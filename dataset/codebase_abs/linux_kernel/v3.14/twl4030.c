static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
for ( V_3 = V_5 ; V_3 <= V_6 ; V_3 ++ ) {
F_2 ( V_7 , & V_4 , V_3 ) ;
V_2 -> V_8 [ V_3 - V_5 ] = V_4 ;
}
}
static unsigned int F_3 ( struct V_9 * V_10 , unsigned int V_11 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_12 = 0 ;
if ( V_11 >= V_13 )
return - V_14 ;
switch ( V_11 ) {
case V_5 :
case V_15 :
case V_16 :
case V_17 :
case V_6 :
case V_18 :
V_12 = V_2 -> V_8 [ V_11 - V_5 ] ;
break;
default:
F_2 ( V_7 , & V_12 , V_11 ) ;
break;
}
return V_12 ;
}
static bool F_5 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
bool V_19 = false ;
switch ( V_11 ) {
case V_5 :
if ( V_2 -> V_20 )
V_19 = true ;
break;
case V_15 :
if ( V_2 -> V_21 )
V_19 = true ;
break;
case V_16 :
if ( V_2 -> V_22 )
V_19 = true ;
break;
case V_17 :
if ( V_2 -> V_23 )
V_19 = true ;
break;
case V_6 :
if ( V_2 -> V_24 )
V_19 = true ;
break;
case V_18 :
if ( V_2 -> V_25 || V_2 -> V_26 )
V_19 = true ;
break;
default:
V_19 = true ;
break;
}
return V_19 ;
}
static int F_6 ( struct V_9 * V_10 , unsigned int V_11 ,
unsigned int V_12 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
switch ( V_11 ) {
case V_5 :
case V_15 :
case V_16 :
case V_17 :
case V_6 :
case V_18 :
V_2 -> V_8 [ V_11 - V_5 ] = V_12 ;
break;
default:
break;
}
if ( F_5 ( V_2 , V_11 ) )
return F_7 ( V_7 , V_12 , V_11 ) ;
return 0 ;
}
static inline void F_8 ( int time )
{
if ( time < 60 ) {
time *= 1000 ;
F_9 ( time , time + 500 ) ;
} else {
F_10 ( time ) ;
}
}
static void F_11 ( struct V_9 * V_10 , int V_27 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
int V_28 ;
if ( V_27 == V_2 -> V_29 )
return;
if ( V_27 )
V_28 = F_12 ( V_30 ) ;
else
V_28 = F_13 ( V_30 ) ;
if ( V_28 >= 0 )
V_2 -> V_29 = V_27 ;
F_14 ( 10 ) ;
}
static void F_15 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_12 ;
F_16 ( V_34 , L_1 ,
& V_32 -> V_35 ) ;
F_16 ( V_34 , L_2 ,
& V_32 -> V_36 ) ;
F_16 ( V_34 , L_3 ,
& V_32 -> V_37 ) ;
if ( ! F_16 ( V_34 , L_4 , & V_12 ) )
V_32 -> V_38 = V_12 ;
V_32 -> V_39 = F_17 ( V_34 ,
L_5 , 0 ) ;
if ( F_18 ( V_32 -> V_39 ) )
V_32 -> V_38 = 1 ;
}
static struct V_31 * F_19 ( struct V_9 * V_10 )
{
struct V_31 * V_32 = F_20 ( V_10 -> V_40 ) ;
struct V_33 * V_41 = NULL ;
V_41 = F_21 ( V_10 -> V_40 -> V_42 -> V_43 ,
L_6 ) ;
if ( ! V_32 && V_41 ) {
V_32 = F_22 ( V_10 -> V_40 ,
sizeof( struct V_31 ) ,
V_44 ) ;
if ( ! V_32 ) {
F_23 ( V_10 -> V_40 , L_7 ) ;
return NULL ;
}
F_15 ( V_32 , V_41 ) ;
}
return V_32 ;
}
static void F_24 ( struct V_9 * V_10 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_11 , V_4 ;
int V_3 = 0 ;
V_32 = F_19 ( V_10 ) ;
if ( V_32 && V_32 -> V_38 ) {
if ( F_18 ( V_32 -> V_39 ) ) {
int V_45 ;
if ( ! V_32 -> V_39 )
F_25 ( V_10 -> V_40 ,
L_8 ) ;
V_45 = F_26 ( V_32 -> V_39 ,
V_46 ,
L_9 ) ;
if ( V_45 ) {
F_23 ( V_10 -> V_40 ,
L_10 ) ;
V_32 -> V_39 = - 1 ;
}
} else {
T_1 V_47 ;
F_2 ( V_48 , & V_47 ,
V_49 ) ;
V_47 &= ~ F_27 ( 0x03 ) ;
V_47 |= F_27 ( 0x02 ) ;
F_7 ( V_48 , V_47 ,
V_49 ) ;
}
}
F_1 ( V_2 ) ;
V_11 = F_3 ( V_10 , V_50 ) ;
F_6 ( V_10 , V_50 ,
V_11 | V_51 ) ;
F_6 ( V_10 , V_52 ,
V_53 | V_54 |
V_55 | V_56 ) ;
F_6 ( V_10 , V_57 , 0x32 ) ;
if ( ! V_32 )
return;
V_2 -> V_32 = V_32 ;
V_11 = F_3 ( V_10 , V_58 ) ;
V_11 &= ~ V_59 ;
V_11 |= ( V_32 -> V_36 << 2 ) ;
F_6 ( V_10 , V_58 , V_11 ) ;
F_11 ( V_10 , 1 ) ;
V_11 = F_3 ( V_10 , V_60 ) ;
V_11 &= ~ V_61 ;
V_11 |= V_32 -> V_37 ;
F_6 ( V_10 , V_60 ,
V_11 | V_62 ) ;
F_10 ( 20 ) ;
do {
F_9 ( 1000 , 2000 ) ;
F_28 ( V_7 , true ) ;
F_2 ( V_7 , & V_4 ,
V_60 ) ;
F_28 ( V_7 , false ) ;
} while ( ( V_3 ++ < 100 ) &&
( ( V_4 & V_62 ) ==
V_62 ) );
F_11 ( V_10 , 0 ) ;
}
static void F_29 ( struct V_9 * V_10 , int V_27 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
int V_63 = - 1 ;
if ( V_27 ) {
V_2 -> V_64 ++ ;
if ( V_2 -> V_64 == 1 )
V_63 = F_12 (
V_65 ) ;
} else {
V_2 -> V_64 -- ;
if ( ! V_2 -> V_64 )
V_63 = F_13 (
V_65 ) ;
}
}
static void F_30 ( struct V_9 * V_10 , int V_11 , int V_66 )
{
unsigned char V_67 ;
V_67 = F_3 ( V_10 , V_11 ) ;
if ( V_66 ) {
V_67 |= V_68 ;
F_6 ( V_10 , V_11 , V_67 ) ;
F_14 ( 10 ) ;
V_67 |= V_69 ;
F_6 ( V_10 , V_11 , V_67 ) ;
F_14 ( 40 ) ;
V_67 |= V_70 ;
V_67 |= V_71 ;
F_6 ( V_10 , V_11 , V_67 ) ;
} else {
V_67 &= ~ V_70 ;
V_67 &= ~ V_71 ;
F_6 ( V_10 , V_11 , V_67 ) ;
V_67 &= ~ V_69 ;
F_6 ( V_10 , V_11 , V_67 ) ;
F_14 ( 40 ) ;
V_67 &= ~ V_68 ;
F_6 ( V_10 , V_11 , V_67 ) ;
}
}
static int F_31 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
switch ( V_76 ) {
case V_77 :
F_30 ( V_73 -> V_10 , V_78 , 1 ) ;
break;
case V_79 :
F_30 ( V_73 -> V_10 , V_78 , 0 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
switch ( V_76 ) {
case V_77 :
F_30 ( V_73 -> V_10 , V_80 , 1 ) ;
break;
case V_79 :
F_30 ( V_73 -> V_10 , V_80 , 0 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
F_6 ( V_73 -> V_10 , V_81 , 0xff ) ;
return 0 ;
}
static int F_34 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
switch ( V_76 ) {
case V_82 :
F_29 ( V_73 -> V_10 , 1 ) ;
break;
case V_79 :
F_29 ( V_73 -> V_10 , 0 ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
T_1 V_83 ;
V_83 = F_3 ( V_73 -> V_10 , V_84 ) ;
switch ( V_76 ) {
case V_82 :
F_29 ( V_73 -> V_10 , 1 ) ;
F_6 ( V_73 -> V_10 , V_84 ,
V_83 | V_85 ) ;
break;
case V_79 :
F_6 ( V_73 -> V_10 , V_84 ,
V_83 & ~ V_85 ) ;
F_29 ( V_73 -> V_10 , 0 ) ;
break;
}
return 0 ;
}
static void F_36 ( struct V_9 * V_10 , int V_66 )
{
unsigned char V_86 , V_87 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
unsigned int V_88 [] = { 524288 , 1048576 , 2097152 , 4194304 ,
8388608 , 16777216 , 33554432 , 67108864 } ;
unsigned int V_89 ;
V_86 = F_3 ( V_10 , V_18 ) ;
V_87 = F_3 ( V_10 , V_58 ) ;
V_89 = ( V_88 [ ( V_87 & V_59 ) >> 2 ] /
V_2 -> V_90 ) + 1 ;
if ( V_32 && V_32 -> V_38 ) {
if ( F_18 ( V_32 -> V_39 ) ) {
F_37 ( V_32 -> V_39 , 1 ) ;
} else {
V_87 |= V_91 ;
F_6 ( V_10 , V_58 , V_87 ) ;
}
}
if ( V_66 ) {
V_87 |= V_92 ;
F_6 ( V_10 , V_58 , V_87 ) ;
F_7 ( V_7 , V_86 ,
V_18 ) ;
V_87 |= V_93 ;
F_6 ( V_10 , V_58 , V_87 ) ;
F_8 ( V_89 ) ;
} else {
V_87 &= ~ V_93 ;
F_6 ( V_10 , V_58 , V_87 ) ;
F_8 ( V_89 ) ;
F_7 ( V_7 , V_86 & ( ~ 0x0f ) ,
V_18 ) ;
V_87 &= ~ V_92 ;
F_6 ( V_10 , V_58 , V_87 ) ;
}
if ( V_32 && V_32 -> V_38 ) {
if ( F_18 ( V_32 -> V_39 ) ) {
F_37 ( V_32 -> V_39 , 0 ) ;
} else {
V_87 &= ~ V_91 ;
F_6 ( V_10 , V_58 , V_87 ) ;
}
}
}
static int F_38 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
struct V_1 * V_2 = F_4 ( V_73 -> V_10 ) ;
switch ( V_76 ) {
case V_77 :
if ( ! V_2 -> V_26 )
F_36 ( V_73 -> V_10 , 1 ) ;
V_2 -> V_25 = 1 ;
break;
case V_79 :
if ( ! V_2 -> V_26 )
F_36 ( V_73 -> V_10 , 0 ) ;
V_2 -> V_25 = 0 ;
break;
}
return 0 ;
}
static int F_39 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
struct V_1 * V_2 = F_4 ( V_73 -> V_10 ) ;
switch ( V_76 ) {
case V_77 :
if ( ! V_2 -> V_25 )
F_36 ( V_73 -> V_10 , 1 ) ;
V_2 -> V_26 = 1 ;
break;
case V_79 :
if ( ! V_2 -> V_25 )
F_36 ( V_73 -> V_10 , 0 ) ;
V_2 -> V_26 = 0 ;
break;
}
return 0 ;
}
static int F_40 ( struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
struct V_1 * V_2 = F_4 ( V_73 -> V_10 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
if ( V_32 && V_32 -> V_35 )
F_8 ( V_32 -> V_35 ) ;
return 0 ;
}
static int F_41 ( struct V_74 * V_75 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_75 -> V_98 ;
struct V_9 * V_10 = F_42 ( V_75 ) ;
unsigned int V_11 = V_97 -> V_11 ;
unsigned int V_99 = V_97 -> V_99 ;
unsigned int V_100 = V_97 -> V_100 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_43 ( V_101 ) ) - 1 ;
V_95 -> V_12 . integer . V_12 [ 0 ] =
( F_44 ( V_10 , V_11 ) >> V_99 ) & V_102 ;
if ( V_95 -> V_12 . integer . V_12 [ 0 ] )
V_95 -> V_12 . integer . V_12 [ 0 ] =
V_101 + 1 - V_95 -> V_12 . integer . V_12 [ 0 ] ;
if ( V_99 != V_100 ) {
V_95 -> V_12 . integer . V_12 [ 1 ] =
( F_44 ( V_10 , V_11 ) >> V_100 ) & V_102 ;
if ( V_95 -> V_12 . integer . V_12 [ 1 ] )
V_95 -> V_12 . integer . V_12 [ 1 ] =
V_101 + 1 - V_95 -> V_12 . integer . V_12 [ 1 ] ;
}
return 0 ;
}
static int F_45 ( struct V_74 * V_75 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_75 -> V_98 ;
struct V_9 * V_10 = F_42 ( V_75 ) ;
unsigned int V_11 = V_97 -> V_11 ;
unsigned int V_99 = V_97 -> V_99 ;
unsigned int V_100 = V_97 -> V_100 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_43 ( V_101 ) ) - 1 ;
unsigned short V_103 , V_104 , V_105 ;
V_103 = ( V_95 -> V_12 . integer . V_12 [ 0 ] & V_102 ) ;
V_105 = V_102 << V_99 ;
if ( V_103 )
V_103 = V_101 + 1 - V_103 ;
V_103 = V_103 << V_99 ;
if ( V_99 != V_100 ) {
V_104 = ( V_95 -> V_12 . integer . V_12 [ 1 ] & V_102 ) ;
V_105 |= V_102 << V_100 ;
if ( V_104 )
V_104 = V_101 + 1 - V_104 ;
V_103 |= V_104 << V_100 ;
}
return F_46 ( V_10 , V_11 , V_105 , V_103 ) ;
}
static int F_47 ( struct V_74 * V_75 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_75 -> V_98 ;
struct V_9 * V_10 = F_42 ( V_75 ) ;
unsigned int V_11 = V_97 -> V_11 ;
unsigned int V_106 = V_97 -> V_107 ;
unsigned int V_99 = V_97 -> V_99 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_43 ( V_101 ) ) - 1 ;
V_95 -> V_12 . integer . V_12 [ 0 ] =
( F_44 ( V_10 , V_11 ) >> V_99 ) & V_102 ;
V_95 -> V_12 . integer . V_12 [ 1 ] =
( F_44 ( V_10 , V_106 ) >> V_99 ) & V_102 ;
if ( V_95 -> V_12 . integer . V_12 [ 0 ] )
V_95 -> V_12 . integer . V_12 [ 0 ] =
V_101 + 1 - V_95 -> V_12 . integer . V_12 [ 0 ] ;
if ( V_95 -> V_12 . integer . V_12 [ 1 ] )
V_95 -> V_12 . integer . V_12 [ 1 ] =
V_101 + 1 - V_95 -> V_12 . integer . V_12 [ 1 ] ;
return 0 ;
}
static int F_48 ( struct V_74 * V_75 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_75 -> V_98 ;
struct V_9 * V_10 = F_42 ( V_75 ) ;
unsigned int V_11 = V_97 -> V_11 ;
unsigned int V_106 = V_97 -> V_107 ;
unsigned int V_99 = V_97 -> V_99 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_43 ( V_101 ) ) - 1 ;
int V_108 ;
unsigned short V_103 , V_104 , V_105 ;
V_105 = V_102 << V_99 ;
V_103 = ( V_95 -> V_12 . integer . V_12 [ 0 ] & V_102 ) ;
V_104 = ( V_95 -> V_12 . integer . V_12 [ 1 ] & V_102 ) ;
if ( V_103 )
V_103 = V_101 + 1 - V_103 ;
if ( V_104 )
V_104 = V_101 + 1 - V_104 ;
V_103 = V_103 << V_99 ;
V_104 = V_104 << V_99 ;
V_108 = F_46 ( V_10 , V_11 , V_105 , V_103 ) ;
if ( V_108 < 0 )
return V_108 ;
V_108 = F_46 ( V_10 , V_106 , V_105 , V_104 ) ;
return V_108 ;
}
static int F_49 ( struct V_74 * V_75 ,
struct V_94 * V_95 )
{
struct V_9 * V_10 = F_42 ( V_75 ) ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_109 * V_110 = (struct V_109 * ) V_75 -> V_98 ;
unsigned short V_103 ;
unsigned short V_102 ;
if ( V_2 -> V_111 ) {
F_23 ( V_10 -> V_40 ,
L_11 ) ;
return - V_112 ;
}
if ( V_95 -> V_12 . V_113 . V_114 [ 0 ] > V_110 -> V_101 - 1 )
return - V_115 ;
V_103 = V_95 -> V_12 . V_113 . V_114 [ 0 ] << V_110 -> V_116 ;
V_102 = V_110 -> V_102 << V_110 -> V_116 ;
if ( V_110 -> V_116 != V_110 -> V_117 ) {
if ( V_95 -> V_12 . V_113 . V_114 [ 1 ] > V_110 -> V_101 - 1 )
return - V_115 ;
V_103 |= V_95 -> V_12 . V_113 . V_114 [ 1 ] << V_110 -> V_117 ;
V_102 |= V_110 -> V_102 << V_110 -> V_117 ;
}
return F_46 ( V_10 , V_110 -> V_11 , V_102 , V_103 ) ;
}
static int F_50 ( struct V_9 * V_10 ,
enum V_118 V_119 )
{
switch ( V_119 ) {
case V_120 :
break;
case V_121 :
break;
case V_122 :
if ( V_10 -> V_123 . V_124 == V_125 )
F_11 ( V_10 , 1 ) ;
break;
case V_125 :
F_11 ( V_10 , 0 ) ;
break;
}
V_10 -> V_123 . V_124 = V_119 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
struct V_126 * V_128 ;
if ( V_127 == V_2 -> V_129 )
V_128 = V_2 -> V_130 ;
else if ( V_127 == V_2 -> V_130 )
V_128 = V_2 -> V_129 ;
else
return;
F_52 ( V_128 -> V_131 ,
V_132 ,
V_2 -> V_133 ,
V_2 -> V_133 ) ;
F_52 ( V_128 -> V_131 ,
V_134 ,
V_2 -> V_135 ,
V_2 -> V_135 ) ;
F_52 ( V_128 -> V_131 ,
V_136 ,
V_2 -> V_137 ,
V_2 -> V_137 ) ;
}
static void F_53 ( struct V_9 * V_10 , int V_138 ,
int V_27 )
{
T_1 V_11 , V_102 ;
V_11 = F_3 ( V_10 , V_52 ) ;
if ( V_138 == V_139 )
V_102 = V_140 | V_141 ;
else
V_102 = V_142 | V_143 ;
if ( V_27 )
V_11 |= V_102 ;
else
V_11 &= ~ V_102 ;
F_6 ( V_10 , V_52 , V_11 ) ;
}
static int F_54 ( struct V_126 * V_144 ,
struct V_145 * V_146 )
{
struct V_9 * V_10 = V_146 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_129 ) {
V_2 -> V_130 = V_144 ;
if ( V_2 -> V_111 )
F_51 ( V_2 , V_2 -> V_129 ) ;
} else {
if ( ! ( F_3 ( V_10 , V_147 ) &
V_148 ) ) {
F_52 ( V_144 -> V_131 ,
V_136 ,
2 , 2 ) ;
}
V_2 -> V_129 = V_144 ;
}
return 0 ;
}
static void F_55 ( struct V_126 * V_144 ,
struct V_145 * V_146 )
{
struct V_9 * V_10 = V_146 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_129 == V_144 )
V_2 -> V_129 = V_2 -> V_130 ;
V_2 -> V_130 = NULL ;
if ( ! V_2 -> V_129 )
V_2 -> V_111 = 0 ;
else if ( ! V_2 -> V_129 -> V_131 -> V_137 )
V_2 -> V_111 = 0 ;
if ( V_144 -> V_131 -> V_137 == 4 )
F_53 ( V_10 , V_144 -> V_149 , 0 ) ;
}
static int F_56 ( struct V_126 * V_144 ,
struct V_150 * V_151 ,
struct V_145 * V_146 )
{
struct V_9 * V_10 = V_146 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_28 , V_152 , V_153 , V_154 ;
if ( F_57 ( V_151 ) == 4 ) {
V_153 = F_3 ( V_10 , V_84 ) ;
V_28 = F_3 ( V_10 , V_147 ) ;
if ( ( V_28 & V_148 ) &&
( ( V_153 & V_155 ) == V_156 ) )
F_53 ( V_10 , V_144 -> V_149 , 1 ) ;
else
return - V_115 ;
}
if ( V_2 -> V_111 )
return 0 ;
V_152 = F_3 ( V_10 ,
V_147 ) & ~ V_157 ;
V_28 = V_152 & ~ V_158 ;
switch ( F_58 ( V_151 ) ) {
case 8000 :
V_28 |= V_159 ;
break;
case 11025 :
V_28 |= V_160 ;
break;
case 12000 :
V_28 |= V_161 ;
break;
case 16000 :
V_28 |= V_162 ;
break;
case 22050 :
V_28 |= V_163 ;
break;
case 24000 :
V_28 |= V_164 ;
break;
case 32000 :
V_28 |= V_165 ;
break;
case 44100 :
V_28 |= V_166 ;
break;
case 48000 :
V_28 |= V_167 ;
break;
case 96000 :
V_28 |= V_168 ;
break;
default:
F_23 ( V_10 -> V_40 , L_12 , V_169 ,
F_58 ( V_151 ) ) ;
return - V_115 ;
}
V_154 = F_3 ( V_10 , V_84 ) ;
V_153 = V_154 ;
V_153 &= ~ V_170 ;
switch ( F_59 ( V_151 ) ) {
case V_171 :
V_153 |= V_172 ;
break;
case V_173 :
V_153 |= V_174 ;
break;
default:
F_23 ( V_10 -> V_40 , L_13 , V_169 ,
F_59 ( V_151 ) ) ;
return - V_115 ;
}
if ( V_153 != V_154 || V_28 != V_152 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_147 , V_28 ) ;
F_6 ( V_10 , V_84 , V_153 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_147 , V_28 ) ;
F_6 ( V_10 , V_84 , V_153 ) ;
}
}
V_2 -> V_111 = 1 ;
V_2 -> V_133 = F_58 ( V_151 ) ;
V_2 -> V_135 = F_60 ( V_151 ,
V_134 ) -> V_175 ;
V_2 -> V_137 = F_57 ( V_151 ) ;
if ( V_2 -> V_130 )
F_51 ( V_2 , V_144 ) ;
return 0 ;
}
static int F_61 ( struct V_145 * V_176 , int V_177 ,
unsigned int V_178 , int V_179 )
{
struct V_9 * V_10 = V_176 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
switch ( V_178 ) {
case 19200000 :
case 26000000 :
case 38400000 :
break;
default:
F_23 ( V_10 -> V_40 , L_14 , V_178 ) ;
return - V_115 ;
}
if ( ( V_178 / 1000 ) != V_2 -> V_90 ) {
F_23 ( V_10 -> V_40 ,
L_15 ,
V_178 , V_2 -> V_90 * 1000 ) ;
return - V_115 ;
}
return 0 ;
}
static int F_62 ( struct V_145 * V_176 , unsigned int V_180 )
{
struct V_9 * V_10 = V_176 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_154 , V_153 ;
V_154 = F_3 ( V_10 , V_84 ) ;
V_153 = V_154 ;
switch ( V_180 & V_181 ) {
case V_182 :
V_153 &= ~ ( V_183 ) ;
V_153 &= ~ ( V_184 ) ;
break;
case V_185 :
V_153 |= V_183 ;
V_153 |= V_184 ;
break;
default:
return - V_115 ;
}
V_153 &= ~ V_155 ;
switch ( V_180 & V_186 ) {
case V_187 :
V_153 |= V_188 ;
break;
case V_189 :
V_153 |= V_156 ;
break;
default:
return - V_115 ;
}
if ( V_153 != V_154 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_84 , V_153 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_84 , V_153 ) ;
}
}
return 0 ;
}
static int F_63 ( struct V_145 * V_146 , int V_190 )
{
struct V_9 * V_10 = V_146 -> V_10 ;
T_1 V_11 = F_3 ( V_10 , V_84 ) ;
if ( V_190 )
V_11 |= V_191 ;
else
V_11 &= ~ V_191 ;
return F_6 ( V_10 , V_84 , V_11 ) ;
}
static void F_64 ( struct V_9 * V_10 , int V_138 ,
int V_27 )
{
T_1 V_11 , V_102 ;
V_11 = F_3 ( V_10 , V_52 ) ;
if ( V_138 == V_139 )
V_102 = V_140 ;
else
V_102 = V_142 | V_143 ;
if ( V_27 )
V_11 |= V_102 ;
else
V_11 &= ~ V_102 ;
F_6 ( V_10 , V_52 , V_11 ) ;
}
static int F_65 ( struct V_126 * V_144 ,
struct V_145 * V_146 )
{
struct V_9 * V_10 = V_146 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_28 ;
if ( V_2 -> V_90 != 26000 ) {
F_23 ( V_10 -> V_40 ,
L_16 ,
V_169 , V_2 -> V_90 ) ;
return - V_115 ;
}
V_28 = F_3 ( V_10 , V_147 )
& V_192 ;
if ( V_28 != V_193 ) {
F_23 ( V_10 -> V_40 , L_17 ,
V_169 ) ;
return - V_115 ;
}
return 0 ;
}
static void F_66 ( struct V_126 * V_144 ,
struct V_145 * V_146 )
{
struct V_9 * V_10 = V_146 -> V_10 ;
F_64 ( V_10 , V_144 -> V_149 , 0 ) ;
}
static int F_67 ( struct V_126 * V_144 ,
struct V_150 * V_151 ,
struct V_145 * V_146 )
{
struct V_9 * V_10 = V_146 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_152 , V_28 ;
F_64 ( V_10 , V_144 -> V_149 , 1 ) ;
V_152 = F_3 ( V_10 ,
V_147 ) & ~ V_157 ;
V_28 = V_152 ;
switch ( F_58 ( V_151 ) ) {
case 8000 :
V_28 &= ~ ( V_194 ) ;
break;
case 16000 :
V_28 |= V_194 ;
break;
default:
F_23 ( V_10 -> V_40 , L_12 , V_169 ,
F_58 ( V_151 ) ) ;
return - V_115 ;
}
if ( V_28 != V_152 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_147 , V_28 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_147 , V_28 ) ;
}
}
return 0 ;
}
static int F_68 ( struct V_145 * V_176 ,
int V_177 , unsigned int V_178 , int V_179 )
{
struct V_9 * V_10 = V_176 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_178 != 26000000 ) {
F_23 ( V_10 -> V_40 ,
L_16 ,
V_169 , V_178 / 1000 ) ;
return - V_115 ;
}
if ( ( V_178 / 1000 ) != V_2 -> V_90 ) {
F_23 ( V_10 -> V_40 ,
L_15 ,
V_178 , V_2 -> V_90 * 1000 ) ;
return - V_115 ;
}
return 0 ;
}
static int F_69 ( struct V_145 * V_176 ,
unsigned int V_180 )
{
struct V_9 * V_10 = V_176 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_154 , V_153 ;
V_154 = F_3 ( V_10 , V_195 ) ;
V_153 = V_154 ;
switch ( V_180 & V_181 ) {
case V_182 :
V_153 &= ~ ( V_196 ) ;
break;
case V_185 :
V_153 |= V_196 ;
break;
default:
return - V_115 ;
}
switch ( V_180 & V_197 ) {
case V_198 :
V_153 &= ~ ( V_199 ) ;
break;
case V_200 :
V_153 |= V_199 ;
break;
default:
return - V_115 ;
}
if ( V_153 != V_154 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_195 , V_153 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_195 , V_153 ) ;
}
}
return 0 ;
}
static int F_70 ( struct V_145 * V_146 , int V_190 )
{
struct V_9 * V_10 = V_146 -> V_10 ;
T_1 V_11 = F_3 ( V_10 , V_195 ) ;
if ( V_190 )
V_11 |= V_201 ;
else
V_11 &= ~ V_201 ;
return F_6 ( V_10 , V_195 , V_11 ) ;
}
static int F_71 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_10 -> V_40 , sizeof( struct V_1 ) ,
V_44 ) ;
if ( V_2 == NULL ) {
F_23 ( V_10 -> V_40 , L_7 ) ;
return - V_202 ;
}
F_72 ( V_10 , V_2 ) ;
V_2 -> V_90 = F_73 () / 1000 ;
F_24 ( V_10 ) ;
return 0 ;
}
static int F_74 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
F_50 ( V_10 , V_125 ) ;
if ( V_32 && V_32 -> V_38 && F_18 ( V_32 -> V_39 ) )
F_75 ( V_32 -> V_39 ) ;
return 0 ;
}
static int F_76 ( struct V_203 * V_204 )
{
return F_77 ( & V_204 -> V_40 , & V_205 ,
V_206 , F_78 ( V_206 ) ) ;
}
static int F_79 ( struct V_203 * V_204 )
{
F_80 ( & V_204 -> V_40 ) ;
return 0 ;
}
