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
F_6 ( F_7 ( V_13 , struct V_1 , V_8 ) ) ;
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
static int F_14 ( struct V_14 * V_14 , struct V_1 * V_2 )
{
int V_15 ;
F_15 ( V_16 ) ;
F_16 ( & V_17 ) ;
V_15 = F_17 ( V_14 , V_2 , 0 , 0 , V_18 ) ;
if ( V_15 >= 0 )
V_2 -> V_19 = V_15 ;
F_18 ( & V_17 ) ;
F_19 () ;
return V_15 < 0 ? V_15 : 0 ;
}
void F_20 ( struct V_14 * V_14 , struct V_1 * V_2 )
{
F_16 ( & V_17 ) ;
F_21 ( V_14 , V_2 -> V_19 ) ;
F_18 ( & V_17 ) ;
}
static struct V_1 * F_22 ( struct V_14 * V_14 , int V_19 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_16 ( & V_17 ) ;
V_2 = F_23 ( V_14 , V_19 ) ;
if ( V_2 ) {
if ( V_2 -> V_5 == V_5 )
F_24 ( & V_2 -> V_8 ) ;
else
V_2 = NULL ;
}
F_18 ( & V_17 ) ;
return V_2 ;
}
static struct V_1 * F_25 ( struct V_14 * V_14 , int V_19 ,
struct V_4 * V_5 , int V_20 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_14 , V_19 , V_5 ) ;
if ( ! V_2 )
return NULL ;
if ( V_20 )
F_26 ( & V_2 -> V_9 , V_21 ) ;
else
F_27 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_12 ) {
F_10 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_1 * F_28 ( struct V_14 * V_14 , int V_19 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_14 , V_19 , V_5 ) ;
if ( ! V_2 )
return NULL ;
F_29 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_12 ) {
F_12 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static void * F_30 ( struct V_14 * V_14 , int V_19 , struct V_4 * V_5 ,
int V_20 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( V_14 , V_19 , V_5 , V_20 ) ;
return V_2 ? V_2 -> V_22 : NULL ;
}
static struct V_23 * F_31 ( int V_24 , struct V_4 * V_5 )
{
return F_30 ( & V_25 , V_24 , V_5 , 0 ) ;
}
static void F_32 ( struct V_23 * V_26 )
{
F_10 ( V_26 -> V_27 ) ;
}
static struct V_28 * F_33 ( int V_29 , struct V_4 * V_5 , int V_20 )
{
return F_30 ( & V_30 , V_29 , V_5 , V_20 ) ;
}
static void F_34 ( struct V_28 * V_31 )
{
F_10 ( V_31 -> V_27 ) ;
}
static struct V_32 * F_35 ( int V_33 , struct V_4 * V_5 )
{
return F_30 ( & V_34 , V_33 , V_5 , 0 ) ;
}
static void F_36 ( struct V_32 * V_35 )
{
F_10 ( V_35 -> V_27 ) ;
}
static struct V_36 * F_37 ( int V_37 , struct V_4 * V_5 )
{
return F_30 ( & V_38 , V_37 , V_5 , 0 ) ;
}
static struct V_36 * F_38 ( int V_37 , struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_28 ( & V_38 , V_37 , V_5 ) ;
return V_2 ? V_2 -> V_22 : NULL ;
}
static void F_39 ( struct V_36 * V_39 )
{
F_10 ( V_39 -> V_27 ) ;
}
static void F_40 ( struct V_36 * V_39 )
{
F_12 ( V_39 -> V_27 ) ;
}
static struct V_40 * F_41 ( int V_41 , struct V_4 * V_5 )
{
return F_30 ( & V_42 , V_41 , V_5 , 0 ) ;
}
static void F_42 ( struct V_40 * V_43 )
{
F_10 ( V_43 -> V_27 ) ;
}
static struct V_44 * F_43 ( int V_45 , struct V_4 * V_5 ,
struct V_1 * * V_2 )
{
* V_2 = F_25 ( & V_46 , V_45 , V_5 , 0 ) ;
return * V_2 ? ( * V_2 ) -> V_22 : NULL ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
T_2 F_45 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 ,
int V_52 , int V_53 )
{
struct F_45 V_54 ;
struct V_55 V_56 ;
struct V_57 V_58 ;
#ifdef F_46
struct V_59 V_60 ;
#endif
struct V_4 * V_61 ;
struct V_48 * V_62 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_48 ( & V_48 -> V_9 ) ;
if ( V_48 -> V_61 ) {
V_15 = - V_65 ;
goto V_66;
}
F_49 ( & V_58 , V_51 + sizeof V_54 ,
( unsigned long ) V_54 . V_67 + sizeof V_56 ,
V_52 - sizeof V_54 , V_53 - sizeof V_56 ) ;
V_61 = V_50 -> V_68 ( V_50 , & V_58 ) ;
if ( F_50 ( V_61 ) ) {
V_15 = F_51 ( V_61 ) ;
goto V_66;
}
V_61 -> V_69 = V_50 ;
F_52 ( & V_61 -> V_70 ) ;
F_52 ( & V_61 -> V_71 ) ;
F_52 ( & V_61 -> V_72 ) ;
F_52 ( & V_61 -> V_73 ) ;
F_52 ( & V_61 -> V_74 ) ;
F_52 ( & V_61 -> V_75 ) ;
F_52 ( & V_61 -> V_76 ) ;
F_52 ( & V_61 -> V_77 ) ;
F_52 ( & V_61 -> V_78 ) ;
F_53 () ;
V_61 -> V_79 = F_54 ( V_80 -> V_81 , V_82 ) ;
F_55 () ;
V_61 -> V_83 = 0 ;
#ifdef F_46
V_61 -> V_84 = V_85 ;
F_3 ( & V_61 -> V_86 ) ;
V_61 -> V_87 = 0 ;
F_52 ( & V_61 -> V_88 ) ;
V_15 = F_56 ( V_50 , & V_60 ) ;
if ( V_15 )
goto V_89;
if ( ! ( V_60 . V_90 & V_91 ) )
V_61 -> V_92 = NULL ;
#endif
V_56 . V_93 = V_48 -> V_69 -> V_93 ;
V_15 = F_57 ( V_94 ) ;
if ( V_15 < 0 )
goto V_89;
V_56 . V_95 = V_15 ;
V_62 = F_58 ( V_48 , V_50 , 1 ) ;
if ( F_50 ( V_62 ) ) {
V_15 = F_51 ( V_62 ) ;
goto V_96;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) ) {
V_15 = - V_64 ;
goto V_97;
}
V_48 -> V_61 = V_61 ;
F_60 ( V_56 . V_95 , V_62 ) ;
F_61 ( & V_48 -> V_9 ) ;
return V_52 ;
V_97:
F_62 ( V_48 ) ;
F_63 ( V_62 ) ;
V_96:
F_64 ( V_56 . V_95 ) ;
V_89:
F_65 ( V_61 -> V_79 ) ;
V_50 -> V_98 ( V_61 ) ;
V_66:
F_61 ( & V_48 -> V_9 ) ;
return V_15 ;
}
static void F_66 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_99 * V_56 ,
struct V_59 * V_100 )
{
V_56 -> V_101 = V_100 -> V_101 ;
V_56 -> V_102 = V_50 -> V_102 ;
V_56 -> V_103 = V_100 -> V_103 ;
V_56 -> V_104 = V_100 -> V_104 ;
V_56 -> V_105 = V_100 -> V_105 ;
V_56 -> V_106 = V_100 -> V_106 ;
V_56 -> V_107 = V_100 -> V_107 ;
V_56 -> V_108 = V_100 -> V_108 ;
V_56 -> V_109 = V_100 -> V_109 ;
V_56 -> V_110 = V_100 -> V_110 ;
V_56 -> V_90 = V_100 -> V_90 ;
V_56 -> V_111 = V_100 -> V_111 ;
V_56 -> V_112 = V_100 -> V_112 ;
V_56 -> V_113 = V_100 -> V_113 ;
V_56 -> V_114 = V_100 -> V_114 ;
V_56 -> V_115 = V_100 -> V_115 ;
V_56 -> V_116 = V_100 -> V_116 ;
V_56 -> V_117 = V_100 -> V_117 ;
V_56 -> V_118 = V_100 -> V_118 ;
V_56 -> V_119 = V_100 -> V_119 ;
V_56 -> V_120 = V_100 -> V_120 ;
V_56 -> V_121 = V_100 -> V_121 ;
V_56 -> V_122 = V_100 -> V_122 ;
V_56 -> V_123 = V_100 -> V_123 ;
V_56 -> V_124 = V_100 -> V_124 ;
V_56 -> V_125 = V_100 -> V_125 ;
V_56 -> V_126 = V_100 -> V_126 ;
V_56 -> V_127 = V_100 -> V_127 ;
V_56 -> V_128 = V_100 -> V_128 ;
V_56 -> V_129 = V_100 -> V_129 ;
V_56 -> V_130 = V_100 -> V_130 ;
V_56 -> V_131 = V_100 -> V_131 ;
V_56 -> V_132 = V_100 -> V_132 ;
V_56 -> V_133 = V_100 -> V_133 ;
V_56 -> V_134 = V_100 -> V_134 ;
V_56 -> V_135 = V_100 -> V_135 ;
V_56 -> V_136 = V_100 -> V_136 ;
V_56 -> V_137 = V_100 -> V_137 ;
V_56 -> V_138 = V_100 -> V_138 ;
V_56 -> V_139 = V_50 -> V_139 ;
}
T_2 F_67 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 ,
int V_52 , int V_53 )
{
struct F_67 V_54 ;
struct V_99 V_56 ;
struct V_59 V_100 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_15 = F_56 ( V_50 , & V_100 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_56 , 0 , sizeof V_56 ) ;
F_66 ( V_48 , V_50 , & V_56 , & V_100 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
return - V_64 ;
return V_52 ;
}
T_2 F_68 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 ,
int V_52 , int V_53 )
{
struct F_68 V_54 ;
struct V_140 V_56 ;
struct V_141 V_100 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_15 = F_69 ( V_50 , V_54 . V_142 , & V_100 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_143 = V_100 . V_143 ;
V_56 . V_144 = V_100 . V_144 ;
V_56 . V_145 = V_100 . V_145 ;
V_56 . V_146 = V_100 . V_146 ;
V_56 . V_147 = V_100 . V_147 ;
V_56 . V_148 = V_100 . V_148 ;
V_56 . V_149 = V_100 . V_149 ;
V_56 . V_150 = V_100 . V_150 ;
V_56 . V_151 = V_100 . V_151 ;
V_56 . V_152 = V_100 . V_152 ;
V_56 . V_153 = V_100 . V_153 ;
V_56 . V_154 = V_100 . V_154 ;
V_56 . V_155 = V_100 . V_155 ;
V_56 . V_156 = V_100 . V_156 ;
V_56 . V_157 = V_100 . V_157 ;
V_56 . V_158 = V_100 . V_158 ;
V_56 . V_159 = V_100 . V_159 ;
V_56 . V_160 = V_100 . V_160 ;
V_56 . V_161 = V_100 . V_161 ;
V_56 . V_162 = F_70 ( V_50 ,
V_54 . V_142 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
return - V_64 ;
return V_52 ;
}
T_2 F_71 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 ,
int V_52 , int V_53 )
{
struct F_71 V_54 ;
struct V_163 V_56 ;
struct V_57 V_58 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_49 ( & V_58 , V_51 + sizeof V_54 ,
( unsigned long ) V_54 . V_67 + sizeof V_56 ,
V_52 - sizeof V_54 , V_53 - sizeof V_56 ) ;
V_2 = F_72 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_164 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_165 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = V_50 -> V_166 ( V_50 , V_48 -> V_61 , & V_58 ) ;
if ( F_50 ( V_26 ) ) {
V_15 = F_51 ( V_26 ) ;
goto V_66;
}
V_26 -> V_69 = V_50 ;
V_26 -> V_27 = V_2 ;
V_26 -> V_167 = NULL ;
F_73 ( & V_26 -> V_168 , 0 ) ;
V_2 -> V_22 = V_26 ;
V_15 = F_14 ( & V_25 , V_2 ) ;
if ( V_15 )
goto V_169;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_24 = V_2 -> V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) ) {
V_15 = - V_64 ;
goto V_170;
}
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_171 , & V_48 -> V_61 -> V_70 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_52 ;
V_170:
F_20 ( & V_25 , V_2 ) ;
V_169:
F_75 ( V_26 ) ;
V_66:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_76 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 ,
int V_52 , int V_53 )
{
struct F_76 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
int V_15 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_2 = F_28 ( & V_25 , V_54 . V_24 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_26 = V_2 -> V_22 ;
if ( F_77 ( & V_26 -> V_168 ) ) {
V_15 = - V_172 ;
goto V_173;
}
V_15 = V_26 -> V_69 -> V_174 ( V_2 -> V_22 ) ;
F_78 ( V_15 , L_1 ) ;
if ( V_15 )
goto V_173;
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_25 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_79 ( & V_2 -> V_171 ) ;
F_61 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_52 ;
V_173:
F_12 ( V_2 ) ;
return V_15 ;
}
static int F_80 ( struct V_175 * V_176 ,
struct V_177 * V_177 ,
struct V_44 * V_178 )
{
struct V_179 * V_180 , * V_181 ;
struct V_182 * * V_183 = & V_176 -> V_184 . V_182 ;
struct V_182 * V_185 = NULL ;
V_180 = F_72 ( sizeof *V_180 , V_16 ) ;
if ( ! V_180 )
return - V_164 ;
V_180 -> V_178 = V_178 ;
V_180 -> V_177 = V_177 ;
while ( * V_183 ) {
V_185 = * V_183 ;
V_181 = F_81 ( V_185 , struct V_179 , V_186 ) ;
if ( V_177 < V_181 -> V_177 ) {
V_183 = & ( * V_183 ) -> V_187 ;
} else if ( V_177 > V_181 -> V_177 ) {
V_183 = & ( * V_183 ) -> V_188 ;
} else {
F_6 ( V_180 ) ;
return - V_189 ;
}
}
F_82 ( & V_180 -> V_186 , V_185 , V_183 ) ;
F_83 ( & V_180 -> V_186 , & V_176 -> V_184 ) ;
F_84 ( V_177 ) ;
return 0 ;
}
static struct V_179 * F_85 ( struct V_175 * V_176 ,
struct V_177 * V_177 )
{
struct V_179 * V_180 ;
struct V_182 * V_183 = V_176 -> V_184 . V_182 ;
while ( V_183 ) {
V_180 = F_81 ( V_183 , struct V_179 , V_186 ) ;
if ( V_177 < V_180 -> V_177 )
V_183 = V_183 -> V_187 ;
else if ( V_177 > V_180 -> V_177 )
V_183 = V_183 -> V_188 ;
else
return V_180 ;
}
return NULL ;
}
static struct V_44 * F_86 ( struct V_175 * V_176 , struct V_177 * V_177 )
{
struct V_179 * V_180 ;
V_180 = F_85 ( V_176 , V_177 ) ;
if ( ! V_180 )
return NULL ;
return V_180 -> V_178 ;
}
static void F_87 ( struct V_175 * V_176 ,
struct V_177 * V_177 )
{
struct V_179 * V_180 ;
V_180 = F_85 ( V_176 , V_177 ) ;
if ( V_180 ) {
F_88 ( V_177 ) ;
F_89 ( & V_180 -> V_186 , & V_176 -> V_184 ) ;
F_6 ( V_180 ) ;
}
}
T_2 F_90 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_90 V_54 ;
struct V_190 V_56 ;
struct V_57 V_58 ;
struct V_191 * V_192 ;
struct V_44 * V_178 = NULL ;
struct V_193 V_194 = { NULL , 0 } ;
struct V_177 * V_177 = NULL ;
int V_15 = 0 ;
int V_195 = 0 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_49 ( & V_58 , V_51 + sizeof V_54 ,
( unsigned long ) V_54 . V_67 + sizeof V_56 ,
V_52 - sizeof V_54 , V_53 - sizeof V_56 ) ;
F_48 ( & V_48 -> V_69 -> V_196 ) ;
if ( V_54 . V_193 != - 1 ) {
V_194 = F_91 ( V_54 . V_193 ) ;
if ( ! V_194 . V_48 ) {
V_15 = - V_197 ;
goto V_198;
}
V_177 = F_92 ( V_194 . V_48 ) ;
V_178 = F_86 ( V_48 -> V_69 , V_177 ) ;
if ( ! V_178 && ! ( V_54 . V_199 & V_200 ) ) {
V_15 = - V_201 ;
goto V_198;
}
if ( V_178 && V_54 . V_199 & V_202 ) {
V_15 = - V_65 ;
goto V_198;
}
}
V_192 = F_72 ( sizeof *V_192 , V_16 ) ;
if ( ! V_192 ) {
V_15 = - V_164 ;
goto V_198;
}
F_1 ( & V_192 -> V_27 , 0 , V_48 -> V_61 , & V_203 ) ;
F_29 ( & V_192 -> V_27 . V_9 ) ;
if ( ! V_178 ) {
V_178 = V_50 -> V_204 ( V_50 , V_48 -> V_61 , & V_58 ) ;
if ( F_50 ( V_178 ) ) {
V_15 = F_51 ( V_178 ) ;
goto V_66;
}
V_178 -> V_177 = V_177 ;
V_178 -> V_69 = V_50 ;
F_73 ( & V_178 -> V_168 , 0 ) ;
F_93 ( & V_178 -> V_205 ) ;
F_52 ( & V_178 -> V_206 ) ;
V_195 = 1 ;
}
F_73 ( & V_192 -> V_207 , 0 ) ;
V_192 -> V_27 . V_22 = V_178 ;
V_15 = F_14 ( & V_46 , & V_192 -> V_27 ) ;
if ( V_15 )
goto V_169;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_45 = V_192 -> V_27 . V_19 ;
if ( V_177 ) {
if ( V_195 ) {
V_15 = F_80 ( V_48 -> V_69 , V_177 , V_178 ) ;
if ( V_15 )
goto V_208;
}
F_94 ( & V_178 -> V_168 ) ;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) ) {
V_15 = - V_64 ;
goto V_170;
}
if ( V_194 . V_48 )
F_95 ( V_194 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_192 -> V_27 . V_171 , & V_48 -> V_61 -> V_77 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_192 -> V_27 . V_12 = 1 ;
F_13 ( & V_192 -> V_27 . V_9 ) ;
F_61 ( & V_48 -> V_69 -> V_196 ) ;
return V_52 ;
V_170:
if ( V_177 ) {
if ( V_195 )
F_87 ( V_48 -> V_69 , V_177 ) ;
F_96 ( & V_178 -> V_168 ) ;
}
V_208:
F_20 ( & V_46 , & V_192 -> V_27 ) ;
V_169:
F_97 ( V_178 ) ;
V_66:
F_12 ( & V_192 -> V_27 ) ;
V_198:
if ( V_194 . V_48 )
F_95 ( V_194 ) ;
F_61 ( & V_48 -> V_69 -> V_196 ) ;
return V_15 ;
}
T_2 F_98 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_98 V_54 ;
struct V_1 * V_2 ;
struct V_44 * V_178 = NULL ;
struct V_177 * V_177 = NULL ;
struct V_191 * V_192 ;
int V_12 ;
int V_15 = 0 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_48 ( & V_48 -> V_69 -> V_196 ) ;
V_2 = F_28 ( & V_46 , V_54 . V_45 , V_48 -> V_61 ) ;
if ( ! V_2 ) {
V_15 = - V_65 ;
goto V_209;
}
V_178 = V_2 -> V_22 ;
V_177 = V_178 -> V_177 ;
V_192 = F_7 ( V_2 , struct V_191 , V_27 ) ;
if ( F_77 ( & V_192 -> V_207 ) ) {
F_12 ( V_2 ) ;
V_15 = - V_172 ;
goto V_209;
}
if ( ! V_177 || F_99 ( & V_178 -> V_168 ) ) {
V_15 = F_97 ( V_2 -> V_22 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
}
V_12 = V_2 -> V_12 ;
if ( V_177 && V_15 )
F_94 ( & V_178 -> V_168 ) ;
F_12 ( V_2 ) ;
if ( V_15 )
goto V_209;
if ( V_177 && ! V_12 )
F_87 ( V_48 -> V_69 , V_177 ) ;
F_20 ( & V_46 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_79 ( & V_2 -> V_171 ) ;
F_61 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
V_15 = V_52 ;
V_209:
F_61 ( & V_48 -> V_69 -> V_196 ) ;
return V_15 ;
}
void F_100 ( struct V_175 * V_176 ,
struct V_44 * V_178 )
{
struct V_177 * V_177 ;
V_177 = V_178 -> V_177 ;
if ( V_177 && ! F_99 ( & V_178 -> V_168 ) )
return;
F_97 ( V_178 ) ;
if ( V_177 )
F_87 ( V_176 , V_177 ) ;
}
T_2 F_101 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_101 V_54 ;
struct V_210 V_56 ;
struct V_57 V_58 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_211 * V_212 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_49 ( & V_58 , V_51 + sizeof V_54 ,
( unsigned long ) V_54 . V_67 + sizeof V_56 ,
V_52 - sizeof V_54 , V_53 - sizeof V_56 ) ;
if ( ( V_54 . V_213 & ~ V_214 ) != ( V_54 . V_215 & ~ V_214 ) )
return - V_65 ;
V_15 = F_102 ( V_54 . V_216 ) ;
if ( V_15 )
return V_15 ;
V_2 = F_72 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_164 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_217 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_54 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_89;
}
if ( V_54 . V_216 & V_218 ) {
struct V_59 V_100 ;
V_15 = F_56 ( V_26 -> V_69 , & V_100 ) ;
if ( V_15 || ! ( V_100 . V_90 &
V_91 ) ) {
F_103 ( L_2 ) ;
V_15 = - V_65 ;
goto V_173;
}
}
V_212 = V_26 -> V_69 -> V_219 ( V_26 , V_54 . V_213 , V_54 . V_220 , V_54 . V_215 ,
V_54 . V_216 , & V_58 ) ;
if ( F_50 ( V_212 ) ) {
V_15 = F_51 ( V_212 ) ;
goto V_173;
}
V_212 -> V_69 = V_26 -> V_69 ;
V_212 -> V_26 = V_26 ;
V_212 -> V_27 = V_2 ;
F_94 ( & V_26 -> V_168 ) ;
F_73 ( & V_212 -> V_168 , 0 ) ;
V_2 -> V_22 = V_212 ;
V_15 = F_14 ( & V_221 , V_2 ) ;
if ( V_15 )
goto V_222;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_223 = V_212 -> V_223 ;
V_56 . V_224 = V_212 -> V_224 ;
V_56 . V_225 = V_2 -> V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) ) {
V_15 = - V_64 ;
goto V_170;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_171 , & V_48 -> V_61 -> V_71 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_52 ;
V_170:
F_20 ( & V_221 , V_2 ) ;
V_222:
F_104 ( V_212 ) ;
V_173:
F_32 ( V_26 ) ;
V_89:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_105 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_105 V_54 ;
struct V_226 V_56 ;
struct V_57 V_58 ;
struct V_23 * V_26 = NULL ;
struct V_211 * V_212 ;
struct V_23 * V_227 ;
int V_15 ;
struct V_1 * V_2 ;
if ( V_53 < sizeof( V_56 ) )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof( V_54 ) ) )
return - V_64 ;
F_49 ( & V_58 , V_51 + sizeof( V_54 ) ,
( unsigned long ) V_54 . V_67 + sizeof( V_56 ) ,
V_52 - sizeof( V_54 ) , V_53 - sizeof( V_56 ) ) ;
if ( V_54 . V_228 & ~ V_229 || ! V_54 . V_228 )
return - V_65 ;
if ( ( V_54 . V_228 & V_230 ) &&
( ! V_54 . V_213 || ! V_54 . V_215 || 0 >= V_54 . V_220 ||
( V_54 . V_213 & ~ V_214 ) != ( V_54 . V_215 & ~ V_214 ) ) )
return - V_65 ;
V_2 = F_28 ( & V_221 , V_54 . V_225 ,
V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_212 = V_2 -> V_22 ;
if ( V_54 . V_228 & V_231 ) {
V_15 = F_102 ( V_54 . V_216 ) ;
if ( V_15 )
goto V_232;
}
if ( V_54 . V_228 & V_233 ) {
V_26 = F_31 ( V_54 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_232;
}
}
if ( F_77 ( & V_212 -> V_168 ) ) {
V_15 = - V_172 ;
goto V_234;
}
V_227 = V_212 -> V_26 ;
V_15 = V_212 -> V_69 -> V_235 ( V_212 , V_54 . V_228 , V_54 . V_213 ,
V_54 . V_220 , V_54 . V_215 ,
V_54 . V_216 , V_26 , & V_58 ) ;
if ( ! V_15 ) {
if ( V_54 . V_228 & V_233 ) {
F_94 ( & V_26 -> V_168 ) ;
V_212 -> V_26 = V_26 ;
F_96 ( & V_227 -> V_168 ) ;
}
} else {
goto V_234;
}
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_223 = V_212 -> V_223 ;
V_56 . V_224 = V_212 -> V_224 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof( V_56 ) ) )
V_15 = - V_64 ;
else
V_15 = V_52 ;
V_234:
if ( V_54 . V_228 & V_233 )
F_32 ( V_26 ) ;
V_232:
F_12 ( V_212 -> V_27 ) ;
return V_15 ;
}
T_2 F_106 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_106 V_54 ;
struct V_211 * V_212 ;
struct V_1 * V_2 ;
int V_15 = - V_65 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_2 = F_28 ( & V_221 , V_54 . V_225 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_212 = V_2 -> V_22 ;
V_15 = F_104 ( V_212 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_221 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_79 ( & V_2 -> V_171 ) ;
F_61 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_52 ;
}
T_2 F_107 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_107 V_54 ;
struct V_236 V_56 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_237 * V_238 ;
int V_15 ;
if ( V_53 < sizeof( V_56 ) )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof( V_54 ) ) )
return - V_64 ;
V_2 = F_72 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return - V_164 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_239 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_54 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_89;
}
V_238 = V_26 -> V_69 -> V_240 ( V_26 , V_54 . V_241 ) ;
if ( F_50 ( V_238 ) ) {
V_15 = F_51 ( V_238 ) ;
goto V_173;
}
V_238 -> V_69 = V_26 -> V_69 ;
V_238 -> V_26 = V_26 ;
V_238 -> V_27 = V_2 ;
F_94 ( & V_26 -> V_168 ) ;
V_2 -> V_22 = V_238 ;
V_15 = F_14 ( & V_242 , V_2 ) ;
if ( V_15 )
goto V_243;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_224 = V_238 -> V_224 ;
V_56 . V_244 = V_2 -> V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof( V_56 ) ) ) {
V_15 = - V_64 ;
goto V_170;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_171 , & V_48 -> V_61 -> V_72 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_52 ;
V_170:
F_20 ( & V_242 , V_2 ) ;
V_243:
F_108 ( V_238 ) ;
V_173:
F_32 ( V_26 ) ;
V_89:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_109 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_109 V_54 ;
struct V_237 * V_238 ;
struct V_1 * V_2 ;
int V_15 = - V_65 ;
if ( F_47 ( & V_54 , V_51 , sizeof( V_54 ) ) )
return - V_64 ;
V_2 = F_28 ( & V_242 , V_54 . V_244 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_238 = V_2 -> V_22 ;
V_15 = F_108 ( V_238 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_242 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_79 ( & V_2 -> V_171 ) ;
F_61 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_52 ;
}
T_2 F_110 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_110 V_54 ;
struct V_245 V_56 ;
struct V_48 * V_62 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_15 = F_57 ( V_94 ) ;
if ( V_15 < 0 )
return V_15 ;
V_56 . V_193 = V_15 ;
V_62 = F_58 ( V_48 , V_50 , 0 ) ;
if ( F_50 ( V_62 ) ) {
F_64 ( V_56 . V_193 ) ;
return F_51 ( V_62 ) ;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) ) {
F_64 ( V_56 . V_193 ) ;
F_63 ( V_62 ) ;
return - V_64 ;
}
F_60 ( V_56 . V_193 , V_62 ) ;
return V_52 ;
}
static struct V_246 * F_111 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_57 * V_247 ,
struct V_57 * V_248 ,
struct V_249 * V_54 ,
T_4 V_250 ,
int (* F_112)( struct V_47 * V_48 ,
struct V_246 * V_192 ,
struct V_251 * V_56 ,
struct V_57 * V_58 ,
void * V_5 ) ,
void * V_5 )
{
struct V_246 * V_192 ;
struct V_252 * V_253 = NULL ;
struct V_28 * V_31 ;
int V_15 ;
struct V_251 V_56 ;
struct V_254 V_100 = {} ;
if ( V_54 -> V_255 >= V_48 -> V_69 -> V_93 )
return F_113 ( - V_65 ) ;
V_192 = F_72 ( sizeof *V_192 , V_16 ) ;
if ( ! V_192 )
return F_113 ( - V_164 ) ;
F_1 ( & V_192 -> V_27 , V_54 -> V_3 , V_48 -> V_61 , & V_256 ) ;
F_29 ( & V_192 -> V_27 . V_9 ) ;
if ( V_54 -> V_257 >= 0 ) {
V_253 = F_114 ( V_54 -> V_257 ) ;
if ( ! V_253 ) {
V_15 = - V_65 ;
goto V_66;
}
}
V_192 -> V_258 = V_48 ;
V_192 -> V_259 = 0 ;
V_192 -> V_260 = 0 ;
F_52 ( & V_192 -> V_261 ) ;
F_52 ( & V_192 -> V_262 ) ;
V_100 . V_263 = V_54 -> V_263 ;
V_100 . V_255 = V_54 -> V_255 ;
if ( V_250 > F_115 ( F_116 ( * V_54 ) , V_228 ) + sizeof( V_54 -> V_228 ) )
V_100 . V_228 = V_54 -> V_228 ;
V_31 = V_50 -> F_111 ( V_50 , & V_100 ,
V_48 -> V_61 , V_248 ) ;
if ( F_50 ( V_31 ) ) {
V_15 = F_51 ( V_31 ) ;
goto V_97;
}
V_31 -> V_69 = V_50 ;
V_31 -> V_27 = & V_192 -> V_27 ;
V_31 -> V_264 = V_265 ;
V_31 -> V_266 = V_267 ;
V_31 -> V_268 = V_253 ;
F_73 ( & V_31 -> V_168 , 0 ) ;
V_192 -> V_27 . V_22 = V_31 ;
V_15 = F_14 ( & V_30 , & V_192 -> V_27 ) ;
if ( V_15 )
goto V_89;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_269 . V_29 = V_192 -> V_27 . V_19 ;
V_56 . V_269 . V_263 = V_31 -> V_263 ;
V_56 . V_270 = F_115 ( F_116 ( V_56 ) , V_270 ) +
sizeof( V_56 . V_270 ) ;
V_15 = F_112 ( V_48 , V_192 , & V_56 , V_247 , V_5 ) ;
if ( V_15 )
goto V_271;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_192 -> V_27 . V_171 , & V_48 -> V_61 -> V_73 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_192 -> V_27 . V_12 = 1 ;
F_13 ( & V_192 -> V_27 . V_9 ) ;
return V_192 ;
V_271:
F_20 ( & V_30 , & V_192 -> V_27 ) ;
V_89:
F_117 ( V_31 ) ;
V_97:
if ( V_253 )
F_118 ( V_48 , V_253 , V_192 ) ;
V_66:
F_12 ( & V_192 -> V_27 ) ;
return F_113 ( V_15 ) ;
}
static int F_119 ( struct V_47 * V_48 ,
struct V_246 * V_192 ,
struct V_251 * V_56 ,
struct V_57 * V_247 , void * V_5 )
{
if ( F_120 ( V_247 , & V_56 -> V_269 , sizeof( V_56 -> V_269 ) ) )
return - V_64 ;
return 0 ;
}
T_2 F_121 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_121 V_54 ;
struct V_249 V_272 ;
struct V_273 V_56 ;
struct V_57 V_247 ;
struct V_57 V_248 ;
struct V_246 * V_192 ;
if ( V_53 < sizeof( V_56 ) )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof( V_54 ) ) )
return - V_64 ;
F_49 ( & V_247 , V_51 , V_54 . V_67 , sizeof( V_54 ) , sizeof( V_56 ) ) ;
F_49 ( & V_248 , V_51 + sizeof( V_54 ) ,
( unsigned long ) V_54 . V_67 + sizeof( V_56 ) ,
V_52 - sizeof( V_54 ) , V_53 - sizeof( V_56 ) ) ;
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
V_272 . V_3 = V_54 . V_3 ;
V_272 . V_263 = V_54 . V_263 ;
V_272 . V_255 = V_54 . V_255 ;
V_272 . V_257 = V_54 . V_257 ;
V_192 = F_111 ( V_48 , V_50 , & V_247 , & V_248 , & V_272 ,
F_115 ( F_116 ( V_272 ) , V_257 ) +
sizeof( V_54 . V_257 ) , F_119 ,
NULL ) ;
if ( F_50 ( V_192 ) )
return F_51 ( V_192 ) ;
return V_52 ;
}
static int F_122 ( struct V_47 * V_48 ,
struct V_246 * V_192 ,
struct V_251 * V_56 ,
struct V_57 * V_247 , void * V_5 )
{
if ( F_120 ( V_247 , V_56 , V_56 -> V_270 ) )
return - V_64 ;
return 0 ;
}
int V_249 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_57 * V_247 ,
struct V_57 * V_248 )
{
struct V_251 V_56 ;
struct V_249 V_54 ;
struct V_246 * V_192 ;
int V_66 ;
if ( V_247 -> V_274 < sizeof( V_54 ) )
return - V_65 ;
V_66 = F_123 ( & V_54 , V_247 , sizeof( V_54 ) ) ;
if ( V_66 )
return V_66 ;
if ( V_54 . V_275 )
return - V_65 ;
if ( V_54 . V_276 )
return - V_65 ;
if ( V_247 -> V_277 < ( F_115 ( F_116 ( V_56 ) , V_270 ) +
sizeof( V_56 . V_270 ) ) )
return - V_63 ;
V_192 = F_111 ( V_48 , V_50 , V_247 , V_248 , & V_54 ,
F_124 ( V_247 -> V_274 , sizeof( V_54 ) ) ,
F_122 , NULL ) ;
if ( F_50 ( V_192 ) )
return F_51 ( V_192 ) ;
return 0 ;
}
T_2 F_125 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_125 V_54 ;
struct V_278 V_56 ;
struct V_57 V_58 ;
struct V_28 * V_31 ;
int V_15 = - V_65 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_49 ( & V_58 , V_51 + sizeof V_54 ,
( unsigned long ) V_54 . V_67 + sizeof V_56 ,
V_52 - sizeof V_54 , V_53 - sizeof V_56 ) ;
V_31 = F_33 ( V_54 . V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_31 )
return - V_65 ;
V_15 = V_31 -> V_69 -> V_279 ( V_31 , V_54 . V_263 , & V_58 ) ;
if ( V_15 )
goto V_209;
V_56 . V_263 = V_31 -> V_263 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 . V_263 ) )
V_15 = - V_64 ;
V_209:
F_34 ( V_31 ) ;
return V_15 ? V_15 : V_52 ;
}
static int F_126 ( void T_3 * V_280 , struct V_281 * V_282 )
{
struct V_283 V_284 ;
V_284 . V_285 = V_282 -> V_285 ;
V_284 . V_286 = V_282 -> V_286 ;
V_284 . V_287 = V_282 -> V_287 ;
V_284 . V_288 = V_282 -> V_288 ;
V_284 . V_289 = V_282 -> V_289 ;
V_284 . V_290 . V_291 = ( V_292 V_293 ) V_282 -> V_290 . V_291 ;
V_284 . V_294 = V_282 -> V_39 -> V_294 ;
V_284 . V_295 = V_282 -> V_295 ;
V_284 . V_296 = V_282 -> V_296 ;
V_284 . V_297 = V_282 -> V_297 ;
V_284 . V_298 = V_282 -> V_298 ;
V_284 . V_299 = V_282 -> V_299 ;
V_284 . V_300 = V_282 -> V_300 ;
V_284 . V_142 = V_282 -> V_142 ;
V_284 . V_276 = 0 ;
if ( F_59 ( V_280 , & V_284 , sizeof V_284 ) )
return - V_64 ;
return 0 ;
}
T_2 F_127 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_127 V_54 ;
struct V_301 V_56 ;
T_5 T_3 * V_302 ;
T_5 T_3 * V_303 ;
struct V_28 * V_31 ;
struct V_281 V_282 ;
int V_15 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_31 = F_33 ( V_54 . V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_31 )
return - V_65 ;
V_302 = ( void T_3 * ) ( unsigned long ) V_54 . V_67 ;
V_303 = V_302 + sizeof V_56 ;
memset ( & V_56 , 0 , sizeof V_56 ) ;
while ( V_56 . V_304 < V_54 . V_305 ) {
V_15 = F_128 ( V_31 , 1 , & V_282 ) ;
if ( V_15 < 0 )
goto V_306;
if ( ! V_15 )
break;
V_15 = F_126 ( V_303 , & V_282 ) ;
if ( V_15 )
goto V_306;
V_303 += sizeof( struct V_283 ) ;
++ V_56 . V_304 ;
}
if ( F_59 ( V_302 , & V_56 , sizeof V_56 ) ) {
V_15 = - V_64 ;
goto V_306;
}
V_15 = V_52 ;
V_306:
F_34 ( V_31 ) ;
return V_15 ;
}
T_2 F_129 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_129 V_54 ;
struct V_28 * V_31 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_31 = F_33 ( V_54 . V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_31 )
return - V_65 ;
F_130 ( V_31 , V_54 . V_307 ?
V_308 : V_309 ) ;
F_34 ( V_31 ) ;
return V_52 ;
}
T_2 F_131 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_131 V_54 ;
struct V_310 V_56 ;
struct V_1 * V_2 ;
struct V_28 * V_31 ;
struct V_246 * V_192 ;
struct V_252 * V_253 ;
int V_15 = - V_65 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_2 = F_28 ( & V_30 , V_54 . V_29 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_31 = V_2 -> V_22 ;
V_253 = V_31 -> V_268 ;
V_192 = F_7 ( V_31 -> V_27 , struct V_246 , V_27 ) ;
V_15 = F_117 ( V_31 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_30 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_79 ( & V_2 -> V_171 ) ;
F_61 ( & V_48 -> V_9 ) ;
F_118 ( V_48 , V_253 , V_192 ) ;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_259 = V_192 -> V_259 ;
V_56 . V_260 = V_192 -> V_260 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
return - V_64 ;
return V_52 ;
}
T_2 F_132 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_132 V_54 ;
struct V_311 V_56 ;
struct V_57 V_58 ;
struct V_312 * V_192 ;
struct V_49 * V_69 ;
struct V_23 * V_26 = NULL ;
struct V_44 * V_178 = NULL ;
struct V_1 * V_313 ( V_314 ) ;
struct V_28 * V_315 = NULL , * V_316 = NULL ;
struct V_40 * V_43 = NULL ;
struct V_36 * V_39 ;
struct V_317 V_100 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
if ( V_54 . V_318 == V_319 && ! F_133 ( V_320 ) )
return - V_321 ;
F_49 ( & V_58 , V_51 + sizeof V_54 ,
( unsigned long ) V_54 . V_67 + sizeof V_56 ,
V_52 - sizeof V_54 , V_53 - sizeof V_56 ) ;
V_192 = F_134 ( sizeof *V_192 , V_16 ) ;
if ( ! V_192 )
return - V_164 ;
F_1 ( & V_192 -> V_322 . V_27 , V_54 . V_3 , V_48 -> V_61 , & V_323 ) ;
F_29 ( & V_192 -> V_322 . V_27 . V_9 ) ;
if ( V_54 . V_318 == V_324 ) {
V_178 = F_43 ( V_54 . V_24 , V_48 -> V_61 , & V_314 ) ;
if ( ! V_178 ) {
V_15 = - V_65 ;
goto V_173;
}
V_69 = V_178 -> V_69 ;
} else {
if ( V_54 . V_318 == V_325 ) {
V_54 . V_326 = V_54 . V_327 = 0 ;
} else {
if ( V_54 . V_328 ) {
V_43 = F_41 ( V_54 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 || V_43 -> V_329 != V_330 ) {
V_15 = - V_65 ;
goto V_173;
}
}
if ( V_54 . V_331 != V_54 . V_332 ) {
V_316 = F_33 ( V_54 . V_331 , V_48 -> V_61 , 0 ) ;
if ( ! V_316 ) {
V_15 = - V_65 ;
goto V_173;
}
}
}
V_315 = F_33 ( V_54 . V_332 , V_48 -> V_61 , ! ! V_316 ) ;
V_316 = V_316 ? : V_315 ;
V_26 = F_31 ( V_54 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 || ! V_315 ) {
V_15 = - V_65 ;
goto V_173;
}
V_69 = V_26 -> V_69 ;
}
V_100 . V_266 = V_333 ;
V_100 . V_334 = V_48 ;
V_100 . V_335 = V_315 ;
V_100 . V_336 = V_316 ;
V_100 . V_43 = V_43 ;
V_100 . V_178 = V_178 ;
V_100 . V_337 = V_54 . V_338 ? V_339 : V_340 ;
V_100 . V_318 = V_54 . V_318 ;
V_100 . V_341 = 0 ;
V_100 . V_342 . V_343 = V_54 . V_343 ;
V_100 . V_342 . V_326 = V_54 . V_326 ;
V_100 . V_342 . V_344 = V_54 . V_344 ;
V_100 . V_342 . V_327 = V_54 . V_327 ;
V_100 . V_342 . V_345 = V_54 . V_345 ;
V_192 -> V_322 . V_346 = 0 ;
F_52 ( & V_192 -> V_322 . V_347 ) ;
F_52 ( & V_192 -> V_348 ) ;
if ( V_54 . V_318 == V_324 )
V_39 = F_135 ( V_26 , & V_100 ) ;
else
V_39 = V_69 -> V_349 ( V_26 , & V_100 , & V_58 ) ;
if ( F_50 ( V_39 ) ) {
V_15 = F_51 ( V_39 ) ;
goto V_173;
}
if ( V_54 . V_318 != V_324 ) {
V_39 -> V_350 = V_39 ;
V_39 -> V_69 = V_69 ;
V_39 -> V_26 = V_26 ;
V_39 -> V_335 = V_100 . V_335 ;
V_39 -> V_336 = V_100 . V_336 ;
V_39 -> V_43 = V_100 . V_43 ;
V_39 -> V_266 = V_100 . V_266 ;
V_39 -> V_334 = V_100 . V_334 ;
V_39 -> V_318 = V_100 . V_318 ;
F_73 ( & V_39 -> V_168 , 0 ) ;
F_94 ( & V_26 -> V_168 ) ;
F_94 ( & V_100 . V_335 -> V_168 ) ;
if ( V_100 . V_336 )
F_94 ( & V_100 . V_336 -> V_168 ) ;
if ( V_100 . V_43 )
F_94 ( & V_100 . V_43 -> V_168 ) ;
}
V_39 -> V_27 = & V_192 -> V_322 . V_27 ;
V_192 -> V_322 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_192 -> V_322 . V_27 ) ;
if ( V_15 )
goto V_351;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_352 = V_39 -> V_294 ;
V_56 . V_37 = V_192 -> V_322 . V_27 . V_19 ;
V_56 . V_327 = V_100 . V_342 . V_327 ;
V_56 . V_344 = V_100 . V_342 . V_344 ;
V_56 . V_326 = V_100 . V_342 . V_326 ;
V_56 . V_343 = V_100 . V_342 . V_343 ;
V_56 . V_345 = V_100 . V_342 . V_345 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) ) {
V_15 = - V_64 ;
goto V_170;
}
if ( V_178 ) {
V_192 -> V_353 = F_7 ( V_314 , struct V_191 ,
V_27 ) ;
F_94 ( & V_192 -> V_353 -> V_207 ) ;
F_44 ( V_314 ) ;
}
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_315 )
F_34 ( V_315 ) ;
if ( V_316 && V_316 != V_315 )
F_34 ( V_316 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_192 -> V_322 . V_27 . V_171 , & V_48 -> V_61 -> V_74 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_192 -> V_322 . V_27 . V_12 = 1 ;
F_13 ( & V_192 -> V_322 . V_27 . V_9 ) ;
return V_52 ;
V_170:
F_20 ( & V_38 , & V_192 -> V_322 . V_27 ) ;
V_351:
F_136 ( V_39 ) ;
V_173:
if ( V_178 )
F_44 ( V_314 ) ;
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_315 )
F_34 ( V_315 ) ;
if ( V_316 && V_316 != V_315 )
F_34 ( V_316 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_12 ( & V_192 -> V_322 . V_27 ) ;
return V_15 ;
}
T_2 F_137 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 , int V_53 )
{
struct F_137 V_54 ;
struct V_311 V_56 ;
struct V_57 V_58 ;
struct V_312 * V_192 ;
struct V_44 * V_178 ;
struct V_1 * V_313 ( V_314 ) ;
struct V_36 * V_39 ;
struct V_354 V_100 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_49 ( & V_58 , V_51 + sizeof V_54 ,
( unsigned long ) V_54 . V_67 + sizeof V_56 ,
V_52 - sizeof V_54 , V_53 - sizeof V_56 ) ;
V_192 = F_72 ( sizeof *V_192 , V_16 ) ;
if ( ! V_192 )
return - V_164 ;
F_1 ( & V_192 -> V_322 . V_27 , V_54 . V_3 , V_48 -> V_61 , & V_323 ) ;
F_29 ( & V_192 -> V_322 . V_27 . V_9 ) ;
V_178 = F_43 ( V_54 . V_24 , V_48 -> V_61 , & V_314 ) ;
if ( ! V_178 ) {
V_15 = - V_65 ;
goto V_173;
}
V_100 . V_266 = V_333 ;
V_100 . V_334 = V_48 ;
V_100 . V_294 = V_54 . V_352 ;
V_100 . V_318 = V_54 . V_318 ;
V_192 -> V_322 . V_346 = 0 ;
F_52 ( & V_192 -> V_322 . V_347 ) ;
F_52 ( & V_192 -> V_348 ) ;
V_39 = F_138 ( V_178 , & V_100 ) ;
if ( F_50 ( V_39 ) ) {
V_15 = F_51 ( V_39 ) ;
goto V_173;
}
V_39 -> V_27 = & V_192 -> V_322 . V_27 ;
V_192 -> V_322 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_192 -> V_322 . V_27 ) ;
if ( V_15 )
goto V_351;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_352 = V_39 -> V_294 ;
V_56 . V_37 = V_192 -> V_322 . V_27 . V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) ) {
V_15 = - V_64 ;
goto V_355;
}
V_192 -> V_353 = F_7 ( V_314 , struct V_191 , V_27 ) ;
F_94 ( & V_192 -> V_353 -> V_207 ) ;
F_44 ( V_314 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_192 -> V_322 . V_27 . V_171 , & V_48 -> V_61 -> V_74 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_192 -> V_322 . V_27 . V_12 = 1 ;
F_13 ( & V_192 -> V_322 . V_27 . V_9 ) ;
return V_52 ;
V_355:
F_20 ( & V_38 , & V_192 -> V_322 . V_27 ) ;
V_351:
F_136 ( V_39 ) ;
V_173:
F_44 ( V_314 ) ;
F_12 ( & V_192 -> V_322 . V_27 ) ;
return V_15 ;
}
T_2 F_139 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_139 V_54 ;
struct V_356 V_56 ;
struct V_36 * V_39 ;
struct V_357 * V_100 ;
struct V_317 * V_358 ;
int V_15 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_100 = F_72 ( sizeof *V_100 , V_16 ) ;
V_358 = F_72 ( sizeof *V_358 , V_16 ) ;
if ( ! V_100 || ! V_358 ) {
V_15 = - V_164 ;
goto V_209;
}
V_39 = F_37 ( V_54 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_15 = - V_65 ;
goto V_209;
}
V_15 = F_140 ( V_39 , V_100 , V_54 . V_359 , V_358 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
goto V_209;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_360 = V_100 -> V_360 ;
V_56 . V_361 = V_100 -> V_361 ;
V_56 . V_362 = V_100 -> V_362 ;
V_56 . V_363 = V_100 -> V_363 ;
V_56 . V_364 = V_100 -> V_364 ;
V_56 . V_365 = V_100 -> V_365 ;
V_56 . V_366 = V_100 -> V_366 ;
V_56 . V_367 = V_100 -> V_367 ;
V_56 . V_368 = V_100 -> V_368 ;
V_56 . V_297 = V_100 -> V_297 ;
V_56 . V_369 = V_100 -> V_369 ;
V_56 . V_370 = V_100 -> V_370 ;
V_56 . V_371 = V_100 -> V_371 ;
V_56 . V_372 = V_100 -> V_372 ;
V_56 . V_373 = V_100 -> V_373 ;
V_56 . V_142 = V_100 -> V_142 ;
V_56 . V_374 = V_100 -> V_374 ;
V_56 . V_375 = V_100 -> V_375 ;
V_56 . V_376 = V_100 -> V_376 ;
V_56 . V_377 = V_100 -> V_377 ;
V_56 . V_378 = V_100 -> V_378 ;
memcpy ( V_56 . V_280 . V_379 , V_100 -> V_380 . V_381 . V_379 . V_382 , 16 ) ;
V_56 . V_280 . V_383 = V_100 -> V_380 . V_381 . V_383 ;
V_56 . V_280 . V_384 = V_100 -> V_380 . V_381 . V_384 ;
V_56 . V_280 . V_385 = V_100 -> V_380 . V_381 . V_385 ;
V_56 . V_280 . V_386 = V_100 -> V_380 . V_381 . V_386 ;
V_56 . V_280 . V_387 = V_100 -> V_380 . V_387 ;
V_56 . V_280 . V_299 = V_100 -> V_380 . V_299 ;
V_56 . V_280 . V_388 = V_100 -> V_380 . V_388 ;
V_56 . V_280 . V_389 = V_100 -> V_380 . V_389 ;
V_56 . V_280 . V_390 = ! ! ( V_100 -> V_380 . V_391 & V_392 ) ;
V_56 . V_280 . V_142 = V_100 -> V_380 . V_142 ;
memcpy ( V_56 . V_393 . V_379 , V_100 -> V_394 . V_381 . V_379 . V_382 , 16 ) ;
V_56 . V_393 . V_383 = V_100 -> V_394 . V_381 . V_383 ;
V_56 . V_393 . V_384 = V_100 -> V_394 . V_381 . V_384 ;
V_56 . V_393 . V_385 = V_100 -> V_394 . V_381 . V_385 ;
V_56 . V_393 . V_386 = V_100 -> V_394 . V_381 . V_386 ;
V_56 . V_393 . V_387 = V_100 -> V_394 . V_387 ;
V_56 . V_393 . V_299 = V_100 -> V_394 . V_299 ;
V_56 . V_393 . V_388 = V_100 -> V_394 . V_388 ;
V_56 . V_393 . V_389 = V_100 -> V_394 . V_389 ;
V_56 . V_393 . V_390 = ! ! ( V_100 -> V_394 . V_391 & V_392 ) ;
V_56 . V_393 . V_142 = V_100 -> V_394 . V_142 ;
V_56 . V_343 = V_358 -> V_342 . V_343 ;
V_56 . V_326 = V_358 -> V_342 . V_326 ;
V_56 . V_344 = V_358 -> V_342 . V_344 ;
V_56 . V_327 = V_358 -> V_342 . V_327 ;
V_56 . V_345 = V_358 -> V_342 . V_345 ;
V_56 . V_338 = V_358 -> V_337 == V_339 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
V_15 = - V_64 ;
V_209:
F_6 ( V_100 ) ;
F_6 ( V_358 ) ;
return V_15 ? V_15 : V_52 ;
}
static int F_141 ( enum V_395 V_318 , int V_396 )
{
switch ( V_318 ) {
case V_325 :
return V_396 & ~ ( V_397 | V_398 ) ;
case V_324 :
return V_396 & ~ ( V_399 | V_400 |
V_401 ) ;
default:
return V_396 ;
}
}
T_2 F_142 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_142 V_54 ;
struct V_57 V_58 ;
struct V_36 * V_39 ;
struct V_357 * V_100 ;
int V_15 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_49 ( & V_58 , V_51 + sizeof V_54 , NULL , V_52 - sizeof V_54 ,
V_53 ) ;
V_100 = F_72 ( sizeof *V_100 , V_16 ) ;
if ( ! V_100 )
return - V_164 ;
V_39 = F_37 ( V_54 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_15 = - V_65 ;
goto V_209;
}
V_100 -> V_360 = V_54 . V_360 ;
V_100 -> V_361 = V_54 . V_361 ;
V_100 -> V_362 = V_54 . V_362 ;
V_100 -> V_363 = V_54 . V_363 ;
V_100 -> V_364 = V_54 . V_364 ;
V_100 -> V_365 = V_54 . V_365 ;
V_100 -> V_366 = V_54 . V_366 ;
V_100 -> V_367 = V_54 . V_367 ;
V_100 -> V_368 = V_54 . V_368 ;
V_100 -> V_297 = V_54 . V_297 ;
V_100 -> V_369 = V_54 . V_369 ;
V_100 -> V_402 = V_54 . V_402 ;
V_100 -> V_371 = V_54 . V_371 ;
V_100 -> V_372 = V_54 . V_372 ;
V_100 -> V_373 = V_54 . V_373 ;
V_100 -> V_142 = V_54 . V_142 ;
V_100 -> V_374 = V_54 . V_374 ;
V_100 -> V_375 = V_54 . V_375 ;
V_100 -> V_376 = V_54 . V_376 ;
V_100 -> V_377 = V_54 . V_377 ;
V_100 -> V_378 = V_54 . V_378 ;
memcpy ( V_100 -> V_380 . V_381 . V_379 . V_382 , V_54 . V_280 . V_379 , 16 ) ;
V_100 -> V_380 . V_381 . V_383 = V_54 . V_280 . V_383 ;
V_100 -> V_380 . V_381 . V_384 = V_54 . V_280 . V_384 ;
V_100 -> V_380 . V_381 . V_385 = V_54 . V_280 . V_385 ;
V_100 -> V_380 . V_381 . V_386 = V_54 . V_280 . V_386 ;
V_100 -> V_380 . V_387 = V_54 . V_280 . V_387 ;
V_100 -> V_380 . V_299 = V_54 . V_280 . V_299 ;
V_100 -> V_380 . V_388 = V_54 . V_280 . V_388 ;
V_100 -> V_380 . V_389 = V_54 . V_280 . V_389 ;
V_100 -> V_380 . V_391 = V_54 . V_280 . V_390 ? V_392 : 0 ;
V_100 -> V_380 . V_142 = V_54 . V_280 . V_142 ;
memcpy ( V_100 -> V_394 . V_381 . V_379 . V_382 , V_54 . V_393 . V_379 , 16 ) ;
V_100 -> V_394 . V_381 . V_383 = V_54 . V_393 . V_383 ;
V_100 -> V_394 . V_381 . V_384 = V_54 . V_393 . V_384 ;
V_100 -> V_394 . V_381 . V_385 = V_54 . V_393 . V_385 ;
V_100 -> V_394 . V_381 . V_386 = V_54 . V_393 . V_386 ;
V_100 -> V_394 . V_387 = V_54 . V_393 . V_387 ;
V_100 -> V_394 . V_299 = V_54 . V_393 . V_299 ;
V_100 -> V_394 . V_388 = V_54 . V_393 . V_388 ;
V_100 -> V_394 . V_389 = V_54 . V_393 . V_389 ;
V_100 -> V_394 . V_391 = V_54 . V_393 . V_390 ? V_392 : 0 ;
V_100 -> V_394 . V_142 = V_54 . V_393 . V_142 ;
if ( V_39 -> V_350 == V_39 ) {
V_15 = F_143 ( V_39 , V_100 , & V_54 . V_359 ) ;
if ( V_15 )
goto V_403;
V_15 = V_39 -> V_69 -> V_404 ( V_39 , V_100 ,
F_141 ( V_39 -> V_318 , V_54 . V_359 ) , & V_58 ) ;
} else {
V_15 = F_144 ( V_39 , V_100 , F_141 ( V_39 -> V_318 , V_54 . V_359 ) ) ;
}
if ( V_15 )
goto V_403;
V_15 = V_52 ;
V_403:
F_39 ( V_39 ) ;
V_209:
F_6 ( V_100 ) ;
return V_15 ;
}
T_2 F_145 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_145 V_54 ;
struct V_405 V_56 ;
struct V_1 * V_2 ;
struct V_36 * V_39 ;
struct V_312 * V_192 ;
int V_15 = - V_65 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_2 = F_28 ( & V_38 , V_54 . V_37 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_39 = V_2 -> V_22 ;
V_192 = F_7 ( V_2 , struct V_312 , V_322 . V_27 ) ;
if ( ! F_146 ( & V_192 -> V_348 ) ) {
F_12 ( V_2 ) ;
return - V_172 ;
}
V_15 = F_136 ( V_39 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_192 -> V_353 )
F_96 ( & V_192 -> V_353 -> V_207 ) ;
F_20 ( & V_38 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_79 ( & V_2 -> V_171 ) ;
F_61 ( & V_48 -> V_9 ) ;
F_147 ( V_48 , & V_192 -> V_322 ) ;
V_56 . V_346 = V_192 -> V_322 . V_346 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
return - V_64 ;
return V_52 ;
}
T_2 F_148 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_148 V_54 ;
struct V_406 V_56 ;
struct V_407 * V_408 ;
struct V_409 * V_410 = NULL , * V_411 , * V_412 , * V_413 ;
struct V_36 * V_39 ;
int V_414 , V_415 ;
int V_416 ;
T_2 V_15 = - V_65 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
if ( V_52 < sizeof V_54 + V_54 . V_417 * V_54 . V_418 +
V_54 . V_419 * sizeof ( struct V_420 ) )
return - V_65 ;
if ( V_54 . V_417 < sizeof ( struct V_407 ) )
return - V_65 ;
V_408 = F_72 ( V_54 . V_417 , V_16 ) ;
if ( ! V_408 )
return - V_164 ;
V_39 = F_37 ( V_54 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
goto V_209;
V_416 = V_39 -> V_318 == V_421 ;
V_415 = 0 ;
V_411 = NULL ;
for ( V_414 = 0 ; V_414 < V_54 . V_418 ; ++ V_414 ) {
if ( F_47 ( V_408 ,
V_51 + sizeof V_54 + V_414 * V_54 . V_417 ,
V_54 . V_417 ) ) {
V_15 = - V_64 ;
goto V_306;
}
if ( V_408 -> V_422 + V_415 > V_54 . V_419 ) {
V_15 = - V_65 ;
goto V_306;
}
V_412 = F_72 ( F_149 ( sizeof *V_412 , sizeof ( struct V_423 ) ) +
V_408 -> V_422 * sizeof ( struct V_423 ) ,
V_16 ) ;
if ( ! V_412 ) {
V_15 = - V_164 ;
goto V_306;
}
if ( ! V_411 )
V_410 = V_412 ;
else
V_411 -> V_412 = V_412 ;
V_411 = V_412 ;
V_412 -> V_412 = NULL ;
V_412 -> V_285 = V_408 -> V_285 ;
V_412 -> V_422 = V_408 -> V_422 ;
V_412 -> V_287 = V_408 -> V_287 ;
V_412 -> V_424 = V_408 -> V_424 ;
if ( V_416 ) {
if ( V_412 -> V_287 != V_425 &&
V_412 -> V_287 != V_426 ) {
V_15 = - V_65 ;
goto V_306;
}
V_412 -> V_410 . V_427 . V_35 = F_35 ( V_408 -> V_410 . V_427 . V_35 ,
V_48 -> V_61 ) ;
if ( ! V_412 -> V_410 . V_427 . V_35 ) {
V_15 = - V_65 ;
goto V_306;
}
V_412 -> V_410 . V_427 . V_428 = V_408 -> V_410 . V_427 . V_428 ;
V_412 -> V_410 . V_427 . V_429 = V_408 -> V_410 . V_427 . V_429 ;
if ( V_412 -> V_287 == V_426 )
V_412 -> V_290 . V_291 =
( V_430 V_293 ) V_408 -> V_290 . V_291 ;
} else {
switch ( V_412 -> V_287 ) {
case V_431 :
V_412 -> V_290 . V_291 =
( V_430 V_293 ) V_408 -> V_290 . V_291 ;
case V_432 :
case V_433 :
V_412 -> V_410 . V_434 . V_435 =
V_408 -> V_410 . V_434 . V_435 ;
V_412 -> V_410 . V_434 . V_224 =
V_408 -> V_410 . V_434 . V_224 ;
break;
case V_426 :
V_412 -> V_290 . V_291 =
( V_430 V_293 ) V_408 -> V_290 . V_291 ;
break;
case V_436 :
V_412 -> V_290 . V_437 =
V_408 -> V_290 . V_437 ;
break;
case V_438 :
case V_439 :
V_412 -> V_410 . V_440 . V_435 =
V_408 -> V_410 . V_440 . V_435 ;
V_412 -> V_410 . V_440 . V_441 =
V_408 -> V_410 . V_440 . V_441 ;
V_412 -> V_410 . V_440 . V_442 = V_408 -> V_410 . V_440 . V_442 ;
V_412 -> V_410 . V_440 . V_224 = V_408 -> V_410 . V_440 . V_224 ;
case V_425 :
break;
default:
V_15 = - V_65 ;
goto V_306;
}
}
if ( V_412 -> V_422 ) {
V_412 -> V_443 = ( void * ) V_412 +
F_149 ( sizeof *V_412 , sizeof ( struct V_423 ) ) ;
if ( F_47 ( V_412 -> V_443 ,
V_51 + sizeof V_54 +
V_54 . V_418 * V_54 . V_417 +
V_415 * sizeof ( struct V_423 ) ,
V_412 -> V_422 * sizeof ( struct V_423 ) ) ) {
V_15 = - V_64 ;
goto V_306;
}
V_415 += V_412 -> V_422 ;
} else
V_412 -> V_443 = NULL ;
}
V_56 . V_413 = 0 ;
V_15 = V_39 -> V_69 -> V_444 ( V_39 -> V_350 , V_410 , & V_413 ) ;
if ( V_15 )
for ( V_412 = V_410 ; V_412 ; V_412 = V_412 -> V_412 ) {
++ V_56 . V_413 ;
if ( V_412 == V_413 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
V_15 = - V_64 ;
V_306:
F_39 ( V_39 ) ;
while ( V_410 ) {
if ( V_416 && V_410 -> V_410 . V_427 . V_35 )
F_36 ( V_410 -> V_410 . V_427 . V_35 ) ;
V_412 = V_410 -> V_412 ;
F_6 ( V_410 ) ;
V_410 = V_412 ;
}
V_209:
F_6 ( V_408 ) ;
return V_15 ? V_15 : V_52 ;
}
static struct V_445 * F_150 ( const char T_3 * V_51 ,
int V_52 ,
T_6 V_418 ,
T_6 V_419 ,
T_6 V_417 )
{
struct V_446 * V_408 ;
struct V_445 * V_410 = NULL , * V_411 , * V_412 ;
int V_415 ;
int V_414 ;
int V_15 ;
if ( V_52 < V_417 * V_418 +
V_419 * sizeof ( struct V_420 ) )
return F_113 ( - V_65 ) ;
if ( V_417 < sizeof ( struct V_446 ) )
return F_113 ( - V_65 ) ;
V_408 = F_72 ( V_417 , V_16 ) ;
if ( ! V_408 )
return F_113 ( - V_164 ) ;
V_415 = 0 ;
V_411 = NULL ;
for ( V_414 = 0 ; V_414 < V_418 ; ++ V_414 ) {
if ( F_47 ( V_408 , V_51 + V_414 * V_417 ,
V_417 ) ) {
V_15 = - V_64 ;
goto V_66;
}
if ( V_408 -> V_422 + V_415 > V_419 ) {
V_15 = - V_65 ;
goto V_66;
}
V_412 = F_72 ( F_149 ( sizeof *V_412 , sizeof ( struct V_423 ) ) +
V_408 -> V_422 * sizeof ( struct V_423 ) ,
V_16 ) ;
if ( ! V_412 ) {
V_15 = - V_164 ;
goto V_66;
}
if ( ! V_411 )
V_410 = V_412 ;
else
V_411 -> V_412 = V_412 ;
V_411 = V_412 ;
V_412 -> V_412 = NULL ;
V_412 -> V_285 = V_408 -> V_285 ;
V_412 -> V_422 = V_408 -> V_422 ;
if ( V_412 -> V_422 ) {
V_412 -> V_443 = ( void * ) V_412 +
F_149 ( sizeof *V_412 , sizeof ( struct V_423 ) ) ;
if ( F_47 ( V_412 -> V_443 ,
V_51 + V_418 * V_417 +
V_415 * sizeof ( struct V_423 ) ,
V_412 -> V_422 * sizeof ( struct V_423 ) ) ) {
V_15 = - V_64 ;
goto V_66;
}
V_415 += V_412 -> V_422 ;
} else
V_412 -> V_443 = NULL ;
}
F_6 ( V_408 ) ;
return V_410 ;
V_66:
F_6 ( V_408 ) ;
while ( V_410 ) {
V_412 = V_410 -> V_412 ;
F_6 ( V_410 ) ;
V_410 = V_412 ;
}
return F_113 ( V_15 ) ;
}
T_2 F_151 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_151 V_54 ;
struct V_447 V_56 ;
struct V_445 * V_410 , * V_412 , * V_413 ;
struct V_36 * V_39 ;
T_2 V_15 = - V_65 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_410 = F_150 ( V_51 + sizeof V_54 ,
V_52 - sizeof V_54 , V_54 . V_418 ,
V_54 . V_419 , V_54 . V_417 ) ;
if ( F_50 ( V_410 ) )
return F_51 ( V_410 ) ;
V_39 = F_37 ( V_54 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
goto V_209;
V_56 . V_413 = 0 ;
V_15 = V_39 -> V_69 -> V_448 ( V_39 -> V_350 , V_410 , & V_413 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
for ( V_412 = V_410 ; V_412 ; V_412 = V_412 -> V_412 ) {
++ V_56 . V_413 ;
if ( V_412 == V_413 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
V_15 = - V_64 ;
V_209:
while ( V_410 ) {
V_412 = V_410 -> V_412 ;
F_6 ( V_410 ) ;
V_410 = V_412 ;
}
return V_15 ? V_15 : V_52 ;
}
T_2 F_152 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_152 V_54 ;
struct V_449 V_56 ;
struct V_445 * V_410 , * V_412 , * V_413 ;
struct V_40 * V_43 ;
T_2 V_15 = - V_65 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_410 = F_150 ( V_51 + sizeof V_54 ,
V_52 - sizeof V_54 , V_54 . V_418 ,
V_54 . V_419 , V_54 . V_417 ) ;
if ( F_50 ( V_410 ) )
return F_51 ( V_410 ) ;
V_43 = F_41 ( V_54 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
goto V_209;
V_56 . V_413 = 0 ;
V_15 = V_43 -> V_69 -> V_450 ( V_43 , V_410 , & V_413 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
for ( V_412 = V_410 ; V_412 ; V_412 = V_412 -> V_412 ) {
++ V_56 . V_413 ;
if ( V_412 == V_413 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
V_15 = - V_64 ;
V_209:
while ( V_410 ) {
V_412 = V_410 -> V_412 ;
F_6 ( V_410 ) ;
V_410 = V_412 ;
}
return V_15 ? V_15 : V_52 ;
}
T_2 F_153 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_153 V_54 ;
struct V_451 V_56 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_32 * V_35 ;
struct V_452 V_100 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_2 = F_72 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_164 ;
F_1 ( V_2 , V_54 . V_3 , V_48 -> V_61 , & V_453 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_54 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_66;
}
V_100 . V_387 = V_54 . V_100 . V_387 ;
V_100 . V_299 = V_54 . V_100 . V_299 ;
V_100 . V_388 = V_54 . V_100 . V_388 ;
V_100 . V_389 = V_54 . V_100 . V_389 ;
V_100 . V_391 = V_54 . V_100 . V_390 ? V_392 : 0 ;
V_100 . V_142 = V_54 . V_100 . V_142 ;
V_100 . V_381 . V_383 = V_54 . V_100 . V_381 . V_383 ;
V_100 . V_381 . V_384 = V_54 . V_100 . V_381 . V_384 ;
V_100 . V_381 . V_385 = V_54 . V_100 . V_381 . V_385 ;
V_100 . V_381 . V_386 = V_54 . V_100 . V_381 . V_386 ;
V_100 . V_454 = 0 ;
memset ( & V_100 . V_455 , 0 , sizeof( V_100 . V_455 ) ) ;
memcpy ( V_100 . V_381 . V_379 . V_382 , V_54 . V_100 . V_381 . V_379 , 16 ) ;
V_35 = F_154 ( V_26 , & V_100 ) ;
if ( F_50 ( V_35 ) ) {
V_15 = F_51 ( V_35 ) ;
goto V_173;
}
V_35 -> V_27 = V_2 ;
V_2 -> V_22 = V_35 ;
V_15 = F_14 ( & V_34 , V_2 ) ;
if ( V_15 )
goto V_351;
V_56 . V_33 = V_2 -> V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) ) {
V_15 = - V_64 ;
goto V_170;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_171 , & V_48 -> V_61 -> V_76 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_52 ;
V_170:
F_20 ( & V_34 , V_2 ) ;
V_351:
F_155 ( V_35 ) ;
V_173:
F_32 ( V_26 ) ;
V_66:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_156 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 , int V_53 )
{
struct F_156 V_54 ;
struct V_32 * V_35 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_2 = F_28 ( & V_34 , V_54 . V_33 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_35 = V_2 -> V_22 ;
V_15 = F_155 ( V_35 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_34 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_79 ( & V_2 -> V_171 ) ;
F_61 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_52 ;
}
T_2 F_157 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_157 V_54 ;
struct V_36 * V_39 ;
struct V_312 * V_192 ;
struct V_456 * V_457 ;
int V_15 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_39 = F_38 ( V_54 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
return - V_65 ;
V_192 = F_7 ( V_39 -> V_27 , struct V_312 , V_322 . V_27 ) ;
F_158 (mcast, &obj->mcast_list, list)
if ( V_54 . V_458 == V_457 -> V_152 &&
! memcmp ( V_54 . V_459 , V_457 -> V_459 . V_382 , sizeof V_457 -> V_459 . V_382 ) ) {
V_15 = 0 ;
goto V_306;
}
V_457 = F_72 ( sizeof *V_457 , V_16 ) ;
if ( ! V_457 ) {
V_15 = - V_164 ;
goto V_306;
}
V_457 -> V_152 = V_54 . V_458 ;
memcpy ( V_457 -> V_459 . V_382 , V_54 . V_459 , sizeof V_457 -> V_459 . V_382 ) ;
V_15 = F_159 ( V_39 , & V_457 -> V_459 , V_54 . V_458 ) ;
if ( ! V_15 )
F_74 ( & V_457 -> V_171 , & V_192 -> V_348 ) ;
else
F_6 ( V_457 ) ;
V_306:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_52 ;
}
T_2 F_160 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_160 V_54 ;
struct V_312 * V_192 ;
struct V_36 * V_39 ;
struct V_456 * V_457 ;
int V_15 = - V_65 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_39 = F_38 ( V_54 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
return - V_65 ;
V_15 = F_161 ( V_39 , (union V_460 * ) V_54 . V_459 , V_54 . V_458 ) ;
if ( V_15 )
goto V_306;
V_192 = F_7 ( V_39 -> V_27 , struct V_312 , V_322 . V_27 ) ;
F_158 (mcast, &obj->mcast_list, list)
if ( V_54 . V_458 == V_457 -> V_152 &&
! memcmp ( V_54 . V_459 , V_457 -> V_459 . V_382 , sizeof V_457 -> V_459 . V_382 ) ) {
F_79 ( & V_457 -> V_171 ) ;
F_6 ( V_457 ) ;
break;
}
V_306:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_52 ;
}
static int F_162 ( struct V_461 * V_462 ,
union V_463 * V_464 )
{
if ( V_462 -> V_276 )
return - V_65 ;
V_464 -> type = V_462 -> type ;
switch ( V_464 -> type ) {
case V_465 :
V_464 -> V_466 . V_467 = sizeof( struct V_468 ) ;
if ( V_464 -> V_466 . V_467 != V_462 -> V_466 . V_467 )
return - V_65 ;
memcpy ( & V_464 -> V_466 . V_469 , & V_462 -> V_466 . V_469 ,
sizeof( struct V_470 ) ) ;
memcpy ( & V_464 -> V_466 . V_396 , & V_462 -> V_466 . V_396 ,
sizeof( struct V_470 ) ) ;
break;
case V_471 :
V_464 -> V_472 . V_467 = sizeof( struct V_473 ) ;
if ( V_464 -> V_472 . V_467 != V_462 -> V_472 . V_467 )
return - V_65 ;
memcpy ( & V_464 -> V_472 . V_469 , & V_462 -> V_472 . V_469 ,
sizeof( struct V_474 ) ) ;
memcpy ( & V_464 -> V_472 . V_396 , & V_462 -> V_472 . V_396 ,
sizeof( struct V_474 ) ) ;
break;
case V_475 :
case V_476 :
V_464 -> V_477 . V_467 = sizeof( struct V_478 ) ;
if ( V_464 -> V_477 . V_467 != V_462 -> V_477 . V_467 )
return - V_65 ;
memcpy ( & V_464 -> V_477 . V_469 , & V_462 -> V_477 . V_469 ,
sizeof( struct V_479 ) ) ;
memcpy ( & V_464 -> V_477 . V_396 , & V_462 -> V_477 . V_396 ,
sizeof( struct V_479 ) ) ;
break;
default:
return - V_65 ;
}
return 0 ;
}
int F_163 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_57 * V_247 ,
struct V_57 * V_248 )
{
struct V_480 V_54 ;
struct V_481 V_56 ;
struct V_1 * V_2 ;
struct V_482 * V_483 ;
struct V_484 * V_485 ;
struct V_486 * V_487 ;
struct V_36 * V_39 ;
int V_66 = 0 ;
void * V_462 ;
void * V_464 ;
int V_414 ;
if ( V_247 -> V_274 < sizeof( V_54 ) )
return - V_65 ;
if ( V_247 -> V_277 < sizeof( V_56 ) )
return - V_63 ;
V_66 = F_123 ( & V_54 , V_247 , sizeof( V_54 ) ) ;
if ( V_66 )
return V_66 ;
V_247 -> V_488 += sizeof( V_54 ) ;
V_247 -> V_274 -= sizeof( V_54 ) ;
if ( V_54 . V_275 )
return - V_65 ;
if ( ( V_54 . V_487 . type == V_489 &&
! F_133 ( V_490 ) ) || ! F_133 ( V_320 ) )
return - V_321 ;
if ( V_54 . V_487 . V_491 > V_492 )
return - V_65 ;
if ( V_54 . V_487 . V_467 > V_247 -> V_274 ||
V_54 . V_487 . V_467 >
( V_54 . V_487 . V_491 * sizeof( struct V_461 ) ) )
return - V_65 ;
if ( V_54 . V_487 . V_276 [ 0 ] ||
V_54 . V_487 . V_276 [ 1 ] )
return - V_65 ;
if ( V_54 . V_487 . V_491 ) {
V_485 = F_72 ( sizeof( * V_485 ) + V_54 . V_487 . V_467 ,
V_16 ) ;
if ( ! V_485 )
return - V_164 ;
memcpy ( V_485 , & V_54 . V_487 , sizeof( * V_485 ) ) ;
V_66 = F_123 ( V_485 + 1 , V_247 ,
V_54 . V_487 . V_467 ) ;
if ( V_66 )
goto V_493;
} else {
V_485 = & V_54 . V_487 ;
}
V_2 = F_72 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 ) {
V_66 = - V_164 ;
goto V_493;
}
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_494 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_39 = F_37 ( V_54 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_66 = - V_65 ;
goto V_495;
}
V_487 = F_72 ( sizeof( * V_487 ) + V_54 . V_487 . V_467 , V_16 ) ;
if ( ! V_487 ) {
V_66 = - V_164 ;
goto V_173;
}
V_487 -> type = V_485 -> type ;
V_487 -> V_496 = V_485 -> V_496 ;
V_487 -> V_491 = V_485 -> V_491 ;
V_487 -> V_497 = V_485 -> V_497 ;
V_487 -> V_228 = V_485 -> V_228 ;
V_487 -> V_467 = sizeof( * V_487 ) ;
V_462 = V_485 + 1 ;
V_464 = V_487 + 1 ;
for ( V_414 = 0 ; V_414 < V_487 -> V_491 &&
V_54 . V_487 . V_467 > F_115 ( struct V_461 , V_276 ) &&
V_54 . V_487 . V_467 >=
( (struct V_461 * ) V_462 ) -> V_467 ; V_414 ++ ) {
V_66 = F_162 ( V_462 , V_464 ) ;
if ( V_66 )
goto V_89;
V_487 -> V_467 +=
( (union V_463 * ) V_464 ) -> V_467 ;
V_54 . V_487 . V_467 -= ( (struct V_461 * ) V_462 ) -> V_467 ;
V_462 += ( (struct V_461 * ) V_462 ) -> V_467 ;
V_464 += ( (union V_463 * ) V_464 ) -> V_467 ;
}
if ( V_54 . V_487 . V_467 || ( V_414 != V_487 -> V_491 ) ) {
F_164 ( L_3 ,
V_414 , V_54 . V_487 . V_467 ) ;
V_66 = - V_65 ;
goto V_89;
}
V_483 = F_165 ( V_39 , V_487 , V_498 ) ;
if ( F_50 ( V_483 ) ) {
V_66 = F_51 ( V_483 ) ;
goto V_89;
}
V_483 -> V_39 = V_39 ;
V_483 -> V_27 = V_2 ;
V_2 -> V_22 = V_483 ;
V_66 = F_14 ( & V_499 , V_2 ) ;
if ( V_66 )
goto V_500;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_501 = V_2 -> V_19 ;
V_66 = F_120 ( V_247 ,
& V_56 , sizeof( V_56 ) ) ;
if ( V_66 )
goto V_170;
F_39 ( V_39 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_171 , & V_48 -> V_61 -> V_78 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_6 ( V_487 ) ;
if ( V_54 . V_487 . V_491 )
F_6 ( V_485 ) ;
return 0 ;
V_170:
F_20 ( & V_499 , V_2 ) ;
V_500:
F_166 ( V_483 ) ;
V_89:
F_6 ( V_487 ) ;
V_173:
F_39 ( V_39 ) ;
V_495:
F_12 ( V_2 ) ;
V_493:
if ( V_54 . V_487 . V_491 )
F_6 ( V_485 ) ;
return V_66 ;
}
int F_167 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_57 * V_247 ,
struct V_57 * V_248 )
{
struct V_502 V_54 ;
struct V_482 * V_483 ;
struct V_1 * V_2 ;
int V_15 ;
if ( V_247 -> V_274 < sizeof( V_54 ) )
return - V_65 ;
V_15 = F_123 ( & V_54 , V_247 , sizeof( V_54 ) ) ;
if ( V_15 )
return V_15 ;
if ( V_54 . V_275 )
return - V_65 ;
V_2 = F_28 ( & V_499 , V_54 . V_501 ,
V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_483 = V_2 -> V_22 ;
V_15 = F_166 ( V_483 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_499 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_79 ( & V_2 -> V_171 ) ;
F_61 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_15 ;
}
static int F_168 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_503 * V_54 ,
struct V_57 * V_58 )
{
struct V_504 V_56 ;
struct V_505 * V_192 ;
struct V_23 * V_26 ;
struct V_40 * V_43 ;
struct V_1 * V_313 ( V_314 ) ;
struct V_506 V_100 ;
int V_15 ;
V_192 = F_72 ( sizeof *V_192 , V_16 ) ;
if ( ! V_192 )
return - V_164 ;
F_1 ( & V_192 -> V_322 . V_27 , V_54 -> V_3 , V_48 -> V_61 , & V_507 ) ;
F_29 ( & V_192 -> V_322 . V_27 . V_9 ) ;
if ( V_54 -> V_329 == V_508 ) {
V_100 . V_509 . V_510 . V_178 = F_43 ( V_54 -> V_45 , V_48 -> V_61 , & V_314 ) ;
if ( ! V_100 . V_509 . V_510 . V_178 ) {
V_15 = - V_65 ;
goto V_66;
}
V_192 -> V_353 = F_7 ( V_314 , struct V_191 , V_27 ) ;
F_94 ( & V_192 -> V_353 -> V_207 ) ;
V_100 . V_509 . V_510 . V_31 = F_33 ( V_54 -> V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_100 . V_509 . V_510 . V_31 ) {
V_15 = - V_65 ;
goto V_511;
}
}
V_26 = F_31 ( V_54 -> V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_512;
}
V_100 . V_266 = V_513 ;
V_100 . V_514 = V_48 ;
V_100 . V_329 = V_54 -> V_329 ;
V_100 . V_100 . V_515 = V_54 -> V_515 ;
V_100 . V_100 . V_111 = V_54 -> V_111 ;
V_100 . V_100 . V_516 = V_54 -> V_516 ;
V_192 -> V_322 . V_346 = 0 ;
F_52 ( & V_192 -> V_322 . V_347 ) ;
V_43 = V_26 -> V_69 -> V_517 ( V_26 , & V_100 , V_58 ) ;
if ( F_50 ( V_43 ) ) {
V_15 = F_51 ( V_43 ) ;
goto V_173;
}
V_43 -> V_69 = V_26 -> V_69 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_329 = V_54 -> V_329 ;
V_43 -> V_27 = & V_192 -> V_322 . V_27 ;
V_43 -> V_266 = V_100 . V_266 ;
V_43 -> V_514 = V_100 . V_514 ;
if ( V_54 -> V_329 == V_508 ) {
V_43 -> V_509 . V_510 . V_31 = V_100 . V_509 . V_510 . V_31 ;
V_43 -> V_509 . V_510 . V_178 = V_100 . V_509 . V_510 . V_178 ;
F_94 ( & V_100 . V_509 . V_510 . V_31 -> V_168 ) ;
F_94 ( & V_100 . V_509 . V_510 . V_178 -> V_168 ) ;
}
F_94 ( & V_26 -> V_168 ) ;
F_73 ( & V_43 -> V_168 , 0 ) ;
V_192 -> V_322 . V_27 . V_22 = V_43 ;
V_15 = F_14 ( & V_42 , & V_192 -> V_322 . V_27 ) ;
if ( V_15 )
goto V_351;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_41 = V_192 -> V_322 . V_27 . V_19 ;
V_56 . V_515 = V_100 . V_100 . V_515 ;
V_56 . V_111 = V_100 . V_100 . V_111 ;
if ( V_54 -> V_329 == V_508 )
V_56 . V_518 = V_43 -> V_509 . V_510 . V_519 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 -> V_67 ,
& V_56 , sizeof V_56 ) ) {
V_15 = - V_64 ;
goto V_170;
}
if ( V_54 -> V_329 == V_508 ) {
F_10 ( V_314 ) ;
F_34 ( V_100 . V_509 . V_510 . V_31 ) ;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_192 -> V_322 . V_27 . V_171 , & V_48 -> V_61 -> V_75 ) ;
F_61 ( & V_48 -> V_9 ) ;
V_192 -> V_322 . V_27 . V_12 = 1 ;
F_13 ( & V_192 -> V_322 . V_27 . V_9 ) ;
return 0 ;
V_170:
F_20 ( & V_42 , & V_192 -> V_322 . V_27 ) ;
V_351:
F_169 ( V_43 ) ;
V_173:
F_32 ( V_26 ) ;
V_512:
if ( V_54 -> V_329 == V_508 )
F_34 ( V_100 . V_509 . V_510 . V_31 ) ;
V_511:
if ( V_54 -> V_329 == V_508 ) {
F_96 ( & V_192 -> V_353 -> V_207 ) ;
F_10 ( V_314 ) ;
}
V_66:
F_12 ( & V_192 -> V_322 . V_27 ) ;
return V_15 ;
}
T_2 F_170 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_170 V_54 ;
struct V_503 V_520 ;
struct V_504 V_56 ;
struct V_57 V_58 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_520 . V_67 = V_54 . V_67 ;
V_520 . V_3 = V_54 . V_3 ;
V_520 . V_329 = V_330 ;
V_520 . V_24 = V_54 . V_24 ;
V_520 . V_515 = V_54 . V_515 ;
V_520 . V_111 = V_54 . V_111 ;
V_520 . V_516 = V_54 . V_516 ;
F_49 ( & V_58 , V_51 + sizeof V_54 ,
( unsigned long ) V_54 . V_67 + sizeof V_56 ,
V_52 - sizeof V_54 , V_53 - sizeof V_56 ) ;
V_15 = F_168 ( V_48 , V_50 , & V_520 , & V_58 ) ;
if ( V_15 )
return V_15 ;
return V_52 ;
}
T_2 V_503 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 , int V_53 )
{
struct V_503 V_54 ;
struct V_504 V_56 ;
struct V_57 V_58 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_49 ( & V_58 , V_51 + sizeof V_54 ,
( unsigned long ) V_54 . V_67 + sizeof V_56 ,
V_52 - sizeof V_54 , V_53 - sizeof V_56 ) ;
V_15 = F_168 ( V_48 , V_50 , & V_54 , & V_58 ) ;
if ( V_15 )
return V_15 ;
return V_52 ;
}
T_2 F_171 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_171 V_54 ;
struct V_57 V_58 ;
struct V_40 * V_43 ;
struct V_521 V_100 ;
int V_15 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
F_49 ( & V_58 , V_51 + sizeof V_54 , NULL , V_52 - sizeof V_54 ,
V_53 ) ;
V_43 = F_41 ( V_54 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
return - V_65 ;
V_100 . V_515 = V_54 . V_515 ;
V_100 . V_516 = V_54 . V_516 ;
V_15 = V_43 -> V_69 -> V_522 ( V_43 , & V_100 , V_54 . V_359 , & V_58 ) ;
F_42 ( V_43 ) ;
return V_15 ? V_15 : V_52 ;
}
T_2 F_172 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 ,
int V_52 , int V_53 )
{
struct F_172 V_54 ;
struct V_523 V_56 ;
struct V_521 V_100 ;
struct V_40 * V_43 ;
int V_15 ;
if ( V_53 < sizeof V_56 )
return - V_63 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_43 = F_41 ( V_54 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
return - V_65 ;
V_15 = F_173 ( V_43 , & V_100 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_515 = V_100 . V_515 ;
V_56 . V_111 = V_100 . V_111 ;
V_56 . V_516 = V_100 . V_516 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
return - V_64 ;
return V_52 ;
}
T_2 F_174 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char T_3 * V_51 , int V_52 ,
int V_53 )
{
struct F_174 V_54 ;
struct V_524 V_56 ;
struct V_1 * V_2 ;
struct V_40 * V_43 ;
struct V_525 * V_192 ;
int V_15 = - V_65 ;
struct V_505 * V_526 ;
enum V_527 V_329 ;
if ( F_47 ( & V_54 , V_51 , sizeof V_54 ) )
return - V_64 ;
V_2 = F_28 ( & V_42 , V_54 . V_41 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_43 = V_2 -> V_22 ;
V_192 = F_7 ( V_2 , struct V_525 , V_27 ) ;
V_329 = V_43 -> V_329 ;
V_15 = F_169 ( V_43 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_329 == V_508 ) {
V_526 = F_7 ( V_192 , struct V_505 , V_322 ) ;
F_96 ( & V_526 -> V_353 -> V_207 ) ;
}
F_20 ( & V_42 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_79 ( & V_2 -> V_171 ) ;
F_61 ( & V_48 -> V_9 ) ;
F_147 ( V_48 , V_192 ) ;
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_346 = V_192 -> V_346 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_54 . V_67 ,
& V_56 , sizeof V_56 ) )
V_15 = - V_64 ;
return V_15 ? V_15 : V_52 ;
}
int F_175 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_57 * V_247 ,
struct V_57 * V_248 )
{
struct V_528 V_56 ;
struct F_175 V_54 ;
struct V_59 V_100 ;
int V_66 ;
if ( V_247 -> V_274 < sizeof( V_54 ) )
return - V_65 ;
V_66 = F_123 ( & V_54 , V_247 , sizeof( V_54 ) ) ;
if ( V_66 )
return V_66 ;
if ( V_54 . V_275 )
return - V_65 ;
if ( V_54 . V_276 )
return - V_65 ;
V_56 . V_270 = F_115 ( F_116 ( V_56 ) , V_529 ) ;
if ( V_247 -> V_277 < V_56 . V_270 )
return - V_63 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_66 = V_50 -> V_530 ( V_50 , & V_100 , V_248 ) ;
if ( V_66 )
return V_66 ;
F_66 ( V_48 , V_50 , & V_56 . V_269 , & V_100 ) ;
V_56 . V_275 = 0 ;
if ( V_247 -> V_277 < V_56 . V_270 + sizeof( V_56 . V_529 ) )
goto V_531;
#ifdef F_46
V_56 . V_529 . V_532 = V_100 . V_529 . V_532 ;
V_56 . V_529 . V_533 . V_534 =
V_100 . V_529 . V_533 . V_534 ;
V_56 . V_529 . V_533 . V_535 =
V_100 . V_529 . V_533 . V_535 ;
V_56 . V_529 . V_533 . V_536 =
V_100 . V_529 . V_533 . V_536 ;
V_56 . V_529 . V_276 = 0 ;
#else
memset ( & V_56 . V_529 , 0 , sizeof( V_56 . V_529 ) ) ;
#endif
V_56 . V_270 += sizeof( V_56 . V_529 ) ;
if ( V_247 -> V_277 < V_56 . V_270 + sizeof( V_56 . V_537 ) )
goto V_531;
V_56 . V_537 = V_100 . V_537 ;
V_56 . V_270 += sizeof( V_56 . V_537 ) ;
if ( V_247 -> V_277 < V_56 . V_270 + sizeof( V_56 . V_538 ) )
goto V_531;
V_56 . V_538 = V_100 . V_538 ;
V_56 . V_270 += sizeof( V_56 . V_538 ) ;
V_531:
V_66 = F_120 ( V_247 , & V_56 , V_56 . V_270 ) ;
if ( V_66 )
return V_66 ;
return 0 ;
}
