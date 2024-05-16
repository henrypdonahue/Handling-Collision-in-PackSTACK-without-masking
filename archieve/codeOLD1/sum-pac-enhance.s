.text
.align 2
.global _main
//compute sum recursively of all number up to N
//where N is passed in as x0
sum:
    cmp  x0,1
    b.le sum_exit

    // PROLOGUE



    stp   x0,lr,[sp,#-16]!
    add   x0,x0,-1
    bl    sum
    ldp   x1,lr,[sp],#16


    // EPILOGUE


    add   x0,x0,x1
sum_exit:   ret

_main:
    stp lr,x28,[sp,#-16]!
    mov x28,0
    mov x0,5
    bl  sum
    ldp lr,x28,[sp],#16
    ret