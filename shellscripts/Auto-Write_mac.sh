#!/bin/sh
DIR="../cmake-build-debug/MCOM_PRIVATE.bin"
COPYCOM="cp ../cmake-build-debug/MCOM_PRIVATE.bin /Volumes/NODE_F767ZI"

echo "監視対象 $DIR"
echo "実行コマンド $COPYCOM"
INTERVAL=1 #監視間隔, 秒で指定
last=`ls -l $DIR | awk '{print $8}'`
while true; do
        sleep $INTERVAL
        current=`ls -l $DIR | awk '{print $8}'`
        if [ $last != $current ] ; then
                echo ""
                echo "updated: $current"
                last=$current
                eval $COPYCOM
        fi
done
