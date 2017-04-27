.section .text
x64_256mc_mul_2:
	.globl x64_256mc_mul_2
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15

	movq 8*0(%rdi), %r8
	movq 8*1(%rdi), %r9
	movq 8*2(%rdi), %r10
	movq 8*3(%rdi), %r11
	movq $0, %r12

	salq %r11
	adcq $0, %r12
	salq %r10
	adcq $0, %r11
	salq %r9
	adcq $0, %r10
	salq %r8
	adcq $0, %r9

	#--- Modular induction
	#--- rsi is the c
	movq %r12, %rax
	mulq %rsi
	addq %rax, %r8
	adcq %rdx, %r9
	adcq $0, %r10

	movq %r8, %r12
	movq %r9, %r13
	movq %r10, %r14
	movq %r11, %r15

	addq %rsi, %r8
	adcq $0, %r9
	adcq $0, %r10
	adcq $0, %r11

	cmovnc %r12, %r8
	cmovnc %r13, %r9
	cmovnc %r14, %r10
	cmovnc %r15, %r11

	movq %r8, 8*0(%rcx)
	movq %r9, 8*1(%rcx)
	movq %r10, 8*2(%rcx)
	movq %r11, 8*3(%rcx)

	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
ret
