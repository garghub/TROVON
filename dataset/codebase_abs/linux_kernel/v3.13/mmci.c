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
if ( V_4 -> V_2 -> V_37 . V_43 == V_44 )
V_16 |= V_33 ;
F_16 ( V_4 , V_16 ) ;
}
static void
F_22 ( struct V_3 * V_4 , struct V_45 * V_46 )
{
F_17 ( 0 , V_4 -> V_8 + V_47 ) ;
F_23 ( V_4 -> V_12 ) ;
V_4 -> V_46 = NULL ;
V_4 -> V_48 = NULL ;
F_24 ( V_4 -> V_2 , V_46 ) ;
F_8 ( F_4 ( V_4 -> V_2 ) ) ;
F_9 ( F_4 ( V_4 -> V_2 ) ) ;
}
static void F_25 ( struct V_3 * V_4 , unsigned int V_49 )
{
void T_2 * V_8 = V_4 -> V_8 ;
if ( V_4 -> V_50 ) {
unsigned int V_51 = F_6 ( V_8 + V_52 ) ;
V_51 &= ~ V_53 ;
V_51 |= V_49 ;
F_17 ( V_51 , V_8 + V_52 ) ;
}
F_17 ( V_49 , V_8 + V_54 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
F_19 ( V_4 , 0 ) ;
F_25 ( V_4 , 0 ) ;
V_4 -> V_12 = NULL ;
}
static void F_27 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
unsigned int V_5 = V_55 ;
if ( V_12 -> V_5 & V_56 )
V_5 |= V_57 ;
else
V_5 |= V_58 ;
F_28 ( & V_4 -> V_59 , V_12 -> V_60 , V_12 -> V_61 , V_5 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
struct V_62 * V_63 = V_4 -> V_63 ;
const char * V_64 , * V_65 ;
T_3 V_49 ;
V_4 -> V_66 = F_30 ( F_4 ( V_4 -> V_2 ) , L_2 ) ;
V_4 -> V_67 = F_30 ( F_4 ( V_4 -> V_2 ) , L_3 ) ;
V_4 -> V_68 . V_69 = 1 ;
F_31 ( V_49 ) ;
F_32 ( V_70 , V_49 ) ;
if ( V_63 && V_63 -> V_71 ) {
if ( ! V_4 -> V_66 && V_63 -> V_72 ) {
V_4 -> V_66 = F_33 ( V_49 ,
V_63 -> V_71 ,
V_63 -> V_72 ) ;
if ( ! V_4 -> V_66 )
F_12 ( F_4 ( V_4 -> V_2 ) , L_4 ) ;
}
if ( ! V_4 -> V_67 && V_63 -> V_73 ) {
V_4 -> V_67 = F_33 ( V_49 ,
V_63 -> V_71 ,
V_63 -> V_73 ) ;
if ( ! V_4 -> V_67 )
F_34 ( F_4 ( V_4 -> V_2 ) , L_5 ) ;
}
}
if ( V_4 -> V_66 && ! V_4 -> V_67 )
V_4 -> V_67 = V_4 -> V_66 ;
if ( V_4 -> V_66 )
V_64 = F_35 ( V_4 -> V_66 ) ;
else
V_64 = L_6 ;
if ( V_4 -> V_67 )
V_65 = F_35 ( V_4 -> V_67 ) ;
else
V_65 = L_6 ;
F_36 ( F_4 ( V_4 -> V_2 ) , L_7 ,
V_64 , V_65 ) ;
if ( V_4 -> V_67 ) {
struct V_74 * V_75 = V_4 -> V_67 -> V_74 -> V_75 ;
unsigned int V_76 = F_37 ( V_75 ) ;
if ( V_76 < V_4 -> V_2 -> V_76 )
V_4 -> V_2 -> V_76 = V_76 ;
}
if ( V_4 -> V_66 ) {
struct V_74 * V_75 = V_4 -> V_66 -> V_74 -> V_75 ;
unsigned int V_76 = F_37 ( V_75 ) ;
if ( V_76 < V_4 -> V_2 -> V_76 )
V_4 -> V_2 -> V_76 = V_76 ;
}
}
static inline void F_38 ( struct V_3 * V_4 )
{
struct V_62 * V_63 = V_4 -> V_63 ;
if ( V_4 -> V_66 )
F_39 ( V_4 -> V_66 ) ;
if ( V_4 -> V_67 && V_63 -> V_73 )
F_39 ( V_4 -> V_67 ) ;
V_4 -> V_66 = V_4 -> V_67 = NULL ;
}
static void F_40 ( struct V_3 * V_4 )
{
F_12 ( F_4 ( V_4 -> V_2 ) , L_8 ) ;
F_41 ( V_4 -> V_77 ) ;
V_4 -> V_77 = NULL ;
V_4 -> V_78 = NULL ;
V_4 -> V_12 -> V_79 = 0 ;
}
static void F_42 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_80 * V_81 ;
enum V_82 V_83 ;
if ( V_12 -> V_5 & V_56 ) {
V_83 = V_84 ;
V_81 = V_4 -> V_66 ;
} else {
V_83 = V_85 ;
V_81 = V_4 -> V_67 ;
}
F_43 ( V_81 -> V_74 -> V_75 , V_12 -> V_60 , V_12 -> V_61 , V_83 ) ;
}
static void F_44 ( struct V_3 * V_4 , struct V_11 * V_12 )
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
F_40 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> error = - V_89 ;
}
if ( ! V_12 -> V_79 )
F_42 ( V_4 , V_12 ) ;
if ( V_86 & V_88 ) {
F_12 ( F_4 ( V_4 -> V_2 ) , L_9 ) ;
F_38 ( V_4 ) ;
}
V_4 -> V_77 = NULL ;
V_4 -> V_78 = NULL ;
}
static int F_45 ( struct V_3 * V_4 , struct V_11 * V_12 ,
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
struct V_105 * V_74 ;
struct V_90 * V_106 ;
enum V_82 V_107 ;
int V_108 ;
if ( V_12 -> V_5 & V_56 ) {
V_93 . V_109 = V_110 ;
V_107 = V_84 ;
V_81 = V_4 -> V_66 ;
} else {
V_93 . V_109 = V_111 ;
V_107 = V_85 ;
V_81 = V_4 -> V_67 ;
}
if ( ! V_81 )
return - V_14 ;
if ( V_12 -> V_13 * V_12 -> V_112 <= V_28 -> V_113 )
return - V_14 ;
V_74 = V_81 -> V_74 ;
V_108 = F_46 ( V_74 -> V_75 , V_12 -> V_60 , V_12 -> V_61 , V_107 ) ;
if ( V_108 == 0 )
return - V_14 ;
F_47 ( V_81 , & V_93 ) ;
V_106 = F_48 ( V_81 , V_12 -> V_60 , V_108 ,
V_93 . V_109 , V_114 ) ;
if ( ! V_106 )
goto V_115;
* V_80 = V_81 ;
* V_91 = V_106 ;
return 0 ;
V_115:
F_43 ( V_74 -> V_75 , V_12 -> V_60 , V_12 -> V_61 , V_107 ) ;
return - V_116 ;
}
static inline int F_49 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
if ( V_4 -> V_77 && V_4 -> V_78 )
return 0 ;
return F_45 ( V_4 , V_12 , & V_4 -> V_77 ,
& V_4 -> V_78 ) ;
}
static inline int F_50 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_117 * V_118 = & V_4 -> V_68 ;
return F_45 ( V_4 , V_12 , & V_118 -> V_80 , & V_118 -> V_91 ) ;
}
static int F_51 ( struct V_3 * V_4 , unsigned int V_22 )
{
int V_119 ;
struct V_11 * V_12 = V_4 -> V_12 ;
V_119 = F_49 ( V_4 , V_4 -> V_12 ) ;
if ( V_119 )
return V_119 ;
F_52 ( F_4 ( V_4 -> V_2 ) ,
L_10 ,
V_12 -> V_61 , V_12 -> V_13 , V_12 -> V_112 , V_12 -> V_5 ) ;
F_53 ( V_4 -> V_78 ) ;
F_54 ( V_4 -> V_77 ) ;
V_22 |= V_120 ;
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_4 -> V_8 + V_52 ) | V_121 ,
V_4 -> V_8 + V_52 ) ;
return 0 ;
}
static void F_55 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_117 * V_122 = & V_4 -> V_68 ;
F_56 ( V_12 -> V_79 && V_12 -> V_79 != V_122 -> V_69 ) ;
F_56 ( ! V_12 -> V_79 && ( V_122 -> V_91 || V_122 -> V_80 ) ) ;
V_4 -> V_78 = V_122 -> V_91 ;
V_4 -> V_77 = V_122 -> V_80 ;
V_122 -> V_91 = NULL ;
V_122 -> V_80 = NULL ;
}
static void F_57 ( struct V_1 * V_2 , struct V_45 * V_46 ,
bool V_123 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_46 -> V_12 ;
struct V_117 * V_118 = & V_4 -> V_68 ;
if ( ! V_12 )
return;
F_23 ( V_12 -> V_79 ) ;
if ( F_10 ( V_4 , V_12 ) )
return;
if ( ! F_50 ( V_4 , V_12 ) )
V_12 -> V_79 = ++ V_118 -> V_69 < 0 ? 1 : V_118 -> V_69 ;
}
static void F_58 ( struct V_1 * V_2 , struct V_45 * V_46 ,
int V_124 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_46 -> V_12 ;
if ( ! V_12 || ! V_12 -> V_79 )
return;
F_42 ( V_4 , V_12 ) ;
if ( V_124 ) {
struct V_117 * V_122 = & V_4 -> V_68 ;
struct V_80 * V_81 ;
if ( V_12 -> V_5 & V_56 )
V_81 = V_4 -> V_66 ;
else
V_81 = V_4 -> V_67 ;
F_41 ( V_81 ) ;
V_122 -> V_91 = NULL ;
V_122 -> V_80 = NULL ;
}
}
static void F_55 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
}
static inline void F_29 ( struct V_3 * V_4 )
{
}
static inline void F_38 ( struct V_3 * V_4 )
{
}
static inline void F_42 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
}
static inline void F_44 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
}
static inline void F_40 ( struct V_3 * V_4 )
{
}
static inline int F_51 ( struct V_3 * V_4 , unsigned int V_22 )
{
return - V_125 ;
}
static void F_59 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
unsigned int V_22 , V_126 , V_127 ;
unsigned long long V_128 ;
void T_2 * V_8 ;
int V_129 ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_11 ,
V_12 -> V_13 , V_12 -> V_112 , V_12 -> V_5 ) ;
V_4 -> V_12 = V_12 ;
V_4 -> V_130 = V_12 -> V_13 * V_12 -> V_112 ;
V_12 -> V_131 = 0 ;
V_128 = ( unsigned long long ) V_12 -> V_132 * V_4 -> V_15 ;
F_61 ( V_128 , 1000000000UL ) ;
V_126 = V_12 -> V_133 + ( unsigned int ) V_128 ;
V_8 = V_4 -> V_8 ;
F_17 ( V_126 , V_8 + V_134 ) ;
F_17 ( V_4 -> V_130 , V_8 + V_135 ) ;
V_129 = F_62 ( V_12 -> V_13 ) - 1 ;
F_23 ( 1 << V_129 != V_12 -> V_13 ) ;
if ( V_28 -> V_136 )
V_22 = V_137 | ( V_12 -> V_13 << 16 ) ;
else
V_22 = V_137 | V_129 << 4 ;
if ( V_12 -> V_5 & V_56 )
V_22 |= V_138 ;
if ( V_28 -> V_139 && V_4 -> V_2 -> V_140 )
if ( F_63 ( V_4 -> V_2 -> V_140 ) ) {
T_1 V_16 ;
V_22 |= V_141 ;
if ( V_12 -> V_5 & V_142 &&
( V_4 -> V_130 < 8 ||
( V_4 -> V_130 <= 8 && V_4 -> V_30 > 50000000 ) ) )
V_16 = V_4 -> V_17 & ~ V_28 -> V_34 ;
else
V_16 = V_4 -> V_17 | V_28 -> V_34 ;
F_16 ( V_4 , V_16 ) ;
}
if ( V_4 -> V_2 -> V_37 . V_43 == V_44 )
V_22 |= V_143 ;
if ( ! F_51 ( V_4 , V_22 ) )
return;
F_27 ( V_4 , V_12 ) ;
if ( V_12 -> V_5 & V_56 ) {
V_127 = V_144 ;
if ( V_4 -> V_130 < V_28 -> V_102 )
V_127 |= V_88 ;
} else {
V_127 = V_145 ;
}
F_19 ( V_4 , V_22 ) ;
F_17 ( F_6 ( V_8 + V_52 ) & ~ V_121 , V_8 + V_52 ) ;
F_25 ( V_4 , V_127 ) ;
}
static void
F_64 ( struct V_3 * V_4 , struct V_146 * V_48 , T_1 V_147 )
{
void T_2 * V_8 = V_4 -> V_8 ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_12 ,
V_48 -> V_148 , V_48 -> V_149 , V_48 -> V_5 ) ;
if ( F_6 ( V_8 + V_47 ) & V_150 ) {
F_17 ( 0 , V_8 + V_47 ) ;
F_14 ( 1 ) ;
}
V_147 |= V_48 -> V_148 | V_150 ;
if ( V_48 -> V_5 & V_151 ) {
if ( V_48 -> V_5 & V_152 )
V_147 |= V_153 ;
V_147 |= V_154 ;
}
if ( 0 )
V_147 |= V_155 ;
V_4 -> V_48 = V_48 ;
F_17 ( V_48 -> V_149 , V_8 + V_156 ) ;
F_17 ( V_147 , V_8 + V_47 ) ;
}
static void
F_65 ( struct V_3 * V_4 , struct V_11 * V_12 ,
unsigned int V_86 )
{
if ( V_86 & ( V_157 | V_158 | V_159 |
V_160 | V_161 ) ) {
T_1 V_162 , V_163 ;
if ( F_66 ( V_4 ) ) {
F_40 ( V_4 ) ;
F_42 ( V_4 , V_12 ) ;
}
V_162 = F_6 ( V_4 -> V_8 + V_164 ) ;
V_163 = V_12 -> V_13 * V_12 -> V_112 - V_162 ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_13 ,
V_86 , V_163 ) ;
if ( V_86 & V_157 ) {
V_163 -= 1 ;
V_12 -> error = - V_165 ;
} else if ( V_86 & V_158 ) {
V_12 -> error = - V_166 ;
} else if ( V_86 & V_159 ) {
V_12 -> error = - V_167 ;
} else if ( V_86 & V_160 ) {
V_12 -> error = - V_89 ;
} else if ( V_86 & V_161 ) {
if ( V_163 > V_4 -> V_28 -> V_113 )
V_163 -= V_4 -> V_28 -> V_113 ;
else
V_163 = 0 ;
V_12 -> error = - V_89 ;
}
V_12 -> V_131 = F_67 ( V_163 , V_12 -> V_13 ) ;
}
if ( V_86 & V_168 )
F_12 ( F_4 ( V_4 -> V_2 ) , L_14 ) ;
if ( V_86 & V_169 || V_12 -> error ) {
if ( F_66 ( V_4 ) )
F_44 ( V_4 , V_12 ) ;
F_26 ( V_4 ) ;
if ( ! V_12 -> error )
V_12 -> V_131 = V_12 -> V_13 * V_12 -> V_112 ;
if ( ! V_12 -> V_170 || V_4 -> V_46 -> V_171 ) {
F_22 ( V_4 , V_12 -> V_46 ) ;
} else {
F_64 ( V_4 , V_12 -> V_170 , 0 ) ;
}
}
}
static void
F_68 ( struct V_3 * V_4 , struct V_146 * V_48 ,
unsigned int V_86 )
{
void T_2 * V_8 = V_4 -> V_8 ;
bool V_171 = ( V_48 == V_4 -> V_46 -> V_171 ) ;
V_4 -> V_48 = NULL ;
if ( V_86 & V_172 ) {
V_48 -> error = - V_166 ;
} else if ( V_86 & V_173 && V_48 -> V_5 & V_174 ) {
V_48 -> error = - V_165 ;
} else {
V_48 -> V_175 [ 0 ] = F_6 ( V_8 + V_176 ) ;
V_48 -> V_175 [ 1 ] = F_6 ( V_8 + V_177 ) ;
V_48 -> V_175 [ 2 ] = F_6 ( V_8 + V_178 ) ;
V_48 -> V_175 [ 3 ] = F_6 ( V_8 + V_179 ) ;
}
if ( ( ! V_171 && ! V_48 -> V_12 ) || V_48 -> error ) {
if ( V_4 -> V_12 ) {
if ( F_66 ( V_4 ) ) {
F_40 ( V_4 ) ;
F_42 ( V_4 , V_4 -> V_12 ) ;
}
F_26 ( V_4 ) ;
}
F_22 ( V_4 , V_4 -> V_46 ) ;
} else if ( V_171 ) {
F_64 ( V_4 , V_4 -> V_46 -> V_48 , 0 ) ;
} else if ( ! ( V_48 -> V_12 -> V_5 & V_56 ) ) {
F_59 ( V_4 , V_48 -> V_12 ) ;
}
}
static int F_69 ( struct V_3 * V_4 , char * V_180 , unsigned int V_162 )
{
void T_2 * V_8 = V_4 -> V_8 ;
char * V_181 = V_180 ;
T_1 V_86 ;
int V_182 = V_4 -> V_130 ;
do {
int V_183 = V_182 - ( F_6 ( V_8 + V_184 ) << 2 ) ;
if ( V_183 > V_162 )
V_183 = V_162 ;
if ( V_183 <= 0 )
break;
if ( F_70 ( V_183 & 0x3 ) ) {
if ( V_183 < 4 ) {
unsigned char V_185 [ 4 ] ;
F_71 ( V_8 + V_96 , V_185 , 1 ) ;
memcpy ( V_181 , V_185 , V_183 ) ;
} else {
F_71 ( V_8 + V_96 , V_181 , V_183 >> 2 ) ;
V_183 &= ~ 0x3 ;
}
} else {
F_71 ( V_8 + V_96 , V_181 , V_183 >> 2 ) ;
}
V_181 += V_183 ;
V_162 -= V_183 ;
V_182 -= V_183 ;
if ( V_162 == 0 )
break;
V_86 = F_6 ( V_8 + V_9 ) ;
} while ( V_86 & V_186 );
return V_181 - V_180 ;
}
static int F_72 ( struct V_3 * V_4 , char * V_180 , unsigned int V_162 , T_1 V_86 )
{
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
char * V_181 = V_180 ;
do {
unsigned int V_183 , V_187 ;
V_187 = V_86 & V_188 ?
V_28 -> V_113 : V_28 -> V_102 ;
V_183 = F_73 ( V_162 , V_187 ) ;
F_74 ( V_8 + V_96 , V_181 , ( V_183 + 3 ) >> 2 ) ;
V_181 += V_183 ;
V_162 -= V_183 ;
if ( V_162 == 0 )
break;
V_86 = F_6 ( V_8 + V_9 ) ;
} while ( V_86 & V_189 );
return V_181 - V_180 ;
}
static T_4 F_75 ( int V_190 , void * V_191 )
{
struct V_3 * V_4 = V_191 ;
struct V_192 * V_59 = & V_4 -> V_59 ;
struct V_27 * V_28 = V_4 -> V_28 ;
void T_2 * V_8 = V_4 -> V_8 ;
unsigned long V_5 ;
T_1 V_86 ;
V_86 = F_6 ( V_8 + V_9 ) ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_15 , V_86 ) ;
F_76 ( V_5 ) ;
do {
unsigned int V_162 , V_193 ;
char * V_180 ;
if ( ! ( V_86 & ( V_189 | V_186 ) ) )
break;
if ( ! F_77 ( V_59 ) )
break;
V_180 = V_59 -> V_194 ;
V_162 = V_59 -> V_195 ;
V_193 = 0 ;
if ( V_86 & V_196 )
V_193 = F_69 ( V_4 , V_180 , V_162 ) ;
if ( V_86 & V_197 )
V_193 = F_72 ( V_4 , V_180 , V_162 , V_86 ) ;
V_59 -> V_198 = V_193 ;
V_4 -> V_130 -= V_193 ;
V_162 -= V_193 ;
if ( V_162 )
break;
V_86 = F_6 ( V_8 + V_9 ) ;
} while ( 1 );
F_78 ( V_59 ) ;
F_79 ( V_5 ) ;
if ( V_86 & V_196 && V_4 -> V_130 < V_28 -> V_102 )
F_25 ( V_4 , V_88 ) ;
if ( V_4 -> V_130 == 0 ) {
F_25 ( V_4 , 0 ) ;
F_17 ( F_6 ( V_8 + V_52 ) | V_121 , V_8 + V_52 ) ;
}
return V_199 ;
}
static T_4 F_80 ( int V_190 , void * V_191 )
{
struct V_3 * V_4 = V_191 ;
T_1 V_86 ;
int V_119 = 0 ;
F_81 ( & V_4 -> V_7 ) ;
do {
struct V_146 * V_48 ;
struct V_11 * V_12 ;
V_86 = F_6 ( V_4 -> V_8 + V_9 ) ;
if ( V_4 -> V_50 ) {
if ( V_86 & F_6 ( V_4 -> V_8 + V_54 ) )
F_75 ( V_190 , V_191 ) ;
V_86 &= ~ V_53 ;
}
V_86 &= F_6 ( V_4 -> V_8 + V_52 ) ;
F_17 ( V_86 , V_4 -> V_8 + V_200 ) ;
F_60 ( F_4 ( V_4 -> V_2 ) , L_16 , V_86 ) ;
V_12 = V_4 -> V_12 ;
if ( V_86 & ( V_157 | V_158 | V_159 |
V_160 | V_161 | V_169 |
V_168 ) && V_12 )
F_65 ( V_4 , V_12 , V_86 ) ;
V_48 = V_4 -> V_48 ;
if ( V_86 & ( V_173 | V_172 | V_201 | V_202 ) && V_48 )
F_68 ( V_4 , V_48 , V_86 ) ;
V_119 = 1 ;
} while ( V_86 );
F_82 ( & V_4 -> V_7 ) ;
return F_83 ( V_119 ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_56 ( V_4 -> V_46 != NULL ) ;
V_46 -> V_48 -> error = F_10 ( V_4 , V_46 -> V_12 ) ;
if ( V_46 -> V_48 -> error ) {
F_24 ( V_2 , V_46 ) ;
return;
}
F_3 ( F_4 ( V_2 ) ) ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
V_4 -> V_46 = V_46 ;
if ( V_46 -> V_12 )
F_55 ( V_4 , V_46 -> V_12 ) ;
if ( V_46 -> V_12 && V_46 -> V_12 -> V_5 & V_56 )
F_59 ( V_4 , V_46 -> V_12 ) ;
if ( V_46 -> V_171 )
F_64 ( V_4 , V_46 -> V_171 , 0 ) ;
else
F_64 ( V_4 , V_46 -> V_48 , 0 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
static void F_85 ( struct V_1 * V_2 , struct V_203 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = V_4 -> V_28 ;
T_1 V_19 = 0 ;
unsigned long V_5 ;
int V_119 ;
F_3 ( F_4 ( V_2 ) ) ;
if ( V_4 -> V_63 -> V_204 &&
V_4 -> V_63 -> V_204 ( F_4 ( V_2 ) , V_37 ) )
F_12 ( F_4 ( V_2 ) , L_17 ) ;
switch ( V_37 -> V_205 ) {
case V_206 :
if ( ! F_86 ( V_2 -> V_207 . V_208 ) )
F_87 ( V_2 , V_2 -> V_207 . V_208 , 0 ) ;
if ( ! F_86 ( V_2 -> V_207 . V_209 ) && V_4 -> V_210 ) {
F_88 ( V_2 -> V_207 . V_209 ) ;
V_4 -> V_210 = false ;
}
break;
case V_211 :
if ( ! F_86 ( V_2 -> V_207 . V_208 ) )
F_87 ( V_2 , V_2 -> V_207 . V_208 , V_37 -> V_212 ) ;
V_19 |= V_28 -> V_213 ;
break;
case V_214 :
if ( ! F_86 ( V_2 -> V_207 . V_209 ) && ! V_4 -> V_210 ) {
V_119 = F_89 ( V_2 -> V_207 . V_209 ) ;
if ( V_119 < 0 )
F_12 ( F_4 ( V_2 ) ,
L_18 ) ;
else
V_4 -> V_210 = true ;
}
V_19 |= V_215 ;
break;
}
if ( V_28 -> V_216 && V_37 -> V_205 != V_206 ) {
V_19 |= V_4 -> V_63 -> V_217 ;
if ( V_37 -> V_38 == V_39 )
V_19 &= ~ V_218 ;
else if ( V_37 -> V_38 == V_219 )
V_19 &= ( ~ V_218 &
~ V_220 &
~ V_221 ) ;
}
if ( V_37 -> V_222 == V_223 ) {
if ( V_4 -> V_224 != V_225 )
V_19 |= V_226 ;
else {
V_19 |= V_227 ;
}
}
if ( ! V_37 -> clock && V_28 -> V_228 )
V_19 &= ~ V_215 ;
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_20 ( V_4 , V_37 -> clock ) ;
F_18 ( V_4 , V_19 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_229 == - V_125 )
return - V_125 ;
return F_91 ( V_4 -> V_229 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_62 * V_63 = V_4 -> V_63 ;
unsigned int V_86 ;
if ( V_4 -> V_230 == - V_125 ) {
if ( ! V_63 -> V_86 )
return 1 ;
V_86 = V_63 -> V_86 ( F_4 ( V_4 -> V_2 ) ) ;
} else
V_86 = ! ! F_91 ( V_4 -> V_230 )
^ V_63 -> V_231 ;
return V_86 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_203 * V_37 )
{
int V_119 = 0 ;
if ( ! F_86 ( V_2 -> V_207 . V_209 ) ) {
F_3 ( F_4 ( V_2 ) ) ;
switch ( V_37 -> V_232 ) {
case V_233 :
V_119 = F_94 ( V_2 -> V_207 . V_209 ,
2700000 , 3600000 ) ;
break;
case V_234 :
V_119 = F_94 ( V_2 -> V_207 . V_209 ,
1700000 , 1950000 ) ;
break;
case V_235 :
V_119 = F_94 ( V_2 -> V_207 . V_209 ,
1100000 , 1300000 ) ;
break;
}
if ( V_119 )
F_34 ( F_4 ( V_2 ) , L_19 ) ;
F_8 ( F_4 ( V_2 ) ) ;
F_9 ( F_4 ( V_2 ) ) ;
}
return V_119 ;
}
static T_4 F_95 ( int V_190 , void * V_191 )
{
struct V_3 * V_4 = V_191 ;
F_96 ( V_4 -> V_2 , F_97 ( 500 ) ) ;
return V_199 ;
}
static void F_98 ( struct V_236 * V_237 ,
struct V_62 * V_238 )
{
int V_38 = 0 ;
V_238 -> V_229 = F_99 ( V_237 , L_20 , 0 ) ;
V_238 -> V_230 = F_99 ( V_237 , L_21 , 0 ) ;
if ( F_100 ( V_237 , L_22 , NULL ) )
V_238 -> V_231 = true ;
else
V_238 -> V_231 = false ;
F_101 ( V_237 , L_23 , & V_238 -> V_239 ) ;
if ( ! V_238 -> V_239 )
F_102 ( L_24 , V_237 -> V_240 ) ;
if ( F_100 ( V_237 , L_25 , NULL ) )
V_238 -> V_241 |= V_242 ;
if ( F_100 ( V_237 , L_26 , NULL ) )
V_238 -> V_241 |= V_243 ;
F_101 ( V_237 , L_27 , & V_38 ) ;
switch ( V_38 ) {
case 0 :
break;
case 4 :
V_238 -> V_241 |= V_244 ;
break;
case 8 :
V_238 -> V_241 |= V_245 ;
break;
default :
F_102 ( L_28 , V_237 -> V_240 ) ;
}
}
static void F_98 ( struct V_236 * V_237 ,
struct V_62 * V_238 )
{
return;
}
static int F_103 ( struct V_246 * V_75 ,
const struct V_247 * V_248 )
{
struct V_62 * V_63 = V_75 -> V_75 . V_249 ;
struct V_236 * V_237 = V_75 -> V_75 . V_250 ;
struct V_27 * V_28 = V_248 -> V_12 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_119 ;
if ( ! V_63 && ! V_237 ) {
F_12 ( & V_75 -> V_75 , L_29 ) ;
return - V_14 ;
}
if ( ! V_63 ) {
V_63 = F_104 ( & V_75 -> V_75 , sizeof( * V_63 ) , V_251 ) ;
if ( ! V_63 )
return - V_116 ;
}
if ( V_237 )
F_98 ( V_237 , V_63 ) ;
V_119 = F_105 ( V_75 , V_252 ) ;
if ( V_119 )
goto V_253;
V_2 = F_106 ( sizeof( struct V_3 ) , & V_75 -> V_75 ) ;
if ( ! V_2 ) {
V_119 = - V_116 ;
goto V_254;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_229 = - V_125 ;
V_4 -> V_230 = - V_125 ;
V_4 -> V_255 = - 1 ;
V_4 -> V_224 = F_107 ( V_75 ) ;
V_4 -> V_256 = F_108 ( V_75 ) ;
F_60 ( F_4 ( V_2 ) , L_30 , V_4 -> V_224 ) ;
F_60 ( F_4 ( V_2 ) , L_31 , V_4 -> V_256 ) ;
V_4 -> V_16 = F_109 ( & V_75 -> V_75 , NULL ) ;
if ( F_86 ( V_4 -> V_16 ) ) {
V_119 = F_110 ( V_4 -> V_16 ) ;
goto V_257;
}
V_119 = F_111 ( V_4 -> V_16 ) ;
if ( V_119 )
goto V_257;
V_4 -> V_63 = V_63 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_30 = F_112 ( V_4 -> V_16 ) ;
if ( V_4 -> V_30 > 100000000 ) {
V_119 = F_113 ( V_4 -> V_16 , 100000000 ) ;
if ( V_119 < 0 )
goto V_258;
V_4 -> V_30 = F_112 ( V_4 -> V_16 ) ;
F_60 ( F_4 ( V_2 ) , L_32 ,
V_4 -> V_30 ) ;
}
V_4 -> V_95 = V_75 -> V_259 . V_260 ;
V_4 -> V_8 = F_114 ( V_75 -> V_259 . V_260 , F_115 ( & V_75 -> V_259 ) ) ;
if ( ! V_4 -> V_8 ) {
V_119 = - V_116 ;
goto V_258;
}
if ( V_28 -> V_261 ) {
V_262 . V_263 = F_1 ;
F_19 ( V_4 , V_24 ) ;
}
V_2 -> V_264 = & V_262 ;
if ( V_28 -> V_32 )
V_2 -> V_265 = F_21 ( V_4 -> V_30 , 257 ) ;
else
V_2 -> V_265 = F_21 ( V_4 -> V_30 , 512 ) ;
if ( V_63 -> V_239 )
V_2 -> V_239 = F_73 ( V_4 -> V_30 , V_63 -> V_239 ) ;
else
V_2 -> V_239 = F_73 ( V_4 -> V_30 , V_266 ) ;
F_60 ( F_4 ( V_2 ) , L_33 , V_2 -> V_239 ) ;
F_116 ( V_2 ) ;
if ( ! V_2 -> V_267 )
V_2 -> V_267 = V_63 -> V_268 ;
else if ( V_63 -> V_268 )
F_34 ( F_4 ( V_2 ) , L_34 ) ;
V_2 -> V_269 = V_63 -> V_241 ;
V_2 -> V_270 = V_63 -> V_271 ;
V_2 -> V_272 = V_273 ;
V_2 -> V_274 = V_275 ;
V_2 -> V_276 = ( 1 << V_28 -> V_277 ) - 1 ;
V_2 -> V_76 = V_2 -> V_276 ;
V_2 -> V_278 = 1 << 11 ;
V_2 -> V_279 = V_2 -> V_276 >> 11 ;
F_117 ( & V_4 -> V_7 ) ;
F_17 ( 0 , V_4 -> V_8 + V_52 ) ;
F_17 ( 0 , V_4 -> V_8 + V_54 ) ;
F_17 ( 0xfff , V_4 -> V_8 + V_200 ) ;
if ( V_63 -> V_230 == - V_280 ) {
V_119 = - V_280 ;
goto V_281;
}
if ( F_118 ( V_63 -> V_230 ) ) {
V_119 = F_119 ( V_63 -> V_230 , V_252 L_35 ) ;
if ( V_119 == 0 )
V_119 = F_120 ( V_63 -> V_230 ) ;
if ( V_119 == 0 )
V_4 -> V_230 = V_63 -> V_230 ;
else if ( V_119 != - V_125 )
goto V_281;
V_119 = F_121 ( F_122 ( V_63 -> V_230 ) ,
F_95 ,
V_282 | V_283 ,
V_252 L_35 , V_4 ) ;
if ( V_119 >= 0 )
V_4 -> V_255 = F_122 ( V_63 -> V_230 ) ;
}
if ( V_63 -> V_229 == - V_280 ) {
V_119 = - V_280 ;
goto V_284;
}
if ( F_118 ( V_63 -> V_229 ) ) {
V_119 = F_119 ( V_63 -> V_229 , V_252 L_36 ) ;
if ( V_119 == 0 )
V_119 = F_120 ( V_63 -> V_229 ) ;
if ( V_119 == 0 )
V_4 -> V_229 = V_63 -> V_229 ;
else if ( V_119 != - V_125 )
goto V_284;
}
if ( ( V_4 -> V_63 -> V_86 || V_4 -> V_230 != - V_125 )
&& V_4 -> V_255 < 0 )
V_2 -> V_269 |= V_285 ;
V_119 = F_123 ( V_75 -> V_190 [ 0 ] , F_80 , V_286 , V_252 L_37 , V_4 ) ;
if ( V_119 )
goto V_287;
if ( ! V_75 -> V_190 [ 1 ] )
V_4 -> V_50 = true ;
else {
V_119 = F_123 ( V_75 -> V_190 [ 1 ] , F_75 , V_286 ,
V_252 L_38 , V_4 ) ;
if ( V_119 )
goto V_288;
}
F_17 ( V_289 , V_4 -> V_8 + V_52 ) ;
F_124 ( V_75 , V_2 ) ;
F_36 ( & V_75 -> V_75 , L_39 ,
F_125 ( V_2 ) , F_126 ( V_75 ) , F_107 ( V_75 ) ,
F_108 ( V_75 ) , ( unsigned long long ) V_75 -> V_259 . V_260 ,
V_75 -> V_190 [ 0 ] , V_75 -> V_190 [ 1 ] ) ;
F_29 ( V_4 ) ;
F_127 ( & V_75 -> V_75 , 50 ) ;
F_128 ( & V_75 -> V_75 ) ;
F_129 ( & V_75 -> V_75 ) ;
F_130 ( V_2 ) ;
return 0 ;
V_288:
F_131 ( V_75 -> V_190 [ 0 ] , V_4 ) ;
V_287:
if ( V_4 -> V_229 != - V_125 )
F_132 ( V_4 -> V_229 ) ;
V_284:
if ( V_4 -> V_255 >= 0 )
F_131 ( V_4 -> V_255 , V_4 ) ;
if ( V_4 -> V_230 != - V_125 )
F_132 ( V_4 -> V_230 ) ;
V_281:
F_133 ( V_4 -> V_8 ) ;
V_258:
F_134 ( V_4 -> V_16 ) ;
V_257:
F_135 ( V_2 ) ;
V_254:
F_136 ( V_75 ) ;
V_253:
return V_119 ;
}
static int F_137 ( struct V_246 * V_75 )
{
struct V_1 * V_2 = F_138 ( V_75 ) ;
F_124 ( V_75 , NULL ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_75 -> V_75 ) ;
F_139 ( V_2 ) ;
F_17 ( 0 , V_4 -> V_8 + V_52 ) ;
F_17 ( 0 , V_4 -> V_8 + V_54 ) ;
F_17 ( 0 , V_4 -> V_8 + V_47 ) ;
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_38 ( V_4 ) ;
F_131 ( V_75 -> V_190 [ 0 ] , V_4 ) ;
if ( ! V_4 -> V_50 )
F_131 ( V_75 -> V_190 [ 1 ] , V_4 ) ;
if ( V_4 -> V_229 != - V_125 )
F_132 ( V_4 -> V_229 ) ;
if ( V_4 -> V_255 >= 0 )
F_131 ( V_4 -> V_255 , V_4 ) ;
if ( V_4 -> V_230 != - V_125 )
F_132 ( V_4 -> V_230 ) ;
F_133 ( V_4 -> V_8 ) ;
F_134 ( V_4 -> V_16 ) ;
F_135 ( V_2 ) ;
F_136 ( V_75 ) ;
}
return 0 ;
}
static int F_140 ( struct V_74 * V_75 )
{
struct V_246 * V_290 = F_141 ( V_75 ) ;
struct V_1 * V_2 = F_138 ( V_290 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_75 ) ;
F_17 ( 0 , V_4 -> V_8 + V_52 ) ;
}
return 0 ;
}
static int F_142 ( struct V_74 * V_75 )
{
struct V_246 * V_290 = F_141 ( V_75 ) ;
struct V_1 * V_2 = F_138 ( V_290 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_289 , V_4 -> V_8 + V_52 ) ;
F_129 ( V_75 ) ;
}
return 0 ;
}
static void F_143 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
if ( V_4 -> V_28 -> V_291 ) {
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_17 ( 0 , V_4 -> V_8 + V_52 ) ;
F_17 ( 0 , V_4 -> V_8 + V_25 ) ;
F_17 ( 0 , V_4 -> V_8 + V_21 ) ;
F_17 ( 0 , V_4 -> V_8 + V_18 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
}
static void F_144 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
if ( V_4 -> V_28 -> V_291 ) {
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_17 ( V_4 -> V_17 , V_4 -> V_8 + V_18 ) ;
F_17 ( V_4 -> V_23 , V_4 -> V_8 + V_25 ) ;
F_17 ( V_4 -> V_20 , V_4 -> V_8 + V_21 ) ;
F_17 ( V_289 , V_4 -> V_8 + V_52 ) ;
F_13 ( V_4 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
}
}
static int F_145 ( struct V_74 * V_75 )
{
struct V_246 * V_290 = F_141 ( V_75 ) ;
struct V_1 * V_2 = F_138 ( V_290 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_146 ( V_75 ) ;
F_143 ( V_4 ) ;
F_134 ( V_4 -> V_16 ) ;
}
return 0 ;
}
static int F_147 ( struct V_74 * V_75 )
{
struct V_246 * V_290 = F_141 ( V_75 ) ;
struct V_1 * V_2 = F_138 ( V_290 ) ;
if ( V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_111 ( V_4 -> V_16 ) ;
F_144 ( V_4 ) ;
F_148 ( V_75 ) ;
}
return 0 ;
}
