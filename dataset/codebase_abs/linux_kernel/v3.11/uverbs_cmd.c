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
V_61 -> V_77 = 0 ;
V_54 . V_78 = V_48 -> V_59 -> V_78 ;
V_15 = F_52 ( V_79 ) ;
if ( V_15 < 0 )
goto V_80;
V_54 . V_81 = V_15 ;
V_62 = F_53 ( V_48 , 1 ) ;
if ( F_49 ( V_62 ) ) {
V_15 = F_50 ( V_62 ) ;
goto V_82;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_83;
}
V_48 -> V_84 = V_62 -> V_85 ;
F_55 ( & V_48 -> V_86 , V_48 -> V_59 -> V_60 ,
V_87 ) ;
V_15 = F_56 ( & V_48 -> V_86 ) ;
if ( V_15 )
goto V_83;
F_24 ( & V_48 -> V_84 -> V_8 ) ;
F_24 ( & V_48 -> V_8 ) ;
V_48 -> V_61 = V_61 ;
F_57 ( V_54 . V_81 , V_62 ) ;
F_58 ( & V_48 -> V_9 ) ;
return V_50 ;
V_83:
F_59 ( V_62 ) ;
V_82:
F_60 ( V_54 . V_81 ) ;
V_80:
V_58 -> V_88 ( V_61 ) ;
V_66:
F_58 ( & V_48 -> V_9 ) ;
return V_15 ;
}
T_2 F_61 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_61 V_52 ;
struct V_89 V_54 ;
struct V_90 V_91 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_15 = F_62 ( V_48 -> V_59 -> V_60 , & V_91 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_92 = V_91 . V_92 ;
V_54 . V_93 = V_48 -> V_59 -> V_60 -> V_93 ;
V_54 . V_94 = V_91 . V_94 ;
V_54 . V_95 = V_91 . V_95 ;
V_54 . V_96 = V_91 . V_96 ;
V_54 . V_97 = V_91 . V_97 ;
V_54 . V_98 = V_91 . V_98 ;
V_54 . V_99 = V_91 . V_99 ;
V_54 . V_100 = V_91 . V_100 ;
V_54 . V_101 = V_91 . V_101 ;
V_54 . V_102 = V_91 . V_102 ;
V_54 . V_103 = V_91 . V_103 ;
V_54 . V_104 = V_91 . V_104 ;
V_54 . V_105 = V_91 . V_105 ;
V_54 . V_106 = V_91 . V_106 ;
V_54 . V_107 = V_91 . V_107 ;
V_54 . V_108 = V_91 . V_108 ;
V_54 . V_109 = V_91 . V_109 ;
V_54 . V_110 = V_91 . V_110 ;
V_54 . V_111 = V_91 . V_111 ;
V_54 . V_112 = V_91 . V_112 ;
V_54 . V_113 = V_91 . V_113 ;
V_54 . V_114 = V_91 . V_114 ;
V_54 . V_115 = V_91 . V_115 ;
V_54 . V_116 = V_91 . V_116 ;
V_54 . V_117 = V_91 . V_117 ;
V_54 . V_118 = V_91 . V_118 ;
V_54 . V_119 = V_91 . V_119 ;
V_54 . V_120 = V_91 . V_120 ;
V_54 . V_121 = V_91 . V_121 ;
V_54 . V_122 = V_91 . V_122 ;
V_54 . V_123 = V_91 . V_123 ;
V_54 . V_124 = V_91 . V_124 ;
V_54 . V_125 = V_91 . V_125 ;
V_54 . V_126 = V_91 . V_126 ;
V_54 . V_127 = V_91 . V_127 ;
V_54 . V_128 = V_91 . V_128 ;
V_54 . V_129 = V_91 . V_129 ;
V_54 . V_130 = V_91 . V_130 ;
V_54 . V_131 = V_48 -> V_59 -> V_60 -> V_131 ;
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
struct V_132 V_54 ;
struct V_133 V_91 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_15 = F_64 ( V_48 -> V_59 -> V_60 , V_52 . V_134 , & V_91 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_135 = V_91 . V_135 ;
V_54 . V_136 = V_91 . V_136 ;
V_54 . V_137 = V_91 . V_137 ;
V_54 . V_138 = V_91 . V_138 ;
V_54 . V_139 = V_91 . V_139 ;
V_54 . V_140 = V_91 . V_140 ;
V_54 . V_141 = V_91 . V_141 ;
V_54 . V_142 = V_91 . V_142 ;
V_54 . V_143 = V_91 . V_143 ;
V_54 . V_144 = V_91 . V_144 ;
V_54 . V_145 = V_91 . V_145 ;
V_54 . V_146 = V_91 . V_146 ;
V_54 . V_147 = V_91 . V_147 ;
V_54 . V_148 = V_91 . V_148 ;
V_54 . V_149 = V_91 . V_149 ;
V_54 . V_150 = V_91 . V_150 ;
V_54 . V_151 = V_91 . V_151 ;
V_54 . V_152 = V_91 . V_152 ;
V_54 . V_153 = V_91 . V_153 ;
V_54 . V_154 = F_65 ( V_48 -> V_59 -> V_60 ,
V_52 . V_134 ) ;
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
struct V_155 V_54 ;
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
return - V_156 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_157 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = V_48 -> V_59 -> V_60 -> V_158 ( V_48 -> V_59 -> V_60 ,
V_48 -> V_61 , & V_56 ) ;
if ( F_49 ( V_26 ) ) {
V_15 = F_50 ( V_26 ) ;
goto V_66;
}
V_26 -> V_59 = V_48 -> V_59 -> V_60 ;
V_26 -> V_27 = V_2 ;
F_68 ( & V_26 -> V_159 , 0 ) ;
V_2 -> V_22 = V_26 ;
V_15 = F_14 ( & V_25 , V_2 ) ;
if ( V_15 )
goto V_160;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_24 = V_2 -> V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_161;
}
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_162 , & V_48 -> V_61 -> V_69 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_161:
F_20 ( & V_25 , V_2 ) ;
V_160:
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
F_72 ( & V_2 -> V_162 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
static int F_73 ( struct V_163 * V_164 ,
struct V_165 * V_165 ,
struct V_44 * V_166 )
{
struct V_167 * V_168 , * V_169 ;
struct V_170 * * V_171 = & V_164 -> V_172 . V_170 ;
struct V_170 * V_173 = NULL ;
V_168 = F_67 ( sizeof *V_168 , V_16 ) ;
if ( ! V_168 )
return - V_156 ;
V_168 -> V_166 = V_166 ;
V_168 -> V_165 = V_165 ;
while ( * V_171 ) {
V_173 = * V_171 ;
V_169 = F_74 ( V_173 , struct V_167 , V_174 ) ;
if ( V_165 < V_169 -> V_165 ) {
V_171 = & ( * V_171 ) -> V_175 ;
} else if ( V_165 > V_169 -> V_165 ) {
V_171 = & ( * V_171 ) -> V_176 ;
} else {
F_6 ( V_168 ) ;
return - V_177 ;
}
}
F_75 ( & V_168 -> V_174 , V_173 , V_171 ) ;
F_76 ( & V_168 -> V_174 , & V_164 -> V_172 ) ;
F_77 ( V_165 ) ;
return 0 ;
}
static struct V_167 * F_78 ( struct V_163 * V_164 ,
struct V_165 * V_165 )
{
struct V_167 * V_168 ;
struct V_170 * V_171 = V_164 -> V_172 . V_170 ;
while ( V_171 ) {
V_168 = F_74 ( V_171 , struct V_167 , V_174 ) ;
if ( V_165 < V_168 -> V_165 )
V_171 = V_171 -> V_175 ;
else if ( V_165 > V_168 -> V_165 )
V_171 = V_171 -> V_176 ;
else
return V_168 ;
}
return NULL ;
}
static struct V_44 * F_79 ( struct V_163 * V_164 , struct V_165 * V_165 )
{
struct V_167 * V_168 ;
V_168 = F_78 ( V_164 , V_165 ) ;
if ( ! V_168 )
return NULL ;
return V_168 -> V_166 ;
}
static void F_80 ( struct V_163 * V_164 ,
struct V_165 * V_165 )
{
struct V_167 * V_168 ;
V_168 = F_78 ( V_164 , V_165 ) ;
if ( V_168 ) {
F_81 ( V_165 ) ;
F_82 ( & V_168 -> V_174 , & V_164 -> V_172 ) ;
F_6 ( V_168 ) ;
}
}
T_2 F_83 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_83 V_52 ;
struct V_178 V_54 ;
struct V_55 V_56 ;
struct V_179 * V_180 ;
struct V_44 * V_166 = NULL ;
struct V_181 V_182 = { NULL , 0 } ;
struct V_165 * V_165 = NULL ;
int V_15 = 0 ;
int V_183 = 0 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
F_47 ( & V_48 -> V_59 -> V_184 ) ;
if ( V_52 . V_181 != - 1 ) {
V_182 = F_84 ( V_52 . V_181 ) ;
if ( ! V_182 . V_48 ) {
V_15 = - V_185 ;
goto V_186;
}
V_165 = F_85 ( V_182 . V_48 ) ;
V_166 = F_79 ( V_48 -> V_59 , V_165 ) ;
if ( ! V_166 && ! ( V_52 . V_187 & V_188 ) ) {
V_15 = - V_189 ;
goto V_186;
}
if ( V_166 && V_52 . V_187 & V_190 ) {
V_15 = - V_65 ;
goto V_186;
}
}
V_180 = F_67 ( sizeof *V_180 , V_16 ) ;
if ( ! V_180 ) {
V_15 = - V_156 ;
goto V_186;
}
F_1 ( & V_180 -> V_27 , 0 , V_48 -> V_61 , & V_191 ) ;
F_29 ( & V_180 -> V_27 . V_9 ) ;
if ( ! V_166 ) {
V_166 = V_48 -> V_59 -> V_60 -> V_192 ( V_48 -> V_59 -> V_60 ,
V_48 -> V_61 , & V_56 ) ;
if ( F_49 ( V_166 ) ) {
V_15 = F_50 ( V_166 ) ;
goto V_66;
}
V_166 -> V_165 = V_165 ;
V_166 -> V_59 = V_48 -> V_59 -> V_60 ;
F_68 ( & V_166 -> V_159 , 0 ) ;
F_86 ( & V_166 -> V_193 ) ;
F_51 ( & V_166 -> V_194 ) ;
V_183 = 1 ;
}
F_68 ( & V_180 -> V_195 , 0 ) ;
V_180 -> V_27 . V_22 = V_166 ;
V_15 = F_14 ( & V_46 , & V_180 -> V_27 ) ;
if ( V_15 )
goto V_160;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_45 = V_180 -> V_27 . V_19 ;
if ( V_165 ) {
if ( V_183 ) {
V_15 = F_73 ( V_48 -> V_59 , V_165 , V_166 ) ;
if ( V_15 )
goto V_196;
}
F_87 ( & V_166 -> V_159 ) ;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_161;
}
if ( V_182 . V_48 )
F_88 ( V_182 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_180 -> V_27 . V_162 , & V_48 -> V_61 -> V_76 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_180 -> V_27 . V_12 = 1 ;
F_13 ( & V_180 -> V_27 . V_9 ) ;
F_58 ( & V_48 -> V_59 -> V_184 ) ;
return V_50 ;
V_161:
if ( V_165 ) {
if ( V_183 )
F_80 ( V_48 -> V_59 , V_165 ) ;
F_89 ( & V_166 -> V_159 ) ;
}
V_196:
F_20 ( & V_46 , & V_180 -> V_27 ) ;
V_160:
F_90 ( V_166 ) ;
V_66:
F_12 ( & V_180 -> V_27 ) ;
V_186:
if ( V_182 . V_48 )
F_88 ( V_182 ) ;
F_58 ( & V_48 -> V_59 -> V_184 ) ;
return V_15 ;
}
T_2 F_91 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_91 V_52 ;
struct V_1 * V_2 ;
struct V_44 * V_166 = NULL ;
struct V_165 * V_165 = NULL ;
struct V_179 * V_180 ;
int V_12 ;
int V_15 = 0 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_47 ( & V_48 -> V_59 -> V_184 ) ;
V_2 = F_28 ( & V_46 , V_52 . V_45 , V_48 -> V_61 ) ;
if ( ! V_2 ) {
V_15 = - V_65 ;
goto V_197;
}
V_166 = V_2 -> V_22 ;
V_165 = V_166 -> V_165 ;
V_180 = F_7 ( V_2 , struct V_179 , V_27 ) ;
if ( F_92 ( & V_180 -> V_195 ) ) {
F_12 ( V_2 ) ;
V_15 = - V_198 ;
goto V_197;
}
if ( ! V_165 || F_93 ( & V_166 -> V_159 ) ) {
V_15 = F_90 ( V_2 -> V_22 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
}
V_12 = V_2 -> V_12 ;
if ( V_165 && V_15 )
F_87 ( & V_166 -> V_159 ) ;
F_12 ( V_2 ) ;
if ( V_15 )
goto V_197;
if ( V_165 && ! V_12 )
F_80 ( V_48 -> V_59 , V_165 ) ;
F_20 ( & V_46 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_162 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
V_15 = V_50 ;
V_197:
F_58 ( & V_48 -> V_59 -> V_184 ) ;
return V_15 ;
}
void F_94 ( struct V_163 * V_164 ,
struct V_44 * V_166 )
{
struct V_165 * V_165 ;
V_165 = V_166 -> V_165 ;
if ( V_165 && ! F_93 ( & V_166 -> V_159 ) )
return;
F_90 ( V_166 ) ;
if ( V_165 )
F_80 ( V_164 , V_165 ) ;
}
T_2 F_95 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_95 V_52 ;
struct V_199 V_54 ;
struct V_55 V_56 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_200 * V_201 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
if ( ( V_52 . V_202 & ~ V_203 ) != ( V_52 . V_204 & ~ V_203 ) )
return - V_65 ;
if ( V_52 . V_205 & ( V_206 | V_207 ) &&
! ( V_52 . V_205 & V_208 ) )
return - V_65 ;
V_2 = F_67 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_156 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_209 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_80;
}
V_201 = V_26 -> V_59 -> V_210 ( V_26 , V_52 . V_202 , V_52 . V_211 , V_52 . V_204 ,
V_52 . V_205 , & V_56 ) ;
if ( F_49 ( V_201 ) ) {
V_15 = F_50 ( V_201 ) ;
goto V_212;
}
V_201 -> V_59 = V_26 -> V_59 ;
V_201 -> V_26 = V_26 ;
V_201 -> V_27 = V_2 ;
F_87 ( & V_26 -> V_159 ) ;
F_68 ( & V_201 -> V_159 , 0 ) ;
V_2 -> V_22 = V_201 ;
V_15 = F_14 ( & V_213 , V_2 ) ;
if ( V_15 )
goto V_214;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_215 = V_201 -> V_215 ;
V_54 . V_216 = V_201 -> V_216 ;
V_54 . V_217 = V_2 -> V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_161;
}
F_32 ( V_26 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_162 , & V_48 -> V_61 -> V_70 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_161:
F_20 ( & V_213 , V_2 ) ;
V_214:
F_96 ( V_201 ) ;
V_212:
F_32 ( V_26 ) ;
V_80:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_97 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_97 V_52 ;
struct V_200 * V_201 ;
struct V_1 * V_2 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_213 , V_52 . V_217 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_201 = V_2 -> V_22 ;
V_15 = F_96 ( V_201 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_213 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_162 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_98 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_98 V_52 ;
struct V_218 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_219 * V_220 ;
int V_15 ;
if ( V_51 < sizeof( V_54 ) )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_64 ;
V_2 = F_67 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return - V_156 ;
F_1 ( V_2 , 0 , V_48 -> V_61 , & V_221 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_80;
}
V_220 = V_26 -> V_59 -> V_222 ( V_26 , V_52 . V_223 ) ;
if ( F_49 ( V_220 ) ) {
V_15 = F_50 ( V_220 ) ;
goto V_212;
}
V_220 -> V_59 = V_26 -> V_59 ;
V_220 -> V_26 = V_26 ;
V_220 -> V_27 = V_2 ;
F_87 ( & V_26 -> V_159 ) ;
V_2 -> V_22 = V_220 ;
V_15 = F_14 ( & V_224 , V_2 ) ;
if ( V_15 )
goto V_225;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_216 = V_220 -> V_216 ;
V_54 . V_226 = V_2 -> V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof( V_54 ) ) ) {
V_15 = - V_64 ;
goto V_161;
}
F_32 ( V_26 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_162 , & V_48 -> V_61 -> V_71 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_161:
F_20 ( & V_224 , V_2 ) ;
V_225:
F_99 ( V_220 ) ;
V_212:
F_32 ( V_26 ) ;
V_80:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_100 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_100 V_52 ;
struct V_219 * V_220 ;
struct V_1 * V_2 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof( V_52 ) ) )
return - V_64 ;
V_2 = F_28 ( & V_224 , V_52 . V_226 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_220 = V_2 -> V_22 ;
V_15 = F_99 ( V_220 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_224 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_162 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_101 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_101 V_52 ;
struct V_227 V_54 ;
struct V_48 * V_62 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_15 = F_52 ( V_79 ) ;
if ( V_15 < 0 )
return V_15 ;
V_54 . V_181 = V_15 ;
V_62 = F_53 ( V_48 , 0 ) ;
if ( F_49 ( V_62 ) ) {
F_60 ( V_54 . V_181 ) ;
return F_50 ( V_62 ) ;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
F_60 ( V_54 . V_181 ) ;
F_59 ( V_62 ) ;
return - V_64 ;
}
F_57 ( V_54 . V_181 , V_62 ) ;
return V_50 ;
}
T_2 F_102 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_102 V_52 ;
struct V_228 V_54 ;
struct V_55 V_56 ;
struct V_229 * V_180 ;
struct V_230 * V_231 = NULL ;
struct V_28 * V_31 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
if ( V_52 . V_232 >= V_48 -> V_59 -> V_78 )
return - V_65 ;
V_180 = F_67 ( sizeof *V_180 , V_16 ) ;
if ( ! V_180 )
return - V_156 ;
F_1 ( & V_180 -> V_27 , V_52 . V_3 , V_48 -> V_61 , & V_233 ) ;
F_29 ( & V_180 -> V_27 . V_9 ) ;
if ( V_52 . V_234 >= 0 ) {
V_231 = F_103 ( V_52 . V_234 ) ;
if ( ! V_231 ) {
V_15 = - V_65 ;
goto V_66;
}
}
V_180 -> V_235 = V_48 ;
V_180 -> V_236 = 0 ;
V_180 -> V_237 = 0 ;
F_51 ( & V_180 -> V_238 ) ;
F_51 ( & V_180 -> V_239 ) ;
V_31 = V_48 -> V_59 -> V_60 -> V_240 ( V_48 -> V_59 -> V_60 , V_52 . V_241 ,
V_52 . V_232 ,
V_48 -> V_61 , & V_56 ) ;
if ( F_49 ( V_31 ) ) {
V_15 = F_50 ( V_31 ) ;
goto V_83;
}
V_31 -> V_59 = V_48 -> V_59 -> V_60 ;
V_31 -> V_27 = & V_180 -> V_27 ;
V_31 -> V_242 = V_243 ;
V_31 -> V_86 = V_244 ;
V_31 -> V_245 = V_231 ;
F_68 ( & V_31 -> V_159 , 0 ) ;
V_180 -> V_27 . V_22 = V_31 ;
V_15 = F_14 ( & V_30 , & V_180 -> V_27 ) ;
if ( V_15 )
goto V_80;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_29 = V_180 -> V_27 . V_19 ;
V_54 . V_241 = V_31 -> V_241 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_161;
}
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_180 -> V_27 . V_162 , & V_48 -> V_61 -> V_72 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_180 -> V_27 . V_12 = 1 ;
F_13 ( & V_180 -> V_27 . V_9 ) ;
return V_50 ;
V_161:
F_20 ( & V_30 , & V_180 -> V_27 ) ;
V_80:
F_104 ( V_31 ) ;
V_83:
if ( V_231 )
F_105 ( V_48 , V_231 , V_180 ) ;
V_66:
F_12 ( & V_180 -> V_27 ) ;
return V_15 ;
}
T_2 F_106 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_106 V_52 ;
struct V_246 V_54 ;
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
V_15 = V_31 -> V_59 -> V_247 ( V_31 , V_52 . V_241 , & V_56 ) ;
if ( V_15 )
goto V_197;
V_54 . V_241 = V_31 -> V_241 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 . V_241 ) )
V_15 = - V_64 ;
V_197:
F_34 ( V_31 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_107 ( void T_3 * V_248 , struct V_249 * V_250 )
{
struct V_251 V_252 ;
V_252 . V_253 = V_250 -> V_253 ;
V_252 . V_254 = V_250 -> V_254 ;
V_252 . V_255 = V_250 -> V_255 ;
V_252 . V_256 = V_250 -> V_256 ;
V_252 . V_257 = V_250 -> V_257 ;
V_252 . V_258 . V_259 = ( V_260 V_261 ) V_250 -> V_258 . V_259 ;
V_252 . V_262 = V_250 -> V_39 -> V_262 ;
V_252 . V_263 = V_250 -> V_263 ;
V_252 . V_264 = V_250 -> V_264 ;
V_252 . V_265 = V_250 -> V_265 ;
V_252 . V_266 = V_250 -> V_266 ;
V_252 . V_267 = V_250 -> V_267 ;
V_252 . V_268 = V_250 -> V_268 ;
V_252 . V_134 = V_250 -> V_134 ;
V_252 . V_269 = 0 ;
if ( F_54 ( V_248 , & V_252 , sizeof V_252 ) )
return - V_64 ;
return 0 ;
}
T_2 F_108 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_108 V_52 ;
struct V_270 V_54 ;
T_4 T_3 * V_271 ;
T_4 T_3 * V_272 ;
struct V_28 * V_31 ;
struct V_249 V_250 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_31 = F_33 ( V_52 . V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_31 )
return - V_65 ;
V_271 = ( void T_3 * ) ( unsigned long ) V_52 . V_67 ;
V_272 = V_271 + sizeof V_54 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
while ( V_54 . V_273 < V_52 . V_274 ) {
V_15 = F_109 ( V_31 , 1 , & V_250 ) ;
if ( V_15 < 0 )
goto V_275;
if ( ! V_15 )
break;
V_15 = F_107 ( V_272 , & V_250 ) ;
if ( V_15 )
goto V_275;
V_272 += sizeof( struct V_251 ) ;
++ V_54 . V_273 ;
}
if ( F_54 ( V_271 , & V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_275;
}
V_15 = V_50 ;
V_275:
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
F_111 ( V_31 , V_52 . V_276 ?
V_277 : V_278 ) ;
F_34 ( V_31 ) ;
return V_50 ;
}
T_2 F_112 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_112 V_52 ;
struct V_279 V_54 ;
struct V_1 * V_2 ;
struct V_28 * V_31 ;
struct V_229 * V_180 ;
struct V_230 * V_231 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_30 , V_52 . V_29 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_31 = V_2 -> V_22 ;
V_231 = V_31 -> V_245 ;
V_180 = F_7 ( V_31 -> V_27 , struct V_229 , V_27 ) ;
V_15 = F_104 ( V_31 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_30 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_162 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_105 ( V_48 , V_231 , V_180 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_236 = V_180 -> V_236 ;
V_54 . V_237 = V_180 -> V_237 ;
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
struct V_280 V_54 ;
struct V_55 V_56 ;
struct V_281 * V_180 ;
struct V_57 * V_59 ;
struct V_23 * V_26 = NULL ;
struct V_44 * V_166 = NULL ;
struct V_1 * V_282 ( V_283 ) ;
struct V_28 * V_284 = NULL , * V_285 = NULL ;
struct V_40 * V_43 = NULL ;
struct V_36 * V_39 ;
struct V_286 V_91 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
if ( V_52 . V_287 == V_288 && ! F_114 ( V_289 ) )
return - V_290 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_180 = F_67 ( sizeof *V_180 , V_16 ) ;
if ( ! V_180 )
return - V_156 ;
F_1 ( & V_180 -> V_291 . V_27 , V_52 . V_3 , V_48 -> V_61 , & V_292 ) ;
F_29 ( & V_180 -> V_291 . V_27 . V_9 ) ;
if ( V_52 . V_287 == V_293 ) {
V_166 = F_43 ( V_52 . V_24 , V_48 -> V_61 , & V_283 ) ;
if ( ! V_166 ) {
V_15 = - V_65 ;
goto V_212;
}
V_59 = V_166 -> V_59 ;
} else {
if ( V_52 . V_287 == V_294 ) {
V_52 . V_295 = V_52 . V_296 = 0 ;
} else {
if ( V_52 . V_297 ) {
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 || V_43 -> V_298 != V_299 ) {
V_15 = - V_65 ;
goto V_212;
}
}
if ( V_52 . V_300 != V_52 . V_301 ) {
V_285 = F_33 ( V_52 . V_300 , V_48 -> V_61 , 0 ) ;
if ( ! V_285 ) {
V_15 = - V_65 ;
goto V_212;
}
}
}
V_284 = F_33 ( V_52 . V_301 , V_48 -> V_61 , ! ! V_285 ) ;
V_285 = V_285 ? : V_284 ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 || ! V_284 ) {
V_15 = - V_65 ;
goto V_212;
}
V_59 = V_26 -> V_59 ;
}
V_91 . V_86 = V_302 ;
V_91 . V_303 = V_48 ;
V_91 . V_304 = V_284 ;
V_91 . V_305 = V_285 ;
V_91 . V_43 = V_43 ;
V_91 . V_166 = V_166 ;
V_91 . V_306 = V_52 . V_307 ? V_308 : V_309 ;
V_91 . V_287 = V_52 . V_287 ;
V_91 . V_310 = 0 ;
V_91 . V_311 . V_312 = V_52 . V_312 ;
V_91 . V_311 . V_295 = V_52 . V_295 ;
V_91 . V_311 . V_313 = V_52 . V_313 ;
V_91 . V_311 . V_296 = V_52 . V_296 ;
V_91 . V_311 . V_314 = V_52 . V_314 ;
V_180 -> V_291 . V_315 = 0 ;
F_51 ( & V_180 -> V_291 . V_316 ) ;
F_51 ( & V_180 -> V_317 ) ;
if ( V_52 . V_287 == V_293 )
V_39 = F_115 ( V_26 , & V_91 ) ;
else
V_39 = V_59 -> V_318 ( V_26 , & V_91 , & V_56 ) ;
if ( F_49 ( V_39 ) ) {
V_15 = F_50 ( V_39 ) ;
goto V_212;
}
if ( V_52 . V_287 != V_293 ) {
V_39 -> V_319 = V_39 ;
V_39 -> V_59 = V_59 ;
V_39 -> V_26 = V_26 ;
V_39 -> V_304 = V_91 . V_304 ;
V_39 -> V_305 = V_91 . V_305 ;
V_39 -> V_43 = V_91 . V_43 ;
V_39 -> V_86 = V_91 . V_86 ;
V_39 -> V_303 = V_91 . V_303 ;
V_39 -> V_287 = V_91 . V_287 ;
F_68 ( & V_39 -> V_159 , 0 ) ;
F_87 ( & V_26 -> V_159 ) ;
F_87 ( & V_91 . V_304 -> V_159 ) ;
if ( V_91 . V_305 )
F_87 ( & V_91 . V_305 -> V_159 ) ;
if ( V_91 . V_43 )
F_87 ( & V_91 . V_43 -> V_159 ) ;
}
V_39 -> V_27 = & V_180 -> V_291 . V_27 ;
V_180 -> V_291 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_180 -> V_291 . V_27 ) ;
if ( V_15 )
goto V_320;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_321 = V_39 -> V_262 ;
V_54 . V_37 = V_180 -> V_291 . V_27 . V_19 ;
V_54 . V_296 = V_91 . V_311 . V_296 ;
V_54 . V_313 = V_91 . V_311 . V_313 ;
V_54 . V_295 = V_91 . V_311 . V_295 ;
V_54 . V_312 = V_91 . V_311 . V_312 ;
V_54 . V_314 = V_91 . V_311 . V_314 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_161;
}
if ( V_166 )
F_44 ( V_283 ) ;
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_284 )
F_34 ( V_284 ) ;
if ( V_285 && V_285 != V_284 )
F_34 ( V_285 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_180 -> V_291 . V_27 . V_162 , & V_48 -> V_61 -> V_73 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_180 -> V_291 . V_27 . V_12 = 1 ;
F_13 ( & V_180 -> V_291 . V_27 . V_9 ) ;
return V_50 ;
V_161:
F_20 ( & V_38 , & V_180 -> V_291 . V_27 ) ;
V_320:
F_116 ( V_39 ) ;
V_212:
if ( V_166 )
F_44 ( V_283 ) ;
if ( V_26 )
F_32 ( V_26 ) ;
if ( V_284 )
F_34 ( V_284 ) ;
if ( V_285 && V_285 != V_284 )
F_34 ( V_285 ) ;
if ( V_43 )
F_42 ( V_43 ) ;
F_12 ( & V_180 -> V_291 . V_27 ) ;
return V_15 ;
}
T_2 F_117 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_117 V_52 ;
struct V_280 V_54 ;
struct V_55 V_56 ;
struct V_281 * V_180 ;
struct V_44 * V_166 ;
struct V_1 * V_282 ( V_283 ) ;
struct V_36 * V_39 ;
struct V_322 V_91 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_180 = F_67 ( sizeof *V_180 , V_16 ) ;
if ( ! V_180 )
return - V_156 ;
F_1 ( & V_180 -> V_291 . V_27 , V_52 . V_3 , V_48 -> V_61 , & V_292 ) ;
F_29 ( & V_180 -> V_291 . V_27 . V_9 ) ;
V_166 = F_43 ( V_52 . V_24 , V_48 -> V_61 , & V_283 ) ;
if ( ! V_166 ) {
V_15 = - V_65 ;
goto V_212;
}
V_91 . V_86 = V_302 ;
V_91 . V_303 = V_48 ;
V_91 . V_262 = V_52 . V_321 ;
V_91 . V_287 = V_52 . V_287 ;
V_180 -> V_291 . V_315 = 0 ;
F_51 ( & V_180 -> V_291 . V_316 ) ;
F_51 ( & V_180 -> V_317 ) ;
V_39 = F_118 ( V_166 , & V_91 ) ;
if ( F_49 ( V_39 ) ) {
V_15 = F_50 ( V_39 ) ;
goto V_212;
}
V_39 -> V_27 = & V_180 -> V_291 . V_27 ;
V_180 -> V_291 . V_27 . V_22 = V_39 ;
V_15 = F_14 ( & V_38 , & V_180 -> V_291 . V_27 ) ;
if ( V_15 )
goto V_320;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_321 = V_39 -> V_262 ;
V_54 . V_37 = V_180 -> V_291 . V_27 . V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_323;
}
F_44 ( V_283 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_180 -> V_291 . V_27 . V_162 , & V_48 -> V_61 -> V_73 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_180 -> V_291 . V_27 . V_12 = 1 ;
F_13 ( & V_180 -> V_291 . V_27 . V_9 ) ;
return V_50 ;
V_323:
F_20 ( & V_38 , & V_180 -> V_291 . V_27 ) ;
V_320:
F_116 ( V_39 ) ;
V_212:
F_44 ( V_283 ) ;
F_12 ( & V_180 -> V_291 . V_27 ) ;
return V_15 ;
}
T_2 F_119 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_119 V_52 ;
struct V_324 V_54 ;
struct V_36 * V_39 ;
struct V_325 * V_91 ;
struct V_286 * V_326 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_91 = F_67 ( sizeof *V_91 , V_16 ) ;
V_326 = F_67 ( sizeof *V_326 , V_16 ) ;
if ( ! V_91 || ! V_326 ) {
V_15 = - V_156 ;
goto V_197;
}
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_15 = - V_65 ;
goto V_197;
}
V_15 = F_120 ( V_39 , V_91 , V_52 . V_327 , V_326 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
goto V_197;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_328 = V_91 -> V_328 ;
V_54 . V_329 = V_91 -> V_329 ;
V_54 . V_330 = V_91 -> V_330 ;
V_54 . V_331 = V_91 -> V_331 ;
V_54 . V_332 = V_91 -> V_332 ;
V_54 . V_333 = V_91 -> V_333 ;
V_54 . V_334 = V_91 -> V_334 ;
V_54 . V_335 = V_91 -> V_335 ;
V_54 . V_336 = V_91 -> V_336 ;
V_54 . V_265 = V_91 -> V_265 ;
V_54 . V_337 = V_91 -> V_337 ;
V_54 . V_338 = V_91 -> V_338 ;
V_54 . V_339 = V_91 -> V_339 ;
V_54 . V_340 = V_91 -> V_340 ;
V_54 . V_341 = V_91 -> V_341 ;
V_54 . V_134 = V_91 -> V_134 ;
V_54 . V_342 = V_91 -> V_342 ;
V_54 . V_343 = V_91 -> V_343 ;
V_54 . V_344 = V_91 -> V_344 ;
V_54 . V_345 = V_91 -> V_345 ;
V_54 . V_346 = V_91 -> V_346 ;
memcpy ( V_54 . V_248 . V_347 , V_91 -> V_348 . V_349 . V_347 . V_350 , 16 ) ;
V_54 . V_248 . V_351 = V_91 -> V_348 . V_349 . V_351 ;
V_54 . V_248 . V_352 = V_91 -> V_348 . V_349 . V_352 ;
V_54 . V_248 . V_353 = V_91 -> V_348 . V_349 . V_353 ;
V_54 . V_248 . V_354 = V_91 -> V_348 . V_349 . V_354 ;
V_54 . V_248 . V_355 = V_91 -> V_348 . V_355 ;
V_54 . V_248 . V_267 = V_91 -> V_348 . V_267 ;
V_54 . V_248 . V_356 = V_91 -> V_348 . V_356 ;
V_54 . V_248 . V_357 = V_91 -> V_348 . V_357 ;
V_54 . V_248 . V_358 = ! ! ( V_91 -> V_348 . V_359 & V_360 ) ;
V_54 . V_248 . V_134 = V_91 -> V_348 . V_134 ;
memcpy ( V_54 . V_361 . V_347 , V_91 -> V_362 . V_349 . V_347 . V_350 , 16 ) ;
V_54 . V_361 . V_351 = V_91 -> V_362 . V_349 . V_351 ;
V_54 . V_361 . V_352 = V_91 -> V_362 . V_349 . V_352 ;
V_54 . V_361 . V_353 = V_91 -> V_362 . V_349 . V_353 ;
V_54 . V_361 . V_354 = V_91 -> V_362 . V_349 . V_354 ;
V_54 . V_361 . V_355 = V_91 -> V_362 . V_355 ;
V_54 . V_361 . V_267 = V_91 -> V_362 . V_267 ;
V_54 . V_361 . V_356 = V_91 -> V_362 . V_356 ;
V_54 . V_361 . V_357 = V_91 -> V_362 . V_357 ;
V_54 . V_361 . V_358 = ! ! ( V_91 -> V_362 . V_359 & V_360 ) ;
V_54 . V_361 . V_134 = V_91 -> V_362 . V_134 ;
V_54 . V_312 = V_326 -> V_311 . V_312 ;
V_54 . V_295 = V_326 -> V_311 . V_295 ;
V_54 . V_313 = V_326 -> V_311 . V_313 ;
V_54 . V_296 = V_326 -> V_311 . V_296 ;
V_54 . V_314 = V_326 -> V_311 . V_314 ;
V_54 . V_307 = V_326 -> V_306 == V_308 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_197:
F_6 ( V_91 ) ;
F_6 ( V_326 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_121 ( enum V_363 V_287 , int V_364 )
{
switch ( V_287 ) {
case V_294 :
return V_364 & ~ ( V_365 | V_366 ) ;
case V_293 :
return V_364 & ~ ( V_367 | V_368 |
V_369 ) ;
default:
return V_364 ;
}
}
T_2 F_122 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_122 V_52 ;
struct V_55 V_56 ;
struct V_36 * V_39 ;
struct V_325 * V_91 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 , NULL , V_50 - sizeof V_52 ,
V_51 ) ;
V_91 = F_67 ( sizeof *V_91 , V_16 ) ;
if ( ! V_91 )
return - V_156 ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 ) {
V_15 = - V_65 ;
goto V_197;
}
V_91 -> V_328 = V_52 . V_328 ;
V_91 -> V_329 = V_52 . V_329 ;
V_91 -> V_330 = V_52 . V_330 ;
V_91 -> V_331 = V_52 . V_331 ;
V_91 -> V_332 = V_52 . V_332 ;
V_91 -> V_333 = V_52 . V_333 ;
V_91 -> V_334 = V_52 . V_334 ;
V_91 -> V_335 = V_52 . V_335 ;
V_91 -> V_336 = V_52 . V_336 ;
V_91 -> V_265 = V_52 . V_265 ;
V_91 -> V_337 = V_52 . V_337 ;
V_91 -> V_370 = V_52 . V_370 ;
V_91 -> V_339 = V_52 . V_339 ;
V_91 -> V_340 = V_52 . V_340 ;
V_91 -> V_341 = V_52 . V_341 ;
V_91 -> V_134 = V_52 . V_134 ;
V_91 -> V_342 = V_52 . V_342 ;
V_91 -> V_343 = V_52 . V_343 ;
V_91 -> V_344 = V_52 . V_344 ;
V_91 -> V_345 = V_52 . V_345 ;
V_91 -> V_346 = V_52 . V_346 ;
memcpy ( V_91 -> V_348 . V_349 . V_347 . V_350 , V_52 . V_248 . V_347 , 16 ) ;
V_91 -> V_348 . V_349 . V_351 = V_52 . V_248 . V_351 ;
V_91 -> V_348 . V_349 . V_352 = V_52 . V_248 . V_352 ;
V_91 -> V_348 . V_349 . V_353 = V_52 . V_248 . V_353 ;
V_91 -> V_348 . V_349 . V_354 = V_52 . V_248 . V_354 ;
V_91 -> V_348 . V_355 = V_52 . V_248 . V_355 ;
V_91 -> V_348 . V_267 = V_52 . V_248 . V_267 ;
V_91 -> V_348 . V_356 = V_52 . V_248 . V_356 ;
V_91 -> V_348 . V_357 = V_52 . V_248 . V_357 ;
V_91 -> V_348 . V_359 = V_52 . V_248 . V_358 ? V_360 : 0 ;
V_91 -> V_348 . V_134 = V_52 . V_248 . V_134 ;
memcpy ( V_91 -> V_362 . V_349 . V_347 . V_350 , V_52 . V_361 . V_347 , 16 ) ;
V_91 -> V_362 . V_349 . V_351 = V_52 . V_361 . V_351 ;
V_91 -> V_362 . V_349 . V_352 = V_52 . V_361 . V_352 ;
V_91 -> V_362 . V_349 . V_353 = V_52 . V_361 . V_353 ;
V_91 -> V_362 . V_349 . V_354 = V_52 . V_361 . V_354 ;
V_91 -> V_362 . V_355 = V_52 . V_361 . V_355 ;
V_91 -> V_362 . V_267 = V_52 . V_361 . V_267 ;
V_91 -> V_362 . V_356 = V_52 . V_361 . V_356 ;
V_91 -> V_362 . V_357 = V_52 . V_361 . V_357 ;
V_91 -> V_362 . V_359 = V_52 . V_361 . V_358 ? V_360 : 0 ;
V_91 -> V_362 . V_134 = V_52 . V_361 . V_134 ;
if ( V_39 -> V_319 == V_39 ) {
V_15 = V_39 -> V_59 -> V_371 ( V_39 , V_91 ,
F_121 ( V_39 -> V_287 , V_52 . V_327 ) , & V_56 ) ;
} else {
V_15 = F_123 ( V_39 , V_91 , F_121 ( V_39 -> V_287 , V_52 . V_327 ) ) ;
}
F_39 ( V_39 ) ;
if ( V_15 )
goto V_197;
V_15 = V_50 ;
V_197:
F_6 ( V_91 ) ;
return V_15 ;
}
T_2 F_124 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_124 V_52 ;
struct V_372 V_54 ;
struct V_1 * V_2 ;
struct V_36 * V_39 ;
struct V_281 * V_180 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_2 = F_28 ( & V_38 , V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_39 = V_2 -> V_22 ;
V_180 = F_7 ( V_2 , struct V_281 , V_291 . V_27 ) ;
if ( ! F_125 ( & V_180 -> V_317 ) ) {
F_12 ( V_2 ) ;
return - V_198 ;
}
V_15 = F_116 ( V_39 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_38 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_162 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_126 ( V_48 , & V_180 -> V_291 ) ;
V_54 . V_315 = V_180 -> V_291 . V_315 ;
F_8 ( V_2 ) ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_127 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_127 V_52 ;
struct V_373 V_54 ;
struct V_374 * V_375 ;
struct V_376 * V_377 = NULL , * V_378 , * V_379 , * V_380 ;
struct V_36 * V_39 ;
int V_381 , V_382 ;
int V_383 ;
T_2 V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
if ( V_50 < sizeof V_52 + V_52 . V_384 * V_52 . V_385 +
V_52 . V_386 * sizeof ( struct V_387 ) )
return - V_65 ;
if ( V_52 . V_384 < sizeof ( struct V_374 ) )
return - V_65 ;
V_375 = F_67 ( V_52 . V_384 , V_16 ) ;
if ( ! V_375 )
return - V_156 ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
goto V_197;
V_383 = V_39 -> V_287 == V_388 ;
V_382 = 0 ;
V_378 = NULL ;
for ( V_381 = 0 ; V_381 < V_52 . V_385 ; ++ V_381 ) {
if ( F_46 ( V_375 ,
V_49 + sizeof V_52 + V_381 * V_52 . V_384 ,
V_52 . V_384 ) ) {
V_15 = - V_64 ;
goto V_275;
}
if ( V_375 -> V_389 + V_382 > V_52 . V_386 ) {
V_15 = - V_65 ;
goto V_275;
}
V_379 = F_67 ( F_128 ( sizeof *V_379 , sizeof ( struct V_390 ) ) +
V_375 -> V_389 * sizeof ( struct V_390 ) ,
V_16 ) ;
if ( ! V_379 ) {
V_15 = - V_156 ;
goto V_275;
}
if ( ! V_378 )
V_377 = V_379 ;
else
V_378 -> V_379 = V_379 ;
V_378 = V_379 ;
V_379 -> V_379 = NULL ;
V_379 -> V_253 = V_375 -> V_253 ;
V_379 -> V_389 = V_375 -> V_389 ;
V_379 -> V_255 = V_375 -> V_255 ;
V_379 -> V_391 = V_375 -> V_391 ;
if ( V_383 ) {
V_379 -> V_377 . V_392 . V_35 = F_35 ( V_375 -> V_377 . V_392 . V_35 ,
V_48 -> V_61 ) ;
if ( ! V_379 -> V_377 . V_392 . V_35 ) {
V_15 = - V_65 ;
goto V_275;
}
V_379 -> V_377 . V_392 . V_393 = V_375 -> V_377 . V_392 . V_393 ;
V_379 -> V_377 . V_392 . V_394 = V_375 -> V_377 . V_392 . V_394 ;
} else {
switch ( V_379 -> V_255 ) {
case V_395 :
V_379 -> V_258 . V_259 =
( V_396 V_261 ) V_375 -> V_258 . V_259 ;
case V_397 :
case V_398 :
V_379 -> V_377 . V_399 . V_400 =
V_375 -> V_377 . V_399 . V_400 ;
V_379 -> V_377 . V_399 . V_216 =
V_375 -> V_377 . V_399 . V_216 ;
break;
case V_401 :
V_379 -> V_258 . V_259 =
( V_396 V_261 ) V_375 -> V_258 . V_259 ;
break;
case V_402 :
V_379 -> V_258 . V_403 =
V_375 -> V_258 . V_403 ;
break;
case V_404 :
case V_405 :
V_379 -> V_377 . V_406 . V_400 =
V_375 -> V_377 . V_406 . V_400 ;
V_379 -> V_377 . V_406 . V_407 =
V_375 -> V_377 . V_406 . V_407 ;
V_379 -> V_377 . V_406 . V_408 = V_375 -> V_377 . V_406 . V_408 ;
V_379 -> V_377 . V_406 . V_216 = V_375 -> V_377 . V_406 . V_216 ;
break;
default:
break;
}
}
if ( V_379 -> V_389 ) {
V_379 -> V_409 = ( void * ) V_379 +
F_128 ( sizeof *V_379 , sizeof ( struct V_390 ) ) ;
if ( F_46 ( V_379 -> V_409 ,
V_49 + sizeof V_52 +
V_52 . V_385 * V_52 . V_384 +
V_382 * sizeof ( struct V_390 ) ,
V_379 -> V_389 * sizeof ( struct V_390 ) ) ) {
V_15 = - V_64 ;
goto V_275;
}
V_382 += V_379 -> V_389 ;
} else
V_379 -> V_409 = NULL ;
}
V_54 . V_380 = 0 ;
V_15 = V_39 -> V_59 -> V_410 ( V_39 -> V_319 , V_377 , & V_380 ) ;
if ( V_15 )
for ( V_379 = V_377 ; V_379 ; V_379 = V_379 -> V_379 ) {
++ V_54 . V_380 ;
if ( V_379 == V_380 )
break;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_275:
F_39 ( V_39 ) ;
while ( V_377 ) {
if ( V_383 && V_377 -> V_377 . V_392 . V_35 )
F_36 ( V_377 -> V_377 . V_392 . V_35 ) ;
V_379 = V_377 -> V_379 ;
F_6 ( V_377 ) ;
V_377 = V_379 ;
}
V_197:
F_6 ( V_375 ) ;
return V_15 ? V_15 : V_50 ;
}
static struct V_411 * F_129 ( const char T_3 * V_49 ,
int V_50 ,
T_5 V_385 ,
T_5 V_386 ,
T_5 V_384 )
{
struct V_412 * V_375 ;
struct V_411 * V_377 = NULL , * V_378 , * V_379 ;
int V_382 ;
int V_381 ;
int V_15 ;
if ( V_50 < V_384 * V_385 +
V_386 * sizeof ( struct V_387 ) )
return F_130 ( - V_65 ) ;
if ( V_384 < sizeof ( struct V_412 ) )
return F_130 ( - V_65 ) ;
V_375 = F_67 ( V_384 , V_16 ) ;
if ( ! V_375 )
return F_130 ( - V_156 ) ;
V_382 = 0 ;
V_378 = NULL ;
for ( V_381 = 0 ; V_381 < V_385 ; ++ V_381 ) {
if ( F_46 ( V_375 , V_49 + V_381 * V_384 ,
V_384 ) ) {
V_15 = - V_64 ;
goto V_66;
}
if ( V_375 -> V_389 + V_382 > V_386 ) {
V_15 = - V_65 ;
goto V_66;
}
V_379 = F_67 ( F_128 ( sizeof *V_379 , sizeof ( struct V_390 ) ) +
V_375 -> V_389 * sizeof ( struct V_390 ) ,
V_16 ) ;
if ( ! V_379 ) {
V_15 = - V_156 ;
goto V_66;
}
if ( ! V_378 )
V_377 = V_379 ;
else
V_378 -> V_379 = V_379 ;
V_378 = V_379 ;
V_379 -> V_379 = NULL ;
V_379 -> V_253 = V_375 -> V_253 ;
V_379 -> V_389 = V_375 -> V_389 ;
if ( V_379 -> V_389 ) {
V_379 -> V_409 = ( void * ) V_379 +
F_128 ( sizeof *V_379 , sizeof ( struct V_390 ) ) ;
if ( F_46 ( V_379 -> V_409 ,
V_49 + V_385 * V_384 +
V_382 * sizeof ( struct V_390 ) ,
V_379 -> V_389 * sizeof ( struct V_390 ) ) ) {
V_15 = - V_64 ;
goto V_66;
}
V_382 += V_379 -> V_389 ;
} else
V_379 -> V_409 = NULL ;
}
F_6 ( V_375 ) ;
return V_377 ;
V_66:
F_6 ( V_375 ) ;
while ( V_377 ) {
V_379 = V_377 -> V_379 ;
F_6 ( V_377 ) ;
V_377 = V_379 ;
}
return F_130 ( V_15 ) ;
}
T_2 F_131 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_131 V_52 ;
struct V_413 V_54 ;
struct V_411 * V_377 , * V_379 , * V_380 ;
struct V_36 * V_39 ;
T_2 V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_377 = F_129 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_385 ,
V_52 . V_386 , V_52 . V_384 ) ;
if ( F_49 ( V_377 ) )
return F_50 ( V_377 ) ;
V_39 = F_37 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
goto V_197;
V_54 . V_380 = 0 ;
V_15 = V_39 -> V_59 -> V_414 ( V_39 -> V_319 , V_377 , & V_380 ) ;
F_39 ( V_39 ) ;
if ( V_15 )
for ( V_379 = V_377 ; V_379 ; V_379 = V_379 -> V_379 ) {
++ V_54 . V_380 ;
if ( V_379 == V_380 )
break;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_197:
while ( V_377 ) {
V_379 = V_377 -> V_379 ;
F_6 ( V_377 ) ;
V_377 = V_379 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_132 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_132 V_52 ;
struct V_415 V_54 ;
struct V_411 * V_377 , * V_379 , * V_380 ;
struct V_40 * V_43 ;
T_2 V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_377 = F_129 ( V_49 + sizeof V_52 ,
V_50 - sizeof V_52 , V_52 . V_385 ,
V_52 . V_386 , V_52 . V_384 ) ;
if ( F_49 ( V_377 ) )
return F_50 ( V_377 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
goto V_197;
V_54 . V_380 = 0 ;
V_15 = V_43 -> V_59 -> V_416 ( V_43 , V_377 , & V_380 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
for ( V_379 = V_377 ; V_379 ; V_379 = V_379 -> V_379 ) {
++ V_54 . V_380 ;
if ( V_379 == V_380 )
break;
}
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
V_197:
while ( V_377 ) {
V_379 = V_377 -> V_379 ;
F_6 ( V_377 ) ;
V_377 = V_379 ;
}
return V_15 ? V_15 : V_50 ;
}
T_2 F_133 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_133 V_52 ;
struct V_417 V_54 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_32 * V_35 ;
struct V_418 V_91 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_67 ( sizeof *V_2 , V_16 ) ;
if ( ! V_2 )
return - V_156 ;
F_1 ( V_2 , V_52 . V_3 , V_48 -> V_61 , & V_419 ) ;
F_29 ( & V_2 -> V_9 ) ;
V_26 = F_31 ( V_52 . V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_66;
}
V_91 . V_355 = V_52 . V_91 . V_355 ;
V_91 . V_267 = V_52 . V_91 . V_267 ;
V_91 . V_356 = V_52 . V_91 . V_356 ;
V_91 . V_357 = V_52 . V_91 . V_357 ;
V_91 . V_359 = V_52 . V_91 . V_358 ? V_360 : 0 ;
V_91 . V_134 = V_52 . V_91 . V_134 ;
V_91 . V_349 . V_351 = V_52 . V_91 . V_349 . V_351 ;
V_91 . V_349 . V_352 = V_52 . V_91 . V_349 . V_352 ;
V_91 . V_349 . V_353 = V_52 . V_91 . V_349 . V_353 ;
V_91 . V_349 . V_354 = V_52 . V_91 . V_349 . V_354 ;
memcpy ( V_91 . V_349 . V_347 . V_350 , V_52 . V_91 . V_349 . V_347 , 16 ) ;
V_35 = F_134 ( V_26 , & V_91 ) ;
if ( F_49 ( V_35 ) ) {
V_15 = F_50 ( V_35 ) ;
goto V_212;
}
V_35 -> V_27 = V_2 ;
V_2 -> V_22 = V_35 ;
V_15 = F_14 ( & V_34 , V_2 ) ;
if ( V_15 )
goto V_320;
V_54 . V_33 = V_2 -> V_19 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_161;
}
F_32 ( V_26 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_2 -> V_162 , & V_48 -> V_61 -> V_75 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_50 ;
V_161:
F_20 ( & V_34 , V_2 ) ;
V_320:
F_135 ( V_35 ) ;
V_212:
F_32 ( V_26 ) ;
V_66:
F_12 ( V_2 ) ;
return V_15 ;
}
T_2 F_136 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct F_136 V_52 ;
struct V_32 * V_35 ;
struct V_1 * V_2 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_34 , V_52 . V_33 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_35 = V_2 -> V_22 ;
V_15 = F_135 ( V_35 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_34 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_162 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_50 ;
}
T_2 F_137 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_137 V_52 ;
struct V_36 * V_39 ;
struct V_281 * V_180 ;
struct V_420 * V_421 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
return - V_65 ;
V_180 = F_7 ( V_39 -> V_27 , struct V_281 , V_291 . V_27 ) ;
F_138 (mcast, &obj->mcast_list, list)
if ( V_52 . V_422 == V_421 -> V_144 &&
! memcmp ( V_52 . V_423 , V_421 -> V_423 . V_350 , sizeof V_421 -> V_423 . V_350 ) ) {
V_15 = 0 ;
goto V_275;
}
V_421 = F_67 ( sizeof *V_421 , V_16 ) ;
if ( ! V_421 ) {
V_15 = - V_156 ;
goto V_275;
}
V_421 -> V_144 = V_52 . V_422 ;
memcpy ( V_421 -> V_423 . V_350 , V_52 . V_423 , sizeof V_421 -> V_423 . V_350 ) ;
V_15 = F_139 ( V_39 , & V_421 -> V_423 , V_52 . V_422 ) ;
if ( ! V_15 )
F_69 ( & V_421 -> V_162 , & V_180 -> V_317 ) ;
else
F_6 ( V_421 ) ;
V_275:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_140 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_140 V_52 ;
struct V_281 * V_180 ;
struct V_36 * V_39 ;
struct V_420 * V_421 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_39 = F_38 ( V_52 . V_37 , V_48 -> V_61 ) ;
if ( ! V_39 )
return - V_65 ;
V_15 = F_141 ( V_39 , (union V_424 * ) V_52 . V_423 , V_52 . V_422 ) ;
if ( V_15 )
goto V_275;
V_180 = F_7 ( V_39 -> V_27 , struct V_281 , V_291 . V_27 ) ;
F_138 (mcast, &obj->mcast_list, list)
if ( V_52 . V_422 == V_421 -> V_144 &&
! memcmp ( V_52 . V_423 , V_421 -> V_423 . V_350 , sizeof V_421 -> V_423 . V_350 ) ) {
F_72 ( & V_421 -> V_162 ) ;
F_6 ( V_421 ) ;
break;
}
V_275:
F_40 ( V_39 ) ;
return V_15 ? V_15 : V_50 ;
}
static int F_142 ( struct V_47 * V_48 ,
struct V_425 * V_52 ,
struct V_55 * V_56 )
{
struct V_426 V_54 ;
struct V_427 * V_180 ;
struct V_23 * V_26 ;
struct V_40 * V_43 ;
struct V_1 * V_282 ( V_283 ) ;
struct V_428 V_91 ;
int V_15 ;
V_180 = F_67 ( sizeof *V_180 , V_16 ) ;
if ( ! V_180 )
return - V_156 ;
F_1 ( & V_180 -> V_291 . V_27 , V_52 -> V_3 , V_48 -> V_61 , & V_429 ) ;
F_29 ( & V_180 -> V_291 . V_27 . V_9 ) ;
if ( V_52 -> V_298 == V_430 ) {
V_91 . V_431 . V_432 . V_166 = F_43 ( V_52 -> V_45 , V_48 -> V_61 , & V_283 ) ;
if ( ! V_91 . V_431 . V_432 . V_166 ) {
V_15 = - V_65 ;
goto V_66;
}
V_180 -> V_433 = F_7 ( V_283 , struct V_179 , V_27 ) ;
F_87 ( & V_180 -> V_433 -> V_195 ) ;
V_91 . V_431 . V_432 . V_31 = F_33 ( V_52 -> V_29 , V_48 -> V_61 , 0 ) ;
if ( ! V_91 . V_431 . V_432 . V_31 ) {
V_15 = - V_65 ;
goto V_434;
}
}
V_26 = F_31 ( V_52 -> V_24 , V_48 -> V_61 ) ;
if ( ! V_26 ) {
V_15 = - V_65 ;
goto V_435;
}
V_91 . V_86 = V_436 ;
V_91 . V_437 = V_48 ;
V_91 . V_298 = V_52 -> V_298 ;
V_91 . V_91 . V_438 = V_52 -> V_438 ;
V_91 . V_91 . V_103 = V_52 -> V_103 ;
V_91 . V_91 . V_439 = V_52 -> V_439 ;
V_180 -> V_291 . V_315 = 0 ;
F_51 ( & V_180 -> V_291 . V_316 ) ;
V_43 = V_26 -> V_59 -> V_440 ( V_26 , & V_91 , V_56 ) ;
if ( F_49 ( V_43 ) ) {
V_15 = F_50 ( V_43 ) ;
goto V_212;
}
V_43 -> V_59 = V_26 -> V_59 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_298 = V_52 -> V_298 ;
V_43 -> V_27 = & V_180 -> V_291 . V_27 ;
V_43 -> V_86 = V_91 . V_86 ;
V_43 -> V_437 = V_91 . V_437 ;
if ( V_52 -> V_298 == V_430 ) {
V_43 -> V_431 . V_432 . V_31 = V_91 . V_431 . V_432 . V_31 ;
V_43 -> V_431 . V_432 . V_166 = V_91 . V_431 . V_432 . V_166 ;
F_87 ( & V_91 . V_431 . V_432 . V_31 -> V_159 ) ;
F_87 ( & V_91 . V_431 . V_432 . V_166 -> V_159 ) ;
}
F_87 ( & V_26 -> V_159 ) ;
F_68 ( & V_43 -> V_159 , 0 ) ;
V_180 -> V_291 . V_27 . V_22 = V_43 ;
V_15 = F_14 ( & V_42 , & V_180 -> V_291 . V_27 ) ;
if ( V_15 )
goto V_320;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_41 = V_180 -> V_291 . V_27 . V_19 ;
V_54 . V_438 = V_91 . V_91 . V_438 ;
V_54 . V_103 = V_91 . V_91 . V_103 ;
if ( V_52 -> V_298 == V_430 )
V_54 . V_441 = V_43 -> V_431 . V_432 . V_442 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 -> V_67 ,
& V_54 , sizeof V_54 ) ) {
V_15 = - V_64 ;
goto V_161;
}
if ( V_52 -> V_298 == V_430 ) {
F_10 ( V_283 ) ;
F_34 ( V_91 . V_431 . V_432 . V_31 ) ;
}
F_32 ( V_26 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_69 ( & V_180 -> V_291 . V_27 . V_162 , & V_48 -> V_61 -> V_74 ) ;
F_58 ( & V_48 -> V_9 ) ;
V_180 -> V_291 . V_27 . V_12 = 1 ;
F_13 ( & V_180 -> V_291 . V_27 . V_9 ) ;
return 0 ;
V_161:
F_20 ( & V_42 , & V_180 -> V_291 . V_27 ) ;
V_320:
F_143 ( V_43 ) ;
V_212:
F_32 ( V_26 ) ;
V_435:
if ( V_52 -> V_298 == V_430 )
F_34 ( V_91 . V_431 . V_432 . V_31 ) ;
V_434:
if ( V_52 -> V_298 == V_430 ) {
F_89 ( & V_180 -> V_433 -> V_195 ) ;
F_10 ( V_283 ) ;
}
V_66:
F_12 ( & V_180 -> V_291 . V_27 ) ;
return V_15 ;
}
T_2 F_144 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_144 V_52 ;
struct V_425 V_443 ;
struct V_426 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_443 . V_67 = V_52 . V_67 ;
V_443 . V_3 = V_52 . V_3 ;
V_443 . V_298 = V_299 ;
V_443 . V_24 = V_52 . V_24 ;
V_443 . V_438 = V_52 . V_438 ;
V_443 . V_103 = V_52 . V_103 ;
V_443 . V_439 = V_52 . V_439 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_142 ( V_48 , & V_443 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 V_425 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 , int V_51 )
{
struct V_425 V_52 ;
struct V_426 V_54 ;
struct V_55 V_56 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 ,
( unsigned long ) V_52 . V_67 + sizeof V_54 ,
V_50 - sizeof V_52 , V_51 - sizeof V_54 ) ;
V_15 = F_142 ( V_48 , & V_52 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return V_50 ;
}
T_2 F_145 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_145 V_52 ;
struct V_55 V_56 ;
struct V_40 * V_43 ;
struct V_444 V_91 ;
int V_15 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
F_48 ( & V_56 , V_49 + sizeof V_52 , NULL , V_50 - sizeof V_52 ,
V_51 ) ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
return - V_65 ;
V_91 . V_438 = V_52 . V_438 ;
V_91 . V_439 = V_52 . V_439 ;
V_15 = V_43 -> V_59 -> V_445 ( V_43 , & V_91 , V_52 . V_327 , & V_56 ) ;
F_42 ( V_43 ) ;
return V_15 ? V_15 : V_50 ;
}
T_2 F_146 ( struct V_47 * V_48 ,
const char T_3 * V_49 ,
int V_50 , int V_51 )
{
struct F_146 V_52 ;
struct V_446 V_54 ;
struct V_444 V_91 ;
struct V_40 * V_43 ;
int V_15 ;
if ( V_51 < sizeof V_54 )
return - V_63 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_43 = F_41 ( V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_43 )
return - V_65 ;
V_15 = F_147 ( V_43 , & V_91 ) ;
F_42 ( V_43 ) ;
if ( V_15 )
return V_15 ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_438 = V_91 . V_438 ;
V_54 . V_103 = V_91 . V_103 ;
V_54 . V_439 = V_91 . V_439 ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
return - V_64 ;
return V_50 ;
}
T_2 F_148 ( struct V_47 * V_48 ,
const char T_3 * V_49 , int V_50 ,
int V_51 )
{
struct F_148 V_52 ;
struct V_447 V_54 ;
struct V_1 * V_2 ;
struct V_40 * V_43 ;
struct V_448 * V_180 ;
int V_15 = - V_65 ;
if ( F_46 ( & V_52 , V_49 , sizeof V_52 ) )
return - V_64 ;
V_2 = F_28 ( & V_42 , V_52 . V_41 , V_48 -> V_61 ) ;
if ( ! V_2 )
return - V_65 ;
V_43 = V_2 -> V_22 ;
V_180 = F_7 ( V_2 , struct V_448 , V_27 ) ;
V_15 = F_143 ( V_43 ) ;
if ( ! V_15 )
V_2 -> V_12 = 0 ;
F_12 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_20 ( & V_42 , V_2 ) ;
F_47 ( & V_48 -> V_9 ) ;
F_72 ( & V_2 -> V_162 ) ;
F_58 ( & V_48 -> V_9 ) ;
F_126 ( V_48 , V_180 ) ;
memset ( & V_54 , 0 , sizeof V_54 ) ;
V_54 . V_315 = V_180 -> V_315 ;
F_8 ( V_2 ) ;
if ( F_54 ( ( void T_3 * ) ( unsigned long ) V_52 . V_67 ,
& V_54 , sizeof V_54 ) )
V_15 = - V_64 ;
return V_15 ? V_15 : V_50 ;
}
