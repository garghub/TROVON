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
if ( ! V_18 )
V_18 = L_6 ;
for ( V_20 = F_11 ( & V_22 -> V_24 [ V_25 ] ) ; V_20 ; V_20 = F_12 ( V_20 ) ) {
struct V_16 * V_26 = F_13 ( V_20 , struct V_16 , V_19 ) ;
if ( strncmp ( V_26 -> V_27 -> V_28 + 1 , V_18 ,
V_26 -> V_27 -> V_29 - 2 ) == 0 ) {
return V_26 ;
}
}
return NULL ;
}
static struct V_27 * F_14 ( const char * V_18 )
{
struct V_27 * V_27 ;
struct V_16 * V_16 ;
const char * V_9 ;
if ( V_18 ) {
F_15 (dso, &machine.kernel_dsos, node) {
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
if ( F_16 ( V_27 , V_16 , V_9 , NULL ) <= 0 )
return NULL ;
} else {
if ( F_17 ( V_27 , V_16 , NULL ) <= 0 ) {
F_3 ( L_8 ) ;
return NULL ;
}
}
V_30:
return V_27 ;
}
const char * F_18 ( const char * V_18 )
{
struct V_27 * V_27 = F_14 ( V_18 ) ;
return ( V_27 ) ? V_27 -> V_32 : NULL ;
}
static int F_19 ( const char * V_18 )
{
const char * V_33 = F_18 ( V_18 ) ;
if ( ! V_33 ) {
F_20 ( L_9 ,
V_18 ? : L_6 ) ;
return - V_34 ;
}
F_3 ( L_10 , V_33 ) ;
return F_21 ( V_33 , V_35 ) ;
}
static int F_22 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_14 * V_40 ;
struct V_16 * V_16 ;
T_3 V_41 ;
int V_4 = - V_34 ;
V_40 = F_8 ( V_37 -> V_14 , & V_16 ) ;
if ( V_40 ) {
V_41 = V_16 -> V_42 ( V_16 , V_40 -> V_43 + V_37 -> V_44 ) ;
F_3 ( L_11 V_45 L_12 , V_37 -> V_14 ,
V_37 -> V_44 , V_41 ) ;
V_4 = F_23 ( ( unsigned long ) V_41 , V_39 ) ;
}
if ( V_4 <= 0 ) {
F_3 ( L_13
L_14 ) ;
V_39 -> V_46 = F_24 ( V_37 -> V_14 ) ;
if ( V_39 -> V_46 == NULL )
return - V_47 ;
V_39 -> V_44 = V_37 -> V_44 ;
}
V_39 -> V_48 = V_37 -> V_48 ;
return 0 ;
}
static int F_25 ( struct V_49 * V_50 ,
struct V_51 * * V_52 ,
int V_53 , const char * V_18 )
{
bool V_54 = F_26 ( V_50 ) ;
int V_55 , V_56 ;
V_55 = F_19 ( V_18 ) ;
if ( V_55 < 0 ) {
if ( V_54 ) {
F_7 ( L_15 ) ;
return V_55 ;
}
F_3 ( L_16 ) ;
return 0 ;
}
V_56 = F_27 ( V_55 , V_50 , V_52 , V_53 ) ;
if ( V_56 > 0 ) {
F_3 ( L_17 , V_56 ) ;
return V_56 ;
}
if ( V_56 == 0 ) {
F_7 ( L_18 ,
F_28 ( & V_50 -> V_57 ) ) ;
return - V_34 ;
}
F_3 ( L_19 , V_56 ) ;
if ( V_56 == - V_58 ) {
F_7 ( L_20
L_21 ) ;
if ( ! V_54 ) {
F_3 ( L_22 ) ;
return 0 ;
}
}
return V_56 ;
}
static int F_29 ( const char * V_59 , const char * V_60 ,
char * * V_61 )
{
const char * V_62 = V_7 . V_63 ;
if ( ! V_62 ) {
if ( V_59 [ 0 ] != '/' && V_60 )
V_62 = V_60 ;
else {
if ( F_30 ( V_59 , V_64 ) == 0 ) {
* V_61 = F_24 ( V_59 ) ;
return 0 ;
} else
return - V_65 ;
}
}
* V_61 = malloc ( ( strlen ( V_62 ) + strlen ( V_59 ) + 2 ) ) ;
if ( ! * V_61 )
return - V_47 ;
for (; ; ) {
sprintf ( * V_61 , L_23 , V_62 , V_59 ) ;
if ( F_30 ( * V_61 , V_64 ) == 0 )
return 0 ;
if ( ! V_7 . V_63 )
return - V_65 ;
switch ( V_65 ) {
case V_66 :
case V_34 :
case V_67 :
case V_68 :
V_59 = strchr ( ++ V_59 , '/' ) ;
if ( ! V_59 ) {
free ( * V_61 ) ;
* V_61 = NULL ;
return - V_34 ;
}
continue;
default:
free ( * V_61 ) ;
* V_61 = NULL ;
return - V_65 ;
}
}
}
static int F_31 ( T_4 * V_69 , int V_70 , bool V_71 , bool V_72 )
{
char V_73 [ V_74 ] ;
const char * V_75 = V_72 ? L_3 : V_76 ;
const char * V_62 = NULL ;
do {
if ( fgets ( V_73 , V_74 , V_69 ) == NULL )
goto error;
if ( V_71 )
continue;
if ( ! V_62 ) {
V_62 = V_72 ? L_24 : L_25 ;
F_32 ( stdout , V_75 , V_62 , V_70 ) ;
}
F_32 ( stdout , V_75 , L_26 , V_73 ) ;
} while ( strchr ( V_73 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_69 ) ) {
F_7 ( L_27 , strerror ( V_65 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_33 ( T_4 * V_69 , int V_70 , bool V_71 , bool V_72 )
{
int V_77 = F_31 ( V_69 , V_70 , V_71 , V_72 ) ;
if ( V_77 == 0 ) {
F_7 ( L_28 ) ;
V_77 = - 1 ;
}
return V_77 ;
}
int F_34 ( struct V_78 * V_79 , const char * V_18 )
{
int V_70 = 1 ;
struct V_80 * V_81 ;
T_4 * V_69 ;
int V_55 , V_4 ;
char * V_82 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_55 = F_19 ( V_18 ) ;
if ( V_55 < 0 ) {
F_7 ( L_15 ) ;
return V_55 ;
}
V_4 = F_35 ( V_55 , V_79 ) ;
if ( V_4 == 0 ) {
F_7 ( L_29 ) ;
return - V_34 ;
} else if ( V_4 < 0 ) {
F_7 ( L_30 , V_4 ) ;
return V_4 ;
}
V_82 = V_79 -> V_33 ;
V_4 = F_29 ( V_82 , V_79 -> V_60 , & V_79 -> V_33 ) ;
free ( V_82 ) ;
if ( V_4 < 0 ) {
F_7 ( L_31 , V_4 ) ;
return V_4 ;
}
F_36 () ;
if ( V_79 -> V_46 )
fprintf ( stdout , L_32 , V_79 -> V_46 , V_79 -> V_33 ,
V_79 -> V_43 - V_79 -> V_44 ) ;
else
fprintf ( stdout , L_33 , V_79 -> V_33 , V_79 -> V_43 ) ;
V_69 = fopen ( V_79 -> V_33 , L_34 ) ;
if ( V_69 == NULL ) {
F_7 ( L_35 , V_79 -> V_33 ,
strerror ( V_65 ) ) ;
return - V_65 ;
}
while ( V_70 < V_79 -> V_43 ) {
V_4 = F_37 ( V_69 , V_70 ++ ) ;
if ( V_4 < 0 )
goto V_83;
}
F_15 (ln, &lr->line_list, list) {
for (; V_81 -> line > V_70 ; V_70 ++ ) {
V_4 = F_38 ( V_69 , V_70 - V_79 -> V_44 ) ;
if ( V_4 < 0 )
goto V_83;
}
V_4 = F_39 ( V_69 , V_70 ++ - V_79 -> V_44 ) ;
if ( V_4 < 0 )
goto V_83;
}
if ( V_79 -> V_83 == V_84 )
V_79 -> V_83 = V_70 + V_85 ;
while ( V_70 <= V_79 -> V_83 ) {
V_4 = F_40 ( V_69 , V_70 ++ - V_79 -> V_44 ) ;
if ( V_4 <= 0 )
break;
}
V_83:
fclose ( V_69 ) ;
return V_4 ;
}
static int F_41 ( int V_55 , struct V_49 * V_50 ,
int V_86 , struct V_87 * V_88 ,
bool V_89 )
{
char * V_73 ;
int V_4 , V_90 , V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 = NULL , * V_96 ;
const char * V_97 ;
V_73 = F_28 ( & V_50 -> V_57 ) ;
if ( ! V_73 )
return - V_98 ;
F_3 ( L_36 , V_73 ) ;
V_4 = F_42 ( V_55 , V_50 , & V_95 , V_86 , V_89 ) ;
if ( V_4 <= 0 ) {
F_20 ( L_37 , V_73 , V_4 ) ;
goto V_83;
}
fprintf ( stdout , L_38 , V_73 ) ;
for ( V_90 = 0 ; V_90 < V_4 ; V_90 ++ ) {
V_96 = & V_95 [ V_90 ] ;
fprintf ( stdout , L_39 , V_96 -> V_57 . V_14 ,
V_96 -> V_57 . V_44 ) ;
free ( V_96 -> V_57 . V_14 ) ;
V_91 = 0 ;
if ( V_96 -> V_99 ) {
F_43 (node, vl->vars) {
V_97 = strchr ( V_93 -> V_100 , '\t' ) + 1 ;
if ( F_44 ( V_88 , V_97 ) ) {
fprintf ( stdout , L_40 , V_93 -> V_100 ) ;
V_91 ++ ;
}
}
F_45 ( V_96 -> V_99 ) ;
}
if ( V_91 == 0 )
fprintf ( stdout , L_41 ) ;
}
free ( V_95 ) ;
V_83:
free ( V_73 ) ;
return V_4 ;
}
int F_46 ( struct V_49 * V_101 , int V_102 ,
int V_86 , const char * V_18 ,
struct V_87 * V_88 , bool V_89 )
{
int V_90 , V_55 , V_4 = 0 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
F_36 () ;
for ( V_90 = 0 ; V_90 < V_102 && V_4 >= 0 ; V_90 ++ ) {
V_55 = F_19 ( V_18 ) ;
if ( V_55 < 0 ) {
F_7 ( L_42 ) ;
V_4 = V_55 ;
break;
}
V_4 = F_41 ( V_55 , & V_101 [ V_90 ] , V_86 , V_88 ,
V_89 ) ;
}
return V_4 ;
}
static int F_22 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_14 * V_40 ;
V_40 = F_8 ( V_37 -> V_14 , NULL ) ;
if ( ! V_40 ) {
F_20 ( L_43 , V_37 -> V_14 ) ;
return - V_34 ;
}
V_39 -> V_46 = F_24 ( V_37 -> V_14 ) ;
if ( V_39 -> V_46 == NULL )
return - V_47 ;
V_39 -> V_44 = V_37 -> V_44 ;
V_39 -> V_48 = V_37 -> V_48 ;
return 0 ;
}
static int F_25 ( struct V_49 * V_50 ,
struct V_51 * * V_52 V_103 ,
int V_53 V_103 , const char * T_5 V_103 )
{
if ( F_26 ( V_50 ) ) {
F_7 ( L_44 ) ;
return - V_104 ;
}
return 0 ;
}
int F_34 ( struct V_78 * V_79 V_103 , const char * V_18 V_103 )
{
F_7 ( L_44 ) ;
return - V_104 ;
}
int F_46 ( struct V_49 * V_101 V_103 ,
int V_102 V_103 , int V_86 V_103 ,
const char * V_18 V_103 ,
struct V_87 * T_6 V_103 ,
bool V_89 V_103 )
{
F_7 ( L_44 ) ;
return - V_104 ;
}
static int F_47 ( char * * V_105 , int * V_106 , const char * V_107 )
{
const char * V_43 = * V_105 ;
V_65 = 0 ;
* V_106 = strtol ( * V_105 , V_105 , 0 ) ;
if ( V_65 || * V_105 == V_43 ) {
F_48 ( L_45 , V_107 ) ;
return - V_98 ;
}
return 0 ;
}
int F_49 ( const char * V_108 , struct V_78 * V_79 )
{
char * V_109 , * V_110 , * V_15 = F_24 ( V_108 ) ;
int V_111 ;
if ( ! V_15 )
return - V_47 ;
V_79 -> V_43 = 0 ;
V_79 -> V_83 = V_84 ;
V_109 = strchr ( V_15 , ':' ) ;
if ( V_109 ) {
* V_109 ++ = '\0' ;
V_111 = F_47 ( & V_109 , & V_79 -> V_43 , L_46 ) ;
if ( V_111 )
goto V_111;
if ( * V_109 == '+' || * V_109 == '-' ) {
const char V_112 = * V_109 ++ ;
V_111 = F_47 ( & V_109 , & V_79 -> V_83 , L_47 ) ;
if ( V_111 )
goto V_111;
if ( V_112 == '+' ) {
V_79 -> V_83 += V_79 -> V_43 ;
V_79 -> V_83 -- ;
}
}
F_3 ( L_48 , V_79 -> V_43 , V_79 -> V_83 ) ;
V_111 = - V_98 ;
if ( V_79 -> V_43 > V_79 -> V_83 ) {
F_48 ( L_49
L_50 ) ;
goto V_111;
}
if ( * V_109 != '\0' ) {
F_48 ( L_51 , V_109 ) ;
goto V_111;
}
}
V_110 = strchr ( V_15 , '@' ) ;
if ( V_110 ) {
* V_110 = '\0' ;
V_79 -> V_110 = F_24 ( ++ V_110 ) ;
if ( V_79 -> V_110 == NULL ) {
V_111 = - V_47 ;
goto V_111;
}
V_79 -> V_46 = V_15 ;
} else if ( strchr ( V_15 , '.' ) )
V_79 -> V_110 = V_15 ;
else
V_79 -> V_46 = V_15 ;
return 0 ;
V_111:
free ( V_15 ) ;
return V_111 ;
}
static bool F_50 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
static int F_51 ( char * V_108 , struct V_49 * V_50 )
{
struct V_38 * V_39 = & V_50 -> V_57 ;
char * V_105 , * V_82 ;
char V_112 , V_113 = 0 ;
V_105 = strpbrk ( V_108 , L_52 ) ;
if ( V_105 && * V_105 == '=' ) {
* V_105 = '\0' ;
V_82 = V_105 + 1 ;
if ( strchr ( V_108 , ':' ) ) {
F_48 ( L_53 ) ;
return - V_114 ;
}
if ( ! F_50 ( V_108 ) ) {
F_48 ( L_54
L_55 , V_108 ) ;
return - V_98 ;
}
V_50 -> V_115 = F_24 ( V_108 ) ;
if ( V_50 -> V_115 == NULL )
return - V_47 ;
V_50 -> V_116 = NULL ;
V_108 = V_82 ;
}
V_105 = strpbrk ( V_108 , L_56 ) ;
if ( V_105 ) {
V_113 = * V_105 ;
* V_105 ++ = '\0' ;
}
V_82 = F_24 ( V_108 ) ;
if ( V_82 == NULL )
return - V_47 ;
if ( strchr ( V_82 , '.' ) )
V_39 -> V_110 = V_82 ;
else
V_39 -> V_46 = V_82 ;
while ( V_105 ) {
V_108 = V_105 ;
V_112 = V_113 ;
if ( V_112 == ';' ) {
V_39 -> V_117 = F_24 ( V_108 ) ;
if ( V_39 -> V_117 == NULL )
return - V_47 ;
break;
}
V_105 = strpbrk ( V_108 , L_56 ) ;
if ( V_105 ) {
V_113 = * V_105 ;
* V_105 ++ = '\0' ;
}
switch ( V_112 ) {
case ':' :
V_39 -> line = strtoul ( V_108 , & V_82 , 0 ) ;
if ( * V_82 != '\0' ) {
F_48 ( L_57
L_58 ) ;
return - V_98 ;
}
break;
case '+' :
V_39 -> V_44 = strtoul ( V_108 , & V_82 , 0 ) ;
if ( * V_82 != '\0' ) {
F_48 ( L_59
L_60 ) ;
return - V_98 ;
}
break;
case '@' :
if ( V_39 -> V_110 ) {
F_48 ( L_61 ) ;
return - V_98 ;
}
V_39 -> V_110 = F_24 ( V_108 ) ;
if ( V_39 -> V_110 == NULL )
return - V_47 ;
break;
case '%' :
if ( strcmp ( V_108 , L_62 ) == 0 ) {
V_39 -> V_48 = 1 ;
} else {
F_48 ( L_63 , V_108 ) ;
return - V_114 ;
}
break;
default:
F_20 ( L_64 ,
__FILE__ , __LINE__ ) ;
return - V_114 ;
break;
}
}
if ( V_39 -> V_117 && V_39 -> line ) {
F_48 ( L_65
L_66 ) ;
return - V_98 ;
}
if ( V_39 -> V_117 && V_39 -> V_44 ) {
F_48 ( L_67 ) ;
return - V_98 ;
}
if ( V_39 -> line && V_39 -> V_44 ) {
F_48 ( L_68 ) ;
return - V_98 ;
}
if ( ! V_39 -> line && ! V_39 -> V_117 && V_39 -> V_110 && ! V_39 -> V_46 ) {
F_48 ( L_69
L_70 ) ;
return - V_98 ;
}
if ( V_39 -> V_44 && ! V_39 -> V_46 ) {
F_48 ( L_71 ) ;
return - V_98 ;
}
if ( V_39 -> V_48 && ! V_39 -> V_46 ) {
F_48 ( L_72 ) ;
return - V_98 ;
}
if ( ( V_39 -> V_44 || V_39 -> line || V_39 -> V_117 ) && V_39 -> V_48 ) {
F_48 ( L_73
L_74 ) ;
return - V_98 ;
}
F_3 ( L_75 ,
V_39 -> V_46 , V_39 -> V_110 , V_39 -> line , V_39 -> V_44 , V_39 -> V_48 ,
V_39 -> V_117 ) ;
return 0 ;
}
static int F_52 ( char * V_1 , struct V_118 * V_108 )
{
char * V_82 , * V_119 ;
struct V_120 * * V_121 ;
F_3 ( L_76 , V_1 ) ;
V_82 = strchr ( V_1 , '=' ) ;
if ( V_82 ) {
V_108 -> V_15 = F_53 ( V_1 , V_82 - V_1 ) ;
if ( V_108 -> V_15 == NULL )
return - V_47 ;
F_3 ( L_77 , V_108 -> V_15 ) ;
V_1 = V_82 + 1 ;
}
V_82 = strchr ( V_1 , ':' ) ;
if ( V_82 ) {
* V_82 = '\0' ;
V_108 -> type = F_24 ( V_82 + 1 ) ;
if ( V_108 -> type == NULL )
return - V_47 ;
F_3 ( L_78 , V_108 -> type ) ;
}
V_82 = strpbrk ( V_1 , L_79 ) ;
if ( ! F_54 ( V_1 ) || ! V_82 ) {
V_108 -> V_97 = F_24 ( V_1 ) ;
if ( V_108 -> V_97 == NULL )
return - V_47 ;
F_3 ( L_80 , V_108 -> V_97 ) ;
return 0 ;
}
V_108 -> V_97 = F_53 ( V_1 , V_82 - V_1 ) ;
if ( V_108 -> V_97 == NULL )
return - V_47 ;
V_119 = V_108 -> V_97 ;
F_3 ( L_81 , V_108 -> V_97 ) ;
V_121 = & V_108 -> V_122 ;
do {
* V_121 = F_55 ( sizeof( struct V_120 ) ) ;
if ( * V_121 == NULL )
return - V_47 ;
if ( * V_82 == '[' ) {
V_1 = V_82 ;
( * V_121 ) -> V_123 = strtol ( V_1 + 1 , & V_82 , 0 ) ;
( * V_121 ) -> V_124 = true ;
if ( * V_82 != ']' || V_82 == V_1 + 1 ) {
F_48 ( L_82
L_83 ) ;
return - V_98 ;
}
V_82 ++ ;
if ( * V_82 == '\0' )
V_82 = NULL ;
} else {
if ( * V_82 == '.' ) {
V_1 = V_82 + 1 ;
( * V_121 ) -> V_124 = false ;
} else if ( V_82 [ 1 ] == '>' ) {
V_1 = V_82 + 2 ;
( * V_121 ) -> V_124 = true ;
} else {
F_48 ( L_84 ,
V_1 ) ;
return - V_98 ;
}
V_82 = strpbrk ( V_1 , L_79 ) ;
}
if ( V_82 ) {
( * V_121 ) -> V_15 = F_53 ( V_1 , V_82 - V_1 ) ;
if ( ( * V_121 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_119 = ( * V_121 ) -> V_15 ;
F_3 ( L_85 , ( * V_121 ) -> V_15 , ( * V_121 ) -> V_124 ) ;
V_121 = & ( * V_121 ) -> V_125 ;
}
} while ( V_82 );
( * V_121 ) -> V_15 = F_24 ( V_1 ) ;
if ( ( * V_121 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_119 = ( * V_121 ) -> V_15 ;
F_3 ( L_86 , ( * V_121 ) -> V_15 , ( * V_121 ) -> V_124 ) ;
if ( ! V_108 -> V_15 ) {
V_108 -> V_15 = F_24 ( V_119 ) ;
if ( V_108 -> V_15 == NULL )
return - V_47 ;
}
return 0 ;
}
int F_56 ( const char * V_126 , struct V_49 * V_50 )
{
char * * V_127 ;
int V_128 , V_90 , V_4 = 0 ;
V_127 = F_57 ( V_126 , & V_128 ) ;
if ( ! V_127 ) {
F_3 ( L_87 ) ;
return - V_47 ;
}
if ( V_128 - 1 > V_129 ) {
F_48 ( L_88 , V_128 - 1 ) ;
V_4 = - V_130 ;
goto V_11;
}
V_4 = F_51 ( V_127 [ 0 ] , V_50 ) ;
if ( V_4 < 0 )
goto V_11;
V_50 -> V_131 = V_128 - 1 ;
V_50 -> args = F_55 ( sizeof( struct V_118 ) * V_50 -> V_131 ) ;
if ( V_50 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_90 = 0 ; V_90 < V_50 -> V_131 && V_4 >= 0 ; V_90 ++ ) {
V_4 = F_52 ( V_127 [ V_90 + 1 ] , & V_50 -> args [ V_90 ] ) ;
if ( V_4 >= 0 &&
F_54 ( V_50 -> args [ V_90 ] . V_97 ) && V_50 -> V_57 . V_48 ) {
F_48 ( L_89
L_90 ) ;
V_4 = - V_98 ;
}
}
V_11:
F_58 ( V_127 ) ;
return V_4 ;
}
bool F_26 ( struct V_49 * V_50 )
{
int V_90 ;
if ( V_50 -> V_57 . V_110 || V_50 -> V_57 . line || V_50 -> V_57 . V_117 )
return true ;
for ( V_90 = 0 ; V_90 < V_50 -> V_131 ; V_90 ++ )
if ( F_54 ( V_50 -> args [ V_90 ] . V_97 ) )
return true ;
return false ;
}
static int F_59 ( const char * V_126 ,
struct V_51 * V_132 )
{
struct V_36 * V_37 = & V_132 -> V_57 ;
char V_133 ;
char * V_134 ;
int V_4 , V_90 , V_128 ;
char * * V_127 ;
F_3 ( L_91 , V_126 ) ;
V_127 = F_57 ( V_126 , & V_128 ) ;
if ( ! V_127 ) {
F_3 ( L_87 ) ;
return - V_47 ;
}
if ( V_128 < 2 ) {
F_48 ( L_92 ) ;
V_4 = - V_130 ;
goto V_11;
}
V_4 = sscanf ( V_127 [ 0 ] , L_93 ,
& V_133 , ( float * ) ( void * ) & V_132 -> V_116 ,
( float * ) ( void * ) & V_132 -> V_115 ) ;
if ( V_4 != 3 ) {
F_48 ( L_94 , V_127 [ 0 ] ) ;
V_4 = - V_98 ;
goto V_11;
}
F_3 ( L_95 , V_132 -> V_116 , V_132 -> V_115 , V_133 ) ;
V_37 -> V_48 = ( V_133 == 'r' ) ;
V_4 = sscanf ( V_127 [ 1 ] , L_96 , ( float * ) ( void * ) & V_37 -> V_14 ,
& V_37 -> V_44 ) ;
if ( V_4 == 1 )
V_37 -> V_44 = 0 ;
V_132 -> V_131 = V_128 - 2 ;
V_132 -> args = F_55 ( sizeof( struct V_135 ) * V_132 -> V_131 ) ;
if ( V_132 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_90 = 0 ; V_90 < V_132 -> V_131 ; V_90 ++ ) {
V_134 = strchr ( V_127 [ V_90 + 2 ] , '=' ) ;
if ( V_134 )
* V_134 ++ = '\0' ;
else
V_134 = V_127 [ V_90 + 2 ] ;
V_132 -> args [ V_90 ] . V_15 = F_24 ( V_127 [ V_90 + 2 ] ) ;
V_132 -> args [ V_90 ] . V_136 = F_24 ( V_134 ) ;
if ( V_132 -> args [ V_90 ] . V_15 == NULL || V_132 -> args [ V_90 ] . V_136 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
F_58 ( V_127 ) ;
return V_4 ;
}
int F_60 ( struct V_118 * V_137 , char * V_73 , T_1 V_138 )
{
struct V_120 * V_122 = V_137 -> V_122 ;
int V_4 ;
char * V_82 = V_73 ;
if ( V_137 -> V_15 && V_137 -> V_97 )
V_4 = F_1 ( V_82 , V_138 , L_97 , V_137 -> V_15 , V_137 -> V_97 ) ;
else
V_4 = F_1 ( V_82 , V_138 , L_26 , V_137 -> V_15 ? V_137 -> V_15 : V_137 -> V_97 ) ;
if ( V_4 <= 0 )
goto error;
V_82 += V_4 ;
V_138 -= V_4 ;
while ( V_122 ) {
if ( V_122 -> V_15 [ 0 ] == '[' )
V_4 = F_1 ( V_82 , V_138 , L_26 , V_122 -> V_15 ) ;
else
V_4 = F_1 ( V_82 , V_138 , L_98 ,
V_122 -> V_124 ? L_99 : L_100 , V_122 -> V_15 ) ;
if ( V_4 <= 0 )
goto error;
V_82 += V_4 ;
V_138 -= V_4 ;
V_122 = V_122 -> V_125 ;
}
if ( V_137 -> type ) {
V_4 = F_1 ( V_82 , V_138 , L_101 , V_137 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_82 += V_4 ;
V_138 -= V_4 ;
}
return V_82 - V_73 ;
error:
F_3 ( L_102 ,
strerror ( - V_4 ) ) ;
return V_4 ;
}
static char * F_28 ( struct V_38 * V_39 )
{
char * V_73 , * V_82 ;
char V_139 [ 32 ] = L_3 , line [ 32 ] = L_3 , V_110 [ 32 ] = L_3 ;
int V_4 , V_138 ;
V_73 = F_55 ( V_140 ) ;
if ( V_73 == NULL ) {
V_4 = - V_47 ;
goto error;
}
if ( V_39 -> V_44 ) {
V_4 = F_1 ( V_139 , 32 , L_103 , V_39 -> V_44 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_39 -> line ) {
V_4 = F_1 ( line , 32 , L_104 , V_39 -> line ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_39 -> V_110 ) {
V_82 = V_39 -> V_110 ;
V_138 = strlen ( V_82 ) ;
if ( V_138 > 30 ) {
V_82 = strchr ( V_39 -> V_110 + V_138 - 30 , '/' ) ;
V_82 = V_82 ? V_82 + 1 : V_39 -> V_110 + V_138 - 30 ;
}
V_4 = F_1 ( V_110 , 32 , L_105 , V_82 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_39 -> V_46 )
V_4 = F_1 ( V_73 , V_140 , L_106 , V_39 -> V_46 ,
V_139 , V_39 -> V_48 ? L_107 : L_3 , line ,
V_110 ) ;
else
V_4 = F_1 ( V_73 , V_140 , L_98 , V_110 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_73 ;
error:
F_3 ( L_108 ,
strerror ( - V_4 ) ) ;
if ( V_73 )
free ( V_73 ) ;
return NULL ;
}
static int F_61 ( struct V_141 * V_124 ,
char * * V_73 , T_1 * V_142 ,
int V_143 )
{
int V_4 ;
if ( V_124 -> V_125 ) {
V_143 = F_61 ( V_124 -> V_125 , V_73 ,
V_142 , V_143 + 1 ) ;
if ( V_143 < 0 )
goto V_11;
}
V_4 = F_1 ( * V_73 , * V_142 , L_109 , V_124 -> V_44 ) ;
if ( V_4 < 0 )
V_143 = V_4 ;
else {
* V_73 += V_4 ;
* V_142 -= V_4 ;
}
V_11:
return V_143 ;
}
static int F_62 ( struct V_135 * V_108 ,
char * V_73 , T_1 V_142 )
{
struct V_141 * V_124 = V_108 -> V_124 ;
int V_4 , V_143 = 0 ;
char * V_82 = V_73 ;
if ( V_108 -> V_15 )
V_4 = F_1 ( V_73 , V_142 , L_110 , V_108 -> V_15 ) ;
else
V_4 = F_1 ( V_73 , V_142 , L_111 ) ;
if ( V_4 < 0 )
return V_4 ;
V_73 += V_4 ;
V_142 -= V_4 ;
if ( V_108 -> V_136 [ 0 ] == '@' && V_108 -> V_124 )
V_124 = V_124 -> V_125 ;
if ( V_124 ) {
V_143 = F_61 ( V_124 , & V_73 ,
& V_142 , 1 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_108 -> V_136 [ 0 ] == '@' && V_108 -> V_124 )
V_4 = F_1 ( V_73 , V_142 , L_112 , V_108 -> V_136 ,
V_108 -> V_124 -> V_44 ) ;
else
V_4 = F_1 ( V_73 , V_142 , L_26 , V_108 -> V_136 ) ;
if ( V_4 < 0 )
return V_4 ;
V_73 += V_4 ;
V_142 -= V_4 ;
while ( V_143 -- ) {
V_4 = F_1 ( V_73 , V_142 , L_113 ) ;
if ( V_4 < 0 )
return V_4 ;
V_73 += V_4 ;
V_142 -= V_4 ;
}
if ( V_108 -> type ) {
V_4 = F_1 ( V_73 , V_142 , L_101 , V_108 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_73 += V_4 ;
}
return V_73 - V_82 ;
}
char * F_63 ( struct V_51 * V_132 )
{
struct V_36 * V_37 = & V_132 -> V_57 ;
char * V_73 ;
int V_90 , V_138 , V_4 ;
V_73 = F_55 ( V_140 ) ;
if ( V_73 == NULL )
return NULL ;
V_138 = F_1 ( V_73 , V_140 , L_114 ,
V_37 -> V_48 ? 'r' : 'p' ,
V_132 -> V_116 , V_132 -> V_115 ,
V_37 -> V_14 , V_37 -> V_44 ) ;
if ( V_138 <= 0 )
goto error;
for ( V_90 = 0 ; V_90 < V_132 -> V_131 ; V_90 ++ ) {
V_4 = F_62 ( & V_132 -> args [ V_90 ] , V_73 + V_138 ,
V_140 - V_138 ) ;
if ( V_4 <= 0 )
goto error;
V_138 += V_4 ;
}
return V_73 ;
error:
free ( V_73 ) ;
return NULL ;
}
static int F_64 ( struct V_51 * V_132 ,
struct V_49 * V_50 )
{
char V_73 [ 64 ] = L_3 ;
int V_90 , V_4 ;
V_50 -> V_115 = F_24 ( V_132 -> V_115 ) ;
V_50 -> V_116 = F_24 ( V_132 -> V_116 ) ;
if ( V_50 -> V_115 == NULL || V_50 -> V_116 == NULL )
return - V_47 ;
V_4 = F_22 ( & V_132 -> V_57 , & V_50 -> V_57 ) ;
if ( V_4 < 0 )
return V_4 ;
V_50 -> V_131 = V_132 -> V_131 ;
V_50 -> args = F_55 ( sizeof( struct V_118 ) * V_50 -> V_131 ) ;
if ( V_50 -> args == NULL )
return - V_47 ;
for ( V_90 = 0 ; V_90 < V_132 -> V_131 && V_4 >= 0 ; V_90 ++ ) {
if ( V_132 -> args [ V_90 ] . V_15 )
V_50 -> args [ V_90 ] . V_15 = F_24 ( V_132 -> args [ V_90 ] . V_15 ) ;
else {
V_4 = F_62 ( & V_132 -> args [ V_90 ] ,
V_73 , 64 ) ;
V_50 -> args [ V_90 ] . V_15 = F_24 ( V_73 ) ;
}
if ( V_50 -> args [ V_90 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_47 ;
}
if ( V_4 < 0 )
F_65 ( V_50 ) ;
return V_4 ;
}
void F_65 ( struct V_49 * V_50 )
{
struct V_38 * V_39 = & V_50 -> V_57 ;
struct V_120 * V_122 , * V_125 ;
int V_90 ;
if ( V_50 -> V_115 )
free ( V_50 -> V_115 ) ;
if ( V_50 -> V_116 )
free ( V_50 -> V_116 ) ;
if ( V_39 -> V_110 )
free ( V_39 -> V_110 ) ;
if ( V_39 -> V_46 )
free ( V_39 -> V_46 ) ;
if ( V_39 -> V_117 )
free ( V_39 -> V_117 ) ;
for ( V_90 = 0 ; V_90 < V_50 -> V_131 ; V_90 ++ ) {
if ( V_50 -> args [ V_90 ] . V_15 )
free ( V_50 -> args [ V_90 ] . V_15 ) ;
if ( V_50 -> args [ V_90 ] . V_97 )
free ( V_50 -> args [ V_90 ] . V_97 ) ;
if ( V_50 -> args [ V_90 ] . type )
free ( V_50 -> args [ V_90 ] . type ) ;
V_122 = V_50 -> args [ V_90 ] . V_122 ;
while ( V_122 ) {
V_125 = V_122 -> V_125 ;
if ( V_122 -> V_15 )
free ( V_122 -> V_15 ) ;
free ( V_122 ) ;
V_122 = V_125 ;
}
}
if ( V_50 -> args )
free ( V_50 -> args ) ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
}
static void F_66 ( struct V_51 * V_132 )
{
struct V_141 * V_124 , * V_125 ;
int V_90 ;
if ( V_132 -> V_115 )
free ( V_132 -> V_115 ) ;
if ( V_132 -> V_116 )
free ( V_132 -> V_116 ) ;
if ( V_132 -> V_57 . V_14 )
free ( V_132 -> V_57 . V_14 ) ;
for ( V_90 = 0 ; V_90 < V_132 -> V_131 ; V_90 ++ ) {
if ( V_132 -> args [ V_90 ] . V_15 )
free ( V_132 -> args [ V_90 ] . V_15 ) ;
if ( V_132 -> args [ V_90 ] . V_136 )
free ( V_132 -> args [ V_90 ] . V_136 ) ;
if ( V_132 -> args [ V_90 ] . type )
free ( V_132 -> args [ V_90 ] . type ) ;
V_124 = V_132 -> args [ V_90 ] . V_124 ;
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
static int F_67 ( bool V_144 )
{
char V_73 [ V_145 ] ;
const char * V_146 ;
int V_4 ;
V_146 = F_68 () ;
if ( V_146 == NULL ) {
F_7 ( L_115 ) ;
return - V_34 ;
}
V_4 = F_1 ( V_73 , V_145 , L_116 , V_146 ) ;
if ( V_4 >= 0 ) {
F_3 ( L_117 , V_73 , V_144 ) ;
if ( V_144 && ! V_147 )
V_4 = F_21 ( V_73 , V_148 , V_149 ) ;
else
V_4 = F_21 ( V_73 , V_35 , 0 ) ;
}
if ( V_4 < 0 ) {
if ( V_65 == V_34 )
F_7 ( L_118
L_119 ) ;
else
F_7 ( L_120 ,
strerror ( V_65 ) ) ;
}
return V_4 ;
}
static struct V_150 * F_69 ( int V_55 )
{
int V_4 , V_151 ;
T_4 * V_69 ;
char V_73 [ V_140 ] ;
char * V_134 ;
struct V_150 * V_152 ;
V_152 = F_70 ( true , NULL ) ;
V_69 = fdopen ( F_71 ( V_55 ) , L_34 ) ;
while ( ! feof ( V_69 ) ) {
V_134 = fgets ( V_73 , V_140 , V_69 ) ;
if ( ! V_134 )
break;
V_151 = strlen ( V_134 ) - 1 ;
if ( V_134 [ V_151 ] == '\n' )
V_134 [ V_151 ] = '\0' ;
V_4 = F_72 ( V_152 , V_73 ) ;
if ( V_4 < 0 ) {
F_3 ( L_121 , strerror ( - V_4 ) ) ;
F_45 ( V_152 ) ;
return NULL ;
}
}
fclose ( V_69 ) ;
return V_152 ;
}
static int F_73 ( struct V_49 * V_50 )
{
int V_90 , V_4 ;
char V_73 [ 128 ] ;
char * V_153 ;
V_153 = F_28 ( & V_50 -> V_57 ) ;
if ( ! V_153 )
return - V_98 ;
V_4 = F_1 ( V_73 , 128 , L_122 , V_50 -> V_116 , V_50 -> V_115 ) ;
if ( V_4 < 0 )
return V_4 ;
printf ( L_123 , V_73 , V_153 ) ;
if ( V_50 -> V_131 > 0 ) {
printf ( L_124 ) ;
for ( V_90 = 0 ; V_90 < V_50 -> V_131 ; V_90 ++ ) {
V_4 = F_60 ( & V_50 -> args [ V_90 ] ,
V_73 , 128 ) ;
if ( V_4 < 0 )
break;
printf ( L_125 , V_73 ) ;
}
}
printf ( L_126 ) ;
free ( V_153 ) ;
return V_4 ;
}
int F_74 ( void )
{
int V_55 , V_4 ;
struct V_51 V_132 ;
struct V_49 V_50 ;
struct V_150 * V_154 ;
struct V_92 * V_155 ;
F_36 () ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_55 = F_67 ( false ) ;
if ( V_55 < 0 )
return V_55 ;
V_154 = F_69 ( V_55 ) ;
F_75 ( V_55 ) ;
if ( ! V_154 )
return - V_34 ;
F_43 (ent, rawlist) {
V_4 = F_59 ( V_155 -> V_100 , & V_132 ) ;
if ( V_4 >= 0 ) {
V_4 = F_64 ( & V_132 , & V_50 ) ;
if ( V_4 >= 0 )
V_4 = F_73 ( & V_50 ) ;
}
F_65 ( & V_50 ) ;
F_66 ( & V_132 ) ;
if ( V_4 < 0 )
break;
}
F_45 ( V_154 ) ;
return V_4 ;
}
static struct V_150 * F_76 ( int V_55 , bool V_156 )
{
char V_73 [ 128 ] ;
struct V_150 * V_152 , * V_154 ;
struct V_92 * V_155 ;
struct V_51 V_132 ;
int V_4 = 0 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_154 = F_69 ( V_55 ) ;
V_152 = F_70 ( true , NULL ) ;
F_43 (ent, rawlist) {
V_4 = F_59 ( V_155 -> V_100 , & V_132 ) ;
if ( V_4 < 0 )
break;
if ( V_156 ) {
V_4 = F_1 ( V_73 , 128 , L_122 , V_132 . V_116 ,
V_132 . V_115 ) ;
if ( V_4 >= 0 )
V_4 = F_72 ( V_152 , V_73 ) ;
} else
V_4 = F_72 ( V_152 , V_132 . V_115 ) ;
F_66 ( & V_132 ) ;
if ( V_4 < 0 )
break;
}
F_45 ( V_154 ) ;
if ( V_4 < 0 ) {
F_45 ( V_152 ) ;
return NULL ;
}
return V_152 ;
}
static int F_77 ( int V_55 , struct V_51 * V_132 )
{
int V_4 = 0 ;
char * V_73 = F_63 ( V_132 ) ;
if ( ! V_73 ) {
F_3 ( L_127 ) ;
return - V_98 ;
}
F_3 ( L_128 , V_73 ) ;
if ( ! V_147 ) {
V_4 = F_78 ( V_55 , V_73 , strlen ( V_73 ) ) ;
if ( V_4 <= 0 )
F_7 ( L_129 ,
strerror ( V_65 ) ) ;
}
free ( V_73 ) ;
return V_4 ;
}
static int F_79 ( char * V_73 , T_1 V_138 , const char * V_157 ,
struct V_150 * V_158 , bool V_159 )
{
int V_90 , V_4 ;
V_4 = F_1 ( V_73 , V_138 , L_26 , V_157 ) ;
if ( V_4 < 0 ) {
F_3 ( L_130 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_80 ( V_158 , V_73 ) )
return 0 ;
if ( ! V_159 ) {
F_7 ( L_131
L_132 , V_157 ) ;
return - V_160 ;
}
for ( V_90 = 1 ; V_90 < V_161 ; V_90 ++ ) {
V_4 = F_1 ( V_73 , V_138 , L_133 , V_157 , V_90 ) ;
if ( V_4 < 0 ) {
F_3 ( L_130 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_80 ( V_158 , V_73 ) )
break;
}
if ( V_90 == V_161 ) {
F_7 ( L_134 ) ;
V_4 = - V_130 ;
}
return V_4 ;
}
static int F_81 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
int V_56 , bool V_159 )
{
int V_90 , V_55 , V_4 ;
struct V_51 * V_132 = NULL ;
char V_73 [ 64 ] ;
const char * V_115 , * V_116 ;
struct V_150 * V_158 ;
V_55 = F_67 ( true ) ;
if ( V_55 < 0 )
return V_55 ;
V_158 = F_76 ( V_55 , false ) ;
if ( ! V_158 ) {
F_3 ( L_135 ) ;
return - V_162 ;
}
V_4 = 0 ;
printf ( L_136 , ( V_56 > 1 ) ? L_137 : L_138 ) ;
for ( V_90 = 0 ; V_90 < V_56 ; V_90 ++ ) {
V_132 = & V_52 [ V_90 ] ;
if ( V_50 -> V_115 )
V_115 = V_50 -> V_115 ;
else
if ( V_50 -> V_57 . V_46 )
V_115 = V_50 -> V_57 . V_46 ;
else
V_115 = V_132 -> V_57 . V_14 ;
if ( V_50 -> V_116 )
V_116 = V_50 -> V_116 ;
else
V_116 = V_163 ;
V_4 = F_79 ( V_73 , 64 , V_115 ,
V_158 , V_159 ) ;
if ( V_4 < 0 )
break;
V_115 = V_73 ;
V_132 -> V_115 = F_24 ( V_115 ) ;
V_132 -> V_116 = F_24 ( V_116 ) ;
if ( V_132 -> V_115 == NULL || V_132 -> V_116 == NULL ) {
V_4 = - V_47 ;
break;
}
V_4 = F_77 ( V_55 , V_132 ) ;
if ( V_4 < 0 )
break;
F_72 ( V_158 , V_115 ) ;
V_115 = V_50 -> V_115 ;
V_116 = V_50 -> V_116 ;
V_50 -> V_115 = V_132 -> V_115 ;
V_50 -> V_116 = V_132 -> V_116 ;
F_73 ( V_50 ) ;
V_50 -> V_115 = ( char * ) V_115 ;
V_50 -> V_116 = ( char * ) V_116 ;
V_159 = true ;
}
if ( V_4 >= 0 ) {
printf ( L_139 ) ;
printf ( L_140 , V_132 -> V_116 ,
V_132 -> V_115 ) ;
}
F_45 ( V_158 ) ;
F_75 ( V_55 ) ;
return V_4 ;
}
static int F_82 ( struct V_49 * V_50 ,
struct V_51 * * V_52 ,
int V_53 , const char * V_18 )
{
struct V_14 * V_40 ;
int V_4 = 0 , V_90 ;
struct V_51 * V_132 ;
V_4 = F_25 ( V_50 , V_52 , V_53 , V_18 ) ;
if ( V_4 != 0 )
return V_4 ;
V_132 = * V_52 = F_55 ( sizeof( struct V_51 ) ) ;
if ( V_132 == NULL )
return - V_47 ;
V_132 -> V_57 . V_14 = F_24 ( V_50 -> V_57 . V_46 ) ;
if ( V_132 -> V_57 . V_14 == NULL ) {
V_4 = - V_47 ;
goto error;
}
V_132 -> V_57 . V_44 = V_50 -> V_57 . V_44 ;
V_132 -> V_57 . V_48 = V_50 -> V_57 . V_48 ;
V_132 -> V_131 = V_50 -> V_131 ;
if ( V_132 -> V_131 ) {
V_132 -> args = F_55 ( sizeof( struct V_135 )
* V_132 -> V_131 ) ;
if ( V_132 -> args == NULL ) {
V_4 = - V_47 ;
goto error;
}
for ( V_90 = 0 ; V_90 < V_132 -> V_131 ; V_90 ++ ) {
if ( V_50 -> args [ V_90 ] . V_15 ) {
V_132 -> args [ V_90 ] . V_15 = F_24 ( V_50 -> args [ V_90 ] . V_15 ) ;
if ( V_132 -> args [ V_90 ] . V_15 == NULL ) {
V_4 = - V_47 ;
goto error;
}
}
V_132 -> args [ V_90 ] . V_136 = F_24 ( V_50 -> args [ V_90 ] . V_97 ) ;
if ( V_132 -> args [ V_90 ] . V_136 == NULL ) {
V_4 = - V_47 ;
goto error;
}
if ( V_50 -> args [ V_90 ] . type ) {
V_132 -> args [ V_90 ] . type = F_24 ( V_50 -> args [ V_90 ] . type ) ;
if ( V_132 -> args [ V_90 ] . type == NULL ) {
V_4 = - V_47 ;
goto error;
}
}
}
}
V_40 = F_8 ( V_132 -> V_57 . V_14 , NULL ) ;
if ( ! V_40 ) {
F_7 ( L_141 ,
V_132 -> V_57 . V_14 ) ;
V_4 = - V_34 ;
goto error;
}
return 1 ;
error:
F_66 ( V_132 ) ;
free ( V_132 ) ;
* V_52 = NULL ;
return V_4 ;
}
int F_83 ( struct V_49 * V_101 , int V_102 ,
int V_53 , const char * V_18 , bool V_164 )
{
int V_90 , V_165 , V_4 ;
struct V_166 * V_167 ;
V_167 = F_55 ( sizeof( struct V_166 ) * V_102 ) ;
if ( V_167 == NULL )
return - V_47 ;
V_4 = F_2 () ;
if ( V_4 < 0 ) {
free ( V_167 ) ;
return V_4 ;
}
for ( V_90 = 0 ; V_90 < V_102 ; V_90 ++ ) {
V_167 [ V_90 ] . V_50 = & V_101 [ V_90 ] ;
V_4 = F_82 ( V_167 [ V_90 ] . V_50 ,
& V_167 [ V_90 ] . V_52 ,
V_53 ,
V_18 ) ;
if ( V_4 < 0 )
goto V_83;
V_167 [ V_90 ] . V_56 = V_4 ;
}
for ( V_90 = 0 ; V_90 < V_102 ; V_90 ++ ) {
V_4 = F_81 ( V_167 [ V_90 ] . V_50 , V_167 [ V_90 ] . V_52 ,
V_167 [ V_90 ] . V_56 , V_164 ) ;
if ( V_4 < 0 )
break;
}
V_83:
for ( V_90 = 0 ; V_90 < V_102 ; V_90 ++ ) {
for ( V_165 = 0 ; V_165 < V_167 [ V_90 ] . V_56 ; V_165 ++ )
F_66 ( & V_167 [ V_90 ] . V_52 [ V_165 ] ) ;
free ( V_167 [ V_90 ] . V_52 ) ;
}
free ( V_167 ) ;
return V_4 ;
}
static int F_84 ( int V_55 , struct V_92 * V_155 )
{
char * V_134 ;
char V_73 [ 128 ] ;
int V_4 ;
V_4 = F_1 ( V_73 , 128 , L_142 , V_155 -> V_100 ) ;
if ( V_4 < 0 )
goto error;
V_134 = strchr ( V_73 + 2 , ':' ) ;
if ( ! V_134 ) {
F_3 ( L_143 ,
V_155 -> V_100 ) ;
V_4 = - V_114 ;
goto error;
}
* V_134 = '/' ;
F_3 ( L_128 , V_73 ) ;
V_4 = F_78 ( V_55 , V_73 , strlen ( V_73 ) ) ;
if ( V_4 < 0 )
goto error;
printf ( L_144 , V_155 -> V_100 ) ;
return 0 ;
error:
F_7 ( L_145 , strerror ( - V_4 ) ) ;
return V_4 ;
}
static int F_85 ( int V_55 , const char * V_116 ,
const char * V_115 , struct V_150 * V_158 )
{
char V_73 [ 128 ] ;
struct V_92 * V_155 , * V_168 ;
int V_30 = 0 , V_4 = 0 ;
V_4 = F_1 ( V_73 , 128 , L_122 , V_116 , V_115 ) ;
if ( V_4 < 0 ) {
F_20 ( L_146 ) ;
return V_4 ;
}
if ( strpbrk ( V_73 , L_147 ) ) {
F_86 (ent, n, namelist)
if ( F_87 ( V_155 -> V_100 , V_73 ) ) {
V_30 ++ ;
V_4 = F_84 ( V_55 , V_155 ) ;
if ( V_4 < 0 )
break;
F_88 ( V_158 , V_155 ) ;
}
} else {
V_155 = F_89 ( V_158 , V_73 ) ;
if ( V_155 ) {
V_30 ++ ;
V_4 = F_84 ( V_55 , V_155 ) ;
if ( V_4 >= 0 )
F_88 ( V_158 , V_155 ) ;
}
}
if ( V_30 == 0 && V_4 >= 0 )
F_90 ( L_148 , V_73 ) ;
return V_4 ;
}
int F_91 ( struct V_150 * V_169 )
{
int V_55 , V_4 = 0 ;
const char * V_116 , * V_115 ;
char * V_134 , * V_1 ;
struct V_92 * V_155 ;
struct V_150 * V_158 ;
V_55 = F_67 ( true ) ;
if ( V_55 < 0 )
return V_55 ;
V_158 = F_76 ( V_55 , true ) ;
if ( V_158 == NULL )
return - V_98 ;
F_43 (ent, dellist) {
V_1 = F_24 ( V_155 -> V_100 ) ;
if ( V_1 == NULL ) {
V_4 = - V_47 ;
break;
}
F_3 ( L_149 , V_1 ) ;
V_134 = strchr ( V_1 , ':' ) ;
if ( V_134 ) {
V_116 = V_1 ;
* V_134 = '\0' ;
V_115 = V_134 + 1 ;
} else {
V_116 = L_150 ;
V_115 = V_1 ;
}
F_3 ( L_151 , V_116 , V_115 ) ;
V_4 = F_85 ( V_55 , V_116 , V_115 , V_158 ) ;
free ( V_1 ) ;
if ( V_4 < 0 )
break;
}
F_45 ( V_158 ) ;
F_75 ( V_55 ) ;
return V_4 ;
}
static int F_92 ( struct V_16 * V_16 V_103 ,
struct V_14 * V_40 )
{
if ( V_40 -> V_170 == V_171 &&
F_44 ( V_172 , V_40 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_93 ( const char * V_18 , struct V_87 * V_88 )
{
struct V_16 * V_16 ;
int V_4 ;
F_36 () ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_16 = F_10 ( V_18 ) ;
if ( ! V_16 ) {
F_20 ( L_152 , ( V_18 ) ? : L_6 ) ;
return - V_98 ;
}
V_172 = V_88 ;
if ( F_94 ( V_16 , F_92 ) ) {
F_20 ( L_153 ) ;
return - V_98 ;
}
if ( ! F_95 ( V_16 -> V_27 , V_16 -> type ) )
F_96 ( V_16 -> V_27 , V_16 -> type ) ;
F_97 ( V_16 -> V_27 , V_16 -> type , stdout ) ;
return 0 ;
}
