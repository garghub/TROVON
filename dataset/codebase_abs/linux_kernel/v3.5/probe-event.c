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
static int F_21 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> V_37 = F_22 ( V_34 -> V_14 ) ;
if ( V_36 -> V_37 == NULL )
return - V_38 ;
V_36 -> V_39 = V_34 -> V_39 ;
V_36 -> V_40 = V_34 -> V_40 ;
return 0 ;
}
static struct V_41 * F_23 ( const char * V_18 )
{
const char * V_42 ;
if ( V_18 && strchr ( V_18 , '/' ) )
V_42 = V_18 ;
else {
V_42 = F_19 ( V_18 ) ;
if ( ! V_42 ) {
F_24 ( L_9 ,
V_18 ? : L_6 ) ;
return NULL ;
}
}
return F_25 ( V_42 ) ;
}
static int F_26 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_14 * V_43 ;
struct V_16 * V_16 ;
T_3 V_44 ;
int V_4 = - V_45 ;
struct V_41 * V_46 ;
V_43 = F_8 ( V_34 -> V_14 , & V_16 ) ;
if ( V_43 ) {
V_44 = V_16 -> V_47 ( V_16 , V_43 -> V_48 + V_34 -> V_39 ) ;
F_3 ( L_10 V_49 L_11 , V_34 -> V_14 ,
V_34 -> V_39 , V_44 ) ;
V_46 = F_27 ( V_44 ) ;
if ( V_46 ) {
V_4 = F_28 ( V_46 ,
( unsigned long ) V_44 , V_36 ) ;
F_29 ( V_46 ) ;
} else {
F_3 ( L_12 V_49 L_11 ,
V_44 ) ;
V_4 = - V_45 ;
}
}
if ( V_4 <= 0 ) {
F_3 ( L_13
L_14 ) ;
return F_21 ( V_34 , V_36 ) ;
}
V_36 -> V_40 = V_34 -> V_40 ;
return 0 ;
}
static int F_30 ( struct V_50 * V_51 ,
int V_52 , const char * V_18 )
{
int V_53 , V_4 = 0 ;
char * V_54 ;
if ( ! V_18 )
return 0 ;
V_54 = strrchr ( V_18 , '/' ) ;
if ( V_54 ) {
V_18 = F_22 ( V_54 + 1 ) ;
if ( ! V_18 )
return - V_38 ;
V_54 = strchr ( V_18 , '.' ) ;
if ( V_54 )
* V_54 = '\0' ;
V_54 = ( char * ) V_18 ;
}
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_51 [ V_53 ] . V_55 . V_18 = F_22 ( V_18 ) ;
if ( ! V_51 [ V_53 ] . V_55 . V_18 ) {
V_4 = - V_38 ;
break;
}
}
if ( V_54 )
free ( V_54 ) ;
return V_4 ;
}
static int F_31 ( struct V_56 * V_57 ,
struct V_50 * * V_51 ,
int V_58 , const char * V_59 )
{
bool V_60 = F_32 ( V_57 ) ;
struct V_41 * V_46 ;
int V_52 , V_4 = 0 ;
if ( V_57 -> V_61 ) {
if ( V_60 ) {
F_7 ( L_15
L_16 ) ;
return - V_62 ;
}
return F_33 ( V_57 , V_59 ) ;
}
V_46 = F_23 ( V_59 ) ;
if ( ! V_46 ) {
if ( V_60 ) {
F_7 ( L_17 ) ;
return - V_45 ;
}
F_3 ( L_18 ) ;
return 0 ;
}
V_52 = F_34 ( V_46 , V_57 , V_51 , V_58 ) ;
F_29 ( V_46 ) ;
if ( V_52 > 0 ) {
F_3 ( L_19 , V_52 ) ;
if ( V_59 )
V_4 = F_30 ( * V_51 , V_52 ,
V_59 ) ;
return V_4 < 0 ? V_4 : V_52 ;
}
if ( V_52 == 0 ) {
F_7 ( L_20 ,
F_35 ( & V_57 -> V_55 ) ) ;
return - V_45 ;
}
F_3 ( L_21 , V_52 ) ;
if ( V_52 == - V_63 ) {
F_7 ( L_22
L_23 ) ;
if ( ! V_60 ) {
F_3 ( L_24 ) ;
return 0 ;
}
}
return V_52 ;
}
static int F_36 ( const char * V_64 , const char * V_65 ,
char * * V_66 )
{
const char * V_67 = V_7 . V_68 ;
if ( ! V_67 ) {
if ( V_64 [ 0 ] != '/' && V_65 )
V_67 = V_65 ;
else {
if ( F_37 ( V_64 , V_69 ) == 0 ) {
* V_66 = F_22 ( V_64 ) ;
return 0 ;
} else
return - V_70 ;
}
}
* V_66 = malloc ( ( strlen ( V_67 ) + strlen ( V_64 ) + 2 ) ) ;
if ( ! * V_66 )
return - V_38 ;
for (; ; ) {
sprintf ( * V_66 , L_25 , V_67 , V_64 ) ;
if ( F_37 ( * V_66 , V_69 ) == 0 )
return 0 ;
if ( ! V_7 . V_68 )
return - V_70 ;
switch ( V_70 ) {
case V_71 :
case V_45 :
case V_72 :
case V_73 :
V_64 = strchr ( ++ V_64 , '/' ) ;
if ( ! V_64 ) {
free ( * V_66 ) ;
* V_66 = NULL ;
return - V_45 ;
}
continue;
default:
free ( * V_66 ) ;
* V_66 = NULL ;
return - V_70 ;
}
}
}
static int F_38 ( T_4 * V_74 , int V_75 , bool V_76 , bool V_77 )
{
char V_78 [ V_79 ] ;
const char * V_80 = V_77 ? L_3 : V_81 ;
const char * V_67 = NULL ;
do {
if ( fgets ( V_78 , V_79 , V_74 ) == NULL )
goto error;
if ( V_76 )
continue;
if ( ! V_67 ) {
V_67 = V_77 ? L_26 : L_27 ;
F_39 ( stdout , V_80 , V_67 , V_75 ) ;
}
F_39 ( stdout , V_80 , L_28 , V_78 ) ;
} while ( strchr ( V_78 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_74 ) ) {
F_7 ( L_29 , strerror ( V_70 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_40 ( T_4 * V_74 , int V_75 , bool V_76 , bool V_77 )
{
int V_82 = F_38 ( V_74 , V_75 , V_76 , V_77 ) ;
if ( V_82 == 0 ) {
F_7 ( L_30 ) ;
V_82 = - 1 ;
}
return V_82 ;
}
int F_41 ( struct V_83 * V_84 , const char * V_18 )
{
int V_75 = 1 ;
struct V_85 * V_86 ;
struct V_41 * V_46 ;
T_4 * V_74 ;
int V_4 ;
char * V_54 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_46 = F_23 ( V_18 ) ;
if ( ! V_46 ) {
F_7 ( L_17 ) ;
return - V_45 ;
}
V_4 = F_42 ( V_46 , V_84 ) ;
F_29 ( V_46 ) ;
if ( V_4 == 0 ) {
F_7 ( L_31 ) ;
return - V_45 ;
} else if ( V_4 < 0 ) {
F_7 ( L_32 , V_4 ) ;
return V_4 ;
}
V_54 = V_84 -> V_42 ;
V_4 = F_36 ( V_54 , V_84 -> V_65 , & V_84 -> V_42 ) ;
free ( V_54 ) ;
if ( V_4 < 0 ) {
F_7 ( L_33 , V_4 ) ;
return V_4 ;
}
F_43 () ;
if ( V_84 -> V_37 )
fprintf ( stdout , L_34 , V_84 -> V_37 , V_84 -> V_42 ,
V_84 -> V_48 - V_84 -> V_39 ) ;
else
fprintf ( stdout , L_35 , V_84 -> V_42 , V_84 -> V_48 ) ;
V_74 = fopen ( V_84 -> V_42 , L_36 ) ;
if ( V_74 == NULL ) {
F_7 ( L_37 , V_84 -> V_42 ,
strerror ( V_70 ) ) ;
return - V_70 ;
}
while ( V_75 < V_84 -> V_48 ) {
V_4 = F_44 ( V_74 , V_75 ++ ) ;
if ( V_4 < 0 )
goto V_87;
}
F_16 (ln, &lr->line_list, list) {
for (; V_86 -> line > V_75 ; V_75 ++ ) {
V_4 = F_45 ( V_74 , V_75 - V_84 -> V_39 ) ;
if ( V_4 < 0 )
goto V_87;
}
V_4 = F_46 ( V_74 , V_75 ++ - V_84 -> V_39 ) ;
if ( V_4 < 0 )
goto V_87;
}
if ( V_84 -> V_87 == V_88 )
V_84 -> V_87 = V_75 + V_89 ;
while ( V_75 <= V_84 -> V_87 ) {
V_4 = F_47 ( V_74 , V_75 ++ - V_84 -> V_39 ) ;
if ( V_4 <= 0 )
break;
}
V_87:
fclose ( V_74 ) ;
return V_4 ;
}
static int F_48 ( struct V_41 * V_46 ,
struct V_56 * V_57 ,
int V_90 , struct V_91 * V_92 ,
bool V_93 )
{
char * V_78 ;
int V_4 , V_53 , V_94 ;
struct V_95 * V_96 ;
struct V_97 * V_98 = NULL , * V_99 ;
const char * V_100 ;
V_78 = F_35 ( & V_57 -> V_55 ) ;
if ( ! V_78 )
return - V_101 ;
F_3 ( L_38 , V_78 ) ;
V_4 = F_49 ( V_46 , V_57 , & V_98 ,
V_90 , V_93 ) ;
if ( V_4 <= 0 ) {
F_24 ( L_39 , V_78 , V_4 ) ;
goto V_87;
}
fprintf ( stdout , L_40 , V_78 ) ;
for ( V_53 = 0 ; V_53 < V_4 ; V_53 ++ ) {
V_99 = & V_98 [ V_53 ] ;
fprintf ( stdout , L_41 , V_99 -> V_55 . V_14 ,
V_99 -> V_55 . V_39 ) ;
free ( V_99 -> V_55 . V_14 ) ;
V_94 = 0 ;
if ( V_99 -> V_102 ) {
F_50 (node, vl->vars) {
V_100 = strchr ( V_96 -> V_103 , '\t' ) + 1 ;
if ( F_51 ( V_92 , V_100 ) ) {
fprintf ( stdout , L_42 , V_96 -> V_103 ) ;
V_94 ++ ;
}
}
F_52 ( V_99 -> V_102 ) ;
}
if ( V_94 == 0 )
fprintf ( stdout , L_43 ) ;
}
free ( V_98 ) ;
V_87:
free ( V_78 ) ;
return V_4 ;
}
int F_53 ( struct V_56 * V_104 , int V_105 ,
int V_90 , const char * V_18 ,
struct V_91 * V_92 , bool V_93 )
{
int V_53 , V_4 = 0 ;
struct V_41 * V_46 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_46 = F_23 ( V_18 ) ;
if ( ! V_46 ) {
F_7 ( L_17 ) ;
return - V_45 ;
}
F_43 () ;
for ( V_53 = 0 ; V_53 < V_105 && V_4 >= 0 ; V_53 ++ )
V_4 = F_48 ( V_46 , & V_104 [ V_53 ] , V_90 , V_92 ,
V_93 ) ;
F_29 ( V_46 ) ;
return V_4 ;
}
static int F_26 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_14 * V_43 ;
V_43 = F_8 ( V_34 -> V_14 , NULL ) ;
if ( ! V_43 ) {
F_24 ( L_44 , V_34 -> V_14 ) ;
return - V_45 ;
}
return F_21 ( V_34 , V_36 ) ;
}
static int F_31 ( struct V_56 * V_57 ,
struct V_50 * * V_51 V_106 ,
int V_58 V_106 , const char * V_59 )
{
if ( F_32 ( V_57 ) ) {
F_7 ( L_45 ) ;
return - V_62 ;
}
if ( V_57 -> V_61 )
return F_33 ( V_57 , V_59 ) ;
return 0 ;
}
int F_41 ( struct V_83 * V_84 V_106 , const char * V_18 V_106 )
{
F_7 ( L_45 ) ;
return - V_62 ;
}
int F_53 ( struct V_56 * V_104 V_106 ,
int V_105 V_106 , int V_90 V_106 ,
const char * V_18 V_106 ,
struct V_91 * T_5 V_106 ,
bool V_93 V_106 )
{
F_7 ( L_45 ) ;
return - V_62 ;
}
static int F_54 ( char * * V_107 , int * V_108 , const char * V_109 )
{
const char * V_48 = * V_107 ;
V_70 = 0 ;
* V_108 = strtol ( * V_107 , V_107 , 0 ) ;
if ( V_70 || * V_107 == V_48 ) {
F_55 ( L_46 , V_109 ) ;
return - V_101 ;
}
return 0 ;
}
int F_56 ( const char * V_110 , struct V_83 * V_84 )
{
char * V_111 , * V_112 , * V_15 = F_22 ( V_110 ) ;
int V_113 ;
if ( ! V_15 )
return - V_38 ;
V_84 -> V_48 = 0 ;
V_84 -> V_87 = V_88 ;
V_111 = strchr ( V_15 , ':' ) ;
if ( V_111 ) {
* V_111 ++ = '\0' ;
V_113 = F_54 ( & V_111 , & V_84 -> V_48 , L_47 ) ;
if ( V_113 )
goto V_113;
if ( * V_111 == '+' || * V_111 == '-' ) {
const char V_114 = * V_111 ++ ;
V_113 = F_54 ( & V_111 , & V_84 -> V_87 , L_48 ) ;
if ( V_113 )
goto V_113;
if ( V_114 == '+' ) {
V_84 -> V_87 += V_84 -> V_48 ;
V_84 -> V_87 -- ;
}
}
F_3 ( L_49 , V_84 -> V_48 , V_84 -> V_87 ) ;
V_113 = - V_101 ;
if ( V_84 -> V_48 > V_84 -> V_87 ) {
F_55 ( L_50
L_51 ) ;
goto V_113;
}
if ( * V_111 != '\0' ) {
F_55 ( L_52 , V_111 ) ;
goto V_113;
}
}
V_112 = strchr ( V_15 , '@' ) ;
if ( V_112 ) {
* V_112 = '\0' ;
V_84 -> V_112 = F_22 ( ++ V_112 ) ;
if ( V_84 -> V_112 == NULL ) {
V_113 = - V_38 ;
goto V_113;
}
V_84 -> V_37 = V_15 ;
} else if ( strchr ( V_15 , '.' ) )
V_84 -> V_112 = V_15 ;
else
V_84 -> V_37 = V_15 ;
return 0 ;
V_113:
free ( V_15 ) ;
return V_113 ;
}
static bool F_57 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
static int F_58 ( char * V_110 , struct V_56 * V_57 )
{
struct V_35 * V_36 = & V_57 -> V_55 ;
char * V_107 , * V_54 ;
char V_114 , V_115 = 0 ;
V_107 = strpbrk ( V_110 , L_53 ) ;
if ( V_107 && * V_107 == '=' ) {
* V_107 = '\0' ;
V_54 = V_107 + 1 ;
if ( strchr ( V_110 , ':' ) ) {
F_55 ( L_54 ) ;
return - V_116 ;
}
if ( ! F_57 ( V_110 ) ) {
F_55 ( L_55
L_56 , V_110 ) ;
return - V_101 ;
}
V_57 -> V_117 = F_22 ( V_110 ) ;
if ( V_57 -> V_117 == NULL )
return - V_38 ;
V_57 -> V_118 = NULL ;
V_110 = V_54 ;
}
V_107 = strpbrk ( V_110 , L_57 ) ;
if ( V_107 ) {
V_115 = * V_107 ;
* V_107 ++ = '\0' ;
}
V_54 = F_22 ( V_110 ) ;
if ( V_54 == NULL )
return - V_38 ;
if ( strchr ( V_54 , '.' ) )
V_36 -> V_112 = V_54 ;
else
V_36 -> V_37 = V_54 ;
while ( V_107 ) {
V_110 = V_107 ;
V_114 = V_115 ;
if ( V_114 == ';' ) {
V_36 -> V_119 = F_22 ( V_110 ) ;
if ( V_36 -> V_119 == NULL )
return - V_38 ;
break;
}
V_107 = strpbrk ( V_110 , L_57 ) ;
if ( V_107 ) {
V_115 = * V_107 ;
* V_107 ++ = '\0' ;
}
switch ( V_114 ) {
case ':' :
V_36 -> line = strtoul ( V_110 , & V_54 , 0 ) ;
if ( * V_54 != '\0' ) {
F_55 ( L_58
L_59 ) ;
return - V_101 ;
}
break;
case '+' :
V_36 -> V_39 = strtoul ( V_110 , & V_54 , 0 ) ;
if ( * V_54 != '\0' ) {
F_55 ( L_60
L_61 ) ;
return - V_101 ;
}
break;
case '@' :
if ( V_36 -> V_112 ) {
F_55 ( L_62 ) ;
return - V_101 ;
}
V_36 -> V_112 = F_22 ( V_110 ) ;
if ( V_36 -> V_112 == NULL )
return - V_38 ;
break;
case '%' :
if ( strcmp ( V_110 , L_63 ) == 0 ) {
V_36 -> V_40 = 1 ;
} else {
F_55 ( L_64 , V_110 ) ;
return - V_116 ;
}
break;
default:
F_24 ( L_65 ,
__FILE__ , __LINE__ ) ;
return - V_116 ;
break;
}
}
if ( V_36 -> V_119 && V_36 -> line ) {
F_55 ( L_66
L_67 ) ;
return - V_101 ;
}
if ( V_36 -> V_119 && V_36 -> V_39 ) {
F_55 ( L_68 ) ;
return - V_101 ;
}
if ( V_36 -> line && V_36 -> V_39 ) {
F_55 ( L_69 ) ;
return - V_101 ;
}
if ( ! V_36 -> line && ! V_36 -> V_119 && V_36 -> V_112 && ! V_36 -> V_37 ) {
F_55 ( L_70
L_71 ) ;
return - V_101 ;
}
if ( V_36 -> V_39 && ! V_36 -> V_37 ) {
F_55 ( L_72 ) ;
return - V_101 ;
}
if ( V_36 -> V_40 && ! V_36 -> V_37 ) {
F_55 ( L_73 ) ;
return - V_101 ;
}
if ( ( V_36 -> V_39 || V_36 -> line || V_36 -> V_119 ) && V_36 -> V_40 ) {
F_55 ( L_74
L_75 ) ;
return - V_101 ;
}
F_3 ( L_76 ,
V_36 -> V_37 , V_36 -> V_112 , V_36 -> line , V_36 -> V_39 , V_36 -> V_40 ,
V_36 -> V_119 ) ;
return 0 ;
}
static int F_59 ( char * V_1 , struct V_120 * V_110 )
{
char * V_54 , * V_121 ;
struct V_122 * * V_123 ;
F_3 ( L_77 , V_1 ) ;
V_54 = strchr ( V_1 , '=' ) ;
if ( V_54 ) {
V_110 -> V_15 = F_60 ( V_1 , V_54 - V_1 ) ;
if ( V_110 -> V_15 == NULL )
return - V_38 ;
F_3 ( L_78 , V_110 -> V_15 ) ;
V_1 = V_54 + 1 ;
}
V_54 = strchr ( V_1 , ':' ) ;
if ( V_54 ) {
* V_54 = '\0' ;
V_110 -> type = F_22 ( V_54 + 1 ) ;
if ( V_110 -> type == NULL )
return - V_38 ;
F_3 ( L_79 , V_110 -> type ) ;
}
V_54 = strpbrk ( V_1 , L_80 ) ;
if ( ! F_61 ( V_1 ) || ! V_54 ) {
V_110 -> V_100 = F_22 ( V_1 ) ;
if ( V_110 -> V_100 == NULL )
return - V_38 ;
F_3 ( L_81 , V_110 -> V_100 ) ;
return 0 ;
}
V_110 -> V_100 = F_60 ( V_1 , V_54 - V_1 ) ;
if ( V_110 -> V_100 == NULL )
return - V_38 ;
V_121 = V_110 -> V_100 ;
F_3 ( L_82 , V_110 -> V_100 ) ;
V_123 = & V_110 -> V_124 ;
do {
* V_123 = F_62 ( sizeof( struct V_122 ) ) ;
if ( * V_123 == NULL )
return - V_38 ;
if ( * V_54 == '[' ) {
V_1 = V_54 ;
( * V_123 ) -> V_125 = strtol ( V_1 + 1 , & V_54 , 0 ) ;
( * V_123 ) -> V_126 = true ;
if ( * V_54 != ']' || V_54 == V_1 + 1 ) {
F_55 ( L_83
L_84 ) ;
return - V_101 ;
}
V_54 ++ ;
if ( * V_54 == '\0' )
V_54 = NULL ;
} else {
if ( * V_54 == '.' ) {
V_1 = V_54 + 1 ;
( * V_123 ) -> V_126 = false ;
} else if ( V_54 [ 1 ] == '>' ) {
V_1 = V_54 + 2 ;
( * V_123 ) -> V_126 = true ;
} else {
F_55 ( L_85 ,
V_1 ) ;
return - V_101 ;
}
V_54 = strpbrk ( V_1 , L_80 ) ;
}
if ( V_54 ) {
( * V_123 ) -> V_15 = F_60 ( V_1 , V_54 - V_1 ) ;
if ( ( * V_123 ) -> V_15 == NULL )
return - V_38 ;
if ( * V_1 != '[' )
V_121 = ( * V_123 ) -> V_15 ;
F_3 ( L_86 , ( * V_123 ) -> V_15 , ( * V_123 ) -> V_126 ) ;
V_123 = & ( * V_123 ) -> V_127 ;
}
} while ( V_54 );
( * V_123 ) -> V_15 = F_22 ( V_1 ) ;
if ( ( * V_123 ) -> V_15 == NULL )
return - V_38 ;
if ( * V_1 != '[' )
V_121 = ( * V_123 ) -> V_15 ;
F_3 ( L_87 , ( * V_123 ) -> V_15 , ( * V_123 ) -> V_126 ) ;
if ( ! V_110 -> V_15 ) {
V_110 -> V_15 = F_22 ( V_121 ) ;
if ( V_110 -> V_15 == NULL )
return - V_38 ;
}
return 0 ;
}
int F_63 ( const char * V_128 , struct V_56 * V_57 )
{
char * * V_129 ;
int V_130 , V_53 , V_4 = 0 ;
V_129 = F_64 ( V_128 , & V_130 ) ;
if ( ! V_129 ) {
F_3 ( L_88 ) ;
return - V_38 ;
}
if ( V_130 - 1 > V_131 ) {
F_55 ( L_89 , V_130 - 1 ) ;
V_4 = - V_132 ;
goto V_11;
}
V_4 = F_58 ( V_129 [ 0 ] , V_57 ) ;
if ( V_4 < 0 )
goto V_11;
V_57 -> V_133 = V_130 - 1 ;
V_57 -> args = F_62 ( sizeof( struct V_120 ) * V_57 -> V_133 ) ;
if ( V_57 -> args == NULL ) {
V_4 = - V_38 ;
goto V_11;
}
for ( V_53 = 0 ; V_53 < V_57 -> V_133 && V_4 >= 0 ; V_53 ++ ) {
V_4 = F_59 ( V_129 [ V_53 + 1 ] , & V_57 -> args [ V_53 ] ) ;
if ( V_4 >= 0 &&
F_61 ( V_57 -> args [ V_53 ] . V_100 ) && V_57 -> V_55 . V_40 ) {
F_55 ( L_90
L_91 ) ;
V_4 = - V_101 ;
}
}
V_11:
F_65 ( V_129 ) ;
return V_4 ;
}
bool F_32 ( struct V_56 * V_57 )
{
int V_53 ;
if ( V_57 -> V_55 . V_112 || V_57 -> V_55 . line || V_57 -> V_55 . V_119 )
return true ;
for ( V_53 = 0 ; V_53 < V_57 -> V_133 ; V_53 ++ )
if ( F_61 ( V_57 -> args [ V_53 ] . V_100 ) )
return true ;
return false ;
}
static int F_66 ( const char * V_128 ,
struct V_50 * V_134 )
{
struct V_33 * V_34 = & V_134 -> V_55 ;
char V_135 ;
char * V_136 ;
int V_4 , V_53 , V_130 ;
char * * V_129 ;
F_3 ( L_92 , V_128 ) ;
V_129 = F_64 ( V_128 , & V_130 ) ;
if ( ! V_129 ) {
F_3 ( L_88 ) ;
return - V_38 ;
}
if ( V_130 < 2 ) {
F_55 ( L_93 ) ;
V_4 = - V_132 ;
goto V_11;
}
V_4 = sscanf ( V_129 [ 0 ] , L_94 ,
& V_135 , ( float * ) ( void * ) & V_134 -> V_118 ,
( float * ) ( void * ) & V_134 -> V_117 ) ;
if ( V_4 != 3 ) {
F_55 ( L_95 , V_129 [ 0 ] ) ;
V_4 = - V_101 ;
goto V_11;
}
F_3 ( L_96 , V_134 -> V_118 , V_134 -> V_117 , V_135 ) ;
V_34 -> V_40 = ( V_135 == 'r' ) ;
V_136 = strchr ( V_129 [ 1 ] , ':' ) ;
if ( V_136 ) {
V_34 -> V_18 = F_60 ( V_129 [ 1 ] , V_136 - V_129 [ 1 ] ) ;
V_136 ++ ;
} else
V_136 = V_129 [ 1 ] ;
V_4 = sscanf ( V_136 , L_97 , ( float * ) ( void * ) & V_34 -> V_14 ,
& V_34 -> V_39 ) ;
if ( V_4 == 1 )
V_34 -> V_39 = 0 ;
V_134 -> V_133 = V_130 - 2 ;
V_134 -> args = F_62 ( sizeof( struct V_137 ) * V_134 -> V_133 ) ;
if ( V_134 -> args == NULL ) {
V_4 = - V_38 ;
goto V_11;
}
for ( V_53 = 0 ; V_53 < V_134 -> V_133 ; V_53 ++ ) {
V_136 = strchr ( V_129 [ V_53 + 2 ] , '=' ) ;
if ( V_136 )
* V_136 ++ = '\0' ;
else
V_136 = V_129 [ V_53 + 2 ] ;
V_134 -> args [ V_53 ] . V_15 = F_22 ( V_129 [ V_53 + 2 ] ) ;
V_134 -> args [ V_53 ] . V_138 = F_22 ( V_136 ) ;
if ( V_134 -> args [ V_53 ] . V_15 == NULL || V_134 -> args [ V_53 ] . V_138 == NULL ) {
V_4 = - V_38 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
F_65 ( V_129 ) ;
return V_4 ;
}
int F_67 ( struct V_120 * V_139 , char * V_78 , T_1 V_140 )
{
struct V_122 * V_124 = V_139 -> V_124 ;
int V_4 ;
char * V_54 = V_78 ;
if ( V_139 -> V_15 && V_139 -> V_100 )
V_4 = F_1 ( V_54 , V_140 , L_98 , V_139 -> V_15 , V_139 -> V_100 ) ;
else
V_4 = F_1 ( V_54 , V_140 , L_28 , V_139 -> V_15 ? V_139 -> V_15 : V_139 -> V_100 ) ;
if ( V_4 <= 0 )
goto error;
V_54 += V_4 ;
V_140 -= V_4 ;
while ( V_124 ) {
if ( V_124 -> V_15 [ 0 ] == '[' )
V_4 = F_1 ( V_54 , V_140 , L_28 , V_124 -> V_15 ) ;
else
V_4 = F_1 ( V_54 , V_140 , L_99 ,
V_124 -> V_126 ? L_100 : L_101 , V_124 -> V_15 ) ;
if ( V_4 <= 0 )
goto error;
V_54 += V_4 ;
V_140 -= V_4 ;
V_124 = V_124 -> V_127 ;
}
if ( V_139 -> type ) {
V_4 = F_1 ( V_54 , V_140 , L_102 , V_139 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_54 += V_4 ;
V_140 -= V_4 ;
}
return V_54 - V_78 ;
error:
F_3 ( L_103 ,
strerror ( - V_4 ) ) ;
return V_4 ;
}
static char * F_35 ( struct V_35 * V_36 )
{
char * V_78 , * V_54 ;
char V_141 [ 32 ] = L_3 , line [ 32 ] = L_3 , V_112 [ 32 ] = L_3 ;
int V_4 , V_140 ;
V_78 = F_62 ( V_142 ) ;
if ( V_78 == NULL ) {
V_4 = - V_38 ;
goto error;
}
if ( V_36 -> V_39 ) {
V_4 = F_1 ( V_141 , 32 , L_104 , V_36 -> V_39 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_36 -> line ) {
V_4 = F_1 ( line , 32 , L_105 , V_36 -> line ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_36 -> V_112 ) {
V_54 = V_36 -> V_112 ;
V_140 = strlen ( V_54 ) ;
if ( V_140 > 30 ) {
V_54 = strchr ( V_36 -> V_112 + V_140 - 30 , '/' ) ;
V_54 = V_54 ? V_54 + 1 : V_36 -> V_112 + V_140 - 30 ;
}
V_4 = F_1 ( V_112 , 32 , L_106 , V_54 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_36 -> V_37 )
V_4 = F_1 ( V_78 , V_142 , L_107 , V_36 -> V_37 ,
V_141 , V_36 -> V_40 ? L_108 : L_3 , line ,
V_112 ) ;
else
V_4 = F_1 ( V_78 , V_142 , L_99 , V_112 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_78 ;
error:
F_3 ( L_109 ,
strerror ( - V_4 ) ) ;
if ( V_78 )
free ( V_78 ) ;
return NULL ;
}
static int F_68 ( struct V_143 * V_126 ,
char * * V_78 , T_1 * V_144 ,
int V_145 )
{
int V_4 ;
if ( V_126 -> V_127 ) {
V_145 = F_68 ( V_126 -> V_127 , V_78 ,
V_144 , V_145 + 1 ) ;
if ( V_145 < 0 )
goto V_11;
}
V_4 = F_1 ( * V_78 , * V_144 , L_110 , V_126 -> V_39 ) ;
if ( V_4 < 0 )
V_145 = V_4 ;
else {
* V_78 += V_4 ;
* V_144 -= V_4 ;
}
V_11:
return V_145 ;
}
static int F_69 ( struct V_137 * V_110 ,
char * V_78 , T_1 V_144 )
{
struct V_143 * V_126 = V_110 -> V_126 ;
int V_4 , V_145 = 0 ;
char * V_54 = V_78 ;
if ( V_110 -> V_15 )
V_4 = F_1 ( V_78 , V_144 , L_111 , V_110 -> V_15 ) ;
else
V_4 = F_1 ( V_78 , V_144 , L_112 ) ;
if ( V_4 < 0 )
return V_4 ;
V_78 += V_4 ;
V_144 -= V_4 ;
if ( V_110 -> V_138 [ 0 ] == '@' && V_110 -> V_126 )
V_126 = V_126 -> V_127 ;
if ( V_126 ) {
V_145 = F_68 ( V_126 , & V_78 ,
& V_144 , 1 ) ;
if ( V_145 < 0 )
return V_145 ;
}
if ( V_110 -> V_138 [ 0 ] == '@' && V_110 -> V_126 )
V_4 = F_1 ( V_78 , V_144 , L_113 , V_110 -> V_138 ,
V_110 -> V_126 -> V_39 ) ;
else
V_4 = F_1 ( V_78 , V_144 , L_28 , V_110 -> V_138 ) ;
if ( V_4 < 0 )
return V_4 ;
V_78 += V_4 ;
V_144 -= V_4 ;
while ( V_145 -- ) {
V_4 = F_1 ( V_78 , V_144 , L_114 ) ;
if ( V_4 < 0 )
return V_4 ;
V_78 += V_4 ;
V_144 -= V_4 ;
}
if ( V_110 -> type ) {
V_4 = F_1 ( V_78 , V_144 , L_102 , V_110 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_78 += V_4 ;
}
return V_78 - V_54 ;
}
char * F_70 ( struct V_50 * V_134 )
{
struct V_33 * V_34 = & V_134 -> V_55 ;
char * V_78 ;
int V_53 , V_140 , V_4 ;
V_78 = F_62 ( V_142 ) ;
if ( V_78 == NULL )
return NULL ;
if ( V_134 -> V_61 )
V_140 = F_1 ( V_78 , V_142 , L_115 ,
V_34 -> V_40 ? 'r' : 'p' ,
V_134 -> V_118 , V_134 -> V_117 ,
V_34 -> V_18 , V_34 -> V_14 ) ;
else
V_140 = F_1 ( V_78 , V_142 , L_116 ,
V_34 -> V_40 ? 'r' : 'p' ,
V_134 -> V_118 , V_134 -> V_117 ,
V_34 -> V_18 ? : L_3 , V_34 -> V_18 ? L_117 : L_3 ,
V_34 -> V_14 , V_34 -> V_39 ) ;
if ( V_140 <= 0 )
goto error;
for ( V_53 = 0 ; V_53 < V_134 -> V_133 ; V_53 ++ ) {
V_4 = F_69 ( & V_134 -> args [ V_53 ] , V_78 + V_140 ,
V_142 - V_140 ) ;
if ( V_4 <= 0 )
goto error;
V_140 += V_4 ;
}
return V_78 ;
error:
free ( V_78 ) ;
return NULL ;
}
static int F_71 ( struct V_50 * V_134 ,
struct V_56 * V_57 , bool V_146 )
{
char V_78 [ 64 ] = L_3 ;
int V_53 , V_4 ;
V_57 -> V_117 = F_22 ( V_134 -> V_117 ) ;
V_57 -> V_118 = F_22 ( V_134 -> V_118 ) ;
if ( V_57 -> V_117 == NULL || V_57 -> V_118 == NULL )
return - V_38 ;
if ( V_146 )
V_4 = F_26 ( & V_134 -> V_55 , & V_57 -> V_55 ) ;
else
V_4 = F_21 ( & V_134 -> V_55 , & V_57 -> V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
V_57 -> V_133 = V_134 -> V_133 ;
V_57 -> args = F_62 ( sizeof( struct V_120 ) * V_57 -> V_133 ) ;
if ( V_57 -> args == NULL )
return - V_38 ;
for ( V_53 = 0 ; V_53 < V_134 -> V_133 && V_4 >= 0 ; V_53 ++ ) {
if ( V_134 -> args [ V_53 ] . V_15 )
V_57 -> args [ V_53 ] . V_15 = F_22 ( V_134 -> args [ V_53 ] . V_15 ) ;
else {
V_4 = F_69 ( & V_134 -> args [ V_53 ] ,
V_78 , 64 ) ;
V_57 -> args [ V_53 ] . V_15 = F_22 ( V_78 ) ;
}
if ( V_57 -> args [ V_53 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_38 ;
}
if ( V_4 < 0 )
F_72 ( V_57 ) ;
return V_4 ;
}
void F_72 ( struct V_56 * V_57 )
{
struct V_35 * V_36 = & V_57 -> V_55 ;
struct V_122 * V_124 , * V_127 ;
int V_53 ;
if ( V_57 -> V_117 )
free ( V_57 -> V_117 ) ;
if ( V_57 -> V_118 )
free ( V_57 -> V_118 ) ;
if ( V_36 -> V_112 )
free ( V_36 -> V_112 ) ;
if ( V_36 -> V_37 )
free ( V_36 -> V_37 ) ;
if ( V_36 -> V_119 )
free ( V_36 -> V_119 ) ;
for ( V_53 = 0 ; V_53 < V_57 -> V_133 ; V_53 ++ ) {
if ( V_57 -> args [ V_53 ] . V_15 )
free ( V_57 -> args [ V_53 ] . V_15 ) ;
if ( V_57 -> args [ V_53 ] . V_100 )
free ( V_57 -> args [ V_53 ] . V_100 ) ;
if ( V_57 -> args [ V_53 ] . type )
free ( V_57 -> args [ V_53 ] . type ) ;
V_124 = V_57 -> args [ V_53 ] . V_124 ;
while ( V_124 ) {
V_127 = V_124 -> V_127 ;
if ( V_124 -> V_15 )
free ( V_124 -> V_15 ) ;
free ( V_124 ) ;
V_124 = V_127 ;
}
}
if ( V_57 -> args )
free ( V_57 -> args ) ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
}
static void F_73 ( struct V_50 * V_134 )
{
struct V_143 * V_126 , * V_127 ;
int V_53 ;
if ( V_134 -> V_117 )
free ( V_134 -> V_117 ) ;
if ( V_134 -> V_118 )
free ( V_134 -> V_118 ) ;
if ( V_134 -> V_55 . V_14 )
free ( V_134 -> V_55 . V_14 ) ;
if ( V_134 -> V_55 . V_18 )
free ( V_134 -> V_55 . V_18 ) ;
for ( V_53 = 0 ; V_53 < V_134 -> V_133 ; V_53 ++ ) {
if ( V_134 -> args [ V_53 ] . V_15 )
free ( V_134 -> args [ V_53 ] . V_15 ) ;
if ( V_134 -> args [ V_53 ] . V_138 )
free ( V_134 -> args [ V_53 ] . V_138 ) ;
if ( V_134 -> args [ V_53 ] . type )
free ( V_134 -> args [ V_53 ] . type ) ;
V_126 = V_134 -> args [ V_53 ] . V_126 ;
while ( V_126 ) {
V_127 = V_126 -> V_127 ;
free ( V_126 ) ;
V_126 = V_127 ;
}
}
if ( V_134 -> args )
free ( V_134 -> args ) ;
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
}
static void F_74 ( const char * V_112 , bool V_146 )
{
if ( V_70 == V_45 ) {
const char * V_147 ;
if ( ! V_146 )
V_147 = L_118 ;
else
V_147 = L_119 ;
F_7 ( L_120
L_121 , V_112 , V_147 ) ;
} else
F_7 ( L_122 , V_112 ,
strerror ( V_70 ) ) ;
}
static int F_75 ( const char * V_148 , bool V_149 ,
bool V_146 )
{
char V_78 [ V_150 ] ;
const char * V_151 ;
int V_4 ;
V_151 = F_76 () ;
if ( V_151 == NULL ) {
F_7 ( L_123 ) ;
return - V_45 ;
}
V_4 = F_1 ( V_78 , V_150 , L_25 , V_151 , V_148 ) ;
if ( V_4 >= 0 ) {
F_3 ( L_124 , V_78 , V_149 ) ;
if ( V_149 && ! V_152 )
V_4 = F_77 ( V_78 , V_153 , V_154 ) ;
else
V_4 = F_77 ( V_78 , V_155 , 0 ) ;
if ( V_4 < 0 )
F_74 ( V_78 , V_146 ) ;
}
return V_4 ;
}
static int F_78 ( bool V_149 )
{
return F_75 ( L_125 , V_149 , true ) ;
}
static int F_79 ( bool V_149 )
{
return F_75 ( L_126 , V_149 , false ) ;
}
static struct V_156 * F_80 ( int V_157 )
{
int V_4 , V_158 ;
T_4 * V_74 ;
char V_78 [ V_142 ] ;
char * V_136 ;
struct V_156 * V_159 ;
V_159 = F_81 ( true , NULL ) ;
V_74 = fdopen ( F_82 ( V_157 ) , L_36 ) ;
while ( ! feof ( V_74 ) ) {
V_136 = fgets ( V_78 , V_142 , V_74 ) ;
if ( ! V_136 )
break;
V_158 = strlen ( V_136 ) - 1 ;
if ( V_136 [ V_158 ] == '\n' )
V_136 [ V_158 ] = '\0' ;
V_4 = F_83 ( V_159 , V_78 ) ;
if ( V_4 < 0 ) {
F_3 ( L_127 , strerror ( - V_4 ) ) ;
F_52 ( V_159 ) ;
return NULL ;
}
}
fclose ( V_74 ) ;
return V_159 ;
}
static int F_84 ( struct V_56 * V_57 )
{
int V_53 , V_4 ;
char V_78 [ 128 ] ;
char * V_160 ;
V_160 = F_35 ( & V_57 -> V_55 ) ;
if ( ! V_160 )
return - V_101 ;
V_4 = F_1 ( V_78 , 128 , L_128 , V_57 -> V_118 , V_57 -> V_117 ) ;
if ( V_4 < 0 )
return V_4 ;
printf ( L_129 , V_78 , V_160 ) ;
if ( V_57 -> V_133 > 0 ) {
printf ( L_130 ) ;
for ( V_53 = 0 ; V_53 < V_57 -> V_133 ; V_53 ++ ) {
V_4 = F_67 ( & V_57 -> args [ V_53 ] ,
V_78 , 128 ) ;
if ( V_4 < 0 )
break;
printf ( L_131 , V_78 ) ;
}
}
printf ( L_132 ) ;
free ( V_160 ) ;
return V_4 ;
}
static int F_85 ( int V_157 , bool V_146 )
{
int V_4 = 0 ;
struct V_50 V_134 ;
struct V_56 V_57 ;
struct V_156 * V_161 ;
struct V_95 * V_162 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_161 = F_80 ( V_157 ) ;
if ( ! V_161 )
return - V_45 ;
F_50 (ent, rawlist) {
V_4 = F_66 ( V_162 -> V_103 , & V_134 ) ;
if ( V_4 >= 0 ) {
V_4 = F_71 ( & V_134 , & V_57 ,
V_146 ) ;
if ( V_4 >= 0 )
V_4 = F_84 ( & V_57 ) ;
}
F_72 ( & V_57 ) ;
F_73 ( & V_134 ) ;
if ( V_4 < 0 )
break;
}
F_52 ( V_161 ) ;
return V_4 ;
}
int F_86 ( void )
{
int V_157 , V_4 ;
F_43 () ;
V_157 = F_78 ( false ) ;
if ( V_157 < 0 )
return V_157 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_85 ( V_157 , true ) ;
F_87 ( V_157 ) ;
V_157 = F_79 ( false ) ;
if ( V_157 >= 0 ) {
V_4 = F_85 ( V_157 , false ) ;
F_87 ( V_157 ) ;
}
return V_4 ;
}
static struct V_156 * F_88 ( int V_157 , bool V_163 )
{
char V_78 [ 128 ] ;
struct V_156 * V_159 , * V_161 ;
struct V_95 * V_162 ;
struct V_50 V_134 ;
int V_4 = 0 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_161 = F_80 ( V_157 ) ;
V_159 = F_81 ( true , NULL ) ;
F_50 (ent, rawlist) {
V_4 = F_66 ( V_162 -> V_103 , & V_134 ) ;
if ( V_4 < 0 )
break;
if ( V_163 ) {
V_4 = F_1 ( V_78 , 128 , L_128 , V_134 . V_118 ,
V_134 . V_117 ) ;
if ( V_4 >= 0 )
V_4 = F_83 ( V_159 , V_78 ) ;
} else
V_4 = F_83 ( V_159 , V_134 . V_117 ) ;
F_73 ( & V_134 ) ;
if ( V_4 < 0 )
break;
}
F_52 ( V_161 ) ;
if ( V_4 < 0 ) {
F_52 ( V_159 ) ;
return NULL ;
}
return V_159 ;
}
static int F_89 ( int V_157 , struct V_50 * V_134 )
{
int V_4 = 0 ;
char * V_78 = F_70 ( V_134 ) ;
if ( ! V_78 ) {
F_3 ( L_133 ) ;
return - V_101 ;
}
F_3 ( L_134 , V_78 ) ;
if ( ! V_152 ) {
V_4 = F_90 ( V_157 , V_78 , strlen ( V_78 ) ) ;
if ( V_4 <= 0 )
F_7 ( L_135 ,
strerror ( V_70 ) ) ;
}
free ( V_78 ) ;
return V_4 ;
}
static int F_91 ( char * V_78 , T_1 V_140 , const char * V_164 ,
struct V_156 * V_165 , bool V_166 )
{
int V_53 , V_4 ;
V_4 = F_1 ( V_78 , V_140 , L_28 , V_164 ) ;
if ( V_4 < 0 ) {
F_3 ( L_136 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_92 ( V_165 , V_78 ) )
return 0 ;
if ( ! V_166 ) {
F_7 ( L_137
L_138 , V_164 ) ;
return - V_167 ;
}
for ( V_53 = 1 ; V_53 < V_168 ; V_53 ++ ) {
V_4 = F_1 ( V_78 , V_140 , L_139 , V_164 , V_53 ) ;
if ( V_4 < 0 ) {
F_3 ( L_136 , strerror ( - V_4 ) ) ;
return V_4 ;
}
if ( ! F_92 ( V_165 , V_78 ) )
break;
}
if ( V_53 == V_168 ) {
F_7 ( L_140 ) ;
V_4 = - V_132 ;
}
return V_4 ;
}
static int F_93 ( struct V_56 * V_57 ,
struct V_50 * V_51 ,
int V_52 , bool V_166 )
{
int V_53 , V_157 , V_4 ;
struct V_50 * V_134 = NULL ;
char V_78 [ 64 ] ;
const char * V_117 , * V_118 ;
struct V_156 * V_165 ;
if ( V_57 -> V_61 )
V_157 = F_79 ( true ) ;
else
V_157 = F_78 ( true ) ;
if ( V_157 < 0 )
return V_157 ;
V_165 = F_88 ( V_157 , false ) ;
if ( ! V_165 ) {
F_3 ( L_141 ) ;
return - V_169 ;
}
V_4 = 0 ;
printf ( L_142 , ( V_52 > 1 ) ? L_143 : L_117 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_134 = & V_51 [ V_53 ] ;
if ( V_57 -> V_117 )
V_117 = V_57 -> V_117 ;
else
if ( V_57 -> V_55 . V_37 )
V_117 = V_57 -> V_55 . V_37 ;
else
V_117 = V_134 -> V_55 . V_14 ;
if ( V_57 -> V_118 )
V_118 = V_57 -> V_118 ;
else
V_118 = V_170 ;
V_4 = F_91 ( V_78 , 64 , V_117 ,
V_165 , V_166 ) ;
if ( V_4 < 0 )
break;
V_117 = V_78 ;
V_134 -> V_117 = F_22 ( V_117 ) ;
V_134 -> V_118 = F_22 ( V_118 ) ;
if ( V_134 -> V_117 == NULL || V_134 -> V_118 == NULL ) {
V_4 = - V_38 ;
break;
}
V_4 = F_89 ( V_157 , V_134 ) ;
if ( V_4 < 0 )
break;
F_83 ( V_165 , V_117 ) ;
V_117 = V_57 -> V_117 ;
V_118 = V_57 -> V_118 ;
V_57 -> V_117 = V_134 -> V_117 ;
V_57 -> V_118 = V_134 -> V_118 ;
F_84 ( V_57 ) ;
V_57 -> V_117 = ( char * ) V_117 ;
V_57 -> V_118 = ( char * ) V_118 ;
V_166 = true ;
}
if ( V_4 >= 0 ) {
printf ( L_144 ) ;
printf ( L_145 , V_134 -> V_118 ,
V_134 -> V_117 ) ;
}
F_52 ( V_165 ) ;
F_87 ( V_157 ) ;
return V_4 ;
}
static int F_94 ( struct V_56 * V_57 ,
struct V_50 * * V_51 ,
int V_58 , const char * V_59 )
{
struct V_14 * V_43 ;
int V_4 = 0 , V_53 ;
struct V_50 * V_134 ;
V_4 = F_31 ( V_57 , V_51 , V_58 , V_59 ) ;
if ( V_4 != 0 )
return V_4 ;
V_134 = * V_51 = F_62 ( sizeof( struct V_50 ) ) ;
if ( V_134 == NULL )
return - V_38 ;
V_134 -> V_55 . V_14 = F_22 ( V_57 -> V_55 . V_37 ) ;
if ( V_134 -> V_55 . V_14 == NULL ) {
V_4 = - V_38 ;
goto error;
}
if ( V_59 ) {
V_134 -> V_55 . V_18 = F_22 ( V_59 ) ;
if ( V_134 -> V_55 . V_18 == NULL ) {
V_4 = - V_38 ;
goto error;
}
}
V_134 -> V_55 . V_39 = V_57 -> V_55 . V_39 ;
V_134 -> V_55 . V_40 = V_57 -> V_55 . V_40 ;
V_134 -> V_133 = V_57 -> V_133 ;
V_134 -> V_61 = V_57 -> V_61 ;
if ( V_134 -> V_133 ) {
V_134 -> args = F_62 ( sizeof( struct V_137 )
* V_134 -> V_133 ) ;
if ( V_134 -> args == NULL ) {
V_4 = - V_38 ;
goto error;
}
for ( V_53 = 0 ; V_53 < V_134 -> V_133 ; V_53 ++ ) {
if ( V_57 -> args [ V_53 ] . V_15 ) {
V_134 -> args [ V_53 ] . V_15 = F_22 ( V_57 -> args [ V_53 ] . V_15 ) ;
if ( V_134 -> args [ V_53 ] . V_15 == NULL ) {
V_4 = - V_38 ;
goto error;
}
}
V_134 -> args [ V_53 ] . V_138 = F_22 ( V_57 -> args [ V_53 ] . V_100 ) ;
if ( V_134 -> args [ V_53 ] . V_138 == NULL ) {
V_4 = - V_38 ;
goto error;
}
if ( V_57 -> args [ V_53 ] . type ) {
V_134 -> args [ V_53 ] . type = F_22 ( V_57 -> args [ V_53 ] . type ) ;
if ( V_134 -> args [ V_53 ] . type == NULL ) {
V_4 = - V_38 ;
goto error;
}
}
}
}
if ( V_57 -> V_61 )
return 1 ;
V_43 = F_8 ( V_134 -> V_55 . V_14 , NULL ) ;
if ( ! V_43 ) {
F_7 ( L_146 ,
V_134 -> V_55 . V_14 ) ;
V_4 = - V_45 ;
goto error;
} else if ( V_134 -> V_55 . V_39 > V_43 -> V_87 - V_43 -> V_48 ) {
F_7 ( L_147 ,
V_134 -> V_55 . V_14 ) ;
V_4 = - V_45 ;
goto error;
}
return 1 ;
error:
F_73 ( V_134 ) ;
free ( V_134 ) ;
* V_51 = NULL ;
return V_4 ;
}
int F_95 ( struct V_56 * V_104 , int V_105 ,
int V_58 , const char * V_59 , bool V_171 )
{
int V_53 , V_172 , V_4 ;
struct V_173 * V_174 ;
V_4 = 0 ;
V_174 = F_62 ( sizeof( struct V_173 ) * V_105 ) ;
if ( V_174 == NULL )
return - V_38 ;
if ( ! V_104 -> V_61 )
V_4 = F_2 () ;
else
V_4 = F_20 () ;
if ( V_4 < 0 ) {
free ( V_174 ) ;
return V_4 ;
}
for ( V_53 = 0 ; V_53 < V_105 ; V_53 ++ ) {
V_174 [ V_53 ] . V_57 = & V_104 [ V_53 ] ;
V_4 = F_94 ( V_174 [ V_53 ] . V_57 ,
& V_174 [ V_53 ] . V_51 ,
V_58 ,
V_59 ) ;
if ( V_4 < 0 )
goto V_87;
V_174 [ V_53 ] . V_52 = V_4 ;
}
for ( V_53 = 0 ; V_53 < V_105 ; V_53 ++ ) {
V_4 = F_93 ( V_174 [ V_53 ] . V_57 , V_174 [ V_53 ] . V_51 ,
V_174 [ V_53 ] . V_52 , V_171 ) ;
if ( V_4 < 0 )
break;
}
V_87:
for ( V_53 = 0 ; V_53 < V_105 ; V_53 ++ ) {
for ( V_172 = 0 ; V_172 < V_174 [ V_53 ] . V_52 ; V_172 ++ )
F_73 ( & V_174 [ V_53 ] . V_51 [ V_172 ] ) ;
free ( V_174 [ V_53 ] . V_51 ) ;
}
free ( V_174 ) ;
return V_4 ;
}
static int F_96 ( int V_157 , struct V_95 * V_162 )
{
char * V_136 ;
char V_78 [ 128 ] ;
int V_4 ;
V_4 = F_1 ( V_78 , 128 , L_148 , V_162 -> V_103 ) ;
if ( V_4 < 0 )
goto error;
V_136 = strchr ( V_78 + 2 , ':' ) ;
if ( ! V_136 ) {
F_3 ( L_149 ,
V_162 -> V_103 ) ;
V_4 = - V_116 ;
goto error;
}
* V_136 = '/' ;
F_3 ( L_134 , V_78 ) ;
V_4 = F_90 ( V_157 , V_78 , strlen ( V_78 ) ) ;
if ( V_4 < 0 ) {
V_4 = - V_70 ;
goto error;
}
printf ( L_150 , V_162 -> V_103 ) ;
return 0 ;
error:
F_7 ( L_151 , strerror ( - V_4 ) ) ;
return V_4 ;
}
static int F_97 ( int V_157 , const char * V_78 ,
struct V_156 * V_165 )
{
struct V_95 * V_162 , * V_175 ;
int V_4 = - 1 ;
if ( strpbrk ( V_78 , L_152 ) ) {
F_98 (ent, n, namelist)
if ( F_99 ( V_162 -> V_103 , V_78 ) ) {
V_4 = F_96 ( V_157 , V_162 ) ;
if ( V_4 < 0 )
break;
F_100 ( V_165 , V_162 ) ;
}
} else {
V_162 = F_101 ( V_165 , V_78 ) ;
if ( V_162 ) {
V_4 = F_96 ( V_157 , V_162 ) ;
if ( V_4 >= 0 )
F_100 ( V_165 , V_162 ) ;
}
}
return V_4 ;
}
int F_102 ( struct V_156 * V_176 )
{
int V_4 = - 1 , V_177 = - 1 , V_178 = - 1 ;
char V_78 [ 128 ] ;
const char * V_118 , * V_117 ;
char * V_136 , * V_1 ;
struct V_95 * V_162 ;
struct V_156 * V_165 = NULL , * V_179 = NULL ;
V_178 = F_78 ( true ) ;
if ( V_178 < 0 )
return V_178 ;
V_165 = F_88 ( V_178 , true ) ;
V_177 = F_79 ( true ) ;
if ( V_177 >= 0 )
V_179 = F_88 ( V_177 , true ) ;
if ( V_165 == NULL && V_179 == NULL )
goto error;
F_50 (ent, dellist) {
V_1 = F_22 ( V_162 -> V_103 ) ;
if ( V_1 == NULL ) {
V_4 = - V_38 ;
goto error;
}
F_3 ( L_153 , V_1 ) ;
V_136 = strchr ( V_1 , ':' ) ;
if ( V_136 ) {
V_118 = V_1 ;
* V_136 = '\0' ;
V_117 = V_136 + 1 ;
} else {
V_118 = L_154 ;
V_117 = V_1 ;
}
V_4 = F_1 ( V_78 , 128 , L_128 , V_118 , V_117 ) ;
if ( V_4 < 0 ) {
F_24 ( L_155 ) ;
free ( V_1 ) ;
goto error;
}
F_3 ( L_156 , V_118 , V_117 ) ;
if ( V_165 )
V_4 = F_97 ( V_178 , V_78 , V_165 ) ;
if ( V_179 && V_4 != 0 )
V_4 = F_97 ( V_177 , V_78 , V_179 ) ;
if ( V_4 != 0 )
F_103 ( L_157 , V_78 ) ;
free ( V_1 ) ;
}
error:
if ( V_178 >= 0 ) {
F_52 ( V_165 ) ;
F_87 ( V_178 ) ;
}
if ( V_177 >= 0 ) {
F_52 ( V_179 ) ;
F_87 ( V_177 ) ;
}
return V_4 ;
}
static int F_104 ( struct V_16 * V_16 V_106 ,
struct V_14 * V_43 )
{
if ( V_43 -> V_180 == V_181 &&
F_51 ( V_182 , V_43 -> V_15 ) )
return 0 ;
return 1 ;
}
static int F_105 ( struct V_16 * V_16 )
{
if ( F_106 ( V_16 , F_104 ) ) {
F_24 ( L_158 ) ;
return - V_101 ;
}
if ( ! F_107 ( V_16 -> V_27 , V_16 -> type ) )
F_108 ( V_16 -> V_27 , V_16 -> type ) ;
F_109 ( V_16 -> V_27 , V_16 -> type , stdout ) ;
return 0 ;
}
static int F_110 ( const char * V_18 )
{
struct V_16 * V_16 ;
int V_4 ;
V_4 = F_2 () ;
if ( V_4 < 0 )
return V_4 ;
V_16 = F_10 ( V_18 ) ;
if ( ! V_16 ) {
F_24 ( L_159 , ( V_18 ) ? : L_6 ) ;
return - V_101 ;
}
return F_105 ( V_16 ) ;
}
static int F_111 ( const char * V_59 )
{
struct V_16 * V_16 ;
int V_4 ;
V_4 = F_20 () ;
if ( V_4 < 0 )
return V_4 ;
V_16 = F_112 ( V_59 ) ;
V_4 = F_105 ( V_16 ) ;
F_113 ( V_16 -> V_27 ) ;
F_114 ( V_16 ) ;
return V_4 ;
}
int F_115 ( const char * V_59 , struct V_91 * V_92 ,
bool V_183 )
{
F_43 () ;
V_182 = V_92 ;
if ( ! V_183 )
return F_110 ( V_59 ) ;
return F_111 ( V_59 ) ;
}
static int F_33 ( struct V_56 * V_57 , const char * V_184 )
{
struct V_35 * V_36 = & V_57 -> V_55 ;
struct V_14 * V_43 ;
struct V_16 * V_16 = NULL ;
char * V_37 = NULL , * V_15 = NULL ;
int V_4 = - V_101 ;
unsigned long long V_185 = 0 ;
if ( ! V_36 -> V_37 ) {
F_7 ( L_160 ) ;
goto V_11;
}
V_37 = F_22 ( V_36 -> V_37 ) ;
if ( ! V_37 ) {
F_7 ( L_161 ) ;
V_4 = - V_38 ;
goto V_11;
}
V_15 = F_116 ( V_184 , NULL ) ;
if ( ! V_15 ) {
F_7 ( L_162 , V_184 ) ;
goto V_11;
}
V_16 = F_112 ( V_15 ) ;
if ( ! V_16 ) {
F_7 ( L_163 , V_184 ) ;
goto V_11;
}
V_182 = F_117 ( V_37 , NULL ) ;
if ( F_106 ( V_16 , F_104 ) ) {
F_24 ( L_158 ) ;
goto V_11;
}
V_43 = F_118 ( V_16 , V_37 , NULL ) ;
if ( ! V_43 ) {
F_7 ( L_164 , V_37 , V_184 ) ;
goto V_11;
}
if ( V_16 -> V_48 > V_43 -> V_48 )
V_185 = V_16 -> V_48 ;
V_185 += V_43 -> V_48 + V_36 -> V_39 + V_16 -> V_186 ;
V_36 -> V_39 = 0 ;
if ( ! V_57 -> V_117 ) {
V_57 -> V_117 = V_37 ;
V_37 = NULL ;
}
if ( ! V_57 -> V_118 ) {
char * V_187 , * V_188 ;
V_57 -> V_118 = F_62 ( sizeof( char * ) * 64 ) ;
V_187 = F_22 ( F_119 ( V_184 ) ) ;
if ( V_187 ) {
V_188 = strpbrk ( V_187 , L_165 ) ;
if ( V_188 )
* V_188 = '\0' ;
F_1 ( V_57 -> V_118 , 64 , L_166 , V_170 ,
V_187 ) ;
free ( V_187 ) ;
}
}
free ( V_36 -> V_37 ) ;
V_36 -> V_37 = F_62 ( sizeof( char * ) * V_131 ) ;
if ( ! V_36 -> V_37 ) {
V_4 = - V_38 ;
F_7 ( L_167 ) ;
goto V_11;
}
F_1 ( V_36 -> V_37 , V_131 , L_168 , V_185 ) ;
V_4 = 0 ;
V_11:
if ( V_16 ) {
F_113 ( V_16 -> V_27 ) ;
F_114 ( V_16 ) ;
}
if ( V_37 )
free ( V_37 ) ;
if ( V_15 )
free ( V_15 ) ;
return V_4 ;
}
