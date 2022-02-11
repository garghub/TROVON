static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 = ( V_3 << 16 ) | V_3 ;
F_2 ( V_8 , V_6 -> V_9 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_3 << 16 , V_6 -> V_9 + V_4 ) ;
}
static bool F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
V_8 = F_5 ( V_6 -> V_9 + V_4 ) ;
return ( V_8 & V_3 ) ? true : false ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_1 ( V_2 , V_10 , V_11 ) ;
while ( ! F_4 ( V_2 , V_10 , V_11 ) )
;
while ( F_5 ( V_6 -> V_9 + V_12 ) & V_13 )
;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_15 | V_14 , V_6 -> V_9 + V_16 ) ;
F_6 ( V_2 ) ;
return F_5 ( V_6 -> V_9 + V_17 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_19 | V_14 , V_6 -> V_9 + V_16 ) ;
F_2 ( V_18 , V_6 -> V_9 + V_17 ) ;
F_6 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_20 , unsigned int V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
V_14 &= 0xffff ;
F_2 ( V_15 | V_14 , V_6 -> V_9 + V_16 ) ;
F_6 ( V_2 ) ;
F_2 ( V_19 | V_14 , V_6 -> V_9 + V_16 ) ;
V_8 = F_5 ( V_6 -> V_9 + V_17 ) ;
V_8 &= V_20 ;
V_8 |= V_18 ;
F_2 ( V_8 & 0xffff , V_6 -> V_9 + V_17 ) ;
F_6 ( V_2 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_21 ;
F_2 ( V_8 , V_6 -> V_9 + V_22 ) ;
F_1 ( V_2 , V_23 , V_11 ) ;
while ( ! F_4 ( V_2 , V_23 , V_11 ) )
;
do {
V_21 = F_5 ( V_6 -> V_9 + V_22 ) ;
} while ( ( V_21 & ( V_24 | V_25 ) ) == V_24 );
return V_21 & V_25 ;
}
static T_3 F_11 ( struct V_1 * V_2 , T_3 V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_10 ( V_2 , F_12 ( V_26 , V_27 )
| F_13 ( V_28 , V_14 )
| F_14 ( V_29 , 0 ) ) ) {
return 0 ;
}
if ( F_10 ( V_2 , F_12 ( V_26 , V_30 )
| F_13 ( V_28 , 0 )
| F_14 ( V_29 , 0 ) ) ) {
return 0 ;
}
return ( F_5 ( V_6 -> V_9 + V_22 ) >> 16 ) & 0xff ;
}
static void F_15 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_8 ( V_2 , V_31 , V_6 -> V_32 ) ;
* V_6 -> V_33 = V_8 ;
F_1 ( V_2 , V_34 , V_35 ) ;
F_2 ( V_36 , V_6 -> V_9 + V_37 ) ;
while ( F_5 ( V_6 -> V_9 + V_35 ) & V_34 )
;
F_2 ( V_38 | V_39 | V_40 , V_6 -> V_9 + F_16 ( 0 ) ) ;
while ( ! ( F_5 ( V_6 -> V_9 + V_41 ) & V_42 ) )
;
F_2 ( V_38 | V_43 | V_44 | V_40 | V_45 ,
V_6 -> V_9 + F_16 ( 0 ) ) ;
if ( F_5 ( V_6 -> V_9 + V_46 ) & 0xff000000 ) {
while ( F_5 ( V_6 -> V_9 + V_46 ) & 0xff000000 )
;
}
F_2 ( V_39 | V_40 | V_45 , V_6 -> V_9 + F_16 ( 0 ) ) ;
while ( ! ( F_5 ( V_6 -> V_9 + V_46 ) & 0xff000000 ) )
;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_47 , short V_48 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
register T_1 V_49 ;
register T_2 V_50 ;
V_49 = 1 << V_47 ;
if ( V_48 < 0 ) {
V_48 = - V_48 ;
V_6 -> V_32 |= V_49 ;
} else
V_6 -> V_32 &= ~ V_49 ;
if ( ( T_1 ) V_48 > 0x1FFF )
V_48 = 0x1FFF ;
V_50 = ( V_47 & 2 ) ? V_51 : V_52 ;
F_2 ( V_38 | V_53 | V_50 , V_6 -> V_9 + F_16 ( 2 ) ) ;
F_2 ( V_38 | V_54 | V_50 , V_6 -> V_9 + F_16 ( 3 ) ) ;
F_2 ( V_38 | V_55 | V_56 , V_6 -> V_9 + F_16 ( 4 ) ) ;
F_2 ( V_38 | V_43 | V_56 | V_45 , V_6 -> V_9 + F_16 ( 5 ) ) ;
F_15 ( V_2 , 0x0F000000
| 0x00004000
| ( ( T_2 ) ( V_47 & 1 ) << 15 )
| ( T_2 ) V_48 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_3 V_57 ,
T_3 V_58 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_47 ;
V_6 -> V_59 [ V_57 ] = ( T_3 ) V_58 ;
V_47 = ( T_2 ) V_60 [ V_57 ] ;
F_2 ( V_38 | V_53 | V_56 , V_6 -> V_9 + F_16 ( 2 ) ) ;
F_2 ( V_38 | V_54 | V_56 , V_6 -> V_9 + F_16 ( 3 ) ) ;
F_2 ( V_38 | V_55 | V_51 , V_6 -> V_9 + F_16 ( 4 ) ) ;
F_2 ( V_38 | V_43 | V_51 | V_45 , V_6 -> V_9 + F_16 ( 5 ) ) ;
F_15 ( V_2 , ( ( T_2 ) V_47 << 8 )
| ( T_2 ) V_58 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
register T_3 V_61 ;
for ( V_61 = 0 ; V_61 < F_20 ( V_60 ) ; V_61 ++ )
F_18 ( V_2 , V_61 , F_11 ( V_2 , V_62 [ V_61 ] ) ) ;
}
static T_2 F_21 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
register T_2 V_65 ;
V_65 = ( T_2 ) F_7 ( V_2 , V_64 -> V_66 ) ;
V_65 |= ( ( T_2 ) F_7 ( V_2 , V_64 -> V_66 + 2 ) << 16 ) ;
return V_65 ;
}
static void F_22 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_1 V_65 )
{
F_9 ( V_2 , V_64 -> V_67 ,
~ ( V_68 | V_69 ) ,
V_65 << V_70 ) ;
}
static void F_23 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_2 V_65 )
{
F_8 ( V_2 , ( T_1 ) ( V_64 -> V_66 ) , ( T_1 ) V_65 ) ;
F_8 ( V_2 , ( T_1 ) ( V_64 -> V_66 + 2 ) ,
( T_1 ) ( V_65 >> 16 ) ) ;
}
static unsigned int F_24 ( int V_71 )
{
unsigned int V_72 ;
V_72 = ( V_71 >> 18 ) ;
if ( V_72 & 0x2000 )
V_72 &= 0x1fff ;
else
V_72 += ( 1 << 13 ) ;
return V_72 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned int V_47 )
{
unsigned int V_73 = V_47 / 16 ;
unsigned int V_20 = 1 << ( V_47 - ( 16 * V_73 ) ) ;
unsigned int V_74 ;
V_74 = F_7 ( V_2 , F_26 ( V_73 ) ) ;
F_8 ( V_2 , F_27 ( V_73 ) , V_20 | V_74 ) ;
V_74 = F_7 ( V_2 , F_28 ( V_73 ) ) ;
F_8 ( V_2 , F_29 ( V_73 ) , V_20 | V_74 ) ;
F_8 ( V_2 , V_75 , V_76 ) ;
V_74 = F_7 ( V_2 , F_30 ( V_73 ) ) ;
F_8 ( V_2 , F_31 ( V_73 ) , V_20 | V_74 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int V_73 ,
unsigned int V_20 )
{
F_8 ( V_2 , V_75 , V_77 ) ;
F_8 ( V_2 , F_31 ( V_73 ) , V_20 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
F_8 ( V_2 , V_75 , V_77 ) ;
for ( V_73 = 0 ; V_73 < V_78 ; V_73 ++ )
F_8 ( V_2 , F_31 ( V_73 ) , 0xffff ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 ,
T_1 V_79 , T_3 V_73 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_80 * V_81 = V_2 -> V_82 ;
struct V_83 * V_3 = & V_81 -> V_84 -> V_3 ;
F_32 ( V_2 , V_73 , V_79 ) ;
if ( V_6 -> V_85 ) {
if ( ( V_79 >> ( V_3 -> V_86 - ( 16 * V_73 ) ) ) == 1 &&
V_3 -> V_87 == V_88 ) {
F_1 ( V_2 , V_89 , V_35 ) ;
if ( V_3 -> V_90 == V_88 )
F_25 ( V_2 , V_3 -> V_91 ) ;
}
if ( ( V_79 >> ( V_3 -> V_91 - ( 16 * V_73 ) ) ) == 1 &&
V_3 -> V_90 == V_88 ) {
F_1 ( V_2 , V_92 , V_11 ) ;
if ( V_3 -> V_93 == V_88 ) {
V_6 -> V_94 = V_3 -> V_95 ;
F_25 ( V_2 , V_3 -> V_96 ) ;
}
if ( V_3 -> V_93 == V_97 ) {
struct V_63 * V_64 = & V_98 [ 5 ] ;
V_6 -> V_94 = V_3 -> V_95 ;
V_64 -> V_99 ( V_2 , V_64 , V_100 ) ;
}
}
if ( ( V_79 >> ( V_3 -> V_96 - ( 16 * V_73 ) ) ) == 1 &&
V_3 -> V_93 == V_88 ) {
F_1 ( V_2 , V_92 , V_11 ) ;
V_6 -> V_94 -- ;
if ( V_6 -> V_94 > 0 )
F_25 ( V_2 , V_3 -> V_96 ) ;
}
}
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_79 ;
T_3 V_73 ;
for ( V_73 = 0 ; V_73 < V_78 ; V_73 ++ ) {
V_79 = 0 ;
V_79 = F_7 ( V_2 , F_36 ( V_73 ) ) ;
if ( V_79 ) {
F_34 ( V_2 , V_79 , V_73 ) ;
return;
}
}
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_80 * V_81 = V_2 -> V_82 ;
struct V_101 * V_84 = V_81 -> V_84 ;
struct V_83 * V_3 = & V_84 -> V_3 ;
struct V_63 * V_64 ;
T_1 V_79 ;
V_79 = F_7 ( V_2 , V_102 ) ;
if ( V_79 & V_103 ) {
V_64 = & V_98 [ 0 ] ;
V_64 -> V_104 ( V_2 , V_64 ) ;
}
if ( V_79 & V_105 ) {
V_64 = & V_98 [ 1 ] ;
V_64 -> V_104 ( V_2 , V_64 ) ;
}
if ( V_79 & V_106 ) {
V_64 = & V_98 [ 2 ] ;
V_64 -> V_104 ( V_2 , V_64 ) ;
}
if ( V_79 & V_107 ) {
V_64 = & V_98 [ 3 ] ;
V_64 -> V_104 ( V_2 , V_64 ) ;
}
if ( V_79 & V_108 ) {
V_64 = & V_98 [ 4 ] ;
V_64 -> V_104 ( V_2 , V_64 ) ;
if ( V_6 -> V_94 > 0 ) {
V_6 -> V_94 -- ;
if ( V_6 -> V_94 == 0 )
V_64 -> V_99 ( V_2 , V_64 , V_109 ) ;
if ( V_3 -> V_93 == V_97 ) {
F_1 ( V_2 , V_92 , V_11 ) ;
}
}
}
if ( V_79 & V_110 ) {
V_64 = & V_98 [ 5 ] ;
V_64 -> V_104 ( V_2 , V_64 ) ;
if ( V_3 -> V_90 == V_97 ) {
F_1 ( V_2 , V_92 , V_11 ) ;
}
if ( V_3 -> V_93 == V_97 ) {
V_64 = & V_98 [ 4 ] ;
V_6 -> V_94 = V_3 -> V_95 ;
V_64 -> V_99 ( V_2 , V_64 , V_100 ) ;
}
}
}
static bool F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_80 * V_81 = V_2 -> V_82 ;
struct V_101 * V_84 = V_81 -> V_84 ;
struct V_83 * V_3 = & V_84 -> V_3 ;
T_4 * V_111 = ( T_4 * ) V_6 -> V_112 . V_113 + 1 ;
bool V_114 = false ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_3 -> V_95 ; V_61 ++ ) {
short V_72 ;
V_72 = F_24 ( ( int ) * V_111 ) ;
V_111 ++ ;
F_39 ( V_81 , V_72 ) ;
}
V_84 -> V_115 |= V_116 ;
if ( ! V_6 -> V_117 )
V_6 -> V_118 -- ;
if ( V_6 -> V_118 <= 0 ) {
V_6 -> V_85 = 0 ;
F_3 ( V_2 , V_89 , V_35 ) ;
V_84 -> V_115 |= V_119 ;
V_114 = true ;
}
if ( V_6 -> V_85 && V_3 -> V_90 == V_88 )
F_25 ( V_2 , V_3 -> V_91 ) ;
F_40 ( V_2 , V_81 ) ;
return V_114 ;
}
static T_5 F_41 ( int V_120 , void * V_121 )
{
struct V_1 * V_2 = V_121 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_122 ;
T_2 V_123 , V_124 ;
if ( ! V_2 -> V_125 )
return V_126 ;
F_42 ( & V_2 -> V_127 , V_122 ) ;
V_124 = F_5 ( V_6 -> V_9 + V_128 ) ;
V_123 = F_5 ( V_6 -> V_9 + V_37 ) ;
F_2 ( 0 , V_6 -> V_9 + V_128 ) ;
F_2 ( V_123 , V_6 -> V_9 + V_37 ) ;
switch ( V_123 ) {
case V_129 :
if ( F_38 ( V_2 ) )
V_124 = 0 ;
break;
case V_130 :
F_35 ( V_2 ) ;
F_37 ( V_2 ) ;
break;
}
F_2 ( V_124 , V_6 -> V_9 + V_128 ) ;
F_43 ( & V_2 -> V_127 , V_122 ) ;
return V_131 ;
}
static void F_44 ( struct V_1 * V_2 , T_3 * V_132 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
register T_2 * V_133 ;
T_2 V_134 ;
T_1 V_61 ;
T_1 V_135 ;
T_2 V_136 ;
struct V_83 * V_3 = & ( V_2 -> V_137 -> V_84 -> V_3 ) ;
F_3 ( V_2 , V_89 , V_35 ) ;
V_133 = ( T_2 * ) V_6 -> V_138 . V_113 ;
F_2 ( ( T_2 ) V_6 -> V_138 . V_139 ,
V_6 -> V_9 + V_140 ) ;
if ( V_3 != NULL && V_3 -> V_90 != V_141 ) {
* V_133 ++ = V_142 | V_143 ;
* V_133 ++ = V_144 | V_143 ;
}
* V_133 ++ = V_145 | ( V_16 >> 2 ) ;
* V_133 ++ = V_19 | V_146 ;
* V_133 ++ = V_145 | ( V_17 >> 2 ) ;
* V_133 ++ = V_147 ;
* V_133 ++ = V_144 | V_148 ;
* V_133 ++ = V_149 | V_148 ;
* V_133 ++ = V_142 | V_148 ;
for ( V_6 -> V_150 = 0 ; V_6 -> V_150 < 16 ; V_6 -> V_150 ++ ) {
V_136 =
( * V_132 << 8 ) | ( * V_132 & 0x10 ? V_147 :
V_151 ) ;
* V_133 ++ = V_145 | ( V_16 >> 2 ) ;
* V_133 ++ = V_19 | V_146 ;
* V_133 ++ = V_145 | ( V_17 >> 2 ) ;
* V_133 ++ = V_136 ;
* V_133 ++ = V_144 | V_148 ;
* V_133 ++ = V_149 | V_148 ;
* V_133 ++ = V_142 | V_148 ;
* V_133 ++ = V_145 | ( V_16 >> 2 ) ;
* V_133 ++ = V_19 | V_152 ;
* V_133 ++ = V_145 | ( V_17 >> 2 ) ;
* V_133 ++ = V_136 ;
* V_133 ++ = V_144 | V_148 ;
* V_133 ++ = V_149 | V_148 ;
* V_133 ++ = V_142 | V_148 ;
V_134 =
( T_2 ) V_6 -> V_138 . V_139 +
( T_2 ) ( ( unsigned long ) V_133 -
( unsigned long ) V_6 -> V_138 . V_113 ) ;
for ( V_61 = 0 ; V_61 < ( 10 * V_153 / 2 ) ; V_61 ++ ) {
V_134 += 8 ;
* V_133 ++ = V_154 ;
* V_133 ++ = V_134 ;
}
if ( V_3 != NULL && V_3 -> V_93 != V_155 ) {
* V_133 ++ = V_142 | V_143 ;
* V_133 ++ = V_144 | V_143 ;
}
* V_133 ++ = V_145 | ( V_156 >> 2 ) ;
* V_133 ++ = V_157 | V_158 ;
* V_133 ++ = V_159 ;
* V_133 ++ = V_145 | ( V_156 >> 2 ) ;
* V_133 ++ = V_157 | V_160 ;
* V_133 ++ = V_142 | V_161 ;
* V_133 ++ = V_162 | ( F_45 ( V_163 ) >> 2 ) ;
* V_133 ++ =
( T_2 ) V_6 -> V_112 . V_139 +
( V_6 -> V_150 << 2 ) ;
if ( * V_132 ++ & V_164 ) {
V_6 -> V_150 ++ ;
break;
}
}
for ( V_135 = 0 ; V_135 < ( 2 * V_153 ) ; V_135 ++ )
* V_133 ++ = V_159 ;
* V_133 ++ = V_145 | ( V_156 >> 2 ) ;
* V_133 ++ = V_157 | V_158 ;
* V_133 ++ = V_159 ;
* V_133 ++ = V_145 | ( V_156 >> 2 ) ;
* V_133 ++ = V_157 | V_160 ;
* V_133 ++ = V_142 | V_161 ;
* V_133 ++ = V_162 | ( F_45 ( V_163 ) >> 2 ) ;
* V_133 ++ =
( T_2 ) V_6 -> V_112 . V_139 + ( V_6 -> V_150 << 2 ) ;
if ( V_6 -> V_85 == 1 ) {
* V_133 ++ = V_165 ;
}
* V_133 ++ = V_154 ;
* V_133 ++ = ( T_2 ) V_6 -> V_138 . V_139 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_166 * V_167 ,
unsigned int * V_71 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
register T_3 V_61 ;
register T_4 * V_111 ;
F_1 ( V_2 , V_92 , V_11 ) ;
while ( F_4 ( V_2 , V_92 , V_11 ) )
;
V_111 = ( T_2 * ) V_6 -> V_112 . V_113 + 1 ;
for ( V_61 = 0 ; V_61 < V_6 -> V_150 ; V_61 ++ ) {
* V_71 = F_24 ( * V_111 ++ ) ;
V_71 ++ ;
}
return V_61 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_166 * V_167 , unsigned int * V_71 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_47 = F_48 ( V_167 -> V_168 ) ;
T_1 V_169 = F_49 ( V_167 -> V_168 ) ;
T_1 V_170 = 0 ;
T_2 V_171 ;
int V_172 ;
int V_135 ;
if ( V_169 == 0 )
V_170 = ( V_47 << 8 ) | ( V_147 ) ;
else
V_170 = ( V_47 << 8 ) | ( V_151 ) ;
F_8 ( V_2 , V_146 , V_170 ) ;
F_8 ( V_2 , V_152 , V_170 ) ;
for ( V_135 = 0 ; V_135 < V_167 -> V_135 ; V_135 ++ ) {
F_50 ( 10 ) ;
V_171 = F_5 ( V_6 -> V_9 + V_156 ) ;
F_2 ( V_171 & ~ V_160 , V_6 -> V_9 + V_156 ) ;
F_2 ( V_171 & ~ V_160 , V_6 -> V_9 + V_156 ) ;
F_2 ( V_171 & ~ V_160 , V_6 -> V_9 + V_156 ) ;
F_2 ( V_171 | V_160 , V_6 -> V_9 + V_156 ) ;
while ( ! ( F_5 ( V_6 -> V_9 + V_12 ) & V_173 ) )
;
if ( V_135 != 0 ) {
V_172 = F_5 ( V_6 -> V_9 + V_163 ) ;
V_71 [ V_135 - 1 ] = F_24 ( V_172 ) ;
}
F_50 ( 4 ) ;
}
V_171 = F_5 ( V_6 -> V_9 + V_156 ) ;
F_2 ( V_171 & ~ V_160 , V_6 -> V_9 + V_156 ) ;
F_2 ( V_171 & ~ V_160 , V_6 -> V_9 + V_156 ) ;
F_2 ( V_171 & ~ V_160 , V_6 -> V_9 + V_156 ) ;
F_2 ( V_171 | V_160 , V_6 -> V_9 + V_156 ) ;
while ( ! ( F_5 ( V_6 -> V_9 + V_12 ) & V_173 ) )
;
if ( V_135 != 0 ) {
V_172 = F_5 ( V_6 -> V_9 + V_163 ) ;
V_71 [ V_135 - 1 ] = F_24 ( V_172 ) ;
}
return V_135 ;
}
static int F_51 ( T_3 * V_132 , struct V_83 * V_3 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_3 -> V_95 ; V_135 ++ ) {
if ( F_49 ( ( V_3 -> V_174 ) [ V_135 ] ) == 0 )
V_132 [ V_135 ] = ( F_48 ( ( V_3 -> V_174 ) [ V_135 ] ) ) | ( V_175 ) ;
else
V_132 [ V_135 ] = ( F_48 ( ( V_3 -> V_174 ) [ V_135 ] ) ) | ( V_176 ) ;
}
if ( V_135 != 0 )
V_132 [ V_135 - 1 ] |= V_164 ;
return V_135 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_80 * V_81 , unsigned int V_177 )
{
if ( V_177 != 0 )
return - V_178 ;
F_1 ( V_2 , V_89 , V_35 ) ;
V_81 -> V_84 -> V_179 = NULL ;
return 1 ;
}
static int F_53 ( int * V_180 , int V_181 )
{
int V_182 , V_183 ;
V_183 = 500 ;
switch ( V_181 ) {
case V_184 :
default:
V_182 = ( * V_180 + V_183 / 2 ) / V_183 ;
break;
case V_185 :
V_182 = ( * V_180 ) / V_183 ;
break;
case V_186 :
V_182 = ( * V_180 + V_183 - 1 ) / V_183 ;
break;
}
* V_180 = V_183 * V_182 ;
return V_182 - 1 ;
}
static void F_54 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_187 )
{
T_1 V_188 = ( V_189 << V_190 ) |
( V_191 << V_192 ) |
( V_193 << V_194 ) |
( V_195 << V_196 ) |
( V_197 << V_196 ) |
( V_198 << V_199 ) |
( V_109 << V_200 ) ;
T_1 V_201 = V_202 ;
V_64 -> V_203 ( V_2 , V_64 , V_188 , FALSE ) ;
F_23 ( V_2 , V_64 , V_187 ) ;
V_64 -> V_204 ( V_2 , V_64 , 0 ) ;
V_64 -> V_205 ( V_2 , V_64 ) ;
V_64 -> V_204 ( V_2 , V_64 , 1 ) ;
V_64 -> V_206 ( V_2 , V_64 , V_207 ) ;
F_22 ( V_2 , V_64 , V_201 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_132 [ 16 ] ;
struct V_83 * V_3 = & V_81 -> V_84 -> V_3 ;
struct V_63 * V_64 ;
int V_187 ;
if ( V_6 -> V_85 ) {
F_56 ( V_208 L_1 ,
V_2 -> V_209 ) ;
return - V_210 ;
}
F_2 ( 0 , V_6 -> V_9 + V_128 ) ;
F_2 ( V_129 | V_130 , V_6 -> V_9 + V_37 ) ;
F_33 ( V_2 ) ;
V_6 -> V_85 = 0 ;
if ( V_3 == NULL )
return - V_178 ;
if ( V_2 -> V_120 == 0 ) {
F_57 ( V_2 ,
L_2 ) ;
return - V_211 ;
}
F_51 ( V_132 , V_3 ) ;
V_6 -> V_85 = 1 ;
V_6 -> V_94 = 0 ;
switch ( V_3 -> V_90 ) {
case V_141 :
break;
case V_97 :
V_64 = & V_98 [ 5 ] ;
V_187 = F_53 ( ( int * ) & V_3 -> V_91 ,
V_3 -> V_122 & V_212 ) ;
F_54 ( V_2 , V_64 , V_187 ) ;
V_64 -> V_99 ( V_2 , V_64 , V_100 ) ;
break;
case V_88 :
if ( V_3 -> V_87 != V_88 )
F_25 ( V_2 , V_3 -> V_91 ) ;
break;
}
switch ( V_3 -> V_93 ) {
case V_155 :
break;
case V_97 :
V_64 = & V_98 [ 4 ] ;
V_187 = F_53 ( ( int * ) & V_3 -> V_96 ,
V_3 -> V_122 & V_212 ) ;
F_54 ( V_2 , V_64 , V_187 ) ;
V_64 -> V_99 ( V_2 , V_64 , V_109 ) ;
break;
case V_88 :
if ( V_3 -> V_90 != V_88
&& V_3 -> V_87 == V_88 )
F_25 ( V_2 , V_3 -> V_96 ) ;
break;
}
switch ( V_3 -> V_213 ) {
case V_214 :
V_6 -> V_118 = V_3 -> V_215 ;
V_6 -> V_117 = 0 ;
break;
case V_216 :
V_6 -> V_117 = 1 ;
V_6 -> V_118 = 1 ;
break;
}
F_44 ( V_2 , V_132 ) ;
switch ( V_3 -> V_87 ) {
case V_155 :
F_1 ( V_2 , V_89 , V_35 ) ;
V_81 -> V_84 -> V_179 = NULL ;
break;
case V_88 :
F_25 ( V_2 , V_3 -> V_86 ) ;
V_81 -> V_84 -> V_179 = NULL ;
break;
case V_217 :
V_81 -> V_84 -> V_179 = F_52 ;
break;
}
F_2 ( V_130 | V_129 , V_6 -> V_9 + V_128 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_80 * V_81 , struct V_83 * V_3 )
{
int V_218 = 0 ;
int V_172 ;
V_218 |= F_59 ( & V_3 -> V_87 ,
V_155 | V_217 | V_88 ) ;
V_218 |= F_59 ( & V_3 -> V_90 ,
V_97 | V_88 | V_141 ) ;
V_218 |= F_59 ( & V_3 -> V_93 ,
V_97 | V_88 | V_155 ) ;
V_218 |= F_59 ( & V_3 -> V_219 , V_214 ) ;
V_218 |= F_59 ( & V_3 -> V_213 , V_214 | V_216 ) ;
if ( V_218 )
return 1 ;
V_218 |= F_60 ( V_3 -> V_87 ) ;
V_218 |= F_60 ( V_3 -> V_90 ) ;
V_218 |= F_60 ( V_3 -> V_93 ) ;
V_218 |= F_60 ( V_3 -> V_213 ) ;
if ( V_218 )
return 2 ;
if ( V_3 -> V_87 != V_88 )
V_218 |= F_61 ( & V_3 -> V_86 , 0 ) ;
if ( V_3 -> V_87 == V_88 )
V_218 |= F_62 ( & V_3 -> V_86 , 39 ) ;
if ( V_3 -> V_90 == V_88 )
V_218 |= F_62 ( & V_3 -> V_91 , 39 ) ;
if ( V_3 -> V_93 == V_88 )
V_218 |= F_62 ( & V_3 -> V_96 , 39 ) ;
#define F_63 200000
#define F_64 2000000000
if ( V_3 -> V_90 == V_97 ) {
V_218 |= F_65 ( & V_3 -> V_91 ,
F_63 ) ;
V_218 |= F_62 ( & V_3 -> V_91 ,
F_64 ) ;
} else {
}
if ( V_3 -> V_93 == V_97 ) {
V_218 |= F_65 ( & V_3 -> V_96 , F_63 ) ;
V_218 |= F_62 ( & V_3 -> V_96 , F_64 ) ;
} else {
}
V_218 |= F_61 ( & V_3 -> V_220 , V_3 -> V_95 ) ;
if ( V_3 -> V_213 == V_214 )
V_218 |= F_62 ( & V_3 -> V_215 , 0x00ffffff ) ;
else
V_218 |= F_61 ( & V_3 -> V_215 , 0 ) ;
if ( V_218 )
return 3 ;
if ( V_3 -> V_90 == V_97 ) {
V_172 = V_3 -> V_91 ;
F_53 ( ( int * ) & V_3 -> V_91 ,
V_3 -> V_122 & V_212 ) ;
if ( V_172 != V_3 -> V_91 )
V_218 ++ ;
}
if ( V_3 -> V_93 == V_97 ) {
V_172 = V_3 -> V_96 ;
F_53 ( ( int * ) & V_3 -> V_96 ,
V_3 -> V_122 & V_212 ) ;
if ( V_172 != V_3 -> V_96 )
V_218 ++ ;
if ( V_3 -> V_90 == V_97 &&
V_3 -> V_91 <
V_3 -> V_96 * V_3 -> V_220 ) {
V_3 -> V_91 =
V_3 -> V_96 * V_3 -> V_220 ;
V_218 ++ ;
}
}
if ( V_218 )
return 4 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_2 , V_89 , V_35 ) ;
F_2 ( 0 , V_6 -> V_9 + V_128 ) ;
V_6 -> V_85 = 0 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_80 * V_81 ,
struct V_166 * V_167 , unsigned int * V_71 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_61 ;
T_1 V_47 = F_48 ( V_167 -> V_168 ) ;
T_6 V_48 ;
for ( V_61 = 0 ; V_61 < V_167 -> V_135 ; V_61 ++ ) {
V_48 = ( T_6 ) V_71 [ V_61 ] ;
V_6 -> V_221 [ F_48 ( V_167 -> V_168 ) ] = V_71 [ V_61 ] ;
V_48 -= ( 0x1fff ) ;
F_17 ( V_2 , V_47 , V_48 ) ;
}
return V_61 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_80 * V_81 ,
struct V_166 * V_167 , unsigned int * V_71 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_167 -> V_135 ; V_61 ++ )
V_71 [ V_61 ] = V_6 -> V_221 [ F_48 ( V_167 -> V_168 ) ] ;
return V_61 ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_1 V_73 ;
F_8 ( V_2 , V_75 , V_77 ) ;
for ( V_73 = 0 ; V_73 < V_78 ; V_73 ++ ) {
F_8 ( V_2 , F_29 ( V_73 ) , 0 ) ;
F_8 ( V_2 , F_31 ( V_73 ) , 0xffff ) ;
F_8 ( V_2 , F_27 ( V_73 ) , 0 ) ;
F_8 ( V_2 , F_70 ( V_73 ) , 0 ) ;
}
}
static int F_71 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_166 * V_167 ,
unsigned int * V_71 )
{
unsigned long V_73 = ( unsigned long ) V_81 -> V_7 ;
unsigned long V_20 = V_71 [ 0 ] ;
unsigned long V_222 = V_71 [ 1 ] ;
if ( V_20 ) {
if ( ( V_81 -> V_223 & V_20 ) != V_20 )
return - V_211 ;
V_81 -> V_224 &= ~ V_20 ;
V_81 -> V_224 |= ( V_222 & V_20 ) ;
F_8 ( V_2 , F_70 ( V_73 ) , V_81 -> V_224 ) ;
}
V_71 [ 1 ] = F_7 ( V_2 , F_72 ( V_73 ) ) ;
return V_167 -> V_135 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_166 * V_167 ,
unsigned int * V_71 )
{
unsigned long V_73 = ( unsigned long ) V_81 -> V_7 ;
int V_225 ;
V_225 = F_74 ( V_2 , V_81 , V_167 , V_71 , 0 ) ;
if ( V_225 )
return V_225 ;
F_8 ( V_2 , F_70 ( V_73 ) , V_81 -> V_223 ) ;
return V_167 -> V_135 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_166 * V_167 , unsigned int * V_71 )
{
T_1 V_188 = ( V_189 << V_190 ) |
( V_191 << V_192 ) |
( V_226 << V_194 ) |
( V_195 << V_196 ) |
( V_198 << V_199 ) |
( V_109 << V_200 ) ;
T_1 V_201 = V_227 ;
T_1 V_228 = V_100 ;
struct V_63 * V_64 = & V_98 [ F_48 ( V_167 -> V_168 ) ] ;
V_64 -> V_203 ( V_2 , V_64 , V_188 , TRUE ) ;
F_23 ( V_2 , V_64 , V_71 [ 0 ] ) ;
V_64 -> V_205 ( V_2 , V_64 ) ;
F_22 ( V_2 , V_64 , V_201 ) ;
V_64 -> V_99 ( V_2 , V_64 , ( T_1 ) ( V_228 != 0 ) ) ;
return V_167 -> V_135 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_166 * V_167 , unsigned int * V_71 )
{
int V_135 ;
struct V_63 * V_64 = & V_98 [ F_48 ( V_167 -> V_168 ) ] ;
for ( V_135 = 0 ; V_135 < V_167 -> V_135 ; V_135 ++ )
V_71 [ V_135 ] = F_21 ( V_2 , V_64 ) ;
return V_135 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
struct V_166 * V_167 , unsigned int * V_71 )
{
struct V_63 * V_64 = & V_98 [ F_48 ( V_167 -> V_168 ) ] ;
F_23 ( V_2 , V_64 , V_71 [ 0 ] ) ;
V_64 -> V_204 ( V_2 , V_64 , 0 ) ;
V_64 -> V_205 ( V_2 , V_64 ) ;
V_64 -> V_204 ( V_2 , V_64 , 2 ) ;
return 1 ;
}
static void F_78 ( struct V_1 * V_2 , T_1 V_229 )
{
F_8 ( V_2 , V_75 , V_230 ) ;
F_8 ( V_2 , V_231 , V_229 ) ;
F_8 ( V_2 , V_75 , V_232 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_233 * V_234 ,
T_7 V_235 )
{
struct V_236 * V_237 = F_80 ( V_2 ) ;
void * V_238 ;
T_8 V_239 ;
if ( V_234 == NULL )
return;
V_238 = V_234 -> V_113 ;
V_239 = V_234 -> V_139 ;
if ( V_238 ) {
F_81 ( V_237 , V_235 , V_238 , V_239 ) ;
V_234 -> V_113 = NULL ;
V_234 -> V_139 = 0 ;
}
}
static void F_82 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
F_9 ( V_2 , V_64 -> V_67 , ~ V_68 ,
V_240 | V_241 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
F_9 ( V_2 , V_64 -> V_67 , ~ V_68 ,
V_240 | V_242 ) ;
}
static T_1 F_84 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
register T_1 V_243 ;
register T_1 V_244 ;
register T_1 V_245 ;
V_243 = F_7 ( V_2 , V_64 -> V_246 ) ;
V_244 = F_7 ( V_2 , V_64 -> V_67 ) ;
V_245 = ( ( V_243 & V_247 )
| ( ( V_244 << ( V_248 - V_70 ) ) & V_249 )
| ( ( V_243 << ( V_250 - V_251 ) ) & V_252 )
| ( ( V_243 << ( V_253 - ( V_254 + 1 ) ) ) & V_255 )
| ( ( V_243 >> ( V_256 - V_257 ) ) & V_258 )
| ( ( V_244 >> ( V_259 - V_260 ) ) & V_261 ) ) ;
if ( V_243 & ( 2 << V_262 ) )
V_245 |= ( ( V_193 << V_263 )
| ( ( V_243 << ( V_264 - V_262 ) ) & V_265 )
| ( V_266 << V_267 ) ) ;
else
V_245 |= ( ( V_226 << V_263 )
| ( ( V_243 >> ( V_268 - V_264 ) ) & V_265 )
| ( ( ( V_243 & V_269 ) == ( V_270 << V_271 ) ) ?
( V_266 << V_267 ) :
( ( V_243 >> ( V_271 -
V_267 ) ) & V_272 ) ) ) ;
return V_245 ;
}
static T_1 F_85 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
register T_1 V_243 ;
register T_1 V_244 ;
register T_1 V_245 ;
V_243 = F_7 ( V_2 , V_64 -> V_246 ) ;
V_244 = F_7 ( V_2 , V_64 -> V_67 ) ;
V_245 = ( ( ( V_244 << ( V_250 - V_273 ) ) & V_252 )
| ( ( V_244 << ( V_248 - V_70 ) ) & V_249 )
| ( ( V_244 << ( V_274 - V_275 ) ) & V_247 )
| ( ( V_244 << ( V_257 - V_276 ) ) & V_258 )
| ( ( V_244 >> ( V_277 - V_260 ) ) & V_261 )
| ( ( V_243 >> ( ( V_278 + 1 ) - V_253 ) ) & V_255 ) ) ;
if ( ( V_244 & V_279 ) == ( V_270 << V_280 ) )
V_245 |= ( ( V_281 << V_263 )
| ( V_266 << V_267 )
| ( ( V_243 >> ( V_282 - V_264 ) ) & V_265 ) ) ;
else if ( V_243 & ( 2 << V_282 ) )
V_245 |= ( ( V_193 << V_263 )
| ( V_266 << V_267 )
| ( ( V_243 >> ( V_282 - V_264 ) ) & V_265 ) ) ;
else
V_245 |= ( ( V_226 << V_263 )
| ( ( V_244 >> ( V_280 - V_267 ) ) & V_272 )
| ( ( V_244 << ( V_264 - V_283 ) ) & V_265 ) ) ;
return V_245 ;
}
static void F_86 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_1 V_188 , T_1 V_284 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
register T_1 V_243 ;
register T_1 V_244 ;
register T_1 V_245 = V_188 ;
V_243 = ( ( V_245 & V_285 )
| ( ( V_245 & V_255 ) >> ( V_253 - ( V_254 + 1 ) ) ) ) ;
V_244 = ( V_240 | V_241
| ( ( V_245 & V_261 ) << ( V_259 - V_260 ) ) ) ;
if ( ! V_284 )
V_243 |= ( ( V_245 & V_252 ) >> ( V_250 -
V_251 ) ) ;
switch ( ( V_245 & V_286 ) >> V_263 ) {
case V_281 :
case V_193 :
V_243 |= ( ( 2 << V_262 )
| ( ( V_245 & V_265 ) >> ( V_264 - V_262 ) )
| ( 1 << V_268 )
| ( V_266 << V_271 ) ) ;
break;
default:
V_243 |= ( V_226
| ( ( V_245 & V_265 ) << ( V_268 - V_264 ) )
| ( ( ( V_245 & V_272 ) == ( V_270 << V_267 ) ) ?
( V_266 << V_271 ) :
( ( V_245 & V_272 ) << ( V_271 -
V_267 ) ) ) ) ;
}
if ( ~ V_245 & V_255 )
V_243 |= ( ( V_245 & V_258 ) << ( V_256 -
V_257 ) ) ;
if ( V_284 )
V_6 -> V_287 &= ~ V_64 -> V_288 [ 3 ] ;
F_9 ( V_2 , V_64 -> V_246 , V_289 | V_290 , V_243 ) ;
F_9 ( V_2 , V_64 -> V_67 , ~ ( V_68 | V_291 ) , V_244 ) ;
}
static void F_87 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_1 V_188 , T_1 V_284 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
register T_1 V_243 ;
register T_1 V_244 ;
register T_1 V_245 = V_188 ;
V_243 = ( ( V_245 & V_255 ) << ( ( V_278 + 1 ) - V_253 ) ) ;
V_244 = ( V_240 | V_242
| ( ( V_245 & V_261 ) << ( V_277 - V_260 ) )
| ( ( V_245 & V_247 ) >> ( V_274 - V_275 ) ) ) ;
if ( ! V_284 )
V_244 |= ( ( V_245 & V_252 ) >> ( V_250 -
V_273 ) ) ;
switch ( ( V_245 & V_286 ) >> V_263 ) {
case V_193 :
V_243 |= ( ( 2 << V_282 )
| ( ( V_245 & V_265 ) << ( V_282 - V_264 ) ) ) ;
V_244 |= ( ( 1 << V_283 )
| ( V_266 << V_280 ) ) ;
break;
case V_281 :
V_243 |= ( ( 2 << V_282 )
| ( ( V_245 & V_265 ) << ( V_282 - V_264 ) ) ) ;
V_244 |= ( ( 1 << V_283 )
| ( V_270 << V_280 ) ) ;
break;
default:
V_243 |= ( V_226 << V_282 ) ;
V_244 |= ( ( ( V_245 & V_265 ) >> ( V_264 - V_283 ) )
| ( ( ( V_245 & V_272 ) == ( V_270 << V_267 ) ) ?
( V_266 << V_280 ) :
( ( V_245 & V_272 ) << ( V_280 -
V_267 ) ) ) ) ;
}
if ( ~ V_245 & V_255 )
V_244 |= ( ( V_245 & V_258 ) >> ( V_257 -
V_276 ) ) ;
if ( V_284 )
V_6 -> V_287 &= ~ V_64 -> V_288 [ 3 ] ;
F_9 ( V_2 , V_64 -> V_246 , ~ ( V_289 | V_290 ) , V_243 ) ;
F_9 ( V_2 , V_64 -> V_67 , V_291 | V_69 , V_244 ) ;
}
static void F_88 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_1 V_228 )
{
F_9 ( V_2 , V_64 -> V_67 , ~ ( V_68 | V_291 ) ,
V_228 << V_259 ) ;
}
static void F_89 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_1 V_228 )
{
F_9 ( V_2 , V_64 -> V_67 , ~ ( V_68 | V_292 ) ,
V_228 << V_277 ) ;
}
static T_1 F_90 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
return ( F_7 ( V_2 , V_64 -> V_67 ) >> V_259 ) & 1 ;
}
static T_1 F_91 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
return ( F_7 ( V_2 , V_64 -> V_67 ) >> V_277 ) & 1 ;
}
static void F_92 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_1 V_293 )
{
F_9 ( V_2 , V_64 -> V_246 , ~ V_285 ,
V_293 << V_294 ) ;
}
static void F_93 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_1 V_293 )
{
F_9 ( V_2 , V_64 -> V_67 , ~ ( V_295 | V_68 ) ,
V_293 << V_275 ) ;
}
static T_1 F_94 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
return ( F_7 ( V_2 , V_64 -> V_246 ) >> V_294 ) & 3 ;
}
static T_1 F_95 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
return ( F_7 ( V_2 , V_64 -> V_67 ) >> V_275 ) & 3 ;
}
static void F_96 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_1 V_296 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_9 ( V_2 , V_64 -> V_67 , ~ V_68 ,
V_240 | V_241 ) ;
F_9 ( V_2 , V_64 -> V_246 , ~ V_297 ,
V_296 << V_251 ) ;
V_6 -> V_287 =
( V_6 -> V_287 & ~ V_64 ->
V_288 [ 3 ] ) | V_64 -> V_288 [ V_296 ] ;
}
static void F_97 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_1 V_296 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_244 ;
V_244 = F_7 ( V_2 , V_64 -> V_67 ) & ~ V_68 ;
F_8 ( V_2 , V_64 -> V_67 ,
( T_1 ) ( V_244 | V_240 | V_242 ) ) ;
F_8 ( V_2 , V_64 -> V_67 ,
( T_1 ) ( ( V_244 & ~ V_298 ) | ( V_296 <<
V_273 ) ) ) ;
V_6 -> V_287 =
( V_6 -> V_287 & ~ V_64 ->
V_288 [ 3 ] ) | V_64 -> V_288 [ V_296 ] ;
}
static T_1 F_98 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
return ( F_7 ( V_2 , V_64 -> V_246 ) >> V_251 ) & 3 ;
}
static T_1 F_99 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
return ( F_7 ( V_2 , V_64 -> V_67 ) >> V_273 ) & 3 ;
}
static void F_100 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
register T_1 V_243 ;
V_243 = F_7 ( V_2 , V_64 -> V_246 ) ;
F_8 ( V_2 , V_64 -> V_246 , ( T_1 ) ( V_243 ^ V_299 ) ) ;
F_8 ( V_2 , V_64 -> V_246 , V_243 ) ;
}
static void F_101 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
register T_1 V_244 ;
V_244 = F_7 ( V_2 , V_64 -> V_67 ) & ~ V_68 ;
F_8 ( V_2 , V_64 -> V_67 , ( T_1 ) ( V_244 ^ V_300 ) ) ;
F_8 ( V_2 , V_64 -> V_67 , V_244 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
int V_47 ;
struct V_63 * V_64 ;
T_1 V_188 = ( V_189 << V_190 ) |
( V_191 << V_192 ) |
( V_226 << V_194 ) |
( V_195 << V_196 ) |
( V_301 << V_196 ) |
( V_198 << V_199 ) |
( V_109 << V_200 ) ;
for ( V_47 = 0 ; V_47 < V_302 ; V_47 ++ ) {
V_64 = & V_98 [ V_47 ] ;
V_64 -> V_203 ( V_2 , V_64 , V_188 , TRUE ) ;
V_64 -> V_206 ( V_2 , V_64 , 0 ) ;
V_64 -> V_104 ( V_2 , V_64 ) ;
V_64 -> V_99 ( V_2 , V_64 , V_100 ) ;
}
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_236 * V_237 = F_80 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
void * V_14 ;
T_8 V_303 ;
V_14 = F_104 ( V_237 , V_304 , & V_303 ) ;
if ( ! V_14 )
return - V_305 ;
V_6 -> V_112 . V_113 = V_14 ;
V_6 -> V_112 . V_139 = V_303 ;
V_14 = F_104 ( V_237 , V_304 , & V_303 ) ;
if ( ! V_14 )
return - V_305 ;
V_6 -> V_138 . V_113 = V_14 ;
V_6 -> V_138 . V_139 = V_303 ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_8 V_306 ;
T_1 V_47 ;
int V_61 ;
F_1 ( V_2 , V_307 | V_308 | V_309 , V_35 ) ;
F_2 ( V_310 |
( V_311 << V_312 ) |
V_313 | V_314 ,
V_6 -> V_9 + V_315 ) ;
F_2 ( V_316 , V_6 -> V_9 + V_317 ) ;
F_2 ( V_157 | V_160 , V_6 -> V_9 + V_156 ) ;
V_6 -> V_318 = 0xA0 ;
F_2 ( V_319 | V_320 , V_6 -> V_9 + V_321 ) ;
F_1 ( V_2 , V_23 , V_11 ) ;
while ( ! ( F_5 ( V_6 -> V_9 + V_11 ) & V_23 ) )
;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
F_2 ( V_319 , V_6 -> V_9 + V_321 ) ;
F_1 ( V_2 , V_23 , V_11 ) ;
while ( ! F_4 ( V_2 , V_23 , V_11 ) )
;
}
F_2 ( V_322 , V_6 -> V_9 + V_323 ) ;
F_2 ( V_324 | V_325 , V_6 -> V_9 + V_326 ) ;
F_2 ( V_324 | V_325 | V_45 , V_6 -> V_9 + V_326 + 4 ) ;
F_2 ( V_327 , V_6 -> V_9 + V_328 ) ;
F_2 ( ( T_2 ) V_6 -> V_138 . V_139 ,
V_6 -> V_9 + V_140 ) ;
F_2 ( 0 , V_6 -> V_9 + V_329 ) ;
F_2 ( 0 , V_6 -> V_9 + V_330 ) ;
#if 0
{
uint8_t PollList;
uint16_t AdcData;
uint16_t StartVal;
uint16_t index;
unsigned int data[16];
PollList = EOPL;
ResetADC(dev, &PollList);
s626_ai_rinsn(dev, dev->subdevices, NULL, data);
StartVal = data[0];
for (index = 0; index < 500; index++) {
s626_ai_rinsn(dev, dev->subdevices, NULL, data);
AdcData = data[0];
if (AdcData != StartVal)
break;
}
}
#endif
F_2 ( 0 , V_6 -> V_9 + V_331 ) ;
V_306 = V_6 -> V_112 . V_139 +
( V_332 * sizeof( T_2 ) ) ;
F_2 ( ( T_2 ) V_306 , V_6 -> V_9 + V_333 ) ;
F_2 ( ( T_2 ) ( V_306 + sizeof( T_2 ) ) ,
V_6 -> V_9 + V_334 ) ;
V_6 -> V_33 = ( T_2 * ) V_6 -> V_112 . V_113 +
V_332 ;
F_2 ( 8 , V_6 -> V_9 + V_335 ) ;
F_2 ( V_38 | V_39 | V_40 | V_45 , V_6 -> V_9 + F_16 ( 0 ) ) ;
F_2 ( V_336 , V_6 -> V_9 + F_16 ( 1 ) ) ;
F_2 ( V_337 , V_6 -> V_9 + V_328 ) ;
F_19 ( V_2 ) ;
F_19 ( V_2 ) ;
for ( V_47 = 0 ; V_47 < V_338 ; V_47 ++ )
F_17 ( V_2 , V_47 , 0 ) ;
F_102 ( V_2 ) ;
F_78 ( V_2 , ( T_1 ) ( F_7 ( V_2 , V_102 ) &
V_339 ) ) ;
F_69 ( V_2 ) ;
}
static int F_106 ( struct V_1 * V_2 ,
unsigned long V_340 )
{
struct V_236 * V_237 = F_80 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_80 * V_81 ;
int V_225 ;
V_6 = F_107 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_305 ;
V_225 = F_108 ( V_2 ) ;
if ( V_225 )
return V_225 ;
V_6 -> V_9 = F_109 ( V_237 , 0 ) ;
if ( ! V_6 -> V_9 )
return - V_305 ;
F_2 ( 0 , V_6 -> V_9 + V_128 ) ;
F_2 ( V_341 , V_6 -> V_9 + V_35 ) ;
V_225 = F_103 ( V_2 ) ;
if ( V_225 )
return V_225 ;
if ( V_237 -> V_120 ) {
V_225 = F_110 ( V_237 -> V_120 , F_41 , V_342 ,
V_2 -> V_343 , V_2 ) ;
if ( V_225 == 0 )
V_2 -> V_120 = V_237 -> V_120 ;
}
V_225 = F_111 ( V_2 , 6 ) ;
if ( V_225 )
return V_225 ;
V_81 = & V_2 -> V_137 [ 0 ] ;
V_81 -> type = V_344 ;
V_81 -> V_345 = V_346 | V_347 | V_348 ;
V_81 -> V_349 = V_350 ;
V_81 -> V_351 = 0x3fff ;
V_81 -> V_352 = & V_353 ;
V_81 -> V_354 = V_350 ;
V_81 -> V_355 = F_47 ;
if ( V_2 -> V_120 ) {
V_2 -> V_82 = V_81 ;
V_81 -> V_356 = F_55 ;
V_81 -> V_357 = F_58 ;
V_81 -> V_358 = F_66 ;
}
V_81 = & V_2 -> V_137 [ 1 ] ;
V_81 -> type = V_359 ;
V_81 -> V_345 = V_360 | V_346 ;
V_81 -> V_349 = V_338 ;
V_81 -> V_351 = 0x3fff ;
V_81 -> V_352 = & V_361 ;
V_81 -> V_362 = F_67 ;
V_81 -> V_355 = F_68 ;
V_81 = & V_2 -> V_137 [ 2 ] ;
V_81 -> type = V_363 ;
V_81 -> V_345 = V_360 | V_346 ;
V_81 -> V_349 = 16 ;
V_81 -> V_351 = 1 ;
V_81 -> V_223 = 0xffff ;
V_81 -> V_7 = ( void * ) 0 ;
V_81 -> V_352 = & V_364 ;
V_81 -> V_365 = F_73 ;
V_81 -> V_366 = F_71 ;
V_81 = & V_2 -> V_137 [ 3 ] ;
V_81 -> type = V_363 ;
V_81 -> V_345 = V_360 | V_346 ;
V_81 -> V_349 = 16 ;
V_81 -> V_351 = 1 ;
V_81 -> V_223 = 0xffff ;
V_81 -> V_7 = ( void * ) 1 ;
V_81 -> V_352 = & V_364 ;
V_81 -> V_365 = F_73 ;
V_81 -> V_366 = F_71 ;
V_81 = & V_2 -> V_137 [ 4 ] ;
V_81 -> type = V_363 ;
V_81 -> V_345 = V_360 | V_346 ;
V_81 -> V_349 = 16 ;
V_81 -> V_351 = 1 ;
V_81 -> V_223 = 0xffff ;
V_81 -> V_7 = ( void * ) 2 ;
V_81 -> V_352 = & V_364 ;
V_81 -> V_365 = F_73 ;
V_81 -> V_366 = F_71 ;
V_81 = & V_2 -> V_137 [ 5 ] ;
V_81 -> type = V_367 ;
V_81 -> V_345 = V_360 | V_346 | V_368 ;
V_81 -> V_349 = V_302 ;
V_81 -> V_351 = 0xffffff ;
V_81 -> V_7 = V_369 ;
V_81 -> V_352 = & V_370 ;
V_81 -> V_365 = F_75 ;
V_81 -> V_355 = F_76 ;
V_81 -> V_362 = F_77 ;
F_105 ( V_2 ) ;
F_112 ( V_2 -> V_371 , L_3 , V_2 -> V_343 ) ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
V_6 -> V_85 = 0 ;
if ( V_6 -> V_9 ) {
F_2 ( 0 , V_6 -> V_9 + V_128 ) ;
F_2 ( V_130 | V_129 ,
V_6 -> V_9 + V_37 ) ;
F_78 ( V_2 , 0 ) ;
F_2 ( V_372 , V_6 -> V_9 + V_35 ) ;
F_2 ( V_373 , V_6 -> V_9 + V_328 ) ;
F_79 ( V_2 , & V_6 -> V_138 , V_304 ) ;
F_79 ( V_2 , & V_6 -> V_112 , V_304 ) ;
}
if ( V_2 -> V_120 )
F_114 ( V_2 -> V_120 , V_2 ) ;
if ( V_6 -> V_9 )
F_115 ( V_6 -> V_9 ) ;
}
F_116 ( V_2 ) ;
}
static int F_117 ( struct V_236 * V_2 ,
const struct V_374 * V_375 )
{
return F_118 ( V_2 , & V_376 , V_375 -> V_377 ) ;
}
