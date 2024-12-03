input=$(cat input)
commands=$(echo $input | grep -o -E -e "mul\([0-9]+,[0-9]+\)" -e "do" -e "don't" | sed -e 's/mul(//g' -e 's/)//g' -e 's/,/*/g' | tr '\n' ' ' | sed 's/do/\ndo/g' | grep "^do " | sed 's/do//g')
echo $commands | sed 's/\ /+/g'
#bruteforce add the first part of the list
echo "420*484+218*461+93*56+162*415+556*374+561*946+97*699+387*15+927*207+$addition" | bc 



