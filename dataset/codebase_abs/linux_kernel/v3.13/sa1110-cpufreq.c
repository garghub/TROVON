static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 * V_2 + 999999 ) / 1000000 ;
}
static inline void F_2 ( T_1 * V_3 , int V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_5 = 2 * V_5 - 1 ;
V_6 = V_4 + 1 + V_5 ;
V_3 [ 0 ] = ( 1 << V_5 ) - 1 ;
V_3 [ 0 ] |= 0x55555555 << V_6 ;
V_3 [ 1 ] = V_3 [ 2 ] = 0x55555555 << ( V_6 & 1 ) ;
}
static void
F_3 ( struct V_7 * V_8 , T_1 V_9 ,
struct V_10 * V_11 )
{
T_1 V_12 , V_13 , V_14 , V_15 ;
V_12 = V_9 / 2 ;
V_13 = V_12 ;
if ( ( F_1 ( V_11 -> V_16 , V_13 ) > 1 ) ||
( V_17 < V_18 && V_13 < 62000 ) )
V_13 /= 2 ;
V_8 -> V_19 = V_20 & 0x007f007f ;
V_15 = F_1 ( V_11 -> V_15 , V_12 ) ;
V_14 = F_1 ( V_11 -> V_14 , V_12 ) - 1 ;
if ( V_14 < 1 )
V_14 = 1 ;
V_8 -> V_19 |= V_14 << 8 ;
V_8 -> V_19 |= V_14 << 24 ;
V_8 -> V_19 |= V_11 -> V_21 << 12 ;
V_8 -> V_19 |= V_11 -> V_21 << 28 ;
V_8 -> V_19 |= V_15 << 14 ;
V_8 -> V_19 |= V_15 << 30 ;
V_8 -> V_22 = V_23 & 0xffbffff0 ;
V_8 -> V_22 |= 7 ;
if ( V_13 != V_12 )
V_8 -> V_22 |= V_24 ;
F_2 ( V_8 -> V_3 , V_13 >= 62000 ,
F_1 ( V_11 -> V_25 , V_12 ) ) ;
#ifdef F_4
F_5 ( V_26 L_1 ,
V_8 -> V_19 , V_8 -> V_22 , V_8 -> V_3 [ 0 ] , V_8 -> V_3 [ 1 ] ,
V_8 -> V_3 [ 2 ] ) ;
#endif
}
static inline void F_6 ( T_1 V_27 )
{
V_23 = ( V_23 & 0xffff000f ) | ( V_27 << 4 ) ;
( void ) V_23 ;
}
static void
F_7 ( T_1 V_9 , struct V_10 * V_11 )
{
T_1 V_28 = ( V_11 -> V_29 * 1000 ) >> V_11 -> V_30 ;
T_1 V_27 = F_1 ( V_28 , V_9 / 2 ) / 32 ;
#ifdef F_4
F_8 ( 250 ) ;
F_5 ( V_26 L_2 , V_27 ) ;
#endif
F_6 ( V_27 ) ;
}
static int F_9 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_10 * V_11 = & V_10 ;
struct V_7 V_8 ;
unsigned long V_34 ;
unsigned int V_35 ;
F_3 ( & V_8 , V_36 [ V_33 ] . V_37 , V_11 ) ;
#if 0
if (policy->max < 147500) {
sd.mdrefr |= MDREFR_K1DB2;
sd.mdcas[0] = 0xaaaaaa7f;
} else {
sd.mdrefr &= ~MDREFR_K1DB2;
sd.mdcas[0] = 0xaaaaaa9f;
}
sd.mdcas[1] = 0xaaaaaaaa;
sd.mdcas[2] = 0xaaaaaaaa;
#endif
F_6 ( 2 ) ;
if ( ! F_10 () )
F_11 ( 20 ) ;
else
F_8 ( 20 ) ;
F_12 ( V_34 ) ;
asm("mcr p15, 0, %0, c7, c10, 4" : : "r" (0));
F_13 ( 10 ) ;
__asm__ __volatile__("\n\
b 2f \n\
.align 5 \n\
1: str %3, [%1, #0] @ MDCNFG \n\
str %4, [%1, #28] @ MDREFR \n\
str %5, [%1, #4] @ MDCAS0 \n\
str %6, [%1, #8] @ MDCAS1 \n\
str %7, [%1, #12] @ MDCAS2 \n\
str %8, [%2, #0] @ PPCR \n\
ldr %0, [%1, #0] \n\
b 3f \n\
2: b 1b \n\
3: nop \n\
nop"
: "=&r" (unused)
: "r" (&MDCNFG), "r" (&PPCR), "0" (sd.mdcnfg),
"r" (sd.mdrefr), "r" (sd.mdcas[0]),
"r" (sd.mdcas[1]), "r" (sd.mdcas[2]), "r" (ppcr));
F_14 ( V_34 ) ;
F_7 ( V_36 [ V_33 ] . V_37 , V_11 ) ;
return 0 ;
}
static int T_2 F_15 ( struct V_31 * V_32 )
{
return F_16 ( V_32 , V_36 , V_38 ) ;
}
static struct V_10 * F_17 ( const char * V_39 )
{
struct V_10 * V_11 ;
for ( V_11 = V_40 ; V_11 < V_40 + F_18 ( V_40 ) ;
V_11 ++ )
if ( strcmp ( V_39 , V_11 -> V_39 ) == 0 )
return V_11 ;
return NULL ;
}
static int T_2 F_19 ( void )
{
struct V_10 * V_11 ;
const char * V_39 = V_41 ;
if ( ! F_20 () )
return - V_42 ;
if ( ! V_39 [ 0 ] ) {
if ( F_21 () )
V_39 = L_3 ;
if ( F_22 () )
V_39 = L_4 ;
if ( F_23 () )
V_39 = L_5 ;
if ( F_24 () )
V_39 = L_6 ;
if ( F_25 () )
V_39 = L_7 ;
}
V_11 = F_17 ( V_39 ) ;
if ( V_11 ) {
F_5 ( V_26 L_8
L_9 ,
V_11 -> V_16 , V_11 -> V_25 , V_11 -> V_14 ,
V_11 -> V_15 , V_11 -> V_29 , V_11 -> V_21 ) ;
memcpy ( & V_10 , V_11 , sizeof( V_10 ) ) ;
return F_26 ( & V_43 ) ;
}
return 0 ;
}
