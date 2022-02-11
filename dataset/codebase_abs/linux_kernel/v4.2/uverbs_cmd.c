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
static void F_67 ( struct V_47 * V_48 ,
struct V_104 * V_54 ,
struct V_61 * V_105 )
{
V_54 -> V_106 = V_105 -> V_106 ;
V_54 -> V_107 = V_48 -> V_59 -> V_60 -> V_107 ;
V_54 -> V_108 = V_105 -> V_108 ;
V_54 -> V_109 = V_105 -> V_109 ;
V_54 -> V_110 = V_105 -> V_110 ;
V_54 -> V_111 = V_105 -> V_111 ;
V_54 -> V_112 = V_105 -> V_112 ;
V_54 -> V_113 = V_105 -> V_113 ;
V_54 -> V_114 = V_105 -> V_114 ;
V_54 -> V_115 = V_105 -> V_115 ;
V_54 -> V_91 = V_105 -> V_91 ;
V_54 -> V_116 = V_105 -> V_116 ;
V_54 -> V_117 = V_105 -> V_117 ;
V_54 -> V_118 = V_105 -> V_118 ;
V_54 -> V_119 = V_105 -> V_119 ;
V_54 -> V_120 = V_105 -> V_120 ;
V_54 -> V_121 = V_105 -> V_121 ;
V_54 -> V_122 = V_105 -> V_122 ;
V_54 -> V_123 = V_105 -> V_123 ;
V_54 -> V_124 = V_105 -> V_124 ;
V_54 -> V_125 = V_105 -> V_125 ;
V_54 -> V_126 = V_105 -> V_126 ;
V_54 -> V_127 = V_105 -> V_127 ;
V_54 -> V_128 = V_105 -> V_128 ;
V_54 -> V_129 = V_105 -> V_129 ;
V_54 -> V_130 = V_105 -> V_130 ;
V_54 -> V_131 = V_105 -> V_131 ;
V_54 -> V_132 = V_105 -> V_132 ;
V_54 -> V_133 = V_105 -> V_133 ;
V_54 -> V_134 = V_105 -> V_134 ;
V_54 -> V_135 = V_105 -> V_135 ;
V_54 -> V_136 = V_105 -> V_136 ;
V_54 -> V_137 = V_105 -> V_137 ;
V_54 -> V_138 = V_105 -> V_138 ;
V_54 -> V_139 = V_105 -> V_139 ;
V_54 -> V_140 = V_105 -> V_140 ;
V_54 -> V_141 = V_105 -> V_141 ;
V_54 -> V_142 = V_105 -> V_142 ;
V_54 -> V_143 = V_105 -> V_143 ;
V_54 -> V_144 = V_48 -> V_59 -> V_60 -> V_144 ;
}
T_2 F_68 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_68 V_52 ;
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
F_67 ( V_48 , & V_54 , & V_105 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_69 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_69 V_52 ;
struct V_145 V_54 ;
struct V_146 V_105 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_15 = F_70 ( V_48 -> V_59 -> V_60 , V_52 . V_147 , & V_105 ) ;
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
V_54 . V_167 = F_71 ( V_48 -> V_59 -> V_60 ,
V_52 . V_147 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_72 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_72 V_52 ;
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
V_2 = F_73 ( sizeof *V_2 , V_16 ) ;
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
F_74 ( & V_26 -> V_172 , 0 ) ;
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
F_75 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_71 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_25 , V_2 ) ;
V_173:
F_76 ( V_26 ) ;
V_68:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_77 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_77 V_52 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_25 , V_52 . V_24 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_15 = F_76 ( V_2 -> V_22 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_25 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_78 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
static int F_79 ( struct V_176 * V_177 ,
struct V_178 * V_178 ,
struct V_44 * V_179 )
{
struct V_180 * V_181 , * V_182 ;
struct V_183 * * V_184 = & V_177 -> V_185 . V_183 ;
struct V_183 * V_186 = NULL ;
V_181 = F_73 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 )
return - V_169 ;
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
F_6 ( V_181 ) ;
return - V_190 ;
}
}
F_81 ( & V_181 -> V_187 , V_186 , V_184 ) ;
F_82 ( & V_181 -> V_187 , & V_177 -> V_185 ) ;
F_83 ( V_178 ) ;
return 0 ;
}
static struct V_180 * F_84 ( struct V_176 * V_177 ,
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
static struct V_44 * F_85 ( struct V_176 * V_177 , struct V_178 * V_178 )
{
struct V_180 * V_181 ;
V_181 = F_84 ( V_177 , V_178 ) ;
if ( ! V_181 )
return NULL ;
return V_181 -> V_179 ;
}
static void F_86 ( struct V_176 * V_177 ,
struct V_178 * V_178 )
{
struct V_180 * V_181 ;
V_181 = F_84 ( V_177 , V_178 ) ;
if ( V_181 ) {
F_87 ( V_178 ) ;
F_88 ( & V_181 -> V_187 , & V_177 -> V_185 ) ;
F_6 ( V_181 ) ;
}
}
T_2 F_89 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_89 V_52 ;
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
V_195 = F_90 ( V_52 . V_194 ) ;
if ( ! V_195 . V_48 ) {
V_15 = - V_198 ;
goto V_199;
}
V_178 = F_91 ( V_195 . V_48 ) ;
V_179 = F_85 ( V_48 -> V_59 , V_178 ) ;
if ( ! V_179 && ! ( V_52 . V_200 & V_201 ) ) {
V_15 = - V_202 ;
goto V_199;
}
if ( V_179 && V_52 . V_200 & V_203 ) {
V_15 = - V_67 ;
goto V_199;
}
}
V_193 = F_73 ( sizeof *V_193 , V_16 ) ;
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
F_74 ( & V_179 -> V_172 , 0 ) ;
F_92 ( & V_179 -> V_206 ) ;
F_52 ( & V_179 -> V_207 ) ;
V_196 = 1 ;
}
F_74 ( & V_193 -> V_208 , 0 ) ;
V_193 -> V_27 . V_22 = V_179 ;
V_15 = F_14 ( & V_46 , & V_193 -> V_27 ) ;
if ( V_15 )
goto V_173;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_45 = V_193 -> V_27 . V_19 ;
if ( V_178 ) {
if ( V_196 ) {
V_15 = F_79 ( V_48 -> V_59 , V_178 , V_179 ) ;
if ( V_15 )
goto V_209;
}
F_93 ( & V_179 -> V_172 ) ;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
if ( V_195 . V_48 )
F_94 ( V_195 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_75 ( & V_193 -> V_27 . V_175 , & V_48 -> V_63 -> V_78 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_27 . V_9 ) ;
F_63 ( & V_48 -> V_59 -> V_197 ) ;
return V_50 ;
V_174:
if ( V_178 ) {
if ( V_196 )
F_86 ( V_48 -> V_59 , V_178 ) ;
F_95 ( & V_179 -> V_172 ) ;
}
V_209:
F_20 ( & V_46 , & V_193 -> V_27 ) ;
V_173:
F_96 ( V_179 ) ;
V_68:
F_12 ( & V_193 -> V_27 ) ;
V_199:
if ( V_195 . V_48 )
F_94 ( V_195 ) ;
F_63 ( & V_48 -> V_59 -> V_197 ) ;
return V_15 ;
}
T_2 F_97 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_97 V_52 ;
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
if ( F_98 ( & V_193 -> V_208 ) ) {
F_12 ( V_2 ) ;
V_15 = - V_211 ;
goto V_210;
}
if ( ! V_178 || F_99 ( & V_179 -> V_172 ) ) {
V_15 = F_96 ( V_2 -> V_22 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
}
V_12 = V_2 -> V_12 ;
if ( V_178 && V_15 )
F_93 ( & V_179 -> V_172 ) ;
F_12 ( V_2 ) ;
if ( V_15 )
goto V_210;
if ( V_178 && ! V_12 )
F_86 ( V_48 -> V_59 , V_178 ) ;
F_20 ( & V_46 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_78 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
V_15 = V_50 ;
V_210:
F_63 ( & V_48 -> V_59 -> V_197 ) ;
return V_15 ;
}
void F_100 ( struct V_176 * V_177 ,
struct V_44 * V_179 )
{
struct V_178 * V_178 ;
V_178 = V_179 -> V_178 ;
if ( V_178 && ! F_99 ( & V_179 -> V_172 ) )
return;
F_96 ( V_179 ) ;
if ( V_178 )
F_86 ( V_177 , V_178 ) ;
}
T_2 F_101 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_101 V_52 ;
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
V_15 = F_102 ( V_52 . V_218 ) ;
if ( V_15 )
return V_15 ;
V_2 = F_73 ( sizeof *V_2 , V_16 ) ;
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
F_103 ( L_1 ) ;
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
F_93 ( & V_26 -> V_172 ) ;
F_74 ( & V_214 -> V_172 , 0 ) ;
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
F_75 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_72 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_224 , V_2 ) ;
V_225:
F_104 ( V_214 ) ;
V_221:
F_32 ( V_26 ) ;
V_90:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_105 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_105 V_52 ;
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
V_15 = F_102 ( V_52 . V_218 ) ;
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
if ( F_98 ( & V_214 -> V_172 ) ) {
V_15 = - V_211 ;
goto V_237;
}
V_230 = V_214 -> V_26 ;
V_15 = V_214 -> V_59 -> V_238 ( V_214 , V_52 . V_231 , V_52 . V_215 ,
V_52 . V_223 , V_52 . V_217 ,
V_52 . V_218 , V_26 , & V_56 ) ;
if ( ! V_15 ) {
if ( V_52 . V_231 & V_236 ) {
F_93 ( & V_26 -> V_172 ) ;
V_214 -> V_26 = V_26 ;
F_95 ( & V_230 -> V_172 ) ;
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
T_2 F_106 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_106 V_52 ;
struct V_213 * V_214 ;
struct V_1 * V_2 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_224 , V_52 . V_228 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_214 = V_2 -> V_22 ;
V_15 = F_104 ( V_214 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_224 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_78 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_107 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_107 V_52 ;
struct V_239 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_240 * V_241 ;
int V_15 ;
if ( V_51 < sizeof( V_54 ) )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_66 ;
V_2 = F_73 ( sizeof( * V_2 ) , V_16 ) ;
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
F_93 ( & V_26 -> V_172 ) ;
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
F_75 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_73 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_245 , V_2 ) ;
V_246:
F_108 ( V_241 ) ;
V_221:
F_32 ( V_26 ) ;
V_90:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_109 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_109 V_52 ;
struct V_240 * V_241 ;
struct V_1 * V_2 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_66 ;
V_2 = F_28 ( & V_245 , V_52 . V_247 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_241 = V_2 -> V_22 ;
V_15 = F_108 ( V_241 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_245 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_78 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_110 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_110 V_52 ;
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
static struct V_249 * F_111 ( struct V_47 * V_48 ,
struct V_55 * V_250 ,
struct V_55 * V_251 ,
struct V_252 * V_52 ,
T_4 V_253 ,
int (* F_112)( struct V_47 * V_48 ,
struct V_249 * V_193 ,
struct V_254 * V_54 ,
struct V_55 * V_56 ,
void * V_5 ) ,
void * V_5 )
{
struct V_249 * V_193 ;
struct V_255 * V_256 = NULL ;
struct V_28 * V_31 ;
int V_15 ;
struct V_254 V_54 ;
struct V_257 V_105 = {} ;
if ( V_52 -> V_258 >= V_48 -> V_59 -> V_94 )
return F_113 ( - V_67 ) ;
V_193 = F_73 ( sizeof *V_193 , V_16 ) ;
if ( ! V_193 )
return F_113 ( - V_169 ) ;
F_1 ( & V_193 -> V_27 , V_52 -> V_3 , V_48 -> V_63 , & V_259 ) ;
F_29 ( & V_193 -> V_27 . V_9 ) ;
if ( V_52 -> V_260 >= 0 ) {
V_256 = F_114 ( V_52 -> V_260 ) ;
if ( ! V_256 ) {
V_15 = - V_67 ;
goto V_68;
}
}
V_193 -> V_261 = V_48 ;
V_193 -> V_262 = 0 ;
V_193 -> V_263 = 0 ;
F_52 ( & V_193 -> V_264 ) ;
F_52 ( & V_193 -> V_265 ) ;
V_105 . V_266 = V_52 -> V_266 ;
V_105 . V_258 = V_52 -> V_258 ;
if ( V_253 > F_115 ( F_116 ( * V_52 ) , V_231 ) + sizeof( V_52 -> V_231 ) )
V_105 . V_231 = V_52 -> V_231 ;
V_31 = V_48 -> V_59 -> V_60 -> F_111 ( V_48 -> V_59 -> V_60 , & V_105 ,
V_48 -> V_63 , V_251 ) ;
if ( F_50 ( V_31 ) ) {
V_15 = F_51 ( V_31 ) ;
goto V_98;
}
V_31 -> V_59 = V_48 -> V_59 -> V_60 ;
V_31 -> V_27 = & V_193 -> V_27 ;
V_31 -> V_267 = V_268 ;
V_31 -> V_101 = V_269 ;
V_31 -> V_270 = V_256 ;
F_74 ( & V_31 -> V_172 , 0 ) ;
V_193 -> V_27 . V_22 = V_31 ;
V_15 = F_14 ( & V_30 , & V_193 -> V_27 ) ;
if ( V_15 )
goto V_90;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_271 . V_29 = V_193 -> V_27 . V_19 ;
V_54 . V_271 . V_266 = V_31 -> V_266 ;
V_54 . V_272 = F_115 ( F_116 ( V_54 ) , V_272 ) +
sizeof( V_54 . V_272 ) ;
V_15 = F_112 ( V_48 , V_193 , & V_54 , V_250 , V_5 ) ;
if ( V_15 )
goto V_273;
F_48 ( & V_48 -> V_9 ) ;
F_75 ( & V_193 -> V_27 . V_175 , & V_48 -> V_63 -> V_74 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_27 . V_9 ) ;
return V_193 ;
V_273:
F_20 ( & V_30 , & V_193 -> V_27 ) ;
V_90:
F_117 ( V_31 ) ;
V_98:
if ( V_256 )
F_118 ( V_48 , V_256 , V_193 ) ;
V_68:
F_12 ( & V_193 -> V_27 ) ;
return F_113 ( V_15 ) ;
}
static int F_119 ( struct V_47 * V_48 ,
struct V_249 * V_193 ,
struct V_254 * V_54 ,
struct V_55 * V_250 , void * V_5 )
{
if ( F_120 ( V_250 , & V_54 -> V_271 , sizeof( V_54 -> V_271 ) ) )
return - V_66 ;
return 0 ;
}
T_2 F_121 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_121 V_52 ;
struct V_252 V_274 ;
struct V_275 V_54 ;
struct V_55 V_250 ;
struct V_55 V_251 ;
struct V_249 * V_193 ;
if ( V_51 < sizeof( V_54 ) )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_66 ;
F_49 ( & V_250 , V_49 , V_52 . V_69 , sizeof( V_52 ) , sizeof( V_54 ) ) ;
F_49 ( & V_251 , V_49 + sizeof( V_52 ) ,
( unsigned long ) V_52 . V_69 + sizeof( V_54 ) ,
V_50 - sizeof( V_52 ) , V_51 - sizeof( V_54 ) ) ;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
V_274 . V_3 = V_52 . V_3 ;
V_274 . V_266 = V_52 . V_266 ;
V_274 . V_258 = V_52 . V_258 ;
V_274 . V_260 = V_52 . V_260 ;
V_193 = F_111 ( V_48 , & V_250 , & V_251 , & V_274 ,
F_115 ( F_116 ( V_274 ) , V_260 ) +
sizeof( V_52 . V_260 ) , F_119 ,
NULL ) ;
if ( F_50 ( V_193 ) )
return F_51 ( V_193 ) ;
return V_50 ;
}
static int F_122 ( struct V_47 * V_48 ,
struct V_249 * V_193 ,
struct V_254 * V_54 ,
struct V_55 * V_250 , void * V_5 )
{
if ( F_120 ( V_250 , V_54 , V_54 -> V_272 ) )
return - V_66 ;
return 0 ;
}
int V_252 ( struct V_47 * V_48 ,
struct V_55 * V_250 ,
struct V_55 * V_251 )
{
struct V_254 V_54 ;
struct V_252 V_52 ;
struct V_249 * V_193 ;
int V_68 ;
if ( V_250 -> V_276 < sizeof( V_52 ) )
return - V_67 ;
V_68 = F_123 ( & V_52 , V_250 , sizeof( V_52 ) ) ;
if ( V_68 )
return V_68 ;
if ( V_52 . V_277 )
return - V_67 ;
if ( V_52 . V_278 )
return - V_67 ;
if ( V_250 -> V_279 < ( F_115 ( F_116 ( V_54 ) , V_272 ) +
sizeof( V_54 . V_272 ) ) )
return - V_65 ;
V_193 = F_111 ( V_48 , V_250 , V_251 , & V_52 ,
F_124 ( V_250 -> V_276 , sizeof( V_52 ) ) ,
F_122 , NULL ) ;
if ( F_50 ( V_193 ) )
return F_51 ( V_193 ) ;
return 0 ;
}
T_2 F_125 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_125 V_52 ;
struct V_280 V_54 ;
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
V_15 = V_31 -> V_59 -> V_281 ( V_31 , V_52 . V_266 , & V_56 ) ;
if ( V_15 )
goto V_210;
V_54 . V_266 = V_31 -> V_266 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 . V_266 ) )
V_15 = - V_66 ;
V_210:
F_34 ( V_31 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_126 ( void T_3 * V_282 , struct V_283 * V_284 )
{
struct V_285 V_286 ;
V_286 . V_287 = V_284 -> V_287 ;
V_286 . V_288 = V_284 -> V_288 ;
V_286 . V_289 = V_284 -> V_289 ;
V_286 . V_290 = V_284 -> V_290 ;
V_286 . V_291 = V_284 -> V_291 ;
V_286 . V_292 . V_293 = ( V_294 V_295 ) V_284 -> V_292 . V_293 ;
V_286 . V_296 = V_284 -> V_39 -> V_296 ;
V_286 . V_297 = V_284 -> V_297 ;
V_286 . V_298 = V_284 -> V_298 ;
V_286 . V_299 = V_284 -> V_299 ;
V_286 . V_300 = V_284 -> V_300 ;
V_286 . V_301 = V_284 -> V_301 ;
V_286 . V_302 = V_284 -> V_302 ;
V_286 . V_147 = V_284 -> V_147 ;
V_286 . V_278 = 0 ;
if ( F_59 ( V_282 , & V_286 , sizeof V_286 ) )
return - V_66 ;
return 0 ;
}
T_2 F_127 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_127 V_52 ;
struct V_303 V_54 ;
T_5 T_3 * V_304 ;
T_5 T_3 * V_305 ;
struct V_28 * V_31 ;
struct V_283 V_284 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_63 , 0 ) ;
if ( ! V_31 )
return - V_67 ;
V_304 = ( void T_3 * ) ( unsigned long ) V_52 . V_69 ;
V_305 = V_304 + sizeof V_54 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
while ( V_54 . V_306 < V_52 . V_307 ) {
V_15 = F_128 ( V_31 , 1 , & V_284 ) ;
if ( V_15 < 0 )
goto V_308;
if ( ! V_15 )
break;
V_15 = F_126 ( V_305 , & V_284 ) ;
if ( V_15 )
goto V_308;
V_305 += sizeof( struct V_285 ) ;
++ V_54 . V_306 ;
}
if ( F_59 ( V_304 , & V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_308;
}
V_15 = V_50 ;
V_308:
F_34 ( V_31 ) ;
return V_15 ;
}
T_2 F_129 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_129 V_52 ;
struct V_28 * V_31 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_63 , 0 ) ;
if ( ! V_31 )
return - V_67 ;
F_130 ( V_31 , V_52 . V_309 ?
V_310 : V_311 ) ;
F_34 ( V_31 ) ;
return V_50 ;
}
T_2 F_131 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_131 V_52 ;
struct V_312 V_54 ;
struct V_1 * V_2 ;
struct V_28 * V_31 ;
struct V_249 * V_193 ;
struct V_255 * V_256 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_30 , V_52 . V_29 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_31 = V_2 -> V_22 ;
V_256 = V_31 -> V_270 ;
V_193 = F_7 ( V_31 -> V_27 , struct V_249 , V_27 ) ;
V_15 = F_117 ( V_31 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_30 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_78 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_118 ( V_48 , V_256 , V_193 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_262 = V_193 -> V_262 ;
V_54 . V_263 = V_193 -> V_263 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_132 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_132 V_52 ;
struct V_313 V_54 ;
struct V_55 V_56 ;
struct V_314 * V_193 ;
struct V_57 * V_59 ;
struct V_23 * V_26 = NULL ;
struct V_44 * V_179 = NULL ;
struct V_1 * V_315 ( V_316 ) ;
struct V_28 * V_317 = NULL , * V_318 = NULL ;
struct V_40 * V_43 = NULL ;
struct V_36 * V_39 ;
struct V_319 V_105 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
if ( V_52 . V_320 == V_321 && ! F_133 ( V_322 ) )
return - V_323 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_193 = F_134 ( sizeof *V_193 , V_16 ) ;
if ( ! V_193 )
return - V_169 ;
F_1 ( & V_193 -> V_324 . V_27 , V_52 . V_3 , V_48 -> V_63 , & V_325 ) ;
F_29 ( & V_193 -> V_324 . V_27 . V_9 ) ;
if ( V_52 . V_320 == V_326 ) {
V_179 = F_43 ( V_52 . V_24 , V_48 -> V_63 , & V_316 ) ;
if ( ! V_179 ) {
V_15 = - V_67 ;
goto V_221;
}
V_59 = V_179 -> V_59 ;
} else {
if ( V_52 . V_320 == V_327 ) {
V_52 . V_328 = V_52 . V_329 = 0 ;
} else {
if ( V_52 . V_330 ) {
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_43 || V_43 -> V_331 != V_332 ) {
V_15 = - V_67 ;
goto V_221;
}
}
if ( V_52 . V_333 != V_52 . V_334 ) {
V_318 = F_33 ( V_52 . V_333 , V_48 -> V_63 , 0 ) ;
if ( ! V_318 ) {
V_15 = - V_67 ;
goto V_221;
}
}
}
V_317 = F_33 ( V_52 . V_334 , V_48 -> V_63 , ! ! V_318 ) ;
V_318 = V_318 ? : V_317 ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_63 ) ;
if ( ! V_26 || ! V_317 ) {
V_15 = - V_67 ;
goto V_221;
}
V_59 = V_26 -> V_59 ;
}
V_105 . V_101 = V_335 ;
V_105 . V_336 = V_48 ;
V_105 . V_337 = V_317 ;
V_105 . V_338 = V_318 ;
V_105 . V_43 = V_43 ;
V_105 . V_179 = V_179 ;
V_105 . V_339 = V_52 . V_340 ? V_341 : V_342 ;
V_105 . V_320 = V_52 . V_320 ;
V_105 . V_343 = 0 ;
V_105 . V_344 . V_345 = V_52 . V_345 ;
V_105 . V_344 . V_328 = V_52 . V_328 ;
V_105 . V_344 . V_346 = V_52 . V_346 ;
V_105 . V_344 . V_329 = V_52 . V_329 ;
V_105 . V_344 . V_347 = V_52 . V_347 ;
V_193 -> V_324 . V_348 = 0 ;
F_52 ( & V_193 -> V_324 . V_349 ) ;
F_52 ( & V_193 -> V_350 ) ;
if ( V_52 . V_320 == V_326 )
V_39 = F_135 ( V_26 , & V_105 ) ;
else
V_39 = V_59 -> V_351 ( V_26 , & V_105 , & V_56 ) ;
if ( F_50 ( V_39 ) ) {
V_15 = F_51 ( V_39 ) ;
goto V_221;
}
if ( V_52 . V_320 != V_326 ) {
V_39 -> V_352 = V_39 ;
V_39 -> V_59 = V_59 ;
V_39 -> V_26 = V_26 ;
V_39 -> V_337 = V_105 . V_337 ;
V_39 -> V_338 = V_105 . V_338 ;
V_39 -> V_43 = V_105 . V_43 ;
V_39 -> V_101 = V_105 . V_101 ;
V_39 -> V_336 = V_105 . V_336 ;
V_39 -> V_320 = V_105 . V_320 ;
F_74 ( & V_39 -> V_172 , 0 ) ;
F_93 ( & V_26 -> V_172 ) ;
F_93 ( & V_105 . V_337 -> V_172 ) ;
if ( V_105 . V_338 )
F_93 ( & V_105 . V_338 -> V_172 ) ;
if ( V_105 . V_43 )
F_93 ( & V_105 . V_43 -> V_172 ) ;
}
V_39 -> V_27 = & V_193 -> V_324 . V_27 ;
V_193 -> V_324 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_193 -> V_324 . V_27 ) ;
if ( V_15 )
goto V_353;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_354 = V_39 -> V_296 ;
V_54 . V_37 = V_193 -> V_324 . V_27 . V_19 ;
V_54 . V_329 = V_105 . V_344 . V_329 ;
V_54 . V_346 = V_105 . V_344 . V_346 ;
V_54 . V_328 = V_105 . V_344 . V_328 ;
V_54 . V_345 = V_105 . V_344 . V_345 ;
V_54 . V_347 = V_105 . V_344 . V_347 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
if ( V_179 ) {
V_193 -> V_355 = F_7 ( V_316 , struct V_192 ,
V_27 ) ;
F_93 ( & V_193 -> V_355 -> V_208 ) ;
F_44 ( V_316 ) ;
}
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_317 )
F_34 ( V_317 ) ;
if ( V_318 && V_318 != V_317 )
F_34 ( V_318 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_75 ( & V_193 -> V_324 . V_27 . V_175 , & V_48 -> V_63 -> V_75 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_324 . V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_324 . V_27 . V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_38 , & V_193 -> V_324 . V_27 ) ;
V_353:
F_136 ( V_39 ) ;
V_221:
if ( V_179 )
F_44 ( V_316 ) ;
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_317 )
F_34 ( V_317 ) ;
if ( V_318 && V_318 != V_317 )
F_34 ( V_318 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_12 ( & V_193 -> V_324 . V_27 ) ;
return V_15 ;
}
T_2 F_137 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_137 V_52 ;
struct V_313 V_54 ;
struct V_55 V_56 ;
struct V_314 * V_193 ;
struct V_44 * V_179 ;
struct V_1 * V_315 ( V_316 ) ;
struct V_36 * V_39 ;
struct V_356 V_105 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_193 = F_73 ( sizeof *V_193 , V_16 ) ;
if ( ! V_193 )
return - V_169 ;
F_1 ( & V_193 -> V_324 . V_27 , V_52 . V_3 , V_48 -> V_63 , & V_325 ) ;
F_29 ( & V_193 -> V_324 . V_27 . V_9 ) ;
V_179 = F_43 ( V_52 . V_24 , V_48 -> V_63 , & V_316 ) ;
if ( ! V_179 ) {
V_15 = - V_67 ;
goto V_221;
}
V_105 . V_101 = V_335 ;
V_105 . V_336 = V_48 ;
V_105 . V_296 = V_52 . V_354 ;
V_105 . V_320 = V_52 . V_320 ;
V_193 -> V_324 . V_348 = 0 ;
F_52 ( & V_193 -> V_324 . V_349 ) ;
F_52 ( & V_193 -> V_350 ) ;
V_39 = F_138 ( V_179 , & V_105 ) ;
if ( F_50 ( V_39 ) ) {
V_15 = F_51 ( V_39 ) ;
goto V_221;
}
V_39 -> V_27 = & V_193 -> V_324 . V_27 ;
V_193 -> V_324 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_193 -> V_324 . V_27 ) ;
if ( V_15 )
goto V_353;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_354 = V_39 -> V_296 ;
V_54 . V_37 = V_193 -> V_324 . V_27 . V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_357;
}
V_193 -> V_355 = F_7 ( V_316 , struct V_192 , V_27 ) ;
F_93 ( & V_193 -> V_355 -> V_208 ) ;
F_44 ( V_316 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_75 ( & V_193 -> V_324 . V_27 . V_175 , & V_48 -> V_63 -> V_75 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_324 . V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_324 . V_27 . V_9 ) ;
return V_50 ;
V_357:
F_20 ( & V_38 , & V_193 -> V_324 . V_27 ) ;
V_353:
F_136 ( V_39 ) ;
V_221:
F_44 ( V_316 ) ;
F_12 ( & V_193 -> V_324 . V_27 ) ;
return V_15 ;
}
T_2 F_139 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_139 V_52 ;
struct V_358 V_54 ;
struct V_36 * V_39 ;
struct V_359 * V_105 ;
struct V_319 * V_360 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_105 = F_73 ( sizeof *V_105 , V_16 ) ;
V_360 = F_73 ( sizeof *V_360 , V_16 ) ;
if ( ! V_105 || ! V_360 ) {
V_15 = - V_169 ;
goto V_210;
}
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 ) {
V_15 = - V_67 ;
goto V_210;
}
V_15 = F_140 ( V_39 , V_105 , V_52 . V_361 , V_360 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
goto V_210;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_362 = V_105 -> V_362 ;
V_54 . V_363 = V_105 -> V_363 ;
V_54 . V_364 = V_105 -> V_364 ;
V_54 . V_365 = V_105 -> V_365 ;
V_54 . V_366 = V_105 -> V_366 ;
V_54 . V_367 = V_105 -> V_367 ;
V_54 . V_368 = V_105 -> V_368 ;
V_54 . V_369 = V_105 -> V_369 ;
V_54 . V_370 = V_105 -> V_370 ;
V_54 . V_299 = V_105 -> V_299 ;
V_54 . V_371 = V_105 -> V_371 ;
V_54 . V_372 = V_105 -> V_372 ;
V_54 . V_373 = V_105 -> V_373 ;
V_54 . V_374 = V_105 -> V_374 ;
V_54 . V_375 = V_105 -> V_375 ;
V_54 . V_147 = V_105 -> V_147 ;
V_54 . V_376 = V_105 -> V_376 ;
V_54 . V_377 = V_105 -> V_377 ;
V_54 . V_378 = V_105 -> V_378 ;
V_54 . V_379 = V_105 -> V_379 ;
V_54 . V_380 = V_105 -> V_380 ;
memcpy ( V_54 . V_282 . V_381 , V_105 -> V_382 . V_383 . V_381 . V_384 , 16 ) ;
V_54 . V_282 . V_385 = V_105 -> V_382 . V_383 . V_385 ;
V_54 . V_282 . V_386 = V_105 -> V_382 . V_383 . V_386 ;
V_54 . V_282 . V_387 = V_105 -> V_382 . V_383 . V_387 ;
V_54 . V_282 . V_388 = V_105 -> V_382 . V_383 . V_388 ;
V_54 . V_282 . V_389 = V_105 -> V_382 . V_389 ;
V_54 . V_282 . V_301 = V_105 -> V_382 . V_301 ;
V_54 . V_282 . V_390 = V_105 -> V_382 . V_390 ;
V_54 . V_282 . V_391 = V_105 -> V_382 . V_391 ;
V_54 . V_282 . V_392 = ! ! ( V_105 -> V_382 . V_393 & V_394 ) ;
V_54 . V_282 . V_147 = V_105 -> V_382 . V_147 ;
memcpy ( V_54 . V_395 . V_381 , V_105 -> V_396 . V_383 . V_381 . V_384 , 16 ) ;
V_54 . V_395 . V_385 = V_105 -> V_396 . V_383 . V_385 ;
V_54 . V_395 . V_386 = V_105 -> V_396 . V_383 . V_386 ;
V_54 . V_395 . V_387 = V_105 -> V_396 . V_383 . V_387 ;
V_54 . V_395 . V_388 = V_105 -> V_396 . V_383 . V_388 ;
V_54 . V_395 . V_389 = V_105 -> V_396 . V_389 ;
V_54 . V_395 . V_301 = V_105 -> V_396 . V_301 ;
V_54 . V_395 . V_390 = V_105 -> V_396 . V_390 ;
V_54 . V_395 . V_391 = V_105 -> V_396 . V_391 ;
V_54 . V_395 . V_392 = ! ! ( V_105 -> V_396 . V_393 & V_394 ) ;
V_54 . V_395 . V_147 = V_105 -> V_396 . V_147 ;
V_54 . V_345 = V_360 -> V_344 . V_345 ;
V_54 . V_328 = V_360 -> V_344 . V_328 ;
V_54 . V_346 = V_360 -> V_344 . V_346 ;
V_54 . V_329 = V_360 -> V_344 . V_329 ;
V_54 . V_347 = V_360 -> V_344 . V_347 ;
V_54 . V_340 = V_360 -> V_339 == V_341 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
V_210:
F_6 ( V_105 ) ;
F_6 ( V_360 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_141 ( enum V_397 V_320 , int V_398 )
{
switch ( V_320 ) {
case V_327 :
return V_398 & ~ ( V_399 | V_400 ) ;
case V_326 :
return V_398 & ~ ( V_401 | V_402 |
V_403 ) ;
default:
return V_398 ;
}
}
T_2 F_142 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_142 V_52 ;
struct V_55 V_56 ;
struct V_36 * V_39 ;
struct V_359 * V_105 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 , NULL , V_50 - sizeof V_52 ,
V_51 ) ;
V_105 = F_73 ( sizeof *V_105 , V_16 ) ;
if ( ! V_105 )
return - V_169 ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 ) {
V_15 = - V_67 ;
goto V_210;
}
V_105 -> V_362 = V_52 . V_362 ;
V_105 -> V_363 = V_52 . V_363 ;
V_105 -> V_364 = V_52 . V_364 ;
V_105 -> V_365 = V_52 . V_365 ;
V_105 -> V_366 = V_52 . V_366 ;
V_105 -> V_367 = V_52 . V_367 ;
V_105 -> V_368 = V_52 . V_368 ;
V_105 -> V_369 = V_52 . V_369 ;
V_105 -> V_370 = V_52 . V_370 ;
V_105 -> V_299 = V_52 . V_299 ;
V_105 -> V_371 = V_52 . V_371 ;
V_105 -> V_404 = V_52 . V_404 ;
V_105 -> V_373 = V_52 . V_373 ;
V_105 -> V_374 = V_52 . V_374 ;
V_105 -> V_375 = V_52 . V_375 ;
V_105 -> V_147 = V_52 . V_147 ;
V_105 -> V_376 = V_52 . V_376 ;
V_105 -> V_377 = V_52 . V_377 ;
V_105 -> V_378 = V_52 . V_378 ;
V_105 -> V_379 = V_52 . V_379 ;
V_105 -> V_380 = V_52 . V_380 ;
memcpy ( V_105 -> V_382 . V_383 . V_381 . V_384 , V_52 . V_282 . V_381 , 16 ) ;
V_105 -> V_382 . V_383 . V_385 = V_52 . V_282 . V_385 ;
V_105 -> V_382 . V_383 . V_386 = V_52 . V_282 . V_386 ;
V_105 -> V_382 . V_383 . V_387 = V_52 . V_282 . V_387 ;
V_105 -> V_382 . V_383 . V_388 = V_52 . V_282 . V_388 ;
V_105 -> V_382 . V_389 = V_52 . V_282 . V_389 ;
V_105 -> V_382 . V_301 = V_52 . V_282 . V_301 ;
V_105 -> V_382 . V_390 = V_52 . V_282 . V_390 ;
V_105 -> V_382 . V_391 = V_52 . V_282 . V_391 ;
V_105 -> V_382 . V_393 = V_52 . V_282 . V_392 ? V_394 : 0 ;
V_105 -> V_382 . V_147 = V_52 . V_282 . V_147 ;
memcpy ( V_105 -> V_396 . V_383 . V_381 . V_384 , V_52 . V_395 . V_381 , 16 ) ;
V_105 -> V_396 . V_383 . V_385 = V_52 . V_395 . V_385 ;
V_105 -> V_396 . V_383 . V_386 = V_52 . V_395 . V_386 ;
V_105 -> V_396 . V_383 . V_387 = V_52 . V_395 . V_387 ;
V_105 -> V_396 . V_383 . V_388 = V_52 . V_395 . V_388 ;
V_105 -> V_396 . V_389 = V_52 . V_395 . V_389 ;
V_105 -> V_396 . V_301 = V_52 . V_395 . V_301 ;
V_105 -> V_396 . V_390 = V_52 . V_395 . V_390 ;
V_105 -> V_396 . V_391 = V_52 . V_395 . V_391 ;
V_105 -> V_396 . V_393 = V_52 . V_395 . V_392 ? V_394 : 0 ;
V_105 -> V_396 . V_147 = V_52 . V_395 . V_147 ;
if ( V_39 -> V_352 == V_39 ) {
V_15 = F_143 ( V_39 , V_105 , & V_52 . V_361 ) ;
if ( V_15 )
goto V_405;
V_15 = V_39 -> V_59 -> V_406 ( V_39 , V_105 ,
F_141 ( V_39 -> V_320 , V_52 . V_361 ) , & V_56 ) ;
} else {
V_15 = F_144 ( V_39 , V_105 , F_141 ( V_39 -> V_320 , V_52 . V_361 ) ) ;
}
if ( V_15 )
goto V_405;
V_15 = V_50 ;
V_405:
F_39 ( V_39 ) ;
V_210:
F_6 ( V_105 ) ;
return V_15 ;
}
T_2 F_145 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_145 V_52 ;
struct V_407 V_54 ;
struct V_1 * V_2 ;
struct V_36 * V_39 ;
struct V_314 * V_193 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_2 = F_28 ( & V_38 , V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_39 = V_2 -> V_22 ;
V_193 = F_7 ( V_2 , struct V_314 , V_324 . V_27 ) ;
if ( ! F_146 ( & V_193 -> V_350 ) ) {
F_12 ( V_2 ) ;
return - V_211 ;
}
V_15 = F_136 ( V_39 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_193 -> V_355 )
F_95 ( & V_193 -> V_355 -> V_208 ) ;
F_20 ( & V_38 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_78 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_147 ( V_48 , & V_193 -> V_324 ) ;
V_54 . V_348 = V_193 -> V_324 . V_348 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_148 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_148 V_52 ;
struct V_408 V_54 ;
struct V_409 * V_410 ;
struct V_411 * V_412 = NULL , * V_413 , * V_414 , * V_415 ;
struct V_36 * V_39 ;
int V_416 , V_417 ;
int V_418 ;
T_2 V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
if ( V_50 < sizeof V_52 + V_52 . V_419 * V_52 . V_420 +
V_52 . V_421 * sizeof ( struct V_422 ) )
return - V_67 ;
if ( V_52 . V_419 < sizeof ( struct V_409 ) )
return - V_67 ;
V_410 = F_73 ( V_52 . V_419 , V_16 ) ;
if ( ! V_410 )
return - V_169 ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 )
goto V_210;
V_418 = V_39 -> V_320 == V_423 ;
V_417 = 0 ;
V_413 = NULL ;
for ( V_416 = 0 ; V_416 < V_52 . V_420 ; ++ V_416 ) {
if ( F_47 ( V_410 ,
V_49 + sizeof V_52 + V_416 * V_52 . V_419 ,
V_52 . V_419 ) ) {
V_15 = - V_66 ;
goto V_308;
}
if ( V_410 -> V_424 + V_417 > V_52 . V_421 ) {
V_15 = - V_67 ;
goto V_308;
}
V_414 = F_73 ( F_149 ( sizeof *V_414 , sizeof ( struct V_425 ) ) +
V_410 -> V_424 * sizeof ( struct V_425 ) ,
V_16 ) ;
if ( ! V_414 ) {
V_15 = - V_169 ;
goto V_308;
}
if ( ! V_413 )
V_412 = V_414 ;
else
V_413 -> V_414 = V_414 ;
V_413 = V_414 ;
V_414 -> V_414 = NULL ;
V_414 -> V_287 = V_410 -> V_287 ;
V_414 -> V_424 = V_410 -> V_424 ;
V_414 -> V_289 = V_410 -> V_289 ;
V_414 -> V_426 = V_410 -> V_426 ;
if ( V_418 ) {
V_414 -> V_412 . V_427 . V_35 = F_35 ( V_410 -> V_412 . V_427 . V_35 ,
V_48 -> V_63 ) ;
if ( ! V_414 -> V_412 . V_427 . V_35 ) {
V_15 = - V_67 ;
goto V_308;
}
V_414 -> V_412 . V_427 . V_428 = V_410 -> V_412 . V_427 . V_428 ;
V_414 -> V_412 . V_427 . V_429 = V_410 -> V_412 . V_427 . V_429 ;
if ( V_414 -> V_289 == V_430 )
V_414 -> V_292 . V_293 =
( V_431 V_295 ) V_410 -> V_292 . V_293 ;
} else {
switch ( V_414 -> V_289 ) {
case V_432 :
V_414 -> V_292 . V_293 =
( V_431 V_295 ) V_410 -> V_292 . V_293 ;
case V_433 :
case V_434 :
V_414 -> V_412 . V_435 . V_436 =
V_410 -> V_412 . V_435 . V_436 ;
V_414 -> V_412 . V_435 . V_227 =
V_410 -> V_412 . V_435 . V_227 ;
break;
case V_430 :
V_414 -> V_292 . V_293 =
( V_431 V_295 ) V_410 -> V_292 . V_293 ;
break;
case V_437 :
V_414 -> V_292 . V_438 =
V_410 -> V_292 . V_438 ;
break;
case V_439 :
case V_440 :
V_414 -> V_412 . V_441 . V_436 =
V_410 -> V_412 . V_441 . V_436 ;
V_414 -> V_412 . V_441 . V_442 =
V_410 -> V_412 . V_441 . V_442 ;
V_414 -> V_412 . V_441 . V_443 = V_410 -> V_412 . V_441 . V_443 ;
V_414 -> V_412 . V_441 . V_227 = V_410 -> V_412 . V_441 . V_227 ;
break;
default:
break;
}
}
if ( V_414 -> V_424 ) {
V_414 -> V_444 = ( void * ) V_414 +
F_149 ( sizeof *V_414 , sizeof ( struct V_425 ) ) ;
if ( F_47 ( V_414 -> V_444 ,
V_49 + sizeof V_52 +
V_52 . V_420 * V_52 . V_419 +
V_417 * sizeof ( struct V_425 ) ,
V_414 -> V_424 * sizeof ( struct V_425 ) ) ) {
V_15 = - V_66 ;
goto V_308;
}
V_417 += V_414 -> V_424 ;
} else
V_414 -> V_444 = NULL ;
}
V_54 . V_415 = 0 ;
V_15 = V_39 -> V_59 -> V_445 ( V_39 -> V_352 , V_412 , & V_415 ) ;
if ( V_15 )
for ( V_414 = V_412 ; V_414 ; V_414 = V_414 -> V_414 ) {
++ V_54 . V_415 ;
if ( V_414 == V_415 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
V_308:
F_39 ( V_39 ) ;
while ( V_412 ) {
if ( V_418 && V_412 -> V_412 . V_427 . V_35 )
F_36 ( V_412 -> V_412 . V_427 . V_35 ) ;
V_414 = V_412 -> V_414 ;
F_6 ( V_412 ) ;
V_412 = V_414 ;
}
V_210:
F_6 ( V_410 ) ;
return V_15 ? V_15 : V_50 ;
}
static struct V_446 * F_150 ( const char T_3 * V_49 ,
int V_50 ,
T_6 V_420 ,
T_6 V_421 ,
T_6 V_419 )
{
struct V_447 * V_410 ;
struct V_446 * V_412 = NULL , * V_413 , * V_414 ;
int V_417 ;
int V_416 ;
int V_15 ;
if ( V_50 < V_419 * V_420 +
V_421 * sizeof ( struct V_422 ) )
return F_113 ( - V_67 ) ;
if ( V_419 < sizeof ( struct V_447 ) )
return F_113 ( - V_67 ) ;
V_410 = F_73 ( V_419 , V_16 ) ;
if ( ! V_410 )
return F_113 ( - V_169 ) ;
V_417 = 0 ;
V_413 = NULL ;
for ( V_416 = 0 ; V_416 < V_420 ; ++ V_416 ) {
if ( F_47 ( V_410 , V_49 + V_416 * V_419 ,
V_419 ) ) {
V_15 = - V_66 ;
goto V_68;
}
if ( V_410 -> V_424 + V_417 > V_421 ) {
V_15 = - V_67 ;
goto V_68;
}
V_414 = F_73 ( F_149 ( sizeof *V_414 , sizeof ( struct V_425 ) ) +
V_410 -> V_424 * sizeof ( struct V_425 ) ,
V_16 ) ;
if ( ! V_414 ) {
V_15 = - V_169 ;
goto V_68;
}
if ( ! V_413 )
V_412 = V_414 ;
else
V_413 -> V_414 = V_414 ;
V_413 = V_414 ;
V_414 -> V_414 = NULL ;
V_414 -> V_287 = V_410 -> V_287 ;
V_414 -> V_424 = V_410 -> V_424 ;
if ( V_414 -> V_424 ) {
V_414 -> V_444 = ( void * ) V_414 +
F_149 ( sizeof *V_414 , sizeof ( struct V_425 ) ) ;
if ( F_47 ( V_414 -> V_444 ,
V_49 + V_420 * V_419 +
V_417 * sizeof ( struct V_425 ) ,
V_414 -> V_424 * sizeof ( struct V_425 ) ) ) {
V_15 = - V_66 ;
goto V_68;
}
V_417 += V_414 -> V_424 ;
} else
V_414 -> V_444 = NULL ;
}
F_6 ( V_410 ) ;
return V_412 ;
V_68:
F_6 ( V_410 ) ;
while ( V_412 ) {
V_414 = V_412 -> V_414 ;
F_6 ( V_412 ) ;
V_412 = V_414 ;
}
return F_113 ( V_15 ) ;
}
T_2 F_151 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_151 V_52 ;
struct V_448 V_54 ;
struct V_446 * V_412 , * V_414 , * V_415 ;
struct V_36 * V_39 ;
T_2 V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_412 = F_150 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_420 ,
V_52 . V_421 , V_52 . V_419 ) ;
if ( F_50 ( V_412 ) )
return F_51 ( V_412 ) ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 )
goto V_210;
V_54 . V_415 = 0 ;
V_15 = V_39 -> V_59 -> V_449 ( V_39 -> V_352 , V_412 , & V_415 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
for ( V_414 = V_412 ; V_414 ; V_414 = V_414 -> V_414 ) {
++ V_54 . V_415 ;
if ( V_414 == V_415 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
V_210:
while ( V_412 ) {
V_414 = V_412 -> V_414 ;
F_6 ( V_412 ) ;
V_412 = V_414 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_152 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_152 V_52 ;
struct V_450 V_54 ;
struct V_446 * V_412 , * V_414 , * V_415 ;
struct V_40 * V_43 ;
T_2 V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_412 = F_150 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_420 ,
V_52 . V_421 , V_52 . V_419 ) ;
if ( F_50 ( V_412 ) )
return F_51 ( V_412 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_43 )
goto V_210;
V_54 . V_415 = 0 ;
V_15 = V_43 -> V_59 -> V_451 ( V_43 , V_412 , & V_415 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
for ( V_414 = V_412 ; V_414 ; V_414 = V_414 -> V_414 ) {
++ V_54 . V_415 ;
if ( V_414 == V_415 )
break;
}
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
V_210:
while ( V_412 ) {
V_414 = V_412 -> V_414 ;
F_6 ( V_412 ) ;
V_412 = V_414 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_153 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_153 V_52 ;
struct V_452 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_32 * V_35 ;
struct V_453 V_105 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_73 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_169 ;
F_1 ( V_2 , V_52 . V_3 , V_48 -> V_63 , & V_454 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_63 ) ;
if ( ! V_26 ) {
V_15 = - V_67 ;
goto V_68;
}
V_105 . V_389 = V_52 . V_105 . V_389 ;
V_105 . V_301 = V_52 . V_105 . V_301 ;
V_105 . V_390 = V_52 . V_105 . V_390 ;
V_105 . V_391 = V_52 . V_105 . V_391 ;
V_105 . V_393 = V_52 . V_105 . V_392 ? V_394 : 0 ;
V_105 . V_147 = V_52 . V_105 . V_147 ;
V_105 . V_383 . V_385 = V_52 . V_105 . V_383 . V_385 ;
V_105 . V_383 . V_386 = V_52 . V_105 . V_383 . V_386 ;
V_105 . V_383 . V_387 = V_52 . V_105 . V_383 . V_387 ;
V_105 . V_383 . V_388 = V_52 . V_105 . V_383 . V_388 ;
V_105 . V_455 = 0 ;
memset ( & V_105 . V_456 , 0 , sizeof( V_105 . V_456 ) ) ;
memcpy ( V_105 . V_383 . V_381 . V_384 , V_52 . V_105 . V_383 . V_381 , 16 ) ;
V_35 = F_154 ( V_26 , & V_105 ) ;
if ( F_50 ( V_35 ) ) {
V_15 = F_51 ( V_35 ) ;
goto V_221;
}
V_35 -> V_27 = V_2 ;
V_2 -> V_22 = V_35 ;
V_15 = F_14 ( & V_34 , V_2 ) ;
if ( V_15 )
goto V_353;
V_54 . V_33 = V_2 -> V_19 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_75 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_77 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_174:
F_20 ( & V_34 , V_2 ) ;
V_353:
F_155 ( V_35 ) ;
V_221:
F_32 ( V_26 ) ;
V_68:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_156 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_156 V_52 ;
struct V_32 * V_35 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_34 , V_52 . V_33 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_35 = V_2 -> V_22 ;
V_15 = F_155 ( V_35 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_34 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_78 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_157 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_157 V_52 ;
struct V_36 * V_39 ;
struct V_314 * V_193 ;
struct V_457 * V_458 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 )
return - V_67 ;
V_193 = F_7 ( V_39 -> V_27 , struct V_314 , V_324 . V_27 ) ;
F_158 (mcast, &obj->mcast_list, list)
if ( V_52 . V_459 == V_458 -> V_157 &&
! memcmp ( V_52 . V_460 , V_458 -> V_460 . V_384 , sizeof V_458 -> V_460 . V_384 ) ) {
V_15 = 0 ;
goto V_308;
}
V_458 = F_73 ( sizeof *V_458 , V_16 ) ;
if ( ! V_458 ) {
V_15 = - V_169 ;
goto V_308;
}
V_458 -> V_157 = V_52 . V_459 ;
memcpy ( V_458 -> V_460 . V_384 , V_52 . V_460 , sizeof V_458 -> V_460 . V_384 ) ;
V_15 = F_159 ( V_39 , & V_458 -> V_460 , V_52 . V_459 ) ;
if ( ! V_15 )
F_75 ( & V_458 -> V_175 , & V_193 -> V_350 ) ;
else
F_6 ( V_458 ) ;
V_308:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_160 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_160 V_52 ;
struct V_314 * V_193 ;
struct V_36 * V_39 ;
struct V_457 * V_458 ;
int V_15 = - V_67 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 )
return - V_67 ;
V_15 = F_161 ( V_39 , (union V_461 * ) V_52 . V_460 , V_52 . V_459 ) ;
if ( V_15 )
goto V_308;
V_193 = F_7 ( V_39 -> V_27 , struct V_314 , V_324 . V_27 ) ;
F_158 (mcast, &obj->mcast_list, list)
if ( V_52 . V_459 == V_458 -> V_157 &&
! memcmp ( V_52 . V_460 , V_458 -> V_460 . V_384 , sizeof V_458 -> V_460 . V_384 ) ) {
F_78 ( & V_458 -> V_175 ) ;
F_6 ( V_458 ) ;
break;
}
V_308:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_162 ( struct V_462 * V_463 ,
union V_464 * V_465 )
{
if ( V_463 -> V_278 )
return - V_67 ;
V_465 -> type = V_463 -> type ;
switch ( V_465 -> type ) {
case V_466 :
V_465 -> V_467 . V_468 = sizeof( struct V_469 ) ;
if ( V_465 -> V_467 . V_468 != V_463 -> V_467 . V_468 )
return - V_67 ;
memcpy ( & V_465 -> V_467 . V_470 , & V_463 -> V_467 . V_470 ,
sizeof( struct V_471 ) ) ;
memcpy ( & V_465 -> V_467 . V_398 , & V_463 -> V_467 . V_398 ,
sizeof( struct V_471 ) ) ;
break;
case V_472 :
V_465 -> V_473 . V_468 = sizeof( struct V_474 ) ;
if ( V_465 -> V_473 . V_468 != V_463 -> V_473 . V_468 )
return - V_67 ;
memcpy ( & V_465 -> V_473 . V_470 , & V_463 -> V_473 . V_470 ,
sizeof( struct V_475 ) ) ;
memcpy ( & V_465 -> V_473 . V_398 , & V_463 -> V_473 . V_398 ,
sizeof( struct V_475 ) ) ;
break;
case V_476 :
case V_477 :
V_465 -> V_478 . V_468 = sizeof( struct V_479 ) ;
if ( V_465 -> V_478 . V_468 != V_463 -> V_478 . V_468 )
return - V_67 ;
memcpy ( & V_465 -> V_478 . V_470 , & V_463 -> V_478 . V_470 ,
sizeof( struct V_480 ) ) ;
memcpy ( & V_465 -> V_478 . V_398 , & V_463 -> V_478 . V_398 ,
sizeof( struct V_480 ) ) ;
break;
default:
return - V_67 ;
}
return 0 ;
}
int F_163 ( struct V_47 * V_48 ,
struct V_55 * V_250 ,
struct V_55 * V_251 )
{
struct V_481 V_52 ;
struct V_482 V_54 ;
struct V_1 * V_2 ;
struct V_483 * V_484 ;
struct V_485 * V_486 ;
struct V_487 * V_488 ;
struct V_36 * V_39 ;
int V_68 = 0 ;
void * V_463 ;
void * V_465 ;
int V_416 ;
if ( V_250 -> V_276 < sizeof( V_52 ) )
return - V_67 ;
if ( V_250 -> V_279 < sizeof( V_54 ) )
return - V_65 ;
V_68 = F_123 ( & V_52 , V_250 , sizeof( V_52 ) ) ;
if ( V_68 )
return V_68 ;
V_250 -> V_489 += sizeof( V_52 ) ;
V_250 -> V_276 -= sizeof( V_52 ) ;
if ( V_52 . V_277 )
return - V_67 ;
if ( ( V_52 . V_488 . type == V_490 &&
! F_133 ( V_491 ) ) || ! F_133 ( V_322 ) )
return - V_323 ;
if ( V_52 . V_488 . V_492 > V_493 )
return - V_67 ;
if ( V_52 . V_488 . V_468 > V_250 -> V_276 ||
V_52 . V_488 . V_468 >
( V_52 . V_488 . V_492 * sizeof( struct V_462 ) ) )
return - V_67 ;
if ( V_52 . V_488 . V_278 [ 0 ] ||
V_52 . V_488 . V_278 [ 1 ] )
return - V_67 ;
if ( V_52 . V_488 . V_492 ) {
V_486 = F_73 ( sizeof( * V_486 ) + V_52 . V_488 . V_468 ,
V_16 ) ;
if ( ! V_486 )
return - V_169 ;
memcpy ( V_486 , & V_52 . V_488 , sizeof( * V_486 ) ) ;
V_68 = F_123 ( V_486 + 1 , V_250 ,
V_52 . V_488 . V_468 ) ;
if ( V_68 )
goto V_494;
} else {
V_486 = & V_52 . V_488 ;
}
V_2 = F_73 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 ) {
V_68 = - V_169 ;
goto V_494;
}
F_1 ( V_2 , 0 , V_48 -> V_63 , & V_495 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_63 ) ;
if ( ! V_39 ) {
V_68 = - V_67 ;
goto V_496;
}
V_488 = F_73 ( sizeof( * V_488 ) + V_52 . V_488 . V_468 , V_16 ) ;
if ( ! V_488 ) {
V_68 = - V_169 ;
goto V_221;
}
V_488 -> type = V_486 -> type ;
V_488 -> V_497 = V_486 -> V_497 ;
V_488 -> V_492 = V_486 -> V_492 ;
V_488 -> V_498 = V_486 -> V_498 ;
V_488 -> V_231 = V_486 -> V_231 ;
V_488 -> V_468 = sizeof( * V_488 ) ;
V_463 = V_486 + 1 ;
V_465 = V_488 + 1 ;
for ( V_416 = 0 ; V_416 < V_488 -> V_492 &&
V_52 . V_488 . V_468 > F_115 ( struct V_462 , V_278 ) &&
V_52 . V_488 . V_468 >=
( (struct V_462 * ) V_463 ) -> V_468 ; V_416 ++ ) {
V_68 = F_162 ( V_463 , V_465 ) ;
if ( V_68 )
goto V_90;
V_488 -> V_468 +=
( (union V_464 * ) V_465 ) -> V_468 ;
V_52 . V_488 . V_468 -= ( (struct V_462 * ) V_463 ) -> V_468 ;
V_463 += ( (struct V_462 * ) V_463 ) -> V_468 ;
V_465 += ( (union V_464 * ) V_465 ) -> V_468 ;
}
if ( V_52 . V_488 . V_468 || ( V_416 != V_488 -> V_492 ) ) {
F_164 ( L_2 ,
V_416 , V_52 . V_488 . V_468 ) ;
V_68 = - V_67 ;
goto V_90;
}
V_484 = F_165 ( V_39 , V_488 , V_499 ) ;
if ( F_50 ( V_484 ) ) {
V_68 = F_51 ( V_484 ) ;
goto V_90;
}
V_484 -> V_39 = V_39 ;
V_484 -> V_27 = V_2 ;
V_2 -> V_22 = V_484 ;
V_68 = F_14 ( & V_500 , V_2 ) ;
if ( V_68 )
goto V_501;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_502 = V_2 -> V_19 ;
V_68 = F_120 ( V_250 ,
& V_54 , sizeof( V_54 ) ) ;
if ( V_68 )
goto V_174;
F_39 ( V_39 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_75 ( & V_2 -> V_175 , & V_48 -> V_63 -> V_79 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_6 ( V_488 ) ;
if ( V_52 . V_488 . V_492 )
F_6 ( V_486 ) ;
return 0 ;
V_174:
F_20 ( & V_500 , V_2 ) ;
V_501:
F_166 ( V_484 ) ;
V_90:
F_6 ( V_488 ) ;
V_221:
F_39 ( V_39 ) ;
V_496:
F_12 ( V_2 ) ;
V_494:
if ( V_52 . V_488 . V_492 )
F_6 ( V_486 ) ;
return V_68 ;
}
int F_167 ( struct V_47 * V_48 ,
struct V_55 * V_250 ,
struct V_55 * V_251 )
{
struct V_503 V_52 ;
struct V_483 * V_484 ;
struct V_1 * V_2 ;
int V_15 ;
if ( V_250 -> V_276 < sizeof( V_52 ) )
return - V_67 ;
V_15 = F_123 ( & V_52 , V_250 , sizeof( V_52 ) ) ;
if ( V_15 )
return V_15 ;
if ( V_52 . V_277 )
return - V_67 ;
V_2 = F_28 ( & V_500 , V_52 . V_502 ,
V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_484 = V_2 -> V_22 ;
V_15 = F_166 ( V_484 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_500 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_78 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_15 ;
}
static int F_168 ( struct V_47 * V_48 ,
struct V_504 * V_52 ,
struct V_55 * V_56 )
{
struct V_505 V_54 ;
struct V_506 * V_193 ;
struct V_23 * V_26 ;
struct V_40 * V_43 ;
struct V_1 * V_315 ( V_316 ) ;
struct V_507 V_105 ;
int V_15 ;
V_193 = F_73 ( sizeof *V_193 , V_16 ) ;
if ( ! V_193 )
return - V_169 ;
F_1 ( & V_193 -> V_324 . V_27 , V_52 -> V_3 , V_48 -> V_63 , & V_508 ) ;
F_29 ( & V_193 -> V_324 . V_27 . V_9 ) ;
if ( V_52 -> V_331 == V_509 ) {
V_105 . V_510 . V_511 . V_179 = F_43 ( V_52 -> V_45 , V_48 -> V_63 , & V_316 ) ;
if ( ! V_105 . V_510 . V_511 . V_179 ) {
V_15 = - V_67 ;
goto V_68;
}
V_193 -> V_355 = F_7 ( V_316 , struct V_192 , V_27 ) ;
F_93 ( & V_193 -> V_355 -> V_208 ) ;
V_105 . V_510 . V_511 . V_31 = F_33 ( V_52 -> V_29 , V_48 -> V_63 , 0 ) ;
if ( ! V_105 . V_510 . V_511 . V_31 ) {
V_15 = - V_67 ;
goto V_512;
}
}
V_26 = F_31 ( V_52 -> V_24 , V_48 -> V_63 ) ;
if ( ! V_26 ) {
V_15 = - V_67 ;
goto V_513;
}
V_105 . V_101 = V_514 ;
V_105 . V_515 = V_48 ;
V_105 . V_331 = V_52 -> V_331 ;
V_105 . V_105 . V_516 = V_52 -> V_516 ;
V_105 . V_105 . V_116 = V_52 -> V_116 ;
V_105 . V_105 . V_517 = V_52 -> V_517 ;
V_193 -> V_324 . V_348 = 0 ;
F_52 ( & V_193 -> V_324 . V_349 ) ;
V_43 = V_26 -> V_59 -> V_518 ( V_26 , & V_105 , V_56 ) ;
if ( F_50 ( V_43 ) ) {
V_15 = F_51 ( V_43 ) ;
goto V_221;
}
V_43 -> V_59 = V_26 -> V_59 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_331 = V_52 -> V_331 ;
V_43 -> V_27 = & V_193 -> V_324 . V_27 ;
V_43 -> V_101 = V_105 . V_101 ;
V_43 -> V_515 = V_105 . V_515 ;
if ( V_52 -> V_331 == V_509 ) {
V_43 -> V_510 . V_511 . V_31 = V_105 . V_510 . V_511 . V_31 ;
V_43 -> V_510 . V_511 . V_179 = V_105 . V_510 . V_511 . V_179 ;
F_93 ( & V_105 . V_510 . V_511 . V_31 -> V_172 ) ;
F_93 ( & V_105 . V_510 . V_511 . V_179 -> V_172 ) ;
}
F_93 ( & V_26 -> V_172 ) ;
F_74 ( & V_43 -> V_172 , 0 ) ;
V_193 -> V_324 . V_27 . V_22 = V_43 ;
V_15 = F_14 ( & V_42 , & V_193 -> V_324 . V_27 ) ;
if ( V_15 )
goto V_353;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_41 = V_193 -> V_324 . V_27 . V_19 ;
V_54 . V_516 = V_105 . V_105 . V_516 ;
V_54 . V_116 = V_105 . V_105 . V_116 ;
if ( V_52 -> V_331 == V_509 )
V_54 . V_519 = V_43 -> V_510 . V_511 . V_520 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 -> V_69 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_66 ;
goto V_174;
}
if ( V_52 -> V_331 == V_509 ) {
F_10 ( V_316 ) ;
F_34 ( V_105 . V_510 . V_511 . V_31 ) ;
}
F_32 ( V_26 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_75 ( & V_193 -> V_324 . V_27 . V_175 , & V_48 -> V_63 -> V_76 ) ;
F_63 ( & V_48 -> V_9 ) ;
V_193 -> V_324 . V_27 . V_12 = 1 ;
F_13 ( & V_193 -> V_324 . V_27 . V_9 ) ;
return 0 ;
V_174:
F_20 ( & V_42 , & V_193 -> V_324 . V_27 ) ;
V_353:
F_169 ( V_43 ) ;
V_221:
F_32 ( V_26 ) ;
V_513:
if ( V_52 -> V_331 == V_509 )
F_34 ( V_105 . V_510 . V_511 . V_31 ) ;
V_512:
if ( V_52 -> V_331 == V_509 ) {
F_95 ( & V_193 -> V_355 -> V_208 ) ;
F_10 ( V_316 ) ;
}
V_68:
F_12 ( & V_193 -> V_324 . V_27 ) ;
return V_15 ;
}
T_2 F_170 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_170 V_52 ;
struct V_504 V_521 ;
struct V_505 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_521 . V_69 = V_52 . V_69 ;
V_521 . V_3 = V_52 . V_3 ;
V_521 . V_331 = V_332 ;
V_521 . V_24 = V_52 . V_24 ;
V_521 . V_516 = V_52 . V_516 ;
V_521 . V_116 = V_52 . V_116 ;
V_521 . V_517 = V_52 . V_517 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_168 ( V_48 , & V_521 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 V_504 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct V_504 V_52 ;
struct V_505 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_69 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_168 ( V_48 , & V_52 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 F_171 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_171 V_52 ;
struct V_55 V_56 ;
struct V_40 * V_43 ;
struct V_522 V_105 ;
int V_15 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
F_49 ( & V_56 , V_49 + sizeof V_52 , NULL , V_50 - sizeof V_52 ,
V_51 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_43 )
return - V_67 ;
V_105 . V_516 = V_52 . V_516 ;
V_105 . V_517 = V_52 . V_517 ;
V_15 = V_43 -> V_59 -> V_523 ( V_43 , & V_105 , V_52 . V_361 , & V_56 ) ;
F_42 ( V_43 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_172 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_172 V_52 ;
struct V_524 V_54 ;
struct V_522 V_105 ;
struct V_40 * V_43 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_65 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_43 )
return - V_67 ;
V_15 = F_173 ( V_43 , & V_105 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_516 = V_105 . V_516 ;
V_54 . V_116 = V_105 . V_116 ;
V_54 . V_517 = V_105 . V_517 ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
return - V_66 ;
return V_50 ;
}
T_2 F_174 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_174 V_52 ;
struct V_525 V_54 ;
struct V_1 * V_2 ;
struct V_40 * V_43 ;
struct V_526 * V_193 ;
int V_15 = - V_67 ;
struct V_506 * V_527 ;
enum V_528 V_331 ;
if ( F_47 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_66 ;
V_2 = F_28 ( & V_42 , V_52 . V_41 , V_48 -> V_63 ) ;
if ( ! V_2 )
return - V_67 ;
V_43 = V_2 -> V_22 ;
V_193 = F_7 ( V_2 , struct V_526 , V_27 ) ;
V_331 = V_43 -> V_331 ;
V_15 = F_169 ( V_43 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_331 == V_509 ) {
V_527 = F_7 ( V_193 , struct V_506 , V_324 ) ;
F_95 ( & V_527 -> V_355 -> V_208 ) ;
}
F_20 ( & V_42 , V_2 ) ;
F_48 ( & V_48 -> V_9 ) ;
F_78 ( & V_2 -> V_175 ) ;
F_63 ( & V_48 -> V_9 ) ;
F_147 ( V_48 , V_193 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_348 = V_193 -> V_348 ;
F_8 ( V_2 ) ;
if ( F_59 ( ( void T_3 * ) ( unsigned long ) V_52 . V_69 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_66 ;
return V_15 ? V_15 : V_50 ;
}
int F_175 ( struct V_47 * V_48 ,
struct V_55 * V_250 ,
struct V_55 * V_251 )
{
struct V_529 V_54 ;
struct F_175 V_52 ;
struct V_61 V_105 ;
struct V_57 * V_59 ;
int V_68 ;
V_59 = V_48 -> V_59 -> V_60 ;
if ( V_250 -> V_276 < sizeof( V_52 ) )
return - V_67 ;
V_68 = F_123 ( & V_52 , V_250 , sizeof( V_52 ) ) ;
if ( V_68 )
return V_68 ;
if ( V_52 . V_277 )
return - V_67 ;
if ( V_52 . V_278 )
return - V_67 ;
V_54 . V_272 = F_115 ( F_116 ( V_54 ) , V_530 ) ;
if ( V_250 -> V_279 < V_54 . V_272 )
return - V_65 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_68 = V_59 -> V_531 ( V_59 , & V_105 , V_251 ) ;
if ( V_68 )
return V_68 ;
F_67 ( V_48 , & V_54 . V_271 , & V_105 ) ;
V_54 . V_277 = 0 ;
if ( V_250 -> V_279 < V_54 . V_272 + sizeof( V_54 . V_530 ) )
goto V_532;
#ifdef F_46
V_54 . V_530 . V_533 = V_105 . V_530 . V_533 ;
V_54 . V_530 . V_534 . V_535 =
V_105 . V_530 . V_534 . V_535 ;
V_54 . V_530 . V_534 . V_536 =
V_105 . V_530 . V_534 . V_536 ;
V_54 . V_530 . V_534 . V_537 =
V_105 . V_530 . V_534 . V_537 ;
V_54 . V_530 . V_278 = 0 ;
#else
memset ( & V_54 . V_530 , 0 , sizeof( V_54 . V_530 ) ) ;
#endif
V_54 . V_272 += sizeof( V_54 . V_530 ) ;
if ( V_250 -> V_279 < V_54 . V_272 + sizeof( V_54 . V_538 ) )
goto V_532;
V_54 . V_538 = V_105 . V_538 ;
V_54 . V_272 += sizeof( V_54 . V_538 ) ;
if ( V_250 -> V_279 < V_54 . V_272 + sizeof( V_54 . V_539 ) )
goto V_532;
V_54 . V_539 = V_105 . V_539 ;
V_54 . V_272 += sizeof( V_54 . V_539 ) ;
V_532:
V_68 = F_120 ( V_250 , & V_54 , V_54 . V_272 ) ;
if ( V_68 )
return V_68 ;
return 0 ;
}
