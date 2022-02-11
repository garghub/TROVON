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
if ( V_27 ) {
V_2 -> V_63 ++ ;
if ( V_2 -> V_63 == 1 )
F_12 (
V_64 ) ;
} else {
V_2 -> V_63 -- ;
if ( ! V_2 -> V_63 )
F_13 (
V_64 ) ;
}
}
static void F_30 ( struct V_9 * V_10 , int V_11 , int V_65 )
{
unsigned char V_66 ;
V_66 = F_3 ( V_10 , V_11 ) ;
if ( V_65 ) {
V_66 |= V_67 ;
F_6 ( V_10 , V_11 , V_66 ) ;
F_14 ( 10 ) ;
V_66 |= V_68 ;
F_6 ( V_10 , V_11 , V_66 ) ;
F_14 ( 40 ) ;
V_66 |= V_69 ;
V_66 |= V_70 ;
F_6 ( V_10 , V_11 , V_66 ) ;
} else {
V_66 &= ~ V_69 ;
V_66 &= ~ V_70 ;
F_6 ( V_10 , V_11 , V_66 ) ;
V_66 &= ~ V_68 ;
F_6 ( V_10 , V_11 , V_66 ) ;
F_14 ( 40 ) ;
V_66 &= ~ V_67 ;
F_6 ( V_10 , V_11 , V_66 ) ;
}
}
static int F_31 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
switch ( V_75 ) {
case V_76 :
F_30 ( V_72 -> V_10 , V_77 , 1 ) ;
break;
case V_78 :
F_30 ( V_72 -> V_10 , V_77 , 0 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
switch ( V_75 ) {
case V_76 :
F_30 ( V_72 -> V_10 , V_79 , 1 ) ;
break;
case V_78 :
F_30 ( V_72 -> V_10 , V_79 , 0 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
F_6 ( V_72 -> V_10 , V_80 , 0xff ) ;
return 0 ;
}
static int F_34 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
switch ( V_75 ) {
case V_81 :
F_29 ( V_72 -> V_10 , 1 ) ;
break;
case V_78 :
F_29 ( V_72 -> V_10 , 0 ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
T_1 V_82 ;
V_82 = F_3 ( V_72 -> V_10 , V_83 ) ;
switch ( V_75 ) {
case V_81 :
F_29 ( V_72 -> V_10 , 1 ) ;
F_6 ( V_72 -> V_10 , V_83 ,
V_82 | V_84 ) ;
break;
case V_78 :
F_6 ( V_72 -> V_10 , V_83 ,
V_82 & ~ V_84 ) ;
F_29 ( V_72 -> V_10 , 0 ) ;
break;
}
return 0 ;
}
static void F_36 ( struct V_9 * V_10 , int V_65 )
{
unsigned char V_85 , V_86 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
unsigned int V_87 [] = { 524288 , 1048576 , 2097152 , 4194304 ,
8388608 , 16777216 , 33554432 , 67108864 } ;
unsigned int V_88 ;
V_85 = F_3 ( V_10 , V_18 ) ;
V_86 = F_3 ( V_10 , V_58 ) ;
V_88 = ( V_87 [ ( V_86 & V_59 ) >> 2 ] /
V_2 -> V_89 ) + 1 ;
if ( V_32 && V_32 -> V_38 ) {
if ( F_18 ( V_32 -> V_39 ) ) {
F_37 ( V_32 -> V_39 , 1 ) ;
} else {
V_86 |= V_90 ;
F_6 ( V_10 , V_58 , V_86 ) ;
}
}
if ( V_65 ) {
V_86 |= V_91 ;
F_6 ( V_10 , V_58 , V_86 ) ;
F_7 ( V_7 , V_85 ,
V_18 ) ;
V_86 |= V_92 ;
F_6 ( V_10 , V_58 , V_86 ) ;
F_8 ( V_88 ) ;
} else {
V_86 &= ~ V_92 ;
F_6 ( V_10 , V_58 , V_86 ) ;
F_8 ( V_88 ) ;
F_7 ( V_7 , V_85 & ( ~ 0x0f ) ,
V_18 ) ;
V_86 &= ~ V_91 ;
F_6 ( V_10 , V_58 , V_86 ) ;
}
if ( V_32 && V_32 -> V_38 ) {
if ( F_18 ( V_32 -> V_39 ) ) {
F_37 ( V_32 -> V_39 , 0 ) ;
} else {
V_86 &= ~ V_90 ;
F_6 ( V_10 , V_58 , V_86 ) ;
}
}
}
static int F_38 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_1 * V_2 = F_4 ( V_72 -> V_10 ) ;
switch ( V_75 ) {
case V_76 :
if ( ! V_2 -> V_26 )
F_36 ( V_72 -> V_10 , 1 ) ;
V_2 -> V_25 = 1 ;
break;
case V_78 :
if ( ! V_2 -> V_26 )
F_36 ( V_72 -> V_10 , 0 ) ;
V_2 -> V_25 = 0 ;
break;
}
return 0 ;
}
static int F_39 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_1 * V_2 = F_4 ( V_72 -> V_10 ) ;
switch ( V_75 ) {
case V_76 :
if ( ! V_2 -> V_25 )
F_36 ( V_72 -> V_10 , 1 ) ;
V_2 -> V_26 = 1 ;
break;
case V_78 :
if ( ! V_2 -> V_25 )
F_36 ( V_72 -> V_10 , 0 ) ;
V_2 -> V_26 = 0 ;
break;
}
return 0 ;
}
static int F_40 ( struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_1 * V_2 = F_4 ( V_72 -> V_10 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
if ( V_32 && V_32 -> V_35 )
F_8 ( V_32 -> V_35 ) ;
return 0 ;
}
static int F_41 ( struct V_73 * V_74 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 =
(struct V_95 * ) V_74 -> V_97 ;
struct V_9 * V_10 = F_42 ( V_74 ) ;
unsigned int V_11 = V_96 -> V_11 ;
unsigned int V_98 = V_96 -> V_98 ;
unsigned int V_99 = V_96 -> V_99 ;
int V_100 = V_96 -> V_100 ;
int V_101 = ( 1 << F_43 ( V_100 ) ) - 1 ;
V_94 -> V_12 . integer . V_12 [ 0 ] =
( F_44 ( V_10 , V_11 ) >> V_98 ) & V_101 ;
if ( V_94 -> V_12 . integer . V_12 [ 0 ] )
V_94 -> V_12 . integer . V_12 [ 0 ] =
V_100 + 1 - V_94 -> V_12 . integer . V_12 [ 0 ] ;
if ( V_98 != V_99 ) {
V_94 -> V_12 . integer . V_12 [ 1 ] =
( F_44 ( V_10 , V_11 ) >> V_99 ) & V_101 ;
if ( V_94 -> V_12 . integer . V_12 [ 1 ] )
V_94 -> V_12 . integer . V_12 [ 1 ] =
V_100 + 1 - V_94 -> V_12 . integer . V_12 [ 1 ] ;
}
return 0 ;
}
static int F_45 ( struct V_73 * V_74 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 =
(struct V_95 * ) V_74 -> V_97 ;
struct V_9 * V_10 = F_42 ( V_74 ) ;
unsigned int V_11 = V_96 -> V_11 ;
unsigned int V_98 = V_96 -> V_98 ;
unsigned int V_99 = V_96 -> V_99 ;
int V_100 = V_96 -> V_100 ;
int V_101 = ( 1 << F_43 ( V_100 ) ) - 1 ;
unsigned short V_102 , V_103 , V_104 ;
V_102 = ( V_94 -> V_12 . integer . V_12 [ 0 ] & V_101 ) ;
V_104 = V_101 << V_98 ;
if ( V_102 )
V_102 = V_100 + 1 - V_102 ;
V_102 = V_102 << V_98 ;
if ( V_98 != V_99 ) {
V_103 = ( V_94 -> V_12 . integer . V_12 [ 1 ] & V_101 ) ;
V_104 |= V_101 << V_99 ;
if ( V_103 )
V_103 = V_100 + 1 - V_103 ;
V_102 |= V_103 << V_99 ;
}
return F_46 ( V_10 , V_11 , V_104 , V_102 ) ;
}
static int F_47 ( struct V_73 * V_74 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 =
(struct V_95 * ) V_74 -> V_97 ;
struct V_9 * V_10 = F_42 ( V_74 ) ;
unsigned int V_11 = V_96 -> V_11 ;
unsigned int V_105 = V_96 -> V_106 ;
unsigned int V_98 = V_96 -> V_98 ;
int V_100 = V_96 -> V_100 ;
int V_101 = ( 1 << F_43 ( V_100 ) ) - 1 ;
V_94 -> V_12 . integer . V_12 [ 0 ] =
( F_44 ( V_10 , V_11 ) >> V_98 ) & V_101 ;
V_94 -> V_12 . integer . V_12 [ 1 ] =
( F_44 ( V_10 , V_105 ) >> V_98 ) & V_101 ;
if ( V_94 -> V_12 . integer . V_12 [ 0 ] )
V_94 -> V_12 . integer . V_12 [ 0 ] =
V_100 + 1 - V_94 -> V_12 . integer . V_12 [ 0 ] ;
if ( V_94 -> V_12 . integer . V_12 [ 1 ] )
V_94 -> V_12 . integer . V_12 [ 1 ] =
V_100 + 1 - V_94 -> V_12 . integer . V_12 [ 1 ] ;
return 0 ;
}
static int F_48 ( struct V_73 * V_74 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 =
(struct V_95 * ) V_74 -> V_97 ;
struct V_9 * V_10 = F_42 ( V_74 ) ;
unsigned int V_11 = V_96 -> V_11 ;
unsigned int V_105 = V_96 -> V_106 ;
unsigned int V_98 = V_96 -> V_98 ;
int V_100 = V_96 -> V_100 ;
int V_101 = ( 1 << F_43 ( V_100 ) ) - 1 ;
int V_107 ;
unsigned short V_102 , V_103 , V_104 ;
V_104 = V_101 << V_98 ;
V_102 = ( V_94 -> V_12 . integer . V_12 [ 0 ] & V_101 ) ;
V_103 = ( V_94 -> V_12 . integer . V_12 [ 1 ] & V_101 ) ;
if ( V_102 )
V_102 = V_100 + 1 - V_102 ;
if ( V_103 )
V_103 = V_100 + 1 - V_103 ;
V_102 = V_102 << V_98 ;
V_103 = V_103 << V_98 ;
V_107 = F_46 ( V_10 , V_11 , V_104 , V_102 ) ;
if ( V_107 < 0 )
return V_107 ;
V_107 = F_46 ( V_10 , V_105 , V_104 , V_103 ) ;
return V_107 ;
}
static int F_49 ( struct V_73 * V_74 ,
struct V_93 * V_94 )
{
struct V_9 * V_10 = F_42 ( V_74 ) ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_108 ) {
F_23 ( V_10 -> V_40 ,
L_11 ) ;
return - V_109 ;
}
return F_50 ( V_74 , V_94 ) ;
}
static int F_51 ( struct V_9 * V_10 ,
enum V_110 V_111 )
{
switch ( V_111 ) {
case V_112 :
break;
case V_113 :
break;
case V_114 :
if ( V_10 -> V_115 . V_116 == V_117 )
F_11 ( V_10 , 1 ) ;
break;
case V_117 :
F_11 ( V_10 , 0 ) ;
break;
}
V_10 -> V_115 . V_116 = V_111 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_118 * V_120 ;
if ( V_119 == V_2 -> V_121 )
V_120 = V_2 -> V_122 ;
else if ( V_119 == V_2 -> V_122 )
V_120 = V_2 -> V_121 ;
else
return;
F_53 ( V_120 -> V_123 ,
V_124 ,
V_2 -> V_125 ,
V_2 -> V_125 ) ;
F_53 ( V_120 -> V_123 ,
V_126 ,
V_2 -> V_127 ,
V_2 -> V_127 ) ;
F_53 ( V_120 -> V_123 ,
V_128 ,
V_2 -> V_129 ,
V_2 -> V_129 ) ;
}
static void F_54 ( struct V_9 * V_10 , int V_130 ,
int V_27 )
{
T_1 V_11 , V_101 ;
V_11 = F_3 ( V_10 , V_52 ) ;
if ( V_130 == V_131 )
V_101 = V_132 | V_133 ;
else
V_101 = V_134 | V_135 ;
if ( V_27 )
V_11 |= V_101 ;
else
V_11 &= ~ V_101 ;
F_6 ( V_10 , V_52 , V_11 ) ;
}
static int F_55 ( struct V_118 * V_136 ,
struct V_137 * V_138 )
{
struct V_9 * V_10 = V_138 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_121 ) {
V_2 -> V_122 = V_136 ;
if ( V_2 -> V_108 )
F_52 ( V_2 , V_2 -> V_121 ) ;
} else {
if ( ! ( F_3 ( V_10 , V_139 ) &
V_140 ) ) {
F_53 ( V_136 -> V_123 ,
V_128 ,
2 , 2 ) ;
}
V_2 -> V_121 = V_136 ;
}
return 0 ;
}
static void F_56 ( struct V_118 * V_136 ,
struct V_137 * V_138 )
{
struct V_9 * V_10 = V_138 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_2 -> V_121 == V_136 )
V_2 -> V_121 = V_2 -> V_122 ;
V_2 -> V_122 = NULL ;
if ( ! V_2 -> V_121 )
V_2 -> V_108 = 0 ;
else if ( ! V_2 -> V_121 -> V_123 -> V_129 )
V_2 -> V_108 = 0 ;
if ( V_136 -> V_123 -> V_129 == 4 )
F_54 ( V_10 , V_136 -> V_141 , 0 ) ;
}
static int F_57 ( struct V_118 * V_136 ,
struct V_142 * V_143 ,
struct V_137 * V_138 )
{
struct V_9 * V_10 = V_138 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_28 , V_144 , V_145 , V_146 ;
if ( F_58 ( V_143 ) == 4 ) {
V_145 = F_3 ( V_10 , V_83 ) ;
V_28 = F_3 ( V_10 , V_139 ) ;
if ( ( V_28 & V_140 ) &&
( ( V_145 & V_147 ) == V_148 ) )
F_54 ( V_10 , V_136 -> V_141 , 1 ) ;
else
return - V_149 ;
}
if ( V_2 -> V_108 )
return 0 ;
V_144 = F_3 ( V_10 ,
V_139 ) & ~ V_150 ;
V_28 = V_144 & ~ V_151 ;
switch ( F_59 ( V_143 ) ) {
case 8000 :
V_28 |= V_152 ;
break;
case 11025 :
V_28 |= V_153 ;
break;
case 12000 :
V_28 |= V_154 ;
break;
case 16000 :
V_28 |= V_155 ;
break;
case 22050 :
V_28 |= V_156 ;
break;
case 24000 :
V_28 |= V_157 ;
break;
case 32000 :
V_28 |= V_158 ;
break;
case 44100 :
V_28 |= V_159 ;
break;
case 48000 :
V_28 |= V_160 ;
break;
case 96000 :
V_28 |= V_161 ;
break;
default:
F_23 ( V_10 -> V_40 , L_12 , V_162 ,
F_59 ( V_143 ) ) ;
return - V_149 ;
}
V_146 = F_3 ( V_10 , V_83 ) ;
V_145 = V_146 ;
V_145 &= ~ V_163 ;
switch ( F_60 ( V_143 ) ) {
case 16 :
V_145 |= V_164 ;
break;
case 32 :
V_145 |= V_165 ;
break;
default:
F_23 ( V_10 -> V_40 , L_13 ,
V_162 , F_60 ( V_143 ) ) ;
return - V_149 ;
}
if ( V_145 != V_146 || V_28 != V_144 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_139 , V_28 ) ;
F_6 ( V_10 , V_83 , V_145 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_139 , V_28 ) ;
F_6 ( V_10 , V_83 , V_145 ) ;
}
}
V_2 -> V_108 = 1 ;
V_2 -> V_125 = F_59 ( V_143 ) ;
V_2 -> V_127 = F_61 ( V_143 ,
V_126 ) -> V_166 ;
V_2 -> V_129 = F_58 ( V_143 ) ;
if ( V_2 -> V_122 )
F_52 ( V_2 , V_136 ) ;
return 0 ;
}
static int F_62 ( struct V_137 * V_167 , int V_168 ,
unsigned int V_169 , int V_170 )
{
struct V_9 * V_10 = V_167 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
switch ( V_169 ) {
case 19200000 :
case 26000000 :
case 38400000 :
break;
default:
F_23 ( V_10 -> V_40 , L_14 , V_169 ) ;
return - V_149 ;
}
if ( ( V_169 / 1000 ) != V_2 -> V_89 ) {
F_23 ( V_10 -> V_40 ,
L_15 ,
V_169 , V_2 -> V_89 * 1000 ) ;
return - V_149 ;
}
return 0 ;
}
static int F_63 ( struct V_137 * V_167 , unsigned int V_171 )
{
struct V_9 * V_10 = V_167 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_146 , V_145 ;
V_146 = F_3 ( V_10 , V_83 ) ;
V_145 = V_146 ;
switch ( V_171 & V_172 ) {
case V_173 :
V_145 &= ~ ( V_174 ) ;
V_145 &= ~ ( V_175 ) ;
break;
case V_176 :
V_145 |= V_174 ;
V_145 |= V_175 ;
break;
default:
return - V_149 ;
}
V_145 &= ~ V_147 ;
switch ( V_171 & V_177 ) {
case V_178 :
V_145 |= V_179 ;
break;
case V_180 :
V_145 |= V_148 ;
break;
default:
return - V_149 ;
}
if ( V_145 != V_146 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_83 , V_145 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_83 , V_145 ) ;
}
}
return 0 ;
}
static int F_64 ( struct V_137 * V_138 , int V_181 )
{
struct V_9 * V_10 = V_138 -> V_10 ;
T_1 V_11 = F_3 ( V_10 , V_83 ) ;
if ( V_181 )
V_11 |= V_182 ;
else
V_11 &= ~ V_182 ;
return F_6 ( V_10 , V_83 , V_11 ) ;
}
static void F_65 ( struct V_9 * V_10 , int V_130 ,
int V_27 )
{
T_1 V_11 , V_101 ;
V_11 = F_3 ( V_10 , V_52 ) ;
if ( V_130 == V_131 )
V_101 = V_132 ;
else
V_101 = V_134 | V_135 ;
if ( V_27 )
V_11 |= V_101 ;
else
V_11 &= ~ V_101 ;
F_6 ( V_10 , V_52 , V_11 ) ;
}
static int F_66 ( struct V_118 * V_136 ,
struct V_137 * V_138 )
{
struct V_9 * V_10 = V_138 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_28 ;
if ( V_2 -> V_89 != 26000 ) {
F_23 ( V_10 -> V_40 ,
L_16 ,
V_162 , V_2 -> V_89 ) ;
return - V_149 ;
}
V_28 = F_3 ( V_10 , V_139 )
& V_183 ;
if ( V_28 != V_184 ) {
F_23 ( V_10 -> V_40 , L_17 ,
V_162 ) ;
return - V_149 ;
}
return 0 ;
}
static void F_67 ( struct V_118 * V_136 ,
struct V_137 * V_138 )
{
struct V_9 * V_10 = V_138 -> V_10 ;
F_65 ( V_10 , V_136 -> V_141 , 0 ) ;
}
static int F_68 ( struct V_118 * V_136 ,
struct V_142 * V_143 ,
struct V_137 * V_138 )
{
struct V_9 * V_10 = V_138 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_144 , V_28 ;
F_65 ( V_10 , V_136 -> V_141 , 1 ) ;
V_144 = F_3 ( V_10 ,
V_139 ) & ~ V_150 ;
V_28 = V_144 ;
switch ( F_59 ( V_143 ) ) {
case 8000 :
V_28 &= ~ ( V_185 ) ;
break;
case 16000 :
V_28 |= V_185 ;
break;
default:
F_23 ( V_10 -> V_40 , L_12 , V_162 ,
F_59 ( V_143 ) ) ;
return - V_149 ;
}
if ( V_28 != V_144 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_139 , V_28 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_139 , V_28 ) ;
}
}
return 0 ;
}
static int F_69 ( struct V_137 * V_167 ,
int V_168 , unsigned int V_169 , int V_170 )
{
struct V_9 * V_10 = V_167 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_169 != 26000000 ) {
F_23 ( V_10 -> V_40 ,
L_16 ,
V_162 , V_169 / 1000 ) ;
return - V_149 ;
}
if ( ( V_169 / 1000 ) != V_2 -> V_89 ) {
F_23 ( V_10 -> V_40 ,
L_15 ,
V_169 , V_2 -> V_89 * 1000 ) ;
return - V_149 ;
}
return 0 ;
}
static int F_70 ( struct V_137 * V_167 ,
unsigned int V_171 )
{
struct V_9 * V_10 = V_167 -> V_10 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
T_1 V_146 , V_145 ;
V_146 = F_3 ( V_10 , V_186 ) ;
V_145 = V_146 ;
switch ( V_171 & V_172 ) {
case V_173 :
V_145 &= ~ ( V_187 ) ;
break;
case V_176 :
V_145 |= V_187 ;
break;
default:
return - V_149 ;
}
switch ( V_171 & V_188 ) {
case V_189 :
V_145 &= ~ ( V_190 ) ;
break;
case V_191 :
V_145 |= V_190 ;
break;
default:
return - V_149 ;
}
if ( V_145 != V_146 ) {
if ( V_2 -> V_29 ) {
F_11 ( V_10 , 0 ) ;
F_6 ( V_10 , V_186 , V_145 ) ;
F_11 ( V_10 , 1 ) ;
} else {
F_6 ( V_10 , V_186 , V_145 ) ;
}
}
return 0 ;
}
static int F_71 ( struct V_137 * V_138 , int V_181 )
{
struct V_9 * V_10 = V_138 -> V_10 ;
T_1 V_11 = F_3 ( V_10 , V_186 ) ;
if ( V_181 )
V_11 |= V_192 ;
else
V_11 &= ~ V_192 ;
return F_6 ( V_10 , V_186 , V_11 ) ;
}
static int F_72 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_10 -> V_40 , sizeof( struct V_1 ) ,
V_44 ) ;
if ( ! V_2 )
return - V_193 ;
F_73 ( V_10 , V_2 ) ;
V_2 -> V_89 = F_74 () / 1000 ;
F_24 ( V_10 ) ;
return 0 ;
}
static int F_75 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_31 * V_32 = V_2 -> V_32 ;
F_51 ( V_10 , V_117 ) ;
if ( V_32 && V_32 -> V_38 && F_18 ( V_32 -> V_39 ) )
F_76 ( V_32 -> V_39 ) ;
return 0 ;
}
static int F_77 ( struct V_194 * V_195 )
{
return F_78 ( & V_195 -> V_40 , & V_196 ,
V_197 , F_79 ( V_197 ) ) ;
}
static int F_80 ( struct V_194 * V_195 )
{
F_81 ( & V_195 -> V_40 ) ;
return 0 ;
}
