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
V_215 -> V_229 = V_206 ? & V_206 -> V_207 : NULL ;
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
struct V_240 V_19 = {} ;
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
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_215 ) , V_17 . V_231 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
F_5 ( V_6 ) ;
V_215 = V_6 -> V_131 ;
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
struct V_275 * V_17 ,
T_3 V_212 ,
int (* F_84)( struct V_10 * V_11 ,
struct V_276 * V_19 ,
struct V_20 * V_21 ) ,
void * V_4 )
{
struct V_277 * V_155 ;
struct V_12 * V_36 ;
struct V_125 * V_126 = NULL ;
struct V_138 * V_139 = NULL ;
struct V_5 * V_278 = F_85 ( - V_279 ) ;
struct V_214 * V_280 = NULL , * V_281 = NULL ;
struct V_282 * V_283 = NULL ;
struct V_284 * V_258 ;
char * V_14 ;
struct V_285 V_61 = {} ;
struct V_276 V_19 ;
int V_26 ;
struct V_286 * V_287 = NULL ;
bool V_288 = true ;
if ( V_17 -> V_289 == V_290 && ! F_105 ( V_291 ) )
return - V_292 ;
V_155 = (struct V_277 * ) F_38 ( F_3 ( V_258 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
V_155 -> V_293 = NULL ;
V_155 -> V_294 . V_128 . V_218 = V_17 -> V_218 ;
F_61 ( & V_155 -> V_295 ) ;
if ( V_212 >= F_86 ( F_87 ( * V_17 ) , V_296 ) +
sizeof( V_17 -> V_296 ) &&
( V_17 -> V_237 & V_297 ) ) {
V_287 = F_71 ( V_298 ,
V_17 -> V_296 ,
V_11 -> V_22 ) ;
if ( ! V_287 ) {
V_26 = - V_30 ;
goto V_182;
}
V_61 . V_299 = V_287 ;
}
if ( ( V_212 >= F_86 ( F_87 ( * V_17 ) , V_300 ) +
sizeof( V_17 -> V_300 ) ) && V_17 -> V_300 ) {
V_26 = - V_301 ;
goto V_182;
}
if ( V_287 && ( V_17 -> V_302 || V_17 -> V_303 || V_17 -> V_304 ) ) {
V_26 = - V_30 ;
goto V_182;
}
if ( V_287 && ! V_17 -> V_305 )
V_288 = false ;
if ( V_17 -> V_289 == V_306 ) {
V_278 = F_2 ( F_3 ( V_139 ) , V_17 -> V_132 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_278 ) ) {
V_26 = - V_30 ;
goto V_182;
}
V_139 = (struct V_138 * ) V_278 -> V_131 ;
if ( ! V_139 ) {
V_26 = - V_30 ;
goto V_182;
}
V_36 = V_139 -> V_36 ;
} else {
if ( V_17 -> V_289 == V_307 ) {
V_17 -> V_302 = 0 ;
V_17 -> V_303 = 0 ;
} else {
if ( V_17 -> V_304 ) {
V_283 = F_71 ( V_283 , V_17 -> V_308 ,
V_11 -> V_22 ) ;
if ( ! V_283 || V_283 -> V_309 != V_310 ) {
V_26 = - V_30 ;
goto V_182;
}
}
if ( ! V_287 ) {
if ( V_17 -> V_311 != V_17 -> V_312 ) {
V_281 = F_71 ( V_215 , V_17 -> V_311 ,
V_11 -> V_22 ) ;
if ( ! V_281 ) {
V_26 = - V_30 ;
goto V_182;
}
}
}
}
if ( V_288 )
V_280 = F_71 ( V_215 , V_17 -> V_312 ,
V_11 -> V_22 ) ;
if ( ! V_287 )
V_281 = V_281 ? : V_280 ;
V_126 = F_71 ( V_126 , V_17 -> V_132 , V_11 -> V_22 ) ;
if ( ! V_126 || ( ! V_280 && V_288 ) ) {
V_26 = - V_30 ;
goto V_182;
}
V_36 = V_126 -> V_36 ;
}
V_61 . V_227 = V_313 ;
V_61 . V_314 = V_11 ;
V_61 . V_315 = V_280 ;
V_61 . V_316 = V_281 ;
V_61 . V_283 = V_283 ;
V_61 . V_139 = V_139 ;
V_61 . V_317 = V_17 -> V_318 ? V_319 :
V_320 ;
V_61 . V_289 = V_17 -> V_289 ;
V_61 . V_321 = 0 ;
V_61 . V_322 . V_305 = V_17 -> V_305 ;
V_61 . V_322 . V_302 = V_17 -> V_302 ;
V_61 . V_322 . V_323 = V_17 -> V_323 ;
V_61 . V_322 . V_303 = V_17 -> V_303 ;
V_61 . V_322 . V_324 = V_17 -> V_324 ;
V_155 -> V_294 . V_325 = 0 ;
F_20 ( & V_155 -> V_294 . V_326 ) ;
F_20 ( & V_155 -> V_327 ) ;
if ( V_212 >= F_86 ( F_87 ( * V_17 ) , V_321 ) +
sizeof( V_17 -> V_321 ) )
V_61 . V_321 = V_17 -> V_321 ;
if ( V_61 . V_321 & ~ ( V_328 |
V_329 |
V_330 |
V_331 |
V_332 |
V_333 ) ) {
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
if ( V_17 -> V_289 == V_306 )
V_258 = F_106 ( V_126 , & V_61 ) ;
else
V_258 = V_36 -> F_104 ( V_126 , & V_61 , V_210 ) ;
if ( F_4 ( V_258 ) ) {
V_26 = F_13 ( V_258 ) ;
goto V_182;
}
if ( V_17 -> V_289 != V_306 ) {
V_26 = F_107 ( V_258 , V_36 ) ;
if ( V_26 )
goto V_233;
V_258 -> V_334 = V_258 ;
V_258 -> V_36 = V_36 ;
V_258 -> V_126 = V_126 ;
V_258 -> V_315 = V_61 . V_315 ;
V_258 -> V_316 = V_61 . V_316 ;
V_258 -> V_283 = V_61 . V_283 ;
V_258 -> V_299 = V_287 ;
V_258 -> V_227 = V_61 . V_227 ;
V_258 -> V_314 = V_61 . V_314 ;
V_258 -> V_289 = V_61 . V_289 ;
F_39 ( & V_258 -> V_130 , 0 ) ;
F_62 ( & V_126 -> V_130 ) ;
V_258 -> V_335 = 0 ;
if ( V_61 . V_315 )
F_62 ( & V_61 . V_315 -> V_130 ) ;
if ( V_61 . V_316 )
F_62 ( & V_61 . V_316 -> V_130 ) ;
if ( V_61 . V_283 )
F_62 ( & V_61 . V_283 -> V_130 ) ;
if ( V_287 )
F_62 ( & V_287 -> V_130 ) ;
}
V_258 -> V_128 = & V_155 -> V_294 . V_128 ;
V_155 -> V_294 . V_128 . V_131 = V_258 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_230 . V_336 = V_258 -> V_257 ;
V_19 . V_230 . V_337 = V_155 -> V_294 . V_128 . V_133 ;
V_19 . V_230 . V_303 = V_61 . V_322 . V_303 ;
V_19 . V_230 . V_323 = V_61 . V_322 . V_323 ;
V_19 . V_230 . V_302 = V_61 . V_322 . V_302 ;
V_19 . V_230 . V_305 = V_61 . V_322 . V_305 ;
V_19 . V_230 . V_324 = V_61 . V_322 . V_324 ;
V_19 . V_232 = F_86 ( F_87 ( V_19 ) , V_232 ) +
sizeof( V_19 . V_232 ) ;
V_26 = F_84 ( V_11 , & V_19 , V_209 ) ;
if ( V_26 )
goto V_233;
if ( V_139 ) {
V_155 -> V_293 = F_7 ( V_278 , struct V_154 ,
V_128 ) ;
F_62 ( & V_155 -> V_293 -> V_168 ) ;
F_6 ( V_278 ) ;
}
if ( V_126 )
F_73 ( V_126 ) ;
if ( V_280 )
F_73 ( V_280 ) ;
if ( V_281 && V_281 != V_280 )
F_73 ( V_281 ) ;
if ( V_283 )
F_73 ( V_283 ) ;
if ( V_287 )
F_73 ( V_287 ) ;
F_40 ( & V_155 -> V_294 . V_128 ) ;
return 0 ;
V_233:
F_108 ( V_258 ) ;
V_182:
if ( ! F_4 ( V_278 ) )
F_6 ( V_278 ) ;
if ( V_126 )
F_73 ( V_126 ) ;
if ( V_280 )
F_73 ( V_280 ) ;
if ( V_281 && V_281 != V_280 )
F_73 ( V_281 ) ;
if ( V_283 )
F_73 ( V_283 ) ;
if ( V_287 )
F_73 ( V_287 ) ;
F_42 ( & V_155 -> V_294 . V_128 ) ;
return V_26 ;
}
static int F_109 ( struct V_10 * V_11 ,
struct V_276 * V_19 ,
struct V_20 * V_209 )
{
if ( F_91 ( V_209 , & V_19 -> V_230 , sizeof( V_19 -> V_230 ) ) )
return - V_28 ;
return 0 ;
}
T_1 F_110 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_110 V_17 ;
struct V_275 V_234 ;
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
V_234 . V_312 = V_17 . V_312 ;
V_234 . V_311 = V_17 . V_311 ;
V_234 . V_308 = V_17 . V_308 ;
V_234 . V_305 = V_17 . V_305 ;
V_234 . V_302 = V_17 . V_302 ;
V_234 . V_323 = V_17 . V_323 ;
V_234 . V_303 = V_17 . V_303 ;
V_234 . V_324 = V_17 . V_324 ;
V_234 . V_318 = V_17 . V_318 ;
V_234 . V_289 = V_17 . V_289 ;
V_234 . V_304 = V_17 . V_304 ;
V_31 = F_104 ( V_11 , & V_209 , & V_210 , & V_234 ,
F_86 ( F_87 ( V_234 ) , V_304 ) +
sizeof( V_17 . V_304 ) , F_109 ,
NULL ) ;
if ( V_31 )
return V_31 ;
return V_15 ;
}
static int F_111 ( struct V_10 * V_11 ,
struct V_276 * V_19 ,
struct V_20 * V_209 )
{
if ( F_91 ( V_209 , V_19 , V_19 -> V_232 ) )
return - V_28 ;
return 0 ;
}
int V_275 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_276 V_19 ;
struct V_275 V_17 = { 0 } ;
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
F_111 , NULL ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
T_1 F_112 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 , int V_16 )
{
struct F_112 V_17 ;
struct V_339 V_19 ;
struct V_20 V_21 ;
struct V_277 * V_155 ;
struct V_138 * V_139 ;
struct V_5 * V_341 ( V_278 ) ;
struct V_284 * V_258 ;
struct V_342 V_61 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 , V_16 - sizeof V_19 ) ;
V_155 = (struct V_277 * ) F_38 ( F_3 ( V_258 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
V_278 = F_2 ( F_3 ( V_139 ) , V_17 . V_132 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_278 ) ) {
V_26 = - V_30 ;
goto V_182;
}
V_139 = (struct V_138 * ) V_278 -> V_131 ;
if ( ! V_139 ) {
V_26 = - V_30 ;
goto V_343;
}
V_61 . V_227 = V_313 ;
V_61 . V_314 = V_11 ;
V_61 . V_257 = V_17 . V_336 ;
V_61 . V_289 = V_17 . V_289 ;
V_155 -> V_294 . V_325 = 0 ;
F_20 ( & V_155 -> V_294 . V_326 ) ;
F_20 ( & V_155 -> V_327 ) ;
V_258 = F_113 ( V_139 , & V_61 ) ;
if ( F_4 ( V_258 ) ) {
V_26 = F_13 ( V_258 ) ;
goto V_343;
}
V_155 -> V_294 . V_128 . V_131 = V_258 ;
V_155 -> V_294 . V_128 . V_218 = V_17 . V_218 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_336 = V_258 -> V_257 ;
V_19 . V_337 = V_155 -> V_294 . V_128 . V_133 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_344;
}
V_155 -> V_293 = F_7 ( V_278 , struct V_154 , V_128 ) ;
F_62 ( & V_155 -> V_293 -> V_168 ) ;
V_258 -> V_128 = & V_155 -> V_294 . V_128 ;
F_6 ( V_278 ) ;
F_40 ( & V_155 -> V_294 . V_128 ) ;
return V_15 ;
V_344:
F_108 ( V_258 ) ;
V_343:
F_6 ( V_278 ) ;
V_182:
F_42 ( & V_155 -> V_294 . V_128 ) ;
return V_26 ;
}
T_1 F_114 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_114 V_17 ;
struct V_345 V_19 ;
struct V_284 * V_258 ;
struct V_346 * V_61 ;
struct V_285 * V_347 ;
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
V_26 = F_115 ( V_258 , V_61 , V_17 . V_350 , V_347 ) ;
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
V_19 . V_243 . V_370 = F_116 ( & V_61 -> V_371 ) ;
V_19 . V_243 . V_263 = F_117 ( & V_61 -> V_371 ) ;
V_19 . V_243 . V_372 = F_118 ( & V_61 -> V_371 ) ;
V_19 . V_243 . V_373 = F_119 ( & V_61 -> V_371 ) ;
V_19 . V_243 . V_374 = ! ! ( F_120 ( & V_61 -> V_371 ) &
V_375 ) ;
if ( V_19 . V_243 . V_374 ) {
V_349 = F_121 ( & V_61 -> V_371 ) ;
memcpy ( V_19 . V_243 . V_376 , V_349 -> V_376 . V_377 , 16 ) ;
V_19 . V_243 . V_378 = V_349 -> V_378 ;
V_19 . V_243 . V_379 = V_349 -> V_379 ;
V_19 . V_243 . V_380 = V_349 -> V_380 ;
V_19 . V_243 . V_381 = V_349 -> V_381 ;
}
V_19 . V_243 . V_103 = F_122 ( & V_61 -> V_371 ) ;
V_19 . V_382 . V_370 = F_116 ( & V_61 -> V_383 ) ;
V_19 . V_382 . V_263 = F_117 ( & V_61 -> V_383 ) ;
V_19 . V_382 . V_372 = F_118 ( & V_61 -> V_383 ) ;
V_19 . V_382 . V_373
= F_119 ( & V_61 -> V_383 ) ;
V_19 . V_382 . V_374
= ! ! ( F_120 ( & V_61 -> V_383 ) &
V_375 ) ;
if ( V_19 . V_382 . V_374 ) {
V_349 = F_121 ( & V_61 -> V_383 ) ;
memcpy ( V_19 . V_382 . V_376 , V_349 -> V_376 . V_377 , 16 ) ;
V_19 . V_382 . V_378 = V_349 -> V_378 ;
V_19 . V_382 . V_379 = V_349 -> V_379 ;
V_19 . V_382 . V_380 = V_349 -> V_380 ;
V_19 . V_382 . V_381 = V_349 -> V_381 ;
}
V_19 . V_382 . V_103 = F_122 ( & V_61 -> V_383 ) ;
V_19 . V_305 = V_347 -> V_322 . V_305 ;
V_19 . V_302 = V_347 -> V_322 . V_302 ;
V_19 . V_323 = V_347 -> V_322 . V_323 ;
V_19 . V_303 = V_347 -> V_322 . V_303 ;
V_19 . V_324 = V_347 -> V_322 . V_324 ;
V_19 . V_318 = V_347 -> V_317 == V_319 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_242:
F_49 ( V_61 ) ;
F_49 ( V_347 ) ;
return V_26 ? V_26 : V_15 ;
}
static int F_123 ( enum V_384 V_289 , int V_385 )
{
switch ( V_289 ) {
case V_307 :
return V_385 & ~ ( V_386 | V_387 ) ;
case V_306 :
return V_385 & ~ ( V_388 | V_389 |
V_390 ) ;
default:
return V_385 ;
}
}
static int F_124 ( struct V_10 * V_11 ,
struct V_391 * V_17 , struct V_20 * V_21 )
{
struct V_346 * V_61 ;
struct V_284 * V_258 ;
int V_26 ;
V_61 = F_47 ( sizeof *V_61 , V_147 ) ;
if ( ! V_61 )
return - V_148 ;
V_258 = F_71 ( V_258 , V_17 -> V_230 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 ) {
V_26 = - V_30 ;
goto V_242;
}
if ( ( V_17 -> V_230 . V_350 & V_392 ) &&
! F_125 ( V_258 -> V_36 , V_17 -> V_230 . V_103 ) ) {
V_26 = - V_30 ;
goto V_393;
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
V_61 -> V_394 = V_17 -> V_230 . V_394 ;
V_61 -> V_362 = V_17 -> V_230 . V_362 ;
V_61 -> V_363 = V_17 -> V_230 . V_363 ;
V_61 -> V_364 = V_17 -> V_230 . V_364 ;
V_61 -> V_103 = V_17 -> V_230 . V_103 ;
V_61 -> V_365 = V_17 -> V_230 . V_365 ;
V_61 -> V_366 = V_17 -> V_230 . V_366 ;
V_61 -> V_367 = V_17 -> V_230 . V_367 ;
V_61 -> V_368 = V_17 -> V_230 . V_368 ;
V_61 -> V_369 = V_17 -> V_230 . V_369 ;
V_61 -> V_395 = V_17 -> V_395 ;
if ( V_17 -> V_230 . V_350 & V_396 )
V_61 -> V_371 . type = F_126 ( V_258 -> V_36 ,
V_17 -> V_230 . V_243 . V_103 ) ;
if ( V_17 -> V_230 . V_243 . V_374 ) {
F_127 ( & V_61 -> V_371 , NULL ,
V_17 -> V_230 . V_243 . V_378 ,
V_17 -> V_230 . V_243 . V_379 ,
V_17 -> V_230 . V_243 . V_380 ,
V_17 -> V_230 . V_243 . V_381 ) ;
F_128 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_376 ) ;
} else {
F_129 ( & V_61 -> V_371 , 0 ) ;
}
F_130 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_370 ) ;
F_131 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_263 ) ;
F_132 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_372 ) ;
F_133 ( & V_61 -> V_371 , V_17 -> V_230 . V_243 . V_373 ) ;
F_134 ( & V_61 -> V_371 ,
V_17 -> V_230 . V_243 . V_103 ) ;
if ( V_17 -> V_230 . V_350 & V_397 )
V_61 -> V_383 . type =
F_126 ( V_258 -> V_36 , V_17 -> V_230 . V_243 . V_103 ) ;
if ( V_17 -> V_230 . V_382 . V_374 ) {
F_127 ( & V_61 -> V_383 , NULL ,
V_17 -> V_230 . V_382 . V_378 ,
V_17 -> V_230 . V_382 . V_379 ,
V_17 -> V_230 . V_382 . V_380 ,
V_17 -> V_230 . V_382 . V_381 ) ;
F_128 ( & V_61 -> V_383 ,
V_17 -> V_230 . V_382 . V_376 ) ;
} else {
F_129 ( & V_61 -> V_383 , 0 ) ;
}
F_130 ( & V_61 -> V_383 , V_17 -> V_230 . V_382 . V_370 ) ;
F_131 ( & V_61 -> V_383 , V_17 -> V_230 . V_382 . V_263 ) ;
F_132 ( & V_61 -> V_383 ,
V_17 -> V_230 . V_382 . V_372 ) ;
F_133 ( & V_61 -> V_383 ,
V_17 -> V_230 . V_382 . V_373 ) ;
F_134 ( & V_61 -> V_383 ,
V_17 -> V_230 . V_382 . V_103 ) ;
V_26 = F_135 ( V_258 , V_61 ,
F_123 ( V_258 -> V_289 ,
V_17 -> V_230 . V_350 ) ,
V_21 ) ;
V_393:
F_73 ( V_258 ) ;
V_242:
F_49 ( V_61 ) ;
return V_26 ;
}
T_1 F_136 ( struct V_10 * V_11 ,
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
~ ( ( V_398 << 1 ) - 1 ) )
return - V_301 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 . V_230 ) , NULL ,
V_15 - sizeof( V_17 . V_230 ) , V_16 ) ;
V_26 = F_124 ( V_11 , & V_17 , & V_21 ) ;
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
F_137 ( V_399 == ( 1 << 31 ) ) ;
if ( V_209 -> V_236 < sizeof( V_17 . V_230 ) )
return - V_30 ;
V_26 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_230 . V_350 &
~ ( ( V_399 << 1 ) - 1 ) )
return - V_301 ;
if ( V_209 -> V_236 > sizeof( V_17 ) ) {
if ( F_138 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_301 ;
}
V_26 = F_124 ( V_11 , & V_17 , V_210 ) ;
return V_26 ;
}
T_1 F_139 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_139 V_17 ;
struct V_400 V_19 ;
struct V_5 * V_6 ;
struct V_277 * V_155 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_6 = F_44 ( F_3 ( V_258 ) , V_17 . V_337 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_155 = F_7 ( V_6 , struct V_277 , V_294 . V_128 ) ;
F_5 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
if ( V_26 ) {
F_103 ( V_6 ) ;
return V_26 ;
}
V_19 . V_325 = V_155 -> V_294 . V_325 ;
F_103 ( V_6 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
static void * F_140 ( T_3 V_401 , V_255 V_402 )
{
if ( V_402 >= ( V_403 - F_141 ( V_401 , sizeof ( struct V_404 ) ) ) /
sizeof ( struct V_404 ) )
return NULL ;
return F_47 ( F_141 ( V_401 , sizeof ( struct V_404 ) ) +
V_402 * sizeof ( struct V_404 ) , V_147 ) ;
}
T_1 F_142 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_142 V_17 ;
struct V_405 V_19 ;
struct V_406 * V_407 ;
struct V_408 * V_409 = NULL , * V_410 , * V_411 , * V_412 ;
struct V_284 * V_258 ;
int V_413 , V_414 ;
int V_415 ;
T_1 V_26 = - V_30 ;
T_3 V_416 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
if ( V_15 < sizeof V_17 + V_17 . V_417 * V_17 . V_418 +
V_17 . V_419 * sizeof ( struct V_420 ) )
return - V_30 ;
if ( V_17 . V_417 < sizeof ( struct V_406 ) )
return - V_30 ;
V_407 = F_47 ( V_17 . V_417 , V_147 ) ;
if ( ! V_407 )
return - V_148 ;
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 )
goto V_242;
V_415 = V_258 -> V_289 == V_421 ;
V_414 = 0 ;
V_410 = NULL ;
for ( V_413 = 0 ; V_413 < V_17 . V_418 ; ++ V_413 ) {
if ( F_9 ( V_407 ,
V_14 + sizeof V_17 + V_413 * V_17 . V_417 ,
V_17 . V_417 ) ) {
V_26 = - V_28 ;
goto V_270;
}
if ( V_407 -> V_402 + V_414 > V_17 . V_419 ) {
V_26 = - V_30 ;
goto V_270;
}
if ( V_415 ) {
struct V_422 * V_423 ;
if ( V_407 -> V_250 != V_424 &&
V_407 -> V_250 != V_425 ) {
V_26 = - V_30 ;
goto V_270;
}
V_416 = sizeof( * V_423 ) ;
V_423 = F_140 ( V_416 , V_407 -> V_402 ) ;
if ( ! V_423 ) {
V_26 = - V_148 ;
goto V_270;
}
V_423 -> V_426 = F_71 ( V_426 , V_407 -> V_409 . V_423 . V_426 ,
V_11 -> V_22 ) ;
if ( ! V_423 -> V_426 ) {
F_49 ( V_423 ) ;
V_26 = - V_30 ;
goto V_270;
}
V_423 -> V_427 = V_407 -> V_409 . V_423 . V_427 ;
V_423 -> V_428 = V_407 -> V_409 . V_423 . V_428 ;
V_411 = & V_423 -> V_409 ;
} else if ( V_407 -> V_250 == V_429 ||
V_407 -> V_250 == V_430 ||
V_407 -> V_250 == V_431 ) {
struct V_432 * V_433 ;
V_416 = sizeof( * V_433 ) ;
V_433 = F_140 ( V_416 , V_407 -> V_402 ) ;
if ( ! V_433 ) {
V_26 = - V_148 ;
goto V_270;
}
V_433 -> V_434 = V_407 -> V_409 . V_433 . V_434 ;
V_433 -> V_186 = V_407 -> V_409 . V_433 . V_186 ;
V_411 = & V_433 -> V_409 ;
} else if ( V_407 -> V_250 == V_435 ||
V_407 -> V_250 == V_436 ) {
struct V_437 * V_438 ;
V_416 = sizeof( * V_438 ) ;
V_438 = F_140 ( V_416 , V_407 -> V_402 ) ;
if ( ! V_438 ) {
V_26 = - V_148 ;
goto V_270;
}
V_438 -> V_434 = V_407 -> V_409 . V_438 . V_434 ;
V_438 -> V_439 = V_407 -> V_409 . V_438 . V_439 ;
V_438 -> V_440 = V_407 -> V_409 . V_438 . V_440 ;
V_438 -> V_186 = V_407 -> V_409 . V_438 . V_186 ;
V_411 = & V_438 -> V_409 ;
} else if ( V_407 -> V_250 == V_424 ||
V_407 -> V_250 == V_425 ||
V_407 -> V_250 == V_441 ) {
V_416 = sizeof( * V_411 ) ;
V_411 = F_140 ( V_416 , V_407 -> V_402 ) ;
if ( ! V_411 ) {
V_26 = - V_148 ;
goto V_270;
}
} else {
V_26 = - V_30 ;
goto V_270;
}
if ( V_407 -> V_250 == V_425 ||
V_407 -> V_250 == V_429 ) {
V_411 -> V_253 . V_254 =
( V_442 V_256 ) V_407 -> V_253 . V_254 ;
} else if ( V_407 -> V_250 == V_441 ) {
V_411 -> V_253 . V_443 = V_407 -> V_253 . V_443 ;
}
if ( ! V_410 )
V_409 = V_411 ;
else
V_410 -> V_411 = V_411 ;
V_410 = V_411 ;
V_411 -> V_411 = NULL ;
V_411 -> V_248 = V_407 -> V_248 ;
V_411 -> V_402 = V_407 -> V_402 ;
V_411 -> V_250 = V_407 -> V_250 ;
V_411 -> V_444 = V_407 -> V_444 ;
if ( V_411 -> V_402 ) {
V_411 -> V_445 = ( void * ) V_411 +
F_141 ( V_416 , sizeof( struct V_404 ) ) ;
if ( F_9 ( V_411 -> V_445 ,
V_14 + sizeof V_17 +
V_17 . V_418 * V_17 . V_417 +
V_414 * sizeof ( struct V_404 ) ,
V_411 -> V_402 * sizeof ( struct V_404 ) ) ) {
V_26 = - V_28 ;
goto V_270;
}
V_414 += V_411 -> V_402 ;
} else
V_411 -> V_445 = NULL ;
}
V_19 . V_412 = 0 ;
V_26 = V_258 -> V_36 -> V_446 ( V_258 -> V_334 , V_409 , & V_412 ) ;
if ( V_26 )
for ( V_411 = V_409 ; V_411 ; V_411 = V_411 -> V_411 ) {
++ V_19 . V_412 ;
if ( V_411 == V_412 )
break;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_270:
F_73 ( V_258 ) ;
while ( V_409 ) {
if ( V_415 && F_143 ( V_409 ) -> V_426 )
F_73 ( F_143 ( V_409 ) -> V_426 ) ;
V_411 = V_409 -> V_411 ;
F_49 ( V_409 ) ;
V_409 = V_411 ;
}
V_242:
F_49 ( V_407 ) ;
return V_26 ? V_26 : V_15 ;
}
static struct V_447 * F_144 ( const char T_2 * V_14 ,
int V_15 ,
T_5 V_418 ,
T_5 V_419 ,
T_5 V_417 )
{
struct V_448 * V_407 ;
struct V_447 * V_409 = NULL , * V_410 , * V_411 ;
int V_414 ;
int V_413 ;
int V_26 ;
if ( V_15 < V_417 * V_418 +
V_419 * sizeof ( struct V_420 ) )
return F_85 ( - V_30 ) ;
if ( V_417 < sizeof ( struct V_448 ) )
return F_85 ( - V_30 ) ;
V_407 = F_47 ( V_417 , V_147 ) ;
if ( ! V_407 )
return F_85 ( - V_148 ) ;
V_414 = 0 ;
V_410 = NULL ;
for ( V_413 = 0 ; V_413 < V_418 ; ++ V_413 ) {
if ( F_9 ( V_407 , V_14 + V_413 * V_417 ,
V_417 ) ) {
V_26 = - V_28 ;
goto V_31;
}
if ( V_407 -> V_402 + V_414 > V_419 ) {
V_26 = - V_30 ;
goto V_31;
}
if ( V_407 -> V_402 >=
( V_403 - F_141 ( sizeof *V_411 , sizeof ( struct V_404 ) ) ) /
sizeof ( struct V_404 ) ) {
V_26 = - V_30 ;
goto V_31;
}
V_411 = F_47 ( F_141 ( sizeof *V_411 , sizeof ( struct V_404 ) ) +
V_407 -> V_402 * sizeof ( struct V_404 ) ,
V_147 ) ;
if ( ! V_411 ) {
V_26 = - V_148 ;
goto V_31;
}
if ( ! V_410 )
V_409 = V_411 ;
else
V_410 -> V_411 = V_411 ;
V_410 = V_411 ;
V_411 -> V_411 = NULL ;
V_411 -> V_248 = V_407 -> V_248 ;
V_411 -> V_402 = V_407 -> V_402 ;
if ( V_411 -> V_402 ) {
V_411 -> V_445 = ( void * ) V_411 +
F_141 ( sizeof *V_411 , sizeof ( struct V_404 ) ) ;
if ( F_9 ( V_411 -> V_445 ,
V_14 + V_418 * V_417 +
V_414 * sizeof ( struct V_404 ) ,
V_411 -> V_402 * sizeof ( struct V_404 ) ) ) {
V_26 = - V_28 ;
goto V_31;
}
V_414 += V_411 -> V_402 ;
} else
V_411 -> V_445 = NULL ;
}
F_49 ( V_407 ) ;
return V_409 ;
V_31:
F_49 ( V_407 ) ;
while ( V_409 ) {
V_411 = V_409 -> V_411 ;
F_49 ( V_409 ) ;
V_409 = V_411 ;
}
return F_85 ( V_26 ) ;
}
T_1 F_145 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_145 V_17 ;
struct V_449 V_19 ;
struct V_447 * V_409 , * V_411 , * V_412 ;
struct V_284 * V_258 ;
T_1 V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_409 = F_144 ( V_14 + sizeof V_17 ,
V_15 - sizeof V_17 , V_17 . V_418 ,
V_17 . V_419 , V_17 . V_417 ) ;
if ( F_4 ( V_409 ) )
return F_13 ( V_409 ) ;
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 )
goto V_242;
V_19 . V_412 = 0 ;
V_26 = V_258 -> V_36 -> V_450 ( V_258 -> V_334 , V_409 , & V_412 ) ;
F_73 ( V_258 ) ;
if ( V_26 ) {
for ( V_411 = V_409 ; V_411 ; V_411 = V_411 -> V_411 ) {
++ V_19 . V_412 ;
if ( V_411 == V_412 )
break;
}
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_242:
while ( V_409 ) {
V_411 = V_409 -> V_411 ;
F_49 ( V_409 ) ;
V_409 = V_411 ;
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
struct V_447 * V_409 , * V_411 , * V_412 ;
struct V_282 * V_283 ;
T_1 V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_409 = F_144 ( V_14 + sizeof V_17 ,
V_15 - sizeof V_17 , V_17 . V_418 ,
V_17 . V_419 , V_17 . V_417 ) ;
if ( F_4 ( V_409 ) )
return F_13 ( V_409 ) ;
V_283 = F_71 ( V_283 , V_17 . V_308 , V_11 -> V_22 ) ;
if ( ! V_283 )
goto V_242;
V_19 . V_412 = 0 ;
V_26 = V_283 -> V_36 -> V_452 ( V_283 , V_409 , & V_412 ) ;
F_73 ( V_283 ) ;
if ( V_26 )
for ( V_411 = V_409 ; V_411 ; V_411 = V_411 -> V_411 ) {
++ V_19 . V_412 ;
if ( V_411 == V_412 )
break;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_242:
while ( V_409 ) {
V_411 = V_409 -> V_411 ;
F_49 ( V_409 ) ;
V_409 = V_411 ;
}
return V_26 ? V_26 : V_15 ;
}
T_1 F_147 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_147 V_17 ;
struct V_453 V_19 ;
struct V_5 * V_6 ;
struct V_125 * V_126 ;
struct V_454 * V_426 ;
struct V_455 V_61 ;
int V_26 ;
struct V_20 V_21 ;
T_4 * V_456 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
if ( ! F_125 ( V_13 , V_17 . V_61 . V_103 ) )
return - V_30 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) , V_16 - sizeof( V_19 ) ) ;
V_6 = F_38 ( F_3 ( V_426 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_126 = F_71 ( V_126 , V_17 . V_132 , V_11 -> V_22 ) ;
if ( ! V_126 ) {
V_26 = - V_30 ;
goto V_31;
}
V_61 . type = F_126 ( V_13 , V_17 . V_61 . V_103 ) ;
F_130 ( & V_61 , V_17 . V_61 . V_370 ) ;
F_131 ( & V_61 , V_17 . V_61 . V_263 ) ;
F_132 ( & V_61 , V_17 . V_61 . V_372 ) ;
F_133 ( & V_61 , V_17 . V_61 . V_373 ) ;
F_134 ( & V_61 , V_17 . V_61 . V_103 ) ;
if ( V_17 . V_61 . V_374 ) {
F_127 ( & V_61 , NULL , V_17 . V_61 . V_349 . V_378 ,
V_17 . V_61 . V_349 . V_379 ,
V_17 . V_61 . V_349 . V_380 ,
V_17 . V_61 . V_349 . V_381 ) ;
F_128 ( & V_61 , V_17 . V_61 . V_349 . V_376 ) ;
} else {
F_129 ( & V_61 , 0 ) ;
}
V_456 = F_148 ( & V_61 ) ;
if ( V_456 )
memset ( V_456 , 0 , V_457 ) ;
V_426 = V_126 -> V_36 -> V_458 ( V_126 , & V_61 , & V_21 ) ;
if ( F_4 ( V_426 ) ) {
V_26 = F_13 ( V_426 ) ;
goto V_182;
}
V_426 -> V_36 = V_126 -> V_36 ;
V_426 -> V_126 = V_126 ;
F_62 ( & V_126 -> V_130 ) ;
V_426 -> V_128 = V_6 ;
V_6 -> V_218 = V_17 . V_218 ;
V_6 -> V_131 = V_426 ;
V_19 . V_459 = V_6 -> V_133 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_134;
}
F_73 ( V_126 ) ;
F_40 ( V_6 ) ;
return V_15 ;
V_134:
F_149 ( V_426 ) ;
V_182:
F_73 ( V_126 ) ;
V_31:
F_42 ( V_6 ) ;
return V_26 ;
}
T_1 F_150 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 , int V_16 )
{
struct F_150 V_17 ;
struct V_5 * V_6 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_426 ) , V_17 . V_459 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
return V_26 ? : V_15 ;
}
T_1 F_151 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_151 V_17 ;
struct V_284 * V_258 ;
struct V_277 * V_155 ;
struct V_460 * V_461 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 )
return - V_30 ;
V_155 = F_7 ( V_258 -> V_128 , struct V_277 , V_294 . V_128 ) ;
F_10 ( & V_155 -> V_295 ) ;
F_152 (mcast, &obj->mcast_list, list)
if ( V_17 . V_462 == V_461 -> V_113 &&
! memcmp ( V_17 . V_463 , V_461 -> V_463 . V_377 , sizeof V_461 -> V_463 . V_377 ) ) {
V_26 = 0 ;
goto V_270;
}
V_461 = F_47 ( sizeof *V_461 , V_147 ) ;
if ( ! V_461 ) {
V_26 = - V_148 ;
goto V_270;
}
V_461 -> V_113 = V_17 . V_462 ;
memcpy ( V_461 -> V_463 . V_377 , V_17 . V_463 , sizeof V_461 -> V_463 . V_377 ) ;
V_26 = F_153 ( V_258 , & V_461 -> V_463 , V_17 . V_462 ) ;
if ( ! V_26 )
F_154 ( & V_461 -> V_464 , & V_155 -> V_327 ) ;
else
F_49 ( V_461 ) ;
V_270:
F_25 ( & V_155 -> V_295 ) ;
F_73 ( V_258 ) ;
return V_26 ? V_26 : V_15 ;
}
T_1 F_155 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_155 V_17 ;
struct V_277 * V_155 ;
struct V_284 * V_258 ;
struct V_460 * V_461 ;
int V_26 = - V_30 ;
bool V_465 = false ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 )
return - V_30 ;
V_155 = F_7 ( V_258 -> V_128 , struct V_277 , V_294 . V_128 ) ;
F_10 ( & V_155 -> V_295 ) ;
F_152 (mcast, &obj->mcast_list, list)
if ( V_17 . V_462 == V_461 -> V_113 &&
! memcmp ( V_17 . V_463 , V_461 -> V_463 . V_377 , sizeof V_461 -> V_463 . V_377 ) ) {
F_156 ( & V_461 -> V_464 ) ;
F_49 ( V_461 ) ;
V_465 = true ;
break;
}
if ( ! V_465 ) {
V_26 = - V_30 ;
goto V_270;
}
V_26 = F_157 ( V_258 , (union V_466 * ) V_17 . V_463 , V_17 . V_462 ) ;
V_270:
F_25 ( & V_155 -> V_295 ) ;
F_73 ( V_258 ) ;
return V_26 ? V_26 : V_15 ;
}
static int F_158 ( struct V_467 * V_468 ,
union V_469 * V_470 )
{
V_470 -> type = V_468 -> type ;
switch ( V_470 -> type ) {
case V_471 :
if ( V_468 -> V_472 . V_473 !=
sizeof( struct V_474 ) )
return - V_30 ;
V_470 -> V_472 . V_473 = sizeof( struct V_475 ) ;
V_470 -> V_472 . V_476 = V_468 -> V_472 . V_476 ;
break;
case V_477 :
if ( V_468 -> V_478 . V_473 !=
sizeof( struct V_479 ) )
return - V_30 ;
V_470 -> V_478 . V_473 = sizeof( struct V_480 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static T_3 F_159 ( struct V_481 * V_482 )
{
return ( V_482 -> V_473 - sizeof( struct V_481 ) ) / 2 ;
}
static T_1 F_160 ( void * V_483 , T_6 V_484 ,
T_6 V_485 )
{
if ( V_484 > V_485 ) {
if ( F_161 ( V_483 +
V_485 , 0 ,
V_484 - V_485 ) )
return - V_30 ;
return V_485 ;
}
return V_484 ;
}
static int F_162 ( struct V_467 * V_468 ,
union V_469 * V_470 )
{
T_1 V_486 ;
T_1 V_487 ;
T_1 V_488 ;
void * V_489 ;
void * V_490 ;
if ( V_468 -> V_238 )
return - V_30 ;
V_470 -> type = V_468 -> type ;
V_487 = F_159 ( & V_468 -> V_491 ) ;
if ( V_487 != F_141 ( V_487 , 4 ) )
return - V_30 ;
V_490 = ( void * ) V_468 +
sizeof( struct V_481 ) ;
V_489 = V_490 + V_487 ;
if ( V_470 -> type == ( V_492 | V_493 ) )
return - V_30 ;
switch ( V_470 -> type & ~ V_492 ) {
case V_494 :
V_488 = F_86 ( struct V_495 , V_496 ) ;
V_486 = F_160 ( V_489 ,
V_487 ,
V_488 ) ;
if ( V_486 <= 0 )
return - V_30 ;
V_470 -> V_473 = sizeof( struct V_497 ) ;
memcpy ( & V_470 -> V_498 . V_499 , V_490 , V_486 ) ;
memcpy ( & V_470 -> V_498 . V_385 , V_489 , V_486 ) ;
break;
case V_500 :
V_488 = F_86 ( struct V_501 , V_496 ) ;
V_486 = F_160 ( V_489 ,
V_487 ,
V_488 ) ;
if ( V_486 <= 0 )
return - V_30 ;
V_470 -> V_473 = sizeof( struct V_502 ) ;
memcpy ( & V_470 -> V_503 . V_499 , V_490 , V_486 ) ;
memcpy ( & V_470 -> V_503 . V_385 , V_489 , V_486 ) ;
break;
case V_504 :
V_488 = F_86 ( struct V_505 , V_496 ) ;
V_486 = F_160 ( V_489 ,
V_487 ,
V_488 ) ;
if ( V_486 <= 0 )
return - V_30 ;
V_470 -> V_473 = sizeof( struct V_506 ) ;
memcpy ( & V_470 -> V_507 . V_499 , V_490 , V_486 ) ;
memcpy ( & V_470 -> V_507 . V_385 , V_489 , V_486 ) ;
if ( ( F_163 ( V_470 -> V_507 . V_385 . V_378 ) ) >= F_164 ( 20 ) ||
( F_163 ( V_470 -> V_507 . V_499 . V_378 ) ) >= F_164 ( 20 ) )
return - V_30 ;
break;
case V_508 :
case V_509 :
V_488 = F_86 ( struct V_510 , V_496 ) ;
V_486 = F_160 ( V_489 ,
V_487 ,
V_488 ) ;
if ( V_486 <= 0 )
return - V_30 ;
V_470 -> V_473 = sizeof( struct V_511 ) ;
memcpy ( & V_470 -> V_512 . V_499 , V_490 , V_486 ) ;
memcpy ( & V_470 -> V_512 . V_385 , V_489 , V_486 ) ;
break;
case V_493 :
V_488 = F_86 ( struct V_513 , V_496 ) ;
V_486 = F_160 ( V_489 ,
V_487 ,
V_488 ) ;
if ( V_486 <= 0 )
return - V_30 ;
V_470 -> V_514 . V_473 = sizeof( struct V_515 ) ;
memcpy ( & V_470 -> V_514 . V_499 , V_490 , V_486 ) ;
memcpy ( & V_470 -> V_514 . V_385 , V_489 , V_486 ) ;
if ( ( F_163 ( V_470 -> V_514 . V_385 . V_516 ) ) >= F_164 ( 24 ) ||
( F_163 ( V_470 -> V_514 . V_499 . V_516 ) ) >= F_164 ( 24 ) )
return - V_30 ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_165 ( struct V_467 * V_468 ,
union V_469 * V_470 )
{
if ( V_468 -> V_238 )
return - V_30 ;
if ( V_468 -> type >= V_471 )
return F_158 ( V_468 , V_470 ) ;
else
return F_162 ( V_468 , V_470 ) ;
}
int F_166 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_166 V_17 = {} ;
struct V_517 V_19 = {} ;
struct V_518 * V_155 ;
int V_31 = 0 ;
struct V_214 * V_215 ;
struct V_125 * V_126 ;
struct V_519 * V_520 ;
struct V_521 V_522 = {} ;
T_3 V_523 ;
T_3 V_524 ;
V_523 = F_86 ( F_87 ( V_17 ) , V_72 ) + sizeof( V_17 . V_72 ) ;
V_524 = F_86 ( F_87 ( V_19 ) , V_525 ) + sizeof( V_19 . V_525 ) ;
if ( V_209 -> V_236 < V_523 )
return - V_30 ;
if ( V_209 -> V_239 < V_524 )
return - V_27 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_138 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_301 ;
V_31 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_31 )
return V_31 ;
if ( V_17 . V_237 )
return - V_301 ;
V_155 = (struct V_518 * ) F_38 ( F_3 ( V_520 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
V_126 = F_71 ( V_126 , V_17 . V_132 , V_11 -> V_22 ) ;
if ( ! V_126 ) {
V_31 = - V_30 ;
goto V_526;
}
V_215 = F_71 ( V_215 , V_17 . V_231 , V_11 -> V_22 ) ;
if ( ! V_215 ) {
V_31 = - V_30 ;
goto V_527;
}
V_522 . V_215 = V_215 ;
V_522 . V_72 = V_17 . V_72 ;
V_522 . V_528 = V_17 . V_528 ;
V_522 . V_529 = V_11 ;
V_522 . V_530 = V_17 . V_530 ;
V_522 . V_227 = V_531 ;
if ( V_209 -> V_236 >= ( F_86 ( F_87 ( V_17 ) , V_321 ) +
sizeof( V_17 . V_321 ) ) )
V_522 . V_321 = V_17 . V_321 ;
V_155 -> V_294 . V_325 = 0 ;
F_20 ( & V_155 -> V_294 . V_326 ) ;
V_520 = V_126 -> V_36 -> V_532 ( V_126 , & V_522 , V_210 ) ;
if ( F_4 ( V_520 ) ) {
V_31 = F_13 ( V_520 ) ;
goto V_533;
}
V_520 -> V_128 = & V_155 -> V_294 . V_128 ;
V_155 -> V_294 . V_128 . V_131 = V_520 ;
V_520 -> V_530 = V_522 . V_530 ;
V_520 -> V_215 = V_215 ;
V_520 -> V_126 = V_126 ;
V_520 -> V_36 = V_126 -> V_36 ;
V_520 -> V_529 = V_522 . V_529 ;
F_39 ( & V_520 -> V_130 , 0 ) ;
F_62 ( & V_126 -> V_130 ) ;
F_62 ( & V_215 -> V_130 ) ;
V_520 -> V_128 = & V_155 -> V_294 . V_128 ;
V_155 -> V_294 . V_128 . V_131 = V_520 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_534 = V_155 -> V_294 . V_128 . V_133 ;
V_19 . V_72 = V_522 . V_72 ;
V_19 . V_528 = V_522 . V_528 ;
V_19 . V_525 = V_520 -> V_535 ;
V_19 . V_232 = V_524 ;
V_31 = F_91 ( V_209 ,
& V_19 , V_19 . V_232 ) ;
if ( V_31 )
goto V_134;
F_73 ( V_126 ) ;
F_73 ( V_215 ) ;
F_40 ( & V_155 -> V_294 . V_128 ) ;
return 0 ;
V_134:
F_167 ( V_520 ) ;
V_533:
F_73 ( V_215 ) ;
V_527:
F_73 ( V_126 ) ;
V_526:
F_42 ( & V_155 -> V_294 . V_128 ) ;
return V_31 ;
}
int F_168 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_168 V_17 = {} ;
struct V_536 V_19 = {} ;
struct V_5 * V_6 ;
struct V_518 * V_155 ;
T_3 V_523 ;
T_3 V_524 ;
int V_26 ;
V_523 = F_86 ( F_87 ( V_17 ) , V_534 ) + sizeof( V_17 . V_534 ) ;
V_524 = F_86 ( F_87 ( V_19 ) , V_238 ) + sizeof( V_19 . V_238 ) ;
if ( V_209 -> V_236 < V_523 )
return - V_30 ;
if ( V_209 -> V_239 < V_524 )
return - V_27 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_138 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_301 ;
V_26 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_237 )
return - V_301 ;
V_19 . V_232 = V_524 ;
V_6 = F_44 ( F_3 ( V_520 ) , V_17 . V_534 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_155 = F_7 ( V_6 , struct V_518 , V_294 . V_128 ) ;
F_5 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
V_19 . V_325 = V_155 -> V_294 . V_325 ;
F_103 ( V_6 ) ;
if ( V_26 )
return V_26 ;
return F_91 ( V_209 , & V_19 , V_19 . V_232 ) ;
}
int F_169 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_169 V_17 = {} ;
struct V_519 * V_520 ;
struct V_537 V_538 = {} ;
T_3 V_523 ;
int V_26 ;
V_523 = F_86 ( F_87 ( V_17 ) , V_539 ) + sizeof( V_17 . V_539 ) ;
if ( V_209 -> V_236 < V_523 )
return - V_30 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_138 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_301 ;
V_26 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( ! V_17 . V_350 )
return - V_30 ;
if ( V_17 . V_350 > ( V_540 | V_541 | V_542 ) )
return - V_30 ;
V_520 = F_71 ( V_520 , V_17 . V_534 , V_11 -> V_22 ) ;
if ( ! V_520 )
return - V_30 ;
V_538 . V_539 = V_17 . V_539 ;
V_538 . V_543 = V_17 . V_543 ;
if ( V_17 . V_350 & V_542 ) {
V_538 . V_190 = V_17 . V_190 ;
V_538 . V_544 = V_17 . V_544 ;
}
V_26 = V_520 -> V_36 -> V_545 ( V_520 , & V_538 , V_17 . V_350 , V_210 ) ;
F_73 ( V_520 ) ;
return V_26 ;
}
int F_170 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_170 V_17 = {} ;
struct V_546 V_19 = {} ;
struct V_5 * V_6 ;
int V_31 = 0 ;
struct V_547 V_347 = {} ;
struct V_286 * V_299 ;
struct V_519 * * V_548 = NULL ;
T_5 * V_549 = NULL ;
struct V_519 * V_520 = NULL ;
int V_413 , V_550 , V_551 ;
T_5 V_552 ;
T_5 V_553 ;
T_3 V_554 ;
T_3 V_524 ;
V_554 = F_86 ( F_87 ( V_17 ) , V_555 ) + sizeof( V_17 . V_555 ) ;
V_524 = F_86 ( F_87 ( V_19 ) , V_556 ) + sizeof( V_19 . V_556 ) ;
if ( V_209 -> V_236 < V_554 )
return - V_30 ;
if ( V_209 -> V_239 < V_524 )
return - V_27 ;
V_31 = F_94 ( & V_17 , V_209 , V_554 ) ;
if ( V_31 )
return V_31 ;
V_209 -> V_557 += V_554 ;
V_209 -> V_236 -= V_554 ;
if ( V_17 . V_237 )
return - V_301 ;
if ( V_17 . V_555 > V_558 )
return - V_30 ;
V_552 = 1 << V_17 . V_555 ;
V_553 = V_552 * sizeof( V_255 ) ;
if ( V_552 == 1 )
V_553 += sizeof( V_255 ) ;
if ( V_209 -> V_236 < V_553 )
return - V_30 ;
if ( V_209 -> V_236 > V_553 &&
! F_138 ( V_209 , V_553 ,
V_209 -> V_236 - V_553 ) )
return - V_301 ;
V_549 = F_171 ( V_552 , sizeof( * V_549 ) ,
V_147 ) ;
if ( ! V_549 )
return - V_148 ;
V_31 = F_94 ( V_549 , V_209 ,
V_552 * sizeof( V_255 ) ) ;
if ( V_31 )
goto V_54;
V_548 = F_171 ( V_552 , sizeof( * V_548 ) , V_147 ) ;
if ( ! V_548 ) {
V_31 = - V_148 ;
goto V_54;
}
for ( V_551 = 0 ; V_551 < V_552 ;
V_551 ++ ) {
V_520 = F_71 ( V_520 , V_549 [ V_551 ] ,
V_11 -> V_22 ) ;
if ( ! V_520 ) {
V_31 = - V_30 ;
goto V_559;
}
V_548 [ V_551 ] = V_520 ;
}
V_6 = F_38 ( F_3 ( V_298 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) ) {
V_31 = F_13 ( V_6 ) ;
goto V_559;
}
V_347 . V_555 = V_17 . V_555 ;
V_347 . V_287 = V_548 ;
V_299 = V_13 -> V_560 ( V_13 , & V_347 , V_210 ) ;
if ( F_4 ( V_299 ) ) {
V_31 = F_13 ( V_299 ) ;
goto V_526;
}
V_299 -> V_287 = V_548 ;
V_299 -> V_555 = V_347 . V_555 ;
V_299 -> V_128 = V_6 ;
V_6 -> V_131 = V_299 ;
V_299 -> V_36 = V_13 ;
F_39 ( & V_299 -> V_130 , 0 ) ;
for ( V_413 = 0 ; V_413 < V_552 ; V_413 ++ )
F_62 ( & V_548 [ V_413 ] -> V_130 ) ;
V_19 . V_561 = V_6 -> V_133 ;
V_19 . V_556 = V_299 -> V_556 ;
V_19 . V_232 = V_524 ;
V_31 = F_91 ( V_209 ,
& V_19 , V_19 . V_232 ) ;
if ( V_31 )
goto V_134;
F_49 ( V_549 ) ;
for ( V_550 = 0 ; V_550 < V_551 ; V_550 ++ )
F_73 ( V_548 [ V_550 ] ) ;
F_40 ( V_6 ) ;
return 0 ;
V_134:
F_172 ( V_299 ) ;
V_526:
F_42 ( V_6 ) ;
V_559:
for ( V_550 = 0 ; V_550 < V_551 ; V_550 ++ )
F_73 ( V_548 [ V_550 ] ) ;
V_54:
F_49 ( V_549 ) ;
F_49 ( V_548 ) ;
return V_31 ;
}
int F_173 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_173 V_17 = {} ;
struct V_5 * V_6 ;
int V_26 ;
T_3 V_523 ;
V_523 = F_86 ( F_87 ( V_17 ) , V_561 ) + sizeof( V_17 . V_561 ) ;
if ( V_209 -> V_236 < V_523 )
return - V_30 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_138 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_301 ;
V_26 = F_94 ( & V_17 , V_209 , F_95 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_237 )
return - V_301 ;
V_6 = F_44 ( F_3 ( V_298 ) , V_17 . V_561 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
return F_45 ( V_6 ) ;
}
int F_174 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_562 V_17 ;
struct V_563 V_19 ;
struct V_5 * V_6 ;
struct V_564 * V_565 ;
struct V_566 * V_567 ;
struct V_568 * V_569 ;
struct V_284 * V_258 ;
int V_31 = 0 ;
void * V_468 ;
void * V_470 ;
int V_413 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
if ( V_209 -> V_239 < sizeof( V_19 ) )
return - V_27 ;
V_31 = F_94 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_31 )
return V_31 ;
V_209 -> V_557 += sizeof( V_17 ) ;
V_209 -> V_236 -= sizeof( V_17 ) ;
if ( V_17 . V_237 )
return - V_30 ;
if ( ! F_105 ( V_291 ) )
return - V_292 ;
if ( V_17 . V_569 . V_190 >= V_570 )
return - V_30 ;
if ( ( V_17 . V_569 . V_190 & V_571 ) &&
( ( V_17 . V_569 . type == V_572 ) ||
( V_17 . V_569 . type == V_573 ) ) )
return - V_30 ;
if ( V_17 . V_569 . V_574 > V_575 )
return - V_30 ;
if ( V_17 . V_569 . V_473 > V_209 -> V_236 ||
V_17 . V_569 . V_473 >
( V_17 . V_569 . V_574 * sizeof( struct V_467 ) ) )
return - V_30 ;
if ( V_17 . V_569 . V_238 [ 0 ] ||
V_17 . V_569 . V_238 [ 1 ] )
return - V_30 ;
if ( V_17 . V_569 . V_574 ) {
V_567 = F_47 ( sizeof( * V_567 ) + V_17 . V_569 . V_473 ,
V_147 ) ;
if ( ! V_567 )
return - V_148 ;
memcpy ( V_567 , & V_17 . V_569 , sizeof( * V_567 ) ) ;
V_31 = F_94 ( V_567 + 1 , V_209 ,
V_17 . V_569 . V_473 ) ;
if ( V_31 )
goto V_576;
} else {
V_567 = & V_17 . V_569 ;
}
V_6 = F_38 ( F_3 ( V_577 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) ) {
V_31 = F_13 ( V_6 ) ;
goto V_576;
}
V_258 = F_71 ( V_258 , V_17 . V_337 , V_11 -> V_22 ) ;
if ( ! V_258 ) {
V_31 = - V_30 ;
goto V_526;
}
V_569 = F_175 ( sizeof( * V_569 ) + V_17 . V_569 . V_574 *
sizeof( union V_469 ) , V_147 ) ;
if ( ! V_569 ) {
V_31 = - V_148 ;
goto V_182;
}
V_569 -> type = V_567 -> type ;
V_569 -> V_578 = V_567 -> V_578 ;
V_569 -> V_574 = V_567 -> V_574 ;
V_569 -> V_335 = V_567 -> V_335 ;
V_569 -> V_190 = V_567 -> V_190 ;
V_569 -> V_473 = sizeof( * V_569 ) ;
V_468 = V_567 + 1 ;
V_470 = V_569 + 1 ;
for ( V_413 = 0 ; V_413 < V_569 -> V_574 &&
V_17 . V_569 . V_473 > F_86 ( struct V_467 , V_238 ) &&
V_17 . V_569 . V_473 >=
( (struct V_467 * ) V_468 ) -> V_473 ; V_413 ++ ) {
V_31 = F_165 ( V_468 , V_470 ) ;
if ( V_31 )
goto V_54;
V_569 -> V_473 +=
( (union V_469 * ) V_470 ) -> V_473 ;
V_17 . V_569 . V_473 -= ( (struct V_467 * ) V_468 ) -> V_473 ;
V_468 += ( (struct V_467 * ) V_468 ) -> V_473 ;
V_470 += ( (union V_469 * ) V_470 ) -> V_473 ;
}
if ( V_17 . V_569 . V_473 || ( V_413 != V_569 -> V_574 ) ) {
F_176 ( L_2 ,
V_413 , V_17 . V_569 . V_473 ) ;
V_31 = - V_30 ;
goto V_54;
}
V_565 = F_177 ( V_258 , V_569 , V_579 ) ;
if ( F_4 ( V_565 ) ) {
V_31 = F_13 ( V_565 ) ;
goto V_54;
}
V_565 -> V_128 = V_6 ;
V_6 -> V_131 = V_565 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_580 = V_6 -> V_133 ;
V_31 = F_91 ( V_209 ,
& V_19 , sizeof( V_19 ) ) ;
if ( V_31 )
goto V_134;
F_73 ( V_258 ) ;
F_40 ( V_6 ) ;
F_49 ( V_569 ) ;
if ( V_17 . V_569 . V_574 )
F_49 ( V_567 ) ;
return 0 ;
V_134:
F_178 ( V_565 ) ;
V_54:
F_49 ( V_569 ) ;
V_182:
F_73 ( V_258 ) ;
V_526:
F_42 ( V_6 ) ;
V_576:
if ( V_17 . V_569 . V_574 )
F_49 ( V_567 ) ;
return V_31 ;
}
int F_179 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_581 V_17 ;
struct V_5 * V_6 ;
int V_26 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
V_26 = F_94 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_237 )
return - V_30 ;
V_6 = F_44 ( F_3 ( V_577 ) , V_17 . V_580 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_45 ( V_6 ) ;
return V_26 ;
}
static int F_180 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_582 * V_17 ,
struct V_20 * V_21 )
{
struct V_583 V_19 ;
struct V_584 * V_155 ;
struct V_125 * V_126 ;
struct V_282 * V_283 ;
struct V_5 * V_341 ( V_278 ) ;
struct V_585 V_61 ;
int V_26 ;
V_155 = (struct V_584 * ) F_38 ( F_3 ( V_283 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_155 ) )
return F_13 ( V_155 ) ;
if ( V_17 -> V_309 == V_586 ) {
V_278 = F_2 ( F_3 ( V_139 ) , V_17 -> V_169 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_278 ) ) {
V_26 = - V_30 ;
goto V_31;
}
V_61 . V_587 . V_588 . V_139 = (struct V_138 * ) V_278 -> V_131 ;
if ( ! V_61 . V_587 . V_588 . V_139 ) {
V_26 = - V_30 ;
goto V_589;
}
V_155 -> V_293 = F_7 ( V_278 , struct V_154 , V_128 ) ;
F_62 ( & V_155 -> V_293 -> V_168 ) ;
V_61 . V_587 . V_588 . V_215 = F_71 ( V_215 , V_17 -> V_231 ,
V_11 -> V_22 ) ;
if ( ! V_61 . V_587 . V_588 . V_215 ) {
V_26 = - V_30 ;
goto V_589;
}
}
V_126 = F_71 ( V_126 , V_17 -> V_132 , V_11 -> V_22 ) ;
if ( ! V_126 ) {
V_26 = - V_30 ;
goto V_533;
}
V_61 . V_227 = V_590 ;
V_61 . V_591 = V_11 ;
V_61 . V_309 = V_17 -> V_309 ;
V_61 . V_61 . V_528 = V_17 -> V_528 ;
V_61 . V_61 . V_72 = V_17 -> V_72 ;
V_61 . V_61 . V_592 = V_17 -> V_592 ;
V_155 -> V_294 . V_325 = 0 ;
F_20 ( & V_155 -> V_294 . V_326 ) ;
V_283 = V_126 -> V_36 -> V_593 ( V_126 , & V_61 , V_21 ) ;
if ( F_4 ( V_283 ) ) {
V_26 = F_13 ( V_283 ) ;
goto V_182;
}
V_283 -> V_36 = V_126 -> V_36 ;
V_283 -> V_126 = V_126 ;
V_283 -> V_309 = V_17 -> V_309 ;
V_283 -> V_128 = & V_155 -> V_294 . V_128 ;
V_283 -> V_227 = V_61 . V_227 ;
V_283 -> V_591 = V_61 . V_591 ;
if ( V_17 -> V_309 == V_586 ) {
V_283 -> V_587 . V_588 . V_215 = V_61 . V_587 . V_588 . V_215 ;
V_283 -> V_587 . V_588 . V_139 = V_61 . V_587 . V_588 . V_139 ;
F_62 ( & V_61 . V_587 . V_588 . V_215 -> V_130 ) ;
F_62 ( & V_61 . V_587 . V_588 . V_139 -> V_130 ) ;
}
F_62 ( & V_126 -> V_130 ) ;
F_39 ( & V_283 -> V_130 , 0 ) ;
V_155 -> V_294 . V_128 . V_131 = V_283 ;
V_155 -> V_294 . V_128 . V_218 = V_17 -> V_218 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_308 = V_155 -> V_294 . V_128 . V_133 ;
V_19 . V_528 = V_61 . V_61 . V_528 ;
V_19 . V_72 = V_61 . V_61 . V_72 ;
if ( V_17 -> V_309 == V_586 )
V_19 . V_594 = V_283 -> V_587 . V_588 . V_595 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 -> V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_134;
}
if ( V_17 -> V_309 == V_586 ) {
F_6 ( V_278 ) ;
F_73 ( V_61 . V_587 . V_588 . V_215 ) ;
}
F_73 ( V_126 ) ;
F_40 ( & V_155 -> V_294 . V_128 ) ;
return 0 ;
V_134:
F_181 ( V_283 ) ;
V_182:
F_73 ( V_126 ) ;
V_533:
if ( V_17 -> V_309 == V_586 )
F_73 ( V_61 . V_587 . V_588 . V_215 ) ;
V_589:
if ( V_17 -> V_309 == V_586 ) {
F_64 ( & V_155 -> V_293 -> V_168 ) ;
F_6 ( V_278 ) ;
}
V_31:
F_42 ( & V_155 -> V_294 . V_128 ) ;
return V_26 ;
}
T_1 F_182 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_182 V_17 ;
struct V_582 V_596 ;
struct V_583 V_19 ;
struct V_20 V_21 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_596 . V_32 = V_17 . V_32 ;
V_596 . V_218 = V_17 . V_218 ;
V_596 . V_309 = V_310 ;
V_596 . V_132 = V_17 . V_132 ;
V_596 . V_528 = V_17 . V_528 ;
V_596 . V_72 = V_17 . V_72 ;
V_596 . V_592 = V_17 . V_592 ;
F_11 ( & V_21 , V_14 + sizeof V_17 ,
( unsigned long ) V_17 . V_32 + sizeof V_19 ,
V_15 - sizeof V_17 - sizeof( struct V_201 ) ,
V_16 - sizeof V_19 ) ;
V_26 = F_180 ( V_11 , V_13 , & V_596 , & V_21 ) ;
if ( V_26 )
return V_26 ;
return V_15 ;
}
T_1 V_582 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 , int V_16 )
{
struct V_582 V_17 ;
struct V_583 V_19 ;
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
V_26 = F_180 ( V_11 , V_13 , & V_17 , & V_21 ) ;
if ( V_26 )
return V_26 ;
return V_15 ;
}
T_1 F_183 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_183 V_17 ;
struct V_20 V_21 ;
struct V_282 * V_283 ;
struct V_597 V_61 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 , NULL , V_15 - sizeof V_17 ,
V_16 ) ;
V_283 = F_71 ( V_283 , V_17 . V_308 , V_11 -> V_22 ) ;
if ( ! V_283 )
return - V_30 ;
V_61 . V_528 = V_17 . V_528 ;
V_61 . V_592 = V_17 . V_592 ;
V_26 = V_283 -> V_36 -> V_598 ( V_283 , & V_61 , V_17 . V_350 , & V_21 ) ;
F_73 ( V_283 ) ;
return V_26 ? V_26 : V_15 ;
}
T_1 F_184 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_184 V_17 ;
struct V_599 V_19 ;
struct V_597 V_61 ;
struct V_282 * V_283 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_283 = F_71 ( V_283 , V_17 . V_308 , V_11 -> V_22 ) ;
if ( ! V_283 )
return - V_30 ;
V_26 = F_185 ( V_283 , & V_61 ) ;
F_73 ( V_283 ) ;
if ( V_26 )
return V_26 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_528 = V_61 . V_528 ;
V_19 . V_72 = V_61 . V_72 ;
V_19 . V_592 = V_61 . V_592 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
T_1 F_186 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_186 V_17 ;
struct V_600 V_19 ;
struct V_5 * V_6 ;
struct V_601 * V_155 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_44 ( F_3 ( V_283 ) , V_17 . V_308 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_155 = F_7 ( V_6 , struct V_601 , V_128 ) ;
F_5 ( V_6 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_26 = F_45 ( V_6 ) ;
if ( V_26 ) {
F_103 ( V_6 ) ;
return V_26 ;
}
V_19 . V_325 = V_155 -> V_325 ;
F_103 ( V_6 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof( V_19 ) ) )
return - V_28 ;
return V_15 ;
}
int F_187 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_602 V_19 = { { 0 } } ;
struct F_187 V_17 ;
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
