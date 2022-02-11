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
static int F_5 ( const struct V_13 * V_14 ,
unsigned int V_10 , unsigned int V_15 )
{
int V_8 ;
struct V_16 * V_17 ;
unsigned int V_18 ;
unsigned int V_19 = 0 ;
char V_20 [ 10 ] ;
F_6 ( & V_21 ) ;
F_7 (dt, &ddebug_tables, link) {
if ( V_14 -> V_22 && strcmp ( V_14 -> V_22 , V_17 -> V_23 ) )
continue;
for ( V_8 = 0 ; V_8 < V_17 -> V_24 ; V_8 ++ ) {
struct V_3 * V_4 = & V_17 -> V_25 [ V_8 ] ;
if ( V_14 -> V_26 &&
strcmp ( V_14 -> V_26 , V_4 -> V_26 ) &&
strcmp ( V_14 -> V_26 , F_8 ( V_4 -> V_26 ) ) &&
strcmp ( V_14 -> V_26 , F_1 ( V_4 -> V_26 ) ) )
continue;
if ( V_14 -> V_27 &&
strcmp ( V_14 -> V_27 , V_4 -> V_27 ) )
continue;
if ( V_14 -> V_28 &&
! strstr ( V_4 -> V_28 , V_14 -> V_28 ) )
continue;
if ( V_14 -> V_29 &&
V_4 -> V_30 < V_14 -> V_29 )
continue;
if ( V_14 -> V_31 &&
V_4 -> V_30 > V_14 -> V_31 )
continue;
V_19 ++ ;
V_18 = ( V_4 -> V_10 & V_15 ) | V_10 ;
if ( V_18 == V_4 -> V_10 )
continue;
V_4 -> V_10 = V_18 ;
F_9 ( L_2 ,
F_1 ( V_4 -> V_26 ) , V_4 -> V_30 ,
V_17 -> V_23 , V_4 -> V_27 ,
F_2 ( V_4 , V_20 ,
sizeof( V_20 ) ) ) ;
}
}
F_10 ( & V_21 ) ;
if ( ! V_19 && V_32 )
F_11 ( L_3 ) ;
return V_19 ;
}
static int F_12 ( char * V_5 , char * V_33 [] , int V_34 )
{
int V_35 = 0 ;
while ( * V_5 ) {
char * V_36 ;
V_5 = F_13 ( V_5 ) ;
if ( ! * V_5 )
break;
if ( * V_5 == '#' )
break;
if ( * V_5 == '"' || * V_5 == '\'' ) {
int V_37 = * V_5 ++ ;
for ( V_36 = V_5 ; * V_36 && * V_36 != V_37 ; V_36 ++ )
;
if ( ! * V_36 )
return - V_38 ;
} else {
for ( V_36 = V_5 ; * V_36 && ! isspace ( * V_36 ) ; V_36 ++ )
;
F_3 ( V_36 == V_5 ) ;
}
if ( V_35 == V_34 )
return - V_38 ;
if ( * V_36 )
* V_36 ++ = '\0' ;
V_33 [ V_35 ++ ] = V_5 ;
V_5 = V_36 ;
}
if ( V_32 ) {
int V_8 ;
F_11 ( L_4 ) ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ )
F_14 ( L_5 , V_33 [ V_8 ] ) ;
F_14 ( L_6 ) ;
}
return V_35 ;
}
static inline int F_15 ( const char * V_39 , unsigned int * V_40 )
{
char * V_36 = NULL ;
F_3 ( V_39 == NULL ) ;
if ( * V_39 == '\0' ) {
* V_40 = 0 ;
return 0 ;
}
* V_40 = F_16 ( V_39 , & V_36 , 10 ) ;
return V_36 == NULL || V_36 == V_39 || * V_36 != '\0' ? - V_38 : 0 ;
}
static char * F_17 ( char * V_39 )
{
char * V_41 = V_39 ;
char * V_42 = V_39 ;
while ( * V_41 ) {
if ( * V_41 == '\\' ) {
if ( V_41 [ 1 ] == '\\' ) {
* V_42 ++ = '\\' ;
V_41 += 2 ;
continue;
} else if ( V_41 [ 1 ] == 't' ) {
* V_42 ++ = '\t' ;
V_41 += 2 ;
continue;
} else if ( V_41 [ 1 ] == 'n' ) {
* V_42 ++ = '\n' ;
V_41 += 2 ;
continue;
} else if ( F_18 ( V_41 [ 1 ] ) &&
F_18 ( V_41 [ 2 ] ) &&
F_18 ( V_41 [ 3 ] ) ) {
* V_42 ++ = ( ( V_41 [ 1 ] - '0' ) << 6 ) |
( ( V_41 [ 2 ] - '0' ) << 3 ) |
( V_41 [ 3 ] - '0' ) ;
V_41 += 4 ;
continue;
}
}
* V_42 ++ = * V_41 ++ ;
}
* V_42 = '\0' ;
return V_39 ;
}
static int F_19 ( const char * * V_43 , char * V_44 , char * V_45 )
{
int V_46 = 0 ;
if ( * V_43 ) {
V_46 = - V_38 ;
F_20 ( L_7 ,
V_45 , * V_43 , V_44 ) ;
}
* V_43 = V_44 ;
return V_46 ;
}
static int F_21 ( char * V_33 [] , int V_35 ,
struct V_13 * V_14 , const char * V_47 )
{
unsigned int V_8 ;
int V_46 ;
if ( V_35 % 2 != 0 )
return - V_38 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
if ( V_47 )
V_14 -> V_22 = V_47 ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 += 2 ) {
if ( ! strcmp ( V_33 [ V_8 ] , L_8 ) )
V_46 = F_19 ( & V_14 -> V_27 , V_33 [ V_8 + 1 ] , L_8 ) ;
else if ( ! strcmp ( V_33 [ V_8 ] , L_9 ) )
V_46 = F_19 ( & V_14 -> V_26 , V_33 [ V_8 + 1 ] , L_9 ) ;
else if ( ! strcmp ( V_33 [ V_8 ] , L_10 ) )
V_46 = F_19 ( & V_14 -> V_22 , V_33 [ V_8 + 1 ] , L_10 ) ;
else if ( ! strcmp ( V_33 [ V_8 ] , L_11 ) )
V_46 = F_19 ( & V_14 -> V_28 , F_17 ( V_33 [ V_8 + 1 ] ) ,
L_11 ) ;
else if ( ! strcmp ( V_33 [ V_8 ] , L_12 ) ) {
char * V_48 = V_33 [ V_8 + 1 ] ;
char * V_49 = strchr ( V_48 , '-' ) ;
if ( V_14 -> V_29 || V_14 -> V_31 ) {
F_20 ( L_13 ) ;
return - V_38 ;
}
if ( V_49 )
* V_49 ++ = '\0' ;
if ( F_15 ( V_48 , & V_14 -> V_29 ) < 0 )
return - V_38 ;
if ( V_49 ) {
if ( F_15 ( V_49 , & V_14 -> V_31 )
< V_14 -> V_29 ) {
F_20 ( L_14 ) ;
return - V_38 ;
}
} else {
V_14 -> V_31 = V_14 -> V_29 ;
}
} else {
F_20 ( L_15 , V_33 [ V_8 ] ) ;
return - V_38 ;
}
if ( V_46 )
return V_46 ;
}
F_22 ( V_14 , L_16 ) ;
return 0 ;
}
static int F_23 ( const char * V_39 , unsigned int * V_50 ,
unsigned int * V_51 )
{
unsigned V_10 = 0 ;
int V_52 = '=' , V_8 ;
switch ( * V_39 ) {
case '+' :
case '-' :
case '=' :
V_52 = * V_39 ++ ;
break;
default:
return - V_38 ;
}
F_9 ( L_17 , V_52 ) ;
for ( ; * V_39 ; ++ V_39 ) {
for ( V_8 = F_4 ( V_9 ) - 1 ; V_8 >= 0 ; V_8 -- ) {
if ( * V_39 == V_9 [ V_8 ] . V_12 ) {
V_10 |= V_9 [ V_8 ] . V_11 ;
break;
}
}
if ( V_8 < 0 )
return - V_38 ;
}
F_9 ( L_18 , V_10 ) ;
switch ( V_52 ) {
case '=' :
* V_51 = 0 ;
* V_50 = V_10 ;
break;
case '+' :
* V_51 = ~ 0U ;
* V_50 = V_10 ;
break;
case '-' :
* V_51 = ~ V_10 ;
* V_50 = 0 ;
break;
}
F_9 ( L_19 , * V_50 , * V_51 ) ;
return 0 ;
}
static int F_24 ( char * V_53 , const char * V_47 )
{
unsigned int V_10 = 0 , V_15 = 0 ;
struct V_13 V_14 ;
#define F_25 9
int V_35 , V_19 ;
char * V_33 [ F_25 ] ;
V_35 = F_12 ( V_53 , V_33 , F_25 ) ;
if ( V_35 <= 0 )
return - V_38 ;
if ( F_21 ( V_33 , V_35 - 1 , & V_14 , V_47 ) )
return - V_38 ;
if ( F_23 ( V_33 [ V_35 - 1 ] , & V_10 , & V_15 ) )
return - V_38 ;
V_19 = F_5 ( & V_14 , V_10 , V_15 ) ;
F_22 ( ( & V_14 ) , ( V_19 ) ? L_20 : L_21 ) ;
return V_19 ;
}
static int F_26 ( char * V_14 , const char * V_47 )
{
char * V_54 ;
int V_8 , V_55 = 0 , V_56 = 0 , V_46 , V_19 = 0 ;
for ( V_8 = 0 ; V_14 ; V_14 = V_54 ) {
V_54 = strpbrk ( V_14 , L_22 ) ;
if ( V_54 )
* V_54 ++ = '\0' ;
V_14 = F_13 ( V_14 ) ;
if ( ! V_14 || ! * V_14 || * V_14 == '#' )
continue;
F_9 ( L_23 , V_8 , V_14 ) ;
V_46 = F_24 ( V_14 , V_47 ) ;
if ( V_46 < 0 ) {
V_55 ++ ;
V_56 = V_46 ;
} else
V_19 += V_46 ;
V_8 ++ ;
}
F_9 ( L_24 ,
V_8 , V_19 , V_55 ) ;
if ( V_56 )
return V_56 ;
return V_19 ;
}
static int F_27 ( int V_57 )
{
if ( V_58 - V_57 > 0 )
return V_58 - V_57 ;
return 0 ;
}
static char * F_28 ( const struct V_3 * V_59 , char * V_5 )
{
int V_60 ;
int V_61 = 0 ;
* V_5 = '\0' ;
if ( V_59 -> V_10 & V_62 ) {
if ( F_29 () )
V_61 += snprintf ( V_5 + V_61 , F_27 ( V_61 ) , L_25 ) ;
else
V_61 += snprintf ( V_5 + V_61 , F_27 ( V_61 ) , L_26 ,
F_30 ( V_63 ) ) ;
}
V_60 = V_61 ;
if ( V_59 -> V_10 & V_64 )
V_61 += snprintf ( V_5 + V_61 , F_27 ( V_61 ) , L_27 ,
V_59 -> V_47 ) ;
if ( V_59 -> V_10 & V_65 )
V_61 += snprintf ( V_5 + V_61 , F_27 ( V_61 ) , L_27 ,
V_59 -> V_27 ) ;
if ( V_59 -> V_10 & V_66 )
V_61 += snprintf ( V_5 + V_61 , F_27 ( V_61 ) , L_28 ,
V_59 -> V_30 ) ;
if ( V_61 - V_60 )
V_61 += snprintf ( V_5 + V_61 , F_27 ( V_61 ) , L_29 ) ;
if ( V_61 >= V_58 )
V_5 [ V_58 - 1 ] = '\0' ;
return V_5 ;
}
int F_31 ( struct V_3 * V_67 , const char * V_68 , ... )
{
T_2 args ;
int V_69 ;
struct V_70 V_71 ;
char V_5 [ V_58 ] ;
F_3 ( ! V_67 ) ;
F_3 ( ! V_68 ) ;
va_start ( args , V_68 ) ;
V_71 . V_68 = V_68 ;
V_71 . V_72 = & args ;
V_69 = F_32 ( V_73 L_30 ,
F_28 ( V_67 , V_5 ) , & V_71 ) ;
va_end ( args ) ;
return V_69 ;
}
int F_33 ( struct V_3 * V_67 ,
const struct V_74 * V_75 , const char * V_68 , ... )
{
struct V_70 V_71 ;
T_2 args ;
int V_69 ;
F_3 ( ! V_67 ) ;
F_3 ( ! V_68 ) ;
va_start ( args , V_68 ) ;
V_71 . V_68 = V_68 ;
V_71 . V_72 = & args ;
if ( ! V_75 ) {
V_69 = F_32 ( V_73 L_31 , & V_71 ) ;
} else {
char V_5 [ V_58 ] ;
V_69 = F_34 ( 7 , V_75 , L_32 ,
F_28 ( V_67 , V_5 ) ,
F_35 ( V_75 ) , F_36 ( V_75 ) ,
& V_71 ) ;
}
va_end ( args ) ;
return V_69 ;
}
int F_37 ( struct V_3 * V_67 ,
const struct V_76 * V_75 , const char * V_68 , ... )
{
struct V_70 V_71 ;
T_2 args ;
int V_69 ;
F_3 ( ! V_67 ) ;
F_3 ( ! V_68 ) ;
va_start ( args , V_68 ) ;
V_71 . V_68 = V_68 ;
V_71 . V_72 = & args ;
if ( V_75 && V_75 -> V_75 . V_77 ) {
char V_5 [ V_58 ] ;
V_69 = F_34 ( 7 , V_75 -> V_75 . V_77 ,
L_33 ,
F_28 ( V_67 , V_5 ) ,
F_35 ( V_75 -> V_75 . V_77 ) ,
F_36 ( V_75 -> V_75 . V_77 ) ,
F_38 ( V_75 ) , & V_71 ) ;
} else if ( V_75 ) {
V_69 = F_32 ( V_73 L_34 , F_38 ( V_75 ) , & V_71 ) ;
} else {
V_69 = F_32 ( V_73 L_35 , & V_71 ) ;
}
va_end ( args ) ;
return V_69 ;
}
static T_3 int F_39 ( char * V_39 )
{
if ( strlen ( V_39 ) >= V_78 ) {
F_40 ( L_36 ) ;
return 0 ;
}
F_41 ( V_79 , V_39 , V_78 ) ;
return 1 ;
}
static T_4 F_42 ( struct V_80 * V_80 , const char T_5 * V_81 ,
T_1 V_82 , T_6 * V_83 )
{
char * V_84 ;
int V_85 ;
if ( V_82 == 0 )
return 0 ;
if ( V_82 > V_86 - 1 ) {
F_40 ( L_37 , V_86 ) ;
return - V_87 ;
}
V_84 = F_43 ( V_82 + 1 , V_88 ) ;
if ( ! V_84 )
return - V_89 ;
if ( F_44 ( V_84 , V_81 , V_82 ) ) {
F_45 ( V_84 ) ;
return - V_90 ;
}
V_84 [ V_82 ] = '\0' ;
F_9 ( L_38 , ( int ) V_82 ) ;
V_85 = F_26 ( V_84 , NULL ) ;
F_45 ( V_84 ) ;
if ( V_85 < 0 )
return V_85 ;
* V_83 += V_82 ;
return V_82 ;
}
static struct V_3 * F_46 ( struct V_91 * V_92 )
{
if ( F_47 ( & V_93 ) ) {
V_92 -> V_94 = NULL ;
V_92 -> V_95 = 0 ;
return NULL ;
}
V_92 -> V_94 = F_48 ( V_93 . V_96 ,
struct V_16 , V_97 ) ;
V_92 -> V_95 = 0 ;
return & V_92 -> V_94 -> V_25 [ V_92 -> V_95 ] ;
}
static struct V_3 * F_49 ( struct V_91 * V_92 )
{
if ( V_92 -> V_94 == NULL )
return NULL ;
if ( ++ V_92 -> V_95 == V_92 -> V_94 -> V_24 ) {
V_92 -> V_95 = 0 ;
if ( F_50 ( & V_92 -> V_94 -> V_97 , & V_93 ) ) {
V_92 -> V_94 = NULL ;
return NULL ;
}
V_92 -> V_94 = F_48 ( V_92 -> V_94 -> V_97 . V_96 ,
struct V_16 , V_97 ) ;
}
return & V_92 -> V_94 -> V_25 [ V_92 -> V_95 ] ;
}
static void * F_51 ( struct V_98 * V_99 , T_6 * V_61 )
{
struct V_91 * V_92 = V_99 -> V_100 ;
struct V_3 * V_4 ;
int V_101 = * V_61 ;
F_9 ( L_39 , V_99 , ( unsigned long long ) * V_61 ) ;
F_6 ( & V_21 ) ;
if ( ! V_101 )
return V_102 ;
if ( V_101 < 0 )
return NULL ;
V_4 = F_46 ( V_92 ) ;
while ( V_4 != NULL && -- V_101 > 0 )
V_4 = F_49 ( V_92 ) ;
return V_4 ;
}
static void * F_52 ( struct V_98 * V_99 , void * V_7 , T_6 * V_61 )
{
struct V_91 * V_92 = V_99 -> V_100 ;
struct V_3 * V_4 ;
F_9 ( L_40 ,
V_99 , V_7 , ( unsigned long long ) * V_61 ) ;
if ( V_7 == V_102 )
V_4 = F_46 ( V_92 ) ;
else
V_4 = F_49 ( V_92 ) ;
++ * V_61 ;
return V_4 ;
}
static int F_53 ( struct V_98 * V_99 , void * V_7 )
{
struct V_91 * V_92 = V_99 -> V_100 ;
struct V_3 * V_4 = V_7 ;
char V_103 [ 10 ] ;
F_9 ( L_41 , V_99 , V_7 ) ;
if ( V_7 == V_102 ) {
F_54 ( V_99 ,
L_42 ) ;
return 0 ;
}
F_55 ( V_99 , L_43 ,
F_1 ( V_4 -> V_26 ) , V_4 -> V_30 ,
V_92 -> V_94 -> V_23 , V_4 -> V_27 ,
F_2 ( V_4 , V_103 , sizeof( V_103 ) ) ) ;
F_56 ( V_99 , V_4 -> V_28 , L_44 ) ;
F_54 ( V_99 , L_45 ) ;
return 0 ;
}
static void F_57 ( struct V_98 * V_99 , void * V_7 )
{
F_9 ( L_41 , V_99 , V_7 ) ;
F_10 ( & V_21 ) ;
}
static int F_58 ( struct V_104 * V_104 , struct V_80 * V_80 )
{
struct V_91 * V_92 ;
int V_105 ;
F_9 ( L_46 ) ;
V_92 = F_59 ( sizeof( * V_92 ) , V_88 ) ;
if ( V_92 == NULL )
return - V_89 ;
V_105 = F_60 ( V_80 , & V_106 ) ;
if ( V_105 ) {
F_45 ( V_92 ) ;
return V_105 ;
}
( (struct V_98 * ) V_80 -> V_107 ) -> V_100 = V_92 ;
return 0 ;
}
int F_61 ( struct V_3 * V_108 , unsigned int V_101 ,
const char * V_45 )
{
struct V_16 * V_17 ;
char * V_109 ;
V_17 = F_59 ( sizeof( * V_17 ) , V_88 ) ;
if ( V_17 == NULL )
return - V_89 ;
V_109 = F_62 ( V_45 , V_88 ) ;
if ( V_109 == NULL ) {
F_45 ( V_17 ) ;
return - V_89 ;
}
V_17 -> V_23 = V_109 ;
V_17 -> V_24 = V_101 ;
V_17 -> V_25 = V_108 ;
F_6 ( & V_21 ) ;
F_63 ( & V_17 -> V_97 , & V_93 ) ;
F_10 ( & V_21 ) ;
F_9 ( L_47 , V_101 , V_17 -> V_23 ) ;
return 0 ;
}
static int F_64 ( char * V_110 , char * V_40 ,
const char * V_47 , int V_111 )
{
char * V_112 ;
V_112 = strchr ( V_110 , '.' ) ;
if ( V_112 ) {
* V_112 = '\0' ;
V_47 = V_110 ;
V_110 = V_112 + 1 ;
}
if ( strcmp ( V_110 , L_48 ) )
return V_111 ;
F_26 ( ( V_40 ? V_40 : L_49 ) , V_47 ) ;
return 0 ;
}
static int F_65 ( char * V_110 , char * V_40 ,
const char * V_113 )
{
F_9 ( L_50 , V_110 , V_40 ) ;
return F_64 ( V_110 , V_40 , NULL , 0 ) ;
}
int F_66 ( char * V_110 , char * V_40 , const char * V_22 )
{
F_9 ( L_51 , V_22 , V_110 , V_40 ) ;
return F_64 ( V_110 , V_40 , V_22 , - V_114 ) ;
}
static void F_67 ( struct V_16 * V_17 )
{
F_68 ( & V_17 -> V_97 ) ;
F_45 ( V_17 -> V_23 ) ;
F_45 ( V_17 ) ;
}
int F_69 ( const char * V_23 )
{
struct V_16 * V_17 , * V_115 ;
int V_85 = - V_114 ;
F_9 ( L_52 , V_23 ) ;
F_6 ( & V_21 ) ;
F_70 (dt, nextdt, &ddebug_tables, link) {
if ( ! strcmp ( V_17 -> V_23 , V_23 ) ) {
F_67 ( V_17 ) ;
V_85 = 0 ;
}
}
F_10 ( & V_21 ) ;
return V_85 ;
}
static void F_71 ( void )
{
F_6 ( & V_21 ) ;
while ( ! F_47 ( & V_93 ) ) {
struct V_16 * V_17 = F_48 ( V_93 . V_96 ,
struct V_16 ,
V_97 ) ;
F_67 ( V_17 ) ;
}
F_10 ( & V_21 ) ;
}
static int T_3 F_72 ( void )
{
struct V_116 * V_117 , * V_80 ;
if ( ! V_118 )
return - V_119 ;
V_117 = F_73 ( L_53 , NULL ) ;
if ( ! V_117 )
return - V_89 ;
V_80 = F_74 ( L_54 , 0644 , V_117 , NULL ,
& V_120 ) ;
if ( ! V_80 ) {
F_75 ( V_117 ) ;
return - V_89 ;
}
return 0 ;
}
static int T_3 F_76 ( void )
{
struct V_3 * V_92 , * V_121 ;
const char * V_47 = NULL ;
char * V_122 ;
int V_85 = 0 ;
int V_101 = 0 , V_123 = 0 , V_124 = 0 ;
int V_125 = 0 ;
if ( V_126 == V_127 ) {
F_40 ( L_55
L_56 ) ;
return 1 ;
}
V_92 = V_126 ;
V_47 = V_92 -> V_47 ;
V_121 = V_92 ;
for (; V_92 < V_127 ; V_92 ++ ) {
V_123 ++ ;
V_125 += strlen ( V_92 -> V_47 ) + strlen ( V_92 -> V_27 )
+ strlen ( V_92 -> V_26 ) + strlen ( V_92 -> V_28 ) ;
if ( strcmp ( V_47 , V_92 -> V_47 ) ) {
V_124 ++ ;
V_85 = F_61 ( V_121 , V_101 , V_47 ) ;
if ( V_85 )
goto V_128;
V_101 = 0 ;
V_47 = V_92 -> V_47 ;
V_121 = V_92 ;
}
V_101 ++ ;
}
V_85 = F_61 ( V_121 , V_101 , V_47 ) ;
if ( V_85 )
goto V_128;
V_118 = 1 ;
F_9 ( L_57
L_58 ,
V_124 , V_123 , ( int ) ( V_124 * sizeof( struct V_16 ) ) ,
V_125 + ( int ) ( V_127 - V_126 ) ) ;
if ( V_79 [ 0 ] != '\0' ) {
F_40 ( L_59
L_60 ) ;
V_85 = F_26 ( V_79 , NULL ) ;
if ( V_85 < 0 )
F_40 ( L_61 ,
V_79 ) ;
else
F_11 ( L_62 , V_85 ) ;
}
V_122 = F_62 ( V_129 , V_88 ) ;
F_77 ( L_63 , V_122 , NULL ,
0 , 0 , 0 , & F_65 ) ;
F_45 ( V_122 ) ;
return 0 ;
V_128:
F_71 () ;
return 0 ;
}
