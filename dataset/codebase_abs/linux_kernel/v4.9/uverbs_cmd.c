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
T_2 F_150 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_150 V_63 ;
struct V_66 V_67 ;
struct V_37 * V_48 ;
struct V_384 * V_111 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof V_63 , NULL , V_61 - sizeof V_63 ,
V_62 ) ;
V_111 = F_76 ( sizeof *V_111 , V_17 ) ;
if ( ! V_111 )
return - V_175 ;
V_48 = F_39 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 ) {
V_16 = - V_72 ;
goto V_220;
}
V_111 -> V_387 = V_63 . V_387 ;
V_111 -> V_388 = V_63 . V_388 ;
V_111 -> V_389 = V_63 . V_389 ;
V_111 -> V_390 = V_63 . V_390 ;
V_111 -> V_391 = V_63 . V_391 ;
V_111 -> V_392 = V_63 . V_392 ;
V_111 -> V_393 = V_63 . V_393 ;
V_111 -> V_394 = V_63 . V_394 ;
V_111 -> V_395 = V_63 . V_395 ;
V_111 -> V_309 = V_63 . V_309 ;
V_111 -> V_396 = V_63 . V_396 ;
V_111 -> V_429 = V_63 . V_429 ;
V_111 -> V_398 = V_63 . V_398 ;
V_111 -> V_399 = V_63 . V_399 ;
V_111 -> V_400 = V_63 . V_400 ;
V_111 -> V_153 = V_63 . V_153 ;
V_111 -> V_401 = V_63 . V_401 ;
V_111 -> V_402 = V_63 . V_402 ;
V_111 -> V_403 = V_63 . V_403 ;
V_111 -> V_404 = V_63 . V_404 ;
V_111 -> V_405 = V_63 . V_405 ;
memcpy ( V_111 -> V_407 . V_408 . V_406 . V_409 , V_63 . V_292 . V_406 , 16 ) ;
V_111 -> V_407 . V_408 . V_410 = V_63 . V_292 . V_410 ;
V_111 -> V_407 . V_408 . V_411 = V_63 . V_292 . V_411 ;
V_111 -> V_407 . V_408 . V_412 = V_63 . V_292 . V_412 ;
V_111 -> V_407 . V_408 . V_413 = V_63 . V_292 . V_413 ;
V_111 -> V_407 . V_414 = V_63 . V_292 . V_414 ;
V_111 -> V_407 . V_311 = V_63 . V_292 . V_311 ;
V_111 -> V_407 . V_415 = V_63 . V_292 . V_415 ;
V_111 -> V_407 . V_416 = V_63 . V_292 . V_416 ;
V_111 -> V_407 . V_418 = V_63 . V_292 . V_417 ? V_419 : 0 ;
V_111 -> V_407 . V_153 = V_63 . V_292 . V_153 ;
memcpy ( V_111 -> V_421 . V_408 . V_406 . V_409 , V_63 . V_420 . V_406 , 16 ) ;
V_111 -> V_421 . V_408 . V_410 = V_63 . V_420 . V_410 ;
V_111 -> V_421 . V_408 . V_411 = V_63 . V_420 . V_411 ;
V_111 -> V_421 . V_408 . V_412 = V_63 . V_420 . V_412 ;
V_111 -> V_421 . V_408 . V_413 = V_63 . V_420 . V_413 ;
V_111 -> V_421 . V_414 = V_63 . V_420 . V_414 ;
V_111 -> V_421 . V_311 = V_63 . V_420 . V_311 ;
V_111 -> V_421 . V_415 = V_63 . V_420 . V_415 ;
V_111 -> V_421 . V_416 = V_63 . V_420 . V_416 ;
V_111 -> V_421 . V_418 = V_63 . V_420 . V_417 ? V_419 : 0 ;
V_111 -> V_421 . V_153 = V_63 . V_420 . V_153 ;
if ( V_48 -> V_374 == V_48 ) {
V_16 = F_151 ( V_48 , V_111 , & V_63 . V_386 ) ;
if ( V_16 )
goto V_430;
V_16 = V_48 -> V_76 -> V_431 ( V_48 , V_111 ,
F_149 ( V_48 -> V_333 , V_63 . V_386 ) , & V_67 ) ;
} else {
V_16 = F_152 ( V_48 , V_111 , F_149 ( V_48 -> V_333 , V_63 . V_386 ) ) ;
}
if ( V_16 )
goto V_430;
V_16 = V_61 ;
V_430:
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
struct F_153 V_63 ;
struct V_432 V_65 ;
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
if ( ! F_154 ( & V_203 -> V_368 ) ) {
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
F_155 ( V_57 , & V_203 -> V_337 ) ;
V_65 . V_366 = V_203 -> V_337 . V_366 ;
F_8 ( V_2 ) ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
return - V_71 ;
return V_61 ;
}
static void * F_156 ( T_4 V_433 , V_304 V_434 )
{
return F_76 ( F_157 ( V_433 , sizeof ( struct V_435 ) ) +
V_434 * sizeof ( struct V_435 ) , V_17 ) ;
}
T_2 F_158 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_158 V_63 ;
struct V_436 V_65 ;
struct V_437 * V_438 ;
struct V_439 * V_440 = NULL , * V_441 , * V_442 , * V_443 ;
struct V_37 * V_48 ;
int V_444 , V_445 ;
int V_446 ;
T_2 V_16 = - V_72 ;
T_4 V_447 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
if ( V_61 < sizeof V_63 + V_63 . V_448 * V_63 . V_449 +
V_63 . V_450 * sizeof ( struct V_451 ) )
return - V_72 ;
if ( V_63 . V_448 < sizeof ( struct V_437 ) )
return - V_72 ;
V_438 = F_76 ( V_63 . V_448 , V_17 ) ;
if ( ! V_438 )
return - V_175 ;
V_48 = F_39 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 )
goto V_220;
V_446 = V_48 -> V_333 == V_452 ;
V_445 = 0 ;
V_441 = NULL ;
for ( V_444 = 0 ; V_444 < V_63 . V_449 ; ++ V_444 ) {
if ( F_52 ( V_438 ,
V_60 + sizeof V_63 + V_444 * V_63 . V_448 ,
V_63 . V_448 ) ) {
V_16 = - V_71 ;
goto V_318;
}
if ( V_438 -> V_434 + V_445 > V_63 . V_450 ) {
V_16 = - V_72 ;
goto V_318;
}
if ( V_446 ) {
struct V_453 * V_454 ;
if ( V_438 -> V_299 != V_455 &&
V_438 -> V_299 != V_456 ) {
V_16 = - V_72 ;
goto V_318;
}
V_447 = sizeof( * V_454 ) ;
V_454 = F_156 ( V_447 , V_438 -> V_434 ) ;
if ( ! V_454 ) {
V_16 = - V_175 ;
goto V_318;
}
V_454 -> V_36 = F_37 ( V_438 -> V_440 . V_454 . V_36 , V_57 -> V_68 ) ;
if ( ! V_454 -> V_36 ) {
F_86 ( V_454 ) ;
V_16 = - V_72 ;
goto V_318;
}
V_454 -> V_457 = V_438 -> V_440 . V_454 . V_457 ;
V_454 -> V_458 = V_438 -> V_440 . V_454 . V_458 ;
V_442 = & V_454 -> V_440 ;
} else if ( V_438 -> V_299 == V_459 ||
V_438 -> V_299 == V_460 ||
V_438 -> V_299 == V_461 ) {
struct V_462 * V_463 ;
V_447 = sizeof( * V_463 ) ;
V_463 = F_156 ( V_447 , V_438 -> V_434 ) ;
if ( ! V_463 ) {
V_16 = - V_175 ;
goto V_318;
}
V_463 -> V_464 = V_438 -> V_440 . V_463 . V_464 ;
V_463 -> V_235 = V_438 -> V_440 . V_463 . V_235 ;
V_442 = & V_463 -> V_440 ;
} else if ( V_438 -> V_299 == V_465 ||
V_438 -> V_299 == V_466 ) {
struct V_467 * V_468 ;
V_447 = sizeof( * V_468 ) ;
V_468 = F_156 ( V_447 , V_438 -> V_434 ) ;
if ( ! V_468 ) {
V_16 = - V_175 ;
goto V_318;
}
V_468 -> V_464 = V_438 -> V_440 . V_468 . V_464 ;
V_468 -> V_469 = V_438 -> V_440 . V_468 . V_469 ;
V_468 -> V_470 = V_438 -> V_440 . V_468 . V_470 ;
V_468 -> V_235 = V_438 -> V_440 . V_468 . V_235 ;
V_442 = & V_468 -> V_440 ;
} else if ( V_438 -> V_299 == V_455 ||
V_438 -> V_299 == V_456 ||
V_438 -> V_299 == V_471 ) {
V_447 = sizeof( * V_442 ) ;
V_442 = F_156 ( V_447 , V_438 -> V_434 ) ;
if ( ! V_442 ) {
V_16 = - V_175 ;
goto V_318;
}
} else {
V_16 = - V_72 ;
goto V_318;
}
if ( V_438 -> V_299 == V_456 ||
V_438 -> V_299 == V_459 ) {
V_442 -> V_302 . V_303 =
( V_472 V_305 ) V_438 -> V_302 . V_303 ;
} else if ( V_438 -> V_299 == V_471 ) {
V_442 -> V_302 . V_473 = V_438 -> V_302 . V_473 ;
}
if ( ! V_441 )
V_440 = V_442 ;
else
V_441 -> V_442 = V_442 ;
V_441 = V_442 ;
V_442 -> V_442 = NULL ;
V_442 -> V_297 = V_438 -> V_297 ;
V_442 -> V_434 = V_438 -> V_434 ;
V_442 -> V_299 = V_438 -> V_299 ;
V_442 -> V_474 = V_438 -> V_474 ;
if ( V_442 -> V_434 ) {
V_442 -> V_475 = ( void * ) V_442 +
F_157 ( V_447 , sizeof( struct V_435 ) ) ;
if ( F_52 ( V_442 -> V_475 ,
V_60 + sizeof V_63 +
V_63 . V_449 * V_63 . V_448 +
V_445 * sizeof ( struct V_435 ) ,
V_442 -> V_434 * sizeof ( struct V_435 ) ) ) {
V_16 = - V_71 ;
goto V_318;
}
V_445 += V_442 -> V_434 ;
} else
V_442 -> V_475 = NULL ;
}
V_65 . V_443 = 0 ;
V_16 = V_48 -> V_76 -> V_476 ( V_48 -> V_374 , V_440 , & V_443 ) ;
if ( V_16 )
for ( V_442 = V_440 ; V_442 ; V_442 = V_442 -> V_442 ) {
++ V_65 . V_443 ;
if ( V_442 == V_443 )
break;
}
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
V_16 = - V_71 ;
V_318:
F_45 ( V_48 ) ;
while ( V_440 ) {
if ( V_446 && F_159 ( V_440 ) -> V_36 )
F_38 ( F_159 ( V_440 ) -> V_36 ) ;
V_442 = V_440 -> V_442 ;
F_86 ( V_440 ) ;
V_440 = V_442 ;
}
V_220:
F_86 ( V_438 ) ;
return V_16 ? V_16 : V_61 ;
}
static struct V_477 * F_160 ( const char T_3 * V_60 ,
int V_61 ,
T_6 V_449 ,
T_6 V_450 ,
T_6 V_448 )
{
struct V_478 * V_438 ;
struct V_477 * V_440 = NULL , * V_441 , * V_442 ;
int V_445 ;
int V_444 ;
int V_16 ;
if ( V_61 < V_448 * V_449 +
V_450 * sizeof ( struct V_451 ) )
return F_118 ( - V_72 ) ;
if ( V_448 < sizeof ( struct V_478 ) )
return F_118 ( - V_72 ) ;
V_438 = F_76 ( V_448 , V_17 ) ;
if ( ! V_438 )
return F_118 ( - V_175 ) ;
V_445 = 0 ;
V_441 = NULL ;
for ( V_444 = 0 ; V_444 < V_449 ; ++ V_444 ) {
if ( F_52 ( V_438 , V_60 + V_444 * V_448 ,
V_448 ) ) {
V_16 = - V_71 ;
goto V_73;
}
if ( V_438 -> V_434 + V_445 > V_450 ) {
V_16 = - V_72 ;
goto V_73;
}
V_442 = F_76 ( F_157 ( sizeof *V_442 , sizeof ( struct V_435 ) ) +
V_438 -> V_434 * sizeof ( struct V_435 ) ,
V_17 ) ;
if ( ! V_442 ) {
V_16 = - V_175 ;
goto V_73;
}
if ( ! V_441 )
V_440 = V_442 ;
else
V_441 -> V_442 = V_442 ;
V_441 = V_442 ;
V_442 -> V_442 = NULL ;
V_442 -> V_297 = V_438 -> V_297 ;
V_442 -> V_434 = V_438 -> V_434 ;
if ( V_442 -> V_434 ) {
V_442 -> V_475 = ( void * ) V_442 +
F_157 ( sizeof *V_442 , sizeof ( struct V_435 ) ) ;
if ( F_52 ( V_442 -> V_475 ,
V_60 + V_449 * V_448 +
V_445 * sizeof ( struct V_435 ) ,
V_442 -> V_434 * sizeof ( struct V_435 ) ) ) {
V_16 = - V_71 ;
goto V_73;
}
V_445 += V_442 -> V_434 ;
} else
V_442 -> V_475 = NULL ;
}
F_86 ( V_438 ) ;
return V_440 ;
V_73:
F_86 ( V_438 ) ;
while ( V_440 ) {
V_442 = V_440 -> V_442 ;
F_86 ( V_440 ) ;
V_440 = V_442 ;
}
return F_118 ( V_16 ) ;
}
T_2 F_161 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_161 V_63 ;
struct V_479 V_65 ;
struct V_477 * V_440 , * V_442 , * V_443 ;
struct V_37 * V_48 ;
T_2 V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_440 = F_160 ( V_60 + sizeof V_63 ,
V_61 - sizeof V_63 , V_63 . V_449 ,
V_63 . V_450 , V_63 . V_448 ) ;
if ( F_55 ( V_440 ) )
return F_56 ( V_440 ) ;
V_48 = F_39 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 )
goto V_220;
V_65 . V_443 = 0 ;
V_16 = V_48 -> V_76 -> V_480 ( V_48 -> V_374 , V_440 , & V_443 ) ;
F_45 ( V_48 ) ;
if ( V_16 )
for ( V_442 = V_440 ; V_442 ; V_442 = V_442 -> V_442 ) {
++ V_65 . V_443 ;
if ( V_442 == V_443 )
break;
}
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
V_16 = - V_71 ;
V_220:
while ( V_440 ) {
V_442 = V_440 -> V_442 ;
F_86 ( V_440 ) ;
V_440 = V_442 ;
}
return V_16 ? V_16 : V_61 ;
}
T_2 F_162 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_162 V_63 ;
struct V_481 V_65 ;
struct V_477 * V_440 , * V_442 , * V_443 ;
struct V_49 * V_52 ;
T_2 V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_440 = F_160 ( V_60 + sizeof V_63 ,
V_61 - sizeof V_63 , V_63 . V_449 ,
V_63 . V_450 , V_63 . V_448 ) ;
if ( F_55 ( V_440 ) )
return F_56 ( V_440 ) ;
V_52 = F_47 ( V_63 . V_50 , V_57 -> V_68 ) ;
if ( ! V_52 )
goto V_220;
V_65 . V_443 = 0 ;
V_16 = V_52 -> V_76 -> V_482 ( V_52 , V_440 , & V_443 ) ;
F_48 ( V_52 ) ;
if ( V_16 )
for ( V_442 = V_440 ; V_442 ; V_442 = V_442 -> V_442 ) {
++ V_65 . V_443 ;
if ( V_442 == V_443 )
break;
}
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
V_16 = - V_71 ;
V_220:
while ( V_440 ) {
V_442 = V_440 -> V_442 ;
F_86 ( V_440 ) ;
V_440 = V_442 ;
}
return V_16 ? V_16 : V_61 ;
}
T_2 F_163 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_163 V_63 ;
struct V_483 V_65 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_33 * V_36 ;
struct V_484 V_111 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_2 = F_76 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_175 ;
F_1 ( V_2 , V_63 . V_3 , V_57 -> V_68 , & V_485 ) ;
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
memset ( & V_111 . V_486 , 0 , sizeof( V_111 . V_486 ) ) ;
memcpy ( V_111 . V_408 . V_406 . V_409 , V_63 . V_111 . V_408 . V_406 , 16 ) ;
V_36 = F_164 ( V_27 , & V_111 ) ;
if ( F_55 ( V_36 ) ) {
V_16 = F_56 ( V_36 ) ;
goto V_184;
}
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
F_165 ( V_36 ) ;
V_184:
F_34 ( V_27 ) ;
V_73:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_166 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 , int V_62 )
{
struct F_166 V_63 ;
struct V_33 * V_36 ;
struct V_1 * V_2 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_2 = F_30 ( & V_35 , V_63 . V_34 , V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_36 = V_2 -> V_23 ;
V_16 = F_165 ( V_36 ) ;
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
T_2 F_167 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_167 V_63 ;
struct V_37 * V_48 ;
struct V_325 * V_203 ;
struct V_487 * V_488 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_48 = F_44 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 )
return - V_72 ;
V_203 = F_7 ( V_48 -> V_28 , struct V_325 , V_337 . V_28 ) ;
F_168 (mcast, &obj->mcast_list, list)
if ( V_63 . V_489 == V_488 -> V_163 &&
! memcmp ( V_63 . V_490 , V_488 -> V_490 . V_409 , sizeof V_488 -> V_490 . V_409 ) ) {
V_16 = 0 ;
goto V_318;
}
V_488 = F_76 ( sizeof *V_488 , V_17 ) ;
if ( ! V_488 ) {
V_16 = - V_175 ;
goto V_318;
}
V_488 -> V_163 = V_63 . V_489 ;
memcpy ( V_488 -> V_490 . V_409 , V_63 . V_490 , sizeof V_488 -> V_490 . V_409 ) ;
V_16 = F_169 ( V_48 , & V_488 -> V_490 , V_63 . V_489 ) ;
if ( ! V_16 )
F_78 ( & V_488 -> V_182 , & V_203 -> V_368 ) ;
else
F_86 ( V_488 ) ;
V_318:
F_46 ( V_48 ) ;
return V_16 ? V_16 : V_61 ;
}
T_2 F_170 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_170 V_63 ;
struct V_325 * V_203 ;
struct V_37 * V_48 ;
struct V_487 * V_488 ;
int V_16 = - V_72 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_48 = F_44 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 )
return - V_72 ;
V_16 = F_171 ( V_48 , (union V_491 * ) V_63 . V_490 , V_63 . V_489 ) ;
if ( V_16 )
goto V_318;
V_203 = F_7 ( V_48 -> V_28 , struct V_325 , V_337 . V_28 ) ;
F_168 (mcast, &obj->mcast_list, list)
if ( V_63 . V_489 == V_488 -> V_163 &&
! memcmp ( V_63 . V_490 , V_488 -> V_490 . V_409 , sizeof V_488 -> V_490 . V_409 ) ) {
F_83 ( & V_488 -> V_182 ) ;
F_86 ( V_488 ) ;
break;
}
V_318:
F_46 ( V_48 ) ;
return V_16 ? V_16 : V_61 ;
}
static T_4 F_172 ( struct V_492 * V_493 )
{
return ( V_493 -> V_494 - sizeof( struct V_492 ) ) / 2 ;
}
static T_2 F_173 ( void * V_495 , T_7 V_496 ,
T_7 V_497 )
{
if ( V_496 > V_497 ) {
if ( F_174 ( V_495 +
V_497 , 0 ,
V_496 - V_497 ) )
return - V_72 ;
return V_497 ;
}
return V_496 ;
}
static int F_175 ( struct V_498 * V_499 ,
union V_500 * V_501 )
{
T_2 V_502 ;
T_2 V_503 ;
T_2 V_504 ;
void * V_505 ;
void * V_506 ;
if ( V_499 -> V_288 )
return - V_72 ;
V_501 -> type = V_499 -> type ;
V_503 = F_172 ( & V_499 -> V_507 ) ;
if ( V_503 != F_157 ( V_503 , 4 ) )
return - V_72 ;
V_506 = ( void * ) V_499 +
sizeof( struct V_492 ) ;
V_505 = V_506 + V_503 ;
switch ( V_501 -> type ) {
case V_508 :
V_504 = F_120 ( struct V_509 , V_510 ) ;
V_502 = F_173 ( V_505 ,
V_503 ,
V_504 ) ;
if ( V_502 <= 0 )
return - V_72 ;
V_501 -> V_494 = sizeof( struct V_511 ) ;
memcpy ( & V_501 -> V_512 . V_513 , V_506 , V_502 ) ;
memcpy ( & V_501 -> V_512 . V_423 , V_505 , V_502 ) ;
break;
case V_514 :
V_504 = F_120 ( struct V_515 , V_510 ) ;
V_502 = F_173 ( V_505 ,
V_503 ,
V_504 ) ;
if ( V_502 <= 0 )
return - V_72 ;
V_501 -> V_494 = sizeof( struct V_516 ) ;
memcpy ( & V_501 -> V_517 . V_513 , V_506 , V_502 ) ;
memcpy ( & V_501 -> V_517 . V_423 , V_505 , V_502 ) ;
break;
case V_518 :
V_504 = F_120 ( struct V_519 , V_510 ) ;
V_502 = F_173 ( V_505 ,
V_503 ,
V_504 ) ;
if ( V_502 <= 0 )
return - V_72 ;
V_501 -> V_494 = sizeof( struct V_520 ) ;
memcpy ( & V_501 -> V_521 . V_513 , V_506 , V_502 ) ;
memcpy ( & V_501 -> V_521 . V_423 , V_505 , V_502 ) ;
if ( ( F_176 ( V_501 -> V_521 . V_423 . V_410 ) ) >= F_177 ( 20 ) ||
( F_176 ( V_501 -> V_521 . V_513 . V_410 ) ) >= F_177 ( 20 ) )
return - V_72 ;
break;
case V_522 :
case V_523 :
V_504 = F_120 ( struct V_524 , V_510 ) ;
V_502 = F_173 ( V_505 ,
V_503 ,
V_504 ) ;
if ( V_502 <= 0 )
return - V_72 ;
V_501 -> V_494 = sizeof( struct V_525 ) ;
memcpy ( & V_501 -> V_526 . V_513 , V_506 , V_502 ) ;
memcpy ( & V_501 -> V_526 . V_423 , V_505 , V_502 ) ;
break;
default:
return - V_72 ;
}
return 0 ;
}
int F_178 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_178 V_63 = {} ;
struct V_527 V_65 = {} ;
struct V_528 * V_203 ;
int V_73 = 0 ;
struct V_29 * V_32 ;
struct V_24 * V_27 ;
struct V_40 * V_43 ;
struct V_529 V_530 = {} ;
T_4 V_531 ;
T_4 V_532 ;
V_531 = F_120 ( F_121 ( V_63 ) , V_122 ) + sizeof( V_63 . V_122 ) ;
V_532 = F_120 ( F_121 ( V_65 ) , V_533 ) + sizeof( V_65 . V_533 ) ;
if ( V_259 -> V_286 < V_531 )
return - V_72 ;
if ( V_259 -> V_289 < V_532 )
return - V_70 ;
if ( V_259 -> V_286 > sizeof( V_63 ) &&
! F_179 ( V_259 , sizeof( V_63 ) ,
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
& V_534 ) ;
F_31 ( & V_203 -> V_337 . V_28 . V_9 ) ;
V_27 = F_33 ( V_63 . V_25 , V_57 -> V_68 ) ;
if ( ! V_27 ) {
V_73 = - V_72 ;
goto V_535;
}
V_32 = F_35 ( V_63 . V_30 , V_57 -> V_68 , 0 ) ;
if ( ! V_32 ) {
V_73 = - V_72 ;
goto V_536;
}
V_530 . V_32 = V_32 ;
V_530 . V_122 = V_63 . V_122 ;
V_530 . V_537 = V_63 . V_537 ;
V_530 . V_538 = V_57 ;
V_530 . V_539 = V_63 . V_539 ;
V_530 . V_278 = V_540 ;
V_203 -> V_337 . V_366 = 0 ;
F_57 ( & V_203 -> V_337 . V_367 ) ;
V_43 = V_27 -> V_76 -> V_541 ( V_27 , & V_530 , V_260 ) ;
if ( F_55 ( V_43 ) ) {
V_73 = F_56 ( V_43 ) ;
goto V_542;
}
V_43 -> V_28 = & V_203 -> V_337 . V_28 ;
V_203 -> V_337 . V_28 . V_23 = V_43 ;
V_43 -> V_539 = V_530 . V_539 ;
V_43 -> V_32 = V_32 ;
V_43 -> V_27 = V_27 ;
V_43 -> V_76 = V_27 -> V_76 ;
V_43 -> V_538 = V_530 . V_538 ;
F_77 ( & V_43 -> V_179 , 0 ) ;
F_99 ( & V_27 -> V_179 ) ;
F_99 ( & V_32 -> V_179 ) ;
V_43 -> V_28 = & V_203 -> V_337 . V_28 ;
V_203 -> V_337 . V_28 . V_23 = V_43 ;
V_73 = F_14 ( & V_42 , & V_203 -> V_337 . V_28 ) ;
if ( V_73 )
goto V_543;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_41 = V_203 -> V_337 . V_28 . V_20 ;
V_65 . V_122 = V_530 . V_122 ;
V_65 . V_537 = V_530 . V_537 ;
V_65 . V_533 = V_43 -> V_544 ;
V_65 . V_282 = V_532 ;
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
V_543:
F_180 ( V_43 ) ;
V_542:
F_36 ( V_32 ) ;
V_536:
F_34 ( V_27 ) ;
V_535:
F_12 ( & V_203 -> V_337 . V_28 ) ;
return V_73 ;
}
int F_181 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_181 V_63 = {} ;
struct V_545 V_65 = {} ;
struct V_40 * V_43 ;
struct V_1 * V_2 ;
struct V_528 * V_203 ;
T_4 V_531 ;
T_4 V_532 ;
int V_16 ;
V_531 = F_120 ( F_121 ( V_63 ) , V_41 ) + sizeof( V_63 . V_41 ) ;
V_532 = F_120 ( F_121 ( V_65 ) , V_288 ) + sizeof( V_65 . V_288 ) ;
if ( V_259 -> V_286 < V_531 )
return - V_72 ;
if ( V_259 -> V_289 < V_532 )
return - V_70 ;
if ( V_259 -> V_286 > sizeof( V_63 ) &&
! F_179 ( V_259 , sizeof( V_63 ) ,
V_259 -> V_286 - sizeof( V_63 ) ) )
return - V_343 ;
V_16 = F_128 ( & V_63 , V_259 , F_129 ( sizeof( V_63 ) , V_259 -> V_286 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_63 . V_287 )
return - V_343 ;
V_65 . V_282 = V_532 ;
V_2 = F_30 ( & V_42 , V_63 . V_41 ,
V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_43 = V_2 -> V_23 ;
V_203 = F_7 ( V_2 , struct V_528 , V_337 . V_28 ) ;
V_16 = F_180 ( V_43 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_42 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_155 ( V_57 , & V_203 -> V_337 ) ;
V_65 . V_366 = V_203 -> V_337 . V_366 ;
F_8 ( V_2 ) ;
V_16 = F_125 ( V_259 , & V_65 , V_65 . V_282 ) ;
if ( V_16 )
return V_16 ;
return 0 ;
}
int F_182 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_182 V_63 = {} ;
struct V_40 * V_43 ;
struct V_546 V_547 = {} ;
T_4 V_531 ;
int V_16 ;
V_531 = F_120 ( F_121 ( V_63 ) , V_548 ) + sizeof( V_63 . V_548 ) ;
if ( V_259 -> V_286 < V_531 )
return - V_72 ;
if ( V_259 -> V_286 > sizeof( V_63 ) &&
! F_179 ( V_259 , sizeof( V_63 ) ,
V_259 -> V_286 - sizeof( V_63 ) ) )
return - V_343 ;
V_16 = F_128 ( & V_63 , V_259 , F_129 ( sizeof( V_63 ) , V_259 -> V_286 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! V_63 . V_386 )
return - V_72 ;
if ( V_63 . V_386 > ( V_549 | V_550 ) )
return - V_72 ;
V_43 = F_40 ( V_63 . V_41 , V_57 -> V_68 ) ;
if ( ! V_43 )
return - V_72 ;
V_547 . V_548 = V_63 . V_548 ;
V_547 . V_551 = V_63 . V_551 ;
V_16 = V_43 -> V_76 -> V_552 ( V_43 , & V_547 , V_63 . V_386 , V_260 ) ;
F_41 ( V_43 ) ;
return V_16 ;
}
int F_183 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_183 V_63 = {} ;
struct V_553 V_65 = {} ;
struct V_1 * V_2 ;
int V_73 = 0 ;
struct V_554 V_385 = {} ;
struct V_44 * V_341 ;
struct V_40 * * V_555 = NULL ;
T_6 * V_556 = NULL ;
struct V_40 * V_43 = NULL ;
int V_444 , V_557 , V_558 ;
T_6 V_559 ;
T_6 V_560 ;
T_4 V_561 ;
T_4 V_532 ;
V_561 = F_120 ( F_121 ( V_63 ) , V_562 ) + sizeof( V_63 . V_562 ) ;
V_532 = F_120 ( F_121 ( V_65 ) , V_563 ) + sizeof( V_65 . V_563 ) ;
if ( V_259 -> V_286 < V_561 )
return - V_72 ;
if ( V_259 -> V_289 < V_532 )
return - V_70 ;
V_73 = F_128 ( & V_63 , V_259 , V_561 ) ;
if ( V_73 )
return V_73 ;
V_259 -> V_564 += V_561 ;
V_259 -> V_286 -= V_561 ;
if ( V_63 . V_287 )
return - V_343 ;
if ( V_63 . V_562 > V_565 )
return - V_72 ;
V_559 = 1 << V_63 . V_562 ;
V_560 = V_559 * sizeof( V_304 ) ;
if ( V_559 == 1 )
V_560 += sizeof( V_304 ) ;
if ( V_259 -> V_286 < V_560 )
return - V_72 ;
if ( V_259 -> V_286 > V_560 &&
! F_179 ( V_259 , V_560 ,
V_259 -> V_286 - V_560 ) )
return - V_343 ;
V_556 = F_184 ( V_559 , sizeof( * V_556 ) ,
V_17 ) ;
if ( ! V_556 )
return - V_175 ;
V_73 = F_128 ( V_556 , V_259 ,
V_559 * sizeof( V_304 ) ) ;
if ( V_73 )
goto V_104;
V_555 = F_184 ( V_559 , sizeof( * V_555 ) , V_17 ) ;
if ( ! V_555 ) {
V_73 = - V_175 ;
goto V_104;
}
for ( V_558 = 0 ; V_558 < V_559 ;
V_558 ++ ) {
V_43 = F_40 ( V_556 [ V_558 ] , V_57 -> V_68 ) ;
if ( ! V_43 ) {
V_73 = - V_72 ;
goto V_566;
}
V_555 [ V_558 ] = V_43 ;
}
V_2 = F_76 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 ) {
V_73 = - V_175 ;
goto V_566;
}
F_1 ( V_2 , 0 , V_57 -> V_68 , & V_567 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_385 . V_562 = V_63 . V_562 ;
V_385 . V_331 = V_555 ;
V_341 = V_59 -> V_568 ( V_59 , & V_385 , V_260 ) ;
if ( F_55 ( V_341 ) ) {
V_73 = F_56 ( V_341 ) ;
goto V_535;
}
V_341 -> V_331 = V_555 ;
V_341 -> V_562 = V_385 . V_562 ;
V_341 -> V_28 = V_2 ;
V_2 -> V_23 = V_341 ;
V_341 -> V_76 = V_59 ;
F_77 ( & V_341 -> V_179 , 0 ) ;
for ( V_444 = 0 ; V_444 < V_559 ; V_444 ++ )
F_99 ( & V_555 [ V_444 ] -> V_179 ) ;
V_73 = F_14 ( & V_46 , V_2 ) ;
if ( V_73 )
goto V_569;
V_65 . V_570 = V_2 -> V_20 ;
V_65 . V_563 = V_341 -> V_563 ;
V_65 . V_282 = V_532 ;
V_73 = F_125 ( V_259 ,
& V_65 , V_65 . V_282 ) ;
if ( V_73 )
goto V_181;
F_86 ( V_556 ) ;
for ( V_557 = 0 ; V_557 < V_558 ; V_557 ++ )
F_41 ( V_555 [ V_557 ] ) ;
F_53 ( & V_57 -> V_9 ) ;
F_78 ( & V_2 -> V_182 , & V_57 -> V_68 -> V_85 ) ;
F_64 ( & V_57 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return 0 ;
V_181:
F_20 ( & V_46 , V_2 ) ;
V_569:
F_185 ( V_341 ) ;
V_535:
F_12 ( V_2 ) ;
V_566:
for ( V_557 = 0 ; V_557 < V_558 ; V_557 ++ )
F_41 ( V_555 [ V_557 ] ) ;
V_104:
F_86 ( V_556 ) ;
F_86 ( V_555 ) ;
return V_73 ;
}
int F_186 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct F_186 V_63 = {} ;
struct V_44 * V_341 ;
struct V_1 * V_2 ;
int V_16 ;
struct V_40 * * V_331 ;
T_4 V_531 ;
V_531 = F_120 ( F_121 ( V_63 ) , V_570 ) + sizeof( V_63 . V_570 ) ;
if ( V_259 -> V_286 < V_531 )
return - V_72 ;
if ( V_259 -> V_286 > sizeof( V_63 ) &&
! F_179 ( V_259 , sizeof( V_63 ) ,
V_259 -> V_286 - sizeof( V_63 ) ) )
return - V_343 ;
V_16 = F_128 ( & V_63 , V_259 , F_129 ( sizeof( V_63 ) , V_259 -> V_286 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_63 . V_287 )
return - V_343 ;
V_2 = F_30 ( & V_46 , V_63 . V_570 ,
V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_341 = V_2 -> V_23 ;
V_331 = V_341 -> V_331 ;
V_16 = F_185 ( V_341 ) ;
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
int F_187 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct V_571 V_63 ;
struct V_572 V_65 ;
struct V_1 * V_2 ;
struct V_573 * V_574 ;
struct V_575 * V_576 ;
struct V_577 * V_578 ;
struct V_37 * V_48 ;
int V_73 = 0 ;
void * V_499 ;
void * V_501 ;
int V_444 ;
if ( V_259 -> V_286 < sizeof( V_63 ) )
return - V_72 ;
if ( V_259 -> V_289 < sizeof( V_65 ) )
return - V_70 ;
V_73 = F_128 ( & V_63 , V_259 , sizeof( V_63 ) ) ;
if ( V_73 )
return V_73 ;
V_259 -> V_564 += sizeof( V_63 ) ;
V_259 -> V_286 -= sizeof( V_63 ) ;
if ( V_63 . V_287 )
return - V_72 ;
if ( ! F_138 ( V_335 ) )
return - V_336 ;
if ( V_63 . V_578 . V_239 >= V_579 )
return - V_72 ;
if ( ( V_63 . V_578 . V_239 & V_580 ) &&
( ( V_63 . V_578 . type == V_581 ) ||
( V_63 . V_578 . type == V_582 ) ) )
return - V_72 ;
if ( V_63 . V_578 . V_583 > V_584 )
return - V_72 ;
if ( V_63 . V_578 . V_494 > V_259 -> V_286 ||
V_63 . V_578 . V_494 >
( V_63 . V_578 . V_583 * sizeof( struct V_498 ) ) )
return - V_72 ;
if ( V_63 . V_578 . V_288 [ 0 ] ||
V_63 . V_578 . V_288 [ 1 ] )
return - V_72 ;
if ( V_63 . V_578 . V_583 ) {
V_576 = F_76 ( sizeof( * V_576 ) + V_63 . V_578 . V_494 ,
V_17 ) ;
if ( ! V_576 )
return - V_175 ;
memcpy ( V_576 , & V_63 . V_578 , sizeof( * V_576 ) ) ;
V_73 = F_128 ( V_576 + 1 , V_259 ,
V_63 . V_578 . V_494 ) ;
if ( V_73 )
goto V_585;
} else {
V_576 = & V_63 . V_578 ;
}
V_2 = F_76 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 ) {
V_73 = - V_175 ;
goto V_585;
}
F_1 ( V_2 , 0 , V_57 -> V_68 , & V_586 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_48 = F_39 ( V_63 . V_38 , V_57 -> V_68 ) ;
if ( ! V_48 ) {
V_73 = - V_72 ;
goto V_535;
}
V_578 = F_139 ( sizeof( * V_578 ) + V_63 . V_578 . V_583 *
sizeof( union V_500 ) , V_17 ) ;
if ( ! V_578 ) {
V_73 = - V_175 ;
goto V_184;
}
V_578 -> type = V_576 -> type ;
V_578 -> V_587 = V_576 -> V_587 ;
V_578 -> V_583 = V_576 -> V_583 ;
V_578 -> V_588 = V_576 -> V_588 ;
V_578 -> V_239 = V_576 -> V_239 ;
V_578 -> V_494 = sizeof( * V_578 ) ;
V_499 = V_576 + 1 ;
V_501 = V_578 + 1 ;
for ( V_444 = 0 ; V_444 < V_578 -> V_583 &&
V_63 . V_578 . V_494 > F_120 ( struct V_498 , V_288 ) &&
V_63 . V_578 . V_494 >=
( (struct V_498 * ) V_499 ) -> V_494 ; V_444 ++ ) {
V_73 = F_175 ( V_499 , V_501 ) ;
if ( V_73 )
goto V_104;
V_578 -> V_494 +=
( (union V_500 * ) V_501 ) -> V_494 ;
V_63 . V_578 . V_494 -= ( (struct V_498 * ) V_499 ) -> V_494 ;
V_499 += ( (struct V_498 * ) V_499 ) -> V_494 ;
V_501 += ( (union V_500 * ) V_501 ) -> V_494 ;
}
if ( V_63 . V_578 . V_494 || ( V_444 != V_578 -> V_583 ) ) {
F_188 ( L_3 ,
V_444 , V_63 . V_578 . V_494 ) ;
V_73 = - V_72 ;
goto V_104;
}
V_574 = F_189 ( V_48 , V_578 , V_589 ) ;
if ( F_55 ( V_574 ) ) {
V_73 = F_56 ( V_574 ) ;
goto V_104;
}
V_574 -> V_48 = V_48 ;
V_574 -> V_28 = V_2 ;
V_2 -> V_23 = V_574 ;
V_73 = F_14 ( & V_590 , V_2 ) ;
if ( V_73 )
goto V_591;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_592 = V_2 -> V_20 ;
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
F_86 ( V_578 ) ;
if ( V_63 . V_578 . V_583 )
F_86 ( V_576 ) ;
return 0 ;
V_181:
F_20 ( & V_590 , V_2 ) ;
V_591:
F_190 ( V_574 ) ;
V_104:
F_86 ( V_578 ) ;
V_184:
F_45 ( V_48 ) ;
V_535:
F_12 ( V_2 ) ;
V_585:
if ( V_63 . V_578 . V_583 )
F_86 ( V_576 ) ;
return V_73 ;
}
int F_191 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct V_593 V_63 ;
struct V_573 * V_574 ;
struct V_1 * V_2 ;
int V_16 ;
if ( V_259 -> V_286 < sizeof( V_63 ) )
return - V_72 ;
V_16 = F_128 ( & V_63 , V_259 , sizeof( V_63 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_63 . V_287 )
return - V_72 ;
V_2 = F_30 ( & V_590 , V_63 . V_592 ,
V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_574 = V_2 -> V_23 ;
V_16 = F_190 ( V_574 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_590 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_16 ;
}
static int F_192 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_594 * V_63 ,
struct V_66 * V_67 )
{
struct V_595 V_65 ;
struct V_596 * V_203 ;
struct V_24 * V_27 ;
struct V_49 * V_52 ;
struct V_1 * V_326 ( V_327 ) ;
struct V_597 V_111 ;
int V_16 ;
V_203 = F_76 ( sizeof *V_203 , V_17 ) ;
if ( ! V_203 )
return - V_175 ;
F_1 ( & V_203 -> V_337 . V_28 , V_63 -> V_3 , V_57 -> V_68 , & V_598 ) ;
F_31 ( & V_203 -> V_337 . V_28 . V_9 ) ;
if ( V_63 -> V_350 == V_599 ) {
V_111 . V_600 . V_601 . V_189 = F_49 ( V_63 -> V_54 , V_57 -> V_68 , & V_327 ) ;
if ( ! V_111 . V_600 . V_601 . V_189 ) {
V_16 = - V_72 ;
goto V_73;
}
V_203 -> V_377 = F_7 ( V_327 , struct V_202 , V_28 ) ;
F_99 ( & V_203 -> V_377 -> V_218 ) ;
V_111 . V_600 . V_601 . V_32 = F_35 ( V_63 -> V_30 , V_57 -> V_68 , 0 ) ;
if ( ! V_111 . V_600 . V_601 . V_32 ) {
V_16 = - V_72 ;
goto V_602;
}
}
V_27 = F_33 ( V_63 -> V_25 , V_57 -> V_68 ) ;
if ( ! V_27 ) {
V_16 = - V_72 ;
goto V_542;
}
V_111 . V_278 = V_603 ;
V_111 . V_604 = V_57 ;
V_111 . V_350 = V_63 -> V_350 ;
V_111 . V_111 . V_537 = V_63 -> V_537 ;
V_111 . V_111 . V_122 = V_63 -> V_122 ;
V_111 . V_111 . V_605 = V_63 -> V_605 ;
V_203 -> V_337 . V_366 = 0 ;
F_57 ( & V_203 -> V_337 . V_367 ) ;
V_52 = V_27 -> V_76 -> V_606 ( V_27 , & V_111 , V_67 ) ;
if ( F_55 ( V_52 ) ) {
V_16 = F_56 ( V_52 ) ;
goto V_184;
}
V_52 -> V_76 = V_27 -> V_76 ;
V_52 -> V_27 = V_27 ;
V_52 -> V_350 = V_63 -> V_350 ;
V_52 -> V_28 = & V_203 -> V_337 . V_28 ;
V_52 -> V_278 = V_111 . V_278 ;
V_52 -> V_604 = V_111 . V_604 ;
if ( V_63 -> V_350 == V_599 ) {
V_52 -> V_600 . V_601 . V_32 = V_111 . V_600 . V_601 . V_32 ;
V_52 -> V_600 . V_601 . V_189 = V_111 . V_600 . V_601 . V_189 ;
F_99 ( & V_111 . V_600 . V_601 . V_32 -> V_179 ) ;
F_99 ( & V_111 . V_600 . V_601 . V_189 -> V_179 ) ;
}
F_99 ( & V_27 -> V_179 ) ;
F_77 ( & V_52 -> V_179 , 0 ) ;
V_203 -> V_337 . V_28 . V_23 = V_52 ;
V_16 = F_14 ( & V_51 , & V_203 -> V_337 . V_28 ) ;
if ( V_16 )
goto V_375;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_50 = V_203 -> V_337 . V_28 . V_20 ;
V_65 . V_537 = V_111 . V_111 . V_537 ;
V_65 . V_122 = V_111 . V_111 . V_122 ;
if ( V_63 -> V_350 == V_599 )
V_65 . V_607 = V_52 -> V_600 . V_601 . V_608 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 -> V_74 ,
& V_65 , sizeof V_65 ) ) {
V_16 = - V_71 ;
goto V_181;
}
if ( V_63 -> V_350 == V_599 ) {
F_10 ( V_327 ) ;
F_36 ( V_111 . V_600 . V_601 . V_32 ) ;
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
F_193 ( V_52 ) ;
V_184:
F_34 ( V_27 ) ;
V_542:
if ( V_63 -> V_350 == V_599 )
F_36 ( V_111 . V_600 . V_601 . V_32 ) ;
V_602:
if ( V_63 -> V_350 == V_599 ) {
F_101 ( & V_203 -> V_377 -> V_218 ) ;
F_10 ( V_327 ) ;
}
V_73:
F_12 ( & V_203 -> V_337 . V_28 ) ;
return V_16 ;
}
T_2 F_194 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_194 V_63 ;
struct V_594 V_609 ;
struct V_595 V_65 ;
struct V_66 V_67 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_609 . V_74 = V_63 . V_74 ;
V_609 . V_3 = V_63 . V_3 ;
V_609 . V_350 = V_351 ;
V_609 . V_25 = V_63 . V_25 ;
V_609 . V_537 = V_63 . V_537 ;
V_609 . V_122 = V_63 . V_122 ;
V_609 . V_605 = V_63 . V_605 ;
F_54 ( & V_67 , V_60 + sizeof V_63 ,
( unsigned long ) V_63 . V_74 + sizeof V_65 ,
V_61 - sizeof V_63 - sizeof( struct V_251 ) ,
V_62 - sizeof V_65 ) ;
V_16 = F_192 ( V_57 , V_59 , & V_609 , & V_67 ) ;
if ( V_16 )
return V_16 ;
return V_61 ;
}
T_2 V_594 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 , int V_62 )
{
struct V_594 V_63 ;
struct V_595 V_65 ;
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
V_16 = F_192 ( V_57 , V_59 , & V_63 , & V_67 ) ;
if ( V_16 )
return V_16 ;
return V_61 ;
}
T_2 F_195 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_195 V_63 ;
struct V_66 V_67 ;
struct V_49 * V_52 ;
struct V_610 V_111 ;
int V_16 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
F_54 ( & V_67 , V_60 + sizeof V_63 , NULL , V_61 - sizeof V_63 ,
V_62 ) ;
V_52 = F_47 ( V_63 . V_50 , V_57 -> V_68 ) ;
if ( ! V_52 )
return - V_72 ;
V_111 . V_537 = V_63 . V_537 ;
V_111 . V_605 = V_63 . V_605 ;
V_16 = V_52 -> V_76 -> V_611 ( V_52 , & V_111 , V_63 . V_386 , & V_67 ) ;
F_48 ( V_52 ) ;
return V_16 ? V_16 : V_61 ;
}
T_2 F_196 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 ,
int V_61 , int V_62 )
{
struct F_196 V_63 ;
struct V_612 V_65 ;
struct V_610 V_111 ;
struct V_49 * V_52 ;
int V_16 ;
if ( V_62 < sizeof V_65 )
return - V_70 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_52 = F_47 ( V_63 . V_50 , V_57 -> V_68 ) ;
if ( ! V_52 )
return - V_72 ;
V_16 = F_197 ( V_52 , & V_111 ) ;
F_48 ( V_52 ) ;
if ( V_16 )
return V_16 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_537 = V_111 . V_537 ;
V_65 . V_122 = V_111 . V_122 ;
V_65 . V_605 = V_111 . V_605 ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
return - V_71 ;
return V_61 ;
}
T_2 F_198 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
const char T_3 * V_60 , int V_61 ,
int V_62 )
{
struct F_198 V_63 ;
struct V_613 V_65 ;
struct V_1 * V_2 ;
struct V_49 * V_52 ;
struct V_614 * V_203 ;
int V_16 = - V_72 ;
struct V_596 * V_615 ;
enum V_616 V_350 ;
if ( F_52 ( & V_63 , V_60 , sizeof V_63 ) )
return - V_71 ;
V_2 = F_30 ( & V_51 , V_63 . V_50 , V_57 -> V_68 ) ;
if ( ! V_2 )
return - V_72 ;
V_52 = V_2 -> V_23 ;
V_203 = F_7 ( V_2 , struct V_614 , V_28 ) ;
V_350 = V_52 -> V_350 ;
V_16 = F_193 ( V_52 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_350 == V_599 ) {
V_615 = F_7 ( V_203 , struct V_596 , V_337 ) ;
F_101 ( & V_615 -> V_377 -> V_218 ) ;
}
F_20 ( & V_51 , V_2 ) ;
F_53 ( & V_57 -> V_9 ) ;
F_83 ( & V_2 -> V_182 ) ;
F_64 ( & V_57 -> V_9 ) ;
F_155 ( V_57 , V_203 ) ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_366 = V_203 -> V_366 ;
F_8 ( V_2 ) ;
if ( F_62 ( ( void T_3 * ) ( unsigned long ) V_63 . V_74 ,
& V_65 , sizeof V_65 ) )
V_16 = - V_71 ;
return V_16 ? V_16 : V_61 ;
}
int F_199 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_66 * V_259 ,
struct V_66 * V_260 )
{
struct V_617 V_65 = { { 0 } } ;
struct F_199 V_63 ;
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
V_65 . V_282 = F_120 ( F_121 ( V_65 ) , V_618 ) ;
if ( V_259 -> V_289 < V_65 . V_282 )
return - V_70 ;
V_73 = V_59 -> V_619 ( V_59 , & V_111 , V_260 ) ;
if ( V_73 )
return V_73 ;
F_69 ( V_57 , V_59 , & V_65 . V_281 , & V_111 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_618 ) )
goto V_620;
#ifdef F_59
V_65 . V_618 . V_621 = V_111 . V_618 . V_621 ;
V_65 . V_618 . V_622 . V_623 =
V_111 . V_618 . V_622 . V_623 ;
V_65 . V_618 . V_622 . V_624 =
V_111 . V_618 . V_622 . V_624 ;
V_65 . V_618 . V_622 . V_625 =
V_111 . V_618 . V_622 . V_625 ;
#endif
V_65 . V_282 += sizeof( V_65 . V_618 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_626 ) )
goto V_620;
V_65 . V_626 = V_111 . V_626 ;
V_65 . V_282 += sizeof( V_65 . V_626 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_627 ) )
goto V_620;
V_65 . V_627 = V_111 . V_627 ;
V_65 . V_282 += sizeof( V_65 . V_627 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_628 ) )
goto V_620;
V_65 . V_628 = V_111 . V_99 ;
V_65 . V_282 += sizeof( V_65 . V_628 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_629 ) )
goto V_620;
V_65 . V_629 . V_630 = V_111 . V_629 . V_630 ;
V_65 . V_629 . V_631 =
V_111 . V_629 . V_631 ;
V_65 . V_629 . V_632 =
V_111 . V_629 . V_632 ;
V_65 . V_282 += sizeof( V_65 . V_629 ) ;
if ( V_259 -> V_289 < V_65 . V_282 + sizeof( V_65 . V_633 ) )
goto V_620;
V_65 . V_633 = V_111 . V_633 ;
V_65 . V_282 += sizeof( V_65 . V_633 ) ;
V_620:
V_73 = F_125 ( V_259 , & V_65 , V_65 . V_282 ) ;
return V_73 ;
}
