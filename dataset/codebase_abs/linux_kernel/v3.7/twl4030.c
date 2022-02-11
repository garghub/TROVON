static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return - V_7 ;
return V_4 [ V_3 ] ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_8 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return;
V_4 [ V_3 ] = V_8 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_11 = 0 ;
F_2 ( V_2 , V_3 , V_8 ) ;
if ( F_5 ( V_3 < V_12 ) ) {
switch ( V_3 ) {
case V_13 :
if ( V_10 -> V_14 )
V_11 = 1 ;
break;
case V_15 :
if ( V_10 -> V_16 )
V_11 = 1 ;
break;
case V_17 :
if ( V_10 -> V_18 )
V_11 = 1 ;
break;
case V_19 :
if ( V_10 -> V_20 )
V_11 = 1 ;
break;
case V_21 :
if ( V_10 -> V_22 )
V_11 = 1 ;
break;
case V_23 :
if ( V_10 -> V_24 || V_10 -> V_25 )
V_11 = 1 ;
break;
default:
V_11 = 1 ;
break;
}
if ( V_11 )
return F_6 ( V_26 ,
V_8 , V_3 ) ;
}
return 0 ;
}
static inline void F_7 ( int time )
{
if ( time < 60 ) {
time *= 1000 ;
F_8 ( time , time + 500 ) ;
} else {
F_9 ( time ) ;
}
}
static void F_10 ( struct V_1 * V_2 , int V_27 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_28 ;
if ( V_27 == V_10 -> V_29 )
return;
if ( V_27 )
V_28 = F_11 ( V_30 ) ;
else
V_28 = F_12 ( V_30 ) ;
if ( V_28 >= 0 ) {
F_2 ( V_2 , V_31 , V_28 ) ;
V_10 -> V_29 = V_27 ;
}
F_13 ( 10 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
int V_32 , V_33 = 0 ;
T_1 V_34 ;
F_15 ( V_2 -> V_35 , L_1 ) ;
for ( V_32 = 1 ; V_32 <= V_36 ; V_32 ++ ) {
F_16 ( V_26 , & V_34 , V_32 ) ;
if ( V_34 != V_37 [ V_32 ] ) {
V_33 ++ ;
F_15 ( V_2 -> V_35 ,
L_2 ,
V_32 , V_34 , V_37 [ V_32 ] ) ;
}
}
F_15 ( V_2 -> V_35 , L_3 ,
V_33 , V_33 ? L_4 : L_5 ) ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
int V_32 ;
for ( V_32 = V_38 ; V_32 <= V_36 ; V_32 ++ )
if ( V_32 != V_39 )
F_3 ( V_2 , V_32 , V_37 [ V_32 ] ) ;
}
static void F_18 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
int V_8 ;
F_19 ( V_43 , L_6 ,
& V_41 -> V_44 ) ;
F_19 ( V_43 , L_7 ,
& V_41 -> V_45 ) ;
F_19 ( V_43 , L_8 ,
& V_41 -> V_46 ) ;
if ( ! F_19 ( V_43 , L_9 , & V_8 ) )
V_41 -> V_47 = V_8 ;
V_41 -> V_48 = F_20 ( V_43 ,
L_10 , 0 ) ;
if ( F_21 ( V_41 -> V_48 ) )
V_41 -> V_47 = 1 ;
}
static struct V_40 * F_22 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_23 ( V_2 -> V_35 ) ;
struct V_42 * V_49 = NULL ;
V_49 = F_24 ( V_2 -> V_35 -> V_50 -> V_51 ,
L_11 ) ;
if ( ! V_41 && V_49 ) {
V_41 = F_25 ( V_2 -> V_35 ,
sizeof( struct V_40 ) ,
V_52 ) ;
if ( ! V_41 ) {
F_26 ( V_2 -> V_35 , L_12 ) ;
return NULL ;
}
F_18 ( V_41 , V_49 ) ;
}
return V_41 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_40 * V_41 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_3 , V_53 ;
int V_32 = 0 ;
V_41 = F_22 ( V_2 ) ;
if ( V_41 && V_41 -> V_47 &&
F_21 ( V_41 -> V_48 ) ) {
int V_54 ;
if ( ! V_41 -> V_48 )
F_28 ( V_2 -> V_35 ,
L_13 ) ;
V_54 = F_29 ( V_41 -> V_48 ,
V_55 , L_14 ) ;
if ( V_54 ) {
F_26 ( V_2 -> V_35 , L_15 ) ;
V_41 -> V_48 = - 1 ;
}
}
if ( V_41 && V_41 -> V_56 )
F_14 ( V_2 ) ;
if ( ! V_41 || ( V_41 && V_41 -> V_57 ) )
F_17 ( V_2 ) ;
F_16 ( V_26 , & V_53 ,
V_39 ) ;
F_2 ( V_2 , V_39 , V_53 ) ;
V_3 = F_1 ( V_2 , V_58 ) ;
F_3 ( V_2 , V_58 ,
V_3 | V_59 ) ;
F_3 ( V_2 , V_38 ,
V_60 | V_61 |
V_62 | V_63 ) ;
F_3 ( V_2 , V_64 , 0x32 ) ;
if ( ! V_41 )
return;
V_10 -> V_41 = V_41 ;
V_3 = F_1 ( V_2 , V_65 ) ;
V_3 &= ~ V_66 ;
V_3 |= ( V_41 -> V_45 << 2 ) ;
F_2 ( V_2 , V_65 , V_3 ) ;
F_10 ( V_2 , 1 ) ;
V_3 = F_1 ( V_2 , V_67 ) ;
V_3 &= ~ V_68 ;
V_3 |= V_41 -> V_46 ;
F_3 ( V_2 , V_67 ,
V_3 | V_69 ) ;
F_9 ( 20 ) ;
do {
F_8 ( 1000 , 2000 ) ;
F_16 ( V_26 , & V_53 ,
V_67 ) ;
} while ( ( V_32 ++ < 100 ) &&
( ( V_53 & V_69 ) ==
V_69 ) );
F_2 ( V_2 , V_67 , V_53 ) ;
F_10 ( V_2 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_27 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_70 = - 1 ;
if ( V_27 ) {
V_10 -> V_71 ++ ;
if ( V_10 -> V_71 == 1 )
V_70 = F_11 (
V_72 ) ;
} else {
V_10 -> V_71 -- ;
if ( ! V_10 -> V_71 )
V_70 = F_12 (
V_72 ) ;
}
if ( V_70 >= 0 )
F_2 ( V_2 , V_39 , V_70 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_3 , int V_73 )
{
unsigned char V_74 ;
V_74 = F_1 ( V_2 , V_3 ) ;
if ( V_73 ) {
V_74 |= V_75 ;
F_3 ( V_2 , V_3 , V_74 ) ;
F_13 ( 10 ) ;
V_74 |= V_76 ;
F_3 ( V_2 , V_3 , V_74 ) ;
F_13 ( 40 ) ;
V_74 |= V_77 ;
V_74 |= V_78 ;
F_3 ( V_2 , V_3 , V_74 ) ;
} else {
V_74 &= ~ V_77 ;
V_74 &= ~ V_78 ;
F_3 ( V_2 , V_3 , V_74 ) ;
V_74 &= ~ V_76 ;
F_3 ( V_2 , V_3 , V_74 ) ;
F_13 ( 40 ) ;
V_74 &= ~ V_75 ;
F_3 ( V_2 , V_3 , V_74 ) ;
}
}
static int F_32 ( struct V_79 * V_80 ,
struct V_81 * V_82 , int V_83 )
{
switch ( V_83 ) {
case V_84 :
F_31 ( V_80 -> V_2 , V_85 , 1 ) ;
break;
case V_86 :
F_31 ( V_80 -> V_2 , V_85 , 0 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_79 * V_80 ,
struct V_81 * V_82 , int V_83 )
{
switch ( V_83 ) {
case V_84 :
F_31 ( V_80 -> V_2 , V_87 , 1 ) ;
break;
case V_86 :
F_31 ( V_80 -> V_2 , V_87 , 0 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_79 * V_80 ,
struct V_81 * V_82 , int V_83 )
{
F_3 ( V_80 -> V_2 , V_88 , 0xff ) ;
return 0 ;
}
static int F_35 ( struct V_79 * V_80 ,
struct V_81 * V_82 , int V_83 )
{
switch ( V_83 ) {
case V_89 :
F_30 ( V_80 -> V_2 , 1 ) ;
break;
case V_86 :
F_30 ( V_80 -> V_2 , 0 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_79 * V_80 ,
struct V_81 * V_82 , int V_83 )
{
T_1 V_90 ;
V_90 = F_1 ( V_80 -> V_2 , V_91 ) ;
switch ( V_83 ) {
case V_89 :
F_30 ( V_80 -> V_2 , 1 ) ;
F_3 ( V_80 -> V_2 , V_91 ,
V_90 | V_92 ) ;
break;
case V_86 :
F_3 ( V_80 -> V_2 , V_91 ,
V_90 & ~ V_92 ) ;
F_30 ( V_80 -> V_2 , 0 ) ;
break;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , int V_73 )
{
unsigned char V_93 , V_94 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_40 * V_41 = V_10 -> V_41 ;
unsigned int V_95 [] = { 524288 , 1048576 , 2097152 , 4194304 ,
8388608 , 16777216 , 33554432 , 67108864 } ;
unsigned int V_96 ;
V_93 = F_1 ( V_2 , V_23 ) ;
V_94 = F_1 ( V_2 , V_65 ) ;
V_96 = ( V_95 [ ( V_94 & V_66 ) >> 2 ] /
V_10 -> V_97 ) + 1 ;
if ( V_41 && V_41 -> V_47 ) {
if ( F_21 ( V_41 -> V_48 ) ) {
F_38 ( V_41 -> V_48 , 1 ) ;
} else {
V_94 |= V_98 ;
F_3 ( V_2 , V_65 , V_94 ) ;
}
}
if ( V_73 ) {
V_94 |= V_99 ;
F_3 ( V_2 , V_65 , V_94 ) ;
F_6 ( V_26 ,
V_93 ,
V_23 ) ;
V_94 |= V_100 ;
F_3 ( V_2 , V_65 , V_94 ) ;
F_7 ( V_96 ) ;
} else {
V_94 &= ~ V_100 ;
F_3 ( V_2 , V_65 , V_94 ) ;
F_7 ( V_96 ) ;
F_6 ( V_26 ,
V_93 & ( ~ 0x0f ) ,
V_23 ) ;
V_94 &= ~ V_99 ;
F_3 ( V_2 , V_65 , V_94 ) ;
}
if ( V_41 && V_41 -> V_47 ) {
if ( F_21 ( V_41 -> V_48 ) ) {
F_38 ( V_41 -> V_48 , 0 ) ;
} else {
V_94 &= ~ V_98 ;
F_3 ( V_2 , V_65 , V_94 ) ;
}
}
}
static int F_39 ( struct V_79 * V_80 ,
struct V_81 * V_82 , int V_83 )
{
struct V_9 * V_10 = F_4 ( V_80 -> V_2 ) ;
switch ( V_83 ) {
case V_84 :
if ( ! V_10 -> V_25 )
F_37 ( V_80 -> V_2 , 1 ) ;
V_10 -> V_24 = 1 ;
break;
case V_86 :
if ( ! V_10 -> V_25 )
F_37 ( V_80 -> V_2 , 0 ) ;
V_10 -> V_24 = 0 ;
break;
}
return 0 ;
}
static int F_40 ( struct V_79 * V_80 ,
struct V_81 * V_82 , int V_83 )
{
struct V_9 * V_10 = F_4 ( V_80 -> V_2 ) ;
switch ( V_83 ) {
case V_84 :
if ( ! V_10 -> V_24 )
F_37 ( V_80 -> V_2 , 1 ) ;
V_10 -> V_25 = 1 ;
break;
case V_86 :
if ( ! V_10 -> V_24 )
F_37 ( V_80 -> V_2 , 0 ) ;
V_10 -> V_25 = 0 ;
break;
}
return 0 ;
}
static int F_41 ( struct V_79 * V_80 ,
struct V_81 * V_82 , int V_83 )
{
struct V_9 * V_10 = F_4 ( V_80 -> V_2 ) ;
struct V_40 * V_41 = V_10 -> V_41 ;
if ( V_41 && V_41 -> V_44 )
F_7 ( V_41 -> V_44 ) ;
return 0 ;
}
static int F_42 ( struct V_81 * V_82 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 =
(struct V_103 * ) V_82 -> V_105 ;
struct V_1 * V_2 = F_43 ( V_82 ) ;
unsigned int V_3 = V_104 -> V_3 ;
unsigned int V_106 = V_104 -> V_106 ;
unsigned int V_107 = V_104 -> V_107 ;
int V_108 = V_104 -> V_108 ;
int V_109 = ( 1 << F_44 ( V_108 ) ) - 1 ;
V_102 -> V_8 . integer . V_8 [ 0 ] =
( F_45 ( V_2 , V_3 ) >> V_106 ) & V_109 ;
if ( V_102 -> V_8 . integer . V_8 [ 0 ] )
V_102 -> V_8 . integer . V_8 [ 0 ] =
V_108 + 1 - V_102 -> V_8 . integer . V_8 [ 0 ] ;
if ( V_106 != V_107 ) {
V_102 -> V_8 . integer . V_8 [ 1 ] =
( F_45 ( V_2 , V_3 ) >> V_107 ) & V_109 ;
if ( V_102 -> V_8 . integer . V_8 [ 1 ] )
V_102 -> V_8 . integer . V_8 [ 1 ] =
V_108 + 1 - V_102 -> V_8 . integer . V_8 [ 1 ] ;
}
return 0 ;
}
static int F_46 ( struct V_81 * V_82 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 =
(struct V_103 * ) V_82 -> V_105 ;
struct V_1 * V_2 = F_43 ( V_82 ) ;
unsigned int V_3 = V_104 -> V_3 ;
unsigned int V_106 = V_104 -> V_106 ;
unsigned int V_107 = V_104 -> V_107 ;
int V_108 = V_104 -> V_108 ;
int V_109 = ( 1 << F_44 ( V_108 ) ) - 1 ;
unsigned short V_34 , V_110 , V_111 ;
V_34 = ( V_102 -> V_8 . integer . V_8 [ 0 ] & V_109 ) ;
V_111 = V_109 << V_106 ;
if ( V_34 )
V_34 = V_108 + 1 - V_34 ;
V_34 = V_34 << V_106 ;
if ( V_106 != V_107 ) {
V_110 = ( V_102 -> V_8 . integer . V_8 [ 1 ] & V_109 ) ;
V_111 |= V_109 << V_107 ;
if ( V_110 )
V_110 = V_108 + 1 - V_110 ;
V_34 |= V_110 << V_107 ;
}
return F_47 ( V_2 , V_3 , V_111 , V_34 ) ;
}
static int F_48 ( struct V_81 * V_82 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 =
(struct V_103 * ) V_82 -> V_105 ;
struct V_1 * V_2 = F_43 ( V_82 ) ;
unsigned int V_3 = V_104 -> V_3 ;
unsigned int V_112 = V_104 -> V_113 ;
unsigned int V_106 = V_104 -> V_106 ;
int V_108 = V_104 -> V_108 ;
int V_109 = ( 1 << F_44 ( V_108 ) ) - 1 ;
V_102 -> V_8 . integer . V_8 [ 0 ] =
( F_45 ( V_2 , V_3 ) >> V_106 ) & V_109 ;
V_102 -> V_8 . integer . V_8 [ 1 ] =
( F_45 ( V_2 , V_112 ) >> V_106 ) & V_109 ;
if ( V_102 -> V_8 . integer . V_8 [ 0 ] )
V_102 -> V_8 . integer . V_8 [ 0 ] =
V_108 + 1 - V_102 -> V_8 . integer . V_8 [ 0 ] ;
if ( V_102 -> V_8 . integer . V_8 [ 1 ] )
V_102 -> V_8 . integer . V_8 [ 1 ] =
V_108 + 1 - V_102 -> V_8 . integer . V_8 [ 1 ] ;
return 0 ;
}
static int F_49 ( struct V_81 * V_82 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 =
(struct V_103 * ) V_82 -> V_105 ;
struct V_1 * V_2 = F_43 ( V_82 ) ;
unsigned int V_3 = V_104 -> V_3 ;
unsigned int V_112 = V_104 -> V_113 ;
unsigned int V_106 = V_104 -> V_106 ;
int V_108 = V_104 -> V_108 ;
int V_109 = ( 1 << F_44 ( V_108 ) ) - 1 ;
int V_114 ;
unsigned short V_34 , V_110 , V_111 ;
V_111 = V_109 << V_106 ;
V_34 = ( V_102 -> V_8 . integer . V_8 [ 0 ] & V_109 ) ;
V_110 = ( V_102 -> V_8 . integer . V_8 [ 1 ] & V_109 ) ;
if ( V_34 )
V_34 = V_108 + 1 - V_34 ;
if ( V_110 )
V_110 = V_108 + 1 - V_110 ;
V_34 = V_34 << V_106 ;
V_110 = V_110 << V_106 ;
V_114 = F_47 ( V_2 , V_3 , V_111 , V_34 ) ;
if ( V_114 < 0 )
return V_114 ;
V_114 = F_47 ( V_2 , V_112 , V_111 , V_110 ) ;
return V_114 ;
}
static int F_50 ( struct V_81 * V_82 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = F_43 ( V_82 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_115 * V_116 = (struct V_115 * ) V_82 -> V_105 ;
unsigned short V_34 ;
unsigned short V_109 ;
if ( V_10 -> V_117 ) {
F_26 ( V_2 -> V_35 ,
L_16 ) ;
return - V_118 ;
}
if ( V_102 -> V_8 . V_119 . V_120 [ 0 ] > V_116 -> V_108 - 1 )
return - V_121 ;
V_34 = V_102 -> V_8 . V_119 . V_120 [ 0 ] << V_116 -> V_122 ;
V_109 = V_116 -> V_109 << V_116 -> V_122 ;
if ( V_116 -> V_122 != V_116 -> V_123 ) {
if ( V_102 -> V_8 . V_119 . V_120 [ 1 ] > V_116 -> V_108 - 1 )
return - V_121 ;
V_34 |= V_102 -> V_8 . V_119 . V_120 [ 1 ] << V_116 -> V_123 ;
V_109 |= V_116 -> V_109 << V_116 -> V_123 ;
}
return F_47 ( V_2 , V_116 -> V_3 , V_109 , V_34 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_124 V_125 )
{
switch ( V_125 ) {
case V_126 :
break;
case V_127 :
break;
case V_128 :
if ( V_2 -> V_129 . V_130 == V_131 )
F_10 ( V_2 , 1 ) ;
break;
case V_131 :
F_10 ( V_2 , 0 ) ;
break;
}
V_2 -> V_129 . V_130 = V_125 ;
return 0 ;
}
static void F_52 ( struct V_9 * V_10 ,
struct V_132 * V_133 )
{
struct V_132 * V_134 ;
if ( V_133 == V_10 -> V_135 )
V_134 = V_10 -> V_136 ;
else if ( V_133 == V_10 -> V_136 )
V_134 = V_10 -> V_135 ;
else
return;
F_53 ( V_134 -> V_137 ,
V_138 ,
V_10 -> V_139 ,
V_10 -> V_139 ) ;
F_53 ( V_134 -> V_137 ,
V_140 ,
V_10 -> V_141 ,
V_10 -> V_141 ) ;
F_53 ( V_134 -> V_137 ,
V_142 ,
V_10 -> V_143 ,
V_10 -> V_143 ) ;
}
static void F_54 ( struct V_1 * V_2 , int V_144 ,
int V_27 )
{
T_1 V_3 , V_109 ;
V_3 = F_1 ( V_2 , V_38 ) ;
if ( V_144 == V_145 )
V_109 = V_146 | V_147 ;
else
V_109 = V_148 | V_149 ;
if ( V_27 )
V_3 |= V_109 ;
else
V_3 &= ~ V_109 ;
F_3 ( V_2 , V_38 , V_3 ) ;
}
static int F_55 ( struct V_132 * V_150 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_135 ) {
V_10 -> V_136 = V_150 ;
if ( V_10 -> V_117 )
F_52 ( V_10 , V_10 -> V_135 ) ;
} else {
if ( ! ( F_1 ( V_2 , V_31 ) &
V_153 ) ) {
F_53 ( V_150 -> V_137 ,
V_142 ,
2 , 2 ) ;
}
V_10 -> V_135 = V_150 ;
}
return 0 ;
}
static void F_56 ( struct V_132 * V_150 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_135 == V_150 )
V_10 -> V_135 = V_10 -> V_136 ;
V_10 -> V_136 = NULL ;
if ( ! V_10 -> V_135 )
V_10 -> V_117 = 0 ;
else if ( ! V_10 -> V_135 -> V_137 -> V_143 )
V_10 -> V_117 = 0 ;
if ( V_150 -> V_137 -> V_143 == 4 )
F_54 ( V_2 , V_150 -> V_154 , 0 ) ;
}
static int F_57 ( struct V_132 * V_150 ,
struct V_155 * V_156 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_28 , V_157 , V_158 , V_159 ;
if ( F_58 ( V_156 ) == 4 ) {
V_158 = F_1 ( V_2 , V_91 ) ;
V_28 = F_1 ( V_2 , V_31 ) ;
if ( ( V_28 & V_153 ) &&
( ( V_158 & V_160 ) == V_161 ) )
F_54 ( V_2 , V_150 -> V_154 , 1 ) ;
else
return - V_121 ;
}
if ( V_10 -> V_117 )
return 0 ;
V_157 = F_1 ( V_2 ,
V_31 ) & ~ V_162 ;
V_28 = V_157 & ~ V_163 ;
switch ( F_59 ( V_156 ) ) {
case 8000 :
V_28 |= V_164 ;
break;
case 11025 :
V_28 |= V_165 ;
break;
case 12000 :
V_28 |= V_166 ;
break;
case 16000 :
V_28 |= V_167 ;
break;
case 22050 :
V_28 |= V_168 ;
break;
case 24000 :
V_28 |= V_169 ;
break;
case 32000 :
V_28 |= V_170 ;
break;
case 44100 :
V_28 |= V_171 ;
break;
case 48000 :
V_28 |= V_172 ;
break;
case 96000 :
V_28 |= V_173 ;
break;
default:
F_26 ( V_2 -> V_35 , L_17 , V_174 ,
F_59 ( V_156 ) ) ;
return - V_121 ;
}
V_159 = F_1 ( V_2 , V_91 ) ;
V_158 = V_159 ;
V_158 &= ~ V_175 ;
switch ( F_60 ( V_156 ) ) {
case V_176 :
V_158 |= V_177 ;
break;
case V_178 :
V_158 |= V_179 ;
break;
default:
F_26 ( V_2 -> V_35 , L_18 , V_174 ,
F_60 ( V_156 ) ) ;
return - V_121 ;
}
if ( V_158 != V_159 || V_28 != V_157 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_31 , V_28 ) ;
F_3 ( V_2 , V_91 , V_158 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_31 , V_28 ) ;
F_3 ( V_2 , V_91 , V_158 ) ;
}
}
V_10 -> V_117 = 1 ;
V_10 -> V_139 = F_59 ( V_156 ) ;
V_10 -> V_141 = F_61 ( V_156 ,
V_140 ) -> V_180 ;
V_10 -> V_143 = F_58 ( V_156 ) ;
if ( V_10 -> V_136 )
F_52 ( V_10 , V_150 ) ;
return 0 ;
}
static int F_62 ( struct V_151 * V_181 ,
int V_182 , unsigned int V_183 , int V_184 )
{
struct V_1 * V_2 = V_181 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
switch ( V_183 ) {
case 19200000 :
case 26000000 :
case 38400000 :
break;
default:
F_26 ( V_2 -> V_35 , L_19 , V_183 ) ;
return - V_121 ;
}
if ( ( V_183 / 1000 ) != V_10 -> V_97 ) {
F_26 ( V_2 -> V_35 ,
L_20 ,
V_183 , V_10 -> V_97 * 1000 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_63 ( struct V_151 * V_181 ,
unsigned int V_185 )
{
struct V_1 * V_2 = V_181 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_159 , V_158 ;
V_159 = F_1 ( V_2 , V_91 ) ;
V_158 = V_159 ;
switch ( V_185 & V_186 ) {
case V_187 :
V_158 &= ~ ( V_188 ) ;
V_158 &= ~ ( V_189 ) ;
break;
case V_190 :
V_158 |= V_188 ;
V_158 |= V_189 ;
break;
default:
return - V_121 ;
}
V_158 &= ~ V_160 ;
switch ( V_185 & V_191 ) {
case V_192 :
V_158 |= V_193 ;
break;
case V_194 :
V_158 |= V_161 ;
break;
default:
return - V_121 ;
}
if ( V_158 != V_159 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_91 , V_158 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_91 , V_158 ) ;
}
}
return 0 ;
}
static int F_64 ( struct V_151 * V_152 , int V_195 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
T_1 V_3 = F_1 ( V_2 , V_91 ) ;
if ( V_195 )
V_3 |= V_196 ;
else
V_3 &= ~ V_196 ;
return F_3 ( V_2 , V_91 , V_3 ) ;
}
static void F_65 ( struct V_1 * V_2 , int V_144 ,
int V_27 )
{
T_1 V_3 , V_109 ;
V_3 = F_1 ( V_2 , V_38 ) ;
if ( V_144 == V_145 )
V_109 = V_146 ;
else
V_109 = V_148 | V_149 ;
if ( V_27 )
V_3 |= V_109 ;
else
V_3 &= ~ V_109 ;
F_3 ( V_2 , V_38 , V_3 ) ;
}
static int F_66 ( struct V_132 * V_150 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_28 ;
if ( V_10 -> V_97 != 26000 ) {
F_26 ( V_2 -> V_35 ,
L_21 ,
V_174 , V_10 -> V_97 ) ;
return - V_121 ;
}
V_28 = F_1 ( V_2 , V_31 )
& V_197 ;
if ( V_28 != V_198 ) {
F_26 ( V_2 -> V_35 , L_22 ,
V_174 ) ;
return - V_121 ;
}
return 0 ;
}
static void F_67 ( struct V_132 * V_150 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
F_65 ( V_2 , V_150 -> V_154 , 0 ) ;
}
static int F_68 ( struct V_132 * V_150 ,
struct V_155 * V_156 , struct V_151 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_157 , V_28 ;
F_65 ( V_2 , V_150 -> V_154 , 1 ) ;
V_157 = F_1 ( V_2 , V_31 )
& ~ ( V_162 ) ;
V_28 = V_157 ;
switch ( F_59 ( V_156 ) ) {
case 8000 :
V_28 &= ~ ( V_199 ) ;
break;
case 16000 :
V_28 |= V_199 ;
break;
default:
F_26 ( V_2 -> V_35 , L_17 , V_174 ,
F_59 ( V_156 ) ) ;
return - V_121 ;
}
if ( V_28 != V_157 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_31 , V_28 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_31 , V_28 ) ;
}
}
return 0 ;
}
static int F_69 ( struct V_151 * V_181 ,
int V_182 , unsigned int V_183 , int V_184 )
{
struct V_1 * V_2 = V_181 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_183 != 26000000 ) {
F_26 ( V_2 -> V_35 ,
L_21 ,
V_174 , V_183 / 1000 ) ;
return - V_121 ;
}
if ( ( V_183 / 1000 ) != V_10 -> V_97 ) {
F_26 ( V_2 -> V_35 ,
L_20 ,
V_183 , V_10 -> V_97 * 1000 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_70 ( struct V_151 * V_181 ,
unsigned int V_185 )
{
struct V_1 * V_2 = V_181 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_159 , V_158 ;
V_159 = F_1 ( V_2 , V_200 ) ;
V_158 = V_159 ;
switch ( V_185 & V_186 ) {
case V_187 :
V_158 &= ~ ( V_201 ) ;
break;
case V_190 :
V_158 |= V_201 ;
break;
default:
return - V_121 ;
}
switch ( V_185 & V_202 ) {
case V_203 :
V_158 &= ~ ( V_204 ) ;
break;
case V_205 :
V_158 |= V_204 ;
break;
default:
return - V_121 ;
}
if ( V_158 != V_159 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_200 , V_158 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_200 , V_158 ) ;
}
}
return 0 ;
}
static int F_71 ( struct V_151 * V_152 , int V_195 )
{
struct V_1 * V_2 = V_152 -> V_2 ;
T_1 V_3 = F_1 ( V_2 , V_200 ) ;
if ( V_195 )
V_3 |= V_206 ;
else
V_3 &= ~ V_206 ;
return F_3 ( V_2 , V_200 , V_3 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
F_51 ( V_2 , V_131 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
F_51 ( V_2 , V_128 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_10 = F_25 ( V_2 -> V_35 , sizeof( struct V_9 ) ,
V_52 ) ;
if ( V_10 == NULL ) {
F_26 ( V_2 -> V_35 , L_12 ) ;
return - V_207 ;
}
F_75 ( V_2 , V_10 ) ;
V_10 -> V_97 = F_76 () / 1000 ;
F_27 ( V_2 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_40 * V_41 = V_10 -> V_41 ;
F_17 ( V_2 ) ;
F_51 ( V_2 , V_131 ) ;
if ( V_41 && V_41 -> V_47 && F_21 ( V_41 -> V_48 ) )
F_78 ( V_41 -> V_48 ) ;
return 0 ;
}
static int T_2 F_79 ( struct V_208 * V_209 )
{
return F_80 ( & V_209 -> V_35 , & V_210 ,
V_211 , F_81 ( V_211 ) ) ;
}
static int T_3 F_82 ( struct V_208 * V_209 )
{
F_83 ( & V_209 -> V_35 ) ;
return 0 ;
}
