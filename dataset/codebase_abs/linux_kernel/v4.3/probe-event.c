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
static int F_2 ( bool V_7 )
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
static void F_8 ( void )
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
if ( F_15 ( V_12 -> V_21 [ V_22 ] , NULL ) < 0 )
return NULL ;
V_20 = F_16 ( V_12 -> V_21 [ V_22 ] ) ;
if ( ! V_20 )
return NULL ;
return V_20 -> V_19 ;
}
static T_3 F_17 ( const char * V_15 , bool V_23 )
{
struct V_19 * V_24 ;
struct V_14 * V_25 ;
struct V_16 * V_16 ;
V_24 = F_14 () ;
if ( V_24 && strcmp ( V_15 , V_24 -> V_15 ) == 0 )
return ( V_23 ) ? V_24 -> V_18 : V_24 -> V_26 ;
else {
V_25 = F_10 ( V_15 , & V_16 ) ;
if ( V_25 )
return V_16 -> V_27 ( V_16 , V_25 -> V_28 ) -
( ( V_23 ) ? 0 : V_16 -> V_23 ) ;
}
return 0 ;
}
static struct V_16 * F_18 ( const char * V_29 )
{
struct V_30 * V_31 = & V_12 -> V_32 ;
struct V_33 * V_33 = & V_31 -> V_33 [ V_22 ] ;
struct V_16 * V_34 ;
if ( V_29 && strchr ( V_29 , '/' ) )
return F_19 ( V_12 , 0 , V_29 ) ;
if ( ! V_29 )
V_29 = L_5 ;
for ( V_34 = F_20 ( V_33 ) ; V_34 ; V_34 = F_21 ( V_34 ) ) {
if ( strncmp ( V_34 -> V_35 -> V_36 + 1 , V_29 ,
V_34 -> V_35 -> V_37 - 2 ) == 0 ) {
return V_34 ;
}
}
return NULL ;
}
static struct V_16 * F_22 ( const char * V_38 , bool V_39 )
{
if ( V_39 )
return F_23 ( V_38 ) ;
else
return F_18 ( V_38 ) ;
}
static void F_24 ( struct V_16 * V_16 , bool V_39 )
{
if ( V_16 && V_39 ) {
F_25 ( V_16 ) ;
}
}
static int F_26 ( const char * V_40 , char * * V_41 )
{
char * V_42 , * V_43 , * V_44 ;
char V_45 [ 64 ] ;
int V_4 ;
V_44 = F_27 ( V_40 ) ;
if ( ! V_44 )
return - V_46 ;
V_42 = F_28 ( V_44 ) ;
if ( ! V_42 ) {
V_4 = - V_47 ;
goto V_11;
}
V_43 = strpbrk ( V_42 , L_6 ) ;
if ( V_43 )
* V_43 = '\0' ;
V_4 = F_1 ( V_45 , 64 , L_7 , V_48 , V_42 ) ;
if ( V_4 < 0 )
goto V_11;
* V_41 = F_27 ( V_45 ) ;
V_4 = * V_41 ? 0 : - V_46 ;
V_11:
free ( V_44 ) ;
return V_4 ;
}
static void F_29 ( struct V_49 * V_50 )
{
free ( V_50 -> V_51 ) ;
free ( V_50 -> V_52 ) ;
free ( V_50 -> V_53 ) ;
}
static void F_30 ( struct V_54 * V_55 , int V_56 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ )
F_31 ( V_55 + V_57 ) ;
}
static bool F_32 ( const char * V_14 , unsigned long V_58 )
{
T_3 V_59 ;
V_59 = F_17 ( L_8 , false ) ;
if ( V_59 != 0 && V_59 < V_58 )
F_7 ( L_9 , V_14 ) ;
else if ( F_33 ( V_58 ) )
F_7 ( L_10 , V_14 ) ;
else
return false ;
return true ;
}
static int F_34 ( const char * V_29 , struct V_35 * * V_60 )
{
struct V_35 * V_35 ;
struct V_16 * V_16 ;
const char * V_13 ;
int V_4 = 0 ;
if ( V_29 ) {
char V_61 [ 128 ] ;
snprintf ( V_61 , sizeof( V_61 ) , L_11 , V_29 ) ;
V_16 = F_35 ( & V_12 -> V_32 , V_22 , V_61 ) ;
if ( V_16 ) {
V_35 = V_16 -> V_35 ;
goto V_62;
}
F_4 ( L_12 , V_29 ) ;
return - V_63 ;
}
V_16 = V_12 -> V_21 [ V_22 ] ;
V_35 = V_16 -> V_35 ;
V_13 = V_8 . V_13 ;
V_35 -> V_64 = 0 ;
if ( V_13 )
V_4 = F_36 ( V_35 , V_16 , V_13 , false , NULL ) ;
else
V_4 = F_37 ( V_35 , V_16 , NULL ) ;
V_62:
* V_60 = V_35 ;
return V_4 ;
}
static int F_38 ( struct V_65 * V_66 ,
struct V_49 * V_50 ,
struct V_49 * V_41 ,
const char * V_38 , bool V_67 )
{
struct V_16 * V_16 = NULL ;
struct V_14 * V_25 ;
T_3 V_58 = 0 ;
int V_4 = - V_63 ;
if ( ! V_50 -> V_52 || V_50 -> V_51 )
return - V_68 ;
V_16 = F_22 ( V_38 , V_67 ) ;
if ( ! V_16 )
return - V_47 ;
F_39 (map, pp->function, sym) {
if ( V_67 )
V_58 = V_25 -> V_28 ;
else
V_58 = V_16 -> V_27 ( V_16 , V_25 -> V_28 ) ;
break;
}
if ( ! V_58 ) {
V_4 = - V_63 ;
goto V_11;
}
F_4 ( L_13 V_69 L_14 ,
V_50 -> V_52 , V_58 ) ;
V_4 = F_40 ( V_66 , ( unsigned long ) V_58 ,
V_41 ) ;
if ( V_4 <= 0 )
V_4 = ( ! V_4 ) ? - V_63 : V_4 ;
else {
V_41 -> V_70 += V_50 -> V_70 ;
V_41 -> line += V_50 -> line ;
V_41 -> V_71 = V_50 -> V_71 ;
V_4 = 0 ;
}
V_11:
F_24 ( V_16 , V_67 ) ;
return V_4 ;
}
static int F_41 ( struct V_65 * V_66 ,
struct V_72 * V_73 ,
struct V_49 * V_74 )
{
int V_4 ;
memcpy ( V_74 , & V_73 -> V_75 , sizeof( * V_74 ) ) ;
memset ( & V_73 -> V_75 , 0 , sizeof( V_73 -> V_75 ) ) ;
V_4 = F_38 ( V_66 , V_74 , & V_73 -> V_75 ,
V_73 -> V_38 , V_73 -> V_67 ) ;
if ( V_4 < 0 )
memcpy ( & V_73 -> V_75 , V_74 , sizeof( * V_74 ) ) ;
return V_4 ;
}
static int F_42 ( struct V_65 * V_66 ,
struct V_76 * V_77 ,
const char * V_38 , bool V_39 )
{
struct V_49 V_50 = { . V_52 = V_77 -> V_52 ,
. V_51 = V_77 -> V_51 ,
. line = V_77 -> V_28 } ;
struct V_49 V_41 ;
int V_4 , V_78 = 0 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
if ( V_77 -> V_79 != V_80 )
V_78 = V_77 -> V_79 - V_77 -> V_28 ;
V_4 = F_38 ( V_66 , & V_50 , & V_41 ,
V_38 , V_39 ) ;
if ( ! V_4 ) {
V_77 -> V_52 = V_41 . V_52 ;
V_77 -> V_51 = V_41 . V_51 ;
V_77 -> V_28 = V_41 . line ;
if ( V_77 -> V_79 != V_80 )
V_77 -> V_79 = V_77 -> V_28 + V_78 ;
F_29 ( & V_50 ) ;
}
return V_4 ;
}
static struct V_65 * F_43 ( const char * V_29 , bool V_81 )
{
const char * V_82 = V_29 ;
char V_83 [ V_84 ] ;
struct V_65 * V_4 = NULL ;
struct V_35 * V_35 = NULL ;
int V_85 ;
if ( ! V_29 || ! strchr ( V_29 , '/' ) ) {
V_85 = F_34 ( V_29 , & V_35 ) ;
if ( V_85 < 0 ) {
if ( ! V_35 || V_35 -> V_64 == 0 ) {
if ( ! F_44 ( - V_85 , V_83 , V_84 ) )
strcpy ( V_83 , L_15 ) ;
} else
F_45 ( V_35 , V_83 , V_84 ) ;
if ( ! V_81 )
F_46 ( L_16 ,
V_29 ? : L_5 , V_83 ) ;
return NULL ;
}
V_82 = V_35 -> V_86 ;
}
V_4 = F_47 ( V_82 ) ;
if ( ! V_4 && ! V_81 ) {
F_7 ( L_17 , V_82 ) ;
if ( ! V_29 || ! F_48 ( V_82 , L_18 ) )
F_7 ( L_19 ) ;
else
F_7 ( L_20 ) ;
F_7 ( L_21 ) ;
}
return V_4 ;
}
static struct V_65 * F_49 ( const char * V_29 , bool V_81 )
{
if ( ( V_87 && ! strcmp ( V_87 , V_29 ) ) ||
( ! V_87 && ! V_29 && V_88 ) )
goto V_11;
free ( V_87 ) ;
if ( V_29 ) {
V_87 = F_27 ( V_29 ) ;
if ( ! V_87 ) {
F_50 ( V_88 ) ;
V_88 = NULL ;
goto V_11;
}
}
V_88 = F_43 ( V_29 , V_81 ) ;
if ( ! V_88 )
F_51 ( & V_87 ) ;
V_11:
return V_88 ;
}
static void F_52 ( void )
{
F_50 ( V_88 ) ;
V_88 = NULL ;
F_51 ( & V_87 ) ;
}
static int F_53 ( const char * V_40 , unsigned long * V_58 )
{
T_4 * V_89 ;
T_5 V_90 ;
T_6 V_91 ;
int V_92 , V_4 = - V_63 ;
V_92 = F_54 ( V_40 , V_93 ) ;
if ( V_92 < 0 )
return - V_94 ;
V_89 = F_55 ( V_92 , V_95 , NULL ) ;
if ( V_89 == NULL )
return - V_47 ;
if ( F_56 ( V_89 , & V_90 ) == NULL )
goto V_11;
if ( ! F_57 ( V_89 , & V_90 , & V_91 , L_22 , NULL ) )
goto V_11;
* V_58 = V_91 . V_96 - V_91 . V_97 ;
V_4 = 0 ;
V_11:
F_58 ( V_89 ) ;
return V_4 ;
}
static int F_59 ( struct V_98 * V_99 ,
struct V_49 * V_50 ,
bool V_100 )
{
struct V_65 * V_66 = NULL ;
unsigned long V_101 = 0 ;
T_3 V_18 = V_99 -> V_58 ;
int V_4 = - V_63 ;
if ( ! V_100 ) {
if ( ! V_18 ) {
V_4 = - V_47 ;
goto error;
}
V_4 = F_53 ( V_99 -> V_29 , & V_101 ) ;
if ( V_4 < 0 )
goto error;
V_18 += V_101 ;
} else if ( V_99 -> V_14 ) {
V_18 = F_17 ( V_99 -> V_14 , false ) ;
if ( V_18 == 0 )
goto error;
V_18 += V_99 -> V_70 ;
}
F_4 ( L_23 V_69 L_24 , V_18 ,
V_99 -> V_29 ? : L_5 ) ;
V_66 = F_49 ( V_99 -> V_29 , V_102 == 0 ) ;
if ( V_66 )
V_4 = F_40 ( V_66 ,
( unsigned long ) V_18 , V_50 ) ;
else
V_4 = - V_63 ;
if ( V_4 > 0 ) {
V_50 -> V_71 = V_99 -> V_71 ;
return 0 ;
}
error:
F_4 ( L_25 ) ;
return V_4 ? : - V_63 ;
}
static int F_60 ( struct V_54 * V_55 ,
int V_56 , const char * V_40 )
{
int V_57 , V_4 = 0 ;
unsigned long V_101 = 0 ;
if ( ! V_40 )
return 0 ;
V_4 = F_53 ( V_40 , & V_101 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_57 = 0 ; V_57 < V_56 && V_4 >= 0 ; V_57 ++ ) {
V_55 [ V_57 ] . V_75 . V_58 -= V_101 ;
V_55 [ V_57 ] . V_75 . V_29 = F_27 ( V_40 ) ;
if ( ! V_55 [ V_57 ] . V_75 . V_29 ) {
V_4 = - V_46 ;
break;
}
V_55 [ V_57 ] . V_67 = true ;
}
return V_4 ;
}
static int F_61 ( struct V_54 * V_55 ,
int V_56 , const char * V_29 )
{
int V_57 , V_4 = 0 ;
char * V_74 ;
if ( ! V_29 )
return 0 ;
V_74 = strrchr ( V_29 , '/' ) ;
if ( V_74 ) {
V_29 = F_27 ( V_74 + 1 ) ;
if ( ! V_29 )
return - V_46 ;
V_74 = strchr ( V_29 , '.' ) ;
if ( V_74 )
* V_74 = '\0' ;
V_74 = ( char * ) V_29 ;
}
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
V_55 [ V_57 ] . V_75 . V_29 = F_27 ( V_29 ) ;
if ( ! V_55 [ V_57 ] . V_75 . V_29 ) {
V_4 = - V_46 ;
break;
}
}
free ( V_74 ) ;
return V_4 ;
}
static int F_62 ( struct V_54 * V_55 ,
int V_56 , const char * V_29 ,
bool V_103 )
{
struct V_19 * V_24 ;
char * V_74 ;
int V_57 , V_104 = 0 ;
if ( V_103 )
return F_60 ( V_55 , V_56 , V_29 ) ;
if ( V_29 )
return F_61 ( V_55 , V_56 , V_29 ) ;
V_24 = F_14 () ;
if ( ! V_24 ) {
F_7 ( L_26 ) ;
return - V_47 ;
}
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
if ( ! V_55 [ V_57 ] . V_75 . V_58 || V_55 [ V_57 ] . V_75 . V_71 )
continue;
if ( F_32 ( V_55 [ V_57 ] . V_75 . V_14 ,
V_55 [ V_57 ] . V_75 . V_58 ) ) {
V_74 = NULL ;
V_104 ++ ;
} else {
V_74 = F_27 ( V_24 -> V_15 ) ;
if ( ! V_74 )
return - V_46 ;
}
if ( ! V_55 [ V_57 ] . V_75 . V_105 )
V_55 [ V_57 ] . V_75 . V_105 = V_55 [ V_57 ] . V_75 . V_14 ;
else
free ( V_55 [ V_57 ] . V_75 . V_14 ) ;
V_55 [ V_57 ] . V_75 . V_14 = V_74 ;
V_55 [ V_57 ] . V_75 . V_70 = V_55 [ V_57 ] . V_75 . V_58 -
V_24 -> V_26 ;
}
return V_104 ;
}
static int F_63 ( struct V_72 * V_73 ,
struct V_54 * * V_55 )
{
bool V_106 = F_64 ( V_73 ) ;
struct V_49 V_74 ;
struct V_65 * V_66 ;
int V_56 , V_4 = 0 ;
V_66 = F_43 ( V_73 -> V_38 , ! V_106 ) ;
if ( ! V_66 ) {
if ( V_106 )
return - V_63 ;
F_4 ( L_27 ) ;
return 0 ;
}
F_4 ( L_28 ) ;
V_56 = F_65 ( V_66 , V_73 , V_55 ) ;
if ( V_56 == 0 ) {
V_4 = F_41 ( V_66 , V_73 , & V_74 ) ;
if ( ! V_4 ) {
V_56 = F_65 ( V_66 , V_73 , V_55 ) ;
F_29 ( & V_73 -> V_75 ) ;
memcpy ( & V_73 -> V_75 , & V_74 , sizeof( V_74 ) ) ;
}
}
F_50 ( V_66 ) ;
if ( V_56 > 0 ) {
F_4 ( L_29 , V_56 ) ;
V_4 = F_62 ( * V_55 , V_56 ,
V_73 -> V_38 , V_73 -> V_67 ) ;
if ( V_4 < 0 || V_4 == V_56 ) {
F_30 ( * V_55 , V_56 ) ;
F_51 ( V_55 ) ;
}
if ( V_4 != V_56 )
return V_4 < 0 ? V_4 : V_56 ;
V_56 = 0 ;
}
if ( V_56 == 0 ) {
F_7 ( L_30 ,
F_66 ( & V_73 -> V_75 ) ) ;
return - V_63 ;
}
F_4 ( L_31 , V_56 ) ;
if ( V_56 < 0 ) {
if ( V_56 == - V_107 )
F_7 ( L_32
L_33 ) ;
if ( ! V_106 ) {
F_4 ( L_34 ) ;
return 0 ;
}
}
return V_56 ;
}
static int F_67 ( T_7 * V_108 , int V_109 , bool V_110 , bool V_111 )
{
char V_45 [ V_112 ] , V_113 [ V_84 ] ;
const char * V_114 = V_111 ? L_35 : V_115 ;
const char * V_116 = NULL ;
do {
if ( fgets ( V_45 , V_112 , V_108 ) == NULL )
goto error;
if ( V_110 )
continue;
if ( ! V_116 ) {
V_116 = V_111 ? L_36 : L_37 ;
F_68 ( stdout , V_114 , V_116 , V_109 ) ;
}
F_68 ( stdout , V_114 , L_38 , V_45 ) ;
} while ( strchr ( V_45 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_108 ) ) {
F_7 ( L_39 ,
F_44 ( V_94 , V_113 , sizeof( V_113 ) ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_69 ( T_7 * V_108 , int V_109 , bool V_110 , bool V_111 )
{
int V_117 = F_67 ( V_108 , V_109 , V_110 , V_111 ) ;
if ( V_117 == 0 ) {
F_7 ( L_40 ) ;
V_117 = - 1 ;
}
return V_117 ;
}
static int F_70 ( struct V_76 * V_77 , const char * V_29 ,
bool V_39 )
{
int V_109 = 1 ;
struct V_118 * V_119 ;
struct V_65 * V_66 ;
T_7 * V_108 ;
int V_4 ;
char * V_74 ;
char V_113 [ V_84 ] ;
V_66 = F_43 ( V_29 , false ) ;
if ( ! V_66 )
return - V_63 ;
V_4 = F_71 ( V_66 , V_77 ) ;
if ( ! V_4 ) {
V_4 = F_42 ( V_66 , V_77 , V_29 , V_39 ) ;
if ( ! V_4 )
V_4 = F_71 ( V_66 , V_77 ) ;
}
F_50 ( V_66 ) ;
if ( V_4 == 0 || V_4 == - V_63 ) {
F_7 ( L_41 ) ;
return - V_63 ;
} else if ( V_4 < 0 ) {
F_7 ( L_42 ) ;
return V_4 ;
}
V_74 = V_77 -> V_82 ;
V_4 = F_72 ( V_74 , V_77 -> V_120 , & V_77 -> V_82 ) ;
if ( V_74 != V_77 -> V_82 )
free ( V_74 ) ;
if ( V_4 < 0 ) {
F_7 ( L_43 ) ;
return V_4 ;
}
F_73 () ;
if ( V_77 -> V_52 )
fprintf ( stdout , L_44 , V_77 -> V_52 , V_77 -> V_82 ,
V_77 -> V_28 - V_77 -> V_70 ) ;
else
fprintf ( stdout , L_45 , V_77 -> V_82 , V_77 -> V_28 ) ;
V_108 = fopen ( V_77 -> V_82 , L_46 ) ;
if ( V_108 == NULL ) {
F_7 ( L_47 , V_77 -> V_82 ,
F_44 ( V_94 , V_113 , sizeof( V_113 ) ) ) ;
return - V_94 ;
}
while ( V_109 < V_77 -> V_28 ) {
V_4 = F_74 ( V_108 , V_109 ++ ) ;
if ( V_4 < 0 )
goto V_79;
}
F_75 (ln, lr->line_list) {
for (; V_119 -> V_57 > V_109 ; V_109 ++ ) {
V_4 = F_76 ( V_108 , V_109 - V_77 -> V_70 ) ;
if ( V_4 < 0 )
goto V_79;
}
V_4 = F_77 ( V_108 , V_109 ++ - V_77 -> V_70 ) ;
if ( V_4 < 0 )
goto V_79;
}
if ( V_77 -> V_79 == V_80 )
V_77 -> V_79 = V_109 + V_121 ;
while ( V_109 <= V_77 -> V_79 ) {
V_4 = F_78 ( V_108 , V_109 ++ - V_77 -> V_70 ) ;
if ( V_4 <= 0 )
break;
}
V_79:
fclose ( V_108 ) ;
return V_4 ;
}
int F_79 ( struct V_76 * V_77 , const char * V_29 , bool V_39 )
{
int V_4 ;
V_4 = F_2 ( V_39 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_70 ( V_77 , V_29 , V_39 ) ;
F_8 () ;
return V_4 ;
}
static int F_80 ( struct V_65 * V_66 ,
struct V_72 * V_73 ,
struct V_122 * V_123 )
{
char * V_45 ;
int V_4 , V_57 , V_124 ;
struct V_125 * V_126 ;
struct V_127 * V_128 = NULL , * V_129 ;
struct V_49 V_74 ;
const char * V_130 ;
V_45 = F_66 ( & V_73 -> V_75 ) ;
if ( ! V_45 )
return - V_47 ;
F_4 ( L_48 , V_45 ) ;
V_4 = F_81 ( V_66 , V_73 , & V_128 ) ;
if ( ! V_4 ) {
V_4 = F_41 ( V_66 , V_73 , & V_74 ) ;
if ( ! V_4 ) {
V_4 = F_81 ( V_66 , V_73 ,
& V_128 ) ;
F_29 ( & V_74 ) ;
}
}
if ( V_4 <= 0 ) {
if ( V_4 == 0 || V_4 == - V_63 ) {
F_46 ( L_49 , V_45 ) ;
V_4 = - V_63 ;
} else
F_7 ( L_42 ) ;
goto V_79;
}
fprintf ( stdout , L_50 , V_45 ) ;
for ( V_57 = 0 ; V_57 < V_4 ; V_57 ++ ) {
V_129 = & V_128 [ V_57 ] ;
fprintf ( stdout , L_51 , V_129 -> V_75 . V_14 ,
V_129 -> V_75 . V_70 ) ;
F_51 ( & V_129 -> V_75 . V_14 ) ;
V_124 = 0 ;
if ( V_129 -> V_131 ) {
F_82 (node, vl->vars) {
V_130 = strchr ( V_126 -> V_132 , '\t' ) + 1 ;
if ( F_83 ( V_123 , V_130 ) ) {
fprintf ( stdout , L_52 , V_126 -> V_132 ) ;
V_124 ++ ;
}
}
F_84 ( V_129 -> V_131 ) ;
}
if ( V_124 == 0 )
fprintf ( stdout , L_53 ) ;
}
free ( V_128 ) ;
V_79:
free ( V_45 ) ;
return V_4 ;
}
int F_85 ( struct V_72 * V_133 , int V_134 ,
struct V_122 * V_123 )
{
int V_57 , V_4 = 0 ;
struct V_65 * V_66 ;
V_4 = F_2 ( V_133 -> V_67 ) ;
if ( V_4 < 0 )
return V_4 ;
V_66 = F_43 ( V_133 -> V_38 , false ) ;
if ( ! V_66 ) {
V_4 = - V_63 ;
goto V_11;
}
F_73 () ;
for ( V_57 = 0 ; V_57 < V_134 && V_4 >= 0 ; V_57 ++ )
V_4 = F_80 ( V_66 , & V_133 [ V_57 ] , V_123 ) ;
F_50 ( V_66 ) ;
V_11:
F_8 () ;
return V_4 ;
}
static void F_52 ( void )
{
}
static int
F_59 ( struct V_98 * V_99 V_135 ,
struct V_49 * V_50 V_135 ,
bool V_100 V_135 )
{
return - V_136 ;
}
static int F_63 ( struct V_72 * V_73 ,
struct V_54 * * V_55 V_135 )
{
if ( F_64 ( V_73 ) ) {
F_7 ( L_54 ) ;
return - V_136 ;
}
return 0 ;
}
int F_79 ( struct V_76 * V_77 V_135 ,
const char * V_29 V_135 ,
bool V_39 V_135 )
{
F_7 ( L_54 ) ;
return - V_136 ;
}
int F_85 ( struct V_72 * V_133 V_135 ,
int V_134 V_135 ,
struct V_122 * T_8 V_135 )
{
F_7 ( L_54 ) ;
return - V_136 ;
}
void F_86 ( struct V_76 * V_77 )
{
free ( V_77 -> V_52 ) ;
free ( V_77 -> V_51 ) ;
free ( V_77 -> V_82 ) ;
free ( V_77 -> V_120 ) ;
F_87 ( V_77 -> V_137 ) ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
}
int F_88 ( struct V_76 * V_77 )
{
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
V_77 -> V_137 = F_89 ( NULL ) ;
if ( ! V_77 -> V_137 )
return - V_46 ;
else
return 0 ;
}
static int F_90 ( char * * V_138 , int * V_139 , const char * V_140 )
{
const char * V_28 = * V_138 ;
V_94 = 0 ;
* V_139 = strtol ( * V_138 , V_138 , 0 ) ;
if ( V_94 || * V_138 == V_28 ) {
F_91 ( L_55 , V_140 ) ;
return - V_47 ;
}
return 0 ;
}
static bool F_92 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
int F_93 ( const char * V_141 , struct V_76 * V_77 )
{
char * V_142 , * V_51 , * V_15 = F_27 ( V_141 ) ;
int V_85 ;
if ( ! V_15 )
return - V_46 ;
V_77 -> V_28 = 0 ;
V_77 -> V_79 = V_80 ;
V_142 = strchr ( V_15 , ':' ) ;
if ( V_142 ) {
* V_142 ++ = '\0' ;
V_85 = F_90 ( & V_142 , & V_77 -> V_28 , L_56 ) ;
if ( V_85 )
goto V_85;
if ( * V_142 == '+' || * V_142 == '-' ) {
const char V_143 = * V_142 ++ ;
V_85 = F_90 ( & V_142 , & V_77 -> V_79 , L_57 ) ;
if ( V_85 )
goto V_85;
if ( V_143 == '+' ) {
V_77 -> V_79 += V_77 -> V_28 ;
V_77 -> V_79 -- ;
}
}
F_4 ( L_58 , V_77 -> V_28 , V_77 -> V_79 ) ;
V_85 = - V_47 ;
if ( V_77 -> V_28 > V_77 -> V_79 ) {
F_91 ( L_59
L_60 ) ;
goto V_85;
}
if ( * V_142 != '\0' ) {
F_91 ( L_61 , V_142 ) ;
goto V_85;
}
}
V_51 = strchr ( V_15 , '@' ) ;
if ( V_51 ) {
* V_51 = '\0' ;
V_77 -> V_51 = F_27 ( ++ V_51 ) ;
if ( V_77 -> V_51 == NULL ) {
V_85 = - V_46 ;
goto V_85;
}
V_77 -> V_52 = V_15 ;
} else if ( strchr ( V_15 , '/' ) || strchr ( V_15 , '.' ) )
V_77 -> V_51 = V_15 ;
else if ( F_92 ( V_15 ) )
V_77 -> V_52 = V_15 ;
else {
F_91 ( L_62 , V_15 ) ;
V_85 = - V_47 ;
goto V_85;
}
return 0 ;
V_85:
free ( V_15 ) ;
return V_85 ;
}
static int F_94 ( char * V_141 , struct V_72 * V_73 )
{
struct V_49 * V_50 = & V_73 -> V_75 ;
char * V_138 , * V_74 ;
char V_143 , V_144 = 0 ;
bool V_145 = false ;
if ( ! V_141 )
return - V_47 ;
V_138 = strpbrk ( V_141 , L_63 ) ;
if ( V_138 && * V_138 == '=' ) {
* V_138 = '\0' ;
V_74 = V_138 + 1 ;
if ( strchr ( V_141 , ':' ) ) {
F_91 ( L_64 ) ;
return - V_68 ;
}
if ( ! F_92 ( V_141 ) ) {
F_91 ( L_65
L_66 , V_141 ) ;
return - V_47 ;
}
V_73 -> V_146 = F_27 ( V_141 ) ;
if ( V_73 -> V_146 == NULL )
return - V_46 ;
V_73 -> V_147 = NULL ;
V_141 = V_74 ;
}
if ( ! strpbrk ( V_141 , L_67 ) && ( V_138 = strpbrk ( V_141 , L_68 ) ) != NULL ) {
if ( memchr ( V_141 , '.' , V_138 - V_141 ) )
V_145 = true ;
}
V_138 = strpbrk ( V_141 , L_69 ) ;
if ( V_138 ) {
V_144 = * V_138 ;
* V_138 ++ = '\0' ;
}
if ( V_141 [ 0 ] == '\0' )
V_74 = NULL ;
else {
V_74 = F_27 ( V_141 ) ;
if ( V_74 == NULL )
return - V_46 ;
}
if ( V_145 )
V_50 -> V_51 = V_74 ;
else {
V_50 -> V_52 = V_74 ;
if ( V_74 && ! strncmp ( V_74 , L_70 , 2 ) ) {
V_50 -> V_148 = strtoul ( V_50 -> V_52 , & V_74 , 0 ) ;
if ( * V_74 != '\0' ) {
F_91 ( L_71 ) ;
return - V_47 ;
}
}
}
while ( V_138 ) {
V_141 = V_138 ;
V_143 = V_144 ;
if ( V_143 == ';' ) {
V_50 -> V_53 = F_27 ( V_141 ) ;
if ( V_50 -> V_53 == NULL )
return - V_46 ;
break;
}
V_138 = strpbrk ( V_141 , L_69 ) ;
if ( V_138 ) {
V_144 = * V_138 ;
* V_138 ++ = '\0' ;
}
switch ( V_143 ) {
case ':' :
V_50 -> line = strtoul ( V_141 , & V_74 , 0 ) ;
if ( * V_74 != '\0' ) {
F_91 ( L_72
L_73 ) ;
return - V_47 ;
}
break;
case '+' :
V_50 -> V_70 = strtoul ( V_141 , & V_74 , 0 ) ;
if ( * V_74 != '\0' ) {
F_91 ( L_74
L_75 ) ;
return - V_47 ;
}
break;
case '@' :
if ( V_50 -> V_51 ) {
F_91 ( L_76 ) ;
return - V_47 ;
}
V_50 -> V_51 = F_27 ( V_141 ) ;
if ( V_50 -> V_51 == NULL )
return - V_46 ;
break;
case '%' :
if ( strcmp ( V_141 , L_77 ) == 0 ) {
V_50 -> V_71 = 1 ;
} else {
F_91 ( L_78 , V_141 ) ;
return - V_68 ;
}
break;
default:
F_46 ( L_79 ,
__FILE__ , __LINE__ ) ;
return - V_68 ;
break;
}
}
if ( V_50 -> V_53 && V_50 -> line ) {
F_91 ( L_80
L_81 ) ;
return - V_47 ;
}
if ( V_50 -> V_53 && V_50 -> V_70 ) {
F_91 ( L_82 ) ;
return - V_47 ;
}
if ( V_50 -> line && V_50 -> V_70 ) {
F_91 ( L_83 ) ;
return - V_47 ;
}
if ( ! V_50 -> line && ! V_50 -> V_53 && V_50 -> V_51 && ! V_50 -> V_52 ) {
F_91 ( L_84
L_85 ) ;
return - V_47 ;
}
if ( V_50 -> V_70 && ! V_50 -> V_52 ) {
F_91 ( L_86 ) ;
return - V_47 ;
}
if ( V_50 -> V_71 && ! V_50 -> V_52 ) {
F_91 ( L_87 ) ;
return - V_47 ;
}
if ( ( V_50 -> V_70 || V_50 -> line || V_50 -> V_53 ) && V_50 -> V_71 ) {
F_91 ( L_88
L_89 ) ;
return - V_47 ;
}
F_4 ( L_90 ,
V_50 -> V_52 , V_50 -> V_51 , V_50 -> line , V_50 -> V_70 , V_50 -> V_71 ,
V_50 -> V_53 ) ;
return 0 ;
}
static int F_95 ( char * V_1 , struct V_149 * V_141 )
{
char * V_74 , * V_150 ;
struct V_151 * * V_152 ;
F_4 ( L_91 , V_1 ) ;
V_74 = strchr ( V_1 , '=' ) ;
if ( V_74 ) {
V_141 -> V_15 = F_96 ( V_1 , V_74 - V_1 ) ;
if ( V_141 -> V_15 == NULL )
return - V_46 ;
F_4 ( L_92 , V_141 -> V_15 ) ;
V_1 = V_74 + 1 ;
}
V_74 = strchr ( V_1 , ':' ) ;
if ( V_74 ) {
* V_74 = '\0' ;
V_141 -> type = F_27 ( V_74 + 1 ) ;
if ( V_141 -> type == NULL )
return - V_46 ;
F_4 ( L_93 , V_141 -> type ) ;
}
V_74 = strpbrk ( V_1 , L_94 ) ;
if ( ! F_97 ( V_1 ) || ! V_74 ) {
V_141 -> V_130 = F_27 ( V_1 ) ;
if ( V_141 -> V_130 == NULL )
return - V_46 ;
F_4 ( L_95 , V_141 -> V_130 ) ;
return 0 ;
}
V_141 -> V_130 = F_96 ( V_1 , V_74 - V_1 ) ;
if ( V_141 -> V_130 == NULL )
return - V_46 ;
V_150 = V_141 -> V_130 ;
F_4 ( L_96 , V_141 -> V_130 ) ;
V_152 = & V_141 -> V_153 ;
do {
* V_152 = F_98 ( sizeof( struct V_151 ) ) ;
if ( * V_152 == NULL )
return - V_46 ;
if ( * V_74 == '[' ) {
V_1 = V_74 ;
( * V_152 ) -> V_154 = strtol ( V_1 + 1 , & V_74 , 0 ) ;
( * V_152 ) -> V_155 = true ;
if ( * V_74 != ']' || V_74 == V_1 + 1 ) {
F_91 ( L_97
L_98 ) ;
return - V_47 ;
}
V_74 ++ ;
if ( * V_74 == '\0' )
V_74 = NULL ;
} else {
if ( * V_74 == '.' ) {
V_1 = V_74 + 1 ;
( * V_152 ) -> V_155 = false ;
} else if ( V_74 [ 1 ] == '>' ) {
V_1 = V_74 + 2 ;
( * V_152 ) -> V_155 = true ;
} else {
F_91 ( L_99 ,
V_1 ) ;
return - V_47 ;
}
V_74 = strpbrk ( V_1 , L_94 ) ;
}
if ( V_74 ) {
( * V_152 ) -> V_15 = F_96 ( V_1 , V_74 - V_1 ) ;
if ( ( * V_152 ) -> V_15 == NULL )
return - V_46 ;
if ( * V_1 != '[' )
V_150 = ( * V_152 ) -> V_15 ;
F_4 ( L_100 , ( * V_152 ) -> V_15 , ( * V_152 ) -> V_155 ) ;
V_152 = & ( * V_152 ) -> V_156 ;
}
} while ( V_74 );
( * V_152 ) -> V_15 = F_27 ( V_1 ) ;
if ( ( * V_152 ) -> V_15 == NULL )
return - V_46 ;
if ( * V_1 != '[' )
V_150 = ( * V_152 ) -> V_15 ;
F_4 ( L_101 , ( * V_152 ) -> V_15 , ( * V_152 ) -> V_155 ) ;
if ( ! V_141 -> V_15 ) {
V_141 -> V_15 = F_27 ( V_150 ) ;
if ( V_141 -> V_15 == NULL )
return - V_46 ;
}
return 0 ;
}
int F_99 ( const char * V_157 , struct V_72 * V_73 )
{
char * * V_158 ;
int V_159 , V_57 , V_4 = 0 ;
V_158 = F_100 ( V_157 , & V_159 ) ;
if ( ! V_158 ) {
F_4 ( L_102 ) ;
return - V_46 ;
}
if ( V_159 - 1 > V_160 ) {
F_91 ( L_103 , V_159 - 1 ) ;
V_4 = - V_161 ;
goto V_11;
}
V_4 = F_94 ( V_158 [ 0 ] , V_73 ) ;
if ( V_4 < 0 )
goto V_11;
V_73 -> V_162 = V_159 - 1 ;
V_73 -> args = F_98 ( sizeof( struct V_149 ) * V_73 -> V_162 ) ;
if ( V_73 -> args == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
for ( V_57 = 0 ; V_57 < V_73 -> V_162 && V_4 >= 0 ; V_57 ++ ) {
V_4 = F_95 ( V_158 [ V_57 + 1 ] , & V_73 -> args [ V_57 ] ) ;
if ( V_4 >= 0 &&
F_97 ( V_73 -> args [ V_57 ] . V_130 ) && V_73 -> V_75 . V_71 ) {
F_91 ( L_104
L_105 ) ;
V_4 = - V_47 ;
}
}
V_11:
F_101 ( V_158 ) ;
return V_4 ;
}
bool F_64 ( struct V_72 * V_73 )
{
int V_57 ;
if ( V_73 -> V_75 . V_51 || V_73 -> V_75 . line || V_73 -> V_75 . V_53 )
return true ;
for ( V_57 = 0 ; V_57 < V_73 -> V_162 ; V_57 ++ )
if ( F_97 ( V_73 -> args [ V_57 ] . V_130 ) )
return true ;
return false ;
}
int F_102 ( const char * V_157 , struct V_54 * V_163 )
{
struct V_98 * V_99 = & V_163 -> V_75 ;
char V_164 ;
char * V_165 ;
char * V_166 = NULL , * V_167 , * V_168 , * V_169 , * V_170 ;
int V_4 , V_57 , V_159 ;
char * * V_158 ;
F_4 ( L_106 , V_157 ) ;
V_158 = F_100 ( V_157 , & V_159 ) ;
if ( ! V_158 ) {
F_4 ( L_102 ) ;
return - V_46 ;
}
if ( V_159 < 2 ) {
F_91 ( L_107 ) ;
V_4 = - V_161 ;
goto V_11;
}
V_166 = F_27 ( V_158 [ 0 ] ) ;
if ( V_166 == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
V_168 = strtok_r ( V_166 , L_108 , & V_167 ) ;
V_169 = strtok_r ( NULL , L_109 , & V_167 ) ;
V_170 = strtok_r ( NULL , L_110 , & V_167 ) ;
if ( V_168 == NULL || strlen ( V_168 ) != 1 || V_169 == NULL
|| V_170 == NULL ) {
F_91 ( L_111 , V_158 [ 0 ] ) ;
V_4 = - V_47 ;
goto V_11;
}
V_164 = V_168 [ 0 ] ;
V_163 -> V_147 = F_27 ( V_169 ) ;
V_163 -> V_146 = F_27 ( V_170 ) ;
if ( V_163 -> V_147 == NULL || V_163 -> V_146 == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
F_4 ( L_112 , V_163 -> V_147 , V_163 -> V_146 , V_164 ) ;
V_99 -> V_71 = ( V_164 == 'r' ) ;
V_165 = strchr ( V_158 [ 1 ] , ':' ) ;
if ( V_165 ) {
V_99 -> V_29 = F_96 ( V_158 [ 1 ] , V_165 - V_158 [ 1 ] ) ;
V_165 ++ ;
} else
V_165 = V_158 [ 1 ] ;
V_168 = strtok_r ( V_165 , L_113 , & V_167 ) ;
if ( V_168 [ 0 ] == '0' ) {
if ( strcmp ( V_168 , L_70 ) == 0 ) {
if ( ! V_158 [ 2 ] || strcmp ( V_158 [ 2 ] , L_114 ) ) {
V_4 = - V_47 ;
goto V_11;
}
V_99 -> V_58 = 0 ;
free ( V_158 [ 2 ] ) ;
for ( V_57 = 2 ; V_158 [ V_57 + 1 ] != NULL ; V_57 ++ )
V_158 [ V_57 ] = V_158 [ V_57 + 1 ] ;
V_158 [ V_57 ] = NULL ;
V_159 -= 1 ;
} else
V_99 -> V_58 = strtoul ( V_168 , NULL , 0 ) ;
} else {
V_99 -> V_14 = F_27 ( V_168 ) ;
if ( V_99 -> V_14 == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
V_169 = strtok_r ( NULL , L_35 , & V_167 ) ;
if ( V_169 == NULL )
V_99 -> V_70 = 0 ;
else
V_99 -> V_70 = strtoul ( V_169 , NULL , 10 ) ;
}
V_163 -> V_162 = V_159 - 2 ;
V_163 -> args = F_98 ( sizeof( struct V_171 ) * V_163 -> V_162 ) ;
if ( V_163 -> args == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
for ( V_57 = 0 ; V_57 < V_163 -> V_162 ; V_57 ++ ) {
V_165 = strchr ( V_158 [ V_57 + 2 ] , '=' ) ;
if ( V_165 )
* V_165 ++ = '\0' ;
else
V_165 = V_158 [ V_57 + 2 ] ;
V_163 -> args [ V_57 ] . V_15 = F_27 ( V_158 [ V_57 + 2 ] ) ;
V_163 -> args [ V_57 ] . V_172 = F_27 ( V_165 ) ;
if ( V_163 -> args [ V_57 ] . V_15 == NULL || V_163 -> args [ V_57 ] . V_172 == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
free ( V_166 ) ;
F_101 ( V_158 ) ;
return V_4 ;
}
int F_103 ( struct V_149 * V_173 , char * V_45 , T_1 V_78 )
{
struct V_151 * V_153 = V_173 -> V_153 ;
int V_4 ;
char * V_74 = V_45 ;
if ( V_173 -> V_15 && V_173 -> V_130 )
V_4 = F_1 ( V_74 , V_78 , L_115 , V_173 -> V_15 , V_173 -> V_130 ) ;
else
V_4 = F_1 ( V_74 , V_78 , L_38 , V_173 -> V_15 ? V_173 -> V_15 : V_173 -> V_130 ) ;
if ( V_4 <= 0 )
goto error;
V_74 += V_4 ;
V_78 -= V_4 ;
while ( V_153 ) {
if ( V_153 -> V_15 [ 0 ] == '[' )
V_4 = F_1 ( V_74 , V_78 , L_38 , V_153 -> V_15 ) ;
else
V_4 = F_1 ( V_74 , V_78 , L_116 ,
V_153 -> V_155 ? L_117 : L_118 , V_153 -> V_15 ) ;
if ( V_4 <= 0 )
goto error;
V_74 += V_4 ;
V_78 -= V_4 ;
V_153 = V_153 -> V_156 ;
}
if ( V_173 -> type ) {
V_4 = F_1 ( V_74 , V_78 , L_119 , V_173 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_74 += V_4 ;
V_78 -= V_4 ;
}
return V_74 - V_45 ;
error:
F_4 ( L_120 , V_4 ) ;
return V_4 ;
}
static char * F_66 ( struct V_49 * V_50 )
{
char * V_45 , * V_74 ;
char V_174 [ 32 ] = L_35 , line [ 32 ] = L_35 , V_51 [ 32 ] = L_35 ;
int V_4 , V_78 ;
V_45 = F_98 ( V_175 ) ;
if ( V_45 == NULL ) {
V_4 = - V_46 ;
goto error;
}
if ( V_50 -> V_70 ) {
V_4 = F_1 ( V_174 , 32 , L_121 , V_50 -> V_70 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_50 -> line ) {
V_4 = F_1 ( line , 32 , L_122 , V_50 -> line ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_50 -> V_51 ) {
V_74 = V_50 -> V_51 ;
V_78 = strlen ( V_74 ) ;
if ( V_78 > 30 ) {
V_74 = strchr ( V_50 -> V_51 + V_78 - 30 , '/' ) ;
V_74 = V_74 ? V_74 + 1 : V_50 -> V_51 + V_78 - 30 ;
}
V_4 = F_1 ( V_51 , 32 , L_123 , V_74 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_50 -> V_52 )
V_4 = F_1 ( V_45 , V_175 , L_124 , V_50 -> V_52 ,
V_174 , V_50 -> V_71 ? L_125 : L_35 , line ,
V_51 ) ;
else
V_4 = F_1 ( V_45 , V_175 , L_116 , V_51 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_45 ;
error:
F_4 ( L_126 , V_4 ) ;
free ( V_45 ) ;
return NULL ;
}
static int F_104 ( struct V_176 * V_155 ,
char * * V_45 , T_1 * V_177 ,
int V_178 )
{
int V_4 ;
if ( V_155 -> V_156 ) {
V_178 = F_104 ( V_155 -> V_156 , V_45 ,
V_177 , V_178 + 1 ) ;
if ( V_178 < 0 )
goto V_11;
}
V_4 = F_1 ( * V_45 , * V_177 , L_127 , V_155 -> V_70 ) ;
if ( V_4 < 0 )
V_178 = V_4 ;
else {
* V_45 += V_4 ;
* V_177 -= V_4 ;
}
V_11:
return V_178 ;
}
static int F_105 ( struct V_171 * V_141 ,
char * V_45 , T_1 V_177 )
{
struct V_176 * V_155 = V_141 -> V_155 ;
int V_4 , V_178 = 0 ;
char * V_74 = V_45 ;
if ( V_141 -> V_15 )
V_4 = F_1 ( V_45 , V_177 , L_128 , V_141 -> V_15 ) ;
else
V_4 = F_1 ( V_45 , V_177 , L_129 ) ;
if ( V_4 < 0 )
return V_4 ;
V_45 += V_4 ;
V_177 -= V_4 ;
if ( V_141 -> V_172 [ 0 ] == '@' && V_141 -> V_155 )
V_155 = V_155 -> V_156 ;
if ( V_155 ) {
V_178 = F_104 ( V_155 , & V_45 ,
& V_177 , 1 ) ;
if ( V_178 < 0 )
return V_178 ;
}
if ( V_141 -> V_172 [ 0 ] == '@' && V_141 -> V_155 )
V_4 = F_1 ( V_45 , V_177 , L_130 , V_141 -> V_172 ,
V_141 -> V_155 -> V_70 ) ;
else
V_4 = F_1 ( V_45 , V_177 , L_38 , V_141 -> V_172 ) ;
if ( V_4 < 0 )
return V_4 ;
V_45 += V_4 ;
V_177 -= V_4 ;
while ( V_178 -- ) {
V_4 = F_1 ( V_45 , V_177 , L_131 ) ;
if ( V_4 < 0 )
return V_4 ;
V_45 += V_4 ;
V_177 -= V_4 ;
}
if ( V_141 -> type ) {
V_4 = F_1 ( V_45 , V_177 , L_119 , V_141 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_45 += V_4 ;
}
return V_45 - V_74 ;
}
char * F_106 ( struct V_54 * V_163 )
{
struct V_98 * V_99 = & V_163 -> V_75 ;
char * V_45 ;
int V_57 , V_78 , V_4 ;
V_45 = F_98 ( V_175 ) ;
if ( V_45 == NULL )
return NULL ;
V_78 = F_1 ( V_45 , V_175 , L_132 , V_99 -> V_71 ? 'r' : 'p' ,
V_163 -> V_147 , V_163 -> V_146 ) ;
if ( V_78 <= 0 )
goto error;
if ( V_163 -> V_67 && ! V_99 -> V_29 )
goto error;
if ( V_163 -> V_67 && ! V_99 -> V_58 ) {
if ( ! V_99 -> V_14 || strcmp ( V_99 -> V_14 , L_133 ) )
goto error;
}
if ( V_163 -> V_67 )
V_4 = F_1 ( V_45 + V_78 , V_175 - V_78 , L_134 ,
V_99 -> V_29 , V_99 -> V_58 ) ;
else if ( ! strncmp ( V_99 -> V_14 , L_70 , 2 ) )
V_4 = F_1 ( V_45 + V_78 , V_175 - V_78 , L_135 ,
V_99 -> V_29 ? : L_35 , V_99 -> V_29 ? L_108 : L_35 ,
V_99 -> V_58 ) ;
else
V_4 = F_1 ( V_45 + V_78 , V_175 - V_78 , L_136 ,
V_99 -> V_29 ? : L_35 , V_99 -> V_29 ? L_108 : L_35 ,
V_99 -> V_14 , V_99 -> V_70 ) ;
if ( V_4 <= 0 )
goto error;
V_78 += V_4 ;
for ( V_57 = 0 ; V_57 < V_163 -> V_162 ; V_57 ++ ) {
V_4 = F_105 ( & V_163 -> args [ V_57 ] , V_45 + V_78 ,
V_175 - V_78 ) ;
if ( V_4 <= 0 )
goto error;
V_78 += V_4 ;
}
return V_45 ;
error:
free ( V_45 ) ;
return NULL ;
}
static int F_107 ( struct V_98 * V_99 ,
struct V_49 * V_50 ,
bool V_100 )
{
struct V_14 * V_25 = NULL ;
struct V_16 * V_16 ;
T_3 V_18 = V_99 -> V_58 ;
int V_4 = - V_63 ;
if ( ! V_100 ) {
V_16 = F_23 ( V_99 -> V_29 ) ;
if ( ! V_16 )
goto V_11;
V_25 = F_108 ( V_16 , V_18 , NULL ) ;
} else {
if ( V_99 -> V_14 )
V_18 = F_17 ( V_99 -> V_14 , true ) ;
if ( V_18 ) {
V_18 += V_99 -> V_70 ;
V_25 = F_12 ( V_18 , & V_16 ) ;
}
}
if ( ! V_25 )
goto V_11;
V_50 -> V_71 = V_99 -> V_71 ;
V_50 -> V_70 = V_18 - V_16 -> V_27 ( V_16 , V_25 -> V_28 ) ;
V_50 -> V_52 = F_27 ( V_25 -> V_15 ) ;
V_4 = V_50 -> V_52 ? 0 : - V_46 ;
V_11:
if ( V_16 && ! V_100 ) {
F_25 ( V_16 ) ;
}
return V_4 ;
}
static int F_109 ( struct V_98 * V_99 ,
struct V_49 * V_50 ,
bool V_100 )
{
char V_45 [ 128 ] ;
int V_4 ;
V_4 = F_59 ( V_99 , V_50 , V_100 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_107 ( V_99 , V_50 , V_100 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( L_137 ) ;
if ( V_99 -> V_14 ) {
V_50 -> V_52 = F_27 ( V_99 -> V_14 ) ;
V_50 -> V_70 = V_99 -> V_70 ;
} else {
V_4 = F_1 ( V_45 , 128 , L_138 V_69 , ( T_3 ) V_99 -> V_58 ) ;
if ( V_4 < 0 )
return V_4 ;
V_50 -> V_52 = F_27 ( V_45 ) ;
V_50 -> V_70 = 0 ;
}
if ( V_50 -> V_52 == NULL )
return - V_46 ;
V_50 -> V_71 = V_99 -> V_71 ;
return 0 ;
}
static int F_110 ( struct V_54 * V_163 ,
struct V_72 * V_73 , bool V_100 )
{
char V_45 [ 64 ] = L_35 ;
int V_57 , V_4 ;
V_73 -> V_146 = F_27 ( V_163 -> V_146 ) ;
V_73 -> V_147 = F_27 ( V_163 -> V_147 ) ;
if ( V_73 -> V_146 == NULL || V_73 -> V_147 == NULL )
return - V_46 ;
V_4 = F_109 ( & V_163 -> V_75 , & V_73 -> V_75 , V_100 ) ;
if ( V_4 < 0 )
return V_4 ;
V_73 -> V_162 = V_163 -> V_162 ;
V_73 -> args = F_98 ( sizeof( struct V_149 ) * V_73 -> V_162 ) ;
if ( V_73 -> args == NULL )
return - V_46 ;
for ( V_57 = 0 ; V_57 < V_163 -> V_162 && V_4 >= 0 ; V_57 ++ ) {
if ( V_163 -> args [ V_57 ] . V_15 )
V_73 -> args [ V_57 ] . V_15 = F_27 ( V_163 -> args [ V_57 ] . V_15 ) ;
else {
V_4 = F_105 ( & V_163 -> args [ V_57 ] ,
V_45 , 64 ) ;
V_73 -> args [ V_57 ] . V_15 = F_27 ( V_45 ) ;
}
if ( V_73 -> args [ V_57 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_46 ;
}
if ( V_4 < 0 )
F_111 ( V_73 ) ;
return V_4 ;
}
void F_111 ( struct V_72 * V_73 )
{
struct V_151 * V_153 , * V_156 ;
int V_57 ;
free ( V_73 -> V_146 ) ;
free ( V_73 -> V_147 ) ;
free ( V_73 -> V_38 ) ;
F_29 ( & V_73 -> V_75 ) ;
for ( V_57 = 0 ; V_57 < V_73 -> V_162 ; V_57 ++ ) {
free ( V_73 -> args [ V_57 ] . V_15 ) ;
free ( V_73 -> args [ V_57 ] . V_130 ) ;
free ( V_73 -> args [ V_57 ] . type ) ;
V_153 = V_73 -> args [ V_57 ] . V_153 ;
while ( V_153 ) {
V_156 = V_153 -> V_156 ;
F_51 ( & V_153 -> V_15 ) ;
free ( V_153 ) ;
V_153 = V_156 ;
}
}
free ( V_73 -> args ) ;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
}
void F_31 ( struct V_54 * V_163 )
{
struct V_176 * V_155 , * V_156 ;
int V_57 ;
free ( V_163 -> V_146 ) ;
free ( V_163 -> V_147 ) ;
free ( V_163 -> V_75 . V_14 ) ;
free ( V_163 -> V_75 . V_105 ) ;
free ( V_163 -> V_75 . V_29 ) ;
for ( V_57 = 0 ; V_57 < V_163 -> V_162 ; V_57 ++ ) {
free ( V_163 -> args [ V_57 ] . V_15 ) ;
free ( V_163 -> args [ V_57 ] . V_172 ) ;
free ( V_163 -> args [ V_57 ] . type ) ;
V_155 = V_163 -> args [ V_57 ] . V_155 ;
while ( V_155 ) {
V_156 = V_155 -> V_156 ;
free ( V_155 ) ;
V_155 = V_156 ;
}
}
free ( V_163 -> args ) ;
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
}
static void F_112 ( struct V_179 * V_180 )
{
struct V_181 * V_126 ;
while ( ! F_113 ( V_180 ) ) {
V_126 = F_114 ( V_180 ,
struct V_181 , V_182 ) ;
F_115 ( & V_126 -> V_182 ) ;
free ( V_126 -> V_14 ) ;
free ( V_126 ) ;
}
}
static int F_116 ( struct V_179 * V_180 )
{
struct V_181 * V_126 ;
const char * V_183 = F_117 () ;
char V_45 [ V_184 ] , * V_165 ;
T_7 * V_108 ;
int V_4 ;
if ( V_183 == NULL )
return - V_68 ;
V_4 = F_1 ( V_45 , V_184 , L_139 , V_183 ) ;
if ( V_4 < 0 )
return V_4 ;
V_108 = fopen ( V_45 , L_46 ) ;
if ( ! V_108 )
return - V_94 ;
V_4 = 0 ;
while ( fgets ( V_45 , V_184 , V_108 ) ) {
V_126 = F_98 ( sizeof( * V_126 ) ) ;
if ( ! V_126 ) {
V_4 = - V_46 ;
break;
}
F_118 ( & V_126 -> V_182 ) ;
F_119 ( & V_126 -> V_182 , V_180 ) ;
if ( sscanf ( V_45 , L_140 , & V_126 -> V_28 , & V_126 -> V_79 ) != 2 ) {
V_4 = - V_47 ;
break;
}
V_165 = strchr ( V_45 , '\t' ) ;
if ( V_165 ) {
V_165 ++ ;
if ( V_165 [ strlen ( V_165 ) - 1 ] == '\n' )
V_165 [ strlen ( V_165 ) - 1 ] = '\0' ;
} else
V_165 = ( char * ) L_141 ;
V_126 -> V_14 = F_27 ( V_165 ) ;
if ( ! V_126 -> V_14 ) {
V_4 = - V_46 ;
break;
}
F_120 ( L_142 ,
V_126 -> V_28 , V_126 -> V_79 , V_126 -> V_14 ) ;
V_4 ++ ;
}
if ( V_4 < 0 )
F_112 ( V_180 ) ;
fclose ( V_108 ) ;
return V_4 ;
}
static struct V_181 *
F_121 ( struct V_179 * V_180 ,
unsigned long V_58 )
{
struct V_181 * V_126 ;
F_122 (node, blacklist, list) {
if ( V_126 -> V_28 <= V_58 && V_58 <= V_126 -> V_79 )
return V_126 ;
}
return NULL ;
}
static void F_123 ( void )
{
if ( ! F_113 ( & V_185 ) )
return;
if ( F_116 ( & V_185 ) < 0 )
F_4 ( L_143 ) ;
}
static void F_124 ( void )
{
F_112 ( & V_185 ) ;
}
static bool F_33 ( unsigned long V_58 )
{
return ! ! F_121 ( & V_185 , V_58 ) ;
}
static int F_125 ( const char * V_147 , const char * V_146 ,
struct V_72 * V_73 ,
const char * V_29 ,
struct V_186 * V_41 )
{
int V_57 , V_4 ;
char V_45 [ 128 ] ;
char * V_187 ;
V_187 = F_66 ( & V_73 -> V_75 ) ;
if ( ! V_187 )
return - V_47 ;
V_4 = F_1 ( V_45 , 128 , L_144 , V_147 , V_146 ) ;
if ( V_4 < 0 )
goto V_11;
F_126 ( V_41 , L_145 , V_45 , V_187 ) ;
if ( V_29 )
F_126 ( V_41 , L_146 , V_29 ) ;
if ( V_73 -> V_162 > 0 ) {
F_127 ( V_41 , L_147 ) ;
for ( V_57 = 0 ; V_57 < V_73 -> V_162 ; V_57 ++ ) {
V_4 = F_103 ( & V_73 -> args [ V_57 ] ,
V_45 , 128 ) ;
if ( V_4 < 0 )
goto V_11;
F_126 ( V_41 , L_148 , V_45 ) ;
}
}
F_128 ( V_41 , ')' ) ;
V_11:
free ( V_187 ) ;
return V_4 ;
}
static int F_129 ( const char * V_147 , const char * V_146 ,
struct V_72 * V_73 ,
const char * V_29 , bool V_188 )
{
struct V_186 V_45 = V_189 ;
int V_4 ;
V_4 = F_125 ( V_147 , V_146 , V_73 , V_29 , & V_45 ) ;
if ( V_4 >= 0 ) {
if ( V_188 )
printf ( L_95 , V_45 . V_45 ) ;
else
F_130 ( L_95 , V_45 . V_45 ) ;
}
F_131 ( & V_45 ) ;
return V_4 ;
}
static bool F_132 ( struct V_54 * V_163 ,
struct V_122 * T_8 )
{
char V_74 [ 128 ] ;
if ( F_83 ( T_8 , V_163 -> V_146 ) )
return true ;
if ( F_1 ( V_74 , 128 , L_144 , V_163 -> V_147 , V_163 -> V_146 ) < 0 )
return false ;
return F_83 ( T_8 , V_74 ) ;
}
static int F_133 ( int V_92 , bool V_100 ,
struct V_122 * T_8 )
{
int V_4 = 0 ;
struct V_54 V_163 ;
struct V_72 V_73 ;
struct V_190 * V_191 ;
struct V_125 * V_192 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_191 = F_134 ( V_92 ) ;
if ( ! V_191 )
return - V_46 ;
F_82 (ent, rawlist) {
V_4 = F_102 ( V_192 -> V_132 , & V_163 ) ;
if ( V_4 >= 0 ) {
if ( ! F_132 ( & V_163 , T_8 ) )
goto V_156;
V_4 = F_110 ( & V_163 , & V_73 ,
V_100 ) ;
if ( V_4 < 0 )
goto V_156;
V_4 = F_129 ( V_73 . V_147 , V_73 . V_146 ,
& V_73 , V_163 . V_75 . V_29 ,
true ) ;
}
V_156:
F_111 ( & V_73 ) ;
F_31 ( & V_163 ) ;
if ( V_4 < 0 )
break;
}
F_84 ( V_191 ) ;
F_52 () ;
return V_4 ;
}
int F_135 ( struct V_122 * T_8 )
{
int V_193 , V_194 , V_4 ;
F_73 () ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_136 ( & V_193 , & V_194 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_193 >= 0 )
V_4 = F_133 ( V_193 , true , T_8 ) ;
if ( V_194 >= 0 && V_4 >= 0 )
V_4 = F_133 ( V_194 , false , T_8 ) ;
if ( V_193 > 0 )
F_137 ( V_193 ) ;
if ( V_194 > 0 )
F_137 ( V_194 ) ;
F_8 () ;
return V_4 ;
}
static int F_138 ( char * V_45 , T_1 V_78 , const char * V_195 ,
struct V_190 * V_196 , bool V_197 )
{
int V_57 , V_4 ;
char * V_165 ;
if ( * V_195 == '.' )
V_195 ++ ;
V_4 = F_1 ( V_45 , V_78 , L_38 , V_195 ) ;
if ( V_4 < 0 ) {
F_4 ( L_149 , V_4 ) ;
return V_4 ;
}
V_165 = strchr ( V_45 , '.' ) ;
if ( V_165 && V_165 != V_45 )
* V_165 = '\0' ;
if ( ! F_139 ( V_196 , V_45 ) )
return 0 ;
if ( ! V_197 ) {
F_7 ( L_150
L_151 , V_195 ) ;
return - V_198 ;
}
for ( V_57 = 1 ; V_57 < V_199 ; V_57 ++ ) {
V_4 = F_1 ( V_45 , V_78 , L_152 , V_195 , V_57 ) ;
if ( V_4 < 0 ) {
F_4 ( L_149 , V_4 ) ;
return V_4 ;
}
if ( ! F_139 ( V_196 , V_45 ) )
break;
}
if ( V_57 == V_199 ) {
F_7 ( L_153 ) ;
V_4 = - V_161 ;
}
return V_4 ;
}
static void F_140 ( struct V_54 * V_163 )
{
int V_57 ;
char * V_45 = F_106 ( V_163 ) ;
if ( ! V_163 -> V_67 || V_163 -> V_162 == 0 || ! V_45 )
goto V_11;
for ( V_57 = 0 ; V_57 < V_163 -> V_162 ; V_57 ++ )
if ( F_141 ( V_163 -> args [ V_57 ] . V_172 , L_154 ) ) {
F_7 ( L_155
L_156 ,
V_163 -> args [ V_57 ] . V_172 ) ;
break;
}
V_11:
free ( V_45 ) ;
}
static int F_142 ( struct V_54 * V_163 ,
struct V_72 * V_73 ,
struct V_190 * V_196 ,
bool V_197 )
{
const char * V_146 , * V_147 ;
char V_45 [ 64 ] ;
int V_4 ;
if ( V_73 -> V_146 )
V_146 = V_73 -> V_146 ;
else
if ( V_73 -> V_75 . V_52 &&
( strncmp ( V_73 -> V_75 . V_52 , L_70 , 2 ) != 0 ) &&
! F_143 ( V_73 -> V_75 . V_52 ) )
V_146 = V_73 -> V_75 . V_52 ;
else
V_146 = V_163 -> V_75 . V_105 ;
if ( V_73 -> V_147 )
V_147 = V_73 -> V_147 ;
else
V_147 = V_48 ;
V_4 = F_138 ( V_45 , 64 , V_146 ,
V_196 , V_197 ) ;
if ( V_4 < 0 )
return V_4 ;
V_146 = V_45 ;
V_163 -> V_146 = F_27 ( V_146 ) ;
V_163 -> V_147 = F_27 ( V_147 ) ;
if ( V_163 -> V_146 == NULL || V_163 -> V_147 == NULL )
return - V_46 ;
F_144 ( V_196 , V_146 ) ;
return 0 ;
}
static int F_145 ( struct V_72 * V_73 ,
struct V_54 * V_55 ,
int V_56 , bool V_197 )
{
int V_57 , V_92 , V_4 ;
struct V_54 * V_163 = NULL ;
const char * V_146 = NULL , * V_147 = NULL ;
struct V_190 * V_196 ;
V_92 = F_146 ( V_200 | ( V_73 -> V_67 ? V_201 : 0 ) ) ;
if ( V_92 < 0 )
return V_92 ;
V_196 = F_147 ( V_92 ) ;
if ( ! V_196 ) {
F_4 ( L_157 ) ;
V_4 = - V_46 ;
goto V_202;
}
V_4 = 0 ;
F_130 ( L_158 , ( V_56 > 1 ) ? L_159 : L_108 ) ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
V_163 = & V_55 [ V_57 ] ;
if ( ! V_163 -> V_75 . V_14 )
continue;
V_4 = F_142 ( V_163 , V_73 , V_196 ,
V_197 ) ;
if ( V_4 < 0 )
break;
V_4 = F_148 ( V_92 , V_163 ) ;
if ( V_4 < 0 )
break;
F_129 ( V_163 -> V_147 , V_163 -> V_146 , V_73 ,
V_163 -> V_75 . V_29 , false ) ;
V_146 = V_163 -> V_146 ;
V_147 = V_163 -> V_147 ;
V_197 = true ;
}
if ( V_4 == - V_47 && V_73 -> V_67 )
F_140 ( V_163 ) ;
if ( V_4 >= 0 && V_146 ) {
F_130 ( L_160 ) ;
F_130 ( L_161 , V_147 , V_146 ) ;
}
F_84 ( V_196 ) ;
V_202:
F_137 ( V_92 ) ;
return V_4 ;
}
static int F_149 ( struct V_16 * V_16 , char * V_15 ,
struct V_14 * * V_203 )
{
int V_62 = 0 ;
struct V_14 * V_25 ;
struct V_204 * V_74 ;
if ( F_15 ( V_16 , NULL ) < 0 )
return 0 ;
F_150 (map, sym, tmp) {
if ( F_141 ( V_25 -> V_15 , V_15 ) ) {
V_62 ++ ;
if ( V_203 && V_62 < V_205 . V_206 )
V_203 [ V_62 - 1 ] = V_25 ;
}
}
return V_62 ;
}
void __weak F_151 ( struct V_72 * V_73 V_135 ,
struct V_54 * V_163 V_135 ,
struct V_16 * V_16 V_135 ) { }
static int F_152 ( struct V_72 * V_73 ,
struct V_54 * * V_55 )
{
struct V_16 * V_16 = NULL ;
struct V_19 * V_24 = NULL ;
struct V_14 * V_25 ;
struct V_14 * * V_203 = NULL ;
struct V_54 * V_163 ;
struct V_49 * V_50 = & V_73 -> V_75 ;
struct V_98 * V_99 ;
int V_207 ;
int V_4 , V_57 , V_208 , V_104 = 0 ;
V_16 = F_22 ( V_73 -> V_38 , V_73 -> V_67 ) ;
if ( ! V_16 ) {
V_4 = - V_47 ;
goto V_11;
}
V_203 = malloc ( sizeof( struct V_14 * ) * V_205 . V_206 ) ;
if ( ! V_203 ) {
V_4 = - V_46 ;
goto V_11;
}
V_207 = F_149 ( V_16 , V_50 -> V_52 , V_203 ) ;
if ( V_207 == 0 ) {
F_46 ( L_162 , V_50 -> V_52 ,
V_73 -> V_38 ? : L_5 ) ;
V_4 = - V_63 ;
goto V_11;
} else if ( V_207 > V_205 . V_206 ) {
F_46 ( L_163 ,
V_73 -> V_38 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
if ( ! V_73 -> V_67 && ! V_50 -> V_71 ) {
V_24 = F_14 () ;
if ( ! V_24 ) {
F_7 ( L_26 ) ;
V_4 = - V_47 ;
goto V_11;
}
}
* V_55 = F_98 ( sizeof( * V_163 ) * V_207 ) ;
if ( ! * V_55 ) {
V_4 = - V_46 ;
goto V_11;
}
V_4 = 0 ;
for ( V_208 = 0 ; V_208 < V_207 ; V_208 ++ ) {
V_25 = V_203 [ V_208 ] ;
V_163 = ( * V_55 ) + V_4 ;
V_99 = & V_163 -> V_75 ;
if ( V_4 == V_207 ) {
F_7 ( L_164 ) ;
break;
}
V_4 ++ ;
if ( V_50 -> V_70 > V_25 -> V_79 - V_25 -> V_28 ) {
F_7 ( L_165 ,
V_50 -> V_70 , V_25 -> V_15 ) ;
V_4 = - V_63 ;
goto V_209;
}
V_99 -> V_58 = V_16 -> V_27 ( V_16 , V_25 -> V_28 ) + V_50 -> V_70 ;
if ( ! V_73 -> V_67 &&
F_32 ( V_25 -> V_15 , V_99 -> V_58 ) ) {
V_99 -> V_14 = NULL ;
V_104 ++ ;
} else if ( V_24 ) {
V_99 -> V_14 = F_153 ( V_24 -> V_15 , V_210 ) ;
V_99 -> V_70 = V_99 -> V_58 - V_24 -> V_18 ;
} else {
V_99 -> V_14 = F_153 ( V_25 -> V_15 , V_210 ) ;
V_99 -> V_70 = V_50 -> V_70 ;
}
V_99 -> V_105 = F_153 ( V_25 -> V_15 , V_210 ) ;
V_99 -> V_71 = V_50 -> V_71 ;
if ( V_73 -> V_38 )
V_163 -> V_75 . V_29 = F_153 ( V_73 -> V_38 ,
V_210 ) ;
V_163 -> V_67 = V_73 -> V_67 ;
V_163 -> V_162 = V_73 -> V_162 ;
if ( V_163 -> V_162 ) {
V_163 -> args = F_98 ( sizeof( struct V_171 ) *
V_163 -> V_162 ) ;
if ( V_163 -> args == NULL )
goto V_210;
}
for ( V_57 = 0 ; V_57 < V_163 -> V_162 ; V_57 ++ ) {
if ( V_73 -> args [ V_57 ] . V_15 )
V_163 -> args [ V_57 ] . V_15 =
F_153 ( V_73 -> args [ V_57 ] . V_15 ,
V_210 ) ;
V_163 -> args [ V_57 ] . V_172 = F_153 ( V_73 -> args [ V_57 ] . V_130 ,
V_210 ) ;
if ( V_73 -> args [ V_57 ] . type )
V_163 -> args [ V_57 ] . type =
F_153 ( V_73 -> args [ V_57 ] . type ,
V_210 ) ;
}
F_151 ( V_73 , V_163 , V_16 ) ;
}
if ( V_4 == V_104 ) {
V_4 = - V_63 ;
goto V_209;
}
V_11:
F_24 ( V_16 , V_73 -> V_67 ) ;
free ( V_203 ) ;
return V_4 ;
V_210:
V_4 = - V_46 ;
V_209:
F_30 ( * V_55 , V_207 ) ;
F_51 ( V_55 ) ;
goto V_11;
}
static int F_154 ( struct V_72 * V_73 ,
struct V_54 * * V_55 )
{
struct V_49 * V_50 = & V_73 -> V_75 ;
struct V_54 * V_163 ;
struct V_98 * V_99 ;
int V_57 , V_85 ;
if ( ! ( V_73 -> V_75 . V_52 && ! strncmp ( V_73 -> V_75 . V_52 , L_70 , 2 ) ) )
return - V_47 ;
if ( F_64 ( V_73 ) )
return - V_47 ;
* V_55 = F_98 ( sizeof( * V_163 ) ) ;
if ( ! * V_55 )
return - V_46 ;
V_163 = * V_55 ;
V_99 = & V_163 -> V_75 ;
V_99 -> V_58 = V_73 -> V_75 . V_148 ;
V_99 -> V_71 = V_50 -> V_71 ;
V_163 -> V_67 = V_73 -> V_67 ;
V_85 = - V_46 ;
if ( F_155 ( & V_99 -> V_14 , L_166 , V_99 -> V_58 ) < 0 )
goto V_211;
if ( ( ! V_163 -> V_67 ) &&
( F_32 ( V_163 -> V_75 . V_14 ,
V_163 -> V_75 . V_58 ) ) ) {
V_85 = - V_212 ;
goto V_211;
}
if ( F_155 ( & V_99 -> V_105 , L_167 , V_99 -> V_58 ) < 0 )
goto V_211;
if ( V_73 -> V_38 ) {
V_99 -> V_29 = F_27 ( V_73 -> V_38 ) ;
if ( ! V_99 -> V_29 )
goto V_211;
}
if ( V_163 -> V_147 ) {
V_163 -> V_147 = F_27 ( V_73 -> V_147 ) ;
if ( ! V_163 -> V_147 )
goto V_211;
}
if ( V_73 -> V_146 ) {
V_163 -> V_146 = F_27 ( V_73 -> V_146 ) ;
if ( ! V_163 -> V_146 )
goto V_211;
}
V_163 -> V_162 = V_73 -> V_162 ;
V_163 -> args = F_98 ( sizeof( struct V_171 ) * V_163 -> V_162 ) ;
if ( ! V_163 -> args ) {
V_85 = - V_46 ;
goto V_211;
}
for ( V_57 = 0 ; V_57 < V_163 -> V_162 ; V_57 ++ )
F_156 ( & V_163 -> args [ V_57 ] , & V_73 -> args [ V_57 ] ) ;
return 1 ;
V_211:
if ( * V_55 ) {
F_30 ( * V_55 , 1 ) ;
* V_55 = NULL ;
}
return V_85 ;
}
bool __weak F_157 ( void ) { return false ; }
static int F_158 ( struct V_72 * V_73 ,
struct V_54 * * V_55 )
{
int V_4 ;
if ( V_73 -> V_67 && ! V_73 -> V_147 ) {
V_4 = F_26 ( V_73 -> V_38 , & V_73 -> V_147 ) ;
if ( V_4 != 0 ) {
F_7 ( L_168 ) ;
return V_4 ;
}
}
V_4 = F_154 ( V_73 , V_55 ) ;
if ( V_4 > 0 )
return V_4 ;
if ( F_157 () && ! F_64 ( V_73 ) ) {
V_4 = F_152 ( V_73 , V_55 ) ;
if ( V_4 > 0 )
return V_4 ;
}
V_4 = F_63 ( V_73 , V_55 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_152 ( V_73 , V_55 ) ;
}
int F_159 ( struct V_72 * V_133 , int V_134 )
{
int V_57 , V_208 , V_4 ;
struct V_213 * V_214 ;
V_4 = 0 ;
V_214 = F_98 ( sizeof( struct V_213 ) * V_134 ) ;
if ( V_214 == NULL )
return - V_46 ;
V_4 = F_2 ( V_133 -> V_67 ) ;
if ( V_4 < 0 ) {
free ( V_214 ) ;
return V_4 ;
}
for ( V_57 = 0 ; V_57 < V_134 ; V_57 ++ ) {
V_214 [ V_57 ] . V_73 = & V_133 [ V_57 ] ;
if ( ! V_214 [ V_57 ] . V_73 -> V_67 )
F_123 () ;
V_4 = F_158 ( V_214 [ V_57 ] . V_73 ,
& V_214 [ V_57 ] . V_55 ) ;
if ( V_4 < 0 )
goto V_79;
V_214 [ V_57 ] . V_56 = V_4 ;
}
F_124 () ;
for ( V_57 = 0 ; V_57 < V_134 ; V_57 ++ ) {
V_4 = F_145 ( V_214 [ V_57 ] . V_73 , V_214 [ V_57 ] . V_55 ,
V_214 [ V_57 ] . V_56 ,
V_205 . V_215 ) ;
if ( V_4 < 0 )
break;
}
V_79:
for ( V_57 = 0 ; V_57 < V_134 ; V_57 ++ ) {
for ( V_208 = 0 ; V_208 < V_214 [ V_57 ] . V_56 ; V_208 ++ )
F_31 ( & V_214 [ V_57 ] . V_55 [ V_208 ] ) ;
F_51 ( & V_214 [ V_57 ] . V_55 ) ;
}
free ( V_214 ) ;
F_8 () ;
return V_4 ;
}
int F_160 ( struct V_122 * T_8 )
{
int V_4 , V_216 , V_217 = - 1 , V_218 = - 1 ;
char * V_1 = F_161 ( T_8 ) ;
if ( ! V_1 )
return - V_47 ;
F_4 ( L_169 , V_1 ) ;
V_4 = F_136 ( & V_218 , & V_217 , V_200 ) ;
if ( V_4 < 0 )
goto V_11;
V_4 = F_162 ( V_218 , T_8 ) ;
if ( V_4 < 0 && V_4 != - V_63 )
goto error;
V_216 = F_162 ( V_217 , T_8 ) ;
if ( V_216 < 0 && V_216 != - V_63 ) {
V_4 = V_216 ;
goto error;
}
if ( V_4 == - V_63 && V_216 == - V_63 )
F_4 ( L_170 , V_1 ) ;
V_4 = 0 ;
error:
if ( V_218 >= 0 )
F_137 ( V_218 ) ;
if ( V_217 >= 0 )
F_137 ( V_217 ) ;
V_11:
free ( V_1 ) ;
return V_4 ;
}
static int F_163 ( struct V_16 * V_16 V_135 ,
struct V_14 * V_25 )
{
if ( F_83 ( V_219 , V_25 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_164 ( const char * V_38 , struct V_122 * V_123 ,
bool V_39 )
{
struct V_16 * V_16 ;
int V_4 ;
V_4 = F_2 ( V_39 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_39 )
V_16 = F_23 ( V_38 ) ;
else
V_16 = F_18 ( V_38 ) ;
if ( ! V_16 ) {
F_46 ( L_171 , ( V_38 ) ? : L_5 ) ;
return - V_47 ;
}
V_219 = V_123 ;
if ( F_15 ( V_16 , F_163 ) ) {
F_46 ( L_172 , ( V_38 ) ? : L_5 ) ;
goto V_79;
}
if ( ! F_165 ( V_16 -> V_35 , V_16 -> type ) )
F_166 ( V_16 -> V_35 , V_16 -> type ) ;
F_73 () ;
F_167 ( V_16 -> V_35 , V_16 -> type , stdout ) ;
V_79:
if ( V_39 ) {
F_25 ( V_16 ) ;
}
F_8 () ;
return V_4 ;
}
int F_156 ( struct V_171 * V_220 ,
struct V_149 * V_221 )
{
V_220 -> V_172 = F_27 ( V_221 -> V_130 ) ;
if ( V_220 -> V_172 == NULL )
return - V_46 ;
if ( V_221 -> type ) {
V_220 -> type = F_27 ( V_221 -> type ) ;
if ( V_220 -> type == NULL )
return - V_46 ;
}
if ( V_221 -> V_15 ) {
V_220 -> V_15 = F_27 ( V_221 -> V_15 ) ;
if ( V_220 -> V_15 == NULL )
return - V_46 ;
} else
V_220 -> V_15 = NULL ;
return 0 ;
}
