.section .text
x64_256mc_mul_2:
	.globl x64_256mc_mul_2
	movq 8*0(%rcx), %r8
	addq %rsi, %r8
	movq 8*1(%rcx), %r9
	adcq $0, %r9
	movq 8*2(%rcx), %r10
	adcq $0, %r10
	movq 8*3(%rcx), %r11
	adcq $0, %r11

	addq 8*0(%rcx), %r8
	adcq 8*1(%rcx), %r9
	adcq 8*2(%rcx), %r10
	adcq 8*3(%rcx), %r11

	movq $0, %rax
	cmovnc %rsi, %rax

	subq %rax, %r8
	sbbq $0, %r9
	sbbq $0, %r10
	sbbq $0, %r11

	movq %r8, 8*0(%rdi)
	movq %r9, 8*1(%rdi)
	movq %r10, 8*2(%rdi)
	movq %r11, 8*3(%rdi)
ret
