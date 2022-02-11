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
static T_2 F_7 ( T_2 V_13 )
{
T_2 V_14 ;
__asm__("dup v1.4s, %w[in] ;"
"movi v0.16b, #0 ;"
"aese v0.16b, v1.16b ;"
"umov %w[out], v0.4s[0] ;"
: [out] "=r"(ret)
: [in] "r"(input)
: "v0","v1");
return V_14 ;
}
int F_8 ( struct V_1 * V_2 , const T_1 * V_15 ,
unsigned int V_16 )
{
static T_1 const V_17 [] = {
0x01 , 0x02 , 0x04 , 0x08 , 0x10 , 0x20 , 0x40 , 0x80 , 0x1b , 0x36 ,
} ;
T_2 V_18 = V_16 / sizeof( T_2 ) ;
struct V_8 * V_19 , * V_20 ;
int V_21 , V_22 ;
if ( V_16 != V_23 &&
V_16 != V_24 &&
V_16 != V_25 )
return - V_26 ;
memcpy ( V_2 -> V_19 , V_15 , V_16 ) ;
V_2 -> V_3 = V_16 ;
F_4 ( 2 ) ;
for ( V_21 = 0 ; V_21 < sizeof( V_17 ) ; V_21 ++ ) {
T_2 * V_27 = V_2 -> V_19 + ( V_21 * V_18 ) ;
T_2 * V_28 = V_27 + V_18 ;
V_28 [ 0 ] = F_9 ( F_7 ( V_27 [ V_18 - 1 ] ) , 8 ) ^ V_17 [ V_21 ] ^ V_27 [ 0 ] ;
V_28 [ 1 ] = V_28 [ 0 ] ^ V_27 [ 1 ] ;
V_28 [ 2 ] = V_28 [ 1 ] ^ V_27 [ 2 ] ;
V_28 [ 3 ] = V_28 [ 2 ] ^ V_27 [ 3 ] ;
if ( V_16 == V_24 ) {
if ( V_21 >= 7 )
break;
V_28 [ 4 ] = V_28 [ 3 ] ^ V_27 [ 4 ] ;
V_28 [ 5 ] = V_28 [ 4 ] ^ V_27 [ 5 ] ;
} else if ( V_16 == V_25 ) {
if ( V_21 >= 6 )
break;
V_28 [ 4 ] = F_7 ( V_28 [ 3 ] ) ^ V_27 [ 4 ] ;
V_28 [ 5 ] = V_28 [ 4 ] ^ V_27 [ 5 ] ;
V_28 [ 6 ] = V_28 [ 5 ] ^ V_27 [ 6 ] ;
V_28 [ 7 ] = V_28 [ 6 ] ^ V_27 [ 7 ] ;
}
}
V_19 = (struct V_8 * ) V_2 -> V_19 ;
V_20 = (struct V_8 * ) V_2 -> V_20 ;
V_22 = F_1 ( V_2 ) ;
V_20 [ 0 ] = V_19 [ V_22 ] ;
for ( V_21 = 1 , V_22 -- ; V_22 > 0 ; V_21 ++ , V_22 -- )
__asm__("ld1 {v0.16b}, %[in] ;"
"aesimc v1.16b, v0.16b ;"
"st1 {v1.16b}, %[out] ;"
: [out] "=Q"(key_dec[i])
: [in] "Q"(key_enc[j])
: "v0","v1");
V_20 [ V_21 ] = V_19 [ 0 ] ;
F_5 () ;
return 0 ;
}
int F_10 ( struct V_4 * V_5 , const T_1 * V_15 ,
unsigned int V_16 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
int V_14 ;
V_14 = F_8 ( V_2 , V_15 , V_16 ) ;
if ( ! V_14 )
return 0 ;
V_5 -> V_29 |= V_30 ;
return - V_26 ;
}
static int T_3 F_11 ( void )
{
return F_12 ( & V_31 ) ;
}
static void T_4 F_13 ( void )
{
F_14 ( & V_31 ) ;
}
