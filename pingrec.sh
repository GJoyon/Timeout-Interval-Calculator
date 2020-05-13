#!/bin/bash
#a program that pings a given target host for a given amount of time,
#then records the resulting sample, estimated RTT, and timeout interval values
#
#make sure there are also C programs candw.c, dev.c, est.c, and tout.c
#each program properly compiled
#
#enter chmod 755 pingrec.sh in the shell command prompt before running
#and type ./pingrec.sh <host_domain_name> <pinging_time> to testrun
#
#example: ./pingrec.sh google.com 50
#this lets the program ping google.com 50 times and
#record the result for each pinging
#
#@author Sua "Joshua" Lee
#@version 19-04-2020

#declare variable(s) that need to be initialized before the loop
dev=0

#do the following for a given amount of time
for count in `seq 1 1 $2`
do
    #ping a given target destination and record the result
    ping_command=$(ping -c 1 $1)
    result=${ping_command:0}

    #look for a value that will be the sample RTT value
    index=0
    trimmed=${result:$index:5}

    #look for a substring "time=" in the ping result
    while [ "$trimmed" != "time=" ]; do
	((index=index+1))
	trimmed=${result:$index:5}
    done

    #the value after the substring "time=" is the one we are looking for
    rtt_index=$(($index + 5))
    rtt_end=$rtt_index
    
    trimmed=${result:$rtt_end:1}

    #exclude unit
    while [ "$trimmed" != "m" ]; do
	((rtt_end=rtt_end+1))
	trimmed=${result:$rtt_end:1}
    done
    
    rtt_end=$(($rtt_end - 1))
    rtt_len=$(($rtt_end - $rtt_index))

    #the variable rtt now holds the resulting "substring" as a sample RTT
    rtt=${result:$rtt_index:$rtt_len}

    echo "Data $count recorded"

    #run the helper C program that converts the string RTT value
    #to floating-point number
    rtt=$(./candw $rtt)

    #now record sample, estimated RTT, and timeout interval
    if [ $count -eq 1 ]; then
	echo "${count} ${rtt}" > sample_log.dat

	estimated=$rtt
	echo "${count} ${estimated}" > est_log.dat

	dev=$(./dev 0 $estimated 0)
	tout=$(./tout $estimated $dev)
	echo "${count} ${tout}" > tout_log.dat
    else
	echo "${count} ${rtt}" >> sample_log.dat

	estimated=$(./est $estimated $rtt)
	echo "${count} ${estimated}" >> est_log.dat

	dev=$(./dev $rtt $estimated $dev)
	tout=$(./tout $estimated $dev)
	echo "${count} ${tout}" >> tout_log.dat
    fi    
done
