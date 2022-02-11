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
V_100 = F_33 ( V_97 -> V_61 , V_79 ,
F_19 ) ;
if ( ! V_100 )
return NULL ;
F_34 ( V_65 ) ;
V_100 -> V_66 = V_65 ;
V_59 = F_20 ( V_100 ) ;
F_35 ( & V_59 -> V_69 ) ;
F_35 ( & V_59 -> V_71 ) ;
F_36 ( & V_59 -> V_101 ) ;
F_35 ( & V_59 -> V_102 ) ;
F_37 ( & V_59 -> V_103 ) ;
V_59 -> V_73 = V_99 ;
F_38 ( & V_59 -> V_104 , V_61 , & V_105 ,
V_106 ) ;
if ( V_98 -> V_107 == V_108 )
V_59 -> V_75 = F_39 ( V_65 -> V_109 ) ;
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
V_100 -> V_107 = V_110 ;
F_42 ( & V_59 -> V_69 , & V_61 -> V_111 ) ;
F_9 ( & V_61 -> V_68 ) ;
F_6 ( & V_65 -> V_70 ) ;
F_42 ( & V_59 -> V_71 , & V_65 -> V_112 ) ;
F_9 ( & V_65 -> V_70 ) ;
F_43 ( & V_59 -> V_62 . V_67 ) ;
return V_59 ;
}
T_4
F_44 ( struct V_113 * V_114 ,
struct V_96 * V_97 , T_5 * V_115 ,
bool V_116 , T_1 V_99 , struct V_58 * * V_117 )
{
struct V_58 * V_59 ;
struct V_56 * V_57 ;
unsigned char V_118 = V_110 ;
T_4 V_82 ;
if ( V_116 )
V_118 |= ( V_119 | V_120 | V_108 ) ;
V_82 = F_45 ( V_97 , V_115 , V_118 , & V_57 ,
F_46 ( F_47 ( V_114 ) , V_121 ) ) ;
if ( V_82 )
goto V_122;
if ( ! F_48 ( & V_97 -> V_123 . V_7 ,
& V_57 -> V_66 -> V_124 ) ) {
V_82 = V_125 ;
goto V_126;
}
if ( V_57 -> V_107 != V_110 ) {
V_59 = F_32 ( V_97 , V_57 , V_99 ) ;
F_49 ( V_57 ) ;
V_82 = V_127 ;
if ( ! V_59 )
goto V_122;
F_50 ( & V_59 -> V_103 ) ;
} else {
V_59 = F_51 ( V_57 , struct V_58 , V_62 ) ;
V_82 = V_125 ;
F_50 ( & V_59 -> V_103 ) ;
if ( F_52 ( V_115 , & V_57 -> V_67 ) )
goto V_128;
if ( V_99 != V_59 -> V_73 )
goto V_128;
}
* V_117 = V_59 ;
return 0 ;
V_128:
F_53 ( & V_59 -> V_103 ) ;
V_126:
F_49 ( V_57 ) ;
V_122:
return V_82 ;
}
static void
F_54 ( struct V_58 * V_59 )
{
F_6 ( & V_59 -> V_101 ) ;
if ( V_59 -> V_77 )
goto V_21;
V_59 -> V_77 = true ;
F_55 ( & V_59 -> V_62 . V_66 -> V_78 ) ;
if ( F_56 ( & V_59 -> V_102 ) )
goto V_21;
F_57 ( & V_59 -> V_62 . V_67 ) ;
F_55 ( & V_59 -> V_62 . V_129 ) ;
F_58 ( & V_59 -> V_104 ) ;
V_21:
F_9 ( & V_59 -> V_101 ) ;
}
static inline T_2
F_59 ( struct V_130 * V_131 )
{
T_2 V_132 = V_131 -> V_133 + V_131 -> V_134 ;
return V_132 >= V_131 -> V_133 ? V_132 : V_135 ;
}
static void
F_60 ( struct V_130 * V_136 , T_2 V_132 )
{
if ( V_132 == V_135 )
V_136 -> V_134 = V_135 ;
else
V_136 -> V_134 = V_132 - V_136 -> V_133 ;
}
static bool
F_61 ( struct V_137 * V_136 , struct V_130 * V_138 )
{
if ( V_138 -> V_139 != V_140 && V_138 -> V_139 != V_136 -> V_141 . V_139 )
return false ;
if ( F_59 ( & V_136 -> V_141 ) <= V_138 -> V_133 )
return false ;
if ( F_59 ( V_138 ) <= V_136 -> V_141 . V_133 )
return false ;
return true ;
}
static bool
F_62 ( struct V_130 * V_136 , struct V_130 * V_142 )
{
if ( V_136 -> V_139 != V_142 -> V_139 )
return false ;
if ( F_59 ( V_142 ) < V_136 -> V_133 )
return false ;
if ( F_59 ( V_136 ) < V_142 -> V_133 )
return false ;
V_136 -> V_133 = F_63 ( V_136 -> V_133 , V_142 -> V_133 ) ;
F_60 ( V_136 , F_64 ( F_59 ( V_136 ) , F_59 ( V_142 ) ) ) ;
return true ;
}
static T_4
F_65 ( struct V_58 * V_59 )
{
struct V_64 * V_65 = V_59 -> V_62 . V_66 ;
struct V_58 * V_143 , * V_144 ;
T_4 V_145 = V_146 ;
F_66 ( & V_65 -> V_70 ) ;
F_67 (l, n, &fp->fi_lo_states, ls_perfile) {
if ( V_143 != V_59 ) {
F_54 ( V_143 ) ;
V_145 = V_147 ;
}
}
return V_145 ;
}
T_4
F_68 ( struct V_148 * V_149 , struct V_58 * V_59 )
{
struct V_130 * V_131 = & V_149 -> V_150 ;
struct V_64 * V_65 = V_59 -> V_62 . V_66 ;
struct V_137 * V_151 , * V_142 = NULL ;
T_4 V_145 ;
F_6 ( & V_65 -> V_70 ) ;
V_145 = F_65 ( V_59 ) ;
if ( V_145 )
goto V_122;
F_6 ( & V_59 -> V_101 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_62 ( & V_151 -> V_141 , V_131 ) )
goto V_152;
}
F_9 ( & V_59 -> V_101 ) ;
F_9 ( & V_65 -> V_70 ) ;
V_142 = F_69 ( V_153 , V_14 ) ;
if ( ! V_142 )
return V_127 ;
memcpy ( & V_142 -> V_141 , V_131 , sizeof( V_151 -> V_141 ) ) ;
V_142 -> V_154 = V_59 ;
F_6 ( & V_65 -> V_70 ) ;
V_145 = F_65 ( V_59 ) ;
if ( V_145 )
goto V_122;
F_6 ( & V_59 -> V_101 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_62 ( & V_151 -> V_141 , V_131 ) )
goto V_152;
}
F_55 ( & V_59 -> V_62 . V_129 ) ;
F_70 ( & V_142 -> V_155 , & V_59 -> V_102 ) ;
V_142 = NULL ;
V_152:
F_71 ( & V_149 -> V_156 , & V_59 -> V_62 ) ;
F_9 ( & V_59 -> V_101 ) ;
V_122:
F_9 ( & V_65 -> V_70 ) ;
if ( V_142 )
F_26 ( V_153 , V_142 ) ;
return V_145 ;
}
static void
F_72 ( struct V_157 * V_158 )
{
while ( ! F_56 ( V_158 ) ) {
struct V_137 * V_151 = F_73 ( V_158 ,
struct V_137 , V_155 ) ;
F_74 ( & V_151 -> V_155 ) ;
F_49 ( & V_151 -> V_154 -> V_62 ) ;
F_26 ( V_153 , V_151 ) ;
}
}
static void
F_75 ( struct V_137 * V_151 , struct V_130 * V_131 ,
struct V_157 * V_158 )
{
struct V_130 * V_136 = & V_151 -> V_141 ;
T_2 V_132 = F_59 ( V_136 ) ;
if ( V_131 -> V_133 <= V_136 -> V_133 ) {
if ( F_59 ( V_131 ) >= V_132 ) {
F_76 ( & V_151 -> V_155 , V_158 ) ;
return;
}
V_136 -> V_133 = F_59 ( V_131 ) ;
} else {
if ( F_59 ( V_131 ) < V_132 ) {
F_77 ( L_1 , V_159 ) ;
return;
}
V_132 = V_131 -> V_133 ;
}
F_60 ( V_136 , V_132 ) ;
}
T_4
F_78 ( struct V_113 * V_114 ,
struct V_96 * V_97 ,
struct V_160 * V_161 )
{
struct V_58 * V_59 ;
struct V_137 * V_151 , * V_144 ;
F_79 ( V_158 ) ;
T_4 V_145 ;
int V_162 = 0 ;
V_145 = F_44 ( V_114 , V_97 , & V_161 -> V_163 ,
false , V_161 -> V_164 ,
& V_59 ) ;
if ( V_145 ) {
F_80 ( & V_161 -> V_163 ) ;
return V_145 ;
}
F_6 ( & V_59 -> V_101 ) ;
F_67 (lp, n, &ls->ls_layouts, lo_perstate) {
if ( F_61 ( V_151 , & V_161 -> V_165 ) ) {
F_75 ( V_151 , & V_161 -> V_165 , & V_158 ) ;
V_162 ++ ;
}
}
if ( ! F_56 ( & V_59 -> V_102 ) ) {
if ( V_162 )
F_71 ( & V_161 -> V_163 , & V_59 -> V_62 ) ;
V_161 -> V_166 = 1 ;
} else {
F_81 ( & V_59 -> V_62 . V_67 ) ;
F_82 ( & V_59 -> V_62 ) ;
V_161 -> V_166 = 0 ;
}
F_9 ( & V_59 -> V_101 ) ;
F_53 ( & V_59 -> V_103 ) ;
F_49 ( & V_59 -> V_62 ) ;
F_72 ( & V_158 ) ;
return V_146 ;
}
T_4
F_83 ( struct V_113 * V_114 ,
struct V_96 * V_97 ,
struct V_160 * V_161 )
{
struct V_58 * V_59 , * V_144 ;
struct V_60 * V_61 = V_97 -> V_61 ;
struct V_137 * V_151 , * V_167 ;
F_79 ( V_158 ) ;
V_161 -> V_166 = 0 ;
F_6 ( & V_61 -> V_68 ) ;
F_67 (ls, n, &clp->cl_lo_states, ls_perclnt) {
if ( V_59 -> V_73 != V_161 -> V_164 )
continue;
if ( V_161 -> V_168 == V_169 &&
! F_84 ( & V_59 -> V_62 . V_66 -> V_124 ,
& V_97 -> V_123 . V_7 ) )
continue;
F_6 ( & V_59 -> V_101 ) ;
F_67 (lp, t, &ls->ls_layouts, lo_perstate) {
if ( V_161 -> V_165 . V_139 == V_140 ||
V_161 -> V_165 . V_139 == V_151 -> V_141 . V_139 )
F_76 ( & V_151 -> V_155 , & V_158 ) ;
}
F_9 ( & V_59 -> V_101 ) ;
}
F_9 ( & V_61 -> V_68 ) ;
F_72 ( & V_158 ) ;
return 0 ;
}
static void
F_85 ( struct V_58 * V_59 ,
struct V_157 * V_158 )
{
F_6 ( & V_59 -> V_101 ) ;
F_86 ( & V_59 -> V_102 , V_158 ) ;
F_9 ( & V_59 -> V_101 ) ;
}
void
F_87 ( struct V_60 * V_61 )
{
struct V_58 * V_59 , * V_144 ;
F_79 ( V_158 ) ;
F_6 ( & V_61 -> V_68 ) ;
F_67 (ls, n, &clp->cl_lo_states, ls_perclnt)
F_85 ( V_59 , & V_158 ) ;
F_9 ( & V_61 -> V_68 ) ;
F_72 ( & V_158 ) ;
}
void
F_88 ( struct V_60 * V_61 , struct V_64 * V_65 )
{
struct V_58 * V_59 , * V_144 ;
F_79 ( V_158 ) ;
F_6 ( & V_65 -> V_70 ) ;
F_67 (ls, n, &fp->fi_lo_states, ls_perfile) {
if ( V_59 -> V_62 . V_63 == V_61 )
F_85 ( V_59 , & V_158 ) ;
}
F_9 ( & V_65 -> V_70 ) ;
F_72 ( & V_158 ) ;
}
static void
F_89 ( struct V_58 * V_59 )
{
struct V_60 * V_61 = V_59 -> V_62 . V_63 ;
char V_170 [ V_171 ] ;
static char * V_172 [] = {
L_2 ,
L_3 ,
L_4 ,
NULL
} ;
char * V_173 [ 8 ] ;
int error ;
F_90 ( (struct V_174 * ) & V_61 -> V_175 , V_170 , sizeof( V_170 ) ) ;
F_91 ( V_176
L_5
L_6 , V_170 ) ;
V_173 [ 0 ] = L_7 ;
V_173 [ 1 ] = V_170 ;
V_173 [ 2 ] = V_59 -> V_75 -> V_177 . V_40 -> V_41 -> V_178 ;
V_173 [ 3 ] = NULL ;
error = F_92 ( V_173 [ 0 ] , V_173 , V_172 , V_179 ) ;
if ( error ) {
F_91 ( V_180 L_8 ,
V_170 , error ) ;
}
}
static void
F_93 ( struct V_181 * V_182 )
{
struct V_58 * V_59 =
F_51 ( V_182 , struct V_58 , V_104 ) ;
F_50 ( & V_59 -> V_103 ) ;
F_71 ( & V_59 -> V_183 , & V_59 -> V_62 ) ;
F_53 ( & V_59 -> V_103 ) ;
}
static int
F_94 ( struct V_181 * V_182 , struct V_184 * V_185 )
{
struct V_58 * V_59 =
F_51 ( V_182 , struct V_58 , V_104 ) ;
struct V_186 * V_187 ;
T_6 V_188 , V_189 ;
const struct V_72 * V_190 ;
F_79 ( V_158 ) ;
switch ( V_185 -> V_191 ) {
case 0 :
case - V_192 :
if ( F_56 ( & V_59 -> V_102 ) )
return 1 ;
V_188 = F_95 () ;
V_187 = F_46 ( V_59 -> V_62 . V_63 -> V_193 , V_121 ) ;
V_189 = F_96 ( V_185 -> V_194 ,
V_187 -> V_195 * V_196 * 2 ) ;
if ( F_97 ( V_188 , V_189 ) ) {
F_98 ( V_185 , V_197 / 100 ) ;
return 0 ;
}
default:
F_99 ( & V_59 -> V_62 . V_67 ) ;
V_190 = V_72 [ V_59 -> V_73 ] ;
if ( V_190 -> V_198 )
V_190 -> V_198 ( V_59 ) ;
else
F_89 ( V_59 ) ;
return - 1 ;
case - V_199 :
F_100 ( & V_59 -> V_62 . V_67 ) ;
V_185 -> V_191 = 0 ;
return 1 ;
}
}
static void
F_101 ( struct V_181 * V_182 )
{
struct V_58 * V_59 =
F_51 ( V_182 , struct V_58 , V_104 ) ;
F_79 ( V_158 ) ;
F_102 ( & V_59 -> V_62 . V_67 ) ;
F_85 ( V_59 , & V_158 ) ;
F_72 ( & V_158 ) ;
F_49 ( & V_59 -> V_62 ) ;
}
static bool
F_103 ( struct V_80 * V_81 )
{
V_81 -> V_200 = 0 ;
F_54 ( V_81 -> V_91 ) ;
return false ;
}
static int
F_104 ( struct V_80 * V_201 , int V_202 ,
struct V_157 * V_203 )
{
F_31 ( ! ( V_202 & V_76 ) ) ;
return F_105 ( V_201 , V_202 , V_203 ) ;
}
int
F_106 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_35 ( & V_25 [ V_13 ] ) ;
V_153 = F_107 ( L_9 ,
sizeof( struct V_137 ) , 0 , 0 , NULL ) ;
if ( ! V_153 )
return - V_30 ;
V_79 = F_107 ( L_10 ,
sizeof( struct V_58 ) , 0 , 0 , NULL ) ;
if ( ! V_79 ) {
F_108 ( V_153 ) ;
return - V_30 ;
}
return 0 ;
}
void
F_109 ( void )
{
int V_13 ;
F_108 ( V_153 ) ;
F_108 ( V_79 ) ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ ) {
struct V_10 * V_11 , * V_144 ;
F_67 (map, n, &nfsd_devid_hash[i], hash)
F_10 ( V_11 ) ;
}
}
