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
V_15 = F_96 ( V_52 . V_206 ) ;
if ( V_15 )
return V_15 ;
V_2 = F_67 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_157 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_207 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_81;
}
V_202 = V_26 -> V_59 -> V_208 ( V_26 , V_52 . V_203 , V_52 . V_209 , V_52 . V_205 ,
V_52 . V_206 , & V_56 ) ;
if ( F_49 ( V_202 ) ) {
V_15 = F_50 ( V_202 ) ;
goto V_210;
}
V_202 -> V_59 = V_26 -> V_59 ;
V_202 -> V_26 = V_26 ;
V_202 -> V_27 = V_2 ;
F_87 ( & V_26 -> V_160 ) ;
F_68 ( & V_202 -> V_160 , 0 ) ;
V_2 -> V_22 = V_202 ;
V_15 = F_14 ( & V_211 , V_2 ) ;
if ( V_15 )
goto V_212;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_213 = V_202 -> V_213 ;
V_54 . V_214 = V_202 -> V_214 ;
V_54 . V_215 = V_2 -> V_19 ;
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
F_20 ( & V_211 , V_2 ) ;
V_212:
F_97 ( V_202 ) ;
V_210:
F_32 ( V_26 ) ;
V_81:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_98 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_98 V_52 ;
struct V_216 V_54 ;
struct V_55 V_56 ;
struct V_23 * V_26 = NULL ;
struct V_201 * V_202 ;
struct V_23 * V_217 ;
int V_15 ;
struct V_1 * V_2 ;
if ( V_51 < sizeof( V_54 ) )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof( V_52 ) ,
( unsigned long ) V_52 . V_67 + sizeof( V_54 ) ,
V_50 - sizeof( V_52 ) , V_51 - sizeof( V_54 ) ) ;
if ( V_52 . V_218 & ~ V_219 || ! V_52 . V_218 )
return - V_65 ;
if ( ( V_52 . V_218 & V_220 ) &&
( ! V_52 . V_203 || ! V_52 . V_205 || 0 >= V_52 . V_209 ||
( V_52 . V_203 & ~ V_204 ) != ( V_52 . V_205 & ~ V_204 ) ) )
return - V_65 ;
V_2 = F_28 ( & V_211 , V_52 . V_215 ,
V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_202 = V_2 -> V_22 ;
if ( V_52 . V_218 & V_221 ) {
V_15 = F_96 ( V_52 . V_206 ) ;
if ( V_15 )
goto V_222;
}
if ( V_52 . V_218 & V_223 ) {
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_222;
}
}
if ( F_92 ( & V_202 -> V_160 ) ) {
V_15 = - V_199 ;
goto V_224;
}
V_217 = V_202 -> V_26 ;
V_15 = V_202 -> V_59 -> V_225 ( V_202 , V_52 . V_218 , V_52 . V_203 ,
V_52 . V_209 , V_52 . V_205 ,
V_52 . V_206 , V_26 , & V_56 ) ;
if ( ! V_15 ) {
if ( V_52 . V_218 & V_223 ) {
F_87 ( & V_26 -> V_160 ) ;
V_202 -> V_26 = V_26 ;
F_89 ( & V_217 -> V_160 ) ;
}
} else {
goto V_224;
}
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_213 = V_202 -> V_213 ;
V_54 . V_214 = V_202 -> V_214 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof( V_54 ) ) )
V_15 = - V_64 ;
else
V_15 = V_50 ;
V_224:
if ( V_52 . V_218 & V_223 )
F_32 ( V_26 ) ;
V_222:
F_12 ( V_202 -> V_27 ) ;
return V_15 ;
}
T_2 F_99 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_99 V_52 ;
struct V_201 * V_202 ;
struct V_1 * V_2 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_211 , V_52 . V_215 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_202 = V_2 -> V_22 ;
V_15 = F_97 ( V_202 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_211 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_100 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_100 V_52 ;
struct V_226 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_227 * V_228 ;
int V_15 ;
if ( V_51 < sizeof( V_54 ) )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_64 ;
V_2 = F_67 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return - V_157 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_229 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_81;
}
V_228 = V_26 -> V_59 -> V_230 ( V_26 , V_52 . V_231 ) ;
if ( F_49 ( V_228 ) ) {
V_15 = F_50 ( V_228 ) ;
goto V_210;
}
V_228 -> V_59 = V_26 -> V_59 ;
V_228 -> V_26 = V_26 ;
V_228 -> V_27 = V_2 ;
F_87 ( & V_26 -> V_160 ) ;
V_2 -> V_22 = V_228 ;
V_15 = F_14 ( & V_232 , V_2 ) ;
if ( V_15 )
goto V_233;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_214 = V_228 -> V_214 ;
V_54 . V_234 = V_2 -> V_19 ;
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
F_20 ( & V_232 , V_2 ) ;
V_233:
F_101 ( V_228 ) ;
V_210:
F_32 ( V_26 ) ;
V_81:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_102 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_102 V_52 ;
struct V_227 * V_228 ;
struct V_1 * V_2 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_64 ;
V_2 = F_28 ( & V_232 , V_52 . V_234 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_228 = V_2 -> V_22 ;
V_15 = F_101 ( V_228 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_232 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_103 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_103 V_52 ;
struct V_235 V_54 ;
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
T_2 F_104 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_104 V_52 ;
struct V_236 V_54 ;
struct V_55 V_56 ;
struct V_237 * V_181 ;
struct V_238 * V_239 = NULL ;
struct V_28 * V_31 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
if ( V_52 . V_240 >= V_48 -> V_59 -> V_79 )
return - V_65 ;
V_181 = F_67 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 )
return - V_157 ;
F_1 ( & V_181 -> V_27 , V_52 . V_3 , V_48 -> V_61 , & V_241 ) ;
F_29 ( & V_181 -> V_27 . V_9 ) ;
if ( V_52 . V_242 >= 0 ) {
V_239 = F_105 ( V_52 . V_242 ) ;
if ( ! V_239 ) {
V_15 = - V_65 ;
goto V_66;
}
}
V_181 -> V_243 = V_48 ;
V_181 -> V_244 = 0 ;
V_181 -> V_245 = 0 ;
F_51 ( & V_181 -> V_246 ) ;
F_51 ( & V_181 -> V_247 ) ;
V_31 = V_48 -> V_59 -> V_60 -> V_248 ( V_48 -> V_59 -> V_60 , V_52 . V_249 ,
V_52 . V_240 ,
V_48 -> V_61 , & V_56 ) ;
if ( F_49 ( V_31 ) ) {
V_15 = F_50 ( V_31 ) ;
goto V_84;
}
V_31 -> V_59 = V_48 -> V_59 -> V_60 ;
V_31 -> V_27 = & V_181 -> V_27 ;
V_31 -> V_250 = V_251 ;
V_31 -> V_87 = V_252 ;
V_31 -> V_253 = V_239 ;
F_68 ( & V_31 -> V_160 , 0 ) ;
V_181 -> V_27 . V_22 = V_31 ;
V_15 = F_14 ( & V_30 , & V_181 -> V_27 ) ;
if ( V_15 )
goto V_81;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_29 = V_181 -> V_27 . V_19 ;
V_54 . V_249 = V_31 -> V_249 ;
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
F_106 ( V_31 ) ;
V_84:
if ( V_239 )
F_107 ( V_48 , V_239 , V_181 ) ;
V_66:
F_12 ( & V_181 -> V_27 ) ;
return V_15 ;
}
T_2 F_108 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_108 V_52 ;
struct V_254 V_54 ;
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
V_15 = V_31 -> V_59 -> V_255 ( V_31 , V_52 . V_249 , & V_56 ) ;
if ( V_15 )
goto V_198;
V_54 . V_249 = V_31 -> V_249 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 . V_249 ) )
V_15 = - V_64 ;
V_198:
F_34 ( V_31 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_109 ( void T_3 * V_256 , struct V_257 * V_258 )
{
struct V_259 V_260 ;
V_260 . V_261 = V_258 -> V_261 ;
V_260 . V_262 = V_258 -> V_262 ;
V_260 . V_263 = V_258 -> V_263 ;
V_260 . V_264 = V_258 -> V_264 ;
V_260 . V_265 = V_258 -> V_265 ;
V_260 . V_266 . V_267 = ( V_268 V_269 ) V_258 -> V_266 . V_267 ;
V_260 . V_270 = V_258 -> V_39 -> V_270 ;
V_260 . V_271 = V_258 -> V_271 ;
V_260 . V_272 = V_258 -> V_272 ;
V_260 . V_273 = V_258 -> V_273 ;
V_260 . V_274 = V_258 -> V_274 ;
V_260 . V_275 = V_258 -> V_275 ;
V_260 . V_276 = V_258 -> V_276 ;
V_260 . V_135 = V_258 -> V_135 ;
V_260 . V_277 = 0 ;
if ( F_54 ( V_256 , & V_260 , sizeof V_260 ) )
return - V_64 ;
return 0 ;
}
T_2 F_110 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_110 V_52 ;
struct V_278 V_54 ;
T_4 T_3 * V_279 ;
T_4 T_3 * V_280 ;
struct V_28 * V_31 ;
struct V_257 V_258 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_31 )
return - V_65 ;
V_279 = ( void T_3 * ) ( unsigned long ) V_52 . V_67 ;
V_280 = V_279 + sizeof V_54 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
while ( V_54 . V_281 < V_52 . V_282 ) {
V_15 = F_111 ( V_31 , 1 , & V_258 ) ;
if ( V_15 < 0 )
goto V_283;
if ( ! V_15 )
break;
V_15 = F_109 ( V_280 , & V_258 ) ;
if ( V_15 )
goto V_283;
V_280 += sizeof( struct V_259 ) ;
++ V_54 . V_281 ;
}
if ( F_54 ( V_279 , & V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_283;
}
V_15 = V_50 ;
V_283:
F_34 ( V_31 ) ;
return V_15 ;
}
T_2 F_112 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_112 V_52 ;
struct V_28 * V_31 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_31 )
return - V_65 ;
F_113 ( V_31 , V_52 . V_284 ?
V_285 : V_286 ) ;
F_34 ( V_31 ) ;
return V_50 ;
}
T_2 F_114 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_114 V_52 ;
struct V_287 V_54 ;
struct V_1 * V_2 ;
struct V_28 * V_31 ;
struct V_237 * V_181 ;
struct V_238 * V_239 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_30 , V_52 . V_29 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_31 = V_2 -> V_22 ;
V_239 = V_31 -> V_253 ;
V_181 = F_7 ( V_31 -> V_27 , struct V_237 , V_27 ) ;
V_15 = F_106 ( V_31 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_30 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_107 ( V_48 , V_239 , V_181 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_244 = V_181 -> V_244 ;
V_54 . V_245 = V_181 -> V_245 ;
F_8 ( V_2 ) ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_115 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_115 V_52 ;
struct V_288 V_54 ;
struct V_55 V_56 ;
struct V_289 * V_181 ;
struct V_57 * V_59 ;
struct V_23 * V_26 = NULL ;
struct V_44 * V_167 = NULL ;
struct V_1 * V_290 ( V_291 ) ;
struct V_28 * V_292 = NULL , * V_293 = NULL ;
struct V_40 * V_43 = NULL ;
struct V_36 * V_39 ;
struct V_294 V_92 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
if ( V_52 . V_295 == V_296 && ! F_116 ( V_297 ) )
return - V_298 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_181 = F_117 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 )
return - V_157 ;
F_1 ( & V_181 -> V_299 . V_27 , V_52 . V_3 , V_48 -> V_61 , & V_300 ) ;
F_29 ( & V_181 -> V_299 . V_27 . V_9 ) ;
if ( V_52 . V_295 == V_301 ) {
V_167 = F_43 ( V_52 . V_24 , V_48 -> V_61 , & V_291 ) ;
if ( ! V_167 ) {
V_15 = - V_65 ;
goto V_210;
}
V_59 = V_167 -> V_59 ;
} else {
if ( V_52 . V_295 == V_302 ) {
V_52 . V_303 = V_52 . V_304 = 0 ;
} else {
if ( V_52 . V_305 ) {
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 || V_43 -> V_306 != V_307 ) {
V_15 = - V_65 ;
goto V_210;
}
}
if ( V_52 . V_308 != V_52 . V_309 ) {
V_293 = F_33 ( V_52 . V_308 , V_48 -> V_61 , 0 ) ;
if ( ! V_293 ) {
V_15 = - V_65 ;
goto V_210;
}
}
}
V_292 = F_33 ( V_52 . V_309 , V_48 -> V_61 , ! ! V_293 ) ;
V_293 = V_293 ? : V_292 ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 || ! V_292 ) {
V_15 = - V_65 ;
goto V_210;
}
V_59 = V_26 -> V_59 ;
}
V_92 . V_87 = V_310 ;
V_92 . V_311 = V_48 ;
V_92 . V_312 = V_292 ;
V_92 . V_313 = V_293 ;
V_92 . V_43 = V_43 ;
V_92 . V_167 = V_167 ;
V_92 . V_314 = V_52 . V_315 ? V_316 : V_317 ;
V_92 . V_295 = V_52 . V_295 ;
V_92 . V_318 = 0 ;
V_92 . V_319 . V_320 = V_52 . V_320 ;
V_92 . V_319 . V_303 = V_52 . V_303 ;
V_92 . V_319 . V_321 = V_52 . V_321 ;
V_92 . V_319 . V_304 = V_52 . V_304 ;
V_92 . V_319 . V_322 = V_52 . V_322 ;
V_181 -> V_299 . V_323 = 0 ;
F_51 ( & V_181 -> V_299 . V_324 ) ;
F_51 ( & V_181 -> V_325 ) ;
if ( V_52 . V_295 == V_301 )
V_39 = F_118 ( V_26 , & V_92 ) ;
else
V_39 = V_59 -> V_326 ( V_26 , & V_92 , & V_56 ) ;
if ( F_49 ( V_39 ) ) {
V_15 = F_50 ( V_39 ) ;
goto V_210;
}
if ( V_52 . V_295 != V_301 ) {
V_39 -> V_327 = V_39 ;
V_39 -> V_59 = V_59 ;
V_39 -> V_26 = V_26 ;
V_39 -> V_312 = V_92 . V_312 ;
V_39 -> V_313 = V_92 . V_313 ;
V_39 -> V_43 = V_92 . V_43 ;
V_39 -> V_87 = V_92 . V_87 ;
V_39 -> V_311 = V_92 . V_311 ;
V_39 -> V_295 = V_92 . V_295 ;
F_68 ( & V_39 -> V_160 , 0 ) ;
F_87 ( & V_26 -> V_160 ) ;
F_87 ( & V_92 . V_312 -> V_160 ) ;
if ( V_92 . V_313 )
F_87 ( & V_92 . V_313 -> V_160 ) ;
if ( V_92 . V_43 )
F_87 ( & V_92 . V_43 -> V_160 ) ;
}
V_39 -> V_27 = & V_181 -> V_299 . V_27 ;
V_181 -> V_299 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_181 -> V_299 . V_27 ) ;
if ( V_15 )
goto V_328;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_329 = V_39 -> V_270 ;
V_54 . V_37 = V_181 -> V_299 . V_27 . V_19 ;
V_54 . V_304 = V_92 . V_319 . V_304 ;
V_54 . V_321 = V_92 . V_319 . V_321 ;
V_54 . V_303 = V_92 . V_319 . V_303 ;
V_54 . V_320 = V_92 . V_319 . V_320 ;
V_54 . V_322 = V_92 . V_319 . V_322 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_162;
}
if ( V_167 ) {
V_181 -> V_330 = F_7 ( V_291 , struct V_180 ,
V_27 ) ;
F_87 ( & V_181 -> V_330 -> V_196 ) ;
F_44 ( V_291 ) ;
}
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_292 )
F_34 ( V_292 ) ;
if ( V_293 && V_293 != V_292 )
F_34 ( V_293 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_181 -> V_299 . V_27 . V_163 , & V_48 -> V_61 -> V_73 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_181 -> V_299 . V_27 . V_12 = 1 ;
F_13 ( & V_181 -> V_299 . V_27 . V_9 ) ;
return V_50 ;
V_162:
F_20 ( & V_38 , & V_181 -> V_299 . V_27 ) ;
V_328:
F_119 ( V_39 ) ;
V_210:
if ( V_167 )
F_44 ( V_291 ) ;
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_292 )
F_34 ( V_292 ) ;
if ( V_293 && V_293 != V_292 )
F_34 ( V_293 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_12 ( & V_181 -> V_299 . V_27 ) ;
return V_15 ;
}
T_2 F_120 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_120 V_52 ;
struct V_288 V_54 ;
struct V_55 V_56 ;
struct V_289 * V_181 ;
struct V_44 * V_167 ;
struct V_1 * V_290 ( V_291 ) ;
struct V_36 * V_39 ;
struct V_331 V_92 ;
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
F_1 ( & V_181 -> V_299 . V_27 , V_52 . V_3 , V_48 -> V_61 , & V_300 ) ;
F_29 ( & V_181 -> V_299 . V_27 . V_9 ) ;
V_167 = F_43 ( V_52 . V_24 , V_48 -> V_61 , & V_291 ) ;
if ( ! V_167 ) {
V_15 = - V_65 ;
goto V_210;
}
V_92 . V_87 = V_310 ;
V_92 . V_311 = V_48 ;
V_92 . V_270 = V_52 . V_329 ;
V_92 . V_295 = V_52 . V_295 ;
V_181 -> V_299 . V_323 = 0 ;
F_51 ( & V_181 -> V_299 . V_324 ) ;
F_51 ( & V_181 -> V_325 ) ;
V_39 = F_121 ( V_167 , & V_92 ) ;
if ( F_49 ( V_39 ) ) {
V_15 = F_50 ( V_39 ) ;
goto V_210;
}
V_39 -> V_27 = & V_181 -> V_299 . V_27 ;
V_181 -> V_299 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_181 -> V_299 . V_27 ) ;
if ( V_15 )
goto V_328;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_329 = V_39 -> V_270 ;
V_54 . V_37 = V_181 -> V_299 . V_27 . V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_332;
}
V_181 -> V_330 = F_7 ( V_291 , struct V_180 , V_27 ) ;
F_87 ( & V_181 -> V_330 -> V_196 ) ;
F_44 ( V_291 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_181 -> V_299 . V_27 . V_163 , & V_48 -> V_61 -> V_73 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_181 -> V_299 . V_27 . V_12 = 1 ;
F_13 ( & V_181 -> V_299 . V_27 . V_9 ) ;
return V_50 ;
V_332:
F_20 ( & V_38 , & V_181 -> V_299 . V_27 ) ;
V_328:
F_119 ( V_39 ) ;
V_210:
F_44 ( V_291 ) ;
F_12 ( & V_181 -> V_299 . V_27 ) ;
return V_15 ;
}
T_2 F_122 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_122 V_52 ;
struct V_333 V_54 ;
struct V_36 * V_39 ;
struct V_334 * V_92 ;
struct V_294 * V_335 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_92 = F_67 ( sizeof *V_92 , V_16 ) ;
V_335 = F_67 ( sizeof *V_335 , V_16 ) ;
if ( ! V_92 || ! V_335 ) {
V_15 = - V_157 ;
goto V_198;
}
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_15 = - V_65 ;
goto V_198;
}
V_15 = F_123 ( V_39 , V_92 , V_52 . V_336 , V_335 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
goto V_198;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_337 = V_92 -> V_337 ;
V_54 . V_338 = V_92 -> V_338 ;
V_54 . V_339 = V_92 -> V_339 ;
V_54 . V_340 = V_92 -> V_340 ;
V_54 . V_341 = V_92 -> V_341 ;
V_54 . V_342 = V_92 -> V_342 ;
V_54 . V_343 = V_92 -> V_343 ;
V_54 . V_344 = V_92 -> V_344 ;
V_54 . V_345 = V_92 -> V_345 ;
V_54 . V_273 = V_92 -> V_273 ;
V_54 . V_346 = V_92 -> V_346 ;
V_54 . V_347 = V_92 -> V_347 ;
V_54 . V_348 = V_92 -> V_348 ;
V_54 . V_349 = V_92 -> V_349 ;
V_54 . V_350 = V_92 -> V_350 ;
V_54 . V_135 = V_92 -> V_135 ;
V_54 . V_351 = V_92 -> V_351 ;
V_54 . V_352 = V_92 -> V_352 ;
V_54 . V_353 = V_92 -> V_353 ;
V_54 . V_354 = V_92 -> V_354 ;
V_54 . V_355 = V_92 -> V_355 ;
memcpy ( V_54 . V_256 . V_356 , V_92 -> V_357 . V_358 . V_356 . V_359 , 16 ) ;
V_54 . V_256 . V_360 = V_92 -> V_357 . V_358 . V_360 ;
V_54 . V_256 . V_361 = V_92 -> V_357 . V_358 . V_361 ;
V_54 . V_256 . V_362 = V_92 -> V_357 . V_358 . V_362 ;
V_54 . V_256 . V_363 = V_92 -> V_357 . V_358 . V_363 ;
V_54 . V_256 . V_364 = V_92 -> V_357 . V_364 ;
V_54 . V_256 . V_275 = V_92 -> V_357 . V_275 ;
V_54 . V_256 . V_365 = V_92 -> V_357 . V_365 ;
V_54 . V_256 . V_366 = V_92 -> V_357 . V_366 ;
V_54 . V_256 . V_367 = ! ! ( V_92 -> V_357 . V_368 & V_369 ) ;
V_54 . V_256 . V_135 = V_92 -> V_357 . V_135 ;
memcpy ( V_54 . V_370 . V_356 , V_92 -> V_371 . V_358 . V_356 . V_359 , 16 ) ;
V_54 . V_370 . V_360 = V_92 -> V_371 . V_358 . V_360 ;
V_54 . V_370 . V_361 = V_92 -> V_371 . V_358 . V_361 ;
V_54 . V_370 . V_362 = V_92 -> V_371 . V_358 . V_362 ;
V_54 . V_370 . V_363 = V_92 -> V_371 . V_358 . V_363 ;
V_54 . V_370 . V_364 = V_92 -> V_371 . V_364 ;
V_54 . V_370 . V_275 = V_92 -> V_371 . V_275 ;
V_54 . V_370 . V_365 = V_92 -> V_371 . V_365 ;
V_54 . V_370 . V_366 = V_92 -> V_371 . V_366 ;
V_54 . V_370 . V_367 = ! ! ( V_92 -> V_371 . V_368 & V_369 ) ;
V_54 . V_370 . V_135 = V_92 -> V_371 . V_135 ;
V_54 . V_320 = V_335 -> V_319 . V_320 ;
V_54 . V_303 = V_335 -> V_319 . V_303 ;
V_54 . V_321 = V_335 -> V_319 . V_321 ;
V_54 . V_304 = V_335 -> V_319 . V_304 ;
V_54 . V_322 = V_335 -> V_319 . V_322 ;
V_54 . V_315 = V_335 -> V_314 == V_316 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_198:
F_6 ( V_92 ) ;
F_6 ( V_335 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_124 ( enum V_372 V_295 , int V_373 )
{
switch ( V_295 ) {
case V_302 :
return V_373 & ~ ( V_374 | V_375 ) ;
case V_301 :
return V_373 & ~ ( V_376 | V_377 |
V_378 ) ;
default:
return V_373 ;
}
}
T_2 F_125 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_125 V_52 ;
struct V_55 V_56 ;
struct V_36 * V_39 ;
struct V_334 * V_92 ;
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
V_92 -> V_337 = V_52 . V_337 ;
V_92 -> V_338 = V_52 . V_338 ;
V_92 -> V_339 = V_52 . V_339 ;
V_92 -> V_340 = V_52 . V_340 ;
V_92 -> V_341 = V_52 . V_341 ;
V_92 -> V_342 = V_52 . V_342 ;
V_92 -> V_343 = V_52 . V_343 ;
V_92 -> V_344 = V_52 . V_344 ;
V_92 -> V_345 = V_52 . V_345 ;
V_92 -> V_273 = V_52 . V_273 ;
V_92 -> V_346 = V_52 . V_346 ;
V_92 -> V_379 = V_52 . V_379 ;
V_92 -> V_348 = V_52 . V_348 ;
V_92 -> V_349 = V_52 . V_349 ;
V_92 -> V_350 = V_52 . V_350 ;
V_92 -> V_135 = V_52 . V_135 ;
V_92 -> V_351 = V_52 . V_351 ;
V_92 -> V_352 = V_52 . V_352 ;
V_92 -> V_353 = V_52 . V_353 ;
V_92 -> V_354 = V_52 . V_354 ;
V_92 -> V_355 = V_52 . V_355 ;
memcpy ( V_92 -> V_357 . V_358 . V_356 . V_359 , V_52 . V_256 . V_356 , 16 ) ;
V_92 -> V_357 . V_358 . V_360 = V_52 . V_256 . V_360 ;
V_92 -> V_357 . V_358 . V_361 = V_52 . V_256 . V_361 ;
V_92 -> V_357 . V_358 . V_362 = V_52 . V_256 . V_362 ;
V_92 -> V_357 . V_358 . V_363 = V_52 . V_256 . V_363 ;
V_92 -> V_357 . V_364 = V_52 . V_256 . V_364 ;
V_92 -> V_357 . V_275 = V_52 . V_256 . V_275 ;
V_92 -> V_357 . V_365 = V_52 . V_256 . V_365 ;
V_92 -> V_357 . V_366 = V_52 . V_256 . V_366 ;
V_92 -> V_357 . V_368 = V_52 . V_256 . V_367 ? V_369 : 0 ;
V_92 -> V_357 . V_135 = V_52 . V_256 . V_135 ;
memcpy ( V_92 -> V_371 . V_358 . V_356 . V_359 , V_52 . V_370 . V_356 , 16 ) ;
V_92 -> V_371 . V_358 . V_360 = V_52 . V_370 . V_360 ;
V_92 -> V_371 . V_358 . V_361 = V_52 . V_370 . V_361 ;
V_92 -> V_371 . V_358 . V_362 = V_52 . V_370 . V_362 ;
V_92 -> V_371 . V_358 . V_363 = V_52 . V_370 . V_363 ;
V_92 -> V_371 . V_364 = V_52 . V_370 . V_364 ;
V_92 -> V_371 . V_275 = V_52 . V_370 . V_275 ;
V_92 -> V_371 . V_365 = V_52 . V_370 . V_365 ;
V_92 -> V_371 . V_366 = V_52 . V_370 . V_366 ;
V_92 -> V_371 . V_368 = V_52 . V_370 . V_367 ? V_369 : 0 ;
V_92 -> V_371 . V_135 = V_52 . V_370 . V_135 ;
if ( V_39 -> V_327 == V_39 ) {
V_15 = F_126 ( V_39 , V_92 , & V_52 . V_336 ) ;
if ( V_15 )
goto V_198;
V_15 = V_39 -> V_59 -> V_380 ( V_39 , V_92 ,
F_124 ( V_39 -> V_295 , V_52 . V_336 ) , & V_56 ) ;
} else {
V_15 = F_127 ( V_39 , V_92 , F_124 ( V_39 -> V_295 , V_52 . V_336 ) ) ;
}
F_39 ( V_39 ) ;
if ( V_15 )
goto V_198;
V_15 = V_50 ;
V_198:
F_6 ( V_92 ) ;
return V_15 ;
}
T_2 F_128 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_128 V_52 ;
struct V_381 V_54 ;
struct V_1 * V_2 ;
struct V_36 * V_39 ;
struct V_289 * V_181 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_2 = F_28 ( & V_38 , V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_39 = V_2 -> V_22 ;
V_181 = F_7 ( V_2 , struct V_289 , V_299 . V_27 ) ;
if ( ! F_129 ( & V_181 -> V_325 ) ) {
F_12 ( V_2 ) ;
return - V_199 ;
}
V_15 = F_119 ( V_39 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_181 -> V_330 )
F_89 ( & V_181 -> V_330 -> V_196 ) ;
F_20 ( & V_38 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_130 ( V_48 , & V_181 -> V_299 ) ;
V_54 . V_323 = V_181 -> V_299 . V_323 ;
F_8 ( V_2 ) ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_131 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_131 V_52 ;
struct V_382 V_54 ;
struct V_383 * V_384 ;
struct V_385 * V_386 = NULL , * V_387 , * V_388 , * V_389 ;
struct V_36 * V_39 ;
int V_390 , V_391 ;
int V_392 ;
T_2 V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
if ( V_50 < sizeof V_52 + V_52 . V_393 * V_52 . V_394 +
V_52 . V_395 * sizeof ( struct V_396 ) )
return - V_65 ;
if ( V_52 . V_393 < sizeof ( struct V_383 ) )
return - V_65 ;
V_384 = F_67 ( V_52 . V_393 , V_16 ) ;
if ( ! V_384 )
return - V_157 ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
goto V_198;
V_392 = V_39 -> V_295 == V_397 ;
V_391 = 0 ;
V_387 = NULL ;
for ( V_390 = 0 ; V_390 < V_52 . V_394 ; ++ V_390 ) {
if ( F_46 ( V_384 ,
V_49 + sizeof V_52 + V_390 * V_52 . V_393 ,
V_52 . V_393 ) ) {
V_15 = - V_64 ;
goto V_283;
}
if ( V_384 -> V_398 + V_391 > V_52 . V_395 ) {
V_15 = - V_65 ;
goto V_283;
}
V_388 = F_67 ( F_132 ( sizeof *V_388 , sizeof ( struct V_399 ) ) +
V_384 -> V_398 * sizeof ( struct V_399 ) ,
V_16 ) ;
if ( ! V_388 ) {
V_15 = - V_157 ;
goto V_283;
}
if ( ! V_387 )
V_386 = V_388 ;
else
V_387 -> V_388 = V_388 ;
V_387 = V_388 ;
V_388 -> V_388 = NULL ;
V_388 -> V_261 = V_384 -> V_261 ;
V_388 -> V_398 = V_384 -> V_398 ;
V_388 -> V_263 = V_384 -> V_263 ;
V_388 -> V_400 = V_384 -> V_400 ;
if ( V_392 ) {
V_388 -> V_386 . V_401 . V_35 = F_35 ( V_384 -> V_386 . V_401 . V_35 ,
V_48 -> V_61 ) ;
if ( ! V_388 -> V_386 . V_401 . V_35 ) {
V_15 = - V_65 ;
goto V_283;
}
V_388 -> V_386 . V_401 . V_402 = V_384 -> V_386 . V_401 . V_402 ;
V_388 -> V_386 . V_401 . V_403 = V_384 -> V_386 . V_401 . V_403 ;
if ( V_388 -> V_263 == V_404 )
V_388 -> V_266 . V_267 =
( V_405 V_269 ) V_384 -> V_266 . V_267 ;
} else {
switch ( V_388 -> V_263 ) {
case V_406 :
V_388 -> V_266 . V_267 =
( V_405 V_269 ) V_384 -> V_266 . V_267 ;
case V_407 :
case V_408 :
V_388 -> V_386 . V_409 . V_410 =
V_384 -> V_386 . V_409 . V_410 ;
V_388 -> V_386 . V_409 . V_214 =
V_384 -> V_386 . V_409 . V_214 ;
break;
case V_404 :
V_388 -> V_266 . V_267 =
( V_405 V_269 ) V_384 -> V_266 . V_267 ;
break;
case V_411 :
V_388 -> V_266 . V_412 =
V_384 -> V_266 . V_412 ;
break;
case V_413 :
case V_414 :
V_388 -> V_386 . V_415 . V_410 =
V_384 -> V_386 . V_415 . V_410 ;
V_388 -> V_386 . V_415 . V_416 =
V_384 -> V_386 . V_415 . V_416 ;
V_388 -> V_386 . V_415 . V_417 = V_384 -> V_386 . V_415 . V_417 ;
V_388 -> V_386 . V_415 . V_214 = V_384 -> V_386 . V_415 . V_214 ;
break;
default:
break;
}
}
if ( V_388 -> V_398 ) {
V_388 -> V_418 = ( void * ) V_388 +
F_132 ( sizeof *V_388 , sizeof ( struct V_399 ) ) ;
if ( F_46 ( V_388 -> V_418 ,
V_49 + sizeof V_52 +
V_52 . V_394 * V_52 . V_393 +
V_391 * sizeof ( struct V_399 ) ,
V_388 -> V_398 * sizeof ( struct V_399 ) ) ) {
V_15 = - V_64 ;
goto V_283;
}
V_391 += V_388 -> V_398 ;
} else
V_388 -> V_418 = NULL ;
}
V_54 . V_389 = 0 ;
V_15 = V_39 -> V_59 -> V_419 ( V_39 -> V_327 , V_386 , & V_389 ) ;
if ( V_15 )
for ( V_388 = V_386 ; V_388 ; V_388 = V_388 -> V_388 ) {
++ V_54 . V_389 ;
if ( V_388 == V_389 )
break;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_283:
F_39 ( V_39 ) ;
while ( V_386 ) {
if ( V_392 && V_386 -> V_386 . V_401 . V_35 )
F_36 ( V_386 -> V_386 . V_401 . V_35 ) ;
V_388 = V_386 -> V_388 ;
F_6 ( V_386 ) ;
V_386 = V_388 ;
}
V_198:
F_6 ( V_384 ) ;
return V_15 ? V_15 : V_50 ;
}
static struct V_420 * F_133 ( const char T_3 * V_49 ,
int V_50 ,
T_5 V_394 ,
T_5 V_395 ,
T_5 V_393 )
{
struct V_421 * V_384 ;
struct V_420 * V_386 = NULL , * V_387 , * V_388 ;
int V_391 ;
int V_390 ;
int V_15 ;
if ( V_50 < V_393 * V_394 +
V_395 * sizeof ( struct V_396 ) )
return F_134 ( - V_65 ) ;
if ( V_393 < sizeof ( struct V_421 ) )
return F_134 ( - V_65 ) ;
V_384 = F_67 ( V_393 , V_16 ) ;
if ( ! V_384 )
return F_134 ( - V_157 ) ;
V_391 = 0 ;
V_387 = NULL ;
for ( V_390 = 0 ; V_390 < V_394 ; ++ V_390 ) {
if ( F_46 ( V_384 , V_49 + V_390 * V_393 ,
V_393 ) ) {
V_15 = - V_64 ;
goto V_66;
}
if ( V_384 -> V_398 + V_391 > V_395 ) {
V_15 = - V_65 ;
goto V_66;
}
V_388 = F_67 ( F_132 ( sizeof *V_388 , sizeof ( struct V_399 ) ) +
V_384 -> V_398 * sizeof ( struct V_399 ) ,
V_16 ) ;
if ( ! V_388 ) {
V_15 = - V_157 ;
goto V_66;
}
if ( ! V_387 )
V_386 = V_388 ;
else
V_387 -> V_388 = V_388 ;
V_387 = V_388 ;
V_388 -> V_388 = NULL ;
V_388 -> V_261 = V_384 -> V_261 ;
V_388 -> V_398 = V_384 -> V_398 ;
if ( V_388 -> V_398 ) {
V_388 -> V_418 = ( void * ) V_388 +
F_132 ( sizeof *V_388 , sizeof ( struct V_399 ) ) ;
if ( F_46 ( V_388 -> V_418 ,
V_49 + V_394 * V_393 +
V_391 * sizeof ( struct V_399 ) ,
V_388 -> V_398 * sizeof ( struct V_399 ) ) ) {
V_15 = - V_64 ;
goto V_66;
}
V_391 += V_388 -> V_398 ;
} else
V_388 -> V_418 = NULL ;
}
F_6 ( V_384 ) ;
return V_386 ;
V_66:
F_6 ( V_384 ) ;
while ( V_386 ) {
V_388 = V_386 -> V_388 ;
F_6 ( V_386 ) ;
V_386 = V_388 ;
}
return F_134 ( V_15 ) ;
}
T_2 F_135 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_135 V_52 ;
struct V_422 V_54 ;
struct V_420 * V_386 , * V_388 , * V_389 ;
struct V_36 * V_39 ;
T_2 V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_386 = F_133 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_394 ,
V_52 . V_395 , V_52 . V_393 ) ;
if ( F_49 ( V_386 ) )
return F_50 ( V_386 ) ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
goto V_198;
V_54 . V_389 = 0 ;
V_15 = V_39 -> V_59 -> V_423 ( V_39 -> V_327 , V_386 , & V_389 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
for ( V_388 = V_386 ; V_388 ; V_388 = V_388 -> V_388 ) {
++ V_54 . V_389 ;
if ( V_388 == V_389 )
break;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_198:
while ( V_386 ) {
V_388 = V_386 -> V_388 ;
F_6 ( V_386 ) ;
V_386 = V_388 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_136 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_136 V_52 ;
struct V_424 V_54 ;
struct V_420 * V_386 , * V_388 , * V_389 ;
struct V_40 * V_43 ;
T_2 V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_386 = F_133 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_394 ,
V_52 . V_395 , V_52 . V_393 ) ;
if ( F_49 ( V_386 ) )
return F_50 ( V_386 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
goto V_198;
V_54 . V_389 = 0 ;
V_15 = V_43 -> V_59 -> V_425 ( V_43 , V_386 , & V_389 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
for ( V_388 = V_386 ; V_388 ; V_388 = V_388 -> V_388 ) {
++ V_54 . V_389 ;
if ( V_388 == V_389 )
break;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_198:
while ( V_386 ) {
V_388 = V_386 -> V_388 ;
F_6 ( V_386 ) ;
V_386 = V_388 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_137 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_137 V_52 ;
struct V_426 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_32 * V_35 ;
struct V_427 V_92 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_67 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_157 ;
F_1 ( V_2 , V_52 . V_3 , V_48 -> V_61 , & V_428 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_66;
}
V_92 . V_364 = V_52 . V_92 . V_364 ;
V_92 . V_275 = V_52 . V_92 . V_275 ;
V_92 . V_365 = V_52 . V_92 . V_365 ;
V_92 . V_366 = V_52 . V_92 . V_366 ;
V_92 . V_368 = V_52 . V_92 . V_367 ? V_369 : 0 ;
V_92 . V_135 = V_52 . V_92 . V_135 ;
V_92 . V_358 . V_360 = V_52 . V_92 . V_358 . V_360 ;
V_92 . V_358 . V_361 = V_52 . V_92 . V_358 . V_361 ;
V_92 . V_358 . V_362 = V_52 . V_92 . V_358 . V_362 ;
V_92 . V_358 . V_363 = V_52 . V_92 . V_358 . V_363 ;
memcpy ( V_92 . V_358 . V_356 . V_359 , V_52 . V_92 . V_358 . V_356 , 16 ) ;
V_35 = F_138 ( V_26 , & V_92 ) ;
if ( F_49 ( V_35 ) ) {
V_15 = F_50 ( V_35 ) ;
goto V_210;
}
V_35 -> V_27 = V_2 ;
V_2 -> V_22 = V_35 ;
V_15 = F_14 ( & V_34 , V_2 ) ;
if ( V_15 )
goto V_328;
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
V_328:
F_139 ( V_35 ) ;
V_210:
F_32 ( V_26 ) ;
V_66:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_140 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_140 V_52 ;
struct V_32 * V_35 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_34 , V_52 . V_33 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_35 = V_2 -> V_22 ;
V_15 = F_139 ( V_35 ) ;
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
T_2 F_141 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_141 V_52 ;
struct V_36 * V_39 ;
struct V_289 * V_181 ;
struct V_429 * V_430 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
return - V_65 ;
V_181 = F_7 ( V_39 -> V_27 , struct V_289 , V_299 . V_27 ) ;
F_142 (mcast, &obj->mcast_list, list)
if ( V_52 . V_431 == V_430 -> V_145 &&
! memcmp ( V_52 . V_432 , V_430 -> V_432 . V_359 , sizeof V_430 -> V_432 . V_359 ) ) {
V_15 = 0 ;
goto V_283;
}
V_430 = F_67 ( sizeof *V_430 , V_16 ) ;
if ( ! V_430 ) {
V_15 = - V_157 ;
goto V_283;
}
V_430 -> V_145 = V_52 . V_431 ;
memcpy ( V_430 -> V_432 . V_359 , V_52 . V_432 , sizeof V_430 -> V_432 . V_359 ) ;
V_15 = F_143 ( V_39 , & V_430 -> V_432 , V_52 . V_431 ) ;
if ( ! V_15 )
F_69 ( & V_430 -> V_163 , & V_181 -> V_325 ) ;
else
F_6 ( V_430 ) ;
V_283:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_144 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_144 V_52 ;
struct V_289 * V_181 ;
struct V_36 * V_39 ;
struct V_429 * V_430 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
return - V_65 ;
V_15 = F_145 ( V_39 , (union V_433 * ) V_52 . V_432 , V_52 . V_431 ) ;
if ( V_15 )
goto V_283;
V_181 = F_7 ( V_39 -> V_27 , struct V_289 , V_299 . V_27 ) ;
F_142 (mcast, &obj->mcast_list, list)
if ( V_52 . V_431 == V_430 -> V_145 &&
! memcmp ( V_52 . V_432 , V_430 -> V_432 . V_359 , sizeof V_430 -> V_432 . V_359 ) ) {
F_72 ( & V_430 -> V_163 ) ;
F_6 ( V_430 ) ;
break;
}
V_283:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_146 ( struct V_434 * V_435 ,
union V_436 * V_437 )
{
if ( V_435 -> V_277 )
return - V_65 ;
V_437 -> type = V_435 -> type ;
switch ( V_437 -> type ) {
case V_438 :
V_437 -> V_439 . V_440 = sizeof( struct V_441 ) ;
if ( V_437 -> V_439 . V_440 != V_435 -> V_439 . V_440 )
return - V_65 ;
memcpy ( & V_437 -> V_439 . V_442 , & V_435 -> V_439 . V_442 ,
sizeof( struct V_443 ) ) ;
memcpy ( & V_437 -> V_439 . V_373 , & V_435 -> V_439 . V_373 ,
sizeof( struct V_443 ) ) ;
break;
case V_444 :
V_437 -> V_445 . V_440 = sizeof( struct V_446 ) ;
if ( V_437 -> V_445 . V_440 != V_435 -> V_445 . V_440 )
return - V_65 ;
memcpy ( & V_437 -> V_445 . V_442 , & V_435 -> V_445 . V_442 ,
sizeof( struct V_447 ) ) ;
memcpy ( & V_437 -> V_445 . V_373 , & V_435 -> V_445 . V_373 ,
sizeof( struct V_447 ) ) ;
break;
case V_448 :
case V_449 :
V_437 -> V_450 . V_440 = sizeof( struct V_451 ) ;
if ( V_437 -> V_450 . V_440 != V_435 -> V_450 . V_440 )
return - V_65 ;
memcpy ( & V_437 -> V_450 . V_442 , & V_435 -> V_450 . V_442 ,
sizeof( struct V_452 ) ) ;
memcpy ( & V_437 -> V_450 . V_373 , & V_435 -> V_450 . V_373 ,
sizeof( struct V_452 ) ) ;
break;
default:
return - V_65 ;
}
return 0 ;
}
int F_147 ( struct V_47 * V_48 ,
struct V_55 * V_453 ,
struct V_55 * V_454 )
{
struct V_455 V_52 ;
struct V_456 V_54 ;
struct V_1 * V_2 ;
struct V_457 * V_458 ;
struct V_459 * V_460 ;
struct V_461 * V_462 ;
struct V_36 * V_39 ;
int V_66 = 0 ;
void * V_435 ;
void * V_437 ;
int V_390 ;
if ( V_453 -> V_463 < sizeof( V_52 ) )
return - V_65 ;
if ( V_453 -> V_464 < sizeof( V_54 ) )
return - V_63 ;
V_66 = F_148 ( & V_52 , V_453 , sizeof( V_52 ) ) ;
if ( V_66 )
return V_66 ;
V_453 -> V_465 += sizeof( V_52 ) ;
V_453 -> V_463 -= sizeof( V_52 ) ;
if ( V_52 . V_466 )
return - V_65 ;
if ( ( V_52 . V_462 . type == V_467 &&
! F_116 ( V_468 ) ) || ! F_116 ( V_297 ) )
return - V_298 ;
if ( V_52 . V_462 . V_469 > V_470 )
return - V_65 ;
if ( V_52 . V_462 . V_440 > V_453 -> V_463 ||
V_52 . V_462 . V_440 >
( V_52 . V_462 . V_469 * sizeof( struct V_434 ) ) )
return - V_65 ;
if ( V_52 . V_462 . V_277 [ 0 ] ||
V_52 . V_462 . V_277 [ 1 ] )
return - V_65 ;
if ( V_52 . V_462 . V_469 ) {
V_460 = F_67 ( sizeof( * V_460 ) + V_52 . V_462 . V_440 ,
V_16 ) ;
if ( ! V_460 )
return - V_157 ;
memcpy ( V_460 , & V_52 . V_462 , sizeof( * V_460 ) ) ;
V_66 = F_148 ( V_460 + 1 , V_453 ,
V_52 . V_462 . V_440 ) ;
if ( V_66 )
goto V_471;
} else {
V_460 = & V_52 . V_462 ;
}
V_2 = F_67 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 ) {
V_66 = - V_157 ;
goto V_471;
}
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_472 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_66 = - V_65 ;
goto V_473;
}
V_462 = F_67 ( sizeof( * V_462 ) + V_52 . V_462 . V_440 , V_16 ) ;
if ( ! V_462 ) {
V_66 = - V_157 ;
goto V_210;
}
V_462 -> type = V_460 -> type ;
V_462 -> V_474 = V_460 -> V_474 ;
V_462 -> V_469 = V_460 -> V_469 ;
V_462 -> V_475 = V_460 -> V_475 ;
V_462 -> V_218 = V_460 -> V_218 ;
V_462 -> V_440 = sizeof( * V_462 ) ;
V_435 = V_460 + 1 ;
V_437 = V_462 + 1 ;
for ( V_390 = 0 ; V_390 < V_462 -> V_469 &&
V_52 . V_462 . V_440 > F_149 ( struct V_434 , V_277 ) &&
V_52 . V_462 . V_440 >=
( (struct V_434 * ) V_435 ) -> V_440 ; V_390 ++ ) {
V_66 = F_146 ( V_435 , V_437 ) ;
if ( V_66 )
goto V_81;
V_462 -> V_440 +=
( (union V_436 * ) V_437 ) -> V_440 ;
V_52 . V_462 . V_440 -= ( (struct V_434 * ) V_435 ) -> V_440 ;
V_435 += ( (struct V_434 * ) V_435 ) -> V_440 ;
V_437 += ( (union V_436 * ) V_437 ) -> V_440 ;
}
if ( V_52 . V_462 . V_440 || ( V_390 != V_462 -> V_469 ) ) {
F_150 ( L_1 ,
V_390 , V_52 . V_462 . V_440 ) ;
V_66 = - V_65 ;
goto V_81;
}
V_458 = F_151 ( V_39 , V_462 , V_476 ) ;
if ( F_49 ( V_458 ) ) {
V_66 = F_50 ( V_458 ) ;
goto V_81;
}
V_458 -> V_39 = V_39 ;
V_458 -> V_27 = V_2 ;
V_2 -> V_22 = V_458 ;
V_66 = F_14 ( & V_477 , V_2 ) ;
if ( V_66 )
goto V_478;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_479 = V_2 -> V_19 ;
V_66 = F_152 ( V_453 ,
& V_54 , sizeof( V_54 ) ) ;
if ( V_66 )
goto V_162;
F_39 ( V_39 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_163 , & V_48 -> V_61 -> V_77 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_6 ( V_462 ) ;
if ( V_52 . V_462 . V_469 )
F_6 ( V_460 ) ;
return 0 ;
V_162:
F_20 ( & V_477 , V_2 ) ;
V_478:
F_153 ( V_458 ) ;
V_81:
F_6 ( V_462 ) ;
V_210:
F_39 ( V_39 ) ;
V_473:
F_12 ( V_2 ) ;
V_471:
if ( V_52 . V_462 . V_469 )
F_6 ( V_460 ) ;
return V_66 ;
}
int F_154 ( struct V_47 * V_48 ,
struct V_55 * V_453 ,
struct V_55 * V_454 )
{
struct V_480 V_52 ;
struct V_457 * V_458 ;
struct V_1 * V_2 ;
int V_15 ;
if ( V_453 -> V_463 < sizeof( V_52 ) )
return - V_65 ;
V_15 = F_148 ( & V_52 , V_453 , sizeof( V_52 ) ) ;
if ( V_15 )
return V_15 ;
if ( V_52 . V_466 )
return - V_65 ;
V_2 = F_28 ( & V_477 , V_52 . V_479 ,
V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_458 = V_2 -> V_22 ;
V_15 = F_153 ( V_458 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
F_20 ( & V_477 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_15 ;
}
static int F_155 ( struct V_47 * V_48 ,
struct V_481 * V_52 ,
struct V_55 * V_56 )
{
struct V_482 V_54 ;
struct V_483 * V_181 ;
struct V_23 * V_26 ;
struct V_40 * V_43 ;
struct V_1 * V_290 ( V_291 ) ;
struct V_484 V_92 ;
int V_15 ;
V_181 = F_67 ( sizeof *V_181 , V_16 ) ;
if ( ! V_181 )
return - V_157 ;
F_1 ( & V_181 -> V_299 . V_27 , V_52 -> V_3 , V_48 -> V_61 , & V_485 ) ;
F_29 ( & V_181 -> V_299 . V_27 . V_9 ) ;
if ( V_52 -> V_306 == V_486 ) {
V_92 . V_487 . V_488 . V_167 = F_43 ( V_52 -> V_45 , V_48 -> V_61 , & V_291 ) ;
if ( ! V_92 . V_487 . V_488 . V_167 ) {
V_15 = - V_65 ;
goto V_66;
}
V_181 -> V_330 = F_7 ( V_291 , struct V_180 , V_27 ) ;
F_87 ( & V_181 -> V_330 -> V_196 ) ;
V_92 . V_487 . V_488 . V_31 = F_33 ( V_52 -> V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_92 . V_487 . V_488 . V_31 ) {
V_15 = - V_65 ;
goto V_489;
}
}
V_26 = F_31 ( V_52 -> V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_490;
}
V_92 . V_87 = V_491 ;
V_92 . V_492 = V_48 ;
V_92 . V_306 = V_52 -> V_306 ;
V_92 . V_92 . V_493 = V_52 -> V_493 ;
V_92 . V_92 . V_104 = V_52 -> V_104 ;
V_92 . V_92 . V_494 = V_52 -> V_494 ;
V_181 -> V_299 . V_323 = 0 ;
F_51 ( & V_181 -> V_299 . V_324 ) ;
V_43 = V_26 -> V_59 -> V_495 ( V_26 , & V_92 , V_56 ) ;
if ( F_49 ( V_43 ) ) {
V_15 = F_50 ( V_43 ) ;
goto V_210;
}
V_43 -> V_59 = V_26 -> V_59 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_306 = V_52 -> V_306 ;
V_43 -> V_27 = & V_181 -> V_299 . V_27 ;
V_43 -> V_87 = V_92 . V_87 ;
V_43 -> V_492 = V_92 . V_492 ;
if ( V_52 -> V_306 == V_486 ) {
V_43 -> V_487 . V_488 . V_31 = V_92 . V_487 . V_488 . V_31 ;
V_43 -> V_487 . V_488 . V_167 = V_92 . V_487 . V_488 . V_167 ;
F_87 ( & V_92 . V_487 . V_488 . V_31 -> V_160 ) ;
F_87 ( & V_92 . V_487 . V_488 . V_167 -> V_160 ) ;
}
F_87 ( & V_26 -> V_160 ) ;
F_68 ( & V_43 -> V_160 , 0 ) ;
V_181 -> V_299 . V_27 . V_22 = V_43 ;
V_15 = F_14 ( & V_42 , & V_181 -> V_299 . V_27 ) ;
if ( V_15 )
goto V_328;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_41 = V_181 -> V_299 . V_27 . V_19 ;
V_54 . V_493 = V_92 . V_92 . V_493 ;
V_54 . V_104 = V_92 . V_92 . V_104 ;
if ( V_52 -> V_306 == V_486 )
V_54 . V_496 = V_43 -> V_487 . V_488 . V_497 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 -> V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_162;
}
if ( V_52 -> V_306 == V_486 ) {
F_10 ( V_291 ) ;
F_34 ( V_92 . V_487 . V_488 . V_31 ) ;
}
F_32 ( V_26 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_181 -> V_299 . V_27 . V_163 , & V_48 -> V_61 -> V_74 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_181 -> V_299 . V_27 . V_12 = 1 ;
F_13 ( & V_181 -> V_299 . V_27 . V_9 ) ;
return 0 ;
V_162:
F_20 ( & V_42 , & V_181 -> V_299 . V_27 ) ;
V_328:
F_156 ( V_43 ) ;
V_210:
F_32 ( V_26 ) ;
V_490:
if ( V_52 -> V_306 == V_486 )
F_34 ( V_92 . V_487 . V_488 . V_31 ) ;
V_489:
if ( V_52 -> V_306 == V_486 ) {
F_89 ( & V_181 -> V_330 -> V_196 ) ;
F_10 ( V_291 ) ;
}
V_66:
F_12 ( & V_181 -> V_299 . V_27 ) ;
return V_15 ;
}
T_2 F_157 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_157 V_52 ;
struct V_481 V_498 ;
struct V_482 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_498 . V_67 = V_52 . V_67 ;
V_498 . V_3 = V_52 . V_3 ;
V_498 . V_306 = V_307 ;
V_498 . V_24 = V_52 . V_24 ;
V_498 . V_493 = V_52 . V_493 ;
V_498 . V_104 = V_52 . V_104 ;
V_498 . V_494 = V_52 . V_494 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_155 ( V_48 , & V_498 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 V_481 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct V_481 V_52 ;
struct V_482 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_155 ( V_48 , & V_52 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 F_158 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_158 V_52 ;
struct V_55 V_56 ;
struct V_40 * V_43 ;
struct V_499 V_92 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 , NULL , V_50 - sizeof V_52 ,
V_51 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
return - V_65 ;
V_92 . V_493 = V_52 . V_493 ;
V_92 . V_494 = V_52 . V_494 ;
V_15 = V_43 -> V_59 -> V_500 ( V_43 , & V_92 , V_52 . V_336 , & V_56 ) ;
F_42 ( V_43 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_159 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_159 V_52 ;
struct V_501 V_54 ;
struct V_499 V_92 ;
struct V_40 * V_43 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
return - V_65 ;
V_15 = F_160 ( V_43 , & V_92 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_493 = V_92 . V_493 ;
V_54 . V_104 = V_92 . V_104 ;
V_54 . V_494 = V_92 . V_494 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_161 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_161 V_52 ;
struct V_502 V_54 ;
struct V_1 * V_2 ;
struct V_40 * V_43 ;
struct V_503 * V_181 ;
int V_15 = - V_65 ;
struct V_483 * V_504 ;
enum V_505 V_306 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_42 , V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_43 = V_2 -> V_22 ;
V_181 = F_7 ( V_2 , struct V_503 , V_27 ) ;
V_306 = V_43 -> V_306 ;
V_15 = F_156 ( V_43 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( V_306 == V_486 ) {
V_504 = F_7 ( V_181 , struct V_483 , V_299 ) ;
F_89 ( & V_504 -> V_330 -> V_196 ) ;
}
F_20 ( & V_42 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_163 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_130 ( V_48 , V_181 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_323 = V_181 -> V_323 ;
F_8 ( V_2 ) ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
return V_15 ? V_15 : V_50 ;
}
