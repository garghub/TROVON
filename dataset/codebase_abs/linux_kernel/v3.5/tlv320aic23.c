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
struct V_5 * V_6 = V_54 -> V_6 ;
T_1 V_55 ;
int V_56 ;
struct V_57 * V_57 = F_14 ( V_6 ) ;
T_2 V_38 = V_57 -> V_58 ;
T_2 V_39 = V_57 -> V_59 ;
T_2 V_60 = F_15 ( V_52 ) ;
if ( V_50 -> V_61 == V_62 ) {
V_57 -> V_59 = V_39 = V_60 ;
if ( ! V_38 )
V_38 = V_60 ;
} else {
V_57 -> V_58 = V_38 = V_60 ;
if ( ! V_39 )
V_39 = V_60 ;
}
V_56 = F_10 ( V_6 , V_57 -> V_22 , V_38 ,
V_39 ) ;
if ( V_56 < 0 )
return V_56 ;
V_55 = F_3 ( V_6 , V_63 ) & ~ ( 0x03 << 2 ) ;
switch ( F_16 ( V_52 ) ) {
case V_64 :
break;
case V_65 :
V_55 |= ( 0x01 << 2 ) ;
break;
case V_66 :
V_55 |= ( 0x02 << 2 ) ;
break;
case V_67 :
V_55 |= ( 0x03 << 2 ) ;
break;
}
F_4 ( V_6 , V_63 , V_55 ) ;
return 0 ;
}
static int F_17 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
struct V_5 * V_6 = V_54 -> V_6 ;
F_4 ( V_6 , V_68 , 0x0001 ) ;
return 0 ;
}
static void F_18 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
struct V_5 * V_6 = V_54 -> V_6 ;
struct V_57 * V_57 = F_14 ( V_6 ) ;
if ( ! V_6 -> V_69 ) {
F_19 ( 50 ) ;
F_4 ( V_6 , V_68 , 0x0 ) ;
}
if ( V_50 -> V_61 == V_62 )
V_57 -> V_59 = 0 ;
else
V_57 -> V_58 = 0 ;
}
static int F_20 ( struct V_53 * V_54 , int V_70 )
{
struct V_5 * V_6 = V_54 -> V_6 ;
T_1 V_8 ;
V_8 = F_3 ( V_6 , V_71 ) ;
if ( V_70 )
V_8 |= V_72 ;
else
V_8 &= ~ V_72 ;
F_4 ( V_6 , V_71 , V_8 ) ;
return 0 ;
}
static int F_21 ( struct V_53 * V_73 ,
unsigned int V_74 )
{
struct V_5 * V_6 = V_73 -> V_6 ;
T_1 V_55 ;
V_55 = F_3 ( V_6 , V_63 ) & ( ~ 0x03 ) ;
switch ( V_74 & V_75 ) {
case V_76 :
V_55 |= V_77 ;
break;
case V_78 :
V_55 &= ~ V_77 ;
break;
default:
return - V_47 ;
}
switch ( V_74 & V_79 ) {
case V_80 :
V_55 |= V_81 ;
break;
case V_82 :
V_55 |= V_83 ;
case V_84 :
V_55 |= V_85 ;
break;
case V_86 :
break;
case V_87 :
V_55 |= V_88 ;
break;
default:
return - V_47 ;
}
F_4 ( V_6 , V_63 , V_55 ) ;
return 0 ;
}
static int F_22 ( struct V_53 * V_73 ,
int V_89 , unsigned int V_90 , int V_91 )
{
struct V_57 * V_57 = F_23 ( V_73 ) ;
V_57 -> V_22 = V_90 ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 ,
enum V_92 V_93 )
{
T_1 V_8 = F_3 ( V_6 , V_94 ) & 0x17f ;
switch ( V_93 ) {
case V_95 :
V_8 &= ~ ( V_96 | V_97 | \
V_98 ) ;
F_4 ( V_6 , V_94 , V_8 ) ;
break;
case V_99 :
break;
case V_100 :
F_4 ( V_6 , V_94 ,
V_8 | V_101 ) ;
break;
case V_102 :
F_4 ( V_6 , V_68 , 0x0 ) ;
F_4 ( V_6 , V_94 , 0x1ff ) ;
break;
}
V_6 -> V_103 . V_104 = V_93 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_102 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
F_27 ( V_6 ) ;
F_24 ( V_6 , V_100 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_57 * V_57 = F_14 ( V_6 ) ;
int V_56 ;
V_56 = F_29 ( V_6 , 7 , 9 , V_57 -> V_105 ) ;
if ( V_56 < 0 ) {
F_30 ( V_6 -> V_106 , L_3 , V_56 ) ;
return V_56 ;
}
F_4 ( V_6 , V_107 , 0 ) ;
F_31 ( V_6 , 0x0A , 0 ) ;
F_31 ( V_6 , 0x0B , 0 ) ;
F_31 ( V_6 , 0x0C , 0 ) ;
F_31 ( V_6 , 0x0D , 0 ) ;
F_31 ( V_6 , 0x0E , 0 ) ;
F_24 ( V_6 , V_100 ) ;
F_4 ( V_6 , V_71 , V_108 ) ;
F_32 ( V_6 , V_109 ,
V_110 , V_111 ) ;
F_32 ( V_6 , V_112 ,
V_110 , V_111 ) ;
F_32 ( V_6 , V_10 ,
V_113 | V_114 ,
0 ) ;
F_4 ( V_6 , V_115 ,
V_116 & V_117 ) ;
F_4 ( V_6 , V_118 ,
V_116 & V_117 ) ;
F_4 ( V_6 , V_68 , 0x1 ) ;
F_33 ( V_6 , V_119 ,
F_8 ( V_119 ) ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_102 ) ;
return 0 ;
}
static int F_35 ( struct V_120 * V_121 ,
const struct V_122 * V_123 )
{
struct V_57 * V_57 ;
int V_56 ;
if ( ! F_36 ( V_121 -> V_124 , V_125 ) )
return - V_47 ;
V_57 = F_37 ( & V_121 -> V_106 , sizeof( struct V_57 ) , V_126 ) ;
if ( V_57 == NULL )
return - V_127 ;
F_38 ( V_121 , V_57 ) ;
V_57 -> V_105 = V_128 ;
V_56 = F_39 ( & V_121 -> V_106 ,
& V_129 , & V_130 , 1 ) ;
return V_56 ;
}
static int T_3 F_40 ( struct V_120 * V_121 )
{
F_41 ( & V_121 -> V_106 ) ;
return 0 ;
}
static int T_4 F_42 ( void )
{
int V_56 ;
#if F_43 ( V_131 ) || F_43 ( V_132 )
V_56 = F_44 ( & V_133 ) ;
if ( V_56 != 0 ) {
F_11 ( V_45 L_4 ,
V_56 ) ;
}
#endif
return V_56 ;
}
static void T_3 F_45 ( void )
{
#if F_43 ( V_131 ) || F_43 ( V_132 )
F_46 ( & V_133 ) ;
#endif
}
