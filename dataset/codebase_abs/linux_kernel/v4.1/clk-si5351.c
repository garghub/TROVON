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
V_43 , F_34 ( V_45 -> V_28 . V_60 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_34 , ( unsigned long ) V_35 ) ;
return ( unsigned long ) V_35 ;
}
static long F_35 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long * V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned long V_61 , V_62 , V_63 , V_64 , V_65 ;
unsigned long long V_66 ;
if ( V_35 < V_67 )
V_35 = V_67 ;
if ( V_35 > V_68 )
V_35 = V_68 ;
V_63 = V_35 / * V_34 ;
if ( V_63 < V_69 )
V_35 = * V_34 * V_69 ;
if ( V_63 > V_70 )
V_35 = * V_34 * V_70 ;
V_62 = 1000 * 1000 ;
V_66 = V_35 % ( * V_34 ) ;
V_66 *= V_62 ;
F_33 ( V_66 , * V_34 ) ;
V_61 = ( unsigned long ) V_66 ;
V_64 = 0 ;
V_65 = 1 ;
if ( V_61 )
F_36 ( V_61 , V_62 ,
V_71 , V_72 , & V_64 , & V_65 ) ;
V_45 -> V_17 . V_21 = V_65 ;
V_45 -> V_17 . V_20 = ( 128 * V_64 ) % V_65 ;
V_45 -> V_17 . V_19 = 128 * V_63 ;
V_45 -> V_17 . V_19 += ( 128 * V_64 / V_65 ) ;
V_45 -> V_17 . V_19 -= 512 ;
V_66 = * V_34 ;
V_66 *= V_64 ;
F_33 ( V_66 , V_65 ) ;
V_35 = ( unsigned long ) V_66 ;
V_35 += * V_34 * V_63 ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_5 ,
V_43 , F_34 ( V_45 -> V_28 . V_60 ) , V_63 , V_64 , V_65 ,
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
F_10 ( V_45 -> V_2 , V_73 + V_45 -> V_12 ,
V_74 ,
( V_45 -> V_17 . V_20 == 0 ) ? V_74 : 0 ) ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_4 ,
V_43 , F_34 ( V_45 -> V_28 . V_60 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
int V_12 , enum V_75 V_46 )
{
if ( V_46 == V_76 )
return 0 ;
if ( V_12 > 8 )
return - V_51 ;
F_10 ( V_2 , V_77 + V_12 , V_78 ,
( V_46 == V_79 ) ? 0 :
V_78 ) ;
return 0 ;
}
static unsigned char F_39 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_4 ;
V_4 = F_1 ( V_45 -> V_2 , V_77 + V_45 -> V_12 ) ;
return ( V_4 & V_78 ) ? 1 : 0 ;
}
static int F_40 ( struct V_27 * V_28 , T_1 V_55 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
return F_38 ( V_45 -> V_2 , V_45 -> V_12 ,
( V_55 == 0 ) ? V_79 :
V_80 ) ;
}
static unsigned long F_41 ( struct V_27 * V_28 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_3 = F_12 ( V_45 -> V_12 ) ;
unsigned long long V_35 ;
unsigned long V_81 ;
if ( ! V_45 -> V_17 . V_22 )
F_13 ( V_45 -> V_2 , V_3 , & V_45 -> V_17 ) ;
if ( V_45 -> V_17 . V_21 == 0 )
return V_34 ;
V_35 = V_34 ;
if ( V_45 -> V_12 > 5 ) {
V_81 = V_45 -> V_17 . V_19 ;
} else if ( ( F_1 ( V_45 -> V_2 , V_3 + 2 ) &
V_82 ) == V_82 ) {
V_81 = 4 ;
} else {
V_35 *= 128 * V_45 -> V_17 . V_21 ;
V_81 = V_45 -> V_17 . V_19 * V_45 -> V_17 . V_21 ;
V_81 += V_45 -> V_17 . V_20 ;
V_81 += 512 * V_45 -> V_17 . V_21 ;
}
if ( V_81 == 0 )
return 0 ;
F_33 ( V_35 , V_81 ) ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_6 ,
V_43 , F_34 ( V_45 -> V_28 . V_60 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_81 , V_34 , ( unsigned long ) V_35 ) ;
return ( unsigned long ) V_35 ;
}
static long F_42 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long * V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned long long V_66 ;
unsigned long V_63 , V_64 , V_65 ;
int V_83 ;
if ( V_45 -> V_12 >= 6 && V_35 > V_84 )
V_35 = V_84 ;
if ( V_35 > V_85 )
V_35 = V_85 ;
if ( V_35 < V_86 )
V_35 = V_86 ;
V_83 = 0 ;
if ( V_35 > V_87 )
V_83 = 1 ;
if ( F_43 ( V_45 -> V_28 . V_60 ) & V_88 ) {
if ( V_83 == 0 ) {
V_66 = V_68 ;
F_33 ( V_66 , V_35 ) ;
V_63 = ( unsigned long ) V_66 ;
} else
V_63 = 4 ;
V_64 = 0 ;
V_65 = 1 ;
* V_34 = V_63 * V_35 ;
} else {
unsigned long V_61 , V_62 ;
if ( V_83 ) {
V_35 = V_87 ;
V_83 = 0 ;
}
V_63 = * V_34 / V_35 ;
if ( V_63 < V_89 )
V_63 = V_89 ;
if ( V_45 -> V_12 >= 6 && V_63 > V_90 )
V_63 = V_90 ;
else if ( V_63 > V_91 )
V_63 = V_91 ;
V_62 = 1000 * 1000 ;
V_66 = ( * V_34 ) % V_35 ;
V_66 *= V_62 ;
F_33 ( V_66 , V_35 ) ;
V_61 = ( unsigned long ) V_66 ;
V_64 = 0 ;
V_65 = 1 ;
if ( V_61 )
F_36 ( V_61 , V_62 ,
V_92 , V_93 ,
& V_64 , & V_65 ) ;
}
V_66 = * V_34 ;
V_66 *= V_65 ;
F_33 ( V_66 , V_63 * V_65 + V_64 ) ;
V_35 = ( unsigned long ) V_66 ;
if ( V_83 ) {
V_45 -> V_17 . V_21 = 1 ;
V_45 -> V_17 . V_20 = 0 ;
V_45 -> V_17 . V_19 = 0 ;
} else {
V_45 -> V_17 . V_21 = V_65 ;
V_45 -> V_17 . V_20 = ( 128 * V_64 ) % V_65 ;
V_45 -> V_17 . V_19 = 128 * V_63 ;
V_45 -> V_17 . V_19 += ( 128 * V_64 / V_65 ) ;
V_45 -> V_17 . V_19 -= 512 ;
}
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_7 ,
V_43 , F_34 ( V_45 -> V_28 . V_60 ) , V_63 , V_64 , V_65 , V_83 ,
* V_34 , V_35 ) ;
return V_35 ;
}
static int F_44 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_3 = F_12 ( V_45 -> V_12 ) ;
int V_83 = 0 ;
F_14 ( V_45 -> V_2 , V_3 , & V_45 -> V_17 ) ;
if ( V_35 > V_87 )
V_83 = 1 ;
if ( V_45 -> V_12 < 6 ) {
F_10 ( V_45 -> V_2 , V_3 + 2 ,
V_82 ,
( V_83 ) ? V_82 : 0 ) ;
F_10 ( V_45 -> V_2 , V_77 + V_45 -> V_12 ,
V_74 ,
( V_45 -> V_17 . V_20 == 0 ) ? V_74 : 0 ) ;
}
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_8 ,
V_43 , F_34 ( V_45 -> V_28 . V_60 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_83 , V_34 , V_35 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
int V_12 , enum V_94 V_46 )
{
T_1 V_4 ;
if ( V_12 > 8 )
return - V_51 ;
switch ( V_46 ) {
case V_95 :
V_4 = V_96 ;
break;
case V_97 :
if ( V_12 == 0 || V_12 == 4 )
V_4 = V_96 ;
else
V_4 = V_98 ;
break;
case V_99 :
V_4 = V_100 ;
break;
case V_101 :
if ( V_2 -> V_52 != V_53 )
return - V_51 ;
V_4 = V_102 ;
break;
default:
return 0 ;
}
F_10 ( V_2 , V_77 + V_12 ,
V_103 , V_4 ) ;
return 0 ;
}
static int F_46 (
struct V_1 * V_2 , int V_12 ,
enum V_104 V_105 )
{
T_1 V_11 ;
if ( V_12 > 8 )
return - V_51 ;
switch ( V_105 ) {
case V_106 :
V_11 = V_107 ;
break;
case V_108 :
V_11 = V_109 ;
break;
case V_110 :
V_11 = V_111 ;
break;
case V_112 :
V_11 = V_113 ;
break;
default:
return 0 ;
}
F_10 ( V_2 , V_77 + V_12 ,
V_114 , V_11 ) ;
return 0 ;
}
static int F_47 (
struct V_1 * V_2 , int V_12 ,
enum V_115 V_116 )
{
T_1 V_3 = ( V_12 < 4 ) ? V_117 :
V_118 ;
T_1 V_119 = ( V_12 < 4 ) ? ( 2 * V_12 ) : ( 2 * ( V_12 - 4 ) ) ;
T_1 V_11 = V_120 << V_119 ;
T_1 V_4 ;
if ( V_12 > 8 )
return - V_51 ;
switch ( V_116 ) {
case V_121 :
V_4 = V_122 ;
break;
case V_123 :
V_4 = V_124 ;
break;
case V_125 :
V_4 = V_126 ;
break;
case V_127 :
V_4 = V_128 ;
break;
default:
return 0 ;
}
F_10 ( V_2 , V_3 , V_11 , V_4 << V_119 ) ;
return 0 ;
}
static int F_48 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
F_10 ( V_45 -> V_2 , V_77 + V_45 -> V_12 ,
V_129 , 0 ) ;
F_10 ( V_45 -> V_2 , V_130 ,
( 1 << V_45 -> V_12 ) , 0 ) ;
return 0 ;
}
static void F_49 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
F_10 ( V_45 -> V_2 , V_77 + V_45 -> V_12 ,
V_129 , V_129 ) ;
F_10 ( V_45 -> V_2 , V_130 ,
( 1 << V_45 -> V_12 ) , ( 1 << V_45 -> V_12 ) ) ;
}
static T_1 F_50 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
int V_55 = 0 ;
unsigned char V_4 ;
V_4 = F_1 ( V_45 -> V_2 , V_77 + V_45 -> V_12 ) ;
switch ( V_4 & V_103 ) {
case V_96 :
V_55 = 0 ;
break;
case V_98 :
V_55 = 1 ;
break;
case V_100 :
V_55 = 2 ;
break;
case V_102 :
V_55 = 3 ;
break;
}
return V_55 ;
}
static int F_51 ( struct V_27 * V_28 , T_1 V_55 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
enum V_94 V_46 = V_131 ;
switch ( V_55 ) {
case 0 :
V_46 = V_95 ;
break;
case 1 :
V_46 = V_97 ;
break;
case 2 :
V_46 = V_99 ;
break;
case 3 :
V_46 = V_101 ;
break;
}
return F_45 ( V_45 -> V_2 , V_45 -> V_12 , V_46 ) ;
}
static unsigned long F_52 ( struct V_27 * V_28 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned char V_3 ;
unsigned char V_132 ;
if ( V_45 -> V_12 <= 5 )
V_3 = F_12 ( V_45 -> V_12 ) + 2 ;
else
V_3 = V_133 ;
V_132 = F_1 ( V_45 -> V_2 , V_3 ) ;
if ( V_45 -> V_12 == 6 ) {
V_132 &= V_134 ;
} else {
V_132 &= V_135 ;
V_132 >>= V_136 ;
}
return V_34 >> V_132 ;
}
static long F_53 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long * V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned char V_132 ;
if ( V_45 -> V_12 >= 6 && V_35 > V_137 )
V_35 = V_137 ;
if ( V_35 > V_138 )
V_35 = V_138 ;
if ( V_35 < V_139 )
V_35 = V_139 ;
if ( F_43 ( V_45 -> V_28 . V_60 ) & V_88 ) {
V_132 = V_140 ;
while ( V_35 < V_86 &&
V_132 < V_141 ) {
V_132 += 1 ;
V_35 *= 2 ;
}
* V_34 = V_35 ;
} else {
unsigned long V_142 , V_143 , V_144 ;
V_132 = V_140 ;
V_142 = * V_34 ;
V_144 = abs ( V_142 - V_35 ) ;
do {
V_142 >>= 1 ;
V_143 = abs ( V_142 - V_35 ) ;
if ( V_143 > V_144 || V_132 == V_141 )
break;
V_132 ++ ;
V_144 = V_143 ;
} while ( 1 );
}
V_35 = * V_34 >> V_132 ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_9 ,
V_43 , F_34 ( V_45 -> V_28 . V_60 ) , ( 1 << V_132 ) ,
* V_34 , V_35 ) ;
return V_35 ;
}
static int F_54 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned long V_142 , V_143 , V_144 ;
unsigned char V_132 ;
V_132 = V_140 ;
V_142 = V_34 ;
V_144 = abs ( V_142 - V_35 ) ;
do {
V_142 >>= 1 ;
V_143 = abs ( V_142 - V_35 ) ;
if ( V_143 > V_144 || V_132 == V_141 )
break;
V_132 ++ ;
V_144 = V_143 ;
} while ( 1 );
switch ( V_45 -> V_12 ) {
case 6 :
F_10 ( V_45 -> V_2 , V_133 ,
V_134 , V_132 ) ;
break;
case 7 :
F_10 ( V_45 -> V_2 , V_133 ,
V_135 ,
V_132 << V_136 ) ;
break;
default:
F_10 ( V_45 -> V_2 ,
F_12 ( V_45 -> V_12 ) + 2 ,
V_135 ,
V_132 << V_136 ) ;
}
F_10 ( V_45 -> V_2 , V_77 + V_45 -> V_12 ,
V_129 , 0 ) ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_9 ,
V_43 , F_34 ( V_45 -> V_28 . V_60 ) , ( 1 << V_132 ) ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_55 ( struct V_145 * V_7 ,
enum V_146 V_52 )
{
struct V_147 * V_148 , * V_149 = V_7 -> V_8 . V_150 ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
const T_3 * V_155 ;
int V_12 = 0 ;
T_2 V_4 ;
if ( V_149 == NULL )
return 0 ;
V_152 = F_56 ( & V_7 -> V_8 , sizeof( * V_152 ) , V_156 ) ;
if ( ! V_152 )
return - V_157 ;
F_57 (np, L_10 , prop, p, num) {
if ( V_12 >= 2 ) {
F_3 ( & V_7 -> V_8 ,
L_11 , V_12 ) ;
return - V_51 ;
}
V_155 = F_58 ( V_154 , V_155 , & V_4 ) ;
if ( ! V_155 ) {
F_3 ( & V_7 -> V_8 ,
L_12 , V_12 ) ;
return - V_51 ;
}
switch ( V_4 ) {
case 0 :
V_152 -> V_158 [ V_12 ] = V_54 ;
break;
case 1 :
if ( V_52 != V_53 ) {
F_3 ( & V_7 -> V_8 ,
L_13 ,
V_4 , V_12 ) ;
return - V_51 ;
}
V_152 -> V_158 [ V_12 ] = V_57 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_13 , V_4 , V_12 ) ;
return - V_51 ;
}
}
F_59 (np, child) {
if ( F_60 ( V_148 , L_14 , & V_12 ) ) {
F_3 ( & V_7 -> V_8 , L_15 ,
V_148 -> V_159 ) ;
return - V_51 ;
}
if ( V_12 >= 8 ||
( V_52 == V_160 && V_12 >= 3 ) ) {
F_3 ( & V_7 -> V_8 , L_16 , V_12 ) ;
return - V_51 ;
}
if ( ! F_60 ( V_148 , L_17 ,
& V_4 ) ) {
switch ( V_4 ) {
case 0 :
V_152 -> V_161 [ V_12 ] . V_162 =
V_79 ;
break;
case 1 :
V_152 -> V_161 [ V_12 ] . V_162 =
V_80 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_18 ,
V_4 , V_12 ) ;
return - V_51 ;
}
}
if ( ! F_60 ( V_148 , L_19 , & V_4 ) ) {
switch ( V_4 ) {
case 0 :
V_152 -> V_161 [ V_12 ] . V_163 =
V_95 ;
break;
case 1 :
V_152 -> V_161 [ V_12 ] . V_163 =
V_97 ;
break;
case 2 :
V_152 -> V_161 [ V_12 ] . V_163 =
V_99 ;
break;
case 3 :
if ( V_52 != V_53 ) {
F_3 ( & V_7 -> V_8 ,
L_20 ,
V_4 , V_12 ) ;
return - V_51 ;
}
V_152 -> V_161 [ V_12 ] . V_163 =
V_101 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_20 ,
V_4 , V_12 ) ;
return - V_51 ;
}
}
if ( ! F_60 ( V_148 , L_21 ,
& V_4 ) ) {
switch ( V_4 ) {
case V_106 :
case V_108 :
case V_110 :
case V_112 :
V_152 -> V_161 [ V_12 ] . V_105 = V_4 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_22 ,
V_4 , V_12 ) ;
return - V_51 ;
}
}
if ( ! F_60 ( V_148 , L_23 ,
& V_4 ) ) {
switch ( V_4 ) {
case 0 :
V_152 -> V_161 [ V_12 ] . V_164 =
V_121 ;
break;
case 1 :
V_152 -> V_161 [ V_12 ] . V_164 =
V_123 ;
break;
case 2 :
V_152 -> V_161 [ V_12 ] . V_164 =
V_125 ;
break;
case 3 :
V_152 -> V_161 [ V_12 ] . V_164 =
V_127 ;
break;
default:
F_3 ( & V_7 -> V_8 ,
L_24 ,
V_4 , V_12 ) ;
return - V_51 ;
}
}
if ( ! F_60 ( V_148 , L_25 , & V_4 ) )
V_152 -> V_161 [ V_12 ] . V_35 = V_4 ;
V_152 -> V_161 [ V_12 ] . V_165 =
F_61 ( V_148 , L_26 ) ;
}
V_7 -> V_8 . V_166 = V_152 ;
return 0 ;
}
static int F_55 ( struct V_145 * V_7 , enum V_146 V_52 )
{
return 0 ;
}
static int F_62 ( struct V_145 * V_7 ,
const struct V_167 * V_168 )
{
enum V_146 V_52 = (enum V_146 ) V_168 -> V_169 ;
struct V_151 * V_152 ;
struct V_1 * V_2 ;
struct V_170 V_171 ;
struct V_60 * V_60 ;
const char * V_172 [ 4 ] ;
T_1 V_173 , V_174 ;
int V_5 , V_175 ;
V_5 = F_55 ( V_7 , V_52 ) ;
if ( V_5 )
return V_5 ;
V_152 = V_7 -> V_8 . V_166 ;
if ( ! V_152 )
return - V_51 ;
V_2 = F_56 ( & V_7 -> V_8 , sizeof( * V_2 ) , V_156 ) ;
if ( V_2 == NULL ) {
F_3 ( & V_7 -> V_8 , L_27 ) ;
return - V_157 ;
}
F_63 ( V_7 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_176 = F_64 ( & V_7 -> V_8 , L_28 ) ;
V_2 -> V_177 = F_64 ( & V_7 -> V_8 , L_29 ) ;
if ( F_65 ( V_2 -> V_176 ) == - V_178 ||
F_65 ( V_2 -> V_177 ) == - V_178 )
return - V_178 ;
if ( F_66 ( V_2 -> V_176 ) &&
( V_2 -> V_52 != V_53 || F_66 ( V_2 -> V_177 ) ) ) {
F_3 ( & V_7 -> V_8 , L_30 ) ;
return - V_51 ;
}
V_2 -> V_6 = F_67 ( V_7 , & V_179 ) ;
if ( F_66 ( V_2 -> V_6 ) ) {
F_3 ( & V_7 -> V_8 , L_31 ) ;
return F_65 ( V_2 -> V_6 ) ;
}
F_6 ( V_2 , V_180 , 0xf0 ) ;
if ( V_2 -> V_52 != V_53 )
F_10 ( V_2 , V_41 ,
V_48 | V_49 , 0 ) ;
for ( V_175 = 0 ; V_175 < 2 ; V_175 ++ ) {
V_5 = F_29 ( V_2 , V_175 , V_152 -> V_158 [ V_175 ] ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_32 ,
V_175 , V_152 -> V_158 [ V_175 ] ) ;
return V_5 ;
}
}
for ( V_175 = 0 ; V_175 < 8 ; V_175 ++ ) {
V_5 = F_38 ( V_2 , V_175 ,
V_152 -> V_161 [ V_175 ] . V_162 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_33 ,
V_175 , V_152 -> V_161 [ V_175 ] . V_162 ) ;
return V_5 ;
}
V_5 = F_45 ( V_2 , V_175 ,
V_152 -> V_161 [ V_175 ] . V_163 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_34 ,
V_175 , V_152 -> V_161 [ V_175 ] . V_163 ) ;
return V_5 ;
}
V_5 = F_46 ( V_2 , V_175 ,
V_152 -> V_161 [ V_175 ] . V_105 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_35 ,
V_175 , V_152 -> V_161 [ V_175 ] . V_105 ) ;
return V_5 ;
}
V_5 = F_47 ( V_2 , V_175 ,
V_152 -> V_161 [ V_175 ] . V_164 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_36 ,
V_175 , V_152 -> V_161 [ V_175 ] . V_164 ) ;
return V_5 ;
}
}
if ( ! F_66 ( V_2 -> V_176 ) )
F_68 ( V_2 -> V_176 ) ;
if ( ! F_66 ( V_2 -> V_177 ) )
F_68 ( V_2 -> V_177 ) ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_159 = V_181 [ 0 ] ;
V_171 . V_182 = & V_183 ;
V_171 . V_184 = 0 ;
if ( ! F_66 ( V_2 -> V_176 ) ) {
V_2 -> V_185 = F_34 ( V_2 -> V_176 ) ;
V_171 . V_172 = & V_2 -> V_185 ;
V_171 . V_173 = 1 ;
}
V_2 -> V_29 . V_171 = & V_171 ;
V_60 = F_69 ( & V_7 -> V_8 , & V_2 -> V_29 ) ;
if ( F_66 ( V_60 ) ) {
F_3 ( & V_7 -> V_8 , L_37 , V_171 . V_159 ) ;
V_5 = F_65 ( V_60 ) ;
goto V_186;
}
if ( V_2 -> V_52 == V_53 ) {
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_159 = V_181 [ 1 ] ;
V_171 . V_182 = & V_187 ;
if ( ! F_66 ( V_2 -> V_177 ) ) {
V_2 -> V_188 = F_34 ( V_2 -> V_177 ) ;
V_171 . V_172 = & V_2 -> V_188 ;
V_171 . V_173 = 1 ;
}
V_2 -> V_32 . V_171 = & V_171 ;
V_60 = F_69 ( & V_7 -> V_8 , & V_2 -> V_32 ) ;
if ( F_66 ( V_60 ) ) {
F_3 ( & V_7 -> V_8 , L_37 ,
V_171 . V_159 ) ;
V_5 = F_65 ( V_60 ) ;
goto V_186;
}
}
V_173 = ( V_2 -> V_52 == V_53 ) ? 2 : 1 ;
V_172 [ 0 ] = V_181 [ 0 ] ;
V_172 [ 1 ] = V_181 [ 1 ] ;
V_2 -> V_189 [ 0 ] . V_12 = 0 ;
V_2 -> V_189 [ 0 ] . V_2 = V_2 ;
V_2 -> V_189 [ 0 ] . V_28 . V_171 = & V_171 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_159 = V_190 [ 0 ] ;
V_171 . V_182 = & V_191 ;
V_171 . V_184 = 0 ;
V_171 . V_172 = V_172 ;
V_171 . V_173 = V_173 ;
V_60 = F_69 ( & V_7 -> V_8 , & V_2 -> V_189 [ 0 ] . V_28 ) ;
if ( F_66 ( V_60 ) ) {
F_3 ( & V_7 -> V_8 , L_37 , V_171 . V_159 ) ;
V_5 = F_65 ( V_60 ) ;
goto V_186;
}
V_2 -> V_189 [ 1 ] . V_12 = 1 ;
V_2 -> V_189 [ 1 ] . V_2 = V_2 ;
V_2 -> V_189 [ 1 ] . V_28 . V_171 = & V_171 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
if ( V_2 -> V_52 == V_192 ) {
V_171 . V_159 = V_190 [ 2 ] ;
V_171 . V_182 = & V_193 ;
V_171 . V_184 = V_194 ;
V_171 . V_172 = NULL ;
V_171 . V_173 = 0 ;
} else {
V_171 . V_159 = V_190 [ 1 ] ;
V_171 . V_182 = & V_191 ;
V_171 . V_184 = 0 ;
V_171 . V_172 = V_172 ;
V_171 . V_173 = V_173 ;
}
V_60 = F_69 ( & V_7 -> V_8 , & V_2 -> V_189 [ 1 ] . V_28 ) ;
if ( F_66 ( V_60 ) ) {
F_3 ( & V_7 -> V_8 , L_37 , V_171 . V_159 ) ;
V_5 = F_65 ( V_60 ) ;
goto V_186;
}
V_174 = ( V_2 -> V_52 == V_160 ) ? 3 : 8 ;
V_172 [ 0 ] = V_190 [ 0 ] ;
if ( V_2 -> V_52 == V_192 )
V_172 [ 1 ] = V_190 [ 2 ] ;
else
V_172 [ 1 ] = V_190 [ 1 ] ;
V_2 -> V_195 = F_56 ( & V_7 -> V_8 , V_174 *
sizeof( * V_2 -> V_195 ) , V_156 ) ;
V_2 -> V_161 = F_56 ( & V_7 -> V_8 , V_174 *
sizeof( * V_2 -> V_161 ) , V_156 ) ;
V_2 -> V_196 . V_197 = V_174 ;
V_2 -> V_196 . V_198 = F_56 ( & V_7 -> V_8 ,
V_174 * sizeof( * V_2 -> V_196 . V_198 ) , V_156 ) ;
if ( F_70 ( ! V_2 -> V_195 || ! V_2 -> V_161 ||
! V_2 -> V_196 . V_198 ) ) {
V_5 = - V_157 ;
goto V_186;
}
for ( V_175 = 0 ; V_175 < V_174 ; V_175 ++ ) {
V_2 -> V_195 [ V_175 ] . V_12 = V_175 ;
V_2 -> V_195 [ V_175 ] . V_2 = V_2 ;
V_2 -> V_195 [ V_175 ] . V_28 . V_171 = & V_171 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_159 = V_199 [ V_175 ] ;
V_171 . V_182 = & V_200 ;
V_171 . V_184 = 0 ;
if ( V_152 -> V_161 [ V_175 ] . V_165 )
V_171 . V_184 |= V_88 ;
V_171 . V_172 = V_172 ;
V_171 . V_173 = 2 ;
V_60 = F_69 ( & V_7 -> V_8 , & V_2 -> V_195 [ V_175 ] . V_28 ) ;
if ( F_66 ( V_60 ) ) {
F_3 ( & V_7 -> V_8 , L_37 ,
V_171 . V_159 ) ;
V_5 = F_65 ( V_60 ) ;
goto V_186;
}
}
V_173 = ( V_2 -> V_52 == V_53 ) ? 4 : 3 ;
V_172 [ 2 ] = V_181 [ 0 ] ;
V_172 [ 3 ] = V_181 [ 1 ] ;
for ( V_175 = 0 ; V_175 < V_174 ; V_175 ++ ) {
V_172 [ 0 ] = V_199 [ V_175 ] ;
V_172 [ 1 ] = ( V_175 < 4 ) ? V_199 [ 0 ] :
V_199 [ 4 ] ;
V_2 -> V_161 [ V_175 ] . V_12 = V_175 ;
V_2 -> V_161 [ V_175 ] . V_2 = V_2 ;
V_2 -> V_161 [ V_175 ] . V_28 . V_171 = & V_171 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_159 = V_201 [ V_175 ] ;
V_171 . V_182 = & V_202 ;
V_171 . V_184 = 0 ;
if ( V_152 -> V_161 [ V_175 ] . V_163 == V_95 )
V_171 . V_184 |= V_88 ;
V_171 . V_172 = V_172 ;
V_171 . V_173 = V_173 ;
V_60 = F_69 ( & V_7 -> V_8 , & V_2 -> V_161 [ V_175 ] . V_28 ) ;
if ( F_66 ( V_60 ) ) {
F_3 ( & V_7 -> V_8 , L_37 ,
V_171 . V_159 ) ;
V_5 = F_65 ( V_60 ) ;
goto V_186;
}
V_2 -> V_196 . V_198 [ V_175 ] = V_60 ;
if ( V_152 -> V_161 [ V_175 ] . V_35 != 0 ) {
int V_5 ;
V_5 = F_71 ( V_60 , V_152 -> V_161 [ V_175 ] . V_35 ) ;
if ( V_5 != 0 ) {
F_3 ( & V_7 -> V_8 , L_38 ,
V_5 ) ;
}
}
}
V_5 = F_72 ( V_7 -> V_8 . V_150 , V_203 ,
& V_2 -> V_196 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 , L_39 ) ;
goto V_186;
}
return 0 ;
V_186:
if ( ! F_66 ( V_2 -> V_176 ) )
F_73 ( V_2 -> V_176 ) ;
if ( ! F_66 ( V_2 -> V_177 ) )
F_73 ( V_2 -> V_177 ) ;
return V_5 ;
}
