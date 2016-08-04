@echo off

 ..\..\..\..\bin\Release\tinterpcurve -i testimg.raw -x 256 -y 256 -z 1 -d 8 -s 0 -a 0 -o testimg_interp_linear_0.raw
 ..\..\..\..\bin\Release\tinterpcurve -i testimg.raw -x 256 -y 256 -z 1 -d 8 -s 0 -a 1 -o testimg_interp_cubic.raw

pause