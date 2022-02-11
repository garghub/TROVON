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
F_9 ( V_12 ) ;
V_12 = NULL ;
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
V_35 -> V_36 -> V_38 - 2 ) == 0 &&
V_29 [ V_35 -> V_36 -> V_38 - 2 ] == '\0' ) {
return V_35 ;
}
}
return NULL ;
}
struct V_16 * F_23 ( const char * V_39 , bool V_40 )
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
V_59 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) - V_16 -> V_21 ;
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
static int
F_66 ( struct V_55 * V_56 ,
int V_57 )
{
struct V_19 * V_23 ;
char * V_87 ;
int V_58 , V_111 = 0 ;
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
V_111 ++ ;
} else {
V_87 = F_28 ( V_23 -> V_15 ) ;
if ( ! V_87 )
return - V_47 ;
}
if ( ! V_56 [ V_58 ] . V_88 . V_112 )
V_56 [ V_58 ] . V_88 . V_112 = V_56 [ V_58 ] . V_88 . V_14 ;
else
free ( V_56 [ V_58 ] . V_88 . V_14 ) ;
V_56 [ V_58 ] . V_88 . V_14 = V_87 ;
V_56 [ V_58 ] . V_88 . V_83 = V_56 [ V_58 ] . V_88 . V_59 -
V_23 -> V_25 ;
}
return V_111 ;
}
void __weak
F_67 ( struct V_85 * V_86 V_113 ,
int V_57 V_113 )
{
}
static int F_68 ( struct V_85 * V_86 ,
struct V_55 * V_56 ,
int V_57 , const char * V_29 ,
bool V_114 )
{
int V_4 ;
if ( V_114 )
V_4 = F_64 ( V_56 , V_57 , V_29 ) ;
else if ( V_29 )
V_4 = F_65 ( V_56 , V_57 , V_29 ) ;
else
V_4 = F_66 ( V_56 , V_57 ) ;
if ( V_4 >= 0 )
F_67 ( V_86 , V_57 ) ;
return V_4 ;
}
static int F_69 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
bool V_115 = F_70 ( V_86 ) ;
struct V_50 V_87 ;
struct V_78 * V_79 ;
int V_57 , V_4 = 0 ;
V_79 = F_52 ( V_86 -> V_39 , ! V_115 ) ;
if ( ! V_79 ) {
if ( V_115 )
return - V_26 ;
F_4 ( L_28 ) ;
return 0 ;
}
F_4 ( L_29 ) ;
V_57 = F_71 ( V_79 , V_86 , V_56 ) ;
if ( V_57 == 0 ) {
V_4 = F_50 ( V_79 , V_86 , & V_87 ) ;
if ( ! V_4 ) {
V_57 = F_71 ( V_79 , V_86 , V_56 ) ;
F_30 ( & V_86 -> V_88 ) ;
memcpy ( & V_86 -> V_88 , & V_87 , sizeof( V_87 ) ) ;
}
}
F_59 ( V_79 ) ;
if ( V_57 > 0 ) {
F_4 ( L_30 , V_57 ) ;
V_4 = F_68 ( V_86 , * V_56 , V_57 ,
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
F_72 ( & V_86 -> V_88 ) ) ;
return - V_26 ;
}
F_4 ( L_32 , V_57 ) ;
if ( V_57 < 0 ) {
if ( V_57 == - V_116 )
F_7 ( L_33
L_34 ) ;
if ( ! V_115 ) {
F_4 ( L_35 ) ;
return 0 ;
}
}
return V_57 ;
}
static int F_73 ( T_9 * V_117 , int V_118 , bool V_119 , bool V_120 )
{
char V_46 [ V_121 ] , V_122 [ V_97 ] ;
const char * V_123 = V_120 ? L_36 : V_124 ;
const char * V_125 = NULL ;
do {
if ( fgets ( V_46 , V_121 , V_117 ) == NULL )
goto error;
if ( V_119 )
continue;
if ( ! V_125 ) {
V_125 = V_120 ? L_37 : L_38 ;
F_74 ( stdout , V_123 , V_125 , V_118 ) ;
}
F_74 ( stdout , V_123 , L_39 , V_46 ) ;
} while ( strchr ( V_46 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_117 ) ) {
F_7 ( L_40 ,
F_53 ( V_102 , V_122 , sizeof( V_122 ) ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_75 ( T_9 * V_117 , int V_118 , bool V_119 , bool V_120 )
{
int V_126 = F_73 ( V_117 , V_118 , V_119 , V_120 ) ;
if ( V_126 == 0 ) {
F_7 ( L_41 ) ;
V_126 = - 1 ;
}
return V_126 ;
}
static int F_76 ( struct V_89 * V_90 , const char * V_29 ,
bool V_40 )
{
int V_118 = 1 ;
struct V_127 * V_128 ;
struct V_78 * V_79 ;
T_9 * V_117 ;
int V_4 ;
char * V_87 ;
char V_122 [ V_97 ] ;
V_79 = F_52 ( V_29 , false ) ;
if ( ! V_79 )
return - V_26 ;
V_4 = F_77 ( V_79 , V_90 ) ;
if ( ! V_4 ) {
V_4 = F_51 ( V_79 , V_90 , V_29 , V_40 ) ;
if ( ! V_4 )
V_4 = F_77 ( V_79 , V_90 ) ;
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
V_4 = F_78 ( V_87 , V_90 -> V_129 , & V_90 -> V_95 ) ;
if ( V_87 != V_90 -> V_95 )
free ( V_87 ) ;
if ( V_4 < 0 ) {
F_7 ( L_44 ) ;
return V_4 ;
}
F_79 () ;
if ( V_90 -> V_53 )
fprintf ( stdout , L_45 , V_90 -> V_53 , V_90 -> V_95 ,
V_90 -> V_28 - V_90 -> V_83 ) ;
else
fprintf ( stdout , L_46 , V_90 -> V_95 , V_90 -> V_28 ) ;
V_117 = fopen ( V_90 -> V_95 , L_47 ) ;
if ( V_117 == NULL ) {
F_7 ( L_48 , V_90 -> V_95 ,
F_53 ( V_102 , V_122 , sizeof( V_122 ) ) ) ;
return - V_102 ;
}
while ( V_118 < V_90 -> V_28 ) {
V_4 = F_80 ( V_117 , V_118 ++ ) ;
if ( V_4 < 0 )
goto V_92;
}
F_81 (ln, lr->line_list) {
for (; V_128 -> V_58 > V_118 ; V_118 ++ ) {
V_4 = F_82 ( V_117 , V_118 - V_90 -> V_83 ) ;
if ( V_4 < 0 )
goto V_92;
}
V_4 = F_83 ( V_117 , V_118 ++ - V_90 -> V_83 ) ;
if ( V_4 < 0 )
goto V_92;
}
if ( V_90 -> V_92 == V_93 )
V_90 -> V_92 = V_118 + V_130 ;
while ( V_118 <= V_90 -> V_92 ) {
V_4 = F_84 ( V_117 , V_118 ++ - V_90 -> V_83 ) ;
if ( V_4 <= 0 )
break;
}
V_92:
fclose ( V_117 ) ;
return V_4 ;
}
int F_85 ( struct V_89 * V_90 , const char * V_29 , bool V_40 )
{
int V_4 ;
V_4 = F_2 ( V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_76 ( V_90 , V_29 , V_40 ) ;
F_8 () ;
return V_4 ;
}
static int F_86 ( struct V_78 * V_79 ,
struct V_85 * V_86 ,
struct V_131 * V_132 )
{
char * V_46 ;
int V_4 , V_58 , V_133 ;
struct V_134 * V_135 ;
struct V_136 * V_137 = NULL , * V_138 ;
struct V_50 V_87 ;
const char * V_139 ;
V_46 = F_72 ( & V_86 -> V_88 ) ;
if ( ! V_46 )
return - V_48 ;
F_4 ( L_49 , V_46 ) ;
V_4 = F_87 ( V_79 , V_86 , & V_137 ) ;
if ( ! V_4 ) {
V_4 = F_50 ( V_79 , V_86 , & V_87 ) ;
if ( ! V_4 ) {
V_4 = F_87 ( V_79 , V_86 ,
& V_137 ) ;
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
V_138 = & V_137 [ V_58 ] ;
fprintf ( stdout , L_52 , V_138 -> V_88 . V_14 ,
V_138 -> V_88 . V_83 ) ;
F_60 ( & V_138 -> V_88 . V_14 ) ;
V_133 = 0 ;
if ( V_138 -> V_140 ) {
F_88 (node, vl->vars) {
V_139 = strchr ( V_135 -> V_141 , '\t' ) + 1 ;
if ( F_89 ( V_132 , V_139 ) ) {
fprintf ( stdout , L_53 , V_135 -> V_141 ) ;
V_133 ++ ;
}
}
F_90 ( V_138 -> V_140 ) ;
}
if ( V_133 == 0 )
fprintf ( stdout , L_54 ) ;
}
free ( V_137 ) ;
V_92:
free ( V_46 ) ;
return V_4 ;
}
int F_91 ( struct V_85 * V_142 , int V_143 ,
struct V_131 * V_132 )
{
int V_58 , V_4 = 0 ;
struct V_78 * V_79 ;
V_4 = F_2 ( V_142 -> V_80 ) ;
if ( V_4 < 0 )
return V_4 ;
V_79 = F_52 ( V_142 -> V_39 , false ) ;
if ( ! V_79 ) {
V_4 = - V_26 ;
goto V_11;
}
F_79 () ;
for ( V_58 = 0 ; V_58 < V_143 && V_4 >= 0 ; V_58 ++ )
V_4 = F_86 ( V_79 , & V_142 [ V_58 ] , V_132 ) ;
F_59 ( V_79 ) ;
V_11:
F_8 () ;
return V_4 ;
}
static void F_61 ( void )
{
}
static int
F_63 ( struct V_106 * V_107 V_113 ,
struct V_50 * V_51 V_113 ,
bool V_108 V_113 )
{
return - V_144 ;
}
static int F_69 ( struct V_85 * V_86 ,
struct V_55 * * V_56 V_113 )
{
if ( F_70 ( V_86 ) ) {
F_7 ( L_55 ) ;
return - V_144 ;
}
return 0 ;
}
int F_85 ( struct V_89 * V_90 V_113 ,
const char * V_29 V_113 ,
bool V_40 V_113 )
{
F_7 ( L_55 ) ;
return - V_144 ;
}
int F_91 ( struct V_85 * V_142 V_113 ,
int V_143 V_113 ,
struct V_131 * T_10 V_113 )
{
F_7 ( L_55 ) ;
return - V_144 ;
}
void F_92 ( struct V_89 * V_90 )
{
free ( V_90 -> V_53 ) ;
free ( V_90 -> V_52 ) ;
free ( V_90 -> V_95 ) ;
free ( V_90 -> V_129 ) ;
F_93 ( V_90 -> V_145 ) ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
}
int F_94 ( struct V_89 * V_90 )
{
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_90 -> V_145 = F_95 ( NULL ) ;
if ( ! V_90 -> V_145 )
return - V_47 ;
else
return 0 ;
}
static int F_96 ( char * * V_146 , int * V_147 , const char * V_148 )
{
const char * V_28 = * V_146 ;
V_102 = 0 ;
* V_147 = strtol ( * V_146 , V_146 , 0 ) ;
if ( V_102 || * V_146 == V_28 ) {
F_97 ( L_56 , V_148 ) ;
return - V_48 ;
}
return 0 ;
}
static bool F_98 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
int F_99 ( const char * V_149 , struct V_89 * V_90 )
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
V_98 = F_96 ( & V_150 , & V_90 -> V_28 , L_57 ) ;
if ( V_98 )
goto V_98;
if ( * V_150 == '+' || * V_150 == '-' ) {
const char V_151 = * V_150 ++ ;
V_98 = F_96 ( & V_150 , & V_90 -> V_92 , L_58 ) ;
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
F_97 ( L_60
L_61 ) ;
goto V_98;
}
if ( * V_150 != '\0' ) {
F_97 ( L_62 , V_150 ) ;
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
else if ( F_98 ( V_15 ) )
V_90 -> V_53 = V_15 ;
else {
F_97 ( L_63 , V_15 ) ;
V_98 = - V_48 ;
goto V_98;
}
return 0 ;
V_98:
free ( V_15 ) ;
return V_98 ;
}
static int F_100 ( char * * V_149 , struct V_85 * V_86 )
{
char * V_146 ;
V_146 = strchr ( * V_149 , ':' ) ;
if ( V_146 ) {
* V_146 = '\0' ;
if ( ! V_86 -> V_152 && ! F_98 ( * V_149 ) )
goto V_153;
V_86 -> V_154 = F_28 ( * V_149 ) ;
if ( ! V_86 -> V_154 )
return - V_47 ;
* V_149 = V_146 + 1 ;
} else
V_86 -> V_154 = NULL ;
if ( ! V_86 -> V_152 && ! F_98 ( * V_149 ) ) {
V_153:
F_97 ( L_64
L_65 , * V_149 ) ;
return - V_48 ;
}
V_86 -> V_155 = F_28 ( * V_149 ) ;
if ( V_86 -> V_155 == NULL )
return - V_47 ;
return 0 ;
}
static int F_101 ( char * V_149 , struct V_85 * V_86 )
{
struct V_50 * V_51 = & V_86 -> V_88 ;
char * V_146 , * V_87 ;
char V_151 , V_156 = 0 ;
bool V_157 = false ;
int V_4 ;
if ( ! V_149 )
return - V_48 ;
if ( V_149 [ 0 ] == '%' ||
( ! strncmp ( V_149 , L_66 , 4 ) &&
! ! strchr ( V_149 , ':' ) && ! strchr ( V_149 , '=' ) ) ) {
V_86 -> V_152 = true ;
if ( V_149 [ 0 ] == '%' )
V_149 ++ ;
}
V_146 = strpbrk ( V_149 , L_67 ) ;
if ( V_86 -> V_152 ) {
if ( V_146 ) {
if ( * V_146 != '@' ) {
F_97 ( L_68 ,
V_149 ) ;
return - V_48 ;
}
V_87 = F_102 ( V_146 + 1 ) ;
if ( V_87 ) {
V_86 -> V_39 = F_103 ( V_87 ) ;
free ( V_87 ) ;
} else
V_86 -> V_39 = F_28 ( V_146 + 1 ) ;
if ( ! V_86 -> V_39 )
return - V_47 ;
* V_146 = '\0' ;
}
V_4 = F_100 ( & V_149 , V_86 ) ;
if ( V_4 == 0 ) {
if ( F_104 ( & V_86 -> V_88 . V_53 , L_69 , V_86 -> V_155 ) < 0 )
V_4 = - V_102 ;
}
return V_4 ;
}
if ( V_146 && * V_146 == '=' ) {
* V_146 = '\0' ;
V_87 = V_146 + 1 ;
V_4 = F_100 ( & V_149 , V_86 ) ;
if ( V_4 < 0 )
return V_4 ;
V_149 = V_87 ;
}
if ( ! strpbrk ( V_149 , L_70 ) && ( V_146 = strpbrk ( V_149 , L_71 ) ) != NULL ) {
if ( memchr ( V_149 , '.' , V_146 - V_149 ) )
V_157 = true ;
}
V_146 = strpbrk ( V_149 , L_72 ) ;
if ( V_146 ) {
V_156 = * V_146 ;
* V_146 ++ = '\0' ;
}
if ( V_149 [ 0 ] == '\0' )
V_87 = NULL ;
else {
V_87 = F_28 ( V_149 ) ;
if ( V_87 == NULL )
return - V_47 ;
}
if ( V_157 )
V_51 -> V_52 = V_87 ;
else {
V_51 -> V_53 = V_87 ;
if ( V_87 && ! strncmp ( V_87 , L_73 , 2 ) ) {
V_51 -> V_158 = strtoul ( V_51 -> V_53 , & V_87 , 0 ) ;
if ( * V_87 != '\0' ) {
F_97 ( L_74 ) ;
return - V_48 ;
}
}
}
while ( V_146 ) {
V_149 = V_146 ;
V_151 = V_156 ;
if ( V_151 == ';' ) {
V_51 -> V_54 = F_28 ( V_149 ) ;
if ( V_51 -> V_54 == NULL )
return - V_47 ;
break;
}
V_146 = strpbrk ( V_149 , L_72 ) ;
if ( V_146 ) {
V_156 = * V_146 ;
* V_146 ++ = '\0' ;
}
switch ( V_151 ) {
case ':' :
V_51 -> line = strtoul ( V_149 , & V_87 , 0 ) ;
if ( * V_87 != '\0' ) {
F_97 ( L_75
L_76 ) ;
return - V_48 ;
}
break;
case '+' :
V_51 -> V_83 = strtoul ( V_149 , & V_87 , 0 ) ;
if ( * V_87 != '\0' ) {
F_97 ( L_77
L_78 ) ;
return - V_48 ;
}
break;
case '@' :
if ( V_51 -> V_52 ) {
F_97 ( L_79 ) ;
return - V_48 ;
}
V_51 -> V_52 = F_28 ( V_149 ) ;
if ( V_51 -> V_52 == NULL )
return - V_47 ;
break;
case '%' :
if ( strcmp ( V_149 , L_80 ) == 0 ) {
V_51 -> V_84 = 1 ;
} else {
F_97 ( L_81 , V_149 ) ;
return - V_81 ;
}
break;
default:
F_55 ( L_82 ,
__FILE__ , __LINE__ ) ;
return - V_81 ;
break;
}
}
if ( V_51 -> V_54 && V_51 -> line ) {
F_97 ( L_83
L_84 ) ;
return - V_48 ;
}
if ( V_51 -> V_54 && V_51 -> V_83 ) {
F_97 ( L_85 ) ;
return - V_48 ;
}
if ( V_51 -> line && V_51 -> V_83 ) {
F_97 ( L_86 ) ;
return - V_48 ;
}
if ( ! V_51 -> line && ! V_51 -> V_54 && V_51 -> V_52 && ! V_51 -> V_53 ) {
F_97 ( L_87
L_88 ) ;
return - V_48 ;
}
if ( V_51 -> V_83 && ! V_51 -> V_53 ) {
F_97 ( L_89 ) ;
return - V_48 ;
}
if ( V_51 -> V_84 && ! V_51 -> V_53 ) {
F_97 ( L_90 ) ;
return - V_48 ;
}
if ( ( V_51 -> V_83 || V_51 -> line || V_51 -> V_54 ) && V_51 -> V_84 ) {
F_97 ( L_91
L_92 ) ;
return - V_48 ;
}
F_4 ( L_93 ,
V_51 -> V_53 , V_51 -> V_52 , V_51 -> line , V_51 -> V_83 , V_51 -> V_84 ,
V_51 -> V_54 ) ;
return 0 ;
}
static int F_105 ( char * V_1 , struct V_159 * V_149 )
{
char * V_87 , * V_160 ;
struct V_161 * * V_162 ;
F_4 ( L_94 , V_1 ) ;
V_87 = strchr ( V_1 , '=' ) ;
if ( V_87 ) {
V_149 -> V_15 = F_106 ( V_1 , V_87 - V_1 ) ;
if ( V_149 -> V_15 == NULL )
return - V_47 ;
F_4 ( L_95 , V_149 -> V_15 ) ;
V_1 = V_87 + 1 ;
}
V_87 = strchr ( V_1 , ':' ) ;
if ( V_87 ) {
* V_87 = '\0' ;
V_149 -> type = F_28 ( V_87 + 1 ) ;
if ( V_149 -> type == NULL )
return - V_47 ;
F_4 ( L_96 , V_149 -> type ) ;
}
V_87 = strpbrk ( V_1 , L_97 ) ;
if ( ! F_107 ( V_1 ) || ! V_87 ) {
V_149 -> V_139 = F_28 ( V_1 ) ;
if ( V_149 -> V_139 == NULL )
return - V_47 ;
F_4 ( L_98 , V_149 -> V_139 ) ;
return 0 ;
}
V_149 -> V_139 = F_106 ( V_1 , V_87 - V_1 ) ;
if ( V_149 -> V_139 == NULL )
return - V_47 ;
V_160 = V_149 -> V_139 ;
F_4 ( L_99 , V_149 -> V_139 ) ;
V_162 = & V_149 -> V_163 ;
do {
* V_162 = F_108 ( sizeof( struct V_161 ) ) ;
if ( * V_162 == NULL )
return - V_47 ;
if ( * V_87 == '[' ) {
V_1 = V_87 ;
( * V_162 ) -> V_164 = strtol ( V_1 + 1 , & V_87 , 0 ) ;
( * V_162 ) -> V_165 = true ;
if ( * V_87 != ']' || V_87 == V_1 + 1 ) {
F_97 ( L_100
L_101 ) ;
return - V_48 ;
}
V_87 ++ ;
if ( * V_87 == '\0' )
V_87 = NULL ;
} else {
if ( * V_87 == '.' ) {
V_1 = V_87 + 1 ;
( * V_162 ) -> V_165 = false ;
} else if ( V_87 [ 1 ] == '>' ) {
V_1 = V_87 + 2 ;
( * V_162 ) -> V_165 = true ;
} else {
F_97 ( L_102 ,
V_1 ) ;
return - V_48 ;
}
V_87 = strpbrk ( V_1 , L_97 ) ;
}
if ( V_87 ) {
( * V_162 ) -> V_15 = F_106 ( V_1 , V_87 - V_1 ) ;
if ( ( * V_162 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_160 = ( * V_162 ) -> V_15 ;
F_4 ( L_103 , ( * V_162 ) -> V_15 , ( * V_162 ) -> V_165 ) ;
V_162 = & ( * V_162 ) -> V_166 ;
}
} while ( V_87 );
( * V_162 ) -> V_15 = F_28 ( V_1 ) ;
if ( ( * V_162 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_160 = ( * V_162 ) -> V_15 ;
F_4 ( L_104 , ( * V_162 ) -> V_15 , ( * V_162 ) -> V_165 ) ;
if ( ! V_149 -> V_15 ) {
V_149 -> V_15 = F_28 ( V_160 ) ;
if ( V_149 -> V_15 == NULL )
return - V_47 ;
}
return 0 ;
}
int F_109 ( const char * V_167 , struct V_85 * V_86 )
{
char * * V_168 ;
int V_169 , V_58 , V_4 = 0 ;
V_168 = F_110 ( V_167 , & V_169 ) ;
if ( ! V_168 ) {
F_4 ( L_105 ) ;
return - V_47 ;
}
if ( V_169 - 1 > V_170 ) {
F_97 ( L_106 , V_169 - 1 ) ;
V_4 = - V_171 ;
goto V_11;
}
V_4 = F_101 ( V_168 [ 0 ] , V_86 ) ;
if ( V_4 < 0 )
goto V_11;
V_86 -> V_172 = V_169 - 1 ;
V_86 -> args = F_108 ( sizeof( struct V_159 ) * V_86 -> V_172 ) ;
if ( V_86 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_58 = 0 ; V_58 < V_86 -> V_172 && V_4 >= 0 ; V_58 ++ ) {
V_4 = F_105 ( V_168 [ V_58 + 1 ] , & V_86 -> args [ V_58 ] ) ;
if ( V_4 >= 0 &&
F_107 ( V_86 -> args [ V_58 ] . V_139 ) && V_86 -> V_88 . V_84 ) {
F_97 ( L_107
L_108 ) ;
V_4 = - V_48 ;
}
}
V_11:
F_111 ( V_168 ) ;
return V_4 ;
}
bool F_70 ( struct V_85 * V_86 )
{
int V_58 ;
if ( V_86 -> V_88 . V_52 || V_86 -> V_88 . line || V_86 -> V_88 . V_54 )
return true ;
for ( V_58 = 0 ; V_58 < V_86 -> V_172 ; V_58 ++ )
if ( F_107 ( V_86 -> args [ V_58 ] . V_139 ) ||
! strcmp ( V_86 -> args [ V_58 ] . V_139 , L_109 ) ||
! strcmp ( V_86 -> args [ V_58 ] . V_139 , L_110 ) )
return true ;
return false ;
}
int F_112 ( const char * V_167 , struct V_55 * V_173 )
{
struct V_106 * V_107 = & V_173 -> V_88 ;
char V_174 ;
char * V_175 ;
char * V_176 = NULL , * V_177 , * V_178 , * V_179 , * V_180 ;
int V_4 , V_58 , V_169 ;
char * * V_168 ;
F_4 ( L_111 , V_167 ) ;
V_168 = F_110 ( V_167 , & V_169 ) ;
if ( ! V_168 ) {
F_4 ( L_105 ) ;
return - V_47 ;
}
if ( V_169 < 2 ) {
F_97 ( L_112 ) ;
V_4 = - V_171 ;
goto V_11;
}
V_176 = F_28 ( V_168 [ 0 ] ) ;
if ( V_176 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
V_178 = strtok_r ( V_176 , L_113 , & V_177 ) ;
V_179 = strtok_r ( NULL , L_114 , & V_177 ) ;
V_180 = strtok_r ( NULL , L_115 , & V_177 ) ;
if ( V_178 == NULL || strlen ( V_178 ) != 1 || V_179 == NULL
|| V_180 == NULL ) {
F_97 ( L_116 , V_168 [ 0 ] ) ;
V_4 = - V_48 ;
goto V_11;
}
V_174 = V_178 [ 0 ] ;
V_173 -> V_154 = F_28 ( V_179 ) ;
V_173 -> V_155 = F_28 ( V_180 ) ;
if ( V_173 -> V_154 == NULL || V_173 -> V_155 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
F_4 ( L_117 , V_173 -> V_154 , V_173 -> V_155 , V_174 ) ;
V_107 -> V_84 = ( V_174 == 'r' ) ;
V_175 = strchr ( V_168 [ 1 ] , ':' ) ;
if ( V_175 ) {
V_107 -> V_29 = F_106 ( V_168 [ 1 ] , V_175 - V_168 [ 1 ] ) ;
if ( ! V_107 -> V_29 ) {
V_4 = - V_47 ;
goto V_11;
}
V_173 -> V_80 = ( V_107 -> V_29 [ 0 ] == '/' ) ;
V_175 ++ ;
} else
V_175 = V_168 [ 1 ] ;
V_178 = strtok_r ( V_175 , L_118 , & V_177 ) ;
if ( V_178 [ 0 ] == '0' ) {
if ( strcmp ( V_178 , L_73 ) == 0 ) {
if ( ! V_168 [ 2 ] || strcmp ( V_168 [ 2 ] , L_119 ) ) {
V_4 = - V_48 ;
goto V_11;
}
V_107 -> V_59 = 0 ;
free ( V_168 [ 2 ] ) ;
for ( V_58 = 2 ; V_168 [ V_58 + 1 ] != NULL ; V_58 ++ )
V_168 [ V_58 ] = V_168 [ V_58 + 1 ] ;
V_168 [ V_58 ] = NULL ;
V_169 -= 1 ;
} else
V_107 -> V_59 = strtoul ( V_178 , NULL , 0 ) ;
} else {
V_107 -> V_14 = F_28 ( V_178 ) ;
if ( V_107 -> V_14 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
V_179 = strtok_r ( NULL , L_36 , & V_177 ) ;
if ( V_179 == NULL )
V_107 -> V_83 = 0 ;
else
V_107 -> V_83 = strtoul ( V_179 , NULL , 10 ) ;
}
V_173 -> V_172 = V_169 - 2 ;
V_173 -> args = F_108 ( sizeof( struct V_181 ) * V_173 -> V_172 ) ;
if ( V_173 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_58 = 0 ; V_58 < V_173 -> V_172 ; V_58 ++ ) {
V_175 = strchr ( V_168 [ V_58 + 2 ] , '=' ) ;
if ( V_175 )
* V_175 ++ = '\0' ;
else
V_175 = V_168 [ V_58 + 2 ] ;
V_173 -> args [ V_58 ] . V_15 = F_28 ( V_168 [ V_58 + 2 ] ) ;
V_173 -> args [ V_58 ] . V_182 = F_28 ( V_175 ) ;
if ( V_173 -> args [ V_58 ] . V_15 == NULL || V_173 -> args [ V_58 ] . V_182 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
free ( V_176 ) ;
F_111 ( V_168 ) ;
return V_4 ;
}
char * F_113 ( struct V_159 * V_183 )
{
struct V_161 * V_163 = V_183 -> V_163 ;
struct V_184 V_46 ;
char * V_4 = NULL ;
int V_98 ;
if ( F_114 ( & V_46 , 64 ) < 0 )
return NULL ;
if ( V_183 -> V_15 && V_183 -> V_139 )
V_98 = F_115 ( & V_46 , L_120 , V_183 -> V_15 , V_183 -> V_139 ) ;
else
V_98 = F_116 ( & V_46 , V_183 -> V_15 ? : V_183 -> V_139 ) ;
if ( V_98 )
goto V_11;
while ( V_163 ) {
if ( V_163 -> V_15 [ 0 ] == '[' )
V_98 = F_116 ( & V_46 , V_163 -> V_15 ) ;
else
V_98 = F_115 ( & V_46 , L_121 , V_163 -> V_165 ? L_122 : L_123 ,
V_163 -> V_15 ) ;
V_163 = V_163 -> V_166 ;
if ( V_98 )
goto V_11;
}
if ( V_183 -> type )
if ( F_115 ( & V_46 , L_124 , V_183 -> type ) < 0 )
goto V_11;
V_4 = F_117 ( & V_46 , NULL ) ;
V_11:
F_118 ( & V_46 ) ;
return V_4 ;
}
char * F_72 ( struct V_50 * V_51 )
{
struct V_184 V_46 ;
char * V_87 , * V_4 = NULL ;
int V_91 , V_98 = 0 ;
if ( F_114 ( & V_46 , 64 ) < 0 )
return NULL ;
if ( V_51 -> V_53 ) {
if ( F_116 ( & V_46 , V_51 -> V_53 ) < 0 )
goto V_11;
if ( V_51 -> V_83 )
V_98 = F_115 ( & V_46 , L_125 , V_51 -> V_83 ) ;
else if ( V_51 -> line )
V_98 = F_115 ( & V_46 , L_126 , V_51 -> line ) ;
else if ( V_51 -> V_84 )
V_98 = F_116 ( & V_46 , L_127 ) ;
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
V_98 = F_115 ( & V_46 , L_128 , V_87 ) ;
if ( ! V_98 && ! V_51 -> V_53 && V_51 -> line )
V_98 = F_115 ( & V_46 , L_126 , V_51 -> line ) ;
}
if ( ! V_98 )
V_4 = F_117 ( & V_46 , NULL ) ;
V_11:
F_118 ( & V_46 ) ;
return V_4 ;
}
char * F_119 ( struct V_85 * V_86 )
{
struct V_184 V_46 ;
char * V_87 , * V_4 = NULL ;
int V_58 ;
if ( F_114 ( & V_46 , 64 ) )
return NULL ;
if ( V_86 -> V_155 )
if ( F_115 ( & V_46 , L_129 , V_86 -> V_154 ? : V_49 ,
V_86 -> V_155 ) < 0 )
goto V_11;
V_87 = F_72 ( & V_86 -> V_88 ) ;
if ( ! V_87 || F_116 ( & V_46 , V_87 ) < 0 )
goto V_11;
free ( V_87 ) ;
for ( V_58 = 0 ; V_58 < V_86 -> V_172 ; V_58 ++ ) {
V_87 = F_113 ( V_86 -> args + V_58 ) ;
if ( ! V_87 || F_115 ( & V_46 , L_130 , V_87 ) < 0 )
goto V_11;
free ( V_87 ) ;
}
V_4 = F_117 ( & V_46 , NULL ) ;
V_11:
F_118 ( & V_46 ) ;
return V_4 ;
}
static int F_120 ( struct V_185 * V_165 ,
struct V_184 * V_46 , int V_186 )
{
int V_98 ;
if ( V_165 -> V_166 ) {
V_186 = F_120 ( V_165 -> V_166 , V_46 ,
V_186 + 1 ) ;
if ( V_186 < 0 )
return V_186 ;
}
V_98 = F_115 ( V_46 , L_131 , V_165 -> V_83 ) ;
return ( V_98 < 0 ) ? V_98 : V_186 ;
}
static int F_121 ( struct V_181 * V_149 ,
struct V_184 * V_46 )
{
struct V_185 * V_165 = V_149 -> V_165 ;
int V_186 = 0 , V_98 ;
if ( V_149 -> V_15 )
V_98 = F_115 ( V_46 , L_132 , V_149 -> V_15 ) ;
else
V_98 = F_122 ( V_46 , ' ' ) ;
if ( V_98 )
return V_98 ;
if ( V_149 -> V_182 [ 0 ] == '@' && V_149 -> V_165 )
V_165 = V_165 -> V_166 ;
if ( V_165 ) {
V_186 = F_120 ( V_165 , V_46 , 1 ) ;
if ( V_186 < 0 )
return V_186 ;
}
if ( V_149 -> V_182 [ 0 ] == '@' && V_149 -> V_165 )
V_98 = F_115 ( V_46 , L_133 , V_149 -> V_182 , V_149 -> V_165 -> V_83 ) ;
else
V_98 = F_116 ( V_46 , V_149 -> V_182 ) ;
while ( ! V_98 && V_186 -- )
V_98 = F_122 ( V_46 , ')' ) ;
if ( ! V_98 && V_149 -> type )
V_98 = F_115 ( V_46 , L_124 , V_149 -> type ) ;
return V_98 ;
}
char * F_123 ( struct V_55 * V_173 )
{
struct V_106 * V_107 = & V_173 -> V_88 ;
struct V_184 V_46 ;
char * V_4 = NULL ;
int V_58 , V_98 ;
if ( V_173 -> V_80 && ! V_107 -> V_29 )
return NULL ;
if ( F_114 ( & V_46 , 32 ) < 0 )
return NULL ;
if ( F_115 ( & V_46 , L_134 , V_107 -> V_84 ? 'r' : 'p' ,
V_173 -> V_154 , V_173 -> V_155 ) < 0 )
goto error;
if ( V_173 -> V_80 && ! V_107 -> V_59 ) {
if ( ! V_107 -> V_14 || strcmp ( V_107 -> V_14 , L_135 ) )
goto error;
}
if ( V_173 -> V_80 )
V_98 = F_115 ( & V_46 , L_136 , V_107 -> V_29 , V_107 -> V_59 ) ;
else if ( ! strncmp ( V_107 -> V_14 , L_73 , 2 ) )
V_98 = F_115 ( & V_46 , L_137 , V_107 -> V_29 ? : L_36 ,
V_107 -> V_29 ? L_113 : L_36 , V_107 -> V_59 ) ;
else
V_98 = F_115 ( & V_46 , L_138 , V_107 -> V_29 ? : L_36 ,
V_107 -> V_29 ? L_113 : L_36 , V_107 -> V_14 , V_107 -> V_83 ) ;
if ( V_98 )
goto error;
for ( V_58 = 0 ; V_58 < V_173 -> V_172 ; V_58 ++ )
if ( F_121 ( & V_173 -> args [ V_58 ] , & V_46 ) < 0 )
goto error;
V_4 = F_117 ( & V_46 , NULL ) ;
error:
F_118 ( & V_46 ) ;
return V_4 ;
}
static int F_124 ( struct V_106 * V_107 ,
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
V_24 = F_125 ( V_16 , V_18 , NULL ) ;
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
static int F_126 ( struct V_106 * V_107 ,
struct V_50 * V_51 ,
bool V_108 )
{
char V_46 [ 128 ] ;
int V_4 ;
V_4 = F_63 ( V_107 , V_51 , V_108 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_124 ( V_107 , V_51 , V_108 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( L_139 ) ;
if ( V_107 -> V_14 ) {
V_51 -> V_53 = F_28 ( V_107 -> V_14 ) ;
V_51 -> V_83 = V_107 -> V_83 ;
} else {
V_4 = F_1 ( V_46 , 128 , L_140 V_82 , ( T_3 ) V_107 -> V_59 ) ;
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
static int F_127 ( struct V_55 * V_173 ,
struct V_85 * V_86 , bool V_108 )
{
struct V_184 V_46 = V_187 ;
int V_58 , V_4 ;
V_86 -> V_155 = F_28 ( V_173 -> V_155 ) ;
V_86 -> V_154 = F_28 ( V_173 -> V_154 ) ;
if ( V_86 -> V_155 == NULL || V_86 -> V_154 == NULL )
return - V_47 ;
V_4 = F_126 ( & V_173 -> V_88 , & V_86 -> V_88 , V_108 ) ;
if ( V_4 < 0 )
return V_4 ;
V_86 -> V_172 = V_173 -> V_172 ;
V_86 -> args = F_108 ( sizeof( struct V_159 ) * V_86 -> V_172 ) ;
if ( V_86 -> args == NULL )
return - V_47 ;
for ( V_58 = 0 ; V_58 < V_173 -> V_172 && V_4 >= 0 ; V_58 ++ ) {
if ( V_173 -> args [ V_58 ] . V_15 )
V_86 -> args [ V_58 ] . V_15 = F_28 ( V_173 -> args [ V_58 ] . V_15 ) ;
else {
if ( ( V_4 = F_114 ( & V_46 , 32 ) ) < 0 )
goto error;
V_4 = F_121 ( & V_173 -> args [ V_58 ] , & V_46 ) ;
V_86 -> args [ V_58 ] . V_15 = F_117 ( & V_46 , NULL ) ;
}
if ( V_86 -> args [ V_58 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_47 ;
}
error:
if ( V_4 < 0 )
F_128 ( V_86 ) ;
return V_4 ;
}
void F_128 ( struct V_85 * V_86 )
{
struct V_161 * V_163 , * V_166 ;
int V_58 ;
free ( V_86 -> V_155 ) ;
free ( V_86 -> V_154 ) ;
free ( V_86 -> V_39 ) ;
F_30 ( & V_86 -> V_88 ) ;
for ( V_58 = 0 ; V_58 < V_86 -> V_172 ; V_58 ++ ) {
free ( V_86 -> args [ V_58 ] . V_15 ) ;
free ( V_86 -> args [ V_58 ] . V_139 ) ;
free ( V_86 -> args [ V_58 ] . type ) ;
V_163 = V_86 -> args [ V_58 ] . V_163 ;
while ( V_163 ) {
V_166 = V_163 -> V_166 ;
F_60 ( & V_163 -> V_15 ) ;
free ( V_163 ) ;
V_163 = V_166 ;
}
}
free ( V_86 -> args ) ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
}
static int F_129 ( struct V_50 * V_188 ,
struct V_50 * V_189 )
{
V_188 -> V_52 = F_130 ( V_189 -> V_52 , V_190 ) ;
V_188 -> V_53 = F_130 ( V_189 -> V_53 , V_190 ) ;
V_188 -> V_54 = F_130 ( V_189 -> V_54 , V_190 ) ;
V_188 -> line = V_189 -> line ;
V_188 -> V_84 = V_189 -> V_84 ;
V_188 -> V_83 = V_189 -> V_83 ;
return 0 ;
V_190:
F_30 ( V_188 ) ;
return - V_47 ;
}
static int F_131 ( struct V_159 * V_188 ,
struct V_159 * V_189 )
{
struct V_161 * V_163 , * * V_191 ;
V_188 -> V_15 = F_130 ( V_189 -> V_15 , V_190 ) ;
V_188 -> V_139 = F_130 ( V_189 -> V_139 , V_190 ) ;
V_188 -> type = F_130 ( V_189 -> type , V_190 ) ;
V_163 = V_189 -> V_163 ;
V_191 = & ( V_188 -> V_163 ) ;
while ( V_163 ) {
* V_191 = F_108 ( sizeof( * V_163 ) ) ;
if ( ! * V_191 )
goto V_190;
( * V_191 ) -> V_15 = F_130 ( V_163 -> V_15 , V_190 ) ;
( * V_191 ) -> V_164 = V_163 -> V_164 ;
( * V_191 ) -> V_165 = V_163 -> V_165 ;
V_163 = V_163 -> V_166 ;
V_191 = & ( ( * V_191 ) -> V_166 ) ;
}
return 0 ;
V_190:
return - V_47 ;
}
int F_132 ( struct V_85 * V_188 ,
struct V_85 * V_189 )
{
int V_58 ;
V_188 -> V_155 = F_130 ( V_189 -> V_155 , V_190 ) ;
V_188 -> V_154 = F_130 ( V_189 -> V_154 , V_190 ) ;
V_188 -> V_39 = F_130 ( V_189 -> V_39 , V_190 ) ;
V_188 -> V_80 = V_189 -> V_80 ;
if ( F_129 ( & V_188 -> V_88 , & V_189 -> V_88 ) < 0 )
goto V_190;
V_188 -> args = F_108 ( sizeof( struct V_159 ) * V_189 -> V_172 ) ;
if ( ! V_188 -> args )
goto V_190;
V_188 -> V_172 = V_189 -> V_172 ;
for ( V_58 = 0 ; V_58 < V_189 -> V_172 ; V_58 ++ )
if ( F_131 ( & V_188 -> args [ V_58 ] , & V_189 -> args [ V_58 ] ) < 0 )
goto V_190;
return 0 ;
V_190:
F_128 ( V_188 ) ;
return - V_47 ;
}
void F_32 ( struct V_55 * V_173 )
{
struct V_185 * V_165 , * V_166 ;
int V_58 ;
free ( V_173 -> V_155 ) ;
free ( V_173 -> V_154 ) ;
free ( V_173 -> V_88 . V_14 ) ;
free ( V_173 -> V_88 . V_112 ) ;
free ( V_173 -> V_88 . V_29 ) ;
for ( V_58 = 0 ; V_58 < V_173 -> V_172 ; V_58 ++ ) {
free ( V_173 -> args [ V_58 ] . V_15 ) ;
free ( V_173 -> args [ V_58 ] . V_182 ) ;
free ( V_173 -> args [ V_58 ] . type ) ;
V_165 = V_173 -> args [ V_58 ] . V_165 ;
while ( V_165 ) {
V_166 = V_165 -> V_166 ;
free ( V_165 ) ;
V_165 = V_166 ;
}
}
free ( V_173 -> args ) ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
}
static void F_133 ( struct V_192 * V_193 )
{
struct V_194 * V_135 ;
while ( ! F_134 ( V_193 ) ) {
V_135 = F_135 ( V_193 ,
struct V_194 , V_195 ) ;
F_136 ( & V_135 -> V_195 ) ;
free ( V_135 -> V_14 ) ;
free ( V_135 ) ;
}
}
static int F_137 ( struct V_192 * V_193 )
{
struct V_194 * V_135 ;
const char * V_196 = F_138 () ;
char V_46 [ V_197 ] , * V_175 ;
T_9 * V_117 ;
int V_4 ;
if ( V_196 == NULL )
return - V_81 ;
V_4 = F_1 ( V_46 , V_197 , L_141 , V_196 ) ;
if ( V_4 < 0 )
return V_4 ;
V_117 = fopen ( V_46 , L_47 ) ;
if ( ! V_117 )
return - V_102 ;
V_4 = 0 ;
while ( fgets ( V_46 , V_197 , V_117 ) ) {
V_135 = F_108 ( sizeof( * V_135 ) ) ;
if ( ! V_135 ) {
V_4 = - V_47 ;
break;
}
F_139 ( & V_135 -> V_195 ) ;
F_140 ( & V_135 -> V_195 , V_193 ) ;
if ( sscanf ( V_46 , L_142 , & V_135 -> V_28 , & V_135 -> V_92 ) != 2 ) {
V_4 = - V_48 ;
break;
}
V_175 = strchr ( V_46 , '\t' ) ;
if ( V_175 ) {
V_175 ++ ;
if ( V_175 [ strlen ( V_175 ) - 1 ] == '\n' )
V_175 [ strlen ( V_175 ) - 1 ] = '\0' ;
} else
V_175 = ( char * ) L_143 ;
V_135 -> V_14 = F_28 ( V_175 ) ;
if ( ! V_135 -> V_14 ) {
V_4 = - V_47 ;
break;
}
F_141 ( L_144 ,
V_135 -> V_28 , V_135 -> V_92 , V_135 -> V_14 ) ;
V_4 ++ ;
}
if ( V_4 < 0 )
F_133 ( V_193 ) ;
fclose ( V_117 ) ;
return V_4 ;
}
static struct V_194 *
F_142 ( struct V_192 * V_193 ,
unsigned long V_59 )
{
struct V_194 * V_135 ;
F_143 (node, blacklist, list) {
if ( V_135 -> V_28 <= V_59 && V_59 <= V_135 -> V_92 )
return V_135 ;
}
return NULL ;
}
static void F_144 ( void )
{
if ( ! F_134 ( & V_198 ) )
return;
if ( F_137 ( & V_198 ) < 0 )
F_4 ( L_145 ) ;
}
static void F_145 ( void )
{
F_133 ( & V_198 ) ;
}
static bool F_34 ( unsigned long V_59 )
{
return ! ! F_142 ( & V_198 , V_59 ) ;
}
static int F_146 ( const char * V_154 , const char * V_155 ,
struct V_85 * V_86 ,
const char * V_29 ,
struct V_184 * V_42 )
{
int V_58 , V_4 ;
char * V_46 ;
if ( F_104 ( & V_46 , L_146 , V_154 , V_155 ) < 0 )
return - V_102 ;
V_4 = F_115 ( V_42 , L_147 , V_46 ) ;
free ( V_46 ) ;
if ( V_4 )
return V_4 ;
V_46 = F_72 ( & V_86 -> V_88 ) ;
if ( ! V_46 )
return - V_47 ;
V_4 = F_116 ( V_42 , V_46 ) ;
free ( V_46 ) ;
if ( ! V_4 && V_29 )
V_4 = F_115 ( V_42 , L_148 , V_29 ) ;
if ( ! V_4 && V_86 -> V_172 > 0 ) {
V_4 = F_147 ( V_42 , L_149 , 5 ) ;
for ( V_58 = 0 ; ! V_4 && V_58 < V_86 -> V_172 ; V_58 ++ ) {
V_46 = F_113 ( & V_86 -> args [ V_58 ] ) ;
if ( ! V_46 )
return - V_47 ;
V_4 = F_115 ( V_42 , L_130 , V_46 ) ;
free ( V_46 ) ;
}
}
if ( ! V_4 )
V_4 = F_122 ( V_42 , ')' ) ;
return V_4 ;
}
int F_148 ( const char * V_154 , const char * V_155 ,
struct V_85 * V_86 ,
const char * V_29 , bool V_199 )
{
struct V_184 V_46 = V_187 ;
int V_4 ;
V_4 = F_146 ( V_154 , V_155 , V_86 , V_29 , & V_46 ) ;
if ( V_4 >= 0 ) {
if ( V_199 )
printf ( L_98 , V_46 . V_46 ) ;
else
F_149 ( L_98 , V_46 . V_46 ) ;
}
F_118 ( & V_46 ) ;
return V_4 ;
}
static bool F_150 ( struct V_55 * V_173 ,
struct V_131 * T_10 )
{
char V_87 [ 128 ] ;
if ( F_89 ( T_10 , V_173 -> V_155 ) )
return true ;
if ( F_1 ( V_87 , 128 , L_146 , V_173 -> V_154 , V_173 -> V_155 ) < 0 )
return false ;
return F_89 ( T_10 , V_87 ) ;
}
static int F_151 ( int V_61 , bool V_108 ,
struct V_131 * T_10 )
{
int V_4 = 0 ;
struct V_55 V_173 ;
struct V_85 V_86 ;
struct V_200 * V_201 ;
struct V_134 * V_202 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_201 = F_152 ( V_61 ) ;
if ( ! V_201 )
return - V_47 ;
F_88 (ent, rawlist) {
V_4 = F_112 ( V_202 -> V_141 , & V_173 ) ;
if ( V_4 >= 0 ) {
if ( ! F_150 ( & V_173 , T_10 ) )
goto V_166;
V_4 = F_127 ( & V_173 , & V_86 ,
V_108 ) ;
if ( V_4 < 0 )
goto V_166;
V_4 = F_148 ( V_86 . V_154 , V_86 . V_155 ,
& V_86 , V_173 . V_88 . V_29 ,
true ) ;
}
V_166:
F_128 ( & V_86 ) ;
F_32 ( & V_173 ) ;
if ( V_4 < 0 )
break;
}
F_90 ( V_201 ) ;
F_61 () ;
return V_4 ;
}
int F_153 ( struct V_131 * T_10 )
{
int V_203 , V_204 , V_4 ;
F_79 () ;
if ( V_205 . V_206 )
return F_154 ( T_10 ) ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_155 ( & V_203 , & V_204 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_203 >= 0 )
V_4 = F_151 ( V_203 , true , T_10 ) ;
if ( V_204 >= 0 && V_4 >= 0 )
V_4 = F_151 ( V_204 , false , T_10 ) ;
if ( V_203 > 0 )
F_42 ( V_203 ) ;
if ( V_204 > 0 )
F_42 ( V_204 ) ;
F_8 () ;
return V_4 ;
}
static int F_156 ( char * V_46 , T_1 V_91 , const char * V_207 ,
struct V_200 * V_208 , bool V_209 )
{
int V_58 , V_4 ;
char * V_175 , * V_210 ;
if ( * V_207 == '.' )
V_207 ++ ;
V_210 = F_28 ( V_207 ) ;
if ( ! V_210 )
return - V_47 ;
V_175 = strchr ( V_210 , '.' ) ;
if ( V_175 && V_175 != V_210 )
* V_175 = '\0' ;
V_4 = F_1 ( V_46 , V_91 , L_39 , V_210 ) ;
if ( V_4 < 0 ) {
F_4 ( L_150 , V_4 ) ;
goto V_11;
}
if ( ! F_157 ( V_208 , V_46 ) )
goto V_11;
if ( ! V_209 ) {
F_7 ( L_151
L_152
L_153
L_154 ,
V_46 ) ;
V_4 = - V_211 ;
goto V_11;
}
for ( V_58 = 1 ; V_58 < V_212 ; V_58 ++ ) {
V_4 = F_1 ( V_46 , V_91 , L_155 , V_210 , V_58 ) ;
if ( V_4 < 0 ) {
F_4 ( L_150 , V_4 ) ;
goto V_11;
}
if ( ! F_157 ( V_208 , V_46 ) )
break;
}
if ( V_58 == V_212 ) {
F_7 ( L_156 ) ;
V_4 = - V_171 ;
}
V_11:
free ( V_210 ) ;
return V_4 ;
}
static void F_158 ( struct V_55 * V_173 )
{
int V_58 ;
char * V_46 = F_123 ( V_173 ) ;
if ( ! V_173 -> V_80 || V_173 -> V_172 == 0 || ! V_46 )
goto V_11;
for ( V_58 = 0 ; V_58 < V_173 -> V_172 ; V_58 ++ )
if ( F_159 ( V_173 -> args [ V_58 ] . V_182 , L_157 ) ) {
F_7 ( L_158
L_159 ,
V_173 -> args [ V_58 ] . V_182 ) ;
break;
}
V_11:
free ( V_46 ) ;
}
static int F_160 ( struct V_55 * V_173 ,
struct V_85 * V_86 ,
struct V_200 * V_208 ,
bool V_209 )
{
const char * V_155 , * V_154 ;
char V_46 [ 64 ] ;
int V_4 ;
if ( V_86 -> V_155 && ! V_86 -> V_152 )
V_155 = V_86 -> V_155 ;
else if ( V_173 -> V_155 )
V_155 = V_173 -> V_155 ;
else {
if ( V_86 -> V_88 . V_53 &&
( strncmp ( V_86 -> V_88 . V_53 , L_73 , 2 ) != 0 ) &&
! F_161 ( V_86 -> V_88 . V_53 ) )
V_155 = V_86 -> V_88 . V_53 ;
else
V_155 = V_173 -> V_88 . V_112 ;
}
if ( V_86 -> V_154 && ! V_86 -> V_152 )
V_154 = V_86 -> V_154 ;
else if ( V_173 -> V_154 )
V_154 = V_173 -> V_154 ;
else
V_154 = V_49 ;
V_4 = F_156 ( V_46 , 64 , V_155 ,
V_208 , V_209 ) ;
if ( V_4 < 0 )
return V_4 ;
V_155 = V_46 ;
V_173 -> V_155 = F_28 ( V_155 ) ;
V_173 -> V_154 = F_28 ( V_154 ) ;
if ( V_173 -> V_155 == NULL || V_173 -> V_154 == NULL )
return - V_47 ;
F_162 ( V_208 , V_155 ) ;
return 0 ;
}
static int F_163 ( bool V_114 ,
struct V_200 * * V_208 )
{
int V_61 ;
V_61 = F_164 ( V_213 | ( V_114 ? V_214 : 0 ) ) ;
if ( V_61 < 0 )
return V_61 ;
* V_208 = F_165 ( V_61 ) ;
if ( ! ( * V_208 ) ) {
F_4 ( L_160 ) ;
F_42 ( V_61 ) ;
return - V_47 ;
}
return V_61 ;
}
static int F_166 ( struct V_85 * V_86 ,
struct V_55 * V_56 ,
int V_57 , bool V_209 )
{
int V_58 , V_61 [ 2 ] = { - 1 , - 1 } , V_215 , V_4 ;
struct V_55 * V_173 = NULL ;
struct V_216 * V_206 = NULL ;
struct V_200 * V_208 [ 2 ] = { NULL , NULL } ;
V_215 = V_86 -> V_80 ? 1 : 0 ;
V_61 [ V_215 ] = F_163 ( V_215 , & V_208 [ V_215 ] ) ;
if ( V_61 [ V_215 ] < 0 )
return V_61 [ V_215 ] ;
V_4 = 0 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_173 = & V_56 [ V_58 ] ;
V_215 = V_173 -> V_80 ? 1 : 0 ;
if ( V_61 [ V_215 ] == - 1 ) {
V_61 [ V_215 ] = F_163 ( V_215 ,
& V_208 [ V_215 ] ) ;
if ( V_61 [ V_215 ] < 0 )
goto V_217;
}
if ( ! V_173 -> V_88 . V_14 && ! V_86 -> V_80 )
continue;
V_4 = F_160 ( V_173 , V_86 , V_208 [ V_215 ] ,
V_209 ) ;
if ( V_4 < 0 )
break;
V_4 = F_167 ( V_61 [ V_215 ] , V_173 ) ;
if ( V_4 < 0 )
break;
V_209 = true ;
}
if ( V_4 == - V_48 && V_86 -> V_80 )
F_158 ( V_173 ) ;
if ( V_4 == 0 && V_205 . V_206 ) {
V_206 = F_168 ( V_86 -> V_39 ) ;
if ( ! V_206 ||
F_169 ( V_206 , V_86 , V_56 , V_57 ) < 0 ||
F_170 ( V_206 ) < 0 )
F_7 ( L_161 ) ;
F_171 ( V_206 ) ;
}
V_217:
for ( V_215 = 0 ; V_215 < 2 ; V_215 ++ ) {
F_90 ( V_208 [ V_215 ] ) ;
if ( V_61 [ V_215 ] >= 0 )
F_42 ( V_61 [ V_215 ] ) ;
}
return V_4 ;
}
static int F_172 ( struct V_16 * V_16 , char * V_15 ,
struct V_14 * * V_218 )
{
int V_76 = 0 ;
struct V_14 * V_24 ;
struct V_219 * V_87 ;
if ( F_16 ( V_16 , NULL ) < 0 )
return 0 ;
F_173 (map, sym, tmp) {
if ( F_159 ( V_24 -> V_15 , V_15 ) ) {
V_76 ++ ;
if ( V_218 && V_76 < V_205 . V_220 )
V_218 [ V_76 - 1 ] = V_24 ;
}
}
return V_76 ;
}
void __weak F_174 ( struct V_85 * V_86 V_113 ,
struct V_55 * V_173 V_113 ,
struct V_16 * V_16 V_113 ,
struct V_14 * V_24 V_113 ) { }
static int F_175 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_16 * V_16 = NULL ;
struct V_19 * V_23 = NULL ;
struct V_14 * V_24 ;
struct V_14 * * V_218 = NULL ;
struct V_55 * V_173 ;
struct V_50 * V_51 = & V_86 -> V_88 ;
struct V_106 * V_107 ;
int V_221 ;
int V_4 , V_58 , V_222 , V_111 = 0 ;
char * V_67 ;
V_16 = F_23 ( V_86 -> V_39 , V_86 -> V_80 ) ;
if ( ! V_16 ) {
V_4 = - V_48 ;
goto V_11;
}
V_218 = malloc ( sizeof( struct V_14 * ) * V_205 . V_220 ) ;
if ( ! V_218 ) {
V_4 = - V_47 ;
goto V_11;
}
V_221 = F_172 ( V_16 , V_51 -> V_53 , V_218 ) ;
if ( V_221 == 0 ) {
F_55 ( L_162 , V_51 -> V_53 ,
V_86 -> V_39 ? : L_5 ) ;
V_4 = - V_26 ;
goto V_11;
} else if ( V_221 > V_205 . V_220 ) {
F_55 ( L_163 ,
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
* V_56 = F_108 ( sizeof( * V_173 ) * V_221 ) ;
if ( ! * V_56 ) {
V_4 = - V_47 ;
goto V_11;
}
V_4 = 0 ;
for ( V_222 = 0 ; V_222 < V_221 ; V_222 ++ ) {
V_24 = V_218 [ V_222 ] ;
V_173 = ( * V_56 ) + V_4 ;
V_107 = & V_173 -> V_88 ;
if ( V_4 == V_221 ) {
F_7 ( L_164 ) ;
break;
}
V_4 ++ ;
if ( V_51 -> V_83 > V_24 -> V_92 - V_24 -> V_28 ) {
F_7 ( L_165 ,
V_51 -> V_83 , V_24 -> V_15 ) ;
V_4 = - V_26 ;
goto V_223;
}
V_107 -> V_59 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) + V_51 -> V_83 ;
if ( ! V_86 -> V_80 && ! V_86 -> V_39 &&
F_33 ( V_24 -> V_15 , V_107 -> V_59 ) ) {
V_107 -> V_14 = NULL ;
V_111 ++ ;
} else if ( V_23 ) {
V_107 -> V_14 = F_130 ( V_23 -> V_15 , V_224 ) ;
V_107 -> V_83 = V_107 -> V_59 - V_23 -> V_18 ;
} else {
V_107 -> V_14 = F_130 ( V_24 -> V_15 , V_224 ) ;
V_107 -> V_83 = V_51 -> V_83 ;
}
V_107 -> V_112 = F_130 ( V_24 -> V_15 , V_224 ) ;
V_107 -> V_84 = V_51 -> V_84 ;
if ( V_86 -> V_39 ) {
if ( V_86 -> V_80 ) {
V_173 -> V_88 . V_29 = F_130 ( V_86 -> V_39 ,
V_224 ) ;
} else {
V_67 = F_35 ( V_86 -> V_39 ) ;
V_173 -> V_88 . V_29 =
F_28 ( V_67 ? V_67 : V_86 -> V_39 ) ;
free ( V_67 ) ;
if ( ! V_173 -> V_88 . V_29 )
goto V_224;
}
}
V_173 -> V_80 = V_86 -> V_80 ;
V_173 -> V_172 = V_86 -> V_172 ;
if ( V_173 -> V_172 ) {
V_173 -> args = F_108 ( sizeof( struct V_181 ) *
V_173 -> V_172 ) ;
if ( V_173 -> args == NULL )
goto V_224;
}
for ( V_58 = 0 ; V_58 < V_173 -> V_172 ; V_58 ++ ) {
if ( V_86 -> args [ V_58 ] . V_15 )
V_173 -> args [ V_58 ] . V_15 =
F_130 ( V_86 -> args [ V_58 ] . V_15 ,
V_224 ) ;
V_173 -> args [ V_58 ] . V_182 = F_130 ( V_86 -> args [ V_58 ] . V_139 ,
V_224 ) ;
if ( V_86 -> args [ V_58 ] . type )
V_173 -> args [ V_58 ] . type =
F_130 ( V_86 -> args [ V_58 ] . type ,
V_224 ) ;
}
F_174 ( V_86 , V_173 , V_16 , V_24 ) ;
}
if ( V_4 == V_111 ) {
V_4 = - V_26 ;
goto V_223;
}
V_11:
F_25 ( V_16 , V_86 -> V_80 ) ;
free ( V_218 ) ;
return V_4 ;
V_224:
V_4 = - V_47 ;
V_223:
F_31 ( * V_56 , V_221 ) ;
F_60 ( V_56 ) ;
goto V_11;
}
static int F_176 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_50 * V_51 = & V_86 -> V_88 ;
struct V_55 * V_173 ;
struct V_106 * V_107 ;
int V_58 , V_98 ;
if ( ! ( V_86 -> V_88 . V_53 && ! strncmp ( V_86 -> V_88 . V_53 , L_73 , 2 ) ) )
return - V_48 ;
if ( F_70 ( V_86 ) )
return - V_48 ;
* V_56 = F_108 ( sizeof( * V_173 ) ) ;
if ( ! * V_56 )
return - V_47 ;
V_173 = * V_56 ;
V_107 = & V_173 -> V_88 ;
V_107 -> V_59 = V_86 -> V_88 . V_158 ;
V_107 -> V_84 = V_51 -> V_84 ;
V_173 -> V_80 = V_86 -> V_80 ;
V_98 = - V_47 ;
if ( F_104 ( & V_107 -> V_14 , L_166 , V_107 -> V_59 ) < 0 )
goto V_225;
if ( ( ! V_173 -> V_80 ) &&
( F_33 ( V_173 -> V_88 . V_14 ,
V_173 -> V_88 . V_59 ) ) ) {
V_98 = - V_226 ;
goto V_225;
}
if ( F_104 ( & V_107 -> V_112 , L_167 , V_107 -> V_59 ) < 0 )
goto V_225;
if ( V_86 -> V_39 ) {
V_107 -> V_29 = F_28 ( V_86 -> V_39 ) ;
if ( ! V_107 -> V_29 )
goto V_225;
}
if ( V_173 -> V_154 ) {
V_173 -> V_154 = F_28 ( V_86 -> V_154 ) ;
if ( ! V_173 -> V_154 )
goto V_225;
}
if ( V_86 -> V_155 ) {
V_173 -> V_155 = F_28 ( V_86 -> V_155 ) ;
if ( ! V_173 -> V_155 )
goto V_225;
}
V_173 -> V_172 = V_86 -> V_172 ;
V_173 -> args = F_108 ( sizeof( struct V_181 ) * V_173 -> V_172 ) ;
if ( ! V_173 -> args ) {
V_98 = - V_47 ;
goto V_225;
}
for ( V_58 = 0 ; V_58 < V_173 -> V_172 ; V_58 ++ )
F_177 ( & V_173 -> args [ V_58 ] , & V_86 -> args [ V_58 ] ) ;
return 1 ;
V_225:
if ( * V_56 ) {
F_31 ( * V_56 , 1 ) ;
* V_56 = NULL ;
}
return V_98 ;
}
static void * F_178 ( void * V_227 , T_1 V_228 , void * V_229 , T_1 V_230 )
{
void * V_4 ;
V_4 = malloc ( V_228 + V_230 ) ;
if ( V_4 ) {
memcpy ( V_4 , V_227 , V_228 ) ;
memcpy ( V_4 + V_228 , V_229 , V_230 ) ;
}
return V_4 ;
}
static int
F_179 ( struct V_55 * * V_56 , int * V_57 ,
struct V_55 * * V_231 , int V_232 )
{
struct V_55 * V_233 ;
int V_4 = 0 ;
if ( V_57 == 0 ) {
* V_56 = * V_231 ;
* V_57 = V_232 ;
* V_231 = NULL ;
return 0 ;
}
if ( * V_57 + V_232 > V_205 . V_220 )
V_4 = - V_6 ;
else {
V_233 = F_178 ( * V_56 , ( * V_57 ) * sizeof( * * V_56 ) ,
* V_231 , V_232 * sizeof( * * V_231 ) ) ;
if ( ! V_233 )
V_4 = - V_47 ;
else {
free ( * V_56 ) ;
* V_56 = V_233 ;
* V_57 += V_232 ;
}
}
if ( V_4 < 0 )
F_31 ( * V_231 , V_232 ) ;
F_60 ( V_231 ) ;
return V_4 ;
}
static int F_180 ( struct V_85 * V_86 ,
struct V_55 * * V_56 ,
const char * V_39 )
{
struct V_216 * V_206 ;
struct V_234 * V_235 ;
struct V_55 * V_236 = NULL ;
int V_57 = 0 ;
int V_4 = 0 ;
V_206 = F_168 ( V_39 ) ;
if ( ! V_206 )
return 0 ;
F_181 (entry, cache) {
if ( ! V_235 -> V_86 . V_155 || ! V_235 -> V_86 . V_154 )
continue;
if ( ( ! V_86 -> V_154 || F_159 ( V_235 -> V_86 . V_154 , V_86 -> V_154 ) ) &&
F_159 ( V_235 -> V_86 . V_155 , V_86 -> V_155 ) ) {
V_4 = F_182 ( V_235 , & V_236 ) ;
if ( V_4 > 0 )
V_4 = F_179 ( V_56 , & V_57 ,
& V_236 , V_4 ) ;
if ( V_4 < 0 )
break;
}
}
F_171 ( V_206 ) ;
if ( V_4 < 0 ) {
F_31 ( * V_56 , V_57 ) ;
F_60 ( V_56 ) ;
} else {
V_4 = V_57 ;
if ( V_57 > 0 && V_39 && V_39 [ 0 ] == '/' )
V_86 -> V_80 = true ;
}
return V_4 ;
}
static int F_183 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_55 * V_236 = NULL ;
struct V_200 * V_237 ;
struct V_134 * V_238 ;
char * V_239 ;
int V_57 = 0 ;
int V_4 ;
V_237 = F_184 ( true ) ;
if ( ! V_237 ) {
V_4 = - V_102 ;
F_4 ( L_168 , V_4 ) ;
return V_4 ;
}
V_4 = 0 ;
F_88 (nd, bidlist) {
V_239 = F_103 ( V_238 -> V_141 ) ;
V_4 = F_180 ( V_86 , & V_236 , V_239 ) ;
if ( V_4 > 0 )
V_4 = F_179 ( V_56 , & V_57 ,
& V_236 , V_4 ) ;
free ( V_239 ) ;
if ( V_4 < 0 )
break;
}
F_90 ( V_237 ) ;
if ( V_4 < 0 ) {
F_31 ( * V_56 , V_57 ) ;
F_60 ( V_56 ) ;
} else
V_4 = V_57 ;
return V_4 ;
}
static int F_185 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_216 * V_206 ;
struct V_234 * V_235 ;
struct V_55 * V_173 ;
struct V_134 * V_135 ;
int V_4 , V_58 ;
if ( V_86 -> V_152 ) {
if ( ! V_86 -> V_39 )
return F_183 ( V_86 , V_56 ) ;
else
return F_180 ( V_86 , V_56 , V_86 -> V_39 ) ;
}
V_206 = F_168 ( V_86 -> V_39 ) ;
if ( ! V_206 )
return 0 ;
V_235 = F_186 ( V_206 , V_86 ) ;
if ( ! V_235 ) {
V_4 = V_86 -> V_152 ? - V_26 : 0 ;
goto V_11;
}
V_4 = F_187 ( V_235 -> V_240 ) ;
if ( V_4 > V_205 . V_220 ) {
F_4 ( L_169 ,
V_86 -> V_39 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
* V_56 = F_108 ( V_4 * sizeof( * V_173 ) ) ;
if ( ! * V_56 ) {
V_4 = - V_47 ;
goto V_11;
}
V_58 = 0 ;
F_88 (node, entry->tevlist) {
V_173 = & ( * V_56 ) [ V_58 ++ ] ;
V_4 = F_112 ( V_135 -> V_141 , V_173 ) ;
if ( V_4 < 0 )
goto V_11;
V_173 -> V_80 = V_86 -> V_80 ;
}
V_4 = V_58 ;
V_11:
F_171 ( V_206 ) ;
return V_4 ;
}
static int F_188 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
int V_4 ;
if ( ! V_86 -> V_154 && ! V_86 -> V_152 ) {
if ( ! V_86 -> V_80 ) {
V_86 -> V_154 = F_28 ( V_49 ) ;
V_4 = V_86 -> V_154 ? 0 : - V_47 ;
} else
V_4 = F_27 ( V_86 -> V_39 , & V_86 -> V_154 ) ;
if ( V_4 != 0 ) {
F_7 ( L_170 ) ;
return V_4 ;
}
}
V_4 = F_176 ( V_86 , V_56 ) ;
if ( V_4 > 0 )
return V_4 ;
V_4 = F_185 ( V_86 , V_56 ) ;
if ( V_4 > 0 || V_86 -> V_152 )
return V_4 == 0 ? - V_26 : V_4 ;
V_4 = F_69 ( V_86 , V_56 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_175 ( V_86 , V_56 ) ;
}
int F_189 ( struct V_85 * V_142 , int V_143 )
{
int V_58 , V_4 ;
for ( V_58 = 0 ; V_58 < V_143 ; V_58 ++ ) {
if ( ! V_142 [ V_58 ] . V_80 )
F_144 () ;
V_4 = F_188 ( & V_142 [ V_58 ] , & V_142 [ V_58 ] . V_56 ) ;
if ( V_4 < 0 )
return V_4 ;
V_142 [ V_58 ] . V_57 = V_4 ;
}
F_145 () ;
return 0 ;
}
int F_190 ( struct V_85 * V_142 , int V_143 )
{
int V_58 , V_4 = 0 ;
for ( V_58 = 0 ; V_58 < V_143 ; V_58 ++ ) {
V_4 = F_166 ( & V_142 [ V_58 ] , V_142 [ V_58 ] . V_56 ,
V_142 [ V_58 ] . V_57 ,
V_205 . V_241 ) ;
if ( V_4 < 0 )
break;
}
return V_4 ;
}
void F_191 ( struct V_85 * V_142 , int V_143 )
{
int V_58 , V_222 ;
for ( V_58 = 0 ; V_58 < V_143 ; V_58 ++ ) {
for ( V_222 = 0 ; V_222 < V_142 [ V_58 ] . V_57 ; V_222 ++ )
F_32 ( & V_142 [ V_58 ] . V_56 [ V_222 ] ) ;
F_60 ( & V_142 [ V_58 ] . V_56 ) ;
V_142 [ V_58 ] . V_57 = 0 ;
F_128 ( & V_142 [ V_58 ] ) ;
}
}
int F_192 ( struct V_85 * V_142 , int V_143 )
{
int V_4 ;
V_4 = F_2 ( V_142 -> V_80 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_189 ( V_142 , V_143 ) ;
if ( V_4 == 0 )
V_4 = F_190 ( V_142 , V_143 ) ;
F_191 ( V_142 , V_143 ) ;
F_8 () ;
return V_4 ;
}
int F_193 ( struct V_131 * T_10 )
{
int V_4 , V_242 , V_243 = - 1 , V_244 = - 1 ;
char * V_1 = F_194 ( T_10 ) ;
if ( ! V_1 )
return - V_48 ;
V_4 = F_155 ( & V_244 , & V_243 , V_213 ) ;
if ( V_4 < 0 )
goto V_11;
V_4 = F_195 ( V_244 , T_10 ) ;
if ( V_4 < 0 && V_4 != - V_26 )
goto error;
V_242 = F_195 ( V_243 , T_10 ) ;
if ( V_242 < 0 && V_242 != - V_26 ) {
V_4 = V_242 ;
goto error;
}
V_4 = 0 ;
error:
if ( V_244 >= 0 )
F_42 ( V_244 ) ;
if ( V_243 >= 0 )
F_42 ( V_243 ) ;
V_11:
free ( V_1 ) ;
return V_4 ;
}
static int F_196 ( struct V_16 * V_16 V_113 ,
struct V_14 * V_24 )
{
if ( F_89 ( V_245 , V_24 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_197 ( const char * V_39 , struct V_131 * V_132 ,
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
F_55 ( L_171 , ( V_39 ) ? : L_5 ) ;
return - V_48 ;
}
V_245 = V_132 ;
V_4 = F_16 ( V_16 , F_196 ) ;
if ( V_4 ) {
if ( V_4 == - 2 ) {
char * V_1 = F_194 ( V_132 ) ;
F_55 ( L_172 ,
V_1 ) ;
free ( V_1 ) ;
} else
F_55 ( L_173 ,
( V_39 ) ? : L_5 ) ;
goto V_92;
}
if ( ! F_198 ( V_16 -> V_36 , V_16 -> type ) )
F_199 ( V_16 -> V_36 , V_16 -> type ) ;
F_79 () ;
F_200 ( V_16 -> V_36 , V_16 -> type , stdout ) ;
V_92:
if ( V_40 ) {
F_26 ( V_16 ) ;
}
F_8 () ;
return V_4 ;
}
int F_177 ( struct V_181 * V_246 ,
struct V_159 * V_247 )
{
V_246 -> V_182 = F_28 ( V_247 -> V_139 ) ;
if ( V_246 -> V_182 == NULL )
return - V_47 ;
if ( V_247 -> type ) {
V_246 -> type = F_28 ( V_247 -> type ) ;
if ( V_246 -> type == NULL )
return - V_47 ;
}
if ( V_247 -> V_15 ) {
V_246 -> V_15 = F_28 ( V_247 -> V_15 ) ;
if ( V_246 -> V_15 == NULL )
return - V_47 ;
} else
V_246 -> V_15 = NULL ;
return 0 ;
}
