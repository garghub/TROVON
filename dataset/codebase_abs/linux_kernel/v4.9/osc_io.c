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
unsigned int V_39 = 0 ;
int V_40 = 0 ;
int V_41 ;
int V_42 ;
unsigned int V_43 ;
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
F_21 ( & V_53 -> V_61 ) ;
V_53 -> V_62 = V_63 | V_64 ;
V_53 -> V_62 |= V_65 ;
F_22 ( & V_53 -> V_61 ) ;
F_23 ( V_11 , V_31 , V_25 , V_42 ) ;
F_24 ( & V_53 -> V_57 , & V_33 ) ;
if ( V_17 -> V_66 )
F_25 ( V_37 , V_35 , V_17 ) ;
else
F_26 ( V_11 , V_35 , V_17 ) ;
if ( ++ V_39 == V_43 ) {
V_39 = 0 ;
V_40 = F_27 ( V_11 , V_19 , & V_33 , V_41 ,
V_42 ) ;
if ( V_40 < 0 )
break;
}
}
if ( V_39 > 0 )
V_40 = F_27 ( V_11 , V_19 , & V_33 , V_41 , V_42 ) ;
F_14 ( V_67 , L_3 , V_35 -> V_44 , V_37 -> V_44 , V_40 ) ;
return V_37 -> V_44 > 0 ? 0 : V_40 ;
}
static void F_28 ( const struct V_10 * V_11 ,
struct V_68 * V_69 , T_1 V_70 , T_2 V_71 )
{
struct V_72 * V_73 = F_15 ( V_69 ) -> V_74 ;
struct V_75 * V_76 = & F_29 ( V_11 ) -> V_77 ;
int V_78 ;
T_3 V_79 ;
V_79 = F_30 ( V_69 , V_70 ) + V_71 ;
F_31 ( V_69 ) ;
F_14 ( V_80 , L_4 ,
V_79 > V_73 -> V_81 ? L_5 : L_6 , V_73 -> V_81 , V_79 ,
V_73 -> V_82 . V_83 ) ;
V_76 -> V_84 = F_32 ( V_85 ) ;
V_76 -> V_86 = V_76 -> V_84 ;
V_78 = V_87 | V_88 ;
if ( V_79 > V_73 -> V_81 ) {
V_76 -> V_89 = V_79 ;
V_78 |= V_90 ;
}
if ( V_79 > V_73 -> V_82 . V_83 ) {
V_76 -> V_91 = V_79 ;
V_78 |= V_92 ;
}
F_33 ( V_11 , V_69 , V_76 , V_78 ) ;
F_34 ( V_69 ) ;
}
static int F_35 ( const struct V_10 * V_11 ,
const struct V_12 * V_23 ,
struct V_34 * V_35 , int V_93 , int V_71 ,
T_4 V_94 )
{
struct V_32 * V_22 = V_23 -> V_95 ;
struct V_9 * V_13 = F_4 ( V_11 , V_23 ) ;
struct V_18 * V_19 = F_15 ( V_23 -> V_46 ) ;
struct V_16 * V_17 ;
struct V_16 * V_96 ;
struct V_15 * V_31 ;
int V_40 = 0 ;
F_9 ( V_35 -> V_44 > 0 ) ;
V_96 = F_36 ( V_35 ) ;
if ( V_13 -> V_97 ) {
V_17 = F_37 ( V_35 ) ;
if ( V_17 == V_96 ) {
F_38 ( V_11 , V_17 , V_93 , V_71 ) ;
} else {
if ( V_93 != 0 )
F_38 ( V_11 , V_17 , V_93 , V_98 ) ;
if ( V_71 != V_98 )
F_38 ( V_11 , V_96 , 0 , V_71 ) ;
}
}
while ( V_35 -> V_44 > 0 ) {
struct V_52 * V_53 ;
V_17 = F_37 ( V_35 ) ;
V_31 = F_6 ( V_17 , V_19 ) ;
V_53 = & V_31 -> V_55 ;
if ( ! F_19 ( & V_53 -> V_58 ) ) {
F_14 ( V_45 , L_2 ,
V_53 , V_31 ) ;
V_40 = - V_59 ;
break;
}
if ( F_19 ( & V_53 -> V_57 ) ) {
V_40 = F_39 ( V_11 , & V_31 -> V_99 , V_22 ) ;
if ( V_40 != 0 )
break;
}
F_28 ( V_11 , F_40 ( V_19 ) , F_41 ( V_31 ) ,
V_17 == V_96 ? V_71 : V_98 ) ;
F_26 ( V_11 , V_35 , V_17 ) ;
(* V_94)( V_11 , V_22 , V_17 ) ;
}
if ( F_42 ( V_22 ) && V_13 -> V_100 ) {
F_43 ( V_11 , V_13 -> V_100 ) ;
V_13 -> V_100 = NULL ;
}
F_14 ( V_67 , L_1 , V_35 -> V_44 , V_40 ) ;
return V_40 ;
}
static int F_44 ( const struct V_10 * V_11 ,
const struct V_12 * V_23 )
{
struct V_32 * V_22 = V_23 -> V_95 ;
struct V_9 * V_13 = F_5 ( V_11 ) ;
struct V_18 * V_19 = F_15 ( V_23 -> V_46 ) ;
struct V_29 * V_30 = F_16 ( V_19 ) ;
unsigned long V_101 ;
unsigned long V_102 ;
unsigned long V_43 ;
if ( F_45 ( V_22 ) )
return 0 ;
V_102 = V_22 -> V_103 . V_104 . V_105 >> V_106 ;
if ( V_22 -> V_103 . V_104 . V_107 & ~ V_108 )
++ V_102 ;
V_43 = V_30 -> V_47 * V_30 -> V_109 ;
if ( V_102 > V_43 )
V_102 = V_43 ;
V_101 = F_46 ( V_30 -> V_110 ) ;
if ( V_101 < V_102 && V_111 ( V_30 ) > 0 )
V_101 = F_46 ( V_30 -> V_110 ) ;
while ( V_101 >= V_102 ) {
if ( V_101 == F_47 ( V_30 -> V_110 , V_101 , V_101 - V_102 ) ) {
V_13 -> V_112 = V_102 ;
break;
}
V_101 = F_46 ( V_30 -> V_110 ) ;
}
return 0 ;
}
static void F_48 ( const struct V_10 * V_11 ,
const struct V_12 * V_23 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
struct V_18 * V_19 = F_15 ( V_23 -> V_46 ) ;
struct V_29 * V_30 = F_16 ( V_19 ) ;
if ( V_13 -> V_112 > 0 ) {
F_49 ( V_13 -> V_112 , V_30 -> V_110 ) ;
V_13 -> V_112 = 0 ;
}
V_13 -> V_113 = NULL ;
}
static int F_50 ( const struct V_10 * V_11 ,
const struct V_12 * V_23 )
{
struct V_32 * V_22 ;
struct V_114 * V_115 ;
V_22 = V_23 -> V_95 ;
V_115 = & V_22 -> V_103 . V_116 ;
F_14 ( V_67 , L_7 ,
V_115 -> V_117 , V_115 -> V_118 , V_115 -> V_119 ) ;
if ( V_115 -> V_118 )
F_28 ( V_11 , V_23 -> V_46 ,
V_115 -> V_117 , V_115 -> V_119 ) ;
return 0 ;
}
static int F_51 ( void * V_120 , int V_121 )
{
struct V_122 * args = V_120 ;
args -> V_123 = V_121 ;
F_52 ( & args -> V_124 ) ;
return 0 ;
}
static int F_53 ( const struct V_10 * V_11 , struct V_32 * V_22 ,
struct V_15 * V_125 , void * V_126 )
{
struct V_16 * V_17 = V_125 -> V_99 . V_127 ;
struct V_52 * V_53 ;
T_3 V_128 = * ( T_3 * ) V_126 ;
V_53 = & V_125 -> V_55 ;
if ( V_53 -> V_129 & V_49 &&
! F_19 ( & V_53 -> V_57 ) )
F_54 ( V_130 , V_11 , V_17 , L_8 ,
V_128 , V_131 -> V_132 ) ;
if ( F_55 ( V_17 -> V_133 ) )
F_14 ( V_45 , L_9 ,
V_125 , F_41 ( V_125 ) , V_53 -> V_129 & V_134 ) ;
return V_135 ;
}
static void F_56 ( const struct V_10 * V_11 , struct V_32 * V_22 ,
struct V_9 * V_13 , T_3 V_136 )
{
struct V_68 * V_137 ;
int V_138 ;
T_1 V_128 ;
V_137 = V_13 -> V_14 . V_46 ;
V_128 = F_57 ( V_137 , V_136 ) ;
V_138 = F_30 ( V_137 , V_128 ) < V_136 ;
F_58 ( V_11 , V_22 , F_15 ( V_137 ) ,
V_128 + V_138 , V_139 ,
F_53 , ( void * ) & V_136 ) ;
}
static int F_59 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_32 * V_22 = V_3 -> V_95 ;
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_68 * V_69 = V_3 -> V_46 ;
struct V_72 * V_73 = F_15 ( V_69 ) -> V_74 ;
struct V_75 * V_76 = & F_29 ( V_11 ) -> V_77 ;
struct V_140 * V_141 = & V_13 -> V_142 ;
struct V_122 * V_143 = & V_13 -> V_144 ;
T_3 V_136 = V_22 -> V_103 . V_145 . V_146 . V_83 ;
unsigned int V_147 = V_22 -> V_103 . V_145 . V_148 ;
int V_40 = 0 ;
struct V_149 V_150 = { } ;
if ( F_60 ( V_22 ) )
V_40 = F_61 ( V_11 , V_13 , F_15 ( V_69 ) , V_136 ) ;
if ( V_40 == 0 && V_13 -> V_97 == 0 ) {
F_31 ( V_69 ) ;
V_40 = F_62 ( V_11 , V_69 , V_76 ) ;
if ( V_40 == 0 ) {
struct V_151 * V_152 = & V_22 -> V_103 . V_145 . V_146 ;
unsigned int V_153 = 0 ;
if ( V_147 & V_154 ) {
V_76 -> V_91 = V_136 ;
V_76 -> V_89 = V_136 ;
V_153 = V_92 | V_90 ;
}
if ( V_147 & V_155 ) {
V_76 -> V_86 = V_152 -> V_156 ;
V_153 |= V_87 ;
}
if ( V_147 & V_157 ) {
V_76 -> V_158 = V_152 -> V_159 ;
V_153 |= V_160 ;
}
if ( V_147 & V_161 ) {
V_76 -> V_84 = V_152 -> V_162 ;
V_153 |= V_88 ;
}
V_40 = F_33 ( V_11 , V_69 , V_76 ,
V_153 ) ;
}
F_34 ( V_69 ) ;
}
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
if ( V_40 == 0 ) {
V_141 -> V_163 = V_73 -> V_164 ;
F_63 ( V_141 , V_22 -> V_103 . V_145 . V_165 ) ;
V_141 -> V_166 = V_22 -> V_103 . V_145 . V_167 ;
V_141 -> V_168 = V_76 -> V_86 ;
V_141 -> V_169 = V_76 -> V_158 ;
V_141 -> V_170 = V_76 -> V_84 ;
V_141 -> V_171 |= V_172 | V_173 | V_174 |
V_175 | V_176 ;
if ( V_147 & V_154 ) {
V_141 -> V_177 = V_136 ;
V_141 -> V_178 = V_179 ;
V_141 -> V_171 |= V_180 | V_181 ;
if ( V_13 -> V_97 ) {
V_141 -> V_182 = V_183 ;
V_141 -> V_171 |= V_184 ;
}
} else {
F_9 ( V_13 -> V_97 == 0 ) ;
}
V_150 . V_142 = V_141 ;
F_64 ( & V_143 -> V_124 ) ;
if ( V_147 & V_154 )
V_40 = F_65 ( F_66 ( F_15 ( V_69 ) ) ,
& V_150 , F_51 ,
V_143 , V_185 ) ;
else
V_40 = F_67 ( F_66 ( F_15 ( V_69 ) ) ,
& V_150 , NULL ,
F_51 ,
V_143 , V_185 ) ;
V_143 -> V_186 = V_40 == 0 ;
}
return V_40 ;
}
static void F_68 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_32 * V_22 = V_3 -> V_95 ;
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_68 * V_69 = V_3 -> V_46 ;
struct V_122 * V_143 = & V_13 -> V_144 ;
int V_40 = 0 ;
if ( V_143 -> V_186 ) {
F_69 ( & V_143 -> V_124 ) ;
V_40 = V_143 -> V_123 ;
V_22 -> V_187 = V_143 -> V_123 ;
}
if ( V_40 == 0 ) {
if ( V_13 -> V_97 ) {
struct V_188 * V_189 = F_70 ( V_69 -> V_190 . V_191 ) ;
F_9 ( F_60 ( V_22 ) ) ;
V_189 -> V_192 . V_193 ++ ;
}
}
if ( F_60 ( V_22 ) ) {
T_3 V_136 = V_22 -> V_103 . V_145 . V_146 . V_83 ;
F_56 ( V_11 , V_22 , V_13 , V_136 ) ;
if ( V_13 -> V_194 ) {
F_71 ( V_11 , V_13 , F_15 ( V_69 ) ) ;
V_13 -> V_194 = NULL ;
}
}
}
static int F_72 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_68 * V_69 = V_3 -> V_46 ;
struct V_75 * V_76 = & F_29 ( V_11 ) -> V_77 ;
int V_121 = 0 ;
if ( ! V_3 -> V_95 -> V_195 ) {
F_31 ( V_69 ) ;
V_76 -> V_158 = F_73 () ;
V_121 = F_33 ( V_11 , V_69 , V_76 , V_160 ) ;
F_34 ( V_69 ) ;
}
return V_121 ;
}
static int F_74 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_68 * V_69 = V_3 -> V_46 ;
struct V_75 * V_76 = & F_29 ( V_11 ) -> V_77 ;
int V_121 = 0 ;
F_75 ( V_196 , 1 ) ;
F_31 ( V_69 ) ;
V_76 -> V_84 = F_73 () ;
V_76 -> V_86 = V_76 -> V_84 ;
V_121 = F_33 ( V_11 , V_69 , V_76 , V_87 | V_88 ) ;
F_34 ( V_69 ) ;
return V_121 ;
}
static int F_76 ( const struct V_10 * V_11 , struct V_18 * V_69 ,
struct V_197 * V_115 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
struct V_140 * V_141 = & V_13 -> V_142 ;
struct V_149 * V_150 = & V_13 -> V_198 ;
struct V_72 * V_73 = V_69 -> V_74 ;
struct V_122 * V_143 = & V_13 -> V_144 ;
int V_121 = 0 ;
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
V_141 -> V_163 = V_73 -> V_164 ;
V_141 -> V_171 = V_172 | V_173 ;
V_141 -> V_177 = V_115 -> V_199 ;
V_141 -> V_178 = V_115 -> V_200 ;
V_141 -> V_171 |= V_180 | V_181 ;
F_63 ( V_141 , V_115 -> V_201 ) ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> V_142 = V_141 ;
F_64 ( & V_143 -> V_124 ) ;
V_121 = F_77 ( F_66 ( V_69 ) , V_150 , F_51 , V_143 ,
V_185 ) ;
return V_121 ;
}
static int F_78 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_32 * V_22 = V_3 -> V_95 ;
struct V_197 * V_115 = & V_22 -> V_103 . V_202 ;
struct V_68 * V_69 = V_3 -> V_46 ;
struct V_18 * V_19 = F_15 ( V_69 ) ;
T_1 V_128 = F_57 ( V_69 , V_115 -> V_199 ) ;
T_1 V_203 = F_57 ( V_69 , V_115 -> V_200 ) ;
int V_40 = 0 ;
if ( V_115 -> V_200 == V_179 )
V_203 = V_139 ;
V_40 = F_79 ( V_11 , V_19 , V_128 , V_203 , 0 ,
V_115 -> V_204 == V_205 ) ;
if ( V_40 > 0 ) {
V_115 -> V_206 += V_40 ;
V_40 = 0 ;
}
if ( V_115 -> V_204 == V_207 ) {
int V_121 ;
V_121 = F_80 ( V_11 , V_19 , V_128 , V_203 ) ;
if ( V_40 == 0 )
V_40 = V_121 ;
V_121 = F_76 ( V_11 , V_19 , V_115 ) ;
if ( V_40 == 0 )
V_40 = V_121 ;
}
return V_40 ;
}
static void F_81 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_197 * V_115 = & V_3 -> V_95 -> V_103 . V_202 ;
struct V_68 * V_69 = V_3 -> V_46 ;
T_1 V_128 = F_57 ( V_69 , V_115 -> V_199 ) ;
T_1 V_203 = F_57 ( V_69 , V_115 -> V_200 ) ;
int V_40 = 0 ;
if ( V_115 -> V_204 == V_208 ) {
V_40 = F_80 ( V_11 , F_15 ( V_69 ) , V_128 , V_203 ) ;
} else if ( V_115 -> V_204 == V_207 ) {
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_122 * V_143 = & V_13 -> V_144 ;
F_69 ( & V_143 -> V_124 ) ;
if ( V_40 == 0 )
V_40 = V_143 -> V_123 ;
}
V_3 -> V_95 -> V_187 = V_40 ;
}
static void F_82 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
if ( V_13 -> V_100 ) {
F_43 ( V_11 , V_13 -> V_100 ) ;
V_13 -> V_100 = NULL ;
}
}
static int F_83 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 )
{
return 0 ;
}
static void F_84 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 , int V_209 )
{
struct V_1 * V_210 ;
V_210 = F_1 ( V_3 ) ;
F_85 ( V_211 , V_210 ) ;
}
static void F_86 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 ,
const struct V_68 * V_69 ,
struct V_212 * V_76 , T_5 V_213 )
{
struct V_72 * V_150 ;
struct V_214 * V_215 ;
struct V_16 * V_216 ;
struct V_217 * V_218 ;
struct V_15 * V_31 ;
struct V_140 * V_141 ;
struct V_151 * V_152 ;
V_150 = F_15 ( V_69 ) -> V_74 ;
V_152 = & V_150 -> V_82 ;
V_141 = V_76 -> V_219 ;
if ( ( V_213 & V_176 ) != 0 ) {
V_141 -> V_168 = V_152 -> V_156 ;
V_141 -> V_171 |= V_176 ;
}
if ( ( V_213 & V_174 ) != 0 ) {
V_141 -> V_169 = V_152 -> V_159 ;
V_141 -> V_171 |= V_174 ;
}
if ( ( V_213 & V_175 ) != 0 ) {
V_141 -> V_170 = V_152 -> V_162 ;
V_141 -> V_171 |= V_175 ;
}
if ( V_213 & V_173 ) {
F_87 ( & V_141 -> V_163 , F_88 ( & V_150 -> V_164 ) ) ;
V_141 -> V_171 |= V_173 ;
}
if ( V_213 & V_172 ) {
F_89 ( & V_141 -> V_163 , F_90 ( & V_150 -> V_164 ) ) ;
V_141 -> V_171 |= V_172 ;
}
if ( V_213 & V_220 ) {
V_215 = V_3 -> V_221 ;
F_9 ( ! F_19 ( & V_215 -> V_222 ) ) ;
V_216 = F_91 ( V_215 -> V_222 . V_223 ,
struct V_16 , V_224 ) ;
V_31 = F_6 ( V_216 , NULL ) ;
V_218 = F_92 ( V_11 , F_15 ( V_69 ) , F_41 ( V_31 ) ,
1 , 1 ) ;
if ( ! V_218 && ! V_31 -> V_225 ) {
struct V_226 * V_227 ;
struct V_228 * V_229 ;
F_54 ( V_130 , V_11 , V_216 , L_10 ) ;
V_229 = & F_29 ( V_11 ) -> V_230 ;
F_93 ( & V_150 -> V_164 , V_229 ) ;
V_227 = F_94 (
F_66 ( F_15 ( V_69 ) ) -> V_231 -> V_232 ,
NULL , V_229 , V_233 , 0 ) ;
F_95 ( V_130 , V_227 ) ;
F_96 () ;
F_97 () ;
}
if ( V_218 ) {
V_141 -> V_234 = V_218 -> V_235 ;
V_141 -> V_171 |= V_220 ;
F_98 ( V_218 ) ;
}
}
}
int F_99 ( const struct V_10 * V_11 ,
struct V_68 * V_69 , struct V_32 * V_22 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
F_100 ( V_13 , V_14 ) ;
F_101 ( V_22 , & V_13 -> V_14 , V_69 , & V_236 ) ;
return 0 ;
}
int F_102 ( const struct V_10 * V_11 , struct V_237 * V_238 ,
struct V_214 * V_239 )
{
struct V_1 * V_210 ;
int V_40 ;
V_210 = F_103 ( V_211 , V_240 ) ;
if ( V_210 ) {
F_104 ( V_239 , & V_210 -> V_8 , V_238 , & V_241 ) ;
V_40 = 0 ;
} else {
V_40 = - V_242 ;
}
return V_40 ;
}
