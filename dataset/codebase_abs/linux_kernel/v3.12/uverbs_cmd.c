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
struct V_4 * V_61 ;
struct V_48 * V_62 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_47 ( & V_48 -> V_9 ) ;
if ( V_48 -> V_61 ) {
V_15 = - V_65 ;
goto V_66;
}
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_61 = V_58 -> V_68 ( V_58 , & V_56 ) ;
if ( F_49 ( V_61 ) ) {
V_15 = F_50 ( V_61 ) ;
goto V_66;
}
V_61 -> V_59 = V_58 ;
F_51 ( & V_61 -> V_69 ) ;
F_51 ( & V_61 -> V_70 ) ;
F_51 ( & V_61 -> V_71 ) ;
F_51 ( & V_61 -> V_72 ) ;
F_51 ( & V_61 -> V_73 ) ;
F_51 ( & V_61 -> V_74 ) ;
F_51 ( & V_61 -> V_75 ) ;
F_51 ( & V_61 -> V_76 ) ;
F_51 ( & V_61 -> V_77 ) ;
V_61 -> V_78 = 0 ;
V_54 . V_79 = V_48 -> V_59 -> V_79 ;
V_15 = F_52 ( V_80 ) ;
if ( V_15 < 0 )
goto V_81;
V_54 . V_82 = V_15 ;
V_62 = F_53 ( V_48 , 1 ) ;
if ( F_49 ( V_62 ) ) {
V_15 = F_50 ( V_62 ) ;
goto V_83;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_84;
}
V_48 -> V_85 = V_62 -> V_86 ;
F_55 ( & V_48 -> V_87 , V_48 -> V_59 -> V_60 ,
V_88 ) ;
V_15 = F_56 ( & V_48 -> V_87 ) ;
if ( V_15 )
goto V_84;
F_24 ( & V_48 -> V_85 -> V_8 ) ;
F_24 ( & V_48 -> V_8 ) ;
V_48 -> V_61 = V_61 ;
F_57 ( V_54 . V_82 , V_62 ) ;
F_58 ( & V_48 -> V_9 ) ;
return V_50 ;
V_84:
F_59 ( V_62 ) ;
V_83:
F_60 ( V_54 . V_82 ) ;
V_81:
V_58 -> V_89 ( V_61 ) ;
V_66:
F_58 ( & V_48 -> V_9 ) ;
return V_15 ;
}
T_2 F_61 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_61 V_52 ;
struct V_90 V_54 ;
struct V_91 V_92 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_15 = F_62 ( V_48 -> V_59 -> V_60 , & V_92 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_93 = V_92 . V_93 ;
V_54 . V_94 = V_48 -> V_59 -> V_60 -> V_94 ;
V_54 . V_95 = V_92 . V_95 ;
V_54 . V_96 = V_92 . V_96 ;
V_54 . V_97 = V_92 . V_97 ;
V_54 . V_98 = V_92 . V_98 ;
V_54 . V_99 = V_92 . V_99 ;
V_54 . V_100 = V_92 . V_100 ;
V_54 . V_101 = V_92 . V_101 ;
V_54 . V_102 = V_92 . V_102 ;
V_54 . V_103 = V_92 . V_103 ;
V_54 . V_104 = V_92 . V_104 ;
V_54 . V_105 = V_92 . V_105 ;
V_54 . V_106 = V_92 . V_106 ;
V_54 . V_107 = V_92 . V_107 ;
V_54 . V_108 = V_92 . V_108 ;
V_54 . V_109 = V_92 . V_109 ;
V_54 . V_110 = V_92 . V_110 ;
V_54 . V_111 = V_92 . V_111 ;
V_54 . V_112 = V_92 . V_112 ;
V_54 . V_113 = V_92 . V_113 ;
V_54 . V_114 = V_92 . V_114 ;
V_54 . V_115 = V_92 . V_115 ;
V_54 . V_116 = V_92 . V_116 ;
V_54 . V_117 = V_92 . V_117 ;
V_54 . V_118 = V_92 . V_118 ;
V_54 . V_119 = V_92 . V_119 ;
V_54 . V_120 = V_92 . V_120 ;
V_54 . V_121 = V_92 . V_121 ;
V_54 . V_122 = V_92 . V_122 ;
V_54 . V_123 = V_92 . V_123 ;
V_54 . V_124 = V_92 . V_124 ;
V_54 . V_125 = V_92 . V_125 ;
V_54 . V_126 = V_92 . V_126 ;
V_54 . V_127 = V_92 . V_127 ;
V_54 . V_128 = V_92 . V_128 ;
V_54 . V_129 = V_92 . V_129 ;
V_54 . V_130 = V_92 . V_130 ;
V_54 . V_131 = V_92 . V_131 ;
V_54 . V_132 = V_48 -> V_59 -> V_60 -> V_132 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_63 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_63 V_52 ;
struct V_133 V_54 ;
struct V_134 V_92 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_15 = F_64 ( V_48 -> V_59 -> V_60 , V_52 . V_135 , & V_92 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_136 = V_92 . V_136 ;
V_54 . V_137 = V_92 . V_137 ;
V_54 . V_138 = V_92 . V_138 ;
V_54 . V_139 = V_92 . V_139 ;
V_54 . V_140 = V_92 . V_140 ;
V_54 . V_141 = V_92 . V_141 ;
V_54 . V_142 = V_92 . V_142 ;
V_54 . V_143 = V_92 . V_143 ;
V_54 . V_144 = V_92 . V_144 ;
V_54 . V_145 = V_92 . V_145 ;
V_54 . V_146 = V_92 . V_146 ;
V_54 . V_147 = V_92 . V_147 ;
V_54 . V_148 = V_92 . V_148 ;
V_54 . V_149 = V_92 . V_149 ;
V_54 . V_150 = V_92 . V_150 ;
V_54 . V_151 = V_92 . V_151 ;
V_54 . V_152 = V_92 . V_152 ;
V_54 . V_153 = V_92 . V_153 ;
V_54 . V_154 = V_92 . V_154 ;
V_54 . V_155 = F_65 ( V_48 -> V_59 -> V_60 ,
V_52 . V_135 ) ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_66 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_66 V_52 ;
struct V_156 V_54 ;
struct V_55 V_56 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_2 = F_67 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_157 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_158 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = V_48 -> V_59 -> V_60 -> V_159 ( V_48 -> V_59 -> V_60 ,
V_48 -> V_61 , & V_56 ) ;
if ( F_49 ( V_26 ) ) {
V_15 = F_50 ( V_26 ) ;
goto V_66;
}
V_26 -> V_59 = V_48 -> V_59 -> V_60 ;
V_26 -> V_27 = V_2 ;
F_68 ( & V_26 -> V_160 , 0 ) ;
V_2 -> V_22 = V_26 ;
V_15 = F_14 ( & V_25 , V_2 ) ;
if ( V_15 )
goto V_161;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_24 = V_2 -> V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_162;
}
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_163 , & V_48 -> V_61 -> V_69 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_162:
F_20 ( & V_25 , V_2 ) ;
V_161:
F_70 ( V_26 ) ;
V_66:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_71 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_71 V_52 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_25 , V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_15 = F_70 ( V_2 -> V_22 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_25 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
static int F_73 ( struct V_164 * V_165 ,
struct V_166 * V_166 ,
struct V_44 * V_167 )
{
struct V_168 * V_169 , * V_170 ;
struct V_171 * * V_172 = & V_165 -> V_173 . V_171 ;
struct V_171 * V_174 = NULL ;
V_169 = F_67 ( sizeof *V_169 , V_16 ) ;
if ( ! V_169 )
return - V_157 ;
V_169 -> V_167 = V_167 ;
V_169 -> V_166 = V_166 ;
while ( * V_172 ) {
V_174 = * V_172 ;
V_170 = F_74 ( V_174 , struct V_168 , V_175 ) ;
if ( V_166 < V_170 -> V_166 ) {
V_172 = & ( * V_172 ) -> V_176 ;
} else if ( V_166 > V_170 -> V_166 ) {
V_172 = & ( * V_172 ) -> V_177 ;
} else {
F_6 ( V_169 ) ;
return - V_178 ;
}
}
F_75 ( & V_169 -> V_175 , V_174 , V_172 ) ;
F_76 ( & V_169 -> V_175 , & V_165 -> V_173 ) ;
F_77 ( V_166 ) ;
return 0 ;
}
static struct V_168 * F_78 ( struct V_164 * V_165 ,
struct V_166 * V_166 )
{
struct V_168 * V_169 ;
struct V_171 * V_172 = V_165 -> V_173 . V_171 ;
while ( V_172 ) {
V_169 = F_74 ( V_172 , struct V_168 , V_175 ) ;
if ( V_166 < V_169 -> V_166 )
V_172 = V_172 -> V_176 ;
else if ( V_166 > V_169 -> V_166 )
V_172 = V_172 -> V_177 ;
else
return V_169 ;
}
return NULL ;
}
static struct V_44 * F_79 ( struct V_164 * V_165 , struct V_166 * V_166 )
{
struct V_168 * V_169 ;
V_169 = F_78 ( V_165 , V_166 ) ;
if ( ! V_169 )
return NULL ;
return V_169 -> V_167 ;
}
static void F_80 ( struct V_164 * V_165 ,
struct V_166 * V_166 )
{
struct V_168 * V_169 ;
V_169 = F_78 ( V_165 , V_166 ) ;
if ( V_169 ) {
F_81 ( V_166 ) ;
F_82 ( & V_169 -> V_175 , & V_165 -> V_173 ) ;
F_6 ( V_169 ) ;
}
}
T_2 F_83 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_83 V_52 ;
struct V_179 V_54 ;
struct V_55 V_56 ;
struct V_180 * V_181 ;
struct V_44 * V_167 = NULL ;
struct V_182 V_183 = { NULL , 0 } ;
struct V_166 * V_166 = NULL ;
int V_15 = 0 ;
int V_184 = 0 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
F_47 ( & V_48 -> V_59 -> V_185 ) ;
if ( V_52 . V_182 != - 1 ) {
V_183 = F_84 ( V_52 . V_182 ) ;
if ( ! V_183 . V_48 ) {
V_15 = - V_186 ;
goto V_187;
}
V_166 = F_85 ( V_183 . V_48 ) ;
V_167 = F_79 ( V_48 -> V_59 , V_166 ) ;
if ( ! V_167 && ! ( V_52 . V_188 & V_189 ) ) {
V_15 = - V_190 ;
goto V_187;
}
if ( V_167 && V_52 . V_188 & V_191 ) {
V_15 = - V_65 ;
goto V_187;
}
}
V_181 = F_67 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 ) {
V_15 = - V_157 ;
goto V_187;
}
F_1 ( & V_181 -> V_27 , 0 , V_48 -> V_61 , & V_192 ) ;
F_29 ( & V_181 -> V_27 . V_9 ) ;
if ( ! V_167 ) {
V_167 = V_48 -> V_59 -> V_60 -> V_193 ( V_48 -> V_59 -> V_60 ,
V_48 -> V_61 , & V_56 ) ;
if ( F_49 ( V_167 ) ) {
V_15 = F_50 ( V_167 ) ;
goto V_66;
}
V_167 -> V_166 = V_166 ;
V_167 -> V_59 = V_48 -> V_59 -> V_60 ;
F_68 ( & V_167 -> V_160 , 0 ) ;
F_86 ( & V_167 -> V_194 ) ;
F_51 ( & V_167 -> V_195 ) ;
V_184 = 1 ;
}
F_68 ( & V_181 -> V_196 , 0 ) ;
V_181 -> V_27 . V_22 = V_167 ;
V_15 = F_14 ( & V_46 , & V_181 -> V_27 ) ;
if ( V_15 )
goto V_161;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_45 = V_181 -> V_27 . V_19 ;
if ( V_166 ) {
if ( V_184 ) {
V_15 = F_73 ( V_48 -> V_59 , V_166 , V_167 ) ;
if ( V_15 )
goto V_197;
}
F_87 ( & V_167 -> V_160 ) ;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_162;
}
if ( V_183 . V_48 )
F_88 ( V_183 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_181 -> V_27 . V_163 , & V_48 -> V_61 -> V_76 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_181 -> V_27 . V_12 = 1 ;
F_13 ( & V_181 -> V_27 . V_9 ) ;
F_58 ( & V_48 -> V_59 -> V_185 ) ;
return V_50 ;
V_162:
if ( V_166 ) {
if ( V_184 )
F_80 ( V_48 -> V_59 , V_166 ) ;
F_89 ( & V_167 -> V_160 ) ;
}
V_197:
F_20 ( & V_46 , & V_181 -> V_27 ) ;
V_161:
F_90 ( V_167 ) ;
V_66:
F_12 ( & V_181 -> V_27 ) ;
V_187:
if ( V_183 . V_48 )
F_88 ( V_183 ) ;
F_58 ( & V_48 -> V_59 -> V_185 ) ;
return V_15 ;
}
T_2 F_91 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_91 V_52 ;
struct V_1 * V_2 ;
struct V_44 * V_167 = NULL ;
struct V_166 * V_166 = NULL ;
struct V_180 * V_181 ;
int V_12 ;
int V_15 = 0 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_47 ( & V_48 -> V_59 -> V_185 ) ;
V_2 = F_28 ( & V_46 , V_52 . V_45 , V_48 -> V_61 ) ;
if ( ! V_2 ) {
V_15 = - V_65 ;
goto V_198;
}
V_167 = V_2 -> V_22 ;
V_166 = V_167 -> V_166 ;
V_181 = F_7 ( V_2 , struct V_180 , V_27 ) ;
if ( F_92 ( & V_181 -> V_196 ) ) {
F_12 ( V_2 ) ;
V_15 = - V_199 ;
goto V_198;
}
if ( ! V_166 || F_93 ( & V_167 -> V_160 ) ) {
V_15 = F_90 ( V_2 -> V_22 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
}
V_12 = V_2 -> V_12 ;
if ( V_166 && V_15 )
F_87 ( & V_167 -> V_160 ) ;
F_12 ( V_2 ) ;
if ( V_15 )
goto V_198;
if ( V_166 && ! V_12 )
F_80 ( V_48 -> V_59 , V_166 ) ;
F_20 ( & V_46 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
V_15 = V_50 ;
V_198:
F_58 ( & V_48 -> V_59 -> V_185 ) ;
return V_15 ;
}
void F_94 ( struct V_164 * V_165 ,
struct V_44 * V_167 )
{
struct V_166 * V_166 ;
V_166 = V_167 -> V_166 ;
if ( V_166 && ! F_93 ( & V_167 -> V_160 ) )
return;
F_90 ( V_167 ) ;
if ( V_166 )
F_80 ( V_165 , V_166 ) ;
}
T_2 F_95 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_95 V_52 ;
struct V_200 V_54 ;
struct V_55 V_56 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_201 * V_202 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
if ( ( V_52 . V_203 & ~ V_204 ) != ( V_52 . V_205 & ~ V_204 ) )
return - V_65 ;
if ( V_52 . V_206 & ( V_207 | V_208 ) &&
! ( V_52 . V_206 & V_209 ) )
return - V_65 ;
V_2 = F_67 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_157 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_210 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_81;
}
V_202 = V_26 -> V_59 -> V_211 ( V_26 , V_52 . V_203 , V_52 . V_212 , V_52 . V_205 ,
V_52 . V_206 , & V_56 ) ;
if ( F_49 ( V_202 ) ) {
V_15 = F_50 ( V_202 ) ;
goto V_213;
}
V_202 -> V_59 = V_26 -> V_59 ;
V_202 -> V_26 = V_26 ;
V_202 -> V_27 = V_2 ;
F_87 ( & V_26 -> V_160 ) ;
F_68 ( & V_202 -> V_160 , 0 ) ;
V_2 -> V_22 = V_202 ;
V_15 = F_14 ( & V_214 , V_2 ) ;
if ( V_15 )
goto V_215;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_216 = V_202 -> V_216 ;
V_54 . V_217 = V_202 -> V_217 ;
V_54 . V_218 = V_2 -> V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_162;
}
F_32 ( V_26 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_163 , & V_48 -> V_61 -> V_70 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_162:
F_20 ( & V_214 , V_2 ) ;
V_215:
F_96 ( V_202 ) ;
V_213:
F_32 ( V_26 ) ;
V_81:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_97 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_97 V_52 ;
struct V_201 * V_202 ;
struct V_1 * V_2 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_214 , V_52 . V_218 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_202 = V_2 -> V_22 ;
V_15 = F_96 ( V_202 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_214 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_98 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_98 V_52 ;
struct V_219 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_220 * V_221 ;
int V_15 ;
if ( V_51 < sizeof( V_54 ) )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_64 ;
V_2 = F_67 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return - V_157 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_222 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_81;
}
V_221 = V_26 -> V_59 -> V_223 ( V_26 , V_52 . V_224 ) ;
if ( F_49 ( V_221 ) ) {
V_15 = F_50 ( V_221 ) ;
goto V_213;
}
V_221 -> V_59 = V_26 -> V_59 ;
V_221 -> V_26 = V_26 ;
V_221 -> V_27 = V_2 ;
F_87 ( & V_26 -> V_160 ) ;
V_2 -> V_22 = V_221 ;
V_15 = F_14 ( & V_225 , V_2 ) ;
if ( V_15 )
goto V_226;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_217 = V_221 -> V_217 ;
V_54 . V_227 = V_2 -> V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof( V_54 ) ) ) {
V_15 = - V_64 ;
goto V_162;
}
F_32 ( V_26 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_163 , & V_48 -> V_61 -> V_71 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_162:
F_20 ( & V_225 , V_2 ) ;
V_226:
F_99 ( V_221 ) ;
V_213:
F_32 ( V_26 ) ;
V_81:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_100 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_100 V_52 ;
struct V_220 * V_221 ;
struct V_1 * V_2 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_64 ;
V_2 = F_28 ( & V_225 , V_52 . V_227 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_221 = V_2 -> V_22 ;
V_15 = F_99 ( V_221 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_225 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_101 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_101 V_52 ;
struct V_228 V_54 ;
struct V_48 * V_62 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_15 = F_52 ( V_80 ) ;
if ( V_15 < 0 )
return V_15 ;
V_54 . V_182 = V_15 ;
V_62 = F_53 ( V_48 , 0 ) ;
if ( F_49 ( V_62 ) ) {
F_60 ( V_54 . V_182 ) ;
return F_50 ( V_62 ) ;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
F_60 ( V_54 . V_182 ) ;
F_59 ( V_62 ) ;
return - V_64 ;
}
F_57 ( V_54 . V_182 , V_62 ) ;
return V_50 ;
}
T_2 F_102 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_102 V_52 ;
struct V_229 V_54 ;
struct V_55 V_56 ;
struct V_230 * V_181 ;
struct V_231 * V_232 = NULL ;
struct V_28 * V_31 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
if ( V_52 . V_233 >= V_48 -> V_59 -> V_79 )
return - V_65 ;
V_181 = F_67 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 )
return - V_157 ;
F_1 ( & V_181 -> V_27 , V_52 . V_3 , V_48 -> V_61 , & V_234 ) ;
F_29 ( & V_181 -> V_27 . V_9 ) ;
if ( V_52 . V_235 >= 0 ) {
V_232 = F_103 ( V_52 . V_235 ) ;
if ( ! V_232 ) {
V_15 = - V_65 ;
goto V_66;
}
}
V_181 -> V_236 = V_48 ;
V_181 -> V_237 = 0 ;
V_181 -> V_238 = 0 ;
F_51 ( & V_181 -> V_239 ) ;
F_51 ( & V_181 -> V_240 ) ;
V_31 = V_48 -> V_59 -> V_60 -> V_241 ( V_48 -> V_59 -> V_60 , V_52 . V_242 ,
V_52 . V_233 ,
V_48 -> V_61 , & V_56 ) ;
if ( F_49 ( V_31 ) ) {
V_15 = F_50 ( V_31 ) ;
goto V_84;
}
V_31 -> V_59 = V_48 -> V_59 -> V_60 ;
V_31 -> V_27 = & V_181 -> V_27 ;
V_31 -> V_243 = V_244 ;
V_31 -> V_87 = V_245 ;
V_31 -> V_246 = V_232 ;
F_68 ( & V_31 -> V_160 , 0 ) ;
V_181 -> V_27 . V_22 = V_31 ;
V_15 = F_14 ( & V_30 , & V_181 -> V_27 ) ;
if ( V_15 )
goto V_81;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_29 = V_181 -> V_27 . V_19 ;
V_54 . V_242 = V_31 -> V_242 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_162;
}
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_181 -> V_27 . V_163 , & V_48 -> V_61 -> V_72 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_181 -> V_27 . V_12 = 1 ;
F_13 ( & V_181 -> V_27 . V_9 ) ;
return V_50 ;
V_162:
F_20 ( & V_30 , & V_181 -> V_27 ) ;
V_81:
F_104 ( V_31 ) ;
V_84:
if ( V_232 )
F_105 ( V_48 , V_232 , V_181 ) ;
V_66:
F_12 ( & V_181 -> V_27 ) ;
return V_15 ;
}
T_2 F_106 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_106 V_52 ;
struct V_247 V_54 ;
struct V_55 V_56 ;
struct V_28 * V_31 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_31 )
return - V_65 ;
V_15 = V_31 -> V_59 -> V_248 ( V_31 , V_52 . V_242 , & V_56 ) ;
if ( V_15 )
goto V_198;
V_54 . V_242 = V_31 -> V_242 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 . V_242 ) )
V_15 = - V_64 ;
V_198:
F_34 ( V_31 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_107 ( void T_3 * V_249 , struct V_250 * V_251 )
{
struct V_252 V_253 ;
V_253 . V_254 = V_251 -> V_254 ;
V_253 . V_255 = V_251 -> V_255 ;
V_253 . V_256 = V_251 -> V_256 ;
V_253 . V_257 = V_251 -> V_257 ;
V_253 . V_258 = V_251 -> V_258 ;
V_253 . V_259 . V_260 = ( V_261 V_262 ) V_251 -> V_259 . V_260 ;
V_253 . V_263 = V_251 -> V_39 -> V_263 ;
V_253 . V_264 = V_251 -> V_264 ;
V_253 . V_265 = V_251 -> V_265 ;
V_253 . V_266 = V_251 -> V_266 ;
V_253 . V_267 = V_251 -> V_267 ;
V_253 . V_268 = V_251 -> V_268 ;
V_253 . V_269 = V_251 -> V_269 ;
V_253 . V_135 = V_251 -> V_135 ;
V_253 . V_270 = 0 ;
if ( F_54 ( V_249 , & V_253 , sizeof V_253 ) )
return - V_64 ;
return 0 ;
}
T_2 F_108 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_108 V_52 ;
struct V_271 V_54 ;
T_4 T_3 * V_272 ;
T_4 T_3 * V_273 ;
struct V_28 * V_31 ;
struct V_250 V_251 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_31 )
return - V_65 ;
V_272 = ( void T_3 * ) ( unsigned long ) V_52 . V_67 ;
V_273 = V_272 + sizeof V_54 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
while ( V_54 . V_274 < V_52 . V_275 ) {
V_15 = F_109 ( V_31 , 1 , & V_251 ) ;
if ( V_15 < 0 )
goto V_276;
if ( ! V_15 )
break;
V_15 = F_107 ( V_273 , & V_251 ) ;
if ( V_15 )
goto V_276;
V_273 += sizeof( struct V_252 ) ;
++ V_54 . V_274 ;
}
if ( F_54 ( V_272 , & V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_276;
}
V_15 = V_50 ;
V_276:
F_34 ( V_31 ) ;
return V_15 ;
}
T_2 F_110 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_110 V_52 ;
struct V_28 * V_31 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_31 )
return - V_65 ;
F_111 ( V_31 , V_52 . V_277 ?
V_278 : V_279 ) ;
F_34 ( V_31 ) ;
return V_50 ;
}
T_2 F_112 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_112 V_52 ;
struct V_280 V_54 ;
struct V_1 * V_2 ;
struct V_28 * V_31 ;
struct V_230 * V_181 ;
struct V_231 * V_232 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_30 , V_52 . V_29 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_31 = V_2 -> V_22 ;
V_232 = V_31 -> V_246 ;
V_181 = F_7 ( V_31 -> V_27 , struct V_230 , V_27 ) ;
V_15 = F_104 ( V_31 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_30 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_105 ( V_48 , V_232 , V_181 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_237 = V_181 -> V_237 ;
V_54 . V_238 = V_181 -> V_238 ;
F_8 ( V_2 ) ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_113 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_113 V_52 ;
struct V_281 V_54 ;
struct V_55 V_56 ;
struct V_282 * V_181 ;
struct V_57 * V_59 ;
struct V_23 * V_26 = NULL ;
struct V_44 * V_167 = NULL ;
struct V_1 * V_283 ( V_284 ) ;
struct V_28 * V_285 = NULL , * V_286 = NULL ;
struct V_40 * V_43 = NULL ;
struct V_36 * V_39 ;
struct V_287 V_92 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
if ( V_52 . V_288 == V_289 && ! F_114 ( V_290 ) )
return - V_291 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_181 = F_115 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 )
return - V_157 ;
F_1 ( & V_181 -> V_292 . V_27 , V_52 . V_3 , V_48 -> V_61 , & V_293 ) ;
F_29 ( & V_181 -> V_292 . V_27 . V_9 ) ;
if ( V_52 . V_288 == V_294 ) {
V_167 = F_43 ( V_52 . V_24 , V_48 -> V_61 , & V_284 ) ;
if ( ! V_167 ) {
V_15 = - V_65 ;
goto V_213;
}
V_59 = V_167 -> V_59 ;
} else {
if ( V_52 . V_288 == V_295 ) {
V_52 . V_296 = V_52 . V_297 = 0 ;
} else {
if ( V_52 . V_298 ) {
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 || V_43 -> V_299 != V_300 ) {
V_15 = - V_65 ;
goto V_213;
}
}
if ( V_52 . V_301 != V_52 . V_302 ) {
V_286 = F_33 ( V_52 . V_301 , V_48 -> V_61 , 0 ) ;
if ( ! V_286 ) {
V_15 = - V_65 ;
goto V_213;
}
}
}
V_285 = F_33 ( V_52 . V_302 , V_48 -> V_61 , ! ! V_286 ) ;
V_286 = V_286 ? : V_285 ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 || ! V_285 ) {
V_15 = - V_65 ;
goto V_213;
}
V_59 = V_26 -> V_59 ;
}
V_92 . V_87 = V_303 ;
V_92 . V_304 = V_48 ;
V_92 . V_305 = V_285 ;
V_92 . V_306 = V_286 ;
V_92 . V_43 = V_43 ;
V_92 . V_167 = V_167 ;
V_92 . V_307 = V_52 . V_308 ? V_309 : V_310 ;
V_92 . V_288 = V_52 . V_288 ;
V_92 . V_311 = 0 ;
V_92 . V_312 . V_313 = V_52 . V_313 ;
V_92 . V_312 . V_296 = V_52 . V_296 ;
V_92 . V_312 . V_314 = V_52 . V_314 ;
V_92 . V_312 . V_297 = V_52 . V_297 ;
V_92 . V_312 . V_315 = V_52 . V_315 ;
V_181 -> V_292 . V_316 = 0 ;
F_51 ( & V_181 -> V_292 . V_317 ) ;
F_51 ( & V_181 -> V_318 ) ;
if ( V_52 . V_288 == V_294 )
V_39 = F_116 ( V_26 , & V_92 ) ;
else
V_39 = V_59 -> V_319 ( V_26 , & V_92 , & V_56 ) ;
if ( F_49 ( V_39 ) ) {
V_15 = F_50 ( V_39 ) ;
goto V_213;
}
if ( V_52 . V_288 != V_294 ) {
V_39 -> V_320 = V_39 ;
V_39 -> V_59 = V_59 ;
V_39 -> V_26 = V_26 ;
V_39 -> V_305 = V_92 . V_305 ;
V_39 -> V_306 = V_92 . V_306 ;
V_39 -> V_43 = V_92 . V_43 ;
V_39 -> V_87 = V_92 . V_87 ;
V_39 -> V_304 = V_92 . V_304 ;
V_39 -> V_288 = V_92 . V_288 ;
F_68 ( & V_39 -> V_160 , 0 ) ;
F_87 ( & V_26 -> V_160 ) ;
F_87 ( & V_92 . V_305 -> V_160 ) ;
if ( V_92 . V_306 )
F_87 ( & V_92 . V_306 -> V_160 ) ;
if ( V_92 . V_43 )
F_87 ( & V_92 . V_43 -> V_160 ) ;
}
V_39 -> V_27 = & V_181 -> V_292 . V_27 ;
V_181 -> V_292 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_181 -> V_292 . V_27 ) ;
if ( V_15 )
goto V_321;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_322 = V_39 -> V_263 ;
V_54 . V_37 = V_181 -> V_292 . V_27 . V_19 ;
V_54 . V_297 = V_92 . V_312 . V_297 ;
V_54 . V_314 = V_92 . V_312 . V_314 ;
V_54 . V_296 = V_92 . V_312 . V_296 ;
V_54 . V_313 = V_92 . V_312 . V_313 ;
V_54 . V_315 = V_92 . V_312 . V_315 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_162;
}
if ( V_167 ) {
V_181 -> V_323 = F_7 ( V_284 , struct V_180 ,
V_27 ) ;
F_87 ( & V_181 -> V_323 -> V_196 ) ;
F_44 ( V_284 ) ;
}
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_285 )
F_34 ( V_285 ) ;
if ( V_286 && V_286 != V_285 )
F_34 ( V_286 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_181 -> V_292 . V_27 . V_163 , & V_48 -> V_61 -> V_73 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_181 -> V_292 . V_27 . V_12 = 1 ;
F_13 ( & V_181 -> V_292 . V_27 . V_9 ) ;
return V_50 ;
V_162:
F_20 ( & V_38 , & V_181 -> V_292 . V_27 ) ;
V_321:
F_117 ( V_39 ) ;
V_213:
if ( V_167 )
F_44 ( V_284 ) ;
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_285 )
F_34 ( V_285 ) ;
if ( V_286 && V_286 != V_285 )
F_34 ( V_286 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_12 ( & V_181 -> V_292 . V_27 ) ;
return V_15 ;
}
T_2 F_118 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_118 V_52 ;
struct V_281 V_54 ;
struct V_55 V_56 ;
struct V_282 * V_181 ;
struct V_44 * V_167 ;
struct V_1 * V_283 ( V_284 ) ;
struct V_36 * V_39 ;
struct V_324 V_92 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_181 = F_67 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 )
return - V_157 ;
F_1 ( & V_181 -> V_292 . V_27 , V_52 . V_3 , V_48 -> V_61 , & V_293 ) ;
F_29 ( & V_181 -> V_292 . V_27 . V_9 ) ;
V_167 = F_43 ( V_52 . V_24 , V_48 -> V_61 , & V_284 ) ;
if ( ! V_167 ) {
V_15 = - V_65 ;
goto V_213;
}
V_92 . V_87 = V_303 ;
V_92 . V_304 = V_48 ;
V_92 . V_263 = V_52 . V_322 ;
V_92 . V_288 = V_52 . V_288 ;
V_181 -> V_292 . V_316 = 0 ;
F_51 ( & V_181 -> V_292 . V_317 ) ;
F_51 ( & V_181 -> V_318 ) ;
V_39 = F_119 ( V_167 , & V_92 ) ;
if ( F_49 ( V_39 ) ) {
V_15 = F_50 ( V_39 ) ;
goto V_213;
}
V_39 -> V_27 = & V_181 -> V_292 . V_27 ;
V_181 -> V_292 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_181 -> V_292 . V_27 ) ;
if ( V_15 )
goto V_321;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_322 = V_39 -> V_263 ;
V_54 . V_37 = V_181 -> V_292 . V_27 . V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_325;
}
V_181 -> V_323 = F_7 ( V_284 , struct V_180 , V_27 ) ;
F_87 ( & V_181 -> V_323 -> V_196 ) ;
F_44 ( V_284 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_181 -> V_292 . V_27 . V_163 , & V_48 -> V_61 -> V_73 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_181 -> V_292 . V_27 . V_12 = 1 ;
F_13 ( & V_181 -> V_292 . V_27 . V_9 ) ;
return V_50 ;
V_325:
F_20 ( & V_38 , & V_181 -> V_292 . V_27 ) ;
V_321:
F_117 ( V_39 ) ;
V_213:
F_44 ( V_284 ) ;
F_12 ( & V_181 -> V_292 . V_27 ) ;
return V_15 ;
}
T_2 F_120 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_120 V_52 ;
struct V_326 V_54 ;
struct V_36 * V_39 ;
struct V_327 * V_92 ;
struct V_287 * V_328 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_92 = F_67 ( sizeof *V_92 , V_16 ) ;
V_328 = F_67 ( sizeof *V_328 , V_16 ) ;
if ( ! V_92 || ! V_328 ) {
V_15 = - V_157 ;
goto V_198;
}
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_15 = - V_65 ;
goto V_198;
}
V_15 = F_121 ( V_39 , V_92 , V_52 . V_329 , V_328 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
goto V_198;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_330 = V_92 -> V_330 ;
V_54 . V_331 = V_92 -> V_331 ;
V_54 . V_332 = V_92 -> V_332 ;
V_54 . V_333 = V_92 -> V_333 ;
V_54 . V_334 = V_92 -> V_334 ;
V_54 . V_335 = V_92 -> V_335 ;
V_54 . V_336 = V_92 -> V_336 ;
V_54 . V_337 = V_92 -> V_337 ;
V_54 . V_338 = V_92 -> V_338 ;
V_54 . V_266 = V_92 -> V_266 ;
V_54 . V_339 = V_92 -> V_339 ;
V_54 . V_340 = V_92 -> V_340 ;
V_54 . V_341 = V_92 -> V_341 ;
V_54 . V_342 = V_92 -> V_342 ;
V_54 . V_343 = V_92 -> V_343 ;
V_54 . V_135 = V_92 -> V_135 ;
V_54 . V_344 = V_92 -> V_344 ;
V_54 . V_345 = V_92 -> V_345 ;
V_54 . V_346 = V_92 -> V_346 ;
V_54 . V_347 = V_92 -> V_347 ;
V_54 . V_348 = V_92 -> V_348 ;
memcpy ( V_54 . V_249 . V_349 , V_92 -> V_350 . V_351 . V_349 . V_352 , 16 ) ;
V_54 . V_249 . V_353 = V_92 -> V_350 . V_351 . V_353 ;
V_54 . V_249 . V_354 = V_92 -> V_350 . V_351 . V_354 ;
V_54 . V_249 . V_355 = V_92 -> V_350 . V_351 . V_355 ;
V_54 . V_249 . V_356 = V_92 -> V_350 . V_351 . V_356 ;
V_54 . V_249 . V_357 = V_92 -> V_350 . V_357 ;
V_54 . V_249 . V_268 = V_92 -> V_350 . V_268 ;
V_54 . V_249 . V_358 = V_92 -> V_350 . V_358 ;
V_54 . V_249 . V_359 = V_92 -> V_350 . V_359 ;
V_54 . V_249 . V_360 = ! ! ( V_92 -> V_350 . V_361 & V_362 ) ;
V_54 . V_249 . V_135 = V_92 -> V_350 . V_135 ;
memcpy ( V_54 . V_363 . V_349 , V_92 -> V_364 . V_351 . V_349 . V_352 , 16 ) ;
V_54 . V_363 . V_353 = V_92 -> V_364 . V_351 . V_353 ;
V_54 . V_363 . V_354 = V_92 -> V_364 . V_351 . V_354 ;
V_54 . V_363 . V_355 = V_92 -> V_364 . V_351 . V_355 ;
V_54 . V_363 . V_356 = V_92 -> V_364 . V_351 . V_356 ;
V_54 . V_363 . V_357 = V_92 -> V_364 . V_357 ;
V_54 . V_363 . V_268 = V_92 -> V_364 . V_268 ;
V_54 . V_363 . V_358 = V_92 -> V_364 . V_358 ;
V_54 . V_363 . V_359 = V_92 -> V_364 . V_359 ;
V_54 . V_363 . V_360 = ! ! ( V_92 -> V_364 . V_361 & V_362 ) ;
V_54 . V_363 . V_135 = V_92 -> V_364 . V_135 ;
V_54 . V_313 = V_328 -> V_312 . V_313 ;
V_54 . V_296 = V_328 -> V_312 . V_296 ;
V_54 . V_314 = V_328 -> V_312 . V_314 ;
V_54 . V_297 = V_328 -> V_312 . V_297 ;
V_54 . V_315 = V_328 -> V_312 . V_315 ;
V_54 . V_308 = V_328 -> V_307 == V_309 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_198:
F_6 ( V_92 ) ;
F_6 ( V_328 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_122 ( enum V_365 V_288 , int V_366 )
{
switch ( V_288 ) {
case V_295 :
return V_366 & ~ ( V_367 | V_368 ) ;
case V_294 :
return V_366 & ~ ( V_369 | V_370 |
V_371 ) ;
default:
return V_366 ;
}
}
T_2 F_123 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_123 V_52 ;
struct V_55 V_56 ;
struct V_36 * V_39 ;
struct V_327 * V_92 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 , NULL , V_50 - sizeof V_52 ,
V_51 ) ;
V_92 = F_67 ( sizeof *V_92 , V_16 ) ;
if ( ! V_92 )
return - V_157 ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_15 = - V_65 ;
goto V_198;
}
V_92 -> V_330 = V_52 . V_330 ;
V_92 -> V_331 = V_52 . V_331 ;
V_92 -> V_332 = V_52 . V_332 ;
V_92 -> V_333 = V_52 . V_333 ;
V_92 -> V_334 = V_52 . V_334 ;
V_92 -> V_335 = V_52 . V_335 ;
V_92 -> V_336 = V_52 . V_336 ;
V_92 -> V_337 = V_52 . V_337 ;
V_92 -> V_338 = V_52 . V_338 ;
V_92 -> V_266 = V_52 . V_266 ;
V_92 -> V_339 = V_52 . V_339 ;
V_92 -> V_372 = V_52 . V_372 ;
V_92 -> V_341 = V_52 . V_341 ;
V_92 -> V_342 = V_52 . V_342 ;
V_92 -> V_343 = V_52 . V_343 ;
V_92 -> V_135 = V_52 . V_135 ;
V_92 -> V_344 = V_52 . V_344 ;
V_92 -> V_345 = V_52 . V_345 ;
V_92 -> V_346 = V_52 . V_346 ;
V_92 -> V_347 = V_52 . V_347 ;
V_92 -> V_348 = V_52 . V_348 ;
memcpy ( V_92 -> V_350 . V_351 . V_349 . V_352 , V_52 . V_249 . V_349 , 16 ) ;
V_92 -> V_350 . V_351 . V_353 = V_52 . V_249 . V_353 ;
V_92 -> V_350 . V_351 . V_354 = V_52 . V_249 . V_354 ;
V_92 -> V_350 . V_351 . V_355 = V_52 . V_249 . V_355 ;
V_92 -> V_350 . V_351 . V_356 = V_52 . V_249 . V_356 ;
V_92 -> V_350 . V_357 = V_52 . V_249 . V_357 ;
V_92 -> V_350 . V_268 = V_52 . V_249 . V_268 ;
V_92 -> V_350 . V_358 = V_52 . V_249 . V_358 ;
V_92 -> V_350 . V_359 = V_52 . V_249 . V_359 ;
V_92 -> V_350 . V_361 = V_52 . V_249 . V_360 ? V_362 : 0 ;
V_92 -> V_350 . V_135 = V_52 . V_249 . V_135 ;
memcpy ( V_92 -> V_364 . V_351 . V_349 . V_352 , V_52 . V_363 . V_349 , 16 ) ;
V_92 -> V_364 . V_351 . V_353 = V_52 . V_363 . V_353 ;
V_92 -> V_364 . V_351 . V_354 = V_52 . V_363 . V_354 ;
V_92 -> V_364 . V_351 . V_355 = V_52 . V_363 . V_355 ;
V_92 -> V_364 . V_351 . V_356 = V_52 . V_363 . V_356 ;
V_92 -> V_364 . V_357 = V_52 . V_363 . V_357 ;
V_92 -> V_364 . V_268 = V_52 . V_363 . V_268 ;
V_92 -> V_364 . V_358 = V_52 . V_363 . V_358 ;
V_92 -> V_364 . V_359 = V_52 . V_363 . V_359 ;
V_92 -> V_364 . V_361 = V_52 . V_363 . V_360 ? V_362 : 0 ;
V_92 -> V_364 . V_135 = V_52 . V_363 . V_135 ;
if ( V_39 -> V_320 == V_39 ) {
V_15 = V_39 -> V_59 -> V_373 ( V_39 , V_92 ,
F_122 ( V_39 -> V_288 , V_52 . V_329 ) , & V_56 ) ;
} else {
V_15 = F_124 ( V_39 , V_92 , F_122 ( V_39 -> V_288 , V_52 . V_329 ) ) ;
}
F_39 ( V_39 ) ;
if ( V_15 )
goto V_198;
V_15 = V_50 ;
V_198:
F_6 ( V_92 ) ;
return V_15 ;
}
T_2 F_125 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_125 V_52 ;
struct V_374 V_54 ;
struct V_1 * V_2 ;
struct V_36 * V_39 ;
struct V_282 * V_181 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_2 = F_28 ( & V_38 , V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_39 = V_2 -> V_22 ;
V_181 = F_7 ( V_2 , struct V_282 , V_292 . V_27 ) ;
if ( ! F_126 ( & V_181 -> V_318 ) ) {
F_12 ( V_2 ) ;
return - V_199 ;
}
V_15 = F_117 ( V_39 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_181 -> V_323 )
F_89 ( & V_181 -> V_323 -> V_196 ) ;
F_20 ( & V_38 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_127 ( V_48 , & V_181 -> V_292 ) ;
V_54 . V_316 = V_181 -> V_292 . V_316 ;
F_8 ( V_2 ) ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_128 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_128 V_52 ;
struct V_375 V_54 ;
struct V_376 * V_377 ;
struct V_378 * V_379 = NULL , * V_380 , * V_381 , * V_382 ;
struct V_36 * V_39 ;
int V_383 , V_384 ;
int V_385 ;
T_2 V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
if ( V_50 < sizeof V_52 + V_52 . V_386 * V_52 . V_387 +
V_52 . V_388 * sizeof ( struct V_389 ) )
return - V_65 ;
if ( V_52 . V_386 < sizeof ( struct V_376 ) )
return - V_65 ;
V_377 = F_67 ( V_52 . V_386 , V_16 ) ;
if ( ! V_377 )
return - V_157 ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
goto V_198;
V_385 = V_39 -> V_288 == V_390 ;
V_384 = 0 ;
V_380 = NULL ;
for ( V_383 = 0 ; V_383 < V_52 . V_387 ; ++ V_383 ) {
if ( F_46 ( V_377 ,
V_49 + sizeof V_52 + V_383 * V_52 . V_386 ,
V_52 . V_386 ) ) {
V_15 = - V_64 ;
goto V_276;
}
if ( V_377 -> V_391 + V_384 > V_52 . V_388 ) {
V_15 = - V_65 ;
goto V_276;
}
V_381 = F_67 ( F_129 ( sizeof *V_381 , sizeof ( struct V_392 ) ) +
V_377 -> V_391 * sizeof ( struct V_392 ) ,
V_16 ) ;
if ( ! V_381 ) {
V_15 = - V_157 ;
goto V_276;
}
if ( ! V_380 )
V_379 = V_381 ;
else
V_380 -> V_381 = V_381 ;
V_380 = V_381 ;
V_381 -> V_381 = NULL ;
V_381 -> V_254 = V_377 -> V_254 ;
V_381 -> V_391 = V_377 -> V_391 ;
V_381 -> V_256 = V_377 -> V_256 ;
V_381 -> V_393 = V_377 -> V_393 ;
if ( V_385 ) {
V_381 -> V_379 . V_394 . V_35 = F_35 ( V_377 -> V_379 . V_394 . V_35 ,
V_48 -> V_61 ) ;
if ( ! V_381 -> V_379 . V_394 . V_35 ) {
V_15 = - V_65 ;
goto V_276;
}
V_381 -> V_379 . V_394 . V_395 = V_377 -> V_379 . V_394 . V_395 ;
V_381 -> V_379 . V_394 . V_396 = V_377 -> V_379 . V_394 . V_396 ;
} else {
switch ( V_381 -> V_256 ) {
case V_397 :
V_381 -> V_259 . V_260 =
( V_398 V_262 ) V_377 -> V_259 . V_260 ;
case V_399 :
case V_400 :
V_381 -> V_379 . V_401 . V_402 =
V_377 -> V_379 . V_401 . V_402 ;
V_381 -> V_379 . V_401 . V_217 =
V_377 -> V_379 . V_401 . V_217 ;
break;
case V_403 :
V_381 -> V_259 . V_260 =
( V_398 V_262 ) V_377 -> V_259 . V_260 ;
break;
case V_404 :
V_381 -> V_259 . V_405 =
V_377 -> V_259 . V_405 ;
break;
case V_406 :
case V_407 :
V_381 -> V_379 . V_408 . V_402 =
V_377 -> V_379 . V_408 . V_402 ;
V_381 -> V_379 . V_408 . V_409 =
V_377 -> V_379 . V_408 . V_409 ;
V_381 -> V_379 . V_408 . V_410 = V_377 -> V_379 . V_408 . V_410 ;
V_381 -> V_379 . V_408 . V_217 = V_377 -> V_379 . V_408 . V_217 ;
break;
default:
break;
}
}
if ( V_381 -> V_391 ) {
V_381 -> V_411 = ( void * ) V_381 +
F_129 ( sizeof *V_381 , sizeof ( struct V_392 ) ) ;
if ( F_46 ( V_381 -> V_411 ,
V_49 + sizeof V_52 +
V_52 . V_387 * V_52 . V_386 +
V_384 * sizeof ( struct V_392 ) ,
V_381 -> V_391 * sizeof ( struct V_392 ) ) ) {
V_15 = - V_64 ;
goto V_276;
}
V_384 += V_381 -> V_391 ;
} else
V_381 -> V_411 = NULL ;
}
V_54 . V_382 = 0 ;
V_15 = V_39 -> V_59 -> V_412 ( V_39 -> V_320 , V_379 , & V_382 ) ;
if ( V_15 )
for ( V_381 = V_379 ; V_381 ; V_381 = V_381 -> V_381 ) {
++ V_54 . V_382 ;
if ( V_381 == V_382 )
break;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_276:
F_39 ( V_39 ) ;
while ( V_379 ) {
if ( V_385 && V_379 -> V_379 . V_394 . V_35 )
F_36 ( V_379 -> V_379 . V_394 . V_35 ) ;
V_381 = V_379 -> V_381 ;
F_6 ( V_379 ) ;
V_379 = V_381 ;
}
V_198:
F_6 ( V_377 ) ;
return V_15 ? V_15 : V_50 ;
}
static struct V_413 * F_130 ( const char T_3 * V_49 ,
int V_50 ,
T_5 V_387 ,
T_5 V_388 ,
T_5 V_386 )
{
struct V_414 * V_377 ;
struct V_413 * V_379 = NULL , * V_380 , * V_381 ;
int V_384 ;
int V_383 ;
int V_15 ;
if ( V_50 < V_386 * V_387 +
V_388 * sizeof ( struct V_389 ) )
return F_131 ( - V_65 ) ;
if ( V_386 < sizeof ( struct V_414 ) )
return F_131 ( - V_65 ) ;
V_377 = F_67 ( V_386 , V_16 ) ;
if ( ! V_377 )
return F_131 ( - V_157 ) ;
V_384 = 0 ;
V_380 = NULL ;
for ( V_383 = 0 ; V_383 < V_387 ; ++ V_383 ) {
if ( F_46 ( V_377 , V_49 + V_383 * V_386 ,
V_386 ) ) {
V_15 = - V_64 ;
goto V_66;
}
if ( V_377 -> V_391 + V_384 > V_388 ) {
V_15 = - V_65 ;
goto V_66;
}
V_381 = F_67 ( F_129 ( sizeof *V_381 , sizeof ( struct V_392 ) ) +
V_377 -> V_391 * sizeof ( struct V_392 ) ,
V_16 ) ;
if ( ! V_381 ) {
V_15 = - V_157 ;
goto V_66;
}
if ( ! V_380 )
V_379 = V_381 ;
else
V_380 -> V_381 = V_381 ;
V_380 = V_381 ;
V_381 -> V_381 = NULL ;
V_381 -> V_254 = V_377 -> V_254 ;
V_381 -> V_391 = V_377 -> V_391 ;
if ( V_381 -> V_391 ) {
V_381 -> V_411 = ( void * ) V_381 +
F_129 ( sizeof *V_381 , sizeof ( struct V_392 ) ) ;
if ( F_46 ( V_381 -> V_411 ,
V_49 + V_387 * V_386 +
V_384 * sizeof ( struct V_392 ) ,
V_381 -> V_391 * sizeof ( struct V_392 ) ) ) {
V_15 = - V_64 ;
goto V_66;
}
V_384 += V_381 -> V_391 ;
} else
V_381 -> V_411 = NULL ;
}
F_6 ( V_377 ) ;
return V_379 ;
V_66:
F_6 ( V_377 ) ;
while ( V_379 ) {
V_381 = V_379 -> V_381 ;
F_6 ( V_379 ) ;
V_379 = V_381 ;
}
return F_131 ( V_15 ) ;
}
T_2 F_132 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_132 V_52 ;
struct V_415 V_54 ;
struct V_413 * V_379 , * V_381 , * V_382 ;
struct V_36 * V_39 ;
T_2 V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_379 = F_130 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_387 ,
V_52 . V_388 , V_52 . V_386 ) ;
if ( F_49 ( V_379 ) )
return F_50 ( V_379 ) ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
goto V_198;
V_54 . V_382 = 0 ;
V_15 = V_39 -> V_59 -> V_416 ( V_39 -> V_320 , V_379 , & V_382 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
for ( V_381 = V_379 ; V_381 ; V_381 = V_381 -> V_381 ) {
++ V_54 . V_382 ;
if ( V_381 == V_382 )
break;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_198:
while ( V_379 ) {
V_381 = V_379 -> V_381 ;
F_6 ( V_379 ) ;
V_379 = V_381 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_133 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_133 V_52 ;
struct V_417 V_54 ;
struct V_413 * V_379 , * V_381 , * V_382 ;
struct V_40 * V_43 ;
T_2 V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_379 = F_130 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_387 ,
V_52 . V_388 , V_52 . V_386 ) ;
if ( F_49 ( V_379 ) )
return F_50 ( V_379 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
goto V_198;
V_54 . V_382 = 0 ;
V_15 = V_43 -> V_59 -> V_418 ( V_43 , V_379 , & V_382 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
for ( V_381 = V_379 ; V_381 ; V_381 = V_381 -> V_381 ) {
++ V_54 . V_382 ;
if ( V_381 == V_382 )
break;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_198:
while ( V_379 ) {
V_381 = V_379 -> V_381 ;
F_6 ( V_379 ) ;
V_379 = V_381 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_134 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_134 V_52 ;
struct V_419 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_32 * V_35 ;
struct V_420 V_92 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_67 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_157 ;
F_1 ( V_2 , V_52 . V_3 , V_48 -> V_61 , & V_421 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_66;
}
V_92 . V_357 = V_52 . V_92 . V_357 ;
V_92 . V_268 = V_52 . V_92 . V_268 ;
V_92 . V_358 = V_52 . V_92 . V_358 ;
V_92 . V_359 = V_52 . V_92 . V_359 ;
V_92 . V_361 = V_52 . V_92 . V_360 ? V_362 : 0 ;
V_92 . V_135 = V_52 . V_92 . V_135 ;
V_92 . V_351 . V_353 = V_52 . V_92 . V_351 . V_353 ;
V_92 . V_351 . V_354 = V_52 . V_92 . V_351 . V_354 ;
V_92 . V_351 . V_355 = V_52 . V_92 . V_351 . V_355 ;
V_92 . V_351 . V_356 = V_52 . V_92 . V_351 . V_356 ;
memcpy ( V_92 . V_351 . V_349 . V_352 , V_52 . V_92 . V_351 . V_349 , 16 ) ;
V_35 = F_135 ( V_26 , & V_92 ) ;
if ( F_49 ( V_35 ) ) {
V_15 = F_50 ( V_35 ) ;
goto V_213;
}
V_35 -> V_27 = V_2 ;
V_2 -> V_22 = V_35 ;
V_15 = F_14 ( & V_34 , V_2 ) ;
if ( V_15 )
goto V_321;
V_54 . V_33 = V_2 -> V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_162;
}
F_32 ( V_26 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_163 , & V_48 -> V_61 -> V_75 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_162:
F_20 ( & V_34 , V_2 ) ;
V_321:
F_136 ( V_35 ) ;
V_213:
F_32 ( V_26 ) ;
V_66:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_137 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_137 V_52 ;
struct V_32 * V_35 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_34 , V_52 . V_33 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_35 = V_2 -> V_22 ;
V_15 = F_136 ( V_35 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_34 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_138 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_138 V_52 ;
struct V_36 * V_39 ;
struct V_282 * V_181 ;
struct V_422 * V_423 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
return - V_65 ;
V_181 = F_7 ( V_39 -> V_27 , struct V_282 , V_292 . V_27 ) ;
F_139 (mcast, &obj->mcast_list, list)
if ( V_52 . V_424 == V_423 -> V_145 &&
! memcmp ( V_52 . V_425 , V_423 -> V_425 . V_352 , sizeof V_423 -> V_425 . V_352 ) ) {
V_15 = 0 ;
goto V_276;
}
V_423 = F_67 ( sizeof *V_423 , V_16 ) ;
if ( ! V_423 ) {
V_15 = - V_157 ;
goto V_276;
}
V_423 -> V_145 = V_52 . V_424 ;
memcpy ( V_423 -> V_425 . V_352 , V_52 . V_425 , sizeof V_423 -> V_425 . V_352 ) ;
V_15 = F_140 ( V_39 , & V_423 -> V_425 , V_52 . V_424 ) ;
if ( ! V_15 )
F_69 ( & V_423 -> V_163 , & V_181 -> V_318 ) ;
else
F_6 ( V_423 ) ;
V_276:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_141 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_141 V_52 ;
struct V_282 * V_181 ;
struct V_36 * V_39 ;
struct V_422 * V_423 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
return - V_65 ;
V_15 = F_142 ( V_39 , (union V_426 * ) V_52 . V_425 , V_52 . V_424 ) ;
if ( V_15 )
goto V_276;
V_181 = F_7 ( V_39 -> V_27 , struct V_282 , V_292 . V_27 ) ;
F_139 (mcast, &obj->mcast_list, list)
if ( V_52 . V_424 == V_423 -> V_145 &&
! memcmp ( V_52 . V_425 , V_423 -> V_425 . V_352 , sizeof V_423 -> V_425 . V_352 ) ) {
F_72 ( & V_423 -> V_163 ) ;
F_6 ( V_423 ) ;
break;
}
V_276:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_143 ( struct V_427 * V_428 ,
union V_429 * V_430 )
{
V_430 -> type = V_428 -> type ;
switch ( V_430 -> type ) {
case V_431 :
V_430 -> V_432 . V_433 = sizeof( struct V_434 ) ;
if ( V_430 -> V_432 . V_433 != V_428 -> V_432 . V_433 )
return - V_65 ;
memcpy ( & V_430 -> V_432 . V_435 , & V_428 -> V_432 . V_435 ,
sizeof( struct V_436 ) ) ;
memcpy ( & V_430 -> V_432 . V_366 , & V_428 -> V_432 . V_366 ,
sizeof( struct V_436 ) ) ;
break;
case V_437 :
V_430 -> V_438 . V_433 = sizeof( struct V_439 ) ;
if ( V_430 -> V_438 . V_433 != V_428 -> V_438 . V_433 )
return - V_65 ;
memcpy ( & V_430 -> V_438 . V_435 , & V_428 -> V_438 . V_435 ,
sizeof( struct V_440 ) ) ;
memcpy ( & V_430 -> V_438 . V_366 , & V_428 -> V_438 . V_366 ,
sizeof( struct V_440 ) ) ;
break;
case V_441 :
case V_442 :
V_430 -> V_443 . V_433 = sizeof( struct V_444 ) ;
if ( V_430 -> V_443 . V_433 != V_428 -> V_443 . V_433 )
return - V_65 ;
memcpy ( & V_430 -> V_443 . V_435 , & V_428 -> V_443 . V_435 ,
sizeof( struct V_445 ) ) ;
memcpy ( & V_430 -> V_443 . V_366 , & V_428 -> V_443 . V_366 ,
sizeof( struct V_445 ) ) ;
break;
default:
return - V_65 ;
}
return 0 ;
}
T_2 F_144 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_144 V_52 ;
struct V_446 V_54 ;
struct V_1 * V_2 ;
struct V_447 * V_448 ;
struct V_449 * V_450 ;
struct V_451 * V_452 ;
struct V_36 * V_39 ;
int V_66 = 0 ;
void * V_428 ;
void * V_430 ;
int V_383 ;
int V_453 ;
if ( V_51 < sizeof( V_54 ) )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_64 ;
if ( V_52 . V_454 )
return - V_65 ;
if ( ( V_52 . V_452 . type == V_455 &&
! F_114 ( V_456 ) ) || ! F_114 ( V_290 ) )
return - V_291 ;
if ( V_52 . V_452 . V_457 < 0 ||
V_52 . V_452 . V_457 > V_458 )
return - V_65 ;
V_453 = V_52 . V_452 . V_433 - sizeof( V_52 ) -
sizeof( struct V_459 ) ;
if ( V_52 . V_452 . V_433 < 0 || V_52 . V_452 . V_433 > V_50 ||
V_453 < 0 || V_453 >
( V_52 . V_452 . V_457 * sizeof( struct V_427 ) ) )
return - V_65 ;
if ( V_52 . V_452 . V_457 ) {
V_450 = F_67 ( V_52 . V_452 . V_433 , V_16 ) ;
if ( ! V_450 )
return - V_157 ;
memcpy ( V_450 , & V_52 . V_452 , sizeof( * V_450 ) ) ;
if ( F_46 ( V_450 + 1 , V_49 + sizeof( V_52 ) ,
V_453 ) ) {
V_66 = - V_64 ;
goto V_460;
}
} else {
V_450 = & V_52 . V_452 ;
V_453 = sizeof( V_52 . V_452 ) ;
}
V_2 = F_67 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 ) {
V_66 = - V_157 ;
goto V_460;
}
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_461 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_66 = - V_65 ;
goto V_462;
}
V_452 = F_67 ( V_52 . V_452 . V_433 , V_16 ) ;
if ( ! V_452 ) {
V_66 = - V_157 ;
goto V_213;
}
V_452 -> type = V_450 -> type ;
V_452 -> V_463 = V_450 -> V_463 ;
V_452 -> V_457 = V_450 -> V_457 ;
V_452 -> V_464 = V_450 -> V_464 ;
V_452 -> V_465 = V_450 -> V_465 ;
V_452 -> V_433 = sizeof( * V_452 ) ;
V_428 = V_450 + 1 ;
V_430 = V_452 + 1 ;
for ( V_383 = 0 ; V_383 < V_452 -> V_457 && V_453 > 0 ; V_383 ++ ) {
V_66 = F_143 ( V_428 , V_430 ) ;
if ( V_66 )
goto V_81;
V_452 -> V_433 +=
( (union V_429 * ) V_430 ) -> V_433 ;
V_453 -= ( (struct V_427 * ) V_428 ) -> V_433 ;
V_428 += ( (struct V_427 * ) V_428 ) -> V_433 ;
V_430 += ( (union V_429 * ) V_430 ) -> V_433 ;
}
if ( V_453 ) {
F_145 ( L_1 ,
V_453 ) ;
goto V_81;
}
V_448 = F_146 ( V_39 , V_452 , V_466 ) ;
if ( F_49 ( V_448 ) ) {
V_66 = F_50 ( V_448 ) ;
goto V_81;
}
V_448 -> V_39 = V_39 ;
V_448 -> V_27 = V_2 ;
V_2 -> V_22 = V_448 ;
V_66 = F_14 ( & V_467 , V_2 ) ;
if ( V_66 )
goto V_468;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_469 = V_2 -> V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof( V_54 ) ) ) {
V_66 = - V_64 ;
goto V_162;
}
F_39 ( V_39 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_163 , & V_48 -> V_61 -> V_77 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_6 ( V_452 ) ;
if ( V_52 . V_452 . V_457 )
F_6 ( V_450 ) ;
return V_50 ;
V_162:
F_20 ( & V_467 , V_2 ) ;
V_468:
F_147 ( V_448 ) ;
V_81:
F_6 ( V_452 ) ;
V_213:
F_39 ( V_39 ) ;
V_462:
F_12 ( V_2 ) ;
V_460:
if ( V_52 . V_452 . V_457 )
F_6 ( V_450 ) ;
return V_66 ;
}
T_2 F_148 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 ) {
struct F_148 V_52 ;
struct V_447 * V_448 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_64 ;
V_2 = F_28 ( & V_467 , V_52 . V_469 ,
V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_448 = V_2 -> V_22 ;
V_15 = F_147 ( V_448 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_467 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_149 ( struct V_47 * V_48 ,
struct V_470 * V_52 ,
struct V_55 * V_56 )
{
struct V_471 V_54 ;
struct V_472 * V_181 ;
struct V_23 * V_26 ;
struct V_40 * V_43 ;
struct V_1 * V_283 ( V_284 ) ;
struct V_473 V_92 ;
int V_15 ;
V_181 = F_67 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 )
return - V_157 ;
F_1 ( & V_181 -> V_292 . V_27 , V_52 -> V_3 , V_48 -> V_61 , & V_474 ) ;
F_29 ( & V_181 -> V_292 . V_27 . V_9 ) ;
if ( V_52 -> V_299 == V_475 ) {
V_92 . V_476 . V_477 . V_167 = F_43 ( V_52 -> V_45 , V_48 -> V_61 , & V_284 ) ;
if ( ! V_92 . V_476 . V_477 . V_167 ) {
V_15 = - V_65 ;
goto V_66;
}
V_181 -> V_323 = F_7 ( V_284 , struct V_180 , V_27 ) ;
F_87 ( & V_181 -> V_323 -> V_196 ) ;
V_92 . V_476 . V_477 . V_31 = F_33 ( V_52 -> V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_92 . V_476 . V_477 . V_31 ) {
V_15 = - V_65 ;
goto V_478;
}
}
V_26 = F_31 ( V_52 -> V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_479;
}
V_92 . V_87 = V_480 ;
V_92 . V_481 = V_48 ;
V_92 . V_299 = V_52 -> V_299 ;
V_92 . V_92 . V_482 = V_52 -> V_482 ;
V_92 . V_92 . V_104 = V_52 -> V_104 ;
V_92 . V_92 . V_483 = V_52 -> V_483 ;
V_181 -> V_292 . V_316 = 0 ;
F_51 ( & V_181 -> V_292 . V_317 ) ;
V_43 = V_26 -> V_59 -> V_484 ( V_26 , & V_92 , V_56 ) ;
if ( F_49 ( V_43 ) ) {
V_15 = F_50 ( V_43 ) ;
goto V_213;
}
V_43 -> V_59 = V_26 -> V_59 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_299 = V_52 -> V_299 ;
V_43 -> V_27 = & V_181 -> V_292 . V_27 ;
V_43 -> V_87 = V_92 . V_87 ;
V_43 -> V_481 = V_92 . V_481 ;
if ( V_52 -> V_299 == V_475 ) {
V_43 -> V_476 . V_477 . V_31 = V_92 . V_476 . V_477 . V_31 ;
V_43 -> V_476 . V_477 . V_167 = V_92 . V_476 . V_477 . V_167 ;
F_87 ( & V_92 . V_476 . V_477 . V_31 -> V_160 ) ;
F_87 ( & V_92 . V_476 . V_477 . V_167 -> V_160 ) ;
}
F_87 ( & V_26 -> V_160 ) ;
F_68 ( & V_43 -> V_160 , 0 ) ;
V_181 -> V_292 . V_27 . V_22 = V_43 ;
V_15 = F_14 ( & V_42 , & V_181 -> V_292 . V_27 ) ;
if ( V_15 )
goto V_321;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_41 = V_181 -> V_292 . V_27 . V_19 ;
V_54 . V_482 = V_92 . V_92 . V_482 ;
V_54 . V_104 = V_92 . V_92 . V_104 ;
if ( V_52 -> V_299 == V_475 )
V_54 . V_485 = V_43 -> V_476 . V_477 . V_486 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 -> V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_162;
}
if ( V_52 -> V_299 == V_475 ) {
F_10 ( V_284 ) ;
F_34 ( V_92 . V_476 . V_477 . V_31 ) ;
}
F_32 ( V_26 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_181 -> V_292 . V_27 . V_163 , & V_48 -> V_61 -> V_74 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_181 -> V_292 . V_27 . V_12 = 1 ;
F_13 ( & V_181 -> V_292 . V_27 . V_9 ) ;
return 0 ;
V_162:
F_20 ( & V_42 , & V_181 -> V_292 . V_27 ) ;
V_321:
F_150 ( V_43 ) ;
V_213:
F_32 ( V_26 ) ;
V_479:
if ( V_52 -> V_299 == V_475 )
F_34 ( V_92 . V_476 . V_477 . V_31 ) ;
V_478:
if ( V_52 -> V_299 == V_475 ) {
F_89 ( & V_181 -> V_323 -> V_196 ) ;
F_10 ( V_284 ) ;
}
V_66:
F_12 ( & V_181 -> V_292 . V_27 ) ;
return V_15 ;
}
T_2 F_151 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_151 V_52 ;
struct V_470 V_487 ;
struct V_471 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_487 . V_67 = V_52 . V_67 ;
V_487 . V_3 = V_52 . V_3 ;
V_487 . V_299 = V_300 ;
V_487 . V_24 = V_52 . V_24 ;
V_487 . V_482 = V_52 . V_482 ;
V_487 . V_104 = V_52 . V_104 ;
V_487 . V_483 = V_52 . V_483 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_149 ( V_48 , & V_487 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 V_470 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct V_470 V_52 ;
struct V_471 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_149 ( V_48 , & V_52 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 F_152 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_152 V_52 ;
struct V_55 V_56 ;
struct V_40 * V_43 ;
struct V_488 V_92 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 , NULL , V_50 - sizeof V_52 ,
V_51 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
return - V_65 ;
V_92 . V_482 = V_52 . V_482 ;
V_92 . V_483 = V_52 . V_483 ;
V_15 = V_43 -> V_59 -> V_489 ( V_43 , & V_92 , V_52 . V_329 , & V_56 ) ;
F_42 ( V_43 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_153 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_153 V_52 ;
struct V_490 V_54 ;
struct V_488 V_92 ;
struct V_40 * V_43 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
return - V_65 ;
V_15 = F_154 ( V_43 , & V_92 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_482 = V_92 . V_482 ;
V_54 . V_104 = V_92 . V_104 ;
V_54 . V_483 = V_92 . V_483 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_155 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_155 V_52 ;
struct V_491 V_54 ;
struct V_1 * V_2 ;
struct V_40 * V_43 ;
struct V_492 * V_181 ;
int V_15 = - V_65 ;
struct V_472 * V_493 ;
enum V_494 V_299 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_42 , V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_43 = V_2 -> V_22 ;
V_181 = F_7 ( V_2 , struct V_492 , V_27 ) ;
V_299 = V_43 -> V_299 ;
V_15 = F_150 ( V_43 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_299 == V_475 ) {
V_493 = F_7 ( V_181 , struct V_472 , V_292 ) ;
F_89 ( & V_493 -> V_323 -> V_196 ) ;
}
F_20 ( & V_42 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_127 ( V_48 , V_181 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_316 = V_181 -> V_316 ;
F_8 ( V_2 ) ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
return V_15 ? V_15 : V_50 ;
}
