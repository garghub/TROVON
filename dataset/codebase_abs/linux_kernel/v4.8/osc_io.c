static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
F_2 ( V_3 -> V_4 -> V_5 . V_6 == & V_7 ) ;
return F_3 ( V_3 , struct V_1 , V_8 ) ;
}
static struct V_9 * F_4 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_9 * V_13 = F_3 ( V_3 , struct V_9 , V_14 ) ;
F_2 ( V_13 == F_5 ( V_11 ) ) ;
return V_13 ;
}
static struct V_15 * F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
const struct V_20 * V_3 ;
if ( V_19 )
V_3 = F_7 ( & V_19 -> V_21 , V_17 ) ;
else
V_3 = F_8 ( V_17 , & V_7 ) ;
F_9 ( V_3 ) ;
return F_10 ( V_3 ) ;
}
static void F_11 ( const struct V_10 * V_11 , const struct V_12 * V_22 )
{
}
static int F_12 ( const struct V_10 * V_11 ,
const struct V_12 * V_23 ,
enum V_24 V_25 , struct V_26 * V_27 )
{
struct V_16 * V_17 ;
struct V_16 * V_28 ;
struct V_29 * V_30 = NULL ;
struct V_18 * V_19 = NULL ;
struct V_15 * V_31 ;
struct V_32 * V_22 ;
F_13 ( V_33 ) ;
struct V_34 * V_35 = & V_27 -> V_36 ;
struct V_34 * V_37 = & V_27 -> V_38 ;
int V_39 = 0 ;
int V_40 = 0 ;
int V_41 ;
int V_42 ;
int V_43 ;
F_9 ( V_35 -> V_44 > 0 ) ;
F_14 ( V_45 , L_1 , V_35 -> V_44 , V_25 ) ;
V_19 = F_15 ( V_23 -> V_46 ) ;
V_30 = F_16 ( V_19 ) ;
V_43 = V_30 -> V_47 ;
V_41 = V_25 == V_48 ? V_49 : V_50 ;
V_42 = F_17 ( F_4 ( V_11 , V_23 ) ) ? V_51 : 0 ;
F_18 (page, tmp, qin) {
struct V_52 * V_53 ;
V_22 = V_17 -> V_54 ;
F_9 ( V_22 ) ;
V_31 = F_6 ( V_17 , V_19 ) ;
V_53 = & V_31 -> V_55 ;
F_9 ( V_19 == V_53 -> V_56 ) ;
if ( ! F_19 ( & V_53 -> V_57 ) ||
! F_19 ( & V_53 -> V_58 ) ) {
F_14 ( V_45 , L_2 ,
V_53 , V_31 ) ;
V_40 = - V_59 ;
break;
}
V_40 = F_20 ( V_11 , V_22 , V_17 , V_25 ) ;
if ( V_40 != 0 ) {
F_9 ( V_40 < 0 ) ;
if ( V_40 != - V_60 )
break;
V_40 = 0 ;
continue;
}
F_21 ( V_37 , V_35 , V_17 ) ;
F_22 ( & V_53 -> V_61 ) ;
V_53 -> V_62 = V_63 | V_64 ;
V_53 -> V_62 |= V_65 ;
F_23 ( & V_53 -> V_61 ) ;
F_24 ( V_11 , V_31 , V_25 , V_42 ) ;
F_25 ( & V_53 -> V_57 , & V_33 ) ;
if ( ++ V_39 == V_43 ) {
V_39 = 0 ;
V_40 = F_26 ( V_11 , V_19 , & V_33 , V_41 ,
V_42 ) ;
if ( V_40 < 0 )
break;
}
}
if ( V_39 > 0 )
V_40 = F_26 ( V_11 , V_19 , & V_33 , V_41 , V_42 ) ;
F_14 ( V_66 , L_3 , V_35 -> V_44 , V_37 -> V_44 , V_40 ) ;
return V_37 -> V_44 > 0 ? 0 : V_40 ;
}
static void F_27 ( const struct V_10 * V_11 ,
struct V_67 * V_68 , T_1 V_69 , unsigned V_70 )
{
struct V_71 * V_72 = F_15 ( V_68 ) -> V_73 ;
struct V_74 * V_75 = & F_28 ( V_11 ) -> V_76 ;
int V_77 ;
T_2 V_78 ;
V_78 = F_29 ( V_68 , V_69 ) + V_70 ;
F_30 ( V_68 ) ;
F_14 ( V_79 , L_4 ,
V_78 > V_72 -> V_80 ? L_5 : L_6 , V_72 -> V_80 , V_78 ,
V_72 -> V_81 . V_82 ) ;
V_75 -> V_83 = F_31 ( V_84 ) ;
V_75 -> V_85 = V_75 -> V_83 ;
V_77 = V_86 | V_87 ;
if ( V_78 > V_72 -> V_80 ) {
V_75 -> V_88 = V_78 ;
V_77 |= V_89 ;
}
if ( V_78 > V_72 -> V_81 . V_82 ) {
V_75 -> V_90 = V_78 ;
V_77 |= V_91 ;
}
F_32 ( V_11 , V_68 , V_75 , V_77 ) ;
F_33 ( V_68 ) ;
}
static int F_34 ( const struct V_10 * V_11 ,
const struct V_12 * V_23 ,
struct V_34 * V_35 , int V_92 , int V_70 ,
T_3 V_93 )
{
struct V_32 * V_22 = V_23 -> V_94 ;
struct V_9 * V_13 = F_4 ( V_11 , V_23 ) ;
struct V_18 * V_19 = F_15 ( V_23 -> V_46 ) ;
struct V_16 * V_17 ;
struct V_16 * V_95 ;
struct V_15 * V_31 ;
int V_40 = 0 ;
F_9 ( V_35 -> V_44 > 0 ) ;
V_95 = F_35 ( V_35 ) ;
if ( V_13 -> V_96 ) {
V_17 = F_36 ( V_35 ) ;
if ( V_17 == V_95 ) {
F_37 ( V_11 , V_17 , V_92 , V_70 ) ;
} else {
if ( V_92 != 0 )
F_37 ( V_11 , V_17 , V_92 , V_97 ) ;
if ( V_70 != V_97 )
F_37 ( V_11 , V_95 , 0 , V_70 ) ;
}
}
while ( V_35 -> V_44 > 0 ) {
struct V_52 * V_53 ;
V_17 = F_36 ( V_35 ) ;
V_31 = F_6 ( V_17 , V_19 ) ;
V_53 = & V_31 -> V_55 ;
if ( ! F_19 ( & V_53 -> V_58 ) ) {
F_14 ( V_45 , L_2 ,
V_53 , V_31 ) ;
V_40 = - V_59 ;
break;
}
if ( F_19 ( & V_53 -> V_57 ) ) {
V_40 = F_38 ( V_11 , & V_31 -> V_98 , V_22 ) ;
if ( V_40 != 0 )
break;
}
F_27 ( V_11 , F_39 ( V_19 ) , F_40 ( V_31 ) ,
V_17 == V_95 ? V_70 : V_97 ) ;
F_41 ( V_11 , V_35 , V_17 ) ;
(* V_93)( V_11 , V_22 , V_17 ) ;
}
if ( F_42 ( V_22 ) && V_13 -> V_99 ) {
F_43 ( V_11 , V_13 -> V_99 ) ;
V_13 -> V_99 = NULL ;
}
F_14 ( V_66 , L_1 , V_35 -> V_44 , V_40 ) ;
return V_40 ;
}
static int F_44 ( const struct V_10 * V_11 ,
const struct V_12 * V_23 )
{
struct V_32 * V_22 = V_23 -> V_94 ;
struct V_9 * V_13 = F_5 ( V_11 ) ;
struct V_18 * V_19 = F_15 ( V_23 -> V_46 ) ;
struct V_29 * V_30 = F_16 ( V_19 ) ;
unsigned long V_100 ;
unsigned int V_101 ;
unsigned int V_43 ;
if ( F_45 ( V_22 ) )
return 0 ;
V_101 = V_22 -> V_102 . V_103 . V_104 >> V_105 ;
if ( V_22 -> V_102 . V_103 . V_106 & ~ V_107 )
++ V_101 ;
V_43 = V_30 -> V_47 * V_30 -> V_108 ;
if ( V_101 > V_43 )
V_101 = V_43 ;
V_100 = F_46 ( V_30 -> V_109 ) ;
if ( V_100 < V_101 && V_110 ( V_30 ) > 0 )
V_100 = F_46 ( V_30 -> V_109 ) ;
while ( V_100 >= V_101 ) {
if ( V_100 == F_47 ( V_30 -> V_109 , V_100 , V_100 - V_101 ) ) {
V_13 -> V_111 = V_101 ;
break;
}
V_100 = F_46 ( V_30 -> V_109 ) ;
}
return 0 ;
}
static void F_48 ( const struct V_10 * V_11 ,
const struct V_12 * V_23 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
struct V_18 * V_19 = F_15 ( V_23 -> V_46 ) ;
struct V_29 * V_30 = F_16 ( V_19 ) ;
if ( V_13 -> V_111 > 0 ) {
F_49 ( V_13 -> V_111 , V_30 -> V_109 ) ;
V_13 -> V_111 = 0 ;
}
V_13 -> V_112 = NULL ;
}
static int F_50 ( const struct V_10 * V_11 ,
const struct V_12 * V_23 )
{
struct V_32 * V_22 ;
struct V_113 * V_114 ;
V_22 = V_23 -> V_94 ;
V_114 = & V_22 -> V_102 . V_115 ;
F_14 ( V_66 , L_7 ,
V_114 -> V_116 , V_114 -> V_117 , V_114 -> V_118 ) ;
if ( V_114 -> V_117 )
F_27 ( V_11 , V_23 -> V_46 ,
V_114 -> V_116 , V_114 -> V_118 ) ;
return 0 ;
}
static int F_51 ( void * V_119 , int V_120 )
{
struct V_121 * args = V_119 ;
args -> V_122 = V_120 ;
F_52 ( & args -> V_123 ) ;
return 0 ;
}
static int F_53 ( const struct V_10 * V_11 , struct V_32 * V_22 ,
struct V_15 * V_124 , void * V_125 )
{
struct V_16 * V_17 = V_124 -> V_98 . V_126 ;
struct V_52 * V_53 ;
T_2 V_127 = * ( T_2 * ) V_125 ;
V_53 = & V_124 -> V_55 ;
if ( V_53 -> V_128 & V_49 &&
! F_19 ( & V_53 -> V_57 ) )
F_54 ( V_129 , V_11 , V_17 , L_8 ,
V_127 , V_130 -> V_131 ) ;
if ( F_55 ( V_17 -> V_132 ) )
F_14 ( V_45 , L_9 ,
V_124 , F_40 ( V_124 ) , V_53 -> V_128 & V_133 ) ;
return V_134 ;
}
static void F_56 ( const struct V_10 * V_11 , struct V_32 * V_22 ,
struct V_9 * V_13 , T_2 V_135 )
{
struct V_67 * V_136 ;
int V_137 ;
T_1 V_127 ;
V_136 = V_13 -> V_14 . V_46 ;
V_127 = F_57 ( V_136 , V_135 ) ;
V_137 = F_29 ( V_136 , V_127 ) < V_135 ;
F_58 ( V_11 , V_22 , F_15 ( V_136 ) ,
V_127 + V_137 , V_138 ,
F_53 , ( void * ) & V_135 ) ;
}
static int F_59 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_32 * V_22 = V_3 -> V_94 ;
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_67 * V_68 = V_3 -> V_46 ;
struct V_71 * V_72 = F_15 ( V_68 ) -> V_73 ;
struct V_74 * V_75 = & F_28 ( V_11 ) -> V_76 ;
struct V_139 * V_140 = & V_13 -> V_141 ;
struct V_121 * V_142 = & V_13 -> V_143 ;
T_2 V_135 = V_22 -> V_102 . V_144 . V_145 . V_82 ;
unsigned int V_146 = V_22 -> V_102 . V_144 . V_147 ;
int V_40 = 0 ;
struct V_148 V_149 = { } ;
if ( F_60 ( V_22 ) )
V_40 = F_61 ( V_11 , V_13 , F_15 ( V_68 ) , V_135 ) ;
if ( V_40 == 0 && V_13 -> V_96 == 0 ) {
F_30 ( V_68 ) ;
V_40 = F_62 ( V_11 , V_68 , V_75 ) ;
if ( V_40 == 0 ) {
struct V_150 * V_151 = & V_22 -> V_102 . V_144 . V_145 ;
unsigned int V_152 = 0 ;
if ( V_146 & V_153 ) {
V_75 -> V_90 = V_135 ;
V_75 -> V_88 = V_135 ;
V_152 = V_91 | V_89 ;
}
if ( V_146 & V_154 ) {
V_75 -> V_85 = V_151 -> V_155 ;
V_152 |= V_86 ;
}
if ( V_146 & V_156 ) {
V_75 -> V_157 = V_151 -> V_158 ;
V_152 |= V_159 ;
}
if ( V_146 & V_160 ) {
V_75 -> V_83 = V_151 -> V_161 ;
V_152 |= V_87 ;
}
V_40 = F_32 ( V_11 , V_68 , V_75 , V_152 ) ;
}
F_33 ( V_68 ) ;
}
memset ( V_140 , 0 , sizeof( * V_140 ) ) ;
if ( V_40 == 0 ) {
V_140 -> V_162 = V_72 -> V_163 ;
V_140 -> V_164 = V_75 -> V_85 ;
V_140 -> V_165 = V_75 -> V_157 ;
V_140 -> V_166 = V_75 -> V_83 ;
V_140 -> V_167 = V_168 | V_169 | V_170 |
V_171 | V_172 ;
if ( V_146 & V_153 ) {
V_140 -> V_173 = V_135 ;
V_140 -> V_174 = V_175 ;
V_140 -> V_167 |= V_176 | V_177 ;
if ( V_13 -> V_96 ) {
V_140 -> V_178 = V_179 ;
V_140 -> V_167 |= V_180 ;
}
} else {
F_9 ( V_13 -> V_96 == 0 ) ;
}
V_149 . V_141 = V_140 ;
F_63 ( & V_142 -> V_123 ) ;
if ( V_146 & V_153 )
V_40 = F_64 ( F_65 ( F_15 ( V_68 ) ) ,
& V_149 , F_51 ,
V_142 , V_181 ) ;
else
V_40 = F_66 ( F_65 ( F_15 ( V_68 ) ) ,
& V_149 , NULL ,
F_51 ,
V_142 , V_181 ) ;
V_142 -> V_182 = V_40 == 0 ;
}
return V_40 ;
}
static void F_67 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_32 * V_22 = V_3 -> V_94 ;
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_67 * V_68 = V_3 -> V_46 ;
struct V_121 * V_142 = & V_13 -> V_143 ;
int V_40 = 0 ;
if ( V_142 -> V_182 ) {
F_68 ( & V_142 -> V_123 ) ;
V_40 = V_142 -> V_122 ;
V_22 -> V_183 = V_142 -> V_122 ;
}
if ( V_40 == 0 ) {
if ( V_13 -> V_96 ) {
struct V_184 * V_185 = F_69 ( V_68 -> V_186 . V_187 ) ;
F_9 ( F_60 ( V_22 ) ) ;
V_185 -> V_188 . V_189 ++ ;
}
}
if ( F_60 ( V_22 ) ) {
T_2 V_135 = V_22 -> V_102 . V_144 . V_145 . V_82 ;
F_56 ( V_11 , V_22 , V_13 , V_135 ) ;
if ( V_13 -> V_190 ) {
F_70 ( V_11 , V_13 , F_15 ( V_68 ) ) ;
V_13 -> V_190 = NULL ;
}
}
}
static int F_71 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_67 * V_68 = V_3 -> V_46 ;
struct V_74 * V_75 = & F_28 ( V_11 ) -> V_76 ;
int V_120 = 0 ;
if ( ! V_3 -> V_94 -> V_191 ) {
F_30 ( V_68 ) ;
V_75 -> V_157 = F_72 () ;
V_120 = F_32 ( V_11 , V_68 , V_75 , V_159 ) ;
F_33 ( V_68 ) ;
}
return V_120 ;
}
static int F_73 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_67 * V_68 = V_3 -> V_46 ;
struct V_74 * V_75 = & F_28 ( V_11 ) -> V_76 ;
int V_120 = 0 ;
F_74 ( V_192 , 1 ) ;
F_30 ( V_68 ) ;
V_75 -> V_83 = F_72 () ;
V_75 -> V_85 = V_75 -> V_83 ;
V_120 = F_32 ( V_11 , V_68 , V_75 , V_86 | V_87 ) ;
F_33 ( V_68 ) ;
return V_120 ;
}
static int F_75 ( const struct V_10 * V_11 , struct V_18 * V_68 ,
struct V_193 * V_114 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
struct V_139 * V_140 = & V_13 -> V_141 ;
struct V_148 * V_149 = & V_13 -> V_194 ;
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_121 * V_142 = & V_13 -> V_143 ;
int V_120 = 0 ;
memset ( V_140 , 0 , sizeof( * V_140 ) ) ;
V_140 -> V_162 = V_72 -> V_163 ;
V_140 -> V_167 = V_168 | V_169 ;
V_140 -> V_173 = V_114 -> V_195 ;
V_140 -> V_174 = V_114 -> V_196 ;
V_140 -> V_167 |= V_176 | V_177 ;
F_76 ( V_140 , V_114 -> V_197 ) ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_149 -> V_141 = V_140 ;
F_63 ( & V_142 -> V_123 ) ;
V_120 = F_77 ( F_65 ( V_68 ) , V_149 , F_51 , V_142 ,
V_181 ) ;
return V_120 ;
}
static int F_78 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_32 * V_22 = V_3 -> V_94 ;
struct V_193 * V_114 = & V_22 -> V_102 . V_198 ;
struct V_67 * V_68 = V_3 -> V_46 ;
struct V_18 * V_19 = F_15 ( V_68 ) ;
T_1 V_127 = F_57 ( V_68 , V_114 -> V_195 ) ;
T_1 V_199 = F_57 ( V_68 , V_114 -> V_196 ) ;
int V_40 = 0 ;
if ( V_114 -> V_196 == V_175 )
V_199 = V_138 ;
V_40 = F_79 ( V_11 , V_19 , V_127 , V_199 , 0 ,
V_114 -> V_200 == V_201 ) ;
if ( V_40 > 0 ) {
V_114 -> V_202 += V_40 ;
V_40 = 0 ;
}
if ( V_114 -> V_200 == V_203 ) {
int V_120 ;
V_120 = F_80 ( V_11 , V_19 , V_127 , V_199 ) ;
if ( V_40 == 0 )
V_40 = V_120 ;
V_120 = F_75 ( V_11 , V_19 , V_114 ) ;
if ( V_40 == 0 )
V_40 = V_120 ;
}
return V_40 ;
}
static void F_81 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_193 * V_114 = & V_3 -> V_94 -> V_102 . V_198 ;
struct V_67 * V_68 = V_3 -> V_46 ;
T_1 V_127 = F_57 ( V_68 , V_114 -> V_195 ) ;
T_1 V_199 = F_57 ( V_68 , V_114 -> V_196 ) ;
int V_40 = 0 ;
if ( V_114 -> V_200 == V_204 ) {
V_40 = F_80 ( V_11 , F_15 ( V_68 ) , V_127 , V_199 ) ;
} else if ( V_114 -> V_200 == V_203 ) {
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_121 * V_142 = & V_13 -> V_143 ;
F_68 ( & V_142 -> V_123 ) ;
if ( V_40 == 0 )
V_40 = V_142 -> V_122 ;
}
V_3 -> V_94 -> V_183 = V_40 ;
}
static void F_82 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
if ( V_13 -> V_99 ) {
F_43 ( V_11 , V_13 -> V_99 ) ;
V_13 -> V_99 = NULL ;
}
}
static int F_83 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 )
{
return 0 ;
}
static void F_84 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 , int V_205 )
{
struct V_1 * V_206 ;
V_206 = F_1 ( V_3 ) ;
F_85 ( V_207 , V_206 ) ;
}
static void F_86 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 ,
const struct V_67 * V_68 ,
struct V_208 * V_75 , T_4 V_209 )
{
struct V_71 * V_149 ;
struct V_210 * V_211 ;
struct V_16 * V_212 ;
struct V_213 * V_214 ;
struct V_15 * V_31 ;
struct V_139 * V_140 ;
struct V_150 * V_151 ;
V_149 = F_15 ( V_68 ) -> V_73 ;
V_151 = & V_149 -> V_81 ;
V_140 = V_75 -> V_215 ;
if ( ( V_209 & V_172 ) != 0 ) {
V_140 -> V_164 = V_151 -> V_155 ;
V_140 -> V_167 |= V_172 ;
}
if ( ( V_209 & V_170 ) != 0 ) {
V_140 -> V_165 = V_151 -> V_158 ;
V_140 -> V_167 |= V_170 ;
}
if ( ( V_209 & V_171 ) != 0 ) {
V_140 -> V_166 = V_151 -> V_161 ;
V_140 -> V_167 |= V_171 ;
}
if ( V_209 & V_169 ) {
F_87 ( & V_140 -> V_162 , F_88 ( & V_149 -> V_163 ) ) ;
V_140 -> V_167 |= V_169 ;
}
if ( V_209 & V_168 ) {
F_89 ( & V_140 -> V_162 , F_90 ( & V_149 -> V_163 ) ) ;
V_140 -> V_167 |= V_168 ;
}
if ( V_209 & V_216 ) {
V_211 = V_3 -> V_217 ;
F_9 ( ! F_19 ( & V_211 -> V_218 ) ) ;
V_212 = F_91 ( V_211 -> V_218 . V_219 ,
struct V_16 , V_220 ) ;
V_31 = F_6 ( V_212 , NULL ) ;
V_214 = F_92 ( V_11 , F_15 ( V_68 ) , F_40 ( V_31 ) ,
1 , 1 ) ;
if ( ! V_214 && ! V_31 -> V_221 ) {
struct V_222 * V_223 ;
struct V_224 * V_225 ;
F_54 ( V_129 , V_11 , V_212 , L_10 ) ;
V_225 = & F_28 ( V_11 ) -> V_226 ;
F_93 ( & V_149 -> V_163 , V_225 ) ;
V_223 = F_94 (
F_65 ( F_15 ( V_68 ) ) -> V_227 -> V_228 ,
NULL , V_225 , V_229 , 0 ) ;
F_95 ( V_129 , V_223 ) ;
F_96 () ;
F_97 () ;
}
if ( V_214 ) {
V_140 -> V_230 = V_214 -> V_231 ;
V_140 -> V_167 |= V_216 ;
F_98 ( V_214 ) ;
}
}
}
int F_99 ( const struct V_10 * V_11 ,
struct V_67 * V_68 , struct V_32 * V_22 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
F_100 ( V_13 , V_14 ) ;
F_101 ( V_22 , & V_13 -> V_14 , V_68 , & V_232 ) ;
return 0 ;
}
int F_102 ( const struct V_10 * V_11 , struct V_233 * V_234 ,
struct V_210 * V_235 )
{
struct V_1 * V_206 ;
int V_40 ;
V_206 = F_103 ( V_207 , V_236 ) ;
if ( V_206 ) {
F_104 ( V_235 , & V_206 -> V_8 , V_234 , & V_237 ) ;
V_40 = 0 ;
} else {
V_40 = - V_238 ;
}
return V_40 ;
}
