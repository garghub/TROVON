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
unsigned long V_8 ;
if ( V_5 < 16 )
return ( ! V_5 ? 0 : V_7 -> V_9 [ V_5 ] ) ;
if ( V_7 -> V_10 & V_11 ) {
struct V_12 * V_13 ;
V_13 = (struct V_12 * ) ( V_7 -> V_9 [ V_14 ] + V_15 ) ;
V_8 = V_13 -> V_16 [ V_5 - 16 ] ;
} else if ( F_4 ( V_17 ) ) {
struct V_18 T_1 * V_19 ;
V_19 = (struct V_18 T_1 * ) ( ( unsigned long ) ( ( V_20 ) V_7 -> V_9 [ V_14 ] ) ) ;
F_5 ( V_8 , & V_19 -> V_16 [ V_5 - 16 ] ) ;
} else {
struct V_12 T_1 * V_13 ;
V_13 = (struct V_12 T_1 * ) ( V_7 -> V_9 [ V_14 ] + V_15 ) ;
F_5 ( V_8 , & V_13 -> V_16 [ V_5 - 16 ] ) ;
}
return V_8 ;
}
static inline unsigned long T_1 * F_6 ( unsigned int V_5 ,
struct V_6 * V_7 )
{
F_7 ( V_5 < 16 ) ;
F_7 ( V_7 -> V_10 & V_11 ) ;
if ( F_4 ( V_17 ) ) {
struct V_18 T_1 * V_19 ;
V_19 = (struct V_18 T_1 * ) ( ( unsigned long ) ( ( V_20 ) V_7 -> V_9 [ V_14 ] ) ) ;
return ( unsigned long T_1 * ) & V_19 -> V_16 [ V_5 - 16 ] ;
} else {
struct V_12 T_1 * V_13 ;
V_13 = (struct V_12 T_1 * ) ( V_7 -> V_9 [ V_14 ] + V_15 ) ;
return & V_13 -> V_16 [ V_5 - 16 ] ;
}
}
static inline unsigned long * F_8 ( unsigned int V_5 ,
struct V_6 * V_7 )
{
F_7 ( V_5 >= 16 ) ;
F_7 ( V_7 -> V_10 & V_11 ) ;
return & V_7 -> V_9 [ V_5 ] ;
}
static void F_9 ( struct V_6 * V_7 , unsigned long V_21 , unsigned long V_3 )
{
if ( V_3 < 16 ) {
unsigned long * V_22 = F_8 ( V_3 , V_7 ) ;
* V_22 = V_21 ;
} else {
unsigned long T_1 * V_23 = F_6 ( V_3 , V_7 ) ;
if ( F_4 ( V_17 ) )
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
if ( F_4 ( V_17 ) ) {
V_1 = V_1 & 0xffffffff ;
V_2 = V_2 & 0xffffffff ;
}
switch ( V_28 ) {
default:
case V_34 :
case V_35 :
V_32 = V_36 [ V_1 & 0x7 ] . V_32 ;
V_33 = V_36 [ V_2 & 0x7 ] . V_33 ;
break;
case V_37 :
case V_38 :
V_32 = V_39 [ V_1 & 0x7 ] . V_32 ;
V_33 = V_39 [ V_2 & 0x7 ] . V_33 ;
break;
case V_40 :
case V_41 :
V_32 = V_42 [ ( V_1 >> 1 ) & 0x3 ] . V_32 ;
V_33 = V_42 [ ( V_2 >> 1 ) & 0x3 ] . V_33 ;
break;
case V_43 :
case V_44 :
V_32 = V_45 [ ( V_1 >> 1 ) & 0x3 ] . V_32 ;
V_33 = V_45 [ ( V_2 >> 1 ) & 0x3 ] . V_33 ;
break;
case V_46 :
case V_47 :
V_32 = V_48 [ ( V_1 >> 2 ) & 0x1 ] . V_32 ;
V_33 = V_48 [ ( V_2 >> 2 ) & 0x1 ] . V_33 ;
break;
case V_49 :
case V_50 :
V_32 = V_51 [ ( V_1 >> 2 ) & 0x1 ] . V_32 ;
V_33 = V_51 [ ( V_2 >> 2 ) & 0x1 ] . V_33 ;
break;
}
if ( ( V_1 & ~ 0x7UL ) == ( V_2 & ~ 0x7UL ) )
V_31 = V_33 & V_32 ;
else
V_31 = V_32 ;
F_9 ( V_7 , V_31 , F_18 ( V_27 ) ) ;
switch ( V_28 ) {
case V_34 :
case V_37 :
case V_40 :
case V_43 :
case V_46 :
case V_49 : {
unsigned long V_52 , V_10 ;
__asm__ __volatile__("subcc %1, %2, %%g0\n\t"
"rd %%ccr, %0"
: "=r" (ccr)
: "r" (orig_rs1), "r" (orig_rs2)
: "cc");
V_10 = V_7 -> V_10 & ~ ( V_53 | V_54 ) ;
V_7 -> V_10 = V_10 | ( V_52 << 32UL ) ;
}
}
}
static void F_19 ( struct V_6 * V_7 , unsigned int V_27 , unsigned int V_28 )
{
unsigned long V_1 , V_2 , V_31 ;
unsigned int V_55 , V_56 ;
F_1 ( F_16 ( V_27 ) , F_17 ( V_27 ) , F_18 ( V_27 ) , 0 ) ;
V_1 = F_3 ( F_16 ( V_27 ) , V_7 ) ;
V_2 = F_3 ( F_17 ( V_27 ) , V_7 ) ;
V_55 = ( V_2 > 5 ? 5 : V_2 ) ;
V_56 = ( 1UL << V_55 ) - 1UL ;
V_31 = ( ( ( ( V_1 >> 11 ) & 0x3 ) << 0 ) |
( ( ( V_1 >> 33 ) & 0x3 ) << 2 ) |
( ( ( V_1 >> 55 ) & 0x1 ) << 4 ) |
( ( ( V_1 >> 13 ) & 0xf ) << 5 ) |
( ( ( V_1 >> 35 ) & 0xf ) << 9 ) |
( ( ( V_1 >> 56 ) & 0xf ) << 13 ) |
( ( ( V_1 >> 17 ) & V_56 ) << 17 ) |
( ( ( V_1 >> 39 ) & V_56 ) << ( 17 + V_55 ) ) |
( ( ( V_1 >> 60 ) & 0xf ) << ( 17 + ( 2 * V_55 ) ) ) ) ;
switch ( V_28 ) {
case V_57 :
V_31 <<= 1 ;
break;
case V_58 :
V_31 <<= 2 ;
}
F_9 ( V_7 , V_31 , F_18 ( V_27 ) ) ;
}
static void F_20 ( struct V_6 * V_7 , unsigned int V_27 )
{
unsigned long V_1 , V_2 , V_31 , V_59 ;
F_1 ( F_16 ( V_27 ) , F_17 ( V_27 ) , F_18 ( V_27 ) , 0 ) ;
V_1 = F_3 ( F_16 ( V_27 ) , V_7 ) ;
V_2 = F_3 ( F_17 ( V_27 ) , V_7 ) ;
V_31 = V_1 + V_2 ;
F_9 ( V_7 , V_31 , F_18 ( V_27 ) ) ;
V_59 = F_21 () -> V_59 [ 0 ] & 0xffffffff ;
V_59 |= V_31 << 32UL ;
F_21 () -> V_59 [ 0 ] = V_59 ;
}
static void F_22 ( struct V_6 * V_7 , unsigned int V_27 )
{
struct V_24 * V_25 = V_60 ;
unsigned long V_1 , V_2 , V_31 ;
unsigned long F_20 , V_61 ;
F_20 = F_21 () -> V_59 [ 0 ] >> 32UL ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0UL ;
for ( V_61 = 0 ; V_61 < 8 ; V_61 ++ ) {
unsigned long V_62 = ( F_20 >> ( V_61 * 4 ) ) & 0xf ;
unsigned long V_63 ;
if ( V_62 < 8 )
V_63 = ( V_1 >> ( V_62 * 8 ) ) & 0xff ;
else
V_63 = ( V_2 >> ( ( V_62 - 8 ) * 8 ) ) & 0xff ;
V_31 |= ( V_63 << ( V_61 * 8 ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
}
static void F_23 ( struct V_6 * V_7 , unsigned int V_27 )
{
struct V_24 * V_25 = V_60 ;
unsigned long V_1 , V_2 , * V_3 , V_31 ;
unsigned long V_61 ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_3 = F_12 ( V_25 , F_18 ( V_27 ) ) ;
V_31 = * V_3 ;
for ( V_61 = 0 ; V_61 < 8 ; V_61 ++ ) {
T_3 V_64 , V_65 ;
V_64 = ( V_1 >> ( 56 - ( V_61 * 8 ) ) ) & 0xff ;
V_65 = ( V_2 >> ( 56 - ( V_61 * 8 ) ) ) & 0xff ;
V_64 -= V_65 ;
if ( V_64 < 0 )
V_64 = ~ V_64 + 1 ;
V_31 += V_64 ;
}
* V_3 = V_31 ;
}
static void F_24 ( struct V_6 * V_7 , unsigned int V_27 , unsigned int V_28 )
{
struct V_24 * V_25 = V_60 ;
unsigned long V_1 , V_2 , V_59 , V_66 , V_31 ;
V_59 = F_21 () -> V_59 [ 0 ] ;
V_66 = ( V_59 >> 3 ) & ( V_28 == V_67 ? 0xf : 0x1f ) ;
switch ( V_28 ) {
case V_67 : {
unsigned long V_63 ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
unsigned int V_21 ;
T_3 V_68 = ( V_2 >> ( V_63 * 16UL ) ) & 0xffffUL ;
int V_69 = V_68 << V_66 ;
int V_70 = V_69 >> 7 ;
V_21 = ( ( V_70 < 0 ) ?
0 :
( V_70 > 255 ) ?
255 : V_70 ) ;
V_31 |= ( V_21 << ( 8 * V_63 ) ) ;
}
* F_14 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_71 : {
unsigned long V_72 ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = ( V_1 << 8 ) & ~ ( 0x000000ff000000ffUL ) ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
unsigned long V_21 ;
T_4 V_68 = ( V_2 >> ( V_72 * 32UL ) ) ;
T_5 V_69 = V_68 << V_66 ;
T_5 V_70 = V_69 >> 23 ;
V_21 = ( ( V_70 < 0 ) ?
0 :
( V_70 > 255 ) ?
255 : V_70 ) ;
V_31 |= ( V_21 << ( 32 * V_72 ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_73 : {
unsigned long V_72 ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
long V_21 ;
T_4 V_68 = ( V_2 >> ( V_72 * 32UL ) ) ;
T_5 V_69 = V_68 << V_66 ;
T_5 V_70 = V_69 >> 16 ;
V_21 = ( ( V_70 < - 32768 ) ?
- 32768 :
( V_70 > 32767 ) ?
32767 : V_70 ) ;
V_31 |= ( ( V_21 & 0xffff ) << ( V_72 * 16 ) ) ;
}
* F_14 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_74 : {
unsigned long V_63 ;
V_2 = F_13 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
unsigned long V_21 ;
T_6 V_68 = ( V_2 >> ( V_63 * 8 ) ) & 0xff ;
V_21 = V_68 << 4 ;
V_31 |= ( V_21 << ( V_63 * 16 ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_75 : {
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
static void F_25 ( struct V_6 * V_7 , unsigned int V_27 , unsigned int V_28 )
{
struct V_24 * V_25 = V_60 ;
unsigned long V_1 , V_2 , V_31 ;
switch ( V_28 ) {
case V_76 : {
unsigned long V_63 ;
V_1 = F_13 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
T_2 V_77 = ( V_1 >> ( V_63 * 8 ) ) & 0x00ff ;
T_3 V_78 = ( V_2 >> ( V_63 * 16 ) ) & 0xffff ;
V_20 V_79 = V_77 * V_78 ;
T_2 V_69 = ( ( V_79 & 0x00ffff00 ) >> 8 ) ;
if ( V_79 & 0x80 )
V_69 ++ ;
V_31 |= ( ( V_69 & 0xffffUL ) << ( V_63 * 16UL ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_80 :
case V_81 : {
unsigned long V_63 ;
T_3 V_78 ;
V_1 = F_13 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_13 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
V_78 = V_2 >> ( V_28 == V_80 ? 16 : 0 ) ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
T_2 V_77 = ( V_1 >> ( V_63 * 8 ) ) & 0x00ff ;
V_20 V_79 = V_77 * V_78 ;
T_2 V_69 = ( ( V_79 & 0x00ffff00 ) >> 8 ) ;
if ( V_79 & 0x80 )
V_69 ++ ;
V_31 |= ( ( V_69 & 0xffffUL ) << ( V_63 * 16UL ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_82 :
case V_83 : {
unsigned long V_63 , V_84 ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
V_84 = ( V_28 == V_82 ) ? 8 : 0 ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
T_2 V_77 ;
T_3 V_78 ;
V_20 V_79 ;
T_2 V_69 ;
V_77 = ( ( V_1 >> ( ( 16 * V_63 ) + V_84 ) ) & 0x00ff ) ;
V_78 = ( ( V_2 >> ( 16 * V_63 ) ) & 0xffff ) ;
V_79 = V_77 * V_78 ;
V_69 = ( ( V_79 & 0x00ffff00 ) >> 8 ) ;
if ( V_79 & 0x80 )
V_69 ++ ;
V_31 |= ( ( V_69 & 0xffffUL ) << ( V_63 * 16UL ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
case V_85 :
case V_86 : {
unsigned long V_63 , V_84 ;
V_1 = F_13 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_13 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
V_84 = ( V_28 == V_85 ) ? 8 : 0 ;
for ( V_63 = 0 ; V_63 < 2 ; V_63 ++ ) {
T_2 V_77 ;
T_3 V_78 ;
V_20 V_79 ;
T_2 V_69 ;
V_77 = ( ( V_1 >> ( ( 16 * V_63 ) + V_84 ) ) & 0x00ff ) ;
V_78 = ( ( V_2 >> ( 16 * V_63 ) ) & 0xffff ) ;
V_79 = V_77 * V_78 ;
V_69 = ( ( V_79 & 0x00ffff00 ) >> 8 ) ;
if ( V_79 & 0x80 )
V_69 ++ ;
V_31 |= ( ( V_69 & 0xffffUL ) <<
( ( V_63 * 32UL ) + 7UL ) ) ;
}
* F_12 ( V_25 , F_18 ( V_27 ) ) = V_31 ;
break;
}
}
}
static void F_26 ( struct V_6 * V_7 , unsigned int V_27 , unsigned int V_28 )
{
struct V_24 * V_25 = V_60 ;
unsigned long V_1 , V_2 , V_31 , V_61 ;
V_1 = F_11 ( V_25 , F_16 ( V_27 ) ) ;
V_2 = F_11 ( V_25 , F_17 ( V_27 ) ) ;
V_31 = 0 ;
switch ( V_28 ) {
case V_87 :
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
T_3 V_88 = ( V_1 >> ( V_61 * 16 ) ) & 0xffff ;
T_3 V_89 = ( V_2 >> ( V_61 * 16 ) ) & 0xffff ;
if ( V_88 > V_89 )
V_31 |= 1 << V_61 ;
}
break;
case V_90 :
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
T_4 V_88 = ( V_1 >> ( V_61 * 32 ) ) & 0xffff ;
T_4 V_89 = ( V_2 >> ( V_61 * 32 ) ) & 0xffff ;
if ( V_88 > V_89 )
V_31 |= 1 << V_61 ;
}
break;
case V_91 :
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
T_3 V_88 = ( V_1 >> ( V_61 * 16 ) ) & 0xffff ;
T_3 V_89 = ( V_2 >> ( V_61 * 16 ) ) & 0xffff ;
if ( V_88 <= V_89 )
V_31 |= 1 << V_61 ;
}
break;
case V_92 :
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
T_4 V_88 = ( V_1 >> ( V_61 * 32 ) ) & 0xffff ;
T_4 V_89 = ( V_2 >> ( V_61 * 32 ) ) & 0xffff ;
if ( V_88 <= V_89 )
V_31 |= 1 << V_61 ;
}
break;
case V_93 :
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
T_3 V_88 = ( V_1 >> ( V_61 * 16 ) ) & 0xffff ;
T_3 V_89 = ( V_2 >> ( V_61 * 16 ) ) & 0xffff ;
if ( V_88 != V_89 )
V_31 |= 1 << V_61 ;
}
break;
case V_94 :
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
T_4 V_88 = ( V_1 >> ( V_61 * 32 ) ) & 0xffff ;
T_4 V_89 = ( V_2 >> ( V_61 * 32 ) ) & 0xffff ;
if ( V_88 != V_89 )
V_31 |= 1 << V_61 ;
}
break;
case V_95 :
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
T_3 V_88 = ( V_1 >> ( V_61 * 16 ) ) & 0xffff ;
T_3 V_89 = ( V_2 >> ( V_61 * 16 ) ) & 0xffff ;
if ( V_88 == V_89 )
V_31 |= 1 << V_61 ;
}
break;
case V_96 :
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
T_4 V_88 = ( V_1 >> ( V_61 * 32 ) ) & 0xffff ;
T_4 V_89 = ( V_2 >> ( V_61 * 32 ) ) & 0xffff ;
if ( V_88 == V_89 )
V_31 |= 1 << V_61 ;
}
break;
}
F_1 ( 0 , 0 , F_18 ( V_27 ) , 0 ) ;
F_9 ( V_7 , V_31 , F_18 ( V_27 ) ) ;
}
int F_27 ( struct V_6 * V_7 , unsigned int V_27 )
{
unsigned long V_97 = V_7 -> V_98 ;
unsigned int V_28 ;
F_7 ( V_7 -> V_10 & V_11 ) ;
F_28 ( V_99 , 1 , V_7 , 0 ) ;
if ( F_4 ( V_17 ) )
V_97 = ( V_20 ) V_97 ;
if ( F_5 ( V_27 , ( V_20 T_1 * ) V_97 ) )
return - V_100 ;
F_29 () ;
V_28 = ( V_27 & V_101 ) >> V_102 ;
switch ( V_28 ) {
default:
return - V_103 ;
case V_67 :
case V_71 :
case V_73 :
case V_74 :
case V_75 :
F_24 ( V_7 , V_27 , V_28 ) ;
break;
case V_76 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_85 :
case V_86 :
F_25 ( V_7 , V_27 , V_28 ) ;
break;
case V_87 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
F_26 ( V_7 , V_27 , V_28 ) ;
break;
case V_34 :
case V_35 :
case V_37 :
case V_38 :
case V_40 :
case V_41 :
case V_43 :
case V_44 :
case V_46 :
case V_47 :
case V_49 :
case V_50 :
F_15 ( V_7 , V_27 , V_28 ) ;
break;
case V_104 :
F_23 ( V_7 , V_27 ) ;
break;
case V_105 :
case V_57 :
case V_58 :
F_19 ( V_7 , V_27 , V_28 ) ;
break;
case V_106 :
F_20 ( V_7 , V_27 ) ;
break;
case V_107 :
F_22 ( V_7 , V_27 ) ;
break;
}
V_7 -> V_98 = V_7 -> V_108 ;
V_7 -> V_108 += 4 ;
return 0 ;
}
