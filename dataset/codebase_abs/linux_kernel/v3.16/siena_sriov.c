static unsigned F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return V_4 + V_2 -> V_3 * F_2 ( V_2 -> V_5 ) + V_3 ;
}
static int F_3 ( struct V_6 * V_5 , bool V_7 ,
unsigned * V_8 , unsigned * V_9 )
{
F_4 ( V_10 , V_11 ) ;
F_4 ( V_12 , V_13 ) ;
unsigned V_14 , V_15 ;
T_1 V_16 ;
int V_17 ;
F_5 ( V_10 , V_18 , V_7 ? 1 : 0 ) ;
F_5 ( V_10 , V_19 , V_4 ) ;
F_5 ( V_10 , V_20 , V_5 -> V_21 ) ;
V_17 = F_6 ( V_5 , V_22 , V_10 , V_11 ,
V_12 , V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
if ( V_16 < V_13 )
return - V_23 ;
V_15 = F_7 ( V_12 , V_24 ) ;
V_14 = F_7 ( V_12 , V_25 ) ;
if ( V_14 > V_26 )
return - V_27 ;
if ( V_8 )
* V_8 = V_14 ;
if ( V_9 )
* V_9 = V_15 ;
return 0 ;
}
static void F_8 ( struct V_6 * V_5 , bool V_28 )
{
T_2 V_29 ;
F_9 ( V_29 ,
V_30 , V_28 ? 0 : 1 ,
V_31 , V_5 -> V_32 -> V_33 ) ;
F_10 ( V_5 , & V_29 , V_34 ) ;
}
static int F_11 ( struct V_6 * V_5 , struct V_35 * V_36 ,
unsigned int V_37 )
{
F_4 ( V_10 , V_38 ) ;
F_12 ( V_39 ) ;
unsigned int V_3 , V_40 ;
T_3 V_41 ;
T_4 V_42 ;
int V_17 ;
F_13 () ;
if ( F_14 ( V_37 > V_43 ) )
return - V_44 ;
V_40 = F_15 ( V_37 ) ;
for ( V_3 = 0 ; V_3 < V_37 ; V_3 ++ ) {
V_39 = F_16 ( V_10 , V_45 , V_3 ) ;
F_5 ( V_39 , V_46 ,
V_37 ) ;
F_5 ( V_39 , V_47 ,
V_36 -> V_48 ) ;
F_17 ( V_39 , V_49 ,
V_36 -> V_50 ) ;
if ( V_36 -> V_51 == NULL ) {
V_42 = V_36 -> V_42 ;
V_41 = V_36 -> V_41 ;
} else {
if ( F_14 ( V_40 + V_36 -> V_52 >
V_38 ) ) {
V_17 = - V_44 ;
goto V_53;
}
V_42 = V_54 ;
V_41 = V_40 ;
memcpy ( F_18 ( V_10 , V_40 ) , V_36 -> V_51 ,
V_36 -> V_52 ) ;
V_40 += V_36 -> V_52 ;
}
F_5 ( V_39 , V_55 , V_42 ) ;
F_17 ( V_39 , V_56 ,
V_41 ) ;
F_5 ( V_39 , V_57 ,
V_36 -> V_52 ) ;
++ V_36 ;
}
V_17 = F_6 ( V_5 , V_58 , V_10 , V_40 , NULL , 0 , NULL ) ;
V_53:
F_13 () ;
return V_17 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_59 V_60 ;
T_5 V_61 ;
int V_17 ;
if ( V_2 -> V_62 != - 1 ) {
F_20 ( V_5 , V_63 ,
V_2 -> V_62 ) ;
F_21 ( V_5 , V_64 , V_5 -> V_65 , L_1 ,
V_2 -> V_66 , V_2 -> V_62 ) ;
V_2 -> V_62 = - 1 ;
}
if ( F_22 ( V_2 -> V_67 . V_68 ) )
return;
if ( V_2 -> V_69 == V_70 && V_71 <= 2 )
V_2 -> V_69 = V_72 ;
V_61 = F_23 ( V_2 -> V_67 . V_73 ) & V_74 ;
F_24 ( & V_60 , F_1 ( V_2 , 0 ) ) ;
V_17 = F_25 ( & V_60 ,
V_61 ? V_61 : V_75 ,
V_2 -> V_67 . V_68 ) ;
F_26 ( V_17 ) ;
V_17 = F_27 ( V_5 , & V_60 , true ) ;
if ( V_17 < 0 ) {
F_28 ( V_5 , V_64 , V_5 -> V_65 ,
L_2 ,
V_2 -> V_66 ) ;
} else {
F_21 ( V_5 , V_64 , V_5 -> V_65 , L_3 ,
V_2 -> V_66 , V_17 ) ;
V_2 -> V_62 = V_17 ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_59 V_60 ;
T_5 V_61 ;
int V_17 ;
if ( V_2 -> V_76 != - 1 ) {
F_20 ( V_5 , V_63 ,
V_2 -> V_76 ) ;
F_21 ( V_5 , V_64 , V_5 -> V_65 , L_4 ,
V_2 -> V_66 , V_2 -> V_76 ) ;
V_2 -> V_76 = - 1 ;
}
if ( ! V_2 -> V_77 || F_22 ( V_2 -> V_67 . V_68 ) )
return;
V_61 = F_23 ( V_2 -> V_67 . V_73 ) & V_74 ;
F_30 ( & V_60 , V_63 ,
V_2 -> V_78 ,
F_1 ( V_2 , V_2 -> V_79 ) ) ;
V_17 = F_25 ( & V_60 ,
V_61 ? V_61 : V_75 ,
V_2 -> V_67 . V_68 ) ;
F_26 ( V_17 ) ;
V_17 = F_27 ( V_5 , & V_60 , true ) ;
if ( V_17 < 0 ) {
F_28 ( V_5 , V_64 , V_5 -> V_65 ,
L_5 ,
V_2 -> V_66 ) ;
} else {
F_21 ( V_5 , V_64 , V_5 -> V_65 , L_6 ,
V_2 -> V_66 , V_17 ) ;
V_2 -> V_76 = V_17 ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_29 ( V_2 ) ;
F_32 ( V_80 , & V_2 -> V_5 -> V_81 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_82 * V_83 = V_5 -> V_82 . V_67 ;
struct V_35 V_84 [ 4 ] ;
struct V_85 * V_86 ;
unsigned int V_87 , V_37 ;
unsigned V_88 ;
T_6 V_89 ;
F_14 ( ! F_34 ( & V_2 -> V_90 ) ) ;
F_14 ( ! V_2 -> V_91 ) ;
V_83 -> V_92 = V_2 -> V_67 ;
V_83 -> V_93 = ++ V_83 -> V_94 ;
memset ( V_84 , '\0' , sizeof( V_84 ) ) ;
V_84 [ 0 ] . V_51 = & V_83 -> V_94 ;
V_84 [ 0 ] . V_48 = V_2 -> V_95 ;
V_84 [ 0 ] . V_50 = V_2 -> V_91 + F_35 ( struct V_82 ,
V_94 ) ;
V_84 [ 0 ] . V_52 = sizeof( V_83 -> V_94 ) ;
V_88 = F_35 ( struct V_82 , V_96 ) ;
V_84 [ 1 ] . V_42 = V_5 -> V_97 -> V_98 ;
V_84 [ 1 ] . V_41 = V_5 -> V_82 . V_99 + V_88 ;
V_84 [ 1 ] . V_48 = V_2 -> V_95 ;
V_84 [ 1 ] . V_50 = V_2 -> V_91 + V_88 ;
V_84 [ 1 ] . V_52 = V_83 -> V_52 - V_88 ;
V_87 = 2 ;
V_37 = 0 ;
F_36 (epp, &efx->local_page_list, link) {
if ( V_37 == V_2 -> V_100 ) {
break;
}
V_84 [ V_87 ] . V_51 = NULL ;
V_84 [ V_87 ] . V_42 = V_5 -> V_97 -> V_98 ;
V_84 [ V_87 ] . V_41 = V_86 -> V_67 ;
V_84 [ V_87 ] . V_48 = V_2 -> V_95 ;
V_84 [ V_87 ] . V_50 = V_2 -> V_101 [ V_37 ] ;
V_84 [ V_87 ] . V_52 = V_102 ;
if ( ++ V_87 == F_37 ( V_84 ) ) {
F_11 ( V_5 , V_84 , F_37 ( V_84 ) ) ;
V_87 = 0 ;
}
++ V_37 ;
}
V_84 [ V_87 ] . V_51 = & V_83 -> V_93 ;
V_84 [ V_87 ] . V_48 = V_2 -> V_95 ;
V_84 [ V_87 ] . V_50 = V_2 -> V_91 + F_35 ( struct V_82 ,
V_93 ) ;
V_84 [ V_87 ] . V_52 = sizeof( V_83 -> V_93 ) ;
F_11 ( V_5 , V_84 , V_87 + 1 ) ;
F_38 ( V_89 ,
V_103 , V_104 ,
V_105 , ( V_2 -> V_106 & 0xff ) ,
V_107 , V_108 ) ;
++ V_2 -> V_106 ;
F_39 ( V_5 ,
V_4 + V_2 -> V_3 * F_2 ( V_5 ) ,
& V_89 ) ;
}
static void F_40 ( struct V_6 * V_5 , unsigned V_109 ,
T_3 * V_67 , unsigned V_37 )
{
T_6 V_110 ;
unsigned V_87 ;
for ( V_87 = 0 ; V_87 < V_37 ; ++ V_87 ) {
F_38 ( V_110 ,
V_111 , 0 ,
V_112 ,
V_67 ? V_67 [ V_87 ] >> 12 : 0 ,
V_113 , 0 ) ;
F_41 ( V_5 , V_5 -> V_114 + V_115 ,
& V_110 , V_109 + V_87 ) ;
}
}
static bool F_42 ( struct V_6 * V_5 , unsigned V_3 )
{
return V_3 >= F_2 ( V_5 ) ;
}
static bool F_43 ( unsigned V_116 , unsigned V_117 )
{
unsigned V_118 = V_117 *
sizeof( T_6 ) / V_119 ;
return ( ( V_116 & ( V_116 - 1 ) ) || V_116 > V_118 ) ;
}
static bool F_44 ( struct V_6 * V_5 , unsigned F_1 ,
struct V_1 * * V_120 , unsigned * V_121 )
{
unsigned V_122 ;
if ( F_1 < V_4 )
return true ;
V_122 = ( F_1 - V_4 ) / F_2 ( V_5 ) ;
if ( V_122 >= V_5 -> V_123 )
return true ;
if ( V_120 )
* V_120 = V_5 -> V_2 + V_122 ;
if ( V_121 )
* V_121 = F_1 % F_2 ( V_5 ) ;
return false ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_124 * V_36 = V_2 -> V_110 . V_67 ;
unsigned V_125 = V_36 -> V_126 . V_127 . V_3 ;
unsigned V_116 = V_36 -> V_126 . V_127 . V_116 ;
unsigned V_128 = F_1 ( V_2 , V_125 ) ;
unsigned V_129 = F_46 ( V_2 , V_125 ) ;
T_2 V_29 ;
if ( F_42 ( V_5 , V_125 ) ||
F_43 ( V_116 , V_130 ) ) {
if ( F_47 () )
F_48 ( V_5 , V_64 , V_5 -> V_65 ,
L_7 ,
V_2 -> V_66 , V_125 , V_116 ) ;
return V_131 ;
}
F_40 ( V_5 , V_129 , V_36 -> V_126 . V_127 . V_67 , V_116 ) ;
F_49 ( V_29 ,
V_132 , 1 ,
V_133 , 0 ,
V_134 , V_135 ) ;
F_50 ( V_5 , & V_29 , V_136 , V_128 ) ;
F_49 ( V_29 ,
V_137 , 1 ,
V_138 , F_51 ( V_116 ) ,
V_139 , V_129 ) ;
F_50 ( V_5 , & V_29 , V_140 , V_128 ) ;
if ( V_125 == 0 ) {
memcpy ( V_2 -> V_141 , V_36 -> V_126 . V_127 . V_67 ,
V_116 * sizeof( T_3 ) ) ;
V_2 -> V_142 = V_116 ;
}
return V_143 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_124 * V_36 = V_2 -> V_110 . V_67 ;
unsigned V_144 = V_36 -> V_126 . V_145 . V_3 ;
unsigned V_125 = V_36 -> V_126 . V_145 . V_146 ;
unsigned V_116 = V_36 -> V_126 . V_145 . V_116 ;
unsigned V_129 = F_53 ( V_2 , V_144 ) ;
unsigned V_147 ;
T_2 V_29 ;
if ( F_42 ( V_5 , V_125 ) || F_42 ( V_5 , V_144 ) ||
V_144 >= V_148 ||
F_43 ( V_116 , V_149 ) ) {
if ( F_47 () )
F_48 ( V_5 , V_64 , V_5 -> V_65 ,
L_8
L_9 , V_2 -> V_66 , V_144 ,
V_125 , V_116 ) ;
return V_131 ;
}
if ( F_54 ( V_36 -> V_126 . V_145 . V_3 , V_2 -> V_150 ) )
++ V_2 -> V_151 ;
F_40 ( V_5 , V_129 , V_36 -> V_126 . V_145 . V_67 , V_116 ) ;
V_147 = V_36 -> V_126 . V_145 . V_147 & F_55 ( V_152 ) ;
F_56 ( V_29 ,
V_153 , V_129 ,
V_154 , F_1 ( V_2 , V_125 ) ,
V_152 , V_147 ,
V_155 , F_51 ( V_116 ) ,
V_156 ,
! ! ( V_36 -> V_126 . V_145 . V_157 &
V_158 ) ,
V_159 , 1 ) ;
F_50 ( V_5 , & V_29 , V_160 ,
F_1 ( V_2 , V_144 ) ) ;
return V_143 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_124 * V_36 = V_2 -> V_110 . V_67 ;
unsigned V_161 = V_36 -> V_126 . V_162 . V_3 ;
unsigned V_125 = V_36 -> V_126 . V_162 . V_146 ;
unsigned V_116 = V_36 -> V_126 . V_162 . V_116 ;
unsigned V_129 = F_58 ( V_2 , V_161 ) ;
unsigned V_147 , V_163 ;
T_2 V_29 ;
if ( F_42 ( V_5 , V_125 ) || F_42 ( V_5 , V_161 ) ||
V_161 >= V_71 ||
F_43 ( V_116 , V_149 ) ) {
if ( F_47 () )
F_48 ( V_5 , V_64 , V_5 -> V_65 ,
L_10
L_9 , V_2 -> V_66 , V_161 ,
V_125 , V_116 ) ;
return V_131 ;
}
F_59 ( & V_2 -> V_164 ) ;
if ( F_54 ( V_36 -> V_126 . V_162 . V_3 , V_2 -> V_165 ) )
++ V_2 -> V_166 ;
F_60 ( & V_2 -> V_164 ) ;
F_40 ( V_5 , V_129 , V_36 -> V_126 . V_162 . V_67 , V_116 ) ;
V_163 = V_2 -> V_69 == V_72 ;
V_147 = V_36 -> V_126 . V_162 . V_147 & F_55 ( V_167 ) ;
F_61 ( V_29 ,
V_168 , F_62 ( V_5 -> V_14 , 1U ) ,
V_169 , V_163 ,
V_170 , 1 ,
V_171 , V_129 ,
V_172 , F_1 ( V_2 , V_125 ) ,
V_167 , V_147 ,
V_173 , F_51 ( V_116 ) ,
V_174 , 1 ) ;
F_50 ( V_5 , & V_29 , V_175 ,
F_1 ( V_2 , V_161 ) ) ;
return V_143 ;
}
static bool F_63 ( struct V_1 * V_2 )
{
F_64 () ;
return ( ! V_2 -> V_166 && ! V_2 -> V_151 ) ||
F_65 ( & V_2 -> V_176 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_165 , 0 , sizeof( V_2 -> V_165 ) ) ;
V_2 -> V_166 = 0 ;
memset ( V_2 -> V_150 , 0 , sizeof( V_2 -> V_150 ) ) ;
V_2 -> V_151 = 0 ;
memset ( V_2 -> V_177 , 0 , sizeof( V_2 -> V_177 ) ) ;
F_67 ( & V_2 -> V_176 , 0 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
T_2 V_29 ;
unsigned V_37 = F_2 ( V_5 ) ;
unsigned V_178 = V_4 + V_2 -> V_3 * F_2 ( V_5 ) ;
unsigned V_179 = V_180 ;
unsigned V_3 , V_181 ;
F_4 ( V_10 , V_182 ) ;
int V_17 ;
F_69 ( V_148 >
V_183 ) ;
F_70 () ;
F_71 ( V_5 ) ;
F_72 () ;
V_181 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
if ( F_73 ( V_3 , V_2 -> V_165 ) ) {
F_9 ( V_29 ,
V_184 , 1 ,
V_185 ,
V_178 + V_3 ) ;
F_10 ( V_5 , & V_29 , V_186 ) ;
}
if ( F_73 ( V_3 , V_2 -> V_150 ) ) {
F_74 (
V_10 , V_187 ,
V_181 , V_178 + V_3 ) ;
V_181 ++ ;
}
}
F_67 ( & V_2 -> V_176 , 0 ) ;
while ( V_179 && ( V_2 -> V_151 || V_2 -> V_166 ) ) {
V_17 = F_6 ( V_5 , V_188 , V_10 ,
F_75 ( V_181 ) ,
NULL , 0 , NULL ) ;
F_14 ( V_17 < 0 ) ;
V_179 = F_76 ( V_2 -> V_189 ,
F_63 ( V_2 ) ,
V_179 ) ;
V_181 = 0 ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
if ( F_77 ( V_3 , V_2 -> V_177 ) ) {
F_78 ( & V_2 -> V_176 ) ;
F_74 (
V_10 , V_187 ,
V_181 , V_178 + V_3 ) ;
V_181 ++ ;
}
}
}
F_70 () ;
F_79 ( V_5 ) ;
F_72 () ;
F_80 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
F_50 ( V_5 , & V_29 , V_160 ,
V_178 + V_3 ) ;
F_50 ( V_5 , & V_29 , V_175 ,
V_178 + V_3 ) ;
F_50 ( V_5 , & V_29 , V_140 ,
V_178 + V_3 ) ;
F_50 ( V_5 , & V_29 , V_136 ,
V_178 + V_3 ) ;
}
F_40 ( V_5 , V_2 -> V_190 , NULL ,
V_191 * F_2 ( V_5 ) ) ;
F_66 ( V_2 ) ;
V_2 -> V_142 = 0 ;
return V_179 ? 0 : V_192 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_124 * V_36 = V_2 -> V_110 . V_67 ;
unsigned V_144 = V_36 -> V_126 . V_193 . V_194 ;
unsigned V_157 ;
if ( F_42 ( V_5 , V_144 ) || V_2 -> V_77 ) {
if ( F_47 () )
F_48 ( V_5 , V_64 , V_5 -> V_65 ,
L_11
L_12 , V_2 -> V_66 , V_144 ,
V_36 -> V_126 . V_193 . V_157 ) ;
return V_131 ;
}
V_157 = 0 ;
if ( V_36 -> V_126 . V_193 . V_157 & V_195 )
V_157 |= V_196 ;
if ( V_36 -> V_126 . V_193 . V_157 & V_197 )
V_157 |= V_198 ;
V_2 -> V_78 = V_157 ;
V_2 -> V_79 = V_144 ;
V_2 -> V_77 = true ;
F_29 ( V_2 ) ;
F_32 ( V_80 , & V_5 -> V_81 ) ;
return V_143 ;
}
static int F_82 ( struct V_1 * V_2 )
{
V_2 -> V_77 = false ;
F_29 ( V_2 ) ;
F_32 ( V_80 , & V_2 -> V_5 -> V_81 ) ;
return V_143 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_124 * V_36 = V_2 -> V_110 . V_67 ;
T_3 V_199 = V_36 -> V_126 . V_200 . V_100 ;
T_3 V_201 =
( V_102 -
F_35 ( struct V_124 , V_126 . V_200 . V_202 [ 0 ] ) )
/ sizeof( V_36 -> V_126 . V_200 . V_202 [ 0 ] ) ;
if ( ! V_36 -> V_126 . V_200 . V_99 || V_199 > V_201 ) {
if ( F_47 () )
F_48 ( V_5 , V_64 , V_5 -> V_65 ,
L_13 ,
V_2 -> V_66 ) ;
return V_131 ;
}
F_59 ( & V_5 -> V_203 ) ;
F_59 ( & V_2 -> V_90 ) ;
V_2 -> V_91 = V_36 -> V_126 . V_200 . V_99 ;
F_84 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
V_2 -> V_100 = 0 ;
if ( V_199 ) {
V_2 -> V_101 = F_85 ( V_199 , sizeof( T_3 ) ,
V_204 ) ;
if ( V_2 -> V_101 ) {
memcpy ( V_2 -> V_101 ,
V_36 -> V_126 . V_200 . V_202 ,
V_199 * sizeof( T_3 ) ) ;
V_2 -> V_100 = V_199 ;
}
}
F_33 ( V_2 ) ;
F_60 ( & V_2 -> V_90 ) ;
F_60 ( & V_5 -> V_203 ) ;
return V_143 ;
}
static int F_86 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_90 ) ;
V_2 -> V_91 = 0 ;
F_60 ( & V_2 -> V_90 ) ;
return V_143 ;
}
static void F_87 ( struct V_205 * V_206 )
{
struct V_1 * V_2 = F_88 ( V_206 , struct V_1 , V_36 ) ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_124 * V_36 = V_2 -> V_110 . V_67 ;
struct V_35 V_84 [ 2 ] ;
int V_17 ;
memset ( V_84 , '\0' , sizeof( V_84 ) ) ;
V_84 [ 0 ] . V_42 = V_2 -> V_95 ;
V_84 [ 0 ] . V_41 = V_2 -> V_207 ;
V_84 [ 0 ] . V_48 = V_5 -> V_97 -> V_98 ;
V_84 [ 0 ] . V_50 = V_2 -> V_110 . V_99 ;
V_84 [ 0 ] . V_52 = V_102 ;
V_17 = F_11 ( V_5 , V_84 , 1 ) ;
if ( V_17 ) {
if ( F_47 () )
F_48 ( V_5 , V_64 , V_5 -> V_65 ,
L_14 ,
V_2 -> V_66 , - V_17 ) ;
V_2 -> V_208 = false ;
return;
}
if ( V_36 -> V_209 < V_210 && V_211 [ V_36 -> V_209 ] != NULL ) {
V_17 = V_211 [ V_36 -> V_209 ] ( V_2 ) ;
if ( V_17 == 0 ) {
F_21 ( V_5 , V_64 , V_5 -> V_65 ,
L_15 ,
V_36 -> V_209 , V_2 -> V_66 ) ;
}
} else {
F_21 ( V_5 , V_64 , V_5 -> V_65 ,
L_16
L_17 , V_36 -> V_209 , V_2 -> V_66 ,
( unsigned long long ) V_2 -> V_207 ) ;
V_17 = V_212 ;
}
V_2 -> V_208 = false ;
F_89 () ;
V_36 -> V_17 = V_17 ;
V_36 -> V_209 = V_213 ;
memset ( V_84 , '\0' , sizeof( V_84 ) ) ;
V_84 [ 0 ] . V_51 = & V_36 -> V_17 ;
V_84 [ 0 ] . V_48 = V_2 -> V_95 ;
V_84 [ 0 ] . V_50 = V_2 -> V_207 + F_35 ( struct V_124 , V_17 ) ;
V_84 [ 0 ] . V_52 = sizeof( V_36 -> V_17 ) ;
V_84 [ 1 ] . V_51 = & V_36 -> V_209 ;
V_84 [ 1 ] . V_48 = V_2 -> V_95 ;
V_84 [ 1 ] . V_50 = V_2 -> V_207 + F_35 ( struct V_124 , V_209 ) ;
V_84 [ 1 ] . V_52 = sizeof( V_36 -> V_209 ) ;
( void ) F_11 ( V_5 , V_84 , F_37 ( V_84 ) ) ;
}
static void F_90 ( struct V_1 * V_2 , struct V_214 * V_215 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_35 V_216 [ 4 ] ;
T_6 V_89 ;
unsigned int V_87 , V_37 , V_217 , V_129 , V_128 ;
T_2 V_29 ;
T_7 V_218 ;
int V_17 ;
F_26 ( V_215 -> V_219 != V_102 ) ;
if ( ! V_2 -> V_142 )
return;
F_26 ( V_2 -> V_142 & ( V_2 -> V_142 - 1 ) ) ;
F_59 ( & V_2 -> V_90 ) ;
F_38 ( V_89 ,
V_103 , V_104 ,
V_105 , V_2 -> V_106 ,
V_107 , V_220 ) ;
V_2 -> V_106 ++ ;
for ( V_87 = 0 ; V_87 < V_102 ; V_87 += sizeof( V_89 ) )
memcpy ( V_215 -> V_67 + V_87 , & V_89 , sizeof( V_89 ) ) ;
for ( V_87 = 0 ; V_87 < V_2 -> V_142 ; V_87 += V_37 ) {
V_37 = F_91 ( unsigned , V_2 -> V_142 - V_87 ,
F_37 ( V_216 ) ) ;
for ( V_217 = 0 ; V_217 < V_37 ; V_217 ++ ) {
V_216 [ V_217 ] . V_51 = NULL ;
V_216 [ V_217 ] . V_42 = V_5 -> V_97 -> V_98 ;
V_216 [ V_217 ] . V_41 = V_215 -> V_99 ;
V_216 [ V_217 ] . V_48 = V_2 -> V_95 ;
V_216 [ V_217 ] . V_50 = V_2 -> V_141 [ V_87 + V_217 ] ;
V_216 [ V_217 ] . V_52 = V_102 ;
}
V_17 = F_11 ( V_5 , V_216 , V_37 ) ;
if ( V_17 ) {
if ( F_47 () )
F_48 ( V_5 , V_64 , V_5 -> V_65 ,
L_18
L_19 , V_2 -> V_66 , - V_17 ) ;
break;
}
}
V_128 = F_1 ( V_2 , 0 ) ;
V_129 = F_46 ( V_2 , 0 ) ;
F_40 ( V_5 , V_129 , V_2 -> V_141 , V_2 -> V_142 ) ;
F_49 ( V_29 ,
V_132 , 1 ,
V_133 , 0 ,
V_134 , V_135 ) ;
F_50 ( V_5 , & V_29 , V_136 , V_128 ) ;
F_49 ( V_29 ,
V_137 , 1 ,
V_138 , F_51 ( V_2 -> V_142 ) ,
V_139 , V_129 ) ;
F_50 ( V_5 , & V_29 , V_140 , V_128 ) ;
F_92 ( V_218 , V_221 , 0 ) ;
F_93 ( V_5 , & V_218 , V_222 + V_223 * V_128 ) ;
F_60 ( & V_2 -> V_90 ) ;
}
static void F_94 ( struct V_205 * V_206 )
{
struct V_1 * V_2 = F_88 ( V_206 , struct V_1 , V_36 ) ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_214 V_110 ;
if ( ! F_95 ( V_5 , & V_110 , V_102 , V_224 ) ) {
F_90 ( V_2 , & V_110 ) ;
F_96 ( V_5 , & V_110 ) ;
}
}
static void F_97 ( struct V_6 * V_5 )
{
F_48 ( V_5 , V_225 , V_5 -> V_65 ,
L_20
L_21 ) ;
V_5 -> V_21 = 0 ;
}
static int F_98 ( struct V_226 * V_33 )
{
V_33 -> V_5 -> V_32 = V_33 ;
return 0 ;
}
static void
F_99 ( struct V_226 * V_33 , char * V_110 , T_1 V_219 )
{
snprintf ( V_110 , V_219 , L_22 , V_33 -> V_5 -> V_227 ) ;
}
void F_100 ( struct V_6 * V_5 )
{
unsigned V_37 ;
if ( ! V_228 )
return;
if ( F_3 ( V_5 , false , & V_5 -> V_14 , & V_37 ) )
return;
if ( V_37 > 0 && V_37 > V_228 )
V_37 = V_228 ;
V_5 -> V_21 = V_37 ;
V_5 -> V_229 [ V_230 ] = & V_231 ;
}
static void F_101 ( struct V_205 * V_232 )
{
struct V_6 * V_5 = F_88 ( V_232 , struct V_6 , V_81 ) ;
struct V_82 * V_82 = V_5 -> V_82 . V_67 ;
struct V_1 * V_2 ;
struct V_233 * V_234 ;
struct V_235 * V_236 ;
struct V_85 * V_86 ;
struct V_237 V_238 ;
unsigned int V_239 ;
unsigned int V_240 ;
unsigned int V_87 ;
F_59 ( & V_5 -> V_203 ) ;
F_102 ( & V_238 ) ;
F_103 ( & V_5 -> V_241 , & V_238 ) ;
V_236 = V_82 -> V_242 + 1 ;
V_239 = F_37 ( V_82 -> V_242 ) - 1 ;
V_240 = 1 ;
for ( V_87 = 0 ; V_87 < V_5 -> V_21 ; ++ V_87 ) {
V_2 = V_5 -> V_2 + V_87 ;
F_59 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_77 && ! F_22 ( V_2 -> V_67 . V_68 ) ) {
* V_236 ++ = V_2 -> V_67 ;
++ V_240 ;
-- V_239 ;
F_26 ( V_239 == 0 ) ;
}
F_60 ( & V_2 -> V_90 ) ;
}
F_36 (local_addr, &efx->local_addr_list, link) {
F_104 ( V_236 -> V_68 , V_234 -> V_67 ) ;
V_236 -> V_73 = 0 ;
++ V_236 ;
++ V_240 ;
if ( -- V_239 == 0 ) {
if ( F_105 ( & V_238 ) ) {
V_86 = F_106 ( sizeof( * V_86 ) , V_204 ) ;
if ( ! V_86 )
break;
V_86 -> V_218 = F_107 (
& V_5 -> V_97 -> V_243 , V_102 ,
& V_86 -> V_67 , V_204 ) ;
if ( ! V_86 -> V_218 ) {
F_84 ( V_86 ) ;
break;
}
} else {
V_86 = F_108 (
& V_238 , struct V_85 , V_244 ) ;
F_109 ( & V_86 -> V_244 ) ;
}
F_110 ( & V_86 -> V_244 , & V_5 -> V_241 ) ;
V_236 = (struct V_235 * ) V_86 -> V_218 ;
V_239 = V_102 / sizeof( struct V_235 ) ;
}
}
V_82 -> V_240 = V_240 ;
F_60 ( & V_5 -> V_203 ) ;
while ( ! F_105 ( & V_238 ) ) {
V_86 = F_108 (
& V_238 , struct V_85 , V_244 ) ;
F_109 ( & V_86 -> V_244 ) ;
F_111 ( & V_5 -> V_97 -> V_243 , V_102 ,
V_86 -> V_218 , V_86 -> V_67 ) ;
F_84 ( V_86 ) ;
}
for ( V_87 = 0 ; V_87 < V_5 -> V_21 ; ++ V_87 ) {
V_2 = V_5 -> V_2 + V_87 ;
F_59 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_91 )
F_33 ( V_2 ) ;
F_60 ( & V_2 -> V_90 ) ;
}
}
static void F_112 ( struct V_6 * V_5 )
{
struct V_233 * V_234 ;
struct V_85 * V_86 ;
while ( ! F_105 ( & V_5 -> V_245 ) ) {
V_234 = F_108 ( & V_5 -> V_245 ,
struct V_233 , V_244 ) ;
F_109 ( & V_234 -> V_244 ) ;
F_84 ( V_234 ) ;
}
while ( ! F_105 ( & V_5 -> V_241 ) ) {
V_86 = F_108 ( & V_5 -> V_241 ,
struct V_85 , V_244 ) ;
F_109 ( & V_86 -> V_244 ) ;
F_111 ( & V_5 -> V_97 -> V_243 , V_102 ,
V_86 -> V_218 , V_86 -> V_67 ) ;
F_84 ( V_86 ) ;
}
}
static int F_113 ( struct V_6 * V_5 )
{
unsigned V_3 ;
struct V_1 * V_2 ;
V_5 -> V_2 = F_114 ( sizeof( struct V_1 ) * V_5 -> V_21 , V_204 ) ;
if ( ! V_5 -> V_2 )
return - V_246 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_21 ; ++ V_3 ) {
V_2 = V_5 -> V_2 + V_3 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_76 = - 1 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_62 = - 1 ;
F_115 ( & V_2 -> V_36 , F_87 ) ;
F_115 ( & V_2 -> V_247 , F_94 ) ;
F_116 ( & V_2 -> V_189 ) ;
F_117 ( & V_2 -> V_90 ) ;
F_117 ( & V_2 -> V_164 ) ;
}
return 0 ;
}
static void F_118 ( struct V_6 * V_5 )
{
struct V_1 * V_2 ;
unsigned int V_87 ;
for ( V_87 = 0 ; V_87 < V_5 -> V_21 ; ++ V_87 ) {
V_2 = V_5 -> V_2 + V_87 ;
F_96 ( V_5 , & V_2 -> V_110 ) ;
F_84 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
V_2 -> V_100 = 0 ;
V_2 -> V_142 = 0 ;
}
}
static int F_119 ( struct V_6 * V_5 )
{
struct V_97 * V_97 = V_5 -> V_97 ;
unsigned V_3 , V_98 , V_248 , V_190 ;
T_5 V_109 , V_249 ;
struct V_1 * V_2 ;
int V_17 ;
V_248 = F_120 ( V_97 , V_250 ) ;
if ( ! V_248 )
return - V_251 ;
F_121 ( V_97 , V_248 + V_252 , & V_109 ) ;
F_121 ( V_97 , V_248 + V_253 , & V_249 ) ;
V_190 = V_5 -> V_254 ;
V_98 = V_97 -> V_98 + V_109 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_21 ; ++ V_3 ) {
V_2 = V_5 -> V_2 + V_3 ;
V_2 -> V_190 = V_190 ;
V_190 += V_191 * F_2 ( V_5 ) ;
V_2 -> V_95 = V_98 ;
snprintf ( V_2 -> V_66 , sizeof( V_2 -> V_66 ) ,
L_23 ,
F_122 ( V_97 -> V_255 ) , V_97 -> V_255 -> V_256 ,
F_123 ( V_98 ) , F_124 ( V_98 ) ) ;
V_17 = F_95 ( V_5 , & V_2 -> V_110 , V_102 ,
V_204 ) ;
if ( V_17 )
goto V_257;
V_98 += V_249 ;
}
return 0 ;
V_257:
F_118 ( V_5 ) ;
return V_17 ;
}
int F_125 ( struct V_6 * V_5 )
{
struct V_258 * V_65 = V_5 -> V_65 ;
struct V_82 * V_82 ;
int V_17 ;
F_69 ( V_259 + 1 >= V_4 ) ;
F_69 ( V_4 & ( ( 1 << V_26 ) - 1 ) ) ;
if ( V_5 -> V_21 == 0 )
return 0 ;
V_17 = F_3 ( V_5 , true , NULL , NULL ) ;
if ( V_17 )
goto V_260;
V_17 = F_95 ( V_5 , & V_5 -> V_82 , sizeof( * V_82 ) ,
V_204 ) ;
if ( V_17 )
goto V_261;
V_82 = V_5 -> V_82 . V_67 ;
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
V_82 -> V_96 = 1 ;
V_82 -> V_52 = sizeof( * V_82 ) ;
V_82 -> V_262 = V_71 ;
V_82 -> V_14 = V_5 -> V_14 ;
V_82 -> V_263 = V_5 -> V_264 ;
V_82 -> V_240 = 1 + V_5 -> V_21 ;
V_82 -> V_265 = V_5 -> V_265 ;
V_17 = F_113 ( V_5 ) ;
if ( V_17 )
goto V_266;
F_117 ( & V_5 -> V_203 ) ;
F_115 ( & V_5 -> V_81 , F_101 ) ;
F_102 ( & V_5 -> V_245 ) ;
F_102 ( & V_5 -> V_241 ) ;
V_17 = F_119 ( V_5 ) ;
if ( V_17 )
goto V_267;
F_70 () ;
F_104 ( V_82 -> V_242 [ 0 ] . V_68 , V_65 -> V_268 ) ;
V_5 -> V_123 = V_5 -> V_21 ;
F_72 () ;
F_8 ( V_5 , true ) ;
V_17 = F_126 ( V_5 -> V_97 , V_5 -> V_21 ) ;
if ( V_17 )
goto V_269;
F_127 ( V_5 , V_270 , V_65 ,
L_24 ,
V_5 -> V_21 , F_2 ( V_5 ) ) ;
return 0 ;
V_269:
F_8 ( V_5 , false ) ;
F_70 () ;
V_5 -> V_123 = 0 ;
F_72 () ;
F_118 ( V_5 ) ;
V_267:
F_128 ( & V_5 -> V_81 ) ;
F_112 ( V_5 ) ;
F_84 ( V_5 -> V_2 ) ;
V_266:
F_96 ( V_5 , & V_5 -> V_82 ) ;
V_261:
F_3 ( V_5 , false , NULL , NULL ) ;
V_260:
return V_17 ;
}
void F_129 ( struct V_6 * V_5 )
{
struct V_1 * V_2 ;
unsigned int V_87 ;
if ( V_5 -> V_123 == 0 )
return;
F_26 ( V_5 -> V_32 -> V_28 ) ;
F_8 ( V_5 , false ) ;
F_70 () ;
V_5 -> V_123 = 0 ;
F_72 () ;
for ( V_87 = 0 ; V_87 < V_5 -> V_21 ; ++ V_87 ) {
V_2 = V_5 -> V_2 + V_87 ;
F_128 ( & V_2 -> V_36 ) ;
F_128 ( & V_2 -> V_247 ) ;
}
F_128 ( & V_5 -> V_81 ) ;
F_130 ( V_5 -> V_97 ) ;
F_118 ( V_5 ) ;
F_112 ( V_5 ) ;
F_84 ( V_5 -> V_2 ) ;
F_96 ( V_5 , & V_5 -> V_82 ) ;
F_3 ( V_5 , false , NULL , NULL ) ;
}
void F_131 ( struct V_226 * V_33 , T_6 * V_89 )
{
struct V_6 * V_5 = V_33 -> V_5 ;
struct V_1 * V_2 ;
unsigned V_271 , V_272 , type , V_232 ;
V_271 = F_132 ( * V_89 , V_273 ) ;
F_69 ( V_274 != 0 ) ;
V_272 = F_132 ( * V_89 , V_105 ) ;
type = F_132 ( * V_89 , V_107 ) ;
V_232 = F_132 ( * V_89 , V_275 ) ;
F_133 ( V_5 , V_64 , V_5 -> V_65 ,
L_25 ,
V_271 , V_272 , type , V_232 ) ;
if ( F_44 ( V_5 , V_271 , & V_2 , NULL ) )
return;
if ( V_2 -> V_208 )
goto error;
if ( type == V_276 ) {
V_2 -> V_277 = V_276 ;
V_2 -> V_278 = V_272 + 1 ;
V_2 -> V_207 = 0 ;
} else if ( V_272 != ( V_2 -> V_278 ++ & 0xff ) || type != V_2 -> V_277 )
goto error;
switch ( V_2 -> V_277 ) {
case V_276 :
case V_279 :
case V_280 :
V_2 -> V_207 |= ( T_3 ) V_232 << ( V_2 -> V_277 << 4 ) ;
++ V_2 -> V_277 ;
return;
case V_281 :
V_2 -> V_207 |= ( T_3 ) V_232 << 48 ;
V_2 -> V_277 = V_276 ;
V_2 -> V_208 = true ;
F_32 ( V_80 , & V_2 -> V_36 ) ;
return;
}
error:
if ( F_47 () )
F_48 ( V_5 , V_64 , V_5 -> V_65 ,
L_26 ,
V_2 -> V_66 ) ;
V_2 -> V_277 = V_276 ;
V_2 -> V_278 = V_272 + 1 ;
}
void F_134 ( struct V_6 * V_5 , unsigned V_122 )
{
struct V_1 * V_2 ;
if ( V_122 > V_5 -> V_123 )
return;
V_2 = V_5 -> V_2 + V_122 ;
F_127 ( V_5 , V_64 , V_5 -> V_65 ,
L_27 , V_2 -> V_66 ) ;
V_2 -> V_91 = 0 ;
F_82 ( V_2 ) ;
F_66 ( V_2 ) ;
V_2 -> V_142 = 0 ;
}
void F_135 ( struct V_6 * V_5 )
{
struct V_82 * V_82 = V_5 -> V_82 . V_67 ;
if ( ! V_5 -> V_123 )
return;
F_104 ( V_82 -> V_242 [ 0 ] . V_68 ,
V_5 -> V_65 -> V_268 ) ;
F_32 ( V_80 , & V_5 -> V_81 ) ;
}
void F_136 ( struct V_6 * V_5 , T_6 * V_89 )
{
struct V_1 * V_2 ;
unsigned V_282 , V_271 ;
V_282 = F_132 ( * V_89 , V_283 ) ;
if ( F_44 ( V_5 , V_282 , & V_2 , & V_271 ) )
return;
if ( ! F_73 ( V_271 , V_2 -> V_165 ) )
return;
F_137 ( V_271 , V_2 -> V_165 ) ;
-- V_2 -> V_166 ;
if ( F_63 ( V_2 ) )
F_138 ( & V_2 -> V_189 ) ;
}
void F_139 ( struct V_6 * V_5 , T_6 * V_89 )
{
struct V_1 * V_2 ;
unsigned V_284 , V_282 , V_271 ;
V_282 = F_132 ( * V_89 , V_285 ) ;
V_284 = F_132 ( * V_89 ,
V_286 ) ;
if ( F_44 ( V_5 , V_282 , & V_2 , & V_271 ) )
return;
if ( ! F_73 ( V_271 , V_2 -> V_150 ) )
return;
if ( V_284 ) {
F_140 ( V_271 , V_2 -> V_177 ) ;
F_141 ( & V_2 -> V_176 ) ;
} else {
F_137 ( V_271 , V_2 -> V_150 ) ;
-- V_2 -> V_151 ;
}
if ( F_63 ( V_2 ) )
F_138 ( & V_2 -> V_189 ) ;
}
void F_142 ( struct V_6 * V_5 , unsigned V_287 )
{
struct V_1 * V_2 ;
unsigned int V_288 ;
if ( F_44 ( V_5 , V_287 , & V_2 , & V_288 ) )
return;
if ( F_47 () )
F_48 ( V_5 , V_64 , V_5 -> V_65 ,
L_28 ,
V_2 -> V_3 , V_288 ) ;
F_32 ( V_80 , & V_2 -> V_247 ) ;
}
void F_143 ( struct V_6 * V_5 )
{
unsigned int V_122 ;
struct V_214 V_110 ;
struct V_1 * V_2 ;
F_144 () ;
if ( V_5 -> V_123 == 0 )
return;
F_8 ( V_5 , true ) ;
( void ) F_3 ( V_5 , true , NULL , NULL ) ;
if ( F_95 ( V_5 , & V_110 , V_102 , V_224 ) )
return;
for ( V_122 = 0 ; V_122 < V_5 -> V_123 ; ++ V_122 ) {
V_2 = V_5 -> V_2 + V_122 ;
F_90 ( V_2 , & V_110 ) ;
}
F_96 ( V_5 , & V_110 ) ;
}
int F_145 ( void )
{
V_80 = F_146 ( L_29 ) ;
if ( ! V_80 )
return - V_246 ;
return 0 ;
}
void F_147 ( void )
{
F_148 ( V_80 ) ;
}
int F_149 ( struct V_258 * V_65 , int V_122 , T_8 * V_289 )
{
struct V_6 * V_5 = F_150 ( V_65 ) ;
struct V_1 * V_2 ;
if ( V_122 >= V_5 -> V_123 )
return - V_290 ;
V_2 = V_5 -> V_2 + V_122 ;
F_59 ( & V_2 -> V_90 ) ;
F_104 ( V_2 -> V_67 . V_68 , V_289 ) ;
F_31 ( V_2 ) ;
F_60 ( & V_2 -> V_90 ) ;
return 0 ;
}
int F_151 ( struct V_258 * V_65 , int V_122 ,
T_5 V_61 , T_8 V_291 )
{
struct V_6 * V_5 = F_150 ( V_65 ) ;
struct V_1 * V_2 ;
T_5 V_73 ;
if ( V_122 >= V_5 -> V_123 )
return - V_290 ;
V_2 = V_5 -> V_2 + V_122 ;
F_59 ( & V_2 -> V_90 ) ;
V_73 = ( V_61 & V_74 ) | ( ( V_291 & 0x7 ) << V_292 ) ;
V_2 -> V_67 . V_73 = F_152 ( V_73 ) ;
F_31 ( V_2 ) ;
F_60 ( & V_2 -> V_90 ) ;
return 0 ;
}
int F_153 ( struct V_258 * V_65 , int V_122 ,
bool V_293 )
{
struct V_6 * V_5 = F_150 ( V_65 ) ;
struct V_1 * V_2 ;
int V_17 ;
if ( V_122 >= V_5 -> V_123 )
return - V_290 ;
V_2 = V_5 -> V_2 + V_122 ;
F_59 ( & V_2 -> V_164 ) ;
if ( V_2 -> V_166 == 0 ) {
V_2 -> V_69 =
V_293 ? V_72 : V_294 ;
V_17 = 0 ;
} else {
V_17 = - V_295 ;
}
F_60 ( & V_2 -> V_164 ) ;
return V_17 ;
}
int F_154 ( struct V_258 * V_65 , int V_122 ,
struct V_296 * V_297 )
{
struct V_6 * V_5 = F_150 ( V_65 ) ;
struct V_1 * V_2 ;
T_5 V_73 ;
if ( V_122 >= V_5 -> V_123 )
return - V_290 ;
V_2 = V_5 -> V_2 + V_122 ;
V_297 -> V_2 = V_122 ;
F_104 ( V_297 -> V_289 , V_2 -> V_67 . V_68 ) ;
V_297 -> V_298 = 0 ;
V_297 -> V_299 = 0 ;
V_73 = F_23 ( V_2 -> V_67 . V_73 ) ;
V_297 -> V_61 = V_73 & V_74 ;
V_297 -> V_291 = ( V_73 >> V_292 ) & 0x7 ;
V_297 -> V_293 = V_2 -> V_69 == V_72 ;
return 0 ;
}
