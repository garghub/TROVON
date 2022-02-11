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
F_23 ( V_59 -> V_72 , V_73 , NULL , ( void * * ) & V_59 ) ;
F_24 ( V_59 -> V_72 ) ;
if ( V_59 -> V_74 )
F_25 ( & V_59 -> V_62 . V_66 -> V_75 ) ;
F_26 ( V_76 , V_59 ) ;
}
static int
F_27 ( struct V_58 * V_59 )
{
struct V_77 * V_78 ;
int V_79 ;
V_78 = F_28 () ;
if ( ! V_78 )
return - V_30 ;
F_29 ( V_78 ) ;
V_78 -> V_80 = & V_81 ;
V_78 -> V_82 = V_83 ;
V_78 -> V_84 = V_85 ;
V_78 -> V_86 = V_87 ;
V_78 -> V_88 = V_59 ;
V_78 -> V_89 = V_90 -> V_91 ;
V_78 -> V_92 = V_59 -> V_72 ;
V_79 = F_23 ( V_78 -> V_92 , V_78 -> V_84 , & V_78 , NULL ) ;
if ( V_79 ) {
F_30 ( V_78 ) ;
return V_79 ;
}
F_31 ( V_78 != NULL ) ;
return 0 ;
}
static struct V_58 *
F_32 ( struct V_93 * V_94 ,
struct V_56 * V_95 , T_1 V_96 )
{
struct V_60 * V_61 = V_94 -> V_61 ;
struct V_64 * V_65 = V_95 -> V_66 ;
struct V_58 * V_59 ;
struct V_56 * V_97 ;
V_97 = F_33 ( V_94 -> V_61 , V_76 ) ;
if ( ! V_97 )
return NULL ;
V_97 -> V_98 = F_19 ;
F_34 ( V_65 ) ;
V_97 -> V_66 = V_65 ;
V_59 = F_20 ( V_97 ) ;
F_35 ( & V_59 -> V_69 ) ;
F_35 ( & V_59 -> V_71 ) ;
F_36 ( & V_59 -> V_99 ) ;
F_35 ( & V_59 -> V_100 ) ;
F_37 ( & V_59 -> V_101 ) ;
V_59 -> V_102 = V_96 ;
F_38 ( & V_59 -> V_103 , V_61 , & V_104 ,
V_105 ) ;
if ( V_95 -> V_106 == V_107 )
V_59 -> V_72 = F_39 ( V_65 -> V_108 ) ;
else
V_59 -> V_72 = F_40 ( V_65 ) ;
F_31 ( ! V_59 -> V_72 ) ;
if ( F_27 ( V_59 ) ) {
F_24 ( V_59 -> V_72 ) ;
F_41 ( V_65 ) ;
F_26 ( V_76 , V_59 ) ;
return NULL ;
}
F_6 ( & V_61 -> V_68 ) ;
V_97 -> V_106 = V_109 ;
F_42 ( & V_59 -> V_69 , & V_61 -> V_110 ) ;
F_9 ( & V_61 -> V_68 ) ;
F_6 ( & V_65 -> V_70 ) ;
F_42 ( & V_59 -> V_71 , & V_65 -> V_111 ) ;
F_9 ( & V_65 -> V_70 ) ;
F_43 ( & V_59 -> V_62 . V_67 ) ;
return V_59 ;
}
T_4
F_44 ( struct V_112 * V_113 ,
struct V_93 * V_94 , T_5 * V_114 ,
bool V_115 , T_1 V_96 , struct V_58 * * V_116 )
{
struct V_58 * V_59 ;
struct V_56 * V_57 ;
unsigned char V_117 = V_109 ;
T_4 V_79 ;
if ( V_115 )
V_117 |= ( V_118 | V_119 | V_107 ) ;
V_79 = F_45 ( V_94 , V_114 , V_117 , & V_57 ,
F_46 ( F_47 ( V_113 ) , V_120 ) ) ;
if ( V_79 )
goto V_121;
if ( ! F_48 ( & V_94 -> V_122 . V_7 ,
& V_57 -> V_66 -> V_123 ) ) {
V_79 = V_124 ;
goto V_125;
}
if ( V_57 -> V_106 != V_109 ) {
V_59 = F_32 ( V_94 , V_57 , V_96 ) ;
F_49 ( V_57 ) ;
V_79 = V_126 ;
if ( ! V_59 )
goto V_121;
F_50 ( & V_59 -> V_101 ) ;
} else {
V_59 = F_51 ( V_57 , struct V_58 , V_62 ) ;
V_79 = V_124 ;
F_50 ( & V_59 -> V_101 ) ;
if ( F_52 ( V_114 , & V_57 -> V_67 ) )
goto V_127;
if ( V_96 != V_59 -> V_102 )
goto V_127;
}
* V_116 = V_59 ;
return 0 ;
V_127:
F_53 ( & V_59 -> V_101 ) ;
V_125:
F_49 ( V_57 ) ;
V_121:
return V_79 ;
}
static void
F_54 ( struct V_58 * V_59 )
{
F_6 ( & V_59 -> V_99 ) ;
if ( V_59 -> V_74 )
goto V_21;
V_59 -> V_74 = true ;
F_55 ( & V_59 -> V_62 . V_66 -> V_75 ) ;
if ( F_56 ( & V_59 -> V_100 ) )
goto V_21;
F_57 ( & V_59 -> V_62 . V_67 ) ;
F_55 ( & V_59 -> V_62 . V_128 ) ;
F_58 ( & V_59 -> V_103 ) ;
V_21:
F_9 ( & V_59 -> V_99 ) ;
}
static inline T_2
F_59 ( struct V_129 * V_130 )
{
T_2 V_131 = V_130 -> V_132 + V_130 -> V_133 ;
return V_131 >= V_130 -> V_132 ? V_131 : V_134 ;
}
static void
F_60 ( struct V_129 * V_135 , T_2 V_131 )
{
if ( V_131 == V_134 )
V_135 -> V_133 = V_134 ;
else
V_135 -> V_133 = V_131 - V_135 -> V_132 ;
}
static bool
F_61 ( struct V_136 * V_135 , struct V_129 * V_137 )
{
if ( V_137 -> V_138 != V_139 && V_137 -> V_138 != V_135 -> V_140 . V_138 )
return false ;
if ( F_59 ( & V_135 -> V_140 ) <= V_137 -> V_132 )
return false ;
if ( F_59 ( V_137 ) <= V_135 -> V_140 . V_132 )
return false ;
return true ;
}
static bool
F_62 ( struct V_129 * V_135 , struct V_129 * V_141 )
{
if ( V_135 -> V_138 != V_141 -> V_138 )
return false ;
if ( F_59 ( V_141 ) < V_135 -> V_132 )
return false ;
if ( F_59 ( V_135 ) < V_141 -> V_132 )
return false ;
V_135 -> V_132 = F_63 ( V_135 -> V_132 , V_141 -> V_132 ) ;
F_60 ( V_135 , F_64 ( F_59 ( V_135 ) , F_59 ( V_141 ) ) ) ;
return true ;
}
static T_4
F_65 ( struct V_58 * V_59 )
{
struct V_64 * V_65 = V_59 -> V_62 . V_66 ;
struct V_58 * V_142 , * V_143 ;
T_4 V_144 = V_145 ;
F_66 ( & V_65 -> V_70 ) ;
F_67 (l, n, &fp->fi_lo_states, ls_perfile) {
if ( V_142 != V_59 ) {
F_54 ( V_142 ) ;
V_144 = V_146 ;
}
}
return V_144 ;
}
T_4
F_68 ( struct V_147 * V_148 , struct V_58 * V_59 )
{
struct V_129 * V_130 = & V_148 -> V_149 ;
struct V_64 * V_65 = V_59 -> V_62 . V_66 ;
struct V_136 * V_150 , * V_141 = NULL ;
T_4 V_144 ;
F_6 ( & V_65 -> V_70 ) ;
V_144 = F_65 ( V_59 ) ;
if ( V_144 )
goto V_121;
F_6 ( & V_59 -> V_99 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_62 ( & V_150 -> V_140 , V_130 ) )
goto V_151;
}
F_9 ( & V_59 -> V_99 ) ;
F_9 ( & V_65 -> V_70 ) ;
V_141 = F_69 ( V_152 , V_14 ) ;
if ( ! V_141 )
return V_126 ;
memcpy ( & V_141 -> V_140 , V_130 , sizeof( V_150 -> V_140 ) ) ;
V_141 -> V_153 = V_59 ;
F_6 ( & V_65 -> V_70 ) ;
V_144 = F_65 ( V_59 ) ;
if ( V_144 )
goto V_121;
F_6 ( & V_59 -> V_99 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_62 ( & V_150 -> V_140 , V_130 ) )
goto V_151;
}
F_55 ( & V_59 -> V_62 . V_128 ) ;
F_70 ( & V_141 -> V_154 , & V_59 -> V_100 ) ;
V_141 = NULL ;
V_151:
F_71 ( & V_148 -> V_155 , & V_59 -> V_62 ) ;
F_9 ( & V_59 -> V_99 ) ;
V_121:
F_9 ( & V_65 -> V_70 ) ;
if ( V_141 )
F_26 ( V_152 , V_141 ) ;
return V_144 ;
}
static void
F_72 ( struct V_156 * V_157 )
{
while ( ! F_56 ( V_157 ) ) {
struct V_136 * V_150 = F_73 ( V_157 ,
struct V_136 , V_154 ) ;
F_74 ( & V_150 -> V_154 ) ;
F_49 ( & V_150 -> V_153 -> V_62 ) ;
F_26 ( V_152 , V_150 ) ;
}
}
static void
F_75 ( struct V_136 * V_150 , struct V_129 * V_130 ,
struct V_156 * V_157 )
{
struct V_129 * V_135 = & V_150 -> V_140 ;
T_2 V_131 = F_59 ( V_135 ) ;
if ( V_130 -> V_132 <= V_135 -> V_132 ) {
if ( F_59 ( V_130 ) >= V_131 ) {
F_76 ( & V_150 -> V_154 , V_157 ) ;
return;
}
V_135 -> V_132 = F_59 ( V_130 ) ;
} else {
if ( F_59 ( V_130 ) < V_131 ) {
F_77 ( L_1 , V_158 ) ;
return;
}
V_131 = V_130 -> V_132 ;
}
F_60 ( V_135 , V_131 ) ;
}
T_4
F_78 ( struct V_112 * V_113 ,
struct V_93 * V_94 ,
struct V_159 * V_160 )
{
struct V_58 * V_59 ;
struct V_136 * V_150 , * V_143 ;
F_79 ( V_157 ) ;
T_4 V_144 ;
int V_161 = 0 ;
V_144 = F_44 ( V_113 , V_94 , & V_160 -> V_162 ,
false , V_160 -> V_163 ,
& V_59 ) ;
if ( V_144 ) {
F_80 ( & V_160 -> V_162 ) ;
return V_144 ;
}
F_6 ( & V_59 -> V_99 ) ;
F_67 (lp, n, &ls->ls_layouts, lo_perstate) {
if ( F_61 ( V_150 , & V_160 -> V_164 ) ) {
F_75 ( V_150 , & V_160 -> V_164 , & V_157 ) ;
V_161 ++ ;
}
}
if ( ! F_56 ( & V_59 -> V_100 ) ) {
if ( V_161 )
F_71 ( & V_160 -> V_162 , & V_59 -> V_62 ) ;
V_160 -> V_165 = 1 ;
} else {
F_81 ( & V_59 -> V_62 . V_67 ) ;
F_82 ( & V_59 -> V_62 ) ;
V_160 -> V_165 = 0 ;
}
F_9 ( & V_59 -> V_99 ) ;
F_53 ( & V_59 -> V_101 ) ;
F_49 ( & V_59 -> V_62 ) ;
F_72 ( & V_157 ) ;
return V_145 ;
}
T_4
F_83 ( struct V_112 * V_113 ,
struct V_93 * V_94 ,
struct V_159 * V_160 )
{
struct V_58 * V_59 , * V_143 ;
struct V_60 * V_61 = V_94 -> V_61 ;
struct V_136 * V_150 , * V_166 ;
F_79 ( V_157 ) ;
V_160 -> V_165 = 0 ;
F_6 ( & V_61 -> V_68 ) ;
F_67 (ls, n, &clp->cl_lo_states, ls_perclnt) {
if ( V_59 -> V_102 != V_160 -> V_163 )
continue;
if ( V_160 -> V_167 == V_168 &&
! F_84 ( & V_59 -> V_62 . V_66 -> V_123 ,
& V_94 -> V_122 . V_7 ) )
continue;
F_6 ( & V_59 -> V_99 ) ;
F_67 (lp, t, &ls->ls_layouts, lo_perstate) {
if ( V_160 -> V_164 . V_138 == V_139 ||
V_160 -> V_164 . V_138 == V_150 -> V_140 . V_138 )
F_76 ( & V_150 -> V_154 , & V_157 ) ;
}
F_9 ( & V_59 -> V_99 ) ;
}
F_9 ( & V_61 -> V_68 ) ;
F_72 ( & V_157 ) ;
return 0 ;
}
static void
F_85 ( struct V_58 * V_59 ,
struct V_156 * V_157 )
{
F_6 ( & V_59 -> V_99 ) ;
F_86 ( & V_59 -> V_100 , V_157 ) ;
F_9 ( & V_59 -> V_99 ) ;
}
void
F_87 ( struct V_60 * V_61 )
{
struct V_58 * V_59 , * V_143 ;
F_79 ( V_157 ) ;
F_6 ( & V_61 -> V_68 ) ;
F_67 (ls, n, &clp->cl_lo_states, ls_perclnt)
F_85 ( V_59 , & V_157 ) ;
F_9 ( & V_61 -> V_68 ) ;
F_72 ( & V_157 ) ;
}
void
F_88 ( struct V_60 * V_61 , struct V_64 * V_65 )
{
struct V_58 * V_59 , * V_143 ;
F_79 ( V_157 ) ;
F_6 ( & V_65 -> V_70 ) ;
F_67 (ls, n, &fp->fi_lo_states, ls_perfile) {
if ( V_59 -> V_62 . V_63 == V_61 )
F_85 ( V_59 , & V_157 ) ;
}
F_9 ( & V_65 -> V_70 ) ;
F_72 ( & V_157 ) ;
}
static void
F_89 ( struct V_58 * V_59 )
{
struct V_60 * V_61 = V_59 -> V_62 . V_63 ;
char V_169 [ V_170 ] ;
static char * V_171 [] = {
L_2 ,
L_3 ,
L_4 ,
NULL
} ;
char * V_172 [ 8 ] ;
int error ;
F_90 ( (struct V_173 * ) & V_61 -> V_174 , V_169 , sizeof( V_169 ) ) ;
F_91 ( V_175
L_5
L_6 , V_169 ) ;
V_172 [ 0 ] = L_7 ;
V_172 [ 1 ] = V_169 ;
V_172 [ 2 ] = V_59 -> V_72 -> V_176 . V_40 -> V_41 -> V_177 ;
V_172 [ 3 ] = NULL ;
error = F_92 ( V_172 [ 0 ] , V_172 , V_171 , V_178 ) ;
if ( error ) {
F_91 ( V_179 L_8 ,
V_169 , error ) ;
}
}
static void
F_93 ( struct V_180 * V_181 )
{
struct V_58 * V_59 =
F_51 ( V_181 , struct V_58 , V_103 ) ;
F_50 ( & V_59 -> V_101 ) ;
F_71 ( & V_59 -> V_182 , & V_59 -> V_62 ) ;
F_53 ( & V_59 -> V_101 ) ;
}
static int
F_94 ( struct V_180 * V_181 , struct V_183 * V_184 )
{
struct V_58 * V_59 =
F_51 ( V_181 , struct V_58 , V_103 ) ;
struct V_185 * V_186 ;
T_6 V_187 , V_188 ;
const struct V_189 * V_190 ;
F_79 ( V_157 ) ;
switch ( V_184 -> V_191 ) {
case 0 :
case - V_192 :
if ( F_56 ( & V_59 -> V_100 ) )
return 1 ;
V_187 = F_95 () ;
V_186 = F_46 ( V_59 -> V_62 . V_63 -> V_193 , V_120 ) ;
V_188 = F_96 ( V_184 -> V_194 ,
V_186 -> V_195 * V_196 * 2 ) ;
if ( F_97 ( V_187 , V_188 ) ) {
F_98 ( V_184 , V_197 / 100 ) ;
return 0 ;
}
case - V_198 :
F_99 ( & V_59 -> V_62 . V_67 ) ;
V_184 -> V_191 = 0 ;
return 1 ;
default:
F_100 ( & V_59 -> V_62 . V_67 ) ;
V_190 = V_189 [ V_59 -> V_102 ] ;
if ( V_190 -> V_199 )
V_190 -> V_199 ( V_59 ) ;
else
F_89 ( V_59 ) ;
return - 1 ;
}
}
static void
F_101 ( struct V_180 * V_181 )
{
struct V_58 * V_59 =
F_51 ( V_181 , struct V_58 , V_103 ) ;
F_79 ( V_157 ) ;
F_102 ( & V_59 -> V_62 . V_67 ) ;
F_85 ( V_59 , & V_157 ) ;
F_72 ( & V_157 ) ;
F_49 ( & V_59 -> V_62 ) ;
}
static bool
F_103 ( struct V_77 * V_78 )
{
V_78 -> V_200 = 0 ;
F_54 ( V_78 -> V_88 ) ;
return false ;
}
static int
F_104 ( struct V_77 * V_201 , int V_202 ,
struct V_156 * V_203 )
{
F_31 ( ! ( V_202 & V_73 ) ) ;
return F_105 ( V_201 , V_202 , V_203 ) ;
}
int
F_106 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_35 ( & V_25 [ V_13 ] ) ;
V_152 = F_107 ( L_9 ,
sizeof( struct V_136 ) , 0 , 0 , NULL ) ;
if ( ! V_152 )
return - V_30 ;
V_76 = F_107 ( L_10 ,
sizeof( struct V_58 ) , 0 , 0 , NULL ) ;
if ( ! V_76 ) {
F_108 ( V_152 ) ;
return - V_30 ;
}
return 0 ;
}
void
F_109 ( void )
{
int V_13 ;
F_108 ( V_152 ) ;
F_108 ( V_76 ) ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ ) {
struct V_10 * V_11 , * V_143 ;
F_67 (map, n, &nfsd_devid_hash[i], hash)
F_10 ( V_11 ) ;
}
}
