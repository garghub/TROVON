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
T_4 V_31 , V_32 , V_33 ;
int V_34 ;
F_13 ( V_2 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
F_5 ( V_2 , 0 , V_28 + V_36 + V_34 * 4 ) ;
V_30 = V_37 * 4 ;
if ( V_2 -> V_38 <= V_39 ) {
V_31 = V_40 ;
V_32 = V_41 ;
V_33 = 8 ;
} else {
V_31 = V_40 ;
V_32 = V_42 ;
V_33 = 8 ;
}
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_31 ) | F_20 ( V_45 , V_44 , V_32 ) ,
V_28 + F_21 ( V_30 ) ) ;
F_5 ( V_2 , F_19 ( V_46 , V_44 , V_33 ) | F_20 ( V_47 , V_48 , V_29 ) ,
V_28 + F_21 ( V_30 + 1 ) ) ;
V_30 = V_49 * 4 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_50 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_51 * 4 ;
if ( V_2 -> V_38 <= V_39 ) {
V_31 = V_52 ;
V_32 = V_41 ;
} else {
V_31 = V_52 ;
V_32 = V_42 ;
}
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_31 ) | F_20 ( V_45 , V_44 , V_32 ) ,
V_28 + F_21 ( V_30 ) ) ;
F_5 ( V_2 , F_19 ( V_53 , V_44 , 0 ) ,
V_28 + F_21 ( V_30 + 1 ) ) ;
V_30 = V_54 * 4 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_55 ) |
F_20 ( V_47 , V_44 , 0x1 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_56 * 4 ;
V_31 = V_2 -> V_57 [ 0 ] . V_58 ;
V_32 = V_2 -> V_38 <= V_39 ? V_41 : V_42 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_31 ) | F_20 ( V_45 , V_44 , V_32 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_59 * 4 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_60 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_61 * 4 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_62 ) |
F_20 ( V_47 , V_44 , 0x8 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_63 * 4 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_64 ) |
F_20 ( V_53 , V_44 , 0x2 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_65 * 4 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_66 ) |
F_20 ( V_47 , V_44 , 0x1 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_67 * 4 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_68 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_69 * 4 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_70 ) ,
V_28 + F_21 ( V_30 ) ) ;
V_30 = V_71 * 4 ;
F_5 ( V_2 , F_19 ( V_43 , V_44 , V_72 ) ,
V_28 + F_21 ( V_30 ) ) ;
F_14 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_4 V_31 )
{
switch ( V_31 ) {
case V_40 :
return V_37 ;
case V_50 :
return V_49 ;
case V_68 :
return V_67 ;
case V_55 :
return V_54 ;
case V_73 :
return V_56 ;
case V_60 :
return V_59 ;
case V_52 :
return V_51 ;
case V_62 :
return V_61 ;
case V_64 :
return V_63 ;
case V_66 :
return V_65 ;
case V_70 :
return V_69 ;
case V_72 :
return V_71 ;
default:
if ( V_31 == V_2 -> V_57 [ 0 ] . V_58 )
return V_56 ;
F_23 ( V_2 -> V_25 , L_2 , V_31 ) ;
break;
}
return - V_74 ;
}
static int
F_24 ( struct V_1 * V_2 , T_4 V_31 , unsigned int V_10 , int V_75 )
{
void T_2 * V_28 = V_2 -> V_14 ;
int V_76 ;
T_1 V_21 , V_77 ;
int V_78 ;
F_25 ( & V_2 -> V_24 ) ;
F_17 ( V_2 -> V_25 , L_3 ,
V_2 -> V_26 , V_10 , V_75 , V_31 ) ;
V_21 = F_8 ( V_2 , V_28 + V_79 ) ;
F_5 ( V_2 , V_2 -> V_80 + V_2 -> V_26 + V_10 ,
V_28 + V_81 ) ;
F_5 ( V_2 , V_82 | V_83 ,
V_28 + V_84 ) ;
F_5 ( V_2 , V_21 | V_85 , V_28 + V_79 ) ;
do {
V_77 = F_8 ( V_2 , V_28 + V_86 ) ;
if ( V_77 & ( V_87 | V_88 ) ) {
F_26 ( 1 ) ;
F_17 ( V_2 -> V_25 , L_4 , V_77 ) ;
continue;
}
break;
} while ( 1 );
V_76 = F_22 ( V_2 , V_31 ) ;
F_5 ( V_2 , ( V_76 << V_89 ) | V_75 ,
V_28 + V_90 ) ;
if ( ! F_27 ( & V_2 -> V_24 , F_28 ( 1000 ) ) ) {
F_23 ( V_2 -> V_25 ,
L_5 ,
V_31 , V_10 , F_8 ( V_2 , V_28 + V_22 ) ,
F_8 ( V_2 , V_28 + V_86 ) ) ;
V_78 = - V_91 ;
} else {
V_78 = 0 ;
}
F_5 ( V_2 , V_21 , V_28 + V_79 ) ;
return V_78 ;
}
static void F_29 ( struct V_1 * V_2 , int V_75 , T_4 * V_92 )
{
T_1 V_93 ;
int V_34 = 0 ;
while ( V_75 > 0 ) {
V_93 = F_8 ( V_2 , V_2 -> V_14 + V_94 + V_34 * 4 ) ;
V_93 = F_11 ( V_2 , V_93 ) ;
F_17 ( V_2 -> V_25 , L_6 ,
V_2 -> V_26 , V_93 ) ;
if ( V_75 >= 4 ) {
* ( ( T_1 * ) V_92 ) = V_93 ;
V_92 += 4 ;
} else {
memcpy ( V_92 , & V_93 , V_75 ) ;
break;
}
V_75 -= 4 ;
V_34 ++ ;
}
}
static inline void F_30 ( struct V_1 * V_2 )
{
T_1 V_21 ;
V_21 = F_8 ( V_2 , V_2 -> V_14 + V_79 ) ;
V_21 |= V_95 | V_96 ;
F_5 ( V_2 , V_21 , V_2 -> V_14 + V_79 ) ;
F_26 ( 1 ) ;
V_21 &= ~ ( V_95 | V_96 ) ;
F_5 ( V_2 , V_21 , V_2 -> V_14 + V_79 ) ;
}
static T_5 F_31 ( struct V_1 * V_2 , struct V_97 * V_57 ,
T_4 V_98 , unsigned int V_99 , T_1 * V_100 ,
unsigned V_101 )
{
int V_102 , V_34 , V_103 ;
T_1 V_93 ;
F_17 ( V_2 -> V_25 , L_7 ,
V_2 -> V_26 , V_99 , V_101 ) ;
V_93 = F_8 ( V_2 , V_2 -> V_14 + V_79 ) ;
F_5 ( V_2 , V_93 | V_104 , V_2 -> V_14 + V_79 ) ;
for ( V_103 = 0 , V_34 = ( ( V_101 + 3 ) / 4 ) ; V_103 < V_34 ; V_103 ++ ) {
V_93 = F_11 ( V_2 , * V_100 ) ;
F_5 ( V_2 , V_93 , V_2 -> V_14 + V_105 ) ;
V_100 ++ ;
}
if ( F_3 ( V_2 ) )
for (; V_34 < 4 ; V_34 ++ )
F_5 ( V_2 , V_93 , V_2 -> V_14 + V_105 ) ;
V_102 = F_24 ( V_2 , V_98 , V_99 , V_101 ) ;
if ( V_102 == 0 )
return V_101 ;
return V_102 ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_38 = V_2 -> V_38 ;
void T_2 * V_28 = V_2 -> V_14 ;
F_5 ( V_2 , V_38 + V_2 -> V_80 , V_28 + V_106 ) ;
F_5 ( V_2 , V_38 * 2 + V_2 -> V_80 , V_28 + V_107 ) ;
F_5 ( V_2 , V_38 * 3 + V_2 -> V_80 , V_28 + V_108 ) ;
F_5 ( V_2 , V_38 * 4 + V_2 -> V_80 , V_28 + V_109 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
void T_2 * V_28 = V_2 -> V_14 ;
int V_76 ;
F_5 ( V_2 , V_110 , V_28 + V_111 ) ;
F_5 ( V_2 , V_110 , V_28 + V_112 ) ;
F_5 ( V_2 , V_110 , V_28 + V_113 ) ;
F_5 ( V_2 , V_114 |
( ( V_2 -> V_3 -> V_115 / 8 )
<< V_116 ) ,
V_28 + V_117 ) ;
F_5 ( V_2 , 0 , V_28 + V_118 ) ;
F_5 ( V_2 , 0 , V_28 + V_119 ) ;
F_5 ( V_2 , 0 , V_28 + V_120 ) ;
V_76 = F_22 ( V_2 , V_2 -> V_57 [ 0 ] . V_121 ) ;
F_5 ( V_2 , V_76 << V_122 ,
V_2 -> V_14 + V_123 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_102 ;
V_102 = F_35 ( V_2 -> V_124 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_35 ( V_2 -> V_125 ) ;
if ( V_102 ) {
F_36 ( V_2 -> V_124 ) ;
return V_102 ;
}
if ( F_4 ( V_2 ) )
F_37 ( & V_2 -> V_126 , V_127 , 0 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) )
F_39 ( & V_2 -> V_126 ) ;
F_36 ( V_2 -> V_125 ) ;
F_36 ( V_2 -> V_124 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
void T_2 * V_28 = V_2 -> V_14 ;
T_1 V_21 ;
int V_102 ;
F_38 ( V_2 ) ;
V_102 = F_41 ( V_2 -> V_125 , 66000000 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_34 ( V_2 ) ;
if ( V_102 )
return V_102 ;
F_5 ( V_2 , V_96 | V_95 ,
V_28 + V_79 ) ;
F_26 ( 1 ) ;
F_18 ( V_2 ) ;
F_5 ( V_2 , V_128 | V_129 ,
V_28 + V_79 ) ;
V_21 = F_8 ( V_2 , V_28 + V_130 ) ;
F_5 ( V_2 , V_21 & ~ ( V_131
| V_132
| V_133
| V_134 ) , V_28 + V_130 ) ;
F_5 ( V_2 , V_129 | V_135 ,
V_28 + V_79 ) ;
F_5 ( V_2 , 0xffffffff , V_2 -> V_14 + V_22 ) ;
F_5 ( V_2 , V_136 , V_2 -> V_14 + V_137 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned long V_138 = V_2 -> V_139 ;
int V_102 ;
if ( F_2 ( V_2 ) )
V_138 *= 4 ;
F_38 ( V_2 ) ;
V_102 = F_41 ( V_2 -> V_125 , V_138 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_34 ( V_2 ) ;
if ( V_102 )
return V_102 ;
F_18 ( V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_97 * V_57 )
{
V_2 -> V_26 = V_2 -> V_38 * ( V_57 - V_2 -> V_57 ) ;
}
static int F_44 ( struct V_97 * V_57 , T_4 V_98 , T_4 * V_140 , int V_75 )
{
int V_102 ;
struct V_1 * V_2 = V_57 -> V_141 ;
V_102 = F_24 ( V_2 , V_98 , 0 , V_75 ) ;
if ( V_102 )
return V_102 ;
F_29 ( V_2 , V_75 , V_140 ) ;
return 0 ;
}
static int F_45 ( struct V_97 * V_57 , T_4 V_98 , T_4 * V_140 , int V_75 )
{
struct V_1 * V_2 = V_57 -> V_141 ;
int V_102 ;
if ( ! V_140 ) {
V_102 = F_24 ( V_2 , V_98 , 0 , 1 ) ;
if ( V_102 )
return V_102 ;
if ( V_98 == V_60 )
F_30 ( V_2 ) ;
} else if ( V_75 > 0 ) {
V_102 = F_31 ( V_2 , V_57 , V_98 , 0 ,
( T_1 * ) V_140 , V_75 ) ;
if ( V_102 > 0 )
return 0 ;
} else {
F_23 ( V_2 -> V_25 , L_8 , V_98 ) ;
V_102 = - V_74 ;
}
return V_102 ;
}
static T_5 F_46 ( struct V_97 * V_57 , T_6 V_99 ,
T_7 V_75 , const T_8 * V_140 )
{
struct V_1 * V_2 = V_57 -> V_141 ;
T_5 V_102 = F_31 ( V_2 , V_57 , V_57 -> V_142 , V_99 ,
( T_1 * ) V_140 , V_75 ) ;
F_30 ( V_2 ) ;
return V_102 ;
}
static T_5 F_47 ( struct V_97 * V_57 , T_6 V_143 ,
T_7 V_75 , T_8 * V_140 )
{
struct V_1 * V_2 = V_57 -> V_141 ;
T_4 V_31 = V_57 -> V_121 ;
if ( ! V_2 -> V_144 ) {
V_2 -> V_145 = V_2 -> V_26 + V_143 ;
V_2 -> V_146 = V_75 > V_147 ? V_75 : V_147 ;
V_2 -> V_144 = F_48 (
V_2 -> V_80 + V_2 -> V_145 ,
V_2 -> V_146 ) ;
if ( ! V_2 -> V_144 ) {
F_23 ( V_2 -> V_25 , L_9 ) ;
return - V_148 ;
}
} else if ( V_2 -> V_26 + V_143 < V_2 -> V_145
|| V_2 -> V_26 + V_143 + V_75 >
V_2 -> V_145 + V_2 -> V_146 ) {
F_49 ( V_2 -> V_144 ) ;
V_2 -> V_145 = V_2 -> V_26 + V_143 ;
V_2 -> V_146 = V_75 > V_147 ? V_75 : V_147 ;
V_2 -> V_144 = F_48 (
V_2 -> V_80 + V_2 -> V_145 ,
V_2 -> V_146 ) ;
if ( ! V_2 -> V_144 ) {
F_23 ( V_2 -> V_25 , L_9 ) ;
return - V_148 ;
}
}
F_17 ( V_2 -> V_25 , L_10 ,
V_31 , V_2 -> V_144 + V_2 -> V_26 + V_143 - V_2 -> V_145 ,
V_75 ) ;
memcpy ( V_140 , V_2 -> V_144 + V_2 -> V_26 + V_143 - V_2 -> V_145 ,
V_75 ) ;
return V_75 ;
}
static int F_50 ( struct V_97 * V_57 , T_6 V_149 )
{
struct V_1 * V_2 = V_57 -> V_141 ;
int V_102 ;
F_17 ( V_57 -> V_25 , L_11 ,
V_57 -> V_150 . V_151 / 1024 , V_2 -> V_26 , ( T_1 ) V_149 ) ;
V_102 = F_24 ( V_2 , V_57 -> V_58 , V_149 , 0 ) ;
if ( V_102 )
return V_102 ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_97 * V_57 , enum V_152 V_153 )
{
struct V_1 * V_2 = V_57 -> V_141 ;
int V_102 ;
F_52 ( & V_2 -> V_154 ) ;
V_102 = F_34 ( V_2 ) ;
if ( V_102 )
goto V_155;
F_43 ( V_2 , V_57 ) ;
return 0 ;
V_155:
F_53 ( & V_2 -> V_154 ) ;
return V_102 ;
}
static void F_54 ( struct V_97 * V_57 , enum V_152 V_153 )
{
struct V_1 * V_2 = V_57 -> V_141 ;
F_38 ( V_2 ) ;
F_53 ( & V_2 -> V_154 ) ;
}
static int F_55 ( struct V_156 * V_157 )
{
struct V_158 * V_159 = V_157 -> V_25 . V_160 ;
struct V_161 * V_25 = & V_157 -> V_25 ;
struct V_1 * V_2 ;
struct V_162 * V_163 ;
struct V_97 * V_57 ;
struct V_164 * V_150 ;
int V_102 , V_34 = 0 ;
V_2 = F_56 ( V_25 , sizeof( * V_2 ) , V_165 ) ;
if ( ! V_2 )
return - V_148 ;
V_2 -> V_166 = F_57 ( V_25 -> V_160 ) ;
if ( ! V_2 -> V_166 || V_2 -> V_166 > V_167 )
return - V_168 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_3 = F_58 ( V_25 ) ;
if ( ! V_2 -> V_3 )
return - V_168 ;
F_59 ( V_157 , V_2 ) ;
V_163 = F_60 ( V_157 , V_169 , L_12 ) ;
V_2 -> V_14 = F_61 ( V_25 , V_163 ) ;
if ( F_62 ( V_2 -> V_14 ) )
return F_63 ( V_2 -> V_14 ) ;
V_2 -> V_11 = F_64 ( V_159 , L_13 ) ;
V_163 = F_60 ( V_157 , V_169 ,
L_14 ) ;
if ( ! F_65 ( V_25 , V_163 -> V_170 , F_66 ( V_163 ) ,
V_163 -> V_171 ) ) {
F_23 ( V_25 , L_15 , V_163 ) ;
return - V_172 ;
}
V_2 -> V_80 = V_163 -> V_170 ;
V_2 -> V_124 = F_67 ( V_25 , L_16 ) ;
if ( F_62 ( V_2 -> V_124 ) )
return F_63 ( V_2 -> V_124 ) ;
V_2 -> V_125 = F_67 ( V_25 , L_17 ) ;
if ( F_62 ( V_2 -> V_125 ) )
return F_63 ( V_2 -> V_125 ) ;
V_102 = F_34 ( V_2 ) ;
if ( V_102 ) {
F_23 ( V_25 , L_18 ) ;
goto V_173;
}
V_102 = F_68 ( V_157 , 0 ) ;
if ( V_102 < 0 ) {
F_23 ( V_25 , L_19 , V_102 ) ;
goto V_174;
}
V_102 = F_69 ( V_25 , V_102 ,
F_15 , 0 , V_157 -> V_171 , V_2 ) ;
if ( V_102 ) {
F_23 ( V_25 , L_20 , V_102 ) ;
goto V_174;
}
V_102 = F_40 ( V_2 ) ;
if ( V_102 )
goto V_174;
if ( F_70 ( V_159 , L_21 , NULL ) )
V_2 -> V_175 = true ;
F_71 ( & V_2 -> V_154 ) ;
F_72 (dev->of_node, np) {
if ( ! V_2 -> V_175 )
V_34 *= 2 ;
V_57 = & V_2 -> V_57 [ V_34 ] ;
V_150 = & V_57 -> V_150 ;
V_57 -> V_25 = V_25 ;
F_73 ( V_57 , V_159 ) ;
V_57 -> V_141 = V_2 ;
V_57 -> V_176 = F_44 ;
V_57 -> V_177 = F_45 ;
V_57 -> V_178 = F_47 ;
V_57 -> V_179 = F_46 ;
V_57 -> V_180 = F_50 ;
V_57 -> V_181 = F_51 ;
V_57 -> V_182 = F_54 ;
V_102 = F_74 ( V_159 , L_22 ,
& V_2 -> V_139 ) ;
if ( V_102 < 0 )
goto V_183;
F_43 ( V_2 , V_57 ) ;
V_102 = F_75 ( V_57 , NULL , V_184 ) ;
if ( V_102 )
goto V_183;
V_102 = F_76 ( V_150 , NULL , 0 ) ;
if ( V_102 )
goto V_183;
if ( V_2 -> V_38 == 0 ) {
V_2 -> V_38 = V_150 -> V_185 ;
F_32 ( V_2 ) ;
}
if ( V_57 -> V_186 > V_2 -> V_3 -> V_187 )
V_57 -> V_186 = V_2 -> V_3 -> V_187 ;
V_34 ++ ;
}
V_102 = F_42 ( V_2 ) ;
if ( V_102 )
goto V_188;
F_38 ( V_2 ) ;
return 0 ;
V_188:
for ( V_34 = 0 ; V_34 < V_2 -> V_166 ; V_34 ++ ) {
if ( ! V_2 -> V_175 )
V_34 *= 2 ;
F_77 ( & V_2 -> V_57 [ V_34 ] . V_150 ) ;
}
V_183:
F_78 ( & V_2 -> V_154 ) ;
V_174:
F_38 ( V_2 ) ;
V_173:
F_23 ( V_25 , L_23 ) ;
return V_102 ;
}
static int F_79 ( struct V_156 * V_157 )
{
struct V_1 * V_2 = F_80 ( V_157 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_166 ; V_34 ++ ) {
if ( ! V_2 -> V_175 )
V_34 *= 2 ;
F_77 ( & V_2 -> V_57 [ V_34 ] . V_150 ) ;
}
F_5 ( V_2 , V_128 , V_2 -> V_14 + V_79 ) ;
F_5 ( V_2 , 0x0 , V_2 -> V_14 + V_137 ) ;
F_78 ( & V_2 -> V_154 ) ;
if ( V_2 -> V_144 )
F_49 ( V_2 -> V_144 ) ;
return 0 ;
}
static int F_81 ( struct V_156 * V_157 , T_9 V_189 )
{
return 0 ;
}
static int F_82 ( struct V_156 * V_157 )
{
int V_102 ;
struct V_1 * V_2 = F_80 ( V_157 ) ;
V_102 = F_34 ( V_2 ) ;
if ( V_102 )
return V_102 ;
F_40 ( V_2 ) ;
F_32 ( V_2 ) ;
F_42 ( V_2 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
