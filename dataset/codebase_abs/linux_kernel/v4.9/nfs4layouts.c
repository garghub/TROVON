static inline T_1 F_1 ( T_2 V_1 )
{
return F_2 ( V_1 , V_1 >> 32 , 0 ) & V_2 ;
}
static void
F_3 ( const struct V_3 * V_4 )
{
const struct V_5 * V_6 = & V_4 -> V_7 ;
T_3 V_8 = F_4 ( V_6 -> V_9 ) ;
struct V_10 * V_11 , * V_12 ;
int V_13 ;
V_11 = F_5 ( sizeof( * V_11 ) + V_8 , V_14 ) ;
if ( ! V_11 )
return;
V_11 -> V_15 = V_6 -> V_9 ;
memcpy ( & V_11 -> V_16 , V_6 -> V_17 , V_8 ) ;
F_6 ( & V_18 ) ;
if ( V_4 -> V_19 -> V_20 )
goto V_21;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ ) {
F_7 (old, &nfsd_devid_hash[i], hash) {
if ( V_12 -> V_15 != V_6 -> V_9 )
continue;
if ( memcmp ( V_12 -> V_16 , V_6 -> V_17 ,
F_4 ( V_12 -> V_15 ) ) )
continue;
V_4 -> V_19 -> V_20 = V_12 ;
goto V_21;
}
}
V_11 -> V_1 = V_23 ++ ;
F_8 ( & V_11 -> V_24 , & V_25 [ F_1 ( V_11 -> V_1 ) ] ) ;
V_4 -> V_19 -> V_20 = V_11 ;
V_11 = NULL ;
V_21:
F_9 ( & V_18 ) ;
F_10 ( V_11 ) ;
}
struct V_10 *
F_11 ( int V_1 )
{
struct V_10 * V_11 , * V_26 = NULL ;
F_12 () ;
F_13 (map, &nfsd_devid_hash[devid_hashfn(idx)], hash)
if ( V_11 -> V_1 == V_1 )
V_26 = V_11 ;
F_14 () ;
return V_26 ;
}
int
F_15 ( struct V_27 * V_28 , const struct V_3 * V_4 ,
T_1 V_29 )
{
if ( ! V_4 -> V_19 -> V_20 ) {
F_3 ( V_4 ) ;
if ( ! V_4 -> V_19 -> V_20 )
return - V_30 ;
}
V_28 -> V_31 = V_4 -> V_19 -> V_20 -> V_1 ;
V_28 -> V_32 = V_29 ;
V_28 -> V_33 = 0 ;
return 0 ;
}
void F_16 ( struct V_34 * exp )
{
#if F_17 ( V_35 ) || F_17 ( V_36 )
struct V_37 * V_38 = exp -> V_39 . V_40 -> V_41 ;
#endif
if ( ! ( exp -> V_42 & V_43 ) )
return;
#ifdef F_18
exp -> V_44 |= 1 << V_45 ;
#endif
#ifdef V_35
if ( V_38 -> V_46 -> V_47 &&
V_38 -> V_46 -> V_48 &&
V_38 -> V_46 -> V_49 )
exp -> V_44 |= 1 << V_50 ;
#endif
#ifdef V_36
if ( V_38 -> V_46 -> V_48 &&
V_38 -> V_46 -> V_49 &&
V_38 -> V_51 && V_38 -> V_51 -> V_52 -> V_53 -> V_54 )
exp -> V_44 |= 1 << V_55 ;
#endif
}
static void
F_19 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_20 ( V_57 ) ;
struct V_60 * V_61 = V_59 -> V_62 . V_63 ;
struct V_64 * V_65 = V_59 -> V_62 . V_66 ;
F_21 ( & V_59 -> V_62 . V_67 ) ;
F_6 ( & V_61 -> V_68 ) ;
F_22 ( & V_59 -> V_69 ) ;
F_9 ( & V_61 -> V_68 ) ;
F_6 ( & V_65 -> V_70 ) ;
F_22 ( & V_59 -> V_71 ) ;
F_9 ( & V_65 -> V_70 ) ;
if ( ! V_72 [ V_59 -> V_73 ] -> V_74 )
F_23 ( V_59 -> V_75 , V_76 , NULL , ( void * * ) & V_59 ) ;
F_24 ( V_59 -> V_75 ) ;
if ( V_59 -> V_77 )
F_25 ( & V_59 -> V_62 . V_66 -> V_78 ) ;
F_26 ( V_79 , V_59 ) ;
}
static int
F_27 ( struct V_58 * V_59 )
{
struct V_80 * V_81 ;
int V_82 ;
if ( V_72 [ V_59 -> V_73 ] -> V_74 )
return 0 ;
V_81 = F_28 () ;
if ( ! V_81 )
return - V_30 ;
F_29 ( V_81 ) ;
V_81 -> V_83 = & V_84 ;
V_81 -> V_85 = V_86 ;
V_81 -> V_87 = V_88 ;
V_81 -> V_89 = V_90 ;
V_81 -> V_91 = V_59 ;
V_81 -> V_92 = V_93 -> V_94 ;
V_81 -> V_95 = V_59 -> V_75 ;
V_82 = F_23 ( V_81 -> V_95 , V_81 -> V_87 , & V_81 , NULL ) ;
if ( V_82 ) {
F_30 ( V_81 ) ;
return V_82 ;
}
F_31 ( V_81 != NULL ) ;
return 0 ;
}
static struct V_58 *
F_32 ( struct V_96 * V_97 ,
struct V_56 * V_98 , T_1 V_99 )
{
struct V_60 * V_61 = V_97 -> V_61 ;
struct V_64 * V_65 = V_98 -> V_66 ;
struct V_58 * V_59 ;
struct V_56 * V_100 ;
V_100 = F_33 ( V_97 -> V_61 , V_79 ) ;
if ( ! V_100 )
return NULL ;
V_100 -> V_101 = F_19 ;
F_34 ( V_65 ) ;
V_100 -> V_66 = V_65 ;
V_59 = F_20 ( V_100 ) ;
F_35 ( & V_59 -> V_69 ) ;
F_35 ( & V_59 -> V_71 ) ;
F_36 ( & V_59 -> V_102 ) ;
F_35 ( & V_59 -> V_103 ) ;
F_37 ( & V_59 -> V_104 ) ;
V_59 -> V_73 = V_99 ;
F_38 ( & V_59 -> V_105 , V_61 , & V_106 ,
V_107 ) ;
if ( V_98 -> V_108 == V_109 )
V_59 -> V_75 = F_39 ( V_65 -> V_110 ) ;
else
V_59 -> V_75 = F_40 ( V_65 ) ;
F_31 ( ! V_59 -> V_75 ) ;
if ( F_27 ( V_59 ) ) {
F_24 ( V_59 -> V_75 ) ;
F_41 ( V_65 ) ;
F_26 ( V_79 , V_59 ) ;
return NULL ;
}
F_6 ( & V_61 -> V_68 ) ;
V_100 -> V_108 = V_111 ;
F_42 ( & V_59 -> V_69 , & V_61 -> V_112 ) ;
F_9 ( & V_61 -> V_68 ) ;
F_6 ( & V_65 -> V_70 ) ;
F_42 ( & V_59 -> V_71 , & V_65 -> V_113 ) ;
F_9 ( & V_65 -> V_70 ) ;
F_43 ( & V_59 -> V_62 . V_67 ) ;
return V_59 ;
}
T_4
F_44 ( struct V_114 * V_115 ,
struct V_96 * V_97 , T_5 * V_116 ,
bool V_117 , T_1 V_99 , struct V_58 * * V_118 )
{
struct V_58 * V_59 ;
struct V_56 * V_57 ;
unsigned char V_119 = V_111 ;
T_4 V_82 ;
if ( V_117 )
V_119 |= ( V_120 | V_121 | V_109 ) ;
V_82 = F_45 ( V_97 , V_116 , V_119 , & V_57 ,
F_46 ( F_47 ( V_115 ) , V_122 ) ) ;
if ( V_82 )
goto V_123;
if ( ! F_48 ( & V_97 -> V_124 . V_7 ,
& V_57 -> V_66 -> V_125 ) ) {
V_82 = V_126 ;
goto V_127;
}
if ( V_57 -> V_108 != V_111 ) {
V_59 = F_32 ( V_97 , V_57 , V_99 ) ;
F_49 ( V_57 ) ;
V_82 = V_128 ;
if ( ! V_59 )
goto V_123;
F_50 ( & V_59 -> V_104 ) ;
} else {
V_59 = F_51 ( V_57 , struct V_58 , V_62 ) ;
V_82 = V_126 ;
F_50 ( & V_59 -> V_104 ) ;
if ( F_52 ( V_116 , & V_57 -> V_67 ) )
goto V_129;
if ( V_99 != V_59 -> V_73 )
goto V_129;
}
* V_118 = V_59 ;
return 0 ;
V_129:
F_53 ( & V_59 -> V_104 ) ;
V_127:
F_49 ( V_57 ) ;
V_123:
return V_82 ;
}
static void
F_54 ( struct V_58 * V_59 )
{
F_6 ( & V_59 -> V_102 ) ;
if ( V_59 -> V_77 )
goto V_21;
V_59 -> V_77 = true ;
F_55 ( & V_59 -> V_62 . V_66 -> V_78 ) ;
if ( F_56 ( & V_59 -> V_103 ) )
goto V_21;
F_57 ( & V_59 -> V_62 . V_67 ) ;
F_55 ( & V_59 -> V_62 . V_130 ) ;
F_58 ( & V_59 -> V_105 ) ;
V_21:
F_9 ( & V_59 -> V_102 ) ;
}
static inline T_2
F_59 ( struct V_131 * V_132 )
{
T_2 V_133 = V_132 -> V_134 + V_132 -> V_135 ;
return V_133 >= V_132 -> V_134 ? V_133 : V_136 ;
}
static void
F_60 ( struct V_131 * V_137 , T_2 V_133 )
{
if ( V_133 == V_136 )
V_137 -> V_135 = V_136 ;
else
V_137 -> V_135 = V_133 - V_137 -> V_134 ;
}
static bool
F_61 ( struct V_138 * V_137 , struct V_131 * V_139 )
{
if ( V_139 -> V_140 != V_141 && V_139 -> V_140 != V_137 -> V_142 . V_140 )
return false ;
if ( F_59 ( & V_137 -> V_142 ) <= V_139 -> V_134 )
return false ;
if ( F_59 ( V_139 ) <= V_137 -> V_142 . V_134 )
return false ;
return true ;
}
static bool
F_62 ( struct V_131 * V_137 , struct V_131 * V_143 )
{
if ( V_137 -> V_140 != V_143 -> V_140 )
return false ;
if ( F_59 ( V_143 ) < V_137 -> V_134 )
return false ;
if ( F_59 ( V_137 ) < V_143 -> V_134 )
return false ;
V_137 -> V_134 = F_63 ( V_137 -> V_134 , V_143 -> V_134 ) ;
F_60 ( V_137 , F_64 ( F_59 ( V_137 ) , F_59 ( V_143 ) ) ) ;
return true ;
}
static T_4
F_65 ( struct V_58 * V_59 )
{
struct V_64 * V_65 = V_59 -> V_62 . V_66 ;
struct V_58 * V_144 , * V_145 ;
T_4 V_146 = V_147 ;
F_66 ( & V_65 -> V_70 ) ;
F_67 (l, n, &fp->fi_lo_states, ls_perfile) {
if ( V_144 != V_59 ) {
F_54 ( V_144 ) ;
V_146 = V_148 ;
}
}
return V_146 ;
}
T_4
F_68 ( struct V_149 * V_150 , struct V_58 * V_59 )
{
struct V_131 * V_132 = & V_150 -> V_151 ;
struct V_64 * V_65 = V_59 -> V_62 . V_66 ;
struct V_138 * V_152 , * V_143 = NULL ;
T_4 V_146 ;
F_6 ( & V_65 -> V_70 ) ;
V_146 = F_65 ( V_59 ) ;
if ( V_146 )
goto V_123;
F_6 ( & V_59 -> V_102 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_62 ( & V_152 -> V_142 , V_132 ) )
goto V_153;
}
F_9 ( & V_59 -> V_102 ) ;
F_9 ( & V_65 -> V_70 ) ;
V_143 = F_69 ( V_154 , V_14 ) ;
if ( ! V_143 )
return V_128 ;
memcpy ( & V_143 -> V_142 , V_132 , sizeof( V_152 -> V_142 ) ) ;
V_143 -> V_155 = V_59 ;
F_6 ( & V_65 -> V_70 ) ;
V_146 = F_65 ( V_59 ) ;
if ( V_146 )
goto V_123;
F_6 ( & V_59 -> V_102 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_62 ( & V_152 -> V_142 , V_132 ) )
goto V_153;
}
F_55 ( & V_59 -> V_62 . V_130 ) ;
F_70 ( & V_143 -> V_156 , & V_59 -> V_103 ) ;
V_143 = NULL ;
V_153:
F_71 ( & V_150 -> V_157 , & V_59 -> V_62 ) ;
F_9 ( & V_59 -> V_102 ) ;
V_123:
F_9 ( & V_65 -> V_70 ) ;
if ( V_143 )
F_26 ( V_154 , V_143 ) ;
return V_146 ;
}
static void
F_72 ( struct V_158 * V_159 )
{
while ( ! F_56 ( V_159 ) ) {
struct V_138 * V_152 = F_73 ( V_159 ,
struct V_138 , V_156 ) ;
F_74 ( & V_152 -> V_156 ) ;
F_49 ( & V_152 -> V_155 -> V_62 ) ;
F_26 ( V_154 , V_152 ) ;
}
}
static void
F_75 ( struct V_138 * V_152 , struct V_131 * V_132 ,
struct V_158 * V_159 )
{
struct V_131 * V_137 = & V_152 -> V_142 ;
T_2 V_133 = F_59 ( V_137 ) ;
if ( V_132 -> V_134 <= V_137 -> V_134 ) {
if ( F_59 ( V_132 ) >= V_133 ) {
F_76 ( & V_152 -> V_156 , V_159 ) ;
return;
}
V_137 -> V_134 = F_59 ( V_132 ) ;
} else {
if ( F_59 ( V_132 ) < V_133 ) {
F_77 ( L_1 , V_160 ) ;
return;
}
V_133 = V_132 -> V_134 ;
}
F_60 ( V_137 , V_133 ) ;
}
T_4
F_78 ( struct V_114 * V_115 ,
struct V_96 * V_97 ,
struct V_161 * V_162 )
{
struct V_58 * V_59 ;
struct V_138 * V_152 , * V_145 ;
F_79 ( V_159 ) ;
T_4 V_146 ;
int V_163 = 0 ;
V_146 = F_44 ( V_115 , V_97 , & V_162 -> V_164 ,
false , V_162 -> V_165 ,
& V_59 ) ;
if ( V_146 ) {
F_80 ( & V_162 -> V_164 ) ;
return V_146 ;
}
F_6 ( & V_59 -> V_102 ) ;
F_67 (lp, n, &ls->ls_layouts, lo_perstate) {
if ( F_61 ( V_152 , & V_162 -> V_166 ) ) {
F_75 ( V_152 , & V_162 -> V_166 , & V_159 ) ;
V_163 ++ ;
}
}
if ( ! F_56 ( & V_59 -> V_103 ) ) {
if ( V_163 )
F_71 ( & V_162 -> V_164 , & V_59 -> V_62 ) ;
V_162 -> V_167 = 1 ;
} else {
F_81 ( & V_59 -> V_62 . V_67 ) ;
F_82 ( & V_59 -> V_62 ) ;
V_162 -> V_167 = 0 ;
}
F_9 ( & V_59 -> V_102 ) ;
F_53 ( & V_59 -> V_104 ) ;
F_49 ( & V_59 -> V_62 ) ;
F_72 ( & V_159 ) ;
return V_147 ;
}
T_4
F_83 ( struct V_114 * V_115 ,
struct V_96 * V_97 ,
struct V_161 * V_162 )
{
struct V_58 * V_59 , * V_145 ;
struct V_60 * V_61 = V_97 -> V_61 ;
struct V_138 * V_152 , * V_168 ;
F_79 ( V_159 ) ;
V_162 -> V_167 = 0 ;
F_6 ( & V_61 -> V_68 ) ;
F_67 (ls, n, &clp->cl_lo_states, ls_perclnt) {
if ( V_59 -> V_73 != V_162 -> V_165 )
continue;
if ( V_162 -> V_169 == V_170 &&
! F_84 ( & V_59 -> V_62 . V_66 -> V_125 ,
& V_97 -> V_124 . V_7 ) )
continue;
F_6 ( & V_59 -> V_102 ) ;
F_67 (lp, t, &ls->ls_layouts, lo_perstate) {
if ( V_162 -> V_166 . V_140 == V_141 ||
V_162 -> V_166 . V_140 == V_152 -> V_142 . V_140 )
F_76 ( & V_152 -> V_156 , & V_159 ) ;
}
F_9 ( & V_59 -> V_102 ) ;
}
F_9 ( & V_61 -> V_68 ) ;
F_72 ( & V_159 ) ;
return 0 ;
}
static void
F_85 ( struct V_58 * V_59 ,
struct V_158 * V_159 )
{
F_6 ( & V_59 -> V_102 ) ;
F_86 ( & V_59 -> V_103 , V_159 ) ;
F_9 ( & V_59 -> V_102 ) ;
}
void
F_87 ( struct V_60 * V_61 )
{
struct V_58 * V_59 , * V_145 ;
F_79 ( V_159 ) ;
F_6 ( & V_61 -> V_68 ) ;
F_67 (ls, n, &clp->cl_lo_states, ls_perclnt)
F_85 ( V_59 , & V_159 ) ;
F_9 ( & V_61 -> V_68 ) ;
F_72 ( & V_159 ) ;
}
void
F_88 ( struct V_60 * V_61 , struct V_64 * V_65 )
{
struct V_58 * V_59 , * V_145 ;
F_79 ( V_159 ) ;
F_6 ( & V_65 -> V_70 ) ;
F_67 (ls, n, &fp->fi_lo_states, ls_perfile) {
if ( V_59 -> V_62 . V_63 == V_61 )
F_85 ( V_59 , & V_159 ) ;
}
F_9 ( & V_65 -> V_70 ) ;
F_72 ( & V_159 ) ;
}
static void
F_89 ( struct V_58 * V_59 )
{
struct V_60 * V_61 = V_59 -> V_62 . V_63 ;
char V_171 [ V_172 ] ;
static char * V_173 [] = {
L_2 ,
L_3 ,
L_4 ,
NULL
} ;
char * V_174 [ 8 ] ;
int error ;
F_90 ( (struct V_175 * ) & V_61 -> V_176 , V_171 , sizeof( V_171 ) ) ;
F_91 ( V_177
L_5
L_6 , V_171 ) ;
V_174 [ 0 ] = L_7 ;
V_174 [ 1 ] = V_171 ;
V_174 [ 2 ] = V_59 -> V_75 -> V_178 . V_40 -> V_41 -> V_179 ;
V_174 [ 3 ] = NULL ;
error = F_92 ( V_174 [ 0 ] , V_174 , V_173 , V_180 ) ;
if ( error ) {
F_91 ( V_181 L_8 ,
V_171 , error ) ;
}
}
static void
F_93 ( struct V_182 * V_183 )
{
struct V_58 * V_59 =
F_51 ( V_183 , struct V_58 , V_105 ) ;
F_50 ( & V_59 -> V_104 ) ;
F_71 ( & V_59 -> V_184 , & V_59 -> V_62 ) ;
F_53 ( & V_59 -> V_104 ) ;
}
static int
F_94 ( struct V_182 * V_183 , struct V_185 * V_186 )
{
struct V_58 * V_59 =
F_51 ( V_183 , struct V_58 , V_105 ) ;
struct V_187 * V_188 ;
T_6 V_189 , V_190 ;
const struct V_72 * V_191 ;
F_79 ( V_159 ) ;
switch ( V_186 -> V_192 ) {
case 0 :
case - V_193 :
if ( F_56 ( & V_59 -> V_103 ) )
return 1 ;
V_189 = F_95 () ;
V_188 = F_46 ( V_59 -> V_62 . V_63 -> V_194 , V_122 ) ;
V_190 = F_96 ( V_186 -> V_195 ,
V_188 -> V_196 * V_197 * 2 ) ;
if ( F_97 ( V_189 , V_190 ) ) {
F_98 ( V_186 , V_198 / 100 ) ;
return 0 ;
}
case - V_199 :
F_99 ( & V_59 -> V_62 . V_67 ) ;
V_186 -> V_192 = 0 ;
return 1 ;
default:
F_100 ( & V_59 -> V_62 . V_67 ) ;
V_191 = V_72 [ V_59 -> V_73 ] ;
if ( V_191 -> V_200 )
V_191 -> V_200 ( V_59 ) ;
else
F_89 ( V_59 ) ;
return - 1 ;
}
}
static void
F_101 ( struct V_182 * V_183 )
{
struct V_58 * V_59 =
F_51 ( V_183 , struct V_58 , V_105 ) ;
F_79 ( V_159 ) ;
F_102 ( & V_59 -> V_62 . V_67 ) ;
F_85 ( V_59 , & V_159 ) ;
F_72 ( & V_159 ) ;
F_49 ( & V_59 -> V_62 ) ;
}
static bool
F_103 ( struct V_80 * V_81 )
{
V_81 -> V_201 = 0 ;
F_54 ( V_81 -> V_91 ) ;
return false ;
}
static int
F_104 ( struct V_80 * V_202 , int V_203 ,
struct V_158 * V_204 )
{
F_31 ( ! ( V_203 & V_76 ) ) ;
return F_105 ( V_202 , V_203 , V_204 ) ;
}
int
F_106 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_35 ( & V_25 [ V_13 ] ) ;
V_154 = F_107 ( L_9 ,
sizeof( struct V_138 ) , 0 , 0 , NULL ) ;
if ( ! V_154 )
return - V_30 ;
V_79 = F_107 ( L_10 ,
sizeof( struct V_58 ) , 0 , 0 , NULL ) ;
if ( ! V_79 ) {
F_108 ( V_154 ) ;
return - V_30 ;
}
return 0 ;
}
void
F_109 ( void )
{
int V_13 ;
F_108 ( V_154 ) ;
F_108 ( V_79 ) ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ ) {
struct V_10 * V_11 , * V_145 ;
F_67 (map, n, &nfsd_devid_hash[i], hash)
F_10 ( V_11 ) ;
}
}
