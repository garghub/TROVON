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
V_51 -> V_93 = V_88 ;
F_35 ( & V_51 -> V_94 , V_53 , & V_95 ,
V_96 ) ;
if ( V_87 -> V_97 == V_98 )
V_51 -> V_64 = F_36 ( V_57 -> V_99 ) ;
else
V_51 -> V_64 = F_37 ( V_57 ) ;
F_29 ( ! V_51 -> V_64 ) ;
if ( F_25 ( V_51 ) ) {
F_38 ( V_57 ) ;
F_24 ( V_68 , V_51 ) ;
return NULL ;
}
F_6 ( & V_53 -> V_60 ) ;
V_89 -> V_97 = V_100 ;
F_39 ( & V_51 -> V_61 , & V_53 -> V_101 ) ;
F_9 ( & V_53 -> V_60 ) ;
F_6 ( & V_57 -> V_62 ) ;
F_39 ( & V_51 -> V_63 , & V_57 -> V_102 ) ;
F_9 ( & V_57 -> V_62 ) ;
F_40 ( & V_51 -> V_54 . V_59 ) ;
return V_51 ;
}
T_4
F_41 ( struct V_103 * V_104 ,
struct V_85 * V_86 , T_5 * V_105 ,
bool V_106 , T_1 V_88 , struct V_50 * * V_107 )
{
struct V_50 * V_51 ;
struct V_48 * V_49 ;
unsigned char V_108 = V_100 ;
T_4 V_71 ;
if ( V_106 )
V_108 |= ( V_109 | V_110 | V_98 ) ;
V_71 = F_42 ( V_86 , V_105 , V_108 , & V_49 ,
F_43 ( F_44 ( V_104 ) , V_111 ) ) ;
if ( V_71 )
goto V_112;
if ( ! F_45 ( & V_86 -> V_113 . V_7 ,
& V_49 -> V_58 -> V_114 ) ) {
V_71 = V_115 ;
goto V_116;
}
if ( V_49 -> V_97 != V_100 ) {
V_51 = F_30 ( V_86 , V_49 , V_88 ) ;
F_46 ( V_49 ) ;
V_71 = V_117 ;
if ( ! V_51 )
goto V_112;
} else {
V_51 = F_47 ( V_49 , struct V_50 , V_54 ) ;
V_71 = V_115 ;
if ( V_105 -> V_118 > V_49 -> V_59 . V_118 )
goto V_116;
if ( V_88 != V_51 -> V_93 )
goto V_116;
}
* V_107 = V_51 ;
return 0 ;
V_116:
F_46 ( V_49 ) ;
V_112:
return V_71 ;
}
static void
F_48 ( struct V_50 * V_51 )
{
F_6 ( & V_51 -> V_91 ) ;
if ( V_51 -> V_66 )
goto V_21;
V_51 -> V_66 = true ;
F_49 ( & V_51 -> V_54 . V_58 -> V_67 ) ;
if ( F_50 ( & V_51 -> V_92 ) )
goto V_21;
F_51 ( & V_51 -> V_54 . V_59 ) ;
F_49 ( & V_51 -> V_54 . V_119 ) ;
F_52 ( & V_51 -> V_54 . V_59 ) ;
memcpy ( & V_51 -> V_120 , & V_51 -> V_54 . V_59 , sizeof( T_5 ) ) ;
F_53 ( & V_51 -> V_94 ) ;
V_21:
F_9 ( & V_51 -> V_91 ) ;
}
static inline T_2
F_54 ( struct V_121 * V_122 )
{
T_2 V_123 = V_122 -> V_124 + V_122 -> V_125 ;
return V_123 >= V_122 -> V_124 ? V_123 : V_126 ;
}
static void
F_55 ( struct V_121 * V_127 , T_2 V_123 )
{
if ( V_123 == V_126 )
V_127 -> V_125 = V_126 ;
else
V_127 -> V_125 = V_123 - V_127 -> V_124 ;
}
static bool
F_56 ( struct V_128 * V_127 , struct V_121 * V_129 )
{
if ( V_129 -> V_130 != V_131 && V_129 -> V_130 != V_127 -> V_132 . V_130 )
return false ;
if ( F_54 ( & V_127 -> V_132 ) <= V_129 -> V_124 )
return false ;
if ( F_54 ( V_129 ) <= V_127 -> V_132 . V_124 )
return false ;
return true ;
}
static bool
F_57 ( struct V_121 * V_127 , struct V_121 * V_133 )
{
if ( V_127 -> V_130 != V_133 -> V_130 )
return false ;
if ( F_54 ( V_133 ) < V_127 -> V_124 )
return false ;
if ( F_54 ( V_127 ) < V_133 -> V_124 )
return false ;
V_127 -> V_124 = F_58 ( V_127 -> V_124 , V_133 -> V_124 ) ;
F_55 ( V_127 , F_59 ( F_54 ( V_127 ) , F_54 ( V_133 ) ) ) ;
return true ;
}
static T_4
F_60 ( struct V_50 * V_51 )
{
struct V_56 * V_57 = V_51 -> V_54 . V_58 ;
struct V_50 * V_134 , * V_135 ;
T_4 V_136 = V_137 ;
F_61 ( & V_57 -> V_62 ) ;
F_62 (l, n, &fp->fi_lo_states, ls_perfile) {
if ( V_134 != V_51 ) {
F_48 ( V_134 ) ;
V_136 = V_138 ;
}
}
return V_136 ;
}
T_4
F_63 ( struct V_139 * V_140 , struct V_50 * V_51 )
{
struct V_121 * V_122 = & V_140 -> V_141 ;
struct V_56 * V_57 = V_51 -> V_54 . V_58 ;
struct V_128 * V_142 , * V_133 = NULL ;
T_4 V_136 ;
F_6 ( & V_57 -> V_62 ) ;
V_136 = F_60 ( V_51 ) ;
if ( V_136 )
goto V_112;
F_6 ( & V_51 -> V_91 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_57 ( & V_142 -> V_132 , V_122 ) )
goto V_143;
}
F_9 ( & V_51 -> V_91 ) ;
F_9 ( & V_57 -> V_62 ) ;
V_133 = F_64 ( V_144 , V_14 ) ;
if ( ! V_133 )
return V_117 ;
memcpy ( & V_133 -> V_132 , V_122 , sizeof( V_142 -> V_132 ) ) ;
V_133 -> V_145 = V_51 ;
F_6 ( & V_57 -> V_62 ) ;
V_136 = F_60 ( V_51 ) ;
if ( V_136 )
goto V_112;
F_6 ( & V_51 -> V_91 ) ;
F_7 (lp, &ls->ls_layouts, lo_perstate) {
if ( F_57 ( & V_142 -> V_132 , V_122 ) )
goto V_143;
}
F_49 ( & V_51 -> V_54 . V_119 ) ;
F_65 ( & V_133 -> V_146 , & V_51 -> V_92 ) ;
V_133 = NULL ;
V_143:
F_52 ( & V_51 -> V_54 . V_59 ) ;
memcpy ( & V_140 -> V_147 , & V_51 -> V_54 . V_59 , sizeof( T_5 ) ) ;
F_9 ( & V_51 -> V_91 ) ;
V_112:
F_9 ( & V_57 -> V_62 ) ;
if ( V_133 )
F_24 ( V_144 , V_133 ) ;
return V_136 ;
}
static void
F_66 ( struct V_148 * V_149 )
{
while ( ! F_50 ( V_149 ) ) {
struct V_128 * V_142 = F_67 ( V_149 ,
struct V_128 , V_146 ) ;
F_68 ( & V_142 -> V_146 ) ;
F_46 ( & V_142 -> V_145 -> V_54 ) ;
F_24 ( V_144 , V_142 ) ;
}
}
static void
F_69 ( struct V_128 * V_142 , struct V_121 * V_122 ,
struct V_148 * V_149 )
{
struct V_121 * V_127 = & V_142 -> V_132 ;
T_2 V_123 = F_54 ( V_127 ) ;
if ( V_122 -> V_124 <= V_127 -> V_124 ) {
if ( F_54 ( V_122 ) >= V_123 ) {
F_70 ( & V_142 -> V_146 , V_149 ) ;
return;
}
V_127 -> V_124 = F_54 ( V_122 ) ;
} else {
if ( F_54 ( V_122 ) < V_123 ) {
F_71 ( L_1 , V_150 ) ;
return;
}
V_123 = V_122 -> V_124 ;
}
F_55 ( V_127 , V_123 ) ;
}
T_4
F_72 ( struct V_103 * V_104 ,
struct V_85 * V_86 ,
struct V_151 * V_152 )
{
struct V_50 * V_51 ;
struct V_128 * V_142 , * V_135 ;
F_73 ( V_149 ) ;
T_4 V_136 ;
int V_153 = 0 ;
V_136 = F_41 ( V_104 , V_86 , & V_152 -> V_154 ,
false , V_152 -> V_155 ,
& V_51 ) ;
if ( V_136 ) {
F_74 ( & V_152 -> V_154 ) ;
return V_136 ;
}
F_6 ( & V_51 -> V_91 ) ;
F_62 (lp, n, &ls->ls_layouts, lo_perstate) {
if ( F_56 ( V_142 , & V_152 -> V_156 ) ) {
F_69 ( V_142 , & V_152 -> V_156 , & V_149 ) ;
V_153 ++ ;
}
}
if ( ! F_50 ( & V_51 -> V_92 ) ) {
if ( V_153 ) {
F_52 ( & V_51 -> V_54 . V_59 ) ;
memcpy ( & V_152 -> V_154 , & V_51 -> V_54 . V_59 ,
sizeof( T_5 ) ) ;
}
V_152 -> V_157 = 1 ;
} else {
F_75 ( & V_51 -> V_54 . V_59 ) ;
F_76 ( & V_51 -> V_54 ) ;
V_152 -> V_157 = 0 ;
}
F_9 ( & V_51 -> V_91 ) ;
F_46 ( & V_51 -> V_54 ) ;
F_66 ( & V_149 ) ;
return V_137 ;
}
T_4
F_77 ( struct V_103 * V_104 ,
struct V_85 * V_86 ,
struct V_151 * V_152 )
{
struct V_50 * V_51 , * V_135 ;
struct V_52 * V_53 = V_86 -> V_53 ;
struct V_128 * V_142 , * V_158 ;
F_73 ( V_149 ) ;
V_152 -> V_157 = 0 ;
F_6 ( & V_53 -> V_60 ) ;
F_62 (ls, n, &clp->cl_lo_states, ls_perclnt) {
if ( V_51 -> V_93 != V_152 -> V_155 )
continue;
if ( V_152 -> V_159 == V_160 &&
! F_78 ( & V_51 -> V_54 . V_58 -> V_114 ,
& V_86 -> V_113 . V_7 ) )
continue;
F_6 ( & V_51 -> V_91 ) ;
F_62 (lp, t, &ls->ls_layouts, lo_perstate) {
if ( V_152 -> V_156 . V_130 == V_131 ||
V_152 -> V_156 . V_130 == V_142 -> V_132 . V_130 )
F_70 ( & V_142 -> V_146 , & V_149 ) ;
}
F_9 ( & V_51 -> V_91 ) ;
}
F_9 ( & V_53 -> V_60 ) ;
F_66 ( & V_149 ) ;
return 0 ;
}
static void
F_79 ( struct V_50 * V_51 ,
struct V_148 * V_149 )
{
F_6 ( & V_51 -> V_91 ) ;
F_80 ( & V_51 -> V_92 , V_149 ) ;
F_9 ( & V_51 -> V_91 ) ;
}
void
F_81 ( struct V_52 * V_53 )
{
struct V_50 * V_51 , * V_135 ;
F_73 ( V_149 ) ;
F_6 ( & V_53 -> V_60 ) ;
F_62 (ls, n, &clp->cl_lo_states, ls_perclnt)
F_79 ( V_51 , & V_149 ) ;
F_9 ( & V_53 -> V_60 ) ;
F_66 ( & V_149 ) ;
}
void
F_82 ( struct V_52 * V_53 , struct V_56 * V_57 )
{
struct V_50 * V_51 , * V_135 ;
F_73 ( V_149 ) ;
F_6 ( & V_57 -> V_62 ) ;
F_62 (ls, n, &fp->fi_lo_states, ls_perfile) {
if ( V_51 -> V_54 . V_55 == V_53 )
F_79 ( V_51 , & V_149 ) ;
}
F_9 ( & V_57 -> V_62 ) ;
F_66 ( & V_149 ) ;
}
static void
F_83 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
char V_161 [ V_162 ] ;
static char * V_163 [] = {
L_2 ,
L_3 ,
L_4 ,
NULL
} ;
char * V_164 [ 8 ] ;
int error ;
F_84 ( (struct V_165 * ) & V_53 -> V_166 , V_161 , sizeof( V_161 ) ) ;
F_85 ( & V_51 -> V_54 . V_59 ) ;
F_86 ( V_167
L_5
L_6 , V_161 ) ;
V_164 [ 0 ] = L_7 ;
V_164 [ 1 ] = V_161 ;
V_164 [ 2 ] = V_51 -> V_64 -> V_168 . V_38 -> V_39 -> V_169 ;
V_164 [ 3 ] = NULL ;
error = F_87 ( V_164 [ 0 ] , V_164 , V_163 , V_170 ) ;
if ( error ) {
F_86 ( V_171 L_8 ,
V_161 , error ) ;
}
}
static int
F_88 ( struct V_172 * V_173 , struct V_174 * V_175 )
{
struct V_50 * V_51 =
F_47 ( V_173 , struct V_50 , V_94 ) ;
F_73 ( V_149 ) ;
switch ( V_175 -> V_176 ) {
case 0 :
return 1 ;
case - V_177 :
F_89 ( & V_51 -> V_54 . V_59 ) ;
V_175 -> V_176 = 0 ;
return 1 ;
case - V_178 :
F_90 ( V_175 , V_179 / 100 ) ;
return 0 ;
default:
F_83 ( V_51 ) ;
return - 1 ;
}
}
static void
F_91 ( struct V_172 * V_173 )
{
struct V_50 * V_51 =
F_47 ( V_173 , struct V_50 , V_94 ) ;
F_73 ( V_149 ) ;
F_92 ( & V_51 -> V_54 . V_59 ) ;
F_79 ( V_51 , & V_149 ) ;
F_66 ( & V_149 ) ;
F_46 ( & V_51 -> V_54 ) ;
}
static bool
F_93 ( struct V_69 * V_70 )
{
V_70 -> V_180 = 0 ;
F_48 ( V_70 -> V_80 ) ;
return false ;
}
static int
F_94 ( struct V_69 * V_181 , int V_182 ,
struct V_148 * V_183 )
{
F_29 ( ! ( V_182 & V_65 ) ) ;
return F_95 ( V_181 , V_182 , V_183 ) ;
}
int
F_96 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_33 ( & V_25 [ V_13 ] ) ;
V_144 = F_97 ( L_9 ,
sizeof( struct V_128 ) , 0 , 0 , NULL ) ;
if ( ! V_144 )
return - V_30 ;
V_68 = F_97 ( L_10 ,
sizeof( struct V_50 ) , 0 , 0 , NULL ) ;
if ( ! V_68 ) {
F_98 ( V_144 ) ;
return - V_30 ;
}
return 0 ;
}
void
F_99 ( void )
{
int V_13 ;
F_98 ( V_144 ) ;
F_98 ( V_68 ) ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ ) {
struct V_10 * V_11 , * V_135 ;
F_62 (map, n, &nfsd_devid_hash[i], hash)
F_10 ( V_11 ) ;
}
}
