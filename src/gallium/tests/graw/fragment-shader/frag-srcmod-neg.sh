FRAG

DCL IN[0], COLOR, LINEAR
DCL OUT[0], COLOR

DCL TEMP[0]

SUB TEMP[0], IN[0], IN[0].yzxw
MOV OUT[0], -TEMP[0]

END
