static inline const char * F_1 ( const char * V_1 )
{
const char * V_2 = strrchr ( V_1 , '/' ) ;
return V_2 ? V_2 + 1 : V_1 ;
}
static char * F_2 ( struct V_3 * V_4 , char * V_5 ,
T_1 V_6 )
{
char * V_7 = V_5 ;
int V_8 ;
F_3 ( V_6 < 4 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_9 ) ; ++ V_8 )
if ( V_4 -> V_10 & V_9 [ V_8 ] . V_11 )
* V_7 ++ = V_9 [ V_8 ] . V_12 ;
if ( V_7 == V_5 )
* V_7 ++ = '-' ;
* V_7 = '\0' ;
return V_5 ;
}
static void F_5 ( const struct V_13 * V_14 ,
unsigned int V_10 , unsigned int V_15 )
{
int V_8 ;
struct V_16 * V_17 ;
unsigned int V_18 ;
unsigned int V_19 = 0 ;
char V_20 [ 8 ] ;
F_6 ( & V_21 ) ;
F_7 (dt, &ddebug_tables, link) {
if ( V_14 -> V_22 != NULL &&
strcmp ( V_14 -> V_22 , V_17 -> V_23 ) )
continue;
for ( V_8 = 0 ; V_8 < V_17 -> V_24 ; V_8 ++ ) {
struct V_3 * V_4 = & V_17 -> V_25 [ V_8 ] ;
if ( V_14 -> V_26 != NULL &&
strcmp ( V_14 -> V_26 , V_4 -> V_26 ) &&
strcmp ( V_14 -> V_26 , F_1 ( V_4 -> V_26 ) ) )
continue;
if ( V_14 -> V_27 != NULL &&
strcmp ( V_14 -> V_27 , V_4 -> V_27 ) )
continue;
if ( V_14 -> V_28 != NULL &&
strstr ( V_4 -> V_28 , V_14 -> V_28 ) == NULL )
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
if ( V_18 )
V_4 -> V_32 = 1 ;
else
V_4 -> V_32 = 0 ;
if ( V_33 )
F_8 ( L_1 ,
V_4 -> V_26 , V_4 -> V_30 ,
V_17 -> V_23 , V_4 -> V_27 ,
F_2 ( V_4 , V_20 ,
sizeof( V_20 ) ) ) ;
}
}
F_9 ( & V_21 ) ;
if ( ! V_19 && V_33 )
F_8 ( L_2 ) ;
}
static int F_10 ( char * V_5 , char * V_34 [] , int V_35 )
{
int V_36 = 0 ;
while ( * V_5 ) {
char * V_37 ;
V_5 = F_11 ( V_5 ) ;
if ( ! * V_5 )
break;
if ( * V_5 == '"' || * V_5 == '\'' ) {
int V_38 = * V_5 ++ ;
for ( V_37 = V_5 ; * V_37 && * V_37 != V_38 ; V_37 ++ )
;
if ( ! * V_37 )
return - V_39 ;
} else {
for ( V_37 = V_5 ; * V_37 && ! isspace ( * V_37 ) ; V_37 ++ )
;
F_3 ( V_37 == V_5 ) ;
}
if ( V_36 == V_35 )
return - V_39 ;
if ( * V_37 )
* V_37 ++ = '\0' ;
V_34 [ V_36 ++ ] = V_5 ;
V_5 = V_37 ;
}
if ( V_33 ) {
int V_8 ;
F_8 ( L_3 ) ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
F_12 ( L_4 , V_34 [ V_8 ] ) ;
F_12 ( L_5 ) ;
}
return V_36 ;
}
static inline int F_13 ( const char * V_40 , unsigned int * V_41 )
{
char * V_37 = NULL ;
F_3 ( V_40 == NULL ) ;
if ( * V_40 == '\0' ) {
* V_41 = 0 ;
return 0 ;
}
* V_41 = F_14 ( V_40 , & V_37 , 10 ) ;
return V_37 == NULL || V_37 == V_40 || * V_37 != '\0' ? - V_39 : 0 ;
}
static char * F_15 ( char * V_40 )
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
} else if ( F_16 ( V_42 [ 1 ] ) &&
F_16 ( V_42 [ 2 ] ) &&
F_16 ( V_42 [ 3 ] ) ) {
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
static int F_17 ( char * V_34 [] , int V_36 ,
struct V_13 * V_14 )
{
unsigned int V_8 ;
if ( V_36 % 2 != 0 )
return - V_39 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 += 2 ) {
if ( ! strcmp ( V_34 [ V_8 ] , L_6 ) )
V_14 -> V_27 = V_34 [ V_8 + 1 ] ;
else if ( ! strcmp ( V_34 [ V_8 ] , L_7 ) )
V_14 -> V_26 = V_34 [ V_8 + 1 ] ;
else if ( ! strcmp ( V_34 [ V_8 ] , L_8 ) )
V_14 -> V_22 = V_34 [ V_8 + 1 ] ;
else if ( ! strcmp ( V_34 [ V_8 ] , L_9 ) )
V_14 -> V_28 = F_15 ( V_34 [ V_8 + 1 ] ) ;
else if ( ! strcmp ( V_34 [ V_8 ] , L_10 ) ) {
char * V_44 = V_34 [ V_8 + 1 ] ;
char * V_45 = strchr ( V_44 , '-' ) ;
if ( V_45 )
* V_45 ++ = '\0' ;
if ( F_13 ( V_44 , & V_14 -> V_29 ) < 0 )
return - V_39 ;
if ( V_45 != NULL ) {
if ( F_13 ( V_45 , & V_14 -> V_31 ) < 0 )
return - V_39 ;
} else {
V_14 -> V_31 = V_14 -> V_29 ;
}
} else {
if ( V_33 )
F_18 ( L_11 , V_34 [ V_8 ] ) ;
return - V_39 ;
}
}
if ( V_33 )
F_8 ( L_12
L_13 ,
V_14 -> V_27 , V_14 -> V_26 ,
V_14 -> V_22 , V_14 -> V_28 , V_14 -> V_29 ,
V_14 -> V_31 ) ;
return 0 ;
}
static int F_19 ( const char * V_40 , unsigned int * V_46 ,
unsigned int * V_47 )
{
unsigned V_10 = 0 ;
int V_48 = '=' , V_8 ;
switch ( * V_40 ) {
case '+' :
case '-' :
case '=' :
V_48 = * V_40 ++ ;
break;
default:
return - V_39 ;
}
if ( V_33 )
F_8 ( L_14 , V_48 ) ;
for ( ; * V_40 ; ++ V_40 ) {
for ( V_8 = F_4 ( V_9 ) - 1 ; V_8 >= 0 ; V_8 -- ) {
if ( * V_40 == V_9 [ V_8 ] . V_12 ) {
V_10 |= V_9 [ V_8 ] . V_11 ;
break;
}
}
if ( V_8 < 0 )
return - V_39 ;
}
if ( V_10 == 0 )
return - V_39 ;
if ( V_33 )
F_8 ( L_15 , V_10 ) ;
switch ( V_48 ) {
case '=' :
* V_47 = 0 ;
* V_46 = V_10 ;
break;
case '+' :
* V_47 = ~ 0U ;
* V_46 = V_10 ;
break;
case '-' :
* V_47 = ~ V_10 ;
* V_46 = 0 ;
break;
}
if ( V_33 )
F_8 ( L_16 , * V_46 , * V_47 ) ;
return 0 ;
}
static int F_20 ( char * V_49 )
{
unsigned int V_10 = 0 , V_15 = 0 ;
struct V_13 V_14 ;
#define F_21 9
int V_36 ;
char * V_34 [ F_21 ] ;
V_36 = F_10 ( V_49 , V_34 , F_21 ) ;
if ( V_36 <= 0 )
return - V_39 ;
if ( F_17 ( V_34 , V_36 - 1 , & V_14 ) )
return - V_39 ;
if ( F_19 ( V_34 [ V_36 - 1 ] , & V_10 , & V_15 ) )
return - V_39 ;
F_5 ( & V_14 , V_10 , V_15 ) ;
return 0 ;
}
static int F_22 ( int V_50 )
{
if ( V_51 - V_50 > 0 )
return V_51 - V_50 ;
return 0 ;
}
static char * F_23 ( const struct V_3 * V_52 , char * V_5 )
{
int V_53 ;
int V_54 = 0 ;
V_54 += snprintf ( V_5 + V_54 , F_22 ( V_54 ) , L_17 , V_55 ) ;
if ( V_52 -> V_10 & V_56 ) {
if ( F_24 () )
V_54 += snprintf ( V_5 + V_54 , F_22 ( V_54 ) , L_18 ,
L_19 ) ;
else
V_54 += snprintf ( V_5 + V_54 , F_22 ( V_54 ) , L_20 ,
F_25 ( V_57 ) ) ;
}
V_53 = V_54 ;
if ( V_52 -> V_10 & V_58 )
V_54 += snprintf ( V_5 + V_54 , F_22 ( V_54 ) , L_21 ,
V_52 -> V_59 ) ;
if ( V_52 -> V_10 & V_60 )
V_54 += snprintf ( V_5 + V_54 , F_22 ( V_54 ) , L_21 ,
V_52 -> V_27 ) ;
if ( V_52 -> V_10 & V_61 )
V_54 += snprintf ( V_5 + V_54 , F_22 ( V_54 ) , L_22 , V_52 -> V_30 ) ;
if ( V_54 - V_53 )
V_54 += snprintf ( V_5 + V_54 , F_22 ( V_54 ) , L_23 ) ;
if ( V_54 >= V_51 )
V_5 [ V_51 - 1 ] = '\0' ;
return V_5 ;
}
int F_26 ( struct V_3 * V_62 , const char * V_63 , ... )
{
T_2 args ;
int V_64 ;
struct V_65 V_66 ;
char V_5 [ V_51 ] ;
F_3 ( ! V_62 ) ;
F_3 ( ! V_63 ) ;
va_start ( args , V_63 ) ;
V_66 . V_63 = V_63 ;
V_66 . V_67 = & args ;
V_64 = F_27 ( L_24 , F_23 ( V_62 , V_5 ) , & V_66 ) ;
va_end ( args ) ;
return V_64 ;
}
int F_28 ( struct V_3 * V_62 ,
const struct V_68 * V_69 , const char * V_63 , ... )
{
struct V_65 V_66 ;
T_2 args ;
int V_64 ;
char V_5 [ V_51 ] ;
F_3 ( ! V_62 ) ;
F_3 ( ! V_63 ) ;
va_start ( args , V_63 ) ;
V_66 . V_63 = V_63 ;
V_66 . V_67 = & args ;
V_64 = F_29 ( F_23 ( V_62 , V_5 ) , V_69 , & V_66 ) ;
va_end ( args ) ;
return V_64 ;
}
int F_30 ( struct V_3 * V_62 ,
const struct V_70 * V_69 , const char * V_63 , ... )
{
struct V_65 V_66 ;
T_2 args ;
int V_64 ;
char V_5 [ V_51 ] ;
F_3 ( ! V_62 ) ;
F_3 ( ! V_63 ) ;
va_start ( args , V_63 ) ;
V_66 . V_63 = V_63 ;
V_66 . V_67 = & args ;
V_64 = F_31 ( F_23 ( V_62 , V_5 ) , V_69 , & V_66 ) ;
va_end ( args ) ;
return V_64 ;
}
static T_3 int F_32 ( char * V_40 )
{
if ( strlen ( V_40 ) >= 1024 ) {
F_33 ( L_25 ) ;
return 0 ;
}
strcpy ( V_71 , V_40 ) ;
return 1 ;
}
static T_4 F_34 ( struct V_72 * V_72 , const char T_5 * V_73 ,
T_1 V_74 , T_6 * V_75 )
{
char V_76 [ 256 ] ;
int V_77 ;
if ( V_74 == 0 )
return 0 ;
if ( V_74 > sizeof( V_76 ) - 1 )
return - V_78 ;
if ( F_35 ( V_76 , V_73 , V_74 ) )
return - V_79 ;
V_76 [ V_74 ] = '\0' ;
if ( V_33 )
F_8 ( L_26 , ( int ) V_74 ) ;
V_77 = F_20 ( V_76 ) ;
if ( V_77 )
return V_77 ;
* V_75 += V_74 ;
return V_74 ;
}
static struct V_3 * F_36 ( struct V_80 * V_81 )
{
if ( F_37 ( & V_82 ) ) {
V_81 -> V_83 = NULL ;
V_81 -> V_84 = 0 ;
return NULL ;
}
V_81 -> V_83 = F_38 ( V_82 . V_85 ,
struct V_16 , V_86 ) ;
V_81 -> V_84 = 0 ;
return & V_81 -> V_83 -> V_25 [ V_81 -> V_84 ] ;
}
static struct V_3 * F_39 ( struct V_80 * V_81 )
{
if ( V_81 -> V_83 == NULL )
return NULL ;
if ( ++ V_81 -> V_84 == V_81 -> V_83 -> V_24 ) {
V_81 -> V_84 = 0 ;
if ( F_40 ( & V_81 -> V_83 -> V_86 , & V_82 ) ) {
V_81 -> V_83 = NULL ;
return NULL ;
}
V_81 -> V_83 = F_38 ( V_81 -> V_83 -> V_86 . V_85 ,
struct V_16 , V_86 ) ;
}
return & V_81 -> V_83 -> V_25 [ V_81 -> V_84 ] ;
}
static void * F_41 ( struct V_87 * V_88 , T_6 * V_54 )
{
struct V_80 * V_81 = V_88 -> V_89 ;
struct V_3 * V_4 ;
int V_90 = * V_54 ;
if ( V_33 )
F_8 ( L_27 , V_88 , ( unsigned long long ) * V_54 ) ;
F_6 ( & V_21 ) ;
if ( ! V_90 )
return V_91 ;
if ( V_90 < 0 )
return NULL ;
V_4 = F_36 ( V_81 ) ;
while ( V_4 != NULL && -- V_90 > 0 )
V_4 = F_39 ( V_81 ) ;
return V_4 ;
}
static void * F_42 ( struct V_87 * V_88 , void * V_7 , T_6 * V_54 )
{
struct V_80 * V_81 = V_88 -> V_89 ;
struct V_3 * V_4 ;
if ( V_33 )
F_8 ( L_28 ,
V_88 , V_7 , ( unsigned long long ) * V_54 ) ;
if ( V_7 == V_91 )
V_4 = F_36 ( V_81 ) ;
else
V_4 = F_39 ( V_81 ) ;
++ * V_54 ;
return V_4 ;
}
static int F_43 ( struct V_87 * V_88 , void * V_7 )
{
struct V_80 * V_81 = V_88 -> V_89 ;
struct V_3 * V_4 = V_7 ;
char V_92 [ 8 ] ;
if ( V_33 )
F_8 ( L_29 , V_88 , V_7 ) ;
if ( V_7 == V_91 ) {
F_44 ( V_88 ,
L_30 ) ;
return 0 ;
}
F_45 ( V_88 , L_31 ,
V_4 -> V_26 , V_4 -> V_30 ,
V_81 -> V_83 -> V_23 , V_4 -> V_27 ,
F_2 ( V_4 , V_92 , sizeof( V_92 ) ) ) ;
F_46 ( V_88 , V_4 -> V_28 , L_32 ) ;
F_44 ( V_88 , L_33 ) ;
return 0 ;
}
static void F_47 ( struct V_87 * V_88 , void * V_7 )
{
if ( V_33 )
F_8 ( L_29 , V_88 , V_7 ) ;
F_9 ( & V_21 ) ;
}
static int F_48 ( struct V_93 * V_93 , struct V_72 * V_72 )
{
struct V_80 * V_81 ;
int V_94 ;
if ( V_33 )
F_8 ( L_34 ) ;
V_81 = F_49 ( sizeof( * V_81 ) , V_95 ) ;
if ( V_81 == NULL )
return - V_96 ;
V_94 = F_50 ( V_72 , & V_97 ) ;
if ( V_94 ) {
F_51 ( V_81 ) ;
return V_94 ;
}
( (struct V_87 * ) V_72 -> V_98 ) -> V_89 = V_81 ;
return 0 ;
}
int F_52 ( struct V_3 * V_99 , unsigned int V_90 ,
const char * V_100 )
{
struct V_16 * V_17 ;
char * V_101 ;
V_17 = F_49 ( sizeof( * V_17 ) , V_95 ) ;
if ( V_17 == NULL )
return - V_96 ;
V_101 = F_53 ( V_100 , V_95 ) ;
if ( V_101 == NULL ) {
F_51 ( V_17 ) ;
return - V_96 ;
}
V_17 -> V_23 = V_101 ;
V_17 -> V_24 = V_90 ;
V_17 -> V_25 = V_99 ;
F_6 ( & V_21 ) ;
F_54 ( & V_17 -> V_86 , & V_82 ) ;
F_9 ( & V_21 ) ;
if ( V_33 )
F_8 ( L_35 , V_90 , V_17 -> V_23 ) ;
return 0 ;
}
static void F_55 ( struct V_16 * V_17 )
{
F_56 ( & V_17 -> V_86 ) ;
F_51 ( V_17 -> V_23 ) ;
F_51 ( V_17 ) ;
}
int F_57 ( const char * V_23 )
{
struct V_16 * V_17 , * V_102 ;
int V_77 = - V_103 ;
if ( V_33 )
F_8 ( L_36 , V_23 ) ;
F_6 ( & V_21 ) ;
F_58 (dt, nextdt, &ddebug_tables, link) {
if ( ! strcmp ( V_17 -> V_23 , V_23 ) ) {
F_55 ( V_17 ) ;
V_77 = 0 ;
}
}
F_9 ( & V_21 ) ;
return V_77 ;
}
static void F_59 ( void )
{
F_6 ( & V_21 ) ;
while ( ! F_37 ( & V_82 ) ) {
struct V_16 * V_17 = F_38 ( V_82 . V_85 ,
struct V_16 ,
V_86 ) ;
F_55 ( V_17 ) ;
}
F_9 ( & V_21 ) ;
}
static int T_3 F_60 ( void )
{
struct V_104 * V_105 , * V_72 ;
if ( ! V_106 )
return - V_107 ;
V_105 = F_61 ( L_37 , NULL ) ;
if ( ! V_105 )
return - V_96 ;
V_72 = F_62 ( L_38 , 0644 , V_105 , NULL ,
& V_108 ) ;
if ( ! V_72 ) {
F_63 ( V_105 ) ;
return - V_96 ;
}
return 0 ;
}
static int T_3 F_64 ( void )
{
struct V_3 * V_81 , * V_109 ;
const char * V_59 = NULL ;
int V_77 = 0 ;
int V_90 = 0 ;
if ( V_110 != V_111 ) {
V_81 = V_110 ;
V_59 = V_81 -> V_59 ;
V_109 = V_81 ;
for (; V_81 < V_111 ; V_81 ++ ) {
if ( strcmp ( V_59 , V_81 -> V_59 ) ) {
V_77 = F_52 ( V_109 , V_90 , V_59 ) ;
if ( V_77 )
goto V_112;
V_90 = 0 ;
V_59 = V_81 -> V_59 ;
V_109 = V_81 ;
}
V_90 ++ ;
}
V_77 = F_52 ( V_109 , V_90 , V_59 ) ;
}
if ( V_71 [ 0 ] != '\0' ) {
V_77 = F_20 ( V_71 ) ;
if ( V_77 )
F_33 ( L_39 ,
V_71 ) ;
else
F_8 ( L_40 ,
V_71 ) ;
}
V_112:
if ( V_77 )
F_59 () ;
else
V_106 = 1 ;
return 0 ;
}
