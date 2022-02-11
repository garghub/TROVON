int F_1 ( char * V_1 , T_1 V_2 , const char * V_3 , ... )
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
int F_2 ( bool V_7 )
{
int V_4 ;
V_8 . V_9 = true ;
V_8 . V_10 = true ;
V_4 = F_3 ( NULL ) ;
if ( V_4 < 0 ) {
F_4 ( L_1 ) ;
goto V_11;
}
if ( V_12 || V_7 )
return 0 ;
if ( V_8 . V_13 )
F_4 ( L_2 , V_8 . V_13 ) ;
V_12 = F_5 () ;
if ( ! V_12 ) {
F_4 ( L_3 ) ;
F_6 () ;
V_4 = - 1 ;
}
V_11:
if ( V_4 < 0 )
F_7 ( L_4 ) ;
return V_4 ;
}
void F_8 ( void )
{
if ( V_12 ) {
F_9 ( V_12 ) ;
V_12 = NULL ;
}
F_6 () ;
}
static struct V_14 * F_10 ( const char * V_15 ,
struct V_16 * * V_17 )
{
return F_11 ( V_12 , V_15 , V_17 ,
NULL ) ;
}
static struct V_14 * F_12 ( T_3 V_18 , struct V_16 * * V_17 )
{
return F_13 ( V_12 , V_18 , V_17 , NULL ) ;
}
static struct V_19 * F_14 ( void )
{
struct V_20 * V_20 ;
struct V_16 * V_16 = F_15 ( V_12 ) ;
if ( F_16 ( V_16 , NULL ) < 0 )
return NULL ;
V_20 = F_17 ( V_16 ) ;
if ( ! V_20 )
return NULL ;
return V_20 -> V_19 ;
}
static int F_18 ( const char * V_15 , T_3 * V_18 ,
bool V_21 , bool V_22 )
{
struct V_19 * V_23 ;
struct V_14 * V_24 ;
struct V_16 * V_16 ;
V_23 = F_14 () ;
if ( V_23 && strcmp ( V_15 , V_23 -> V_15 ) == 0 )
* V_18 = ( V_21 ) ? V_23 -> V_18 : V_23 -> V_25 ;
else {
V_24 = F_10 ( V_15 , & V_16 ) ;
if ( ! V_24 )
return - V_26 ;
* V_18 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) -
( ( V_21 ) ? 0 : V_16 -> V_21 ) -
( ( V_22 ) ? V_16 -> V_28 : 0 ) ;
}
return 0 ;
}
static struct V_16 * F_19 ( const char * V_29 )
{
struct V_30 * V_31 = & V_12 -> V_32 ;
struct V_33 * V_33 = & V_31 -> V_33 [ V_34 ] ;
struct V_16 * V_35 ;
if ( V_29 && strchr ( V_29 , '/' ) )
return F_20 ( V_12 , 0 , V_29 ) ;
if ( ! V_29 )
V_29 = L_5 ;
for ( V_35 = F_21 ( V_33 ) ; V_35 ; V_35 = F_22 ( V_35 ) ) {
if ( strncmp ( V_35 -> V_36 -> V_37 + 1 , V_29 ,
V_35 -> V_36 -> V_38 - 2 ) == 0 ) {
return V_35 ;
}
}
return NULL ;
}
static struct V_16 * F_23 ( const char * V_39 , bool V_40 )
{
if ( V_40 )
return F_24 ( V_39 ) ;
else
return F_19 ( V_39 ) ;
}
static void F_25 ( struct V_16 * V_16 , bool V_40 )
{
if ( V_16 && V_40 ) {
F_26 ( V_16 ) ;
}
}
static int F_27 ( const char * V_41 , char * * V_42 )
{
char * V_43 , * V_44 , * V_45 ;
char V_46 [ 64 ] ;
int V_4 ;
V_45 = F_28 ( V_41 ) ;
if ( ! V_45 )
return - V_47 ;
V_43 = F_29 ( V_45 ) ;
if ( ! V_43 ) {
V_4 = - V_48 ;
goto V_11;
}
V_44 = strpbrk ( V_43 , L_6 ) ;
if ( V_44 )
* V_44 = '\0' ;
V_4 = F_1 ( V_46 , 64 , L_7 , V_49 , V_43 ) ;
if ( V_4 < 0 )
goto V_11;
* V_42 = F_28 ( V_46 ) ;
V_4 = * V_42 ? 0 : - V_47 ;
V_11:
free ( V_45 ) ;
return V_4 ;
}
static void F_30 ( struct V_50 * V_51 )
{
free ( V_51 -> V_52 ) ;
free ( V_51 -> V_53 ) ;
free ( V_51 -> V_54 ) ;
}
static void F_31 ( struct V_55 * V_56 , int V_57 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ )
F_32 ( V_56 + V_58 ) ;
}
static bool F_33 ( const char * V_14 , unsigned long V_59 )
{
T_3 V_60 = 0 ;
int V_4 ;
V_4 = F_18 ( L_8 , & V_60 ,
false , false ) ;
if ( V_4 == 0 && V_60 < V_59 )
F_7 ( L_9 , V_14 ) ;
else if ( F_34 ( V_59 ) )
F_7 ( L_10 , V_14 ) ;
else
return false ;
return true ;
}
static char * F_35 ( const char * V_29 )
{
int V_61 ;
T_4 * V_62 ;
T_5 V_63 ;
T_6 V_64 ;
T_7 * V_65 ;
T_8 * V_66 ;
char * V_67 = NULL ;
V_61 = F_36 ( V_29 , V_68 ) ;
if ( V_61 < 0 )
return NULL ;
V_62 = F_37 ( V_61 , V_69 , NULL ) ;
if ( V_62 == NULL )
goto V_70;
if ( F_38 ( V_62 , & V_63 ) == NULL )
goto V_71;
V_66 = F_39 ( V_62 , & V_63 , & V_64 ,
L_11 , NULL ) ;
if ( ! V_66 )
goto V_71;
V_65 = F_40 ( V_66 , NULL ) ;
if ( ! V_65 || ! V_65 -> V_72 )
goto V_71;
V_67 = F_28 ( ( char * ) V_65 -> V_72 + V_73 ) ;
V_71:
F_41 ( V_62 ) ;
V_70:
F_42 ( V_61 ) ;
return V_67 ;
}
static int F_43 ( const char * V_29 , struct V_36 * * V_74 )
{
struct V_36 * V_36 ;
struct V_16 * V_16 ;
const char * V_13 ;
int V_4 = 0 ;
if ( V_29 ) {
char V_75 [ 128 ] ;
snprintf ( V_75 , sizeof( V_75 ) , L_12 , V_29 ) ;
V_16 = F_44 ( & V_12 -> V_32 , V_34 , V_75 ) ;
if ( V_16 ) {
V_36 = V_16 -> V_36 ;
goto V_76;
}
F_4 ( L_13 , V_29 ) ;
return - V_26 ;
}
V_16 = F_15 ( V_12 ) ;
V_36 = V_16 -> V_36 ;
V_13 = V_8 . V_13 ;
V_36 -> V_77 = 0 ;
if ( V_13 )
V_4 = F_45 ( V_36 , V_16 , V_13 , false , NULL ) ;
else
V_4 = F_46 ( V_36 , V_16 , NULL ) ;
V_76:
* V_74 = V_36 ;
return V_4 ;
}
static int F_47 ( struct V_78 * V_79 ,
struct V_50 * V_51 ,
struct V_50 * V_42 ,
const char * V_39 , bool V_80 )
{
struct V_16 * V_16 = NULL ;
struct V_14 * V_24 ;
T_3 V_59 = 0 ;
int V_4 = - V_26 ;
if ( ! V_51 -> V_53 || V_51 -> V_52 )
return - V_81 ;
V_16 = F_23 ( V_39 , V_80 ) ;
if ( ! V_16 )
return - V_48 ;
F_48 (map, pp->function, sym) {
if ( V_80 )
V_59 = V_24 -> V_28 ;
else
V_59 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) ;
break;
}
if ( ! V_59 ) {
V_4 = - V_26 ;
goto V_11;
}
F_4 ( L_14 V_82 L_15 ,
V_51 -> V_53 , V_59 ) ;
V_4 = F_49 ( V_79 , ( unsigned long ) V_59 ,
V_42 ) ;
if ( V_4 <= 0 )
V_4 = ( ! V_4 ) ? - V_26 : V_4 ;
else {
V_42 -> V_83 += V_51 -> V_83 ;
V_42 -> line += V_51 -> line ;
V_42 -> V_84 = V_51 -> V_84 ;
V_4 = 0 ;
}
V_11:
F_25 ( V_16 , V_80 ) ;
return V_4 ;
}
static int F_50 ( struct V_78 * V_79 ,
struct V_85 * V_86 ,
struct V_50 * V_87 )
{
int V_4 ;
memcpy ( V_87 , & V_86 -> V_88 , sizeof( * V_87 ) ) ;
memset ( & V_86 -> V_88 , 0 , sizeof( V_86 -> V_88 ) ) ;
V_4 = F_47 ( V_79 , V_87 , & V_86 -> V_88 ,
V_86 -> V_39 , V_86 -> V_80 ) ;
if ( V_4 < 0 )
memcpy ( & V_86 -> V_88 , V_87 , sizeof( * V_87 ) ) ;
return V_4 ;
}
static int F_51 ( struct V_78 * V_79 ,
struct V_89 * V_90 ,
const char * V_39 , bool V_40 )
{
struct V_50 V_51 = { . V_53 = V_90 -> V_53 ,
. V_52 = V_90 -> V_52 ,
. line = V_90 -> V_28 } ;
struct V_50 V_42 ;
int V_4 , V_91 = 0 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
if ( V_90 -> V_92 != V_93 )
V_91 = V_90 -> V_92 - V_90 -> V_28 ;
V_4 = F_47 ( V_79 , & V_51 , & V_42 ,
V_39 , V_40 ) ;
if ( ! V_4 ) {
V_90 -> V_53 = V_42 . V_53 ;
V_90 -> V_52 = V_42 . V_52 ;
V_90 -> V_28 = V_42 . line ;
if ( V_90 -> V_92 != V_93 )
V_90 -> V_92 = V_90 -> V_28 + V_91 ;
F_30 ( & V_51 ) ;
}
return V_4 ;
}
static struct V_78 * F_52 ( const char * V_29 , bool V_94 )
{
const char * V_95 = V_29 ;
char V_96 [ V_97 ] ;
struct V_78 * V_4 = NULL ;
struct V_36 * V_36 = NULL ;
int V_98 ;
if ( ! V_29 || ! strchr ( V_29 , '/' ) ) {
V_98 = F_43 ( V_29 , & V_36 ) ;
if ( V_98 < 0 ) {
if ( ! V_36 || V_36 -> V_77 == 0 ) {
if ( ! F_53 ( - V_98 , V_96 , V_97 ) )
strcpy ( V_96 , L_16 ) ;
} else
F_54 ( V_36 , V_96 , V_97 ) ;
if ( ! V_94 )
F_55 ( L_17 ,
V_29 ? : L_5 , V_96 ) ;
return NULL ;
}
V_95 = V_36 -> V_99 ;
}
V_4 = F_56 ( V_95 ) ;
if ( ! V_4 && ! V_94 ) {
F_7 ( L_18 , V_95 ) ;
if ( ! V_29 || ! F_57 ( V_95 , L_19 ) )
F_7 ( L_20 ) ;
else
F_7 ( L_21 ) ;
F_7 ( L_22 ) ;
}
return V_4 ;
}
static struct V_78 * F_58 ( const char * V_29 , bool V_94 )
{
const char * V_95 = V_29 ;
if ( ! V_29 )
V_95 = L_5 ;
if ( V_100 && ! strcmp ( V_100 , V_95 ) )
goto V_11;
free ( V_100 ) ;
V_100 = F_28 ( V_95 ) ;
if ( ! V_100 ) {
F_59 ( V_101 ) ;
V_101 = NULL ;
goto V_11;
}
V_101 = F_52 ( V_29 , V_94 ) ;
if ( ! V_101 )
F_60 ( & V_100 ) ;
V_11:
return V_101 ;
}
static void F_61 ( void )
{
F_59 ( V_101 ) ;
V_101 = NULL ;
F_60 ( & V_100 ) ;
}
static int F_62 ( const char * V_41 , unsigned long * V_59 )
{
T_4 * V_62 ;
T_5 V_63 ;
T_6 V_64 ;
int V_61 , V_4 = - V_26 ;
V_61 = F_36 ( V_41 , V_68 ) ;
if ( V_61 < 0 )
return - V_102 ;
V_62 = F_37 ( V_61 , V_69 , NULL ) ;
if ( V_62 == NULL ) {
V_4 = - V_48 ;
goto V_103;
}
if ( F_38 ( V_62 , & V_63 ) == NULL )
goto V_11;
if ( ! F_39 ( V_62 , & V_63 , & V_64 , L_23 , NULL ) )
goto V_11;
* V_59 = V_64 . V_104 - V_64 . V_105 ;
V_4 = 0 ;
V_11:
F_41 ( V_62 ) ;
V_103:
F_42 ( V_61 ) ;
return V_4 ;
}
static int F_63 ( struct V_106 * V_107 ,
struct V_50 * V_51 ,
bool V_108 )
{
struct V_78 * V_79 = NULL ;
unsigned long V_109 = 0 ;
T_3 V_18 = V_107 -> V_59 ;
int V_4 = - V_26 ;
if ( ! V_108 ) {
if ( ! V_18 ) {
V_4 = - V_48 ;
goto error;
}
V_4 = F_62 ( V_107 -> V_29 , & V_109 ) ;
if ( V_4 < 0 )
goto error;
V_18 += V_109 ;
} else if ( V_107 -> V_14 ) {
V_4 = F_18 ( V_107 -> V_14 , & V_18 ,
false , ! ! V_107 -> V_29 ) ;
if ( V_4 != 0 )
goto error;
V_18 += V_107 -> V_83 ;
}
F_4 ( L_24 V_82 L_25 , V_18 ,
V_107 -> V_29 ? : L_5 ) ;
V_79 = F_58 ( V_107 -> V_29 , V_110 == 0 ) ;
if ( V_79 )
V_4 = F_49 ( V_79 ,
( unsigned long ) V_18 , V_51 ) ;
else
V_4 = - V_26 ;
if ( V_4 > 0 ) {
V_51 -> V_84 = V_107 -> V_84 ;
return 0 ;
}
error:
F_4 ( L_26 ) ;
return V_4 ? : - V_26 ;
}
static int F_64 ( struct V_55 * V_56 ,
int V_57 , const char * V_41 )
{
int V_58 , V_4 = 0 ;
unsigned long V_109 = 0 ;
if ( ! V_41 )
return 0 ;
V_4 = F_62 ( V_41 , & V_109 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_58 = 0 ; V_58 < V_57 && V_4 >= 0 ; V_58 ++ ) {
V_56 [ V_58 ] . V_88 . V_59 -= V_109 ;
V_56 [ V_58 ] . V_88 . V_29 = F_28 ( V_41 ) ;
if ( ! V_56 [ V_58 ] . V_88 . V_29 ) {
V_4 = - V_47 ;
break;
}
V_56 [ V_58 ] . V_80 = true ;
}
return V_4 ;
}
static int F_65 ( struct V_55 * V_56 ,
int V_57 , const char * V_29 )
{
int V_58 , V_4 = 0 ;
char * V_67 = NULL ;
if ( ! V_29 )
return 0 ;
V_67 = F_35 ( V_29 ) ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_56 [ V_58 ] . V_88 . V_29 =
F_28 ( V_67 ? V_67 : V_29 ) ;
if ( ! V_56 [ V_58 ] . V_88 . V_29 ) {
V_4 = - V_47 ;
break;
}
}
free ( V_67 ) ;
return V_4 ;
}
static int F_66 ( struct V_55 * V_56 ,
int V_57 , const char * V_29 ,
bool V_111 )
{
struct V_19 * V_23 ;
char * V_87 ;
int V_58 , V_112 = 0 ;
if ( V_111 )
return F_64 ( V_56 , V_57 , V_29 ) ;
if ( V_29 )
return F_65 ( V_56 , V_57 , V_29 ) ;
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_27 ) ;
return - V_48 ;
}
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
if ( ! V_56 [ V_58 ] . V_88 . V_59 || V_56 [ V_58 ] . V_88 . V_84 )
continue;
if ( F_33 ( V_56 [ V_58 ] . V_88 . V_14 ,
V_56 [ V_58 ] . V_88 . V_59 ) ) {
V_87 = NULL ;
V_112 ++ ;
} else {
V_87 = F_28 ( V_23 -> V_15 ) ;
if ( ! V_87 )
return - V_47 ;
}
if ( ! V_56 [ V_58 ] . V_88 . V_113 )
V_56 [ V_58 ] . V_88 . V_113 = V_56 [ V_58 ] . V_88 . V_14 ;
else
free ( V_56 [ V_58 ] . V_88 . V_14 ) ;
V_56 [ V_58 ] . V_88 . V_14 = V_87 ;
V_56 [ V_58 ] . V_88 . V_83 = V_56 [ V_58 ] . V_88 . V_59 -
V_23 -> V_25 ;
}
return V_112 ;
}
static int F_67 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
bool V_114 = F_68 ( V_86 ) ;
struct V_50 V_87 ;
struct V_78 * V_79 ;
int V_57 , V_4 = 0 ;
V_79 = F_52 ( V_86 -> V_39 , ! V_114 ) ;
if ( ! V_79 ) {
if ( V_114 )
return - V_26 ;
F_4 ( L_28 ) ;
return 0 ;
}
F_4 ( L_29 ) ;
V_57 = F_69 ( V_79 , V_86 , V_56 ) ;
if ( V_57 == 0 ) {
V_4 = F_50 ( V_79 , V_86 , & V_87 ) ;
if ( ! V_4 ) {
V_57 = F_69 ( V_79 , V_86 , V_56 ) ;
F_30 ( & V_86 -> V_88 ) ;
memcpy ( & V_86 -> V_88 , & V_87 , sizeof( V_87 ) ) ;
}
}
F_59 ( V_79 ) ;
if ( V_57 > 0 ) {
F_4 ( L_30 , V_57 ) ;
V_4 = F_66 ( * V_56 , V_57 ,
V_86 -> V_39 , V_86 -> V_80 ) ;
if ( V_4 < 0 || V_4 == V_57 ) {
F_31 ( * V_56 , V_57 ) ;
F_60 ( V_56 ) ;
}
if ( V_4 != V_57 )
return V_4 < 0 ? V_4 : V_57 ;
V_57 = 0 ;
}
if ( V_57 == 0 ) {
F_7 ( L_31 ,
F_70 ( & V_86 -> V_88 ) ) ;
return - V_26 ;
}
F_4 ( L_32 , V_57 ) ;
if ( V_57 < 0 ) {
if ( V_57 == - V_115 )
F_7 ( L_33
L_34 ) ;
if ( ! V_114 ) {
F_4 ( L_35 ) ;
return 0 ;
}
}
return V_57 ;
}
static int F_71 ( T_9 * V_116 , int V_117 , bool V_118 , bool V_119 )
{
char V_46 [ V_120 ] , V_121 [ V_97 ] ;
const char * V_122 = V_119 ? L_36 : V_123 ;
const char * V_124 = NULL ;
do {
if ( fgets ( V_46 , V_120 , V_116 ) == NULL )
goto error;
if ( V_118 )
continue;
if ( ! V_124 ) {
V_124 = V_119 ? L_37 : L_38 ;
F_72 ( stdout , V_122 , V_124 , V_117 ) ;
}
F_72 ( stdout , V_122 , L_39 , V_46 ) ;
} while ( strchr ( V_46 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_116 ) ) {
F_7 ( L_40 ,
F_53 ( V_102 , V_121 , sizeof( V_121 ) ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_73 ( T_9 * V_116 , int V_117 , bool V_118 , bool V_119 )
{
int V_125 = F_71 ( V_116 , V_117 , V_118 , V_119 ) ;
if ( V_125 == 0 ) {
F_7 ( L_41 ) ;
V_125 = - 1 ;
}
return V_125 ;
}
static int F_74 ( struct V_89 * V_90 , const char * V_29 ,
bool V_40 )
{
int V_117 = 1 ;
struct V_126 * V_127 ;
struct V_78 * V_79 ;
T_9 * V_116 ;
int V_4 ;
char * V_87 ;
char V_121 [ V_97 ] ;
V_79 = F_52 ( V_29 , false ) ;
if ( ! V_79 )
return - V_26 ;
V_4 = F_75 ( V_79 , V_90 ) ;
if ( ! V_4 ) {
V_4 = F_51 ( V_79 , V_90 , V_29 , V_40 ) ;
if ( ! V_4 )
V_4 = F_75 ( V_79 , V_90 ) ;
}
F_59 ( V_79 ) ;
if ( V_4 == 0 || V_4 == - V_26 ) {
F_7 ( L_42 ) ;
return - V_26 ;
} else if ( V_4 < 0 ) {
F_7 ( L_43 ) ;
return V_4 ;
}
V_87 = V_90 -> V_95 ;
V_4 = F_76 ( V_87 , V_90 -> V_128 , & V_90 -> V_95 ) ;
if ( V_87 != V_90 -> V_95 )
free ( V_87 ) ;
if ( V_4 < 0 ) {
F_7 ( L_44 ) ;
return V_4 ;
}
F_77 () ;
if ( V_90 -> V_53 )
fprintf ( stdout , L_45 , V_90 -> V_53 , V_90 -> V_95 ,
V_90 -> V_28 - V_90 -> V_83 ) ;
else
fprintf ( stdout , L_46 , V_90 -> V_95 , V_90 -> V_28 ) ;
V_116 = fopen ( V_90 -> V_95 , L_47 ) ;
if ( V_116 == NULL ) {
F_7 ( L_48 , V_90 -> V_95 ,
F_53 ( V_102 , V_121 , sizeof( V_121 ) ) ) ;
return - V_102 ;
}
while ( V_117 < V_90 -> V_28 ) {
V_4 = F_78 ( V_116 , V_117 ++ ) ;
if ( V_4 < 0 )
goto V_92;
}
F_79 (ln, lr->line_list) {
for (; V_127 -> V_58 > V_117 ; V_117 ++ ) {
V_4 = F_80 ( V_116 , V_117 - V_90 -> V_83 ) ;
if ( V_4 < 0 )
goto V_92;
}
V_4 = F_81 ( V_116 , V_117 ++ - V_90 -> V_83 ) ;
if ( V_4 < 0 )
goto V_92;
}
if ( V_90 -> V_92 == V_93 )
V_90 -> V_92 = V_117 + V_129 ;
while ( V_117 <= V_90 -> V_92 ) {
V_4 = F_82 ( V_116 , V_117 ++ - V_90 -> V_83 ) ;
if ( V_4 <= 0 )
break;
}
V_92:
fclose ( V_116 ) ;
return V_4 ;
}
int F_83 ( struct V_89 * V_90 , const char * V_29 , bool V_40 )
{
int V_4 ;
V_4 = F_2 ( V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_74 ( V_90 , V_29 , V_40 ) ;
F_8 () ;
return V_4 ;
}
static int F_84 ( struct V_78 * V_79 ,
struct V_85 * V_86 ,
struct V_130 * V_131 )
{
char * V_46 ;
int V_4 , V_58 , V_132 ;
struct V_133 * V_134 ;
struct V_135 * V_136 = NULL , * V_137 ;
struct V_50 V_87 ;
const char * V_138 ;
V_46 = F_70 ( & V_86 -> V_88 ) ;
if ( ! V_46 )
return - V_48 ;
F_4 ( L_49 , V_46 ) ;
V_4 = F_85 ( V_79 , V_86 , & V_136 ) ;
if ( ! V_4 ) {
V_4 = F_50 ( V_79 , V_86 , & V_87 ) ;
if ( ! V_4 ) {
V_4 = F_85 ( V_79 , V_86 ,
& V_136 ) ;
F_30 ( & V_87 ) ;
}
}
if ( V_4 <= 0 ) {
if ( V_4 == 0 || V_4 == - V_26 ) {
F_55 ( L_50 , V_46 ) ;
V_4 = - V_26 ;
} else
F_7 ( L_43 ) ;
goto V_92;
}
fprintf ( stdout , L_51 , V_46 ) ;
for ( V_58 = 0 ; V_58 < V_4 ; V_58 ++ ) {
V_137 = & V_136 [ V_58 ] ;
fprintf ( stdout , L_52 , V_137 -> V_88 . V_14 ,
V_137 -> V_88 . V_83 ) ;
F_60 ( & V_137 -> V_88 . V_14 ) ;
V_132 = 0 ;
if ( V_137 -> V_139 ) {
F_86 (node, vl->vars) {
V_138 = strchr ( V_134 -> V_140 , '\t' ) + 1 ;
if ( F_87 ( V_131 , V_138 ) ) {
fprintf ( stdout , L_53 , V_134 -> V_140 ) ;
V_132 ++ ;
}
}
F_88 ( V_137 -> V_139 ) ;
}
if ( V_132 == 0 )
fprintf ( stdout , L_54 ) ;
}
free ( V_136 ) ;
V_92:
free ( V_46 ) ;
return V_4 ;
}
int F_89 ( struct V_85 * V_141 , int V_142 ,
struct V_130 * V_131 )
{
int V_58 , V_4 = 0 ;
struct V_78 * V_79 ;
V_4 = F_2 ( V_141 -> V_80 ) ;
if ( V_4 < 0 )
return V_4 ;
V_79 = F_52 ( V_141 -> V_39 , false ) ;
if ( ! V_79 ) {
V_4 = - V_26 ;
goto V_11;
}
F_77 () ;
for ( V_58 = 0 ; V_58 < V_142 && V_4 >= 0 ; V_58 ++ )
V_4 = F_84 ( V_79 , & V_141 [ V_58 ] , V_131 ) ;
F_59 ( V_79 ) ;
V_11:
F_8 () ;
return V_4 ;
}
static void F_61 ( void )
{
}
static int
F_63 ( struct V_106 * V_107 V_143 ,
struct V_50 * V_51 V_143 ,
bool V_108 V_143 )
{
return - V_144 ;
}
static int F_67 ( struct V_85 * V_86 ,
struct V_55 * * V_56 V_143 )
{
if ( F_68 ( V_86 ) ) {
F_7 ( L_55 ) ;
return - V_144 ;
}
return 0 ;
}
int F_83 ( struct V_89 * V_90 V_143 ,
const char * V_29 V_143 ,
bool V_40 V_143 )
{
F_7 ( L_55 ) ;
return - V_144 ;
}
int F_89 ( struct V_85 * V_141 V_143 ,
int V_142 V_143 ,
struct V_130 * T_10 V_143 )
{
F_7 ( L_55 ) ;
return - V_144 ;
}
void F_90 ( struct V_89 * V_90 )
{
free ( V_90 -> V_53 ) ;
free ( V_90 -> V_52 ) ;
free ( V_90 -> V_95 ) ;
free ( V_90 -> V_128 ) ;
F_91 ( V_90 -> V_145 ) ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
}
int F_92 ( struct V_89 * V_90 )
{
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_90 -> V_145 = F_93 ( NULL ) ;
if ( ! V_90 -> V_145 )
return - V_47 ;
else
return 0 ;
}
static int F_94 ( char * * V_146 , int * V_147 , const char * V_148 )
{
const char * V_28 = * V_146 ;
V_102 = 0 ;
* V_147 = strtol ( * V_146 , V_146 , 0 ) ;
if ( V_102 || * V_146 == V_28 ) {
F_95 ( L_56 , V_148 ) ;
return - V_48 ;
}
return 0 ;
}
static bool F_96 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
int F_97 ( const char * V_149 , struct V_89 * V_90 )
{
char * V_150 , * V_52 , * V_15 = F_28 ( V_149 ) ;
int V_98 ;
if ( ! V_15 )
return - V_47 ;
V_90 -> V_28 = 0 ;
V_90 -> V_92 = V_93 ;
V_150 = strchr ( V_15 , ':' ) ;
if ( V_150 ) {
* V_150 ++ = '\0' ;
V_98 = F_94 ( & V_150 , & V_90 -> V_28 , L_57 ) ;
if ( V_98 )
goto V_98;
if ( * V_150 == '+' || * V_150 == '-' ) {
const char V_151 = * V_150 ++ ;
V_98 = F_94 ( & V_150 , & V_90 -> V_92 , L_58 ) ;
if ( V_98 )
goto V_98;
if ( V_151 == '+' ) {
V_90 -> V_92 += V_90 -> V_28 ;
V_90 -> V_92 -- ;
}
}
F_4 ( L_59 , V_90 -> V_28 , V_90 -> V_92 ) ;
V_98 = - V_48 ;
if ( V_90 -> V_28 > V_90 -> V_92 ) {
F_95 ( L_60
L_61 ) ;
goto V_98;
}
if ( * V_150 != '\0' ) {
F_95 ( L_62 , V_150 ) ;
goto V_98;
}
}
V_52 = strchr ( V_15 , '@' ) ;
if ( V_52 ) {
* V_52 = '\0' ;
V_90 -> V_52 = F_28 ( ++ V_52 ) ;
if ( V_90 -> V_52 == NULL ) {
V_98 = - V_47 ;
goto V_98;
}
V_90 -> V_53 = V_15 ;
} else if ( strchr ( V_15 , '/' ) || strchr ( V_15 , '.' ) )
V_90 -> V_52 = V_15 ;
else if ( F_96 ( V_15 ) )
V_90 -> V_53 = V_15 ;
else {
F_95 ( L_63 , V_15 ) ;
V_98 = - V_48 ;
goto V_98;
}
return 0 ;
V_98:
free ( V_15 ) ;
return V_98 ;
}
static int F_98 ( char * V_149 , struct V_85 * V_86 )
{
struct V_50 * V_51 = & V_86 -> V_88 ;
char * V_146 , * V_87 ;
char V_151 , V_152 = 0 ;
bool V_153 = false ;
if ( ! V_149 )
return - V_48 ;
V_146 = strpbrk ( V_149 , L_64 ) ;
if ( V_146 && * V_146 == '=' ) {
* V_146 = '\0' ;
V_87 = V_146 + 1 ;
if ( strchr ( V_149 , ':' ) ) {
F_95 ( L_65 ) ;
return - V_81 ;
}
if ( ! F_96 ( V_149 ) ) {
F_95 ( L_66
L_67 , V_149 ) ;
return - V_48 ;
}
V_86 -> V_154 = F_28 ( V_149 ) ;
if ( V_86 -> V_154 == NULL )
return - V_47 ;
V_86 -> V_155 = NULL ;
V_149 = V_87 ;
}
if ( ! strpbrk ( V_149 , L_68 ) && ( V_146 = strpbrk ( V_149 , L_69 ) ) != NULL ) {
if ( memchr ( V_149 , '.' , V_146 - V_149 ) )
V_153 = true ;
}
V_146 = strpbrk ( V_149 , L_70 ) ;
if ( V_146 ) {
V_152 = * V_146 ;
* V_146 ++ = '\0' ;
}
if ( V_149 [ 0 ] == '\0' )
V_87 = NULL ;
else {
V_87 = F_28 ( V_149 ) ;
if ( V_87 == NULL )
return - V_47 ;
}
if ( V_153 )
V_51 -> V_52 = V_87 ;
else {
V_51 -> V_53 = V_87 ;
if ( V_87 && ! strncmp ( V_87 , L_71 , 2 ) ) {
V_51 -> V_156 = strtoul ( V_51 -> V_53 , & V_87 , 0 ) ;
if ( * V_87 != '\0' ) {
F_95 ( L_72 ) ;
return - V_48 ;
}
}
}
while ( V_146 ) {
V_149 = V_146 ;
V_151 = V_152 ;
if ( V_151 == ';' ) {
V_51 -> V_54 = F_28 ( V_149 ) ;
if ( V_51 -> V_54 == NULL )
return - V_47 ;
break;
}
V_146 = strpbrk ( V_149 , L_70 ) ;
if ( V_146 ) {
V_152 = * V_146 ;
* V_146 ++ = '\0' ;
}
switch ( V_151 ) {
case ':' :
V_51 -> line = strtoul ( V_149 , & V_87 , 0 ) ;
if ( * V_87 != '\0' ) {
F_95 ( L_73
L_74 ) ;
return - V_48 ;
}
break;
case '+' :
V_51 -> V_83 = strtoul ( V_149 , & V_87 , 0 ) ;
if ( * V_87 != '\0' ) {
F_95 ( L_75
L_76 ) ;
return - V_48 ;
}
break;
case '@' :
if ( V_51 -> V_52 ) {
F_95 ( L_77 ) ;
return - V_48 ;
}
V_51 -> V_52 = F_28 ( V_149 ) ;
if ( V_51 -> V_52 == NULL )
return - V_47 ;
break;
case '%' :
if ( strcmp ( V_149 , L_78 ) == 0 ) {
V_51 -> V_84 = 1 ;
} else {
F_95 ( L_79 , V_149 ) ;
return - V_81 ;
}
break;
default:
F_55 ( L_80 ,
__FILE__ , __LINE__ ) ;
return - V_81 ;
break;
}
}
if ( V_51 -> V_54 && V_51 -> line ) {
F_95 ( L_81
L_82 ) ;
return - V_48 ;
}
if ( V_51 -> V_54 && V_51 -> V_83 ) {
F_95 ( L_83 ) ;
return - V_48 ;
}
if ( V_51 -> line && V_51 -> V_83 ) {
F_95 ( L_84 ) ;
return - V_48 ;
}
if ( ! V_51 -> line && ! V_51 -> V_54 && V_51 -> V_52 && ! V_51 -> V_53 ) {
F_95 ( L_85
L_86 ) ;
return - V_48 ;
}
if ( V_51 -> V_83 && ! V_51 -> V_53 ) {
F_95 ( L_87 ) ;
return - V_48 ;
}
if ( V_51 -> V_84 && ! V_51 -> V_53 ) {
F_95 ( L_88 ) ;
return - V_48 ;
}
if ( ( V_51 -> V_83 || V_51 -> line || V_51 -> V_54 ) && V_51 -> V_84 ) {
F_95 ( L_89
L_90 ) ;
return - V_48 ;
}
F_4 ( L_91 ,
V_51 -> V_53 , V_51 -> V_52 , V_51 -> line , V_51 -> V_83 , V_51 -> V_84 ,
V_51 -> V_54 ) ;
return 0 ;
}
static int F_99 ( char * V_1 , struct V_157 * V_149 )
{
char * V_87 , * V_158 ;
struct V_159 * * V_160 ;
F_4 ( L_92 , V_1 ) ;
V_87 = strchr ( V_1 , '=' ) ;
if ( V_87 ) {
V_149 -> V_15 = F_100 ( V_1 , V_87 - V_1 ) ;
if ( V_149 -> V_15 == NULL )
return - V_47 ;
F_4 ( L_93 , V_149 -> V_15 ) ;
V_1 = V_87 + 1 ;
}
V_87 = strchr ( V_1 , ':' ) ;
if ( V_87 ) {
* V_87 = '\0' ;
V_149 -> type = F_28 ( V_87 + 1 ) ;
if ( V_149 -> type == NULL )
return - V_47 ;
F_4 ( L_94 , V_149 -> type ) ;
}
V_87 = strpbrk ( V_1 , L_95 ) ;
if ( ! F_101 ( V_1 ) || ! V_87 ) {
V_149 -> V_138 = F_28 ( V_1 ) ;
if ( V_149 -> V_138 == NULL )
return - V_47 ;
F_4 ( L_96 , V_149 -> V_138 ) ;
return 0 ;
}
V_149 -> V_138 = F_100 ( V_1 , V_87 - V_1 ) ;
if ( V_149 -> V_138 == NULL )
return - V_47 ;
V_158 = V_149 -> V_138 ;
F_4 ( L_97 , V_149 -> V_138 ) ;
V_160 = & V_149 -> V_161 ;
do {
* V_160 = F_102 ( sizeof( struct V_159 ) ) ;
if ( * V_160 == NULL )
return - V_47 ;
if ( * V_87 == '[' ) {
V_1 = V_87 ;
( * V_160 ) -> V_162 = strtol ( V_1 + 1 , & V_87 , 0 ) ;
( * V_160 ) -> V_163 = true ;
if ( * V_87 != ']' || V_87 == V_1 + 1 ) {
F_95 ( L_98
L_99 ) ;
return - V_48 ;
}
V_87 ++ ;
if ( * V_87 == '\0' )
V_87 = NULL ;
} else {
if ( * V_87 == '.' ) {
V_1 = V_87 + 1 ;
( * V_160 ) -> V_163 = false ;
} else if ( V_87 [ 1 ] == '>' ) {
V_1 = V_87 + 2 ;
( * V_160 ) -> V_163 = true ;
} else {
F_95 ( L_100 ,
V_1 ) ;
return - V_48 ;
}
V_87 = strpbrk ( V_1 , L_95 ) ;
}
if ( V_87 ) {
( * V_160 ) -> V_15 = F_100 ( V_1 , V_87 - V_1 ) ;
if ( ( * V_160 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_158 = ( * V_160 ) -> V_15 ;
F_4 ( L_101 , ( * V_160 ) -> V_15 , ( * V_160 ) -> V_163 ) ;
V_160 = & ( * V_160 ) -> V_164 ;
}
} while ( V_87 );
( * V_160 ) -> V_15 = F_28 ( V_1 ) ;
if ( ( * V_160 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_158 = ( * V_160 ) -> V_15 ;
F_4 ( L_102 , ( * V_160 ) -> V_15 , ( * V_160 ) -> V_163 ) ;
if ( ! V_149 -> V_15 ) {
V_149 -> V_15 = F_28 ( V_158 ) ;
if ( V_149 -> V_15 == NULL )
return - V_47 ;
}
return 0 ;
}
int F_103 ( const char * V_165 , struct V_85 * V_86 )
{
char * * V_166 ;
int V_167 , V_58 , V_4 = 0 ;
V_166 = F_104 ( V_165 , & V_167 ) ;
if ( ! V_166 ) {
F_4 ( L_103 ) ;
return - V_47 ;
}
if ( V_167 - 1 > V_168 ) {
F_95 ( L_104 , V_167 - 1 ) ;
V_4 = - V_169 ;
goto V_11;
}
V_4 = F_98 ( V_166 [ 0 ] , V_86 ) ;
if ( V_4 < 0 )
goto V_11;
V_86 -> V_170 = V_167 - 1 ;
V_86 -> args = F_102 ( sizeof( struct V_157 ) * V_86 -> V_170 ) ;
if ( V_86 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_58 = 0 ; V_58 < V_86 -> V_170 && V_4 >= 0 ; V_58 ++ ) {
V_4 = F_99 ( V_166 [ V_58 + 1 ] , & V_86 -> args [ V_58 ] ) ;
if ( V_4 >= 0 &&
F_101 ( V_86 -> args [ V_58 ] . V_138 ) && V_86 -> V_88 . V_84 ) {
F_95 ( L_105
L_106 ) ;
V_4 = - V_48 ;
}
}
V_11:
F_105 ( V_166 ) ;
return V_4 ;
}
bool F_68 ( struct V_85 * V_86 )
{
int V_58 ;
if ( V_86 -> V_88 . V_52 || V_86 -> V_88 . line || V_86 -> V_88 . V_54 )
return true ;
for ( V_58 = 0 ; V_58 < V_86 -> V_170 ; V_58 ++ )
if ( F_101 ( V_86 -> args [ V_58 ] . V_138 ) )
return true ;
return false ;
}
int F_106 ( const char * V_165 , struct V_55 * V_171 )
{
struct V_106 * V_107 = & V_171 -> V_88 ;
char V_172 ;
char * V_173 ;
char * V_174 = NULL , * V_175 , * V_176 , * V_177 , * V_178 ;
int V_4 , V_58 , V_167 ;
char * * V_166 ;
F_4 ( L_107 , V_165 ) ;
V_166 = F_104 ( V_165 , & V_167 ) ;
if ( ! V_166 ) {
F_4 ( L_103 ) ;
return - V_47 ;
}
if ( V_167 < 2 ) {
F_95 ( L_108 ) ;
V_4 = - V_169 ;
goto V_11;
}
V_174 = F_28 ( V_166 [ 0 ] ) ;
if ( V_174 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
V_176 = strtok_r ( V_174 , L_109 , & V_175 ) ;
V_177 = strtok_r ( NULL , L_110 , & V_175 ) ;
V_178 = strtok_r ( NULL , L_111 , & V_175 ) ;
if ( V_176 == NULL || strlen ( V_176 ) != 1 || V_177 == NULL
|| V_178 == NULL ) {
F_95 ( L_112 , V_166 [ 0 ] ) ;
V_4 = - V_48 ;
goto V_11;
}
V_172 = V_176 [ 0 ] ;
V_171 -> V_155 = F_28 ( V_177 ) ;
V_171 -> V_154 = F_28 ( V_178 ) ;
if ( V_171 -> V_155 == NULL || V_171 -> V_154 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
F_4 ( L_113 , V_171 -> V_155 , V_171 -> V_154 , V_172 ) ;
V_107 -> V_84 = ( V_172 == 'r' ) ;
V_173 = strchr ( V_166 [ 1 ] , ':' ) ;
if ( V_173 ) {
V_107 -> V_29 = F_100 ( V_166 [ 1 ] , V_173 - V_166 [ 1 ] ) ;
V_173 ++ ;
} else
V_173 = V_166 [ 1 ] ;
V_176 = strtok_r ( V_173 , L_114 , & V_175 ) ;
if ( V_176 [ 0 ] == '0' ) {
if ( strcmp ( V_176 , L_71 ) == 0 ) {
if ( ! V_166 [ 2 ] || strcmp ( V_166 [ 2 ] , L_115 ) ) {
V_4 = - V_48 ;
goto V_11;
}
V_107 -> V_59 = 0 ;
free ( V_166 [ 2 ] ) ;
for ( V_58 = 2 ; V_166 [ V_58 + 1 ] != NULL ; V_58 ++ )
V_166 [ V_58 ] = V_166 [ V_58 + 1 ] ;
V_166 [ V_58 ] = NULL ;
V_167 -= 1 ;
} else
V_107 -> V_59 = strtoul ( V_176 , NULL , 0 ) ;
} else {
V_107 -> V_14 = F_28 ( V_176 ) ;
if ( V_107 -> V_14 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
V_177 = strtok_r ( NULL , L_36 , & V_175 ) ;
if ( V_177 == NULL )
V_107 -> V_83 = 0 ;
else
V_107 -> V_83 = strtoul ( V_177 , NULL , 10 ) ;
}
V_171 -> V_170 = V_167 - 2 ;
V_171 -> args = F_102 ( sizeof( struct V_179 ) * V_171 -> V_170 ) ;
if ( V_171 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_58 = 0 ; V_58 < V_171 -> V_170 ; V_58 ++ ) {
V_173 = strchr ( V_166 [ V_58 + 2 ] , '=' ) ;
if ( V_173 )
* V_173 ++ = '\0' ;
else
V_173 = V_166 [ V_58 + 2 ] ;
V_171 -> args [ V_58 ] . V_15 = F_28 ( V_166 [ V_58 + 2 ] ) ;
V_171 -> args [ V_58 ] . V_180 = F_28 ( V_173 ) ;
if ( V_171 -> args [ V_58 ] . V_15 == NULL || V_171 -> args [ V_58 ] . V_180 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
free ( V_174 ) ;
F_105 ( V_166 ) ;
return V_4 ;
}
char * F_107 ( struct V_157 * V_181 )
{
struct V_159 * V_161 = V_181 -> V_161 ;
struct V_182 V_46 ;
char * V_4 = NULL ;
int V_98 ;
if ( F_108 ( & V_46 , 64 ) < 0 )
return NULL ;
if ( V_181 -> V_15 && V_181 -> V_138 )
V_98 = F_109 ( & V_46 , L_116 , V_181 -> V_15 , V_181 -> V_138 ) ;
else
V_98 = F_110 ( & V_46 , V_181 -> V_15 ? : V_181 -> V_138 ) ;
if ( V_98 )
goto V_11;
while ( V_161 ) {
if ( V_161 -> V_15 [ 0 ] == '[' )
V_98 = F_110 ( & V_46 , V_161 -> V_15 ) ;
else
V_98 = F_109 ( & V_46 , L_117 , V_161 -> V_163 ? L_118 : L_119 ,
V_161 -> V_15 ) ;
V_161 = V_161 -> V_164 ;
if ( V_98 )
goto V_11;
}
if ( V_181 -> type )
if ( F_109 ( & V_46 , L_120 , V_181 -> type ) < 0 )
goto V_11;
V_4 = F_111 ( & V_46 , NULL ) ;
V_11:
F_112 ( & V_46 ) ;
return V_4 ;
}
static char * F_70 ( struct V_50 * V_51 )
{
struct V_182 V_46 ;
char * V_87 , * V_4 = NULL ;
int V_91 , V_98 = 0 ;
if ( F_108 ( & V_46 , 64 ) < 0 )
return NULL ;
if ( V_51 -> V_53 ) {
if ( F_110 ( & V_46 , V_51 -> V_53 ) < 0 )
goto V_11;
if ( V_51 -> V_83 )
V_98 = F_109 ( & V_46 , L_121 , V_51 -> V_83 ) ;
else if ( V_51 -> line )
V_98 = F_109 ( & V_46 , L_122 , V_51 -> line ) ;
else if ( V_51 -> V_84 )
V_98 = F_110 ( & V_46 , L_123 ) ;
if ( V_98 )
goto V_11;
}
if ( V_51 -> V_52 ) {
V_87 = V_51 -> V_52 ;
V_91 = strlen ( V_87 ) ;
if ( V_91 > 30 ) {
V_87 = strchr ( V_51 -> V_52 + V_91 - 30 , '/' ) ;
V_87 = V_87 ? V_87 + 1 : V_51 -> V_52 + V_91 - 30 ;
}
V_98 = F_109 ( & V_46 , L_124 , V_87 ) ;
if ( ! V_98 && ! V_51 -> V_53 && V_51 -> line )
V_98 = F_109 ( & V_46 , L_122 , V_51 -> line ) ;
}
if ( ! V_98 )
V_4 = F_111 ( & V_46 , NULL ) ;
V_11:
F_112 ( & V_46 ) ;
return V_4 ;
}
static int F_113 ( struct V_183 * V_163 ,
struct V_182 * V_46 , int V_184 )
{
int V_98 ;
if ( V_163 -> V_164 ) {
V_184 = F_113 ( V_163 -> V_164 , V_46 ,
V_184 + 1 ) ;
if ( V_184 < 0 )
return V_184 ;
}
V_98 = F_109 ( V_46 , L_125 , V_163 -> V_83 ) ;
return ( V_98 < 0 ) ? V_98 : V_184 ;
}
static int F_114 ( struct V_179 * V_149 ,
struct V_182 * V_46 )
{
struct V_183 * V_163 = V_149 -> V_163 ;
int V_184 = 0 , V_98 ;
if ( V_149 -> V_15 )
V_98 = F_109 ( V_46 , L_126 , V_149 -> V_15 ) ;
else
V_98 = F_115 ( V_46 , ' ' ) ;
if ( V_98 )
return V_98 ;
if ( V_149 -> V_180 [ 0 ] == '@' && V_149 -> V_163 )
V_163 = V_163 -> V_164 ;
if ( V_163 ) {
V_184 = F_113 ( V_163 , V_46 , 1 ) ;
if ( V_184 < 0 )
return V_184 ;
}
if ( V_149 -> V_180 [ 0 ] == '@' && V_149 -> V_163 )
V_98 = F_109 ( V_46 , L_127 , V_149 -> V_180 , V_149 -> V_163 -> V_83 ) ;
else
V_98 = F_110 ( V_46 , V_149 -> V_180 ) ;
while ( ! V_98 && V_184 -- )
V_98 = F_115 ( V_46 , ')' ) ;
if ( ! V_98 && V_149 -> type )
V_98 = F_109 ( V_46 , L_120 , V_149 -> type ) ;
return V_98 ;
}
char * F_116 ( struct V_55 * V_171 )
{
struct V_106 * V_107 = & V_171 -> V_88 ;
struct V_182 V_46 ;
char * V_4 = NULL ;
int V_58 , V_98 ;
if ( V_171 -> V_80 && ! V_107 -> V_29 )
return NULL ;
if ( F_108 ( & V_46 , 32 ) < 0 )
return NULL ;
if ( F_109 ( & V_46 , L_128 , V_107 -> V_84 ? 'r' : 'p' ,
V_171 -> V_155 , V_171 -> V_154 ) < 0 )
goto error;
if ( V_171 -> V_80 && ! V_107 -> V_59 ) {
if ( ! V_107 -> V_14 || strcmp ( V_107 -> V_14 , L_129 ) )
goto error;
}
if ( V_171 -> V_80 )
V_98 = F_109 ( & V_46 , L_130 , V_107 -> V_29 , V_107 -> V_59 ) ;
else if ( ! strncmp ( V_107 -> V_14 , L_71 , 2 ) )
V_98 = F_109 ( & V_46 , L_131 , V_107 -> V_29 ? : L_36 ,
V_107 -> V_29 ? L_109 : L_36 , V_107 -> V_59 ) ;
else
V_98 = F_109 ( & V_46 , L_132 , V_107 -> V_29 ? : L_36 ,
V_107 -> V_29 ? L_109 : L_36 , V_107 -> V_14 , V_107 -> V_83 ) ;
if ( V_98 )
goto error;
for ( V_58 = 0 ; V_58 < V_171 -> V_170 ; V_58 ++ )
if ( F_114 ( & V_171 -> args [ V_58 ] , & V_46 ) < 0 )
goto error;
V_4 = F_111 ( & V_46 , NULL ) ;
error:
F_112 ( & V_46 ) ;
return V_4 ;
}
static int F_117 ( struct V_106 * V_107 ,
struct V_50 * V_51 ,
bool V_108 )
{
struct V_14 * V_24 = NULL ;
struct V_16 * V_16 ;
T_3 V_18 = V_107 -> V_59 ;
int V_4 = - V_26 ;
if ( ! V_108 ) {
V_16 = F_24 ( V_107 -> V_29 ) ;
if ( ! V_16 )
goto V_11;
V_24 = F_118 ( V_16 , V_18 , NULL ) ;
} else {
if ( V_107 -> V_14 && ! V_18 ) {
if ( F_18 ( V_107 -> V_14 ,
& V_18 , true , false ) < 0 )
goto V_11;
}
if ( V_18 ) {
V_18 += V_107 -> V_83 ;
V_24 = F_12 ( V_18 , & V_16 ) ;
}
}
if ( ! V_24 )
goto V_11;
V_51 -> V_84 = V_107 -> V_84 ;
V_51 -> V_83 = V_18 - V_16 -> V_27 ( V_16 , V_24 -> V_28 ) ;
V_51 -> V_53 = F_28 ( V_24 -> V_15 ) ;
V_4 = V_51 -> V_53 ? 0 : - V_47 ;
V_11:
if ( V_16 && ! V_108 ) {
F_26 ( V_16 ) ;
}
return V_4 ;
}
static int F_119 ( struct V_106 * V_107 ,
struct V_50 * V_51 ,
bool V_108 )
{
char V_46 [ 128 ] ;
int V_4 ;
V_4 = F_63 ( V_107 , V_51 , V_108 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_117 ( V_107 , V_51 , V_108 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( L_133 ) ;
if ( V_107 -> V_14 ) {
V_51 -> V_53 = F_28 ( V_107 -> V_14 ) ;
V_51 -> V_83 = V_107 -> V_83 ;
} else {
V_4 = F_1 ( V_46 , 128 , L_134 V_82 , ( T_3 ) V_107 -> V_59 ) ;
if ( V_4 < 0 )
return V_4 ;
V_51 -> V_53 = F_28 ( V_46 ) ;
V_51 -> V_83 = 0 ;
}
if ( V_51 -> V_53 == NULL )
return - V_47 ;
V_51 -> V_84 = V_107 -> V_84 ;
return 0 ;
}
static int F_120 ( struct V_55 * V_171 ,
struct V_85 * V_86 , bool V_108 )
{
struct V_182 V_46 = V_185 ;
int V_58 , V_4 ;
V_86 -> V_154 = F_28 ( V_171 -> V_154 ) ;
V_86 -> V_155 = F_28 ( V_171 -> V_155 ) ;
if ( V_86 -> V_154 == NULL || V_86 -> V_155 == NULL )
return - V_47 ;
V_4 = F_119 ( & V_171 -> V_88 , & V_86 -> V_88 , V_108 ) ;
if ( V_4 < 0 )
return V_4 ;
V_86 -> V_170 = V_171 -> V_170 ;
V_86 -> args = F_102 ( sizeof( struct V_157 ) * V_86 -> V_170 ) ;
if ( V_86 -> args == NULL )
return - V_47 ;
for ( V_58 = 0 ; V_58 < V_171 -> V_170 && V_4 >= 0 ; V_58 ++ ) {
if ( V_171 -> args [ V_58 ] . V_15 )
V_86 -> args [ V_58 ] . V_15 = F_28 ( V_171 -> args [ V_58 ] . V_15 ) ;
else {
if ( ( V_4 = F_108 ( & V_46 , 32 ) ) < 0 )
goto error;
V_4 = F_114 ( & V_171 -> args [ V_58 ] , & V_46 ) ;
V_86 -> args [ V_58 ] . V_15 = F_111 ( & V_46 , NULL ) ;
}
if ( V_86 -> args [ V_58 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_47 ;
}
error:
if ( V_4 < 0 )
F_121 ( V_86 ) ;
return V_4 ;
}
void F_121 ( struct V_85 * V_86 )
{
struct V_159 * V_161 , * V_164 ;
int V_58 ;
free ( V_86 -> V_154 ) ;
free ( V_86 -> V_155 ) ;
free ( V_86 -> V_39 ) ;
F_30 ( & V_86 -> V_88 ) ;
for ( V_58 = 0 ; V_58 < V_86 -> V_170 ; V_58 ++ ) {
free ( V_86 -> args [ V_58 ] . V_15 ) ;
free ( V_86 -> args [ V_58 ] . V_138 ) ;
free ( V_86 -> args [ V_58 ] . type ) ;
V_161 = V_86 -> args [ V_58 ] . V_161 ;
while ( V_161 ) {
V_164 = V_161 -> V_164 ;
F_60 ( & V_161 -> V_15 ) ;
free ( V_161 ) ;
V_161 = V_164 ;
}
}
free ( V_86 -> args ) ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
}
void F_32 ( struct V_55 * V_171 )
{
struct V_183 * V_163 , * V_164 ;
int V_58 ;
free ( V_171 -> V_154 ) ;
free ( V_171 -> V_155 ) ;
free ( V_171 -> V_88 . V_14 ) ;
free ( V_171 -> V_88 . V_113 ) ;
free ( V_171 -> V_88 . V_29 ) ;
for ( V_58 = 0 ; V_58 < V_171 -> V_170 ; V_58 ++ ) {
free ( V_171 -> args [ V_58 ] . V_15 ) ;
free ( V_171 -> args [ V_58 ] . V_180 ) ;
free ( V_171 -> args [ V_58 ] . type ) ;
V_163 = V_171 -> args [ V_58 ] . V_163 ;
while ( V_163 ) {
V_164 = V_163 -> V_164 ;
free ( V_163 ) ;
V_163 = V_164 ;
}
}
free ( V_171 -> args ) ;
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
}
static void F_122 ( struct V_186 * V_187 )
{
struct V_188 * V_134 ;
while ( ! F_123 ( V_187 ) ) {
V_134 = F_124 ( V_187 ,
struct V_188 , V_189 ) ;
F_125 ( & V_134 -> V_189 ) ;
free ( V_134 -> V_14 ) ;
free ( V_134 ) ;
}
}
static int F_126 ( struct V_186 * V_187 )
{
struct V_188 * V_134 ;
const char * V_190 = F_127 () ;
char V_46 [ V_191 ] , * V_173 ;
T_9 * V_116 ;
int V_4 ;
if ( V_190 == NULL )
return - V_81 ;
V_4 = F_1 ( V_46 , V_191 , L_135 , V_190 ) ;
if ( V_4 < 0 )
return V_4 ;
V_116 = fopen ( V_46 , L_47 ) ;
if ( ! V_116 )
return - V_102 ;
V_4 = 0 ;
while ( fgets ( V_46 , V_191 , V_116 ) ) {
V_134 = F_102 ( sizeof( * V_134 ) ) ;
if ( ! V_134 ) {
V_4 = - V_47 ;
break;
}
F_128 ( & V_134 -> V_189 ) ;
F_129 ( & V_134 -> V_189 , V_187 ) ;
if ( sscanf ( V_46 , L_136 , & V_134 -> V_28 , & V_134 -> V_92 ) != 2 ) {
V_4 = - V_48 ;
break;
}
V_173 = strchr ( V_46 , '\t' ) ;
if ( V_173 ) {
V_173 ++ ;
if ( V_173 [ strlen ( V_173 ) - 1 ] == '\n' )
V_173 [ strlen ( V_173 ) - 1 ] = '\0' ;
} else
V_173 = ( char * ) L_137 ;
V_134 -> V_14 = F_28 ( V_173 ) ;
if ( ! V_134 -> V_14 ) {
V_4 = - V_47 ;
break;
}
F_130 ( L_138 ,
V_134 -> V_28 , V_134 -> V_92 , V_134 -> V_14 ) ;
V_4 ++ ;
}
if ( V_4 < 0 )
F_122 ( V_187 ) ;
fclose ( V_116 ) ;
return V_4 ;
}
static struct V_188 *
F_131 ( struct V_186 * V_187 ,
unsigned long V_59 )
{
struct V_188 * V_134 ;
F_132 (node, blacklist, list) {
if ( V_134 -> V_28 <= V_59 && V_59 <= V_134 -> V_92 )
return V_134 ;
}
return NULL ;
}
static void F_133 ( void )
{
if ( ! F_123 ( & V_192 ) )
return;
if ( F_126 ( & V_192 ) < 0 )
F_4 ( L_139 ) ;
}
static void F_134 ( void )
{
F_122 ( & V_192 ) ;
}
static bool F_34 ( unsigned long V_59 )
{
return ! ! F_131 ( & V_192 , V_59 ) ;
}
static int F_135 ( const char * V_155 , const char * V_154 ,
struct V_85 * V_86 ,
const char * V_29 ,
struct V_182 * V_42 )
{
int V_58 , V_4 ;
char * V_46 ;
if ( F_136 ( & V_46 , L_140 , V_155 , V_154 ) < 0 )
return - V_102 ;
V_4 = F_109 ( V_42 , L_141 , V_46 ) ;
free ( V_46 ) ;
if ( V_4 )
return V_4 ;
V_46 = F_70 ( & V_86 -> V_88 ) ;
if ( ! V_46 )
return - V_47 ;
V_4 = F_110 ( V_42 , V_46 ) ;
free ( V_46 ) ;
if ( ! V_4 && V_29 )
V_4 = F_109 ( V_42 , L_142 , V_29 ) ;
if ( ! V_4 && V_86 -> V_170 > 0 ) {
V_4 = F_137 ( V_42 , L_143 , 5 ) ;
for ( V_58 = 0 ; ! V_4 && V_58 < V_86 -> V_170 ; V_58 ++ ) {
V_46 = F_107 ( & V_86 -> args [ V_58 ] ) ;
if ( ! V_46 )
return - V_47 ;
V_4 = F_109 ( V_42 , L_144 , V_46 ) ;
free ( V_46 ) ;
}
}
if ( ! V_4 )
V_4 = F_115 ( V_42 , ')' ) ;
return V_4 ;
}
int F_138 ( const char * V_155 , const char * V_154 ,
struct V_85 * V_86 ,
const char * V_29 , bool V_193 )
{
struct V_182 V_46 = V_185 ;
int V_4 ;
V_4 = F_135 ( V_155 , V_154 , V_86 , V_29 , & V_46 ) ;
if ( V_4 >= 0 ) {
if ( V_193 )
printf ( L_96 , V_46 . V_46 ) ;
else
F_139 ( L_96 , V_46 . V_46 ) ;
}
F_112 ( & V_46 ) ;
return V_4 ;
}
static bool F_140 ( struct V_55 * V_171 ,
struct V_130 * T_10 )
{
char V_87 [ 128 ] ;
if ( F_87 ( T_10 , V_171 -> V_154 ) )
return true ;
if ( F_1 ( V_87 , 128 , L_140 , V_171 -> V_155 , V_171 -> V_154 ) < 0 )
return false ;
return F_87 ( T_10 , V_87 ) ;
}
static int F_141 ( int V_61 , bool V_108 ,
struct V_130 * T_10 )
{
int V_4 = 0 ;
struct V_55 V_171 ;
struct V_85 V_86 ;
struct V_194 * V_195 ;
struct V_133 * V_196 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_195 = F_142 ( V_61 ) ;
if ( ! V_195 )
return - V_47 ;
F_86 (ent, rawlist) {
V_4 = F_106 ( V_196 -> V_140 , & V_171 ) ;
if ( V_4 >= 0 ) {
if ( ! F_140 ( & V_171 , T_10 ) )
goto V_164;
V_4 = F_120 ( & V_171 , & V_86 ,
V_108 ) ;
if ( V_4 < 0 )
goto V_164;
V_4 = F_138 ( V_86 . V_155 , V_86 . V_154 ,
& V_86 , V_171 . V_88 . V_29 ,
true ) ;
}
V_164:
F_121 ( & V_86 ) ;
F_32 ( & V_171 ) ;
if ( V_4 < 0 )
break;
}
F_88 ( V_195 ) ;
F_61 () ;
return V_4 ;
}
int F_143 ( struct V_130 * T_10 )
{
int V_197 , V_198 , V_4 ;
F_77 () ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_144 ( & V_197 , & V_198 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_197 >= 0 )
V_4 = F_141 ( V_197 , true , T_10 ) ;
if ( V_198 >= 0 && V_4 >= 0 )
V_4 = F_141 ( V_198 , false , T_10 ) ;
if ( V_197 > 0 )
F_42 ( V_197 ) ;
if ( V_198 > 0 )
F_42 ( V_198 ) ;
F_8 () ;
return V_4 ;
}
static int F_145 ( char * V_46 , T_1 V_91 , const char * V_199 ,
struct V_194 * V_200 , bool V_201 )
{
int V_58 , V_4 ;
char * V_173 , * V_202 ;
if ( * V_199 == '.' )
V_199 ++ ;
V_202 = F_28 ( V_199 ) ;
if ( ! V_202 )
return - V_47 ;
V_173 = strchr ( V_202 , '.' ) ;
if ( V_173 && V_173 != V_202 )
* V_173 = '\0' ;
V_4 = F_1 ( V_46 , V_91 , L_39 , V_202 ) ;
if ( V_4 < 0 ) {
F_4 ( L_145 , V_4 ) ;
goto V_11;
}
if ( ! F_146 ( V_200 , V_46 ) )
goto V_11;
if ( ! V_201 ) {
F_7 ( L_146
L_147
L_148
L_149 ,
V_46 ) ;
V_4 = - V_203 ;
goto V_11;
}
for ( V_58 = 1 ; V_58 < V_204 ; V_58 ++ ) {
V_4 = F_1 ( V_46 , V_91 , L_150 , V_202 , V_58 ) ;
if ( V_4 < 0 ) {
F_4 ( L_145 , V_4 ) ;
goto V_11;
}
if ( ! F_146 ( V_200 , V_46 ) )
break;
}
if ( V_58 == V_204 ) {
F_7 ( L_151 ) ;
V_4 = - V_169 ;
}
V_11:
free ( V_202 ) ;
return V_4 ;
}
static void F_147 ( struct V_55 * V_171 )
{
int V_58 ;
char * V_46 = F_116 ( V_171 ) ;
if ( ! V_171 -> V_80 || V_171 -> V_170 == 0 || ! V_46 )
goto V_11;
for ( V_58 = 0 ; V_58 < V_171 -> V_170 ; V_58 ++ )
if ( F_148 ( V_171 -> args [ V_58 ] . V_180 , L_152 ) ) {
F_7 ( L_153
L_154 ,
V_171 -> args [ V_58 ] . V_180 ) ;
break;
}
V_11:
free ( V_46 ) ;
}
static int F_149 ( struct V_55 * V_171 ,
struct V_85 * V_86 ,
struct V_194 * V_200 ,
bool V_201 )
{
const char * V_154 , * V_155 ;
char V_46 [ 64 ] ;
int V_4 ;
if ( V_86 -> V_154 )
V_154 = V_86 -> V_154 ;
else
if ( V_86 -> V_88 . V_53 &&
( strncmp ( V_86 -> V_88 . V_53 , L_71 , 2 ) != 0 ) &&
! F_150 ( V_86 -> V_88 . V_53 ) )
V_154 = V_86 -> V_88 . V_53 ;
else
V_154 = V_171 -> V_88 . V_113 ;
if ( V_86 -> V_155 )
V_155 = V_86 -> V_155 ;
else
V_155 = V_49 ;
V_4 = F_145 ( V_46 , 64 , V_154 ,
V_200 , V_201 ) ;
if ( V_4 < 0 )
return V_4 ;
V_154 = V_46 ;
V_171 -> V_154 = F_28 ( V_154 ) ;
V_171 -> V_155 = F_28 ( V_155 ) ;
if ( V_171 -> V_154 == NULL || V_171 -> V_155 == NULL )
return - V_47 ;
F_151 ( V_200 , V_154 ) ;
return 0 ;
}
static int F_152 ( struct V_85 * V_86 ,
struct V_55 * V_56 ,
int V_57 , bool V_201 )
{
int V_58 , V_61 , V_4 ;
struct V_55 * V_171 = NULL ;
struct V_194 * V_200 ;
V_61 = F_153 ( V_205 | ( V_86 -> V_80 ? V_206 : 0 ) ) ;
if ( V_61 < 0 )
return V_61 ;
V_200 = F_154 ( V_61 ) ;
if ( ! V_200 ) {
F_4 ( L_155 ) ;
V_4 = - V_47 ;
goto V_207;
}
V_4 = 0 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_171 = & V_56 [ V_58 ] ;
if ( ! V_171 -> V_88 . V_14 )
continue;
V_4 = F_149 ( V_171 , V_86 , V_200 ,
V_201 ) ;
if ( V_4 < 0 )
break;
V_4 = F_155 ( V_61 , V_171 ) ;
if ( V_4 < 0 )
break;
V_201 = true ;
}
if ( V_4 == - V_48 && V_86 -> V_80 )
F_147 ( V_171 ) ;
F_88 ( V_200 ) ;
V_207:
F_42 ( V_61 ) ;
return V_4 ;
}
static int F_156 ( struct V_16 * V_16 , char * V_15 ,
struct V_14 * * V_208 )
{
int V_76 = 0 ;
struct V_14 * V_24 ;
struct V_209 * V_87 ;
if ( F_16 ( V_16 , NULL ) < 0 )
return 0 ;
F_157 (map, sym, tmp) {
if ( F_148 ( V_24 -> V_15 , V_15 ) ) {
V_76 ++ ;
if ( V_208 && V_76 < V_210 . V_211 )
V_208 [ V_76 - 1 ] = V_24 ;
}
}
return V_76 ;
}
void __weak F_158 ( struct V_85 * V_86 V_143 ,
struct V_55 * V_171 V_143 ,
struct V_16 * V_16 V_143 ,
struct V_14 * V_24 V_143 ) { }
static int F_159 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_16 * V_16 = NULL ;
struct V_19 * V_23 = NULL ;
struct V_14 * V_24 ;
struct V_14 * * V_208 = NULL ;
struct V_55 * V_171 ;
struct V_50 * V_51 = & V_86 -> V_88 ;
struct V_106 * V_107 ;
int V_212 ;
int V_4 , V_58 , V_213 , V_112 = 0 ;
char * V_67 ;
V_16 = F_23 ( V_86 -> V_39 , V_86 -> V_80 ) ;
if ( ! V_16 ) {
V_4 = - V_48 ;
goto V_11;
}
V_208 = malloc ( sizeof( struct V_14 * ) * V_210 . V_211 ) ;
if ( ! V_208 ) {
V_4 = - V_47 ;
goto V_11;
}
V_212 = F_156 ( V_16 , V_51 -> V_53 , V_208 ) ;
if ( V_212 == 0 ) {
F_55 ( L_156 , V_51 -> V_53 ,
V_86 -> V_39 ? : L_5 ) ;
V_4 = - V_26 ;
goto V_11;
} else if ( V_212 > V_210 . V_211 ) {
F_55 ( L_157 ,
V_86 -> V_39 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
if ( ! V_86 -> V_80 && ! V_51 -> V_84 && ! V_86 -> V_39 ) {
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_27 ) ;
V_4 = - V_48 ;
goto V_11;
}
}
* V_56 = F_102 ( sizeof( * V_171 ) * V_212 ) ;
if ( ! * V_56 ) {
V_4 = - V_47 ;
goto V_11;
}
V_4 = 0 ;
for ( V_213 = 0 ; V_213 < V_212 ; V_213 ++ ) {
V_24 = V_208 [ V_213 ] ;
V_171 = ( * V_56 ) + V_4 ;
V_107 = & V_171 -> V_88 ;
if ( V_4 == V_212 ) {
F_7 ( L_158 ) ;
break;
}
V_4 ++ ;
if ( V_51 -> V_83 > V_24 -> V_92 - V_24 -> V_28 ) {
F_7 ( L_159 ,
V_51 -> V_83 , V_24 -> V_15 ) ;
V_4 = - V_26 ;
goto V_214;
}
V_107 -> V_59 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) + V_51 -> V_83 ;
if ( ! V_86 -> V_80 && ! V_86 -> V_39 &&
F_33 ( V_24 -> V_15 , V_107 -> V_59 ) ) {
V_107 -> V_14 = NULL ;
V_112 ++ ;
} else if ( V_23 ) {
V_107 -> V_14 = F_160 ( V_23 -> V_15 , V_215 ) ;
V_107 -> V_83 = V_107 -> V_59 - V_23 -> V_18 ;
} else {
V_107 -> V_14 = F_160 ( V_24 -> V_15 , V_215 ) ;
V_107 -> V_83 = V_51 -> V_83 ;
}
V_107 -> V_113 = F_160 ( V_24 -> V_15 , V_215 ) ;
V_107 -> V_84 = V_51 -> V_84 ;
if ( V_86 -> V_39 ) {
if ( V_86 -> V_80 ) {
V_171 -> V_88 . V_29 = F_160 ( V_86 -> V_39 ,
V_215 ) ;
} else {
V_67 = F_35 ( V_86 -> V_39 ) ;
V_171 -> V_88 . V_29 =
F_28 ( V_67 ? V_67 : V_86 -> V_39 ) ;
free ( V_67 ) ;
if ( ! V_171 -> V_88 . V_29 )
goto V_215;
}
}
V_171 -> V_80 = V_86 -> V_80 ;
V_171 -> V_170 = V_86 -> V_170 ;
if ( V_171 -> V_170 ) {
V_171 -> args = F_102 ( sizeof( struct V_179 ) *
V_171 -> V_170 ) ;
if ( V_171 -> args == NULL )
goto V_215;
}
for ( V_58 = 0 ; V_58 < V_171 -> V_170 ; V_58 ++ ) {
if ( V_86 -> args [ V_58 ] . V_15 )
V_171 -> args [ V_58 ] . V_15 =
F_160 ( V_86 -> args [ V_58 ] . V_15 ,
V_215 ) ;
V_171 -> args [ V_58 ] . V_180 = F_160 ( V_86 -> args [ V_58 ] . V_138 ,
V_215 ) ;
if ( V_86 -> args [ V_58 ] . type )
V_171 -> args [ V_58 ] . type =
F_160 ( V_86 -> args [ V_58 ] . type ,
V_215 ) ;
}
F_158 ( V_86 , V_171 , V_16 , V_24 ) ;
}
if ( V_4 == V_112 ) {
V_4 = - V_26 ;
goto V_214;
}
V_11:
F_25 ( V_16 , V_86 -> V_80 ) ;
free ( V_208 ) ;
return V_4 ;
V_215:
V_4 = - V_47 ;
V_214:
F_31 ( * V_56 , V_212 ) ;
F_60 ( V_56 ) ;
goto V_11;
}
static int F_161 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_50 * V_51 = & V_86 -> V_88 ;
struct V_55 * V_171 ;
struct V_106 * V_107 ;
int V_58 , V_98 ;
if ( ! ( V_86 -> V_88 . V_53 && ! strncmp ( V_86 -> V_88 . V_53 , L_71 , 2 ) ) )
return - V_48 ;
if ( F_68 ( V_86 ) )
return - V_48 ;
* V_56 = F_102 ( sizeof( * V_171 ) ) ;
if ( ! * V_56 )
return - V_47 ;
V_171 = * V_56 ;
V_107 = & V_171 -> V_88 ;
V_107 -> V_59 = V_86 -> V_88 . V_156 ;
V_107 -> V_84 = V_51 -> V_84 ;
V_171 -> V_80 = V_86 -> V_80 ;
V_98 = - V_47 ;
if ( F_136 ( & V_107 -> V_14 , L_160 , V_107 -> V_59 ) < 0 )
goto V_216;
if ( ( ! V_171 -> V_80 ) &&
( F_33 ( V_171 -> V_88 . V_14 ,
V_171 -> V_88 . V_59 ) ) ) {
V_98 = - V_217 ;
goto V_216;
}
if ( F_136 ( & V_107 -> V_113 , L_161 , V_107 -> V_59 ) < 0 )
goto V_216;
if ( V_86 -> V_39 ) {
V_107 -> V_29 = F_28 ( V_86 -> V_39 ) ;
if ( ! V_107 -> V_29 )
goto V_216;
}
if ( V_171 -> V_155 ) {
V_171 -> V_155 = F_28 ( V_86 -> V_155 ) ;
if ( ! V_171 -> V_155 )
goto V_216;
}
if ( V_86 -> V_154 ) {
V_171 -> V_154 = F_28 ( V_86 -> V_154 ) ;
if ( ! V_171 -> V_154 )
goto V_216;
}
V_171 -> V_170 = V_86 -> V_170 ;
V_171 -> args = F_102 ( sizeof( struct V_179 ) * V_171 -> V_170 ) ;
if ( ! V_171 -> args ) {
V_98 = - V_47 ;
goto V_216;
}
for ( V_58 = 0 ; V_58 < V_171 -> V_170 ; V_58 ++ )
F_162 ( & V_171 -> args [ V_58 ] , & V_86 -> args [ V_58 ] ) ;
return 1 ;
V_216:
if ( * V_56 ) {
F_31 ( * V_56 , 1 ) ;
* V_56 = NULL ;
}
return V_98 ;
}
bool __weak F_163 ( void ) { return false ; }
static int F_164 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
int V_4 ;
if ( ! V_86 -> V_155 ) {
if ( ! V_86 -> V_80 ) {
V_86 -> V_155 = F_28 ( V_49 ) ;
V_4 = V_86 -> V_155 ? 0 : - V_47 ;
} else
V_4 = F_27 ( V_86 -> V_39 , & V_86 -> V_155 ) ;
if ( V_4 != 0 ) {
F_7 ( L_162 ) ;
return V_4 ;
}
}
V_4 = F_161 ( V_86 , V_56 ) ;
if ( V_4 > 0 )
return V_4 ;
if ( F_163 () && ! F_68 ( V_86 ) ) {
V_4 = F_159 ( V_86 , V_56 ) ;
if ( V_4 > 0 )
return V_4 ;
}
V_4 = F_67 ( V_86 , V_56 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_159 ( V_86 , V_56 ) ;
}
int F_165 ( struct V_85 * V_141 , int V_142 )
{
int V_58 , V_4 ;
for ( V_58 = 0 ; V_58 < V_142 ; V_58 ++ ) {
if ( ! V_141 [ V_58 ] . V_80 )
F_133 () ;
V_4 = F_164 ( & V_141 [ V_58 ] , & V_141 [ V_58 ] . V_56 ) ;
if ( V_4 < 0 )
return V_4 ;
V_141 [ V_58 ] . V_57 = V_4 ;
}
F_134 () ;
return 0 ;
}
int F_166 ( struct V_85 * V_141 , int V_142 )
{
int V_58 , V_4 = 0 ;
for ( V_58 = 0 ; V_58 < V_142 ; V_58 ++ ) {
V_4 = F_152 ( & V_141 [ V_58 ] , V_141 [ V_58 ] . V_56 ,
V_141 [ V_58 ] . V_57 ,
V_210 . V_218 ) ;
if ( V_4 < 0 )
break;
}
return V_4 ;
}
void F_167 ( struct V_85 * V_141 , int V_142 )
{
int V_58 , V_213 ;
for ( V_58 = 0 ; V_58 < V_142 ; V_58 ++ ) {
for ( V_213 = 0 ; V_213 < V_141 [ V_58 ] . V_57 ; V_213 ++ )
F_32 ( & V_141 [ V_58 ] . V_56 [ V_213 ] ) ;
F_60 ( & V_141 [ V_58 ] . V_56 ) ;
V_141 [ V_58 ] . V_57 = 0 ;
F_121 ( & V_141 [ V_58 ] ) ;
}
}
int F_168 ( struct V_85 * V_141 , int V_142 )
{
int V_4 ;
V_4 = F_2 ( V_141 -> V_80 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_165 ( V_141 , V_142 ) ;
if ( V_4 == 0 )
V_4 = F_166 ( V_141 , V_142 ) ;
F_167 ( V_141 , V_142 ) ;
F_8 () ;
return V_4 ;
}
int F_169 ( struct V_130 * T_10 )
{
int V_4 , V_219 , V_220 = - 1 , V_221 = - 1 ;
char * V_1 = F_170 ( T_10 ) ;
if ( ! V_1 )
return - V_48 ;
V_4 = F_144 ( & V_221 , & V_220 , V_205 ) ;
if ( V_4 < 0 )
goto V_11;
V_4 = F_171 ( V_221 , T_10 ) ;
if ( V_4 < 0 && V_4 != - V_26 )
goto error;
V_219 = F_171 ( V_220 , T_10 ) ;
if ( V_219 < 0 && V_219 != - V_26 ) {
V_4 = V_219 ;
goto error;
}
V_4 = 0 ;
error:
if ( V_221 >= 0 )
F_42 ( V_221 ) ;
if ( V_220 >= 0 )
F_42 ( V_220 ) ;
V_11:
free ( V_1 ) ;
return V_4 ;
}
static int F_172 ( struct V_16 * V_16 V_143 ,
struct V_14 * V_24 )
{
if ( F_87 ( V_222 , V_24 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_173 ( const char * V_39 , struct V_130 * V_131 ,
bool V_40 )
{
struct V_16 * V_16 ;
int V_4 ;
V_4 = F_2 ( V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_40 )
V_16 = F_24 ( V_39 ) ;
else
V_16 = F_19 ( V_39 ) ;
if ( ! V_16 ) {
F_55 ( L_163 , ( V_39 ) ? : L_5 ) ;
return - V_48 ;
}
V_222 = V_131 ;
if ( F_16 ( V_16 , F_172 ) ) {
F_55 ( L_164 , ( V_39 ) ? : L_5 ) ;
goto V_92;
}
if ( ! F_174 ( V_16 -> V_36 , V_16 -> type ) )
F_175 ( V_16 -> V_36 , V_16 -> type ) ;
F_77 () ;
F_176 ( V_16 -> V_36 , V_16 -> type , stdout ) ;
V_92:
if ( V_40 ) {
F_26 ( V_16 ) ;
}
F_8 () ;
return V_4 ;
}
int F_162 ( struct V_179 * V_223 ,
struct V_157 * V_224 )
{
V_223 -> V_180 = F_28 ( V_224 -> V_138 ) ;
if ( V_223 -> V_180 == NULL )
return - V_47 ;
if ( V_224 -> type ) {
V_223 -> type = F_28 ( V_224 -> type ) ;
if ( V_223 -> type == NULL )
return - V_47 ;
}
if ( V_224 -> V_15 ) {
V_223 -> V_15 = F_28 ( V_224 -> V_15 ) ;
if ( V_223 -> V_15 == NULL )
return - V_47 ;
} else
V_223 -> V_15 = NULL ;
return 0 ;
}
