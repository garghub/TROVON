static int F_1 ( enum V_1 type , const char * V_2 )
{
return V_3 [ type ] &&
! regexec ( & V_4 [ type ] , V_2 , 0 , NULL , 0 ) ;
}
static void F_2 ( int V_5 )
{
char V_6 [ 128 ] ;
int V_7 ;
int V_8 ;
if ( V_5 )
V_3 = V_9 ;
else
V_3 = V_10 ;
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
if ( ! V_3 [ V_8 ] )
continue;
V_7 = regcomp ( & V_4 [ V_8 ] , V_3 [ V_8 ] ,
V_12 | V_13 ) ;
if ( V_7 ) {
regerror ( V_7 , & V_4 [ V_8 ] , V_6 , sizeof V_6 ) ;
F_3 ( L_1 , V_6 ) ;
}
}
}
static const char * F_4 ( unsigned type )
{
static const char * V_14 [] = {
#define F_5 ( T_1 ) [X] = #X
F_5 ( V_15 ) ,
F_5 ( V_16 ) ,
F_5 ( V_17 ) ,
F_5 ( V_18 ) ,
F_5 ( V_19 ) ,
F_5 ( V_20 ) ,
F_5 ( V_21 ) ,
#undef F_5
} ;
const char * V_22 = L_2 ;
if ( type < F_6 ( V_14 ) ) {
V_22 = V_14 [ type ] ;
}
return V_22 ;
}
static const char * F_7 ( unsigned V_23 )
{
static const char * V_24 [] = {
#define F_8 ( T_1 ) [X] = #X
F_8 ( V_25 ) ,
F_8 ( V_26 ) ,
F_8 ( V_27 ) ,
#undef F_8
} ;
const char * V_22 = L_3 ;
if ( V_23 < F_6 ( V_24 ) ) {
V_22 = V_24 [ V_23 ] ;
}
return V_22 ;
}
static const char * F_9 ( unsigned V_28 )
{
static const char * V_29 [] = {
#define F_10 ( T_1 ) [X] = #X
F_10 ( V_30 ) ,
F_10 ( V_31 ) ,
F_10 ( V_32 ) ,
F_10 ( V_33 ) ,
#undef F_10
} ;
const char * V_22 = L_4 ;
if ( V_28 < F_6 ( V_29 ) ) {
V_22 = V_29 [ V_28 ] ;
}
return V_22 ;
}
static const char * F_11 ( unsigned type )
{
static const char * V_14 [] = {
#define F_12 ( T_1 ) [X] = #X
#if V_34 == 64
F_12 ( V_35 ) ,
F_12 ( V_36 ) ,
F_12 ( V_37 ) ,
F_12 ( V_38 ) ,
F_12 ( V_39 ) ,
F_12 ( V_40 ) ,
F_12 ( V_41 ) ,
F_12 ( V_42 ) ,
F_12 ( V_43 ) ,
F_12 ( V_44 ) ,
F_12 ( V_45 ) ,
F_12 ( V_46 ) ,
F_12 ( V_47 ) ,
F_12 ( V_48 ) ,
F_12 ( V_49 ) ,
F_12 ( V_50 ) ,
#else
F_12 ( V_51 ) ,
F_12 ( V_52 ) ,
F_12 ( V_53 ) ,
F_12 ( V_54 ) ,
F_12 ( V_55 ) ,
F_12 ( V_56 ) ,
F_12 ( V_57 ) ,
F_12 ( V_58 ) ,
F_12 ( V_59 ) ,
F_12 ( V_60 ) ,
F_12 ( V_61 ) ,
F_12 ( V_62 ) ,
F_12 ( V_63 ) ,
F_12 ( V_64 ) ,
F_12 ( V_65 ) ,
#endif
#undef F_12
} ;
const char * V_22 = L_5 ;
if ( type < F_6 ( V_14 ) && V_14 [ type ] ) {
V_22 = V_14 [ type ] ;
}
return V_22 ;
}
static const char * F_13 ( unsigned V_66 )
{
const char * V_67 ;
const char * V_22 ;
V_67 = V_68 [ V_69 . V_70 ] . V_71 ;
V_22 = L_6 ;
if ( V_66 < V_69 . V_72 ) {
V_22 = V_67 + V_68 [ V_66 ] . V_73 . V_74 ;
}
else if ( V_66 == V_75 ) {
V_22 = L_7 ;
}
else if ( V_66 == V_76 ) {
V_22 = L_8 ;
}
return V_22 ;
}
static const char * V_2 ( const char * V_77 , T_2 * V_78 )
{
const char * V_22 ;
V_22 = L_6 ;
if ( V_78 -> V_79 ) {
V_22 = V_77 + V_78 -> V_79 ;
}
else {
V_22 = F_13 ( V_78 -> V_80 ) ;
}
return V_22 ;
}
static T_2 * F_14 ( const char * V_81 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_69 . V_72 ; V_8 ++ ) {
struct V_82 * V_83 = & V_68 [ V_8 ] ;
long V_84 ;
char * V_71 ;
T_2 * V_85 ;
T_2 * V_78 ;
if ( V_83 -> V_73 . V_86 != V_87 )
continue;
V_84 = V_83 -> V_73 . V_88 / sizeof( T_2 ) ;
V_85 = V_83 -> V_85 ;
V_71 = V_83 -> V_89 -> V_71 ;
for ( V_78 = V_85 ; -- V_84 >= 0 ; V_78 ++ ) {
if ( ! V_78 -> V_79 )
continue;
if ( strcmp ( V_81 , V_71 + V_78 -> V_79 ) == 0 )
return V_78 ;
}
}
return 0 ;
}
static T_3 F_15 ( T_3 V_90 )
{
return F_16 ( V_90 ) ;
}
static T_4 F_17 ( T_4 V_90 )
{
return F_18 ( V_90 ) ;
}
static T_5 F_19 ( T_5 V_90 )
{
return F_20 ( V_90 ) ;
}
static void F_21 ( T_6 * V_91 )
{
if ( fread ( & V_69 , sizeof( V_69 ) , 1 , V_91 ) != 1 ) {
F_3 ( L_9 ,
strerror ( V_92 ) ) ;
}
if ( memcmp ( V_69 . V_93 , V_94 , V_95 ) != 0 ) {
F_3 ( L_10 ) ;
}
if ( V_69 . V_93 [ V_96 ] != V_97 ) {
F_3 ( L_11 , V_34 ) ;
}
if ( V_69 . V_93 [ V_98 ] != V_99 ) {
F_3 ( L_12 ) ;
}
if ( V_69 . V_93 [ V_100 ] != V_101 ) {
F_3 ( L_13 ) ;
}
V_69 . V_102 = F_22 ( V_69 . V_102 ) ;
V_69 . V_103 = F_22 ( V_69 . V_103 ) ;
V_69 . V_104 = F_23 ( V_69 . V_104 ) ;
V_69 . V_105 = F_24 ( V_69 . V_105 ) ;
V_69 . V_106 = F_25 ( V_69 . V_106 ) ;
V_69 . V_107 = F_25 ( V_69 . V_107 ) ;
V_69 . V_108 = F_23 ( V_69 . V_108 ) ;
V_69 . V_109 = F_22 ( V_69 . V_109 ) ;
V_69 . V_110 = F_22 ( V_69 . V_110 ) ;
V_69 . V_111 = F_22 ( V_69 . V_111 ) ;
V_69 . V_112 = F_22 ( V_69 . V_112 ) ;
V_69 . V_72 = F_22 ( V_69 . V_72 ) ;
V_69 . V_70 = F_22 ( V_69 . V_70 ) ;
if ( ( V_69 . V_102 != V_113 ) && ( V_69 . V_102 != V_114 ) ) {
F_3 ( L_14 ) ;
}
if ( V_69 . V_103 != V_115 ) {
F_3 ( L_15 , V_116 ) ;
}
if ( V_69 . V_104 != V_101 ) {
F_3 ( L_13 ) ;
}
if ( V_69 . V_109 != sizeof( V_117 ) ) {
F_3 ( L_16 ) ;
}
if ( V_69 . V_110 != sizeof( V_118 ) ) {
F_3 ( L_17 ) ;
}
if ( V_69 . V_112 != sizeof( V_119 ) ) {
F_3 ( L_18 ) ;
}
if ( V_69 . V_70 >= V_69 . V_72 ) {
F_3 ( L_19 ) ;
}
}
static void F_26 ( T_6 * V_91 )
{
int V_8 ;
V_119 V_73 ;
V_68 = calloc ( V_69 . V_72 , sizeof( struct V_82 ) ) ;
if ( ! V_68 ) {
F_3 ( L_20 ,
V_69 . V_72 ) ;
}
if ( fseek ( V_91 , V_69 . V_107 , V_120 ) < 0 ) {
F_3 ( L_21 ,
V_69 . V_107 , strerror ( V_92 ) ) ;
}
for ( V_8 = 0 ; V_8 < V_69 . V_72 ; V_8 ++ ) {
struct V_82 * V_83 = & V_68 [ V_8 ] ;
if ( fread ( & V_73 , sizeof V_73 , 1 , V_91 ) != 1 )
F_3 ( L_22 ,
V_8 , V_69 . V_72 , strerror ( V_92 ) ) ;
V_83 -> V_73 . V_74 = F_23 ( V_73 . V_74 ) ;
V_83 -> V_73 . V_86 = F_23 ( V_73 . V_86 ) ;
V_83 -> V_73 . V_121 = F_27 ( V_73 . V_121 ) ;
V_83 -> V_73 . V_122 = F_24 ( V_73 . V_122 ) ;
V_83 -> V_73 . V_123 = F_25 ( V_73 . V_123 ) ;
V_83 -> V_73 . V_88 = F_27 ( V_73 . V_88 ) ;
V_83 -> V_73 . V_124 = F_23 ( V_73 . V_124 ) ;
V_83 -> V_73 . V_125 = F_23 ( V_73 . V_125 ) ;
V_83 -> V_73 . V_126 = F_27 ( V_73 . V_126 ) ;
V_83 -> V_73 . V_127 = F_27 ( V_73 . V_127 ) ;
if ( V_83 -> V_73 . V_124 < V_69 . V_72 )
V_83 -> V_89 = & V_68 [ V_83 -> V_73 . V_124 ] ;
}
}
static void F_28 ( T_6 * V_91 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_69 . V_72 ; V_8 ++ ) {
struct V_82 * V_83 = & V_68 [ V_8 ] ;
if ( V_83 -> V_73 . V_86 != V_128 ) {
continue;
}
V_83 -> V_71 = malloc ( V_83 -> V_73 . V_88 ) ;
if ( ! V_83 -> V_71 ) {
F_3 ( L_23 ,
V_83 -> V_73 . V_88 ) ;
}
if ( fseek ( V_91 , V_83 -> V_73 . V_123 , V_120 ) < 0 ) {
F_3 ( L_21 ,
V_83 -> V_73 . V_123 , strerror ( V_92 ) ) ;
}
if ( fread ( V_83 -> V_71 , 1 , V_83 -> V_73 . V_88 , V_91 )
!= V_83 -> V_73 . V_88 ) {
F_3 ( L_24 ,
strerror ( V_92 ) ) ;
}
}
}
static void F_29 ( T_6 * V_91 )
{
int V_8 , V_129 ;
for ( V_8 = 0 ; V_8 < V_69 . V_72 ; V_8 ++ ) {
struct V_82 * V_83 = & V_68 [ V_8 ] ;
if ( V_83 -> V_73 . V_86 != V_87 ) {
continue;
}
V_83 -> V_85 = malloc ( V_83 -> V_73 . V_88 ) ;
if ( ! V_83 -> V_85 ) {
F_3 ( L_25 ,
V_83 -> V_73 . V_88 ) ;
}
if ( fseek ( V_91 , V_83 -> V_73 . V_123 , V_120 ) < 0 ) {
F_3 ( L_21 ,
V_83 -> V_73 . V_123 , strerror ( V_92 ) ) ;
}
if ( fread ( V_83 -> V_85 , 1 , V_83 -> V_73 . V_88 , V_91 )
!= V_83 -> V_73 . V_88 ) {
F_3 ( L_24 ,
strerror ( V_92 ) ) ;
}
for ( V_129 = 0 ; V_129 < V_83 -> V_73 . V_88 / sizeof( T_2 ) ; V_129 ++ ) {
T_2 * V_78 = & V_83 -> V_85 [ V_129 ] ;
V_78 -> V_79 = F_23 ( V_78 -> V_79 ) ;
V_78 -> V_130 = F_24 ( V_78 -> V_130 ) ;
V_78 -> V_131 = F_27 ( V_78 -> V_131 ) ;
V_78 -> V_80 = F_22 ( V_78 -> V_80 ) ;
}
}
}
static void F_30 ( T_6 * V_91 )
{
int V_8 , V_129 ;
for ( V_8 = 0 ; V_8 < V_69 . V_72 ; V_8 ++ ) {
struct V_82 * V_83 = & V_68 [ V_8 ] ;
if ( V_83 -> V_73 . V_86 != V_132 ) {
continue;
}
V_83 -> V_133 = malloc ( V_83 -> V_73 . V_88 ) ;
if ( ! V_83 -> V_133 ) {
F_3 ( L_26 ,
V_83 -> V_73 . V_88 ) ;
}
if ( fseek ( V_91 , V_83 -> V_73 . V_123 , V_120 ) < 0 ) {
F_3 ( L_21 ,
V_83 -> V_73 . V_123 , strerror ( V_92 ) ) ;
}
if ( fread ( V_83 -> V_133 , 1 , V_83 -> V_73 . V_88 , V_91 )
!= V_83 -> V_73 . V_88 ) {
F_3 ( L_24 ,
strerror ( V_92 ) ) ;
}
for ( V_129 = 0 ; V_129 < V_83 -> V_73 . V_88 / sizeof( V_134 ) ; V_129 ++ ) {
V_134 * V_135 = & V_83 -> V_133 [ V_129 ] ;
V_135 -> V_136 = F_24 ( V_135 -> V_136 ) ;
V_135 -> V_137 = F_27 ( V_135 -> V_137 ) ;
#if ( V_132 == V_138 )
V_135 -> V_139 = F_27 ( V_135 -> V_139 ) ;
#endif
}
}
}
static void F_31 ( void )
{
int V_8 ;
const char * V_140 ;
if ( V_34 == 64 )
V_140 = L_27 V_141 L_28 V_142 L_29 ;
else
V_140 = L_30 V_143 L_31 V_144 L_29 ;
printf ( L_32 ) ;
printf ( L_33 ) ;
for ( V_8 = 0 ; V_8 < V_69 . V_72 ; V_8 ++ ) {
struct V_82 * V_83 = & V_68 [ V_8 ] ;
char * V_77 ;
int V_129 ;
if ( V_83 -> V_73 . V_86 != V_87 ) {
continue;
}
V_77 = V_83 -> V_89 -> V_71 ;
for ( V_129 = 0 ; V_129 < V_83 -> V_73 . V_88 / sizeof( T_2 ) ; V_129 ++ ) {
T_2 * V_78 ;
const char * V_22 ;
V_78 = & V_83 -> V_85 [ V_129 ] ;
V_22 = V_2 ( V_77 , V_78 ) ;
if ( V_78 -> V_80 != V_75 ) {
continue;
}
printf ( V_140 ,
V_129 , V_78 -> V_130 , V_78 -> V_131 ,
F_4 ( F_32 ( V_78 -> V_145 ) ) ,
F_7 ( F_33 ( V_78 -> V_145 ) ) ,
F_9 ( F_34 ( V_78 -> V_146 ) ) ,
V_22 ) ;
}
}
printf ( L_34 ) ;
}
static void F_35 ( void )
{
int V_8 , V_147 = 0 ;
const char * V_140 ;
if ( V_34 == 64 )
V_140 = L_35 V_141 L_36 V_141 L_37 V_141 L_38 ;
else
V_140 = L_39 V_143 L_40 V_143 L_41 V_143 L_38 ;
for ( V_8 = 0 ; V_8 < V_69 . V_72 ; V_8 ++ ) {
struct V_82 * V_83 = & V_68 [ V_8 ] ;
struct V_82 * V_148 , * V_149 ;
char * V_77 ;
T_2 * V_150 ;
int V_129 ;
if ( V_83 -> V_73 . V_86 != V_132 ) {
continue;
}
V_149 = V_83 -> V_89 ;
V_148 = & V_68 [ V_83 -> V_73 . V_125 ] ;
if ( ! ( V_148 -> V_73 . V_121 & V_151 ) ) {
continue;
}
V_150 = V_149 -> V_85 ;
V_77 = V_149 -> V_89 -> V_71 ;
for ( V_129 = 0 ; V_129 < V_83 -> V_73 . V_88 / sizeof( V_134 ) ; V_129 ++ ) {
V_134 * V_135 ;
T_2 * V_78 ;
const char * V_22 ;
V_135 = & V_83 -> V_133 [ V_129 ] ;
V_78 = & V_150 [ F_36 ( V_135 -> V_137 ) ] ;
V_22 = V_2 ( V_77 , V_78 ) ;
if ( V_78 -> V_80 != V_75 ) {
continue;
}
if ( F_1 ( V_152 , V_22 ) || F_1 ( V_153 , V_22 ) )
continue;
if ( ! V_147 ) {
printf ( L_42
L_43 ) ;
printf ( L_44
L_45 ) ;
V_147 = 1 ;
}
printf ( V_140 ,
V_135 -> V_136 ,
V_135 -> V_137 ,
F_11 ( F_37 ( V_135 -> V_137 ) ) ,
V_78 -> V_130 ,
V_22 ) ;
}
}
if ( V_147 )
printf ( L_34 ) ;
}
static void F_38 ( struct V_154 * V_155 , T_4 V_156 )
{
if ( V_155 -> V_157 == V_155 -> V_158 ) {
unsigned long V_159 = V_155 -> V_158 + 50000 ;
void * V_160 = realloc ( V_155 -> V_156 , V_159 * sizeof( V_155 -> V_156 [ 0 ] ) ) ;
if ( ! V_160 )
F_3 ( L_46 ,
V_159 ) ;
V_155 -> V_156 = V_160 ;
V_155 -> V_158 = V_159 ;
}
V_155 -> V_156 [ V_155 -> V_157 ++ ] = V_156 ;
}
static void F_39 ( int (* F_40)( struct V_82 * V_83 , V_134 * V_135 ,
T_2 * V_78 , const char * V_81 ) )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_69 . V_72 ; V_8 ++ ) {
char * V_77 ;
T_2 * V_150 ;
struct V_82 * V_148 , * V_149 ;
int V_129 ;
struct V_82 * V_83 = & V_68 [ V_8 ] ;
if ( V_83 -> V_73 . V_86 != V_132 ) {
continue;
}
V_149 = V_83 -> V_89 ;
V_148 = & V_68 [ V_83 -> V_73 . V_125 ] ;
if ( ! ( V_148 -> V_73 . V_121 & V_151 ) ) {
continue;
}
V_150 = V_149 -> V_85 ;
V_77 = V_149 -> V_89 -> V_71 ;
for ( V_129 = 0 ; V_129 < V_83 -> V_73 . V_88 / sizeof( V_134 ) ; V_129 ++ ) {
V_134 * V_135 = & V_83 -> V_133 [ V_129 ] ;
T_2 * V_78 = & V_150 [ F_36 ( V_135 -> V_137 ) ] ;
const char * V_81 = V_2 ( V_77 , V_78 ) ;
F_40 ( V_83 , V_135 , V_78 , V_81 ) ;
}
}
}
static void F_41 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_69 . V_72 ; V_8 ++ ) {
F_42 ( V_161 ) * V_78 ;
if ( strcmp ( F_13 ( V_8 ) , L_47 ) )
continue;
if ( V_68 [ V_8 ] . V_73 . V_122 != 0 )
return;
V_78 = F_14 ( L_48 ) ;
if ( ! V_78 )
F_3 ( L_49 ) ;
V_162 = V_8 ;
V_163 = V_78 -> V_130 ;
return;
}
}
static int F_43 ( struct V_82 * V_83 , V_134 * V_135 , T_2 * V_78 ,
const char * V_81 )
{
unsigned V_164 = F_44 ( V_135 -> V_137 ) ;
int V_165 = ( V_78 -> V_80 == V_75 ) && ! F_1 ( V_153 , V_81 ) ;
switch ( V_164 ) {
case V_51 :
case V_53 :
case V_65 :
case V_63 :
break;
case V_52 :
if ( V_165 ) {
if ( F_1 ( V_152 , V_81 ) )
break;
F_3 ( L_50 ,
F_11 ( V_164 ) , V_81 ) ;
break;
}
F_38 ( & V_166 , V_135 -> V_136 ) ;
break;
default:
F_3 ( L_51 ,
F_11 ( V_164 ) , V_164 ) ;
break;
}
return 0 ;
}
static int F_45 ( struct V_82 * V_83 , V_134 * V_135 , T_2 * V_78 ,
const char * V_81 )
{
unsigned V_164 = F_44 ( V_135 -> V_137 ) ;
int V_165 = ( V_78 -> V_80 == V_75 ) && ! F_1 ( V_153 , V_81 ) ;
switch ( V_164 ) {
case V_51 :
case V_53 :
case V_65 :
case V_63 :
break;
case V_64 :
if ( V_165 ) {
if ( F_1 ( V_152 , V_81 ) )
break;
if ( F_1 ( V_167 , V_81 ) ) {
F_38 ( & V_168 , V_135 -> V_136 ) ;
break;
}
} else {
if ( ! F_1 ( V_169 , V_81 ) )
break;
}
F_3 ( L_52 ,
V_165 ? L_53 : L_54 ,
F_11 ( V_164 ) , V_81 ) ;
break;
case V_52 :
if ( V_165 ) {
if ( F_1 ( V_152 , V_81 ) )
break;
if ( F_1 ( V_153 , V_81 ) ) {
F_38 ( & V_166 , V_135 -> V_136 ) ;
break;
}
} else {
if ( F_1 ( V_169 , V_81 ) )
F_38 ( & V_166 , V_135 -> V_136 ) ;
break;
}
F_3 ( L_52 ,
V_165 ? L_53 : L_54 ,
F_11 ( V_164 ) , V_81 ) ;
break;
default:
F_3 ( L_51 ,
F_11 ( V_164 ) , V_164 ) ;
break;
}
return 0 ;
}
static int F_46 ( const void * V_170 , const void * V_171 )
{
const T_4 * V_172 , * V_173 ;
V_172 = V_170 ; V_173 = V_171 ;
return ( * V_172 == * V_173 ) ? 0 : ( * V_172 > * V_173 ) ? 1 : - 1 ;
}
static void F_47 ( struct V_154 * V_155 )
{
qsort ( V_155 -> V_156 , V_155 -> V_157 , sizeof( V_155 -> V_156 [ 0 ] ) , F_46 ) ;
}
static int F_48 ( T_4 V_174 , T_6 * V_175 )
{
unsigned char V_176 [ 4 ] ;
F_49 ( V_174 , V_176 ) ;
return fwrite ( V_176 , 1 , 4 , V_175 ) == 4 ? 0 : - 1 ;
}
static int F_50 ( T_4 V_174 , T_6 * V_175 )
{
return fprintf ( V_175 , L_55 V_143 L_34 , V_174 ) > 0 ? 0 : - 1 ;
}
static void F_51 ( int V_177 , int V_5 )
{
int V_8 ;
int (* F_52)( T_4 , T_6 * ) = F_48 ;
int (* F_53)( struct V_82 * V_83 , V_134 * V_135 , T_2 * V_78 ,
const char * V_81 );
#if V_34 == 64
if ( ! V_5 )
F_53 = V_178 ;
else
F_3 ( L_56 ) ;
#else
if ( ! V_5 )
F_53 = F_43 ;
else
F_53 = F_45 ;
#endif
F_39 ( F_53 ) ;
if ( V_168 . V_157 && ! V_5 )
F_3 ( L_57 ) ;
F_47 ( & V_168 ) ;
F_47 ( & V_166 ) ;
#if V_34 == 64
F_47 ( & V_179 ) ;
F_47 ( & V_180 ) ;
#endif
if ( V_177 ) {
printf ( L_58 ) ;
printf ( L_59 ) ;
F_52 = F_50 ;
}
if ( V_5 ) {
F_52 ( V_168 . V_157 , stdout ) ;
for ( V_8 = 0 ; V_8 < V_168 . V_157 ; V_8 ++ )
F_52 ( V_168 . V_156 [ V_8 ] , stdout ) ;
F_52 ( V_166 . V_157 , stdout ) ;
for ( V_8 = 0 ; V_8 < V_166 . V_157 ; V_8 ++ )
F_52 ( V_166 . V_156 [ V_8 ] , stdout ) ;
} else {
#if V_34 == 64
F_52 ( 0 , stdout ) ;
for ( V_8 = 0 ; V_8 < V_180 . V_157 ; V_8 ++ )
F_52 ( V_180 . V_156 [ V_8 ] , stdout ) ;
F_52 ( 0 , stdout ) ;
for ( V_8 = 0 ; V_8 < V_179 . V_157 ; V_8 ++ )
F_52 ( V_179 . V_156 [ V_8 ] , stdout ) ;
#endif
F_52 ( 0 , stdout ) ;
for ( V_8 = 0 ; V_8 < V_166 . V_157 ; V_8 ++ )
F_52 ( V_166 . V_156 [ V_8 ] , stdout ) ;
}
}
static void F_54 ( void )
{
printf ( L_60 ) ;
F_39 ( V_181 ) ;
}
void F_40 ( T_6 * V_91 , int V_5 , int V_177 ,
int V_182 , int V_183 ,
int V_184 )
{
F_2 ( V_5 ) ;
F_21 ( V_91 ) ;
F_26 ( V_91 ) ;
F_28 ( V_91 ) ;
F_29 ( V_91 ) ;
F_30 ( V_91 ) ;
if ( V_34 == 64 )
F_41 () ;
if ( V_182 ) {
F_31 () ;
return;
}
if ( V_183 ) {
F_35 () ;
return;
}
if ( V_184 ) {
F_54 () ;
return;
}
F_51 ( V_177 , V_5 ) ;
}
