static inline const char * F_1 ( const char * V_1 )
{
const char * V_2 = strrchr ( V_1 , '/' ) ;
return V_2 ? V_2 + 1 : V_1 ;
}
static inline const char * F_2 ( const char * V_1 )
{
int V_3 = strlen ( __FILE__ ) - strlen ( L_1 ) ;
if ( strncmp ( V_1 , __FILE__ , V_3 ) )
V_3 = 0 ;
return V_1 + V_3 ;
}
static char * F_3 ( struct V_4 * V_5 , char * V_6 ,
T_1 V_7 )
{
char * V_8 = V_6 ;
int V_9 ;
F_4 ( V_7 < 6 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; ++ V_9 )
if ( V_5 -> V_11 & V_10 [ V_9 ] . V_12 )
* V_8 ++ = V_10 [ V_9 ] . V_13 ;
if ( V_8 == V_6 )
* V_8 ++ = '_' ;
* V_8 = '\0' ;
return V_6 ;
}
static int F_6 ( const struct V_14 * V_15 ,
unsigned int V_11 , unsigned int V_16 )
{
int V_9 ;
struct V_17 * V_18 ;
unsigned int V_19 ;
unsigned int V_20 = 0 ;
char V_21 [ 10 ] ;
F_7 ( & V_22 ) ;
F_8 (dt, &ddebug_tables, link) {
if ( V_15 -> V_23 && strcmp ( V_15 -> V_23 , V_18 -> V_24 ) )
continue;
for ( V_9 = 0 ; V_9 < V_18 -> V_25 ; V_9 ++ ) {
struct V_4 * V_5 = & V_18 -> V_26 [ V_9 ] ;
if ( V_15 -> V_27 &&
strcmp ( V_15 -> V_27 , V_5 -> V_27 ) &&
strcmp ( V_15 -> V_27 , F_1 ( V_5 -> V_27 ) ) &&
strcmp ( V_15 -> V_27 , F_2 ( V_5 -> V_27 ) ) )
continue;
if ( V_15 -> V_28 &&
strcmp ( V_15 -> V_28 , V_5 -> V_28 ) )
continue;
if ( V_15 -> V_29 &&
! strstr ( V_5 -> V_29 , V_15 -> V_29 ) )
continue;
if ( V_15 -> V_30 &&
V_5 -> V_31 < V_15 -> V_30 )
continue;
if ( V_15 -> V_32 &&
V_5 -> V_31 > V_15 -> V_32 )
continue;
V_20 ++ ;
V_19 = ( V_5 -> V_11 & V_16 ) | V_11 ;
if ( V_19 == V_5 -> V_11 )
continue;
V_5 -> V_11 = V_19 ;
F_9 ( L_2 ,
F_2 ( V_5 -> V_27 ) , V_5 -> V_31 ,
V_18 -> V_24 , V_5 -> V_28 ,
F_3 ( V_5 , V_21 ,
sizeof( V_21 ) ) ) ;
}
}
F_10 ( & V_22 ) ;
if ( ! V_20 && V_33 )
F_11 ( L_3 ) ;
return V_20 ;
}
static int F_12 ( char * V_6 , char * V_34 [] , int V_35 )
{
int V_36 = 0 ;
while ( * V_6 ) {
char * V_37 ;
V_6 = F_13 ( V_6 ) ;
if ( ! * V_6 )
break;
if ( * V_6 == '#' )
break;
if ( * V_6 == '"' || * V_6 == '\'' ) {
int V_38 = * V_6 ++ ;
for ( V_37 = V_6 ; * V_37 && * V_37 != V_38 ; V_37 ++ )
;
if ( ! * V_37 )
return - V_39 ;
} else {
for ( V_37 = V_6 ; * V_37 && ! isspace ( * V_37 ) ; V_37 ++ )
;
F_4 ( V_37 == V_6 ) ;
}
if ( V_36 == V_35 )
return - V_39 ;
if ( * V_37 )
* V_37 ++ = '\0' ;
V_34 [ V_36 ++ ] = V_6 ;
V_6 = V_37 ;
}
if ( V_33 ) {
int V_9 ;
F_11 ( L_4 ) ;
for ( V_9 = 0 ; V_9 < V_36 ; V_9 ++ )
F_14 ( L_5 , V_34 [ V_9 ] ) ;
F_14 ( L_6 ) ;
}
return V_36 ;
}
static inline int F_15 ( const char * V_40 , unsigned int * V_41 )
{
char * V_37 = NULL ;
F_4 ( V_40 == NULL ) ;
if ( * V_40 == '\0' ) {
* V_41 = 0 ;
return 0 ;
}
* V_41 = F_16 ( V_40 , & V_37 , 10 ) ;
return V_37 == NULL || V_37 == V_40 || * V_37 != '\0' ? - V_39 : 0 ;
}
static char * F_17 ( char * V_40 )
{
char * V_42 = V_40 ;
char * V_43 = V_40 ;
while ( * V_42 ) {
if ( * V_42 == '\\' ) {
if ( V_42 [ 1 ] == '\\' ) {
* V_43 ++ = '\\' ;
V_42 += 2 ;
continue;
} else if ( V_42 [ 1 ] == 't' ) {
* V_43 ++ = '\t' ;
V_42 += 2 ;
continue;
} else if ( V_42 [ 1 ] == 'n' ) {
* V_43 ++ = '\n' ;
V_42 += 2 ;
continue;
} else if ( F_18 ( V_42 [ 1 ] ) &&
F_18 ( V_42 [ 2 ] ) &&
F_18 ( V_42 [ 3 ] ) ) {
* V_43 ++ = ( ( V_42 [ 1 ] - '0' ) << 6 ) |
( ( V_42 [ 2 ] - '0' ) << 3 ) |
( V_42 [ 3 ] - '0' ) ;
V_42 += 4 ;
continue;
}
}
* V_43 ++ = * V_42 ++ ;
}
* V_43 = '\0' ;
return V_40 ;
}
static int F_19 ( const char * * V_44 , char * V_45 , char * V_46 )
{
int V_47 = 0 ;
if ( * V_44 ) {
V_47 = - V_39 ;
F_20 ( L_7 ,
V_46 , * V_44 , V_45 ) ;
}
* V_44 = V_45 ;
return V_47 ;
}
static int F_21 ( char * V_34 [] , int V_36 ,
struct V_14 * V_15 , const char * V_48 )
{
unsigned int V_9 ;
int V_47 ;
if ( V_36 % 2 != 0 )
return - V_39 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
if ( V_48 )
V_15 -> V_23 = V_48 ;
for ( V_9 = 0 ; V_9 < V_36 ; V_9 += 2 ) {
if ( ! strcmp ( V_34 [ V_9 ] , L_8 ) )
V_47 = F_19 ( & V_15 -> V_28 , V_34 [ V_9 + 1 ] , L_8 ) ;
else if ( ! strcmp ( V_34 [ V_9 ] , L_9 ) )
V_47 = F_19 ( & V_15 -> V_27 , V_34 [ V_9 + 1 ] , L_9 ) ;
else if ( ! strcmp ( V_34 [ V_9 ] , L_10 ) )
V_47 = F_19 ( & V_15 -> V_23 , V_34 [ V_9 + 1 ] , L_10 ) ;
else if ( ! strcmp ( V_34 [ V_9 ] , L_11 ) )
V_47 = F_19 ( & V_15 -> V_29 , F_17 ( V_34 [ V_9 + 1 ] ) ,
L_11 ) ;
else if ( ! strcmp ( V_34 [ V_9 ] , L_12 ) ) {
char * V_49 = V_34 [ V_9 + 1 ] ;
char * V_50 = strchr ( V_49 , '-' ) ;
if ( V_15 -> V_30 || V_15 -> V_32 ) {
F_20 ( L_13 ) ;
return - V_39 ;
}
if ( V_50 )
* V_50 ++ = '\0' ;
if ( F_15 ( V_49 , & V_15 -> V_30 ) < 0 )
return - V_39 ;
if ( V_50 ) {
if ( F_15 ( V_50 , & V_15 -> V_32 )
< V_15 -> V_30 ) {
F_20 ( L_14 ) ;
return - V_39 ;
}
} else {
V_15 -> V_32 = V_15 -> V_30 ;
}
} else {
F_20 ( L_15 , V_34 [ V_9 ] ) ;
return - V_39 ;
}
if ( V_47 )
return V_47 ;
}
F_22 ( V_15 , L_16 ) ;
return 0 ;
}
static int F_23 ( const char * V_40 , unsigned int * V_51 ,
unsigned int * V_52 )
{
unsigned V_11 = 0 ;
int V_53 = '=' , V_9 ;
switch ( * V_40 ) {
case '+' :
case '-' :
case '=' :
V_53 = * V_40 ++ ;
break;
default:
return - V_39 ;
}
F_9 ( L_17 , V_53 ) ;
for ( ; * V_40 ; ++ V_40 ) {
for ( V_9 = F_5 ( V_10 ) - 1 ; V_9 >= 0 ; V_9 -- ) {
if ( * V_40 == V_10 [ V_9 ] . V_13 ) {
V_11 |= V_10 [ V_9 ] . V_12 ;
break;
}
}
if ( V_9 < 0 )
return - V_39 ;
}
F_9 ( L_18 , V_11 ) ;
switch ( V_53 ) {
case '=' :
* V_52 = 0 ;
* V_51 = V_11 ;
break;
case '+' :
* V_52 = ~ 0U ;
* V_51 = V_11 ;
break;
case '-' :
* V_52 = ~ V_11 ;
* V_51 = 0 ;
break;
}
F_9 ( L_19 , * V_51 , * V_52 ) ;
return 0 ;
}
static int F_24 ( char * V_54 , const char * V_48 )
{
unsigned int V_11 = 0 , V_16 = 0 ;
struct V_14 V_15 ;
#define F_25 9
int V_36 , V_20 ;
char * V_34 [ F_25 ] ;
V_36 = F_12 ( V_54 , V_34 , F_25 ) ;
if ( V_36 <= 0 )
return - V_39 ;
if ( F_21 ( V_34 , V_36 - 1 , & V_15 , V_48 ) )
return - V_39 ;
if ( F_23 ( V_34 [ V_36 - 1 ] , & V_11 , & V_16 ) )
return - V_39 ;
V_20 = F_6 ( & V_15 , V_11 , V_16 ) ;
F_22 ( ( & V_15 ) , ( V_20 ) ? L_20 : L_21 ) ;
return V_20 ;
}
static int F_26 ( char * V_15 , const char * V_48 )
{
char * V_55 ;
int V_9 , V_56 = 0 , V_57 = 0 , V_47 , V_20 = 0 ;
for ( V_9 = 0 ; V_15 ; V_15 = V_55 ) {
V_55 = strpbrk ( V_15 , L_22 ) ;
if ( V_55 )
* V_55 ++ = '\0' ;
V_15 = F_13 ( V_15 ) ;
if ( ! V_15 || ! * V_15 || * V_15 == '#' )
continue;
F_9 ( L_23 , V_9 , V_15 ) ;
V_47 = F_24 ( V_15 , V_48 ) ;
if ( V_47 < 0 ) {
V_56 ++ ;
V_57 = V_47 ;
} else
V_20 += V_47 ;
V_9 ++ ;
}
F_9 ( L_24 ,
V_9 , V_20 , V_56 ) ;
if ( V_57 )
return V_57 ;
return V_20 ;
}
static int F_27 ( int V_58 )
{
if ( V_59 - V_58 > 0 )
return V_59 - V_58 ;
return 0 ;
}
static char * F_28 ( const struct V_4 * V_60 , char * V_6 )
{
int V_61 ;
int V_62 = 0 ;
V_62 += snprintf ( V_6 + V_62 , F_27 ( V_62 ) , L_25 , V_63 ) ;
if ( V_60 -> V_11 & V_64 ) {
if ( F_29 () )
V_62 += snprintf ( V_6 + V_62 , F_27 ( V_62 ) , L_26 ,
L_27 ) ;
else
V_62 += snprintf ( V_6 + V_62 , F_27 ( V_62 ) , L_28 ,
F_30 ( V_65 ) ) ;
}
V_61 = V_62 ;
if ( V_60 -> V_11 & V_66 )
V_62 += snprintf ( V_6 + V_62 , F_27 ( V_62 ) , L_29 ,
V_60 -> V_48 ) ;
if ( V_60 -> V_11 & V_67 )
V_62 += snprintf ( V_6 + V_62 , F_27 ( V_62 ) , L_29 ,
V_60 -> V_28 ) ;
if ( V_60 -> V_11 & V_68 )
V_62 += snprintf ( V_6 + V_62 , F_27 ( V_62 ) , L_30 ,
V_60 -> V_31 ) ;
if ( V_62 - V_61 )
V_62 += snprintf ( V_6 + V_62 , F_27 ( V_62 ) , L_31 ) ;
if ( V_62 >= V_59 )
V_6 [ V_59 - 1 ] = '\0' ;
return V_6 ;
}
int F_31 ( struct V_4 * V_69 , const char * V_70 , ... )
{
T_2 args ;
int V_71 ;
struct V_72 V_73 ;
char V_6 [ V_59 ] ;
F_4 ( ! V_69 ) ;
F_4 ( ! V_70 ) ;
va_start ( args , V_70 ) ;
V_73 . V_70 = V_70 ;
V_73 . V_74 = & args ;
V_71 = F_32 ( L_32 , F_28 ( V_69 , V_6 ) , & V_73 ) ;
va_end ( args ) ;
return V_71 ;
}
int F_33 ( struct V_4 * V_69 ,
const struct V_75 * V_76 , const char * V_70 , ... )
{
struct V_72 V_73 ;
T_2 args ;
int V_71 ;
char V_6 [ V_59 ] ;
F_4 ( ! V_69 ) ;
F_4 ( ! V_70 ) ;
va_start ( args , V_70 ) ;
V_73 . V_70 = V_70 ;
V_73 . V_74 = & args ;
V_71 = F_34 ( F_28 ( V_69 , V_6 ) , V_76 , & V_73 ) ;
va_end ( args ) ;
return V_71 ;
}
int F_35 ( struct V_4 * V_69 ,
const struct V_77 * V_76 , const char * V_70 , ... )
{
struct V_72 V_73 ;
T_2 args ;
int V_71 ;
char V_6 [ V_59 ] ;
F_4 ( ! V_69 ) ;
F_4 ( ! V_70 ) ;
va_start ( args , V_70 ) ;
V_73 . V_70 = V_70 ;
V_73 . V_74 = & args ;
V_71 = F_36 ( F_28 ( V_69 , V_6 ) , V_76 , & V_73 ) ;
va_end ( args ) ;
return V_71 ;
}
static T_3 int F_37 ( char * V_40 )
{
if ( strlen ( V_40 ) >= V_78 ) {
F_38 ( L_33 ) ;
return 0 ;
}
F_39 ( V_79 , V_40 , V_78 ) ;
return 1 ;
}
static T_4 F_40 ( struct V_80 * V_80 , const char T_5 * V_81 ,
T_1 V_82 , T_6 * V_83 )
{
char * V_84 ;
int V_85 ;
if ( V_82 == 0 )
return 0 ;
if ( V_82 > V_86 - 1 ) {
F_38 ( L_34 , V_86 ) ;
return - V_87 ;
}
V_84 = F_41 ( V_82 + 1 , V_88 ) ;
if ( ! V_84 )
return - V_89 ;
if ( F_42 ( V_84 , V_81 , V_82 ) ) {
F_43 ( V_84 ) ;
return - V_90 ;
}
V_84 [ V_82 ] = '\0' ;
F_9 ( L_35 , ( int ) V_82 ) ;
V_85 = F_26 ( V_84 , NULL ) ;
F_43 ( V_84 ) ;
if ( V_85 < 0 )
return V_85 ;
* V_83 += V_82 ;
return V_82 ;
}
static struct V_4 * F_44 ( struct V_91 * V_92 )
{
if ( F_45 ( & V_93 ) ) {
V_92 -> V_94 = NULL ;
V_92 -> V_95 = 0 ;
return NULL ;
}
V_92 -> V_94 = F_46 ( V_93 . V_96 ,
struct V_17 , V_97 ) ;
V_92 -> V_95 = 0 ;
return & V_92 -> V_94 -> V_26 [ V_92 -> V_95 ] ;
}
static struct V_4 * F_47 ( struct V_91 * V_92 )
{
if ( V_92 -> V_94 == NULL )
return NULL ;
if ( ++ V_92 -> V_95 == V_92 -> V_94 -> V_25 ) {
V_92 -> V_95 = 0 ;
if ( F_48 ( & V_92 -> V_94 -> V_97 , & V_93 ) ) {
V_92 -> V_94 = NULL ;
return NULL ;
}
V_92 -> V_94 = F_46 ( V_92 -> V_94 -> V_97 . V_96 ,
struct V_17 , V_97 ) ;
}
return & V_92 -> V_94 -> V_26 [ V_92 -> V_95 ] ;
}
static void * F_49 ( struct V_98 * V_99 , T_6 * V_62 )
{
struct V_91 * V_92 = V_99 -> V_100 ;
struct V_4 * V_5 ;
int V_101 = * V_62 ;
F_9 ( L_36 , V_99 , ( unsigned long long ) * V_62 ) ;
F_7 ( & V_22 ) ;
if ( ! V_101 )
return V_102 ;
if ( V_101 < 0 )
return NULL ;
V_5 = F_44 ( V_92 ) ;
while ( V_5 != NULL && -- V_101 > 0 )
V_5 = F_47 ( V_92 ) ;
return V_5 ;
}
static void * F_50 ( struct V_98 * V_99 , void * V_8 , T_6 * V_62 )
{
struct V_91 * V_92 = V_99 -> V_100 ;
struct V_4 * V_5 ;
F_9 ( L_37 ,
V_99 , V_8 , ( unsigned long long ) * V_62 ) ;
if ( V_8 == V_102 )
V_5 = F_44 ( V_92 ) ;
else
V_5 = F_47 ( V_92 ) ;
++ * V_62 ;
return V_5 ;
}
static int F_51 ( struct V_98 * V_99 , void * V_8 )
{
struct V_91 * V_92 = V_99 -> V_100 ;
struct V_4 * V_5 = V_8 ;
char V_103 [ 10 ] ;
F_9 ( L_38 , V_99 , V_8 ) ;
if ( V_8 == V_102 ) {
F_52 ( V_99 ,
L_39 ) ;
return 0 ;
}
F_53 ( V_99 , L_40 ,
F_2 ( V_5 -> V_27 ) , V_5 -> V_31 ,
V_92 -> V_94 -> V_24 , V_5 -> V_28 ,
F_3 ( V_5 , V_103 , sizeof( V_103 ) ) ) ;
F_54 ( V_99 , V_5 -> V_29 , L_41 ) ;
F_52 ( V_99 , L_42 ) ;
return 0 ;
}
static void F_55 ( struct V_98 * V_99 , void * V_8 )
{
F_9 ( L_38 , V_99 , V_8 ) ;
F_10 ( & V_22 ) ;
}
static int F_56 ( struct V_104 * V_104 , struct V_80 * V_80 )
{
struct V_91 * V_92 ;
int V_105 ;
F_9 ( L_43 ) ;
V_92 = F_57 ( sizeof( * V_92 ) , V_88 ) ;
if ( V_92 == NULL )
return - V_89 ;
V_105 = F_58 ( V_80 , & V_106 ) ;
if ( V_105 ) {
F_43 ( V_92 ) ;
return V_105 ;
}
( (struct V_98 * ) V_80 -> V_107 ) -> V_100 = V_92 ;
return 0 ;
}
int F_59 ( struct V_4 * V_108 , unsigned int V_101 ,
const char * V_46 )
{
struct V_17 * V_18 ;
char * V_109 ;
V_18 = F_57 ( sizeof( * V_18 ) , V_88 ) ;
if ( V_18 == NULL )
return - V_89 ;
V_109 = F_60 ( V_46 , V_88 ) ;
if ( V_109 == NULL ) {
F_43 ( V_18 ) ;
return - V_89 ;
}
V_18 -> V_24 = V_109 ;
V_18 -> V_25 = V_101 ;
V_18 -> V_26 = V_108 ;
F_7 ( & V_22 ) ;
F_61 ( & V_18 -> V_97 , & V_93 ) ;
F_10 ( & V_22 ) ;
F_9 ( L_44 , V_101 , V_18 -> V_24 ) ;
return 0 ;
}
static int F_62 ( char * V_110 , char * V_41 ,
const char * V_48 , int V_111 )
{
char * V_112 ;
V_112 = strchr ( V_110 , '.' ) ;
if ( V_112 ) {
* V_112 = '\0' ;
V_48 = V_110 ;
V_110 = V_112 + 1 ;
}
if ( strcmp ( V_110 , L_45 ) )
return V_111 ;
F_26 ( ( V_41 ? V_41 : L_46 ) , V_48 ) ;
return 0 ;
}
static int F_63 ( char * V_110 , char * V_41 ,
const char * V_113 )
{
F_9 ( L_47 , V_110 , V_41 ) ;
return F_62 ( V_110 , V_41 , NULL , 0 ) ;
}
int F_64 ( char * V_110 , char * V_41 , const char * V_23 )
{
F_9 ( L_48 , V_23 , V_110 , V_41 ) ;
return F_62 ( V_110 , V_41 , V_23 , - V_114 ) ;
}
static void F_65 ( struct V_17 * V_18 )
{
F_66 ( & V_18 -> V_97 ) ;
F_43 ( V_18 -> V_24 ) ;
F_43 ( V_18 ) ;
}
int F_67 ( const char * V_24 )
{
struct V_17 * V_18 , * V_115 ;
int V_85 = - V_114 ;
F_9 ( L_49 , V_24 ) ;
F_7 ( & V_22 ) ;
F_68 (dt, nextdt, &ddebug_tables, link) {
if ( ! strcmp ( V_18 -> V_24 , V_24 ) ) {
F_65 ( V_18 ) ;
V_85 = 0 ;
}
}
F_10 ( & V_22 ) ;
return V_85 ;
}
static void F_69 ( void )
{
F_7 ( & V_22 ) ;
while ( ! F_45 ( & V_93 ) ) {
struct V_17 * V_18 = F_46 ( V_93 . V_96 ,
struct V_17 ,
V_97 ) ;
F_65 ( V_18 ) ;
}
F_10 ( & V_22 ) ;
}
static int T_3 F_70 ( void )
{
struct V_116 * V_117 , * V_80 ;
if ( ! V_118 )
return - V_119 ;
V_117 = F_71 ( L_50 , NULL ) ;
if ( ! V_117 )
return - V_89 ;
V_80 = F_72 ( L_51 , 0644 , V_117 , NULL ,
& V_120 ) ;
if ( ! V_80 ) {
F_73 ( V_117 ) ;
return - V_89 ;
}
return 0 ;
}
static int T_3 F_74 ( void )
{
struct V_4 * V_92 , * V_121 ;
const char * V_48 = NULL ;
char * V_122 ;
int V_85 = 0 ;
int V_101 = 0 , V_123 = 0 , V_124 = 0 ;
int V_125 = 0 ;
if ( V_126 == V_127 ) {
F_38 ( L_52
L_53 ) ;
return 1 ;
}
V_92 = V_126 ;
V_48 = V_92 -> V_48 ;
V_121 = V_92 ;
for (; V_92 < V_127 ; V_92 ++ ) {
V_123 ++ ;
V_125 += strlen ( V_92 -> V_48 ) + strlen ( V_92 -> V_28 )
+ strlen ( V_92 -> V_27 ) + strlen ( V_92 -> V_29 ) ;
if ( strcmp ( V_48 , V_92 -> V_48 ) ) {
V_124 ++ ;
V_85 = F_59 ( V_121 , V_101 , V_48 ) ;
if ( V_85 )
goto V_128;
V_101 = 0 ;
V_48 = V_92 -> V_48 ;
V_121 = V_92 ;
}
V_101 ++ ;
}
V_85 = F_59 ( V_121 , V_101 , V_48 ) ;
if ( V_85 )
goto V_128;
V_118 = 1 ;
F_9 ( L_54
L_55 ,
V_124 , V_123 , ( int ) ( V_124 * sizeof( struct V_17 ) ) ,
V_125 + ( int ) ( V_127 - V_126 ) ) ;
if ( V_79 [ 0 ] != '\0' ) {
F_38 ( L_56
L_57 ) ;
V_85 = F_26 ( V_79 , NULL ) ;
if ( V_85 < 0 )
F_38 ( L_58 ,
V_79 ) ;
else
F_11 ( L_59 , V_85 ) ;
}
V_122 = F_60 ( V_129 , V_88 ) ;
F_75 ( L_60 , V_122 , NULL ,
0 , 0 , 0 , & F_63 ) ;
F_43 ( V_122 ) ;
return 0 ;
V_128:
F_69 () ;
return 0 ;
}
