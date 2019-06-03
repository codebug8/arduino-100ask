@echo off

wmic LogicalDisk where "DriveType='2'" get size /value > temp.txt
type temp.txt > new.txt

for /f "tokens=2 delims==" %%i in (new.txt) do (
 if %%i leq 10500000 if %%i geq 10000000 (
 For /f "usebackq delims== tokens=2" %%x in (`wmic logicaldisk where "Size='%%i'" get caption /format:value`) do set caption=%%x
 goto :Show 
 )
)
:Show

set backdir="%caption%\arduino-100ask"
echo "%backdir%"

if exist %backdir% ( copy chn_ip.txt   %backdir% ) else (echo "Directory is unknown"  echo !! ) 

exit