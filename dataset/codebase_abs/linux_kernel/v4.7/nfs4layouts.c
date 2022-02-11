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
if ( F_52 ( V_111 , & V_54 -> V_64 ) )
goto V_124;
if ( V_93 != V_56 -> V_99 )
goto V_124;
}
* V_113 = V_56 ;
return 0 ;
V_124:
F_53 ( & V_56 -> V_98 ) ;
V_122:
F_49 ( V_54 ) ;
V_118:
return V_76 ;
}
static void
F_54 ( struct V_55 * V_56 )
{
F_6 ( & V_56 -> V_96 ) ;
if ( V_56 -> V_71 )
goto V_21;
V_56 -> V_71 = true ;
F_55 ( & V_56 -> V_59 . V_63 -> V_72 ) ;
if ( F_56 ( & V_56 -> V_97 ) )
goto V_21;
F_57 ( & V_56 -> V_59 . V_64 ) ;
F_55 ( & V_56 -> V_59 . V_125 ) ;
F_58 ( & V_56 -> V_100 ) ;
V_21:
F_9 ( & V_56 -> V_96 ) ;
}
static inline T_2
F_59 ( struct V_126 * V_127 )
{
T_2 V_128 = V_127 -> V_129 + V_127 -> V_130 ;
return V_128 >= V_127 -> V_129 ? V_128 : V_131 ;
}
static void
F_60 ( struct V_126 * V_132 , T_2 V_128 )
{
if ( V_128 == V_131 )
V_132 -> V_130 = V_131 ;
else
V_132 -> V_130 = V_128 - V_132 -> V_129 ;
}
static bool
F_61 ( struct V_133 * V_132 , struct V_126 * V_134 )
{
if ( V_134 -> V_135 != V_136 && V_134 -> V_135 != V_132 -> V_137 . V_135 )
return false ;
if ( F_59 ( & V_132 -> V_137 ) <= V_134 -> V_129 )
return false ;
if ( F_59 ( V_134 ) <= V_132 -> V_137 . V_129 )
return false ;
return true ;
}
static bool
F_62 ( struct V_126 * V_132 , struct V_126 * V_138 )
{
if ( V_132 -> V_135 != V_138 -> V_135 )
return false ;
if ( F_59 ( V_138 ) < V_132 -> V_129 )
return false ;
if ( F_59 ( V_132 ) < V_138 -> V_129 )
return false ;
V_132 -> V_129 = F_63 ( V_132 -> V_129 , V_138 -> V_129 ) ;
F_60 ( V_132 , F_64 ( F_59 ( V_132 ) , F_59 ( V_138 ) ) ) ;
return true ;
}
static T_4
F_65 ( struct V_55 * V_56 )
{
struct V_61 * V_62 = V_56 -> V_59 . V_63 ;
struct V_55 * V_139 , * V_140 ;
T_4 V_141 = V_142 ;
F_66 ( & V_62 -> V_67 ) ;
F_67 (l, n, &fp->fi_lo_states, ls_perfile) {
if ( V_139 != V_56 ) {
F_54 ( V_139 ) ;
V_141 = V_143 ;
}
}
return V_141 ;
}
T_4
F_68 ( struct V_144 * V_145 , struct V_55 * V_56 )
{
struct V_126 * V_127 = & V_145 -> V_146 ;
struct V_61 * V_62 = V_56 -> V_59 . V_63 ;
struct V_133 * V_147 , * V_138 = NULL ;
T_4 V_141 ;
F_6 ( & V_62 -> V_67 ) ;
V_141 = F_65 ( V_56 ) ;
if ( V_141 )
goto V_118;
F_6 ( & V_56 -> V_96 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_62 ( & V_147 -> V_137 , V_127 ) )
goto V_148;
}
F_9 ( & V_56 -> V_96 ) ;
F_9 ( & V_62 -> V_67 ) ;
V_138 = F_69 ( V_149 , V_14 ) ;
if ( ! V_138 )
return V_123 ;
memcpy ( & V_138 -> V_137 , V_127 , sizeof( V_147 -> V_137 ) ) ;
V_138 -> V_150 = V_56 ;
F_6 ( & V_62 -> V_67 ) ;
V_141 = F_65 ( V_56 ) ;
if ( V_141 )
goto V_118;
F_6 ( & V_56 -> V_96 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_62 ( & V_147 -> V_137 , V_127 ) )
goto V_148;
}
F_55 ( & V_56 -> V_59 . V_125 ) ;
F_70 ( & V_138 -> V_151 , & V_56 -> V_97 ) ;
V_138 = NULL ;
V_148:
F_71 ( & V_145 -> V_152 , & V_56 -> V_59 ) ;
F_9 ( & V_56 -> V_96 ) ;
V_118:
F_9 ( & V_62 -> V_67 ) ;
if ( V_138 )
F_26 ( V_149 , V_138 ) ;
return V_141 ;
}
static void
F_72 ( struct V_153 * V_154 )
{
while ( ! F_56 ( V_154 ) ) {
struct V_133 * V_147 = F_73 ( V_154 ,
struct V_133 , V_151 ) ;
F_74 ( & V_147 -> V_151 ) ;
F_49 ( & V_147 -> V_150 -> V_59 ) ;
F_26 ( V_149 , V_147 ) ;
}
}
static void
F_75 ( struct V_133 * V_147 , struct V_126 * V_127 ,
struct V_153 * V_154 )
{
struct V_126 * V_132 = & V_147 -> V_137 ;
T_2 V_128 = F_59 ( V_132 ) ;
if ( V_127 -> V_129 <= V_132 -> V_129 ) {
if ( F_59 ( V_127 ) >= V_128 ) {
F_76 ( & V_147 -> V_151 , V_154 ) ;
return;
}
V_132 -> V_129 = F_59 ( V_127 ) ;
} else {
if ( F_59 ( V_127 ) < V_128 ) {
F_77 ( L_1 , V_155 ) ;
return;
}
V_128 = V_127 -> V_129 ;
}
F_60 ( V_132 , V_128 ) ;
}
T_4
F_78 ( struct V_109 * V_110 ,
struct V_90 * V_91 ,
struct V_156 * V_157 )
{
struct V_55 * V_56 ;
struct V_133 * V_147 , * V_140 ;
F_79 ( V_154 ) ;
T_4 V_141 ;
int V_158 = 0 ;
V_141 = F_44 ( V_110 , V_91 , & V_157 -> V_159 ,
false , V_157 -> V_160 ,
& V_56 ) ;
if ( V_141 ) {
F_80 ( & V_157 -> V_159 ) ;
return V_141 ;
}
F_6 ( & V_56 -> V_96 ) ;
F_67 (lp, n, &ls->ls_layouts, lo_perstate) {
if ( F_61 ( V_147 , & V_157 -> V_161 ) ) {
F_75 ( V_147 , & V_157 -> V_161 , & V_154 ) ;
V_158 ++ ;
}
}
if ( ! F_56 ( & V_56 -> V_97 ) ) {
if ( V_158 )
F_71 ( & V_157 -> V_159 , & V_56 -> V_59 ) ;
V_157 -> V_162 = 1 ;
} else {
F_81 ( & V_56 -> V_59 . V_64 ) ;
F_82 ( & V_56 -> V_59 ) ;
V_157 -> V_162 = 0 ;
}
F_9 ( & V_56 -> V_96 ) ;
F_53 ( & V_56 -> V_98 ) ;
F_49 ( & V_56 -> V_59 ) ;
F_72 ( & V_154 ) ;
return V_142 ;
}
T_4
F_83 ( struct V_109 * V_110 ,
struct V_90 * V_91 ,
struct V_156 * V_157 )
{
struct V_55 * V_56 , * V_140 ;
struct V_57 * V_58 = V_91 -> V_58 ;
struct V_133 * V_147 , * V_163 ;
F_79 ( V_154 ) ;
V_157 -> V_162 = 0 ;
F_6 ( & V_58 -> V_65 ) ;
F_67 (ls, n, &clp->cl_lo_states, ls_perclnt) {
if ( V_56 -> V_99 != V_157 -> V_160 )
continue;
if ( V_157 -> V_164 == V_165 &&
! F_84 ( & V_56 -> V_59 . V_63 -> V_120 ,
& V_91 -> V_119 . V_7 ) )
continue;
F_6 ( & V_56 -> V_96 ) ;
F_67 (lp, t, &ls->ls_layouts, lo_perstate) {
if ( V_157 -> V_161 . V_135 == V_136 ||
V_157 -> V_161 . V_135 == V_147 -> V_137 . V_135 )
F_76 ( & V_147 -> V_151 , & V_154 ) ;
}
F_9 ( & V_56 -> V_96 ) ;
}
F_9 ( & V_58 -> V_65 ) ;
F_72 ( & V_154 ) ;
return 0 ;
}
static void
F_85 ( struct V_55 * V_56 ,
struct V_153 * V_154 )
{
F_6 ( & V_56 -> V_96 ) ;
F_86 ( & V_56 -> V_97 , V_154 ) ;
F_9 ( & V_56 -> V_96 ) ;
}
void
F_87 ( struct V_57 * V_58 )
{
struct V_55 * V_56 , * V_140 ;
F_79 ( V_154 ) ;
F_6 ( & V_58 -> V_65 ) ;
F_67 (ls, n, &clp->cl_lo_states, ls_perclnt)
F_85 ( V_56 , & V_154 ) ;
F_9 ( & V_58 -> V_65 ) ;
F_72 ( & V_154 ) ;
}
void
F_88 ( struct V_57 * V_58 , struct V_61 * V_62 )
{
struct V_55 * V_56 , * V_140 ;
F_79 ( V_154 ) ;
F_6 ( & V_62 -> V_67 ) ;
F_67 (ls, n, &fp->fi_lo_states, ls_perfile) {
if ( V_56 -> V_59 . V_60 == V_58 )
F_85 ( V_56 , & V_154 ) ;
}
F_9 ( & V_62 -> V_67 ) ;
F_72 ( & V_154 ) ;
}
static void
F_89 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = V_56 -> V_59 . V_60 ;
char V_166 [ V_167 ] ;
static char * V_168 [] = {
L_2 ,
L_3 ,
L_4 ,
NULL
} ;
char * V_169 [ 8 ] ;
int error ;
F_90 ( (struct V_170 * ) & V_58 -> V_171 , V_166 , sizeof( V_166 ) ) ;
F_91 ( V_172
L_5
L_6 , V_166 ) ;
V_169 [ 0 ] = L_7 ;
V_169 [ 1 ] = V_166 ;
V_169 [ 2 ] = V_56 -> V_69 -> V_173 . V_38 -> V_39 -> V_174 ;
V_169 [ 3 ] = NULL ;
error = F_92 ( V_169 [ 0 ] , V_169 , V_168 , V_175 ) ;
if ( error ) {
F_91 ( V_176 L_8 ,
V_166 , error ) ;
}
}
static void
F_93 ( struct V_177 * V_178 )
{
struct V_55 * V_56 =
F_51 ( V_178 , struct V_55 , V_100 ) ;
F_50 ( & V_56 -> V_98 ) ;
F_71 ( & V_56 -> V_179 , & V_56 -> V_59 ) ;
F_53 ( & V_56 -> V_98 ) ;
}
static int
F_94 ( struct V_177 * V_178 , struct V_180 * V_181 )
{
struct V_55 * V_56 =
F_51 ( V_178 , struct V_55 , V_100 ) ;
struct V_182 * V_183 ;
T_6 V_184 , V_185 ;
const struct V_186 * V_187 ;
F_79 ( V_154 ) ;
switch ( V_181 -> V_188 ) {
case 0 :
case - V_189 :
if ( F_56 ( & V_56 -> V_97 ) )
return 1 ;
V_184 = F_95 () ;
V_183 = F_46 ( V_56 -> V_59 . V_60 -> V_190 , V_117 ) ;
V_185 = F_96 ( V_181 -> V_191 ,
V_183 -> V_192 * V_193 * 2 ) ;
if ( F_97 ( V_184 , V_185 ) ) {
F_98 ( V_181 , V_194 / 100 ) ;
return 0 ;
}
case - V_195 :
F_99 ( & V_56 -> V_59 . V_64 ) ;
V_181 -> V_188 = 0 ;
return 1 ;
default:
F_100 ( & V_56 -> V_59 . V_64 ) ;
V_187 = V_186 [ V_56 -> V_99 ] ;
if ( V_187 -> V_196 )
V_187 -> V_196 ( V_56 ) ;
else
F_89 ( V_56 ) ;
return - 1 ;
}
}
static void
F_101 ( struct V_177 * V_178 )
{
struct V_55 * V_56 =
F_51 ( V_178 , struct V_55 , V_100 ) ;
F_79 ( V_154 ) ;
F_102 ( & V_56 -> V_59 . V_64 ) ;
F_85 ( V_56 , & V_154 ) ;
F_72 ( & V_154 ) ;
F_49 ( & V_56 -> V_59 ) ;
}
static bool
F_103 ( struct V_74 * V_75 )
{
V_75 -> V_197 = 0 ;
F_54 ( V_75 -> V_85 ) ;
return false ;
}
static int
F_104 ( struct V_74 * V_198 , int V_199 ,
struct V_153 * V_200 )
{
F_31 ( ! ( V_199 & V_70 ) ) ;
return F_105 ( V_198 , V_199 , V_200 ) ;
}
int
F_106 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_35 ( & V_25 [ V_13 ] ) ;
V_149 = F_107 ( L_9 ,
sizeof( struct V_133 ) , 0 , 0 , NULL ) ;
if ( ! V_149 )
return - V_30 ;
V_73 = F_107 ( L_10 ,
sizeof( struct V_55 ) , 0 , 0 , NULL ) ;
if ( ! V_73 ) {
F_108 ( V_149 ) ;
return - V_30 ;
}
return 0 ;
}
void
F_109 ( void )
{
int V_13 ;
F_108 ( V_149 ) ;
F_108 ( V_73 ) ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ ) {
struct V_10 * V_11 , * V_140 ;
F_67 (map, n, &nfsd_devid_hash[i], hash)
F_10 ( V_11 ) ;
}
}
