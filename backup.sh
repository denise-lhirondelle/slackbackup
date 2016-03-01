#!/bin/bash

date=`date "+%Y-%m-%d_%H_%M_%S"`
backup_root="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)"

function get_previous_backup {
    cd $backup_root
    return $(ls -1 | tail -n 1)
}

previous_backup=$(get_previous_backup)

rsync -azP \
    --delete \
    #--delete-excluded \
    #--exclude-from=/dir/to/exclude \
    --link-dest= \
