static int F_1 ( const char * V_1 )
{
return ! regexec ( & V_2 , V_1 , 0 , NULL , 0 ) ;
}
static int F_2 ( const char * V_1 )
{
return ! regexec ( & V_3 , V_1 , 0 , NULL , 0 ) ;
}
static void F_3 ( void )
{
char V_4 [ 128 ] ;
int V_5 ;
V_5 = regcomp ( & V_2 , V_6 ,
V_7 | V_8 ) ;
if ( V_5 ) {
regerror ( V_5 , & V_2 , V_4 , sizeof V_4 ) ;
F_4 ( L_1 , V_4 ) ;
}
V_5 = regcomp ( & V_3 , V_9 ,
V_7 | V_8 ) ;
if ( V_5 ) {
regerror ( V_5 , & V_3 , V_4 , sizeof V_4 ) ;
F_4 ( L_1 , V_4 ) ;
}
}
static void F_4 ( char * V_10 , ... )
{
T_1 V_11 ;
va_start ( V_11 , V_10 ) ;
vfprintf ( V_12 , V_10 , V_11 ) ;
va_end ( V_11 ) ;
exit ( 1 ) ;
}
static const char * F_5 ( unsigned type )
{
static const char * V_13 [] = {
#define F_6 ( T_2 ) [X] = #X
F_6 ( V_14 ) ,
F_6 ( V_15 ) ,
F_6 ( V_16 ) ,
F_6 ( V_17 ) ,
F_6 ( V_18 ) ,
F_6 ( V_19 ) ,
F_6 ( V_20 ) ,
#undef F_6
} ;
const char * V_21 = L_2 ;
if ( type < F_7 ( V_13 ) ) {
V_21 = V_13 [ type ] ;
}
return V_21 ;
}
static const char * F_8 ( unsigned V_22 )
{
static const char * V_23 [] = {
#define F_9 ( T_2 ) [X] = #X
F_9 ( V_24 ) ,
F_9 ( V_25 ) ,
F_9 ( V_26 ) ,
#undef F_9
} ;
const char * V_21 = L_3 ;
if ( V_22 < F_7 ( V_23 ) ) {
V_21 = V_23 [ V_22 ] ;
}
return V_21 ;
}
static const char * F_10 ( unsigned V_27 )
{
static const char * V_28 [] = {
#define F_11 ( T_2 ) [X] = #X
F_11 ( V_29 ) ,
F_11 ( V_30 ) ,
F_11 ( V_31 ) ,
F_11 ( V_32 ) ,
#undef F_11
} ;
const char * V_21 = L_4 ;
if ( V_27 < F_7 ( V_28 ) ) {
V_21 = V_28 [ V_27 ] ;
}
return V_21 ;
}
static const char * F_12 ( unsigned type )
{
static const char * V_13 [] = {
#define F_13 ( T_2 ) [X] = #X
F_13 ( V_33 ) ,
F_13 ( V_34 ) ,
F_13 ( V_35 ) ,
F_13 ( V_36 ) ,
F_13 ( V_37 ) ,
F_13 ( V_38 ) ,
F_13 ( V_39 ) ,
F_13 ( V_40 ) ,
F_13 ( V_41 ) ,
F_13 ( V_42 ) ,
F_13 ( V_43 ) ,
#undef F_13
} ;
const char * V_21 = L_5 ;
if ( type < F_7 ( V_13 ) && V_13 [ type ] ) {
V_21 = V_13 [ type ] ;
}
return V_21 ;
}
static const char * F_14 ( unsigned V_44 )
{
const char * V_45 ;
const char * V_21 ;
V_45 = V_46 [ V_47 . V_48 ] . V_49 ;
V_21 = L_6 ;
if ( V_44 < V_47 . V_50 ) {
V_21 = V_45 + V_46 [ V_44 ] . V_51 . V_52 ;
}
else if ( V_44 == V_53 ) {
V_21 = L_7 ;
}
else if ( V_44 == V_54 ) {
V_21 = L_8 ;
}
return V_21 ;
}
static const char * V_1 ( const char * V_55 , T_3 * V_56 )
{
const char * V_21 ;
V_21 = L_6 ;
if ( V_56 -> V_57 ) {
V_21 = V_55 + V_56 -> V_57 ;
}
else {
V_21 = F_14 ( V_46 [ V_56 -> V_58 ] . V_51 . V_52 ) ;
}
return V_21 ;
}
static T_4 F_15 ( T_4 V_59 )
{
return F_16 ( V_59 ) ;
}
static T_5 F_17 ( T_5 V_59 )
{
return F_18 ( V_59 ) ;
}
static void F_19 ( T_6 * V_60 )
{
if ( fread ( & V_47 , sizeof( V_47 ) , 1 , V_60 ) != 1 ) {
F_4 ( L_9 ,
strerror ( V_61 ) ) ;
}
if ( memcmp ( V_47 . V_62 , V_63 , V_64 ) != 0 ) {
F_4 ( L_10 ) ;
}
if ( V_47 . V_62 [ V_65 ] != V_66 ) {
F_4 ( L_11 ) ;
}
if ( V_47 . V_62 [ V_67 ] != V_68 ) {
F_4 ( L_12 ) ;
}
if ( V_47 . V_62 [ V_69 ] != V_70 ) {
F_4 ( L_13 ) ;
}
V_47 . V_71 = F_15 ( V_47 . V_71 ) ;
V_47 . V_72 = F_15 ( V_47 . V_72 ) ;
V_47 . V_73 = F_17 ( V_47 . V_73 ) ;
V_47 . V_74 = F_17 ( V_47 . V_74 ) ;
V_47 . V_75 = F_17 ( V_47 . V_75 ) ;
V_47 . V_76 = F_17 ( V_47 . V_76 ) ;
V_47 . V_77 = F_17 ( V_47 . V_77 ) ;
V_47 . V_78 = F_15 ( V_47 . V_78 ) ;
V_47 . V_79 = F_15 ( V_47 . V_79 ) ;
V_47 . V_80 = F_15 ( V_47 . V_80 ) ;
V_47 . V_81 = F_15 ( V_47 . V_81 ) ;
V_47 . V_50 = F_15 ( V_47 . V_50 ) ;
V_47 . V_48 = F_15 ( V_47 . V_48 ) ;
if ( ( V_47 . V_71 != V_82 ) && ( V_47 . V_71 != V_83 ) ) {
F_4 ( L_14 ) ;
}
if ( V_47 . V_72 != V_84 ) {
F_4 ( L_15 ) ;
}
if ( V_47 . V_73 != V_70 ) {
F_4 ( L_13 ) ;
}
if ( V_47 . V_78 != sizeof( V_85 ) ) {
F_4 ( L_16 ) ;
}
if ( V_47 . V_79 != sizeof( V_86 ) ) {
F_4 ( L_17 ) ;
}
if ( V_47 . V_81 != sizeof( V_87 ) ) {
F_4 ( L_18 ) ;
}
if ( V_47 . V_48 >= V_47 . V_50 ) {
F_4 ( L_19 ) ;
}
}
static void F_20 ( T_6 * V_60 )
{
int V_88 ;
V_87 V_51 ;
V_46 = calloc ( V_47 . V_50 , sizeof( struct V_89 ) ) ;
if ( ! V_46 ) {
F_4 ( L_20 ,
V_47 . V_50 ) ;
}
if ( fseek ( V_60 , V_47 . V_76 , V_90 ) < 0 ) {
F_4 ( L_21 ,
V_47 . V_76 , strerror ( V_61 ) ) ;
}
for ( V_88 = 0 ; V_88 < V_47 . V_50 ; V_88 ++ ) {
struct V_89 * V_91 = & V_46 [ V_88 ] ;
if ( fread ( & V_51 , sizeof V_51 , 1 , V_60 ) != 1 )
F_4 ( L_22 ,
V_88 , V_47 . V_50 , strerror ( V_61 ) ) ;
V_91 -> V_51 . V_52 = F_17 ( V_51 . V_52 ) ;
V_91 -> V_51 . V_92 = F_17 ( V_51 . V_92 ) ;
V_91 -> V_51 . V_93 = F_17 ( V_51 . V_93 ) ;
V_91 -> V_51 . V_94 = F_17 ( V_51 . V_94 ) ;
V_91 -> V_51 . V_95 = F_17 ( V_51 . V_95 ) ;
V_91 -> V_51 . V_96 = F_17 ( V_51 . V_96 ) ;
V_91 -> V_51 . V_97 = F_17 ( V_51 . V_97 ) ;
V_91 -> V_51 . V_98 = F_17 ( V_51 . V_98 ) ;
V_91 -> V_51 . V_99 = F_17 ( V_51 . V_99 ) ;
V_91 -> V_51 . V_100 = F_17 ( V_51 . V_100 ) ;
if ( V_91 -> V_51 . V_97 < V_47 . V_50 )
V_91 -> V_101 = & V_46 [ V_91 -> V_51 . V_97 ] ;
}
}
static void F_21 ( T_6 * V_60 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_47 . V_50 ; V_88 ++ ) {
struct V_89 * V_91 = & V_46 [ V_88 ] ;
if ( V_91 -> V_51 . V_92 != V_102 ) {
continue;
}
V_91 -> V_49 = malloc ( V_91 -> V_51 . V_96 ) ;
if ( ! V_91 -> V_49 ) {
F_4 ( L_23 ,
V_91 -> V_51 . V_96 ) ;
}
if ( fseek ( V_60 , V_91 -> V_51 . V_95 , V_90 ) < 0 ) {
F_4 ( L_21 ,
V_91 -> V_51 . V_95 , strerror ( V_61 ) ) ;
}
if ( fread ( V_91 -> V_49 , 1 , V_91 -> V_51 . V_96 , V_60 )
!= V_91 -> V_51 . V_96 ) {
F_4 ( L_24 ,
strerror ( V_61 ) ) ;
}
}
}
static void F_22 ( T_6 * V_60 )
{
int V_88 , V_103 ;
for ( V_88 = 0 ; V_88 < V_47 . V_50 ; V_88 ++ ) {
struct V_89 * V_91 = & V_46 [ V_88 ] ;
if ( V_91 -> V_51 . V_92 != V_104 ) {
continue;
}
V_91 -> V_105 = malloc ( V_91 -> V_51 . V_96 ) ;
if ( ! V_91 -> V_105 ) {
F_4 ( L_25 ,
V_91 -> V_51 . V_96 ) ;
}
if ( fseek ( V_60 , V_91 -> V_51 . V_95 , V_90 ) < 0 ) {
F_4 ( L_21 ,
V_91 -> V_51 . V_95 , strerror ( V_61 ) ) ;
}
if ( fread ( V_91 -> V_105 , 1 , V_91 -> V_51 . V_96 , V_60 )
!= V_91 -> V_51 . V_96 ) {
F_4 ( L_24 ,
strerror ( V_61 ) ) ;
}
for ( V_103 = 0 ; V_103 < V_91 -> V_51 . V_96 / sizeof( T_3 ) ; V_103 ++ ) {
T_3 * V_56 = & V_91 -> V_105 [ V_103 ] ;
V_56 -> V_57 = F_17 ( V_56 -> V_57 ) ;
V_56 -> V_106 = F_17 ( V_56 -> V_106 ) ;
V_56 -> V_107 = F_17 ( V_56 -> V_107 ) ;
V_56 -> V_58 = F_15 ( V_56 -> V_58 ) ;
}
}
}
static void F_23 ( T_6 * V_60 )
{
int V_88 , V_103 ;
for ( V_88 = 0 ; V_88 < V_47 . V_50 ; V_88 ++ ) {
struct V_89 * V_91 = & V_46 [ V_88 ] ;
if ( V_91 -> V_51 . V_92 != V_108 ) {
continue;
}
V_91 -> V_109 = malloc ( V_91 -> V_51 . V_96 ) ;
if ( ! V_91 -> V_109 ) {
F_4 ( L_26 ,
V_91 -> V_51 . V_96 ) ;
}
if ( fseek ( V_60 , V_91 -> V_51 . V_95 , V_90 ) < 0 ) {
F_4 ( L_21 ,
V_91 -> V_51 . V_95 , strerror ( V_61 ) ) ;
}
if ( fread ( V_91 -> V_109 , 1 , V_91 -> V_51 . V_96 , V_60 )
!= V_91 -> V_51 . V_96 ) {
F_4 ( L_24 ,
strerror ( V_61 ) ) ;
}
for ( V_103 = 0 ; V_103 < V_91 -> V_51 . V_96 / sizeof( V_110 ) ; V_103 ++ ) {
V_110 * V_111 = & V_91 -> V_109 [ V_103 ] ;
V_111 -> V_112 = F_17 ( V_111 -> V_112 ) ;
V_111 -> V_113 = F_17 ( V_111 -> V_113 ) ;
}
}
}
static void F_24 ( void )
{
int V_88 ;
printf ( L_27 ) ;
printf ( L_28 ) ;
for ( V_88 = 0 ; V_88 < V_47 . V_50 ; V_88 ++ ) {
struct V_89 * V_91 = & V_46 [ V_88 ] ;
char * V_55 ;
T_3 * V_114 ;
int V_103 ;
if ( V_91 -> V_51 . V_92 != V_104 ) {
continue;
}
V_114 = V_91 -> V_105 ;
V_55 = V_91 -> V_101 -> V_49 ;
for ( V_103 = 0 ; V_103 < V_91 -> V_51 . V_96 / sizeof( T_3 ) ; V_103 ++ ) {
T_3 * V_56 ;
const char * V_21 ;
V_56 = & V_91 -> V_105 [ V_103 ] ;
V_21 = V_1 ( V_55 , V_56 ) ;
if ( V_56 -> V_58 != V_53 ) {
continue;
}
printf ( L_29 ,
V_103 , V_56 -> V_106 , V_56 -> V_107 ,
F_5 ( F_25 ( V_56 -> V_115 ) ) ,
F_8 ( F_26 ( V_56 -> V_115 ) ) ,
F_10 ( F_27 ( V_56 -> V_116 ) ) ,
V_21 ) ;
}
}
printf ( L_30 ) ;
}
static void F_28 ( void )
{
int V_88 , V_117 = 0 ;
for ( V_88 = 0 ; V_88 < V_47 . V_50 ; V_88 ++ ) {
struct V_89 * V_91 = & V_46 [ V_88 ] ;
struct V_89 * V_118 , * V_119 ;
char * V_55 ;
T_3 * V_114 ;
int V_103 ;
if ( V_91 -> V_51 . V_92 != V_108 ) {
continue;
}
V_119 = V_91 -> V_101 ;
V_118 = & V_46 [ V_91 -> V_51 . V_98 ] ;
if ( ! ( V_118 -> V_51 . V_93 & V_120 ) ) {
continue;
}
V_114 = V_119 -> V_105 ;
V_55 = V_119 -> V_101 -> V_49 ;
for ( V_103 = 0 ; V_103 < V_91 -> V_51 . V_96 / sizeof( V_110 ) ; V_103 ++ ) {
V_110 * V_111 ;
T_3 * V_56 ;
const char * V_21 ;
V_111 = & V_91 -> V_109 [ V_103 ] ;
V_56 = & V_114 [ F_29 ( V_111 -> V_113 ) ] ;
V_21 = V_1 ( V_55 , V_56 ) ;
if ( V_56 -> V_58 != V_53 ) {
continue;
}
if ( F_1 ( V_21 ) || F_2 ( V_21 ) )
continue;
if ( ! V_117 ) {
printf ( L_31
L_32 ) ;
printf ( L_33
L_34 ) ;
V_117 = 1 ;
}
printf ( L_35 ,
V_111 -> V_112 ,
V_111 -> V_113 ,
F_12 ( F_30 ( V_111 -> V_113 ) ) ,
V_56 -> V_106 ,
V_21 ) ;
}
}
if ( V_117 )
printf ( L_30 ) ;
}
static void F_31 ( void (* F_32)( V_110 * V_111 , T_3 * V_56 ) )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_47 . V_50 ; V_88 ++ ) {
char * V_55 ;
T_3 * V_114 ;
struct V_89 * V_118 , * V_119 ;
int V_103 ;
struct V_89 * V_91 = & V_46 [ V_88 ] ;
if ( V_91 -> V_51 . V_92 != V_108 ) {
continue;
}
V_119 = V_91 -> V_101 ;
V_118 = & V_46 [ V_91 -> V_51 . V_98 ] ;
if ( ! ( V_118 -> V_51 . V_93 & V_120 ) ) {
continue;
}
V_114 = V_119 -> V_105 ;
V_55 = V_119 -> V_101 -> V_49 ;
for ( V_103 = 0 ; V_103 < V_91 -> V_51 . V_96 / sizeof( V_110 ) ; V_103 ++ ) {
V_110 * V_111 ;
T_3 * V_56 ;
unsigned V_121 ;
V_111 = & V_91 -> V_109 [ V_103 ] ;
V_56 = & V_114 [ F_29 ( V_111 -> V_113 ) ] ;
V_121 = F_30 ( V_111 -> V_113 ) ;
if ( V_56 -> V_58 == V_53 &&
! F_2 ( V_1 ( V_55 , V_56 ) ) ) {
continue;
}
switch ( V_121 ) {
case V_33 :
case V_35 :
break;
case V_34 :
F_32 ( V_111 , V_56 ) ;
break;
default:
F_4 ( L_36 ,
F_12 ( V_121 ) , V_121 ) ;
break;
}
}
}
}
static void F_33 ( V_110 * V_111 , T_3 * V_56 )
{
V_122 += 1 ;
}
static void F_34 ( V_110 * V_111 , T_3 * V_56 )
{
V_123 [ V_124 ++ ] = V_111 -> V_112 ;
}
static int F_35 ( const void * V_125 , const void * V_126 )
{
const unsigned long * V_127 , * V_128 ;
V_127 = V_125 ; V_128 = V_126 ;
return ( * V_127 == * V_128 ) ? 0 : ( * V_127 > * V_128 ) ? 1 : - 1 ;
}
static void F_36 ( int V_129 )
{
int V_88 ;
V_122 = 0 ;
F_31 ( F_33 ) ;
V_123 = malloc ( V_122 * sizeof( V_123 [ 0 ] ) ) ;
if ( ! V_123 ) {
F_4 ( L_37 ,
V_122 ) ;
}
V_124 = 0 ;
F_31 ( F_34 ) ;
qsort ( V_123 , V_122 , sizeof( V_123 [ 0 ] ) , F_35 ) ;
if ( V_129 ) {
printf ( L_38 ) ;
printf ( L_39 ) ;
for ( V_88 = 0 ; V_88 < V_122 ; V_88 ++ ) {
printf ( L_40 , V_123 [ V_88 ] ) ;
}
printf ( L_30 ) ;
}
else {
unsigned char V_130 [ 4 ] ;
fwrite ( L_41 , 4 , 1 , stdout ) ;
for ( V_88 = 0 ; V_88 < V_122 ; V_88 ++ ) {
V_130 [ 0 ] = ( V_123 [ V_88 ] >> 0 ) & 0xff ;
V_130 [ 1 ] = ( V_123 [ V_88 ] >> 8 ) & 0xff ;
V_130 [ 2 ] = ( V_123 [ V_88 ] >> 16 ) & 0xff ;
V_130 [ 3 ] = ( V_123 [ V_88 ] >> 24 ) & 0xff ;
fwrite ( V_130 , 4 , 1 , stdout ) ;
}
}
}
static void F_37 ( void )
{
F_4 ( L_42 ) ;
}
int main ( int V_131 , char * * V_132 )
{
int V_133 , V_134 ;
int V_129 ;
const char * V_135 ;
T_6 * V_60 ;
int V_88 ;
F_3 () ;
V_133 = 0 ;
V_134 = 0 ;
V_129 = 0 ;
V_135 = NULL ;
for ( V_88 = 1 ; V_88 < V_131 ; V_88 ++ ) {
char * V_136 = V_132 [ V_88 ] ;
if ( * V_136 == '-' ) {
if ( strcmp ( V_132 [ 1 ] , L_43 ) == 0 ) {
V_133 = 1 ;
continue;
}
if ( strcmp ( V_132 [ 1 ] , L_44 ) == 0 ) {
V_134 = 1 ;
continue;
}
else if ( strcmp ( V_132 [ 1 ] , L_45 ) == 0 ) {
V_129 = 1 ;
continue;
}
}
else if ( ! V_135 ) {
V_135 = V_136 ;
continue;
}
F_37 () ;
}
if ( ! V_135 ) {
F_37 () ;
}
V_60 = fopen ( V_135 , L_46 ) ;
if ( ! V_60 ) {
F_4 ( L_47 ,
V_135 , strerror ( V_61 ) ) ;
}
F_19 ( V_60 ) ;
F_20 ( V_60 ) ;
F_21 ( V_60 ) ;
F_22 ( V_60 ) ;
F_23 ( V_60 ) ;
if ( V_133 ) {
F_24 () ;
return 0 ;
}
if ( V_134 ) {
F_28 () ;
return 0 ;
}
F_36 ( V_129 ) ;
return 0 ;
}
