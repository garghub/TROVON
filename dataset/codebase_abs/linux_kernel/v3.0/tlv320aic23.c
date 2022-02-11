static inline unsigned int F_1 ( struct V_1
* V_2 , unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= F_2 ( V_6 ) )
return - 1 ;
return V_4 [ V_3 ] ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_2 V_3 , T_1 V_7 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= F_2 ( V_6 ) )
return;
V_4 [ V_3 ] = V_7 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
T_2 V_8 [ 2 ] ;
if ( V_3 > 9 && V_3 != 15 ) {
F_5 ( V_9 L_1 , V_10 , V_3 ) ;
return - 1 ;
}
V_8 [ 0 ] = ( V_3 << 1 ) | ( V_7 >> 8 & 0x01 ) ;
V_8 [ 1 ] = V_7 & 0xff ;
F_3 ( V_2 , V_3 , V_7 ) ;
if ( V_2 -> V_11 ( V_2 -> V_12 , V_8 , 2 ) == 2 )
return 0 ;
F_5 ( V_13 L_2 , V_10 ,
V_7 , V_3 ) ;
return - V_14 ;
}
static int F_6 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
T_1 V_19 , V_3 ;
V_19 = ( V_18 -> V_7 . integer . V_7 [ 0 ] & 0x07 ) ;
V_19 = ( V_19 >= 4 ) ? 4 : ( 3 - V_19 ) ;
V_3 = F_1 ( V_2 , V_20 ) & ( ~ 0x1C0 ) ;
F_4 ( V_2 , V_20 , V_3 | ( V_19 << 6 ) ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
T_1 V_19 ;
V_19 = F_1 ( V_2 , V_20 ) & ( 0x1C0 ) ;
V_19 = V_19 >> 6 ;
V_19 = ( V_19 >= 4 ) ? 4 : ( 3 - V_19 ) ;
V_18 -> V_7 . integer . V_7 [ 0 ] = V_19 ;
return 0 ;
}
static unsigned F_9 ( int V_21 , int V_22 , int V_23 , int V_24 ,
int V_25 , int V_26 , int V_27 , int V_28 )
{
if ( ( V_21 >= V_22 ) && ( V_21 <= V_23 ) &&
( V_25 >= V_26 ) && ( V_25 <= V_27 ) ) {
int V_29 = V_24 - V_21 ;
int V_30 = V_28 - V_25 ;
return abs ( V_29 ) + abs ( V_30 ) ;
}
return V_31 ;
}
static int F_10 ( int V_32 , T_3 V_24 , T_3 V_28 )
{
int V_33 , V_34 ;
int V_35 = - 1 ;
int V_36 = - 1 ;
int V_37 = 0 ;
unsigned V_38 = V_31 ;
int V_22 , V_23 , V_26 , V_27 ;
V_24 *= V_39 ;
V_28 *= V_39 ;
V_22 = V_24 - ( V_24 >> 5 ) ;
V_23 = V_24 + ( V_24 >> 5 ) ;
V_26 = V_28 - ( V_28 >> 5 ) ;
V_27 = V_28 + ( V_28 >> 5 ) ;
for ( V_33 = 0 ; V_33 < F_2 ( V_40 ) ; V_33 ++ ) {
int V_41 = V_32 / V_40 [ V_33 ] ;
int V_42 = V_43 [ V_33 ] ;
for ( V_34 = 0 ; V_34 < F_2 ( V_44 ) ;
V_34 ++ , V_42 >>= 1 ) {
int V_21 ;
int V_25 ;
int V_45 ;
if ( ( V_42 & 1 ) == 0 )
continue;
V_21 = V_41 * V_44 [ V_34 ] ;
V_25 = V_41 * V_46 [ V_34 ] ;
V_45 = F_9 ( V_21 , V_22 , V_23 , V_24 ,
V_25 , V_26 , V_27 , V_28 ) ;
if ( V_38 > V_45 ) {
V_38 = V_45 ;
V_35 = V_33 ;
V_36 = V_34 ;
V_37 = 0 ;
}
V_45 = F_9 ( ( V_21 >> 1 ) , V_22 , V_23 , V_24 ,
( V_25 >> 1 ) , V_26 , V_27 , V_28 ) ;
if ( ( V_45 != V_31 ) && ( V_38 >= V_45 ) ) {
V_38 = V_45 ;
V_35 = V_33 ;
V_36 = V_34 ;
V_37 = 1 ;
}
}
}
return ( V_36 << 2 ) | V_35 | ( V_37 << V_47 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_32 ,
T_3 * V_48 , T_3 * V_49 )
{
int V_50 = F_1 ( V_2 , V_51 ) ;
int V_52 = ( V_50 >> 2 ) & 0x0f ;
int V_19 = ( V_32 / V_40 [ V_50 & 3 ] ) ;
int V_21 = ( V_19 * V_44 [ V_52 ] ) / V_39 ;
int V_25 = ( V_19 * V_46 [ V_52 ] ) / V_39 ;
if ( V_50 & V_53 ) {
V_21 >>= 1 ;
V_25 >>= 1 ;
}
* V_48 = V_21 ;
* V_49 = V_25 ;
}
static int F_12 ( struct V_1 * V_2 , int V_32 ,
T_3 V_48 , T_3 V_49 )
{
int V_8 = F_10 ( V_32 , V_48 , V_49 ) ;
if ( V_8 < 0 ) {
F_5 ( V_13 L_3 ,
V_10 , V_48 , V_49 ) ;
return - V_54 ;
}
F_4 ( V_2 , V_51 , V_8 ) ;
#ifdef F_13
{
T_3 V_21 , V_25 ;
F_11 ( V_2 , V_32 , & V_21 , & V_25 ) ;
F_5 ( V_55 L_4 ,
V_21 , V_25 , V_8 ) ;
}
#endif
return 0 ;
}
static int F_14 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = V_57 -> V_64 ;
struct V_1 * V_2 = V_63 -> V_2 ;
T_1 V_65 ;
int V_66 ;
struct V_67 * V_67 = F_15 ( V_2 ) ;
T_3 V_48 = V_67 -> V_68 ;
T_3 V_49 = V_67 -> V_69 ;
T_3 V_70 = F_16 ( V_59 ) ;
if ( V_57 -> V_71 == V_72 ) {
V_67 -> V_69 = V_49 = V_70 ;
if ( ! V_48 )
V_48 = V_70 ;
} else {
V_67 -> V_68 = V_48 = V_70 ;
if ( ! V_49 )
V_49 = V_70 ;
}
V_66 = F_12 ( V_2 , V_67 -> V_32 , V_48 ,
V_49 ) ;
if ( V_66 < 0 )
return V_66 ;
V_65 =
F_1 ( V_2 ,
V_73 ) & ~ ( 0x03 << 2 ) ;
switch ( F_17 ( V_59 ) ) {
case V_74 :
break;
case V_75 :
V_65 |= ( 0x01 << 2 ) ;
break;
case V_76 :
V_65 |= ( 0x02 << 2 ) ;
break;
case V_77 :
V_65 |= ( 0x03 << 2 ) ;
break;
}
F_4 ( V_2 , V_73 , V_65 ) ;
return 0 ;
}
static int F_18 ( struct V_56 * V_57 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = V_57 -> V_64 ;
struct V_1 * V_2 = V_63 -> V_2 ;
F_4 ( V_2 , V_78 , 0x0001 ) ;
return 0 ;
}
static void F_19 ( struct V_56 * V_57 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = V_57 -> V_64 ;
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_67 * V_67 = F_15 ( V_2 ) ;
if ( ! V_2 -> V_79 ) {
F_20 ( 50 ) ;
F_4 ( V_2 , V_78 , 0x0 ) ;
}
if ( V_57 -> V_71 == V_72 )
V_67 -> V_69 = 0 ;
else
V_67 -> V_68 = 0 ;
}
static int F_21 ( struct V_60 * V_61 , int V_80 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_81 ) ;
if ( V_80 )
V_3 |= V_82 ;
else
V_3 &= ~ V_82 ;
F_4 ( V_2 , V_81 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_60 * V_83 ,
unsigned int V_84 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
T_1 V_65 ;
V_65 =
F_1 ( V_2 , V_73 ) & ( ~ 0x03 ) ;
switch ( V_84 & V_85 ) {
case V_86 :
V_65 |= V_87 ;
break;
case V_88 :
break;
default:
return - V_54 ;
}
switch ( V_84 & V_89 ) {
case V_90 :
V_65 |= V_91 ;
break;
case V_92 :
V_65 |= V_93 ;
case V_94 :
V_65 |= V_95 ;
break;
case V_96 :
break;
case V_97 :
V_65 |= V_98 ;
break;
default:
return - V_54 ;
}
F_4 ( V_2 , V_73 , V_65 ) ;
return 0 ;
}
static int F_23 ( struct V_60 * V_83 ,
int V_99 , unsigned int V_100 , int V_101 )
{
struct V_67 * V_67 = F_24 ( V_83 ) ;
V_67 -> V_32 = V_100 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_102 V_103 )
{
T_1 V_3 = F_1 ( V_2 , V_104 ) & 0xff7f ;
switch ( V_103 ) {
case V_105 :
V_3 &= ~ ( V_106 | V_107 | \
V_108 ) ;
F_4 ( V_2 , V_104 , V_3 ) ;
break;
case V_109 :
break;
case V_110 :
F_4 ( V_2 , V_104 , V_3 | \
V_111 ) ;
break;
case V_112 :
F_4 ( V_2 , V_78 , 0x0 ) ;
F_4 ( V_2 , V_104 , 0xffff ) ;
break;
}
V_2 -> V_113 . V_114 = V_103 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
T_4 V_115 )
{
F_25 ( V_2 , V_112 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 <= V_78 ; V_3 ++ ) {
T_1 V_19 = F_1 ( V_2 , V_3 ) ;
F_4 ( V_2 , V_3 , V_19 ) ;
}
F_25 ( V_2 , V_110 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_67 * V_67 = F_15 ( V_2 ) ;
int V_3 ;
F_5 ( V_116 L_5 , V_117 ) ;
V_2 -> V_12 = V_67 -> V_12 ;
V_2 -> V_11 = ( V_118 ) V_119 ;
V_2 -> V_120 = NULL ;
F_4 ( V_2 , V_121 , 0 ) ;
F_25 ( V_2 , V_110 ) ;
F_4 ( V_2 , V_81 , V_122 ) ;
V_3 = F_1 ( V_2 , V_123 ) ;
F_4 ( V_2 , V_123 ,
( V_3 & ( ~ V_124 ) ) |
( V_125 ) ) ;
V_3 = F_1 ( V_2 , V_126 ) ;
F_4 ( V_2 , V_126 ,
( V_3 & ( ~ V_124 ) ) |
V_125 ) ;
V_3 = F_1 ( V_2 , V_20 ) ;
F_4 ( V_2 , V_20 ,
( V_3 ) & ( ~ V_127 ) &
( ~ V_128 ) ) ;
F_4 ( V_2 , V_129 ,
V_130 &
V_131 ) ;
F_4 ( V_2 , V_132 ,
V_130 &
V_131 ) ;
F_4 ( V_2 , V_78 , 0x1 ) ;
F_29 ( V_2 , V_133 ,
F_2 ( V_133 ) ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_25 ( V_2 , V_112 ) ;
return 0 ;
}
static int F_31 ( struct V_134 * V_135 ,
const struct V_136 * V_137 )
{
struct V_67 * V_67 ;
int V_66 ;
if ( ! F_32 ( V_135 -> V_138 , V_139 ) )
return - V_54 ;
V_67 = F_33 ( sizeof( struct V_67 ) , V_140 ) ;
if ( V_67 == NULL )
return - V_141 ;
F_34 ( V_135 , V_67 ) ;
V_67 -> V_12 = V_135 ;
V_67 -> V_142 = V_143 ;
V_66 = F_35 ( & V_135 -> V_144 ,
& V_145 , & V_146 , 1 ) ;
if ( V_66 < 0 )
F_36 ( V_67 ) ;
return V_66 ;
}
static int T_5 F_37 ( struct V_134 * V_135 )
{
F_38 ( & V_135 -> V_144 ) ;
F_36 ( F_39 ( V_135 ) ) ;
return 0 ;
}
static int T_6 F_40 ( void )
{
int V_66 ;
#if F_41 ( V_147 ) || F_41 ( V_148 )
V_66 = F_42 ( & V_149 ) ;
if ( V_66 != 0 ) {
F_5 ( V_13 L_6 ,
V_66 ) ;
}
#endif
return V_66 ;
}
static void T_5 F_43 ( void )
{
#if F_41 ( V_147 ) || F_41 ( V_148 )
F_44 ( & V_149 ) ;
#endif
}
