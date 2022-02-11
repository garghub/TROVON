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
static int F_9 ( struct V_31 * V_32 ,
unsigned int V_33 ,
unsigned int V_34 )
{
struct V_10 * V_11 = & V_10 ;
struct V_35 V_36 ;
struct V_7 V_8 ;
unsigned long V_37 ;
unsigned int V_38 , V_39 ;
switch ( V_34 ) {
case V_40 :
V_38 = F_10 ( V_33 ) ;
if ( F_11 ( V_38 ) > V_32 -> V_41 )
V_38 -- ;
break;
case V_42 :
V_38 = F_10 ( V_33 ) ;
if ( V_38 && ( F_11 ( V_38 ) > V_33 ) &&
( F_11 ( V_38 - 1 ) >= V_32 -> V_43 ) )
V_38 -- ;
break;
default:
return - V_44 ;
}
V_36 . V_45 = F_12 ( 0 ) ;
V_36 . V_46 = F_11 ( V_38 ) ;
F_3 ( & V_8 , V_36 . V_46 , V_11 ) ;
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
F_13 ( V_32 , & V_36 , V_47 ) ;
F_6 ( 2 ) ;
if ( ! F_14 () )
F_15 ( 20 ) ;
else
F_8 ( 20 ) ;
F_16 ( V_37 ) ;
asm("mcr p15, 0, %0, c7, c10, 4" : : "r" (0));
F_17 ( 10 ) ;
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
F_18 ( V_37 ) ;
F_7 ( V_36 . V_46 , V_11 ) ;
F_13 ( V_32 , & V_36 , V_48 ) ;
return 0 ;
}
static int T_2 F_19 ( struct V_31 * V_32 )
{
if ( V_32 -> V_49 != 0 )
return - V_44 ;
V_32 -> V_50 = V_32 -> V_43 = V_32 -> V_41 = F_12 ( 0 ) ;
V_32 -> V_51 . V_52 = 59000 ;
V_32 -> V_51 . V_53 = 287000 ;
V_32 -> V_51 . V_54 = V_55 ;
return 0 ;
}
static struct V_10 * F_20 ( const char * V_56 )
{
struct V_10 * V_11 ;
for ( V_11 = V_57 ; V_11 < V_57 + F_21 ( V_57 ) ;
V_11 ++ )
if ( strcmp ( V_56 , V_11 -> V_56 ) == 0 )
return V_11 ;
return NULL ;
}
static int T_2 F_22 ( void )
{
struct V_10 * V_11 ;
const char * V_56 = V_58 ;
if ( ! F_23 () )
return - V_59 ;
if ( ! V_56 [ 0 ] ) {
if ( F_24 () )
V_56 = L_3 ;
if ( F_25 () )
V_56 = L_4 ;
if ( F_26 () )
V_56 = L_5 ;
if ( F_27 () )
V_56 = L_6 ;
if ( F_28 () )
V_56 = L_7 ;
}
V_11 = F_20 ( V_56 ) ;
if ( V_11 ) {
F_5 ( V_26 L_8
L_9 ,
V_11 -> V_16 , V_11 -> V_25 , V_11 -> V_14 ,
V_11 -> V_15 , V_11 -> V_29 , V_11 -> V_21 ) ;
memcpy ( & V_10 , V_11 , sizeof( V_10 ) ) ;
return F_29 ( & V_60 ) ;
}
return 0 ;
}
