#!/bin/bash

count=$(ls -1q exports/ | wc -l)
padding_length=4
padded_count=$(printf "%0${padding_length}d" "$count")
new_name="snesdev2025__$padded_count.nes"	
	
echo $new_name 
cp hello_world.sfc exports/$new_name
