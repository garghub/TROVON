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
}
static inline void F_36 ( struct V_3 * V_4 )
{
if ( V_4 -> V_67 )
F_37 ( V_4 -> V_67 ) ;
if ( V_4 -> V_68 )
F_37 ( V_4 -> V_68 ) ;
V_4 -> V_67 = V_4 -> V_68 = NULL ;
}
static void F_38 ( struct V_3 * V_4 )
{
F_12 ( F_4 ( V_4 -> V_2 ) , L_6 ) ;
F_39 ( V_4 -> V_75 ) ;
V_4 -> V_75 = NULL ;
V_4 -> V_76 = NULL ;
V_4 -> V_12 -> V_77 = 0 ;
}
static void F_40 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_78 * V_79 ;
enum V_80 V_81 ;
if ( V_12 -> V_5 & V_59 ) {
V_81 = V_82 ;
V_79 = V_4 -> V_67 ;
} else {
V_81 = V_83 ;
V_79 = V_4 -> V_68 ;
}
F_41 ( V_79 -> V_72 -> V_73 , V_12 -> V_63 , V_12 -> V_64 , V_81 ) ;
}
static void F_42 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
T_1 V_84 ;
int V_85 ;
for ( V_85 = 0 ; ; V_85 ++ ) {
V_84 = F_6 ( V_4 -> V_8 + V_9 ) ;
if ( ! ( V_84 & V_86 ) || V_85 >= 100 )
break;
F_14 ( 10 ) ;
}
if ( V_84 & V_86 ) {
F_38 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> error = - V_87 ;
}
if ( ! V_12 -> V_77 )
F_40 ( V_4 , V_12 ) ;
if ( V_84 & V_86 ) {
F_12 ( F_4 ( V_4 -> V_2 ) , L_7 ) ;
F_36 ( V_4 ) ;
}
V_4 -> V_75 = NULL ;
V_4 -> V_76 = NULL ;
}
static int F_43 ( struct V_3 * V_4 , struct V_11 * V_12 ,
struct V_78 * * V_78 ,
struct V_88 * * V_89 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_90 V_91 = {
. V_92 = V_4 -> V_93 + V_94 ,
. V_95 = V_4 -> V_93 + V_94 ,
. V_96 = V_97 ,
. V_98 = V_97 ,
. V_99 = V_28 -> V_100 >> 2 ,
. V_101 = V_28 -> V_100 >> 2 ,
. V_102 = false ,
} ;
struct V_78 * V_79 ;
struct V_103 * V_72 ;
struct V_88 * V_104 ;
enum V_80 V_105 ;
int V_106 ;
if ( V_12 -> V_5 & V_59 ) {
V_91 . V_107 = V_108 ;
V_105 = V_82 ;
V_79 = V_4 -> V_67 ;
} else {
V_91 . V_107 = V_109 ;
V_105 = V_83 ;
V_79 = V_4 -> V_68 ;
}
if ( ! V_79 )
return - V_14 ;
if ( V_12 -> V_13 * V_12 -> V_110 <= V_28 -> V_111 )
return - V_14 ;
V_72 = V_79 -> V_72 ;
V_106 = F_44 ( V_72 -> V_73 , V_12 -> V_63 , V_12 -> V_64 , V_105 ) ;
if ( V_106 == 0 )
return - V_14 ;
F_45 ( V_79 , & V_91 ) ;
V_104 = F_46 ( V_79 , V_12 -> V_63 , V_106 ,
V_91 . V_107 , V_112 ) ;
if ( ! V_104 )
goto V_113;
* V_78 = V_79 ;
* V_89 = V_104 ;
return 0 ;
V_113:
F_41 ( V_72 -> V_73 , V_12 -> V_63 , V_12 -> V_64 , V_105 ) ;
return - V_114 ;
}
static inline int F_47 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
if ( V_4 -> V_75 && V_4 -> V_76 )
return 0 ;
return F_43 ( V_4 , V_12 , & V_4 -> V_75 ,
& V_4 -> V_76 ) ;
}
static inline int F_48 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_115 * V_116 = & V_4 -> V_69 ;
return F_43 ( V_4 , V_12 , & V_116 -> V_78 , & V_116 -> V_89 ) ;
}
static int F_49 ( struct V_3 * V_4 , unsigned int V_22 )
{
int V_117 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_117 = F_47 ( V_4 , V_4 -> V_12 ) ;
if ( V_117 )
return V_117 ;
F_50 ( F_4 ( V_4 -> V_2 ) ,
L_8 ,
V_12 -> V_64 , V_12 -> V_13 , V_12 -> V_110 , V_12 -> V_5 ) ;
F_51 ( V_4 -> V_76 ) ;
F_52 ( V_4 -> V_75 ) ;
V_22 |= V_118 ;
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_4 -> V_8 + V_55 ) | V_119 ,
V_4 -> V_8 + V_55 ) ;
return 0 ;
}
static void F_53 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_115 * V_120 = & V_4 -> V_69 ;
F_54 ( V_12 -> V_77 && V_12 -> V_77 != V_120 -> V_70 ) ;
F_54 ( ! V_12 -> V_77 && ( V_120 -> V_89 || V_120 -> V_78 ) ) ;
V_4 -> V_76 = V_120 -> V_89 ;
V_4 -> V_75 = V_120 -> V_78 ;
V_120 -> V_89 = NULL ;
V_120 -> V_78 = NULL ;
}
static void F_55 ( struct V_1 * V_2 , struct V_48 * V_49 ,
bool V_121 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_49 -> V_12 ;
struct V_115 * V_116 = & V_4 -> V_69 ;
if ( ! V_12 )
return;
F_23 ( V_12 -> V_77 ) ;
if ( F_10 ( V_4 , V_12 ) )
return;
if ( ! F_48 ( V_4 , V_12 ) )
V_12 -> V_77 = ++ V_116 -> V_70 < 0 ? 1 : V_116 -> V_70 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_48 * V_49 ,
int V_122 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_49 -> V_12 ;
if ( ! V_12 || ! V_12 -> V_77 )
return;
F_40 ( V_4 , V_12 ) ;
if ( V_122 ) {
struct V_115 * V_120 = & V_4 -> V_69 ;
struct V_78 * V_79 ;
if ( V_12 -> V_5 & V_59 )
V_79 = V_4 -> V_67 ;
else
V_79 = V_4 -> V_68 ;
F_39 ( V_79 ) ;
V_120 -> V_89 = NULL ;
V_120 -> V_78 = NULL ;
}
}
static void F_53 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
}
static inline void F_29 ( struct V_3 * V_4 )
{
}
static inline void F_36 ( struct V_3 * V_4 )
{
}
static inline void F_40 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
}
static inline void F_42 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
}
static inline void F_38 ( struct V_3 * V_4 )
{
}
static inline int F_49 ( struct V_3 * V_4 , unsigned int V_22 )
{
return - V_123 ;
}
static void F_57 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
unsigned int V_22 , V_124 , V_125 ;
unsigned long long V_126 ;
void T_2 * V_8 ;
int V_127 ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_9 ,
V_12 -> V_13 , V_12 -> V_110 , V_12 -> V_5 ) ;
V_4 -> V_12 = V_12 ;
V_4 -> V_128 = V_12 -> V_13 * V_12 -> V_110 ;
V_12 -> V_129 = 0 ;
V_126 = ( unsigned long long ) V_12 -> V_130 * V_4 -> V_15 ;
F_59 ( V_126 , V_131 ) ;
V_124 = V_12 -> V_132 + ( unsigned int ) V_126 ;
V_8 = V_4 -> V_8 ;
F_17 ( V_124 , V_8 + V_133 ) ;
F_17 ( V_4 -> V_128 , V_8 + V_134 ) ;
V_127 = F_60 ( V_12 -> V_13 ) - 1 ;
F_23 ( 1 << V_127 != V_12 -> V_13 ) ;
if ( V_28 -> V_135 )
V_22 = V_136 | ( V_12 -> V_13 << 16 ) ;
else if ( V_28 -> V_137 )
V_22 = V_136 | ( V_12 -> V_13 << 4 ) ;
else
V_22 = V_136 | V_127 << 4 ;
if ( V_12 -> V_5 & V_59 )
V_22 |= V_138 ;
if ( V_28 -> V_139 && V_4 -> V_2 -> V_140 )
if ( F_61 ( V_4 -> V_2 -> V_140 ) ) {
T_1 V_16 ;
V_22 |= V_141 ;
if ( V_12 -> V_5 & V_142 &&
( V_4 -> V_128 < 8 ||
( V_4 -> V_128 <= 8 && V_4 -> V_31 > 50000000 ) ) )
V_16 = V_4 -> V_17 & ~ V_28 -> V_35 ;
else
V_16 = V_4 -> V_17 | V_28 -> V_35 ;
F_16 ( V_4 , V_16 ) ;
}
if ( V_4 -> V_2 -> V_38 . V_44 == V_45 ||
V_4 -> V_2 -> V_38 . V_44 == V_46 )
V_22 |= V_28 -> V_143 ;
if ( ! F_49 ( V_4 , V_22 ) )
return;
F_27 ( V_4 , V_12 ) ;
if ( V_12 -> V_5 & V_59 ) {
V_125 = V_144 ;
if ( V_4 -> V_128 < V_28 -> V_100 )
V_125 |= V_86 ;
} else {
V_125 = V_145 ;
}
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_8 + V_55 ) & ~ V_119 , V_8 + V_55 ) ;
F_25 ( V_4 , V_125 ) ;
}
static void
F_62 ( struct V_3 * V_4 , struct V_146 * V_51 , T_1 V_147 )
{
void T_2 * V_8 = V_4 -> V_8 ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_10 ,
V_51 -> V_148 , V_51 -> V_149 , V_51 -> V_5 ) ;
if ( F_6 ( V_8 + V_50 ) & V_150 ) {
F_17 ( 0 , V_8 + V_50 ) ;
F_13 ( V_4 ) ;
}
V_147 |= V_51 -> V_148 | V_150 ;
if ( V_51 -> V_5 & V_151 ) {
if ( V_51 -> V_5 & V_152 )
V_147 |= V_153 ;
V_147 |= V_154 ;
}
if ( 0 )
V_147 |= V_155 ;
if ( F_63 ( V_51 ) == V_156 )
V_147 |= V_4 -> V_28 -> V_157 ;
V_4 -> V_51 = V_51 ;
F_17 ( V_51 -> V_149 , V_8 + V_158 ) ;
F_17 ( V_147 , V_8 + V_50 ) ;
}
static void
F_64 ( struct V_3 * V_4 , struct V_11 * V_12 ,
unsigned int V_84 )
{
if ( ! V_12 )
return;
if ( V_84 & ( V_159 | V_160 | V_161 |
V_162 | V_163 ) ) {
T_1 V_164 , V_165 ;
if ( F_65 ( V_4 ) ) {
F_38 ( V_4 ) ;
F_40 ( V_4 , V_12 ) ;
}
V_164 = F_6 ( V_4 -> V_8 + V_166 ) ;
V_165 = V_12 -> V_13 * V_12 -> V_110 - V_164 ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_11 ,
V_84 , V_165 ) ;
if ( V_84 & V_159 ) {
V_165 -= 1 ;
V_12 -> error = - V_167 ;
} else if ( V_84 & V_160 ) {
V_12 -> error = - V_168 ;
} else if ( V_84 & V_161 ) {
V_12 -> error = - V_169 ;
} else if ( V_84 & V_162 ) {
V_12 -> error = - V_87 ;
} else if ( V_84 & V_163 ) {
if ( V_165 > V_4 -> V_28 -> V_111 )
V_165 -= V_4 -> V_28 -> V_111 ;
else
V_165 = 0 ;
V_12 -> error = - V_87 ;
}
V_12 -> V_129 = F_66 ( V_165 , V_12 -> V_13 ) ;
}
if ( V_84 & V_170 )
F_12 ( F_4 ( V_4 -> V_2 ) , L_12 ) ;
if ( V_84 & V_171 || V_12 -> error ) {
if ( F_65 ( V_4 ) )
F_42 ( V_4 , V_12 ) ;
F_26 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> V_129 = V_12 -> V_13 * V_12 -> V_110 ;
if ( ! V_12 -> V_172 || V_4 -> V_49 -> V_173 ) {
F_22 ( V_4 , V_12 -> V_49 ) ;
} else {
F_62 ( V_4 , V_12 -> V_172 , 0 ) ;
}
}
}
static void
F_67 ( struct V_3 * V_4 , struct V_146 * V_51 ,
unsigned int V_84 )
{
void T_2 * V_8 = V_4 -> V_8 ;
bool V_173 , V_174 ;
if ( ! V_51 )
return;
V_173 = ( V_51 == V_4 -> V_49 -> V_173 ) ;
V_174 = V_4 -> V_28 -> V_175 && ( V_51 -> V_5 & V_176 ) ;
if ( ! ( ( V_84 | V_4 -> V_177 ) & ( V_178 | V_179 |
V_180 | V_181 ) ) )
return;
if ( V_4 -> V_177 && ( V_84 & V_10 ) )
return;
if ( ! V_4 -> V_177 && V_174 &&
! ( V_84 & ( V_178 | V_179 ) ) &&
( F_6 ( V_8 + V_9 ) & V_10 ) ) {
F_17 ( F_6 ( V_8 + V_55 ) | V_182 ,
V_8 + V_55 ) ;
V_4 -> V_177 = V_84 & ( V_180 | V_181 ) ;
return;
}
if ( V_4 -> V_177 ) {
F_17 ( F_6 ( V_8 + V_55 ) & ~ V_182 ,
V_8 + V_55 ) ;
V_4 -> V_177 = 0 ;
}
V_4 -> V_51 = NULL ;
if ( V_84 & V_179 ) {
V_51 -> error = - V_168 ;
} else if ( V_84 & V_178 && V_51 -> V_5 & V_183 ) {
V_51 -> error = - V_167 ;
} else {
V_51 -> V_184 [ 0 ] = F_6 ( V_8 + V_185 ) ;
V_51 -> V_184 [ 1 ] = F_6 ( V_8 + V_186 ) ;
V_51 -> V_184 [ 2 ] = F_6 ( V_8 + V_187 ) ;
V_51 -> V_184 [ 3 ] = F_6 ( V_8 + V_188 ) ;
}
if ( ( ! V_173 && ! V_51 -> V_12 ) || V_51 -> error ) {
if ( V_4 -> V_12 ) {
if ( F_65 ( V_4 ) ) {
F_38 ( V_4 ) ;
F_40 ( V_4 , V_4 -> V_12 ) ;
}
F_26 ( V_4 ) ;
}
F_22 ( V_4 , V_4 -> V_49 ) ;
} else if ( V_173 ) {
F_62 ( V_4 , V_4 -> V_49 -> V_51 , 0 ) ;
} else if ( ! ( V_51 -> V_12 -> V_5 & V_59 ) ) {
F_57 ( V_4 , V_51 -> V_12 ) ;
}
}
static int F_68 ( struct V_3 * V_4 , T_1 V_84 , int V_164 )
{
return V_164 - ( F_6 ( V_4 -> V_8 + V_189 ) << 2 ) ;
}
static int F_69 ( struct V_3 * V_4 , T_1 V_84 , int V_190 )
{
if ( V_84 & V_191 )
return V_4 -> V_28 -> V_100 ;
else if ( V_84 & V_192 )
return 4 ;
return 0 ;
}
static int F_70 ( struct V_3 * V_4 , char * V_193 , unsigned int V_164 )
{
void T_2 * V_8 = V_4 -> V_8 ;
char * V_194 = V_193 ;
T_1 V_84 = F_6 ( V_4 -> V_8 + V_9 ) ;
int V_195 = V_4 -> V_128 ;
do {
int V_196 = V_4 -> V_197 ( V_4 , V_84 , V_195 ) ;
if ( V_196 > V_164 )
V_196 = V_164 ;
if ( V_196 <= 0 )
break;
if ( F_71 ( V_196 & 0x3 ) ) {
if ( V_196 < 4 ) {
unsigned char V_198 [ 4 ] ;
F_72 ( V_8 + V_94 , V_198 , 1 ) ;
memcpy ( V_194 , V_198 , V_196 ) ;
} else {
F_72 ( V_8 + V_94 , V_194 , V_196 >> 2 ) ;
V_196 &= ~ 0x3 ;
}
} else {
F_72 ( V_8 + V_94 , V_194 , V_196 >> 2 ) ;
}
V_194 += V_196 ;
V_164 -= V_196 ;
V_195 -= V_196 ;
if ( V_164 == 0 )
break;
V_84 = F_6 ( V_8 + V_9 ) ;
} while ( V_84 & V_192 );
return V_194 - V_193 ;
}
static int F_73 ( struct V_3 * V_4 , char * V_193 , unsigned int V_164 , T_1 V_84 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
char * V_194 = V_193 ;
do {
unsigned int V_196 , V_199 ;
V_199 = V_84 & V_200 ?
V_28 -> V_111 : V_28 -> V_100 ;
V_196 = F_74 ( V_164 , V_199 ) ;
F_75 ( V_8 + V_94 , V_194 , ( V_196 + 3 ) >> 2 ) ;
V_194 += V_196 ;
V_164 -= V_196 ;
if ( V_164 == 0 )
break;
V_84 = F_6 ( V_8 + V_9 ) ;
} while ( V_84 & V_201 );
return V_194 - V_193 ;
}
static T_4 F_76 ( int V_202 , void * V_203 )
{
struct V_3 * V_4 = V_203 ;
struct V_204 * V_62 = & V_4 -> V_62 ;
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
unsigned long V_5 ;
T_1 V_84 ;
V_84 = F_6 ( V_8 + V_9 ) ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_13 , V_84 ) ;
F_77 ( V_5 ) ;
do {
unsigned int V_164 , V_205 ;
char * V_193 ;
if ( ! ( V_84 & ( V_201 | V_192 ) ) )
break;
if ( ! F_78 ( V_62 ) )
break;
V_193 = V_62 -> V_206 ;
V_164 = V_62 -> V_207 ;
V_205 = 0 ;
if ( V_84 & V_208 )
V_205 = F_70 ( V_4 , V_193 , V_164 ) ;
if ( V_84 & V_209 )
V_205 = F_73 ( V_4 , V_193 , V_164 , V_84 ) ;
V_62 -> V_210 = V_205 ;
V_4 -> V_128 -= V_205 ;
V_164 -= V_205 ;
if ( V_164 )
break;
V_84 = F_6 ( V_8 + V_9 ) ;
} while ( 1 );
F_79 ( V_62 ) ;
F_80 ( V_5 ) ;
if ( V_84 & V_208 && V_4 -> V_128 < V_28 -> V_100 )
F_25 ( V_4 , V_86 ) ;
if ( V_4 -> V_128 == 0 ) {
F_25 ( V_4 , 0 ) ;
F_17 ( F_6 ( V_8 + V_55 ) | V_119 , V_8 + V_55 ) ;
}
return V_211 ;
}
static T_4 F_81 ( int V_202 , void * V_203 )
{
struct V_3 * V_4 = V_203 ;
T_1 V_84 ;
int V_117 = 0 ;
F_82 ( & V_4 -> V_7 ) ;
do {
V_84 = F_6 ( V_4 -> V_8 + V_9 ) ;
if ( V_4 -> V_53 ) {
if ( V_84 & F_6 ( V_4 -> V_8 + V_57 ) )
F_76 ( V_202 , V_203 ) ;
V_84 &= ~ V_56 ;
}
V_84 &= F_6 ( V_4 -> V_8 + V_55 ) ;
F_17 ( V_84 , V_4 -> V_8 + V_212 ) ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_14 , V_84 ) ;
if ( V_4 -> V_28 -> V_213 ) {
F_64 ( V_4 , V_4 -> V_12 , V_84 ) ;
F_67 ( V_4 , V_4 -> V_51 , V_84 ) ;
} else {
F_67 ( V_4 , V_4 -> V_51 , V_84 ) ;
F_64 ( V_4 , V_4 -> V_12 , V_84 ) ;
}
if ( V_4 -> V_177 )
V_84 &= ~ V_10 ;
V_117 = 1 ;
} while ( V_84 );
F_83 ( & V_4 -> V_7 ) ;
return F_84 ( V_117 ) ;
}
static void F_85 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_54 ( V_4 -> V_49 != NULL ) ;
V_49 -> V_51 -> error = F_10 ( V_4 , V_49 -> V_12 ) ;
if ( V_49 -> V_51 -> error ) {
F_24 ( V_2 , V_49 ) ;
return;
}
F_3 ( F_4 ( V_2 ) ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
V_4 -> V_49 = V_49 ;
if ( V_49 -> V_12 )
F_53 ( V_4 , V_49 -> V_12 ) ;
if ( V_49 -> V_12 && V_49 -> V_12 -> V_5 & V_59 )
F_57 ( V_4 , V_49 -> V_12 ) ;
if ( V_49 -> V_173 )
F_62 ( V_4 , V_49 -> V_173 , 0 ) ;
else
F_62 ( V_4 , V_49 -> V_51 , 0 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_86 ( struct V_1 * V_2 , struct V_214 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_4 -> V_28 ;
T_1 V_19 = 0 ;
unsigned long V_5 ;
int V_117 ;
F_3 ( F_4 ( V_2 ) ) ;
if ( V_4 -> V_215 -> V_216 &&
V_4 -> V_215 -> V_216 ( F_4 ( V_2 ) , V_38 ) )
F_12 ( F_4 ( V_2 ) , L_15 ) ;
switch ( V_38 -> V_217 ) {
case V_218 :
if ( ! F_87 ( V_2 -> V_219 . V_220 ) )
F_88 ( V_2 , V_2 -> V_219 . V_220 , 0 ) ;
if ( ! F_87 ( V_2 -> V_219 . V_221 ) && V_4 -> V_222 ) {
F_89 ( V_2 -> V_219 . V_221 ) ;
V_4 -> V_222 = false ;
}
break;
case V_223 :
if ( ! F_87 ( V_2 -> V_219 . V_220 ) )
F_88 ( V_2 , V_2 -> V_219 . V_220 , V_38 -> V_224 ) ;
V_19 |= V_28 -> V_225 ;
break;
case V_226 :
if ( ! F_87 ( V_2 -> V_219 . V_221 ) && ! V_4 -> V_222 ) {
V_117 = F_90 ( V_2 -> V_219 . V_221 ) ;
if ( V_117 < 0 )
F_12 ( F_4 ( V_2 ) ,
L_16 ) ;
else
V_4 -> V_222 = true ;
}
V_19 |= V_227 ;
break;
}
if ( V_28 -> V_228 && V_38 -> V_217 != V_218 ) {
V_19 |= V_4 -> V_229 ;
if ( V_38 -> V_39 == V_40 )
V_19 &= ~ V_230 ;
else if ( V_38 -> V_39 == V_231 )
V_19 &= ( ~ V_230 &
~ V_232 &
~ V_233 ) ;
}
if ( V_38 -> V_234 == V_235 ) {
if ( V_4 -> V_236 != V_237 )
V_19 |= V_238 ;
else {
V_19 |= V_239 ;
}
}
if ( ! V_38 -> clock && V_28 -> V_240 )
V_19 &= ~ V_227 ;
if ( V_4 -> V_28 -> V_30 &&
V_38 -> clock != V_4 -> V_241 ) {
V_117 = F_91 ( V_4 -> V_16 , V_38 -> clock ) ;
if ( V_117 < 0 )
F_12 ( F_4 ( V_4 -> V_2 ) ,
L_17 , V_117 ) ;
else
V_4 -> V_31 = F_92 ( V_4 -> V_16 ) ;
}
V_4 -> V_241 = V_38 -> clock ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_20 ( V_4 , V_38 -> clock ) ;
F_18 ( V_4 , V_19 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_242 * V_215 = V_4 -> V_215 ;
unsigned int V_84 = F_94 ( V_2 ) ;
if ( V_84 == - V_123 ) {
if ( ! V_215 -> V_84 )
return 1 ;
V_84 = V_215 -> V_84 ( F_4 ( V_4 -> V_2 ) ) ;
}
return V_84 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_214 * V_38 )
{
int V_117 = 0 ;
if ( ! F_87 ( V_2 -> V_219 . V_221 ) ) {
F_3 ( F_4 ( V_2 ) ) ;
switch ( V_38 -> V_243 ) {
case V_244 :
V_117 = F_96 ( V_2 -> V_219 . V_221 ,
2700000 , 3600000 ) ;
break;
case V_245 :
V_117 = F_96 ( V_2 -> V_219 . V_221 ,
1700000 , 1950000 ) ;
break;
case V_246 :
V_117 = F_96 ( V_2 -> V_219 . V_221 ,
1100000 , 1300000 ) ;
break;
}
if ( V_117 )
F_97 ( F_4 ( V_2 ) , L_18 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
}
return V_117 ;
}
static int F_98 ( struct V_247 * V_248 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_117 = F_99 ( V_2 ) ;
if ( V_117 )
return V_117 ;
if ( F_100 ( V_248 , L_19 , NULL ) )
V_4 -> V_229 |= V_249 ;
if ( F_100 ( V_248 , L_20 , NULL ) )
V_4 -> V_229 |= V_233 ;
if ( F_100 ( V_248 , L_21 , NULL ) )
V_4 -> V_229 |= V_232 ;
if ( F_100 ( V_248 , L_22 , NULL ) )
V_4 -> V_229 |= V_230 ;
if ( F_100 ( V_248 , L_23 , NULL ) )
V_4 -> V_229 |= V_250 ;
if ( F_100 ( V_248 , L_24 , NULL ) )
V_4 -> V_229 |= V_251 ;
if ( F_100 ( V_248 , L_25 , NULL ) )
V_2 -> V_252 |= V_253 ;
if ( F_100 ( V_248 , L_26 , NULL ) )
V_2 -> V_252 |= V_254 ;
return 0 ;
}
static int F_101 ( struct V_255 * V_73 ,
const struct V_256 * V_257 )
{
struct V_242 * V_215 = V_73 -> V_73 . V_258 ;
struct V_247 * V_248 = V_73 -> V_73 . V_259 ;
struct V_27 * V_28 = V_257 -> V_12 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_117 ;
if ( ! V_215 && ! V_248 ) {
F_12 ( & V_73 -> V_73 , L_27 ) ;
return - V_14 ;
}
if ( ! V_215 ) {
V_215 = F_102 ( & V_73 -> V_73 , sizeof( * V_215 ) , V_260 ) ;
if ( ! V_215 )
return - V_114 ;
}
V_2 = F_103 ( sizeof( struct V_3 ) , & V_73 -> V_73 ) ;
if ( ! V_2 )
return - V_114 ;
V_117 = F_98 ( V_248 , V_2 ) ;
if ( V_117 )
goto V_261;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_236 = F_104 ( V_73 ) ;
V_4 -> V_262 = F_105 ( V_73 ) ;
F_58 ( F_4 ( V_2 ) , L_28 , V_4 -> V_236 ) ;
F_58 ( F_4 ( V_2 ) , L_29 , V_4 -> V_262 ) ;
V_4 -> V_16 = F_106 ( & V_73 -> V_73 , NULL ) ;
if ( F_87 ( V_4 -> V_16 ) ) {
V_117 = F_107 ( V_4 -> V_16 ) ;
goto V_261;
}
V_117 = F_108 ( V_4 -> V_16 ) ;
if ( V_117 )
goto V_261;
if ( V_28 -> V_263 )
V_4 -> V_197 = F_69 ;
else
V_4 -> V_197 = F_68 ;
V_4 -> V_215 = V_215 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_31 = F_92 ( V_4 -> V_16 ) ;
if ( V_4 -> V_31 > V_28 -> V_264 ) {
V_117 = F_91 ( V_4 -> V_16 , V_28 -> V_264 ) ;
if ( V_117 < 0 )
goto V_265;
V_4 -> V_31 = F_92 ( V_4 -> V_16 ) ;
F_58 ( F_4 ( V_2 ) , L_30 ,
V_4 -> V_31 ) ;
}
V_4 -> V_93 = V_73 -> V_266 . V_267 ;
V_4 -> V_8 = F_109 ( & V_73 -> V_73 , & V_73 -> V_266 ) ;
if ( F_87 ( V_4 -> V_8 ) ) {
V_117 = F_107 ( V_4 -> V_8 ) ;
goto V_265;
}
if ( V_28 -> V_33 )
V_2 -> V_268 = F_21 ( V_4 -> V_31 , 257 ) ;
else if ( V_28 -> V_30 )
V_2 -> V_268 = F_110 ( V_4 -> V_16 , 100000 ) ;
else
V_2 -> V_268 = F_21 ( V_4 -> V_31 , 512 ) ;
if ( V_2 -> V_264 )
V_2 -> V_264 = V_28 -> V_30 ?
F_74 ( V_28 -> V_264 , V_2 -> V_264 ) :
F_74 ( V_4 -> V_31 , V_2 -> V_264 ) ;
else
V_2 -> V_264 = V_28 -> V_30 ?
V_269 : F_74 ( V_4 -> V_31 , V_269 ) ;
F_58 ( F_4 ( V_2 ) , L_31 , V_2 -> V_264 ) ;
F_111 ( V_2 ) ;
if ( ! V_2 -> V_270 )
V_2 -> V_270 = V_215 -> V_271 ;
else if ( V_215 -> V_271 )
F_97 ( F_4 ( V_2 ) , L_32 ) ;
if ( ! V_248 ) {
if ( ! V_215 -> V_272 )
V_2 -> V_273 |= V_274 ;
V_2 -> V_273 |= V_275 ;
}
V_2 -> V_252 |= V_276 ;
if ( V_28 -> V_175 ) {
V_277 . V_278 = F_1 ;
F_19 ( V_4 , V_24 ) ;
V_2 -> V_252 |= V_279 ;
V_2 -> V_280 = 0 ;
}
V_2 -> V_281 = & V_277 ;
V_2 -> V_282 |= V_283 ;
V_2 -> V_284 = V_285 ;
V_2 -> V_286 = ( 1 << V_28 -> V_287 ) - 1 ;
V_2 -> V_74 = V_2 -> V_286 ;
V_2 -> V_288 = 1 << 11 ;
V_2 -> V_289 = V_2 -> V_286 >> 11 ;
F_112 ( & V_4 -> V_7 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
F_17 ( 0 , V_4 -> V_8 + V_57 ) ;
F_17 ( 0xfff , V_4 -> V_8 + V_212 ) ;
if ( ! V_248 && F_113 ( V_215 -> V_290 ) ) {
V_117 = F_114 ( V_2 , V_215 -> V_290 , 0 ) ;
if ( V_117 )
goto V_265;
}
if ( ! V_248 && F_113 ( V_215 -> V_291 ) ) {
V_117 = F_115 ( V_2 , V_215 -> V_291 ) ;
if ( V_117 )
goto V_265;
}
V_117 = F_116 ( & V_73 -> V_73 , V_73 -> V_202 [ 0 ] , F_81 , V_292 ,
V_293 L_33 , V_4 ) ;
if ( V_117 )
goto V_265;
if ( ! V_73 -> V_202 [ 1 ] )
V_4 -> V_53 = true ;
else {
V_117 = F_116 ( & V_73 -> V_73 , V_73 -> V_202 [ 1 ] , F_76 ,
V_292 , V_293 L_34 , V_4 ) ;
if ( V_117 )
goto V_265;
}
F_17 ( V_294 , V_4 -> V_8 + V_55 ) ;
F_117 ( V_73 , V_2 ) ;
F_34 ( & V_73 -> V_73 , L_35 ,
F_118 ( V_2 ) , F_119 ( V_73 ) , F_104 ( V_73 ) ,
F_105 ( V_73 ) , ( unsigned long long ) V_73 -> V_266 . V_267 ,
V_73 -> V_202 [ 0 ] , V_73 -> V_202 [ 1 ] ) ;
F_29 ( V_4 ) ;
F_120 ( & V_73 -> V_73 , 50 ) ;
F_121 ( & V_73 -> V_73 ) ;
F_122 ( & V_73 -> V_73 ) ;
F_123 ( V_2 ) ;
return 0 ;
V_265:
F_124 ( V_4 -> V_16 ) ;
V_261:
F_125 ( V_2 ) ;
return V_117 ;
}
static int F_126 ( struct V_255 * V_73 )
{
struct V_1 * V_2 = F_127 ( V_73 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_73 -> V_73 ) ;
F_128 ( V_2 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
F_17 ( 0 , V_4 -> V_8 + V_57 ) ;
F_17 ( 0 , V_4 -> V_8 + V_50 ) ;
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_36 ( V_4 ) ;
F_124 ( V_4 -> V_16 ) ;
F_125 ( V_2 ) ;
}
return 0 ;
}
static void F_129 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
if ( V_4 -> V_28 -> V_295 ) {
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_17 ( 0 , V_4 -> V_8 + V_21 ) ;
F_17 ( 0 , V_4 -> V_8 + V_18 ) ;
}
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_130 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
if ( V_4 -> V_28 -> V_295 ) {
F_17 ( V_4 -> V_17 , V_4 -> V_8 + V_18 ) ;
F_17 ( V_4 -> V_23 , V_4 -> V_8 + V_25 ) ;
F_17 ( V_4 -> V_20 , V_4 -> V_8 + V_21 ) ;
}
F_17 ( V_294 , V_4 -> V_8 + V_55 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static int F_131 ( struct V_72 * V_73 )
{
struct V_255 * V_296 = F_132 ( V_73 ) ;
struct V_1 * V_2 = F_127 ( V_296 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_133 ( V_73 ) ;
F_129 ( V_4 ) ;
F_124 ( V_4 -> V_16 ) ;
}
return 0 ;
}
static int F_134 ( struct V_72 * V_73 )
{
struct V_255 * V_296 = F_132 ( V_73 ) ;
struct V_1 * V_2 = F_127 ( V_296 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_108 ( V_4 -> V_16 ) ;
F_130 ( V_4 ) ;
F_135 ( V_73 ) ;
}
return 0 ;
}
