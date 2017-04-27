/**
 * Multiplication of two 256-bit numbers
 *
 * @param r	256-bit number stores the result
 * @param c	64-bit number, which is the 2^256 - c
 * @param NOPARAM	NULL parameter
 * @param a	256-bit number stores the multiplicand 1
 * @param b	256-bit number stores the multiplicand 2
 */
void x64_256mc_mul_n(unsigned long *r, unsigned long c, void *NOPARAM, unsigned long *a, unsigned long *b);

/**
 * Squaring of a 256-bit number
 *
 * @param r	256-bit number stores the result
 * @param c	64-bit number, which is the 2^256 - c
 * @param NOPARAM	NULL parameter
 * @param a	256-bit number stores the multiplicand 1
 */
void x64_256mc_sqr_n(unsigned long *r, unsigned long c, void *NOPARAM, unsigned long *a);

/**
 * Multiplication of a 256-bit number by two
 *
 * @param r	256-bit number stores the result
 * @param c	64-bit number, which is the 2^256 - c
 * @param NOPARAM	NULL parameter
 * @param a	256-bit number stores the multiplicand 1
 */
void x64_256mc_mul_2(unsigned long *r, unsigned long c, void *NOPARAM, unsigned long *a);

/**
 * Addition of two 256-bit numbers
 *
 * @param r	256-bit number stores the result
 * @param c	64-bit number, which is the 2^256 - c
 * @param NOPARAM	NULL paremeter
 * @param a	256-bit number stores the addend 1
 * @param b	256-bit number stores the addend 2
 */
void x64_256mc_add_n(unsigned long *r, unsigned long c, void *NOPARAM, unsigned long *a, unsigned long *b);

/**
 * Subtraction of two 256-bit numbers
 *
 * r = a - b (mod 2^256-c)
 *
 * @param r	256-bit number stores the result
 * @param c	64-bit number, which is the 2^256 - c
 * @param NOPARAM	NULL parameter
 * @param a	256-bit number stores the minuend
 * @param b	256-bit number stores the subtrahend
 */
void x64_256mc_sub_n(unsigned long *r, unsigned long c, void *NOPARAM, unsigned long *a, unsigned long *b);

/**
 * Modular inversion of a 256-bit number
 *
 * @param r	256-bit number stores the result
 * @param c	64-bit number at 2^256 - c
 * @param NOPARAM	NULL parameter
 * @param a	256-bit number
 */
void x64_256mc_inv_n(unsigned long *r, unsigned long c, void *NOPARAM, unsigned long *a);
