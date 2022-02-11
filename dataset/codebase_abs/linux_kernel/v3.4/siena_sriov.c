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
F_40 ( V_121 , V_153 ) ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_8
L_9 , V_2 -> V_71 , V_149 ,
V_130 , V_121 ) ;
return V_136 ;
}
if ( F_51 ( V_36 -> V_131 . V_150 . V_3 , V_2 -> V_154 ) )
++ V_2 -> V_155 ;
F_37 ( V_5 , V_134 , V_36 -> V_131 . V_150 . V_72 , V_121 ) ;
V_152 = V_36 -> V_131 . V_150 . V_152 & F_52 ( V_156 ) ;
F_53 ( V_29 ,
V_157 , V_134 ,
V_158 , F_1 ( V_2 , V_130 ) ,
V_156 , V_152 ,
V_159 , F_48 ( V_121 ) ,
V_160 ,
! ! ( V_36 -> V_131 . V_150 . V_161 &
V_162 ) ,
V_163 , 1 ) ;
F_47 ( V_5 , & V_29 , V_164 ,
F_1 ( V_2 , V_149 ) ) ;
return V_148 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
unsigned V_165 = V_36 -> V_131 . V_166 . V_3 ;
unsigned V_130 = V_36 -> V_131 . V_166 . V_151 ;
unsigned V_121 = V_36 -> V_131 . V_166 . V_121 ;
unsigned V_134 = F_55 ( V_2 , V_165 ) ;
unsigned V_152 , V_167 ;
T_3 V_29 ;
if ( F_39 ( V_5 , V_130 ) || F_39 ( V_5 , V_165 ) ||
V_165 >= V_76 ||
F_40 ( V_121 , V_153 ) ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_10
L_9 , V_2 -> V_71 , V_165 ,
V_130 , V_121 ) ;
return V_136 ;
}
F_56 ( & V_2 -> V_168 ) ;
if ( F_51 ( V_36 -> V_131 . V_166 . V_3 , V_2 -> V_169 ) )
++ V_2 -> V_170 ;
F_57 ( & V_2 -> V_168 ) ;
F_37 ( V_5 , V_134 , V_36 -> V_131 . V_166 . V_72 , V_121 ) ;
V_167 = V_2 -> V_74 == V_77 ;
V_152 = V_36 -> V_131 . V_166 . V_152 & F_52 ( V_171 ) ;
F_58 ( V_29 ,
V_172 , F_59 ( V_5 -> V_14 , 1U ) ,
V_173 , V_167 ,
V_174 , 1 ,
V_175 , V_134 ,
V_176 , F_1 ( V_2 , V_130 ) ,
V_171 , V_152 ,
V_177 , F_48 ( V_121 ) ,
V_178 , 1 ) ;
F_47 ( V_5 , & V_29 , V_179 ,
F_1 ( V_2 , V_165 ) ) ;
return V_148 ;
}
static bool F_60 ( struct V_1 * V_2 )
{
F_61 () ;
return ( ! V_2 -> V_170 && ! V_2 -> V_155 ) ||
F_62 ( & V_2 -> V_180 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_169 , 0 , sizeof( V_2 -> V_169 ) ) ;
V_2 -> V_170 = 0 ;
memset ( V_2 -> V_154 , 0 , sizeof( V_2 -> V_154 ) ) ;
V_2 -> V_155 = 0 ;
memset ( V_2 -> V_181 , 0 , sizeof( V_2 -> V_181 ) ) ;
F_64 ( & V_2 -> V_180 , 0 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
T_3 V_29 ;
unsigned V_37 = F_2 ( V_5 ) ;
unsigned V_182 = V_4 + V_2 -> V_3 * F_2 ( V_5 ) ;
unsigned V_183 = V_184 ;
unsigned V_3 , V_185 ;
T_8 * V_186 ;
int V_17 ;
V_186 = F_66 ( V_37 * sizeof( * V_186 ) , V_45 ) ;
if ( V_186 == NULL )
return V_187 ;
F_67 () ;
if ( V_5 -> V_188 ++ == 0 )
F_68 ( V_5 ) ;
F_69 () ;
V_185 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
if ( F_70 ( V_3 , V_2 -> V_169 ) ) {
F_8 ( V_29 ,
V_189 , 1 ,
V_190 ,
V_182 + V_3 ) ;
F_9 ( V_5 , & V_29 , V_191 ) ;
}
if ( F_70 ( V_3 , V_2 -> V_154 ) )
V_186 [ V_185 ++ ] = F_71 ( V_182 + V_3 ) ;
}
F_64 ( & V_2 -> V_180 , 0 ) ;
while ( V_183 && ( V_2 -> V_155 || V_2 -> V_170 ) ) {
V_17 = F_5 ( V_5 , V_192 , ( T_1 * ) V_186 ,
V_185 * sizeof( * V_186 ) , NULL , 0 , NULL ) ;
F_13 ( V_17 < 0 ) ;
V_183 = F_72 ( V_2 -> V_193 ,
F_60 ( V_2 ) ,
V_183 ) ;
V_185 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
if ( F_73 ( V_3 , V_2 -> V_181 ) ) {
F_74 ( & V_2 -> V_180 ) ;
V_186 [ V_185 ++ ] =
F_71 ( V_182 + V_3 ) ;
}
}
}
F_67 () ;
if ( -- V_5 -> V_188 == 0 )
F_68 ( V_5 ) ;
F_69 () ;
F_75 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
F_47 ( V_5 , & V_29 , V_164 ,
V_182 + V_3 ) ;
F_47 ( V_5 , & V_29 , V_179 ,
V_182 + V_3 ) ;
F_47 ( V_5 , & V_29 , V_145 ,
V_182 + V_3 ) ;
F_47 ( V_5 , & V_29 , V_141 ,
V_182 + V_3 ) ;
}
F_37 ( V_5 , V_2 -> V_194 , NULL ,
V_195 * F_2 ( V_5 ) ) ;
F_15 ( V_186 ) ;
F_63 ( V_2 ) ;
V_2 -> V_147 = 0 ;
return V_183 ? 0 : V_196 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
unsigned V_149 = V_36 -> V_131 . V_197 . V_198 ;
unsigned V_161 ;
if ( F_39 ( V_5 , V_149 ) || V_2 -> V_82 ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_11
L_12 , V_2 -> V_71 , V_149 ,
V_36 -> V_131 . V_197 . V_161 ) ;
return V_136 ;
}
V_161 = 0 ;
if ( V_36 -> V_131 . V_197 . V_161 & V_199 )
V_161 |= V_200 ;
if ( V_36 -> V_131 . V_197 . V_161 & V_201 )
V_161 |= V_202 ;
V_2 -> V_83 = V_161 ;
V_2 -> V_84 = V_149 ;
V_2 -> V_82 = true ;
F_26 ( V_2 ) ;
F_29 ( V_85 , & V_5 -> V_86 ) ;
return V_148 ;
}
static int F_77 ( struct V_1 * V_2 )
{
V_2 -> V_82 = false ;
F_26 ( V_2 ) ;
F_29 ( V_85 , & V_2 -> V_5 -> V_86 ) ;
return V_148 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
T_7 V_203 = V_36 -> V_131 . V_204 . V_105 ;
T_7 V_205 =
( V_107 -
F_32 ( struct V_129 , V_131 . V_204 . V_206 [ 0 ] ) )
/ sizeof( V_36 -> V_131 . V_204 . V_206 [ 0 ] ) ;
if ( ! V_36 -> V_131 . V_204 . V_104 || V_203 > V_205 ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_13 ,
V_2 -> V_71 ) ;
return V_136 ;
}
F_56 ( & V_5 -> V_207 ) ;
F_56 ( & V_2 -> V_95 ) ;
V_2 -> V_96 = V_36 -> V_131 . V_204 . V_104 ;
F_15 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
V_2 -> V_105 = 0 ;
if ( V_203 ) {
V_2 -> V_106 = F_79 ( V_203 , sizeof( T_7 ) ,
V_45 ) ;
if ( V_2 -> V_106 ) {
memcpy ( V_2 -> V_106 ,
V_36 -> V_131 . V_204 . V_206 ,
V_203 * sizeof( T_7 ) ) ;
V_2 -> V_105 = V_203 ;
}
}
F_30 ( V_2 ) ;
F_57 ( & V_2 -> V_95 ) ;
F_57 ( & V_5 -> V_207 ) ;
return V_148 ;
}
static int F_80 ( struct V_1 * V_2 )
{
F_56 ( & V_2 -> V_95 ) ;
V_2 -> V_96 = 0 ;
F_57 ( & V_2 -> V_95 ) ;
return V_148 ;
}
static void F_81 ( struct V_208 * V_209 )
{
struct V_1 * V_2 = F_82 ( V_209 , struct V_1 , V_36 ) ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_129 * V_36 = V_2 -> V_115 . V_72 ;
struct V_35 V_89 [ 2 ] ;
int V_17 ;
memset ( V_89 , '\0' , sizeof( V_89 ) ) ;
V_89 [ 0 ] . V_40 = V_2 -> V_100 ;
V_89 [ 0 ] . V_54 = V_2 -> V_210 ;
V_89 [ 0 ] . V_49 = V_5 -> V_102 -> V_103 ;
V_89 [ 0 ] . V_51 = V_2 -> V_115 . V_104 ;
V_89 [ 0 ] . V_55 = V_107 ;
V_17 = F_10 ( V_5 , V_89 , 1 ) ;
if ( V_17 ) {
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_14 ,
V_2 -> V_71 , - V_17 ) ;
V_2 -> V_211 = false ;
return;
}
if ( V_36 -> V_212 < V_213 && V_214 [ V_36 -> V_212 ] != NULL ) {
V_17 = V_214 [ V_36 -> V_212 ] ( V_2 ) ;
if ( V_17 == 0 ) {
F_18 ( V_5 , V_69 , V_5 -> V_70 ,
L_15 ,
V_36 -> V_212 , V_2 -> V_71 ) ;
}
} else {
F_18 ( V_5 , V_69 , V_5 -> V_70 ,
L_16
L_17 , V_36 -> V_212 , V_2 -> V_71 ,
( unsigned long long ) V_2 -> V_210 ) ;
V_17 = V_215 ;
}
V_2 -> V_211 = false ;
F_83 () ;
V_36 -> V_17 = V_17 ;
V_36 -> V_212 = V_216 ;
memset ( V_89 , '\0' , sizeof( V_89 ) ) ;
V_89 [ 0 ] . V_53 = & V_36 -> V_17 ;
V_89 [ 0 ] . V_49 = V_2 -> V_100 ;
V_89 [ 0 ] . V_51 = V_2 -> V_210 + F_32 ( struct V_129 , V_17 ) ;
V_89 [ 0 ] . V_55 = sizeof( V_36 -> V_17 ) ;
V_89 [ 1 ] . V_53 = & V_36 -> V_212 ;
V_89 [ 1 ] . V_49 = V_2 -> V_100 ;
V_89 [ 1 ] . V_51 = V_2 -> V_210 + F_32 ( struct V_129 , V_212 ) ;
V_89 [ 1 ] . V_55 = sizeof( V_36 -> V_212 ) ;
( void ) F_10 ( V_5 , V_89 , F_34 ( V_89 ) ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_217 * V_218 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_35 V_219 [ 4 ] ;
T_6 V_94 ;
unsigned int V_92 , V_37 , V_220 , V_134 , V_133 ;
T_3 V_29 ;
T_9 V_221 ;
int V_17 ;
F_23 ( V_218 -> V_222 != V_107 ) ;
if ( ! V_2 -> V_147 )
return;
F_23 ( V_2 -> V_147 & ( V_2 -> V_147 - 1 ) ) ;
F_56 ( & V_2 -> V_95 ) ;
F_35 ( V_94 ,
V_108 , V_109 ,
V_110 , V_2 -> V_111 ,
V_112 , V_223 ) ;
V_2 -> V_111 ++ ;
for ( V_92 = 0 ; V_92 < V_107 ; V_92 += sizeof( V_94 ) )
memcpy ( V_218 -> V_72 + V_92 , & V_94 , sizeof( V_94 ) ) ;
for ( V_92 = 0 ; V_92 < V_2 -> V_147 ; V_92 += V_37 ) {
V_37 = F_85 ( unsigned , V_2 -> V_147 - V_92 ,
F_34 ( V_219 ) ) ;
for ( V_220 = 0 ; V_220 < V_37 ; V_220 ++ ) {
V_219 [ V_220 ] . V_53 = NULL ;
V_219 [ V_220 ] . V_40 = V_5 -> V_102 -> V_103 ;
V_219 [ V_220 ] . V_54 = V_218 -> V_104 ;
V_219 [ V_220 ] . V_49 = V_2 -> V_100 ;
V_219 [ V_220 ] . V_51 = V_2 -> V_146 [ V_92 + V_220 ] ;
V_219 [ V_220 ] . V_55 = V_107 ;
}
V_17 = F_10 ( V_5 , V_219 , V_37 ) ;
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
F_86 ( V_221 , V_224 , 0 ) ;
F_87 ( V_5 , & V_221 , V_225 , V_133 ) ;
F_57 ( & V_2 -> V_95 ) ;
}
static void F_88 ( struct V_208 * V_209 )
{
struct V_1 * V_2 = F_82 ( V_209 , struct V_1 , V_36 ) ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_217 V_115 ;
if ( ! F_89 ( V_5 , & V_115 , V_107 ) ) {
F_84 ( V_2 , & V_115 ) ;
F_90 ( V_5 , & V_115 ) ;
}
}
static void F_91 ( struct V_6 * V_5 )
{
F_45 ( V_5 , V_226 , V_5 -> V_70 ,
L_20
L_21 ) ;
V_5 -> V_21 = 0 ;
}
static int F_92 ( struct V_227 * V_33 )
{
V_33 -> V_5 -> V_32 = V_33 ;
return 0 ;
}
static void
F_93 ( struct V_227 * V_33 , char * V_115 , T_2 V_222 )
{
snprintf ( V_115 , V_222 , L_22 , V_33 -> V_5 -> V_228 ) ;
}
void F_94 ( struct V_6 * V_5 )
{
unsigned V_37 ;
if ( ! V_229 )
return;
if ( F_3 ( V_5 , false , & V_5 -> V_14 , & V_37 ) )
return;
if ( V_37 > 0 && V_37 > V_229 )
V_37 = V_229 ;
V_5 -> V_21 = V_37 ;
V_5 -> V_230 [ V_231 ] = & V_232 ;
}
static void F_95 ( struct V_208 * V_233 )
{
struct V_6 * V_5 = F_82 ( V_233 , struct V_6 , V_86 ) ;
struct V_87 * V_87 = V_5 -> V_87 . V_72 ;
struct V_1 * V_2 ;
struct V_234 * V_235 ;
struct V_236 * V_237 ;
struct V_90 * V_91 ;
struct V_238 V_239 ;
unsigned int V_240 ;
unsigned int V_241 ;
unsigned int V_92 ;
F_56 ( & V_5 -> V_207 ) ;
F_96 ( & V_239 ) ;
F_97 ( & V_5 -> V_242 , & V_239 ) ;
V_237 = V_87 -> V_243 + 1 ;
V_240 = F_34 ( V_87 -> V_243 ) - 1 ;
V_241 = 1 ;
for ( V_92 = 0 ; V_92 < V_5 -> V_21 ; ++ V_92 ) {
V_2 = V_5 -> V_2 + V_92 ;
F_56 ( & V_2 -> V_95 ) ;
if ( V_2 -> V_82 && ! F_19 ( V_2 -> V_72 . V_73 ) ) {
* V_237 ++ = V_2 -> V_72 ;
++ V_241 ;
-- V_240 ;
F_23 ( V_240 == 0 ) ;
}
F_57 ( & V_2 -> V_95 ) ;
}
F_33 (local_addr, &efx->local_addr_list, link) {
memcpy ( V_237 -> V_73 , V_235 -> V_72 , V_244 ) ;
V_237 -> V_78 = 0 ;
++ V_237 ;
++ V_241 ;
if ( -- V_240 == 0 ) {
if ( F_98 ( & V_239 ) ) {
V_91 = F_66 ( sizeof( * V_91 ) , V_45 ) ;
if ( ! V_91 )
break;
V_91 -> V_221 = F_99 (
& V_5 -> V_102 -> V_245 , V_107 ,
& V_91 -> V_72 , V_45 ) ;
if ( ! V_91 -> V_221 ) {
F_15 ( V_91 ) ;
break;
}
} else {
V_91 = F_100 (
& V_239 , struct V_90 , V_246 ) ;
F_101 ( & V_91 -> V_246 ) ;
}
F_102 ( & V_91 -> V_246 , & V_5 -> V_242 ) ;
V_237 = (struct V_236 * ) V_91 -> V_221 ;
V_240 = V_107 / sizeof( struct V_236 ) ;
}
}
V_87 -> V_241 = V_241 ;
F_57 ( & V_5 -> V_207 ) ;
while ( ! F_98 ( & V_239 ) ) {
V_91 = F_100 (
& V_239 , struct V_90 , V_246 ) ;
F_101 ( & V_91 -> V_246 ) ;
F_103 ( & V_5 -> V_102 -> V_245 , V_107 ,
V_91 -> V_221 , V_91 -> V_72 ) ;
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
static void F_104 ( struct V_6 * V_5 )
{
struct V_234 * V_235 ;
struct V_90 * V_91 ;
while ( ! F_98 ( & V_5 -> V_247 ) ) {
V_235 = F_100 ( & V_5 -> V_247 ,
struct V_234 , V_246 ) ;
F_101 ( & V_235 -> V_246 ) ;
F_15 ( V_235 ) ;
}
while ( ! F_98 ( & V_5 -> V_242 ) ) {
V_91 = F_100 ( & V_5 -> V_242 ,
struct V_90 , V_246 ) ;
F_101 ( & V_91 -> V_246 ) ;
F_103 ( & V_5 -> V_102 -> V_245 , V_107 ,
V_91 -> V_221 , V_91 -> V_72 ) ;
F_15 ( V_91 ) ;
}
}
static int F_105 ( struct V_6 * V_5 )
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
F_106 ( & V_2 -> V_36 , F_81 ) ;
F_106 ( & V_2 -> V_248 , F_88 ) ;
F_107 ( & V_2 -> V_193 ) ;
F_108 ( & V_2 -> V_95 ) ;
F_108 ( & V_2 -> V_168 ) ;
}
return 0 ;
}
static void F_109 ( struct V_6 * V_5 )
{
struct V_1 * V_2 ;
unsigned int V_92 ;
for ( V_92 = 0 ; V_92 < V_5 -> V_21 ; ++ V_92 ) {
V_2 = V_5 -> V_2 + V_92 ;
F_90 ( V_5 , & V_2 -> V_115 ) ;
F_15 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
V_2 -> V_105 = 0 ;
V_2 -> V_147 = 0 ;
}
}
static int F_110 ( struct V_6 * V_5 )
{
struct V_102 * V_102 = V_5 -> V_102 ;
unsigned V_3 , V_103 , V_249 , V_194 ;
T_5 V_114 , V_250 ;
struct V_1 * V_2 ;
int V_17 ;
V_249 = F_111 ( V_102 , V_251 ) ;
if ( ! V_249 )
return - V_252 ;
F_112 ( V_102 , V_249 + V_253 , & V_114 ) ;
F_112 ( V_102 , V_249 + V_254 , & V_250 ) ;
V_194 = V_5 -> V_255 ;
V_103 = V_102 -> V_103 + V_114 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_21 ; ++ V_3 ) {
V_2 = V_5 -> V_2 + V_3 ;
V_2 -> V_194 = V_194 ;
V_194 += V_195 * F_2 ( V_5 ) ;
V_2 -> V_100 = V_103 ;
snprintf ( V_2 -> V_71 , sizeof( V_2 -> V_71 ) ,
L_23 ,
F_113 ( V_102 -> V_256 ) , V_102 -> V_256 -> V_257 ,
F_114 ( V_103 ) , F_115 ( V_103 ) ) ;
V_17 = F_89 ( V_5 , & V_2 -> V_115 , V_107 ) ;
if ( V_17 )
goto V_258;
V_103 += V_250 ;
}
return 0 ;
V_258:
F_109 ( V_5 ) ;
return V_17 ;
}
int F_116 ( struct V_6 * V_5 )
{
struct V_259 * V_70 = V_5 -> V_70 ;
struct V_87 * V_87 ;
int V_17 ;
F_117 ( V_260 + 1 >= V_4 ) ;
F_117 ( V_4 & ( ( 1 << V_26 ) - 1 ) ) ;
if ( V_5 -> V_21 == 0 )
return 0 ;
V_17 = F_3 ( V_5 , true , NULL , NULL ) ;
if ( V_17 )
goto V_261;
V_17 = F_89 ( V_5 , & V_5 -> V_87 , sizeof( * V_87 ) ) ;
if ( V_17 )
goto V_262;
V_87 = V_5 -> V_87 . V_72 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_101 = 1 ;
V_87 -> V_55 = sizeof( * V_87 ) ;
V_87 -> V_263 = V_76 ;
V_87 -> V_14 = V_5 -> V_14 ;
V_87 -> V_264 = V_5 -> V_265 ;
V_87 -> V_241 = 1 + V_5 -> V_21 ;
V_87 -> V_266 = V_5 -> V_266 ;
V_17 = F_105 ( V_5 ) ;
if ( V_17 )
goto V_267;
F_108 ( & V_5 -> V_207 ) ;
F_106 ( & V_5 -> V_86 , F_95 ) ;
F_96 ( & V_5 -> V_247 ) ;
F_96 ( & V_5 -> V_242 ) ;
V_17 = F_110 ( V_5 ) ;
if ( V_17 )
goto V_268;
F_67 () ;
memcpy ( V_87 -> V_243 [ 0 ] . V_73 ,
V_70 -> V_269 , V_244 ) ;
V_5 -> V_128 = V_5 -> V_21 ;
F_69 () ;
F_7 ( V_5 , true ) ;
V_17 = F_118 ( V_5 -> V_102 , V_5 -> V_21 ) ;
if ( V_17 )
goto V_270;
F_119 ( V_5 , V_271 , V_70 ,
L_24 ,
V_5 -> V_21 , F_2 ( V_5 ) ) ;
return 0 ;
V_270:
F_7 ( V_5 , false ) ;
F_67 () ;
V_5 -> V_128 = 0 ;
F_69 () ;
F_109 ( V_5 ) ;
V_268:
F_120 ( & V_5 -> V_86 ) ;
F_104 ( V_5 ) ;
F_15 ( V_5 -> V_2 ) ;
V_267:
F_90 ( V_5 , & V_5 -> V_87 ) ;
V_262:
F_3 ( V_5 , false , NULL , NULL ) ;
V_261:
return V_17 ;
}
void F_121 ( struct V_6 * V_5 )
{
struct V_1 * V_2 ;
unsigned int V_92 ;
if ( V_5 -> V_128 == 0 )
return;
F_23 ( V_5 -> V_32 -> V_28 ) ;
F_7 ( V_5 , false ) ;
F_67 () ;
V_5 -> V_128 = 0 ;
F_69 () ;
for ( V_92 = 0 ; V_92 < V_5 -> V_21 ; ++ V_92 ) {
V_2 = V_5 -> V_2 + V_92 ;
F_120 ( & V_2 -> V_36 ) ;
F_120 ( & V_2 -> V_248 ) ;
}
F_120 ( & V_5 -> V_86 ) ;
F_122 ( V_5 -> V_102 ) ;
F_109 ( V_5 ) ;
F_104 ( V_5 ) ;
F_15 ( V_5 -> V_2 ) ;
F_90 ( V_5 , & V_5 -> V_87 ) ;
F_3 ( V_5 , false , NULL , NULL ) ;
}
void F_123 ( struct V_227 * V_33 , T_6 * V_94 )
{
struct V_6 * V_5 = V_33 -> V_5 ;
struct V_1 * V_2 ;
unsigned V_272 , V_273 , type , V_233 ;
V_272 = F_124 ( * V_94 , V_274 ) ;
F_117 ( V_275 != 0 ) ;
V_273 = F_124 ( * V_94 , V_110 ) ;
type = F_124 ( * V_94 , V_112 ) ;
V_233 = F_124 ( * V_94 , V_276 ) ;
F_125 ( V_5 , V_69 , V_5 -> V_70 ,
L_25 ,
V_272 , V_273 , type , V_233 ) ;
if ( F_41 ( V_5 , V_272 , & V_2 , NULL ) )
return;
if ( V_2 -> V_211 )
goto error;
if ( type == V_277 ) {
V_2 -> V_278 = V_277 ;
V_2 -> V_279 = V_273 + 1 ;
V_2 -> V_210 = 0 ;
} else if ( V_273 != ( V_2 -> V_279 ++ & 0xff ) || type != V_2 -> V_278 )
goto error;
switch ( V_2 -> V_278 ) {
case V_277 :
case V_280 :
case V_281 :
V_2 -> V_210 |= ( T_7 ) V_233 << ( V_2 -> V_278 << 4 ) ;
++ V_2 -> V_278 ;
return;
case V_282 :
V_2 -> V_210 |= ( T_7 ) V_233 << 48 ;
V_2 -> V_278 = V_277 ;
V_2 -> V_211 = true ;
F_29 ( V_85 , & V_2 -> V_36 ) ;
return;
}
error:
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_26 ,
V_2 -> V_71 ) ;
V_2 -> V_278 = V_277 ;
V_2 -> V_279 = V_273 + 1 ;
}
void F_126 ( struct V_6 * V_5 , unsigned V_127 )
{
struct V_1 * V_2 ;
if ( V_127 > V_5 -> V_128 )
return;
V_2 = V_5 -> V_2 + V_127 ;
F_119 ( V_5 , V_69 , V_5 -> V_70 ,
L_27 , V_2 -> V_71 ) ;
V_2 -> V_96 = 0 ;
F_77 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_147 = 0 ;
}
void F_127 ( struct V_6 * V_5 )
{
struct V_87 * V_87 = V_5 -> V_87 . V_72 ;
if ( ! V_5 -> V_128 )
return;
memcpy ( V_87 -> V_243 [ 0 ] . V_73 ,
V_5 -> V_70 -> V_269 , V_244 ) ;
F_29 ( V_85 , & V_5 -> V_86 ) ;
}
void F_128 ( struct V_6 * V_5 , T_6 * V_94 )
{
struct V_1 * V_2 ;
unsigned V_283 , V_272 ;
V_283 = F_124 ( * V_94 , V_284 ) ;
if ( F_41 ( V_5 , V_283 , & V_2 , & V_272 ) )
return;
if ( ! F_70 ( V_272 , V_2 -> V_169 ) )
return;
F_129 ( V_272 , V_2 -> V_169 ) ;
-- V_2 -> V_170 ;
if ( F_60 ( V_2 ) )
F_130 ( & V_2 -> V_193 ) ;
}
void F_131 ( struct V_6 * V_5 , T_6 * V_94 )
{
struct V_1 * V_2 ;
unsigned V_285 , V_283 , V_272 ;
V_283 = F_124 ( * V_94 , V_286 ) ;
V_285 = F_124 ( * V_94 ,
V_287 ) ;
if ( F_41 ( V_5 , V_283 , & V_2 , & V_272 ) )
return;
if ( ! F_70 ( V_272 , V_2 -> V_154 ) )
return;
if ( V_285 ) {
F_132 ( V_272 , V_2 -> V_181 ) ;
F_133 ( & V_2 -> V_180 ) ;
} else {
F_129 ( V_272 , V_2 -> V_154 ) ;
-- V_2 -> V_155 ;
}
if ( F_60 ( V_2 ) )
F_130 ( & V_2 -> V_193 ) ;
}
void F_134 ( struct V_6 * V_5 , unsigned V_288 )
{
struct V_1 * V_2 ;
unsigned int V_289 ;
if ( F_41 ( V_5 , V_288 , & V_2 , & V_289 ) )
return;
if ( F_44 () )
F_45 ( V_5 , V_69 , V_5 -> V_70 ,
L_28 ,
V_2 -> V_3 , V_289 ) ;
F_29 ( V_85 , & V_2 -> V_248 ) ;
}
void F_135 ( struct V_6 * V_5 )
{
unsigned int V_127 ;
struct V_217 V_115 ;
struct V_1 * V_2 ;
F_136 () ;
if ( V_5 -> V_128 == 0 )
return;
F_7 ( V_5 , true ) ;
( void ) F_3 ( V_5 , true , NULL , NULL ) ;
if ( F_89 ( V_5 , & V_115 , V_107 ) )
return;
for ( V_127 = 0 ; V_127 < V_5 -> V_128 ; ++ V_127 ) {
V_2 = V_5 -> V_2 + V_127 ;
F_84 ( V_2 , & V_115 ) ;
}
F_90 ( V_5 , & V_115 ) ;
}
int F_137 ( void )
{
V_85 = F_138 ( L_29 ) ;
if ( ! V_85 )
return - V_46 ;
return 0 ;
}
void F_139 ( void )
{
F_140 ( V_85 ) ;
}
int F_141 ( struct V_259 * V_70 , int V_127 , T_1 * V_290 )
{
struct V_6 * V_5 = F_142 ( V_70 ) ;
struct V_1 * V_2 ;
if ( V_127 >= V_5 -> V_128 )
return - V_291 ;
V_2 = V_5 -> V_2 + V_127 ;
F_56 ( & V_2 -> V_95 ) ;
memcpy ( V_2 -> V_72 . V_73 , V_290 , V_244 ) ;
F_28 ( V_2 ) ;
F_57 ( & V_2 -> V_95 ) ;
return 0 ;
}
int F_143 ( struct V_259 * V_70 , int V_127 ,
T_5 V_66 , T_1 V_292 )
{
struct V_6 * V_5 = F_142 ( V_70 ) ;
struct V_1 * V_2 ;
T_5 V_78 ;
if ( V_127 >= V_5 -> V_128 )
return - V_291 ;
V_2 = V_5 -> V_2 + V_127 ;
F_56 ( & V_2 -> V_95 ) ;
V_78 = ( V_66 & V_79 ) | ( ( V_292 & 0x7 ) << V_293 ) ;
V_2 -> V_72 . V_78 = F_144 ( V_78 ) ;
F_28 ( V_2 ) ;
F_57 ( & V_2 -> V_95 ) ;
return 0 ;
}
int F_145 ( struct V_259 * V_70 , int V_127 ,
bool V_294 )
{
struct V_6 * V_5 = F_142 ( V_70 ) ;
struct V_1 * V_2 ;
int V_17 ;
if ( V_127 >= V_5 -> V_128 )
return - V_291 ;
V_2 = V_5 -> V_2 + V_127 ;
F_56 ( & V_2 -> V_168 ) ;
if ( V_2 -> V_170 == 0 ) {
V_2 -> V_74 =
V_294 ? V_77 : V_295 ;
V_17 = 0 ;
} else {
V_17 = - V_296 ;
}
F_57 ( & V_2 -> V_168 ) ;
return V_17 ;
}
int F_146 ( struct V_259 * V_70 , int V_127 ,
struct V_297 * V_298 )
{
struct V_6 * V_5 = F_142 ( V_70 ) ;
struct V_1 * V_2 ;
T_5 V_78 ;
if ( V_127 >= V_5 -> V_128 )
return - V_291 ;
V_2 = V_5 -> V_2 + V_127 ;
V_298 -> V_2 = V_127 ;
memcpy ( V_298 -> V_290 , V_2 -> V_72 . V_73 , V_244 ) ;
V_298 -> V_299 = 0 ;
V_78 = F_20 ( V_2 -> V_72 . V_78 ) ;
V_298 -> V_66 = V_78 & V_79 ;
V_298 -> V_292 = ( V_78 >> V_293 ) & 0x7 ;
V_298 -> V_294 = V_2 -> V_74 == V_77 ;
return 0 ;
}
