static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
F_2 ( & V_2 -> V_8 ) ;
F_3 ( & V_2 -> V_9 ) ;
F_4 ( & V_2 -> V_9 , & V_7 -> V_10 , V_7 -> V_11 ) ;
V_2 -> V_12 = 0 ;
}
static void F_5 ( struct V_13 * V_13 )
{
F_6 ( F_7 ( V_13 , struct V_1 , V_8 ) , V_14 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_8 , F_5 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_9 ) ;
F_8 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_9 ) ;
F_8 ( V_2 ) ;
}
static int F_14 ( struct V_15 * V_15 , struct V_1 * V_2 )
{
int V_16 ;
F_15 ( V_17 ) ;
F_16 ( & V_18 ) ;
V_16 = F_17 ( V_15 , V_2 , 0 , 0 , V_19 ) ;
if ( V_16 >= 0 )
V_2 -> V_20 = V_16 ;
F_18 ( & V_18 ) ;
F_19 () ;
return V_16 < 0 ? V_16 : 0 ;
}
void F_20 ( struct V_15 * V_15 , struct V_1 * V_2 )
{
F_16 ( & V_18 ) ;
F_21 ( V_15 , V_2 -> V_20 ) ;
F_18 ( & V_18 ) ;
}
static struct V_1 * F_22 ( struct V_15 * V_15 , int V_20 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_23 () ;
V_2 = F_24 ( V_15 , V_20 ) ;
if ( V_2 ) {
if ( V_2 -> V_5 == V_5 )
F_25 ( & V_2 -> V_8 ) ;
else
V_2 = NULL ;
}
F_26 () ;
return V_2 ;
}
static struct V_1 * F_27 ( struct V_15 * V_15 , int V_20 ,
struct V_4 * V_5 , int V_21 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_15 , V_20 , V_5 ) ;
if ( ! V_2 )
return NULL ;
if ( V_21 )
F_28 ( & V_2 -> V_9 , V_22 ) ;
else
F_29 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_12 ) {
F_10 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_1 * F_30 ( struct V_15 * V_15 , int V_20 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_15 , V_20 , V_5 ) ;
if ( ! V_2 )
return NULL ;
F_31 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_12 ) {
F_12 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static void * F_32 ( struct V_15 * V_15 , int V_20 , struct V_4 * V_5 ,
int V_21 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_15 , V_20 , V_5 , V_21 ) ;
return V_2 ? V_2 -> V_23 : NULL ;
}
static struct V_24 * F_33 ( int V_25 , struct V_4 * V_5 )
{
return F_32 ( & V_26 , V_25 , V_5 , 0 ) ;
}
static void F_34 ( struct V_24 * V_27 )
{
F_10 ( V_27 -> V_28 ) ;
}
static struct V_29 * F_35 ( int V_30 , struct V_4 * V_5 , int V_21 )
{
return F_32 ( & V_31 , V_30 , V_5 , V_21 ) ;
}
static void F_36 ( struct V_29 * V_32 )
{
F_10 ( V_32 -> V_28 ) ;
}
static struct V_33 * F_37 ( int V_34 , struct V_4 * V_5 )
{
return F_32 ( & V_35 , V_34 , V_5 , 0 ) ;
}
static void F_38 ( struct V_33 * V_36 )
{
F_10 ( V_36 -> V_28 ) ;
}
static struct V_37 * F_39 ( int V_38 , struct V_4 * V_5 )
{
return F_32 ( & V_39 , V_38 , V_5 , 0 ) ;
}
static struct V_40 * F_40 ( int V_41 , struct V_4 * V_5 )
{
return F_32 ( & V_42 , V_41 , V_5 , 0 ) ;
}
static void F_41 ( struct V_40 * V_43 )
{
F_10 ( V_43 -> V_28 ) ;
}
static struct V_44 * F_42 ( int V_45 ,
struct V_4 * V_5 )
{
return F_32 ( & V_46 , V_45 , V_5 , 0 ) ;
}
static void F_43 ( struct V_44 * V_47 )
{
F_10 ( V_47 -> V_28 ) ;
}
static struct V_37 * F_44 ( int V_38 , struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( & V_39 , V_38 , V_5 ) ;
return V_2 ? V_2 -> V_23 : NULL ;
}
static void F_45 ( struct V_37 * V_48 )
{
F_10 ( V_48 -> V_28 ) ;
}
static void F_46 ( struct V_37 * V_48 )
{
F_12 ( V_48 -> V_28 ) ;
}
static struct V_49 * F_47 ( int V_50 , struct V_4 * V_5 )
{
return F_32 ( & V_51 , V_50 , V_5 , 0 ) ;
}
static void F_48 ( struct V_49 * V_52 )
{
F_10 ( V_52 -> V_28 ) ;
}
static struct V_53 * F_49 ( int V_54 , struct V_4 * V_5 ,
struct V_1 * * V_2 )
{
* V_2 = F_27 ( & V_55 , V_54 , V_5 , 0 ) ;
return * V_2 ? ( * V_2 ) -> V_23 : NULL ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
T_2 F_51 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 ,
int V_61 , int V_62 )
{
struct F_51 V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
struct V_4 * V_68 ;
struct V_57 * V_69 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_53 ( & V_57 -> V_9 ) ;
if ( V_57 -> V_68 ) {
V_16 = - V_72 ;
goto V_73;
}
F_54 ( & V_67 , V_60 + sizeof V_63 ,
( unsigned long ) V_63 . V_74 + sizeof V_65 ,
V_61 - sizeof V_63 , V_62 - sizeof V_65 ) ;
V_68 = V_59 -> V_75 ( V_59 , & V_67 ) ;
if ( F_55 ( V_68 ) ) {
V_16 = F_56 ( V_68 ) ;
goto V_73;
}
V_68 -> V_76 = V_59 ;
F_57 ( & V_68 -> V_77 ) ;
F_57 ( & V_68 -> V_78 ) ;
F_57 ( & V_68 -> V_79 ) ;
F_57 ( & V_68 -> V_80 ) ;
F_57 ( & V_68 -> V_81 ) ;
F_57 ( & V_68 -> V_82 ) ;
F_57 ( & V_68 -> V_83 ) ;
F_57 ( & V_68 -> V_84 ) ;
F_57 ( & V_68 -> V_85 ) ;
F_57 ( & V_68 -> V_86 ) ;
F_57 ( & V_68 -> V_87 ) ;
F_23 () ;
V_68 -> V_88 = F_58 ( V_89 -> V_90 , V_91 ) ;
F_26 () ;
V_68 -> V_92 = 0 ;
#ifdef F_59
V_68 -> V_93 = V_94 ;
F_3 ( & V_68 -> V_95 ) ;
V_68 -> V_96 = 0 ;
F_57 ( & V_68 -> V_97 ) ;
if ( ! ( V_59 -> V_98 . V_99 & V_100 ) )
V_68 -> V_101 = NULL ;
#endif
V_65 . V_102 = V_57 -> V_76 -> V_102 ;
V_16 = F_60 ( V_103 ) ;
if ( V_16 < 0 )
goto V_104;
V_65 . V_105 = V_16 ;
V_69 = F_61 ( V_57 , V_59 , 1 ) ;
if ( F_55 ( V_69 ) ) {
V_16 = F_56 ( V_69 ) ;
goto V_106;
}
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) ) {
V_16 = - V_71 ;
goto V_107;
}
V_57 -> V_68 = V_68 ;
F_63 ( V_65 . V_105 , V_69 ) ;
F_64 ( & V_57 -> V_9 ) ;
return V_61 ;
V_107:
F_65 ( V_57 ) ;
F_66 ( V_69 ) ;
V_106:
F_67 ( V_65 . V_105 ) ;
V_104:
F_68 ( V_68 -> V_88 ) ;
V_59 -> V_108 ( V_68 ) ;
V_73:
F_64 ( & V_57 -> V_9 ) ;
return V_16 ;
}
static void F_69 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_109 * V_65 ,
struct V_110 * V_111 )
{
V_65 -> V_112 = V_111 -> V_112 ;
V_65 -> V_113 = V_59 -> V_113 ;
V_65 -> V_114 = V_111 -> V_114 ;
V_65 -> V_115 = V_111 -> V_115 ;
V_65 -> V_116 = V_111 -> V_116 ;
V_65 -> V_117 = V_111 -> V_117 ;
V_65 -> V_118 = V_111 -> V_118 ;
V_65 -> V_119 = V_111 -> V_119 ;
V_65 -> V_120 = V_111 -> V_120 ;
V_65 -> V_121 = V_111 -> V_121 ;
V_65 -> V_99 = F_70 ( V_111 -> V_99 ) ;
V_65 -> V_122 = V_111 -> V_122 ;
V_65 -> V_123 = V_111 -> V_123 ;
V_65 -> V_124 = V_111 -> V_124 ;
V_65 -> V_125 = V_111 -> V_125 ;
V_65 -> V_126 = V_111 -> V_126 ;
V_65 -> V_127 = V_111 -> V_127 ;
V_65 -> V_128 = V_111 -> V_128 ;
V_65 -> V_129 = V_111 -> V_129 ;
V_65 -> V_130 = V_111 -> V_130 ;
V_65 -> V_131 = V_111 -> V_131 ;
V_65 -> V_132 = V_111 -> V_132 ;
V_65 -> V_133 = V_111 -> V_133 ;
V_65 -> V_134 = V_111 -> V_134 ;
V_65 -> V_135 = V_111 -> V_135 ;
V_65 -> V_136 = V_111 -> V_136 ;
V_65 -> V_137 = V_111 -> V_137 ;
V_65 -> V_138 = V_111 -> V_138 ;
V_65 -> V_139 = V_111 -> V_139 ;
V_65 -> V_140 = V_111 -> V_140 ;
V_65 -> V_141 = V_111 -> V_141 ;
V_65 -> V_142 = V_111 -> V_142 ;
V_65 -> V_143 = V_111 -> V_143 ;
V_65 -> V_144 = V_111 -> V_144 ;
V_65 -> V_145 = V_111 -> V_145 ;
V_65 -> V_146 = V_111 -> V_146 ;
V_65 -> V_147 = V_111 -> V_147 ;
V_65 -> V_148 = V_111 -> V_148 ;
V_65 -> V_149 = V_111 -> V_149 ;
V_65 -> V_150 = V_59 -> V_150 ;
}
T_2 F_71 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 ,
int V_61 , int V_62 )
{
struct F_71 V_63 ;
struct V_109 V_65 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
F_69 ( V_57 , V_59 , & V_65 , & V_59 -> V_98 ) ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
return - V_71 ;
return V_61 ;
}
T_2 F_72 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 ,
int V_61 , int V_62 )
{
struct F_72 V_63 ;
struct V_151 V_65 ;
struct V_152 V_111 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_16 = F_73 ( V_59 , V_63 . V_153 , & V_111 ) ;
if ( V_16 )
return V_16 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_154 = V_111 . V_154 ;
V_65 . V_155 = V_111 . V_155 ;
V_65 . V_156 = V_111 . V_156 ;
V_65 . V_157 = V_111 . V_157 ;
V_65 . V_158 = V_111 . V_158 ;
V_65 . V_159 = V_111 . V_159 ;
V_65 . V_160 = V_111 . V_160 ;
V_65 . V_161 = V_111 . V_161 ;
V_65 . V_162 = V_111 . V_162 ;
V_65 . V_163 = V_111 . V_163 ;
V_65 . V_164 = V_111 . V_164 ;
V_65 . V_165 = V_111 . V_165 ;
V_65 . V_166 = V_111 . V_166 ;
V_65 . V_167 = V_111 . V_167 ;
V_65 . V_168 = V_111 . V_168 ;
V_65 . V_169 = V_111 . V_169 ;
V_65 . V_170 = V_111 . V_170 ;
V_65 . V_171 = V_111 . V_171 ;
V_65 . V_172 = V_111 . V_172 ;
V_65 . V_173 = F_74 ( V_59 ,
V_63 . V_153 ) ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
return - V_71 ;
return V_61 ;
}
T_2 F_75 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 ,
int V_61 , int V_62 )
{
struct F_75 V_63 ;
struct V_174 V_65 ;
struct V_66 V_67 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof V_63 ,
( unsigned long ) V_63 . V_74 + sizeof V_65 ,
V_61 - sizeof V_63 , V_62 - sizeof V_65 ) ;
V_2 = F_76 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_175 ;
F_1 ( V_2 , 0 , V_57 -> V_68 , & V_176 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = V_59 -> V_177 ( V_59 , V_57 -> V_68 , & V_67 ) ;
if ( F_55 ( V_27 ) ) {
V_16 = F_56 ( V_27 ) ;
goto V_73;
}
V_27 -> V_76 = V_59 ;
V_27 -> V_28 = V_2 ;
V_27 -> V_178 = NULL ;
F_77 ( & V_27 -> V_179 , 0 ) ;
V_2 -> V_23 = V_27 ;
V_16 = F_14 ( & V_26 , V_2 ) ;
if ( V_16 )
goto V_180;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_25 = V_2 -> V_20 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) ) {
V_16 = - V_71 ;
goto V_181;
}
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_2 -> V_182 , & V_57 -> V_68 -> V_77 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_61 ;
V_181:
F_20 ( & V_26 , V_2 ) ;
V_180:
F_79 ( V_27 ) ;
V_73:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_80 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 ,
int V_61 , int V_62 )
{
struct F_80 V_63 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_2 = F_30 ( & V_26 , V_63 . V_25 , V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_27 = V_2 -> V_23 ;
if ( F_81 ( & V_27 -> V_179 ) ) {
V_16 = - V_183 ;
goto V_184;
}
V_16 = V_27 -> V_76 -> V_185 ( V_2 -> V_23 ) ;
F_82 ( V_16 , L_1 ) ;
if ( V_16 )
goto V_184;
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_26 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_61 ;
V_184:
F_12 ( V_2 ) ;
return V_16 ;
}
static int F_84 ( struct V_186 * V_187 ,
struct V_188 * V_188 ,
struct V_53 * V_189 )
{
struct V_190 * V_191 , * V_192 ;
struct V_193 * * V_194 = & V_187 -> V_195 . V_193 ;
struct V_193 * V_196 = NULL ;
V_191 = F_76 ( sizeof *V_191 , V_17 ) ;
if ( ! V_191 )
return - V_175 ;
V_191 -> V_189 = V_189 ;
V_191 -> V_188 = V_188 ;
while ( * V_194 ) {
V_196 = * V_194 ;
V_192 = F_85 ( V_196 , struct V_190 , V_197 ) ;
if ( V_188 < V_192 -> V_188 ) {
V_194 = & ( * V_194 ) -> V_198 ;
} else if ( V_188 > V_192 -> V_188 ) {
V_194 = & ( * V_194 ) -> V_199 ;
} else {
F_86 ( V_191 ) ;
return - V_200 ;
}
}
F_87 ( & V_191 -> V_197 , V_196 , V_194 ) ;
F_88 ( & V_191 -> V_197 , & V_187 -> V_195 ) ;
F_89 ( V_188 ) ;
return 0 ;
}
static struct V_190 * F_90 ( struct V_186 * V_187 ,
struct V_188 * V_188 )
{
struct V_190 * V_191 ;
struct V_193 * V_194 = V_187 -> V_195 . V_193 ;
while ( V_194 ) {
V_191 = F_85 ( V_194 , struct V_190 , V_197 ) ;
if ( V_188 < V_191 -> V_188 )
V_194 = V_194 -> V_198 ;
else if ( V_188 > V_191 -> V_188 )
V_194 = V_194 -> V_199 ;
else
return V_191 ;
}
return NULL ;
}
static struct V_53 * F_91 ( struct V_186 * V_187 , struct V_188 * V_188 )
{
struct V_190 * V_191 ;
V_191 = F_90 ( V_187 , V_188 ) ;
if ( ! V_191 )
return NULL ;
return V_191 -> V_189 ;
}
static void F_92 ( struct V_186 * V_187 ,
struct V_188 * V_188 )
{
struct V_190 * V_191 ;
V_191 = F_90 ( V_187 , V_188 ) ;
if ( V_191 ) {
F_93 ( V_188 ) ;
F_94 ( & V_191 -> V_197 , & V_187 -> V_195 ) ;
F_86 ( V_191 ) ;
}
}
T_2 F_95 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_95 V_63 ;
struct V_201 V_65 ;
struct V_66 V_67 ;
struct V_202 * V_203 ;
struct V_53 * V_189 = NULL ;
struct V_204 V_205 = { NULL , 0 } ;
struct V_188 * V_188 = NULL ;
int V_16 = 0 ;
int V_206 = 0 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof V_63 ,
( unsigned long ) V_63 . V_74 + sizeof V_65 ,
V_61 - sizeof V_63 , V_62 - sizeof V_65 ) ;
F_53 ( & V_57 -> V_76 -> V_207 ) ;
if ( V_63 . V_204 != - 1 ) {
V_205 = F_96 ( V_63 . V_204 ) ;
if ( ! V_205 . V_57 ) {
V_16 = - V_208 ;
goto V_209;
}
V_188 = F_97 ( V_205 . V_57 ) ;
V_189 = F_91 ( V_57 -> V_76 , V_188 ) ;
if ( ! V_189 && ! ( V_63 . V_210 & V_211 ) ) {
V_16 = - V_212 ;
goto V_209;
}
if ( V_189 && V_63 . V_210 & V_213 ) {
V_16 = - V_72 ;
goto V_209;
}
}
V_203 = F_76 ( sizeof *V_203 , V_17 ) ;
if ( ! V_203 ) {
V_16 = - V_175 ;
goto V_209;
}
F_1 ( & V_203 -> V_28 , 0 , V_57 -> V_68 , & V_214 ) ;
F_31 ( & V_203 -> V_28 . V_9 ) ;
if ( ! V_189 ) {
V_189 = V_59 -> V_215 ( V_59 , V_57 -> V_68 , & V_67 ) ;
if ( F_55 ( V_189 ) ) {
V_16 = F_56 ( V_189 ) ;
goto V_73;
}
V_189 -> V_188 = V_188 ;
V_189 -> V_76 = V_59 ;
F_77 ( & V_189 -> V_179 , 0 ) ;
F_98 ( & V_189 -> V_216 ) ;
F_57 ( & V_189 -> V_217 ) ;
V_206 = 1 ;
}
F_77 ( & V_203 -> V_218 , 0 ) ;
V_203 -> V_28 . V_23 = V_189 ;
V_16 = F_14 ( & V_55 , & V_203 -> V_28 ) ;
if ( V_16 )
goto V_180;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_54 = V_203 -> V_28 . V_20 ;
if ( V_188 ) {
if ( V_206 ) {
V_16 = F_84 ( V_57 -> V_76 , V_188 , V_189 ) ;
if ( V_16 )
goto V_219;
}
F_99 ( & V_189 -> V_179 ) ;
}
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) ) {
V_16 = - V_71 ;
goto V_181;
}
if ( V_205 . V_57 )
F_100 ( V_205 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_203 -> V_28 . V_182 , & V_57 -> V_68 -> V_86 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_203 -> V_28 . V_12 = 1 ;
F_13 ( & V_203 -> V_28 . V_9 ) ;
F_64 ( & V_57 -> V_76 -> V_207 ) ;
return V_61 ;
V_181:
if ( V_188 ) {
if ( V_206 )
F_92 ( V_57 -> V_76 , V_188 ) ;
F_101 ( & V_189 -> V_179 ) ;
}
V_219:
F_20 ( & V_55 , & V_203 -> V_28 ) ;
V_180:
F_102 ( V_189 ) ;
V_73:
F_12 ( & V_203 -> V_28 ) ;
V_209:
if ( V_205 . V_57 )
F_100 ( V_205 ) ;
F_64 ( & V_57 -> V_76 -> V_207 ) ;
return V_16 ;
}
T_2 F_103 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_103 V_63 ;
struct V_1 * V_2 ;
struct V_53 * V_189 = NULL ;
struct V_188 * V_188 = NULL ;
struct V_202 * V_203 ;
int V_12 ;
int V_16 = 0 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_53 ( & V_57 -> V_76 -> V_207 ) ;
V_2 = F_30 ( & V_55 , V_63 . V_54 , V_57 -> V_68 ) ;
if ( ! V_2 ) {
V_16 = - V_72 ;
goto V_220;
}
V_189 = V_2 -> V_23 ;
V_188 = V_189 -> V_188 ;
V_203 = F_7 ( V_2 , struct V_202 , V_28 ) ;
if ( F_81 ( & V_203 -> V_218 ) ) {
F_12 ( V_2 ) ;
V_16 = - V_183 ;
goto V_220;
}
if ( ! V_188 || F_104 ( & V_189 -> V_179 ) ) {
V_16 = F_102 ( V_2 -> V_23 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
}
V_12 = V_2 -> V_12 ;
if ( V_188 && V_16 )
F_99 ( & V_189 -> V_179 ) ;
F_12 ( V_2 ) ;
if ( V_16 )
goto V_220;
if ( V_188 && ! V_12 )
F_92 ( V_57 -> V_76 , V_188 ) ;
F_20 ( & V_55 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_8 ( V_2 ) ;
V_16 = V_61 ;
V_220:
F_64 ( & V_57 -> V_76 -> V_207 ) ;
return V_16 ;
}
void F_105 ( struct V_186 * V_187 ,
struct V_53 * V_189 )
{
struct V_188 * V_188 ;
V_188 = V_189 -> V_188 ;
if ( V_188 && ! F_104 ( & V_189 -> V_179 ) )
return;
F_102 ( V_189 ) ;
if ( V_188 )
F_92 ( V_187 , V_188 ) ;
}
T_2 F_106 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_106 V_63 ;
struct V_221 V_65 ;
struct V_66 V_67 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_222 * V_223 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof V_63 ,
( unsigned long ) V_63 . V_74 + sizeof V_65 ,
V_61 - sizeof V_63 , V_62 - sizeof V_65 ) ;
if ( ( V_63 . V_224 & ~ V_225 ) != ( V_63 . V_226 & ~ V_225 ) )
return - V_72 ;
V_16 = F_107 ( V_63 . V_227 ) ;
if ( V_16 )
return V_16 ;
V_2 = F_76 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_175 ;
F_1 ( V_2 , 0 , V_57 -> V_68 , & V_228 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_63 . V_25 , V_57 -> V_68 ) ;
if ( ! V_27 ) {
V_16 = - V_72 ;
goto V_104;
}
if ( V_63 . V_227 & V_229 ) {
if ( ! ( V_27 -> V_76 -> V_98 . V_99 &
V_100 ) ) {
F_108 ( L_2 ) ;
V_16 = - V_72 ;
goto V_184;
}
}
V_223 = V_27 -> V_76 -> V_230 ( V_27 , V_63 . V_224 , V_63 . V_231 , V_63 . V_226 ,
V_63 . V_227 , & V_67 ) ;
if ( F_55 ( V_223 ) ) {
V_16 = F_56 ( V_223 ) ;
goto V_184;
}
V_223 -> V_76 = V_27 -> V_76 ;
V_223 -> V_27 = V_27 ;
V_223 -> V_28 = V_2 ;
F_99 ( & V_27 -> V_179 ) ;
V_2 -> V_23 = V_223 ;
V_16 = F_14 ( & V_232 , V_2 ) ;
if ( V_16 )
goto V_233;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_234 = V_223 -> V_234 ;
V_65 . V_235 = V_223 -> V_235 ;
V_65 . V_236 = V_2 -> V_20 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) ) {
V_16 = - V_71 ;
goto V_181;
}
F_34 ( V_27 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_2 -> V_182 , & V_57 -> V_68 -> V_78 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_61 ;
V_181:
F_20 ( & V_232 , V_2 ) ;
V_233:
F_109 ( V_223 ) ;
V_184:
F_34 ( V_27 ) ;
V_104:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_110 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_110 V_63 ;
struct V_237 V_65 ;
struct V_66 V_67 ;
struct V_24 * V_27 = NULL ;
struct V_222 * V_223 ;
struct V_24 * V_238 ;
int V_16 ;
struct V_1 * V_2 ;
if ( V_62 < sizeof( V_65 ) )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof( V_63 ) ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof( V_63 ) ,
( unsigned long ) V_63 . V_74 + sizeof( V_65 ) ,
V_61 - sizeof( V_63 ) , V_62 - sizeof( V_65 ) ) ;
if ( V_63 . V_239 & ~ V_240 || ! V_63 . V_239 )
return - V_72 ;
if ( ( V_63 . V_239 & V_241 ) &&
( ! V_63 . V_224 || ! V_63 . V_226 || 0 >= V_63 . V_231 ||
( V_63 . V_224 & ~ V_225 ) != ( V_63 . V_226 & ~ V_225 ) ) )
return - V_72 ;
V_2 = F_30 ( & V_232 , V_63 . V_236 ,
V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_223 = V_2 -> V_23 ;
if ( V_63 . V_239 & V_242 ) {
V_16 = F_107 ( V_63 . V_227 ) ;
if ( V_16 )
goto V_243;
}
if ( V_63 . V_239 & V_244 ) {
V_27 = F_33 ( V_63 . V_25 , V_57 -> V_68 ) ;
if ( ! V_27 ) {
V_16 = - V_72 ;
goto V_243;
}
}
V_238 = V_223 -> V_27 ;
V_16 = V_223 -> V_76 -> V_245 ( V_223 , V_63 . V_239 , V_63 . V_224 ,
V_63 . V_231 , V_63 . V_226 ,
V_63 . V_227 , V_27 , & V_67 ) ;
if ( ! V_16 ) {
if ( V_63 . V_239 & V_244 ) {
F_99 ( & V_27 -> V_179 ) ;
V_223 -> V_27 = V_27 ;
F_101 ( & V_238 -> V_179 ) ;
}
} else {
goto V_246;
}
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_234 = V_223 -> V_234 ;
V_65 . V_235 = V_223 -> V_235 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof( V_65 ) ) )
V_16 = - V_71 ;
else
V_16 = V_61 ;
V_246:
if ( V_63 . V_239 & V_244 )
F_34 ( V_27 ) ;
V_243:
F_12 ( V_223 -> V_28 ) ;
return V_16 ;
}
T_2 F_111 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_111 V_63 ;
struct V_222 * V_223 ;
struct V_1 * V_2 ;
int V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_2 = F_30 ( & V_232 , V_63 . V_236 , V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_223 = V_2 -> V_23 ;
V_16 = F_109 ( V_223 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_232 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_61 ;
}
T_2 F_112 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_112 V_63 ;
struct V_247 V_65 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_248 * V_249 ;
struct V_66 V_67 ;
int V_16 ;
if ( V_62 < sizeof( V_65 ) )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof( V_63 ) ) )
return - V_71 ;
V_2 = F_76 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_175 ;
F_1 ( V_2 , 0 , V_57 -> V_68 , & V_250 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_63 . V_25 , V_57 -> V_68 ) ;
if ( ! V_27 ) {
V_16 = - V_72 ;
goto V_104;
}
F_54 ( & V_67 , V_60 + sizeof( V_63 ) ,
( unsigned long ) V_63 . V_74 + sizeof( V_65 ) ,
V_61 - sizeof( V_63 ) - sizeof( struct V_251 ) ,
V_62 - sizeof( V_65 ) ) ;
V_249 = V_27 -> V_76 -> V_252 ( V_27 , V_63 . V_253 , & V_67 ) ;
if ( F_55 ( V_249 ) ) {
V_16 = F_56 ( V_249 ) ;
goto V_184;
}
V_249 -> V_76 = V_27 -> V_76 ;
V_249 -> V_27 = V_27 ;
V_249 -> V_28 = V_2 ;
F_99 ( & V_27 -> V_179 ) ;
V_2 -> V_23 = V_249 ;
V_16 = F_14 ( & V_254 , V_2 ) ;
if ( V_16 )
goto V_255;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_235 = V_249 -> V_235 ;
V_65 . V_256 = V_2 -> V_20 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof( V_65 ) ) ) {
V_16 = - V_71 ;
goto V_181;
}
F_34 ( V_27 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_2 -> V_182 , & V_57 -> V_68 -> V_79 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_61 ;
V_181:
F_20 ( & V_254 , V_2 ) ;
V_255:
F_113 ( V_249 ) ;
V_184:
F_34 ( V_27 ) ;
V_104:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_114 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_114 V_63 ;
struct V_248 * V_249 ;
struct V_1 * V_2 ;
int V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof( V_63 ) ) )
return - V_71 ;
V_2 = F_30 ( & V_254 , V_63 . V_256 , V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_249 = V_2 -> V_23 ;
V_16 = F_113 ( V_249 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_254 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_61 ;
}
T_2 F_115 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_115 V_63 ;
struct V_257 V_65 ;
struct V_57 * V_69 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_16 = F_60 ( V_103 ) ;
if ( V_16 < 0 )
return V_16 ;
V_65 . V_204 = V_16 ;
V_69 = F_61 ( V_57 , V_59 , 0 ) ;
if ( F_55 ( V_69 ) ) {
F_67 ( V_65 . V_204 ) ;
return F_56 ( V_69 ) ;
}
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) ) {
F_67 ( V_65 . V_204 ) ;
F_66 ( V_69 ) ;
return - V_71 ;
}
F_63 ( V_65 . V_204 , V_69 ) ;
return V_61 ;
}
static struct V_258 * F_116 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 ,
struct V_261 * V_63 ,
T_4 V_262 ,
int (* F_117)( struct V_56 * V_57 ,
struct V_258 * V_203 ,
struct V_263 * V_65 ,
struct V_66 * V_67 ,
void * V_5 ) ,
void * V_5 )
{
struct V_258 * V_203 ;
struct V_264 * V_265 = NULL ;
struct V_29 * V_32 ;
int V_16 ;
struct V_263 V_65 ;
struct V_266 V_111 = {} ;
if ( V_63 -> V_267 >= V_57 -> V_76 -> V_102 )
return F_118 ( - V_72 ) ;
V_203 = F_76 ( sizeof *V_203 , V_17 ) ;
if ( ! V_203 )
return F_118 ( - V_175 ) ;
F_1 ( & V_203 -> V_28 , V_63 -> V_3 , V_57 -> V_68 , & V_268 ) ;
F_31 ( & V_203 -> V_28 . V_9 ) ;
if ( V_63 -> V_269 >= 0 ) {
V_265 = F_119 ( V_63 -> V_269 ) ;
if ( ! V_265 ) {
V_16 = - V_72 ;
goto V_73;
}
}
V_203 -> V_270 = V_57 ;
V_203 -> V_271 = 0 ;
V_203 -> V_272 = 0 ;
F_57 ( & V_203 -> V_273 ) ;
F_57 ( & V_203 -> V_274 ) ;
V_111 . V_275 = V_63 -> V_275 ;
V_111 . V_267 = V_63 -> V_267 ;
if ( V_262 > F_120 ( F_121 ( * V_63 ) , V_239 ) + sizeof( V_63 -> V_239 ) )
V_111 . V_239 = V_63 -> V_239 ;
V_32 = V_59 -> F_116 ( V_59 , & V_111 ,
V_57 -> V_68 , V_260 ) ;
if ( F_55 ( V_32 ) ) {
V_16 = F_56 ( V_32 ) ;
goto V_107;
}
V_32 -> V_76 = V_59 ;
V_32 -> V_28 = & V_203 -> V_28 ;
V_32 -> V_276 = V_277 ;
V_32 -> V_278 = V_279 ;
V_32 -> V_280 = V_265 ;
F_77 ( & V_32 -> V_179 , 0 ) ;
V_203 -> V_28 . V_23 = V_32 ;
V_16 = F_14 ( & V_31 , & V_203 -> V_28 ) ;
if ( V_16 )
goto V_104;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_281 . V_30 = V_203 -> V_28 . V_20 ;
V_65 . V_281 . V_275 = V_32 -> V_275 ;
V_65 . V_282 = F_120 ( F_121 ( V_65 ) , V_282 ) +
sizeof( V_65 . V_282 ) ;
V_16 = F_117 ( V_57 , V_203 , & V_65 , V_259 , V_5 ) ;
if ( V_16 )
goto V_283;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_203 -> V_28 . V_182 , & V_57 -> V_68 -> V_80 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_203 -> V_28 . V_12 = 1 ;
F_13 ( & V_203 -> V_28 . V_9 ) ;
return V_203 ;
V_283:
F_20 ( & V_31 , & V_203 -> V_28 ) ;
V_104:
F_122 ( V_32 ) ;
V_107:
if ( V_265 )
F_123 ( V_57 , V_265 , V_203 ) ;
V_73:
F_12 ( & V_203 -> V_28 ) ;
return F_118 ( V_16 ) ;
}
static int F_124 ( struct V_56 * V_57 ,
struct V_258 * V_203 ,
struct V_263 * V_65 ,
struct V_66 * V_259 , void * V_5 )
{
if ( F_125 ( V_259 , & V_65 -> V_281 , sizeof( V_65 -> V_281 ) ) )
return - V_71 ;
return 0 ;
}
T_2 F_126 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_126 V_63 ;
struct V_261 V_284 ;
struct V_285 V_65 ;
struct V_66 V_259 ;
struct V_66 V_260 ;
struct V_258 * V_203 ;
if ( V_62 < sizeof( V_65 ) )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof( V_63 ) ) )
return - V_71 ;
F_54 ( & V_259 , V_60 , ( unsigned long ) V_63 . V_74 , sizeof( V_63 ) , sizeof( V_65 ) ) ;
F_54 ( & V_260 , V_60 + sizeof( V_63 ) ,
( unsigned long ) V_63 . V_74 + sizeof( V_65 ) ,
V_61 - sizeof( V_63 ) , V_62 - sizeof( V_65 ) ) ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_284 . V_3 = V_63 . V_3 ;
V_284 . V_275 = V_63 . V_275 ;
V_284 . V_267 = V_63 . V_267 ;
V_284 . V_269 = V_63 . V_269 ;
V_203 = F_116 ( V_57 , V_59 , & V_259 , & V_260 , & V_284 ,
F_120 ( F_121 ( V_284 ) , V_269 ) +
sizeof( V_63 . V_269 ) , F_124 ,
NULL ) ;
if ( F_55 ( V_203 ) )
return F_56 ( V_203 ) ;
return V_61 ;
}
static int F_127 ( struct V_56 * V_57 ,
struct V_258 * V_203 ,
struct V_263 * V_65 ,
struct V_66 * V_259 , void * V_5 )
{
if ( F_125 ( V_259 , V_65 , V_65 -> V_282 ) )
return - V_71 ;
return 0 ;
}
int V_261 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct V_263 V_65 ;
struct V_261 V_63 ;
struct V_258 * V_203 ;
int V_73 ;
if ( V_259 -> V_286 < sizeof( V_63 ) )
return - V_72 ;
V_73 = F_128 ( & V_63 , V_259 , sizeof( V_63 ) ) ;
if ( V_73 )
return V_73 ;
if ( V_63 . V_287 )
return - V_72 ;
if ( V_63 . V_288 )
return - V_72 ;
if ( V_259 -> V_289 < ( F_120 ( F_121 ( V_65 ) , V_282 ) +
sizeof( V_65 . V_282 ) ) )
return - V_70 ;
V_203 = F_116 ( V_57 , V_59 , V_259 , V_260 , & V_63 ,
F_129 ( V_259 -> V_286 , sizeof( V_63 ) ) ,
F_127 , NULL ) ;
if ( F_55 ( V_203 ) )
return F_56 ( V_203 ) ;
return 0 ;
}
T_2 F_130 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_130 V_63 ;
struct V_290 V_65 ;
struct V_66 V_67 ;
struct V_29 * V_32 ;
int V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof V_63 ,
( unsigned long ) V_63 . V_74 + sizeof V_65 ,
V_61 - sizeof V_63 , V_62 - sizeof V_65 ) ;
V_32 = F_35 ( V_63 . V_30 , V_57 -> V_68 , 0 ) ;
if ( ! V_32 )
return - V_72 ;
V_16 = V_32 -> V_76 -> V_291 ( V_32 , V_63 . V_275 , & V_67 ) ;
if ( V_16 )
goto V_220;
V_65 . V_275 = V_32 -> V_275 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 . V_275 ) )
V_16 = - V_71 ;
V_220:
F_36 ( V_32 ) ;
return V_16 ? V_16 : V_61 ;
}
static int F_131 ( void T_3 * V_292 , struct V_293 * V_294 )
{
struct V_295 V_296 ;
V_296 . V_297 = V_294 -> V_297 ;
V_296 . V_298 = V_294 -> V_298 ;
V_296 . V_299 = V_294 -> V_299 ;
V_296 . V_300 = V_294 -> V_300 ;
V_296 . V_301 = V_294 -> V_301 ;
V_296 . V_302 . V_303 = ( V_304 V_305 ) V_294 -> V_302 . V_303 ;
V_296 . V_306 = V_294 -> V_48 -> V_306 ;
V_296 . V_307 = V_294 -> V_307 ;
V_296 . V_308 = V_294 -> V_308 ;
V_296 . V_309 = V_294 -> V_309 ;
V_296 . V_310 = V_294 -> V_310 ;
V_296 . V_311 = V_294 -> V_311 ;
V_296 . V_312 = V_294 -> V_312 ;
V_296 . V_153 = V_294 -> V_153 ;
V_296 . V_288 = 0 ;
if ( F_62 ( V_292 , & V_296 , sizeof V_296 ) )
return - V_71 ;
return 0 ;
}
T_2 F_132 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_132 V_63 ;
struct V_313 V_65 ;
T_5 T_3 * V_314 ;
T_5 T_3 * V_315 ;
struct V_29 * V_32 ;
struct V_293 V_294 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_32 = F_35 ( V_63 . V_30 , V_57 -> V_68 , 0 ) ;
if ( ! V_32 )
return - V_72 ;
V_314 = ( void T_3 * ) ( unsigned long ) V_63 . V_74 ;
V_315 = V_314 + sizeof V_65 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
while ( V_65 . V_316 < V_63 . V_317 ) {
V_16 = F_133 ( V_32 , 1 , & V_294 ) ;
if ( V_16 < 0 )
goto V_318;
if ( ! V_16 )
break;
V_16 = F_131 ( V_315 , & V_294 ) ;
if ( V_16 )
goto V_318;
V_315 += sizeof( struct V_295 ) ;
++ V_65 . V_316 ;
}
if ( F_62 ( V_314 , & V_65 , sizeof V_65 ) ) {
V_16 = - V_71 ;
goto V_318;
}
V_16 = V_61 ;
V_318:
F_36 ( V_32 ) ;
return V_16 ;
}
T_2 F_134 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_134 V_63 ;
struct V_29 * V_32 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_32 = F_35 ( V_63 . V_30 , V_57 -> V_68 , 0 ) ;
if ( ! V_32 )
return - V_72 ;
F_135 ( V_32 , V_63 . V_319 ?
V_320 : V_321 ) ;
F_36 ( V_32 ) ;
return V_61 ;
}
T_2 F_136 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_136 V_63 ;
struct V_322 V_65 ;
struct V_1 * V_2 ;
struct V_29 * V_32 ;
struct V_258 * V_203 ;
struct V_264 * V_265 ;
int V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_2 = F_30 ( & V_31 , V_63 . V_30 , V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_32 = V_2 -> V_23 ;
V_265 = V_32 -> V_280 ;
V_203 = F_7 ( V_32 -> V_28 , struct V_258 , V_28 ) ;
V_16 = F_122 ( V_32 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_31 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_123 ( V_57 , V_265 , V_203 ) ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_271 = V_203 -> V_271 ;
V_65 . V_272 = V_203 -> V_272 ;
F_8 ( V_2 ) ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
return - V_71 ;
return V_61 ;
}
static int F_137 ( struct V_56 * V_57 ,
struct V_66 * V_259 ,
struct V_66 * V_260 ,
struct V_323 * V_63 ,
T_4 V_262 ,
int (* F_117)( struct V_56 * V_57 ,
struct V_324 * V_65 ,
struct V_66 * V_67 ) ,
void * V_5 )
{
struct V_325 * V_203 ;
struct V_58 * V_76 ;
struct V_24 * V_27 = NULL ;
struct V_53 * V_189 = NULL ;
struct V_1 * V_326 ( V_327 ) ;
struct V_29 * V_328 = NULL , * V_329 = NULL ;
struct V_49 * V_52 = NULL ;
struct V_37 * V_48 ;
char * V_60 ;
struct V_330 V_111 = {} ;
struct V_324 V_65 ;
int V_16 ;
struct V_44 * V_331 = NULL ;
bool V_332 = true ;
if ( V_63 -> V_333 == V_334 && ! F_138 ( V_335 ) )
return - V_336 ;
V_203 = F_139 ( sizeof *V_203 , V_17 ) ;
if ( ! V_203 )
return - V_175 ;
F_1 ( & V_203 -> V_337 . V_28 , V_63 -> V_3 , V_57 -> V_68 ,
& V_338 ) ;
F_31 ( & V_203 -> V_337 . V_28 . V_9 ) ;
if ( V_262 >= F_120 ( F_121 ( * V_63 ) , V_339 ) +
sizeof( V_63 -> V_339 ) &&
( V_63 -> V_287 & V_340 ) ) {
V_331 = F_42 ( V_63 -> V_339 ,
V_57 -> V_68 ) ;
if ( ! V_331 ) {
V_16 = - V_72 ;
goto V_184;
}
V_111 . V_341 = V_331 ;
}
if ( ( V_262 >= F_120 ( F_121 ( * V_63 ) , V_342 ) +
sizeof( V_63 -> V_342 ) ) && V_63 -> V_342 ) {
V_16 = - V_343 ;
goto V_184;
}
if ( V_331 && ( V_63 -> V_344 || V_63 -> V_345 || V_63 -> V_346 ) ) {
V_16 = - V_72 ;
goto V_184;
}
if ( V_331 && ! V_63 -> V_347 )
V_332 = false ;
if ( V_63 -> V_333 == V_348 ) {
V_189 = F_49 ( V_63 -> V_25 , V_57 -> V_68 ,
& V_327 ) ;
if ( ! V_189 ) {
V_16 = - V_72 ;
goto V_184;
}
V_76 = V_189 -> V_76 ;
} else {
if ( V_63 -> V_333 == V_349 ) {
V_63 -> V_344 = 0 ;
V_63 -> V_345 = 0 ;
} else {
if ( V_63 -> V_346 ) {
V_52 = F_47 ( V_63 -> V_50 ,
V_57 -> V_68 ) ;
if ( ! V_52 || V_52 -> V_350 != V_351 ) {
V_16 = - V_72 ;
goto V_184;
}
}
if ( ! V_331 ) {
if ( V_63 -> V_352 != V_63 -> V_353 ) {
V_329 = F_35 ( V_63 -> V_352 ,
V_57 -> V_68 , 0 ) ;
if ( ! V_329 ) {
V_16 = - V_72 ;
goto V_184;
}
}
}
}
if ( V_332 )
V_328 = F_35 ( V_63 -> V_353 , V_57 -> V_68 , ! ! V_329 ) ;
if ( ! V_331 )
V_329 = V_329 ? : V_328 ;
V_27 = F_33 ( V_63 -> V_25 , V_57 -> V_68 ) ;
if ( ! V_27 || ( ! V_328 && V_332 ) ) {
V_16 = - V_72 ;
goto V_184;
}
V_76 = V_27 -> V_76 ;
}
V_111 . V_278 = V_354 ;
V_111 . V_355 = V_57 ;
V_111 . V_356 = V_328 ;
V_111 . V_357 = V_329 ;
V_111 . V_52 = V_52 ;
V_111 . V_189 = V_189 ;
V_111 . V_358 = V_63 -> V_359 ? V_360 :
V_361 ;
V_111 . V_333 = V_63 -> V_333 ;
V_111 . V_362 = 0 ;
V_111 . V_363 . V_347 = V_63 -> V_347 ;
V_111 . V_363 . V_344 = V_63 -> V_344 ;
V_111 . V_363 . V_364 = V_63 -> V_364 ;
V_111 . V_363 . V_345 = V_63 -> V_345 ;
V_111 . V_363 . V_365 = V_63 -> V_365 ;
V_203 -> V_337 . V_366 = 0 ;
F_57 ( & V_203 -> V_337 . V_367 ) ;
F_57 ( & V_203 -> V_368 ) ;
if ( V_262 >= F_120 ( F_121 ( * V_63 ) , V_362 ) +
sizeof( V_63 -> V_362 ) )
V_111 . V_362 = V_63 -> V_362 ;
if ( V_111 . V_362 & ~ ( V_369 |
V_370 |
V_371 |
V_372 |
V_373 ) ) {
V_16 = - V_72 ;
goto V_184;
}
V_60 = ( void * ) V_63 + sizeof( * V_63 ) ;
if ( V_262 > sizeof( * V_63 ) )
if ( ! ( V_60 [ 0 ] == 0 && ! memcmp ( V_60 , V_60 + 1 ,
V_262 - sizeof( * V_63 ) - 1 ) ) ) {
V_16 = - V_72 ;
goto V_184;
}
if ( V_63 -> V_333 == V_348 )
V_48 = F_140 ( V_27 , & V_111 ) ;
else
V_48 = V_76 -> F_137 ( V_27 , & V_111 , V_260 ) ;
if ( F_55 ( V_48 ) ) {
V_16 = F_56 ( V_48 ) ;
goto V_184;
}
if ( V_63 -> V_333 != V_348 ) {
V_48 -> V_374 = V_48 ;
V_48 -> V_76 = V_76 ;
V_48 -> V_27 = V_27 ;
V_48 -> V_356 = V_111 . V_356 ;
V_48 -> V_357 = V_111 . V_357 ;
V_48 -> V_52 = V_111 . V_52 ;
V_48 -> V_341 = V_331 ;
V_48 -> V_278 = V_111 . V_278 ;
V_48 -> V_355 = V_111 . V_355 ;
V_48 -> V_333 = V_111 . V_333 ;
F_77 ( & V_48 -> V_179 , 0 ) ;
F_99 ( & V_27 -> V_179 ) ;
if ( V_111 . V_356 )
F_99 ( & V_111 . V_356 -> V_179 ) ;
if ( V_111 . V_357 )
F_99 ( & V_111 . V_357 -> V_179 ) ;
if ( V_111 . V_52 )
F_99 ( & V_111 . V_52 -> V_179 ) ;
if ( V_331 )
F_99 ( & V_331 -> V_179 ) ;
}
V_48 -> V_28 = & V_203 -> V_337 . V_28 ;
V_203 -> V_337 . V_28 . V_23 = V_48 ;
V_16 = F_14 ( & V_39 , & V_203 -> V_337 . V_28 ) ;
if ( V_16 )
goto V_375;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_281 . V_376 = V_48 -> V_306 ;
V_65 . V_281 . V_38 = V_203 -> V_337 . V_28 . V_20 ;
V_65 . V_281 . V_345 = V_111 . V_363 . V_345 ;
V_65 . V_281 . V_364 = V_111 . V_363 . V_364 ;
V_65 . V_281 . V_344 = V_111 . V_363 . V_344 ;
V_65 . V_281 . V_347 = V_111 . V_363 . V_347 ;
V_65 . V_281 . V_365 = V_111 . V_363 . V_365 ;
V_65 . V_282 = F_120 ( F_121 ( V_65 ) , V_282 ) +
sizeof( V_65 . V_282 ) ;
V_16 = F_117 ( V_57 , & V_65 , V_259 ) ;
if ( V_16 )
goto V_283;
if ( V_189 ) {
V_203 -> V_377 = F_7 ( V_327 , struct V_202 ,
V_28 ) ;
F_99 ( & V_203 -> V_377 -> V_218 ) ;
F_50 ( V_327 ) ;
}
if ( V_27 )
F_34 ( V_27 ) ;
if ( V_328 )
F_36 ( V_328 ) ;
if ( V_329 && V_329 != V_328 )
F_36 ( V_329 ) ;
if ( V_52 )
F_48 ( V_52 ) ;
if ( V_331 )
F_43 ( V_331 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_203 -> V_337 . V_28 . V_182 , & V_57 -> V_68 -> V_81 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_203 -> V_337 . V_28 . V_12 = 1 ;
F_13 ( & V_203 -> V_337 . V_28 . V_9 ) ;
return 0 ;
V_283:
F_20 ( & V_39 , & V_203 -> V_337 . V_28 ) ;
V_375:
F_141 ( V_48 ) ;
V_184:
if ( V_189 )
F_50 ( V_327 ) ;
if ( V_27 )
F_34 ( V_27 ) ;
if ( V_328 )
F_36 ( V_328 ) ;
if ( V_329 && V_329 != V_328 )
F_36 ( V_329 ) ;
if ( V_52 )
F_48 ( V_52 ) ;
if ( V_331 )
F_43 ( V_331 ) ;
F_12 ( & V_203 -> V_337 . V_28 ) ;
return V_16 ;
}
static int F_142 ( struct V_56 * V_57 ,
struct V_324 * V_65 ,
struct V_66 * V_259 )
{
if ( F_125 ( V_259 , & V_65 -> V_281 , sizeof( V_65 -> V_281 ) ) )
return - V_71 ;
return 0 ;
}
T_2 F_143 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_143 V_63 ;
struct V_323 V_284 ;
struct V_66 V_259 ;
struct V_66 V_260 ;
T_2 V_378 = sizeof( struct V_379 ) ;
int V_73 ;
if ( V_62 < V_378 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof( V_63 ) ) )
return - V_71 ;
F_54 ( & V_259 , V_60 , ( unsigned long ) V_63 . V_74 , sizeof( V_63 ) ,
V_378 ) ;
F_54 ( & V_260 , V_60 + sizeof( V_63 ) ,
( unsigned long ) V_63 . V_74 + V_378 ,
V_61 - sizeof( V_63 ) - sizeof( struct V_251 ) ,
V_62 - V_378 ) ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_284 . V_3 = V_63 . V_3 ;
V_284 . V_25 = V_63 . V_25 ;
V_284 . V_353 = V_63 . V_353 ;
V_284 . V_352 = V_63 . V_352 ;
V_284 . V_50 = V_63 . V_50 ;
V_284 . V_347 = V_63 . V_347 ;
V_284 . V_344 = V_63 . V_344 ;
V_284 . V_364 = V_63 . V_364 ;
V_284 . V_345 = V_63 . V_345 ;
V_284 . V_365 = V_63 . V_365 ;
V_284 . V_359 = V_63 . V_359 ;
V_284 . V_333 = V_63 . V_333 ;
V_284 . V_346 = V_63 . V_346 ;
V_73 = F_137 ( V_57 , & V_259 , & V_260 , & V_284 ,
F_120 ( F_121 ( V_284 ) , V_346 ) +
sizeof( V_63 . V_346 ) , F_142 ,
NULL ) ;
if ( V_73 )
return V_73 ;
return V_61 ;
}
static int F_144 ( struct V_56 * V_57 ,
struct V_324 * V_65 ,
struct V_66 * V_259 )
{
if ( F_125 ( V_259 , V_65 , V_65 -> V_282 ) )
return - V_71 ;
return 0 ;
}
int V_323 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct V_324 V_65 ;
struct V_323 V_63 = { 0 } ;
int V_73 ;
if ( V_259 -> V_286 < ( F_120 ( F_121 ( V_63 ) , V_287 ) +
sizeof( V_63 . V_287 ) ) )
return - V_72 ;
V_73 = F_128 ( & V_63 , V_259 , F_129 ( sizeof( V_63 ) , V_259 -> V_286 ) ) ;
if ( V_73 )
return V_73 ;
if ( V_63 . V_287 & ~ V_380 )
return - V_72 ;
if ( V_63 . V_288 )
return - V_72 ;
if ( V_259 -> V_289 < ( F_120 ( F_121 ( V_65 ) , V_282 ) +
sizeof( V_65 . V_282 ) ) )
return - V_70 ;
V_73 = F_137 ( V_57 , V_259 , V_260 , & V_63 ,
F_129 ( V_259 -> V_286 , sizeof( V_63 ) ) ,
F_144 , NULL ) ;
if ( V_73 )
return V_73 ;
return 0 ;
}
T_2 F_145 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 , int V_62 )
{
struct F_145 V_63 ;
struct V_379 V_65 ;
struct V_66 V_67 ;
struct V_325 * V_203 ;
struct V_53 * V_189 ;
struct V_1 * V_326 ( V_327 ) ;
struct V_37 * V_48 ;
struct V_381 V_111 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof V_63 ,
( unsigned long ) V_63 . V_74 + sizeof V_65 ,
V_61 - sizeof V_63 , V_62 - sizeof V_65 ) ;
V_203 = F_76 ( sizeof *V_203 , V_17 ) ;
if ( ! V_203 )
return - V_175 ;
F_1 ( & V_203 -> V_337 . V_28 , V_63 . V_3 , V_57 -> V_68 , & V_338 ) ;
F_31 ( & V_203 -> V_337 . V_28 . V_9 ) ;
V_189 = F_49 ( V_63 . V_25 , V_57 -> V_68 , & V_327 ) ;
if ( ! V_189 ) {
V_16 = - V_72 ;
goto V_184;
}
V_111 . V_278 = V_354 ;
V_111 . V_355 = V_57 ;
V_111 . V_306 = V_63 . V_376 ;
V_111 . V_333 = V_63 . V_333 ;
V_203 -> V_337 . V_366 = 0 ;
F_57 ( & V_203 -> V_337 . V_367 ) ;
F_57 ( & V_203 -> V_368 ) ;
V_48 = F_146 ( V_189 , & V_111 ) ;
if ( F_55 ( V_48 ) ) {
V_16 = F_56 ( V_48 ) ;
goto V_184;
}
V_48 -> V_28 = & V_203 -> V_337 . V_28 ;
V_203 -> V_337 . V_28 . V_23 = V_48 ;
V_16 = F_14 ( & V_39 , & V_203 -> V_337 . V_28 ) ;
if ( V_16 )
goto V_375;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_376 = V_48 -> V_306 ;
V_65 . V_38 = V_203 -> V_337 . V_28 . V_20 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) ) {
V_16 = - V_71 ;
goto V_382;
}
V_203 -> V_377 = F_7 ( V_327 , struct V_202 , V_28 ) ;
F_99 ( & V_203 -> V_377 -> V_218 ) ;
F_50 ( V_327 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_203 -> V_337 . V_28 . V_182 , & V_57 -> V_68 -> V_81 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_203 -> V_337 . V_28 . V_12 = 1 ;
F_13 ( & V_203 -> V_337 . V_28 . V_9 ) ;
return V_61 ;
V_382:
F_20 ( & V_39 , & V_203 -> V_337 . V_28 ) ;
V_375:
F_141 ( V_48 ) ;
V_184:
F_50 ( V_327 ) ;
F_12 ( & V_203 -> V_337 . V_28 ) ;
return V_16 ;
}
T_2 F_147 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_147 V_63 ;
struct V_383 V_65 ;
struct V_37 * V_48 ;
struct V_384 * V_111 ;
struct V_330 * V_385 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_111 = F_76 ( sizeof *V_111 , V_17 ) ;
V_385 = F_76 ( sizeof *V_385 , V_17 ) ;
if ( ! V_111 || ! V_385 ) {
V_16 = - V_175 ;
goto V_220;
}
V_48 = F_39 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 ) {
V_16 = - V_72 ;
goto V_220;
}
V_16 = F_148 ( V_48 , V_111 , V_63 . V_386 , V_385 ) ;
F_45 ( V_48 ) ;
if ( V_16 )
goto V_220;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_387 = V_111 -> V_387 ;
V_65 . V_388 = V_111 -> V_388 ;
V_65 . V_389 = V_111 -> V_389 ;
V_65 . V_390 = V_111 -> V_390 ;
V_65 . V_391 = V_111 -> V_391 ;
V_65 . V_392 = V_111 -> V_392 ;
V_65 . V_393 = V_111 -> V_393 ;
V_65 . V_394 = V_111 -> V_394 ;
V_65 . V_395 = V_111 -> V_395 ;
V_65 . V_309 = V_111 -> V_309 ;
V_65 . V_396 = V_111 -> V_396 ;
V_65 . V_397 = V_111 -> V_397 ;
V_65 . V_398 = V_111 -> V_398 ;
V_65 . V_399 = V_111 -> V_399 ;
V_65 . V_400 = V_111 -> V_400 ;
V_65 . V_153 = V_111 -> V_153 ;
V_65 . V_401 = V_111 -> V_401 ;
V_65 . V_402 = V_111 -> V_402 ;
V_65 . V_403 = V_111 -> V_403 ;
V_65 . V_404 = V_111 -> V_404 ;
V_65 . V_405 = V_111 -> V_405 ;
memcpy ( V_65 . V_292 . V_406 , V_111 -> V_407 . V_408 . V_406 . V_409 , 16 ) ;
V_65 . V_292 . V_410 = V_111 -> V_407 . V_408 . V_410 ;
V_65 . V_292 . V_411 = V_111 -> V_407 . V_408 . V_411 ;
V_65 . V_292 . V_412 = V_111 -> V_407 . V_408 . V_412 ;
V_65 . V_292 . V_413 = V_111 -> V_407 . V_408 . V_413 ;
V_65 . V_292 . V_414 = V_111 -> V_407 . V_414 ;
V_65 . V_292 . V_311 = V_111 -> V_407 . V_311 ;
V_65 . V_292 . V_415 = V_111 -> V_407 . V_415 ;
V_65 . V_292 . V_416 = V_111 -> V_407 . V_416 ;
V_65 . V_292 . V_417 = ! ! ( V_111 -> V_407 . V_418 & V_419 ) ;
V_65 . V_292 . V_153 = V_111 -> V_407 . V_153 ;
memcpy ( V_65 . V_420 . V_406 , V_111 -> V_421 . V_408 . V_406 . V_409 , 16 ) ;
V_65 . V_420 . V_410 = V_111 -> V_421 . V_408 . V_410 ;
V_65 . V_420 . V_411 = V_111 -> V_421 . V_408 . V_411 ;
V_65 . V_420 . V_412 = V_111 -> V_421 . V_408 . V_412 ;
V_65 . V_420 . V_413 = V_111 -> V_421 . V_408 . V_413 ;
V_65 . V_420 . V_414 = V_111 -> V_421 . V_414 ;
V_65 . V_420 . V_311 = V_111 -> V_421 . V_311 ;
V_65 . V_420 . V_415 = V_111 -> V_421 . V_415 ;
V_65 . V_420 . V_416 = V_111 -> V_421 . V_416 ;
V_65 . V_420 . V_417 = ! ! ( V_111 -> V_421 . V_418 & V_419 ) ;
V_65 . V_420 . V_153 = V_111 -> V_421 . V_153 ;
V_65 . V_347 = V_385 -> V_363 . V_347 ;
V_65 . V_344 = V_385 -> V_363 . V_344 ;
V_65 . V_364 = V_385 -> V_363 . V_364 ;
V_65 . V_345 = V_385 -> V_363 . V_345 ;
V_65 . V_365 = V_385 -> V_363 . V_365 ;
V_65 . V_359 = V_385 -> V_358 == V_360 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
V_16 = - V_71 ;
V_220:
F_86 ( V_111 ) ;
F_86 ( V_385 ) ;
return V_16 ? V_16 : V_61 ;
}
static int F_149 ( enum V_422 V_333 , int V_423 )
{
switch ( V_333 ) {
case V_349 :
return V_423 & ~ ( V_424 | V_425 ) ;
case V_348 :
return V_423 & ~ ( V_426 | V_427 |
V_428 ) ;
default:
return V_423 ;
}
}
static int F_150 ( struct V_56 * V_57 ,
struct V_429 * V_63 , struct V_66 * V_67 )
{
struct V_384 * V_111 ;
struct V_37 * V_48 ;
int V_16 ;
V_111 = F_76 ( sizeof *V_111 , V_17 ) ;
if ( ! V_111 )
return - V_175 ;
V_48 = F_39 ( V_63 -> V_281 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 ) {
V_16 = - V_72 ;
goto V_220;
}
V_111 -> V_387 = V_63 -> V_281 . V_387 ;
V_111 -> V_388 = V_63 -> V_281 . V_388 ;
V_111 -> V_389 = V_63 -> V_281 . V_389 ;
V_111 -> V_390 = V_63 -> V_281 . V_390 ;
V_111 -> V_391 = V_63 -> V_281 . V_391 ;
V_111 -> V_392 = V_63 -> V_281 . V_392 ;
V_111 -> V_393 = V_63 -> V_281 . V_393 ;
V_111 -> V_394 = V_63 -> V_281 . V_394 ;
V_111 -> V_395 = V_63 -> V_281 . V_395 ;
V_111 -> V_309 = V_63 -> V_281 . V_309 ;
V_111 -> V_396 = V_63 -> V_281 . V_396 ;
V_111 -> V_430 = V_63 -> V_281 . V_430 ;
V_111 -> V_398 = V_63 -> V_281 . V_398 ;
V_111 -> V_399 = V_63 -> V_281 . V_399 ;
V_111 -> V_400 = V_63 -> V_281 . V_400 ;
V_111 -> V_153 = V_63 -> V_281 . V_153 ;
V_111 -> V_401 = V_63 -> V_281 . V_401 ;
V_111 -> V_402 = V_63 -> V_281 . V_402 ;
V_111 -> V_403 = V_63 -> V_281 . V_403 ;
V_111 -> V_404 = V_63 -> V_281 . V_404 ;
V_111 -> V_405 = V_63 -> V_281 . V_405 ;
V_111 -> V_431 = V_63 -> V_431 ;
memcpy ( V_111 -> V_407 . V_408 . V_406 . V_409 , V_63 -> V_281 . V_292 . V_406 , 16 ) ;
V_111 -> V_407 . V_408 . V_410 = V_63 -> V_281 . V_292 . V_410 ;
V_111 -> V_407 . V_408 . V_411 = V_63 -> V_281 . V_292 . V_411 ;
V_111 -> V_407 . V_408 . V_412 = V_63 -> V_281 . V_292 . V_412 ;
V_111 -> V_407 . V_408 . V_413 = V_63 -> V_281 . V_292 . V_413 ;
V_111 -> V_407 . V_414 = V_63 -> V_281 . V_292 . V_414 ;
V_111 -> V_407 . V_311 = V_63 -> V_281 . V_292 . V_311 ;
V_111 -> V_407 . V_415 = V_63 -> V_281 . V_292 . V_415 ;
V_111 -> V_407 . V_416 = V_63 -> V_281 . V_292 . V_416 ;
V_111 -> V_407 . V_418 = V_63 -> V_281 . V_292 . V_417 ?
V_419 : 0 ;
V_111 -> V_407 . V_153 = V_63 -> V_281 . V_292 . V_153 ;
memcpy ( V_111 -> V_421 . V_408 . V_406 . V_409 , V_63 -> V_281 . V_420 . V_406 , 16 ) ;
V_111 -> V_421 . V_408 . V_410 = V_63 -> V_281 . V_420 . V_410 ;
V_111 -> V_421 . V_408 . V_411 = V_63 -> V_281 . V_420 . V_411 ;
V_111 -> V_421 . V_408 . V_412 = V_63 -> V_281 . V_420 . V_412 ;
V_111 -> V_421 . V_408 . V_413 = V_63 -> V_281 . V_420 . V_413 ;
V_111 -> V_421 . V_414 = V_63 -> V_281 . V_420 . V_414 ;
V_111 -> V_421 . V_311 = V_63 -> V_281 . V_420 . V_311 ;
V_111 -> V_421 . V_415 = V_63 -> V_281 . V_420 . V_415 ;
V_111 -> V_421 . V_416 = V_63 -> V_281 . V_420 . V_416 ;
V_111 -> V_421 . V_418 = V_63 -> V_281 . V_420 . V_417 ?
V_419 : 0 ;
V_111 -> V_421 . V_153 = V_63 -> V_281 . V_420 . V_153 ;
if ( V_48 -> V_374 == V_48 ) {
if ( V_63 -> V_281 . V_386 & V_432 ) {
V_16 = F_151 ( V_48 -> V_76 , & V_111 -> V_407 ) ;
if ( V_16 )
goto V_433;
}
V_16 = V_48 -> V_76 -> F_150 ( V_48 , V_111 ,
F_149 ( V_48 -> V_333 ,
V_63 -> V_281 . V_386 ) ,
V_67 ) ;
} else {
V_16 = F_152 ( V_48 , V_111 ,
F_149 ( V_48 -> V_333 ,
V_63 -> V_281 . V_386 ) ) ;
}
V_433:
F_45 ( V_48 ) ;
V_220:
F_86 ( V_111 ) ;
return V_16 ;
}
T_2 F_153 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct V_429 V_63 = {} ;
struct V_66 V_67 ;
int V_16 ;
if ( F_52 ( & V_63 . V_281 , V_60 , sizeof( V_63 . V_281 ) ) )
return - V_71 ;
if ( V_63 . V_281 . V_386 &
~ ( ( V_434 << 1 ) - 1 ) )
return - V_343 ;
F_54 ( & V_67 , V_60 + sizeof( V_63 . V_281 ) , NULL ,
V_61 - sizeof( V_63 . V_281 ) , V_62 ) ;
V_16 = F_150 ( V_57 , & V_63 , & V_67 ) ;
if ( V_16 )
return V_16 ;
return V_61 ;
}
int V_429 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct V_429 V_63 = {} ;
int V_16 ;
F_154 ( V_435 == ( 1 << 31 ) ) ;
if ( V_259 -> V_286 < sizeof( V_63 . V_281 ) )
return - V_72 ;
V_16 = F_128 ( & V_63 , V_259 , F_129 ( sizeof( V_63 ) , V_259 -> V_286 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_63 . V_281 . V_386 &
~ ( ( V_435 << 1 ) - 1 ) )
return - V_343 ;
if ( V_259 -> V_286 > sizeof( V_63 ) ) {
if ( F_155 ( V_259 , sizeof( V_63 ) ,
V_259 -> V_286 - sizeof( V_63 ) ) )
return - V_343 ;
}
V_16 = F_150 ( V_57 , & V_63 , V_260 ) ;
return V_16 ;
}
T_2 F_156 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_156 V_63 ;
struct V_436 V_65 ;
struct V_1 * V_2 ;
struct V_37 * V_48 ;
struct V_325 * V_203 ;
int V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_2 = F_30 ( & V_39 , V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_48 = V_2 -> V_23 ;
V_203 = F_7 ( V_2 , struct V_325 , V_337 . V_28 ) ;
if ( ! F_157 ( & V_203 -> V_368 ) ) {
F_12 ( V_2 ) ;
return - V_183 ;
}
V_16 = F_141 ( V_48 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_203 -> V_377 )
F_101 ( & V_203 -> V_377 -> V_218 ) ;
F_20 ( & V_39 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_158 ( V_57 , & V_203 -> V_337 ) ;
V_65 . V_366 = V_203 -> V_337 . V_366 ;
F_8 ( V_2 ) ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
return - V_71 ;
return V_61 ;
}
static void * F_159 ( T_4 V_437 , V_304 V_438 )
{
return F_76 ( F_160 ( V_437 , sizeof ( struct V_439 ) ) +
V_438 * sizeof ( struct V_439 ) , V_17 ) ;
}
T_2 F_161 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_161 V_63 ;
struct V_440 V_65 ;
struct V_441 * V_442 ;
struct V_443 * V_444 = NULL , * V_445 , * V_446 , * V_447 ;
struct V_37 * V_48 ;
int V_448 , V_449 ;
int V_450 ;
T_2 V_16 = - V_72 ;
T_4 V_451 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
if ( V_61 < sizeof V_63 + V_63 . V_452 * V_63 . V_453 +
V_63 . V_454 * sizeof ( struct V_455 ) )
return - V_72 ;
if ( V_63 . V_452 < sizeof ( struct V_441 ) )
return - V_72 ;
V_442 = F_76 ( V_63 . V_452 , V_17 ) ;
if ( ! V_442 )
return - V_175 ;
V_48 = F_39 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 )
goto V_220;
V_450 = V_48 -> V_333 == V_456 ;
V_449 = 0 ;
V_445 = NULL ;
for ( V_448 = 0 ; V_448 < V_63 . V_453 ; ++ V_448 ) {
if ( F_52 ( V_442 ,
V_60 + sizeof V_63 + V_448 * V_63 . V_452 ,
V_63 . V_452 ) ) {
V_16 = - V_71 ;
goto V_318;
}
if ( V_442 -> V_438 + V_449 > V_63 . V_454 ) {
V_16 = - V_72 ;
goto V_318;
}
if ( V_450 ) {
struct V_457 * V_458 ;
if ( V_442 -> V_299 != V_459 &&
V_442 -> V_299 != V_460 ) {
V_16 = - V_72 ;
goto V_318;
}
V_451 = sizeof( * V_458 ) ;
V_458 = F_159 ( V_451 , V_442 -> V_438 ) ;
if ( ! V_458 ) {
V_16 = - V_175 ;
goto V_318;
}
V_458 -> V_36 = F_37 ( V_442 -> V_444 . V_458 . V_36 , V_57 -> V_68 ) ;
if ( ! V_458 -> V_36 ) {
F_86 ( V_458 ) ;
V_16 = - V_72 ;
goto V_318;
}
V_458 -> V_461 = V_442 -> V_444 . V_458 . V_461 ;
V_458 -> V_462 = V_442 -> V_444 . V_458 . V_462 ;
V_446 = & V_458 -> V_444 ;
} else if ( V_442 -> V_299 == V_463 ||
V_442 -> V_299 == V_464 ||
V_442 -> V_299 == V_465 ) {
struct V_466 * V_467 ;
V_451 = sizeof( * V_467 ) ;
V_467 = F_159 ( V_451 , V_442 -> V_438 ) ;
if ( ! V_467 ) {
V_16 = - V_175 ;
goto V_318;
}
V_467 -> V_468 = V_442 -> V_444 . V_467 . V_468 ;
V_467 -> V_235 = V_442 -> V_444 . V_467 . V_235 ;
V_446 = & V_467 -> V_444 ;
} else if ( V_442 -> V_299 == V_469 ||
V_442 -> V_299 == V_470 ) {
struct V_471 * V_472 ;
V_451 = sizeof( * V_472 ) ;
V_472 = F_159 ( V_451 , V_442 -> V_438 ) ;
if ( ! V_472 ) {
V_16 = - V_175 ;
goto V_318;
}
V_472 -> V_468 = V_442 -> V_444 . V_472 . V_468 ;
V_472 -> V_473 = V_442 -> V_444 . V_472 . V_473 ;
V_472 -> V_474 = V_442 -> V_444 . V_472 . V_474 ;
V_472 -> V_235 = V_442 -> V_444 . V_472 . V_235 ;
V_446 = & V_472 -> V_444 ;
} else if ( V_442 -> V_299 == V_459 ||
V_442 -> V_299 == V_460 ||
V_442 -> V_299 == V_475 ) {
V_451 = sizeof( * V_446 ) ;
V_446 = F_159 ( V_451 , V_442 -> V_438 ) ;
if ( ! V_446 ) {
V_16 = - V_175 ;
goto V_318;
}
} else {
V_16 = - V_72 ;
goto V_318;
}
if ( V_442 -> V_299 == V_460 ||
V_442 -> V_299 == V_463 ) {
V_446 -> V_302 . V_303 =
( V_476 V_305 ) V_442 -> V_302 . V_303 ;
} else if ( V_442 -> V_299 == V_475 ) {
V_446 -> V_302 . V_477 = V_442 -> V_302 . V_477 ;
}
if ( ! V_445 )
V_444 = V_446 ;
else
V_445 -> V_446 = V_446 ;
V_445 = V_446 ;
V_446 -> V_446 = NULL ;
V_446 -> V_297 = V_442 -> V_297 ;
V_446 -> V_438 = V_442 -> V_438 ;
V_446 -> V_299 = V_442 -> V_299 ;
V_446 -> V_478 = V_442 -> V_478 ;
if ( V_446 -> V_438 ) {
V_446 -> V_479 = ( void * ) V_446 +
F_160 ( V_451 , sizeof( struct V_439 ) ) ;
if ( F_52 ( V_446 -> V_479 ,
V_60 + sizeof V_63 +
V_63 . V_453 * V_63 . V_452 +
V_449 * sizeof ( struct V_439 ) ,
V_446 -> V_438 * sizeof ( struct V_439 ) ) ) {
V_16 = - V_71 ;
goto V_318;
}
V_449 += V_446 -> V_438 ;
} else
V_446 -> V_479 = NULL ;
}
V_65 . V_447 = 0 ;
V_16 = V_48 -> V_76 -> V_480 ( V_48 -> V_374 , V_444 , & V_447 ) ;
if ( V_16 )
for ( V_446 = V_444 ; V_446 ; V_446 = V_446 -> V_446 ) {
++ V_65 . V_447 ;
if ( V_446 == V_447 )
break;
}
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
V_16 = - V_71 ;
V_318:
F_45 ( V_48 ) ;
while ( V_444 ) {
if ( V_450 && F_162 ( V_444 ) -> V_36 )
F_38 ( F_162 ( V_444 ) -> V_36 ) ;
V_446 = V_444 -> V_446 ;
F_86 ( V_444 ) ;
V_444 = V_446 ;
}
V_220:
F_86 ( V_442 ) ;
return V_16 ? V_16 : V_61 ;
}
static struct V_481 * F_163 ( const char T_3 * V_60 ,
int V_61 ,
T_6 V_453 ,
T_6 V_454 ,
T_6 V_452 )
{
struct V_482 * V_442 ;
struct V_481 * V_444 = NULL , * V_445 , * V_446 ;
int V_449 ;
int V_448 ;
int V_16 ;
if ( V_61 < V_452 * V_453 +
V_454 * sizeof ( struct V_455 ) )
return F_118 ( - V_72 ) ;
if ( V_452 < sizeof ( struct V_482 ) )
return F_118 ( - V_72 ) ;
V_442 = F_76 ( V_452 , V_17 ) ;
if ( ! V_442 )
return F_118 ( - V_175 ) ;
V_449 = 0 ;
V_445 = NULL ;
for ( V_448 = 0 ; V_448 < V_453 ; ++ V_448 ) {
if ( F_52 ( V_442 , V_60 + V_448 * V_452 ,
V_452 ) ) {
V_16 = - V_71 ;
goto V_73;
}
if ( V_442 -> V_438 + V_449 > V_454 ) {
V_16 = - V_72 ;
goto V_73;
}
V_446 = F_76 ( F_160 ( sizeof *V_446 , sizeof ( struct V_439 ) ) +
V_442 -> V_438 * sizeof ( struct V_439 ) ,
V_17 ) ;
if ( ! V_446 ) {
V_16 = - V_175 ;
goto V_73;
}
if ( ! V_445 )
V_444 = V_446 ;
else
V_445 -> V_446 = V_446 ;
V_445 = V_446 ;
V_446 -> V_446 = NULL ;
V_446 -> V_297 = V_442 -> V_297 ;
V_446 -> V_438 = V_442 -> V_438 ;
if ( V_446 -> V_438 ) {
V_446 -> V_479 = ( void * ) V_446 +
F_160 ( sizeof *V_446 , sizeof ( struct V_439 ) ) ;
if ( F_52 ( V_446 -> V_479 ,
V_60 + V_453 * V_452 +
V_449 * sizeof ( struct V_439 ) ,
V_446 -> V_438 * sizeof ( struct V_439 ) ) ) {
V_16 = - V_71 ;
goto V_73;
}
V_449 += V_446 -> V_438 ;
} else
V_446 -> V_479 = NULL ;
}
F_86 ( V_442 ) ;
return V_444 ;
V_73:
F_86 ( V_442 ) ;
while ( V_444 ) {
V_446 = V_444 -> V_446 ;
F_86 ( V_444 ) ;
V_444 = V_446 ;
}
return F_118 ( V_16 ) ;
}
T_2 F_164 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_164 V_63 ;
struct V_483 V_65 ;
struct V_481 * V_444 , * V_446 , * V_447 ;
struct V_37 * V_48 ;
T_2 V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_444 = F_163 ( V_60 + sizeof V_63 ,
V_61 - sizeof V_63 , V_63 . V_453 ,
V_63 . V_454 , V_63 . V_452 ) ;
if ( F_55 ( V_444 ) )
return F_56 ( V_444 ) ;
V_48 = F_39 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 )
goto V_220;
V_65 . V_447 = 0 ;
V_16 = V_48 -> V_76 -> V_484 ( V_48 -> V_374 , V_444 , & V_447 ) ;
F_45 ( V_48 ) ;
if ( V_16 )
for ( V_446 = V_444 ; V_446 ; V_446 = V_446 -> V_446 ) {
++ V_65 . V_447 ;
if ( V_446 == V_447 )
break;
}
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
V_16 = - V_71 ;
V_220:
while ( V_444 ) {
V_446 = V_444 -> V_446 ;
F_86 ( V_444 ) ;
V_444 = V_446 ;
}
return V_16 ? V_16 : V_61 ;
}
T_2 F_165 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_165 V_63 ;
struct V_485 V_65 ;
struct V_481 * V_444 , * V_446 , * V_447 ;
struct V_49 * V_52 ;
T_2 V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_444 = F_163 ( V_60 + sizeof V_63 ,
V_61 - sizeof V_63 , V_63 . V_453 ,
V_63 . V_454 , V_63 . V_452 ) ;
if ( F_55 ( V_444 ) )
return F_56 ( V_444 ) ;
V_52 = F_47 ( V_63 . V_50 , V_57 -> V_68 ) ;
if ( ! V_52 )
goto V_220;
V_65 . V_447 = 0 ;
V_16 = V_52 -> V_76 -> V_486 ( V_52 , V_444 , & V_447 ) ;
F_48 ( V_52 ) ;
if ( V_16 )
for ( V_446 = V_444 ; V_446 ; V_446 = V_446 -> V_446 ) {
++ V_65 . V_447 ;
if ( V_446 == V_447 )
break;
}
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
V_16 = - V_71 ;
V_220:
while ( V_444 ) {
V_446 = V_444 -> V_446 ;
F_86 ( V_444 ) ;
V_444 = V_446 ;
}
return V_16 ? V_16 : V_61 ;
}
T_2 F_166 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_166 V_63 ;
struct V_487 V_65 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_33 * V_36 ;
struct V_488 V_111 ;
int V_16 ;
struct V_66 V_67 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof( V_63 ) ,
( unsigned long ) V_63 . V_74 + sizeof( V_65 ) ,
V_61 - sizeof( V_63 ) , V_62 - sizeof( V_65 ) ) ;
V_2 = F_76 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_175 ;
F_1 ( V_2 , V_63 . V_3 , V_57 -> V_68 , & V_489 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_63 . V_25 , V_57 -> V_68 ) ;
if ( ! V_27 ) {
V_16 = - V_72 ;
goto V_73;
}
V_111 . V_414 = V_63 . V_111 . V_414 ;
V_111 . V_311 = V_63 . V_111 . V_311 ;
V_111 . V_415 = V_63 . V_111 . V_415 ;
V_111 . V_416 = V_63 . V_111 . V_416 ;
V_111 . V_418 = V_63 . V_111 . V_417 ? V_419 : 0 ;
V_111 . V_153 = V_63 . V_111 . V_153 ;
V_111 . V_408 . V_410 = V_63 . V_111 . V_408 . V_410 ;
V_111 . V_408 . V_411 = V_63 . V_111 . V_408 . V_411 ;
V_111 . V_408 . V_412 = V_63 . V_111 . V_408 . V_412 ;
V_111 . V_408 . V_413 = V_63 . V_111 . V_408 . V_413 ;
memset ( & V_111 . V_490 , 0 , sizeof( V_111 . V_490 ) ) ;
memcpy ( V_111 . V_408 . V_406 . V_409 , V_63 . V_111 . V_408 . V_406 , 16 ) ;
V_36 = V_27 -> V_76 -> V_491 ( V_27 , & V_111 , & V_67 ) ;
if ( F_55 ( V_36 ) ) {
V_16 = F_56 ( V_36 ) ;
goto V_184;
}
V_36 -> V_76 = V_27 -> V_76 ;
V_36 -> V_27 = V_27 ;
F_99 ( & V_27 -> V_179 ) ;
V_36 -> V_28 = V_2 ;
V_2 -> V_23 = V_36 ;
V_16 = F_14 ( & V_35 , V_2 ) ;
if ( V_16 )
goto V_375;
V_65 . V_34 = V_2 -> V_20 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) ) {
V_16 = - V_71 ;
goto V_181;
}
F_34 ( V_27 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_2 -> V_182 , & V_57 -> V_68 -> V_83 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_61 ;
V_181:
F_20 ( & V_35 , V_2 ) ;
V_375:
F_167 ( V_36 ) ;
V_184:
F_34 ( V_27 ) ;
V_73:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_168 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 , int V_62 )
{
struct F_168 V_63 ;
struct V_33 * V_36 ;
struct V_1 * V_2 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_2 = F_30 ( & V_35 , V_63 . V_34 , V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_36 = V_2 -> V_23 ;
V_16 = F_167 ( V_36 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_35 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_61 ;
}
T_2 F_169 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_169 V_63 ;
struct V_37 * V_48 ;
struct V_325 * V_203 ;
struct V_492 * V_493 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_48 = F_44 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 )
return - V_72 ;
V_203 = F_7 ( V_48 -> V_28 , struct V_325 , V_337 . V_28 ) ;
F_170 (mcast, &obj->mcast_list, list)
if ( V_63 . V_494 == V_493 -> V_163 &&
! memcmp ( V_63 . V_495 , V_493 -> V_495 . V_409 , sizeof V_493 -> V_495 . V_409 ) ) {
V_16 = 0 ;
goto V_318;
}
V_493 = F_76 ( sizeof *V_493 , V_17 ) ;
if ( ! V_493 ) {
V_16 = - V_175 ;
goto V_318;
}
V_493 -> V_163 = V_63 . V_494 ;
memcpy ( V_493 -> V_495 . V_409 , V_63 . V_495 , sizeof V_493 -> V_495 . V_409 ) ;
V_16 = F_171 ( V_48 , & V_493 -> V_495 , V_63 . V_494 ) ;
if ( ! V_16 )
F_78 ( & V_493 -> V_182 , & V_203 -> V_368 ) ;
else
F_86 ( V_493 ) ;
V_318:
F_46 ( V_48 ) ;
return V_16 ? V_16 : V_61 ;
}
T_2 F_172 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_172 V_63 ;
struct V_325 * V_203 ;
struct V_37 * V_48 ;
struct V_492 * V_493 ;
int V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_48 = F_44 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 )
return - V_72 ;
V_16 = F_173 ( V_48 , (union V_496 * ) V_63 . V_495 , V_63 . V_494 ) ;
if ( V_16 )
goto V_318;
V_203 = F_7 ( V_48 -> V_28 , struct V_325 , V_337 . V_28 ) ;
F_170 (mcast, &obj->mcast_list, list)
if ( V_63 . V_494 == V_493 -> V_163 &&
! memcmp ( V_63 . V_495 , V_493 -> V_495 . V_409 , sizeof V_493 -> V_495 . V_409 ) ) {
F_83 ( & V_493 -> V_182 ) ;
F_86 ( V_493 ) ;
break;
}
V_318:
F_46 ( V_48 ) ;
return V_16 ? V_16 : V_61 ;
}
static T_4 F_174 ( struct V_497 * V_498 )
{
return ( V_498 -> V_499 - sizeof( struct V_497 ) ) / 2 ;
}
static T_2 F_175 ( void * V_500 , T_7 V_501 ,
T_7 V_502 )
{
if ( V_501 > V_502 ) {
if ( F_176 ( V_500 +
V_502 , 0 ,
V_501 - V_502 ) )
return - V_72 ;
return V_502 ;
}
return V_501 ;
}
static int F_177 ( struct V_503 * V_504 ,
union V_505 * V_506 )
{
T_2 V_507 ;
T_2 V_508 ;
T_2 V_509 ;
void * V_510 ;
void * V_511 ;
if ( V_504 -> V_288 )
return - V_72 ;
V_506 -> type = V_504 -> type ;
V_508 = F_174 ( & V_504 -> V_512 ) ;
if ( V_508 != F_160 ( V_508 , 4 ) )
return - V_72 ;
V_511 = ( void * ) V_504 +
sizeof( struct V_497 ) ;
V_510 = V_511 + V_508 ;
if ( V_506 -> type == ( V_513 | V_514 ) )
return - V_72 ;
switch ( V_506 -> type & ~ V_513 ) {
case V_515 :
V_509 = F_120 ( struct V_516 , V_517 ) ;
V_507 = F_175 ( V_510 ,
V_508 ,
V_509 ) ;
if ( V_507 <= 0 )
return - V_72 ;
V_506 -> V_499 = sizeof( struct V_518 ) ;
memcpy ( & V_506 -> V_519 . V_520 , V_511 , V_507 ) ;
memcpy ( & V_506 -> V_519 . V_423 , V_510 , V_507 ) ;
break;
case V_521 :
V_509 = F_120 ( struct V_522 , V_517 ) ;
V_507 = F_175 ( V_510 ,
V_508 ,
V_509 ) ;
if ( V_507 <= 0 )
return - V_72 ;
V_506 -> V_499 = sizeof( struct V_523 ) ;
memcpy ( & V_506 -> V_524 . V_520 , V_511 , V_507 ) ;
memcpy ( & V_506 -> V_524 . V_423 , V_510 , V_507 ) ;
break;
case V_525 :
V_509 = F_120 ( struct V_526 , V_517 ) ;
V_507 = F_175 ( V_510 ,
V_508 ,
V_509 ) ;
if ( V_507 <= 0 )
return - V_72 ;
V_506 -> V_499 = sizeof( struct V_527 ) ;
memcpy ( & V_506 -> V_528 . V_520 , V_511 , V_507 ) ;
memcpy ( & V_506 -> V_528 . V_423 , V_510 , V_507 ) ;
if ( ( F_178 ( V_506 -> V_528 . V_423 . V_410 ) ) >= F_179 ( 20 ) ||
( F_178 ( V_506 -> V_528 . V_520 . V_410 ) ) >= F_179 ( 20 ) )
return - V_72 ;
break;
case V_529 :
case V_530 :
V_509 = F_120 ( struct V_531 , V_517 ) ;
V_507 = F_175 ( V_510 ,
V_508 ,
V_509 ) ;
if ( V_507 <= 0 )
return - V_72 ;
V_506 -> V_499 = sizeof( struct V_532 ) ;
memcpy ( & V_506 -> V_533 . V_520 , V_511 , V_507 ) ;
memcpy ( & V_506 -> V_533 . V_423 , V_510 , V_507 ) ;
break;
case V_514 :
V_509 = F_120 ( struct V_534 , V_517 ) ;
V_507 = F_175 ( V_510 ,
V_508 ,
V_509 ) ;
if ( V_507 <= 0 )
return - V_72 ;
V_506 -> V_535 . V_499 = sizeof( struct V_536 ) ;
memcpy ( & V_506 -> V_535 . V_520 , V_511 , V_507 ) ;
memcpy ( & V_506 -> V_535 . V_423 , V_510 , V_507 ) ;
if ( ( F_178 ( V_506 -> V_535 . V_423 . V_537 ) ) >= F_179 ( 24 ) ||
( F_178 ( V_506 -> V_535 . V_520 . V_537 ) ) >= F_179 ( 24 ) )
return - V_72 ;
break;
default:
return - V_72 ;
}
return 0 ;
}
int F_180 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_180 V_63 = {} ;
struct V_538 V_65 = {} ;
struct V_539 * V_203 ;
int V_73 = 0 ;
struct V_29 * V_32 ;
struct V_24 * V_27 ;
struct V_40 * V_43 ;
struct V_540 V_541 = {} ;
T_4 V_542 ;
T_4 V_543 ;
V_542 = F_120 ( F_121 ( V_63 ) , V_122 ) + sizeof( V_63 . V_122 ) ;
V_543 = F_120 ( F_121 ( V_65 ) , V_544 ) + sizeof( V_65 . V_544 ) ;
if ( V_259 -> V_286 < V_542 )
return - V_72 ;
if ( V_259 -> V_289 < V_543 )
return - V_70 ;
if ( V_259 -> V_286 > sizeof( V_63 ) &&
! F_155 ( V_259 , sizeof( V_63 ) ,
V_259 -> V_286 - sizeof( V_63 ) ) )
return - V_343 ;
V_73 = F_128 ( & V_63 , V_259 , F_129 ( sizeof( V_63 ) , V_259 -> V_286 ) ) ;
if ( V_73 )
return V_73 ;
if ( V_63 . V_287 )
return - V_343 ;
V_203 = F_76 ( sizeof( * V_203 ) , V_17 ) ;
if ( ! V_203 )
return - V_175 ;
F_1 ( & V_203 -> V_337 . V_28 , V_63 . V_3 , V_57 -> V_68 ,
& V_545 ) ;
F_31 ( & V_203 -> V_337 . V_28 . V_9 ) ;
V_27 = F_33 ( V_63 . V_25 , V_57 -> V_68 ) ;
if ( ! V_27 ) {
V_73 = - V_72 ;
goto V_546;
}
V_32 = F_35 ( V_63 . V_30 , V_57 -> V_68 , 0 ) ;
if ( ! V_32 ) {
V_73 = - V_72 ;
goto V_547;
}
V_541 . V_32 = V_32 ;
V_541 . V_122 = V_63 . V_122 ;
V_541 . V_548 = V_63 . V_548 ;
V_541 . V_549 = V_57 ;
V_541 . V_550 = V_63 . V_550 ;
V_541 . V_278 = V_551 ;
V_203 -> V_337 . V_366 = 0 ;
F_57 ( & V_203 -> V_337 . V_367 ) ;
V_43 = V_27 -> V_76 -> V_552 ( V_27 , & V_541 , V_260 ) ;
if ( F_55 ( V_43 ) ) {
V_73 = F_56 ( V_43 ) ;
goto V_553;
}
V_43 -> V_28 = & V_203 -> V_337 . V_28 ;
V_203 -> V_337 . V_28 . V_23 = V_43 ;
V_43 -> V_550 = V_541 . V_550 ;
V_43 -> V_32 = V_32 ;
V_43 -> V_27 = V_27 ;
V_43 -> V_76 = V_27 -> V_76 ;
V_43 -> V_549 = V_541 . V_549 ;
F_77 ( & V_43 -> V_179 , 0 ) ;
F_99 ( & V_27 -> V_179 ) ;
F_99 ( & V_32 -> V_179 ) ;
V_43 -> V_28 = & V_203 -> V_337 . V_28 ;
V_203 -> V_337 . V_28 . V_23 = V_43 ;
V_73 = F_14 ( & V_42 , & V_203 -> V_337 . V_28 ) ;
if ( V_73 )
goto V_554;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_41 = V_203 -> V_337 . V_28 . V_20 ;
V_65 . V_122 = V_541 . V_122 ;
V_65 . V_548 = V_541 . V_548 ;
V_65 . V_544 = V_43 -> V_555 ;
V_65 . V_282 = V_543 ;
V_73 = F_125 ( V_259 ,
& V_65 , V_65 . V_282 ) ;
if ( V_73 )
goto V_181;
F_34 ( V_27 ) ;
F_36 ( V_32 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_203 -> V_337 . V_28 . V_182 , & V_57 -> V_68 -> V_84 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_203 -> V_337 . V_28 . V_12 = 1 ;
F_13 ( & V_203 -> V_337 . V_28 . V_9 ) ;
return 0 ;
V_181:
F_20 ( & V_42 , & V_203 -> V_337 . V_28 ) ;
V_554:
F_181 ( V_43 ) ;
V_553:
F_36 ( V_32 ) ;
V_547:
F_34 ( V_27 ) ;
V_546:
F_12 ( & V_203 -> V_337 . V_28 ) ;
return V_73 ;
}
int F_182 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_182 V_63 = {} ;
struct V_556 V_65 = {} ;
struct V_40 * V_43 ;
struct V_1 * V_2 ;
struct V_539 * V_203 ;
T_4 V_542 ;
T_4 V_543 ;
int V_16 ;
V_542 = F_120 ( F_121 ( V_63 ) , V_41 ) + sizeof( V_63 . V_41 ) ;
V_543 = F_120 ( F_121 ( V_65 ) , V_288 ) + sizeof( V_65 . V_288 ) ;
if ( V_259 -> V_286 < V_542 )
return - V_72 ;
if ( V_259 -> V_289 < V_543 )
return - V_70 ;
if ( V_259 -> V_286 > sizeof( V_63 ) &&
! F_155 ( V_259 , sizeof( V_63 ) ,
V_259 -> V_286 - sizeof( V_63 ) ) )
return - V_343 ;
V_16 = F_128 ( & V_63 , V_259 , F_129 ( sizeof( V_63 ) , V_259 -> V_286 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_63 . V_287 )
return - V_343 ;
V_65 . V_282 = V_543 ;
V_2 = F_30 ( & V_42 , V_63 . V_41 ,
V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_43 = V_2 -> V_23 ;
V_203 = F_7 ( V_2 , struct V_539 , V_337 . V_28 ) ;
V_16 = F_181 ( V_43 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_42 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_158 ( V_57 , & V_203 -> V_337 ) ;
V_65 . V_366 = V_203 -> V_337 . V_366 ;
F_8 ( V_2 ) ;
V_16 = F_125 ( V_259 , & V_65 , V_65 . V_282 ) ;
if ( V_16 )
return V_16 ;
return 0 ;
}
int F_183 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_183 V_63 = {} ;
struct V_40 * V_43 ;
struct V_557 V_558 = {} ;
T_4 V_542 ;
int V_16 ;
V_542 = F_120 ( F_121 ( V_63 ) , V_559 ) + sizeof( V_63 . V_559 ) ;
if ( V_259 -> V_286 < V_542 )
return - V_72 ;
if ( V_259 -> V_286 > sizeof( V_63 ) &&
! F_155 ( V_259 , sizeof( V_63 ) ,
V_259 -> V_286 - sizeof( V_63 ) ) )
return - V_343 ;
V_16 = F_128 ( & V_63 , V_259 , F_129 ( sizeof( V_63 ) , V_259 -> V_286 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! V_63 . V_386 )
return - V_72 ;
if ( V_63 . V_386 > ( V_560 | V_561 ) )
return - V_72 ;
V_43 = F_40 ( V_63 . V_41 , V_57 -> V_68 ) ;
if ( ! V_43 )
return - V_72 ;
V_558 . V_559 = V_63 . V_559 ;
V_558 . V_562 = V_63 . V_562 ;
V_16 = V_43 -> V_76 -> V_563 ( V_43 , & V_558 , V_63 . V_386 , V_260 ) ;
F_41 ( V_43 ) ;
return V_16 ;
}
int F_184 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_184 V_63 = {} ;
struct V_564 V_65 = {} ;
struct V_1 * V_2 ;
int V_73 = 0 ;
struct V_565 V_385 = {} ;
struct V_44 * V_341 ;
struct V_40 * * V_566 = NULL ;
T_6 * V_567 = NULL ;
struct V_40 * V_43 = NULL ;
int V_448 , V_568 , V_569 ;
T_6 V_570 ;
T_6 V_571 ;
T_4 V_572 ;
T_4 V_543 ;
V_572 = F_120 ( F_121 ( V_63 ) , V_573 ) + sizeof( V_63 . V_573 ) ;
V_543 = F_120 ( F_121 ( V_65 ) , V_574 ) + sizeof( V_65 . V_574 ) ;
if ( V_259 -> V_286 < V_572 )
return - V_72 ;
if ( V_259 -> V_289 < V_543 )
return - V_70 ;
V_73 = F_128 ( & V_63 , V_259 , V_572 ) ;
if ( V_73 )
return V_73 ;
V_259 -> V_575 += V_572 ;
V_259 -> V_286 -= V_572 ;
if ( V_63 . V_287 )
return - V_343 ;
if ( V_63 . V_573 > V_576 )
return - V_72 ;
V_570 = 1 << V_63 . V_573 ;
V_571 = V_570 * sizeof( V_304 ) ;
if ( V_570 == 1 )
V_571 += sizeof( V_304 ) ;
if ( V_259 -> V_286 < V_571 )
return - V_72 ;
if ( V_259 -> V_286 > V_571 &&
! F_155 ( V_259 , V_571 ,
V_259 -> V_286 - V_571 ) )
return - V_343 ;
V_567 = F_185 ( V_570 , sizeof( * V_567 ) ,
V_17 ) ;
if ( ! V_567 )
return - V_175 ;
V_73 = F_128 ( V_567 , V_259 ,
V_570 * sizeof( V_304 ) ) ;
if ( V_73 )
goto V_104;
V_566 = F_185 ( V_570 , sizeof( * V_566 ) , V_17 ) ;
if ( ! V_566 ) {
V_73 = - V_175 ;
goto V_104;
}
for ( V_569 = 0 ; V_569 < V_570 ;
V_569 ++ ) {
V_43 = F_40 ( V_567 [ V_569 ] , V_57 -> V_68 ) ;
if ( ! V_43 ) {
V_73 = - V_72 ;
goto V_577;
}
V_566 [ V_569 ] = V_43 ;
}
V_2 = F_76 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 ) {
V_73 = - V_175 ;
goto V_577;
}
F_1 ( V_2 , 0 , V_57 -> V_68 , & V_578 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_385 . V_573 = V_63 . V_573 ;
V_385 . V_331 = V_566 ;
V_341 = V_59 -> V_579 ( V_59 , & V_385 , V_260 ) ;
if ( F_55 ( V_341 ) ) {
V_73 = F_56 ( V_341 ) ;
goto V_546;
}
V_341 -> V_331 = V_566 ;
V_341 -> V_573 = V_385 . V_573 ;
V_341 -> V_28 = V_2 ;
V_2 -> V_23 = V_341 ;
V_341 -> V_76 = V_59 ;
F_77 ( & V_341 -> V_179 , 0 ) ;
for ( V_448 = 0 ; V_448 < V_570 ; V_448 ++ )
F_99 ( & V_566 [ V_448 ] -> V_179 ) ;
V_73 = F_14 ( & V_46 , V_2 ) ;
if ( V_73 )
goto V_580;
V_65 . V_581 = V_2 -> V_20 ;
V_65 . V_574 = V_341 -> V_574 ;
V_65 . V_282 = V_543 ;
V_73 = F_125 ( V_259 ,
& V_65 , V_65 . V_282 ) ;
if ( V_73 )
goto V_181;
F_86 ( V_567 ) ;
for ( V_568 = 0 ; V_568 < V_569 ; V_568 ++ )
F_41 ( V_566 [ V_568 ] ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_2 -> V_182 , & V_57 -> V_68 -> V_85 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return 0 ;
V_181:
F_20 ( & V_46 , V_2 ) ;
V_580:
F_186 ( V_341 ) ;
V_546:
F_12 ( V_2 ) ;
V_577:
for ( V_568 = 0 ; V_568 < V_569 ; V_568 ++ )
F_41 ( V_566 [ V_568 ] ) ;
V_104:
F_86 ( V_567 ) ;
F_86 ( V_566 ) ;
return V_73 ;
}
int F_187 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_187 V_63 = {} ;
struct V_44 * V_341 ;
struct V_1 * V_2 ;
int V_16 ;
struct V_40 * * V_331 ;
T_4 V_542 ;
V_542 = F_120 ( F_121 ( V_63 ) , V_581 ) + sizeof( V_63 . V_581 ) ;
if ( V_259 -> V_286 < V_542 )
return - V_72 ;
if ( V_259 -> V_286 > sizeof( V_63 ) &&
! F_155 ( V_259 , sizeof( V_63 ) ,
V_259 -> V_286 - sizeof( V_63 ) ) )
return - V_343 ;
V_16 = F_128 ( & V_63 , V_259 , F_129 ( sizeof( V_63 ) , V_259 -> V_286 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_63 . V_287 )
return - V_343 ;
V_2 = F_30 ( & V_46 , V_63 . V_581 ,
V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_341 = V_2 -> V_23 ;
V_331 = V_341 -> V_331 ;
V_16 = F_186 ( V_341 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_46 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_8 ( V_2 ) ;
F_86 ( V_331 ) ;
return V_16 ;
}
int F_188 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct V_582 V_63 ;
struct V_583 V_65 ;
struct V_1 * V_2 ;
struct V_584 * V_585 ;
struct V_586 * V_587 ;
struct V_588 * V_589 ;
struct V_37 * V_48 ;
int V_73 = 0 ;
void * V_504 ;
void * V_506 ;
int V_448 ;
if ( V_259 -> V_286 < sizeof( V_63 ) )
return - V_72 ;
if ( V_259 -> V_289 < sizeof( V_65 ) )
return - V_70 ;
V_73 = F_128 ( & V_63 , V_259 , sizeof( V_63 ) ) ;
if ( V_73 )
return V_73 ;
V_259 -> V_575 += sizeof( V_63 ) ;
V_259 -> V_286 -= sizeof( V_63 ) ;
if ( V_63 . V_287 )
return - V_72 ;
if ( ! F_138 ( V_335 ) )
return - V_336 ;
if ( V_63 . V_589 . V_239 >= V_590 )
return - V_72 ;
if ( ( V_63 . V_589 . V_239 & V_591 ) &&
( ( V_63 . V_589 . type == V_592 ) ||
( V_63 . V_589 . type == V_593 ) ) )
return - V_72 ;
if ( V_63 . V_589 . V_594 > V_595 )
return - V_72 ;
if ( V_63 . V_589 . V_499 > V_259 -> V_286 ||
V_63 . V_589 . V_499 >
( V_63 . V_589 . V_594 * sizeof( struct V_503 ) ) )
return - V_72 ;
if ( V_63 . V_589 . V_288 [ 0 ] ||
V_63 . V_589 . V_288 [ 1 ] )
return - V_72 ;
if ( V_63 . V_589 . V_594 ) {
V_587 = F_76 ( sizeof( * V_587 ) + V_63 . V_589 . V_499 ,
V_17 ) ;
if ( ! V_587 )
return - V_175 ;
memcpy ( V_587 , & V_63 . V_589 , sizeof( * V_587 ) ) ;
V_73 = F_128 ( V_587 + 1 , V_259 ,
V_63 . V_589 . V_499 ) ;
if ( V_73 )
goto V_596;
} else {
V_587 = & V_63 . V_589 ;
}
V_2 = F_76 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 ) {
V_73 = - V_175 ;
goto V_596;
}
F_1 ( V_2 , 0 , V_57 -> V_68 , & V_597 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_48 = F_39 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 ) {
V_73 = - V_72 ;
goto V_546;
}
V_589 = F_139 ( sizeof( * V_589 ) + V_63 . V_589 . V_594 *
sizeof( union V_505 ) , V_17 ) ;
if ( ! V_589 ) {
V_73 = - V_175 ;
goto V_184;
}
V_589 -> type = V_587 -> type ;
V_589 -> V_598 = V_587 -> V_598 ;
V_589 -> V_594 = V_587 -> V_594 ;
V_589 -> V_599 = V_587 -> V_599 ;
V_589 -> V_239 = V_587 -> V_239 ;
V_589 -> V_499 = sizeof( * V_589 ) ;
V_504 = V_587 + 1 ;
V_506 = V_589 + 1 ;
for ( V_448 = 0 ; V_448 < V_589 -> V_594 &&
V_63 . V_589 . V_499 > F_120 ( struct V_503 , V_288 ) &&
V_63 . V_589 . V_499 >=
( (struct V_503 * ) V_504 ) -> V_499 ; V_448 ++ ) {
V_73 = F_177 ( V_504 , V_506 ) ;
if ( V_73 )
goto V_104;
V_589 -> V_499 +=
( (union V_505 * ) V_506 ) -> V_499 ;
V_63 . V_589 . V_499 -= ( (struct V_503 * ) V_504 ) -> V_499 ;
V_504 += ( (struct V_503 * ) V_504 ) -> V_499 ;
V_506 += ( (union V_505 * ) V_506 ) -> V_499 ;
}
if ( V_63 . V_589 . V_499 || ( V_448 != V_589 -> V_594 ) ) {
F_189 ( L_3 ,
V_448 , V_63 . V_589 . V_499 ) ;
V_73 = - V_72 ;
goto V_104;
}
V_585 = F_190 ( V_48 , V_589 , V_600 ) ;
if ( F_55 ( V_585 ) ) {
V_73 = F_56 ( V_585 ) ;
goto V_104;
}
V_585 -> V_28 = V_2 ;
V_2 -> V_23 = V_585 ;
V_73 = F_14 ( & V_601 , V_2 ) ;
if ( V_73 )
goto V_602;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_603 = V_2 -> V_20 ;
V_73 = F_125 ( V_259 ,
& V_65 , sizeof( V_65 ) ) ;
if ( V_73 )
goto V_181;
F_45 ( V_48 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_2 -> V_182 , & V_57 -> V_68 -> V_87 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_86 ( V_589 ) ;
if ( V_63 . V_589 . V_594 )
F_86 ( V_587 ) ;
return 0 ;
V_181:
F_20 ( & V_601 , V_2 ) ;
V_602:
F_191 ( V_585 ) ;
V_104:
F_86 ( V_589 ) ;
V_184:
F_45 ( V_48 ) ;
V_546:
F_12 ( V_2 ) ;
V_596:
if ( V_63 . V_589 . V_594 )
F_86 ( V_587 ) ;
return V_73 ;
}
int F_192 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct V_604 V_63 ;
struct V_584 * V_585 ;
struct V_1 * V_2 ;
int V_16 ;
if ( V_259 -> V_286 < sizeof( V_63 ) )
return - V_72 ;
V_16 = F_128 ( & V_63 , V_259 , sizeof( V_63 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_63 . V_287 )
return - V_72 ;
V_2 = F_30 ( & V_601 , V_63 . V_603 ,
V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_585 = V_2 -> V_23 ;
V_16 = F_191 ( V_585 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_601 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_16 ;
}
static int F_193 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_605 * V_63 ,
struct V_66 * V_67 )
{
struct V_606 V_65 ;
struct V_607 * V_203 ;
struct V_24 * V_27 ;
struct V_49 * V_52 ;
struct V_1 * V_326 ( V_327 ) ;
struct V_608 V_111 ;
int V_16 ;
V_203 = F_76 ( sizeof *V_203 , V_17 ) ;
if ( ! V_203 )
return - V_175 ;
F_1 ( & V_203 -> V_337 . V_28 , V_63 -> V_3 , V_57 -> V_68 , & V_609 ) ;
F_31 ( & V_203 -> V_337 . V_28 . V_9 ) ;
if ( V_63 -> V_350 == V_610 ) {
V_111 . V_611 . V_612 . V_189 = F_49 ( V_63 -> V_54 , V_57 -> V_68 , & V_327 ) ;
if ( ! V_111 . V_611 . V_612 . V_189 ) {
V_16 = - V_72 ;
goto V_73;
}
V_203 -> V_377 = F_7 ( V_327 , struct V_202 , V_28 ) ;
F_99 ( & V_203 -> V_377 -> V_218 ) ;
V_111 . V_611 . V_612 . V_32 = F_35 ( V_63 -> V_30 , V_57 -> V_68 , 0 ) ;
if ( ! V_111 . V_611 . V_612 . V_32 ) {
V_16 = - V_72 ;
goto V_613;
}
}
V_27 = F_33 ( V_63 -> V_25 , V_57 -> V_68 ) ;
if ( ! V_27 ) {
V_16 = - V_72 ;
goto V_553;
}
V_111 . V_278 = V_614 ;
V_111 . V_615 = V_57 ;
V_111 . V_350 = V_63 -> V_350 ;
V_111 . V_111 . V_548 = V_63 -> V_548 ;
V_111 . V_111 . V_122 = V_63 -> V_122 ;
V_111 . V_111 . V_616 = V_63 -> V_616 ;
V_203 -> V_337 . V_366 = 0 ;
F_57 ( & V_203 -> V_337 . V_367 ) ;
V_52 = V_27 -> V_76 -> V_617 ( V_27 , & V_111 , V_67 ) ;
if ( F_55 ( V_52 ) ) {
V_16 = F_56 ( V_52 ) ;
goto V_184;
}
V_52 -> V_76 = V_27 -> V_76 ;
V_52 -> V_27 = V_27 ;
V_52 -> V_350 = V_63 -> V_350 ;
V_52 -> V_28 = & V_203 -> V_337 . V_28 ;
V_52 -> V_278 = V_111 . V_278 ;
V_52 -> V_615 = V_111 . V_615 ;
if ( V_63 -> V_350 == V_610 ) {
V_52 -> V_611 . V_612 . V_32 = V_111 . V_611 . V_612 . V_32 ;
V_52 -> V_611 . V_612 . V_189 = V_111 . V_611 . V_612 . V_189 ;
F_99 ( & V_111 . V_611 . V_612 . V_32 -> V_179 ) ;
F_99 ( & V_111 . V_611 . V_612 . V_189 -> V_179 ) ;
}
F_99 ( & V_27 -> V_179 ) ;
F_77 ( & V_52 -> V_179 , 0 ) ;
V_203 -> V_337 . V_28 . V_23 = V_52 ;
V_16 = F_14 ( & V_51 , & V_203 -> V_337 . V_28 ) ;
if ( V_16 )
goto V_375;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_50 = V_203 -> V_337 . V_28 . V_20 ;
V_65 . V_548 = V_111 . V_111 . V_548 ;
V_65 . V_122 = V_111 . V_111 . V_122 ;
if ( V_63 -> V_350 == V_610 )
V_65 . V_618 = V_52 -> V_611 . V_612 . V_619 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 -> V_74 ,
& V_65 , sizeof V_65 ) ) {
V_16 = - V_71 ;
goto V_181;
}
if ( V_63 -> V_350 == V_610 ) {
F_10 ( V_327 ) ;
F_36 ( V_111 . V_611 . V_612 . V_32 ) ;
}
F_34 ( V_27 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_203 -> V_337 . V_28 . V_182 , & V_57 -> V_68 -> V_82 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_203 -> V_337 . V_28 . V_12 = 1 ;
F_13 ( & V_203 -> V_337 . V_28 . V_9 ) ;
return 0 ;
V_181:
F_20 ( & V_51 , & V_203 -> V_337 . V_28 ) ;
V_375:
F_194 ( V_52 ) ;
V_184:
F_34 ( V_27 ) ;
V_553:
if ( V_63 -> V_350 == V_610 )
F_36 ( V_111 . V_611 . V_612 . V_32 ) ;
V_613:
if ( V_63 -> V_350 == V_610 ) {
F_101 ( & V_203 -> V_377 -> V_218 ) ;
F_10 ( V_327 ) ;
}
V_73:
F_12 ( & V_203 -> V_337 . V_28 ) ;
return V_16 ;
}
T_2 F_195 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_195 V_63 ;
struct V_605 V_620 ;
struct V_606 V_65 ;
struct V_66 V_67 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_620 . V_74 = V_63 . V_74 ;
V_620 . V_3 = V_63 . V_3 ;
V_620 . V_350 = V_351 ;
V_620 . V_25 = V_63 . V_25 ;
V_620 . V_548 = V_63 . V_548 ;
V_620 . V_122 = V_63 . V_122 ;
V_620 . V_616 = V_63 . V_616 ;
F_54 ( & V_67 , V_60 + sizeof V_63 ,
( unsigned long ) V_63 . V_74 + sizeof V_65 ,
V_61 - sizeof V_63 - sizeof( struct V_251 ) ,
V_62 - sizeof V_65 ) ;
V_16 = F_193 ( V_57 , V_59 , & V_620 , & V_67 ) ;
if ( V_16 )
return V_16 ;
return V_61 ;
}
T_2 V_605 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 , int V_62 )
{
struct V_605 V_63 ;
struct V_606 V_65 ;
struct V_66 V_67 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof V_63 ,
( unsigned long ) V_63 . V_74 + sizeof V_65 ,
V_61 - sizeof V_63 - sizeof( struct V_251 ) ,
V_62 - sizeof V_65 ) ;
V_16 = F_193 ( V_57 , V_59 , & V_63 , & V_67 ) ;
if ( V_16 )
return V_16 ;
return V_61 ;
}
T_2 F_196 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_196 V_63 ;
struct V_66 V_67 ;
struct V_49 * V_52 ;
struct V_621 V_111 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof V_63 , NULL , V_61 - sizeof V_63 ,
V_62 ) ;
V_52 = F_47 ( V_63 . V_50 , V_57 -> V_68 ) ;
if ( ! V_52 )
return - V_72 ;
V_111 . V_548 = V_63 . V_548 ;
V_111 . V_616 = V_63 . V_616 ;
V_16 = V_52 -> V_76 -> V_622 ( V_52 , & V_111 , V_63 . V_386 , & V_67 ) ;
F_48 ( V_52 ) ;
return V_16 ? V_16 : V_61 ;
}
T_2 F_197 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 ,
int V_61 , int V_62 )
{
struct F_197 V_63 ;
struct V_623 V_65 ;
struct V_621 V_111 ;
struct V_49 * V_52 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_52 = F_47 ( V_63 . V_50 , V_57 -> V_68 ) ;
if ( ! V_52 )
return - V_72 ;
V_16 = F_198 ( V_52 , & V_111 ) ;
F_48 ( V_52 ) ;
if ( V_16 )
return V_16 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_548 = V_111 . V_548 ;
V_65 . V_122 = V_111 . V_122 ;
V_65 . V_616 = V_111 . V_616 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
return - V_71 ;
return V_61 ;
}
T_2 F_199 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_199 V_63 ;
struct V_624 V_65 ;
struct V_1 * V_2 ;
struct V_49 * V_52 ;
struct V_625 * V_203 ;
int V_16 = - V_72 ;
struct V_607 * V_626 ;
enum V_627 V_350 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_2 = F_30 ( & V_51 , V_63 . V_50 , V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_52 = V_2 -> V_23 ;
V_203 = F_7 ( V_2 , struct V_625 , V_28 ) ;
V_350 = V_52 -> V_350 ;
V_16 = F_194 ( V_52 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_350 == V_610 ) {
V_626 = F_7 ( V_203 , struct V_607 , V_337 ) ;
F_101 ( & V_626 -> V_377 -> V_218 ) ;
}
F_20 ( & V_51 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_158 ( V_57 , V_203 ) ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_366 = V_203 -> V_366 ;
F_8 ( V_2 ) ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
V_16 = - V_71 ;
return V_16 ? V_16 : V_61 ;
}
int F_200 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct V_628 V_65 = { { 0 } } ;
struct F_200 V_63 ;
struct V_110 V_111 = { 0 } ;
int V_73 ;
if ( V_259 -> V_286 < sizeof( V_63 ) )
return - V_72 ;
V_73 = F_128 ( & V_63 , V_259 , sizeof( V_63 ) ) ;
if ( V_73 )
return V_73 ;
if ( V_63 . V_287 )
return - V_72 ;
if ( V_63 . V_288 )
return - V_72 ;
V_65 . V_282 = F_120 ( F_121 ( V_65 ) , V_629 ) ;
if ( V_259 -> V_289 < V_65 . V_282 )
return - V_70 ;
V_73 = V_59 -> V_630 ( V_59 , & V_111 , V_260 ) ;
if ( V_73 )
return V_73 ;
F_69 ( V_57 , V_59 , & V_65 . V_281 , & V_111 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_629 ) )
goto V_631;
#ifdef F_59
V_65 . V_629 . V_632 = V_111 . V_629 . V_632 ;
V_65 . V_629 . V_633 . V_634 =
V_111 . V_629 . V_633 . V_634 ;
V_65 . V_629 . V_633 . V_635 =
V_111 . V_629 . V_633 . V_635 ;
V_65 . V_629 . V_633 . V_636 =
V_111 . V_629 . V_633 . V_636 ;
#endif
V_65 . V_282 += sizeof( V_65 . V_629 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_637 ) )
goto V_631;
V_65 . V_637 = V_111 . V_637 ;
V_65 . V_282 += sizeof( V_65 . V_637 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_638 ) )
goto V_631;
V_65 . V_638 = V_111 . V_638 ;
V_65 . V_282 += sizeof( V_65 . V_638 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_639 ) )
goto V_631;
V_65 . V_639 = V_111 . V_99 ;
V_65 . V_282 += sizeof( V_65 . V_639 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_640 ) )
goto V_631;
V_65 . V_640 . V_641 = V_111 . V_640 . V_641 ;
V_65 . V_640 . V_642 =
V_111 . V_640 . V_642 ;
V_65 . V_640 . V_643 =
V_111 . V_640 . V_643 ;
V_65 . V_282 += sizeof( V_65 . V_640 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_644 ) )
goto V_631;
V_65 . V_644 = V_111 . V_644 ;
V_65 . V_282 += sizeof( V_65 . V_644 ) ;
V_631:
V_73 = F_125 ( V_259 , & V_65 , V_65 . V_282 ) ;
return V_73 ;
}
