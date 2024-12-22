## ********************FAILED********************

****************************************
## ********************SUCCESS********************
### *****./riscv -d ./code/input/R/R.input > ./code/out/R/R.solution*****
 ```
```
### *****python3 compare.py ./code/out/R/R.solution ./code/ref/R/R.solution*****
 ```
```
### *****timeout 60 ./riscv -r ./code/input/R/R.input > ./code/out/R/R.trace*****
 ```
```
### *****python3 compare.py ./code/out/R/R.trace ./code/ref/R/R.trace*****
 ```
```
### *****./riscv -d ./code/input/Ri/Ri.input > ./code/out/Ri/Ri.solution*****
 ```
```
### *****python3 compare.py ./code/out/Ri/Ri.solution ./code/ref/Ri/Ri.solution*****
 ```
```
### *****timeout 60 ./riscv -r -v ./code/input/Ri/Ri.input > ./code/out/Ri/Ri.trace*****
 ```
```
### *****python3 compare.py ./code/out/Ri/Ri.trace ./code/ref/Ri/Ri.trace*****
 ```
```
### *****./riscv -d ./code/input/I/I.input > ./code/out/I/I.solution*****
 ```
```
### *****python3 compare.py ./code/out/I/I.solution ./code/ref/I/I.solution*****
 ```
```
### *****./riscv -d ./code/input/I/L.input > ./code/out/I/L.solution*****
 ```
```
### *****python3 compare.py ./code/out/I/L.solution ./code/ref/I/L.solution*****
 ```
```
### *****timeout 60 ./riscv -r ./code/input/I/I.input > ./code/out/I/I.trace*****
 ```
```
### *****python3 compare.py ./code/out/I/I.trace ./code/ref/I/I.trace*****
 ```
```
### *****timeout 60 ./riscv -r ./code/input/I/L.input > ./code/out/I/L.trace*****
 ```
```
### *****python3 compare.py ./code/out/I/L.trace ./code/ref/I/L.trace*****
 ```
```
### *****./riscv -d ./code/input/S/S.input > ./code/out/S/S.solution*****
 ```
```
### *****python3 compare.py ./code/out/S/S.solution ./code/ref/S/S.solution*****
 ```
```
### *****timeout 60 ./riscv -r ./code/input/S/S.input > ./code/out/S/S.trace*****
 ```
```
### *****python3 compare.py ./code/out/S/S.trace ./code/ref/S/S.trace*****
 ```
```
### *****./riscv -d ./code/input/SB/SB.input > ./code/out/SB/SB.solution*****
 ```
```
### *****python3 compare.py ./code/out/SB/SB.solution ./code/ref/SB/SB.solution*****
 ```
```
### *****timeout 60 ./riscv -r ./code/input/SB/SB.input > ./code/out/SB/SB.trace*****
 ```
```
### *****python3 compare.py ./code/out/SB/SB.trace ./code/ref/SB/SB.trace*****
 ```
```
### *****./riscv -d ./code/input/U/U.input > ./code/out/U/U.solution*****
 ```
```
### *****python3 compare.py ./code/out/U/U.solution ./code/ref/U/U.solution*****
 ```
```
### *****timeout 60 ./riscv -r ./code/input/U/U.input > ./code/out/U/U.trace*****
 ```
```
### *****python3 compare.py ./code/out/U/U.trace ./code/ref/U/U.trace*****
 ```
```
### *****./riscv -d ./code/input/UJ/UJ.input > ./code/out/UJ/UJ.solution*****
 ```
```
### *****python3 compare.py ./code/out/UJ/UJ.solution ./code/ref/UJ/UJ.solution*****
 ```
```
### *****timeout 60 ./riscv -r ./code/input/UJ/UJ.input > ./code/out/UJ/UJ.trace*****
 ```
```
### *****python3 compare.py ./code/out/UJ/UJ.trace ./code/ref/UJ/UJ.trace*****
 ```
```
### *****./riscv -d ./code/input/custom_slt.input > code/out/custom_slt.solution*****
 ```
```
### *****python3 compare.py ./code/out/custom_slt.solution ./code/ref/custom_slt.solution*****
 ```
```
### *****timeout 60 ./riscv -e -r -s ./code/input/slt_data.input  -a 0x8,0x3000 ./code/input/custom_slt.input > code/out/custom_slt.trace*****
 ```
```
### *****python3 compare.py ./code/out/custom_slt.trace ./code/ref/custom_slt.trace*****
 ```
```
### *****./riscv -d ./code/input/simple.input > ./code/out/simple.solution*****
 ```
```
### *****python3 compare.py ./code/out/simple.solution ./code/ref/simple.solution*****
 ```
```
### *****./riscv -d ./code/input/multiply.input > ./code/out/multiply.solution*****
 ```
```
### *****python3 compare.py ./code/out/multiply.solution ./code/ref/multiply.solution*****
 ```
```
### *****./riscv -d ./code/input/random.input > ./code/out/random.solution*****
 ```
```
### *****python3 compare.py ./code/out/random.solution ./code/ref/random.solution*****
 ```
```
### *****timeout 60 ./riscv -r -e ./code/input/simple.input > ./code/out/simple.trace*****
 ```
```
### *****python3 part2_tester.py simple*****
 ```
Starting simple test
simple test has passed.

```
### *****timeout 60 ./riscv -r -e ./code/input/multiply.input > ./code/out/multiply.trace*****
 ```
```
### *****python3 part2_tester.py multiply*****
 ```
Starting multiply test
multiply test has passed.

```
### *****timeout 60 ./riscv -r -e ./code/input/random.input > ./code/out/random.trace*****
 ```
```
### *****python3 part2_tester.py random*****
 ```
Starting random test
random test has passed.

```
