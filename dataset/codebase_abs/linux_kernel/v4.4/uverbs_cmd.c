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
static struct V_37 * F_40 ( int V_38 , struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( & V_39 , V_38 , V_5 ) ;
return V_2 ? V_2 -> V_23 : NULL ;
}
static void F_41 ( struct V_37 * V_40 )
{
F_10 ( V_40 -> V_28 ) ;
}
static void F_42 ( struct V_37 * V_40 )
{
F_12 ( V_40 -> V_28 ) ;
}
static struct V_41 * F_43 ( int V_42 , struct V_4 * V_5 )
{
return F_32 ( & V_43 , V_42 , V_5 , 0 ) ;
}
static void F_44 ( struct V_41 * V_44 )
{
F_10 ( V_44 -> V_28 ) ;
}
static struct V_45 * F_45 ( int V_46 , struct V_4 * V_5 ,
struct V_1 * * V_2 )
{
* V_2 = F_27 ( & V_47 , V_46 , V_5 , 0 ) ;
return * V_2 ? ( * V_2 ) -> V_23 : NULL ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
T_2 F_47 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_47 V_55 ;
struct V_56 V_57 ;
struct V_58 V_59 ;
#ifdef F_48
struct V_60 V_61 ;
#endif
struct V_4 * V_62 ;
struct V_49 * V_63 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_50 ( & V_49 -> V_9 ) ;
if ( V_49 -> V_62 ) {
V_16 = - V_66 ;
goto V_67;
}
F_51 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_68 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_62 = V_51 -> V_69 ( V_51 , & V_59 ) ;
if ( F_52 ( V_62 ) ) {
V_16 = F_53 ( V_62 ) ;
goto V_67;
}
V_62 -> V_70 = V_51 ;
F_54 ( & V_62 -> V_71 ) ;
F_54 ( & V_62 -> V_72 ) ;
F_54 ( & V_62 -> V_73 ) ;
F_54 ( & V_62 -> V_74 ) ;
F_54 ( & V_62 -> V_75 ) ;
F_54 ( & V_62 -> V_76 ) ;
F_54 ( & V_62 -> V_77 ) ;
F_54 ( & V_62 -> V_78 ) ;
F_54 ( & V_62 -> V_79 ) ;
F_23 () ;
V_62 -> V_80 = F_55 ( V_81 -> V_82 , V_83 ) ;
F_26 () ;
V_62 -> V_84 = 0 ;
#ifdef F_48
V_62 -> V_85 = V_86 ;
F_3 ( & V_62 -> V_87 ) ;
V_62 -> V_88 = 0 ;
F_54 ( & V_62 -> V_89 ) ;
V_16 = F_56 ( V_51 , & V_61 ) ;
if ( V_16 )
goto V_90;
if ( ! ( V_61 . V_91 & V_92 ) )
V_62 -> V_93 = NULL ;
#endif
V_57 . V_94 = V_49 -> V_70 -> V_94 ;
V_16 = F_57 ( V_95 ) ;
if ( V_16 < 0 )
goto V_90;
V_57 . V_96 = V_16 ;
V_63 = F_58 ( V_49 , V_51 , 1 ) ;
if ( F_52 ( V_63 ) ) {
V_16 = F_53 ( V_63 ) ;
goto V_97;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_65 ;
goto V_98;
}
V_49 -> V_62 = V_62 ;
F_60 ( V_57 . V_96 , V_63 ) ;
F_61 ( & V_49 -> V_9 ) ;
return V_53 ;
V_98:
F_62 ( V_49 ) ;
F_63 ( V_63 ) ;
V_97:
F_64 ( V_57 . V_96 ) ;
V_90:
F_65 ( V_62 -> V_80 ) ;
V_51 -> V_99 ( V_62 ) ;
V_67:
F_61 ( & V_49 -> V_9 ) ;
return V_16 ;
}
static void F_66 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_100 * V_57 ,
struct V_60 * V_101 )
{
V_57 -> V_102 = V_101 -> V_102 ;
V_57 -> V_103 = V_51 -> V_103 ;
V_57 -> V_104 = V_101 -> V_104 ;
V_57 -> V_105 = V_101 -> V_105 ;
V_57 -> V_106 = V_101 -> V_106 ;
V_57 -> V_107 = V_101 -> V_107 ;
V_57 -> V_108 = V_101 -> V_108 ;
V_57 -> V_109 = V_101 -> V_109 ;
V_57 -> V_110 = V_101 -> V_110 ;
V_57 -> V_111 = V_101 -> V_111 ;
V_57 -> V_91 = V_101 -> V_91 ;
V_57 -> V_112 = V_101 -> V_112 ;
V_57 -> V_113 = V_101 -> V_113 ;
V_57 -> V_114 = V_101 -> V_114 ;
V_57 -> V_115 = V_101 -> V_115 ;
V_57 -> V_116 = V_101 -> V_116 ;
V_57 -> V_117 = V_101 -> V_117 ;
V_57 -> V_118 = V_101 -> V_118 ;
V_57 -> V_119 = V_101 -> V_119 ;
V_57 -> V_120 = V_101 -> V_120 ;
V_57 -> V_121 = V_101 -> V_121 ;
V_57 -> V_122 = V_101 -> V_122 ;
V_57 -> V_123 = V_101 -> V_123 ;
V_57 -> V_124 = V_101 -> V_124 ;
V_57 -> V_125 = V_101 -> V_125 ;
V_57 -> V_126 = V_101 -> V_126 ;
V_57 -> V_127 = V_101 -> V_127 ;
V_57 -> V_128 = V_101 -> V_128 ;
V_57 -> V_129 = V_101 -> V_129 ;
V_57 -> V_130 = V_101 -> V_130 ;
V_57 -> V_131 = V_101 -> V_131 ;
V_57 -> V_132 = V_101 -> V_132 ;
V_57 -> V_133 = V_101 -> V_133 ;
V_57 -> V_134 = V_101 -> V_134 ;
V_57 -> V_135 = V_101 -> V_135 ;
V_57 -> V_136 = V_101 -> V_136 ;
V_57 -> V_137 = V_101 -> V_137 ;
V_57 -> V_138 = V_101 -> V_138 ;
V_57 -> V_139 = V_101 -> V_139 ;
V_57 -> V_140 = V_51 -> V_140 ;
}
T_2 F_67 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_67 V_55 ;
struct V_100 V_57 ;
struct V_60 V_101 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_16 = F_56 ( V_51 , & V_101 ) ;
if ( V_16 )
return V_16 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
F_66 ( V_49 , V_51 , & V_57 , & V_101 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
return - V_65 ;
return V_53 ;
}
T_2 F_68 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_68 V_55 ;
struct V_141 V_57 ;
struct V_142 V_101 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_16 = F_69 ( V_51 , V_55 . V_143 , & V_101 ) ;
if ( V_16 )
return V_16 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_144 = V_101 . V_144 ;
V_57 . V_145 = V_101 . V_145 ;
V_57 . V_146 = V_101 . V_146 ;
V_57 . V_147 = V_101 . V_147 ;
V_57 . V_148 = V_101 . V_148 ;
V_57 . V_149 = V_101 . V_149 ;
V_57 . V_150 = V_101 . V_150 ;
V_57 . V_151 = V_101 . V_151 ;
V_57 . V_152 = V_101 . V_152 ;
V_57 . V_153 = V_101 . V_153 ;
V_57 . V_154 = V_101 . V_154 ;
V_57 . V_155 = V_101 . V_155 ;
V_57 . V_156 = V_101 . V_156 ;
V_57 . V_157 = V_101 . V_157 ;
V_57 . V_158 = V_101 . V_158 ;
V_57 . V_159 = V_101 . V_159 ;
V_57 . V_160 = V_101 . V_160 ;
V_57 . V_161 = V_101 . V_161 ;
V_57 . V_162 = V_101 . V_162 ;
V_57 . V_163 = F_70 ( V_51 ,
V_55 . V_143 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
return - V_65 ;
return V_53 ;
}
T_2 F_71 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_71 V_55 ;
struct V_164 V_57 ;
struct V_58 V_59 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_51 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_68 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_2 = F_72 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , 0 , V_49 -> V_62 , & V_166 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = V_51 -> V_167 ( V_51 , V_49 -> V_62 , & V_59 ) ;
if ( F_52 ( V_27 ) ) {
V_16 = F_53 ( V_27 ) ;
goto V_67;
}
V_27 -> V_70 = V_51 ;
V_27 -> V_28 = V_2 ;
V_27 -> V_168 = NULL ;
F_73 ( & V_27 -> V_169 , 0 ) ;
V_2 -> V_23 = V_27 ;
V_16 = F_14 ( & V_26 , V_2 ) ;
if ( V_16 )
goto V_170;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_25 = V_2 -> V_20 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_65 ;
goto V_171;
}
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_62 -> V_71 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_26 , V_2 ) ;
V_170:
F_75 ( V_27 ) ;
V_67:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_76 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_76 V_55 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
int V_16 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_2 = F_30 ( & V_26 , V_55 . V_25 , V_49 -> V_62 ) ;
if ( ! V_2 )
return - V_66 ;
V_27 = V_2 -> V_23 ;
if ( F_77 ( & V_27 -> V_169 ) ) {
V_16 = - V_173 ;
goto V_174;
}
V_16 = V_27 -> V_70 -> V_175 ( V_2 -> V_23 ) ;
F_78 ( V_16 , L_1 ) ;
if ( V_16 )
goto V_174;
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_26 , V_2 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_61 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_53 ;
V_174:
F_12 ( V_2 ) ;
return V_16 ;
}
static int F_80 ( struct V_176 * V_177 ,
struct V_178 * V_178 ,
struct V_45 * V_179 )
{
struct V_180 * V_181 , * V_182 ;
struct V_183 * * V_184 = & V_177 -> V_185 . V_183 ;
struct V_183 * V_186 = NULL ;
V_181 = F_72 ( sizeof *V_181 , V_17 ) ;
if ( ! V_181 )
return - V_165 ;
V_181 -> V_179 = V_179 ;
V_181 -> V_178 = V_178 ;
while ( * V_184 ) {
V_186 = * V_184 ;
V_182 = F_81 ( V_186 , struct V_180 , V_187 ) ;
if ( V_178 < V_182 -> V_178 ) {
V_184 = & ( * V_184 ) -> V_188 ;
} else if ( V_178 > V_182 -> V_178 ) {
V_184 = & ( * V_184 ) -> V_189 ;
} else {
F_82 ( V_181 ) ;
return - V_190 ;
}
}
F_83 ( & V_181 -> V_187 , V_186 , V_184 ) ;
F_84 ( & V_181 -> V_187 , & V_177 -> V_185 ) ;
F_85 ( V_178 ) ;
return 0 ;
}
static struct V_180 * F_86 ( struct V_176 * V_177 ,
struct V_178 * V_178 )
{
struct V_180 * V_181 ;
struct V_183 * V_184 = V_177 -> V_185 . V_183 ;
while ( V_184 ) {
V_181 = F_81 ( V_184 , struct V_180 , V_187 ) ;
if ( V_178 < V_181 -> V_178 )
V_184 = V_184 -> V_188 ;
else if ( V_178 > V_181 -> V_178 )
V_184 = V_184 -> V_189 ;
else
return V_181 ;
}
return NULL ;
}
static struct V_45 * F_87 ( struct V_176 * V_177 , struct V_178 * V_178 )
{
struct V_180 * V_181 ;
V_181 = F_86 ( V_177 , V_178 ) ;
if ( ! V_181 )
return NULL ;
return V_181 -> V_179 ;
}
static void F_88 ( struct V_176 * V_177 ,
struct V_178 * V_178 )
{
struct V_180 * V_181 ;
V_181 = F_86 ( V_177 , V_178 ) ;
if ( V_181 ) {
F_89 ( V_178 ) ;
F_90 ( & V_181 -> V_187 , & V_177 -> V_185 ) ;
F_82 ( V_181 ) ;
}
}
T_2 F_91 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_91 V_55 ;
struct V_191 V_57 ;
struct V_58 V_59 ;
struct V_192 * V_193 ;
struct V_45 * V_179 = NULL ;
struct V_194 V_195 = { NULL , 0 } ;
struct V_178 * V_178 = NULL ;
int V_16 = 0 ;
int V_196 = 0 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_51 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_68 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
F_50 ( & V_49 -> V_70 -> V_197 ) ;
if ( V_55 . V_194 != - 1 ) {
V_195 = F_92 ( V_55 . V_194 ) ;
if ( ! V_195 . V_49 ) {
V_16 = - V_198 ;
goto V_199;
}
V_178 = F_93 ( V_195 . V_49 ) ;
V_179 = F_87 ( V_49 -> V_70 , V_178 ) ;
if ( ! V_179 && ! ( V_55 . V_200 & V_201 ) ) {
V_16 = - V_202 ;
goto V_199;
}
if ( V_179 && V_55 . V_200 & V_203 ) {
V_16 = - V_66 ;
goto V_199;
}
}
V_193 = F_72 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 ) {
V_16 = - V_165 ;
goto V_199;
}
F_1 ( & V_193 -> V_28 , 0 , V_49 -> V_62 , & V_204 ) ;
F_31 ( & V_193 -> V_28 . V_9 ) ;
if ( ! V_179 ) {
V_179 = V_51 -> V_205 ( V_51 , V_49 -> V_62 , & V_59 ) ;
if ( F_52 ( V_179 ) ) {
V_16 = F_53 ( V_179 ) ;
goto V_67;
}
V_179 -> V_178 = V_178 ;
V_179 -> V_70 = V_51 ;
F_73 ( & V_179 -> V_169 , 0 ) ;
F_94 ( & V_179 -> V_206 ) ;
F_54 ( & V_179 -> V_207 ) ;
V_196 = 1 ;
}
F_73 ( & V_193 -> V_208 , 0 ) ;
V_193 -> V_28 . V_23 = V_179 ;
V_16 = F_14 ( & V_47 , & V_193 -> V_28 ) ;
if ( V_16 )
goto V_170;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_46 = V_193 -> V_28 . V_20 ;
if ( V_178 ) {
if ( V_196 ) {
V_16 = F_80 ( V_49 -> V_70 , V_178 , V_179 ) ;
if ( V_16 )
goto V_209;
}
F_95 ( & V_179 -> V_169 ) ;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_65 ;
goto V_171;
}
if ( V_195 . V_49 )
F_96 ( V_195 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_28 . V_172 , & V_49 -> V_62 -> V_78 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_193 -> V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_28 . V_9 ) ;
F_61 ( & V_49 -> V_70 -> V_197 ) ;
return V_53 ;
V_171:
if ( V_178 ) {
if ( V_196 )
F_88 ( V_49 -> V_70 , V_178 ) ;
F_97 ( & V_179 -> V_169 ) ;
}
V_209:
F_20 ( & V_47 , & V_193 -> V_28 ) ;
V_170:
F_98 ( V_179 ) ;
V_67:
F_12 ( & V_193 -> V_28 ) ;
V_199:
if ( V_195 . V_49 )
F_96 ( V_195 ) ;
F_61 ( & V_49 -> V_70 -> V_197 ) ;
return V_16 ;
}
T_2 F_99 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_99 V_55 ;
struct V_1 * V_2 ;
struct V_45 * V_179 = NULL ;
struct V_178 * V_178 = NULL ;
struct V_192 * V_193 ;
int V_12 ;
int V_16 = 0 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_50 ( & V_49 -> V_70 -> V_197 ) ;
V_2 = F_30 ( & V_47 , V_55 . V_46 , V_49 -> V_62 ) ;
if ( ! V_2 ) {
V_16 = - V_66 ;
goto V_210;
}
V_179 = V_2 -> V_23 ;
V_178 = V_179 -> V_178 ;
V_193 = F_7 ( V_2 , struct V_192 , V_28 ) ;
if ( F_77 ( & V_193 -> V_208 ) ) {
F_12 ( V_2 ) ;
V_16 = - V_173 ;
goto V_210;
}
if ( ! V_178 || F_100 ( & V_179 -> V_169 ) ) {
V_16 = F_98 ( V_2 -> V_23 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
}
V_12 = V_2 -> V_12 ;
if ( V_178 && V_16 )
F_95 ( & V_179 -> V_169 ) ;
F_12 ( V_2 ) ;
if ( V_16 )
goto V_210;
if ( V_178 && ! V_12 )
F_88 ( V_49 -> V_70 , V_178 ) ;
F_20 ( & V_47 , V_2 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_61 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
V_16 = V_53 ;
V_210:
F_61 ( & V_49 -> V_70 -> V_197 ) ;
return V_16 ;
}
void F_101 ( struct V_176 * V_177 ,
struct V_45 * V_179 )
{
struct V_178 * V_178 ;
V_178 = V_179 -> V_178 ;
if ( V_178 && ! F_100 ( & V_179 -> V_169 ) )
return;
F_98 ( V_179 ) ;
if ( V_178 )
F_88 ( V_177 , V_178 ) ;
}
T_2 F_102 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_102 V_55 ;
struct V_211 V_57 ;
struct V_58 V_59 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_212 * V_213 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_51 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_68 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
if ( ( V_55 . V_214 & ~ V_215 ) != ( V_55 . V_216 & ~ V_215 ) )
return - V_66 ;
V_16 = F_103 ( V_55 . V_217 ) ;
if ( V_16 )
return V_16 ;
V_2 = F_72 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , 0 , V_49 -> V_62 , & V_218 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_62 ) ;
if ( ! V_27 ) {
V_16 = - V_66 ;
goto V_90;
}
if ( V_55 . V_217 & V_219 ) {
struct V_60 V_101 ;
V_16 = F_56 ( V_27 -> V_70 , & V_101 ) ;
if ( V_16 || ! ( V_101 . V_91 &
V_92 ) ) {
F_104 ( L_2 ) ;
V_16 = - V_66 ;
goto V_174;
}
}
V_213 = V_27 -> V_70 -> V_220 ( V_27 , V_55 . V_214 , V_55 . V_221 , V_55 . V_216 ,
V_55 . V_217 , & V_59 ) ;
if ( F_52 ( V_213 ) ) {
V_16 = F_53 ( V_213 ) ;
goto V_174;
}
V_213 -> V_70 = V_27 -> V_70 ;
V_213 -> V_27 = V_27 ;
V_213 -> V_28 = V_2 ;
F_95 ( & V_27 -> V_169 ) ;
F_73 ( & V_213 -> V_169 , 0 ) ;
V_2 -> V_23 = V_213 ;
V_16 = F_14 ( & V_222 , V_2 ) ;
if ( V_16 )
goto V_223;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_224 = V_213 -> V_224 ;
V_57 . V_225 = V_213 -> V_225 ;
V_57 . V_226 = V_2 -> V_20 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_65 ;
goto V_171;
}
F_34 ( V_27 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_62 -> V_72 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_222 , V_2 ) ;
V_223:
F_105 ( V_213 ) ;
V_174:
F_34 ( V_27 ) ;
V_90:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_106 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_106 V_55 ;
struct V_227 V_57 ;
struct V_58 V_59 ;
struct V_24 * V_27 = NULL ;
struct V_212 * V_213 ;
struct V_24 * V_228 ;
int V_16 ;
struct V_1 * V_2 ;
if ( V_54 < sizeof( V_57 ) )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_65 ;
F_51 ( & V_59 , V_52 + sizeof( V_55 ) ,
( unsigned long ) V_55 . V_68 + sizeof( V_57 ) ,
V_53 - sizeof( V_55 ) , V_54 - sizeof( V_57 ) ) ;
if ( V_55 . V_229 & ~ V_230 || ! V_55 . V_229 )
return - V_66 ;
if ( ( V_55 . V_229 & V_231 ) &&
( ! V_55 . V_214 || ! V_55 . V_216 || 0 >= V_55 . V_221 ||
( V_55 . V_214 & ~ V_215 ) != ( V_55 . V_216 & ~ V_215 ) ) )
return - V_66 ;
V_2 = F_30 ( & V_222 , V_55 . V_226 ,
V_49 -> V_62 ) ;
if ( ! V_2 )
return - V_66 ;
V_213 = V_2 -> V_23 ;
if ( V_55 . V_229 & V_232 ) {
V_16 = F_103 ( V_55 . V_217 ) ;
if ( V_16 )
goto V_233;
}
if ( V_55 . V_229 & V_234 ) {
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_62 ) ;
if ( ! V_27 ) {
V_16 = - V_66 ;
goto V_233;
}
}
if ( F_77 ( & V_213 -> V_169 ) ) {
V_16 = - V_173 ;
goto V_235;
}
V_228 = V_213 -> V_27 ;
V_16 = V_213 -> V_70 -> V_236 ( V_213 , V_55 . V_229 , V_55 . V_214 ,
V_55 . V_221 , V_55 . V_216 ,
V_55 . V_217 , V_27 , & V_59 ) ;
if ( ! V_16 ) {
if ( V_55 . V_229 & V_234 ) {
F_95 ( & V_27 -> V_169 ) ;
V_213 -> V_27 = V_27 ;
F_97 ( & V_228 -> V_169 ) ;
}
} else {
goto V_235;
}
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_224 = V_213 -> V_224 ;
V_57 . V_225 = V_213 -> V_225 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof( V_57 ) ) )
V_16 = - V_65 ;
else
V_16 = V_53 ;
V_235:
if ( V_55 . V_229 & V_234 )
F_34 ( V_27 ) ;
V_233:
F_12 ( V_213 -> V_28 ) ;
return V_16 ;
}
T_2 F_107 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_107 V_55 ;
struct V_212 * V_213 ;
struct V_1 * V_2 ;
int V_16 = - V_66 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_2 = F_30 ( & V_222 , V_55 . V_226 , V_49 -> V_62 ) ;
if ( ! V_2 )
return - V_66 ;
V_213 = V_2 -> V_23 ;
V_16 = F_105 ( V_213 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_222 , V_2 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_61 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_53 ;
}
T_2 F_108 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_108 V_55 ;
struct V_237 V_57 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_238 * V_239 ;
int V_16 ;
if ( V_54 < sizeof( V_57 ) )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_65 ;
V_2 = F_72 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , 0 , V_49 -> V_62 , & V_240 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_62 ) ;
if ( ! V_27 ) {
V_16 = - V_66 ;
goto V_90;
}
V_239 = V_27 -> V_70 -> V_241 ( V_27 , V_55 . V_242 ) ;
if ( F_52 ( V_239 ) ) {
V_16 = F_53 ( V_239 ) ;
goto V_174;
}
V_239 -> V_70 = V_27 -> V_70 ;
V_239 -> V_27 = V_27 ;
V_239 -> V_28 = V_2 ;
F_95 ( & V_27 -> V_169 ) ;
V_2 -> V_23 = V_239 ;
V_16 = F_14 ( & V_243 , V_2 ) ;
if ( V_16 )
goto V_244;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_225 = V_239 -> V_225 ;
V_57 . V_245 = V_2 -> V_20 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof( V_57 ) ) ) {
V_16 = - V_65 ;
goto V_171;
}
F_34 ( V_27 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_62 -> V_73 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_243 , V_2 ) ;
V_244:
F_109 ( V_239 ) ;
V_174:
F_34 ( V_27 ) ;
V_90:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_110 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_110 V_55 ;
struct V_238 * V_239 ;
struct V_1 * V_2 ;
int V_16 = - V_66 ;
if ( F_49 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_65 ;
V_2 = F_30 ( & V_243 , V_55 . V_245 , V_49 -> V_62 ) ;
if ( ! V_2 )
return - V_66 ;
V_239 = V_2 -> V_23 ;
V_16 = F_109 ( V_239 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_243 , V_2 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_61 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_53 ;
}
T_2 F_111 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_111 V_55 ;
struct V_246 V_57 ;
struct V_49 * V_63 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_16 = F_57 ( V_95 ) ;
if ( V_16 < 0 )
return V_16 ;
V_57 . V_194 = V_16 ;
V_63 = F_58 ( V_49 , V_51 , 0 ) ;
if ( F_52 ( V_63 ) ) {
F_64 ( V_57 . V_194 ) ;
return F_53 ( V_63 ) ;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) ) {
F_64 ( V_57 . V_194 ) ;
F_63 ( V_63 ) ;
return - V_65 ;
}
F_60 ( V_57 . V_194 , V_63 ) ;
return V_53 ;
}
static struct V_247 * F_112 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 ,
struct V_250 * V_55 ,
T_4 V_251 ,
int (* F_113)( struct V_48 * V_49 ,
struct V_247 * V_193 ,
struct V_252 * V_57 ,
struct V_58 * V_59 ,
void * V_5 ) ,
void * V_5 )
{
struct V_247 * V_193 ;
struct V_253 * V_254 = NULL ;
struct V_29 * V_32 ;
int V_16 ;
struct V_252 V_57 ;
struct V_255 V_101 = {} ;
if ( V_55 -> V_256 >= V_49 -> V_70 -> V_94 )
return F_114 ( - V_66 ) ;
V_193 = F_72 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return F_114 ( - V_165 ) ;
F_1 ( & V_193 -> V_28 , V_55 -> V_3 , V_49 -> V_62 , & V_257 ) ;
F_31 ( & V_193 -> V_28 . V_9 ) ;
if ( V_55 -> V_258 >= 0 ) {
V_254 = F_115 ( V_55 -> V_258 ) ;
if ( ! V_254 ) {
V_16 = - V_66 ;
goto V_67;
}
}
V_193 -> V_259 = V_49 ;
V_193 -> V_260 = 0 ;
V_193 -> V_261 = 0 ;
F_54 ( & V_193 -> V_262 ) ;
F_54 ( & V_193 -> V_263 ) ;
V_101 . V_264 = V_55 -> V_264 ;
V_101 . V_256 = V_55 -> V_256 ;
if ( V_251 > F_116 ( F_117 ( * V_55 ) , V_229 ) + sizeof( V_55 -> V_229 ) )
V_101 . V_229 = V_55 -> V_229 ;
V_32 = V_51 -> F_112 ( V_51 , & V_101 ,
V_49 -> V_62 , V_249 ) ;
if ( F_52 ( V_32 ) ) {
V_16 = F_53 ( V_32 ) ;
goto V_98;
}
V_32 -> V_70 = V_51 ;
V_32 -> V_28 = & V_193 -> V_28 ;
V_32 -> V_265 = V_266 ;
V_32 -> V_267 = V_268 ;
V_32 -> V_269 = V_254 ;
F_73 ( & V_32 -> V_169 , 0 ) ;
V_193 -> V_28 . V_23 = V_32 ;
V_16 = F_14 ( & V_31 , & V_193 -> V_28 ) ;
if ( V_16 )
goto V_90;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_270 . V_30 = V_193 -> V_28 . V_20 ;
V_57 . V_270 . V_264 = V_32 -> V_264 ;
V_57 . V_271 = F_116 ( F_117 ( V_57 ) , V_271 ) +
sizeof( V_57 . V_271 ) ;
V_16 = F_113 ( V_49 , V_193 , & V_57 , V_248 , V_5 ) ;
if ( V_16 )
goto V_272;
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_28 . V_172 , & V_49 -> V_62 -> V_74 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_193 -> V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_28 . V_9 ) ;
return V_193 ;
V_272:
F_20 ( & V_31 , & V_193 -> V_28 ) ;
V_90:
F_118 ( V_32 ) ;
V_98:
if ( V_254 )
F_119 ( V_49 , V_254 , V_193 ) ;
V_67:
F_12 ( & V_193 -> V_28 ) ;
return F_114 ( V_16 ) ;
}
static int F_120 ( struct V_48 * V_49 ,
struct V_247 * V_193 ,
struct V_252 * V_57 ,
struct V_58 * V_248 , void * V_5 )
{
if ( F_121 ( V_248 , & V_57 -> V_270 , sizeof( V_57 -> V_270 ) ) )
return - V_65 ;
return 0 ;
}
T_2 F_122 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_122 V_55 ;
struct V_250 V_273 ;
struct V_274 V_57 ;
struct V_58 V_248 ;
struct V_58 V_249 ;
struct V_247 * V_193 ;
if ( V_54 < sizeof( V_57 ) )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_65 ;
F_51 ( & V_248 , V_52 , ( unsigned long ) V_55 . V_68 , sizeof( V_55 ) , sizeof( V_57 ) ) ;
F_51 ( & V_249 , V_52 + sizeof( V_55 ) ,
( unsigned long ) V_55 . V_68 + sizeof( V_57 ) ,
V_53 - sizeof( V_55 ) , V_54 - sizeof( V_57 ) ) ;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_3 = V_55 . V_3 ;
V_273 . V_264 = V_55 . V_264 ;
V_273 . V_256 = V_55 . V_256 ;
V_273 . V_258 = V_55 . V_258 ;
V_193 = F_112 ( V_49 , V_51 , & V_248 , & V_249 , & V_273 ,
F_116 ( F_117 ( V_273 ) , V_258 ) +
sizeof( V_55 . V_258 ) , F_120 ,
NULL ) ;
if ( F_52 ( V_193 ) )
return F_53 ( V_193 ) ;
return V_53 ;
}
static int F_123 ( struct V_48 * V_49 ,
struct V_247 * V_193 ,
struct V_252 * V_57 ,
struct V_58 * V_248 , void * V_5 )
{
if ( F_121 ( V_248 , V_57 , V_57 -> V_271 ) )
return - V_65 ;
return 0 ;
}
int V_250 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 )
{
struct V_252 V_57 ;
struct V_250 V_55 ;
struct V_247 * V_193 ;
int V_67 ;
if ( V_248 -> V_275 < sizeof( V_55 ) )
return - V_66 ;
V_67 = F_124 ( & V_55 , V_248 , sizeof( V_55 ) ) ;
if ( V_67 )
return V_67 ;
if ( V_55 . V_276 )
return - V_66 ;
if ( V_55 . V_277 )
return - V_66 ;
if ( V_248 -> V_278 < ( F_116 ( F_117 ( V_57 ) , V_271 ) +
sizeof( V_57 . V_271 ) ) )
return - V_64 ;
V_193 = F_112 ( V_49 , V_51 , V_248 , V_249 , & V_55 ,
F_125 ( V_248 -> V_275 , sizeof( V_55 ) ) ,
F_123 , NULL ) ;
if ( F_52 ( V_193 ) )
return F_53 ( V_193 ) ;
return 0 ;
}
T_2 F_126 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_126 V_55 ;
struct V_279 V_57 ;
struct V_58 V_59 ;
struct V_29 * V_32 ;
int V_16 = - V_66 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_51 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_68 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_32 = F_35 ( V_55 . V_30 , V_49 -> V_62 , 0 ) ;
if ( ! V_32 )
return - V_66 ;
V_16 = V_32 -> V_70 -> V_280 ( V_32 , V_55 . V_264 , & V_59 ) ;
if ( V_16 )
goto V_210;
V_57 . V_264 = V_32 -> V_264 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 . V_264 ) )
V_16 = - V_65 ;
V_210:
F_36 ( V_32 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_127 ( void T_3 * V_281 , struct V_282 * V_283 )
{
struct V_284 V_285 ;
V_285 . V_286 = V_283 -> V_286 ;
V_285 . V_287 = V_283 -> V_287 ;
V_285 . V_288 = V_283 -> V_288 ;
V_285 . V_289 = V_283 -> V_289 ;
V_285 . V_290 = V_283 -> V_290 ;
V_285 . V_291 . V_292 = ( V_293 V_294 ) V_283 -> V_291 . V_292 ;
V_285 . V_295 = V_283 -> V_40 -> V_295 ;
V_285 . V_296 = V_283 -> V_296 ;
V_285 . V_297 = V_283 -> V_297 ;
V_285 . V_298 = V_283 -> V_298 ;
V_285 . V_299 = V_283 -> V_299 ;
V_285 . V_300 = V_283 -> V_300 ;
V_285 . V_301 = V_283 -> V_301 ;
V_285 . V_143 = V_283 -> V_143 ;
V_285 . V_277 = 0 ;
if ( F_59 ( V_281 , & V_285 , sizeof V_285 ) )
return - V_65 ;
return 0 ;
}
T_2 F_128 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_128 V_55 ;
struct V_302 V_57 ;
T_5 T_3 * V_303 ;
T_5 T_3 * V_304 ;
struct V_29 * V_32 ;
struct V_282 V_283 ;
int V_16 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_32 = F_35 ( V_55 . V_30 , V_49 -> V_62 , 0 ) ;
if ( ! V_32 )
return - V_66 ;
V_303 = ( void T_3 * ) ( unsigned long ) V_55 . V_68 ;
V_304 = V_303 + sizeof V_57 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
while ( V_57 . V_305 < V_55 . V_306 ) {
V_16 = F_129 ( V_32 , 1 , & V_283 ) ;
if ( V_16 < 0 )
goto V_307;
if ( ! V_16 )
break;
V_16 = F_127 ( V_304 , & V_283 ) ;
if ( V_16 )
goto V_307;
V_304 += sizeof( struct V_284 ) ;
++ V_57 . V_305 ;
}
if ( F_59 ( V_303 , & V_57 , sizeof V_57 ) ) {
V_16 = - V_65 ;
goto V_307;
}
V_16 = V_53 ;
V_307:
F_36 ( V_32 ) ;
return V_16 ;
}
T_2 F_130 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_130 V_55 ;
struct V_29 * V_32 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_32 = F_35 ( V_55 . V_30 , V_49 -> V_62 , 0 ) ;
if ( ! V_32 )
return - V_66 ;
F_131 ( V_32 , V_55 . V_308 ?
V_309 : V_310 ) ;
F_36 ( V_32 ) ;
return V_53 ;
}
T_2 F_132 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_132 V_55 ;
struct V_311 V_57 ;
struct V_1 * V_2 ;
struct V_29 * V_32 ;
struct V_247 * V_193 ;
struct V_253 * V_254 ;
int V_16 = - V_66 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_2 = F_30 ( & V_31 , V_55 . V_30 , V_49 -> V_62 ) ;
if ( ! V_2 )
return - V_66 ;
V_32 = V_2 -> V_23 ;
V_254 = V_32 -> V_269 ;
V_193 = F_7 ( V_32 -> V_28 , struct V_247 , V_28 ) ;
V_16 = F_118 ( V_32 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_31 , V_2 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_61 ( & V_49 -> V_9 ) ;
F_119 ( V_49 , V_254 , V_193 ) ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_260 = V_193 -> V_260 ;
V_57 . V_261 = V_193 -> V_261 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
return - V_65 ;
return V_53 ;
}
static int F_133 ( struct V_48 * V_49 ,
struct V_58 * V_248 ,
struct V_58 * V_249 ,
struct V_312 * V_55 ,
T_4 V_251 ,
int (* F_113)( struct V_48 * V_49 ,
struct V_313 * V_57 ,
struct V_58 * V_59 ) ,
void * V_5 )
{
struct V_314 * V_193 ;
struct V_50 * V_70 ;
struct V_24 * V_27 = NULL ;
struct V_45 * V_179 = NULL ;
struct V_1 * V_315 ( V_316 ) ;
struct V_29 * V_317 = NULL , * V_318 = NULL ;
struct V_41 * V_44 = NULL ;
struct V_37 * V_40 ;
char * V_52 ;
struct V_319 V_101 ;
struct V_313 V_57 ;
int V_16 ;
if ( V_55 -> V_320 == V_321 && ! F_134 ( V_322 ) )
return - V_323 ;
V_193 = F_135 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return - V_165 ;
F_1 ( & V_193 -> V_324 . V_28 , V_55 -> V_3 , V_49 -> V_62 ,
& V_325 ) ;
F_31 ( & V_193 -> V_324 . V_28 . V_9 ) ;
if ( V_55 -> V_320 == V_326 ) {
V_179 = F_45 ( V_55 -> V_25 , V_49 -> V_62 ,
& V_316 ) ;
if ( ! V_179 ) {
V_16 = - V_66 ;
goto V_174;
}
V_70 = V_179 -> V_70 ;
} else {
if ( V_55 -> V_320 == V_327 ) {
V_55 -> V_328 = 0 ;
V_55 -> V_329 = 0 ;
} else {
if ( V_55 -> V_330 ) {
V_44 = F_43 ( V_55 -> V_42 ,
V_49 -> V_62 ) ;
if ( ! V_44 || V_44 -> V_331 != V_332 ) {
V_16 = - V_66 ;
goto V_174;
}
}
if ( V_55 -> V_333 != V_55 -> V_334 ) {
V_318 = F_35 ( V_55 -> V_333 ,
V_49 -> V_62 , 0 ) ;
if ( ! V_318 ) {
V_16 = - V_66 ;
goto V_174;
}
}
}
V_317 = F_35 ( V_55 -> V_334 , V_49 -> V_62 , ! ! V_318 ) ;
V_318 = V_318 ? : V_317 ;
V_27 = F_33 ( V_55 -> V_25 , V_49 -> V_62 ) ;
if ( ! V_27 || ! V_317 ) {
V_16 = - V_66 ;
goto V_174;
}
V_70 = V_27 -> V_70 ;
}
V_101 . V_267 = V_335 ;
V_101 . V_336 = V_49 ;
V_101 . V_337 = V_317 ;
V_101 . V_338 = V_318 ;
V_101 . V_44 = V_44 ;
V_101 . V_179 = V_179 ;
V_101 . V_339 = V_55 -> V_340 ? V_341 :
V_342 ;
V_101 . V_320 = V_55 -> V_320 ;
V_101 . V_343 = 0 ;
V_101 . V_344 . V_345 = V_55 -> V_345 ;
V_101 . V_344 . V_328 = V_55 -> V_328 ;
V_101 . V_344 . V_346 = V_55 -> V_346 ;
V_101 . V_344 . V_329 = V_55 -> V_329 ;
V_101 . V_344 . V_347 = V_55 -> V_347 ;
V_193 -> V_324 . V_348 = 0 ;
F_54 ( & V_193 -> V_324 . V_349 ) ;
F_54 ( & V_193 -> V_350 ) ;
if ( V_251 >= F_116 ( F_117 ( * V_55 ) , V_343 ) +
sizeof( V_55 -> V_343 ) )
V_101 . V_343 = V_55 -> V_343 ;
if ( V_101 . V_343 & ~ V_351 ) {
V_16 = - V_66 ;
goto V_174;
}
V_52 = ( void * ) V_55 + sizeof( * V_55 ) ;
if ( V_251 > sizeof( * V_55 ) )
if ( ! ( V_52 [ 0 ] == 0 && ! memcmp ( V_52 , V_52 + 1 ,
V_251 - sizeof( * V_55 ) - 1 ) ) ) {
V_16 = - V_66 ;
goto V_174;
}
if ( V_55 -> V_320 == V_326 )
V_40 = F_136 ( V_27 , & V_101 ) ;
else
V_40 = V_70 -> F_133 ( V_27 , & V_101 , V_249 ) ;
if ( F_52 ( V_40 ) ) {
V_16 = F_53 ( V_40 ) ;
goto V_174;
}
if ( V_55 -> V_320 != V_326 ) {
V_40 -> V_352 = V_40 ;
V_40 -> V_70 = V_70 ;
V_40 -> V_27 = V_27 ;
V_40 -> V_337 = V_101 . V_337 ;
V_40 -> V_338 = V_101 . V_338 ;
V_40 -> V_44 = V_101 . V_44 ;
V_40 -> V_267 = V_101 . V_267 ;
V_40 -> V_336 = V_101 . V_336 ;
V_40 -> V_320 = V_101 . V_320 ;
F_73 ( & V_40 -> V_169 , 0 ) ;
F_95 ( & V_27 -> V_169 ) ;
F_95 ( & V_101 . V_337 -> V_169 ) ;
if ( V_101 . V_338 )
F_95 ( & V_101 . V_338 -> V_169 ) ;
if ( V_101 . V_44 )
F_95 ( & V_101 . V_44 -> V_169 ) ;
}
V_40 -> V_28 = & V_193 -> V_324 . V_28 ;
V_193 -> V_324 . V_28 . V_23 = V_40 ;
V_16 = F_14 ( & V_39 , & V_193 -> V_324 . V_28 ) ;
if ( V_16 )
goto V_353;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_270 . V_354 = V_40 -> V_295 ;
V_57 . V_270 . V_38 = V_193 -> V_324 . V_28 . V_20 ;
V_57 . V_270 . V_329 = V_101 . V_344 . V_329 ;
V_57 . V_270 . V_346 = V_101 . V_344 . V_346 ;
V_57 . V_270 . V_328 = V_101 . V_344 . V_328 ;
V_57 . V_270 . V_345 = V_101 . V_344 . V_345 ;
V_57 . V_270 . V_347 = V_101 . V_344 . V_347 ;
V_57 . V_271 = F_116 ( F_117 ( V_57 ) , V_271 ) +
sizeof( V_57 . V_271 ) ;
V_16 = F_113 ( V_49 , & V_57 , V_248 ) ;
if ( V_16 )
goto V_272;
if ( V_179 ) {
V_193 -> V_355 = F_7 ( V_316 , struct V_192 ,
V_28 ) ;
F_95 ( & V_193 -> V_355 -> V_208 ) ;
F_46 ( V_316 ) ;
}
if ( V_27 )
F_34 ( V_27 ) ;
if ( V_317 )
F_36 ( V_317 ) ;
if ( V_318 && V_318 != V_317 )
F_36 ( V_318 ) ;
if ( V_44 )
F_44 ( V_44 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_324 . V_28 . V_172 , & V_49 -> V_62 -> V_75 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_193 -> V_324 . V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_324 . V_28 . V_9 ) ;
return 0 ;
V_272:
F_20 ( & V_39 , & V_193 -> V_324 . V_28 ) ;
V_353:
F_137 ( V_40 ) ;
V_174:
if ( V_179 )
F_46 ( V_316 ) ;
if ( V_27 )
F_34 ( V_27 ) ;
if ( V_317 )
F_36 ( V_317 ) ;
if ( V_318 && V_318 != V_317 )
F_36 ( V_318 ) ;
if ( V_44 )
F_44 ( V_44 ) ;
F_12 ( & V_193 -> V_324 . V_28 ) ;
return V_16 ;
}
static int F_138 ( struct V_48 * V_49 ,
struct V_313 * V_57 ,
struct V_58 * V_248 )
{
if ( F_121 ( V_248 , & V_57 -> V_270 , sizeof( V_57 -> V_270 ) ) )
return - V_65 ;
return 0 ;
}
T_2 F_139 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_139 V_55 ;
struct V_312 V_273 ;
struct V_58 V_248 ;
struct V_58 V_249 ;
T_2 V_356 = sizeof( struct V_357 ) ;
int V_67 ;
if ( V_54 < V_356 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_65 ;
F_51 ( & V_248 , V_52 , ( unsigned long ) V_55 . V_68 , sizeof( V_55 ) ,
V_356 ) ;
F_51 ( & V_249 , V_52 + sizeof( V_55 ) ,
( unsigned long ) V_55 . V_68 + V_356 ,
V_53 - sizeof( V_55 ) , V_54 - V_356 ) ;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_3 = V_55 . V_3 ;
V_273 . V_25 = V_55 . V_25 ;
V_273 . V_334 = V_55 . V_334 ;
V_273 . V_333 = V_55 . V_333 ;
V_273 . V_42 = V_55 . V_42 ;
V_273 . V_345 = V_55 . V_345 ;
V_273 . V_328 = V_55 . V_328 ;
V_273 . V_346 = V_55 . V_346 ;
V_273 . V_329 = V_55 . V_329 ;
V_273 . V_347 = V_55 . V_347 ;
V_273 . V_340 = V_55 . V_340 ;
V_273 . V_320 = V_55 . V_320 ;
V_273 . V_330 = V_55 . V_330 ;
V_67 = F_133 ( V_49 , & V_248 , & V_249 , & V_273 ,
F_116 ( F_117 ( V_273 ) , V_330 ) +
sizeof( V_55 . V_330 ) , F_138 ,
NULL ) ;
if ( V_67 )
return V_67 ;
return V_53 ;
}
static int F_140 ( struct V_48 * V_49 ,
struct V_313 * V_57 ,
struct V_58 * V_248 )
{
if ( F_121 ( V_248 , V_57 , V_57 -> V_271 ) )
return - V_65 ;
return 0 ;
}
int V_312 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 )
{
struct V_313 V_57 ;
struct V_312 V_55 = { 0 } ;
int V_67 ;
if ( V_248 -> V_275 < ( F_116 ( F_117 ( V_55 ) , V_276 ) +
sizeof( V_55 . V_276 ) ) )
return - V_66 ;
V_67 = F_124 ( & V_55 , V_248 , F_125 ( sizeof( V_55 ) , V_248 -> V_275 ) ) ;
if ( V_67 )
return V_67 ;
if ( V_55 . V_276 )
return - V_66 ;
if ( V_55 . V_277 )
return - V_66 ;
if ( V_248 -> V_278 < ( F_116 ( F_117 ( V_57 ) , V_271 ) +
sizeof( V_57 . V_271 ) ) )
return - V_64 ;
V_67 = F_133 ( V_49 , V_248 , V_249 , & V_55 ,
F_125 ( V_248 -> V_275 , sizeof( V_55 ) ) ,
F_140 , NULL ) ;
if ( V_67 )
return V_67 ;
return 0 ;
}
T_2 F_141 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 , int V_54 )
{
struct F_141 V_55 ;
struct V_357 V_57 ;
struct V_58 V_59 ;
struct V_314 * V_193 ;
struct V_45 * V_179 ;
struct V_1 * V_315 ( V_316 ) ;
struct V_37 * V_40 ;
struct V_358 V_101 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_51 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_68 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_193 = F_72 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return - V_165 ;
F_1 ( & V_193 -> V_324 . V_28 , V_55 . V_3 , V_49 -> V_62 , & V_325 ) ;
F_31 ( & V_193 -> V_324 . V_28 . V_9 ) ;
V_179 = F_45 ( V_55 . V_25 , V_49 -> V_62 , & V_316 ) ;
if ( ! V_179 ) {
V_16 = - V_66 ;
goto V_174;
}
V_101 . V_267 = V_335 ;
V_101 . V_336 = V_49 ;
V_101 . V_295 = V_55 . V_354 ;
V_101 . V_320 = V_55 . V_320 ;
V_193 -> V_324 . V_348 = 0 ;
F_54 ( & V_193 -> V_324 . V_349 ) ;
F_54 ( & V_193 -> V_350 ) ;
V_40 = F_142 ( V_179 , & V_101 ) ;
if ( F_52 ( V_40 ) ) {
V_16 = F_53 ( V_40 ) ;
goto V_174;
}
V_40 -> V_28 = & V_193 -> V_324 . V_28 ;
V_193 -> V_324 . V_28 . V_23 = V_40 ;
V_16 = F_14 ( & V_39 , & V_193 -> V_324 . V_28 ) ;
if ( V_16 )
goto V_353;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_354 = V_40 -> V_295 ;
V_57 . V_38 = V_193 -> V_324 . V_28 . V_20 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_65 ;
goto V_359;
}
V_193 -> V_355 = F_7 ( V_316 , struct V_192 , V_28 ) ;
F_95 ( & V_193 -> V_355 -> V_208 ) ;
F_46 ( V_316 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_324 . V_28 . V_172 , & V_49 -> V_62 -> V_75 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_193 -> V_324 . V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_324 . V_28 . V_9 ) ;
return V_53 ;
V_359:
F_20 ( & V_39 , & V_193 -> V_324 . V_28 ) ;
V_353:
F_137 ( V_40 ) ;
V_174:
F_46 ( V_316 ) ;
F_12 ( & V_193 -> V_324 . V_28 ) ;
return V_16 ;
}
T_2 F_143 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_143 V_55 ;
struct V_360 V_57 ;
struct V_37 * V_40 ;
struct V_361 * V_101 ;
struct V_319 * V_362 ;
int V_16 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_101 = F_72 ( sizeof *V_101 , V_17 ) ;
V_362 = F_72 ( sizeof *V_362 , V_17 ) ;
if ( ! V_101 || ! V_362 ) {
V_16 = - V_165 ;
goto V_210;
}
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_62 ) ;
if ( ! V_40 ) {
V_16 = - V_66 ;
goto V_210;
}
V_16 = F_144 ( V_40 , V_101 , V_55 . V_363 , V_362 ) ;
F_41 ( V_40 ) ;
if ( V_16 )
goto V_210;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_364 = V_101 -> V_364 ;
V_57 . V_365 = V_101 -> V_365 ;
V_57 . V_366 = V_101 -> V_366 ;
V_57 . V_367 = V_101 -> V_367 ;
V_57 . V_368 = V_101 -> V_368 ;
V_57 . V_369 = V_101 -> V_369 ;
V_57 . V_370 = V_101 -> V_370 ;
V_57 . V_371 = V_101 -> V_371 ;
V_57 . V_372 = V_101 -> V_372 ;
V_57 . V_298 = V_101 -> V_298 ;
V_57 . V_373 = V_101 -> V_373 ;
V_57 . V_374 = V_101 -> V_374 ;
V_57 . V_375 = V_101 -> V_375 ;
V_57 . V_376 = V_101 -> V_376 ;
V_57 . V_377 = V_101 -> V_377 ;
V_57 . V_143 = V_101 -> V_143 ;
V_57 . V_378 = V_101 -> V_378 ;
V_57 . V_379 = V_101 -> V_379 ;
V_57 . V_380 = V_101 -> V_380 ;
V_57 . V_381 = V_101 -> V_381 ;
V_57 . V_382 = V_101 -> V_382 ;
memcpy ( V_57 . V_281 . V_383 , V_101 -> V_384 . V_385 . V_383 . V_386 , 16 ) ;
V_57 . V_281 . V_387 = V_101 -> V_384 . V_385 . V_387 ;
V_57 . V_281 . V_388 = V_101 -> V_384 . V_385 . V_388 ;
V_57 . V_281 . V_389 = V_101 -> V_384 . V_385 . V_389 ;
V_57 . V_281 . V_390 = V_101 -> V_384 . V_385 . V_390 ;
V_57 . V_281 . V_391 = V_101 -> V_384 . V_391 ;
V_57 . V_281 . V_300 = V_101 -> V_384 . V_300 ;
V_57 . V_281 . V_392 = V_101 -> V_384 . V_392 ;
V_57 . V_281 . V_393 = V_101 -> V_384 . V_393 ;
V_57 . V_281 . V_394 = ! ! ( V_101 -> V_384 . V_395 & V_396 ) ;
V_57 . V_281 . V_143 = V_101 -> V_384 . V_143 ;
memcpy ( V_57 . V_397 . V_383 , V_101 -> V_398 . V_385 . V_383 . V_386 , 16 ) ;
V_57 . V_397 . V_387 = V_101 -> V_398 . V_385 . V_387 ;
V_57 . V_397 . V_388 = V_101 -> V_398 . V_385 . V_388 ;
V_57 . V_397 . V_389 = V_101 -> V_398 . V_385 . V_389 ;
V_57 . V_397 . V_390 = V_101 -> V_398 . V_385 . V_390 ;
V_57 . V_397 . V_391 = V_101 -> V_398 . V_391 ;
V_57 . V_397 . V_300 = V_101 -> V_398 . V_300 ;
V_57 . V_397 . V_392 = V_101 -> V_398 . V_392 ;
V_57 . V_397 . V_393 = V_101 -> V_398 . V_393 ;
V_57 . V_397 . V_394 = ! ! ( V_101 -> V_398 . V_395 & V_396 ) ;
V_57 . V_397 . V_143 = V_101 -> V_398 . V_143 ;
V_57 . V_345 = V_362 -> V_344 . V_345 ;
V_57 . V_328 = V_362 -> V_344 . V_328 ;
V_57 . V_346 = V_362 -> V_344 . V_346 ;
V_57 . V_329 = V_362 -> V_344 . V_329 ;
V_57 . V_347 = V_362 -> V_344 . V_347 ;
V_57 . V_340 = V_362 -> V_339 == V_341 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_65 ;
V_210:
F_82 ( V_101 ) ;
F_82 ( V_362 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_145 ( enum V_399 V_320 , int V_400 )
{
switch ( V_320 ) {
case V_327 :
return V_400 & ~ ( V_401 | V_402 ) ;
case V_326 :
return V_400 & ~ ( V_403 | V_404 |
V_405 ) ;
default:
return V_400 ;
}
}
T_2 F_146 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_146 V_55 ;
struct V_58 V_59 ;
struct V_37 * V_40 ;
struct V_361 * V_101 ;
int V_16 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_51 ( & V_59 , V_52 + sizeof V_55 , NULL , V_53 - sizeof V_55 ,
V_54 ) ;
V_101 = F_72 ( sizeof *V_101 , V_17 ) ;
if ( ! V_101 )
return - V_165 ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_62 ) ;
if ( ! V_40 ) {
V_16 = - V_66 ;
goto V_210;
}
V_101 -> V_364 = V_55 . V_364 ;
V_101 -> V_365 = V_55 . V_365 ;
V_101 -> V_366 = V_55 . V_366 ;
V_101 -> V_367 = V_55 . V_367 ;
V_101 -> V_368 = V_55 . V_368 ;
V_101 -> V_369 = V_55 . V_369 ;
V_101 -> V_370 = V_55 . V_370 ;
V_101 -> V_371 = V_55 . V_371 ;
V_101 -> V_372 = V_55 . V_372 ;
V_101 -> V_298 = V_55 . V_298 ;
V_101 -> V_373 = V_55 . V_373 ;
V_101 -> V_406 = V_55 . V_406 ;
V_101 -> V_375 = V_55 . V_375 ;
V_101 -> V_376 = V_55 . V_376 ;
V_101 -> V_377 = V_55 . V_377 ;
V_101 -> V_143 = V_55 . V_143 ;
V_101 -> V_378 = V_55 . V_378 ;
V_101 -> V_379 = V_55 . V_379 ;
V_101 -> V_380 = V_55 . V_380 ;
V_101 -> V_381 = V_55 . V_381 ;
V_101 -> V_382 = V_55 . V_382 ;
memcpy ( V_101 -> V_384 . V_385 . V_383 . V_386 , V_55 . V_281 . V_383 , 16 ) ;
V_101 -> V_384 . V_385 . V_387 = V_55 . V_281 . V_387 ;
V_101 -> V_384 . V_385 . V_388 = V_55 . V_281 . V_388 ;
V_101 -> V_384 . V_385 . V_389 = V_55 . V_281 . V_389 ;
V_101 -> V_384 . V_385 . V_390 = V_55 . V_281 . V_390 ;
V_101 -> V_384 . V_391 = V_55 . V_281 . V_391 ;
V_101 -> V_384 . V_300 = V_55 . V_281 . V_300 ;
V_101 -> V_384 . V_392 = V_55 . V_281 . V_392 ;
V_101 -> V_384 . V_393 = V_55 . V_281 . V_393 ;
V_101 -> V_384 . V_395 = V_55 . V_281 . V_394 ? V_396 : 0 ;
V_101 -> V_384 . V_143 = V_55 . V_281 . V_143 ;
memcpy ( V_101 -> V_398 . V_385 . V_383 . V_386 , V_55 . V_397 . V_383 , 16 ) ;
V_101 -> V_398 . V_385 . V_387 = V_55 . V_397 . V_387 ;
V_101 -> V_398 . V_385 . V_388 = V_55 . V_397 . V_388 ;
V_101 -> V_398 . V_385 . V_389 = V_55 . V_397 . V_389 ;
V_101 -> V_398 . V_385 . V_390 = V_55 . V_397 . V_390 ;
V_101 -> V_398 . V_391 = V_55 . V_397 . V_391 ;
V_101 -> V_398 . V_300 = V_55 . V_397 . V_300 ;
V_101 -> V_398 . V_392 = V_55 . V_397 . V_392 ;
V_101 -> V_398 . V_393 = V_55 . V_397 . V_393 ;
V_101 -> V_398 . V_395 = V_55 . V_397 . V_394 ? V_396 : 0 ;
V_101 -> V_398 . V_143 = V_55 . V_397 . V_143 ;
if ( V_40 -> V_352 == V_40 ) {
V_16 = F_147 ( V_40 , V_101 , & V_55 . V_363 ) ;
if ( V_16 )
goto V_407;
V_16 = V_40 -> V_70 -> V_408 ( V_40 , V_101 ,
F_145 ( V_40 -> V_320 , V_55 . V_363 ) , & V_59 ) ;
} else {
V_16 = F_148 ( V_40 , V_101 , F_145 ( V_40 -> V_320 , V_55 . V_363 ) ) ;
}
if ( V_16 )
goto V_407;
V_16 = V_53 ;
V_407:
F_41 ( V_40 ) ;
V_210:
F_82 ( V_101 ) ;
return V_16 ;
}
T_2 F_149 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_149 V_55 ;
struct V_409 V_57 ;
struct V_1 * V_2 ;
struct V_37 * V_40 ;
struct V_314 * V_193 ;
int V_16 = - V_66 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_2 = F_30 ( & V_39 , V_55 . V_38 , V_49 -> V_62 ) ;
if ( ! V_2 )
return - V_66 ;
V_40 = V_2 -> V_23 ;
V_193 = F_7 ( V_2 , struct V_314 , V_324 . V_28 ) ;
if ( ! F_150 ( & V_193 -> V_350 ) ) {
F_12 ( V_2 ) ;
return - V_173 ;
}
V_16 = F_137 ( V_40 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_193 -> V_355 )
F_97 ( & V_193 -> V_355 -> V_208 ) ;
F_20 ( & V_39 , V_2 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_61 ( & V_49 -> V_9 ) ;
F_151 ( V_49 , & V_193 -> V_324 ) ;
V_57 . V_348 = V_193 -> V_324 . V_348 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
return - V_65 ;
return V_53 ;
}
static void * F_152 ( T_4 V_410 , V_293 V_411 )
{
return F_72 ( F_153 ( V_410 , sizeof ( struct V_412 ) ) +
V_411 * sizeof ( struct V_412 ) , V_17 ) ;
}
T_2 F_154 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_154 V_55 ;
struct V_413 V_57 ;
struct V_414 * V_415 ;
struct V_416 * V_417 = NULL , * V_418 , * V_419 , * V_420 ;
struct V_37 * V_40 ;
int V_421 , V_422 ;
int V_423 ;
T_2 V_16 = - V_66 ;
T_4 V_424 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
if ( V_53 < sizeof V_55 + V_55 . V_425 * V_55 . V_426 +
V_55 . V_427 * sizeof ( struct V_428 ) )
return - V_66 ;
if ( V_55 . V_425 < sizeof ( struct V_414 ) )
return - V_66 ;
V_415 = F_72 ( V_55 . V_425 , V_17 ) ;
if ( ! V_415 )
return - V_165 ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_62 ) ;
if ( ! V_40 )
goto V_210;
V_423 = V_40 -> V_320 == V_429 ;
V_422 = 0 ;
V_418 = NULL ;
for ( V_421 = 0 ; V_421 < V_55 . V_426 ; ++ V_421 ) {
if ( F_49 ( V_415 ,
V_52 + sizeof V_55 + V_421 * V_55 . V_425 ,
V_55 . V_425 ) ) {
V_16 = - V_65 ;
goto V_307;
}
if ( V_415 -> V_411 + V_422 > V_55 . V_427 ) {
V_16 = - V_66 ;
goto V_307;
}
if ( V_423 ) {
struct V_430 * V_431 ;
if ( V_415 -> V_288 != V_432 &&
V_415 -> V_288 != V_433 ) {
V_16 = - V_66 ;
goto V_307;
}
V_424 = sizeof( * V_431 ) ;
V_431 = F_152 ( V_424 , V_415 -> V_411 ) ;
if ( ! V_431 ) {
V_16 = - V_165 ;
goto V_307;
}
V_431 -> V_36 = F_37 ( V_415 -> V_417 . V_431 . V_36 , V_49 -> V_62 ) ;
if ( ! V_431 -> V_36 ) {
F_82 ( V_431 ) ;
V_16 = - V_66 ;
goto V_307;
}
V_431 -> V_434 = V_415 -> V_417 . V_431 . V_434 ;
V_431 -> V_435 = V_415 -> V_417 . V_431 . V_435 ;
V_419 = & V_431 -> V_417 ;
} else if ( V_415 -> V_288 == V_436 ||
V_415 -> V_288 == V_437 ||
V_415 -> V_288 == V_438 ) {
struct V_439 * V_440 ;
V_424 = sizeof( * V_440 ) ;
V_440 = F_152 ( V_424 , V_415 -> V_411 ) ;
if ( ! V_440 ) {
V_16 = - V_165 ;
goto V_307;
}
V_440 -> V_441 = V_415 -> V_417 . V_440 . V_441 ;
V_440 -> V_225 = V_415 -> V_417 . V_440 . V_225 ;
V_419 = & V_440 -> V_417 ;
} else if ( V_415 -> V_288 == V_442 ||
V_415 -> V_288 == V_443 ) {
struct V_444 * V_445 ;
V_424 = sizeof( * V_445 ) ;
V_445 = F_152 ( V_424 , V_415 -> V_411 ) ;
if ( ! V_445 ) {
V_16 = - V_165 ;
goto V_307;
}
V_445 -> V_441 = V_415 -> V_417 . V_445 . V_441 ;
V_445 -> V_446 = V_415 -> V_417 . V_445 . V_446 ;
V_445 -> V_447 = V_415 -> V_417 . V_445 . V_447 ;
V_445 -> V_225 = V_415 -> V_417 . V_445 . V_225 ;
V_419 = & V_445 -> V_417 ;
} else if ( V_415 -> V_288 == V_432 ||
V_415 -> V_288 == V_433 ||
V_415 -> V_288 == V_448 ) {
V_424 = sizeof( * V_419 ) ;
V_419 = F_152 ( V_424 , V_415 -> V_411 ) ;
if ( ! V_419 ) {
V_16 = - V_165 ;
goto V_307;
}
} else {
V_16 = - V_66 ;
goto V_307;
}
if ( V_415 -> V_288 == V_433 ||
V_415 -> V_288 == V_436 ) {
V_419 -> V_291 . V_292 =
( V_449 V_294 ) V_415 -> V_291 . V_292 ;
} else if ( V_415 -> V_288 == V_448 ) {
V_419 -> V_291 . V_450 = V_415 -> V_291 . V_450 ;
}
if ( ! V_418 )
V_417 = V_419 ;
else
V_418 -> V_419 = V_419 ;
V_418 = V_419 ;
V_419 -> V_419 = NULL ;
V_419 -> V_286 = V_415 -> V_286 ;
V_419 -> V_411 = V_415 -> V_411 ;
V_419 -> V_288 = V_415 -> V_288 ;
V_419 -> V_451 = V_415 -> V_451 ;
if ( V_419 -> V_411 ) {
V_419 -> V_452 = ( void * ) V_419 +
F_153 ( V_424 , sizeof( struct V_412 ) ) ;
if ( F_49 ( V_419 -> V_452 ,
V_52 + sizeof V_55 +
V_55 . V_426 * V_55 . V_425 +
V_422 * sizeof ( struct V_412 ) ,
V_419 -> V_411 * sizeof ( struct V_412 ) ) ) {
V_16 = - V_65 ;
goto V_307;
}
V_422 += V_419 -> V_411 ;
} else
V_419 -> V_452 = NULL ;
}
V_57 . V_420 = 0 ;
V_16 = V_40 -> V_70 -> V_453 ( V_40 -> V_352 , V_417 , & V_420 ) ;
if ( V_16 )
for ( V_419 = V_417 ; V_419 ; V_419 = V_419 -> V_419 ) {
++ V_57 . V_420 ;
if ( V_419 == V_420 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_65 ;
V_307:
F_41 ( V_40 ) ;
while ( V_417 ) {
if ( V_423 && F_155 ( V_417 ) -> V_36 )
F_38 ( F_155 ( V_417 ) -> V_36 ) ;
V_419 = V_417 -> V_419 ;
F_82 ( V_417 ) ;
V_417 = V_419 ;
}
V_210:
F_82 ( V_415 ) ;
return V_16 ? V_16 : V_53 ;
}
static struct V_454 * F_156 ( const char T_3 * V_52 ,
int V_53 ,
T_6 V_426 ,
T_6 V_427 ,
T_6 V_425 )
{
struct V_455 * V_415 ;
struct V_454 * V_417 = NULL , * V_418 , * V_419 ;
int V_422 ;
int V_421 ;
int V_16 ;
if ( V_53 < V_425 * V_426 +
V_427 * sizeof ( struct V_428 ) )
return F_114 ( - V_66 ) ;
if ( V_425 < sizeof ( struct V_455 ) )
return F_114 ( - V_66 ) ;
V_415 = F_72 ( V_425 , V_17 ) ;
if ( ! V_415 )
return F_114 ( - V_165 ) ;
V_422 = 0 ;
V_418 = NULL ;
for ( V_421 = 0 ; V_421 < V_426 ; ++ V_421 ) {
if ( F_49 ( V_415 , V_52 + V_421 * V_425 ,
V_425 ) ) {
V_16 = - V_65 ;
goto V_67;
}
if ( V_415 -> V_411 + V_422 > V_427 ) {
V_16 = - V_66 ;
goto V_67;
}
V_419 = F_72 ( F_153 ( sizeof *V_419 , sizeof ( struct V_412 ) ) +
V_415 -> V_411 * sizeof ( struct V_412 ) ,
V_17 ) ;
if ( ! V_419 ) {
V_16 = - V_165 ;
goto V_67;
}
if ( ! V_418 )
V_417 = V_419 ;
else
V_418 -> V_419 = V_419 ;
V_418 = V_419 ;
V_419 -> V_419 = NULL ;
V_419 -> V_286 = V_415 -> V_286 ;
V_419 -> V_411 = V_415 -> V_411 ;
if ( V_419 -> V_411 ) {
V_419 -> V_452 = ( void * ) V_419 +
F_153 ( sizeof *V_419 , sizeof ( struct V_412 ) ) ;
if ( F_49 ( V_419 -> V_452 ,
V_52 + V_426 * V_425 +
V_422 * sizeof ( struct V_412 ) ,
V_419 -> V_411 * sizeof ( struct V_412 ) ) ) {
V_16 = - V_65 ;
goto V_67;
}
V_422 += V_419 -> V_411 ;
} else
V_419 -> V_452 = NULL ;
}
F_82 ( V_415 ) ;
return V_417 ;
V_67:
F_82 ( V_415 ) ;
while ( V_417 ) {
V_419 = V_417 -> V_419 ;
F_82 ( V_417 ) ;
V_417 = V_419 ;
}
return F_114 ( V_16 ) ;
}
T_2 F_157 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_157 V_55 ;
struct V_456 V_57 ;
struct V_454 * V_417 , * V_419 , * V_420 ;
struct V_37 * V_40 ;
T_2 V_16 = - V_66 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_417 = F_156 ( V_52 + sizeof V_55 ,
V_53 - sizeof V_55 , V_55 . V_426 ,
V_55 . V_427 , V_55 . V_425 ) ;
if ( F_52 ( V_417 ) )
return F_53 ( V_417 ) ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_62 ) ;
if ( ! V_40 )
goto V_210;
V_57 . V_420 = 0 ;
V_16 = V_40 -> V_70 -> V_457 ( V_40 -> V_352 , V_417 , & V_420 ) ;
F_41 ( V_40 ) ;
if ( V_16 )
for ( V_419 = V_417 ; V_419 ; V_419 = V_419 -> V_419 ) {
++ V_57 . V_420 ;
if ( V_419 == V_420 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_65 ;
V_210:
while ( V_417 ) {
V_419 = V_417 -> V_419 ;
F_82 ( V_417 ) ;
V_417 = V_419 ;
}
return V_16 ? V_16 : V_53 ;
}
T_2 F_158 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_158 V_55 ;
struct V_458 V_57 ;
struct V_454 * V_417 , * V_419 , * V_420 ;
struct V_41 * V_44 ;
T_2 V_16 = - V_66 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_417 = F_156 ( V_52 + sizeof V_55 ,
V_53 - sizeof V_55 , V_55 . V_426 ,
V_55 . V_427 , V_55 . V_425 ) ;
if ( F_52 ( V_417 ) )
return F_53 ( V_417 ) ;
V_44 = F_43 ( V_55 . V_42 , V_49 -> V_62 ) ;
if ( ! V_44 )
goto V_210;
V_57 . V_420 = 0 ;
V_16 = V_44 -> V_70 -> V_459 ( V_44 , V_417 , & V_420 ) ;
F_44 ( V_44 ) ;
if ( V_16 )
for ( V_419 = V_417 ; V_419 ; V_419 = V_419 -> V_419 ) {
++ V_57 . V_420 ;
if ( V_419 == V_420 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_65 ;
V_210:
while ( V_417 ) {
V_419 = V_417 -> V_419 ;
F_82 ( V_417 ) ;
V_417 = V_419 ;
}
return V_16 ? V_16 : V_53 ;
}
T_2 F_159 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_159 V_55 ;
struct V_460 V_57 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_33 * V_36 ;
struct V_461 V_101 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_2 = F_72 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , V_55 . V_3 , V_49 -> V_62 , & V_462 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_62 ) ;
if ( ! V_27 ) {
V_16 = - V_66 ;
goto V_67;
}
V_101 . V_391 = V_55 . V_101 . V_391 ;
V_101 . V_300 = V_55 . V_101 . V_300 ;
V_101 . V_392 = V_55 . V_101 . V_392 ;
V_101 . V_393 = V_55 . V_101 . V_393 ;
V_101 . V_395 = V_55 . V_101 . V_394 ? V_396 : 0 ;
V_101 . V_143 = V_55 . V_101 . V_143 ;
V_101 . V_385 . V_387 = V_55 . V_101 . V_385 . V_387 ;
V_101 . V_385 . V_388 = V_55 . V_101 . V_385 . V_388 ;
V_101 . V_385 . V_389 = V_55 . V_101 . V_385 . V_389 ;
V_101 . V_385 . V_390 = V_55 . V_101 . V_385 . V_390 ;
memset ( & V_101 . V_463 , 0 , sizeof( V_101 . V_463 ) ) ;
memcpy ( V_101 . V_385 . V_383 . V_386 , V_55 . V_101 . V_385 . V_383 , 16 ) ;
V_36 = F_160 ( V_27 , & V_101 ) ;
if ( F_52 ( V_36 ) ) {
V_16 = F_53 ( V_36 ) ;
goto V_174;
}
V_36 -> V_28 = V_2 ;
V_2 -> V_23 = V_36 ;
V_16 = F_14 ( & V_35 , V_2 ) ;
if ( V_16 )
goto V_353;
V_57 . V_34 = V_2 -> V_20 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_65 ;
goto V_171;
}
F_34 ( V_27 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_62 -> V_77 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_35 , V_2 ) ;
V_353:
F_161 ( V_36 ) ;
V_174:
F_34 ( V_27 ) ;
V_67:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_162 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 , int V_54 )
{
struct F_162 V_55 ;
struct V_33 * V_36 ;
struct V_1 * V_2 ;
int V_16 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_2 = F_30 ( & V_35 , V_55 . V_34 , V_49 -> V_62 ) ;
if ( ! V_2 )
return - V_66 ;
V_36 = V_2 -> V_23 ;
V_16 = F_161 ( V_36 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_35 , V_2 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_61 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_53 ;
}
T_2 F_163 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_163 V_55 ;
struct V_37 * V_40 ;
struct V_314 * V_193 ;
struct V_464 * V_465 ;
int V_16 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_40 = F_40 ( V_55 . V_38 , V_49 -> V_62 ) ;
if ( ! V_40 )
return - V_66 ;
V_193 = F_7 ( V_40 -> V_28 , struct V_314 , V_324 . V_28 ) ;
F_164 (mcast, &obj->mcast_list, list)
if ( V_55 . V_466 == V_465 -> V_153 &&
! memcmp ( V_55 . V_467 , V_465 -> V_467 . V_386 , sizeof V_465 -> V_467 . V_386 ) ) {
V_16 = 0 ;
goto V_307;
}
V_465 = F_72 ( sizeof *V_465 , V_17 ) ;
if ( ! V_465 ) {
V_16 = - V_165 ;
goto V_307;
}
V_465 -> V_153 = V_55 . V_466 ;
memcpy ( V_465 -> V_467 . V_386 , V_55 . V_467 , sizeof V_465 -> V_467 . V_386 ) ;
V_16 = F_165 ( V_40 , & V_465 -> V_467 , V_55 . V_466 ) ;
if ( ! V_16 )
F_74 ( & V_465 -> V_172 , & V_193 -> V_350 ) ;
else
F_82 ( V_465 ) ;
V_307:
F_42 ( V_40 ) ;
return V_16 ? V_16 : V_53 ;
}
T_2 F_166 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_166 V_55 ;
struct V_314 * V_193 ;
struct V_37 * V_40 ;
struct V_464 * V_465 ;
int V_16 = - V_66 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_40 = F_40 ( V_55 . V_38 , V_49 -> V_62 ) ;
if ( ! V_40 )
return - V_66 ;
V_16 = F_167 ( V_40 , (union V_468 * ) V_55 . V_467 , V_55 . V_466 ) ;
if ( V_16 )
goto V_307;
V_193 = F_7 ( V_40 -> V_28 , struct V_314 , V_324 . V_28 ) ;
F_164 (mcast, &obj->mcast_list, list)
if ( V_55 . V_466 == V_465 -> V_153 &&
! memcmp ( V_55 . V_467 , V_465 -> V_467 . V_386 , sizeof V_465 -> V_467 . V_386 ) ) {
F_79 ( & V_465 -> V_172 ) ;
F_82 ( V_465 ) ;
break;
}
V_307:
F_42 ( V_40 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_168 ( struct V_469 * V_470 ,
union V_471 * V_472 )
{
if ( V_470 -> V_277 )
return - V_66 ;
V_472 -> type = V_470 -> type ;
switch ( V_472 -> type ) {
case V_473 :
V_472 -> V_474 . V_475 = sizeof( struct V_476 ) ;
if ( V_472 -> V_474 . V_475 != V_470 -> V_474 . V_475 )
return - V_66 ;
memcpy ( & V_472 -> V_474 . V_477 , & V_470 -> V_474 . V_477 ,
sizeof( struct V_478 ) ) ;
memcpy ( & V_472 -> V_474 . V_400 , & V_470 -> V_474 . V_400 ,
sizeof( struct V_478 ) ) ;
break;
case V_479 :
V_472 -> V_480 . V_475 = sizeof( struct V_481 ) ;
if ( V_472 -> V_480 . V_475 != V_470 -> V_480 . V_475 )
return - V_66 ;
memcpy ( & V_472 -> V_480 . V_477 , & V_470 -> V_480 . V_477 ,
sizeof( struct V_482 ) ) ;
memcpy ( & V_472 -> V_480 . V_400 , & V_470 -> V_480 . V_400 ,
sizeof( struct V_482 ) ) ;
break;
case V_483 :
case V_484 :
V_472 -> V_485 . V_475 = sizeof( struct V_486 ) ;
if ( V_472 -> V_485 . V_475 != V_470 -> V_485 . V_475 )
return - V_66 ;
memcpy ( & V_472 -> V_485 . V_477 , & V_470 -> V_485 . V_477 ,
sizeof( struct V_487 ) ) ;
memcpy ( & V_472 -> V_485 . V_400 , & V_470 -> V_485 . V_400 ,
sizeof( struct V_487 ) ) ;
break;
default:
return - V_66 ;
}
return 0 ;
}
int F_169 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 )
{
struct V_488 V_55 ;
struct V_489 V_57 ;
struct V_1 * V_2 ;
struct V_490 * V_491 ;
struct V_492 * V_493 ;
struct V_494 * V_495 ;
struct V_37 * V_40 ;
int V_67 = 0 ;
void * V_470 ;
void * V_472 ;
int V_421 ;
if ( V_248 -> V_275 < sizeof( V_55 ) )
return - V_66 ;
if ( V_248 -> V_278 < sizeof( V_57 ) )
return - V_64 ;
V_67 = F_124 ( & V_55 , V_248 , sizeof( V_55 ) ) ;
if ( V_67 )
return V_67 ;
V_248 -> V_496 += sizeof( V_55 ) ;
V_248 -> V_275 -= sizeof( V_55 ) ;
if ( V_55 . V_276 )
return - V_66 ;
if ( ( V_55 . V_495 . type == V_497 &&
! F_134 ( V_498 ) ) || ! F_134 ( V_322 ) )
return - V_323 ;
if ( V_55 . V_495 . V_499 > V_500 )
return - V_66 ;
if ( V_55 . V_495 . V_475 > V_248 -> V_275 ||
V_55 . V_495 . V_475 >
( V_55 . V_495 . V_499 * sizeof( struct V_469 ) ) )
return - V_66 ;
if ( V_55 . V_495 . V_277 [ 0 ] ||
V_55 . V_495 . V_277 [ 1 ] )
return - V_66 ;
if ( V_55 . V_495 . V_499 ) {
V_493 = F_72 ( sizeof( * V_493 ) + V_55 . V_495 . V_475 ,
V_17 ) ;
if ( ! V_493 )
return - V_165 ;
memcpy ( V_493 , & V_55 . V_495 , sizeof( * V_493 ) ) ;
V_67 = F_124 ( V_493 + 1 , V_248 ,
V_55 . V_495 . V_475 ) ;
if ( V_67 )
goto V_501;
} else {
V_493 = & V_55 . V_495 ;
}
V_2 = F_72 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 ) {
V_67 = - V_165 ;
goto V_501;
}
F_1 ( V_2 , 0 , V_49 -> V_62 , & V_502 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_62 ) ;
if ( ! V_40 ) {
V_67 = - V_66 ;
goto V_503;
}
V_495 = F_72 ( sizeof( * V_495 ) + V_55 . V_495 . V_475 , V_17 ) ;
if ( ! V_495 ) {
V_67 = - V_165 ;
goto V_174;
}
V_495 -> type = V_493 -> type ;
V_495 -> V_504 = V_493 -> V_504 ;
V_495 -> V_499 = V_493 -> V_499 ;
V_495 -> V_505 = V_493 -> V_505 ;
V_495 -> V_229 = V_493 -> V_229 ;
V_495 -> V_475 = sizeof( * V_495 ) ;
V_470 = V_493 + 1 ;
V_472 = V_495 + 1 ;
for ( V_421 = 0 ; V_421 < V_495 -> V_499 &&
V_55 . V_495 . V_475 > F_116 ( struct V_469 , V_277 ) &&
V_55 . V_495 . V_475 >=
( (struct V_469 * ) V_470 ) -> V_475 ; V_421 ++ ) {
V_67 = F_168 ( V_470 , V_472 ) ;
if ( V_67 )
goto V_90;
V_495 -> V_475 +=
( (union V_471 * ) V_472 ) -> V_475 ;
V_55 . V_495 . V_475 -= ( (struct V_469 * ) V_470 ) -> V_475 ;
V_470 += ( (struct V_469 * ) V_470 ) -> V_475 ;
V_472 += ( (union V_471 * ) V_472 ) -> V_475 ;
}
if ( V_55 . V_495 . V_475 || ( V_421 != V_495 -> V_499 ) ) {
F_170 ( L_3 ,
V_421 , V_55 . V_495 . V_475 ) ;
V_67 = - V_66 ;
goto V_90;
}
V_491 = F_171 ( V_40 , V_495 , V_506 ) ;
if ( F_52 ( V_491 ) ) {
V_67 = F_53 ( V_491 ) ;
goto V_90;
}
V_491 -> V_40 = V_40 ;
V_491 -> V_28 = V_2 ;
V_2 -> V_23 = V_491 ;
V_67 = F_14 ( & V_507 , V_2 ) ;
if ( V_67 )
goto V_508;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_509 = V_2 -> V_20 ;
V_67 = F_121 ( V_248 ,
& V_57 , sizeof( V_57 ) ) ;
if ( V_67 )
goto V_171;
F_41 ( V_40 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_62 -> V_79 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_82 ( V_495 ) ;
if ( V_55 . V_495 . V_499 )
F_82 ( V_493 ) ;
return 0 ;
V_171:
F_20 ( & V_507 , V_2 ) ;
V_508:
F_172 ( V_491 ) ;
V_90:
F_82 ( V_495 ) ;
V_174:
F_41 ( V_40 ) ;
V_503:
F_12 ( V_2 ) ;
V_501:
if ( V_55 . V_495 . V_499 )
F_82 ( V_493 ) ;
return V_67 ;
}
int F_173 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 )
{
struct V_510 V_55 ;
struct V_490 * V_491 ;
struct V_1 * V_2 ;
int V_16 ;
if ( V_248 -> V_275 < sizeof( V_55 ) )
return - V_66 ;
V_16 = F_124 ( & V_55 , V_248 , sizeof( V_55 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_55 . V_276 )
return - V_66 ;
V_2 = F_30 ( & V_507 , V_55 . V_509 ,
V_49 -> V_62 ) ;
if ( ! V_2 )
return - V_66 ;
V_491 = V_2 -> V_23 ;
V_16 = F_172 ( V_491 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_507 , V_2 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_61 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_16 ;
}
static int F_174 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_511 * V_55 ,
struct V_58 * V_59 )
{
struct V_512 V_57 ;
struct V_513 * V_193 ;
struct V_24 * V_27 ;
struct V_41 * V_44 ;
struct V_1 * V_315 ( V_316 ) ;
struct V_514 V_101 ;
int V_16 ;
V_193 = F_72 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return - V_165 ;
F_1 ( & V_193 -> V_324 . V_28 , V_55 -> V_3 , V_49 -> V_62 , & V_515 ) ;
F_31 ( & V_193 -> V_324 . V_28 . V_9 ) ;
if ( V_55 -> V_331 == V_516 ) {
V_101 . V_517 . V_518 . V_179 = F_45 ( V_55 -> V_46 , V_49 -> V_62 , & V_316 ) ;
if ( ! V_101 . V_517 . V_518 . V_179 ) {
V_16 = - V_66 ;
goto V_67;
}
V_193 -> V_355 = F_7 ( V_316 , struct V_192 , V_28 ) ;
F_95 ( & V_193 -> V_355 -> V_208 ) ;
V_101 . V_517 . V_518 . V_32 = F_35 ( V_55 -> V_30 , V_49 -> V_62 , 0 ) ;
if ( ! V_101 . V_517 . V_518 . V_32 ) {
V_16 = - V_66 ;
goto V_519;
}
}
V_27 = F_33 ( V_55 -> V_25 , V_49 -> V_62 ) ;
if ( ! V_27 ) {
V_16 = - V_66 ;
goto V_520;
}
V_101 . V_267 = V_521 ;
V_101 . V_522 = V_49 ;
V_101 . V_331 = V_55 -> V_331 ;
V_101 . V_101 . V_523 = V_55 -> V_523 ;
V_101 . V_101 . V_112 = V_55 -> V_112 ;
V_101 . V_101 . V_524 = V_55 -> V_524 ;
V_193 -> V_324 . V_348 = 0 ;
F_54 ( & V_193 -> V_324 . V_349 ) ;
V_44 = V_27 -> V_70 -> V_525 ( V_27 , & V_101 , V_59 ) ;
if ( F_52 ( V_44 ) ) {
V_16 = F_53 ( V_44 ) ;
goto V_174;
}
V_44 -> V_70 = V_27 -> V_70 ;
V_44 -> V_27 = V_27 ;
V_44 -> V_331 = V_55 -> V_331 ;
V_44 -> V_28 = & V_193 -> V_324 . V_28 ;
V_44 -> V_267 = V_101 . V_267 ;
V_44 -> V_522 = V_101 . V_522 ;
if ( V_55 -> V_331 == V_516 ) {
V_44 -> V_517 . V_518 . V_32 = V_101 . V_517 . V_518 . V_32 ;
V_44 -> V_517 . V_518 . V_179 = V_101 . V_517 . V_518 . V_179 ;
F_95 ( & V_101 . V_517 . V_518 . V_32 -> V_169 ) ;
F_95 ( & V_101 . V_517 . V_518 . V_179 -> V_169 ) ;
}
F_95 ( & V_27 -> V_169 ) ;
F_73 ( & V_44 -> V_169 , 0 ) ;
V_193 -> V_324 . V_28 . V_23 = V_44 ;
V_16 = F_14 ( & V_43 , & V_193 -> V_324 . V_28 ) ;
if ( V_16 )
goto V_353;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_42 = V_193 -> V_324 . V_28 . V_20 ;
V_57 . V_523 = V_101 . V_101 . V_523 ;
V_57 . V_112 = V_101 . V_101 . V_112 ;
if ( V_55 -> V_331 == V_516 )
V_57 . V_526 = V_44 -> V_517 . V_518 . V_527 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 -> V_68 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_65 ;
goto V_171;
}
if ( V_55 -> V_331 == V_516 ) {
F_10 ( V_316 ) ;
F_36 ( V_101 . V_517 . V_518 . V_32 ) ;
}
F_34 ( V_27 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_324 . V_28 . V_172 , & V_49 -> V_62 -> V_76 ) ;
F_61 ( & V_49 -> V_9 ) ;
V_193 -> V_324 . V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_324 . V_28 . V_9 ) ;
return 0 ;
V_171:
F_20 ( & V_43 , & V_193 -> V_324 . V_28 ) ;
V_353:
F_175 ( V_44 ) ;
V_174:
F_34 ( V_27 ) ;
V_520:
if ( V_55 -> V_331 == V_516 )
F_36 ( V_101 . V_517 . V_518 . V_32 ) ;
V_519:
if ( V_55 -> V_331 == V_516 ) {
F_97 ( & V_193 -> V_355 -> V_208 ) ;
F_10 ( V_316 ) ;
}
V_67:
F_12 ( & V_193 -> V_324 . V_28 ) ;
return V_16 ;
}
T_2 F_176 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_176 V_55 ;
struct V_511 V_528 ;
struct V_512 V_57 ;
struct V_58 V_59 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_528 . V_68 = V_55 . V_68 ;
V_528 . V_3 = V_55 . V_3 ;
V_528 . V_331 = V_332 ;
V_528 . V_25 = V_55 . V_25 ;
V_528 . V_523 = V_55 . V_523 ;
V_528 . V_112 = V_55 . V_112 ;
V_528 . V_524 = V_55 . V_524 ;
F_51 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_68 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_16 = F_174 ( V_49 , V_51 , & V_528 , & V_59 ) ;
if ( V_16 )
return V_16 ;
return V_53 ;
}
T_2 V_511 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 , int V_54 )
{
struct V_511 V_55 ;
struct V_512 V_57 ;
struct V_58 V_59 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_51 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_68 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_16 = F_174 ( V_49 , V_51 , & V_55 , & V_59 ) ;
if ( V_16 )
return V_16 ;
return V_53 ;
}
T_2 F_177 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_177 V_55 ;
struct V_58 V_59 ;
struct V_41 * V_44 ;
struct V_529 V_101 ;
int V_16 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
F_51 ( & V_59 , V_52 + sizeof V_55 , NULL , V_53 - sizeof V_55 ,
V_54 ) ;
V_44 = F_43 ( V_55 . V_42 , V_49 -> V_62 ) ;
if ( ! V_44 )
return - V_66 ;
V_101 . V_523 = V_55 . V_523 ;
V_101 . V_524 = V_55 . V_524 ;
V_16 = V_44 -> V_70 -> V_530 ( V_44 , & V_101 , V_55 . V_363 , & V_59 ) ;
F_44 ( V_44 ) ;
return V_16 ? V_16 : V_53 ;
}
T_2 F_178 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_178 V_55 ;
struct V_531 V_57 ;
struct V_529 V_101 ;
struct V_41 * V_44 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_64 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_44 = F_43 ( V_55 . V_42 , V_49 -> V_62 ) ;
if ( ! V_44 )
return - V_66 ;
V_16 = F_179 ( V_44 , & V_101 ) ;
F_44 ( V_44 ) ;
if ( V_16 )
return V_16 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_523 = V_101 . V_523 ;
V_57 . V_112 = V_101 . V_112 ;
V_57 . V_524 = V_101 . V_524 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
return - V_65 ;
return V_53 ;
}
T_2 F_180 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_180 V_55 ;
struct V_532 V_57 ;
struct V_1 * V_2 ;
struct V_41 * V_44 ;
struct V_533 * V_193 ;
int V_16 = - V_66 ;
struct V_513 * V_534 ;
enum V_535 V_331 ;
if ( F_49 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_65 ;
V_2 = F_30 ( & V_43 , V_55 . V_42 , V_49 -> V_62 ) ;
if ( ! V_2 )
return - V_66 ;
V_44 = V_2 -> V_23 ;
V_193 = F_7 ( V_2 , struct V_533 , V_28 ) ;
V_331 = V_44 -> V_331 ;
V_16 = F_175 ( V_44 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_331 == V_516 ) {
V_534 = F_7 ( V_193 , struct V_513 , V_324 ) ;
F_97 ( & V_534 -> V_355 -> V_208 ) ;
}
F_20 ( & V_43 , V_2 ) ;
F_50 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_61 ( & V_49 -> V_9 ) ;
F_151 ( V_49 , V_193 ) ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_348 = V_193 -> V_348 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_55 . V_68 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_65 ;
return V_16 ? V_16 : V_53 ;
}
int F_181 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 )
{
struct V_536 V_57 ;
struct F_181 V_55 ;
struct V_60 V_101 ;
int V_67 ;
if ( V_248 -> V_275 < sizeof( V_55 ) )
return - V_66 ;
V_67 = F_124 ( & V_55 , V_248 , sizeof( V_55 ) ) ;
if ( V_67 )
return V_67 ;
if ( V_55 . V_276 )
return - V_66 ;
if ( V_55 . V_277 )
return - V_66 ;
V_57 . V_271 = F_116 ( F_117 ( V_57 ) , V_537 ) ;
if ( V_248 -> V_278 < V_57 . V_271 )
return - V_64 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_67 = V_51 -> V_538 ( V_51 , & V_101 , V_249 ) ;
if ( V_67 )
return V_67 ;
F_66 ( V_49 , V_51 , & V_57 . V_270 , & V_101 ) ;
V_57 . V_276 = 0 ;
if ( V_248 -> V_278 < V_57 . V_271 + sizeof( V_57 . V_537 ) )
goto V_539;
#ifdef F_48
V_57 . V_537 . V_540 = V_101 . V_537 . V_540 ;
V_57 . V_537 . V_541 . V_542 =
V_101 . V_537 . V_541 . V_542 ;
V_57 . V_537 . V_541 . V_543 =
V_101 . V_537 . V_541 . V_543 ;
V_57 . V_537 . V_541 . V_544 =
V_101 . V_537 . V_541 . V_544 ;
V_57 . V_537 . V_277 = 0 ;
#else
memset ( & V_57 . V_537 , 0 , sizeof( V_57 . V_537 ) ) ;
#endif
V_57 . V_271 += sizeof( V_57 . V_537 ) ;
if ( V_248 -> V_278 < V_57 . V_271 + sizeof( V_57 . V_545 ) )
goto V_539;
V_57 . V_545 = V_101 . V_545 ;
V_57 . V_271 += sizeof( V_57 . V_545 ) ;
if ( V_248 -> V_278 < V_57 . V_271 + sizeof( V_57 . V_546 ) )
goto V_539;
V_57 . V_546 = V_101 . V_546 ;
V_57 . V_271 += sizeof( V_57 . V_546 ) ;
V_539:
V_67 = F_121 ( V_248 , & V_57 , V_57 . V_271 ) ;
if ( V_67 )
return V_67 ;
return 0 ;
}
