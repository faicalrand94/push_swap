#!/bin/bash

function max()
{
	TEST=$(./tester_push_swap.sh $1 $2 | grep "operations == $3")
	if [ "$TEST" == "operations == $3" ]
	then
		echo "KO"
	fi
}
max $1 $2 $3