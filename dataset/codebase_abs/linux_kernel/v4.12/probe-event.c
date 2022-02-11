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
return F_20 ( V_29 ) ;
if ( ! V_29 )
V_29 = L_5 ;
for ( V_35 = F_21 ( V_33 ) ; V_35 ; V_35 = F_22 ( V_35 ) ) {
if ( strncmp ( V_35 -> V_36 -> V_37 + 1 , V_29 ,
V_35 -> V_36 -> V_38 - 2 ) == 0 &&
V_29 [ V_35 -> V_36 -> V_38 - 2 ] == '\0' ) {
F_23 ( V_35 ) ;
return V_35 ;
}
}
return NULL ;
}
struct V_16 * F_24 ( const char * V_39 , bool V_40 )
{
if ( V_40 )
return F_20 ( V_39 ) ;
else
return F_19 ( V_39 ) ;
}
static int F_25 ( const char * V_41 , char * * V_42 )
{
char * V_43 , * V_44 , * V_45 ;
char V_46 [ 64 ] ;
int V_4 ;
V_45 = F_26 ( V_41 ) ;
if ( ! V_45 )
return - V_47 ;
V_43 = F_27 ( V_45 ) ;
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
* V_42 = F_26 ( V_46 ) ;
V_4 = * V_42 ? 0 : - V_47 ;
V_11:
free ( V_45 ) ;
return V_4 ;
}
static void F_28 ( struct V_50 * V_51 )
{
free ( V_51 -> V_52 ) ;
free ( V_51 -> V_53 ) ;
free ( V_51 -> V_54 ) ;
}
static void F_29 ( struct V_55 * V_56 , int V_57 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ )
F_30 ( V_56 + V_58 ) ;
}
static bool F_31 ( const char * V_14 , unsigned long V_59 )
{
T_3 V_60 = 0 ;
int V_4 ;
V_4 = F_18 ( L_7 , & V_60 ,
false , false ) ;
if ( V_4 == 0 && V_60 < V_59 )
F_7 ( L_8 , V_14 ) ;
else if ( F_32 ( V_59 ) )
F_7 ( L_9 , V_14 ) ;
else
return false ;
return true ;
}
static char * F_33 ( const char * V_29 )
{
int V_61 ;
T_4 * V_62 ;
T_5 V_63 ;
T_6 V_64 ;
T_7 * V_65 ;
T_8 * V_66 ;
char * V_67 = NULL ;
int V_68 ;
V_61 = F_34 ( V_29 , V_69 ) ;
if ( V_61 < 0 )
return NULL ;
V_62 = F_35 ( V_61 , V_70 , NULL ) ;
if ( V_62 == NULL )
goto V_71;
if ( F_36 ( V_62 , & V_63 ) == NULL )
goto V_72;
V_66 = F_37 ( V_62 , & V_63 , & V_64 ,
L_10 , NULL ) ;
if ( ! V_66 )
goto V_72;
V_65 = F_38 ( V_66 , NULL ) ;
if ( ! V_65 || ! V_65 -> V_73 )
goto V_72;
if ( V_63 . V_74 [ V_75 ] == V_76 )
V_68 = 12 ;
else
V_68 = 24 ;
V_67 = F_26 ( ( char * ) V_65 -> V_73 + V_68 ) ;
V_72:
F_39 ( V_62 ) ;
V_71:
F_40 ( V_61 ) ;
return V_67 ;
}
static int F_41 ( const char * V_29 , struct V_36 * * V_77 )
{
struct V_36 * V_36 ;
struct V_16 * V_16 ;
const char * V_13 ;
int V_4 = 0 ;
if ( V_29 ) {
char V_78 [ 128 ] ;
snprintf ( V_78 , sizeof( V_78 ) , L_11 , V_29 ) ;
V_16 = F_42 ( & V_12 -> V_32 , V_34 , V_78 ) ;
if ( V_16 ) {
V_36 = V_16 -> V_36 ;
goto V_79;
}
F_4 ( L_12 , V_29 ) ;
return - V_26 ;
}
V_16 = F_15 ( V_12 ) ;
V_36 = V_16 -> V_36 ;
V_13 = V_8 . V_13 ;
V_36 -> V_80 = 0 ;
if ( V_13 )
V_4 = F_43 ( V_36 , V_16 , V_13 , false ) ;
else
V_4 = F_44 ( V_36 , V_16 ) ;
V_79:
* V_77 = V_36 ;
return V_4 ;
}
static int F_45 ( struct V_81 * V_82 ,
struct V_50 * V_51 ,
struct V_50 * V_42 ,
const char * V_39 , bool V_83 )
{
struct V_16 * V_16 = NULL ;
struct V_14 * V_24 ;
T_3 V_59 = 0 ;
int V_4 = - V_26 ;
if ( ! V_51 -> V_53 || V_51 -> V_52 )
return - V_84 ;
V_16 = F_24 ( V_39 , V_83 ) ;
if ( ! V_16 )
return - V_48 ;
F_46 (map, pp->function, sym) {
if ( V_83 )
V_59 = V_24 -> V_28 ;
else
V_59 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) - V_16 -> V_21 ;
break;
}
if ( ! V_59 ) {
V_4 = - V_26 ;
goto V_11;
}
F_4 ( L_13 V_85 L_14 ,
V_51 -> V_53 , V_59 ) ;
V_4 = F_47 ( V_82 , ( unsigned long ) V_59 ,
V_42 ) ;
if ( V_4 <= 0 )
V_4 = ( ! V_4 ) ? - V_26 : V_4 ;
else {
V_42 -> V_86 += V_51 -> V_86 ;
V_42 -> line += V_51 -> line ;
V_42 -> V_87 = V_51 -> V_87 ;
V_4 = 0 ;
}
V_11:
F_48 ( V_16 ) ;
return V_4 ;
}
static int F_49 ( struct V_81 * V_82 ,
struct V_88 * V_89 ,
struct V_50 * V_90 )
{
int V_4 ;
memcpy ( V_90 , & V_89 -> V_91 , sizeof( * V_90 ) ) ;
memset ( & V_89 -> V_91 , 0 , sizeof( V_89 -> V_91 ) ) ;
V_4 = F_45 ( V_82 , V_90 , & V_89 -> V_91 ,
V_89 -> V_39 , V_89 -> V_83 ) ;
if ( V_4 < 0 )
memcpy ( & V_89 -> V_91 , V_90 , sizeof( * V_90 ) ) ;
return V_4 ;
}
static int F_50 ( struct V_81 * V_82 ,
struct V_92 * V_93 ,
const char * V_39 , bool V_40 )
{
struct V_50 V_51 = { . V_53 = V_93 -> V_53 ,
. V_52 = V_93 -> V_52 ,
. line = V_93 -> V_28 } ;
struct V_50 V_42 ;
int V_4 , V_94 = 0 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
if ( V_93 -> V_95 != V_96 )
V_94 = V_93 -> V_95 - V_93 -> V_28 ;
V_4 = F_45 ( V_82 , & V_51 , & V_42 ,
V_39 , V_40 ) ;
if ( ! V_4 ) {
V_93 -> V_53 = V_42 . V_53 ;
V_93 -> V_52 = V_42 . V_52 ;
V_93 -> V_28 = V_42 . line ;
if ( V_93 -> V_95 != V_96 )
V_93 -> V_95 = V_93 -> V_28 + V_94 ;
F_28 ( & V_51 ) ;
}
return V_4 ;
}
static struct V_81 * F_51 ( const char * V_29 , bool V_97 )
{
const char * V_98 = V_29 ;
char V_99 [ V_100 ] ;
struct V_81 * V_4 = NULL ;
struct V_36 * V_36 = NULL ;
int V_101 ;
if ( ! V_29 || ! strchr ( V_29 , '/' ) ) {
V_101 = F_41 ( V_29 , & V_36 ) ;
if ( V_101 < 0 ) {
if ( ! V_36 || V_36 -> V_80 == 0 ) {
if ( ! F_52 ( - V_101 , V_99 , V_100 ) )
strcpy ( V_99 , L_15 ) ;
} else
F_53 ( V_36 , V_99 , V_100 ) ;
if ( ! V_97 )
F_54 ( L_16 ,
V_29 ? : L_5 , V_99 ) ;
return NULL ;
}
V_98 = V_36 -> V_102 ;
}
V_4 = F_55 ( V_98 ) ;
if ( ! V_4 && ! V_97 ) {
F_7 ( L_17 , V_98 ) ;
if ( ! V_29 || ! F_56 ( V_98 , L_18 ) )
F_7 ( L_19 ) ;
else
F_7 ( L_20 ) ;
F_7 ( L_21 ) ;
}
return V_4 ;
}
static struct V_81 * F_57 ( const char * V_29 , bool V_97 )
{
const char * V_98 = V_29 ;
if ( ! V_29 )
V_98 = L_5 ;
if ( V_103 && ! strcmp ( V_103 , V_98 ) )
goto V_11;
free ( V_103 ) ;
V_103 = F_26 ( V_98 ) ;
if ( ! V_103 ) {
F_58 ( V_104 ) ;
V_104 = NULL ;
goto V_11;
}
V_104 = F_51 ( V_29 , V_97 ) ;
if ( ! V_104 )
F_59 ( & V_103 ) ;
V_11:
return V_104 ;
}
static void F_60 ( void )
{
F_58 ( V_104 ) ;
V_104 = NULL ;
F_59 ( & V_103 ) ;
}
static int F_61 ( const char * V_41 , unsigned long * V_59 )
{
T_4 * V_62 ;
T_5 V_63 ;
T_6 V_64 ;
int V_61 , V_4 = - V_26 ;
V_61 = F_34 ( V_41 , V_69 ) ;
if ( V_61 < 0 )
return - V_105 ;
V_62 = F_35 ( V_61 , V_70 , NULL ) ;
if ( V_62 == NULL ) {
V_4 = - V_48 ;
goto V_106;
}
if ( F_36 ( V_62 , & V_63 ) == NULL )
goto V_11;
if ( ! F_37 ( V_62 , & V_63 , & V_64 , L_22 , NULL ) )
goto V_11;
* V_59 = V_64 . V_107 - V_64 . V_108 ;
V_4 = 0 ;
V_11:
F_39 ( V_62 ) ;
V_106:
F_40 ( V_61 ) ;
return V_4 ;
}
static int F_62 ( struct V_109 * V_110 ,
struct V_50 * V_51 ,
bool V_111 )
{
struct V_81 * V_82 = NULL ;
unsigned long V_112 = 0 ;
T_3 V_18 = V_110 -> V_59 ;
int V_4 = - V_26 ;
if ( ! V_111 ) {
if ( ! V_18 ) {
V_4 = - V_48 ;
goto error;
}
V_4 = F_61 ( V_110 -> V_29 , & V_112 ) ;
if ( V_4 < 0 )
goto error;
V_18 += V_112 ;
} else if ( V_110 -> V_14 ) {
V_4 = F_18 ( V_110 -> V_14 , & V_18 ,
false , ! ! V_110 -> V_29 ) ;
if ( V_4 != 0 )
goto error;
V_18 += V_110 -> V_86 ;
}
F_4 ( L_23 V_85 L_24 , V_18 ,
V_110 -> V_29 ? : L_5 ) ;
V_82 = F_57 ( V_110 -> V_29 , V_113 <= 0 ) ;
if ( V_82 )
V_4 = F_47 ( V_82 ,
( unsigned long ) V_18 , V_51 ) ;
else
V_4 = - V_26 ;
if ( V_4 > 0 ) {
V_51 -> V_87 = V_110 -> V_87 ;
return 0 ;
}
error:
F_4 ( L_25 ) ;
return V_4 ? : - V_26 ;
}
static int F_63 ( struct V_109 * V_110 ,
struct V_16 * V_16 , unsigned long V_114 )
{
struct V_14 * V_24 ;
T_3 V_18 = V_110 -> V_59 - V_114 ;
V_24 = F_64 ( V_16 , V_18 ) ;
if ( ! V_24 )
return - V_26 ;
if ( strcmp ( V_24 -> V_15 , V_110 -> V_14 ) ) {
if ( ! V_110 -> V_115 )
V_110 -> V_115 = V_110 -> V_14 ;
else
free ( V_110 -> V_14 ) ;
V_110 -> V_14 = F_26 ( V_24 -> V_15 ) ;
if ( ! V_110 -> V_14 )
return - V_47 ;
}
V_110 -> V_86 = V_18 - V_24 -> V_28 ;
V_110 -> V_59 -= V_114 ;
return 0 ;
}
static int
F_65 ( struct V_55 * V_56 ,
int V_57 , const char * V_116 )
{
struct V_16 * V_16 ;
unsigned long V_112 = 0 ;
int V_58 , V_4 = 0 ;
V_16 = F_20 ( V_116 ) ;
if ( ! V_16 || F_61 ( V_116 , & V_112 ) < 0 ) {
F_7 ( L_26 , V_116 ) ;
return - V_48 ;
}
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_4 = F_63 ( & V_56 [ V_58 ] . V_91 ,
V_16 , V_112 ) ;
if ( V_4 < 0 )
break;
}
F_48 ( V_16 ) ;
return V_4 ;
}
static int F_66 ( struct V_55 * V_56 ,
int V_57 , const char * V_41 )
{
int V_58 , V_4 = 0 ;
unsigned long V_112 = 0 ;
if ( ! V_41 )
return 0 ;
V_4 = F_61 ( V_41 , & V_112 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_58 = 0 ; V_58 < V_57 && V_4 >= 0 ; V_58 ++ ) {
V_56 [ V_58 ] . V_91 . V_59 -= V_112 ;
V_56 [ V_58 ] . V_91 . V_29 = F_26 ( V_41 ) ;
if ( ! V_56 [ V_58 ] . V_91 . V_29 ) {
V_4 = - V_47 ;
break;
}
V_56 [ V_58 ] . V_83 = true ;
}
return V_4 ;
}
static int
F_67 ( struct V_55 * V_56 ,
int V_57 , const char * V_29 ,
struct V_81 * V_82 )
{
T_9 V_117 = 0 ;
int V_58 , V_4 = 0 ;
char * V_67 = NULL ;
struct V_16 * V_16 ;
if ( ! V_29 )
return 0 ;
V_16 = F_24 ( V_29 , false ) ;
if ( ! V_16 || F_68 ( V_82 , & V_117 , true ) < 0 ) {
F_7 ( L_26 , V_29 ) ;
return - V_48 ;
}
V_67 = F_33 ( V_29 ) ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_4 = F_63 ( & V_56 [ V_58 ] . V_91 ,
V_16 , ( unsigned long ) V_117 ) ;
if ( V_4 < 0 )
break;
V_56 [ V_58 ] . V_91 . V_29 =
F_26 ( V_67 ? V_67 : V_29 ) ;
if ( ! V_56 [ V_58 ] . V_91 . V_29 ) {
V_4 = - V_47 ;
break;
}
}
free ( V_67 ) ;
F_48 ( V_16 ) ;
return V_4 ;
}
static int
F_69 ( struct V_55 * V_56 ,
int V_57 )
{
struct V_19 * V_23 ;
char * V_90 ;
int V_58 , V_118 = 0 ;
if ( V_8 . V_119 )
return F_65 ( V_56 , V_57 ,
V_8 . V_13 ) ;
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_27 ) ;
return - V_48 ;
}
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
if ( ! V_56 [ V_58 ] . V_91 . V_59 )
continue;
if ( V_56 [ V_58 ] . V_91 . V_87 && ! F_70 () )
continue;
if ( F_31 ( V_56 [ V_58 ] . V_91 . V_14 ,
V_56 [ V_58 ] . V_91 . V_59 ) ) {
V_90 = NULL ;
V_118 ++ ;
} else {
V_90 = F_26 ( V_23 -> V_15 ) ;
if ( ! V_90 )
return - V_47 ;
}
if ( ! V_56 [ V_58 ] . V_91 . V_115 )
V_56 [ V_58 ] . V_91 . V_115 = V_56 [ V_58 ] . V_91 . V_14 ;
else
free ( V_56 [ V_58 ] . V_91 . V_14 ) ;
V_56 [ V_58 ] . V_91 . V_14 = V_90 ;
V_56 [ V_58 ] . V_91 . V_86 = V_56 [ V_58 ] . V_91 . V_59 -
V_23 -> V_25 ;
}
return V_118 ;
}
void __weak
F_71 ( struct V_88 * V_89 V_120 ,
int V_57 V_120 )
{
}
static int F_72 ( struct V_88 * V_89 ,
struct V_55 * V_56 ,
int V_57 , const char * V_29 ,
bool V_121 , struct V_81 * V_82 )
{
int V_4 ;
if ( V_121 )
V_4 = F_66 ( V_56 , V_57 , V_29 ) ;
else if ( V_29 )
V_4 = F_67 ( V_56 , V_57 ,
V_29 , V_82 ) ;
else
V_4 = F_69 ( V_56 , V_57 ) ;
if ( V_4 >= 0 )
F_71 ( V_89 , V_57 ) ;
return V_4 ;
}
static int F_73 ( struct V_88 * V_89 ,
struct V_55 * * V_56 )
{
bool V_122 = F_74 ( V_89 ) ;
struct V_50 V_90 ;
struct V_81 * V_82 ;
int V_57 , V_4 = 0 ;
V_82 = F_51 ( V_89 -> V_39 , ! V_122 ) ;
if ( ! V_82 ) {
if ( V_122 )
return - V_26 ;
F_4 ( L_28 ) ;
return 0 ;
}
F_4 ( L_29 ) ;
V_57 = F_75 ( V_82 , V_89 , V_56 ) ;
if ( V_57 == 0 ) {
V_4 = F_49 ( V_82 , V_89 , & V_90 ) ;
if ( ! V_4 ) {
V_57 = F_75 ( V_82 , V_89 , V_56 ) ;
F_28 ( & V_89 -> V_91 ) ;
memcpy ( & V_89 -> V_91 , & V_90 , sizeof( V_90 ) ) ;
}
}
if ( V_57 > 0 ) {
F_4 ( L_30 , V_57 ) ;
V_4 = F_72 ( V_89 , * V_56 , V_57 ,
V_89 -> V_39 , V_89 -> V_83 , V_82 ) ;
if ( V_4 < 0 || V_4 == V_57 ) {
F_4 ( L_31 , V_4 ) ;
F_29 ( * V_56 , V_57 ) ;
F_59 ( V_56 ) ;
V_57 = 0 ;
}
}
F_58 ( V_82 ) ;
if ( V_57 == 0 ) {
F_7 ( L_32 ,
F_76 ( & V_89 -> V_91 ) ) ;
return - V_26 ;
} else if ( V_57 < 0 ) {
F_4 ( L_33 , V_57 ) ;
if ( V_57 == - V_123 )
F_7 ( L_34
L_35 ) ;
if ( ! V_122 ) {
F_4 ( L_36 ) ;
return 0 ;
}
}
return V_57 ;
}
static int F_77 ( T_10 * V_124 , int V_125 , bool V_126 , bool V_127 )
{
char V_46 [ V_128 ] , V_129 [ V_100 ] ;
const char * V_130 = V_127 ? L_37 : V_131 ;
const char * V_132 = NULL ;
do {
if ( fgets ( V_46 , V_128 , V_124 ) == NULL )
goto error;
if ( V_126 )
continue;
if ( ! V_132 ) {
V_132 = V_127 ? L_38 : L_39 ;
F_78 ( stdout , V_130 , V_132 , V_125 ) ;
}
F_78 ( stdout , V_130 , L_40 , V_46 ) ;
} while ( strchr ( V_46 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_124 ) ) {
F_7 ( L_41 ,
F_52 ( V_105 , V_129 , sizeof( V_129 ) ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_79 ( T_10 * V_124 , int V_125 , bool V_126 , bool V_127 )
{
int V_133 = F_77 ( V_124 , V_125 , V_126 , V_127 ) ;
if ( V_133 == 0 ) {
F_7 ( L_42 ) ;
V_133 = - 1 ;
}
return V_133 ;
}
static int F_80 ( struct V_92 * V_93 , const char * V_29 ,
bool V_40 )
{
int V_125 = 1 ;
struct V_134 * V_135 ;
struct V_81 * V_82 ;
T_10 * V_124 ;
int V_4 ;
char * V_90 ;
char V_129 [ V_100 ] ;
V_82 = F_51 ( V_29 , false ) ;
if ( ! V_82 )
return - V_26 ;
V_4 = F_81 ( V_82 , V_93 ) ;
if ( ! V_4 ) {
V_4 = F_50 ( V_82 , V_93 , V_29 , V_40 ) ;
if ( ! V_4 )
V_4 = F_81 ( V_82 , V_93 ) ;
}
F_58 ( V_82 ) ;
if ( V_4 == 0 || V_4 == - V_26 ) {
F_7 ( L_43 ) ;
return - V_26 ;
} else if ( V_4 < 0 ) {
F_7 ( L_44 ) ;
return V_4 ;
}
V_90 = V_93 -> V_98 ;
V_4 = F_82 ( V_90 , V_93 -> V_136 , & V_93 -> V_98 ) ;
if ( V_90 != V_93 -> V_98 )
free ( V_90 ) ;
if ( V_4 < 0 ) {
F_7 ( L_45 ) ;
return V_4 ;
}
F_83 () ;
if ( V_93 -> V_53 )
fprintf ( stdout , L_46 , V_93 -> V_53 , V_93 -> V_98 ,
V_93 -> V_28 - V_93 -> V_86 ) ;
else
fprintf ( stdout , L_47 , V_93 -> V_98 , V_93 -> V_28 ) ;
V_124 = fopen ( V_93 -> V_98 , L_48 ) ;
if ( V_124 == NULL ) {
F_7 ( L_49 , V_93 -> V_98 ,
F_52 ( V_105 , V_129 , sizeof( V_129 ) ) ) ;
return - V_105 ;
}
while ( V_125 < V_93 -> V_28 ) {
V_4 = F_84 ( V_124 , V_125 ++ ) ;
if ( V_4 < 0 )
goto V_95;
}
F_85 (ln, lr->line_list) {
for (; V_135 -> V_58 > V_125 ; V_125 ++ ) {
V_4 = F_86 ( V_124 , V_125 - V_93 -> V_86 ) ;
if ( V_4 < 0 )
goto V_95;
}
V_4 = F_87 ( V_124 , V_125 ++ - V_93 -> V_86 ) ;
if ( V_4 < 0 )
goto V_95;
}
if ( V_93 -> V_95 == V_96 )
V_93 -> V_95 = V_125 + V_137 ;
while ( V_125 <= V_93 -> V_95 ) {
V_4 = F_88 ( V_124 , V_125 ++ - V_93 -> V_86 ) ;
if ( V_4 <= 0 )
break;
}
V_95:
fclose ( V_124 ) ;
return V_4 ;
}
int F_89 ( struct V_92 * V_93 , const char * V_29 , bool V_40 )
{
int V_4 ;
V_4 = F_2 ( V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_80 ( V_93 , V_29 , V_40 ) ;
F_8 () ;
return V_4 ;
}
static int F_90 ( struct V_81 * V_82 ,
struct V_88 * V_89 ,
struct V_138 * V_139 )
{
char * V_46 ;
int V_4 , V_58 , V_140 ;
struct V_141 * V_142 ;
struct V_143 * V_144 = NULL , * V_145 ;
struct V_50 V_90 ;
const char * V_146 ;
V_46 = F_76 ( & V_89 -> V_91 ) ;
if ( ! V_46 )
return - V_48 ;
F_4 ( L_50 , V_46 ) ;
V_4 = F_91 ( V_82 , V_89 , & V_144 ) ;
if ( ! V_4 ) {
V_4 = F_49 ( V_82 , V_89 , & V_90 ) ;
if ( ! V_4 ) {
V_4 = F_91 ( V_82 , V_89 ,
& V_144 ) ;
F_28 ( & V_90 ) ;
}
}
if ( V_4 <= 0 ) {
if ( V_4 == 0 || V_4 == - V_26 ) {
F_54 ( L_51 , V_46 ) ;
V_4 = - V_26 ;
} else
F_7 ( L_44 ) ;
goto V_95;
}
fprintf ( stdout , L_52 , V_46 ) ;
for ( V_58 = 0 ; V_58 < V_4 ; V_58 ++ ) {
V_145 = & V_144 [ V_58 ] ;
fprintf ( stdout , L_53 , V_145 -> V_91 . V_14 ,
V_145 -> V_91 . V_86 ) ;
F_59 ( & V_145 -> V_91 . V_14 ) ;
V_140 = 0 ;
if ( V_145 -> V_147 ) {
F_92 (node, vl->vars) {
V_146 = strchr ( V_142 -> V_148 , '\t' ) + 1 ;
if ( F_93 ( V_139 , V_146 ) ) {
fprintf ( stdout , L_54 , V_142 -> V_148 ) ;
V_140 ++ ;
}
}
F_94 ( V_145 -> V_147 ) ;
}
if ( V_140 == 0 )
fprintf ( stdout , L_55 ) ;
}
free ( V_144 ) ;
V_95:
free ( V_46 ) ;
return V_4 ;
}
int F_95 ( struct V_88 * V_149 , int V_150 ,
struct V_138 * V_139 )
{
int V_58 , V_4 = 0 ;
struct V_81 * V_82 ;
V_4 = F_2 ( V_149 -> V_83 ) ;
if ( V_4 < 0 )
return V_4 ;
V_82 = F_51 ( V_149 -> V_39 , false ) ;
if ( ! V_82 ) {
V_4 = - V_26 ;
goto V_11;
}
F_83 () ;
for ( V_58 = 0 ; V_58 < V_150 && V_4 >= 0 ; V_58 ++ )
V_4 = F_90 ( V_82 , & V_149 [ V_58 ] , V_139 ) ;
F_58 ( V_82 ) ;
V_11:
F_8 () ;
return V_4 ;
}
static void F_60 ( void )
{
}
static int
F_62 ( struct V_109 * V_110 V_120 ,
struct V_50 * V_51 V_120 ,
bool V_111 V_120 )
{
return - V_151 ;
}
static int F_73 ( struct V_88 * V_89 ,
struct V_55 * * V_56 V_120 )
{
if ( F_74 ( V_89 ) ) {
F_7 ( L_56 ) ;
return - V_151 ;
}
return 0 ;
}
int F_89 ( struct V_92 * V_93 V_120 ,
const char * V_29 V_120 ,
bool V_40 V_120 )
{
F_7 ( L_56 ) ;
return - V_151 ;
}
int F_95 ( struct V_88 * V_149 V_120 ,
int V_150 V_120 ,
struct V_138 * T_11 V_120 )
{
F_7 ( L_56 ) ;
return - V_151 ;
}
void F_96 ( struct V_92 * V_93 )
{
free ( V_93 -> V_53 ) ;
free ( V_93 -> V_52 ) ;
free ( V_93 -> V_98 ) ;
free ( V_93 -> V_136 ) ;
F_97 ( V_93 -> V_152 ) ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
}
int F_98 ( struct V_92 * V_93 )
{
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
V_93 -> V_152 = F_99 ( NULL ) ;
if ( ! V_93 -> V_152 )
return - V_47 ;
else
return 0 ;
}
static int F_100 ( char * * V_153 , int * V_154 , const char * V_155 )
{
const char * V_28 = * V_153 ;
V_105 = 0 ;
* V_154 = strtol ( * V_153 , V_153 , 0 ) ;
if ( V_105 || * V_153 == V_28 ) {
F_101 ( L_57 , V_155 ) ;
return - V_48 ;
}
return 0 ;
}
static bool F_102 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
int F_103 ( const char * V_156 , struct V_92 * V_93 )
{
char * V_157 , * V_52 , * V_15 = F_26 ( V_156 ) ;
int V_101 ;
if ( ! V_15 )
return - V_47 ;
V_93 -> V_28 = 0 ;
V_93 -> V_95 = V_96 ;
V_157 = strchr ( V_15 , ':' ) ;
if ( V_157 ) {
* V_157 ++ = '\0' ;
V_101 = F_100 ( & V_157 , & V_93 -> V_28 , L_58 ) ;
if ( V_101 )
goto V_101;
if ( * V_157 == '+' || * V_157 == '-' ) {
const char V_158 = * V_157 ++ ;
V_101 = F_100 ( & V_157 , & V_93 -> V_95 , L_59 ) ;
if ( V_101 )
goto V_101;
if ( V_158 == '+' ) {
V_93 -> V_95 += V_93 -> V_28 ;
V_93 -> V_95 -- ;
}
}
F_4 ( L_60 , V_93 -> V_28 , V_93 -> V_95 ) ;
V_101 = - V_48 ;
if ( V_93 -> V_28 > V_93 -> V_95 ) {
F_101 ( L_61
L_62 ) ;
goto V_101;
}
if ( * V_157 != '\0' ) {
F_101 ( L_63 , V_157 ) ;
goto V_101;
}
}
V_52 = strchr ( V_15 , '@' ) ;
if ( V_52 ) {
* V_52 = '\0' ;
V_93 -> V_52 = F_26 ( ++ V_52 ) ;
if ( V_93 -> V_52 == NULL ) {
V_101 = - V_47 ;
goto V_101;
}
V_93 -> V_53 = V_15 ;
} else if ( strchr ( V_15 , '/' ) || strchr ( V_15 , '.' ) )
V_93 -> V_52 = V_15 ;
else if ( F_102 ( V_15 ) )
V_93 -> V_53 = V_15 ;
else {
F_101 ( L_64 , V_15 ) ;
V_101 = - V_48 ;
goto V_101;
}
return 0 ;
V_101:
free ( V_15 ) ;
return V_101 ;
}
static int F_104 ( char * * V_156 , struct V_88 * V_89 )
{
char * V_153 ;
V_153 = strchr ( * V_156 , ':' ) ;
if ( V_153 ) {
* V_153 = '\0' ;
if ( ! V_89 -> V_159 && ! F_102 ( * V_156 ) )
goto V_160;
V_89 -> V_161 = F_26 ( * V_156 ) ;
if ( ! V_89 -> V_161 )
return - V_47 ;
* V_156 = V_153 + 1 ;
} else
V_89 -> V_161 = NULL ;
if ( ! V_89 -> V_159 && ! F_102 ( * V_156 ) ) {
V_160:
F_101 ( L_65
L_66 , * V_156 ) ;
return - V_48 ;
}
V_89 -> V_162 = F_26 ( * V_156 ) ;
if ( V_89 -> V_162 == NULL )
return - V_47 ;
return 0 ;
}
static int F_105 ( char * V_156 , struct V_88 * V_89 )
{
struct V_50 * V_51 = & V_89 -> V_91 ;
char * V_153 , * V_90 ;
char V_158 , V_163 = 0 ;
bool V_164 = false ;
int V_4 ;
if ( ! V_156 )
return - V_48 ;
if ( F_106 ( V_156 ) ) {
V_89 -> V_159 = true ;
if ( V_156 [ 0 ] == '%' )
V_156 ++ ;
}
V_153 = strpbrk ( V_156 , L_67 ) ;
if ( V_89 -> V_159 ) {
if ( V_153 ) {
if ( * V_153 != '@' ) {
F_101 ( L_68 ,
V_156 ) ;
return - V_48 ;
}
V_90 = F_107 ( V_153 + 1 ) ;
if ( V_90 ) {
V_89 -> V_39 = F_108 ( V_90 ) ;
free ( V_90 ) ;
} else
V_89 -> V_39 = F_26 ( V_153 + 1 ) ;
if ( ! V_89 -> V_39 )
return - V_47 ;
* V_153 = '\0' ;
}
V_4 = F_104 ( & V_156 , V_89 ) ;
if ( V_4 == 0 ) {
if ( F_109 ( & V_89 -> V_91 . V_53 , L_69 , V_89 -> V_162 ) < 0 )
V_4 = - V_105 ;
}
return V_4 ;
}
if ( V_153 && * V_153 == '=' ) {
* V_153 = '\0' ;
V_90 = V_153 + 1 ;
V_4 = F_104 ( & V_156 , V_89 ) ;
if ( V_4 < 0 )
return V_4 ;
V_156 = V_90 ;
}
if ( ! strpbrk ( V_156 , L_70 ) && ( V_153 = strpbrk ( V_156 , L_71 ) ) != NULL ) {
if ( memchr ( V_156 , '.' , V_153 - V_156 ) )
V_164 = true ;
}
V_153 = strpbrk ( V_156 , L_72 ) ;
if ( V_153 ) {
V_163 = * V_153 ;
* V_153 ++ = '\0' ;
}
if ( V_156 [ 0 ] == '\0' )
V_90 = NULL ;
else {
V_90 = F_26 ( V_156 ) ;
if ( V_90 == NULL )
return - V_47 ;
}
if ( V_164 )
V_51 -> V_52 = V_90 ;
else {
V_51 -> V_53 = V_90 ;
if ( V_90 && ! strncmp ( V_90 , L_73 , 2 ) ) {
V_51 -> V_165 = strtoul ( V_51 -> V_53 , & V_90 , 0 ) ;
if ( * V_90 != '\0' ) {
F_101 ( L_74 ) ;
return - V_48 ;
}
}
}
while ( V_153 ) {
V_156 = V_153 ;
V_158 = V_163 ;
if ( V_158 == ';' ) {
V_51 -> V_54 = F_26 ( V_156 ) ;
if ( V_51 -> V_54 == NULL )
return - V_47 ;
break;
}
V_153 = strpbrk ( V_156 , L_72 ) ;
if ( V_153 ) {
V_163 = * V_153 ;
* V_153 ++ = '\0' ;
}
switch ( V_158 ) {
case ':' :
V_51 -> line = strtoul ( V_156 , & V_90 , 0 ) ;
if ( * V_90 != '\0' ) {
F_101 ( L_75
L_76 ) ;
return - V_48 ;
}
break;
case '+' :
V_51 -> V_86 = strtoul ( V_156 , & V_90 , 0 ) ;
if ( * V_90 != '\0' ) {
F_101 ( L_77
L_78 ) ;
return - V_48 ;
}
break;
case '@' :
if ( V_51 -> V_52 ) {
F_101 ( L_79 ) ;
return - V_48 ;
}
V_51 -> V_52 = F_26 ( V_156 ) ;
if ( V_51 -> V_52 == NULL )
return - V_47 ;
break;
case '%' :
if ( strcmp ( V_156 , L_80 ) == 0 ) {
V_51 -> V_87 = 1 ;
} else {
F_101 ( L_81 , V_156 ) ;
return - V_84 ;
}
break;
default:
F_54 ( L_82 ,
__FILE__ , __LINE__ ) ;
return - V_84 ;
break;
}
}
if ( V_51 -> V_54 && V_51 -> line ) {
F_101 ( L_83
L_84 ) ;
return - V_48 ;
}
if ( V_51 -> V_54 && V_51 -> V_86 ) {
F_101 ( L_85 ) ;
return - V_48 ;
}
if ( V_51 -> line && V_51 -> V_86 ) {
F_101 ( L_86 ) ;
return - V_48 ;
}
if ( ! V_51 -> line && ! V_51 -> V_54 && V_51 -> V_52 && ! V_51 -> V_53 ) {
F_101 ( L_87
L_88 ) ;
return - V_48 ;
}
if ( V_51 -> V_86 && ! V_51 -> V_53 ) {
F_101 ( L_89 ) ;
return - V_48 ;
}
if ( ( V_51 -> V_86 || V_51 -> line || V_51 -> V_54 ) && V_51 -> V_87 ) {
F_101 ( L_90
L_91 ) ;
return - V_48 ;
}
F_4 ( L_92 ,
V_51 -> V_53 , V_51 -> V_52 , V_51 -> line , V_51 -> V_86 , V_51 -> V_87 ,
V_51 -> V_54 ) ;
return 0 ;
}
static int F_110 ( char * V_1 , struct V_166 * V_156 )
{
char * V_90 , * V_167 ;
struct V_168 * * V_169 ;
F_4 ( L_93 , V_1 ) ;
V_90 = strchr ( V_1 , '=' ) ;
if ( V_90 ) {
V_156 -> V_15 = F_111 ( V_1 , V_90 - V_1 ) ;
if ( V_156 -> V_15 == NULL )
return - V_47 ;
F_4 ( L_94 , V_156 -> V_15 ) ;
V_1 = V_90 + 1 ;
}
V_90 = strchr ( V_1 , ':' ) ;
if ( V_90 ) {
* V_90 = '\0' ;
V_156 -> type = F_26 ( V_90 + 1 ) ;
if ( V_156 -> type == NULL )
return - V_47 ;
F_4 ( L_95 , V_156 -> type ) ;
}
V_90 = strpbrk ( V_1 , L_96 ) ;
if ( ! F_112 ( V_1 ) || ! V_90 ) {
V_156 -> V_146 = F_26 ( V_1 ) ;
if ( V_156 -> V_146 == NULL )
return - V_47 ;
F_4 ( L_97 , V_156 -> V_146 ) ;
return 0 ;
}
V_156 -> V_146 = F_111 ( V_1 , V_90 - V_1 ) ;
if ( V_156 -> V_146 == NULL )
return - V_47 ;
V_167 = V_156 -> V_146 ;
F_4 ( L_98 , V_156 -> V_146 ) ;
V_169 = & V_156 -> V_170 ;
do {
* V_169 = F_113 ( sizeof( struct V_168 ) ) ;
if ( * V_169 == NULL )
return - V_47 ;
if ( * V_90 == '[' ) {
V_1 = V_90 ;
( * V_169 ) -> V_171 = strtol ( V_1 + 1 , & V_90 , 0 ) ;
( * V_169 ) -> V_172 = true ;
if ( * V_90 != ']' || V_90 == V_1 + 1 ) {
F_101 ( L_99
L_100 ) ;
return - V_48 ;
}
V_90 ++ ;
if ( * V_90 == '\0' )
V_90 = NULL ;
} else {
if ( * V_90 == '.' ) {
V_1 = V_90 + 1 ;
( * V_169 ) -> V_172 = false ;
} else if ( V_90 [ 1 ] == '>' ) {
V_1 = V_90 + 2 ;
( * V_169 ) -> V_172 = true ;
} else {
F_101 ( L_101 ,
V_1 ) ;
return - V_48 ;
}
V_90 = strpbrk ( V_1 , L_96 ) ;
}
if ( V_90 ) {
( * V_169 ) -> V_15 = F_111 ( V_1 , V_90 - V_1 ) ;
if ( ( * V_169 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_167 = ( * V_169 ) -> V_15 ;
F_4 ( L_102 , ( * V_169 ) -> V_15 , ( * V_169 ) -> V_172 ) ;
V_169 = & ( * V_169 ) -> V_173 ;
}
} while ( V_90 );
( * V_169 ) -> V_15 = F_26 ( V_1 ) ;
if ( ( * V_169 ) -> V_15 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_167 = ( * V_169 ) -> V_15 ;
F_4 ( L_103 , ( * V_169 ) -> V_15 , ( * V_169 ) -> V_172 ) ;
if ( ! V_156 -> V_15 ) {
V_156 -> V_15 = F_26 ( V_167 ) ;
if ( V_156 -> V_15 == NULL )
return - V_47 ;
}
return 0 ;
}
int F_114 ( const char * V_174 , struct V_88 * V_89 )
{
char * * V_175 ;
int V_176 , V_58 , V_4 = 0 ;
V_175 = F_115 ( V_174 , & V_176 ) ;
if ( ! V_175 ) {
F_4 ( L_104 ) ;
return - V_47 ;
}
if ( V_176 - 1 > V_177 ) {
F_101 ( L_105 , V_176 - 1 ) ;
V_4 = - V_178 ;
goto V_11;
}
V_4 = F_105 ( V_175 [ 0 ] , V_89 ) ;
if ( V_4 < 0 )
goto V_11;
V_89 -> V_179 = V_176 - 1 ;
V_89 -> args = F_113 ( sizeof( struct V_166 ) * V_89 -> V_179 ) ;
if ( V_89 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_58 = 0 ; V_58 < V_89 -> V_179 && V_4 >= 0 ; V_58 ++ ) {
V_4 = F_110 ( V_175 [ V_58 + 1 ] , & V_89 -> args [ V_58 ] ) ;
if ( V_4 >= 0 &&
F_112 ( V_89 -> args [ V_58 ] . V_146 ) && V_89 -> V_91 . V_87 ) {
F_101 ( L_106
L_107 ) ;
V_4 = - V_48 ;
}
}
V_11:
F_116 ( V_175 ) ;
return V_4 ;
}
bool F_117 ( struct V_88 * V_89 )
{
int V_58 = 0 ;
for ( V_58 = 0 ; V_58 < V_89 -> V_179 ; V_58 ++ )
if ( F_112 ( V_89 -> args [ V_58 ] . V_146 ) ||
! strcmp ( V_89 -> args [ V_58 ] . V_146 , V_180 ) ||
! strcmp ( V_89 -> args [ V_58 ] . V_146 , V_181 ) )
return true ;
return false ;
}
bool F_74 ( struct V_88 * V_89 )
{
if ( V_89 -> V_91 . V_52 || V_89 -> V_91 . line || V_89 -> V_91 . V_54 )
return true ;
if ( F_117 ( V_89 ) )
return true ;
return false ;
}
int F_118 ( const char * V_174 , struct V_55 * V_182 )
{
struct V_109 * V_110 = & V_182 -> V_91 ;
char V_183 ;
char * V_184 ;
char * V_185 = NULL , * V_186 , * V_187 , * V_188 , * V_189 ;
int V_4 , V_58 , V_176 ;
char * * V_175 ;
F_4 ( L_108 , V_174 ) ;
V_175 = F_115 ( V_174 , & V_176 ) ;
if ( ! V_175 ) {
F_4 ( L_104 ) ;
return - V_47 ;
}
if ( V_176 < 2 ) {
F_101 ( L_109 ) ;
V_4 = - V_178 ;
goto V_11;
}
V_185 = F_26 ( V_175 [ 0 ] ) ;
if ( V_185 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
V_187 = strtok_r ( V_185 , L_110 , & V_186 ) ;
V_188 = strtok_r ( NULL , L_111 , & V_186 ) ;
V_189 = strtok_r ( NULL , L_112 , & V_186 ) ;
if ( V_187 == NULL || strlen ( V_187 ) != 1 || V_188 == NULL
|| V_189 == NULL ) {
F_101 ( L_113 , V_175 [ 0 ] ) ;
V_4 = - V_48 ;
goto V_11;
}
V_183 = V_187 [ 0 ] ;
V_182 -> V_161 = F_26 ( V_188 ) ;
V_182 -> V_162 = F_26 ( V_189 ) ;
if ( V_182 -> V_161 == NULL || V_182 -> V_162 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
F_4 ( L_114 , V_182 -> V_161 , V_182 -> V_162 , V_183 ) ;
V_110 -> V_87 = ( V_183 == 'r' ) ;
V_184 = strchr ( V_175 [ 1 ] , ':' ) ;
if ( V_184 ) {
V_110 -> V_29 = F_111 ( V_175 [ 1 ] , V_184 - V_175 [ 1 ] ) ;
if ( ! V_110 -> V_29 ) {
V_4 = - V_47 ;
goto V_11;
}
V_182 -> V_83 = ( V_110 -> V_29 [ 0 ] == '/' ) ;
V_184 ++ ;
} else
V_184 = V_175 [ 1 ] ;
V_187 = strtok_r ( V_184 , L_115 , & V_186 ) ;
if ( V_187 [ 0 ] == '0' ) {
if ( strcmp ( V_187 , L_73 ) == 0 ) {
if ( ! V_175 [ 2 ] || strcmp ( V_175 [ 2 ] , L_116 ) ) {
V_4 = - V_48 ;
goto V_11;
}
V_110 -> V_59 = 0 ;
free ( V_175 [ 2 ] ) ;
for ( V_58 = 2 ; V_175 [ V_58 + 1 ] != NULL ; V_58 ++ )
V_175 [ V_58 ] = V_175 [ V_58 + 1 ] ;
V_175 [ V_58 ] = NULL ;
V_176 -= 1 ;
} else
V_110 -> V_59 = strtoul ( V_187 , NULL , 0 ) ;
} else {
V_110 -> V_14 = F_26 ( V_187 ) ;
if ( V_110 -> V_14 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
V_188 = strtok_r ( NULL , L_37 , & V_186 ) ;
if ( V_188 == NULL )
V_110 -> V_86 = 0 ;
else
V_110 -> V_86 = strtoul ( V_188 , NULL , 10 ) ;
}
V_182 -> V_179 = V_176 - 2 ;
V_182 -> args = F_113 ( sizeof( struct V_190 ) * V_182 -> V_179 ) ;
if ( V_182 -> args == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
for ( V_58 = 0 ; V_58 < V_182 -> V_179 ; V_58 ++ ) {
V_184 = strchr ( V_175 [ V_58 + 2 ] , '=' ) ;
if ( V_184 )
* V_184 ++ = '\0' ;
else
V_184 = V_175 [ V_58 + 2 ] ;
V_182 -> args [ V_58 ] . V_15 = F_26 ( V_175 [ V_58 + 2 ] ) ;
V_182 -> args [ V_58 ] . V_191 = F_26 ( V_184 ) ;
if ( V_182 -> args [ V_58 ] . V_15 == NULL || V_182 -> args [ V_58 ] . V_191 == NULL ) {
V_4 = - V_47 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
free ( V_185 ) ;
F_116 ( V_175 ) ;
return V_4 ;
}
char * F_119 ( struct V_166 * V_192 )
{
struct V_168 * V_170 = V_192 -> V_170 ;
struct V_193 V_46 ;
char * V_4 = NULL ;
int V_101 ;
if ( F_120 ( & V_46 , 64 ) < 0 )
return NULL ;
if ( V_192 -> V_15 && V_192 -> V_146 )
V_101 = F_121 ( & V_46 , L_117 , V_192 -> V_15 , V_192 -> V_146 ) ;
else
V_101 = F_122 ( & V_46 , V_192 -> V_15 ? : V_192 -> V_146 ) ;
if ( V_101 )
goto V_11;
while ( V_170 ) {
if ( V_170 -> V_15 [ 0 ] == '[' )
V_101 = F_122 ( & V_46 , V_170 -> V_15 ) ;
else
V_101 = F_121 ( & V_46 , L_118 , V_170 -> V_172 ? L_119 : L_120 ,
V_170 -> V_15 ) ;
V_170 = V_170 -> V_173 ;
if ( V_101 )
goto V_11;
}
if ( V_192 -> type )
if ( F_121 ( & V_46 , L_121 , V_192 -> type ) < 0 )
goto V_11;
V_4 = F_123 ( & V_46 , NULL ) ;
V_11:
F_124 ( & V_46 ) ;
return V_4 ;
}
char * F_76 ( struct V_50 * V_51 )
{
struct V_193 V_46 ;
char * V_90 , * V_4 = NULL ;
int V_94 , V_101 = 0 ;
if ( F_120 ( & V_46 , 64 ) < 0 )
return NULL ;
if ( V_51 -> V_53 ) {
if ( F_122 ( & V_46 , V_51 -> V_53 ) < 0 )
goto V_11;
if ( V_51 -> V_86 )
V_101 = F_121 ( & V_46 , L_122 , V_51 -> V_86 ) ;
else if ( V_51 -> line )
V_101 = F_121 ( & V_46 , L_123 , V_51 -> line ) ;
else if ( V_51 -> V_87 )
V_101 = F_122 ( & V_46 , L_124 ) ;
if ( V_101 )
goto V_11;
}
if ( V_51 -> V_52 ) {
V_90 = V_51 -> V_52 ;
V_94 = strlen ( V_90 ) ;
if ( V_94 > 30 ) {
V_90 = strchr ( V_51 -> V_52 + V_94 - 30 , '/' ) ;
V_90 = V_90 ? V_90 + 1 : V_51 -> V_52 + V_94 - 30 ;
}
V_101 = F_121 ( & V_46 , L_125 , V_90 ) ;
if ( ! V_101 && ! V_51 -> V_53 && V_51 -> line )
V_101 = F_121 ( & V_46 , L_123 , V_51 -> line ) ;
}
if ( ! V_101 )
V_4 = F_123 ( & V_46 , NULL ) ;
V_11:
F_124 ( & V_46 ) ;
return V_4 ;
}
char * F_125 ( struct V_88 * V_89 )
{
struct V_193 V_46 ;
char * V_90 , * V_4 = NULL ;
int V_58 ;
if ( F_120 ( & V_46 , 64 ) )
return NULL ;
if ( V_89 -> V_162 )
if ( F_121 ( & V_46 , L_126 , V_89 -> V_161 ? : V_49 ,
V_89 -> V_162 ) < 0 )
goto V_11;
V_90 = F_76 ( & V_89 -> V_91 ) ;
if ( ! V_90 || F_122 ( & V_46 , V_90 ) < 0 )
goto V_11;
free ( V_90 ) ;
for ( V_58 = 0 ; V_58 < V_89 -> V_179 ; V_58 ++ ) {
V_90 = F_119 ( V_89 -> args + V_58 ) ;
if ( ! V_90 || F_121 ( & V_46 , L_127 , V_90 ) < 0 )
goto V_11;
free ( V_90 ) ;
}
V_4 = F_123 ( & V_46 , NULL ) ;
V_11:
F_124 ( & V_46 ) ;
return V_4 ;
}
static int F_126 ( struct V_194 * V_172 ,
struct V_193 * V_46 , int V_195 )
{
int V_101 ;
if ( V_172 -> V_173 ) {
V_195 = F_126 ( V_172 -> V_173 , V_46 ,
V_195 + 1 ) ;
if ( V_195 < 0 )
return V_195 ;
}
V_101 = F_121 ( V_46 , L_128 , V_172 -> V_86 ) ;
return ( V_101 < 0 ) ? V_101 : V_195 ;
}
static int F_127 ( struct V_190 * V_156 ,
struct V_193 * V_46 )
{
struct V_194 * V_172 = V_156 -> V_172 ;
int V_195 = 0 , V_101 ;
if ( V_156 -> V_15 )
V_101 = F_121 ( V_46 , L_129 , V_156 -> V_15 ) ;
else
V_101 = F_128 ( V_46 , ' ' ) ;
if ( V_101 )
return V_101 ;
if ( V_156 -> V_191 [ 0 ] == '@' && V_156 -> V_172 )
V_172 = V_172 -> V_173 ;
if ( V_172 ) {
V_195 = F_126 ( V_172 , V_46 , 1 ) ;
if ( V_195 < 0 )
return V_195 ;
}
if ( V_156 -> V_191 [ 0 ] == '@' && V_156 -> V_172 )
V_101 = F_121 ( V_46 , L_130 , V_156 -> V_191 , V_156 -> V_172 -> V_86 ) ;
else
V_101 = F_122 ( V_46 , V_156 -> V_191 ) ;
while ( ! V_101 && V_195 -- )
V_101 = F_128 ( V_46 , ')' ) ;
if ( ! V_101 && V_156 -> type )
V_101 = F_121 ( V_46 , L_121 , V_156 -> type ) ;
return V_101 ;
}
char * F_129 ( struct V_55 * V_182 )
{
struct V_109 * V_110 = & V_182 -> V_91 ;
struct V_193 V_46 ;
char * V_4 = NULL ;
int V_58 , V_101 ;
if ( V_182 -> V_83 && ! V_110 -> V_29 )
return NULL ;
if ( F_120 ( & V_46 , 32 ) < 0 )
return NULL ;
if ( F_121 ( & V_46 , L_131 , V_110 -> V_87 ? 'r' : 'p' ,
V_182 -> V_161 , V_182 -> V_162 ) < 0 )
goto error;
if ( V_182 -> V_83 && ! V_110 -> V_59 ) {
if ( ! V_110 -> V_14 || strcmp ( V_110 -> V_14 , L_132 ) )
goto error;
}
if ( V_182 -> V_83 )
V_101 = F_121 ( & V_46 , L_133 , V_110 -> V_29 , V_110 -> V_59 ) ;
else if ( ! strncmp ( V_110 -> V_14 , L_73 , 2 ) )
V_101 = F_121 ( & V_46 , L_134 , V_110 -> V_29 ? : L_37 ,
V_110 -> V_29 ? L_110 : L_37 , V_110 -> V_59 ) ;
else
V_101 = F_121 ( & V_46 , L_135 , V_110 -> V_29 ? : L_37 ,
V_110 -> V_29 ? L_110 : L_37 , V_110 -> V_14 , V_110 -> V_86 ) ;
if ( V_101 )
goto error;
for ( V_58 = 0 ; V_58 < V_182 -> V_179 ; V_58 ++ )
if ( F_127 ( & V_182 -> args [ V_58 ] , & V_46 ) < 0 )
goto error;
V_4 = F_123 ( & V_46 , NULL ) ;
error:
F_124 ( & V_46 ) ;
return V_4 ;
}
static int F_130 ( struct V_109 * V_110 ,
struct V_50 * V_51 ,
bool V_111 )
{
struct V_14 * V_24 = NULL ;
struct V_16 * V_16 = NULL ;
T_3 V_18 = V_110 -> V_59 ;
int V_4 = - V_26 ;
if ( ! V_111 ) {
V_16 = F_20 ( V_110 -> V_29 ) ;
if ( ! V_16 )
goto V_11;
V_24 = F_64 ( V_16 , V_18 ) ;
} else {
if ( V_110 -> V_14 && ! V_18 ) {
if ( F_18 ( V_110 -> V_14 ,
& V_18 , true , false ) < 0 )
goto V_11;
}
if ( V_18 ) {
V_18 += V_110 -> V_86 ;
V_24 = F_12 ( V_18 , & V_16 ) ;
}
}
if ( ! V_24 )
goto V_11;
V_51 -> V_87 = V_110 -> V_87 ;
V_51 -> V_86 = V_18 - V_16 -> V_27 ( V_16 , V_24 -> V_28 ) ;
V_51 -> V_53 = F_26 ( V_24 -> V_15 ) ;
V_4 = V_51 -> V_53 ? 0 : - V_47 ;
V_11:
if ( V_16 && ! V_111 ) {
F_48 ( V_16 ) ;
}
return V_4 ;
}
static int F_131 ( struct V_109 * V_110 ,
struct V_50 * V_51 ,
bool V_111 )
{
char V_46 [ 128 ] ;
int V_4 ;
V_4 = F_62 ( V_110 , V_51 , V_111 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_130 ( V_110 , V_51 , V_111 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( L_136 ) ;
if ( V_110 -> V_14 ) {
V_51 -> V_53 = F_26 ( V_110 -> V_14 ) ;
V_51 -> V_86 = V_110 -> V_86 ;
} else {
V_4 = F_1 ( V_46 , 128 , L_137 V_85 , ( T_3 ) V_110 -> V_59 ) ;
if ( V_4 < 0 )
return V_4 ;
V_51 -> V_53 = F_26 ( V_46 ) ;
V_51 -> V_86 = 0 ;
}
if ( V_51 -> V_53 == NULL )
return - V_47 ;
V_51 -> V_87 = V_110 -> V_87 ;
return 0 ;
}
static int F_132 ( struct V_55 * V_182 ,
struct V_88 * V_89 , bool V_111 )
{
struct V_193 V_46 = V_196 ;
int V_58 , V_4 ;
V_89 -> V_162 = F_26 ( V_182 -> V_162 ) ;
V_89 -> V_161 = F_26 ( V_182 -> V_161 ) ;
if ( V_89 -> V_162 == NULL || V_89 -> V_161 == NULL )
return - V_47 ;
V_4 = F_131 ( & V_182 -> V_91 , & V_89 -> V_91 , V_111 ) ;
if ( V_4 < 0 )
return V_4 ;
V_89 -> V_179 = V_182 -> V_179 ;
V_89 -> args = F_113 ( sizeof( struct V_166 ) * V_89 -> V_179 ) ;
if ( V_89 -> args == NULL )
return - V_47 ;
for ( V_58 = 0 ; V_58 < V_182 -> V_179 && V_4 >= 0 ; V_58 ++ ) {
if ( V_182 -> args [ V_58 ] . V_15 )
V_89 -> args [ V_58 ] . V_15 = F_26 ( V_182 -> args [ V_58 ] . V_15 ) ;
else {
if ( ( V_4 = F_120 ( & V_46 , 32 ) ) < 0 )
goto error;
V_4 = F_127 ( & V_182 -> args [ V_58 ] , & V_46 ) ;
V_89 -> args [ V_58 ] . V_15 = F_123 ( & V_46 , NULL ) ;
}
if ( V_89 -> args [ V_58 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_47 ;
}
error:
if ( V_4 < 0 )
F_133 ( V_89 ) ;
return V_4 ;
}
void F_133 ( struct V_88 * V_89 )
{
struct V_168 * V_170 , * V_173 ;
int V_58 ;
free ( V_89 -> V_162 ) ;
free ( V_89 -> V_161 ) ;
free ( V_89 -> V_39 ) ;
F_28 ( & V_89 -> V_91 ) ;
for ( V_58 = 0 ; V_58 < V_89 -> V_179 ; V_58 ++ ) {
free ( V_89 -> args [ V_58 ] . V_15 ) ;
free ( V_89 -> args [ V_58 ] . V_146 ) ;
free ( V_89 -> args [ V_58 ] . type ) ;
V_170 = V_89 -> args [ V_58 ] . V_170 ;
while ( V_170 ) {
V_173 = V_170 -> V_173 ;
F_59 ( & V_170 -> V_15 ) ;
free ( V_170 ) ;
V_170 = V_173 ;
}
}
free ( V_89 -> args ) ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
}
static int F_134 ( struct V_50 * V_197 ,
struct V_50 * V_198 )
{
V_197 -> V_52 = F_135 ( V_198 -> V_52 , V_199 ) ;
V_197 -> V_53 = F_135 ( V_198 -> V_53 , V_199 ) ;
V_197 -> V_54 = F_135 ( V_198 -> V_54 , V_199 ) ;
V_197 -> line = V_198 -> line ;
V_197 -> V_87 = V_198 -> V_87 ;
V_197 -> V_86 = V_198 -> V_86 ;
return 0 ;
V_199:
F_28 ( V_197 ) ;
return - V_47 ;
}
static int F_136 ( struct V_166 * V_197 ,
struct V_166 * V_198 )
{
struct V_168 * V_170 , * * V_200 ;
V_197 -> V_15 = F_135 ( V_198 -> V_15 , V_199 ) ;
V_197 -> V_146 = F_135 ( V_198 -> V_146 , V_199 ) ;
V_197 -> type = F_135 ( V_198 -> type , V_199 ) ;
V_170 = V_198 -> V_170 ;
V_200 = & ( V_197 -> V_170 ) ;
while ( V_170 ) {
* V_200 = F_113 ( sizeof( * V_170 ) ) ;
if ( ! * V_200 )
goto V_199;
( * V_200 ) -> V_15 = F_135 ( V_170 -> V_15 , V_199 ) ;
( * V_200 ) -> V_171 = V_170 -> V_171 ;
( * V_200 ) -> V_172 = V_170 -> V_172 ;
V_170 = V_170 -> V_173 ;
V_200 = & ( ( * V_200 ) -> V_173 ) ;
}
return 0 ;
V_199:
return - V_47 ;
}
int F_137 ( struct V_88 * V_197 ,
struct V_88 * V_198 )
{
int V_58 ;
V_197 -> V_162 = F_135 ( V_198 -> V_162 , V_199 ) ;
V_197 -> V_161 = F_135 ( V_198 -> V_161 , V_199 ) ;
V_197 -> V_39 = F_135 ( V_198 -> V_39 , V_199 ) ;
V_197 -> V_83 = V_198 -> V_83 ;
if ( F_134 ( & V_197 -> V_91 , & V_198 -> V_91 ) < 0 )
goto V_199;
V_197 -> args = F_113 ( sizeof( struct V_166 ) * V_198 -> V_179 ) ;
if ( ! V_197 -> args )
goto V_199;
V_197 -> V_179 = V_198 -> V_179 ;
for ( V_58 = 0 ; V_58 < V_198 -> V_179 ; V_58 ++ )
if ( F_136 ( & V_197 -> args [ V_58 ] , & V_198 -> args [ V_58 ] ) < 0 )
goto V_199;
return 0 ;
V_199:
F_133 ( V_197 ) ;
return - V_47 ;
}
void F_30 ( struct V_55 * V_182 )
{
struct V_194 * V_172 , * V_173 ;
int V_58 ;
free ( V_182 -> V_162 ) ;
free ( V_182 -> V_161 ) ;
free ( V_182 -> V_91 . V_14 ) ;
free ( V_182 -> V_91 . V_115 ) ;
free ( V_182 -> V_91 . V_29 ) ;
for ( V_58 = 0 ; V_58 < V_182 -> V_179 ; V_58 ++ ) {
free ( V_182 -> args [ V_58 ] . V_15 ) ;
free ( V_182 -> args [ V_58 ] . V_191 ) ;
free ( V_182 -> args [ V_58 ] . type ) ;
V_172 = V_182 -> args [ V_58 ] . V_172 ;
while ( V_172 ) {
V_173 = V_172 -> V_173 ;
free ( V_172 ) ;
V_172 = V_173 ;
}
}
free ( V_182 -> args ) ;
memset ( V_182 , 0 , sizeof( * V_182 ) ) ;
}
static void F_138 ( struct V_201 * V_202 )
{
struct V_203 * V_142 ;
while ( ! F_139 ( V_202 ) ) {
V_142 = F_140 ( V_202 ,
struct V_203 , V_204 ) ;
F_141 ( & V_142 -> V_204 ) ;
free ( V_142 -> V_14 ) ;
free ( V_142 ) ;
}
}
static int F_142 ( struct V_201 * V_202 )
{
struct V_203 * V_142 ;
const char * V_205 = F_143 () ;
char V_46 [ V_206 ] , * V_184 ;
T_10 * V_124 ;
int V_4 ;
if ( V_205 == NULL )
return - V_84 ;
V_4 = F_1 ( V_46 , V_206 , L_138 , V_205 ) ;
if ( V_4 < 0 )
return V_4 ;
V_124 = fopen ( V_46 , L_48 ) ;
if ( ! V_124 )
return - V_105 ;
V_4 = 0 ;
while ( fgets ( V_46 , V_206 , V_124 ) ) {
V_142 = F_113 ( sizeof( * V_142 ) ) ;
if ( ! V_142 ) {
V_4 = - V_47 ;
break;
}
F_144 ( & V_142 -> V_204 ) ;
F_145 ( & V_142 -> V_204 , V_202 ) ;
if ( sscanf ( V_46 , L_139 , & V_142 -> V_28 , & V_142 -> V_95 ) != 2 ) {
V_4 = - V_48 ;
break;
}
V_184 = strchr ( V_46 , '\t' ) ;
if ( V_184 ) {
V_184 ++ ;
if ( V_184 [ strlen ( V_184 ) - 1 ] == '\n' )
V_184 [ strlen ( V_184 ) - 1 ] = '\0' ;
} else
V_184 = ( char * ) L_140 ;
V_142 -> V_14 = F_26 ( V_184 ) ;
if ( ! V_142 -> V_14 ) {
V_4 = - V_47 ;
break;
}
F_146 ( L_141 ,
V_142 -> V_28 , V_142 -> V_95 , V_142 -> V_14 ) ;
V_4 ++ ;
}
if ( V_4 < 0 )
F_138 ( V_202 ) ;
fclose ( V_124 ) ;
return V_4 ;
}
static struct V_203 *
F_147 ( struct V_201 * V_202 ,
unsigned long V_59 )
{
struct V_203 * V_142 ;
F_148 (node, blacklist, list) {
if ( V_142 -> V_28 <= V_59 && V_59 <= V_142 -> V_95 )
return V_142 ;
}
return NULL ;
}
static void F_149 ( void )
{
if ( ! F_139 ( & V_207 ) )
return;
if ( F_142 ( & V_207 ) < 0 )
F_4 ( L_142 ) ;
}
static void F_150 ( void )
{
F_138 ( & V_207 ) ;
}
static bool F_32 ( unsigned long V_59 )
{
return ! ! F_147 ( & V_207 , V_59 ) ;
}
static int F_151 ( const char * V_161 , const char * V_162 ,
struct V_88 * V_89 ,
const char * V_29 ,
struct V_193 * V_42 )
{
int V_58 , V_4 ;
char * V_46 ;
if ( F_109 ( & V_46 , L_143 , V_161 , V_162 ) < 0 )
return - V_105 ;
V_4 = F_121 ( V_42 , L_144 , V_46 ) ;
free ( V_46 ) ;
if ( V_4 )
return V_4 ;
V_46 = F_76 ( & V_89 -> V_91 ) ;
if ( ! V_46 )
return - V_47 ;
V_4 = F_122 ( V_42 , V_46 ) ;
free ( V_46 ) ;
if ( ! V_4 && V_29 )
V_4 = F_121 ( V_42 , L_145 , V_29 ) ;
if ( ! V_4 && V_89 -> V_179 > 0 ) {
V_4 = F_152 ( V_42 , L_146 , 5 ) ;
for ( V_58 = 0 ; ! V_4 && V_58 < V_89 -> V_179 ; V_58 ++ ) {
V_46 = F_119 ( & V_89 -> args [ V_58 ] ) ;
if ( ! V_46 )
return - V_47 ;
V_4 = F_121 ( V_42 , L_127 , V_46 ) ;
free ( V_46 ) ;
}
}
if ( ! V_4 )
V_4 = F_128 ( V_42 , ')' ) ;
return V_4 ;
}
int F_153 ( const char * V_161 , const char * V_162 ,
struct V_88 * V_89 ,
const char * V_29 , bool V_208 )
{
struct V_193 V_46 = V_196 ;
int V_4 ;
V_4 = F_151 ( V_161 , V_162 , V_89 , V_29 , & V_46 ) ;
if ( V_4 >= 0 ) {
if ( V_208 )
printf ( L_97 , V_46 . V_46 ) ;
else
F_154 ( L_97 , V_46 . V_46 ) ;
}
F_124 ( & V_46 ) ;
return V_4 ;
}
static bool F_155 ( struct V_55 * V_182 ,
struct V_138 * T_11 )
{
char V_90 [ 128 ] ;
if ( F_93 ( T_11 , V_182 -> V_162 ) )
return true ;
if ( F_1 ( V_90 , 128 , L_143 , V_182 -> V_161 , V_182 -> V_162 ) < 0 )
return false ;
return F_93 ( T_11 , V_90 ) ;
}
static int F_156 ( int V_61 , bool V_111 ,
struct V_138 * T_11 )
{
int V_4 = 0 ;
struct V_55 V_182 ;
struct V_88 V_89 ;
struct V_209 * V_210 ;
struct V_141 * V_211 ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_210 = F_157 ( V_61 ) ;
if ( ! V_210 )
return - V_47 ;
F_92 (ent, rawlist) {
V_4 = F_118 ( V_211 -> V_148 , & V_182 ) ;
if ( V_4 >= 0 ) {
if ( ! F_155 ( & V_182 , T_11 ) )
goto V_173;
V_4 = F_132 ( & V_182 , & V_89 ,
V_111 ) ;
if ( V_4 < 0 )
goto V_173;
V_4 = F_153 ( V_89 . V_161 , V_89 . V_162 ,
& V_89 , V_182 . V_91 . V_29 ,
true ) ;
}
V_173:
F_133 ( & V_89 ) ;
F_30 ( & V_182 ) ;
if ( V_4 < 0 )
break;
}
F_94 ( V_210 ) ;
F_60 () ;
return V_4 ;
}
int F_158 ( struct V_138 * T_11 )
{
int V_212 , V_213 , V_4 ;
F_83 () ;
if ( V_214 . V_215 )
return F_159 ( T_11 ) ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_160 ( & V_212 , & V_213 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_212 >= 0 )
V_4 = F_156 ( V_212 , true , T_11 ) ;
if ( V_213 >= 0 && V_4 >= 0 )
V_4 = F_156 ( V_213 , false , T_11 ) ;
if ( V_212 > 0 )
F_40 ( V_212 ) ;
if ( V_213 > 0 )
F_40 ( V_213 ) ;
F_8 () ;
return V_4 ;
}
static int F_161 ( char * V_46 , T_1 V_94 , const char * V_216 ,
struct V_209 * V_217 , bool V_218 )
{
int V_58 , V_4 ;
char * V_184 , * V_219 ;
if ( * V_216 == '.' )
V_216 ++ ;
V_219 = F_26 ( V_216 ) ;
if ( ! V_219 )
return - V_47 ;
V_184 = strchr ( V_219 , '.' ) ;
if ( V_184 && V_184 != V_219 )
* V_184 = '\0' ;
V_4 = F_1 ( V_46 , V_94 , L_40 , V_219 ) ;
if ( V_4 < 0 ) {
F_4 ( L_147 , V_4 ) ;
goto V_11;
}
if ( ! F_162 ( V_217 , V_46 ) )
goto V_11;
if ( ! V_218 ) {
F_7 ( L_148
L_149
L_150
L_151 ,
V_46 ) ;
V_4 = - V_220 ;
goto V_11;
}
for ( V_58 = 1 ; V_58 < V_221 ; V_58 ++ ) {
V_4 = F_1 ( V_46 , V_94 , L_152 , V_219 , V_58 ) ;
if ( V_4 < 0 ) {
F_4 ( L_147 , V_4 ) ;
goto V_11;
}
if ( ! F_162 ( V_217 , V_46 ) )
break;
}
if ( V_58 == V_221 ) {
F_7 ( L_153 ) ;
V_4 = - V_178 ;
}
V_11:
free ( V_219 ) ;
return V_4 ;
}
static void F_163 ( struct V_55 * V_182 )
{
int V_58 ;
char * V_46 = F_129 ( V_182 ) ;
if ( ! V_182 -> V_83 || V_182 -> V_179 == 0 || ! V_46 )
goto V_11;
for ( V_58 = 0 ; V_58 < V_182 -> V_179 ; V_58 ++ )
if ( F_164 ( V_182 -> args [ V_58 ] . V_191 , L_154 ) ) {
F_7 ( L_155
L_156 ,
V_182 -> args [ V_58 ] . V_191 ) ;
break;
}
V_11:
free ( V_46 ) ;
}
static int F_165 ( struct V_55 * V_182 ,
struct V_88 * V_89 ,
struct V_209 * V_217 ,
bool V_218 )
{
const char * V_162 , * V_161 ;
char V_46 [ 64 ] ;
int V_4 ;
if ( V_89 -> V_162 && ! V_89 -> V_159 )
V_162 = V_89 -> V_162 ;
else if ( V_182 -> V_162 )
V_162 = V_182 -> V_162 ;
else {
if ( V_89 -> V_91 . V_53 &&
( strncmp ( V_89 -> V_91 . V_53 , L_73 , 2 ) != 0 ) &&
! F_166 ( V_89 -> V_91 . V_53 ) )
V_162 = V_89 -> V_91 . V_53 ;
else
V_162 = V_182 -> V_91 . V_115 ;
}
if ( V_89 -> V_161 && ! V_89 -> V_159 )
V_161 = V_89 -> V_161 ;
else if ( V_182 -> V_161 )
V_161 = V_182 -> V_161 ;
else
V_161 = V_49 ;
V_4 = F_161 ( V_46 , 64 , V_162 ,
V_217 , V_218 ) ;
if ( V_4 < 0 )
return V_4 ;
V_162 = V_46 ;
V_182 -> V_162 = F_26 ( V_162 ) ;
V_182 -> V_161 = F_26 ( V_161 ) ;
if ( V_182 -> V_162 == NULL || V_182 -> V_161 == NULL )
return - V_47 ;
F_167 ( V_217 , V_162 ) ;
return 0 ;
}
static int F_168 ( bool V_121 ,
struct V_209 * * V_217 )
{
int V_61 ;
V_61 = F_169 ( V_222 | ( V_121 ? V_223 : 0 ) ) ;
if ( V_61 < 0 )
return V_61 ;
* V_217 = F_170 ( V_61 ) ;
if ( ! ( * V_217 ) ) {
F_4 ( L_157 ) ;
F_40 ( V_61 ) ;
return - V_47 ;
}
return V_61 ;
}
static int F_171 ( struct V_88 * V_89 ,
struct V_55 * V_56 ,
int V_57 , bool V_218 )
{
int V_58 , V_61 [ 2 ] = { - 1 , - 1 } , V_224 , V_4 ;
struct V_55 * V_182 = NULL ;
struct V_225 * V_215 = NULL ;
struct V_209 * V_217 [ 2 ] = { NULL , NULL } ;
V_224 = V_89 -> V_83 ? 1 : 0 ;
V_61 [ V_224 ] = F_168 ( V_224 , & V_217 [ V_224 ] ) ;
if ( V_61 [ V_224 ] < 0 )
return V_61 [ V_224 ] ;
V_4 = 0 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_182 = & V_56 [ V_58 ] ;
V_224 = V_182 -> V_83 ? 1 : 0 ;
if ( V_61 [ V_224 ] == - 1 ) {
V_61 [ V_224 ] = F_168 ( V_224 ,
& V_217 [ V_224 ] ) ;
if ( V_61 [ V_224 ] < 0 )
goto V_226;
}
if ( ! V_182 -> V_91 . V_14 && ! V_89 -> V_83 )
continue;
V_4 = F_165 ( V_182 , V_89 , V_217 [ V_224 ] ,
V_218 ) ;
if ( V_4 < 0 )
break;
V_4 = F_172 ( V_61 [ V_224 ] , V_182 ) ;
if ( V_4 < 0 )
break;
V_218 = true ;
}
if ( V_4 == - V_48 && V_89 -> V_83 )
F_163 ( V_182 ) ;
if ( V_4 == 0 && V_214 . V_215 ) {
V_215 = F_173 ( V_89 -> V_39 ) ;
if ( ! V_215 ||
F_174 ( V_215 , V_89 , V_56 , V_57 ) < 0 ||
F_175 ( V_215 ) < 0 )
F_7 ( L_158 ) ;
F_176 ( V_215 ) ;
}
V_226:
for ( V_224 = 0 ; V_224 < 2 ; V_224 ++ ) {
F_94 ( V_217 [ V_224 ] ) ;
if ( V_61 [ V_224 ] >= 0 )
F_40 ( V_61 [ V_224 ] ) ;
}
return V_4 ;
}
static int F_177 ( struct V_16 * V_16 , char * V_15 ,
struct V_14 * * V_227 )
{
int V_79 = 0 ;
struct V_14 * V_24 ;
struct V_228 * V_90 ;
if ( F_16 ( V_16 ) < 0 )
return 0 ;
F_178 (map, sym, tmp) {
if ( F_164 ( V_24 -> V_15 , V_15 ) ) {
V_79 ++ ;
if ( V_227 && V_79 < V_214 . V_229 )
V_227 [ V_79 - 1 ] = V_24 ;
}
}
return V_79 ;
}
void __weak F_179 ( struct V_88 * V_89 V_120 ,
struct V_55 * V_182 V_120 ,
struct V_16 * V_16 V_120 ,
struct V_14 * V_24 V_120 ) { }
static int F_180 ( struct V_88 * V_89 ,
struct V_55 * * V_56 )
{
struct V_16 * V_16 = NULL ;
struct V_19 * V_23 = NULL ;
struct V_14 * V_24 ;
struct V_14 * * V_227 = NULL ;
struct V_55 * V_182 ;
struct V_50 * V_51 = & V_89 -> V_91 ;
struct V_109 * V_110 ;
int V_230 ;
int V_4 , V_58 , V_231 , V_118 = 0 ;
char * V_67 ;
V_16 = F_24 ( V_89 -> V_39 , V_89 -> V_83 ) ;
if ( ! V_16 ) {
V_4 = - V_48 ;
goto V_11;
}
V_227 = malloc ( sizeof( struct V_14 * ) * V_214 . V_229 ) ;
if ( ! V_227 ) {
V_4 = - V_47 ;
goto V_11;
}
V_230 = F_177 ( V_16 , V_51 -> V_53 , V_227 ) ;
if ( V_230 == 0 ) {
F_54 ( L_159 , V_51 -> V_53 ,
V_89 -> V_39 ? : L_5 ) ;
V_4 = - V_26 ;
goto V_11;
} else if ( V_230 > V_214 . V_229 ) {
F_54 ( L_160 ,
V_89 -> V_39 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
if ( ! V_89 -> V_83 && ! V_89 -> V_39 &&
( ! V_51 -> V_87 || F_70 () ) ) {
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_27 ) ;
V_4 = - V_48 ;
goto V_11;
}
}
* V_56 = F_113 ( sizeof( * V_182 ) * V_230 ) ;
if ( ! * V_56 ) {
V_4 = - V_47 ;
goto V_11;
}
V_4 = 0 ;
for ( V_231 = 0 ; V_231 < V_230 ; V_231 ++ ) {
V_24 = V_227 [ V_231 ] ;
V_182 = ( * V_56 ) + V_4 ;
V_110 = & V_182 -> V_91 ;
if ( V_4 == V_230 ) {
F_7 ( L_161 ) ;
break;
}
V_4 ++ ;
if ( V_51 -> V_86 > V_24 -> V_95 - V_24 -> V_28 ) {
F_7 ( L_162 ,
V_51 -> V_86 , V_24 -> V_15 ) ;
V_4 = - V_26 ;
goto V_232;
}
V_110 -> V_59 = V_16 -> V_27 ( V_16 , V_24 -> V_28 ) + V_51 -> V_86 ;
if ( ! V_89 -> V_83 && ! V_89 -> V_39 &&
F_31 ( V_24 -> V_15 , V_110 -> V_59 ) ) {
V_110 -> V_14 = NULL ;
V_118 ++ ;
} else if ( V_23 ) {
V_110 -> V_14 = F_135 ( V_23 -> V_15 , V_233 ) ;
V_110 -> V_86 = V_110 -> V_59 - V_23 -> V_18 ;
} else {
V_110 -> V_14 = F_135 ( V_24 -> V_15 , V_233 ) ;
V_110 -> V_86 = V_51 -> V_86 ;
}
V_110 -> V_115 = F_135 ( V_24 -> V_15 , V_233 ) ;
V_110 -> V_87 = V_51 -> V_87 ;
if ( V_89 -> V_39 ) {
if ( V_89 -> V_83 ) {
V_182 -> V_91 . V_29 = F_135 ( V_89 -> V_39 ,
V_233 ) ;
} else {
V_67 = F_33 ( V_89 -> V_39 ) ;
V_182 -> V_91 . V_29 =
F_26 ( V_67 ? V_67 : V_89 -> V_39 ) ;
free ( V_67 ) ;
if ( ! V_182 -> V_91 . V_29 )
goto V_233;
}
}
V_182 -> V_83 = V_89 -> V_83 ;
V_182 -> V_179 = V_89 -> V_179 ;
if ( V_182 -> V_179 ) {
V_182 -> args = F_113 ( sizeof( struct V_190 ) *
V_182 -> V_179 ) ;
if ( V_182 -> args == NULL )
goto V_233;
}
for ( V_58 = 0 ; V_58 < V_182 -> V_179 ; V_58 ++ ) {
if ( V_89 -> args [ V_58 ] . V_15 )
V_182 -> args [ V_58 ] . V_15 =
F_135 ( V_89 -> args [ V_58 ] . V_15 ,
V_233 ) ;
V_182 -> args [ V_58 ] . V_191 = F_135 ( V_89 -> args [ V_58 ] . V_146 ,
V_233 ) ;
if ( V_89 -> args [ V_58 ] . type )
V_182 -> args [ V_58 ] . type =
F_135 ( V_89 -> args [ V_58 ] . type ,
V_233 ) ;
}
F_179 ( V_89 , V_182 , V_16 , V_24 ) ;
}
if ( V_4 == V_118 ) {
V_4 = - V_26 ;
goto V_232;
}
V_11:
F_48 ( V_16 ) ;
free ( V_227 ) ;
return V_4 ;
V_233:
V_4 = - V_47 ;
V_232:
F_29 ( * V_56 , V_230 ) ;
F_59 ( V_56 ) ;
goto V_11;
}
static int F_181 ( struct V_88 * V_89 ,
struct V_55 * * V_56 )
{
struct V_50 * V_51 = & V_89 -> V_91 ;
struct V_55 * V_182 ;
struct V_109 * V_110 ;
int V_58 , V_101 ;
if ( ! ( V_89 -> V_91 . V_53 && ! strncmp ( V_89 -> V_91 . V_53 , L_73 , 2 ) ) )
return - V_48 ;
if ( F_74 ( V_89 ) )
return - V_48 ;
* V_56 = F_113 ( sizeof( * V_182 ) ) ;
if ( ! * V_56 )
return - V_47 ;
V_182 = * V_56 ;
V_110 = & V_182 -> V_91 ;
V_110 -> V_59 = V_89 -> V_91 . V_165 ;
V_110 -> V_87 = V_51 -> V_87 ;
V_182 -> V_83 = V_89 -> V_83 ;
V_101 = - V_47 ;
if ( F_109 ( & V_110 -> V_14 , L_163 , V_110 -> V_59 ) < 0 )
goto V_234;
if ( ( ! V_182 -> V_83 ) &&
( F_31 ( V_182 -> V_91 . V_14 ,
V_182 -> V_91 . V_59 ) ) ) {
V_101 = - V_235 ;
goto V_234;
}
if ( F_109 ( & V_110 -> V_115 , L_164 , V_110 -> V_59 ) < 0 )
goto V_234;
if ( V_89 -> V_39 ) {
V_110 -> V_29 = F_26 ( V_89 -> V_39 ) ;
if ( ! V_110 -> V_29 )
goto V_234;
}
if ( V_182 -> V_161 ) {
V_182 -> V_161 = F_26 ( V_89 -> V_161 ) ;
if ( ! V_182 -> V_161 )
goto V_234;
}
if ( V_89 -> V_162 ) {
V_182 -> V_162 = F_26 ( V_89 -> V_162 ) ;
if ( ! V_182 -> V_162 )
goto V_234;
}
V_182 -> V_179 = V_89 -> V_179 ;
V_182 -> args = F_113 ( sizeof( struct V_190 ) * V_182 -> V_179 ) ;
if ( ! V_182 -> args )
goto V_234;
for ( V_58 = 0 ; V_58 < V_182 -> V_179 ; V_58 ++ )
F_182 ( & V_182 -> args [ V_58 ] , & V_89 -> args [ V_58 ] ) ;
return 1 ;
V_234:
F_29 ( * V_56 , 1 ) ;
* V_56 = NULL ;
return V_101 ;
}
static void * F_183 ( void * V_236 , T_1 V_237 , void * V_238 , T_1 V_239 )
{
void * V_4 ;
V_4 = malloc ( V_237 + V_239 ) ;
if ( V_4 ) {
memcpy ( V_4 , V_236 , V_237 ) ;
memcpy ( V_4 + V_237 , V_238 , V_239 ) ;
}
return V_4 ;
}
static int
F_184 ( struct V_55 * * V_56 , int * V_57 ,
struct V_55 * * V_240 , int V_241 )
{
struct V_55 * V_242 ;
int V_4 = 0 ;
if ( * V_57 == 0 ) {
* V_56 = * V_240 ;
* V_57 = V_241 ;
* V_240 = NULL ;
return 0 ;
}
if ( * V_57 + V_241 > V_214 . V_229 )
V_4 = - V_6 ;
else {
V_242 = F_183 ( * V_56 , ( * V_57 ) * sizeof( * * V_56 ) ,
* V_240 , V_241 * sizeof( * * V_240 ) ) ;
if ( ! V_242 )
V_4 = - V_47 ;
else {
free ( * V_56 ) ;
* V_56 = V_242 ;
* V_57 += V_241 ;
}
}
if ( V_4 < 0 )
F_29 ( * V_240 , V_241 ) ;
F_59 ( V_240 ) ;
return V_4 ;
}
static int F_185 ( struct V_88 * V_89 ,
struct V_55 * * V_56 ,
const char * V_39 )
{
struct V_225 * V_215 ;
struct V_243 * V_244 ;
struct V_55 * V_245 = NULL ;
int V_57 = 0 ;
int V_4 = 0 ;
V_215 = F_173 ( V_39 ) ;
if ( ! V_215 )
return 0 ;
F_186 (entry, cache) {
if ( ! V_244 -> V_89 . V_162 || ! V_244 -> V_89 . V_161 )
continue;
if ( ( ! V_89 -> V_161 || F_164 ( V_244 -> V_89 . V_161 , V_89 -> V_161 ) ) &&
F_164 ( V_244 -> V_89 . V_162 , V_89 -> V_162 ) ) {
V_4 = F_187 ( V_244 , & V_245 ) ;
if ( V_4 > 0 )
V_4 = F_184 ( V_56 , & V_57 ,
& V_245 , V_4 ) ;
if ( V_4 < 0 )
break;
}
}
F_176 ( V_215 ) ;
if ( V_4 < 0 ) {
F_29 ( * V_56 , V_57 ) ;
F_59 ( V_56 ) ;
} else {
V_4 = V_57 ;
if ( V_57 > 0 && V_39 && V_39 [ 0 ] == '/' )
V_89 -> V_83 = true ;
}
return V_4 ;
}
static int F_188 ( struct V_88 * V_89 ,
struct V_55 * * V_56 )
{
struct V_55 * V_245 = NULL ;
struct V_209 * V_246 ;
struct V_141 * V_247 ;
char * V_116 ;
int V_57 = 0 ;
int V_4 ;
V_246 = F_189 ( true ) ;
if ( ! V_246 ) {
V_4 = - V_105 ;
F_4 ( L_165 , V_4 ) ;
return V_4 ;
}
V_4 = 0 ;
F_92 (nd, bidlist) {
V_116 = F_108 ( V_247 -> V_148 ) ;
V_4 = F_185 ( V_89 , & V_245 , V_116 ) ;
if ( V_4 > 0 )
V_4 = F_184 ( V_56 , & V_57 ,
& V_245 , V_4 ) ;
free ( V_116 ) ;
if ( V_4 < 0 )
break;
}
F_94 ( V_246 ) ;
if ( V_4 < 0 ) {
F_29 ( * V_56 , V_57 ) ;
F_59 ( V_56 ) ;
} else
V_4 = V_57 ;
return V_4 ;
}
static int F_190 ( struct V_88 * V_89 ,
struct V_55 * * V_56 )
{
struct V_225 * V_215 ;
struct V_243 * V_244 ;
struct V_55 * V_182 ;
struct V_141 * V_142 ;
int V_4 , V_58 ;
if ( V_89 -> V_159 ) {
if ( ! V_89 -> V_39 )
return F_188 ( V_89 , V_56 ) ;
else
return F_185 ( V_89 , V_56 , V_89 -> V_39 ) ;
}
V_215 = F_173 ( V_89 -> V_39 ) ;
if ( ! V_215 )
return 0 ;
V_244 = F_191 ( V_215 , V_89 ) ;
if ( ! V_244 ) {
V_4 = V_89 -> V_159 ? - V_26 : 0 ;
goto V_11;
}
V_4 = F_192 ( V_244 -> V_248 ) ;
if ( V_4 > V_214 . V_229 ) {
F_4 ( L_166 ,
V_89 -> V_39 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
* V_56 = F_113 ( V_4 * sizeof( * V_182 ) ) ;
if ( ! * V_56 ) {
V_4 = - V_47 ;
goto V_11;
}
V_58 = 0 ;
F_92 (node, entry->tevlist) {
V_182 = & ( * V_56 ) [ V_58 ++ ] ;
V_4 = F_118 ( V_142 -> V_148 , V_182 ) ;
if ( V_4 < 0 )
goto V_11;
V_182 -> V_83 = V_89 -> V_83 ;
}
V_4 = V_58 ;
V_11:
F_176 ( V_215 ) ;
return V_4 ;
}
static int F_193 ( struct V_88 * V_89 ,
struct V_55 * * V_56 )
{
int V_4 ;
if ( ! V_89 -> V_161 && ! V_89 -> V_159 ) {
if ( ! V_89 -> V_83 ) {
V_89 -> V_161 = F_26 ( V_49 ) ;
V_4 = V_89 -> V_161 ? 0 : - V_47 ;
} else
V_4 = F_25 ( V_89 -> V_39 , & V_89 -> V_161 ) ;
if ( V_4 != 0 ) {
F_7 ( L_167 ) ;
return V_4 ;
}
}
V_4 = F_181 ( V_89 , V_56 ) ;
if ( V_4 > 0 )
return V_4 ;
V_4 = F_190 ( V_89 , V_56 ) ;
if ( V_4 > 0 || V_89 -> V_159 )
return V_4 == 0 ? - V_26 : V_4 ;
V_4 = F_73 ( V_89 , V_56 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_180 ( V_89 , V_56 ) ;
}
int F_194 ( struct V_88 * V_149 , int V_150 )
{
int V_58 , V_4 ;
for ( V_58 = 0 ; V_58 < V_150 ; V_58 ++ ) {
if ( ! V_149 [ V_58 ] . V_83 )
F_149 () ;
V_4 = F_193 ( & V_149 [ V_58 ] , & V_149 [ V_58 ] . V_56 ) ;
if ( V_4 < 0 )
return V_4 ;
V_149 [ V_58 ] . V_57 = V_4 ;
}
F_150 () ;
return 0 ;
}
static int F_195 ( struct V_55 * V_182 )
{
char * V_46 = F_129 ( V_182 ) ;
if ( ! V_46 ) {
F_4 ( L_168 ) ;
return - V_48 ;
}
printf ( L_97 , V_46 ) ;
free ( V_46 ) ;
return 0 ;
}
int F_196 ( struct V_88 * V_149 , int V_150 )
{
struct V_209 * V_217 = F_197 ( NULL , NULL ) ;
struct V_55 * V_182 ;
struct V_88 * V_89 ;
int V_58 , V_231 , V_4 = 0 ;
if ( ! V_217 )
return - V_47 ;
for ( V_231 = 0 ; V_231 < V_150 && ! V_4 ; V_231 ++ ) {
V_89 = & V_149 [ V_231 ] ;
for ( V_58 = 0 ; V_58 < V_89 -> V_57 && ! V_4 ; V_58 ++ ) {
V_182 = & V_89 -> V_56 [ V_58 ] ;
if ( ! V_182 -> V_91 . V_14 && ! V_89 -> V_83 )
continue;
V_4 = F_165 ( V_182 , V_89 ,
V_217 , true ) ;
if ( ! V_4 )
V_4 = F_195 ( V_182 ) ;
}
}
F_94 ( V_217 ) ;
return V_4 ;
}
int F_198 ( struct V_88 * V_149 , int V_150 )
{
int V_58 , V_4 = 0 ;
for ( V_58 = 0 ; V_58 < V_150 ; V_58 ++ ) {
V_4 = F_171 ( & V_149 [ V_58 ] , V_149 [ V_58 ] . V_56 ,
V_149 [ V_58 ] . V_57 ,
V_214 . V_249 ) ;
if ( V_4 < 0 )
break;
}
return V_4 ;
}
void F_199 ( struct V_88 * V_149 , int V_150 )
{
int V_58 , V_231 ;
for ( V_58 = 0 ; V_58 < V_150 ; V_58 ++ ) {
for ( V_231 = 0 ; V_231 < V_149 [ V_58 ] . V_57 ; V_231 ++ )
F_30 ( & V_149 [ V_58 ] . V_56 [ V_231 ] ) ;
F_59 ( & V_149 [ V_58 ] . V_56 ) ;
V_149 [ V_58 ] . V_57 = 0 ;
F_133 ( & V_149 [ V_58 ] ) ;
}
}
int F_200 ( struct V_88 * V_149 , int V_150 )
{
int V_4 ;
V_4 = F_2 ( V_149 -> V_83 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_194 ( V_149 , V_150 ) ;
if ( V_4 == 0 )
V_4 = F_198 ( V_149 , V_150 ) ;
F_199 ( V_149 , V_150 ) ;
F_8 () ;
return V_4 ;
}
int F_201 ( struct V_138 * T_11 )
{
int V_4 , V_250 , V_251 = - 1 , V_252 = - 1 ;
char * V_1 = F_202 ( T_11 ) ;
if ( ! V_1 )
return - V_48 ;
V_4 = F_160 ( & V_252 , & V_251 , V_222 ) ;
if ( V_4 < 0 )
goto V_11;
V_4 = F_203 ( V_252 , T_11 ) ;
if ( V_4 < 0 && V_4 != - V_26 )
goto error;
V_250 = F_203 ( V_251 , T_11 ) ;
if ( V_250 < 0 && V_250 != - V_26 ) {
V_4 = V_250 ;
goto error;
}
V_4 = 0 ;
error:
if ( V_252 >= 0 )
F_40 ( V_252 ) ;
if ( V_251 >= 0 )
F_40 ( V_251 ) ;
V_11:
free ( V_1 ) ;
return V_4 ;
}
int F_204 ( const char * V_39 , struct V_138 * V_139 ,
bool V_40 )
{
struct V_228 * V_247 ;
struct V_16 * V_16 ;
int V_4 ;
V_4 = F_2 ( V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
V_16 = F_24 ( V_39 , V_40 ) ;
if ( ! V_16 ) {
F_54 ( L_169 , ( V_39 ) ? : L_5 ) ;
return - V_48 ;
}
V_4 = F_16 ( V_16 ) ;
if ( V_4 ) {
if ( V_4 == - 2 ) {
char * V_1 = F_202 ( V_139 ) ;
F_54 ( L_170 ,
V_1 ) ;
free ( V_1 ) ;
} else
F_54 ( L_171 ,
( V_39 ) ? : L_5 ) ;
goto V_95;
}
if ( ! F_205 ( V_16 -> V_36 , V_16 -> type ) )
F_206 ( V_16 -> V_36 , V_16 -> type ) ;
F_83 () ;
for ( V_247 = F_207 ( & V_16 -> V_36 -> V_253 [ V_16 -> type ] ) ; V_247 ; V_247 = F_208 ( V_247 ) ) {
struct V_254 * V_35 = F_209 ( V_247 , struct V_254 , V_228 ) ;
if ( F_93 ( V_139 , V_35 -> V_24 . V_15 ) )
printf ( L_97 , V_35 -> V_24 . V_15 ) ;
}
V_95:
F_48 ( V_16 ) ;
F_8 () ;
return V_4 ;
}
int F_182 ( struct V_190 * V_255 ,
struct V_166 * V_256 )
{
V_255 -> V_191 = F_26 ( V_256 -> V_146 ) ;
if ( V_255 -> V_191 == NULL )
return - V_47 ;
if ( V_256 -> type ) {
V_255 -> type = F_26 ( V_256 -> type ) ;
if ( V_255 -> type == NULL )
return - V_47 ;
}
if ( V_256 -> V_15 ) {
V_255 -> V_15 = F_26 ( V_256 -> V_15 ) ;
if ( V_255 -> V_15 == NULL )
return - V_47 ;
} else
V_255 -> V_15 = NULL ;
return 0 ;
}
