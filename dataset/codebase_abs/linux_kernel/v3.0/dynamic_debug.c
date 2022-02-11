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
if ( ! V_18 )
V_17 -> V_32 -- ;
else if ( ! V_4 -> V_10 )
V_17 -> V_32 ++ ;
V_4 -> V_10 = V_18 ;
if ( V_18 )
V_4 -> V_33 = 1 ;
else
V_4 -> V_33 = 0 ;
if ( V_34 )
F_8 ( V_35
L_1 ,
V_4 -> V_26 , V_4 -> V_30 ,
V_17 -> V_23 , V_4 -> V_27 ,
F_2 ( V_4 , V_20 ,
sizeof( V_20 ) ) ) ;
}
}
F_9 ( & V_21 ) ;
if ( ! V_19 && V_34 )
F_8 ( V_35 L_2 ) ;
}
static int F_10 ( char * V_5 , char * V_36 [] , int V_37 )
{
int V_38 = 0 ;
while ( * V_5 ) {
char * V_39 ;
V_5 = F_11 ( V_5 ) ;
if ( ! * V_5 )
break;
if ( * V_5 == '"' || * V_5 == '\'' ) {
int V_40 = * V_5 ++ ;
for ( V_39 = V_5 ; * V_39 && * V_39 != V_40 ; V_39 ++ )
;
if ( ! * V_39 )
return - V_41 ;
} else {
for ( V_39 = V_5 ; * V_39 && ! isspace ( * V_39 ) ; V_39 ++ )
;
F_3 ( V_39 == V_5 ) ;
}
if ( V_38 == V_37 )
return - V_41 ;
if ( * V_39 )
* V_39 ++ = '\0' ;
V_36 [ V_38 ++ ] = V_5 ;
V_5 = V_39 ;
}
if ( V_34 ) {
int V_8 ;
F_8 ( V_35 L_3 , V_42 ) ;
for ( V_8 = 0 ; V_8 < V_38 ; V_8 ++ )
F_8 ( L_4 , V_36 [ V_8 ] ) ;
F_8 ( L_5 ) ;
}
return V_38 ;
}
static inline int F_12 ( const char * V_43 , unsigned int * V_44 )
{
char * V_39 = NULL ;
F_3 ( V_43 == NULL ) ;
if ( * V_43 == '\0' ) {
* V_44 = 0 ;
return 0 ;
}
* V_44 = F_13 ( V_43 , & V_39 , 10 ) ;
return V_39 == NULL || V_39 == V_43 || * V_39 != '\0' ? - V_41 : 0 ;
}
static char * F_14 ( char * V_43 )
{
char * V_45 = V_43 ;
char * V_46 = V_43 ;
while ( * V_45 ) {
if ( * V_45 == '\\' ) {
if ( V_45 [ 1 ] == '\\' ) {
* V_46 ++ = '\\' ;
V_45 += 2 ;
continue;
} else if ( V_45 [ 1 ] == 't' ) {
* V_46 ++ = '\t' ;
V_45 += 2 ;
continue;
} else if ( V_45 [ 1 ] == 'n' ) {
* V_46 ++ = '\n' ;
V_45 += 2 ;
continue;
} else if ( F_15 ( V_45 [ 1 ] ) &&
F_15 ( V_45 [ 2 ] ) &&
F_15 ( V_45 [ 3 ] ) ) {
* V_46 ++ = ( ( V_45 [ 1 ] - '0' ) << 6 ) |
( ( V_45 [ 2 ] - '0' ) << 3 ) |
( V_45 [ 3 ] - '0' ) ;
V_45 += 4 ;
continue;
}
}
* V_46 ++ = * V_45 ++ ;
}
* V_46 = '\0' ;
return V_43 ;
}
static int F_16 ( char * V_36 [] , int V_38 ,
struct V_13 * V_14 )
{
unsigned int V_8 ;
if ( V_38 % 2 != 0 )
return - V_41 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
for ( V_8 = 0 ; V_8 < V_38 ; V_8 += 2 ) {
if ( ! strcmp ( V_36 [ V_8 ] , L_6 ) )
V_14 -> V_27 = V_36 [ V_8 + 1 ] ;
else if ( ! strcmp ( V_36 [ V_8 ] , L_7 ) )
V_14 -> V_26 = V_36 [ V_8 + 1 ] ;
else if ( ! strcmp ( V_36 [ V_8 ] , L_8 ) )
V_14 -> V_22 = V_36 [ V_8 + 1 ] ;
else if ( ! strcmp ( V_36 [ V_8 ] , L_9 ) )
V_14 -> V_28 = F_14 ( V_36 [ V_8 + 1 ] ) ;
else if ( ! strcmp ( V_36 [ V_8 ] , L_10 ) ) {
char * V_47 = V_36 [ V_8 + 1 ] ;
char * V_48 = strchr ( V_47 , '-' ) ;
if ( V_48 )
* V_48 ++ = '\0' ;
if ( F_12 ( V_47 , & V_14 -> V_29 ) < 0 )
return - V_41 ;
if ( V_48 != NULL ) {
if ( F_12 ( V_48 , & V_14 -> V_31 ) < 0 )
return - V_41 ;
} else {
V_14 -> V_31 = V_14 -> V_29 ;
}
} else {
if ( V_34 )
F_8 ( V_49 L_11 ,
V_42 , V_36 [ V_8 ] ) ;
return - V_41 ;
}
}
if ( V_34 )
F_8 ( V_35 L_12
L_13 ,
V_42 , V_14 -> V_27 , V_14 -> V_26 ,
V_14 -> V_22 , V_14 -> V_28 , V_14 -> V_29 ,
V_14 -> V_31 ) ;
return 0 ;
}
static int F_17 ( const char * V_43 , unsigned int * V_50 ,
unsigned int * V_51 )
{
unsigned V_10 = 0 ;
int V_52 = '=' , V_8 ;
switch ( * V_43 ) {
case '+' :
case '-' :
case '=' :
V_52 = * V_43 ++ ;
break;
default:
return - V_41 ;
}
if ( V_34 )
F_8 ( V_35 L_14 , V_42 , V_52 ) ;
for ( ; * V_43 ; ++ V_43 ) {
for ( V_8 = F_4 ( V_9 ) - 1 ; V_8 >= 0 ; V_8 -- ) {
if ( * V_43 == V_9 [ V_8 ] . V_12 ) {
V_10 |= V_9 [ V_8 ] . V_11 ;
break;
}
}
if ( V_8 < 0 )
return - V_41 ;
}
if ( V_10 == 0 )
return - V_41 ;
if ( V_34 )
F_8 ( V_35 L_15 , V_42 , V_10 ) ;
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
if ( V_34 )
F_8 ( V_35 L_16 ,
V_42 , * V_50 , * V_51 ) ;
return 0 ;
}
static int F_18 ( char * V_53 )
{
unsigned int V_10 = 0 , V_15 = 0 ;
struct V_13 V_14 ;
#define F_19 9
int V_38 ;
char * V_36 [ F_19 ] ;
V_38 = F_10 ( V_53 , V_36 , F_19 ) ;
if ( V_38 <= 0 )
return - V_41 ;
if ( F_16 ( V_36 , V_38 - 1 , & V_14 ) )
return - V_41 ;
if ( F_17 ( V_36 [ V_38 - 1 ] , & V_10 , & V_15 ) )
return - V_41 ;
F_5 ( & V_14 , V_10 , V_15 ) ;
return 0 ;
}
int F_20 ( struct V_3 * V_54 , const char * V_55 , ... )
{
T_2 args ;
int V_56 ;
F_3 ( ! V_54 ) ;
F_3 ( ! V_55 ) ;
va_start ( args , V_55 ) ;
V_56 = F_8 ( V_57 ) ;
if ( V_54 -> V_10 & V_58 ) {
if ( F_21 () )
V_56 += F_8 ( V_59 L_17 ) ;
else
V_56 += F_8 ( V_59 L_18 , F_22 ( V_60 ) ) ;
}
if ( V_54 -> V_10 & V_61 )
V_56 += F_8 ( V_59 L_19 , V_54 -> V_62 ) ;
if ( V_54 -> V_10 & V_63 )
V_56 += F_8 ( V_59 L_19 , V_54 -> V_27 ) ;
if ( V_54 -> V_10 & V_64 )
V_56 += F_8 ( V_59 L_20 , V_54 -> V_30 ) ;
V_56 += F_23 ( V_55 , args ) ;
va_end ( args ) ;
return V_56 ;
}
static T_3 int F_24 ( char * V_43 )
{
if ( strlen ( V_43 ) >= 1024 ) {
F_25 ( L_21 ) ;
return 0 ;
}
strcpy ( V_65 , V_43 ) ;
return 1 ;
}
static T_4 F_26 ( struct V_66 * V_66 , const char T_5 * V_67 ,
T_1 V_68 , T_6 * V_69 )
{
char V_70 [ 256 ] ;
int V_71 ;
if ( V_68 == 0 )
return 0 ;
if ( V_68 > sizeof( V_70 ) - 1 )
return - V_72 ;
if ( F_27 ( V_70 , V_67 , V_68 ) )
return - V_73 ;
V_70 [ V_68 ] = '\0' ;
if ( V_34 )
F_8 ( V_35 L_22 ,
V_42 , ( int ) V_68 ) ;
V_71 = F_18 ( V_70 ) ;
if ( V_71 )
return V_71 ;
* V_69 += V_68 ;
return V_68 ;
}
static struct V_3 * F_28 ( struct V_74 * V_75 )
{
if ( F_29 ( & V_76 ) ) {
V_75 -> V_77 = NULL ;
V_75 -> V_78 = 0 ;
return NULL ;
}
V_75 -> V_77 = F_30 ( V_76 . V_79 ,
struct V_16 , V_80 ) ;
V_75 -> V_78 = 0 ;
return & V_75 -> V_77 -> V_25 [ V_75 -> V_78 ] ;
}
static struct V_3 * F_31 ( struct V_74 * V_75 )
{
if ( V_75 -> V_77 == NULL )
return NULL ;
if ( ++ V_75 -> V_78 == V_75 -> V_77 -> V_24 ) {
V_75 -> V_78 = 0 ;
if ( F_32 ( & V_75 -> V_77 -> V_80 , & V_76 ) ) {
V_75 -> V_77 = NULL ;
return NULL ;
}
V_75 -> V_77 = F_30 ( V_75 -> V_77 -> V_80 . V_79 ,
struct V_16 , V_80 ) ;
}
return & V_75 -> V_77 -> V_25 [ V_75 -> V_78 ] ;
}
static void * F_33 ( struct V_81 * V_82 , T_6 * V_83 )
{
struct V_74 * V_75 = V_82 -> V_84 ;
struct V_3 * V_4 ;
int V_85 = * V_83 ;
if ( V_34 )
F_8 ( V_35 L_23 ,
V_42 , V_82 , ( unsigned long long ) * V_83 ) ;
F_6 ( & V_21 ) ;
if ( ! V_85 )
return V_86 ;
if ( V_85 < 0 )
return NULL ;
V_4 = F_28 ( V_75 ) ;
while ( V_4 != NULL && -- V_85 > 0 )
V_4 = F_31 ( V_75 ) ;
return V_4 ;
}
static void * F_34 ( struct V_81 * V_82 , void * V_7 , T_6 * V_83 )
{
struct V_74 * V_75 = V_82 -> V_84 ;
struct V_3 * V_4 ;
if ( V_34 )
F_8 ( V_35 L_24 ,
V_42 , V_82 , V_7 , ( unsigned long long ) * V_83 ) ;
if ( V_7 == V_86 )
V_4 = F_28 ( V_75 ) ;
else
V_4 = F_31 ( V_75 ) ;
++ * V_83 ;
return V_4 ;
}
static int F_35 ( struct V_81 * V_82 , void * V_7 )
{
struct V_74 * V_75 = V_82 -> V_84 ;
struct V_3 * V_4 = V_7 ;
char V_87 [ 8 ] ;
if ( V_34 )
F_8 ( V_35 L_25 ,
V_42 , V_82 , V_7 ) ;
if ( V_7 == V_86 ) {
F_36 ( V_82 ,
L_26 ) ;
return 0 ;
}
F_37 ( V_82 , L_27 ,
V_4 -> V_26 , V_4 -> V_30 ,
V_75 -> V_77 -> V_23 , V_4 -> V_27 ,
F_2 ( V_4 , V_87 , sizeof( V_87 ) ) ) ;
F_38 ( V_82 , V_4 -> V_28 , L_28 ) ;
F_36 ( V_82 , L_29 ) ;
return 0 ;
}
static void F_39 ( struct V_81 * V_82 , void * V_7 )
{
if ( V_34 )
F_8 ( V_35 L_25 ,
V_42 , V_82 , V_7 ) ;
F_9 ( & V_21 ) ;
}
static int F_40 ( struct V_88 * V_88 , struct V_66 * V_66 )
{
struct V_74 * V_75 ;
int V_89 ;
if ( V_34 )
F_8 ( V_35 L_30 , V_42 ) ;
V_75 = F_41 ( sizeof( * V_75 ) , V_90 ) ;
if ( V_75 == NULL )
return - V_91 ;
V_89 = F_42 ( V_66 , & V_92 ) ;
if ( V_89 ) {
F_43 ( V_75 ) ;
return V_89 ;
}
( (struct V_81 * ) V_66 -> V_93 ) -> V_84 = V_75 ;
return 0 ;
}
int F_44 ( struct V_3 * V_94 , unsigned int V_85 ,
const char * V_95 )
{
struct V_16 * V_17 ;
char * V_96 ;
V_17 = F_41 ( sizeof( * V_17 ) , V_90 ) ;
if ( V_17 == NULL )
return - V_91 ;
V_96 = F_45 ( V_95 , V_90 ) ;
if ( V_96 == NULL ) {
F_43 ( V_17 ) ;
return - V_91 ;
}
V_17 -> V_23 = V_96 ;
V_17 -> V_24 = V_85 ;
V_17 -> V_32 = 0 ;
V_17 -> V_25 = V_94 ;
F_6 ( & V_21 ) ;
F_46 ( & V_17 -> V_80 , & V_76 ) ;
F_9 ( & V_21 ) ;
if ( V_34 )
F_8 ( V_35 L_31 ,
V_85 , V_17 -> V_23 ) ;
return 0 ;
}
static void F_47 ( struct V_16 * V_17 )
{
F_48 ( & V_17 -> V_80 ) ;
F_43 ( V_17 -> V_23 ) ;
F_43 ( V_17 ) ;
}
int F_49 ( const char * V_23 )
{
struct V_16 * V_17 , * V_97 ;
int V_71 = - V_98 ;
if ( V_34 )
F_8 ( V_35 L_32 ,
V_42 , V_23 ) ;
F_6 ( & V_21 ) ;
F_50 (dt, nextdt, &ddebug_tables, link) {
if ( ! strcmp ( V_17 -> V_23 , V_23 ) ) {
F_47 ( V_17 ) ;
V_71 = 0 ;
}
}
F_9 ( & V_21 ) ;
return V_71 ;
}
static void F_51 ( void )
{
F_6 ( & V_21 ) ;
while ( ! F_29 ( & V_76 ) ) {
struct V_16 * V_17 = F_30 ( V_76 . V_79 ,
struct V_16 ,
V_80 ) ;
F_47 ( V_17 ) ;
}
F_9 ( & V_21 ) ;
}
static int T_3 F_52 ( void )
{
struct V_99 * V_100 , * V_66 ;
if ( ! V_101 )
return - V_102 ;
V_100 = F_53 ( L_33 , NULL ) ;
if ( ! V_100 )
return - V_91 ;
V_66 = F_54 ( L_34 , 0644 , V_100 , NULL ,
& V_103 ) ;
if ( ! V_66 ) {
F_55 ( V_100 ) ;
return - V_91 ;
}
return 0 ;
}
static int T_3 F_56 ( void )
{
struct V_3 * V_75 , * V_104 ;
const char * V_62 = NULL ;
int V_71 = 0 ;
int V_85 = 0 ;
if ( V_105 != V_106 ) {
V_75 = V_105 ;
V_62 = V_75 -> V_62 ;
V_104 = V_75 ;
for (; V_75 < V_106 ; V_75 ++ ) {
if ( strcmp ( V_62 , V_75 -> V_62 ) ) {
V_71 = F_44 ( V_104 , V_85 , V_62 ) ;
if ( V_71 )
goto V_107;
V_85 = 0 ;
V_62 = V_75 -> V_62 ;
V_104 = V_75 ;
}
V_85 ++ ;
}
V_71 = F_44 ( V_104 , V_85 , V_62 ) ;
}
if ( V_65 [ 0 ] != '\0' ) {
V_71 = F_18 ( V_65 ) ;
if ( V_71 )
F_25 ( L_35 ,
V_65 ) ;
else
F_57 ( L_36 ,
V_65 ) ;
}
V_107:
if ( V_71 )
F_51 () ;
else
V_101 = 1 ;
return 0 ;
}
