static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
int V_6 = 0 ;
F_3 ( F_4 ( V_2 ) ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
if ( F_6 ( V_4 -> V_8 + V_9 ) & V_10 )
V_6 = 1 ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
return V_6 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
if ( ! V_12 )
return 0 ;
if ( ! F_11 ( V_12 -> V_13 ) ) {
F_12 ( F_4 ( V_4 -> V_2 ) ,
L_1 , V_12 -> V_13 ) ;
return - V_14 ;
}
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
if ( V_4 -> V_15 < 25000000 )
F_14 ( 30 ) ;
else
F_15 ( 120 ) ;
}
static void F_16 ( struct V_3 * V_4 , T_1 V_16 )
{
if ( V_4 -> V_17 != V_16 ) {
V_4 -> V_17 = V_16 ;
F_17 ( V_16 , V_4 -> V_8 + V_18 ) ;
}
}
static void F_18 ( struct V_3 * V_4 , T_1 V_19 )
{
if ( V_4 -> V_20 != V_19 ) {
V_4 -> V_20 = V_19 ;
F_17 ( V_19 , V_4 -> V_8 + V_21 ) ;
}
}
static void F_19 ( struct V_3 * V_4 , T_1 V_22 )
{
V_22 |= V_4 -> V_23 & V_24 ;
if ( V_4 -> V_23 != V_22 ) {
V_4 -> V_23 = V_22 ;
F_17 ( V_22 , V_4 -> V_8 + V_25 ) ;
}
}
static void F_20 ( struct V_3 * V_4 , unsigned int V_26 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
T_1 V_16 = V_28 -> V_29 ;
V_4 -> V_15 = 0 ;
if ( V_26 ) {
if ( V_28 -> V_30 ) {
V_4 -> V_15 = V_4 -> V_31 ;
} else if ( V_26 >= V_4 -> V_31 ) {
V_16 = V_32 ;
if ( V_28 -> V_33 )
V_16 |= V_34 ;
V_4 -> V_15 = V_4 -> V_31 ;
} else if ( V_28 -> V_33 ) {
V_16 = F_21 ( V_4 -> V_31 , V_26 ) - 2 ;
if ( V_16 >= 256 )
V_16 = 255 ;
V_4 -> V_15 = V_4 -> V_31 / ( V_16 + 2 ) ;
} else {
V_16 = V_4 -> V_31 / ( 2 * V_26 ) - 1 ;
if ( V_16 >= 256 )
V_16 = 255 ;
V_4 -> V_15 = V_4 -> V_31 / ( 2 * ( V_16 + 1 ) ) ;
}
V_16 |= V_28 -> V_35 ;
V_16 |= V_36 ;
}
V_4 -> V_2 -> V_37 = V_4 -> V_15 ;
if ( V_4 -> V_2 -> V_38 . V_39 == V_40 )
V_16 |= V_41 ;
if ( V_4 -> V_2 -> V_38 . V_39 == V_42 )
V_16 |= V_28 -> V_43 ;
if ( V_4 -> V_2 -> V_38 . V_44 == V_45 ||
V_4 -> V_2 -> V_38 . V_44 == V_46 )
V_16 |= V_28 -> V_47 ;
F_16 ( V_4 , V_16 ) ;
}
static void
F_22 ( struct V_3 * V_4 , struct V_48 * V_49 )
{
F_17 ( 0 , V_4 -> V_8 + V_50 ) ;
F_23 ( V_4 -> V_12 ) ;
V_4 -> V_49 = NULL ;
V_4 -> V_51 = NULL ;
F_24 ( V_4 -> V_2 , V_49 ) ;
F_8 ( F_4 ( V_4 -> V_2 ) ) ;
F_9 ( F_4 ( V_4 -> V_2 ) ) ;
}
static void F_25 ( struct V_3 * V_4 , unsigned int V_52 )
{
void T_2 * V_8 = V_4 -> V_8 ;
if ( V_4 -> V_53 ) {
unsigned int V_54 = F_6 ( V_8 + V_55 ) ;
V_54 &= ~ V_56 ;
V_54 |= V_52 ;
F_17 ( V_54 , V_8 + V_55 ) ;
}
F_17 ( V_52 , V_8 + V_57 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
F_19 ( V_4 , 0 ) ;
F_25 ( V_4 , 0 ) ;
V_4 -> V_12 = NULL ;
}
static void F_27 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
unsigned int V_5 = V_58 ;
if ( V_12 -> V_5 & V_59 )
V_5 |= V_60 ;
else
V_5 |= V_61 ;
F_28 ( & V_4 -> V_62 , V_12 -> V_63 , V_12 -> V_64 , V_5 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
const char * V_65 , * V_66 ;
T_3 V_52 ;
struct V_27 * V_28 = V_4 -> V_28 ;
V_4 -> V_67 = F_30 ( F_4 ( V_4 -> V_2 ) , L_2 ) ;
V_4 -> V_68 = F_30 ( F_4 ( V_4 -> V_2 ) , L_3 ) ;
V_4 -> V_69 . V_70 = 1 ;
F_31 ( V_52 ) ;
F_32 ( V_71 , V_52 ) ;
if ( V_4 -> V_67 && ! V_4 -> V_68 )
V_4 -> V_68 = V_4 -> V_67 ;
if ( V_4 -> V_67 )
V_65 = F_33 ( V_4 -> V_67 ) ;
else
V_65 = L_4 ;
if ( V_4 -> V_68 )
V_66 = F_33 ( V_4 -> V_68 ) ;
else
V_66 = L_4 ;
F_34 ( F_4 ( V_4 -> V_2 ) , L_5 ,
V_65 , V_66 ) ;
if ( V_4 -> V_68 ) {
struct V_72 * V_73 = V_4 -> V_68 -> V_72 -> V_73 ;
unsigned int V_74 = F_35 ( V_73 ) ;
if ( V_74 < V_4 -> V_2 -> V_74 )
V_4 -> V_2 -> V_74 = V_74 ;
}
if ( V_4 -> V_67 ) {
struct V_72 * V_73 = V_4 -> V_67 -> V_72 -> V_73 ;
unsigned int V_74 = F_35 ( V_73 ) ;
if ( V_74 < V_4 -> V_2 -> V_74 )
V_4 -> V_2 -> V_74 = V_74 ;
}
if ( V_28 -> V_75 && V_4 -> V_67 && V_4 -> V_68 )
if ( F_36 ( V_4 , V_4 -> V_2 -> V_76 -> V_77 ) )
V_28 -> V_75 = false ;
}
static inline void F_37 ( struct V_3 * V_4 )
{
if ( V_4 -> V_67 )
F_38 ( V_4 -> V_67 ) ;
if ( V_4 -> V_68 )
F_38 ( V_4 -> V_68 ) ;
V_4 -> V_67 = V_4 -> V_68 = NULL ;
}
static void F_39 ( struct V_3 * V_4 )
{
F_12 ( F_4 ( V_4 -> V_2 ) , L_6 ) ;
F_40 ( V_4 -> V_78 ) ;
V_4 -> V_78 = NULL ;
V_4 -> V_79 = NULL ;
V_4 -> V_12 -> V_80 = 0 ;
}
static void F_41 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_81 * V_82 ;
enum V_83 V_84 ;
if ( V_12 -> V_5 & V_59 ) {
V_84 = V_85 ;
V_82 = V_4 -> V_67 ;
} else {
V_84 = V_86 ;
V_82 = V_4 -> V_68 ;
}
F_42 ( V_82 -> V_72 -> V_73 , V_12 -> V_63 , V_12 -> V_64 , V_84 ) ;
}
static void F_43 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
T_1 V_87 ;
int V_88 ;
for ( V_88 = 0 ; ; V_88 ++ ) {
V_87 = F_6 ( V_4 -> V_8 + V_9 ) ;
if ( ! ( V_87 & V_89 ) || V_88 >= 100 )
break;
F_14 ( 10 ) ;
}
if ( V_87 & V_89 ) {
F_39 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> error = - V_90 ;
}
if ( ! V_12 -> V_80 )
F_41 ( V_4 , V_12 ) ;
if ( V_87 & V_89 ) {
F_12 ( F_4 ( V_4 -> V_2 ) , L_7 ) ;
F_37 ( V_4 ) ;
}
V_4 -> V_78 = NULL ;
V_4 -> V_79 = NULL ;
}
static int F_44 ( struct V_3 * V_4 , struct V_11 * V_12 ,
struct V_81 * * V_81 ,
struct V_91 * * V_92 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_93 V_94 = {
. V_95 = V_4 -> V_96 + V_97 ,
. V_98 = V_4 -> V_96 + V_97 ,
. V_99 = V_100 ,
. V_101 = V_100 ,
. V_102 = V_28 -> V_103 >> 2 ,
. V_104 = V_28 -> V_103 >> 2 ,
. V_105 = false ,
} ;
struct V_81 * V_82 ;
struct V_106 * V_72 ;
struct V_91 * V_107 ;
enum V_83 V_108 ;
int V_109 ;
unsigned long V_5 = V_110 ;
if ( V_12 -> V_5 & V_59 ) {
V_94 . V_111 = V_112 ;
V_108 = V_85 ;
V_82 = V_4 -> V_67 ;
} else {
V_94 . V_111 = V_113 ;
V_108 = V_86 ;
V_82 = V_4 -> V_68 ;
}
if ( ! V_82 )
return - V_14 ;
if ( V_12 -> V_13 * V_12 -> V_114 <= V_28 -> V_115 )
return - V_14 ;
V_72 = V_82 -> V_72 ;
V_109 = F_45 ( V_72 -> V_73 , V_12 -> V_63 , V_12 -> V_64 , V_108 ) ;
if ( V_109 == 0 )
return - V_14 ;
if ( V_4 -> V_28 -> V_75 )
V_5 |= V_116 ;
F_46 ( V_82 , & V_94 ) ;
V_107 = F_47 ( V_82 , V_12 -> V_63 , V_109 ,
V_94 . V_111 , V_5 ) ;
if ( ! V_107 )
goto V_117;
* V_81 = V_82 ;
* V_92 = V_107 ;
return 0 ;
V_117:
F_42 ( V_72 -> V_73 , V_12 -> V_63 , V_12 -> V_64 , V_108 ) ;
return - V_118 ;
}
static inline int F_48 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
if ( V_4 -> V_78 && V_4 -> V_79 )
return 0 ;
return F_44 ( V_4 , V_12 , & V_4 -> V_78 ,
& V_4 -> V_79 ) ;
}
static inline int F_49 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_119 * V_120 = & V_4 -> V_69 ;
return F_44 ( V_4 , V_12 , & V_120 -> V_81 , & V_120 -> V_92 ) ;
}
static int F_50 ( struct V_3 * V_4 , unsigned int V_22 )
{
int V_121 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_121 = F_48 ( V_4 , V_4 -> V_12 ) ;
if ( V_121 )
return V_121 ;
F_51 ( F_4 ( V_4 -> V_2 ) ,
L_8 ,
V_12 -> V_64 , V_12 -> V_13 , V_12 -> V_114 , V_12 -> V_5 ) ;
F_52 ( V_4 -> V_79 ) ;
F_53 ( V_4 -> V_78 ) ;
if ( V_4 -> V_28 -> V_75 )
F_54 ( V_4 , V_12 ) ;
V_22 |= V_122 ;
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_4 -> V_8 + V_55 ) | V_123 ,
V_4 -> V_8 + V_55 ) ;
return 0 ;
}
static void F_55 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_119 * V_124 = & V_4 -> V_69 ;
F_56 ( V_12 -> V_80 && V_12 -> V_80 != V_124 -> V_70 ) ;
F_56 ( ! V_12 -> V_80 && ( V_124 -> V_92 || V_124 -> V_81 ) ) ;
V_4 -> V_79 = V_124 -> V_92 ;
V_4 -> V_78 = V_124 -> V_81 ;
V_124 -> V_92 = NULL ;
V_124 -> V_81 = NULL ;
}
static void F_57 ( struct V_1 * V_2 , struct V_48 * V_49 ,
bool V_125 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_49 -> V_12 ;
struct V_119 * V_120 = & V_4 -> V_69 ;
if ( ! V_12 )
return;
F_23 ( V_12 -> V_80 ) ;
if ( F_10 ( V_4 , V_12 ) )
return;
if ( ! F_49 ( V_4 , V_12 ) )
V_12 -> V_80 = ++ V_120 -> V_70 < 0 ? 1 : V_120 -> V_70 ;
}
static void F_58 ( struct V_1 * V_2 , struct V_48 * V_49 ,
int V_126 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_49 -> V_12 ;
if ( ! V_12 || ! V_12 -> V_80 )
return;
F_41 ( V_4 , V_12 ) ;
if ( V_126 ) {
struct V_119 * V_124 = & V_4 -> V_69 ;
struct V_81 * V_82 ;
if ( V_12 -> V_5 & V_59 )
V_82 = V_4 -> V_67 ;
else
V_82 = V_4 -> V_68 ;
F_40 ( V_82 ) ;
V_124 -> V_92 = NULL ;
V_124 -> V_81 = NULL ;
}
}
static void F_55 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
}
static inline void F_29 ( struct V_3 * V_4 )
{
}
static inline void F_37 ( struct V_3 * V_4 )
{
}
static inline void F_41 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
}
static inline void F_43 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
}
static inline void F_39 ( struct V_3 * V_4 )
{
}
static inline int F_50 ( struct V_3 * V_4 , unsigned int V_22 )
{
return - V_127 ;
}
static void F_59 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
unsigned int V_22 , V_128 , V_129 ;
unsigned long long V_130 ;
void T_2 * V_8 ;
int V_131 ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_9 ,
V_12 -> V_13 , V_12 -> V_114 , V_12 -> V_5 ) ;
V_4 -> V_12 = V_12 ;
V_4 -> V_132 = V_12 -> V_13 * V_12 -> V_114 ;
V_12 -> V_133 = 0 ;
V_130 = ( unsigned long long ) V_12 -> V_134 * V_4 -> V_15 ;
F_61 ( V_130 , V_135 ) ;
V_128 = V_12 -> V_136 + ( unsigned int ) V_130 ;
V_8 = V_4 -> V_8 ;
F_17 ( V_128 , V_8 + V_137 ) ;
F_17 ( V_4 -> V_132 , V_8 + V_138 ) ;
V_131 = F_62 ( V_12 -> V_13 ) - 1 ;
F_23 ( 1 << V_131 != V_12 -> V_13 ) ;
if ( V_28 -> V_139 )
V_22 = V_140 | ( V_12 -> V_13 << 16 ) ;
else if ( V_28 -> V_141 )
V_22 = V_140 | ( V_12 -> V_13 << 4 ) ;
else
V_22 = V_140 | V_131 << 4 ;
if ( V_12 -> V_5 & V_59 )
V_22 |= V_142 ;
if ( V_4 -> V_2 -> V_143 && F_63 ( V_4 -> V_2 -> V_143 ) ) {
T_1 V_16 ;
V_22 |= V_28 -> V_144 ;
if ( V_28 -> V_145 && V_12 -> V_5 & V_146 &&
( V_4 -> V_132 < 8 ||
( V_4 -> V_132 <= 8 && V_4 -> V_31 > 50000000 ) ) )
V_16 = V_4 -> V_17 & ~ V_28 -> V_35 ;
else
V_16 = V_4 -> V_17 | V_28 -> V_35 ;
F_16 ( V_4 , V_16 ) ;
}
if ( V_4 -> V_2 -> V_38 . V_44 == V_45 ||
V_4 -> V_2 -> V_38 . V_44 == V_46 )
V_22 |= V_28 -> V_147 ;
if ( ! F_50 ( V_4 , V_22 ) )
return;
F_27 ( V_4 , V_12 ) ;
if ( V_12 -> V_5 & V_59 ) {
V_129 = V_148 ;
if ( V_4 -> V_132 < V_28 -> V_103 )
V_129 |= V_89 ;
} else {
V_129 = V_149 ;
}
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_8 + V_55 ) & ~ V_123 , V_8 + V_55 ) ;
F_25 ( V_4 , V_129 ) ;
}
static void
F_64 ( struct V_3 * V_4 , struct V_150 * V_51 , T_1 V_151 )
{
void T_2 * V_8 = V_4 -> V_8 ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_10 ,
V_51 -> V_152 , V_51 -> V_153 , V_51 -> V_5 ) ;
if ( F_6 ( V_8 + V_50 ) & V_154 ) {
F_17 ( 0 , V_8 + V_50 ) ;
F_13 ( V_4 ) ;
}
V_151 |= V_51 -> V_152 | V_154 ;
if ( V_51 -> V_5 & V_155 ) {
if ( V_51 -> V_5 & V_156 )
V_151 |= V_157 ;
V_151 |= V_158 ;
}
if ( 0 )
V_151 |= V_159 ;
if ( F_65 ( V_51 ) == V_160 )
V_151 |= V_4 -> V_28 -> V_161 ;
V_4 -> V_51 = V_51 ;
F_17 ( V_51 -> V_153 , V_8 + V_162 ) ;
F_17 ( V_151 , V_8 + V_50 ) ;
}
static void
F_66 ( struct V_3 * V_4 , struct V_11 * V_12 ,
unsigned int V_87 )
{
if ( ! V_12 )
return;
if ( V_87 & ( V_163 | V_164 | V_165 |
V_166 | V_167 ) ) {
T_1 V_168 , V_169 ;
if ( F_67 ( V_4 ) ) {
F_39 ( V_4 ) ;
F_41 ( V_4 , V_12 ) ;
}
V_168 = F_6 ( V_4 -> V_8 + V_170 ) ;
V_169 = V_12 -> V_13 * V_12 -> V_114 - V_168 ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_11 ,
V_87 , V_169 ) ;
if ( V_87 & V_163 ) {
V_169 -= 1 ;
V_12 -> error = - V_171 ;
} else if ( V_87 & V_164 ) {
V_12 -> error = - V_172 ;
} else if ( V_87 & V_165 ) {
V_12 -> error = - V_173 ;
} else if ( V_87 & V_166 ) {
V_12 -> error = - V_90 ;
} else if ( V_87 & V_167 ) {
if ( V_169 > V_4 -> V_28 -> V_115 )
V_169 -= V_4 -> V_28 -> V_115 ;
else
V_169 = 0 ;
V_12 -> error = - V_90 ;
}
V_12 -> V_133 = F_68 ( V_169 , V_12 -> V_13 ) ;
}
if ( V_87 & V_174 )
F_12 ( F_4 ( V_4 -> V_2 ) , L_12 ) ;
if ( V_87 & V_175 || V_12 -> error ) {
if ( F_67 ( V_4 ) )
F_43 ( V_4 , V_12 ) ;
F_26 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> V_133 = V_12 -> V_13 * V_12 -> V_114 ;
if ( ! V_12 -> V_176 || V_4 -> V_49 -> V_177 ) {
F_22 ( V_4 , V_12 -> V_49 ) ;
} else {
F_64 ( V_4 , V_12 -> V_176 , 0 ) ;
}
}
}
static void
F_69 ( struct V_3 * V_4 , struct V_150 * V_51 ,
unsigned int V_87 )
{
void T_2 * V_8 = V_4 -> V_8 ;
bool V_177 , V_178 ;
if ( ! V_51 )
return;
V_177 = ( V_51 == V_4 -> V_49 -> V_177 ) ;
V_178 = V_4 -> V_28 -> V_179 && ( V_51 -> V_5 & V_180 ) ;
if ( ! ( ( V_87 | V_4 -> V_181 ) & ( V_182 | V_183 |
V_184 | V_185 ) ) )
return;
if ( V_4 -> V_181 && ( V_87 & V_10 ) )
return;
if ( ! V_4 -> V_181 && V_178 &&
! ( V_87 & ( V_182 | V_183 ) ) &&
( F_6 ( V_8 + V_9 ) & V_10 ) ) {
F_17 ( F_6 ( V_8 + V_55 ) | V_186 ,
V_8 + V_55 ) ;
V_4 -> V_181 = V_87 & ( V_184 | V_185 ) ;
return;
}
if ( V_4 -> V_181 ) {
F_17 ( F_6 ( V_8 + V_55 ) & ~ V_186 ,
V_8 + V_55 ) ;
V_4 -> V_181 = 0 ;
}
V_4 -> V_51 = NULL ;
if ( V_87 & V_183 ) {
V_51 -> error = - V_172 ;
} else if ( V_87 & V_182 && V_51 -> V_5 & V_187 ) {
V_51 -> error = - V_171 ;
} else {
V_51 -> V_188 [ 0 ] = F_6 ( V_8 + V_189 ) ;
V_51 -> V_188 [ 1 ] = F_6 ( V_8 + V_190 ) ;
V_51 -> V_188 [ 2 ] = F_6 ( V_8 + V_191 ) ;
V_51 -> V_188 [ 3 ] = F_6 ( V_8 + V_192 ) ;
}
if ( ( ! V_177 && ! V_51 -> V_12 ) || V_51 -> error ) {
if ( V_4 -> V_12 ) {
if ( F_67 ( V_4 ) ) {
F_39 ( V_4 ) ;
F_41 ( V_4 , V_4 -> V_12 ) ;
}
F_26 ( V_4 ) ;
}
F_22 ( V_4 , V_4 -> V_49 ) ;
} else if ( V_177 ) {
F_64 ( V_4 , V_4 -> V_49 -> V_51 , 0 ) ;
} else if ( ! ( V_51 -> V_12 -> V_5 & V_59 ) ) {
F_59 ( V_4 , V_51 -> V_12 ) ;
}
}
static int F_70 ( struct V_3 * V_4 , T_1 V_87 , int V_168 )
{
return V_168 - ( F_6 ( V_4 -> V_8 + V_193 ) << 2 ) ;
}
static int F_71 ( struct V_3 * V_4 , T_1 V_87 , int V_194 )
{
if ( V_87 & V_195 )
return V_4 -> V_28 -> V_103 ;
else if ( V_87 & V_196 )
return 4 ;
return 0 ;
}
static int F_72 ( struct V_3 * V_4 , char * V_197 , unsigned int V_168 )
{
void T_2 * V_8 = V_4 -> V_8 ;
char * V_198 = V_197 ;
T_1 V_87 = F_6 ( V_4 -> V_8 + V_9 ) ;
int V_199 = V_4 -> V_132 ;
do {
int V_200 = V_4 -> V_201 ( V_4 , V_87 , V_199 ) ;
if ( V_200 > V_168 )
V_200 = V_168 ;
if ( V_200 <= 0 )
break;
if ( F_73 ( V_200 & 0x3 ) ) {
if ( V_200 < 4 ) {
unsigned char V_202 [ 4 ] ;
F_74 ( V_8 + V_97 , V_202 , 1 ) ;
memcpy ( V_198 , V_202 , V_200 ) ;
} else {
F_74 ( V_8 + V_97 , V_198 , V_200 >> 2 ) ;
V_200 &= ~ 0x3 ;
}
} else {
F_74 ( V_8 + V_97 , V_198 , V_200 >> 2 ) ;
}
V_198 += V_200 ;
V_168 -= V_200 ;
V_199 -= V_200 ;
if ( V_168 == 0 )
break;
V_87 = F_6 ( V_8 + V_9 ) ;
} while ( V_87 & V_196 );
return V_198 - V_197 ;
}
static int F_75 ( struct V_3 * V_4 , char * V_197 , unsigned int V_168 , T_1 V_87 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
char * V_198 = V_197 ;
do {
unsigned int V_200 , V_203 ;
V_203 = V_87 & V_204 ?
V_28 -> V_115 : V_28 -> V_103 ;
V_200 = F_76 ( V_168 , V_203 ) ;
F_77 ( V_8 + V_97 , V_198 , ( V_200 + 3 ) >> 2 ) ;
V_198 += V_200 ;
V_168 -= V_200 ;
if ( V_168 == 0 )
break;
V_87 = F_6 ( V_8 + V_9 ) ;
} while ( V_87 & V_205 );
return V_198 - V_197 ;
}
static T_4 F_78 ( int V_206 , void * V_207 )
{
struct V_3 * V_4 = V_207 ;
struct V_208 * V_62 = & V_4 -> V_62 ;
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
unsigned long V_5 ;
T_1 V_87 ;
V_87 = F_6 ( V_8 + V_9 ) ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_13 , V_87 ) ;
F_79 ( V_5 ) ;
do {
unsigned int V_168 , V_209 ;
char * V_197 ;
if ( ! ( V_87 & ( V_205 | V_196 ) ) )
break;
if ( ! F_80 ( V_62 ) )
break;
V_197 = V_62 -> V_210 ;
V_168 = V_62 -> V_211 ;
V_209 = 0 ;
if ( V_87 & V_212 )
V_209 = F_72 ( V_4 , V_197 , V_168 ) ;
if ( V_87 & V_213 )
V_209 = F_75 ( V_4 , V_197 , V_168 , V_87 ) ;
V_62 -> V_214 = V_209 ;
V_4 -> V_132 -= V_209 ;
V_168 -= V_209 ;
if ( V_168 )
break;
V_87 = F_6 ( V_8 + V_9 ) ;
} while ( 1 );
F_81 ( V_62 ) ;
F_82 ( V_5 ) ;
if ( V_87 & V_212 && V_4 -> V_132 < V_28 -> V_103 )
F_25 ( V_4 , V_89 ) ;
if ( V_4 -> V_132 == 0 ) {
F_25 ( V_4 , 0 ) ;
F_17 ( F_6 ( V_8 + V_55 ) | V_123 , V_8 + V_55 ) ;
}
return V_215 ;
}
static T_4 F_83 ( int V_206 , void * V_207 )
{
struct V_3 * V_4 = V_207 ;
T_1 V_87 ;
int V_121 = 0 ;
F_84 ( & V_4 -> V_7 ) ;
do {
V_87 = F_6 ( V_4 -> V_8 + V_9 ) ;
if ( V_4 -> V_53 ) {
if ( V_87 & F_6 ( V_4 -> V_8 + V_57 ) )
F_78 ( V_206 , V_207 ) ;
V_87 &= ~ V_56 ;
}
V_87 &= F_6 ( V_4 -> V_8 + V_55 ) ;
F_17 ( V_87 , V_4 -> V_8 + V_216 ) ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_14 , V_87 ) ;
if ( V_4 -> V_28 -> V_217 ) {
F_66 ( V_4 , V_4 -> V_12 , V_87 ) ;
F_69 ( V_4 , V_4 -> V_51 , V_87 ) ;
} else {
F_69 ( V_4 , V_4 -> V_51 , V_87 ) ;
F_66 ( V_4 , V_4 -> V_12 , V_87 ) ;
}
if ( V_4 -> V_181 )
V_87 &= ~ V_10 ;
V_121 = 1 ;
} while ( V_87 );
F_85 ( & V_4 -> V_7 ) ;
return F_86 ( V_121 ) ;
}
static void F_87 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_56 ( V_4 -> V_49 != NULL ) ;
V_49 -> V_51 -> error = F_10 ( V_4 , V_49 -> V_12 ) ;
if ( V_49 -> V_51 -> error ) {
F_24 ( V_2 , V_49 ) ;
return;
}
F_3 ( F_4 ( V_2 ) ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
V_4 -> V_49 = V_49 ;
if ( V_49 -> V_12 )
F_55 ( V_4 , V_49 -> V_12 ) ;
if ( V_49 -> V_12 && V_49 -> V_12 -> V_5 & V_59 )
F_59 ( V_4 , V_49 -> V_12 ) ;
if ( V_49 -> V_177 )
F_64 ( V_4 , V_49 -> V_177 , 0 ) ;
else
F_64 ( V_4 , V_49 -> V_51 , 0 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_88 ( struct V_1 * V_2 , struct V_218 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_4 -> V_28 ;
T_1 V_19 = 0 ;
unsigned long V_5 ;
int V_121 ;
F_3 ( F_4 ( V_2 ) ) ;
if ( V_4 -> V_219 -> V_220 &&
V_4 -> V_219 -> V_220 ( F_4 ( V_2 ) , V_38 ) )
F_12 ( F_4 ( V_2 ) , L_15 ) ;
switch ( V_38 -> V_221 ) {
case V_222 :
if ( ! F_89 ( V_2 -> V_223 . V_224 ) )
F_90 ( V_2 , V_2 -> V_223 . V_224 , 0 ) ;
if ( ! F_89 ( V_2 -> V_223 . V_225 ) && V_4 -> V_226 ) {
F_91 ( V_2 -> V_223 . V_225 ) ;
V_4 -> V_226 = false ;
}
break;
case V_227 :
if ( ! F_89 ( V_2 -> V_223 . V_224 ) )
F_90 ( V_2 , V_2 -> V_223 . V_224 , V_38 -> V_228 ) ;
V_19 |= V_28 -> V_229 ;
break;
case V_230 :
if ( ! F_89 ( V_2 -> V_223 . V_225 ) && ! V_4 -> V_226 ) {
V_121 = F_92 ( V_2 -> V_223 . V_225 ) ;
if ( V_121 < 0 )
F_12 ( F_4 ( V_2 ) ,
L_16 ) ;
else
V_4 -> V_226 = true ;
}
V_19 |= V_231 ;
break;
}
if ( V_28 -> V_232 && V_38 -> V_221 != V_222 ) {
V_19 |= V_4 -> V_233 ;
if ( V_38 -> V_39 == V_40 )
V_19 &= ~ V_234 ;
else if ( V_38 -> V_39 == V_235 )
V_19 &= ( ~ V_234 &
~ V_236 &
~ V_237 ) ;
}
if ( V_38 -> V_238 == V_239 ) {
if ( V_4 -> V_240 != V_241 )
V_19 |= V_242 ;
else {
V_19 |= V_243 ;
}
}
if ( ! V_38 -> clock && V_28 -> V_244 )
V_19 &= ~ V_231 ;
if ( V_4 -> V_28 -> V_30 &&
V_38 -> clock != V_4 -> V_245 ) {
V_121 = F_93 ( V_4 -> V_16 , V_38 -> clock ) ;
if ( V_121 < 0 )
F_12 ( F_4 ( V_4 -> V_2 ) ,
L_17 , V_121 ) ;
else
V_4 -> V_31 = F_94 ( V_4 -> V_16 ) ;
}
V_4 -> V_245 = V_38 -> clock ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_20 ( V_4 , V_38 -> clock ) ;
F_18 ( V_4 , V_19 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_246 * V_219 = V_4 -> V_219 ;
unsigned int V_87 = F_96 ( V_2 ) ;
if ( V_87 == - V_127 ) {
if ( ! V_219 -> V_87 )
return 1 ;
V_87 = V_219 -> V_87 ( F_4 ( V_4 -> V_2 ) ) ;
}
return V_87 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_218 * V_38 )
{
int V_121 = 0 ;
if ( ! F_89 ( V_2 -> V_223 . V_225 ) ) {
F_3 ( F_4 ( V_2 ) ) ;
switch ( V_38 -> V_247 ) {
case V_248 :
V_121 = F_98 ( V_2 -> V_223 . V_225 ,
2700000 , 3600000 ) ;
break;
case V_249 :
V_121 = F_98 ( V_2 -> V_223 . V_225 ,
1700000 , 1950000 ) ;
break;
case V_250 :
V_121 = F_98 ( V_2 -> V_223 . V_225 ,
1100000 , 1300000 ) ;
break;
}
if ( V_121 )
F_99 ( F_4 ( V_2 ) , L_18 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
}
return V_121 ;
}
static int F_100 ( struct V_251 * V_252 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_121 = F_101 ( V_2 ) ;
if ( V_121 )
return V_121 ;
if ( F_102 ( V_252 , L_19 , NULL ) )
V_4 -> V_233 |= V_253 ;
if ( F_102 ( V_252 , L_20 , NULL ) )
V_4 -> V_233 |= V_237 ;
if ( F_102 ( V_252 , L_21 , NULL ) )
V_4 -> V_233 |= V_236 ;
if ( F_102 ( V_252 , L_22 , NULL ) )
V_4 -> V_233 |= V_234 ;
if ( F_102 ( V_252 , L_23 , NULL ) )
V_4 -> V_233 |= V_254 ;
if ( F_102 ( V_252 , L_24 , NULL ) )
V_4 -> V_233 |= V_255 ;
if ( F_102 ( V_252 , L_25 , NULL ) )
V_2 -> V_256 |= V_257 ;
if ( F_102 ( V_252 , L_26 , NULL ) )
V_2 -> V_256 |= V_258 ;
return 0 ;
}
static int F_103 ( struct V_259 * V_73 ,
const struct V_260 * V_261 )
{
struct V_246 * V_219 = V_73 -> V_73 . V_262 ;
struct V_251 * V_252 = V_73 -> V_73 . V_77 ;
struct V_27 * V_28 = V_261 -> V_12 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_121 ;
if ( ! V_219 && ! V_252 ) {
F_12 ( & V_73 -> V_73 , L_27 ) ;
return - V_14 ;
}
if ( ! V_219 ) {
V_219 = F_104 ( & V_73 -> V_73 , sizeof( * V_219 ) , V_263 ) ;
if ( ! V_219 )
return - V_118 ;
}
V_2 = F_105 ( sizeof( struct V_3 ) , & V_73 -> V_73 ) ;
if ( ! V_2 )
return - V_118 ;
V_121 = F_100 ( V_252 , V_2 ) ;
if ( V_121 )
goto V_264;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_240 = F_106 ( V_73 ) ;
V_4 -> V_265 = F_107 ( V_73 ) ;
F_60 ( F_4 ( V_2 ) , L_28 , V_4 -> V_240 ) ;
F_60 ( F_4 ( V_2 ) , L_29 , V_4 -> V_265 ) ;
V_4 -> V_16 = F_108 ( & V_73 -> V_73 , NULL ) ;
if ( F_89 ( V_4 -> V_16 ) ) {
V_121 = F_109 ( V_4 -> V_16 ) ;
goto V_264;
}
V_121 = F_110 ( V_4 -> V_16 ) ;
if ( V_121 )
goto V_264;
if ( V_28 -> V_266 )
V_4 -> V_201 = F_71 ;
else
V_4 -> V_201 = F_70 ;
V_4 -> V_219 = V_219 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_31 = F_94 ( V_4 -> V_16 ) ;
if ( V_4 -> V_31 > V_28 -> V_267 ) {
V_121 = F_93 ( V_4 -> V_16 , V_28 -> V_267 ) ;
if ( V_121 < 0 )
goto V_268;
V_4 -> V_31 = F_94 ( V_4 -> V_16 ) ;
F_60 ( F_4 ( V_2 ) , L_30 ,
V_4 -> V_31 ) ;
}
V_4 -> V_96 = V_73 -> V_269 . V_270 ;
V_4 -> V_8 = F_111 ( & V_73 -> V_73 , & V_73 -> V_269 ) ;
if ( F_89 ( V_4 -> V_8 ) ) {
V_121 = F_109 ( V_4 -> V_8 ) ;
goto V_268;
}
if ( V_28 -> V_33 )
V_2 -> V_271 = F_21 ( V_4 -> V_31 , 257 ) ;
else if ( V_28 -> V_30 )
V_2 -> V_271 = F_112 ( V_4 -> V_16 , 100000 ) ;
else
V_2 -> V_271 = F_21 ( V_4 -> V_31 , 512 ) ;
if ( V_2 -> V_267 )
V_2 -> V_267 = V_28 -> V_30 ?
F_76 ( V_28 -> V_267 , V_2 -> V_267 ) :
F_76 ( V_4 -> V_31 , V_2 -> V_267 ) ;
else
V_2 -> V_267 = V_28 -> V_30 ?
V_272 : F_76 ( V_4 -> V_31 , V_272 ) ;
F_60 ( F_4 ( V_2 ) , L_31 , V_2 -> V_267 ) ;
F_113 ( V_2 ) ;
if ( ! V_2 -> V_273 )
V_2 -> V_273 = V_219 -> V_274 ;
else if ( V_219 -> V_274 )
F_99 ( F_4 ( V_2 ) , L_32 ) ;
if ( ! V_252 ) {
if ( ! V_219 -> V_275 )
V_2 -> V_276 |= V_277 ;
V_2 -> V_276 |= V_278 ;
}
V_2 -> V_256 |= V_279 ;
if ( V_28 -> V_179 ) {
V_280 . V_281 = F_1 ;
F_19 ( V_4 , V_24 ) ;
V_2 -> V_256 |= V_282 ;
V_2 -> V_283 = 0 ;
}
V_2 -> V_284 = & V_280 ;
V_2 -> V_285 |= V_286 ;
V_2 -> V_287 = V_288 ;
V_2 -> V_289 = ( 1 << V_28 -> V_290 ) - 1 ;
V_2 -> V_74 = V_2 -> V_289 ;
V_2 -> V_291 = 1 << 11 ;
V_2 -> V_292 = V_2 -> V_289 >> 11 ;
F_114 ( & V_4 -> V_7 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
F_17 ( 0 , V_4 -> V_8 + V_57 ) ;
F_17 ( 0xfff , V_4 -> V_8 + V_216 ) ;
if ( ! V_252 ) {
V_121 = F_115 ( V_2 , L_33 , 0 , false , 0 , NULL ) ;
if ( V_121 < 0 ) {
if ( V_121 == - V_293 )
goto V_268;
else if ( F_116 ( V_219 -> V_294 ) ) {
V_121 = F_117 ( V_2 , V_219 -> V_294 , 0 ) ;
if ( V_121 )
goto V_268;
}
}
V_121 = F_118 ( V_2 , L_34 , 0 , false , 0 , NULL ) ;
if ( V_121 < 0 ) {
if ( V_121 == - V_293 )
goto V_268;
else if ( F_116 ( V_219 -> V_295 ) ) {
V_121 = F_119 ( V_2 , V_219 -> V_295 ) ;
if ( V_121 )
goto V_268;
}
}
}
V_121 = F_120 ( & V_73 -> V_73 , V_73 -> V_206 [ 0 ] , F_83 , V_296 ,
V_297 L_35 , V_4 ) ;
if ( V_121 )
goto V_268;
if ( ! V_73 -> V_206 [ 1 ] )
V_4 -> V_53 = true ;
else {
V_121 = F_120 ( & V_73 -> V_73 , V_73 -> V_206 [ 1 ] , F_78 ,
V_296 , V_297 L_36 , V_4 ) ;
if ( V_121 )
goto V_268;
}
F_17 ( V_298 , V_4 -> V_8 + V_55 ) ;
F_121 ( V_73 , V_2 ) ;
F_34 ( & V_73 -> V_73 , L_37 ,
F_122 ( V_2 ) , F_123 ( V_73 ) , F_106 ( V_73 ) ,
F_107 ( V_73 ) , ( unsigned long long ) V_73 -> V_269 . V_270 ,
V_73 -> V_206 [ 0 ] , V_73 -> V_206 [ 1 ] ) ;
F_29 ( V_4 ) ;
F_124 ( & V_73 -> V_73 , 50 ) ;
F_125 ( & V_73 -> V_73 ) ;
F_126 ( & V_73 -> V_73 ) ;
F_127 ( V_2 ) ;
return 0 ;
V_268:
F_128 ( V_4 -> V_16 ) ;
V_264:
F_129 ( V_2 ) ;
return V_121 ;
}
static int F_130 ( struct V_259 * V_73 )
{
struct V_1 * V_2 = F_131 ( V_73 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_73 -> V_73 ) ;
F_132 ( V_2 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
F_17 ( 0 , V_4 -> V_8 + V_57 ) ;
F_17 ( 0 , V_4 -> V_8 + V_50 ) ;
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_37 ( V_4 ) ;
F_128 ( V_4 -> V_16 ) ;
F_129 ( V_2 ) ;
}
return 0 ;
}
static void F_133 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
if ( V_4 -> V_28 -> V_299 ) {
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_17 ( 0 , V_4 -> V_8 + V_21 ) ;
F_17 ( 0 , V_4 -> V_8 + V_18 ) ;
}
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_134 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
if ( V_4 -> V_28 -> V_299 ) {
F_17 ( V_4 -> V_17 , V_4 -> V_8 + V_18 ) ;
F_17 ( V_4 -> V_23 , V_4 -> V_8 + V_25 ) ;
F_17 ( V_4 -> V_20 , V_4 -> V_8 + V_21 ) ;
}
F_17 ( V_298 , V_4 -> V_8 + V_55 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static int F_135 ( struct V_72 * V_73 )
{
struct V_259 * V_300 = F_136 ( V_73 ) ;
struct V_1 * V_2 = F_131 ( V_300 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_137 ( V_73 ) ;
F_133 ( V_4 ) ;
F_128 ( V_4 -> V_16 ) ;
}
return 0 ;
}
static int F_138 ( struct V_72 * V_73 )
{
struct V_259 * V_300 = F_136 ( V_73 ) ;
struct V_1 * V_2 = F_131 ( V_300 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_110 ( V_4 -> V_16 ) ;
F_134 ( V_4 ) ;
F_139 ( V_73 ) ;
}
return 0 ;
}
