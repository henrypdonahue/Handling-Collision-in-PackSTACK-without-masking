.align 2
.text
.global _main

//compute sum recursively of all number up to N
//where N is passed in as x0
sum:
            cmp  x0,1
            b.le sum_exit
            stp  x0,lr,[sp,#-16]!
            add  x0,x0,-1
            bl   sum
            ldp  x1,lr,[sp],#16
            add  x0,x0,x1
sum_exit:   ret


_main:
    str lr,[sp,#-16]!
    mov x0,7
    bl  sum
    ldr lr,[sp],#16
    ret