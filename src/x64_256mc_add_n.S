.section .text
x64_256mc_add_n:
	.globl x64_256mc_add_n
	movq 8*0(%rcx), %rdx
	addq %rsi, %rdx
	movq 8*1(%rcx), %r9
	adcq $0, %r9
	movq 8*2(%rcx), %r10
	adcq $0, %r10
	movq 8*3(%rcx), %r11
	adcq $0, %r11

	addq 8*0(%r8), %rdx
	adcq 8*1(%r8), %r9
	adcq 8*2(%r8), %r10
	adcq 8*3(%r8), %r11

	movq $0, %rax
	cmovnc %rsi, %rax

	subq %rax, %rdx
	sbbq $0, %r9
	sbbq $0, %r10
	sbbq $0, %r11

	movq %rdx, 8*0(%rdi)
	movq %r9, 8*1(%rdi)
	movq %r10, 8*2(%rdi)
	movq %r11, 8*3(%rdi)
ret
