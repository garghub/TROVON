static int F_1 ( struct V_1 * V_2 )
{
return 6 + V_2 -> V_3 / 4 ;
}
static void F_2 ( struct V_4 * V_5 , T_1 V_6 [] , T_1 const V_7 [] )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
struct V_8 * V_9 = (struct V_8 * ) V_6 ;
struct V_8 const * V_10 = (struct V_8 * ) V_7 ;
void * V_11 ;
int V_12 ;
F_4 ( 4 ) ;
__asm__(" ld1 {v0.16b}, %[in] ;"
" ld1 {v1.2d}, [%[key]], #16 ;"
" cmp %w[rounds], #10 ;"
" bmi 0f ;"
" bne 3f ;"
" mov v3.16b, v1.16b ;"
" b 2f ;"
"0: mov v2.16b, v1.16b ;"
" ld1 {v3.2d}, [%[key]], #16 ;"
"1: aese v0.16b, v2.16b ;"
" aesmc v0.16b, v0.16b ;"
"2: ld1 {v1.2d}, [%[key]], #16 ;"
" aese v0.16b, v3.16b ;"
" aesmc v0.16b, v0.16b ;"
"3: ld1 {v2.2d}, [%[key]], #16 ;"
" subs %w[rounds], %w[rounds], #3 ;"
" aese v0.16b, v1.16b ;"
" aesmc v0.16b, v0.16b ;"
" ld1 {v3.2d}, [%[key]], #16 ;"
" bpl 1b ;"
" aese v0.16b, v2.16b ;"
" eor v0.16b, v0.16b, v3.16b ;"
" st1 {v0.16b}, %[out] ;"
: [out] "=Q"(*out),
[key] "=r"(dummy0),
[rounds] "=r"(dummy1)
: [in] "Q"(*in),
"1"(ctx->key_enc),
"2"(num_rounds(ctx) - 2)
: "cc");
F_5 () ;
}
static void F_6 ( struct V_4 * V_5 , T_1 V_6 [] , T_1 const V_7 [] )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
struct V_8 * V_9 = (struct V_8 * ) V_6 ;
struct V_8 const * V_10 = (struct V_8 * ) V_7 ;
void * V_11 ;
int V_12 ;
F_4 ( 4 ) ;
__asm__(" ld1 {v0.16b}, %[in] ;"
" ld1 {v1.2d}, [%[key]], #16 ;"
" cmp %w[rounds], #10 ;"
" bmi 0f ;"
" bne 3f ;"
" mov v3.16b, v1.16b ;"
" b 2f ;"
"0: mov v2.16b, v1.16b ;"
" ld1 {v3.2d}, [%[key]], #16 ;"
"1: aesd v0.16b, v2.16b ;"
" aesimc v0.16b, v0.16b ;"
"2: ld1 {v1.2d}, [%[key]], #16 ;"
" aesd v0.16b, v3.16b ;"
" aesimc v0.16b, v0.16b ;"
"3: ld1 {v2.2d}, [%[key]], #16 ;"
" subs %w[rounds], %w[rounds], #3 ;"
" aesd v0.16b, v1.16b ;"
" aesimc v0.16b, v0.16b ;"
" ld1 {v3.2d}, [%[key]], #16 ;"
" bpl 1b ;"
" aesd v0.16b, v2.16b ;"
" eor v0.16b, v0.16b, v3.16b ;"
" st1 {v0.16b}, %[out] ;"
: [out] "=Q"(*out),
[key] "=r"(dummy0),
[rounds] "=r"(dummy1)
: [in] "Q"(*in),
"1"(ctx->key_dec),
"2"(num_rounds(ctx) - 2)
: "cc");
F_5 () ;
}
static int T_2 F_7 ( void )
{
return F_8 ( & V_13 ) ;
}
static void T_3 F_9 ( void )
{
F_10 ( & V_13 ) ;
}
