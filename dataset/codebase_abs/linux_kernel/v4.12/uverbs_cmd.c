static struct V_1 *
F_1 ( int V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_7 ) ,
V_2 , V_4 ) ;
struct V_8 * V_9 ;
if ( F_4 ( V_6 ) )
return ( void * ) V_6 ;
F_5 ( V_6 ) ;
F_6 ( V_6 ) ;
V_9 = F_7 ( V_6 , struct V_8 , V_6 ) ;
return F_7 ( V_9 , struct V_1 ,
V_9 ) ;
}
T_1 F_8 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_8 V_17 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
struct V_3 * V_22 ;
struct V_11 * V_23 ;
struct V_24 V_25 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_10 ( & V_11 -> V_29 ) ;
if ( V_11 -> V_22 ) {
V_26 = - V_30 ;
goto V_31;
}
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 , V_16 - sizeof V_19 ) ;
V_26 = F_12 ( & V_25 , V_13 , V_33 ) ;
if ( V_26 )
goto V_31;
V_22 = V_13 -> V_34 ( V_13 , & V_21 ) ;
if ( F_4 ( V_22 ) ) {
V_26 = F_13 ( V_22 ) ;
goto V_35;
}
V_22 -> V_36 = V_13 ;
V_22 -> V_25 = V_25 ;
V_22 -> V_37 = V_11 ;
F_14 ( V_22 ) ;
F_15 () ;
V_22 -> V_38 = F_16 ( V_39 -> V_40 , V_41 ) ;
F_17 () ;
V_22 -> V_42 = 0 ;
#ifdef F_18
V_22 -> V_43 = V_44 ;
F_19 ( & V_22 -> V_45 ) ;
V_22 -> V_46 = 0 ;
F_20 ( & V_22 -> V_47 ) ;
if ( ! ( V_13 -> V_48 . V_49 & V_50 ) )
V_22 -> V_51 = NULL ;
#endif
V_19 . V_52 = V_11 -> V_36 -> V_52 ;
V_26 = F_21 ( V_53 ) ;
if ( V_26 < 0 )
goto V_54;
V_19 . V_55 = V_26 ;
V_23 = F_22 ( V_11 , V_13 ) ;
if ( F_4 ( V_23 ) ) {
V_26 = F_13 ( V_23 ) ;
goto V_56;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_57;
}
V_11 -> V_22 = V_22 ;
F_24 ( V_19 . V_55 , V_23 ) ;
F_25 ( & V_11 -> V_29 ) ;
return V_15 ;
V_57:
F_26 ( V_11 ) ;
F_27 ( V_23 ) ;
V_56:
F_28 ( V_19 . V_55 ) ;
V_54:
F_29 ( V_22 -> V_38 ) ;
V_13 -> V_58 ( V_22 ) ;
V_35:
F_30 ( & V_25 , V_13 , V_33 ) ;
V_31:
F_25 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static void F_31 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_59 * V_19 ,
struct V_60 * V_61 )
{
V_19 -> V_62 = V_61 -> V_62 ;
V_19 -> V_63 = V_13 -> V_63 ;
V_19 -> V_64 = V_61 -> V_64 ;
V_19 -> V_65 = V_61 -> V_65 ;
V_19 -> V_66 = V_61 -> V_66 ;
V_19 -> V_67 = V_61 -> V_67 ;
V_19 -> V_68 = V_61 -> V_68 ;
V_19 -> V_69 = V_61 -> V_69 ;
V_19 -> V_70 = V_61 -> V_70 ;
V_19 -> V_71 = V_61 -> V_71 ;
V_19 -> V_49 = F_32 ( V_61 -> V_49 ) ;
V_19 -> V_72 = V_61 -> V_72 ;
V_19 -> V_73 = V_61 -> V_73 ;
V_19 -> V_74 = V_61 -> V_74 ;
V_19 -> V_75 = V_61 -> V_75 ;
V_19 -> V_76 = V_61 -> V_76 ;
V_19 -> V_77 = V_61 -> V_77 ;
V_19 -> V_78 = V_61 -> V_78 ;
V_19 -> V_79 = V_61 -> V_79 ;
V_19 -> V_80 = V_61 -> V_80 ;
V_19 -> V_81 = V_61 -> V_81 ;
V_19 -> V_82 = V_61 -> V_82 ;
V_19 -> V_83 = V_61 -> V_83 ;
V_19 -> V_84 = V_61 -> V_84 ;
V_19 -> V_85 = V_61 -> V_85 ;
V_19 -> V_86 = V_61 -> V_86 ;
V_19 -> V_87 = V_61 -> V_87 ;
V_19 -> V_88 = V_61 -> V_88 ;
V_19 -> V_89 = V_61 -> V_89 ;
V_19 -> V_90 = V_61 -> V_90 ;
V_19 -> V_91 = V_61 -> V_91 ;
V_19 -> V_92 = V_61 -> V_92 ;
V_19 -> V_93 = V_61 -> V_93 ;
V_19 -> V_94 = V_61 -> V_94 ;
V_19 -> V_95 = V_61 -> V_95 ;
V_19 -> V_96 = V_61 -> V_96 ;
V_19 -> V_97 = V_61 -> V_97 ;
V_19 -> V_98 = V_61 -> V_98 ;
V_19 -> V_99 = V_61 -> V_99 ;
V_19 -> V_100 = V_13 -> V_100 ;
}
T_1 F_33 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_33 V_17 ;
struct V_59 V_19 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
F_31 ( V_11 , V_13 , & V_19 , & V_13 -> V_48 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
T_1 F_34 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_34 V_17 ;
struct V_101 V_19 ;
struct V_102 V_61 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_26 = F_35 ( V_13 , V_17 . V_103 , & V_61 ) ;
if ( V_26 )
return V_26 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_104 = V_61 . V_104 ;
V_19 . V_105 = V_61 . V_105 ;
V_19 . V_106 = V_61 . V_106 ;
V_19 . V_107 = V_61 . V_107 ;
V_19 . V_108 = V_61 . V_108 ;
V_19 . V_109 = V_61 . V_109 ;
V_19 . V_110 = V_61 . V_110 ;
V_19 . V_111 = V_61 . V_111 ;
V_19 . V_112 = V_61 . V_112 ;
V_19 . V_113 = V_61 . V_113 ;
V_19 . V_114 = V_61 . V_114 ;
V_19 . V_115 = V_61 . V_115 ;
V_19 . V_116 = V_61 . V_116 ;
V_19 . V_117 = V_61 . V_117 ;
V_19 . V_118 = V_61 . V_118 ;
V_19 . V_119 = V_61 . V_119 ;
V_19 . V_120 = V_61 . V_120 ;
V_19 . V_121 = V_61 . V_121 ;
V_19 . V_122 = V_61 . V_122 ;
V_19 . V_123 = F_36 ( V_13 ,
V_17 . V_103 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
T_1 F_37 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_37 V_17 ;
struct V_124 V_19 ;
struct V_20 V_21 ;
struct V_5 * V_6 ;
struct V_125 * V_126 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 , V_16 - sizeof V_19 ) ;
V_6 = F_38 ( F_3 ( V_126 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_126 = V_13 -> V_127 ( V_13 , V_11 -> V_22 , & V_21 ) ;
if ( F_4 ( V_126 ) ) {
V_26 = F_13 ( V_126 ) ;
goto V_31;
}
V_126 -> V_36 = V_13 ;
V_126 -> V_128 = V_6 ;
V_126 -> V_129 = NULL ;
F_39 ( & V_126 -> V_130 , 0 ) ;
V_6 -> V_131 = V_126 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_132 = V_6 -> V_133 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_134;
}
F_40 ( V_6 ) ;
return V_15 ;
V_134:
F_41 ( V_126 ) ;
V_31:
F_42 ( V_6 ) ;
return V_26 ;
}
T_1 F_43 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_43 V_17 ;
struct V_5 * V_6 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_126 ) , V_17 . V_132 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
return V_26 ? : V_15 ;
}
static int F_46 ( struct V_135 * V_136 ,
struct V_137 * V_137 ,
struct V_138 * V_139 )
{
struct V_140 * V_141 , * V_142 ;
struct V_143 * * V_144 = & V_136 -> V_145 . V_143 ;
struct V_143 * V_146 = NULL ;
V_141 = F_47 ( sizeof *V_141 , V_147 ) ;
if ( ! V_141 )
return - V_148 ;
V_141 -> V_139 = V_139 ;
V_141 -> V_137 = V_137 ;
while ( * V_144 ) {
V_146 = * V_144 ;
V_142 = F_48 ( V_146 , struct V_140 , V_149 ) ;
if ( V_137 < V_142 -> V_137 ) {
V_144 = & ( * V_144 ) -> V_150 ;
} else if ( V_137 > V_142 -> V_137 ) {
V_144 = & ( * V_144 ) -> V_151 ;
} else {
F_49 ( V_141 ) ;
return - V_152 ;
}
}
F_50 ( & V_141 -> V_149 , V_146 , V_144 ) ;
F_51 ( & V_141 -> V_149 , & V_136 -> V_145 ) ;
F_52 ( V_137 ) ;
return 0 ;
}
static struct V_140 * F_53 ( struct V_135 * V_136 ,
struct V_137 * V_137 )
{
struct V_140 * V_141 ;
struct V_143 * V_144 = V_136 -> V_145 . V_143 ;
while ( V_144 ) {
V_141 = F_48 ( V_144 , struct V_140 , V_149 ) ;
if ( V_137 < V_141 -> V_137 )
V_144 = V_144 -> V_150 ;
else if ( V_137 > V_141 -> V_137 )
V_144 = V_144 -> V_151 ;
else
return V_141 ;
}
return NULL ;
}
static struct V_138 * F_54 ( struct V_135 * V_136 , struct V_137 * V_137 )
{
struct V_140 * V_141 ;
V_141 = F_53 ( V_136 , V_137 ) ;
if ( ! V_141 )
return NULL ;
return V_141 -> V_139 ;
}
static void F_55 ( struct V_135 * V_136 ,
struct V_137 * V_137 )
{
struct V_140 * V_141 ;
V_141 = F_53 ( V_136 , V_137 ) ;
if ( V_141 ) {
F_56 ( V_137 ) ;
F_57 ( & V_141 -> V_149 , & V_136 -> V_145 ) ;
F_49 ( V_141 ) ;
}
}
T_1 F_58 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_58 V_17 ;
struct V_153 V_19 ;
struct V_20 V_21 ;
struct V_154 * V_155 ;
struct V_138 * V_139 = NULL ;
struct V_2 V_156 = { NULL , 0 } ;
struct V_137 * V_137 = NULL ;
int V_26 = 0 ;
int V_157 = 0 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 , V_16 - sizeof V_19 ) ;
F_10 ( & V_11 -> V_36 -> V_158 ) ;
if ( V_17 . V_2 != - 1 ) {
V_156 = F_59 ( V_17 . V_2 ) ;
if ( ! V_156 . V_11 ) {
V_26 = - V_159 ;
goto V_160;
}
V_137 = F_60 ( V_156 . V_11 ) ;
V_139 = F_54 ( V_11 -> V_36 , V_137 ) ;
if ( ! V_139 && ! ( V_17 . V_161 & V_162 ) ) {
V_26 = - V_163 ;
goto V_160;
}
if ( V_139 && V_17 . V_161 & V_164 ) {
V_26 = - V_30 ;
goto V_160;
}
}
V_155 = (struct V_154 * ) F_38 ( F_3 ( V_139 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) ) {
V_26 = F_13 ( V_155 ) ;
goto V_160;
}
if ( ! V_139 ) {
V_139 = V_13 -> V_165 ( V_13 , V_11 -> V_22 , & V_21 ) ;
if ( F_4 ( V_139 ) ) {
V_26 = F_13 ( V_139 ) ;
goto V_31;
}
V_139 -> V_137 = V_137 ;
V_139 -> V_36 = V_13 ;
F_39 ( & V_139 -> V_130 , 0 ) ;
F_61 ( & V_139 -> V_166 ) ;
F_20 ( & V_139 -> V_167 ) ;
V_157 = 1 ;
}
F_39 ( & V_155 -> V_168 , 0 ) ;
V_155 -> V_128 . V_131 = V_139 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_169 = V_155 -> V_128 . V_133 ;
if ( V_137 ) {
if ( V_157 ) {
V_26 = F_46 ( V_11 -> V_36 , V_137 , V_139 ) ;
if ( V_26 )
goto V_170;
}
F_62 ( & V_139 -> V_130 ) ;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_134;
}
if ( V_156 . V_11 )
F_63 ( V_156 ) ;
F_40 ( & V_155 -> V_128 ) ;
F_25 ( & V_11 -> V_36 -> V_158 ) ;
return V_15 ;
V_134:
if ( V_137 ) {
if ( V_157 )
F_55 ( V_11 -> V_36 , V_137 ) ;
F_64 ( & V_139 -> V_130 ) ;
}
V_170:
F_65 ( V_139 ) ;
V_31:
F_42 ( & V_155 -> V_128 ) ;
V_160:
if ( V_156 . V_11 )
F_63 ( V_156 ) ;
F_25 ( & V_11 -> V_36 -> V_158 ) ;
return V_26 ;
}
T_1 F_66 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_66 V_17 ;
struct V_5 * V_6 ;
int V_26 = 0 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_139 ) , V_17 . V_169 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) ) {
F_25 ( & V_11 -> V_36 -> V_158 ) ;
return F_13 ( V_6 ) ;
}
V_26 = F_45 ( V_6 ) ;
return V_26 ? : V_15 ;
}
int F_67 ( struct V_135 * V_136 ,
struct V_138 * V_139 ,
enum V_171 V_172 )
{
struct V_137 * V_137 ;
int V_26 ;
V_137 = V_139 -> V_137 ;
if ( V_137 && ! F_68 ( & V_139 -> V_130 ) )
return 0 ;
V_26 = F_65 ( V_139 ) ;
if ( V_172 == V_173 && V_26 )
F_62 ( & V_139 -> V_130 ) ;
else if ( V_137 )
F_55 ( V_136 , V_137 ) ;
return V_26 ;
}
T_1 F_69 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_69 V_17 ;
struct V_174 V_19 ;
struct V_20 V_21 ;
struct V_5 * V_6 ;
struct V_125 * V_126 ;
struct V_175 * V_176 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 , V_16 - sizeof V_19 ) ;
if ( ( V_17 . V_177 & ~ V_178 ) != ( V_17 . V_179 & ~ V_178 ) )
return - V_30 ;
V_26 = F_70 ( V_17 . V_180 ) ;
if ( V_26 )
return V_26 ;
V_6 = F_38 ( F_3 ( V_176 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_126 = F_71 ( V_126 , V_17 . V_132 , V_11 -> V_22 ) ;
if ( ! V_126 ) {
V_26 = - V_30 ;
goto V_54;
}
if ( V_17 . V_180 & V_181 ) {
if ( ! ( V_126 -> V_36 -> V_48 . V_49 &
V_50 ) ) {
F_72 ( L_1 ) ;
V_26 = - V_30 ;
goto V_182;
}
}
V_176 = V_126 -> V_36 -> V_183 ( V_126 , V_17 . V_177 , V_17 . V_184 , V_17 . V_179 ,
V_17 . V_180 , & V_21 ) ;
if ( F_4 ( V_176 ) ) {
V_26 = F_13 ( V_176 ) ;
goto V_182;
}
V_176 -> V_36 = V_126 -> V_36 ;
V_176 -> V_126 = V_126 ;
V_176 -> V_128 = V_6 ;
F_62 ( & V_126 -> V_130 ) ;
V_6 -> V_131 = V_176 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_185 = V_176 -> V_185 ;
V_19 . V_186 = V_176 -> V_186 ;
V_19 . V_187 = V_6 -> V_133 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_134;
}
F_73 ( V_126 ) ;
F_40 ( V_6 ) ;
return V_15 ;
V_134:
F_74 ( V_176 ) ;
V_182:
F_73 ( V_126 ) ;
V_54:
F_42 ( V_6 ) ;
return V_26 ;
}
T_1 F_75 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_75 V_17 ;
struct V_188 V_19 ;
struct V_20 V_21 ;
struct V_125 * V_126 = NULL ;
struct V_175 * V_176 ;
struct V_125 * V_189 ;
int V_26 ;
struct V_5 * V_6 ;
if ( V_16 < sizeof( V_19 ) )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) , V_16 - sizeof( V_19 ) ) ;
if ( V_17 . V_190 & ~ V_191 || ! V_17 . V_190 )
return - V_30 ;
if ( ( V_17 . V_190 & V_192 ) &&
( ! V_17 . V_177 || ! V_17 . V_179 || 0 >= V_17 . V_184 ||
( V_17 . V_177 & ~ V_178 ) != ( V_17 . V_179 & ~ V_178 ) ) )
return - V_30 ;
V_6 = F_44 ( F_3 ( V_176 ) , V_17 . V_187 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_176 = V_6 -> V_131 ;
if ( V_17 . V_190 & V_193 ) {
V_26 = F_70 ( V_17 . V_180 ) ;
if ( V_26 )
goto V_194;
}
if ( V_17 . V_190 & V_195 ) {
V_126 = F_71 ( V_126 , V_17 . V_132 , V_11 -> V_22 ) ;
if ( ! V_126 ) {
V_26 = - V_30 ;
goto V_194;
}
}
V_189 = V_176 -> V_126 ;
V_26 = V_176 -> V_36 -> V_196 ( V_176 , V_17 . V_190 , V_17 . V_177 ,
V_17 . V_184 , V_17 . V_179 ,
V_17 . V_180 , V_126 , & V_21 ) ;
if ( ! V_26 ) {
if ( V_17 . V_190 & V_195 ) {
F_62 ( & V_126 -> V_130 ) ;
V_176 -> V_126 = V_126 ;
F_64 ( & V_189 -> V_130 ) ;
}
} else {
goto V_197;
}
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_185 = V_176 -> V_185 ;
V_19 . V_186 = V_176 -> V_186 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof( V_19 ) ) )
V_26 = - V_28 ;
else
V_26 = V_15 ;
V_197:
if ( V_17 . V_190 & V_195 )
F_73 ( V_126 ) ;
V_194:
F_76 ( V_6 ) ;
return V_26 ;
}
T_1 F_77 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_77 V_17 ;
struct V_5 * V_6 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_176 ) , V_17 . V_187 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
return V_26 ? : V_15 ;
}
T_1 F_78 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_78 V_17 ;
struct V_198 V_19 ;
struct V_5 * V_6 ;
struct V_125 * V_126 ;
struct V_199 * V_200 ;
struct V_20 V_21 ;
int V_26 ;
if ( V_16 < sizeof( V_19 ) )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
V_6 = F_38 ( F_3 ( V_200 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_126 = F_71 ( V_126 , V_17 . V_132 , V_11 -> V_22 ) ;
if ( ! V_126 ) {
V_26 = - V_30 ;
goto V_54;
}
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_201 ) ,
V_16 - sizeof( V_19 ) ) ;
V_200 = V_126 -> V_36 -> V_202 ( V_126 , V_17 . V_203 , & V_21 ) ;
if ( F_4 ( V_200 ) ) {
V_26 = F_13 ( V_200 ) ;
goto V_182;
}
V_200 -> V_36 = V_126 -> V_36 ;
V_200 -> V_126 = V_126 ;
V_200 -> V_128 = V_6 ;
F_62 ( & V_126 -> V_130 ) ;
V_6 -> V_131 = V_200 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_186 = V_200 -> V_186 ;
V_19 . V_204 = V_6 -> V_133 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof( V_19 ) ) ) {
V_26 = - V_28 ;
goto V_134;
}
F_73 ( V_126 ) ;
F_40 ( V_6 ) ;
return V_15 ;
V_134:
F_79 ( V_200 ) ;
V_182:
F_73 ( V_126 ) ;
V_54:
F_42 ( V_6 ) ;
return V_26 ;
}
T_1 F_80 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_80 V_17 ;
struct V_5 * V_6 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_200 ) , V_17 . V_204 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
return V_26 ? : V_15 ;
}
T_1 F_81 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_81 V_17 ;
struct V_205 V_19 ;
struct V_5 * V_6 ;
struct V_1 * V_206 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_38 ( F_3 ( V_7 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_19 . V_2 = V_6 -> V_133 ;
V_206 = F_7 ( V_6 , struct V_1 ,
V_9 . V_6 ) ;
F_82 ( & V_206 -> V_207 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
F_42 ( V_6 ) ;
return - V_28 ;
}
F_40 ( V_6 ) ;
return V_15 ;
}
static struct V_208 * F_83 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 ,
struct V_211 * V_17 ,
T_3 V_212 ,
int (* F_84)( struct V_10 * V_11 ,
struct V_208 * V_155 ,
struct V_213 * V_19 ,
struct V_20 * V_21 ,
void * V_4 ) ,
void * V_4 )
{
struct V_208 * V_155 ;
struct V_1 * V_206 = NULL ;
struct V_214 * V_215 ;
int V_26 ;
struct V_213 V_19 ;
struct V_216 V_61 = {} ;
if ( V_17 -> V_217 >= V_11 -> V_36 -> V_52 )
return F_85 ( - V_30 ) ;
V_155 = (struct V_208 * ) F_38 ( F_3 ( V_215 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) )
return V_155 ;
if ( V_17 -> V_7 >= 0 ) {
V_206 = F_1 ( V_17 -> V_7 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_206 ) ) {
V_26 = F_13 ( V_206 ) ;
goto V_31;
}
}
V_155 -> V_128 . V_218 = V_17 -> V_218 ;
V_155 -> V_219 = V_11 ;
V_155 -> V_220 = 0 ;
V_155 -> V_221 = 0 ;
F_20 ( & V_155 -> V_222 ) ;
F_20 ( & V_155 -> V_223 ) ;
V_61 . V_224 = V_17 -> V_224 ;
V_61 . V_217 = V_17 -> V_217 ;
if ( V_212 > F_86 ( F_87 ( * V_17 ) , V_190 ) + sizeof( V_17 -> V_190 ) )
V_61 . V_190 = V_17 -> V_190 ;
V_215 = V_13 -> F_83 ( V_13 , & V_61 , V_11 -> V_22 , V_210 ) ;
if ( F_4 ( V_215 ) ) {
V_26 = F_13 ( V_215 ) ;
goto V_57;
}
V_215 -> V_36 = V_13 ;
V_215 -> V_128 = & V_155 -> V_128 ;
V_215 -> V_225 = V_226 ;
V_215 -> V_227 = V_228 ;
V_215 -> V_229 = & V_206 -> V_207 ;
F_39 ( & V_215 -> V_130 , 0 ) ;
V_155 -> V_128 . V_131 = V_215 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_230 . V_231 = V_155 -> V_128 . V_133 ;
V_19 . V_230 . V_224 = V_215 -> V_224 ;
V_19 . V_232 = F_86 ( F_87 ( V_19 ) , V_232 ) +
sizeof( V_19 . V_232 ) ;
V_26 = F_84 ( V_11 , V_155 , & V_19 , V_209 , V_4 ) ;
if ( V_26 )
goto V_233;
F_40 ( & V_155 -> V_128 ) ;
return V_155 ;
V_233:
F_88 ( V_215 ) ;
V_57:
if ( V_206 )
F_89 ( V_11 , V_206 , V_155 ) ;
V_31:
F_42 ( & V_155 -> V_128 ) ;
return F_85 ( V_26 ) ;
}
static int F_90 ( struct V_10 * V_11 ,
struct V_208 * V_155 ,
struct V_213 * V_19 ,
struct V_20 * V_209 , void * V_4 )
{
if ( F_91 ( V_209 , & V_19 -> V_230 , sizeof( V_19 -> V_230 ) ) )
return - V_28 ;
return 0 ;
}
T_1 F_92 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_92 V_17 ;
struct V_211 V_234 ;
struct V_235 V_19 ;
struct V_20 V_209 ;
struct V_20 V_210 ;
struct V_208 * V_155 ;
if ( V_16 < sizeof( V_19 ) )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
F_11 ( & V_209 , V_14 , ( unsigned long ) V_17 . V_32 , sizeof( V_17 ) , sizeof( V_19 ) ) ;
F_11 ( & V_210 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) , V_16 - sizeof( V_19 ) ) ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_218 = V_17 . V_218 ;
V_234 . V_224 = V_17 . V_224 ;
V_234 . V_217 = V_17 . V_217 ;
V_234 . V_7 = V_17 . V_7 ;
V_155 = F_83 ( V_11 , V_13 , & V_209 , & V_210 , & V_234 ,
F_86 ( F_87 ( V_234 ) , V_7 ) +
sizeof( V_17 . V_7 ) , F_90 ,
NULL ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
return V_15 ;
}
static int F_93 ( struct V_10 * V_11 ,
struct V_208 * V_155 ,
struct V_213 * V_19 ,
struct V_20 * V_209 , void * V_4 )
{
if ( F_91 ( V_209 , V_19 , V_19 -> V_232 ) )
return - V_28 ;
return 0 ;
}
int V_211 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_213 V_19 ;
struct V_211 V_17 ;
struct V_208 * V_155 ;
int V_31 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
V_31 = F_94 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_31 )
return V_31 ;
if ( V_17 . V_237 )
return - V_30 ;
if ( V_17 . V_238 )
return - V_30 ;
if ( V_209 -> V_239 < ( F_86 ( F_87 ( V_19 ) , V_232 ) +
sizeof( V_19 . V_232 ) ) )
return - V_27 ;
V_155 = F_83 ( V_11 , V_13 , V_209 , V_210 , & V_17 ,
F_95 ( V_209 -> V_236 , sizeof( V_17 ) ) ,
F_93 , NULL ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
return 0 ;
}
T_1 F_96 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_96 V_17 ;
struct V_240 V_19 ;
struct V_20 V_21 ;
struct V_214 * V_215 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 , V_16 - sizeof V_19 ) ;
V_215 = F_71 ( V_215 , V_17 . V_231 , V_11 -> V_22 ) ;
if ( ! V_215 )
return - V_30 ;
V_26 = V_215 -> V_36 -> V_241 ( V_215 , V_17 . V_224 , & V_21 ) ;
if ( V_26 )
goto V_242;
V_19 . V_224 = V_215 -> V_224 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 . V_224 ) )
V_26 = - V_28 ;
V_242:
F_73 ( V_215 ) ;
return V_26 ? V_26 : V_15 ;
}
static int F_97 ( void T_2 * V_243 , struct V_244 * V_245 )
{
struct V_246 V_247 ;
V_247 . V_248 = V_245 -> V_248 ;
V_247 . V_249 = V_245 -> V_249 ;
V_247 . V_250 = V_245 -> V_250 ;
V_247 . V_251 = V_245 -> V_251 ;
V_247 . V_252 = V_245 -> V_252 ;
V_247 . V_253 . V_254 = ( V_255 V_256 ) V_245 -> V_253 . V_254 ;
V_247 . V_257 = V_245 -> V_258 -> V_257 ;
V_247 . V_259 = V_245 -> V_259 ;
V_247 . V_260 = V_245 -> V_260 ;
V_247 . V_261 = V_245 -> V_261 ;
V_247 . V_262 = V_245 -> V_262 ;
V_247 . V_263 = V_245 -> V_263 ;
V_247 . V_264 = V_245 -> V_264 ;
V_247 . V_103 = V_245 -> V_103 ;
V_247 . V_238 = 0 ;
if ( F_23 ( V_243 , & V_247 , sizeof V_247 ) )
return - V_28 ;
return 0 ;
}
T_1 F_98 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_98 V_17 ;
struct V_265 V_19 ;
T_4 T_2 * V_266 ;
T_4 T_2 * V_267 ;
struct V_214 * V_215 ;
struct V_244 V_245 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_215 = F_71 ( V_215 , V_17 . V_231 , V_11 -> V_22 ) ;
if ( ! V_215 )
return - V_30 ;
V_266 = ( void T_2 * ) ( unsigned long ) V_17 . V_32 ;
V_267 = V_266 + sizeof V_19 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
while ( V_19 . V_268 < V_17 . V_269 ) {
V_26 = F_99 ( V_215 , 1 , & V_245 ) ;
if ( V_26 < 0 )
goto V_270;
if ( ! V_26 )
break;
V_26 = F_97 ( V_267 , & V_245 ) ;
if ( V_26 )
goto V_270;
V_267 += sizeof( struct V_246 ) ;
++ V_19 . V_268 ;
}
if ( F_23 ( V_266 , & V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_270;
}
V_26 = V_15 ;
V_270:
F_73 ( V_215 ) ;
return V_26 ;
}
T_1 F_100 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_100 V_17 ;
struct V_214 * V_215 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_215 = F_71 ( V_215 , V_17 . V_231 , V_11 -> V_22 ) ;
if ( ! V_215 )
return - V_30 ;
F_101 ( V_215 , V_17 . V_271 ?
V_272 : V_273 ) ;
F_73 ( V_215 ) ;
return V_15 ;
}
T_1 F_102 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_102 V_17 ;
struct V_274 V_19 ;
struct V_5 * V_6 ;
struct V_214 * V_215 ;
struct V_208 * V_155 ;
struct V_275 * V_207 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_215 ) , V_17 . V_231 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
F_5 ( V_6 ) ;
V_215 = V_6 -> V_131 ;
V_207 = V_215 -> V_229 ;
V_155 = F_7 ( V_215 -> V_128 , struct V_208 , V_128 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_26 = F_45 ( V_6 ) ;
if ( V_26 ) {
F_103 ( V_6 ) ;
return V_26 ;
}
V_19 . V_220 = V_155 -> V_220 ;
V_19 . V_221 = V_155 -> V_221 ;
F_103 ( V_6 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
static int F_104 ( struct V_10 * V_11 ,
struct V_20 * V_209 ,
struct V_20 * V_210 ,
struct V_276 * V_17 ,
T_3 V_212 ,
int (* F_84)( struct V_10 * V_11 ,
struct V_277 * V_19 ,
struct V_20 * V_21 ) ,
void * V_4 )
{
struct V_278 * V_155 ;
struct V_12 * V_36 ;
struct V_125 * V_126 = NULL ;
struct V_138 * V_139 = NULL ;
struct V_5 * V_279 = F_85 ( - V_280 ) ;
struct V_214 * V_281 = NULL , * V_282 = NULL ;
struct V_283 * V_284 = NULL ;
struct V_285 * V_258 ;
char * V_14 ;
struct V_286 V_61 = {} ;
struct V_277 V_19 ;
int V_26 ;
struct V_287 * V_288 = NULL ;
bool V_289 = true ;
if ( V_17 -> V_290 == V_291 && ! F_105 ( V_292 ) )
return - V_293 ;
V_155 = (struct V_278 * ) F_38 ( F_3 ( V_258 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
V_155 -> V_294 = NULL ;
V_155 -> V_295 . V_128 . V_218 = V_17 -> V_218 ;
F_61 ( & V_155 -> V_296 ) ;
if ( V_212 >= F_86 ( F_87 ( * V_17 ) , V_297 ) +
sizeof( V_17 -> V_297 ) &&
( V_17 -> V_237 & V_298 ) ) {
V_288 = F_71 ( V_299 ,
V_17 -> V_297 ,
V_11 -> V_22 ) ;
if ( ! V_288 ) {
V_26 = - V_30 ;
goto V_182;
}
V_61 . V_300 = V_288 ;
}
if ( ( V_212 >= F_86 ( F_87 ( * V_17 ) , V_301 ) +
sizeof( V_17 -> V_301 ) ) && V_17 -> V_301 ) {
V_26 = - V_302 ;
goto V_182;
}
if ( V_288 && ( V_17 -> V_303 || V_17 -> V_304 || V_17 -> V_305 ) ) {
V_26 = - V_30 ;
goto V_182;
}
if ( V_288 && ! V_17 -> V_306 )
V_289 = false ;
if ( V_17 -> V_290 == V_307 ) {
V_279 = F_2 ( F_3 ( V_139 ) , V_17 -> V_132 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_279 ) ) {
V_26 = - V_30 ;
goto V_182;
}
V_139 = (struct V_138 * ) V_279 -> V_131 ;
if ( ! V_139 ) {
V_26 = - V_30 ;
goto V_182;
}
V_36 = V_139 -> V_36 ;
} else {
if ( V_17 -> V_290 == V_308 ) {
V_17 -> V_303 = 0 ;
V_17 -> V_304 = 0 ;
} else {
if ( V_17 -> V_305 ) {
V_284 = F_71 ( V_284 , V_17 -> V_309 ,
V_11 -> V_22 ) ;
if ( ! V_284 || V_284 -> V_310 != V_311 ) {
V_26 = - V_30 ;
goto V_182;
}
}
if ( ! V_288 ) {
if ( V_17 -> V_312 != V_17 -> V_313 ) {
V_282 = F_71 ( V_215 , V_17 -> V_312 ,
V_11 -> V_22 ) ;
if ( ! V_282 ) {
V_26 = - V_30 ;
goto V_182;
}
}
}
}
if ( V_289 )
V_281 = F_71 ( V_215 , V_17 -> V_313 ,
V_11 -> V_22 ) ;
if ( ! V_288 )
V_282 = V_282 ? : V_281 ;
V_126 = F_71 ( V_126 , V_17 -> V_132 , V_11 -> V_22 ) ;
if ( ! V_126 || ( ! V_281 && V_289 ) ) {
V_26 = - V_30 ;
goto V_182;
}
V_36 = V_126 -> V_36 ;
}
V_61 . V_227 = V_314 ;
V_61 . V_315 = V_11 ;
V_61 . V_316 = V_281 ;
V_61 . V_317 = V_282 ;
V_61 . V_284 = V_284 ;
V_61 . V_139 = V_139 ;
V_61 . V_318 = V_17 -> V_319 ? V_320 :
V_321 ;
V_61 . V_290 = V_17 -> V_290 ;
V_61 . V_322 = 0 ;
V_61 . V_323 . V_306 = V_17 -> V_306 ;
V_61 . V_323 . V_303 = V_17 -> V_303 ;
V_61 . V_323 . V_324 = V_17 -> V_324 ;
V_61 . V_323 . V_304 = V_17 -> V_304 ;
V_61 . V_323 . V_325 = V_17 -> V_325 ;
V_155 -> V_295 . V_326 = 0 ;
F_20 ( & V_155 -> V_295 . V_327 ) ;
F_20 ( & V_155 -> V_328 ) ;
if ( V_212 >= F_86 ( F_87 ( * V_17 ) , V_322 ) +
sizeof( V_17 -> V_322 ) )
V_61 . V_322 = V_17 -> V_322 ;
if ( V_61 . V_322 & ~ ( V_329 |
V_330 |
V_331 |
V_332 |
V_333 |
V_334 ) ) {
V_26 = - V_30 ;
goto V_182;
}
V_14 = ( void * ) V_17 + sizeof( * V_17 ) ;
if ( V_212 > sizeof( * V_17 ) )
if ( ! ( V_14 [ 0 ] == 0 && ! memcmp ( V_14 , V_14 + 1 ,
V_212 - sizeof( * V_17 ) - 1 ) ) ) {
V_26 = - V_30 ;
goto V_182;
}
if ( V_17 -> V_290 == V_307 )
V_258 = F_106 ( V_126 , & V_61 ) ;
else
V_258 = V_36 -> F_104 ( V_126 , & V_61 , V_210 ) ;
if ( F_4 ( V_258 ) ) {
V_26 = F_13 ( V_258 ) ;
goto V_182;
}
if ( V_17 -> V_290 != V_307 ) {
V_258 -> V_335 = V_258 ;
V_258 -> V_36 = V_36 ;
V_258 -> V_126 = V_126 ;
V_258 -> V_316 = V_61 . V_316 ;
V_258 -> V_317 = V_61 . V_317 ;
V_258 -> V_284 = V_61 . V_284 ;
V_258 -> V_300 = V_288 ;
V_258 -> V_227 = V_61 . V_227 ;
V_258 -> V_315 = V_61 . V_315 ;
V_258 -> V_290 = V_61 . V_290 ;
F_39 ( & V_258 -> V_130 , 0 ) ;
F_62 ( & V_126 -> V_130 ) ;
if ( V_61 . V_316 )
F_62 ( & V_61 . V_316 -> V_130 ) ;
if ( V_61 . V_317 )
F_62 ( & V_61 . V_317 -> V_130 ) ;
if ( V_61 . V_284 )
F_62 ( & V_61 . V_284 -> V_130 ) ;
if ( V_288 )
F_62 ( & V_288 -> V_130 ) ;
}
V_258 -> V_128 = & V_155 -> V_295 . V_128 ;
V_155 -> V_295 . V_128 . V_131 = V_258 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_230 . V_336 = V_258 -> V_257 ;
V_19 . V_230 . V_337 = V_155 -> V_295 . V_128 . V_133 ;
V_19 . V_230 . V_304 = V_61 . V_323 . V_304 ;
V_19 . V_230 . V_324 = V_61 . V_323 . V_324 ;
V_19 . V_230 . V_303 = V_61 . V_323 . V_303 ;
V_19 . V_230 . V_306 = V_61 . V_323 . V_306 ;
V_19 . V_230 . V_325 = V_61 . V_323 . V_325 ;
V_19 . V_232 = F_86 ( F_87 ( V_19 ) , V_232 ) +
sizeof( V_19 . V_232 ) ;
V_26 = F_84 ( V_11 , & V_19 , V_209 ) ;
if ( V_26 )
goto V_233;
if ( V_139 ) {
V_155 -> V_294 = F_7 ( V_279 , struct V_154 ,
V_128 ) ;
F_62 ( & V_155 -> V_294 -> V_168 ) ;
F_6 ( V_279 ) ;
}
if ( V_126 )
F_73 ( V_126 ) ;
if ( V_281 )
F_73 ( V_281 ) ;
if ( V_282 && V_282 != V_281 )
F_73 ( V_282 ) ;
if ( V_284 )
F_73 ( V_284 ) ;
if ( V_288 )
F_73 ( V_288 ) ;
F_40 ( & V_155 -> V_295 . V_128 ) ;
return 0 ;
V_233:
F_107 ( V_258 ) ;
V_182:
if ( ! F_4 ( V_279 ) )
F_6 ( V_279 ) ;
if ( V_126 )
F_73 ( V_126 ) ;
if ( V_281 )
F_73 ( V_281 ) ;
if ( V_282 && V_282 != V_281 )
F_73 ( V_282 ) ;
if ( V_284 )
F_73 ( V_284 ) ;
if ( V_288 )
F_73 ( V_288 ) ;
F_42 ( & V_155 -> V_295 . V_128 ) ;
return V_26 ;
}
static int F_108 ( struct V_10 * V_11 ,
struct V_277 * V_19 ,
struct V_20 * V_209 )
{
if ( F_91 ( V_209 , & V_19 -> V_230 , sizeof( V_19 -> V_230 ) ) )
return - V_28 ;
return 0 ;
}
T_1 F_109 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_109 V_17 ;
struct V_276 V_234 ;
struct V_20 V_209 ;
struct V_20 V_210 ;
T_1 V_338 = sizeof( struct V_339 ) ;
int V_31 ;
if ( V_16 < V_338 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
F_11 ( & V_209 , V_14 , ( unsigned long ) V_17 . V_32 , sizeof( V_17 ) ,
V_338 ) ;
F_11 ( & V_210 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + V_338 ,
V_15 - sizeof( V_17 ) - sizeof( struct V_201 ) ,
V_16 - V_338 ) ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_218 = V_17 . V_218 ;
V_234 . V_132 = V_17 . V_132 ;
V_234 . V_313 = V_17 . V_313 ;
V_234 . V_312 = V_17 . V_312 ;
V_234 . V_309 = V_17 . V_309 ;
V_234 . V_306 = V_17 . V_306 ;
V_234 . V_303 = V_17 . V_303 ;
V_234 . V_324 = V_17 . V_324 ;
V_234 . V_304 = V_17 . V_304 ;
V_234 . V_325 = V_17 . V_325 ;
V_234 . V_319 = V_17 . V_319 ;
V_234 . V_290 = V_17 . V_290 ;
V_234 . V_305 = V_17 . V_305 ;
V_31 = F_104 ( V_11 , & V_209 , & V_210 , & V_234 ,
F_86 ( F_87 ( V_234 ) , V_305 ) +
sizeof( V_17 . V_305 ) , F_108 ,
NULL ) ;
if ( V_31 )
return V_31 ;
return V_15 ;
}
static int F_110 ( struct V_10 * V_11 ,
struct V_277 * V_19 ,
struct V_20 * V_209 )
{
if ( F_91 ( V_209 , V_19 , V_19 -> V_232 ) )
return - V_28 ;
return 0 ;
}
int V_276 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_277 V_19 ;
struct V_276 V_17 = { 0 } ;
int V_31 ;
if ( V_209 -> V_236 < ( F_86 ( F_87 ( V_17 ) , V_237 ) +
sizeof( V_17 . V_237 ) ) )
return - V_30 ;
V_31 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_31 )
return V_31 ;
if ( V_17 . V_237 & ~ V_340 )
return - V_30 ;
if ( V_17 . V_238 )
return - V_30 ;
if ( V_209 -> V_239 < ( F_86 ( F_87 ( V_19 ) , V_232 ) +
sizeof( V_19 . V_232 ) ) )
return - V_27 ;
V_31 = F_104 ( V_11 , V_209 , V_210 , & V_17 ,
F_95 ( V_209 -> V_236 , sizeof( V_17 ) ) ,
F_110 , NULL ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
T_1 F_111 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 , int V_16 )
{
struct F_111 V_17 ;
struct V_339 V_19 ;
struct V_20 V_21 ;
struct V_278 * V_155 ;
struct V_138 * V_139 ;
struct V_5 * V_341 ( V_279 ) ;
struct V_285 * V_258 ;
struct V_342 V_61 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 , V_16 - sizeof V_19 ) ;
V_155 = (struct V_278 * ) F_38 ( F_3 ( V_258 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
V_279 = F_2 ( F_3 ( V_139 ) , V_17 . V_132 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_279 ) ) {
V_26 = - V_30 ;
goto V_182;
}
V_139 = (struct V_138 * ) V_279 -> V_131 ;
if ( ! V_139 ) {
V_26 = - V_30 ;
goto V_343;
}
V_61 . V_227 = V_314 ;
V_61 . V_315 = V_11 ;
V_61 . V_257 = V_17 . V_336 ;
V_61 . V_290 = V_17 . V_290 ;
V_155 -> V_295 . V_326 = 0 ;
F_20 ( & V_155 -> V_295 . V_327 ) ;
F_20 ( & V_155 -> V_328 ) ;
V_258 = F_112 ( V_139 , & V_61 ) ;
if ( F_4 ( V_258 ) ) {
V_26 = F_13 ( V_258 ) ;
goto V_343;
}
V_155 -> V_295 . V_128 . V_131 = V_258 ;
V_155 -> V_295 . V_128 . V_218 = V_17 . V_218 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_336 = V_258 -> V_257 ;
V_19 . V_337 = V_155 -> V_295 . V_128 . V_133 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_344;
}
V_155 -> V_294 = F_7 ( V_279 , struct V_154 , V_128 ) ;
F_62 ( & V_155 -> V_294 -> V_168 ) ;
V_258 -> V_128 = & V_155 -> V_295 . V_128 ;
F_6 ( V_279 ) ;
F_40 ( & V_155 -> V_295 . V_128 ) ;
return V_15 ;
V_344:
F_107 ( V_258 ) ;
V_343:
F_6 ( V_279 ) ;
V_182:
F_42 ( & V_155 -> V_295 . V_128 ) ;
return V_26 ;
}
T_1 F_113 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_113 V_17 ;
struct V_345 V_19 ;
struct V_285 * V_258 ;
struct V_346 * V_61 ;
struct V_286 * V_347 ;
const struct V_348 * V_349 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_61 = F_47 ( sizeof *V_61 , V_147 ) ;
V_347 = F_47 ( sizeof *V_347 , V_147 ) ;
if ( ! V_61 || ! V_347 ) {
V_26 = - V_148 ;
goto V_242;
}
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 ) {
V_26 = - V_30 ;
goto V_242;
}
V_26 = F_114 ( V_258 , V_61 , V_17 . V_350 , V_347 ) ;
F_73 ( V_258 ) ;
if ( V_26 )
goto V_242;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_351 = V_61 -> V_351 ;
V_19 . V_352 = V_61 -> V_352 ;
V_19 . V_353 = V_61 -> V_353 ;
V_19 . V_354 = V_61 -> V_354 ;
V_19 . V_355 = V_61 -> V_355 ;
V_19 . V_356 = V_61 -> V_356 ;
V_19 . V_357 = V_61 -> V_357 ;
V_19 . V_358 = V_61 -> V_358 ;
V_19 . V_359 = V_61 -> V_359 ;
V_19 . V_261 = V_61 -> V_261 ;
V_19 . V_360 = V_61 -> V_360 ;
V_19 . V_361 = V_61 -> V_361 ;
V_19 . V_362 = V_61 -> V_362 ;
V_19 . V_363 = V_61 -> V_363 ;
V_19 . V_364 = V_61 -> V_364 ;
V_19 . V_103 = V_61 -> V_103 ;
V_19 . V_365 = V_61 -> V_365 ;
V_19 . V_366 = V_61 -> V_366 ;
V_19 . V_367 = V_61 -> V_367 ;
V_19 . V_368 = V_61 -> V_368 ;
V_19 . V_369 = V_61 -> V_369 ;
V_19 . V_243 . V_370 = F_115 ( & V_61 -> V_371 ) ;
V_19 . V_243 . V_263 = F_116 ( & V_61 -> V_371 ) ;
V_19 . V_243 . V_372 = F_117 ( & V_61 -> V_371 ) ;
V_19 . V_243 . V_373 = F_118 ( & V_61 -> V_371 ) ;
V_19 . V_243 . V_374 = ! ! ( F_119 ( & V_61 -> V_371 ) &
V_375 ) ;
if ( V_19 . V_243 . V_374 ) {
V_349 = F_120 ( & V_61 -> V_371 ) ;
memcpy ( V_19 . V_243 . V_376 , V_349 -> V_376 . V_377 , 16 ) ;
V_19 . V_243 . V_378 = V_349 -> V_378 ;
V_19 . V_243 . V_379 = V_349 -> V_379 ;
V_19 . V_243 . V_380 = V_349 -> V_380 ;
V_19 . V_243 . V_381 = V_349 -> V_381 ;
}
V_19 . V_243 . V_103 = F_121 ( & V_61 -> V_371 ) ;
V_19 . V_382 . V_370 = F_115 ( & V_61 -> V_383 ) ;
V_19 . V_382 . V_263 = F_116 ( & V_61 -> V_383 ) ;
V_19 . V_382 . V_372 = F_117 ( & V_61 -> V_383 ) ;
V_19 . V_382 . V_373
= F_118 ( & V_61 -> V_383 ) ;
V_19 . V_382 . V_374
= ! ! ( F_119 ( & V_61 -> V_383 ) &
V_375 ) ;
if ( V_19 . V_382 . V_374 ) {
V_349 = F_120 ( & V_61 -> V_383 ) ;
memcpy ( V_19 . V_382 . V_376 , V_349 -> V_376 . V_377 , 16 ) ;
V_19 . V_382 . V_378 = V_349 -> V_378 ;
V_19 . V_382 . V_379 = V_349 -> V_379 ;
V_19 . V_382 . V_380 = V_349 -> V_380 ;
V_19 . V_382 . V_381 = V_349 -> V_381 ;
}
V_19 . V_382 . V_103 = F_121 ( & V_61 -> V_383 ) ;
V_19 . V_306 = V_347 -> V_323 . V_306 ;
V_19 . V_303 = V_347 -> V_323 . V_303 ;
V_19 . V_324 = V_347 -> V_323 . V_324 ;
V_19 . V_304 = V_347 -> V_323 . V_304 ;
V_19 . V_325 = V_347 -> V_323 . V_325 ;
V_19 . V_319 = V_347 -> V_318 == V_320 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_242:
F_49 ( V_61 ) ;
F_49 ( V_347 ) ;
return V_26 ? V_26 : V_15 ;
}
static int F_122 ( enum V_384 V_290 , int V_385 )
{
switch ( V_290 ) {
case V_308 :
return V_385 & ~ ( V_386 | V_387 ) ;
case V_307 :
return V_385 & ~ ( V_388 | V_389 |
V_390 ) ;
default:
return V_385 ;
}
}
static int F_123 ( struct V_10 * V_11 ,
struct V_391 * V_17 , struct V_20 * V_21 )
{
struct V_346 * V_61 ;
struct V_285 * V_258 ;
int V_26 ;
V_61 = F_47 ( sizeof *V_61 , V_147 ) ;
if ( ! V_61 )
return - V_148 ;
V_258 = F_71 ( V_258 , V_17 -> V_230 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 ) {
V_26 = - V_30 ;
goto V_242;
}
V_61 -> V_351 = V_17 -> V_230 . V_351 ;
V_61 -> V_352 = V_17 -> V_230 . V_352 ;
V_61 -> V_353 = V_17 -> V_230 . V_353 ;
V_61 -> V_354 = V_17 -> V_230 . V_354 ;
V_61 -> V_355 = V_17 -> V_230 . V_355 ;
V_61 -> V_356 = V_17 -> V_230 . V_356 ;
V_61 -> V_357 = V_17 -> V_230 . V_357 ;
V_61 -> V_358 = V_17 -> V_230 . V_358 ;
V_61 -> V_359 = V_17 -> V_230 . V_359 ;
V_61 -> V_261 = V_17 -> V_230 . V_261 ;
V_61 -> V_360 = V_17 -> V_230 . V_360 ;
V_61 -> V_392 = V_17 -> V_230 . V_392 ;
V_61 -> V_362 = V_17 -> V_230 . V_362 ;
V_61 -> V_363 = V_17 -> V_230 . V_363 ;
V_61 -> V_364 = V_17 -> V_230 . V_364 ;
V_61 -> V_103 = V_17 -> V_230 . V_103 ;
V_61 -> V_365 = V_17 -> V_230 . V_365 ;
V_61 -> V_366 = V_17 -> V_230 . V_366 ;
V_61 -> V_367 = V_17 -> V_230 . V_367 ;
V_61 -> V_368 = V_17 -> V_230 . V_368 ;
V_61 -> V_369 = V_17 -> V_230 . V_369 ;
V_61 -> V_393 = V_17 -> V_393 ;
V_61 -> V_371 . type = F_124 ( V_258 -> V_36 ,
V_17 -> V_230 . V_243 . V_103 ) ;
if ( V_17 -> V_230 . V_243 . V_374 ) {
F_125 ( & V_61 -> V_371 , NULL ,
V_17 -> V_230 . V_243 . V_378 ,
V_17 -> V_230 . V_243 . V_379 ,
V_17 -> V_230 . V_243 . V_380 ,
V_17 -> V_230 . V_243 . V_381 ) ;
F_126 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_376 ) ;
} else {
F_127 ( & V_61 -> V_371 , 0 ) ;
}
F_128 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_370 ) ;
F_129 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_263 ) ;
F_130 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_372 ) ;
F_131 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_373 ) ;
F_132 ( & V_61 -> V_371 ,
V_17 -> V_230 . V_243 . V_103 ) ;
V_61 -> V_383 . type = F_124 ( V_258 -> V_36 ,
V_17 -> V_230 . V_243 . V_103 ) ;
if ( V_17 -> V_230 . V_382 . V_374 ) {
F_125 ( & V_61 -> V_383 , NULL ,
V_17 -> V_230 . V_382 . V_378 ,
V_17 -> V_230 . V_382 . V_379 ,
V_17 -> V_230 . V_382 . V_380 ,
V_17 -> V_230 . V_382 . V_381 ) ;
F_126 ( & V_61 -> V_383 ,
V_17 -> V_230 . V_382 . V_376 ) ;
} else {
F_127 ( & V_61 -> V_383 , 0 ) ;
}
F_128 ( & V_61 -> V_383 , V_17 -> V_230 . V_382 . V_370 ) ;
F_129 ( & V_61 -> V_383 , V_17 -> V_230 . V_382 . V_263 ) ;
F_130 ( & V_61 -> V_383 ,
V_17 -> V_230 . V_382 . V_372 ) ;
F_131 ( & V_61 -> V_383 ,
V_17 -> V_230 . V_382 . V_373 ) ;
F_132 ( & V_61 -> V_383 ,
V_17 -> V_230 . V_382 . V_103 ) ;
if ( V_258 -> V_335 == V_258 ) {
if ( V_17 -> V_230 . V_350 & V_394 ) {
V_26 = F_133 ( V_258 -> V_36 , & V_61 -> V_371 ) ;
if ( V_26 )
goto V_395;
}
V_26 = V_258 -> V_36 -> F_123 ( V_258 , V_61 ,
F_122 ( V_258 -> V_290 ,
V_17 -> V_230 . V_350 ) ,
V_21 ) ;
} else {
V_26 = F_134 ( V_258 , V_61 ,
F_122 ( V_258 -> V_290 ,
V_17 -> V_230 . V_350 ) ) ;
}
V_395:
F_73 ( V_258 ) ;
V_242:
F_49 ( V_61 ) ;
return V_26 ;
}
T_1 F_135 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct V_391 V_17 = {} ;
struct V_20 V_21 ;
int V_26 ;
if ( F_9 ( & V_17 . V_230 , V_14 , sizeof( V_17 . V_230 ) ) )
return - V_28 ;
if ( V_17 . V_230 . V_350 &
~ ( ( V_396 << 1 ) - 1 ) )
return - V_302 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 . V_230 ) , NULL ,
V_15 - sizeof( V_17 . V_230 ) , V_16 ) ;
V_26 = F_123 ( V_11 , & V_17 , & V_21 ) ;
if ( V_26 )
return V_26 ;
return V_15 ;
}
int V_391 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_391 V_17 = {} ;
int V_26 ;
F_136 ( V_397 == ( 1 << 31 ) ) ;
if ( V_209 -> V_236 < sizeof( V_17 . V_230 ) )
return - V_30 ;
V_26 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_230 . V_350 &
~ ( ( V_397 << 1 ) - 1 ) )
return - V_302 ;
if ( V_209 -> V_236 > sizeof( V_17 ) ) {
if ( F_137 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_302 ;
}
V_26 = F_123 ( V_11 , & V_17 , V_210 ) ;
return V_26 ;
}
T_1 F_138 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_138 V_17 ;
struct V_398 V_19 ;
struct V_5 * V_6 ;
struct V_285 * V_258 ;
struct V_278 * V_155 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_6 = F_44 ( F_3 ( V_258 ) , V_17 . V_337 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_258 = V_6 -> V_131 ;
V_155 = F_7 ( V_6 , struct V_278 , V_295 . V_128 ) ;
F_5 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
if ( V_26 ) {
F_103 ( V_6 ) ;
return V_26 ;
}
V_19 . V_326 = V_155 -> V_295 . V_326 ;
F_103 ( V_6 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
static void * F_139 ( T_3 V_399 , V_255 V_400 )
{
if ( V_400 >= ( V_401 - F_140 ( V_399 , sizeof ( struct V_402 ) ) ) /
sizeof ( struct V_402 ) )
return NULL ;
return F_47 ( F_140 ( V_399 , sizeof ( struct V_402 ) ) +
V_400 * sizeof ( struct V_402 ) , V_147 ) ;
}
T_1 F_141 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_141 V_17 ;
struct V_403 V_19 ;
struct V_404 * V_405 ;
struct V_406 * V_407 = NULL , * V_408 , * V_409 , * V_410 ;
struct V_285 * V_258 ;
int V_411 , V_412 ;
int V_413 ;
T_1 V_26 = - V_30 ;
T_3 V_414 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
if ( V_15 < sizeof V_17 + V_17 . V_415 * V_17 . V_416 +
V_17 . V_417 * sizeof ( struct V_418 ) )
return - V_30 ;
if ( V_17 . V_415 < sizeof ( struct V_404 ) )
return - V_30 ;
V_405 = F_47 ( V_17 . V_415 , V_147 ) ;
if ( ! V_405 )
return - V_148 ;
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 )
goto V_242;
V_413 = V_258 -> V_290 == V_419 ;
V_412 = 0 ;
V_408 = NULL ;
for ( V_411 = 0 ; V_411 < V_17 . V_416 ; ++ V_411 ) {
if ( F_9 ( V_405 ,
V_14 + sizeof V_17 + V_411 * V_17 . V_415 ,
V_17 . V_415 ) ) {
V_26 = - V_28 ;
goto V_270;
}
if ( V_405 -> V_400 + V_412 > V_17 . V_417 ) {
V_26 = - V_30 ;
goto V_270;
}
if ( V_413 ) {
struct V_420 * V_421 ;
if ( V_405 -> V_250 != V_422 &&
V_405 -> V_250 != V_423 ) {
V_26 = - V_30 ;
goto V_270;
}
V_414 = sizeof( * V_421 ) ;
V_421 = F_139 ( V_414 , V_405 -> V_400 ) ;
if ( ! V_421 ) {
V_26 = - V_148 ;
goto V_270;
}
V_421 -> V_424 = F_71 ( V_424 , V_405 -> V_407 . V_421 . V_424 ,
V_11 -> V_22 ) ;
if ( ! V_421 -> V_424 ) {
F_49 ( V_421 ) ;
V_26 = - V_30 ;
goto V_270;
}
V_421 -> V_425 = V_405 -> V_407 . V_421 . V_425 ;
V_421 -> V_426 = V_405 -> V_407 . V_421 . V_426 ;
V_409 = & V_421 -> V_407 ;
} else if ( V_405 -> V_250 == V_427 ||
V_405 -> V_250 == V_428 ||
V_405 -> V_250 == V_429 ) {
struct V_430 * V_431 ;
V_414 = sizeof( * V_431 ) ;
V_431 = F_139 ( V_414 , V_405 -> V_400 ) ;
if ( ! V_431 ) {
V_26 = - V_148 ;
goto V_270;
}
V_431 -> V_432 = V_405 -> V_407 . V_431 . V_432 ;
V_431 -> V_186 = V_405 -> V_407 . V_431 . V_186 ;
V_409 = & V_431 -> V_407 ;
} else if ( V_405 -> V_250 == V_433 ||
V_405 -> V_250 == V_434 ) {
struct V_435 * V_436 ;
V_414 = sizeof( * V_436 ) ;
V_436 = F_139 ( V_414 , V_405 -> V_400 ) ;
if ( ! V_436 ) {
V_26 = - V_148 ;
goto V_270;
}
V_436 -> V_432 = V_405 -> V_407 . V_436 . V_432 ;
V_436 -> V_437 = V_405 -> V_407 . V_436 . V_437 ;
V_436 -> V_438 = V_405 -> V_407 . V_436 . V_438 ;
V_436 -> V_186 = V_405 -> V_407 . V_436 . V_186 ;
V_409 = & V_436 -> V_407 ;
} else if ( V_405 -> V_250 == V_422 ||
V_405 -> V_250 == V_423 ||
V_405 -> V_250 == V_439 ) {
V_414 = sizeof( * V_409 ) ;
V_409 = F_139 ( V_414 , V_405 -> V_400 ) ;
if ( ! V_409 ) {
V_26 = - V_148 ;
goto V_270;
}
} else {
V_26 = - V_30 ;
goto V_270;
}
if ( V_405 -> V_250 == V_423 ||
V_405 -> V_250 == V_427 ) {
V_409 -> V_253 . V_254 =
( V_440 V_256 ) V_405 -> V_253 . V_254 ;
} else if ( V_405 -> V_250 == V_439 ) {
V_409 -> V_253 . V_441 = V_405 -> V_253 . V_441 ;
}
if ( ! V_408 )
V_407 = V_409 ;
else
V_408 -> V_409 = V_409 ;
V_408 = V_409 ;
V_409 -> V_409 = NULL ;
V_409 -> V_248 = V_405 -> V_248 ;
V_409 -> V_400 = V_405 -> V_400 ;
V_409 -> V_250 = V_405 -> V_250 ;
V_409 -> V_442 = V_405 -> V_442 ;
if ( V_409 -> V_400 ) {
V_409 -> V_443 = ( void * ) V_409 +
F_140 ( V_414 , sizeof( struct V_402 ) ) ;
if ( F_9 ( V_409 -> V_443 ,
V_14 + sizeof V_17 +
V_17 . V_416 * V_17 . V_415 +
V_412 * sizeof ( struct V_402 ) ,
V_409 -> V_400 * sizeof ( struct V_402 ) ) ) {
V_26 = - V_28 ;
goto V_270;
}
V_412 += V_409 -> V_400 ;
} else
V_409 -> V_443 = NULL ;
}
V_19 . V_410 = 0 ;
V_26 = V_258 -> V_36 -> V_444 ( V_258 -> V_335 , V_407 , & V_410 ) ;
if ( V_26 )
for ( V_409 = V_407 ; V_409 ; V_409 = V_409 -> V_409 ) {
++ V_19 . V_410 ;
if ( V_409 == V_410 )
break;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_270:
F_73 ( V_258 ) ;
while ( V_407 ) {
if ( V_413 && F_142 ( V_407 ) -> V_424 )
F_73 ( F_142 ( V_407 ) -> V_424 ) ;
V_409 = V_407 -> V_409 ;
F_49 ( V_407 ) ;
V_407 = V_409 ;
}
V_242:
F_49 ( V_405 ) ;
return V_26 ? V_26 : V_15 ;
}
static struct V_445 * F_143 ( const char T_2 * V_14 ,
int V_15 ,
T_5 V_416 ,
T_5 V_417 ,
T_5 V_415 )
{
struct V_446 * V_405 ;
struct V_445 * V_407 = NULL , * V_408 , * V_409 ;
int V_412 ;
int V_411 ;
int V_26 ;
if ( V_15 < V_415 * V_416 +
V_417 * sizeof ( struct V_418 ) )
return F_85 ( - V_30 ) ;
if ( V_415 < sizeof ( struct V_446 ) )
return F_85 ( - V_30 ) ;
V_405 = F_47 ( V_415 , V_147 ) ;
if ( ! V_405 )
return F_85 ( - V_148 ) ;
V_412 = 0 ;
V_408 = NULL ;
for ( V_411 = 0 ; V_411 < V_416 ; ++ V_411 ) {
if ( F_9 ( V_405 , V_14 + V_411 * V_415 ,
V_415 ) ) {
V_26 = - V_28 ;
goto V_31;
}
if ( V_405 -> V_400 + V_412 > V_417 ) {
V_26 = - V_30 ;
goto V_31;
}
if ( V_405 -> V_400 >=
( V_401 - F_140 ( sizeof *V_409 , sizeof ( struct V_402 ) ) ) /
sizeof ( struct V_402 ) ) {
V_26 = - V_30 ;
goto V_31;
}
V_409 = F_47 ( F_140 ( sizeof *V_409 , sizeof ( struct V_402 ) ) +
V_405 -> V_400 * sizeof ( struct V_402 ) ,
V_147 ) ;
if ( ! V_409 ) {
V_26 = - V_148 ;
goto V_31;
}
if ( ! V_408 )
V_407 = V_409 ;
else
V_408 -> V_409 = V_409 ;
V_408 = V_409 ;
V_409 -> V_409 = NULL ;
V_409 -> V_248 = V_405 -> V_248 ;
V_409 -> V_400 = V_405 -> V_400 ;
if ( V_409 -> V_400 ) {
V_409 -> V_443 = ( void * ) V_409 +
F_140 ( sizeof *V_409 , sizeof ( struct V_402 ) ) ;
if ( F_9 ( V_409 -> V_443 ,
V_14 + V_416 * V_415 +
V_412 * sizeof ( struct V_402 ) ,
V_409 -> V_400 * sizeof ( struct V_402 ) ) ) {
V_26 = - V_28 ;
goto V_31;
}
V_412 += V_409 -> V_400 ;
} else
V_409 -> V_443 = NULL ;
}
F_49 ( V_405 ) ;
return V_407 ;
V_31:
F_49 ( V_405 ) ;
while ( V_407 ) {
V_409 = V_407 -> V_409 ;
F_49 ( V_407 ) ;
V_407 = V_409 ;
}
return F_85 ( V_26 ) ;
}
T_1 F_144 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_144 V_17 ;
struct V_447 V_19 ;
struct V_445 * V_407 , * V_409 , * V_410 ;
struct V_285 * V_258 ;
T_1 V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_407 = F_143 ( V_14 + sizeof V_17 ,
V_15 - sizeof V_17 , V_17 . V_416 ,
V_17 . V_417 , V_17 . V_415 ) ;
if ( F_4 ( V_407 ) )
return F_13 ( V_407 ) ;
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 )
goto V_242;
V_19 . V_410 = 0 ;
V_26 = V_258 -> V_36 -> V_448 ( V_258 -> V_335 , V_407 , & V_410 ) ;
F_73 ( V_258 ) ;
if ( V_26 ) {
for ( V_409 = V_407 ; V_409 ; V_409 = V_409 -> V_409 ) {
++ V_19 . V_410 ;
if ( V_409 == V_410 )
break;
}
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_242:
while ( V_407 ) {
V_409 = V_407 -> V_409 ;
F_49 ( V_407 ) ;
V_407 = V_409 ;
}
return V_26 ? V_26 : V_15 ;
}
T_1 F_145 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_145 V_17 ;
struct V_449 V_19 ;
struct V_445 * V_407 , * V_409 , * V_410 ;
struct V_283 * V_284 ;
T_1 V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_407 = F_143 ( V_14 + sizeof V_17 ,
V_15 - sizeof V_17 , V_17 . V_416 ,
V_17 . V_417 , V_17 . V_415 ) ;
if ( F_4 ( V_407 ) )
return F_13 ( V_407 ) ;
V_284 = F_71 ( V_284 , V_17 . V_309 , V_11 -> V_22 ) ;
if ( ! V_284 )
goto V_242;
V_19 . V_410 = 0 ;
V_26 = V_284 -> V_36 -> V_450 ( V_284 , V_407 , & V_410 ) ;
F_73 ( V_284 ) ;
if ( V_26 )
for ( V_409 = V_407 ; V_409 ; V_409 = V_409 -> V_409 ) {
++ V_19 . V_410 ;
if ( V_409 == V_410 )
break;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_242:
while ( V_407 ) {
V_409 = V_407 -> V_409 ;
F_49 ( V_407 ) ;
V_407 = V_409 ;
}
return V_26 ? V_26 : V_15 ;
}
T_1 F_146 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_146 V_17 ;
struct V_451 V_19 ;
struct V_5 * V_6 ;
struct V_125 * V_126 ;
struct V_452 * V_424 ;
struct V_453 V_61 ;
int V_26 ;
struct V_20 V_21 ;
T_4 * V_454 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) , V_16 - sizeof( V_19 ) ) ;
V_6 = F_38 ( F_3 ( V_424 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_126 = F_71 ( V_126 , V_17 . V_132 , V_11 -> V_22 ) ;
if ( ! V_126 ) {
V_26 = - V_30 ;
goto V_31;
}
V_61 . type = F_124 ( V_13 , V_17 . V_61 . V_103 ) ;
F_128 ( & V_61 , V_17 . V_61 . V_370 ) ;
F_129 ( & V_61 , V_17 . V_61 . V_263 ) ;
F_130 ( & V_61 , V_17 . V_61 . V_372 ) ;
F_131 ( & V_61 , V_17 . V_61 . V_373 ) ;
F_132 ( & V_61 , V_17 . V_61 . V_103 ) ;
if ( V_17 . V_61 . V_374 ) {
F_125 ( & V_61 , NULL , V_17 . V_61 . V_349 . V_378 ,
V_17 . V_61 . V_349 . V_379 ,
V_17 . V_61 . V_349 . V_380 ,
V_17 . V_61 . V_349 . V_381 ) ;
F_126 ( & V_61 , V_17 . V_61 . V_349 . V_376 ) ;
} else {
F_127 ( & V_61 , 0 ) ;
}
V_454 = F_147 ( & V_61 ) ;
if ( V_454 )
memset ( V_454 , 0 , V_455 ) ;
V_424 = V_126 -> V_36 -> V_456 ( V_126 , & V_61 , & V_21 ) ;
if ( F_4 ( V_424 ) ) {
V_26 = F_13 ( V_424 ) ;
goto V_182;
}
V_424 -> V_36 = V_126 -> V_36 ;
V_424 -> V_126 = V_126 ;
F_62 ( & V_126 -> V_130 ) ;
V_424 -> V_128 = V_6 ;
V_6 -> V_218 = V_17 . V_218 ;
V_6 -> V_131 = V_424 ;
V_19 . V_457 = V_6 -> V_133 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_134;
}
F_73 ( V_126 ) ;
F_40 ( V_6 ) ;
return V_15 ;
V_134:
F_148 ( V_424 ) ;
V_182:
F_73 ( V_126 ) ;
V_31:
F_42 ( V_6 ) ;
return V_26 ;
}
T_1 F_149 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 , int V_16 )
{
struct F_149 V_17 ;
struct V_5 * V_6 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_424 ) , V_17 . V_457 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
return V_26 ? : V_15 ;
}
T_1 F_150 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_150 V_17 ;
struct V_285 * V_258 ;
struct V_278 * V_155 ;
struct V_458 * V_459 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 )
return - V_30 ;
V_155 = F_7 ( V_258 -> V_128 , struct V_278 , V_295 . V_128 ) ;
F_10 ( & V_155 -> V_296 ) ;
F_151 (mcast, &obj->mcast_list, list)
if ( V_17 . V_460 == V_459 -> V_113 &&
! memcmp ( V_17 . V_461 , V_459 -> V_461 . V_377 , sizeof V_459 -> V_461 . V_377 ) ) {
V_26 = 0 ;
goto V_270;
}
V_459 = F_47 ( sizeof *V_459 , V_147 ) ;
if ( ! V_459 ) {
V_26 = - V_148 ;
goto V_270;
}
V_459 -> V_113 = V_17 . V_460 ;
memcpy ( V_459 -> V_461 . V_377 , V_17 . V_461 , sizeof V_459 -> V_461 . V_377 ) ;
V_26 = F_152 ( V_258 , & V_459 -> V_461 , V_17 . V_460 ) ;
if ( ! V_26 )
F_153 ( & V_459 -> V_462 , & V_155 -> V_328 ) ;
else
F_49 ( V_459 ) ;
V_270:
F_25 ( & V_155 -> V_296 ) ;
F_73 ( V_258 ) ;
return V_26 ? V_26 : V_15 ;
}
T_1 F_154 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_154 V_17 ;
struct V_278 * V_155 ;
struct V_285 * V_258 ;
struct V_458 * V_459 ;
int V_26 = - V_30 ;
bool V_463 = false ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 )
return - V_30 ;
V_155 = F_7 ( V_258 -> V_128 , struct V_278 , V_295 . V_128 ) ;
F_10 ( & V_155 -> V_296 ) ;
F_151 (mcast, &obj->mcast_list, list)
if ( V_17 . V_460 == V_459 -> V_113 &&
! memcmp ( V_17 . V_461 , V_459 -> V_461 . V_377 , sizeof V_459 -> V_461 . V_377 ) ) {
F_155 ( & V_459 -> V_462 ) ;
F_49 ( V_459 ) ;
V_463 = true ;
break;
}
if ( ! V_463 ) {
V_26 = - V_30 ;
goto V_270;
}
V_26 = F_156 ( V_258 , (union V_464 * ) V_17 . V_461 , V_17 . V_460 ) ;
V_270:
F_25 ( & V_155 -> V_296 ) ;
F_73 ( V_258 ) ;
return V_26 ? V_26 : V_15 ;
}
static int F_157 ( struct V_465 * V_466 ,
union V_467 * V_468 )
{
V_468 -> type = V_466 -> type ;
switch ( V_468 -> type ) {
case V_469 :
if ( V_466 -> V_470 . V_471 !=
sizeof( struct V_472 ) )
return - V_30 ;
V_468 -> V_470 . V_471 = sizeof( struct V_473 ) ;
V_468 -> V_470 . V_474 = V_466 -> V_470 . V_474 ;
break;
case V_475 :
if ( V_466 -> V_476 . V_471 !=
sizeof( struct V_477 ) )
return - V_30 ;
V_468 -> V_476 . V_471 = sizeof( struct V_478 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static T_3 F_158 ( struct V_479 * V_480 )
{
return ( V_480 -> V_471 - sizeof( struct V_479 ) ) / 2 ;
}
static T_1 F_159 ( void * V_481 , T_6 V_482 ,
T_6 V_483 )
{
if ( V_482 > V_483 ) {
if ( F_160 ( V_481 +
V_483 , 0 ,
V_482 - V_483 ) )
return - V_30 ;
return V_483 ;
}
return V_482 ;
}
static int F_161 ( struct V_465 * V_466 ,
union V_467 * V_468 )
{
T_1 V_484 ;
T_1 V_485 ;
T_1 V_486 ;
void * V_487 ;
void * V_488 ;
if ( V_466 -> V_238 )
return - V_30 ;
V_468 -> type = V_466 -> type ;
V_485 = F_158 ( & V_466 -> V_489 ) ;
if ( V_485 != F_140 ( V_485 , 4 ) )
return - V_30 ;
V_488 = ( void * ) V_466 +
sizeof( struct V_479 ) ;
V_487 = V_488 + V_485 ;
if ( V_468 -> type == ( V_490 | V_491 ) )
return - V_30 ;
switch ( V_468 -> type & ~ V_490 ) {
case V_492 :
V_486 = F_86 ( struct V_493 , V_494 ) ;
V_484 = F_159 ( V_487 ,
V_485 ,
V_486 ) ;
if ( V_484 <= 0 )
return - V_30 ;
V_468 -> V_471 = sizeof( struct V_495 ) ;
memcpy ( & V_468 -> V_496 . V_497 , V_488 , V_484 ) ;
memcpy ( & V_468 -> V_496 . V_385 , V_487 , V_484 ) ;
break;
case V_498 :
V_486 = F_86 ( struct V_499 , V_494 ) ;
V_484 = F_159 ( V_487 ,
V_485 ,
V_486 ) ;
if ( V_484 <= 0 )
return - V_30 ;
V_468 -> V_471 = sizeof( struct V_500 ) ;
memcpy ( & V_468 -> V_501 . V_497 , V_488 , V_484 ) ;
memcpy ( & V_468 -> V_501 . V_385 , V_487 , V_484 ) ;
break;
case V_502 :
V_486 = F_86 ( struct V_503 , V_494 ) ;
V_484 = F_159 ( V_487 ,
V_485 ,
V_486 ) ;
if ( V_484 <= 0 )
return - V_30 ;
V_468 -> V_471 = sizeof( struct V_504 ) ;
memcpy ( & V_468 -> V_505 . V_497 , V_488 , V_484 ) ;
memcpy ( & V_468 -> V_505 . V_385 , V_487 , V_484 ) ;
if ( ( F_162 ( V_468 -> V_505 . V_385 . V_378 ) ) >= F_163 ( 20 ) ||
( F_162 ( V_468 -> V_505 . V_497 . V_378 ) ) >= F_163 ( 20 ) )
return - V_30 ;
break;
case V_506 :
case V_507 :
V_486 = F_86 ( struct V_508 , V_494 ) ;
V_484 = F_159 ( V_487 ,
V_485 ,
V_486 ) ;
if ( V_484 <= 0 )
return - V_30 ;
V_468 -> V_471 = sizeof( struct V_509 ) ;
memcpy ( & V_468 -> V_510 . V_497 , V_488 , V_484 ) ;
memcpy ( & V_468 -> V_510 . V_385 , V_487 , V_484 ) ;
break;
case V_491 :
V_486 = F_86 ( struct V_511 , V_494 ) ;
V_484 = F_159 ( V_487 ,
V_485 ,
V_486 ) ;
if ( V_484 <= 0 )
return - V_30 ;
V_468 -> V_512 . V_471 = sizeof( struct V_513 ) ;
memcpy ( & V_468 -> V_512 . V_497 , V_488 , V_484 ) ;
memcpy ( & V_468 -> V_512 . V_385 , V_487 , V_484 ) ;
if ( ( F_162 ( V_468 -> V_512 . V_385 . V_514 ) ) >= F_163 ( 24 ) ||
( F_162 ( V_468 -> V_512 . V_497 . V_514 ) ) >= F_163 ( 24 ) )
return - V_30 ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_164 ( struct V_465 * V_466 ,
union V_467 * V_468 )
{
if ( V_466 -> V_238 )
return - V_30 ;
if ( V_466 -> type >= V_469 )
return F_157 ( V_466 , V_468 ) ;
else
return F_161 ( V_466 , V_468 ) ;
}
int F_165 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_165 V_17 = {} ;
struct V_515 V_19 = {} ;
struct V_516 * V_155 ;
int V_31 = 0 ;
struct V_214 * V_215 ;
struct V_125 * V_126 ;
struct V_517 * V_518 ;
struct V_519 V_520 = {} ;
T_3 V_521 ;
T_3 V_522 ;
V_521 = F_86 ( F_87 ( V_17 ) , V_72 ) + sizeof( V_17 . V_72 ) ;
V_522 = F_86 ( F_87 ( V_19 ) , V_523 ) + sizeof( V_19 . V_523 ) ;
if ( V_209 -> V_236 < V_521 )
return - V_30 ;
if ( V_209 -> V_239 < V_522 )
return - V_27 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_137 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_302 ;
V_31 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_31 )
return V_31 ;
if ( V_17 . V_237 )
return - V_302 ;
V_155 = (struct V_516 * ) F_38 ( F_3 ( V_518 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
V_126 = F_71 ( V_126 , V_17 . V_132 , V_11 -> V_22 ) ;
if ( ! V_126 ) {
V_31 = - V_30 ;
goto V_524;
}
V_215 = F_71 ( V_215 , V_17 . V_231 , V_11 -> V_22 ) ;
if ( ! V_215 ) {
V_31 = - V_30 ;
goto V_525;
}
V_520 . V_215 = V_215 ;
V_520 . V_72 = V_17 . V_72 ;
V_520 . V_526 = V_17 . V_526 ;
V_520 . V_527 = V_11 ;
V_520 . V_528 = V_17 . V_528 ;
V_520 . V_227 = V_529 ;
if ( V_209 -> V_236 >= ( F_86 ( F_87 ( V_17 ) , V_322 ) +
sizeof( V_17 . V_322 ) ) )
V_520 . V_322 = V_17 . V_322 ;
V_155 -> V_295 . V_326 = 0 ;
F_20 ( & V_155 -> V_295 . V_327 ) ;
V_518 = V_126 -> V_36 -> V_530 ( V_126 , & V_520 , V_210 ) ;
if ( F_4 ( V_518 ) ) {
V_31 = F_13 ( V_518 ) ;
goto V_531;
}
V_518 -> V_128 = & V_155 -> V_295 . V_128 ;
V_155 -> V_295 . V_128 . V_131 = V_518 ;
V_518 -> V_528 = V_520 . V_528 ;
V_518 -> V_215 = V_215 ;
V_518 -> V_126 = V_126 ;
V_518 -> V_36 = V_126 -> V_36 ;
V_518 -> V_527 = V_520 . V_527 ;
F_39 ( & V_518 -> V_130 , 0 ) ;
F_62 ( & V_126 -> V_130 ) ;
F_62 ( & V_215 -> V_130 ) ;
V_518 -> V_128 = & V_155 -> V_295 . V_128 ;
V_155 -> V_295 . V_128 . V_131 = V_518 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_532 = V_155 -> V_295 . V_128 . V_133 ;
V_19 . V_72 = V_520 . V_72 ;
V_19 . V_526 = V_520 . V_526 ;
V_19 . V_523 = V_518 -> V_533 ;
V_19 . V_232 = V_522 ;
V_31 = F_91 ( V_209 ,
& V_19 , V_19 . V_232 ) ;
if ( V_31 )
goto V_134;
F_73 ( V_126 ) ;
F_73 ( V_215 ) ;
F_40 ( & V_155 -> V_295 . V_128 ) ;
return 0 ;
V_134:
F_166 ( V_518 ) ;
V_531:
F_73 ( V_215 ) ;
V_525:
F_73 ( V_126 ) ;
V_524:
F_42 ( & V_155 -> V_295 . V_128 ) ;
return V_31 ;
}
int F_167 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_167 V_17 = {} ;
struct V_534 V_19 = {} ;
struct V_517 * V_518 ;
struct V_5 * V_6 ;
struct V_516 * V_155 ;
T_3 V_521 ;
T_3 V_522 ;
int V_26 ;
V_521 = F_86 ( F_87 ( V_17 ) , V_532 ) + sizeof( V_17 . V_532 ) ;
V_522 = F_86 ( F_87 ( V_19 ) , V_238 ) + sizeof( V_19 . V_238 ) ;
if ( V_209 -> V_236 < V_521 )
return - V_30 ;
if ( V_209 -> V_239 < V_522 )
return - V_27 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_137 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_302 ;
V_26 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_237 )
return - V_302 ;
V_19 . V_232 = V_522 ;
V_6 = F_44 ( F_3 ( V_518 ) , V_17 . V_532 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_518 = V_6 -> V_131 ;
V_155 = F_7 ( V_6 , struct V_516 , V_295 . V_128 ) ;
F_5 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
V_19 . V_326 = V_155 -> V_295 . V_326 ;
F_103 ( V_6 ) ;
if ( V_26 )
return V_26 ;
return F_91 ( V_209 , & V_19 , V_19 . V_232 ) ;
}
int F_168 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_168 V_17 = {} ;
struct V_517 * V_518 ;
struct V_535 V_536 = {} ;
T_3 V_521 ;
int V_26 ;
V_521 = F_86 ( F_87 ( V_17 ) , V_537 ) + sizeof( V_17 . V_537 ) ;
if ( V_209 -> V_236 < V_521 )
return - V_30 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_137 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_302 ;
V_26 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( ! V_17 . V_350 )
return - V_30 ;
if ( V_17 . V_350 > ( V_538 | V_539 | V_540 ) )
return - V_30 ;
V_518 = F_71 ( V_518 , V_17 . V_532 , V_11 -> V_22 ) ;
if ( ! V_518 )
return - V_30 ;
V_536 . V_537 = V_17 . V_537 ;
V_536 . V_541 = V_17 . V_541 ;
if ( V_17 . V_350 & V_540 ) {
V_536 . V_190 = V_17 . V_190 ;
V_536 . V_542 = V_17 . V_542 ;
}
V_26 = V_518 -> V_36 -> V_543 ( V_518 , & V_536 , V_17 . V_350 , V_210 ) ;
F_73 ( V_518 ) ;
return V_26 ;
}
int F_169 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_169 V_17 = {} ;
struct V_544 V_19 = {} ;
struct V_5 * V_6 ;
int V_31 = 0 ;
struct V_545 V_347 = {} ;
struct V_287 * V_300 ;
struct V_517 * * V_546 = NULL ;
T_5 * V_547 = NULL ;
struct V_517 * V_518 = NULL ;
int V_411 , V_548 , V_549 ;
T_5 V_550 ;
T_5 V_551 ;
T_3 V_552 ;
T_3 V_522 ;
V_552 = F_86 ( F_87 ( V_17 ) , V_553 ) + sizeof( V_17 . V_553 ) ;
V_522 = F_86 ( F_87 ( V_19 ) , V_554 ) + sizeof( V_19 . V_554 ) ;
if ( V_209 -> V_236 < V_552 )
return - V_30 ;
if ( V_209 -> V_239 < V_522 )
return - V_27 ;
V_31 = F_94 ( & V_17 , V_209 , V_552 ) ;
if ( V_31 )
return V_31 ;
V_209 -> V_555 += V_552 ;
V_209 -> V_236 -= V_552 ;
if ( V_17 . V_237 )
return - V_302 ;
if ( V_17 . V_553 > V_556 )
return - V_30 ;
V_550 = 1 << V_17 . V_553 ;
V_551 = V_550 * sizeof( V_255 ) ;
if ( V_550 == 1 )
V_551 += sizeof( V_255 ) ;
if ( V_209 -> V_236 < V_551 )
return - V_30 ;
if ( V_209 -> V_236 > V_551 &&
! F_137 ( V_209 , V_551 ,
V_209 -> V_236 - V_551 ) )
return - V_302 ;
V_547 = F_170 ( V_550 , sizeof( * V_547 ) ,
V_147 ) ;
if ( ! V_547 )
return - V_148 ;
V_31 = F_94 ( V_547 , V_209 ,
V_550 * sizeof( V_255 ) ) ;
if ( V_31 )
goto V_54;
V_546 = F_170 ( V_550 , sizeof( * V_546 ) , V_147 ) ;
if ( ! V_546 ) {
V_31 = - V_148 ;
goto V_54;
}
for ( V_549 = 0 ; V_549 < V_550 ;
V_549 ++ ) {
V_518 = F_71 ( V_518 , V_547 [ V_549 ] ,
V_11 -> V_22 ) ;
if ( ! V_518 ) {
V_31 = - V_30 ;
goto V_557;
}
V_546 [ V_549 ] = V_518 ;
}
V_6 = F_38 ( F_3 ( V_299 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) ) {
V_31 = F_13 ( V_6 ) ;
goto V_557;
}
V_347 . V_553 = V_17 . V_553 ;
V_347 . V_288 = V_546 ;
V_300 = V_13 -> V_558 ( V_13 , & V_347 , V_210 ) ;
if ( F_4 ( V_300 ) ) {
V_31 = F_13 ( V_300 ) ;
goto V_524;
}
V_300 -> V_288 = V_546 ;
V_300 -> V_553 = V_347 . V_553 ;
V_300 -> V_128 = V_6 ;
V_6 -> V_131 = V_300 ;
V_300 -> V_36 = V_13 ;
F_39 ( & V_300 -> V_130 , 0 ) ;
for ( V_411 = 0 ; V_411 < V_550 ; V_411 ++ )
F_62 ( & V_546 [ V_411 ] -> V_130 ) ;
V_19 . V_559 = V_6 -> V_133 ;
V_19 . V_554 = V_300 -> V_554 ;
V_19 . V_232 = V_522 ;
V_31 = F_91 ( V_209 ,
& V_19 , V_19 . V_232 ) ;
if ( V_31 )
goto V_134;
F_49 ( V_547 ) ;
for ( V_548 = 0 ; V_548 < V_549 ; V_548 ++ )
F_73 ( V_546 [ V_548 ] ) ;
F_40 ( V_6 ) ;
return 0 ;
V_134:
F_171 ( V_300 ) ;
V_524:
F_42 ( V_6 ) ;
V_557:
for ( V_548 = 0 ; V_548 < V_549 ; V_548 ++ )
F_73 ( V_546 [ V_548 ] ) ;
V_54:
F_49 ( V_547 ) ;
F_49 ( V_546 ) ;
return V_31 ;
}
int F_172 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_172 V_17 = {} ;
struct V_5 * V_6 ;
int V_26 ;
T_3 V_521 ;
V_521 = F_86 ( F_87 ( V_17 ) , V_559 ) + sizeof( V_17 . V_559 ) ;
if ( V_209 -> V_236 < V_521 )
return - V_30 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_137 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_302 ;
V_26 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_237 )
return - V_302 ;
V_6 = F_44 ( F_3 ( V_299 ) , V_17 . V_559 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
return F_45 ( V_6 ) ;
}
int F_173 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_560 V_17 ;
struct V_561 V_19 ;
struct V_5 * V_6 ;
struct V_562 * V_563 ;
struct V_564 * V_565 ;
struct V_566 * V_567 ;
struct V_285 * V_258 ;
int V_31 = 0 ;
void * V_466 ;
void * V_468 ;
int V_411 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
if ( V_209 -> V_239 < sizeof( V_19 ) )
return - V_27 ;
V_31 = F_94 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_31 )
return V_31 ;
V_209 -> V_555 += sizeof( V_17 ) ;
V_209 -> V_236 -= sizeof( V_17 ) ;
if ( V_17 . V_237 )
return - V_30 ;
if ( ! F_105 ( V_292 ) )
return - V_293 ;
if ( V_17 . V_567 . V_190 >= V_568 )
return - V_30 ;
if ( ( V_17 . V_567 . V_190 & V_569 ) &&
( ( V_17 . V_567 . type == V_570 ) ||
( V_17 . V_567 . type == V_571 ) ) )
return - V_30 ;
if ( V_17 . V_567 . V_572 > V_573 )
return - V_30 ;
if ( V_17 . V_567 . V_471 > V_209 -> V_236 ||
V_17 . V_567 . V_471 >
( V_17 . V_567 . V_572 * sizeof( struct V_465 ) ) )
return - V_30 ;
if ( V_17 . V_567 . V_238 [ 0 ] ||
V_17 . V_567 . V_238 [ 1 ] )
return - V_30 ;
if ( V_17 . V_567 . V_572 ) {
V_565 = F_47 ( sizeof( * V_565 ) + V_17 . V_567 . V_471 ,
V_147 ) ;
if ( ! V_565 )
return - V_148 ;
memcpy ( V_565 , & V_17 . V_567 , sizeof( * V_565 ) ) ;
V_31 = F_94 ( V_565 + 1 , V_209 ,
V_17 . V_567 . V_471 ) ;
if ( V_31 )
goto V_574;
} else {
V_565 = & V_17 . V_567 ;
}
V_6 = F_38 ( F_3 ( V_575 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) ) {
V_31 = F_13 ( V_6 ) ;
goto V_574;
}
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 ) {
V_31 = - V_30 ;
goto V_524;
}
V_567 = F_174 ( sizeof( * V_567 ) + V_17 . V_567 . V_572 *
sizeof( union V_467 ) , V_147 ) ;
if ( ! V_567 ) {
V_31 = - V_148 ;
goto V_182;
}
V_567 -> type = V_565 -> type ;
V_567 -> V_576 = V_565 -> V_576 ;
V_567 -> V_572 = V_565 -> V_572 ;
V_567 -> V_577 = V_565 -> V_577 ;
V_567 -> V_190 = V_565 -> V_190 ;
V_567 -> V_471 = sizeof( * V_567 ) ;
V_466 = V_565 + 1 ;
V_468 = V_567 + 1 ;
for ( V_411 = 0 ; V_411 < V_567 -> V_572 &&
V_17 . V_567 . V_471 > F_86 ( struct V_465 , V_238 ) &&
V_17 . V_567 . V_471 >=
( (struct V_465 * ) V_466 ) -> V_471 ; V_411 ++ ) {
V_31 = F_164 ( V_466 , V_468 ) ;
if ( V_31 )
goto V_54;
V_567 -> V_471 +=
( (union V_467 * ) V_468 ) -> V_471 ;
V_17 . V_567 . V_471 -= ( (struct V_465 * ) V_466 ) -> V_471 ;
V_466 += ( (struct V_465 * ) V_466 ) -> V_471 ;
V_468 += ( (union V_467 * ) V_468 ) -> V_471 ;
}
if ( V_17 . V_567 . V_471 || ( V_411 != V_567 -> V_572 ) ) {
F_175 ( L_2 ,
V_411 , V_17 . V_567 . V_471 ) ;
V_31 = - V_30 ;
goto V_54;
}
V_563 = F_176 ( V_258 , V_567 , V_578 ) ;
if ( F_4 ( V_563 ) ) {
V_31 = F_13 ( V_563 ) ;
goto V_54;
}
V_563 -> V_128 = V_6 ;
V_6 -> V_131 = V_563 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_579 = V_6 -> V_133 ;
V_31 = F_91 ( V_209 ,
& V_19 , sizeof( V_19 ) ) ;
if ( V_31 )
goto V_134;
F_73 ( V_258 ) ;
F_40 ( V_6 ) ;
F_49 ( V_567 ) ;
if ( V_17 . V_567 . V_572 )
F_49 ( V_565 ) ;
return 0 ;
V_134:
F_177 ( V_563 ) ;
V_54:
F_49 ( V_567 ) ;
V_182:
F_73 ( V_258 ) ;
V_524:
F_42 ( V_6 ) ;
V_574:
if ( V_17 . V_567 . V_572 )
F_49 ( V_565 ) ;
return V_31 ;
}
int F_178 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_580 V_17 ;
struct V_5 * V_6 ;
int V_26 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
V_26 = F_94 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_237 )
return - V_30 ;
V_6 = F_44 ( F_3 ( V_575 ) , V_17 . V_579 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
return V_26 ;
}
static int F_179 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_581 * V_17 ,
struct V_20 * V_21 )
{
struct V_582 V_19 ;
struct V_583 * V_155 ;
struct V_125 * V_126 ;
struct V_283 * V_284 ;
struct V_5 * V_341 ( V_279 ) ;
struct V_584 V_61 ;
int V_26 ;
V_155 = (struct V_583 * ) F_38 ( F_3 ( V_284 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
if ( V_17 -> V_310 == V_585 ) {
V_279 = F_2 ( F_3 ( V_139 ) , V_17 -> V_169 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_279 ) ) {
V_26 = - V_30 ;
goto V_31;
}
V_61 . V_586 . V_587 . V_139 = (struct V_138 * ) V_279 -> V_131 ;
if ( ! V_61 . V_586 . V_587 . V_139 ) {
V_26 = - V_30 ;
goto V_588;
}
V_155 -> V_294 = F_7 ( V_279 , struct V_154 , V_128 ) ;
F_62 ( & V_155 -> V_294 -> V_168 ) ;
V_61 . V_586 . V_587 . V_215 = F_71 ( V_215 , V_17 -> V_231 ,
V_11 -> V_22 ) ;
if ( ! V_61 . V_586 . V_587 . V_215 ) {
V_26 = - V_30 ;
goto V_588;
}
}
V_126 = F_71 ( V_126 , V_17 -> V_132 , V_11 -> V_22 ) ;
if ( ! V_126 ) {
V_26 = - V_30 ;
goto V_531;
}
V_61 . V_227 = V_589 ;
V_61 . V_590 = V_11 ;
V_61 . V_310 = V_17 -> V_310 ;
V_61 . V_61 . V_526 = V_17 -> V_526 ;
V_61 . V_61 . V_72 = V_17 -> V_72 ;
V_61 . V_61 . V_591 = V_17 -> V_591 ;
V_155 -> V_295 . V_326 = 0 ;
F_20 ( & V_155 -> V_295 . V_327 ) ;
V_284 = V_126 -> V_36 -> V_592 ( V_126 , & V_61 , V_21 ) ;
if ( F_4 ( V_284 ) ) {
V_26 = F_13 ( V_284 ) ;
goto V_182;
}
V_284 -> V_36 = V_126 -> V_36 ;
V_284 -> V_126 = V_126 ;
V_284 -> V_310 = V_17 -> V_310 ;
V_284 -> V_128 = & V_155 -> V_295 . V_128 ;
V_284 -> V_227 = V_61 . V_227 ;
V_284 -> V_590 = V_61 . V_590 ;
if ( V_17 -> V_310 == V_585 ) {
V_284 -> V_586 . V_587 . V_215 = V_61 . V_586 . V_587 . V_215 ;
V_284 -> V_586 . V_587 . V_139 = V_61 . V_586 . V_587 . V_139 ;
F_62 ( & V_61 . V_586 . V_587 . V_215 -> V_130 ) ;
F_62 ( & V_61 . V_586 . V_587 . V_139 -> V_130 ) ;
}
F_62 ( & V_126 -> V_130 ) ;
F_39 ( & V_284 -> V_130 , 0 ) ;
V_155 -> V_295 . V_128 . V_131 = V_284 ;
V_155 -> V_295 . V_128 . V_218 = V_17 -> V_218 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_309 = V_155 -> V_295 . V_128 . V_133 ;
V_19 . V_526 = V_61 . V_61 . V_526 ;
V_19 . V_72 = V_61 . V_61 . V_72 ;
if ( V_17 -> V_310 == V_585 )
V_19 . V_593 = V_284 -> V_586 . V_587 . V_594 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 -> V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_134;
}
if ( V_17 -> V_310 == V_585 ) {
F_6 ( V_279 ) ;
F_73 ( V_61 . V_586 . V_587 . V_215 ) ;
}
F_73 ( V_126 ) ;
F_40 ( & V_155 -> V_295 . V_128 ) ;
return 0 ;
V_134:
F_180 ( V_284 ) ;
V_182:
F_73 ( V_126 ) ;
V_531:
if ( V_17 -> V_310 == V_585 )
F_73 ( V_61 . V_586 . V_587 . V_215 ) ;
V_588:
if ( V_17 -> V_310 == V_585 ) {
F_64 ( & V_155 -> V_294 -> V_168 ) ;
F_6 ( V_279 ) ;
}
V_31:
F_42 ( & V_155 -> V_295 . V_128 ) ;
return V_26 ;
}
T_1 F_181 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_181 V_17 ;
struct V_581 V_595 ;
struct V_582 V_19 ;
struct V_20 V_21 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_595 . V_32 = V_17 . V_32 ;
V_595 . V_218 = V_17 . V_218 ;
V_595 . V_310 = V_311 ;
V_595 . V_132 = V_17 . V_132 ;
V_595 . V_526 = V_17 . V_526 ;
V_595 . V_72 = V_17 . V_72 ;
V_595 . V_591 = V_17 . V_591 ;
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 - sizeof( struct V_201 ) ,
V_16 - sizeof V_19 ) ;
V_26 = F_179 ( V_11 , V_13 , & V_595 , & V_21 ) ;
if ( V_26 )
return V_26 ;
return V_15 ;
}
T_1 V_581 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 , int V_16 )
{
struct V_581 V_17 ;
struct V_582 V_19 ;
struct V_20 V_21 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 - sizeof( struct V_201 ) ,
V_16 - sizeof V_19 ) ;
V_26 = F_179 ( V_11 , V_13 , & V_17 , & V_21 ) ;
if ( V_26 )
return V_26 ;
return V_15 ;
}
T_1 F_182 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_182 V_17 ;
struct V_20 V_21 ;
struct V_283 * V_284 ;
struct V_596 V_61 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 , NULL , V_15 - sizeof V_17 ,
V_16 ) ;
V_284 = F_71 ( V_284 , V_17 . V_309 , V_11 -> V_22 ) ;
if ( ! V_284 )
return - V_30 ;
V_61 . V_526 = V_17 . V_526 ;
V_61 . V_591 = V_17 . V_591 ;
V_26 = V_284 -> V_36 -> V_597 ( V_284 , & V_61 , V_17 . V_350 , & V_21 ) ;
F_73 ( V_284 ) ;
return V_26 ? V_26 : V_15 ;
}
T_1 F_183 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_183 V_17 ;
struct V_598 V_19 ;
struct V_596 V_61 ;
struct V_283 * V_284 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_284 = F_71 ( V_284 , V_17 . V_309 , V_11 -> V_22 ) ;
if ( ! V_284 )
return - V_30 ;
V_26 = F_184 ( V_284 , & V_61 ) ;
F_73 ( V_284 ) ;
if ( V_26 )
return V_26 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_526 = V_61 . V_526 ;
V_19 . V_72 = V_61 . V_72 ;
V_19 . V_591 = V_61 . V_591 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
T_1 F_185 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_185 V_17 ;
struct V_599 V_19 ;
struct V_5 * V_6 ;
struct V_283 * V_284 ;
struct V_600 * V_155 ;
int V_26 = - V_30 ;
enum V_601 V_310 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_284 ) , V_17 . V_309 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_284 = V_6 -> V_131 ;
V_155 = F_7 ( V_6 , struct V_600 , V_128 ) ;
V_310 = V_284 -> V_310 ;
F_5 ( V_6 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_26 = F_45 ( V_6 ) ;
if ( V_26 ) {
F_103 ( V_6 ) ;
return V_26 ;
}
V_19 . V_326 = V_155 -> V_326 ;
F_103 ( V_6 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof( V_19 ) ) )
return - V_28 ;
return V_15 ;
}
int F_186 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_602 V_19 = { { 0 } } ;
struct F_186 V_17 ;
struct V_60 V_61 = { 0 } ;
int V_31 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
V_31 = F_94 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_31 )
return V_31 ;
if ( V_17 . V_237 )
return - V_30 ;
if ( V_17 . V_238 )
return - V_30 ;
V_19 . V_232 = F_86 ( F_87 ( V_19 ) , V_603 ) ;
if ( V_209 -> V_239 < V_19 . V_232 )
return - V_27 ;
V_31 = V_13 -> V_604 ( V_13 , & V_61 , V_210 ) ;
if ( V_31 )
return V_31 ;
F_31 ( V_11 , V_13 , & V_19 . V_230 , & V_61 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_603 ) )
goto V_605;
#ifdef F_18
V_19 . V_603 . V_606 = V_61 . V_603 . V_606 ;
V_19 . V_603 . V_607 . V_608 =
V_61 . V_603 . V_607 . V_608 ;
V_19 . V_603 . V_607 . V_609 =
V_61 . V_603 . V_607 . V_609 ;
V_19 . V_603 . V_607 . V_610 =
V_61 . V_603 . V_607 . V_610 ;
#endif
V_19 . V_232 += sizeof( V_19 . V_603 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_611 ) )
goto V_605;
V_19 . V_611 = V_61 . V_611 ;
V_19 . V_232 += sizeof( V_19 . V_611 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_612 ) )
goto V_605;
V_19 . V_612 = V_61 . V_612 ;
V_19 . V_232 += sizeof( V_19 . V_612 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_613 ) )
goto V_605;
V_19 . V_613 = V_61 . V_49 ;
V_19 . V_232 += sizeof( V_19 . V_613 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_614 ) )
goto V_605;
V_19 . V_614 . V_615 = V_61 . V_614 . V_615 ;
V_19 . V_614 . V_616 =
V_61 . V_614 . V_616 ;
V_19 . V_614 . V_617 =
V_61 . V_614 . V_617 ;
V_19 . V_232 += sizeof( V_19 . V_614 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_618 ) )
goto V_605;
V_19 . V_618 = V_61 . V_618 ;
V_19 . V_232 += sizeof( V_19 . V_618 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_619 ) )
goto V_605;
V_19 . V_619 = V_61 . V_619 ;
V_19 . V_232 += sizeof( V_19 . V_619 ) ;
V_605:
V_31 = F_91 ( V_209 , & V_19 , V_19 . V_232 ) ;
return V_31 ;
}
