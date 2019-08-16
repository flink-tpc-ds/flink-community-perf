#!/bin/bash

#Params
uploadFile=$1
uploadDest=$2

#[Orig] Copy to target file
cp $uploadFile $uploadDest

#delete the local file (or named pipe)
rm -f $uploadFile
