#!/bin/bash

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
gcc ../push_swap.c ../src/*.c ../libft.a -o ../push_swap
function push_swap()
{
	
	TEST1=$(../push_swap $@ | ../checker_Mac $@)
	LENINC=$(../push_swap $@ | wc -l)

	if [ "$TEST1" == "OK" ]
	then
		printf " $BLUE%s\n$RESET" "================="
		printf " $GREEN%s$@\n$RESET\n"
		printf "$GREEN\n%s$RESET" "stats = OK"
		printf "\n $GREEN%s %d\n$RESET" "operations ==" $LENINC
		printf " $BLUE%s\n$RESET" "================="
	elif [ "$TEST1" == "KO" ]
	then
		printf "$RED%s$RESET\n" "============="
		printf "$RED%s$@$RESET\n" "KO in "
		printf "$RED%s$RESET\n" "============="
	elif [ "$TEST1" == "Error" ]
	then
		printf "$RED%s$RESET\n" "============="
		printf "$RED%s$@\n$RESET" "KO ERROR in "
		printf "$RED%s$RESET\n" "============="
	fi
}
function test_push
{
	i="0"
	while [ $i != $1 ]; 
	do
		ARG=$(python3 ./test.py $2)
		printf "$YELLOW%s%d$RESET\n" "test for ===> " "$2"
		push_swap $ARG 
		i=$[$i+1]; 
	done
}
#argument  1 = how much while loop and arg2 how much number gnrate
function test_all()
{
	echo "<=======================> start $2 number <=================>"
	test_push $1 $2
	echo "<=======================> end $2 number <===================>"
}

test_all $1 $2

