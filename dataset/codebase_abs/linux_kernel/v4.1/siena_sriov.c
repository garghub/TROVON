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
struct V_29 * V_30 = V_5 -> V_30 ;
T_2 V_31 ;
F_9 ( V_31 ,
V_32 , V_28 ? 0 : 1 ,
V_33 , V_30 -> V_34 -> V_35 ) ;
F_10 ( V_5 , & V_31 , V_36 ) ;
}
static int F_11 ( struct V_6 * V_5 ,
struct V_37 * V_38 ,
unsigned int V_39 )
{
F_4 ( V_10 , V_40 ) ;
F_12 ( V_41 ) ;
unsigned int V_3 , V_42 ;
T_3 V_43 ;
T_4 V_44 ;
int V_17 ;
F_13 () ;
if ( F_14 ( V_39 > V_45 ) )
return - V_46 ;
V_42 = F_15 ( V_39 ) ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) {
V_41 = F_16 ( V_10 , V_47 , V_3 ) ;
F_5 ( V_41 , V_48 ,
V_39 ) ;
F_5 ( V_41 , V_49 ,
V_38 -> V_50 ) ;
F_17 ( V_41 , V_51 ,
V_38 -> V_52 ) ;
if ( V_38 -> V_53 == NULL ) {
V_44 = V_38 -> V_44 ;
V_43 = V_38 -> V_43 ;
} else {
if ( F_14 ( V_42 + V_38 -> V_54 >
V_40 ) ) {
V_17 = - V_46 ;
goto V_55;
}
V_44 = V_56 ;
V_43 = V_42 ;
memcpy ( F_18 ( V_10 , V_42 ) , V_38 -> V_53 ,
V_38 -> V_54 ) ;
V_42 += V_38 -> V_54 ;
}
F_5 ( V_41 , V_57 , V_44 ) ;
F_17 ( V_41 , V_58 ,
V_43 ) ;
F_5 ( V_41 , V_59 ,
V_38 -> V_54 ) ;
++ V_38 ;
}
V_17 = F_6 ( V_5 , V_60 , V_10 , V_42 , NULL , 0 , NULL ) ;
V_55:
F_13 () ;
return V_17 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_61 V_62 ;
T_5 V_63 ;
int V_17 ;
if ( V_2 -> V_64 != - 1 ) {
F_20 ( V_5 , V_65 ,
V_2 -> V_64 ) ;
F_21 ( V_5 , V_66 , V_5 -> V_67 , L_1 ,
V_2 -> V_68 , V_2 -> V_64 ) ;
V_2 -> V_64 = - 1 ;
}
if ( F_22 ( V_2 -> V_69 . V_70 ) )
return;
if ( V_2 -> V_71 == V_72 && V_73 <= 2 )
V_2 -> V_71 = V_74 ;
V_63 = F_23 ( V_2 -> V_69 . V_75 ) & V_76 ;
F_24 ( & V_62 , F_1 ( V_2 , 0 ) ) ;
V_17 = F_25 ( & V_62 ,
V_63 ? V_63 : V_77 ,
V_2 -> V_69 . V_70 ) ;
F_26 ( V_17 ) ;
V_17 = F_27 ( V_5 , & V_62 , true ) ;
if ( V_17 < 0 ) {
F_28 ( V_5 , V_66 , V_5 -> V_67 ,
L_2 ,
V_2 -> V_68 ) ;
} else {
F_21 ( V_5 , V_66 , V_5 -> V_67 , L_3 ,
V_2 -> V_68 , V_17 ) ;
V_2 -> V_64 = V_17 ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_61 V_62 ;
T_5 V_63 ;
int V_17 ;
if ( V_2 -> V_78 != - 1 ) {
F_20 ( V_5 , V_65 ,
V_2 -> V_78 ) ;
F_21 ( V_5 , V_66 , V_5 -> V_67 , L_4 ,
V_2 -> V_68 , V_2 -> V_78 ) ;
V_2 -> V_78 = - 1 ;
}
if ( ! V_2 -> V_79 || F_22 ( V_2 -> V_69 . V_70 ) )
return;
V_63 = F_23 ( V_2 -> V_69 . V_75 ) & V_76 ;
F_30 ( & V_62 , V_65 ,
V_2 -> V_80 ,
F_1 ( V_2 , V_2 -> V_81 ) ) ;
V_17 = F_25 ( & V_62 ,
V_63 ? V_63 : V_77 ,
V_2 -> V_69 . V_70 ) ;
F_26 ( V_17 ) ;
V_17 = F_27 ( V_5 , & V_62 , true ) ;
if ( V_17 < 0 ) {
F_28 ( V_5 , V_66 , V_5 -> V_67 ,
L_5 ,
V_2 -> V_68 ) ;
} else {
F_21 ( V_5 , V_66 , V_5 -> V_67 , L_6 ,
V_2 -> V_68 , V_17 ) ;
V_2 -> V_78 = V_17 ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_29 * V_30 = V_5 -> V_30 ;
F_19 ( V_2 ) ;
F_29 ( V_2 ) ;
F_32 ( V_82 , & V_30 -> V_83 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_29 * V_30 = V_5 -> V_30 ;
struct V_84 * V_85 = V_30 -> V_84 . V_69 ;
struct V_37 V_86 [ 4 ] ;
struct V_87 * V_88 ;
unsigned int V_89 , V_39 ;
unsigned V_90 ;
T_6 V_91 ;
F_14 ( ! F_34 ( & V_2 -> V_92 ) ) ;
F_14 ( ! V_2 -> V_93 ) ;
V_85 -> V_94 = V_2 -> V_69 ;
V_85 -> V_95 = ++ V_85 -> V_96 ;
memset ( V_86 , '\0' , sizeof( V_86 ) ) ;
V_86 [ 0 ] . V_53 = & V_85 -> V_96 ;
V_86 [ 0 ] . V_50 = V_2 -> V_97 ;
V_86 [ 0 ] . V_52 = V_2 -> V_93 + F_35 ( struct V_84 ,
V_96 ) ;
V_86 [ 0 ] . V_54 = sizeof( V_85 -> V_96 ) ;
V_90 = F_35 ( struct V_84 , V_98 ) ;
V_86 [ 1 ] . V_44 = V_5 -> V_99 -> V_100 ;
V_86 [ 1 ] . V_43 = V_30 -> V_84 . V_101 + V_90 ;
V_86 [ 1 ] . V_50 = V_2 -> V_97 ;
V_86 [ 1 ] . V_52 = V_2 -> V_93 + V_90 ;
V_86 [ 1 ] . V_54 = V_85 -> V_54 - V_90 ;
V_89 = 2 ;
V_39 = 0 ;
F_36 (epp, &nic_data->local_page_list, link) {
if ( V_39 == V_2 -> V_102 ) {
break;
}
V_86 [ V_89 ] . V_53 = NULL ;
V_86 [ V_89 ] . V_44 = V_5 -> V_99 -> V_100 ;
V_86 [ V_89 ] . V_43 = V_88 -> V_69 ;
V_86 [ V_89 ] . V_50 = V_2 -> V_97 ;
V_86 [ V_89 ] . V_52 = V_2 -> V_103 [ V_39 ] ;
V_86 [ V_89 ] . V_54 = V_104 ;
if ( ++ V_89 == F_37 ( V_86 ) ) {
F_11 ( V_5 , V_86 , F_37 ( V_86 ) ) ;
V_89 = 0 ;
}
++ V_39 ;
}
V_86 [ V_89 ] . V_53 = & V_85 -> V_95 ;
V_86 [ V_89 ] . V_50 = V_2 -> V_97 ;
V_86 [ V_89 ] . V_52 = V_2 -> V_93 + F_35 ( struct V_84 ,
V_95 ) ;
V_86 [ V_89 ] . V_54 = sizeof( V_85 -> V_95 ) ;
F_11 ( V_5 , V_86 , V_89 + 1 ) ;
F_38 ( V_91 ,
V_105 , V_106 ,
V_107 , ( V_2 -> V_108 & 0xff ) ,
V_109 , V_110 ) ;
++ V_2 -> V_108 ;
F_39 ( V_5 ,
V_4 + V_2 -> V_3 * F_2 ( V_5 ) ,
& V_91 ) ;
}
static void F_40 ( struct V_6 * V_5 , unsigned V_111 ,
T_3 * V_69 , unsigned V_39 )
{
T_6 V_112 ;
unsigned V_89 ;
for ( V_89 = 0 ; V_89 < V_39 ; ++ V_89 ) {
F_38 ( V_112 ,
V_113 , 0 ,
V_114 ,
V_69 ? V_69 [ V_89 ] >> 12 : 0 ,
V_115 , 0 ) ;
F_41 ( V_5 , V_5 -> V_116 + V_117 ,
& V_112 , V_111 + V_89 ) ;
}
}
static bool F_42 ( struct V_6 * V_5 , unsigned V_3 )
{
return V_3 >= F_2 ( V_5 ) ;
}
static bool F_43 ( unsigned V_118 , unsigned V_119 )
{
unsigned V_120 = V_119 *
sizeof( T_6 ) / V_121 ;
return ( ( V_118 & ( V_118 - 1 ) ) || V_118 > V_120 ) ;
}
static bool F_44 ( struct V_6 * V_5 , unsigned F_1 ,
struct V_1 * * V_122 , unsigned * V_123 )
{
unsigned V_124 ;
if ( F_1 < V_4 )
return true ;
V_124 = ( F_1 - V_4 ) / F_2 ( V_5 ) ;
if ( V_124 >= V_5 -> V_125 )
return true ;
if ( V_122 )
* V_122 = V_5 -> V_2 + V_124 ;
if ( V_123 )
* V_123 = F_1 % F_2 ( V_5 ) ;
return false ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_126 * V_38 = V_2 -> V_112 . V_69 ;
unsigned V_127 = V_38 -> V_128 . V_129 . V_3 ;
unsigned V_118 = V_38 -> V_128 . V_129 . V_118 ;
unsigned V_130 = F_1 ( V_2 , V_127 ) ;
unsigned V_131 = F_46 ( V_2 , V_127 ) ;
T_2 V_31 ;
if ( F_42 ( V_5 , V_127 ) ||
F_43 ( V_118 , V_132 ) ) {
if ( F_47 () )
F_48 ( V_5 , V_66 , V_5 -> V_67 ,
L_7 ,
V_2 -> V_68 , V_127 , V_118 ) ;
return V_133 ;
}
F_40 ( V_5 , V_131 , V_38 -> V_128 . V_129 . V_69 , V_118 ) ;
F_49 ( V_31 ,
V_134 , 1 ,
V_135 , 0 ,
V_136 , V_137 ) ;
F_50 ( V_5 , & V_31 , V_138 , V_130 ) ;
F_49 ( V_31 ,
V_139 , 1 ,
V_140 , F_51 ( V_118 ) ,
V_141 , V_131 ) ;
F_50 ( V_5 , & V_31 , V_142 , V_130 ) ;
if ( V_127 == 0 ) {
memcpy ( V_2 -> V_143 , V_38 -> V_128 . V_129 . V_69 ,
V_118 * sizeof( T_3 ) ) ;
V_2 -> V_144 = V_118 ;
}
return V_145 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_126 * V_38 = V_2 -> V_112 . V_69 ;
unsigned V_146 = V_38 -> V_128 . V_147 . V_3 ;
unsigned V_127 = V_38 -> V_128 . V_147 . V_148 ;
unsigned V_118 = V_38 -> V_128 . V_147 . V_118 ;
unsigned V_131 = F_53 ( V_2 , V_146 ) ;
unsigned V_149 ;
T_2 V_31 ;
if ( F_42 ( V_5 , V_127 ) || F_42 ( V_5 , V_146 ) ||
V_146 >= V_150 ||
F_43 ( V_118 , V_151 ) ) {
if ( F_47 () )
F_48 ( V_5 , V_66 , V_5 -> V_67 ,
L_8
L_9 , V_2 -> V_68 , V_146 ,
V_127 , V_118 ) ;
return V_133 ;
}
if ( F_54 ( V_38 -> V_128 . V_147 . V_3 , V_2 -> V_152 ) )
++ V_2 -> V_153 ;
F_40 ( V_5 , V_131 , V_38 -> V_128 . V_147 . V_69 , V_118 ) ;
V_149 = V_38 -> V_128 . V_147 . V_149 & F_55 ( V_154 ) ;
F_56 ( V_31 ,
V_155 , V_131 ,
V_156 , F_1 ( V_2 , V_127 ) ,
V_154 , V_149 ,
V_157 , F_51 ( V_118 ) ,
V_158 ,
! ! ( V_38 -> V_128 . V_147 . V_159 &
V_160 ) ,
V_161 , 1 ) ;
F_50 ( V_5 , & V_31 , V_162 ,
F_1 ( V_2 , V_146 ) ) ;
return V_145 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_126 * V_38 = V_2 -> V_112 . V_69 ;
unsigned V_163 = V_38 -> V_128 . V_164 . V_3 ;
unsigned V_127 = V_38 -> V_128 . V_164 . V_148 ;
unsigned V_118 = V_38 -> V_128 . V_164 . V_118 ;
unsigned V_131 = F_58 ( V_2 , V_163 ) ;
unsigned V_149 , V_165 ;
T_2 V_31 ;
if ( F_42 ( V_5 , V_127 ) || F_42 ( V_5 , V_163 ) ||
V_163 >= V_73 ||
F_43 ( V_118 , V_151 ) ) {
if ( F_47 () )
F_48 ( V_5 , V_66 , V_5 -> V_67 ,
L_10
L_9 , V_2 -> V_68 , V_163 ,
V_127 , V_118 ) ;
return V_133 ;
}
F_59 ( & V_2 -> V_166 ) ;
if ( F_54 ( V_38 -> V_128 . V_164 . V_3 , V_2 -> V_167 ) )
++ V_2 -> V_168 ;
F_60 ( & V_2 -> V_166 ) ;
F_40 ( V_5 , V_131 , V_38 -> V_128 . V_164 . V_69 , V_118 ) ;
V_165 = V_2 -> V_71 == V_74 ;
V_149 = V_38 -> V_128 . V_164 . V_149 & F_55 ( V_169 ) ;
F_61 ( V_31 ,
V_170 , F_62 ( V_5 -> V_14 , 1U ) ,
V_171 , V_165 ,
V_172 , 1 ,
V_173 , V_131 ,
V_174 , F_1 ( V_2 , V_127 ) ,
V_169 , V_149 ,
V_175 , F_51 ( V_118 ) ,
V_176 , 1 ) ;
F_50 ( V_5 , & V_31 , V_177 ,
F_1 ( V_2 , V_163 ) ) ;
return V_145 ;
}
static bool F_63 ( struct V_1 * V_2 )
{
F_64 () ;
return ( ! V_2 -> V_168 && ! V_2 -> V_153 ) ||
F_65 ( & V_2 -> V_178 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_167 , 0 , sizeof( V_2 -> V_167 ) ) ;
V_2 -> V_168 = 0 ;
memset ( V_2 -> V_152 , 0 , sizeof( V_2 -> V_152 ) ) ;
V_2 -> V_153 = 0 ;
memset ( V_2 -> V_179 , 0 , sizeof( V_2 -> V_179 ) ) ;
F_67 ( & V_2 -> V_178 , 0 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
T_2 V_31 ;
unsigned V_39 = F_2 ( V_5 ) ;
unsigned V_180 = V_4 + V_2 -> V_3 * F_2 ( V_5 ) ;
unsigned V_181 = V_182 ;
unsigned V_3 , V_183 ;
F_4 ( V_10 , V_184 ) ;
int V_17 ;
F_69 ( V_150 >
V_185 ) ;
F_70 () ;
F_71 ( V_5 ) ;
F_72 () ;
V_183 = 0 ;
for ( V_3 = 0 ; V_3 < V_39 ; ++ V_3 ) {
if ( F_73 ( V_3 , V_2 -> V_167 ) ) {
F_9 ( V_31 ,
V_186 , 1 ,
V_187 ,
V_180 + V_3 ) ;
F_10 ( V_5 , & V_31 , V_188 ) ;
}
if ( F_73 ( V_3 , V_2 -> V_152 ) ) {
F_74 (
V_10 , V_189 ,
V_183 , V_180 + V_3 ) ;
V_183 ++ ;
}
}
F_67 ( & V_2 -> V_178 , 0 ) ;
while ( V_181 && ( V_2 -> V_153 || V_2 -> V_168 ) ) {
V_17 = F_6 ( V_5 , V_190 , V_10 ,
F_75 ( V_183 ) ,
NULL , 0 , NULL ) ;
F_14 ( V_17 < 0 ) ;
V_181 = F_76 ( V_2 -> V_191 ,
F_63 ( V_2 ) ,
V_181 ) ;
V_183 = 0 ;
for ( V_3 = 0 ; V_3 < V_39 ; ++ V_3 ) {
if ( F_77 ( V_3 , V_2 -> V_179 ) ) {
F_78 ( & V_2 -> V_178 ) ;
F_74 (
V_10 , V_189 ,
V_183 , V_180 + V_3 ) ;
V_183 ++ ;
}
}
}
F_70 () ;
F_79 ( V_5 ) ;
F_72 () ;
F_80 ( V_31 ) ;
for ( V_3 = 0 ; V_3 < V_39 ; ++ V_3 ) {
F_50 ( V_5 , & V_31 , V_162 ,
V_180 + V_3 ) ;
F_50 ( V_5 , & V_31 , V_177 ,
V_180 + V_3 ) ;
F_50 ( V_5 , & V_31 , V_142 ,
V_180 + V_3 ) ;
F_50 ( V_5 , & V_31 , V_138 ,
V_180 + V_3 ) ;
}
F_40 ( V_5 , V_2 -> V_192 , NULL ,
V_193 * F_2 ( V_5 ) ) ;
F_66 ( V_2 ) ;
V_2 -> V_144 = 0 ;
return V_181 ? 0 : V_194 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_29 * V_30 = V_5 -> V_30 ;
struct V_126 * V_38 = V_2 -> V_112 . V_69 ;
unsigned V_146 = V_38 -> V_128 . V_195 . V_196 ;
unsigned V_159 ;
if ( F_42 ( V_5 , V_146 ) || V_2 -> V_79 ) {
if ( F_47 () )
F_48 ( V_5 , V_66 , V_5 -> V_67 ,
L_11
L_12 , V_2 -> V_68 , V_146 ,
V_38 -> V_128 . V_195 . V_159 ) ;
return V_133 ;
}
V_159 = 0 ;
if ( V_38 -> V_128 . V_195 . V_159 & V_197 )
V_159 |= V_198 ;
if ( V_38 -> V_128 . V_195 . V_159 & V_199 )
V_159 |= V_200 ;
V_2 -> V_80 = V_159 ;
V_2 -> V_81 = V_146 ;
V_2 -> V_79 = true ;
F_29 ( V_2 ) ;
F_32 ( V_82 , & V_30 -> V_83 ) ;
return V_145 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_29 * V_30 = V_5 -> V_30 ;
V_2 -> V_79 = false ;
F_29 ( V_2 ) ;
F_32 ( V_82 , & V_30 -> V_83 ) ;
return V_145 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_29 * V_30 = V_5 -> V_30 ;
struct V_126 * V_38 = V_2 -> V_112 . V_69 ;
T_3 V_201 = V_38 -> V_128 . V_202 . V_102 ;
T_3 V_203 =
( V_104 -
F_35 ( struct V_126 , V_128 . V_202 . V_204 [ 0 ] ) )
/ sizeof( V_38 -> V_128 . V_202 . V_204 [ 0 ] ) ;
if ( ! V_38 -> V_128 . V_202 . V_101 || V_201 > V_203 ) {
if ( F_47 () )
F_48 ( V_5 , V_66 , V_5 -> V_67 ,
L_13 ,
V_2 -> V_68 ) ;
return V_133 ;
}
F_59 ( & V_30 -> V_205 ) ;
F_59 ( & V_2 -> V_92 ) ;
V_2 -> V_93 = V_38 -> V_128 . V_202 . V_101 ;
F_84 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
V_2 -> V_102 = 0 ;
if ( V_201 ) {
V_2 -> V_103 = F_85 ( V_201 , sizeof( T_3 ) ,
V_206 ) ;
if ( V_2 -> V_103 ) {
memcpy ( V_2 -> V_103 ,
V_38 -> V_128 . V_202 . V_204 ,
V_201 * sizeof( T_3 ) ) ;
V_2 -> V_102 = V_201 ;
}
}
F_33 ( V_2 ) ;
F_60 ( & V_2 -> V_92 ) ;
F_60 ( & V_30 -> V_205 ) ;
return V_145 ;
}
static int F_86 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_92 ) ;
V_2 -> V_93 = 0 ;
F_60 ( & V_2 -> V_92 ) ;
return V_145 ;
}
static void F_87 ( struct V_207 * V_208 )
{
struct V_1 * V_2 = F_88 ( V_208 , struct V_1 , V_38 ) ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_126 * V_38 = V_2 -> V_112 . V_69 ;
struct V_37 V_86 [ 2 ] ;
int V_17 ;
memset ( V_86 , '\0' , sizeof( V_86 ) ) ;
V_86 [ 0 ] . V_44 = V_2 -> V_97 ;
V_86 [ 0 ] . V_43 = V_2 -> V_209 ;
V_86 [ 0 ] . V_50 = V_5 -> V_99 -> V_100 ;
V_86 [ 0 ] . V_52 = V_2 -> V_112 . V_101 ;
V_86 [ 0 ] . V_54 = V_104 ;
V_17 = F_11 ( V_5 , V_86 , 1 ) ;
if ( V_17 ) {
if ( F_47 () )
F_48 ( V_5 , V_66 , V_5 -> V_67 ,
L_14 ,
V_2 -> V_68 , - V_17 ) ;
V_2 -> V_210 = false ;
return;
}
if ( V_38 -> V_211 < V_212 && V_213 [ V_38 -> V_211 ] != NULL ) {
V_17 = V_213 [ V_38 -> V_211 ] ( V_2 ) ;
if ( V_17 == 0 ) {
F_21 ( V_5 , V_66 , V_5 -> V_67 ,
L_15 ,
V_38 -> V_211 , V_2 -> V_68 ) ;
}
} else {
F_21 ( V_5 , V_66 , V_5 -> V_67 ,
L_16
L_17 , V_38 -> V_211 , V_2 -> V_68 ,
( unsigned long long ) V_2 -> V_209 ) ;
V_17 = V_214 ;
}
V_2 -> V_210 = false ;
F_89 () ;
V_38 -> V_17 = V_17 ;
V_38 -> V_211 = V_215 ;
memset ( V_86 , '\0' , sizeof( V_86 ) ) ;
V_86 [ 0 ] . V_53 = & V_38 -> V_17 ;
V_86 [ 0 ] . V_50 = V_2 -> V_97 ;
V_86 [ 0 ] . V_52 = V_2 -> V_209 + F_35 ( struct V_126 , V_17 ) ;
V_86 [ 0 ] . V_54 = sizeof( V_38 -> V_17 ) ;
V_86 [ 1 ] . V_53 = & V_38 -> V_211 ;
V_86 [ 1 ] . V_50 = V_2 -> V_97 ;
V_86 [ 1 ] . V_52 = V_2 -> V_209 + F_35 ( struct V_126 , V_211 ) ;
V_86 [ 1 ] . V_54 = sizeof( V_38 -> V_211 ) ;
( void ) F_11 ( V_5 , V_86 , F_37 ( V_86 ) ) ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_37 V_218 [ 4 ] ;
T_6 V_91 ;
unsigned int V_89 , V_39 , V_219 , V_131 , V_130 ;
T_2 V_31 ;
T_7 V_220 ;
int V_17 ;
F_26 ( V_217 -> V_221 != V_104 ) ;
if ( ! V_2 -> V_144 )
return;
F_26 ( V_2 -> V_144 & ( V_2 -> V_144 - 1 ) ) ;
F_59 ( & V_2 -> V_92 ) ;
F_38 ( V_91 ,
V_105 , V_106 ,
V_107 , V_2 -> V_108 ,
V_109 , V_222 ) ;
V_2 -> V_108 ++ ;
for ( V_89 = 0 ; V_89 < V_104 ; V_89 += sizeof( V_91 ) )
memcpy ( V_217 -> V_69 + V_89 , & V_91 , sizeof( V_91 ) ) ;
for ( V_89 = 0 ; V_89 < V_2 -> V_144 ; V_89 += V_39 ) {
V_39 = F_91 ( unsigned , V_2 -> V_144 - V_89 ,
F_37 ( V_218 ) ) ;
for ( V_219 = 0 ; V_219 < V_39 ; V_219 ++ ) {
V_218 [ V_219 ] . V_53 = NULL ;
V_218 [ V_219 ] . V_44 = V_5 -> V_99 -> V_100 ;
V_218 [ V_219 ] . V_43 = V_217 -> V_101 ;
V_218 [ V_219 ] . V_50 = V_2 -> V_97 ;
V_218 [ V_219 ] . V_52 = V_2 -> V_143 [ V_89 + V_219 ] ;
V_218 [ V_219 ] . V_54 = V_104 ;
}
V_17 = F_11 ( V_5 , V_218 , V_39 ) ;
if ( V_17 ) {
if ( F_47 () )
F_48 ( V_5 , V_66 , V_5 -> V_67 ,
L_18
L_19 , V_2 -> V_68 , - V_17 ) ;
break;
}
}
V_130 = F_1 ( V_2 , 0 ) ;
V_131 = F_46 ( V_2 , 0 ) ;
F_40 ( V_5 , V_131 , V_2 -> V_143 , V_2 -> V_144 ) ;
F_49 ( V_31 ,
V_134 , 1 ,
V_135 , 0 ,
V_136 , V_137 ) ;
F_50 ( V_5 , & V_31 , V_138 , V_130 ) ;
F_49 ( V_31 ,
V_139 , 1 ,
V_140 , F_51 ( V_2 -> V_144 ) ,
V_141 , V_131 ) ;
F_50 ( V_5 , & V_31 , V_142 , V_130 ) ;
F_92 ( V_220 , V_223 , 0 ) ;
F_93 ( V_5 , & V_220 , V_224 + V_225 * V_130 ) ;
F_60 ( & V_2 -> V_92 ) ;
}
static void F_94 ( struct V_207 * V_208 )
{
struct V_1 * V_2 = F_88 ( V_208 , struct V_1 , V_38 ) ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_216 V_112 ;
if ( ! F_95 ( V_5 , & V_112 , V_104 , V_226 ) ) {
F_90 ( V_2 , & V_112 ) ;
F_96 ( V_5 , & V_112 ) ;
}
}
static void F_97 ( struct V_6 * V_5 )
{
F_48 ( V_5 , V_227 , V_5 -> V_67 ,
L_20
L_21 ) ;
V_5 -> V_21 = 0 ;
}
static int F_98 ( struct V_228 * V_35 )
{
struct V_29 * V_30 = V_35 -> V_5 -> V_30 ;
V_30 -> V_34 = V_35 ;
return 0 ;
}
static void
F_99 ( struct V_228 * V_35 ,
char * V_112 , T_1 V_221 )
{
snprintf ( V_112 , V_221 , L_22 , V_35 -> V_5 -> V_229 ) ;
}
void F_100 ( struct V_6 * V_5 )
{
unsigned V_39 ;
if ( ! V_230 )
return;
if ( F_3 ( V_5 , false , & V_5 -> V_14 , & V_39 ) )
return;
if ( V_39 > 0 && V_39 > V_230 )
V_39 = V_230 ;
V_5 -> V_21 = V_39 ;
V_5 -> V_231 [ V_232 ] = & V_233 ;
}
static void F_101 ( struct V_207 * V_234 )
{
struct V_29 * V_30 = F_88 ( V_234 ,
struct V_29 ,
V_83 ) ;
struct V_6 * V_5 = V_30 -> V_5 ;
struct V_84 * V_84 = V_30 -> V_84 . V_69 ;
struct V_1 * V_2 ;
struct V_235 * V_236 ;
struct V_237 * V_238 ;
struct V_87 * V_88 ;
struct V_239 V_240 ;
unsigned int V_241 ;
unsigned int V_242 ;
unsigned int V_89 ;
F_59 ( & V_30 -> V_205 ) ;
F_102 ( & V_240 ) ;
F_103 ( & V_30 -> V_243 , & V_240 ) ;
V_238 = V_84 -> V_244 + 1 ;
V_241 = F_37 ( V_84 -> V_244 ) - 1 ;
V_242 = 1 ;
for ( V_89 = 0 ; V_89 < V_5 -> V_21 ; ++ V_89 ) {
V_2 = V_5 -> V_2 + V_89 ;
F_59 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_79 && ! F_22 ( V_2 -> V_69 . V_70 ) ) {
* V_238 ++ = V_2 -> V_69 ;
++ V_242 ;
-- V_241 ;
F_26 ( V_241 == 0 ) ;
}
F_60 ( & V_2 -> V_92 ) ;
}
F_36 (local_addr, &nic_data->local_addr_list, link) {
F_104 ( V_238 -> V_70 , V_236 -> V_69 ) ;
V_238 -> V_75 = 0 ;
++ V_238 ;
++ V_242 ;
if ( -- V_241 == 0 ) {
if ( F_105 ( & V_240 ) ) {
V_88 = F_106 ( sizeof( * V_88 ) , V_206 ) ;
if ( ! V_88 )
break;
V_88 -> V_220 = F_107 (
& V_5 -> V_99 -> V_245 , V_104 ,
& V_88 -> V_69 , V_206 ) ;
if ( ! V_88 -> V_220 ) {
F_84 ( V_88 ) ;
break;
}
} else {
V_88 = F_108 (
& V_240 , struct V_87 , V_246 ) ;
F_109 ( & V_88 -> V_246 ) ;
}
F_110 ( & V_88 -> V_246 , & V_30 -> V_243 ) ;
V_238 = (struct V_237 * ) V_88 -> V_220 ;
V_241 = V_104 / sizeof( struct V_237 ) ;
}
}
V_84 -> V_242 = V_242 ;
F_60 ( & V_30 -> V_205 ) ;
while ( ! F_105 ( & V_240 ) ) {
V_88 = F_108 (
& V_240 , struct V_87 , V_246 ) ;
F_109 ( & V_88 -> V_246 ) ;
F_111 ( & V_5 -> V_99 -> V_245 , V_104 ,
V_88 -> V_220 , V_88 -> V_69 ) ;
F_84 ( V_88 ) ;
}
for ( V_89 = 0 ; V_89 < V_5 -> V_21 ; ++ V_89 ) {
V_2 = V_5 -> V_2 + V_89 ;
F_59 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_93 )
F_33 ( V_2 ) ;
F_60 ( & V_2 -> V_92 ) ;
}
}
static void F_112 ( struct V_6 * V_5 )
{
struct V_29 * V_30 = V_5 -> V_30 ;
struct V_235 * V_236 ;
struct V_87 * V_88 ;
while ( ! F_105 ( & V_30 -> V_247 ) ) {
V_236 = F_108 ( & V_30 -> V_247 ,
struct V_235 , V_246 ) ;
F_109 ( & V_236 -> V_246 ) ;
F_84 ( V_236 ) ;
}
while ( ! F_105 ( & V_30 -> V_243 ) ) {
V_88 = F_108 ( & V_30 -> V_243 ,
struct V_87 , V_246 ) ;
F_109 ( & V_88 -> V_246 ) ;
F_111 ( & V_5 -> V_99 -> V_245 , V_104 ,
V_88 -> V_220 , V_88 -> V_69 ) ;
F_84 ( V_88 ) ;
}
}
static int F_113 ( struct V_6 * V_5 )
{
unsigned V_3 ;
struct V_1 * V_2 ;
V_5 -> V_2 = F_114 ( sizeof( struct V_1 ) * V_5 -> V_21 , V_206 ) ;
if ( ! V_5 -> V_2 )
return - V_248 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_21 ; ++ V_3 ) {
V_2 = V_5 -> V_2 + V_3 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_78 = - 1 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_64 = - 1 ;
F_115 ( & V_2 -> V_38 , F_87 ) ;
F_115 ( & V_2 -> V_249 , F_94 ) ;
F_116 ( & V_2 -> V_191 ) ;
F_117 ( & V_2 -> V_92 ) ;
F_117 ( & V_2 -> V_166 ) ;
}
return 0 ;
}
static void F_118 ( struct V_6 * V_5 )
{
struct V_1 * V_2 ;
unsigned int V_89 ;
for ( V_89 = 0 ; V_89 < V_5 -> V_21 ; ++ V_89 ) {
V_2 = V_5 -> V_2 + V_89 ;
F_96 ( V_5 , & V_2 -> V_112 ) ;
F_84 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
V_2 -> V_102 = 0 ;
V_2 -> V_144 = 0 ;
}
}
static int F_119 ( struct V_6 * V_5 )
{
struct V_99 * V_99 = V_5 -> V_99 ;
struct V_29 * V_30 = V_5 -> V_30 ;
unsigned V_3 , V_100 , V_250 , V_192 ;
T_5 V_111 , V_251 ;
struct V_1 * V_2 ;
int V_17 ;
V_250 = F_120 ( V_99 , V_252 ) ;
if ( ! V_250 )
return - V_253 ;
F_121 ( V_99 , V_250 + V_254 , & V_111 ) ;
F_121 ( V_99 , V_250 + V_255 , & V_251 ) ;
V_192 = V_30 -> V_256 ;
V_100 = V_99 -> V_100 + V_111 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_21 ; ++ V_3 ) {
V_2 = V_5 -> V_2 + V_3 ;
V_2 -> V_192 = V_192 ;
V_192 += V_193 * F_2 ( V_5 ) ;
V_2 -> V_97 = V_100 ;
snprintf ( V_2 -> V_68 , sizeof( V_2 -> V_68 ) ,
L_23 ,
F_122 ( V_99 -> V_257 ) , V_99 -> V_257 -> V_258 ,
F_123 ( V_100 ) , F_124 ( V_100 ) ) ;
V_17 = F_95 ( V_5 , & V_2 -> V_112 , V_104 ,
V_206 ) ;
if ( V_17 )
goto V_259;
V_100 += V_251 ;
}
return 0 ;
V_259:
F_118 ( V_5 ) ;
return V_17 ;
}
int F_125 ( struct V_6 * V_5 )
{
struct V_260 * V_67 = V_5 -> V_67 ;
struct V_29 * V_30 = V_5 -> V_30 ;
struct V_84 * V_84 ;
int V_17 ;
F_69 ( V_261 + 1 >= V_4 ) ;
F_69 ( V_4 & ( ( 1 << V_26 ) - 1 ) ) ;
if ( V_5 -> V_21 == 0 )
return 0 ;
V_17 = F_3 ( V_5 , true , NULL , NULL ) ;
if ( V_17 )
goto V_262;
V_17 = F_95 ( V_5 , & V_30 -> V_84 ,
sizeof( * V_84 ) , V_206 ) ;
if ( V_17 )
goto V_263;
V_84 = V_30 -> V_84 . V_69 ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_98 = 1 ;
V_84 -> V_54 = sizeof( * V_84 ) ;
V_84 -> V_264 = V_73 ;
V_84 -> V_14 = V_5 -> V_14 ;
V_84 -> V_265 = V_5 -> V_266 ;
V_84 -> V_242 = 1 + V_5 -> V_21 ;
V_84 -> V_267 = V_5 -> V_267 ;
V_17 = F_113 ( V_5 ) ;
if ( V_17 )
goto V_268;
F_117 ( & V_30 -> V_205 ) ;
F_115 ( & V_30 -> V_83 , F_101 ) ;
F_102 ( & V_30 -> V_247 ) ;
F_102 ( & V_30 -> V_243 ) ;
V_17 = F_119 ( V_5 ) ;
if ( V_17 )
goto V_269;
F_70 () ;
F_104 ( V_84 -> V_244 [ 0 ] . V_70 , V_67 -> V_270 ) ;
V_5 -> V_125 = V_5 -> V_21 ;
F_72 () ;
F_8 ( V_5 , true ) ;
V_17 = F_126 ( V_5 -> V_99 , V_5 -> V_21 ) ;
if ( V_17 )
goto V_271;
F_127 ( V_5 , V_272 , V_67 ,
L_24 ,
V_5 -> V_21 , F_2 ( V_5 ) ) ;
return 0 ;
V_271:
F_8 ( V_5 , false ) ;
F_70 () ;
V_5 -> V_125 = 0 ;
F_72 () ;
F_118 ( V_5 ) ;
V_269:
F_128 ( & V_30 -> V_83 ) ;
F_112 ( V_5 ) ;
F_84 ( V_5 -> V_2 ) ;
V_268:
F_96 ( V_5 , & V_30 -> V_84 ) ;
V_263:
F_3 ( V_5 , false , NULL , NULL ) ;
V_262:
return V_17 ;
}
void F_129 ( struct V_6 * V_5 )
{
struct V_1 * V_2 ;
unsigned int V_89 ;
struct V_29 * V_30 = V_5 -> V_30 ;
if ( V_5 -> V_125 == 0 )
return;
F_26 ( V_30 -> V_34 -> V_28 ) ;
F_8 ( V_5 , false ) ;
F_70 () ;
V_5 -> V_125 = 0 ;
F_72 () ;
for ( V_89 = 0 ; V_89 < V_5 -> V_21 ; ++ V_89 ) {
V_2 = V_5 -> V_2 + V_89 ;
F_128 ( & V_2 -> V_38 ) ;
F_128 ( & V_2 -> V_249 ) ;
}
F_128 ( & V_30 -> V_83 ) ;
F_130 ( V_5 -> V_99 ) ;
F_118 ( V_5 ) ;
F_112 ( V_5 ) ;
F_84 ( V_5 -> V_2 ) ;
F_96 ( V_5 , & V_30 -> V_84 ) ;
F_3 ( V_5 , false , NULL , NULL ) ;
}
void F_131 ( struct V_228 * V_35 , T_6 * V_91 )
{
struct V_6 * V_5 = V_35 -> V_5 ;
struct V_1 * V_2 ;
unsigned V_273 , V_274 , type , V_234 ;
V_273 = F_132 ( * V_91 , V_275 ) ;
F_69 ( V_276 != 0 ) ;
V_274 = F_132 ( * V_91 , V_107 ) ;
type = F_132 ( * V_91 , V_109 ) ;
V_234 = F_132 ( * V_91 , V_277 ) ;
F_133 ( V_5 , V_66 , V_5 -> V_67 ,
L_25 ,
V_273 , V_274 , type , V_234 ) ;
if ( F_44 ( V_5 , V_273 , & V_2 , NULL ) )
return;
if ( V_2 -> V_210 )
goto error;
if ( type == V_278 ) {
V_2 -> V_279 = V_278 ;
V_2 -> V_280 = V_274 + 1 ;
V_2 -> V_209 = 0 ;
} else if ( V_274 != ( V_2 -> V_280 ++ & 0xff ) || type != V_2 -> V_279 )
goto error;
switch ( V_2 -> V_279 ) {
case V_278 :
case V_281 :
case V_282 :
V_2 -> V_209 |= ( T_3 ) V_234 << ( V_2 -> V_279 << 4 ) ;
++ V_2 -> V_279 ;
return;
case V_283 :
V_2 -> V_209 |= ( T_3 ) V_234 << 48 ;
V_2 -> V_279 = V_278 ;
V_2 -> V_210 = true ;
F_32 ( V_82 , & V_2 -> V_38 ) ;
return;
}
error:
if ( F_47 () )
F_48 ( V_5 , V_66 , V_5 -> V_67 ,
L_26 ,
V_2 -> V_68 ) ;
V_2 -> V_279 = V_278 ;
V_2 -> V_280 = V_274 + 1 ;
}
void F_134 ( struct V_6 * V_5 , unsigned V_124 )
{
struct V_1 * V_2 ;
if ( V_124 > V_5 -> V_125 )
return;
V_2 = V_5 -> V_2 + V_124 ;
F_127 ( V_5 , V_66 , V_5 -> V_67 ,
L_27 , V_2 -> V_68 ) ;
V_2 -> V_93 = 0 ;
F_82 ( V_2 ) ;
F_66 ( V_2 ) ;
V_2 -> V_144 = 0 ;
}
void F_135 ( struct V_6 * V_5 )
{
struct V_29 * V_30 = V_5 -> V_30 ;
struct V_84 * V_84 = V_30 -> V_84 . V_69 ;
if ( ! V_5 -> V_125 )
return;
F_104 ( V_84 -> V_244 [ 0 ] . V_70 ,
V_5 -> V_67 -> V_270 ) ;
F_32 ( V_82 , & V_30 -> V_83 ) ;
}
void F_136 ( struct V_6 * V_5 , T_6 * V_91 )
{
struct V_1 * V_2 ;
unsigned V_284 , V_273 ;
V_284 = F_132 ( * V_91 , V_285 ) ;
if ( F_44 ( V_5 , V_284 , & V_2 , & V_273 ) )
return;
if ( ! F_73 ( V_273 , V_2 -> V_167 ) )
return;
F_137 ( V_273 , V_2 -> V_167 ) ;
-- V_2 -> V_168 ;
if ( F_63 ( V_2 ) )
F_138 ( & V_2 -> V_191 ) ;
}
void F_139 ( struct V_6 * V_5 , T_6 * V_91 )
{
struct V_1 * V_2 ;
unsigned V_286 , V_284 , V_273 ;
V_284 = F_132 ( * V_91 , V_287 ) ;
V_286 = F_132 ( * V_91 ,
V_288 ) ;
if ( F_44 ( V_5 , V_284 , & V_2 , & V_273 ) )
return;
if ( ! F_73 ( V_273 , V_2 -> V_152 ) )
return;
if ( V_286 ) {
F_140 ( V_273 , V_2 -> V_179 ) ;
F_141 ( & V_2 -> V_178 ) ;
} else {
F_137 ( V_273 , V_2 -> V_152 ) ;
-- V_2 -> V_153 ;
}
if ( F_63 ( V_2 ) )
F_138 ( & V_2 -> V_191 ) ;
}
void F_142 ( struct V_6 * V_5 , unsigned V_289 )
{
struct V_1 * V_2 ;
unsigned int V_290 ;
if ( F_44 ( V_5 , V_289 , & V_2 , & V_290 ) )
return;
if ( F_47 () )
F_48 ( V_5 , V_66 , V_5 -> V_67 ,
L_28 ,
V_2 -> V_3 , V_290 ) ;
F_32 ( V_82 , & V_2 -> V_249 ) ;
}
void F_143 ( struct V_6 * V_5 )
{
unsigned int V_124 ;
struct V_216 V_112 ;
struct V_1 * V_2 ;
F_144 () ;
if ( V_5 -> V_125 == 0 )
return;
F_8 ( V_5 , true ) ;
( void ) F_3 ( V_5 , true , NULL , NULL ) ;
if ( F_95 ( V_5 , & V_112 , V_104 , V_226 ) )
return;
for ( V_124 = 0 ; V_124 < V_5 -> V_125 ; ++ V_124 ) {
V_2 = V_5 -> V_2 + V_124 ;
F_90 ( V_2 , & V_112 ) ;
}
F_96 ( V_5 , & V_112 ) ;
}
int F_145 ( void )
{
V_82 = F_146 ( L_29 ) ;
if ( ! V_82 )
return - V_248 ;
return 0 ;
}
void F_147 ( void )
{
F_148 ( V_82 ) ;
}
int F_149 ( struct V_260 * V_67 , int V_124 , T_8 * V_291 )
{
struct V_6 * V_5 = F_150 ( V_67 ) ;
struct V_1 * V_2 ;
if ( V_124 >= V_5 -> V_125 )
return - V_292 ;
V_2 = V_5 -> V_2 + V_124 ;
F_59 ( & V_2 -> V_92 ) ;
F_104 ( V_2 -> V_69 . V_70 , V_291 ) ;
F_31 ( V_2 ) ;
F_60 ( & V_2 -> V_92 ) ;
return 0 ;
}
int F_151 ( struct V_260 * V_67 , int V_124 ,
T_5 V_63 , T_8 V_293 )
{
struct V_6 * V_5 = F_150 ( V_67 ) ;
struct V_1 * V_2 ;
T_5 V_75 ;
if ( V_124 >= V_5 -> V_125 )
return - V_292 ;
V_2 = V_5 -> V_2 + V_124 ;
F_59 ( & V_2 -> V_92 ) ;
V_75 = ( V_63 & V_76 ) | ( ( V_293 & 0x7 ) << V_294 ) ;
V_2 -> V_69 . V_75 = F_152 ( V_75 ) ;
F_31 ( V_2 ) ;
F_60 ( & V_2 -> V_92 ) ;
return 0 ;
}
int F_153 ( struct V_260 * V_67 , int V_124 ,
bool V_295 )
{
struct V_6 * V_5 = F_150 ( V_67 ) ;
struct V_1 * V_2 ;
int V_17 ;
if ( V_124 >= V_5 -> V_125 )
return - V_292 ;
V_2 = V_5 -> V_2 + V_124 ;
F_59 ( & V_2 -> V_166 ) ;
if ( V_2 -> V_168 == 0 ) {
V_2 -> V_71 =
V_295 ? V_74 : V_296 ;
V_17 = 0 ;
} else {
V_17 = - V_297 ;
}
F_60 ( & V_2 -> V_166 ) ;
return V_17 ;
}
int F_154 ( struct V_260 * V_67 , int V_124 ,
struct V_298 * V_299 )
{
struct V_6 * V_5 = F_150 ( V_67 ) ;
struct V_1 * V_2 ;
T_5 V_75 ;
if ( V_124 >= V_5 -> V_125 )
return - V_292 ;
V_2 = V_5 -> V_2 + V_124 ;
V_299 -> V_2 = V_124 ;
F_104 ( V_299 -> V_291 , V_2 -> V_69 . V_70 ) ;
V_299 -> V_300 = 0 ;
V_299 -> V_301 = 0 ;
V_75 = F_23 ( V_2 -> V_69 . V_75 ) ;
V_299 -> V_63 = V_75 & V_76 ;
V_299 -> V_293 = ( V_75 >> V_294 ) & 0x7 ;
V_299 -> V_295 = V_2 -> V_71 == V_74 ;
return 0 ;
}
