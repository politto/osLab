for file in $(find . -type f -name "*.c" | cut -d'/' -f2 | tac)
do
	trimmedName=`echo $file | cut -d'.' -f1 `
	cc $file -o $trimmedName 2>/dev/null
	
	if [ -f $trimmedName ]
	then
		ans=$(./$trimmedName)
		if [ "$ans" == 20 ]
		then
			printf "%s 10 \n" $file
		else
			printf "%s 7 \n" $file
		fi
	else
		printf "%s 5 \n" $file
	fi
done
