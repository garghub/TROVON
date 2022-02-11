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
static int F_2 ( void )
{
int V_4 ;
V_7 . V_8 = true ;
if ( V_7 . V_9 == NULL )
V_7 . V_10 = true ;
else
F_3 ( L_1 , V_7 . V_9 ) ;
V_4 = F_4 () ;
if ( V_4 < 0 ) {
F_3 ( L_2 ) ;
goto V_11;
}
V_4 = F_5 ( & V_12 , L_3 , V_13 ) ;
if ( V_4 < 0 )
goto V_11;
if ( F_6 ( & V_12 ) < 0 ) {
F_3 ( L_4 ) ;
goto V_11;
}
V_11:
if ( V_4 < 0 )
F_7 ( L_5 ) ;
return V_4 ;
}
static struct V_14 * F_8 ( const char * V_15 ,
struct V_16 * * V_17 )
{
return F_9 ( & V_12 , V_15 , V_17 ,
NULL ) ;
}
static struct V_16 * F_10 ( const char * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 = & V_12 . V_23 ;
if ( V_18 && strchr ( V_18 , '/' ) )
return F_11 ( & V_12 , 0 , V_18 ) ;
if ( ! V_18 )
V_18 = L_6 ;
for ( V_20 = F_12 ( & V_22 -> V_24 [ V_25 ] ) ; V_20 ; V_20 = F_13 ( V_20 ) ) {
struct V_16 * V_26 = F_14 ( V_20 , struct V_16 , V_19 ) ;
if ( strncmp ( V_26 -> V_27 -> V_28 + 1 , V_18 ,
V_26 -> V_27 -> V_29 - 2 ) == 0 ) {
return V_26 ;
}
}
return NULL ;
}
static struct V_27 * F_15 ( const char * V_18 )
{
struct V_27 * V_27 ;
struct V_16 * V_16 ;
const char * V_9 ;
if ( V_18 ) {
F_16 (dso, &machine.kernel_dsos, node) {
if ( strncmp ( V_27 -> V_28 + 1 , V_18 ,
V_27 -> V_29 - 2 ) == 0 )
goto V_30;
}
F_3 ( L_7 , V_18 ) ;
return NULL ;
}
V_16 = V_12 . V_31 [ V_25 ] ;
V_27 = V_16 -> V_27 ;
V_9 = V_7 . V_9 ;
if ( V_9 ) {
if ( F_17 ( V_27 , V_16 , V_9 , false , NULL ) <= 0 )
return NULL ;
} else {
if ( F_18 ( V_27 , V_16 , NULL ) <= 0 ) {
F_3 ( L_8 ) ;
return NULL ;
}
}
V_30:
return V_27 ;
}
const char * F_19 ( const char * V_18 )
{
struct V_27 * V_27 = F_15 ( V_18 ) ;
return ( V_27 ) ? V_27 -> V_32 : NULL ;
}
static int F_20 ( void )
{
int V_4 = 0 ;
V_7 . V_10 = false ;
V_7 . V_8 = true ;
V_4 = F_4 () ;
if ( V_4 < 0 )
F_3 ( L_2 ) ;
return V_4 ;
}
static int F_21 ( const char * V_33 , char * * V_34 )
{
char * V_35 , * V_36 , * V_37 ;
char V_38 [ 64 ] ;
int V_4 ;
V_37 = F_22 ( V_33 ) ;
if ( ! V_37 )
return - V_39 ;
V_35 = F_23 ( V_37 ) ;
if ( ! V_35 ) {
V_4 = - V_40 ;
goto V_11;
}
V_36 = strpbrk ( V_35 , L_9 ) ;
if ( V_36 )
* V_36 = '\0' ;
V_4 = F_1 ( V_38 , 64 , L_10 , V_41 , V_35 ) ;
if ( V_4 < 0 )
goto V_11;
* V_34 = F_22 ( V_38 ) ;
V_4 = * V_34 ? 0 : - V_39 ;
V_11:
free ( V_37 ) ;
return V_4 ;
}
static int F_24 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
V_45 -> V_46 = F_22 ( V_43 -> V_14 ) ;
if ( V_45 -> V_46 == NULL )
return - V_39 ;
V_45 -> V_47 = V_43 -> V_47 ;
V_45 -> V_48 = V_43 -> V_48 ;
return 0 ;
}
static struct V_49 * F_25 ( const char * V_18 )
{
const char * V_50 ;
if ( V_18 && strchr ( V_18 , '/' ) )
V_50 = V_18 ;
else {
V_50 = F_19 ( V_18 ) ;
if ( ! V_50 ) {
F_26 ( L_11 ,
V_18 ? : L_6 ) ;
return NULL ;
}
}
return F_27 ( V_50 ) ;
}
static int F_28 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_14 * V_51 ;
struct V_16 * V_16 ;
T_3 V_52 ;
int V_4 = - V_53 ;
struct V_49 * V_54 ;
V_51 = F_8 ( V_43 -> V_14 , & V_16 ) ;
if ( V_51 ) {
V_52 = V_16 -> V_55 ( V_16 , V_51 -> V_56 + V_43 -> V_47 ) ;
F_3 ( L_12 V_57 L_13 , V_43 -> V_14 ,
V_43 -> V_47 , V_52 ) ;
V_54 = F_29 ( V_52 ) ;
if ( V_54 ) {
V_4 = F_30 ( V_54 ,
( unsigned long ) V_52 , V_45 ) ;
F_31 ( V_54 ) ;
} else {
F_3 ( L_14 V_57 L_13 ,
V_52 ) ;
V_4 = - V_53 ;
}
}
if ( V_4 <= 0 ) {
F_3 ( L_15
L_16 ) ;
return F_24 ( V_43 , V_45 ) ;
}
V_45 -> V_48 = V_43 -> V_48 ;
return 0 ;
}
static int F_32 ( const char * V_33 , unsigned long * V_58 )
{
T_4 * V_59 ;
T_5 V_60 ;
T_6 V_61 ;
int V_62 , V_4 = - V_53 ;
V_62 = F_33 ( V_33 , V_63 ) ;
if ( V_62 < 0 )
return - V_64 ;
V_59 = F_34 ( V_62 , V_65 , NULL ) ;
if ( V_59 == NULL )
return - V_40 ;
if ( F_35 ( V_59 , & V_60 ) == NULL )
goto V_11;
if ( ! F_36 ( V_59 , & V_60 , & V_61 , L_17 , NULL ) )
goto V_11;
* V_58 = V_61 . V_66 - V_61 . V_67 ;
V_4 = 0 ;
V_11:
F_37 ( V_59 ) ;
return V_4 ;
}
static int F_38 ( struct V_68 * V_69 ,
int V_70 , const char * V_33 )
{
int V_71 , V_4 = 0 ;
unsigned long V_47 , V_72 = 0 ;
char V_38 [ 32 ] ;
if ( ! V_33 )
return 0 ;
V_4 = F_32 ( V_33 , & V_72 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_71 = 0 ; V_71 < V_70 && V_4 >= 0 ; V_71 ++ ) {
V_47 = V_69 [ V_71 ] . V_73 . V_58 - V_72 ;
V_69 [ V_71 ] . V_73 . V_47 = 0 ;
F_39 ( & V_69 [ V_71 ] . V_73 . V_14 ) ;
V_4 = F_1 ( V_38 , 32 , L_18 , V_47 ) ;
if ( V_4 < 0 )
break;
V_69 [ V_71 ] . V_73 . V_18 = F_22 ( V_33 ) ;
V_69 [ V_71 ] . V_73 . V_14 = F_22 ( V_38 ) ;
if ( ! V_69 [ V_71 ] . V_73 . V_14 || ! V_69 [ V_71 ] . V_73 . V_18 ) {
V_4 = - V_39 ;
break;
}
V_69 [ V_71 ] . V_74 = true ;
}
return V_4 ;
}
static int F_40 ( struct V_68 * V_69 ,
int V_70 , const char * V_18 )
{
int V_71 , V_4 = 0 ;
char * V_75 ;
if ( ! V_18 )
return 0 ;
V_75 = strrchr ( V_18 , '/' ) ;
if ( V_75 ) {
V_18 = F_22 ( V_75 + 1 ) ;
if ( ! V_18 )
return - V_39 ;
V_75 = strchr ( V_18 , '.' ) ;
if ( V_75 )
* V_75 = '\0' ;
V_75 = ( char * ) V_18 ;
}
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
V_69 [ V_71 ] . V_73 . V_18 = F_22 ( V_18 ) ;
if ( ! V_69 [ V_71 ] . V_73 . V_18 ) {
V_4 = - V_39 ;
break;
}
}
free ( V_75 ) ;
return V_4 ;
}
static void F_41 ( struct V_68 * V_69 , int V_70 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ )
F_42 ( V_69 + V_71 ) ;
}
static int F_43 ( struct V_76 * V_77 ,
struct V_68 * * V_69 ,
int V_78 , const char * V_79 )
{
bool V_80 = F_44 ( V_77 ) ;
struct V_49 * V_54 ;
int V_70 , V_4 = 0 ;
V_54 = F_25 ( V_79 ) ;
if ( ! V_54 ) {
if ( V_80 ) {
F_7 ( L_19 ) ;
return - V_53 ;
}
F_3 ( L_20 ) ;
return 0 ;
}
V_70 = F_45 ( V_54 , V_77 , V_69 , V_78 ) ;
F_31 ( V_54 ) ;
if ( V_70 > 0 ) {
F_3 ( L_21 , V_70 ) ;
if ( V_79 ) {
if ( V_77 -> V_74 )
V_4 = F_38 ( * V_69 ,
V_70 , V_79 ) ;
else
V_4 = F_40 ( * V_69 ,
V_70 , V_79 ) ;
}
if ( V_4 < 0 ) {
F_41 ( * V_69 , V_70 ) ;
F_39 ( V_69 ) ;
}
return V_4 < 0 ? V_4 : V_70 ;
}
if ( V_70 == 0 ) {
F_7 ( L_22 ,
F_46 ( & V_77 -> V_73 ) ) ;
return - V_53 ;
}
F_3 ( L_23 , V_70 ) ;
if ( V_70 == - V_81 ) {
F_7 ( L_24
L_25 ) ;
if ( ! V_80 ) {
F_3 ( L_26 ) ;
return 0 ;
}
}
return V_70 ;
}
static int F_47 ( const char * V_82 , const char * V_83 ,
char * * V_84 )
{
const char * V_85 = V_7 . V_86 ;
if ( ! V_85 ) {
if ( V_82 [ 0 ] != '/' && V_83 )
V_85 = V_83 ;
else {
if ( F_48 ( V_82 , V_87 ) == 0 ) {
* V_84 = F_22 ( V_82 ) ;
return 0 ;
} else
return - V_64 ;
}
}
* V_84 = malloc ( ( strlen ( V_85 ) + strlen ( V_82 ) + 2 ) ) ;
if ( ! * V_84 )
return - V_39 ;
for (; ; ) {
sprintf ( * V_84 , L_27 , V_85 , V_82 ) ;
if ( F_48 ( * V_84 , V_87 ) == 0 )
return 0 ;
if ( ! V_7 . V_86 )
return - V_64 ;
switch ( V_64 ) {
case V_88 :
case V_53 :
case V_89 :
case V_90 :
V_82 = strchr ( ++ V_82 , '/' ) ;
if ( ! V_82 ) {
F_39 ( V_84 ) ;
return - V_53 ;
}
continue;
default:
F_39 ( V_84 ) ;
return - V_64 ;
}
}
}
static int F_49 ( T_7 * V_91 , int V_92 , bool V_93 , bool V_94 )
{
char V_38 [ V_95 ] ;
const char * V_96 = V_94 ? L_3 : V_97 ;
const char * V_85 = NULL ;
do {
if ( fgets ( V_38 , V_95 , V_91 ) == NULL )
goto error;
if ( V_93 )
continue;
if ( ! V_85 ) {
V_85 = V_94 ? L_28 : L_29 ;
F_50 ( stdout , V_96 , V_85 , V_92 ) ;
}
F_50 ( stdout , V_96 , L_30 , V_38 ) ;
} while ( strchr ( V_38 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_91 ) ) {
F_7 ( L_31 , strerror ( V_64 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_51 ( T_7 * V_91 , int V_92 , bool V_93 , bool V_94 )
{
int V_98 = F_49 ( V_91 , V_92 , V_93 , V_94 ) ;
if ( V_98 == 0 ) {
F_7 ( L_32 ) ;
V_98 = - 1 ;
}
return V_98 ;
}
int F_52 ( struct V_99 * V_100 , const char * V_18 )
{
int V_92 = 1 ;
struct V_101 * V_102 ;
struct V_49 * V_54 ;
T_7 * V_91 ;
int V_4 ;
char * V_75 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_54 = F_25 ( V_18 ) ;
if ( ! V_54 ) {
F_7 ( L_19 ) ;
return - V_53 ;
}
V_4 = F_53 ( V_54 , V_100 ) ;
F_31 ( V_54 ) ;
if ( V_4 == 0 ) {
F_7 ( L_33 ) ;
return - V_53 ;
} else if ( V_4 < 0 ) {
F_7 ( L_34 , V_4 ) ;
return V_4 ;
}
V_75 = V_100 -> V_50 ;
V_4 = F_47 ( V_75 , V_100 -> V_83 , & V_100 -> V_50 ) ;
free ( V_75 ) ;
if ( V_4 < 0 ) {
F_7 ( L_35 , V_4 ) ;
return V_4 ;
}
F_54 () ;
if ( V_100 -> V_46 )
fprintf ( stdout , L_36 , V_100 -> V_46 , V_100 -> V_50 ,
V_100 -> V_56 - V_100 -> V_47 ) ;
else
fprintf ( stdout , L_37 , V_100 -> V_50 , V_100 -> V_56 ) ;
V_91 = fopen ( V_100 -> V_50 , L_38 ) ;
if ( V_91 == NULL ) {
F_7 ( L_39 , V_100 -> V_50 ,
strerror ( V_64 ) ) ;
return - V_64 ;
}
while ( V_92 < V_100 -> V_56 ) {
V_4 = F_55 ( V_91 , V_92 ++ ) ;
if ( V_4 < 0 )
goto V_103;
}
F_16 (ln, &lr->line_list, list) {
for (; V_102 -> line > V_92 ; V_92 ++ ) {
V_4 = F_56 ( V_91 , V_92 - V_100 -> V_47 ) ;
if ( V_4 < 0 )
goto V_103;
}
V_4 = F_57 ( V_91 , V_92 ++ - V_100 -> V_47 ) ;
if ( V_4 < 0 )
goto V_103;
}
if ( V_100 -> V_103 == V_104 )
V_100 -> V_103 = V_92 + V_105 ;
while ( V_92 <= V_100 -> V_103 ) {
V_4 = F_58 ( V_91 , V_92 ++ - V_100 -> V_47 ) ;
if ( V_4 <= 0 )
break;
}
V_103:
fclose ( V_91 ) ;
return V_4 ;
}
static int F_59 ( struct V_49 * V_54 ,
struct V_76 * V_77 ,
int V_106 , struct V_107 * V_108 ,
bool V_109 )
{
char * V_38 ;
int V_4 , V_71 , V_110 ;
struct V_111 * V_112 ;
struct V_113 * V_114 = NULL , * V_115 ;
const char * V_116 ;
V_38 = F_46 ( & V_77 -> V_73 ) ;
if ( ! V_38 )
return - V_40 ;
F_3 ( L_40 , V_38 ) ;
V_4 = F_60 ( V_54 , V_77 , & V_114 ,
V_106 , V_109 ) ;
if ( V_4 <= 0 ) {
F_26 ( L_41 , V_38 , V_4 ) ;
goto V_103;
}
fprintf ( stdout , L_42 , V_38 ) ;
for ( V_71 = 0 ; V_71 < V_4 ; V_71 ++ ) {
V_115 = & V_114 [ V_71 ] ;
fprintf ( stdout , L_43 , V_115 -> V_73 . V_14 ,
V_115 -> V_73 . V_47 ) ;
F_39 ( & V_115 -> V_73 . V_14 ) ;
V_110 = 0 ;
if ( V_115 -> V_117 ) {
F_61 (node, vl->vars) {
V_116 = strchr ( V_112 -> V_118 , '\t' ) + 1 ;
if ( F_62 ( V_108 , V_116 ) ) {
fprintf ( stdout , L_44 , V_112 -> V_118 ) ;
V_110 ++ ;
}
}
F_63 ( V_115 -> V_117 ) ;
}
if ( V_110 == 0 )
fprintf ( stdout , L_45 ) ;
}
free ( V_114 ) ;
V_103:
free ( V_38 ) ;
return V_4 ;
}
int F_64 ( struct V_76 * V_119 , int V_120 ,
int V_106 , const char * V_18 ,
struct V_107 * V_108 , bool V_109 )
{
int V_71 , V_4 = 0 ;
struct V_49 * V_54 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_54 = F_25 ( V_18 ) ;
if ( ! V_54 ) {
F_7 ( L_19 ) ;
return - V_53 ;
}
F_54 () ;
for ( V_71 = 0 ; V_71 < V_120 && V_4 >= 0 ; V_71 ++ )
V_4 = F_59 ( V_54 , & V_119 [ V_71 ] , V_106 , V_108 ,
V_109 ) ;
F_31 ( V_54 ) ;
return V_4 ;
}
static int F_28 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_14 * V_51 ;
V_51 = F_8 ( V_43 -> V_14 , NULL ) ;
if ( ! V_51 ) {
F_26 ( L_46 , V_43 -> V_14 ) ;
return - V_53 ;
}
return F_24 ( V_43 , V_45 ) ;
}
static int F_43 ( struct V_76 * V_77 ,
struct V_68 * * V_69 V_121 ,
int V_78 V_121 ,
const char * V_79 V_121 )
{
if ( F_44 ( V_77 ) ) {
F_7 ( L_47 ) ;
return - V_122 ;
}
return 0 ;
}
int F_52 ( struct V_99 * V_100 V_121 ,
const char * V_18 V_121 )
{
F_7 ( L_47 ) ;
return - V_122 ;
}
int F_64 ( struct V_76 * V_119 V_121 ,
int V_120 V_121 , int V_106 V_121 ,
const char * V_18 V_121 ,
struct V_107 * T_8 V_121 ,
bool V_109 V_121 )
{
F_7 ( L_47 ) ;
return - V_122 ;
}
void F_65 ( struct V_99 * V_100 )
{
struct V_101 * V_102 ;
free ( V_100 -> V_46 ) ;
free ( V_100 -> V_123 ) ;
free ( V_100 -> V_50 ) ;
free ( V_100 -> V_83 ) ;
while ( ! F_66 ( & V_100 -> V_124 ) ) {
V_102 = F_67 ( & V_100 -> V_124 , struct V_101 , V_125 ) ;
F_68 ( & V_102 -> V_125 ) ;
free ( V_102 ) ;
}
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
}
void F_69 ( struct V_99 * V_100 )
{
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
F_70 ( & V_100 -> V_124 ) ;
}
static int F_71 ( char * * V_126 , int * V_127 , const char * V_128 )
{
const char * V_56 = * V_126 ;
V_64 = 0 ;
* V_127 = strtol ( * V_126 , V_126 , 0 ) ;
if ( V_64 || * V_126 == V_56 ) {
F_72 ( L_48 , V_128 ) ;
return - V_40 ;
}
return 0 ;
}
int F_73 ( const char * V_129 , struct V_99 * V_100 )
{
char * V_130 , * V_123 , * V_15 = F_22 ( V_129 ) ;
int V_131 ;
if ( ! V_15 )
return - V_39 ;
V_100 -> V_56 = 0 ;
V_100 -> V_103 = V_104 ;
V_130 = strchr ( V_15 , ':' ) ;
if ( V_130 ) {
* V_130 ++ = '\0' ;
V_131 = F_71 ( & V_130 , & V_100 -> V_56 , L_49 ) ;
if ( V_131 )
goto V_131;
if ( * V_130 == '+' || * V_130 == '-' ) {
const char V_132 = * V_130 ++ ;
V_131 = F_71 ( & V_130 , & V_100 -> V_103 , L_50 ) ;
if ( V_131 )
goto V_131;
if ( V_132 == '+' ) {
V_100 -> V_103 += V_100 -> V_56 ;
V_100 -> V_103 -- ;
}
}
F_3 ( L_51 , V_100 -> V_56 , V_100 -> V_103 ) ;
V_131 = - V_40 ;
if ( V_100 -> V_56 > V_100 -> V_103 ) {
F_72 ( L_52
L_53 ) ;
goto V_131;
}
if ( * V_130 != '\0' ) {
F_72 ( L_54 , V_130 ) ;
goto V_131;
}
}
V_123 = strchr ( V_15 , '@' ) ;
if ( V_123 ) {
* V_123 = '\0' ;
V_100 -> V_123 = F_22 ( ++ V_123 ) ;
if ( V_100 -> V_123 == NULL ) {
V_131 = - V_39 ;
goto V_131;
}
V_100 -> V_46 = V_15 ;
} else if ( strchr ( V_15 , '.' ) )
V_100 -> V_123 = V_15 ;
else
V_100 -> V_46 = V_15 ;
return 0 ;
V_131:
free ( V_15 ) ;
return V_131 ;
}
static bool F_74 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
static int F_75 ( char * V_129 , struct V_76 * V_77 )
{
struct V_44 * V_45 = & V_77 -> V_73 ;
char * V_126 , * V_75 ;
char V_132 , V_133 = 0 ;
V_126 = strpbrk ( V_129 , L_55 ) ;
if ( V_126 && * V_126 == '=' ) {
* V_126 = '\0' ;
V_75 = V_126 + 1 ;
if ( strchr ( V_129 , ':' ) ) {
F_72 ( L_56 ) ;
return - V_134 ;
}
if ( ! F_74 ( V_129 ) ) {
F_72 ( L_57
L_58 , V_129 ) ;
return - V_40 ;
}
V_77 -> V_135 = F_22 ( V_129 ) ;
if ( V_77 -> V_135 == NULL )
return - V_39 ;
V_77 -> V_136 = NULL ;
V_129 = V_75 ;
}
V_126 = strpbrk ( V_129 , L_59 ) ;
if ( V_126 ) {
V_133 = * V_126 ;
* V_126 ++ = '\0' ;
}
V_75 = F_22 ( V_129 ) ;
if ( V_75 == NULL )
return - V_39 ;
if ( strchr ( V_75 , '.' ) )
V_45 -> V_123 = V_75 ;
else
V_45 -> V_46 = V_75 ;
while ( V_126 ) {
V_129 = V_126 ;
V_132 = V_133 ;
if ( V_132 == ';' ) {
V_45 -> V_137 = F_22 ( V_129 ) ;
if ( V_45 -> V_137 == NULL )
return - V_39 ;
break;
}
V_126 = strpbrk ( V_129 , L_59 ) ;
if ( V_126 ) {
V_133 = * V_126 ;
* V_126 ++ = '\0' ;
}
switch ( V_132 ) {
case ':' :
V_45 -> line = strtoul ( V_129 , & V_75 , 0 ) ;
if ( * V_75 != '\0' ) {
F_72 ( L_60
L_61 ) ;
return - V_40 ;
}
break;
case '+' :
V_45 -> V_47 = strtoul ( V_129 , & V_75 , 0 ) ;
if ( * V_75 != '\0' ) {
F_72 ( L_62
L_63 ) ;
return - V_40 ;
}
break;
case '@' :
if ( V_45 -> V_123 ) {
F_72 ( L_64 ) ;
return - V_40 ;
}
V_45 -> V_123 = F_22 ( V_129 ) ;
if ( V_45 -> V_123 == NULL )
return - V_39 ;
break;
case '%' :
if ( strcmp ( V_129 , L_65 ) == 0 ) {
V_45 -> V_48 = 1 ;
} else {
F_72 ( L_66 , V_129 ) ;
return - V_134 ;
}
break;
default:
F_26 ( L_67 ,
__FILE__ , __LINE__ ) ;
return - V_134 ;
break;
}
}
if ( V_45 -> V_137 && V_45 -> line ) {
F_72 ( L_68
L_69 ) ;
return - V_40 ;
}
if ( V_45 -> V_137 && V_45 -> V_47 ) {
F_72 ( L_70 ) ;
return - V_40 ;
}
if ( V_45 -> line && V_45 -> V_47 ) {
F_72 ( L_71 ) ;
return - V_40 ;
}
if ( ! V_45 -> line && ! V_45 -> V_137 && V_45 -> V_123 && ! V_45 -> V_46 ) {
F_72 ( L_72
L_73 ) ;
return - V_40 ;
}
if ( V_45 -> V_47 && ! V_45 -> V_46 ) {
F_72 ( L_74 ) ;
return - V_40 ;
}
if ( V_45 -> V_48 && ! V_45 -> V_46 ) {
F_72 ( L_75 ) ;
return - V_40 ;
}
if ( ( V_45 -> V_47 || V_45 -> line || V_45 -> V_137 ) && V_45 -> V_48 ) {
F_72 ( L_76
L_77 ) ;
return - V_40 ;
}
F_3 ( L_78 ,
V_45 -> V_46 , V_45 -> V_123 , V_45 -> line , V_45 -> V_47 , V_45 -> V_48 ,
V_45 -> V_137 ) ;
return 0 ;
}
static int F_76 ( char * V_1 , struct V_138 * V_129 )
{
char * V_75 , * V_139 ;
struct V_140 * * V_141 ;
F_3 ( L_79 , V_1 ) ;
V_75 = strchr ( V_1 , '=' ) ;
if ( V_75 ) {
V_129 -> V_15 = F_77 ( V_1 , V_75 - V_1 ) ;
if ( V_129 -> V_15 == NULL )
return - V_39 ;
F_3 ( L_80 , V_129 -> V_15 ) ;
V_1 = V_75 + 1 ;
}
V_75 = strchr ( V_1 , ':' ) ;
if ( V_75 ) {
* V_75 = '\0' ;
V_129 -> type = F_22 ( V_75 + 1 ) ;
if ( V_129 -> type == NULL )
return - V_39 ;
F_3 ( L_81 , V_129 -> type ) ;
}
V_75 = strpbrk ( V_1 , L_82 ) ;
if ( ! F_78 ( V_1 ) || ! V_75 ) {
V_129 -> V_116 = F_22 ( V_1 ) ;
if ( V_129 -> V_116 == NULL )
return - V_39 ;
F_3 ( L_83 , V_129 -> V_116 ) ;
return 0 ;
}
V_129 -> V_116 = F_77 ( V_1 , V_75 - V_1 ) ;
if ( V_129 -> V_116 == NULL )
return - V_39 ;
V_139 = V_129 -> V_116 ;
F_3 ( L_84 , V_129 -> V_116 ) ;
V_141 = & V_129 -> V_142 ;
do {
* V_141 = F_79 ( sizeof( struct V_140 ) ) ;
if ( * V_141 == NULL )
return - V_39 ;
if ( * V_75 == '[' ) {
V_1 = V_75 ;
( * V_141 ) -> V_143 = strtol ( V_1 + 1 , & V_75 , 0 ) ;
( * V_141 ) -> V_144 = true ;
if ( * V_75 != ']' || V_75 == V_1 + 1 ) {
F_72 ( L_85
L_86 ) ;
return - V_40 ;
}
V_75 ++ ;
if ( * V_75 == '\0' )
V_75 = NULL ;
} else {
if ( * V_75 == '.' ) {
V_1 = V_75 + 1 ;
( * V_141 ) -> V_144 = false ;
} else if ( V_75 [ 1 ] == '>' ) {
V_1 = V_75 + 2 ;
( * V_141 ) -> V_144 = true ;
} else {
F_72 ( L_87 ,
V_1 ) ;
return - V_40 ;
}
V_75 = strpbrk ( V_1 , L_82 ) ;
}
if ( V_75 ) {
( * V_141 ) -> V_15 = F_77 ( V_1 , V_75 - V_1 ) ;
if ( ( * V_141 ) -> V_15 == NULL )
return - V_39 ;
if ( * V_1 != '[' )
V_139 = ( * V_141 ) -> V_15 ;
F_3 ( L_88 , ( * V_141 ) -> V_15 , ( * V_141 ) -> V_144 ) ;
V_141 = & ( * V_141 ) -> V_145 ;
}
} while ( V_75 );
( * V_141 ) -> V_15 = F_22 ( V_1 ) ;
if ( ( * V_141 ) -> V_15 == NULL )
return - V_39 ;
if ( * V_1 != '[' )
V_139 = ( * V_141 ) -> V_15 ;
F_3 ( L_89 , ( * V_141 ) -> V_15 , ( * V_141 ) -> V_144 ) ;
if ( ! V_129 -> V_15 ) {
V_129 -> V_15 = F_22 ( V_139 ) ;
if ( V_129 -> V_15 == NULL )
return - V_39 ;
}
return 0 ;
}
int F_80 ( const char * V_146 , struct V_76 * V_77 )
{
char * * V_147 ;
int V_148 , V_71 , V_4 = 0 ;
V_147 = F_81 ( V_146 , & V_148 ) ;
if ( ! V_147 ) {
F_3 ( L_90 ) ;
return - V_39 ;
}
if ( V_148 - 1 > V_149 ) {
F_72 ( L_91 , V_148 - 1 ) ;
V_4 = - V_150 ;
goto V_11;
}
V_4 = F_75 ( V_147 [ 0 ] , V_77 ) ;
if ( V_4 < 0 )
goto V_11;
V_77 -> V_151 = V_148 - 1 ;
V_77 -> args = F_79 ( sizeof( struct V_138 ) * V_77 -> V_151 ) ;
if ( V_77 -> args == NULL ) {
V_4 = - V_39 ;
goto V_11;
}
for ( V_71 = 0 ; V_71 < V_77 -> V_151 && V_4 >= 0 ; V_71 ++ ) {
V_4 = F_76 ( V_147 [ V_71 + 1 ] , & V_77 -> args [ V_71 ] ) ;
if ( V_4 >= 0 &&
F_78 ( V_77 -> args [ V_71 ] . V_116 ) && V_77 -> V_73 . V_48 ) {
F_72 ( L_92
L_93 ) ;
V_4 = - V_40 ;
}
}
V_11:
F_82 ( V_147 ) ;
return V_4 ;
}
bool F_44 ( struct V_76 * V_77 )
{
int V_71 ;
if ( V_77 -> V_73 . V_123 || V_77 -> V_73 . line || V_77 -> V_73 . V_137 )
return true ;
for ( V_71 = 0 ; V_71 < V_77 -> V_151 ; V_71 ++ )
if ( F_78 ( V_77 -> args [ V_71 ] . V_116 ) )
return true ;
return false ;
}
static int F_83 ( const char * V_146 ,
struct V_68 * V_152 )
{
struct V_42 * V_43 = & V_152 -> V_73 ;
char V_153 ;
char * V_154 ;
char * V_155 = NULL , * V_156 , * V_157 , * V_158 , * V_159 ;
int V_4 , V_71 , V_148 ;
char * * V_147 ;
F_3 ( L_94 , V_146 ) ;
V_147 = F_81 ( V_146 , & V_148 ) ;
if ( ! V_147 ) {
F_3 ( L_90 ) ;
return - V_39 ;
}
if ( V_148 < 2 ) {
F_72 ( L_95 ) ;
V_4 = - V_150 ;
goto V_11;
}
V_155 = F_22 ( V_147 [ 0 ] ) ;
if ( V_155 == NULL ) {
V_4 = - V_39 ;
goto V_11;
}
V_157 = strtok_r ( V_155 , L_96 , & V_156 ) ;
V_158 = strtok_r ( NULL , L_97 , & V_156 ) ;
V_159 = strtok_r ( NULL , L_98 , & V_156 ) ;
if ( V_157 == NULL || strlen ( V_157 ) != 1 || V_158 == NULL
|| V_159 == NULL ) {
F_72 ( L_99 , V_147 [ 0 ] ) ;
V_4 = - V_40 ;
goto V_11;
}
V_153 = V_157 [ 0 ] ;
V_152 -> V_136 = F_22 ( V_158 ) ;
V_152 -> V_135 = F_22 ( V_159 ) ;
if ( V_152 -> V_136 == NULL || V_152 -> V_135 == NULL ) {
V_4 = - V_39 ;
goto V_11;
}
F_3 ( L_100 , V_152 -> V_136 , V_152 -> V_135 , V_153 ) ;
V_43 -> V_48 = ( V_153 == 'r' ) ;
V_154 = strchr ( V_147 [ 1 ] , ':' ) ;
if ( V_154 ) {
V_43 -> V_18 = F_77 ( V_147 [ 1 ] , V_154 - V_147 [ 1 ] ) ;
V_154 ++ ;
} else
V_154 = V_147 [ 1 ] ;
V_157 = strtok_r ( V_154 , L_101 , & V_156 ) ;
V_43 -> V_14 = F_22 ( V_157 ) ;
if ( V_43 -> V_14 == NULL ) {
V_4 = - V_39 ;
goto V_11;
}
V_158 = strtok_r ( NULL , L_3 , & V_156 ) ;
if ( V_158 == NULL )
V_43 -> V_47 = 0 ;
else
V_43 -> V_47 = strtoul ( V_158 , NULL , 10 ) ;
V_152 -> V_151 = V_148 - 2 ;
V_152 -> args = F_79 ( sizeof( struct V_160 ) * V_152 -> V_151 ) ;
if ( V_152 -> args == NULL ) {
V_4 = - V_39 ;
goto V_11;
}
for ( V_71 = 0 ; V_71 < V_152 -> V_151 ; V_71 ++ ) {
V_154 = strchr ( V_147 [ V_71 + 2 ] , '=' ) ;
if ( V_154 )
* V_154 ++ = '\0' ;
else
V_154 = V_147 [ V_71 + 2 ] ;
V_152 -> args [ V_71 ] . V_15 = F_22 ( V_147 [ V_71 + 2 ] ) ;
V_152 -> args [ V_71 ] . V_161 = F_22 ( V_154 ) ;
if ( V_152 -> args [ V_71 ] . V_15 == NULL || V_152 -> args [ V_71 ] . V_161 == NULL ) {
V_4 = - V_39 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
free ( V_155 ) ;
F_82 ( V_147 ) ;
return V_4 ;
}
int F_84 ( struct V_138 * V_162 , char * V_38 , T_1 V_163 )
{
struct V_140 * V_142 = V_162 -> V_142 ;
int V_4 ;
char * V_75 = V_38 ;
if ( V_162 -> V_15 && V_162 -> V_116 )
V_4 = F_1 ( V_75 , V_163 , L_102 , V_162 -> V_15 , V_162 -> V_116 ) ;
else
V_4 = F_1 ( V_75 , V_163 , L_30 , V_162 -> V_15 ? V_162 -> V_15 : V_162 -> V_116 ) ;
if ( V_4 <= 0 )
goto error;
V_75 += V_4 ;
V_163 -= V_4 ;
while ( V_142 ) {
if ( V_142 -> V_15 [ 0 ] == '[' )
V_4 = F_1 ( V_75 , V_163 , L_30 , V_142 -> V_15 ) ;
else
V_4 = F_1 ( V_75 , V_163 , L_103 ,
V_142 -> V_144 ? L_104 : L_105 , V_142 -> V_15 ) ;
if ( V_4 <= 0 )
goto error;
V_75 += V_4 ;
V_163 -= V_4 ;
V_142 = V_142 -> V_145 ;
}
if ( V_162 -> type ) {
V_4 = F_1 ( V_75 , V_163 , L_106 , V_162 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_75 += V_4 ;
V_163 -= V_4 ;
}
return V_75 - V_38 ;
error:
F_3 ( L_107 ,
strerror ( - V_4 ) ) ;
return V_4 ;
}
static char * F_46 ( struct V_44 * V_45 )
{
char * V_38 , * V_75 ;
char V_164 [ 32 ] = L_3 , line [ 32 ] = L_3 , V_123 [ 32 ] = L_3 ;
int V_4 , V_163 ;
V_38 = F_79 ( V_165 ) ;
if ( V_38 == NULL ) {
V_4 = - V_39 ;
goto error;
}
if ( V_45 -> V_47 ) {
V_4 = F_1 ( V_164 , 32 , L_108 , V_45 -> V_47 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_45 -> line ) {
V_4 = F_1 ( line , 32 , L_109 , V_45 -> line ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_45 -> V_123 ) {
V_75 = V_45 -> V_123 ;
V_163 = strlen ( V_75 ) ;
if ( V_163 > 30 ) {
V_75 = strchr ( V_45 -> V_123 + V_163 - 30 , '/' ) ;
V_75 = V_75 ? V_75 + 1 : V_45 -> V_123 + V_163 - 30 ;
}
V_4 = F_1 ( V_123 , 32 , L_110 , V_75 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_45 -> V_46 )
V_4 = F_1 ( V_38 , V_165 , L_111 , V_45 -> V_46 ,
V_164 , V_45 -> V_48 ? L_112 : L_3 , line ,
V_123 ) ;
else
V_4 = F_1 ( V_38 , V_165 , L_103 , V_123 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_38 ;
error:
F_3 ( L_113 ,
strerror ( - V_4 ) ) ;
free ( V_38 ) ;
return NULL ;
}
static int F_85 ( struct V_166 * V_144 ,
char * * V_38 , T_1 * V_167 ,
int V_168 )
{
int V_4 ;
if ( V_144 -> V_145 ) {
V_168 = F_85 ( V_144 -> V_145 , V_38 ,
V_167 , V_168 + 1 ) ;
if ( V_168 < 0 )
goto V_11;
}
V_4 = F_1 ( * V_38 , * V_167 , L_114 , V_144 -> V_47 ) ;
if ( V_4 < 0 )
V_168 = V_4 ;
else {
* V_38 += V_4 ;
* V_167 -= V_4 ;
}
V_11:
return V_168 ;
}
static int F_86 ( struct V_160 * V_129 ,
char * V_38 , T_1 V_167 )
{
struct V_166 * V_144 = V_129 -> V_144 ;
int V_4 , V_168 = 0 ;
char * V_75 = V_38 ;
if ( V_129 -> V_15 )
V_4 = F_1 ( V_38 , V_167 , L_115 , V_129 -> V_15 ) ;
else
V_4 = F_1 ( V_38 , V_167 , L_116 ) ;
if ( V_4 < 0 )
return V_4 ;
V_38 += V_4 ;
V_167 -= V_4 ;
if ( V_129 -> V_161 [ 0 ] == '@' && V_129 -> V_144 )
V_144 = V_144 -> V_145 ;
if ( V_144 ) {
V_168 = F_85 ( V_144 , & V_38 ,
& V_167 , 1 ) ;
if ( V_168 < 0 )
return V_168 ;
}
if ( V_129 -> V_161 [ 0 ] == '@' && V_129 -> V_144 )
V_4 = F_1 ( V_38 , V_167 , L_117 , V_129 -> V_161 ,
V_129 -> V_144 -> V_47 ) ;
else
V_4 = F_1 ( V_38 , V_167 , L_30 , V_129 -> V_161 ) ;
if ( V_4 < 0 )
return V_4 ;
V_38 += V_4 ;
V_167 -= V_4 ;
while ( V_168 -- ) {
V_4 = F_1 ( V_38 , V_167 , L_118 ) ;
if ( V_4 < 0 )
return V_4 ;
V_38 += V_4 ;
V_167 -= V_4 ;
}
if ( V_129 -> type ) {
V_4 = F_1 ( V_38 , V_167 , L_106 , V_129 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_38 += V_4 ;
}
return V_38 - V_75 ;
}
char * F_87 ( struct V_68 * V_152 )
{
struct V_42 * V_43 = & V_152 -> V_73 ;
char * V_38 ;
int V_71 , V_163 , V_4 ;
V_38 = F_79 ( V_165 ) ;
if ( V_38 == NULL )
return NULL ;
if ( V_152 -> V_74 )
V_163 = F_1 ( V_38 , V_165 , L_119 ,
V_43 -> V_48 ? 'r' : 'p' ,
V_152 -> V_136 , V_152 -> V_135 ,
V_43 -> V_18 , V_43 -> V_14 ) ;
else
V_163 = F_1 ( V_38 , V_165 , L_120 ,
V_43 -> V_48 ? 'r' : 'p' ,
V_152 -> V_136 , V_152 -> V_135 ,
V_43 -> V_18 ? : L_3 , V_43 -> V_18 ? L_96 : L_3 ,
V_43 -> V_14 , V_43 -> V_47 ) ;
if ( V_163 <= 0 )
goto error;
for ( V_71 = 0 ; V_71 < V_152 -> V_151 ; V_71 ++ ) {
V_4 = F_86 ( & V_152 -> args [ V_71 ] , V_38 + V_163 ,
V_165 - V_163 ) ;
if ( V_4 <= 0 )
goto error;
V_163 += V_4 ;
}
return V_38 ;
error:
free ( V_38 ) ;
return NULL ;
}
static int F_88 ( struct V_68 * V_152 ,
struct V_76 * V_77 , bool V_169 )
{
char V_38 [ 64 ] = L_3 ;
int V_71 , V_4 ;
V_77 -> V_135 = F_22 ( V_152 -> V_135 ) ;
V_77 -> V_136 = F_22 ( V_152 -> V_136 ) ;
if ( V_77 -> V_135 == NULL || V_77 -> V_136 == NULL )
return - V_39 ;
if ( V_169 )
V_4 = F_28 ( & V_152 -> V_73 , & V_77 -> V_73 ) ;
else
V_4 = F_24 ( & V_152 -> V_73 , & V_77 -> V_73 ) ;
if ( V_4 < 0 )
return V_4 ;
V_77 -> V_151 = V_152 -> V_151 ;
V_77 -> args = F_79 ( sizeof( struct V_138 ) * V_77 -> V_151 ) ;
if ( V_77 -> args == NULL )
return - V_39 ;
for ( V_71 = 0 ; V_71 < V_152 -> V_151 && V_4 >= 0 ; V_71 ++ ) {
if ( V_152 -> args [ V_71 ] . V_15 )
V_77 -> args [ V_71 ] . V_15 = F_22 ( V_152 -> args [ V_71 ] . V_15 ) ;
else {
V_4 = F_86 ( & V_152 -> args [ V_71 ] ,
V_38 , 64 ) ;
V_77 -> args [ V_71 ] . V_15 = F_22 ( V_38 ) ;
}
if ( V_77 -> args [ V_71 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_39 ;
}
if ( V_4 < 0 )
F_89 ( V_77 ) ;
return V_4 ;
}
void F_89 ( struct V_76 * V_77 )
{
struct V_44 * V_45 = & V_77 -> V_73 ;
struct V_140 * V_142 , * V_145 ;
int V_71 ;
free ( V_77 -> V_135 ) ;
free ( V_77 -> V_136 ) ;
free ( V_45 -> V_123 ) ;
free ( V_45 -> V_46 ) ;
free ( V_45 -> V_137 ) ;
for ( V_71 = 0 ; V_71 < V_77 -> V_151 ; V_71 ++ ) {
free ( V_77 -> args [ V_71 ] . V_15 ) ;
free ( V_77 -> args [ V_71 ] . V_116 ) ;
free ( V_77 -> args [ V_71 ] . type ) ;
V_142 = V_77 -> args [ V_71 ] . V_142 ;
while ( V_142 ) {
V_145 = V_142 -> V_145 ;
F_39 ( & V_142 -> V_15 ) ;
free ( V_142 ) ;
V_142 = V_145 ;
}
}
free ( V_77 -> args ) ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
}
static void F_42 ( struct V_68 * V_152 )
{
struct V_166 * V_144 , * V_145 ;
int V_71 ;
free ( V_152 -> V_135 ) ;
free ( V_152 -> V_136 ) ;
free ( V_152 -> V_73 . V_14 ) ;
free ( V_152 -> V_73 . V_18 ) ;
for ( V_71 = 0 ; V_71 < V_152 -> V_151 ; V_71 ++ ) {
free ( V_152 -> args [ V_71 ] . V_15 ) ;
free ( V_152 -> args [ V_71 ] . V_161 ) ;
free ( V_152 -> args [ V_71 ] . type ) ;
V_144 = V_152 -> args [ V_71 ] . V_144 ;
while ( V_144 ) {
V_145 = V_144 -> V_145 ;
free ( V_144 ) ;
V_144 = V_145 ;
}
}
free ( V_152 -> args ) ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
}
static void F_90 ( const char * V_123 , bool V_169 )
{
if ( V_64 == V_53 ) {
const char * V_170 ;
if ( ! V_169 )
V_170 = L_121 ;
else
V_170 = L_122 ;
F_7 ( L_123
L_124 , V_123 , V_170 ) ;
} else
F_7 ( L_125 , V_123 ,
strerror ( V_64 ) ) ;
}
static int F_91 ( const char * V_171 , bool V_172 ,
bool V_169 )
{
char V_38 [ V_173 ] ;
const char * V_174 ;
int V_4 ;
V_174 = F_92 () ;
if ( V_174 == NULL ) {
F_7 ( L_126 ) ;
return - V_53 ;
}
V_4 = F_1 ( V_38 , V_173 , L_27 , V_174 , V_171 ) ;
if ( V_4 >= 0 ) {
F_3 ( L_127 , V_38 , V_172 ) ;
if ( V_172 && ! V_175 )
V_4 = F_33 ( V_38 , V_176 , V_177 ) ;
else
V_4 = F_33 ( V_38 , V_63 , 0 ) ;
if ( V_4 < 0 )
F_90 ( V_38 , V_169 ) ;
}
return V_4 ;
}
static int F_93 ( bool V_172 )
{
return F_91 ( L_128 , V_172 , true ) ;
}
static int F_94 ( bool V_172 )
{
return F_91 ( L_129 , V_172 , false ) ;
}
static struct V_178 * F_95 ( int V_62 )
{
int V_4 , V_179 ;
T_7 * V_91 ;
char V_38 [ V_165 ] ;
char * V_154 ;
struct V_178 * V_180 ;
V_180 = F_96 ( true , NULL ) ;
V_91 = fdopen ( F_97 ( V_62 ) , L_38 ) ;
while ( ! feof ( V_91 ) ) {
V_154 = fgets ( V_38 , V_165 , V_91 ) ;
if ( ! V_154 )
break;
V_179 = strlen ( V_154 ) - 1 ;
if ( V_154 [ V_179 ] == '\n' )
V_154 [ V_179 ] = '\0' ;
V_4 = F_98 ( V_180 , V_38 ) ;
if ( V_4 < 0 ) {
F_3 ( L_130 , strerror ( - V_4 ) ) ;
F_63 ( V_180 ) ;
return NULL ;
}
}
fclose ( V_91 ) ;
return V_180 ;
}
static int F_99 ( struct V_76 * V_77 )
{
int V_71 , V_4 ;
char V_38 [ 128 ] ;
char * V_181 ;
V_181 = F_46 ( & V_77 -> V_73 ) ;
if ( ! V_181 )
return - V_40 ;
V_4 = F_1 ( V_38 , 128 , L_131 , V_77 -> V_136 , V_77 -> V_135 ) ;
if ( V_4 < 0 )
return V_4 ;
printf ( L_132 , V_38 , V_181 ) ;
if ( V_77 -> V_151 > 0 ) {
printf ( L_133 ) ;
for ( V_71 = 0 ; V_71 < V_77 -> V_151 ; V_71 ++ ) {
V_4 = F_84 ( & V_77 -> args [ V_71 ] ,
V_38 , 128 ) ;
if ( V_4 < 0 )
break;
printf ( L_134 , V_38 ) ;
}
}
printf ( L_135 ) ;
free ( V_181 ) ;
return V_4 ;
}
static int F_100 ( int V_62 , bool V_169 )
{
int V_4 = 0 ;
struct V_68 V_152 ;
struct V_76 V_77 ;
struct V_178 * V_182 ;
struct V_111 * V_183 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_182 = F_95 ( V_62 ) ;
if ( ! V_182 )
return - V_53 ;
F_61 (ent, rawlist) {
V_4 = F_83 ( V_183 -> V_118 , & V_152 ) ;
if ( V_4 >= 0 ) {
V_4 = F_88 ( & V_152 , & V_77 ,
V_169 ) ;
if ( V_4 >= 0 )
V_4 = F_99 ( & V_77 ) ;
}
F_89 ( & V_77 ) ;
F_42 ( & V_152 ) ;
if ( V_4 < 0 )
break;
}
F_63 ( V_182 ) ;
return V_4 ;
}
int F_101 ( void )
{
int V_62 , V_4 ;
F_54 () ;
V_62 = F_93 ( false ) ;
if ( V_62 < 0 )
return V_62 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_100 ( V_62 , true ) ;
F_102 ( V_62 ) ;
V_62 = F_94 ( false ) ;
if ( V_62 >= 0 ) {
V_4 = F_100 ( V_62 , false ) ;
F_102 ( V_62 ) ;
}
return V_4 ;
}
static struct V_178 * F_103 ( int V_62 , bool V_184 )
{
char V_38 [ 128 ] ;
struct V_178 * V_180 , * V_182 ;
struct V_111 * V_183 ;
struct V_68 V_152 ;
int V_4 = 0 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_182 = F_95 ( V_62 ) ;
V_180 = F_96 ( true , NULL ) ;
F_61 (ent, rawlist) {
V_4 = F_83 ( V_183 -> V_118 , & V_152 ) ;
if ( V_4 < 0 )
break;
if ( V_184 ) {
V_4 = F_1 ( V_38 , 128 , L_131 , V_152 . V_136 ,
V_152 . V_135 ) ;
if ( V_4 >= 0 )
V_4 = F_98 ( V_180 , V_38 ) ;
} else
V_4 = F_98 ( V_180 , V_152 . V_135 ) ;
F_42 ( & V_152 ) ;
if ( V_4 < 0 )
break;
}
F_63 ( V_182 ) ;
if ( V_4 < 0 ) {
F_63 ( V_180 ) ;
return NULL ;
}
return V_180 ;
}
static int F_104 ( int V_62 , struct V_68 * V_152 )
{
int V_4 = 0 ;
char * V_38 = F_87 ( V_152 ) ;
if ( ! V_38 ) {
F_3 ( L_136 ) ;
return - V_40 ;
}
F_3 ( L_137 , V_38 ) ;
if ( ! V_175 ) {
V_4 = F_105 ( V_62 , V_38 , strlen ( V_38 ) ) ;
if ( V_4 <= 0 )
F_7 ( L_138 ,
strerror ( V_64 ) ) ;
}
free ( V_38 ) ;
return V_4 ;
}
static int F_106 ( char * V_38 , T_1 V_163 , const char * V_185 ,
struct V_178 * V_186 , bool V_187 )
{
int V_71 , V_4 ;
V_4 = F_1 ( V_38 , V_163 , L_30 , V_185 ) ;
if ( V_4 < 0 ) {
F_3 ( L_139 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_107 ( V_186 , V_38 ) )
return 0 ;
if ( ! V_187 ) {
F_7 ( L_140
L_141 , V_185 ) ;
return - V_188 ;
}
for ( V_71 = 1 ; V_71 < V_189 ; V_71 ++ ) {
V_4 = F_1 ( V_38 , V_163 , L_142 , V_185 , V_71 ) ;
if ( V_4 < 0 ) {
F_3 ( L_139 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_107 ( V_186 , V_38 ) )
break;
}
if ( V_71 == V_189 ) {
F_7 ( L_143 ) ;
V_4 = - V_150 ;
}
return V_4 ;
}
static int F_108 ( struct V_76 * V_77 ,
struct V_68 * V_69 ,
int V_70 , bool V_187 )
{
int V_71 , V_62 , V_4 ;
struct V_68 * V_152 = NULL ;
char V_38 [ 64 ] ;
const char * V_135 , * V_136 ;
struct V_178 * V_186 ;
if ( V_77 -> V_74 )
V_62 = F_94 ( true ) ;
else
V_62 = F_93 ( true ) ;
if ( V_62 < 0 )
return V_62 ;
V_186 = F_103 ( V_62 , false ) ;
if ( ! V_186 ) {
F_3 ( L_144 ) ;
return - V_190 ;
}
V_4 = 0 ;
printf ( L_145 , ( V_70 > 1 ) ? L_146 : L_96 ) ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
V_152 = & V_69 [ V_71 ] ;
if ( V_77 -> V_135 )
V_135 = V_77 -> V_135 ;
else
if ( V_77 -> V_73 . V_46 )
V_135 = V_77 -> V_73 . V_46 ;
else
V_135 = V_152 -> V_73 . V_14 ;
if ( V_77 -> V_136 )
V_136 = V_77 -> V_136 ;
else
V_136 = V_41 ;
V_4 = F_106 ( V_38 , 64 , V_135 ,
V_186 , V_187 ) ;
if ( V_4 < 0 )
break;
V_135 = V_38 ;
V_152 -> V_135 = F_22 ( V_135 ) ;
V_152 -> V_136 = F_22 ( V_136 ) ;
if ( V_152 -> V_135 == NULL || V_152 -> V_136 == NULL ) {
V_4 = - V_39 ;
break;
}
V_4 = F_104 ( V_62 , V_152 ) ;
if ( V_4 < 0 )
break;
F_98 ( V_186 , V_135 ) ;
V_135 = V_77 -> V_135 ;
V_136 = V_77 -> V_136 ;
V_77 -> V_135 = V_152 -> V_135 ;
V_77 -> V_136 = V_152 -> V_136 ;
F_99 ( V_77 ) ;
V_77 -> V_135 = ( char * ) V_135 ;
V_77 -> V_136 = ( char * ) V_136 ;
V_187 = true ;
}
if ( V_4 >= 0 ) {
printf ( L_147 ) ;
printf ( L_148 , V_152 -> V_136 ,
V_152 -> V_135 ) ;
}
F_63 ( V_186 ) ;
F_102 ( V_62 ) ;
return V_4 ;
}
static int F_109 ( struct V_76 * V_77 ,
struct V_68 * * V_69 ,
int V_78 , const char * V_79 )
{
struct V_14 * V_51 ;
int V_4 , V_71 ;
struct V_68 * V_152 ;
if ( V_77 -> V_74 && ! V_77 -> V_136 ) {
V_4 = F_21 ( V_79 , & V_77 -> V_136 ) ;
if ( V_4 != 0 ) {
F_7 ( L_149 ) ;
return V_4 ;
}
}
V_4 = F_43 ( V_77 , V_69 , V_78 , V_79 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_77 -> V_74 ) {
V_4 = F_110 ( V_77 , V_79 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_152 = * V_69 = F_79 ( sizeof( struct V_68 ) ) ;
if ( V_152 == NULL )
return - V_39 ;
V_152 -> V_73 . V_14 = F_22 ( V_77 -> V_73 . V_46 ) ;
if ( V_152 -> V_73 . V_14 == NULL ) {
V_4 = - V_39 ;
goto error;
}
if ( V_79 ) {
V_152 -> V_73 . V_18 = F_22 ( V_79 ) ;
if ( V_152 -> V_73 . V_18 == NULL ) {
V_4 = - V_39 ;
goto error;
}
}
V_152 -> V_73 . V_47 = V_77 -> V_73 . V_47 ;
V_152 -> V_73 . V_48 = V_77 -> V_73 . V_48 ;
V_152 -> V_151 = V_77 -> V_151 ;
V_152 -> V_74 = V_77 -> V_74 ;
if ( V_152 -> V_151 ) {
V_152 -> args = F_79 ( sizeof( struct V_160 )
* V_152 -> V_151 ) ;
if ( V_152 -> args == NULL ) {
V_4 = - V_39 ;
goto error;
}
for ( V_71 = 0 ; V_71 < V_152 -> V_151 ; V_71 ++ ) {
if ( V_77 -> args [ V_71 ] . V_15 ) {
V_152 -> args [ V_71 ] . V_15 = F_22 ( V_77 -> args [ V_71 ] . V_15 ) ;
if ( V_152 -> args [ V_71 ] . V_15 == NULL ) {
V_4 = - V_39 ;
goto error;
}
}
V_152 -> args [ V_71 ] . V_161 = F_22 ( V_77 -> args [ V_71 ] . V_116 ) ;
if ( V_152 -> args [ V_71 ] . V_161 == NULL ) {
V_4 = - V_39 ;
goto error;
}
if ( V_77 -> args [ V_71 ] . type ) {
V_152 -> args [ V_71 ] . type = F_22 ( V_77 -> args [ V_71 ] . type ) ;
if ( V_152 -> args [ V_71 ] . type == NULL ) {
V_4 = - V_39 ;
goto error;
}
}
}
}
if ( V_77 -> V_74 )
return 1 ;
V_51 = F_8 ( V_152 -> V_73 . V_14 , NULL ) ;
if ( ! V_51 ) {
F_7 ( L_150 ,
V_152 -> V_73 . V_14 ) ;
V_4 = - V_53 ;
goto error;
} else if ( V_152 -> V_73 . V_47 > V_51 -> V_103 - V_51 -> V_56 ) {
F_7 ( L_151 ,
V_152 -> V_73 . V_14 ) ;
V_4 = - V_53 ;
goto error;
}
return 1 ;
error:
F_42 ( V_152 ) ;
free ( V_152 ) ;
* V_69 = NULL ;
return V_4 ;
}
int F_111 ( struct V_76 * V_119 , int V_120 ,
int V_78 , const char * V_79 , bool V_191 )
{
int V_71 , V_192 , V_4 ;
struct V_193 * V_194 ;
V_4 = 0 ;
V_194 = F_79 ( sizeof( struct V_193 ) * V_120 ) ;
if ( V_194 == NULL )
return - V_39 ;
if ( ! V_119 -> V_74 )
V_4 = F_2 () ;
else
V_4 = F_20 () ;
if ( V_4 < 0 ) {
free ( V_194 ) ;
return V_4 ;
}
for ( V_71 = 0 ; V_71 < V_120 ; V_71 ++ ) {
V_194 [ V_71 ] . V_77 = & V_119 [ V_71 ] ;
V_4 = F_109 ( V_194 [ V_71 ] . V_77 ,
& V_194 [ V_71 ] . V_69 ,
V_78 ,
V_79 ) ;
if ( V_4 < 0 )
goto V_103;
V_194 [ V_71 ] . V_70 = V_4 ;
}
for ( V_71 = 0 ; V_71 < V_120 ; V_71 ++ ) {
V_4 = F_108 ( V_194 [ V_71 ] . V_77 , V_194 [ V_71 ] . V_69 ,
V_194 [ V_71 ] . V_70 , V_191 ) ;
if ( V_4 < 0 )
break;
}
V_103:
for ( V_71 = 0 ; V_71 < V_120 ; V_71 ++ ) {
for ( V_192 = 0 ; V_192 < V_194 [ V_71 ] . V_70 ; V_192 ++ )
F_42 ( & V_194 [ V_71 ] . V_69 [ V_192 ] ) ;
F_39 ( & V_194 [ V_71 ] . V_69 ) ;
}
free ( V_194 ) ;
return V_4 ;
}
static int F_112 ( int V_62 , struct V_111 * V_183 )
{
char * V_154 ;
char V_38 [ 128 ] ;
int V_4 ;
V_4 = F_1 ( V_38 , 128 , L_152 , V_183 -> V_118 ) ;
if ( V_4 < 0 )
goto error;
V_154 = strchr ( V_38 + 2 , ':' ) ;
if ( ! V_154 ) {
F_3 ( L_153 ,
V_183 -> V_118 ) ;
V_4 = - V_134 ;
goto error;
}
* V_154 = '/' ;
F_3 ( L_137 , V_38 ) ;
V_4 = F_105 ( V_62 , V_38 , strlen ( V_38 ) ) ;
if ( V_4 < 0 ) {
V_4 = - V_64 ;
goto error;
}
printf ( L_154 , V_183 -> V_118 ) ;
return 0 ;
error:
F_7 ( L_155 , strerror ( - V_4 ) ) ;
return V_4 ;
}
static int F_113 ( int V_62 , const char * V_38 ,
struct V_178 * V_186 )
{
struct V_111 * V_183 , * V_195 ;
int V_4 = - 1 ;
if ( strpbrk ( V_38 , L_156 ) ) {
F_114 (ent, n, namelist)
if ( F_115 ( V_183 -> V_118 , V_38 ) ) {
V_4 = F_112 ( V_62 , V_183 ) ;
if ( V_4 < 0 )
break;
F_116 ( V_186 , V_183 ) ;
}
} else {
V_183 = F_117 ( V_186 , V_38 ) ;
if ( V_183 ) {
V_4 = F_112 ( V_62 , V_183 ) ;
if ( V_4 >= 0 )
F_116 ( V_186 , V_183 ) ;
}
}
return V_4 ;
}
int F_118 ( struct V_178 * V_196 )
{
int V_4 = - 1 , V_197 = - 1 , V_198 = - 1 ;
char V_38 [ 128 ] ;
const char * V_136 , * V_135 ;
char * V_154 , * V_1 ;
struct V_111 * V_183 ;
struct V_178 * V_186 = NULL , * V_199 = NULL ;
V_198 = F_93 ( true ) ;
if ( V_198 < 0 )
return V_198 ;
V_186 = F_103 ( V_198 , true ) ;
V_197 = F_94 ( true ) ;
if ( V_197 >= 0 )
V_199 = F_103 ( V_197 , true ) ;
if ( V_186 == NULL && V_199 == NULL )
goto error;
F_61 (ent, dellist) {
V_1 = F_22 ( V_183 -> V_118 ) ;
if ( V_1 == NULL ) {
V_4 = - V_39 ;
goto error;
}
F_3 ( L_157 , V_1 ) ;
V_154 = strchr ( V_1 , ':' ) ;
if ( V_154 ) {
V_136 = V_1 ;
* V_154 = '\0' ;
V_135 = V_154 + 1 ;
} else {
V_136 = L_158 ;
V_135 = V_1 ;
}
V_4 = F_1 ( V_38 , 128 , L_131 , V_136 , V_135 ) ;
if ( V_4 < 0 ) {
F_26 ( L_159 ) ;
free ( V_1 ) ;
goto error;
}
F_3 ( L_160 , V_136 , V_135 ) ;
if ( V_186 )
V_4 = F_113 ( V_198 , V_38 , V_186 ) ;
if ( V_199 && V_4 != 0 )
V_4 = F_113 ( V_197 , V_38 , V_199 ) ;
if ( V_4 != 0 )
F_119 ( L_161 , V_38 ) ;
free ( V_1 ) ;
}
error:
if ( V_198 >= 0 ) {
F_63 ( V_186 ) ;
F_102 ( V_198 ) ;
}
if ( V_197 >= 0 ) {
F_63 ( V_199 ) ;
F_102 ( V_197 ) ;
}
return V_4 ;
}
static int F_120 ( struct V_16 * V_16 V_121 ,
struct V_14 * V_51 )
{
if ( V_51 -> V_200 == V_201 &&
F_62 ( V_202 , V_51 -> V_15 ) )
return 0 ;
return 1 ;
}
static int F_121 ( struct V_16 * V_16 )
{
if ( F_122 ( V_16 , F_120 ) ) {
F_26 ( L_162 ) ;
return - V_40 ;
}
if ( ! F_123 ( V_16 -> V_27 , V_16 -> type ) )
F_124 ( V_16 -> V_27 , V_16 -> type ) ;
F_125 ( V_16 -> V_27 , V_16 -> type , stdout ) ;
return 0 ;
}
static int F_126 ( const char * V_18 )
{
struct V_16 * V_16 ;
int V_4 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_16 = F_10 ( V_18 ) ;
if ( ! V_16 ) {
F_26 ( L_163 , ( V_18 ) ? : L_6 ) ;
return - V_40 ;
}
return F_121 ( V_16 ) ;
}
static int F_127 ( const char * V_79 )
{
struct V_16 * V_16 ;
int V_4 ;
V_4 = F_20 () ;
if ( V_4 < 0 )
return V_4 ;
V_16 = F_128 ( V_79 ) ;
V_4 = F_121 ( V_16 ) ;
F_129 ( V_16 -> V_27 ) ;
F_130 ( V_16 ) ;
return V_4 ;
}
int F_131 ( const char * V_79 , struct V_107 * V_108 ,
bool V_203 )
{
F_54 () ;
V_202 = V_108 ;
if ( ! V_203 )
return F_126 ( V_79 ) ;
return F_127 ( V_79 ) ;
}
static int F_110 ( struct V_76 * V_77 , const char * V_33 )
{
struct V_44 * V_45 = & V_77 -> V_73 ;
struct V_14 * V_51 ;
struct V_16 * V_16 = NULL ;
char * V_46 = NULL ;
int V_4 = - V_40 ;
unsigned long long V_204 = 0 ;
if ( ! V_45 -> V_46 ) {
F_7 ( L_164 ) ;
goto V_11;
}
V_46 = F_22 ( V_45 -> V_46 ) ;
if ( ! V_46 ) {
F_7 ( L_165 ) ;
V_4 = - V_39 ;
goto V_11;
}
V_16 = F_128 ( V_33 ) ;
if ( ! V_16 ) {
F_7 ( L_166 , V_33 ) ;
goto V_11;
}
V_202 = F_132 ( V_46 , NULL ) ;
if ( F_122 ( V_16 , F_120 ) ) {
F_26 ( L_162 ) ;
goto V_11;
}
V_51 = F_133 ( V_16 , V_46 , NULL ) ;
if ( ! V_51 ) {
F_7 ( L_167 , V_46 , V_33 ) ;
goto V_11;
}
if ( V_16 -> V_56 > V_51 -> V_56 )
V_204 = V_16 -> V_56 ;
V_204 += V_51 -> V_56 + V_45 -> V_47 + V_16 -> V_205 ;
V_45 -> V_47 = 0 ;
if ( ! V_77 -> V_135 ) {
V_77 -> V_135 = V_46 ;
V_46 = NULL ;
}
if ( ! V_77 -> V_136 ) {
char * V_35 , * V_36 , * V_37 ;
V_77 -> V_136 = F_79 ( sizeof( char * ) * 64 ) ;
V_37 = F_22 ( V_33 ) ;
if ( ! V_37 ) {
V_4 = - V_39 ;
F_7 ( L_168 ) ;
goto V_11;
}
V_35 = F_22 ( F_23 ( V_37 ) ) ;
if ( V_35 ) {
V_36 = strpbrk ( V_35 , L_9 ) ;
if ( V_36 )
* V_36 = '\0' ;
F_1 ( V_77 -> V_136 , 64 , L_10 , V_41 ,
V_35 ) ;
free ( V_35 ) ;
}
free ( V_37 ) ;
}
free ( V_45 -> V_46 ) ;
V_45 -> V_46 = F_79 ( sizeof( char * ) * V_149 ) ;
if ( ! V_45 -> V_46 ) {
V_4 = - V_39 ;
F_7 ( L_169 ) ;
goto V_11;
}
F_1 ( V_45 -> V_46 , V_149 , L_170 , V_204 ) ;
V_4 = 0 ;
V_11:
if ( V_16 ) {
F_129 ( V_16 -> V_27 ) ;
F_130 ( V_16 ) ;
}
if ( V_46 )
free ( V_46 ) ;
return V_4 ;
}
