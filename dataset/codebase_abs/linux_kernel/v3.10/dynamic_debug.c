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
static int F_19 ( const char * * V_43 , char * V_44 , char * V_45 )
{
int V_46 = 0 ;
if ( * V_43 ) {
V_46 = - V_40 ;
F_15 ( L_12 ,
V_45 , * V_43 , V_44 ) ;
}
* V_43 = V_44 ;
return V_46 ;
}
static int F_20 ( char * V_35 [] , int V_37 ,
struct V_13 * V_14 , const char * V_47 )
{
unsigned int V_8 ;
int V_46 ;
if ( V_37 % 2 != 0 ) {
F_15 ( L_13 ) ;
return - V_40 ;
}
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
if ( V_47 )
V_14 -> V_20 = V_47 ;
for ( V_8 = 0 ; V_8 < V_37 ; V_8 += 2 ) {
if ( ! strcmp ( V_35 [ V_8 ] , L_14 ) ) {
V_46 = F_19 ( & V_14 -> V_18 , V_35 [ V_8 + 1 ] , L_14 ) ;
} else if ( ! strcmp ( V_35 [ V_8 ] , L_15 ) ) {
V_46 = F_19 ( & V_14 -> V_19 , V_35 [ V_8 + 1 ] , L_15 ) ;
} else if ( ! strcmp ( V_35 [ V_8 ] , L_16 ) ) {
V_46 = F_19 ( & V_14 -> V_20 , V_35 [ V_8 + 1 ] , L_16 ) ;
} else if ( ! strcmp ( V_35 [ V_8 ] , L_17 ) ) {
F_21 ( V_35 [ V_8 + 1 ] , V_48 |
V_49 |
V_50 ) ;
V_46 = F_19 ( & V_14 -> V_17 , V_35 [ V_8 + 1 ] , L_17 ) ;
} else if ( ! strcmp ( V_35 [ V_8 ] , L_18 ) ) {
char * V_51 = V_35 [ V_8 + 1 ] ;
char * V_52 = strchr ( V_51 , '-' ) ;
if ( V_14 -> V_21 || V_14 -> V_22 ) {
F_15 ( L_19 ) ;
return - V_40 ;
}
if ( V_52 )
* V_52 ++ = '\0' ;
if ( F_17 ( V_51 , & V_14 -> V_21 ) < 0 ) {
F_15 ( L_20 ) ;
return - V_40 ;
}
if ( V_52 ) {
if ( F_17 ( V_52 , & V_14 -> V_22 )
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
if ( V_46 )
return V_46 ;
}
F_5 ( V_14 , L_23 ) ;
return 0 ;
}
static int F_22 ( const char * V_41 , unsigned int * V_53 ,
unsigned int * V_54 )
{
unsigned V_10 = 0 ;
int V_55 = '=' , V_8 ;
switch ( * V_41 ) {
case '+' :
case '-' :
case '=' :
V_55 = * V_41 ++ ;
break;
default:
F_15 ( L_24 , * V_41 , V_41 ) ;
return - V_40 ;
}
F_6 ( L_25 , V_55 ) ;
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
switch ( V_55 ) {
case '=' :
* V_54 = 0 ;
* V_53 = V_10 ;
break;
case '+' :
* V_54 = ~ 0U ;
* V_53 = V_10 ;
break;
case '-' :
* V_54 = ~ V_10 ;
* V_53 = 0 ;
break;
}
F_6 ( L_28 , * V_53 , * V_54 ) ;
return 0 ;
}
static int F_23 ( char * V_56 , const char * V_47 )
{
unsigned int V_10 = 0 , V_23 = 0 ;
struct V_13 V_14 ;
#define F_24 9
int V_37 , V_27 ;
char * V_35 [ F_24 ] ;
V_37 = F_13 ( V_56 , V_35 , F_24 ) ;
if ( V_37 <= 0 ) {
F_15 ( L_29 ) ;
return - V_40 ;
}
if ( F_22 ( V_35 [ V_37 - 1 ] , & V_10 , & V_23 ) ) {
F_15 ( L_30 ) ;
return - V_40 ;
}
if ( F_20 ( V_35 , V_37 - 1 , & V_14 , V_47 ) ) {
F_15 ( L_31 ) ;
return - V_40 ;
}
V_27 = F_7 ( & V_14 , V_10 , V_23 ) ;
F_5 ( & V_14 , V_27 ? L_32 : L_33 ) ;
return V_27 ;
}
static int F_25 ( char * V_14 , const char * V_47 )
{
char * V_57 ;
int V_8 , V_58 = 0 , V_59 = 0 , V_46 , V_27 = 0 ;
for ( V_8 = 0 ; V_14 ; V_14 = V_57 ) {
V_57 = strpbrk ( V_14 , L_34 ) ;
if ( V_57 )
* V_57 ++ = '\0' ;
V_14 = F_14 ( V_14 ) ;
if ( ! V_14 || ! * V_14 || * V_14 == '#' )
continue;
F_6 ( L_35 , V_8 , V_14 ) ;
V_46 = F_23 ( V_14 , V_47 ) ;
if ( V_46 < 0 ) {
V_58 ++ ;
V_59 = V_46 ;
} else {
V_27 += V_46 ;
}
V_8 ++ ;
}
F_6 ( L_36 ,
V_8 , V_27 , V_58 ) ;
if ( V_59 )
return V_59 ;
return V_27 ;
}
static int F_26 ( int V_60 )
{
if ( V_61 - V_60 > 0 )
return V_61 - V_60 ;
return 0 ;
}
static char * F_27 ( const struct V_3 * V_62 , char * V_5 )
{
int V_63 ;
int V_64 = 0 ;
* V_5 = '\0' ;
if ( V_62 -> V_10 & V_65 ) {
if ( F_28 () )
V_64 += snprintf ( V_5 + V_64 , F_26 ( V_64 ) , L_37 ) ;
else
V_64 += snprintf ( V_5 + V_64 , F_26 ( V_64 ) , L_38 ,
F_29 ( V_66 ) ) ;
}
V_63 = V_64 ;
if ( V_62 -> V_10 & V_67 )
V_64 += snprintf ( V_5 + V_64 , F_26 ( V_64 ) , L_39 ,
V_62 -> V_47 ) ;
if ( V_62 -> V_10 & V_68 )
V_64 += snprintf ( V_5 + V_64 , F_26 ( V_64 ) , L_39 ,
V_62 -> V_18 ) ;
if ( V_62 -> V_10 & V_69 )
V_64 += snprintf ( V_5 + V_64 , F_26 ( V_64 ) , L_40 ,
V_62 -> V_33 ) ;
if ( V_64 - V_63 )
V_64 += snprintf ( V_5 + V_64 , F_26 ( V_64 ) , L_41 ) ;
if ( V_64 >= V_61 )
V_5 [ V_61 - 1 ] = '\0' ;
return V_5 ;
}
int F_30 ( struct V_3 * V_70 , const char * V_71 , ... )
{
T_2 args ;
int V_72 ;
struct V_73 V_74 ;
char V_5 [ V_61 ] ;
F_3 ( ! V_70 ) ;
F_3 ( ! V_71 ) ;
va_start ( args , V_71 ) ;
V_74 . V_71 = V_71 ;
V_74 . V_75 = & args ;
V_72 = F_31 ( V_76 L_42 ,
F_27 ( V_70 , V_5 ) , & V_74 ) ;
va_end ( args ) ;
return V_72 ;
}
int F_32 ( struct V_3 * V_70 ,
const struct V_77 * V_78 , const char * V_71 , ... )
{
struct V_73 V_74 ;
T_2 args ;
int V_72 ;
F_3 ( ! V_70 ) ;
F_3 ( ! V_71 ) ;
va_start ( args , V_71 ) ;
V_74 . V_71 = V_71 ;
V_74 . V_75 = & args ;
if ( ! V_78 ) {
V_72 = F_31 ( V_76 L_43 , & V_74 ) ;
} else {
char V_5 [ V_61 ] ;
V_72 = F_33 ( 7 , V_78 , L_44 ,
F_27 ( V_70 , V_5 ) ,
F_34 ( V_78 ) , F_35 ( V_78 ) ,
& V_74 ) ;
}
va_end ( args ) ;
return V_72 ;
}
int F_36 ( struct V_3 * V_70 ,
const struct V_79 * V_78 , const char * V_71 , ... )
{
struct V_73 V_74 ;
T_2 args ;
int V_72 ;
F_3 ( ! V_70 ) ;
F_3 ( ! V_71 ) ;
va_start ( args , V_71 ) ;
V_74 . V_71 = V_71 ;
V_74 . V_75 = & args ;
if ( V_78 && V_78 -> V_78 . V_80 ) {
char V_5 [ V_61 ] ;
V_72 = F_33 ( 7 , V_78 -> V_78 . V_80 ,
L_45 ,
F_27 ( V_70 , V_5 ) ,
F_34 ( V_78 -> V_78 . V_80 ) ,
F_35 ( V_78 -> V_78 . V_80 ) ,
F_37 ( V_78 ) , & V_74 ) ;
} else if ( V_78 ) {
V_72 = F_31 ( V_76 L_46 , F_37 ( V_78 ) , & V_74 ) ;
} else {
V_72 = F_31 ( V_76 L_47 , & V_74 ) ;
}
va_end ( args ) ;
return V_72 ;
}
static T_3 int F_38 ( char * V_41 )
{
if ( strlen ( V_41 ) >= V_81 ) {
F_39 ( L_48 ) ;
return 0 ;
}
F_40 ( V_82 , V_41 , V_81 ) ;
return 1 ;
}
static T_4 F_41 ( struct V_83 * V_83 , const char T_5 * V_84 ,
T_1 V_85 , T_6 * V_86 )
{
char * V_87 ;
int V_88 ;
if ( V_85 == 0 )
return 0 ;
if ( V_85 > V_89 - 1 ) {
F_39 ( L_49 , V_89 ) ;
return - V_90 ;
}
V_87 = F_42 ( V_85 + 1 , V_91 ) ;
if ( ! V_87 )
return - V_92 ;
if ( F_43 ( V_87 , V_84 , V_85 ) ) {
F_44 ( V_87 ) ;
return - V_93 ;
}
V_87 [ V_85 ] = '\0' ;
F_6 ( L_50 , ( int ) V_85 ) ;
V_88 = F_25 ( V_87 , NULL ) ;
F_44 ( V_87 ) ;
if ( V_88 < 0 )
return V_88 ;
* V_86 += V_85 ;
return V_85 ;
}
static struct V_3 * F_45 ( struct V_94 * V_95 )
{
if ( F_46 ( & V_96 ) ) {
V_95 -> V_97 = NULL ;
V_95 -> V_98 = 0 ;
return NULL ;
}
V_95 -> V_97 = F_47 ( V_96 . V_99 ,
struct V_24 , V_100 ) ;
V_95 -> V_98 = 0 ;
return & V_95 -> V_97 -> V_32 [ V_95 -> V_98 ] ;
}
static struct V_3 * F_48 ( struct V_94 * V_95 )
{
if ( V_95 -> V_97 == NULL )
return NULL ;
if ( ++ V_95 -> V_98 == V_95 -> V_97 -> V_31 ) {
V_95 -> V_98 = 0 ;
if ( F_49 ( & V_95 -> V_97 -> V_100 , & V_96 ) ) {
V_95 -> V_97 = NULL ;
return NULL ;
}
V_95 -> V_97 = F_47 ( V_95 -> V_97 -> V_100 . V_99 ,
struct V_24 , V_100 ) ;
}
return & V_95 -> V_97 -> V_32 [ V_95 -> V_98 ] ;
}
static void * F_50 ( struct V_101 * V_102 , T_6 * V_64 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
struct V_3 * V_4 ;
int V_104 = * V_64 ;
F_6 ( L_51 , V_102 , ( unsigned long long ) * V_64 ) ;
F_8 ( & V_29 ) ;
if ( ! V_104 )
return V_105 ;
if ( V_104 < 0 )
return NULL ;
V_4 = F_45 ( V_95 ) ;
while ( V_4 != NULL && -- V_104 > 0 )
V_4 = F_48 ( V_95 ) ;
return V_4 ;
}
static void * F_51 ( struct V_101 * V_102 , void * V_7 , T_6 * V_64 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
struct V_3 * V_4 ;
F_6 ( L_52 ,
V_102 , V_7 , ( unsigned long long ) * V_64 ) ;
if ( V_7 == V_105 )
V_4 = F_45 ( V_95 ) ;
else
V_4 = F_48 ( V_95 ) ;
++ * V_64 ;
return V_4 ;
}
static int F_52 ( struct V_101 * V_102 , void * V_7 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
struct V_3 * V_4 = V_7 ;
char V_106 [ 10 ] ;
F_6 ( L_53 , V_102 , V_7 ) ;
if ( V_7 == V_105 ) {
F_53 ( V_102 ,
L_54 ) ;
return 0 ;
}
F_54 ( V_102 , L_55 ,
F_1 ( V_4 -> V_19 ) , V_4 -> V_33 ,
V_95 -> V_97 -> V_30 , V_4 -> V_18 ,
F_2 ( V_4 , V_106 , sizeof( V_106 ) ) ) ;
F_55 ( V_102 , V_4 -> V_17 , L_56 ) ;
F_53 ( V_102 , L_57 ) ;
return 0 ;
}
static void F_56 ( struct V_101 * V_102 , void * V_7 )
{
F_6 ( L_53 , V_102 , V_7 ) ;
F_11 ( & V_29 ) ;
}
static int F_57 ( struct V_107 * V_107 , struct V_83 * V_83 )
{
struct V_94 * V_95 ;
int V_108 ;
F_6 ( L_58 ) ;
V_95 = F_58 ( sizeof( * V_95 ) , V_91 ) ;
if ( V_95 == NULL )
return - V_92 ;
V_108 = F_59 ( V_83 , & V_109 ) ;
if ( V_108 ) {
F_44 ( V_95 ) ;
return V_108 ;
}
( (struct V_101 * ) V_83 -> V_110 ) -> V_103 = V_95 ;
return 0 ;
}
int F_60 ( struct V_3 * V_111 , unsigned int V_104 ,
const char * V_45 )
{
struct V_24 * V_25 ;
char * V_112 ;
V_25 = F_58 ( sizeof( * V_25 ) , V_91 ) ;
if ( V_25 == NULL )
return - V_92 ;
V_112 = F_61 ( V_45 , V_91 ) ;
if ( V_112 == NULL ) {
F_44 ( V_25 ) ;
return - V_92 ;
}
V_25 -> V_30 = V_112 ;
V_25 -> V_31 = V_104 ;
V_25 -> V_32 = V_111 ;
F_8 ( & V_29 ) ;
F_62 ( & V_25 -> V_100 , & V_96 ) ;
F_11 ( & V_29 ) ;
F_6 ( L_59 , V_104 , V_25 -> V_30 ) ;
return 0 ;
}
static int F_63 ( char * V_113 , char * V_42 ,
const char * V_47 , int V_114 )
{
char * V_115 ;
V_115 = strchr ( V_113 , '.' ) ;
if ( V_115 ) {
* V_115 = '\0' ;
V_47 = V_113 ;
V_113 = V_115 + 1 ;
}
if ( strcmp ( V_113 , L_60 ) )
return V_114 ;
F_25 ( ( V_42 ? V_42 : L_61 ) , V_47 ) ;
return 0 ;
}
static int F_64 ( char * V_113 , char * V_42 ,
const char * V_116 )
{
F_6 ( L_62 , V_113 , V_42 ) ;
return F_63 ( V_113 , V_42 , NULL , 0 ) ;
}
int F_65 ( char * V_113 , char * V_42 , const char * V_20 )
{
F_6 ( L_63 , V_20 , V_113 , V_42 ) ;
return F_63 ( V_113 , V_42 , V_20 , - V_117 ) ;
}
static void F_66 ( struct V_24 * V_25 )
{
F_67 ( & V_25 -> V_100 ) ;
F_44 ( V_25 -> V_30 ) ;
F_44 ( V_25 ) ;
}
int F_68 ( const char * V_30 )
{
struct V_24 * V_25 , * V_118 ;
int V_88 = - V_117 ;
F_6 ( L_64 , V_30 ) ;
F_8 ( & V_29 ) ;
F_69 (dt, nextdt, &ddebug_tables, link) {
if ( ! strcmp ( V_25 -> V_30 , V_30 ) ) {
F_66 ( V_25 ) ;
V_88 = 0 ;
}
}
F_11 ( & V_29 ) ;
return V_88 ;
}
static void F_70 ( void )
{
F_8 ( & V_29 ) ;
while ( ! F_46 ( & V_96 ) ) {
struct V_24 * V_25 = F_47 ( V_96 . V_99 ,
struct V_24 ,
V_100 ) ;
F_66 ( V_25 ) ;
}
F_11 ( & V_29 ) ;
}
static int T_3 F_71 ( void )
{
struct V_119 * V_120 , * V_83 ;
if ( ! V_121 )
return - V_122 ;
V_120 = F_72 ( L_65 , NULL ) ;
if ( ! V_120 )
return - V_92 ;
V_83 = F_73 ( L_66 , 0644 , V_120 , NULL ,
& V_123 ) ;
if ( ! V_83 ) {
F_74 ( V_120 ) ;
return - V_92 ;
}
return 0 ;
}
static int T_3 F_75 ( void )
{
struct V_3 * V_95 , * V_124 ;
const char * V_47 = NULL ;
char * V_125 ;
int V_88 = 0 ;
int V_104 = 0 , V_126 = 0 , V_127 = 0 ;
int V_128 = 0 ;
if ( V_129 == V_130 ) {
F_39 ( L_67 ) ;
return 1 ;
}
V_95 = V_129 ;
V_47 = V_95 -> V_47 ;
V_124 = V_95 ;
for (; V_95 < V_130 ; V_95 ++ ) {
V_126 ++ ;
V_128 += strlen ( V_95 -> V_47 ) + strlen ( V_95 -> V_18 )
+ strlen ( V_95 -> V_19 ) + strlen ( V_95 -> V_17 ) ;
if ( strcmp ( V_47 , V_95 -> V_47 ) ) {
V_127 ++ ;
V_88 = F_60 ( V_124 , V_104 , V_47 ) ;
if ( V_88 )
goto V_131;
V_104 = 0 ;
V_47 = V_95 -> V_47 ;
V_124 = V_95 ;
}
V_104 ++ ;
}
V_88 = F_60 ( V_124 , V_104 , V_47 ) ;
if ( V_88 )
goto V_131;
V_121 = 1 ;
F_6 ( L_68 ,
V_127 , V_126 , ( int ) ( V_127 * sizeof( struct V_24 ) ) ,
V_128 + ( int ) ( V_130 - V_129 ) ) ;
if ( V_82 [ 0 ] != '\0' ) {
F_39 ( L_69 ) ;
V_88 = F_25 ( V_82 , NULL ) ;
if ( V_88 < 0 )
F_39 ( L_70 ,
V_82 ) ;
else
F_12 ( L_71 , V_88 ) ;
}
V_125 = F_61 ( V_132 , V_91 ) ;
F_76 ( L_72 , V_125 , NULL ,
0 , 0 , 0 , & F_64 ) ;
F_44 ( V_125 ) ;
return 0 ;
V_131:
F_70 () ;
return 0 ;
}
