static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 , V_8 ;
V_7 = ( V_4 -> V_9 . integer . V_9 [ 0 ] & 0x07 ) ;
V_7 = ( V_7 >= 4 ) ? 4 : ( 3 - V_7 ) ;
V_8 = F_3 ( V_6 , V_10 ) & ( ~ 0x1C0 ) ;
F_4 ( V_6 , V_10 , V_8 | ( V_7 << 6 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_6 , V_10 ) & ( 0x1C0 ) ;
V_7 = V_7 >> 6 ;
V_7 = ( V_7 >= 4 ) ? 4 : ( 3 - V_7 ) ;
V_4 -> V_9 . integer . V_9 [ 0 ] = V_7 ;
return 0 ;
}
static unsigned F_6 ( int V_11 , int V_12 , int V_13 , int V_14 ,
int V_15 , int V_16 , int V_17 , int V_18 )
{
if ( ( V_11 >= V_12 ) && ( V_11 <= V_13 ) &&
( V_15 >= V_16 ) && ( V_15 <= V_17 ) ) {
int V_19 = V_14 - V_11 ;
int V_20 = V_18 - V_15 ;
return abs ( V_19 ) + abs ( V_20 ) ;
}
return V_21 ;
}
static int F_7 ( int V_22 , T_2 V_14 , T_2 V_18 )
{
int V_23 , V_24 ;
int V_25 = - 1 ;
int V_26 = - 1 ;
int V_27 = 0 ;
unsigned V_28 = V_21 ;
int V_12 , V_13 , V_16 , V_17 ;
V_14 *= V_29 ;
V_18 *= V_29 ;
V_12 = V_14 - ( V_14 >> 5 ) ;
V_13 = V_14 + ( V_14 >> 5 ) ;
V_16 = V_18 - ( V_18 >> 5 ) ;
V_17 = V_18 + ( V_18 >> 5 ) ;
for ( V_23 = 0 ; V_23 < F_8 ( V_30 ) ; V_23 ++ ) {
int V_31 = V_22 / V_30 [ V_23 ] ;
int V_32 = V_33 [ V_23 ] ;
for ( V_24 = 0 ; V_24 < F_8 ( V_34 ) ;
V_24 ++ , V_32 >>= 1 ) {
int V_11 ;
int V_15 ;
int V_35 ;
if ( ( V_32 & 1 ) == 0 )
continue;
V_11 = V_31 * V_34 [ V_24 ] ;
V_15 = V_31 * V_36 [ V_24 ] ;
V_35 = F_6 ( V_11 , V_12 , V_13 , V_14 ,
V_15 , V_16 , V_17 , V_18 ) ;
if ( V_28 > V_35 ) {
V_28 = V_35 ;
V_25 = V_23 ;
V_26 = V_24 ;
V_27 = 0 ;
}
V_35 = F_6 ( ( V_11 >> 1 ) , V_12 , V_13 , V_14 ,
( V_15 >> 1 ) , V_16 , V_17 , V_18 ) ;
if ( ( V_35 != V_21 ) && ( V_28 >= V_35 ) ) {
V_28 = V_35 ;
V_25 = V_23 ;
V_26 = V_24 ;
V_27 = 1 ;
}
}
}
return ( V_26 << 2 ) | V_25 | ( V_27 << V_37 ) ;
}
static void F_9 ( struct V_5 * V_6 , int V_22 ,
T_2 * V_38 , T_2 * V_39 )
{
int V_40 = F_3 ( V_6 , V_41 ) ;
int V_42 = ( V_40 >> 2 ) & 0x0f ;
int V_7 = ( V_22 / V_30 [ V_40 & 3 ] ) ;
int V_11 = ( V_7 * V_34 [ V_42 ] ) / V_29 ;
int V_15 = ( V_7 * V_36 [ V_42 ] ) / V_29 ;
if ( V_40 & V_43 ) {
V_11 >>= 1 ;
V_15 >>= 1 ;
}
* V_38 = V_11 ;
* V_39 = V_15 ;
}
static int F_10 ( struct V_5 * V_6 , int V_22 ,
T_2 V_38 , T_2 V_39 )
{
int V_44 = F_7 ( V_22 , V_38 , V_39 ) ;
if ( V_44 < 0 ) {
F_11 ( V_45 L_1 ,
V_46 , V_38 , V_39 ) ;
return - V_47 ;
}
F_4 ( V_6 , V_41 , V_44 ) ;
#ifdef F_12
{
T_2 V_11 , V_15 ;
F_9 ( V_6 , V_22 , & V_11 , & V_15 ) ;
F_11 ( V_48 L_2 ,
V_11 , V_15 , V_44 ) ;
}
#endif
return 0 ;
}
static int F_13 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = V_50 -> V_57 ;
struct V_5 * V_6 = V_56 -> V_6 ;
T_1 V_58 ;
int V_59 ;
struct V_60 * V_60 = F_14 ( V_6 ) ;
T_2 V_38 = V_60 -> V_61 ;
T_2 V_39 = V_60 -> V_62 ;
T_2 V_63 = F_15 ( V_52 ) ;
if ( V_50 -> V_64 == V_65 ) {
V_60 -> V_62 = V_39 = V_63 ;
if ( ! V_38 )
V_38 = V_63 ;
} else {
V_60 -> V_61 = V_38 = V_63 ;
if ( ! V_39 )
V_39 = V_63 ;
}
V_59 = F_10 ( V_6 , V_60 -> V_22 , V_38 ,
V_39 ) ;
if ( V_59 < 0 )
return V_59 ;
V_58 = F_3 ( V_6 , V_66 ) & ~ ( 0x03 << 2 ) ;
switch ( F_16 ( V_52 ) ) {
case V_67 :
break;
case V_68 :
V_58 |= ( 0x01 << 2 ) ;
break;
case V_69 :
V_58 |= ( 0x02 << 2 ) ;
break;
case V_70 :
V_58 |= ( 0x03 << 2 ) ;
break;
}
F_4 ( V_6 , V_66 , V_58 ) ;
return 0 ;
}
static int F_17 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = V_50 -> V_57 ;
struct V_5 * V_6 = V_56 -> V_6 ;
F_4 ( V_6 , V_71 , 0x0001 ) ;
return 0 ;
}
static void F_18 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = V_50 -> V_57 ;
struct V_5 * V_6 = V_56 -> V_6 ;
struct V_60 * V_60 = F_14 ( V_6 ) ;
if ( ! V_6 -> V_72 ) {
F_19 ( 50 ) ;
F_4 ( V_6 , V_71 , 0x0 ) ;
}
if ( V_50 -> V_64 == V_65 )
V_60 -> V_62 = 0 ;
else
V_60 -> V_61 = 0 ;
}
static int F_20 ( struct V_53 * V_54 , int V_73 )
{
struct V_5 * V_6 = V_54 -> V_6 ;
T_1 V_8 ;
V_8 = F_3 ( V_6 , V_74 ) ;
if ( V_73 )
V_8 |= V_75 ;
else
V_8 &= ~ V_75 ;
F_4 ( V_6 , V_74 , V_8 ) ;
return 0 ;
}
static int F_21 ( struct V_53 * V_76 ,
unsigned int V_77 )
{
struct V_5 * V_6 = V_76 -> V_6 ;
T_1 V_58 ;
V_58 = F_3 ( V_6 , V_66 ) & ( ~ 0x03 ) ;
switch ( V_77 & V_78 ) {
case V_79 :
V_58 |= V_80 ;
break;
case V_81 :
V_58 &= ~ V_80 ;
break;
default:
return - V_47 ;
}
switch ( V_77 & V_82 ) {
case V_83 :
V_58 |= V_84 ;
break;
case V_85 :
V_58 |= V_86 ;
case V_87 :
V_58 |= V_88 ;
break;
case V_89 :
break;
case V_90 :
V_58 |= V_91 ;
break;
default:
return - V_47 ;
}
F_4 ( V_6 , V_66 , V_58 ) ;
return 0 ;
}
static int F_22 ( struct V_53 * V_76 ,
int V_92 , unsigned int V_93 , int V_94 )
{
struct V_60 * V_60 = F_23 ( V_76 ) ;
V_60 -> V_22 = V_93 ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 ,
enum V_95 V_96 )
{
T_1 V_8 = F_3 ( V_6 , V_97 ) & 0xff7f ;
switch ( V_96 ) {
case V_98 :
V_8 &= ~ ( V_99 | V_100 | \
V_101 ) ;
F_4 ( V_6 , V_97 , V_8 ) ;
break;
case V_102 :
break;
case V_103 :
F_4 ( V_6 , V_97 ,
V_8 | V_104 ) ;
break;
case V_105 :
F_4 ( V_6 , V_71 , 0x0 ) ;
F_4 ( V_6 , V_97 , 0xffff ) ;
break;
}
V_6 -> V_106 . V_107 = V_96 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_105 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
F_27 ( V_6 ) ;
F_24 ( V_6 , V_103 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_60 * V_60 = F_14 ( V_6 ) ;
int V_59 ;
F_11 ( V_108 L_3 , V_109 ) ;
V_59 = F_29 ( V_6 , 7 , 9 , V_60 -> V_110 ) ;
if ( V_59 < 0 ) {
F_30 ( V_6 -> V_111 , L_4 , V_59 ) ;
return V_59 ;
}
F_4 ( V_6 , V_112 , 0 ) ;
F_31 ( V_6 , 0x0A , 0 ) ;
F_31 ( V_6 , 0x0B , 0 ) ;
F_31 ( V_6 , 0x0C , 0 ) ;
F_31 ( V_6 , 0x0D , 0 ) ;
F_31 ( V_6 , 0x0E , 0 ) ;
F_24 ( V_6 , V_103 ) ;
F_4 ( V_6 , V_74 , V_113 ) ;
F_32 ( V_6 , V_114 ,
V_115 , V_116 ) ;
F_32 ( V_6 , V_117 ,
V_115 , V_116 ) ;
F_32 ( V_6 , V_10 ,
V_118 | V_119 ,
0 ) ;
F_4 ( V_6 , V_120 ,
V_121 & V_122 ) ;
F_4 ( V_6 , V_123 ,
V_121 & V_122 ) ;
F_4 ( V_6 , V_71 , 0x1 ) ;
F_33 ( V_6 , V_124 ,
F_8 ( V_124 ) ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_105 ) ;
return 0 ;
}
static int F_35 ( struct V_125 * V_126 ,
const struct V_127 * V_128 )
{
struct V_60 * V_60 ;
int V_59 ;
if ( ! F_36 ( V_126 -> V_129 , V_130 ) )
return - V_47 ;
V_60 = F_37 ( & V_126 -> V_111 , sizeof( struct V_60 ) , V_131 ) ;
if ( V_60 == NULL )
return - V_132 ;
F_38 ( V_126 , V_60 ) ;
V_60 -> V_110 = V_133 ;
V_59 = F_39 ( & V_126 -> V_111 ,
& V_134 , & V_135 , 1 ) ;
return V_59 ;
}
static int T_3 F_40 ( struct V_125 * V_126 )
{
F_41 ( & V_126 -> V_111 ) ;
return 0 ;
}
static int T_4 F_42 ( void )
{
int V_59 ;
#if F_43 ( V_136 ) || F_43 ( V_137 )
V_59 = F_44 ( & V_138 ) ;
if ( V_59 != 0 ) {
F_11 ( V_45 L_5 ,
V_59 ) ;
}
#endif
return V_59 ;
}
static void T_3 F_45 ( void )
{
#if F_43 ( V_136 ) || F_43 ( V_137 )
F_46 ( & V_138 ) ;
#endif
}
