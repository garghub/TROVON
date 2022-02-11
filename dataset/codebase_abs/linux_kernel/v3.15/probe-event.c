static int F_1 ( char * V_1 , T_1 V_2 , const char * V_3 , ... )
{
int V_4 ;
T_2 V_5 ;
va_start ( V_5 , V_3 ) ;
V_4 = vsnprintf ( V_1 , V_2 , V_3 , V_5 ) ;
va_end ( V_5 ) ;
if ( V_4 >= ( int ) V_2 )
V_4 = - V_6 ;
return V_4 ;
}
static int F_2 ( bool V_7 )
{
int V_4 ;
V_8 . V_9 = true ;
V_4 = F_3 () ;
if ( V_4 < 0 ) {
F_4 ( L_1 ) ;
goto V_10;
}
if ( V_11 || V_7 )
return 0 ;
if ( V_8 . V_12 )
F_4 ( L_2 , V_8 . V_12 ) ;
V_11 = F_5 () ;
if ( ! V_11 ) {
F_4 ( L_3 ) ;
F_6 () ;
V_4 = - 1 ;
}
V_10:
if ( V_4 < 0 )
F_7 ( L_4 ) ;
return V_4 ;
}
static void F_8 ( void )
{
if ( V_11 ) {
F_9 ( V_11 ) ;
V_11 = NULL ;
}
F_6 () ;
}
static struct V_13 * F_10 ( const char * V_14 ,
struct V_15 * * V_16 )
{
return F_11 ( V_11 , V_14 , V_16 ,
NULL ) ;
}
static struct V_13 * F_12 ( T_3 V_17 , struct V_15 * * V_16 )
{
return F_13 ( V_11 , V_17 , V_16 , NULL ) ;
}
static struct V_18 * F_14 ( void )
{
struct V_19 * V_19 ;
if ( F_15 ( V_11 -> V_20 [ V_21 ] , NULL ) < 0 )
return NULL ;
V_19 = F_16 ( V_11 -> V_20 [ V_21 ] ) ;
return V_19 -> V_18 ;
}
static T_3 F_17 ( const char * V_14 , bool V_22 )
{
struct V_18 * V_23 ;
struct V_13 * V_24 ;
struct V_15 * V_15 ;
V_23 = F_14 () ;
if ( V_23 && strcmp ( V_14 , V_23 -> V_14 ) == 0 )
return ( V_22 ) ? V_23 -> V_17 : V_23 -> V_25 ;
else {
V_24 = F_10 ( V_14 , & V_15 ) ;
if ( V_24 )
return V_15 -> V_26 ( V_15 , V_24 -> V_27 ) -
( V_22 ) ? 0 : V_15 -> V_22 ;
}
return 0 ;
}
static struct V_15 * F_18 ( const char * V_28 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 = & V_11 -> V_33 ;
if ( V_28 && strchr ( V_28 , '/' ) )
return F_19 ( V_11 , 0 , V_28 ) ;
if ( ! V_28 )
V_28 = L_5 ;
for ( V_30 = F_20 ( & V_32 -> V_34 [ V_21 ] ) ; V_30 ; V_30 = F_21 ( V_30 ) ) {
struct V_15 * V_35 = F_22 ( V_30 , struct V_15 , V_29 ) ;
if ( strncmp ( V_35 -> V_36 -> V_37 + 1 , V_28 ,
V_35 -> V_36 -> V_38 - 2 ) == 0 ) {
return V_35 ;
}
}
return NULL ;
}
static struct V_36 * F_23 ( const char * V_28 )
{
struct V_36 * V_36 ;
struct V_15 * V_15 ;
const char * V_12 ;
if ( V_28 ) {
F_24 (dso, &host_machine->kernel_dsos, node) {
if ( strncmp ( V_36 -> V_37 + 1 , V_28 ,
V_36 -> V_38 - 2 ) == 0 )
goto V_39;
}
F_4 ( L_6 , V_28 ) ;
return NULL ;
}
V_15 = V_11 -> V_20 [ V_21 ] ;
V_36 = V_15 -> V_36 ;
V_12 = V_8 . V_12 ;
if ( V_12 ) {
if ( F_25 ( V_36 , V_15 , V_12 , false , NULL ) <= 0 )
return NULL ;
} else {
if ( F_26 ( V_36 , V_15 , NULL ) <= 0 ) {
F_4 ( L_7 ) ;
return NULL ;
}
}
V_39:
return V_36 ;
}
const char * F_27 ( const char * V_28 )
{
struct V_36 * V_36 = F_23 ( V_28 ) ;
return ( V_36 ) ? V_36 -> V_40 : NULL ;
}
static int F_28 ( const char * V_41 , char * * V_42 )
{
char * V_43 , * V_44 , * V_45 ;
char V_46 [ 64 ] ;
int V_4 ;
V_45 = F_29 ( V_41 ) ;
if ( ! V_45 )
return - V_47 ;
V_43 = F_30 ( V_45 ) ;
if ( ! V_43 ) {
V_4 = - V_48 ;
goto V_10;
}
V_44 = strpbrk ( V_43 , L_8 ) ;
if ( V_44 )
* V_44 = '\0' ;
V_4 = F_1 ( V_46 , 64 , L_9 , V_49 , V_43 ) ;
if ( V_4 < 0 )
goto V_10;
* V_42 = F_29 ( V_46 ) ;
V_4 = * V_42 ? 0 : - V_47 ;
V_10:
free ( V_45 ) ;
return V_4 ;
}
static void F_31 ( struct V_50 * V_51 , int V_52 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ )
F_32 ( V_51 + V_53 ) ;
}
static struct V_54 * F_33 ( const char * V_28 )
{
const char * V_55 = V_28 ;
if ( ! V_28 || ! strchr ( V_28 , '/' ) ) {
V_55 = F_27 ( V_28 ) ;
if ( ! V_55 ) {
F_34 ( L_10 ,
V_28 ? : L_5 ) ;
return NULL ;
}
}
return F_35 ( V_55 ) ;
}
static int F_36 ( const char * V_41 , unsigned long * V_56 )
{
T_4 * V_57 ;
T_5 V_58 ;
T_6 V_59 ;
int V_60 , V_4 = - V_61 ;
V_60 = F_37 ( V_41 , V_62 ) ;
if ( V_60 < 0 )
return - V_63 ;
V_57 = F_38 ( V_60 , V_64 , NULL ) ;
if ( V_57 == NULL )
return - V_48 ;
if ( F_39 ( V_57 , & V_58 ) == NULL )
goto V_10;
if ( ! F_40 ( V_57 , & V_58 , & V_59 , L_11 , NULL ) )
goto V_10;
* V_56 = V_59 . V_65 - V_59 . V_66 ;
V_4 = 0 ;
V_10:
F_41 ( V_57 ) ;
return V_4 ;
}
static int F_42 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
bool V_71 )
{
struct V_54 * V_72 = NULL ;
unsigned long V_73 = 0 ;
T_3 V_17 = V_68 -> V_56 ;
int V_4 = - V_61 ;
if ( ! V_71 ) {
if ( ! V_17 ) {
V_4 = - V_48 ;
goto error;
}
V_4 = F_36 ( V_68 -> V_28 , & V_73 ) ;
if ( V_4 < 0 )
goto error;
V_17 += V_73 ;
} else {
V_17 = F_17 ( V_68 -> V_13 , false ) ;
if ( V_17 == 0 )
goto error;
V_17 += V_68 -> V_74 ;
}
F_4 ( L_12 V_75 L_13 , V_17 ,
V_68 -> V_28 ? : L_5 ) ;
V_72 = F_33 ( V_68 -> V_28 ) ;
if ( V_72 ) {
V_4 = F_43 ( V_72 ,
( unsigned long ) V_17 , V_70 ) ;
F_44 ( V_72 ) ;
} else {
F_4 ( L_14 V_75 L_15 , V_17 ) ;
V_4 = - V_61 ;
}
if ( V_4 > 0 ) {
V_70 -> V_76 = V_68 -> V_76 ;
return 0 ;
}
error:
F_4 ( L_16 ) ;
return V_4 ? : - V_61 ;
}
static int F_45 ( struct V_50 * V_51 ,
int V_52 , const char * V_41 )
{
int V_53 , V_4 = 0 ;
unsigned long V_73 = 0 ;
if ( ! V_41 )
return 0 ;
V_4 = F_36 ( V_41 , & V_73 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_53 = 0 ; V_53 < V_52 && V_4 >= 0 ; V_53 ++ ) {
V_51 [ V_53 ] . V_77 . V_56 -= V_73 ;
V_51 [ V_53 ] . V_77 . V_28 = F_29 ( V_41 ) ;
if ( ! V_51 [ V_53 ] . V_77 . V_28 ) {
V_4 = - V_47 ;
break;
}
V_51 [ V_53 ] . V_78 = true ;
}
return V_4 ;
}
static int F_46 ( struct V_50 * V_51 ,
int V_52 , const char * V_28 )
{
int V_53 , V_4 = 0 ;
char * V_79 ;
if ( ! V_28 )
return 0 ;
V_79 = strrchr ( V_28 , '/' ) ;
if ( V_79 ) {
V_28 = F_29 ( V_79 + 1 ) ;
if ( ! V_28 )
return - V_47 ;
V_79 = strchr ( V_28 , '.' ) ;
if ( V_79 )
* V_79 = '\0' ;
V_79 = ( char * ) V_28 ;
}
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_51 [ V_53 ] . V_77 . V_28 = F_29 ( V_28 ) ;
if ( ! V_51 [ V_53 ] . V_77 . V_28 ) {
V_4 = - V_47 ;
break;
}
}
free ( V_79 ) ;
return V_4 ;
}
static int F_47 ( struct V_50 * V_51 ,
int V_52 , const char * V_28 ,
bool V_80 )
{
struct V_18 * V_23 ;
char * V_79 ;
int V_53 ;
if ( V_80 )
return F_45 ( V_51 , V_52 , V_28 ) ;
if ( V_28 )
return F_46 ( V_51 , V_52 , V_28 ) ;
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_17 ) ;
return - V_48 ;
}
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
if ( V_51 [ V_53 ] . V_77 . V_56 ) {
V_79 = F_29 ( V_23 -> V_14 ) ;
if ( ! V_79 )
return - V_47 ;
free ( V_51 [ V_53 ] . V_77 . V_13 ) ;
V_51 [ V_53 ] . V_77 . V_13 = V_79 ;
V_51 [ V_53 ] . V_77 . V_74 = V_51 [ V_53 ] . V_77 . V_56 -
V_23 -> V_25 ;
}
}
return 0 ;
}
static int F_48 ( struct V_81 * V_82 ,
struct V_50 * * V_51 ,
int V_83 , const char * V_84 )
{
bool V_85 = F_49 ( V_82 ) ;
struct V_54 * V_72 ;
int V_52 , V_4 = 0 ;
V_72 = F_33 ( V_84 ) ;
if ( ! V_72 ) {
if ( V_85 ) {
F_7 ( L_18 ) ;
return - V_61 ;
}
F_4 ( L_19 ) ;
return 0 ;
}
F_4 ( L_20 ) ;
V_52 = F_50 ( V_72 , V_82 , V_51 , V_83 ) ;
F_44 ( V_72 ) ;
if ( V_52 > 0 ) {
F_4 ( L_21 , V_52 ) ;
V_4 = F_47 ( * V_51 , V_52 ,
V_84 , V_82 -> V_78 ) ;
if ( V_4 < 0 ) {
F_31 ( * V_51 , V_52 ) ;
F_51 ( V_51 ) ;
}
return V_4 < 0 ? V_4 : V_52 ;
}
if ( V_52 == 0 ) {
F_7 ( L_22 ,
F_52 ( & V_82 -> V_77 ) ) ;
return - V_61 ;
}
F_4 ( L_23 , V_52 ) ;
if ( V_52 == - V_86 ) {
F_7 ( L_24
L_25 ) ;
if ( ! V_85 ) {
F_4 ( L_26 ) ;
return 0 ;
}
}
return V_52 ;
}
static int F_53 ( const char * V_87 , const char * V_88 ,
char * * V_89 )
{
const char * V_90 = V_8 . V_91 ;
if ( ! V_90 ) {
if ( V_87 [ 0 ] != '/' && V_88 )
V_90 = V_88 ;
else {
if ( F_54 ( V_87 , V_92 ) == 0 ) {
* V_89 = F_29 ( V_87 ) ;
return 0 ;
} else
return - V_63 ;
}
}
* V_89 = malloc ( ( strlen ( V_90 ) + strlen ( V_87 ) + 2 ) ) ;
if ( ! * V_89 )
return - V_47 ;
for (; ; ) {
sprintf ( * V_89 , L_27 , V_90 , V_87 ) ;
if ( F_54 ( * V_89 , V_92 ) == 0 )
return 0 ;
if ( ! V_8 . V_91 )
return - V_63 ;
switch ( V_63 ) {
case V_93 :
case V_61 :
case V_94 :
case V_95 :
V_87 = strchr ( ++ V_87 , '/' ) ;
if ( ! V_87 ) {
F_51 ( V_89 ) ;
return - V_61 ;
}
continue;
default:
F_51 ( V_89 ) ;
return - V_63 ;
}
}
}
static int F_55 ( T_7 * V_96 , int V_97 , bool V_98 , bool V_99 )
{
char V_46 [ V_100 ] ;
const char * V_101 = V_99 ? L_28 : V_102 ;
const char * V_90 = NULL ;
do {
if ( fgets ( V_46 , V_100 , V_96 ) == NULL )
goto error;
if ( V_98 )
continue;
if ( ! V_90 ) {
V_90 = V_99 ? L_29 : L_30 ;
F_56 ( stdout , V_101 , V_90 , V_97 ) ;
}
F_56 ( stdout , V_101 , L_31 , V_46 ) ;
} while ( strchr ( V_46 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_96 ) ) {
F_7 ( L_32 , strerror ( V_63 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_57 ( T_7 * V_96 , int V_97 , bool V_98 , bool V_99 )
{
int V_103 = F_55 ( V_96 , V_97 , V_98 , V_99 ) ;
if ( V_103 == 0 ) {
F_7 ( L_33 ) ;
V_103 = - 1 ;
}
return V_103 ;
}
static int F_58 ( struct V_104 * V_105 , const char * V_28 )
{
int V_97 = 1 ;
struct V_106 * V_107 ;
struct V_54 * V_72 ;
T_7 * V_96 ;
int V_4 ;
char * V_79 ;
V_72 = F_33 ( V_28 ) ;
if ( ! V_72 ) {
F_7 ( L_18 ) ;
return - V_61 ;
}
V_4 = F_59 ( V_72 , V_105 ) ;
F_44 ( V_72 ) ;
if ( V_4 == 0 ) {
F_7 ( L_34 ) ;
return - V_61 ;
} else if ( V_4 < 0 ) {
F_7 ( L_35 , V_4 ) ;
return V_4 ;
}
V_79 = V_105 -> V_55 ;
V_4 = F_53 ( V_79 , V_105 -> V_88 , & V_105 -> V_55 ) ;
free ( V_79 ) ;
if ( V_4 < 0 ) {
F_7 ( L_36 , V_4 ) ;
return V_4 ;
}
F_60 () ;
if ( V_105 -> V_108 )
fprintf ( stdout , L_37 , V_105 -> V_108 , V_105 -> V_55 ,
V_105 -> V_27 - V_105 -> V_74 ) ;
else
fprintf ( stdout , L_38 , V_105 -> V_55 , V_105 -> V_27 ) ;
V_96 = fopen ( V_105 -> V_55 , L_39 ) ;
if ( V_96 == NULL ) {
F_7 ( L_40 , V_105 -> V_55 ,
strerror ( V_63 ) ) ;
return - V_63 ;
}
while ( V_97 < V_105 -> V_27 ) {
V_4 = F_61 ( V_96 , V_97 ++ ) ;
if ( V_4 < 0 )
goto V_109;
}
F_62 (ln, lr->line_list) {
for (; V_107 -> V_53 > V_97 ; V_97 ++ ) {
V_4 = F_63 ( V_96 , V_97 - V_105 -> V_74 ) ;
if ( V_4 < 0 )
goto V_109;
}
V_4 = F_64 ( V_96 , V_97 ++ - V_105 -> V_74 ) ;
if ( V_4 < 0 )
goto V_109;
}
if ( V_105 -> V_109 == V_110 )
V_105 -> V_109 = V_97 + V_111 ;
while ( V_97 <= V_105 -> V_109 ) {
V_4 = F_65 ( V_96 , V_97 ++ - V_105 -> V_74 ) ;
if ( V_4 <= 0 )
break;
}
V_109:
fclose ( V_96 ) ;
return V_4 ;
}
int F_66 ( struct V_104 * V_105 , const char * V_28 )
{
int V_4 ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_58 ( V_105 , V_28 ) ;
F_8 () ;
return V_4 ;
}
static int F_67 ( struct V_54 * V_72 ,
struct V_81 * V_82 ,
int V_112 , struct V_113 * V_114 ,
bool V_115 )
{
char * V_46 ;
int V_4 , V_53 , V_116 ;
struct V_117 * V_118 ;
struct V_119 * V_120 = NULL , * V_121 ;
const char * V_122 ;
V_46 = F_52 ( & V_82 -> V_77 ) ;
if ( ! V_46 )
return - V_48 ;
F_4 ( L_41 , V_46 ) ;
V_4 = F_68 ( V_72 , V_82 , & V_120 ,
V_112 , V_115 ) ;
if ( V_4 <= 0 ) {
F_34 ( L_42 , V_46 , V_4 ) ;
goto V_109;
}
fprintf ( stdout , L_43 , V_46 ) ;
for ( V_53 = 0 ; V_53 < V_4 ; V_53 ++ ) {
V_121 = & V_120 [ V_53 ] ;
fprintf ( stdout , L_44 , V_121 -> V_77 . V_13 ,
V_121 -> V_77 . V_74 ) ;
F_51 ( & V_121 -> V_77 . V_13 ) ;
V_116 = 0 ;
if ( V_121 -> V_123 ) {
F_69 (node, vl->vars) {
V_122 = strchr ( V_118 -> V_124 , '\t' ) + 1 ;
if ( F_70 ( V_114 , V_122 ) ) {
fprintf ( stdout , L_45 , V_118 -> V_124 ) ;
V_116 ++ ;
}
}
F_71 ( V_121 -> V_123 ) ;
}
if ( V_116 == 0 )
fprintf ( stdout , L_46 ) ;
}
free ( V_120 ) ;
V_109:
free ( V_46 ) ;
return V_4 ;
}
int F_72 ( struct V_81 * V_125 , int V_126 ,
int V_112 , const char * V_28 ,
struct V_113 * V_114 , bool V_115 )
{
int V_53 , V_4 = 0 ;
struct V_54 * V_72 ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_72 = F_33 ( V_28 ) ;
if ( ! V_72 ) {
F_7 ( L_18 ) ;
V_4 = - V_61 ;
goto V_10;
}
F_60 () ;
for ( V_53 = 0 ; V_53 < V_126 && V_4 >= 0 ; V_53 ++ )
V_4 = F_67 ( V_72 , & V_125 [ V_53 ] , V_112 , V_114 ,
V_115 ) ;
F_44 ( V_72 ) ;
V_10:
F_8 () ;
return V_4 ;
}
static int
F_42 ( struct V_67 * V_68 V_127 ,
struct V_69 * V_70 V_127 ,
bool V_71 V_127 )
{
return - V_128 ;
}
static int F_48 ( struct V_81 * V_82 ,
struct V_50 * * V_51 V_127 ,
int V_83 V_127 ,
const char * V_84 V_127 )
{
if ( F_49 ( V_82 ) ) {
F_7 ( L_47 ) ;
return - V_128 ;
}
return 0 ;
}
int F_66 ( struct V_104 * V_105 V_127 ,
const char * V_28 V_127 )
{
F_7 ( L_47 ) ;
return - V_128 ;
}
int F_72 ( struct V_81 * V_125 V_127 ,
int V_126 V_127 , int V_112 V_127 ,
const char * V_28 V_127 ,
struct V_113 * T_8 V_127 ,
bool V_115 V_127 )
{
F_7 ( L_47 ) ;
return - V_128 ;
}
void F_73 ( struct V_104 * V_105 )
{
free ( V_105 -> V_108 ) ;
free ( V_105 -> V_129 ) ;
free ( V_105 -> V_55 ) ;
free ( V_105 -> V_88 ) ;
F_74 ( V_105 -> V_130 ) ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
}
int F_75 ( struct V_104 * V_105 )
{
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_130 = F_76 ( NULL ) ;
if ( ! V_105 -> V_130 )
return - V_47 ;
else
return 0 ;
}
static int F_77 ( char * * V_131 , int * V_132 , const char * V_133 )
{
const char * V_27 = * V_131 ;
V_63 = 0 ;
* V_132 = strtol ( * V_131 , V_131 , 0 ) ;
if ( V_63 || * V_131 == V_27 ) {
F_78 ( L_48 , V_133 ) ;
return - V_48 ;
}
return 0 ;
}
int F_79 ( const char * V_134 , struct V_104 * V_105 )
{
char * V_135 , * V_129 , * V_14 = F_29 ( V_134 ) ;
int V_136 ;
if ( ! V_14 )
return - V_47 ;
V_105 -> V_27 = 0 ;
V_105 -> V_109 = V_110 ;
V_135 = strchr ( V_14 , ':' ) ;
if ( V_135 ) {
* V_135 ++ = '\0' ;
V_136 = F_77 ( & V_135 , & V_105 -> V_27 , L_49 ) ;
if ( V_136 )
goto V_136;
if ( * V_135 == '+' || * V_135 == '-' ) {
const char V_137 = * V_135 ++ ;
V_136 = F_77 ( & V_135 , & V_105 -> V_109 , L_50 ) ;
if ( V_136 )
goto V_136;
if ( V_137 == '+' ) {
V_105 -> V_109 += V_105 -> V_27 ;
V_105 -> V_109 -- ;
}
}
F_4 ( L_51 , V_105 -> V_27 , V_105 -> V_109 ) ;
V_136 = - V_48 ;
if ( V_105 -> V_27 > V_105 -> V_109 ) {
F_78 ( L_52
L_53 ) ;
goto V_136;
}
if ( * V_135 != '\0' ) {
F_78 ( L_54 , V_135 ) ;
goto V_136;
}
}
V_129 = strchr ( V_14 , '@' ) ;
if ( V_129 ) {
* V_129 = '\0' ;
V_105 -> V_129 = F_29 ( ++ V_129 ) ;
if ( V_105 -> V_129 == NULL ) {
V_136 = - V_47 ;
goto V_136;
}
V_105 -> V_108 = V_14 ;
} else if ( strchr ( V_14 , '.' ) )
V_105 -> V_129 = V_14 ;
else
V_105 -> V_108 = V_14 ;
return 0 ;
V_136:
free ( V_14 ) ;
return V_136 ;
}
static bool F_80 ( const char * V_14 )
{
if ( ! isalpha ( * V_14 ) && * V_14 != '_' )
return false ;
while ( * ++ V_14 != '\0' ) {
if ( ! isalpha ( * V_14 ) && ! isdigit ( * V_14 ) && * V_14 != '_' )
return false ;
}
return true ;
}
static int F_81 ( char * V_134 , struct V_81 * V_82 )
{
struct V_69 * V_70 = & V_82 -> V_77 ;
char * V_131 , * V_79 ;
char V_137 , V_138 = 0 ;
V_131 = strpbrk ( V_134 , L_55 ) ;
if ( V_131 && * V_131 == '=' ) {
* V_131 = '\0' ;
V_79 = V_131 + 1 ;
if ( strchr ( V_134 , ':' ) ) {
F_78 ( L_56 ) ;
return - V_139 ;
}
if ( ! F_80 ( V_134 ) ) {
F_78 ( L_57
L_58 , V_134 ) ;
return - V_48 ;
}
V_82 -> V_140 = F_29 ( V_134 ) ;
if ( V_82 -> V_140 == NULL )
return - V_47 ;
V_82 -> V_141 = NULL ;
V_134 = V_79 ;
}
V_131 = strpbrk ( V_134 , L_59 ) ;
if ( V_131 ) {
V_138 = * V_131 ;
* V_131 ++ = '\0' ;
}
V_79 = F_29 ( V_134 ) ;
if ( V_79 == NULL )
return - V_47 ;
if ( strchr ( V_79 , '.' ) )
V_70 -> V_129 = V_79 ;
else
V_70 -> V_108 = V_79 ;
while ( V_131 ) {
V_134 = V_131 ;
V_137 = V_138 ;
if ( V_137 == ';' ) {
V_70 -> V_142 = F_29 ( V_134 ) ;
if ( V_70 -> V_142 == NULL )
return - V_47 ;
break;
}
V_131 = strpbrk ( V_134 , L_59 ) ;
if ( V_131 ) {
V_138 = * V_131 ;
* V_131 ++ = '\0' ;
}
switch ( V_137 ) {
case ':' :
V_70 -> line = strtoul ( V_134 , & V_79 , 0 ) ;
if ( * V_79 != '\0' ) {
F_78 ( L_60
L_61 ) ;
return - V_48 ;
}
break;
case '+' :
V_70 -> V_74 = strtoul ( V_134 , & V_79 , 0 ) ;
if ( * V_79 != '\0' ) {
F_78 ( L_62
L_63 ) ;
return - V_48 ;
}
break;
case '@' :
if ( V_70 -> V_129 ) {
F_78 ( L_64 ) ;
return - V_48 ;
}
V_70 -> V_129 = F_29 ( V_134 ) ;
if ( V_70 -> V_129 == NULL )
return - V_47 ;
break;
case '%' :
if ( strcmp ( V_134 , L_65 ) == 0 ) {
V_70 -> V_76 = 1 ;
} else {
F_78 ( L_66 , V_134 ) ;
return - V_139 ;
}
break;
default:
F_34 ( L_67 ,
__FILE__ , __LINE__ ) ;
return - V_139 ;
break;
}
}
if ( V_70 -> V_142 && V_70 -> line ) {
F_78 ( L_68
L_69 ) ;
return - V_48 ;
}
if ( V_70 -> V_142 && V_70 -> V_74 ) {
F_78 ( L_70 ) ;
return - V_48 ;
}
if ( V_70 -> line && V_70 -> V_74 ) {
F_78 ( L_71 ) ;
return - V_48 ;
}
if ( ! V_70 -> line && ! V_70 -> V_142 && V_70 -> V_129 && ! V_70 -> V_108 ) {
F_78 ( L_72
L_73 ) ;
return - V_48 ;
}
if ( V_70 -> V_74 && ! V_70 -> V_108 ) {
F_78 ( L_74 ) ;
return - V_48 ;
}
if ( V_70 -> V_76 && ! V_70 -> V_108 ) {
F_78 ( L_75 ) ;
return - V_48 ;
}
if ( ( V_70 -> V_74 || V_70 -> line || V_70 -> V_142 ) && V_70 -> V_76 ) {
F_78 ( L_76
L_77 ) ;
return - V_48 ;
}
F_4 ( L_78 ,
V_70 -> V_108 , V_70 -> V_129 , V_70 -> line , V_70 -> V_74 , V_70 -> V_76 ,
V_70 -> V_142 ) ;
return 0 ;
}
static int F_82 ( char * V_1 , struct V_143 * V_134 )
{
char * V_79 , * V_144 ;
struct V_145 * * V_146 ;
F_4 ( L_79 , V_1 ) ;
V_79 = strchr ( V_1 , '=' ) ;
if ( V_79 ) {
V_134 -> V_14 = F_83 ( V_1 , V_79 - V_1 ) ;
if ( V_134 -> V_14 == NULL )
return - V_47 ;
F_4 ( L_80 , V_134 -> V_14 ) ;
V_1 = V_79 + 1 ;
}
V_79 = strchr ( V_1 , ':' ) ;
if ( V_79 ) {
* V_79 = '\0' ;
V_134 -> type = F_29 ( V_79 + 1 ) ;
if ( V_134 -> type == NULL )
return - V_47 ;
F_4 ( L_81 , V_134 -> type ) ;
}
V_79 = strpbrk ( V_1 , L_82 ) ;
if ( ! F_84 ( V_1 ) || ! V_79 ) {
V_134 -> V_122 = F_29 ( V_1 ) ;
if ( V_134 -> V_122 == NULL )
return - V_47 ;
F_4 ( L_83 , V_134 -> V_122 ) ;
return 0 ;
}
V_134 -> V_122 = F_83 ( V_1 , V_79 - V_1 ) ;
if ( V_134 -> V_122 == NULL )
return - V_47 ;
V_144 = V_134 -> V_122 ;
F_4 ( L_84 , V_134 -> V_122 ) ;
V_146 = & V_134 -> V_147 ;
do {
* V_146 = F_85 ( sizeof( struct V_145 ) ) ;
if ( * V_146 == NULL )
return - V_47 ;
if ( * V_79 == '[' ) {
V_1 = V_79 ;
( * V_146 ) -> V_148 = strtol ( V_1 + 1 , & V_79 , 0 ) ;
( * V_146 ) -> V_149 = true ;
if ( * V_79 != ']' || V_79 == V_1 + 1 ) {
F_78 ( L_85
L_86 ) ;
return - V_48 ;
}
V_79 ++ ;
if ( * V_79 == '\0' )
V_79 = NULL ;
} else {
if ( * V_79 == '.' ) {
V_1 = V_79 + 1 ;
( * V_146 ) -> V_149 = false ;
} else if ( V_79 [ 1 ] == '>' ) {
V_1 = V_79 + 2 ;
( * V_146 ) -> V_149 = true ;
} else {
F_78 ( L_87 ,
V_1 ) ;
return - V_48 ;
}
V_79 = strpbrk ( V_1 , L_82 ) ;
}
if ( V_79 ) {
( * V_146 ) -> V_14 = F_83 ( V_1 , V_79 - V_1 ) ;
if ( ( * V_146 ) -> V_14 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_144 = ( * V_146 ) -> V_14 ;
F_4 ( L_88 , ( * V_146 ) -> V_14 , ( * V_146 ) -> V_149 ) ;
V_146 = & ( * V_146 ) -> V_150 ;
}
} while ( V_79 );
( * V_146 ) -> V_14 = F_29 ( V_1 ) ;
if ( ( * V_146 ) -> V_14 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_144 = ( * V_146 ) -> V_14 ;
F_4 ( L_89 , ( * V_146 ) -> V_14 , ( * V_146 ) -> V_149 ) ;
if ( ! V_134 -> V_14 ) {
V_134 -> V_14 = F_29 ( V_144 ) ;
if ( V_134 -> V_14 == NULL )
return - V_47 ;
}
return 0 ;
}
int F_86 ( const char * V_151 , struct V_81 * V_82 )
{
char * * V_152 ;
int V_153 , V_53 , V_4 = 0 ;
V_152 = F_87 ( V_151 , & V_153 ) ;
if ( ! V_152 ) {
F_4 ( L_90 ) ;
return - V_47 ;
}
if ( V_153 - 1 > V_154 ) {
F_78 ( L_91 , V_153 - 1 ) ;
V_4 = - V_155 ;
goto V_10;
}
V_4 = F_81 ( V_152 [ 0 ] , V_82 ) ;
if ( V_4 < 0 )
goto V_10;
V_82 -> V_156 = V_153 - 1 ;
V_82 -> args = F_85 ( sizeof( struct V_143 ) * V_82 -> V_156 ) ;
if ( V_82 -> args == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
for ( V_53 = 0 ; V_53 < V_82 -> V_156 && V_4 >= 0 ; V_53 ++ ) {
V_4 = F_82 ( V_152 [ V_53 + 1 ] , & V_82 -> args [ V_53 ] ) ;
if ( V_4 >= 0 &&
F_84 ( V_82 -> args [ V_53 ] . V_122 ) && V_82 -> V_77 . V_76 ) {
F_78 ( L_92
L_93 ) ;
V_4 = - V_48 ;
}
}
V_10:
F_88 ( V_152 ) ;
return V_4 ;
}
bool F_49 ( struct V_81 * V_82 )
{
int V_53 ;
if ( V_82 -> V_77 . V_129 || V_82 -> V_77 . line || V_82 -> V_77 . V_142 )
return true ;
for ( V_53 = 0 ; V_53 < V_82 -> V_156 ; V_53 ++ )
if ( F_84 ( V_82 -> args [ V_53 ] . V_122 ) )
return true ;
return false ;
}
static int F_89 ( const char * V_151 ,
struct V_50 * V_157 )
{
struct V_67 * V_68 = & V_157 -> V_77 ;
char V_158 ;
char * V_159 ;
char * V_160 = NULL , * V_161 , * V_162 , * V_163 , * V_164 ;
int V_4 , V_53 , V_153 ;
char * * V_152 ;
F_4 ( L_94 , V_151 ) ;
V_152 = F_87 ( V_151 , & V_153 ) ;
if ( ! V_152 ) {
F_4 ( L_90 ) ;
return - V_47 ;
}
if ( V_153 < 2 ) {
F_78 ( L_95 ) ;
V_4 = - V_155 ;
goto V_10;
}
V_160 = F_29 ( V_152 [ 0 ] ) ;
if ( V_160 == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
V_162 = strtok_r ( V_160 , L_96 , & V_161 ) ;
V_163 = strtok_r ( NULL , L_97 , & V_161 ) ;
V_164 = strtok_r ( NULL , L_98 , & V_161 ) ;
if ( V_162 == NULL || strlen ( V_162 ) != 1 || V_163 == NULL
|| V_164 == NULL ) {
F_78 ( L_99 , V_152 [ 0 ] ) ;
V_4 = - V_48 ;
goto V_10;
}
V_158 = V_162 [ 0 ] ;
V_157 -> V_141 = F_29 ( V_163 ) ;
V_157 -> V_140 = F_29 ( V_164 ) ;
if ( V_157 -> V_141 == NULL || V_157 -> V_140 == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
F_4 ( L_100 , V_157 -> V_141 , V_157 -> V_140 , V_158 ) ;
V_68 -> V_76 = ( V_158 == 'r' ) ;
V_159 = strchr ( V_152 [ 1 ] , ':' ) ;
if ( V_159 ) {
V_68 -> V_28 = F_83 ( V_152 [ 1 ] , V_159 - V_152 [ 1 ] ) ;
V_159 ++ ;
} else
V_159 = V_152 [ 1 ] ;
V_162 = strtok_r ( V_159 , L_101 , & V_161 ) ;
if ( V_162 [ 0 ] == '0' )
V_68 -> V_56 = strtoul ( V_162 , NULL , 0 ) ;
else {
V_68 -> V_13 = F_29 ( V_162 ) ;
if ( V_68 -> V_13 == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
V_163 = strtok_r ( NULL , L_28 , & V_161 ) ;
if ( V_163 == NULL )
V_68 -> V_74 = 0 ;
else
V_68 -> V_74 = strtoul ( V_163 , NULL , 10 ) ;
}
V_157 -> V_156 = V_153 - 2 ;
V_157 -> args = F_85 ( sizeof( struct V_165 ) * V_157 -> V_156 ) ;
if ( V_157 -> args == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
for ( V_53 = 0 ; V_53 < V_157 -> V_156 ; V_53 ++ ) {
V_159 = strchr ( V_152 [ V_53 + 2 ] , '=' ) ;
if ( V_159 )
* V_159 ++ = '\0' ;
else
V_159 = V_152 [ V_53 + 2 ] ;
V_157 -> args [ V_53 ] . V_14 = F_29 ( V_152 [ V_53 + 2 ] ) ;
V_157 -> args [ V_53 ] . V_166 = F_29 ( V_159 ) ;
if ( V_157 -> args [ V_53 ] . V_14 == NULL || V_157 -> args [ V_53 ] . V_166 == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
}
V_4 = 0 ;
V_10:
free ( V_160 ) ;
F_88 ( V_152 ) ;
return V_4 ;
}
int F_90 ( struct V_143 * V_167 , char * V_46 , T_1 V_168 )
{
struct V_145 * V_147 = V_167 -> V_147 ;
int V_4 ;
char * V_79 = V_46 ;
if ( V_167 -> V_14 && V_167 -> V_122 )
V_4 = F_1 ( V_79 , V_168 , L_102 , V_167 -> V_14 , V_167 -> V_122 ) ;
else
V_4 = F_1 ( V_79 , V_168 , L_31 , V_167 -> V_14 ? V_167 -> V_14 : V_167 -> V_122 ) ;
if ( V_4 <= 0 )
goto error;
V_79 += V_4 ;
V_168 -= V_4 ;
while ( V_147 ) {
if ( V_147 -> V_14 [ 0 ] == '[' )
V_4 = F_1 ( V_79 , V_168 , L_31 , V_147 -> V_14 ) ;
else
V_4 = F_1 ( V_79 , V_168 , L_103 ,
V_147 -> V_149 ? L_104 : L_105 , V_147 -> V_14 ) ;
if ( V_4 <= 0 )
goto error;
V_79 += V_4 ;
V_168 -= V_4 ;
V_147 = V_147 -> V_150 ;
}
if ( V_167 -> type ) {
V_4 = F_1 ( V_79 , V_168 , L_106 , V_167 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_79 += V_4 ;
V_168 -= V_4 ;
}
return V_79 - V_46 ;
error:
F_4 ( L_107 ,
strerror ( - V_4 ) ) ;
return V_4 ;
}
static char * F_52 ( struct V_69 * V_70 )
{
char * V_46 , * V_79 ;
char V_169 [ 32 ] = L_28 , line [ 32 ] = L_28 , V_129 [ 32 ] = L_28 ;
int V_4 , V_168 ;
V_46 = F_85 ( V_170 ) ;
if ( V_46 == NULL ) {
V_4 = - V_47 ;
goto error;
}
if ( V_70 -> V_74 ) {
V_4 = F_1 ( V_169 , 32 , L_108 , V_70 -> V_74 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_70 -> line ) {
V_4 = F_1 ( line , 32 , L_109 , V_70 -> line ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_70 -> V_129 ) {
V_79 = V_70 -> V_129 ;
V_168 = strlen ( V_79 ) ;
if ( V_168 > 30 ) {
V_79 = strchr ( V_70 -> V_129 + V_168 - 30 , '/' ) ;
V_79 = V_79 ? V_79 + 1 : V_70 -> V_129 + V_168 - 30 ;
}
V_4 = F_1 ( V_129 , 32 , L_110 , V_79 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_70 -> V_108 )
V_4 = F_1 ( V_46 , V_170 , L_111 , V_70 -> V_108 ,
V_169 , V_70 -> V_76 ? L_112 : L_28 , line ,
V_129 ) ;
else
V_4 = F_1 ( V_46 , V_170 , L_103 , V_129 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_46 ;
error:
F_4 ( L_113 ,
strerror ( - V_4 ) ) ;
free ( V_46 ) ;
return NULL ;
}
static int F_91 ( struct V_171 * V_149 ,
char * * V_46 , T_1 * V_172 ,
int V_173 )
{
int V_4 ;
if ( V_149 -> V_150 ) {
V_173 = F_91 ( V_149 -> V_150 , V_46 ,
V_172 , V_173 + 1 ) ;
if ( V_173 < 0 )
goto V_10;
}
V_4 = F_1 ( * V_46 , * V_172 , L_114 , V_149 -> V_74 ) ;
if ( V_4 < 0 )
V_173 = V_4 ;
else {
* V_46 += V_4 ;
* V_172 -= V_4 ;
}
V_10:
return V_173 ;
}
static int F_92 ( struct V_165 * V_134 ,
char * V_46 , T_1 V_172 )
{
struct V_171 * V_149 = V_134 -> V_149 ;
int V_4 , V_173 = 0 ;
char * V_79 = V_46 ;
if ( V_134 -> V_14 )
V_4 = F_1 ( V_46 , V_172 , L_115 , V_134 -> V_14 ) ;
else
V_4 = F_1 ( V_46 , V_172 , L_116 ) ;
if ( V_4 < 0 )
return V_4 ;
V_46 += V_4 ;
V_172 -= V_4 ;
if ( V_134 -> V_166 [ 0 ] == '@' && V_134 -> V_149 )
V_149 = V_149 -> V_150 ;
if ( V_149 ) {
V_173 = F_91 ( V_149 , & V_46 ,
& V_172 , 1 ) ;
if ( V_173 < 0 )
return V_173 ;
}
if ( V_134 -> V_166 [ 0 ] == '@' && V_134 -> V_149 )
V_4 = F_1 ( V_46 , V_172 , L_117 , V_134 -> V_166 ,
V_134 -> V_149 -> V_74 ) ;
else
V_4 = F_1 ( V_46 , V_172 , L_31 , V_134 -> V_166 ) ;
if ( V_4 < 0 )
return V_4 ;
V_46 += V_4 ;
V_172 -= V_4 ;
while ( V_173 -- ) {
V_4 = F_1 ( V_46 , V_172 , L_118 ) ;
if ( V_4 < 0 )
return V_4 ;
V_46 += V_4 ;
V_172 -= V_4 ;
}
if ( V_134 -> type ) {
V_4 = F_1 ( V_46 , V_172 , L_106 , V_134 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_46 += V_4 ;
}
return V_46 - V_79 ;
}
char * F_93 ( struct V_50 * V_157 )
{
struct V_67 * V_68 = & V_157 -> V_77 ;
char * V_46 ;
int V_53 , V_168 , V_4 ;
V_46 = F_85 ( V_170 ) ;
if ( V_46 == NULL )
return NULL ;
V_168 = F_1 ( V_46 , V_170 , L_119 , V_68 -> V_76 ? 'r' : 'p' ,
V_157 -> V_141 , V_157 -> V_140 ) ;
if ( V_168 <= 0 )
goto error;
if ( V_157 -> V_78 && ( ! V_68 -> V_56 || ! V_68 -> V_28 ) )
goto error;
if ( V_157 -> V_78 )
V_4 = F_1 ( V_46 + V_168 , V_170 - V_168 , L_120 ,
V_68 -> V_28 , V_68 -> V_56 ) ;
else
V_4 = F_1 ( V_46 + V_168 , V_170 - V_168 , L_121 ,
V_68 -> V_28 ? : L_28 , V_68 -> V_28 ? L_96 : L_28 ,
V_68 -> V_13 , V_68 -> V_74 ) ;
if ( V_4 <= 0 )
goto error;
V_168 += V_4 ;
for ( V_53 = 0 ; V_53 < V_157 -> V_156 ; V_53 ++ ) {
V_4 = F_92 ( & V_157 -> args [ V_53 ] , V_46 + V_168 ,
V_170 - V_168 ) ;
if ( V_4 <= 0 )
goto error;
V_168 += V_4 ;
}
return V_46 ;
error:
free ( V_46 ) ;
return NULL ;
}
static int F_94 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
bool V_71 )
{
struct V_13 * V_24 = NULL ;
struct V_15 * V_15 ;
T_3 V_17 ;
int V_4 = - V_61 ;
if ( ! V_71 ) {
V_15 = F_95 ( V_68 -> V_28 ) ;
if ( ! V_15 )
goto V_10;
V_17 = V_68 -> V_56 ;
V_24 = F_96 ( V_15 , V_17 , NULL ) ;
} else {
V_17 = F_17 ( V_68 -> V_13 , true ) ;
if ( V_17 ) {
V_17 += V_68 -> V_74 ;
V_24 = F_12 ( V_17 , & V_15 ) ;
}
}
if ( ! V_24 )
goto V_10;
V_70 -> V_76 = V_68 -> V_76 ;
V_70 -> V_74 = V_17 - V_15 -> V_26 ( V_15 , V_24 -> V_27 ) ;
V_70 -> V_108 = F_29 ( V_24 -> V_14 ) ;
V_4 = V_70 -> V_108 ? 0 : - V_47 ;
V_10:
if ( V_15 && ! V_71 ) {
F_97 ( V_15 -> V_36 ) ;
F_98 ( V_15 ) ;
}
return V_4 ;
}
static int F_99 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
bool V_71 )
{
char V_46 [ 128 ] ;
int V_4 ;
V_4 = F_42 ( V_68 , V_70 , V_71 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_94 ( V_68 , V_70 , V_71 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( L_122 ) ;
if ( V_68 -> V_13 ) {
V_70 -> V_108 = F_29 ( V_68 -> V_13 ) ;
V_70 -> V_74 = V_68 -> V_74 ;
} else if ( ! V_68 -> V_28 && ! V_71 ) {
V_4 = F_1 ( V_46 , 128 , L_123 V_75 , ( T_3 ) V_68 -> V_56 ) ;
if ( V_4 < 0 )
return V_4 ;
V_70 -> V_108 = F_29 ( V_46 ) ;
V_70 -> V_74 = 0 ;
}
if ( V_70 -> V_108 == NULL )
return - V_47 ;
V_70 -> V_76 = V_68 -> V_76 ;
return 0 ;
}
static int F_100 ( struct V_50 * V_157 ,
struct V_81 * V_82 , bool V_71 )
{
char V_46 [ 64 ] = L_28 ;
int V_53 , V_4 ;
V_82 -> V_140 = F_29 ( V_157 -> V_140 ) ;
V_82 -> V_141 = F_29 ( V_157 -> V_141 ) ;
if ( V_82 -> V_140 == NULL || V_82 -> V_141 == NULL )
return - V_47 ;
V_4 = F_99 ( & V_157 -> V_77 , & V_82 -> V_77 , V_71 ) ;
if ( V_4 < 0 )
return V_4 ;
V_82 -> V_156 = V_157 -> V_156 ;
V_82 -> args = F_85 ( sizeof( struct V_143 ) * V_82 -> V_156 ) ;
if ( V_82 -> args == NULL )
return - V_47 ;
for ( V_53 = 0 ; V_53 < V_157 -> V_156 && V_4 >= 0 ; V_53 ++ ) {
if ( V_157 -> args [ V_53 ] . V_14 )
V_82 -> args [ V_53 ] . V_14 = F_29 ( V_157 -> args [ V_53 ] . V_14 ) ;
else {
V_4 = F_92 ( & V_157 -> args [ V_53 ] ,
V_46 , 64 ) ;
V_82 -> args [ V_53 ] . V_14 = F_29 ( V_46 ) ;
}
if ( V_82 -> args [ V_53 ] . V_14 == NULL && V_4 >= 0 )
V_4 = - V_47 ;
}
if ( V_4 < 0 )
F_101 ( V_82 ) ;
return V_4 ;
}
void F_101 ( struct V_81 * V_82 )
{
struct V_69 * V_70 = & V_82 -> V_77 ;
struct V_145 * V_147 , * V_150 ;
int V_53 ;
free ( V_82 -> V_140 ) ;
free ( V_82 -> V_141 ) ;
free ( V_70 -> V_129 ) ;
free ( V_70 -> V_108 ) ;
free ( V_70 -> V_142 ) ;
for ( V_53 = 0 ; V_53 < V_82 -> V_156 ; V_53 ++ ) {
free ( V_82 -> args [ V_53 ] . V_14 ) ;
free ( V_82 -> args [ V_53 ] . V_122 ) ;
free ( V_82 -> args [ V_53 ] . type ) ;
V_147 = V_82 -> args [ V_53 ] . V_147 ;
while ( V_147 ) {
V_150 = V_147 -> V_150 ;
F_51 ( & V_147 -> V_14 ) ;
free ( V_147 ) ;
V_147 = V_150 ;
}
}
free ( V_82 -> args ) ;
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
}
static void F_32 ( struct V_50 * V_157 )
{
struct V_171 * V_149 , * V_150 ;
int V_53 ;
free ( V_157 -> V_140 ) ;
free ( V_157 -> V_141 ) ;
free ( V_157 -> V_77 . V_13 ) ;
free ( V_157 -> V_77 . V_28 ) ;
for ( V_53 = 0 ; V_53 < V_157 -> V_156 ; V_53 ++ ) {
free ( V_157 -> args [ V_53 ] . V_14 ) ;
free ( V_157 -> args [ V_53 ] . V_166 ) ;
free ( V_157 -> args [ V_53 ] . type ) ;
V_149 = V_157 -> args [ V_53 ] . V_149 ;
while ( V_149 ) {
V_150 = V_149 -> V_150 ;
free ( V_149 ) ;
V_149 = V_150 ;
}
}
free ( V_157 -> args ) ;
memset ( V_157 , 0 , sizeof( * V_157 ) ) ;
}
static void F_102 ( const char * V_129 , bool V_71 )
{
if ( V_63 == V_61 ) {
const char * V_174 ;
if ( ! V_71 )
V_174 = L_124 ;
else
V_174 = L_125 ;
F_7 ( L_126
L_127 , V_129 , V_174 ) ;
} else
F_7 ( L_128 , V_129 ,
strerror ( V_63 ) ) ;
}
static int F_103 ( const char * V_175 , bool V_176 ,
bool V_71 )
{
char V_46 [ V_177 ] ;
const char * V_178 ;
int V_4 ;
V_178 = F_104 () ;
if ( V_178 == NULL ) {
F_7 ( L_129 ) ;
return - V_61 ;
}
V_4 = F_1 ( V_46 , V_177 , L_27 , V_178 , V_175 ) ;
if ( V_4 >= 0 ) {
F_4 ( L_130 , V_46 , V_176 ) ;
if ( V_176 && ! V_179 )
V_4 = F_37 ( V_46 , V_180 , V_181 ) ;
else
V_4 = F_37 ( V_46 , V_62 , 0 ) ;
if ( V_4 < 0 )
F_102 ( V_46 , V_71 ) ;
}
return V_4 ;
}
static int F_105 ( bool V_176 )
{
return F_103 ( L_131 , V_176 , true ) ;
}
static int F_106 ( bool V_176 )
{
return F_103 ( L_132 , V_176 , false ) ;
}
static struct V_182 * F_107 ( int V_60 )
{
int V_4 , V_183 ;
T_7 * V_96 ;
char V_46 [ V_170 ] ;
char * V_159 ;
struct V_182 * V_184 ;
V_184 = F_108 ( true , NULL ) ;
V_96 = fdopen ( F_109 ( V_60 ) , L_39 ) ;
while ( ! feof ( V_96 ) ) {
V_159 = fgets ( V_46 , V_170 , V_96 ) ;
if ( ! V_159 )
break;
V_183 = strlen ( V_159 ) - 1 ;
if ( V_159 [ V_183 ] == '\n' )
V_159 [ V_183 ] = '\0' ;
V_4 = F_110 ( V_184 , V_46 ) ;
if ( V_4 < 0 ) {
F_4 ( L_133 , strerror ( - V_4 ) ) ;
F_71 ( V_184 ) ;
return NULL ;
}
}
fclose ( V_96 ) ;
return V_184 ;
}
static int F_111 ( struct V_81 * V_82 ,
const char * V_28 )
{
int V_53 , V_4 ;
char V_46 [ 128 ] ;
char * V_185 ;
V_185 = F_52 ( & V_82 -> V_77 ) ;
if ( ! V_185 )
return - V_48 ;
V_4 = F_1 ( V_46 , 128 , L_134 , V_82 -> V_141 , V_82 -> V_140 ) ;
if ( V_4 < 0 )
return V_4 ;
printf ( L_135 , V_46 , V_185 ) ;
if ( V_28 )
printf ( L_136 , V_28 ) ;
if ( V_82 -> V_156 > 0 ) {
printf ( L_137 ) ;
for ( V_53 = 0 ; V_53 < V_82 -> V_156 ; V_53 ++ ) {
V_4 = F_90 ( & V_82 -> args [ V_53 ] ,
V_46 , 128 ) ;
if ( V_4 < 0 )
break;
printf ( L_138 , V_46 ) ;
}
}
printf ( L_139 ) ;
free ( V_185 ) ;
return V_4 ;
}
static int F_112 ( int V_60 , bool V_71 )
{
int V_4 = 0 ;
struct V_50 V_157 ;
struct V_81 V_82 ;
struct V_182 * V_186 ;
struct V_117 * V_187 ;
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_186 = F_107 ( V_60 ) ;
if ( ! V_186 )
return - V_61 ;
F_69 (ent, rawlist) {
V_4 = F_89 ( V_187 -> V_124 , & V_157 ) ;
if ( V_4 >= 0 ) {
V_4 = F_100 ( & V_157 , & V_82 ,
V_71 ) ;
if ( V_4 >= 0 )
V_4 = F_111 ( & V_82 ,
V_157 . V_77 . V_28 ) ;
}
F_101 ( & V_82 ) ;
F_32 ( & V_157 ) ;
if ( V_4 < 0 )
break;
}
F_71 ( V_186 ) ;
return V_4 ;
}
int F_113 ( void )
{
int V_60 , V_4 ;
F_60 () ;
V_60 = F_105 ( false ) ;
if ( V_60 < 0 )
return V_60 ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_112 ( V_60 , true ) ;
F_114 ( V_60 ) ;
V_60 = F_106 ( false ) ;
if ( V_60 >= 0 ) {
V_4 = F_112 ( V_60 , false ) ;
F_114 ( V_60 ) ;
}
F_8 () ;
return V_4 ;
}
static struct V_182 * F_115 ( int V_60 , bool V_188 )
{
char V_46 [ 128 ] ;
struct V_182 * V_184 , * V_186 ;
struct V_117 * V_187 ;
struct V_50 V_157 ;
int V_4 = 0 ;
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
V_186 = F_107 ( V_60 ) ;
V_184 = F_108 ( true , NULL ) ;
F_69 (ent, rawlist) {
V_4 = F_89 ( V_187 -> V_124 , & V_157 ) ;
if ( V_4 < 0 )
break;
if ( V_188 ) {
V_4 = F_1 ( V_46 , 128 , L_134 , V_157 . V_141 ,
V_157 . V_140 ) ;
if ( V_4 >= 0 )
V_4 = F_110 ( V_184 , V_46 ) ;
} else
V_4 = F_110 ( V_184 , V_157 . V_140 ) ;
F_32 ( & V_157 ) ;
if ( V_4 < 0 )
break;
}
F_71 ( V_186 ) ;
if ( V_4 < 0 ) {
F_71 ( V_184 ) ;
return NULL ;
}
return V_184 ;
}
static int F_116 ( int V_60 , struct V_50 * V_157 )
{
int V_4 = 0 ;
char * V_46 = F_93 ( V_157 ) ;
if ( ! V_46 ) {
F_4 ( L_140 ) ;
return - V_48 ;
}
F_4 ( L_141 , V_46 ) ;
if ( ! V_179 ) {
V_4 = F_117 ( V_60 , V_46 , strlen ( V_46 ) ) ;
if ( V_4 <= 0 )
F_7 ( L_142 ,
strerror ( V_63 ) ) ;
}
free ( V_46 ) ;
return V_4 ;
}
static int F_118 ( char * V_46 , T_1 V_168 , const char * V_189 ,
struct V_182 * V_190 , bool V_191 )
{
int V_53 , V_4 ;
V_4 = F_1 ( V_46 , V_168 , L_31 , V_189 ) ;
if ( V_4 < 0 ) {
F_4 ( L_143 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_119 ( V_190 , V_46 ) )
return 0 ;
if ( ! V_191 ) {
F_7 ( L_144
L_145 , V_189 ) ;
return - V_192 ;
}
for ( V_53 = 1 ; V_53 < V_193 ; V_53 ++ ) {
V_4 = F_1 ( V_46 , V_168 , L_146 , V_189 , V_53 ) ;
if ( V_4 < 0 ) {
F_4 ( L_143 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_119 ( V_190 , V_46 ) )
break;
}
if ( V_53 == V_193 ) {
F_7 ( L_147 ) ;
V_4 = - V_155 ;
}
return V_4 ;
}
static int F_120 ( struct V_81 * V_82 ,
struct V_50 * V_51 ,
int V_52 , bool V_191 )
{
int V_53 , V_60 , V_4 ;
struct V_50 * V_157 = NULL ;
char V_46 [ 64 ] ;
const char * V_140 , * V_141 ;
struct V_182 * V_190 ;
if ( V_82 -> V_78 )
V_60 = F_106 ( true ) ;
else
V_60 = F_105 ( true ) ;
if ( V_60 < 0 )
return V_60 ;
V_190 = F_115 ( V_60 , false ) ;
if ( ! V_190 ) {
F_4 ( L_148 ) ;
return - V_194 ;
}
V_4 = 0 ;
printf ( L_149 , ( V_52 > 1 ) ? L_150 : L_96 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_157 = & V_51 [ V_53 ] ;
if ( V_82 -> V_140 )
V_140 = V_82 -> V_140 ;
else
if ( V_82 -> V_77 . V_108 )
V_140 = V_82 -> V_77 . V_108 ;
else
V_140 = V_157 -> V_77 . V_13 ;
if ( V_82 -> V_141 )
V_141 = V_82 -> V_141 ;
else
V_141 = V_49 ;
V_4 = F_118 ( V_46 , 64 , V_140 ,
V_190 , V_191 ) ;
if ( V_4 < 0 )
break;
V_140 = V_46 ;
V_157 -> V_140 = F_29 ( V_140 ) ;
V_157 -> V_141 = F_29 ( V_141 ) ;
if ( V_157 -> V_140 == NULL || V_157 -> V_141 == NULL ) {
V_4 = - V_47 ;
break;
}
V_4 = F_116 ( V_60 , V_157 ) ;
if ( V_4 < 0 )
break;
F_110 ( V_190 , V_140 ) ;
V_140 = V_82 -> V_140 ;
V_141 = V_82 -> V_141 ;
V_82 -> V_140 = V_157 -> V_140 ;
V_82 -> V_141 = V_157 -> V_141 ;
F_111 ( V_82 , V_157 -> V_77 . V_28 ) ;
V_82 -> V_140 = ( char * ) V_140 ;
V_82 -> V_141 = ( char * ) V_141 ;
V_191 = true ;
}
if ( V_4 >= 0 ) {
printf ( L_151 ) ;
printf ( L_152 , V_157 -> V_141 ,
V_157 -> V_140 ) ;
}
F_71 ( V_190 ) ;
F_114 ( V_60 ) ;
return V_4 ;
}
static int F_121 ( struct V_15 * V_15 V_127 ,
struct V_13 * V_24 )
{
if ( ( V_24 -> V_195 == V_196 || V_24 -> V_195 == V_197 ) &&
strcmp ( V_198 , V_24 -> V_14 ) == 0 ) {
V_199 ++ ;
return 0 ;
}
return 1 ;
}
static int F_122 ( struct V_81 * V_82 ,
struct V_50 * * V_51 ,
int V_83 , const char * V_84 )
{
struct V_15 * V_15 = NULL ;
struct V_19 * V_19 = NULL ;
struct V_18 * V_23 = NULL ;
struct V_13 * V_24 ;
struct V_29 * V_30 ;
struct V_50 * V_157 ;
struct V_69 * V_70 = & V_82 -> V_77 ;
struct V_67 * V_68 ;
int V_4 , V_53 ;
if ( V_82 -> V_78 )
V_15 = F_95 ( V_84 ) ;
else
V_15 = F_18 ( V_84 ) ;
if ( ! V_15 ) {
V_4 = - V_48 ;
goto V_10;
}
V_199 = 0 ;
V_198 = V_70 -> V_108 ;
V_4 = F_15 ( V_15 , F_121 ) ;
if ( V_4 || V_199 == 0 ) {
F_34 ( L_153 , V_70 -> V_108 ,
V_84 ? : L_5 ) ;
V_4 = - V_61 ;
goto V_10;
} else if ( V_199 > V_83 ) {
F_34 ( L_154 ,
V_84 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_10;
}
if ( ! V_82 -> V_78 ) {
V_19 = F_16 ( V_15 ) ;
V_23 = V_19 -> V_18 ;
if ( ! V_23 ) {
F_7 ( L_17 ) ;
V_4 = - V_48 ;
goto V_10;
}
}
* V_51 = F_85 ( sizeof( * V_157 ) * V_199 ) ;
if ( ! * V_51 ) {
V_4 = - V_47 ;
goto V_10;
}
V_4 = 0 ;
F_123 (map, sym, nd) {
V_157 = ( * V_51 ) + V_4 ;
V_68 = & V_157 -> V_77 ;
if ( V_4 == V_199 ) {
F_7 ( L_155 ) ;
break;
}
V_4 ++ ;
if ( V_70 -> V_74 > V_24 -> V_109 - V_24 -> V_27 ) {
F_7 ( L_156 ,
V_70 -> V_74 , V_24 -> V_14 ) ;
V_4 = - V_61 ;
goto V_200;
}
V_68 -> V_56 = V_15 -> V_26 ( V_15 , V_24 -> V_27 ) + V_70 -> V_74 ;
if ( V_23 ) {
V_68 -> V_13 = F_124 ( V_23 -> V_14 , V_201 ) ;
V_68 -> V_74 = V_68 -> V_56 - V_23 -> V_17 ;
} else {
V_68 -> V_13 = F_124 ( V_24 -> V_14 , V_201 ) ;
V_68 -> V_74 = V_70 -> V_74 ;
}
V_68 -> V_76 = V_70 -> V_76 ;
if ( V_84 )
V_157 -> V_77 . V_28 = F_124 ( V_84 , V_201 ) ;
V_157 -> V_78 = V_82 -> V_78 ;
V_157 -> V_156 = V_82 -> V_156 ;
if ( V_157 -> V_156 ) {
V_157 -> args = F_85 ( sizeof( struct V_165 ) *
V_157 -> V_156 ) ;
if ( V_157 -> args == NULL )
goto V_201;
}
for ( V_53 = 0 ; V_53 < V_157 -> V_156 ; V_53 ++ ) {
if ( V_82 -> args [ V_53 ] . V_14 )
V_157 -> args [ V_53 ] . V_14 =
F_124 ( V_82 -> args [ V_53 ] . V_14 ,
V_201 ) ;
V_157 -> args [ V_53 ] . V_166 = F_124 ( V_82 -> args [ V_53 ] . V_122 ,
V_201 ) ;
if ( V_82 -> args [ V_53 ] . type )
V_157 -> args [ V_53 ] . type =
F_124 ( V_82 -> args [ V_53 ] . type ,
V_201 ) ;
}
}
V_10:
if ( V_15 && V_82 -> V_78 ) {
F_97 ( V_15 -> V_36 ) ;
F_98 ( V_15 ) ;
}
return V_4 ;
V_201:
V_4 = - V_47 ;
V_200:
F_31 ( * V_51 , V_199 ) ;
F_51 ( V_51 ) ;
goto V_10;
}
static int F_125 ( struct V_81 * V_82 ,
struct V_50 * * V_51 ,
int V_83 , const char * V_84 )
{
int V_4 ;
if ( V_82 -> V_78 && ! V_82 -> V_141 ) {
V_4 = F_28 ( V_84 , & V_82 -> V_141 ) ;
if ( V_4 != 0 ) {
F_7 ( L_157 ) ;
return V_4 ;
}
}
V_4 = F_48 ( V_82 , V_51 , V_83 , V_84 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_122 ( V_82 , V_51 , V_83 , V_84 ) ;
}
int F_126 ( struct V_81 * V_125 , int V_126 ,
int V_83 , const char * V_84 , bool V_202 )
{
int V_53 , V_203 , V_4 ;
struct V_204 * V_205 ;
V_4 = 0 ;
V_205 = F_85 ( sizeof( struct V_204 ) * V_126 ) ;
if ( V_205 == NULL )
return - V_47 ;
V_4 = F_2 ( V_125 -> V_78 ) ;
if ( V_4 < 0 ) {
free ( V_205 ) ;
return V_4 ;
}
for ( V_53 = 0 ; V_53 < V_126 ; V_53 ++ ) {
V_205 [ V_53 ] . V_82 = & V_125 [ V_53 ] ;
V_4 = F_125 ( V_205 [ V_53 ] . V_82 ,
& V_205 [ V_53 ] . V_51 ,
V_83 ,
V_84 ) ;
if ( V_4 < 0 )
goto V_109;
V_205 [ V_53 ] . V_52 = V_4 ;
}
for ( V_53 = 0 ; V_53 < V_126 ; V_53 ++ ) {
V_4 = F_120 ( V_205 [ V_53 ] . V_82 , V_205 [ V_53 ] . V_51 ,
V_205 [ V_53 ] . V_52 , V_202 ) ;
if ( V_4 < 0 )
break;
}
V_109:
for ( V_53 = 0 ; V_53 < V_126 ; V_53 ++ ) {
for ( V_203 = 0 ; V_203 < V_205 [ V_53 ] . V_52 ; V_203 ++ )
F_32 ( & V_205 [ V_53 ] . V_51 [ V_203 ] ) ;
F_51 ( & V_205 [ V_53 ] . V_51 ) ;
}
free ( V_205 ) ;
F_8 () ;
return V_4 ;
}
static int F_127 ( int V_60 , struct V_117 * V_187 )
{
char * V_159 ;
char V_46 [ 128 ] ;
int V_4 ;
V_4 = F_1 ( V_46 , 128 , L_158 , V_187 -> V_124 ) ;
if ( V_4 < 0 )
goto error;
V_159 = strchr ( V_46 + 2 , ':' ) ;
if ( ! V_159 ) {
F_4 ( L_159 ,
V_187 -> V_124 ) ;
V_4 = - V_139 ;
goto error;
}
* V_159 = '/' ;
F_4 ( L_141 , V_46 ) ;
V_4 = F_117 ( V_60 , V_46 , strlen ( V_46 ) ) ;
if ( V_4 < 0 ) {
V_4 = - V_63 ;
goto error;
}
printf ( L_160 , V_187 -> V_124 ) ;
return 0 ;
error:
F_7 ( L_161 , strerror ( - V_4 ) ) ;
return V_4 ;
}
static int F_128 ( int V_60 , const char * V_46 ,
struct V_182 * V_190 )
{
struct V_117 * V_187 , * V_206 ;
int V_4 = - 1 ;
if ( strpbrk ( V_46 , L_162 ) ) {
F_129 (ent, n, namelist)
if ( F_130 ( V_187 -> V_124 , V_46 ) ) {
V_4 = F_127 ( V_60 , V_187 ) ;
if ( V_4 < 0 )
break;
F_131 ( V_190 , V_187 ) ;
}
} else {
V_187 = F_132 ( V_190 , V_46 ) ;
if ( V_187 ) {
V_4 = F_127 ( V_60 , V_187 ) ;
if ( V_4 >= 0 )
F_131 ( V_190 , V_187 ) ;
}
}
return V_4 ;
}
int F_133 ( struct V_182 * V_207 )
{
int V_4 = - 1 , V_208 = - 1 , V_209 = - 1 ;
char V_46 [ 128 ] ;
const char * V_141 , * V_140 ;
char * V_159 , * V_1 ;
struct V_117 * V_187 ;
struct V_182 * V_190 = NULL , * V_210 = NULL ;
V_209 = F_105 ( true ) ;
if ( V_209 < 0 )
return V_209 ;
V_190 = F_115 ( V_209 , true ) ;
V_208 = F_106 ( true ) ;
if ( V_208 >= 0 )
V_210 = F_115 ( V_208 , true ) ;
if ( V_190 == NULL && V_210 == NULL )
goto error;
F_69 (ent, dellist) {
V_1 = F_29 ( V_187 -> V_124 ) ;
if ( V_1 == NULL ) {
V_4 = - V_47 ;
goto error;
}
F_4 ( L_163 , V_1 ) ;
V_159 = strchr ( V_1 , ':' ) ;
if ( V_159 ) {
V_141 = V_1 ;
* V_159 = '\0' ;
V_140 = V_159 + 1 ;
} else {
V_141 = L_164 ;
V_140 = V_1 ;
}
V_4 = F_1 ( V_46 , 128 , L_134 , V_141 , V_140 ) ;
if ( V_4 < 0 ) {
F_34 ( L_165 ) ;
free ( V_1 ) ;
goto error;
}
F_4 ( L_166 , V_141 , V_140 ) ;
if ( V_190 )
V_4 = F_128 ( V_209 , V_46 , V_190 ) ;
if ( V_210 && V_4 != 0 )
V_4 = F_128 ( V_208 , V_46 , V_210 ) ;
if ( V_4 != 0 )
F_134 ( L_167 , V_46 ) ;
free ( V_1 ) ;
}
error:
if ( V_209 >= 0 ) {
F_71 ( V_190 ) ;
F_114 ( V_209 ) ;
}
if ( V_208 >= 0 ) {
F_71 ( V_210 ) ;
F_114 ( V_208 ) ;
}
return V_4 ;
}
static int F_135 ( struct V_15 * V_15 V_127 ,
struct V_13 * V_24 )
{
if ( ( V_24 -> V_195 == V_196 || V_24 -> V_195 == V_197 ) &&
F_70 ( V_211 , V_24 -> V_14 ) )
return 0 ;
return 1 ;
}
int F_136 ( const char * V_84 , struct V_113 * V_114 ,
bool V_212 )
{
struct V_15 * V_15 ;
int V_4 ;
V_4 = F_2 ( V_212 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_212 )
V_15 = F_95 ( V_84 ) ;
else
V_15 = F_18 ( V_84 ) ;
if ( ! V_15 ) {
F_34 ( L_168 , ( V_84 ) ? : L_5 ) ;
return - V_48 ;
}
V_211 = V_114 ;
if ( F_15 ( V_15 , F_135 ) ) {
F_34 ( L_169 , ( V_84 ) ? : L_5 ) ;
goto V_109;
}
if ( ! F_137 ( V_15 -> V_36 , V_15 -> type ) )
F_138 ( V_15 -> V_36 , V_15 -> type ) ;
F_60 () ;
F_139 ( V_15 -> V_36 , V_15 -> type , stdout ) ;
V_109:
if ( V_212 ) {
F_97 ( V_15 -> V_36 ) ;
F_98 ( V_15 ) ;
}
F_8 () ;
return V_4 ;
}
