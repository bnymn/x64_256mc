// nol: 124 (without mod)
.section .text
x64_256mc_mul_n:
	.globl x64_256mc_mul_n
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15

	#---
	movq 8*0(%rcx), %rax
	mulq 8*0(%r8)
	movq %rax, %r9
	movq %rdx, %rbx

	movq 8*1(%rcx), %rax
	mulq 8*0(%r8)
	addq %rbx, %rax
	adcq $0, %rdx
	movq %rax, %r10
	movq %rdx, %rbx

	movq 8*2(%rcx), %rax
	mulq 8*0(%r8)
	addq %rbx, %rax
	adcq $0, %rdx
	movq %rax, %r11
	movq %rdx, %rbx

	movq 8*3(%rcx), %rax
	mulq 8*0(%r8)
	addq %rbx, %rax
	adcq $0, %rdx
	movq %rax, %r12
	movq %rdx, %r13

	#---
	movq 8*0(%rcx), %rax
	mulq 8*1(%r8)
	addq %rax, %r10
	adcq $0, %rdx
	movq %rdx, %rbx

	movq 8*1(%rcx), %rax
	mulq 8*1(%r8)
	addq %rax, %r11
	adcq $0, %rdx
	addq %rbx, %r11
	adcq $0, %rdx
	movq %rdx, %rbx

	movq 8*2(%rcx), %rax
	mulq 8*1(%r8)
	addq %rax, %r12
	adcq $0, %rdx
	addq %rbx, %r12
	adcq $0, %rdx
	movq %rdx, %rbx

	movq 8*3(%rcx), %rax
	mulq 8*1(%r8)
	addq %rax, %r13
	adcq $0, %rdx
	addq %rbx, %r13
	adcq $0, %rdx
	movq %rdx, %r14

	#---
	movq 8*0(%rcx), %rax
	mulq 8*2(%r8)
	addq %rax, %r11
	adcq $0, %rdx
	movq %rdx, %rbx

	movq 8*1(%rcx), %rax
	mulq 8*2(%r8)
	addq %rax, %r12
	adcq $0, %rdx
	addq %rbx, %r12
	adcq $0, %rdx
	movq %rdx, %rbx

	movq 8*2(%rcx), %rax
	mulq 8*2(%r8)
	addq %rax, %r13
	adcq $0, %rdx
	addq %rbx, %r13
	adcq $0, %rdx
	movq %rdx, %rbx

	movq 8*3(%rcx), %rax
	mulq 8*2(%r8)
	addq %rax, %r14
	adcq $0, %rdx
	addq %rbx, %r14
	adcq $0, %rdx
	movq %rdx, %r15

	#---
	movq 8*0(%rcx), %rax
	mulq 8*3(%r8)
	addq %rax, %r12
	adcq $0, %rdx
	movq %rdx, %rbx

	movq 8*1(%rcx), %rax
	mulq 8*3(%r8)
	addq %rax, %r13
	adcq $0, %rdx
	addq %rbx, %r13
	adcq $0, %rdx
	movq %rdx, %rbx

	movq 8*2(%rcx), %rax
	mulq 8*3(%r8)
	addq %rax, %r14
	adcq $0, %rdx
	addq %rbx, %r14
	adcq $0, %rdx
	movq %rdx, %rbx

	movq 8*3(%rcx), %rax
	mulq 8*3(%r8)
	addq %rax, %r15
	adcq $0, %rdx
	addq %rbx, %r15
	adcq $0, %rdx
	movq %rdx, %r8

	#--- Modular induction
	#--- rsi is the c
	movq %r13, %rax
	mulq %rsi
	addq %rax, %r9
	adcq %rdx, %r10
	adcq $0, %r11

	movq %r14, %rax
	mulq %rsi
	addq %rax, %r10
	adcq %rdx, %r11
	adcq $0, %r12

	movq $0, %r13
	movq %r13, %r14

	movq %r15, %rax
	mulq %rsi
	addq %rax, %r11
	adcq %rdx, %r12
	adcq $0, %r13

	movq %r8, %rax
	mulq %rsi
	addq %rax, %r12
	adcq %rdx, %r13
	adcq $0, %r14

	movq %r13, %rax
	mulq %rsi
	addq %rax, %r9
	adcq %rdx, %r10
	adcq $0, %r11

	movq %r14, %rax
	mulq %rsi
	addq %rax, %r10
	adcq %rdx, %r11
	adcq $0, %r12

	movq %r9, %r13
	movq %r10, %r14
	movq %r11, %r15
	movq %r12, %r8

	addq %rsi, %r9
	adcq $0, %r10
	adcq $0, %r11
	adcq $0, %r12

	cmovnc %r13, %r9
	cmovnc %r14, %r10
	cmovnc %r15, %r11
	cmovnc %r8, %r12

	movq %r9, 8*0(%rdi)
	movq %r10, 8*1(%rdi)
	movq %r11, 8*2(%rdi)
	movq %r12, 8*3(%rdi)

	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
ret
