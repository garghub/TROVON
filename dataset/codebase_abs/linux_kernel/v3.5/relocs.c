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
static void F_3 ( char * V_14 , ... )
{
T_1 V_15 ;
va_start ( V_15 , V_14 ) ;
vfprintf ( V_16 , V_14 , V_15 ) ;
va_end ( V_15 ) ;
exit ( 1 ) ;
}
static const char * F_4 ( unsigned type )
{
static const char * V_17 [] = {
#define F_5 ( T_2 ) [X] = #X
F_5 ( V_18 ) ,
F_5 ( V_19 ) ,
F_5 ( V_20 ) ,
F_5 ( V_21 ) ,
F_5 ( V_22 ) ,
F_5 ( V_23 ) ,
F_5 ( V_24 ) ,
#undef F_5
} ;
const char * V_25 = L_2 ;
if ( type < F_6 ( V_17 ) ) {
V_25 = V_17 [ type ] ;
}
return V_25 ;
}
static const char * F_7 ( unsigned V_26 )
{
static const char * V_27 [] = {
#define F_8 ( T_2 ) [X] = #X
F_8 ( V_28 ) ,
F_8 ( V_29 ) ,
F_8 ( V_30 ) ,
#undef F_8
} ;
const char * V_25 = L_3 ;
if ( V_26 < F_6 ( V_27 ) ) {
V_25 = V_27 [ V_26 ] ;
}
return V_25 ;
}
static const char * F_9 ( unsigned V_31 )
{
static const char * V_32 [] = {
#define F_10 ( T_2 ) [X] = #X
F_10 ( V_33 ) ,
F_10 ( V_34 ) ,
F_10 ( V_35 ) ,
F_10 ( V_36 ) ,
#undef F_10
} ;
const char * V_25 = L_4 ;
if ( V_31 < F_6 ( V_32 ) ) {
V_25 = V_32 [ V_31 ] ;
}
return V_25 ;
}
static const char * F_11 ( unsigned type )
{
static const char * V_17 [] = {
#define F_12 ( T_2 ) [X] = #X
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
F_12 ( V_51 ) ,
#undef F_12
} ;
const char * V_25 = L_5 ;
if ( type < F_6 ( V_17 ) && V_17 [ type ] ) {
V_25 = V_17 [ type ] ;
}
return V_25 ;
}
static const char * F_13 ( unsigned V_52 )
{
const char * V_53 ;
const char * V_25 ;
V_53 = V_54 [ V_55 . V_56 ] . V_57 ;
V_25 = L_6 ;
if ( V_52 < V_55 . V_58 ) {
V_25 = V_53 + V_54 [ V_52 ] . V_59 . V_60 ;
}
else if ( V_52 == V_61 ) {
V_25 = L_7 ;
}
else if ( V_52 == V_62 ) {
V_25 = L_8 ;
}
return V_25 ;
}
static const char * V_2 ( const char * V_63 , T_3 * V_64 )
{
const char * V_25 ;
V_25 = L_6 ;
if ( V_64 -> V_65 ) {
V_25 = V_63 + V_64 -> V_65 ;
}
else {
V_25 = F_13 ( V_64 -> V_66 ) ;
}
return V_25 ;
}
static T_4 F_14 ( T_4 V_67 )
{
return F_15 ( V_67 ) ;
}
static T_5 F_16 ( T_5 V_67 )
{
return F_17 ( V_67 ) ;
}
static void F_18 ( T_6 * V_68 )
{
if ( fread ( & V_55 , sizeof( V_55 ) , 1 , V_68 ) != 1 ) {
F_3 ( L_9 ,
strerror ( V_69 ) ) ;
}
if ( memcmp ( V_55 . V_70 , V_71 , V_72 ) != 0 ) {
F_3 ( L_10 ) ;
}
if ( V_55 . V_70 [ V_73 ] != V_74 ) {
F_3 ( L_11 ) ;
}
if ( V_55 . V_70 [ V_75 ] != V_76 ) {
F_3 ( L_12 ) ;
}
if ( V_55 . V_70 [ V_77 ] != V_78 ) {
F_3 ( L_13 ) ;
}
V_55 . V_79 = F_14 ( V_55 . V_79 ) ;
V_55 . V_80 = F_14 ( V_55 . V_80 ) ;
V_55 . V_81 = F_16 ( V_55 . V_81 ) ;
V_55 . V_82 = F_16 ( V_55 . V_82 ) ;
V_55 . V_83 = F_16 ( V_55 . V_83 ) ;
V_55 . V_84 = F_16 ( V_55 . V_84 ) ;
V_55 . V_85 = F_16 ( V_55 . V_85 ) ;
V_55 . V_86 = F_14 ( V_55 . V_86 ) ;
V_55 . V_87 = F_14 ( V_55 . V_87 ) ;
V_55 . V_88 = F_14 ( V_55 . V_88 ) ;
V_55 . V_89 = F_14 ( V_55 . V_89 ) ;
V_55 . V_58 = F_14 ( V_55 . V_58 ) ;
V_55 . V_56 = F_14 ( V_55 . V_56 ) ;
if ( ( V_55 . V_79 != V_90 ) && ( V_55 . V_79 != V_91 ) ) {
F_3 ( L_14 ) ;
}
if ( V_55 . V_80 != V_92 ) {
F_3 ( L_15 ) ;
}
if ( V_55 . V_81 != V_78 ) {
F_3 ( L_13 ) ;
}
if ( V_55 . V_86 != sizeof( V_93 ) ) {
F_3 ( L_16 ) ;
}
if ( V_55 . V_87 != sizeof( V_94 ) ) {
F_3 ( L_17 ) ;
}
if ( V_55 . V_89 != sizeof( V_95 ) ) {
F_3 ( L_18 ) ;
}
if ( V_55 . V_56 >= V_55 . V_58 ) {
F_3 ( L_19 ) ;
}
}
static void F_19 ( T_6 * V_68 )
{
int V_8 ;
V_95 V_59 ;
V_54 = calloc ( V_55 . V_58 , sizeof( struct V_96 ) ) ;
if ( ! V_54 ) {
F_3 ( L_20 ,
V_55 . V_58 ) ;
}
if ( fseek ( V_68 , V_55 . V_84 , V_97 ) < 0 ) {
F_3 ( L_21 ,
V_55 . V_84 , strerror ( V_69 ) ) ;
}
for ( V_8 = 0 ; V_8 < V_55 . V_58 ; V_8 ++ ) {
struct V_96 * V_98 = & V_54 [ V_8 ] ;
if ( fread ( & V_59 , sizeof V_59 , 1 , V_68 ) != 1 )
F_3 ( L_22 ,
V_8 , V_55 . V_58 , strerror ( V_69 ) ) ;
V_98 -> V_59 . V_60 = F_16 ( V_59 . V_60 ) ;
V_98 -> V_59 . V_99 = F_16 ( V_59 . V_99 ) ;
V_98 -> V_59 . V_100 = F_16 ( V_59 . V_100 ) ;
V_98 -> V_59 . V_101 = F_16 ( V_59 . V_101 ) ;
V_98 -> V_59 . V_102 = F_16 ( V_59 . V_102 ) ;
V_98 -> V_59 . V_103 = F_16 ( V_59 . V_103 ) ;
V_98 -> V_59 . V_104 = F_16 ( V_59 . V_104 ) ;
V_98 -> V_59 . V_105 = F_16 ( V_59 . V_105 ) ;
V_98 -> V_59 . V_106 = F_16 ( V_59 . V_106 ) ;
V_98 -> V_59 . V_107 = F_16 ( V_59 . V_107 ) ;
if ( V_98 -> V_59 . V_104 < V_55 . V_58 )
V_98 -> V_108 = & V_54 [ V_98 -> V_59 . V_104 ] ;
}
}
static void F_20 ( T_6 * V_68 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_55 . V_58 ; V_8 ++ ) {
struct V_96 * V_98 = & V_54 [ V_8 ] ;
if ( V_98 -> V_59 . V_99 != V_109 ) {
continue;
}
V_98 -> V_57 = malloc ( V_98 -> V_59 . V_103 ) ;
if ( ! V_98 -> V_57 ) {
F_3 ( L_23 ,
V_98 -> V_59 . V_103 ) ;
}
if ( fseek ( V_68 , V_98 -> V_59 . V_102 , V_97 ) < 0 ) {
F_3 ( L_21 ,
V_98 -> V_59 . V_102 , strerror ( V_69 ) ) ;
}
if ( fread ( V_98 -> V_57 , 1 , V_98 -> V_59 . V_103 , V_68 )
!= V_98 -> V_59 . V_103 ) {
F_3 ( L_24 ,
strerror ( V_69 ) ) ;
}
}
}
static void F_21 ( T_6 * V_68 )
{
int V_8 , V_110 ;
for ( V_8 = 0 ; V_8 < V_55 . V_58 ; V_8 ++ ) {
struct V_96 * V_98 = & V_54 [ V_8 ] ;
if ( V_98 -> V_59 . V_99 != V_111 ) {
continue;
}
V_98 -> V_112 = malloc ( V_98 -> V_59 . V_103 ) ;
if ( ! V_98 -> V_112 ) {
F_3 ( L_25 ,
V_98 -> V_59 . V_103 ) ;
}
if ( fseek ( V_68 , V_98 -> V_59 . V_102 , V_97 ) < 0 ) {
F_3 ( L_21 ,
V_98 -> V_59 . V_102 , strerror ( V_69 ) ) ;
}
if ( fread ( V_98 -> V_112 , 1 , V_98 -> V_59 . V_103 , V_68 )
!= V_98 -> V_59 . V_103 ) {
F_3 ( L_24 ,
strerror ( V_69 ) ) ;
}
for ( V_110 = 0 ; V_110 < V_98 -> V_59 . V_103 / sizeof( T_3 ) ; V_110 ++ ) {
T_3 * V_64 = & V_98 -> V_112 [ V_110 ] ;
V_64 -> V_65 = F_16 ( V_64 -> V_65 ) ;
V_64 -> V_113 = F_16 ( V_64 -> V_113 ) ;
V_64 -> V_114 = F_16 ( V_64 -> V_114 ) ;
V_64 -> V_66 = F_14 ( V_64 -> V_66 ) ;
}
}
}
static void F_22 ( T_6 * V_68 )
{
int V_8 , V_110 ;
for ( V_8 = 0 ; V_8 < V_55 . V_58 ; V_8 ++ ) {
struct V_96 * V_98 = & V_54 [ V_8 ] ;
if ( V_98 -> V_59 . V_99 != V_115 ) {
continue;
}
V_98 -> V_116 = malloc ( V_98 -> V_59 . V_103 ) ;
if ( ! V_98 -> V_116 ) {
F_3 ( L_26 ,
V_98 -> V_59 . V_103 ) ;
}
if ( fseek ( V_68 , V_98 -> V_59 . V_102 , V_97 ) < 0 ) {
F_3 ( L_21 ,
V_98 -> V_59 . V_102 , strerror ( V_69 ) ) ;
}
if ( fread ( V_98 -> V_116 , 1 , V_98 -> V_59 . V_103 , V_68 )
!= V_98 -> V_59 . V_103 ) {
F_3 ( L_24 ,
strerror ( V_69 ) ) ;
}
for ( V_110 = 0 ; V_110 < V_98 -> V_59 . V_103 / sizeof( V_117 ) ; V_110 ++ ) {
V_117 * V_118 = & V_98 -> V_116 [ V_110 ] ;
V_118 -> V_119 = F_16 ( V_118 -> V_119 ) ;
V_118 -> V_120 = F_16 ( V_118 -> V_120 ) ;
}
}
}
static void F_23 ( void )
{
int V_8 ;
printf ( L_27 ) ;
printf ( L_28 ) ;
for ( V_8 = 0 ; V_8 < V_55 . V_58 ; V_8 ++ ) {
struct V_96 * V_98 = & V_54 [ V_8 ] ;
char * V_63 ;
int V_110 ;
if ( V_98 -> V_59 . V_99 != V_111 ) {
continue;
}
V_63 = V_98 -> V_108 -> V_57 ;
for ( V_110 = 0 ; V_110 < V_98 -> V_59 . V_103 / sizeof( T_3 ) ; V_110 ++ ) {
T_3 * V_64 ;
const char * V_25 ;
V_64 = & V_98 -> V_112 [ V_110 ] ;
V_25 = V_2 ( V_63 , V_64 ) ;
if ( V_64 -> V_66 != V_61 ) {
continue;
}
printf ( L_29 ,
V_110 , V_64 -> V_113 , V_64 -> V_114 ,
F_4 ( F_24 ( V_64 -> V_121 ) ) ,
F_7 ( F_25 ( V_64 -> V_121 ) ) ,
F_9 ( F_26 ( V_64 -> V_122 ) ) ,
V_25 ) ;
}
}
printf ( L_30 ) ;
}
static void F_27 ( void )
{
int V_8 , V_123 = 0 ;
for ( V_8 = 0 ; V_8 < V_55 . V_58 ; V_8 ++ ) {
struct V_96 * V_98 = & V_54 [ V_8 ] ;
struct V_96 * V_124 , * V_125 ;
char * V_63 ;
T_3 * V_126 ;
int V_110 ;
if ( V_98 -> V_59 . V_99 != V_115 ) {
continue;
}
V_125 = V_98 -> V_108 ;
V_124 = & V_54 [ V_98 -> V_59 . V_105 ] ;
if ( ! ( V_124 -> V_59 . V_100 & V_127 ) ) {
continue;
}
V_126 = V_125 -> V_112 ;
V_63 = V_125 -> V_108 -> V_57 ;
for ( V_110 = 0 ; V_110 < V_98 -> V_59 . V_103 / sizeof( V_117 ) ; V_110 ++ ) {
V_117 * V_118 ;
T_3 * V_64 ;
const char * V_25 ;
V_118 = & V_98 -> V_116 [ V_110 ] ;
V_64 = & V_126 [ F_28 ( V_118 -> V_120 ) ] ;
V_25 = V_2 ( V_63 , V_64 ) ;
if ( V_64 -> V_66 != V_61 ) {
continue;
}
if ( F_1 ( V_128 , V_25 ) || F_1 ( V_129 , V_25 ) )
continue;
if ( ! V_123 ) {
printf ( L_31
L_32 ) ;
printf ( L_33
L_34 ) ;
V_123 = 1 ;
}
printf ( L_35 ,
V_118 -> V_119 ,
V_118 -> V_120 ,
F_11 ( F_29 ( V_118 -> V_120 ) ) ,
V_64 -> V_113 ,
V_25 ) ;
}
}
if ( V_123 )
printf ( L_30 ) ;
}
static void F_30 ( void (* F_31)( V_117 * V_118 , T_3 * V_64 ) ,
int V_5 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_55 . V_58 ; V_8 ++ ) {
char * V_63 ;
T_3 * V_126 ;
struct V_96 * V_124 , * V_125 ;
int V_110 ;
struct V_96 * V_98 = & V_54 [ V_8 ] ;
if ( V_98 -> V_59 . V_99 != V_115 ) {
continue;
}
V_125 = V_98 -> V_108 ;
V_124 = & V_54 [ V_98 -> V_59 . V_105 ] ;
if ( ! ( V_124 -> V_59 . V_100 & V_127 ) ) {
continue;
}
V_126 = V_125 -> V_112 ;
V_63 = V_125 -> V_108 -> V_57 ;
for ( V_110 = 0 ; V_110 < V_98 -> V_59 . V_103 / sizeof( V_117 ) ; V_110 ++ ) {
V_117 * V_118 ;
T_3 * V_64 ;
unsigned V_130 ;
const char * V_131 ;
int V_132 ;
V_118 = & V_98 -> V_116 [ V_110 ] ;
V_64 = & V_126 [ F_28 ( V_118 -> V_120 ) ] ;
V_130 = F_29 ( V_118 -> V_120 ) ;
V_132 = V_64 -> V_66 == V_61 ;
switch ( V_130 ) {
case V_37 :
case V_39 :
case V_51 :
case V_49 :
break;
case V_50 :
V_131 = V_2 ( V_63 , V_64 ) ;
if ( ! V_5 )
goto V_133;
if ( V_132 ) {
if ( F_1 ( V_128 , V_131 ) )
break;
else if ( ! F_1 ( V_134 , V_131 ) )
goto V_133;
} else {
if ( F_1 ( V_135 , V_131 ) )
goto V_133;
else
break;
}
F_31 ( V_118 , V_64 ) ;
break;
case V_38 :
V_131 = V_2 ( V_63 , V_64 ) ;
if ( V_132 ) {
if ( F_1 ( V_128 , V_131 ) )
break;
else if ( ! F_1 ( V_129 , V_131 ) )
goto V_133;
} else {
if ( V_5 &&
! F_1 ( V_135 , V_131 ) )
break;
}
F_31 ( V_118 , V_64 ) ;
break;
default:
F_3 ( L_36 ,
F_11 ( V_130 ) , V_130 ) ;
break;
V_133:
V_131 = V_2 ( V_63 , V_64 ) ;
F_3 ( L_37 ,
V_132 ? L_38 : L_39 ,
F_11 ( V_130 ) , V_131 ) ;
}
}
}
}
static void F_32 ( V_117 * V_118 , T_3 * V_64 )
{
if ( F_29 ( V_118 -> V_120 ) == V_50 )
V_136 ++ ;
else
V_137 ++ ;
}
static void F_33 ( V_117 * V_118 , T_3 * V_64 )
{
if ( F_29 ( V_118 -> V_120 ) == V_50 )
V_138 [ V_139 ++ ] = V_118 -> V_119 ;
else
V_140 [ V_141 ++ ] = V_118 -> V_119 ;
}
static int F_34 ( const void * V_142 , const void * V_143 )
{
const unsigned long * V_144 , * V_145 ;
V_144 = V_142 ; V_145 = V_143 ;
return ( * V_144 == * V_145 ) ? 0 : ( * V_144 > * V_145 ) ? 1 : - 1 ;
}
static int F_35 ( unsigned int V_146 , T_6 * V_147 )
{
unsigned char V_148 [ 4 ] ;
F_36 ( V_146 , V_148 ) ;
return fwrite ( V_148 , 1 , 4 , V_147 ) == 4 ? 0 : - 1 ;
}
static void F_37 ( int V_149 , int V_5 )
{
int V_8 ;
V_137 = 0 ;
F_30 ( F_32 , V_5 ) ;
V_140 = malloc ( V_137 * sizeof( V_140 [ 0 ] ) ) ;
if ( ! V_140 ) {
F_3 ( L_40 ,
V_137 ) ;
}
V_138 = malloc ( V_136 * sizeof( V_140 [ 0 ] ) ) ;
if ( ! V_138 ) {
F_3 ( L_41 ,
V_136 ) ;
}
V_141 = 0 ;
F_30 ( F_33 , V_5 ) ;
if ( V_136 && ! V_5 )
F_3 ( L_42 ) ;
qsort ( V_140 , V_137 , sizeof( V_140 [ 0 ] ) , F_34 ) ;
qsort ( V_138 , V_136 , sizeof( V_138 [ 0 ] ) , F_34 ) ;
if ( V_149 ) {
printf ( L_43 ) ;
printf ( L_44 ) ;
if ( V_5 ) {
printf ( L_45 , V_136 ) ;
for ( V_8 = 0 ; V_8 < V_136 ; V_8 ++ )
printf ( L_46 , V_138 [ V_8 ] ) ;
printf ( L_45 , V_137 ) ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
printf ( L_46 , V_140 [ V_8 ] ) ;
}
} else {
printf ( L_46 , ( unsigned long ) 0 ) ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
printf ( L_46 , V_140 [ V_8 ] ) ;
}
}
printf ( L_30 ) ;
}
else {
if ( V_5 ) {
F_35 ( V_136 , stdout ) ;
for ( V_8 = 0 ; V_8 < V_136 ; V_8 ++ )
F_35 ( V_138 [ V_8 ] , stdout ) ;
F_35 ( V_137 , stdout ) ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ )
F_35 ( V_140 [ V_8 ] , stdout ) ;
} else {
F_35 ( 0 , stdout ) ;
for ( V_8 = 0 ; V_8 < V_137 ; V_8 ++ ) {
F_35 ( V_140 [ V_8 ] , stdout ) ;
}
}
}
}
static void F_38 ( void )
{
F_3 ( L_47 ) ;
}
int main ( int V_150 , char * * V_151 )
{
int V_152 , V_153 ;
int V_149 , V_5 ;
const char * V_154 ;
T_6 * V_68 ;
int V_8 ;
V_152 = 0 ;
V_153 = 0 ;
V_149 = 0 ;
V_5 = 0 ;
V_154 = NULL ;
for ( V_8 = 1 ; V_8 < V_150 ; V_8 ++ ) {
char * V_155 = V_151 [ V_8 ] ;
if ( * V_155 == '-' ) {
if ( strcmp ( V_155 , L_48 ) == 0 ) {
V_152 = 1 ;
continue;
}
if ( strcmp ( V_155 , L_49 ) == 0 ) {
V_153 = 1 ;
continue;
}
if ( strcmp ( V_155 , L_50 ) == 0 ) {
V_149 = 1 ;
continue;
}
if ( strcmp ( V_155 , L_51 ) == 0 ) {
V_5 = 1 ;
continue;
}
}
else if ( ! V_154 ) {
V_154 = V_155 ;
continue;
}
F_38 () ;
}
if ( ! V_154 ) {
F_38 () ;
}
F_2 ( V_5 ) ;
V_68 = fopen ( V_154 , L_52 ) ;
if ( ! V_68 ) {
F_3 ( L_53 ,
V_154 , strerror ( V_69 ) ) ;
}
F_18 ( V_68 ) ;
F_19 ( V_68 ) ;
F_20 ( V_68 ) ;
F_21 ( V_68 ) ;
F_22 ( V_68 ) ;
if ( V_152 ) {
F_23 () ;
return 0 ;
}
if ( V_153 ) {
F_27 () ;
return 0 ;
}
F_37 ( V_149 , V_5 ) ;
return 0 ;
}
