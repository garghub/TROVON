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
( F_4 () < V_17 && V_13 < 62000 ) )
V_13 /= 2 ;
V_8 -> V_18 = V_19 & 0x007f007f ;
V_15 = F_1 ( V_11 -> V_15 , V_12 ) ;
V_14 = F_1 ( V_11 -> V_14 , V_12 ) - 1 ;
if ( V_14 < 1 )
V_14 = 1 ;
V_8 -> V_18 |= V_14 << 8 ;
V_8 -> V_18 |= V_14 << 24 ;
V_8 -> V_18 |= V_11 -> V_20 << 12 ;
V_8 -> V_18 |= V_11 -> V_20 << 28 ;
V_8 -> V_18 |= V_15 << 14 ;
V_8 -> V_18 |= V_15 << 30 ;
V_8 -> V_21 = V_22 & 0xffbffff0 ;
V_8 -> V_21 |= 7 ;
if ( V_13 != V_12 )
V_8 -> V_21 |= V_23 ;
F_2 ( V_8 -> V_3 , V_13 >= 62000 ,
F_1 ( V_11 -> V_24 , V_12 ) ) ;
#ifdef F_5
F_6 ( V_25 L_1 ,
V_8 -> V_18 , V_8 -> V_21 , V_8 -> V_3 [ 0 ] , V_8 -> V_3 [ 1 ] ,
V_8 -> V_3 [ 2 ] ) ;
#endif
}
static inline void F_7 ( T_1 V_26 )
{
V_22 = ( V_22 & 0xffff000f ) | ( V_26 << 4 ) ;
( void ) V_22 ;
}
static void
F_8 ( T_1 V_9 , struct V_10 * V_11 )
{
T_1 V_27 = ( V_11 -> V_28 * 1000 ) >> V_11 -> V_29 ;
T_1 V_26 = F_1 ( V_27 , V_9 / 2 ) / 32 ;
#ifdef F_5
F_9 ( 250 ) ;
F_6 ( V_25 L_2 , V_26 ) ;
#endif
F_7 ( V_26 ) ;
}
static int F_10 ( struct V_30 * V_31 , unsigned int V_32 )
{
struct V_10 * V_11 = & V_10 ;
struct V_7 V_8 ;
unsigned long V_33 ;
unsigned int V_34 ;
F_3 ( & V_8 , V_35 [ V_32 ] . V_36 , V_11 ) ;
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
F_7 ( 2 ) ;
if ( ! F_11 () )
F_12 ( 20 ) ;
else
F_9 ( 20 ) ;
F_13 ( V_33 ) ;
asm("mcr p15, 0, %0, c7, c10, 4" : : "r" (0));
F_14 ( 10 ) ;
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
F_15 ( V_33 ) ;
F_8 ( V_35 [ V_32 ] . V_36 , V_11 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_30 * V_31 )
{
return F_17 ( V_31 , V_35 , V_37 ) ;
}
static struct V_10 * F_18 ( const char * V_38 )
{
struct V_10 * V_11 ;
for ( V_11 = V_39 ; V_11 < V_39 + F_19 ( V_39 ) ;
V_11 ++ )
if ( strcmp ( V_38 , V_11 -> V_38 ) == 0 )
return V_11 ;
return NULL ;
}
static int T_2 F_20 ( void )
{
struct V_10 * V_11 ;
const char * V_38 = V_40 ;
if ( ! F_21 () )
return - V_41 ;
if ( ! V_38 [ 0 ] ) {
if ( F_22 () )
V_38 = L_3 ;
if ( F_23 () )
V_38 = L_4 ;
if ( F_24 () )
V_38 = L_5 ;
if ( F_25 () || F_26 () )
V_38 = L_6 ;
if ( F_27 () )
V_38 = L_7 ;
}
V_11 = F_18 ( V_38 ) ;
if ( V_11 ) {
F_6 ( V_25 L_8
L_9 ,
V_11 -> V_16 , V_11 -> V_24 , V_11 -> V_14 ,
V_11 -> V_15 , V_11 -> V_28 , V_11 -> V_20 ) ;
memcpy ( & V_10 , V_11 , sizeof( V_10 ) ) ;
return F_28 ( & V_42 ) ;
}
return 0 ;
}
