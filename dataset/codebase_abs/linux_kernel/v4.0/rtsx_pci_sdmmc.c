static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & ( V_3 -> V_4 -> V_5 ) ;
}
static inline void F_2 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_7 ,
V_8 | V_9 , V_8 | V_9 ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_10 , T_1 V_11 )
{
T_1 V_12 = V_11 - V_10 + 1 ;
int V_13 ;
T_2 V_14 [ 8 ] ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 += 8 ) {
int V_15 ;
int V_16 = F_5 ( 8 , V_12 - V_13 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_6 ( V_3 -> V_6 , V_10 + V_13 + V_15 ,
V_14 + V_15 ) ;
F_7 ( F_1 ( V_3 ) , L_1 ,
V_10 + V_13 , V_16 , V_14 ) ;
}
}
static void F_8 ( struct V_2 * V_3 )
{
F_4 ( V_3 , 0xFDA0 , 0xFDB3 ) ;
F_4 ( V_3 , 0xFD52 , 0xFD69 ) ;
}
static inline int F_9 ( struct V_2 * V_3 )
{
return F_10 ( V_3 -> V_6 , V_17 ) & V_18 ;
}
static void F_11 ( struct V_19 * V_6 , struct V_20 * V_21 )
{
F_12 ( V_6 , V_22 , V_23 , 0xFF ,
V_24 | V_21 -> V_25 ) ;
F_13 ( V_6 , V_26 , V_21 -> V_27 ) ;
}
static void F_14 ( struct V_19 * V_6 , T_1 V_28 , T_1 V_29 )
{
F_12 ( V_6 , V_22 , V_30 , 0xFF , V_28 ) ;
F_12 ( V_6 , V_22 , V_31 , 0xFF , V_28 >> 8 ) ;
F_12 ( V_6 , V_22 , V_32 , 0xFF , V_29 ) ;
F_12 ( V_6 , V_22 , V_33 , 0xFF , V_29 >> 8 ) ;
}
static int F_15 ( struct V_20 * V_21 )
{
switch ( F_16 ( V_21 ) ) {
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
case V_36 & ~ V_38 :
return V_37 | V_39 ;
case V_40 :
return V_41 ;
case V_42 :
return V_43 ;
case V_44 :
return V_45 ;
default:
return - V_46 ;
}
}
static int F_17 ( int V_47 )
{
if ( V_47 == V_35 )
return 0 ;
else if ( V_47 == V_43 )
return 16 ;
return 5 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_48 * V_14 , bool V_49 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
int V_50 = V_14 -> V_51 & V_52 ;
int V_53 = 0 ;
int V_54 = 0 ;
if ( ! V_49 && V_14 -> V_55 && V_14 -> V_55 != V_3 -> V_56 ) {
F_19 ( F_1 ( V_3 ) ,
L_2 ,
V_14 -> V_55 , V_3 -> V_56 ) ;
V_14 -> V_55 = 0 ;
}
if ( V_49 || V_14 -> V_55 != V_3 -> V_56 ) {
V_53 = F_20 ( V_6 , V_14 -> V_57 , V_14 -> V_58 , V_50 ) ;
} else {
V_53 = V_3 -> V_59 ;
V_54 = 1 ;
}
if ( V_49 ) {
V_3 -> V_59 = V_53 ;
if ( ++ V_3 -> V_56 < 0 )
V_3 -> V_56 = 1 ;
V_14 -> V_55 = V_3 -> V_56 ;
} else {
V_3 -> V_60 = V_53 ;
}
return V_54 ;
}
static void F_21 ( struct V_61 * V_62 , struct V_63 * V_64 ,
bool V_65 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_48 * V_14 = V_64 -> V_14 ;
if ( V_14 -> V_55 ) {
F_19 ( F_1 ( V_3 ) ,
L_3 ,
V_14 -> V_55 ) ;
V_14 -> V_55 = 0 ;
}
F_18 ( V_3 , V_14 , true ) ;
F_7 ( F_1 ( V_3 ) , L_4 , V_3 -> V_59 ) ;
}
static void F_23 ( struct V_61 * V_62 , struct V_63 * V_64 ,
int V_66 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_48 * V_14 = V_64 -> V_14 ;
int V_50 = V_14 -> V_51 & V_52 ;
F_24 ( V_6 , V_14 -> V_57 , V_14 -> V_58 , V_50 ) ;
V_14 -> V_55 = 0 ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_20 * V_21 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
T_2 V_67 = ( T_2 ) V_21 -> V_25 ;
T_3 V_27 = V_21 -> V_27 ;
int V_66 = 0 ;
int V_68 = 100 ;
int V_13 ;
T_2 * V_69 ;
int V_70 ;
int V_71 ;
bool V_72 = false ;
F_7 ( F_1 ( V_3 ) , L_5 ,
V_73 , V_67 , V_27 ) ;
V_70 = F_15 ( V_21 ) ;
if ( V_70 < 0 )
goto V_74;
V_71 = F_17 ( V_70 ) ;
if ( V_70 == V_41 )
V_68 = 3000 ;
if ( V_21 -> V_25 == V_75 ) {
V_66 = F_3 ( V_6 , V_76 ,
0xFF , V_77 ) ;
if ( V_66 < 0 )
goto V_74;
V_72 = true ;
}
F_26 ( V_6 ) ;
F_11 ( V_6 , V_21 ) ;
F_12 ( V_6 , V_22 , V_78 , 0xFF , V_70 ) ;
F_12 ( V_6 , V_22 , V_79 ,
0x01 , V_80 ) ;
F_12 ( V_6 , V_22 , V_81 ,
0xFF , V_82 | V_83 ) ;
F_12 ( V_6 , V_84 , V_81 ,
V_85 | V_86 ,
V_85 | V_86 ) ;
if ( V_70 == V_43 ) {
for ( V_13 = V_87 ; V_13 < V_87 + 16 ; V_13 ++ )
F_12 ( V_6 , V_88 , ( T_1 ) V_13 , 0 , 0 ) ;
} else if ( V_70 != V_35 ) {
for ( V_13 = V_23 ; V_13 <= V_89 ; V_13 ++ )
F_12 ( V_6 , V_88 , ( T_1 ) V_13 , 0 , 0 ) ;
}
F_12 ( V_6 , V_88 , V_90 , 0 , 0 ) ;
V_66 = F_27 ( V_6 , V_68 ) ;
if ( V_66 < 0 ) {
F_8 ( V_3 ) ;
F_2 ( V_3 ) ;
F_7 ( F_1 ( V_3 ) ,
L_6 , V_66 ) ;
goto V_74;
}
if ( V_70 == V_35 ) {
V_66 = 0 ;
goto V_74;
}
V_69 = F_28 ( V_6 ) + 1 ;
if ( ( V_69 [ 0 ] & 0xC0 ) != 0 ) {
V_66 = - V_91 ;
F_7 ( F_1 ( V_3 ) , L_7 ) ;
goto V_74;
}
if ( ! ( V_70 & V_39 ) ) {
if ( V_69 [ V_71 ] & V_92 ) {
V_66 = - V_91 ;
F_7 ( F_1 ( V_3 ) , L_8 ) ;
goto V_74;
}
}
if ( V_70 == V_43 ) {
V_69 [ 16 ] = 1 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_21 -> V_93 [ V_13 ] = F_29 ( V_69 + 1 + V_13 * 4 ) ;
F_7 ( F_1 ( V_3 ) , L_9 ,
V_13 , V_21 -> V_93 [ V_13 ] ) ;
}
} else {
V_21 -> V_93 [ 0 ] = F_29 ( V_69 + 1 ) ;
F_7 ( F_1 ( V_3 ) , L_10 ,
V_21 -> V_93 [ 0 ] ) ;
}
V_74:
V_21 -> error = V_66 ;
if ( V_66 && V_72 )
F_3 ( V_6 , V_76 ,
V_77 | V_94 , 0 ) ;
}
static int F_30 ( struct V_2 * V_3 , struct V_20 * V_21 ,
T_1 V_95 , T_2 * V_96 , int V_97 , int V_68 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 ;
T_2 V_98 ;
F_7 ( F_1 ( V_3 ) , L_5 ,
V_73 , V_21 -> V_25 , V_21 -> V_27 ) ;
if ( ! V_96 )
V_97 = 0 ;
if ( V_21 -> V_25 == V_99 )
V_98 = V_100 ;
else
V_98 = V_101 ;
F_26 ( V_6 ) ;
F_11 ( V_6 , V_21 ) ;
F_14 ( V_6 , 1 , V_95 ) ;
F_12 ( V_6 , V_22 , V_78 , 0xFF ,
V_102 | V_103 |
V_104 | V_105 | V_106 ) ;
if ( V_98 != V_100 )
F_12 ( V_6 , V_22 ,
V_79 , 0x01 , V_80 ) ;
F_12 ( V_6 , V_22 , V_81 ,
0xFF , V_98 | V_83 ) ;
F_12 ( V_6 , V_84 , V_81 ,
V_85 , V_85 ) ;
V_66 = F_27 ( V_6 , V_68 ) ;
if ( V_66 < 0 ) {
F_8 ( V_3 ) ;
F_7 ( F_1 ( V_3 ) ,
L_11 , V_66 ) ;
return V_66 ;
}
if ( V_96 && V_97 ) {
V_66 = F_31 ( V_6 , V_96 , V_97 ) ;
if ( V_66 < 0 ) {
F_7 ( F_1 ( V_3 ) ,
L_12 , V_66 ) ;
return V_66 ;
}
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_1 V_95 , T_2 * V_96 , int V_97 ,
int V_68 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 ;
F_7 ( F_1 ( V_3 ) , L_5 ,
V_73 , V_21 -> V_25 , V_21 -> V_27 ) ;
if ( ! V_96 )
V_97 = 0 ;
F_25 ( V_3 , V_21 ) ;
if ( V_21 -> error )
return V_21 -> error ;
if ( V_96 && V_97 ) {
V_66 = F_33 ( V_6 , V_96 , V_97 ) ;
if ( V_66 < 0 ) {
F_7 ( F_1 ( V_3 ) ,
L_13 , V_66 ) ;
return V_66 ;
}
}
F_26 ( V_6 ) ;
F_14 ( V_6 , 1 , V_95 ) ;
F_12 ( V_6 , V_22 , V_78 , 0xFF ,
V_102 | V_103 |
V_104 | V_105 | V_107 ) ;
F_12 ( V_6 , V_22 , V_81 , 0xFF ,
V_83 | V_108 ) ;
F_12 ( V_6 , V_84 , V_81 ,
V_85 , V_85 ) ;
V_66 = F_27 ( V_6 , V_68 ) ;
if ( V_66 < 0 ) {
F_8 ( V_3 ) ;
F_7 ( F_1 ( V_3 ) ,
L_11 , V_66 ) ;
return V_66 ;
}
return 0 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_63 * V_64 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_61 * V_62 = V_3 -> V_62 ;
struct V_109 * V_110 = V_62 -> V_110 ;
struct V_20 * V_21 = V_64 -> V_21 ;
struct V_48 * V_14 = V_64 -> V_14 ;
int V_111 = F_35 ( V_110 ) ;
T_2 V_112 = 0 ;
int V_66 ;
int V_47 ;
T_4 V_113 = V_14 -> V_29 * V_14 -> V_28 ;
F_7 ( F_1 ( V_3 ) , L_5 ,
V_73 , V_21 -> V_25 , V_21 -> V_27 ) ;
V_47 = F_15 ( V_21 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( ! V_111 )
V_112 |= V_114 ;
F_26 ( V_6 ) ;
F_11 ( V_6 , V_21 ) ;
F_14 ( V_6 , V_14 -> V_28 , V_14 -> V_29 ) ;
F_12 ( V_6 , V_22 , V_115 ,
V_116 , V_116 ) ;
F_12 ( V_6 , V_22 , V_117 ,
0xFF , ( T_2 ) ( V_113 >> 24 ) ) ;
F_12 ( V_6 , V_22 , V_118 ,
0xFF , ( T_2 ) ( V_113 >> 16 ) ) ;
F_12 ( V_6 , V_22 , V_119 ,
0xFF , ( T_2 ) ( V_113 >> 8 ) ) ;
F_12 ( V_6 , V_22 , V_120 , 0xFF , ( T_2 ) V_113 ) ;
F_12 ( V_6 , V_22 , V_121 ,
0x03 | V_122 ,
V_123 | V_124 | V_125 ) ;
F_12 ( V_6 , V_22 , V_79 ,
0x01 , V_126 ) ;
F_12 ( V_6 , V_22 , V_78 , 0xFF , V_112 | V_47 ) ;
F_12 ( V_6 , V_22 , V_81 , 0xFF ,
V_83 | V_127 ) ;
F_12 ( V_6 , V_84 , V_81 ,
V_85 , V_85 ) ;
F_36 ( V_6 ) ;
V_66 = F_37 ( V_6 , V_14 -> V_57 , V_3 -> V_60 , 1 , 10000 ) ;
if ( V_66 < 0 ) {
F_8 ( V_3 ) ;
F_2 ( V_3 ) ;
return V_66 ;
}
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_63 * V_64 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_61 * V_62 = V_3 -> V_62 ;
struct V_109 * V_110 = V_62 -> V_110 ;
struct V_20 * V_21 = V_64 -> V_21 ;
struct V_48 * V_14 = V_64 -> V_14 ;
int V_111 = F_35 ( V_110 ) ;
T_2 V_112 ;
int V_66 ;
T_4 V_113 = V_14 -> V_29 * V_14 -> V_28 ;
F_25 ( V_3 , V_21 ) ;
if ( V_21 -> error )
return V_21 -> error ;
F_7 ( F_1 ( V_3 ) , L_5 ,
V_73 , V_21 -> V_25 , V_21 -> V_27 ) ;
V_112 = V_128 | V_103 |
V_104 | V_39 | V_107 ;
if ( ! V_111 )
V_112 |= V_114 ;
F_26 ( V_6 ) ;
F_14 ( V_6 , V_14 -> V_28 , V_14 -> V_29 ) ;
F_12 ( V_6 , V_22 , V_115 ,
V_116 , V_116 ) ;
F_12 ( V_6 , V_22 , V_117 ,
0xFF , ( T_2 ) ( V_113 >> 24 ) ) ;
F_12 ( V_6 , V_22 , V_118 ,
0xFF , ( T_2 ) ( V_113 >> 16 ) ) ;
F_12 ( V_6 , V_22 , V_119 ,
0xFF , ( T_2 ) ( V_113 >> 8 ) ) ;
F_12 ( V_6 , V_22 , V_120 , 0xFF , ( T_2 ) V_113 ) ;
F_12 ( V_6 , V_22 , V_121 ,
0x03 | V_122 ,
V_129 | V_124 | V_125 ) ;
F_12 ( V_6 , V_22 , V_79 ,
0x01 , V_126 ) ;
F_12 ( V_6 , V_22 , V_78 , 0xFF , V_112 ) ;
F_12 ( V_6 , V_22 , V_81 , 0xFF ,
V_83 | V_108 ) ;
F_12 ( V_6 , V_84 , V_81 ,
V_85 , V_85 ) ;
F_36 ( V_6 ) ;
V_66 = F_37 ( V_6 , V_14 -> V_57 , V_3 -> V_60 , 0 , 10000 ) ;
if ( V_66 < 0 ) {
F_2 ( V_3 ) ;
return V_66 ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_63 * V_64 )
{
struct V_48 * V_14 = V_64 -> V_14 ;
if ( V_3 -> V_60 < 0 ) {
V_14 -> error = V_3 -> V_60 ;
F_7 ( F_1 ( V_3 ) , L_14 ,
V_73 , V_3 -> V_60 ) ;
return V_14 -> error ;
}
if ( V_14 -> V_51 & V_52 )
return F_34 ( V_3 , V_64 ) ;
return F_38 ( V_3 , V_64 ) ;
}
static inline void F_40 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_130 ,
V_131 , V_132 ) ;
}
static inline void F_41 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_130 ,
V_131 , V_133 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_63 * V_64 )
{
struct V_20 * V_21 = V_64 -> V_21 ;
struct V_48 * V_14 = V_64 -> V_14 ;
T_2 * V_96 ;
V_96 = F_43 ( V_14 -> V_29 , V_134 ) ;
if ( ! V_96 ) {
V_21 -> error = - V_135 ;
return;
}
if ( V_14 -> V_51 & V_52 ) {
if ( V_3 -> V_136 )
F_41 ( V_3 ) ;
V_21 -> error = F_30 ( V_3 , V_21 , ( T_1 ) V_14 -> V_29 , V_96 ,
V_14 -> V_29 , 200 ) ;
if ( V_3 -> V_136 )
F_40 ( V_3 ) ;
F_44 ( V_14 -> V_57 , V_14 -> V_58 , V_96 , V_14 -> V_29 ) ;
} else {
F_45 ( V_14 -> V_57 , V_14 -> V_58 , V_96 , V_14 -> V_29 ) ;
V_21 -> error = F_32 ( V_3 , V_21 , ( T_1 ) V_14 -> V_29 , V_96 ,
V_14 -> V_29 , 200 ) ;
}
F_46 ( V_96 ) ;
}
static int F_47 ( struct V_2 * V_3 ,
T_2 V_137 , bool V_138 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 ;
F_7 ( F_1 ( V_3 ) , L_15 ,
V_73 , V_138 ? L_16 : L_17 , V_137 ) ;
F_26 ( V_6 ) ;
F_12 ( V_6 , V_22 , V_139 , V_140 , V_140 ) ;
if ( V_138 )
F_12 ( V_6 , V_22 ,
V_141 , 0x1F , V_137 ) ;
else
F_12 ( V_6 , V_22 ,
V_142 , 0x1F , V_137 ) ;
F_12 ( V_6 , V_22 , V_143 , V_144 , 0 ) ;
F_12 ( V_6 , V_22 , V_143 ,
V_144 , V_144 ) ;
F_12 ( V_6 , V_22 , V_139 , V_140 , 0 ) ;
F_12 ( V_6 , V_22 , V_130 , V_145 , 0 ) ;
V_66 = F_27 ( V_6 , 100 ) ;
if ( V_66 < 0 )
return V_66 ;
return 0 ;
}
static inline T_3 F_48 ( T_3 V_146 , unsigned int V_147 )
{
V_147 %= V_148 ;
return V_146 & ( 1 << V_147 ) ;
}
static int F_49 ( T_3 V_146 , unsigned int V_149 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_148 ; V_13 ++ ) {
if ( F_48 ( V_146 , V_149 + V_13 ) == 0 )
return V_13 ;
}
return V_148 ;
}
static T_2 F_50 ( struct V_2 * V_3 , T_3 V_146 )
{
int V_10 = 0 , V_12 = 0 ;
int V_150 = 0 , V_151 = 0 ;
T_2 V_152 = 0xFF ;
if ( V_146 == 0 ) {
F_19 ( F_1 ( V_3 ) , L_18 , V_146 ) ;
return V_152 ;
}
while ( V_10 < V_148 ) {
V_12 = F_49 ( V_146 , V_10 ) ;
if ( V_151 < V_12 ) {
V_150 = V_10 ;
V_151 = V_12 ;
}
V_10 += V_12 ? V_12 : 1 ;
}
V_152 = ( V_150 + V_151 / 2 ) % V_148 ;
F_7 ( F_1 ( V_3 ) , L_19 ,
V_146 , V_151 , V_152 ) ;
return V_152 ;
}
static void F_51 ( struct V_2 * V_3 )
{
int V_66 , V_13 ;
T_2 V_153 = 0 ;
for ( V_13 = 0 ; V_13 < 100 ; V_13 ++ ) {
V_66 = F_6 ( V_3 -> V_6 , V_154 , & V_153 ) ;
if ( V_153 & V_155 )
return;
F_52 ( 100 ) ;
}
}
static int F_53 ( struct V_2 * V_3 ,
T_2 V_25 , T_2 V_137 )
{
int V_66 ;
struct V_20 V_21 = { 0 } ;
V_66 = F_47 ( V_3 , V_137 , true ) ;
if ( V_66 < 0 )
return V_66 ;
V_21 . V_25 = V_25 ;
V_66 = F_30 ( V_3 , & V_21 , 0x40 , NULL , 0 , 100 ) ;
if ( V_66 < 0 ) {
F_51 ( V_3 ) ;
F_2 ( V_3 ) ;
return V_66 ;
}
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
T_2 V_25 , T_3 * V_146 )
{
int V_66 , V_13 ;
T_3 V_156 = 0 ;
for ( V_13 = 0 ; V_13 < V_148 ; V_13 ++ ) {
V_66 = F_53 ( V_3 , V_25 , ( T_2 ) V_13 ) ;
if ( V_66 == 0 )
V_156 |= 1 << V_13 ;
}
if ( V_146 )
* V_146 = V_156 ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , T_2 V_25 )
{
int V_66 , V_13 ;
T_3 V_156 [ V_157 ] = { 0 } , V_146 ;
T_2 V_152 ;
for ( V_13 = 0 ; V_13 < V_157 ; V_13 ++ ) {
V_66 = F_54 ( V_3 , V_25 , & ( V_156 [ V_13 ] ) ) ;
if ( V_66 < 0 )
return V_66 ;
if ( V_156 [ V_13 ] == 0 )
break;
}
V_146 = 0xFFFFFFFF ;
for ( V_13 = 0 ; V_13 < V_157 ; V_13 ++ ) {
F_7 ( F_1 ( V_3 ) , L_20 ,
V_13 , V_156 [ V_13 ] ) ;
V_146 &= V_156 [ V_13 ] ;
}
F_7 ( F_1 ( V_3 ) , L_21 , V_146 ) ;
if ( V_146 ) {
V_152 = F_50 ( V_3 , V_146 ) ;
if ( V_152 == 0xFF )
return - V_46 ;
V_66 = F_47 ( V_3 , V_152 , true ) ;
if ( V_66 < 0 )
return V_66 ;
} else {
return - V_46 ;
}
return 0 ;
}
static inline int F_56 ( struct V_20 * V_21 ,
struct V_48 * V_14 )
{
return ( V_21 -> V_25 == V_158 ) && ( V_14 -> V_29 == 512 ) ;
}
static inline int F_57 ( struct V_20 * V_21 )
{
return F_58 ( V_21 -> V_25 ) ||
( V_21 -> V_25 == V_159 ) ||
( V_21 -> V_25 == V_160 ) ;
}
static void F_59 ( struct V_161 * V_162 )
{
struct V_2 * V_3 = F_60 ( V_162 ,
struct V_2 , V_162 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_61 * V_62 = V_3 -> V_62 ;
struct V_63 * V_64 = V_3 -> V_64 ;
struct V_20 * V_21 = V_64 -> V_21 ;
struct V_48 * V_14 = V_64 -> V_14 ;
unsigned int V_163 = 0 ;
int V_66 ;
if ( V_3 -> V_164 || ! F_9 ( V_3 ) ) {
V_21 -> error = - V_165 ;
goto V_166;
}
V_66 = F_61 ( V_3 -> V_6 , V_167 ) ;
if ( V_66 ) {
V_21 -> error = V_66 ;
goto V_166;
}
F_62 ( & V_6 -> V_168 ) ;
F_63 ( V_6 ) ;
F_64 ( V_6 , V_3 -> clock , V_3 -> V_169 ,
V_3 -> V_136 , V_3 -> V_170 , V_3 -> V_171 ) ;
F_3 ( V_6 , V_172 , 0x07 , V_173 ) ;
F_3 ( V_6 , V_174 ,
V_175 , V_176 ) ;
F_62 ( & V_3 -> V_177 ) ;
V_3 -> V_64 = V_64 ;
F_65 ( & V_3 -> V_177 ) ;
if ( V_64 -> V_14 )
V_163 = V_14 -> V_28 * V_14 -> V_29 ;
if ( ! V_163 ) {
F_25 ( V_3 , V_21 ) ;
} else if ( F_57 ( V_21 ) || F_56 ( V_21 , V_14 ) ) {
V_21 -> error = F_39 ( V_3 , V_64 ) ;
if ( ! V_3 -> V_54 )
F_23 ( V_3 -> V_62 , V_3 -> V_64 , 0 ) ;
if ( F_58 ( V_21 -> V_25 ) && V_64 -> V_178 )
F_25 ( V_3 , V_64 -> V_178 ) ;
} else {
F_42 ( V_3 , V_64 ) ;
}
if ( V_64 -> V_14 ) {
if ( V_21 -> error || V_14 -> error )
V_14 -> V_179 = 0 ;
else
V_14 -> V_179 = V_14 -> V_28 * V_14 -> V_29 ;
}
F_65 ( & V_6 -> V_168 ) ;
V_166:
if ( V_21 -> error ) {
F_7 ( F_1 ( V_3 ) , L_22 ,
V_21 -> V_25 , V_21 -> V_27 , V_21 -> error ) ;
}
F_62 ( & V_3 -> V_177 ) ;
V_3 -> V_64 = NULL ;
F_65 ( & V_3 -> V_177 ) ;
F_66 ( V_62 , V_64 ) ;
}
static void F_67 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_48 * V_14 = V_64 -> V_14 ;
F_62 ( & V_3 -> V_177 ) ;
V_3 -> V_64 = V_64 ;
F_65 ( & V_3 -> V_177 ) ;
if ( F_57 ( V_64 -> V_21 ) || F_56 ( V_64 -> V_21 , V_14 ) )
V_3 -> V_54 = F_18 ( V_3 , V_14 , false ) ;
F_68 ( V_3 -> V_180 , & V_3 -> V_162 ) ;
}
static int F_69 ( struct V_2 * V_3 ,
unsigned char V_181 )
{
int V_66 = 0 ;
T_2 V_182 [] = {
[ V_183 ] = V_184 ,
[ V_185 ] = V_186 ,
[ V_187 ] = V_188 ,
} ;
if ( V_181 <= V_187 )
V_66 = F_3 ( V_3 -> V_6 , V_130 ,
0x03 , V_182 [ V_181 ] ) ;
return V_66 ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 ;
if ( V_3 -> V_189 == V_190 )
return 0 ;
F_26 ( V_6 ) ;
F_12 ( V_6 , V_22 , V_172 , 0x07 , V_173 ) ;
F_12 ( V_6 , V_22 , V_174 ,
V_175 , V_176 ) ;
F_12 ( V_6 , V_22 , V_191 ,
V_192 , V_192 ) ;
V_66 = F_27 ( V_6 , 100 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_71 ( V_6 , V_167 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_72 ( V_6 , V_167 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_3 ( V_6 , V_193 , V_194 , V_194 ) ;
if ( V_66 < 0 )
return V_66 ;
V_3 -> V_189 = V_190 ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 ;
V_3 -> V_189 = V_195 ;
F_26 ( V_6 ) ;
F_12 ( V_6 , V_22 , V_191 , V_192 , 0 ) ;
F_12 ( V_6 , V_22 , V_193 , V_194 , 0 ) ;
V_66 = F_27 ( V_6 , 100 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_74 ( V_6 , V_167 ) ;
if ( V_66 < 0 )
return V_66 ;
return F_75 ( V_6 , V_167 ) ;
}
static int F_76 ( struct V_2 * V_3 ,
unsigned char V_196 )
{
int V_66 ;
if ( V_196 == V_197 )
V_66 = F_73 ( V_3 ) ;
else
V_66 = F_70 ( V_3 ) ;
return V_66 ;
}
static int F_77 ( struct V_2 * V_3 , unsigned char V_198 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 = 0 ;
F_26 ( V_6 ) ;
switch ( V_198 ) {
case V_199 :
case V_200 :
F_12 ( V_6 , V_22 , V_130 ,
0x0C | V_145 ,
V_201 | V_145 ) ;
F_12 ( V_6 , V_22 , V_139 ,
V_202 , V_202 ) ;
F_12 ( V_6 , V_22 , V_203 , 0xFF ,
V_204 | V_205 | V_206 ) ;
F_12 ( V_6 , V_22 , V_139 , V_202 , 0 ) ;
break;
case V_207 :
case V_208 :
F_12 ( V_6 , V_22 , V_130 ,
0x0C | V_145 ,
V_209 | V_145 ) ;
F_12 ( V_6 , V_22 , V_139 ,
V_202 , V_202 ) ;
F_12 ( V_6 , V_22 , V_203 , 0xFF ,
V_204 | V_205 | V_206 ) ;
F_12 ( V_6 , V_22 , V_139 , V_202 , 0 ) ;
F_12 ( V_6 , V_22 , V_210 ,
V_211 , V_211 ) ;
F_12 ( V_6 , V_22 , V_212 ,
V_213 | V_214 ,
V_213 | V_214 ) ;
break;
case V_215 :
case V_216 :
F_12 ( V_6 , V_22 , V_130 ,
0x0C , V_217 ) ;
F_12 ( V_6 , V_22 , V_139 ,
V_202 , V_202 ) ;
F_12 ( V_6 , V_22 , V_203 , 0xFF ,
V_218 | V_219 | V_206 ) ;
F_12 ( V_6 , V_22 , V_139 , V_202 , 0 ) ;
F_12 ( V_6 , V_22 , V_210 ,
V_220 , V_221 ) ;
F_12 ( V_6 , V_22 , V_212 ,
V_222 , V_223 ) ;
break;
default:
F_12 ( V_6 , V_22 ,
V_130 , 0x0C , V_217 ) ;
F_12 ( V_6 , V_22 , V_139 ,
V_202 , V_202 ) ;
F_12 ( V_6 , V_22 , V_203 , 0xFF ,
V_218 | V_219 | V_206 ) ;
F_12 ( V_6 , V_22 , V_139 , V_202 , 0 ) ;
F_12 ( V_6 , V_22 ,
V_210 , 0xFF , 0 ) ;
F_12 ( V_6 , V_22 , V_212 ,
V_222 , V_224 ) ;
break;
}
V_66 = F_27 ( V_6 , 100 ) ;
return V_66 ;
}
static void F_78 ( struct V_61 * V_62 , struct V_225 * V_226 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_164 )
return;
if ( F_61 ( V_3 -> V_6 , V_167 ) )
return;
F_62 ( & V_6 -> V_168 ) ;
F_63 ( V_6 ) ;
F_69 ( V_3 , V_226 -> V_181 ) ;
F_76 ( V_3 , V_226 -> V_196 ) ;
F_77 ( V_3 , V_226 -> V_198 ) ;
V_3 -> V_171 = false ;
V_3 -> V_170 = true ;
switch ( V_226 -> V_198 ) {
case V_199 :
case V_200 :
V_3 -> V_169 = V_227 ;
V_3 -> V_171 = true ;
V_3 -> V_170 = false ;
break;
case V_207 :
case V_208 :
case V_228 :
V_3 -> V_169 = V_229 ;
break;
default:
V_3 -> V_169 = V_230 ;
break;
}
V_3 -> V_136 = ( V_226 -> clock <= 1000000 ) ? true : false ;
V_3 -> clock = V_226 -> clock ;
F_64 ( V_6 , V_226 -> clock , V_3 -> V_169 ,
V_3 -> V_136 , V_3 -> V_170 , V_3 -> V_171 ) ;
F_65 ( & V_6 -> V_168 ) ;
}
static int F_79 ( struct V_61 * V_62 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
int V_231 = 0 ;
T_3 V_153 ;
if ( V_3 -> V_164 )
return - V_165 ;
F_62 ( & V_6 -> V_168 ) ;
F_63 ( V_6 ) ;
V_153 = F_10 ( V_6 , V_17 ) ;
F_7 ( F_1 ( V_3 ) , L_23 , V_73 , V_153 ) ;
if ( V_153 & V_232 )
V_231 = 1 ;
F_65 ( & V_6 -> V_168 ) ;
return V_231 ;
}
static int F_80 ( struct V_61 * V_62 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
int V_233 = 0 ;
T_3 V_153 ;
if ( V_3 -> V_164 )
return V_233 ;
F_62 ( & V_6 -> V_168 ) ;
F_63 ( V_6 ) ;
V_153 = F_81 ( V_6 ) ;
F_7 ( F_1 ( V_3 ) , L_23 , V_73 , V_153 ) ;
if ( V_153 & V_18 )
V_233 = 1 ;
F_65 ( & V_6 -> V_168 ) ;
return V_233 ;
}
static int F_82 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 ;
T_2 V_234 ;
F_83 ( 1 ) ;
V_66 = F_6 ( V_6 , V_76 , & V_234 ) ;
if ( V_66 < 0 )
return V_66 ;
if ( V_234 & ( V_235 | V_236 | V_237 |
V_238 | V_239 ) )
return - V_46 ;
V_66 = F_3 ( V_6 , V_76 ,
0xFF , V_94 ) ;
if ( V_66 < 0 )
return V_66 ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 ;
T_2 V_234 , V_240 , V_153 ;
F_85 ( 50 ) ;
V_66 = F_3 ( V_6 , V_76 , 0xFF , V_77 ) ;
if ( V_66 < 0 )
return V_66 ;
F_85 ( 20 ) ;
V_66 = F_6 ( V_6 , V_76 , & V_234 ) ;
if ( V_66 < 0 )
return V_66 ;
V_240 = V_235 | V_236 | V_237 |
V_238 | V_239 ;
V_153 = V_235 | V_236 | V_237 |
V_238 | V_239 ;
if ( ( V_234 & V_240 ) != V_153 ) {
F_7 ( F_1 ( V_3 ) ,
L_24 , V_73 , V_234 ) ;
F_3 ( V_6 , V_76 ,
V_77 | V_94 , 0 ) ;
F_3 ( V_6 , V_191 , 0xFF , 0 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_86 ( struct V_61 * V_62 , struct V_225 * V_226 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 = 0 ;
T_2 V_241 ;
F_7 ( F_1 ( V_3 ) , L_25 ,
V_73 , V_226 -> V_242 ) ;
if ( V_3 -> V_164 )
return - V_165 ;
V_66 = F_61 ( V_3 -> V_6 , V_167 ) ;
if ( V_66 )
return V_66 ;
F_62 ( & V_6 -> V_168 ) ;
F_63 ( V_6 ) ;
if ( V_226 -> V_242 == V_243 )
V_241 = V_244 ;
else
V_241 = V_245 ;
if ( V_241 == V_245 ) {
V_66 = F_82 ( V_3 ) ;
if ( V_66 < 0 )
goto V_74;
}
V_66 = F_87 ( V_6 , V_241 ) ;
if ( V_66 < 0 )
goto V_74;
if ( V_241 == V_245 ) {
V_66 = F_84 ( V_3 ) ;
if ( V_66 < 0 )
goto V_74;
}
V_74:
V_66 = F_3 ( V_6 , V_76 ,
V_77 | V_94 , 0 ) ;
F_65 ( & V_6 -> V_168 ) ;
return V_66 ;
}
static int F_88 ( struct V_61 * V_62 , T_3 V_25 )
{
struct V_2 * V_3 = F_22 ( V_62 ) ;
struct V_19 * V_6 = V_3 -> V_6 ;
int V_66 = 0 ;
if ( V_3 -> V_164 )
return - V_165 ;
V_66 = F_61 ( V_3 -> V_6 , V_167 ) ;
if ( V_66 )
return V_66 ;
F_62 ( & V_6 -> V_168 ) ;
F_63 ( V_6 ) ;
switch ( V_62 -> V_226 . V_198 ) {
case V_199 :
V_66 = F_47 ( V_3 , F_89 ( V_6 ) , false ) ;
break;
case V_200 :
V_66 = F_47 ( V_3 , F_90 ( V_6 ) , false ) ;
break;
case V_208 :
V_66 = F_47 ( V_3 , F_91 ( V_6 ) , false ) ;
break;
default:
V_66 = 0 ;
}
if ( V_66 )
goto V_74;
if ( ( V_62 -> V_226 . V_198 == V_199 ) ||
( V_62 -> V_226 . V_198 == V_200 ) )
V_66 = F_55 ( V_3 , V_25 ) ;
else if ( V_62 -> V_226 . V_198 == V_208 )
V_66 = F_47 ( V_3 , F_92 ( V_6 ) , true ) ;
V_74:
F_65 ( & V_6 -> V_168 ) ;
return V_66 ;
}
static void F_93 ( struct V_2 * V_3 )
{
struct V_61 * V_62 = V_3 -> V_62 ;
struct V_19 * V_6 = V_3 -> V_6 ;
F_7 ( F_1 ( V_3 ) , L_26 , V_6 -> V_246 ) ;
if ( V_6 -> V_246 & V_247 )
V_62 -> V_248 |= V_249 ;
if ( V_6 -> V_246 & V_250 )
V_62 -> V_248 |= V_251 ;
if ( V_6 -> V_246 & V_252 )
V_62 -> V_248 |= V_253 ;
if ( V_6 -> V_246 & V_254 )
V_62 -> V_248 |= V_255 ;
if ( V_6 -> V_246 & V_256 )
V_62 -> V_248 |= V_257 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_61 * V_62 = V_3 -> V_62 ;
V_62 -> V_258 = 250000 ;
V_62 -> V_259 = 208000000 ;
V_62 -> V_260 = V_261 | V_262 | V_263 ;
V_62 -> V_248 = V_264 | V_265 |
V_266 | V_267 |
V_268 | V_269 ;
V_62 -> V_270 = V_271 | V_272 ;
V_62 -> V_273 = 400 ;
V_62 -> V_274 = 800 ;
V_62 -> V_275 = & V_276 ;
F_93 ( V_3 ) ;
V_62 -> V_277 = 256 ;
V_62 -> V_278 = 65536 ;
V_62 -> V_279 = 512 ;
V_62 -> V_280 = 65535 ;
V_62 -> V_281 = 524288 ;
}
static void F_95 ( struct V_282 * V_4 )
{
struct V_2 * V_3 = F_96 ( V_4 ) ;
V_3 -> V_56 = - 1 ;
F_97 ( V_3 -> V_62 , 0 ) ;
}
static int F_98 ( struct V_282 * V_4 )
{
struct V_61 * V_62 ;
struct V_2 * V_3 ;
struct V_19 * V_6 ;
struct V_283 * V_284 = V_4 -> V_5 . V_285 ;
if ( ! V_284 )
return - V_286 ;
V_6 = V_284 -> V_6 ;
if ( ! V_6 )
return - V_286 ;
F_7 ( & ( V_4 -> V_5 ) , L_27 ) ;
V_62 = F_99 ( sizeof( * V_3 ) , & V_4 -> V_5 ) ;
if ( ! V_62 )
return - V_135 ;
V_3 = F_22 ( V_62 ) ;
V_3 -> V_180 = F_100 ( V_287 ) ;
if ( ! V_3 -> V_180 ) {
F_101 ( V_62 ) ;
return - V_135 ;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_62 = V_62 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_56 = - 1 ;
V_3 -> V_189 = V_195 ;
F_102 ( & V_3 -> V_162 , F_59 ) ;
F_103 ( V_4 , V_3 ) ;
V_6 -> V_288 [ V_167 ] . V_289 = V_4 ;
V_6 -> V_288 [ V_167 ] . V_290 = F_95 ;
F_104 ( & V_3 -> V_177 ) ;
F_94 ( V_3 ) ;
F_105 ( V_62 ) ;
return 0 ;
}
static int F_106 ( struct V_282 * V_4 )
{
struct V_2 * V_3 = F_96 ( V_4 ) ;
struct V_19 * V_6 ;
struct V_61 * V_62 ;
if ( ! V_3 )
return 0 ;
V_6 = V_3 -> V_6 ;
V_6 -> V_288 [ V_167 ] . V_289 = NULL ;
V_6 -> V_288 [ V_167 ] . V_290 = NULL ;
V_62 = V_3 -> V_62 ;
F_107 ( & V_3 -> V_162 ) ;
F_62 ( & V_3 -> V_177 ) ;
if ( V_3 -> V_64 ) {
F_7 ( & ( V_4 -> V_5 ) ,
L_28 ,
F_108 ( V_62 ) ) ;
F_109 ( V_6 ) ;
V_3 -> V_64 -> V_21 -> error = - V_165 ;
if ( V_3 -> V_64 -> V_178 )
V_3 -> V_64 -> V_178 -> error = - V_165 ;
F_66 ( V_62 , V_3 -> V_64 ) ;
}
F_65 ( & V_3 -> V_177 ) ;
F_110 ( V_62 ) ;
V_3 -> V_164 = true ;
F_111 ( V_3 -> V_180 ) ;
F_112 ( V_3 -> V_180 ) ;
V_3 -> V_180 = NULL ;
F_101 ( V_62 ) ;
F_7 ( & ( V_4 -> V_5 ) ,
L_29 ) ;
return 0 ;
}
