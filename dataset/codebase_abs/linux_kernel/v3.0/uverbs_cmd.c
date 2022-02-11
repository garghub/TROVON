static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
F_2 ( & V_2 -> V_8 ) ;
F_3 ( & V_2 -> V_9 ) ;
F_4 ( & V_2 -> V_9 , V_7 ) ;
V_2 -> V_10 = 0 ;
}
static void F_5 ( struct V_11 * V_11 )
{
F_6 ( F_7 ( V_11 , struct V_1 , V_8 ) ) ;
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
static int F_14 ( struct V_12 * V_12 , struct V_1 * V_2 )
{
int V_13 ;
V_14:
if ( ! F_15 ( V_12 , V_15 ) )
return - V_16 ;
F_16 ( & V_17 ) ;
V_13 = F_17 ( V_12 , V_2 , & V_2 -> V_18 ) ;
F_18 ( & V_17 ) ;
if ( V_13 == - V_19 )
goto V_14;
return V_13 ;
}
void F_19 ( struct V_12 * V_12 , struct V_1 * V_2 )
{
F_16 ( & V_17 ) ;
F_20 ( V_12 , V_2 -> V_18 ) ;
F_18 ( & V_17 ) ;
}
static struct V_1 * F_21 ( struct V_12 * V_12 , int V_18 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_16 ( & V_17 ) ;
V_2 = F_22 ( V_12 , V_18 ) ;
if ( V_2 ) {
if ( V_2 -> V_5 == V_5 )
F_23 ( & V_2 -> V_8 ) ;
else
V_2 = NULL ;
}
F_18 ( & V_17 ) ;
return V_2 ;
}
static struct V_1 * F_24 ( struct V_12 * V_12 , int V_18 ,
struct V_4 * V_5 , int V_20 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_12 , V_18 , V_5 ) ;
if ( ! V_2 )
return NULL ;
if ( V_20 )
F_25 ( & V_2 -> V_9 , V_21 ) ;
else
F_26 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_10 ) {
F_10 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_1 * F_27 ( struct V_12 * V_12 , int V_18 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_12 , V_18 , V_5 ) ;
if ( ! V_2 )
return NULL ;
F_28 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_10 ) {
F_12 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static void * F_29 ( struct V_12 * V_12 , int V_18 , struct V_4 * V_5 ,
int V_20 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( V_12 , V_18 , V_5 , V_20 ) ;
return V_2 ? V_2 -> V_22 : NULL ;
}
static struct V_23 * F_30 ( int V_24 , struct V_4 * V_5 )
{
return F_29 ( & V_25 , V_24 , V_5 , 0 ) ;
}
static void F_31 ( struct V_23 * V_26 )
{
F_10 ( V_26 -> V_27 ) ;
}
static struct V_28 * F_32 ( int V_29 , struct V_4 * V_5 , int V_20 )
{
return F_29 ( & V_30 , V_29 , V_5 , V_20 ) ;
}
static void F_33 ( struct V_28 * V_31 )
{
F_10 ( V_31 -> V_27 ) ;
}
static struct V_32 * F_34 ( int V_33 , struct V_4 * V_5 )
{
return F_29 ( & V_34 , V_33 , V_5 , 0 ) ;
}
static void F_35 ( struct V_32 * V_35 )
{
F_10 ( V_35 -> V_27 ) ;
}
static struct V_36 * F_36 ( int V_37 , struct V_4 * V_5 )
{
return F_29 ( & V_38 , V_37 , V_5 , 0 ) ;
}
static void F_37 ( struct V_36 * V_39 )
{
F_10 ( V_39 -> V_27 ) ;
}
static struct V_40 * F_38 ( int V_41 , struct V_4 * V_5 )
{
return F_29 ( & V_42 , V_41 , V_5 , 0 ) ;
}
static void F_39 ( struct V_40 * V_43 )
{
F_10 ( V_43 -> V_27 ) ;
}
T_2 F_40 ( struct V_44 * V_45 ,
const char T_3 * V_46 ,
int V_47 , int V_48 )
{
struct F_40 V_49 ;
struct V_50 V_51 ;
struct V_52 V_53 ;
struct V_54 * V_55 = V_45 -> V_56 -> V_57 ;
struct V_4 * V_58 ;
struct V_45 * V_59 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
F_42 ( & V_45 -> V_9 ) ;
if ( V_45 -> V_58 ) {
V_13 = - V_62 ;
goto V_63;
}
F_43 ( & V_53 , V_46 + sizeof V_49 ,
( unsigned long ) V_49 . V_64 + sizeof V_51 ,
V_47 - sizeof V_49 , V_48 - sizeof V_51 ) ;
V_58 = V_55 -> V_65 ( V_55 , & V_53 ) ;
if ( F_44 ( V_58 ) ) {
V_13 = F_45 ( V_58 ) ;
goto V_63;
}
V_58 -> V_56 = V_55 ;
F_46 ( & V_58 -> V_66 ) ;
F_46 ( & V_58 -> V_67 ) ;
F_46 ( & V_58 -> V_68 ) ;
F_46 ( & V_58 -> V_69 ) ;
F_46 ( & V_58 -> V_70 ) ;
F_46 ( & V_58 -> V_71 ) ;
F_46 ( & V_58 -> V_72 ) ;
V_58 -> V_73 = 0 ;
V_51 . V_74 = V_45 -> V_56 -> V_74 ;
V_13 = F_47 () ;
if ( V_13 < 0 )
goto V_75;
V_51 . V_76 = V_13 ;
V_59 = F_48 ( V_45 , 1 ) ;
if ( F_44 ( V_59 ) ) {
V_13 = F_45 ( V_59 ) ;
goto V_77;
}
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) ) {
V_13 = - V_61 ;
goto V_78;
}
V_45 -> V_79 = V_59 -> V_80 ;
F_50 ( & V_45 -> V_81 , V_45 -> V_56 -> V_57 ,
V_82 ) ;
V_13 = F_51 ( & V_45 -> V_81 ) ;
if ( V_13 )
goto V_78;
F_23 ( & V_45 -> V_79 -> V_8 ) ;
F_23 ( & V_45 -> V_8 ) ;
V_45 -> V_58 = V_58 ;
F_52 ( V_51 . V_76 , V_59 ) ;
F_53 ( & V_45 -> V_9 ) ;
return V_47 ;
V_78:
F_54 ( V_59 ) ;
V_77:
F_55 ( V_51 . V_76 ) ;
V_75:
V_55 -> V_83 ( V_58 ) ;
V_63:
F_53 ( & V_45 -> V_9 ) ;
return V_13 ;
}
T_2 F_56 ( struct V_44 * V_45 ,
const char T_3 * V_46 ,
int V_47 , int V_48 )
{
struct F_56 V_49 ;
struct V_84 V_51 ;
struct V_85 V_86 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_13 = F_57 ( V_45 -> V_56 -> V_57 , & V_86 ) ;
if ( V_13 )
return V_13 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_87 = V_86 . V_87 ;
V_51 . V_88 = V_45 -> V_56 -> V_57 -> V_88 ;
V_51 . V_89 = V_86 . V_89 ;
V_51 . V_90 = V_86 . V_90 ;
V_51 . V_91 = V_86 . V_91 ;
V_51 . V_92 = V_86 . V_92 ;
V_51 . V_93 = V_86 . V_93 ;
V_51 . V_94 = V_86 . V_94 ;
V_51 . V_95 = V_86 . V_95 ;
V_51 . V_96 = V_86 . V_96 ;
V_51 . V_97 = V_86 . V_97 ;
V_51 . V_98 = V_86 . V_98 ;
V_51 . V_99 = V_86 . V_99 ;
V_51 . V_100 = V_86 . V_100 ;
V_51 . V_101 = V_86 . V_101 ;
V_51 . V_102 = V_86 . V_102 ;
V_51 . V_103 = V_86 . V_103 ;
V_51 . V_104 = V_86 . V_104 ;
V_51 . V_105 = V_86 . V_105 ;
V_51 . V_106 = V_86 . V_106 ;
V_51 . V_107 = V_86 . V_107 ;
V_51 . V_108 = V_86 . V_108 ;
V_51 . V_109 = V_86 . V_109 ;
V_51 . V_110 = V_86 . V_110 ;
V_51 . V_111 = V_86 . V_111 ;
V_51 . V_112 = V_86 . V_112 ;
V_51 . V_113 = V_86 . V_113 ;
V_51 . V_114 = V_86 . V_114 ;
V_51 . V_115 = V_86 . V_115 ;
V_51 . V_116 = V_86 . V_116 ;
V_51 . V_117 = V_86 . V_117 ;
V_51 . V_118 = V_86 . V_118 ;
V_51 . V_119 = V_86 . V_119 ;
V_51 . V_120 = V_86 . V_120 ;
V_51 . V_121 = V_86 . V_121 ;
V_51 . V_122 = V_86 . V_122 ;
V_51 . V_123 = V_86 . V_123 ;
V_51 . V_124 = V_86 . V_124 ;
V_51 . V_125 = V_86 . V_125 ;
V_51 . V_126 = V_45 -> V_56 -> V_57 -> V_126 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
return - V_61 ;
return V_47 ;
}
T_2 F_58 ( struct V_44 * V_45 ,
const char T_3 * V_46 ,
int V_47 , int V_48 )
{
struct F_58 V_49 ;
struct V_127 V_51 ;
struct V_128 V_86 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_13 = F_59 ( V_45 -> V_56 -> V_57 , V_49 . V_129 , & V_86 ) ;
if ( V_13 )
return V_13 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_130 = V_86 . V_130 ;
V_51 . V_131 = V_86 . V_131 ;
V_51 . V_132 = V_86 . V_132 ;
V_51 . V_133 = V_86 . V_133 ;
V_51 . V_134 = V_86 . V_134 ;
V_51 . V_135 = V_86 . V_135 ;
V_51 . V_136 = V_86 . V_136 ;
V_51 . V_137 = V_86 . V_137 ;
V_51 . V_138 = V_86 . V_138 ;
V_51 . V_139 = V_86 . V_139 ;
V_51 . V_140 = V_86 . V_140 ;
V_51 . V_141 = V_86 . V_141 ;
V_51 . V_142 = V_86 . V_142 ;
V_51 . V_143 = V_86 . V_143 ;
V_51 . V_144 = V_86 . V_144 ;
V_51 . V_145 = V_86 . V_145 ;
V_51 . V_146 = V_86 . V_146 ;
V_51 . V_147 = V_86 . V_147 ;
V_51 . V_148 = V_86 . V_148 ;
V_51 . V_149 = F_60 ( V_45 -> V_56 -> V_57 ,
V_49 . V_129 ) ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
return - V_61 ;
return V_47 ;
}
T_2 F_61 ( struct V_44 * V_45 ,
const char T_3 * V_46 ,
int V_47 , int V_48 )
{
struct F_61 V_49 ;
struct V_150 V_51 ;
struct V_52 V_53 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
F_43 ( & V_53 , V_46 + sizeof V_49 ,
( unsigned long ) V_49 . V_64 + sizeof V_51 ,
V_47 - sizeof V_49 , V_48 - sizeof V_51 ) ;
V_2 = F_62 ( sizeof *V_2 , V_15 ) ;
if ( ! V_2 )
return - V_16 ;
F_1 ( V_2 , 0 , V_45 -> V_58 , & V_151 ) ;
F_28 ( & V_2 -> V_9 ) ;
V_26 = V_45 -> V_56 -> V_57 -> V_152 ( V_45 -> V_56 -> V_57 ,
V_45 -> V_58 , & V_53 ) ;
if ( F_44 ( V_26 ) ) {
V_13 = F_45 ( V_26 ) ;
goto V_63;
}
V_26 -> V_56 = V_45 -> V_56 -> V_57 ;
V_26 -> V_27 = V_2 ;
F_63 ( & V_26 -> V_153 , 0 ) ;
V_2 -> V_22 = V_26 ;
V_13 = F_14 ( & V_25 , V_2 ) ;
if ( V_13 )
goto V_154;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_24 = V_2 -> V_18 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) ) {
V_13 = - V_61 ;
goto V_155;
}
F_42 ( & V_45 -> V_9 ) ;
F_64 ( & V_2 -> V_156 , & V_45 -> V_58 -> V_66 ) ;
F_53 ( & V_45 -> V_9 ) ;
V_2 -> V_10 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_47 ;
V_155:
F_19 ( & V_25 , V_2 ) ;
V_154:
F_65 ( V_26 ) ;
V_63:
F_12 ( V_2 ) ;
return V_13 ;
}
T_2 F_66 ( struct V_44 * V_45 ,
const char T_3 * V_46 ,
int V_47 , int V_48 )
{
struct F_66 V_49 ;
struct V_1 * V_2 ;
int V_13 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_2 = F_27 ( & V_25 , V_49 . V_24 , V_45 -> V_58 ) ;
if ( ! V_2 )
return - V_62 ;
V_13 = F_65 ( V_2 -> V_22 ) ;
if ( ! V_13 )
V_2 -> V_10 = 0 ;
F_12 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_19 ( & V_25 , V_2 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_67 ( & V_2 -> V_156 ) ;
F_53 ( & V_45 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_47 ;
}
T_2 F_68 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_68 V_49 ;
struct V_157 V_51 ;
struct V_52 V_53 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_158 * V_159 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
F_43 ( & V_53 , V_46 + sizeof V_49 ,
( unsigned long ) V_49 . V_64 + sizeof V_51 ,
V_47 - sizeof V_49 , V_48 - sizeof V_51 ) ;
if ( ( V_49 . V_160 & ~ V_161 ) != ( V_49 . V_162 & ~ V_161 ) )
return - V_62 ;
if ( V_49 . V_163 & ( V_164 | V_165 ) &&
! ( V_49 . V_163 & V_166 ) )
return - V_62 ;
V_2 = F_62 ( sizeof *V_2 , V_15 ) ;
if ( ! V_2 )
return - V_16 ;
F_1 ( V_2 , 0 , V_45 -> V_58 , & V_167 ) ;
F_28 ( & V_2 -> V_9 ) ;
V_26 = F_30 ( V_49 . V_24 , V_45 -> V_58 ) ;
if ( ! V_26 ) {
V_13 = - V_62 ;
goto V_75;
}
V_159 = V_26 -> V_56 -> V_168 ( V_26 , V_49 . V_160 , V_49 . V_169 , V_49 . V_162 ,
V_49 . V_163 , & V_53 ) ;
if ( F_44 ( V_159 ) ) {
V_13 = F_45 ( V_159 ) ;
goto V_170;
}
V_159 -> V_56 = V_26 -> V_56 ;
V_159 -> V_26 = V_26 ;
V_159 -> V_27 = V_2 ;
F_69 ( & V_26 -> V_153 ) ;
F_63 ( & V_159 -> V_153 , 0 ) ;
V_2 -> V_22 = V_159 ;
V_13 = F_14 ( & V_171 , V_2 ) ;
if ( V_13 )
goto V_172;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_173 = V_159 -> V_173 ;
V_51 . V_174 = V_159 -> V_174 ;
V_51 . V_175 = V_2 -> V_18 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) ) {
V_13 = - V_61 ;
goto V_155;
}
F_31 ( V_26 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_64 ( & V_2 -> V_156 , & V_45 -> V_58 -> V_67 ) ;
F_53 ( & V_45 -> V_9 ) ;
V_2 -> V_10 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_47 ;
V_155:
F_19 ( & V_171 , V_2 ) ;
V_172:
F_70 ( V_159 ) ;
V_170:
F_31 ( V_26 ) ;
V_75:
F_12 ( V_2 ) ;
return V_13 ;
}
T_2 F_71 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_71 V_49 ;
struct V_158 * V_159 ;
struct V_1 * V_2 ;
int V_13 = - V_62 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_2 = F_27 ( & V_171 , V_49 . V_175 , V_45 -> V_58 ) ;
if ( ! V_2 )
return - V_62 ;
V_159 = V_2 -> V_22 ;
V_13 = F_70 ( V_159 ) ;
if ( ! V_13 )
V_2 -> V_10 = 0 ;
F_12 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_19 ( & V_171 , V_2 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_67 ( & V_2 -> V_156 ) ;
F_53 ( & V_45 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_47 ;
}
T_2 F_72 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_72 V_49 ;
struct V_176 V_51 ;
struct V_45 * V_59 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_13 = F_47 () ;
if ( V_13 < 0 )
return V_13 ;
V_51 . V_177 = V_13 ;
V_59 = F_48 ( V_45 , 0 ) ;
if ( F_44 ( V_59 ) ) {
F_55 ( V_51 . V_177 ) ;
return F_45 ( V_59 ) ;
}
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) ) {
F_55 ( V_51 . V_177 ) ;
F_54 ( V_59 ) ;
return - V_61 ;
}
F_52 ( V_51 . V_177 , V_59 ) ;
return V_47 ;
}
T_2 F_73 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_73 V_49 ;
struct V_178 V_51 ;
struct V_52 V_53 ;
struct V_179 * V_180 ;
struct V_181 * V_182 = NULL ;
struct V_28 * V_31 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
F_43 ( & V_53 , V_46 + sizeof V_49 ,
( unsigned long ) V_49 . V_64 + sizeof V_51 ,
V_47 - sizeof V_49 , V_48 - sizeof V_51 ) ;
if ( V_49 . V_183 >= V_45 -> V_56 -> V_74 )
return - V_62 ;
V_180 = F_62 ( sizeof *V_180 , V_15 ) ;
if ( ! V_180 )
return - V_16 ;
F_1 ( & V_180 -> V_27 , V_49 . V_3 , V_45 -> V_58 , & V_184 ) ;
F_28 ( & V_180 -> V_27 . V_9 ) ;
if ( V_49 . V_185 >= 0 ) {
V_182 = F_74 ( V_49 . V_185 ) ;
if ( ! V_182 ) {
V_13 = - V_62 ;
goto V_63;
}
}
V_180 -> V_186 = V_45 ;
V_180 -> V_187 = 0 ;
V_180 -> V_188 = 0 ;
F_46 ( & V_180 -> V_189 ) ;
F_46 ( & V_180 -> V_190 ) ;
V_31 = V_45 -> V_56 -> V_57 -> V_191 ( V_45 -> V_56 -> V_57 , V_49 . V_192 ,
V_49 . V_183 ,
V_45 -> V_58 , & V_53 ) ;
if ( F_44 ( V_31 ) ) {
V_13 = F_45 ( V_31 ) ;
goto V_78;
}
V_31 -> V_56 = V_45 -> V_56 -> V_57 ;
V_31 -> V_27 = & V_180 -> V_27 ;
V_31 -> V_193 = V_194 ;
V_31 -> V_81 = V_195 ;
V_31 -> V_196 = V_182 ;
F_63 ( & V_31 -> V_153 , 0 ) ;
V_180 -> V_27 . V_22 = V_31 ;
V_13 = F_14 ( & V_30 , & V_180 -> V_27 ) ;
if ( V_13 )
goto V_75;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_29 = V_180 -> V_27 . V_18 ;
V_51 . V_192 = V_31 -> V_192 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) ) {
V_13 = - V_61 ;
goto V_155;
}
F_42 ( & V_45 -> V_9 ) ;
F_64 ( & V_180 -> V_27 . V_156 , & V_45 -> V_58 -> V_69 ) ;
F_53 ( & V_45 -> V_9 ) ;
V_180 -> V_27 . V_10 = 1 ;
F_13 ( & V_180 -> V_27 . V_9 ) ;
return V_47 ;
V_155:
F_19 ( & V_30 , & V_180 -> V_27 ) ;
V_75:
F_75 ( V_31 ) ;
V_78:
if ( V_182 )
F_76 ( V_45 , V_182 , V_180 ) ;
V_63:
F_12 ( & V_180 -> V_27 ) ;
return V_13 ;
}
T_2 F_77 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_77 V_49 ;
struct V_197 V_51 ;
struct V_52 V_53 ;
struct V_28 * V_31 ;
int V_13 = - V_62 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
F_43 ( & V_53 , V_46 + sizeof V_49 ,
( unsigned long ) V_49 . V_64 + sizeof V_51 ,
V_47 - sizeof V_49 , V_48 - sizeof V_51 ) ;
V_31 = F_32 ( V_49 . V_29 , V_45 -> V_58 , 0 ) ;
if ( ! V_31 )
return - V_62 ;
V_13 = V_31 -> V_56 -> V_198 ( V_31 , V_49 . V_192 , & V_53 ) ;
if ( V_13 )
goto V_199;
V_51 . V_192 = V_31 -> V_192 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 . V_192 ) )
V_13 = - V_61 ;
V_199:
F_33 ( V_31 ) ;
return V_13 ? V_13 : V_47 ;
}
static int F_78 ( void T_3 * V_200 , struct V_201 * V_202 )
{
struct V_203 V_204 ;
V_204 . V_205 = V_202 -> V_205 ;
V_204 . V_206 = V_202 -> V_206 ;
V_204 . V_207 = V_202 -> V_207 ;
V_204 . V_208 = V_202 -> V_208 ;
V_204 . V_209 = V_202 -> V_209 ;
V_204 . V_210 . V_211 = ( V_212 V_213 ) V_202 -> V_210 . V_211 ;
V_204 . V_214 = V_202 -> V_39 -> V_214 ;
V_204 . V_215 = V_202 -> V_215 ;
V_204 . V_216 = V_202 -> V_216 ;
V_204 . V_217 = V_202 -> V_217 ;
V_204 . V_218 = V_202 -> V_218 ;
V_204 . V_219 = V_202 -> V_219 ;
V_204 . V_220 = V_202 -> V_220 ;
V_204 . V_129 = V_202 -> V_129 ;
V_204 . V_221 = 0 ;
if ( F_49 ( V_200 , & V_204 , sizeof V_204 ) )
return - V_61 ;
return 0 ;
}
T_2 F_79 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_79 V_49 ;
struct V_222 V_51 ;
T_4 T_3 * V_223 ;
T_4 T_3 * V_224 ;
struct V_28 * V_31 ;
struct V_201 V_202 ;
int V_13 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_31 = F_32 ( V_49 . V_29 , V_45 -> V_58 , 0 ) ;
if ( ! V_31 )
return - V_62 ;
V_223 = ( void T_3 * ) ( unsigned long ) V_49 . V_64 ;
V_224 = V_223 + sizeof V_51 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
while ( V_51 . V_225 < V_49 . V_226 ) {
V_13 = F_80 ( V_31 , 1 , & V_202 ) ;
if ( V_13 < 0 )
goto V_227;
if ( ! V_13 )
break;
V_13 = F_78 ( V_224 , & V_202 ) ;
if ( V_13 )
goto V_227;
V_224 += sizeof( struct V_203 ) ;
++ V_51 . V_225 ;
}
if ( F_49 ( V_223 , & V_51 , sizeof V_51 ) ) {
V_13 = - V_61 ;
goto V_227;
}
V_13 = V_47 ;
V_227:
F_33 ( V_31 ) ;
return V_13 ;
}
T_2 F_81 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_81 V_49 ;
struct V_28 * V_31 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_31 = F_32 ( V_49 . V_29 , V_45 -> V_58 , 0 ) ;
if ( ! V_31 )
return - V_62 ;
F_82 ( V_31 , V_49 . V_228 ?
V_229 : V_230 ) ;
F_33 ( V_31 ) ;
return V_47 ;
}
T_2 F_83 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_83 V_49 ;
struct V_231 V_51 ;
struct V_1 * V_2 ;
struct V_28 * V_31 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
int V_13 = - V_62 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_2 = F_27 ( & V_30 , V_49 . V_29 , V_45 -> V_58 ) ;
if ( ! V_2 )
return - V_62 ;
V_31 = V_2 -> V_22 ;
V_182 = V_31 -> V_196 ;
V_180 = F_7 ( V_31 -> V_27 , struct V_179 , V_27 ) ;
V_13 = F_75 ( V_31 ) ;
if ( ! V_13 )
V_2 -> V_10 = 0 ;
F_12 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_19 ( & V_30 , V_2 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_67 ( & V_2 -> V_156 ) ;
F_53 ( & V_45 -> V_9 ) ;
F_76 ( V_45 , V_182 , V_180 ) ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_187 = V_180 -> V_187 ;
V_51 . V_188 = V_180 -> V_188 ;
F_8 ( V_2 ) ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
return - V_61 ;
return V_47 ;
}
T_2 F_84 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_84 V_49 ;
struct V_232 V_51 ;
struct V_52 V_53 ;
struct V_233 * V_180 ;
struct V_23 * V_26 ;
struct V_28 * V_234 , * V_235 ;
struct V_40 * V_43 ;
struct V_36 * V_39 ;
struct V_236 V_86 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
F_43 ( & V_53 , V_46 + sizeof V_49 ,
( unsigned long ) V_49 . V_64 + sizeof V_51 ,
V_47 - sizeof V_49 , V_48 - sizeof V_51 ) ;
V_180 = F_62 ( sizeof *V_180 , V_15 ) ;
if ( ! V_180 )
return - V_16 ;
F_1 ( & V_180 -> V_237 . V_27 , V_49 . V_3 , V_45 -> V_58 , & V_238 ) ;
F_28 ( & V_180 -> V_237 . V_27 . V_9 ) ;
V_43 = V_49 . V_239 ? F_38 ( V_49 . V_41 , V_45 -> V_58 ) : NULL ;
V_26 = F_30 ( V_49 . V_24 , V_45 -> V_58 ) ;
V_234 = F_32 ( V_49 . V_240 , V_45 -> V_58 , 0 ) ;
V_235 = V_49 . V_241 == V_49 . V_240 ?
V_234 : F_32 ( V_49 . V_241 , V_45 -> V_58 , 1 ) ;
if ( ! V_26 || ! V_234 || ! V_235 || ( V_49 . V_239 && ! V_43 ) ) {
V_13 = - V_62 ;
goto V_170;
}
V_86 . V_81 = V_242 ;
V_86 . V_243 = V_45 ;
V_86 . V_244 = V_234 ;
V_86 . V_245 = V_235 ;
V_86 . V_43 = V_43 ;
V_86 . V_246 = V_49 . V_247 ? V_248 : V_249 ;
V_86 . V_250 = V_49 . V_250 ;
V_86 . V_251 = 0 ;
V_86 . V_252 . V_253 = V_49 . V_253 ;
V_86 . V_252 . V_254 = V_49 . V_254 ;
V_86 . V_252 . V_255 = V_49 . V_255 ;
V_86 . V_252 . V_256 = V_49 . V_256 ;
V_86 . V_252 . V_257 = V_49 . V_257 ;
V_180 -> V_237 . V_258 = 0 ;
F_46 ( & V_180 -> V_237 . V_259 ) ;
F_46 ( & V_180 -> V_260 ) ;
V_39 = V_26 -> V_56 -> V_261 ( V_26 , & V_86 , & V_53 ) ;
if ( F_44 ( V_39 ) ) {
V_13 = F_45 ( V_39 ) ;
goto V_170;
}
V_39 -> V_56 = V_26 -> V_56 ;
V_39 -> V_26 = V_26 ;
V_39 -> V_244 = V_86 . V_244 ;
V_39 -> V_245 = V_86 . V_245 ;
V_39 -> V_43 = V_86 . V_43 ;
V_39 -> V_27 = & V_180 -> V_237 . V_27 ;
V_39 -> V_81 = V_86 . V_81 ;
V_39 -> V_243 = V_86 . V_243 ;
V_39 -> V_250 = V_86 . V_250 ;
F_69 ( & V_26 -> V_153 ) ;
F_69 ( & V_86 . V_244 -> V_153 ) ;
F_69 ( & V_86 . V_245 -> V_153 ) ;
if ( V_86 . V_43 )
F_69 ( & V_86 . V_43 -> V_153 ) ;
V_180 -> V_237 . V_27 . V_22 = V_39 ;
V_13 = F_14 ( & V_38 , & V_180 -> V_237 . V_27 ) ;
if ( V_13 )
goto V_262;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_263 = V_39 -> V_214 ;
V_51 . V_37 = V_180 -> V_237 . V_27 . V_18 ;
V_51 . V_256 = V_86 . V_252 . V_256 ;
V_51 . V_255 = V_86 . V_252 . V_255 ;
V_51 . V_254 = V_86 . V_252 . V_254 ;
V_51 . V_253 = V_86 . V_252 . V_253 ;
V_51 . V_257 = V_86 . V_252 . V_257 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) ) {
V_13 = - V_61 ;
goto V_155;
}
F_31 ( V_26 ) ;
F_33 ( V_234 ) ;
if ( V_235 != V_234 )
F_33 ( V_235 ) ;
if ( V_43 )
F_39 ( V_43 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_64 ( & V_180 -> V_237 . V_27 . V_156 , & V_45 -> V_58 -> V_70 ) ;
F_53 ( & V_45 -> V_9 ) ;
V_180 -> V_237 . V_27 . V_10 = 1 ;
F_13 ( & V_180 -> V_237 . V_27 . V_9 ) ;
return V_47 ;
V_155:
F_19 ( & V_38 , & V_180 -> V_237 . V_27 ) ;
V_262:
F_85 ( V_39 ) ;
V_170:
if ( V_26 )
F_31 ( V_26 ) ;
if ( V_234 )
F_33 ( V_234 ) ;
if ( V_235 && V_235 != V_234 )
F_33 ( V_235 ) ;
if ( V_43 )
F_39 ( V_43 ) ;
F_12 ( & V_180 -> V_237 . V_27 ) ;
return V_13 ;
}
T_2 F_86 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_86 V_49 ;
struct V_264 V_51 ;
struct V_36 * V_39 ;
struct V_265 * V_86 ;
struct V_236 * V_266 ;
int V_13 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_86 = F_62 ( sizeof *V_86 , V_15 ) ;
V_266 = F_62 ( sizeof *V_266 , V_15 ) ;
if ( ! V_86 || ! V_266 ) {
V_13 = - V_16 ;
goto V_199;
}
V_39 = F_36 ( V_49 . V_37 , V_45 -> V_58 ) ;
if ( ! V_39 ) {
V_13 = - V_62 ;
goto V_199;
}
V_13 = F_87 ( V_39 , V_86 , V_49 . V_267 , V_266 ) ;
F_37 ( V_39 ) ;
if ( V_13 )
goto V_199;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_268 = V_86 -> V_268 ;
V_51 . V_269 = V_86 -> V_269 ;
V_51 . V_270 = V_86 -> V_270 ;
V_51 . V_271 = V_86 -> V_271 ;
V_51 . V_272 = V_86 -> V_272 ;
V_51 . V_273 = V_86 -> V_273 ;
V_51 . V_274 = V_86 -> V_274 ;
V_51 . V_275 = V_86 -> V_275 ;
V_51 . V_276 = V_86 -> V_276 ;
V_51 . V_217 = V_86 -> V_217 ;
V_51 . V_277 = V_86 -> V_277 ;
V_51 . V_278 = V_86 -> V_278 ;
V_51 . V_279 = V_86 -> V_279 ;
V_51 . V_280 = V_86 -> V_280 ;
V_51 . V_281 = V_86 -> V_281 ;
V_51 . V_129 = V_86 -> V_129 ;
V_51 . V_282 = V_86 -> V_282 ;
V_51 . V_283 = V_86 -> V_283 ;
V_51 . V_284 = V_86 -> V_284 ;
V_51 . V_285 = V_86 -> V_285 ;
V_51 . V_286 = V_86 -> V_286 ;
memcpy ( V_51 . V_200 . V_287 , V_86 -> V_288 . V_289 . V_287 . V_290 , 16 ) ;
V_51 . V_200 . V_291 = V_86 -> V_288 . V_289 . V_291 ;
V_51 . V_200 . V_292 = V_86 -> V_288 . V_289 . V_292 ;
V_51 . V_200 . V_293 = V_86 -> V_288 . V_289 . V_293 ;
V_51 . V_200 . V_294 = V_86 -> V_288 . V_289 . V_294 ;
V_51 . V_200 . V_295 = V_86 -> V_288 . V_295 ;
V_51 . V_200 . V_219 = V_86 -> V_288 . V_219 ;
V_51 . V_200 . V_296 = V_86 -> V_288 . V_296 ;
V_51 . V_200 . V_297 = V_86 -> V_288 . V_297 ;
V_51 . V_200 . V_298 = ! ! ( V_86 -> V_288 . V_299 & V_300 ) ;
V_51 . V_200 . V_129 = V_86 -> V_288 . V_129 ;
memcpy ( V_51 . V_301 . V_287 , V_86 -> V_302 . V_289 . V_287 . V_290 , 16 ) ;
V_51 . V_301 . V_291 = V_86 -> V_302 . V_289 . V_291 ;
V_51 . V_301 . V_292 = V_86 -> V_302 . V_289 . V_292 ;
V_51 . V_301 . V_293 = V_86 -> V_302 . V_289 . V_293 ;
V_51 . V_301 . V_294 = V_86 -> V_302 . V_289 . V_294 ;
V_51 . V_301 . V_295 = V_86 -> V_302 . V_295 ;
V_51 . V_301 . V_219 = V_86 -> V_302 . V_219 ;
V_51 . V_301 . V_296 = V_86 -> V_302 . V_296 ;
V_51 . V_301 . V_297 = V_86 -> V_302 . V_297 ;
V_51 . V_301 . V_298 = ! ! ( V_86 -> V_302 . V_299 & V_300 ) ;
V_51 . V_301 . V_129 = V_86 -> V_302 . V_129 ;
V_51 . V_253 = V_266 -> V_252 . V_253 ;
V_51 . V_254 = V_266 -> V_252 . V_254 ;
V_51 . V_255 = V_266 -> V_252 . V_255 ;
V_51 . V_256 = V_266 -> V_252 . V_256 ;
V_51 . V_257 = V_266 -> V_252 . V_257 ;
V_51 . V_247 = V_266 -> V_246 == V_248 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
V_13 = - V_61 ;
V_199:
F_6 ( V_86 ) ;
F_6 ( V_266 ) ;
return V_13 ? V_13 : V_47 ;
}
T_2 F_88 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_88 V_49 ;
struct V_52 V_53 ;
struct V_36 * V_39 ;
struct V_265 * V_86 ;
int V_13 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
F_43 ( & V_53 , V_46 + sizeof V_49 , NULL , V_47 - sizeof V_49 ,
V_48 ) ;
V_86 = F_62 ( sizeof *V_86 , V_15 ) ;
if ( ! V_86 )
return - V_16 ;
V_39 = F_36 ( V_49 . V_37 , V_45 -> V_58 ) ;
if ( ! V_39 ) {
V_13 = - V_62 ;
goto V_199;
}
V_86 -> V_268 = V_49 . V_268 ;
V_86 -> V_269 = V_49 . V_269 ;
V_86 -> V_270 = V_49 . V_270 ;
V_86 -> V_271 = V_49 . V_271 ;
V_86 -> V_272 = V_49 . V_272 ;
V_86 -> V_273 = V_49 . V_273 ;
V_86 -> V_274 = V_49 . V_274 ;
V_86 -> V_275 = V_49 . V_275 ;
V_86 -> V_276 = V_49 . V_276 ;
V_86 -> V_217 = V_49 . V_217 ;
V_86 -> V_277 = V_49 . V_277 ;
V_86 -> V_303 = V_49 . V_303 ;
V_86 -> V_279 = V_49 . V_279 ;
V_86 -> V_280 = V_49 . V_280 ;
V_86 -> V_281 = V_49 . V_281 ;
V_86 -> V_129 = V_49 . V_129 ;
V_86 -> V_282 = V_49 . V_282 ;
V_86 -> V_283 = V_49 . V_283 ;
V_86 -> V_284 = V_49 . V_284 ;
V_86 -> V_285 = V_49 . V_285 ;
V_86 -> V_286 = V_49 . V_286 ;
memcpy ( V_86 -> V_288 . V_289 . V_287 . V_290 , V_49 . V_200 . V_287 , 16 ) ;
V_86 -> V_288 . V_289 . V_291 = V_49 . V_200 . V_291 ;
V_86 -> V_288 . V_289 . V_292 = V_49 . V_200 . V_292 ;
V_86 -> V_288 . V_289 . V_293 = V_49 . V_200 . V_293 ;
V_86 -> V_288 . V_289 . V_294 = V_49 . V_200 . V_294 ;
V_86 -> V_288 . V_295 = V_49 . V_200 . V_295 ;
V_86 -> V_288 . V_219 = V_49 . V_200 . V_219 ;
V_86 -> V_288 . V_296 = V_49 . V_200 . V_296 ;
V_86 -> V_288 . V_297 = V_49 . V_200 . V_297 ;
V_86 -> V_288 . V_299 = V_49 . V_200 . V_298 ? V_300 : 0 ;
V_86 -> V_288 . V_129 = V_49 . V_200 . V_129 ;
memcpy ( V_86 -> V_302 . V_289 . V_287 . V_290 , V_49 . V_301 . V_287 , 16 ) ;
V_86 -> V_302 . V_289 . V_291 = V_49 . V_301 . V_291 ;
V_86 -> V_302 . V_289 . V_292 = V_49 . V_301 . V_292 ;
V_86 -> V_302 . V_289 . V_293 = V_49 . V_301 . V_293 ;
V_86 -> V_302 . V_289 . V_294 = V_49 . V_301 . V_294 ;
V_86 -> V_302 . V_295 = V_49 . V_301 . V_295 ;
V_86 -> V_302 . V_219 = V_49 . V_301 . V_219 ;
V_86 -> V_302 . V_296 = V_49 . V_301 . V_296 ;
V_86 -> V_302 . V_297 = V_49 . V_301 . V_297 ;
V_86 -> V_302 . V_299 = V_49 . V_301 . V_298 ? V_300 : 0 ;
V_86 -> V_302 . V_129 = V_49 . V_301 . V_129 ;
V_13 = V_39 -> V_56 -> V_304 ( V_39 , V_86 , V_49 . V_267 , & V_53 ) ;
F_37 ( V_39 ) ;
if ( V_13 )
goto V_199;
V_13 = V_47 ;
V_199:
F_6 ( V_86 ) ;
return V_13 ;
}
T_2 F_89 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_89 V_49 ;
struct V_305 V_51 ;
struct V_1 * V_2 ;
struct V_36 * V_39 ;
struct V_233 * V_180 ;
int V_13 = - V_62 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_2 = F_27 ( & V_38 , V_49 . V_37 , V_45 -> V_58 ) ;
if ( ! V_2 )
return - V_62 ;
V_39 = V_2 -> V_22 ;
V_180 = F_7 ( V_2 , struct V_233 , V_237 . V_27 ) ;
if ( ! F_90 ( & V_180 -> V_260 ) ) {
F_12 ( V_2 ) ;
return - V_306 ;
}
V_13 = F_85 ( V_39 ) ;
if ( ! V_13 )
V_2 -> V_10 = 0 ;
F_12 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_19 ( & V_38 , V_2 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_67 ( & V_2 -> V_156 ) ;
F_53 ( & V_45 -> V_9 ) ;
F_91 ( V_45 , & V_180 -> V_237 ) ;
V_51 . V_258 = V_180 -> V_237 . V_258 ;
F_8 ( V_2 ) ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
return - V_61 ;
return V_47 ;
}
T_2 F_92 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_92 V_49 ;
struct V_307 V_51 ;
struct V_308 * V_309 ;
struct V_310 * V_311 = NULL , * V_312 , * V_313 , * V_314 ;
struct V_36 * V_39 ;
int V_315 , V_316 ;
int V_317 ;
T_2 V_13 = - V_62 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
if ( V_47 < sizeof V_49 + V_49 . V_318 * V_49 . V_319 +
V_49 . V_320 * sizeof ( struct V_321 ) )
return - V_62 ;
if ( V_49 . V_318 < sizeof ( struct V_308 ) )
return - V_62 ;
V_309 = F_62 ( V_49 . V_318 , V_15 ) ;
if ( ! V_309 )
return - V_16 ;
V_39 = F_36 ( V_49 . V_37 , V_45 -> V_58 ) ;
if ( ! V_39 )
goto V_199;
V_317 = V_39 -> V_250 == V_322 ;
V_316 = 0 ;
V_312 = NULL ;
for ( V_315 = 0 ; V_315 < V_49 . V_319 ; ++ V_315 ) {
if ( F_41 ( V_309 ,
V_46 + sizeof V_49 + V_315 * V_49 . V_318 ,
V_49 . V_318 ) ) {
V_13 = - V_61 ;
goto V_227;
}
if ( V_309 -> V_323 + V_316 > V_49 . V_320 ) {
V_13 = - V_62 ;
goto V_227;
}
V_313 = F_62 ( F_93 ( sizeof *V_313 , sizeof ( struct V_324 ) ) +
V_309 -> V_323 * sizeof ( struct V_324 ) ,
V_15 ) ;
if ( ! V_313 ) {
V_13 = - V_16 ;
goto V_227;
}
if ( ! V_312 )
V_311 = V_313 ;
else
V_312 -> V_313 = V_313 ;
V_312 = V_313 ;
V_313 -> V_313 = NULL ;
V_313 -> V_205 = V_309 -> V_205 ;
V_313 -> V_323 = V_309 -> V_323 ;
V_313 -> V_207 = V_309 -> V_207 ;
V_313 -> V_325 = V_309 -> V_325 ;
if ( V_317 ) {
V_313 -> V_311 . V_326 . V_35 = F_34 ( V_309 -> V_311 . V_326 . V_35 ,
V_45 -> V_58 ) ;
if ( ! V_313 -> V_311 . V_326 . V_35 ) {
V_13 = - V_62 ;
goto V_227;
}
V_313 -> V_311 . V_326 . V_327 = V_309 -> V_311 . V_326 . V_327 ;
V_313 -> V_311 . V_326 . V_328 = V_309 -> V_311 . V_326 . V_328 ;
} else {
switch ( V_313 -> V_207 ) {
case V_329 :
V_313 -> V_210 . V_211 =
( V_330 V_213 ) V_309 -> V_210 . V_211 ;
case V_331 :
case V_332 :
V_313 -> V_311 . V_333 . V_334 =
V_309 -> V_311 . V_333 . V_334 ;
V_313 -> V_311 . V_333 . V_174 =
V_309 -> V_311 . V_333 . V_174 ;
break;
case V_335 :
V_313 -> V_210 . V_211 =
( V_330 V_213 ) V_309 -> V_210 . V_211 ;
break;
case V_336 :
V_313 -> V_210 . V_337 =
V_309 -> V_210 . V_337 ;
break;
case V_338 :
case V_339 :
V_313 -> V_311 . V_340 . V_334 =
V_309 -> V_311 . V_340 . V_334 ;
V_313 -> V_311 . V_340 . V_341 =
V_309 -> V_311 . V_340 . V_341 ;
V_313 -> V_311 . V_340 . V_342 = V_309 -> V_311 . V_340 . V_342 ;
V_313 -> V_311 . V_340 . V_174 = V_309 -> V_311 . V_340 . V_174 ;
break;
default:
break;
}
}
if ( V_313 -> V_323 ) {
V_313 -> V_343 = ( void * ) V_313 +
F_93 ( sizeof *V_313 , sizeof ( struct V_324 ) ) ;
if ( F_41 ( V_313 -> V_343 ,
V_46 + sizeof V_49 +
V_49 . V_319 * V_49 . V_318 +
V_316 * sizeof ( struct V_324 ) ,
V_313 -> V_323 * sizeof ( struct V_324 ) ) ) {
V_13 = - V_61 ;
goto V_227;
}
V_316 += V_313 -> V_323 ;
} else
V_313 -> V_343 = NULL ;
}
V_51 . V_314 = 0 ;
V_13 = V_39 -> V_56 -> V_344 ( V_39 , V_311 , & V_314 ) ;
if ( V_13 )
for ( V_313 = V_311 ; V_313 ; V_313 = V_313 -> V_313 ) {
++ V_51 . V_314 ;
if ( V_313 == V_314 )
break;
}
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
V_13 = - V_61 ;
V_227:
F_37 ( V_39 ) ;
while ( V_311 ) {
if ( V_317 && V_311 -> V_311 . V_326 . V_35 )
F_35 ( V_311 -> V_311 . V_326 . V_35 ) ;
V_313 = V_311 -> V_313 ;
F_6 ( V_311 ) ;
V_311 = V_313 ;
}
V_199:
F_6 ( V_309 ) ;
return V_13 ? V_13 : V_47 ;
}
static struct V_345 * F_94 ( const char T_3 * V_46 ,
int V_47 ,
T_5 V_319 ,
T_5 V_320 ,
T_5 V_318 )
{
struct V_346 * V_309 ;
struct V_345 * V_311 = NULL , * V_312 , * V_313 ;
int V_316 ;
int V_315 ;
int V_13 ;
if ( V_47 < V_318 * V_319 +
V_320 * sizeof ( struct V_321 ) )
return F_95 ( - V_62 ) ;
if ( V_318 < sizeof ( struct V_346 ) )
return F_95 ( - V_62 ) ;
V_309 = F_62 ( V_318 , V_15 ) ;
if ( ! V_309 )
return F_95 ( - V_16 ) ;
V_316 = 0 ;
V_312 = NULL ;
for ( V_315 = 0 ; V_315 < V_319 ; ++ V_315 ) {
if ( F_41 ( V_309 , V_46 + V_315 * V_318 ,
V_318 ) ) {
V_13 = - V_61 ;
goto V_63;
}
if ( V_309 -> V_323 + V_316 > V_320 ) {
V_13 = - V_62 ;
goto V_63;
}
V_313 = F_62 ( F_93 ( sizeof *V_313 , sizeof ( struct V_324 ) ) +
V_309 -> V_323 * sizeof ( struct V_324 ) ,
V_15 ) ;
if ( ! V_313 ) {
V_13 = - V_16 ;
goto V_63;
}
if ( ! V_312 )
V_311 = V_313 ;
else
V_312 -> V_313 = V_313 ;
V_312 = V_313 ;
V_313 -> V_313 = NULL ;
V_313 -> V_205 = V_309 -> V_205 ;
V_313 -> V_323 = V_309 -> V_323 ;
if ( V_313 -> V_323 ) {
V_313 -> V_343 = ( void * ) V_313 +
F_93 ( sizeof *V_313 , sizeof ( struct V_324 ) ) ;
if ( F_41 ( V_313 -> V_343 ,
V_46 + V_319 * V_318 +
V_316 * sizeof ( struct V_324 ) ,
V_313 -> V_323 * sizeof ( struct V_324 ) ) ) {
V_13 = - V_61 ;
goto V_63;
}
V_316 += V_313 -> V_323 ;
} else
V_313 -> V_343 = NULL ;
}
F_6 ( V_309 ) ;
return V_311 ;
V_63:
F_6 ( V_309 ) ;
while ( V_311 ) {
V_313 = V_311 -> V_313 ;
F_6 ( V_311 ) ;
V_311 = V_313 ;
}
return F_95 ( V_13 ) ;
}
T_2 F_96 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_96 V_49 ;
struct V_347 V_51 ;
struct V_345 * V_311 , * V_313 , * V_314 ;
struct V_36 * V_39 ;
T_2 V_13 = - V_62 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_311 = F_94 ( V_46 + sizeof V_49 ,
V_47 - sizeof V_49 , V_49 . V_319 ,
V_49 . V_320 , V_49 . V_318 ) ;
if ( F_44 ( V_311 ) )
return F_45 ( V_311 ) ;
V_39 = F_36 ( V_49 . V_37 , V_45 -> V_58 ) ;
if ( ! V_39 )
goto V_199;
V_51 . V_314 = 0 ;
V_13 = V_39 -> V_56 -> V_348 ( V_39 , V_311 , & V_314 ) ;
F_37 ( V_39 ) ;
if ( V_13 )
for ( V_313 = V_311 ; V_313 ; V_313 = V_313 -> V_313 ) {
++ V_51 . V_314 ;
if ( V_313 == V_314 )
break;
}
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
V_13 = - V_61 ;
V_199:
while ( V_311 ) {
V_313 = V_311 -> V_313 ;
F_6 ( V_311 ) ;
V_311 = V_313 ;
}
return V_13 ? V_13 : V_47 ;
}
T_2 F_97 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_97 V_49 ;
struct V_349 V_51 ;
struct V_345 * V_311 , * V_313 , * V_314 ;
struct V_40 * V_43 ;
T_2 V_13 = - V_62 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_311 = F_94 ( V_46 + sizeof V_49 ,
V_47 - sizeof V_49 , V_49 . V_319 ,
V_49 . V_320 , V_49 . V_318 ) ;
if ( F_44 ( V_311 ) )
return F_45 ( V_311 ) ;
V_43 = F_38 ( V_49 . V_41 , V_45 -> V_58 ) ;
if ( ! V_43 )
goto V_199;
V_51 . V_314 = 0 ;
V_13 = V_43 -> V_56 -> V_350 ( V_43 , V_311 , & V_314 ) ;
F_39 ( V_43 ) ;
if ( V_13 )
for ( V_313 = V_311 ; V_313 ; V_313 = V_313 -> V_313 ) {
++ V_51 . V_314 ;
if ( V_313 == V_314 )
break;
}
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
V_13 = - V_61 ;
V_199:
while ( V_311 ) {
V_313 = V_311 -> V_313 ;
F_6 ( V_311 ) ;
V_311 = V_313 ;
}
return V_13 ? V_13 : V_47 ;
}
T_2 F_98 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_98 V_49 ;
struct V_351 V_51 ;
struct V_1 * V_2 ;
struct V_23 * V_26 ;
struct V_32 * V_35 ;
struct V_352 V_86 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_2 = F_62 ( sizeof *V_2 , V_15 ) ;
if ( ! V_2 )
return - V_16 ;
F_1 ( V_2 , V_49 . V_3 , V_45 -> V_58 , & V_353 ) ;
F_28 ( & V_2 -> V_9 ) ;
V_26 = F_30 ( V_49 . V_24 , V_45 -> V_58 ) ;
if ( ! V_26 ) {
V_13 = - V_62 ;
goto V_63;
}
V_86 . V_295 = V_49 . V_86 . V_295 ;
V_86 . V_219 = V_49 . V_86 . V_219 ;
V_86 . V_296 = V_49 . V_86 . V_296 ;
V_86 . V_297 = V_49 . V_86 . V_297 ;
V_86 . V_299 = V_49 . V_86 . V_298 ? V_300 : 0 ;
V_86 . V_129 = V_49 . V_86 . V_129 ;
V_86 . V_289 . V_291 = V_49 . V_86 . V_289 . V_291 ;
V_86 . V_289 . V_292 = V_49 . V_86 . V_289 . V_292 ;
V_86 . V_289 . V_293 = V_49 . V_86 . V_289 . V_293 ;
V_86 . V_289 . V_294 = V_49 . V_86 . V_289 . V_294 ;
memcpy ( V_86 . V_289 . V_287 . V_290 , V_49 . V_86 . V_289 . V_287 , 16 ) ;
V_35 = F_99 ( V_26 , & V_86 ) ;
if ( F_44 ( V_35 ) ) {
V_13 = F_45 ( V_35 ) ;
goto V_170;
}
V_35 -> V_27 = V_2 ;
V_2 -> V_22 = V_35 ;
V_13 = F_14 ( & V_34 , V_2 ) ;
if ( V_13 )
goto V_262;
V_51 . V_33 = V_2 -> V_18 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) ) {
V_13 = - V_61 ;
goto V_155;
}
F_31 ( V_26 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_64 ( & V_2 -> V_156 , & V_45 -> V_58 -> V_72 ) ;
F_53 ( & V_45 -> V_9 ) ;
V_2 -> V_10 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
return V_47 ;
V_155:
F_19 ( & V_34 , V_2 ) ;
V_262:
F_100 ( V_35 ) ;
V_170:
F_31 ( V_26 ) ;
V_63:
F_12 ( V_2 ) ;
return V_13 ;
}
T_2 F_101 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 , int V_48 )
{
struct F_101 V_49 ;
struct V_32 * V_35 ;
struct V_1 * V_2 ;
int V_13 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_2 = F_27 ( & V_34 , V_49 . V_33 , V_45 -> V_58 ) ;
if ( ! V_2 )
return - V_62 ;
V_35 = V_2 -> V_22 ;
V_13 = F_100 ( V_35 ) ;
if ( ! V_13 )
V_2 -> V_10 = 0 ;
F_12 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_19 ( & V_34 , V_2 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_67 ( & V_2 -> V_156 ) ;
F_53 ( & V_45 -> V_9 ) ;
F_8 ( V_2 ) ;
return V_47 ;
}
T_2 F_102 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_102 V_49 ;
struct V_36 * V_39 ;
struct V_233 * V_180 ;
struct V_354 * V_355 ;
int V_13 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_39 = F_36 ( V_49 . V_37 , V_45 -> V_58 ) ;
if ( ! V_39 )
return - V_62 ;
V_180 = F_7 ( V_39 -> V_27 , struct V_233 , V_237 . V_27 ) ;
F_103 (mcast, &obj->mcast_list, list)
if ( V_49 . V_356 == V_355 -> V_139 &&
! memcmp ( V_49 . V_357 , V_355 -> V_357 . V_290 , sizeof V_355 -> V_357 . V_290 ) ) {
V_13 = 0 ;
goto V_227;
}
V_355 = F_62 ( sizeof *V_355 , V_15 ) ;
if ( ! V_355 ) {
V_13 = - V_16 ;
goto V_227;
}
V_355 -> V_139 = V_49 . V_356 ;
memcpy ( V_355 -> V_357 . V_290 , V_49 . V_357 , sizeof V_355 -> V_357 . V_290 ) ;
V_13 = F_104 ( V_39 , & V_355 -> V_357 , V_49 . V_356 ) ;
if ( ! V_13 )
F_64 ( & V_355 -> V_156 , & V_180 -> V_260 ) ;
else
F_6 ( V_355 ) ;
V_227:
F_37 ( V_39 ) ;
return V_13 ? V_13 : V_47 ;
}
T_2 F_105 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_105 V_49 ;
struct V_233 * V_180 ;
struct V_36 * V_39 ;
struct V_354 * V_355 ;
int V_13 = - V_62 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_39 = F_36 ( V_49 . V_37 , V_45 -> V_58 ) ;
if ( ! V_39 )
return - V_62 ;
V_13 = F_106 ( V_39 , (union V_358 * ) V_49 . V_357 , V_49 . V_356 ) ;
if ( V_13 )
goto V_227;
V_180 = F_7 ( V_39 -> V_27 , struct V_233 , V_237 . V_27 ) ;
F_103 (mcast, &obj->mcast_list, list)
if ( V_49 . V_356 == V_355 -> V_139 &&
! memcmp ( V_49 . V_357 , V_355 -> V_357 . V_290 , sizeof V_355 -> V_357 . V_290 ) ) {
F_67 ( & V_355 -> V_156 ) ;
F_6 ( V_355 ) ;
break;
}
V_227:
F_37 ( V_39 ) ;
return V_13 ? V_13 : V_47 ;
}
T_2 F_107 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_107 V_49 ;
struct V_359 V_51 ;
struct V_52 V_53 ;
struct V_360 * V_180 ;
struct V_23 * V_26 ;
struct V_40 * V_43 ;
struct V_361 V_86 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
F_43 ( & V_53 , V_46 + sizeof V_49 ,
( unsigned long ) V_49 . V_64 + sizeof V_51 ,
V_47 - sizeof V_49 , V_48 - sizeof V_51 ) ;
V_180 = F_62 ( sizeof *V_180 , V_15 ) ;
if ( ! V_180 )
return - V_16 ;
F_1 ( & V_180 -> V_27 , V_49 . V_3 , V_45 -> V_58 , & V_362 ) ;
F_28 ( & V_180 -> V_27 . V_9 ) ;
V_26 = F_30 ( V_49 . V_24 , V_45 -> V_58 ) ;
if ( ! V_26 ) {
V_13 = - V_62 ;
goto V_63;
}
V_86 . V_81 = V_363 ;
V_86 . V_364 = V_45 ;
V_86 . V_86 . V_365 = V_49 . V_365 ;
V_86 . V_86 . V_98 = V_49 . V_98 ;
V_86 . V_86 . V_366 = V_49 . V_366 ;
V_180 -> V_258 = 0 ;
F_46 ( & V_180 -> V_259 ) ;
V_43 = V_26 -> V_56 -> V_367 ( V_26 , & V_86 , & V_53 ) ;
if ( F_44 ( V_43 ) ) {
V_13 = F_45 ( V_43 ) ;
goto V_170;
}
V_43 -> V_56 = V_26 -> V_56 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_27 = & V_180 -> V_27 ;
V_43 -> V_81 = V_86 . V_81 ;
V_43 -> V_364 = V_86 . V_364 ;
F_69 ( & V_26 -> V_153 ) ;
F_63 ( & V_43 -> V_153 , 0 ) ;
V_180 -> V_27 . V_22 = V_43 ;
V_13 = F_14 ( & V_42 , & V_180 -> V_27 ) ;
if ( V_13 )
goto V_262;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_41 = V_180 -> V_27 . V_18 ;
V_51 . V_365 = V_86 . V_86 . V_365 ;
V_51 . V_98 = V_86 . V_86 . V_98 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) ) {
V_13 = - V_61 ;
goto V_155;
}
F_31 ( V_26 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_64 ( & V_180 -> V_27 . V_156 , & V_45 -> V_58 -> V_71 ) ;
F_53 ( & V_45 -> V_9 ) ;
V_180 -> V_27 . V_10 = 1 ;
F_13 ( & V_180 -> V_27 . V_9 ) ;
return V_47 ;
V_155:
F_19 ( & V_42 , & V_180 -> V_27 ) ;
V_262:
F_108 ( V_43 ) ;
V_170:
F_31 ( V_26 ) ;
V_63:
F_12 ( & V_180 -> V_27 ) ;
return V_13 ;
}
T_2 F_109 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_109 V_49 ;
struct V_52 V_53 ;
struct V_40 * V_43 ;
struct V_368 V_86 ;
int V_13 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
F_43 ( & V_53 , V_46 + sizeof V_49 , NULL , V_47 - sizeof V_49 ,
V_48 ) ;
V_43 = F_38 ( V_49 . V_41 , V_45 -> V_58 ) ;
if ( ! V_43 )
return - V_62 ;
V_86 . V_365 = V_49 . V_365 ;
V_86 . V_366 = V_49 . V_366 ;
V_13 = V_43 -> V_56 -> V_369 ( V_43 , & V_86 , V_49 . V_267 , & V_53 ) ;
F_39 ( V_43 ) ;
return V_13 ? V_13 : V_47 ;
}
T_2 F_110 ( struct V_44 * V_45 ,
const char T_3 * V_46 ,
int V_47 , int V_48 )
{
struct F_110 V_49 ;
struct V_370 V_51 ;
struct V_368 V_86 ;
struct V_40 * V_43 ;
int V_13 ;
if ( V_48 < sizeof V_51 )
return - V_60 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_43 = F_38 ( V_49 . V_41 , V_45 -> V_58 ) ;
if ( ! V_43 )
return - V_62 ;
V_13 = F_111 ( V_43 , & V_86 ) ;
F_39 ( V_43 ) ;
if ( V_13 )
return V_13 ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_365 = V_86 . V_365 ;
V_51 . V_98 = V_86 . V_98 ;
V_51 . V_366 = V_86 . V_366 ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
return - V_61 ;
return V_47 ;
}
T_2 F_112 ( struct V_44 * V_45 ,
const char T_3 * V_46 , int V_47 ,
int V_48 )
{
struct F_112 V_49 ;
struct V_371 V_51 ;
struct V_1 * V_2 ;
struct V_40 * V_43 ;
struct V_360 * V_180 ;
int V_13 = - V_62 ;
if ( F_41 ( & V_49 , V_46 , sizeof V_49 ) )
return - V_61 ;
V_2 = F_27 ( & V_42 , V_49 . V_41 , V_45 -> V_58 ) ;
if ( ! V_2 )
return - V_62 ;
V_43 = V_2 -> V_22 ;
V_180 = F_7 ( V_2 , struct V_360 , V_27 ) ;
V_13 = F_108 ( V_43 ) ;
if ( ! V_13 )
V_2 -> V_10 = 0 ;
F_12 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_19 ( & V_42 , V_2 ) ;
F_42 ( & V_45 -> V_9 ) ;
F_67 ( & V_2 -> V_156 ) ;
F_53 ( & V_45 -> V_9 ) ;
F_91 ( V_45 , V_180 ) ;
memset ( & V_51 , 0 , sizeof V_51 ) ;
V_51 . V_258 = V_180 -> V_258 ;
F_8 ( V_2 ) ;
if ( F_49 ( ( void T_3 * ) ( unsigned long ) V_49 . V_64 ,
& V_51 , sizeof V_51 ) )
V_13 = - V_61 ;
return V_13 ? V_13 : V_47 ;
}
