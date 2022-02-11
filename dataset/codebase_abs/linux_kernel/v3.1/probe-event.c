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
int V_58 , const char * V_18 )
{
bool V_59 = F_30 ( V_57 ) ;
struct V_33 * V_42 = F_20 ( V_18 ) ;
int V_52 , V_4 = 0 ;
if ( ! V_42 ) {
if ( V_59 ) {
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
if ( V_18 )
V_4 = F_28 ( * V_51 , V_52 ,
V_18 ) ;
return V_4 < 0 ? V_4 : V_52 ;
}
if ( V_52 == 0 ) {
F_7 ( L_18 ,
F_32 ( & V_57 -> V_55 ) ) ;
return - V_41 ;
}
F_3 ( L_19 , V_52 ) ;
if ( V_52 == - V_60 ) {
F_7 ( L_20
L_21 ) ;
if ( ! V_59 ) {
F_3 ( L_22 ) ;
return 0 ;
}
}
return V_52 ;
}
static int F_33 ( const char * V_61 , const char * V_62 ,
char * * V_63 )
{
const char * V_64 = V_7 . V_65 ;
if ( ! V_64 ) {
if ( V_61 [ 0 ] != '/' && V_62 )
V_64 = V_62 ;
else {
if ( F_34 ( V_61 , V_66 ) == 0 ) {
* V_63 = F_27 ( V_61 ) ;
return 0 ;
} else
return - V_67 ;
}
}
* V_63 = malloc ( ( strlen ( V_64 ) + strlen ( V_61 ) + 2 ) ) ;
if ( ! * V_63 )
return - V_48 ;
for (; ; ) {
sprintf ( * V_63 , L_23 , V_64 , V_61 ) ;
if ( F_34 ( * V_63 , V_66 ) == 0 )
return 0 ;
if ( ! V_7 . V_65 )
return - V_67 ;
switch ( V_67 ) {
case V_68 :
case V_41 :
case V_69 :
case V_70 :
V_61 = strchr ( ++ V_61 , '/' ) ;
if ( ! V_61 ) {
free ( * V_63 ) ;
* V_63 = NULL ;
return - V_41 ;
}
continue;
default:
free ( * V_63 ) ;
* V_63 = NULL ;
return - V_67 ;
}
}
}
static int F_35 ( T_4 * V_71 , int V_72 , bool V_73 , bool V_74 )
{
char V_75 [ V_76 ] ;
const char * V_77 = V_74 ? L_3 : V_78 ;
const char * V_64 = NULL ;
do {
if ( fgets ( V_75 , V_76 , V_71 ) == NULL )
goto error;
if ( V_73 )
continue;
if ( ! V_64 ) {
V_64 = V_74 ? L_24 : L_25 ;
F_36 ( stdout , V_77 , V_64 , V_72 ) ;
}
F_36 ( stdout , V_77 , L_26 , V_75 ) ;
} while ( strchr ( V_75 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_71 ) ) {
F_7 ( L_27 , strerror ( V_67 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_37 ( T_4 * V_71 , int V_72 , bool V_73 , bool V_74 )
{
int V_79 = F_35 ( V_71 , V_72 , V_73 , V_74 ) ;
if ( V_79 == 0 ) {
F_7 ( L_28 ) ;
V_79 = - 1 ;
}
return V_79 ;
}
int F_38 ( struct V_80 * V_81 , const char * V_18 )
{
int V_72 = 1 ;
struct V_82 * V_83 ;
struct V_33 * V_42 ;
T_4 * V_71 ;
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
V_4 = F_39 ( V_42 , V_81 ) ;
F_26 ( V_42 ) ;
if ( V_4 == 0 ) {
F_7 ( L_29 ) ;
return - V_41 ;
} else if ( V_4 < 0 ) {
F_7 ( L_30 , V_4 ) ;
return V_4 ;
}
V_54 = V_81 -> V_34 ;
V_4 = F_33 ( V_54 , V_81 -> V_62 , & V_81 -> V_34 ) ;
free ( V_54 ) ;
if ( V_4 < 0 ) {
F_7 ( L_31 , V_4 ) ;
return V_4 ;
}
F_40 () ;
if ( V_81 -> V_47 )
fprintf ( stdout , L_32 , V_81 -> V_47 , V_81 -> V_34 ,
V_81 -> V_44 - V_81 -> V_45 ) ;
else
fprintf ( stdout , L_33 , V_81 -> V_34 , V_81 -> V_44 ) ;
V_71 = fopen ( V_81 -> V_34 , L_34 ) ;
if ( V_71 == NULL ) {
F_7 ( L_35 , V_81 -> V_34 ,
strerror ( V_67 ) ) ;
return - V_67 ;
}
while ( V_72 < V_81 -> V_44 ) {
V_4 = F_41 ( V_71 , V_72 ++ ) ;
if ( V_4 < 0 )
goto V_84;
}
F_16 (ln, &lr->line_list, list) {
for (; V_83 -> line > V_72 ; V_72 ++ ) {
V_4 = F_42 ( V_71 , V_72 - V_81 -> V_45 ) ;
if ( V_4 < 0 )
goto V_84;
}
V_4 = F_43 ( V_71 , V_72 ++ - V_81 -> V_45 ) ;
if ( V_4 < 0 )
goto V_84;
}
if ( V_81 -> V_84 == V_85 )
V_81 -> V_84 = V_72 + V_86 ;
while ( V_72 <= V_81 -> V_84 ) {
V_4 = F_44 ( V_71 , V_72 ++ - V_81 -> V_45 ) ;
if ( V_4 <= 0 )
break;
}
V_84:
fclose ( V_71 ) ;
return V_4 ;
}
static int F_45 ( struct V_33 * V_42 ,
struct V_56 * V_57 ,
int V_87 , struct V_88 * V_89 ,
bool V_90 )
{
char * V_75 ;
int V_4 , V_53 , V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 = NULL , * V_96 ;
const char * V_97 ;
V_75 = F_32 ( & V_57 -> V_55 ) ;
if ( ! V_75 )
return - V_98 ;
F_3 ( L_36 , V_75 ) ;
V_4 = F_46 ( V_42 , V_57 , & V_95 ,
V_87 , V_90 ) ;
if ( V_4 <= 0 ) {
F_21 ( L_37 , V_75 , V_4 ) ;
goto V_84;
}
fprintf ( stdout , L_38 , V_75 ) ;
for ( V_53 = 0 ; V_53 < V_4 ; V_53 ++ ) {
V_96 = & V_95 [ V_53 ] ;
fprintf ( stdout , L_39 , V_96 -> V_55 . V_14 ,
V_96 -> V_55 . V_45 ) ;
free ( V_96 -> V_55 . V_14 ) ;
V_91 = 0 ;
if ( V_96 -> V_99 ) {
F_47 (node, vl->vars) {
V_97 = strchr ( V_93 -> V_100 , '\t' ) + 1 ;
if ( F_48 ( V_89 , V_97 ) ) {
fprintf ( stdout , L_40 , V_93 -> V_100 ) ;
V_91 ++ ;
}
}
F_49 ( V_96 -> V_99 ) ;
}
if ( V_91 == 0 )
fprintf ( stdout , L_41 ) ;
}
free ( V_95 ) ;
V_84:
free ( V_75 ) ;
return V_4 ;
}
int F_50 ( struct V_56 * V_101 , int V_102 ,
int V_87 , const char * V_18 ,
struct V_88 * V_89 , bool V_90 )
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
for ( V_53 = 0 ; V_53 < V_102 && V_4 >= 0 ; V_53 ++ )
V_4 = F_45 ( V_42 , & V_101 [ V_53 ] , V_87 , V_89 ,
V_90 ) ;
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
struct V_50 * * V_51 V_103 ,
int V_58 V_103 , const char * T_5 V_103 )
{
if ( F_30 ( V_57 ) ) {
F_7 ( L_43 ) ;
return - V_104 ;
}
return 0 ;
}
int F_38 ( struct V_80 * V_81 V_103 , const char * V_18 V_103 )
{
F_7 ( L_43 ) ;
return - V_104 ;
}
int F_50 ( struct V_56 * V_101 V_103 ,
int V_102 V_103 , int V_87 V_103 ,
const char * V_18 V_103 ,
struct V_88 * T_6 V_103 ,
bool V_90 V_103 )
{
F_7 ( L_43 ) ;
return - V_104 ;
}
static int F_51 ( char * * V_105 , int * V_106 , const char * V_107 )
{
const char * V_44 = * V_105 ;
V_67 = 0 ;
* V_106 = strtol ( * V_105 , V_105 , 0 ) ;
if ( V_67 || * V_105 == V_44 ) {
F_52 ( L_44 , V_107 ) ;
return - V_98 ;
}
return 0 ;
}
int F_53 ( const char * V_108 , struct V_80 * V_81 )
{
char * V_109 , * V_110 , * V_15 = F_27 ( V_108 ) ;
int V_111 ;
if ( ! V_15 )
return - V_48 ;
V_81 -> V_44 = 0 ;
V_81 -> V_84 = V_85 ;
V_109 = strchr ( V_15 , ':' ) ;
if ( V_109 ) {
* V_109 ++ = '\0' ;
V_111 = F_51 ( & V_109 , & V_81 -> V_44 , L_45 ) ;
if ( V_111 )
goto V_111;
if ( * V_109 == '+' || * V_109 == '-' ) {
const char V_112 = * V_109 ++ ;
V_111 = F_51 ( & V_109 , & V_81 -> V_84 , L_46 ) ;
if ( V_111 )
goto V_111;
if ( V_112 == '+' ) {
V_81 -> V_84 += V_81 -> V_44 ;
V_81 -> V_84 -- ;
}
}
F_3 ( L_47 , V_81 -> V_44 , V_81 -> V_84 ) ;
V_111 = - V_98 ;
if ( V_81 -> V_44 > V_81 -> V_84 ) {
F_52 ( L_48
L_49 ) ;
goto V_111;
}
if ( * V_109 != '\0' ) {
F_52 ( L_50 , V_109 ) ;
goto V_111;
}
}
V_110 = strchr ( V_15 , '@' ) ;
if ( V_110 ) {
* V_110 = '\0' ;
V_81 -> V_110 = F_27 ( ++ V_110 ) ;
if ( V_81 -> V_110 == NULL ) {
V_111 = - V_48 ;
goto V_111;
}
V_81 -> V_47 = V_15 ;
} else if ( strchr ( V_15 , '.' ) )
V_81 -> V_110 = V_15 ;
else
V_81 -> V_47 = V_15 ;
return 0 ;
V_111:
free ( V_15 ) ;
return V_111 ;
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
static int F_55 ( char * V_108 , struct V_56 * V_57 )
{
struct V_37 * V_38 = & V_57 -> V_55 ;
char * V_105 , * V_54 ;
char V_112 , V_113 = 0 ;
V_105 = strpbrk ( V_108 , L_51 ) ;
if ( V_105 && * V_105 == '=' ) {
* V_105 = '\0' ;
V_54 = V_105 + 1 ;
if ( strchr ( V_108 , ':' ) ) {
F_52 ( L_52 ) ;
return - V_114 ;
}
if ( ! F_54 ( V_108 ) ) {
F_52 ( L_53
L_54 , V_108 ) ;
return - V_98 ;
}
V_57 -> V_115 = F_27 ( V_108 ) ;
if ( V_57 -> V_115 == NULL )
return - V_48 ;
V_57 -> V_116 = NULL ;
V_108 = V_54 ;
}
V_105 = strpbrk ( V_108 , L_55 ) ;
if ( V_105 ) {
V_113 = * V_105 ;
* V_105 ++ = '\0' ;
}
V_54 = F_27 ( V_108 ) ;
if ( V_54 == NULL )
return - V_48 ;
if ( strchr ( V_54 , '.' ) )
V_38 -> V_110 = V_54 ;
else
V_38 -> V_47 = V_54 ;
while ( V_105 ) {
V_108 = V_105 ;
V_112 = V_113 ;
if ( V_112 == ';' ) {
V_38 -> V_117 = F_27 ( V_108 ) ;
if ( V_38 -> V_117 == NULL )
return - V_48 ;
break;
}
V_105 = strpbrk ( V_108 , L_55 ) ;
if ( V_105 ) {
V_113 = * V_105 ;
* V_105 ++ = '\0' ;
}
switch ( V_112 ) {
case ':' :
V_38 -> line = strtoul ( V_108 , & V_54 , 0 ) ;
if ( * V_54 != '\0' ) {
F_52 ( L_56
L_57 ) ;
return - V_98 ;
}
break;
case '+' :
V_38 -> V_45 = strtoul ( V_108 , & V_54 , 0 ) ;
if ( * V_54 != '\0' ) {
F_52 ( L_58
L_59 ) ;
return - V_98 ;
}
break;
case '@' :
if ( V_38 -> V_110 ) {
F_52 ( L_60 ) ;
return - V_98 ;
}
V_38 -> V_110 = F_27 ( V_108 ) ;
if ( V_38 -> V_110 == NULL )
return - V_48 ;
break;
case '%' :
if ( strcmp ( V_108 , L_61 ) == 0 ) {
V_38 -> V_49 = 1 ;
} else {
F_52 ( L_62 , V_108 ) ;
return - V_114 ;
}
break;
default:
F_21 ( L_63 ,
__FILE__ , __LINE__ ) ;
return - V_114 ;
break;
}
}
if ( V_38 -> V_117 && V_38 -> line ) {
F_52 ( L_64
L_65 ) ;
return - V_98 ;
}
if ( V_38 -> V_117 && V_38 -> V_45 ) {
F_52 ( L_66 ) ;
return - V_98 ;
}
if ( V_38 -> line && V_38 -> V_45 ) {
F_52 ( L_67 ) ;
return - V_98 ;
}
if ( ! V_38 -> line && ! V_38 -> V_117 && V_38 -> V_110 && ! V_38 -> V_47 ) {
F_52 ( L_68
L_69 ) ;
return - V_98 ;
}
if ( V_38 -> V_45 && ! V_38 -> V_47 ) {
F_52 ( L_70 ) ;
return - V_98 ;
}
if ( V_38 -> V_49 && ! V_38 -> V_47 ) {
F_52 ( L_71 ) ;
return - V_98 ;
}
if ( ( V_38 -> V_45 || V_38 -> line || V_38 -> V_117 ) && V_38 -> V_49 ) {
F_52 ( L_72
L_73 ) ;
return - V_98 ;
}
F_3 ( L_74 ,
V_38 -> V_47 , V_38 -> V_110 , V_38 -> line , V_38 -> V_45 , V_38 -> V_49 ,
V_38 -> V_117 ) ;
return 0 ;
}
static int F_56 ( char * V_1 , struct V_118 * V_108 )
{
char * V_54 , * V_119 ;
struct V_120 * * V_121 ;
F_3 ( L_75 , V_1 ) ;
V_54 = strchr ( V_1 , '=' ) ;
if ( V_54 ) {
V_108 -> V_15 = F_57 ( V_1 , V_54 - V_1 ) ;
if ( V_108 -> V_15 == NULL )
return - V_48 ;
F_3 ( L_76 , V_108 -> V_15 ) ;
V_1 = V_54 + 1 ;
}
V_54 = strchr ( V_1 , ':' ) ;
if ( V_54 ) {
* V_54 = '\0' ;
V_108 -> type = F_27 ( V_54 + 1 ) ;
if ( V_108 -> type == NULL )
return - V_48 ;
F_3 ( L_77 , V_108 -> type ) ;
}
V_54 = strpbrk ( V_1 , L_78 ) ;
if ( ! F_58 ( V_1 ) || ! V_54 ) {
V_108 -> V_97 = F_27 ( V_1 ) ;
if ( V_108 -> V_97 == NULL )
return - V_48 ;
F_3 ( L_79 , V_108 -> V_97 ) ;
return 0 ;
}
V_108 -> V_97 = F_57 ( V_1 , V_54 - V_1 ) ;
if ( V_108 -> V_97 == NULL )
return - V_48 ;
V_119 = V_108 -> V_97 ;
F_3 ( L_80 , V_108 -> V_97 ) ;
V_121 = & V_108 -> V_122 ;
do {
* V_121 = F_59 ( sizeof( struct V_120 ) ) ;
if ( * V_121 == NULL )
return - V_48 ;
if ( * V_54 == '[' ) {
V_1 = V_54 ;
( * V_121 ) -> V_123 = strtol ( V_1 + 1 , & V_54 , 0 ) ;
( * V_121 ) -> V_124 = true ;
if ( * V_54 != ']' || V_54 == V_1 + 1 ) {
F_52 ( L_81
L_82 ) ;
return - V_98 ;
}
V_54 ++ ;
if ( * V_54 == '\0' )
V_54 = NULL ;
} else {
if ( * V_54 == '.' ) {
V_1 = V_54 + 1 ;
( * V_121 ) -> V_124 = false ;
} else if ( V_54 [ 1 ] == '>' ) {
V_1 = V_54 + 2 ;
( * V_121 ) -> V_124 = true ;
} else {
F_52 ( L_83 ,
V_1 ) ;
return - V_98 ;
}
V_54 = strpbrk ( V_1 , L_78 ) ;
}
if ( V_54 ) {
( * V_121 ) -> V_15 = F_57 ( V_1 , V_54 - V_1 ) ;
if ( ( * V_121 ) -> V_15 == NULL )
return - V_48 ;
if ( * V_1 != '[' )
V_119 = ( * V_121 ) -> V_15 ;
F_3 ( L_84 , ( * V_121 ) -> V_15 , ( * V_121 ) -> V_124 ) ;
V_121 = & ( * V_121 ) -> V_125 ;
}
} while ( V_54 );
( * V_121 ) -> V_15 = F_27 ( V_1 ) ;
if ( ( * V_121 ) -> V_15 == NULL )
return - V_48 ;
if ( * V_1 != '[' )
V_119 = ( * V_121 ) -> V_15 ;
F_3 ( L_85 , ( * V_121 ) -> V_15 , ( * V_121 ) -> V_124 ) ;
if ( ! V_108 -> V_15 ) {
V_108 -> V_15 = F_27 ( V_119 ) ;
if ( V_108 -> V_15 == NULL )
return - V_48 ;
}
return 0 ;
}
int F_60 ( const char * V_126 , struct V_56 * V_57 )
{
char * * V_127 ;
int V_128 , V_53 , V_4 = 0 ;
V_127 = F_61 ( V_126 , & V_128 ) ;
if ( ! V_127 ) {
F_3 ( L_86 ) ;
return - V_48 ;
}
if ( V_128 - 1 > V_129 ) {
F_52 ( L_87 , V_128 - 1 ) ;
V_4 = - V_130 ;
goto V_11;
}
V_4 = F_55 ( V_127 [ 0 ] , V_57 ) ;
if ( V_4 < 0 )
goto V_11;
V_57 -> V_131 = V_128 - 1 ;
V_57 -> args = F_59 ( sizeof( struct V_118 ) * V_57 -> V_131 ) ;
if ( V_57 -> args == NULL ) {
V_4 = - V_48 ;
goto V_11;
}
for ( V_53 = 0 ; V_53 < V_57 -> V_131 && V_4 >= 0 ; V_53 ++ ) {
V_4 = F_56 ( V_127 [ V_53 + 1 ] , & V_57 -> args [ V_53 ] ) ;
if ( V_4 >= 0 &&
F_58 ( V_57 -> args [ V_53 ] . V_97 ) && V_57 -> V_55 . V_49 ) {
F_52 ( L_88
L_89 ) ;
V_4 = - V_98 ;
}
}
V_11:
F_62 ( V_127 ) ;
return V_4 ;
}
bool F_30 ( struct V_56 * V_57 )
{
int V_53 ;
if ( V_57 -> V_55 . V_110 || V_57 -> V_55 . line || V_57 -> V_55 . V_117 )
return true ;
for ( V_53 = 0 ; V_53 < V_57 -> V_131 ; V_53 ++ )
if ( F_58 ( V_57 -> args [ V_53 ] . V_97 ) )
return true ;
return false ;
}
static int F_63 ( const char * V_126 ,
struct V_50 * V_132 )
{
struct V_35 * V_36 = & V_132 -> V_55 ;
char V_133 ;
char * V_134 ;
int V_4 , V_53 , V_128 ;
char * * V_127 ;
F_3 ( L_90 , V_126 ) ;
V_127 = F_61 ( V_126 , & V_128 ) ;
if ( ! V_127 ) {
F_3 ( L_86 ) ;
return - V_48 ;
}
if ( V_128 < 2 ) {
F_52 ( L_91 ) ;
V_4 = - V_130 ;
goto V_11;
}
V_4 = sscanf ( V_127 [ 0 ] , L_92 ,
& V_133 , ( float * ) ( void * ) & V_132 -> V_116 ,
( float * ) ( void * ) & V_132 -> V_115 ) ;
if ( V_4 != 3 ) {
F_52 ( L_93 , V_127 [ 0 ] ) ;
V_4 = - V_98 ;
goto V_11;
}
F_3 ( L_94 , V_132 -> V_116 , V_132 -> V_115 , V_133 ) ;
V_36 -> V_49 = ( V_133 == 'r' ) ;
V_134 = strchr ( V_127 [ 1 ] , ':' ) ;
if ( V_134 ) {
V_36 -> V_18 = F_57 ( V_127 [ 1 ] , V_134 - V_127 [ 1 ] ) ;
V_134 ++ ;
} else
V_134 = V_127 [ 1 ] ;
V_4 = sscanf ( V_134 , L_95 , ( float * ) ( void * ) & V_36 -> V_14 ,
& V_36 -> V_45 ) ;
if ( V_4 == 1 )
V_36 -> V_45 = 0 ;
V_132 -> V_131 = V_128 - 2 ;
V_132 -> args = F_59 ( sizeof( struct V_135 ) * V_132 -> V_131 ) ;
if ( V_132 -> args == NULL ) {
V_4 = - V_48 ;
goto V_11;
}
for ( V_53 = 0 ; V_53 < V_132 -> V_131 ; V_53 ++ ) {
V_134 = strchr ( V_127 [ V_53 + 2 ] , '=' ) ;
if ( V_134 )
* V_134 ++ = '\0' ;
else
V_134 = V_127 [ V_53 + 2 ] ;
V_132 -> args [ V_53 ] . V_15 = F_27 ( V_127 [ V_53 + 2 ] ) ;
V_132 -> args [ V_53 ] . V_136 = F_27 ( V_134 ) ;
if ( V_132 -> args [ V_53 ] . V_15 == NULL || V_132 -> args [ V_53 ] . V_136 == NULL ) {
V_4 = - V_48 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
F_62 ( V_127 ) ;
return V_4 ;
}
int F_64 ( struct V_118 * V_137 , char * V_75 , T_1 V_138 )
{
struct V_120 * V_122 = V_137 -> V_122 ;
int V_4 ;
char * V_54 = V_75 ;
if ( V_137 -> V_15 && V_137 -> V_97 )
V_4 = F_1 ( V_54 , V_138 , L_96 , V_137 -> V_15 , V_137 -> V_97 ) ;
else
V_4 = F_1 ( V_54 , V_138 , L_26 , V_137 -> V_15 ? V_137 -> V_15 : V_137 -> V_97 ) ;
if ( V_4 <= 0 )
goto error;
V_54 += V_4 ;
V_138 -= V_4 ;
while ( V_122 ) {
if ( V_122 -> V_15 [ 0 ] == '[' )
V_4 = F_1 ( V_54 , V_138 , L_26 , V_122 -> V_15 ) ;
else
V_4 = F_1 ( V_54 , V_138 , L_97 ,
V_122 -> V_124 ? L_98 : L_99 , V_122 -> V_15 ) ;
if ( V_4 <= 0 )
goto error;
V_54 += V_4 ;
V_138 -= V_4 ;
V_122 = V_122 -> V_125 ;
}
if ( V_137 -> type ) {
V_4 = F_1 ( V_54 , V_138 , L_100 , V_137 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_54 += V_4 ;
V_138 -= V_4 ;
}
return V_54 - V_75 ;
error:
F_3 ( L_101 ,
strerror ( - V_4 ) ) ;
return V_4 ;
}
static char * F_32 ( struct V_37 * V_38 )
{
char * V_75 , * V_54 ;
char V_139 [ 32 ] = L_3 , line [ 32 ] = L_3 , V_110 [ 32 ] = L_3 ;
int V_4 , V_138 ;
V_75 = F_59 ( V_140 ) ;
if ( V_75 == NULL ) {
V_4 = - V_48 ;
goto error;
}
if ( V_38 -> V_45 ) {
V_4 = F_1 ( V_139 , 32 , L_102 , V_38 -> V_45 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_38 -> line ) {
V_4 = F_1 ( line , 32 , L_103 , V_38 -> line ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_38 -> V_110 ) {
V_54 = V_38 -> V_110 ;
V_138 = strlen ( V_54 ) ;
if ( V_138 > 30 ) {
V_54 = strchr ( V_38 -> V_110 + V_138 - 30 , '/' ) ;
V_54 = V_54 ? V_54 + 1 : V_38 -> V_110 + V_138 - 30 ;
}
V_4 = F_1 ( V_110 , 32 , L_104 , V_54 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_38 -> V_47 )
V_4 = F_1 ( V_75 , V_140 , L_105 , V_38 -> V_47 ,
V_139 , V_38 -> V_49 ? L_106 : L_3 , line ,
V_110 ) ;
else
V_4 = F_1 ( V_75 , V_140 , L_97 , V_110 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_75 ;
error:
F_3 ( L_107 ,
strerror ( - V_4 ) ) ;
if ( V_75 )
free ( V_75 ) ;
return NULL ;
}
static int F_65 ( struct V_141 * V_124 ,
char * * V_75 , T_1 * V_142 ,
int V_143 )
{
int V_4 ;
if ( V_124 -> V_125 ) {
V_143 = F_65 ( V_124 -> V_125 , V_75 ,
V_142 , V_143 + 1 ) ;
if ( V_143 < 0 )
goto V_11;
}
V_4 = F_1 ( * V_75 , * V_142 , L_108 , V_124 -> V_45 ) ;
if ( V_4 < 0 )
V_143 = V_4 ;
else {
* V_75 += V_4 ;
* V_142 -= V_4 ;
}
V_11:
return V_143 ;
}
static int F_66 ( struct V_135 * V_108 ,
char * V_75 , T_1 V_142 )
{
struct V_141 * V_124 = V_108 -> V_124 ;
int V_4 , V_143 = 0 ;
char * V_54 = V_75 ;
if ( V_108 -> V_15 )
V_4 = F_1 ( V_75 , V_142 , L_109 , V_108 -> V_15 ) ;
else
V_4 = F_1 ( V_75 , V_142 , L_110 ) ;
if ( V_4 < 0 )
return V_4 ;
V_75 += V_4 ;
V_142 -= V_4 ;
if ( V_108 -> V_136 [ 0 ] == '@' && V_108 -> V_124 )
V_124 = V_124 -> V_125 ;
if ( V_124 ) {
V_143 = F_65 ( V_124 , & V_75 ,
& V_142 , 1 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_108 -> V_136 [ 0 ] == '@' && V_108 -> V_124 )
V_4 = F_1 ( V_75 , V_142 , L_111 , V_108 -> V_136 ,
V_108 -> V_124 -> V_45 ) ;
else
V_4 = F_1 ( V_75 , V_142 , L_26 , V_108 -> V_136 ) ;
if ( V_4 < 0 )
return V_4 ;
V_75 += V_4 ;
V_142 -= V_4 ;
while ( V_143 -- ) {
V_4 = F_1 ( V_75 , V_142 , L_112 ) ;
if ( V_4 < 0 )
return V_4 ;
V_75 += V_4 ;
V_142 -= V_4 ;
}
if ( V_108 -> type ) {
V_4 = F_1 ( V_75 , V_142 , L_100 , V_108 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_75 += V_4 ;
}
return V_75 - V_54 ;
}
char * F_67 ( struct V_50 * V_132 )
{
struct V_35 * V_36 = & V_132 -> V_55 ;
char * V_75 ;
int V_53 , V_138 , V_4 ;
V_75 = F_59 ( V_140 ) ;
if ( V_75 == NULL )
return NULL ;
V_138 = F_1 ( V_75 , V_140 , L_113 ,
V_36 -> V_49 ? 'r' : 'p' ,
V_132 -> V_116 , V_132 -> V_115 ,
V_36 -> V_18 ? : L_3 , V_36 -> V_18 ? L_114 : L_3 ,
V_36 -> V_14 , V_36 -> V_45 ) ;
if ( V_138 <= 0 )
goto error;
for ( V_53 = 0 ; V_53 < V_132 -> V_131 ; V_53 ++ ) {
V_4 = F_66 ( & V_132 -> args [ V_53 ] , V_75 + V_138 ,
V_140 - V_138 ) ;
if ( V_4 <= 0 )
goto error;
V_138 += V_4 ;
}
return V_75 ;
error:
free ( V_75 ) ;
return NULL ;
}
static int F_68 ( struct V_50 * V_132 ,
struct V_56 * V_57 )
{
char V_75 [ 64 ] = L_3 ;
int V_53 , V_4 ;
V_57 -> V_115 = F_27 ( V_132 -> V_115 ) ;
V_57 -> V_116 = F_27 ( V_132 -> V_116 ) ;
if ( V_57 -> V_115 == NULL || V_57 -> V_116 == NULL )
return - V_48 ;
V_4 = F_23 ( & V_132 -> V_55 , & V_57 -> V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
V_57 -> V_131 = V_132 -> V_131 ;
V_57 -> args = F_59 ( sizeof( struct V_118 ) * V_57 -> V_131 ) ;
if ( V_57 -> args == NULL )
return - V_48 ;
for ( V_53 = 0 ; V_53 < V_132 -> V_131 && V_4 >= 0 ; V_53 ++ ) {
if ( V_132 -> args [ V_53 ] . V_15 )
V_57 -> args [ V_53 ] . V_15 = F_27 ( V_132 -> args [ V_53 ] . V_15 ) ;
else {
V_4 = F_66 ( & V_132 -> args [ V_53 ] ,
V_75 , 64 ) ;
V_57 -> args [ V_53 ] . V_15 = F_27 ( V_75 ) ;
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
struct V_120 * V_122 , * V_125 ;
int V_53 ;
if ( V_57 -> V_115 )
free ( V_57 -> V_115 ) ;
if ( V_57 -> V_116 )
free ( V_57 -> V_116 ) ;
if ( V_38 -> V_110 )
free ( V_38 -> V_110 ) ;
if ( V_38 -> V_47 )
free ( V_38 -> V_47 ) ;
if ( V_38 -> V_117 )
free ( V_38 -> V_117 ) ;
for ( V_53 = 0 ; V_53 < V_57 -> V_131 ; V_53 ++ ) {
if ( V_57 -> args [ V_53 ] . V_15 )
free ( V_57 -> args [ V_53 ] . V_15 ) ;
if ( V_57 -> args [ V_53 ] . V_97 )
free ( V_57 -> args [ V_53 ] . V_97 ) ;
if ( V_57 -> args [ V_53 ] . type )
free ( V_57 -> args [ V_53 ] . type ) ;
V_122 = V_57 -> args [ V_53 ] . V_122 ;
while ( V_122 ) {
V_125 = V_122 -> V_125 ;
if ( V_122 -> V_15 )
free ( V_122 -> V_15 ) ;
free ( V_122 ) ;
V_122 = V_125 ;
}
}
if ( V_57 -> args )
free ( V_57 -> args ) ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
}
static void F_70 ( struct V_50 * V_132 )
{
struct V_141 * V_124 , * V_125 ;
int V_53 ;
if ( V_132 -> V_115 )
free ( V_132 -> V_115 ) ;
if ( V_132 -> V_116 )
free ( V_132 -> V_116 ) ;
if ( V_132 -> V_55 . V_14 )
free ( V_132 -> V_55 . V_14 ) ;
if ( V_132 -> V_55 . V_18 )
free ( V_132 -> V_55 . V_18 ) ;
for ( V_53 = 0 ; V_53 < V_132 -> V_131 ; V_53 ++ ) {
if ( V_132 -> args [ V_53 ] . V_15 )
free ( V_132 -> args [ V_53 ] . V_15 ) ;
if ( V_132 -> args [ V_53 ] . V_136 )
free ( V_132 -> args [ V_53 ] . V_136 ) ;
if ( V_132 -> args [ V_53 ] . type )
free ( V_132 -> args [ V_53 ] . type ) ;
V_124 = V_132 -> args [ V_53 ] . V_124 ;
while ( V_124 ) {
V_125 = V_124 -> V_125 ;
free ( V_124 ) ;
V_124 = V_125 ;
}
}
if ( V_132 -> args )
free ( V_132 -> args ) ;
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
}
static int F_71 ( bool V_144 )
{
char V_75 [ V_145 ] ;
const char * V_146 ;
int V_4 ;
V_146 = F_72 () ;
if ( V_146 == NULL ) {
F_7 ( L_115 ) ;
return - V_41 ;
}
V_4 = F_1 ( V_75 , V_145 , L_116 , V_146 ) ;
if ( V_4 >= 0 ) {
F_3 ( L_117 , V_75 , V_144 ) ;
if ( V_144 && ! V_147 )
V_4 = F_73 ( V_75 , V_148 , V_149 ) ;
else
V_4 = F_73 ( V_75 , V_150 , 0 ) ;
}
if ( V_4 < 0 ) {
if ( V_67 == V_41 )
F_7 ( L_118
L_119 ) ;
else
F_7 ( L_120 ,
strerror ( V_67 ) ) ;
}
return V_4 ;
}
static struct V_151 * F_74 ( int V_152 )
{
int V_4 , V_153 ;
T_4 * V_71 ;
char V_75 [ V_140 ] ;
char * V_134 ;
struct V_151 * V_154 ;
V_154 = F_75 ( true , NULL ) ;
V_71 = fdopen ( F_76 ( V_152 ) , L_34 ) ;
while ( ! feof ( V_71 ) ) {
V_134 = fgets ( V_75 , V_140 , V_71 ) ;
if ( ! V_134 )
break;
V_153 = strlen ( V_134 ) - 1 ;
if ( V_134 [ V_153 ] == '\n' )
V_134 [ V_153 ] = '\0' ;
V_4 = F_77 ( V_154 , V_75 ) ;
if ( V_4 < 0 ) {
F_3 ( L_121 , strerror ( - V_4 ) ) ;
F_49 ( V_154 ) ;
return NULL ;
}
}
fclose ( V_71 ) ;
return V_154 ;
}
static int F_78 ( struct V_56 * V_57 )
{
int V_53 , V_4 ;
char V_75 [ 128 ] ;
char * V_155 ;
V_155 = F_32 ( & V_57 -> V_55 ) ;
if ( ! V_155 )
return - V_98 ;
V_4 = F_1 ( V_75 , 128 , L_122 , V_57 -> V_116 , V_57 -> V_115 ) ;
if ( V_4 < 0 )
return V_4 ;
printf ( L_123 , V_75 , V_155 ) ;
if ( V_57 -> V_131 > 0 ) {
printf ( L_124 ) ;
for ( V_53 = 0 ; V_53 < V_57 -> V_131 ; V_53 ++ ) {
V_4 = F_64 ( & V_57 -> args [ V_53 ] ,
V_75 , 128 ) ;
if ( V_4 < 0 )
break;
printf ( L_125 , V_75 ) ;
}
}
printf ( L_126 ) ;
free ( V_155 ) ;
return V_4 ;
}
int F_79 ( void )
{
int V_152 , V_4 ;
struct V_50 V_132 ;
struct V_56 V_57 ;
struct V_151 * V_156 ;
struct V_92 * V_157 ;
F_40 () ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_152 = F_71 ( false ) ;
if ( V_152 < 0 )
return V_152 ;
V_156 = F_74 ( V_152 ) ;
F_80 ( V_152 ) ;
if ( ! V_156 )
return - V_41 ;
F_47 (ent, rawlist) {
V_4 = F_63 ( V_157 -> V_100 , & V_132 ) ;
if ( V_4 >= 0 ) {
V_4 = F_68 ( & V_132 , & V_57 ) ;
if ( V_4 >= 0 )
V_4 = F_78 ( & V_57 ) ;
}
F_69 ( & V_57 ) ;
F_70 ( & V_132 ) ;
if ( V_4 < 0 )
break;
}
F_49 ( V_156 ) ;
return V_4 ;
}
static struct V_151 * F_81 ( int V_152 , bool V_158 )
{
char V_75 [ 128 ] ;
struct V_151 * V_154 , * V_156 ;
struct V_92 * V_157 ;
struct V_50 V_132 ;
int V_4 = 0 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_156 = F_74 ( V_152 ) ;
V_154 = F_75 ( true , NULL ) ;
F_47 (ent, rawlist) {
V_4 = F_63 ( V_157 -> V_100 , & V_132 ) ;
if ( V_4 < 0 )
break;
if ( V_158 ) {
V_4 = F_1 ( V_75 , 128 , L_122 , V_132 . V_116 ,
V_132 . V_115 ) ;
if ( V_4 >= 0 )
V_4 = F_77 ( V_154 , V_75 ) ;
} else
V_4 = F_77 ( V_154 , V_132 . V_115 ) ;
F_70 ( & V_132 ) ;
if ( V_4 < 0 )
break;
}
F_49 ( V_156 ) ;
if ( V_4 < 0 ) {
F_49 ( V_154 ) ;
return NULL ;
}
return V_154 ;
}
static int F_82 ( int V_152 , struct V_50 * V_132 )
{
int V_4 = 0 ;
char * V_75 = F_67 ( V_132 ) ;
if ( ! V_75 ) {
F_3 ( L_127 ) ;
return - V_98 ;
}
F_3 ( L_128 , V_75 ) ;
if ( ! V_147 ) {
V_4 = F_83 ( V_152 , V_75 , strlen ( V_75 ) ) ;
if ( V_4 <= 0 )
F_7 ( L_129 ,
strerror ( V_67 ) ) ;
}
free ( V_75 ) ;
return V_4 ;
}
static int F_84 ( char * V_75 , T_1 V_138 , const char * V_159 ,
struct V_151 * V_160 , bool V_161 )
{
int V_53 , V_4 ;
V_4 = F_1 ( V_75 , V_138 , L_26 , V_159 ) ;
if ( V_4 < 0 ) {
F_3 ( L_130 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_85 ( V_160 , V_75 ) )
return 0 ;
if ( ! V_161 ) {
F_7 ( L_131
L_132 , V_159 ) ;
return - V_162 ;
}
for ( V_53 = 1 ; V_53 < V_163 ; V_53 ++ ) {
V_4 = F_1 ( V_75 , V_138 , L_133 , V_159 , V_53 ) ;
if ( V_4 < 0 ) {
F_3 ( L_130 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_85 ( V_160 , V_75 ) )
break;
}
if ( V_53 == V_163 ) {
F_7 ( L_134 ) ;
V_4 = - V_130 ;
}
return V_4 ;
}
static int F_86 ( struct V_56 * V_57 ,
struct V_50 * V_51 ,
int V_52 , bool V_161 )
{
int V_53 , V_152 , V_4 ;
struct V_50 * V_132 = NULL ;
char V_75 [ 64 ] ;
const char * V_115 , * V_116 ;
struct V_151 * V_160 ;
V_152 = F_71 ( true ) ;
if ( V_152 < 0 )
return V_152 ;
V_160 = F_81 ( V_152 , false ) ;
if ( ! V_160 ) {
F_3 ( L_135 ) ;
return - V_164 ;
}
V_4 = 0 ;
printf ( L_136 , ( V_52 > 1 ) ? L_137 : L_114 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_132 = & V_51 [ V_53 ] ;
if ( V_57 -> V_115 )
V_115 = V_57 -> V_115 ;
else
if ( V_57 -> V_55 . V_47 )
V_115 = V_57 -> V_55 . V_47 ;
else
V_115 = V_132 -> V_55 . V_14 ;
if ( V_57 -> V_116 )
V_116 = V_57 -> V_116 ;
else
V_116 = V_165 ;
V_4 = F_84 ( V_75 , 64 , V_115 ,
V_160 , V_161 ) ;
if ( V_4 < 0 )
break;
V_115 = V_75 ;
V_132 -> V_115 = F_27 ( V_115 ) ;
V_132 -> V_116 = F_27 ( V_116 ) ;
if ( V_132 -> V_115 == NULL || V_132 -> V_116 == NULL ) {
V_4 = - V_48 ;
break;
}
V_4 = F_82 ( V_152 , V_132 ) ;
if ( V_4 < 0 )
break;
F_77 ( V_160 , V_115 ) ;
V_115 = V_57 -> V_115 ;
V_116 = V_57 -> V_116 ;
V_57 -> V_115 = V_132 -> V_115 ;
V_57 -> V_116 = V_132 -> V_116 ;
F_78 ( V_57 ) ;
V_57 -> V_115 = ( char * ) V_115 ;
V_57 -> V_116 = ( char * ) V_116 ;
V_161 = true ;
}
if ( V_4 >= 0 ) {
printf ( L_138 ) ;
printf ( L_139 , V_132 -> V_116 ,
V_132 -> V_115 ) ;
}
F_49 ( V_160 ) ;
F_80 ( V_152 ) ;
return V_4 ;
}
static int F_87 ( struct V_56 * V_57 ,
struct V_50 * * V_51 ,
int V_58 , const char * V_18 )
{
struct V_14 * V_39 ;
int V_4 = 0 , V_53 ;
struct V_50 * V_132 ;
V_4 = F_29 ( V_57 , V_51 , V_58 , V_18 ) ;
if ( V_4 != 0 )
return V_4 ;
V_132 = * V_51 = F_59 ( sizeof( struct V_50 ) ) ;
if ( V_132 == NULL )
return - V_48 ;
V_132 -> V_55 . V_14 = F_27 ( V_57 -> V_55 . V_47 ) ;
if ( V_132 -> V_55 . V_14 == NULL ) {
V_4 = - V_48 ;
goto error;
}
if ( V_18 ) {
V_132 -> V_55 . V_18 = F_27 ( V_18 ) ;
if ( V_132 -> V_55 . V_18 == NULL ) {
V_4 = - V_48 ;
goto error;
}
}
V_132 -> V_55 . V_45 = V_57 -> V_55 . V_45 ;
V_132 -> V_55 . V_49 = V_57 -> V_55 . V_49 ;
V_132 -> V_131 = V_57 -> V_131 ;
if ( V_132 -> V_131 ) {
V_132 -> args = F_59 ( sizeof( struct V_135 )
* V_132 -> V_131 ) ;
if ( V_132 -> args == NULL ) {
V_4 = - V_48 ;
goto error;
}
for ( V_53 = 0 ; V_53 < V_132 -> V_131 ; V_53 ++ ) {
if ( V_57 -> args [ V_53 ] . V_15 ) {
V_132 -> args [ V_53 ] . V_15 = F_27 ( V_57 -> args [ V_53 ] . V_15 ) ;
if ( V_132 -> args [ V_53 ] . V_15 == NULL ) {
V_4 = - V_48 ;
goto error;
}
}
V_132 -> args [ V_53 ] . V_136 = F_27 ( V_57 -> args [ V_53 ] . V_97 ) ;
if ( V_132 -> args [ V_53 ] . V_136 == NULL ) {
V_4 = - V_48 ;
goto error;
}
if ( V_57 -> args [ V_53 ] . type ) {
V_132 -> args [ V_53 ] . type = F_27 ( V_57 -> args [ V_53 ] . type ) ;
if ( V_132 -> args [ V_53 ] . type == NULL ) {
V_4 = - V_48 ;
goto error;
}
}
}
}
V_39 = F_8 ( V_132 -> V_55 . V_14 , NULL ) ;
if ( ! V_39 ) {
F_7 ( L_140 ,
V_132 -> V_55 . V_14 ) ;
V_4 = - V_41 ;
goto error;
}
return 1 ;
error:
F_70 ( V_132 ) ;
free ( V_132 ) ;
* V_51 = NULL ;
return V_4 ;
}
int F_88 ( struct V_56 * V_101 , int V_102 ,
int V_58 , const char * V_18 , bool V_166 )
{
int V_53 , V_167 , V_4 ;
struct V_168 * V_169 ;
V_169 = F_59 ( sizeof( struct V_168 ) * V_102 ) ;
if ( V_169 == NULL )
return - V_48 ;
V_4 = F_2 () ;
if ( V_4 < 0 ) {
free ( V_169 ) ;
return V_4 ;
}
for ( V_53 = 0 ; V_53 < V_102 ; V_53 ++ ) {
V_169 [ V_53 ] . V_57 = & V_101 [ V_53 ] ;
V_4 = F_87 ( V_169 [ V_53 ] . V_57 ,
& V_169 [ V_53 ] . V_51 ,
V_58 ,
V_18 ) ;
if ( V_4 < 0 )
goto V_84;
V_169 [ V_53 ] . V_52 = V_4 ;
}
for ( V_53 = 0 ; V_53 < V_102 ; V_53 ++ ) {
V_4 = F_86 ( V_169 [ V_53 ] . V_57 , V_169 [ V_53 ] . V_51 ,
V_169 [ V_53 ] . V_52 , V_166 ) ;
if ( V_4 < 0 )
break;
}
V_84:
for ( V_53 = 0 ; V_53 < V_102 ; V_53 ++ ) {
for ( V_167 = 0 ; V_167 < V_169 [ V_53 ] . V_52 ; V_167 ++ )
F_70 ( & V_169 [ V_53 ] . V_51 [ V_167 ] ) ;
free ( V_169 [ V_53 ] . V_51 ) ;
}
free ( V_169 ) ;
return V_4 ;
}
static int F_89 ( int V_152 , struct V_92 * V_157 )
{
char * V_134 ;
char V_75 [ 128 ] ;
int V_4 ;
V_4 = F_1 ( V_75 , 128 , L_141 , V_157 -> V_100 ) ;
if ( V_4 < 0 )
goto error;
V_134 = strchr ( V_75 + 2 , ':' ) ;
if ( ! V_134 ) {
F_3 ( L_142 ,
V_157 -> V_100 ) ;
V_4 = - V_114 ;
goto error;
}
* V_134 = '/' ;
F_3 ( L_128 , V_75 ) ;
V_4 = F_83 ( V_152 , V_75 , strlen ( V_75 ) ) ;
if ( V_4 < 0 )
goto error;
printf ( L_143 , V_157 -> V_100 ) ;
return 0 ;
error:
F_7 ( L_144 , strerror ( - V_4 ) ) ;
return V_4 ;
}
static int F_90 ( int V_152 , const char * V_116 ,
const char * V_115 , struct V_151 * V_160 )
{
char V_75 [ 128 ] ;
struct V_92 * V_157 , * V_170 ;
int V_30 = 0 , V_4 = 0 ;
V_4 = F_1 ( V_75 , 128 , L_122 , V_116 , V_115 ) ;
if ( V_4 < 0 ) {
F_21 ( L_145 ) ;
return V_4 ;
}
if ( strpbrk ( V_75 , L_146 ) ) {
F_91 (ent, n, namelist)
if ( F_92 ( V_157 -> V_100 , V_75 ) ) {
V_30 ++ ;
V_4 = F_89 ( V_152 , V_157 ) ;
if ( V_4 < 0 )
break;
F_93 ( V_160 , V_157 ) ;
}
} else {
V_157 = F_94 ( V_160 , V_75 ) ;
if ( V_157 ) {
V_30 ++ ;
V_4 = F_89 ( V_152 , V_157 ) ;
if ( V_4 >= 0 )
F_93 ( V_160 , V_157 ) ;
}
}
if ( V_30 == 0 && V_4 >= 0 )
F_95 ( L_147 , V_75 ) ;
return V_4 ;
}
int F_96 ( struct V_151 * V_171 )
{
int V_152 , V_4 = 0 ;
const char * V_116 , * V_115 ;
char * V_134 , * V_1 ;
struct V_92 * V_157 ;
struct V_151 * V_160 ;
V_152 = F_71 ( true ) ;
if ( V_152 < 0 )
return V_152 ;
V_160 = F_81 ( V_152 , true ) ;
if ( V_160 == NULL )
return - V_98 ;
F_47 (ent, dellist) {
V_1 = F_27 ( V_157 -> V_100 ) ;
if ( V_1 == NULL ) {
V_4 = - V_48 ;
break;
}
F_3 ( L_148 , V_1 ) ;
V_134 = strchr ( V_1 , ':' ) ;
if ( V_134 ) {
V_116 = V_1 ;
* V_134 = '\0' ;
V_115 = V_134 + 1 ;
} else {
V_116 = L_149 ;
V_115 = V_1 ;
}
F_3 ( L_150 , V_116 , V_115 ) ;
V_4 = F_90 ( V_152 , V_116 , V_115 , V_160 ) ;
free ( V_1 ) ;
if ( V_4 < 0 )
break;
}
F_49 ( V_160 ) ;
F_80 ( V_152 ) ;
return V_4 ;
}
static int F_97 ( struct V_16 * V_16 V_103 ,
struct V_14 * V_39 )
{
if ( V_39 -> V_172 == V_173 &&
F_48 ( V_174 , V_39 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_98 ( const char * V_18 , struct V_88 * V_89 )
{
struct V_16 * V_16 ;
int V_4 ;
F_40 () ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_16 = F_10 ( V_18 ) ;
if ( ! V_16 ) {
F_21 ( L_151 , ( V_18 ) ? : L_6 ) ;
return - V_98 ;
}
V_174 = V_89 ;
if ( F_99 ( V_16 , F_97 ) ) {
F_21 ( L_152 ) ;
return - V_98 ;
}
if ( ! F_100 ( V_16 -> V_27 , V_16 -> type ) )
F_101 ( V_16 -> V_27 , V_16 -> type ) ;
F_102 ( V_16 -> V_27 , V_16 -> type , stdout ) ;
return 0 ;
}
