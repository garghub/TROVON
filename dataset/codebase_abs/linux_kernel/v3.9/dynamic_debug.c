static inline const char * F_1 ( const char * V_1 )
{
int V_2 = strlen ( __FILE__ ) - strlen ( L_1 ) ;
if ( strncmp ( V_1 , __FILE__ , V_2 ) )
V_2 = 0 ;
return V_1 + V_2 ;
}
static char * F_2 ( struct V_3 * V_4 , char * V_5 ,
T_1 V_6 )
{
char * V_7 = V_5 ;
int V_8 ;
F_3 ( V_6 < 6 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_9 ) ; ++ V_8 )
if ( V_4 -> V_10 & V_9 [ V_8 ] . V_11 )
* V_7 ++ = V_9 [ V_8 ] . V_12 ;
if ( V_7 == V_5 )
* V_7 ++ = '_' ;
* V_7 = '\0' ;
return V_5 ;
}
static void F_5 ( const struct V_13 * V_14 , const char * V_15 )
{
int V_16 = 0 ;
if ( V_14 -> V_17 ) {
V_16 = strlen ( V_14 -> V_17 ) ;
while ( V_16 && V_14 -> V_17 [ V_16 - 1 ] == '\n' )
V_16 -- ;
}
F_6 ( L_2 ,
V_15 ,
V_14 -> V_18 ? V_14 -> V_18 : L_3 ,
V_14 -> V_19 ? V_14 -> V_19 : L_3 ,
V_14 -> V_20 ? V_14 -> V_20 : L_3 ,
V_16 , V_14 -> V_17 ? V_14 -> V_17 : L_3 ,
V_14 -> V_21 , V_14 -> V_22 ) ;
}
static int F_7 ( const struct V_13 * V_14 ,
unsigned int V_10 , unsigned int V_23 )
{
int V_8 ;
struct V_24 * V_25 ;
unsigned int V_26 ;
unsigned int V_27 = 0 ;
char V_28 [ 10 ] ;
F_8 ( & V_29 ) ;
F_9 (dt, &ddebug_tables, link) {
if ( V_14 -> V_20 && strcmp ( V_14 -> V_20 , V_25 -> V_30 ) )
continue;
for ( V_8 = 0 ; V_8 < V_25 -> V_31 ; V_8 ++ ) {
struct V_3 * V_4 = & V_25 -> V_32 [ V_8 ] ;
if ( V_14 -> V_19 &&
strcmp ( V_14 -> V_19 , V_4 -> V_19 ) &&
strcmp ( V_14 -> V_19 , F_10 ( V_4 -> V_19 ) ) &&
strcmp ( V_14 -> V_19 , F_1 ( V_4 -> V_19 ) ) )
continue;
if ( V_14 -> V_18 &&
strcmp ( V_14 -> V_18 , V_4 -> V_18 ) )
continue;
if ( V_14 -> V_17 &&
! strstr ( V_4 -> V_17 , V_14 -> V_17 ) )
continue;
if ( V_14 -> V_21 &&
V_4 -> V_33 < V_14 -> V_21 )
continue;
if ( V_14 -> V_22 &&
V_4 -> V_33 > V_14 -> V_22 )
continue;
V_27 ++ ;
V_26 = ( V_4 -> V_10 & V_23 ) | V_10 ;
if ( V_26 == V_4 -> V_10 )
continue;
V_4 -> V_10 = V_26 ;
F_6 ( L_4 ,
F_1 ( V_4 -> V_19 ) , V_4 -> V_33 ,
V_25 -> V_30 , V_4 -> V_18 ,
F_2 ( V_4 , V_28 ,
sizeof( V_28 ) ) ) ;
}
}
F_11 ( & V_29 ) ;
if ( ! V_27 && V_34 )
F_12 ( L_5 ) ;
return V_27 ;
}
static int F_13 ( char * V_5 , char * V_35 [] , int V_36 )
{
int V_37 = 0 ;
while ( * V_5 ) {
char * V_38 ;
V_5 = F_14 ( V_5 ) ;
if ( ! * V_5 )
break;
if ( * V_5 == '#' )
break;
if ( * V_5 == '"' || * V_5 == '\'' ) {
int V_39 = * V_5 ++ ;
for ( V_38 = V_5 ; * V_38 && * V_38 != V_39 ; V_38 ++ )
;
if ( ! * V_38 ) {
F_15 ( L_6 , V_5 ) ;
return - V_40 ;
}
} else {
for ( V_38 = V_5 ; * V_38 && ! isspace ( * V_38 ) ; V_38 ++ )
;
F_3 ( V_38 == V_5 ) ;
}
if ( V_37 == V_36 ) {
F_15 ( L_7 , V_36 ) ;
return - V_40 ;
}
if ( * V_38 )
* V_38 ++ = '\0' ;
V_35 [ V_37 ++ ] = V_5 ;
V_5 = V_38 ;
}
if ( V_34 ) {
int V_8 ;
F_12 ( L_8 ) ;
for ( V_8 = 0 ; V_8 < V_37 ; V_8 ++ )
F_16 ( L_9 , V_35 [ V_8 ] ) ;
F_16 ( L_10 ) ;
}
return V_37 ;
}
static inline int F_17 ( const char * V_41 , unsigned int * V_42 )
{
char * V_38 = NULL ;
F_3 ( V_41 == NULL ) ;
if ( * V_41 == '\0' ) {
* V_42 = 0 ;
return 0 ;
}
* V_42 = F_18 ( V_41 , & V_38 , 10 ) ;
if ( V_38 == NULL || V_38 == V_41 || * V_38 != '\0' ) {
F_15 ( L_11 , V_41 ) ;
return - V_40 ;
}
return 0 ;
}
static char * F_19 ( char * V_41 )
{
char * V_43 = V_41 ;
char * V_44 = V_41 ;
while ( * V_43 ) {
if ( * V_43 == '\\' ) {
if ( V_43 [ 1 ] == '\\' ) {
* V_44 ++ = '\\' ;
V_43 += 2 ;
continue;
} else if ( V_43 [ 1 ] == 't' ) {
* V_44 ++ = '\t' ;
V_43 += 2 ;
continue;
} else if ( V_43 [ 1 ] == 'n' ) {
* V_44 ++ = '\n' ;
V_43 += 2 ;
continue;
} else if ( F_20 ( V_43 [ 1 ] ) &&
F_20 ( V_43 [ 2 ] ) &&
F_20 ( V_43 [ 3 ] ) ) {
* V_44 ++ = ( ( ( V_43 [ 1 ] - '0' ) << 6 ) |
( ( V_43 [ 2 ] - '0' ) << 3 ) |
( V_43 [ 3 ] - '0' ) ) ;
V_43 += 4 ;
continue;
}
}
* V_44 ++ = * V_43 ++ ;
}
* V_44 = '\0' ;
return V_41 ;
}
static int F_21 ( const char * * V_45 , char * V_46 , char * V_47 )
{
int V_48 = 0 ;
if ( * V_45 ) {
V_48 = - V_40 ;
F_15 ( L_12 ,
V_47 , * V_45 , V_46 ) ;
}
* V_45 = V_46 ;
return V_48 ;
}
static int F_22 ( char * V_35 [] , int V_37 ,
struct V_13 * V_14 , const char * V_49 )
{
unsigned int V_8 ;
int V_48 ;
if ( V_37 % 2 != 0 ) {
F_15 ( L_13 ) ;
return - V_40 ;
}
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
if ( V_49 )
V_14 -> V_20 = V_49 ;
for ( V_8 = 0 ; V_8 < V_37 ; V_8 += 2 ) {
if ( ! strcmp ( V_35 [ V_8 ] , L_14 ) ) {
V_48 = F_21 ( & V_14 -> V_18 , V_35 [ V_8 + 1 ] , L_14 ) ;
} else if ( ! strcmp ( V_35 [ V_8 ] , L_15 ) ) {
V_48 = F_21 ( & V_14 -> V_19 , V_35 [ V_8 + 1 ] , L_15 ) ;
} else if ( ! strcmp ( V_35 [ V_8 ] , L_16 ) ) {
V_48 = F_21 ( & V_14 -> V_20 , V_35 [ V_8 + 1 ] , L_16 ) ;
} else if ( ! strcmp ( V_35 [ V_8 ] , L_17 ) ) {
V_48 = F_21 ( & V_14 -> V_17 , F_19 ( V_35 [ V_8 + 1 ] ) ,
L_17 ) ;
} else if ( ! strcmp ( V_35 [ V_8 ] , L_18 ) ) {
char * V_50 = V_35 [ V_8 + 1 ] ;
char * V_51 = strchr ( V_50 , '-' ) ;
if ( V_14 -> V_21 || V_14 -> V_22 ) {
F_15 ( L_19 ) ;
return - V_40 ;
}
if ( V_51 )
* V_51 ++ = '\0' ;
if ( F_17 ( V_50 , & V_14 -> V_21 ) < 0 ) {
F_15 ( L_20 ) ;
return - V_40 ;
}
if ( V_51 ) {
if ( F_17 ( V_51 , & V_14 -> V_22 )
< V_14 -> V_21 ) {
F_15 ( L_21 ,
V_14 -> V_22 ,
V_14 -> V_21 ) ;
return - V_40 ;
}
} else {
V_14 -> V_22 = V_14 -> V_21 ;
}
} else {
F_15 ( L_22 , V_35 [ V_8 ] ) ;
return - V_40 ;
}
if ( V_48 )
return V_48 ;
}
F_5 ( V_14 , L_23 ) ;
return 0 ;
}
static int F_23 ( const char * V_41 , unsigned int * V_52 ,
unsigned int * V_53 )
{
unsigned V_10 = 0 ;
int V_54 = '=' , V_8 ;
switch ( * V_41 ) {
case '+' :
case '-' :
case '=' :
V_54 = * V_41 ++ ;
break;
default:
F_15 ( L_24 , * V_41 , V_41 ) ;
return - V_40 ;
}
F_6 ( L_25 , V_54 ) ;
for (; * V_41 ; ++ V_41 ) {
for ( V_8 = F_4 ( V_9 ) - 1 ; V_8 >= 0 ; V_8 -- ) {
if ( * V_41 == V_9 [ V_8 ] . V_12 ) {
V_10 |= V_9 [ V_8 ] . V_11 ;
break;
}
}
if ( V_8 < 0 ) {
F_15 ( L_26 , * V_41 , V_41 ) ;
return - V_40 ;
}
}
F_6 ( L_27 , V_10 ) ;
switch ( V_54 ) {
case '=' :
* V_53 = 0 ;
* V_52 = V_10 ;
break;
case '+' :
* V_53 = ~ 0U ;
* V_52 = V_10 ;
break;
case '-' :
* V_53 = ~ V_10 ;
* V_52 = 0 ;
break;
}
F_6 ( L_28 , * V_52 , * V_53 ) ;
return 0 ;
}
static int F_24 ( char * V_55 , const char * V_49 )
{
unsigned int V_10 = 0 , V_23 = 0 ;
struct V_13 V_14 ;
#define F_25 9
int V_37 , V_27 ;
char * V_35 [ F_25 ] ;
V_37 = F_13 ( V_55 , V_35 , F_25 ) ;
if ( V_37 <= 0 ) {
F_15 ( L_29 ) ;
return - V_40 ;
}
if ( F_23 ( V_35 [ V_37 - 1 ] , & V_10 , & V_23 ) ) {
F_15 ( L_30 ) ;
return - V_40 ;
}
if ( F_22 ( V_35 , V_37 - 1 , & V_14 , V_49 ) ) {
F_15 ( L_31 ) ;
return - V_40 ;
}
V_27 = F_7 ( & V_14 , V_10 , V_23 ) ;
F_5 ( & V_14 , V_27 ? L_32 : L_33 ) ;
return V_27 ;
}
static int F_26 ( char * V_14 , const char * V_49 )
{
char * V_56 ;
int V_8 , V_57 = 0 , V_58 = 0 , V_48 , V_27 = 0 ;
for ( V_8 = 0 ; V_14 ; V_14 = V_56 ) {
V_56 = strpbrk ( V_14 , L_34 ) ;
if ( V_56 )
* V_56 ++ = '\0' ;
V_14 = F_14 ( V_14 ) ;
if ( ! V_14 || ! * V_14 || * V_14 == '#' )
continue;
F_6 ( L_35 , V_8 , V_14 ) ;
V_48 = F_24 ( V_14 , V_49 ) ;
if ( V_48 < 0 ) {
V_57 ++ ;
V_58 = V_48 ;
} else {
V_27 += V_48 ;
}
V_8 ++ ;
}
F_6 ( L_36 ,
V_8 , V_27 , V_57 ) ;
if ( V_58 )
return V_58 ;
return V_27 ;
}
static int F_27 ( int V_59 )
{
if ( V_60 - V_59 > 0 )
return V_60 - V_59 ;
return 0 ;
}
static char * F_28 ( const struct V_3 * V_61 , char * V_5 )
{
int V_62 ;
int V_63 = 0 ;
* V_5 = '\0' ;
if ( V_61 -> V_10 & V_64 ) {
if ( F_29 () )
V_63 += snprintf ( V_5 + V_63 , F_27 ( V_63 ) , L_37 ) ;
else
V_63 += snprintf ( V_5 + V_63 , F_27 ( V_63 ) , L_38 ,
F_30 ( V_65 ) ) ;
}
V_62 = V_63 ;
if ( V_61 -> V_10 & V_66 )
V_63 += snprintf ( V_5 + V_63 , F_27 ( V_63 ) , L_39 ,
V_61 -> V_49 ) ;
if ( V_61 -> V_10 & V_67 )
V_63 += snprintf ( V_5 + V_63 , F_27 ( V_63 ) , L_39 ,
V_61 -> V_18 ) ;
if ( V_61 -> V_10 & V_68 )
V_63 += snprintf ( V_5 + V_63 , F_27 ( V_63 ) , L_40 ,
V_61 -> V_33 ) ;
if ( V_63 - V_62 )
V_63 += snprintf ( V_5 + V_63 , F_27 ( V_63 ) , L_41 ) ;
if ( V_63 >= V_60 )
V_5 [ V_60 - 1 ] = '\0' ;
return V_5 ;
}
int F_31 ( struct V_3 * V_69 , const char * V_70 , ... )
{
T_2 args ;
int V_71 ;
struct V_72 V_73 ;
char V_5 [ V_60 ] ;
F_3 ( ! V_69 ) ;
F_3 ( ! V_70 ) ;
va_start ( args , V_70 ) ;
V_73 . V_70 = V_70 ;
V_73 . V_74 = & args ;
V_71 = F_32 ( V_75 L_42 ,
F_28 ( V_69 , V_5 ) , & V_73 ) ;
va_end ( args ) ;
return V_71 ;
}
int F_33 ( struct V_3 * V_69 ,
const struct V_76 * V_77 , const char * V_70 , ... )
{
struct V_72 V_73 ;
T_2 args ;
int V_71 ;
F_3 ( ! V_69 ) ;
F_3 ( ! V_70 ) ;
va_start ( args , V_70 ) ;
V_73 . V_70 = V_70 ;
V_73 . V_74 = & args ;
if ( ! V_77 ) {
V_71 = F_32 ( V_75 L_43 , & V_73 ) ;
} else {
char V_5 [ V_60 ] ;
V_71 = F_34 ( 7 , V_77 , L_44 ,
F_28 ( V_69 , V_5 ) ,
F_35 ( V_77 ) , F_36 ( V_77 ) ,
& V_73 ) ;
}
va_end ( args ) ;
return V_71 ;
}
int F_37 ( struct V_3 * V_69 ,
const struct V_78 * V_77 , const char * V_70 , ... )
{
struct V_72 V_73 ;
T_2 args ;
int V_71 ;
F_3 ( ! V_69 ) ;
F_3 ( ! V_70 ) ;
va_start ( args , V_70 ) ;
V_73 . V_70 = V_70 ;
V_73 . V_74 = & args ;
if ( V_77 && V_77 -> V_77 . V_79 ) {
char V_5 [ V_60 ] ;
V_71 = F_34 ( 7 , V_77 -> V_77 . V_79 ,
L_45 ,
F_28 ( V_69 , V_5 ) ,
F_35 ( V_77 -> V_77 . V_79 ) ,
F_36 ( V_77 -> V_77 . V_79 ) ,
F_38 ( V_77 ) , & V_73 ) ;
} else if ( V_77 ) {
V_71 = F_32 ( V_75 L_46 , F_38 ( V_77 ) , & V_73 ) ;
} else {
V_71 = F_32 ( V_75 L_47 , & V_73 ) ;
}
va_end ( args ) ;
return V_71 ;
}
static T_3 int F_39 ( char * V_41 )
{
if ( strlen ( V_41 ) >= V_80 ) {
F_40 ( L_48 ) ;
return 0 ;
}
F_41 ( V_81 , V_41 , V_80 ) ;
return 1 ;
}
static T_4 F_42 ( struct V_82 * V_82 , const char T_5 * V_83 ,
T_1 V_84 , T_6 * V_85 )
{
char * V_86 ;
int V_87 ;
if ( V_84 == 0 )
return 0 ;
if ( V_84 > V_88 - 1 ) {
F_40 ( L_49 , V_88 ) ;
return - V_89 ;
}
V_86 = F_43 ( V_84 + 1 , V_90 ) ;
if ( ! V_86 )
return - V_91 ;
if ( F_44 ( V_86 , V_83 , V_84 ) ) {
F_45 ( V_86 ) ;
return - V_92 ;
}
V_86 [ V_84 ] = '\0' ;
F_6 ( L_50 , ( int ) V_84 ) ;
V_87 = F_26 ( V_86 , NULL ) ;
F_45 ( V_86 ) ;
if ( V_87 < 0 )
return V_87 ;
* V_85 += V_84 ;
return V_84 ;
}
static struct V_3 * F_46 ( struct V_93 * V_94 )
{
if ( F_47 ( & V_95 ) ) {
V_94 -> V_96 = NULL ;
V_94 -> V_97 = 0 ;
return NULL ;
}
V_94 -> V_96 = F_48 ( V_95 . V_98 ,
struct V_24 , V_99 ) ;
V_94 -> V_97 = 0 ;
return & V_94 -> V_96 -> V_32 [ V_94 -> V_97 ] ;
}
static struct V_3 * F_49 ( struct V_93 * V_94 )
{
if ( V_94 -> V_96 == NULL )
return NULL ;
if ( ++ V_94 -> V_97 == V_94 -> V_96 -> V_31 ) {
V_94 -> V_97 = 0 ;
if ( F_50 ( & V_94 -> V_96 -> V_99 , & V_95 ) ) {
V_94 -> V_96 = NULL ;
return NULL ;
}
V_94 -> V_96 = F_48 ( V_94 -> V_96 -> V_99 . V_98 ,
struct V_24 , V_99 ) ;
}
return & V_94 -> V_96 -> V_32 [ V_94 -> V_97 ] ;
}
static void * F_51 ( struct V_100 * V_101 , T_6 * V_63 )
{
struct V_93 * V_94 = V_101 -> V_102 ;
struct V_3 * V_4 ;
int V_103 = * V_63 ;
F_6 ( L_51 , V_101 , ( unsigned long long ) * V_63 ) ;
F_8 ( & V_29 ) ;
if ( ! V_103 )
return V_104 ;
if ( V_103 < 0 )
return NULL ;
V_4 = F_46 ( V_94 ) ;
while ( V_4 != NULL && -- V_103 > 0 )
V_4 = F_49 ( V_94 ) ;
return V_4 ;
}
static void * F_52 ( struct V_100 * V_101 , void * V_7 , T_6 * V_63 )
{
struct V_93 * V_94 = V_101 -> V_102 ;
struct V_3 * V_4 ;
F_6 ( L_52 ,
V_101 , V_7 , ( unsigned long long ) * V_63 ) ;
if ( V_7 == V_104 )
V_4 = F_46 ( V_94 ) ;
else
V_4 = F_49 ( V_94 ) ;
++ * V_63 ;
return V_4 ;
}
static int F_53 ( struct V_100 * V_101 , void * V_7 )
{
struct V_93 * V_94 = V_101 -> V_102 ;
struct V_3 * V_4 = V_7 ;
char V_105 [ 10 ] ;
F_6 ( L_53 , V_101 , V_7 ) ;
if ( V_7 == V_104 ) {
F_54 ( V_101 ,
L_54 ) ;
return 0 ;
}
F_55 ( V_101 , L_55 ,
F_1 ( V_4 -> V_19 ) , V_4 -> V_33 ,
V_94 -> V_96 -> V_30 , V_4 -> V_18 ,
F_2 ( V_4 , V_105 , sizeof( V_105 ) ) ) ;
F_56 ( V_101 , V_4 -> V_17 , L_56 ) ;
F_54 ( V_101 , L_57 ) ;
return 0 ;
}
static void F_57 ( struct V_100 * V_101 , void * V_7 )
{
F_6 ( L_53 , V_101 , V_7 ) ;
F_11 ( & V_29 ) ;
}
static int F_58 ( struct V_106 * V_106 , struct V_82 * V_82 )
{
struct V_93 * V_94 ;
int V_107 ;
F_6 ( L_58 ) ;
V_94 = F_59 ( sizeof( * V_94 ) , V_90 ) ;
if ( V_94 == NULL )
return - V_91 ;
V_107 = F_60 ( V_82 , & V_108 ) ;
if ( V_107 ) {
F_45 ( V_94 ) ;
return V_107 ;
}
( (struct V_100 * ) V_82 -> V_109 ) -> V_102 = V_94 ;
return 0 ;
}
int F_61 ( struct V_3 * V_110 , unsigned int V_103 ,
const char * V_47 )
{
struct V_24 * V_25 ;
char * V_111 ;
V_25 = F_59 ( sizeof( * V_25 ) , V_90 ) ;
if ( V_25 == NULL )
return - V_91 ;
V_111 = F_62 ( V_47 , V_90 ) ;
if ( V_111 == NULL ) {
F_45 ( V_25 ) ;
return - V_91 ;
}
V_25 -> V_30 = V_111 ;
V_25 -> V_31 = V_103 ;
V_25 -> V_32 = V_110 ;
F_8 ( & V_29 ) ;
F_63 ( & V_25 -> V_99 , & V_95 ) ;
F_11 ( & V_29 ) ;
F_6 ( L_59 , V_103 , V_25 -> V_30 ) ;
return 0 ;
}
static int F_64 ( char * V_112 , char * V_42 ,
const char * V_49 , int V_113 )
{
char * V_114 ;
V_114 = strchr ( V_112 , '.' ) ;
if ( V_114 ) {
* V_114 = '\0' ;
V_49 = V_112 ;
V_112 = V_114 + 1 ;
}
if ( strcmp ( V_112 , L_60 ) )
return V_113 ;
F_26 ( ( V_42 ? V_42 : L_61 ) , V_49 ) ;
return 0 ;
}
static int F_65 ( char * V_112 , char * V_42 ,
const char * V_115 )
{
F_6 ( L_62 , V_112 , V_42 ) ;
return F_64 ( V_112 , V_42 , NULL , 0 ) ;
}
int F_66 ( char * V_112 , char * V_42 , const char * V_20 )
{
F_6 ( L_63 , V_20 , V_112 , V_42 ) ;
return F_64 ( V_112 , V_42 , V_20 , - V_116 ) ;
}
static void F_67 ( struct V_24 * V_25 )
{
F_68 ( & V_25 -> V_99 ) ;
F_45 ( V_25 -> V_30 ) ;
F_45 ( V_25 ) ;
}
int F_69 ( const char * V_30 )
{
struct V_24 * V_25 , * V_117 ;
int V_87 = - V_116 ;
F_6 ( L_64 , V_30 ) ;
F_8 ( & V_29 ) ;
F_70 (dt, nextdt, &ddebug_tables, link) {
if ( ! strcmp ( V_25 -> V_30 , V_30 ) ) {
F_67 ( V_25 ) ;
V_87 = 0 ;
}
}
F_11 ( & V_29 ) ;
return V_87 ;
}
static void F_71 ( void )
{
F_8 ( & V_29 ) ;
while ( ! F_47 ( & V_95 ) ) {
struct V_24 * V_25 = F_48 ( V_95 . V_98 ,
struct V_24 ,
V_99 ) ;
F_67 ( V_25 ) ;
}
F_11 ( & V_29 ) ;
}
static int T_3 F_72 ( void )
{
struct V_118 * V_119 , * V_82 ;
if ( ! V_120 )
return - V_121 ;
V_119 = F_73 ( L_65 , NULL ) ;
if ( ! V_119 )
return - V_91 ;
V_82 = F_74 ( L_66 , 0644 , V_119 , NULL ,
& V_122 ) ;
if ( ! V_82 ) {
F_75 ( V_119 ) ;
return - V_91 ;
}
return 0 ;
}
static int T_3 F_76 ( void )
{
struct V_3 * V_94 , * V_123 ;
const char * V_49 = NULL ;
char * V_124 ;
int V_87 = 0 ;
int V_103 = 0 , V_125 = 0 , V_126 = 0 ;
int V_127 = 0 ;
if ( V_128 == V_129 ) {
F_40 ( L_67 ) ;
return 1 ;
}
V_94 = V_128 ;
V_49 = V_94 -> V_49 ;
V_123 = V_94 ;
for (; V_94 < V_129 ; V_94 ++ ) {
V_125 ++ ;
V_127 += strlen ( V_94 -> V_49 ) + strlen ( V_94 -> V_18 )
+ strlen ( V_94 -> V_19 ) + strlen ( V_94 -> V_17 ) ;
if ( strcmp ( V_49 , V_94 -> V_49 ) ) {
V_126 ++ ;
V_87 = F_61 ( V_123 , V_103 , V_49 ) ;
if ( V_87 )
goto V_130;
V_103 = 0 ;
V_49 = V_94 -> V_49 ;
V_123 = V_94 ;
}
V_103 ++ ;
}
V_87 = F_61 ( V_123 , V_103 , V_49 ) ;
if ( V_87 )
goto V_130;
V_120 = 1 ;
F_6 ( L_68 ,
V_126 , V_125 , ( int ) ( V_126 * sizeof( struct V_24 ) ) ,
V_127 + ( int ) ( V_129 - V_128 ) ) ;
if ( V_81 [ 0 ] != '\0' ) {
F_40 ( L_69 ) ;
V_87 = F_26 ( V_81 , NULL ) ;
if ( V_87 < 0 )
F_40 ( L_70 ,
V_81 ) ;
else
F_12 ( L_71 , V_87 ) ;
}
V_124 = F_62 ( V_131 , V_90 ) ;
F_77 ( L_72 , V_124 , NULL ,
0 , 0 , 0 , & F_65 ) ;
F_45 ( V_124 ) ;
return 0 ;
V_130:
F_71 () ;
return 0 ;
}
