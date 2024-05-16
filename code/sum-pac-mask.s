    
.align 2
.text
.global _main
//compute sum recursively of all number up to N
//where N is passed in as x0
sum:
sum_prologue:
            mov   x15,xzr
            pacia lr ,x28
            pacia x15,x28 //the mask
            eor   lr,lr,x15
            mov   x15,xzr
            stp   lr,x28,[sp,#-16]!
            mov   x28,lr //feedback into next modifier
            
            cmp   x0,1
            b.le  sum_exit
            str   x0,[sp,#-16]!
            add   x0,x0,-1
            bl    sum
            ldr   x1,[sp],#16
            add   x0,x0,x1

sum_exit:   
sum_epilogue:
            ldp   lr,x28,[sp],#16
            mov   x15,xzr
            pacia x15,x28
            eor   lr,lr,x15
            mov   x15,xzr
            autia lr,x28            //"decrypt" the return addr
            ret


_main:
    stp lr,x28,[sp,#-16]!
    mov x28,23
    mov x0,9
    bl  sum
    ldp lr,x28,[sp],#16
    ret
