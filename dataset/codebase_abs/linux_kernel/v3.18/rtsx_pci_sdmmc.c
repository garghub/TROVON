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
static int F_10 ( struct V_2 * V_3 ,
struct V_14 * V_15 , bool V_16 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_17 = V_15 -> V_18 & V_19 ;
int V_20 = 0 ;
int V_21 = 0 ;
if ( ! V_16 && V_15 -> V_22 && V_15 -> V_22 != V_3 -> V_23 ) {
F_11 ( F_1 ( V_3 ) ,
L_2 ,
V_15 -> V_22 , V_3 -> V_23 ) ;
V_15 -> V_22 = 0 ;
}
if ( V_16 || V_15 -> V_22 != V_3 -> V_23 ) {
V_20 = F_12 ( V_6 , V_15 -> V_24 , V_15 -> V_25 , V_17 ) ;
} else {
V_20 = V_3 -> V_26 ;
V_21 = 1 ;
}
if ( V_16 ) {
V_3 -> V_26 = V_20 ;
if ( ++ V_3 -> V_23 < 0 )
V_3 -> V_23 = 1 ;
V_15 -> V_22 = V_3 -> V_23 ;
} else {
V_3 -> V_27 = V_20 ;
}
return V_21 ;
}
static void F_13 ( struct V_28 * V_29 , struct V_30 * V_31 ,
bool V_32 )
{
struct V_2 * V_3 = F_14 ( V_29 ) ;
struct V_14 * V_15 = V_31 -> V_15 ;
if ( V_15 -> V_22 ) {
F_11 ( F_1 ( V_3 ) ,
L_3 ,
V_15 -> V_22 ) ;
V_15 -> V_22 = 0 ;
}
F_10 ( V_3 , V_15 , true ) ;
F_9 ( F_1 ( V_3 ) , L_4 , V_3 -> V_26 ) ;
}
static void F_15 ( struct V_28 * V_29 , struct V_30 * V_31 ,
int V_33 )
{
struct V_2 * V_3 = F_14 ( V_29 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_14 * V_15 = V_31 -> V_15 ;
int V_17 = V_15 -> V_18 & V_19 ;
F_16 ( V_6 , V_15 -> V_24 , V_15 -> V_25 , V_17 ) ;
V_15 -> V_22 = 0 ;
}
static int F_17 ( struct V_2 * V_3 , T_2 * V_34 , T_1 V_35 ,
T_2 * V_36 , int V_37 , int V_38 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 , V_11 ;
T_2 V_39 ;
F_9 ( F_1 ( V_3 ) , L_5 , V_40 , V_34 [ 0 ] - 0x40 ) ;
if ( ! V_36 )
V_37 = 0 ;
if ( ( V_34 [ 0 ] & 0x3F ) == V_41 )
V_39 = V_42 ;
else
V_39 = V_43 ;
F_5 ( V_6 ) ;
for ( V_11 = 0 ; V_11 < 5 ; V_11 ++ )
F_6 ( V_6 , V_44 , V_45 + V_11 , 0xFF , V_34 [ V_11 ] ) ;
F_6 ( V_6 , V_44 , V_46 , 0xFF , ( T_2 ) V_35 ) ;
F_6 ( V_6 , V_44 , V_47 ,
0xFF , ( T_2 ) ( V_35 >> 8 ) ) ;
F_6 ( V_6 , V_44 , V_48 , 0xFF , 1 ) ;
F_6 ( V_6 , V_44 , V_49 , 0xFF , 0 ) ;
F_6 ( V_6 , V_44 , V_50 , 0xFF ,
V_51 | V_52 |
V_53 | V_54 | V_55 ) ;
if ( V_39 != V_42 )
F_6 ( V_6 , V_44 ,
V_56 , 0x01 , V_57 ) ;
F_6 ( V_6 , V_44 , V_58 ,
0xFF , V_39 | V_59 ) ;
F_6 ( V_6 , V_60 , V_58 ,
V_61 , V_61 ) ;
V_33 = F_7 ( V_6 , V_38 ) ;
if ( V_33 < 0 ) {
F_4 ( V_3 ) ;
F_9 ( F_1 ( V_3 ) ,
L_6 , V_33 ) ;
return V_33 ;
}
if ( V_36 && V_37 ) {
V_33 = F_18 ( V_6 , V_36 , V_37 ) ;
if ( V_33 < 0 ) {
F_9 ( F_1 ( V_3 ) ,
L_7 , V_33 ) ;
return V_33 ;
}
}
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_2 * V_34 , T_1 V_35 ,
T_2 * V_36 , int V_37 , int V_38 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 , V_11 ;
T_2 V_39 ;
if ( ! V_36 )
V_37 = 0 ;
if ( V_36 && V_37 ) {
V_33 = F_20 ( V_6 , V_36 , V_37 ) ;
if ( V_33 < 0 ) {
F_9 ( F_1 ( V_3 ) ,
L_8 , V_33 ) ;
return V_33 ;
}
}
V_39 = V_34 ? V_62 : V_63 ;
F_5 ( V_6 ) ;
if ( V_34 ) {
F_9 ( F_1 ( V_3 ) , L_9 , V_40 ,
V_34 [ 0 ] - 0x40 ) ;
for ( V_11 = 0 ; V_11 < 5 ; V_11 ++ )
F_6 ( V_6 , V_44 ,
V_45 + V_11 , 0xFF , V_34 [ V_11 ] ) ;
}
F_6 ( V_6 , V_44 , V_46 , 0xFF , ( T_2 ) V_35 ) ;
F_6 ( V_6 , V_44 , V_47 ,
0xFF , ( T_2 ) ( V_35 >> 8 ) ) ;
F_6 ( V_6 , V_44 , V_48 , 0xFF , 1 ) ;
F_6 ( V_6 , V_44 , V_49 , 0xFF , 0 ) ;
F_6 ( V_6 , V_44 , V_50 , 0xFF ,
V_51 | V_52 |
V_53 | V_54 | V_55 ) ;
F_6 ( V_6 , V_44 , V_58 , 0xFF ,
V_39 | V_59 ) ;
F_6 ( V_6 , V_60 , V_58 ,
V_61 , V_61 ) ;
V_33 = F_7 ( V_6 , V_38 ) ;
if ( V_33 < 0 ) {
F_4 ( V_3 ) ;
F_9 ( F_1 ( V_3 ) ,
L_6 , V_33 ) ;
return V_33 ;
}
return 0 ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_64 * V_34 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
T_2 V_65 = ( T_2 ) V_34 -> V_66 ;
T_3 V_67 = V_34 -> V_67 ;
int V_33 = 0 ;
int V_38 = 100 ;
int V_11 ;
T_2 * V_12 ;
int V_68 = 0 ;
T_2 V_69 ;
int V_70 = 5 ;
bool V_71 = false ;
F_9 ( F_1 ( V_3 ) , L_10 ,
V_40 , V_65 , V_67 ) ;
switch ( F_22 ( V_34 ) ) {
case V_72 :
V_69 = V_73 ;
V_70 = 0 ;
break;
case V_74 :
V_69 = V_75 ;
break;
case V_74 & ~ V_76 :
V_69 = V_75 | V_77 ;
break;
case V_78 :
V_69 = V_79 ;
break;
case V_80 :
V_69 = V_81 ;
V_70 = 16 ;
break;
case V_82 :
V_69 = V_83 ;
break;
default:
F_9 ( F_1 ( V_3 ) , L_11 ) ;
V_33 = - V_84 ;
goto V_85;
}
if ( V_69 == V_79 )
V_38 = 3000 ;
if ( V_34 -> V_66 == V_86 ) {
V_33 = F_3 ( V_6 , V_87 ,
0xFF , V_88 ) ;
if ( V_33 < 0 )
goto V_85;
V_71 = true ;
}
F_5 ( V_6 ) ;
F_6 ( V_6 , V_44 , V_45 , 0xFF , 0x40 | V_65 ) ;
F_6 ( V_6 , V_44 , V_89 , 0xFF , ( T_2 ) ( V_67 >> 24 ) ) ;
F_6 ( V_6 , V_44 , V_90 , 0xFF , ( T_2 ) ( V_67 >> 16 ) ) ;
F_6 ( V_6 , V_44 , V_91 , 0xFF , ( T_2 ) ( V_67 >> 8 ) ) ;
F_6 ( V_6 , V_44 , V_92 , 0xFF , ( T_2 ) V_67 ) ;
F_6 ( V_6 , V_44 , V_50 , 0xFF , V_69 ) ;
F_6 ( V_6 , V_44 , V_56 ,
0x01 , V_57 ) ;
F_6 ( V_6 , V_44 , V_58 ,
0xFF , V_93 | V_59 ) ;
F_6 ( V_6 , V_60 , V_58 ,
V_61 | V_94 ,
V_61 | V_94 ) ;
if ( V_69 == V_81 ) {
for ( V_11 = V_95 ; V_11 < V_95 + 16 ; V_11 ++ )
F_6 ( V_6 , V_13 , ( T_1 ) V_11 , 0 , 0 ) ;
V_68 = 16 ;
} else if ( V_69 != V_73 ) {
for ( V_11 = V_45 ; V_11 <= V_92 ; V_11 ++ )
F_6 ( V_6 , V_13 , ( T_1 ) V_11 , 0 , 0 ) ;
V_68 = 5 ;
}
F_6 ( V_6 , V_13 , V_96 , 0 , 0 ) ;
V_33 = F_7 ( V_6 , V_38 ) ;
if ( V_33 < 0 ) {
F_4 ( V_3 ) ;
F_2 ( V_3 ) ;
F_9 ( F_1 ( V_3 ) ,
L_12 , V_33 ) ;
goto V_85;
}
if ( V_69 == V_73 ) {
V_33 = 0 ;
goto V_85;
}
V_12 = F_8 ( V_6 ) + 1 ;
if ( ( V_12 [ 0 ] & 0xC0 ) != 0 ) {
V_33 = - V_97 ;
F_9 ( F_1 ( V_3 ) , L_13 ) ;
goto V_85;
}
if ( ! ( V_69 & V_77 ) ) {
if ( V_12 [ V_68 ] & V_98 ) {
V_33 = - V_97 ;
F_9 ( F_1 ( V_3 ) , L_14 ) ;
goto V_85;
}
}
if ( V_69 == V_81 ) {
V_12 [ 16 ] = 1 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_34 -> V_99 [ V_11 ] = F_23 ( V_12 + 1 + V_11 * 4 ) ;
F_9 ( F_1 ( V_3 ) , L_15 ,
V_11 , V_34 -> V_99 [ V_11 ] ) ;
}
} else {
V_34 -> V_99 [ 0 ] = F_23 ( V_12 + 1 ) ;
F_9 ( F_1 ( V_3 ) , L_16 ,
V_34 -> V_99 [ 0 ] ) ;
}
V_85:
V_34 -> error = V_33 ;
if ( V_33 && V_71 )
F_3 ( V_6 , V_87 ,
V_88 | V_100 , 0 ) ;
}
static int F_24 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_28 * V_29 = V_3 -> V_29 ;
struct V_101 * V_102 = V_29 -> V_102 ;
struct V_14 * V_15 = V_31 -> V_15 ;
int V_103 = F_25 ( V_102 ) ;
int V_17 = ( V_15 -> V_18 & V_19 ) ? 1 : 0 ;
T_2 V_104 , V_39 ;
int V_33 ;
T_4 V_105 = V_15 -> V_106 * V_15 -> V_107 ;
if ( V_17 ) {
V_104 = V_51 | V_52 |
V_53 | V_54 | V_108 ;
V_39 = V_109 ;
} else {
V_104 = V_110 | V_52 |
V_53 | V_77 | V_108 ;
V_39 = V_63 ;
}
if ( ! V_103 )
V_104 |= V_111 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_44 , V_46 , 0xFF , 0x00 ) ;
F_6 ( V_6 , V_44 , V_47 , 0xFF , 0x02 ) ;
F_6 ( V_6 , V_44 , V_48 ,
0xFF , ( T_2 ) V_15 -> V_107 ) ;
F_6 ( V_6 , V_44 , V_49 ,
0xFF , ( T_2 ) ( V_15 -> V_107 >> 8 ) ) ;
F_6 ( V_6 , V_44 , V_112 ,
V_113 , V_113 ) ;
F_6 ( V_6 , V_44 , V_114 ,
0xFF , ( T_2 ) ( V_105 >> 24 ) ) ;
F_6 ( V_6 , V_44 , V_115 ,
0xFF , ( T_2 ) ( V_105 >> 16 ) ) ;
F_6 ( V_6 , V_44 , V_116 ,
0xFF , ( T_2 ) ( V_105 >> 8 ) ) ;
F_6 ( V_6 , V_44 , V_117 , 0xFF , ( T_2 ) V_105 ) ;
if ( V_17 ) {
F_6 ( V_6 , V_44 , V_118 ,
0x03 | V_119 ,
V_120 | V_121 | V_122 ) ;
} else {
F_6 ( V_6 , V_44 , V_118 ,
0x03 | V_119 ,
V_123 | V_121 | V_122 ) ;
}
F_6 ( V_6 , V_44 , V_56 ,
0x01 , V_124 ) ;
F_6 ( V_6 , V_44 , V_50 , 0xFF , V_104 ) ;
F_6 ( V_6 , V_44 , V_58 , 0xFF ,
V_39 | V_59 ) ;
F_6 ( V_6 , V_60 , V_58 ,
V_61 , V_61 ) ;
F_26 ( V_6 ) ;
V_33 = F_27 ( V_6 , V_15 -> V_24 , V_3 -> V_27 , V_17 , 10000 ) ;
if ( V_33 < 0 ) {
F_2 ( V_3 ) ;
return V_33 ;
}
return 0 ;
}
static inline void F_28 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_125 ,
V_126 , V_127 ) ;
}
static inline void F_29 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_125 ,
V_126 , V_128 ) ;
}
static void F_30 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
struct V_64 * V_34 = V_31 -> V_34 ;
struct V_14 * V_15 = V_31 -> V_15 ;
T_2 V_129 [ 5 ] , * V_36 ;
V_129 [ 0 ] = 0x40 | ( T_2 ) V_34 -> V_66 ;
F_31 ( V_34 -> V_67 , ( T_3 * ) ( & V_129 [ 1 ] ) ) ;
V_36 = F_32 ( V_15 -> V_106 , V_130 ) ;
if ( ! V_36 ) {
V_34 -> error = - V_131 ;
return;
}
if ( V_15 -> V_18 & V_19 ) {
if ( V_3 -> V_132 )
F_29 ( V_3 ) ;
V_34 -> error = F_17 ( V_3 , V_129 , ( T_1 ) V_15 -> V_106 , V_36 ,
V_15 -> V_106 , 200 ) ;
if ( V_3 -> V_132 )
F_28 ( V_3 ) ;
F_33 ( V_15 -> V_24 , V_15 -> V_25 , V_36 , V_15 -> V_106 ) ;
} else {
F_34 ( V_15 -> V_24 , V_15 -> V_25 , V_36 , V_15 -> V_106 ) ;
V_34 -> error = F_19 ( V_3 , V_129 , ( T_1 ) V_15 -> V_106 , V_36 ,
V_15 -> V_106 , 200 ) ;
}
F_35 ( V_36 ) ;
}
static int F_36 ( struct V_2 * V_3 ,
T_2 V_133 , bool V_134 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 ;
F_9 ( F_1 ( V_3 ) , L_17 ,
V_40 , V_134 ? L_18 : L_19 , V_133 ) ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_44 , V_135 , V_136 , V_136 ) ;
if ( V_134 )
F_6 ( V_6 , V_44 ,
V_137 , 0x1F , V_133 ) ;
else
F_6 ( V_6 , V_44 ,
V_138 , 0x1F , V_133 ) ;
F_6 ( V_6 , V_44 , V_139 , V_140 , 0 ) ;
F_6 ( V_6 , V_44 , V_139 ,
V_140 , V_140 ) ;
F_6 ( V_6 , V_44 , V_135 , V_136 , 0 ) ;
F_6 ( V_6 , V_44 , V_125 , V_141 , 0 ) ;
V_33 = F_7 ( V_6 , 100 ) ;
if ( V_33 < 0 )
return V_33 ;
return 0 ;
}
static inline T_3 F_37 ( T_3 V_142 , unsigned int V_143 )
{
V_143 %= V_144 ;
return V_142 & ( 1 << V_143 ) ;
}
static int F_38 ( T_3 V_142 , unsigned int V_145 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_144 ; V_11 ++ ) {
if ( F_37 ( V_142 , V_145 + V_11 ) == 0 )
return V_11 ;
}
return V_144 ;
}
static T_2 F_39 ( struct V_2 * V_3 , T_3 V_142 )
{
int V_146 = 0 , V_147 = 0 ;
int V_148 = 0 , V_149 = 0 ;
T_2 V_150 = 0xFF ;
if ( V_142 == 0 ) {
F_11 ( F_1 ( V_3 ) , L_20 , V_142 ) ;
return V_150 ;
}
while ( V_146 < V_144 ) {
V_147 = F_38 ( V_142 , V_146 ) ;
if ( V_149 < V_147 ) {
V_148 = V_146 ;
V_149 = V_147 ;
}
V_146 += V_147 ? V_147 : 1 ;
}
V_150 = ( V_148 + V_149 / 2 ) % V_144 ;
F_9 ( F_1 ( V_3 ) , L_21 ,
V_142 , V_149 , V_150 ) ;
return V_150 ;
}
static void F_40 ( struct V_2 * V_3 )
{
int V_33 , V_11 ;
T_2 V_151 = 0 ;
for ( V_11 = 0 ; V_11 < 100 ; V_11 ++ ) {
V_33 = F_41 ( V_3 -> V_6 , V_152 , & V_151 ) ;
if ( V_151 & V_153 )
return;
F_42 ( 100 ) ;
}
}
static int F_43 ( struct V_2 * V_3 ,
T_2 V_66 , T_2 V_133 )
{
int V_33 ;
T_2 V_34 [ 5 ] = { 0 } ;
V_33 = F_36 ( V_3 , V_133 , true ) ;
if ( V_33 < 0 )
return V_33 ;
V_34 [ 0 ] = 0x40 | V_66 ;
V_33 = F_17 ( V_3 , V_34 , 0x40 , NULL , 0 , 100 ) ;
if ( V_33 < 0 ) {
F_40 ( V_3 ) ;
F_2 ( V_3 ) ;
return V_33 ;
}
return 0 ;
}
static int F_44 ( struct V_2 * V_3 ,
T_2 V_66 , T_3 * V_142 )
{
int V_33 , V_11 ;
T_3 V_154 = 0 ;
for ( V_11 = 0 ; V_11 < V_144 ; V_11 ++ ) {
V_33 = F_43 ( V_3 , V_66 , ( T_2 ) V_11 ) ;
if ( V_33 == 0 )
V_154 |= 1 << V_11 ;
}
if ( V_142 )
* V_142 = V_154 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , T_2 V_66 )
{
int V_33 , V_11 ;
T_3 V_154 [ V_155 ] = { 0 } , V_142 ;
T_2 V_150 ;
for ( V_11 = 0 ; V_11 < V_155 ; V_11 ++ ) {
V_33 = F_44 ( V_3 , V_66 , & ( V_154 [ V_11 ] ) ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_154 [ V_11 ] == 0 )
break;
}
V_142 = 0xFFFFFFFF ;
for ( V_11 = 0 ; V_11 < V_155 ; V_11 ++ ) {
F_9 ( F_1 ( V_3 ) , L_22 ,
V_11 , V_154 [ V_11 ] ) ;
V_142 &= V_154 [ V_11 ] ;
}
F_9 ( F_1 ( V_3 ) , L_23 , V_142 ) ;
if ( V_142 ) {
V_150 = F_39 ( V_3 , V_142 ) ;
if ( V_150 == 0xFF )
return - V_84 ;
V_33 = F_36 ( V_3 , V_150 , true ) ;
if ( V_33 < 0 )
return V_33 ;
} else {
return - V_84 ;
}
return 0 ;
}
static inline int F_46 ( struct V_64 * V_34 )
{
return F_47 ( V_34 -> V_66 ) ||
( V_34 -> V_66 == V_156 ) ||
( V_34 -> V_66 == V_157 ) ;
}
static void F_48 ( struct V_158 * V_159 )
{
struct V_2 * V_3 = F_49 ( V_159 ,
struct V_2 , V_159 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_28 * V_29 = V_3 -> V_29 ;
struct V_30 * V_31 = V_3 -> V_31 ;
struct V_64 * V_34 = V_31 -> V_34 ;
struct V_14 * V_15 = V_31 -> V_15 ;
unsigned int V_160 = 0 ;
int V_33 ;
if ( V_3 -> V_161 ) {
V_34 -> error = - V_162 ;
goto V_163;
}
V_33 = F_50 ( V_3 -> V_6 , V_164 ) ;
if ( V_33 ) {
V_34 -> error = V_33 ;
goto V_163;
}
F_51 ( & V_6 -> V_165 ) ;
F_52 ( V_6 ) ;
F_53 ( V_6 , V_3 -> clock , V_3 -> V_166 ,
V_3 -> V_132 , V_3 -> V_167 , V_3 -> V_168 ) ;
F_3 ( V_6 , V_169 , 0x07 , V_170 ) ;
F_3 ( V_6 , V_171 ,
V_172 , V_173 ) ;
F_51 ( & V_3 -> V_174 ) ;
V_3 -> V_31 = V_31 ;
F_54 ( & V_3 -> V_174 ) ;
if ( V_31 -> V_15 )
V_160 = V_15 -> V_107 * V_15 -> V_106 ;
if ( ! V_160 || F_46 ( V_34 ) ) {
F_21 ( V_3 , V_34 ) ;
if ( ! V_34 -> error && V_160 ) {
F_24 ( V_3 , V_31 ) ;
if ( ! V_3 -> V_21 )
F_15 ( V_3 -> V_29 , V_3 -> V_31 , 0 ) ;
if ( F_47 ( V_34 -> V_66 ) && V_31 -> V_175 )
F_21 ( V_3 , V_31 -> V_175 ) ;
}
} else {
F_30 ( V_3 , V_31 ) ;
}
if ( V_31 -> V_15 ) {
if ( V_34 -> error || V_15 -> error )
V_15 -> V_176 = 0 ;
else
V_15 -> V_176 = V_15 -> V_107 * V_15 -> V_106 ;
}
F_54 ( & V_6 -> V_165 ) ;
V_163:
if ( V_34 -> error )
F_9 ( F_1 ( V_3 ) , L_24 , V_34 -> error ) ;
F_51 ( & V_3 -> V_174 ) ;
V_3 -> V_31 = NULL ;
F_54 ( & V_3 -> V_174 ) ;
F_55 ( V_29 , V_31 ) ;
}
static void F_56 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
struct V_2 * V_3 = F_14 ( V_29 ) ;
struct V_14 * V_15 = V_31 -> V_15 ;
F_51 ( & V_3 -> V_174 ) ;
V_3 -> V_31 = V_31 ;
F_54 ( & V_3 -> V_174 ) ;
if ( F_46 ( V_31 -> V_34 ) )
V_3 -> V_21 = F_10 ( V_3 , V_15 , false ) ;
F_57 ( V_3 -> V_177 , & V_3 -> V_159 ) ;
}
static int F_58 ( struct V_2 * V_3 ,
unsigned char V_178 )
{
int V_33 = 0 ;
T_2 V_179 [] = {
[ V_180 ] = V_181 ,
[ V_182 ] = V_183 ,
[ V_184 ] = V_185 ,
} ;
if ( V_178 <= V_184 )
V_33 = F_3 ( V_3 -> V_6 , V_125 ,
0x03 , V_179 [ V_178 ] ) ;
return V_33 ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 ;
if ( V_3 -> V_186 == V_187 )
return 0 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_44 , V_169 , 0x07 , V_170 ) ;
F_6 ( V_6 , V_44 , V_171 ,
V_172 , V_173 ) ;
F_6 ( V_6 , V_44 , V_188 ,
V_189 , V_189 ) ;
V_33 = F_7 ( V_6 , 100 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_60 ( V_6 , V_164 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_61 ( V_6 , V_164 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_3 ( V_6 , V_190 , V_191 , V_191 ) ;
if ( V_33 < 0 )
return V_33 ;
V_3 -> V_186 = V_187 ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 ;
V_3 -> V_186 = V_192 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_44 , V_188 , V_189 , 0 ) ;
F_6 ( V_6 , V_44 , V_190 , V_191 , 0 ) ;
V_33 = F_7 ( V_6 , 100 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_63 ( V_6 , V_164 ) ;
if ( V_33 < 0 )
return V_33 ;
return F_64 ( V_6 , V_164 ) ;
}
static int F_65 ( struct V_2 * V_3 ,
unsigned char V_193 )
{
int V_33 ;
if ( V_193 == V_194 )
V_33 = F_62 ( V_3 ) ;
else
V_33 = F_59 ( V_3 ) ;
return V_33 ;
}
static int F_66 ( struct V_2 * V_3 , unsigned char V_195 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 = 0 ;
F_5 ( V_6 ) ;
switch ( V_195 ) {
case V_196 :
case V_197 :
F_6 ( V_6 , V_44 , V_125 ,
0x0C | V_141 ,
V_198 | V_141 ) ;
F_6 ( V_6 , V_44 , V_135 ,
V_199 , V_199 ) ;
F_6 ( V_6 , V_44 , V_200 , 0xFF ,
V_201 | V_202 | V_203 ) ;
F_6 ( V_6 , V_44 , V_135 , V_199 , 0 ) ;
break;
case V_204 :
case V_205 :
F_6 ( V_6 , V_44 , V_125 ,
0x0C | V_141 ,
V_206 | V_141 ) ;
F_6 ( V_6 , V_44 , V_135 ,
V_199 , V_199 ) ;
F_6 ( V_6 , V_44 , V_200 , 0xFF ,
V_201 | V_202 | V_203 ) ;
F_6 ( V_6 , V_44 , V_135 , V_199 , 0 ) ;
F_6 ( V_6 , V_44 , V_207 ,
V_208 , V_208 ) ;
F_6 ( V_6 , V_44 , V_209 ,
V_210 | V_211 ,
V_210 | V_211 ) ;
break;
case V_212 :
case V_213 :
F_6 ( V_6 , V_44 , V_125 ,
0x0C , V_214 ) ;
F_6 ( V_6 , V_44 , V_135 ,
V_199 , V_199 ) ;
F_6 ( V_6 , V_44 , V_200 , 0xFF ,
V_215 | V_216 | V_203 ) ;
F_6 ( V_6 , V_44 , V_135 , V_199 , 0 ) ;
F_6 ( V_6 , V_44 , V_207 ,
V_217 , V_218 ) ;
F_6 ( V_6 , V_44 , V_209 ,
V_219 , V_220 ) ;
break;
default:
F_6 ( V_6 , V_44 ,
V_125 , 0x0C , V_214 ) ;
F_6 ( V_6 , V_44 , V_135 ,
V_199 , V_199 ) ;
F_6 ( V_6 , V_44 , V_200 , 0xFF ,
V_215 | V_216 | V_203 ) ;
F_6 ( V_6 , V_44 , V_135 , V_199 , 0 ) ;
F_6 ( V_6 , V_44 ,
V_207 , 0xFF , 0 ) ;
F_6 ( V_6 , V_44 , V_209 ,
V_219 , V_221 ) ;
break;
}
V_33 = F_7 ( V_6 , 100 ) ;
return V_33 ;
}
static void F_67 ( struct V_28 * V_29 , struct V_222 * V_223 )
{
struct V_2 * V_3 = F_14 ( V_29 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_161 )
return;
if ( F_50 ( V_3 -> V_6 , V_164 ) )
return;
F_51 ( & V_6 -> V_165 ) ;
F_52 ( V_6 ) ;
F_58 ( V_3 , V_223 -> V_178 ) ;
F_65 ( V_3 , V_223 -> V_193 ) ;
F_66 ( V_3 , V_223 -> V_195 ) ;
V_3 -> V_168 = false ;
V_3 -> V_167 = true ;
switch ( V_223 -> V_195 ) {
case V_196 :
case V_197 :
V_3 -> V_166 = V_224 ;
V_3 -> V_168 = true ;
V_3 -> V_167 = false ;
break;
case V_204 :
case V_205 :
case V_225 :
V_3 -> V_166 = V_226 ;
break;
default:
V_3 -> V_166 = V_227 ;
break;
}
V_3 -> V_132 = ( V_223 -> clock <= 1000000 ) ? true : false ;
V_3 -> clock = V_223 -> clock ;
F_53 ( V_6 , V_223 -> clock , V_3 -> V_166 ,
V_3 -> V_132 , V_3 -> V_167 , V_3 -> V_168 ) ;
F_54 ( & V_6 -> V_165 ) ;
}
static int F_68 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_14 ( V_29 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_228 = 0 ;
T_3 V_151 ;
if ( V_3 -> V_161 )
return - V_162 ;
F_51 ( & V_6 -> V_165 ) ;
F_52 ( V_6 ) ;
V_151 = F_69 ( V_6 , V_229 ) ;
F_9 ( F_1 ( V_3 ) , L_25 , V_40 , V_151 ) ;
if ( V_151 & V_230 )
V_228 = 1 ;
F_54 ( & V_6 -> V_165 ) ;
return V_228 ;
}
static int F_70 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_14 ( V_29 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_231 = 0 ;
T_3 V_151 ;
if ( V_3 -> V_161 )
return - V_162 ;
F_51 ( & V_6 -> V_165 ) ;
F_52 ( V_6 ) ;
V_151 = F_71 ( V_6 ) ;
F_9 ( F_1 ( V_3 ) , L_25 , V_40 , V_151 ) ;
if ( V_151 & V_232 )
V_231 = 1 ;
F_54 ( & V_6 -> V_165 ) ;
return V_231 ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 ;
T_2 V_233 ;
F_73 ( 1 ) ;
V_33 = F_41 ( V_6 , V_87 , & V_233 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_233 & ( V_234 | V_235 | V_236 |
V_237 | V_238 ) )
return - V_84 ;
V_33 = F_3 ( V_6 , V_87 ,
0xFF , V_100 ) ;
if ( V_33 < 0 )
return V_33 ;
return 0 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 ;
T_2 V_233 , V_239 , V_151 ;
F_75 ( 50 ) ;
V_33 = F_3 ( V_6 , V_87 , 0xFF , V_88 ) ;
if ( V_33 < 0 )
return V_33 ;
F_75 ( 20 ) ;
V_33 = F_41 ( V_6 , V_87 , & V_233 ) ;
if ( V_33 < 0 )
return V_33 ;
V_239 = V_234 | V_235 | V_236 |
V_237 | V_238 ;
V_151 = V_234 | V_235 | V_236 |
V_237 | V_238 ;
if ( ( V_233 & V_239 ) != V_151 ) {
F_9 ( F_1 ( V_3 ) ,
L_26 , V_40 , V_233 ) ;
F_3 ( V_6 , V_87 ,
V_88 | V_100 , 0 ) ;
F_3 ( V_6 , V_188 , 0xFF , 0 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_76 ( struct V_28 * V_29 , struct V_222 * V_223 )
{
struct V_2 * V_3 = F_14 ( V_29 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 = 0 ;
T_2 V_240 ;
F_9 ( F_1 ( V_3 ) , L_27 ,
V_40 , V_223 -> V_241 ) ;
if ( V_3 -> V_161 )
return - V_162 ;
V_33 = F_50 ( V_3 -> V_6 , V_164 ) ;
if ( V_33 )
return V_33 ;
F_51 ( & V_6 -> V_165 ) ;
F_52 ( V_6 ) ;
if ( V_223 -> V_241 == V_242 )
V_240 = V_243 ;
else
V_240 = V_244 ;
if ( V_240 == V_244 ) {
V_33 = F_72 ( V_3 ) ;
if ( V_33 < 0 )
goto V_85;
}
V_33 = F_77 ( V_6 , V_240 ) ;
if ( V_33 < 0 )
goto V_85;
if ( V_240 == V_244 ) {
V_33 = F_74 ( V_3 ) ;
if ( V_33 < 0 )
goto V_85;
}
V_85:
V_33 = F_3 ( V_6 , V_87 ,
V_88 | V_100 , 0 ) ;
F_54 ( & V_6 -> V_165 ) ;
return V_33 ;
}
static int F_78 ( struct V_28 * V_29 , T_3 V_66 )
{
struct V_2 * V_3 = F_14 ( V_29 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
int V_33 = 0 ;
if ( V_3 -> V_161 )
return - V_162 ;
V_33 = F_50 ( V_3 -> V_6 , V_164 ) ;
if ( V_33 )
return V_33 ;
F_51 ( & V_6 -> V_165 ) ;
F_52 ( V_6 ) ;
switch ( V_29 -> V_223 . V_195 ) {
case V_196 :
V_33 = F_36 ( V_3 , F_79 ( V_6 ) , false ) ;
break;
case V_197 :
V_33 = F_36 ( V_3 , F_80 ( V_6 ) , false ) ;
break;
case V_205 :
V_33 = F_36 ( V_3 , F_81 ( V_6 ) , false ) ;
break;
default:
V_33 = 0 ;
}
if ( V_33 )
goto V_85;
if ( ( V_29 -> V_223 . V_195 == V_196 ) ||
( V_29 -> V_223 . V_195 == V_197 ) )
V_33 = F_45 ( V_3 , V_66 ) ;
else if ( V_29 -> V_223 . V_195 == V_205 )
V_33 = F_36 ( V_3 , F_82 ( V_6 ) , true ) ;
V_85:
F_54 ( & V_6 -> V_165 ) ;
return V_33 ;
}
static void F_83 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = V_3 -> V_29 ;
struct V_10 * V_6 = V_3 -> V_6 ;
F_9 ( F_1 ( V_3 ) , L_28 , V_6 -> V_245 ) ;
if ( V_6 -> V_245 & V_246 )
V_29 -> V_247 |= V_248 ;
if ( V_6 -> V_245 & V_249 )
V_29 -> V_247 |= V_250 ;
if ( V_6 -> V_245 & V_251 )
V_29 -> V_247 |= V_252 ;
if ( V_6 -> V_245 & V_253 )
V_29 -> V_247 |= V_254 ;
if ( V_6 -> V_245 & V_255 )
V_29 -> V_247 |= V_256 ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = V_3 -> V_29 ;
V_29 -> V_257 = 250000 ;
V_29 -> V_258 = 208000000 ;
V_29 -> V_259 = V_260 | V_261 | V_262 ;
V_29 -> V_247 = V_263 | V_264 |
V_265 | V_266 |
V_267 | V_268 ;
V_29 -> V_269 = V_270 | V_271 ;
V_29 -> V_272 = 400 ;
V_29 -> V_273 = 800 ;
V_29 -> V_274 = & V_275 ;
F_83 ( V_3 ) ;
V_29 -> V_276 = 256 ;
V_29 -> V_277 = 65536 ;
V_29 -> V_278 = 512 ;
V_29 -> V_279 = 65535 ;
V_29 -> V_280 = 524288 ;
}
static void F_85 ( struct V_281 * V_4 )
{
struct V_2 * V_3 = F_86 ( V_4 ) ;
F_87 ( V_3 -> V_29 , 0 ) ;
}
static int F_88 ( struct V_281 * V_4 )
{
struct V_28 * V_29 ;
struct V_2 * V_3 ;
struct V_10 * V_6 ;
struct V_282 * V_283 = V_4 -> V_5 . V_284 ;
if ( ! V_283 )
return - V_285 ;
V_6 = V_283 -> V_6 ;
if ( ! V_6 )
return - V_285 ;
F_9 ( & ( V_4 -> V_5 ) , L_29 ) ;
V_29 = F_89 ( sizeof( * V_3 ) , & V_4 -> V_5 ) ;
if ( ! V_29 )
return - V_131 ;
V_3 = F_14 ( V_29 ) ;
V_3 -> V_177 = F_90 ( V_286 ) ;
if ( ! V_3 -> V_177 ) {
F_91 ( V_29 ) ;
return - V_131 ;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_29 = V_29 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_186 = V_192 ;
F_92 ( & V_3 -> V_159 , F_48 ) ;
F_93 ( V_4 , V_3 ) ;
V_6 -> V_287 [ V_164 ] . V_288 = V_4 ;
V_6 -> V_287 [ V_164 ] . V_289 = F_85 ;
F_94 ( & V_3 -> V_174 ) ;
F_84 ( V_3 ) ;
F_95 ( V_29 ) ;
return 0 ;
}
static int F_96 ( struct V_281 * V_4 )
{
struct V_2 * V_3 = F_86 ( V_4 ) ;
struct V_10 * V_6 ;
struct V_28 * V_29 ;
if ( ! V_3 )
return 0 ;
V_6 = V_3 -> V_6 ;
V_6 -> V_287 [ V_164 ] . V_288 = NULL ;
V_6 -> V_287 [ V_164 ] . V_289 = NULL ;
V_29 = V_3 -> V_29 ;
F_97 ( & V_3 -> V_159 ) ;
F_51 ( & V_3 -> V_174 ) ;
if ( V_3 -> V_31 ) {
F_9 ( & ( V_4 -> V_5 ) ,
L_30 ,
F_98 ( V_29 ) ) ;
F_99 ( V_6 ) ;
V_3 -> V_31 -> V_34 -> error = - V_162 ;
if ( V_3 -> V_31 -> V_175 )
V_3 -> V_31 -> V_175 -> error = - V_162 ;
F_55 ( V_29 , V_3 -> V_31 ) ;
}
F_54 ( & V_3 -> V_174 ) ;
F_100 ( V_29 ) ;
V_3 -> V_161 = true ;
F_101 ( V_3 -> V_177 ) ;
F_102 ( V_3 -> V_177 ) ;
V_3 -> V_177 = NULL ;
F_91 ( V_29 ) ;
F_9 ( & ( V_4 -> V_5 ) ,
L_31 ) ;
return 0 ;
}
