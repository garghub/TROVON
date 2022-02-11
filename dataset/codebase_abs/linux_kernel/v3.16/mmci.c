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
if ( V_26 >= V_4 -> V_30 ) {
V_16 = V_31 ;
if ( V_28 -> V_32 )
V_16 |= V_33 ;
V_4 -> V_15 = V_4 -> V_30 ;
} else if ( V_28 -> V_32 ) {
V_16 = F_21 ( V_4 -> V_30 , V_26 ) - 2 ;
if ( V_16 >= 256 )
V_16 = 255 ;
V_4 -> V_15 = V_4 -> V_30 / ( V_16 + 2 ) ;
} else {
V_16 = V_4 -> V_30 / ( 2 * V_26 ) - 1 ;
if ( V_16 >= 256 )
V_16 = 255 ;
V_4 -> V_15 = V_4 -> V_30 / ( 2 * ( V_16 + 1 ) ) ;
}
V_16 |= V_28 -> V_34 ;
V_16 |= V_35 ;
}
V_4 -> V_2 -> V_36 = V_4 -> V_15 ;
if ( V_4 -> V_2 -> V_37 . V_38 == V_39 )
V_16 |= V_40 ;
if ( V_4 -> V_2 -> V_37 . V_38 == V_41 )
V_16 |= V_42 ;
if ( V_4 -> V_2 -> V_37 . V_43 == V_44 ||
V_4 -> V_2 -> V_37 . V_43 == V_45 )
V_16 |= V_33 ;
F_16 ( V_4 , V_16 ) ;
}
static void
F_22 ( struct V_3 * V_4 , struct V_46 * V_47 )
{
F_17 ( 0 , V_4 -> V_8 + V_48 ) ;
F_23 ( V_4 -> V_12 ) ;
V_4 -> V_47 = NULL ;
V_4 -> V_49 = NULL ;
F_24 ( V_4 -> V_2 , V_47 ) ;
F_8 ( F_4 ( V_4 -> V_2 ) ) ;
F_9 ( F_4 ( V_4 -> V_2 ) ) ;
}
static void F_25 ( struct V_3 * V_4 , unsigned int V_50 )
{
void T_2 * V_8 = V_4 -> V_8 ;
if ( V_4 -> V_51 ) {
unsigned int V_52 = F_6 ( V_8 + V_53 ) ;
V_52 &= ~ V_54 ;
V_52 |= V_50 ;
F_17 ( V_52 , V_8 + V_53 ) ;
}
F_17 ( V_50 , V_8 + V_55 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
F_19 ( V_4 , 0 ) ;
F_25 ( V_4 , 0 ) ;
V_4 -> V_12 = NULL ;
}
static void F_27 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
unsigned int V_5 = V_56 ;
if ( V_12 -> V_5 & V_57 )
V_5 |= V_58 ;
else
V_5 |= V_59 ;
F_28 ( & V_4 -> V_60 , V_12 -> V_61 , V_12 -> V_62 , V_5 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
const char * V_63 , * V_64 ;
T_3 V_50 ;
V_4 -> V_65 = F_30 ( F_4 ( V_4 -> V_2 ) , L_2 ) ;
V_4 -> V_66 = F_30 ( F_4 ( V_4 -> V_2 ) , L_3 ) ;
V_4 -> V_67 . V_68 = 1 ;
F_31 ( V_50 ) ;
F_32 ( V_69 , V_50 ) ;
if ( V_4 -> V_65 && ! V_4 -> V_66 )
V_4 -> V_66 = V_4 -> V_65 ;
if ( V_4 -> V_65 )
V_63 = F_33 ( V_4 -> V_65 ) ;
else
V_63 = L_4 ;
if ( V_4 -> V_66 )
V_64 = F_33 ( V_4 -> V_66 ) ;
else
V_64 = L_4 ;
F_34 ( F_4 ( V_4 -> V_2 ) , L_5 ,
V_63 , V_64 ) ;
if ( V_4 -> V_66 ) {
struct V_70 * V_71 = V_4 -> V_66 -> V_70 -> V_71 ;
unsigned int V_72 = F_35 ( V_71 ) ;
if ( V_72 < V_4 -> V_2 -> V_72 )
V_4 -> V_2 -> V_72 = V_72 ;
}
if ( V_4 -> V_65 ) {
struct V_70 * V_71 = V_4 -> V_65 -> V_70 -> V_71 ;
unsigned int V_72 = F_35 ( V_71 ) ;
if ( V_72 < V_4 -> V_2 -> V_72 )
V_4 -> V_2 -> V_72 = V_72 ;
}
}
static inline void F_36 ( struct V_3 * V_4 )
{
if ( V_4 -> V_65 )
F_37 ( V_4 -> V_65 ) ;
if ( V_4 -> V_66 )
F_37 ( V_4 -> V_66 ) ;
V_4 -> V_65 = V_4 -> V_66 = NULL ;
}
static void F_38 ( struct V_3 * V_4 )
{
F_12 ( F_4 ( V_4 -> V_2 ) , L_6 ) ;
F_39 ( V_4 -> V_73 ) ;
V_4 -> V_73 = NULL ;
V_4 -> V_74 = NULL ;
V_4 -> V_12 -> V_75 = 0 ;
}
static void F_40 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_76 * V_77 ;
enum V_78 V_79 ;
if ( V_12 -> V_5 & V_57 ) {
V_79 = V_80 ;
V_77 = V_4 -> V_65 ;
} else {
V_79 = V_81 ;
V_77 = V_4 -> V_66 ;
}
F_41 ( V_77 -> V_70 -> V_71 , V_12 -> V_61 , V_12 -> V_62 , V_79 ) ;
}
static void F_42 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
T_1 V_82 ;
int V_83 ;
for ( V_83 = 0 ; ; V_83 ++ ) {
V_82 = F_6 ( V_4 -> V_8 + V_9 ) ;
if ( ! ( V_82 & V_84 ) || V_83 >= 100 )
break;
F_14 ( 10 ) ;
}
if ( V_82 & V_84 ) {
F_38 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> error = - V_85 ;
}
if ( ! V_12 -> V_75 )
F_40 ( V_4 , V_12 ) ;
if ( V_82 & V_84 ) {
F_12 ( F_4 ( V_4 -> V_2 ) , L_7 ) ;
F_36 ( V_4 ) ;
}
V_4 -> V_73 = NULL ;
V_4 -> V_74 = NULL ;
}
static int F_43 ( struct V_3 * V_4 , struct V_11 * V_12 ,
struct V_76 * * V_76 ,
struct V_86 * * V_87 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
struct V_88 V_89 = {
. V_90 = V_4 -> V_91 + V_92 ,
. V_93 = V_4 -> V_91 + V_92 ,
. V_94 = V_95 ,
. V_96 = V_95 ,
. V_97 = V_28 -> V_98 >> 2 ,
. V_99 = V_28 -> V_98 >> 2 ,
. V_100 = false ,
} ;
struct V_76 * V_77 ;
struct V_101 * V_70 ;
struct V_86 * V_102 ;
enum V_78 V_103 ;
int V_104 ;
if ( V_12 -> V_5 & V_57 ) {
V_89 . V_105 = V_106 ;
V_103 = V_80 ;
V_77 = V_4 -> V_65 ;
} else {
V_89 . V_105 = V_107 ;
V_103 = V_81 ;
V_77 = V_4 -> V_66 ;
}
if ( ! V_77 )
return - V_14 ;
if ( V_12 -> V_13 * V_12 -> V_108 <= V_28 -> V_109 )
return - V_14 ;
V_70 = V_77 -> V_70 ;
V_104 = F_44 ( V_70 -> V_71 , V_12 -> V_61 , V_12 -> V_62 , V_103 ) ;
if ( V_104 == 0 )
return - V_14 ;
F_45 ( V_77 , & V_89 ) ;
V_102 = F_46 ( V_77 , V_12 -> V_61 , V_104 ,
V_89 . V_105 , V_110 ) ;
if ( ! V_102 )
goto V_111;
* V_76 = V_77 ;
* V_87 = V_102 ;
return 0 ;
V_111:
F_41 ( V_70 -> V_71 , V_12 -> V_61 , V_12 -> V_62 , V_103 ) ;
return - V_112 ;
}
static inline int F_47 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
if ( V_4 -> V_73 && V_4 -> V_74 )
return 0 ;
return F_43 ( V_4 , V_12 , & V_4 -> V_73 ,
& V_4 -> V_74 ) ;
}
static inline int F_48 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_113 * V_114 = & V_4 -> V_67 ;
return F_43 ( V_4 , V_12 , & V_114 -> V_76 , & V_114 -> V_87 ) ;
}
static int F_49 ( struct V_3 * V_4 , unsigned int V_22 )
{
int V_115 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_115 = F_47 ( V_4 , V_4 -> V_12 ) ;
if ( V_115 )
return V_115 ;
F_50 ( F_4 ( V_4 -> V_2 ) ,
L_8 ,
V_12 -> V_62 , V_12 -> V_13 , V_12 -> V_108 , V_12 -> V_5 ) ;
F_51 ( V_4 -> V_74 ) ;
F_52 ( V_4 -> V_73 ) ;
V_22 |= V_116 ;
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_4 -> V_8 + V_53 ) | V_117 ,
V_4 -> V_8 + V_53 ) ;
return 0 ;
}
static void F_53 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_113 * V_118 = & V_4 -> V_67 ;
F_54 ( V_12 -> V_75 && V_12 -> V_75 != V_118 -> V_68 ) ;
F_54 ( ! V_12 -> V_75 && ( V_118 -> V_87 || V_118 -> V_76 ) ) ;
V_4 -> V_74 = V_118 -> V_87 ;
V_4 -> V_73 = V_118 -> V_76 ;
V_118 -> V_87 = NULL ;
V_118 -> V_76 = NULL ;
}
static void F_55 ( struct V_1 * V_2 , struct V_46 * V_47 ,
bool V_119 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_47 -> V_12 ;
struct V_113 * V_114 = & V_4 -> V_67 ;
if ( ! V_12 )
return;
F_23 ( V_12 -> V_75 ) ;
if ( F_10 ( V_4 , V_12 ) )
return;
if ( ! F_48 ( V_4 , V_12 ) )
V_12 -> V_75 = ++ V_114 -> V_68 < 0 ? 1 : V_114 -> V_68 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_46 * V_47 ,
int V_120 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_47 -> V_12 ;
if ( ! V_12 || ! V_12 -> V_75 )
return;
F_40 ( V_4 , V_12 ) ;
if ( V_120 ) {
struct V_113 * V_118 = & V_4 -> V_67 ;
struct V_76 * V_77 ;
if ( V_12 -> V_5 & V_57 )
V_77 = V_4 -> V_65 ;
else
V_77 = V_4 -> V_66 ;
F_39 ( V_77 ) ;
V_118 -> V_87 = NULL ;
V_118 -> V_76 = NULL ;
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
return - V_121 ;
}
static void F_57 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
unsigned int V_22 , V_122 , V_123 ;
unsigned long long V_124 ;
void T_2 * V_8 ;
int V_125 ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_9 ,
V_12 -> V_13 , V_12 -> V_108 , V_12 -> V_5 ) ;
V_4 -> V_12 = V_12 ;
V_4 -> V_126 = V_12 -> V_13 * V_12 -> V_108 ;
V_12 -> V_127 = 0 ;
V_124 = ( unsigned long long ) V_12 -> V_128 * V_4 -> V_15 ;
F_59 ( V_124 , 1000000000UL ) ;
V_122 = V_12 -> V_129 + ( unsigned int ) V_124 ;
V_8 = V_4 -> V_8 ;
F_17 ( V_122 , V_8 + V_130 ) ;
F_17 ( V_4 -> V_126 , V_8 + V_131 ) ;
V_125 = F_60 ( V_12 -> V_13 ) - 1 ;
F_23 ( 1 << V_125 != V_12 -> V_13 ) ;
if ( V_28 -> V_132 )
V_22 = V_133 | ( V_12 -> V_13 << 16 ) ;
else
V_22 = V_133 | V_125 << 4 ;
if ( V_12 -> V_5 & V_57 )
V_22 |= V_134 ;
if ( V_28 -> V_135 && V_4 -> V_2 -> V_136 )
if ( F_61 ( V_4 -> V_2 -> V_136 ) ) {
T_1 V_16 ;
V_22 |= V_137 ;
if ( V_12 -> V_5 & V_138 &&
( V_4 -> V_126 < 8 ||
( V_4 -> V_126 <= 8 && V_4 -> V_30 > 50000000 ) ) )
V_16 = V_4 -> V_17 & ~ V_28 -> V_34 ;
else
V_16 = V_4 -> V_17 | V_28 -> V_34 ;
F_16 ( V_4 , V_16 ) ;
}
if ( V_4 -> V_2 -> V_37 . V_43 == V_44 ||
V_4 -> V_2 -> V_37 . V_43 == V_45 )
V_22 |= V_139 ;
if ( ! F_49 ( V_4 , V_22 ) )
return;
F_27 ( V_4 , V_12 ) ;
if ( V_12 -> V_5 & V_57 ) {
V_123 = V_140 ;
if ( V_4 -> V_126 < V_28 -> V_98 )
V_123 |= V_84 ;
} else {
V_123 = V_141 ;
}
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_8 + V_53 ) & ~ V_117 , V_8 + V_53 ) ;
F_25 ( V_4 , V_123 ) ;
}
static void
F_62 ( struct V_3 * V_4 , struct V_142 * V_49 , T_1 V_143 )
{
void T_2 * V_8 = V_4 -> V_8 ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_10 ,
V_49 -> V_144 , V_49 -> V_145 , V_49 -> V_5 ) ;
if ( F_6 ( V_8 + V_48 ) & V_146 ) {
F_17 ( 0 , V_8 + V_48 ) ;
F_14 ( 1 ) ;
}
V_143 |= V_49 -> V_144 | V_146 ;
if ( V_49 -> V_5 & V_147 ) {
if ( V_49 -> V_5 & V_148 )
V_143 |= V_149 ;
V_143 |= V_150 ;
}
if ( 0 )
V_143 |= V_151 ;
V_4 -> V_49 = V_49 ;
F_17 ( V_49 -> V_145 , V_8 + V_152 ) ;
F_17 ( V_143 , V_8 + V_48 ) ;
}
static void
F_63 ( struct V_3 * V_4 , struct V_11 * V_12 ,
unsigned int V_82 )
{
if ( V_82 & ( V_153 | V_154 | V_155 |
V_156 | V_157 ) ) {
T_1 V_158 , V_159 ;
if ( F_64 ( V_4 ) ) {
F_38 ( V_4 ) ;
F_40 ( V_4 , V_12 ) ;
}
V_158 = F_6 ( V_4 -> V_8 + V_160 ) ;
V_159 = V_12 -> V_13 * V_12 -> V_108 - V_158 ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_11 ,
V_82 , V_159 ) ;
if ( V_82 & V_153 ) {
V_159 -= 1 ;
V_12 -> error = - V_161 ;
} else if ( V_82 & V_154 ) {
V_12 -> error = - V_162 ;
} else if ( V_82 & V_155 ) {
V_12 -> error = - V_163 ;
} else if ( V_82 & V_156 ) {
V_12 -> error = - V_85 ;
} else if ( V_82 & V_157 ) {
if ( V_159 > V_4 -> V_28 -> V_109 )
V_159 -= V_4 -> V_28 -> V_109 ;
else
V_159 = 0 ;
V_12 -> error = - V_85 ;
}
V_12 -> V_127 = F_65 ( V_159 , V_12 -> V_13 ) ;
}
if ( V_82 & V_164 )
F_12 ( F_4 ( V_4 -> V_2 ) , L_12 ) ;
if ( V_82 & V_165 || V_12 -> error ) {
if ( F_64 ( V_4 ) )
F_42 ( V_4 , V_12 ) ;
F_26 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> V_127 = V_12 -> V_13 * V_12 -> V_108 ;
if ( ! V_12 -> V_166 || V_4 -> V_47 -> V_167 ) {
F_22 ( V_4 , V_12 -> V_47 ) ;
} else {
F_62 ( V_4 , V_12 -> V_166 , 0 ) ;
}
}
}
static void
F_66 ( struct V_3 * V_4 , struct V_142 * V_49 ,
unsigned int V_82 )
{
void T_2 * V_8 = V_4 -> V_8 ;
bool V_167 = ( V_49 == V_4 -> V_47 -> V_167 ) ;
bool V_168 = V_4 -> V_28 -> V_169 &&
( V_49 -> V_5 & V_170 ) ;
if ( V_4 -> V_171 && ( V_82 & V_10 ) )
return;
if ( ! V_4 -> V_171 && V_168 &&
! ( V_82 & ( V_172 | V_173 ) ) &&
( F_6 ( V_8 + V_9 ) & V_10 ) ) {
F_17 ( F_6 ( V_8 + V_53 ) | V_174 ,
V_8 + V_53 ) ;
V_4 -> V_171 = V_82 & ( V_175 | V_176 ) ;
return;
}
if ( V_4 -> V_171 ) {
F_17 ( F_6 ( V_8 + V_53 ) & ~ V_174 ,
V_8 + V_53 ) ;
V_4 -> V_171 = 0 ;
}
V_4 -> V_49 = NULL ;
if ( V_82 & V_173 ) {
V_49 -> error = - V_162 ;
} else if ( V_82 & V_172 && V_49 -> V_5 & V_177 ) {
V_49 -> error = - V_161 ;
} else {
V_49 -> V_178 [ 0 ] = F_6 ( V_8 + V_179 ) ;
V_49 -> V_178 [ 1 ] = F_6 ( V_8 + V_180 ) ;
V_49 -> V_178 [ 2 ] = F_6 ( V_8 + V_181 ) ;
V_49 -> V_178 [ 3 ] = F_6 ( V_8 + V_182 ) ;
}
if ( ( ! V_167 && ! V_49 -> V_12 ) || V_49 -> error ) {
if ( V_4 -> V_12 ) {
if ( F_64 ( V_4 ) ) {
F_38 ( V_4 ) ;
F_40 ( V_4 , V_4 -> V_12 ) ;
}
F_26 ( V_4 ) ;
}
F_22 ( V_4 , V_4 -> V_47 ) ;
} else if ( V_167 ) {
F_62 ( V_4 , V_4 -> V_47 -> V_49 , 0 ) ;
} else if ( ! ( V_49 -> V_12 -> V_5 & V_57 ) ) {
F_57 ( V_4 , V_49 -> V_12 ) ;
}
}
static int F_67 ( struct V_3 * V_4 , char * V_183 , unsigned int V_158 )
{
void T_2 * V_8 = V_4 -> V_8 ;
char * V_184 = V_183 ;
T_1 V_82 ;
int V_185 = V_4 -> V_126 ;
do {
int V_186 = V_185 - ( F_6 ( V_8 + V_187 ) << 2 ) ;
if ( V_186 > V_158 )
V_186 = V_158 ;
if ( V_186 <= 0 )
break;
if ( F_68 ( V_186 & 0x3 ) ) {
if ( V_186 < 4 ) {
unsigned char V_188 [ 4 ] ;
F_69 ( V_8 + V_92 , V_188 , 1 ) ;
memcpy ( V_184 , V_188 , V_186 ) ;
} else {
F_69 ( V_8 + V_92 , V_184 , V_186 >> 2 ) ;
V_186 &= ~ 0x3 ;
}
} else {
F_69 ( V_8 + V_92 , V_184 , V_186 >> 2 ) ;
}
V_184 += V_186 ;
V_158 -= V_186 ;
V_185 -= V_186 ;
if ( V_158 == 0 )
break;
V_82 = F_6 ( V_8 + V_9 ) ;
} while ( V_82 & V_189 );
return V_184 - V_183 ;
}
static int F_70 ( struct V_3 * V_4 , char * V_183 , unsigned int V_158 , T_1 V_82 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
char * V_184 = V_183 ;
do {
unsigned int V_186 , V_190 ;
V_190 = V_82 & V_191 ?
V_28 -> V_109 : V_28 -> V_98 ;
V_186 = F_71 ( V_158 , V_190 ) ;
F_72 ( V_8 + V_92 , V_184 , ( V_186 + 3 ) >> 2 ) ;
V_184 += V_186 ;
V_158 -= V_186 ;
if ( V_158 == 0 )
break;
V_82 = F_6 ( V_8 + V_9 ) ;
} while ( V_82 & V_192 );
return V_184 - V_183 ;
}
static T_4 F_73 ( int V_193 , void * V_194 )
{
struct V_3 * V_4 = V_194 ;
struct V_195 * V_60 = & V_4 -> V_60 ;
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
unsigned long V_5 ;
T_1 V_82 ;
V_82 = F_6 ( V_8 + V_9 ) ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_13 , V_82 ) ;
F_74 ( V_5 ) ;
do {
unsigned int V_158 , V_196 ;
char * V_183 ;
if ( ! ( V_82 & ( V_192 | V_189 ) ) )
break;
if ( ! F_75 ( V_60 ) )
break;
V_183 = V_60 -> V_197 ;
V_158 = V_60 -> V_198 ;
V_196 = 0 ;
if ( V_82 & V_199 )
V_196 = F_67 ( V_4 , V_183 , V_158 ) ;
if ( V_82 & V_200 )
V_196 = F_70 ( V_4 , V_183 , V_158 , V_82 ) ;
V_60 -> V_201 = V_196 ;
V_4 -> V_126 -= V_196 ;
V_158 -= V_196 ;
if ( V_158 )
break;
V_82 = F_6 ( V_8 + V_9 ) ;
} while ( 1 );
F_76 ( V_60 ) ;
F_77 ( V_5 ) ;
if ( V_82 & V_199 && V_4 -> V_126 < V_28 -> V_98 )
F_25 ( V_4 , V_84 ) ;
if ( V_4 -> V_126 == 0 ) {
F_25 ( V_4 , 0 ) ;
F_17 ( F_6 ( V_8 + V_53 ) | V_117 , V_8 + V_53 ) ;
}
return V_202 ;
}
static T_4 F_78 ( int V_193 , void * V_194 )
{
struct V_3 * V_4 = V_194 ;
T_1 V_82 ;
int V_115 = 0 ;
F_79 ( & V_4 -> V_7 ) ;
do {
struct V_142 * V_49 ;
struct V_11 * V_12 ;
V_82 = F_6 ( V_4 -> V_8 + V_9 ) ;
if ( V_4 -> V_51 ) {
if ( V_82 & F_6 ( V_4 -> V_8 + V_55 ) )
F_73 ( V_193 , V_194 ) ;
V_82 &= ~ V_54 ;
}
V_82 &= F_6 ( V_4 -> V_8 + V_53 ) ;
F_17 ( V_82 , V_4 -> V_8 + V_203 ) ;
F_58 ( F_4 ( V_4 -> V_2 ) , L_14 , V_82 ) ;
V_49 = V_4 -> V_49 ;
if ( ( V_82 | V_4 -> V_171 ) & ( V_172 | V_173 |
V_175 | V_176 ) && V_49 )
F_66 ( V_4 , V_49 , V_82 ) ;
V_12 = V_4 -> V_12 ;
if ( V_82 & ( V_153 | V_154 | V_155 |
V_156 | V_157 | V_165 |
V_164 ) && V_12 )
F_63 ( V_4 , V_12 , V_82 ) ;
if ( V_4 -> V_171 )
V_82 &= ~ V_10 ;
V_115 = 1 ;
} while ( V_82 );
F_80 ( & V_4 -> V_7 ) ;
return F_81 ( V_115 ) ;
}
static void F_82 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_54 ( V_4 -> V_47 != NULL ) ;
V_47 -> V_49 -> error = F_10 ( V_4 , V_47 -> V_12 ) ;
if ( V_47 -> V_49 -> error ) {
F_24 ( V_2 , V_47 ) ;
return;
}
F_3 ( F_4 ( V_2 ) ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
V_4 -> V_47 = V_47 ;
if ( V_47 -> V_12 )
F_53 ( V_4 , V_47 -> V_12 ) ;
if ( V_47 -> V_12 && V_47 -> V_12 -> V_5 & V_57 )
F_57 ( V_4 , V_47 -> V_12 ) ;
if ( V_47 -> V_167 )
F_62 ( V_4 , V_47 -> V_167 , 0 ) ;
else
F_62 ( V_4 , V_47 -> V_49 , 0 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_204 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_4 -> V_28 ;
T_1 V_19 = 0 ;
unsigned long V_5 ;
int V_115 ;
F_3 ( F_4 ( V_2 ) ) ;
if ( V_4 -> V_205 -> V_206 &&
V_4 -> V_205 -> V_206 ( F_4 ( V_2 ) , V_37 ) )
F_12 ( F_4 ( V_2 ) , L_15 ) ;
switch ( V_37 -> V_207 ) {
case V_208 :
if ( ! F_84 ( V_2 -> V_209 . V_210 ) )
F_85 ( V_2 , V_2 -> V_209 . V_210 , 0 ) ;
if ( ! F_84 ( V_2 -> V_209 . V_211 ) && V_4 -> V_212 ) {
F_86 ( V_2 -> V_209 . V_211 ) ;
V_4 -> V_212 = false ;
}
break;
case V_213 :
if ( ! F_84 ( V_2 -> V_209 . V_210 ) )
F_85 ( V_2 , V_2 -> V_209 . V_210 , V_37 -> V_214 ) ;
V_19 |= V_28 -> V_215 ;
break;
case V_216 :
if ( ! F_84 ( V_2 -> V_209 . V_211 ) && ! V_4 -> V_212 ) {
V_115 = F_87 ( V_2 -> V_209 . V_211 ) ;
if ( V_115 < 0 )
F_12 ( F_4 ( V_2 ) ,
L_16 ) ;
else
V_4 -> V_212 = true ;
}
V_19 |= V_217 ;
break;
}
if ( V_28 -> V_218 && V_37 -> V_207 != V_208 ) {
V_19 |= V_4 -> V_219 ;
if ( V_37 -> V_38 == V_39 )
V_19 &= ~ V_220 ;
else if ( V_37 -> V_38 == V_221 )
V_19 &= ( ~ V_220 &
~ V_222 &
~ V_223 ) ;
}
if ( V_37 -> V_224 == V_225 ) {
if ( V_4 -> V_226 != V_227 )
V_19 |= V_228 ;
else {
V_19 |= V_229 ;
}
}
if ( ! V_37 -> clock && V_28 -> V_230 )
V_19 &= ~ V_217 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_20 ( V_4 , V_37 -> clock ) ;
F_18 ( V_4 , V_19 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_231 * V_205 = V_4 -> V_205 ;
unsigned int V_82 = F_89 ( V_2 ) ;
if ( V_82 == - V_121 ) {
if ( ! V_205 -> V_82 )
return 1 ;
V_82 = V_205 -> V_82 ( F_4 ( V_4 -> V_2 ) ) ;
}
return V_82 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_204 * V_37 )
{
int V_115 = 0 ;
if ( ! F_84 ( V_2 -> V_209 . V_211 ) ) {
F_3 ( F_4 ( V_2 ) ) ;
switch ( V_37 -> V_232 ) {
case V_233 :
V_115 = F_91 ( V_2 -> V_209 . V_211 ,
2700000 , 3600000 ) ;
break;
case V_234 :
V_115 = F_91 ( V_2 -> V_209 . V_211 ,
1700000 , 1950000 ) ;
break;
case V_235 :
V_115 = F_91 ( V_2 -> V_209 . V_211 ,
1100000 , 1300000 ) ;
break;
}
if ( V_115 )
F_92 ( F_4 ( V_2 ) , L_17 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
}
return V_115 ;
}
static int F_93 ( struct V_236 * V_237 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_115 = F_94 ( V_2 ) ;
if ( V_115 )
return V_115 ;
if ( F_95 ( V_237 , L_18 , NULL ) )
V_4 -> V_219 |= V_238 ;
if ( F_95 ( V_237 , L_19 , NULL ) )
V_4 -> V_219 |= V_223 ;
if ( F_95 ( V_237 , L_20 , NULL ) )
V_4 -> V_219 |= V_222 ;
if ( F_95 ( V_237 , L_21 , NULL ) )
V_4 -> V_219 |= V_220 ;
if ( F_95 ( V_237 , L_22 , NULL ) )
V_4 -> V_219 |= V_239 ;
if ( F_95 ( V_237 , L_23 , NULL ) )
V_4 -> V_219 |= V_240 ;
if ( F_95 ( V_237 , L_24 , NULL ) )
V_2 -> V_241 |= V_242 ;
if ( F_95 ( V_237 , L_25 , NULL ) )
V_2 -> V_241 |= V_243 ;
return 0 ;
}
static int F_96 ( struct V_244 * V_71 ,
const struct V_245 * V_246 )
{
struct V_231 * V_205 = V_71 -> V_71 . V_247 ;
struct V_236 * V_237 = V_71 -> V_71 . V_248 ;
struct V_27 * V_28 = V_246 -> V_12 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_115 ;
if ( ! V_205 && ! V_237 ) {
F_12 ( & V_71 -> V_71 , L_26 ) ;
return - V_14 ;
}
if ( ! V_205 ) {
V_205 = F_97 ( & V_71 -> V_71 , sizeof( * V_205 ) , V_249 ) ;
if ( ! V_205 )
return - V_112 ;
}
V_2 = F_98 ( sizeof( struct V_3 ) , & V_71 -> V_71 ) ;
if ( ! V_2 )
return - V_112 ;
V_115 = F_93 ( V_237 , V_2 ) ;
if ( V_115 )
goto V_250;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_226 = F_99 ( V_71 ) ;
V_4 -> V_251 = F_100 ( V_71 ) ;
F_58 ( F_4 ( V_2 ) , L_27 , V_4 -> V_226 ) ;
F_58 ( F_4 ( V_2 ) , L_28 , V_4 -> V_251 ) ;
V_4 -> V_16 = F_101 ( & V_71 -> V_71 , NULL ) ;
if ( F_84 ( V_4 -> V_16 ) ) {
V_115 = F_102 ( V_4 -> V_16 ) ;
goto V_250;
}
V_115 = F_103 ( V_4 -> V_16 ) ;
if ( V_115 )
goto V_250;
V_4 -> V_205 = V_205 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_30 = F_104 ( V_4 -> V_16 ) ;
if ( V_4 -> V_30 > 100000000 ) {
V_115 = F_105 ( V_4 -> V_16 , 100000000 ) ;
if ( V_115 < 0 )
goto V_252;
V_4 -> V_30 = F_104 ( V_4 -> V_16 ) ;
F_58 ( F_4 ( V_2 ) , L_29 ,
V_4 -> V_30 ) ;
}
V_4 -> V_91 = V_71 -> V_253 . V_254 ;
V_4 -> V_8 = F_106 ( & V_71 -> V_71 , & V_71 -> V_253 ) ;
if ( F_84 ( V_4 -> V_8 ) ) {
V_115 = F_102 ( V_4 -> V_8 ) ;
goto V_252;
}
if ( V_28 -> V_32 )
V_2 -> V_255 = F_21 ( V_4 -> V_30 , 257 ) ;
else
V_2 -> V_255 = F_21 ( V_4 -> V_30 , 512 ) ;
if ( V_2 -> V_256 )
V_2 -> V_256 = F_71 ( V_4 -> V_30 , V_2 -> V_256 ) ;
else
V_2 -> V_256 = F_71 ( V_4 -> V_30 , V_257 ) ;
F_58 ( F_4 ( V_2 ) , L_30 , V_2 -> V_256 ) ;
F_107 ( V_2 ) ;
if ( ! V_2 -> V_258 )
V_2 -> V_258 = V_205 -> V_259 ;
else if ( V_205 -> V_259 )
F_92 ( F_4 ( V_2 ) , L_31 ) ;
if ( ! V_237 ) {
if ( ! V_205 -> V_260 )
V_2 -> V_261 |= V_262 ;
V_2 -> V_261 |= V_263 ;
}
V_2 -> V_241 |= V_264 ;
if ( V_28 -> V_169 ) {
V_265 . V_266 = F_1 ;
F_19 ( V_4 , V_24 ) ;
V_2 -> V_241 |= V_267 ;
V_2 -> V_268 = 0 ;
}
V_2 -> V_269 = & V_265 ;
V_2 -> V_270 |= V_271 ;
V_2 -> V_272 = V_273 ;
V_2 -> V_274 = ( 1 << V_28 -> V_275 ) - 1 ;
V_2 -> V_72 = V_2 -> V_274 ;
V_2 -> V_276 = 1 << 11 ;
V_2 -> V_277 = V_2 -> V_274 >> 11 ;
F_108 ( & V_4 -> V_7 ) ;
F_17 ( 0 , V_4 -> V_8 + V_53 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
F_17 ( 0xfff , V_4 -> V_8 + V_203 ) ;
if ( ! V_237 && F_109 ( V_205 -> V_278 ) ) {
V_115 = F_110 ( V_2 , V_205 -> V_278 , 0 ) ;
if ( V_115 )
goto V_252;
}
if ( ! V_237 && F_109 ( V_205 -> V_279 ) ) {
V_115 = F_111 ( V_2 , V_205 -> V_279 ) ;
if ( V_115 )
goto V_252;
}
V_115 = F_112 ( & V_71 -> V_71 , V_71 -> V_193 [ 0 ] , F_78 , V_280 ,
V_281 L_32 , V_4 ) ;
if ( V_115 )
goto V_252;
if ( ! V_71 -> V_193 [ 1 ] )
V_4 -> V_51 = true ;
else {
V_115 = F_112 ( & V_71 -> V_71 , V_71 -> V_193 [ 1 ] , F_73 ,
V_280 , V_281 L_33 , V_4 ) ;
if ( V_115 )
goto V_252;
}
F_17 ( V_282 , V_4 -> V_8 + V_53 ) ;
F_113 ( V_71 , V_2 ) ;
F_34 ( & V_71 -> V_71 , L_34 ,
F_114 ( V_2 ) , F_115 ( V_71 ) , F_99 ( V_71 ) ,
F_100 ( V_71 ) , ( unsigned long long ) V_71 -> V_253 . V_254 ,
V_71 -> V_193 [ 0 ] , V_71 -> V_193 [ 1 ] ) ;
F_29 ( V_4 ) ;
F_116 ( & V_71 -> V_71 , 50 ) ;
F_117 ( & V_71 -> V_71 ) ;
F_118 ( & V_71 -> V_71 ) ;
F_119 ( V_2 ) ;
return 0 ;
V_252:
F_120 ( V_4 -> V_16 ) ;
V_250:
F_121 ( V_2 ) ;
return V_115 ;
}
static int F_122 ( struct V_244 * V_71 )
{
struct V_1 * V_2 = F_123 ( V_71 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_71 -> V_71 ) ;
F_124 ( V_2 ) ;
F_17 ( 0 , V_4 -> V_8 + V_53 ) ;
F_17 ( 0 , V_4 -> V_8 + V_55 ) ;
F_17 ( 0 , V_4 -> V_8 + V_48 ) ;
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_36 ( V_4 ) ;
F_120 ( V_4 -> V_16 ) ;
F_121 ( V_2 ) ;
}
return 0 ;
}
static void F_125 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_17 ( 0 , V_4 -> V_8 + V_53 ) ;
if ( V_4 -> V_28 -> V_283 ) {
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_17 ( 0 , V_4 -> V_8 + V_21 ) ;
F_17 ( 0 , V_4 -> V_8 + V_18 ) ;
}
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_126 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
if ( V_4 -> V_28 -> V_283 ) {
F_17 ( V_4 -> V_17 , V_4 -> V_8 + V_18 ) ;
F_17 ( V_4 -> V_23 , V_4 -> V_8 + V_25 ) ;
F_17 ( V_4 -> V_20 , V_4 -> V_8 + V_21 ) ;
}
F_17 ( V_282 , V_4 -> V_8 + V_53 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static int F_127 ( struct V_70 * V_71 )
{
struct V_244 * V_284 = F_128 ( V_71 ) ;
struct V_1 * V_2 = F_123 ( V_284 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_129 ( V_71 ) ;
F_125 ( V_4 ) ;
F_120 ( V_4 -> V_16 ) ;
}
return 0 ;
}
static int F_130 ( struct V_70 * V_71 )
{
struct V_244 * V_284 = F_128 ( V_71 ) ;
struct V_1 * V_2 = F_123 ( V_284 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_103 ( V_4 -> V_16 ) ;
F_126 ( V_4 ) ;
F_131 ( V_71 ) ;
}
return 0 ;
}
