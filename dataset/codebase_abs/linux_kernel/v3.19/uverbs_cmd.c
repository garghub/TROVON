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
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_45 V_52 ;
struct V_53 V_54 ;
struct V_55 V_56 ;
struct V_57 * V_58 = V_48 -> V_59 -> V_60 ;
#ifdef F_46
struct V_61 V_62 ;
#endif
struct V_4 * V_63 ;
struct V_48 * V_64 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_48 ( & V_48 -> V_9 ) ;
if ( V_48 -> V_63 ) {
V_15 = - V_67 ;
goto V_68;
}
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_63 = V_58 -> V_70 ( V_58 , & V_56 ) ;
if ( F_50 ( V_63 ) ) {
V_15 = F_51 ( V_63 ) ;
goto V_68;
}
V_63 -> V_59 = V_58 ;
F_52 ( & V_63 -> V_71 ) ;
F_52 ( & V_63 -> V_72 ) ;
F_52 ( & V_63 -> V_73 ) ;
F_52 ( & V_63 -> V_74 ) ;
F_52 ( & V_63 -> V_75 ) ;
F_52 ( & V_63 -> V_76 ) ;
F_52 ( & V_63 -> V_77 ) ;
F_52 ( & V_63 -> V_78 ) ;
F_52 ( & V_63 -> V_79 ) ;
F_53 () ;
V_63 -> V_80 = F_54 ( V_81 -> V_82 , V_83 ) ;
F_55 () ;
V_63 -> V_84 = 0 ;
#ifdef F_46
V_63 -> V_85 = V_86 ;
F_3 ( & V_63 -> V_87 ) ;
V_63 -> V_88 = 0 ;
F_52 ( & V_63 -> V_89 ) ;
V_15 = F_56 ( V_58 , & V_62 ) ;
if ( V_15 )
goto V_90;
if ( ! ( V_62 . V_91 & V_92 ) )
V_63 -> V_93 = NULL ;
#endif
V_54 . V_94 = V_48 -> V_59 -> V_94 ;
V_15 = F_57 ( V_95 ) ;
if ( V_15 < 0 )
goto V_90;
V_54 . V_96 = V_15 ;
V_64 = F_58 ( V_48 , 1 ) ;
if ( F_50 ( V_64 ) ) {
V_15 = F_51 ( V_64 ) ;
goto V_97;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_98;
}
V_48 -> V_99 = V_64 -> V_100 ;
F_60 ( & V_48 -> V_101 , V_48 -> V_59 -> V_60 ,
V_102 ) ;
V_15 = F_61 ( & V_48 -> V_101 ) ;
if ( V_15 )
goto V_98;
F_24 ( & V_48 -> V_99 -> V_8 ) ;
F_24 ( & V_48 -> V_8 ) ;
V_48 -> V_63 = V_63 ;
F_62 ( V_54 . V_96 , V_64 ) ;
F_63 ( & V_48 -> V_9 ) ;
return V_50 ;
V_98:
F_64 ( V_64 ) ;
V_97:
F_65 ( V_54 . V_96 ) ;
V_90:
F_66 ( V_63 -> V_80 ) ;
V_58 -> V_103 ( V_63 ) ;
V_68:
F_63 ( & V_48 -> V_9 ) ;
return V_15 ;
}
T_2 F_67 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_67 V_52 ;
struct V_104 V_54 ;
struct V_61 V_105 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_15 = F_56 ( V_48 -> V_59 -> V_60 , & V_105 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_106 = V_105 . V_106 ;
V_54 . V_107 = V_48 -> V_59 -> V_60 -> V_107 ;
V_54 . V_108 = V_105 . V_108 ;
V_54 . V_109 = V_105 . V_109 ;
V_54 . V_110 = V_105 . V_110 ;
V_54 . V_111 = V_105 . V_111 ;
V_54 . V_112 = V_105 . V_112 ;
V_54 . V_113 = V_105 . V_113 ;
V_54 . V_114 = V_105 . V_114 ;
V_54 . V_115 = V_105 . V_115 ;
V_54 . V_91 = V_105 . V_91 ;
V_54 . V_116 = V_105 . V_116 ;
V_54 . V_117 = V_105 . V_117 ;
V_54 . V_118 = V_105 . V_118 ;
V_54 . V_119 = V_105 . V_119 ;
V_54 . V_120 = V_105 . V_120 ;
V_54 . V_121 = V_105 . V_121 ;
V_54 . V_122 = V_105 . V_122 ;
V_54 . V_123 = V_105 . V_123 ;
V_54 . V_124 = V_105 . V_124 ;
V_54 . V_125 = V_105 . V_125 ;
V_54 . V_126 = V_105 . V_126 ;
V_54 . V_127 = V_105 . V_127 ;
V_54 . V_128 = V_105 . V_128 ;
V_54 . V_129 = V_105 . V_129 ;
V_54 . V_130 = V_105 . V_130 ;
V_54 . V_131 = V_105 . V_131 ;
V_54 . V_132 = V_105 . V_132 ;
V_54 . V_133 = V_105 . V_133 ;
V_54 . V_134 = V_105 . V_134 ;
V_54 . V_135 = V_105 . V_135 ;
V_54 . V_136 = V_105 . V_136 ;
V_54 . V_137 = V_105 . V_137 ;
V_54 . V_138 = V_105 . V_138 ;
V_54 . V_139 = V_105 . V_139 ;
V_54 . V_140 = V_105 . V_140 ;
V_54 . V_141 = V_105 . V_141 ;
V_54 . V_142 = V_105 . V_142 ;
V_54 . V_143 = V_105 . V_143 ;
V_54 . V_144 = V_48 -> V_59 -> V_60 -> V_144 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_68 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_68 V_52 ;
struct V_145 V_54 ;
struct V_146 V_105 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_15 = F_69 ( V_48 -> V_59 -> V_60 , V_52 . V_147 , & V_105 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_148 = V_105 . V_148 ;
V_54 . V_149 = V_105 . V_149 ;
V_54 . V_150 = V_105 . V_150 ;
V_54 . V_151 = V_105 . V_151 ;
V_54 . V_152 = V_105 . V_152 ;
V_54 . V_153 = V_105 . V_153 ;
V_54 . V_154 = V_105 . V_154 ;
V_54 . V_155 = V_105 . V_155 ;
V_54 . V_156 = V_105 . V_156 ;
V_54 . V_157 = V_105 . V_157 ;
V_54 . V_158 = V_105 . V_158 ;
V_54 . V_159 = V_105 . V_159 ;
V_54 . V_160 = V_105 . V_160 ;
V_54 . V_161 = V_105 . V_161 ;
V_54 . V_162 = V_105 . V_162 ;
V_54 . V_163 = V_105 . V_163 ;
V_54 . V_164 = V_105 . V_164 ;
V_54 . V_165 = V_105 . V_165 ;
V_54 . V_166 = V_105 . V_166 ;
V_54 . V_167 = F_70 ( V_48 -> V_59 -> V_60 ,
V_52 . V_147 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_71 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_71 V_52 ;
struct V_168 V_54 ;
struct V_55 V_56 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_2 = F_72 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_169 ;
F_1 ( V_2 , 0 , V_48 -> V_63 , & V_170 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = V_48 -> V_59 -> V_60 -> V_171 ( V_48 -> V_59 -> V_60 ,
V_48 -> V_63 , & V_56 ) ;
if ( F_50 ( V_26 ) ) {
V_15 = F_51 ( V_26 ) ;
goto V_68;
}
V_26 -> V_59 = V_48 -> V_59 -> V_60 ;
V_26 -> V_27 = V_2 ;
F_73 ( & V_26 -> V_172 , 0 ) ;
V_2 -> V_22 = V_26 ;
V_15 = F_14 ( & V_25 , V_2 ) ;
if ( V_15 )
goto V_173;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_24 = V_2 -> V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_71 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_25 , V_2 ) ;
V_173:
F_75 ( V_26 ) ;
V_68:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_76 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_76 V_52 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_25 , V_52 . V_24 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_15 = F_75 ( V_2 -> V_22 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_25 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_77 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
static int F_78 ( struct V_176 * V_177 ,
struct V_178 * V_178 ,
struct V_44 * V_179 )
{
struct V_180 * V_181 , * V_182 ;
struct V_183 * * V_184 = & V_177 -> V_185 . V_183 ;
struct V_183 * V_186 = NULL ;
V_181 = F_72 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 )
return - V_169 ;
V_181 -> V_179 = V_179 ;
V_181 -> V_178 = V_178 ;
while ( * V_184 ) {
V_186 = * V_184 ;
V_182 = F_79 ( V_186 , struct V_180 , V_187 ) ;
if ( V_178 < V_182 -> V_178 ) {
V_184 = & ( * V_184 ) -> V_188 ;
} else if ( V_178 > V_182 -> V_178 ) {
V_184 = & ( * V_184 ) -> V_189 ;
} else {
F_6 ( V_181 ) ;
return - V_190 ;
}
}
F_80 ( & V_181 -> V_187 , V_186 , V_184 ) ;
F_81 ( & V_181 -> V_187 , & V_177 -> V_185 ) ;
F_82 ( V_178 ) ;
return 0 ;
}
static struct V_180 * F_83 ( struct V_176 * V_177 ,
struct V_178 * V_178 )
{
struct V_180 * V_181 ;
struct V_183 * V_184 = V_177 -> V_185 . V_183 ;
while ( V_184 ) {
V_181 = F_79 ( V_184 , struct V_180 , V_187 ) ;
if ( V_178 < V_181 -> V_178 )
V_184 = V_184 -> V_188 ;
else if ( V_178 > V_181 -> V_178 )
V_184 = V_184 -> V_189 ;
else
return V_181 ;
}
return NULL ;
}
static struct V_44 * F_84 ( struct V_176 * V_177 , struct V_178 * V_178 )
{
struct V_180 * V_181 ;
V_181 = F_83 ( V_177 , V_178 ) ;
if ( ! V_181 )
return NULL ;
return V_181 -> V_179 ;
}
static void F_85 ( struct V_176 * V_177 ,
struct V_178 * V_178 )
{
struct V_180 * V_181 ;
V_181 = F_83 ( V_177 , V_178 ) ;
if ( V_181 ) {
F_86 ( V_178 ) ;
F_87 ( & V_181 -> V_187 , & V_177 -> V_185 ) ;
F_6 ( V_181 ) ;
}
}
T_2 F_88 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_88 V_52 ;
struct V_191 V_54 ;
struct V_55 V_56 ;
struct V_192 * V_193 ;
struct V_44 * V_179 = NULL ;
struct V_194 V_195 = { NULL , 0 } ;
struct V_178 * V_178 = NULL ;
int V_15 = 0 ;
int V_196 = 0 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
F_48 ( & V_48 -> V_59 -> V_197 ) ;
if ( V_52 . V_194 != - 1 ) {
V_195 = F_89 ( V_52 . V_194 ) ;
if ( ! V_195 . V_48 ) {
V_15 = - V_198 ;
goto V_199;
}
V_178 = F_90 ( V_195 . V_48 ) ;
V_179 = F_84 ( V_48 -> V_59 , V_178 ) ;
if ( ! V_179 && ! ( V_52 . V_200 & V_201 ) ) {
V_15 = - V_202 ;
goto V_199;
}
if ( V_179 && V_52 . V_200 & V_203 ) {
V_15 = - V_67 ;
goto V_199;
}
}
V_193 = F_72 ( sizeof *V_193 , V_16 ) ;
if ( ! V_193 ) {
V_15 = - V_169 ;
goto V_199;
}
F_1 ( & V_193 -> V_27 , 0 , V_48 -> V_63 , & V_204 ) ;
F_29 ( & V_193 -> V_27 . V_9 ) ;
if ( ! V_179 ) {
V_179 = V_48 -> V_59 -> V_60 -> V_205 ( V_48 -> V_59 -> V_60 ,
V_48 -> V_63 , & V_56 ) ;
if ( F_50 ( V_179 ) ) {
V_15 = F_51 ( V_179 ) ;
goto V_68;
}
V_179 -> V_178 = V_178 ;
V_179 -> V_59 = V_48 -> V_59 -> V_60 ;
F_73 ( & V_179 -> V_172 , 0 ) ;
F_91 ( & V_179 -> V_206 ) ;
F_52 ( & V_179 -> V_207 ) ;
V_196 = 1 ;
}
F_73 ( & V_193 -> V_208 , 0 ) ;
V_193 -> V_27 . V_22 = V_179 ;
V_15 = F_14 ( & V_46 , & V_193 -> V_27 ) ;
if ( V_15 )
goto V_173;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_45 = V_193 -> V_27 . V_19 ;
if ( V_178 ) {
if ( V_196 ) {
V_15 = F_78 ( V_48 -> V_59 , V_178 , V_179 ) ;
if ( V_15 )
goto V_209;
}
F_92 ( & V_179 -> V_172 ) ;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
if ( V_195 . V_48 )
F_93 ( V_195 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_193 -> V_27 . V_175 , & V_48 -> V_63 -> V_78 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_27 . V_9 ) ;
F_63 ( & V_48 -> V_59 -> V_197 ) ;
return V_50 ;
V_174:
if ( V_178 ) {
if ( V_196 )
F_85 ( V_48 -> V_59 , V_178 ) ;
F_94 ( & V_179 -> V_172 ) ;
}
V_209:
F_20 ( & V_46 , & V_193 -> V_27 ) ;
V_173:
F_95 ( V_179 ) ;
V_68:
F_12 ( & V_193 -> V_27 ) ;
V_199:
if ( V_195 . V_48 )
F_93 ( V_195 ) ;
F_63 ( & V_48 -> V_59 -> V_197 ) ;
return V_15 ;
}
T_2 F_96 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_96 V_52 ;
struct V_1 * V_2 ;
struct V_44 * V_179 = NULL ;
struct V_178 * V_178 = NULL ;
struct V_192 * V_193 ;
int V_12 ;
int V_15 = 0 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_48 ( & V_48 -> V_59 -> V_197 ) ;
V_2 = F_28 ( & V_46 , V_52 . V_45 , V_48 -> V_63 ) ;
if ( ! V_2 ) {
V_15 = - V_67 ;
goto V_210;
}
V_179 = V_2 -> V_22 ;
V_178 = V_179 -> V_178 ;
V_193 = F_7 ( V_2 , struct V_192 , V_27 ) ;
if ( F_97 ( & V_193 -> V_208 ) ) {
F_12 ( V_2 ) ;
V_15 = - V_211 ;
goto V_210;
}
if ( ! V_178 || F_98 ( & V_179 -> V_172 ) ) {
V_15 = F_95 ( V_2 -> V_22 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
}
V_12 = V_2 -> V_12 ;
if ( V_178 && V_15 )
F_92 ( & V_179 -> V_172 ) ;
F_12 ( V_2 ) ;
if ( V_15 )
goto V_210;
if ( V_178 && ! V_12 )
F_85 ( V_48 -> V_59 , V_178 ) ;
F_20 ( & V_46 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_77 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
V_15 = V_50 ;
V_210:
F_63 ( & V_48 -> V_59 -> V_197 ) ;
return V_15 ;
}
void F_99 ( struct V_176 * V_177 ,
struct V_44 * V_179 )
{
struct V_178 * V_178 ;
V_178 = V_179 -> V_178 ;
if ( V_178 && ! F_98 ( & V_179 -> V_172 ) )
return;
F_95 ( V_179 ) ;
if ( V_178 )
F_85 ( V_177 , V_178 ) ;
}
T_2 F_100 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_100 V_52 ;
struct V_212 V_54 ;
struct V_55 V_56 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_213 * V_214 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
if ( ( V_52 . V_215 & ~ V_216 ) != ( V_52 . V_217 & ~ V_216 ) )
return - V_67 ;
V_15 = F_101 ( V_52 . V_218 ) ;
if ( V_15 )
return V_15 ;
V_2 = F_72 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_169 ;
F_1 ( V_2 , 0 , V_48 -> V_63 , & V_219 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_63 ) ;
if ( ! V_26 ) {
V_15 = - V_67 ;
goto V_90;
}
if ( V_52 . V_218 & V_220 ) {
struct V_61 V_105 ;
V_15 = F_56 ( V_26 -> V_59 , & V_105 ) ;
if ( V_15 || ! ( V_105 . V_91 &
V_92 ) ) {
F_102 ( L_1 ) ;
V_15 = - V_67 ;
goto V_221;
}
}
V_214 = V_26 -> V_59 -> V_222 ( V_26 , V_52 . V_215 , V_52 . V_223 , V_52 . V_217 ,
V_52 . V_218 , & V_56 ) ;
if ( F_50 ( V_214 ) ) {
V_15 = F_51 ( V_214 ) ;
goto V_221;
}
V_214 -> V_59 = V_26 -> V_59 ;
V_214 -> V_26 = V_26 ;
V_214 -> V_27 = V_2 ;
F_92 ( & V_26 -> V_172 ) ;
F_73 ( & V_214 -> V_172 , 0 ) ;
V_2 -> V_22 = V_214 ;
V_15 = F_14 ( & V_224 , V_2 ) ;
if ( V_15 )
goto V_225;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_226 = V_214 -> V_226 ;
V_54 . V_227 = V_214 -> V_227 ;
V_54 . V_228 = V_2 -> V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_72 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_224 , V_2 ) ;
V_225:
F_103 ( V_214 ) ;
V_221:
F_32 ( V_26 ) ;
V_90:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_104 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_104 V_52 ;
struct V_229 V_54 ;
struct V_55 V_56 ;
struct V_23 * V_26 = NULL ;
struct V_213 * V_214 ;
struct V_23 * V_230 ;
int V_15 ;
struct V_1 * V_2 ;
if ( V_51 < sizeof( V_54 ) )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof( V_52 ) ,
( unsigned long ) V_52 . V_69 + sizeof( V_54 ) ,
V_50 - sizeof( V_52 ) , V_51 - sizeof( V_54 ) ) ;
if ( V_52 . V_231 & ~ V_232 || ! V_52 . V_231 )
return - V_67 ;
if ( ( V_52 . V_231 & V_233 ) &&
( ! V_52 . V_215 || ! V_52 . V_217 || 0 >= V_52 . V_223 ||
( V_52 . V_215 & ~ V_216 ) != ( V_52 . V_217 & ~ V_216 ) ) )
return - V_67 ;
V_2 = F_28 ( & V_224 , V_52 . V_228 ,
V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_214 = V_2 -> V_22 ;
if ( V_52 . V_231 & V_234 ) {
V_15 = F_101 ( V_52 . V_218 ) ;
if ( V_15 )
goto V_235;
}
if ( V_52 . V_231 & V_236 ) {
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_63 ) ;
if ( ! V_26 ) {
V_15 = - V_67 ;
goto V_235;
}
}
if ( F_97 ( & V_214 -> V_172 ) ) {
V_15 = - V_211 ;
goto V_237;
}
V_230 = V_214 -> V_26 ;
V_15 = V_214 -> V_59 -> V_238 ( V_214 , V_52 . V_231 , V_52 . V_215 ,
V_52 . V_223 , V_52 . V_217 ,
V_52 . V_218 , V_26 , & V_56 ) ;
if ( ! V_15 ) {
if ( V_52 . V_231 & V_236 ) {
F_92 ( & V_26 -> V_172 ) ;
V_214 -> V_26 = V_26 ;
F_94 ( & V_230 -> V_172 ) ;
}
} else {
goto V_237;
}
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_226 = V_214 -> V_226 ;
V_54 . V_227 = V_214 -> V_227 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof( V_54 ) ) )
V_15 = - V_66 ;
else
V_15 = V_50 ;
V_237:
if ( V_52 . V_231 & V_236 )
F_32 ( V_26 ) ;
V_235:
F_12 ( V_214 -> V_27 ) ;
return V_15 ;
}
T_2 F_105 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_105 V_52 ;
struct V_213 * V_214 ;
struct V_1 * V_2 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_224 , V_52 . V_228 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_214 = V_2 -> V_22 ;
V_15 = F_103 ( V_214 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_224 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_77 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_106 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_106 V_52 ;
struct V_239 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_240 * V_241 ;
int V_15 ;
if ( V_51 < sizeof( V_54 ) )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_66 ;
V_2 = F_72 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return - V_169 ;
F_1 ( V_2 , 0 , V_48 -> V_63 , & V_242 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_63 ) ;
if ( ! V_26 ) {
V_15 = - V_67 ;
goto V_90;
}
V_241 = V_26 -> V_59 -> V_243 ( V_26 , V_52 . V_244 ) ;
if ( F_50 ( V_241 ) ) {
V_15 = F_51 ( V_241 ) ;
goto V_221;
}
V_241 -> V_59 = V_26 -> V_59 ;
V_241 -> V_26 = V_26 ;
V_241 -> V_27 = V_2 ;
F_92 ( & V_26 -> V_172 ) ;
V_2 -> V_22 = V_241 ;
V_15 = F_14 ( & V_245 , V_2 ) ;
if ( V_15 )
goto V_246;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_227 = V_241 -> V_227 ;
V_54 . V_247 = V_2 -> V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof( V_54 ) ) ) {
V_15 = - V_66 ;
goto V_174;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_73 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_245 , V_2 ) ;
V_246:
F_107 ( V_241 ) ;
V_221:
F_32 ( V_26 ) ;
V_90:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_108 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_108 V_52 ;
struct V_240 * V_241 ;
struct V_1 * V_2 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_66 ;
V_2 = F_28 ( & V_245 , V_52 . V_247 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_241 = V_2 -> V_22 ;
V_15 = F_107 ( V_241 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_245 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_77 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_109 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_109 V_52 ;
struct V_248 V_54 ;
struct V_48 * V_64 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_15 = F_57 ( V_95 ) ;
if ( V_15 < 0 )
return V_15 ;
V_54 . V_194 = V_15 ;
V_64 = F_58 ( V_48 , 0 ) ;
if ( F_50 ( V_64 ) ) {
F_65 ( V_54 . V_194 ) ;
return F_51 ( V_64 ) ;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
F_65 ( V_54 . V_194 ) ;
F_64 ( V_64 ) ;
return - V_66 ;
}
F_62 ( V_54 . V_194 , V_64 ) ;
return V_50 ;
}
T_2 F_110 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_110 V_52 ;
struct V_249 V_54 ;
struct V_55 V_56 ;
struct V_250 * V_193 ;
struct V_251 * V_252 = NULL ;
struct V_28 * V_31 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
if ( V_52 . V_253 >= V_48 -> V_59 -> V_94 )
return - V_67 ;
V_193 = F_72 ( sizeof *V_193 , V_16 ) ;
if ( ! V_193 )
return - V_169 ;
F_1 ( & V_193 -> V_27 , V_52 . V_3 , V_48 -> V_63 , & V_254 ) ;
F_29 ( & V_193 -> V_27 . V_9 ) ;
if ( V_52 . V_255 >= 0 ) {
V_252 = F_111 ( V_52 . V_255 ) ;
if ( ! V_252 ) {
V_15 = - V_67 ;
goto V_68;
}
}
V_193 -> V_256 = V_48 ;
V_193 -> V_257 = 0 ;
V_193 -> V_258 = 0 ;
F_52 ( & V_193 -> V_259 ) ;
F_52 ( & V_193 -> V_260 ) ;
V_31 = V_48 -> V_59 -> V_60 -> V_261 ( V_48 -> V_59 -> V_60 , V_52 . V_262 ,
V_52 . V_253 ,
V_48 -> V_63 , & V_56 ) ;
if ( F_50 ( V_31 ) ) {
V_15 = F_51 ( V_31 ) ;
goto V_98;
}
V_31 -> V_59 = V_48 -> V_59 -> V_60 ;
V_31 -> V_27 = & V_193 -> V_27 ;
V_31 -> V_263 = V_264 ;
V_31 -> V_101 = V_265 ;
V_31 -> V_266 = V_252 ;
F_73 ( & V_31 -> V_172 , 0 ) ;
V_193 -> V_27 . V_22 = V_31 ;
V_15 = F_14 ( & V_30 , & V_193 -> V_27 ) ;
if ( V_15 )
goto V_90;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_29 = V_193 -> V_27 . V_19 ;
V_54 . V_262 = V_31 -> V_262 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_193 -> V_27 . V_175 , & V_48 -> V_63 -> V_74 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_27 . V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_30 , & V_193 -> V_27 ) ;
V_90:
F_112 ( V_31 ) ;
V_98:
if ( V_252 )
F_113 ( V_48 , V_252 , V_193 ) ;
V_68:
F_12 ( & V_193 -> V_27 ) ;
return V_15 ;
}
T_2 F_114 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_114 V_52 ;
struct V_267 V_54 ;
struct V_55 V_56 ;
struct V_28 * V_31 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_63 , 0 ) ;
if ( ! V_31 )
return - V_67 ;
V_15 = V_31 -> V_59 -> V_268 ( V_31 , V_52 . V_262 , & V_56 ) ;
if ( V_15 )
goto V_210;
V_54 . V_262 = V_31 -> V_262 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 . V_262 ) )
V_15 = - V_66 ;
V_210:
F_34 ( V_31 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_115 ( void T_3 * V_269 , struct V_270 * V_271 )
{
struct V_272 V_273 ;
V_273 . V_274 = V_271 -> V_274 ;
V_273 . V_275 = V_271 -> V_275 ;
V_273 . V_276 = V_271 -> V_276 ;
V_273 . V_277 = V_271 -> V_277 ;
V_273 . V_278 = V_271 -> V_278 ;
V_273 . V_279 . V_280 = ( V_281 V_282 ) V_271 -> V_279 . V_280 ;
V_273 . V_283 = V_271 -> V_39 -> V_283 ;
V_273 . V_284 = V_271 -> V_284 ;
V_273 . V_285 = V_271 -> V_285 ;
V_273 . V_286 = V_271 -> V_286 ;
V_273 . V_287 = V_271 -> V_287 ;
V_273 . V_288 = V_271 -> V_288 ;
V_273 . V_289 = V_271 -> V_289 ;
V_273 . V_147 = V_271 -> V_147 ;
V_273 . V_290 = 0 ;
if ( F_59 ( V_269 , & V_273 , sizeof V_273 ) )
return - V_66 ;
return 0 ;
}
T_2 F_116 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_116 V_52 ;
struct V_291 V_54 ;
T_4 T_3 * V_292 ;
T_4 T_3 * V_293 ;
struct V_28 * V_31 ;
struct V_270 V_271 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_63 , 0 ) ;
if ( ! V_31 )
return - V_67 ;
V_292 = ( void T_3 * ) ( unsigned long ) V_52 . V_69 ;
V_293 = V_292 + sizeof V_54 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
while ( V_54 . V_294 < V_52 . V_295 ) {
V_15 = F_117 ( V_31 , 1 , & V_271 ) ;
if ( V_15 < 0 )
goto V_296;
if ( ! V_15 )
break;
V_15 = F_115 ( V_293 , & V_271 ) ;
if ( V_15 )
goto V_296;
V_293 += sizeof( struct V_272 ) ;
++ V_54 . V_294 ;
}
if ( F_59 ( V_292 , & V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_296;
}
V_15 = V_50 ;
V_296:
F_34 ( V_31 ) ;
return V_15 ;
}
T_2 F_118 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_118 V_52 ;
struct V_28 * V_31 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_63 , 0 ) ;
if ( ! V_31 )
return - V_67 ;
F_119 ( V_31 , V_52 . V_297 ?
V_298 : V_299 ) ;
F_34 ( V_31 ) ;
return V_50 ;
}
T_2 F_120 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_120 V_52 ;
struct V_300 V_54 ;
struct V_1 * V_2 ;
struct V_28 * V_31 ;
struct V_250 * V_193 ;
struct V_251 * V_252 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_30 , V_52 . V_29 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_31 = V_2 -> V_22 ;
V_252 = V_31 -> V_266 ;
V_193 = F_7 ( V_31 -> V_27 , struct V_250 , V_27 ) ;
V_15 = F_112 ( V_31 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_30 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_77 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_113 ( V_48 , V_252 , V_193 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_257 = V_193 -> V_257 ;
V_54 . V_258 = V_193 -> V_258 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_121 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_121 V_52 ;
struct V_301 V_54 ;
struct V_55 V_56 ;
struct V_302 * V_193 ;
struct V_57 * V_59 ;
struct V_23 * V_26 = NULL ;
struct V_44 * V_179 = NULL ;
struct V_1 * V_303 ( V_304 ) ;
struct V_28 * V_305 = NULL , * V_306 = NULL ;
struct V_40 * V_43 = NULL ;
struct V_36 * V_39 ;
struct V_307 V_105 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
if ( V_52 . V_308 == V_309 && ! F_122 ( V_310 ) )
return - V_311 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_193 = F_123 ( sizeof *V_193 , V_16 ) ;
if ( ! V_193 )
return - V_169 ;
F_1 ( & V_193 -> V_312 . V_27 , V_52 . V_3 , V_48 -> V_63 , & V_313 ) ;
F_29 ( & V_193 -> V_312 . V_27 . V_9 ) ;
if ( V_52 . V_308 == V_314 ) {
V_179 = F_43 ( V_52 . V_24 , V_48 -> V_63 , & V_304 ) ;
if ( ! V_179 ) {
V_15 = - V_67 ;
goto V_221;
}
V_59 = V_179 -> V_59 ;
} else {
if ( V_52 . V_308 == V_315 ) {
V_52 . V_316 = V_52 . V_317 = 0 ;
} else {
if ( V_52 . V_318 ) {
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_43 || V_43 -> V_319 != V_320 ) {
V_15 = - V_67 ;
goto V_221;
}
}
if ( V_52 . V_321 != V_52 . V_322 ) {
V_306 = F_33 ( V_52 . V_321 , V_48 -> V_63 , 0 ) ;
if ( ! V_306 ) {
V_15 = - V_67 ;
goto V_221;
}
}
}
V_305 = F_33 ( V_52 . V_322 , V_48 -> V_63 , ! ! V_306 ) ;
V_306 = V_306 ? : V_305 ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_63 ) ;
if ( ! V_26 || ! V_305 ) {
V_15 = - V_67 ;
goto V_221;
}
V_59 = V_26 -> V_59 ;
}
V_105 . V_101 = V_323 ;
V_105 . V_324 = V_48 ;
V_105 . V_325 = V_305 ;
V_105 . V_326 = V_306 ;
V_105 . V_43 = V_43 ;
V_105 . V_179 = V_179 ;
V_105 . V_327 = V_52 . V_328 ? V_329 : V_330 ;
V_105 . V_308 = V_52 . V_308 ;
V_105 . V_331 = 0 ;
V_105 . V_332 . V_333 = V_52 . V_333 ;
V_105 . V_332 . V_316 = V_52 . V_316 ;
V_105 . V_332 . V_334 = V_52 . V_334 ;
V_105 . V_332 . V_317 = V_52 . V_317 ;
V_105 . V_332 . V_335 = V_52 . V_335 ;
V_193 -> V_312 . V_336 = 0 ;
F_52 ( & V_193 -> V_312 . V_337 ) ;
F_52 ( & V_193 -> V_338 ) ;
if ( V_52 . V_308 == V_314 )
V_39 = F_124 ( V_26 , & V_105 ) ;
else
V_39 = V_59 -> V_339 ( V_26 , & V_105 , & V_56 ) ;
if ( F_50 ( V_39 ) ) {
V_15 = F_51 ( V_39 ) ;
goto V_221;
}
if ( V_52 . V_308 != V_314 ) {
V_39 -> V_340 = V_39 ;
V_39 -> V_59 = V_59 ;
V_39 -> V_26 = V_26 ;
V_39 -> V_325 = V_105 . V_325 ;
V_39 -> V_326 = V_105 . V_326 ;
V_39 -> V_43 = V_105 . V_43 ;
V_39 -> V_101 = V_105 . V_101 ;
V_39 -> V_324 = V_105 . V_324 ;
V_39 -> V_308 = V_105 . V_308 ;
F_73 ( & V_39 -> V_172 , 0 ) ;
F_92 ( & V_26 -> V_172 ) ;
F_92 ( & V_105 . V_325 -> V_172 ) ;
if ( V_105 . V_326 )
F_92 ( & V_105 . V_326 -> V_172 ) ;
if ( V_105 . V_43 )
F_92 ( & V_105 . V_43 -> V_172 ) ;
}
V_39 -> V_27 = & V_193 -> V_312 . V_27 ;
V_193 -> V_312 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_193 -> V_312 . V_27 ) ;
if ( V_15 )
goto V_341;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_342 = V_39 -> V_283 ;
V_54 . V_37 = V_193 -> V_312 . V_27 . V_19 ;
V_54 . V_317 = V_105 . V_332 . V_317 ;
V_54 . V_334 = V_105 . V_332 . V_334 ;
V_54 . V_316 = V_105 . V_332 . V_316 ;
V_54 . V_333 = V_105 . V_332 . V_333 ;
V_54 . V_335 = V_105 . V_332 . V_335 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
if ( V_179 ) {
V_193 -> V_343 = F_7 ( V_304 , struct V_192 ,
V_27 ) ;
F_92 ( & V_193 -> V_343 -> V_208 ) ;
F_44 ( V_304 ) ;
}
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_305 )
F_34 ( V_305 ) ;
if ( V_306 && V_306 != V_305 )
F_34 ( V_306 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_193 -> V_312 . V_27 . V_175 , & V_48 -> V_63 -> V_75 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_312 . V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_312 . V_27 . V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_38 , & V_193 -> V_312 . V_27 ) ;
V_341:
F_125 ( V_39 ) ;
V_221:
if ( V_179 )
F_44 ( V_304 ) ;
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_305 )
F_34 ( V_305 ) ;
if ( V_306 && V_306 != V_305 )
F_34 ( V_306 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_12 ( & V_193 -> V_312 . V_27 ) ;
return V_15 ;
}
T_2 F_126 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_126 V_52 ;
struct V_301 V_54 ;
struct V_55 V_56 ;
struct V_302 * V_193 ;
struct V_44 * V_179 ;
struct V_1 * V_303 ( V_304 ) ;
struct V_36 * V_39 ;
struct V_344 V_105 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_193 = F_72 ( sizeof *V_193 , V_16 ) ;
if ( ! V_193 )
return - V_169 ;
F_1 ( & V_193 -> V_312 . V_27 , V_52 . V_3 , V_48 -> V_63 , & V_313 ) ;
F_29 ( & V_193 -> V_312 . V_27 . V_9 ) ;
V_179 = F_43 ( V_52 . V_24 , V_48 -> V_63 , & V_304 ) ;
if ( ! V_179 ) {
V_15 = - V_67 ;
goto V_221;
}
V_105 . V_101 = V_323 ;
V_105 . V_324 = V_48 ;
V_105 . V_283 = V_52 . V_342 ;
V_105 . V_308 = V_52 . V_308 ;
V_193 -> V_312 . V_336 = 0 ;
F_52 ( & V_193 -> V_312 . V_337 ) ;
F_52 ( & V_193 -> V_338 ) ;
V_39 = F_127 ( V_179 , & V_105 ) ;
if ( F_50 ( V_39 ) ) {
V_15 = F_51 ( V_39 ) ;
goto V_221;
}
V_39 -> V_27 = & V_193 -> V_312 . V_27 ;
V_193 -> V_312 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_193 -> V_312 . V_27 ) ;
if ( V_15 )
goto V_341;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_342 = V_39 -> V_283 ;
V_54 . V_37 = V_193 -> V_312 . V_27 . V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_345;
}
V_193 -> V_343 = F_7 ( V_304 , struct V_192 , V_27 ) ;
F_92 ( & V_193 -> V_343 -> V_208 ) ;
F_44 ( V_304 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_193 -> V_312 . V_27 . V_175 , & V_48 -> V_63 -> V_75 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_312 . V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_312 . V_27 . V_9 ) ;
return V_50 ;
V_345:
F_20 ( & V_38 , & V_193 -> V_312 . V_27 ) ;
V_341:
F_125 ( V_39 ) ;
V_221:
F_44 ( V_304 ) ;
F_12 ( & V_193 -> V_312 . V_27 ) ;
return V_15 ;
}
T_2 F_128 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_128 V_52 ;
struct V_346 V_54 ;
struct V_36 * V_39 ;
struct V_347 * V_105 ;
struct V_307 * V_348 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_105 = F_72 ( sizeof *V_105 , V_16 ) ;
V_348 = F_72 ( sizeof *V_348 , V_16 ) ;
if ( ! V_105 || ! V_348 ) {
V_15 = - V_169 ;
goto V_210;
}
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 ) {
V_15 = - V_67 ;
goto V_210;
}
V_15 = F_129 ( V_39 , V_105 , V_52 . V_349 , V_348 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
goto V_210;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_350 = V_105 -> V_350 ;
V_54 . V_351 = V_105 -> V_351 ;
V_54 . V_352 = V_105 -> V_352 ;
V_54 . V_353 = V_105 -> V_353 ;
V_54 . V_354 = V_105 -> V_354 ;
V_54 . V_355 = V_105 -> V_355 ;
V_54 . V_356 = V_105 -> V_356 ;
V_54 . V_357 = V_105 -> V_357 ;
V_54 . V_358 = V_105 -> V_358 ;
V_54 . V_286 = V_105 -> V_286 ;
V_54 . V_359 = V_105 -> V_359 ;
V_54 . V_360 = V_105 -> V_360 ;
V_54 . V_361 = V_105 -> V_361 ;
V_54 . V_362 = V_105 -> V_362 ;
V_54 . V_363 = V_105 -> V_363 ;
V_54 . V_147 = V_105 -> V_147 ;
V_54 . V_364 = V_105 -> V_364 ;
V_54 . V_365 = V_105 -> V_365 ;
V_54 . V_366 = V_105 -> V_366 ;
V_54 . V_367 = V_105 -> V_367 ;
V_54 . V_368 = V_105 -> V_368 ;
memcpy ( V_54 . V_269 . V_369 , V_105 -> V_370 . V_371 . V_369 . V_372 , 16 ) ;
V_54 . V_269 . V_373 = V_105 -> V_370 . V_371 . V_373 ;
V_54 . V_269 . V_374 = V_105 -> V_370 . V_371 . V_374 ;
V_54 . V_269 . V_375 = V_105 -> V_370 . V_371 . V_375 ;
V_54 . V_269 . V_376 = V_105 -> V_370 . V_371 . V_376 ;
V_54 . V_269 . V_377 = V_105 -> V_370 . V_377 ;
V_54 . V_269 . V_288 = V_105 -> V_370 . V_288 ;
V_54 . V_269 . V_378 = V_105 -> V_370 . V_378 ;
V_54 . V_269 . V_379 = V_105 -> V_370 . V_379 ;
V_54 . V_269 . V_380 = ! ! ( V_105 -> V_370 . V_381 & V_382 ) ;
V_54 . V_269 . V_147 = V_105 -> V_370 . V_147 ;
memcpy ( V_54 . V_383 . V_369 , V_105 -> V_384 . V_371 . V_369 . V_372 , 16 ) ;
V_54 . V_383 . V_373 = V_105 -> V_384 . V_371 . V_373 ;
V_54 . V_383 . V_374 = V_105 -> V_384 . V_371 . V_374 ;
V_54 . V_383 . V_375 = V_105 -> V_384 . V_371 . V_375 ;
V_54 . V_383 . V_376 = V_105 -> V_384 . V_371 . V_376 ;
V_54 . V_383 . V_377 = V_105 -> V_384 . V_377 ;
V_54 . V_383 . V_288 = V_105 -> V_384 . V_288 ;
V_54 . V_383 . V_378 = V_105 -> V_384 . V_378 ;
V_54 . V_383 . V_379 = V_105 -> V_384 . V_379 ;
V_54 . V_383 . V_380 = ! ! ( V_105 -> V_384 . V_381 & V_382 ) ;
V_54 . V_383 . V_147 = V_105 -> V_384 . V_147 ;
V_54 . V_333 = V_348 -> V_332 . V_333 ;
V_54 . V_316 = V_348 -> V_332 . V_316 ;
V_54 . V_334 = V_348 -> V_332 . V_334 ;
V_54 . V_317 = V_348 -> V_332 . V_317 ;
V_54 . V_335 = V_348 -> V_332 . V_335 ;
V_54 . V_328 = V_348 -> V_327 == V_329 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
V_210:
F_6 ( V_105 ) ;
F_6 ( V_348 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_130 ( enum V_385 V_308 , int V_386 )
{
switch ( V_308 ) {
case V_315 :
return V_386 & ~ ( V_387 | V_388 ) ;
case V_314 :
return V_386 & ~ ( V_389 | V_390 |
V_391 ) ;
default:
return V_386 ;
}
}
T_2 F_131 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_131 V_52 ;
struct V_55 V_56 ;
struct V_36 * V_39 ;
struct V_347 * V_105 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 , NULL , V_50 - sizeof V_52 ,
V_51 ) ;
V_105 = F_72 ( sizeof *V_105 , V_16 ) ;
if ( ! V_105 )
return - V_169 ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 ) {
V_15 = - V_67 ;
goto V_210;
}
V_105 -> V_350 = V_52 . V_350 ;
V_105 -> V_351 = V_52 . V_351 ;
V_105 -> V_352 = V_52 . V_352 ;
V_105 -> V_353 = V_52 . V_353 ;
V_105 -> V_354 = V_52 . V_354 ;
V_105 -> V_355 = V_52 . V_355 ;
V_105 -> V_356 = V_52 . V_356 ;
V_105 -> V_357 = V_52 . V_357 ;
V_105 -> V_358 = V_52 . V_358 ;
V_105 -> V_286 = V_52 . V_286 ;
V_105 -> V_359 = V_52 . V_359 ;
V_105 -> V_392 = V_52 . V_392 ;
V_105 -> V_361 = V_52 . V_361 ;
V_105 -> V_362 = V_52 . V_362 ;
V_105 -> V_363 = V_52 . V_363 ;
V_105 -> V_147 = V_52 . V_147 ;
V_105 -> V_364 = V_52 . V_364 ;
V_105 -> V_365 = V_52 . V_365 ;
V_105 -> V_366 = V_52 . V_366 ;
V_105 -> V_367 = V_52 . V_367 ;
V_105 -> V_368 = V_52 . V_368 ;
memcpy ( V_105 -> V_370 . V_371 . V_369 . V_372 , V_52 . V_269 . V_369 , 16 ) ;
V_105 -> V_370 . V_371 . V_373 = V_52 . V_269 . V_373 ;
V_105 -> V_370 . V_371 . V_374 = V_52 . V_269 . V_374 ;
V_105 -> V_370 . V_371 . V_375 = V_52 . V_269 . V_375 ;
V_105 -> V_370 . V_371 . V_376 = V_52 . V_269 . V_376 ;
V_105 -> V_370 . V_377 = V_52 . V_269 . V_377 ;
V_105 -> V_370 . V_288 = V_52 . V_269 . V_288 ;
V_105 -> V_370 . V_378 = V_52 . V_269 . V_378 ;
V_105 -> V_370 . V_379 = V_52 . V_269 . V_379 ;
V_105 -> V_370 . V_381 = V_52 . V_269 . V_380 ? V_382 : 0 ;
V_105 -> V_370 . V_147 = V_52 . V_269 . V_147 ;
memcpy ( V_105 -> V_384 . V_371 . V_369 . V_372 , V_52 . V_383 . V_369 , 16 ) ;
V_105 -> V_384 . V_371 . V_373 = V_52 . V_383 . V_373 ;
V_105 -> V_384 . V_371 . V_374 = V_52 . V_383 . V_374 ;
V_105 -> V_384 . V_371 . V_375 = V_52 . V_383 . V_375 ;
V_105 -> V_384 . V_371 . V_376 = V_52 . V_383 . V_376 ;
V_105 -> V_384 . V_377 = V_52 . V_383 . V_377 ;
V_105 -> V_384 . V_288 = V_52 . V_383 . V_288 ;
V_105 -> V_384 . V_378 = V_52 . V_383 . V_378 ;
V_105 -> V_384 . V_379 = V_52 . V_383 . V_379 ;
V_105 -> V_384 . V_381 = V_52 . V_383 . V_380 ? V_382 : 0 ;
V_105 -> V_384 . V_147 = V_52 . V_383 . V_147 ;
if ( V_39 -> V_340 == V_39 ) {
V_15 = F_132 ( V_39 , V_105 , & V_52 . V_349 ) ;
if ( V_15 )
goto V_210;
V_15 = V_39 -> V_59 -> V_393 ( V_39 , V_105 ,
F_130 ( V_39 -> V_308 , V_52 . V_349 ) , & V_56 ) ;
} else {
V_15 = F_133 ( V_39 , V_105 , F_130 ( V_39 -> V_308 , V_52 . V_349 ) ) ;
}
F_39 ( V_39 ) ;
if ( V_15 )
goto V_210;
V_15 = V_50 ;
V_210:
F_6 ( V_105 ) ;
return V_15 ;
}
T_2 F_134 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_134 V_52 ;
struct V_394 V_54 ;
struct V_1 * V_2 ;
struct V_36 * V_39 ;
struct V_302 * V_193 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_2 = F_28 ( & V_38 , V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_39 = V_2 -> V_22 ;
V_193 = F_7 ( V_2 , struct V_302 , V_312 . V_27 ) ;
if ( ! F_135 ( & V_193 -> V_338 ) ) {
F_12 ( V_2 ) ;
return - V_211 ;
}
V_15 = F_125 ( V_39 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_193 -> V_343 )
F_94 ( & V_193 -> V_343 -> V_208 ) ;
F_20 ( & V_38 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_77 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_136 ( V_48 , & V_193 -> V_312 ) ;
V_54 . V_336 = V_193 -> V_312 . V_336 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_137 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_137 V_52 ;
struct V_395 V_54 ;
struct V_396 * V_397 ;
struct V_398 * V_399 = NULL , * V_400 , * V_401 , * V_402 ;
struct V_36 * V_39 ;
int V_403 , V_404 ;
int V_405 ;
T_2 V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
if ( V_50 < sizeof V_52 + V_52 . V_406 * V_52 . V_407 +
V_52 . V_408 * sizeof ( struct V_409 ) )
return - V_67 ;
if ( V_52 . V_406 < sizeof ( struct V_396 ) )
return - V_67 ;
V_397 = F_72 ( V_52 . V_406 , V_16 ) ;
if ( ! V_397 )
return - V_169 ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 )
goto V_210;
V_405 = V_39 -> V_308 == V_410 ;
V_404 = 0 ;
V_400 = NULL ;
for ( V_403 = 0 ; V_403 < V_52 . V_407 ; ++ V_403 ) {
if ( F_47 ( V_397 ,
V_49 + sizeof V_52 + V_403 * V_52 . V_406 ,
V_52 . V_406 ) ) {
V_15 = - V_66 ;
goto V_296;
}
if ( V_397 -> V_411 + V_404 > V_52 . V_408 ) {
V_15 = - V_67 ;
goto V_296;
}
V_401 = F_72 ( F_138 ( sizeof *V_401 , sizeof ( struct V_412 ) ) +
V_397 -> V_411 * sizeof ( struct V_412 ) ,
V_16 ) ;
if ( ! V_401 ) {
V_15 = - V_169 ;
goto V_296;
}
if ( ! V_400 )
V_399 = V_401 ;
else
V_400 -> V_401 = V_401 ;
V_400 = V_401 ;
V_401 -> V_401 = NULL ;
V_401 -> V_274 = V_397 -> V_274 ;
V_401 -> V_411 = V_397 -> V_411 ;
V_401 -> V_276 = V_397 -> V_276 ;
V_401 -> V_413 = V_397 -> V_413 ;
if ( V_405 ) {
V_401 -> V_399 . V_414 . V_35 = F_35 ( V_397 -> V_399 . V_414 . V_35 ,
V_48 -> V_63 ) ;
if ( ! V_401 -> V_399 . V_414 . V_35 ) {
V_15 = - V_67 ;
goto V_296;
}
V_401 -> V_399 . V_414 . V_415 = V_397 -> V_399 . V_414 . V_415 ;
V_401 -> V_399 . V_414 . V_416 = V_397 -> V_399 . V_414 . V_416 ;
if ( V_401 -> V_276 == V_417 )
V_401 -> V_279 . V_280 =
( V_418 V_282 ) V_397 -> V_279 . V_280 ;
} else {
switch ( V_401 -> V_276 ) {
case V_419 :
V_401 -> V_279 . V_280 =
( V_418 V_282 ) V_397 -> V_279 . V_280 ;
case V_420 :
case V_421 :
V_401 -> V_399 . V_422 . V_423 =
V_397 -> V_399 . V_422 . V_423 ;
V_401 -> V_399 . V_422 . V_227 =
V_397 -> V_399 . V_422 . V_227 ;
break;
case V_417 :
V_401 -> V_279 . V_280 =
( V_418 V_282 ) V_397 -> V_279 . V_280 ;
break;
case V_424 :
V_401 -> V_279 . V_425 =
V_397 -> V_279 . V_425 ;
break;
case V_426 :
case V_427 :
V_401 -> V_399 . V_428 . V_423 =
V_397 -> V_399 . V_428 . V_423 ;
V_401 -> V_399 . V_428 . V_429 =
V_397 -> V_399 . V_428 . V_429 ;
V_401 -> V_399 . V_428 . V_430 = V_397 -> V_399 . V_428 . V_430 ;
V_401 -> V_399 . V_428 . V_227 = V_397 -> V_399 . V_428 . V_227 ;
break;
default:
break;
}
}
if ( V_401 -> V_411 ) {
V_401 -> V_431 = ( void * ) V_401 +
F_138 ( sizeof *V_401 , sizeof ( struct V_412 ) ) ;
if ( F_47 ( V_401 -> V_431 ,
V_49 + sizeof V_52 +
V_52 . V_407 * V_52 . V_406 +
V_404 * sizeof ( struct V_412 ) ,
V_401 -> V_411 * sizeof ( struct V_412 ) ) ) {
V_15 = - V_66 ;
goto V_296;
}
V_404 += V_401 -> V_411 ;
} else
V_401 -> V_431 = NULL ;
}
V_54 . V_402 = 0 ;
V_15 = V_39 -> V_59 -> V_432 ( V_39 -> V_340 , V_399 , & V_402 ) ;
if ( V_15 )
for ( V_401 = V_399 ; V_401 ; V_401 = V_401 -> V_401 ) {
++ V_54 . V_402 ;
if ( V_401 == V_402 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
V_296:
F_39 ( V_39 ) ;
while ( V_399 ) {
if ( V_405 && V_399 -> V_399 . V_414 . V_35 )
F_36 ( V_399 -> V_399 . V_414 . V_35 ) ;
V_401 = V_399 -> V_401 ;
F_6 ( V_399 ) ;
V_399 = V_401 ;
}
V_210:
F_6 ( V_397 ) ;
return V_15 ? V_15 : V_50 ;
}
static struct V_433 * F_139 ( const char T_3 * V_49 ,
int V_50 ,
T_5 V_407 ,
T_5 V_408 ,
T_5 V_406 )
{
struct V_434 * V_397 ;
struct V_433 * V_399 = NULL , * V_400 , * V_401 ;
int V_404 ;
int V_403 ;
int V_15 ;
if ( V_50 < V_406 * V_407 +
V_408 * sizeof ( struct V_409 ) )
return F_140 ( - V_67 ) ;
if ( V_406 < sizeof ( struct V_434 ) )
return F_140 ( - V_67 ) ;
V_397 = F_72 ( V_406 , V_16 ) ;
if ( ! V_397 )
return F_140 ( - V_169 ) ;
V_404 = 0 ;
V_400 = NULL ;
for ( V_403 = 0 ; V_403 < V_407 ; ++ V_403 ) {
if ( F_47 ( V_397 , V_49 + V_403 * V_406 ,
V_406 ) ) {
V_15 = - V_66 ;
goto V_68;
}
if ( V_397 -> V_411 + V_404 > V_408 ) {
V_15 = - V_67 ;
goto V_68;
}
V_401 = F_72 ( F_138 ( sizeof *V_401 , sizeof ( struct V_412 ) ) +
V_397 -> V_411 * sizeof ( struct V_412 ) ,
V_16 ) ;
if ( ! V_401 ) {
V_15 = - V_169 ;
goto V_68;
}
if ( ! V_400 )
V_399 = V_401 ;
else
V_400 -> V_401 = V_401 ;
V_400 = V_401 ;
V_401 -> V_401 = NULL ;
V_401 -> V_274 = V_397 -> V_274 ;
V_401 -> V_411 = V_397 -> V_411 ;
if ( V_401 -> V_411 ) {
V_401 -> V_431 = ( void * ) V_401 +
F_138 ( sizeof *V_401 , sizeof ( struct V_412 ) ) ;
if ( F_47 ( V_401 -> V_431 ,
V_49 + V_407 * V_406 +
V_404 * sizeof ( struct V_412 ) ,
V_401 -> V_411 * sizeof ( struct V_412 ) ) ) {
V_15 = - V_66 ;
goto V_68;
}
V_404 += V_401 -> V_411 ;
} else
V_401 -> V_431 = NULL ;
}
F_6 ( V_397 ) ;
return V_399 ;
V_68:
F_6 ( V_397 ) ;
while ( V_399 ) {
V_401 = V_399 -> V_401 ;
F_6 ( V_399 ) ;
V_399 = V_401 ;
}
return F_140 ( V_15 ) ;
}
T_2 F_141 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_141 V_52 ;
struct V_435 V_54 ;
struct V_433 * V_399 , * V_401 , * V_402 ;
struct V_36 * V_39 ;
T_2 V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_399 = F_139 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_407 ,
V_52 . V_408 , V_52 . V_406 ) ;
if ( F_50 ( V_399 ) )
return F_51 ( V_399 ) ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 )
goto V_210;
V_54 . V_402 = 0 ;
V_15 = V_39 -> V_59 -> V_436 ( V_39 -> V_340 , V_399 , & V_402 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
for ( V_401 = V_399 ; V_401 ; V_401 = V_401 -> V_401 ) {
++ V_54 . V_402 ;
if ( V_401 == V_402 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
V_210:
while ( V_399 ) {
V_401 = V_399 -> V_401 ;
F_6 ( V_399 ) ;
V_399 = V_401 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_142 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_142 V_52 ;
struct V_437 V_54 ;
struct V_433 * V_399 , * V_401 , * V_402 ;
struct V_40 * V_43 ;
T_2 V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_399 = F_139 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_407 ,
V_52 . V_408 , V_52 . V_406 ) ;
if ( F_50 ( V_399 ) )
return F_51 ( V_399 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_43 )
goto V_210;
V_54 . V_402 = 0 ;
V_15 = V_43 -> V_59 -> V_438 ( V_43 , V_399 , & V_402 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
for ( V_401 = V_399 ; V_401 ; V_401 = V_401 -> V_401 ) {
++ V_54 . V_402 ;
if ( V_401 == V_402 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
V_210:
while ( V_399 ) {
V_401 = V_399 -> V_401 ;
F_6 ( V_399 ) ;
V_399 = V_401 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_143 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_143 V_52 ;
struct V_439 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_32 * V_35 ;
struct V_440 V_105 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_72 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_169 ;
F_1 ( V_2 , V_52 . V_3 , V_48 -> V_63 , & V_441 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_63 ) ;
if ( ! V_26 ) {
V_15 = - V_67 ;
goto V_68;
}
V_105 . V_377 = V_52 . V_105 . V_377 ;
V_105 . V_288 = V_52 . V_105 . V_288 ;
V_105 . V_378 = V_52 . V_105 . V_378 ;
V_105 . V_379 = V_52 . V_105 . V_379 ;
V_105 . V_381 = V_52 . V_105 . V_380 ? V_382 : 0 ;
V_105 . V_147 = V_52 . V_105 . V_147 ;
V_105 . V_371 . V_373 = V_52 . V_105 . V_371 . V_373 ;
V_105 . V_371 . V_374 = V_52 . V_105 . V_371 . V_374 ;
V_105 . V_371 . V_375 = V_52 . V_105 . V_371 . V_375 ;
V_105 . V_371 . V_376 = V_52 . V_105 . V_371 . V_376 ;
V_105 . V_442 = 0 ;
memset ( & V_105 . V_443 , 0 , sizeof( V_105 . V_443 ) ) ;
memcpy ( V_105 . V_371 . V_369 . V_372 , V_52 . V_105 . V_371 . V_369 , 16 ) ;
V_35 = F_144 ( V_26 , & V_105 ) ;
if ( F_50 ( V_35 ) ) {
V_15 = F_51 ( V_35 ) ;
goto V_221;
}
V_35 -> V_27 = V_2 ;
V_2 -> V_22 = V_35 ;
V_15 = F_14 ( & V_34 , V_2 ) ;
if ( V_15 )
goto V_341;
V_54 . V_33 = V_2 -> V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_77 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_34 , V_2 ) ;
V_341:
F_145 ( V_35 ) ;
V_221:
F_32 ( V_26 ) ;
V_68:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_146 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_146 V_52 ;
struct V_32 * V_35 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_34 , V_52 . V_33 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_35 = V_2 -> V_22 ;
V_15 = F_145 ( V_35 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_34 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_77 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_147 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_147 V_52 ;
struct V_36 * V_39 ;
struct V_302 * V_193 ;
struct V_444 * V_445 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 )
return - V_67 ;
V_193 = F_7 ( V_39 -> V_27 , struct V_302 , V_312 . V_27 ) ;
F_148 (mcast, &obj->mcast_list, list)
if ( V_52 . V_446 == V_445 -> V_157 &&
! memcmp ( V_52 . V_447 , V_445 -> V_447 . V_372 , sizeof V_445 -> V_447 . V_372 ) ) {
V_15 = 0 ;
goto V_296;
}
V_445 = F_72 ( sizeof *V_445 , V_16 ) ;
if ( ! V_445 ) {
V_15 = - V_169 ;
goto V_296;
}
V_445 -> V_157 = V_52 . V_446 ;
memcpy ( V_445 -> V_447 . V_372 , V_52 . V_447 , sizeof V_445 -> V_447 . V_372 ) ;
V_15 = F_149 ( V_39 , & V_445 -> V_447 , V_52 . V_446 ) ;
if ( ! V_15 )
F_74 ( & V_445 -> V_175 , & V_193 -> V_338 ) ;
else
F_6 ( V_445 ) ;
V_296:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_150 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_150 V_52 ;
struct V_302 * V_193 ;
struct V_36 * V_39 ;
struct V_444 * V_445 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 )
return - V_67 ;
V_15 = F_151 ( V_39 , (union V_448 * ) V_52 . V_447 , V_52 . V_446 ) ;
if ( V_15 )
goto V_296;
V_193 = F_7 ( V_39 -> V_27 , struct V_302 , V_312 . V_27 ) ;
F_148 (mcast, &obj->mcast_list, list)
if ( V_52 . V_446 == V_445 -> V_157 &&
! memcmp ( V_52 . V_447 , V_445 -> V_447 . V_372 , sizeof V_445 -> V_447 . V_372 ) ) {
F_77 ( & V_445 -> V_175 ) ;
F_6 ( V_445 ) ;
break;
}
V_296:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_152 ( struct V_449 * V_450 ,
union V_451 * V_452 )
{
if ( V_450 -> V_290 )
return - V_67 ;
V_452 -> type = V_450 -> type ;
switch ( V_452 -> type ) {
case V_453 :
V_452 -> V_454 . V_455 = sizeof( struct V_456 ) ;
if ( V_452 -> V_454 . V_455 != V_450 -> V_454 . V_455 )
return - V_67 ;
memcpy ( & V_452 -> V_454 . V_457 , & V_450 -> V_454 . V_457 ,
sizeof( struct V_458 ) ) ;
memcpy ( & V_452 -> V_454 . V_386 , & V_450 -> V_454 . V_386 ,
sizeof( struct V_458 ) ) ;
break;
case V_459 :
V_452 -> V_460 . V_455 = sizeof( struct V_461 ) ;
if ( V_452 -> V_460 . V_455 != V_450 -> V_460 . V_455 )
return - V_67 ;
memcpy ( & V_452 -> V_460 . V_457 , & V_450 -> V_460 . V_457 ,
sizeof( struct V_462 ) ) ;
memcpy ( & V_452 -> V_460 . V_386 , & V_450 -> V_460 . V_386 ,
sizeof( struct V_462 ) ) ;
break;
case V_463 :
case V_464 :
V_452 -> V_465 . V_455 = sizeof( struct V_466 ) ;
if ( V_452 -> V_465 . V_455 != V_450 -> V_465 . V_455 )
return - V_67 ;
memcpy ( & V_452 -> V_465 . V_457 , & V_450 -> V_465 . V_457 ,
sizeof( struct V_467 ) ) ;
memcpy ( & V_452 -> V_465 . V_386 , & V_450 -> V_465 . V_386 ,
sizeof( struct V_467 ) ) ;
break;
default:
return - V_67 ;
}
return 0 ;
}
int F_153 ( struct V_47 * V_48 ,
struct V_55 * V_468 ,
struct V_55 * V_469 )
{
struct V_470 V_52 ;
struct V_471 V_54 ;
struct V_1 * V_2 ;
struct V_472 * V_473 ;
struct V_474 * V_475 ;
struct V_476 * V_477 ;
struct V_36 * V_39 ;
int V_68 = 0 ;
void * V_450 ;
void * V_452 ;
int V_403 ;
if ( V_468 -> V_478 < sizeof( V_52 ) )
return - V_67 ;
if ( V_468 -> V_479 < sizeof( V_54 ) )
return - V_65 ;
V_68 = F_154 ( & V_52 , V_468 , sizeof( V_52 ) ) ;
if ( V_68 )
return V_68 ;
V_468 -> V_480 += sizeof( V_52 ) ;
V_468 -> V_478 -= sizeof( V_52 ) ;
if ( V_52 . V_481 )
return - V_67 ;
if ( ( V_52 . V_477 . type == V_482 &&
! F_122 ( V_483 ) ) || ! F_122 ( V_310 ) )
return - V_311 ;
if ( V_52 . V_477 . V_484 > V_485 )
return - V_67 ;
if ( V_52 . V_477 . V_455 > V_468 -> V_478 ||
V_52 . V_477 . V_455 >
( V_52 . V_477 . V_484 * sizeof( struct V_449 ) ) )
return - V_67 ;
if ( V_52 . V_477 . V_290 [ 0 ] ||
V_52 . V_477 . V_290 [ 1 ] )
return - V_67 ;
if ( V_52 . V_477 . V_484 ) {
V_475 = F_72 ( sizeof( * V_475 ) + V_52 . V_477 . V_455 ,
V_16 ) ;
if ( ! V_475 )
return - V_169 ;
memcpy ( V_475 , & V_52 . V_477 , sizeof( * V_475 ) ) ;
V_68 = F_154 ( V_475 + 1 , V_468 ,
V_52 . V_477 . V_455 ) ;
if ( V_68 )
goto V_486;
} else {
V_475 = & V_52 . V_477 ;
}
V_2 = F_72 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 ) {
V_68 = - V_169 ;
goto V_486;
}
F_1 ( V_2 , 0 , V_48 -> V_63 , & V_487 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 ) {
V_68 = - V_67 ;
goto V_488;
}
V_477 = F_72 ( sizeof( * V_477 ) + V_52 . V_477 . V_455 , V_16 ) ;
if ( ! V_477 ) {
V_68 = - V_169 ;
goto V_221;
}
V_477 -> type = V_475 -> type ;
V_477 -> V_489 = V_475 -> V_489 ;
V_477 -> V_484 = V_475 -> V_484 ;
V_477 -> V_490 = V_475 -> V_490 ;
V_477 -> V_231 = V_475 -> V_231 ;
V_477 -> V_455 = sizeof( * V_477 ) ;
V_450 = V_475 + 1 ;
V_452 = V_477 + 1 ;
for ( V_403 = 0 ; V_403 < V_477 -> V_484 &&
V_52 . V_477 . V_455 > F_155 ( struct V_449 , V_290 ) &&
V_52 . V_477 . V_455 >=
( (struct V_449 * ) V_450 ) -> V_455 ; V_403 ++ ) {
V_68 = F_152 ( V_450 , V_452 ) ;
if ( V_68 )
goto V_90;
V_477 -> V_455 +=
( (union V_451 * ) V_452 ) -> V_455 ;
V_52 . V_477 . V_455 -= ( (struct V_449 * ) V_450 ) -> V_455 ;
V_450 += ( (struct V_449 * ) V_450 ) -> V_455 ;
V_452 += ( (union V_451 * ) V_452 ) -> V_455 ;
}
if ( V_52 . V_477 . V_455 || ( V_403 != V_477 -> V_484 ) ) {
F_156 ( L_2 ,
V_403 , V_52 . V_477 . V_455 ) ;
V_68 = - V_67 ;
goto V_90;
}
V_473 = F_157 ( V_39 , V_477 , V_491 ) ;
if ( F_50 ( V_473 ) ) {
V_68 = F_51 ( V_473 ) ;
goto V_90;
}
V_473 -> V_39 = V_39 ;
V_473 -> V_27 = V_2 ;
V_2 -> V_22 = V_473 ;
V_68 = F_14 ( & V_492 , V_2 ) ;
if ( V_68 )
goto V_493;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_494 = V_2 -> V_19 ;
V_68 = F_158 ( V_468 ,
& V_54 , sizeof( V_54 ) ) ;
if ( V_68 )
goto V_174;
F_39 ( V_39 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_79 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_6 ( V_477 ) ;
if ( V_52 . V_477 . V_484 )
F_6 ( V_475 ) ;
return 0 ;
V_174:
F_20 ( & V_492 , V_2 ) ;
V_493:
F_159 ( V_473 ) ;
V_90:
F_6 ( V_477 ) ;
V_221:
F_39 ( V_39 ) ;
V_488:
F_12 ( V_2 ) ;
V_486:
if ( V_52 . V_477 . V_484 )
F_6 ( V_475 ) ;
return V_68 ;
}
int F_160 ( struct V_47 * V_48 ,
struct V_55 * V_468 ,
struct V_55 * V_469 )
{
struct V_495 V_52 ;
struct V_472 * V_473 ;
struct V_1 * V_2 ;
int V_15 ;
if ( V_468 -> V_478 < sizeof( V_52 ) )
return - V_67 ;
V_15 = F_154 ( & V_52 , V_468 , sizeof( V_52 ) ) ;
if ( V_15 )
return V_15 ;
if ( V_52 . V_481 )
return - V_67 ;
V_2 = F_28 ( & V_492 , V_52 . V_494 ,
V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_473 = V_2 -> V_22 ;
V_15 = F_159 ( V_473 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_492 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_77 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_15 ;
}
static int F_161 ( struct V_47 * V_48 ,
struct V_496 * V_52 ,
struct V_55 * V_56 )
{
struct V_497 V_54 ;
struct V_498 * V_193 ;
struct V_23 * V_26 ;
struct V_40 * V_43 ;
struct V_1 * V_303 ( V_304 ) ;
struct V_499 V_105 ;
int V_15 ;
V_193 = F_72 ( sizeof *V_193 , V_16 ) ;
if ( ! V_193 )
return - V_169 ;
F_1 ( & V_193 -> V_312 . V_27 , V_52 -> V_3 , V_48 -> V_63 , & V_500 ) ;
F_29 ( & V_193 -> V_312 . V_27 . V_9 ) ;
if ( V_52 -> V_319 == V_501 ) {
V_105 . V_502 . V_503 . V_179 = F_43 ( V_52 -> V_45 , V_48 -> V_63 , & V_304 ) ;
if ( ! V_105 . V_502 . V_503 . V_179 ) {
V_15 = - V_67 ;
goto V_68;
}
V_193 -> V_343 = F_7 ( V_304 , struct V_192 , V_27 ) ;
F_92 ( & V_193 -> V_343 -> V_208 ) ;
V_105 . V_502 . V_503 . V_31 = F_33 ( V_52 -> V_29 , V_48 -> V_63 , 0 ) ;
if ( ! V_105 . V_502 . V_503 . V_31 ) {
V_15 = - V_67 ;
goto V_504;
}
}
V_26 = F_31 ( V_52 -> V_24 , V_48 -> V_63 ) ;
if ( ! V_26 ) {
V_15 = - V_67 ;
goto V_505;
}
V_105 . V_101 = V_506 ;
V_105 . V_507 = V_48 ;
V_105 . V_319 = V_52 -> V_319 ;
V_105 . V_105 . V_508 = V_52 -> V_508 ;
V_105 . V_105 . V_116 = V_52 -> V_116 ;
V_105 . V_105 . V_509 = V_52 -> V_509 ;
V_193 -> V_312 . V_336 = 0 ;
F_52 ( & V_193 -> V_312 . V_337 ) ;
V_43 = V_26 -> V_59 -> V_510 ( V_26 , & V_105 , V_56 ) ;
if ( F_50 ( V_43 ) ) {
V_15 = F_51 ( V_43 ) ;
goto V_221;
}
V_43 -> V_59 = V_26 -> V_59 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_319 = V_52 -> V_319 ;
V_43 -> V_27 = & V_193 -> V_312 . V_27 ;
V_43 -> V_101 = V_105 . V_101 ;
V_43 -> V_507 = V_105 . V_507 ;
if ( V_52 -> V_319 == V_501 ) {
V_43 -> V_502 . V_503 . V_31 = V_105 . V_502 . V_503 . V_31 ;
V_43 -> V_502 . V_503 . V_179 = V_105 . V_502 . V_503 . V_179 ;
F_92 ( & V_105 . V_502 . V_503 . V_31 -> V_172 ) ;
F_92 ( & V_105 . V_502 . V_503 . V_179 -> V_172 ) ;
}
F_92 ( & V_26 -> V_172 ) ;
F_73 ( & V_43 -> V_172 , 0 ) ;
V_193 -> V_312 . V_27 . V_22 = V_43 ;
V_15 = F_14 ( & V_42 , & V_193 -> V_312 . V_27 ) ;
if ( V_15 )
goto V_341;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_41 = V_193 -> V_312 . V_27 . V_19 ;
V_54 . V_508 = V_105 . V_105 . V_508 ;
V_54 . V_116 = V_105 . V_105 . V_116 ;
if ( V_52 -> V_319 == V_501 )
V_54 . V_511 = V_43 -> V_502 . V_503 . V_512 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 -> V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
if ( V_52 -> V_319 == V_501 ) {
F_10 ( V_304 ) ;
F_34 ( V_105 . V_502 . V_503 . V_31 ) ;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_74 ( & V_193 -> V_312 . V_27 . V_175 , & V_48 -> V_63 -> V_76 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_312 . V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_312 . V_27 . V_9 ) ;
return 0 ;
V_174:
F_20 ( & V_42 , & V_193 -> V_312 . V_27 ) ;
V_341:
F_162 ( V_43 ) ;
V_221:
F_32 ( V_26 ) ;
V_505:
if ( V_52 -> V_319 == V_501 )
F_34 ( V_105 . V_502 . V_503 . V_31 ) ;
V_504:
if ( V_52 -> V_319 == V_501 ) {
F_94 ( & V_193 -> V_343 -> V_208 ) ;
F_10 ( V_304 ) ;
}
V_68:
F_12 ( & V_193 -> V_312 . V_27 ) ;
return V_15 ;
}
T_2 F_163 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_163 V_52 ;
struct V_496 V_513 ;
struct V_497 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_513 . V_69 = V_52 . V_69 ;
V_513 . V_3 = V_52 . V_3 ;
V_513 . V_319 = V_320 ;
V_513 . V_24 = V_52 . V_24 ;
V_513 . V_508 = V_52 . V_508 ;
V_513 . V_116 = V_52 . V_116 ;
V_513 . V_509 = V_52 . V_509 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_161 ( V_48 , & V_513 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 V_496 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct V_496 V_52 ;
struct V_497 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_161 ( V_48 , & V_52 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 F_164 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_164 V_52 ;
struct V_55 V_56 ;
struct V_40 * V_43 ;
struct V_514 V_105 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 , NULL , V_50 - sizeof V_52 ,
V_51 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_43 )
return - V_67 ;
V_105 . V_508 = V_52 . V_508 ;
V_105 . V_509 = V_52 . V_509 ;
V_15 = V_43 -> V_59 -> V_515 ( V_43 , & V_105 , V_52 . V_349 , & V_56 ) ;
F_42 ( V_43 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_165 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_165 V_52 ;
struct V_516 V_54 ;
struct V_514 V_105 ;
struct V_40 * V_43 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_43 )
return - V_67 ;
V_15 = F_166 ( V_43 , & V_105 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_508 = V_105 . V_508 ;
V_54 . V_116 = V_105 . V_116 ;
V_54 . V_509 = V_105 . V_509 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_167 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_167 V_52 ;
struct V_517 V_54 ;
struct V_1 * V_2 ;
struct V_40 * V_43 ;
struct V_518 * V_193 ;
int V_15 = - V_67 ;
struct V_498 * V_519 ;
enum V_520 V_319 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_42 , V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_43 = V_2 -> V_22 ;
V_193 = F_7 ( V_2 , struct V_518 , V_27 ) ;
V_319 = V_43 -> V_319 ;
V_15 = F_162 ( V_43 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_319 == V_501 ) {
V_519 = F_7 ( V_193 , struct V_498 , V_312 ) ;
F_94 ( & V_519 -> V_343 -> V_208 ) ;
}
F_20 ( & V_42 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_77 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_136 ( V_48 , V_193 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_336 = V_193 -> V_336 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
return V_15 ? V_15 : V_50 ;
}
