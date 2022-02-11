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
if ( F_17 ( V_27 , V_16 , V_9 , NULL ) <= 0 )
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
static struct V_33 * F_20 ( const char * V_18 )
{
const char * V_34 ;
if ( V_18 && strchr ( V_18 , '/' ) )
V_34 = V_18 ;
else {
V_34 = F_19 ( V_18 ) ;
if ( ! V_34 ) {
F_21 ( L_9 ,
V_18 ? : L_6 ) ;
return NULL ;
}
}
return F_22 ( V_34 ) ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_14 * V_39 ;
struct V_16 * V_16 ;
T_3 V_40 ;
int V_4 = - V_41 ;
struct V_33 * V_42 ;
V_39 = F_8 ( V_36 -> V_14 , & V_16 ) ;
if ( V_39 ) {
V_40 = V_16 -> V_43 ( V_16 , V_39 -> V_44 + V_36 -> V_45 ) ;
F_3 ( L_10 V_46 L_11 , V_36 -> V_14 ,
V_36 -> V_45 , V_40 ) ;
V_42 = F_24 ( V_40 ) ;
if ( V_42 ) {
V_4 = F_25 ( V_42 ,
( unsigned long ) V_40 , V_38 ) ;
F_26 ( V_42 ) ;
} else {
F_3 ( L_12 V_46 L_11 ,
V_40 ) ;
V_4 = - V_41 ;
}
}
if ( V_4 <= 0 ) {
F_3 ( L_13
L_14 ) ;
V_38 -> V_47 = F_27 ( V_36 -> V_14 ) ;
if ( V_38 -> V_47 == NULL )
return - V_48 ;
V_38 -> V_45 = V_36 -> V_45 ;
}
V_38 -> V_49 = V_36 -> V_49 ;
return 0 ;
}
static int F_28 ( struct V_50 * V_51 ,
int V_52 , const char * V_18 )
{
int V_53 , V_4 = 0 ;
char * V_54 ;
if ( ! V_18 )
return 0 ;
V_54 = strrchr ( V_18 , '/' ) ;
if ( V_54 ) {
V_18 = F_27 ( V_54 + 1 ) ;
if ( ! V_18 )
return - V_48 ;
V_54 = strchr ( V_18 , '.' ) ;
if ( V_54 )
* V_54 = '\0' ;
V_54 = ( char * ) V_18 ;
}
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_51 [ V_53 ] . V_55 . V_18 = F_27 ( V_18 ) ;
if ( ! V_51 [ V_53 ] . V_55 . V_18 ) {
V_4 = - V_48 ;
break;
}
}
if ( V_54 )
free ( V_54 ) ;
return V_4 ;
}
static int F_29 ( struct V_56 * V_57 ,
struct V_50 * * V_51 ,
int V_58 , const char * V_59 )
{
bool V_60 = F_30 ( V_57 ) ;
struct V_33 * V_42 = F_20 ( V_59 ) ;
int V_52 , V_4 = 0 ;
if ( ! V_42 ) {
if ( V_60 ) {
F_7 ( L_15 ) ;
return - V_41 ;
}
F_3 ( L_16 ) ;
return 0 ;
}
V_52 = F_31 ( V_42 , V_57 , V_51 , V_58 ) ;
F_26 ( V_42 ) ;
if ( V_52 > 0 ) {
F_3 ( L_17 , V_52 ) ;
if ( V_59 )
V_4 = F_28 ( * V_51 , V_52 ,
V_59 ) ;
return V_4 < 0 ? V_4 : V_52 ;
}
if ( V_52 == 0 ) {
F_7 ( L_18 ,
F_32 ( & V_57 -> V_55 ) ) ;
return - V_41 ;
}
F_3 ( L_19 , V_52 ) ;
if ( V_52 == - V_61 ) {
F_7 ( L_20
L_21 ) ;
if ( ! V_60 ) {
F_3 ( L_22 ) ;
return 0 ;
}
}
return V_52 ;
}
static int F_33 ( const char * V_62 , const char * V_63 ,
char * * V_64 )
{
const char * V_65 = V_7 . V_66 ;
if ( ! V_65 ) {
if ( V_62 [ 0 ] != '/' && V_63 )
V_65 = V_63 ;
else {
if ( F_34 ( V_62 , V_67 ) == 0 ) {
* V_64 = F_27 ( V_62 ) ;
return 0 ;
} else
return - V_68 ;
}
}
* V_64 = malloc ( ( strlen ( V_65 ) + strlen ( V_62 ) + 2 ) ) ;
if ( ! * V_64 )
return - V_48 ;
for (; ; ) {
sprintf ( * V_64 , L_23 , V_65 , V_62 ) ;
if ( F_34 ( * V_64 , V_67 ) == 0 )
return 0 ;
if ( ! V_7 . V_66 )
return - V_68 ;
switch ( V_68 ) {
case V_69 :
case V_41 :
case V_70 :
case V_71 :
V_62 = strchr ( ++ V_62 , '/' ) ;
if ( ! V_62 ) {
free ( * V_64 ) ;
* V_64 = NULL ;
return - V_41 ;
}
continue;
default:
free ( * V_64 ) ;
* V_64 = NULL ;
return - V_68 ;
}
}
}
static int F_35 ( T_4 * V_72 , int V_73 , bool V_74 , bool V_75 )
{
char V_76 [ V_77 ] ;
const char * V_78 = V_75 ? L_3 : V_79 ;
const char * V_65 = NULL ;
do {
if ( fgets ( V_76 , V_77 , V_72 ) == NULL )
goto error;
if ( V_74 )
continue;
if ( ! V_65 ) {
V_65 = V_75 ? L_24 : L_25 ;
F_36 ( stdout , V_78 , V_65 , V_73 ) ;
}
F_36 ( stdout , V_78 , L_26 , V_76 ) ;
} while ( strchr ( V_76 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_72 ) ) {
F_7 ( L_27 , strerror ( V_68 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_37 ( T_4 * V_72 , int V_73 , bool V_74 , bool V_75 )
{
int V_80 = F_35 ( V_72 , V_73 , V_74 , V_75 ) ;
if ( V_80 == 0 ) {
F_7 ( L_28 ) ;
V_80 = - 1 ;
}
return V_80 ;
}
int F_38 ( struct V_81 * V_82 , const char * V_18 )
{
int V_73 = 1 ;
struct V_83 * V_84 ;
struct V_33 * V_42 ;
T_4 * V_72 ;
int V_4 ;
char * V_54 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_42 = F_20 ( V_18 ) ;
if ( ! V_42 ) {
F_7 ( L_15 ) ;
return - V_41 ;
}
V_4 = F_39 ( V_42 , V_82 ) ;
F_26 ( V_42 ) ;
if ( V_4 == 0 ) {
F_7 ( L_29 ) ;
return - V_41 ;
} else if ( V_4 < 0 ) {
F_7 ( L_30 , V_4 ) ;
return V_4 ;
}
V_54 = V_82 -> V_34 ;
V_4 = F_33 ( V_54 , V_82 -> V_63 , & V_82 -> V_34 ) ;
free ( V_54 ) ;
if ( V_4 < 0 ) {
F_7 ( L_31 , V_4 ) ;
return V_4 ;
}
F_40 () ;
if ( V_82 -> V_47 )
fprintf ( stdout , L_32 , V_82 -> V_47 , V_82 -> V_34 ,
V_82 -> V_44 - V_82 -> V_45 ) ;
else
fprintf ( stdout , L_33 , V_82 -> V_34 , V_82 -> V_44 ) ;
V_72 = fopen ( V_82 -> V_34 , L_34 ) ;
if ( V_72 == NULL ) {
F_7 ( L_35 , V_82 -> V_34 ,
strerror ( V_68 ) ) ;
return - V_68 ;
}
while ( V_73 < V_82 -> V_44 ) {
V_4 = F_41 ( V_72 , V_73 ++ ) ;
if ( V_4 < 0 )
goto V_85;
}
F_16 (ln, &lr->line_list, list) {
for (; V_84 -> line > V_73 ; V_73 ++ ) {
V_4 = F_42 ( V_72 , V_73 - V_82 -> V_45 ) ;
if ( V_4 < 0 )
goto V_85;
}
V_4 = F_43 ( V_72 , V_73 ++ - V_82 -> V_45 ) ;
if ( V_4 < 0 )
goto V_85;
}
if ( V_82 -> V_85 == V_86 )
V_82 -> V_85 = V_73 + V_87 ;
while ( V_73 <= V_82 -> V_85 ) {
V_4 = F_44 ( V_72 , V_73 ++ - V_82 -> V_45 ) ;
if ( V_4 <= 0 )
break;
}
V_85:
fclose ( V_72 ) ;
return V_4 ;
}
static int F_45 ( struct V_33 * V_42 ,
struct V_56 * V_57 ,
int V_88 , struct V_89 * V_90 ,
bool V_91 )
{
char * V_76 ;
int V_4 , V_53 , V_92 ;
struct V_93 * V_94 ;
struct V_95 * V_96 = NULL , * V_97 ;
const char * V_98 ;
V_76 = F_32 ( & V_57 -> V_55 ) ;
if ( ! V_76 )
return - V_99 ;
F_3 ( L_36 , V_76 ) ;
V_4 = F_46 ( V_42 , V_57 , & V_96 ,
V_88 , V_91 ) ;
if ( V_4 <= 0 ) {
F_21 ( L_37 , V_76 , V_4 ) ;
goto V_85;
}
fprintf ( stdout , L_38 , V_76 ) ;
for ( V_53 = 0 ; V_53 < V_4 ; V_53 ++ ) {
V_97 = & V_96 [ V_53 ] ;
fprintf ( stdout , L_39 , V_97 -> V_55 . V_14 ,
V_97 -> V_55 . V_45 ) ;
free ( V_97 -> V_55 . V_14 ) ;
V_92 = 0 ;
if ( V_97 -> V_100 ) {
F_47 (node, vl->vars) {
V_98 = strchr ( V_94 -> V_101 , '\t' ) + 1 ;
if ( F_48 ( V_90 , V_98 ) ) {
fprintf ( stdout , L_40 , V_94 -> V_101 ) ;
V_92 ++ ;
}
}
F_49 ( V_97 -> V_100 ) ;
}
if ( V_92 == 0 )
fprintf ( stdout , L_41 ) ;
}
free ( V_96 ) ;
V_85:
free ( V_76 ) ;
return V_4 ;
}
int F_50 ( struct V_56 * V_102 , int V_103 ,
int V_88 , const char * V_18 ,
struct V_89 * V_90 , bool V_91 )
{
int V_53 , V_4 = 0 ;
struct V_33 * V_42 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_42 = F_20 ( V_18 ) ;
if ( ! V_42 ) {
F_7 ( L_15 ) ;
return - V_41 ;
}
F_40 () ;
for ( V_53 = 0 ; V_53 < V_103 && V_4 >= 0 ; V_53 ++ )
V_4 = F_45 ( V_42 , & V_102 [ V_53 ] , V_88 , V_90 ,
V_91 ) ;
F_26 ( V_42 ) ;
return V_4 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_14 * V_39 ;
V_39 = F_8 ( V_36 -> V_14 , NULL ) ;
if ( ! V_39 ) {
F_21 ( L_42 , V_36 -> V_14 ) ;
return - V_41 ;
}
V_38 -> V_47 = F_27 ( V_36 -> V_14 ) ;
if ( V_38 -> V_47 == NULL )
return - V_48 ;
V_38 -> V_45 = V_36 -> V_45 ;
V_38 -> V_49 = V_36 -> V_49 ;
return 0 ;
}
static int F_29 ( struct V_56 * V_57 ,
struct V_50 * * V_51 V_104 ,
int V_58 V_104 , const char * T_5 V_104 )
{
if ( F_30 ( V_57 ) ) {
F_7 ( L_43 ) ;
return - V_105 ;
}
return 0 ;
}
int F_38 ( struct V_81 * V_82 V_104 , const char * V_18 V_104 )
{
F_7 ( L_43 ) ;
return - V_105 ;
}
int F_50 ( struct V_56 * V_102 V_104 ,
int V_103 V_104 , int V_88 V_104 ,
const char * V_18 V_104 ,
struct V_89 * T_6 V_104 ,
bool V_91 V_104 )
{
F_7 ( L_43 ) ;
return - V_105 ;
}
static int F_51 ( char * * V_106 , int * V_107 , const char * V_108 )
{
const char * V_44 = * V_106 ;
V_68 = 0 ;
* V_107 = strtol ( * V_106 , V_106 , 0 ) ;
if ( V_68 || * V_106 == V_44 ) {
F_52 ( L_44 , V_108 ) ;
return - V_99 ;
}
return 0 ;
}
int F_53 ( const char * V_109 , struct V_81 * V_82 )
{
char * V_110 , * V_111 , * V_15 = F_27 ( V_109 ) ;
int V_112 ;
if ( ! V_15 )
return - V_48 ;
V_82 -> V_44 = 0 ;
V_82 -> V_85 = V_86 ;
V_110 = strchr ( V_15 , ':' ) ;
if ( V_110 ) {
* V_110 ++ = '\0' ;
V_112 = F_51 ( & V_110 , & V_82 -> V_44 , L_45 ) ;
if ( V_112 )
goto V_112;
if ( * V_110 == '+' || * V_110 == '-' ) {
const char V_113 = * V_110 ++ ;
V_112 = F_51 ( & V_110 , & V_82 -> V_85 , L_46 ) ;
if ( V_112 )
goto V_112;
if ( V_113 == '+' ) {
V_82 -> V_85 += V_82 -> V_44 ;
V_82 -> V_85 -- ;
}
}
F_3 ( L_47 , V_82 -> V_44 , V_82 -> V_85 ) ;
V_112 = - V_99 ;
if ( V_82 -> V_44 > V_82 -> V_85 ) {
F_52 ( L_48
L_49 ) ;
goto V_112;
}
if ( * V_110 != '\0' ) {
F_52 ( L_50 , V_110 ) ;
goto V_112;
}
}
V_111 = strchr ( V_15 , '@' ) ;
if ( V_111 ) {
* V_111 = '\0' ;
V_82 -> V_111 = F_27 ( ++ V_111 ) ;
if ( V_82 -> V_111 == NULL ) {
V_112 = - V_48 ;
goto V_112;
}
V_82 -> V_47 = V_15 ;
} else if ( strchr ( V_15 , '.' ) )
V_82 -> V_111 = V_15 ;
else
V_82 -> V_47 = V_15 ;
return 0 ;
V_112:
free ( V_15 ) ;
return V_112 ;
}
static bool F_54 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
static int F_55 ( char * V_109 , struct V_56 * V_57 )
{
struct V_37 * V_38 = & V_57 -> V_55 ;
char * V_106 , * V_54 ;
char V_113 , V_114 = 0 ;
V_106 = strpbrk ( V_109 , L_51 ) ;
if ( V_106 && * V_106 == '=' ) {
* V_106 = '\0' ;
V_54 = V_106 + 1 ;
if ( strchr ( V_109 , ':' ) ) {
F_52 ( L_52 ) ;
return - V_115 ;
}
if ( ! F_54 ( V_109 ) ) {
F_52 ( L_53
L_54 , V_109 ) ;
return - V_99 ;
}
V_57 -> V_116 = F_27 ( V_109 ) ;
if ( V_57 -> V_116 == NULL )
return - V_48 ;
V_57 -> V_117 = NULL ;
V_109 = V_54 ;
}
V_106 = strpbrk ( V_109 , L_55 ) ;
if ( V_106 ) {
V_114 = * V_106 ;
* V_106 ++ = '\0' ;
}
V_54 = F_27 ( V_109 ) ;
if ( V_54 == NULL )
return - V_48 ;
if ( strchr ( V_54 , '.' ) )
V_38 -> V_111 = V_54 ;
else
V_38 -> V_47 = V_54 ;
while ( V_106 ) {
V_109 = V_106 ;
V_113 = V_114 ;
if ( V_113 == ';' ) {
V_38 -> V_118 = F_27 ( V_109 ) ;
if ( V_38 -> V_118 == NULL )
return - V_48 ;
break;
}
V_106 = strpbrk ( V_109 , L_55 ) ;
if ( V_106 ) {
V_114 = * V_106 ;
* V_106 ++ = '\0' ;
}
switch ( V_113 ) {
case ':' :
V_38 -> line = strtoul ( V_109 , & V_54 , 0 ) ;
if ( * V_54 != '\0' ) {
F_52 ( L_56
L_57 ) ;
return - V_99 ;
}
break;
case '+' :
V_38 -> V_45 = strtoul ( V_109 , & V_54 , 0 ) ;
if ( * V_54 != '\0' ) {
F_52 ( L_58
L_59 ) ;
return - V_99 ;
}
break;
case '@' :
if ( V_38 -> V_111 ) {
F_52 ( L_60 ) ;
return - V_99 ;
}
V_38 -> V_111 = F_27 ( V_109 ) ;
if ( V_38 -> V_111 == NULL )
return - V_48 ;
break;
case '%' :
if ( strcmp ( V_109 , L_61 ) == 0 ) {
V_38 -> V_49 = 1 ;
} else {
F_52 ( L_62 , V_109 ) ;
return - V_115 ;
}
break;
default:
F_21 ( L_63 ,
__FILE__ , __LINE__ ) ;
return - V_115 ;
break;
}
}
if ( V_38 -> V_118 && V_38 -> line ) {
F_52 ( L_64
L_65 ) ;
return - V_99 ;
}
if ( V_38 -> V_118 && V_38 -> V_45 ) {
F_52 ( L_66 ) ;
return - V_99 ;
}
if ( V_38 -> line && V_38 -> V_45 ) {
F_52 ( L_67 ) ;
return - V_99 ;
}
if ( ! V_38 -> line && ! V_38 -> V_118 && V_38 -> V_111 && ! V_38 -> V_47 ) {
F_52 ( L_68
L_69 ) ;
return - V_99 ;
}
if ( V_38 -> V_45 && ! V_38 -> V_47 ) {
F_52 ( L_70 ) ;
return - V_99 ;
}
if ( V_38 -> V_49 && ! V_38 -> V_47 ) {
F_52 ( L_71 ) ;
return - V_99 ;
}
if ( ( V_38 -> V_45 || V_38 -> line || V_38 -> V_118 ) && V_38 -> V_49 ) {
F_52 ( L_72
L_73 ) ;
return - V_99 ;
}
F_3 ( L_74 ,
V_38 -> V_47 , V_38 -> V_111 , V_38 -> line , V_38 -> V_45 , V_38 -> V_49 ,
V_38 -> V_118 ) ;
return 0 ;
}
static int F_56 ( char * V_1 , struct V_119 * V_109 )
{
char * V_54 , * V_120 ;
struct V_121 * * V_122 ;
F_3 ( L_75 , V_1 ) ;
V_54 = strchr ( V_1 , '=' ) ;
if ( V_54 ) {
V_109 -> V_15 = F_57 ( V_1 , V_54 - V_1 ) ;
if ( V_109 -> V_15 == NULL )
return - V_48 ;
F_3 ( L_76 , V_109 -> V_15 ) ;
V_1 = V_54 + 1 ;
}
V_54 = strchr ( V_1 , ':' ) ;
if ( V_54 ) {
* V_54 = '\0' ;
V_109 -> type = F_27 ( V_54 + 1 ) ;
if ( V_109 -> type == NULL )
return - V_48 ;
F_3 ( L_77 , V_109 -> type ) ;
}
V_54 = strpbrk ( V_1 , L_78 ) ;
if ( ! F_58 ( V_1 ) || ! V_54 ) {
V_109 -> V_98 = F_27 ( V_1 ) ;
if ( V_109 -> V_98 == NULL )
return - V_48 ;
F_3 ( L_79 , V_109 -> V_98 ) ;
return 0 ;
}
V_109 -> V_98 = F_57 ( V_1 , V_54 - V_1 ) ;
if ( V_109 -> V_98 == NULL )
return - V_48 ;
V_120 = V_109 -> V_98 ;
F_3 ( L_80 , V_109 -> V_98 ) ;
V_122 = & V_109 -> V_123 ;
do {
* V_122 = F_59 ( sizeof( struct V_121 ) ) ;
if ( * V_122 == NULL )
return - V_48 ;
if ( * V_54 == '[' ) {
V_1 = V_54 ;
( * V_122 ) -> V_124 = strtol ( V_1 + 1 , & V_54 , 0 ) ;
( * V_122 ) -> V_125 = true ;
if ( * V_54 != ']' || V_54 == V_1 + 1 ) {
F_52 ( L_81
L_82 ) ;
return - V_99 ;
}
V_54 ++ ;
if ( * V_54 == '\0' )
V_54 = NULL ;
} else {
if ( * V_54 == '.' ) {
V_1 = V_54 + 1 ;
( * V_122 ) -> V_125 = false ;
} else if ( V_54 [ 1 ] == '>' ) {
V_1 = V_54 + 2 ;
( * V_122 ) -> V_125 = true ;
} else {
F_52 ( L_83 ,
V_1 ) ;
return - V_99 ;
}
V_54 = strpbrk ( V_1 , L_78 ) ;
}
if ( V_54 ) {
( * V_122 ) -> V_15 = F_57 ( V_1 , V_54 - V_1 ) ;
if ( ( * V_122 ) -> V_15 == NULL )
return - V_48 ;
if ( * V_1 != '[' )
V_120 = ( * V_122 ) -> V_15 ;
F_3 ( L_84 , ( * V_122 ) -> V_15 , ( * V_122 ) -> V_125 ) ;
V_122 = & ( * V_122 ) -> V_126 ;
}
} while ( V_54 );
( * V_122 ) -> V_15 = F_27 ( V_1 ) ;
if ( ( * V_122 ) -> V_15 == NULL )
return - V_48 ;
if ( * V_1 != '[' )
V_120 = ( * V_122 ) -> V_15 ;
F_3 ( L_85 , ( * V_122 ) -> V_15 , ( * V_122 ) -> V_125 ) ;
if ( ! V_109 -> V_15 ) {
V_109 -> V_15 = F_27 ( V_120 ) ;
if ( V_109 -> V_15 == NULL )
return - V_48 ;
}
return 0 ;
}
int F_60 ( const char * V_127 , struct V_56 * V_57 )
{
char * * V_128 ;
int V_129 , V_53 , V_4 = 0 ;
V_128 = F_61 ( V_127 , & V_129 ) ;
if ( ! V_128 ) {
F_3 ( L_86 ) ;
return - V_48 ;
}
if ( V_129 - 1 > V_130 ) {
F_52 ( L_87 , V_129 - 1 ) ;
V_4 = - V_131 ;
goto V_11;
}
V_4 = F_55 ( V_128 [ 0 ] , V_57 ) ;
if ( V_4 < 0 )
goto V_11;
V_57 -> V_132 = V_129 - 1 ;
V_57 -> args = F_59 ( sizeof( struct V_119 ) * V_57 -> V_132 ) ;
if ( V_57 -> args == NULL ) {
V_4 = - V_48 ;
goto V_11;
}
for ( V_53 = 0 ; V_53 < V_57 -> V_132 && V_4 >= 0 ; V_53 ++ ) {
V_4 = F_56 ( V_128 [ V_53 + 1 ] , & V_57 -> args [ V_53 ] ) ;
if ( V_4 >= 0 &&
F_58 ( V_57 -> args [ V_53 ] . V_98 ) && V_57 -> V_55 . V_49 ) {
F_52 ( L_88
L_89 ) ;
V_4 = - V_99 ;
}
}
V_11:
F_62 ( V_128 ) ;
return V_4 ;
}
bool F_30 ( struct V_56 * V_57 )
{
int V_53 ;
if ( V_57 -> V_55 . V_111 || V_57 -> V_55 . line || V_57 -> V_55 . V_118 )
return true ;
for ( V_53 = 0 ; V_53 < V_57 -> V_132 ; V_53 ++ )
if ( F_58 ( V_57 -> args [ V_53 ] . V_98 ) )
return true ;
return false ;
}
static int F_63 ( const char * V_127 ,
struct V_50 * V_133 )
{
struct V_35 * V_36 = & V_133 -> V_55 ;
char V_134 ;
char * V_135 ;
int V_4 , V_53 , V_129 ;
char * * V_128 ;
F_3 ( L_90 , V_127 ) ;
V_128 = F_61 ( V_127 , & V_129 ) ;
if ( ! V_128 ) {
F_3 ( L_86 ) ;
return - V_48 ;
}
if ( V_129 < 2 ) {
F_52 ( L_91 ) ;
V_4 = - V_131 ;
goto V_11;
}
V_4 = sscanf ( V_128 [ 0 ] , L_92 ,
& V_134 , ( float * ) ( void * ) & V_133 -> V_117 ,
( float * ) ( void * ) & V_133 -> V_116 ) ;
if ( V_4 != 3 ) {
F_52 ( L_93 , V_128 [ 0 ] ) ;
V_4 = - V_99 ;
goto V_11;
}
F_3 ( L_94 , V_133 -> V_117 , V_133 -> V_116 , V_134 ) ;
V_36 -> V_49 = ( V_134 == 'r' ) ;
V_135 = strchr ( V_128 [ 1 ] , ':' ) ;
if ( V_135 ) {
V_36 -> V_18 = F_57 ( V_128 [ 1 ] , V_135 - V_128 [ 1 ] ) ;
V_135 ++ ;
} else
V_135 = V_128 [ 1 ] ;
V_4 = sscanf ( V_135 , L_95 , ( float * ) ( void * ) & V_36 -> V_14 ,
& V_36 -> V_45 ) ;
if ( V_4 == 1 )
V_36 -> V_45 = 0 ;
V_133 -> V_132 = V_129 - 2 ;
V_133 -> args = F_59 ( sizeof( struct V_136 ) * V_133 -> V_132 ) ;
if ( V_133 -> args == NULL ) {
V_4 = - V_48 ;
goto V_11;
}
for ( V_53 = 0 ; V_53 < V_133 -> V_132 ; V_53 ++ ) {
V_135 = strchr ( V_128 [ V_53 + 2 ] , '=' ) ;
if ( V_135 )
* V_135 ++ = '\0' ;
else
V_135 = V_128 [ V_53 + 2 ] ;
V_133 -> args [ V_53 ] . V_15 = F_27 ( V_128 [ V_53 + 2 ] ) ;
V_133 -> args [ V_53 ] . V_137 = F_27 ( V_135 ) ;
if ( V_133 -> args [ V_53 ] . V_15 == NULL || V_133 -> args [ V_53 ] . V_137 == NULL ) {
V_4 = - V_48 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
F_62 ( V_128 ) ;
return V_4 ;
}
int F_64 ( struct V_119 * V_138 , char * V_76 , T_1 V_139 )
{
struct V_121 * V_123 = V_138 -> V_123 ;
int V_4 ;
char * V_54 = V_76 ;
if ( V_138 -> V_15 && V_138 -> V_98 )
V_4 = F_1 ( V_54 , V_139 , L_96 , V_138 -> V_15 , V_138 -> V_98 ) ;
else
V_4 = F_1 ( V_54 , V_139 , L_26 , V_138 -> V_15 ? V_138 -> V_15 : V_138 -> V_98 ) ;
if ( V_4 <= 0 )
goto error;
V_54 += V_4 ;
V_139 -= V_4 ;
while ( V_123 ) {
if ( V_123 -> V_15 [ 0 ] == '[' )
V_4 = F_1 ( V_54 , V_139 , L_26 , V_123 -> V_15 ) ;
else
V_4 = F_1 ( V_54 , V_139 , L_97 ,
V_123 -> V_125 ? L_98 : L_99 , V_123 -> V_15 ) ;
if ( V_4 <= 0 )
goto error;
V_54 += V_4 ;
V_139 -= V_4 ;
V_123 = V_123 -> V_126 ;
}
if ( V_138 -> type ) {
V_4 = F_1 ( V_54 , V_139 , L_100 , V_138 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_54 += V_4 ;
V_139 -= V_4 ;
}
return V_54 - V_76 ;
error:
F_3 ( L_101 ,
strerror ( - V_4 ) ) ;
return V_4 ;
}
static char * F_32 ( struct V_37 * V_38 )
{
char * V_76 , * V_54 ;
char V_140 [ 32 ] = L_3 , line [ 32 ] = L_3 , V_111 [ 32 ] = L_3 ;
int V_4 , V_139 ;
V_76 = F_59 ( V_141 ) ;
if ( V_76 == NULL ) {
V_4 = - V_48 ;
goto error;
}
if ( V_38 -> V_45 ) {
V_4 = F_1 ( V_140 , 32 , L_102 , V_38 -> V_45 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_38 -> line ) {
V_4 = F_1 ( line , 32 , L_103 , V_38 -> line ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_38 -> V_111 ) {
V_54 = V_38 -> V_111 ;
V_139 = strlen ( V_54 ) ;
if ( V_139 > 30 ) {
V_54 = strchr ( V_38 -> V_111 + V_139 - 30 , '/' ) ;
V_54 = V_54 ? V_54 + 1 : V_38 -> V_111 + V_139 - 30 ;
}
V_4 = F_1 ( V_111 , 32 , L_104 , V_54 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_38 -> V_47 )
V_4 = F_1 ( V_76 , V_141 , L_105 , V_38 -> V_47 ,
V_140 , V_38 -> V_49 ? L_106 : L_3 , line ,
V_111 ) ;
else
V_4 = F_1 ( V_76 , V_141 , L_97 , V_111 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_76 ;
error:
F_3 ( L_107 ,
strerror ( - V_4 ) ) ;
if ( V_76 )
free ( V_76 ) ;
return NULL ;
}
static int F_65 ( struct V_142 * V_125 ,
char * * V_76 , T_1 * V_143 ,
int V_144 )
{
int V_4 ;
if ( V_125 -> V_126 ) {
V_144 = F_65 ( V_125 -> V_126 , V_76 ,
V_143 , V_144 + 1 ) ;
if ( V_144 < 0 )
goto V_11;
}
V_4 = F_1 ( * V_76 , * V_143 , L_108 , V_125 -> V_45 ) ;
if ( V_4 < 0 )
V_144 = V_4 ;
else {
* V_76 += V_4 ;
* V_143 -= V_4 ;
}
V_11:
return V_144 ;
}
static int F_66 ( struct V_136 * V_109 ,
char * V_76 , T_1 V_143 )
{
struct V_142 * V_125 = V_109 -> V_125 ;
int V_4 , V_144 = 0 ;
char * V_54 = V_76 ;
if ( V_109 -> V_15 )
V_4 = F_1 ( V_76 , V_143 , L_109 , V_109 -> V_15 ) ;
else
V_4 = F_1 ( V_76 , V_143 , L_110 ) ;
if ( V_4 < 0 )
return V_4 ;
V_76 += V_4 ;
V_143 -= V_4 ;
if ( V_109 -> V_137 [ 0 ] == '@' && V_109 -> V_125 )
V_125 = V_125 -> V_126 ;
if ( V_125 ) {
V_144 = F_65 ( V_125 , & V_76 ,
& V_143 , 1 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_109 -> V_137 [ 0 ] == '@' && V_109 -> V_125 )
V_4 = F_1 ( V_76 , V_143 , L_111 , V_109 -> V_137 ,
V_109 -> V_125 -> V_45 ) ;
else
V_4 = F_1 ( V_76 , V_143 , L_26 , V_109 -> V_137 ) ;
if ( V_4 < 0 )
return V_4 ;
V_76 += V_4 ;
V_143 -= V_4 ;
while ( V_144 -- ) {
V_4 = F_1 ( V_76 , V_143 , L_112 ) ;
if ( V_4 < 0 )
return V_4 ;
V_76 += V_4 ;
V_143 -= V_4 ;
}
if ( V_109 -> type ) {
V_4 = F_1 ( V_76 , V_143 , L_100 , V_109 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_76 += V_4 ;
}
return V_76 - V_54 ;
}
char * F_67 ( struct V_50 * V_133 )
{
struct V_35 * V_36 = & V_133 -> V_55 ;
char * V_76 ;
int V_53 , V_139 , V_4 ;
V_76 = F_59 ( V_141 ) ;
if ( V_76 == NULL )
return NULL ;
V_139 = F_1 ( V_76 , V_141 , L_113 ,
V_36 -> V_49 ? 'r' : 'p' ,
V_133 -> V_117 , V_133 -> V_116 ,
V_36 -> V_18 ? : L_3 , V_36 -> V_18 ? L_114 : L_3 ,
V_36 -> V_14 , V_36 -> V_45 ) ;
if ( V_139 <= 0 )
goto error;
for ( V_53 = 0 ; V_53 < V_133 -> V_132 ; V_53 ++ ) {
V_4 = F_66 ( & V_133 -> args [ V_53 ] , V_76 + V_139 ,
V_141 - V_139 ) ;
if ( V_4 <= 0 )
goto error;
V_139 += V_4 ;
}
return V_76 ;
error:
free ( V_76 ) ;
return NULL ;
}
static int F_68 ( struct V_50 * V_133 ,
struct V_56 * V_57 )
{
char V_76 [ 64 ] = L_3 ;
int V_53 , V_4 ;
V_57 -> V_116 = F_27 ( V_133 -> V_116 ) ;
V_57 -> V_117 = F_27 ( V_133 -> V_117 ) ;
if ( V_57 -> V_116 == NULL || V_57 -> V_117 == NULL )
return - V_48 ;
V_4 = F_23 ( & V_133 -> V_55 , & V_57 -> V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
V_57 -> V_132 = V_133 -> V_132 ;
V_57 -> args = F_59 ( sizeof( struct V_119 ) * V_57 -> V_132 ) ;
if ( V_57 -> args == NULL )
return - V_48 ;
for ( V_53 = 0 ; V_53 < V_133 -> V_132 && V_4 >= 0 ; V_53 ++ ) {
if ( V_133 -> args [ V_53 ] . V_15 )
V_57 -> args [ V_53 ] . V_15 = F_27 ( V_133 -> args [ V_53 ] . V_15 ) ;
else {
V_4 = F_66 ( & V_133 -> args [ V_53 ] ,
V_76 , 64 ) ;
V_57 -> args [ V_53 ] . V_15 = F_27 ( V_76 ) ;
}
if ( V_57 -> args [ V_53 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_48 ;
}
if ( V_4 < 0 )
F_69 ( V_57 ) ;
return V_4 ;
}
void F_69 ( struct V_56 * V_57 )
{
struct V_37 * V_38 = & V_57 -> V_55 ;
struct V_121 * V_123 , * V_126 ;
int V_53 ;
if ( V_57 -> V_116 )
free ( V_57 -> V_116 ) ;
if ( V_57 -> V_117 )
free ( V_57 -> V_117 ) ;
if ( V_38 -> V_111 )
free ( V_38 -> V_111 ) ;
if ( V_38 -> V_47 )
free ( V_38 -> V_47 ) ;
if ( V_38 -> V_118 )
free ( V_38 -> V_118 ) ;
for ( V_53 = 0 ; V_53 < V_57 -> V_132 ; V_53 ++ ) {
if ( V_57 -> args [ V_53 ] . V_15 )
free ( V_57 -> args [ V_53 ] . V_15 ) ;
if ( V_57 -> args [ V_53 ] . V_98 )
free ( V_57 -> args [ V_53 ] . V_98 ) ;
if ( V_57 -> args [ V_53 ] . type )
free ( V_57 -> args [ V_53 ] . type ) ;
V_123 = V_57 -> args [ V_53 ] . V_123 ;
while ( V_123 ) {
V_126 = V_123 -> V_126 ;
if ( V_123 -> V_15 )
free ( V_123 -> V_15 ) ;
free ( V_123 ) ;
V_123 = V_126 ;
}
}
if ( V_57 -> args )
free ( V_57 -> args ) ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
}
static void F_70 ( struct V_50 * V_133 )
{
struct V_142 * V_125 , * V_126 ;
int V_53 ;
if ( V_133 -> V_116 )
free ( V_133 -> V_116 ) ;
if ( V_133 -> V_117 )
free ( V_133 -> V_117 ) ;
if ( V_133 -> V_55 . V_14 )
free ( V_133 -> V_55 . V_14 ) ;
if ( V_133 -> V_55 . V_18 )
free ( V_133 -> V_55 . V_18 ) ;
for ( V_53 = 0 ; V_53 < V_133 -> V_132 ; V_53 ++ ) {
if ( V_133 -> args [ V_53 ] . V_15 )
free ( V_133 -> args [ V_53 ] . V_15 ) ;
if ( V_133 -> args [ V_53 ] . V_137 )
free ( V_133 -> args [ V_53 ] . V_137 ) ;
if ( V_133 -> args [ V_53 ] . type )
free ( V_133 -> args [ V_53 ] . type ) ;
V_125 = V_133 -> args [ V_53 ] . V_125 ;
while ( V_125 ) {
V_126 = V_125 -> V_126 ;
free ( V_125 ) ;
V_125 = V_126 ;
}
}
if ( V_133 -> args )
free ( V_133 -> args ) ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
}
static int F_71 ( bool V_145 )
{
char V_76 [ V_146 ] ;
const char * V_147 ;
int V_4 ;
V_147 = F_72 () ;
if ( V_147 == NULL ) {
F_7 ( L_115 ) ;
return - V_41 ;
}
V_4 = F_1 ( V_76 , V_146 , L_116 , V_147 ) ;
if ( V_4 >= 0 ) {
F_3 ( L_117 , V_76 , V_145 ) ;
if ( V_145 && ! V_148 )
V_4 = F_73 ( V_76 , V_149 , V_150 ) ;
else
V_4 = F_73 ( V_76 , V_151 , 0 ) ;
}
if ( V_4 < 0 ) {
if ( V_68 == V_41 )
F_7 ( L_118
L_119 ) ;
else
F_7 ( L_120 ,
strerror ( V_68 ) ) ;
}
return V_4 ;
}
static struct V_152 * F_74 ( int V_153 )
{
int V_4 , V_154 ;
T_4 * V_72 ;
char V_76 [ V_141 ] ;
char * V_135 ;
struct V_152 * V_155 ;
V_155 = F_75 ( true , NULL ) ;
V_72 = fdopen ( F_76 ( V_153 ) , L_34 ) ;
while ( ! feof ( V_72 ) ) {
V_135 = fgets ( V_76 , V_141 , V_72 ) ;
if ( ! V_135 )
break;
V_154 = strlen ( V_135 ) - 1 ;
if ( V_135 [ V_154 ] == '\n' )
V_135 [ V_154 ] = '\0' ;
V_4 = F_77 ( V_155 , V_76 ) ;
if ( V_4 < 0 ) {
F_3 ( L_121 , strerror ( - V_4 ) ) ;
F_49 ( V_155 ) ;
return NULL ;
}
}
fclose ( V_72 ) ;
return V_155 ;
}
static int F_78 ( struct V_56 * V_57 )
{
int V_53 , V_4 ;
char V_76 [ 128 ] ;
char * V_156 ;
V_156 = F_32 ( & V_57 -> V_55 ) ;
if ( ! V_156 )
return - V_99 ;
V_4 = F_1 ( V_76 , 128 , L_122 , V_57 -> V_117 , V_57 -> V_116 ) ;
if ( V_4 < 0 )
return V_4 ;
printf ( L_123 , V_76 , V_156 ) ;
if ( V_57 -> V_132 > 0 ) {
printf ( L_124 ) ;
for ( V_53 = 0 ; V_53 < V_57 -> V_132 ; V_53 ++ ) {
V_4 = F_64 ( & V_57 -> args [ V_53 ] ,
V_76 , 128 ) ;
if ( V_4 < 0 )
break;
printf ( L_125 , V_76 ) ;
}
}
printf ( L_126 ) ;
free ( V_156 ) ;
return V_4 ;
}
int F_79 ( void )
{
int V_153 , V_4 ;
struct V_50 V_133 ;
struct V_56 V_57 ;
struct V_152 * V_157 ;
struct V_93 * V_158 ;
F_40 () ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_153 = F_71 ( false ) ;
if ( V_153 < 0 )
return V_153 ;
V_157 = F_74 ( V_153 ) ;
F_80 ( V_153 ) ;
if ( ! V_157 )
return - V_41 ;
F_47 (ent, rawlist) {
V_4 = F_63 ( V_158 -> V_101 , & V_133 ) ;
if ( V_4 >= 0 ) {
V_4 = F_68 ( & V_133 , & V_57 ) ;
if ( V_4 >= 0 )
V_4 = F_78 ( & V_57 ) ;
}
F_69 ( & V_57 ) ;
F_70 ( & V_133 ) ;
if ( V_4 < 0 )
break;
}
F_49 ( V_157 ) ;
return V_4 ;
}
static struct V_152 * F_81 ( int V_153 , bool V_159 )
{
char V_76 [ 128 ] ;
struct V_152 * V_155 , * V_157 ;
struct V_93 * V_158 ;
struct V_50 V_133 ;
int V_4 = 0 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_157 = F_74 ( V_153 ) ;
V_155 = F_75 ( true , NULL ) ;
F_47 (ent, rawlist) {
V_4 = F_63 ( V_158 -> V_101 , & V_133 ) ;
if ( V_4 < 0 )
break;
if ( V_159 ) {
V_4 = F_1 ( V_76 , 128 , L_122 , V_133 . V_117 ,
V_133 . V_116 ) ;
if ( V_4 >= 0 )
V_4 = F_77 ( V_155 , V_76 ) ;
} else
V_4 = F_77 ( V_155 , V_133 . V_116 ) ;
F_70 ( & V_133 ) ;
if ( V_4 < 0 )
break;
}
F_49 ( V_157 ) ;
if ( V_4 < 0 ) {
F_49 ( V_155 ) ;
return NULL ;
}
return V_155 ;
}
static int F_82 ( int V_153 , struct V_50 * V_133 )
{
int V_4 = 0 ;
char * V_76 = F_67 ( V_133 ) ;
if ( ! V_76 ) {
F_3 ( L_127 ) ;
return - V_99 ;
}
F_3 ( L_128 , V_76 ) ;
if ( ! V_148 ) {
V_4 = F_83 ( V_153 , V_76 , strlen ( V_76 ) ) ;
if ( V_4 <= 0 )
F_7 ( L_129 ,
strerror ( V_68 ) ) ;
}
free ( V_76 ) ;
return V_4 ;
}
static int F_84 ( char * V_76 , T_1 V_139 , const char * V_160 ,
struct V_152 * V_161 , bool V_162 )
{
int V_53 , V_4 ;
V_4 = F_1 ( V_76 , V_139 , L_26 , V_160 ) ;
if ( V_4 < 0 ) {
F_3 ( L_130 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_85 ( V_161 , V_76 ) )
return 0 ;
if ( ! V_162 ) {
F_7 ( L_131
L_132 , V_160 ) ;
return - V_163 ;
}
for ( V_53 = 1 ; V_53 < V_164 ; V_53 ++ ) {
V_4 = F_1 ( V_76 , V_139 , L_133 , V_160 , V_53 ) ;
if ( V_4 < 0 ) {
F_3 ( L_130 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_85 ( V_161 , V_76 ) )
break;
}
if ( V_53 == V_164 ) {
F_7 ( L_134 ) ;
V_4 = - V_131 ;
}
return V_4 ;
}
static int F_86 ( struct V_56 * V_57 ,
struct V_50 * V_51 ,
int V_52 , bool V_162 )
{
int V_53 , V_153 , V_4 ;
struct V_50 * V_133 = NULL ;
char V_76 [ 64 ] ;
const char * V_116 , * V_117 ;
struct V_152 * V_161 ;
V_153 = F_71 ( true ) ;
if ( V_153 < 0 )
return V_153 ;
V_161 = F_81 ( V_153 , false ) ;
if ( ! V_161 ) {
F_3 ( L_135 ) ;
return - V_165 ;
}
V_4 = 0 ;
printf ( L_136 , ( V_52 > 1 ) ? L_137 : L_114 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_133 = & V_51 [ V_53 ] ;
if ( V_57 -> V_116 )
V_116 = V_57 -> V_116 ;
else
if ( V_57 -> V_55 . V_47 )
V_116 = V_57 -> V_55 . V_47 ;
else
V_116 = V_133 -> V_55 . V_14 ;
if ( V_57 -> V_117 )
V_117 = V_57 -> V_117 ;
else
V_117 = V_166 ;
V_4 = F_84 ( V_76 , 64 , V_116 ,
V_161 , V_162 ) ;
if ( V_4 < 0 )
break;
V_116 = V_76 ;
V_133 -> V_116 = F_27 ( V_116 ) ;
V_133 -> V_117 = F_27 ( V_117 ) ;
if ( V_133 -> V_116 == NULL || V_133 -> V_117 == NULL ) {
V_4 = - V_48 ;
break;
}
V_4 = F_82 ( V_153 , V_133 ) ;
if ( V_4 < 0 )
break;
F_77 ( V_161 , V_116 ) ;
V_116 = V_57 -> V_116 ;
V_117 = V_57 -> V_117 ;
V_57 -> V_116 = V_133 -> V_116 ;
V_57 -> V_117 = V_133 -> V_117 ;
F_78 ( V_57 ) ;
V_57 -> V_116 = ( char * ) V_116 ;
V_57 -> V_117 = ( char * ) V_117 ;
V_162 = true ;
}
if ( V_4 >= 0 ) {
printf ( L_138 ) ;
printf ( L_139 , V_133 -> V_117 ,
V_133 -> V_116 ) ;
}
F_49 ( V_161 ) ;
F_80 ( V_153 ) ;
return V_4 ;
}
static int F_87 ( struct V_56 * V_57 ,
struct V_50 * * V_51 ,
int V_58 , const char * V_59 )
{
struct V_14 * V_39 ;
int V_4 = 0 , V_53 ;
struct V_50 * V_133 ;
V_4 = F_29 ( V_57 , V_51 , V_58 , V_59 ) ;
if ( V_4 != 0 )
return V_4 ;
V_133 = * V_51 = F_59 ( sizeof( struct V_50 ) ) ;
if ( V_133 == NULL )
return - V_48 ;
V_133 -> V_55 . V_14 = F_27 ( V_57 -> V_55 . V_47 ) ;
if ( V_133 -> V_55 . V_14 == NULL ) {
V_4 = - V_48 ;
goto error;
}
if ( V_59 ) {
V_133 -> V_55 . V_18 = F_27 ( V_59 ) ;
if ( V_133 -> V_55 . V_18 == NULL ) {
V_4 = - V_48 ;
goto error;
}
}
V_133 -> V_55 . V_45 = V_57 -> V_55 . V_45 ;
V_133 -> V_55 . V_49 = V_57 -> V_55 . V_49 ;
V_133 -> V_132 = V_57 -> V_132 ;
if ( V_133 -> V_132 ) {
V_133 -> args = F_59 ( sizeof( struct V_136 )
* V_133 -> V_132 ) ;
if ( V_133 -> args == NULL ) {
V_4 = - V_48 ;
goto error;
}
for ( V_53 = 0 ; V_53 < V_133 -> V_132 ; V_53 ++ ) {
if ( V_57 -> args [ V_53 ] . V_15 ) {
V_133 -> args [ V_53 ] . V_15 = F_27 ( V_57 -> args [ V_53 ] . V_15 ) ;
if ( V_133 -> args [ V_53 ] . V_15 == NULL ) {
V_4 = - V_48 ;
goto error;
}
}
V_133 -> args [ V_53 ] . V_137 = F_27 ( V_57 -> args [ V_53 ] . V_98 ) ;
if ( V_133 -> args [ V_53 ] . V_137 == NULL ) {
V_4 = - V_48 ;
goto error;
}
if ( V_57 -> args [ V_53 ] . type ) {
V_133 -> args [ V_53 ] . type = F_27 ( V_57 -> args [ V_53 ] . type ) ;
if ( V_133 -> args [ V_53 ] . type == NULL ) {
V_4 = - V_48 ;
goto error;
}
}
}
}
V_39 = F_8 ( V_133 -> V_55 . V_14 , NULL ) ;
if ( ! V_39 ) {
F_7 ( L_140 ,
V_133 -> V_55 . V_14 ) ;
V_4 = - V_41 ;
goto error;
} else if ( V_133 -> V_55 . V_45 > V_39 -> V_85 - V_39 -> V_44 ) {
F_7 ( L_141 ,
V_133 -> V_55 . V_14 ) ;
V_4 = - V_41 ;
goto error;
}
return 1 ;
error:
F_70 ( V_133 ) ;
free ( V_133 ) ;
* V_51 = NULL ;
return V_4 ;
}
int F_88 ( struct V_56 * V_102 , int V_103 ,
int V_58 , const char * V_59 , bool V_167 )
{
int V_53 , V_168 , V_4 ;
struct V_169 * V_170 ;
V_170 = F_59 ( sizeof( struct V_169 ) * V_103 ) ;
if ( V_170 == NULL )
return - V_48 ;
V_4 = F_2 () ;
if ( V_4 < 0 ) {
free ( V_170 ) ;
return V_4 ;
}
for ( V_53 = 0 ; V_53 < V_103 ; V_53 ++ ) {
V_170 [ V_53 ] . V_57 = & V_102 [ V_53 ] ;
V_4 = F_87 ( V_170 [ V_53 ] . V_57 ,
& V_170 [ V_53 ] . V_51 ,
V_58 ,
V_59 ) ;
if ( V_4 < 0 )
goto V_85;
V_170 [ V_53 ] . V_52 = V_4 ;
}
for ( V_53 = 0 ; V_53 < V_103 ; V_53 ++ ) {
V_4 = F_86 ( V_170 [ V_53 ] . V_57 , V_170 [ V_53 ] . V_51 ,
V_170 [ V_53 ] . V_52 , V_167 ) ;
if ( V_4 < 0 )
break;
}
V_85:
for ( V_53 = 0 ; V_53 < V_103 ; V_53 ++ ) {
for ( V_168 = 0 ; V_168 < V_170 [ V_53 ] . V_52 ; V_168 ++ )
F_70 ( & V_170 [ V_53 ] . V_51 [ V_168 ] ) ;
free ( V_170 [ V_53 ] . V_51 ) ;
}
free ( V_170 ) ;
return V_4 ;
}
static int F_89 ( int V_153 , struct V_93 * V_158 )
{
char * V_135 ;
char V_76 [ 128 ] ;
int V_4 ;
V_4 = F_1 ( V_76 , 128 , L_142 , V_158 -> V_101 ) ;
if ( V_4 < 0 )
goto error;
V_135 = strchr ( V_76 + 2 , ':' ) ;
if ( ! V_135 ) {
F_3 ( L_143 ,
V_158 -> V_101 ) ;
V_4 = - V_115 ;
goto error;
}
* V_135 = '/' ;
F_3 ( L_128 , V_76 ) ;
V_4 = F_83 ( V_153 , V_76 , strlen ( V_76 ) ) ;
if ( V_4 < 0 ) {
V_4 = - V_68 ;
goto error;
}
printf ( L_144 , V_158 -> V_101 ) ;
return 0 ;
error:
F_7 ( L_145 , strerror ( - V_4 ) ) ;
return V_4 ;
}
static int F_90 ( int V_153 , const char * V_117 ,
const char * V_116 , struct V_152 * V_161 )
{
char V_76 [ 128 ] ;
struct V_93 * V_158 , * V_171 ;
int V_30 = 0 , V_4 = 0 ;
V_4 = F_1 ( V_76 , 128 , L_122 , V_117 , V_116 ) ;
if ( V_4 < 0 ) {
F_21 ( L_146 ) ;
return V_4 ;
}
if ( strpbrk ( V_76 , L_147 ) ) {
F_91 (ent, n, namelist)
if ( F_92 ( V_158 -> V_101 , V_76 ) ) {
V_30 ++ ;
V_4 = F_89 ( V_153 , V_158 ) ;
if ( V_4 < 0 )
break;
F_93 ( V_161 , V_158 ) ;
}
} else {
V_158 = F_94 ( V_161 , V_76 ) ;
if ( V_158 ) {
V_30 ++ ;
V_4 = F_89 ( V_153 , V_158 ) ;
if ( V_4 >= 0 )
F_93 ( V_161 , V_158 ) ;
}
}
if ( V_30 == 0 && V_4 >= 0 )
F_95 ( L_148 , V_76 ) ;
return V_4 ;
}
int F_96 ( struct V_152 * V_172 )
{
int V_153 , V_4 = 0 ;
const char * V_117 , * V_116 ;
char * V_135 , * V_1 ;
struct V_93 * V_158 ;
struct V_152 * V_161 ;
V_153 = F_71 ( true ) ;
if ( V_153 < 0 )
return V_153 ;
V_161 = F_81 ( V_153 , true ) ;
if ( V_161 == NULL )
return - V_99 ;
F_47 (ent, dellist) {
V_1 = F_27 ( V_158 -> V_101 ) ;
if ( V_1 == NULL ) {
V_4 = - V_48 ;
break;
}
F_3 ( L_149 , V_1 ) ;
V_135 = strchr ( V_1 , ':' ) ;
if ( V_135 ) {
V_117 = V_1 ;
* V_135 = '\0' ;
V_116 = V_135 + 1 ;
} else {
V_117 = L_150 ;
V_116 = V_1 ;
}
F_3 ( L_151 , V_117 , V_116 ) ;
V_4 = F_90 ( V_153 , V_117 , V_116 , V_161 ) ;
free ( V_1 ) ;
if ( V_4 < 0 )
break;
}
F_49 ( V_161 ) ;
F_80 ( V_153 ) ;
return V_4 ;
}
static int F_97 ( struct V_16 * V_16 V_104 ,
struct V_14 * V_39 )
{
if ( V_39 -> V_173 == V_174 &&
F_48 ( V_175 , V_39 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_98 ( const char * V_59 , struct V_89 * V_90 )
{
struct V_16 * V_16 ;
int V_4 ;
F_40 () ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_16 = F_10 ( V_59 ) ;
if ( ! V_16 ) {
F_21 ( L_152 , ( V_59 ) ? : L_6 ) ;
return - V_99 ;
}
V_175 = V_90 ;
if ( F_99 ( V_16 , F_97 ) ) {
F_21 ( L_153 ) ;
return - V_99 ;
}
if ( ! F_100 ( V_16 -> V_27 , V_16 -> type ) )
F_101 ( V_16 -> V_27 , V_16 -> type ) ;
F_102 ( V_16 -> V_27 , V_16 -> type , stdout ) ;
return 0 ;
}
