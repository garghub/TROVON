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
V_57 -> V_89 = V_101 -> V_89 ;
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
T_2 F_66 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_66 V_55 ;
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
T_2 F_67 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_67 V_55 ;
struct V_141 V_57 ;
struct V_142 V_101 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_16 = F_68 ( V_51 , V_55 . V_143 , & V_101 ) ;
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
V_57 . V_163 = F_69 ( V_51 ,
V_55 . V_143 ) ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
return - V_63 ;
return V_53 ;
}
T_2 F_70 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_70 V_55 ;
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
V_2 = F_71 ( sizeof *V_2 , V_17 ) ;
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
F_72 ( & V_27 -> V_169 , 0 ) ;
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
F_73 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_69 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_26 , V_2 ) ;
V_170:
F_74 ( V_27 ) ;
V_65:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_75 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_75 V_55 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_26 , V_55 . V_25 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_27 = V_2 -> V_23 ;
if ( F_76 ( & V_27 -> V_169 ) ) {
V_16 = - V_173 ;
goto V_174;
}
V_16 = V_27 -> V_68 -> V_175 ( V_2 -> V_23 ) ;
F_77 ( V_16 , L_1 ) ;
if ( V_16 )
goto V_174;
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_26 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_78 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_53 ;
V_174:
F_12 ( V_2 ) ;
return V_16 ;
}
static int F_79 ( struct V_176 * V_177 ,
struct V_178 * V_178 ,
struct V_45 * V_179 )
{
struct V_180 * V_181 , * V_182 ;
struct V_183 * * V_184 = & V_177 -> V_185 . V_183 ;
struct V_183 * V_186 = NULL ;
V_181 = F_71 ( sizeof *V_181 , V_17 ) ;
if ( ! V_181 )
return - V_165 ;
V_181 -> V_179 = V_179 ;
V_181 -> V_178 = V_178 ;
while ( * V_184 ) {
V_186 = * V_184 ;
V_182 = F_80 ( V_186 , struct V_180 , V_187 ) ;
if ( V_178 < V_182 -> V_178 ) {
V_184 = & ( * V_184 ) -> V_188 ;
} else if ( V_178 > V_182 -> V_178 ) {
V_184 = & ( * V_184 ) -> V_189 ;
} else {
F_81 ( V_181 ) ;
return - V_190 ;
}
}
F_82 ( & V_181 -> V_187 , V_186 , V_184 ) ;
F_83 ( & V_181 -> V_187 , & V_177 -> V_185 ) ;
F_84 ( V_178 ) ;
return 0 ;
}
static struct V_180 * F_85 ( struct V_176 * V_177 ,
struct V_178 * V_178 )
{
struct V_180 * V_181 ;
struct V_183 * V_184 = V_177 -> V_185 . V_183 ;
while ( V_184 ) {
V_181 = F_80 ( V_184 , struct V_180 , V_187 ) ;
if ( V_178 < V_181 -> V_178 )
V_184 = V_184 -> V_188 ;
else if ( V_178 > V_181 -> V_178 )
V_184 = V_184 -> V_189 ;
else
return V_181 ;
}
return NULL ;
}
static struct V_45 * F_86 ( struct V_176 * V_177 , struct V_178 * V_178 )
{
struct V_180 * V_181 ;
V_181 = F_85 ( V_177 , V_178 ) ;
if ( ! V_181 )
return NULL ;
return V_181 -> V_179 ;
}
static void F_87 ( struct V_176 * V_177 ,
struct V_178 * V_178 )
{
struct V_180 * V_181 ;
V_181 = F_85 ( V_177 , V_178 ) ;
if ( V_181 ) {
F_88 ( V_178 ) ;
F_89 ( & V_181 -> V_187 , & V_177 -> V_185 ) ;
F_81 ( V_181 ) ;
}
}
T_2 F_90 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_90 V_55 ;
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
V_195 = F_91 ( V_55 . V_194 ) ;
if ( ! V_195 . V_49 ) {
V_16 = - V_198 ;
goto V_199;
}
V_178 = F_92 ( V_195 . V_49 ) ;
V_179 = F_86 ( V_49 -> V_68 , V_178 ) ;
if ( ! V_179 && ! ( V_55 . V_200 & V_201 ) ) {
V_16 = - V_202 ;
goto V_199;
}
if ( V_179 && V_55 . V_200 & V_203 ) {
V_16 = - V_64 ;
goto V_199;
}
}
V_193 = F_71 ( sizeof *V_193 , V_17 ) ;
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
F_72 ( & V_179 -> V_169 , 0 ) ;
F_93 ( & V_179 -> V_206 ) ;
F_53 ( & V_179 -> V_207 ) ;
V_196 = 1 ;
}
F_72 ( & V_193 -> V_208 , 0 ) ;
V_193 -> V_28 . V_23 = V_179 ;
V_16 = F_14 ( & V_47 , & V_193 -> V_28 ) ;
if ( V_16 )
goto V_170;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_46 = V_193 -> V_28 . V_20 ;
if ( V_178 ) {
if ( V_196 ) {
V_16 = F_79 ( V_49 -> V_68 , V_178 , V_179 ) ;
if ( V_16 )
goto V_209;
}
F_94 ( & V_179 -> V_169 ) ;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_171;
}
if ( V_195 . V_49 )
F_95 ( V_195 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_73 ( & V_193 -> V_28 . V_172 , & V_49 -> V_60 -> V_76 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_28 . V_9 ) ;
F_60 ( & V_49 -> V_68 -> V_197 ) ;
return V_53 ;
V_171:
if ( V_178 ) {
if ( V_196 )
F_87 ( V_49 -> V_68 , V_178 ) ;
F_96 ( & V_179 -> V_169 ) ;
}
V_209:
F_20 ( & V_47 , & V_193 -> V_28 ) ;
V_170:
F_97 ( V_179 ) ;
V_65:
F_12 ( & V_193 -> V_28 ) ;
V_199:
if ( V_195 . V_49 )
F_95 ( V_195 ) ;
F_60 ( & V_49 -> V_68 -> V_197 ) ;
return V_16 ;
}
T_2 F_98 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_98 V_55 ;
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
if ( F_76 ( & V_193 -> V_208 ) ) {
F_12 ( V_2 ) ;
V_16 = - V_173 ;
goto V_210;
}
if ( ! V_178 || F_99 ( & V_179 -> V_169 ) ) {
V_16 = F_97 ( V_2 -> V_23 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
}
V_12 = V_2 -> V_12 ;
if ( V_178 && V_16 )
F_94 ( & V_179 -> V_169 ) ;
F_12 ( V_2 ) ;
if ( V_16 )
goto V_210;
if ( V_178 && ! V_12 )
F_87 ( V_49 -> V_68 , V_178 ) ;
F_20 ( & V_47 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_78 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
V_16 = V_53 ;
V_210:
F_60 ( & V_49 -> V_68 -> V_197 ) ;
return V_16 ;
}
void F_100 ( struct V_176 * V_177 ,
struct V_45 * V_179 )
{
struct V_178 * V_178 ;
V_178 = V_179 -> V_178 ;
if ( V_178 && ! F_99 ( & V_179 -> V_169 ) )
return;
F_97 ( V_179 ) ;
if ( V_178 )
F_87 ( V_177 , V_178 ) ;
}
T_2 F_101 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_101 V_55 ;
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
V_16 = F_102 ( V_55 . V_217 ) ;
if ( V_16 )
return V_16 ;
V_2 = F_71 ( sizeof *V_2 , V_17 ) ;
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
F_103 ( L_2 ) ;
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
F_94 ( & V_27 -> V_169 ) ;
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
F_73 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_70 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_222 , V_2 ) ;
V_223:
F_104 ( V_213 ) ;
V_174:
F_34 ( V_27 ) ;
V_94:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_105 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_105 V_55 ;
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
V_16 = F_102 ( V_55 . V_217 ) ;
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
F_94 ( & V_27 -> V_169 ) ;
V_213 -> V_27 = V_27 ;
F_96 ( & V_228 -> V_169 ) ;
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
T_2 F_106 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_106 V_55 ;
struct V_212 * V_213 ;
struct V_1 * V_2 ;
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_222 , V_55 . V_226 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_213 = V_2 -> V_23 ;
V_16 = F_104 ( V_213 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_222 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_78 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_53 ;
}
T_2 F_107 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_107 V_55 ;
struct V_237 V_57 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_238 * V_239 ;
int V_16 ;
if ( V_54 < sizeof( V_57 ) )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_63 ;
V_2 = F_71 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , 0 , V_49 -> V_60 , & V_240 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_60 ) ;
if ( ! V_27 ) {
V_16 = - V_64 ;
goto V_94;
}
V_239 = V_27 -> V_68 -> V_241 ( V_27 , V_55 . V_242 ) ;
if ( F_51 ( V_239 ) ) {
V_16 = F_52 ( V_239 ) ;
goto V_174;
}
V_239 -> V_68 = V_27 -> V_68 ;
V_239 -> V_27 = V_27 ;
V_239 -> V_28 = V_2 ;
F_94 ( & V_27 -> V_169 ) ;
V_2 -> V_23 = V_239 ;
V_16 = F_14 ( & V_243 , V_2 ) ;
if ( V_16 )
goto V_244;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_225 = V_239 -> V_225 ;
V_57 . V_245 = V_2 -> V_20 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof( V_57 ) ) ) {
V_16 = - V_63 ;
goto V_171;
}
F_34 ( V_27 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_73 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_71 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_243 , V_2 ) ;
V_244:
F_108 ( V_239 ) ;
V_174:
F_34 ( V_27 ) ;
V_94:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_109 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_109 V_55 ;
struct V_238 * V_239 ;
struct V_1 * V_2 ;
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_63 ;
V_2 = F_30 ( & V_243 , V_55 . V_245 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_239 = V_2 -> V_23 ;
V_16 = F_108 ( V_239 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_243 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_78 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_53 ;
}
T_2 F_110 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_110 V_55 ;
struct V_246 V_57 ;
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
static struct V_247 * F_111 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 ,
struct V_250 * V_55 ,
T_4 V_251 ,
int (* F_112)( struct V_48 * V_49 ,
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
if ( V_55 -> V_256 >= V_49 -> V_68 -> V_92 )
return F_113 ( - V_64 ) ;
V_193 = F_71 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return F_113 ( - V_165 ) ;
F_1 ( & V_193 -> V_28 , V_55 -> V_3 , V_49 -> V_60 , & V_257 ) ;
F_31 ( & V_193 -> V_28 . V_9 ) ;
if ( V_55 -> V_258 >= 0 ) {
V_254 = F_114 ( V_55 -> V_258 ) ;
if ( ! V_254 ) {
V_16 = - V_64 ;
goto V_65;
}
}
V_193 -> V_259 = V_49 ;
V_193 -> V_260 = 0 ;
V_193 -> V_261 = 0 ;
F_53 ( & V_193 -> V_262 ) ;
F_53 ( & V_193 -> V_263 ) ;
V_101 . V_264 = V_55 -> V_264 ;
V_101 . V_256 = V_55 -> V_256 ;
if ( V_251 > F_115 ( F_116 ( * V_55 ) , V_229 ) + sizeof( V_55 -> V_229 ) )
V_101 . V_229 = V_55 -> V_229 ;
V_32 = V_51 -> F_111 ( V_51 , & V_101 ,
V_49 -> V_60 , V_249 ) ;
if ( F_51 ( V_32 ) ) {
V_16 = F_52 ( V_32 ) ;
goto V_97;
}
V_32 -> V_68 = V_51 ;
V_32 -> V_28 = & V_193 -> V_28 ;
V_32 -> V_265 = V_266 ;
V_32 -> V_267 = V_268 ;
V_32 -> V_269 = V_254 ;
F_72 ( & V_32 -> V_169 , 0 ) ;
V_193 -> V_28 . V_23 = V_32 ;
V_16 = F_14 ( & V_31 , & V_193 -> V_28 ) ;
if ( V_16 )
goto V_94;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_270 . V_30 = V_193 -> V_28 . V_20 ;
V_57 . V_270 . V_264 = V_32 -> V_264 ;
V_57 . V_271 = F_115 ( F_116 ( V_57 ) , V_271 ) +
sizeof( V_57 . V_271 ) ;
V_16 = F_112 ( V_49 , V_193 , & V_57 , V_248 , V_5 ) ;
if ( V_16 )
goto V_272;
F_49 ( & V_49 -> V_9 ) ;
F_73 ( & V_193 -> V_28 . V_172 , & V_49 -> V_60 -> V_72 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_28 . V_9 ) ;
return V_193 ;
V_272:
F_20 ( & V_31 , & V_193 -> V_28 ) ;
V_94:
F_117 ( V_32 ) ;
V_97:
if ( V_254 )
F_118 ( V_49 , V_254 , V_193 ) ;
V_65:
F_12 ( & V_193 -> V_28 ) ;
return F_113 ( V_16 ) ;
}
static int F_119 ( struct V_48 * V_49 ,
struct V_247 * V_193 ,
struct V_252 * V_57 ,
struct V_58 * V_248 , void * V_5 )
{
if ( F_120 ( V_248 , & V_57 -> V_270 , sizeof( V_57 -> V_270 ) ) )
return - V_63 ;
return 0 ;
}
T_2 F_121 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_121 V_55 ;
struct V_250 V_273 ;
struct V_274 V_57 ;
struct V_58 V_248 ;
struct V_58 V_249 ;
struct V_247 * V_193 ;
if ( V_54 < sizeof( V_57 ) )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_63 ;
F_50 ( & V_248 , V_52 , ( unsigned long ) V_55 . V_66 , sizeof( V_55 ) , sizeof( V_57 ) ) ;
F_50 ( & V_249 , V_52 + sizeof( V_55 ) ,
( unsigned long ) V_55 . V_66 + sizeof( V_57 ) ,
V_53 - sizeof( V_55 ) , V_54 - sizeof( V_57 ) ) ;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_3 = V_55 . V_3 ;
V_273 . V_264 = V_55 . V_264 ;
V_273 . V_256 = V_55 . V_256 ;
V_273 . V_258 = V_55 . V_258 ;
V_193 = F_111 ( V_49 , V_51 , & V_248 , & V_249 , & V_273 ,
F_115 ( F_116 ( V_273 ) , V_258 ) +
sizeof( V_55 . V_258 ) , F_119 ,
NULL ) ;
if ( F_51 ( V_193 ) )
return F_52 ( V_193 ) ;
return V_53 ;
}
static int F_122 ( struct V_48 * V_49 ,
struct V_247 * V_193 ,
struct V_252 * V_57 ,
struct V_58 * V_248 , void * V_5 )
{
if ( F_120 ( V_248 , V_57 , V_57 -> V_271 ) )
return - V_63 ;
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
int V_65 ;
if ( V_248 -> V_275 < sizeof( V_55 ) )
return - V_64 ;
V_65 = F_123 ( & V_55 , V_248 , sizeof( V_55 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_55 . V_276 )
return - V_64 ;
if ( V_55 . V_277 )
return - V_64 ;
if ( V_248 -> V_278 < ( F_115 ( F_116 ( V_57 ) , V_271 ) +
sizeof( V_57 . V_271 ) ) )
return - V_62 ;
V_193 = F_111 ( V_49 , V_51 , V_248 , V_249 , & V_55 ,
F_124 ( V_248 -> V_275 , sizeof( V_55 ) ) ,
F_122 , NULL ) ;
if ( F_51 ( V_193 ) )
return F_52 ( V_193 ) ;
return 0 ;
}
T_2 F_125 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_125 V_55 ;
struct V_279 V_57 ;
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
V_16 = V_32 -> V_68 -> V_280 ( V_32 , V_55 . V_264 , & V_59 ) ;
if ( V_16 )
goto V_210;
V_57 . V_264 = V_32 -> V_264 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 . V_264 ) )
V_16 = - V_63 ;
V_210:
F_36 ( V_32 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_126 ( void T_3 * V_281 , struct V_282 * V_283 )
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
if ( F_58 ( V_281 , & V_285 , sizeof V_285 ) )
return - V_63 ;
return 0 ;
}
T_2 F_127 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_127 V_55 ;
struct V_302 V_57 ;
T_5 T_3 * V_303 ;
T_5 T_3 * V_304 ;
struct V_29 * V_32 ;
struct V_282 V_283 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_32 = F_35 ( V_55 . V_30 , V_49 -> V_60 , 0 ) ;
if ( ! V_32 )
return - V_64 ;
V_303 = ( void T_3 * ) ( unsigned long ) V_55 . V_66 ;
V_304 = V_303 + sizeof V_57 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
while ( V_57 . V_305 < V_55 . V_306 ) {
V_16 = F_128 ( V_32 , 1 , & V_283 ) ;
if ( V_16 < 0 )
goto V_307;
if ( ! V_16 )
break;
V_16 = F_126 ( V_304 , & V_283 ) ;
if ( V_16 )
goto V_307;
V_304 += sizeof( struct V_284 ) ;
++ V_57 . V_305 ;
}
if ( F_58 ( V_303 , & V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_307;
}
V_16 = V_53 ;
V_307:
F_36 ( V_32 ) ;
return V_16 ;
}
T_2 F_129 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_129 V_55 ;
struct V_29 * V_32 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_32 = F_35 ( V_55 . V_30 , V_49 -> V_60 , 0 ) ;
if ( ! V_32 )
return - V_64 ;
F_130 ( V_32 , V_55 . V_308 ?
V_309 : V_310 ) ;
F_36 ( V_32 ) ;
return V_53 ;
}
T_2 F_131 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_131 V_55 ;
struct V_311 V_57 ;
struct V_1 * V_2 ;
struct V_29 * V_32 ;
struct V_247 * V_193 ;
struct V_253 * V_254 ;
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_31 , V_55 . V_30 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_32 = V_2 -> V_23 ;
V_254 = V_32 -> V_269 ;
V_193 = F_7 ( V_32 -> V_28 , struct V_247 , V_28 ) ;
V_16 = F_117 ( V_32 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_31 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_78 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_118 ( V_49 , V_254 , V_193 ) ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_260 = V_193 -> V_260 ;
V_57 . V_261 = V_193 -> V_261 ;
F_8 ( V_2 ) ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
return - V_63 ;
return V_53 ;
}
static int F_132 ( struct V_48 * V_49 ,
struct V_58 * V_248 ,
struct V_58 * V_249 ,
struct V_312 * V_55 ,
T_4 V_251 ,
int (* F_112)( struct V_48 * V_49 ,
struct V_313 * V_57 ,
struct V_58 * V_59 ) ,
void * V_5 )
{
struct V_314 * V_193 ;
struct V_50 * V_68 ;
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
if ( V_55 -> V_320 == V_321 && ! F_133 ( V_322 ) )
return - V_323 ;
V_193 = F_134 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return - V_165 ;
F_1 ( & V_193 -> V_324 . V_28 , V_55 -> V_3 , V_49 -> V_60 ,
& V_325 ) ;
F_31 ( & V_193 -> V_324 . V_28 . V_9 ) ;
if ( V_55 -> V_320 == V_326 ) {
V_179 = F_45 ( V_55 -> V_25 , V_49 -> V_60 ,
& V_316 ) ;
if ( ! V_179 ) {
V_16 = - V_64 ;
goto V_174;
}
V_68 = V_179 -> V_68 ;
} else {
if ( V_55 -> V_320 == V_327 ) {
V_55 -> V_328 = 0 ;
V_55 -> V_329 = 0 ;
} else {
if ( V_55 -> V_330 ) {
V_44 = F_43 ( V_55 -> V_42 ,
V_49 -> V_60 ) ;
if ( ! V_44 || V_44 -> V_331 != V_332 ) {
V_16 = - V_64 ;
goto V_174;
}
}
if ( V_55 -> V_333 != V_55 -> V_334 ) {
V_318 = F_35 ( V_55 -> V_333 ,
V_49 -> V_60 , 0 ) ;
if ( ! V_318 ) {
V_16 = - V_64 ;
goto V_174;
}
}
}
V_317 = F_35 ( V_55 -> V_334 , V_49 -> V_60 , ! ! V_318 ) ;
V_318 = V_318 ? : V_317 ;
V_27 = F_33 ( V_55 -> V_25 , V_49 -> V_60 ) ;
if ( ! V_27 || ! V_317 ) {
V_16 = - V_64 ;
goto V_174;
}
V_68 = V_27 -> V_68 ;
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
F_53 ( & V_193 -> V_324 . V_349 ) ;
F_53 ( & V_193 -> V_350 ) ;
if ( V_251 >= F_115 ( F_116 ( * V_55 ) , V_343 ) +
sizeof( V_55 -> V_343 ) )
V_101 . V_343 = V_55 -> V_343 ;
if ( V_101 . V_343 & ~ ( V_351 |
V_352 |
V_353 |
V_354 ) ) {
V_16 = - V_64 ;
goto V_174;
}
V_52 = ( void * ) V_55 + sizeof( * V_55 ) ;
if ( V_251 > sizeof( * V_55 ) )
if ( ! ( V_52 [ 0 ] == 0 && ! memcmp ( V_52 , V_52 + 1 ,
V_251 - sizeof( * V_55 ) - 1 ) ) ) {
V_16 = - V_64 ;
goto V_174;
}
if ( V_55 -> V_320 == V_326 )
V_40 = F_135 ( V_27 , & V_101 ) ;
else
V_40 = V_68 -> F_132 ( V_27 , & V_101 , V_249 ) ;
if ( F_51 ( V_40 ) ) {
V_16 = F_52 ( V_40 ) ;
goto V_174;
}
if ( V_55 -> V_320 != V_326 ) {
V_40 -> V_355 = V_40 ;
V_40 -> V_68 = V_68 ;
V_40 -> V_27 = V_27 ;
V_40 -> V_337 = V_101 . V_337 ;
V_40 -> V_338 = V_101 . V_338 ;
V_40 -> V_44 = V_101 . V_44 ;
V_40 -> V_267 = V_101 . V_267 ;
V_40 -> V_336 = V_101 . V_336 ;
V_40 -> V_320 = V_101 . V_320 ;
F_72 ( & V_40 -> V_169 , 0 ) ;
F_94 ( & V_27 -> V_169 ) ;
F_94 ( & V_101 . V_337 -> V_169 ) ;
if ( V_101 . V_338 )
F_94 ( & V_101 . V_338 -> V_169 ) ;
if ( V_101 . V_44 )
F_94 ( & V_101 . V_44 -> V_169 ) ;
}
V_40 -> V_28 = & V_193 -> V_324 . V_28 ;
V_193 -> V_324 . V_28 . V_23 = V_40 ;
V_16 = F_14 ( & V_39 , & V_193 -> V_324 . V_28 ) ;
if ( V_16 )
goto V_356;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_270 . V_357 = V_40 -> V_295 ;
V_57 . V_270 . V_38 = V_193 -> V_324 . V_28 . V_20 ;
V_57 . V_270 . V_329 = V_101 . V_344 . V_329 ;
V_57 . V_270 . V_346 = V_101 . V_344 . V_346 ;
V_57 . V_270 . V_328 = V_101 . V_344 . V_328 ;
V_57 . V_270 . V_345 = V_101 . V_344 . V_345 ;
V_57 . V_270 . V_347 = V_101 . V_344 . V_347 ;
V_57 . V_271 = F_115 ( F_116 ( V_57 ) , V_271 ) +
sizeof( V_57 . V_271 ) ;
V_16 = F_112 ( V_49 , & V_57 , V_248 ) ;
if ( V_16 )
goto V_272;
if ( V_179 ) {
V_193 -> V_358 = F_7 ( V_316 , struct V_192 ,
V_28 ) ;
F_94 ( & V_193 -> V_358 -> V_208 ) ;
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
F_49 ( & V_49 -> V_9 ) ;
F_73 ( & V_193 -> V_324 . V_28 . V_172 , & V_49 -> V_60 -> V_73 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_324 . V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_324 . V_28 . V_9 ) ;
return 0 ;
V_272:
F_20 ( & V_39 , & V_193 -> V_324 . V_28 ) ;
V_356:
F_136 ( V_40 ) ;
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
static int F_137 ( struct V_48 * V_49 ,
struct V_313 * V_57 ,
struct V_58 * V_248 )
{
if ( F_120 ( V_248 , & V_57 -> V_270 , sizeof( V_57 -> V_270 ) ) )
return - V_63 ;
return 0 ;
}
T_2 F_138 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_138 V_55 ;
struct V_312 V_273 ;
struct V_58 V_248 ;
struct V_58 V_249 ;
T_2 V_359 = sizeof( struct V_360 ) ;
int V_65 ;
if ( V_54 < V_359 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof( V_55 ) ) )
return - V_63 ;
F_50 ( & V_248 , V_52 , ( unsigned long ) V_55 . V_66 , sizeof( V_55 ) ,
V_359 ) ;
F_50 ( & V_249 , V_52 + sizeof( V_55 ) ,
( unsigned long ) V_55 . V_66 + V_359 ,
V_53 - sizeof( V_55 ) - sizeof( struct V_361 ) ,
V_54 - V_359 ) ;
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
V_65 = F_132 ( V_49 , & V_248 , & V_249 , & V_273 ,
F_115 ( F_116 ( V_273 ) , V_330 ) +
sizeof( V_55 . V_330 ) , F_137 ,
NULL ) ;
if ( V_65 )
return V_65 ;
return V_53 ;
}
static int F_139 ( struct V_48 * V_49 ,
struct V_313 * V_57 ,
struct V_58 * V_248 )
{
if ( F_120 ( V_248 , V_57 , V_57 -> V_271 ) )
return - V_63 ;
return 0 ;
}
int V_312 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 )
{
struct V_313 V_57 ;
struct V_312 V_55 = { 0 } ;
int V_65 ;
if ( V_248 -> V_275 < ( F_115 ( F_116 ( V_55 ) , V_276 ) +
sizeof( V_55 . V_276 ) ) )
return - V_64 ;
V_65 = F_123 ( & V_55 , V_248 , F_124 ( sizeof( V_55 ) , V_248 -> V_275 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_55 . V_276 )
return - V_64 ;
if ( V_55 . V_277 )
return - V_64 ;
if ( V_248 -> V_278 < ( F_115 ( F_116 ( V_57 ) , V_271 ) +
sizeof( V_57 . V_271 ) ) )
return - V_62 ;
V_65 = F_132 ( V_49 , V_248 , V_249 , & V_55 ,
F_124 ( V_248 -> V_275 , sizeof( V_55 ) ) ,
F_139 , NULL ) ;
if ( V_65 )
return V_65 ;
return 0 ;
}
T_2 F_140 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 , int V_54 )
{
struct F_140 V_55 ;
struct V_360 V_57 ;
struct V_58 V_59 ;
struct V_314 * V_193 ;
struct V_45 * V_179 ;
struct V_1 * V_315 ( V_316 ) ;
struct V_37 * V_40 ;
struct V_362 V_101 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 , V_54 - sizeof V_57 ) ;
V_193 = F_71 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return - V_165 ;
F_1 ( & V_193 -> V_324 . V_28 , V_55 . V_3 , V_49 -> V_60 , & V_325 ) ;
F_31 ( & V_193 -> V_324 . V_28 . V_9 ) ;
V_179 = F_45 ( V_55 . V_25 , V_49 -> V_60 , & V_316 ) ;
if ( ! V_179 ) {
V_16 = - V_64 ;
goto V_174;
}
V_101 . V_267 = V_335 ;
V_101 . V_336 = V_49 ;
V_101 . V_295 = V_55 . V_357 ;
V_101 . V_320 = V_55 . V_320 ;
V_193 -> V_324 . V_348 = 0 ;
F_53 ( & V_193 -> V_324 . V_349 ) ;
F_53 ( & V_193 -> V_350 ) ;
V_40 = F_141 ( V_179 , & V_101 ) ;
if ( F_51 ( V_40 ) ) {
V_16 = F_52 ( V_40 ) ;
goto V_174;
}
V_40 -> V_28 = & V_193 -> V_324 . V_28 ;
V_193 -> V_324 . V_28 . V_23 = V_40 ;
V_16 = F_14 ( & V_39 , & V_193 -> V_324 . V_28 ) ;
if ( V_16 )
goto V_356;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_357 = V_40 -> V_295 ;
V_57 . V_38 = V_193 -> V_324 . V_28 . V_20 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_363;
}
V_193 -> V_358 = F_7 ( V_316 , struct V_192 , V_28 ) ;
F_94 ( & V_193 -> V_358 -> V_208 ) ;
F_46 ( V_316 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_73 ( & V_193 -> V_324 . V_28 . V_172 , & V_49 -> V_60 -> V_73 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_324 . V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_324 . V_28 . V_9 ) ;
return V_53 ;
V_363:
F_20 ( & V_39 , & V_193 -> V_324 . V_28 ) ;
V_356:
F_136 ( V_40 ) ;
V_174:
F_46 ( V_316 ) ;
F_12 ( & V_193 -> V_324 . V_28 ) ;
return V_16 ;
}
T_2 F_142 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_142 V_55 ;
struct V_364 V_57 ;
struct V_37 * V_40 ;
struct V_365 * V_101 ;
struct V_319 * V_366 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_101 = F_71 ( sizeof *V_101 , V_17 ) ;
V_366 = F_71 ( sizeof *V_366 , V_17 ) ;
if ( ! V_101 || ! V_366 ) {
V_16 = - V_165 ;
goto V_210;
}
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 ) {
V_16 = - V_64 ;
goto V_210;
}
V_16 = F_143 ( V_40 , V_101 , V_55 . V_367 , V_366 ) ;
F_41 ( V_40 ) ;
if ( V_16 )
goto V_210;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_368 = V_101 -> V_368 ;
V_57 . V_369 = V_101 -> V_369 ;
V_57 . V_370 = V_101 -> V_370 ;
V_57 . V_371 = V_101 -> V_371 ;
V_57 . V_372 = V_101 -> V_372 ;
V_57 . V_373 = V_101 -> V_373 ;
V_57 . V_374 = V_101 -> V_374 ;
V_57 . V_375 = V_101 -> V_375 ;
V_57 . V_376 = V_101 -> V_376 ;
V_57 . V_298 = V_101 -> V_298 ;
V_57 . V_377 = V_101 -> V_377 ;
V_57 . V_378 = V_101 -> V_378 ;
V_57 . V_379 = V_101 -> V_379 ;
V_57 . V_380 = V_101 -> V_380 ;
V_57 . V_381 = V_101 -> V_381 ;
V_57 . V_143 = V_101 -> V_143 ;
V_57 . V_382 = V_101 -> V_382 ;
V_57 . V_383 = V_101 -> V_383 ;
V_57 . V_384 = V_101 -> V_384 ;
V_57 . V_385 = V_101 -> V_385 ;
V_57 . V_386 = V_101 -> V_386 ;
memcpy ( V_57 . V_281 . V_387 , V_101 -> V_388 . V_389 . V_387 . V_390 , 16 ) ;
V_57 . V_281 . V_391 = V_101 -> V_388 . V_389 . V_391 ;
V_57 . V_281 . V_392 = V_101 -> V_388 . V_389 . V_392 ;
V_57 . V_281 . V_393 = V_101 -> V_388 . V_389 . V_393 ;
V_57 . V_281 . V_394 = V_101 -> V_388 . V_389 . V_394 ;
V_57 . V_281 . V_395 = V_101 -> V_388 . V_395 ;
V_57 . V_281 . V_300 = V_101 -> V_388 . V_300 ;
V_57 . V_281 . V_396 = V_101 -> V_388 . V_396 ;
V_57 . V_281 . V_397 = V_101 -> V_388 . V_397 ;
V_57 . V_281 . V_398 = ! ! ( V_101 -> V_388 . V_399 & V_400 ) ;
V_57 . V_281 . V_143 = V_101 -> V_388 . V_143 ;
memcpy ( V_57 . V_401 . V_387 , V_101 -> V_402 . V_389 . V_387 . V_390 , 16 ) ;
V_57 . V_401 . V_391 = V_101 -> V_402 . V_389 . V_391 ;
V_57 . V_401 . V_392 = V_101 -> V_402 . V_389 . V_392 ;
V_57 . V_401 . V_393 = V_101 -> V_402 . V_389 . V_393 ;
V_57 . V_401 . V_394 = V_101 -> V_402 . V_389 . V_394 ;
V_57 . V_401 . V_395 = V_101 -> V_402 . V_395 ;
V_57 . V_401 . V_300 = V_101 -> V_402 . V_300 ;
V_57 . V_401 . V_396 = V_101 -> V_402 . V_396 ;
V_57 . V_401 . V_397 = V_101 -> V_402 . V_397 ;
V_57 . V_401 . V_398 = ! ! ( V_101 -> V_402 . V_399 & V_400 ) ;
V_57 . V_401 . V_143 = V_101 -> V_402 . V_143 ;
V_57 . V_345 = V_366 -> V_344 . V_345 ;
V_57 . V_328 = V_366 -> V_344 . V_328 ;
V_57 . V_346 = V_366 -> V_344 . V_346 ;
V_57 . V_329 = V_366 -> V_344 . V_329 ;
V_57 . V_347 = V_366 -> V_344 . V_347 ;
V_57 . V_340 = V_366 -> V_339 == V_341 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
V_210:
F_81 ( V_101 ) ;
F_81 ( V_366 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_144 ( enum V_403 V_320 , int V_404 )
{
switch ( V_320 ) {
case V_327 :
return V_404 & ~ ( V_405 | V_406 ) ;
case V_326 :
return V_404 & ~ ( V_407 | V_408 |
V_409 ) ;
default:
return V_404 ;
}
}
T_2 F_145 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_145 V_55 ;
struct V_58 V_59 ;
struct V_37 * V_40 ;
struct V_365 * V_101 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 , NULL , V_53 - sizeof V_55 ,
V_54 ) ;
V_101 = F_71 ( sizeof *V_101 , V_17 ) ;
if ( ! V_101 )
return - V_165 ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 ) {
V_16 = - V_64 ;
goto V_210;
}
V_101 -> V_368 = V_55 . V_368 ;
V_101 -> V_369 = V_55 . V_369 ;
V_101 -> V_370 = V_55 . V_370 ;
V_101 -> V_371 = V_55 . V_371 ;
V_101 -> V_372 = V_55 . V_372 ;
V_101 -> V_373 = V_55 . V_373 ;
V_101 -> V_374 = V_55 . V_374 ;
V_101 -> V_375 = V_55 . V_375 ;
V_101 -> V_376 = V_55 . V_376 ;
V_101 -> V_298 = V_55 . V_298 ;
V_101 -> V_377 = V_55 . V_377 ;
V_101 -> V_410 = V_55 . V_410 ;
V_101 -> V_379 = V_55 . V_379 ;
V_101 -> V_380 = V_55 . V_380 ;
V_101 -> V_381 = V_55 . V_381 ;
V_101 -> V_143 = V_55 . V_143 ;
V_101 -> V_382 = V_55 . V_382 ;
V_101 -> V_383 = V_55 . V_383 ;
V_101 -> V_384 = V_55 . V_384 ;
V_101 -> V_385 = V_55 . V_385 ;
V_101 -> V_386 = V_55 . V_386 ;
memcpy ( V_101 -> V_388 . V_389 . V_387 . V_390 , V_55 . V_281 . V_387 , 16 ) ;
V_101 -> V_388 . V_389 . V_391 = V_55 . V_281 . V_391 ;
V_101 -> V_388 . V_389 . V_392 = V_55 . V_281 . V_392 ;
V_101 -> V_388 . V_389 . V_393 = V_55 . V_281 . V_393 ;
V_101 -> V_388 . V_389 . V_394 = V_55 . V_281 . V_394 ;
V_101 -> V_388 . V_395 = V_55 . V_281 . V_395 ;
V_101 -> V_388 . V_300 = V_55 . V_281 . V_300 ;
V_101 -> V_388 . V_396 = V_55 . V_281 . V_396 ;
V_101 -> V_388 . V_397 = V_55 . V_281 . V_397 ;
V_101 -> V_388 . V_399 = V_55 . V_281 . V_398 ? V_400 : 0 ;
V_101 -> V_388 . V_143 = V_55 . V_281 . V_143 ;
memcpy ( V_101 -> V_402 . V_389 . V_387 . V_390 , V_55 . V_401 . V_387 , 16 ) ;
V_101 -> V_402 . V_389 . V_391 = V_55 . V_401 . V_391 ;
V_101 -> V_402 . V_389 . V_392 = V_55 . V_401 . V_392 ;
V_101 -> V_402 . V_389 . V_393 = V_55 . V_401 . V_393 ;
V_101 -> V_402 . V_389 . V_394 = V_55 . V_401 . V_394 ;
V_101 -> V_402 . V_395 = V_55 . V_401 . V_395 ;
V_101 -> V_402 . V_300 = V_55 . V_401 . V_300 ;
V_101 -> V_402 . V_396 = V_55 . V_401 . V_396 ;
V_101 -> V_402 . V_397 = V_55 . V_401 . V_397 ;
V_101 -> V_402 . V_399 = V_55 . V_401 . V_398 ? V_400 : 0 ;
V_101 -> V_402 . V_143 = V_55 . V_401 . V_143 ;
if ( V_40 -> V_355 == V_40 ) {
V_16 = F_146 ( V_40 , V_101 , & V_55 . V_367 ) ;
if ( V_16 )
goto V_411;
V_16 = V_40 -> V_68 -> V_412 ( V_40 , V_101 ,
F_144 ( V_40 -> V_320 , V_55 . V_367 ) , & V_59 ) ;
} else {
V_16 = F_147 ( V_40 , V_101 , F_144 ( V_40 -> V_320 , V_55 . V_367 ) ) ;
}
if ( V_16 )
goto V_411;
V_16 = V_53 ;
V_411:
F_41 ( V_40 ) ;
V_210:
F_81 ( V_101 ) ;
return V_16 ;
}
T_2 F_148 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_148 V_55 ;
struct V_413 V_57 ;
struct V_1 * V_2 ;
struct V_37 * V_40 ;
struct V_314 * V_193 ;
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_2 = F_30 ( & V_39 , V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_40 = V_2 -> V_23 ;
V_193 = F_7 ( V_2 , struct V_314 , V_324 . V_28 ) ;
if ( ! F_149 ( & V_193 -> V_350 ) ) {
F_12 ( V_2 ) ;
return - V_173 ;
}
V_16 = F_136 ( V_40 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_193 -> V_358 )
F_96 ( & V_193 -> V_358 -> V_208 ) ;
F_20 ( & V_39 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_78 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_150 ( V_49 , & V_193 -> V_324 ) ;
V_57 . V_348 = V_193 -> V_324 . V_348 ;
F_8 ( V_2 ) ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
return - V_63 ;
return V_53 ;
}
static void * F_151 ( T_4 V_414 , V_293 V_415 )
{
return F_71 ( F_152 ( V_414 , sizeof ( struct V_416 ) ) +
V_415 * sizeof ( struct V_416 ) , V_17 ) ;
}
T_2 F_153 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_153 V_55 ;
struct V_417 V_57 ;
struct V_418 * V_419 ;
struct V_420 * V_421 = NULL , * V_422 , * V_423 , * V_424 ;
struct V_37 * V_40 ;
int V_425 , V_426 ;
int V_427 ;
T_2 V_16 = - V_64 ;
T_4 V_428 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
if ( V_53 < sizeof V_55 + V_55 . V_429 * V_55 . V_430 +
V_55 . V_431 * sizeof ( struct V_432 ) )
return - V_64 ;
if ( V_55 . V_429 < sizeof ( struct V_418 ) )
return - V_64 ;
V_419 = F_71 ( V_55 . V_429 , V_17 ) ;
if ( ! V_419 )
return - V_165 ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 )
goto V_210;
V_427 = V_40 -> V_320 == V_433 ;
V_426 = 0 ;
V_422 = NULL ;
for ( V_425 = 0 ; V_425 < V_55 . V_430 ; ++ V_425 ) {
if ( F_48 ( V_419 ,
V_52 + sizeof V_55 + V_425 * V_55 . V_429 ,
V_55 . V_429 ) ) {
V_16 = - V_63 ;
goto V_307;
}
if ( V_419 -> V_415 + V_426 > V_55 . V_431 ) {
V_16 = - V_64 ;
goto V_307;
}
if ( V_427 ) {
struct V_434 * V_435 ;
if ( V_419 -> V_288 != V_436 &&
V_419 -> V_288 != V_437 ) {
V_16 = - V_64 ;
goto V_307;
}
V_428 = sizeof( * V_435 ) ;
V_435 = F_151 ( V_428 , V_419 -> V_415 ) ;
if ( ! V_435 ) {
V_16 = - V_165 ;
goto V_307;
}
V_435 -> V_36 = F_37 ( V_419 -> V_421 . V_435 . V_36 , V_49 -> V_60 ) ;
if ( ! V_435 -> V_36 ) {
F_81 ( V_435 ) ;
V_16 = - V_64 ;
goto V_307;
}
V_435 -> V_438 = V_419 -> V_421 . V_435 . V_438 ;
V_435 -> V_439 = V_419 -> V_421 . V_435 . V_439 ;
V_423 = & V_435 -> V_421 ;
} else if ( V_419 -> V_288 == V_440 ||
V_419 -> V_288 == V_441 ||
V_419 -> V_288 == V_442 ) {
struct V_443 * V_444 ;
V_428 = sizeof( * V_444 ) ;
V_444 = F_151 ( V_428 , V_419 -> V_415 ) ;
if ( ! V_444 ) {
V_16 = - V_165 ;
goto V_307;
}
V_444 -> V_445 = V_419 -> V_421 . V_444 . V_445 ;
V_444 -> V_225 = V_419 -> V_421 . V_444 . V_225 ;
V_423 = & V_444 -> V_421 ;
} else if ( V_419 -> V_288 == V_446 ||
V_419 -> V_288 == V_447 ) {
struct V_448 * V_449 ;
V_428 = sizeof( * V_449 ) ;
V_449 = F_151 ( V_428 , V_419 -> V_415 ) ;
if ( ! V_449 ) {
V_16 = - V_165 ;
goto V_307;
}
V_449 -> V_445 = V_419 -> V_421 . V_449 . V_445 ;
V_449 -> V_450 = V_419 -> V_421 . V_449 . V_450 ;
V_449 -> V_451 = V_419 -> V_421 . V_449 . V_451 ;
V_449 -> V_225 = V_419 -> V_421 . V_449 . V_225 ;
V_423 = & V_449 -> V_421 ;
} else if ( V_419 -> V_288 == V_436 ||
V_419 -> V_288 == V_437 ||
V_419 -> V_288 == V_452 ) {
V_428 = sizeof( * V_423 ) ;
V_423 = F_151 ( V_428 , V_419 -> V_415 ) ;
if ( ! V_423 ) {
V_16 = - V_165 ;
goto V_307;
}
} else {
V_16 = - V_64 ;
goto V_307;
}
if ( V_419 -> V_288 == V_437 ||
V_419 -> V_288 == V_440 ) {
V_423 -> V_291 . V_292 =
( V_453 V_294 ) V_419 -> V_291 . V_292 ;
} else if ( V_419 -> V_288 == V_452 ) {
V_423 -> V_291 . V_454 = V_419 -> V_291 . V_454 ;
}
if ( ! V_422 )
V_421 = V_423 ;
else
V_422 -> V_423 = V_423 ;
V_422 = V_423 ;
V_423 -> V_423 = NULL ;
V_423 -> V_286 = V_419 -> V_286 ;
V_423 -> V_415 = V_419 -> V_415 ;
V_423 -> V_288 = V_419 -> V_288 ;
V_423 -> V_455 = V_419 -> V_455 ;
if ( V_423 -> V_415 ) {
V_423 -> V_456 = ( void * ) V_423 +
F_152 ( V_428 , sizeof( struct V_416 ) ) ;
if ( F_48 ( V_423 -> V_456 ,
V_52 + sizeof V_55 +
V_55 . V_430 * V_55 . V_429 +
V_426 * sizeof ( struct V_416 ) ,
V_423 -> V_415 * sizeof ( struct V_416 ) ) ) {
V_16 = - V_63 ;
goto V_307;
}
V_426 += V_423 -> V_415 ;
} else
V_423 -> V_456 = NULL ;
}
V_57 . V_424 = 0 ;
V_16 = V_40 -> V_68 -> V_457 ( V_40 -> V_355 , V_421 , & V_424 ) ;
if ( V_16 )
for ( V_423 = V_421 ; V_423 ; V_423 = V_423 -> V_423 ) {
++ V_57 . V_424 ;
if ( V_423 == V_424 )
break;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
V_307:
F_41 ( V_40 ) ;
while ( V_421 ) {
if ( V_427 && F_154 ( V_421 ) -> V_36 )
F_38 ( F_154 ( V_421 ) -> V_36 ) ;
V_423 = V_421 -> V_423 ;
F_81 ( V_421 ) ;
V_421 = V_423 ;
}
V_210:
F_81 ( V_419 ) ;
return V_16 ? V_16 : V_53 ;
}
static struct V_458 * F_155 ( const char T_3 * V_52 ,
int V_53 ,
T_6 V_430 ,
T_6 V_431 ,
T_6 V_429 )
{
struct V_459 * V_419 ;
struct V_458 * V_421 = NULL , * V_422 , * V_423 ;
int V_426 ;
int V_425 ;
int V_16 ;
if ( V_53 < V_429 * V_430 +
V_431 * sizeof ( struct V_432 ) )
return F_113 ( - V_64 ) ;
if ( V_429 < sizeof ( struct V_459 ) )
return F_113 ( - V_64 ) ;
V_419 = F_71 ( V_429 , V_17 ) ;
if ( ! V_419 )
return F_113 ( - V_165 ) ;
V_426 = 0 ;
V_422 = NULL ;
for ( V_425 = 0 ; V_425 < V_430 ; ++ V_425 ) {
if ( F_48 ( V_419 , V_52 + V_425 * V_429 ,
V_429 ) ) {
V_16 = - V_63 ;
goto V_65;
}
if ( V_419 -> V_415 + V_426 > V_431 ) {
V_16 = - V_64 ;
goto V_65;
}
V_423 = F_71 ( F_152 ( sizeof *V_423 , sizeof ( struct V_416 ) ) +
V_419 -> V_415 * sizeof ( struct V_416 ) ,
V_17 ) ;
if ( ! V_423 ) {
V_16 = - V_165 ;
goto V_65;
}
if ( ! V_422 )
V_421 = V_423 ;
else
V_422 -> V_423 = V_423 ;
V_422 = V_423 ;
V_423 -> V_423 = NULL ;
V_423 -> V_286 = V_419 -> V_286 ;
V_423 -> V_415 = V_419 -> V_415 ;
if ( V_423 -> V_415 ) {
V_423 -> V_456 = ( void * ) V_423 +
F_152 ( sizeof *V_423 , sizeof ( struct V_416 ) ) ;
if ( F_48 ( V_423 -> V_456 ,
V_52 + V_430 * V_429 +
V_426 * sizeof ( struct V_416 ) ,
V_423 -> V_415 * sizeof ( struct V_416 ) ) ) {
V_16 = - V_63 ;
goto V_65;
}
V_426 += V_423 -> V_415 ;
} else
V_423 -> V_456 = NULL ;
}
F_81 ( V_419 ) ;
return V_421 ;
V_65:
F_81 ( V_419 ) ;
while ( V_421 ) {
V_423 = V_421 -> V_423 ;
F_81 ( V_421 ) ;
V_421 = V_423 ;
}
return F_113 ( V_16 ) ;
}
T_2 F_156 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_156 V_55 ;
struct V_460 V_57 ;
struct V_458 * V_421 , * V_423 , * V_424 ;
struct V_37 * V_40 ;
T_2 V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_421 = F_155 ( V_52 + sizeof V_55 ,
V_53 - sizeof V_55 , V_55 . V_430 ,
V_55 . V_431 , V_55 . V_429 ) ;
if ( F_51 ( V_421 ) )
return F_52 ( V_421 ) ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 )
goto V_210;
V_57 . V_424 = 0 ;
V_16 = V_40 -> V_68 -> V_461 ( V_40 -> V_355 , V_421 , & V_424 ) ;
F_41 ( V_40 ) ;
if ( V_16 )
for ( V_423 = V_421 ; V_423 ; V_423 = V_423 -> V_423 ) {
++ V_57 . V_424 ;
if ( V_423 == V_424 )
break;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
V_210:
while ( V_421 ) {
V_423 = V_421 -> V_423 ;
F_81 ( V_421 ) ;
V_421 = V_423 ;
}
return V_16 ? V_16 : V_53 ;
}
T_2 F_157 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_157 V_55 ;
struct V_462 V_57 ;
struct V_458 * V_421 , * V_423 , * V_424 ;
struct V_41 * V_44 ;
T_2 V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_421 = F_155 ( V_52 + sizeof V_55 ,
V_53 - sizeof V_55 , V_55 . V_430 ,
V_55 . V_431 , V_55 . V_429 ) ;
if ( F_51 ( V_421 ) )
return F_52 ( V_421 ) ;
V_44 = F_43 ( V_55 . V_42 , V_49 -> V_60 ) ;
if ( ! V_44 )
goto V_210;
V_57 . V_424 = 0 ;
V_16 = V_44 -> V_68 -> V_463 ( V_44 , V_421 , & V_424 ) ;
F_44 ( V_44 ) ;
if ( V_16 )
for ( V_423 = V_421 ; V_423 ; V_423 = V_423 -> V_423 ) {
++ V_57 . V_424 ;
if ( V_423 == V_424 )
break;
}
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
V_210:
while ( V_421 ) {
V_423 = V_421 -> V_423 ;
F_81 ( V_421 ) ;
V_421 = V_423 ;
}
return V_16 ? V_16 : V_53 ;
}
T_2 F_158 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_158 V_55 ;
struct V_464 V_57 ;
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_33 * V_36 ;
struct V_465 V_101 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_71 ( sizeof *V_2 , V_17 ) ;
if ( ! V_2 )
return - V_165 ;
F_1 ( V_2 , V_55 . V_3 , V_49 -> V_60 , & V_466 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_27 = F_33 ( V_55 . V_25 , V_49 -> V_60 ) ;
if ( ! V_27 ) {
V_16 = - V_64 ;
goto V_65;
}
V_101 . V_395 = V_55 . V_101 . V_395 ;
V_101 . V_300 = V_55 . V_101 . V_300 ;
V_101 . V_396 = V_55 . V_101 . V_396 ;
V_101 . V_397 = V_55 . V_101 . V_397 ;
V_101 . V_399 = V_55 . V_101 . V_398 ? V_400 : 0 ;
V_101 . V_143 = V_55 . V_101 . V_143 ;
V_101 . V_389 . V_391 = V_55 . V_101 . V_389 . V_391 ;
V_101 . V_389 . V_392 = V_55 . V_101 . V_389 . V_392 ;
V_101 . V_389 . V_393 = V_55 . V_101 . V_389 . V_393 ;
V_101 . V_389 . V_394 = V_55 . V_101 . V_389 . V_394 ;
memset ( & V_101 . V_467 , 0 , sizeof( V_101 . V_467 ) ) ;
memcpy ( V_101 . V_389 . V_387 . V_390 , V_55 . V_101 . V_389 . V_387 , 16 ) ;
V_36 = F_159 ( V_27 , & V_101 ) ;
if ( F_51 ( V_36 ) ) {
V_16 = F_52 ( V_36 ) ;
goto V_174;
}
V_36 -> V_28 = V_2 ;
V_2 -> V_23 = V_36 ;
V_16 = F_14 ( & V_35 , V_2 ) ;
if ( V_16 )
goto V_356;
V_57 . V_34 = V_2 -> V_20 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_171;
}
F_34 ( V_27 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_73 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_75 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_53 ;
V_171:
F_20 ( & V_35 , V_2 ) ;
V_356:
F_160 ( V_36 ) ;
V_174:
F_34 ( V_27 ) ;
V_65:
F_12 ( V_2 ) ;
return V_16 ;
}
T_2 F_161 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 , int V_54 )
{
struct F_161 V_55 ;
struct V_33 * V_36 ;
struct V_1 * V_2 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_35 , V_55 . V_34 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_36 = V_2 -> V_23 ;
V_16 = F_160 ( V_36 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_20 ( & V_35 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_78 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_53 ;
}
T_2 F_162 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_162 V_55 ;
struct V_37 * V_40 ;
struct V_314 * V_193 ;
struct V_468 * V_469 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_40 = F_40 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 )
return - V_64 ;
V_193 = F_7 ( V_40 -> V_28 , struct V_314 , V_324 . V_28 ) ;
F_163 (mcast, &obj->mcast_list, list)
if ( V_55 . V_470 == V_469 -> V_153 &&
! memcmp ( V_55 . V_471 , V_469 -> V_471 . V_390 , sizeof V_469 -> V_471 . V_390 ) ) {
V_16 = 0 ;
goto V_307;
}
V_469 = F_71 ( sizeof *V_469 , V_17 ) ;
if ( ! V_469 ) {
V_16 = - V_165 ;
goto V_307;
}
V_469 -> V_153 = V_55 . V_470 ;
memcpy ( V_469 -> V_471 . V_390 , V_55 . V_471 , sizeof V_469 -> V_471 . V_390 ) ;
V_16 = F_164 ( V_40 , & V_469 -> V_471 , V_55 . V_470 ) ;
if ( ! V_16 )
F_73 ( & V_469 -> V_172 , & V_193 -> V_350 ) ;
else
F_81 ( V_469 ) ;
V_307:
F_42 ( V_40 ) ;
return V_16 ? V_16 : V_53 ;
}
T_2 F_165 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_165 V_55 ;
struct V_314 * V_193 ;
struct V_37 * V_40 ;
struct V_468 * V_469 ;
int V_16 = - V_64 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_40 = F_40 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 )
return - V_64 ;
V_16 = F_166 ( V_40 , (union V_472 * ) V_55 . V_471 , V_55 . V_470 ) ;
if ( V_16 )
goto V_307;
V_193 = F_7 ( V_40 -> V_28 , struct V_314 , V_324 . V_28 ) ;
F_163 (mcast, &obj->mcast_list, list)
if ( V_55 . V_470 == V_469 -> V_153 &&
! memcmp ( V_55 . V_471 , V_469 -> V_471 . V_390 , sizeof V_469 -> V_471 . V_390 ) ) {
F_78 ( & V_469 -> V_172 ) ;
F_81 ( V_469 ) ;
break;
}
V_307:
F_42 ( V_40 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_167 ( struct V_473 * V_474 ,
union V_475 * V_476 )
{
if ( V_474 -> V_277 )
return - V_64 ;
V_476 -> type = V_474 -> type ;
switch ( V_476 -> type ) {
case V_477 :
V_476 -> V_478 . V_479 = sizeof( struct V_480 ) ;
if ( V_476 -> V_478 . V_479 != V_474 -> V_478 . V_479 )
return - V_64 ;
memcpy ( & V_476 -> V_478 . V_481 , & V_474 -> V_478 . V_481 ,
sizeof( struct V_482 ) ) ;
memcpy ( & V_476 -> V_478 . V_404 , & V_474 -> V_478 . V_404 ,
sizeof( struct V_482 ) ) ;
break;
case V_483 :
V_476 -> V_484 . V_479 = sizeof( struct V_485 ) ;
if ( V_476 -> V_484 . V_479 != V_474 -> V_484 . V_479 )
return - V_64 ;
memcpy ( & V_476 -> V_484 . V_481 , & V_474 -> V_484 . V_481 ,
sizeof( struct V_486 ) ) ;
memcpy ( & V_476 -> V_484 . V_404 , & V_474 -> V_484 . V_404 ,
sizeof( struct V_486 ) ) ;
break;
case V_487 :
case V_488 :
V_476 -> V_489 . V_479 = sizeof( struct V_490 ) ;
if ( V_476 -> V_489 . V_479 != V_474 -> V_489 . V_479 )
return - V_64 ;
memcpy ( & V_476 -> V_489 . V_481 , & V_474 -> V_489 . V_481 ,
sizeof( struct V_491 ) ) ;
memcpy ( & V_476 -> V_489 . V_404 , & V_474 -> V_489 . V_404 ,
sizeof( struct V_491 ) ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
int F_168 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 )
{
struct V_492 V_55 ;
struct V_493 V_57 ;
struct V_1 * V_2 ;
struct V_494 * V_495 ;
struct V_496 * V_497 ;
struct V_498 * V_499 ;
struct V_37 * V_40 ;
int V_65 = 0 ;
void * V_474 ;
void * V_476 ;
int V_425 ;
if ( V_248 -> V_275 < sizeof( V_55 ) )
return - V_64 ;
if ( V_248 -> V_278 < sizeof( V_57 ) )
return - V_62 ;
V_65 = F_123 ( & V_55 , V_248 , sizeof( V_55 ) ) ;
if ( V_65 )
return V_65 ;
V_248 -> V_500 += sizeof( V_55 ) ;
V_248 -> V_275 -= sizeof( V_55 ) ;
if ( V_55 . V_276 )
return - V_64 ;
if ( ( V_55 . V_499 . type == V_501 &&
! F_133 ( V_502 ) ) || ! F_133 ( V_322 ) )
return - V_323 ;
if ( V_55 . V_499 . V_503 > V_504 )
return - V_64 ;
if ( V_55 . V_499 . V_479 > V_248 -> V_275 ||
V_55 . V_499 . V_479 >
( V_55 . V_499 . V_503 * sizeof( struct V_473 ) ) )
return - V_64 ;
if ( V_55 . V_499 . V_277 [ 0 ] ||
V_55 . V_499 . V_277 [ 1 ] )
return - V_64 ;
if ( V_55 . V_499 . V_503 ) {
V_497 = F_71 ( sizeof( * V_497 ) + V_55 . V_499 . V_479 ,
V_17 ) ;
if ( ! V_497 )
return - V_165 ;
memcpy ( V_497 , & V_55 . V_499 , sizeof( * V_497 ) ) ;
V_65 = F_123 ( V_497 + 1 , V_248 ,
V_55 . V_499 . V_479 ) ;
if ( V_65 )
goto V_505;
} else {
V_497 = & V_55 . V_499 ;
}
V_2 = F_71 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 ) {
V_65 = - V_165 ;
goto V_505;
}
F_1 ( V_2 , 0 , V_49 -> V_60 , & V_506 ) ;
F_31 ( & V_2 -> V_9 ) ;
V_40 = F_39 ( V_55 . V_38 , V_49 -> V_60 ) ;
if ( ! V_40 ) {
V_65 = - V_64 ;
goto V_507;
}
V_499 = F_71 ( sizeof( * V_499 ) + V_55 . V_499 . V_479 , V_17 ) ;
if ( ! V_499 ) {
V_65 = - V_165 ;
goto V_174;
}
V_499 -> type = V_497 -> type ;
V_499 -> V_508 = V_497 -> V_508 ;
V_499 -> V_503 = V_497 -> V_503 ;
V_499 -> V_509 = V_497 -> V_509 ;
V_499 -> V_229 = V_497 -> V_229 ;
V_499 -> V_479 = sizeof( * V_499 ) ;
V_474 = V_497 + 1 ;
V_476 = V_499 + 1 ;
for ( V_425 = 0 ; V_425 < V_499 -> V_503 &&
V_55 . V_499 . V_479 > F_115 ( struct V_473 , V_277 ) &&
V_55 . V_499 . V_479 >=
( (struct V_473 * ) V_474 ) -> V_479 ; V_425 ++ ) {
V_65 = F_167 ( V_474 , V_476 ) ;
if ( V_65 )
goto V_94;
V_499 -> V_479 +=
( (union V_475 * ) V_476 ) -> V_479 ;
V_55 . V_499 . V_479 -= ( (struct V_473 * ) V_474 ) -> V_479 ;
V_474 += ( (struct V_473 * ) V_474 ) -> V_479 ;
V_476 += ( (union V_475 * ) V_476 ) -> V_479 ;
}
if ( V_55 . V_499 . V_479 || ( V_425 != V_499 -> V_503 ) ) {
F_169 ( L_3 ,
V_425 , V_55 . V_499 . V_479 ) ;
V_65 = - V_64 ;
goto V_94;
}
V_495 = F_170 ( V_40 , V_499 , V_510 ) ;
if ( F_51 ( V_495 ) ) {
V_65 = F_52 ( V_495 ) ;
goto V_94;
}
V_495 -> V_40 = V_40 ;
V_495 -> V_28 = V_2 ;
V_2 -> V_23 = V_495 ;
V_65 = F_14 ( & V_511 , V_2 ) ;
if ( V_65 )
goto V_512;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_513 = V_2 -> V_20 ;
V_65 = F_120 ( V_248 ,
& V_57 , sizeof( V_57 ) ) ;
if ( V_65 )
goto V_171;
F_41 ( V_40 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_73 ( & V_2 -> V_172 , & V_49 -> V_60 -> V_77 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_81 ( V_499 ) ;
if ( V_55 . V_499 . V_503 )
F_81 ( V_497 ) ;
return 0 ;
V_171:
F_20 ( & V_511 , V_2 ) ;
V_512:
F_171 ( V_495 ) ;
V_94:
F_81 ( V_499 ) ;
V_174:
F_41 ( V_40 ) ;
V_507:
F_12 ( V_2 ) ;
V_505:
if ( V_55 . V_499 . V_503 )
F_81 ( V_497 ) ;
return V_65 ;
}
int F_172 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 )
{
struct V_514 V_55 ;
struct V_494 * V_495 ;
struct V_1 * V_2 ;
int V_16 ;
if ( V_248 -> V_275 < sizeof( V_55 ) )
return - V_64 ;
V_16 = F_123 ( & V_55 , V_248 , sizeof( V_55 ) ) ;
if ( V_16 )
return V_16 ;
if ( V_55 . V_276 )
return - V_64 ;
V_2 = F_30 ( & V_511 , V_55 . V_513 ,
V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_495 = V_2 -> V_23 ;
V_16 = F_171 ( V_495 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_511 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_78 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_16 ;
}
static int F_173 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_515 * V_55 ,
struct V_58 * V_59 )
{
struct V_516 V_57 ;
struct V_517 * V_193 ;
struct V_24 * V_27 ;
struct V_41 * V_44 ;
struct V_1 * V_315 ( V_316 ) ;
struct V_518 V_101 ;
int V_16 ;
V_193 = F_71 ( sizeof *V_193 , V_17 ) ;
if ( ! V_193 )
return - V_165 ;
F_1 ( & V_193 -> V_324 . V_28 , V_55 -> V_3 , V_49 -> V_60 , & V_519 ) ;
F_31 ( & V_193 -> V_324 . V_28 . V_9 ) ;
if ( V_55 -> V_331 == V_520 ) {
V_101 . V_521 . V_522 . V_179 = F_45 ( V_55 -> V_46 , V_49 -> V_60 , & V_316 ) ;
if ( ! V_101 . V_521 . V_522 . V_179 ) {
V_16 = - V_64 ;
goto V_65;
}
V_193 -> V_358 = F_7 ( V_316 , struct V_192 , V_28 ) ;
F_94 ( & V_193 -> V_358 -> V_208 ) ;
V_101 . V_521 . V_522 . V_32 = F_35 ( V_55 -> V_30 , V_49 -> V_60 , 0 ) ;
if ( ! V_101 . V_521 . V_522 . V_32 ) {
V_16 = - V_64 ;
goto V_523;
}
}
V_27 = F_33 ( V_55 -> V_25 , V_49 -> V_60 ) ;
if ( ! V_27 ) {
V_16 = - V_64 ;
goto V_524;
}
V_101 . V_267 = V_525 ;
V_101 . V_526 = V_49 ;
V_101 . V_331 = V_55 -> V_331 ;
V_101 . V_101 . V_527 = V_55 -> V_527 ;
V_101 . V_101 . V_112 = V_55 -> V_112 ;
V_101 . V_101 . V_528 = V_55 -> V_528 ;
V_193 -> V_324 . V_348 = 0 ;
F_53 ( & V_193 -> V_324 . V_349 ) ;
V_44 = V_27 -> V_68 -> V_529 ( V_27 , & V_101 , V_59 ) ;
if ( F_51 ( V_44 ) ) {
V_16 = F_52 ( V_44 ) ;
goto V_174;
}
V_44 -> V_68 = V_27 -> V_68 ;
V_44 -> V_27 = V_27 ;
V_44 -> V_331 = V_55 -> V_331 ;
V_44 -> V_28 = & V_193 -> V_324 . V_28 ;
V_44 -> V_267 = V_101 . V_267 ;
V_44 -> V_526 = V_101 . V_526 ;
if ( V_55 -> V_331 == V_520 ) {
V_44 -> V_521 . V_522 . V_32 = V_101 . V_521 . V_522 . V_32 ;
V_44 -> V_521 . V_522 . V_179 = V_101 . V_521 . V_522 . V_179 ;
F_94 ( & V_101 . V_521 . V_522 . V_32 -> V_169 ) ;
F_94 ( & V_101 . V_521 . V_522 . V_179 -> V_169 ) ;
}
F_94 ( & V_27 -> V_169 ) ;
F_72 ( & V_44 -> V_169 , 0 ) ;
V_193 -> V_324 . V_28 . V_23 = V_44 ;
V_16 = F_14 ( & V_43 , & V_193 -> V_324 . V_28 ) ;
if ( V_16 )
goto V_356;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_42 = V_193 -> V_324 . V_28 . V_20 ;
V_57 . V_527 = V_101 . V_101 . V_527 ;
V_57 . V_112 = V_101 . V_101 . V_112 ;
if ( V_55 -> V_331 == V_520 )
V_57 . V_530 = V_44 -> V_521 . V_522 . V_531 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 -> V_66 ,
& V_57 , sizeof V_57 ) ) {
V_16 = - V_63 ;
goto V_171;
}
if ( V_55 -> V_331 == V_520 ) {
F_10 ( V_316 ) ;
F_36 ( V_101 . V_521 . V_522 . V_32 ) ;
}
F_34 ( V_27 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_73 ( & V_193 -> V_324 . V_28 . V_172 , & V_49 -> V_60 -> V_74 ) ;
F_60 ( & V_49 -> V_9 ) ;
V_193 -> V_324 . V_28 . V_12 = 1 ;
F_13 ( & V_193 -> V_324 . V_28 . V_9 ) ;
return 0 ;
V_171:
F_20 ( & V_43 , & V_193 -> V_324 . V_28 ) ;
V_356:
F_174 ( V_44 ) ;
V_174:
F_34 ( V_27 ) ;
V_524:
if ( V_55 -> V_331 == V_520 )
F_36 ( V_101 . V_521 . V_522 . V_32 ) ;
V_523:
if ( V_55 -> V_331 == V_520 ) {
F_96 ( & V_193 -> V_358 -> V_208 ) ;
F_10 ( V_316 ) ;
}
V_65:
F_12 ( & V_193 -> V_324 . V_28 ) ;
return V_16 ;
}
T_2 F_175 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_175 V_55 ;
struct V_515 V_532 ;
struct V_516 V_57 ;
struct V_58 V_59 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_532 . V_66 = V_55 . V_66 ;
V_532 . V_3 = V_55 . V_3 ;
V_532 . V_331 = V_332 ;
V_532 . V_25 = V_55 . V_25 ;
V_532 . V_527 = V_55 . V_527 ;
V_532 . V_112 = V_55 . V_112 ;
V_532 . V_528 = V_55 . V_528 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 - sizeof( struct V_361 ) ,
V_54 - sizeof V_57 ) ;
V_16 = F_173 ( V_49 , V_51 , & V_532 , & V_59 ) ;
if ( V_16 )
return V_16 ;
return V_53 ;
}
T_2 V_515 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 , int V_54 )
{
struct V_515 V_55 ;
struct V_516 V_57 ;
struct V_58 V_59 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 ,
( unsigned long ) V_55 . V_66 + sizeof V_57 ,
V_53 - sizeof V_55 - sizeof( struct V_361 ) ,
V_54 - sizeof V_57 ) ;
V_16 = F_173 ( V_49 , V_51 , & V_55 , & V_59 ) ;
if ( V_16 )
return V_16 ;
return V_53 ;
}
T_2 F_176 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_176 V_55 ;
struct V_58 V_59 ;
struct V_41 * V_44 ;
struct V_533 V_101 ;
int V_16 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
F_50 ( & V_59 , V_52 + sizeof V_55 , NULL , V_53 - sizeof V_55 ,
V_54 ) ;
V_44 = F_43 ( V_55 . V_42 , V_49 -> V_60 ) ;
if ( ! V_44 )
return - V_64 ;
V_101 . V_527 = V_55 . V_527 ;
V_101 . V_528 = V_55 . V_528 ;
V_16 = V_44 -> V_68 -> V_534 ( V_44 , & V_101 , V_55 . V_367 , & V_59 ) ;
F_44 ( V_44 ) ;
return V_16 ? V_16 : V_53 ;
}
T_2 F_177 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 ,
int V_53 , int V_54 )
{
struct F_177 V_55 ;
struct V_535 V_57 ;
struct V_533 V_101 ;
struct V_41 * V_44 ;
int V_16 ;
if ( V_54 < sizeof V_57 )
return - V_62 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_44 = F_43 ( V_55 . V_42 , V_49 -> V_60 ) ;
if ( ! V_44 )
return - V_64 ;
V_16 = F_178 ( V_44 , & V_101 ) ;
F_44 ( V_44 ) ;
if ( V_16 )
return V_16 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_527 = V_101 . V_527 ;
V_57 . V_112 = V_101 . V_112 ;
V_57 . V_528 = V_101 . V_528 ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
return - V_63 ;
return V_53 ;
}
T_2 F_179 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
const char T_3 * V_52 , int V_53 ,
int V_54 )
{
struct F_179 V_55 ;
struct V_536 V_57 ;
struct V_1 * V_2 ;
struct V_41 * V_44 ;
struct V_537 * V_193 ;
int V_16 = - V_64 ;
struct V_517 * V_538 ;
enum V_539 V_331 ;
if ( F_48 ( & V_55 , V_52 , sizeof V_55 ) )
return - V_63 ;
V_2 = F_30 ( & V_43 , V_55 . V_42 , V_49 -> V_60 ) ;
if ( ! V_2 )
return - V_64 ;
V_44 = V_2 -> V_23 ;
V_193 = F_7 ( V_2 , struct V_537 , V_28 ) ;
V_331 = V_44 -> V_331 ;
V_16 = F_174 ( V_44 ) ;
if ( ! V_16 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_331 == V_520 ) {
V_538 = F_7 ( V_193 , struct V_517 , V_324 ) ;
F_96 ( & V_538 -> V_358 -> V_208 ) ;
}
F_20 ( & V_43 , V_2 ) ;
F_49 ( & V_49 -> V_9 ) ;
F_78 ( & V_2 -> V_172 ) ;
F_60 ( & V_49 -> V_9 ) ;
F_150 ( V_49 , V_193 ) ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_348 = V_193 -> V_348 ;
F_8 ( V_2 ) ;
if ( F_58 ( ( void T_3 * ) ( unsigned long ) V_55 . V_66 ,
& V_57 , sizeof V_57 ) )
V_16 = - V_63 ;
return V_16 ? V_16 : V_53 ;
}
int F_180 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_58 * V_248 ,
struct V_58 * V_249 )
{
struct V_540 V_57 ;
struct F_180 V_55 ;
struct V_100 V_101 ;
int V_65 ;
if ( V_248 -> V_275 < sizeof( V_55 ) )
return - V_64 ;
V_65 = F_123 ( & V_55 , V_248 , sizeof( V_55 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_55 . V_276 )
return - V_64 ;
if ( V_55 . V_277 )
return - V_64 ;
V_57 . V_271 = F_115 ( F_116 ( V_57 ) , V_541 ) ;
if ( V_248 -> V_278 < V_57 . V_271 )
return - V_62 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_65 = V_51 -> V_542 ( V_51 , & V_101 , V_249 ) ;
if ( V_65 )
return V_65 ;
F_65 ( V_49 , V_51 , & V_57 . V_270 , & V_101 ) ;
V_57 . V_276 = 0 ;
if ( V_248 -> V_278 < V_57 . V_271 + sizeof( V_57 . V_541 ) )
goto V_543;
#ifdef F_55
V_57 . V_541 . V_544 = V_101 . V_541 . V_544 ;
V_57 . V_541 . V_545 . V_546 =
V_101 . V_541 . V_545 . V_546 ;
V_57 . V_541 . V_545 . V_547 =
V_101 . V_541 . V_545 . V_547 ;
V_57 . V_541 . V_545 . V_548 =
V_101 . V_541 . V_545 . V_548 ;
V_57 . V_541 . V_277 = 0 ;
#else
memset ( & V_57 . V_541 , 0 , sizeof( V_57 . V_541 ) ) ;
#endif
V_57 . V_271 += sizeof( V_57 . V_541 ) ;
if ( V_248 -> V_278 < V_57 . V_271 + sizeof( V_57 . V_549 ) )
goto V_543;
V_57 . V_549 = V_101 . V_549 ;
V_57 . V_271 += sizeof( V_57 . V_549 ) ;
if ( V_248 -> V_278 < V_57 . V_271 + sizeof( V_57 . V_550 ) )
goto V_543;
V_57 . V_550 = V_101 . V_550 ;
V_57 . V_271 += sizeof( V_57 . V_550 ) ;
V_543:
V_65 = F_120 ( V_248 , & V_57 , V_57 . V_271 ) ;
if ( V_65 )
return V_65 ;
return 0 ;
}
