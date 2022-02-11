static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_3 , & V_4 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_7 -> V_8 ,
L_1 , V_3 ) ;
return 0 ;
}
return ( T_1 ) V_4 ;
}
static inline int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_9 , T_1 * V_10 )
{
return F_5 ( V_2 -> V_6 , V_3 , V_10 , V_9 ) ;
}
static inline int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
return F_7 ( V_2 -> V_6 , V_3 , V_4 ) ;
}
static inline int F_8 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_9 , const T_1 * V_10 )
{
return F_9 ( V_2 -> V_6 , V_3 , V_10 , V_9 ) ;
}
static inline int F_10 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_11 , T_1 V_4 )
{
return F_11 ( V_2 -> V_6 , V_3 , V_11 , V_4 ) ;
}
static inline T_1 F_12 ( int V_12 )
{
if ( V_12 > 5 )
return V_13 + ( V_12 - 6 ) ;
return V_14 + ( V_15 * V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_16 * V_17 )
{
T_1 V_10 [ V_15 ] ;
switch ( V_3 ) {
case V_13 :
case V_18 :
V_10 [ 0 ] = F_1 ( V_2 , V_3 ) ;
V_17 -> V_19 = V_10 [ 0 ] ;
V_17 -> V_20 = 0 ;
V_17 -> V_21 = 1 ;
break;
default:
F_4 ( V_2 , V_3 , V_15 , V_10 ) ;
V_17 -> V_19 = ( ( V_10 [ 2 ] & 0x03 ) << 16 ) | ( V_10 [ 3 ] << 8 ) | V_10 [ 4 ] ;
V_17 -> V_20 = ( ( V_10 [ 5 ] & 0x0f ) << 16 ) | ( V_10 [ 6 ] << 8 ) | V_10 [ 7 ] ;
V_17 -> V_21 = ( ( V_10 [ 5 ] & 0xf0 ) << 12 ) | ( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ;
}
V_17 -> V_22 = 1 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_16 * V_17 )
{
T_1 V_10 [ V_15 ] ;
switch ( V_3 ) {
case V_13 :
case V_18 :
V_10 [ 0 ] = V_17 -> V_19 & 0xff ;
F_6 ( V_2 , V_3 , V_10 [ 0 ] ) ;
break;
default:
V_10 [ 0 ] = ( ( V_17 -> V_21 & 0x0ff00 ) >> 8 ) & 0xff ;
V_10 [ 1 ] = V_17 -> V_21 & 0xff ;
V_10 [ 2 ] = F_1 ( V_2 , V_3 + 2 ) & ~ 0x03 ;
V_10 [ 2 ] |= ( ( V_17 -> V_19 & 0x30000 ) >> 16 ) & 0x03 ;
V_10 [ 3 ] = ( ( V_17 -> V_19 & 0x0ff00 ) >> 8 ) & 0xff ;
V_10 [ 4 ] = V_17 -> V_19 & 0xff ;
V_10 [ 5 ] = ( ( V_17 -> V_21 & 0xf0000 ) >> 12 ) |
( ( V_17 -> V_20 & 0xf0000 ) >> 16 ) ;
V_10 [ 6 ] = ( ( V_17 -> V_20 & 0x0ff00 ) >> 8 ) & 0xff ;
V_10 [ 7 ] = V_17 -> V_20 & 0xff ;
F_8 ( V_2 , V_3 , V_15 , V_10 ) ;
}
}
static bool F_15 ( struct V_23 * V_8 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_24 :
case V_25 :
case V_26 :
return true ;
}
return false ;
}
static bool F_16 ( struct V_23 * V_8 , unsigned int V_3 )
{
if ( V_3 >= 4 && V_3 <= 8 )
return false ;
if ( V_3 >= 10 && V_3 <= 14 )
return false ;
if ( V_3 >= 173 && V_3 <= 176 )
return false ;
if ( V_3 >= 178 && V_3 <= 182 )
return false ;
if ( V_3 == V_24 )
return false ;
return true ;
}
static int F_17 ( struct V_27 * V_28 )
{
struct V_1 * V_2 =
F_18 ( V_28 , struct V_1 , V_29 ) ;
F_10 ( V_2 , V_30 ,
V_31 , V_31 ) ;
return 0 ;
}
static void F_19 ( struct V_27 * V_28 )
{
struct V_1 * V_2 =
F_18 ( V_28 , struct V_1 , V_29 ) ;
F_10 ( V_2 , V_30 ,
V_31 , 0 ) ;
}
static int F_20 ( struct V_27 * V_28 )
{
struct V_1 * V_2 =
F_18 ( V_28 , struct V_1 , V_32 ) ;
F_10 ( V_2 , V_30 ,
V_33 , V_33 ) ;
return 0 ;
}
static void F_21 ( struct V_27 * V_28 )
{
struct V_1 * V_2 =
F_18 ( V_28 , struct V_1 , V_32 ) ;
F_10 ( V_2 , V_30 ,
V_33 , 0 ) ;
}
static unsigned long F_22 ( struct V_27 * V_28 ,
unsigned long V_34 )
{
struct V_1 * V_2 =
F_18 ( V_28 , struct V_1 , V_32 ) ;
unsigned long V_35 ;
unsigned char V_36 ;
V_35 = V_34 ;
if ( V_34 > 160000000 ) {
V_36 = V_37 ;
V_35 /= 8 ;
} else if ( V_34 > 80000000 ) {
V_36 = V_38 ;
V_35 /= 4 ;
} else if ( V_34 > 40000000 ) {
V_36 = V_39 ;
V_35 /= 2 ;
} else {
V_36 = V_40 ;
}
F_10 ( V_2 , V_41 ,
V_42 , V_36 ) ;
F_23 ( & V_2 -> V_7 -> V_8 , L_2 ,
V_43 , ( 1 << ( V_36 >> 6 ) ) , V_35 ) ;
return V_35 ;
}
static int F_24 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
F_25 ( & V_45 -> V_2 -> V_7 -> V_8 , L_3 ) ;
return 0 ;
}
static void F_26 ( struct V_27 * V_28 )
{
}
static unsigned long F_27 ( struct V_27 * V_28 ,
unsigned long V_34 )
{
return 0 ;
}
static int F_28 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long V_46 )
{
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_12 , enum V_47 V_46 )
{
T_1 V_11 = ( V_12 == 0 ) ? V_48 : V_49 ;
if ( V_46 == V_50 )
return 0 ;
if ( V_12 > 2 )
return - V_51 ;
if ( V_2 -> V_52 != V_53 &&
V_46 != V_54 )
return - V_51 ;
F_10 ( V_2 , V_41 , V_11 ,
( V_46 == V_54 ) ? 0 : V_11 ) ;
return 0 ;
}
static unsigned char F_30 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_11 = ( V_45 -> V_12 == 0 ) ? V_48 : V_49 ;
T_1 V_4 ;
V_4 = F_1 ( V_45 -> V_2 , V_41 ) ;
return ( V_4 & V_11 ) ? 1 : 0 ;
}
static int F_31 ( struct V_27 * V_28 , T_1 V_55 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
if ( V_45 -> V_2 -> V_52 != V_53 &&
V_55 > 0 )
return - V_56 ;
if ( V_55 > 1 )
return - V_51 ;
return F_29 ( V_45 -> V_2 , V_45 -> V_12 ,
( V_55 == 0 ) ? V_54 :
V_57 ) ;
}
static unsigned long F_32 ( struct V_27 * V_28 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_3 = ( V_45 -> V_12 == 0 ) ? V_58 :
V_59 ;
unsigned long long V_35 ;
if ( ! V_45 -> V_17 . V_22 )
F_13 ( V_45 -> V_2 , V_3 , & V_45 -> V_17 ) ;
if ( V_45 -> V_17 . V_21 == 0 )
return V_34 ;
V_35 = V_45 -> V_17 . V_19 * V_45 -> V_17 . V_21 ;
V_35 += 512 * V_45 -> V_17 . V_21 ;
V_35 += V_45 -> V_17 . V_20 ;
V_35 *= V_34 ;
F_33 ( V_35 , 128 * V_45 -> V_17 . V_21 ) ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_4 ,
V_43 , F_34 ( V_28 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_34 , ( unsigned long ) V_35 ) ;
return ( unsigned long ) V_35 ;
}
static long F_35 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long * V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned long V_60 , V_61 , V_62 , V_63 , V_64 ;
unsigned long long V_65 ;
if ( V_35 < V_66 )
V_35 = V_66 ;
if ( V_35 > V_67 )
V_35 = V_67 ;
V_62 = V_35 / * V_34 ;
if ( V_62 < V_68 )
V_35 = * V_34 * V_68 ;
if ( V_62 > V_69 )
V_35 = * V_34 * V_69 ;
V_61 = 1000 * 1000 ;
V_65 = V_35 % ( * V_34 ) ;
V_65 *= V_61 ;
F_33 ( V_65 , * V_34 ) ;
V_60 = ( unsigned long ) V_65 ;
V_63 = 0 ;
V_64 = 1 ;
if ( V_60 )
F_36 ( V_60 , V_61 ,
V_70 , V_71 , & V_63 , & V_64 ) ;
V_45 -> V_17 . V_21 = V_64 ;
V_45 -> V_17 . V_20 = ( 128 * V_63 ) % V_64 ;
V_45 -> V_17 . V_19 = 128 * V_62 ;
V_45 -> V_17 . V_19 += ( 128 * V_63 / V_64 ) ;
V_45 -> V_17 . V_19 -= 512 ;
V_65 = * V_34 ;
V_65 *= V_63 ;
F_33 ( V_65 , V_64 ) ;
V_35 = ( unsigned long ) V_65 ;
V_35 += * V_34 * V_62 ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_5 ,
V_43 , F_34 ( V_28 ) , V_62 , V_63 , V_64 ,
* V_34 , V_35 ) ;
return V_35 ;
}
static int F_37 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_3 = ( V_45 -> V_12 == 0 ) ? V_58 :
V_59 ;
F_14 ( V_45 -> V_2 , V_3 , & V_45 -> V_17 ) ;
F_10 ( V_45 -> V_2 , V_72 + V_45 -> V_12 ,
V_73 ,
( V_45 -> V_17 . V_20 == 0 ) ? V_73 : 0 ) ;
F_6 ( V_45 -> V_2 , V_26 ,
V_45 -> V_12 == 0 ? V_74 :
V_75 ) ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_4 ,
V_43 , F_34 ( V_28 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
int V_12 , enum V_76 V_46 )
{
if ( V_46 == V_77 )
return 0 ;
if ( V_12 > 8 )
return - V_51 ;
F_10 ( V_2 , V_78 + V_12 , V_79 ,
( V_46 == V_80 ) ? 0 :
V_79 ) ;
return 0 ;
}
static unsigned char F_39 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_4 ;
V_4 = F_1 ( V_45 -> V_2 , V_78 + V_45 -> V_12 ) ;
return ( V_4 & V_79 ) ? 1 : 0 ;
}
static int F_40 ( struct V_27 * V_28 , T_1 V_55 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
return F_38 ( V_45 -> V_2 , V_45 -> V_12 ,
( V_55 == 0 ) ? V_80 :
V_81 ) ;
}
static unsigned long F_41 ( struct V_27 * V_28 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_3 = F_12 ( V_45 -> V_12 ) ;
unsigned long long V_35 ;
unsigned long V_82 ;
if ( ! V_45 -> V_17 . V_22 )
F_13 ( V_45 -> V_2 , V_3 , & V_45 -> V_17 ) ;
V_35 = V_34 ;
if ( V_45 -> V_12 > 5 ) {
V_82 = V_45 -> V_17 . V_19 ;
} else if ( V_45 -> V_17 . V_21 == 0 ) {
return V_34 ;
} else if ( ( F_1 ( V_45 -> V_2 , V_3 + 2 ) &
V_83 ) == V_83 ) {
V_82 = 4 ;
} else {
V_35 *= 128 * V_45 -> V_17 . V_21 ;
V_82 = V_45 -> V_17 . V_19 * V_45 -> V_17 . V_21 ;
V_82 += V_45 -> V_17 . V_20 ;
V_82 += 512 * V_45 -> V_17 . V_21 ;
}
if ( V_82 == 0 )
return 0 ;
F_33 ( V_35 , V_82 ) ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_6 ,
V_43 , F_34 ( V_28 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_82 , V_34 , ( unsigned long ) V_35 ) ;
return ( unsigned long ) V_35 ;
}
static long F_42 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long * V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned long long V_65 ;
unsigned long V_62 , V_63 , V_64 ;
int V_84 ;
if ( V_45 -> V_12 >= 6 && V_35 > V_85 )
V_35 = V_85 ;
if ( V_35 > V_86 )
V_35 = V_86 ;
if ( V_35 < V_87 )
V_35 = V_87 ;
V_84 = 0 ;
if ( V_35 > V_88 )
V_84 = 1 ;
if ( F_43 ( V_28 ) & V_89 ) {
if ( V_84 == 0 ) {
V_65 = V_67 ;
F_33 ( V_65 , V_35 ) ;
V_62 = ( unsigned long ) V_65 ;
} else
V_62 = 4 ;
V_63 = 0 ;
V_64 = 1 ;
* V_34 = V_62 * V_35 ;
} else if ( V_45 -> V_12 >= 6 ) {
V_62 = F_44 ( * V_34 , V_35 ) ;
if ( V_62 < V_90 )
V_62 = V_90 ;
if ( V_62 > V_91 )
V_62 = V_91 ;
V_63 = 0 ;
V_64 = 1 ;
} else {
unsigned long V_60 , V_61 ;
if ( V_84 ) {
V_35 = V_88 ;
V_84 = 0 ;
}
V_62 = * V_34 / V_35 ;
if ( V_62 < V_90 )
V_62 = V_90 ;
if ( V_62 > V_92 )
V_62 = V_92 ;
V_61 = 1000 * 1000 ;
V_65 = ( * V_34 ) % V_35 ;
V_65 *= V_61 ;
F_33 ( V_65 , V_35 ) ;
V_60 = ( unsigned long ) V_65 ;
V_63 = 0 ;
V_64 = 1 ;
if ( V_60 )
F_36 ( V_60 , V_61 ,
V_93 , V_94 ,
& V_63 , & V_64 ) ;
}
V_65 = * V_34 ;
V_65 *= V_64 ;
F_33 ( V_65 , V_62 * V_64 + V_63 ) ;
V_35 = ( unsigned long ) V_65 ;
if ( V_84 ) {
V_45 -> V_17 . V_21 = 1 ;
V_45 -> V_17 . V_20 = 0 ;
V_45 -> V_17 . V_19 = 0 ;
} else if ( V_45 -> V_12 >= 6 ) {
V_45 -> V_17 . V_21 = 0 ;
V_45 -> V_17 . V_20 = 0 ;
V_45 -> V_17 . V_19 = V_62 ;
} else {
V_45 -> V_17 . V_21 = V_64 ;
V_45 -> V_17 . V_20 = ( 128 * V_63 ) % V_64 ;
V_45 -> V_17 . V_19 = 128 * V_62 ;
V_45 -> V_17 . V_19 += ( 128 * V_63 / V_64 ) ;
V_45 -> V_17 . V_19 -= 512 ;
}
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_7 ,
V_43 , F_34 ( V_28 ) , V_62 , V_63 , V_64 , V_84 ,
* V_34 , V_35 ) ;
return V_35 ;
}
static int F_45 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_3 = F_12 ( V_45 -> V_12 ) ;
int V_84 = 0 ;
F_14 ( V_45 -> V_2 , V_3 , & V_45 -> V_17 ) ;
if ( V_35 > V_88 )
V_84 = 1 ;
if ( V_45 -> V_12 < 6 ) {
F_10 ( V_45 -> V_2 , V_3 + 2 ,
V_83 ,
( V_84 ) ? V_83 : 0 ) ;
F_10 ( V_45 -> V_2 , V_78 + V_45 -> V_12 ,
V_73 ,
( V_45 -> V_17 . V_20 == 0 ) ? V_73 : 0 ) ;
}
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_8 ,
V_43 , F_34 ( V_28 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_84 , V_34 , V_35 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
int V_12 , enum V_95 V_46 )
{
T_1 V_4 ;
if ( V_12 > 8 )
return - V_51 ;
switch ( V_46 ) {
case V_96 :
V_4 = V_97 ;
break;
case V_98 :
if ( V_12 == 0 || V_12 == 4 )
V_4 = V_97 ;
else
V_4 = V_99 ;
break;
case V_100 :
V_4 = V_101 ;
break;
case V_102 :
if ( V_2 -> V_52 != V_53 )
return - V_51 ;
V_4 = V_103 ;
break;
default:
return 0 ;
}
F_10 ( V_2 , V_78 + V_12 ,
V_104 , V_4 ) ;
return 0 ;
}
static int F_47 (
struct V_1 * V_2 , int V_12 ,
enum V_105 V_106 )
{
T_1 V_11 ;
if ( V_12 > 8 )
return - V_51 ;
switch ( V_106 ) {
case V_107 :
V_11 = V_108 ;
break;
case V_109 :
V_11 = V_110 ;
break;
case V_111 :
V_11 = V_112 ;
break;
case V_113 :
V_11 = V_114 ;
break;
default:
return 0 ;
}
F_10 ( V_2 , V_78 + V_12 ,
V_115 , V_11 ) ;
return 0 ;
}
static int F_48 (
struct V_1 * V_2 , int V_12 ,
enum V_116 V_117 )
{
T_1 V_3 = ( V_12 < 4 ) ? V_118 :
V_119 ;
T_1 V_120 = ( V_12 < 4 ) ? ( 2 * V_12 ) : ( 2 * ( V_12 - 4 ) ) ;
T_1 V_11 = V_121 << V_120 ;
T_1 V_4 ;
if ( V_12 > 8 )
return - V_51 ;
switch ( V_117 ) {
case V_122 :
V_4 = V_123 ;
break;
case V_124 :
V_4 = V_125 ;
break;
case V_126 :
V_4 = V_127 ;
break;
case V_128 :
V_4 = V_129 ;
break;
default:
return 0 ;
}
F_10 ( V_2 , V_3 , V_11 , V_4 << V_120 ) ;
return 0 ;
}
static int F_49 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
F_10 ( V_45 -> V_2 , V_78 + V_45 -> V_12 ,
V_130 , 0 ) ;
F_10 ( V_45 -> V_2 , V_131 ,
( 1 << V_45 -> V_12 ) , 0 ) ;
return 0 ;
}
static void F_50 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
F_10 ( V_45 -> V_2 , V_78 + V_45 -> V_12 ,
V_130 , V_130 ) ;
F_10 ( V_45 -> V_2 , V_131 ,
( 1 << V_45 -> V_12 ) , ( 1 << V_45 -> V_12 ) ) ;
}
static T_1 F_51 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
int V_55 = 0 ;
unsigned char V_4 ;
V_4 = F_1 ( V_45 -> V_2 , V_78 + V_45 -> V_12 ) ;
switch ( V_4 & V_104 ) {
case V_97 :
V_55 = 0 ;
break;
case V_99 :
V_55 = 1 ;
break;
case V_101 :
V_55 = 2 ;
break;
case V_103 :
V_55 = 3 ;
break;
}
return V_55 ;
}
static int F_52 ( struct V_27 * V_28 , T_1 V_55 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
enum V_95 V_46 = V_132 ;
switch ( V_55 ) {
case 0 :
V_46 = V_96 ;
break;
case 1 :
V_46 = V_98 ;
break;
case 2 :
V_46 = V_100 ;
break;
case 3 :
V_46 = V_102 ;
break;
}
return F_46 ( V_45 -> V_2 , V_45 -> V_12 , V_46 ) ;
}
static unsigned long F_53 ( struct V_27 * V_28 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned char V_3 ;
unsigned char V_133 ;
if ( V_45 -> V_12 <= 5 )
V_3 = F_12 ( V_45 -> V_12 ) + 2 ;
else
V_3 = V_134 ;
V_133 = F_1 ( V_45 -> V_2 , V_3 ) ;
if ( V_45 -> V_12 == 6 ) {
V_133 &= V_135 ;
} else {
V_133 &= V_136 ;
V_133 >>= V_137 ;
}
return V_34 >> V_133 ;
}
static long F_54 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long * V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned char V_133 ;
if ( V_45 -> V_12 >= 6 && V_35 > V_138 )
V_35 = V_138 ;
if ( V_35 > V_139 )
V_35 = V_139 ;
if ( V_35 < V_140 )
V_35 = V_140 ;
if ( F_43 ( V_28 ) & V_89 ) {
V_133 = V_141 ;
while ( V_35 < V_87 &&
V_133 < V_142 ) {
V_133 += 1 ;
V_35 *= 2 ;
}
* V_34 = V_35 ;
} else {
unsigned long V_143 , V_144 , V_145 ;
V_133 = V_141 ;
V_143 = * V_34 ;
V_145 = abs ( V_143 - V_35 ) ;
do {
V_143 >>= 1 ;
V_144 = abs ( V_143 - V_35 ) ;
if ( V_144 > V_145 || V_133 == V_142 )
break;
V_133 ++ ;
V_145 = V_144 ;
} while ( 1 );
}
V_35 = * V_34 >> V_133 ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_9 ,
V_43 , F_34 ( V_28 ) , ( 1 << V_133 ) ,
* V_34 , V_35 ) ;
return V_35 ;
}
static int F_55 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned long V_143 , V_144 , V_145 ;
unsigned char V_133 ;
V_133 = V_141 ;
V_143 = V_34 ;
V_145 = abs ( V_143 - V_35 ) ;
do {
V_143 >>= 1 ;
V_144 = abs ( V_143 - V_35 ) ;
if ( V_144 > V_145 || V_133 == V_142 )
break;
V_133 ++ ;
V_145 = V_144 ;
} while ( 1 );
switch ( V_45 -> V_12 ) {
case 6 :
F_10 ( V_45 -> V_2 , V_134 ,
V_135 , V_133 ) ;
break;
case 7 :
F_10 ( V_45 -> V_2 , V_134 ,
V_136 ,
V_133 << V_137 ) ;
break;
default:
F_10 ( V_45 -> V_2 ,
F_12 ( V_45 -> V_12 ) + 2 ,
V_136 ,
V_133 << V_137 ) ;
}
F_10 ( V_45 -> V_2 , V_78 + V_45 -> V_12 ,
V_130 , 0 ) ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_9 ,
V_43 , F_34 ( V_28 ) , ( 1 << V_133 ) ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_56 ( struct V_146 * V_7 ,
enum V_147 V_52 )
{
struct V_148 * V_149 , * V_150 = V_7 -> V_8 . V_151 ;
struct V_152 * V_153 ;
struct V_154 * V_155 ;
const T_3 * V_156 ;
int V_12 = 0 ;
T_2 V_4 ;
if ( V_150 == NULL )
return 0 ;
V_153 = F_57 ( & V_7 -> V_8 , sizeof( * V_153 ) , V_157 ) ;
if ( ! V_153 )
return - V_158 ;
F_58 (np, L_10 , prop, p, num) {
if ( V_12 >= 2 ) {
F_3 ( & V_7 -> V_8 ,
L_11 , V_12 ) ;
return - V_51 ;
}
V_156 = F_59 ( V_155 , V_156 , & V_4 ) ;
if ( ! V_156 ) {
F_3 ( & V_7 -> V_8 ,
L_12 , V_12 ) ;
return - V_51 ;
}
switch ( V_4 ) {
case 0 :
V_153 -> V_159 [ V_12 ] = V_54 ;
break;
case 1 :
if ( V_52 != V_53 ) {
F_3 ( & V_7 -> V_8 ,
L_13 ,
V_4 , V_12 ) ;
return - V_51 ;
}
V_153 -> V_159 [ V_12 ] = V_57 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_13 , V_4 , V_12 ) ;
return - V_51 ;
}
}
F_60 (np, child) {
if ( F_61 ( V_149 , L_14 , & V_12 ) ) {
F_3 ( & V_7 -> V_8 , L_15 ,
V_149 -> V_160 ) ;
goto V_161;
}
if ( V_12 >= 8 ||
( V_52 == V_162 && V_12 >= 3 ) ) {
F_3 ( & V_7 -> V_8 , L_16 , V_12 ) ;
goto V_161;
}
if ( ! F_61 ( V_149 , L_17 ,
& V_4 ) ) {
switch ( V_4 ) {
case 0 :
V_153 -> V_163 [ V_12 ] . V_164 =
V_80 ;
break;
case 1 :
V_153 -> V_163 [ V_12 ] . V_164 =
V_81 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_18 ,
V_4 , V_12 ) ;
goto V_161;
}
}
if ( ! F_61 ( V_149 , L_19 , & V_4 ) ) {
switch ( V_4 ) {
case 0 :
V_153 -> V_163 [ V_12 ] . V_165 =
V_96 ;
break;
case 1 :
V_153 -> V_163 [ V_12 ] . V_165 =
V_98 ;
break;
case 2 :
V_153 -> V_163 [ V_12 ] . V_165 =
V_100 ;
break;
case 3 :
if ( V_52 != V_53 ) {
F_3 ( & V_7 -> V_8 ,
L_20 ,
V_4 , V_12 ) ;
goto V_161;
}
V_153 -> V_163 [ V_12 ] . V_165 =
V_102 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_20 ,
V_4 , V_12 ) ;
goto V_161;
}
}
if ( ! F_61 ( V_149 , L_21 ,
& V_4 ) ) {
switch ( V_4 ) {
case V_107 :
case V_109 :
case V_111 :
case V_113 :
V_153 -> V_163 [ V_12 ] . V_106 = V_4 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_22 ,
V_4 , V_12 ) ;
goto V_161;
}
}
if ( ! F_61 ( V_149 , L_23 ,
& V_4 ) ) {
switch ( V_4 ) {
case 0 :
V_153 -> V_163 [ V_12 ] . V_166 =
V_122 ;
break;
case 1 :
V_153 -> V_163 [ V_12 ] . V_166 =
V_124 ;
break;
case 2 :
V_153 -> V_163 [ V_12 ] . V_166 =
V_126 ;
break;
case 3 :
V_153 -> V_163 [ V_12 ] . V_166 =
V_128 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_24 ,
V_4 , V_12 ) ;
goto V_161;
}
}
if ( ! F_61 ( V_149 , L_25 , & V_4 ) )
V_153 -> V_163 [ V_12 ] . V_35 = V_4 ;
V_153 -> V_163 [ V_12 ] . V_167 =
F_62 ( V_149 , L_26 ) ;
}
V_7 -> V_8 . V_168 = V_153 ;
return 0 ;
V_161:
F_63 ( V_149 ) ;
return - V_51 ;
}
static struct V_27 *
F_64 ( struct V_169 * V_170 , void * V_171 )
{
struct V_1 * V_2 = V_171 ;
unsigned int V_172 = V_170 -> args [ 0 ] ;
if ( V_172 >= V_2 -> V_173 ) {
F_65 ( L_27 , V_43 , V_172 ) ;
return F_66 ( - V_51 ) ;
}
return & V_2 -> V_163 [ V_172 ] . V_28 ;
}
static int F_56 ( struct V_146 * V_7 , enum V_147 V_52 )
{
return 0 ;
}
static struct V_27 *
F_64 ( struct V_169 * V_170 , void * V_171 )
{
return NULL ;
}
static int F_67 ( struct V_146 * V_7 ,
const struct V_174 * V_175 )
{
enum V_147 V_52 = (enum V_147 ) V_175 -> V_176 ;
struct V_152 * V_153 ;
struct V_1 * V_2 ;
struct V_177 V_178 ;
const char * V_179 [ 4 ] ;
T_1 V_180 , V_181 ;
int V_5 , V_182 ;
V_5 = F_56 ( V_7 , V_52 ) ;
if ( V_5 )
return V_5 ;
V_153 = V_7 -> V_8 . V_168 ;
if ( ! V_153 )
return - V_51 ;
V_2 = F_57 ( & V_7 -> V_8 , sizeof( * V_2 ) , V_157 ) ;
if ( ! V_2 )
return - V_158 ;
F_68 ( V_7 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_183 = F_69 ( & V_7 -> V_8 , L_28 ) ;
V_2 -> V_184 = F_69 ( & V_7 -> V_8 , L_29 ) ;
if ( F_70 ( V_2 -> V_183 ) == - V_185 ||
F_70 ( V_2 -> V_184 ) == - V_185 )
return - V_185 ;
if ( F_71 ( V_2 -> V_183 ) &&
( V_2 -> V_52 != V_53 || F_71 ( V_2 -> V_184 ) ) ) {
F_3 ( & V_7 -> V_8 , L_30 ) ;
return - V_51 ;
}
V_2 -> V_6 = F_72 ( V_7 , & V_186 ) ;
if ( F_71 ( V_2 -> V_6 ) ) {
F_3 ( & V_7 -> V_8 , L_31 ) ;
return F_70 ( V_2 -> V_6 ) ;
}
F_6 ( V_2 , V_187 , 0xf0 ) ;
if ( V_2 -> V_52 != V_53 )
F_10 ( V_2 , V_41 ,
V_48 | V_49 , 0 ) ;
for ( V_182 = 0 ; V_182 < 2 ; V_182 ++ ) {
V_5 = F_29 ( V_2 , V_182 , V_153 -> V_159 [ V_182 ] ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_32 ,
V_182 , V_153 -> V_159 [ V_182 ] ) ;
return V_5 ;
}
}
for ( V_182 = 0 ; V_182 < 8 ; V_182 ++ ) {
V_5 = F_38 ( V_2 , V_182 ,
V_153 -> V_163 [ V_182 ] . V_164 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_33 ,
V_182 , V_153 -> V_163 [ V_182 ] . V_164 ) ;
return V_5 ;
}
V_5 = F_46 ( V_2 , V_182 ,
V_153 -> V_163 [ V_182 ] . V_165 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_34 ,
V_182 , V_153 -> V_163 [ V_182 ] . V_165 ) ;
return V_5 ;
}
V_5 = F_47 ( V_2 , V_182 ,
V_153 -> V_163 [ V_182 ] . V_106 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_35 ,
V_182 , V_153 -> V_163 [ V_182 ] . V_106 ) ;
return V_5 ;
}
V_5 = F_48 ( V_2 , V_182 ,
V_153 -> V_163 [ V_182 ] . V_166 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_36 ,
V_182 , V_153 -> V_163 [ V_182 ] . V_166 ) ;
return V_5 ;
}
}
if ( ! F_71 ( V_2 -> V_183 ) )
F_73 ( V_2 -> V_183 ) ;
if ( ! F_71 ( V_2 -> V_184 ) )
F_73 ( V_2 -> V_184 ) ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_160 = V_188 [ 0 ] ;
V_178 . V_189 = & V_190 ;
V_178 . V_191 = 0 ;
if ( ! F_71 ( V_2 -> V_183 ) ) {
V_2 -> V_192 = F_74 ( V_2 -> V_183 ) ;
V_178 . V_179 = & V_2 -> V_192 ;
V_178 . V_180 = 1 ;
}
V_2 -> V_29 . V_178 = & V_178 ;
V_5 = F_75 ( & V_7 -> V_8 , & V_2 -> V_29 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 , L_37 , V_178 . V_160 ) ;
goto V_193;
}
if ( V_2 -> V_52 == V_53 ) {
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_160 = V_188 [ 1 ] ;
V_178 . V_189 = & V_194 ;
if ( ! F_71 ( V_2 -> V_184 ) ) {
V_2 -> V_195 = F_74 ( V_2 -> V_184 ) ;
V_178 . V_179 = & V_2 -> V_195 ;
V_178 . V_180 = 1 ;
}
V_2 -> V_32 . V_178 = & V_178 ;
V_5 = F_75 ( & V_7 -> V_8 , & V_2 -> V_32 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 , L_37 ,
V_178 . V_160 ) ;
goto V_193;
}
}
V_180 = ( V_2 -> V_52 == V_53 ) ? 2 : 1 ;
V_179 [ 0 ] = V_188 [ 0 ] ;
V_179 [ 1 ] = V_188 [ 1 ] ;
V_2 -> V_196 [ 0 ] . V_12 = 0 ;
V_2 -> V_196 [ 0 ] . V_2 = V_2 ;
V_2 -> V_196 [ 0 ] . V_28 . V_178 = & V_178 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_160 = V_197 [ 0 ] ;
V_178 . V_189 = & V_198 ;
V_178 . V_191 = 0 ;
V_178 . V_179 = V_179 ;
V_178 . V_180 = V_180 ;
V_5 = F_75 ( & V_7 -> V_8 , & V_2 -> V_196 [ 0 ] . V_28 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 , L_37 , V_178 . V_160 ) ;
goto V_193;
}
V_2 -> V_196 [ 1 ] . V_12 = 1 ;
V_2 -> V_196 [ 1 ] . V_2 = V_2 ;
V_2 -> V_196 [ 1 ] . V_28 . V_178 = & V_178 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
if ( V_2 -> V_52 == V_199 ) {
V_178 . V_160 = V_197 [ 2 ] ;
V_178 . V_189 = & V_200 ;
V_178 . V_191 = 0 ;
V_178 . V_179 = NULL ;
V_178 . V_180 = 0 ;
} else {
V_178 . V_160 = V_197 [ 1 ] ;
V_178 . V_189 = & V_198 ;
V_178 . V_191 = 0 ;
V_178 . V_179 = V_179 ;
V_178 . V_180 = V_180 ;
}
V_5 = F_75 ( & V_7 -> V_8 , & V_2 -> V_196 [ 1 ] . V_28 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 , L_37 , V_178 . V_160 ) ;
goto V_193;
}
V_181 = ( V_2 -> V_52 == V_162 ) ? 3 : 8 ;
V_179 [ 0 ] = V_197 [ 0 ] ;
if ( V_2 -> V_52 == V_199 )
V_179 [ 1 ] = V_197 [ 2 ] ;
else
V_179 [ 1 ] = V_197 [ 1 ] ;
V_2 -> V_201 = F_76 ( & V_7 -> V_8 , V_181 ,
sizeof( * V_2 -> V_201 ) , V_157 ) ;
V_2 -> V_163 = F_76 ( & V_7 -> V_8 , V_181 ,
sizeof( * V_2 -> V_163 ) , V_157 ) ;
V_2 -> V_173 = V_181 ;
if ( F_77 ( ! V_2 -> V_201 || ! V_2 -> V_163 ) ) {
V_5 = - V_158 ;
goto V_193;
}
for ( V_182 = 0 ; V_182 < V_181 ; V_182 ++ ) {
V_2 -> V_201 [ V_182 ] . V_12 = V_182 ;
V_2 -> V_201 [ V_182 ] . V_2 = V_2 ;
V_2 -> V_201 [ V_182 ] . V_28 . V_178 = & V_178 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_160 = V_202 [ V_182 ] ;
V_178 . V_189 = & V_203 ;
V_178 . V_191 = 0 ;
if ( V_153 -> V_163 [ V_182 ] . V_167 )
V_178 . V_191 |= V_89 ;
V_178 . V_179 = V_179 ;
V_178 . V_180 = 2 ;
V_5 = F_75 ( & V_7 -> V_8 ,
& V_2 -> V_201 [ V_182 ] . V_28 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 , L_37 ,
V_178 . V_160 ) ;
goto V_193;
}
}
V_180 = ( V_2 -> V_52 == V_53 ) ? 4 : 3 ;
V_179 [ 2 ] = V_188 [ 0 ] ;
V_179 [ 3 ] = V_188 [ 1 ] ;
for ( V_182 = 0 ; V_182 < V_181 ; V_182 ++ ) {
V_179 [ 0 ] = V_202 [ V_182 ] ;
V_179 [ 1 ] = ( V_182 < 4 ) ? V_202 [ 0 ] :
V_202 [ 4 ] ;
V_2 -> V_163 [ V_182 ] . V_12 = V_182 ;
V_2 -> V_163 [ V_182 ] . V_2 = V_2 ;
V_2 -> V_163 [ V_182 ] . V_28 . V_178 = & V_178 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_160 = V_204 [ V_182 ] ;
V_178 . V_189 = & V_205 ;
V_178 . V_191 = 0 ;
if ( V_153 -> V_163 [ V_182 ] . V_165 == V_96 )
V_178 . V_191 |= V_89 ;
V_178 . V_179 = V_179 ;
V_178 . V_180 = V_180 ;
V_5 = F_75 ( & V_7 -> V_8 ,
& V_2 -> V_163 [ V_182 ] . V_28 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 , L_37 ,
V_178 . V_160 ) ;
goto V_193;
}
if ( V_153 -> V_163 [ V_182 ] . V_35 != 0 ) {
int V_5 ;
V_5 = F_78 ( V_2 -> V_163 [ V_182 ] . V_28 . V_206 ,
V_153 -> V_163 [ V_182 ] . V_35 ) ;
if ( V_5 != 0 ) {
F_3 ( & V_7 -> V_8 , L_38 ,
V_5 ) ;
}
}
}
V_5 = F_79 ( V_7 -> V_8 . V_151 , F_64 ,
V_2 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 , L_39 ) ;
goto V_193;
}
return 0 ;
V_193:
if ( ! F_71 ( V_2 -> V_183 ) )
F_80 ( V_2 -> V_183 ) ;
if ( ! F_71 ( V_2 -> V_184 ) )
F_80 ( V_2 -> V_184 ) ;
return V_5 ;
}
