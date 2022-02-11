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
if ( V_14 -> V_20 &&
! F_10 ( V_14 -> V_20 , V_25 -> V_30 ) )
continue;
for ( V_8 = 0 ; V_8 < V_25 -> V_31 ; V_8 ++ ) {
struct V_3 * V_4 = & V_25 -> V_32 [ V_8 ] ;
if ( V_14 -> V_19 &&
! F_10 ( V_14 -> V_19 , V_4 -> V_19 ) &&
! F_10 ( V_14 -> V_19 ,
F_11 ( V_4 -> V_19 ) ) &&
! F_10 ( V_14 -> V_19 ,
F_1 ( V_4 -> V_19 ) ) )
continue;
if ( V_14 -> V_18 &&
! F_10 ( V_14 -> V_18 , V_4 -> V_18 ) )
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
#ifdef F_12
if ( V_4 -> V_10 & V_34 ) {
if ( ! ( V_10 & V_34 ) )
F_13 ( & V_4 -> V_35 . V_36 ) ;
} else if ( V_10 & V_34 )
F_14 ( & V_4 -> V_35 . V_36 ) ;
#endif
V_4 -> V_10 = V_26 ;
F_6 ( L_4 ,
F_1 ( V_4 -> V_19 ) , V_4 -> V_33 ,
V_25 -> V_30 , V_4 -> V_18 ,
F_2 ( V_4 , V_28 ,
sizeof( V_28 ) ) ) ;
}
}
F_15 ( & V_29 ) ;
if ( ! V_27 && V_37 )
F_16 ( L_5 ) ;
return V_27 ;
}
static int F_17 ( char * V_5 , char * V_38 [] , int V_39 )
{
int V_40 = 0 ;
while ( * V_5 ) {
char * V_41 ;
V_5 = F_18 ( V_5 ) ;
if ( ! * V_5 )
break;
if ( * V_5 == '#' )
break;
if ( * V_5 == '"' || * V_5 == '\'' ) {
int V_42 = * V_5 ++ ;
for ( V_41 = V_5 ; * V_41 && * V_41 != V_42 ; V_41 ++ )
;
if ( ! * V_41 ) {
F_19 ( L_6 , V_5 ) ;
return - V_43 ;
}
} else {
for ( V_41 = V_5 ; * V_41 && ! isspace ( * V_41 ) ; V_41 ++ )
;
F_3 ( V_41 == V_5 ) ;
}
if ( V_40 == V_39 ) {
F_19 ( L_7 , V_39 ) ;
return - V_43 ;
}
if ( * V_41 )
* V_41 ++ = '\0' ;
V_38 [ V_40 ++ ] = V_5 ;
V_5 = V_41 ;
}
if ( V_37 ) {
int V_8 ;
F_16 ( L_8 ) ;
for ( V_8 = 0 ; V_8 < V_40 ; V_8 ++ )
F_20 ( L_9 , V_38 [ V_8 ] ) ;
F_20 ( L_10 ) ;
}
return V_40 ;
}
static inline int F_21 ( const char * V_44 , unsigned int * V_45 )
{
F_3 ( V_44 == NULL ) ;
if ( * V_44 == '\0' ) {
* V_45 = 0 ;
return 0 ;
}
if ( F_22 ( V_44 , 10 , V_45 ) < 0 ) {
F_19 ( L_11 , V_44 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_23 ( const char * * V_46 , char * V_47 , char * V_48 )
{
int V_49 = 0 ;
if ( * V_46 ) {
V_49 = - V_43 ;
F_19 ( L_12 ,
V_48 , * V_46 , V_47 ) ;
}
* V_46 = V_47 ;
return V_49 ;
}
static int F_24 ( char * V_38 [] , int V_40 ,
struct V_13 * V_14 , const char * V_50 )
{
unsigned int V_8 ;
int V_49 = 0 ;
if ( V_40 % 2 != 0 ) {
F_19 ( L_13 ) ;
return - V_43 ;
}
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
if ( V_50 )
V_14 -> V_20 = V_50 ;
for ( V_8 = 0 ; V_8 < V_40 ; V_8 += 2 ) {
if ( ! strcmp ( V_38 [ V_8 ] , L_14 ) ) {
V_49 = F_23 ( & V_14 -> V_18 , V_38 [ V_8 + 1 ] , L_14 ) ;
} else if ( ! strcmp ( V_38 [ V_8 ] , L_15 ) ) {
V_49 = F_23 ( & V_14 -> V_19 , V_38 [ V_8 + 1 ] , L_15 ) ;
} else if ( ! strcmp ( V_38 [ V_8 ] , L_16 ) ) {
V_49 = F_23 ( & V_14 -> V_20 , V_38 [ V_8 + 1 ] , L_16 ) ;
} else if ( ! strcmp ( V_38 [ V_8 ] , L_17 ) ) {
F_25 ( V_38 [ V_8 + 1 ] , V_51 |
V_52 |
V_53 ) ;
V_49 = F_23 ( & V_14 -> V_17 , V_38 [ V_8 + 1 ] , L_17 ) ;
} else if ( ! strcmp ( V_38 [ V_8 ] , L_18 ) ) {
char * V_54 = V_38 [ V_8 + 1 ] ;
char * V_55 = strchr ( V_54 , '-' ) ;
if ( V_14 -> V_21 || V_14 -> V_22 ) {
F_19 ( L_19 ) ;
return - V_43 ;
}
if ( V_55 )
* V_55 ++ = '\0' ;
if ( F_21 ( V_54 , & V_14 -> V_21 ) < 0 )
return - V_43 ;
if ( V_55 ) {
if ( F_21 ( V_55 , & V_14 -> V_22 ) < 0 )
return - V_43 ;
if ( V_14 -> V_22 < V_14 -> V_21 ) {
F_19 ( L_20 ,
V_14 -> V_22 ,
V_14 -> V_21 ) ;
return - V_43 ;
}
} else {
V_14 -> V_22 = V_14 -> V_21 ;
}
} else {
F_19 ( L_21 , V_38 [ V_8 ] ) ;
return - V_43 ;
}
if ( V_49 )
return V_49 ;
}
F_5 ( V_14 , L_22 ) ;
return 0 ;
}
static int F_26 ( const char * V_44 , unsigned int * V_56 ,
unsigned int * V_57 )
{
unsigned V_10 = 0 ;
int V_58 = '=' , V_8 ;
switch ( * V_44 ) {
case '+' :
case '-' :
case '=' :
V_58 = * V_44 ++ ;
break;
default:
F_19 ( L_23 , * V_44 , V_44 ) ;
return - V_43 ;
}
F_6 ( L_24 , V_58 ) ;
for (; * V_44 ; ++ V_44 ) {
for ( V_8 = F_4 ( V_9 ) - 1 ; V_8 >= 0 ; V_8 -- ) {
if ( * V_44 == V_9 [ V_8 ] . V_12 ) {
V_10 |= V_9 [ V_8 ] . V_11 ;
break;
}
}
if ( V_8 < 0 ) {
F_19 ( L_25 , * V_44 , V_44 ) ;
return - V_43 ;
}
}
F_6 ( L_26 , V_10 ) ;
switch ( V_58 ) {
case '=' :
* V_57 = 0 ;
* V_56 = V_10 ;
break;
case '+' :
* V_57 = ~ 0U ;
* V_56 = V_10 ;
break;
case '-' :
* V_57 = ~ V_10 ;
* V_56 = 0 ;
break;
}
F_6 ( L_27 , * V_56 , * V_57 ) ;
return 0 ;
}
static int F_27 ( char * V_59 , const char * V_50 )
{
unsigned int V_10 = 0 , V_23 = 0 ;
struct V_13 V_14 ;
#define F_28 9
int V_40 , V_27 ;
char * V_38 [ F_28 ] ;
V_40 = F_17 ( V_59 , V_38 , F_28 ) ;
if ( V_40 <= 0 ) {
F_19 ( L_28 ) ;
return - V_43 ;
}
if ( F_26 ( V_38 [ V_40 - 1 ] , & V_10 , & V_23 ) ) {
F_19 ( L_29 ) ;
return - V_43 ;
}
if ( F_24 ( V_38 , V_40 - 1 , & V_14 , V_50 ) ) {
F_19 ( L_30 ) ;
return - V_43 ;
}
V_27 = F_7 ( & V_14 , V_10 , V_23 ) ;
F_5 ( & V_14 , V_27 ? L_31 : L_32 ) ;
return V_27 ;
}
static int F_29 ( char * V_14 , const char * V_50 )
{
char * V_60 ;
int V_8 , V_61 = 0 , V_62 = 0 , V_49 , V_27 = 0 ;
for ( V_8 = 0 ; V_14 ; V_14 = V_60 ) {
V_60 = strpbrk ( V_14 , L_33 ) ;
if ( V_60 )
* V_60 ++ = '\0' ;
V_14 = F_18 ( V_14 ) ;
if ( ! V_14 || ! * V_14 || * V_14 == '#' )
continue;
F_6 ( L_34 , V_8 , V_14 ) ;
V_49 = F_27 ( V_14 , V_50 ) ;
if ( V_49 < 0 ) {
V_61 ++ ;
V_62 = V_49 ;
} else {
V_27 += V_49 ;
}
V_8 ++ ;
}
F_6 ( L_35 ,
V_8 , V_27 , V_61 ) ;
if ( V_62 )
return V_62 ;
return V_27 ;
}
static int F_30 ( int V_63 )
{
if ( V_64 - V_63 > 0 )
return V_64 - V_63 ;
return 0 ;
}
static char * F_31 ( const struct V_3 * V_65 , char * V_5 )
{
int V_66 ;
int V_67 = 0 ;
* V_5 = '\0' ;
if ( V_65 -> V_10 & V_68 ) {
if ( F_32 () )
V_67 += snprintf ( V_5 + V_67 , F_30 ( V_67 ) , L_36 ) ;
else
V_67 += snprintf ( V_5 + V_67 , F_30 ( V_67 ) , L_37 ,
F_33 ( V_69 ) ) ;
}
V_66 = V_67 ;
if ( V_65 -> V_10 & V_70 )
V_67 += snprintf ( V_5 + V_67 , F_30 ( V_67 ) , L_38 ,
V_65 -> V_50 ) ;
if ( V_65 -> V_10 & V_71 )
V_67 += snprintf ( V_5 + V_67 , F_30 ( V_67 ) , L_38 ,
V_65 -> V_18 ) ;
if ( V_65 -> V_10 & V_72 )
V_67 += snprintf ( V_5 + V_67 , F_30 ( V_67 ) , L_39 ,
V_65 -> V_33 ) ;
if ( V_67 - V_66 )
V_67 += snprintf ( V_5 + V_67 , F_30 ( V_67 ) , L_40 ) ;
if ( V_67 >= V_64 )
V_5 [ V_64 - 1 ] = '\0' ;
return V_5 ;
}
void F_34 ( struct V_3 * V_73 , const char * V_74 , ... )
{
T_2 args ;
struct V_75 V_76 ;
char V_5 [ V_64 ] ;
F_3 ( ! V_73 ) ;
F_3 ( ! V_74 ) ;
va_start ( args , V_74 ) ;
V_76 . V_74 = V_74 ;
V_76 . V_77 = & args ;
F_35 ( V_78 L_41 , F_31 ( V_73 , V_5 ) , & V_76 ) ;
va_end ( args ) ;
}
void F_36 ( struct V_3 * V_73 ,
const struct V_79 * V_80 , const char * V_74 , ... )
{
struct V_75 V_76 ;
T_2 args ;
F_3 ( ! V_73 ) ;
F_3 ( ! V_74 ) ;
va_start ( args , V_74 ) ;
V_76 . V_74 = V_74 ;
V_76 . V_77 = & args ;
if ( ! V_80 ) {
F_35 ( V_78 L_42 , & V_76 ) ;
} else {
char V_5 [ V_64 ] ;
F_37 ( V_81 , V_80 , L_43 ,
F_31 ( V_73 , V_5 ) ,
F_38 ( V_80 ) , F_39 ( V_80 ) ,
& V_76 ) ;
}
va_end ( args ) ;
}
void F_40 ( struct V_3 * V_73 ,
const struct V_82 * V_80 , const char * V_74 , ... )
{
struct V_75 V_76 ;
T_2 args ;
F_3 ( ! V_73 ) ;
F_3 ( ! V_74 ) ;
va_start ( args , V_74 ) ;
V_76 . V_74 = V_74 ;
V_76 . V_77 = & args ;
if ( V_80 && V_80 -> V_80 . V_83 ) {
char V_5 [ V_64 ] ;
F_37 ( V_81 , V_80 -> V_80 . V_83 ,
L_44 ,
F_31 ( V_73 , V_5 ) ,
F_38 ( V_80 -> V_80 . V_83 ) ,
F_39 ( V_80 -> V_80 . V_83 ) ,
F_41 ( V_80 ) , F_42 ( V_80 ) ,
& V_76 ) ;
} else if ( V_80 ) {
F_35 ( V_78 L_45 , F_41 ( V_80 ) ,
F_42 ( V_80 ) , & V_76 ) ;
} else {
F_35 ( V_78 L_46 , & V_76 ) ;
}
va_end ( args ) ;
}
static T_3 int F_43 ( char * V_44 )
{
if ( strlen ( V_44 ) >= V_84 ) {
F_44 ( L_47 ) ;
return 0 ;
}
F_45 ( V_85 , V_44 , V_84 ) ;
return 1 ;
}
static T_4 F_46 ( struct V_86 * V_86 , const char T_5 * V_87 ,
T_1 V_88 , T_6 * V_89 )
{
char * V_90 ;
int V_91 ;
if ( V_88 == 0 )
return 0 ;
if ( V_88 > V_92 - 1 ) {
F_44 ( L_48 , V_92 ) ;
return - V_93 ;
}
V_90 = F_47 ( V_87 , V_88 ) ;
if ( F_48 ( V_90 ) )
return F_49 ( V_90 ) ;
F_6 ( L_49 , ( int ) V_88 ) ;
V_91 = F_29 ( V_90 , NULL ) ;
F_50 ( V_90 ) ;
if ( V_91 < 0 )
return V_91 ;
* V_89 += V_88 ;
return V_88 ;
}
static struct V_3 * F_51 ( struct V_94 * V_95 )
{
if ( F_52 ( & V_96 ) ) {
V_95 -> V_97 = NULL ;
V_95 -> V_98 = 0 ;
return NULL ;
}
V_95 -> V_97 = F_53 ( V_96 . V_99 ,
struct V_24 , V_100 ) ;
V_95 -> V_98 = 0 ;
return & V_95 -> V_97 -> V_32 [ V_95 -> V_98 ] ;
}
static struct V_3 * F_54 ( struct V_94 * V_95 )
{
if ( V_95 -> V_97 == NULL )
return NULL ;
if ( ++ V_95 -> V_98 == V_95 -> V_97 -> V_31 ) {
V_95 -> V_98 = 0 ;
if ( F_55 ( & V_95 -> V_97 -> V_100 , & V_96 ) ) {
V_95 -> V_97 = NULL ;
return NULL ;
}
V_95 -> V_97 = F_53 ( V_95 -> V_97 -> V_100 . V_99 ,
struct V_24 , V_100 ) ;
}
return & V_95 -> V_97 -> V_32 [ V_95 -> V_98 ] ;
}
static void * F_56 ( struct V_101 * V_102 , T_6 * V_67 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
struct V_3 * V_4 ;
int V_104 = * V_67 ;
F_6 ( L_50 , V_102 , ( unsigned long long ) * V_67 ) ;
F_8 ( & V_29 ) ;
if ( ! V_104 )
return V_105 ;
if ( V_104 < 0 )
return NULL ;
V_4 = F_51 ( V_95 ) ;
while ( V_4 != NULL && -- V_104 > 0 )
V_4 = F_54 ( V_95 ) ;
return V_4 ;
}
static void * F_57 ( struct V_101 * V_102 , void * V_7 , T_6 * V_67 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
struct V_3 * V_4 ;
F_6 ( L_51 ,
V_102 , V_7 , ( unsigned long long ) * V_67 ) ;
if ( V_7 == V_105 )
V_4 = F_51 ( V_95 ) ;
else
V_4 = F_54 ( V_95 ) ;
++ * V_67 ;
return V_4 ;
}
static int F_58 ( struct V_101 * V_102 , void * V_7 )
{
struct V_94 * V_95 = V_102 -> V_103 ;
struct V_3 * V_4 = V_7 ;
char V_106 [ 10 ] ;
F_6 ( L_52 , V_102 , V_7 ) ;
if ( V_7 == V_105 ) {
F_59 ( V_102 ,
L_53 ) ;
return 0 ;
}
F_60 ( V_102 , L_54 ,
F_1 ( V_4 -> V_19 ) , V_4 -> V_33 ,
V_95 -> V_97 -> V_30 , V_4 -> V_18 ,
F_2 ( V_4 , V_106 , sizeof( V_106 ) ) ) ;
F_61 ( V_102 , V_4 -> V_17 , L_55 ) ;
F_59 ( V_102 , L_56 ) ;
return 0 ;
}
static void F_62 ( struct V_101 * V_102 , void * V_7 )
{
F_6 ( L_52 , V_102 , V_7 ) ;
F_15 ( & V_29 ) ;
}
static int F_63 ( struct V_107 * V_107 , struct V_86 * V_86 )
{
F_6 ( L_57 ) ;
return F_64 ( V_86 , & V_108 ,
sizeof( struct V_94 ) ) ;
}
int F_65 ( struct V_3 * V_109 , unsigned int V_104 ,
const char * V_48 )
{
struct V_24 * V_25 ;
const char * V_110 ;
V_25 = F_66 ( sizeof( * V_25 ) , V_111 ) ;
if ( V_25 == NULL )
return - V_112 ;
V_110 = F_67 ( V_48 , V_111 ) ;
if ( V_110 == NULL ) {
F_50 ( V_25 ) ;
return - V_112 ;
}
V_25 -> V_30 = V_110 ;
V_25 -> V_31 = V_104 ;
V_25 -> V_32 = V_109 ;
F_8 ( & V_29 ) ;
F_68 ( & V_25 -> V_100 , & V_96 ) ;
F_15 ( & V_29 ) ;
F_6 ( L_58 , V_104 , V_25 -> V_30 ) ;
return 0 ;
}
static int F_69 ( char * V_113 , char * V_45 ,
const char * V_50 , int V_114 )
{
char * V_115 ;
V_115 = strchr ( V_113 , '.' ) ;
if ( V_115 ) {
* V_115 = '\0' ;
V_50 = V_113 ;
V_113 = V_115 + 1 ;
}
if ( strcmp ( V_113 , L_59 ) )
return V_114 ;
F_29 ( ( V_45 ? V_45 : L_60 ) , V_50 ) ;
return 0 ;
}
static int F_70 ( char * V_113 , char * V_45 ,
const char * V_116 , void * V_117 )
{
F_6 ( L_61 , V_113 , V_45 ) ;
return F_69 ( V_113 , V_45 , NULL , 0 ) ;
}
int F_71 ( char * V_113 , char * V_45 , const char * V_20 )
{
F_6 ( L_62 , V_20 , V_113 , V_45 ) ;
return F_69 ( V_113 , V_45 , V_20 , - V_118 ) ;
}
static void F_72 ( struct V_24 * V_25 )
{
F_73 ( & V_25 -> V_100 ) ;
F_74 ( V_25 -> V_30 ) ;
F_50 ( V_25 ) ;
}
int F_75 ( const char * V_30 )
{
struct V_24 * V_25 , * V_119 ;
int V_91 = - V_118 ;
F_6 ( L_63 , V_30 ) ;
F_8 ( & V_29 ) ;
F_76 (dt, nextdt, &ddebug_tables, link) {
if ( ! strcmp ( V_25 -> V_30 , V_30 ) ) {
F_72 ( V_25 ) ;
V_91 = 0 ;
}
}
F_15 ( & V_29 ) ;
return V_91 ;
}
static void F_77 ( void )
{
F_8 ( & V_29 ) ;
while ( ! F_52 ( & V_96 ) ) {
struct V_24 * V_25 = F_53 ( V_96 . V_99 ,
struct V_24 ,
V_100 ) ;
F_72 ( V_25 ) ;
}
F_15 ( & V_29 ) ;
}
static int T_3 F_78 ( void )
{
struct V_120 * V_121 , * V_86 ;
if ( ! V_122 )
return - V_123 ;
V_121 = F_79 ( L_64 , NULL ) ;
if ( ! V_121 )
return - V_112 ;
V_86 = F_80 ( L_65 , 0644 , V_121 , NULL ,
& V_124 ) ;
if ( ! V_86 ) {
F_81 ( V_121 ) ;
return - V_112 ;
}
return 0 ;
}
static int T_3 F_82 ( void )
{
struct V_3 * V_95 , * V_125 ;
const char * V_50 = NULL ;
char * V_126 ;
int V_91 = 0 ;
int V_104 = 0 , V_127 = 0 , V_128 = 0 ;
int V_129 = 0 ;
if ( V_130 == V_131 ) {
F_44 ( L_66 ) ;
return 1 ;
}
V_95 = V_130 ;
V_50 = V_95 -> V_50 ;
V_125 = V_95 ;
for (; V_95 < V_131 ; V_95 ++ ) {
V_127 ++ ;
V_129 += strlen ( V_95 -> V_50 ) + strlen ( V_95 -> V_18 )
+ strlen ( V_95 -> V_19 ) + strlen ( V_95 -> V_17 ) ;
if ( strcmp ( V_50 , V_95 -> V_50 ) ) {
V_128 ++ ;
V_91 = F_65 ( V_125 , V_104 , V_50 ) ;
if ( V_91 )
goto V_132;
V_104 = 0 ;
V_50 = V_95 -> V_50 ;
V_125 = V_95 ;
}
V_104 ++ ;
}
V_91 = F_65 ( V_125 , V_104 , V_50 ) ;
if ( V_91 )
goto V_132;
V_122 = 1 ;
F_6 ( L_67 ,
V_128 , V_127 , ( int ) ( V_128 * sizeof( struct V_24 ) ) ,
V_129 + ( int ) ( V_131 - V_130 ) ) ;
if ( V_85 [ 0 ] != '\0' ) {
F_44 ( L_68 ) ;
V_91 = F_29 ( V_85 , NULL ) ;
if ( V_91 < 0 )
F_44 ( L_69 ,
V_85 ) ;
else
F_16 ( L_70 , V_91 ) ;
}
V_126 = F_83 ( V_133 , V_111 ) ;
F_84 ( L_71 , V_126 , NULL ,
0 , 0 , 0 , NULL , & F_70 ) ;
F_50 ( V_126 ) ;
return 0 ;
V_132:
F_77 () ;
return 0 ;
}
