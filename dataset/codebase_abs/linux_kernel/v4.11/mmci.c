static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
int V_6 = 0 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
if ( F_4 ( V_4 -> V_8 + V_9 ) & V_4 -> V_10 -> V_11 )
V_6 = 1 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
return V_6 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
if ( ! V_13 )
return 0 ;
if ( ! F_7 ( V_13 -> V_14 ) ) {
F_8 ( F_9 ( V_4 -> V_2 ) ,
L_1 , V_13 -> V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
if ( V_4 -> V_16 < 25000000 )
F_11 ( 30 ) ;
else
F_12 ( 120 ) ;
}
static void F_13 ( struct V_3 * V_4 , T_1 V_17 )
{
if ( V_4 -> V_18 != V_17 ) {
V_4 -> V_18 = V_17 ;
F_14 ( V_17 , V_4 -> V_8 + V_19 ) ;
}
}
static void F_15 ( struct V_3 * V_4 , T_1 V_20 )
{
if ( V_4 -> V_21 != V_20 ) {
V_4 -> V_21 = V_20 ;
F_14 ( V_20 , V_4 -> V_8 + V_22 ) ;
}
}
static void F_16 ( struct V_3 * V_4 , T_1 V_23 )
{
V_23 |= V_4 -> V_24 & V_4 -> V_10 -> V_25 ;
if ( V_4 -> V_24 != V_23 ) {
V_4 -> V_24 = V_23 ;
F_14 ( V_23 , V_4 -> V_8 + V_26 ) ;
}
}
static void F_17 ( struct V_3 * V_4 , unsigned int V_27 )
{
struct V_28 * V_10 = V_4 -> V_10 ;
T_1 V_17 = V_10 -> V_29 ;
V_4 -> V_16 = 0 ;
if ( V_27 ) {
if ( V_10 -> V_30 ) {
V_4 -> V_16 = V_4 -> V_31 ;
} else if ( V_27 >= V_4 -> V_31 ) {
V_17 = V_32 ;
if ( V_10 -> V_33 )
V_17 |= V_34 ;
V_4 -> V_16 = V_4 -> V_31 ;
} else if ( V_10 -> V_33 ) {
V_17 = F_18 ( V_4 -> V_31 , V_27 ) - 2 ;
if ( V_17 >= 256 )
V_17 = 255 ;
V_4 -> V_16 = V_4 -> V_31 / ( V_17 + 2 ) ;
} else {
V_17 = V_4 -> V_31 / ( 2 * V_27 ) - 1 ;
if ( V_17 >= 256 )
V_17 = 255 ;
V_4 -> V_16 = V_4 -> V_31 / ( 2 * ( V_17 + 1 ) ) ;
}
V_17 |= V_10 -> V_35 ;
V_17 |= V_36 ;
}
V_4 -> V_2 -> V_37 = V_4 -> V_16 ;
if ( V_4 -> V_2 -> V_38 . V_39 == V_40 )
V_17 |= V_41 ;
if ( V_4 -> V_2 -> V_38 . V_39 == V_42 )
V_17 |= V_10 -> V_43 ;
if ( V_4 -> V_2 -> V_38 . V_44 == V_45 ||
V_4 -> V_2 -> V_38 . V_44 == V_46 )
V_17 |= V_10 -> V_47 ;
F_13 ( V_4 , V_17 ) ;
}
static void
F_19 ( struct V_3 * V_4 , struct V_48 * V_49 )
{
F_14 ( 0 , V_4 -> V_8 + V_50 ) ;
F_20 ( V_4 -> V_13 ) ;
V_4 -> V_49 = NULL ;
V_4 -> V_51 = NULL ;
F_21 ( V_4 -> V_2 , V_49 ) ;
}
static void F_22 ( struct V_3 * V_4 , unsigned int V_52 )
{
void T_2 * V_8 = V_4 -> V_8 ;
if ( V_4 -> V_53 ) {
unsigned int V_54 = F_4 ( V_8 + V_55 ) ;
V_54 &= ~ V_56 ;
V_54 |= V_52 ;
F_14 ( V_54 , V_8 + V_55 ) ;
}
F_14 ( V_52 , V_8 + V_57 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
F_16 ( V_4 , 0 ) ;
F_22 ( V_4 , 0 ) ;
V_4 -> V_13 = NULL ;
}
static void F_24 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
unsigned int V_5 = V_58 ;
if ( V_13 -> V_5 & V_59 )
V_5 |= V_60 ;
else
V_5 |= V_61 ;
F_25 ( & V_4 -> V_62 , V_13 -> V_63 , V_13 -> V_64 , V_5 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
const char * V_65 , * V_66 ;
struct V_28 * V_10 = V_4 -> V_10 ;
V_4 -> V_67 = F_27 ( F_9 ( V_4 -> V_2 ) , L_2 ) ;
V_4 -> V_68 = F_27 ( F_9 ( V_4 -> V_2 ) , L_3 ) ;
V_4 -> V_69 . V_70 = 1 ;
if ( V_4 -> V_67 && ! V_4 -> V_68 )
V_4 -> V_68 = V_4 -> V_67 ;
if ( V_4 -> V_67 )
V_65 = F_28 ( V_4 -> V_67 ) ;
else
V_65 = L_4 ;
if ( V_4 -> V_68 )
V_66 = F_28 ( V_4 -> V_68 ) ;
else
V_66 = L_4 ;
F_29 ( F_9 ( V_4 -> V_2 ) , L_5 ,
V_65 , V_66 ) ;
if ( V_4 -> V_68 ) {
struct V_71 * V_72 = V_4 -> V_68 -> V_71 -> V_72 ;
unsigned int V_73 = F_30 ( V_72 ) ;
if ( V_73 < V_4 -> V_2 -> V_73 )
V_4 -> V_2 -> V_73 = V_73 ;
}
if ( V_4 -> V_67 ) {
struct V_71 * V_72 = V_4 -> V_67 -> V_71 -> V_72 ;
unsigned int V_73 = F_30 ( V_72 ) ;
if ( V_73 < V_4 -> V_2 -> V_73 )
V_4 -> V_2 -> V_73 = V_73 ;
}
if ( V_10 -> V_74 && V_4 -> V_67 && V_4 -> V_68 )
if ( F_31 ( V_4 , V_4 -> V_2 -> V_75 -> V_76 ) )
V_10 -> V_74 = false ;
}
static inline void F_32 ( struct V_3 * V_4 )
{
if ( V_4 -> V_67 )
F_33 ( V_4 -> V_67 ) ;
if ( V_4 -> V_68 )
F_33 ( V_4 -> V_68 ) ;
V_4 -> V_67 = V_4 -> V_68 = NULL ;
}
static void F_34 ( struct V_3 * V_4 )
{
F_8 ( F_9 ( V_4 -> V_2 ) , L_6 ) ;
F_35 ( V_4 -> V_77 ) ;
V_4 -> V_78 = false ;
V_4 -> V_77 = NULL ;
V_4 -> V_79 = NULL ;
V_4 -> V_13 -> V_80 = 0 ;
}
static void F_36 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_81 * V_82 ;
enum V_83 V_84 ;
if ( V_13 -> V_5 & V_59 ) {
V_84 = V_85 ;
V_82 = V_4 -> V_67 ;
} else {
V_84 = V_86 ;
V_82 = V_4 -> V_68 ;
}
F_37 ( V_82 -> V_71 -> V_72 , V_13 -> V_63 , V_13 -> V_64 , V_84 ) ;
}
static void F_38 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
T_1 V_87 ;
int V_88 ;
for ( V_88 = 0 ; ; V_88 ++ ) {
V_87 = F_4 ( V_4 -> V_8 + V_9 ) ;
if ( ! ( V_87 & V_89 ) || V_88 >= 100 )
break;
F_11 ( 10 ) ;
}
if ( V_87 & V_89 ) {
F_34 ( V_4 ) ;
if ( ! V_13 -> error )
V_13 -> error = - V_90 ;
}
if ( ! V_13 -> V_80 )
F_36 ( V_4 , V_13 ) ;
if ( V_87 & V_89 ) {
F_8 ( F_9 ( V_4 -> V_2 ) , L_7 ) ;
F_32 ( V_4 ) ;
}
V_4 -> V_78 = false ;
V_4 -> V_77 = NULL ;
V_4 -> V_79 = NULL ;
}
static int F_39 ( struct V_3 * V_4 , struct V_12 * V_13 ,
struct V_81 * * V_81 ,
struct V_91 * * V_92 )
{
struct V_28 * V_10 = V_4 -> V_10 ;
struct V_93 V_94 = {
. V_95 = V_4 -> V_96 + V_97 ,
. V_98 = V_4 -> V_96 + V_97 ,
. V_99 = V_100 ,
. V_101 = V_100 ,
. V_102 = V_10 -> V_103 >> 2 ,
. V_104 = V_10 -> V_103 >> 2 ,
. V_105 = false ,
} ;
struct V_81 * V_82 ;
struct V_106 * V_71 ;
struct V_91 * V_107 ;
enum V_83 V_108 ;
int V_109 ;
unsigned long V_5 = V_110 ;
if ( V_13 -> V_5 & V_59 ) {
V_94 . V_111 = V_112 ;
V_108 = V_85 ;
V_82 = V_4 -> V_67 ;
} else {
V_94 . V_111 = V_113 ;
V_108 = V_86 ;
V_82 = V_4 -> V_68 ;
}
if ( ! V_82 )
return - V_15 ;
if ( V_13 -> V_14 * V_13 -> V_114 <= V_10 -> V_115 )
return - V_15 ;
V_71 = V_82 -> V_71 ;
V_109 = F_40 ( V_71 -> V_72 , V_13 -> V_63 , V_13 -> V_64 , V_108 ) ;
if ( V_109 == 0 )
return - V_15 ;
if ( V_4 -> V_10 -> V_74 )
V_5 |= V_116 ;
F_41 ( V_82 , & V_94 ) ;
V_107 = F_42 ( V_82 , V_13 -> V_63 , V_109 ,
V_94 . V_111 , V_5 ) ;
if ( ! V_107 )
goto V_117;
* V_81 = V_82 ;
* V_92 = V_107 ;
return 0 ;
V_117:
F_37 ( V_71 -> V_72 , V_13 -> V_63 , V_13 -> V_64 , V_108 ) ;
return - V_118 ;
}
static inline int F_43 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
if ( V_4 -> V_77 && V_4 -> V_79 )
return 0 ;
return F_39 ( V_4 , V_13 , & V_4 -> V_77 ,
& V_4 -> V_79 ) ;
}
static inline int F_44 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
struct V_119 * V_120 = & V_4 -> V_69 ;
return F_39 ( V_4 , V_13 , & V_120 -> V_81 , & V_120 -> V_92 ) ;
}
static int F_45 ( struct V_3 * V_4 , unsigned int V_23 )
{
int V_121 ;
struct V_12 * V_13 = V_4 -> V_13 ;
V_121 = F_43 ( V_4 , V_4 -> V_13 ) ;
if ( V_121 )
return V_121 ;
F_46 ( F_9 ( V_4 -> V_2 ) ,
L_8 ,
V_13 -> V_64 , V_13 -> V_14 , V_13 -> V_114 , V_13 -> V_5 ) ;
V_4 -> V_78 = true ;
F_47 ( V_4 -> V_79 ) ;
F_48 ( V_4 -> V_77 ) ;
if ( V_4 -> V_10 -> V_74 )
F_49 ( V_4 , V_13 ) ;
V_23 |= V_122 ;
F_16 ( V_4 , V_23 ) ;
F_14 ( F_4 ( V_4 -> V_8 + V_55 ) | V_123 ,
V_4 -> V_8 + V_55 ) ;
return 0 ;
}
static void F_50 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_119 * V_124 = & V_4 -> V_69 ;
F_51 ( V_13 -> V_80 && V_13 -> V_80 != V_124 -> V_70 ) ;
F_51 ( ! V_13 -> V_80 && ( V_124 -> V_92 || V_124 -> V_81 ) ) ;
V_4 -> V_79 = V_124 -> V_92 ;
V_4 -> V_77 = V_124 -> V_81 ;
V_124 -> V_92 = NULL ;
V_124 -> V_81 = NULL ;
}
static void F_52 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_49 -> V_13 ;
struct V_119 * V_120 = & V_4 -> V_69 ;
if ( ! V_13 )
return;
F_20 ( V_13 -> V_80 ) ;
if ( F_6 ( V_4 , V_13 ) )
return;
if ( ! F_44 ( V_4 , V_13 ) )
V_13 -> V_80 = ++ V_120 -> V_70 < 0 ? 1 : V_120 -> V_70 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_48 * V_49 ,
int V_125 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_49 -> V_13 ;
if ( ! V_13 || ! V_13 -> V_80 )
return;
F_36 ( V_4 , V_13 ) ;
if ( V_125 ) {
struct V_119 * V_124 = & V_4 -> V_69 ;
struct V_81 * V_82 ;
if ( V_13 -> V_5 & V_59 )
V_82 = V_4 -> V_67 ;
else
V_82 = V_4 -> V_68 ;
F_35 ( V_82 ) ;
if ( V_4 -> V_79 == V_124 -> V_92 )
V_4 -> V_79 = NULL ;
if ( V_4 -> V_77 == V_124 -> V_81 ) {
V_4 -> V_78 = false ;
V_4 -> V_77 = NULL ;
}
V_124 -> V_92 = NULL ;
V_124 -> V_81 = NULL ;
V_13 -> V_80 = 0 ;
}
}
static void F_50 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
}
static inline void F_26 ( struct V_3 * V_4 )
{
}
static inline void F_32 ( struct V_3 * V_4 )
{
}
static inline void F_36 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
}
static inline void F_38 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
}
static inline void F_34 ( struct V_3 * V_4 )
{
}
static inline int F_45 ( struct V_3 * V_4 , unsigned int V_23 )
{
return - V_126 ;
}
static void F_54 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_28 * V_10 = V_4 -> V_10 ;
unsigned int V_23 , V_127 , V_128 ;
unsigned long long V_129 ;
void T_2 * V_8 ;
int V_130 ;
F_55 ( F_9 ( V_4 -> V_2 ) , L_9 ,
V_13 -> V_14 , V_13 -> V_114 , V_13 -> V_5 ) ;
V_4 -> V_13 = V_13 ;
V_4 -> V_131 = V_13 -> V_14 * V_13 -> V_114 ;
V_13 -> V_132 = 0 ;
V_129 = ( unsigned long long ) V_13 -> V_133 * V_4 -> V_16 ;
F_56 ( V_129 , V_134 ) ;
V_127 = V_13 -> V_135 + ( unsigned int ) V_129 ;
V_8 = V_4 -> V_8 ;
F_14 ( V_127 , V_8 + V_136 ) ;
F_14 ( V_4 -> V_131 , V_8 + V_137 ) ;
V_130 = F_57 ( V_13 -> V_14 ) - 1 ;
F_20 ( 1 << V_130 != V_13 -> V_14 ) ;
if ( V_10 -> V_138 )
V_23 = V_139 | ( V_13 -> V_14 << 16 ) ;
else if ( V_10 -> V_140 )
V_23 = V_139 | ( V_13 -> V_14 << 4 ) ;
else
V_23 = V_139 | V_130 << 4 ;
if ( V_13 -> V_5 & V_59 )
V_23 |= V_141 ;
if ( V_4 -> V_2 -> V_142 && F_58 ( V_4 -> V_2 -> V_142 ) ) {
T_1 V_17 ;
V_23 |= V_10 -> V_143 ;
if ( V_10 -> V_144 && V_13 -> V_5 & V_145 &&
( V_4 -> V_131 < 8 ||
( V_4 -> V_131 <= 8 && V_4 -> V_31 > 50000000 ) ) )
V_17 = V_4 -> V_18 & ~ V_10 -> V_35 ;
else
V_17 = V_4 -> V_18 | V_10 -> V_35 ;
F_13 ( V_4 , V_17 ) ;
}
if ( V_4 -> V_2 -> V_38 . V_44 == V_45 ||
V_4 -> V_2 -> V_38 . V_44 == V_46 )
V_23 |= V_10 -> V_146 ;
if ( ! F_45 ( V_4 , V_23 ) )
return;
F_24 ( V_4 , V_13 ) ;
if ( V_13 -> V_5 & V_59 ) {
V_128 = V_147 ;
if ( V_4 -> V_131 < V_10 -> V_103 )
V_128 |= V_89 ;
} else {
V_128 = V_148 ;
}
F_16 ( V_4 , V_23 ) ;
F_14 ( F_4 ( V_8 + V_55 ) & ~ V_123 , V_8 + V_55 ) ;
F_22 ( V_4 , V_128 ) ;
}
static void
F_59 ( struct V_3 * V_4 , struct V_149 * V_51 , T_1 V_150 )
{
void T_2 * V_8 = V_4 -> V_8 ;
F_55 ( F_9 ( V_4 -> V_2 ) , L_10 ,
V_51 -> V_151 , V_51 -> V_152 , V_51 -> V_5 ) ;
if ( F_4 ( V_8 + V_50 ) & V_153 ) {
F_14 ( 0 , V_8 + V_50 ) ;
F_10 ( V_4 ) ;
}
V_150 |= V_51 -> V_151 | V_153 ;
if ( V_51 -> V_5 & V_154 ) {
if ( V_51 -> V_5 & V_155 )
V_150 |= V_156 ;
V_150 |= V_157 ;
}
if ( 0 )
V_150 |= V_158 ;
if ( F_60 ( V_51 ) == V_159 )
V_150 |= V_4 -> V_10 -> V_160 ;
V_4 -> V_51 = V_51 ;
F_14 ( V_51 -> V_152 , V_8 + V_161 ) ;
F_14 ( V_150 , V_8 + V_50 ) ;
}
static void
F_61 ( struct V_3 * V_4 , struct V_12 * V_13 ,
unsigned int V_87 )
{
if ( ! V_13 )
return;
if ( V_87 & ( V_162 | V_163 | V_164 |
V_165 | V_166 ) ) {
T_1 V_167 , V_168 ;
if ( F_62 ( V_4 ) ) {
F_34 ( V_4 ) ;
F_36 ( V_4 , V_13 ) ;
}
V_167 = F_4 ( V_4 -> V_8 + V_169 ) ;
V_168 = V_13 -> V_14 * V_13 -> V_114 - V_167 ;
F_55 ( F_9 ( V_4 -> V_2 ) , L_11 ,
V_87 , V_168 ) ;
if ( V_87 & V_162 ) {
V_168 -= 1 ;
V_13 -> error = - V_170 ;
} else if ( V_87 & V_163 ) {
V_13 -> error = - V_171 ;
} else if ( V_87 & V_164 ) {
V_13 -> error = - V_172 ;
} else if ( V_87 & V_165 ) {
V_13 -> error = - V_90 ;
} else if ( V_87 & V_166 ) {
if ( V_168 > V_4 -> V_10 -> V_115 )
V_168 -= V_4 -> V_10 -> V_115 ;
else
V_168 = 0 ;
V_13 -> error = - V_90 ;
}
V_13 -> V_132 = F_63 ( V_168 , V_13 -> V_14 ) ;
}
if ( V_87 & V_173 )
F_8 ( F_9 ( V_4 -> V_2 ) , L_12 ) ;
if ( V_87 & V_174 || V_13 -> error ) {
if ( F_62 ( V_4 ) )
F_38 ( V_4 , V_13 ) ;
F_23 ( V_4 ) ;
if ( ! V_13 -> error )
V_13 -> V_132 = V_13 -> V_14 * V_13 -> V_114 ;
if ( ! V_13 -> V_175 || V_4 -> V_49 -> V_176 ) {
F_19 ( V_4 , V_13 -> V_49 ) ;
} else {
F_59 ( V_4 , V_13 -> V_175 , 0 ) ;
}
}
}
static void
F_64 ( struct V_3 * V_4 , struct V_149 * V_51 ,
unsigned int V_87 )
{
void T_2 * V_8 = V_4 -> V_8 ;
bool V_176 ;
if ( ! V_51 )
return;
V_176 = ( V_51 == V_4 -> V_49 -> V_176 ) ;
if ( ! ( ( V_87 | V_4 -> V_177 ) &
( V_178 | V_179 | V_180 | V_181 ) ) )
return;
if ( V_4 -> V_10 -> V_182 ) {
bool V_183 = ! ! ( V_51 -> V_5 & V_184 ) ;
if ( V_4 -> V_177 &&
( V_87 & V_4 -> V_10 -> V_11 ) )
return;
if ( ! V_4 -> V_177 && V_183 &&
! ( V_87 & ( V_178 | V_179 ) ) &&
( F_4 ( V_8 + V_9 ) & V_4 -> V_10 -> V_11 ) ) {
F_14 ( V_4 -> V_10 -> V_185 ,
V_4 -> V_8 + V_186 ) ;
F_14 ( F_4 ( V_8 + V_55 ) |
V_4 -> V_10 -> V_185 ,
V_8 + V_55 ) ;
V_4 -> V_177 =
V_87 & ( V_180 | V_181 ) ;
return;
}
if ( V_4 -> V_177 ) {
F_14 ( V_4 -> V_10 -> V_185 ,
V_4 -> V_8 + V_186 ) ;
F_14 ( F_4 ( V_8 + V_55 ) &
~ V_4 -> V_10 -> V_185 ,
V_8 + V_55 ) ;
V_4 -> V_177 = 0 ;
}
}
V_4 -> V_51 = NULL ;
if ( V_87 & V_179 ) {
V_51 -> error = - V_171 ;
} else if ( V_87 & V_178 && V_51 -> V_5 & V_187 ) {
V_51 -> error = - V_170 ;
} else {
V_51 -> V_188 [ 0 ] = F_4 ( V_8 + V_189 ) ;
V_51 -> V_188 [ 1 ] = F_4 ( V_8 + V_190 ) ;
V_51 -> V_188 [ 2 ] = F_4 ( V_8 + V_191 ) ;
V_51 -> V_188 [ 3 ] = F_4 ( V_8 + V_192 ) ;
}
if ( ( ! V_176 && ! V_51 -> V_13 ) || V_51 -> error ) {
if ( V_4 -> V_13 ) {
if ( F_62 ( V_4 ) ) {
F_34 ( V_4 ) ;
F_36 ( V_4 , V_4 -> V_13 ) ;
}
F_23 ( V_4 ) ;
}
F_19 ( V_4 , V_4 -> V_49 ) ;
} else if ( V_176 ) {
F_59 ( V_4 , V_4 -> V_49 -> V_51 , 0 ) ;
} else if ( ! ( V_51 -> V_13 -> V_5 & V_59 ) ) {
F_54 ( V_4 , V_51 -> V_13 ) ;
}
}
static int F_65 ( struct V_3 * V_4 , T_1 V_87 , int V_167 )
{
return V_167 - ( F_4 ( V_4 -> V_8 + V_193 ) << 2 ) ;
}
static int F_66 ( struct V_3 * V_4 , T_1 V_87 , int V_194 )
{
if ( V_87 & V_195 )
return V_4 -> V_10 -> V_103 ;
else if ( V_87 & V_196 )
return 4 ;
return 0 ;
}
static int F_67 ( struct V_3 * V_4 , char * V_197 , unsigned int V_167 )
{
void T_2 * V_8 = V_4 -> V_8 ;
char * V_198 = V_197 ;
T_1 V_87 = F_4 ( V_4 -> V_8 + V_9 ) ;
int V_199 = V_4 -> V_131 ;
do {
int V_200 = V_4 -> V_201 ( V_4 , V_87 , V_199 ) ;
if ( V_200 > V_167 )
V_200 = V_167 ;
if ( V_200 <= 0 )
break;
if ( F_68 ( V_200 & 0x3 ) ) {
if ( V_200 < 4 ) {
unsigned char V_202 [ 4 ] ;
F_69 ( V_8 + V_97 , V_202 , 1 ) ;
memcpy ( V_198 , V_202 , V_200 ) ;
} else {
F_69 ( V_8 + V_97 , V_198 , V_200 >> 2 ) ;
V_200 &= ~ 0x3 ;
}
} else {
F_69 ( V_8 + V_97 , V_198 , V_200 >> 2 ) ;
}
V_198 += V_200 ;
V_167 -= V_200 ;
V_199 -= V_200 ;
if ( V_167 == 0 )
break;
V_87 = F_4 ( V_8 + V_9 ) ;
} while ( V_87 & V_196 );
return V_198 - V_197 ;
}
static int F_70 ( struct V_3 * V_4 , char * V_197 , unsigned int V_167 , T_1 V_87 )
{
struct V_28 * V_10 = V_4 -> V_10 ;
void T_2 * V_8 = V_4 -> V_8 ;
char * V_198 = V_197 ;
do {
unsigned int V_200 , V_203 ;
V_203 = V_87 & V_204 ?
V_10 -> V_115 : V_10 -> V_103 ;
V_200 = F_71 ( V_167 , V_203 ) ;
F_72 ( V_8 + V_97 , V_198 , ( V_200 + 3 ) >> 2 ) ;
V_198 += V_200 ;
V_167 -= V_200 ;
if ( V_167 == 0 )
break;
V_87 = F_4 ( V_8 + V_9 ) ;
} while ( V_87 & V_205 );
return V_198 - V_197 ;
}
static T_3 F_73 ( int V_206 , void * V_207 )
{
struct V_3 * V_4 = V_207 ;
struct V_208 * V_62 = & V_4 -> V_62 ;
struct V_28 * V_10 = V_4 -> V_10 ;
void T_2 * V_8 = V_4 -> V_8 ;
unsigned long V_5 ;
T_1 V_87 ;
V_87 = F_4 ( V_8 + V_9 ) ;
F_55 ( F_9 ( V_4 -> V_2 ) , L_13 , V_87 ) ;
F_74 ( V_5 ) ;
do {
unsigned int V_167 , V_209 ;
char * V_197 ;
if ( ! ( V_87 & ( V_205 | V_196 ) ) )
break;
if ( ! F_75 ( V_62 ) )
break;
V_197 = V_62 -> V_210 ;
V_167 = V_62 -> V_211 ;
V_209 = 0 ;
if ( V_87 & V_212 )
V_209 = F_67 ( V_4 , V_197 , V_167 ) ;
if ( V_87 & V_213 )
V_209 = F_70 ( V_4 , V_197 , V_167 , V_87 ) ;
V_62 -> V_214 = V_209 ;
V_4 -> V_131 -= V_209 ;
V_167 -= V_209 ;
if ( V_167 )
break;
V_87 = F_4 ( V_8 + V_9 ) ;
} while ( 1 );
F_76 ( V_62 ) ;
F_77 ( V_5 ) ;
if ( V_87 & V_212 && V_4 -> V_131 < V_10 -> V_103 )
F_22 ( V_4 , V_89 ) ;
if ( V_4 -> V_131 == 0 ) {
F_22 ( V_4 , 0 ) ;
F_14 ( F_4 ( V_8 + V_55 ) | V_123 , V_8 + V_55 ) ;
}
return V_215 ;
}
static T_3 F_78 ( int V_206 , void * V_207 )
{
struct V_3 * V_4 = V_207 ;
T_1 V_87 ;
int V_121 = 0 ;
F_79 ( & V_4 -> V_7 ) ;
do {
V_87 = F_4 ( V_4 -> V_8 + V_9 ) ;
if ( V_4 -> V_53 ) {
if ( V_87 & F_4 ( V_4 -> V_8 + V_57 ) )
F_73 ( V_206 , V_207 ) ;
V_87 &= ~ V_56 ;
}
V_87 &= F_4 ( V_4 -> V_8 + V_55 ) ;
if ( V_4 -> V_10 -> V_182 )
F_14 ( V_87 & ~ V_4 -> V_10 -> V_185 ,
V_4 -> V_8 + V_186 ) ;
else
F_14 ( V_87 , V_4 -> V_8 + V_186 ) ;
F_55 ( F_9 ( V_4 -> V_2 ) , L_14 , V_87 ) ;
if ( V_4 -> V_10 -> V_216 ) {
F_61 ( V_4 , V_4 -> V_13 , V_87 ) ;
F_64 ( V_4 , V_4 -> V_51 , V_87 ) ;
} else {
F_64 ( V_4 , V_4 -> V_51 , V_87 ) ;
F_61 ( V_4 , V_4 -> V_13 , V_87 ) ;
}
if ( V_4 -> V_10 -> V_182 && V_4 -> V_177 )
V_87 &= ~ V_4 -> V_10 -> V_11 ;
V_121 = 1 ;
} while ( V_87 );
F_80 ( & V_4 -> V_7 ) ;
return F_81 ( V_121 ) ;
}
static void F_82 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_51 ( V_4 -> V_49 != NULL ) ;
V_49 -> V_51 -> error = F_6 ( V_4 , V_49 -> V_13 ) ;
if ( V_49 -> V_51 -> error ) {
F_21 ( V_2 , V_49 ) ;
return;
}
F_3 ( & V_4 -> V_7 , V_5 ) ;
V_4 -> V_49 = V_49 ;
if ( V_49 -> V_13 )
F_50 ( V_4 , V_49 -> V_13 ) ;
if ( V_49 -> V_13 && V_49 -> V_13 -> V_5 & V_59 )
F_54 ( V_4 , V_49 -> V_13 ) ;
if ( V_49 -> V_176 )
F_59 ( V_4 , V_49 -> V_176 , 0 ) ;
else
F_59 ( V_4 , V_49 -> V_51 , 0 ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_217 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_10 = V_4 -> V_10 ;
T_1 V_20 = 0 ;
unsigned long V_5 ;
int V_121 ;
if ( V_4 -> V_218 -> V_219 &&
V_4 -> V_218 -> V_219 ( F_9 ( V_2 ) , V_38 ) )
F_8 ( F_9 ( V_2 ) , L_15 ) ;
switch ( V_38 -> V_220 ) {
case V_221 :
if ( ! F_84 ( V_2 -> V_222 . V_223 ) )
F_85 ( V_2 , V_2 -> V_222 . V_223 , 0 ) ;
if ( ! F_84 ( V_2 -> V_222 . V_224 ) && V_4 -> V_225 ) {
F_86 ( V_2 -> V_222 . V_224 ) ;
V_4 -> V_225 = false ;
}
break;
case V_226 :
if ( ! F_84 ( V_2 -> V_222 . V_223 ) )
F_85 ( V_2 , V_2 -> V_222 . V_223 , V_38 -> V_227 ) ;
V_20 |= V_10 -> V_228 ;
break;
case V_229 :
if ( ! F_84 ( V_2 -> V_222 . V_224 ) && ! V_4 -> V_225 ) {
V_121 = F_87 ( V_2 -> V_222 . V_224 ) ;
if ( V_121 < 0 )
F_8 ( F_9 ( V_2 ) ,
L_16 ) ;
else
V_4 -> V_225 = true ;
}
V_20 |= V_230 ;
break;
}
if ( V_10 -> V_231 && V_38 -> V_220 != V_221 ) {
V_20 |= V_4 -> V_232 ;
if ( V_38 -> V_39 == V_40 )
V_20 &= ~ V_233 ;
else if ( V_38 -> V_39 == V_234 )
V_20 &= ( ~ V_233 &
~ V_235 &
~ V_236 ) ;
}
if ( V_38 -> V_237 == V_238 ) {
if ( V_4 -> V_239 != V_240 )
V_20 |= V_241 ;
else {
V_20 |= V_242 ;
}
}
if ( ! V_38 -> clock && V_10 -> V_243 )
V_20 &= ~ V_230 ;
if ( V_4 -> V_10 -> V_30 &&
V_38 -> clock != V_4 -> V_244 ) {
V_121 = F_88 ( V_4 -> V_17 , V_38 -> clock ) ;
if ( V_121 < 0 )
F_8 ( F_9 ( V_4 -> V_2 ) ,
L_17 , V_121 ) ;
else
V_4 -> V_31 = F_89 ( V_4 -> V_17 ) ;
}
V_4 -> V_244 = V_38 -> clock ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
F_17 ( V_4 , V_38 -> clock ) ;
F_15 ( V_4 , V_20 ) ;
F_10 ( V_4 ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_245 * V_218 = V_4 -> V_218 ;
unsigned int V_87 = F_91 ( V_2 ) ;
if ( V_87 == - V_126 ) {
if ( ! V_218 -> V_87 )
return 1 ;
V_87 = V_218 -> V_87 ( F_9 ( V_4 -> V_2 ) ) ;
}
return V_87 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_217 * V_38 )
{
int V_121 = 0 ;
if ( ! F_84 ( V_2 -> V_222 . V_224 ) ) {
switch ( V_38 -> V_246 ) {
case V_247 :
V_121 = F_93 ( V_2 -> V_222 . V_224 ,
2700000 , 3600000 ) ;
break;
case V_248 :
V_121 = F_93 ( V_2 -> V_222 . V_224 ,
1700000 , 1950000 ) ;
break;
case V_249 :
V_121 = F_93 ( V_2 -> V_222 . V_224 ,
1100000 , 1300000 ) ;
break;
}
if ( V_121 )
F_94 ( F_9 ( V_2 ) , L_18 ) ;
}
return V_121 ;
}
static int F_95 ( struct V_250 * V_251 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_121 = F_96 ( V_2 ) ;
if ( V_121 )
return V_121 ;
if ( F_97 ( V_251 , L_19 , NULL ) )
V_4 -> V_232 |= V_252 ;
if ( F_97 ( V_251 , L_20 , NULL ) )
V_4 -> V_232 |= V_236 ;
if ( F_97 ( V_251 , L_21 , NULL ) )
V_4 -> V_232 |= V_235 ;
if ( F_97 ( V_251 , L_22 , NULL ) )
V_4 -> V_232 |= V_233 ;
if ( F_97 ( V_251 , L_23 , NULL ) )
V_4 -> V_232 |= V_253 ;
if ( F_97 ( V_251 , L_24 , NULL ) )
V_4 -> V_232 |= V_254 ;
if ( F_97 ( V_251 , L_25 , NULL ) )
V_2 -> V_255 |= V_256 ;
if ( F_97 ( V_251 , L_26 , NULL ) )
V_2 -> V_255 |= V_257 ;
return 0 ;
}
static int F_98 ( struct V_258 * V_72 ,
const struct V_259 * V_260 )
{
struct V_245 * V_218 = V_72 -> V_72 . V_261 ;
struct V_250 * V_251 = V_72 -> V_72 . V_76 ;
struct V_28 * V_10 = V_260 -> V_13 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_121 ;
if ( ! V_218 && ! V_251 ) {
F_8 ( & V_72 -> V_72 , L_27 ) ;
return - V_15 ;
}
if ( ! V_218 ) {
V_218 = F_99 ( & V_72 -> V_72 , sizeof( * V_218 ) , V_262 ) ;
if ( ! V_218 )
return - V_118 ;
}
V_2 = F_100 ( sizeof( struct V_3 ) , & V_72 -> V_72 ) ;
if ( ! V_2 )
return - V_118 ;
V_121 = F_95 ( V_251 , V_2 ) ;
if ( V_121 )
goto V_263;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_239 = F_101 ( V_72 ) ;
V_4 -> V_264 = F_102 ( V_72 ) ;
F_55 ( F_9 ( V_2 ) , L_28 , V_4 -> V_239 ) ;
F_55 ( F_9 ( V_2 ) , L_29 , V_4 -> V_264 ) ;
V_4 -> V_17 = F_103 ( & V_72 -> V_72 , NULL ) ;
if ( F_84 ( V_4 -> V_17 ) ) {
V_121 = F_104 ( V_4 -> V_17 ) ;
goto V_263;
}
V_121 = F_105 ( V_4 -> V_17 ) ;
if ( V_121 )
goto V_263;
if ( V_10 -> V_265 )
V_4 -> V_201 = F_66 ;
else
V_4 -> V_201 = F_65 ;
V_4 -> V_218 = V_218 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_31 = F_89 ( V_4 -> V_17 ) ;
if ( V_4 -> V_31 > V_10 -> V_266 ) {
V_121 = F_88 ( V_4 -> V_17 , V_10 -> V_266 ) ;
if ( V_121 < 0 )
goto V_267;
V_4 -> V_31 = F_89 ( V_4 -> V_17 ) ;
F_55 ( F_9 ( V_2 ) , L_30 ,
V_4 -> V_31 ) ;
}
V_4 -> V_96 = V_72 -> V_268 . V_269 ;
V_4 -> V_8 = F_106 ( & V_72 -> V_72 , & V_72 -> V_268 ) ;
if ( F_84 ( V_4 -> V_8 ) ) {
V_121 = F_104 ( V_4 -> V_8 ) ;
goto V_267;
}
if ( V_10 -> V_33 )
V_2 -> V_270 = F_18 ( V_4 -> V_31 , 257 ) ;
else if ( V_10 -> V_30 )
V_2 -> V_270 = F_107 ( V_4 -> V_17 , 100000 ) ;
else
V_2 -> V_270 = F_18 ( V_4 -> V_31 , 512 ) ;
if ( V_2 -> V_266 )
V_2 -> V_266 = V_10 -> V_30 ?
F_71 ( V_10 -> V_266 , V_2 -> V_266 ) :
F_71 ( V_4 -> V_31 , V_2 -> V_266 ) ;
else
V_2 -> V_266 = V_10 -> V_30 ?
V_271 : F_71 ( V_4 -> V_31 , V_271 ) ;
F_55 ( F_9 ( V_2 ) , L_31 , V_2 -> V_266 ) ;
V_121 = F_108 ( V_2 ) ;
if ( V_121 == - V_272 )
goto V_267;
if ( ! V_2 -> V_273 )
V_2 -> V_273 = V_218 -> V_274 ;
else if ( V_218 -> V_274 )
F_94 ( F_9 ( V_2 ) , L_32 ) ;
if ( ! V_251 ) {
if ( ! V_218 -> V_275 )
V_2 -> V_276 |= V_277 ;
V_2 -> V_276 |= V_278 ;
}
V_2 -> V_255 |= V_279 ;
if ( V_10 -> V_182 ) {
V_280 . V_281 = F_1 ;
if ( V_10 -> V_25 )
F_16 ( V_4 ,
V_4 -> V_10 -> V_25 ) ;
V_2 -> V_255 |= V_282 ;
V_2 -> V_283 = 0 ;
}
V_2 -> V_284 = & V_280 ;
V_2 -> V_285 |= V_286 ;
V_2 -> V_287 = V_288 ;
V_2 -> V_289 = ( 1 << V_10 -> V_290 ) - 1 ;
V_2 -> V_73 = V_2 -> V_289 ;
V_2 -> V_291 = 1 << 11 ;
V_2 -> V_292 = V_2 -> V_289 >> 11 ;
F_109 ( & V_4 -> V_7 ) ;
F_14 ( 0 , V_4 -> V_8 + V_55 ) ;
F_14 ( 0 , V_4 -> V_8 + V_57 ) ;
F_14 ( 0xfff , V_4 -> V_8 + V_186 ) ;
if ( ! V_251 ) {
V_121 = F_110 ( V_2 , L_33 , 0 , false , 0 , NULL ) ;
if ( V_121 < 0 ) {
if ( V_121 == - V_272 )
goto V_267;
else if ( F_111 ( V_218 -> V_293 ) ) {
V_121 = F_112 ( V_2 , V_218 -> V_293 , 0 ) ;
if ( V_121 )
goto V_267;
}
}
V_121 = F_113 ( V_2 , L_34 , 0 , false , 0 , NULL ) ;
if ( V_121 < 0 ) {
if ( V_121 == - V_272 )
goto V_267;
else if ( F_111 ( V_218 -> V_294 ) ) {
V_121 = F_114 ( V_2 , V_218 -> V_294 ) ;
if ( V_121 )
goto V_267;
}
}
}
V_121 = F_115 ( & V_72 -> V_72 , V_72 -> V_206 [ 0 ] , F_78 , V_295 ,
V_296 L_35 , V_4 ) ;
if ( V_121 )
goto V_267;
if ( ! V_72 -> V_206 [ 1 ] )
V_4 -> V_53 = true ;
else {
V_121 = F_115 ( & V_72 -> V_72 , V_72 -> V_206 [ 1 ] , F_73 ,
V_295 , V_296 L_36 , V_4 ) ;
if ( V_121 )
goto V_267;
}
F_14 ( V_297 , V_4 -> V_8 + V_55 ) ;
F_116 ( V_72 , V_2 ) ;
F_29 ( & V_72 -> V_72 , L_37 ,
F_117 ( V_2 ) , F_118 ( V_72 ) , F_101 ( V_72 ) ,
F_102 ( V_72 ) , ( unsigned long long ) V_72 -> V_268 . V_269 ,
V_72 -> V_206 [ 0 ] , V_72 -> V_206 [ 1 ] ) ;
F_26 ( V_4 ) ;
F_119 ( & V_72 -> V_72 , 50 ) ;
F_120 ( & V_72 -> V_72 ) ;
F_121 ( V_2 ) ;
F_122 ( & V_72 -> V_72 ) ;
return 0 ;
V_267:
F_123 ( V_4 -> V_17 ) ;
V_263:
F_124 ( V_2 ) ;
return V_121 ;
}
static int F_125 ( struct V_258 * V_72 )
{
struct V_1 * V_2 = F_126 ( V_72 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_127 ( & V_72 -> V_72 ) ;
F_128 ( V_2 ) ;
F_14 ( 0 , V_4 -> V_8 + V_55 ) ;
F_14 ( 0 , V_4 -> V_8 + V_57 ) ;
F_14 ( 0 , V_4 -> V_8 + V_50 ) ;
F_14 ( 0 , V_4 -> V_8 + V_26 ) ;
F_32 ( V_4 ) ;
F_123 ( V_4 -> V_17 ) ;
F_124 ( V_2 ) ;
}
return 0 ;
}
static void F_129 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
F_14 ( 0 , V_4 -> V_8 + V_55 ) ;
if ( V_4 -> V_10 -> V_298 ) {
F_14 ( 0 , V_4 -> V_8 + V_26 ) ;
F_14 ( 0 , V_4 -> V_8 + V_22 ) ;
F_14 ( 0 , V_4 -> V_8 + V_19 ) ;
}
F_10 ( V_4 ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_130 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
if ( V_4 -> V_10 -> V_298 ) {
F_14 ( V_4 -> V_18 , V_4 -> V_8 + V_19 ) ;
F_14 ( V_4 -> V_24 , V_4 -> V_8 + V_26 ) ;
F_14 ( V_4 -> V_21 , V_4 -> V_8 + V_22 ) ;
}
F_14 ( V_297 , V_4 -> V_8 + V_55 ) ;
F_10 ( V_4 ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
}
static int F_131 ( struct V_71 * V_72 )
{
struct V_258 * V_299 = F_132 ( V_72 ) ;
struct V_1 * V_2 = F_126 ( V_299 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_133 ( V_72 ) ;
F_129 ( V_4 ) ;
F_123 ( V_4 -> V_17 ) ;
}
return 0 ;
}
static int F_134 ( struct V_71 * V_72 )
{
struct V_258 * V_299 = F_132 ( V_72 ) ;
struct V_1 * V_2 = F_126 ( V_299 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_105 ( V_4 -> V_17 ) ;
F_130 ( V_4 ) ;
F_135 ( V_72 ) ;
}
return 0 ;
}
