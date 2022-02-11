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
struct V_35 * V_36 = exp -> V_37 . V_38 -> V_39 ;
if ( ! ( exp -> V_40 & V_41 ) )
return;
#ifdef F_17
if ( V_36 -> V_42 -> V_43 &&
V_36 -> V_42 -> V_44 &&
V_36 -> V_42 -> V_45 )
exp -> V_46 = V_47 ;
#endif
#ifdef F_18
if ( V_36 -> V_42 -> V_44 &&
V_36 -> V_42 -> V_45 &&
V_36 -> V_48 && V_36 -> V_48 -> V_49 -> V_50 -> V_51 )
exp -> V_46 = V_52 ;
#endif
}
static void
F_19 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_20 ( V_54 ) ;
struct V_57 * V_58 = V_56 -> V_59 . V_60 ;
struct V_61 * V_62 = V_56 -> V_59 . V_63 ;
F_21 ( & V_56 -> V_59 . V_64 ) ;
F_6 ( & V_58 -> V_65 ) ;
F_22 ( & V_56 -> V_66 ) ;
F_9 ( & V_58 -> V_65 ) ;
F_6 ( & V_62 -> V_67 ) ;
F_22 ( & V_56 -> V_68 ) ;
F_9 ( & V_62 -> V_67 ) ;
F_23 ( V_56 -> V_69 , V_70 , NULL , ( void * * ) & V_56 ) ;
F_24 ( V_56 -> V_69 ) ;
if ( V_56 -> V_71 )
F_25 ( & V_56 -> V_59 . V_63 -> V_72 ) ;
F_26 ( V_73 , V_56 ) ;
}
static int
F_27 ( struct V_55 * V_56 )
{
struct V_74 * V_75 ;
int V_76 ;
V_75 = F_28 () ;
if ( ! V_75 )
return - V_30 ;
F_29 ( V_75 ) ;
V_75 -> V_77 = & V_78 ;
V_75 -> V_79 = V_80 ;
V_75 -> V_81 = V_82 ;
V_75 -> V_83 = V_84 ;
V_75 -> V_85 = V_56 ;
V_75 -> V_86 = V_87 -> V_88 ;
V_75 -> V_89 = V_56 -> V_69 ;
V_76 = F_23 ( V_75 -> V_89 , V_75 -> V_81 , & V_75 , NULL ) ;
if ( V_76 ) {
F_30 ( V_75 ) ;
return V_76 ;
}
F_31 ( V_75 != NULL ) ;
return 0 ;
}
static struct V_55 *
F_32 ( struct V_90 * V_91 ,
struct V_53 * V_92 , T_1 V_93 )
{
struct V_57 * V_58 = V_91 -> V_58 ;
struct V_61 * V_62 = V_92 -> V_63 ;
struct V_55 * V_56 ;
struct V_53 * V_94 ;
V_94 = F_33 ( V_91 -> V_58 , V_73 ) ;
if ( ! V_94 )
return NULL ;
V_94 -> V_95 = F_19 ;
F_34 ( V_62 ) ;
V_94 -> V_63 = V_62 ;
V_56 = F_20 ( V_94 ) ;
F_35 ( & V_56 -> V_66 ) ;
F_35 ( & V_56 -> V_68 ) ;
F_36 ( & V_56 -> V_96 ) ;
F_35 ( & V_56 -> V_97 ) ;
F_37 ( & V_56 -> V_98 ) ;
V_56 -> V_99 = V_93 ;
F_38 ( & V_56 -> V_100 , V_58 , & V_101 ,
V_102 ) ;
if ( V_92 -> V_103 == V_104 )
V_56 -> V_69 = F_39 ( V_62 -> V_105 ) ;
else
V_56 -> V_69 = F_40 ( V_62 ) ;
F_31 ( ! V_56 -> V_69 ) ;
if ( F_27 ( V_56 ) ) {
F_24 ( V_56 -> V_69 ) ;
F_41 ( V_62 ) ;
F_26 ( V_73 , V_56 ) ;
return NULL ;
}
F_6 ( & V_58 -> V_65 ) ;
V_94 -> V_103 = V_106 ;
F_42 ( & V_56 -> V_66 , & V_58 -> V_107 ) ;
F_9 ( & V_58 -> V_65 ) ;
F_6 ( & V_62 -> V_67 ) ;
F_42 ( & V_56 -> V_68 , & V_62 -> V_108 ) ;
F_9 ( & V_62 -> V_67 ) ;
F_43 ( & V_56 -> V_59 . V_64 ) ;
return V_56 ;
}
T_4
F_44 ( struct V_109 * V_110 ,
struct V_90 * V_91 , T_5 * V_111 ,
bool V_112 , T_1 V_93 , struct V_55 * * V_113 )
{
struct V_55 * V_56 ;
struct V_53 * V_54 ;
unsigned char V_114 = V_106 ;
T_4 V_76 ;
if ( V_112 )
V_114 |= ( V_115 | V_116 | V_104 ) ;
V_76 = F_45 ( V_91 , V_111 , V_114 , & V_54 ,
F_46 ( F_47 ( V_110 ) , V_117 ) ) ;
if ( V_76 )
goto V_118;
if ( ! F_48 ( & V_91 -> V_119 . V_7 ,
& V_54 -> V_63 -> V_120 ) ) {
V_76 = V_121 ;
goto V_122;
}
if ( V_54 -> V_103 != V_106 ) {
V_56 = F_32 ( V_91 , V_54 , V_93 ) ;
F_49 ( V_54 ) ;
V_76 = V_123 ;
if ( ! V_56 )
goto V_118;
F_50 ( & V_56 -> V_98 ) ;
} else {
V_56 = F_51 ( V_54 , struct V_55 , V_59 ) ;
V_76 = V_121 ;
F_50 ( & V_56 -> V_98 ) ;
if ( V_111 -> V_124 > V_54 -> V_64 . V_124 )
goto V_125;
if ( V_93 != V_56 -> V_99 )
goto V_125;
}
* V_113 = V_56 ;
return 0 ;
V_125:
F_52 ( & V_56 -> V_98 ) ;
V_122:
F_49 ( V_54 ) ;
V_118:
return V_76 ;
}
static void
F_53 ( struct V_55 * V_56 )
{
F_6 ( & V_56 -> V_96 ) ;
if ( V_56 -> V_71 )
goto V_21;
V_56 -> V_71 = true ;
F_54 ( & V_56 -> V_59 . V_63 -> V_72 ) ;
if ( F_55 ( & V_56 -> V_97 ) )
goto V_21;
F_56 ( & V_56 -> V_59 . V_64 ) ;
F_54 ( & V_56 -> V_59 . V_126 ) ;
F_57 ( & V_56 -> V_100 ) ;
V_21:
F_9 ( & V_56 -> V_96 ) ;
}
static inline T_2
F_58 ( struct V_127 * V_128 )
{
T_2 V_129 = V_128 -> V_130 + V_128 -> V_131 ;
return V_129 >= V_128 -> V_130 ? V_129 : V_132 ;
}
static void
F_59 ( struct V_127 * V_133 , T_2 V_129 )
{
if ( V_129 == V_132 )
V_133 -> V_131 = V_132 ;
else
V_133 -> V_131 = V_129 - V_133 -> V_130 ;
}
static bool
F_60 ( struct V_134 * V_133 , struct V_127 * V_135 )
{
if ( V_135 -> V_136 != V_137 && V_135 -> V_136 != V_133 -> V_138 . V_136 )
return false ;
if ( F_58 ( & V_133 -> V_138 ) <= V_135 -> V_130 )
return false ;
if ( F_58 ( V_135 ) <= V_133 -> V_138 . V_130 )
return false ;
return true ;
}
static bool
F_61 ( struct V_127 * V_133 , struct V_127 * V_139 )
{
if ( V_133 -> V_136 != V_139 -> V_136 )
return false ;
if ( F_58 ( V_139 ) < V_133 -> V_130 )
return false ;
if ( F_58 ( V_133 ) < V_139 -> V_130 )
return false ;
V_133 -> V_130 = F_62 ( V_133 -> V_130 , V_139 -> V_130 ) ;
F_59 ( V_133 , F_63 ( F_58 ( V_133 ) , F_58 ( V_139 ) ) ) ;
return true ;
}
static T_4
F_64 ( struct V_55 * V_56 )
{
struct V_61 * V_62 = V_56 -> V_59 . V_63 ;
struct V_55 * V_140 , * V_141 ;
T_4 V_142 = V_143 ;
F_65 ( & V_62 -> V_67 ) ;
F_66 (l, n, &fp->fi_lo_states, ls_perfile) {
if ( V_140 != V_56 ) {
F_53 ( V_140 ) ;
V_142 = V_144 ;
}
}
return V_142 ;
}
T_4
F_67 ( struct V_145 * V_146 , struct V_55 * V_56 )
{
struct V_127 * V_128 = & V_146 -> V_147 ;
struct V_61 * V_62 = V_56 -> V_59 . V_63 ;
struct V_134 * V_148 , * V_139 = NULL ;
T_4 V_142 ;
F_6 ( & V_62 -> V_67 ) ;
V_142 = F_64 ( V_56 ) ;
if ( V_142 )
goto V_118;
F_6 ( & V_56 -> V_96 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_61 ( & V_148 -> V_138 , V_128 ) )
goto V_149;
}
F_9 ( & V_56 -> V_96 ) ;
F_9 ( & V_62 -> V_67 ) ;
V_139 = F_68 ( V_150 , V_14 ) ;
if ( ! V_139 )
return V_123 ;
memcpy ( & V_139 -> V_138 , V_128 , sizeof( V_148 -> V_138 ) ) ;
V_139 -> V_151 = V_56 ;
F_6 ( & V_62 -> V_67 ) ;
V_142 = F_64 ( V_56 ) ;
if ( V_142 )
goto V_118;
F_6 ( & V_56 -> V_96 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_61 ( & V_148 -> V_138 , V_128 ) )
goto V_149;
}
F_54 ( & V_56 -> V_59 . V_126 ) ;
F_69 ( & V_139 -> V_152 , & V_56 -> V_97 ) ;
V_139 = NULL ;
V_149:
F_70 ( & V_146 -> V_153 , & V_56 -> V_59 ) ;
F_9 ( & V_56 -> V_96 ) ;
V_118:
F_9 ( & V_62 -> V_67 ) ;
if ( V_139 )
F_26 ( V_150 , V_139 ) ;
return V_142 ;
}
static void
F_71 ( struct V_154 * V_155 )
{
while ( ! F_55 ( V_155 ) ) {
struct V_134 * V_148 = F_72 ( V_155 ,
struct V_134 , V_152 ) ;
F_73 ( & V_148 -> V_152 ) ;
F_49 ( & V_148 -> V_151 -> V_59 ) ;
F_26 ( V_150 , V_148 ) ;
}
}
static void
F_74 ( struct V_134 * V_148 , struct V_127 * V_128 ,
struct V_154 * V_155 )
{
struct V_127 * V_133 = & V_148 -> V_138 ;
T_2 V_129 = F_58 ( V_133 ) ;
if ( V_128 -> V_130 <= V_133 -> V_130 ) {
if ( F_58 ( V_128 ) >= V_129 ) {
F_75 ( & V_148 -> V_152 , V_155 ) ;
return;
}
V_133 -> V_130 = F_58 ( V_128 ) ;
} else {
if ( F_58 ( V_128 ) < V_129 ) {
F_76 ( L_1 , V_156 ) ;
return;
}
V_129 = V_128 -> V_130 ;
}
F_59 ( V_133 , V_129 ) ;
}
T_4
F_77 ( struct V_109 * V_110 ,
struct V_90 * V_91 ,
struct V_157 * V_158 )
{
struct V_55 * V_56 ;
struct V_134 * V_148 , * V_141 ;
F_78 ( V_155 ) ;
T_4 V_142 ;
int V_159 = 0 ;
V_142 = F_44 ( V_110 , V_91 , & V_158 -> V_160 ,
false , V_158 -> V_161 ,
& V_56 ) ;
if ( V_142 ) {
F_79 ( & V_158 -> V_160 ) ;
return V_142 ;
}
F_6 ( & V_56 -> V_96 ) ;
F_66 (lp, n, &ls->ls_layouts, lo_perstate) {
if ( F_60 ( V_148 , & V_158 -> V_162 ) ) {
F_74 ( V_148 , & V_158 -> V_162 , & V_155 ) ;
V_159 ++ ;
}
}
if ( ! F_55 ( & V_56 -> V_97 ) ) {
if ( V_159 )
F_70 ( & V_158 -> V_160 , & V_56 -> V_59 ) ;
V_158 -> V_163 = 1 ;
} else {
F_80 ( & V_56 -> V_59 . V_64 ) ;
F_81 ( & V_56 -> V_59 ) ;
V_158 -> V_163 = 0 ;
}
F_9 ( & V_56 -> V_96 ) ;
F_52 ( & V_56 -> V_98 ) ;
F_49 ( & V_56 -> V_59 ) ;
F_71 ( & V_155 ) ;
return V_143 ;
}
T_4
F_82 ( struct V_109 * V_110 ,
struct V_90 * V_91 ,
struct V_157 * V_158 )
{
struct V_55 * V_56 , * V_141 ;
struct V_57 * V_58 = V_91 -> V_58 ;
struct V_134 * V_148 , * V_164 ;
F_78 ( V_155 ) ;
V_158 -> V_163 = 0 ;
F_6 ( & V_58 -> V_65 ) ;
F_66 (ls, n, &clp->cl_lo_states, ls_perclnt) {
if ( V_56 -> V_99 != V_158 -> V_161 )
continue;
if ( V_158 -> V_165 == V_166 &&
! F_83 ( & V_56 -> V_59 . V_63 -> V_120 ,
& V_91 -> V_119 . V_7 ) )
continue;
F_6 ( & V_56 -> V_96 ) ;
F_66 (lp, t, &ls->ls_layouts, lo_perstate) {
if ( V_158 -> V_162 . V_136 == V_137 ||
V_158 -> V_162 . V_136 == V_148 -> V_138 . V_136 )
F_75 ( & V_148 -> V_152 , & V_155 ) ;
}
F_9 ( & V_56 -> V_96 ) ;
}
F_9 ( & V_58 -> V_65 ) ;
F_71 ( & V_155 ) ;
return 0 ;
}
static void
F_84 ( struct V_55 * V_56 ,
struct V_154 * V_155 )
{
F_6 ( & V_56 -> V_96 ) ;
F_85 ( & V_56 -> V_97 , V_155 ) ;
F_9 ( & V_56 -> V_96 ) ;
}
void
F_86 ( struct V_57 * V_58 )
{
struct V_55 * V_56 , * V_141 ;
F_78 ( V_155 ) ;
F_6 ( & V_58 -> V_65 ) ;
F_66 (ls, n, &clp->cl_lo_states, ls_perclnt)
F_84 ( V_56 , & V_155 ) ;
F_9 ( & V_58 -> V_65 ) ;
F_71 ( & V_155 ) ;
}
void
F_87 ( struct V_57 * V_58 , struct V_61 * V_62 )
{
struct V_55 * V_56 , * V_141 ;
F_78 ( V_155 ) ;
F_6 ( & V_62 -> V_67 ) ;
F_66 (ls, n, &fp->fi_lo_states, ls_perfile) {
if ( V_56 -> V_59 . V_60 == V_58 )
F_84 ( V_56 , & V_155 ) ;
}
F_9 ( & V_62 -> V_67 ) ;
F_71 ( & V_155 ) ;
}
static void
F_88 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = V_56 -> V_59 . V_60 ;
char V_167 [ V_168 ] ;
static char * V_169 [] = {
L_2 ,
L_3 ,
L_4 ,
NULL
} ;
char * V_170 [ 8 ] ;
int error ;
F_89 ( (struct V_171 * ) & V_58 -> V_172 , V_167 , sizeof( V_167 ) ) ;
F_90 ( V_173
L_5
L_6 , V_167 ) ;
V_170 [ 0 ] = L_7 ;
V_170 [ 1 ] = V_167 ;
V_170 [ 2 ] = V_56 -> V_69 -> V_174 . V_38 -> V_39 -> V_175 ;
V_170 [ 3 ] = NULL ;
error = F_91 ( V_170 [ 0 ] , V_170 , V_169 , V_176 ) ;
if ( error ) {
F_90 ( V_177 L_8 ,
V_167 , error ) ;
}
}
static void
F_92 ( struct V_178 * V_179 )
{
struct V_55 * V_56 =
F_51 ( V_179 , struct V_55 , V_100 ) ;
F_50 ( & V_56 -> V_98 ) ;
F_70 ( & V_56 -> V_180 , & V_56 -> V_59 ) ;
F_52 ( & V_56 -> V_98 ) ;
}
static int
F_93 ( struct V_178 * V_179 , struct V_181 * V_182 )
{
struct V_55 * V_56 =
F_51 ( V_179 , struct V_55 , V_100 ) ;
struct V_183 * V_184 ;
T_6 V_185 , V_186 ;
const struct V_187 * V_188 ;
F_78 ( V_155 ) ;
switch ( V_182 -> V_189 ) {
case 0 :
case - V_190 :
if ( F_55 ( & V_56 -> V_97 ) )
return 1 ;
V_185 = F_94 () ;
V_184 = F_46 ( V_56 -> V_59 . V_60 -> V_191 , V_117 ) ;
V_186 = F_95 ( V_182 -> V_192 ,
V_184 -> V_193 * V_194 * 2 ) ;
if ( F_96 ( V_185 , V_186 ) ) {
F_97 ( V_182 , V_195 / 100 ) ;
return 0 ;
}
case - V_196 :
F_98 ( & V_56 -> V_59 . V_64 ) ;
V_182 -> V_189 = 0 ;
return 1 ;
default:
F_99 ( & V_56 -> V_59 . V_64 ) ;
V_188 = V_187 [ V_56 -> V_99 ] ;
if ( V_188 -> V_197 )
V_188 -> V_197 ( V_56 ) ;
else
F_88 ( V_56 ) ;
return - 1 ;
}
}
static void
F_100 ( struct V_178 * V_179 )
{
struct V_55 * V_56 =
F_51 ( V_179 , struct V_55 , V_100 ) ;
F_78 ( V_155 ) ;
F_101 ( & V_56 -> V_59 . V_64 ) ;
F_84 ( V_56 , & V_155 ) ;
F_71 ( & V_155 ) ;
F_49 ( & V_56 -> V_59 ) ;
}
static bool
F_102 ( struct V_74 * V_75 )
{
V_75 -> V_198 = 0 ;
F_53 ( V_75 -> V_85 ) ;
return false ;
}
static int
F_103 ( struct V_74 * V_199 , int V_200 ,
struct V_154 * V_201 )
{
F_31 ( ! ( V_200 & V_70 ) ) ;
return F_104 ( V_199 , V_200 , V_201 ) ;
}
int
F_105 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_35 ( & V_25 [ V_13 ] ) ;
V_150 = F_106 ( L_9 ,
sizeof( struct V_134 ) , 0 , 0 , NULL ) ;
if ( ! V_150 )
return - V_30 ;
V_73 = F_106 ( L_10 ,
sizeof( struct V_55 ) , 0 , 0 , NULL ) ;
if ( ! V_73 ) {
F_107 ( V_150 ) ;
return - V_30 ;
}
return 0 ;
}
void
F_108 ( void )
{
int V_13 ;
F_107 ( V_150 ) ;
F_107 ( V_73 ) ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ ) {
struct V_10 * V_11 , * V_141 ;
F_66 (map, n, &nfsd_devid_hash[i], hash)
F_10 ( V_11 ) ;
}
}
