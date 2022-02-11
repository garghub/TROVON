static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 & V_5 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 & V_6 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 & V_7 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 & V_8 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_9 , void T_2 * V_10 )
{
if ( V_2 -> V_11 )
F_6 ( V_9 , V_10 ) ;
else
F_7 ( V_9 , V_10 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , void T_2 * V_10 )
{
if ( V_2 -> V_11 )
return F_9 ( V_10 ) ;
else
return F_10 ( V_10 ) ;
}
static inline T_1 F_11 ( struct V_1 * V_2 , T_1 V_12 )
{
return F_1 ( V_2 ) ? F_12 ( V_12 ) : V_12 ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_13 , V_2 -> V_14 + V_15 ) ;
F_5 ( V_2 , V_16 , V_2 -> V_14 + V_17 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_13 , V_2 -> V_14 + V_15 ) ;
F_5 ( V_2 , V_18 , V_2 -> V_14 + V_17 ) ;
}
static T_3 F_15 ( int V_19 , void * V_20 )
{
struct V_1 * V_2 = V_20 ;
T_1 V_21 ;
V_21 = F_8 ( V_2 , V_2 -> V_14 + V_22 ) ;
F_5 ( V_2 , V_21 , V_2 -> V_14 + V_22 ) ;
if ( V_21 & V_23 )
F_16 ( & V_2 -> V_24 ) ;
F_17 ( V_2 -> V_25 , L_1 , V_2 -> V_26 , V_21 ) ;
return V_27 ;
}
static void F_18 ( struct V_1 * V_2 )
{
void T_2 * V_28 = V_2 -> V_14 ;
int V_29 = V_2 -> V_3 -> V_29 ;
T_1 V_30 ;
int V_31 ;
struct V_32 * V_33 = & V_2 -> V_33 [ 0 ] ;
T_4 V_34 = ( V_33 -> V_35 == 3 ) ? V_36 : V_37 ;
T_4 V_38 = V_33 -> V_39 ;
T_4 V_40 = V_33 -> V_41 ;
F_13 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_42 ; V_31 ++ )
F_5 ( V_2 , 0 , V_28 + V_43 + V_31 * 4 ) ;
V_30 = V_44 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_38 ) | F_20 ( V_47 , V_46 , V_34 ) ,
V_28 + F_21 ( V_30 ) ) ;
F_5 ( V_2 , F_19 ( V_48 , V_46 , V_40 ) |
F_20 ( V_49 , V_50 , V_29 ) ,
V_28 + F_21 ( V_30 + 1 ) ) ;
V_30 = V_51 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_52 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_53 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_33 -> V_54 ) |
F_20 ( V_47 , V_46 , V_34 ) ,
V_28 + F_21 ( V_30 ) ) ;
F_5 ( V_2 , F_19 ( V_55 , V_46 , 0 ) ,
V_28 + F_21 ( V_30 + 1 ) ) ;
V_30 = V_56 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_57 ) |
F_20 ( V_49 , V_46 , 0x1 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_58 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_33 -> V_59 ) |
F_20 ( V_47 , V_46 , V_34 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_60 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_61 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_62 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_63 ) |
F_20 ( V_49 , V_46 , 0x8 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_64 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_65 ) |
F_20 ( V_55 , V_46 , 0x2 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_66 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_67 ) |
F_20 ( V_49 , V_46 , 0x1 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_68 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_69 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_70 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_71 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_72 * 4 ;
F_5 ( V_2 , F_19 ( V_45 , V_46 , V_73 ) ,
V_28 + F_21 ( V_30 ) ) ;
F_14 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_4 V_74 )
{
switch ( V_74 ) {
case V_75 :
return V_44 ;
case V_52 :
return V_51 ;
case V_69 :
return V_68 ;
case V_57 :
return V_56 ;
case V_76 :
return V_58 ;
case V_61 :
return V_60 ;
case V_77 :
return V_53 ;
case V_63 :
return V_62 ;
case V_65 :
return V_64 ;
case V_67 :
return V_66 ;
case V_71 :
return V_70 ;
case V_73 :
return V_72 ;
default:
if ( V_74 == V_2 -> V_33 [ 0 ] . V_59 )
return V_58 ;
F_23 ( V_2 -> V_25 , L_2 , V_74 ) ;
break;
}
return - V_78 ;
}
static int
F_24 ( struct V_1 * V_2 , T_4 V_74 , unsigned int V_10 , int V_79 )
{
void T_2 * V_28 = V_2 -> V_14 ;
int V_80 ;
T_1 V_21 , V_81 ;
int V_82 ;
F_25 ( & V_2 -> V_24 ) ;
F_17 ( V_2 -> V_25 , L_3 ,
V_2 -> V_26 , V_10 , V_79 , V_74 ) ;
V_21 = F_8 ( V_2 , V_28 + V_83 ) ;
F_5 ( V_2 , V_2 -> V_84 + V_2 -> V_26 + V_10 ,
V_28 + V_85 ) ;
F_5 ( V_2 , V_86 | V_87 ,
V_28 + V_88 ) ;
F_5 ( V_2 , V_21 | V_89 , V_28 + V_83 ) ;
do {
V_81 = F_8 ( V_2 , V_28 + V_90 ) ;
if ( V_81 & ( V_91 | V_92 ) ) {
F_26 ( 1 ) ;
F_17 ( V_2 -> V_25 , L_4 , V_81 ) ;
continue;
}
break;
} while ( 1 );
V_80 = F_22 ( V_2 , V_74 ) ;
F_5 ( V_2 , ( V_80 << V_93 ) | V_79 ,
V_28 + V_94 ) ;
if ( ! F_27 ( & V_2 -> V_24 , F_28 ( 1000 ) ) ) {
F_23 ( V_2 -> V_25 ,
L_5 ,
V_74 , V_10 , F_8 ( V_2 , V_28 + V_22 ) ,
F_8 ( V_2 , V_28 + V_90 ) ) ;
V_82 = - V_95 ;
} else {
V_82 = 0 ;
}
F_5 ( V_2 , V_21 , V_28 + V_83 ) ;
return V_82 ;
}
static void F_29 ( struct V_1 * V_2 , int V_79 , T_4 * V_96 )
{
T_1 V_97 ;
int V_31 = 0 ;
while ( V_79 > 0 ) {
V_97 = F_8 ( V_2 , V_2 -> V_14 + V_98 + V_31 * 4 ) ;
V_97 = F_11 ( V_2 , V_97 ) ;
F_17 ( V_2 -> V_25 , L_6 ,
V_2 -> V_26 , V_97 ) ;
if ( V_79 >= 4 ) {
* ( ( T_1 * ) V_96 ) = V_97 ;
V_96 += 4 ;
} else {
memcpy ( V_96 , & V_97 , V_79 ) ;
break;
}
V_79 -= 4 ;
V_31 ++ ;
}
}
static inline void F_30 ( struct V_1 * V_2 )
{
T_1 V_21 ;
V_21 = F_8 ( V_2 , V_2 -> V_14 + V_83 ) ;
V_21 |= V_99 | V_100 ;
F_5 ( V_2 , V_21 , V_2 -> V_14 + V_83 ) ;
F_26 ( 1 ) ;
V_21 &= ~ ( V_99 | V_100 ) ;
F_5 ( V_2 , V_21 , V_2 -> V_14 + V_83 ) ;
}
static T_5 F_31 ( struct V_1 * V_2 , struct V_32 * V_33 ,
T_4 V_101 , unsigned int V_102 , T_1 * V_103 ,
unsigned V_104 )
{
int V_105 , V_31 , V_106 ;
T_1 V_97 ;
F_17 ( V_2 -> V_25 , L_7 ,
V_2 -> V_26 , V_102 , V_104 ) ;
V_97 = F_8 ( V_2 , V_2 -> V_14 + V_83 ) ;
F_5 ( V_2 , V_97 | V_107 , V_2 -> V_14 + V_83 ) ;
for ( V_106 = 0 , V_31 = ( ( V_104 + 3 ) / 4 ) ; V_106 < V_31 ; V_106 ++ ) {
V_97 = F_11 ( V_2 , * V_103 ) ;
F_5 ( V_2 , V_97 , V_2 -> V_14 + V_108 ) ;
V_103 ++ ;
}
if ( F_3 ( V_2 ) )
for (; V_31 < 4 ; V_31 ++ )
F_5 ( V_2 , V_97 , V_2 -> V_14 + V_108 ) ;
V_105 = F_24 ( V_2 , V_101 , V_102 , V_104 ) ;
if ( V_105 == 0 )
return V_104 ;
return V_105 ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_109 = V_2 -> V_109 ;
void T_2 * V_28 = V_2 -> V_14 ;
F_5 ( V_2 , V_109 + V_2 -> V_84 , V_28 + V_110 ) ;
F_5 ( V_2 , V_109 * 2 + V_2 -> V_84 , V_28 + V_111 ) ;
F_5 ( V_2 , V_109 * 3 + V_2 -> V_84 , V_28 + V_112 ) ;
F_5 ( V_2 , V_109 * 4 + V_2 -> V_84 , V_28 + V_113 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
void T_2 * V_28 = V_2 -> V_14 ;
int V_80 ;
F_5 ( V_2 , V_114 , V_28 + V_115 ) ;
F_5 ( V_2 , V_114 , V_28 + V_116 ) ;
F_5 ( V_2 , V_114 , V_28 + V_117 ) ;
F_5 ( V_2 , V_118 |
( ( V_2 -> V_3 -> V_119 / 8 )
<< V_120 ) ,
V_28 + V_121 ) ;
F_5 ( V_2 , 0 , V_28 + V_122 ) ;
F_5 ( V_2 , 0 , V_28 + V_123 ) ;
F_5 ( V_2 , 0 , V_28 + V_124 ) ;
V_80 = F_22 ( V_2 , V_2 -> V_33 [ 0 ] . V_39 ) ;
F_5 ( V_2 , V_80 << V_125 ,
V_2 -> V_14 + V_126 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_105 ;
V_105 = F_35 ( V_2 -> V_127 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_35 ( V_2 -> V_128 ) ;
if ( V_105 ) {
F_36 ( V_2 -> V_127 ) ;
return V_105 ;
}
if ( F_4 ( V_2 ) )
F_37 ( & V_2 -> V_129 , V_130 , 0 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) )
F_39 ( & V_2 -> V_129 ) ;
F_36 ( V_2 -> V_128 ) ;
F_36 ( V_2 -> V_127 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
void T_2 * V_28 = V_2 -> V_14 ;
T_1 V_21 ;
int V_105 ;
F_38 ( V_2 ) ;
V_105 = F_41 ( V_2 -> V_128 , 66000000 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_34 ( V_2 ) ;
if ( V_105 )
return V_105 ;
F_5 ( V_2 , V_100 | V_99 ,
V_28 + V_83 ) ;
F_26 ( 1 ) ;
F_18 ( V_2 ) ;
F_5 ( V_2 , V_131 | V_132 ,
V_28 + V_83 ) ;
V_21 = F_8 ( V_2 , V_28 + V_133 ) ;
F_5 ( V_2 , V_21 & ~ ( V_134
| V_135
| V_136
| V_137 ) , V_28 + V_133 ) ;
F_5 ( V_2 , V_132 | V_138 ,
V_28 + V_83 ) ;
F_5 ( V_2 , 0xffffffff , V_2 -> V_14 + V_22 ) ;
F_5 ( V_2 , V_139 , V_2 -> V_14 + V_140 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned long V_141 = V_2 -> V_142 ;
int V_105 ;
if ( F_2 ( V_2 ) )
V_141 *= 4 ;
F_38 ( V_2 ) ;
V_105 = F_41 ( V_2 -> V_128 , V_141 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_34 ( V_2 ) ;
if ( V_105 )
return V_105 ;
F_18 ( V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
V_2 -> V_26 = V_2 -> V_109 * ( V_33 - V_2 -> V_33 ) ;
}
static int F_44 ( struct V_32 * V_33 , T_4 V_101 , T_4 * V_143 , int V_79 )
{
int V_105 ;
struct V_1 * V_2 = V_33 -> V_144 ;
V_105 = F_24 ( V_2 , V_101 , 0 , V_79 ) ;
if ( V_105 )
return V_105 ;
F_29 ( V_2 , V_79 , V_143 ) ;
return 0 ;
}
static int F_45 ( struct V_32 * V_33 , T_4 V_101 , T_4 * V_143 , int V_79 )
{
struct V_1 * V_2 = V_33 -> V_144 ;
int V_105 ;
if ( ! V_143 ) {
V_105 = F_24 ( V_2 , V_101 , 0 , 1 ) ;
if ( V_105 )
return V_105 ;
if ( V_101 == V_61 )
F_30 ( V_2 ) ;
} else if ( V_79 > 0 ) {
V_105 = F_31 ( V_2 , V_33 , V_101 , 0 ,
( T_1 * ) V_143 , V_79 ) ;
if ( V_105 > 0 )
return 0 ;
} else {
F_23 ( V_2 -> V_25 , L_8 , V_101 ) ;
V_105 = - V_78 ;
}
return V_105 ;
}
static T_5 F_46 ( struct V_32 * V_33 , T_6 V_102 ,
T_7 V_79 , const T_8 * V_143 )
{
struct V_1 * V_2 = V_33 -> V_144 ;
T_5 V_105 = F_31 ( V_2 , V_33 , V_33 -> V_54 , V_102 ,
( T_1 * ) V_143 , V_79 ) ;
F_30 ( V_2 ) ;
return V_105 ;
}
static T_5 F_47 ( struct V_32 * V_33 , T_6 V_145 ,
T_7 V_79 , T_8 * V_143 )
{
struct V_1 * V_2 = V_33 -> V_144 ;
T_4 V_74 = V_33 -> V_39 ;
if ( ! V_2 -> V_146 ) {
V_2 -> V_147 = V_2 -> V_26 + V_145 ;
V_2 -> V_148 = V_79 > V_149 ? V_79 : V_149 ;
V_2 -> V_146 = F_48 (
V_2 -> V_84 + V_2 -> V_147 ,
V_2 -> V_148 ) ;
if ( ! V_2 -> V_146 ) {
F_23 ( V_2 -> V_25 , L_9 ) ;
return - V_150 ;
}
} else if ( V_2 -> V_26 + V_145 < V_2 -> V_147
|| V_2 -> V_26 + V_145 + V_79 >
V_2 -> V_147 + V_2 -> V_148 ) {
F_49 ( V_2 -> V_146 ) ;
V_2 -> V_147 = V_2 -> V_26 + V_145 ;
V_2 -> V_148 = V_79 > V_149 ? V_79 : V_149 ;
V_2 -> V_146 = F_48 (
V_2 -> V_84 + V_2 -> V_147 ,
V_2 -> V_148 ) ;
if ( ! V_2 -> V_146 ) {
F_23 ( V_2 -> V_25 , L_9 ) ;
return - V_150 ;
}
}
F_17 ( V_2 -> V_25 , L_10 ,
V_74 , V_2 -> V_146 + V_2 -> V_26 + V_145 - V_2 -> V_147 ,
V_79 ) ;
memcpy ( V_143 , V_2 -> V_146 + V_2 -> V_26 + V_145 - V_2 -> V_147 ,
V_79 ) ;
return V_79 ;
}
static int F_50 ( struct V_32 * V_33 , T_6 V_151 )
{
struct V_1 * V_2 = V_33 -> V_144 ;
int V_105 ;
F_17 ( V_33 -> V_25 , L_11 ,
V_33 -> V_152 . V_153 / 1024 , V_2 -> V_26 , ( T_1 ) V_151 ) ;
V_105 = F_24 ( V_2 , V_33 -> V_59 , V_151 , 0 ) ;
if ( V_105 )
return V_105 ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_32 * V_33 , enum V_154 V_155 )
{
struct V_1 * V_2 = V_33 -> V_144 ;
int V_105 ;
F_52 ( & V_2 -> V_156 ) ;
V_105 = F_34 ( V_2 ) ;
if ( V_105 )
goto V_157;
F_43 ( V_2 , V_33 ) ;
return 0 ;
V_157:
F_53 ( & V_2 -> V_156 ) ;
return V_105 ;
}
static void F_54 ( struct V_32 * V_33 , enum V_154 V_155 )
{
struct V_1 * V_2 = V_33 -> V_144 ;
F_38 ( V_2 ) ;
F_53 ( & V_2 -> V_156 ) ;
}
static int F_55 ( struct V_158 * V_159 )
{
struct V_160 * V_161 = V_159 -> V_25 . V_162 ;
struct V_163 * V_25 = & V_159 -> V_25 ;
struct V_1 * V_2 ;
struct V_164 * V_165 ;
struct V_32 * V_33 ;
struct V_166 * V_152 ;
int V_105 , V_31 = 0 ;
V_2 = F_56 ( V_25 , sizeof( * V_2 ) , V_167 ) ;
if ( ! V_2 )
return - V_150 ;
V_2 -> V_168 = F_57 ( V_25 -> V_162 ) ;
if ( ! V_2 -> V_168 || V_2 -> V_168 > V_169 )
return - V_170 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_3 = F_58 ( V_25 ) ;
if ( ! V_2 -> V_3 )
return - V_170 ;
F_59 ( V_159 , V_2 ) ;
V_165 = F_60 ( V_159 , V_171 , L_12 ) ;
V_2 -> V_14 = F_61 ( V_25 , V_165 ) ;
if ( F_62 ( V_2 -> V_14 ) )
return F_63 ( V_2 -> V_14 ) ;
V_2 -> V_11 = F_64 ( V_161 , L_13 ) ;
V_165 = F_60 ( V_159 , V_171 ,
L_14 ) ;
if ( ! F_65 ( V_25 , V_165 -> V_172 , F_66 ( V_165 ) ,
V_165 -> V_173 ) ) {
F_23 ( V_25 , L_15 , V_165 ) ;
return - V_174 ;
}
V_2 -> V_84 = V_165 -> V_172 ;
V_2 -> V_127 = F_67 ( V_25 , L_16 ) ;
if ( F_62 ( V_2 -> V_127 ) )
return F_63 ( V_2 -> V_127 ) ;
V_2 -> V_128 = F_67 ( V_25 , L_17 ) ;
if ( F_62 ( V_2 -> V_128 ) )
return F_63 ( V_2 -> V_128 ) ;
V_105 = F_34 ( V_2 ) ;
if ( V_105 ) {
F_23 ( V_25 , L_18 ) ;
goto V_175;
}
V_105 = F_68 ( V_159 , 0 ) ;
if ( V_105 < 0 ) {
F_23 ( V_25 , L_19 , V_105 ) ;
goto V_176;
}
V_105 = F_69 ( V_25 , V_105 ,
F_15 , 0 , V_159 -> V_173 , V_2 ) ;
if ( V_105 ) {
F_23 ( V_25 , L_20 , V_105 ) ;
goto V_176;
}
V_105 = F_40 ( V_2 ) ;
if ( V_105 )
goto V_176;
if ( F_70 ( V_161 , L_21 , NULL ) )
V_2 -> V_177 = true ;
F_71 ( & V_2 -> V_156 ) ;
F_72 (dev->of_node, np) {
if ( ! V_2 -> V_177 )
V_31 *= 2 ;
V_33 = & V_2 -> V_33 [ V_31 ] ;
V_152 = & V_33 -> V_152 ;
V_33 -> V_25 = V_25 ;
F_73 ( V_33 , V_161 ) ;
V_33 -> V_144 = V_2 ;
V_33 -> V_178 = F_44 ;
V_33 -> V_179 = F_45 ;
V_33 -> V_180 = F_47 ;
V_33 -> V_181 = F_46 ;
V_33 -> V_182 = F_50 ;
V_33 -> V_183 = F_51 ;
V_33 -> V_184 = F_54 ;
V_105 = F_74 ( V_161 , L_22 ,
& V_2 -> V_142 ) ;
if ( V_105 < 0 )
goto V_185;
F_43 ( V_2 , V_33 ) ;
V_105 = F_75 ( V_33 , NULL , V_186 ) ;
if ( V_105 )
goto V_185;
V_105 = F_76 ( V_152 , NULL , 0 ) ;
if ( V_105 )
goto V_185;
if ( V_2 -> V_109 == 0 ) {
V_2 -> V_109 = V_152 -> V_187 ;
F_32 ( V_2 ) ;
}
if ( V_33 -> V_188 > V_2 -> V_3 -> V_189 )
V_33 -> V_188 = V_2 -> V_3 -> V_189 ;
V_31 ++ ;
}
V_105 = F_42 ( V_2 ) ;
if ( V_105 )
goto V_190;
F_38 ( V_2 ) ;
return 0 ;
V_190:
for ( V_31 = 0 ; V_31 < V_2 -> V_168 ; V_31 ++ ) {
if ( ! V_2 -> V_177 )
V_31 *= 2 ;
F_77 ( & V_2 -> V_33 [ V_31 ] . V_152 ) ;
}
V_185:
F_78 ( & V_2 -> V_156 ) ;
V_176:
F_38 ( V_2 ) ;
V_175:
F_23 ( V_25 , L_23 ) ;
return V_105 ;
}
static int F_79 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_80 ( V_159 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_168 ; V_31 ++ ) {
if ( ! V_2 -> V_177 )
V_31 *= 2 ;
F_77 ( & V_2 -> V_33 [ V_31 ] . V_152 ) ;
}
F_5 ( V_2 , V_131 , V_2 -> V_14 + V_83 ) ;
F_5 ( V_2 , 0x0 , V_2 -> V_14 + V_140 ) ;
F_78 ( & V_2 -> V_156 ) ;
if ( V_2 -> V_146 )
F_49 ( V_2 -> V_146 ) ;
return 0 ;
}
static int F_81 ( struct V_158 * V_159 , T_9 V_191 )
{
return 0 ;
}
static int F_82 ( struct V_158 * V_159 )
{
int V_105 ;
struct V_1 * V_2 = F_80 ( V_159 ) ;
V_105 = F_34 ( V_2 ) ;
if ( V_105 )
return V_105 ;
F_40 ( V_2 ) ;
F_32 ( V_2 ) ;
F_42 ( V_2 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
