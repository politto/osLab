echo "is it morning? yes or no"
read timeofday
if [ $timeofday = "yes" ]
then
	echo "おはよございます！ 「Good morning」"
elif [ $timeofday = "no" ]
then
	echo "こにしわ！「Good afternoon」"
else
	echo "すしませ！，Do not understand $timeofday"
	exit 1
fi
exit 0
