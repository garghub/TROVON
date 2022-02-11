static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & ( V_3 -> V_4 -> V_5 ) ;
}
static inline void F_2 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
F_3 ( V_7 , V_8 ,
V_9 | V_10 ,
V_9 | V_10 ) ;
F_4 ( V_7 ) ;
F_5 ( V_7 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
T_1 V_11 = 0 ;
F_7 ( V_7 , V_12 , & V_11 ) ;
F_8 ( F_1 ( V_3 ) , L_1 , V_11 ) ;
F_7 ( V_7 , V_13 , & V_11 ) ;
F_8 ( F_1 ( V_3 ) , L_2 , V_11 ) ;
F_7 ( V_7 , V_14 , & V_11 ) ;
F_8 ( F_1 ( V_3 ) , L_3 , V_11 ) ;
}
static int F_9 ( struct V_2 * V_3 , struct V_15 * V_16 ,
T_2 V_17 , T_1 * V_18 , int V_19 , int V_20 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 ;
T_1 V_22 ;
if ( ! V_18 )
V_19 = 0 ;
F_10 ( V_7 ) ;
if ( V_16 != NULL ) {
F_8 ( F_1 ( V_3 ) , L_4 , V_23
, V_16 -> V_24 ) ;
if ( V_16 -> V_24 == V_25 )
V_22 = V_26 ;
else
V_22 = V_27 ;
F_11 ( V_7 , V_28 ,
V_29 , 0xFF , ( T_1 ) ( V_16 -> V_24 ) | 0x40 ) ;
F_11 ( V_7 , V_28 ,
V_30 , 0xFF , ( T_1 ) ( V_16 -> V_31 >> 24 ) ) ;
F_11 ( V_7 , V_28 ,
V_32 , 0xFF , ( T_1 ) ( V_16 -> V_31 >> 16 ) ) ;
F_11 ( V_7 , V_28 ,
V_33 , 0xFF , ( T_1 ) ( V_16 -> V_31 >> 8 ) ) ;
F_11 ( V_7 , V_28 ,
V_34 , 0xFF , ( T_1 ) V_16 -> V_31 ) ;
} else {
V_22 = V_35 ;
}
F_11 ( V_7 , V_28 , V_36 , 0xFF , ( T_1 ) V_17 ) ;
F_11 ( V_7 , V_28 , V_37 ,
0xFF , ( T_1 ) ( V_17 >> 8 ) ) ;
F_11 ( V_7 , V_28 , V_38 , 0xFF , 1 ) ;
F_11 ( V_7 , V_28 , V_39 , 0xFF , 0 ) ;
F_11 ( V_7 , V_28 , V_40 , 0xFF ,
V_41 | V_42 |
V_43 | V_44 | V_45 ) ;
if ( V_22 != V_26 )
F_11 ( V_7 , V_28 ,
V_46 , 0x01 , V_47 ) ;
F_11 ( V_7 , V_28 , V_48 ,
0xFF , V_22 | V_49 ) ;
F_11 ( V_7 , V_50 , V_48 ,
V_51 , V_51 ) ;
if ( V_16 != NULL ) {
F_11 ( V_7 , V_52 , V_30 , 0 , 0 ) ;
F_11 ( V_7 , V_52 , V_32 , 0 , 0 ) ;
F_11 ( V_7 , V_52 , V_33 , 0 , 0 ) ;
F_11 ( V_7 , V_52 , V_34 , 0 , 0 ) ;
}
V_21 = F_12 ( V_7 , V_53 , V_20 ) ;
if ( V_21 ) {
F_8 ( F_1 ( V_3 ) ,
L_5 , V_21 ) ;
return V_21 ;
}
V_21 = F_13 ( V_7 , ! V_16 ? 1 : 5 , V_20 ) ;
if ( V_21 || ( V_7 -> V_54 [ 0 ] & V_55 ) ) {
F_6 ( V_3 ) ;
if ( ! V_21 ) {
F_8 ( F_1 ( V_3 ) ,
L_6 ,
V_7 -> V_54 [ 0 ] ) ;
V_21 = - V_56 ;
} else {
F_8 ( F_1 ( V_3 ) ,
L_7 , V_21 ) ;
}
return V_21 ;
}
if ( V_16 != NULL ) {
V_16 -> V_57 [ 0 ] = F_14 ( V_7 -> V_54 + 1 ) ;
F_8 ( F_1 ( V_3 ) , L_8 ,
V_16 -> V_57 [ 0 ] ) ;
}
if ( V_18 && V_19 ) {
V_21 = F_15 ( V_7 , V_18 , V_17 - ( V_17 % 2 ) ) ;
if ( V_21 ) {
F_8 ( F_1 ( V_3 ) ,
L_9 , V_21 ) ;
return V_21 ;
}
if ( V_17 % 2 )
return F_16 ( V_7 ,
V_58 + V_17 ,
V_18 + V_17 - 1 ) ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_15 * V_16 ,
T_2 V_17 , T_1 * V_18 , int V_19 , int V_20 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 ;
T_1 V_22 ;
if ( ! V_18 )
V_19 = 0 ;
if ( V_18 && V_19 ) {
V_21 = F_18 ( V_7 , V_18 , V_19 ) ;
if ( V_21 ) {
F_8 ( F_1 ( V_3 ) ,
L_10 ,
V_21 ) ;
return V_21 ;
}
}
V_22 = ( V_16 != NULL ) ? V_59 : V_60 ;
F_10 ( V_7 ) ;
if ( V_16 != NULL ) {
F_8 ( F_1 ( V_3 ) , L_4 , V_23 ,
V_16 -> V_24 ) ;
F_11 ( V_7 , V_28 ,
V_29 , 0xFF , ( T_1 ) ( V_16 -> V_24 ) | 0x40 ) ;
F_11 ( V_7 , V_28 ,
V_30 , 0xFF , ( T_1 ) ( V_16 -> V_31 >> 24 ) ) ;
F_11 ( V_7 , V_28 ,
V_32 , 0xFF , ( T_1 ) ( V_16 -> V_31 >> 16 ) ) ;
F_11 ( V_7 , V_28 ,
V_33 , 0xFF , ( T_1 ) ( V_16 -> V_31 >> 8 ) ) ;
F_11 ( V_7 , V_28 ,
V_34 , 0xFF , ( T_1 ) V_16 -> V_31 ) ;
}
F_11 ( V_7 , V_28 , V_36 , 0xFF , ( T_1 ) V_17 ) ;
F_11 ( V_7 , V_28 , V_37 ,
0xFF , ( T_1 ) ( V_17 >> 8 ) ) ;
F_11 ( V_7 , V_28 , V_38 , 0xFF , 1 ) ;
F_11 ( V_7 , V_28 , V_39 , 0xFF , 0 ) ;
F_11 ( V_7 , V_28 , V_40 , 0xFF ,
V_41 | V_42 |
V_43 | V_44 | V_45 ) ;
F_11 ( V_7 , V_28 ,
V_46 , 0x01 , V_47 ) ;
F_11 ( V_7 , V_28 , V_48 , 0xFF ,
V_22 | V_49 ) ;
F_11 ( V_7 , V_50 , V_48 ,
V_51 , V_51 ) ;
if ( V_16 != NULL ) {
F_11 ( V_7 , V_52 , V_30 , 0 , 0 ) ;
F_11 ( V_7 , V_52 , V_32 , 0 , 0 ) ;
F_11 ( V_7 , V_52 , V_33 , 0 , 0 ) ;
F_11 ( V_7 , V_52 , V_34 , 0 , 0 ) ;
}
V_21 = F_12 ( V_7 , V_53 , V_20 ) ;
if ( V_21 ) {
F_8 ( F_1 ( V_3 ) ,
L_5 , V_21 ) ;
return V_21 ;
}
V_21 = F_13 ( V_7 , ! V_16 ? 1 : 5 , V_20 ) ;
if ( V_21 ) {
F_6 ( V_3 ) ;
F_8 ( F_1 ( V_3 ) ,
L_7 , V_21 ) ;
return V_21 ;
}
if ( V_16 != NULL ) {
V_16 -> V_57 [ 0 ] = F_14 ( V_7 -> V_54 + 1 ) ;
F_8 ( F_1 ( V_3 ) , L_8 ,
V_16 -> V_57 [ 0 ] ) ;
}
return 0 ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
T_1 V_61 = ( T_1 ) V_16 -> V_24 ;
T_3 V_31 = V_16 -> V_31 ;
int V_21 = 0 ;
int V_20 = 100 ;
int V_62 ;
T_1 * V_63 ;
int V_64 = 0 ;
int V_65 = 2 ;
T_1 V_66 ;
F_8 ( F_1 ( V_3 ) , L_11 ,
V_23 , V_61 , V_31 ) ;
switch ( F_20 ( V_16 ) ) {
case V_67 :
V_66 = V_68 ;
break;
case V_69 :
V_66 = V_70 ;
break;
case V_71 :
V_66 = V_70 | V_72 ;
break;
case V_73 :
V_66 = V_74 ;
break;
case V_75 :
V_66 = V_76 ;
break;
case V_77 :
V_66 = V_78 ;
break;
default:
F_8 ( F_1 ( V_3 ) , L_12 ) ;
V_21 = - V_79 ;
goto V_80;
}
if ( V_66 == V_74 )
V_20 = 3000 ;
if ( V_16 -> V_24 == V_81 ) {
V_21 = F_21 ( V_7 , V_14 ,
V_82 | V_83 ,
V_82 ) ;
if ( V_21 )
goto V_80;
}
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_29 , 0xFF , 0x40 | V_61 ) ;
F_11 ( V_7 , V_28 , V_30 , 0xFF , ( T_1 ) ( V_31 >> 24 ) ) ;
F_11 ( V_7 , V_28 , V_32 , 0xFF , ( T_1 ) ( V_31 >> 16 ) ) ;
F_11 ( V_7 , V_28 , V_33 , 0xFF , ( T_1 ) ( V_31 >> 8 ) ) ;
F_11 ( V_7 , V_28 , V_34 , 0xFF , ( T_1 ) V_31 ) ;
F_11 ( V_7 , V_28 , V_40 , 0xFF , V_66 ) ;
F_11 ( V_7 , V_28 , V_46 ,
0x01 , V_47 ) ;
F_11 ( V_7 , V_28 , V_48 ,
0xFF , V_84 | V_49 ) ;
F_11 ( V_7 , V_50 , V_48 ,
V_51 | V_85 ,
V_51 | V_85 ) ;
if ( V_66 == V_76 ) {
for ( V_62 = V_58 ; V_62 < V_58 + 16 ; V_62 ++ )
F_11 ( V_7 , V_52 , ( T_2 ) V_62 , 0 , 0 ) ;
V_64 = 16 ;
} else if ( V_66 != V_68 ) {
for ( V_62 = V_29 ; V_62 <= V_34 ; V_62 ++ )
F_11 ( V_7 , V_52 , ( T_2 ) V_62 , 0 , 0 ) ;
V_64 = 5 ;
}
V_65 += V_64 ;
F_11 ( V_7 , V_52 , V_12 , 0 , 0 ) ;
V_21 = F_12 ( V_7 , V_53 , 100 ) ;
if ( V_21 ) {
F_8 ( F_1 ( V_3 ) ,
L_13 , V_21 ) ;
goto V_80;
}
V_21 = F_13 ( V_7 , V_65 , V_20 ) ;
if ( V_21 || ( V_7 -> V_54 [ 0 ] & V_55 ) ) {
F_6 ( V_3 ) ;
F_2 ( V_3 ) ;
if ( ! V_21 ) {
F_8 ( F_1 ( V_3 ) ,
L_6 ,
V_7 -> V_54 [ 0 ] ) ;
V_21 = - V_56 ;
} else {
F_8 ( F_1 ( V_3 ) ,
L_7 , V_21 ) ;
}
goto V_80;
}
if ( V_66 == V_68 ) {
V_21 = 0 ;
goto V_80;
}
V_63 = V_7 -> V_54 + 1 ;
if ( ( V_63 [ 0 ] & 0xC0 ) != 0 ) {
V_21 = - V_86 ;
F_8 ( F_1 ( V_3 ) , L_14 ) ;
goto V_80;
}
if ( ! ( V_66 & V_72 ) ) {
if ( V_63 [ V_64 ] & V_87 ) {
V_21 = - V_86 ;
F_8 ( F_1 ( V_3 ) , L_15 ) ;
goto V_80;
}
}
if ( V_66 == V_76 ) {
V_63 [ 16 ] = 1 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
V_16 -> V_57 [ V_62 ] = F_14 ( V_63 + 1 + V_62 * 4 ) ;
F_8 ( F_1 ( V_3 ) , L_16 ,
V_62 , V_16 -> V_57 [ V_62 ] ) ;
}
} else {
V_16 -> V_57 [ 0 ] = F_14 ( V_63 + 1 ) ;
F_8 ( F_1 ( V_3 ) , L_8 ,
V_16 -> V_57 [ 0 ] ) ;
}
V_80:
V_16 -> error = V_21 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_88 * V_89 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_90 * V_91 = V_89 -> V_91 ;
int V_92 = ( V_91 -> V_93 & V_94 ) ? 1 : 0 ;
T_1 V_95 , V_22 ;
int V_21 ;
T_1 V_96 ;
T_4 V_97 = V_91 -> V_98 * V_91 -> V_99 ;
unsigned int V_100 ;
if ( V_92 ) {
F_8 ( F_1 ( V_3 ) , L_17 ,
V_23 , V_97 ) ;
V_95 = V_41 | V_42 |
V_43 | V_44 | V_101 ;
V_22 = V_35 ;
} else {
F_8 ( F_1 ( V_3 ) , L_18 ,
V_23 , V_97 ) ;
V_95 = V_102 | V_42 |
V_43 | V_72 | V_101 ;
V_22 = V_60 ;
}
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_36 , 0xFF , 0x00 ) ;
F_11 ( V_7 , V_28 , V_37 , 0xFF , 0x02 ) ;
F_11 ( V_7 , V_28 , V_38 ,
0xFF , ( T_1 ) V_91 -> V_99 ) ;
F_11 ( V_7 , V_28 , V_39 ,
0xFF , ( T_1 ) ( V_91 -> V_99 >> 8 ) ) ;
F_11 ( V_7 , V_28 , V_46 ,
0x01 , V_103 ) ;
F_11 ( V_7 , V_28 , V_104 ,
0xFF , ( T_1 ) ( V_97 >> 24 ) ) ;
F_11 ( V_7 , V_28 , V_105 ,
0xFF , ( T_1 ) ( V_97 >> 16 ) ) ;
F_11 ( V_7 , V_28 , V_106 ,
0xFF , ( T_1 ) ( V_97 >> 8 ) ) ;
F_11 ( V_7 , V_28 , V_107 ,
0xFF , ( T_1 ) V_97 ) ;
if ( V_92 ) {
V_96 = V_108 ;
F_11 ( V_7 , V_28 , V_109 ,
0x03 | V_110 ,
V_111 | V_112 | V_113 ) ;
} else {
V_96 = V_114 ;
F_11 ( V_7 , V_28 , V_109 ,
0x03 | V_110 ,
V_115 | V_112 | V_113 ) ;
}
F_11 ( V_7 , V_28 , V_40 , 0xFF , V_95 ) ;
F_11 ( V_7 , V_28 , V_48 , 0xFF ,
V_22 | V_49 ) ;
F_11 ( V_7 , V_50 , V_48 ,
V_51 , V_51 ) ;
V_21 = F_12 ( V_7 , V_96 , 100 ) ;
if ( V_21 )
return V_21 ;
if ( V_92 )
V_100 = F_23 ( V_7 -> V_116 , V_117 ) ;
else
V_100 = F_24 ( V_7 -> V_116 , V_118 ) ;
V_21 = F_25 ( V_7 , V_100 , V_91 -> V_119 , V_97 ,
V_91 -> V_120 , NULL , 10000 ) ;
if ( V_21 ) {
F_8 ( F_1 ( V_3 ) , L_19
, V_21 ) ;
F_2 ( V_3 ) ;
return V_21 ;
}
return F_13 ( V_7 , 1 , 2000 ) ;
}
static inline void F_26 ( struct V_2 * V_3 )
{
F_21 ( V_3 -> V_7 , V_121 ,
V_122 , V_123 ) ;
}
static inline void F_27 ( struct V_2 * V_3 )
{
F_21 ( V_3 -> V_7 , V_121 ,
V_122 , V_124 ) ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_88 * V_89 )
{
struct V_15 * V_16 = V_89 -> V_16 ;
struct V_90 * V_91 = V_89 -> V_91 ;
T_1 * V_18 ;
V_18 = F_29 ( V_91 -> V_98 , V_125 ) ;
if ( ! V_18 ) {
V_16 -> error = - V_126 ;
return;
}
if ( V_91 -> V_93 & V_94 ) {
if ( V_3 -> V_127 )
F_27 ( V_3 ) ;
V_16 -> error = F_9 ( V_3 , V_16 , ( T_2 ) V_91 -> V_98 , V_18 ,
V_91 -> V_98 , 200 ) ;
if ( V_3 -> V_127 )
F_26 ( V_3 ) ;
F_30 ( V_91 -> V_119 , V_91 -> V_120 , V_18 , V_91 -> V_98 ) ;
} else {
F_31 ( V_91 -> V_119 , V_91 -> V_120 , V_18 , V_91 -> V_98 ) ;
V_16 -> error = F_17 ( V_3 , V_16 , ( T_2 ) V_91 -> V_98 , V_18 ,
V_91 -> V_98 , 200 ) ;
}
F_32 ( V_18 ) ;
}
static int F_33 ( struct V_2 * V_3 , T_1 V_128 , int V_129 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 ;
F_8 ( F_1 ( V_3 ) , L_20 ,
V_23 , V_129 ? L_21 : L_22 , V_128 ) ;
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_130 , V_131 , V_131 ) ;
if ( V_129 )
F_11 ( V_7 , V_28 , V_132 ,
0x0F , V_128 ) ;
else
F_11 ( V_7 , V_28 , V_133 ,
0x0F , V_128 ) ;
F_11 ( V_7 , V_28 , V_132 , V_134 , 0 ) ;
F_11 ( V_7 , V_28 , V_132 ,
V_134 , V_134 ) ;
F_11 ( V_7 , V_28 , V_130 , V_131 , 0 ) ;
F_11 ( V_7 , V_28 , V_121 , V_135 , 0 ) ;
V_21 = F_12 ( V_7 , V_136 , 100 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static inline T_3 F_34 ( T_3 V_137 , unsigned int V_138 )
{
V_138 &= V_139 ;
return V_137 & ( 1 << V_138 ) ;
}
static int F_35 ( T_3 V_137 , unsigned int V_138 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_139 + 1 ; V_62 ++ ) {
if ( F_34 ( V_137 , V_138 + V_62 ) == 0 )
return V_62 ;
}
return V_139 + 1 ;
}
static T_1 F_36 ( struct V_2 * V_3 , T_3 V_137 )
{
int V_140 = 0 , V_65 = 0 ;
int V_141 = 0 , V_142 = 0 ;
T_1 V_143 = 0xFF ;
if ( V_137 == 0 ) {
F_8 ( F_1 ( V_3 ) , L_23 , V_137 ) ;
return V_143 ;
}
while ( V_140 < V_139 + 1 ) {
V_65 = F_35 ( V_137 , V_140 ) ;
if ( V_142 < V_65 ) {
V_141 = V_140 ;
V_142 = V_65 ;
}
V_140 += V_65 ? V_65 : 1 ;
}
V_143 = ( V_141 + V_142 / 2 ) & V_139 ;
F_8 ( F_1 ( V_3 ) , L_24 ,
V_137 , V_142 , V_143 ) ;
return V_143 ;
}
static void F_37 ( struct V_2 * V_3 )
{
int V_21 , V_62 ;
T_1 V_11 = 0 ;
for ( V_62 = 0 ; V_62 < 100 ; V_62 ++ ) {
V_21 = F_7 ( V_3 -> V_7 ,
V_144 , & V_11 ) ;
if ( V_11 & V_145 )
return;
F_38 ( 100 , 1000 ) ;
}
}
static int F_39 ( struct V_2 * V_3 ,
T_1 V_24 , T_1 V_128 )
{
int V_21 ;
struct V_15 V_16 = {} ;
V_21 = F_33 ( V_3 , V_128 , 0 ) ;
if ( V_21 )
return V_21 ;
V_16 . V_24 = V_25 ;
V_21 = F_9 ( V_3 , & V_16 , 0x40 , NULL , 0 , 100 ) ;
if ( V_21 ) {
F_37 ( V_3 ) ;
F_2 ( V_3 ) ;
return V_21 ;
}
return 0 ;
}
static void F_40 ( struct V_2 * V_3 ,
T_1 V_24 , T_2 * V_137 )
{
int V_21 , V_62 ;
T_2 V_146 = 0 ;
for ( V_62 = V_139 ; V_62 >= 0 ; V_62 -- ) {
V_21 = F_39 ( V_3 , V_24 , ( T_1 ) V_62 ) ;
if ( ! V_21 )
V_146 |= 1 << V_62 ;
}
if ( V_137 )
* V_137 = V_146 ;
}
static int F_41 ( struct V_2 * V_3 , T_1 V_24 )
{
int V_21 , V_62 ;
T_2 V_146 [ V_147 ] = { 0 } , V_137 ;
T_1 V_143 ;
V_21 = F_33 ( V_3 , 0x01 , 1 ) ;
if ( V_21 ) {
F_8 ( F_1 ( V_3 ) , L_25 ) ;
return V_21 ;
}
for ( V_62 = 0 ; V_62 < V_147 ; V_62 ++ ) {
F_40 ( V_3 , V_24 , & ( V_146 [ V_62 ] ) ) ;
if ( V_146 [ V_62 ] == 0 )
break;
}
V_137 = 0xFFFF ;
for ( V_62 = 0 ; V_62 < V_147 ; V_62 ++ ) {
F_8 ( F_1 ( V_3 ) , L_26 ,
V_62 , V_146 [ V_62 ] ) ;
V_137 &= V_146 [ V_62 ] ;
}
F_8 ( F_1 ( V_3 ) , L_27 , V_137 ) ;
if ( V_137 ) {
V_143 = F_36 ( V_3 , V_137 ) ;
if ( V_143 == 0xFF )
return - V_79 ;
V_21 = F_33 ( V_3 , V_143 , 0 ) ;
if ( V_21 )
return V_21 ;
} else {
return - V_79 ;
}
return 0 ;
}
static int F_42 ( struct V_148 * V_149 )
{
struct V_2 * V_3 = F_43 ( V_149 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 ;
T_2 V_11 ;
if ( V_3 -> V_150 )
return - V_151 ;
F_44 ( & V_7 -> V_152 ) ;
V_21 = F_45 ( V_7 , & V_11 ) ;
F_46 ( & V_7 -> V_152 ) ;
if ( V_21 )
return 0 ;
if ( V_11 & V_153 )
return 1 ;
return 0 ;
}
static int F_47 ( struct V_148 * V_149 )
{
struct V_2 * V_3 = F_43 ( V_149 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 ;
T_2 V_11 ;
if ( V_3 -> V_150 )
return - V_151 ;
F_44 ( & V_7 -> V_152 ) ;
V_21 = F_45 ( V_7 , & V_11 ) ;
F_46 ( & V_7 -> V_152 ) ;
if ( V_21 )
goto V_154;
if ( V_11 & V_155 ) {
V_3 -> V_156 = true ;
return 1 ;
}
V_154:
V_3 -> V_156 = false ;
return 0 ;
}
static void F_48 ( struct V_148 * V_149 , struct V_88 * V_89 )
{
struct V_2 * V_3 = F_43 ( V_149 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_15 * V_16 = V_89 -> V_16 ;
struct V_90 * V_91 = V_89 -> V_91 ;
unsigned int V_157 = 0 ;
F_8 ( F_1 ( V_3 ) , L_28 , V_23 ) ;
if ( V_3 -> V_150 ) {
V_16 -> error = - V_151 ;
goto V_158;
}
if ( ( ! V_3 -> V_156 ) ) {
V_16 -> error = - V_151 ;
goto V_159;
}
if ( V_16 -> V_24 == V_160 ||
V_16 -> V_24 == V_161 ||
V_16 -> V_24 == V_162 ) {
V_16 -> error = - V_79 ;
goto V_158;
}
F_44 ( & V_7 -> V_152 ) ;
F_44 ( & V_3 -> V_163 ) ;
V_3 -> V_89 = V_89 ;
F_46 ( & V_3 -> V_163 ) ;
if ( V_89 -> V_91 )
V_157 = V_91 -> V_99 * V_91 -> V_98 ;
if ( ! V_157 ) {
F_19 ( V_3 , V_16 ) ;
} else if ( ( ! ( V_157 % 512 ) && V_16 -> V_24 != V_164 ) ||
F_49 ( V_16 -> V_24 ) ) {
F_19 ( V_3 , V_16 ) ;
if ( ! V_16 -> error ) {
F_22 ( V_3 , V_89 ) ;
if ( F_49 ( V_16 -> V_24 ) && V_89 -> V_165 ) {
F_19 ( V_3 , V_89 -> V_165 ) ;
F_21 ( V_7 , V_166 ,
V_167 , V_167 ) ;
}
}
} else {
F_28 ( V_3 , V_89 ) ;
}
if ( V_89 -> V_91 ) {
if ( V_16 -> error || V_91 -> error )
V_91 -> V_168 = 0 ;
else
V_91 -> V_168 = V_91 -> V_99 * V_91 -> V_98 ;
}
F_46 ( & V_7 -> V_152 ) ;
V_159:
if ( V_16 -> error ) {
F_47 ( V_149 ) ;
F_8 ( F_1 ( V_3 ) , L_29 , V_16 -> error ) ;
}
V_158:
F_44 ( & V_3 -> V_163 ) ;
V_3 -> V_89 = NULL ;
F_46 ( & V_3 -> V_163 ) ;
F_50 ( V_149 , V_89 ) ;
}
static int F_51 ( struct V_2 * V_3 ,
unsigned char V_169 )
{
int V_21 = 0 ;
T_1 V_170 [] = {
[ V_171 ] = V_172 ,
[ V_173 ] = V_174 ,
[ V_175 ] = V_176 ,
} ;
if ( V_169 <= V_175 )
V_21 = F_21 ( V_3 -> V_7 , V_121 ,
0x03 , V_170 [ V_169 ] ) ;
return V_21 ;
}
static int F_52 ( struct V_6 * V_7 )
{
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_177 , 0xFF , 0x55 ) ;
F_11 ( V_7 , V_28 , V_178 , 0xFF , 0x55 ) ;
F_11 ( V_7 , V_28 , V_179 , 0xFF , 0x95 ) ;
F_11 ( V_7 , V_28 , V_180 , 0xFF , 0x55 ) ;
F_11 ( V_7 , V_28 , V_181 , 0xFF , 0x55 ) ;
F_11 ( V_7 , V_28 , V_182 , 0xFF , 0xA5 ) ;
return F_12 ( V_7 , V_136 , 100 ) ;
}
static int F_53 ( struct V_6 * V_7 )
{
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_177 , 0xFF , 0x65 ) ;
F_11 ( V_7 , V_28 , V_178 , 0xFF , 0x55 ) ;
F_11 ( V_7 , V_28 , V_179 , 0xFF , 0x95 ) ;
F_11 ( V_7 , V_28 , V_180 , 0xFF , 0x55 ) ;
F_11 ( V_7 , V_28 , V_181 , 0xFF , 0x56 ) ;
F_11 ( V_7 , V_28 , V_182 , 0xFF , 0x59 ) ;
return F_12 ( V_7 , V_136 , 100 ) ;
}
static int F_54 ( struct V_6 * V_7 )
{
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_177 , 0xFF , 0xAA ) ;
F_11 ( V_7 , V_28 , V_178 , 0xFF , 0xAA ) ;
F_11 ( V_7 , V_28 , V_179 , 0xFF , 0xA9 ) ;
F_11 ( V_7 , V_28 , V_180 , 0xFF , 0x55 ) ;
F_11 ( V_7 , V_28 , V_181 , 0xFF , 0x55 ) ;
F_11 ( V_7 , V_28 , V_182 , 0xFF , 0xA5 ) ;
return F_12 ( V_7 , V_136 , 100 ) ;
}
static int F_55 ( struct V_6 * V_7 )
{
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_177 , 0xFF , 0xA5 ) ;
F_11 ( V_7 , V_28 , V_178 , 0xFF , 0x9A ) ;
F_11 ( V_7 , V_28 , V_179 , 0xFF , 0xA5 ) ;
F_11 ( V_7 , V_28 , V_180 , 0xFF , 0x9A ) ;
F_11 ( V_7 , V_28 , V_181 , 0xFF , 0x65 ) ;
F_11 ( V_7 , V_28 , V_182 , 0xFF , 0x5A ) ;
return F_12 ( V_7 , V_136 , 100 ) ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 ;
F_8 ( F_1 ( V_3 ) , L_28 , V_23 ) ;
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_183 , 0x07 , V_184 ) ;
F_11 ( V_7 , V_28 , V_185 ,
V_186 , V_187 ) ;
F_11 ( V_7 , V_28 , V_188 ,
V_189 , V_189 ) ;
V_21 = F_12 ( V_7 , V_136 , 100 ) ;
if ( V_21 )
return V_21 ;
if ( F_57 ( V_7 , V_190 ) )
V_21 = F_54 ( V_7 ) ;
else
V_21 = F_55 ( V_7 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_21 ( V_7 , V_191 ,
V_192 , V_193 ) ;
if ( V_21 )
return V_21 ;
F_38 ( 800 , 1000 ) ;
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_191 ,
V_192 | V_194 , V_195 | V_196 ) ;
F_11 ( V_7 , V_28 , V_197 ,
V_198 , V_198 ) ;
return F_12 ( V_7 , V_136 , 100 ) ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 ;
F_8 ( F_1 ( V_3 ) , L_28 , V_23 ) ;
F_10 ( V_7 ) ;
F_11 ( V_7 , V_28 , V_188 , V_189 , 0 ) ;
F_11 ( V_7 , V_28 , V_197 , V_198 , 0 ) ;
F_11 ( V_7 , V_28 , V_191 ,
V_192 , V_199 ) ;
F_11 ( V_7 , V_28 , V_191 ,
V_192 | V_194 , V_199 | V_200 ) ;
V_21 = F_12 ( V_7 , V_136 , 100 ) ;
if ( V_21 )
return V_21 ;
if ( F_57 ( V_7 , V_190 ) )
return F_52 ( V_7 ) ;
return F_53 ( V_7 ) ;
}
static int F_59 ( struct V_2 * V_3 ,
unsigned char V_201 )
{
int V_21 ;
if ( V_201 != V_202 )
V_201 = V_203 ;
if ( V_201 == V_3 -> V_201 )
return 0 ;
if ( V_201 == V_202 ) {
V_21 = F_58 ( V_3 ) ;
F_60 ( F_1 ( V_3 ) ) ;
} else {
F_61 ( F_1 ( V_3 ) ) ;
V_21 = F_56 ( V_3 ) ;
}
if ( ! V_21 )
V_3 -> V_201 = V_201 ;
return V_21 ;
}
static int F_62 ( struct V_2 * V_3 ,
unsigned char V_204 , bool * V_205 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 ;
* V_205 = false ;
F_10 ( V_7 ) ;
switch ( V_204 ) {
case V_206 :
case V_207 :
F_11 ( V_7 , V_28 , V_121 ,
0x0C | V_135 ,
V_208 | V_135 ) ;
F_11 ( V_7 , V_28 , V_209 , 0xFF ,
V_210 | V_211 | V_212 ) ;
break;
case V_213 :
* V_205 = true ;
F_11 ( V_7 , V_28 , V_121 ,
0x0C | V_135 ,
V_214 | V_135 ) ;
F_11 ( V_7 , V_28 , V_209 , 0xFF ,
V_210 | V_211 | V_212 ) ;
F_11 ( V_7 , V_28 , V_215 ,
V_216 , V_216 ) ;
F_11 ( V_7 , V_28 , V_217 ,
V_218 | V_219 ,
V_218 | V_219 ) ;
break;
case V_220 :
case V_221 :
F_11 ( V_7 , V_28 , V_121 ,
0x0C , V_222 ) ;
F_11 ( V_7 , V_28 , V_209 , 0xFF ,
V_223 | V_224 | V_212 ) ;
F_11 ( V_7 , V_28 , V_215 ,
V_225 , V_226 ) ;
F_11 ( V_7 , V_28 , V_217 ,
V_227 , V_228 ) ;
break;
default:
F_11 ( V_7 , V_28 ,
V_121 , 0x0C , V_222 ) ;
F_11 ( V_7 , V_28 , V_209 , 0xFF ,
V_223 | V_224 | V_212 ) ;
F_11 ( V_7 , V_28 ,
V_215 , 0xFF , 0 ) ;
F_11 ( V_7 , V_28 , V_217 ,
V_227 , V_229 ) ;
break;
}
V_21 = F_12 ( V_7 , V_136 , 100 ) ;
return V_21 ;
}
static void F_63 ( struct V_148 * V_149 , struct V_230 * V_231 )
{
struct V_2 * V_3 = F_43 ( V_149 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
F_8 ( F_1 ( V_3 ) , L_28 , V_23 ) ;
F_44 ( & V_7 -> V_152 ) ;
F_59 ( V_3 , V_231 -> V_201 ) ;
F_51 ( V_3 , V_231 -> V_169 ) ;
F_62 ( V_3 , V_231 -> V_204 , & V_3 -> V_205 ) ;
V_3 -> V_232 = false ;
V_3 -> V_233 = true ;
switch ( V_231 -> V_204 ) {
case V_206 :
case V_207 :
V_3 -> V_234 = V_235 ;
V_3 -> V_232 = true ;
V_3 -> V_233 = false ;
break;
case V_213 :
case V_236 :
V_3 -> V_234 = V_237 ;
break;
default:
V_3 -> V_234 = V_238 ;
break;
}
V_3 -> V_127 = ( V_231 -> clock <= 1000000 ) ? true : false ;
V_3 -> clock = V_231 -> clock ;
F_64 ( V_3 -> V_7 , V_3 -> clock , V_3 -> V_234 ,
V_3 -> V_127 , V_3 -> V_233 , V_3 -> V_232 ) ;
F_46 ( & V_7 -> V_152 ) ;
F_8 ( F_1 ( V_3 ) , L_30 , V_23 ) ;
}
static int F_65 ( struct V_148 * V_149 , struct V_230 * V_231 )
{
struct V_2 * V_3 = F_43 ( V_149 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 = 0 ;
F_8 ( F_1 ( V_3 ) , L_31 ,
V_23 , V_231 -> V_239 ) ;
if ( V_3 -> V_150 )
return - V_151 ;
if ( V_231 -> V_239 == V_240 )
return - V_241 ;
F_44 ( & V_7 -> V_152 ) ;
V_21 = F_66 ( V_7 , V_242 ) ;
if ( V_21 ) {
F_46 ( & V_7 -> V_152 ) ;
return V_21 ;
}
F_10 ( V_7 ) ;
if ( V_231 -> V_239 == V_243 ) {
F_11 ( V_7 , V_28 , V_244 ,
V_245 , V_246 ) ;
F_11 ( V_7 , V_28 , V_247 ,
V_248 , V_249 ) ;
} else {
F_11 ( V_7 , V_28 , V_14 ,
V_82 | V_83 ,
V_83 ) ;
F_11 ( V_7 , V_28 , V_244 ,
V_245 , V_245 ) ;
F_11 ( V_7 , V_28 , V_247 ,
V_248 , V_250 ) ;
}
V_21 = F_12 ( V_7 , V_136 , 100 ) ;
F_46 ( & V_7 -> V_152 ) ;
return V_21 ;
}
static int F_67 ( struct V_148 * V_149 )
{
struct V_2 * V_3 = F_43 ( V_149 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 ;
T_1 V_251 ;
T_1 V_252 = V_253 | V_254 | V_255
| V_256 ;
F_8 ( F_1 ( V_3 ) , L_28 , V_23 ) ;
F_44 ( & V_7 -> V_152 ) ;
V_21 = F_21 ( V_7 , V_14 ,
V_82 | V_83 ,
V_82 ) ;
if ( V_21 )
goto V_80;
F_68 ( 1 ) ;
V_21 = F_16 ( V_7 , V_14 , & V_251 ) ;
if ( V_21 )
goto V_80;
V_21 = F_21 ( V_7 , V_14 ,
V_82 | V_83 , 0 ) ;
V_80:
F_46 ( & V_7 -> V_152 ) ;
if ( V_21 )
return V_21 ;
if ( ( V_251 & V_252 ) != V_252 )
return 1 ;
else
return 0 ;
}
static int F_69 ( struct V_148 * V_149 , T_3 V_24 )
{
struct V_2 * V_3 = F_43 ( V_149 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_21 = 0 ;
if ( V_3 -> V_150 )
return - V_151 ;
F_44 ( & V_7 -> V_152 ) ;
if ( ! V_3 -> V_205 )
V_21 = F_41 ( V_3 , V_25 ) ;
F_46 ( & V_7 -> V_152 ) ;
return V_21 ;
}
static void F_70 ( struct V_257 * V_258 ,
enum V_259 V_260 )
{
struct V_2 * V_3 = F_71 ( V_258 ,
struct V_2 , V_258 ) ;
if ( V_3 -> V_150 )
return;
V_3 -> V_258 . V_260 = V_260 ;
F_72 ( & V_3 -> V_261 ) ;
}
static void F_73 ( struct V_262 * V_263 )
{
struct V_2 * V_3 =
F_71 ( V_263 , struct V_2 , V_261 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
F_61 ( F_1 ( V_3 ) ) ;
F_44 ( & V_7 -> V_152 ) ;
if ( V_3 -> V_258 . V_260 == V_264 )
F_74 ( V_7 ) ;
else
F_75 ( V_7 ) ;
F_46 ( & V_7 -> V_152 ) ;
F_60 ( F_1 ( V_3 ) ) ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_148 * V_149 = V_3 -> V_149 ;
V_149 -> V_265 = 250000 ;
V_149 -> V_266 = 208000000 ;
V_149 -> V_267 = V_268 | V_269 | V_270 ;
V_149 -> V_271 = V_272 | V_273 |
V_274 | V_275 |
V_276 | V_277 | V_278 |
V_279 ;
V_149 -> V_280 = V_281 | V_282 ;
V_149 -> V_283 = 400 ;
V_149 -> V_284 = 800 ;
V_149 -> V_285 = & V_286 ;
V_149 -> V_287 = 256 ;
V_149 -> V_288 = 65536 ;
V_149 -> V_289 = 512 ;
V_149 -> V_290 = 65535 ;
V_149 -> V_291 = 524288 ;
V_3 -> V_201 = V_202 ;
}
static int F_77 ( struct V_292 * V_4 )
{
struct V_148 * V_149 ;
struct V_2 * V_3 ;
struct V_6 * V_7 ;
#ifdef F_78
int V_21 ;
#endif
V_7 = F_79 ( F_80 ( V_4 -> V_5 . V_293 ) ) ;
if ( ! V_7 )
return - V_294 ;
F_8 ( & ( V_4 -> V_5 ) , L_32 ) ;
V_149 = F_81 ( sizeof( * V_3 ) , & V_4 -> V_5 ) ;
if ( ! V_149 )
return - V_126 ;
V_3 = F_43 ( V_149 ) ;
V_3 -> V_7 = V_7 ;
V_3 -> V_149 = V_149 ;
V_3 -> V_4 = V_4 ;
F_82 ( V_4 , V_3 ) ;
F_83 ( & V_3 -> V_163 ) ;
F_76 ( V_3 ) ;
F_84 ( & V_4 -> V_5 ) ;
F_85 ( & V_4 -> V_5 , 50 ) ;
F_86 ( & V_4 -> V_5 ) ;
#ifdef F_78
snprintf ( V_3 -> V_295 , sizeof( V_3 -> V_295 ) ,
L_33 , F_87 ( V_149 ) ) ;
V_3 -> V_258 . V_296 = V_3 -> V_295 ;
V_3 -> V_258 . V_260 = V_264 ;
V_3 -> V_258 . V_297 = F_87 ( V_149 ) ;
V_3 -> V_258 . V_298 = F_70 ;
V_21 = F_88 ( F_89 ( V_149 ) , & V_3 -> V_258 ) ;
if ( V_21 )
F_90 ( & ( V_4 -> V_5 ) ,
L_34 , V_21 ) ;
F_91 ( & V_3 -> V_261 , F_73 ) ;
#endif
F_92 ( V_149 ) ;
return 0 ;
}
static int F_93 ( struct V_292 * V_4 )
{
struct V_2 * V_3 = F_94 ( V_4 ) ;
struct V_148 * V_149 ;
if ( ! V_3 )
return 0 ;
V_149 = V_3 -> V_149 ;
V_3 -> V_150 = true ;
F_44 ( & V_3 -> V_163 ) ;
if ( V_3 -> V_89 ) {
F_8 ( & ( V_4 -> V_5 ) ,
L_35 ,
F_87 ( V_149 ) ) ;
V_3 -> V_89 -> V_16 -> error = - V_151 ;
if ( V_3 -> V_89 -> V_165 )
V_3 -> V_89 -> V_165 -> error = - V_151 ;
F_50 ( V_149 , V_3 -> V_89 ) ;
}
F_46 ( & V_3 -> V_163 ) ;
F_95 ( V_149 ) ;
#ifdef F_78
F_96 ( & V_3 -> V_261 ) ;
F_97 ( & V_3 -> V_258 ) ;
#endif
F_98 ( V_149 ) ;
F_99 ( & V_4 -> V_5 ) ;
F_100 ( & V_4 -> V_5 ) ;
F_82 ( V_4 , NULL ) ;
F_8 ( & ( V_4 -> V_5 ) ,
L_36 ) ;
return 0 ;
}
