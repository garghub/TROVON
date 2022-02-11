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
struct V_27 * V_28 = V_4 -> V_28 ;
V_4 -> V_67 = F_30 ( F_4 ( V_4 -> V_2 ) , L_2 ) ;
V_4 -> V_68 = F_30 ( F_4 ( V_4 -> V_2 ) , L_3 ) ;
V_4 -> V_69 . V_70 = 1 ;
if ( V_4 -> V_67 && ! V_4 -> V_68 )
V_4 -> V_68 = V_4 -> V_67 ;
if ( V_4 -> V_67 )
V_65 = F_31 ( V_4 -> V_67 ) ;
else
V_65 = L_4 ;
if ( V_4 -> V_68 )
V_66 = F_31 ( V_4 -> V_68 ) ;
else
V_66 = L_4 ;
F_32 ( F_4 ( V_4 -> V_2 ) , L_5 ,
V_65 , V_66 ) ;
if ( V_4 -> V_68 ) {
struct V_71 * V_72 = V_4 -> V_68 -> V_71 -> V_72 ;
unsigned int V_73 = F_33 ( V_72 ) ;
if ( V_73 < V_4 -> V_2 -> V_73 )
V_4 -> V_2 -> V_73 = V_73 ;
}
if ( V_4 -> V_67 ) {
struct V_71 * V_72 = V_4 -> V_67 -> V_71 -> V_72 ;
unsigned int V_73 = F_33 ( V_72 ) ;
if ( V_73 < V_4 -> V_2 -> V_73 )
V_4 -> V_2 -> V_73 = V_73 ;
}
if ( V_28 -> V_74 && V_4 -> V_67 && V_4 -> V_68 )
if ( F_34 ( V_4 , V_4 -> V_2 -> V_75 -> V_76 ) )
V_28 -> V_74 = false ;
}
static inline void F_35 ( struct V_3 * V_4 )
{
if ( V_4 -> V_67 )
F_36 ( V_4 -> V_67 ) ;
if ( V_4 -> V_68 )
F_36 ( V_4 -> V_68 ) ;
V_4 -> V_67 = V_4 -> V_68 = NULL ;
}
static void F_37 ( struct V_3 * V_4 )
{
F_12 ( F_4 ( V_4 -> V_2 ) , L_6 ) ;
F_38 ( V_4 -> V_77 ) ;
V_4 -> V_77 = NULL ;
V_4 -> V_78 = NULL ;
V_4 -> V_12 -> V_79 = 0 ;
}
static void F_39 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_80 * V_81 ;
enum V_82 V_83 ;
if ( V_12 -> V_5 & V_59 ) {
V_83 = V_84 ;
V_81 = V_4 -> V_67 ;
} else {
V_83 = V_85 ;
V_81 = V_4 -> V_68 ;
}
F_40 ( V_81 -> V_71 -> V_72 , V_12 -> V_63 , V_12 -> V_64 , V_83 ) ;
}
static void F_41 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
T_1 V_86 ;
int V_87 ;
for ( V_87 = 0 ; ; V_87 ++ ) {
V_86 = F_6 ( V_4 -> V_8 + V_9 ) ;
if ( ! ( V_86 & V_88 ) || V_87 >= 100 )
break;
F_14 ( 10 ) ;
}
if ( V_86 & V_88 ) {
F_37 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> error = - V_89 ;
}
if ( ! V_12 -> V_79 )
F_39 ( V_4 , V_12 ) ;
if ( V_86 & V_88 ) {
F_12 ( F_4 ( V_4 -> V_2 ) , L_7 ) ;
F_35 ( V_4 ) ;
}
V_4 -> V_77 = NULL ;
V_4 -> V_78 = NULL ;
}
static int F_42 ( struct V_3 * V_4 , struct V_11 * V_12 ,
struct V_80 * * V_80 ,
struct V_90 * * V_91 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_92 V_93 = {
. V_94 = V_4 -> V_95 + V_96 ,
. V_97 = V_4 -> V_95 + V_96 ,
. V_98 = V_99 ,
. V_100 = V_99 ,
. V_101 = V_28 -> V_102 >> 2 ,
. V_103 = V_28 -> V_102 >> 2 ,
. V_104 = false ,
} ;
struct V_80 * V_81 ;
struct V_105 * V_71 ;
struct V_90 * V_106 ;
enum V_82 V_107 ;
int V_108 ;
unsigned long V_5 = V_109 ;
if ( V_12 -> V_5 & V_59 ) {
V_93 . V_110 = V_111 ;
V_107 = V_84 ;
V_81 = V_4 -> V_67 ;
} else {
V_93 . V_110 = V_112 ;
V_107 = V_85 ;
V_81 = V_4 -> V_68 ;
}
if ( ! V_81 )
return - V_14 ;
if ( V_12 -> V_13 * V_12 -> V_113 <= V_28 -> V_114 )
return - V_14 ;
V_71 = V_81 -> V_71 ;
V_108 = F_43 ( V_71 -> V_72 , V_12 -> V_63 , V_12 -> V_64 , V_107 ) ;
if ( V_108 == 0 )
return - V_14 ;
if ( V_4 -> V_28 -> V_74 )
V_5 |= V_115 ;
F_44 ( V_81 , & V_93 ) ;
V_106 = F_45 ( V_81 , V_12 -> V_63 , V_108 ,
V_93 . V_110 , V_5 ) ;
if ( ! V_106 )
goto V_116;
* V_80 = V_81 ;
* V_91 = V_106 ;
return 0 ;
V_116:
F_40 ( V_71 -> V_72 , V_12 -> V_63 , V_12 -> V_64 , V_107 ) ;
return - V_117 ;
}
static inline int F_46 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
if ( V_4 -> V_77 && V_4 -> V_78 )
return 0 ;
return F_42 ( V_4 , V_12 , & V_4 -> V_77 ,
& V_4 -> V_78 ) ;
}
static inline int F_47 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_118 * V_119 = & V_4 -> V_69 ;
return F_42 ( V_4 , V_12 , & V_119 -> V_80 , & V_119 -> V_91 ) ;
}
static int F_48 ( struct V_3 * V_4 , unsigned int V_22 )
{
int V_120 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_120 = F_46 ( V_4 , V_4 -> V_12 ) ;
if ( V_120 )
return V_120 ;
F_49 ( F_4 ( V_4 -> V_2 ) ,
L_8 ,
V_12 -> V_64 , V_12 -> V_13 , V_12 -> V_113 , V_12 -> V_5 ) ;
F_50 ( V_4 -> V_78 ) ;
F_51 ( V_4 -> V_77 ) ;
if ( V_4 -> V_28 -> V_74 )
F_52 ( V_4 , V_12 ) ;
V_22 |= V_121 ;
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_4 -> V_8 + V_55 ) | V_122 ,
V_4 -> V_8 + V_55 ) ;
return 0 ;
}
static void F_53 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_118 * V_123 = & V_4 -> V_69 ;
F_54 ( V_12 -> V_79 && V_12 -> V_79 != V_123 -> V_70 ) ;
F_54 ( ! V_12 -> V_79 && ( V_123 -> V_91 || V_123 -> V_80 ) ) ;
V_4 -> V_78 = V_123 -> V_91 ;
V_4 -> V_77 = V_123 -> V_80 ;
V_123 -> V_91 = NULL ;
V_123 -> V_80 = NULL ;
}
static void F_55 ( struct V_1 * V_2 , struct V_48 * V_49 ,
bool V_124 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_49 -> V_12 ;
struct V_118 * V_119 = & V_4 -> V_69 ;
if ( ! V_12 )
return;
F_23 ( V_12 -> V_79 ) ;
if ( F_10 ( V_4 , V_12 ) )
return;
if ( ! F_47 ( V_4 , V_12 ) )
V_12 -> V_79 = ++ V_119 -> V_70 < 0 ? 1 : V_119 -> V_70 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_48 * V_49 ,
int V_125 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_49 -> V_12 ;
if ( ! V_12 || ! V_12 -> V_79 )
return;
F_39 ( V_4 , V_12 ) ;
if ( V_125 ) {
struct V_118 * V_123 = & V_4 -> V_69 ;
struct V_80 * V_81 ;
if ( V_12 -> V_5 & V_59 )
V_81 = V_4 -> V_67 ;
else
V_81 = V_4 -> V_68 ;
F_38 ( V_81 ) ;
if ( V_4 -> V_78 == V_123 -> V_91 )
V_4 -> V_78 = NULL ;
if ( V_4 -> V_77 == V_123 -> V_80 )
V_4 -> V_77 = NULL ;
V_123 -> V_91 = NULL ;
V_123 -> V_80 = NULL ;
V_12 -> V_79 = 0 ;
}
}
static void F_53 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
}
static inline void F_29 ( struct V_3 * V_4 )
{
}
static inline void F_35 ( struct V_3 * V_4 )
{
}
static inline void F_39 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
}
static inline void F_41 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
}
static inline void F_37 ( struct V_3 * V_4 )
{
}
static inline int F_48 ( struct V_3 * V_4 , unsigned int V_22 )
{
return - V_126 ;
}
static void F_57 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
unsigned int V_22 , V_127 , V_128 ;
unsigned long long V_129 ;
void T_2 * V_8 ;
int V_130 ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_9 ,
V_12 -> V_13 , V_12 -> V_113 , V_12 -> V_5 ) ;
V_4 -> V_12 = V_12 ;
V_4 -> V_131 = V_12 -> V_13 * V_12 -> V_113 ;
V_12 -> V_132 = 0 ;
V_129 = ( unsigned long long ) V_12 -> V_133 * V_4 -> V_15 ;
F_59 ( V_129 , V_134 ) ;
V_127 = V_12 -> V_135 + ( unsigned int ) V_129 ;
V_8 = V_4 -> V_8 ;
F_17 ( V_127 , V_8 + V_136 ) ;
F_17 ( V_4 -> V_131 , V_8 + V_137 ) ;
V_130 = F_60 ( V_12 -> V_13 ) - 1 ;
F_23 ( 1 << V_130 != V_12 -> V_13 ) ;
if ( V_28 -> V_138 )
V_22 = V_139 | ( V_12 -> V_13 << 16 ) ;
else if ( V_28 -> V_140 )
V_22 = V_139 | ( V_12 -> V_13 << 4 ) ;
else
V_22 = V_139 | V_130 << 4 ;
if ( V_12 -> V_5 & V_59 )
V_22 |= V_141 ;
if ( V_4 -> V_2 -> V_142 && F_61 ( V_4 -> V_2 -> V_142 ) ) {
T_1 V_16 ;
V_22 |= V_28 -> V_143 ;
if ( V_28 -> V_144 && V_12 -> V_5 & V_145 &&
( V_4 -> V_131 < 8 ||
( V_4 -> V_131 <= 8 && V_4 -> V_31 > 50000000 ) ) )
V_16 = V_4 -> V_17 & ~ V_28 -> V_35 ;
else
V_16 = V_4 -> V_17 | V_28 -> V_35 ;
F_16 ( V_4 , V_16 ) ;
}
if ( V_4 -> V_2 -> V_38 . V_44 == V_45 ||
V_4 -> V_2 -> V_38 . V_44 == V_46 )
V_22 |= V_28 -> V_146 ;
if ( ! F_48 ( V_4 , V_22 ) )
return;
F_27 ( V_4 , V_12 ) ;
if ( V_12 -> V_5 & V_59 ) {
V_128 = V_147 ;
if ( V_4 -> V_131 < V_28 -> V_102 )
V_128 |= V_88 ;
} else {
V_128 = V_148 ;
}
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_8 + V_55 ) & ~ V_122 , V_8 + V_55 ) ;
F_25 ( V_4 , V_128 ) ;
}
static void
F_62 ( struct V_3 * V_4 , struct V_149 * V_51 , T_1 V_150 )
{
void T_2 * V_8 = V_4 -> V_8 ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_10 ,
V_51 -> V_151 , V_51 -> V_152 , V_51 -> V_5 ) ;
if ( F_6 ( V_8 + V_50 ) & V_153 ) {
F_17 ( 0 , V_8 + V_50 ) ;
F_13 ( V_4 ) ;
}
V_150 |= V_51 -> V_151 | V_153 ;
if ( V_51 -> V_5 & V_154 ) {
if ( V_51 -> V_5 & V_155 )
V_150 |= V_156 ;
V_150 |= V_157 ;
}
if ( 0 )
V_150 |= V_158 ;
if ( F_63 ( V_51 ) == V_159 )
V_150 |= V_4 -> V_28 -> V_160 ;
V_4 -> V_51 = V_51 ;
F_17 ( V_51 -> V_152 , V_8 + V_161 ) ;
F_17 ( V_150 , V_8 + V_50 ) ;
}
static void
F_64 ( struct V_3 * V_4 , struct V_11 * V_12 ,
unsigned int V_86 )
{
if ( ! V_12 )
return;
if ( V_86 & ( V_162 | V_163 | V_164 |
V_165 | V_166 ) ) {
T_1 V_167 , V_168 ;
if ( F_65 ( V_4 ) ) {
F_37 ( V_4 ) ;
F_39 ( V_4 , V_12 ) ;
}
V_167 = F_6 ( V_4 -> V_8 + V_169 ) ;
V_168 = V_12 -> V_13 * V_12 -> V_113 - V_167 ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_11 ,
V_86 , V_168 ) ;
if ( V_86 & V_162 ) {
V_168 -= 1 ;
V_12 -> error = - V_170 ;
} else if ( V_86 & V_163 ) {
V_12 -> error = - V_171 ;
} else if ( V_86 & V_164 ) {
V_12 -> error = - V_172 ;
} else if ( V_86 & V_165 ) {
V_12 -> error = - V_89 ;
} else if ( V_86 & V_166 ) {
if ( V_168 > V_4 -> V_28 -> V_114 )
V_168 -= V_4 -> V_28 -> V_114 ;
else
V_168 = 0 ;
V_12 -> error = - V_89 ;
}
V_12 -> V_132 = F_66 ( V_168 , V_12 -> V_13 ) ;
}
if ( V_86 & V_173 )
F_12 ( F_4 ( V_4 -> V_2 ) , L_12 ) ;
if ( V_86 & V_174 || V_12 -> error ) {
if ( F_65 ( V_4 ) )
F_41 ( V_4 , V_12 ) ;
F_26 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> V_132 = V_12 -> V_13 * V_12 -> V_113 ;
if ( ! V_12 -> V_175 || V_4 -> V_49 -> V_176 ) {
F_22 ( V_4 , V_12 -> V_49 ) ;
} else {
F_62 ( V_4 , V_12 -> V_175 , 0 ) ;
}
}
}
static void
F_67 ( struct V_3 * V_4 , struct V_149 * V_51 ,
unsigned int V_86 )
{
void T_2 * V_8 = V_4 -> V_8 ;
bool V_176 , V_177 ;
if ( ! V_51 )
return;
V_176 = ( V_51 == V_4 -> V_49 -> V_176 ) ;
V_177 = V_4 -> V_28 -> V_178 && ( V_51 -> V_5 & V_179 ) ;
if ( ! ( ( V_86 | V_4 -> V_180 ) & ( V_181 | V_182 |
V_183 | V_184 ) ) )
return;
if ( V_4 -> V_180 && ( V_86 & V_10 ) )
return;
if ( ! V_4 -> V_180 && V_177 &&
! ( V_86 & ( V_181 | V_182 ) ) &&
( F_6 ( V_8 + V_9 ) & V_10 ) ) {
F_17 ( F_6 ( V_8 + V_55 ) | V_185 ,
V_8 + V_55 ) ;
V_4 -> V_180 = V_86 & ( V_183 | V_184 ) ;
return;
}
if ( V_4 -> V_180 ) {
F_17 ( F_6 ( V_8 + V_55 ) & ~ V_185 ,
V_8 + V_55 ) ;
V_4 -> V_180 = 0 ;
}
V_4 -> V_51 = NULL ;
if ( V_86 & V_182 ) {
V_51 -> error = - V_171 ;
} else if ( V_86 & V_181 && V_51 -> V_5 & V_186 ) {
V_51 -> error = - V_170 ;
} else {
V_51 -> V_187 [ 0 ] = F_6 ( V_8 + V_188 ) ;
V_51 -> V_187 [ 1 ] = F_6 ( V_8 + V_189 ) ;
V_51 -> V_187 [ 2 ] = F_6 ( V_8 + V_190 ) ;
V_51 -> V_187 [ 3 ] = F_6 ( V_8 + V_191 ) ;
}
if ( ( ! V_176 && ! V_51 -> V_12 ) || V_51 -> error ) {
if ( V_4 -> V_12 ) {
if ( F_65 ( V_4 ) ) {
F_37 ( V_4 ) ;
F_39 ( V_4 , V_4 -> V_12 ) ;
}
F_26 ( V_4 ) ;
}
F_22 ( V_4 , V_4 -> V_49 ) ;
} else if ( V_176 ) {
F_62 ( V_4 , V_4 -> V_49 -> V_51 , 0 ) ;
} else if ( ! ( V_51 -> V_12 -> V_5 & V_59 ) ) {
F_57 ( V_4 , V_51 -> V_12 ) ;
}
}
static int F_68 ( struct V_3 * V_4 , T_1 V_86 , int V_167 )
{
return V_167 - ( F_6 ( V_4 -> V_8 + V_192 ) << 2 ) ;
}
static int F_69 ( struct V_3 * V_4 , T_1 V_86 , int V_193 )
{
if ( V_86 & V_194 )
return V_4 -> V_28 -> V_102 ;
else if ( V_86 & V_195 )
return 4 ;
return 0 ;
}
static int F_70 ( struct V_3 * V_4 , char * V_196 , unsigned int V_167 )
{
void T_2 * V_8 = V_4 -> V_8 ;
char * V_197 = V_196 ;
T_1 V_86 = F_6 ( V_4 -> V_8 + V_9 ) ;
int V_198 = V_4 -> V_131 ;
do {
int V_199 = V_4 -> V_200 ( V_4 , V_86 , V_198 ) ;
if ( V_199 > V_167 )
V_199 = V_167 ;
if ( V_199 <= 0 )
break;
if ( F_71 ( V_199 & 0x3 ) ) {
if ( V_199 < 4 ) {
unsigned char V_201 [ 4 ] ;
F_72 ( V_8 + V_96 , V_201 , 1 ) ;
memcpy ( V_197 , V_201 , V_199 ) ;
} else {
F_72 ( V_8 + V_96 , V_197 , V_199 >> 2 ) ;
V_199 &= ~ 0x3 ;
}
} else {
F_72 ( V_8 + V_96 , V_197 , V_199 >> 2 ) ;
}
V_197 += V_199 ;
V_167 -= V_199 ;
V_198 -= V_199 ;
if ( V_167 == 0 )
break;
V_86 = F_6 ( V_8 + V_9 ) ;
} while ( V_86 & V_195 );
return V_197 - V_196 ;
}
static int F_73 ( struct V_3 * V_4 , char * V_196 , unsigned int V_167 , T_1 V_86 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
char * V_197 = V_196 ;
do {
unsigned int V_199 , V_202 ;
V_202 = V_86 & V_203 ?
V_28 -> V_114 : V_28 -> V_102 ;
V_199 = F_74 ( V_167 , V_202 ) ;
F_75 ( V_8 + V_96 , V_197 , ( V_199 + 3 ) >> 2 ) ;
V_197 += V_199 ;
V_167 -= V_199 ;
if ( V_167 == 0 )
break;
V_86 = F_6 ( V_8 + V_9 ) ;
} while ( V_86 & V_204 );
return V_197 - V_196 ;
}
static T_3 F_76 ( int V_205 , void * V_206 )
{
struct V_3 * V_4 = V_206 ;
struct V_207 * V_62 = & V_4 -> V_62 ;
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
unsigned long V_5 ;
T_1 V_86 ;
V_86 = F_6 ( V_8 + V_9 ) ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_13 , V_86 ) ;
F_77 ( V_5 ) ;
do {
unsigned int V_167 , V_208 ;
char * V_196 ;
if ( ! ( V_86 & ( V_204 | V_195 ) ) )
break;
if ( ! F_78 ( V_62 ) )
break;
V_196 = V_62 -> V_209 ;
V_167 = V_62 -> V_210 ;
V_208 = 0 ;
if ( V_86 & V_211 )
V_208 = F_70 ( V_4 , V_196 , V_167 ) ;
if ( V_86 & V_212 )
V_208 = F_73 ( V_4 , V_196 , V_167 , V_86 ) ;
V_62 -> V_213 = V_208 ;
V_4 -> V_131 -= V_208 ;
V_167 -= V_208 ;
if ( V_167 )
break;
V_86 = F_6 ( V_8 + V_9 ) ;
} while ( 1 );
F_79 ( V_62 ) ;
F_80 ( V_5 ) ;
if ( V_86 & V_211 && V_4 -> V_131 < V_28 -> V_102 )
F_25 ( V_4 , V_88 ) ;
if ( V_4 -> V_131 == 0 ) {
F_25 ( V_4 , 0 ) ;
F_17 ( F_6 ( V_8 + V_55 ) | V_122 , V_8 + V_55 ) ;
}
return V_214 ;
}
static T_3 F_81 ( int V_205 , void * V_206 )
{
struct V_3 * V_4 = V_206 ;
T_1 V_86 ;
int V_120 = 0 ;
F_82 ( & V_4 -> V_7 ) ;
do {
V_86 = F_6 ( V_4 -> V_8 + V_9 ) ;
if ( V_4 -> V_53 ) {
if ( V_86 & F_6 ( V_4 -> V_8 + V_57 ) )
F_76 ( V_205 , V_206 ) ;
V_86 &= ~ V_56 ;
}
V_86 &= F_6 ( V_4 -> V_8 + V_55 ) ;
F_17 ( V_86 , V_4 -> V_8 + V_215 ) ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_14 , V_86 ) ;
if ( V_4 -> V_28 -> V_216 ) {
F_64 ( V_4 , V_4 -> V_12 , V_86 ) ;
F_67 ( V_4 , V_4 -> V_51 , V_86 ) ;
} else {
F_67 ( V_4 , V_4 -> V_51 , V_86 ) ;
F_64 ( V_4 , V_4 -> V_12 , V_86 ) ;
}
if ( V_4 -> V_180 )
V_86 &= ~ V_10 ;
V_120 = 1 ;
} while ( V_86 );
F_83 ( & V_4 -> V_7 ) ;
return F_84 ( V_120 ) ;
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
if ( V_49 -> V_176 )
F_62 ( V_4 , V_49 -> V_176 , 0 ) ;
else
F_62 ( V_4 , V_49 -> V_51 , 0 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_86 ( struct V_1 * V_2 , struct V_217 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_4 -> V_28 ;
T_1 V_19 = 0 ;
unsigned long V_5 ;
int V_120 ;
F_3 ( F_4 ( V_2 ) ) ;
if ( V_4 -> V_218 -> V_219 &&
V_4 -> V_218 -> V_219 ( F_4 ( V_2 ) , V_38 ) )
F_12 ( F_4 ( V_2 ) , L_15 ) ;
switch ( V_38 -> V_220 ) {
case V_221 :
if ( ! F_87 ( V_2 -> V_222 . V_223 ) )
F_88 ( V_2 , V_2 -> V_222 . V_223 , 0 ) ;
if ( ! F_87 ( V_2 -> V_222 . V_224 ) && V_4 -> V_225 ) {
F_89 ( V_2 -> V_222 . V_224 ) ;
V_4 -> V_225 = false ;
}
break;
case V_226 :
if ( ! F_87 ( V_2 -> V_222 . V_223 ) )
F_88 ( V_2 , V_2 -> V_222 . V_223 , V_38 -> V_227 ) ;
V_19 |= V_28 -> V_228 ;
break;
case V_229 :
if ( ! F_87 ( V_2 -> V_222 . V_224 ) && ! V_4 -> V_225 ) {
V_120 = F_90 ( V_2 -> V_222 . V_224 ) ;
if ( V_120 < 0 )
F_12 ( F_4 ( V_2 ) ,
L_16 ) ;
else
V_4 -> V_225 = true ;
}
V_19 |= V_230 ;
break;
}
if ( V_28 -> V_231 && V_38 -> V_220 != V_221 ) {
V_19 |= V_4 -> V_232 ;
if ( V_38 -> V_39 == V_40 )
V_19 &= ~ V_233 ;
else if ( V_38 -> V_39 == V_234 )
V_19 &= ( ~ V_233 &
~ V_235 &
~ V_236 ) ;
}
if ( V_38 -> V_237 == V_238 ) {
if ( V_4 -> V_239 != V_240 )
V_19 |= V_241 ;
else {
V_19 |= V_242 ;
}
}
if ( ! V_38 -> clock && V_28 -> V_243 )
V_19 &= ~ V_230 ;
if ( V_4 -> V_28 -> V_30 &&
V_38 -> clock != V_4 -> V_244 ) {
V_120 = F_91 ( V_4 -> V_16 , V_38 -> clock ) ;
if ( V_120 < 0 )
F_12 ( F_4 ( V_4 -> V_2 ) ,
L_17 , V_120 ) ;
else
V_4 -> V_31 = F_92 ( V_4 -> V_16 ) ;
}
V_4 -> V_244 = V_38 -> clock ;
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
struct V_245 * V_218 = V_4 -> V_218 ;
unsigned int V_86 = F_94 ( V_2 ) ;
if ( V_86 == - V_126 ) {
if ( ! V_218 -> V_86 )
return 1 ;
V_86 = V_218 -> V_86 ( F_4 ( V_4 -> V_2 ) ) ;
}
return V_86 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_217 * V_38 )
{
int V_120 = 0 ;
if ( ! F_87 ( V_2 -> V_222 . V_224 ) ) {
F_3 ( F_4 ( V_2 ) ) ;
switch ( V_38 -> V_246 ) {
case V_247 :
V_120 = F_96 ( V_2 -> V_222 . V_224 ,
2700000 , 3600000 ) ;
break;
case V_248 :
V_120 = F_96 ( V_2 -> V_222 . V_224 ,
1700000 , 1950000 ) ;
break;
case V_249 :
V_120 = F_96 ( V_2 -> V_222 . V_224 ,
1100000 , 1300000 ) ;
break;
}
if ( V_120 )
F_97 ( F_4 ( V_2 ) , L_18 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
}
return V_120 ;
}
static int F_98 ( struct V_250 * V_251 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_120 = F_99 ( V_2 ) ;
if ( V_120 )
return V_120 ;
if ( F_100 ( V_251 , L_19 , NULL ) )
V_4 -> V_232 |= V_252 ;
if ( F_100 ( V_251 , L_20 , NULL ) )
V_4 -> V_232 |= V_236 ;
if ( F_100 ( V_251 , L_21 , NULL ) )
V_4 -> V_232 |= V_235 ;
if ( F_100 ( V_251 , L_22 , NULL ) )
V_4 -> V_232 |= V_233 ;
if ( F_100 ( V_251 , L_23 , NULL ) )
V_4 -> V_232 |= V_253 ;
if ( F_100 ( V_251 , L_24 , NULL ) )
V_4 -> V_232 |= V_254 ;
if ( F_100 ( V_251 , L_25 , NULL ) )
V_2 -> V_255 |= V_256 ;
if ( F_100 ( V_251 , L_26 , NULL ) )
V_2 -> V_255 |= V_257 ;
return 0 ;
}
static int F_101 ( struct V_258 * V_72 ,
const struct V_259 * V_260 )
{
struct V_245 * V_218 = V_72 -> V_72 . V_261 ;
struct V_250 * V_251 = V_72 -> V_72 . V_76 ;
struct V_27 * V_28 = V_260 -> V_12 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_120 ;
if ( ! V_218 && ! V_251 ) {
F_12 ( & V_72 -> V_72 , L_27 ) ;
return - V_14 ;
}
if ( ! V_218 ) {
V_218 = F_102 ( & V_72 -> V_72 , sizeof( * V_218 ) , V_262 ) ;
if ( ! V_218 )
return - V_117 ;
}
V_2 = F_103 ( sizeof( struct V_3 ) , & V_72 -> V_72 ) ;
if ( ! V_2 )
return - V_117 ;
V_120 = F_98 ( V_251 , V_2 ) ;
if ( V_120 )
goto V_263;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_239 = F_104 ( V_72 ) ;
V_4 -> V_264 = F_105 ( V_72 ) ;
F_58 ( F_4 ( V_2 ) , L_28 , V_4 -> V_239 ) ;
F_58 ( F_4 ( V_2 ) , L_29 , V_4 -> V_264 ) ;
V_4 -> V_16 = F_106 ( & V_72 -> V_72 , NULL ) ;
if ( F_87 ( V_4 -> V_16 ) ) {
V_120 = F_107 ( V_4 -> V_16 ) ;
goto V_263;
}
V_120 = F_108 ( V_4 -> V_16 ) ;
if ( V_120 )
goto V_263;
if ( V_28 -> V_265 )
V_4 -> V_200 = F_69 ;
else
V_4 -> V_200 = F_68 ;
V_4 -> V_218 = V_218 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_31 = F_92 ( V_4 -> V_16 ) ;
if ( V_4 -> V_31 > V_28 -> V_266 ) {
V_120 = F_91 ( V_4 -> V_16 , V_28 -> V_266 ) ;
if ( V_120 < 0 )
goto V_267;
V_4 -> V_31 = F_92 ( V_4 -> V_16 ) ;
F_58 ( F_4 ( V_2 ) , L_30 ,
V_4 -> V_31 ) ;
}
V_4 -> V_95 = V_72 -> V_268 . V_269 ;
V_4 -> V_8 = F_109 ( & V_72 -> V_72 , & V_72 -> V_268 ) ;
if ( F_87 ( V_4 -> V_8 ) ) {
V_120 = F_107 ( V_4 -> V_8 ) ;
goto V_267;
}
if ( V_28 -> V_33 )
V_2 -> V_270 = F_21 ( V_4 -> V_31 , 257 ) ;
else if ( V_28 -> V_30 )
V_2 -> V_270 = F_110 ( V_4 -> V_16 , 100000 ) ;
else
V_2 -> V_270 = F_21 ( V_4 -> V_31 , 512 ) ;
if ( V_2 -> V_266 )
V_2 -> V_266 = V_28 -> V_30 ?
F_74 ( V_28 -> V_266 , V_2 -> V_266 ) :
F_74 ( V_4 -> V_31 , V_2 -> V_266 ) ;
else
V_2 -> V_266 = V_28 -> V_30 ?
V_271 : F_74 ( V_4 -> V_31 , V_271 ) ;
F_58 ( F_4 ( V_2 ) , L_31 , V_2 -> V_266 ) ;
F_111 ( V_2 ) ;
if ( ! V_2 -> V_272 )
V_2 -> V_272 = V_218 -> V_273 ;
else if ( V_218 -> V_273 )
F_97 ( F_4 ( V_2 ) , L_32 ) ;
if ( ! V_251 ) {
if ( ! V_218 -> V_274 )
V_2 -> V_275 |= V_276 ;
V_2 -> V_275 |= V_277 ;
}
V_2 -> V_255 |= V_278 ;
if ( V_28 -> V_178 ) {
V_279 . V_280 = F_1 ;
F_19 ( V_4 , V_24 ) ;
V_2 -> V_255 |= V_281 ;
V_2 -> V_282 = 0 ;
}
V_2 -> V_283 = & V_279 ;
V_2 -> V_284 |= V_285 ;
V_2 -> V_286 = V_287 ;
V_2 -> V_288 = ( 1 << V_28 -> V_289 ) - 1 ;
V_2 -> V_73 = V_2 -> V_288 ;
V_2 -> V_290 = 1 << 11 ;
V_2 -> V_291 = V_2 -> V_288 >> 11 ;
F_112 ( & V_4 -> V_7 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
F_17 ( 0 , V_4 -> V_8 + V_57 ) ;
F_17 ( 0xfff , V_4 -> V_8 + V_215 ) ;
if ( ! V_251 ) {
V_120 = F_113 ( V_2 , L_33 , 0 , false , 0 , NULL ) ;
if ( V_120 < 0 ) {
if ( V_120 == - V_292 )
goto V_267;
else if ( F_114 ( V_218 -> V_293 ) ) {
V_120 = F_115 ( V_2 , V_218 -> V_293 , 0 ) ;
if ( V_120 )
goto V_267;
}
}
V_120 = F_116 ( V_2 , L_34 , 0 , false , 0 , NULL ) ;
if ( V_120 < 0 ) {
if ( V_120 == - V_292 )
goto V_267;
else if ( F_114 ( V_218 -> V_294 ) ) {
V_120 = F_117 ( V_2 , V_218 -> V_294 ) ;
if ( V_120 )
goto V_267;
}
}
}
V_120 = F_118 ( & V_72 -> V_72 , V_72 -> V_205 [ 0 ] , F_81 , V_295 ,
V_296 L_35 , V_4 ) ;
if ( V_120 )
goto V_267;
if ( ! V_72 -> V_205 [ 1 ] )
V_4 -> V_53 = true ;
else {
V_120 = F_118 ( & V_72 -> V_72 , V_72 -> V_205 [ 1 ] , F_76 ,
V_295 , V_296 L_36 , V_4 ) ;
if ( V_120 )
goto V_267;
}
F_17 ( V_297 , V_4 -> V_8 + V_55 ) ;
F_119 ( V_72 , V_2 ) ;
F_32 ( & V_72 -> V_72 , L_37 ,
F_120 ( V_2 ) , F_121 ( V_72 ) , F_104 ( V_72 ) ,
F_105 ( V_72 ) , ( unsigned long long ) V_72 -> V_268 . V_269 ,
V_72 -> V_205 [ 0 ] , V_72 -> V_205 [ 1 ] ) ;
F_29 ( V_4 ) ;
F_122 ( & V_72 -> V_72 , 50 ) ;
F_123 ( & V_72 -> V_72 ) ;
F_124 ( V_2 ) ;
F_125 ( & V_72 -> V_72 ) ;
return 0 ;
V_267:
F_126 ( V_4 -> V_16 ) ;
V_263:
F_127 ( V_2 ) ;
return V_120 ;
}
static int F_128 ( struct V_258 * V_72 )
{
struct V_1 * V_2 = F_129 ( V_72 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_72 -> V_72 ) ;
F_130 ( V_2 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
F_17 ( 0 , V_4 -> V_8 + V_57 ) ;
F_17 ( 0 , V_4 -> V_8 + V_50 ) ;
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_35 ( V_4 ) ;
F_126 ( V_4 -> V_16 ) ;
F_127 ( V_2 ) ;
}
return 0 ;
}
static void F_131 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
if ( V_4 -> V_28 -> V_298 ) {
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_17 ( 0 , V_4 -> V_8 + V_21 ) ;
F_17 ( 0 , V_4 -> V_8 + V_18 ) ;
}
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_132 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
if ( V_4 -> V_28 -> V_298 ) {
F_17 ( V_4 -> V_17 , V_4 -> V_8 + V_18 ) ;
F_17 ( V_4 -> V_23 , V_4 -> V_8 + V_25 ) ;
F_17 ( V_4 -> V_20 , V_4 -> V_8 + V_21 ) ;
}
F_17 ( V_297 , V_4 -> V_8 + V_55 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static int F_133 ( struct V_71 * V_72 )
{
struct V_258 * V_299 = F_134 ( V_72 ) ;
struct V_1 * V_2 = F_129 ( V_299 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_135 ( V_72 ) ;
F_131 ( V_4 ) ;
F_126 ( V_4 -> V_16 ) ;
}
return 0 ;
}
static int F_136 ( struct V_71 * V_72 )
{
struct V_258 * V_299 = F_134 ( V_72 ) ;
struct V_1 * V_2 = F_129 ( V_299 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_108 ( V_4 -> V_16 ) ;
F_132 ( V_4 ) ;
F_137 ( V_72 ) ;
}
return 0 ;
}
