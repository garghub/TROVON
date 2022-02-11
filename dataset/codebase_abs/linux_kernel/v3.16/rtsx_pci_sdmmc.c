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
case V_55 & ~ V_57 :
V_50 = V_56 | V_58 ;
break;
case V_59 :
V_50 = V_60 ;
break;
case V_61 :
V_50 = V_62 ;
V_51 = 16 ;
break;
case V_63 :
V_50 = V_64 ;
break;
default:
F_9 ( F_1 ( V_3 ) , L_8 ) ;
V_19 = - V_65 ;
goto V_66;
}
if ( V_50 == V_60 )
V_18 = 3000 ;
if ( V_14 -> V_47 == V_67 ) {
V_19 = F_3 ( V_6 , V_68 ,
0xFF , V_69 ) ;
if ( V_19 < 0 )
goto V_66;
V_52 = true ;
}
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_26 , 0xFF , 0x40 | V_46 ) ;
F_6 ( V_6 , V_25 , V_70 , 0xFF , ( T_2 ) ( V_48 >> 24 ) ) ;
F_6 ( V_6 , V_25 , V_71 , 0xFF , ( T_2 ) ( V_48 >> 16 ) ) ;
F_6 ( V_6 , V_25 , V_72 , 0xFF , ( T_2 ) ( V_48 >> 8 ) ) ;
F_6 ( V_6 , V_25 , V_73 , 0xFF , ( T_2 ) V_48 ) ;
F_6 ( V_6 , V_25 , V_31 , 0xFF , V_50 ) ;
F_6 ( V_6 , V_25 , V_37 ,
0x01 , V_38 ) ;
F_6 ( V_6 , V_25 , V_39 ,
0xFF , V_74 | V_40 ) ;
F_6 ( V_6 , V_41 , V_39 ,
V_42 | V_75 ,
V_42 | V_75 ) ;
if ( V_50 == V_62 ) {
for ( V_11 = V_76 ; V_11 < V_76 + 16 ; V_11 ++ )
F_6 ( V_6 , V_13 , ( T_1 ) V_11 , 0 , 0 ) ;
V_49 = 16 ;
} else if ( V_50 != V_54 ) {
for ( V_11 = V_26 ; V_11 <= V_73 ; V_11 ++ )
F_6 ( V_6 , V_13 , ( T_1 ) V_11 , 0 , 0 ) ;
V_49 = 5 ;
}
F_6 ( V_6 , V_13 , V_77 , 0 , 0 ) ;
V_19 = F_7 ( V_6 , V_18 ) ;
if ( V_19 < 0 ) {
F_4 ( V_3 ) ;
F_2 ( V_3 ) ;
F_9 ( F_1 ( V_3 ) ,
L_9 , V_19 ) ;
goto V_66;
}
if ( V_50 == V_54 ) {
V_19 = 0 ;
goto V_66;
}
V_12 = F_8 ( V_6 ) + 1 ;
if ( ( V_12 [ 0 ] & 0xC0 ) != 0 ) {
V_19 = - V_78 ;
F_9 ( F_1 ( V_3 ) , L_10 ) ;
goto V_66;
}
if ( ! ( V_50 & V_58 ) ) {
if ( V_12 [ V_49 ] & V_79 ) {
V_19 = - V_78 ;
F_9 ( F_1 ( V_3 ) , L_11 ) ;
goto V_66;
}
}
if ( V_50 == V_62 ) {
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_14 -> V_80 [ V_11 ] = F_16 ( V_12 + 1 + V_11 * 4 ) ;
F_9 ( F_1 ( V_3 ) , L_12 ,
V_11 , V_14 -> V_80 [ V_11 ] ) ;
}
} else {
V_14 -> V_80 [ 0 ] = F_16 ( V_12 + 1 ) ;
F_9 ( F_1 ( V_3 ) , L_13 ,
V_14 -> V_80 [ 0 ] ) ;
}
V_66:
V_14 -> error = V_19 ;
if ( V_19 && V_52 )
F_3 ( V_6 , V_68 ,
V_69 | V_81 , 0 ) ;
}
static int F_17 ( struct V_2 * V_3 , struct V_82 * V_83 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_84 * V_85 = V_3 -> V_85 ;
struct V_86 * V_87 = V_85 -> V_87 ;
struct V_88 * V_89 = V_83 -> V_89 ;
int V_90 = F_18 ( V_87 ) ;
int V_91 = ( V_89 -> V_92 & V_93 ) ? 1 : 0 ;
T_2 V_94 , V_20 ;
int V_19 ;
T_4 V_95 = V_89 -> V_96 * V_89 -> V_97 ;
if ( V_91 ) {
V_94 = V_32 | V_33 |
V_34 | V_35 | V_98 ;
V_20 = V_99 ;
} else {
V_94 = V_100 | V_33 |
V_34 | V_58 | V_98 ;
V_20 = V_44 ;
}
if ( ! V_90 )
V_94 |= V_101 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_27 , 0xFF , 0x00 ) ;
F_6 ( V_6 , V_25 , V_28 , 0xFF , 0x02 ) ;
F_6 ( V_6 , V_25 , V_29 ,
0xFF , ( T_2 ) V_89 -> V_97 ) ;
F_6 ( V_6 , V_25 , V_30 ,
0xFF , ( T_2 ) ( V_89 -> V_97 >> 8 ) ) ;
F_6 ( V_6 , V_25 , V_102 ,
V_103 , V_103 ) ;
F_6 ( V_6 , V_25 , V_104 ,
0xFF , ( T_2 ) ( V_95 >> 24 ) ) ;
F_6 ( V_6 , V_25 , V_105 ,
0xFF , ( T_2 ) ( V_95 >> 16 ) ) ;
F_6 ( V_6 , V_25 , V_106 ,
0xFF , ( T_2 ) ( V_95 >> 8 ) ) ;
F_6 ( V_6 , V_25 , V_107 , 0xFF , ( T_2 ) V_95 ) ;
if ( V_91 ) {
F_6 ( V_6 , V_25 , V_108 ,
0x03 | V_109 ,
V_110 | V_111 | V_112 ) ;
} else {
F_6 ( V_6 , V_25 , V_108 ,
0x03 | V_109 ,
V_113 | V_111 | V_112 ) ;
}
F_6 ( V_6 , V_25 , V_37 ,
0x01 , V_114 ) ;
F_6 ( V_6 , V_25 , V_31 , 0xFF , V_94 ) ;
F_6 ( V_6 , V_25 , V_39 , 0xFF ,
V_20 | V_40 ) ;
F_6 ( V_6 , V_41 , V_39 ,
V_42 , V_42 ) ;
F_19 ( V_6 ) ;
V_19 = F_20 ( V_6 , V_89 -> V_115 , V_89 -> V_116 , V_91 , 10000 ) ;
if ( V_19 < 0 ) {
F_2 ( V_3 ) ;
return V_19 ;
}
return 0 ;
}
static inline void F_21 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_117 ,
V_118 , V_119 ) ;
}
static inline void F_22 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_117 ,
V_118 , V_120 ) ;
}
static void F_23 ( struct V_2 * V_3 ,
struct V_82 * V_83 )
{
struct V_45 * V_14 = V_83 -> V_14 ;
struct V_88 * V_89 = V_83 -> V_89 ;
T_2 V_121 [ 5 ] , * V_16 ;
V_121 [ 0 ] = 0x40 | ( T_2 ) V_14 -> V_47 ;
F_24 ( V_14 -> V_48 , ( T_3 * ) ( & V_121 [ 1 ] ) ) ;
V_16 = F_25 ( V_89 -> V_96 , V_122 ) ;
if ( ! V_16 ) {
V_14 -> error = - V_123 ;
return;
}
if ( V_89 -> V_92 & V_93 ) {
if ( V_3 -> V_124 )
F_22 ( V_3 ) ;
V_14 -> error = F_10 ( V_3 , V_121 , ( T_1 ) V_89 -> V_96 , V_16 ,
V_89 -> V_96 , 200 ) ;
if ( V_3 -> V_124 )
F_21 ( V_3 ) ;
F_26 ( V_89 -> V_115 , V_89 -> V_116 , V_16 , V_89 -> V_96 ) ;
} else {
F_27 ( V_89 -> V_115 , V_89 -> V_116 , V_16 , V_89 -> V_96 ) ;
V_14 -> error = F_12 ( V_3 , V_121 , ( T_1 ) V_89 -> V_96 , V_16 ,
V_89 -> V_96 , 200 ) ;
}
F_28 ( V_16 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
T_2 V_125 , bool V_126 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
F_9 ( F_1 ( V_3 ) , L_14 ,
V_21 , V_126 ? L_15 : L_16 , V_125 ) ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_127 , V_128 , V_128 ) ;
if ( V_126 )
F_6 ( V_6 , V_25 ,
V_129 , 0x1F , V_125 ) ;
else
F_6 ( V_6 , V_25 ,
V_130 , 0x1F , V_125 ) ;
F_6 ( V_6 , V_25 , V_131 , V_132 , 0 ) ;
F_6 ( V_6 , V_25 , V_131 ,
V_132 , V_132 ) ;
F_6 ( V_6 , V_25 , V_127 , V_128 , 0 ) ;
F_6 ( V_6 , V_25 , V_117 , V_133 , 0 ) ;
V_19 = F_7 ( V_6 , 100 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static inline T_3 F_30 ( T_3 V_134 , unsigned int V_135 )
{
V_135 %= V_136 ;
return V_134 & ( 1 << V_135 ) ;
}
static int F_31 ( T_3 V_134 , unsigned int V_137 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_136 ; V_11 ++ ) {
if ( F_30 ( V_134 , V_137 + V_11 ) == 0 )
return V_11 ;
}
return V_136 ;
}
static T_2 F_32 ( struct V_2 * V_3 , T_3 V_134 )
{
int V_138 = 0 , V_139 = 0 ;
int V_140 = 0 , V_141 = 0 ;
T_2 V_142 = 0xFF ;
if ( V_134 == 0 ) {
F_33 ( F_1 ( V_3 ) , L_17 , V_134 ) ;
return V_142 ;
}
while ( V_138 < V_136 ) {
V_139 = F_31 ( V_134 , V_138 ) ;
if ( V_141 < V_139 ) {
V_140 = V_138 ;
V_141 = V_139 ;
}
V_138 += V_139 ? V_139 : 1 ;
}
V_142 = ( V_140 + V_141 / 2 ) % V_136 ;
F_9 ( F_1 ( V_3 ) , L_18 ,
V_134 , V_141 , V_142 ) ;
return V_142 ;
}
static void F_34 ( struct V_2 * V_3 )
{
int V_19 , V_11 ;
T_2 V_143 = 0 ;
for ( V_11 = 0 ; V_11 < 100 ; V_11 ++ ) {
V_19 = F_35 ( V_3 -> V_6 , V_144 , & V_143 ) ;
if ( V_143 & V_145 )
return;
F_36 ( 100 ) ;
}
}
static int F_37 ( struct V_2 * V_3 ,
T_2 V_47 , T_2 V_125 )
{
int V_19 ;
T_2 V_14 [ 5 ] = { 0 } ;
V_19 = F_29 ( V_3 , V_125 , true ) ;
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
T_2 V_47 , T_3 * V_134 )
{
int V_19 , V_11 ;
T_3 V_146 = 0 ;
for ( V_11 = 0 ; V_11 < V_136 ; V_11 ++ ) {
V_19 = F_37 ( V_3 , V_47 , ( T_2 ) V_11 ) ;
if ( V_19 == 0 )
V_146 |= 1 << V_11 ;
}
if ( V_134 )
* V_134 = V_146 ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , T_2 V_47 )
{
int V_19 , V_11 ;
T_3 V_146 [ V_147 ] = { 0 } , V_134 ;
T_2 V_142 ;
for ( V_11 = 0 ; V_11 < V_147 ; V_11 ++ ) {
V_19 = F_38 ( V_3 , V_47 , & ( V_146 [ V_11 ] ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_146 [ V_11 ] == 0 )
break;
}
V_134 = 0xFFFFFFFF ;
for ( V_11 = 0 ; V_11 < V_147 ; V_11 ++ ) {
F_9 ( F_1 ( V_3 ) , L_19 ,
V_11 , V_146 [ V_11 ] ) ;
V_134 &= V_146 [ V_11 ] ;
}
F_9 ( F_1 ( V_3 ) , L_20 , V_134 ) ;
if ( V_134 ) {
V_142 = F_32 ( V_3 , V_134 ) ;
if ( V_142 == 0xFF )
return - V_65 ;
V_19 = F_29 ( V_3 , V_142 , true ) ;
if ( V_19 < 0 )
return V_19 ;
} else {
return - V_65 ;
}
return 0 ;
}
static void F_40 ( struct V_84 * V_85 , struct V_82 * V_83 )
{
struct V_2 * V_3 = F_41 ( V_85 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_45 * V_14 = V_83 -> V_14 ;
struct V_88 * V_89 = V_83 -> V_89 ;
unsigned int V_148 = 0 ;
int V_19 ;
if ( V_3 -> V_149 ) {
V_14 -> error = - V_150 ;
goto V_151;
}
V_19 = F_42 ( V_3 -> V_6 , V_152 ) ;
if ( V_19 ) {
V_14 -> error = V_19 ;
goto V_151;
}
F_43 ( & V_6 -> V_153 ) ;
F_44 ( V_6 ) ;
F_45 ( V_6 , V_3 -> clock , V_3 -> V_154 ,
V_3 -> V_124 , V_3 -> V_155 , V_3 -> V_156 ) ;
F_3 ( V_6 , V_157 , 0x07 , V_158 ) ;
F_3 ( V_6 , V_159 ,
V_160 , V_161 ) ;
F_43 ( & V_3 -> V_162 ) ;
V_3 -> V_83 = V_83 ;
F_46 ( & V_3 -> V_162 ) ;
if ( V_83 -> V_89 )
V_148 = V_89 -> V_97 * V_89 -> V_96 ;
if ( ! V_148 || F_47 ( V_14 -> V_47 ) ||
( V_14 -> V_47 == V_163 ) ||
( V_14 -> V_47 == V_164 ) ) {
F_14 ( V_3 , V_14 ) ;
if ( ! V_14 -> error && V_148 ) {
F_17 ( V_3 , V_83 ) ;
if ( F_47 ( V_14 -> V_47 ) && V_83 -> V_165 )
F_14 ( V_3 , V_83 -> V_165 ) ;
}
} else {
F_23 ( V_3 , V_83 ) ;
}
if ( V_83 -> V_89 ) {
if ( V_14 -> error || V_89 -> error )
V_89 -> V_166 = 0 ;
else
V_89 -> V_166 = V_89 -> V_97 * V_89 -> V_96 ;
}
F_46 ( & V_6 -> V_153 ) ;
V_151:
if ( V_14 -> error )
F_9 ( F_1 ( V_3 ) , L_21 , V_14 -> error ) ;
F_43 ( & V_3 -> V_162 ) ;
V_3 -> V_83 = NULL ;
F_46 ( & V_3 -> V_162 ) ;
F_48 ( V_85 , V_83 ) ;
}
static int F_49 ( struct V_2 * V_3 ,
unsigned char V_167 )
{
int V_19 = 0 ;
T_2 V_168 [] = {
[ V_169 ] = V_170 ,
[ V_171 ] = V_172 ,
[ V_173 ] = V_174 ,
} ;
if ( V_167 <= V_173 )
V_19 = F_3 ( V_3 -> V_6 , V_117 ,
0x03 , V_168 [ V_167 ] ) ;
return V_19 ;
}
static int F_50 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
if ( V_3 -> V_175 == V_176 )
return 0 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_157 , 0x07 , V_158 ) ;
F_6 ( V_6 , V_25 , V_159 ,
V_160 , V_161 ) ;
F_6 ( V_6 , V_25 , V_177 ,
V_178 , V_178 ) ;
V_19 = F_7 ( V_6 , 100 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_51 ( V_6 , V_152 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_52 ( V_6 , V_152 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_3 ( V_6 , V_179 , V_180 , V_180 ) ;
if ( V_19 < 0 )
return V_19 ;
V_3 -> V_175 = V_176 ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
V_3 -> V_175 = V_181 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_25 , V_177 , V_178 , 0 ) ;
F_6 ( V_6 , V_25 , V_179 , V_180 , 0 ) ;
V_19 = F_7 ( V_6 , 100 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_54 ( V_6 , V_152 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_55 ( V_6 , V_152 ) ;
}
static int F_56 ( struct V_2 * V_3 ,
unsigned char V_182 )
{
int V_19 ;
if ( V_182 == V_183 )
V_19 = F_53 ( V_3 ) ;
else
V_19 = F_50 ( V_3 ) ;
return V_19 ;
}
static int F_57 ( struct V_2 * V_3 , unsigned char V_184 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 = 0 ;
F_5 ( V_6 ) ;
switch ( V_184 ) {
case V_185 :
case V_186 :
F_6 ( V_6 , V_25 , V_117 ,
0x0C | V_133 ,
V_187 | V_133 ) ;
F_6 ( V_6 , V_25 , V_127 ,
V_188 , V_188 ) ;
F_6 ( V_6 , V_25 , V_189 , 0xFF ,
V_190 | V_191 | V_192 ) ;
F_6 ( V_6 , V_25 , V_127 , V_188 , 0 ) ;
break;
case V_193 :
case V_194 :
F_6 ( V_6 , V_25 , V_117 ,
0x0C | V_133 ,
V_195 | V_133 ) ;
F_6 ( V_6 , V_25 , V_127 ,
V_188 , V_188 ) ;
F_6 ( V_6 , V_25 , V_189 , 0xFF ,
V_190 | V_191 | V_192 ) ;
F_6 ( V_6 , V_25 , V_127 , V_188 , 0 ) ;
F_6 ( V_6 , V_25 , V_196 ,
V_197 , V_197 ) ;
F_6 ( V_6 , V_25 , V_198 ,
V_199 | V_200 ,
V_199 | V_200 ) ;
break;
case V_201 :
case V_202 :
F_6 ( V_6 , V_25 , V_117 ,
0x0C , V_203 ) ;
F_6 ( V_6 , V_25 , V_127 ,
V_188 , V_188 ) ;
F_6 ( V_6 , V_25 , V_189 , 0xFF ,
V_204 | V_205 | V_192 ) ;
F_6 ( V_6 , V_25 , V_127 , V_188 , 0 ) ;
F_6 ( V_6 , V_25 , V_196 ,
V_206 , V_207 ) ;
F_6 ( V_6 , V_25 , V_198 ,
V_208 , V_209 ) ;
break;
default:
F_6 ( V_6 , V_25 ,
V_117 , 0x0C , V_203 ) ;
F_6 ( V_6 , V_25 , V_127 ,
V_188 , V_188 ) ;
F_6 ( V_6 , V_25 , V_189 , 0xFF ,
V_204 | V_205 | V_192 ) ;
F_6 ( V_6 , V_25 , V_127 , V_188 , 0 ) ;
F_6 ( V_6 , V_25 ,
V_196 , 0xFF , 0 ) ;
F_6 ( V_6 , V_25 , V_198 ,
V_208 , V_210 ) ;
break;
}
V_19 = F_7 ( V_6 , 100 ) ;
return V_19 ;
}
static void F_58 ( struct V_84 * V_85 , struct V_211 * V_212 )
{
struct V_2 * V_3 = F_41 ( V_85 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_149 )
return;
if ( F_42 ( V_3 -> V_6 , V_152 ) )
return;
F_43 ( & V_6 -> V_153 ) ;
F_44 ( V_6 ) ;
F_49 ( V_3 , V_212 -> V_167 ) ;
F_56 ( V_3 , V_212 -> V_182 ) ;
F_57 ( V_3 , V_212 -> V_184 ) ;
V_3 -> V_156 = false ;
V_3 -> V_155 = true ;
switch ( V_212 -> V_184 ) {
case V_185 :
case V_186 :
V_3 -> V_154 = V_213 ;
V_3 -> V_156 = true ;
V_3 -> V_155 = false ;
break;
case V_193 :
case V_194 :
case V_214 :
V_3 -> V_154 = V_215 ;
break;
default:
V_3 -> V_154 = V_216 ;
break;
}
V_3 -> V_124 = ( V_212 -> clock <= 1000000 ) ? true : false ;
V_3 -> clock = V_212 -> clock ;
F_45 ( V_6 , V_212 -> clock , V_3 -> V_154 ,
V_3 -> V_124 , V_3 -> V_155 , V_3 -> V_156 ) ;
F_46 ( & V_6 -> V_153 ) ;
}
static int F_59 ( struct V_84 * V_85 )
{
struct V_2 * V_3 = F_41 ( V_85 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_217 = 0 ;
T_3 V_143 ;
if ( V_3 -> V_149 )
return - V_150 ;
F_43 ( & V_6 -> V_153 ) ;
F_44 ( V_6 ) ;
V_143 = F_60 ( V_6 , V_218 ) ;
F_9 ( F_1 ( V_3 ) , L_22 , V_21 , V_143 ) ;
if ( V_143 & V_219 )
V_217 = 1 ;
F_46 ( & V_6 -> V_153 ) ;
return V_217 ;
}
static int F_61 ( struct V_84 * V_85 )
{
struct V_2 * V_3 = F_41 ( V_85 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_220 = 0 ;
T_3 V_143 ;
if ( V_3 -> V_149 )
return - V_150 ;
F_43 ( & V_6 -> V_153 ) ;
F_44 ( V_6 ) ;
V_143 = F_62 ( V_6 ) ;
F_9 ( F_1 ( V_3 ) , L_22 , V_21 , V_143 ) ;
if ( V_143 & V_221 )
V_220 = 1 ;
F_46 ( & V_6 -> V_153 ) ;
return V_220 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
T_2 V_222 ;
F_64 ( 1 ) ;
V_19 = F_35 ( V_6 , V_68 , & V_222 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_222 & ( V_223 | V_224 | V_225 |
V_226 | V_227 ) )
return - V_65 ;
V_19 = F_3 ( V_6 , V_68 ,
0xFF , V_81 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 ;
T_2 V_222 , V_228 , V_143 ;
F_66 ( 50 ) ;
V_19 = F_3 ( V_6 , V_68 , 0xFF , V_69 ) ;
if ( V_19 < 0 )
return V_19 ;
F_66 ( 20 ) ;
V_19 = F_35 ( V_6 , V_68 , & V_222 ) ;
if ( V_19 < 0 )
return V_19 ;
V_228 = V_223 | V_224 | V_225 |
V_226 | V_227 ;
V_143 = V_223 | V_224 | V_225 |
V_226 | V_227 ;
if ( ( V_222 & V_228 ) != V_143 ) {
F_9 ( F_1 ( V_3 ) ,
L_23 , V_21 , V_222 ) ;
F_3 ( V_6 , V_68 ,
V_69 | V_81 , 0 ) ;
F_3 ( V_6 , V_177 , 0xFF , 0 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_67 ( struct V_84 * V_85 , struct V_211 * V_212 )
{
struct V_2 * V_3 = F_41 ( V_85 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 = 0 ;
T_2 V_229 ;
F_9 ( F_1 ( V_3 ) , L_24 ,
V_21 , V_212 -> V_230 ) ;
if ( V_3 -> V_149 )
return - V_150 ;
V_19 = F_42 ( V_3 -> V_6 , V_152 ) ;
if ( V_19 )
return V_19 ;
F_43 ( & V_6 -> V_153 ) ;
F_44 ( V_6 ) ;
if ( V_212 -> V_230 == V_231 )
V_229 = V_232 ;
else
V_229 = V_233 ;
if ( V_229 == V_233 ) {
V_19 = F_63 ( V_3 ) ;
if ( V_19 < 0 )
goto V_66;
}
V_19 = F_68 ( V_6 , V_229 ) ;
if ( V_19 < 0 )
goto V_66;
if ( V_229 == V_233 ) {
V_19 = F_65 ( V_3 ) ;
if ( V_19 < 0 )
goto V_66;
}
V_66:
V_19 = F_3 ( V_6 , V_68 ,
V_69 | V_81 , 0 ) ;
F_46 ( & V_6 -> V_153 ) ;
return V_19 ;
}
static int F_69 ( struct V_84 * V_85 , T_3 V_47 )
{
struct V_2 * V_3 = F_41 ( V_85 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_19 = 0 ;
if ( V_3 -> V_149 )
return - V_150 ;
V_19 = F_42 ( V_3 -> V_6 , V_152 ) ;
if ( V_19 )
return V_19 ;
F_43 ( & V_6 -> V_153 ) ;
F_44 ( V_6 ) ;
switch ( V_85 -> V_212 . V_184 ) {
case V_185 :
V_19 = F_29 ( V_3 , F_70 ( V_6 ) , false ) ;
break;
case V_186 :
V_19 = F_29 ( V_3 , F_71 ( V_6 ) , false ) ;
break;
case V_194 :
V_19 = F_29 ( V_3 , F_72 ( V_6 ) , false ) ;
break;
default:
V_19 = 0 ;
}
if ( V_19 )
goto V_66;
if ( ( V_85 -> V_212 . V_184 == V_185 ) ||
( V_85 -> V_212 . V_184 == V_186 ) )
V_19 = F_39 ( V_3 , V_47 ) ;
else if ( V_85 -> V_212 . V_184 == V_194 )
V_19 = F_29 ( V_3 , F_73 ( V_6 ) , true ) ;
V_66:
F_46 ( & V_6 -> V_153 ) ;
return V_19 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_84 * V_85 = V_3 -> V_85 ;
struct V_10 * V_6 = V_3 -> V_6 ;
F_9 ( F_1 ( V_3 ) , L_25 , V_6 -> V_234 ) ;
if ( V_6 -> V_234 & V_235 )
V_85 -> V_236 |= V_237 ;
if ( V_6 -> V_234 & V_238 )
V_85 -> V_236 |= V_239 ;
if ( V_6 -> V_234 & V_240 )
V_85 -> V_236 |= V_241 ;
if ( V_6 -> V_234 & V_242 )
V_85 -> V_236 |= V_243 ;
if ( V_6 -> V_234 & V_244 )
V_85 -> V_236 |= V_245 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_84 * V_85 = V_3 -> V_85 ;
V_85 -> V_246 = 250000 ;
V_85 -> V_247 = 208000000 ;
V_85 -> V_248 = V_249 | V_250 | V_251 ;
V_85 -> V_236 = V_252 | V_253 |
V_254 | V_255 |
V_256 | V_257 ;
V_85 -> V_258 = 400 ;
V_85 -> V_259 = 800 ;
V_85 -> V_260 = & V_261 ;
F_74 ( V_3 ) ;
V_85 -> V_262 = 256 ;
V_85 -> V_263 = 65536 ;
V_85 -> V_264 = 512 ;
V_85 -> V_265 = 65535 ;
V_85 -> V_266 = 524288 ;
}
static void F_76 ( struct V_267 * V_4 )
{
struct V_2 * V_3 = F_77 ( V_4 ) ;
F_78 ( V_3 -> V_85 , 0 ) ;
}
static int F_79 ( struct V_267 * V_4 )
{
struct V_84 * V_85 ;
struct V_2 * V_3 ;
struct V_10 * V_6 ;
struct V_268 * V_269 = V_4 -> V_5 . V_270 ;
if ( ! V_269 )
return - V_271 ;
V_6 = V_269 -> V_6 ;
if ( ! V_6 )
return - V_271 ;
F_9 ( & ( V_4 -> V_5 ) , L_26 ) ;
V_85 = F_80 ( sizeof( * V_3 ) , & V_4 -> V_5 ) ;
if ( ! V_85 )
return - V_123 ;
V_3 = F_41 ( V_85 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_85 = V_85 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_175 = V_181 ;
F_81 ( V_4 , V_3 ) ;
V_6 -> V_272 [ V_152 ] . V_273 = V_4 ;
V_6 -> V_272 [ V_152 ] . V_274 = F_76 ;
F_82 ( & V_3 -> V_162 ) ;
F_75 ( V_3 ) ;
F_83 ( V_85 ) ;
return 0 ;
}
static int F_84 ( struct V_267 * V_4 )
{
struct V_2 * V_3 = F_77 ( V_4 ) ;
struct V_10 * V_6 ;
struct V_84 * V_85 ;
if ( ! V_3 )
return 0 ;
V_6 = V_3 -> V_6 ;
V_6 -> V_272 [ V_152 ] . V_273 = NULL ;
V_6 -> V_272 [ V_152 ] . V_274 = NULL ;
V_85 = V_3 -> V_85 ;
F_43 ( & V_3 -> V_162 ) ;
if ( V_3 -> V_83 ) {
F_9 ( & ( V_4 -> V_5 ) ,
L_27 ,
F_85 ( V_85 ) ) ;
F_86 ( V_6 ) ;
V_3 -> V_83 -> V_14 -> error = - V_150 ;
if ( V_3 -> V_83 -> V_165 )
V_3 -> V_83 -> V_165 -> error = - V_150 ;
F_48 ( V_85 , V_3 -> V_83 ) ;
}
F_46 ( & V_3 -> V_162 ) ;
F_87 ( V_85 ) ;
V_3 -> V_149 = true ;
F_88 ( V_85 ) ;
F_9 ( & ( V_4 -> V_5 ) ,
L_28 ) ;
return 0 ;
}
