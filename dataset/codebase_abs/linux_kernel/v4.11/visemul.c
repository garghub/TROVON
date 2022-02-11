static inline void F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_4 )
{
if ( V_2 >= 16 || V_1 >= 16 || V_3 >= 16 ) {
if ( V_4 != 0 )
__asm__ __volatile__("flushw");
else
F_2 () ;
}
}
static unsigned long F_3 ( unsigned int V_5 , struct V_6 * V_7 )
{
unsigned long V_8 , V_9 ;
if ( V_5 < 16 )
return ( ! V_5 ? 0 : V_7 -> V_10 [ V_5 ] ) ;
V_9 = V_7 -> V_10 [ V_11 ] ;
if ( V_7 -> V_12 & V_13 ) {
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) ( V_9 + V_16 ) ;
V_8 = V_15 -> V_17 [ V_5 - 16 ] ;
} else if ( ! F_4 ( V_9 ) ) {
struct V_18 T_1 * V_19 ;
V_19 = (struct V_18 T_1 * ) ( ( unsigned long ) ( ( V_20 ) V_9 ) ) ;
F_5 ( V_8 , & V_19 -> V_17 [ V_5 - 16 ] ) ;
} else {
struct V_14 T_1 * V_15 ;
V_15 = (struct V_14 T_1 * ) ( V_9 + V_16 ) ;
F_5 ( V_8 , & V_15 -> V_17 [ V_5 - 16 ] ) ;
}
return V_8 ;
}
static inline unsigned long T_1 * F_6 ( unsigned int V_5 ,
struct V_6 * V_7 )
{
unsigned long V_9 = V_7 -> V_10 [ V_11 ] ;
F_7 ( V_5 < 16 ) ;
F_7 ( V_7 -> V_12 & V_13 ) ;
if ( ! F_4 ( V_9 ) ) {
struct V_18 T_1 * V_19 ;
V_19 = (struct V_18 T_1 * ) ( ( unsigned long ) ( ( V_20 ) V_9 ) ) ;
return ( unsigned long T_1 * ) & V_19 -> V_17 [ V_5 - 16 ] ;
} else {
struct V_14 T_1 * V_15 ;
V_15 = (struct V_14 T_1 * ) ( V_9 + V_16 ) ;
return & V_15 -> V_17 [ V_5 - 16 ] ;
}
}
static inline unsigned long * F_8 ( unsigned int V_5 ,
struct V_6 * V_7 )
{
F_7 ( V_5 >= 16 ) ;
F_7 ( V_7 -> V_12 & V_13 ) ;
return & V_7 -> V_10 [ V_5 ] ;
}
static void F_9 ( struct V_6 * V_7 , unsigned long V_21 , unsigned long V_3 )
{
if ( V_3 < 16 ) {
unsigned long * V_22 = F_8 ( V_3 , V_7 ) ;
* V_22 = V_21 ;
} else {
unsigned long T_1 * V_23 = F_6 ( V_3 , V_7 ) ;
if ( ! F_4 ( V_7 -> V_10 [ V_11 ] ) )
F_10 ( ( V_20 ) V_21 , ( V_20 T_1 * ) V_23 ) ;
else
F_10 ( V_21 , V_23 ) ;
}
}
static inline unsigned long F_11 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
V_26 = ( ( ( V_26 & 1 ) << 5 ) |
( V_26 & 0x1e ) ) ;
return * ( unsigned long * ) & V_25 -> V_7 [ V_26 ] ;
}
static inline unsigned long * F_12 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
V_26 = ( ( ( V_26 & 1 ) << 5 ) |
( V_26 & 0x1e ) ) ;
return ( unsigned long * ) & V_25 -> V_7 [ V_26 ] ;
}
static inline unsigned int F_13 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
return V_25 -> V_7 [ V_26 ] ;
}
static inline unsigned int * F_14 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
return & V_25 -> V_7 [ V_26 ] ;
}
static void F_15 ( struct V_6 * V_7 , unsigned int V_27 , unsigned int V_28 )
{
unsigned long V_29 , V_1 , V_30 , V_2 , V_31 ;
T_2 V_32 , V_33 ;
F_1 ( F_16 ( V_27 ) , F_17 ( V_27 ) , F_18 ( V_27 ) , 0 ) ;
V_29 = V_1 = F_3 ( F_16 ( V_27 ) , V_7 ) ;
V_30 = V_2 = F_3 ( F_17 ( V_27 ) , V_7 ) ;
if ( F_19 ( V_34 ) ) {
V_1 = V_1 & 0xffffffff ;
V_2 = V_2 & 0xffffffff ;
}
switch ( V_28 ) {
default:
case V_35 :
case V_36 :
V_32 = V_37 [ V_1 & 0x7 ] . V_32 ;
V_33 = V_37 [ V_2 & 0x7 ] . V_33 ;
break;
case V_38 :
case V_39 :
V_32 = V_40 [ V_1 & 0x7 ] . V_32 ;
V_33 = V_40 [ V_2 & 0x7 ] . V_33 ;
break;
case V_41 :
case V_42 :
V_32 = V_43 [ ( V_1 >> 1 ) & 0x3 ] . V_32 ;
V_33 = V_43 [ ( V_2 >> 1 ) & 0x3 ] . V_33 ;
break;
case V_44 :
case V_45 :
V_32 = V_46 [ ( V_1 >> 1 ) & 0x3 ] . V_32 ;
V_33 = V_46 [ ( V_2 >> 1 ) & 0x3 ] . V_33 ;
break;
case V_47 :
case V_48 :
V_32 = V_49 [ ( V_1 >> 2 ) & 0x1 ] . V_32 ;
V_33 = V_49 [ ( V_2 >> 2 ) & 0x1 ] . V_33 ;
break;
case V_50 :
case V_51 :
V_32 = V_52 [ ( V_1 >> 2 ) & 0x1 ] . V_32 ;
V_33 = V_52 [ ( V_2 >> 2 ) & 0x1 ] . V_33 ;
break;
}
if ( ( V_1 & ~ 0x7UL ) == ( V_2 & ~ 0x7UL ) )
V_31 = V_33 & V_32 ;
else
V_31 = V_32 ;
F_9 ( V_7 , V_31 , F_18 ( V_27 ) ) ;
switch ( V_28 ) {
case V_35 :
case V_38 :
case V_41 :
case V_44 :
case V_47 :
case V_50 : {
unsigned long V_53 , V_12 ;
__asm__ __volatile__("subcc %1, %2, %%g0\n\t"
"rd %%ccr, %0"
: "=r" (ccr)
: "r" (orig_rs1), "r" (orig_rs2)
: "cc");
V_12 = V_7 -> V_12 & ~ ( V_54 | V_55 ) ;
V_7 -> V_12 = V_12 | ( V_53 << 32UL ) ;
}
}
}
static void F_20 ( struct V_6 * V_7 , unsigned int V_27 , unsigned int V_28 )
{
unsigned long V_1 , V_2 , V_31 ;
unsigned int V_56 , V_57 ;
F_1 ( F_16 ( V_27 ) , F_17 ( V_27 ) , F_18 ( V_27 ) , 0 ) ;
V_1 = F_3 ( F_16 ( V_27 ) , V_7 ) ;
V_2 = F_3 ( F_17 ( V_27 ) , V_7 ) ;
V_56 = ( V_2 > 5 ? 5 : V_2 ) ;
V_57 = ( 1UL << V_56 ) - 1UL ;
V_31 = ( ( ( ( V_1 >> 11 ) & 0x3 ) << 0 ) |
( ( ( V_1 >> 33 ) & 0x3 ) << 2 ) |
( ( ( V_1 >> 55 ) & 0x1 ) << 4 ) |
( ( ( V_1 >> 13 ) & 0xf ) << 5 ) |
( ( ( V_1 >> 35 ) & 0xf ) << 9 ) |
( ( ( V_1 >> 56 ) & 0xf ) << 13 ) |
( ( ( V_1 >> 17 ) & V_57 ) << 17 ) |
( ( ( V_1 >> 39 ) & V_57 ) << ( 17 + V_56 ) ) |
( ( ( V_1 >> 60 ) & 0xf ) << ( 17 + ( 2 * V_56 ) ) ) ) ;
switch ( V_28 ) {
case V_58 :
V_31 <<= 1 ;
break;
case V_59 :
V_31 <<= 2 ;
}
F_9 ( V_7 , V_31 , F_18 ( V_27 ) ) ;
}
static void F_21 ( struct V_6 * V_7 , unsigned int V_27 )
{
unsigned long V_1 , V_2 , V_31 , V_60 ;
F_1 ( F_16 ( V_27 ) , F_17 ( V_27 ) , F_18 ( V_27 ) , 0 ) ;
V_1 = F_3 ( F_16 ( V_27 ) , V_7 ) ;
V_2 = F_3 ( F_17 ( V_27 ) , V_7 ) ;
V_31 = V_1 + V_2 ;
F_9 ( V_7 , V_31 , F_18 ( V_27 ) ) ;
V_60 = F_22 () -> V_60 [ 0 ] & 0xffffffff ;
V_60 |= V_31 << 32UL ;
F_22 () -> V_60 [ 0 ] = V_60 ;
}
static void F_23 ( struct V_6 * V_7 , unsigned int V_27 )
{
struct V_24 * V_25 = V_61 ;
unsigned long V_1 , V_2 , V_31 ;
unsigned long F_21 , V_62 ;
F_21 = F_22 () -> V_60 [ 0 ] >> 32UL ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0UL ;
for ( V_62 = 0 ; V_62 < 8 ; V_62 ++ ) {
unsigned long V_63 = ( F_21 >> ( V_62 * 4 ) ) & 0xf ;
unsigned long V_64 ;
if ( V_63 < 8 )
V_64 = ( V_1 >> ( V_63 * 8 ) ) & 0xff ;
else
V_64 = ( V_2 >> ( ( V_63 - 8 ) * 8 ) ) & 0xff ;
V_31 |= ( V_64 << ( V_62 * 8 ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
}
static void F_24 ( struct V_6 * V_7 , unsigned int V_27 )
{
struct V_24 * V_25 = V_61 ;
unsigned long V_1 , V_2 , * V_3 , V_31 ;
unsigned long V_62 ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_3 = F_12 ( V_25 , F_18 ( V_27 ) ) ;
V_31 = * V_3 ;
for ( V_62 = 0 ; V_62 < 8 ; V_62 ++ ) {
T_3 V_65 , V_66 ;
V_65 = ( V_1 >> ( 56 - ( V_62 * 8 ) ) ) & 0xff ;
V_66 = ( V_2 >> ( 56 - ( V_62 * 8 ) ) ) & 0xff ;
V_65 -= V_66 ;
if ( V_65 < 0 )
V_65 = ~ V_65 + 1 ;
V_31 += V_65 ;
}
* V_3 = V_31 ;
}
static void F_25 ( struct V_6 * V_7 , unsigned int V_27 , unsigned int V_28 )
{
struct V_24 * V_25 = V_61 ;
unsigned long V_1 , V_2 , V_60 , V_67 , V_31 ;
V_60 = F_22 () -> V_60 [ 0 ] ;
V_67 = ( V_60 >> 3 ) & ( V_28 == V_68 ? 0xf : 0x1f ) ;
switch ( V_28 ) {
case V_68 : {
unsigned long V_64 ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
unsigned int V_21 ;
T_3 V_69 = ( V_2 >> ( V_64 * 16UL ) ) & 0xffffUL ;
int V_70 = V_69 << V_67 ;
int V_71 = V_70 >> 7 ;
V_21 = ( ( V_71 < 0 ) ?
0 :
( V_71 > 255 ) ?
255 : V_71 ) ;
V_31 |= ( V_21 << ( 8 * V_64 ) ) ;
}
* F_14 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_72 : {
unsigned long V_73 ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = ( V_1 << 8 ) & ~ ( 0x000000ff000000ffUL ) ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
unsigned long V_21 ;
T_4 V_69 = ( V_2 >> ( V_73 * 32UL ) ) ;
T_5 V_70 = V_69 << V_67 ;
T_5 V_71 = V_70 >> 23 ;
V_21 = ( ( V_71 < 0 ) ?
0 :
( V_71 > 255 ) ?
255 : V_71 ) ;
V_31 |= ( V_21 << ( 32 * V_73 ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_74 : {
unsigned long V_73 ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
long V_21 ;
T_4 V_69 = ( V_2 >> ( V_73 * 32UL ) ) ;
T_5 V_70 = V_69 << V_67 ;
T_5 V_71 = V_70 >> 16 ;
V_21 = ( ( V_71 < - 32768 ) ?
- 32768 :
( V_71 > 32767 ) ?
32767 : V_71 ) ;
V_31 |= ( ( V_21 & 0xffff ) << ( V_73 * 16 ) ) ;
}
* F_14 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_75 : {
unsigned long V_64 ;
V_2 = F_13 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
unsigned long V_21 ;
T_6 V_69 = ( V_2 >> ( V_64 * 8 ) ) & 0xff ;
V_21 = V_69 << 4 ;
V_31 |= ( V_21 << ( V_64 * 16 ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_76 : {
V_1 = F_13 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_13 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = ( ( ( V_2 & 0x000000ff ) << 0 ) |
( ( V_1 & 0x000000ff ) << 8 ) |
( ( V_2 & 0x0000ff00 ) << 8 ) |
( ( V_1 & 0x0000ff00 ) << 16 ) |
( ( V_2 & 0x00ff0000 ) << 16 ) |
( ( V_1 & 0x00ff0000 ) << 24 ) |
( ( V_2 & 0xff000000 ) << 24 ) |
( ( V_1 & 0xff000000 ) << 32 ) ) ;
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
}
}
static void F_26 ( struct V_6 * V_7 , unsigned int V_27 , unsigned int V_28 )
{
struct V_24 * V_25 = V_61 ;
unsigned long V_1 , V_2 , V_31 ;
switch ( V_28 ) {
case V_77 : {
unsigned long V_64 ;
V_1 = F_13 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
T_2 V_78 = ( V_1 >> ( V_64 * 8 ) ) & 0x00ff ;
T_3 V_79 = ( V_2 >> ( V_64 * 16 ) ) & 0xffff ;
V_20 V_80 = V_78 * V_79 ;
T_2 V_70 = ( ( V_80 & 0x00ffff00 ) >> 8 ) ;
if ( V_80 & 0x80 )
V_70 ++ ;
V_31 |= ( ( V_70 & 0xffffUL ) << ( V_64 * 16UL ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_81 :
case V_82 : {
unsigned long V_64 ;
T_3 V_79 ;
V_1 = F_13 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_13 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
V_79 = V_2 >> ( V_28 == V_81 ? 16 : 0 ) ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
T_2 V_78 = ( V_1 >> ( V_64 * 8 ) ) & 0x00ff ;
V_20 V_80 = V_78 * V_79 ;
T_2 V_70 = ( ( V_80 & 0x00ffff00 ) >> 8 ) ;
if ( V_80 & 0x80 )
V_70 ++ ;
V_31 |= ( ( V_70 & 0xffffUL ) << ( V_64 * 16UL ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_83 :
case V_84 : {
unsigned long V_64 , V_85 ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
V_85 = ( V_28 == V_83 ) ? 8 : 0 ;
for ( V_64 = 0 ; V_64 < 4 ; V_64 ++ ) {
T_2 V_78 ;
T_3 V_79 ;
V_20 V_80 ;
T_2 V_70 ;
V_78 = ( ( V_1 >> ( ( 16 * V_64 ) + V_85 ) ) & 0x00ff ) ;
V_79 = ( ( V_2 >> ( 16 * V_64 ) ) & 0xffff ) ;
V_80 = V_78 * V_79 ;
V_70 = ( ( V_80 & 0x00ffff00 ) >> 8 ) ;
if ( V_80 & 0x80 )
V_70 ++ ;
V_31 |= ( ( V_70 & 0xffffUL ) << ( V_64 * 16UL ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_86 :
case V_87 : {
unsigned long V_64 , V_85 ;
V_1 = F_13 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_13 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
V_85 = ( V_28 == V_86 ) ? 8 : 0 ;
for ( V_64 = 0 ; V_64 < 2 ; V_64 ++ ) {
T_2 V_78 ;
T_3 V_79 ;
V_20 V_80 ;
T_2 V_70 ;
V_78 = ( ( V_1 >> ( ( 16 * V_64 ) + V_85 ) ) & 0x00ff ) ;
V_79 = ( ( V_2 >> ( 16 * V_64 ) ) & 0xffff ) ;
V_80 = V_78 * V_79 ;
V_70 = ( ( V_80 & 0x00ffff00 ) >> 8 ) ;
if ( V_80 & 0x80 )
V_70 ++ ;
V_31 |= ( ( V_70 & 0xffffUL ) <<
( ( V_64 * 32UL ) + 7UL ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
}
}
static void F_27 ( struct V_6 * V_7 , unsigned int V_27 , unsigned int V_28 )
{
struct V_24 * V_25 = V_61 ;
unsigned long V_1 , V_2 , V_31 , V_62 ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
switch ( V_28 ) {
case V_88 :
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
T_3 V_89 = ( V_1 >> ( V_62 * 16 ) ) & 0xffff ;
T_3 V_90 = ( V_2 >> ( V_62 * 16 ) ) & 0xffff ;
if ( V_89 > V_90 )
V_31 |= 8 >> V_62 ;
}
break;
case V_91 :
for ( V_62 = 0 ; V_62 < 2 ; V_62 ++ ) {
T_4 V_89 = ( V_1 >> ( V_62 * 32 ) ) & 0xffffffff ;
T_4 V_90 = ( V_2 >> ( V_62 * 32 ) ) & 0xffffffff ;
if ( V_89 > V_90 )
V_31 |= 2 >> V_62 ;
}
break;
case V_92 :
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
T_3 V_89 = ( V_1 >> ( V_62 * 16 ) ) & 0xffff ;
T_3 V_90 = ( V_2 >> ( V_62 * 16 ) ) & 0xffff ;
if ( V_89 <= V_90 )
V_31 |= 8 >> V_62 ;
}
break;
case V_93 :
for ( V_62 = 0 ; V_62 < 2 ; V_62 ++ ) {
T_4 V_89 = ( V_1 >> ( V_62 * 32 ) ) & 0xffffffff ;
T_4 V_90 = ( V_2 >> ( V_62 * 32 ) ) & 0xffffffff ;
if ( V_89 <= V_90 )
V_31 |= 2 >> V_62 ;
}
break;
case V_94 :
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
T_3 V_89 = ( V_1 >> ( V_62 * 16 ) ) & 0xffff ;
T_3 V_90 = ( V_2 >> ( V_62 * 16 ) ) & 0xffff ;
if ( V_89 != V_90 )
V_31 |= 8 >> V_62 ;
}
break;
case V_95 :
for ( V_62 = 0 ; V_62 < 2 ; V_62 ++ ) {
T_4 V_89 = ( V_1 >> ( V_62 * 32 ) ) & 0xffffffff ;
T_4 V_90 = ( V_2 >> ( V_62 * 32 ) ) & 0xffffffff ;
if ( V_89 != V_90 )
V_31 |= 2 >> V_62 ;
}
break;
case V_96 :
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
T_3 V_89 = ( V_1 >> ( V_62 * 16 ) ) & 0xffff ;
T_3 V_90 = ( V_2 >> ( V_62 * 16 ) ) & 0xffff ;
if ( V_89 == V_90 )
V_31 |= 8 >> V_62 ;
}
break;
case V_97 :
for ( V_62 = 0 ; V_62 < 2 ; V_62 ++ ) {
T_4 V_89 = ( V_1 >> ( V_62 * 32 ) ) & 0xffffffff ;
T_4 V_90 = ( V_2 >> ( V_62 * 32 ) ) & 0xffffffff ;
if ( V_89 == V_90 )
V_31 |= 2 >> V_62 ;
}
break;
}
F_1 ( 0 , 0 , F_18 ( V_27 ) , 0 ) ;
F_9 ( V_7 , V_31 , F_18 ( V_27 ) ) ;
}
int F_28 ( struct V_6 * V_7 , unsigned int V_27 )
{
unsigned long V_98 = V_7 -> V_99 ;
unsigned int V_28 ;
F_7 ( V_7 -> V_12 & V_13 ) ;
F_29 ( V_100 , 1 , V_7 , 0 ) ;
if ( F_19 ( V_34 ) )
V_98 = ( V_20 ) V_98 ;
if ( F_5 ( V_27 , ( V_20 T_1 * ) V_98 ) )
return - V_101 ;
F_30 () ;
V_28 = ( V_27 & V_102 ) >> V_103 ;
switch ( V_28 ) {
default:
return - V_104 ;
case V_68 :
case V_72 :
case V_74 :
case V_75 :
case V_76 :
F_25 ( V_7 , V_27 , V_28 ) ;
break;
case V_77 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_86 :
case V_87 :
F_26 ( V_7 , V_27 , V_28 ) ;
break;
case V_88 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
F_27 ( V_7 , V_27 , V_28 ) ;
break;
case V_35 :
case V_36 :
case V_38 :
case V_39 :
case V_41 :
case V_42 :
case V_44 :
case V_45 :
case V_47 :
case V_48 :
case V_50 :
case V_51 :
F_15 ( V_7 , V_27 , V_28 ) ;
break;
case V_105 :
F_24 ( V_7 , V_27 ) ;
break;
case V_106 :
case V_58 :
case V_59 :
F_20 ( V_7 , V_27 , V_28 ) ;
break;
case V_107 :
F_21 ( V_7 , V_27 ) ;
break;
case V_108 :
F_23 ( V_7 , V_27 ) ;
break;
}
V_7 -> V_99 = V_7 -> V_109 ;
V_7 -> V_109 += 4 ;
return 0 ;
}
