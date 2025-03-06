#!/bin/sh
DIR="../cmake-build-debug/MCOM_PRIVATE.hex"
COPYCOM="st-flash --reset --format ihex write ../cmake-build-debug/MCOM_PRIVATE.hex"

$COPYCOM
echo "監視対象 $DIR"
echo "実行コマンド $COPYCOM"
INTERVAL=1 #監視間隔, 秒で指定
last=`ls -l -T1 $DIR | awk '{print $8}'`
while true; do
        sleep $INTERVAL
        current=`ls -l -T1 $DIR | awk '{print $8}'`
        if [ $last != $current ] ; then
                echo ""
                echo "updated: $current"
                last=$current
                eval $COPYCOM
        fi
done