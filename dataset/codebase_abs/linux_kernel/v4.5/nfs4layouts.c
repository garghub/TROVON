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
if ( V_36 -> V_42 -> V_43 &&
V_36 -> V_42 -> V_44 &&
V_36 -> V_42 -> V_45 )
exp -> V_46 = V_47 ;
}
static void
F_17 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = F_18 ( V_49 ) ;
struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
struct V_56 * V_57 = V_51 -> V_54 . V_58 ;
F_19 ( & V_51 -> V_54 . V_59 ) ;
F_6 ( & V_53 -> V_60 ) ;
F_20 ( & V_51 -> V_61 ) ;
F_9 ( & V_53 -> V_60 ) ;
F_6 ( & V_57 -> V_62 ) ;
F_20 ( & V_51 -> V_63 ) ;
F_9 ( & V_57 -> V_62 ) ;
F_21 ( V_51 -> V_64 , V_65 , NULL , ( void * * ) & V_51 ) ;
F_22 ( V_51 -> V_64 ) ;
if ( V_51 -> V_66 )
F_23 ( & V_51 -> V_54 . V_58 -> V_67 ) ;
F_24 ( V_68 , V_51 ) ;
}
static int
F_25 ( struct V_50 * V_51 )
{
struct V_69 * V_70 ;
int V_71 ;
V_70 = F_26 () ;
if ( ! V_70 )
return - V_30 ;
F_27 ( V_70 ) ;
V_70 -> V_72 = & V_73 ;
V_70 -> V_74 = V_75 ;
V_70 -> V_76 = V_77 ;
V_70 -> V_78 = V_79 ;
V_70 -> V_80 = V_51 ;
V_70 -> V_81 = V_82 -> V_83 ;
V_70 -> V_84 = V_51 -> V_64 ;
V_71 = F_21 ( V_70 -> V_84 , V_70 -> V_76 , & V_70 , NULL ) ;
if ( V_71 ) {
F_28 ( V_70 ) ;
return V_71 ;
}
F_29 ( V_70 != NULL ) ;
return 0 ;
}
static struct V_50 *
F_30 ( struct V_85 * V_86 ,
struct V_48 * V_87 , T_1 V_88 )
{
struct V_52 * V_53 = V_86 -> V_53 ;
struct V_56 * V_57 = V_87 -> V_58 ;
struct V_50 * V_51 ;
struct V_48 * V_89 ;
V_89 = F_31 ( V_86 -> V_53 , V_68 ) ;
if ( ! V_89 )
return NULL ;
V_89 -> V_90 = F_17 ;
F_32 ( V_57 ) ;
V_89 -> V_58 = V_57 ;
V_51 = F_18 ( V_89 ) ;
F_33 ( & V_51 -> V_61 ) ;
F_33 ( & V_51 -> V_63 ) ;
F_34 ( & V_51 -> V_91 ) ;
F_33 ( & V_51 -> V_92 ) ;
F_35 ( & V_51 -> V_93 ) ;
V_51 -> V_94 = V_88 ;
F_36 ( & V_51 -> V_95 , V_53 , & V_96 ,
V_97 ) ;
if ( V_87 -> V_98 == V_99 )
V_51 -> V_64 = F_37 ( V_57 -> V_100 ) ;
else
V_51 -> V_64 = F_38 ( V_57 ) ;
F_29 ( ! V_51 -> V_64 ) ;
if ( F_25 ( V_51 ) ) {
F_22 ( V_51 -> V_64 ) ;
F_39 ( V_57 ) ;
F_24 ( V_68 , V_51 ) ;
return NULL ;
}
F_6 ( & V_53 -> V_60 ) ;
V_89 -> V_98 = V_101 ;
F_40 ( & V_51 -> V_61 , & V_53 -> V_102 ) ;
F_9 ( & V_53 -> V_60 ) ;
F_6 ( & V_57 -> V_62 ) ;
F_40 ( & V_51 -> V_63 , & V_57 -> V_103 ) ;
F_9 ( & V_57 -> V_62 ) ;
F_41 ( & V_51 -> V_54 . V_59 ) ;
return V_51 ;
}
T_4
F_42 ( struct V_104 * V_105 ,
struct V_85 * V_86 , T_5 * V_106 ,
bool V_107 , T_1 V_88 , struct V_50 * * V_108 )
{
struct V_50 * V_51 ;
struct V_48 * V_49 ;
unsigned char V_109 = V_101 ;
T_4 V_71 ;
if ( V_107 )
V_109 |= ( V_110 | V_111 | V_99 ) ;
V_71 = F_43 ( V_86 , V_106 , V_109 , & V_49 ,
F_44 ( F_45 ( V_105 ) , V_112 ) ) ;
if ( V_71 )
goto V_113;
if ( ! F_46 ( & V_86 -> V_114 . V_7 ,
& V_49 -> V_58 -> V_115 ) ) {
V_71 = V_116 ;
goto V_117;
}
if ( V_49 -> V_98 != V_101 ) {
V_51 = F_30 ( V_86 , V_49 , V_88 ) ;
F_47 ( V_49 ) ;
V_71 = V_118 ;
if ( ! V_51 )
goto V_113;
F_48 ( & V_51 -> V_93 ) ;
} else {
V_51 = F_49 ( V_49 , struct V_50 , V_54 ) ;
V_71 = V_116 ;
F_48 ( & V_51 -> V_93 ) ;
if ( V_106 -> V_119 > V_49 -> V_59 . V_119 )
goto V_120;
if ( V_88 != V_51 -> V_94 )
goto V_120;
}
* V_108 = V_51 ;
return 0 ;
V_120:
F_50 ( & V_51 -> V_93 ) ;
V_117:
F_47 ( V_49 ) ;
V_113:
return V_71 ;
}
static void
F_51 ( struct V_50 * V_51 )
{
F_6 ( & V_51 -> V_91 ) ;
if ( V_51 -> V_66 )
goto V_21;
V_51 -> V_66 = true ;
F_52 ( & V_51 -> V_54 . V_58 -> V_67 ) ;
if ( F_53 ( & V_51 -> V_92 ) )
goto V_21;
F_54 ( & V_51 -> V_54 . V_59 ) ;
F_52 ( & V_51 -> V_54 . V_121 ) ;
F_55 ( & V_51 -> V_95 ) ;
V_21:
F_9 ( & V_51 -> V_91 ) ;
}
static inline T_2
F_56 ( struct V_122 * V_123 )
{
T_2 V_124 = V_123 -> V_125 + V_123 -> V_126 ;
return V_124 >= V_123 -> V_125 ? V_124 : V_127 ;
}
static void
F_57 ( struct V_122 * V_128 , T_2 V_124 )
{
if ( V_124 == V_127 )
V_128 -> V_126 = V_127 ;
else
V_128 -> V_126 = V_124 - V_128 -> V_125 ;
}
static bool
F_58 ( struct V_129 * V_128 , struct V_122 * V_130 )
{
if ( V_130 -> V_131 != V_132 && V_130 -> V_131 != V_128 -> V_133 . V_131 )
return false ;
if ( F_56 ( & V_128 -> V_133 ) <= V_130 -> V_125 )
return false ;
if ( F_56 ( V_130 ) <= V_128 -> V_133 . V_125 )
return false ;
return true ;
}
static bool
F_59 ( struct V_122 * V_128 , struct V_122 * V_134 )
{
if ( V_128 -> V_131 != V_134 -> V_131 )
return false ;
if ( F_56 ( V_134 ) < V_128 -> V_125 )
return false ;
if ( F_56 ( V_128 ) < V_134 -> V_125 )
return false ;
V_128 -> V_125 = F_60 ( V_128 -> V_125 , V_134 -> V_125 ) ;
F_57 ( V_128 , F_61 ( F_56 ( V_128 ) , F_56 ( V_134 ) ) ) ;
return true ;
}
static T_4
F_62 ( struct V_50 * V_51 )
{
struct V_56 * V_57 = V_51 -> V_54 . V_58 ;
struct V_50 * V_135 , * V_136 ;
T_4 V_137 = V_138 ;
F_63 ( & V_57 -> V_62 ) ;
F_64 (l, n, &fp->fi_lo_states, ls_perfile) {
if ( V_135 != V_51 ) {
F_51 ( V_135 ) ;
V_137 = V_139 ;
}
}
return V_137 ;
}
T_4
F_65 ( struct V_140 * V_141 , struct V_50 * V_51 )
{
struct V_122 * V_123 = & V_141 -> V_142 ;
struct V_56 * V_57 = V_51 -> V_54 . V_58 ;
struct V_129 * V_143 , * V_134 = NULL ;
T_4 V_137 ;
F_6 ( & V_57 -> V_62 ) ;
V_137 = F_62 ( V_51 ) ;
if ( V_137 )
goto V_113;
F_6 ( & V_51 -> V_91 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_59 ( & V_143 -> V_133 , V_123 ) )
goto V_144;
}
F_9 ( & V_51 -> V_91 ) ;
F_9 ( & V_57 -> V_62 ) ;
V_134 = F_66 ( V_145 , V_14 ) ;
if ( ! V_134 )
return V_118 ;
memcpy ( & V_134 -> V_133 , V_123 , sizeof( V_143 -> V_133 ) ) ;
V_134 -> V_146 = V_51 ;
F_6 ( & V_57 -> V_62 ) ;
V_137 = F_62 ( V_51 ) ;
if ( V_137 )
goto V_113;
F_6 ( & V_51 -> V_91 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_59 ( & V_143 -> V_133 , V_123 ) )
goto V_144;
}
F_52 ( & V_51 -> V_54 . V_121 ) ;
F_67 ( & V_134 -> V_147 , & V_51 -> V_92 ) ;
V_134 = NULL ;
V_144:
F_68 ( & V_141 -> V_148 , & V_51 -> V_54 ) ;
F_9 ( & V_51 -> V_91 ) ;
V_113:
F_9 ( & V_57 -> V_62 ) ;
if ( V_134 )
F_24 ( V_145 , V_134 ) ;
return V_137 ;
}
static void
F_69 ( struct V_149 * V_150 )
{
while ( ! F_53 ( V_150 ) ) {
struct V_129 * V_143 = F_70 ( V_150 ,
struct V_129 , V_147 ) ;
F_71 ( & V_143 -> V_147 ) ;
F_47 ( & V_143 -> V_146 -> V_54 ) ;
F_24 ( V_145 , V_143 ) ;
}
}
static void
F_72 ( struct V_129 * V_143 , struct V_122 * V_123 ,
struct V_149 * V_150 )
{
struct V_122 * V_128 = & V_143 -> V_133 ;
T_2 V_124 = F_56 ( V_128 ) ;
if ( V_123 -> V_125 <= V_128 -> V_125 ) {
if ( F_56 ( V_123 ) >= V_124 ) {
F_73 ( & V_143 -> V_147 , V_150 ) ;
return;
}
V_128 -> V_125 = F_56 ( V_123 ) ;
} else {
if ( F_56 ( V_123 ) < V_124 ) {
F_74 ( L_1 , V_151 ) ;
return;
}
V_124 = V_123 -> V_125 ;
}
F_57 ( V_128 , V_124 ) ;
}
T_4
F_75 ( struct V_104 * V_105 ,
struct V_85 * V_86 ,
struct V_152 * V_153 )
{
struct V_50 * V_51 ;
struct V_129 * V_143 , * V_136 ;
F_76 ( V_150 ) ;
T_4 V_137 ;
int V_154 = 0 ;
V_137 = F_42 ( V_105 , V_86 , & V_153 -> V_155 ,
false , V_153 -> V_156 ,
& V_51 ) ;
if ( V_137 ) {
F_77 ( & V_153 -> V_155 ) ;
return V_137 ;
}
F_6 ( & V_51 -> V_91 ) ;
F_64 (lp, n, &ls->ls_layouts, lo_perstate) {
if ( F_58 ( V_143 , & V_153 -> V_157 ) ) {
F_72 ( V_143 , & V_153 -> V_157 , & V_150 ) ;
V_154 ++ ;
}
}
if ( ! F_53 ( & V_51 -> V_92 ) ) {
if ( V_154 )
F_68 ( & V_153 -> V_155 , & V_51 -> V_54 ) ;
V_153 -> V_158 = 1 ;
} else {
F_78 ( & V_51 -> V_54 . V_59 ) ;
F_79 ( & V_51 -> V_54 ) ;
V_153 -> V_158 = 0 ;
}
F_9 ( & V_51 -> V_91 ) ;
F_50 ( & V_51 -> V_93 ) ;
F_47 ( & V_51 -> V_54 ) ;
F_69 ( & V_150 ) ;
return V_138 ;
}
T_4
F_80 ( struct V_104 * V_105 ,
struct V_85 * V_86 ,
struct V_152 * V_153 )
{
struct V_50 * V_51 , * V_136 ;
struct V_52 * V_53 = V_86 -> V_53 ;
struct V_129 * V_143 , * V_159 ;
F_76 ( V_150 ) ;
V_153 -> V_158 = 0 ;
F_6 ( & V_53 -> V_60 ) ;
F_64 (ls, n, &clp->cl_lo_states, ls_perclnt) {
if ( V_51 -> V_94 != V_153 -> V_156 )
continue;
if ( V_153 -> V_160 == V_161 &&
! F_81 ( & V_51 -> V_54 . V_58 -> V_115 ,
& V_86 -> V_114 . V_7 ) )
continue;
F_6 ( & V_51 -> V_91 ) ;
F_64 (lp, t, &ls->ls_layouts, lo_perstate) {
if ( V_153 -> V_157 . V_131 == V_132 ||
V_153 -> V_157 . V_131 == V_143 -> V_133 . V_131 )
F_73 ( & V_143 -> V_147 , & V_150 ) ;
}
F_9 ( & V_51 -> V_91 ) ;
}
F_9 ( & V_53 -> V_60 ) ;
F_69 ( & V_150 ) ;
return 0 ;
}
static void
F_82 ( struct V_50 * V_51 ,
struct V_149 * V_150 )
{
F_6 ( & V_51 -> V_91 ) ;
F_83 ( & V_51 -> V_92 , V_150 ) ;
F_9 ( & V_51 -> V_91 ) ;
}
void
F_84 ( struct V_52 * V_53 )
{
struct V_50 * V_51 , * V_136 ;
F_76 ( V_150 ) ;
F_6 ( & V_53 -> V_60 ) ;
F_64 (ls, n, &clp->cl_lo_states, ls_perclnt)
F_82 ( V_51 , & V_150 ) ;
F_9 ( & V_53 -> V_60 ) ;
F_69 ( & V_150 ) ;
}
void
F_85 ( struct V_52 * V_53 , struct V_56 * V_57 )
{
struct V_50 * V_51 , * V_136 ;
F_76 ( V_150 ) ;
F_6 ( & V_57 -> V_62 ) ;
F_64 (ls, n, &fp->fi_lo_states, ls_perfile) {
if ( V_51 -> V_54 . V_55 == V_53 )
F_82 ( V_51 , & V_150 ) ;
}
F_9 ( & V_57 -> V_62 ) ;
F_69 ( & V_150 ) ;
}
static void
F_86 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
char V_162 [ V_163 ] ;
static char * V_164 [] = {
L_2 ,
L_3 ,
L_4 ,
NULL
} ;
char * V_165 [ 8 ] ;
int error ;
F_87 ( (struct V_166 * ) & V_53 -> V_167 , V_162 , sizeof( V_162 ) ) ;
F_88 ( & V_51 -> V_54 . V_59 ) ;
F_89 ( V_168
L_5
L_6 , V_162 ) ;
V_165 [ 0 ] = L_7 ;
V_165 [ 1 ] = V_162 ;
V_165 [ 2 ] = V_51 -> V_64 -> V_169 . V_38 -> V_39 -> V_170 ;
V_165 [ 3 ] = NULL ;
error = F_90 ( V_165 [ 0 ] , V_165 , V_164 , V_171 ) ;
if ( error ) {
F_89 ( V_172 L_8 ,
V_162 , error ) ;
}
}
static void
F_91 ( struct V_173 * V_174 )
{
struct V_50 * V_51 =
F_49 ( V_174 , struct V_50 , V_95 ) ;
F_48 ( & V_51 -> V_93 ) ;
F_68 ( & V_51 -> V_175 , & V_51 -> V_54 ) ;
F_50 ( & V_51 -> V_93 ) ;
}
static int
F_92 ( struct V_173 * V_174 , struct V_176 * V_177 )
{
struct V_50 * V_51 =
F_49 ( V_174 , struct V_50 , V_95 ) ;
struct V_178 * V_179 ;
T_6 V_180 , V_181 ;
F_76 ( V_150 ) ;
switch ( V_177 -> V_182 ) {
case 0 :
case - V_183 :
if ( F_53 ( & V_51 -> V_92 ) )
return 1 ;
V_180 = F_93 () ;
V_179 = F_44 ( V_51 -> V_54 . V_55 -> V_184 , V_112 ) ;
V_181 = F_94 ( V_177 -> V_185 ,
V_179 -> V_186 * V_187 * 2 ) ;
if ( F_95 ( V_180 , V_181 ) ) {
F_96 ( V_177 , V_188 / 100 ) ;
return 0 ;
}
case - V_189 :
F_97 ( & V_51 -> V_54 . V_59 ) ;
V_177 -> V_182 = 0 ;
return 1 ;
default:
F_86 ( V_51 ) ;
return - 1 ;
}
}
static void
F_98 ( struct V_173 * V_174 )
{
struct V_50 * V_51 =
F_49 ( V_174 , struct V_50 , V_95 ) ;
F_76 ( V_150 ) ;
F_99 ( & V_51 -> V_54 . V_59 ) ;
F_82 ( V_51 , & V_150 ) ;
F_69 ( & V_150 ) ;
F_47 ( & V_51 -> V_54 ) ;
}
static bool
F_100 ( struct V_69 * V_70 )
{
V_70 -> V_190 = 0 ;
F_51 ( V_70 -> V_80 ) ;
return false ;
}
static int
F_101 ( struct V_69 * V_191 , int V_192 ,
struct V_149 * V_193 )
{
F_29 ( ! ( V_192 & V_65 ) ) ;
return F_102 ( V_191 , V_192 , V_193 ) ;
}
int
F_103 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_33 ( & V_25 [ V_13 ] ) ;
V_145 = F_104 ( L_9 ,
sizeof( struct V_129 ) , 0 , 0 , NULL ) ;
if ( ! V_145 )
return - V_30 ;
V_68 = F_104 ( L_10 ,
sizeof( struct V_50 ) , 0 , 0 , NULL ) ;
if ( ! V_68 ) {
F_105 ( V_145 ) ;
return - V_30 ;
}
return 0 ;
}
void
F_106 ( void )
{
int V_13 ;
F_105 ( V_145 ) ;
F_105 ( V_68 ) ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ ) {
struct V_10 * V_11 , * V_136 ;
F_64 (map, n, &nfsd_devid_hash[i], hash)
F_10 ( V_11 ) ;
}
}
