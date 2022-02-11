static unsigned F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return V_4 + V_2 -> V_3 * F_2 ( V_2 -> V_5 ) + V_3 ;
}
static int F_3 ( struct V_6 * V_5 , bool V_7 ,
unsigned * V_8 , unsigned * V_9 )
{
T_1 V_10 [ V_11 ] ;
T_1 V_12 [ V_13 ] ;
unsigned V_14 , V_15 ;
T_2 V_16 ;
int V_17 ;
F_4 ( V_10 , V_18 , V_7 ? 1 : 0 ) ;
F_4 ( V_10 , V_19 , V_4 ) ;
F_4 ( V_10 , V_20 , V_5 -> V_21 ) ;
V_17 = F_5 ( V_5 , V_22 , V_10 , V_11 ,
V_12 , V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
if ( V_16 < V_13 )
return - V_23 ;
V_15 = F_6 ( V_12 , V_24 ) ;
V_14 = F_6 ( V_12 , V_25 ) ;
if ( V_14 > V_26 )
return - V_27 ;
if ( V_8 )
* V_8 = V_14 ;
if ( V_9 )
* V_9 = V_15 ;
return 0 ;
}
static void F_7 ( struct V_6 * V_5 , bool V_28 )
{
T_3 V_29 ;
F_8 ( V_29 ,
V_30 , V_28 ? 0 : 1 ,
V_31 , V_5 -> V_32 -> V_33 ) ;
F_9 ( V_5 , & V_29 , V_34 ) ;
}
static int F_10 ( struct V_6 * V_5 , struct V_35 * V_36 ,
unsigned int V_37 )
{
T_1 * V_10 , * V_38 ;
unsigned int V_39 ;
T_4 V_40 , V_41 , V_42 ;
int V_17 ;
F_11 () ;
V_39 = F_12 ( V_37 ) ;
if ( F_13 ( V_39 > V_43 ) )
return - V_44 ;
V_10 = F_14 ( V_43 , V_45 ) ;
if ( V_10 == NULL )
return - V_46 ;
V_38 = V_10 ;
F_4 ( V_38 , V_47 , V_37 ) ;
while ( V_37 -- > 0 ) {
F_4 ( V_38 , V_48 ,
V_36 -> V_49 ) ;
F_4 ( V_38 , V_50 ,
( T_4 ) V_36 -> V_51 ) ;
F_4 ( V_38 , V_52 ,
( T_4 ) ( V_36 -> V_51 >> 32 ) ) ;
if ( V_36 -> V_53 == NULL ) {
V_40 = V_36 -> V_40 ;
V_42 = ( T_4 ) V_36 -> V_54 ;
V_41 = ( T_4 ) ( V_36 -> V_54 >> 32 ) ;
} else {
if ( F_13 ( V_39 + V_36 -> V_55 > V_43 ) ) {
V_17 = - V_44 ;
goto V_56;
}
V_40 = V_57 ;
V_42 = V_39 ;
V_41 = 0 ;
memcpy ( V_10 + V_39 , V_36 -> V_53 , V_36 -> V_55 ) ;
V_39 += V_36 -> V_55 ;
}
F_4 ( V_38 , V_58 , V_40 ) ;
F_4 ( V_38 , V_59 ,
V_42 ) ;
F_4 ( V_38 , V_60 ,
V_41 ) ;
F_4 ( V_38 , V_61 ,
V_36 -> V_55 ) ;
++ V_36 ;
V_38 += V_62 ;
}
V_17 = F_5 ( V_5 , V_63 , V_10 , V_39 , NULL , 0 , NULL ) ;
V_56:
F_15 ( V_10 ) ;
F_11 () ;
return V_17 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_64 V_65 ;
T_5 V_66 ;
int V_17 ;
if ( V_2 -> V_67 != - 1 ) {
F_17 ( V_5 , V_68 ,
V_2 -> V_67 ) ;
F_18 ( V_5 , V_69 , V_5 -> V_70 , L_1 ,
V_2 -> V_71 , V_2 -> V_67 ) ;
V_2 -> V_67 = - 1 ;
}
if ( F_19 ( V_2 -> V_72 . V_73 ) )
return;
if ( V_2 -> V_74 == V_75 && V_76 <= 2 )
V_2 -> V_74 = V_77 ;
V_66 = F_20 ( V_2 -> V_72 . V_78 ) & V_79 ;
F_21 ( & V_65 , F_1 ( V_2 , 0 ) ) ;
V_17 = F_22 ( & V_65 ,
V_66 ? V_66 : V_80 ,
V_2 -> V_72 . V_73 ) ;
F_23 ( V_17 ) ;
V_17 = F_24 ( V_5 , & V_65 , true ) ;
if ( V_17 < 0 ) {
F_25 ( V_5 , V_69 , V_5 -> V_70 ,
L_2 ,
V_2 -> V_71 ) ;
} else {
F_18 ( V_5 , V_69 , V_5 -> V_70 , L_3 ,
V_2 -> V_71 , V_17 ) ;
V_2 -> V_67 = V_17 ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_64 V_65 ;
T_5 V_66 ;
int V_17 ;
if ( V_2 -> V_81 != - 1 ) {
F_17 ( V_5 , V_68 ,
V_2 -> V_81 ) ;
F_18 ( V_5 , V_69 , V_5 -> V_70 , L_4 ,
V_2 -> V_71 , V_2 -> V_81 ) ;
V_2 -> V_81 = - 1 ;
}
if ( ! V_2 -> V_82 || F_19 ( V_2 -> V_72 . V_73 ) )
return;
V_66 = F_20 ( V_2 -> V_72 . V_78 ) & V_79 ;
F_27 ( & V_65 , V_68 ,
V_2 -> V_83 ,
F_1 ( V_2 , V_2 -> V_84 ) ) ;
V_17 = F_22 ( & V_65 ,
V_66 ? V_66 : V_80 ,
V_2 -> V_72 . V_73 ) ;
F_23 ( V_17 ) ;
V_17 = F_24 ( V_5 , & V_65 , true ) ;
if ( V_17 < 0 ) {
F_25 ( V_5 , V_69 , V_5 -> V_70 ,
L_5 ,
V_2 -> V_71 ) ;
} else {
F_18 ( V_5 , V_69 , V_5 -> V_70 , L_6 ,
V_2 -> V_71 , V_17 ) ;
V_2 -> V_81 = V_17 ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_26 ( V_2 ) ;
F_29 ( V_85 , & V_2 -> V_5 -> V_86 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_87 * V_88 = V_5 -> V_87 . V_72 ;
struct V_35 V_89 [ 4 ] ;
struct V_90 * V_91 ;
unsigned int V_92 , V_37 ;
unsigned V_93 ;
T_6 V_94 ;
F_13 ( ! F_31 ( & V_2 -> V_95 ) ) ;
F_13 ( ! V_2 -> V_96 ) ;
V_88 -> V_97 = V_2 -> V_72 ;
V_88 -> V_98 = ++ V_88 -> V_99 ;
memset ( V_89 , '\0' , sizeof( V_89 ) ) ;
V_89 [ 0 ] . V_53 = & V_88 -> V_99 ;
V_89 [ 0 ] . V_49 = V_2 -> V_100 ;
V_89 [ 0 ] . V_51 = V_2 -> V_96 + F_32 ( struct V_87 ,
V_99 ) ;
V_89 [ 0 ] . V_55 = sizeof( V_88 -> V_99 ) ;
V_93 = F_32 ( struct V_87 , V_101 ) ;
V_89 [ 1 ] . V_40 = V_5 -> V_102 -> V_103 ;
V_89 [ 1 ] . V_54 = V_5 -> V_87 . V_104 + V_93 ;
V_89 [ 1 ] . V_49 = V_2 -> V_100 ;
V_89 [ 1 ] . V_51 = V_2 -> V_96 + V_93 ;
V_89 [ 1 ] . V_55 = V_88 -> V_55 - V_93 ;
V_92 = 2 ;
V_37 = 0 ;
F_33 (epp, &efx->local_page_list, link) {
if ( V_37 == V_2 -> V_105 ) {
break;
}
V_89 [ V_92 ] . V_53 = NULL ;
V_89 [ V_92 ] . V_40 = V_5 -> V_102 -> V_103 ;
V_89 [ V_92 ] . V_54 = V_91 -> V_72 ;
V_89 [ V_92 ] . V_49 = V_2 -> V_100 ;
V_89 [ V_92 ] . V_51 = V_2 -> V_106 [ V_37 ] ;
V_89 [ V_92 ] . V_55 = V_107 ;
if ( ++ V_92 == F_34 ( V_89 ) ) {
F_10 ( V_5 , V_89 , F_34 ( V_89 ) ) ;
V_92 = 0 ;
}
++ V_37 ;
}
V_89 [ V_92 ] . V_53 = & V_88 -> V_98 ;
V_89 [ V_92 ] . V_49 = V_2 -> V_100 ;
V_89 [ V_92 ] . V_51 = V_2 -> V_96 + F_32 ( struct V_87 ,
V_98 ) ;
V_89 [ V_92 ] . V_55 = sizeof( V_88 -> V_98 ) ;
F_10 ( V_5 , V_89 , V_92 + 1 ) ;
F_35 ( V_94 ,
V_108 , V_109 ,
V_110 , ( V_2 -> V_111 & 0xff ) ,
V_112 , V_113 ) ;
++ V_2 -> V_111 ;
F_36 ( V_5 , V_4 + V_2 -> V_3 * F_2 ( V_5 ) ,
& V_94 ) ;
}
static void F_37 ( struct V_6 * V_5 , unsigned V_114 ,
T_7 * V_72 , unsigned V_37 )
{
T_6 V_115 ;
unsigned V_92 ;
for ( V_92 = 0 ; V_92 < V_37 ; ++ V_92 ) {
F_35 ( V_115 ,
V_116 , 0 ,
V_117 ,
V_72 ? V_72 [ V_92 ] >> 12 : 0 ,
V_118 , 0 ) ;
F_38 ( V_5 , V_5 -> V_119 + V_120 ,
& V_115 , V_114 + V_92 ) ;
}
}
static bool F_39 ( struct V_6 * V_5 , unsigned V_3 )
{
return V_3 >= F_2 ( V_5 ) ;
}
static bool F_40 ( unsigned V_121 , unsigned V_122 )
{
unsigned V_123 = V_122 *
sizeof( T_6 ) / V_124 ;
return ( ( V_121 & ( V_121 - 1 ) ) || V_121 > V_123 ) ;
}
static bool F_41 ( struct V_6 * V_5 , unsigned F_1 ,
struct V_1 * * V_125 , unsigned * V_126 )
{
unsigned V_127 ;
if ( F_1 < V_4 )
return true ;
V_127 = ( F_1 - V_4 ) / F_2 ( V_5 ) ;
if ( V_127 >= V_5 -> V_128 )
return true ;
if ( V_125 )
* V_125 = V_5 -> V_2 + V_127 ;
if ( V_126 )
* V_126 = F_1 % F_2 ( V_5 ) ;
return false ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
unsigned V_130 = V_36 -> V_131 . V_132 . V_3 ;
unsigned V_121 = V_36 -> V_131 . V_132 . V_121 ;
unsigned V_133 = F_1 ( V_2 , V_130 ) ;
unsigned V_134 = F_43 ( V_2 , V_130 ) ;
T_3 V_29 ;
if ( F_39 ( V_5 , V_130 ) ||
F_40 ( V_121 , V_135 ) ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_7 ,
V_2 -> V_71 , V_130 , V_121 ) ;
return V_136 ;
}
F_37 ( V_5 , V_134 , V_36 -> V_131 . V_132 . V_72 , V_121 ) ;
F_46 ( V_29 ,
V_137 , 1 ,
V_138 , 0 ,
V_139 , V_140 ) ;
F_47 ( V_5 , & V_29 , V_141 , V_133 ) ;
F_46 ( V_29 ,
V_142 , 1 ,
V_143 , F_48 ( V_121 ) ,
V_144 , V_134 ) ;
F_47 ( V_5 , & V_29 , V_145 , V_133 ) ;
if ( V_130 == 0 ) {
memcpy ( V_2 -> V_146 , V_36 -> V_131 . V_132 . V_72 ,
V_121 * sizeof( T_7 ) ) ;
V_2 -> V_147 = V_121 ;
}
return V_148 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
unsigned V_149 = V_36 -> V_131 . V_150 . V_3 ;
unsigned V_130 = V_36 -> V_131 . V_150 . V_151 ;
unsigned V_121 = V_36 -> V_131 . V_150 . V_121 ;
unsigned V_134 = F_50 ( V_2 , V_149 ) ;
unsigned V_152 ;
T_3 V_29 ;
if ( F_39 ( V_5 , V_130 ) || F_39 ( V_5 , V_149 ) ||
V_149 >= V_153 ||
F_40 ( V_121 , V_154 ) ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_8
L_9 , V_2 -> V_71 , V_149 ,
V_130 , V_121 ) ;
return V_136 ;
}
if ( F_51 ( V_36 -> V_131 . V_150 . V_3 , V_2 -> V_155 ) )
++ V_2 -> V_156 ;
F_37 ( V_5 , V_134 , V_36 -> V_131 . V_150 . V_72 , V_121 ) ;
V_152 = V_36 -> V_131 . V_150 . V_152 & F_52 ( V_157 ) ;
F_53 ( V_29 ,
V_158 , V_134 ,
V_159 , F_1 ( V_2 , V_130 ) ,
V_157 , V_152 ,
V_160 , F_48 ( V_121 ) ,
V_161 ,
! ! ( V_36 -> V_131 . V_150 . V_162 &
V_163 ) ,
V_164 , 1 ) ;
F_47 ( V_5 , & V_29 , V_165 ,
F_1 ( V_2 , V_149 ) ) ;
return V_148 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
unsigned V_166 = V_36 -> V_131 . V_167 . V_3 ;
unsigned V_130 = V_36 -> V_131 . V_167 . V_151 ;
unsigned V_121 = V_36 -> V_131 . V_167 . V_121 ;
unsigned V_134 = F_55 ( V_2 , V_166 ) ;
unsigned V_152 , V_168 ;
T_3 V_29 ;
if ( F_39 ( V_5 , V_130 ) || F_39 ( V_5 , V_166 ) ||
V_166 >= V_76 ||
F_40 ( V_121 , V_154 ) ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_10
L_9 , V_2 -> V_71 , V_166 ,
V_130 , V_121 ) ;
return V_136 ;
}
F_56 ( & V_2 -> V_169 ) ;
if ( F_51 ( V_36 -> V_131 . V_167 . V_3 , V_2 -> V_170 ) )
++ V_2 -> V_171 ;
F_57 ( & V_2 -> V_169 ) ;
F_37 ( V_5 , V_134 , V_36 -> V_131 . V_167 . V_72 , V_121 ) ;
V_168 = V_2 -> V_74 == V_77 ;
V_152 = V_36 -> V_131 . V_167 . V_152 & F_52 ( V_172 ) ;
F_58 ( V_29 ,
V_173 , F_59 ( V_5 -> V_14 , 1U ) ,
V_174 , V_168 ,
V_175 , 1 ,
V_176 , V_134 ,
V_177 , F_1 ( V_2 , V_130 ) ,
V_172 , V_152 ,
V_178 , F_48 ( V_121 ) ,
V_179 , 1 ) ;
F_47 ( V_5 , & V_29 , V_180 ,
F_1 ( V_2 , V_166 ) ) ;
return V_148 ;
}
static bool F_60 ( struct V_1 * V_2 )
{
F_61 () ;
return ( ! V_2 -> V_171 && ! V_2 -> V_156 ) ||
F_62 ( & V_2 -> V_181 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_170 , 0 , sizeof( V_2 -> V_170 ) ) ;
V_2 -> V_171 = 0 ;
memset ( V_2 -> V_155 , 0 , sizeof( V_2 -> V_155 ) ) ;
V_2 -> V_156 = 0 ;
memset ( V_2 -> V_182 , 0 , sizeof( V_2 -> V_182 ) ) ;
F_64 ( & V_2 -> V_181 , 0 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
T_3 V_29 ;
unsigned V_37 = F_2 ( V_5 ) ;
unsigned V_183 = V_4 + V_2 -> V_3 * F_2 ( V_5 ) ;
unsigned V_184 = V_185 ;
unsigned V_3 , V_186 ;
T_8 * V_187 ;
int V_17 ;
F_66 ( V_153 >
V_188 ) ;
V_187 = F_67 ( V_37 * sizeof( * V_187 ) , V_45 ) ;
if ( V_187 == NULL )
return V_189 ;
F_68 () ;
F_69 ( V_5 ) ;
F_70 () ;
V_186 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
if ( F_71 ( V_3 , V_2 -> V_170 ) ) {
F_8 ( V_29 ,
V_190 , 1 ,
V_191 ,
V_183 + V_3 ) ;
F_9 ( V_5 , & V_29 , V_192 ) ;
}
if ( F_71 ( V_3 , V_2 -> V_155 ) )
V_187 [ V_186 ++ ] = F_72 ( V_183 + V_3 ) ;
}
F_64 ( & V_2 -> V_181 , 0 ) ;
while ( V_184 && ( V_2 -> V_156 || V_2 -> V_171 ) ) {
V_17 = F_5 ( V_5 , V_193 , ( T_1 * ) V_187 ,
V_186 * sizeof( * V_187 ) , NULL , 0 , NULL ) ;
F_13 ( V_17 < 0 ) ;
V_184 = F_73 ( V_2 -> V_194 ,
F_60 ( V_2 ) ,
V_184 ) ;
V_186 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
if ( F_74 ( V_3 , V_2 -> V_182 ) ) {
F_75 ( & V_2 -> V_181 ) ;
V_187 [ V_186 ++ ] =
F_72 ( V_183 + V_3 ) ;
}
}
}
F_68 () ;
F_76 ( V_5 ) ;
F_70 () ;
F_77 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
F_47 ( V_5 , & V_29 , V_165 ,
V_183 + V_3 ) ;
F_47 ( V_5 , & V_29 , V_180 ,
V_183 + V_3 ) ;
F_47 ( V_5 , & V_29 , V_145 ,
V_183 + V_3 ) ;
F_47 ( V_5 , & V_29 , V_141 ,
V_183 + V_3 ) ;
}
F_37 ( V_5 , V_2 -> V_195 , NULL ,
V_196 * F_2 ( V_5 ) ) ;
F_15 ( V_187 ) ;
F_63 ( V_2 ) ;
V_2 -> V_147 = 0 ;
return V_184 ? 0 : V_197 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
unsigned V_149 = V_36 -> V_131 . V_198 . V_199 ;
unsigned V_162 ;
if ( F_39 ( V_5 , V_149 ) || V_2 -> V_82 ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_11
L_12 , V_2 -> V_71 , V_149 ,
V_36 -> V_131 . V_198 . V_162 ) ;
return V_136 ;
}
V_162 = 0 ;
if ( V_36 -> V_131 . V_198 . V_162 & V_200 )
V_162 |= V_201 ;
if ( V_36 -> V_131 . V_198 . V_162 & V_202 )
V_162 |= V_203 ;
V_2 -> V_83 = V_162 ;
V_2 -> V_84 = V_149 ;
V_2 -> V_82 = true ;
F_26 ( V_2 ) ;
F_29 ( V_85 , & V_5 -> V_86 ) ;
return V_148 ;
}
static int F_79 ( struct V_1 * V_2 )
{
V_2 -> V_82 = false ;
F_26 ( V_2 ) ;
F_29 ( V_85 , & V_2 -> V_5 -> V_86 ) ;
return V_148 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
T_7 V_204 = V_36 -> V_131 . V_205 . V_105 ;
T_7 V_206 =
( V_107 -
F_32 ( struct V_129 , V_131 . V_205 . V_207 [ 0 ] ) )
/ sizeof( V_36 -> V_131 . V_205 . V_207 [ 0 ] ) ;
if ( ! V_36 -> V_131 . V_205 . V_104 || V_204 > V_206 ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_13 ,
V_2 -> V_71 ) ;
return V_136 ;
}
F_56 ( & V_5 -> V_208 ) ;
F_56 ( & V_2 -> V_95 ) ;
V_2 -> V_96 = V_36 -> V_131 . V_205 . V_104 ;
F_15 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
V_2 -> V_105 = 0 ;
if ( V_204 ) {
V_2 -> V_106 = F_81 ( V_204 , sizeof( T_7 ) ,
V_45 ) ;
if ( V_2 -> V_106 ) {
memcpy ( V_2 -> V_106 ,
V_36 -> V_131 . V_205 . V_207 ,
V_204 * sizeof( T_7 ) ) ;
V_2 -> V_105 = V_204 ;
}
}
F_30 ( V_2 ) ;
F_57 ( & V_2 -> V_95 ) ;
F_57 ( & V_5 -> V_208 ) ;
return V_148 ;
}
static int F_82 ( struct V_1 * V_2 )
{
F_56 ( & V_2 -> V_95 ) ;
V_2 -> V_96 = 0 ;
F_57 ( & V_2 -> V_95 ) ;
return V_148 ;
}
static void F_83 ( struct V_209 * V_210 )
{
struct V_1 * V_2 = F_84 ( V_210 , struct V_1 , V_36 ) ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
struct V_35 V_89 [ 2 ] ;
int V_17 ;
memset ( V_89 , '\0' , sizeof( V_89 ) ) ;
V_89 [ 0 ] . V_40 = V_2 -> V_100 ;
V_89 [ 0 ] . V_54 = V_2 -> V_211 ;
V_89 [ 0 ] . V_49 = V_5 -> V_102 -> V_103 ;
V_89 [ 0 ] . V_51 = V_2 -> V_115 . V_104 ;
V_89 [ 0 ] . V_55 = V_107 ;
V_17 = F_10 ( V_5 , V_89 , 1 ) ;
if ( V_17 ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_14 ,
V_2 -> V_71 , - V_17 ) ;
V_2 -> V_212 = false ;
return;
}
if ( V_36 -> V_213 < V_214 && V_215 [ V_36 -> V_213 ] != NULL ) {
V_17 = V_215 [ V_36 -> V_213 ] ( V_2 ) ;
if ( V_17 == 0 ) {
F_18 ( V_5 , V_69 , V_5 -> V_70 ,
L_15 ,
V_36 -> V_213 , V_2 -> V_71 ) ;
}
} else {
F_18 ( V_5 , V_69 , V_5 -> V_70 ,
L_16
L_17 , V_36 -> V_213 , V_2 -> V_71 ,
( unsigned long long ) V_2 -> V_211 ) ;
V_17 = V_216 ;
}
V_2 -> V_212 = false ;
F_85 () ;
V_36 -> V_17 = V_17 ;
V_36 -> V_213 = V_217 ;
memset ( V_89 , '\0' , sizeof( V_89 ) ) ;
V_89 [ 0 ] . V_53 = & V_36 -> V_17 ;
V_89 [ 0 ] . V_49 = V_2 -> V_100 ;
V_89 [ 0 ] . V_51 = V_2 -> V_211 + F_32 ( struct V_129 , V_17 ) ;
V_89 [ 0 ] . V_55 = sizeof( V_36 -> V_17 ) ;
V_89 [ 1 ] . V_53 = & V_36 -> V_213 ;
V_89 [ 1 ] . V_49 = V_2 -> V_100 ;
V_89 [ 1 ] . V_51 = V_2 -> V_211 + F_32 ( struct V_129 , V_213 ) ;
V_89 [ 1 ] . V_55 = sizeof( V_36 -> V_213 ) ;
( void ) F_10 ( V_5 , V_89 , F_34 ( V_89 ) ) ;
}
static void F_86 ( struct V_1 * V_2 , struct V_218 * V_219 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_35 V_220 [ 4 ] ;
T_6 V_94 ;
unsigned int V_92 , V_37 , V_221 , V_134 , V_133 ;
T_3 V_29 ;
T_9 V_222 ;
int V_17 ;
F_23 ( V_219 -> V_223 != V_107 ) ;
if ( ! V_2 -> V_147 )
return;
F_23 ( V_2 -> V_147 & ( V_2 -> V_147 - 1 ) ) ;
F_56 ( & V_2 -> V_95 ) ;
F_35 ( V_94 ,
V_108 , V_109 ,
V_110 , V_2 -> V_111 ,
V_112 , V_224 ) ;
V_2 -> V_111 ++ ;
for ( V_92 = 0 ; V_92 < V_107 ; V_92 += sizeof( V_94 ) )
memcpy ( V_219 -> V_72 + V_92 , & V_94 , sizeof( V_94 ) ) ;
for ( V_92 = 0 ; V_92 < V_2 -> V_147 ; V_92 += V_37 ) {
V_37 = F_87 ( unsigned , V_2 -> V_147 - V_92 ,
F_34 ( V_220 ) ) ;
for ( V_221 = 0 ; V_221 < V_37 ; V_221 ++ ) {
V_220 [ V_221 ] . V_53 = NULL ;
V_220 [ V_221 ] . V_40 = V_5 -> V_102 -> V_103 ;
V_220 [ V_221 ] . V_54 = V_219 -> V_104 ;
V_220 [ V_221 ] . V_49 = V_2 -> V_100 ;
V_220 [ V_221 ] . V_51 = V_2 -> V_146 [ V_92 + V_221 ] ;
V_220 [ V_221 ] . V_55 = V_107 ;
}
V_17 = F_10 ( V_5 , V_220 , V_37 ) ;
if ( V_17 ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_18
L_19 , V_2 -> V_71 , - V_17 ) ;
break;
}
}
V_133 = F_1 ( V_2 , 0 ) ;
V_134 = F_43 ( V_2 , 0 ) ;
F_37 ( V_5 , V_134 , V_2 -> V_146 , V_2 -> V_147 ) ;
F_46 ( V_29 ,
V_137 , 1 ,
V_138 , 0 ,
V_139 , V_140 ) ;
F_47 ( V_5 , & V_29 , V_141 , V_133 ) ;
F_46 ( V_29 ,
V_142 , 1 ,
V_143 , F_48 ( V_2 -> V_147 ) ,
V_144 , V_134 ) ;
F_47 ( V_5 , & V_29 , V_145 , V_133 ) ;
F_88 ( V_222 , V_225 , 0 ) ;
F_89 ( V_5 , & V_222 , V_226 + V_227 * V_133 ) ;
F_57 ( & V_2 -> V_95 ) ;
}
static void F_90 ( struct V_209 * V_210 )
{
struct V_1 * V_2 = F_84 ( V_210 , struct V_1 , V_36 ) ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_218 V_115 ;
if ( ! F_91 ( V_5 , & V_115 , V_107 ) ) {
F_86 ( V_2 , & V_115 ) ;
F_92 ( V_5 , & V_115 ) ;
}
}
static void F_93 ( struct V_6 * V_5 )
{
F_45 ( V_5 , V_228 , V_5 -> V_70 ,
L_20
L_21 ) ;
V_5 -> V_21 = 0 ;
}
static int F_94 ( struct V_229 * V_33 )
{
V_33 -> V_5 -> V_32 = V_33 ;
return 0 ;
}
static void
F_95 ( struct V_229 * V_33 , char * V_115 , T_2 V_223 )
{
snprintf ( V_115 , V_223 , L_22 , V_33 -> V_5 -> V_230 ) ;
}
void F_96 ( struct V_6 * V_5 )
{
unsigned V_37 ;
if ( ! V_231 )
return;
if ( F_3 ( V_5 , false , & V_5 -> V_14 , & V_37 ) )
return;
if ( V_37 > 0 && V_37 > V_231 )
V_37 = V_231 ;
V_5 -> V_21 = V_37 ;
V_5 -> V_232 [ V_233 ] = & V_234 ;
}
static void F_97 ( struct V_209 * V_235 )
{
struct V_6 * V_5 = F_84 ( V_235 , struct V_6 , V_86 ) ;
struct V_87 * V_87 = V_5 -> V_87 . V_72 ;
struct V_1 * V_2 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
struct V_90 * V_91 ;
struct V_240 V_241 ;
unsigned int V_242 ;
unsigned int V_243 ;
unsigned int V_92 ;
F_56 ( & V_5 -> V_208 ) ;
F_98 ( & V_241 ) ;
F_99 ( & V_5 -> V_244 , & V_241 ) ;
V_239 = V_87 -> V_245 + 1 ;
V_242 = F_34 ( V_87 -> V_245 ) - 1 ;
V_243 = 1 ;
for ( V_92 = 0 ; V_92 < V_5 -> V_21 ; ++ V_92 ) {
V_2 = V_5 -> V_2 + V_92 ;
F_56 ( & V_2 -> V_95 ) ;
if ( V_2 -> V_82 && ! F_19 ( V_2 -> V_72 . V_73 ) ) {
* V_239 ++ = V_2 -> V_72 ;
++ V_243 ;
-- V_242 ;
F_23 ( V_242 == 0 ) ;
}
F_57 ( & V_2 -> V_95 ) ;
}
F_33 (local_addr, &efx->local_addr_list, link) {
memcpy ( V_239 -> V_73 , V_237 -> V_72 , V_246 ) ;
V_239 -> V_78 = 0 ;
++ V_239 ;
++ V_243 ;
if ( -- V_242 == 0 ) {
if ( F_100 ( & V_241 ) ) {
V_91 = F_67 ( sizeof( * V_91 ) , V_45 ) ;
if ( ! V_91 )
break;
V_91 -> V_222 = F_101 (
& V_5 -> V_102 -> V_247 , V_107 ,
& V_91 -> V_72 , V_45 ) ;
if ( ! V_91 -> V_222 ) {
F_15 ( V_91 ) ;
break;
}
} else {
V_91 = F_102 (
& V_241 , struct V_90 , V_248 ) ;
F_103 ( & V_91 -> V_248 ) ;
}
F_104 ( & V_91 -> V_248 , & V_5 -> V_244 ) ;
V_239 = (struct V_238 * ) V_91 -> V_222 ;
V_242 = V_107 / sizeof( struct V_238 ) ;
}
}
V_87 -> V_243 = V_243 ;
F_57 ( & V_5 -> V_208 ) ;
while ( ! F_100 ( & V_241 ) ) {
V_91 = F_102 (
& V_241 , struct V_90 , V_248 ) ;
F_103 ( & V_91 -> V_248 ) ;
F_105 ( & V_5 -> V_102 -> V_247 , V_107 ,
V_91 -> V_222 , V_91 -> V_72 ) ;
F_15 ( V_91 ) ;
}
for ( V_92 = 0 ; V_92 < V_5 -> V_21 ; ++ V_92 ) {
V_2 = V_5 -> V_2 + V_92 ;
F_56 ( & V_2 -> V_95 ) ;
if ( V_2 -> V_96 )
F_30 ( V_2 ) ;
F_57 ( & V_2 -> V_95 ) ;
}
}
static void F_106 ( struct V_6 * V_5 )
{
struct V_236 * V_237 ;
struct V_90 * V_91 ;
while ( ! F_100 ( & V_5 -> V_249 ) ) {
V_237 = F_102 ( & V_5 -> V_249 ,
struct V_236 , V_248 ) ;
F_103 ( & V_237 -> V_248 ) ;
F_15 ( V_237 ) ;
}
while ( ! F_100 ( & V_5 -> V_244 ) ) {
V_91 = F_102 ( & V_5 -> V_244 ,
struct V_90 , V_248 ) ;
F_103 ( & V_91 -> V_248 ) ;
F_105 ( & V_5 -> V_102 -> V_247 , V_107 ,
V_91 -> V_222 , V_91 -> V_72 ) ;
F_15 ( V_91 ) ;
}
}
static int F_107 ( struct V_6 * V_5 )
{
unsigned V_3 ;
struct V_1 * V_2 ;
V_5 -> V_2 = F_14 ( sizeof( struct V_1 ) * V_5 -> V_21 , V_45 ) ;
if ( ! V_5 -> V_2 )
return - V_46 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_21 ; ++ V_3 ) {
V_2 = V_5 -> V_2 + V_3 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_81 = - 1 ;
V_2 -> V_74 = V_75 ;
V_2 -> V_67 = - 1 ;
F_108 ( & V_2 -> V_36 , F_83 ) ;
F_108 ( & V_2 -> V_250 , F_90 ) ;
F_109 ( & V_2 -> V_194 ) ;
F_110 ( & V_2 -> V_95 ) ;
F_110 ( & V_2 -> V_169 ) ;
}
return 0 ;
}
static void F_111 ( struct V_6 * V_5 )
{
struct V_1 * V_2 ;
unsigned int V_92 ;
for ( V_92 = 0 ; V_92 < V_5 -> V_21 ; ++ V_92 ) {
V_2 = V_5 -> V_2 + V_92 ;
F_92 ( V_5 , & V_2 -> V_115 ) ;
F_15 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
V_2 -> V_105 = 0 ;
V_2 -> V_147 = 0 ;
}
}
static int F_112 ( struct V_6 * V_5 )
{
struct V_102 * V_102 = V_5 -> V_102 ;
unsigned V_3 , V_103 , V_251 , V_195 ;
T_5 V_114 , V_252 ;
struct V_1 * V_2 ;
int V_17 ;
V_251 = F_113 ( V_102 , V_253 ) ;
if ( ! V_251 )
return - V_254 ;
F_114 ( V_102 , V_251 + V_255 , & V_114 ) ;
F_114 ( V_102 , V_251 + V_256 , & V_252 ) ;
V_195 = V_5 -> V_257 ;
V_103 = V_102 -> V_103 + V_114 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_21 ; ++ V_3 ) {
V_2 = V_5 -> V_2 + V_3 ;
V_2 -> V_195 = V_195 ;
V_195 += V_196 * F_2 ( V_5 ) ;
V_2 -> V_100 = V_103 ;
snprintf ( V_2 -> V_71 , sizeof( V_2 -> V_71 ) ,
L_23 ,
F_115 ( V_102 -> V_258 ) , V_102 -> V_258 -> V_259 ,
F_116 ( V_103 ) , F_117 ( V_103 ) ) ;
V_17 = F_91 ( V_5 , & V_2 -> V_115 , V_107 ) ;
if ( V_17 )
goto V_260;
V_103 += V_252 ;
}
return 0 ;
V_260:
F_111 ( V_5 ) ;
return V_17 ;
}
int F_118 ( struct V_6 * V_5 )
{
struct V_261 * V_70 = V_5 -> V_70 ;
struct V_87 * V_87 ;
int V_17 ;
F_66 ( V_262 + 1 >= V_4 ) ;
F_66 ( V_4 & ( ( 1 << V_26 ) - 1 ) ) ;
if ( V_5 -> V_21 == 0 )
return 0 ;
V_17 = F_3 ( V_5 , true , NULL , NULL ) ;
if ( V_17 )
goto V_263;
V_17 = F_91 ( V_5 , & V_5 -> V_87 , sizeof( * V_87 ) ) ;
if ( V_17 )
goto V_264;
V_87 = V_5 -> V_87 . V_72 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_101 = 1 ;
V_87 -> V_55 = sizeof( * V_87 ) ;
V_87 -> V_265 = V_76 ;
V_87 -> V_14 = V_5 -> V_14 ;
V_87 -> V_266 = V_5 -> V_267 ;
V_87 -> V_243 = 1 + V_5 -> V_21 ;
V_87 -> V_268 = V_5 -> V_268 ;
V_17 = F_107 ( V_5 ) ;
if ( V_17 )
goto V_269;
F_110 ( & V_5 -> V_208 ) ;
F_108 ( & V_5 -> V_86 , F_97 ) ;
F_98 ( & V_5 -> V_249 ) ;
F_98 ( & V_5 -> V_244 ) ;
V_17 = F_112 ( V_5 ) ;
if ( V_17 )
goto V_270;
F_68 () ;
memcpy ( V_87 -> V_245 [ 0 ] . V_73 ,
V_70 -> V_271 , V_246 ) ;
V_5 -> V_128 = V_5 -> V_21 ;
F_70 () ;
F_7 ( V_5 , true ) ;
V_17 = F_119 ( V_5 -> V_102 , V_5 -> V_21 ) ;
if ( V_17 )
goto V_272;
F_120 ( V_5 , V_273 , V_70 ,
L_24 ,
V_5 -> V_21 , F_2 ( V_5 ) ) ;
return 0 ;
V_272:
F_7 ( V_5 , false ) ;
F_68 () ;
V_5 -> V_128 = 0 ;
F_70 () ;
F_111 ( V_5 ) ;
V_270:
F_121 ( & V_5 -> V_86 ) ;
F_106 ( V_5 ) ;
F_15 ( V_5 -> V_2 ) ;
V_269:
F_92 ( V_5 , & V_5 -> V_87 ) ;
V_264:
F_3 ( V_5 , false , NULL , NULL ) ;
V_263:
return V_17 ;
}
void F_122 ( struct V_6 * V_5 )
{
struct V_1 * V_2 ;
unsigned int V_92 ;
if ( V_5 -> V_128 == 0 )
return;
F_23 ( V_5 -> V_32 -> V_28 ) ;
F_7 ( V_5 , false ) ;
F_68 () ;
V_5 -> V_128 = 0 ;
F_70 () ;
for ( V_92 = 0 ; V_92 < V_5 -> V_21 ; ++ V_92 ) {
V_2 = V_5 -> V_2 + V_92 ;
F_121 ( & V_2 -> V_36 ) ;
F_121 ( & V_2 -> V_250 ) ;
}
F_121 ( & V_5 -> V_86 ) ;
F_123 ( V_5 -> V_102 ) ;
F_111 ( V_5 ) ;
F_106 ( V_5 ) ;
F_15 ( V_5 -> V_2 ) ;
F_92 ( V_5 , & V_5 -> V_87 ) ;
F_3 ( V_5 , false , NULL , NULL ) ;
}
void F_124 ( struct V_229 * V_33 , T_6 * V_94 )
{
struct V_6 * V_5 = V_33 -> V_5 ;
struct V_1 * V_2 ;
unsigned V_274 , V_275 , type , V_235 ;
V_274 = F_125 ( * V_94 , V_276 ) ;
F_66 ( V_277 != 0 ) ;
V_275 = F_125 ( * V_94 , V_110 ) ;
type = F_125 ( * V_94 , V_112 ) ;
V_235 = F_125 ( * V_94 , V_278 ) ;
F_126 ( V_5 , V_69 , V_5 -> V_70 ,
L_25 ,
V_274 , V_275 , type , V_235 ) ;
if ( F_41 ( V_5 , V_274 , & V_2 , NULL ) )
return;
if ( V_2 -> V_212 )
goto error;
if ( type == V_279 ) {
V_2 -> V_280 = V_279 ;
V_2 -> V_281 = V_275 + 1 ;
V_2 -> V_211 = 0 ;
} else if ( V_275 != ( V_2 -> V_281 ++ & 0xff ) || type != V_2 -> V_280 )
goto error;
switch ( V_2 -> V_280 ) {
case V_279 :
case V_282 :
case V_283 :
V_2 -> V_211 |= ( T_7 ) V_235 << ( V_2 -> V_280 << 4 ) ;
++ V_2 -> V_280 ;
return;
case V_284 :
V_2 -> V_211 |= ( T_7 ) V_235 << 48 ;
V_2 -> V_280 = V_279 ;
V_2 -> V_212 = true ;
F_29 ( V_85 , & V_2 -> V_36 ) ;
return;
}
error:
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_26 ,
V_2 -> V_71 ) ;
V_2 -> V_280 = V_279 ;
V_2 -> V_281 = V_275 + 1 ;
}
void F_127 ( struct V_6 * V_5 , unsigned V_127 )
{
struct V_1 * V_2 ;
if ( V_127 > V_5 -> V_128 )
return;
V_2 = V_5 -> V_2 + V_127 ;
F_120 ( V_5 , V_69 , V_5 -> V_70 ,
L_27 , V_2 -> V_71 ) ;
V_2 -> V_96 = 0 ;
F_79 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_147 = 0 ;
}
void F_128 ( struct V_6 * V_5 )
{
struct V_87 * V_87 = V_5 -> V_87 . V_72 ;
if ( ! V_5 -> V_128 )
return;
memcpy ( V_87 -> V_245 [ 0 ] . V_73 ,
V_5 -> V_70 -> V_271 , V_246 ) ;
F_29 ( V_85 , & V_5 -> V_86 ) ;
}
void F_129 ( struct V_6 * V_5 , T_6 * V_94 )
{
struct V_1 * V_2 ;
unsigned V_285 , V_274 ;
V_285 = F_125 ( * V_94 , V_286 ) ;
if ( F_41 ( V_5 , V_285 , & V_2 , & V_274 ) )
return;
if ( ! F_71 ( V_274 , V_2 -> V_170 ) )
return;
F_130 ( V_274 , V_2 -> V_170 ) ;
-- V_2 -> V_171 ;
if ( F_60 ( V_2 ) )
F_131 ( & V_2 -> V_194 ) ;
}
void F_132 ( struct V_6 * V_5 , T_6 * V_94 )
{
struct V_1 * V_2 ;
unsigned V_287 , V_285 , V_274 ;
V_285 = F_125 ( * V_94 , V_288 ) ;
V_287 = F_125 ( * V_94 ,
V_289 ) ;
if ( F_41 ( V_5 , V_285 , & V_2 , & V_274 ) )
return;
if ( ! F_71 ( V_274 , V_2 -> V_155 ) )
return;
if ( V_287 ) {
F_133 ( V_274 , V_2 -> V_182 ) ;
F_134 ( & V_2 -> V_181 ) ;
} else {
F_130 ( V_274 , V_2 -> V_155 ) ;
-- V_2 -> V_156 ;
}
if ( F_60 ( V_2 ) )
F_131 ( & V_2 -> V_194 ) ;
}
void F_135 ( struct V_6 * V_5 , unsigned V_290 )
{
struct V_1 * V_2 ;
unsigned int V_291 ;
if ( F_41 ( V_5 , V_290 , & V_2 , & V_291 ) )
return;
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_28 ,
V_2 -> V_3 , V_291 ) ;
F_29 ( V_85 , & V_2 -> V_250 ) ;
}
void F_136 ( struct V_6 * V_5 )
{
unsigned int V_127 ;
struct V_218 V_115 ;
struct V_1 * V_2 ;
F_137 () ;
if ( V_5 -> V_128 == 0 )
return;
F_7 ( V_5 , true ) ;
( void ) F_3 ( V_5 , true , NULL , NULL ) ;
if ( F_91 ( V_5 , & V_115 , V_107 ) )
return;
for ( V_127 = 0 ; V_127 < V_5 -> V_128 ; ++ V_127 ) {
V_2 = V_5 -> V_2 + V_127 ;
F_86 ( V_2 , & V_115 ) ;
}
F_92 ( V_5 , & V_115 ) ;
}
int F_138 ( void )
{
V_85 = F_139 ( L_29 ) ;
if ( ! V_85 )
return - V_46 ;
return 0 ;
}
void F_140 ( void )
{
F_141 ( V_85 ) ;
}
int F_142 ( struct V_261 * V_70 , int V_127 , T_1 * V_292 )
{
struct V_6 * V_5 = F_143 ( V_70 ) ;
struct V_1 * V_2 ;
if ( V_127 >= V_5 -> V_128 )
return - V_293 ;
V_2 = V_5 -> V_2 + V_127 ;
F_56 ( & V_2 -> V_95 ) ;
memcpy ( V_2 -> V_72 . V_73 , V_292 , V_246 ) ;
F_28 ( V_2 ) ;
F_57 ( & V_2 -> V_95 ) ;
return 0 ;
}
int F_144 ( struct V_261 * V_70 , int V_127 ,
T_5 V_66 , T_1 V_294 )
{
struct V_6 * V_5 = F_143 ( V_70 ) ;
struct V_1 * V_2 ;
T_5 V_78 ;
if ( V_127 >= V_5 -> V_128 )
return - V_293 ;
V_2 = V_5 -> V_2 + V_127 ;
F_56 ( & V_2 -> V_95 ) ;
V_78 = ( V_66 & V_79 ) | ( ( V_294 & 0x7 ) << V_295 ) ;
V_2 -> V_72 . V_78 = F_145 ( V_78 ) ;
F_28 ( V_2 ) ;
F_57 ( & V_2 -> V_95 ) ;
return 0 ;
}
int F_146 ( struct V_261 * V_70 , int V_127 ,
bool V_296 )
{
struct V_6 * V_5 = F_143 ( V_70 ) ;
struct V_1 * V_2 ;
int V_17 ;
if ( V_127 >= V_5 -> V_128 )
return - V_293 ;
V_2 = V_5 -> V_2 + V_127 ;
F_56 ( & V_2 -> V_169 ) ;
if ( V_2 -> V_171 == 0 ) {
V_2 -> V_74 =
V_296 ? V_77 : V_297 ;
V_17 = 0 ;
} else {
V_17 = - V_298 ;
}
F_57 ( & V_2 -> V_169 ) ;
return V_17 ;
}
int F_147 ( struct V_261 * V_70 , int V_127 ,
struct V_299 * V_300 )
{
struct V_6 * V_5 = F_143 ( V_70 ) ;
struct V_1 * V_2 ;
T_5 V_78 ;
if ( V_127 >= V_5 -> V_128 )
return - V_293 ;
V_2 = V_5 -> V_2 + V_127 ;
V_300 -> V_2 = V_127 ;
memcpy ( V_300 -> V_292 , V_2 -> V_72 . V_73 , V_246 ) ;
V_300 -> V_301 = 0 ;
V_78 = F_20 ( V_2 -> V_72 . V_78 ) ;
V_300 -> V_66 = V_78 & V_79 ;
V_300 -> V_294 = ( V_78 >> V_295 ) & 0x7 ;
V_300 -> V_296 = V_2 -> V_74 == V_77 ;
return 0 ;
}
