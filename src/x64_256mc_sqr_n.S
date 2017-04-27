/**
 * Square of a 256-bit integer
 *
 * It starts the calculation from LVL 0, writes the result to the appropriate registers. You can
 * see which registers assigned to which levels at the end of the diagram.
 *
 *                                                                          +----+----+----+----+
 *                                                                          | a3 | a2 | a1 | a0 |
 *                                                                          +----+----+----+----+
 *                                                                          +----+----+----+----+
 *                                                                          | a3 | a2 | a1 | a0 |
 *                                                                          +----+----+----+----+
 *                                                      =========================================
 *                                                                                    +---------+
 *                                                                                    |  LVL 0  |
 *                                                                                    +---------+
 *                                                                               +----+----+    |
 *                                                                               |  LVL 1  |    |
 *                                                                               +----+----+    |
 *                                                                          +----+----+    |    |
 *                                                                          |  LVL 2  |    |    |
 *                                                                          +----+----+    |    |
 *                                                                     +----+----+    |    |    |
 *                                                                     |  LVL 3  |    |    |    |
 *                                                                     +----+----+    |    |    |
 *                                                                +----+----+    |    |    |    |
 *                                                                |  LVL 4  |    |    |    |    |
 *                                                                +----+----+    |    |    |    |
 *                                                           +----+----+    |    |    |    |    |
 *                                                           |  LVL 4  |    |    |    |    |    |
 *                                                           +----+----+    |    |    |    |    |
 *                                                      +----+----+    |    |    |    |    |    |
 *                                                      |  LVL 5  |    |    |    |    |    |    |
 *                                                      +----+----+    |    |    |    |    |    |
 *                                                      |    |    |    |    |    |    +----+----+
 *                                                      |    |    |    |    |    |    | a0 * a0 |
 *                                                      |    |    |    |    |    |    +----+----+
 *                                                      |    |    |    |    |    +----+----+    |
 *                                                      |    |    |    |    |    | a0 * a1 |    |
 *                                                      |    |    |    |    |    +----+----+    |
 *                                                      |    |    |    |    +----+----+    |    |
 *                                                      |    |    |    |    | a0 * a2 |    |    |
 *                                                      |    |    |    |    +----+----+    |    |
 *                                                      |    |    |    +----+----+    |    |    |
 *                                                      |    |    |    | a0 * a3 |    |    |    |
 *                                                      |    |    |    +----+----+    |    |    |
 *                                                      |    |    |    |    |    +----+----+    |
 *                                                      |    |    |    |    |    | a1 * a0 |    |
 *                                                      |    |    |    |    |    +----+----+    |
 *                                                      |    |    |    |    +----+----+    |    |
 *                                                      |    |    |    |    | a1 * a1 |    |    |
 *                                                      |    |    |    |    +----+----+    |    |
 *                                                      |    |    |    +----+----+    |    |    |
 *                                                      |    |    |    | a1 * a2 |    |    |    |
 *                                                      |    |    |    +---------+    |    |    |
 *                                                      |    |    +----+----+    |    |    |    |
 *                                                      |    |    | a1 * a3 |    |    |    |    |
 *                                                      |    |    +----+----+    |    |    |    |
 *                                                      |    |    |    |    +----+----+    |    |
 *                                                      |    |    |    |    | a2 * a0 |    |    |
 *                                                      |    |    |    |    +----+----+    |    |
 *                                                      |    |    |    +----+----+    |    |    |
 *                                                      |    |    |    | a2 * a1 |    |    |    |
 *                                                      |    |    |    +----+----+    |    |    |
 *                                                      |    |    +----+----+    |    |    |    |
 *                                                      |    |    | a2 * a2 |    |    |    |    |
 *                                                      |    |    +----+----+    |    |    |    |
 *                                                      |    +----+----+    |    |    |    |    |
 *                                                      |    | a2 * a3 |    |    |    |    |    |
 *                                                      |    +----+----+    |    |    |    |    |
 *                                                      |    |    |    +----+----+    |    |    |
 *                                                      |    |    |    | a3 * a0 |    |    |    |
 *                                                      |    |    |    +----+----+    |    |    |
 *                                                      |    |    +----+----+    |    |    |    |
 *                                                      |    |    | a3 * a1 |    |    |    |    |
 *                                                      |    |    +----+----+    |    |    |    |
 *                                                      |    +----+----+    |    |    |    |    |
 *                                                      |    | a3 * a2 |    |    |    |    |    |
 *                                                      |    +----+----+    |    |    |    |    |
 *                                                      +----+----+    |    |    |    |    |    |
 *                                                      | a3 * a3 |    |    |    |    |    |    |
 *                                                      +----+----+----+----+----+----+----+----+
 *                                                      | 15 | 14 | 13 | 12 | 11 | 10 | r9 | r8 |
 *                                                      +----+----+----+----+----+----+----+----+
 */
.section .text
x64_256mc_sqr_n:
	.globl x64_256mc_sqr_n
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15

	movq $0, %r10
	movq $0, %r11
	movq $0, %r12
	movq $0, %r13
	movq $0, %r14
	movq $0, %r15

	movq 8*0(%rcx), %rax
	mulq %rax
	movq %rax, %r8
	movq %rdx, %r9

	movq 8*0(%rcx), %rax
	mulq 8*1(%rcx)
	addq %rax, %r9
	adcq %rdx, %r10
	adcq $0, %r11
	addq %rax, %r9
	adcq %rdx, %r10
	adcq $0, %r11

	movq 8*0(%rcx), %rax
	mulq 8*2(%rcx)
	addq %rax, %r10
	adcq %rdx, %r11
	adcq $0, %r12
	addq %rax, %r10
	adcq %rdx, %r11
	adcq $0, %r12
	movq 8*1(%rcx), %rax
	mulq %rax
	addq %rax, %r10
	adcq %rdx, %r11
	adcq $0, %r12

	movq 8*0(%rcx), %rax
	mulq 8*3(%rcx)
	addq %rax, %r11
	adcq %rdx, %r12
	adcq $0, %r13
	addq %rax, %r11
	adcq %rdx, %r12
	adcq $0, %r13
	movq 8*1(%rcx), %rax
	mulq 8*2(%rcx)
	addq %rax, %r11
	adcq %rdx, %r12
	adcq $0, %r13
	addq %rax, %r11
	adcq %rdx, %r12
	adcq $0, %r13

	movq 8*1(%rcx), %rax
	mulq 8*3(%rcx)
	addq %rax, %r12
	adcq %rdx, %r13
	adcq $0, %r14
	addq %rax, %r12
	adcq %rdx, %r13
	adcq $0, %r14
	movq 8*2(%rcx), %rax
	mulq %rax
	addq %rax, %r12
	adcq %rdx, %r13
	adcq $0, %r14

	movq 8*2(%rcx), %rax
	mulq 8*3(%rcx)
	addq %rax, %r13
	adcq %rdx, %r14
	adcq $0, %r15
	addq %rax, %r13
	adcq %rdx, %r14
	adcq $0, %r15

	movq 8*3(%rcx), %rax
	mulq %rax
	addq %rax, %r14
	adcq %rdx, %r15

	#--- Modular induction
	#--- %rsi is c
	movq %r12, %rax
	mulq %rsi
	addq %rax, %r8
	adcq %rdx, %r9
	adcq $0, %r10

	movq %r13, %rax
	mulq %rsi
	addq %rax, %r9
	adcq %rdx, %r10
	adcq $0, %r11

	movq $0, %r12
	movq %r12, %r13

	movq %r14, %rax
	mulq %rsi
	addq %rax, %r10
	adcq %rdx, %r11
	adcq $0, %r12

	movq %r15, %rax
	mulq %rsi
	addq %rax, %r11
	adcq %rdx, %r12
	adcq $0, %r13

	movq %r12, %rax
	mulq %rsi
	addq %rax, %r8
	adcq %rdx, %r9
	adcq $0, %r10

	movq %r13, %rax
	mulq %rsi
	addq %rax, %r9
	adcq %rdx, %r10
	adcq $0, %r11

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

	movq %r8, 8*0(%rdi)
	movq %r9, 8*1(%rdi)
	movq %r10, 8*2(%rdi)
	movq %r11, 8*3(%rdi)

	popq %r15
	popq %r14
	popq %r13
	popq %r12
ret
