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
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
V_26 = F_12 ( & V_25 , V_13 , V_34 ) ;
if ( V_26 )
goto V_31;
V_22 = V_13 -> V_35 ( V_13 , & V_21 ) ;
if ( F_4 ( V_22 ) ) {
V_26 = F_13 ( V_22 ) ;
goto V_36;
}
V_22 -> V_37 = V_13 ;
V_22 -> V_25 = V_25 ;
V_22 -> V_38 = V_11 ;
F_14 ( V_22 ) ;
F_15 () ;
V_22 -> V_39 = F_16 ( V_40 -> V_41 , V_42 ) ;
F_17 () ;
V_22 -> V_43 = 0 ;
#ifdef F_18
V_22 -> V_44 = V_45 ;
F_19 ( & V_22 -> V_46 ) ;
V_22 -> V_47 = 0 ;
F_20 ( & V_22 -> V_48 ) ;
if ( ! ( V_13 -> V_49 . V_50 & V_51 ) )
V_22 -> V_52 = NULL ;
#endif
V_19 . V_53 = V_11 -> V_37 -> V_53 ;
V_26 = F_21 ( V_54 ) ;
if ( V_26 < 0 )
goto V_55;
V_19 . V_56 = V_26 ;
V_23 = F_22 ( V_11 , V_13 ) ;
if ( F_4 ( V_23 ) ) {
V_26 = F_13 ( V_23 ) ;
goto V_57;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_58;
}
V_11 -> V_22 = V_22 ;
F_24 ( V_19 . V_56 , V_23 ) ;
F_25 ( & V_11 -> V_29 ) ;
return V_15 ;
V_58:
F_26 ( V_11 ) ;
F_27 ( V_23 ) ;
V_57:
F_28 ( V_19 . V_56 ) ;
V_55:
F_29 ( V_22 -> V_39 ) ;
V_13 -> V_59 ( V_22 ) ;
V_36:
F_30 ( & V_25 , V_13 , V_34 ) ;
V_31:
F_25 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static void F_31 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_60 * V_19 ,
struct V_61 * V_62 )
{
V_19 -> V_63 = V_62 -> V_63 ;
V_19 -> V_64 = V_13 -> V_64 ;
V_19 -> V_65 = V_62 -> V_65 ;
V_19 -> V_66 = V_62 -> V_66 ;
V_19 -> V_67 = V_62 -> V_67 ;
V_19 -> V_68 = V_62 -> V_68 ;
V_19 -> V_69 = V_62 -> V_69 ;
V_19 -> V_70 = V_62 -> V_70 ;
V_19 -> V_71 = V_62 -> V_71 ;
V_19 -> V_72 = V_62 -> V_72 ;
V_19 -> V_50 = F_32 ( V_62 -> V_50 ) ;
V_19 -> V_73 = V_62 -> V_73 ;
V_19 -> V_74 = V_62 -> V_74 ;
V_19 -> V_75 = V_62 -> V_75 ;
V_19 -> V_76 = V_62 -> V_76 ;
V_19 -> V_77 = V_62 -> V_77 ;
V_19 -> V_78 = V_62 -> V_78 ;
V_19 -> V_79 = V_62 -> V_79 ;
V_19 -> V_80 = V_62 -> V_80 ;
V_19 -> V_81 = V_62 -> V_81 ;
V_19 -> V_82 = V_62 -> V_82 ;
V_19 -> V_83 = V_62 -> V_83 ;
V_19 -> V_84 = V_62 -> V_84 ;
V_19 -> V_85 = V_62 -> V_85 ;
V_19 -> V_86 = V_62 -> V_86 ;
V_19 -> V_87 = V_62 -> V_87 ;
V_19 -> V_88 = V_62 -> V_88 ;
V_19 -> V_89 = V_62 -> V_89 ;
V_19 -> V_90 = V_62 -> V_90 ;
V_19 -> V_91 = V_62 -> V_91 ;
V_19 -> V_92 = V_62 -> V_92 ;
V_19 -> V_93 = V_62 -> V_93 ;
V_19 -> V_94 = V_62 -> V_94 ;
V_19 -> V_95 = V_62 -> V_95 ;
V_19 -> V_96 = V_62 -> V_96 ;
V_19 -> V_97 = V_62 -> V_97 ;
V_19 -> V_98 = V_62 -> V_98 ;
V_19 -> V_99 = V_62 -> V_99 ;
V_19 -> V_100 = V_62 -> V_100 ;
V_19 -> V_101 = V_13 -> V_101 ;
}
T_1 F_33 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_33 V_17 ;
struct V_60 V_19 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
F_31 ( V_11 , V_13 , & V_19 , & V_13 -> V_49 ) ;
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
struct V_102 V_19 ;
struct V_103 V_62 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_26 = F_35 ( V_13 , V_17 . V_104 , & V_62 ) ;
if ( V_26 )
return V_26 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_105 = V_62 . V_105 ;
V_19 . V_106 = V_62 . V_106 ;
V_19 . V_107 = V_62 . V_107 ;
V_19 . V_108 = V_62 . V_108 ;
V_19 . V_109 = V_62 . V_109 ;
V_19 . V_110 = V_62 . V_110 ;
V_19 . V_111 = V_62 . V_111 ;
V_19 . V_112 = V_62 . V_112 ;
V_19 . V_113 = V_62 . V_113 ;
if ( F_36 ( V_13 , V_17 . V_104 ) ) {
V_19 . V_114 = F_37 ( V_62 . V_114 ) ;
V_19 . V_115 = F_37 ( V_62 . V_115 ) ;
} else {
V_19 . V_114 = F_38 ( V_62 . V_114 ) ;
V_19 . V_115 = F_38 ( V_62 . V_115 ) ;
}
V_19 . V_116 = V_62 . V_116 ;
V_19 . V_117 = V_62 . V_117 ;
V_19 . V_118 = V_62 . V_118 ;
V_19 . V_119 = V_62 . V_119 ;
V_19 . V_120 = V_62 . V_120 ;
V_19 . V_121 = V_62 . V_121 ;
V_19 . V_122 = V_62 . V_122 ;
V_19 . V_123 = V_62 . V_123 ;
V_19 . V_124 = F_39 ( V_13 ,
V_17 . V_104 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
T_1 F_40 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_40 V_17 ;
struct V_125 V_19 ;
struct V_20 V_21 ;
struct V_5 * V_6 ;
struct V_126 * V_127 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
V_6 = F_41 ( F_3 ( V_127 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_127 = V_13 -> V_128 ( V_13 , V_11 -> V_22 , & V_21 ) ;
if ( F_4 ( V_127 ) ) {
V_26 = F_13 ( V_127 ) ;
goto V_31;
}
V_127 -> V_37 = V_13 ;
V_127 -> V_129 = V_6 ;
V_127 -> V_130 = NULL ;
F_42 ( & V_127 -> V_131 , 0 ) ;
V_6 -> V_132 = V_127 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_133 = V_6 -> V_134 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_135;
}
F_43 ( V_6 ) ;
return V_15 ;
V_135:
F_44 ( V_127 ) ;
V_31:
F_45 ( V_6 ) ;
return V_26 ;
}
T_1 F_46 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_46 V_17 ;
struct V_5 * V_6 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_47 ( F_3 ( V_127 ) , V_17 . V_133 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_48 ( V_6 ) ;
return V_26 ? : V_15 ;
}
static int F_49 ( struct V_136 * V_137 ,
struct V_138 * V_138 ,
struct V_139 * V_140 )
{
struct V_141 * V_142 , * V_143 ;
struct V_144 * * V_145 = & V_137 -> V_146 . V_144 ;
struct V_144 * V_147 = NULL ;
V_142 = F_50 ( sizeof *V_142 , V_148 ) ;
if ( ! V_142 )
return - V_149 ;
V_142 -> V_140 = V_140 ;
V_142 -> V_138 = V_138 ;
while ( * V_145 ) {
V_147 = * V_145 ;
V_143 = F_51 ( V_147 , struct V_141 , V_150 ) ;
if ( V_138 < V_143 -> V_138 ) {
V_145 = & ( * V_145 ) -> V_151 ;
} else if ( V_138 > V_143 -> V_138 ) {
V_145 = & ( * V_145 ) -> V_152 ;
} else {
F_52 ( V_142 ) ;
return - V_153 ;
}
}
F_53 ( & V_142 -> V_150 , V_147 , V_145 ) ;
F_54 ( & V_142 -> V_150 , & V_137 -> V_146 ) ;
F_55 ( V_138 ) ;
return 0 ;
}
static struct V_141 * F_56 ( struct V_136 * V_137 ,
struct V_138 * V_138 )
{
struct V_141 * V_142 ;
struct V_144 * V_145 = V_137 -> V_146 . V_144 ;
while ( V_145 ) {
V_142 = F_51 ( V_145 , struct V_141 , V_150 ) ;
if ( V_138 < V_142 -> V_138 )
V_145 = V_145 -> V_151 ;
else if ( V_138 > V_142 -> V_138 )
V_145 = V_145 -> V_152 ;
else
return V_142 ;
}
return NULL ;
}
static struct V_139 * F_57 ( struct V_136 * V_137 , struct V_138 * V_138 )
{
struct V_141 * V_142 ;
V_142 = F_56 ( V_137 , V_138 ) ;
if ( ! V_142 )
return NULL ;
return V_142 -> V_140 ;
}
static void F_58 ( struct V_136 * V_137 ,
struct V_138 * V_138 )
{
struct V_141 * V_142 ;
V_142 = F_56 ( V_137 , V_138 ) ;
if ( V_142 ) {
F_59 ( V_138 ) ;
F_60 ( & V_142 -> V_150 , & V_137 -> V_146 ) ;
F_52 ( V_142 ) ;
}
}
T_1 F_61 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_61 V_17 ;
struct V_154 V_19 ;
struct V_20 V_21 ;
struct V_155 * V_156 ;
struct V_139 * V_140 = NULL ;
struct V_2 V_157 = { NULL , 0 } ;
struct V_138 * V_138 = NULL ;
int V_26 = 0 ;
int V_158 = 0 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
F_10 ( & V_11 -> V_37 -> V_159 ) ;
if ( V_17 . V_2 != - 1 ) {
V_157 = F_62 ( V_17 . V_2 ) ;
if ( ! V_157 . V_11 ) {
V_26 = - V_160 ;
goto V_161;
}
V_138 = F_63 ( V_157 . V_11 ) ;
V_140 = F_57 ( V_11 -> V_37 , V_138 ) ;
if ( ! V_140 && ! ( V_17 . V_162 & V_163 ) ) {
V_26 = - V_164 ;
goto V_161;
}
if ( V_140 && V_17 . V_162 & V_165 ) {
V_26 = - V_30 ;
goto V_161;
}
}
V_156 = (struct V_155 * ) F_41 ( F_3 ( V_140 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_156 ) ) {
V_26 = F_13 ( V_156 ) ;
goto V_161;
}
if ( ! V_140 ) {
V_140 = V_13 -> V_166 ( V_13 , V_11 -> V_22 , & V_21 ) ;
if ( F_4 ( V_140 ) ) {
V_26 = F_13 ( V_140 ) ;
goto V_31;
}
V_140 -> V_138 = V_138 ;
V_140 -> V_37 = V_13 ;
F_42 ( & V_140 -> V_131 , 0 ) ;
F_64 ( & V_140 -> V_167 ) ;
F_20 ( & V_140 -> V_168 ) ;
V_158 = 1 ;
}
F_42 ( & V_156 -> V_169 , 0 ) ;
V_156 -> V_129 . V_132 = V_140 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_170 = V_156 -> V_129 . V_134 ;
if ( V_138 ) {
if ( V_158 ) {
V_26 = F_49 ( V_11 -> V_37 , V_138 , V_140 ) ;
if ( V_26 )
goto V_171;
}
F_65 ( & V_140 -> V_131 ) ;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_135;
}
if ( V_157 . V_11 )
F_66 ( V_157 ) ;
F_43 ( & V_156 -> V_129 ) ;
F_25 ( & V_11 -> V_37 -> V_159 ) ;
return V_15 ;
V_135:
if ( V_138 ) {
if ( V_158 )
F_58 ( V_11 -> V_37 , V_138 ) ;
F_67 ( & V_140 -> V_131 ) ;
}
V_171:
F_68 ( V_140 ) ;
V_31:
F_45 ( & V_156 -> V_129 ) ;
V_161:
if ( V_157 . V_11 )
F_66 ( V_157 ) ;
F_25 ( & V_11 -> V_37 -> V_159 ) ;
return V_26 ;
}
T_1 F_69 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_69 V_17 ;
struct V_5 * V_6 ;
int V_26 = 0 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_47 ( F_3 ( V_140 ) , V_17 . V_170 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) ) {
F_25 ( & V_11 -> V_37 -> V_159 ) ;
return F_13 ( V_6 ) ;
}
V_26 = F_48 ( V_6 ) ;
return V_26 ? : V_15 ;
}
int F_70 ( struct V_136 * V_137 ,
struct V_139 * V_140 ,
enum V_172 V_173 )
{
struct V_138 * V_138 ;
int V_26 ;
V_138 = V_140 -> V_138 ;
if ( V_138 && ! F_71 ( & V_140 -> V_131 ) )
return 0 ;
V_26 = F_68 ( V_140 ) ;
if ( V_173 == V_174 && V_26 )
F_65 ( & V_140 -> V_131 ) ;
else if ( V_138 )
F_58 ( V_137 , V_138 ) ;
return V_26 ;
}
T_1 F_72 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_72 V_17 ;
struct V_175 V_19 ;
struct V_20 V_21 ;
struct V_5 * V_6 ;
struct V_126 * V_127 ;
struct V_176 * V_177 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
if ( ( V_17 . V_178 & ~ V_179 ) != ( V_17 . V_180 & ~ V_179 ) )
return - V_30 ;
V_26 = F_73 ( V_17 . V_181 ) ;
if ( V_26 )
return V_26 ;
V_6 = F_41 ( F_3 ( V_177 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_127 = F_74 ( V_127 , V_17 . V_133 , V_11 -> V_22 ) ;
if ( ! V_127 ) {
V_26 = - V_30 ;
goto V_55;
}
if ( V_17 . V_181 & V_182 ) {
if ( ! ( V_127 -> V_37 -> V_49 . V_50 &
V_51 ) ) {
F_75 ( L_1 ) ;
V_26 = - V_30 ;
goto V_183;
}
}
V_177 = V_127 -> V_37 -> V_184 ( V_127 , V_17 . V_178 , V_17 . V_185 , V_17 . V_180 ,
V_17 . V_181 , & V_21 ) ;
if ( F_4 ( V_177 ) ) {
V_26 = F_13 ( V_177 ) ;
goto V_183;
}
V_177 -> V_37 = V_127 -> V_37 ;
V_177 -> V_127 = V_127 ;
V_177 -> V_129 = V_6 ;
F_65 ( & V_127 -> V_131 ) ;
V_6 -> V_132 = V_177 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_186 = V_177 -> V_186 ;
V_19 . V_187 = V_177 -> V_187 ;
V_19 . V_188 = V_6 -> V_134 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_135;
}
F_76 ( V_127 ) ;
F_43 ( V_6 ) ;
return V_15 ;
V_135:
F_77 ( V_177 ) ;
V_183:
F_76 ( V_127 ) ;
V_55:
F_45 ( V_6 ) ;
return V_26 ;
}
T_1 F_78 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_78 V_17 ;
struct V_189 V_19 ;
struct V_20 V_21 ;
struct V_126 * V_127 = NULL ;
struct V_176 * V_177 ;
struct V_126 * V_190 ;
int V_26 ;
struct V_5 * V_6 ;
if ( V_16 < sizeof( V_19 ) )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
if ( V_17 . V_191 & ~ V_192 || ! V_17 . V_191 )
return - V_30 ;
if ( ( V_17 . V_191 & V_193 ) &&
( ! V_17 . V_178 || ! V_17 . V_180 || 0 >= V_17 . V_185 ||
( V_17 . V_178 & ~ V_179 ) != ( V_17 . V_180 & ~ V_179 ) ) )
return - V_30 ;
V_6 = F_47 ( F_3 ( V_177 ) , V_17 . V_188 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_177 = V_6 -> V_132 ;
if ( V_17 . V_191 & V_194 ) {
V_26 = F_73 ( V_17 . V_181 ) ;
if ( V_26 )
goto V_195;
}
if ( V_17 . V_191 & V_196 ) {
V_127 = F_74 ( V_127 , V_17 . V_133 , V_11 -> V_22 ) ;
if ( ! V_127 ) {
V_26 = - V_30 ;
goto V_195;
}
}
V_190 = V_177 -> V_127 ;
V_26 = V_177 -> V_37 -> V_197 ( V_177 , V_17 . V_191 , V_17 . V_178 ,
V_17 . V_185 , V_17 . V_180 ,
V_17 . V_181 , V_127 , & V_21 ) ;
if ( ! V_26 ) {
if ( V_17 . V_191 & V_196 ) {
F_65 ( & V_127 -> V_131 ) ;
V_177 -> V_127 = V_127 ;
F_67 ( & V_190 -> V_131 ) ;
}
} else {
goto V_198;
}
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_186 = V_177 -> V_186 ;
V_19 . V_187 = V_177 -> V_187 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof( V_19 ) ) )
V_26 = - V_28 ;
else
V_26 = V_15 ;
V_198:
if ( V_17 . V_191 & V_196 )
F_76 ( V_127 ) ;
V_195:
F_79 ( V_6 ) ;
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
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_47 ( F_3 ( V_177 ) , V_17 . V_188 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_48 ( V_6 ) ;
return V_26 ? : V_15 ;
}
T_1 F_81 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_81 V_17 ;
struct V_199 V_19 ;
struct V_5 * V_6 ;
struct V_126 * V_127 ;
struct V_200 * V_201 ;
struct V_20 V_21 ;
int V_26 ;
if ( V_16 < sizeof( V_19 ) )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
V_6 = F_41 ( F_3 ( V_201 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_127 = F_74 ( V_127 , V_17 . V_133 , V_11 -> V_22 ) ;
if ( ! V_127 ) {
V_26 = - V_30 ;
goto V_55;
}
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
V_201 = V_127 -> V_37 -> V_202 ( V_127 , V_17 . V_203 , & V_21 ) ;
if ( F_4 ( V_201 ) ) {
V_26 = F_13 ( V_201 ) ;
goto V_183;
}
V_201 -> V_37 = V_127 -> V_37 ;
V_201 -> V_127 = V_127 ;
V_201 -> V_129 = V_6 ;
F_65 ( & V_127 -> V_131 ) ;
V_6 -> V_132 = V_201 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_187 = V_201 -> V_187 ;
V_19 . V_204 = V_6 -> V_134 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof( V_19 ) ) ) {
V_26 = - V_28 ;
goto V_135;
}
F_76 ( V_127 ) ;
F_43 ( V_6 ) ;
return V_15 ;
V_135:
F_82 ( V_201 ) ;
V_183:
F_76 ( V_127 ) ;
V_55:
F_45 ( V_6 ) ;
return V_26 ;
}
T_1 F_83 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_83 V_17 ;
struct V_5 * V_6 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
V_6 = F_47 ( F_3 ( V_201 ) , V_17 . V_204 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_48 ( V_6 ) ;
return V_26 ? : V_15 ;
}
T_1 F_84 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_84 V_17 ;
struct V_205 V_19 ;
struct V_5 * V_6 ;
struct V_1 * V_206 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_41 ( F_3 ( V_7 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_19 . V_2 = V_6 -> V_134 ;
V_206 = F_7 ( V_6 , struct V_1 ,
V_9 . V_6 ) ;
F_85 ( & V_206 -> V_207 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
F_45 ( V_6 ) ;
return - V_28 ;
}
F_43 ( V_6 ) ;
return V_15 ;
}
static struct V_208 * F_86 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 ,
struct V_211 * V_17 ,
T_3 V_212 ,
int (* F_87)( struct V_10 * V_11 ,
struct V_208 * V_156 ,
struct V_213 * V_19 ,
struct V_20 * V_21 ,
void * V_4 ) ,
void * V_4 )
{
struct V_208 * V_156 ;
struct V_1 * V_206 = NULL ;
struct V_214 * V_215 ;
int V_26 ;
struct V_213 V_19 ;
struct V_216 V_62 = {} ;
if ( V_17 -> V_217 >= V_11 -> V_37 -> V_53 )
return F_88 ( - V_30 ) ;
V_156 = (struct V_208 * ) F_41 ( F_3 ( V_215 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_156 ) )
return V_156 ;
if ( V_17 -> V_7 >= 0 ) {
V_206 = F_1 ( V_17 -> V_7 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_206 ) ) {
V_26 = F_13 ( V_206 ) ;
goto V_31;
}
}
V_156 -> V_129 . V_218 = V_17 -> V_218 ;
V_156 -> V_219 = V_11 ;
V_156 -> V_220 = 0 ;
V_156 -> V_221 = 0 ;
F_20 ( & V_156 -> V_222 ) ;
F_20 ( & V_156 -> V_223 ) ;
V_62 . V_224 = V_17 -> V_224 ;
V_62 . V_217 = V_17 -> V_217 ;
if ( V_212 > F_89 ( F_90 ( * V_17 ) , V_191 ) + sizeof( V_17 -> V_191 ) )
V_62 . V_191 = V_17 -> V_191 ;
V_215 = V_13 -> F_86 ( V_13 , & V_62 , V_11 -> V_22 , V_210 ) ;
if ( F_4 ( V_215 ) ) {
V_26 = F_13 ( V_215 ) ;
goto V_58;
}
V_215 -> V_37 = V_13 ;
V_215 -> V_129 = & V_156 -> V_129 ;
V_215 -> V_225 = V_226 ;
V_215 -> V_227 = V_228 ;
V_215 -> V_229 = V_206 ? & V_206 -> V_207 : NULL ;
F_42 ( & V_215 -> V_131 , 0 ) ;
V_156 -> V_129 . V_132 = V_215 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_230 . V_231 = V_156 -> V_129 . V_134 ;
V_19 . V_230 . V_224 = V_215 -> V_224 ;
V_19 . V_232 = F_89 ( F_90 ( V_19 ) , V_232 ) +
sizeof( V_19 . V_232 ) ;
V_26 = F_87 ( V_11 , V_156 , & V_19 , V_209 , V_4 ) ;
if ( V_26 )
goto V_233;
F_43 ( & V_156 -> V_129 ) ;
return V_156 ;
V_233:
F_91 ( V_215 ) ;
V_58:
if ( V_206 )
F_92 ( V_11 , V_206 , V_156 ) ;
V_31:
F_45 ( & V_156 -> V_129 ) ;
return F_88 ( V_26 ) ;
}
static int F_93 ( struct V_10 * V_11 ,
struct V_208 * V_156 ,
struct V_213 * V_19 ,
struct V_20 * V_209 , void * V_4 )
{
if ( F_94 ( V_209 , & V_19 -> V_230 , sizeof( V_19 -> V_230 ) ) )
return - V_28 ;
return 0 ;
}
T_1 F_95 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_95 V_17 ;
struct V_211 V_234 ;
struct V_235 V_19 ;
struct V_20 V_209 ;
struct V_20 V_210 ;
struct V_208 * V_156 ;
if ( V_16 < sizeof( V_19 ) )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
F_11 ( & V_209 , V_14 , ( unsigned long ) V_17 . V_32 , sizeof( V_17 ) , sizeof( V_19 ) ) ;
F_11 ( & V_210 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_218 = V_17 . V_218 ;
V_234 . V_224 = V_17 . V_224 ;
V_234 . V_217 = V_17 . V_217 ;
V_234 . V_7 = V_17 . V_7 ;
V_156 = F_86 ( V_11 , V_13 , & V_209 , & V_210 , & V_234 ,
F_89 ( F_90 ( V_234 ) , V_7 ) +
sizeof( V_17 . V_7 ) , F_93 ,
NULL ) ;
if ( F_4 ( V_156 ) )
return F_13 ( V_156 ) ;
return V_15 ;
}
static int F_96 ( struct V_10 * V_11 ,
struct V_208 * V_156 ,
struct V_213 * V_19 ,
struct V_20 * V_209 , void * V_4 )
{
if ( F_94 ( V_209 , V_19 , V_19 -> V_232 ) )
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
struct V_208 * V_156 ;
int V_31 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
V_31 = F_97 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_31 )
return V_31 ;
if ( V_17 . V_237 )
return - V_30 ;
if ( V_17 . V_238 )
return - V_30 ;
if ( V_209 -> V_239 < ( F_89 ( F_90 ( V_19 ) , V_232 ) +
sizeof( V_19 . V_232 ) ) )
return - V_27 ;
V_156 = F_86 ( V_11 , V_13 , V_209 , V_210 , & V_17 ,
F_98 ( V_209 -> V_236 , sizeof( V_17 ) ) ,
F_96 , NULL ) ;
if ( F_4 ( V_156 ) )
return F_13 ( V_156 ) ;
return 0 ;
}
T_1 F_99 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_99 V_17 ;
struct V_240 V_19 = {} ;
struct V_20 V_21 ;
struct V_214 * V_215 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
V_215 = F_74 ( V_215 , V_17 . V_231 , V_11 -> V_22 ) ;
if ( ! V_215 )
return - V_30 ;
V_26 = V_215 -> V_37 -> V_241 ( V_215 , V_17 . V_224 , & V_21 ) ;
if ( V_26 )
goto V_242;
V_19 . V_224 = V_215 -> V_224 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 . V_224 ) )
V_26 = - V_28 ;
V_242:
F_76 ( V_215 ) ;
return V_26 ? V_26 : V_15 ;
}
static int F_100 ( struct V_12 * V_13 , void T_2 * V_243 ,
struct V_244 * V_245 )
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
if ( F_36 ( V_13 , V_245 -> V_104 ) )
V_247 . V_262 = F_37 ( V_245 -> V_262 ) ;
else
V_247 . V_262 = F_38 ( V_245 -> V_262 ) ;
V_247 . V_263 = V_245 -> V_263 ;
V_247 . V_264 = V_245 -> V_264 ;
V_247 . V_104 = V_245 -> V_104 ;
V_247 . V_238 = 0 ;
if ( F_23 ( V_243 , & V_247 , sizeof V_247 ) )
return - V_28 ;
return 0 ;
}
T_1 F_101 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_101 V_17 ;
struct V_265 V_19 ;
T_4 T_2 * V_266 ;
T_4 T_2 * V_267 ;
struct V_214 * V_215 ;
struct V_244 V_245 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_215 = F_74 ( V_215 , V_17 . V_231 , V_11 -> V_22 ) ;
if ( ! V_215 )
return - V_30 ;
V_266 = ( void T_2 * ) ( unsigned long ) V_17 . V_32 ;
V_267 = V_266 + sizeof V_19 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
while ( V_19 . V_268 < V_17 . V_269 ) {
V_26 = F_102 ( V_215 , 1 , & V_245 ) ;
if ( V_26 < 0 )
goto V_270;
if ( ! V_26 )
break;
V_26 = F_100 ( V_13 , V_267 , & V_245 ) ;
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
F_76 ( V_215 ) ;
return V_26 ;
}
T_1 F_103 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_103 V_17 ;
struct V_214 * V_215 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_215 = F_74 ( V_215 , V_17 . V_231 , V_11 -> V_22 ) ;
if ( ! V_215 )
return - V_30 ;
F_104 ( V_215 , V_17 . V_271 ?
V_272 : V_273 ) ;
F_76 ( V_215 ) ;
return V_15 ;
}
T_1 F_105 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_105 V_17 ;
struct V_274 V_19 ;
struct V_5 * V_6 ;
struct V_214 * V_215 ;
struct V_208 * V_156 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_47 ( F_3 ( V_215 ) , V_17 . V_231 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
F_5 ( V_6 ) ;
V_215 = V_6 -> V_132 ;
V_156 = F_7 ( V_215 -> V_129 , struct V_208 , V_129 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_26 = F_48 ( V_6 ) ;
if ( V_26 ) {
F_106 ( V_6 ) ;
return V_26 ;
}
V_19 . V_220 = V_156 -> V_220 ;
V_19 . V_221 = V_156 -> V_221 ;
F_106 ( V_6 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
static int F_107 ( struct V_10 * V_11 ,
struct V_20 * V_209 ,
struct V_20 * V_210 ,
struct V_275 * V_17 ,
T_3 V_212 ,
int (* F_87)( struct V_10 * V_11 ,
struct V_276 * V_19 ,
struct V_20 * V_21 ) ,
void * V_4 )
{
struct V_277 * V_156 ;
struct V_12 * V_37 ;
struct V_126 * V_127 = NULL ;
struct V_139 * V_140 = NULL ;
struct V_5 * V_278 = F_88 ( - V_279 ) ;
struct V_214 * V_280 = NULL , * V_281 = NULL ;
struct V_282 * V_283 = NULL ;
struct V_284 * V_258 ;
char * V_14 ;
struct V_285 V_62 = {} ;
struct V_276 V_19 ;
int V_26 ;
struct V_286 * V_287 = NULL ;
bool V_288 = true ;
if ( V_17 -> V_289 == V_290 && ! F_108 ( V_291 ) )
return - V_292 ;
V_156 = (struct V_277 * ) F_41 ( F_3 ( V_258 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_156 ) )
return F_13 ( V_156 ) ;
V_156 -> V_293 = NULL ;
V_156 -> V_294 . V_129 . V_218 = V_17 -> V_218 ;
F_64 ( & V_156 -> V_295 ) ;
if ( V_212 >= F_89 ( F_90 ( * V_17 ) , V_296 ) +
sizeof( V_17 -> V_296 ) &&
( V_17 -> V_237 & V_297 ) ) {
V_287 = F_74 ( V_298 ,
V_17 -> V_296 ,
V_11 -> V_22 ) ;
if ( ! V_287 ) {
V_26 = - V_30 ;
goto V_183;
}
V_62 . V_299 = V_287 ;
}
if ( V_212 > sizeof( * V_17 ) &&
! F_109 ( V_209 , sizeof( * V_17 ) ,
V_212 - sizeof( * V_17 ) ) ) {
V_26 = - V_300 ;
goto V_183;
}
if ( V_287 && ( V_17 -> V_301 || V_17 -> V_302 || V_17 -> V_303 ) ) {
V_26 = - V_30 ;
goto V_183;
}
if ( V_287 && ! V_17 -> V_304 )
V_288 = false ;
if ( V_17 -> V_289 == V_305 ) {
V_278 = F_2 ( F_3 ( V_140 ) , V_17 -> V_133 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_278 ) ) {
V_26 = - V_30 ;
goto V_183;
}
V_140 = (struct V_139 * ) V_278 -> V_132 ;
if ( ! V_140 ) {
V_26 = - V_30 ;
goto V_183;
}
V_37 = V_140 -> V_37 ;
} else {
if ( V_17 -> V_289 == V_306 ) {
V_17 -> V_301 = 0 ;
V_17 -> V_302 = 0 ;
} else {
if ( V_17 -> V_303 ) {
V_283 = F_74 ( V_283 , V_17 -> V_307 ,
V_11 -> V_22 ) ;
if ( ! V_283 || V_283 -> V_308 == V_309 ) {
V_26 = - V_30 ;
goto V_183;
}
}
if ( ! V_287 ) {
if ( V_17 -> V_310 != V_17 -> V_311 ) {
V_281 = F_74 ( V_215 , V_17 -> V_310 ,
V_11 -> V_22 ) ;
if ( ! V_281 ) {
V_26 = - V_30 ;
goto V_183;
}
}
}
}
if ( V_288 )
V_280 = F_74 ( V_215 , V_17 -> V_311 ,
V_11 -> V_22 ) ;
if ( ! V_287 )
V_281 = V_281 ? : V_280 ;
V_127 = F_74 ( V_127 , V_17 -> V_133 , V_11 -> V_22 ) ;
if ( ! V_127 || ( ! V_280 && V_288 ) ) {
V_26 = - V_30 ;
goto V_183;
}
V_37 = V_127 -> V_37 ;
}
V_62 . V_227 = V_312 ;
V_62 . V_313 = V_11 ;
V_62 . V_314 = V_280 ;
V_62 . V_315 = V_281 ;
V_62 . V_283 = V_283 ;
V_62 . V_140 = V_140 ;
V_62 . V_316 = V_17 -> V_317 ? V_318 :
V_319 ;
V_62 . V_289 = V_17 -> V_289 ;
V_62 . V_320 = 0 ;
V_62 . V_321 . V_304 = V_17 -> V_304 ;
V_62 . V_321 . V_301 = V_17 -> V_301 ;
V_62 . V_321 . V_322 = V_17 -> V_322 ;
V_62 . V_321 . V_302 = V_17 -> V_302 ;
V_62 . V_321 . V_323 = V_17 -> V_323 ;
V_156 -> V_294 . V_324 = 0 ;
F_20 ( & V_156 -> V_294 . V_325 ) ;
F_20 ( & V_156 -> V_326 ) ;
if ( V_212 >= F_89 ( F_90 ( * V_17 ) , V_320 ) +
sizeof( V_17 -> V_320 ) )
V_62 . V_320 = V_17 -> V_320 ;
if ( V_62 . V_320 & ~ ( V_327 |
V_328 |
V_329 |
V_330 |
V_331 |
V_332 |
V_333 ) ) {
V_26 = - V_30 ;
goto V_183;
}
if ( V_62 . V_320 & V_333 ) {
if ( ! F_108 ( V_291 ) ) {
V_26 = - V_292 ;
goto V_183;
}
V_62 . V_334 = V_17 -> V_334 ;
}
V_14 = ( void * ) V_17 + sizeof( * V_17 ) ;
if ( V_212 > sizeof( * V_17 ) )
if ( ! ( V_14 [ 0 ] == 0 && ! memcmp ( V_14 , V_14 + 1 ,
V_212 - sizeof( * V_17 ) - 1 ) ) ) {
V_26 = - V_30 ;
goto V_183;
}
if ( V_17 -> V_289 == V_305 )
V_258 = F_110 ( V_127 , & V_62 ) ;
else
V_258 = V_37 -> F_107 ( V_127 , & V_62 , V_210 ) ;
if ( F_4 ( V_258 ) ) {
V_26 = F_13 ( V_258 ) ;
goto V_183;
}
if ( V_17 -> V_289 != V_305 ) {
V_26 = F_111 ( V_258 , V_37 ) ;
if ( V_26 )
goto V_233;
V_258 -> V_335 = V_258 ;
V_258 -> V_37 = V_37 ;
V_258 -> V_127 = V_127 ;
V_258 -> V_314 = V_62 . V_314 ;
V_258 -> V_315 = V_62 . V_315 ;
V_258 -> V_283 = V_62 . V_283 ;
V_258 -> V_299 = V_287 ;
V_258 -> V_227 = V_62 . V_227 ;
V_258 -> V_313 = V_62 . V_313 ;
V_258 -> V_289 = V_62 . V_289 ;
F_42 ( & V_258 -> V_131 , 0 ) ;
F_65 ( & V_127 -> V_131 ) ;
V_258 -> V_336 = 0 ;
if ( V_62 . V_314 )
F_65 ( & V_62 . V_314 -> V_131 ) ;
if ( V_62 . V_315 )
F_65 ( & V_62 . V_315 -> V_131 ) ;
if ( V_62 . V_283 )
F_65 ( & V_62 . V_283 -> V_131 ) ;
if ( V_287 )
F_65 ( & V_287 -> V_131 ) ;
}
V_258 -> V_129 = & V_156 -> V_294 . V_129 ;
V_156 -> V_294 . V_129 . V_132 = V_258 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_230 . V_337 = V_258 -> V_257 ;
V_19 . V_230 . V_338 = V_156 -> V_294 . V_129 . V_134 ;
V_19 . V_230 . V_302 = V_62 . V_321 . V_302 ;
V_19 . V_230 . V_322 = V_62 . V_321 . V_322 ;
V_19 . V_230 . V_301 = V_62 . V_321 . V_301 ;
V_19 . V_230 . V_304 = V_62 . V_321 . V_304 ;
V_19 . V_230 . V_323 = V_62 . V_321 . V_323 ;
V_19 . V_232 = F_89 ( F_90 ( V_19 ) , V_232 ) +
sizeof( V_19 . V_232 ) ;
V_26 = F_87 ( V_11 , & V_19 , V_209 ) ;
if ( V_26 )
goto V_233;
if ( V_140 ) {
V_156 -> V_293 = F_7 ( V_278 , struct V_155 ,
V_129 ) ;
F_65 ( & V_156 -> V_293 -> V_169 ) ;
F_6 ( V_278 ) ;
}
if ( V_127 )
F_76 ( V_127 ) ;
if ( V_280 )
F_76 ( V_280 ) ;
if ( V_281 && V_281 != V_280 )
F_76 ( V_281 ) ;
if ( V_283 )
F_76 ( V_283 ) ;
if ( V_287 )
F_76 ( V_287 ) ;
F_43 ( & V_156 -> V_294 . V_129 ) ;
return 0 ;
V_233:
F_112 ( V_258 ) ;
V_183:
if ( ! F_4 ( V_278 ) )
F_6 ( V_278 ) ;
if ( V_127 )
F_76 ( V_127 ) ;
if ( V_280 )
F_76 ( V_280 ) ;
if ( V_281 && V_281 != V_280 )
F_76 ( V_281 ) ;
if ( V_283 )
F_76 ( V_283 ) ;
if ( V_287 )
F_76 ( V_287 ) ;
F_45 ( & V_156 -> V_294 . V_129 ) ;
return V_26 ;
}
static int F_113 ( struct V_10 * V_11 ,
struct V_276 * V_19 ,
struct V_20 * V_209 )
{
if ( F_94 ( V_209 , & V_19 -> V_230 , sizeof( V_19 -> V_230 ) ) )
return - V_28 ;
return 0 ;
}
T_1 F_114 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_114 V_17 ;
struct V_275 V_234 ;
struct V_20 V_209 ;
struct V_20 V_210 ;
T_1 V_339 = sizeof( struct V_340 ) ;
int V_31 ;
if ( V_16 < V_339 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof( V_17 ) ) )
return - V_28 ;
F_11 ( & V_209 , V_14 , ( unsigned long ) V_17 . V_32 , sizeof( V_17 ) ,
V_339 ) ;
F_11 ( & V_210 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + V_339 ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - V_339 ) ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_218 = V_17 . V_218 ;
V_234 . V_133 = V_17 . V_133 ;
V_234 . V_311 = V_17 . V_311 ;
V_234 . V_310 = V_17 . V_310 ;
V_234 . V_307 = V_17 . V_307 ;
V_234 . V_304 = V_17 . V_304 ;
V_234 . V_301 = V_17 . V_301 ;
V_234 . V_322 = V_17 . V_322 ;
V_234 . V_302 = V_17 . V_302 ;
V_234 . V_323 = V_17 . V_323 ;
V_234 . V_317 = V_17 . V_317 ;
V_234 . V_289 = V_17 . V_289 ;
V_234 . V_303 = V_17 . V_303 ;
V_31 = F_107 ( V_11 , & V_209 , & V_210 , & V_234 ,
F_89 ( F_90 ( V_234 ) , V_303 ) +
sizeof( V_17 . V_303 ) , F_113 ,
NULL ) ;
if ( V_31 )
return V_31 ;
return V_15 ;
}
static int F_115 ( struct V_10 * V_11 ,
struct V_276 * V_19 ,
struct V_20 * V_209 )
{
if ( F_94 ( V_209 , V_19 , V_19 -> V_232 ) )
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
if ( V_209 -> V_236 < ( F_89 ( F_90 ( V_17 ) , V_237 ) +
sizeof( V_17 . V_237 ) ) )
return - V_30 ;
V_31 = F_97 ( & V_17 , V_209 , F_98 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_31 )
return V_31 ;
if ( V_17 . V_237 & ~ V_341 )
return - V_30 ;
if ( V_17 . V_238 )
return - V_30 ;
if ( V_209 -> V_239 < ( F_89 ( F_90 ( V_19 ) , V_232 ) +
sizeof( V_19 . V_232 ) ) )
return - V_27 ;
V_31 = F_107 ( V_11 , V_209 , V_210 , & V_17 ,
F_98 ( V_209 -> V_236 , sizeof( V_17 ) ) ,
F_115 , NULL ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
T_1 F_116 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 , int V_16 )
{
struct F_116 V_17 ;
struct V_340 V_19 ;
struct V_20 V_21 ;
struct V_277 * V_156 ;
struct V_139 * V_140 ;
struct V_5 * V_342 ( V_278 ) ;
struct V_284 * V_258 ;
struct V_343 V_62 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
V_156 = (struct V_277 * ) F_41 ( F_3 ( V_258 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_156 ) )
return F_13 ( V_156 ) ;
V_278 = F_2 ( F_3 ( V_140 ) , V_17 . V_133 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_278 ) ) {
V_26 = - V_30 ;
goto V_183;
}
V_140 = (struct V_139 * ) V_278 -> V_132 ;
if ( ! V_140 ) {
V_26 = - V_30 ;
goto V_344;
}
V_62 . V_227 = V_312 ;
V_62 . V_313 = V_11 ;
V_62 . V_257 = V_17 . V_337 ;
V_62 . V_289 = V_17 . V_289 ;
V_156 -> V_294 . V_324 = 0 ;
F_20 ( & V_156 -> V_294 . V_325 ) ;
F_20 ( & V_156 -> V_326 ) ;
V_258 = F_117 ( V_140 , & V_62 ) ;
if ( F_4 ( V_258 ) ) {
V_26 = F_13 ( V_258 ) ;
goto V_344;
}
V_156 -> V_294 . V_129 . V_132 = V_258 ;
V_156 -> V_294 . V_129 . V_218 = V_17 . V_218 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_337 = V_258 -> V_257 ;
V_19 . V_338 = V_156 -> V_294 . V_129 . V_134 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_345;
}
V_156 -> V_293 = F_7 ( V_278 , struct V_155 , V_129 ) ;
F_65 ( & V_156 -> V_293 -> V_169 ) ;
V_258 -> V_129 = & V_156 -> V_294 . V_129 ;
F_6 ( V_278 ) ;
F_43 ( & V_156 -> V_294 . V_129 ) ;
return V_15 ;
V_345:
F_112 ( V_258 ) ;
V_344:
F_6 ( V_278 ) ;
V_183:
F_45 ( & V_156 -> V_294 . V_129 ) ;
return V_26 ;
}
static void F_118 ( struct V_346 * V_347 ,
struct V_348 * V_349 )
{
const struct V_350 * V_351 ;
V_347 -> V_352 = F_119 ( V_349 ) ;
V_347 -> V_263 = F_120 ( V_349 ) ;
V_347 -> V_353 = F_121 ( V_349 ) ;
V_347 -> V_354 = F_122 ( V_349 ) ;
V_347 -> V_355 = ! ! ( F_123 ( V_349 ) &
V_356 ) ;
if ( V_347 -> V_355 ) {
V_351 = F_124 ( V_349 ) ;
memcpy ( V_347 -> V_357 , V_351 -> V_357 . V_358 , 16 ) ;
V_347 -> V_359 = V_351 -> V_359 ;
V_347 -> V_360 = V_351 -> V_360 ;
V_347 -> V_361 = V_351 -> V_361 ;
V_347 -> V_362 = V_351 -> V_362 ;
}
V_347 -> V_104 = F_125 ( V_349 ) ;
}
T_1 F_126 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_126 V_17 ;
struct V_363 V_19 ;
struct V_284 * V_258 ;
struct V_364 * V_62 ;
struct V_285 * V_365 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_62 = F_50 ( sizeof *V_62 , V_148 ) ;
V_365 = F_50 ( sizeof *V_365 , V_148 ) ;
if ( ! V_62 || ! V_365 ) {
V_26 = - V_149 ;
goto V_242;
}
V_258 = F_74 ( V_258 , V_17 . V_338 , V_11 -> V_22 ) ;
if ( ! V_258 ) {
V_26 = - V_30 ;
goto V_242;
}
V_26 = F_127 ( V_258 , V_62 , V_17 . V_366 , V_365 ) ;
F_76 ( V_258 ) ;
if ( V_26 )
goto V_242;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_367 = V_62 -> V_367 ;
V_19 . V_368 = V_62 -> V_368 ;
V_19 . V_369 = V_62 -> V_369 ;
V_19 . V_370 = V_62 -> V_370 ;
V_19 . V_371 = V_62 -> V_371 ;
V_19 . V_372 = V_62 -> V_372 ;
V_19 . V_373 = V_62 -> V_373 ;
V_19 . V_374 = V_62 -> V_374 ;
V_19 . V_375 = V_62 -> V_375 ;
V_19 . V_261 = V_62 -> V_261 ;
V_19 . V_376 = V_62 -> V_376 ;
V_19 . V_377 = V_62 -> V_377 ;
V_19 . V_378 = V_62 -> V_378 ;
V_19 . V_379 = V_62 -> V_379 ;
V_19 . V_380 = V_62 -> V_380 ;
V_19 . V_104 = V_62 -> V_104 ;
V_19 . V_381 = V_62 -> V_381 ;
V_19 . V_382 = V_62 -> V_382 ;
V_19 . V_383 = V_62 -> V_383 ;
V_19 . V_384 = V_62 -> V_384 ;
V_19 . V_385 = V_62 -> V_385 ;
F_118 ( & V_19 . V_243 , & V_62 -> V_386 ) ;
F_118 ( & V_19 . V_387 , & V_62 -> V_388 ) ;
V_19 . V_304 = V_365 -> V_321 . V_304 ;
V_19 . V_301 = V_365 -> V_321 . V_301 ;
V_19 . V_322 = V_365 -> V_321 . V_322 ;
V_19 . V_302 = V_365 -> V_321 . V_302 ;
V_19 . V_323 = V_365 -> V_321 . V_323 ;
V_19 . V_317 = V_365 -> V_316 == V_318 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_242:
F_52 ( V_62 ) ;
F_52 ( V_365 ) ;
return V_26 ? V_26 : V_15 ;
}
static int F_128 ( enum V_389 V_289 , int V_390 )
{
switch ( V_289 ) {
case V_306 :
return V_390 & ~ ( V_391 | V_392 ) ;
case V_305 :
return V_390 & ~ ( V_393 | V_394 |
V_395 ) ;
default:
return V_390 ;
}
}
static void F_129 ( struct V_12 * V_137 ,
struct V_348 * V_349 ,
struct V_346 * V_347 )
{
V_349 -> type = F_130 ( V_137 , V_347 -> V_104 ) ;
if ( V_347 -> V_355 ) {
F_131 ( V_349 , NULL ,
V_347 -> V_359 ,
V_347 -> V_360 ,
V_347 -> V_361 ,
V_347 -> V_362 ) ;
F_132 ( V_349 , V_347 -> V_357 ) ;
} else {
F_133 ( V_349 , 0 ) ;
}
F_134 ( V_349 , V_347 -> V_352 ) ;
F_135 ( V_349 , V_347 -> V_263 ) ;
F_136 ( V_349 , V_347 -> V_353 ) ;
F_137 ( V_349 , V_347 -> V_354 ) ;
F_138 ( V_349 , V_347 -> V_104 ) ;
F_139 ( V_349 , false ) ;
}
static int F_140 ( struct V_10 * V_11 ,
struct V_396 * V_17 , struct V_20 * V_21 )
{
struct V_364 * V_62 ;
struct V_284 * V_258 ;
int V_26 ;
V_62 = F_50 ( sizeof *V_62 , V_148 ) ;
if ( ! V_62 )
return - V_149 ;
V_258 = F_74 ( V_258 , V_17 -> V_230 . V_338 , V_11 -> V_22 ) ;
if ( ! V_258 ) {
V_26 = - V_30 ;
goto V_242;
}
if ( ( V_17 -> V_230 . V_366 & V_397 ) &&
! F_141 ( V_258 -> V_37 , V_17 -> V_230 . V_104 ) ) {
V_26 = - V_30 ;
goto V_398;
}
V_62 -> V_367 = V_17 -> V_230 . V_367 ;
V_62 -> V_368 = V_17 -> V_230 . V_368 ;
V_62 -> V_369 = V_17 -> V_230 . V_369 ;
V_62 -> V_370 = V_17 -> V_230 . V_370 ;
V_62 -> V_371 = V_17 -> V_230 . V_371 ;
V_62 -> V_372 = V_17 -> V_230 . V_372 ;
V_62 -> V_373 = V_17 -> V_230 . V_373 ;
V_62 -> V_374 = V_17 -> V_230 . V_374 ;
V_62 -> V_375 = V_17 -> V_230 . V_375 ;
V_62 -> V_261 = V_17 -> V_230 . V_261 ;
V_62 -> V_376 = V_17 -> V_230 . V_376 ;
V_62 -> V_399 = V_17 -> V_230 . V_399 ;
V_62 -> V_378 = V_17 -> V_230 . V_378 ;
V_62 -> V_379 = V_17 -> V_230 . V_379 ;
V_62 -> V_380 = V_17 -> V_230 . V_380 ;
V_62 -> V_104 = V_17 -> V_230 . V_104 ;
V_62 -> V_381 = V_17 -> V_230 . V_381 ;
V_62 -> V_382 = V_17 -> V_230 . V_382 ;
V_62 -> V_383 = V_17 -> V_230 . V_383 ;
V_62 -> V_384 = V_17 -> V_230 . V_384 ;
V_62 -> V_385 = V_17 -> V_230 . V_385 ;
V_62 -> V_400 = V_17 -> V_400 ;
if ( V_17 -> V_230 . V_366 & V_401 )
F_129 ( V_258 -> V_37 , & V_62 -> V_386 ,
& V_17 -> V_230 . V_243 ) ;
if ( V_17 -> V_230 . V_366 & V_402 )
F_129 ( V_258 -> V_37 , & V_62 -> V_388 ,
& V_17 -> V_230 . V_387 ) ;
V_26 = F_142 ( V_258 , V_62 ,
F_128 ( V_258 -> V_289 ,
V_17 -> V_230 . V_366 ) ,
V_21 ) ;
V_398:
F_76 ( V_258 ) ;
V_242:
F_52 ( V_62 ) ;
return V_26 ;
}
T_1 F_143 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct V_396 V_17 = {} ;
struct V_20 V_21 ;
int V_26 ;
if ( F_9 ( & V_17 . V_230 , V_14 , sizeof( V_17 . V_230 ) ) )
return - V_28 ;
if ( V_17 . V_230 . V_366 &
~ ( ( V_403 << 1 ) - 1 ) )
return - V_300 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 . V_230 ) , NULL ,
V_15 - sizeof( V_17 . V_230 ) - sizeof( struct V_33 ) ,
V_16 ) ;
V_26 = F_140 ( V_11 , & V_17 , & V_21 ) ;
if ( V_26 )
return V_26 ;
return V_15 ;
}
int V_396 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_396 V_17 = {} ;
int V_26 ;
F_144 ( V_404 == ( 1 << 31 ) ) ;
if ( V_209 -> V_236 < sizeof( V_17 . V_230 ) )
return - V_30 ;
V_26 = F_97 ( & V_17 , V_209 , F_98 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_230 . V_366 &
~ ( ( V_404 << 1 ) - 1 ) )
return - V_300 ;
if ( V_209 -> V_236 > sizeof( V_17 ) ) {
if ( F_109 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_300 ;
}
V_26 = F_140 ( V_11 , & V_17 , V_210 ) ;
return V_26 ;
}
T_1 F_145 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_145 V_17 ;
struct V_405 V_19 ;
struct V_5 * V_6 ;
struct V_277 * V_156 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_6 = F_47 ( F_3 ( V_258 ) , V_17 . V_338 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_156 = F_7 ( V_6 , struct V_277 , V_294 . V_129 ) ;
F_5 ( V_6 ) ;
V_26 = F_48 ( V_6 ) ;
if ( V_26 ) {
F_106 ( V_6 ) ;
return V_26 ;
}
V_19 . V_324 = V_156 -> V_294 . V_324 ;
F_106 ( V_6 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
static void * F_146 ( T_3 V_406 , V_255 V_407 )
{
if ( V_407 >= ( V_408 - F_147 ( V_406 , sizeof ( struct V_409 ) ) ) /
sizeof ( struct V_409 ) )
return NULL ;
return F_50 ( F_147 ( V_406 , sizeof ( struct V_409 ) ) +
V_407 * sizeof ( struct V_409 ) , V_148 ) ;
}
T_1 F_148 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_148 V_17 ;
struct V_410 V_19 ;
struct V_411 * V_412 ;
struct V_413 * V_414 = NULL , * V_415 , * V_416 , * V_417 ;
struct V_284 * V_258 ;
int V_418 , V_419 ;
int V_420 ;
T_1 V_26 = - V_30 ;
T_3 V_421 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
if ( V_15 < sizeof V_17 + V_17 . V_422 * V_17 . V_423 +
V_17 . V_424 * sizeof ( struct V_425 ) )
return - V_30 ;
if ( V_17 . V_422 < sizeof ( struct V_411 ) )
return - V_30 ;
V_412 = F_50 ( V_17 . V_422 , V_148 ) ;
if ( ! V_412 )
return - V_149 ;
V_258 = F_74 ( V_258 , V_17 . V_338 , V_11 -> V_22 ) ;
if ( ! V_258 )
goto V_242;
V_420 = V_258 -> V_289 == V_426 ;
V_419 = 0 ;
V_415 = NULL ;
for ( V_418 = 0 ; V_418 < V_17 . V_423 ; ++ V_418 ) {
if ( F_9 ( V_412 ,
V_14 + sizeof V_17 + V_418 * V_17 . V_422 ,
V_17 . V_422 ) ) {
V_26 = - V_28 ;
goto V_270;
}
if ( V_412 -> V_407 + V_419 > V_17 . V_424 ) {
V_26 = - V_30 ;
goto V_270;
}
if ( V_420 ) {
struct V_427 * V_428 ;
if ( V_412 -> V_250 != V_429 &&
V_412 -> V_250 != V_430 ) {
V_26 = - V_30 ;
goto V_270;
}
V_421 = sizeof( * V_428 ) ;
V_428 = F_146 ( V_421 , V_412 -> V_407 ) ;
if ( ! V_428 ) {
V_26 = - V_149 ;
goto V_270;
}
V_428 -> V_431 = F_74 ( V_431 , V_412 -> V_414 . V_428 . V_431 ,
V_11 -> V_22 ) ;
if ( ! V_428 -> V_431 ) {
F_52 ( V_428 ) ;
V_26 = - V_30 ;
goto V_270;
}
V_428 -> V_432 = V_412 -> V_414 . V_428 . V_432 ;
V_428 -> V_433 = V_412 -> V_414 . V_428 . V_433 ;
V_416 = & V_428 -> V_414 ;
} else if ( V_412 -> V_250 == V_434 ||
V_412 -> V_250 == V_435 ||
V_412 -> V_250 == V_436 ) {
struct V_437 * V_438 ;
V_421 = sizeof( * V_438 ) ;
V_438 = F_146 ( V_421 , V_412 -> V_407 ) ;
if ( ! V_438 ) {
V_26 = - V_149 ;
goto V_270;
}
V_438 -> V_439 = V_412 -> V_414 . V_438 . V_439 ;
V_438 -> V_187 = V_412 -> V_414 . V_438 . V_187 ;
V_416 = & V_438 -> V_414 ;
} else if ( V_412 -> V_250 == V_440 ||
V_412 -> V_250 == V_441 ) {
struct V_442 * V_443 ;
V_421 = sizeof( * V_443 ) ;
V_443 = F_146 ( V_421 , V_412 -> V_407 ) ;
if ( ! V_443 ) {
V_26 = - V_149 ;
goto V_270;
}
V_443 -> V_439 = V_412 -> V_414 . V_443 . V_439 ;
V_443 -> V_444 = V_412 -> V_414 . V_443 . V_444 ;
V_443 -> V_445 = V_412 -> V_414 . V_443 . V_445 ;
V_443 -> V_187 = V_412 -> V_414 . V_443 . V_187 ;
V_416 = & V_443 -> V_414 ;
} else if ( V_412 -> V_250 == V_429 ||
V_412 -> V_250 == V_430 ||
V_412 -> V_250 == V_446 ) {
V_421 = sizeof( * V_416 ) ;
V_416 = F_146 ( V_421 , V_412 -> V_407 ) ;
if ( ! V_416 ) {
V_26 = - V_149 ;
goto V_270;
}
} else {
V_26 = - V_30 ;
goto V_270;
}
if ( V_412 -> V_250 == V_430 ||
V_412 -> V_250 == V_434 ) {
V_416 -> V_253 . V_254 =
( V_447 V_256 ) V_412 -> V_253 . V_254 ;
} else if ( V_412 -> V_250 == V_446 ) {
V_416 -> V_253 . V_448 = V_412 -> V_253 . V_448 ;
}
if ( ! V_415 )
V_414 = V_416 ;
else
V_415 -> V_416 = V_416 ;
V_415 = V_416 ;
V_416 -> V_416 = NULL ;
V_416 -> V_248 = V_412 -> V_248 ;
V_416 -> V_407 = V_412 -> V_407 ;
V_416 -> V_250 = V_412 -> V_250 ;
V_416 -> V_449 = V_412 -> V_449 ;
if ( V_416 -> V_407 ) {
V_416 -> V_450 = ( void * ) V_416 +
F_147 ( V_421 , sizeof( struct V_409 ) ) ;
if ( F_9 ( V_416 -> V_450 ,
V_14 + sizeof V_17 +
V_17 . V_423 * V_17 . V_422 +
V_419 * sizeof ( struct V_409 ) ,
V_416 -> V_407 * sizeof ( struct V_409 ) ) ) {
V_26 = - V_28 ;
goto V_270;
}
V_419 += V_416 -> V_407 ;
} else
V_416 -> V_450 = NULL ;
}
V_19 . V_417 = 0 ;
V_26 = V_258 -> V_37 -> V_451 ( V_258 -> V_335 , V_414 , & V_417 ) ;
if ( V_26 )
for ( V_416 = V_414 ; V_416 ; V_416 = V_416 -> V_416 ) {
++ V_19 . V_417 ;
if ( V_416 == V_417 )
break;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_270:
F_76 ( V_258 ) ;
while ( V_414 ) {
if ( V_420 && F_149 ( V_414 ) -> V_431 )
F_76 ( F_149 ( V_414 ) -> V_431 ) ;
V_416 = V_414 -> V_416 ;
F_52 ( V_414 ) ;
V_414 = V_416 ;
}
V_242:
F_52 ( V_412 ) ;
return V_26 ? V_26 : V_15 ;
}
static struct V_452 * F_150 ( const char T_2 * V_14 ,
int V_15 ,
T_5 V_423 ,
T_5 V_424 ,
T_5 V_422 )
{
struct V_453 * V_412 ;
struct V_452 * V_414 = NULL , * V_415 , * V_416 ;
int V_419 ;
int V_418 ;
int V_26 ;
if ( V_15 < V_422 * V_423 +
V_424 * sizeof ( struct V_425 ) )
return F_88 ( - V_30 ) ;
if ( V_422 < sizeof ( struct V_453 ) )
return F_88 ( - V_30 ) ;
V_412 = F_50 ( V_422 , V_148 ) ;
if ( ! V_412 )
return F_88 ( - V_149 ) ;
V_419 = 0 ;
V_415 = NULL ;
for ( V_418 = 0 ; V_418 < V_423 ; ++ V_418 ) {
if ( F_9 ( V_412 , V_14 + V_418 * V_422 ,
V_422 ) ) {
V_26 = - V_28 ;
goto V_31;
}
if ( V_412 -> V_407 + V_419 > V_424 ) {
V_26 = - V_30 ;
goto V_31;
}
if ( V_412 -> V_407 >=
( V_408 - F_147 ( sizeof *V_416 , sizeof ( struct V_409 ) ) ) /
sizeof ( struct V_409 ) ) {
V_26 = - V_30 ;
goto V_31;
}
V_416 = F_50 ( F_147 ( sizeof *V_416 , sizeof ( struct V_409 ) ) +
V_412 -> V_407 * sizeof ( struct V_409 ) ,
V_148 ) ;
if ( ! V_416 ) {
V_26 = - V_149 ;
goto V_31;
}
if ( ! V_415 )
V_414 = V_416 ;
else
V_415 -> V_416 = V_416 ;
V_415 = V_416 ;
V_416 -> V_416 = NULL ;
V_416 -> V_248 = V_412 -> V_248 ;
V_416 -> V_407 = V_412 -> V_407 ;
if ( V_416 -> V_407 ) {
V_416 -> V_450 = ( void * ) V_416 +
F_147 ( sizeof *V_416 , sizeof ( struct V_409 ) ) ;
if ( F_9 ( V_416 -> V_450 ,
V_14 + V_423 * V_422 +
V_419 * sizeof ( struct V_409 ) ,
V_416 -> V_407 * sizeof ( struct V_409 ) ) ) {
V_26 = - V_28 ;
goto V_31;
}
V_419 += V_416 -> V_407 ;
} else
V_416 -> V_450 = NULL ;
}
F_52 ( V_412 ) ;
return V_414 ;
V_31:
F_52 ( V_412 ) ;
while ( V_414 ) {
V_416 = V_414 -> V_416 ;
F_52 ( V_414 ) ;
V_414 = V_416 ;
}
return F_88 ( V_26 ) ;
}
T_1 F_151 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_151 V_17 ;
struct V_454 V_19 ;
struct V_452 * V_414 , * V_416 , * V_417 ;
struct V_284 * V_258 ;
T_1 V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_414 = F_150 ( V_14 + sizeof V_17 ,
V_15 - sizeof V_17 , V_17 . V_423 ,
V_17 . V_424 , V_17 . V_422 ) ;
if ( F_4 ( V_414 ) )
return F_13 ( V_414 ) ;
V_258 = F_74 ( V_258 , V_17 . V_338 , V_11 -> V_22 ) ;
if ( ! V_258 )
goto V_242;
V_19 . V_417 = 0 ;
V_26 = V_258 -> V_37 -> V_455 ( V_258 -> V_335 , V_414 , & V_417 ) ;
F_76 ( V_258 ) ;
if ( V_26 ) {
for ( V_416 = V_414 ; V_416 ; V_416 = V_416 -> V_416 ) {
++ V_19 . V_417 ;
if ( V_416 == V_417 )
break;
}
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_242:
while ( V_414 ) {
V_416 = V_414 -> V_416 ;
F_52 ( V_414 ) ;
V_414 = V_416 ;
}
return V_26 ? V_26 : V_15 ;
}
T_1 F_152 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_152 V_17 ;
struct V_456 V_19 ;
struct V_452 * V_414 , * V_416 , * V_417 ;
struct V_282 * V_283 ;
T_1 V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_414 = F_150 ( V_14 + sizeof V_17 ,
V_15 - sizeof V_17 , V_17 . V_423 ,
V_17 . V_424 , V_17 . V_422 ) ;
if ( F_4 ( V_414 ) )
return F_13 ( V_414 ) ;
V_283 = F_74 ( V_283 , V_17 . V_307 , V_11 -> V_22 ) ;
if ( ! V_283 )
goto V_242;
V_19 . V_417 = 0 ;
V_26 = V_283 -> V_37 -> V_457 ( V_283 , V_414 , & V_417 ) ;
F_76 ( V_283 ) ;
if ( V_26 )
for ( V_416 = V_414 ; V_416 ; V_416 = V_416 -> V_416 ) {
++ V_19 . V_417 ;
if ( V_416 == V_417 )
break;
}
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
V_26 = - V_28 ;
V_242:
while ( V_414 ) {
V_416 = V_414 -> V_416 ;
F_52 ( V_414 ) ;
V_414 = V_416 ;
}
return V_26 ? V_26 : V_15 ;
}
T_1 F_153 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_153 V_17 ;
struct V_458 V_19 ;
struct V_5 * V_6 ;
struct V_126 * V_127 ;
struct V_459 * V_431 ;
struct V_348 V_62 ;
int V_26 ;
struct V_20 V_21 ;
T_4 * V_460 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
if ( ! F_141 ( V_13 , V_17 . V_62 . V_104 ) )
return - V_30 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
V_6 = F_41 ( F_3 ( V_431 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_127 = F_74 ( V_127 , V_17 . V_133 , V_11 -> V_22 ) ;
if ( ! V_127 ) {
V_26 = - V_30 ;
goto V_31;
}
V_62 . type = F_130 ( V_13 , V_17 . V_62 . V_104 ) ;
F_139 ( & V_62 , false ) ;
F_134 ( & V_62 , V_17 . V_62 . V_352 ) ;
F_135 ( & V_62 , V_17 . V_62 . V_263 ) ;
F_136 ( & V_62 , V_17 . V_62 . V_353 ) ;
F_137 ( & V_62 , V_17 . V_62 . V_354 ) ;
F_138 ( & V_62 , V_17 . V_62 . V_104 ) ;
if ( V_17 . V_62 . V_355 ) {
F_131 ( & V_62 , NULL , V_17 . V_62 . V_351 . V_359 ,
V_17 . V_62 . V_351 . V_360 ,
V_17 . V_62 . V_351 . V_361 ,
V_17 . V_62 . V_351 . V_362 ) ;
F_132 ( & V_62 , V_17 . V_62 . V_351 . V_357 ) ;
} else {
F_133 ( & V_62 , 0 ) ;
}
V_460 = F_154 ( & V_62 ) ;
if ( V_460 )
memset ( V_460 , 0 , V_461 ) ;
V_431 = V_127 -> V_37 -> V_462 ( V_127 , & V_62 , & V_21 ) ;
if ( F_4 ( V_431 ) ) {
V_26 = F_13 ( V_431 ) ;
goto V_183;
}
V_431 -> V_37 = V_127 -> V_37 ;
V_431 -> V_127 = V_127 ;
F_65 ( & V_127 -> V_131 ) ;
V_431 -> V_129 = V_6 ;
V_6 -> V_218 = V_17 . V_218 ;
V_6 -> V_132 = V_431 ;
V_19 . V_463 = V_6 -> V_134 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_135;
}
F_76 ( V_127 ) ;
F_43 ( V_6 ) ;
return V_15 ;
V_135:
F_155 ( V_431 ) ;
V_183:
F_76 ( V_127 ) ;
V_31:
F_45 ( V_6 ) ;
return V_26 ;
}
T_1 F_156 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 , int V_16 )
{
struct F_156 V_17 ;
struct V_5 * V_6 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_47 ( F_3 ( V_431 ) , V_17 . V_463 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_48 ( V_6 ) ;
return V_26 ? : V_15 ;
}
T_1 F_157 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_157 V_17 ;
struct V_284 * V_258 ;
struct V_277 * V_156 ;
struct V_464 * V_465 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_258 = F_74 ( V_258 , V_17 . V_338 , V_11 -> V_22 ) ;
if ( ! V_258 )
return - V_30 ;
V_156 = F_7 ( V_258 -> V_129 , struct V_277 , V_294 . V_129 ) ;
F_10 ( & V_156 -> V_295 ) ;
F_158 (mcast, &obj->mcast_list, list)
if ( V_17 . V_466 == V_465 -> V_114 &&
! memcmp ( V_17 . V_467 , V_465 -> V_467 . V_358 , sizeof V_465 -> V_467 . V_358 ) ) {
V_26 = 0 ;
goto V_270;
}
V_465 = F_50 ( sizeof *V_465 , V_148 ) ;
if ( ! V_465 ) {
V_26 = - V_149 ;
goto V_270;
}
V_465 -> V_114 = V_17 . V_466 ;
memcpy ( V_465 -> V_467 . V_358 , V_17 . V_467 , sizeof V_465 -> V_467 . V_358 ) ;
V_26 = F_159 ( V_258 , & V_465 -> V_467 , V_17 . V_466 ) ;
if ( ! V_26 )
F_160 ( & V_465 -> V_468 , & V_156 -> V_326 ) ;
else
F_52 ( V_465 ) ;
V_270:
F_25 ( & V_156 -> V_295 ) ;
F_76 ( V_258 ) ;
return V_26 ? V_26 : V_15 ;
}
T_1 F_161 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_161 V_17 ;
struct V_277 * V_156 ;
struct V_284 * V_258 ;
struct V_464 * V_465 ;
int V_26 = - V_30 ;
bool V_469 = false ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_258 = F_74 ( V_258 , V_17 . V_338 , V_11 -> V_22 ) ;
if ( ! V_258 )
return - V_30 ;
V_156 = F_7 ( V_258 -> V_129 , struct V_277 , V_294 . V_129 ) ;
F_10 ( & V_156 -> V_295 ) ;
F_158 (mcast, &obj->mcast_list, list)
if ( V_17 . V_466 == V_465 -> V_114 &&
! memcmp ( V_17 . V_467 , V_465 -> V_467 . V_358 , sizeof V_465 -> V_467 . V_358 ) ) {
F_162 ( & V_465 -> V_468 ) ;
F_52 ( V_465 ) ;
V_469 = true ;
break;
}
if ( ! V_469 ) {
V_26 = - V_30 ;
goto V_270;
}
V_26 = F_163 ( V_258 , (union V_470 * ) V_17 . V_467 , V_17 . V_466 ) ;
V_270:
F_25 ( & V_156 -> V_295 ) ;
F_76 ( V_258 ) ;
return V_26 ? V_26 : V_15 ;
}
static int F_164 ( struct V_471 * V_472 ,
union V_473 * V_474 )
{
V_474 -> type = V_472 -> type ;
switch ( V_474 -> type ) {
case V_475 :
if ( V_472 -> V_476 . V_477 !=
sizeof( struct V_478 ) )
return - V_30 ;
V_474 -> V_476 . V_477 = sizeof( struct V_479 ) ;
V_474 -> V_476 . V_480 = V_472 -> V_476 . V_480 ;
break;
case V_481 :
if ( V_472 -> V_482 . V_477 !=
sizeof( struct V_483 ) )
return - V_30 ;
V_474 -> V_482 . V_477 = sizeof( struct V_484 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static T_3 F_165 ( struct V_485 * V_486 )
{
return ( V_486 -> V_477 - sizeof( struct V_485 ) ) / 2 ;
}
static T_1 F_166 ( void * V_487 , T_6 V_488 ,
T_6 V_489 )
{
if ( V_488 > V_489 ) {
if ( F_167 ( V_487 +
V_489 , 0 ,
V_488 - V_489 ) )
return - V_30 ;
return V_489 ;
}
return V_488 ;
}
static int F_168 ( struct V_471 * V_472 ,
union V_473 * V_474 )
{
T_1 V_490 ;
T_1 V_491 ;
T_1 V_492 ;
void * V_493 ;
void * V_494 ;
if ( V_472 -> V_238 )
return - V_30 ;
V_474 -> type = V_472 -> type ;
V_491 = F_165 ( & V_472 -> V_495 ) ;
if ( V_491 != F_147 ( V_491 , 4 ) )
return - V_30 ;
V_494 = ( void * ) V_472 +
sizeof( struct V_485 ) ;
V_493 = V_494 + V_491 ;
if ( V_474 -> type == ( V_496 | V_497 ) )
return - V_30 ;
switch ( V_474 -> type & ~ V_496 ) {
case V_498 :
V_492 = F_89 ( struct V_499 , V_500 ) ;
V_490 = F_166 ( V_493 ,
V_491 ,
V_492 ) ;
if ( V_490 <= 0 )
return - V_30 ;
V_474 -> V_477 = sizeof( struct V_501 ) ;
memcpy ( & V_474 -> V_502 . V_503 , V_494 , V_490 ) ;
memcpy ( & V_474 -> V_502 . V_390 , V_493 , V_490 ) ;
break;
case V_504 :
V_492 = F_89 ( struct V_505 , V_500 ) ;
V_490 = F_166 ( V_493 ,
V_491 ,
V_492 ) ;
if ( V_490 <= 0 )
return - V_30 ;
V_474 -> V_477 = sizeof( struct V_506 ) ;
memcpy ( & V_474 -> V_507 . V_503 , V_494 , V_490 ) ;
memcpy ( & V_474 -> V_507 . V_390 , V_493 , V_490 ) ;
break;
case V_508 :
V_492 = F_89 ( struct V_509 , V_500 ) ;
V_490 = F_166 ( V_493 ,
V_491 ,
V_492 ) ;
if ( V_490 <= 0 )
return - V_30 ;
V_474 -> V_477 = sizeof( struct V_510 ) ;
memcpy ( & V_474 -> V_511 . V_503 , V_494 , V_490 ) ;
memcpy ( & V_474 -> V_511 . V_390 , V_493 , V_490 ) ;
if ( ( F_169 ( V_474 -> V_511 . V_390 . V_359 ) ) >= F_170 ( 20 ) ||
( F_169 ( V_474 -> V_511 . V_503 . V_359 ) ) >= F_170 ( 20 ) )
return - V_30 ;
break;
case V_512 :
case V_513 :
V_492 = F_89 ( struct V_514 , V_500 ) ;
V_490 = F_166 ( V_493 ,
V_491 ,
V_492 ) ;
if ( V_490 <= 0 )
return - V_30 ;
V_474 -> V_477 = sizeof( struct V_515 ) ;
memcpy ( & V_474 -> V_516 . V_503 , V_494 , V_490 ) ;
memcpy ( & V_474 -> V_516 . V_390 , V_493 , V_490 ) ;
break;
case V_497 :
V_492 = F_89 ( struct V_517 , V_500 ) ;
V_490 = F_166 ( V_493 ,
V_491 ,
V_492 ) ;
if ( V_490 <= 0 )
return - V_30 ;
V_474 -> V_518 . V_477 = sizeof( struct V_519 ) ;
memcpy ( & V_474 -> V_518 . V_503 , V_494 , V_490 ) ;
memcpy ( & V_474 -> V_518 . V_390 , V_493 , V_490 ) ;
if ( ( F_169 ( V_474 -> V_518 . V_390 . V_520 ) ) >= F_170 ( 24 ) ||
( F_169 ( V_474 -> V_518 . V_503 . V_520 ) ) >= F_170 ( 24 ) )
return - V_30 ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_171 ( struct V_471 * V_472 ,
union V_473 * V_474 )
{
if ( V_472 -> V_238 )
return - V_30 ;
if ( V_472 -> type >= V_475 )
return F_164 ( V_472 , V_474 ) ;
else
return F_168 ( V_472 , V_474 ) ;
}
int F_172 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_172 V_17 = {} ;
struct V_521 V_19 = {} ;
struct V_522 * V_156 ;
int V_31 = 0 ;
struct V_214 * V_215 ;
struct V_126 * V_127 ;
struct V_523 * V_524 ;
struct V_525 V_526 = {} ;
T_3 V_527 ;
T_3 V_528 ;
V_527 = F_89 ( F_90 ( V_17 ) , V_73 ) + sizeof( V_17 . V_73 ) ;
V_528 = F_89 ( F_90 ( V_19 ) , V_529 ) + sizeof( V_19 . V_529 ) ;
if ( V_209 -> V_236 < V_527 )
return - V_30 ;
if ( V_209 -> V_239 < V_528 )
return - V_27 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_109 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_300 ;
V_31 = F_97 ( & V_17 , V_209 , F_98 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_31 )
return V_31 ;
if ( V_17 . V_237 )
return - V_300 ;
V_156 = (struct V_522 * ) F_41 ( F_3 ( V_524 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_156 ) )
return F_13 ( V_156 ) ;
V_127 = F_74 ( V_127 , V_17 . V_133 , V_11 -> V_22 ) ;
if ( ! V_127 ) {
V_31 = - V_30 ;
goto V_530;
}
V_215 = F_74 ( V_215 , V_17 . V_231 , V_11 -> V_22 ) ;
if ( ! V_215 ) {
V_31 = - V_30 ;
goto V_531;
}
V_526 . V_215 = V_215 ;
V_526 . V_73 = V_17 . V_73 ;
V_526 . V_532 = V_17 . V_532 ;
V_526 . V_533 = V_11 ;
V_526 . V_534 = V_17 . V_534 ;
V_526 . V_227 = V_535 ;
if ( V_209 -> V_236 >= ( F_89 ( F_90 ( V_17 ) , V_320 ) +
sizeof( V_17 . V_320 ) ) )
V_526 . V_320 = V_17 . V_320 ;
V_156 -> V_294 . V_324 = 0 ;
F_20 ( & V_156 -> V_294 . V_325 ) ;
V_524 = V_127 -> V_37 -> V_536 ( V_127 , & V_526 , V_210 ) ;
if ( F_4 ( V_524 ) ) {
V_31 = F_13 ( V_524 ) ;
goto V_537;
}
V_524 -> V_129 = & V_156 -> V_294 . V_129 ;
V_156 -> V_294 . V_129 . V_132 = V_524 ;
V_524 -> V_534 = V_526 . V_534 ;
V_524 -> V_215 = V_215 ;
V_524 -> V_127 = V_127 ;
V_524 -> V_37 = V_127 -> V_37 ;
V_524 -> V_533 = V_526 . V_533 ;
F_42 ( & V_524 -> V_131 , 0 ) ;
F_65 ( & V_127 -> V_131 ) ;
F_65 ( & V_215 -> V_131 ) ;
V_524 -> V_129 = & V_156 -> V_294 . V_129 ;
V_156 -> V_294 . V_129 . V_132 = V_524 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_538 = V_156 -> V_294 . V_129 . V_134 ;
V_19 . V_73 = V_526 . V_73 ;
V_19 . V_532 = V_526 . V_532 ;
V_19 . V_529 = V_524 -> V_539 ;
V_19 . V_232 = V_528 ;
V_31 = F_94 ( V_209 ,
& V_19 , V_19 . V_232 ) ;
if ( V_31 )
goto V_135;
F_76 ( V_127 ) ;
F_76 ( V_215 ) ;
F_43 ( & V_156 -> V_294 . V_129 ) ;
return 0 ;
V_135:
F_173 ( V_524 ) ;
V_537:
F_76 ( V_215 ) ;
V_531:
F_76 ( V_127 ) ;
V_530:
F_45 ( & V_156 -> V_294 . V_129 ) ;
return V_31 ;
}
int F_174 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_174 V_17 = {} ;
struct V_540 V_19 = {} ;
struct V_5 * V_6 ;
struct V_522 * V_156 ;
T_3 V_527 ;
T_3 V_528 ;
int V_26 ;
V_527 = F_89 ( F_90 ( V_17 ) , V_538 ) + sizeof( V_17 . V_538 ) ;
V_528 = F_89 ( F_90 ( V_19 ) , V_238 ) + sizeof( V_19 . V_238 ) ;
if ( V_209 -> V_236 < V_527 )
return - V_30 ;
if ( V_209 -> V_239 < V_528 )
return - V_27 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_109 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_300 ;
V_26 = F_97 ( & V_17 , V_209 , F_98 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_237 )
return - V_300 ;
V_19 . V_232 = V_528 ;
V_6 = F_47 ( F_3 ( V_524 ) , V_17 . V_538 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_156 = F_7 ( V_6 , struct V_522 , V_294 . V_129 ) ;
F_5 ( V_6 ) ;
V_26 = F_48 ( V_6 ) ;
V_19 . V_324 = V_156 -> V_294 . V_324 ;
F_106 ( V_6 ) ;
if ( V_26 )
return V_26 ;
return F_94 ( V_209 , & V_19 , V_19 . V_232 ) ;
}
int F_175 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_175 V_17 = {} ;
struct V_523 * V_524 ;
struct V_541 V_542 = {} ;
T_3 V_527 ;
int V_26 ;
V_527 = F_89 ( F_90 ( V_17 ) , V_543 ) + sizeof( V_17 . V_543 ) ;
if ( V_209 -> V_236 < V_527 )
return - V_30 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_109 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_300 ;
V_26 = F_97 ( & V_17 , V_209 , F_98 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( ! V_17 . V_366 )
return - V_30 ;
if ( V_17 . V_366 > ( V_544 | V_545 | V_546 ) )
return - V_30 ;
V_524 = F_74 ( V_524 , V_17 . V_538 , V_11 -> V_22 ) ;
if ( ! V_524 )
return - V_30 ;
V_542 . V_543 = V_17 . V_543 ;
V_542 . V_547 = V_17 . V_547 ;
if ( V_17 . V_366 & V_546 ) {
V_542 . V_191 = V_17 . V_191 ;
V_542 . V_548 = V_17 . V_548 ;
}
V_26 = V_524 -> V_37 -> V_549 ( V_524 , & V_542 , V_17 . V_366 , V_210 ) ;
F_76 ( V_524 ) ;
return V_26 ;
}
int F_176 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_176 V_17 = {} ;
struct V_550 V_19 = {} ;
struct V_5 * V_6 ;
int V_31 = 0 ;
struct V_551 V_365 = {} ;
struct V_286 * V_299 ;
struct V_523 * * V_552 = NULL ;
T_5 * V_553 = NULL ;
struct V_523 * V_524 = NULL ;
int V_418 , V_554 , V_555 ;
T_5 V_556 ;
T_5 V_557 ;
T_3 V_558 ;
T_3 V_528 ;
V_558 = F_89 ( F_90 ( V_17 ) , V_559 ) + sizeof( V_17 . V_559 ) ;
V_528 = F_89 ( F_90 ( V_19 ) , V_560 ) + sizeof( V_19 . V_560 ) ;
if ( V_209 -> V_236 < V_558 )
return - V_30 ;
if ( V_209 -> V_239 < V_528 )
return - V_27 ;
V_31 = F_97 ( & V_17 , V_209 , V_558 ) ;
if ( V_31 )
return V_31 ;
V_209 -> V_561 += V_558 ;
V_209 -> V_236 -= V_558 ;
if ( V_17 . V_237 )
return - V_300 ;
if ( V_17 . V_559 > V_562 )
return - V_30 ;
V_556 = 1 << V_17 . V_559 ;
V_557 = V_556 * sizeof( V_255 ) ;
if ( V_556 == 1 )
V_557 += sizeof( V_255 ) ;
if ( V_209 -> V_236 < V_557 )
return - V_30 ;
if ( V_209 -> V_236 > V_557 &&
! F_109 ( V_209 , V_557 ,
V_209 -> V_236 - V_557 ) )
return - V_300 ;
V_553 = F_177 ( V_556 , sizeof( * V_553 ) ,
V_148 ) ;
if ( ! V_553 )
return - V_149 ;
V_31 = F_97 ( V_553 , V_209 ,
V_556 * sizeof( V_255 ) ) ;
if ( V_31 )
goto V_55;
V_552 = F_177 ( V_556 , sizeof( * V_552 ) , V_148 ) ;
if ( ! V_552 ) {
V_31 = - V_149 ;
goto V_55;
}
for ( V_555 = 0 ; V_555 < V_556 ;
V_555 ++ ) {
V_524 = F_74 ( V_524 , V_553 [ V_555 ] ,
V_11 -> V_22 ) ;
if ( ! V_524 ) {
V_31 = - V_30 ;
goto V_563;
}
V_552 [ V_555 ] = V_524 ;
}
V_6 = F_41 ( F_3 ( V_298 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) ) {
V_31 = F_13 ( V_6 ) ;
goto V_563;
}
V_365 . V_559 = V_17 . V_559 ;
V_365 . V_287 = V_552 ;
V_299 = V_13 -> V_564 ( V_13 , & V_365 , V_210 ) ;
if ( F_4 ( V_299 ) ) {
V_31 = F_13 ( V_299 ) ;
goto V_530;
}
V_299 -> V_287 = V_552 ;
V_299 -> V_559 = V_365 . V_559 ;
V_299 -> V_129 = V_6 ;
V_6 -> V_132 = V_299 ;
V_299 -> V_37 = V_13 ;
F_42 ( & V_299 -> V_131 , 0 ) ;
for ( V_418 = 0 ; V_418 < V_556 ; V_418 ++ )
F_65 ( & V_552 [ V_418 ] -> V_131 ) ;
V_19 . V_565 = V_6 -> V_134 ;
V_19 . V_560 = V_299 -> V_560 ;
V_19 . V_232 = V_528 ;
V_31 = F_94 ( V_209 ,
& V_19 , V_19 . V_232 ) ;
if ( V_31 )
goto V_135;
F_52 ( V_553 ) ;
for ( V_554 = 0 ; V_554 < V_555 ; V_554 ++ )
F_76 ( V_552 [ V_554 ] ) ;
F_43 ( V_6 ) ;
return 0 ;
V_135:
F_178 ( V_299 ) ;
V_530:
F_45 ( V_6 ) ;
V_563:
for ( V_554 = 0 ; V_554 < V_555 ; V_554 ++ )
F_76 ( V_552 [ V_554 ] ) ;
V_55:
F_52 ( V_553 ) ;
F_52 ( V_552 ) ;
return V_31 ;
}
int F_179 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct F_179 V_17 = {} ;
struct V_5 * V_6 ;
int V_26 ;
T_3 V_527 ;
V_527 = F_89 ( F_90 ( V_17 ) , V_565 ) + sizeof( V_17 . V_565 ) ;
if ( V_209 -> V_236 < V_527 )
return - V_30 ;
if ( V_209 -> V_236 > sizeof( V_17 ) &&
! F_109 ( V_209 , sizeof( V_17 ) ,
V_209 -> V_236 - sizeof( V_17 ) ) )
return - V_300 ;
V_26 = F_97 ( & V_17 , V_209 , F_98 ( sizeof( V_17 ) , V_209 -> V_236 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_237 )
return - V_300 ;
V_6 = F_47 ( F_3 ( V_298 ) , V_17 . V_565 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
return F_48 ( V_6 ) ;
}
int F_180 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_566 V_17 ;
struct V_567 V_19 ;
struct V_5 * V_6 ;
struct V_568 * V_569 ;
struct V_570 * V_571 ;
struct V_572 * V_573 ;
struct V_284 * V_258 ;
int V_31 = 0 ;
void * V_472 ;
void * V_474 ;
int V_418 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
if ( V_209 -> V_239 < sizeof( V_19 ) )
return - V_27 ;
V_31 = F_97 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_31 )
return V_31 ;
V_209 -> V_561 += sizeof( V_17 ) ;
V_209 -> V_236 -= sizeof( V_17 ) ;
if ( V_17 . V_237 )
return - V_30 ;
if ( ! F_108 ( V_291 ) )
return - V_292 ;
if ( V_17 . V_573 . V_191 >= V_574 )
return - V_30 ;
if ( ( V_17 . V_573 . V_191 & V_575 ) &&
( ( V_17 . V_573 . type == V_576 ) ||
( V_17 . V_573 . type == V_577 ) ) )
return - V_30 ;
if ( V_17 . V_573 . V_578 > V_579 )
return - V_30 ;
if ( V_17 . V_573 . V_477 > V_209 -> V_236 ||
V_17 . V_573 . V_477 >
( V_17 . V_573 . V_578 * sizeof( struct V_471 ) ) )
return - V_30 ;
if ( V_17 . V_573 . V_238 [ 0 ] ||
V_17 . V_573 . V_238 [ 1 ] )
return - V_30 ;
if ( V_17 . V_573 . V_578 ) {
V_571 = F_50 ( sizeof( * V_571 ) + V_17 . V_573 . V_477 ,
V_148 ) ;
if ( ! V_571 )
return - V_149 ;
memcpy ( V_571 , & V_17 . V_573 , sizeof( * V_571 ) ) ;
V_31 = F_97 ( V_571 + 1 , V_209 ,
V_17 . V_573 . V_477 ) ;
if ( V_31 )
goto V_580;
} else {
V_571 = & V_17 . V_573 ;
}
V_6 = F_41 ( F_3 ( V_581 ) , V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) ) {
V_31 = F_13 ( V_6 ) ;
goto V_580;
}
V_258 = F_74 ( V_258 , V_17 . V_338 , V_11 -> V_22 ) ;
if ( ! V_258 ) {
V_31 = - V_30 ;
goto V_530;
}
V_573 = F_181 ( sizeof( * V_573 ) + V_17 . V_573 . V_578 *
sizeof( union V_473 ) , V_148 ) ;
if ( ! V_573 ) {
V_31 = - V_149 ;
goto V_183;
}
V_573 -> type = V_571 -> type ;
V_573 -> V_582 = V_571 -> V_582 ;
V_573 -> V_578 = V_571 -> V_578 ;
V_573 -> V_336 = V_571 -> V_336 ;
V_573 -> V_191 = V_571 -> V_191 ;
V_573 -> V_477 = sizeof( * V_573 ) ;
V_472 = V_571 + 1 ;
V_474 = V_573 + 1 ;
for ( V_418 = 0 ; V_418 < V_573 -> V_578 &&
V_17 . V_573 . V_477 > F_89 ( struct V_471 , V_238 ) &&
V_17 . V_573 . V_477 >=
( (struct V_471 * ) V_472 ) -> V_477 ; V_418 ++ ) {
V_31 = F_171 ( V_472 , V_474 ) ;
if ( V_31 )
goto V_55;
V_573 -> V_477 +=
( (union V_473 * ) V_474 ) -> V_477 ;
V_17 . V_573 . V_477 -= ( (struct V_471 * ) V_472 ) -> V_477 ;
V_472 += ( (struct V_471 * ) V_472 ) -> V_477 ;
V_474 += ( (union V_473 * ) V_474 ) -> V_477 ;
}
if ( V_17 . V_573 . V_477 || ( V_418 != V_573 -> V_578 ) ) {
F_182 ( L_2 ,
V_418 , V_17 . V_573 . V_477 ) ;
V_31 = - V_30 ;
goto V_55;
}
V_569 = F_183 ( V_258 , V_573 , V_583 ) ;
if ( F_4 ( V_569 ) ) {
V_31 = F_13 ( V_569 ) ;
goto V_55;
}
V_569 -> V_129 = V_6 ;
V_6 -> V_132 = V_569 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_584 = V_6 -> V_134 ;
V_31 = F_94 ( V_209 ,
& V_19 , sizeof( V_19 ) ) ;
if ( V_31 )
goto V_135;
F_76 ( V_258 ) ;
F_43 ( V_6 ) ;
F_52 ( V_573 ) ;
if ( V_17 . V_573 . V_578 )
F_52 ( V_571 ) ;
return 0 ;
V_135:
F_184 ( V_569 ) ;
V_55:
F_52 ( V_573 ) ;
V_183:
F_76 ( V_258 ) ;
V_530:
F_45 ( V_6 ) ;
V_580:
if ( V_17 . V_573 . V_578 )
F_52 ( V_571 ) ;
return V_31 ;
}
int F_185 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_585 V_17 ;
struct V_5 * V_6 ;
int V_26 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
V_26 = F_97 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_26 )
return V_26 ;
if ( V_17 . V_237 )
return - V_30 ;
V_6 = F_47 ( F_3 ( V_581 ) , V_17 . V_584 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_26 = F_48 ( V_6 ) ;
return V_26 ;
}
static int F_186 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_586 * V_17 ,
struct V_20 * V_21 )
{
struct V_587 V_19 ;
struct V_588 * V_156 ;
struct V_126 * V_127 ;
struct V_282 * V_283 ;
struct V_5 * V_342 ( V_278 ) ;
struct V_589 V_62 ;
int V_26 ;
V_156 = (struct V_588 * ) F_41 ( F_3 ( V_283 ) ,
V_11 -> V_22 ) ;
if ( F_4 ( V_156 ) )
return F_13 ( V_156 ) ;
if ( V_17 -> V_308 == V_590 )
V_62 . V_591 . V_592 . V_593 = V_17 -> V_593 ;
if ( V_17 -> V_308 == V_309 ) {
V_278 = F_2 ( F_3 ( V_140 ) , V_17 -> V_170 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_278 ) ) {
V_26 = - V_30 ;
goto V_31;
}
V_62 . V_591 . V_594 . V_140 = (struct V_139 * ) V_278 -> V_132 ;
if ( ! V_62 . V_591 . V_594 . V_140 ) {
V_26 = - V_30 ;
goto V_595;
}
V_156 -> V_293 = F_7 ( V_278 , struct V_155 , V_129 ) ;
F_65 ( & V_156 -> V_293 -> V_169 ) ;
}
if ( F_187 ( V_17 -> V_308 ) ) {
V_62 . V_591 . V_215 = F_74 ( V_215 , V_17 -> V_231 ,
V_11 -> V_22 ) ;
if ( ! V_62 . V_591 . V_215 ) {
V_26 = - V_30 ;
goto V_595;
}
}
V_127 = F_74 ( V_127 , V_17 -> V_133 , V_11 -> V_22 ) ;
if ( ! V_127 ) {
V_26 = - V_30 ;
goto V_537;
}
V_62 . V_227 = V_596 ;
V_62 . V_597 = V_11 ;
V_62 . V_308 = V_17 -> V_308 ;
V_62 . V_62 . V_532 = V_17 -> V_532 ;
V_62 . V_62 . V_73 = V_17 -> V_73 ;
V_62 . V_62 . V_598 = V_17 -> V_598 ;
V_156 -> V_294 . V_324 = 0 ;
F_20 ( & V_156 -> V_294 . V_325 ) ;
V_283 = V_127 -> V_37 -> V_599 ( V_127 , & V_62 , V_21 ) ;
if ( F_4 ( V_283 ) ) {
V_26 = F_13 ( V_283 ) ;
goto V_183;
}
V_283 -> V_37 = V_127 -> V_37 ;
V_283 -> V_127 = V_127 ;
V_283 -> V_308 = V_17 -> V_308 ;
V_283 -> V_129 = & V_156 -> V_294 . V_129 ;
V_283 -> V_227 = V_62 . V_227 ;
V_283 -> V_597 = V_62 . V_597 ;
if ( F_187 ( V_17 -> V_308 ) ) {
V_283 -> V_591 . V_215 = V_62 . V_591 . V_215 ;
F_65 ( & V_62 . V_591 . V_215 -> V_131 ) ;
}
if ( V_17 -> V_308 == V_309 ) {
V_283 -> V_591 . V_594 . V_140 = V_62 . V_591 . V_594 . V_140 ;
F_65 ( & V_62 . V_591 . V_594 . V_140 -> V_131 ) ;
}
F_65 ( & V_127 -> V_131 ) ;
F_42 ( & V_283 -> V_131 , 0 ) ;
V_156 -> V_294 . V_129 . V_132 = V_283 ;
V_156 -> V_294 . V_129 . V_218 = V_17 -> V_218 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_307 = V_156 -> V_294 . V_129 . V_134 ;
V_19 . V_532 = V_62 . V_62 . V_532 ;
V_19 . V_73 = V_62 . V_62 . V_73 ;
if ( V_17 -> V_308 == V_309 )
V_19 . V_600 = V_283 -> V_591 . V_594 . V_601 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 -> V_32 ,
& V_19 , sizeof V_19 ) ) {
V_26 = - V_28 ;
goto V_135;
}
if ( V_17 -> V_308 == V_309 )
F_6 ( V_278 ) ;
if ( F_187 ( V_17 -> V_308 ) )
F_76 ( V_62 . V_591 . V_215 ) ;
F_76 ( V_127 ) ;
F_43 ( & V_156 -> V_294 . V_129 ) ;
return 0 ;
V_135:
F_188 ( V_283 ) ;
V_183:
F_76 ( V_127 ) ;
V_537:
if ( F_187 ( V_17 -> V_308 ) )
F_76 ( V_62 . V_591 . V_215 ) ;
V_595:
if ( V_17 -> V_308 == V_309 ) {
F_67 ( & V_156 -> V_293 -> V_169 ) ;
F_6 ( V_278 ) ;
}
V_31:
F_45 ( & V_156 -> V_294 . V_129 ) ;
return V_26 ;
}
T_1 F_189 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_189 V_17 ;
struct V_586 V_602 ;
struct V_587 V_19 ;
struct V_20 V_21 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
memset ( & V_602 , 0 , sizeof( V_602 ) ) ;
V_602 . V_32 = V_17 . V_32 ;
V_602 . V_218 = V_17 . V_218 ;
V_602 . V_308 = V_603 ;
V_602 . V_133 = V_17 . V_133 ;
V_602 . V_532 = V_17 . V_532 ;
V_602 . V_73 = V_17 . V_73 ;
V_602 . V_598 = V_17 . V_598 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
V_26 = F_186 ( V_11 , V_13 , & V_602 , & V_21 ) ;
if ( V_26 )
return V_26 ;
return V_15 ;
}
T_1 V_586 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 , int V_16 )
{
struct V_586 V_17 ;
struct V_587 V_19 ;
struct V_20 V_21 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof( V_17 ) ,
( unsigned long ) V_17 . V_32 + sizeof( V_19 ) ,
V_15 - sizeof( V_17 ) - sizeof( struct V_33 ) ,
V_16 - sizeof( V_19 ) ) ;
V_26 = F_186 ( V_11 , V_13 , & V_17 , & V_21 ) ;
if ( V_26 )
return V_26 ;
return V_15 ;
}
T_1 F_190 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_190 V_17 ;
struct V_20 V_21 ;
struct V_282 * V_283 ;
struct V_604 V_62 ;
int V_26 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
F_11 ( & V_21 , V_14 + sizeof V_17 , NULL , V_15 - sizeof V_17 ,
V_16 ) ;
V_283 = F_74 ( V_283 , V_17 . V_307 , V_11 -> V_22 ) ;
if ( ! V_283 )
return - V_30 ;
V_62 . V_532 = V_17 . V_532 ;
V_62 . V_598 = V_17 . V_598 ;
V_26 = V_283 -> V_37 -> V_605 ( V_283 , & V_62 , V_17 . V_366 , & V_21 ) ;
F_76 ( V_283 ) ;
return V_26 ? V_26 : V_15 ;
}
T_1 F_191 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 ,
int V_15 , int V_16 )
{
struct F_191 V_17 ;
struct V_606 V_19 ;
struct V_604 V_62 ;
struct V_282 * V_283 ;
int V_26 ;
if ( V_16 < sizeof V_19 )
return - V_27 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_283 = F_74 ( V_283 , V_17 . V_307 , V_11 -> V_22 ) ;
if ( ! V_283 )
return - V_30 ;
V_26 = F_192 ( V_283 , & V_62 ) ;
F_76 ( V_283 ) ;
if ( V_26 )
return V_26 ;
memset ( & V_19 , 0 , sizeof V_19 ) ;
V_19 . V_532 = V_62 . V_532 ;
V_19 . V_73 = V_62 . V_73 ;
V_19 . V_598 = V_62 . V_598 ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof V_19 ) )
return - V_28 ;
return V_15 ;
}
T_1 F_193 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
const char T_2 * V_14 , int V_15 ,
int V_16 )
{
struct F_193 V_17 ;
struct V_607 V_19 ;
struct V_5 * V_6 ;
struct V_608 * V_156 ;
int V_26 = - V_30 ;
if ( F_9 ( & V_17 , V_14 , sizeof V_17 ) )
return - V_28 ;
V_6 = F_47 ( F_3 ( V_283 ) , V_17 . V_307 ,
V_11 -> V_22 ) ;
if ( F_4 ( V_6 ) )
return F_13 ( V_6 ) ;
V_156 = F_7 ( V_6 , struct V_608 , V_129 ) ;
F_5 ( V_6 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_26 = F_48 ( V_6 ) ;
if ( V_26 ) {
F_106 ( V_6 ) ;
return V_26 ;
}
V_19 . V_324 = V_156 -> V_324 ;
F_106 ( V_6 ) ;
if ( F_23 ( ( void T_2 * ) ( unsigned long ) V_17 . V_32 ,
& V_19 , sizeof( V_19 ) ) )
return - V_28 ;
return V_15 ;
}
int F_194 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_20 * V_209 ,
struct V_20 * V_210 )
{
struct V_609 V_19 = { { 0 } } ;
struct F_194 V_17 ;
struct V_61 V_62 = { 0 } ;
int V_31 ;
if ( V_209 -> V_236 < sizeof( V_17 ) )
return - V_30 ;
V_31 = F_97 ( & V_17 , V_209 , sizeof( V_17 ) ) ;
if ( V_31 )
return V_31 ;
if ( V_17 . V_237 )
return - V_30 ;
if ( V_17 . V_238 )
return - V_30 ;
V_19 . V_232 = F_89 ( F_90 ( V_19 ) , V_610 ) ;
if ( V_209 -> V_239 < V_19 . V_232 )
return - V_27 ;
V_31 = V_13 -> V_611 ( V_13 , & V_62 , V_210 ) ;
if ( V_31 )
return V_31 ;
F_31 ( V_11 , V_13 , & V_19 . V_230 , & V_62 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_610 ) )
goto V_612;
#ifdef F_18
V_19 . V_610 . V_613 = V_62 . V_610 . V_613 ;
V_19 . V_610 . V_614 . V_615 =
V_62 . V_610 . V_614 . V_615 ;
V_19 . V_610 . V_614 . V_616 =
V_62 . V_610 . V_614 . V_616 ;
V_19 . V_610 . V_614 . V_617 =
V_62 . V_610 . V_614 . V_617 ;
#endif
V_19 . V_232 += sizeof( V_19 . V_610 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_618 ) )
goto V_612;
V_19 . V_618 = V_62 . V_618 ;
V_19 . V_232 += sizeof( V_19 . V_618 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_619 ) )
goto V_612;
V_19 . V_619 = V_62 . V_619 ;
V_19 . V_232 += sizeof( V_19 . V_619 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_620 ) )
goto V_612;
V_19 . V_620 = V_62 . V_50 ;
V_19 . V_232 += sizeof( V_19 . V_620 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_621 ) )
goto V_612;
V_19 . V_621 . V_622 = V_62 . V_621 . V_622 ;
V_19 . V_621 . V_623 =
V_62 . V_621 . V_623 ;
V_19 . V_621 . V_624 =
V_62 . V_621 . V_624 ;
V_19 . V_232 += sizeof( V_19 . V_621 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_625 ) )
goto V_612;
V_19 . V_625 = V_62 . V_625 ;
V_19 . V_232 += sizeof( V_19 . V_625 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_626 ) )
goto V_612;
V_19 . V_626 = V_62 . V_626 ;
V_19 . V_232 += sizeof( V_19 . V_626 ) ;
if ( V_209 -> V_239 < V_19 . V_232 + sizeof( V_19 . V_627 ) )
goto V_612;
V_19 . V_627 . V_628 = V_62 . V_627 . V_628 ;
V_19 . V_627 . V_593 = V_62 . V_627 . V_593 ;
V_19 . V_627 . V_629 = V_62 . V_627 . V_629 ;
V_19 . V_627 . V_73 = V_62 . V_627 . V_73 ;
V_19 . V_627 . V_191 = V_62 . V_627 . V_191 ;
V_19 . V_232 += sizeof( V_19 . V_627 ) ;
V_612:
V_31 = F_94 ( V_209 , & V_19 , V_19 . V_232 ) ;
return V_31 ;
}
