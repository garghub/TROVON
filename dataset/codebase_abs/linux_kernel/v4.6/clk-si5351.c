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
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_4 ,
V_43 , F_34 ( V_28 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
int V_12 , enum V_74 V_46 )
{
if ( V_46 == V_75 )
return 0 ;
if ( V_12 > 8 )
return - V_51 ;
F_10 ( V_2 , V_76 + V_12 , V_77 ,
( V_46 == V_78 ) ? 0 :
V_77 ) ;
return 0 ;
}
static unsigned char F_39 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_4 ;
V_4 = F_1 ( V_45 -> V_2 , V_76 + V_45 -> V_12 ) ;
return ( V_4 & V_77 ) ? 1 : 0 ;
}
static int F_40 ( struct V_27 * V_28 , T_1 V_55 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
return F_38 ( V_45 -> V_2 , V_45 -> V_12 ,
( V_55 == 0 ) ? V_78 :
V_79 ) ;
}
static unsigned long F_41 ( struct V_27 * V_28 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_3 = F_12 ( V_45 -> V_12 ) ;
unsigned long long V_35 ;
unsigned long V_80 ;
if ( ! V_45 -> V_17 . V_22 )
F_13 ( V_45 -> V_2 , V_3 , & V_45 -> V_17 ) ;
V_35 = V_34 ;
if ( V_45 -> V_12 > 5 ) {
V_80 = V_45 -> V_17 . V_19 ;
} else if ( V_45 -> V_17 . V_21 == 0 ) {
return V_34 ;
} else if ( ( F_1 ( V_45 -> V_2 , V_3 + 2 ) &
V_81 ) == V_81 ) {
V_80 = 4 ;
} else {
V_35 *= 128 * V_45 -> V_17 . V_21 ;
V_80 = V_45 -> V_17 . V_19 * V_45 -> V_17 . V_21 ;
V_80 += V_45 -> V_17 . V_20 ;
V_80 += 512 * V_45 -> V_17 . V_21 ;
}
if ( V_80 == 0 )
return 0 ;
F_33 ( V_35 , V_80 ) ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_6 ,
V_43 , F_34 ( V_28 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_80 , V_34 , ( unsigned long ) V_35 ) ;
return ( unsigned long ) V_35 ;
}
static long F_42 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long * V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned long long V_65 ;
unsigned long V_62 , V_63 , V_64 ;
int V_82 ;
if ( V_45 -> V_12 >= 6 && V_35 > V_83 )
V_35 = V_83 ;
if ( V_35 > V_84 )
V_35 = V_84 ;
if ( V_35 < V_85 )
V_35 = V_85 ;
V_82 = 0 ;
if ( V_35 > V_86 )
V_82 = 1 ;
if ( F_43 ( V_28 ) & V_87 ) {
if ( V_82 == 0 ) {
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
if ( V_62 < V_88 )
V_62 = V_88 ;
if ( V_62 > V_89 )
V_62 = V_89 ;
V_63 = 0 ;
V_64 = 1 ;
} else {
unsigned long V_60 , V_61 ;
if ( V_82 ) {
V_35 = V_86 ;
V_82 = 0 ;
}
V_62 = * V_34 / V_35 ;
if ( V_62 < V_88 )
V_62 = V_88 ;
if ( V_62 > V_90 )
V_62 = V_90 ;
V_61 = 1000 * 1000 ;
V_65 = ( * V_34 ) % V_35 ;
V_65 *= V_61 ;
F_33 ( V_65 , V_35 ) ;
V_60 = ( unsigned long ) V_65 ;
V_63 = 0 ;
V_64 = 1 ;
if ( V_60 )
F_36 ( V_60 , V_61 ,
V_91 , V_92 ,
& V_63 , & V_64 ) ;
}
V_65 = * V_34 ;
V_65 *= V_64 ;
F_33 ( V_65 , V_62 * V_64 + V_63 ) ;
V_35 = ( unsigned long ) V_65 ;
if ( V_82 ) {
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
V_43 , F_34 ( V_28 ) , V_62 , V_63 , V_64 , V_82 ,
* V_34 , V_35 ) ;
return V_35 ;
}
static int F_45 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
T_1 V_3 = F_12 ( V_45 -> V_12 ) ;
int V_82 = 0 ;
F_14 ( V_45 -> V_2 , V_3 , & V_45 -> V_17 ) ;
if ( V_35 > V_86 )
V_82 = 1 ;
if ( V_45 -> V_12 < 6 ) {
F_10 ( V_45 -> V_2 , V_3 + 2 ,
V_81 ,
( V_82 ) ? V_81 : 0 ) ;
F_10 ( V_45 -> V_2 , V_76 + V_45 -> V_12 ,
V_73 ,
( V_45 -> V_17 . V_20 == 0 ) ? V_73 : 0 ) ;
}
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_8 ,
V_43 , F_34 ( V_28 ) ,
V_45 -> V_17 . V_19 , V_45 -> V_17 . V_20 , V_45 -> V_17 . V_21 ,
V_82 , V_34 , V_35 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
int V_12 , enum V_93 V_46 )
{
T_1 V_4 ;
if ( V_12 > 8 )
return - V_51 ;
switch ( V_46 ) {
case V_94 :
V_4 = V_95 ;
break;
case V_96 :
if ( V_12 == 0 || V_12 == 4 )
V_4 = V_95 ;
else
V_4 = V_97 ;
break;
case V_98 :
V_4 = V_99 ;
break;
case V_100 :
if ( V_2 -> V_52 != V_53 )
return - V_51 ;
V_4 = V_101 ;
break;
default:
return 0 ;
}
F_10 ( V_2 , V_76 + V_12 ,
V_102 , V_4 ) ;
return 0 ;
}
static int F_47 (
struct V_1 * V_2 , int V_12 ,
enum V_103 V_104 )
{
T_1 V_11 ;
if ( V_12 > 8 )
return - V_51 ;
switch ( V_104 ) {
case V_105 :
V_11 = V_106 ;
break;
case V_107 :
V_11 = V_108 ;
break;
case V_109 :
V_11 = V_110 ;
break;
case V_111 :
V_11 = V_112 ;
break;
default:
return 0 ;
}
F_10 ( V_2 , V_76 + V_12 ,
V_113 , V_11 ) ;
return 0 ;
}
static int F_48 (
struct V_1 * V_2 , int V_12 ,
enum V_114 V_115 )
{
T_1 V_3 = ( V_12 < 4 ) ? V_116 :
V_117 ;
T_1 V_118 = ( V_12 < 4 ) ? ( 2 * V_12 ) : ( 2 * ( V_12 - 4 ) ) ;
T_1 V_11 = V_119 << V_118 ;
T_1 V_4 ;
if ( V_12 > 8 )
return - V_51 ;
switch ( V_115 ) {
case V_120 :
V_4 = V_121 ;
break;
case V_122 :
V_4 = V_123 ;
break;
case V_124 :
V_4 = V_125 ;
break;
case V_126 :
V_4 = V_127 ;
break;
default:
return 0 ;
}
F_10 ( V_2 , V_3 , V_11 , V_4 << V_118 ) ;
return 0 ;
}
static int F_49 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
F_10 ( V_45 -> V_2 , V_76 + V_45 -> V_12 ,
V_128 , 0 ) ;
F_10 ( V_45 -> V_2 , V_129 ,
( 1 << V_45 -> V_12 ) , 0 ) ;
return 0 ;
}
static void F_50 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
F_10 ( V_45 -> V_2 , V_76 + V_45 -> V_12 ,
V_128 , V_128 ) ;
F_10 ( V_45 -> V_2 , V_129 ,
( 1 << V_45 -> V_12 ) , ( 1 << V_45 -> V_12 ) ) ;
}
static T_1 F_51 ( struct V_27 * V_28 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
int V_55 = 0 ;
unsigned char V_4 ;
V_4 = F_1 ( V_45 -> V_2 , V_76 + V_45 -> V_12 ) ;
switch ( V_4 & V_102 ) {
case V_95 :
V_55 = 0 ;
break;
case V_97 :
V_55 = 1 ;
break;
case V_99 :
V_55 = 2 ;
break;
case V_101 :
V_55 = 3 ;
break;
}
return V_55 ;
}
static int F_52 ( struct V_27 * V_28 , T_1 V_55 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
enum V_93 V_46 = V_130 ;
switch ( V_55 ) {
case 0 :
V_46 = V_94 ;
break;
case 1 :
V_46 = V_96 ;
break;
case 2 :
V_46 = V_98 ;
break;
case 3 :
V_46 = V_100 ;
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
unsigned char V_131 ;
if ( V_45 -> V_12 <= 5 )
V_3 = F_12 ( V_45 -> V_12 ) + 2 ;
else
V_3 = V_132 ;
V_131 = F_1 ( V_45 -> V_2 , V_3 ) ;
if ( V_45 -> V_12 == 6 ) {
V_131 &= V_133 ;
} else {
V_131 &= V_134 ;
V_131 >>= V_135 ;
}
return V_34 >> V_131 ;
}
static long F_54 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long * V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned char V_131 ;
if ( V_45 -> V_12 >= 6 && V_35 > V_136 )
V_35 = V_136 ;
if ( V_35 > V_137 )
V_35 = V_137 ;
if ( V_35 < V_138 )
V_35 = V_138 ;
if ( F_43 ( V_28 ) & V_87 ) {
V_131 = V_139 ;
while ( V_35 < V_85 &&
V_131 < V_140 ) {
V_131 += 1 ;
V_35 *= 2 ;
}
* V_34 = V_35 ;
} else {
unsigned long V_141 , V_142 , V_143 ;
V_131 = V_139 ;
V_141 = * V_34 ;
V_143 = abs ( V_141 - V_35 ) ;
do {
V_141 >>= 1 ;
V_142 = abs ( V_141 - V_35 ) ;
if ( V_142 > V_143 || V_131 == V_140 )
break;
V_131 ++ ;
V_143 = V_142 ;
} while ( 1 );
}
V_35 = * V_34 >> V_131 ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_9 ,
V_43 , F_34 ( V_28 ) , ( 1 << V_131 ) ,
* V_34 , V_35 ) ;
return V_35 ;
}
static int F_55 ( struct V_27 * V_28 , unsigned long V_35 ,
unsigned long V_34 )
{
struct V_44 * V_45 =
F_18 ( V_28 , struct V_44 , V_28 ) ;
unsigned long V_141 , V_142 , V_143 ;
unsigned char V_131 ;
V_131 = V_139 ;
V_141 = V_34 ;
V_143 = abs ( V_141 - V_35 ) ;
do {
V_141 >>= 1 ;
V_142 = abs ( V_141 - V_35 ) ;
if ( V_142 > V_143 || V_131 == V_140 )
break;
V_131 ++ ;
V_143 = V_142 ;
} while ( 1 );
switch ( V_45 -> V_12 ) {
case 6 :
F_10 ( V_45 -> V_2 , V_132 ,
V_133 , V_131 ) ;
break;
case 7 :
F_10 ( V_45 -> V_2 , V_132 ,
V_134 ,
V_131 << V_135 ) ;
break;
default:
F_10 ( V_45 -> V_2 ,
F_12 ( V_45 -> V_12 ) + 2 ,
V_134 ,
V_131 << V_135 ) ;
}
F_10 ( V_45 -> V_2 , V_76 + V_45 -> V_12 ,
V_128 , 0 ) ;
F_6 ( V_45 -> V_2 , V_26 ,
V_144 | V_145 ) ;
F_23 ( & V_45 -> V_2 -> V_7 -> V_8 ,
L_9 ,
V_43 , F_34 ( V_28 ) , ( 1 << V_131 ) ,
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
V_78 ;
break;
case 1 :
V_153 -> V_163 [ V_12 ] . V_164 =
V_79 ;
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
V_94 ;
break;
case 1 :
V_153 -> V_163 [ V_12 ] . V_165 =
V_96 ;
break;
case 2 :
V_153 -> V_163 [ V_12 ] . V_165 =
V_98 ;
break;
case 3 :
if ( V_52 != V_53 ) {
F_3 ( & V_7 -> V_8 ,
L_20 ,
V_4 , V_12 ) ;
goto V_161;
}
V_153 -> V_163 [ V_12 ] . V_165 =
V_100 ;
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
case V_105 :
case V_107 :
case V_109 :
case V_111 :
V_153 -> V_163 [ V_12 ] . V_104 = V_4 ;
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
V_120 ;
break;
case 1 :
V_153 -> V_163 [ V_12 ] . V_166 =
V_122 ;
break;
case 2 :
V_153 -> V_163 [ V_12 ] . V_166 =
V_124 ;
break;
case 3 :
V_153 -> V_163 [ V_12 ] . V_166 =
V_126 ;
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
static int F_56 ( struct V_146 * V_7 , enum V_147 V_52 )
{
return 0 ;
}
static int F_64 ( struct V_146 * V_7 ,
const struct V_169 * V_170 )
{
enum V_147 V_52 = (enum V_147 ) V_170 -> V_171 ;
struct V_152 * V_153 ;
struct V_1 * V_2 ;
struct V_172 V_173 ;
struct V_174 * V_174 ;
const char * V_175 [ 4 ] ;
T_1 V_176 , V_177 ;
int V_5 , V_178 ;
V_5 = F_56 ( V_7 , V_52 ) ;
if ( V_5 )
return V_5 ;
V_153 = V_7 -> V_8 . V_168 ;
if ( ! V_153 )
return - V_51 ;
V_2 = F_57 ( & V_7 -> V_8 , sizeof( * V_2 ) , V_157 ) ;
if ( V_2 == NULL ) {
F_3 ( & V_7 -> V_8 , L_27 ) ;
return - V_158 ;
}
F_65 ( V_7 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_179 = F_66 ( & V_7 -> V_8 , L_28 ) ;
V_2 -> V_180 = F_66 ( & V_7 -> V_8 , L_29 ) ;
if ( F_67 ( V_2 -> V_179 ) == - V_181 ||
F_67 ( V_2 -> V_180 ) == - V_181 )
return - V_181 ;
if ( F_68 ( V_2 -> V_179 ) &&
( V_2 -> V_52 != V_53 || F_68 ( V_2 -> V_180 ) ) ) {
F_3 ( & V_7 -> V_8 , L_30 ) ;
return - V_51 ;
}
V_2 -> V_6 = F_69 ( V_7 , & V_182 ) ;
if ( F_68 ( V_2 -> V_6 ) ) {
F_3 ( & V_7 -> V_8 , L_31 ) ;
return F_67 ( V_2 -> V_6 ) ;
}
F_6 ( V_2 , V_183 , 0xf0 ) ;
if ( V_2 -> V_52 != V_53 )
F_10 ( V_2 , V_41 ,
V_48 | V_49 , 0 ) ;
for ( V_178 = 0 ; V_178 < 2 ; V_178 ++ ) {
V_5 = F_29 ( V_2 , V_178 , V_153 -> V_159 [ V_178 ] ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_32 ,
V_178 , V_153 -> V_159 [ V_178 ] ) ;
return V_5 ;
}
}
for ( V_178 = 0 ; V_178 < 8 ; V_178 ++ ) {
V_5 = F_38 ( V_2 , V_178 ,
V_153 -> V_163 [ V_178 ] . V_164 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_33 ,
V_178 , V_153 -> V_163 [ V_178 ] . V_164 ) ;
return V_5 ;
}
V_5 = F_46 ( V_2 , V_178 ,
V_153 -> V_163 [ V_178 ] . V_165 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_34 ,
V_178 , V_153 -> V_163 [ V_178 ] . V_165 ) ;
return V_5 ;
}
V_5 = F_47 ( V_2 , V_178 ,
V_153 -> V_163 [ V_178 ] . V_104 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_35 ,
V_178 , V_153 -> V_163 [ V_178 ] . V_104 ) ;
return V_5 ;
}
V_5 = F_48 ( V_2 , V_178 ,
V_153 -> V_163 [ V_178 ] . V_166 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 ,
L_36 ,
V_178 , V_153 -> V_163 [ V_178 ] . V_166 ) ;
return V_5 ;
}
}
if ( ! F_68 ( V_2 -> V_179 ) )
F_70 ( V_2 -> V_179 ) ;
if ( ! F_68 ( V_2 -> V_180 ) )
F_70 ( V_2 -> V_180 ) ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_160 = V_184 [ 0 ] ;
V_173 . V_185 = & V_186 ;
V_173 . V_187 = 0 ;
if ( ! F_68 ( V_2 -> V_179 ) ) {
V_2 -> V_188 = F_71 ( V_2 -> V_179 ) ;
V_173 . V_175 = & V_2 -> V_188 ;
V_173 . V_176 = 1 ;
}
V_2 -> V_29 . V_173 = & V_173 ;
V_174 = F_72 ( & V_7 -> V_8 , & V_2 -> V_29 ) ;
if ( F_68 ( V_174 ) ) {
F_3 ( & V_7 -> V_8 , L_37 , V_173 . V_160 ) ;
V_5 = F_67 ( V_174 ) ;
goto V_189;
}
if ( V_2 -> V_52 == V_53 ) {
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_160 = V_184 [ 1 ] ;
V_173 . V_185 = & V_190 ;
if ( ! F_68 ( V_2 -> V_180 ) ) {
V_2 -> V_191 = F_71 ( V_2 -> V_180 ) ;
V_173 . V_175 = & V_2 -> V_191 ;
V_173 . V_176 = 1 ;
}
V_2 -> V_32 . V_173 = & V_173 ;
V_174 = F_72 ( & V_7 -> V_8 , & V_2 -> V_32 ) ;
if ( F_68 ( V_174 ) ) {
F_3 ( & V_7 -> V_8 , L_37 ,
V_173 . V_160 ) ;
V_5 = F_67 ( V_174 ) ;
goto V_189;
}
}
V_176 = ( V_2 -> V_52 == V_53 ) ? 2 : 1 ;
V_175 [ 0 ] = V_184 [ 0 ] ;
V_175 [ 1 ] = V_184 [ 1 ] ;
V_2 -> V_192 [ 0 ] . V_12 = 0 ;
V_2 -> V_192 [ 0 ] . V_2 = V_2 ;
V_2 -> V_192 [ 0 ] . V_28 . V_173 = & V_173 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_160 = V_193 [ 0 ] ;
V_173 . V_185 = & V_194 ;
V_173 . V_187 = 0 ;
V_173 . V_175 = V_175 ;
V_173 . V_176 = V_176 ;
V_174 = F_72 ( & V_7 -> V_8 , & V_2 -> V_192 [ 0 ] . V_28 ) ;
if ( F_68 ( V_174 ) ) {
F_3 ( & V_7 -> V_8 , L_37 , V_173 . V_160 ) ;
V_5 = F_67 ( V_174 ) ;
goto V_189;
}
V_2 -> V_192 [ 1 ] . V_12 = 1 ;
V_2 -> V_192 [ 1 ] . V_2 = V_2 ;
V_2 -> V_192 [ 1 ] . V_28 . V_173 = & V_173 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
if ( V_2 -> V_52 == V_195 ) {
V_173 . V_160 = V_193 [ 2 ] ;
V_173 . V_185 = & V_196 ;
V_173 . V_187 = 0 ;
V_173 . V_175 = NULL ;
V_173 . V_176 = 0 ;
} else {
V_173 . V_160 = V_193 [ 1 ] ;
V_173 . V_185 = & V_194 ;
V_173 . V_187 = 0 ;
V_173 . V_175 = V_175 ;
V_173 . V_176 = V_176 ;
}
V_174 = F_72 ( & V_7 -> V_8 , & V_2 -> V_192 [ 1 ] . V_28 ) ;
if ( F_68 ( V_174 ) ) {
F_3 ( & V_7 -> V_8 , L_37 , V_173 . V_160 ) ;
V_5 = F_67 ( V_174 ) ;
goto V_189;
}
V_177 = ( V_2 -> V_52 == V_162 ) ? 3 : 8 ;
V_175 [ 0 ] = V_193 [ 0 ] ;
if ( V_2 -> V_52 == V_195 )
V_175 [ 1 ] = V_193 [ 2 ] ;
else
V_175 [ 1 ] = V_193 [ 1 ] ;
V_2 -> V_197 = F_57 ( & V_7 -> V_8 , V_177 *
sizeof( * V_2 -> V_197 ) , V_157 ) ;
V_2 -> V_163 = F_57 ( & V_7 -> V_8 , V_177 *
sizeof( * V_2 -> V_163 ) , V_157 ) ;
V_2 -> V_198 . V_199 = V_177 ;
V_2 -> V_198 . V_200 = F_57 ( & V_7 -> V_8 ,
V_177 * sizeof( * V_2 -> V_198 . V_200 ) , V_157 ) ;
if ( F_73 ( ! V_2 -> V_197 || ! V_2 -> V_163 ||
! V_2 -> V_198 . V_200 ) ) {
V_5 = - V_158 ;
goto V_189;
}
for ( V_178 = 0 ; V_178 < V_177 ; V_178 ++ ) {
V_2 -> V_197 [ V_178 ] . V_12 = V_178 ;
V_2 -> V_197 [ V_178 ] . V_2 = V_2 ;
V_2 -> V_197 [ V_178 ] . V_28 . V_173 = & V_173 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_160 = V_201 [ V_178 ] ;
V_173 . V_185 = & V_202 ;
V_173 . V_187 = 0 ;
if ( V_153 -> V_163 [ V_178 ] . V_167 )
V_173 . V_187 |= V_87 ;
V_173 . V_175 = V_175 ;
V_173 . V_176 = 2 ;
V_174 = F_72 ( & V_7 -> V_8 , & V_2 -> V_197 [ V_178 ] . V_28 ) ;
if ( F_68 ( V_174 ) ) {
F_3 ( & V_7 -> V_8 , L_37 ,
V_173 . V_160 ) ;
V_5 = F_67 ( V_174 ) ;
goto V_189;
}
}
V_176 = ( V_2 -> V_52 == V_53 ) ? 4 : 3 ;
V_175 [ 2 ] = V_184 [ 0 ] ;
V_175 [ 3 ] = V_184 [ 1 ] ;
for ( V_178 = 0 ; V_178 < V_177 ; V_178 ++ ) {
V_175 [ 0 ] = V_201 [ V_178 ] ;
V_175 [ 1 ] = ( V_178 < 4 ) ? V_201 [ 0 ] :
V_201 [ 4 ] ;
V_2 -> V_163 [ V_178 ] . V_12 = V_178 ;
V_2 -> V_163 [ V_178 ] . V_2 = V_2 ;
V_2 -> V_163 [ V_178 ] . V_28 . V_173 = & V_173 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_160 = V_203 [ V_178 ] ;
V_173 . V_185 = & V_204 ;
V_173 . V_187 = 0 ;
if ( V_153 -> V_163 [ V_178 ] . V_165 == V_94 )
V_173 . V_187 |= V_87 ;
V_173 . V_175 = V_175 ;
V_173 . V_176 = V_176 ;
V_174 = F_72 ( & V_7 -> V_8 , & V_2 -> V_163 [ V_178 ] . V_28 ) ;
if ( F_68 ( V_174 ) ) {
F_3 ( & V_7 -> V_8 , L_37 ,
V_173 . V_160 ) ;
V_5 = F_67 ( V_174 ) ;
goto V_189;
}
V_2 -> V_198 . V_200 [ V_178 ] = V_174 ;
if ( V_153 -> V_163 [ V_178 ] . V_35 != 0 ) {
int V_5 ;
V_5 = F_74 ( V_174 , V_153 -> V_163 [ V_178 ] . V_35 ) ;
if ( V_5 != 0 ) {
F_3 ( & V_7 -> V_8 , L_38 ,
V_5 ) ;
}
}
}
V_5 = F_75 ( V_7 -> V_8 . V_151 , V_205 ,
& V_2 -> V_198 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_8 , L_39 ) ;
goto V_189;
}
return 0 ;
V_189:
if ( ! F_68 ( V_2 -> V_179 ) )
F_76 ( V_2 -> V_179 ) ;
if ( ! F_68 ( V_2 -> V_180 ) )
F_76 ( V_2 -> V_180 ) ;
return V_5 ;
}
