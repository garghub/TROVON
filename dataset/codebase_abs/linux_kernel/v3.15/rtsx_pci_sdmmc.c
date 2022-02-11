static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & ( V_3 -> V_4 -> V_5 ) ;
}
static inline void F_2 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_7 ,
V_8 | V_9 , V_8 | V_9 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
T_1 V_11 ;
T_2 * V_12 ;
F_5 ( V_6 ) ;
for ( V_11 = 0xFDA0 ; V_11 <= 0xFDAE ; V_11 ++ )
F_6 ( V_6 , V_13 , V_11 , 0 , 0 ) ;
for ( V_11 = 0xFD52 ; V_11 <= 0xFD69 ; V_11 ++ )
F_6 ( V_6 , V_13 , V_11 , 0 , 0 ) ;
F_7 ( V_6 , 100 ) ;
V_12 = F_8 ( V_6 ) ;
for ( V_11 = 0xFDA0 ; V_11 <= 0xFDAE ; V_11 ++ )
F_9 ( F_1 ( V_3 ) , L_1 , V_11 , * ( V_12 ++ ) ) ;
for ( V_11 = 0xFD52 ; V_11 <= 0xFD69 ; V_11 ++ )
F_9 ( F_1 ( V_3 ) , L_1 , V_11 , * ( V_12 ++ ) ) ;
}
static int F_10 ( struct V_2 * V_3 , T_2 * V_14 , T_1 V_15 ,
T_2 * V_16 , int V_17 , int V_18 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 , V_11 ;
T_2 V_20 ;
F_9 ( F_1 ( V_3 ) , L_2 , V_21 , V_14 [ 0 ] - 0x40 ) ;
if ( ! V_16 )
V_17 = 0 ;
if ( ( V_14 [ 0 ] & 0x3F ) == V_22 )
V_20 = V_23 ;
else
V_20 = V_24 ;
F_5 ( V_6 ) ;
for ( V_11 = 0 ; V_11 < 5 ; V_11 ++ )
F_6 ( V_6 , V_25 , V_26 + V_11 , 0xFF , V_14 [ V_11 ] ) ;
F_6 ( V_6 , V_25 , V_27 , 0xFF , ( T_2 ) V_15 ) ;
F_6 ( V_6 , V_25 , V_28 ,
0xFF , ( T_2 ) ( V_15 >> 8 ) ) ;
F_6 ( V_6 , V_25 , V_29 , 0xFF , 1 ) ;
F_6 ( V_6 , V_25 , V_30 , 0xFF , 0 ) ;
F_6 ( V_6 , V_25 , V_31 , 0xFF ,
V_32 | V_33 |
V_34 | V_35 | V_36 ) ;
if ( V_20 != V_23 )
F_6 ( V_6 , V_25 ,
V_37 , 0x01 , V_38 ) ;
F_6 ( V_6 , V_25 , V_39 ,
0xFF , V_20 | V_40 ) ;
F_6 ( V_6 , V_41 , V_39 ,
V_42 , V_42 ) ;
V_19 = F_7 ( V_6 , V_18 ) ;
if ( V_19 < 0 ) {
F_4 ( V_3 ) ;
F_9 ( F_1 ( V_3 ) ,
L_3 , V_19 ) ;
return V_19 ;
}
if ( V_16 && V_17 ) {
V_19 = F_11 ( V_6 , V_16 , V_17 ) ;
if ( V_19 < 0 ) {
F_9 ( F_1 ( V_3 ) ,
L_4 , V_19 ) ;
return V_19 ;
}
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , T_2 * V_14 , T_1 V_15 ,
T_2 * V_16 , int V_17 , int V_18 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 , V_11 ;
T_2 V_20 ;
if ( ! V_16 )
V_17 = 0 ;
if ( V_16 && V_17 ) {
V_19 = F_13 ( V_6 , V_16 , V_17 ) ;
if ( V_19 < 0 ) {
F_9 ( F_1 ( V_3 ) ,
L_5 , V_19 ) ;
return V_19 ;
}
}
V_20 = V_14 ? V_43 : V_44 ;
F_5 ( V_6 ) ;
if ( V_14 ) {
F_9 ( F_1 ( V_3 ) , L_6 , V_21 ,
V_14 [ 0 ] - 0x40 ) ;
for ( V_11 = 0 ; V_11 < 5 ; V_11 ++ )
F_6 ( V_6 , V_25 ,
V_26 + V_11 , 0xFF , V_14 [ V_11 ] ) ;
}
F_6 ( V_6 , V_25 , V_27 , 0xFF , ( T_2 ) V_15 ) ;
F_6 ( V_6 , V_25 , V_28 ,
0xFF , ( T_2 ) ( V_15 >> 8 ) ) ;
F_6 ( V_6 , V_25 , V_29 , 0xFF , 1 ) ;
F_6 ( V_6 , V_25 , V_30 , 0xFF , 0 ) ;
F_6 ( V_6 , V_25 , V_31 , 0xFF ,
V_32 | V_33 |
V_34 | V_35 | V_36 ) ;
F_6 ( V_6 , V_25 , V_39 , 0xFF ,
V_20 | V_40 ) ;
F_6 ( V_6 , V_41 , V_39 ,
V_42 , V_42 ) ;
V_19 = F_7 ( V_6 , V_18 ) ;
if ( V_19 < 0 ) {
F_4 ( V_3 ) ;
F_9 ( F_1 ( V_3 ) ,
L_3 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_45 * V_14 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
T_2 V_46 = ( T_2 ) V_14 -> V_47 ;
T_3 V_48 = V_14 -> V_48 ;
int V_19 = 0 ;
int V_18 = 100 ;
int V_11 ;
T_2 * V_12 ;
int V_49 = 0 ;
T_2 V_50 ;
int V_51 = 5 ;
bool V_52 = false ;
F_9 ( F_1 ( V_3 ) , L_7 ,
V_21 , V_46 , V_48 ) ;
switch ( F_15 ( V_14 ) ) {
case V_53 :
V_50 = V_54 ;
V_51 = 0 ;
break;
case V_55 :
V_50 = V_56 ;
break;
case V_57 :
V_50 = V_58 ;
break;
case V_59 :
V_50 = V_60 ;
V_51 = 16 ;
break;
case V_61 :
V_50 = V_62 ;
break;
default:
F_9 ( F_1 ( V_3 ) , L_8 ) ;
V_19 = - V_63 ;
goto V_64;
}
if ( V_50 == V_58 )
V_18 = 3000 ;
if ( V_14 -> V_47 == V_65 ) {
V_19 = F_3 ( V_6 , V_66 ,
0xFF , V_67 ) ;
if ( V_19 < 0 )
goto V_64;
V_52 = true ;
}
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_26 , 0xFF , 0x40 | V_46 ) ;
F_6 ( V_6 , V_25 , V_68 , 0xFF , ( T_2 ) ( V_48 >> 24 ) ) ;
F_6 ( V_6 , V_25 , V_69 , 0xFF , ( T_2 ) ( V_48 >> 16 ) ) ;
F_6 ( V_6 , V_25 , V_70 , 0xFF , ( T_2 ) ( V_48 >> 8 ) ) ;
F_6 ( V_6 , V_25 , V_71 , 0xFF , ( T_2 ) V_48 ) ;
F_6 ( V_6 , V_25 , V_31 , 0xFF , V_50 ) ;
F_6 ( V_6 , V_25 , V_37 ,
0x01 , V_38 ) ;
F_6 ( V_6 , V_25 , V_39 ,
0xFF , V_72 | V_40 ) ;
F_6 ( V_6 , V_41 , V_39 ,
V_42 | V_73 ,
V_42 | V_73 ) ;
if ( V_50 == V_60 ) {
for ( V_11 = V_74 ; V_11 < V_74 + 16 ; V_11 ++ )
F_6 ( V_6 , V_13 , ( T_1 ) V_11 , 0 , 0 ) ;
V_49 = 16 ;
} else if ( V_50 != V_54 ) {
for ( V_11 = V_26 ; V_11 <= V_71 ; V_11 ++ )
F_6 ( V_6 , V_13 , ( T_1 ) V_11 , 0 , 0 ) ;
V_49 = 5 ;
}
F_6 ( V_6 , V_13 , V_75 , 0 , 0 ) ;
V_19 = F_7 ( V_6 , V_18 ) ;
if ( V_19 < 0 ) {
F_4 ( V_3 ) ;
F_2 ( V_3 ) ;
F_9 ( F_1 ( V_3 ) ,
L_9 , V_19 ) ;
goto V_64;
}
if ( V_50 == V_54 ) {
V_19 = 0 ;
goto V_64;
}
V_12 = F_8 ( V_6 ) + 1 ;
if ( ( V_12 [ 0 ] & 0xC0 ) != 0 ) {
V_19 = - V_76 ;
F_9 ( F_1 ( V_3 ) , L_10 ) ;
goto V_64;
}
if ( ! ( V_50 & V_77 ) ) {
if ( V_12 [ V_49 ] & V_78 ) {
V_19 = - V_76 ;
F_9 ( F_1 ( V_3 ) , L_11 ) ;
goto V_64;
}
}
if ( V_50 == V_60 ) {
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_14 -> V_79 [ V_11 ] = F_16 ( V_12 + 1 + V_11 * 4 ) ;
F_9 ( F_1 ( V_3 ) , L_12 ,
V_11 , V_14 -> V_79 [ V_11 ] ) ;
}
} else {
V_14 -> V_79 [ 0 ] = F_16 ( V_12 + 1 ) ;
F_9 ( F_1 ( V_3 ) , L_13 ,
V_14 -> V_79 [ 0 ] ) ;
}
V_64:
V_14 -> error = V_19 ;
if ( V_19 && V_52 )
F_3 ( V_6 , V_66 ,
V_67 | V_80 , 0 ) ;
}
static int F_17 ( struct V_2 * V_3 , struct V_81 * V_82 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_83 * V_84 = V_3 -> V_84 ;
struct V_85 * V_86 = V_84 -> V_86 ;
struct V_87 * V_88 = V_82 -> V_88 ;
int V_89 = F_18 ( V_86 ) ;
int V_90 = ( V_88 -> V_91 & V_92 ) ? 1 : 0 ;
T_2 V_93 , V_20 ;
int V_19 ;
T_4 V_94 = V_88 -> V_95 * V_88 -> V_96 ;
if ( V_90 ) {
V_93 = V_32 | V_33 |
V_34 | V_35 | V_97 ;
V_20 = V_98 ;
} else {
V_93 = V_99 | V_33 |
V_34 | V_77 | V_97 ;
V_20 = V_44 ;
}
if ( ! V_89 )
V_93 |= V_100 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_27 , 0xFF , 0x00 ) ;
F_6 ( V_6 , V_25 , V_28 , 0xFF , 0x02 ) ;
F_6 ( V_6 , V_25 , V_29 ,
0xFF , ( T_2 ) V_88 -> V_96 ) ;
F_6 ( V_6 , V_25 , V_30 ,
0xFF , ( T_2 ) ( V_88 -> V_96 >> 8 ) ) ;
F_6 ( V_6 , V_25 , V_101 ,
V_102 , V_102 ) ;
F_6 ( V_6 , V_25 , V_103 ,
0xFF , ( T_2 ) ( V_94 >> 24 ) ) ;
F_6 ( V_6 , V_25 , V_104 ,
0xFF , ( T_2 ) ( V_94 >> 16 ) ) ;
F_6 ( V_6 , V_25 , V_105 ,
0xFF , ( T_2 ) ( V_94 >> 8 ) ) ;
F_6 ( V_6 , V_25 , V_106 , 0xFF , ( T_2 ) V_94 ) ;
if ( V_90 ) {
F_6 ( V_6 , V_25 , V_107 ,
0x03 | V_108 ,
V_109 | V_110 | V_111 ) ;
} else {
F_6 ( V_6 , V_25 , V_107 ,
0x03 | V_108 ,
V_112 | V_110 | V_111 ) ;
}
F_6 ( V_6 , V_25 , V_37 ,
0x01 , V_113 ) ;
F_6 ( V_6 , V_25 , V_31 , 0xFF , V_93 ) ;
F_6 ( V_6 , V_25 , V_39 , 0xFF ,
V_20 | V_40 ) ;
F_6 ( V_6 , V_41 , V_39 ,
V_42 , V_42 ) ;
F_19 ( V_6 ) ;
V_19 = F_20 ( V_6 , V_88 -> V_114 , V_88 -> V_115 , V_90 , 10000 ) ;
if ( V_19 < 0 ) {
F_2 ( V_3 ) ;
return V_19 ;
}
return 0 ;
}
static inline void F_21 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_116 ,
V_117 , V_118 ) ;
}
static inline void F_22 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_116 ,
V_117 , V_119 ) ;
}
static void F_23 ( struct V_2 * V_3 ,
struct V_81 * V_82 )
{
struct V_45 * V_14 = V_82 -> V_14 ;
struct V_87 * V_88 = V_82 -> V_88 ;
T_2 V_120 [ 5 ] , * V_16 ;
V_120 [ 0 ] = 0x40 | ( T_2 ) V_14 -> V_47 ;
F_24 ( V_14 -> V_48 , ( T_3 * ) ( & V_120 [ 1 ] ) ) ;
V_16 = F_25 ( V_88 -> V_95 , V_121 ) ;
if ( ! V_16 ) {
V_14 -> error = - V_122 ;
return;
}
if ( V_88 -> V_91 & V_92 ) {
if ( V_3 -> V_123 )
F_22 ( V_3 ) ;
V_14 -> error = F_10 ( V_3 , V_120 , ( T_1 ) V_88 -> V_95 , V_16 ,
V_88 -> V_95 , 200 ) ;
if ( V_3 -> V_123 )
F_21 ( V_3 ) ;
F_26 ( V_88 -> V_114 , V_88 -> V_115 , V_16 , V_88 -> V_95 ) ;
} else {
F_27 ( V_88 -> V_114 , V_88 -> V_115 , V_16 , V_88 -> V_95 ) ;
V_14 -> error = F_12 ( V_3 , V_120 , ( T_1 ) V_88 -> V_95 , V_16 ,
V_88 -> V_95 , 200 ) ;
}
F_28 ( V_16 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
T_2 V_124 , bool V_125 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
F_9 ( F_1 ( V_3 ) , L_14 ,
V_21 , V_125 ? L_15 : L_16 , V_124 ) ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_126 , V_127 , V_127 ) ;
if ( V_125 )
F_6 ( V_6 , V_25 ,
V_128 , 0x1F , V_124 ) ;
else
F_6 ( V_6 , V_25 ,
V_129 , 0x1F , V_124 ) ;
F_6 ( V_6 , V_25 , V_130 , V_131 , 0 ) ;
F_6 ( V_6 , V_25 , V_130 ,
V_131 , V_131 ) ;
F_6 ( V_6 , V_25 , V_126 , V_127 , 0 ) ;
F_6 ( V_6 , V_25 , V_116 , V_132 , 0 ) ;
V_19 = F_7 ( V_6 , 100 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static inline T_3 F_30 ( T_3 V_133 , unsigned int V_134 )
{
V_134 %= V_135 ;
return V_133 & ( 1 << V_134 ) ;
}
static int F_31 ( T_3 V_133 , unsigned int V_136 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_135 ; V_11 ++ ) {
if ( F_30 ( V_133 , V_136 + V_11 ) == 0 )
return V_11 ;
}
return V_135 ;
}
static T_2 F_32 ( struct V_2 * V_3 , T_3 V_133 )
{
int V_137 = 0 , V_138 = 0 ;
int V_139 = 0 , V_140 = 0 ;
T_2 V_141 = 0xFF ;
if ( V_133 == 0 ) {
F_33 ( F_1 ( V_3 ) , L_17 , V_133 ) ;
return V_141 ;
}
while ( V_137 < V_135 ) {
V_138 = F_31 ( V_133 , V_137 ) ;
if ( V_140 < V_138 ) {
V_139 = V_137 ;
V_140 = V_138 ;
}
V_137 += V_138 ? V_138 : 1 ;
}
V_141 = ( V_139 + V_140 / 2 ) % V_135 ;
F_9 ( F_1 ( V_3 ) , L_18 ,
V_133 , V_140 , V_141 ) ;
return V_141 ;
}
static void F_34 ( struct V_2 * V_3 )
{
int V_19 , V_11 ;
T_2 V_142 = 0 ;
for ( V_11 = 0 ; V_11 < 100 ; V_11 ++ ) {
V_19 = F_35 ( V_3 -> V_6 , V_143 , & V_142 ) ;
if ( V_142 & V_144 )
return;
F_36 ( 100 ) ;
}
}
static int F_37 ( struct V_2 * V_3 ,
T_2 V_47 , T_2 V_124 )
{
int V_19 ;
T_2 V_14 [ 5 ] = { 0 } ;
V_19 = F_29 ( V_3 , V_124 , true ) ;
if ( V_19 < 0 )
return V_19 ;
V_14 [ 0 ] = 0x40 | V_47 ;
V_19 = F_10 ( V_3 , V_14 , 0x40 , NULL , 0 , 100 ) ;
if ( V_19 < 0 ) {
F_34 ( V_3 ) ;
F_2 ( V_3 ) ;
return V_19 ;
}
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
T_2 V_47 , T_3 * V_133 )
{
int V_19 , V_11 ;
T_3 V_145 = 0 ;
for ( V_11 = 0 ; V_11 < V_135 ; V_11 ++ ) {
V_19 = F_37 ( V_3 , V_47 , ( T_2 ) V_11 ) ;
if ( V_19 == 0 )
V_145 |= 1 << V_11 ;
}
if ( V_133 )
* V_133 = V_145 ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , T_2 V_47 )
{
int V_19 , V_11 ;
T_3 V_145 [ V_146 ] = { 0 } , V_133 ;
T_2 V_141 ;
for ( V_11 = 0 ; V_11 < V_146 ; V_11 ++ ) {
V_19 = F_38 ( V_3 , V_47 , & ( V_145 [ V_11 ] ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_145 [ V_11 ] == 0 )
break;
}
V_133 = 0xFFFFFFFF ;
for ( V_11 = 0 ; V_11 < V_146 ; V_11 ++ ) {
F_9 ( F_1 ( V_3 ) , L_19 ,
V_11 , V_145 [ V_11 ] ) ;
V_133 &= V_145 [ V_11 ] ;
}
F_9 ( F_1 ( V_3 ) , L_20 , V_133 ) ;
if ( V_133 ) {
V_141 = F_32 ( V_3 , V_133 ) ;
if ( V_141 == 0xFF )
return - V_63 ;
V_19 = F_29 ( V_3 , V_141 , true ) ;
if ( V_19 < 0 )
return V_19 ;
} else {
return - V_63 ;
}
return 0 ;
}
static void F_40 ( struct V_83 * V_84 , struct V_81 * V_82 )
{
struct V_2 * V_3 = F_41 ( V_84 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_45 * V_14 = V_82 -> V_14 ;
struct V_87 * V_88 = V_82 -> V_88 ;
unsigned int V_147 = 0 ;
int V_19 ;
if ( V_3 -> V_148 ) {
V_14 -> error = - V_149 ;
goto V_150;
}
V_19 = F_42 ( V_3 -> V_6 , V_151 ) ;
if ( V_19 ) {
V_14 -> error = V_19 ;
goto V_150;
}
F_43 ( & V_6 -> V_152 ) ;
F_44 ( V_6 ) ;
F_45 ( V_6 , V_3 -> clock , V_3 -> V_153 ,
V_3 -> V_123 , V_3 -> V_154 , V_3 -> V_155 ) ;
F_3 ( V_6 , V_156 , 0x07 , V_157 ) ;
F_3 ( V_6 , V_158 ,
V_159 , V_160 ) ;
F_43 ( & V_3 -> V_161 ) ;
V_3 -> V_82 = V_82 ;
F_46 ( & V_3 -> V_161 ) ;
if ( V_82 -> V_88 )
V_147 = V_88 -> V_96 * V_88 -> V_95 ;
if ( ! V_147 || F_47 ( V_14 -> V_47 ) ||
( V_14 -> V_47 == V_162 ) ||
( V_14 -> V_47 == V_163 ) ) {
F_14 ( V_3 , V_14 ) ;
if ( ! V_14 -> error && V_147 ) {
F_17 ( V_3 , V_82 ) ;
if ( F_47 ( V_14 -> V_47 ) && V_82 -> V_164 )
F_14 ( V_3 , V_82 -> V_164 ) ;
}
} else {
F_23 ( V_3 , V_82 ) ;
}
if ( V_82 -> V_88 ) {
if ( V_14 -> error || V_88 -> error )
V_88 -> V_165 = 0 ;
else
V_88 -> V_165 = V_88 -> V_96 * V_88 -> V_95 ;
}
F_46 ( & V_6 -> V_152 ) ;
V_150:
if ( V_14 -> error )
F_9 ( F_1 ( V_3 ) , L_21 , V_14 -> error ) ;
F_43 ( & V_3 -> V_161 ) ;
V_3 -> V_82 = NULL ;
F_46 ( & V_3 -> V_161 ) ;
F_48 ( V_84 , V_82 ) ;
}
static int F_49 ( struct V_2 * V_3 ,
unsigned char V_166 )
{
int V_19 = 0 ;
T_2 V_167 [] = {
[ V_168 ] = V_169 ,
[ V_170 ] = V_171 ,
[ V_172 ] = V_173 ,
} ;
if ( V_166 <= V_172 )
V_19 = F_3 ( V_3 -> V_6 , V_116 ,
0x03 , V_167 [ V_166 ] ) ;
return V_19 ;
}
static int F_50 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
if ( V_3 -> V_174 == V_175 )
return 0 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_156 , 0x07 , V_157 ) ;
F_6 ( V_6 , V_25 , V_158 ,
V_159 , V_160 ) ;
F_6 ( V_6 , V_25 , V_176 ,
V_177 , V_177 ) ;
V_19 = F_7 ( V_6 , 100 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_51 ( V_6 , V_151 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_52 ( V_6 , V_151 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_3 ( V_6 , V_178 , V_179 , V_179 ) ;
if ( V_19 < 0 )
return V_19 ;
V_3 -> V_174 = V_175 ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
V_3 -> V_174 = V_180 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_176 , V_177 , 0 ) ;
F_6 ( V_6 , V_25 , V_178 , V_179 , 0 ) ;
V_19 = F_7 ( V_6 , 100 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_54 ( V_6 , V_151 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_55 ( V_6 , V_151 ) ;
}
static int F_56 ( struct V_2 * V_3 ,
unsigned char V_181 )
{
int V_19 ;
if ( V_181 == V_182 )
V_19 = F_53 ( V_3 ) ;
else
V_19 = F_50 ( V_3 ) ;
return V_19 ;
}
static int F_57 ( struct V_2 * V_3 , unsigned char V_183 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 = 0 ;
F_5 ( V_6 ) ;
switch ( V_183 ) {
case V_184 :
case V_185 :
F_6 ( V_6 , V_25 , V_116 ,
0x0C | V_132 ,
V_186 | V_132 ) ;
F_6 ( V_6 , V_25 , V_126 ,
V_187 , V_187 ) ;
F_6 ( V_6 , V_25 , V_188 , 0xFF ,
V_189 | V_190 | V_191 ) ;
F_6 ( V_6 , V_25 , V_126 , V_187 , 0 ) ;
break;
case V_192 :
F_6 ( V_6 , V_25 , V_116 ,
0x0C | V_132 ,
V_193 | V_132 ) ;
F_6 ( V_6 , V_25 , V_126 ,
V_187 , V_187 ) ;
F_6 ( V_6 , V_25 , V_188 , 0xFF ,
V_189 | V_190 | V_191 ) ;
F_6 ( V_6 , V_25 , V_126 , V_187 , 0 ) ;
F_6 ( V_6 , V_25 , V_194 ,
V_195 , V_195 ) ;
F_6 ( V_6 , V_25 , V_196 ,
V_197 | V_198 ,
V_197 | V_198 ) ;
break;
case V_199 :
case V_200 :
F_6 ( V_6 , V_25 , V_116 ,
0x0C , V_201 ) ;
F_6 ( V_6 , V_25 , V_126 ,
V_187 , V_187 ) ;
F_6 ( V_6 , V_25 , V_188 , 0xFF ,
V_202 | V_203 | V_191 ) ;
F_6 ( V_6 , V_25 , V_126 , V_187 , 0 ) ;
F_6 ( V_6 , V_25 , V_194 ,
V_204 , V_205 ) ;
F_6 ( V_6 , V_25 , V_196 ,
V_206 , V_207 ) ;
break;
default:
F_6 ( V_6 , V_25 ,
V_116 , 0x0C , V_201 ) ;
F_6 ( V_6 , V_25 , V_126 ,
V_187 , V_187 ) ;
F_6 ( V_6 , V_25 , V_188 , 0xFF ,
V_202 | V_203 | V_191 ) ;
F_6 ( V_6 , V_25 , V_126 , V_187 , 0 ) ;
F_6 ( V_6 , V_25 ,
V_194 , 0xFF , 0 ) ;
F_6 ( V_6 , V_25 , V_196 ,
V_206 , V_208 ) ;
break;
}
V_19 = F_7 ( V_6 , 100 ) ;
return V_19 ;
}
static void F_58 ( struct V_83 * V_84 , struct V_209 * V_210 )
{
struct V_2 * V_3 = F_41 ( V_84 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_148 )
return;
if ( F_42 ( V_3 -> V_6 , V_151 ) )
return;
F_43 ( & V_6 -> V_152 ) ;
F_44 ( V_6 ) ;
F_49 ( V_3 , V_210 -> V_166 ) ;
F_56 ( V_3 , V_210 -> V_181 ) ;
F_57 ( V_3 , V_210 -> V_183 ) ;
V_3 -> V_155 = false ;
V_3 -> V_154 = true ;
switch ( V_210 -> V_183 ) {
case V_184 :
case V_185 :
V_3 -> V_153 = V_211 ;
V_3 -> V_155 = true ;
V_3 -> V_154 = false ;
break;
case V_192 :
case V_212 :
V_3 -> V_153 = V_213 ;
break;
default:
V_3 -> V_153 = V_214 ;
break;
}
V_3 -> V_123 = ( V_210 -> clock <= 1000000 ) ? true : false ;
V_3 -> clock = V_210 -> clock ;
F_45 ( V_6 , V_210 -> clock , V_3 -> V_153 ,
V_3 -> V_123 , V_3 -> V_154 , V_3 -> V_155 ) ;
F_46 ( & V_6 -> V_152 ) ;
}
static int F_59 ( struct V_83 * V_84 )
{
struct V_2 * V_3 = F_41 ( V_84 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_215 = 0 ;
T_3 V_142 ;
if ( V_3 -> V_148 )
return - V_149 ;
F_43 ( & V_6 -> V_152 ) ;
F_44 ( V_6 ) ;
V_142 = F_60 ( V_6 , V_216 ) ;
F_9 ( F_1 ( V_3 ) , L_22 , V_21 , V_142 ) ;
if ( V_142 & V_217 )
V_215 = 1 ;
F_46 ( & V_6 -> V_152 ) ;
return V_215 ;
}
static int F_61 ( struct V_83 * V_84 )
{
struct V_2 * V_3 = F_41 ( V_84 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_218 = 0 ;
T_3 V_142 ;
if ( V_3 -> V_148 )
return - V_149 ;
F_43 ( & V_6 -> V_152 ) ;
F_44 ( V_6 ) ;
V_142 = F_62 ( V_6 ) ;
F_9 ( F_1 ( V_3 ) , L_22 , V_21 , V_142 ) ;
if ( V_142 & V_219 )
V_218 = 1 ;
F_46 ( & V_6 -> V_152 ) ;
return V_218 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
T_2 V_220 ;
F_64 ( 1 ) ;
V_19 = F_35 ( V_6 , V_66 , & V_220 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_220 & ( V_221 | V_222 | V_223 |
V_224 | V_225 ) )
return - V_63 ;
V_19 = F_3 ( V_6 , V_66 ,
0xFF , V_80 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
T_2 V_220 , V_226 , V_142 ;
F_66 ( 50 ) ;
V_19 = F_3 ( V_6 , V_66 , 0xFF , V_67 ) ;
if ( V_19 < 0 )
return V_19 ;
F_66 ( 20 ) ;
V_19 = F_35 ( V_6 , V_66 , & V_220 ) ;
if ( V_19 < 0 )
return V_19 ;
V_226 = V_221 | V_222 | V_223 |
V_224 | V_225 ;
V_142 = V_221 | V_222 | V_223 |
V_224 | V_225 ;
if ( ( V_220 & V_226 ) != V_142 ) {
F_9 ( F_1 ( V_3 ) ,
L_23 , V_21 , V_220 ) ;
F_3 ( V_6 , V_66 ,
V_67 | V_80 , 0 ) ;
F_3 ( V_6 , V_176 , 0xFF , 0 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_67 ( struct V_83 * V_84 , struct V_209 * V_210 )
{
struct V_2 * V_3 = F_41 ( V_84 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 = 0 ;
T_2 V_227 ;
F_9 ( F_1 ( V_3 ) , L_24 ,
V_21 , V_210 -> V_228 ) ;
if ( V_3 -> V_148 )
return - V_149 ;
V_19 = F_42 ( V_3 -> V_6 , V_151 ) ;
if ( V_19 )
return V_19 ;
F_43 ( & V_6 -> V_152 ) ;
F_44 ( V_6 ) ;
if ( V_210 -> V_228 == V_229 )
V_227 = V_230 ;
else
V_227 = V_231 ;
if ( V_227 == V_231 ) {
V_19 = F_63 ( V_3 ) ;
if ( V_19 < 0 )
goto V_64;
}
V_19 = F_68 ( V_6 , V_227 ) ;
if ( V_19 < 0 )
goto V_64;
if ( V_227 == V_231 ) {
V_19 = F_65 ( V_3 ) ;
if ( V_19 < 0 )
goto V_64;
}
V_64:
V_19 = F_3 ( V_6 , V_66 ,
V_67 | V_80 , 0 ) ;
F_46 ( & V_6 -> V_152 ) ;
return V_19 ;
}
static int F_69 ( struct V_83 * V_84 , T_3 V_47 )
{
struct V_2 * V_3 = F_41 ( V_84 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 = 0 ;
if ( V_3 -> V_148 )
return - V_149 ;
V_19 = F_42 ( V_3 -> V_6 , V_151 ) ;
if ( V_19 )
return V_19 ;
F_43 ( & V_6 -> V_152 ) ;
F_44 ( V_6 ) ;
switch ( V_84 -> V_210 . V_183 ) {
case V_184 :
V_19 = F_29 ( V_3 , F_70 ( V_6 ) , false ) ;
break;
case V_185 :
V_19 = F_29 ( V_3 , F_71 ( V_6 ) , false ) ;
break;
case V_192 :
V_19 = F_29 ( V_3 , F_72 ( V_6 ) , false ) ;
break;
default:
V_19 = 0 ;
}
if ( V_19 )
goto V_64;
if ( ( V_84 -> V_210 . V_183 == V_184 ) ||
( V_84 -> V_210 . V_183 == V_185 ) )
V_19 = F_39 ( V_3 , V_47 ) ;
else if ( V_84 -> V_210 . V_183 == V_192 )
V_19 = F_29 ( V_3 , F_73 ( V_6 ) , true ) ;
V_64:
F_46 ( & V_6 -> V_152 ) ;
return V_19 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_83 * V_84 = V_3 -> V_84 ;
struct V_10 * V_6 = V_3 -> V_6 ;
F_9 ( F_1 ( V_3 ) , L_25 , V_6 -> V_232 ) ;
if ( V_6 -> V_232 & V_233 )
V_84 -> V_234 |= V_235 ;
if ( V_6 -> V_232 & V_236 )
V_84 -> V_234 |= V_237 ;
if ( V_6 -> V_232 & V_238 )
V_84 -> V_234 |= V_239 ;
if ( V_6 -> V_232 & V_240 )
V_84 -> V_234 |= V_241 ;
if ( V_6 -> V_232 & V_242 )
V_84 -> V_234 |= V_243 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_83 * V_84 = V_3 -> V_84 ;
V_84 -> V_244 = 250000 ;
V_84 -> V_245 = 208000000 ;
V_84 -> V_246 = V_247 | V_248 | V_249 ;
V_84 -> V_234 = V_250 | V_251 |
V_252 | V_253 |
V_254 | V_255 ;
V_84 -> V_256 = 400 ;
V_84 -> V_257 = 800 ;
V_84 -> V_258 = & V_259 ;
F_74 ( V_3 ) ;
V_84 -> V_260 = 256 ;
V_84 -> V_261 = 65536 ;
V_84 -> V_262 = 512 ;
V_84 -> V_263 = 65535 ;
V_84 -> V_264 = 524288 ;
}
static void F_76 ( struct V_265 * V_4 )
{
struct V_2 * V_3 = F_77 ( V_4 ) ;
F_78 ( V_3 -> V_84 , 0 ) ;
}
static int F_79 ( struct V_265 * V_4 )
{
struct V_83 * V_84 ;
struct V_2 * V_3 ;
struct V_10 * V_6 ;
struct V_266 * V_267 = V_4 -> V_5 . V_268 ;
if ( ! V_267 )
return - V_269 ;
V_6 = V_267 -> V_6 ;
if ( ! V_6 )
return - V_269 ;
F_9 ( & ( V_4 -> V_5 ) , L_26 ) ;
V_84 = F_80 ( sizeof( * V_3 ) , & V_4 -> V_5 ) ;
if ( ! V_84 )
return - V_122 ;
V_3 = F_41 ( V_84 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_84 = V_84 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_174 = V_180 ;
F_81 ( V_4 , V_3 ) ;
V_6 -> V_270 [ V_151 ] . V_271 = V_4 ;
V_6 -> V_270 [ V_151 ] . V_272 = F_76 ;
F_82 ( & V_3 -> V_161 ) ;
F_75 ( V_3 ) ;
F_83 ( V_84 ) ;
return 0 ;
}
static int F_84 ( struct V_265 * V_4 )
{
struct V_2 * V_3 = F_77 ( V_4 ) ;
struct V_10 * V_6 ;
struct V_83 * V_84 ;
if ( ! V_3 )
return 0 ;
V_6 = V_3 -> V_6 ;
V_6 -> V_270 [ V_151 ] . V_271 = NULL ;
V_6 -> V_270 [ V_151 ] . V_272 = NULL ;
V_84 = V_3 -> V_84 ;
F_43 ( & V_3 -> V_161 ) ;
if ( V_3 -> V_82 ) {
F_9 ( & ( V_4 -> V_5 ) ,
L_27 ,
F_85 ( V_84 ) ) ;
F_86 ( V_6 ) ;
V_3 -> V_82 -> V_14 -> error = - V_149 ;
if ( V_3 -> V_82 -> V_164 )
V_3 -> V_82 -> V_164 -> error = - V_149 ;
F_48 ( V_84 , V_3 -> V_82 ) ;
}
F_46 ( & V_3 -> V_161 ) ;
F_87 ( V_84 ) ;
V_3 -> V_148 = true ;
F_88 ( V_84 ) ;
F_9 ( & ( V_4 -> V_5 ) ,
L_28 ) ;
return 0 ;
}
