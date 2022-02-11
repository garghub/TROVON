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
return F_11 ( V_12 , V_15 , V_17 ) ;
}
static struct V_14 * F_12 ( T_3 V_18 , struct V_16 * * V_17 )
{
return F_13 ( V_12 , V_18 , V_17 ) ;
}
static struct V_19 * F_14 ( void )
{
struct V_20 * V_20 ;
struct V_16 * V_16 = F_15 ( V_12 ) ;
if ( F_16 ( V_16 ) < 0 )
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
for ( V_44 = V_43 ; * V_44 != '\0' ; V_44 ++ ) {
if ( ! isalnum ( * V_44 ) && * V_44 != '_' ) {
* V_44 = '\0' ;
break;
}
}
V_4 = F_1 ( V_46 , 64 , L_6 , V_49 , V_43 ) ;
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
V_4 = F_18 ( L_7 , & V_60 ,
false , false ) ;
if ( V_4 == 0 && V_60 < V_59 )
F_7 ( L_8 , V_14 ) ;
else if ( F_34 ( V_59 ) )
F_7 ( L_9 , V_14 ) ;
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
L_10 , NULL ) ;
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
snprintf ( V_75 , sizeof( V_75 ) , L_11 , V_29 ) ;
V_16 = F_44 ( & V_12 -> V_32 , V_34 , V_75 ) ;
if ( V_16 ) {
V_36 = V_16 -> V_36 ;
goto V_76;
}
F_4 ( L_12 , V_29 ) ;
return - V_26 ;
}
V_16 = F_15 ( V_12 ) ;
V_36 = V_16 -> V_36 ;
V_13 = V_8 . V_13 ;
V_36 -> V_77 = 0 ;
if ( V_13 )
V_4 = F_45 ( V_36 , V_16 , V_13 , false ) ;
else
V_4 = F_46 ( V_36 , V_16 ) ;
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
F_4 ( L_13 V_82 L_14 ,
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
strcpy ( V_96 , L_15 ) ;
} else
F_54 ( V_36 , V_96 , V_97 ) ;
if ( ! V_94 )
F_55 ( L_16 ,
V_29 ? : L_5 , V_96 ) ;
return NULL ;
}
V_95 = V_36 -> V_99 ;
}
V_4 = F_56 ( V_95 ) ;
if ( ! V_4 && ! V_94 ) {
F_7 ( L_17 , V_95 ) ;
if ( ! V_29 || ! F_57 ( V_95 , L_18 ) )
F_7 ( L_19 ) ;
else
F_7 ( L_20 ) ;
F_7 ( L_21 ) ;
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
if ( ! F_39 ( V_62 , & V_63 , & V_64 , L_22 , NULL ) )
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
F_4 ( L_23 V_82 L_24 , V_18 ,
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
F_4 ( L_25 ) ;
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
if ( V_8 . V_112 )
return 0 ;
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_26 ) ;
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
if ( ! V_56 [ V_58 ] . V_88 . V_113 )
V_56 [ V_58 ] . V_88 . V_113 = V_56 [ V_58 ] . V_88 . V_14 ;
else
free ( V_56 [ V_58 ] . V_88 . V_14 ) ;
V_56 [ V_58 ] . V_88 . V_14 = V_87 ;
V_56 [ V_58 ] . V_88 . V_83 = V_56 [ V_58 ] . V_88 . V_59 -
V_23 -> V_25 ;
}
return V_111 ;
}
void __weak
F_67 ( struct V_85 * V_86 V_114 ,
int V_57 V_114 )
{
}
static int F_68 ( struct V_85 * V_86 ,
struct V_55 * V_56 ,
int V_57 , const char * V_29 ,
bool V_115 )
{
int V_4 ;
if ( V_115 )
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
bool V_116 = F_70 ( V_86 ) ;
struct V_50 V_87 ;
struct V_78 * V_79 ;
int V_57 , V_4 = 0 ;
V_79 = F_52 ( V_86 -> V_39 , ! V_116 ) ;
if ( ! V_79 ) {
if ( V_116 )
return - V_26 ;
F_4 ( L_27 ) ;
return 0 ;
}
F_4 ( L_28 ) ;
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
F_4 ( L_29 , V_57 ) ;
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
F_7 ( L_30 ,
F_72 ( & V_86 -> V_88 ) ) ;
return - V_26 ;
}
F_4 ( L_31 , V_57 ) ;
if ( V_57 < 0 ) {
if ( V_57 == - V_117 )
F_7 ( L_32
L_33 ) ;
if ( ! V_116 ) {
F_4 ( L_34 ) ;
return 0 ;
}
}
return V_57 ;
}
static int F_73 ( T_9 * V_118 , int V_119 , bool V_120 , bool V_121 )
{
char V_46 [ V_122 ] , V_123 [ V_97 ] ;
const char * V_124 = V_121 ? L_35 : V_125 ;
const char * V_126 = NULL ;
do {
if ( fgets ( V_46 , V_122 , V_118 ) == NULL )
goto error;
if ( V_120 )
continue;
if ( ! V_126 ) {
V_126 = V_121 ? L_36 : L_37 ;
F_74 ( stdout , V_124 , V_126 , V_119 ) ;
}
F_74 ( stdout , V_124 , L_38 , V_46 ) ;
} while ( strchr ( V_46 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_118 ) ) {
F_7 ( L_39 ,
F_53 ( V_102 , V_123 , sizeof( V_123 ) ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_75 ( T_9 * V_118 , int V_119 , bool V_120 , bool V_121 )
{
int V_127 = F_73 ( V_118 , V_119 , V_120 , V_121 ) ;
if ( V_127 == 0 ) {
F_7 ( L_40 ) ;
V_127 = - 1 ;
}
return V_127 ;
}
static int F_76 ( struct V_89 * V_90 , const char * V_29 ,
bool V_40 )
{
int V_119 = 1 ;
struct V_128 * V_129 ;
struct V_78 * V_79 ;
T_9 * V_118 ;
int V_4 ;
char * V_87 ;
char V_123 [ V_97 ] ;
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
F_7 ( L_41 ) ;
return - V_26 ;
} else if ( V_4 < 0 ) {
F_7 ( L_42 ) ;
return V_4 ;
}
V_87 = V_90 -> V_95 ;
V_4 = F_78 ( V_87 , V_90 -> V_130 , & V_90 -> V_95 ) ;
if ( V_87 != V_90 -> V_95 )
free ( V_87 ) ;
if ( V_4 < 0 ) {
F_7 ( L_43 ) ;
return V_4 ;
}
F_79 () ;
if ( V_90 -> V_53 )
fprintf ( stdout , L_44 , V_90 -> V_53 , V_90 -> V_95 ,
V_90 -> V_28 - V_90 -> V_83 ) ;
else
fprintf ( stdout , L_45 , V_90 -> V_95 , V_90 -> V_28 ) ;
V_118 = fopen ( V_90 -> V_95 , L_46 ) ;
if ( V_118 == NULL ) {
F_7 ( L_47 , V_90 -> V_95 ,
F_53 ( V_102 , V_123 , sizeof( V_123 ) ) ) ;
return - V_102 ;
}
while ( V_119 < V_90 -> V_28 ) {
V_4 = F_80 ( V_118 , V_119 ++ ) ;
if ( V_4 < 0 )
goto V_92;
}
F_81 (ln, lr->line_list) {
for (; V_129 -> V_58 > V_119 ; V_119 ++ ) {
V_4 = F_82 ( V_118 , V_119 - V_90 -> V_83 ) ;
if ( V_4 < 0 )
goto V_92;
}
V_4 = F_83 ( V_118 , V_119 ++ - V_90 -> V_83 ) ;
if ( V_4 < 0 )
goto V_92;
}
if ( V_90 -> V_92 == V_93 )
V_90 -> V_92 = V_119 + V_131 ;
while ( V_119 <= V_90 -> V_92 ) {
V_4 = F_84 ( V_118 , V_119 ++ - V_90 -> V_83 ) ;
if ( V_4 <= 0 )
break;
}
V_92:
fclose ( V_118 ) ;
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
struct V_132 * V_133 )
{
char * V_46 ;
int V_4 , V_58 , V_134 ;
struct V_135 * V_136 ;
struct V_137 * V_138 = NULL , * V_139 ;
struct V_50 V_87 ;
const char * V_140 ;
V_46 = F_72 ( & V_86 -> V_88 ) ;
if ( ! V_46 )
return - V_48 ;
F_4 ( L_48 , V_46 ) ;
V_4 = F_87 ( V_79 , V_86 , & V_138 ) ;
if ( ! V_4 ) {
V_4 = F_50 ( V_79 , V_86 , & V_87 ) ;
if ( ! V_4 ) {
V_4 = F_87 ( V_79 , V_86 ,
& V_138 ) ;
F_30 ( & V_87 ) ;
}
}
if ( V_4 <= 0 ) {
if ( V_4 == 0 || V_4 == - V_26 ) {
F_55 ( L_49 , V_46 ) ;
V_4 = - V_26 ;
} else
F_7 ( L_42 ) ;
goto V_92;
}
fprintf ( stdout , L_50 , V_46 ) ;
for ( V_58 = 0 ; V_58 < V_4 ; V_58 ++ ) {
V_139 = & V_138 [ V_58 ] ;
fprintf ( stdout , L_51 , V_139 -> V_88 . V_14 ,
V_139 -> V_88 . V_83 ) ;
F_60 ( & V_139 -> V_88 . V_14 ) ;
V_134 = 0 ;
if ( V_139 -> V_141 ) {
F_88 (node, vl->vars) {
V_140 = strchr ( V_136 -> V_142 , '\t' ) + 1 ;
if ( F_89 ( V_133 , V_140 ) ) {
fprintf ( stdout , L_52 , V_136 -> V_142 ) ;
V_134 ++ ;
}
}
F_90 ( V_139 -> V_141 ) ;
}
if ( V_134 == 0 )
fprintf ( stdout , L_53 ) ;
}
free ( V_138 ) ;
V_92:
free ( V_46 ) ;
return V_4 ;
}
int F_91 ( struct V_85 * V_143 , int V_144 ,
struct V_132 * V_133 )
{
int V_58 , V_4 = 0 ;
struct V_78 * V_79 ;
V_4 = F_2 ( V_143 -> V_80 ) ;
if ( V_4 < 0 )
return V_4 ;
V_79 = F_52 ( V_143 -> V_39 , false ) ;
if ( ! V_79 ) {
V_4 = - V_26 ;
goto V_11;
}
F_79 () ;
for ( V_58 = 0 ; V_58 < V_144 && V_4 >= 0 ; V_58 ++ )
V_4 = F_86 ( V_79 , & V_143 [ V_58 ] , V_133 ) ;
F_59 ( V_79 ) ;
V_11:
F_8 () ;
return V_4 ;
}
static void F_61 ( void )
{
}
static int
F_63 ( struct V_106 * V_107 V_114 ,
struct V_50 * V_51 V_114 ,
bool V_108 V_114 )
{
return - V_145 ;
}
static int F_69 ( struct V_85 * V_86 ,
struct V_55 * * V_56 V_114 )
{
if ( F_70 ( V_86 ) ) {
F_7 ( L_54 ) ;
return - V_145 ;
}
return 0 ;
}
int F_85 ( struct V_89 * V_90 V_114 ,
const char * V_29 V_114 ,
bool V_40 V_114 )
{
F_7 ( L_54 ) ;
return - V_145 ;
}
int F_91 ( struct V_85 * V_143 V_114 ,
int V_144 V_114 ,
struct V_132 * T_10 V_114 )
{
F_7 ( L_54 ) ;
return - V_145 ;
}
void F_92 ( struct V_89 * V_90 )
{
free ( V_90 -> V_53 ) ;
free ( V_90 -> V_52 ) ;
free ( V_90 -> V_95 ) ;
free ( V_90 -> V_130 ) ;
F_93 ( V_90 -> V_146 ) ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
}
int F_94 ( struct V_89 * V_90 )
{
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_90 -> V_146 = F_95 ( NULL ) ;
if ( ! V_90 -> V_146 )
return - V_47 ;
else
return 0 ;
}
static int F_96 ( char * * V_147 , int * V_148 , const char * V_149 )
{
const char * V_28 = * V_147 ;
V_102 = 0 ;
* V_148 = strtol ( * V_147 , V_147 , 0 ) ;
if ( V_102 || * V_147 == V_28 ) {
F_97 ( L_55 , V_149 ) ;
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
int F_99 ( const char * V_150 , struct V_89 * V_90 )
{
char * V_151 , * V_52 , * V_15 = F_28 ( V_150 ) ;
int V_98 ;
if ( ! V_15 )
return - V_47 ;
V_90 -> V_28 = 0 ;
V_90 -> V_92 = V_93 ;
V_151 = strchr ( V_15 , ':' ) ;
if ( V_151 ) {
* V_151 ++ = '\0' ;
V_98 = F_96 ( & V_151 , & V_90 -> V_28 , L_56 ) ;
if ( V_98 )
goto V_98;
if ( * V_151 == '+' || * V_151 == '-' ) {
const char V_152 = * V_151 ++ ;
V_98 = F_96 ( & V_151 , & V_90 -> V_92 , L_57 ) ;
if ( V_98 )
goto V_98;
if ( V_152 == '+' ) {
V_90 -> V_92 += V_90 -> V_28 ;
V_90 -> V_92 -- ;
}
}
F_4 ( L_58 , V_90 -> V_28 , V_90 -> V_92 ) ;
V_98 = - V_48 ;
if ( V_90 -> V_28 > V_90 -> V_92 ) {
F_97 ( L_59
L_60 ) ;
goto V_98;
}
if ( * V_151 != '\0' ) {
F_97 ( L_61 , V_151 ) ;
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
F_97 ( L_62 , V_15 ) ;
V_98 = - V_48 ;
goto V_98;
}
return 0 ;
V_98:
free ( V_15 ) ;
return V_98 ;
}
static int F_100 ( char * * V_150 , struct V_85 * V_86 )
{
char * V_147 ;
V_147 = strchr ( * V_150 , ':' ) ;
if ( V_147 ) {
* V_147 = '\0' ;
if ( ! V_86 -> V_153 && ! F_98 ( * V_150 ) )
goto V_154;
V_86 -> V_155 = F_28 ( * V_150 ) ;
if ( ! V_86 -> V_155 )
return - V_47 ;
* V_150 = V_147 + 1 ;
} else
V_86 -> V_155 = NULL ;
if ( ! V_86 -> V_153 && ! F_98 ( * V_150 ) ) {
V_154:
F_97 ( L_63
L_64 , * V_150 ) ;
return - V_48 ;
}
V_86 -> V_156 = F_28 ( * V_150 ) ;
if ( V_86 -> V_156 == NULL )
return - V_47 ;
return 0 ;
}
static int F_101 ( char * V_150 , struct V_85 * V_86 )
{
struct V_50 * V_51 = & V_86 -> V_88 ;
char * V_147 , * V_87 ;
char V_152 , V_157 = 0 ;
bool V_158 = false ;
int V_4 ;
if ( ! V_150 )
return - V_48 ;
if ( V_150 [ 0 ] == '%' ||
( ! strncmp ( V_150 , L_65 , 4 ) &&
! ! strchr ( V_150 , ':' ) && ! strchr ( V_150 , '=' ) ) ) {
V_86 -> V_153 = true ;
if ( V_150 [ 0 ] == '%' )
V_150 ++ ;
}
V_147 = strpbrk ( V_150 , L_66 ) ;
if ( V_86 -> V_153 ) {
if ( V_147 ) {
if ( * V_147 != '@' ) {
F_97 ( L_67 ,
V_150 ) ;
return - V_48 ;
}
V_87 = F_102 ( V_147 + 1 ) ;
if ( V_87 ) {
V_86 -> V_39 = F_103 ( V_87 ) ;
free ( V_87 ) ;
} else
V_86 -> V_39 = F_28 ( V_147 + 1 ) ;
if ( ! V_86 -> V_39 )
return - V_47 ;
* V_147 = '\0' ;
}
V_4 = F_100 ( & V_150 , V_86 ) ;
if ( V_4 == 0 ) {
if ( F_104 ( & V_86 -> V_88 . V_53 , L_68 , V_86 -> V_156 ) < 0 )
V_4 = - V_102 ;
}
return V_4 ;
}
if ( V_147 && * V_147 == '=' ) {
* V_147 = '\0' ;
V_87 = V_147 + 1 ;
V_4 = F_100 ( & V_150 , V_86 ) ;
if ( V_4 < 0 )
return V_4 ;
V_150 = V_87 ;
}
if ( ! strpbrk ( V_150 , L_69 ) && ( V_147 = strpbrk ( V_150 , L_70 ) ) != NULL ) {
if ( memchr ( V_150 , '.' , V_147 - V_150 ) )
V_158 = true ;
}
V_147 = strpbrk ( V_150 , L_71 ) ;
if ( V_147 ) {
V_157 = * V_147 ;
* V_147 ++ = '\0' ;
}
if ( V_150 [ 0 ] == '\0' )
V_87 = NULL ;
else {
V_87 = F_28 ( V_150 ) ;
if ( V_87 == NULL )
return - V_47 ;
}
if ( V_158 )
V_51 -> V_52 = V_87 ;
else {
V_51 -> V_53 = V_87 ;
if ( V_87 && ! strncmp ( V_87 , L_72 , 2 ) ) {
V_51 -> V_159 = strtoul ( V_51 -> V_53 , & V_87 , 0 ) ;
if ( * V_87 != '\0' ) {
F_97 ( L_73 ) ;
return - V_48 ;
}
}
}
while ( V_147 ) {
V_150 = V_147 ;
V_152 = V_157 ;
if ( V_152 == ';' ) {
V_51 -> V_54 = F_28 ( V_150 ) ;
if ( V_51 -> V_54 == NULL )
return - V_47 ;
break;
}
V_147 = strpbrk ( V_150 , L_71 ) ;
if ( V_147 ) {
V_157 = * V_147 ;
* V_147 ++ = '\0' ;
}
switch ( V_152 ) {
case ':' :
V_51 -> line = strtoul ( V_150 , & V_87 , 0 ) ;
if ( * V_87 != '\0' ) {
F_97 ( L_74
L_75 ) ;
return - V_48 ;
}
break;
case '+' :
V_51 -> V_83 = strtoul ( V_150 , & V_87 , 0 ) ;
if ( * V_87 != '\0' ) {
F_97 ( L_76
L_77 ) ;
return - V_48 ;
}
break;
case '@' :
if ( V_51 -> V_52 ) {
F_97 ( L_78 ) ;
return - V_48 ;
}
V_51 -> V_52 = F_28 ( V_150 ) ;
if ( V_51 -> V_52 == NULL )
return - V_47 ;
break;
case '%' :
if ( strcmp ( V_150 , L_79 ) == 0 ) {
V_51 -> V_84 = 1 ;
} else {
F_97 ( L_80 , V_150 ) ;
return - V_81 ;
}
break;
default:
F_55 ( L_81 ,
__FILE__ , __LINE__ ) ;
return - V_81 ;
break;
}
}
if ( V_51 -> V_54 && V_51 -> line ) {
F_97 ( L_82
L_83 ) ;
return - V_48 ;
}
if ( V_51 -> V_54 && V_51 -> V_83 ) {
F_97 ( L_84 ) ;
return - V_48 ;
}
if ( V_51 -> line && V_51 -> V_83 ) {
F_97 ( L_85 ) ;
return - V_48 ;
}
if ( ! V_51 -> line && ! V_51 -> V_54 && V_51 -> V_52 && ! V_51 -> V_53 ) {
F_97 ( L_86
L_87 ) ;
return - V_48 ;
}
if ( V_51 -> V_83 && ! V_51 -> V_53 ) {
F_97 ( L_88 ) ;
return - V_48 ;
}
if ( V_51 -> V_84 && ! V_51 -> V_53 ) {
F_97 ( L_89 ) ;
return - V_48 ;
}
if ( ( V_51 -> V_83 || V_51 -> line || V_51 -> V_54 ) && V_51 -> V_84 ) {
F_97 ( L_90
L_91 ) ;
return - V_48 ;
}
F_4 ( L_92 ,
V_51 -> V_53 , V_51 -> V_52 , V_51 -> line , V_51 -> V_83 , V_51 -> V_84 ,
V_51 -> V_54 ) ;
return 0 ;
}
static int F_105 ( char * V_1 , struct V_160 * V_150 )
{
char * V_87 , * V_161 ;
struct V_162 * * V_163 ;
F_4 ( L_93 , V_1 ) ;
V_87 = strchr ( V_1 , '=' ) ;
if ( V_87 ) {
V_150 -> V_15 = F_106 ( V_1 , V_87 - V_1 ) ;
if ( V_150 -> V_15 == NULL )
return - V_47 ;
F_4 ( L_94 , V_150 -> V_15 ) ;
V_1 = V_87 + 1 ;
}
V_87 = strchr ( V_1 , ':' ) ;
if ( V_87 ) {
* V_87 = '\0' ;
V_150 -> type = F_28 ( V_87 + 1 ) ;
if ( V_150 -> type == NULL )
return - V_47 ;
F_4 ( L_95 , V_150 -> type ) ;
}
V_87 = strpbrk ( V_1 , L_96 ) ;
if ( ! F_107 ( V_1 ) || ! V_87 ) {
V_150 -> V_140 = F_28 ( V_1 ) ;
if ( V_150 -> V_140 == NULL )
return - V_47 ;
F_4 ( L_97 , V_150 -> V_140 ) ;
return 0 ;
}
V_150 -> V_140 = F_106 ( V_1 , V_87 - V_1 ) ;
if ( V_150 -> V_140 == NULL )
return - V_47 ;
V_161 = V_150 -> V_140 ;
F_4 ( L_98 , V_150 -> V_140 ) ;
V_163 = & V_150 -> V_164 ;
do {
* V_163 = F_108 ( sizeof( struct V_162 ) ) ;
if ( * V_163 == NULL )
return - V_47 ;
if ( * V_87 == '[' ) {
V_1 = V_87 ;
( * V_163 ) -> V_165 = strtol ( V_1 + 1 , & V_87 , 0 ) ;
( * V_163 ) -> V_166 = true ;
if ( * V_87 != ']' || V_87 == V_1 + 1 ) {
F_97 ( L_99
L_100 ) ;
return - V_48 ;
}
V_87 ++ ;
if ( * V_87 == '\0' )
V_87 = NULL ;
} else {
if ( * V_87 == '.' ) {
V_1 = V_87 + 1 ;
( * V_163 ) -> V_166 = false ;
} else if ( V_87 [ 1 ] == '>' ) {
V_1 = V_87 + 2 ;
( * V_163 ) -> V_166 = true ;
} else {
F_97 ( L_101 ,
V_1 ) ;
return - V_48 ;
}
V_87 = strpbrk ( V_1 , L_96 ) ;
}
if ( V_87 ) {
( * V_163 ) -> V_15 = F_106 ( V_1 , V_87 - V_1 ) ;
if ( ( * V_163 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_161 = ( * V_163 ) -> V_15 ;
F_4 ( L_102 , ( * V_163 ) -> V_15 , ( * V_163 ) -> V_166 ) ;
V_163 = & ( * V_163 ) -> V_167 ;
}
} while ( V_87 );
( * V_163 ) -> V_15 = F_28 ( V_1 ) ;
if ( ( * V_163 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_161 = ( * V_163 ) -> V_15 ;
F_4 ( L_103 , ( * V_163 ) -> V_15 , ( * V_163 ) -> V_166 ) ;
if ( ! V_150 -> V_15 ) {
V_150 -> V_15 = F_28 ( V_161 ) ;
if ( V_150 -> V_15 == NULL )
return - V_47 ;
}
return 0 ;
}
int F_109 ( const char * V_168 , struct V_85 * V_86 )
{
char * * V_169 ;
int V_170 , V_58 , V_4 = 0 ;
V_169 = F_110 ( V_168 , & V_170 ) ;
if ( ! V_169 ) {
F_4 ( L_104 ) ;
return - V_47 ;
}
if ( V_170 - 1 > V_171 ) {
F_97 ( L_105 , V_170 - 1 ) ;
V_4 = - V_172 ;
goto V_11;
}
V_4 = F_101 ( V_169 [ 0 ] , V_86 ) ;
if ( V_4 < 0 )
goto V_11;
V_86 -> V_173 = V_170 - 1 ;
V_86 -> args = F_108 ( sizeof( struct V_160 ) * V_86 -> V_173 ) ;
if ( V_86 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_58 = 0 ; V_58 < V_86 -> V_173 && V_4 >= 0 ; V_58 ++ ) {
V_4 = F_105 ( V_169 [ V_58 + 1 ] , & V_86 -> args [ V_58 ] ) ;
if ( V_4 >= 0 &&
F_107 ( V_86 -> args [ V_58 ] . V_140 ) && V_86 -> V_88 . V_84 ) {
F_97 ( L_106
L_107 ) ;
V_4 = - V_48 ;
}
}
V_11:
F_111 ( V_169 ) ;
return V_4 ;
}
bool F_112 ( struct V_85 * V_86 )
{
int V_58 = 0 ;
for ( V_58 = 0 ; V_58 < V_86 -> V_173 ; V_58 ++ )
if ( F_107 ( V_86 -> args [ V_58 ] . V_140 ) ||
! strcmp ( V_86 -> args [ V_58 ] . V_140 , V_174 ) ||
! strcmp ( V_86 -> args [ V_58 ] . V_140 , V_175 ) )
return true ;
return false ;
}
bool F_70 ( struct V_85 * V_86 )
{
if ( V_86 -> V_88 . V_52 || V_86 -> V_88 . line || V_86 -> V_88 . V_54 )
return true ;
if ( F_112 ( V_86 ) )
return true ;
return false ;
}
int F_113 ( const char * V_168 , struct V_55 * V_176 )
{
struct V_106 * V_107 = & V_176 -> V_88 ;
char V_177 ;
char * V_178 ;
char * V_179 = NULL , * V_180 , * V_181 , * V_182 , * V_183 ;
int V_4 , V_58 , V_170 ;
char * * V_169 ;
F_4 ( L_108 , V_168 ) ;
V_169 = F_110 ( V_168 , & V_170 ) ;
if ( ! V_169 ) {
F_4 ( L_104 ) ;
return - V_47 ;
}
if ( V_170 < 2 ) {
F_97 ( L_109 ) ;
V_4 = - V_172 ;
goto V_11;
}
V_179 = F_28 ( V_169 [ 0 ] ) ;
if ( V_179 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
V_181 = strtok_r ( V_179 , L_110 , & V_180 ) ;
V_182 = strtok_r ( NULL , L_111 , & V_180 ) ;
V_183 = strtok_r ( NULL , L_112 , & V_180 ) ;
if ( V_181 == NULL || strlen ( V_181 ) != 1 || V_182 == NULL
|| V_183 == NULL ) {
F_97 ( L_113 , V_169 [ 0 ] ) ;
V_4 = - V_48 ;
goto V_11;
}
V_177 = V_181 [ 0 ] ;
V_176 -> V_155 = F_28 ( V_182 ) ;
V_176 -> V_156 = F_28 ( V_183 ) ;
if ( V_176 -> V_155 == NULL || V_176 -> V_156 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
F_4 ( L_114 , V_176 -> V_155 , V_176 -> V_156 , V_177 ) ;
V_107 -> V_84 = ( V_177 == 'r' ) ;
V_178 = strchr ( V_169 [ 1 ] , ':' ) ;
if ( V_178 ) {
V_107 -> V_29 = F_106 ( V_169 [ 1 ] , V_178 - V_169 [ 1 ] ) ;
if ( ! V_107 -> V_29 ) {
V_4 = - V_47 ;
goto V_11;
}
V_176 -> V_80 = ( V_107 -> V_29 [ 0 ] == '/' ) ;
V_178 ++ ;
} else
V_178 = V_169 [ 1 ] ;
V_181 = strtok_r ( V_178 , L_115 , & V_180 ) ;
if ( V_181 [ 0 ] == '0' ) {
if ( strcmp ( V_181 , L_72 ) == 0 ) {
if ( ! V_169 [ 2 ] || strcmp ( V_169 [ 2 ] , L_116 ) ) {
V_4 = - V_48 ;
goto V_11;
}
V_107 -> V_59 = 0 ;
free ( V_169 [ 2 ] ) ;
for ( V_58 = 2 ; V_169 [ V_58 + 1 ] != NULL ; V_58 ++ )
V_169 [ V_58 ] = V_169 [ V_58 + 1 ] ;
V_169 [ V_58 ] = NULL ;
V_170 -= 1 ;
} else
V_107 -> V_59 = strtoul ( V_181 , NULL , 0 ) ;
} else {
V_107 -> V_14 = F_28 ( V_181 ) ;
if ( V_107 -> V_14 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
V_182 = strtok_r ( NULL , L_35 , & V_180 ) ;
if ( V_182 == NULL )
V_107 -> V_83 = 0 ;
else
V_107 -> V_83 = strtoul ( V_182 , NULL , 10 ) ;
}
V_176 -> V_173 = V_170 - 2 ;
V_176 -> args = F_108 ( sizeof( struct V_184 ) * V_176 -> V_173 ) ;
if ( V_176 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_58 = 0 ; V_58 < V_176 -> V_173 ; V_58 ++ ) {
V_178 = strchr ( V_169 [ V_58 + 2 ] , '=' ) ;
if ( V_178 )
* V_178 ++ = '\0' ;
else
V_178 = V_169 [ V_58 + 2 ] ;
V_176 -> args [ V_58 ] . V_15 = F_28 ( V_169 [ V_58 + 2 ] ) ;
V_176 -> args [ V_58 ] . V_185 = F_28 ( V_178 ) ;
if ( V_176 -> args [ V_58 ] . V_15 == NULL || V_176 -> args [ V_58 ] . V_185 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
free ( V_179 ) ;
F_111 ( V_169 ) ;
return V_4 ;
}
char * F_114 ( struct V_160 * V_186 )
{
struct V_162 * V_164 = V_186 -> V_164 ;
struct V_187 V_46 ;
char * V_4 = NULL ;
int V_98 ;
if ( F_115 ( & V_46 , 64 ) < 0 )
return NULL ;
if ( V_186 -> V_15 && V_186 -> V_140 )
V_98 = F_116 ( & V_46 , L_117 , V_186 -> V_15 , V_186 -> V_140 ) ;
else
V_98 = F_117 ( & V_46 , V_186 -> V_15 ? : V_186 -> V_140 ) ;
if ( V_98 )
goto V_11;
while ( V_164 ) {
if ( V_164 -> V_15 [ 0 ] == '[' )
V_98 = F_117 ( & V_46 , V_164 -> V_15 ) ;
else
V_98 = F_116 ( & V_46 , L_118 , V_164 -> V_166 ? L_119 : L_120 ,
V_164 -> V_15 ) ;
V_164 = V_164 -> V_167 ;
if ( V_98 )
goto V_11;
}
if ( V_186 -> type )
if ( F_116 ( & V_46 , L_121 , V_186 -> type ) < 0 )
goto V_11;
V_4 = F_118 ( & V_46 , NULL ) ;
V_11:
F_119 ( & V_46 ) ;
return V_4 ;
}
char * F_72 ( struct V_50 * V_51 )
{
struct V_187 V_46 ;
char * V_87 , * V_4 = NULL ;
int V_91 , V_98 = 0 ;
if ( F_115 ( & V_46 , 64 ) < 0 )
return NULL ;
if ( V_51 -> V_53 ) {
if ( F_117 ( & V_46 , V_51 -> V_53 ) < 0 )
goto V_11;
if ( V_51 -> V_83 )
V_98 = F_116 ( & V_46 , L_122 , V_51 -> V_83 ) ;
else if ( V_51 -> line )
V_98 = F_116 ( & V_46 , L_123 , V_51 -> line ) ;
else if ( V_51 -> V_84 )
V_98 = F_117 ( & V_46 , L_124 ) ;
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
V_98 = F_116 ( & V_46 , L_125 , V_87 ) ;
if ( ! V_98 && ! V_51 -> V_53 && V_51 -> line )
V_98 = F_116 ( & V_46 , L_123 , V_51 -> line ) ;
}
if ( ! V_98 )
V_4 = F_118 ( & V_46 , NULL ) ;
V_11:
F_119 ( & V_46 ) ;
return V_4 ;
}
char * F_120 ( struct V_85 * V_86 )
{
struct V_187 V_46 ;
char * V_87 , * V_4 = NULL ;
int V_58 ;
if ( F_115 ( & V_46 , 64 ) )
return NULL ;
if ( V_86 -> V_156 )
if ( F_116 ( & V_46 , L_126 , V_86 -> V_155 ? : V_49 ,
V_86 -> V_156 ) < 0 )
goto V_11;
V_87 = F_72 ( & V_86 -> V_88 ) ;
if ( ! V_87 || F_117 ( & V_46 , V_87 ) < 0 )
goto V_11;
free ( V_87 ) ;
for ( V_58 = 0 ; V_58 < V_86 -> V_173 ; V_58 ++ ) {
V_87 = F_114 ( V_86 -> args + V_58 ) ;
if ( ! V_87 || F_116 ( & V_46 , L_127 , V_87 ) < 0 )
goto V_11;
free ( V_87 ) ;
}
V_4 = F_118 ( & V_46 , NULL ) ;
V_11:
F_119 ( & V_46 ) ;
return V_4 ;
}
static int F_121 ( struct V_188 * V_166 ,
struct V_187 * V_46 , int V_189 )
{
int V_98 ;
if ( V_166 -> V_167 ) {
V_189 = F_121 ( V_166 -> V_167 , V_46 ,
V_189 + 1 ) ;
if ( V_189 < 0 )
return V_189 ;
}
V_98 = F_116 ( V_46 , L_128 , V_166 -> V_83 ) ;
return ( V_98 < 0 ) ? V_98 : V_189 ;
}
static int F_122 ( struct V_184 * V_150 ,
struct V_187 * V_46 )
{
struct V_188 * V_166 = V_150 -> V_166 ;
int V_189 = 0 , V_98 ;
if ( V_150 -> V_15 )
V_98 = F_116 ( V_46 , L_129 , V_150 -> V_15 ) ;
else
V_98 = F_123 ( V_46 , ' ' ) ;
if ( V_98 )
return V_98 ;
if ( V_150 -> V_185 [ 0 ] == '@' && V_150 -> V_166 )
V_166 = V_166 -> V_167 ;
if ( V_166 ) {
V_189 = F_121 ( V_166 , V_46 , 1 ) ;
if ( V_189 < 0 )
return V_189 ;
}
if ( V_150 -> V_185 [ 0 ] == '@' && V_150 -> V_166 )
V_98 = F_116 ( V_46 , L_130 , V_150 -> V_185 , V_150 -> V_166 -> V_83 ) ;
else
V_98 = F_117 ( V_46 , V_150 -> V_185 ) ;
while ( ! V_98 && V_189 -- )
V_98 = F_123 ( V_46 , ')' ) ;
if ( ! V_98 && V_150 -> type )
V_98 = F_116 ( V_46 , L_121 , V_150 -> type ) ;
return V_98 ;
}
char * F_124 ( struct V_55 * V_176 )
{
struct V_106 * V_107 = & V_176 -> V_88 ;
struct V_187 V_46 ;
char * V_4 = NULL ;
int V_58 , V_98 ;
if ( V_176 -> V_80 && ! V_107 -> V_29 )
return NULL ;
if ( F_115 ( & V_46 , 32 ) < 0 )
return NULL ;
if ( F_116 ( & V_46 , L_131 , V_107 -> V_84 ? 'r' : 'p' ,
V_176 -> V_155 , V_176 -> V_156 ) < 0 )
goto error;
if ( V_176 -> V_80 && ! V_107 -> V_59 ) {
if ( ! V_107 -> V_14 || strcmp ( V_107 -> V_14 , L_132 ) )
goto error;
}
if ( V_176 -> V_80 )
V_98 = F_116 ( & V_46 , L_133 , V_107 -> V_29 , V_107 -> V_59 ) ;
else if ( ! strncmp ( V_107 -> V_14 , L_72 , 2 ) )
V_98 = F_116 ( & V_46 , L_134 , V_107 -> V_29 ? : L_35 ,
V_107 -> V_29 ? L_110 : L_35 , V_107 -> V_59 ) ;
else
V_98 = F_116 ( & V_46 , L_135 , V_107 -> V_29 ? : L_35 ,
V_107 -> V_29 ? L_110 : L_35 , V_107 -> V_14 , V_107 -> V_83 ) ;
if ( V_98 )
goto error;
for ( V_58 = 0 ; V_58 < V_176 -> V_173 ; V_58 ++ )
if ( F_122 ( & V_176 -> args [ V_58 ] , & V_46 ) < 0 )
goto error;
V_4 = F_118 ( & V_46 , NULL ) ;
error:
F_119 ( & V_46 ) ;
return V_4 ;
}
static int F_125 ( struct V_106 * V_107 ,
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
V_24 = F_126 ( V_16 , V_18 ) ;
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
static int F_127 ( struct V_106 * V_107 ,
struct V_50 * V_51 ,
bool V_108 )
{
char V_46 [ 128 ] ;
int V_4 ;
V_4 = F_63 ( V_107 , V_51 , V_108 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_125 ( V_107 , V_51 , V_108 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( L_136 ) ;
if ( V_107 -> V_14 ) {
V_51 -> V_53 = F_28 ( V_107 -> V_14 ) ;
V_51 -> V_83 = V_107 -> V_83 ;
} else {
V_4 = F_1 ( V_46 , 128 , L_137 V_82 , ( T_3 ) V_107 -> V_59 ) ;
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
static int F_128 ( struct V_55 * V_176 ,
struct V_85 * V_86 , bool V_108 )
{
struct V_187 V_46 = V_190 ;
int V_58 , V_4 ;
V_86 -> V_156 = F_28 ( V_176 -> V_156 ) ;
V_86 -> V_155 = F_28 ( V_176 -> V_155 ) ;
if ( V_86 -> V_156 == NULL || V_86 -> V_155 == NULL )
return - V_47 ;
V_4 = F_127 ( & V_176 -> V_88 , & V_86 -> V_88 , V_108 ) ;
if ( V_4 < 0 )
return V_4 ;
V_86 -> V_173 = V_176 -> V_173 ;
V_86 -> args = F_108 ( sizeof( struct V_160 ) * V_86 -> V_173 ) ;
if ( V_86 -> args == NULL )
return - V_47 ;
for ( V_58 = 0 ; V_58 < V_176 -> V_173 && V_4 >= 0 ; V_58 ++ ) {
if ( V_176 -> args [ V_58 ] . V_15 )
V_86 -> args [ V_58 ] . V_15 = F_28 ( V_176 -> args [ V_58 ] . V_15 ) ;
else {
if ( ( V_4 = F_115 ( & V_46 , 32 ) ) < 0 )
goto error;
V_4 = F_122 ( & V_176 -> args [ V_58 ] , & V_46 ) ;
V_86 -> args [ V_58 ] . V_15 = F_118 ( & V_46 , NULL ) ;
}
if ( V_86 -> args [ V_58 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_47 ;
}
error:
if ( V_4 < 0 )
F_129 ( V_86 ) ;
return V_4 ;
}
void F_129 ( struct V_85 * V_86 )
{
struct V_162 * V_164 , * V_167 ;
int V_58 ;
free ( V_86 -> V_156 ) ;
free ( V_86 -> V_155 ) ;
free ( V_86 -> V_39 ) ;
F_30 ( & V_86 -> V_88 ) ;
for ( V_58 = 0 ; V_58 < V_86 -> V_173 ; V_58 ++ ) {
free ( V_86 -> args [ V_58 ] . V_15 ) ;
free ( V_86 -> args [ V_58 ] . V_140 ) ;
free ( V_86 -> args [ V_58 ] . type ) ;
V_164 = V_86 -> args [ V_58 ] . V_164 ;
while ( V_164 ) {
V_167 = V_164 -> V_167 ;
F_60 ( & V_164 -> V_15 ) ;
free ( V_164 ) ;
V_164 = V_167 ;
}
}
free ( V_86 -> args ) ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
}
static int F_130 ( struct V_50 * V_191 ,
struct V_50 * V_192 )
{
V_191 -> V_52 = F_131 ( V_192 -> V_52 , V_193 ) ;
V_191 -> V_53 = F_131 ( V_192 -> V_53 , V_193 ) ;
V_191 -> V_54 = F_131 ( V_192 -> V_54 , V_193 ) ;
V_191 -> line = V_192 -> line ;
V_191 -> V_84 = V_192 -> V_84 ;
V_191 -> V_83 = V_192 -> V_83 ;
return 0 ;
V_193:
F_30 ( V_191 ) ;
return - V_47 ;
}
static int F_132 ( struct V_160 * V_191 ,
struct V_160 * V_192 )
{
struct V_162 * V_164 , * * V_194 ;
V_191 -> V_15 = F_131 ( V_192 -> V_15 , V_193 ) ;
V_191 -> V_140 = F_131 ( V_192 -> V_140 , V_193 ) ;
V_191 -> type = F_131 ( V_192 -> type , V_193 ) ;
V_164 = V_192 -> V_164 ;
V_194 = & ( V_191 -> V_164 ) ;
while ( V_164 ) {
* V_194 = F_108 ( sizeof( * V_164 ) ) ;
if ( ! * V_194 )
goto V_193;
( * V_194 ) -> V_15 = F_131 ( V_164 -> V_15 , V_193 ) ;
( * V_194 ) -> V_165 = V_164 -> V_165 ;
( * V_194 ) -> V_166 = V_164 -> V_166 ;
V_164 = V_164 -> V_167 ;
V_194 = & ( ( * V_194 ) -> V_167 ) ;
}
return 0 ;
V_193:
return - V_47 ;
}
int F_133 ( struct V_85 * V_191 ,
struct V_85 * V_192 )
{
int V_58 ;
V_191 -> V_156 = F_131 ( V_192 -> V_156 , V_193 ) ;
V_191 -> V_155 = F_131 ( V_192 -> V_155 , V_193 ) ;
V_191 -> V_39 = F_131 ( V_192 -> V_39 , V_193 ) ;
V_191 -> V_80 = V_192 -> V_80 ;
if ( F_130 ( & V_191 -> V_88 , & V_192 -> V_88 ) < 0 )
goto V_193;
V_191 -> args = F_108 ( sizeof( struct V_160 ) * V_192 -> V_173 ) ;
if ( ! V_191 -> args )
goto V_193;
V_191 -> V_173 = V_192 -> V_173 ;
for ( V_58 = 0 ; V_58 < V_192 -> V_173 ; V_58 ++ )
if ( F_132 ( & V_191 -> args [ V_58 ] , & V_192 -> args [ V_58 ] ) < 0 )
goto V_193;
return 0 ;
V_193:
F_129 ( V_191 ) ;
return - V_47 ;
}
void F_32 ( struct V_55 * V_176 )
{
struct V_188 * V_166 , * V_167 ;
int V_58 ;
free ( V_176 -> V_156 ) ;
free ( V_176 -> V_155 ) ;
free ( V_176 -> V_88 . V_14 ) ;
free ( V_176 -> V_88 . V_113 ) ;
free ( V_176 -> V_88 . V_29 ) ;
for ( V_58 = 0 ; V_58 < V_176 -> V_173 ; V_58 ++ ) {
free ( V_176 -> args [ V_58 ] . V_15 ) ;
free ( V_176 -> args [ V_58 ] . V_185 ) ;
free ( V_176 -> args [ V_58 ] . type ) ;
V_166 = V_176 -> args [ V_58 ] . V_166 ;
while ( V_166 ) {
V_167 = V_166 -> V_167 ;
free ( V_166 ) ;
V_166 = V_167 ;
}
}
free ( V_176 -> args ) ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
}
static void F_134 ( struct V_195 * V_196 )
{
struct V_197 * V_136 ;
while ( ! F_135 ( V_196 ) ) {
V_136 = F_136 ( V_196 ,
struct V_197 , V_198 ) ;
F_137 ( & V_136 -> V_198 ) ;
free ( V_136 -> V_14 ) ;
free ( V_136 ) ;
}
}
static int F_138 ( struct V_195 * V_196 )
{
struct V_197 * V_136 ;
const char * V_199 = F_139 () ;
char V_46 [ V_200 ] , * V_178 ;
T_9 * V_118 ;
int V_4 ;
if ( V_199 == NULL )
return - V_81 ;
V_4 = F_1 ( V_46 , V_200 , L_138 , V_199 ) ;
if ( V_4 < 0 )
return V_4 ;
V_118 = fopen ( V_46 , L_46 ) ;
if ( ! V_118 )
return - V_102 ;
V_4 = 0 ;
while ( fgets ( V_46 , V_200 , V_118 ) ) {
V_136 = F_108 ( sizeof( * V_136 ) ) ;
if ( ! V_136 ) {
V_4 = - V_47 ;
break;
}
F_140 ( & V_136 -> V_198 ) ;
F_141 ( & V_136 -> V_198 , V_196 ) ;
if ( sscanf ( V_46 , L_139 , & V_136 -> V_28 , & V_136 -> V_92 ) != 2 ) {
V_4 = - V_48 ;
break;
}
V_178 = strchr ( V_46 , '\t' ) ;
if ( V_178 ) {
V_178 ++ ;
if ( V_178 [ strlen ( V_178 ) - 1 ] == '\n' )
V_178 [ strlen ( V_178 ) - 1 ] = '\0' ;
} else
V_178 = ( char * ) L_140 ;
V_136 -> V_14 = F_28 ( V_178 ) ;
if ( ! V_136 -> V_14 ) {
V_4 = - V_47 ;
break;
}
F_142 ( L_141 ,
V_136 -> V_28 , V_136 -> V_92 , V_136 -> V_14 ) ;
V_4 ++ ;
}
if ( V_4 < 0 )
F_134 ( V_196 ) ;
fclose ( V_118 ) ;
return V_4 ;
}
static struct V_197 *
F_143 ( struct V_195 * V_196 ,
unsigned long V_59 )
{
struct V_197 * V_136 ;
F_144 (node, blacklist, list) {
if ( V_136 -> V_28 <= V_59 && V_59 <= V_136 -> V_92 )
return V_136 ;
}
return NULL ;
}
static void F_145 ( void )
{
if ( ! F_135 ( & V_201 ) )
return;
if ( F_138 ( & V_201 ) < 0 )
F_4 ( L_142 ) ;
}
static void F_146 ( void )
{
F_134 ( & V_201 ) ;
}
static bool F_34 ( unsigned long V_59 )
{
return ! ! F_143 ( & V_201 , V_59 ) ;
}
static int F_147 ( const char * V_155 , const char * V_156 ,
struct V_85 * V_86 ,
const char * V_29 ,
struct V_187 * V_42 )
{
int V_58 , V_4 ;
char * V_46 ;
if ( F_104 ( & V_46 , L_143 , V_155 , V_156 ) < 0 )
return - V_102 ;
V_4 = F_116 ( V_42 , L_144 , V_46 ) ;
free ( V_46 ) ;
if ( V_4 )
return V_4 ;
V_46 = F_72 ( & V_86 -> V_88 ) ;
if ( ! V_46 )
return - V_47 ;
V_4 = F_117 ( V_42 , V_46 ) ;
free ( V_46 ) ;
if ( ! V_4 && V_29 )
V_4 = F_116 ( V_42 , L_145 , V_29 ) ;
if ( ! V_4 && V_86 -> V_173 > 0 ) {
V_4 = F_148 ( V_42 , L_146 , 5 ) ;
for ( V_58 = 0 ; ! V_4 && V_58 < V_86 -> V_173 ; V_58 ++ ) {
V_46 = F_114 ( & V_86 -> args [ V_58 ] ) ;
if ( ! V_46 )
return - V_47 ;
V_4 = F_116 ( V_42 , L_127 , V_46 ) ;
free ( V_46 ) ;
}
}
if ( ! V_4 )
V_4 = F_123 ( V_42 , ')' ) ;
return V_4 ;
}
int F_149 ( const char * V_155 , const char * V_156 ,
struct V_85 * V_86 ,
const char * V_29 , bool V_202 )
{
struct V_187 V_46 = V_190 ;
int V_4 ;
V_4 = F_147 ( V_155 , V_156 , V_86 , V_29 , & V_46 ) ;
if ( V_4 >= 0 ) {
if ( V_202 )
printf ( L_97 , V_46 . V_46 ) ;
else
F_150 ( L_97 , V_46 . V_46 ) ;
}
F_119 ( & V_46 ) ;
return V_4 ;
}
static bool F_151 ( struct V_55 * V_176 ,
struct V_132 * T_10 )
{
char V_87 [ 128 ] ;
if ( F_89 ( T_10 , V_176 -> V_156 ) )
return true ;
if ( F_1 ( V_87 , 128 , L_143 , V_176 -> V_155 , V_176 -> V_156 ) < 0 )
return false ;
return F_89 ( T_10 , V_87 ) ;
}
static int F_152 ( int V_61 , bool V_108 ,
struct V_132 * T_10 )
{
int V_4 = 0 ;
struct V_55 V_176 ;
struct V_85 V_86 ;
struct V_203 * V_204 ;
struct V_135 * V_205 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_204 = F_153 ( V_61 ) ;
if ( ! V_204 )
return - V_47 ;
F_88 (ent, rawlist) {
V_4 = F_113 ( V_205 -> V_142 , & V_176 ) ;
if ( V_4 >= 0 ) {
if ( ! F_151 ( & V_176 , T_10 ) )
goto V_167;
V_4 = F_128 ( & V_176 , & V_86 ,
V_108 ) ;
if ( V_4 < 0 )
goto V_167;
V_4 = F_149 ( V_86 . V_155 , V_86 . V_156 ,
& V_86 , V_176 . V_88 . V_29 ,
true ) ;
}
V_167:
F_129 ( & V_86 ) ;
F_32 ( & V_176 ) ;
if ( V_4 < 0 )
break;
}
F_90 ( V_204 ) ;
F_61 () ;
return V_4 ;
}
int F_154 ( struct V_132 * T_10 )
{
int V_206 , V_207 , V_4 ;
F_79 () ;
if ( V_208 . V_209 )
return F_155 ( T_10 ) ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_156 ( & V_206 , & V_207 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_206 >= 0 )
V_4 = F_152 ( V_206 , true , T_10 ) ;
if ( V_207 >= 0 && V_4 >= 0 )
V_4 = F_152 ( V_207 , false , T_10 ) ;
if ( V_206 > 0 )
F_42 ( V_206 ) ;
if ( V_207 > 0 )
F_42 ( V_207 ) ;
F_8 () ;
return V_4 ;
}
static int F_157 ( char * V_46 , T_1 V_91 , const char * V_210 ,
struct V_203 * V_211 , bool V_212 )
{
int V_58 , V_4 ;
char * V_178 , * V_213 ;
if ( * V_210 == '.' )
V_210 ++ ;
V_213 = F_28 ( V_210 ) ;
if ( ! V_213 )
return - V_47 ;
V_178 = strchr ( V_213 , '.' ) ;
if ( V_178 && V_178 != V_213 )
* V_178 = '\0' ;
V_4 = F_1 ( V_46 , V_91 , L_38 , V_213 ) ;
if ( V_4 < 0 ) {
F_4 ( L_147 , V_4 ) ;
goto V_11;
}
if ( ! F_158 ( V_211 , V_46 ) )
goto V_11;
if ( ! V_212 ) {
F_7 ( L_148
L_149
L_150
L_151 ,
V_46 ) ;
V_4 = - V_214 ;
goto V_11;
}
for ( V_58 = 1 ; V_58 < V_215 ; V_58 ++ ) {
V_4 = F_1 ( V_46 , V_91 , L_152 , V_213 , V_58 ) ;
if ( V_4 < 0 ) {
F_4 ( L_147 , V_4 ) ;
goto V_11;
}
if ( ! F_158 ( V_211 , V_46 ) )
break;
}
if ( V_58 == V_215 ) {
F_7 ( L_153 ) ;
V_4 = - V_172 ;
}
V_11:
free ( V_213 ) ;
return V_4 ;
}
static void F_159 ( struct V_55 * V_176 )
{
int V_58 ;
char * V_46 = F_124 ( V_176 ) ;
if ( ! V_176 -> V_80 || V_176 -> V_173 == 0 || ! V_46 )
goto V_11;
for ( V_58 = 0 ; V_58 < V_176 -> V_173 ; V_58 ++ )
if ( F_160 ( V_176 -> args [ V_58 ] . V_185 , L_154 ) ) {
F_7 ( L_155
L_156 ,
V_176 -> args [ V_58 ] . V_185 ) ;
break;
}
V_11:
free ( V_46 ) ;
}
static int F_161 ( struct V_55 * V_176 ,
struct V_85 * V_86 ,
struct V_203 * V_211 ,
bool V_212 )
{
const char * V_156 , * V_155 ;
char V_46 [ 64 ] ;
int V_4 ;
if ( V_86 -> V_156 && ! V_86 -> V_153 )
V_156 = V_86 -> V_156 ;
else if ( V_176 -> V_156 )
V_156 = V_176 -> V_156 ;
else {
if ( V_86 -> V_88 . V_53 &&
( strncmp ( V_86 -> V_88 . V_53 , L_72 , 2 ) != 0 ) &&
! F_162 ( V_86 -> V_88 . V_53 ) )
V_156 = V_86 -> V_88 . V_53 ;
else
V_156 = V_176 -> V_88 . V_113 ;
}
if ( V_86 -> V_155 && ! V_86 -> V_153 )
V_155 = V_86 -> V_155 ;
else if ( V_176 -> V_155 )
V_155 = V_176 -> V_155 ;
else
V_155 = V_49 ;
V_4 = F_157 ( V_46 , 64 , V_156 ,
V_211 , V_212 ) ;
if ( V_4 < 0 )
return V_4 ;
V_156 = V_46 ;
V_176 -> V_156 = F_28 ( V_156 ) ;
V_176 -> V_155 = F_28 ( V_155 ) ;
if ( V_176 -> V_156 == NULL || V_176 -> V_155 == NULL )
return - V_47 ;
F_163 ( V_211 , V_156 ) ;
return 0 ;
}
static int F_164 ( bool V_115 ,
struct V_203 * * V_211 )
{
int V_61 ;
V_61 = F_165 ( V_216 | ( V_115 ? V_217 : 0 ) ) ;
if ( V_61 < 0 )
return V_61 ;
* V_211 = F_166 ( V_61 ) ;
if ( ! ( * V_211 ) ) {
F_4 ( L_157 ) ;
F_42 ( V_61 ) ;
return - V_47 ;
}
return V_61 ;
}
static int F_167 ( struct V_85 * V_86 ,
struct V_55 * V_56 ,
int V_57 , bool V_212 )
{
int V_58 , V_61 [ 2 ] = { - 1 , - 1 } , V_218 , V_4 ;
struct V_55 * V_176 = NULL ;
struct V_219 * V_209 = NULL ;
struct V_203 * V_211 [ 2 ] = { NULL , NULL } ;
V_218 = V_86 -> V_80 ? 1 : 0 ;
V_61 [ V_218 ] = F_164 ( V_218 , & V_211 [ V_218 ] ) ;
if ( V_61 [ V_218 ] < 0 )
return V_61 [ V_218 ] ;
V_4 = 0 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_176 = & V_56 [ V_58 ] ;
V_218 = V_176 -> V_80 ? 1 : 0 ;
if ( V_61 [ V_218 ] == - 1 ) {
V_61 [ V_218 ] = F_164 ( V_218 ,
& V_211 [ V_218 ] ) ;
if ( V_61 [ V_218 ] < 0 )
goto V_220;
}
if ( ! V_176 -> V_88 . V_14 && ! V_86 -> V_80 )
continue;
V_4 = F_161 ( V_176 , V_86 , V_211 [ V_218 ] ,
V_212 ) ;
if ( V_4 < 0 )
break;
V_4 = F_168 ( V_61 [ V_218 ] , V_176 ) ;
if ( V_4 < 0 )
break;
V_212 = true ;
}
if ( V_4 == - V_48 && V_86 -> V_80 )
F_159 ( V_176 ) ;
if ( V_4 == 0 && V_208 . V_209 ) {
V_209 = F_169 ( V_86 -> V_39 ) ;
if ( ! V_209 ||
F_170 ( V_209 , V_86 , V_56 , V_57 ) < 0 ||
F_171 ( V_209 ) < 0 )
F_7 ( L_158 ) ;
F_172 ( V_209 ) ;
}
V_220:
for ( V_218 = 0 ; V_218 < 2 ; V_218 ++ ) {
F_90 ( V_211 [ V_218 ] ) ;
if ( V_61 [ V_218 ] >= 0 )
F_42 ( V_61 [ V_218 ] ) ;
}
return V_4 ;
}
static int F_173 ( struct V_16 * V_16 , char * V_15 ,
struct V_14 * * V_221 )
{
int V_76 = 0 ;
struct V_14 * V_24 ;
struct V_222 * V_87 ;
if ( F_16 ( V_16 ) < 0 )
return 0 ;
F_174 (map, sym, tmp) {
if ( F_160 ( V_24 -> V_15 , V_15 ) ) {
V_76 ++ ;
if ( V_221 && V_76 < V_208 . V_223 )
V_221 [ V_76 - 1 ] = V_24 ;
}
}
return V_76 ;
}
void __weak F_175 ( struct V_85 * V_86 V_114 ,
struct V_55 * V_176 V_114 ,
struct V_16 * V_16 V_114 ,
struct V_14 * V_24 V_114 ) { }
static int F_176 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_16 * V_16 = NULL ;
struct V_19 * V_23 = NULL ;
struct V_14 * V_24 ;
struct V_14 * * V_221 = NULL ;
struct V_55 * V_176 ;
struct V_50 * V_51 = & V_86 -> V_88 ;
struct V_106 * V_107 ;
int V_224 ;
int V_4 , V_58 , V_225 , V_111 = 0 ;
char * V_67 ;
V_16 = F_23 ( V_86 -> V_39 , V_86 -> V_80 ) ;
if ( ! V_16 ) {
V_4 = - V_48 ;
goto V_11;
}
V_221 = malloc ( sizeof( struct V_14 * ) * V_208 . V_223 ) ;
if ( ! V_221 ) {
V_4 = - V_47 ;
goto V_11;
}
V_224 = F_173 ( V_16 , V_51 -> V_53 , V_221 ) ;
if ( V_224 == 0 ) {
F_55 ( L_159 , V_51 -> V_53 ,
V_86 -> V_39 ? : L_5 ) ;
V_4 = - V_26 ;
goto V_11;
} else if ( V_224 > V_208 . V_223 ) {
F_55 ( L_160 ,
V_86 -> V_39 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
if ( ! V_86 -> V_80 && ! V_51 -> V_84 && ! V_86 -> V_39 ) {
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_26 ) ;
V_4 = - V_48 ;
goto V_11;
}
}
* V_56 = F_108 ( sizeof( * V_176 ) * V_224 ) ;
if ( ! * V_56 ) {
V_4 = - V_47 ;
goto V_11;
}
V_4 = 0 ;
for ( V_225 = 0 ; V_225 < V_224 ; V_225 ++ ) {
V_24 = V_221 [ V_225 ] ;
V_176 = ( * V_56 ) + V_4 ;
V_107 = & V_176 -> V_88 ;
if ( V_4 == V_224 ) {
F_7 ( L_161 ) ;
break;
}
V_4 ++ ;
if ( V_51 -> V_83 > V_24 -> V_92 - V_24 -> V_28 ) {
F_7 ( L_162 ,
V_51 -> V_83 , V_24 -> V_15 ) ;
V_4 = - V_26 ;
goto V_226;
}
V_107 -> V_59 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) + V_51 -> V_83 ;
if ( ! V_86 -> V_80 && ! V_86 -> V_39 &&
F_33 ( V_24 -> V_15 , V_107 -> V_59 ) ) {
V_107 -> V_14 = NULL ;
V_111 ++ ;
} else if ( V_23 ) {
V_107 -> V_14 = F_131 ( V_23 -> V_15 , V_227 ) ;
V_107 -> V_83 = V_107 -> V_59 - V_23 -> V_18 ;
} else {
V_107 -> V_14 = F_131 ( V_24 -> V_15 , V_227 ) ;
V_107 -> V_83 = V_51 -> V_83 ;
}
V_107 -> V_113 = F_131 ( V_24 -> V_15 , V_227 ) ;
V_107 -> V_84 = V_51 -> V_84 ;
if ( V_86 -> V_39 ) {
if ( V_86 -> V_80 ) {
V_176 -> V_88 . V_29 = F_131 ( V_86 -> V_39 ,
V_227 ) ;
} else {
V_67 = F_35 ( V_86 -> V_39 ) ;
V_176 -> V_88 . V_29 =
F_28 ( V_67 ? V_67 : V_86 -> V_39 ) ;
free ( V_67 ) ;
if ( ! V_176 -> V_88 . V_29 )
goto V_227;
}
}
V_176 -> V_80 = V_86 -> V_80 ;
V_176 -> V_173 = V_86 -> V_173 ;
if ( V_176 -> V_173 ) {
V_176 -> args = F_108 ( sizeof( struct V_184 ) *
V_176 -> V_173 ) ;
if ( V_176 -> args == NULL )
goto V_227;
}
for ( V_58 = 0 ; V_58 < V_176 -> V_173 ; V_58 ++ ) {
if ( V_86 -> args [ V_58 ] . V_15 )
V_176 -> args [ V_58 ] . V_15 =
F_131 ( V_86 -> args [ V_58 ] . V_15 ,
V_227 ) ;
V_176 -> args [ V_58 ] . V_185 = F_131 ( V_86 -> args [ V_58 ] . V_140 ,
V_227 ) ;
if ( V_86 -> args [ V_58 ] . type )
V_176 -> args [ V_58 ] . type =
F_131 ( V_86 -> args [ V_58 ] . type ,
V_227 ) ;
}
F_175 ( V_86 , V_176 , V_16 , V_24 ) ;
}
if ( V_4 == V_111 ) {
V_4 = - V_26 ;
goto V_226;
}
V_11:
F_25 ( V_16 , V_86 -> V_80 ) ;
free ( V_221 ) ;
return V_4 ;
V_227:
V_4 = - V_47 ;
V_226:
F_31 ( * V_56 , V_224 ) ;
F_60 ( V_56 ) ;
goto V_11;
}
static int F_177 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_50 * V_51 = & V_86 -> V_88 ;
struct V_55 * V_176 ;
struct V_106 * V_107 ;
int V_58 , V_98 ;
if ( ! ( V_86 -> V_88 . V_53 && ! strncmp ( V_86 -> V_88 . V_53 , L_72 , 2 ) ) )
return - V_48 ;
if ( F_70 ( V_86 ) )
return - V_48 ;
* V_56 = F_108 ( sizeof( * V_176 ) ) ;
if ( ! * V_56 )
return - V_47 ;
V_176 = * V_56 ;
V_107 = & V_176 -> V_88 ;
V_107 -> V_59 = V_86 -> V_88 . V_159 ;
V_107 -> V_84 = V_51 -> V_84 ;
V_176 -> V_80 = V_86 -> V_80 ;
V_98 = - V_47 ;
if ( F_104 ( & V_107 -> V_14 , L_163 , V_107 -> V_59 ) < 0 )
goto V_228;
if ( ( ! V_176 -> V_80 ) &&
( F_33 ( V_176 -> V_88 . V_14 ,
V_176 -> V_88 . V_59 ) ) ) {
V_98 = - V_229 ;
goto V_228;
}
if ( F_104 ( & V_107 -> V_113 , L_164 , V_107 -> V_59 ) < 0 )
goto V_228;
if ( V_86 -> V_39 ) {
V_107 -> V_29 = F_28 ( V_86 -> V_39 ) ;
if ( ! V_107 -> V_29 )
goto V_228;
}
if ( V_176 -> V_155 ) {
V_176 -> V_155 = F_28 ( V_86 -> V_155 ) ;
if ( ! V_176 -> V_155 )
goto V_228;
}
if ( V_86 -> V_156 ) {
V_176 -> V_156 = F_28 ( V_86 -> V_156 ) ;
if ( ! V_176 -> V_156 )
goto V_228;
}
V_176 -> V_173 = V_86 -> V_173 ;
V_176 -> args = F_108 ( sizeof( struct V_184 ) * V_176 -> V_173 ) ;
if ( ! V_176 -> args ) {
V_98 = - V_47 ;
goto V_228;
}
for ( V_58 = 0 ; V_58 < V_176 -> V_173 ; V_58 ++ )
F_178 ( & V_176 -> args [ V_58 ] , & V_86 -> args [ V_58 ] ) ;
return 1 ;
V_228:
if ( * V_56 ) {
F_31 ( * V_56 , 1 ) ;
* V_56 = NULL ;
}
return V_98 ;
}
static void * F_179 ( void * V_230 , T_1 V_231 , void * V_232 , T_1 V_233 )
{
void * V_4 ;
V_4 = malloc ( V_231 + V_233 ) ;
if ( V_4 ) {
memcpy ( V_4 , V_230 , V_231 ) ;
memcpy ( V_4 + V_231 , V_232 , V_233 ) ;
}
return V_4 ;
}
static int
F_180 ( struct V_55 * * V_56 , int * V_57 ,
struct V_55 * * V_234 , int V_235 )
{
struct V_55 * V_236 ;
int V_4 = 0 ;
if ( V_57 == 0 ) {
* V_56 = * V_234 ;
* V_57 = V_235 ;
* V_234 = NULL ;
return 0 ;
}
if ( * V_57 + V_235 > V_208 . V_223 )
V_4 = - V_6 ;
else {
V_236 = F_179 ( * V_56 , ( * V_57 ) * sizeof( * * V_56 ) ,
* V_234 , V_235 * sizeof( * * V_234 ) ) ;
if ( ! V_236 )
V_4 = - V_47 ;
else {
free ( * V_56 ) ;
* V_56 = V_236 ;
* V_57 += V_235 ;
}
}
if ( V_4 < 0 )
F_31 ( * V_234 , V_235 ) ;
F_60 ( V_234 ) ;
return V_4 ;
}
static int F_181 ( struct V_85 * V_86 ,
struct V_55 * * V_56 ,
const char * V_39 )
{
struct V_219 * V_209 ;
struct V_237 * V_238 ;
struct V_55 * V_239 = NULL ;
int V_57 = 0 ;
int V_4 = 0 ;
V_209 = F_169 ( V_39 ) ;
if ( ! V_209 )
return 0 ;
F_182 (entry, cache) {
if ( ! V_238 -> V_86 . V_156 || ! V_238 -> V_86 . V_155 )
continue;
if ( ( ! V_86 -> V_155 || F_160 ( V_238 -> V_86 . V_155 , V_86 -> V_155 ) ) &&
F_160 ( V_238 -> V_86 . V_156 , V_86 -> V_156 ) ) {
V_4 = F_183 ( V_238 , & V_239 ) ;
if ( V_4 > 0 )
V_4 = F_180 ( V_56 , & V_57 ,
& V_239 , V_4 ) ;
if ( V_4 < 0 )
break;
}
}
F_172 ( V_209 ) ;
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
static int F_184 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_55 * V_239 = NULL ;
struct V_203 * V_240 ;
struct V_135 * V_241 ;
char * V_242 ;
int V_57 = 0 ;
int V_4 ;
V_240 = F_185 ( true ) ;
if ( ! V_240 ) {
V_4 = - V_102 ;
F_4 ( L_165 , V_4 ) ;
return V_4 ;
}
V_4 = 0 ;
F_88 (nd, bidlist) {
V_242 = F_103 ( V_241 -> V_142 ) ;
V_4 = F_181 ( V_86 , & V_239 , V_242 ) ;
if ( V_4 > 0 )
V_4 = F_180 ( V_56 , & V_57 ,
& V_239 , V_4 ) ;
free ( V_242 ) ;
if ( V_4 < 0 )
break;
}
F_90 ( V_240 ) ;
if ( V_4 < 0 ) {
F_31 ( * V_56 , V_57 ) ;
F_60 ( V_56 ) ;
} else
V_4 = V_57 ;
return V_4 ;
}
static int F_186 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
struct V_219 * V_209 ;
struct V_237 * V_238 ;
struct V_55 * V_176 ;
struct V_135 * V_136 ;
int V_4 , V_58 ;
if ( V_86 -> V_153 ) {
if ( ! V_86 -> V_39 )
return F_184 ( V_86 , V_56 ) ;
else
return F_181 ( V_86 , V_56 , V_86 -> V_39 ) ;
}
V_209 = F_169 ( V_86 -> V_39 ) ;
if ( ! V_209 )
return 0 ;
V_238 = F_187 ( V_209 , V_86 ) ;
if ( ! V_238 ) {
V_4 = V_86 -> V_153 ? - V_26 : 0 ;
goto V_11;
}
V_4 = F_188 ( V_238 -> V_243 ) ;
if ( V_4 > V_208 . V_223 ) {
F_4 ( L_166 ,
V_86 -> V_39 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
* V_56 = F_108 ( V_4 * sizeof( * V_176 ) ) ;
if ( ! * V_56 ) {
V_4 = - V_47 ;
goto V_11;
}
V_58 = 0 ;
F_88 (node, entry->tevlist) {
V_176 = & ( * V_56 ) [ V_58 ++ ] ;
V_4 = F_113 ( V_136 -> V_142 , V_176 ) ;
if ( V_4 < 0 )
goto V_11;
V_176 -> V_80 = V_86 -> V_80 ;
}
V_4 = V_58 ;
V_11:
F_172 ( V_209 ) ;
return V_4 ;
}
static int F_189 ( struct V_85 * V_86 ,
struct V_55 * * V_56 )
{
int V_4 ;
if ( ! V_86 -> V_155 && ! V_86 -> V_153 ) {
if ( ! V_86 -> V_80 ) {
V_86 -> V_155 = F_28 ( V_49 ) ;
V_4 = V_86 -> V_155 ? 0 : - V_47 ;
} else
V_4 = F_27 ( V_86 -> V_39 , & V_86 -> V_155 ) ;
if ( V_4 != 0 ) {
F_7 ( L_167 ) ;
return V_4 ;
}
}
V_4 = F_177 ( V_86 , V_56 ) ;
if ( V_4 > 0 )
return V_4 ;
V_4 = F_186 ( V_86 , V_56 ) ;
if ( V_4 > 0 || V_86 -> V_153 )
return V_4 == 0 ? - V_26 : V_4 ;
V_4 = F_69 ( V_86 , V_56 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_176 ( V_86 , V_56 ) ;
}
int F_190 ( struct V_85 * V_143 , int V_144 )
{
int V_58 , V_4 ;
for ( V_58 = 0 ; V_58 < V_144 ; V_58 ++ ) {
if ( ! V_143 [ V_58 ] . V_80 )
F_145 () ;
V_4 = F_189 ( & V_143 [ V_58 ] , & V_143 [ V_58 ] . V_56 ) ;
if ( V_4 < 0 )
return V_4 ;
V_143 [ V_58 ] . V_57 = V_4 ;
}
F_146 () ;
return 0 ;
}
static int F_191 ( struct V_55 * V_176 )
{
char * V_46 = F_124 ( V_176 ) ;
if ( ! V_46 ) {
F_4 ( L_168 ) ;
return - V_48 ;
}
printf ( L_97 , V_46 ) ;
free ( V_46 ) ;
return 0 ;
}
int F_192 ( struct V_85 * V_143 , int V_144 )
{
struct V_203 * V_211 = F_193 ( NULL , NULL ) ;
struct V_55 * V_176 ;
struct V_85 * V_86 ;
int V_58 , V_225 , V_4 = 0 ;
if ( ! V_211 )
return - V_47 ;
for ( V_225 = 0 ; V_225 < V_144 && ! V_4 ; V_225 ++ ) {
V_86 = & V_143 [ V_225 ] ;
for ( V_58 = 0 ; V_58 < V_86 -> V_57 && ! V_4 ; V_58 ++ ) {
V_176 = & V_86 -> V_56 [ V_58 ] ;
if ( ! V_176 -> V_88 . V_14 && ! V_86 -> V_80 )
continue;
V_4 = F_161 ( V_176 , V_86 ,
V_211 , true ) ;
if ( ! V_4 )
V_4 = F_191 ( V_176 ) ;
}
}
F_90 ( V_211 ) ;
return V_4 ;
}
int F_194 ( struct V_85 * V_143 , int V_144 )
{
int V_58 , V_4 = 0 ;
for ( V_58 = 0 ; V_58 < V_144 ; V_58 ++ ) {
V_4 = F_167 ( & V_143 [ V_58 ] , V_143 [ V_58 ] . V_56 ,
V_143 [ V_58 ] . V_57 ,
V_208 . V_244 ) ;
if ( V_4 < 0 )
break;
}
return V_4 ;
}
void F_195 ( struct V_85 * V_143 , int V_144 )
{
int V_58 , V_225 ;
for ( V_58 = 0 ; V_58 < V_144 ; V_58 ++ ) {
for ( V_225 = 0 ; V_225 < V_143 [ V_58 ] . V_57 ; V_225 ++ )
F_32 ( & V_143 [ V_58 ] . V_56 [ V_225 ] ) ;
F_60 ( & V_143 [ V_58 ] . V_56 ) ;
V_143 [ V_58 ] . V_57 = 0 ;
F_129 ( & V_143 [ V_58 ] ) ;
}
}
int F_196 ( struct V_85 * V_143 , int V_144 )
{
int V_4 ;
V_4 = F_2 ( V_143 -> V_80 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_190 ( V_143 , V_144 ) ;
if ( V_4 == 0 )
V_4 = F_194 ( V_143 , V_144 ) ;
F_195 ( V_143 , V_144 ) ;
F_8 () ;
return V_4 ;
}
int F_197 ( struct V_132 * T_10 )
{
int V_4 , V_245 , V_246 = - 1 , V_247 = - 1 ;
char * V_1 = F_198 ( T_10 ) ;
if ( ! V_1 )
return - V_48 ;
V_4 = F_156 ( & V_247 , & V_246 , V_216 ) ;
if ( V_4 < 0 )
goto V_11;
V_4 = F_199 ( V_247 , T_10 ) ;
if ( V_4 < 0 && V_4 != - V_26 )
goto error;
V_245 = F_199 ( V_246 , T_10 ) ;
if ( V_245 < 0 && V_245 != - V_26 ) {
V_4 = V_245 ;
goto error;
}
V_4 = 0 ;
error:
if ( V_247 >= 0 )
F_42 ( V_247 ) ;
if ( V_246 >= 0 )
F_42 ( V_246 ) ;
V_11:
free ( V_1 ) ;
return V_4 ;
}
int F_200 ( const char * V_39 , struct V_132 * V_133 ,
bool V_40 )
{
struct V_222 * V_241 ;
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
F_55 ( L_169 , ( V_39 ) ? : L_5 ) ;
return - V_48 ;
}
V_4 = F_16 ( V_16 ) ;
if ( V_4 ) {
if ( V_4 == - 2 ) {
char * V_1 = F_198 ( V_133 ) ;
F_55 ( L_170 ,
V_1 ) ;
free ( V_1 ) ;
} else
F_55 ( L_171 ,
( V_39 ) ? : L_5 ) ;
goto V_92;
}
if ( ! F_201 ( V_16 -> V_36 , V_16 -> type ) )
F_202 ( V_16 -> V_36 , V_16 -> type ) ;
F_79 () ;
for ( V_241 = F_203 ( & V_16 -> V_36 -> V_248 [ V_16 -> type ] ) ; V_241 ; V_241 = F_204 ( V_241 ) ) {
struct V_249 * V_35 = F_205 ( V_241 , struct V_249 , V_222 ) ;
if ( F_89 ( V_133 , V_35 -> V_24 . V_15 ) )
printf ( L_97 , V_35 -> V_24 . V_15 ) ;
}
V_92:
if ( V_40 ) {
F_26 ( V_16 ) ;
}
F_8 () ;
return V_4 ;
}
int F_178 ( struct V_184 * V_250 ,
struct V_160 * V_251 )
{
V_250 -> V_185 = F_28 ( V_251 -> V_140 ) ;
if ( V_250 -> V_185 == NULL )
return - V_47 ;
if ( V_251 -> type ) {
V_250 -> type = F_28 ( V_251 -> type ) ;
if ( V_250 -> type == NULL )
return - V_47 ;
}
if ( V_251 -> V_15 ) {
V_250 -> V_15 = F_28 ( V_251 -> V_15 ) ;
if ( V_250 -> V_15 == NULL )
return - V_47 ;
} else
V_250 -> V_15 = NULL ;
return 0 ;
}
