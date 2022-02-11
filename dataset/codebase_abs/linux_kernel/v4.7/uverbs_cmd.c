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
struct V_4 * V_60 ;
struct V_49 * V_61 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_49 ( & V_49 -> V_9 ) ;
if ( V_49 -> V_60 ) {
V_16 = - V_64 ;
goto V_65;
}
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_60 = V_51 -> V_67 ( V_51 , & V_59 ) ;
if ( F_51 ( V_60 ) ) {
V_16 = F_52 ( V_60 ) ;
goto V_65;
}
V_60 -> V_68 = V_51 ;
F_53 ( & V_60 -> V_69 ) ;
F_53 ( & V_60 -> V_70 ) ;
F_53 ( & V_60 -> V_71 ) ;
F_53 ( & V_60 -> V_72 ) ;
F_53 ( & V_60 -> V_73 ) ;
F_53 ( & V_60 -> V_74 ) ;
F_53 ( & V_60 -> V_75 ) ;
F_53 ( & V_60 -> V_76 ) ;
F_53 ( & V_60 -> V_77 ) ;
F_23 () ;
V_60 -> V_78 = F_54 ( V_79 -> V_80 , V_81 ) ;
F_26 () ;
V_60 -> V_82 = 0 ;
#ifdef F_55
V_60 -> V_83 = V_84 ;
F_3 ( & V_60 -> V_85 ) ;
V_60 -> V_86 = 0 ;
F_53 ( & V_60 -> V_87 ) ;
if ( ! ( V_51 -> V_88 . V_89 & V_90 ) )
V_60 -> V_91 = NULL ;
#endif
V_57 . V_92 = V_49 -> V_68 -> V_92 ;
V_16 = F_56 ( V_93 ) ;
if ( V_16 < 0 )
goto V_94;
V_57 . V_95 = V_16 ;
V_61 = F_57 ( V_49 , V_51 , 1 ) ;
if ( F_51 ( V_61 ) ) {
V_16 = F_52 ( V_61 ) ;
goto V_96;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_97;
}
V_49 -> V_60 = V_60 ;
F_59 ( V_57 . V_95 , V_61 ) ;
F_60 ( & V_49 -> V_9 ) ;
return V_53 ;
V_97:
F_61 ( V_49 ) ;
F_62 ( V_61 ) ;
V_96:
F_63 ( V_57 . V_95 ) ;
V_94:
F_64 ( V_60 -> V_78 ) ;
V_51 -> V_98 ( V_60 ) ;
V_65:
F_60 ( & V_49 -> V_9 ) ;
return V_16 ;
}
static void F_65 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_99 * V_57 ,
struct V_100 * V_101 )
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
V_57 -> V_89 = F_66 ( V_101 -> V_89 ) ;
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
struct V_99 V_57 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
F_65 ( V_49 , V_51 , & V_57 , & V_51 -> V_88 ) ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
return - V_63 ;
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
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
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
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
return - V_63 ;
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
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_2 = F_72 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , 0 , V_49 -> V_60 , & V_166 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = V_51 -> V_167 ( V_51 , V_49 -> V_60 , & V_59 ) ;
if ( F_51 ( V_27 ) ) {
V_16 = F_52 ( V_27 ) ;
goto V_65;
}
V_27 -> V_68 = V_51 ;
V_27 -> V_28 = V_2 ;
V_27 -> V_168 = NULL ;
F_73 ( & V_27 -> V_169 , 0 ) ;
V_2 -> V_23 = V_27 ;
V_16 = F_14 ( & V_26 , V_2 ) ;
if ( V_16 )
goto V_170;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_25 = V_2 -> V_20 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_171;
}
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_69 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_26 , V_2 ) ;
V_170:
F_75 ( V_27 ) ;
V_65:
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
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_26 , V_55 . V_25 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_27 = V_2 -> V_23 ;
if ( F_77 ( & V_27 -> V_169 ) ) {
V_16 = - V_173 ;
goto V_174;
}
V_16 = V_27 -> V_68 -> V_175 ( V_2 -> V_23 ) ;
F_78 ( V_16 , L_1 ) ;
if ( V_16 )
goto V_174;
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_26 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
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
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
F_49 ( & V_49 -> V_68 -> V_197 ) ;
if ( V_55 . V_194 != - 1 ) {
V_195 = F_92 ( V_55 . V_194 ) ;
if ( ! V_195 . V_49 ) {
V_16 = - V_198 ;
goto V_199;
}
V_178 = F_93 ( V_195 . V_49 ) ;
V_179 = F_87 ( V_49 -> V_68 , V_178 ) ;
if ( ! V_179 && ! ( V_55 . V_200 & V_201 ) ) {
V_16 = - V_202 ;
goto V_199;
}
if ( V_179 && V_55 . V_200 & V_203 ) {
V_16 = - V_64 ;
goto V_199;
}
}
V_193 = F_72 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 ) {
V_16 = - V_165 ;
goto V_199;
}
F_1 ( & V_193 -> V_28 , 0 , V_49 -> V_60 , & V_204 ) ;
F_31 ( & V_193 -> V_28 . V_9 ) ;
if ( ! V_179 ) {
V_179 = V_51 -> V_205 ( V_51 , V_49 -> V_60 , & V_59 ) ;
if ( F_51 ( V_179 ) ) {
V_16 = F_52 ( V_179 ) ;
goto V_65;
}
V_179 -> V_178 = V_178 ;
V_179 -> V_68 = V_51 ;
F_73 ( & V_179 -> V_169 , 0 ) ;
F_94 ( & V_179 -> V_206 ) ;
F_53 ( & V_179 -> V_207 ) ;
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
V_16 = F_80 ( V_49 -> V_68 , V_178 , V_179 ) ;
if ( V_16 )
goto V_209;
}
F_95 ( & V_179 -> V_169 ) ;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_171;
}
if ( V_195 . V_49 )
F_96 ( V_195 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_28 . V_172 , & V_49 -> V_60 -> V_76 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_28 . V_9 ) ;
F_60 ( & V_49 -> V_68 -> V_197 ) ;
return V_53 ;
V_171:
if ( V_178 ) {
if ( V_196 )
F_88 ( V_49 -> V_68 , V_178 ) ;
F_97 ( & V_179 -> V_169 ) ;
}
V_209:
F_20 ( & V_47 , & V_193 -> V_28 ) ;
V_170:
F_98 ( V_179 ) ;
V_65:
F_12 ( & V_193 -> V_28 ) ;
V_199:
if ( V_195 . V_49 )
F_96 ( V_195 ) ;
F_60 ( & V_49 -> V_68 -> V_197 ) ;
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
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_49 ( & V_49 -> V_68 -> V_197 ) ;
V_2 = F_30 ( & V_47 , V_55 . V_46 , V_49 -> V_60 ) ;
if ( ! V_2 ) {
V_16 = - V_64 ;
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
F_88 ( V_49 -> V_68 , V_178 ) ;
F_20 ( & V_47 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
V_16 = V_53 ;
V_210:
F_60 ( & V_49 -> V_68 -> V_197 ) ;
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
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
if ( ( V_55 . V_214 & ~ V_215 ) != ( V_55 . V_216 & ~ V_215 ) )
return - V_64 ;
V_16 = F_103 ( V_55 . V_217 ) ;
if ( V_16 )
return V_16 ;
V_2 = F_72 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , 0 , V_49 -> V_60 , & V_218 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_60 ) ;
if ( ! V_27 ) {
V_16 = - V_64 ;
goto V_94;
}
if ( V_55 . V_217 & V_219 ) {
if ( ! ( V_27 -> V_68 -> V_88 . V_89 &
V_90 ) ) {
F_104 ( L_2 ) ;
V_16 = - V_64 ;
goto V_174;
}
}
V_213 = V_27 -> V_68 -> V_220 ( V_27 , V_55 . V_214 , V_55 . V_221 , V_55 . V_216 ,
V_55 . V_217 , & V_59 ) ;
if ( F_51 ( V_213 ) ) {
V_16 = F_52 ( V_213 ) ;
goto V_174;
}
V_213 -> V_68 = V_27 -> V_68 ;
V_213 -> V_27 = V_27 ;
V_213 -> V_28 = V_2 ;
F_95 ( & V_27 -> V_169 ) ;
V_2 -> V_23 = V_213 ;
V_16 = F_14 ( & V_222 , V_2 ) ;
if ( V_16 )
goto V_223;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_224 = V_213 -> V_224 ;
V_57 . V_225 = V_213 -> V_225 ;
V_57 . V_226 = V_2 -> V_20 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_171;
}
F_34 ( V_27 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_70 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_222 , V_2 ) ;
V_223:
F_105 ( V_213 ) ;
V_174:
F_34 ( V_27 ) ;
V_94:
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
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof( V_55 ) ,
( unsigned long ) V_55 . V_66 + sizeof( V_57 ) ,
V_53 - sizeof( V_55 ) , V_54 - sizeof( V_57 ) ) ;
if ( V_55 . V_229 & ~ V_230 || ! V_55 . V_229 )
return - V_64 ;
if ( ( V_55 . V_229 & V_231 ) &&
( ! V_55 . V_214 || ! V_55 . V_216 || 0 >= V_55 . V_221 ||
( V_55 . V_214 & ~ V_215 ) != ( V_55 . V_216 & ~ V_215 ) ) )
return - V_64 ;
V_2 = F_30 ( & V_222 , V_55 . V_226 ,
V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_213 = V_2 -> V_23 ;
if ( V_55 . V_229 & V_232 ) {
V_16 = F_103 ( V_55 . V_217 ) ;
if ( V_16 )
goto V_233;
}
if ( V_55 . V_229 & V_234 ) {
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_60 ) ;
if ( ! V_27 ) {
V_16 = - V_64 ;
goto V_233;
}
}
V_228 = V_213 -> V_27 ;
V_16 = V_213 -> V_68 -> V_235 ( V_213 , V_55 . V_229 , V_55 . V_214 ,
V_55 . V_221 , V_55 . V_216 ,
V_55 . V_217 , V_27 , & V_59 ) ;
if ( ! V_16 ) {
if ( V_55 . V_229 & V_234 ) {
F_95 ( & V_27 -> V_169 ) ;
V_213 -> V_27 = V_27 ;
F_97 ( & V_228 -> V_169 ) ;
}
} else {
goto V_236;
}
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_224 = V_213 -> V_224 ;
V_57 . V_225 = V_213 -> V_225 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof( V_57 ) ) )
V_16 = - V_63 ;
else
V_16 = V_53 ;
V_236:
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
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_222 , V_55 . V_226 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_213 = V_2 -> V_23 ;
V_16 = F_105 ( V_213 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_222 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
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
struct V_58 V_59 ;
int V_16 ;
if ( V_54 < sizeof( V_57 ) )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_63 ;
V_2 = F_72 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , 0 , V_49 -> V_60 , & V_240 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_60 ) ;
if ( ! V_27 ) {
V_16 = - V_64 ;
goto V_94;
}
F_50 ( & V_59 , V_52 + sizeof( V_55 ) ,
( unsigned long ) V_55 . V_66 + sizeof( V_57 ) ,
V_53 - sizeof( V_55 ) - sizeof( struct V_241 ) ,
V_54 - sizeof( V_57 ) ) ;
V_239 = V_27 -> V_68 -> V_242 ( V_27 , V_55 . V_243 , & V_59 ) ;
if ( F_51 ( V_239 ) ) {
V_16 = F_52 ( V_239 ) ;
goto V_174;
}
V_239 -> V_68 = V_27 -> V_68 ;
V_239 -> V_27 = V_27 ;
V_239 -> V_28 = V_2 ;
F_95 ( & V_27 -> V_169 ) ;
V_2 -> V_23 = V_239 ;
V_16 = F_14 ( & V_244 , V_2 ) ;
if ( V_16 )
goto V_245;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_225 = V_239 -> V_225 ;
V_57 . V_246 = V_2 -> V_20 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof( V_57 ) ) ) {
V_16 = - V_63 ;
goto V_171;
}
F_34 ( V_27 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_71 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_244 , V_2 ) ;
V_245:
F_109 ( V_239 ) ;
V_174:
F_34 ( V_27 ) ;
V_94:
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
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_63 ;
V_2 = F_30 ( & V_244 , V_55 . V_246 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_239 = V_2 -> V_23 ;
V_16 = F_109 ( V_239 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_244 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_53 ;
}
T_2 F_111 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_111 V_55 ;
struct V_247 V_57 ;
struct V_49 * V_61 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_16 = F_56 ( V_93 ) ;
if ( V_16 < 0 )
return V_16 ;
V_57 . V_194 = V_16 ;
V_61 = F_57 ( V_49 , V_51 , 0 ) ;
if ( F_51 ( V_61 ) ) {
F_63 ( V_57 . V_194 ) ;
return F_52 ( V_61 ) ;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
F_63 ( V_57 . V_194 ) ;
F_62 ( V_61 ) ;
return - V_63 ;
}
F_59 ( V_57 . V_194 , V_61 ) ;
return V_53 ;
}
static struct V_248 * F_112 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_249 ,
struct V_58 * V_250 ,
struct V_251 * V_55 ,
T_4 V_252 ,
int (* F_113)( struct V_48 * V_49 ,
struct V_248 * V_193 ,
struct V_253 * V_57 ,
struct V_58 * V_59 ,
void * V_5 ) ,
void * V_5 )
{
struct V_248 * V_193 ;
struct V_254 * V_255 = NULL ;
struct V_29 * V_32 ;
int V_16 ;
struct V_253 V_57 ;
struct V_256 V_101 = {} ;
if ( V_55 -> V_257 >= V_49 -> V_68 -> V_92 )
return F_114 ( - V_64 ) ;
V_193 = F_72 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return F_114 ( - V_165 ) ;
F_1 ( & V_193 -> V_28 , V_55 -> V_3 , V_49 -> V_60 , & V_258 ) ;
F_31 ( & V_193 -> V_28 . V_9 ) ;
if ( V_55 -> V_259 >= 0 ) {
V_255 = F_115 ( V_55 -> V_259 ) ;
if ( ! V_255 ) {
V_16 = - V_64 ;
goto V_65;
}
}
V_193 -> V_260 = V_49 ;
V_193 -> V_261 = 0 ;
V_193 -> V_262 = 0 ;
F_53 ( & V_193 -> V_263 ) ;
F_53 ( & V_193 -> V_264 ) ;
V_101 . V_265 = V_55 -> V_265 ;
V_101 . V_257 = V_55 -> V_257 ;
if ( V_252 > F_116 ( F_117 ( * V_55 ) , V_229 ) + sizeof( V_55 -> V_229 ) )
V_101 . V_229 = V_55 -> V_229 ;
V_32 = V_51 -> F_112 ( V_51 , & V_101 ,
V_49 -> V_60 , V_250 ) ;
if ( F_51 ( V_32 ) ) {
V_16 = F_52 ( V_32 ) ;
goto V_97;
}
V_32 -> V_68 = V_51 ;
V_32 -> V_28 = & V_193 -> V_28 ;
V_32 -> V_266 = V_267 ;
V_32 -> V_268 = V_269 ;
V_32 -> V_270 = V_255 ;
F_73 ( & V_32 -> V_169 , 0 ) ;
V_193 -> V_28 . V_23 = V_32 ;
V_16 = F_14 ( & V_31 , & V_193 -> V_28 ) ;
if ( V_16 )
goto V_94;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_271 . V_30 = V_193 -> V_28 . V_20 ;
V_57 . V_271 . V_265 = V_32 -> V_265 ;
V_57 . V_272 = F_116 ( F_117 ( V_57 ) , V_272 ) +
sizeof( V_57 . V_272 ) ;
V_16 = F_113 ( V_49 , V_193 , & V_57 , V_249 , V_5 ) ;
if ( V_16 )
goto V_273;
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_28 . V_172 , & V_49 -> V_60 -> V_72 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_28 . V_9 ) ;
return V_193 ;
V_273:
F_20 ( & V_31 , & V_193 -> V_28 ) ;
V_94:
F_118 ( V_32 ) ;
V_97:
if ( V_255 )
F_119 ( V_49 , V_255 , V_193 ) ;
V_65:
F_12 ( & V_193 -> V_28 ) ;
return F_114 ( V_16 ) ;
}
static int F_120 ( struct V_48 * V_49 ,
struct V_248 * V_193 ,
struct V_253 * V_57 ,
struct V_58 * V_249 , void * V_5 )
{
if ( F_121 ( V_249 , & V_57 -> V_271 , sizeof( V_57 -> V_271 ) ) )
return - V_63 ;
return 0 ;
}
T_2 F_122 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_122 V_55 ;
struct V_251 V_274 ;
struct V_275 V_57 ;
struct V_58 V_249 ;
struct V_58 V_250 ;
struct V_248 * V_193 ;
if ( V_54 < sizeof( V_57 ) )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_63 ;
F_50 ( & V_249 , V_52 , ( unsigned long ) V_55 . V_66 , sizeof( V_55 ) , sizeof( V_57 ) ) ;
F_50 ( & V_250 , V_52 + sizeof( V_55 ) ,
( unsigned long ) V_55 . V_66 + sizeof( V_57 ) ,
V_53 - sizeof( V_55 ) , V_54 - sizeof( V_57 ) ) ;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
V_274 . V_3 = V_55 . V_3 ;
V_274 . V_265 = V_55 . V_265 ;
V_274 . V_257 = V_55 . V_257 ;
V_274 . V_259 = V_55 . V_259 ;
V_193 = F_112 ( V_49 , V_51 , & V_249 , & V_250 , & V_274 ,
F_116 ( F_117 ( V_274 ) , V_259 ) +
sizeof( V_55 . V_259 ) , F_120 ,
NULL ) ;
if ( F_51 ( V_193 ) )
return F_52 ( V_193 ) ;
return V_53 ;
}
static int F_123 ( struct V_48 * V_49 ,
struct V_248 * V_193 ,
struct V_253 * V_57 ,
struct V_58 * V_249 , void * V_5 )
{
if ( F_121 ( V_249 , V_57 , V_57 -> V_272 ) )
return - V_63 ;
return 0 ;
}
int V_251 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_249 ,
struct V_58 * V_250 )
{
struct V_253 V_57 ;
struct V_251 V_55 ;
struct V_248 * V_193 ;
int V_65 ;
if ( V_249 -> V_276 < sizeof( V_55 ) )
return - V_64 ;
V_65 = F_124 ( & V_55 , V_249 , sizeof( V_55 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_55 . V_277 )
return - V_64 ;
if ( V_55 . V_278 )
return - V_64 ;
if ( V_249 -> V_279 < ( F_116 ( F_117 ( V_57 ) , V_272 ) +
sizeof( V_57 . V_272 ) ) )
return - V_62 ;
V_193 = F_112 ( V_49 , V_51 , V_249 , V_250 , & V_55 ,
F_125 ( V_249 -> V_276 , sizeof( V_55 ) ) ,
F_123 , NULL ) ;
if ( F_51 ( V_193 ) )
return F_52 ( V_193 ) ;
return 0 ;
}
T_2 F_126 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_126 V_55 ;
struct V_280 V_57 ;
struct V_58 V_59 ;
struct V_29 * V_32 ;
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_32 = F_35 ( V_55 . V_30 , V_49 -> V_60 , 0 ) ;
if ( ! V_32 )
return - V_64 ;
V_16 = V_32 -> V_68 -> V_281 ( V_32 , V_55 . V_265 , & V_59 ) ;
if ( V_16 )
goto V_210;
V_57 . V_265 = V_32 -> V_265 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 . V_265 ) )
V_16 = - V_63 ;
V_210:
F_36 ( V_32 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_127 ( void T_3 * V_282 , struct V_283 * V_284 )
{
struct V_285 V_286 ;
V_286 . V_287 = V_284 -> V_287 ;
V_286 . V_288 = V_284 -> V_288 ;
V_286 . V_289 = V_284 -> V_289 ;
V_286 . V_290 = V_284 -> V_290 ;
V_286 . V_291 = V_284 -> V_291 ;
V_286 . V_292 . V_293 = ( V_294 V_295 ) V_284 -> V_292 . V_293 ;
V_286 . V_296 = V_284 -> V_40 -> V_296 ;
V_286 . V_297 = V_284 -> V_297 ;
V_286 . V_298 = V_284 -> V_298 ;
V_286 . V_299 = V_284 -> V_299 ;
V_286 . V_300 = V_284 -> V_300 ;
V_286 . V_301 = V_284 -> V_301 ;
V_286 . V_302 = V_284 -> V_302 ;
V_286 . V_143 = V_284 -> V_143 ;
V_286 . V_278 = 0 ;
if ( F_58 ( V_282 , & V_286 , sizeof V_286 ) )
return - V_63 ;
return 0 ;
}
T_2 F_128 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_128 V_55 ;
struct V_303 V_57 ;
T_5 T_3 * V_304 ;
T_5 T_3 * V_305 ;
struct V_29 * V_32 ;
struct V_283 V_284 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_32 = F_35 ( V_55 . V_30 , V_49 -> V_60 , 0 ) ;
if ( ! V_32 )
return - V_64 ;
V_304 = ( void T_3 * ) ( unsigned long ) V_55 . V_66 ;
V_305 = V_304 + sizeof V_57 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
while ( V_57 . V_306 < V_55 . V_307 ) {
V_16 = F_129 ( V_32 , 1 , & V_284 ) ;
if ( V_16 < 0 )
goto V_308;
if ( ! V_16 )
break;
V_16 = F_127 ( V_305 , & V_284 ) ;
if ( V_16 )
goto V_308;
V_305 += sizeof( struct V_285 ) ;
++ V_57 . V_306 ;
}
if ( F_58 ( V_304 , & V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_308;
}
V_16 = V_53 ;
V_308:
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
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_32 = F_35 ( V_55 . V_30 , V_49 -> V_60 , 0 ) ;
if ( ! V_32 )
return - V_64 ;
F_131 ( V_32 , V_55 . V_309 ?
V_310 : V_311 ) ;
F_36 ( V_32 ) ;
return V_53 ;
}
T_2 F_132 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_132 V_55 ;
struct V_312 V_57 ;
struct V_1 * V_2 ;
struct V_29 * V_32 ;
struct V_248 * V_193 ;
struct V_254 * V_255 ;
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_31 , V_55 . V_30 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_32 = V_2 -> V_23 ;
V_255 = V_32 -> V_270 ;
V_193 = F_7 ( V_32 -> V_28 , struct V_248 , V_28 ) ;
V_16 = F_118 ( V_32 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_31 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_119 ( V_49 , V_255 , V_193 ) ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_261 = V_193 -> V_261 ;
V_57 . V_262 = V_193 -> V_262 ;
F_8 ( V_2 ) ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
return - V_63 ;
return V_53 ;
}
static int F_133 ( struct V_48 * V_49 ,
struct V_58 * V_249 ,
struct V_58 * V_250 ,
struct V_313 * V_55 ,
T_4 V_252 ,
int (* F_113)( struct V_48 * V_49 ,
struct V_314 * V_57 ,
struct V_58 * V_59 ) ,
void * V_5 )
{
struct V_315 * V_193 ;
struct V_50 * V_68 ;
struct V_24 * V_27 = NULL ;
struct V_45 * V_179 = NULL ;
struct V_1 * V_316 ( V_317 ) ;
struct V_29 * V_318 = NULL , * V_319 = NULL ;
struct V_41 * V_44 = NULL ;
struct V_37 * V_40 ;
char * V_52 ;
struct V_320 V_101 = {} ;
struct V_314 V_57 ;
int V_16 ;
if ( V_55 -> V_321 == V_322 && ! F_134 ( V_323 ) )
return - V_324 ;
V_193 = F_135 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return - V_165 ;
F_1 ( & V_193 -> V_325 . V_28 , V_55 -> V_3 , V_49 -> V_60 ,
& V_326 ) ;
F_31 ( & V_193 -> V_325 . V_28 . V_9 ) ;
if ( V_55 -> V_321 == V_327 ) {
V_179 = F_45 ( V_55 -> V_25 , V_49 -> V_60 ,
& V_317 ) ;
if ( ! V_179 ) {
V_16 = - V_64 ;
goto V_174;
}
V_68 = V_179 -> V_68 ;
} else {
if ( V_55 -> V_321 == V_328 ) {
V_55 -> V_329 = 0 ;
V_55 -> V_330 = 0 ;
} else {
if ( V_55 -> V_331 ) {
V_44 = F_43 ( V_55 -> V_42 ,
V_49 -> V_60 ) ;
if ( ! V_44 || V_44 -> V_332 != V_333 ) {
V_16 = - V_64 ;
goto V_174;
}
}
if ( V_55 -> V_334 != V_55 -> V_335 ) {
V_319 = F_35 ( V_55 -> V_334 ,
V_49 -> V_60 , 0 ) ;
if ( ! V_319 ) {
V_16 = - V_64 ;
goto V_174;
}
}
}
V_318 = F_35 ( V_55 -> V_335 , V_49 -> V_60 , ! ! V_319 ) ;
V_319 = V_319 ? : V_318 ;
V_27 = F_33 ( V_55 -> V_25 , V_49 -> V_60 ) ;
if ( ! V_27 || ! V_318 ) {
V_16 = - V_64 ;
goto V_174;
}
V_68 = V_27 -> V_68 ;
}
V_101 . V_268 = V_336 ;
V_101 . V_337 = V_49 ;
V_101 . V_338 = V_318 ;
V_101 . V_339 = V_319 ;
V_101 . V_44 = V_44 ;
V_101 . V_179 = V_179 ;
V_101 . V_340 = V_55 -> V_341 ? V_342 :
V_343 ;
V_101 . V_321 = V_55 -> V_321 ;
V_101 . V_344 = 0 ;
V_101 . V_345 . V_346 = V_55 -> V_346 ;
V_101 . V_345 . V_329 = V_55 -> V_329 ;
V_101 . V_345 . V_347 = V_55 -> V_347 ;
V_101 . V_345 . V_330 = V_55 -> V_330 ;
V_101 . V_345 . V_348 = V_55 -> V_348 ;
V_193 -> V_325 . V_349 = 0 ;
F_53 ( & V_193 -> V_325 . V_350 ) ;
F_53 ( & V_193 -> V_351 ) ;
if ( V_252 >= F_116 ( F_117 ( * V_55 ) , V_344 ) +
sizeof( V_55 -> V_344 ) )
V_101 . V_344 = V_55 -> V_344 ;
if ( V_101 . V_344 & ~ ( V_352 |
V_353 |
V_354 |
V_355 |
V_356 ) ) {
V_16 = - V_64 ;
goto V_174;
}
V_52 = ( void * ) V_55 + sizeof( * V_55 ) ;
if ( V_252 > sizeof( * V_55 ) )
if ( ! ( V_52 [ 0 ] == 0 && ! memcmp ( V_52 , V_52 + 1 ,
V_252 - sizeof( * V_55 ) - 1 ) ) ) {
V_16 = - V_64 ;
goto V_174;
}
if ( V_55 -> V_321 == V_327 )
V_40 = F_136 ( V_27 , & V_101 ) ;
else
V_40 = V_68 -> F_133 ( V_27 , & V_101 , V_250 ) ;
if ( F_51 ( V_40 ) ) {
V_16 = F_52 ( V_40 ) ;
goto V_174;
}
if ( V_55 -> V_321 != V_327 ) {
V_40 -> V_357 = V_40 ;
V_40 -> V_68 = V_68 ;
V_40 -> V_27 = V_27 ;
V_40 -> V_338 = V_101 . V_338 ;
V_40 -> V_339 = V_101 . V_339 ;
V_40 -> V_44 = V_101 . V_44 ;
V_40 -> V_268 = V_101 . V_268 ;
V_40 -> V_337 = V_101 . V_337 ;
V_40 -> V_321 = V_101 . V_321 ;
F_73 ( & V_40 -> V_169 , 0 ) ;
F_95 ( & V_27 -> V_169 ) ;
F_95 ( & V_101 . V_338 -> V_169 ) ;
if ( V_101 . V_339 )
F_95 ( & V_101 . V_339 -> V_169 ) ;
if ( V_101 . V_44 )
F_95 ( & V_101 . V_44 -> V_169 ) ;
}
V_40 -> V_28 = & V_193 -> V_325 . V_28 ;
V_193 -> V_325 . V_28 . V_23 = V_40 ;
V_16 = F_14 ( & V_39 , & V_193 -> V_325 . V_28 ) ;
if ( V_16 )
goto V_358;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_271 . V_359 = V_40 -> V_296 ;
V_57 . V_271 . V_38 = V_193 -> V_325 . V_28 . V_20 ;
V_57 . V_271 . V_330 = V_101 . V_345 . V_330 ;
V_57 . V_271 . V_347 = V_101 . V_345 . V_347 ;
V_57 . V_271 . V_329 = V_101 . V_345 . V_329 ;
V_57 . V_271 . V_346 = V_101 . V_345 . V_346 ;
V_57 . V_271 . V_348 = V_101 . V_345 . V_348 ;
V_57 . V_272 = F_116 ( F_117 ( V_57 ) , V_272 ) +
sizeof( V_57 . V_272 ) ;
V_16 = F_113 ( V_49 , & V_57 , V_249 ) ;
if ( V_16 )
goto V_273;
if ( V_179 ) {
V_193 -> V_360 = F_7 ( V_317 , struct V_192 ,
V_28 ) ;
F_95 ( & V_193 -> V_360 -> V_208 ) ;
F_46 ( V_317 ) ;
}
if ( V_27 )
F_34 ( V_27 ) ;
if ( V_318 )
F_36 ( V_318 ) ;
if ( V_319 && V_319 != V_318 )
F_36 ( V_319 ) ;
if ( V_44 )
F_44 ( V_44 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_325 . V_28 . V_172 , & V_49 -> V_60 -> V_73 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_325 . V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_325 . V_28 . V_9 ) ;
return 0 ;
V_273:
F_20 ( & V_39 , & V_193 -> V_325 . V_28 ) ;
V_358:
F_137 ( V_40 ) ;
V_174:
if ( V_179 )
F_46 ( V_317 ) ;
if ( V_27 )
F_34 ( V_27 ) ;
if ( V_318 )
F_36 ( V_318 ) ;
if ( V_319 && V_319 != V_318 )
F_36 ( V_319 ) ;
if ( V_44 )
F_44 ( V_44 ) ;
F_12 ( & V_193 -> V_325 . V_28 ) ;
return V_16 ;
}
static int F_138 ( struct V_48 * V_49 ,
struct V_314 * V_57 ,
struct V_58 * V_249 )
{
if ( F_121 ( V_249 , & V_57 -> V_271 , sizeof( V_57 -> V_271 ) ) )
return - V_63 ;
return 0 ;
}
T_2 F_139 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_139 V_55 ;
struct V_313 V_274 ;
struct V_58 V_249 ;
struct V_58 V_250 ;
T_2 V_361 = sizeof( struct V_362 ) ;
int V_65 ;
if ( V_54 < V_361 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_63 ;
F_50 ( & V_249 , V_52 , ( unsigned long ) V_55 . V_66 , sizeof( V_55 ) ,
V_361 ) ;
F_50 ( & V_250 , V_52 + sizeof( V_55 ) ,
( unsigned long ) V_55 . V_66 + V_361 ,
V_53 - sizeof( V_55 ) - sizeof( struct V_241 ) ,
V_54 - V_361 ) ;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
V_274 . V_3 = V_55 . V_3 ;
V_274 . V_25 = V_55 . V_25 ;
V_274 . V_335 = V_55 . V_335 ;
V_274 . V_334 = V_55 . V_334 ;
V_274 . V_42 = V_55 . V_42 ;
V_274 . V_346 = V_55 . V_346 ;
V_274 . V_329 = V_55 . V_329 ;
V_274 . V_347 = V_55 . V_347 ;
V_274 . V_330 = V_55 . V_330 ;
V_274 . V_348 = V_55 . V_348 ;
V_274 . V_341 = V_55 . V_341 ;
V_274 . V_321 = V_55 . V_321 ;
V_274 . V_331 = V_55 . V_331 ;
V_65 = F_133 ( V_49 , & V_249 , & V_250 , & V_274 ,
F_116 ( F_117 ( V_274 ) , V_331 ) +
sizeof( V_55 . V_331 ) , F_138 ,
NULL ) ;
if ( V_65 )
return V_65 ;
return V_53 ;
}
static int F_140 ( struct V_48 * V_49 ,
struct V_314 * V_57 ,
struct V_58 * V_249 )
{
if ( F_121 ( V_249 , V_57 , V_57 -> V_272 ) )
return - V_63 ;
return 0 ;
}
int V_313 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_249 ,
struct V_58 * V_250 )
{
struct V_314 V_57 ;
struct V_313 V_55 = { 0 } ;
int V_65 ;
if ( V_249 -> V_276 < ( F_116 ( F_117 ( V_55 ) , V_277 ) +
sizeof( V_55 . V_277 ) ) )
return - V_64 ;
V_65 = F_124 ( & V_55 , V_249 , F_125 ( sizeof( V_55 ) , V_249 -> V_276 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_55 . V_277 )
return - V_64 ;
if ( V_55 . V_278 )
return - V_64 ;
if ( V_249 -> V_279 < ( F_116 ( F_117 ( V_57 ) , V_272 ) +
sizeof( V_57 . V_272 ) ) )
return - V_62 ;
V_65 = F_133 ( V_49 , V_249 , V_250 , & V_55 ,
F_125 ( V_249 -> V_276 , sizeof( V_55 ) ) ,
F_140 , NULL ) ;
if ( V_65 )
return V_65 ;
return 0 ;
}
T_2 F_141 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 , int V_54 )
{
struct F_141 V_55 ;
struct V_362 V_57 ;
struct V_58 V_59 ;
struct V_315 * V_193 ;
struct V_45 * V_179 ;
struct V_1 * V_316 ( V_317 ) ;
struct V_37 * V_40 ;
struct V_363 V_101 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_193 = F_72 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return - V_165 ;
F_1 ( & V_193 -> V_325 . V_28 , V_55 . V_3 , V_49 -> V_60 , & V_326 ) ;
F_31 ( & V_193 -> V_325 . V_28 . V_9 ) ;
V_179 = F_45 ( V_55 . V_25 , V_49 -> V_60 , & V_317 ) ;
if ( ! V_179 ) {
V_16 = - V_64 ;
goto V_174;
}
V_101 . V_268 = V_336 ;
V_101 . V_337 = V_49 ;
V_101 . V_296 = V_55 . V_359 ;
V_101 . V_321 = V_55 . V_321 ;
V_193 -> V_325 . V_349 = 0 ;
F_53 ( & V_193 -> V_325 . V_350 ) ;
F_53 ( & V_193 -> V_351 ) ;
V_40 = F_142 ( V_179 , & V_101 ) ;
if ( F_51 ( V_40 ) ) {
V_16 = F_52 ( V_40 ) ;
goto V_174;
}
V_40 -> V_28 = & V_193 -> V_325 . V_28 ;
V_193 -> V_325 . V_28 . V_23 = V_40 ;
V_16 = F_14 ( & V_39 , & V_193 -> V_325 . V_28 ) ;
if ( V_16 )
goto V_358;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_359 = V_40 -> V_296 ;
V_57 . V_38 = V_193 -> V_325 . V_28 . V_20 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_364;
}
V_193 -> V_360 = F_7 ( V_317 , struct V_192 , V_28 ) ;
F_95 ( & V_193 -> V_360 -> V_208 ) ;
F_46 ( V_317 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_325 . V_28 . V_172 , & V_49 -> V_60 -> V_73 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_325 . V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_325 . V_28 . V_9 ) ;
return V_53 ;
V_364:
F_20 ( & V_39 , & V_193 -> V_325 . V_28 ) ;
V_358:
F_137 ( V_40 ) ;
V_174:
F_46 ( V_317 ) ;
F_12 ( & V_193 -> V_325 . V_28 ) ;
return V_16 ;
}
T_2 F_143 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_143 V_55 ;
struct V_365 V_57 ;
struct V_37 * V_40 ;
struct V_366 * V_101 ;
struct V_320 * V_367 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_101 = F_72 ( sizeof *V_101 , V_17 ) ;
V_367 = F_72 ( sizeof *V_367 , V_17 ) ;
if ( ! V_101 || ! V_367 ) {
V_16 = - V_165 ;
goto V_210;
}
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 ) {
V_16 = - V_64 ;
goto V_210;
}
V_16 = F_144 ( V_40 , V_101 , V_55 . V_368 , V_367 ) ;
F_41 ( V_40 ) ;
if ( V_16 )
goto V_210;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_369 = V_101 -> V_369 ;
V_57 . V_370 = V_101 -> V_370 ;
V_57 . V_371 = V_101 -> V_371 ;
V_57 . V_372 = V_101 -> V_372 ;
V_57 . V_373 = V_101 -> V_373 ;
V_57 . V_374 = V_101 -> V_374 ;
V_57 . V_375 = V_101 -> V_375 ;
V_57 . V_376 = V_101 -> V_376 ;
V_57 . V_377 = V_101 -> V_377 ;
V_57 . V_299 = V_101 -> V_299 ;
V_57 . V_378 = V_101 -> V_378 ;
V_57 . V_379 = V_101 -> V_379 ;
V_57 . V_380 = V_101 -> V_380 ;
V_57 . V_381 = V_101 -> V_381 ;
V_57 . V_382 = V_101 -> V_382 ;
V_57 . V_143 = V_101 -> V_143 ;
V_57 . V_383 = V_101 -> V_383 ;
V_57 . V_384 = V_101 -> V_384 ;
V_57 . V_385 = V_101 -> V_385 ;
V_57 . V_386 = V_101 -> V_386 ;
V_57 . V_387 = V_101 -> V_387 ;
memcpy ( V_57 . V_282 . V_388 , V_101 -> V_389 . V_390 . V_388 . V_391 , 16 ) ;
V_57 . V_282 . V_392 = V_101 -> V_389 . V_390 . V_392 ;
V_57 . V_282 . V_393 = V_101 -> V_389 . V_390 . V_393 ;
V_57 . V_282 . V_394 = V_101 -> V_389 . V_390 . V_394 ;
V_57 . V_282 . V_395 = V_101 -> V_389 . V_390 . V_395 ;
V_57 . V_282 . V_396 = V_101 -> V_389 . V_396 ;
V_57 . V_282 . V_301 = V_101 -> V_389 . V_301 ;
V_57 . V_282 . V_397 = V_101 -> V_389 . V_397 ;
V_57 . V_282 . V_398 = V_101 -> V_389 . V_398 ;
V_57 . V_282 . V_399 = ! ! ( V_101 -> V_389 . V_400 & V_401 ) ;
V_57 . V_282 . V_143 = V_101 -> V_389 . V_143 ;
memcpy ( V_57 . V_402 . V_388 , V_101 -> V_403 . V_390 . V_388 . V_391 , 16 ) ;
V_57 . V_402 . V_392 = V_101 -> V_403 . V_390 . V_392 ;
V_57 . V_402 . V_393 = V_101 -> V_403 . V_390 . V_393 ;
V_57 . V_402 . V_394 = V_101 -> V_403 . V_390 . V_394 ;
V_57 . V_402 . V_395 = V_101 -> V_403 . V_390 . V_395 ;
V_57 . V_402 . V_396 = V_101 -> V_403 . V_396 ;
V_57 . V_402 . V_301 = V_101 -> V_403 . V_301 ;
V_57 . V_402 . V_397 = V_101 -> V_403 . V_397 ;
V_57 . V_402 . V_398 = V_101 -> V_403 . V_398 ;
V_57 . V_402 . V_399 = ! ! ( V_101 -> V_403 . V_400 & V_401 ) ;
V_57 . V_402 . V_143 = V_101 -> V_403 . V_143 ;
V_57 . V_346 = V_367 -> V_345 . V_346 ;
V_57 . V_329 = V_367 -> V_345 . V_329 ;
V_57 . V_347 = V_367 -> V_345 . V_347 ;
V_57 . V_330 = V_367 -> V_345 . V_330 ;
V_57 . V_348 = V_367 -> V_345 . V_348 ;
V_57 . V_341 = V_367 -> V_340 == V_342 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
V_210:
F_82 ( V_101 ) ;
F_82 ( V_367 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_145 ( enum V_404 V_321 , int V_405 )
{
switch ( V_321 ) {
case V_328 :
return V_405 & ~ ( V_406 | V_407 ) ;
case V_327 :
return V_405 & ~ ( V_408 | V_409 |
V_410 ) ;
default:
return V_405 ;
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
struct V_366 * V_101 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 , NULL , V_53 - sizeof V_55 ,
V_54 ) ;
V_101 = F_72 ( sizeof *V_101 , V_17 ) ;
if ( ! V_101 )
return - V_165 ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 ) {
V_16 = - V_64 ;
goto V_210;
}
V_101 -> V_369 = V_55 . V_369 ;
V_101 -> V_370 = V_55 . V_370 ;
V_101 -> V_371 = V_55 . V_371 ;
V_101 -> V_372 = V_55 . V_372 ;
V_101 -> V_373 = V_55 . V_373 ;
V_101 -> V_374 = V_55 . V_374 ;
V_101 -> V_375 = V_55 . V_375 ;
V_101 -> V_376 = V_55 . V_376 ;
V_101 -> V_377 = V_55 . V_377 ;
V_101 -> V_299 = V_55 . V_299 ;
V_101 -> V_378 = V_55 . V_378 ;
V_101 -> V_411 = V_55 . V_411 ;
V_101 -> V_380 = V_55 . V_380 ;
V_101 -> V_381 = V_55 . V_381 ;
V_101 -> V_382 = V_55 . V_382 ;
V_101 -> V_143 = V_55 . V_143 ;
V_101 -> V_383 = V_55 . V_383 ;
V_101 -> V_384 = V_55 . V_384 ;
V_101 -> V_385 = V_55 . V_385 ;
V_101 -> V_386 = V_55 . V_386 ;
V_101 -> V_387 = V_55 . V_387 ;
memcpy ( V_101 -> V_389 . V_390 . V_388 . V_391 , V_55 . V_282 . V_388 , 16 ) ;
V_101 -> V_389 . V_390 . V_392 = V_55 . V_282 . V_392 ;
V_101 -> V_389 . V_390 . V_393 = V_55 . V_282 . V_393 ;
V_101 -> V_389 . V_390 . V_394 = V_55 . V_282 . V_394 ;
V_101 -> V_389 . V_390 . V_395 = V_55 . V_282 . V_395 ;
V_101 -> V_389 . V_396 = V_55 . V_282 . V_396 ;
V_101 -> V_389 . V_301 = V_55 . V_282 . V_301 ;
V_101 -> V_389 . V_397 = V_55 . V_282 . V_397 ;
V_101 -> V_389 . V_398 = V_55 . V_282 . V_398 ;
V_101 -> V_389 . V_400 = V_55 . V_282 . V_399 ? V_401 : 0 ;
V_101 -> V_389 . V_143 = V_55 . V_282 . V_143 ;
memcpy ( V_101 -> V_403 . V_390 . V_388 . V_391 , V_55 . V_402 . V_388 , 16 ) ;
V_101 -> V_403 . V_390 . V_392 = V_55 . V_402 . V_392 ;
V_101 -> V_403 . V_390 . V_393 = V_55 . V_402 . V_393 ;
V_101 -> V_403 . V_390 . V_394 = V_55 . V_402 . V_394 ;
V_101 -> V_403 . V_390 . V_395 = V_55 . V_402 . V_395 ;
V_101 -> V_403 . V_396 = V_55 . V_402 . V_396 ;
V_101 -> V_403 . V_301 = V_55 . V_402 . V_301 ;
V_101 -> V_403 . V_397 = V_55 . V_402 . V_397 ;
V_101 -> V_403 . V_398 = V_55 . V_402 . V_398 ;
V_101 -> V_403 . V_400 = V_55 . V_402 . V_399 ? V_401 : 0 ;
V_101 -> V_403 . V_143 = V_55 . V_402 . V_143 ;
if ( V_40 -> V_357 == V_40 ) {
V_16 = F_147 ( V_40 , V_101 , & V_55 . V_368 ) ;
if ( V_16 )
goto V_412;
V_16 = V_40 -> V_68 -> V_413 ( V_40 , V_101 ,
F_145 ( V_40 -> V_321 , V_55 . V_368 ) , & V_59 ) ;
} else {
V_16 = F_148 ( V_40 , V_101 , F_145 ( V_40 -> V_321 , V_55 . V_368 ) ) ;
}
if ( V_16 )
goto V_412;
V_16 = V_53 ;
V_412:
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
struct V_414 V_57 ;
struct V_1 * V_2 ;
struct V_37 * V_40 ;
struct V_315 * V_193 ;
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_2 = F_30 ( & V_39 , V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_40 = V_2 -> V_23 ;
V_193 = F_7 ( V_2 , struct V_315 , V_325 . V_28 ) ;
if ( ! F_150 ( & V_193 -> V_351 ) ) {
F_12 ( V_2 ) ;
return - V_173 ;
}
V_16 = F_137 ( V_40 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_193 -> V_360 )
F_97 ( & V_193 -> V_360 -> V_208 ) ;
F_20 ( & V_39 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_151 ( V_49 , & V_193 -> V_325 ) ;
V_57 . V_349 = V_193 -> V_325 . V_349 ;
F_8 ( V_2 ) ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
return - V_63 ;
return V_53 ;
}
static void * F_152 ( T_4 V_415 , V_294 V_416 )
{
return F_72 ( F_153 ( V_415 , sizeof ( struct V_417 ) ) +
V_416 * sizeof ( struct V_417 ) , V_17 ) ;
}
T_2 F_154 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_154 V_55 ;
struct V_418 V_57 ;
struct V_419 * V_420 ;
struct V_421 * V_422 = NULL , * V_423 , * V_424 , * V_425 ;
struct V_37 * V_40 ;
int V_426 , V_427 ;
int V_428 ;
T_2 V_16 = - V_64 ;
T_4 V_429 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
if ( V_53 < sizeof V_55 + V_55 . V_430 * V_55 . V_431 +
V_55 . V_432 * sizeof ( struct V_433 ) )
return - V_64 ;
if ( V_55 . V_430 < sizeof ( struct V_419 ) )
return - V_64 ;
V_420 = F_72 ( V_55 . V_430 , V_17 ) ;
if ( ! V_420 )
return - V_165 ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 )
goto V_210;
V_428 = V_40 -> V_321 == V_434 ;
V_427 = 0 ;
V_423 = NULL ;
for ( V_426 = 0 ; V_426 < V_55 . V_431 ; ++ V_426 ) {
if ( F_48 ( V_420 ,
V_52 + sizeof V_55 + V_426 * V_55 . V_430 ,
V_55 . V_430 ) ) {
V_16 = - V_63 ;
goto V_308;
}
if ( V_420 -> V_416 + V_427 > V_55 . V_432 ) {
V_16 = - V_64 ;
goto V_308;
}
if ( V_428 ) {
struct V_435 * V_436 ;
if ( V_420 -> V_289 != V_437 &&
V_420 -> V_289 != V_438 ) {
V_16 = - V_64 ;
goto V_308;
}
V_429 = sizeof( * V_436 ) ;
V_436 = F_152 ( V_429 , V_420 -> V_416 ) ;
if ( ! V_436 ) {
V_16 = - V_165 ;
goto V_308;
}
V_436 -> V_36 = F_37 ( V_420 -> V_422 . V_436 . V_36 , V_49 -> V_60 ) ;
if ( ! V_436 -> V_36 ) {
F_82 ( V_436 ) ;
V_16 = - V_64 ;
goto V_308;
}
V_436 -> V_439 = V_420 -> V_422 . V_436 . V_439 ;
V_436 -> V_440 = V_420 -> V_422 . V_436 . V_440 ;
V_424 = & V_436 -> V_422 ;
} else if ( V_420 -> V_289 == V_441 ||
V_420 -> V_289 == V_442 ||
V_420 -> V_289 == V_443 ) {
struct V_444 * V_445 ;
V_429 = sizeof( * V_445 ) ;
V_445 = F_152 ( V_429 , V_420 -> V_416 ) ;
if ( ! V_445 ) {
V_16 = - V_165 ;
goto V_308;
}
V_445 -> V_446 = V_420 -> V_422 . V_445 . V_446 ;
V_445 -> V_225 = V_420 -> V_422 . V_445 . V_225 ;
V_424 = & V_445 -> V_422 ;
} else if ( V_420 -> V_289 == V_447 ||
V_420 -> V_289 == V_448 ) {
struct V_449 * V_450 ;
V_429 = sizeof( * V_450 ) ;
V_450 = F_152 ( V_429 , V_420 -> V_416 ) ;
if ( ! V_450 ) {
V_16 = - V_165 ;
goto V_308;
}
V_450 -> V_446 = V_420 -> V_422 . V_450 . V_446 ;
V_450 -> V_451 = V_420 -> V_422 . V_450 . V_451 ;
V_450 -> V_452 = V_420 -> V_422 . V_450 . V_452 ;
V_450 -> V_225 = V_420 -> V_422 . V_450 . V_225 ;
V_424 = & V_450 -> V_422 ;
} else if ( V_420 -> V_289 == V_437 ||
V_420 -> V_289 == V_438 ||
V_420 -> V_289 == V_453 ) {
V_429 = sizeof( * V_424 ) ;
V_424 = F_152 ( V_429 , V_420 -> V_416 ) ;
if ( ! V_424 ) {
V_16 = - V_165 ;
goto V_308;
}
} else {
V_16 = - V_64 ;
goto V_308;
}
if ( V_420 -> V_289 == V_438 ||
V_420 -> V_289 == V_441 ) {
V_424 -> V_292 . V_293 =
( V_454 V_295 ) V_420 -> V_292 . V_293 ;
} else if ( V_420 -> V_289 == V_453 ) {
V_424 -> V_292 . V_455 = V_420 -> V_292 . V_455 ;
}
if ( ! V_423 )
V_422 = V_424 ;
else
V_423 -> V_424 = V_424 ;
V_423 = V_424 ;
V_424 -> V_424 = NULL ;
V_424 -> V_287 = V_420 -> V_287 ;
V_424 -> V_416 = V_420 -> V_416 ;
V_424 -> V_289 = V_420 -> V_289 ;
V_424 -> V_456 = V_420 -> V_456 ;
if ( V_424 -> V_416 ) {
V_424 -> V_457 = ( void * ) V_424 +
F_153 ( V_429 , sizeof( struct V_417 ) ) ;
if ( F_48 ( V_424 -> V_457 ,
V_52 + sizeof V_55 +
V_55 . V_431 * V_55 . V_430 +
V_427 * sizeof ( struct V_417 ) ,
V_424 -> V_416 * sizeof ( struct V_417 ) ) ) {
V_16 = - V_63 ;
goto V_308;
}
V_427 += V_424 -> V_416 ;
} else
V_424 -> V_457 = NULL ;
}
V_57 . V_425 = 0 ;
V_16 = V_40 -> V_68 -> V_458 ( V_40 -> V_357 , V_422 , & V_425 ) ;
if ( V_16 )
for ( V_424 = V_422 ; V_424 ; V_424 = V_424 -> V_424 ) {
++ V_57 . V_425 ;
if ( V_424 == V_425 )
break;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
V_308:
F_41 ( V_40 ) ;
while ( V_422 ) {
if ( V_428 && F_155 ( V_422 ) -> V_36 )
F_38 ( F_155 ( V_422 ) -> V_36 ) ;
V_424 = V_422 -> V_424 ;
F_82 ( V_422 ) ;
V_422 = V_424 ;
}
V_210:
F_82 ( V_420 ) ;
return V_16 ? V_16 : V_53 ;
}
static struct V_459 * F_156 ( const char T_3 * V_52 ,
int V_53 ,
T_6 V_431 ,
T_6 V_432 ,
T_6 V_430 )
{
struct V_460 * V_420 ;
struct V_459 * V_422 = NULL , * V_423 , * V_424 ;
int V_427 ;
int V_426 ;
int V_16 ;
if ( V_53 < V_430 * V_431 +
V_432 * sizeof ( struct V_433 ) )
return F_114 ( - V_64 ) ;
if ( V_430 < sizeof ( struct V_460 ) )
return F_114 ( - V_64 ) ;
V_420 = F_72 ( V_430 , V_17 ) ;
if ( ! V_420 )
return F_114 ( - V_165 ) ;
V_427 = 0 ;
V_423 = NULL ;
for ( V_426 = 0 ; V_426 < V_431 ; ++ V_426 ) {
if ( F_48 ( V_420 , V_52 + V_426 * V_430 ,
V_430 ) ) {
V_16 = - V_63 ;
goto V_65;
}
if ( V_420 -> V_416 + V_427 > V_432 ) {
V_16 = - V_64 ;
goto V_65;
}
V_424 = F_72 ( F_153 ( sizeof *V_424 , sizeof ( struct V_417 ) ) +
V_420 -> V_416 * sizeof ( struct V_417 ) ,
V_17 ) ;
if ( ! V_424 ) {
V_16 = - V_165 ;
goto V_65;
}
if ( ! V_423 )
V_422 = V_424 ;
else
V_423 -> V_424 = V_424 ;
V_423 = V_424 ;
V_424 -> V_424 = NULL ;
V_424 -> V_287 = V_420 -> V_287 ;
V_424 -> V_416 = V_420 -> V_416 ;
if ( V_424 -> V_416 ) {
V_424 -> V_457 = ( void * ) V_424 +
F_153 ( sizeof *V_424 , sizeof ( struct V_417 ) ) ;
if ( F_48 ( V_424 -> V_457 ,
V_52 + V_431 * V_430 +
V_427 * sizeof ( struct V_417 ) ,
V_424 -> V_416 * sizeof ( struct V_417 ) ) ) {
V_16 = - V_63 ;
goto V_65;
}
V_427 += V_424 -> V_416 ;
} else
V_424 -> V_457 = NULL ;
}
F_82 ( V_420 ) ;
return V_422 ;
V_65:
F_82 ( V_420 ) ;
while ( V_422 ) {
V_424 = V_422 -> V_424 ;
F_82 ( V_422 ) ;
V_422 = V_424 ;
}
return F_114 ( V_16 ) ;
}
T_2 F_157 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_157 V_55 ;
struct V_461 V_57 ;
struct V_459 * V_422 , * V_424 , * V_425 ;
struct V_37 * V_40 ;
T_2 V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_422 = F_156 ( V_52 + sizeof V_55 ,
V_53 - sizeof V_55 , V_55 . V_431 ,
V_55 . V_432 , V_55 . V_430 ) ;
if ( F_51 ( V_422 ) )
return F_52 ( V_422 ) ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 )
goto V_210;
V_57 . V_425 = 0 ;
V_16 = V_40 -> V_68 -> V_462 ( V_40 -> V_357 , V_422 , & V_425 ) ;
F_41 ( V_40 ) ;
if ( V_16 )
for ( V_424 = V_422 ; V_424 ; V_424 = V_424 -> V_424 ) {
++ V_57 . V_425 ;
if ( V_424 == V_425 )
break;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
V_210:
while ( V_422 ) {
V_424 = V_422 -> V_424 ;
F_82 ( V_422 ) ;
V_422 = V_424 ;
}
return V_16 ? V_16 : V_53 ;
}
T_2 F_158 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_158 V_55 ;
struct V_463 V_57 ;
struct V_459 * V_422 , * V_424 , * V_425 ;
struct V_41 * V_44 ;
T_2 V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_422 = F_156 ( V_52 + sizeof V_55 ,
V_53 - sizeof V_55 , V_55 . V_431 ,
V_55 . V_432 , V_55 . V_430 ) ;
if ( F_51 ( V_422 ) )
return F_52 ( V_422 ) ;
V_44 = F_43 ( V_55 . V_42 , V_49 -> V_60 ) ;
if ( ! V_44 )
goto V_210;
V_57 . V_425 = 0 ;
V_16 = V_44 -> V_68 -> V_464 ( V_44 , V_422 , & V_425 ) ;
F_44 ( V_44 ) ;
if ( V_16 )
for ( V_424 = V_422 ; V_424 ; V_424 = V_424 -> V_424 ) {
++ V_57 . V_425 ;
if ( V_424 == V_425 )
break;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
V_210:
while ( V_422 ) {
V_424 = V_422 -> V_424 ;
F_82 ( V_422 ) ;
V_422 = V_424 ;
}
return V_16 ? V_16 : V_53 ;
}
T_2 F_159 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_159 V_55 ;
struct V_465 V_57 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_33 * V_36 ;
struct V_466 V_101 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_72 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , V_55 . V_3 , V_49 -> V_60 , & V_467 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_60 ) ;
if ( ! V_27 ) {
V_16 = - V_64 ;
goto V_65;
}
V_101 . V_396 = V_55 . V_101 . V_396 ;
V_101 . V_301 = V_55 . V_101 . V_301 ;
V_101 . V_397 = V_55 . V_101 . V_397 ;
V_101 . V_398 = V_55 . V_101 . V_398 ;
V_101 . V_400 = V_55 . V_101 . V_399 ? V_401 : 0 ;
V_101 . V_143 = V_55 . V_101 . V_143 ;
V_101 . V_390 . V_392 = V_55 . V_101 . V_390 . V_392 ;
V_101 . V_390 . V_393 = V_55 . V_101 . V_390 . V_393 ;
V_101 . V_390 . V_394 = V_55 . V_101 . V_390 . V_394 ;
V_101 . V_390 . V_395 = V_55 . V_101 . V_390 . V_395 ;
memset ( & V_101 . V_468 , 0 , sizeof( V_101 . V_468 ) ) ;
memcpy ( V_101 . V_390 . V_388 . V_391 , V_55 . V_101 . V_390 . V_388 , 16 ) ;
V_36 = F_160 ( V_27 , & V_101 ) ;
if ( F_51 ( V_36 ) ) {
V_16 = F_52 ( V_36 ) ;
goto V_174;
}
V_36 -> V_28 = V_2 ;
V_2 -> V_23 = V_36 ;
V_16 = F_14 ( & V_35 , V_2 ) ;
if ( V_16 )
goto V_358;
V_57 . V_34 = V_2 -> V_20 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_171;
}
F_34 ( V_27 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_75 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_35 , V_2 ) ;
V_358:
F_161 ( V_36 ) ;
V_174:
F_34 ( V_27 ) ;
V_65:
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
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_35 , V_55 . V_34 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_36 = V_2 -> V_23 ;
V_16 = F_161 ( V_36 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_35 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
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
struct V_315 * V_193 ;
struct V_469 * V_470 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_40 = F_40 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 )
return - V_64 ;
V_193 = F_7 ( V_40 -> V_28 , struct V_315 , V_325 . V_28 ) ;
F_164 (mcast, &obj->mcast_list, list)
if ( V_55 . V_471 == V_470 -> V_153 &&
! memcmp ( V_55 . V_472 , V_470 -> V_472 . V_391 , sizeof V_470 -> V_472 . V_391 ) ) {
V_16 = 0 ;
goto V_308;
}
V_470 = F_72 ( sizeof *V_470 , V_17 ) ;
if ( ! V_470 ) {
V_16 = - V_165 ;
goto V_308;
}
V_470 -> V_153 = V_55 . V_471 ;
memcpy ( V_470 -> V_472 . V_391 , V_55 . V_472 , sizeof V_470 -> V_472 . V_391 ) ;
V_16 = F_165 ( V_40 , & V_470 -> V_472 , V_55 . V_471 ) ;
if ( ! V_16 )
F_74 ( & V_470 -> V_172 , & V_193 -> V_351 ) ;
else
F_82 ( V_470 ) ;
V_308:
F_42 ( V_40 ) ;
return V_16 ? V_16 : V_53 ;
}
T_2 F_166 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_166 V_55 ;
struct V_315 * V_193 ;
struct V_37 * V_40 ;
struct V_469 * V_470 ;
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_40 = F_40 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 )
return - V_64 ;
V_16 = F_167 ( V_40 , (union V_473 * ) V_55 . V_472 , V_55 . V_471 ) ;
if ( V_16 )
goto V_308;
V_193 = F_7 ( V_40 -> V_28 , struct V_315 , V_325 . V_28 ) ;
F_164 (mcast, &obj->mcast_list, list)
if ( V_55 . V_471 == V_470 -> V_153 &&
! memcmp ( V_55 . V_472 , V_470 -> V_472 . V_391 , sizeof V_470 -> V_472 . V_391 ) ) {
F_79 ( & V_470 -> V_172 ) ;
F_82 ( V_470 ) ;
break;
}
V_308:
F_42 ( V_40 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_168 ( struct V_474 * V_475 ,
union V_476 * V_477 )
{
if ( V_475 -> V_278 )
return - V_64 ;
V_477 -> type = V_475 -> type ;
switch ( V_477 -> type ) {
case V_478 :
V_477 -> V_479 . V_480 = sizeof( struct V_481 ) ;
if ( V_477 -> V_479 . V_480 != V_475 -> V_479 . V_480 )
return - V_64 ;
memcpy ( & V_477 -> V_479 . V_482 , & V_475 -> V_479 . V_482 ,
sizeof( struct V_483 ) ) ;
memcpy ( & V_477 -> V_479 . V_405 , & V_475 -> V_479 . V_405 ,
sizeof( struct V_483 ) ) ;
break;
case V_484 :
V_477 -> V_485 . V_480 = sizeof( struct V_486 ) ;
if ( V_477 -> V_485 . V_480 != V_475 -> V_485 . V_480 )
return - V_64 ;
memcpy ( & V_477 -> V_485 . V_482 , & V_475 -> V_485 . V_482 ,
sizeof( struct V_487 ) ) ;
memcpy ( & V_477 -> V_485 . V_405 , & V_475 -> V_485 . V_405 ,
sizeof( struct V_487 ) ) ;
break;
case V_488 :
case V_489 :
V_477 -> V_490 . V_480 = sizeof( struct V_491 ) ;
if ( V_477 -> V_490 . V_480 != V_475 -> V_490 . V_480 )
return - V_64 ;
memcpy ( & V_477 -> V_490 . V_482 , & V_475 -> V_490 . V_482 ,
sizeof( struct V_492 ) ) ;
memcpy ( & V_477 -> V_490 . V_405 , & V_475 -> V_490 . V_405 ,
sizeof( struct V_492 ) ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
int F_169 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_249 ,
struct V_58 * V_250 )
{
struct V_493 V_55 ;
struct V_494 V_57 ;
struct V_1 * V_2 ;
struct V_495 * V_496 ;
struct V_497 * V_498 ;
struct V_499 * V_500 ;
struct V_37 * V_40 ;
int V_65 = 0 ;
void * V_475 ;
void * V_477 ;
int V_426 ;
if ( V_249 -> V_276 < sizeof( V_55 ) )
return - V_64 ;
if ( V_249 -> V_279 < sizeof( V_57 ) )
return - V_62 ;
V_65 = F_124 ( & V_55 , V_249 , sizeof( V_55 ) ) ;
if ( V_65 )
return V_65 ;
V_249 -> V_501 += sizeof( V_55 ) ;
V_249 -> V_276 -= sizeof( V_55 ) ;
if ( V_55 . V_277 )
return - V_64 ;
if ( ! F_134 ( V_323 ) )
return - V_324 ;
if ( V_55 . V_500 . V_229 >= V_502 )
return - V_64 ;
if ( ( V_55 . V_500 . V_229 & V_503 ) &&
( ( V_55 . V_500 . type == V_504 ) ||
( V_55 . V_500 . type == V_505 ) ) )
return - V_64 ;
if ( V_55 . V_500 . V_506 > V_507 )
return - V_64 ;
if ( V_55 . V_500 . V_480 > V_249 -> V_276 ||
V_55 . V_500 . V_480 >
( V_55 . V_500 . V_506 * sizeof( struct V_474 ) ) )
return - V_64 ;
if ( V_55 . V_500 . V_278 [ 0 ] ||
V_55 . V_500 . V_278 [ 1 ] )
return - V_64 ;
if ( V_55 . V_500 . V_506 ) {
V_498 = F_72 ( sizeof( * V_498 ) + V_55 . V_500 . V_480 ,
V_17 ) ;
if ( ! V_498 )
return - V_165 ;
memcpy ( V_498 , & V_55 . V_500 , sizeof( * V_498 ) ) ;
V_65 = F_124 ( V_498 + 1 , V_249 ,
V_55 . V_500 . V_480 ) ;
if ( V_65 )
goto V_508;
} else {
V_498 = & V_55 . V_500 ;
}
V_2 = F_72 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 ) {
V_65 = - V_165 ;
goto V_508;
}
F_1 ( V_2 , 0 , V_49 -> V_60 , & V_509 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 ) {
V_65 = - V_64 ;
goto V_510;
}
V_500 = F_72 ( sizeof( * V_500 ) + V_55 . V_500 . V_480 , V_17 ) ;
if ( ! V_500 ) {
V_65 = - V_165 ;
goto V_174;
}
V_500 -> type = V_498 -> type ;
V_500 -> V_511 = V_498 -> V_511 ;
V_500 -> V_506 = V_498 -> V_506 ;
V_500 -> V_512 = V_498 -> V_512 ;
V_500 -> V_229 = V_498 -> V_229 ;
V_500 -> V_480 = sizeof( * V_500 ) ;
V_475 = V_498 + 1 ;
V_477 = V_500 + 1 ;
for ( V_426 = 0 ; V_426 < V_500 -> V_506 &&
V_55 . V_500 . V_480 > F_116 ( struct V_474 , V_278 ) &&
V_55 . V_500 . V_480 >=
( (struct V_474 * ) V_475 ) -> V_480 ; V_426 ++ ) {
V_65 = F_168 ( V_475 , V_477 ) ;
if ( V_65 )
goto V_94;
V_500 -> V_480 +=
( (union V_476 * ) V_477 ) -> V_480 ;
V_55 . V_500 . V_480 -= ( (struct V_474 * ) V_475 ) -> V_480 ;
V_475 += ( (struct V_474 * ) V_475 ) -> V_480 ;
V_477 += ( (union V_476 * ) V_477 ) -> V_480 ;
}
if ( V_55 . V_500 . V_480 || ( V_426 != V_500 -> V_506 ) ) {
F_170 ( L_3 ,
V_426 , V_55 . V_500 . V_480 ) ;
V_65 = - V_64 ;
goto V_94;
}
V_496 = F_171 ( V_40 , V_500 , V_513 ) ;
if ( F_51 ( V_496 ) ) {
V_65 = F_52 ( V_496 ) ;
goto V_94;
}
V_496 -> V_40 = V_40 ;
V_496 -> V_28 = V_2 ;
V_2 -> V_23 = V_496 ;
V_65 = F_14 ( & V_514 , V_2 ) ;
if ( V_65 )
goto V_515;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_516 = V_2 -> V_20 ;
V_65 = F_121 ( V_249 ,
& V_57 , sizeof( V_57 ) ) ;
if ( V_65 )
goto V_171;
F_41 ( V_40 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_77 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_82 ( V_500 ) ;
if ( V_55 . V_500 . V_506 )
F_82 ( V_498 ) ;
return 0 ;
V_171:
F_20 ( & V_514 , V_2 ) ;
V_515:
F_172 ( V_496 ) ;
V_94:
F_82 ( V_500 ) ;
V_174:
F_41 ( V_40 ) ;
V_510:
F_12 ( V_2 ) ;
V_508:
if ( V_55 . V_500 . V_506 )
F_82 ( V_498 ) ;
return V_65 ;
}
int F_173 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_249 ,
struct V_58 * V_250 )
{
struct V_517 V_55 ;
struct V_495 * V_496 ;
struct V_1 * V_2 ;
int V_16 ;
if ( V_249 -> V_276 < sizeof( V_55 ) )
return - V_64 ;
V_16 = F_124 ( & V_55 , V_249 , sizeof( V_55 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_55 . V_277 )
return - V_64 ;
V_2 = F_30 ( & V_514 , V_55 . V_516 ,
V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_496 = V_2 -> V_23 ;
V_16 = F_172 ( V_496 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_514 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_16 ;
}
static int F_174 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_518 * V_55 ,
struct V_58 * V_59 )
{
struct V_519 V_57 ;
struct V_520 * V_193 ;
struct V_24 * V_27 ;
struct V_41 * V_44 ;
struct V_1 * V_316 ( V_317 ) ;
struct V_521 V_101 ;
int V_16 ;
V_193 = F_72 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return - V_165 ;
F_1 ( & V_193 -> V_325 . V_28 , V_55 -> V_3 , V_49 -> V_60 , & V_522 ) ;
F_31 ( & V_193 -> V_325 . V_28 . V_9 ) ;
if ( V_55 -> V_332 == V_523 ) {
V_101 . V_524 . V_525 . V_179 = F_45 ( V_55 -> V_46 , V_49 -> V_60 , & V_317 ) ;
if ( ! V_101 . V_524 . V_525 . V_179 ) {
V_16 = - V_64 ;
goto V_65;
}
V_193 -> V_360 = F_7 ( V_317 , struct V_192 , V_28 ) ;
F_95 ( & V_193 -> V_360 -> V_208 ) ;
V_101 . V_524 . V_525 . V_32 = F_35 ( V_55 -> V_30 , V_49 -> V_60 , 0 ) ;
if ( ! V_101 . V_524 . V_525 . V_32 ) {
V_16 = - V_64 ;
goto V_526;
}
}
V_27 = F_33 ( V_55 -> V_25 , V_49 -> V_60 ) ;
if ( ! V_27 ) {
V_16 = - V_64 ;
goto V_527;
}
V_101 . V_268 = V_528 ;
V_101 . V_529 = V_49 ;
V_101 . V_332 = V_55 -> V_332 ;
V_101 . V_101 . V_530 = V_55 -> V_530 ;
V_101 . V_101 . V_112 = V_55 -> V_112 ;
V_101 . V_101 . V_531 = V_55 -> V_531 ;
V_193 -> V_325 . V_349 = 0 ;
F_53 ( & V_193 -> V_325 . V_350 ) ;
V_44 = V_27 -> V_68 -> V_532 ( V_27 , & V_101 , V_59 ) ;
if ( F_51 ( V_44 ) ) {
V_16 = F_52 ( V_44 ) ;
goto V_174;
}
V_44 -> V_68 = V_27 -> V_68 ;
V_44 -> V_27 = V_27 ;
V_44 -> V_332 = V_55 -> V_332 ;
V_44 -> V_28 = & V_193 -> V_325 . V_28 ;
V_44 -> V_268 = V_101 . V_268 ;
V_44 -> V_529 = V_101 . V_529 ;
if ( V_55 -> V_332 == V_523 ) {
V_44 -> V_524 . V_525 . V_32 = V_101 . V_524 . V_525 . V_32 ;
V_44 -> V_524 . V_525 . V_179 = V_101 . V_524 . V_525 . V_179 ;
F_95 ( & V_101 . V_524 . V_525 . V_32 -> V_169 ) ;
F_95 ( & V_101 . V_524 . V_525 . V_179 -> V_169 ) ;
}
F_95 ( & V_27 -> V_169 ) ;
F_73 ( & V_44 -> V_169 , 0 ) ;
V_193 -> V_325 . V_28 . V_23 = V_44 ;
V_16 = F_14 ( & V_43 , & V_193 -> V_325 . V_28 ) ;
if ( V_16 )
goto V_358;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_42 = V_193 -> V_325 . V_28 . V_20 ;
V_57 . V_530 = V_101 . V_101 . V_530 ;
V_57 . V_112 = V_101 . V_101 . V_112 ;
if ( V_55 -> V_332 == V_523 )
V_57 . V_533 = V_44 -> V_524 . V_525 . V_534 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 -> V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_171;
}
if ( V_55 -> V_332 == V_523 ) {
F_10 ( V_317 ) ;
F_36 ( V_101 . V_524 . V_525 . V_32 ) ;
}
F_34 ( V_27 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_74 ( & V_193 -> V_325 . V_28 . V_172 , & V_49 -> V_60 -> V_74 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_325 . V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_325 . V_28 . V_9 ) ;
return 0 ;
V_171:
F_20 ( & V_43 , & V_193 -> V_325 . V_28 ) ;
V_358:
F_175 ( V_44 ) ;
V_174:
F_34 ( V_27 ) ;
V_527:
if ( V_55 -> V_332 == V_523 )
F_36 ( V_101 . V_524 . V_525 . V_32 ) ;
V_526:
if ( V_55 -> V_332 == V_523 ) {
F_97 ( & V_193 -> V_360 -> V_208 ) ;
F_10 ( V_317 ) ;
}
V_65:
F_12 ( & V_193 -> V_325 . V_28 ) ;
return V_16 ;
}
T_2 F_176 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_176 V_55 ;
struct V_518 V_535 ;
struct V_519 V_57 ;
struct V_58 V_59 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_535 . V_66 = V_55 . V_66 ;
V_535 . V_3 = V_55 . V_3 ;
V_535 . V_332 = V_333 ;
V_535 . V_25 = V_55 . V_25 ;
V_535 . V_530 = V_55 . V_530 ;
V_535 . V_112 = V_55 . V_112 ;
V_535 . V_531 = V_55 . V_531 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 - sizeof( struct V_241 ) ,
V_54 - sizeof V_57 ) ;
V_16 = F_174 ( V_49 , V_51 , & V_535 , & V_59 ) ;
if ( V_16 )
return V_16 ;
return V_53 ;
}
T_2 V_518 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 , int V_54 )
{
struct V_518 V_55 ;
struct V_519 V_57 ;
struct V_58 V_59 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 - sizeof( struct V_241 ) ,
V_54 - sizeof V_57 ) ;
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
struct V_536 V_101 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 , NULL , V_53 - sizeof V_55 ,
V_54 ) ;
V_44 = F_43 ( V_55 . V_42 , V_49 -> V_60 ) ;
if ( ! V_44 )
return - V_64 ;
V_101 . V_530 = V_55 . V_530 ;
V_101 . V_531 = V_55 . V_531 ;
V_16 = V_44 -> V_68 -> V_537 ( V_44 , & V_101 , V_55 . V_368 , & V_59 ) ;
F_44 ( V_44 ) ;
return V_16 ? V_16 : V_53 ;
}
T_2 F_178 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_178 V_55 ;
struct V_538 V_57 ;
struct V_536 V_101 ;
struct V_41 * V_44 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_44 = F_43 ( V_55 . V_42 , V_49 -> V_60 ) ;
if ( ! V_44 )
return - V_64 ;
V_16 = F_179 ( V_44 , & V_101 ) ;
F_44 ( V_44 ) ;
if ( V_16 )
return V_16 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_530 = V_101 . V_530 ;
V_57 . V_112 = V_101 . V_112 ;
V_57 . V_531 = V_101 . V_531 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
return - V_63 ;
return V_53 ;
}
T_2 F_180 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_180 V_55 ;
struct V_539 V_57 ;
struct V_1 * V_2 ;
struct V_41 * V_44 ;
struct V_540 * V_193 ;
int V_16 = - V_64 ;
struct V_520 * V_541 ;
enum V_542 V_332 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_43 , V_55 . V_42 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_44 = V_2 -> V_23 ;
V_193 = F_7 ( V_2 , struct V_540 , V_28 ) ;
V_332 = V_44 -> V_332 ;
V_16 = F_175 ( V_44 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_332 == V_523 ) {
V_541 = F_7 ( V_193 , struct V_520 , V_325 ) ;
F_97 ( & V_541 -> V_360 -> V_208 ) ;
}
F_20 ( & V_43 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_79 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_151 ( V_49 , V_193 ) ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_349 = V_193 -> V_349 ;
F_8 ( V_2 ) ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
return V_16 ? V_16 : V_53 ;
}
int F_181 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_249 ,
struct V_58 * V_250 )
{
struct V_543 V_57 = { { 0 } } ;
struct F_181 V_55 ;
struct V_100 V_101 = { 0 } ;
int V_65 ;
if ( V_249 -> V_276 < sizeof( V_55 ) )
return - V_64 ;
V_65 = F_124 ( & V_55 , V_249 , sizeof( V_55 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_55 . V_277 )
return - V_64 ;
if ( V_55 . V_278 )
return - V_64 ;
V_57 . V_272 = F_116 ( F_117 ( V_57 ) , V_544 ) ;
if ( V_249 -> V_279 < V_57 . V_272 )
return - V_62 ;
V_65 = V_51 -> V_545 ( V_51 , & V_101 , V_250 ) ;
if ( V_65 )
return V_65 ;
F_65 ( V_49 , V_51 , & V_57 . V_271 , & V_101 ) ;
if ( V_249 -> V_279 < V_57 . V_272 + sizeof( V_57 . V_544 ) )
goto V_546;
#ifdef F_55
V_57 . V_544 . V_547 = V_101 . V_544 . V_547 ;
V_57 . V_544 . V_548 . V_549 =
V_101 . V_544 . V_548 . V_549 ;
V_57 . V_544 . V_548 . V_550 =
V_101 . V_544 . V_548 . V_550 ;
V_57 . V_544 . V_548 . V_551 =
V_101 . V_544 . V_548 . V_551 ;
#endif
V_57 . V_272 += sizeof( V_57 . V_544 ) ;
if ( V_249 -> V_279 < V_57 . V_272 + sizeof( V_57 . V_552 ) )
goto V_546;
V_57 . V_552 = V_101 . V_552 ;
V_57 . V_272 += sizeof( V_57 . V_552 ) ;
if ( V_249 -> V_279 < V_57 . V_272 + sizeof( V_57 . V_553 ) )
goto V_546;
V_57 . V_553 = V_101 . V_553 ;
V_57 . V_272 += sizeof( V_57 . V_553 ) ;
if ( V_249 -> V_279 < V_57 . V_272 + sizeof( V_57 . V_554 ) )
goto V_546;
V_57 . V_554 = V_101 . V_89 ;
V_57 . V_272 += sizeof( V_57 . V_554 ) ;
V_546:
V_65 = F_121 ( V_249 , & V_57 , V_57 . V_272 ) ;
return V_65 ;
}
