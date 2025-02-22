	.globl add
	.globl subtract
	.globl multiply
	.globl divide

	.text
add:
	add %rsi, %rdi
	mov %rdi, %rax
	ret

subtract:
	sub %rsi, %rdi
	mov %rdi, %rax
	ret

multiply:
	mov $1, %r12
	mov %rdi, %r13
	cmp $0, %rsi
	je _mul_zero
_mul_loop:
	add %r13, %rdi
	add $1, %r12
	cmp %rsi, %r12
	jne _mul_loop
	mov %rdi, %rax
	ret
_mul_zero:
	mov $0, %rax
	ret

divide:
	cmp $0, %rsi
	je _div_err_zero
	cvtsi2sd %rdi, %xmm0
	cvtsi2sd %rsi, %xmm1
	divsd %xmm1, %xmm0
	ret
_div_err_zero:
	mov $1, %rax
	mov $1, %rdi
	mov $msg, %rsi
	mov $25, %rdx
	syscall

	mov $0, %rdi
	cvtsi2sd %rdi, %xmm0
	ret

	.data
msg:
	.ascii "division by zero error!\n"
