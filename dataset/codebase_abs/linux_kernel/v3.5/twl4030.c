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
static void F_18 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_19 ( V_2 -> V_35 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_3 , V_42 ;
int V_32 = 0 ;
if ( V_41 && V_41 -> V_43 )
F_14 ( V_2 ) ;
if ( ! V_41 || ( V_41 && V_41 -> V_44 ) )
F_17 ( V_2 ) ;
F_16 ( V_26 , & V_42 ,
V_39 ) ;
F_2 ( V_2 , V_39 , V_42 ) ;
V_3 = F_1 ( V_2 , V_45 ) ;
F_3 ( V_2 , V_45 ,
V_3 | V_46 ) ;
F_3 ( V_2 , V_38 ,
V_47 | V_48 |
V_49 | V_50 ) ;
F_3 ( V_2 , V_51 , 0x32 ) ;
if ( ! V_41 )
return;
V_10 -> V_52 = V_41 -> V_52 ;
V_3 = F_1 ( V_2 , V_53 ) ;
V_3 &= ~ V_54 ;
V_3 |= ( V_41 -> V_55 << 2 ) ;
F_2 ( V_2 , V_53 , V_3 ) ;
F_10 ( V_2 , 1 ) ;
V_3 = F_1 ( V_2 , V_56 ) ;
V_3 &= ~ V_57 ;
V_3 |= V_41 -> V_58 ;
F_3 ( V_2 , V_56 ,
V_3 | V_59 ) ;
F_9 ( 20 ) ;
do {
F_8 ( 1000 , 2000 ) ;
F_16 ( V_26 , & V_42 ,
V_56 ) ;
} while ( ( V_32 ++ < 100 ) &&
( ( V_42 & V_59 ) ==
V_59 ) );
F_2 ( V_2 , V_56 , V_42 ) ;
F_10 ( V_2 , 0 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_27 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_60 = - 1 ;
if ( V_27 ) {
V_10 -> V_61 ++ ;
if ( V_10 -> V_61 == 1 )
V_60 = F_11 (
V_62 ) ;
} else {
V_10 -> V_61 -- ;
if ( ! V_10 -> V_61 )
V_60 = F_12 (
V_62 ) ;
}
if ( V_60 >= 0 )
F_2 ( V_2 , V_39 , V_60 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_3 , int V_63 )
{
unsigned char V_64 ;
V_64 = F_1 ( V_2 , V_3 ) ;
if ( V_63 ) {
V_64 |= V_65 ;
F_3 ( V_2 , V_3 , V_64 ) ;
F_13 ( 10 ) ;
V_64 |= V_66 ;
F_3 ( V_2 , V_3 , V_64 ) ;
F_13 ( 40 ) ;
V_64 |= V_67 ;
V_64 |= V_68 ;
F_3 ( V_2 , V_3 , V_64 ) ;
} else {
V_64 &= ~ V_67 ;
V_64 &= ~ V_68 ;
F_3 ( V_2 , V_3 , V_64 ) ;
V_64 &= ~ V_66 ;
F_3 ( V_2 , V_3 , V_64 ) ;
F_13 ( 40 ) ;
V_64 &= ~ V_65 ;
F_3 ( V_2 , V_3 , V_64 ) ;
}
}
static int F_22 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
switch ( V_73 ) {
case V_74 :
F_21 ( V_70 -> V_2 , V_75 , 1 ) ;
break;
case V_76 :
F_21 ( V_70 -> V_2 , V_75 , 0 ) ;
break;
}
return 0 ;
}
static int F_23 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
switch ( V_73 ) {
case V_74 :
F_21 ( V_70 -> V_2 , V_77 , 1 ) ;
break;
case V_76 :
F_21 ( V_70 -> V_2 , V_77 , 0 ) ;
break;
}
return 0 ;
}
static int F_24 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
F_3 ( V_70 -> V_2 , V_78 , 0xff ) ;
return 0 ;
}
static int F_25 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
switch ( V_73 ) {
case V_79 :
F_20 ( V_70 -> V_2 , 1 ) ;
break;
case V_76 :
F_20 ( V_70 -> V_2 , 0 ) ;
break;
}
return 0 ;
}
static int F_26 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
T_1 V_80 ;
V_80 = F_1 ( V_70 -> V_2 , V_81 ) ;
switch ( V_73 ) {
case V_79 :
F_20 ( V_70 -> V_2 , 1 ) ;
F_3 ( V_70 -> V_2 , V_81 ,
V_80 | V_82 ) ;
break;
case V_76 :
F_3 ( V_70 -> V_2 , V_81 ,
V_80 & ~ V_82 ) ;
F_20 ( V_70 -> V_2 , 0 ) ;
break;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 , int V_63 )
{
struct V_40 * V_41 = V_2 -> V_35 -> V_83 ;
unsigned char V_84 , V_85 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
unsigned int V_86 [] = { 524288 , 1048576 , 2097152 , 4194304 ,
8388608 , 16777216 , 33554432 , 67108864 } ;
unsigned int V_87 ;
V_84 = F_1 ( V_2 , V_23 ) ;
V_85 = F_1 ( V_2 , V_53 ) ;
V_87 = ( V_86 [ ( V_85 & V_54 ) >> 2 ] /
V_10 -> V_88 ) + 1 ;
if ( V_41 && V_41 -> V_89 ) {
if ( V_41 -> V_90 ) {
V_41 -> V_90 ( 1 ) ;
} else {
V_85 |= V_91 ;
F_3 ( V_2 , V_53 , V_85 ) ;
}
}
if ( V_63 ) {
V_85 |= V_92 ;
F_3 ( V_2 , V_53 , V_85 ) ;
F_6 ( V_26 ,
V_84 ,
V_23 ) ;
V_85 |= V_93 ;
F_3 ( V_2 , V_53 , V_85 ) ;
F_7 ( V_87 ) ;
} else {
V_85 &= ~ V_93 ;
F_3 ( V_2 , V_53 , V_85 ) ;
F_7 ( V_87 ) ;
F_6 ( V_26 ,
V_84 & ( ~ 0x0f ) ,
V_23 ) ;
V_85 &= ~ V_92 ;
F_3 ( V_2 , V_53 , V_85 ) ;
}
if ( V_41 && V_41 -> V_89 ) {
if ( V_41 -> V_90 ) {
V_41 -> V_90 ( 0 ) ;
} else {
V_85 &= ~ V_91 ;
F_3 ( V_2 , V_53 , V_85 ) ;
}
}
}
static int F_28 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
struct V_9 * V_10 = F_4 ( V_70 -> V_2 ) ;
switch ( V_73 ) {
case V_74 :
if ( ! V_10 -> V_25 )
F_27 ( V_70 -> V_2 , 1 ) ;
V_10 -> V_24 = 1 ;
break;
case V_76 :
if ( ! V_10 -> V_25 )
F_27 ( V_70 -> V_2 , 0 ) ;
V_10 -> V_24 = 0 ;
break;
}
return 0 ;
}
static int F_29 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
struct V_9 * V_10 = F_4 ( V_70 -> V_2 ) ;
switch ( V_73 ) {
case V_74 :
if ( ! V_10 -> V_24 )
F_27 ( V_70 -> V_2 , 1 ) ;
V_10 -> V_25 = 1 ;
break;
case V_76 :
if ( ! V_10 -> V_24 )
F_27 ( V_70 -> V_2 , 0 ) ;
V_10 -> V_25 = 0 ;
break;
}
return 0 ;
}
static int F_30 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
struct V_9 * V_10 = F_4 ( V_70 -> V_2 ) ;
if ( V_10 -> V_52 )
F_7 ( V_10 -> V_52 ) ;
return 0 ;
}
static int F_31 ( struct V_71 * V_72 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_72 -> V_98 ;
struct V_1 * V_2 = F_32 ( V_72 ) ;
unsigned int V_3 = V_97 -> V_3 ;
unsigned int V_99 = V_97 -> V_99 ;
unsigned int V_100 = V_97 -> V_100 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_33 ( V_101 ) ) - 1 ;
V_95 -> V_8 . integer . V_8 [ 0 ] =
( F_34 ( V_2 , V_3 ) >> V_99 ) & V_102 ;
if ( V_95 -> V_8 . integer . V_8 [ 0 ] )
V_95 -> V_8 . integer . V_8 [ 0 ] =
V_101 + 1 - V_95 -> V_8 . integer . V_8 [ 0 ] ;
if ( V_99 != V_100 ) {
V_95 -> V_8 . integer . V_8 [ 1 ] =
( F_34 ( V_2 , V_3 ) >> V_100 ) & V_102 ;
if ( V_95 -> V_8 . integer . V_8 [ 1 ] )
V_95 -> V_8 . integer . V_8 [ 1 ] =
V_101 + 1 - V_95 -> V_8 . integer . V_8 [ 1 ] ;
}
return 0 ;
}
static int F_35 ( struct V_71 * V_72 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_72 -> V_98 ;
struct V_1 * V_2 = F_32 ( V_72 ) ;
unsigned int V_3 = V_97 -> V_3 ;
unsigned int V_99 = V_97 -> V_99 ;
unsigned int V_100 = V_97 -> V_100 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_33 ( V_101 ) ) - 1 ;
unsigned short V_34 , V_103 , V_104 ;
V_34 = ( V_95 -> V_8 . integer . V_8 [ 0 ] & V_102 ) ;
V_104 = V_102 << V_99 ;
if ( V_34 )
V_34 = V_101 + 1 - V_34 ;
V_34 = V_34 << V_99 ;
if ( V_99 != V_100 ) {
V_103 = ( V_95 -> V_8 . integer . V_8 [ 1 ] & V_102 ) ;
V_104 |= V_102 << V_100 ;
if ( V_103 )
V_103 = V_101 + 1 - V_103 ;
V_34 |= V_103 << V_100 ;
}
return F_36 ( V_2 , V_3 , V_104 , V_34 ) ;
}
static int F_37 ( struct V_71 * V_72 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_72 -> V_98 ;
struct V_1 * V_2 = F_32 ( V_72 ) ;
unsigned int V_3 = V_97 -> V_3 ;
unsigned int V_105 = V_97 -> V_106 ;
unsigned int V_99 = V_97 -> V_99 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_33 ( V_101 ) ) - 1 ;
V_95 -> V_8 . integer . V_8 [ 0 ] =
( F_34 ( V_2 , V_3 ) >> V_99 ) & V_102 ;
V_95 -> V_8 . integer . V_8 [ 1 ] =
( F_34 ( V_2 , V_105 ) >> V_99 ) & V_102 ;
if ( V_95 -> V_8 . integer . V_8 [ 0 ] )
V_95 -> V_8 . integer . V_8 [ 0 ] =
V_101 + 1 - V_95 -> V_8 . integer . V_8 [ 0 ] ;
if ( V_95 -> V_8 . integer . V_8 [ 1 ] )
V_95 -> V_8 . integer . V_8 [ 1 ] =
V_101 + 1 - V_95 -> V_8 . integer . V_8 [ 1 ] ;
return 0 ;
}
static int F_38 ( struct V_71 * V_72 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 =
(struct V_96 * ) V_72 -> V_98 ;
struct V_1 * V_2 = F_32 ( V_72 ) ;
unsigned int V_3 = V_97 -> V_3 ;
unsigned int V_105 = V_97 -> V_106 ;
unsigned int V_99 = V_97 -> V_99 ;
int V_101 = V_97 -> V_101 ;
int V_102 = ( 1 << F_33 ( V_101 ) ) - 1 ;
int V_107 ;
unsigned short V_34 , V_103 , V_104 ;
V_104 = V_102 << V_99 ;
V_34 = ( V_95 -> V_8 . integer . V_8 [ 0 ] & V_102 ) ;
V_103 = ( V_95 -> V_8 . integer . V_8 [ 1 ] & V_102 ) ;
if ( V_34 )
V_34 = V_101 + 1 - V_34 ;
if ( V_103 )
V_103 = V_101 + 1 - V_103 ;
V_34 = V_34 << V_99 ;
V_103 = V_103 << V_99 ;
V_107 = F_36 ( V_2 , V_3 , V_104 , V_34 ) ;
if ( V_107 < 0 )
return V_107 ;
V_107 = F_36 ( V_2 , V_105 , V_104 , V_103 ) ;
return V_107 ;
}
static int F_39 ( struct V_71 * V_72 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_72 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_108 * V_109 = (struct V_108 * ) V_72 -> V_98 ;
unsigned short V_34 ;
unsigned short V_102 , V_110 ;
if ( V_10 -> V_111 ) {
F_40 ( V_2 -> V_35 ,
L_6 ) ;
return - V_112 ;
}
for ( V_110 = 1 ; V_110 < V_109 -> V_101 ; V_110 <<= 1 )
;
if ( V_95 -> V_8 . V_113 . V_114 [ 0 ] > V_109 -> V_101 - 1 )
return - V_115 ;
V_34 = V_95 -> V_8 . V_113 . V_114 [ 0 ] << V_109 -> V_116 ;
V_102 = ( V_110 - 1 ) << V_109 -> V_116 ;
if ( V_109 -> V_116 != V_109 -> V_117 ) {
if ( V_95 -> V_8 . V_113 . V_114 [ 1 ] > V_109 -> V_101 - 1 )
return - V_115 ;
V_34 |= V_95 -> V_8 . V_113 . V_114 [ 1 ] << V_109 -> V_117 ;
V_102 |= ( V_110 - 1 ) << V_109 -> V_117 ;
}
return F_36 ( V_2 , V_109 -> V_3 , V_102 , V_34 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
enum V_118 V_119 )
{
switch ( V_119 ) {
case V_120 :
break;
case V_121 :
break;
case V_122 :
if ( V_2 -> V_123 . V_124 == V_125 )
F_10 ( V_2 , 1 ) ;
break;
case V_125 :
F_10 ( V_2 , 0 ) ;
break;
}
V_2 -> V_123 . V_124 = V_119 ;
return 0 ;
}
static void F_42 ( struct V_9 * V_10 ,
struct V_126 * V_127 )
{
struct V_126 * V_128 ;
if ( V_127 == V_10 -> V_129 )
V_128 = V_10 -> V_130 ;
else if ( V_127 == V_10 -> V_130 )
V_128 = V_10 -> V_129 ;
else
return;
F_43 ( V_128 -> V_131 ,
V_132 ,
V_10 -> V_133 ,
V_10 -> V_133 ) ;
F_43 ( V_128 -> V_131 ,
V_134 ,
V_10 -> V_135 ,
V_10 -> V_135 ) ;
F_43 ( V_128 -> V_131 ,
V_136 ,
V_10 -> V_137 ,
V_10 -> V_137 ) ;
}
static void F_44 ( struct V_1 * V_2 , int V_138 ,
int V_27 )
{
T_1 V_3 , V_102 ;
V_3 = F_1 ( V_2 , V_38 ) ;
if ( V_138 == V_139 )
V_102 = V_140 | V_141 ;
else
V_102 = V_142 | V_143 ;
if ( V_27 )
V_3 |= V_102 ;
else
V_3 &= ~ V_102 ;
F_3 ( V_2 , V_38 , V_3 ) ;
}
static int F_45 ( struct V_126 * V_144 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_129 ) {
V_10 -> V_130 = V_144 ;
if ( V_10 -> V_111 )
F_42 ( V_10 , V_10 -> V_129 ) ;
} else {
if ( ! ( F_1 ( V_2 , V_31 ) &
V_147 ) ) {
F_43 ( V_144 -> V_131 ,
V_136 ,
2 , 2 ) ;
}
V_10 -> V_129 = V_144 ;
}
return 0 ;
}
static void F_46 ( struct V_126 * V_144 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_129 == V_144 )
V_10 -> V_129 = V_10 -> V_130 ;
V_10 -> V_130 = NULL ;
if ( ! V_10 -> V_129 )
V_10 -> V_111 = 0 ;
else if ( ! V_10 -> V_129 -> V_131 -> V_137 )
V_10 -> V_111 = 0 ;
if ( V_144 -> V_131 -> V_137 == 4 )
F_44 ( V_2 , V_144 -> V_148 , 0 ) ;
}
static int F_47 ( struct V_126 * V_144 ,
struct V_149 * V_150 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_28 , V_151 , V_152 , V_153 ;
if ( F_48 ( V_150 ) == 4 ) {
V_152 = F_1 ( V_2 , V_81 ) ;
V_28 = F_1 ( V_2 , V_31 ) ;
if ( ( V_28 & V_147 ) &&
( ( V_152 & V_154 ) == V_155 ) )
F_44 ( V_2 , V_144 -> V_148 , 1 ) ;
else
return - V_115 ;
}
if ( V_10 -> V_111 )
return 0 ;
V_151 = F_1 ( V_2 ,
V_31 ) & ~ V_156 ;
V_28 = V_151 & ~ V_157 ;
switch ( F_49 ( V_150 ) ) {
case 8000 :
V_28 |= V_158 ;
break;
case 11025 :
V_28 |= V_159 ;
break;
case 12000 :
V_28 |= V_160 ;
break;
case 16000 :
V_28 |= V_161 ;
break;
case 22050 :
V_28 |= V_162 ;
break;
case 24000 :
V_28 |= V_163 ;
break;
case 32000 :
V_28 |= V_164 ;
break;
case 44100 :
V_28 |= V_165 ;
break;
case 48000 :
V_28 |= V_166 ;
break;
case 96000 :
V_28 |= V_167 ;
break;
default:
F_40 ( V_2 -> V_35 , L_7 , V_168 ,
F_49 ( V_150 ) ) ;
return - V_115 ;
}
V_153 = F_1 ( V_2 , V_81 ) ;
V_152 = V_153 ;
V_152 &= ~ V_169 ;
switch ( F_50 ( V_150 ) ) {
case V_170 :
V_152 |= V_171 ;
break;
case V_172 :
V_152 |= V_173 ;
break;
default:
F_40 ( V_2 -> V_35 , L_8 , V_168 ,
F_50 ( V_150 ) ) ;
return - V_115 ;
}
if ( V_152 != V_153 || V_28 != V_151 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_31 , V_28 ) ;
F_3 ( V_2 , V_81 , V_152 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_31 , V_28 ) ;
F_3 ( V_2 , V_81 , V_152 ) ;
}
}
V_10 -> V_111 = 1 ;
V_10 -> V_133 = F_49 ( V_150 ) ;
V_10 -> V_135 = F_51 ( V_150 ,
V_134 ) -> V_174 ;
V_10 -> V_137 = F_48 ( V_150 ) ;
if ( V_10 -> V_130 )
F_42 ( V_10 , V_144 ) ;
return 0 ;
}
static int F_52 ( struct V_145 * V_175 ,
int V_176 , unsigned int V_177 , int V_178 )
{
struct V_1 * V_2 = V_175 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
switch ( V_177 ) {
case 19200000 :
case 26000000 :
case 38400000 :
break;
default:
F_40 ( V_2 -> V_35 , L_9 , V_177 ) ;
return - V_115 ;
}
if ( ( V_177 / 1000 ) != V_10 -> V_88 ) {
F_40 ( V_2 -> V_35 ,
L_10 ,
V_177 , V_10 -> V_88 * 1000 ) ;
return - V_115 ;
}
return 0 ;
}
static int F_53 ( struct V_145 * V_175 ,
unsigned int V_179 )
{
struct V_1 * V_2 = V_175 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_153 , V_152 ;
V_153 = F_1 ( V_2 , V_81 ) ;
V_152 = V_153 ;
switch ( V_179 & V_180 ) {
case V_181 :
V_152 &= ~ ( V_182 ) ;
V_152 &= ~ ( V_183 ) ;
break;
case V_184 :
V_152 |= V_182 ;
V_152 |= V_183 ;
break;
default:
return - V_115 ;
}
V_152 &= ~ V_154 ;
switch ( V_179 & V_185 ) {
case V_186 :
V_152 |= V_187 ;
break;
case V_188 :
V_152 |= V_155 ;
break;
default:
return - V_115 ;
}
if ( V_152 != V_153 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_81 , V_152 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_81 , V_152 ) ;
}
}
return 0 ;
}
static int F_54 ( struct V_145 * V_146 , int V_189 )
{
struct V_1 * V_2 = V_146 -> V_2 ;
T_1 V_3 = F_1 ( V_2 , V_81 ) ;
if ( V_189 )
V_3 |= V_190 ;
else
V_3 &= ~ V_190 ;
return F_3 ( V_2 , V_81 , V_3 ) ;
}
static void F_55 ( struct V_1 * V_2 , int V_138 ,
int V_27 )
{
T_1 V_3 , V_102 ;
V_3 = F_1 ( V_2 , V_38 ) ;
if ( V_138 == V_139 )
V_102 = V_140 ;
else
V_102 = V_142 | V_143 ;
if ( V_27 )
V_3 |= V_102 ;
else
V_3 &= ~ V_102 ;
F_3 ( V_2 , V_38 , V_3 ) ;
}
static int F_56 ( struct V_126 * V_144 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_28 ;
if ( V_10 -> V_88 != 26000 ) {
F_40 ( V_2 -> V_35 ,
L_11 ,
V_168 , V_10 -> V_88 ) ;
return - V_115 ;
}
V_28 = F_1 ( V_2 , V_31 )
& V_191 ;
if ( V_28 != V_192 ) {
F_40 ( V_2 -> V_35 , L_12 ,
V_168 ) ;
return - V_115 ;
}
return 0 ;
}
static void F_57 ( struct V_126 * V_144 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_2 ;
F_55 ( V_2 , V_144 -> V_148 , 0 ) ;
}
static int F_58 ( struct V_126 * V_144 ,
struct V_149 * V_150 , struct V_145 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_151 , V_28 ;
F_55 ( V_2 , V_144 -> V_148 , 1 ) ;
V_151 = F_1 ( V_2 , V_31 )
& ~ ( V_156 ) ;
V_28 = V_151 ;
switch ( F_49 ( V_150 ) ) {
case 8000 :
V_28 &= ~ ( V_193 ) ;
break;
case 16000 :
V_28 |= V_193 ;
break;
default:
F_40 ( V_2 -> V_35 , L_7 , V_168 ,
F_49 ( V_150 ) ) ;
return - V_115 ;
}
if ( V_28 != V_151 ) {
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
static int F_59 ( struct V_145 * V_175 ,
int V_176 , unsigned int V_177 , int V_178 )
{
struct V_1 * V_2 = V_175 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_177 != 26000000 ) {
F_40 ( V_2 -> V_35 ,
L_11 ,
V_168 , V_177 / 1000 ) ;
return - V_115 ;
}
if ( ( V_177 / 1000 ) != V_10 -> V_88 ) {
F_40 ( V_2 -> V_35 ,
L_10 ,
V_177 , V_10 -> V_88 * 1000 ) ;
return - V_115 ;
}
return 0 ;
}
static int F_60 ( struct V_145 * V_175 ,
unsigned int V_179 )
{
struct V_1 * V_2 = V_175 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_153 , V_152 ;
V_153 = F_1 ( V_2 , V_194 ) ;
V_152 = V_153 ;
switch ( V_179 & V_180 ) {
case V_181 :
V_152 &= ~ ( V_195 ) ;
break;
case V_184 :
V_152 |= V_195 ;
break;
default:
return - V_115 ;
}
switch ( V_179 & V_196 ) {
case V_197 :
V_152 &= ~ ( V_198 ) ;
break;
case V_199 :
V_152 |= V_198 ;
break;
default:
return - V_115 ;
}
if ( V_152 != V_153 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_194 , V_152 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_194 , V_152 ) ;
}
}
return 0 ;
}
static int F_61 ( struct V_145 * V_146 , int V_189 )
{
struct V_1 * V_2 = V_146 -> V_2 ;
T_1 V_3 = F_1 ( V_2 , V_194 ) ;
if ( V_189 )
V_3 |= V_200 ;
else
V_3 &= ~ V_200 ;
return F_3 ( V_2 , V_194 , V_3 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
F_41 ( V_2 , V_125 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
F_41 ( V_2 , V_122 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_10 = F_65 ( sizeof( struct V_9 ) , V_201 ) ;
if ( V_10 == NULL ) {
F_40 ( V_2 -> V_35 , L_13 ) ;
return - V_202 ;
}
F_66 ( V_2 , V_10 ) ;
V_10 -> V_88 = F_67 () / 1000 ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
F_17 ( V_2 ) ;
F_41 ( V_2 , V_125 ) ;
F_69 ( V_10 ) ;
return 0 ;
}
static int T_2 F_70 ( struct V_203 * V_204 )
{
struct V_40 * V_41 = V_204 -> V_35 . V_83 ;
if ( ! V_41 ) {
F_40 ( & V_204 -> V_35 , L_14 ) ;
return - V_115 ;
}
return F_71 ( & V_204 -> V_35 , & V_205 ,
V_206 , F_72 ( V_206 ) ) ;
}
static int T_3 F_73 ( struct V_203 * V_204 )
{
F_74 ( & V_204 -> V_35 ) ;
return 0 ;
}
