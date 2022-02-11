static int F_1 ( char * V_1 , T_1 V_2 , const char * V_3 , ... )
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
F_35 (dso, &host_machine->dsos.head, node) {
if ( ! V_35 -> V_61 )
continue;
if ( strncmp ( V_35 -> V_36 + 1 , V_29 ,
V_35 -> V_37 - 2 ) == 0 )
goto V_62;
}
F_4 ( L_11 , V_29 ) ;
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
F_4 ( L_12 V_69 L_13 ,
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
strcpy ( V_83 , L_14 ) ;
} else
F_45 ( V_35 , V_83 , V_84 ) ;
if ( ! V_81 )
F_46 ( L_15 ,
V_29 ? : L_5 , V_83 ) ;
return NULL ;
}
V_82 = V_35 -> V_86 ;
}
V_4 = F_47 ( V_82 ) ;
if ( ! V_4 && ! V_81 ) {
F_7 ( L_16 , V_82 ) ;
if ( ! V_29 || ! F_48 ( V_82 , L_17 ) )
F_7 ( L_18 ) ;
else
F_7 ( L_19 ) ;
F_7 ( L_20 ) ;
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
if ( ! F_57 ( V_89 , & V_90 , & V_91 , L_21 , NULL ) )
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
} else {
V_18 = F_17 ( V_99 -> V_14 , false ) ;
if ( V_18 == 0 )
goto error;
V_18 += V_99 -> V_70 ;
}
F_4 ( L_22 V_69 L_23 , V_18 ,
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
F_4 ( L_24 ) ;
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
F_7 ( L_25 ) ;
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
F_4 ( L_26 ) ;
return 0 ;
}
F_4 ( L_27 ) ;
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
F_4 ( L_28 , V_56 ) ;
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
F_7 ( L_29 ,
F_66 ( & V_73 -> V_75 ) ) ;
return - V_63 ;
}
F_4 ( L_30 , V_56 ) ;
if ( V_56 == - V_107 ) {
F_7 ( L_31
L_32 ) ;
if ( ! V_106 ) {
F_4 ( L_33 ) ;
return 0 ;
}
}
return V_56 ;
}
static int F_67 ( T_7 * V_108 , int V_109 , bool V_110 , bool V_111 )
{
char V_45 [ V_112 ] , V_113 [ V_84 ] ;
const char * V_114 = V_111 ? L_34 : V_115 ;
const char * V_116 = NULL ;
do {
if ( fgets ( V_45 , V_112 , V_108 ) == NULL )
goto error;
if ( V_110 )
continue;
if ( ! V_116 ) {
V_116 = V_111 ? L_35 : L_36 ;
F_68 ( stdout , V_114 , V_116 , V_109 ) ;
}
F_68 ( stdout , V_114 , L_37 , V_45 ) ;
} while ( strchr ( V_45 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_108 ) ) {
F_7 ( L_38 ,
F_44 ( V_94 , V_113 , sizeof( V_113 ) ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_69 ( T_7 * V_108 , int V_109 , bool V_110 , bool V_111 )
{
int V_117 = F_67 ( V_108 , V_109 , V_110 , V_111 ) ;
if ( V_117 == 0 ) {
F_7 ( L_39 ) ;
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
F_7 ( L_40 ) ;
return - V_63 ;
} else if ( V_4 < 0 ) {
F_7 ( L_41 ) ;
return V_4 ;
}
V_74 = V_77 -> V_82 ;
V_4 = F_72 ( V_74 , V_77 -> V_120 , & V_77 -> V_82 ) ;
if ( V_74 != V_77 -> V_82 )
free ( V_74 ) ;
if ( V_4 < 0 ) {
F_7 ( L_42 ) ;
return V_4 ;
}
F_73 () ;
if ( V_77 -> V_52 )
fprintf ( stdout , L_43 , V_77 -> V_52 , V_77 -> V_82 ,
V_77 -> V_28 - V_77 -> V_70 ) ;
else
fprintf ( stdout , L_44 , V_77 -> V_82 , V_77 -> V_28 ) ;
V_108 = fopen ( V_77 -> V_82 , L_45 ) ;
if ( V_108 == NULL ) {
F_7 ( L_46 , V_77 -> V_82 ,
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
F_4 ( L_47 , V_45 ) ;
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
F_46 ( L_48 , V_45 ) ;
V_4 = - V_63 ;
} else
F_7 ( L_41 ) ;
goto V_79;
}
fprintf ( stdout , L_49 , V_45 ) ;
for ( V_57 = 0 ; V_57 < V_4 ; V_57 ++ ) {
V_129 = & V_128 [ V_57 ] ;
fprintf ( stdout , L_50 , V_129 -> V_75 . V_14 ,
V_129 -> V_75 . V_70 ) ;
F_51 ( & V_129 -> V_75 . V_14 ) ;
V_124 = 0 ;
if ( V_129 -> V_131 ) {
F_82 (node, vl->vars) {
V_130 = strchr ( V_126 -> V_132 , '\t' ) + 1 ;
if ( F_83 ( V_123 , V_130 ) ) {
fprintf ( stdout , L_51 , V_126 -> V_132 ) ;
V_124 ++ ;
}
}
F_84 ( V_129 -> V_131 ) ;
}
if ( V_124 == 0 )
fprintf ( stdout , L_52 ) ;
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
F_7 ( L_53 ) ;
return - V_136 ;
}
return 0 ;
}
int F_79 ( struct V_76 * V_77 V_135 ,
const char * V_29 V_135 ,
bool V_39 V_135 )
{
F_7 ( L_53 ) ;
return - V_136 ;
}
int F_85 ( struct V_72 * V_133 V_135 ,
int V_134 V_135 ,
struct V_122 * T_8 V_135 )
{
F_7 ( L_53 ) ;
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
F_91 ( L_54 , V_140 ) ;
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
V_85 = F_90 ( & V_142 , & V_77 -> V_28 , L_55 ) ;
if ( V_85 )
goto V_85;
if ( * V_142 == '+' || * V_142 == '-' ) {
const char V_143 = * V_142 ++ ;
V_85 = F_90 ( & V_142 , & V_77 -> V_79 , L_56 ) ;
if ( V_85 )
goto V_85;
if ( V_143 == '+' ) {
V_77 -> V_79 += V_77 -> V_28 ;
V_77 -> V_79 -- ;
}
}
F_4 ( L_57 , V_77 -> V_28 , V_77 -> V_79 ) ;
V_85 = - V_47 ;
if ( V_77 -> V_28 > V_77 -> V_79 ) {
F_91 ( L_58
L_59 ) ;
goto V_85;
}
if ( * V_142 != '\0' ) {
F_91 ( L_60 , V_142 ) ;
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
F_91 ( L_61 , V_15 ) ;
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
V_138 = strpbrk ( V_141 , L_62 ) ;
if ( V_138 && * V_138 == '=' ) {
* V_138 = '\0' ;
V_74 = V_138 + 1 ;
if ( strchr ( V_141 , ':' ) ) {
F_91 ( L_63 ) ;
return - V_68 ;
}
if ( ! F_92 ( V_141 ) ) {
F_91 ( L_64
L_65 , V_141 ) ;
return - V_47 ;
}
V_73 -> V_146 = F_27 ( V_141 ) ;
if ( V_73 -> V_146 == NULL )
return - V_46 ;
V_73 -> V_147 = NULL ;
V_141 = V_74 ;
}
if ( ! strpbrk ( V_141 , L_66 ) && ( V_138 = strpbrk ( V_141 , L_67 ) ) != NULL ) {
if ( memchr ( V_141 , '.' , V_138 - V_141 ) )
V_145 = true ;
}
V_138 = strpbrk ( V_141 , L_68 ) ;
if ( V_138 ) {
V_144 = * V_138 ;
* V_138 ++ = '\0' ;
}
V_74 = F_27 ( V_141 ) ;
if ( V_74 == NULL )
return - V_46 ;
if ( V_145 )
V_50 -> V_51 = V_74 ;
else
V_50 -> V_52 = V_74 ;
while ( V_138 ) {
V_141 = V_138 ;
V_143 = V_144 ;
if ( V_143 == ';' ) {
V_50 -> V_53 = F_27 ( V_141 ) ;
if ( V_50 -> V_53 == NULL )
return - V_46 ;
break;
}
V_138 = strpbrk ( V_141 , L_68 ) ;
if ( V_138 ) {
V_144 = * V_138 ;
* V_138 ++ = '\0' ;
}
switch ( V_143 ) {
case ':' :
V_50 -> line = strtoul ( V_141 , & V_74 , 0 ) ;
if ( * V_74 != '\0' ) {
F_91 ( L_69
L_70 ) ;
return - V_47 ;
}
break;
case '+' :
V_50 -> V_70 = strtoul ( V_141 , & V_74 , 0 ) ;
if ( * V_74 != '\0' ) {
F_91 ( L_71
L_72 ) ;
return - V_47 ;
}
break;
case '@' :
if ( V_50 -> V_51 ) {
F_91 ( L_73 ) ;
return - V_47 ;
}
V_50 -> V_51 = F_27 ( V_141 ) ;
if ( V_50 -> V_51 == NULL )
return - V_46 ;
break;
case '%' :
if ( strcmp ( V_141 , L_74 ) == 0 ) {
V_50 -> V_71 = 1 ;
} else {
F_91 ( L_75 , V_141 ) ;
return - V_68 ;
}
break;
default:
F_46 ( L_76 ,
__FILE__ , __LINE__ ) ;
return - V_68 ;
break;
}
}
if ( V_50 -> V_53 && V_50 -> line ) {
F_91 ( L_77
L_78 ) ;
return - V_47 ;
}
if ( V_50 -> V_53 && V_50 -> V_70 ) {
F_91 ( L_79 ) ;
return - V_47 ;
}
if ( V_50 -> line && V_50 -> V_70 ) {
F_91 ( L_80 ) ;
return - V_47 ;
}
if ( ! V_50 -> line && ! V_50 -> V_53 && V_50 -> V_51 && ! V_50 -> V_52 ) {
F_91 ( L_81
L_82 ) ;
return - V_47 ;
}
if ( V_50 -> V_70 && ! V_50 -> V_52 ) {
F_91 ( L_83 ) ;
return - V_47 ;
}
if ( V_50 -> V_71 && ! V_50 -> V_52 ) {
F_91 ( L_84 ) ;
return - V_47 ;
}
if ( ( V_50 -> V_70 || V_50 -> line || V_50 -> V_53 ) && V_50 -> V_71 ) {
F_91 ( L_85
L_86 ) ;
return - V_47 ;
}
F_4 ( L_87 ,
V_50 -> V_52 , V_50 -> V_51 , V_50 -> line , V_50 -> V_70 , V_50 -> V_71 ,
V_50 -> V_53 ) ;
return 0 ;
}
static int F_95 ( char * V_1 , struct V_148 * V_141 )
{
char * V_74 , * V_149 ;
struct V_150 * * V_151 ;
F_4 ( L_88 , V_1 ) ;
V_74 = strchr ( V_1 , '=' ) ;
if ( V_74 ) {
V_141 -> V_15 = F_96 ( V_1 , V_74 - V_1 ) ;
if ( V_141 -> V_15 == NULL )
return - V_46 ;
F_4 ( L_89 , V_141 -> V_15 ) ;
V_1 = V_74 + 1 ;
}
V_74 = strchr ( V_1 , ':' ) ;
if ( V_74 ) {
* V_74 = '\0' ;
V_141 -> type = F_27 ( V_74 + 1 ) ;
if ( V_141 -> type == NULL )
return - V_46 ;
F_4 ( L_90 , V_141 -> type ) ;
}
V_74 = strpbrk ( V_1 , L_91 ) ;
if ( ! F_97 ( V_1 ) || ! V_74 ) {
V_141 -> V_130 = F_27 ( V_1 ) ;
if ( V_141 -> V_130 == NULL )
return - V_46 ;
F_4 ( L_92 , V_141 -> V_130 ) ;
return 0 ;
}
V_141 -> V_130 = F_96 ( V_1 , V_74 - V_1 ) ;
if ( V_141 -> V_130 == NULL )
return - V_46 ;
V_149 = V_141 -> V_130 ;
F_4 ( L_93 , V_141 -> V_130 ) ;
V_151 = & V_141 -> V_152 ;
do {
* V_151 = F_98 ( sizeof( struct V_150 ) ) ;
if ( * V_151 == NULL )
return - V_46 ;
if ( * V_74 == '[' ) {
V_1 = V_74 ;
( * V_151 ) -> V_153 = strtol ( V_1 + 1 , & V_74 , 0 ) ;
( * V_151 ) -> V_154 = true ;
if ( * V_74 != ']' || V_74 == V_1 + 1 ) {
F_91 ( L_94
L_95 ) ;
return - V_47 ;
}
V_74 ++ ;
if ( * V_74 == '\0' )
V_74 = NULL ;
} else {
if ( * V_74 == '.' ) {
V_1 = V_74 + 1 ;
( * V_151 ) -> V_154 = false ;
} else if ( V_74 [ 1 ] == '>' ) {
V_1 = V_74 + 2 ;
( * V_151 ) -> V_154 = true ;
} else {
F_91 ( L_96 ,
V_1 ) ;
return - V_47 ;
}
V_74 = strpbrk ( V_1 , L_91 ) ;
}
if ( V_74 ) {
( * V_151 ) -> V_15 = F_96 ( V_1 , V_74 - V_1 ) ;
if ( ( * V_151 ) -> V_15 == NULL )
return - V_46 ;
if ( * V_1 != '[' )
V_149 = ( * V_151 ) -> V_15 ;
F_4 ( L_97 , ( * V_151 ) -> V_15 , ( * V_151 ) -> V_154 ) ;
V_151 = & ( * V_151 ) -> V_155 ;
}
} while ( V_74 );
( * V_151 ) -> V_15 = F_27 ( V_1 ) ;
if ( ( * V_151 ) -> V_15 == NULL )
return - V_46 ;
if ( * V_1 != '[' )
V_149 = ( * V_151 ) -> V_15 ;
F_4 ( L_98 , ( * V_151 ) -> V_15 , ( * V_151 ) -> V_154 ) ;
if ( ! V_141 -> V_15 ) {
V_141 -> V_15 = F_27 ( V_149 ) ;
if ( V_141 -> V_15 == NULL )
return - V_46 ;
}
return 0 ;
}
int F_99 ( const char * V_156 , struct V_72 * V_73 )
{
char * * V_157 ;
int V_158 , V_57 , V_4 = 0 ;
V_157 = F_100 ( V_156 , & V_158 ) ;
if ( ! V_157 ) {
F_4 ( L_99 ) ;
return - V_46 ;
}
if ( V_158 - 1 > V_159 ) {
F_91 ( L_100 , V_158 - 1 ) ;
V_4 = - V_160 ;
goto V_11;
}
V_4 = F_94 ( V_157 [ 0 ] , V_73 ) ;
if ( V_4 < 0 )
goto V_11;
V_73 -> V_161 = V_158 - 1 ;
V_73 -> args = F_98 ( sizeof( struct V_148 ) * V_73 -> V_161 ) ;
if ( V_73 -> args == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
for ( V_57 = 0 ; V_57 < V_73 -> V_161 && V_4 >= 0 ; V_57 ++ ) {
V_4 = F_95 ( V_157 [ V_57 + 1 ] , & V_73 -> args [ V_57 ] ) ;
if ( V_4 >= 0 &&
F_97 ( V_73 -> args [ V_57 ] . V_130 ) && V_73 -> V_75 . V_71 ) {
F_91 ( L_101
L_102 ) ;
V_4 = - V_47 ;
}
}
V_11:
F_101 ( V_157 ) ;
return V_4 ;
}
bool F_64 ( struct V_72 * V_73 )
{
int V_57 ;
if ( V_73 -> V_75 . V_51 || V_73 -> V_75 . line || V_73 -> V_75 . V_53 )
return true ;
for ( V_57 = 0 ; V_57 < V_73 -> V_161 ; V_57 ++ )
if ( F_97 ( V_73 -> args [ V_57 ] . V_130 ) )
return true ;
return false ;
}
static int F_102 ( const char * V_156 ,
struct V_54 * V_162 )
{
struct V_98 * V_99 = & V_162 -> V_75 ;
char V_163 ;
char * V_164 ;
char * V_165 = NULL , * V_166 , * V_167 , * V_168 , * V_169 ;
int V_4 , V_57 , V_158 ;
char * * V_157 ;
F_4 ( L_103 , V_156 ) ;
V_157 = F_100 ( V_156 , & V_158 ) ;
if ( ! V_157 ) {
F_4 ( L_99 ) ;
return - V_46 ;
}
if ( V_158 < 2 ) {
F_91 ( L_104 ) ;
V_4 = - V_160 ;
goto V_11;
}
V_165 = F_27 ( V_157 [ 0 ] ) ;
if ( V_165 == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
V_167 = strtok_r ( V_165 , L_105 , & V_166 ) ;
V_168 = strtok_r ( NULL , L_106 , & V_166 ) ;
V_169 = strtok_r ( NULL , L_107 , & V_166 ) ;
if ( V_167 == NULL || strlen ( V_167 ) != 1 || V_168 == NULL
|| V_169 == NULL ) {
F_91 ( L_108 , V_157 [ 0 ] ) ;
V_4 = - V_47 ;
goto V_11;
}
V_163 = V_167 [ 0 ] ;
V_162 -> V_147 = F_27 ( V_168 ) ;
V_162 -> V_146 = F_27 ( V_169 ) ;
if ( V_162 -> V_147 == NULL || V_162 -> V_146 == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
F_4 ( L_109 , V_162 -> V_147 , V_162 -> V_146 , V_163 ) ;
V_99 -> V_71 = ( V_163 == 'r' ) ;
V_164 = strchr ( V_157 [ 1 ] , ':' ) ;
if ( V_164 ) {
V_99 -> V_29 = F_96 ( V_157 [ 1 ] , V_164 - V_157 [ 1 ] ) ;
V_164 ++ ;
} else
V_164 = V_157 [ 1 ] ;
V_167 = strtok_r ( V_164 , L_110 , & V_166 ) ;
if ( V_167 [ 0 ] == '0' )
V_99 -> V_58 = strtoul ( V_167 , NULL , 0 ) ;
else {
V_99 -> V_14 = F_27 ( V_167 ) ;
if ( V_99 -> V_14 == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
V_168 = strtok_r ( NULL , L_34 , & V_166 ) ;
if ( V_168 == NULL )
V_99 -> V_70 = 0 ;
else
V_99 -> V_70 = strtoul ( V_168 , NULL , 10 ) ;
}
V_162 -> V_161 = V_158 - 2 ;
V_162 -> args = F_98 ( sizeof( struct V_170 ) * V_162 -> V_161 ) ;
if ( V_162 -> args == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
for ( V_57 = 0 ; V_57 < V_162 -> V_161 ; V_57 ++ ) {
V_164 = strchr ( V_157 [ V_57 + 2 ] , '=' ) ;
if ( V_164 )
* V_164 ++ = '\0' ;
else
V_164 = V_157 [ V_57 + 2 ] ;
V_162 -> args [ V_57 ] . V_15 = F_27 ( V_157 [ V_57 + 2 ] ) ;
V_162 -> args [ V_57 ] . V_171 = F_27 ( V_164 ) ;
if ( V_162 -> args [ V_57 ] . V_15 == NULL || V_162 -> args [ V_57 ] . V_171 == NULL ) {
V_4 = - V_46 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
free ( V_165 ) ;
F_101 ( V_157 ) ;
return V_4 ;
}
int F_103 ( struct V_148 * V_172 , char * V_45 , T_1 V_78 )
{
struct V_150 * V_152 = V_172 -> V_152 ;
int V_4 ;
char * V_74 = V_45 ;
if ( V_172 -> V_15 && V_172 -> V_130 )
V_4 = F_1 ( V_74 , V_78 , L_111 , V_172 -> V_15 , V_172 -> V_130 ) ;
else
V_4 = F_1 ( V_74 , V_78 , L_37 , V_172 -> V_15 ? V_172 -> V_15 : V_172 -> V_130 ) ;
if ( V_4 <= 0 )
goto error;
V_74 += V_4 ;
V_78 -= V_4 ;
while ( V_152 ) {
if ( V_152 -> V_15 [ 0 ] == '[' )
V_4 = F_1 ( V_74 , V_78 , L_37 , V_152 -> V_15 ) ;
else
V_4 = F_1 ( V_74 , V_78 , L_112 ,
V_152 -> V_154 ? L_113 : L_114 , V_152 -> V_15 ) ;
if ( V_4 <= 0 )
goto error;
V_74 += V_4 ;
V_78 -= V_4 ;
V_152 = V_152 -> V_155 ;
}
if ( V_172 -> type ) {
V_4 = F_1 ( V_74 , V_78 , L_115 , V_172 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_74 += V_4 ;
V_78 -= V_4 ;
}
return V_74 - V_45 ;
error:
F_4 ( L_116 , V_4 ) ;
return V_4 ;
}
static char * F_66 ( struct V_49 * V_50 )
{
char * V_45 , * V_74 ;
char V_173 [ 32 ] = L_34 , line [ 32 ] = L_34 , V_51 [ 32 ] = L_34 ;
int V_4 , V_78 ;
V_45 = F_98 ( V_174 ) ;
if ( V_45 == NULL ) {
V_4 = - V_46 ;
goto error;
}
if ( V_50 -> V_70 ) {
V_4 = F_1 ( V_173 , 32 , L_117 , V_50 -> V_70 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_50 -> line ) {
V_4 = F_1 ( line , 32 , L_118 , V_50 -> line ) ;
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
V_4 = F_1 ( V_51 , 32 , L_119 , V_74 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_50 -> V_52 )
V_4 = F_1 ( V_45 , V_174 , L_120 , V_50 -> V_52 ,
V_173 , V_50 -> V_71 ? L_121 : L_34 , line ,
V_51 ) ;
else
V_4 = F_1 ( V_45 , V_174 , L_112 , V_51 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_45 ;
error:
F_4 ( L_122 , V_4 ) ;
free ( V_45 ) ;
return NULL ;
}
static int F_104 ( struct V_175 * V_154 ,
char * * V_45 , T_1 * V_176 ,
int V_177 )
{
int V_4 ;
if ( V_154 -> V_155 ) {
V_177 = F_104 ( V_154 -> V_155 , V_45 ,
V_176 , V_177 + 1 ) ;
if ( V_177 < 0 )
goto V_11;
}
V_4 = F_1 ( * V_45 , * V_176 , L_123 , V_154 -> V_70 ) ;
if ( V_4 < 0 )
V_177 = V_4 ;
else {
* V_45 += V_4 ;
* V_176 -= V_4 ;
}
V_11:
return V_177 ;
}
static int F_105 ( struct V_170 * V_141 ,
char * V_45 , T_1 V_176 )
{
struct V_175 * V_154 = V_141 -> V_154 ;
int V_4 , V_177 = 0 ;
char * V_74 = V_45 ;
if ( V_141 -> V_15 )
V_4 = F_1 ( V_45 , V_176 , L_124 , V_141 -> V_15 ) ;
else
V_4 = F_1 ( V_45 , V_176 , L_125 ) ;
if ( V_4 < 0 )
return V_4 ;
V_45 += V_4 ;
V_176 -= V_4 ;
if ( V_141 -> V_171 [ 0 ] == '@' && V_141 -> V_154 )
V_154 = V_154 -> V_155 ;
if ( V_154 ) {
V_177 = F_104 ( V_154 , & V_45 ,
& V_176 , 1 ) ;
if ( V_177 < 0 )
return V_177 ;
}
if ( V_141 -> V_171 [ 0 ] == '@' && V_141 -> V_154 )
V_4 = F_1 ( V_45 , V_176 , L_126 , V_141 -> V_171 ,
V_141 -> V_154 -> V_70 ) ;
else
V_4 = F_1 ( V_45 , V_176 , L_37 , V_141 -> V_171 ) ;
if ( V_4 < 0 )
return V_4 ;
V_45 += V_4 ;
V_176 -= V_4 ;
while ( V_177 -- ) {
V_4 = F_1 ( V_45 , V_176 , L_127 ) ;
if ( V_4 < 0 )
return V_4 ;
V_45 += V_4 ;
V_176 -= V_4 ;
}
if ( V_141 -> type ) {
V_4 = F_1 ( V_45 , V_176 , L_115 , V_141 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_45 += V_4 ;
}
return V_45 - V_74 ;
}
char * F_106 ( struct V_54 * V_162 )
{
struct V_98 * V_99 = & V_162 -> V_75 ;
char * V_45 ;
int V_57 , V_78 , V_4 ;
V_45 = F_98 ( V_174 ) ;
if ( V_45 == NULL )
return NULL ;
V_78 = F_1 ( V_45 , V_174 , L_128 , V_99 -> V_71 ? 'r' : 'p' ,
V_162 -> V_147 , V_162 -> V_146 ) ;
if ( V_78 <= 0 )
goto error;
if ( V_162 -> V_67 && ( ! V_99 -> V_58 || ! V_99 -> V_29 ) )
goto error;
if ( V_162 -> V_67 )
V_4 = F_1 ( V_45 + V_78 , V_174 - V_78 , L_129 ,
V_99 -> V_29 , V_99 -> V_58 ) ;
else
V_4 = F_1 ( V_45 + V_78 , V_174 - V_78 , L_130 ,
V_99 -> V_29 ? : L_34 , V_99 -> V_29 ? L_105 : L_34 ,
V_99 -> V_14 , V_99 -> V_70 ) ;
if ( V_4 <= 0 )
goto error;
V_78 += V_4 ;
for ( V_57 = 0 ; V_57 < V_162 -> V_161 ; V_57 ++ ) {
V_4 = F_105 ( & V_162 -> args [ V_57 ] , V_45 + V_78 ,
V_174 - V_78 ) ;
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
T_3 V_18 ;
int V_4 = - V_63 ;
if ( ! V_100 ) {
V_16 = F_23 ( V_99 -> V_29 ) ;
if ( ! V_16 )
goto V_11;
V_18 = V_99 -> V_58 ;
V_25 = F_108 ( V_16 , V_18 , NULL ) ;
} else {
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
F_4 ( L_131 ) ;
if ( V_99 -> V_14 ) {
V_50 -> V_52 = F_27 ( V_99 -> V_14 ) ;
V_50 -> V_70 = V_99 -> V_70 ;
} else if ( ! V_99 -> V_29 && ! V_100 ) {
V_4 = F_1 ( V_45 , 128 , L_132 V_69 , ( T_3 ) V_99 -> V_58 ) ;
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
static int F_110 ( struct V_54 * V_162 ,
struct V_72 * V_73 , bool V_100 )
{
char V_45 [ 64 ] = L_34 ;
int V_57 , V_4 ;
V_73 -> V_146 = F_27 ( V_162 -> V_146 ) ;
V_73 -> V_147 = F_27 ( V_162 -> V_147 ) ;
if ( V_73 -> V_146 == NULL || V_73 -> V_147 == NULL )
return - V_46 ;
V_4 = F_109 ( & V_162 -> V_75 , & V_73 -> V_75 , V_100 ) ;
if ( V_4 < 0 )
return V_4 ;
V_73 -> V_161 = V_162 -> V_161 ;
V_73 -> args = F_98 ( sizeof( struct V_148 ) * V_73 -> V_161 ) ;
if ( V_73 -> args == NULL )
return - V_46 ;
for ( V_57 = 0 ; V_57 < V_162 -> V_161 && V_4 >= 0 ; V_57 ++ ) {
if ( V_162 -> args [ V_57 ] . V_15 )
V_73 -> args [ V_57 ] . V_15 = F_27 ( V_162 -> args [ V_57 ] . V_15 ) ;
else {
V_4 = F_105 ( & V_162 -> args [ V_57 ] ,
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
struct V_150 * V_152 , * V_155 ;
int V_57 ;
free ( V_73 -> V_146 ) ;
free ( V_73 -> V_147 ) ;
free ( V_73 -> V_38 ) ;
F_29 ( & V_73 -> V_75 ) ;
for ( V_57 = 0 ; V_57 < V_73 -> V_161 ; V_57 ++ ) {
free ( V_73 -> args [ V_57 ] . V_15 ) ;
free ( V_73 -> args [ V_57 ] . V_130 ) ;
free ( V_73 -> args [ V_57 ] . type ) ;
V_152 = V_73 -> args [ V_57 ] . V_152 ;
while ( V_152 ) {
V_155 = V_152 -> V_155 ;
F_51 ( & V_152 -> V_15 ) ;
free ( V_152 ) ;
V_152 = V_155 ;
}
}
free ( V_73 -> args ) ;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
}
static void F_31 ( struct V_54 * V_162 )
{
struct V_175 * V_154 , * V_155 ;
int V_57 ;
free ( V_162 -> V_146 ) ;
free ( V_162 -> V_147 ) ;
free ( V_162 -> V_75 . V_14 ) ;
free ( V_162 -> V_75 . V_105 ) ;
free ( V_162 -> V_75 . V_29 ) ;
for ( V_57 = 0 ; V_57 < V_162 -> V_161 ; V_57 ++ ) {
free ( V_162 -> args [ V_57 ] . V_15 ) ;
free ( V_162 -> args [ V_57 ] . V_171 ) ;
free ( V_162 -> args [ V_57 ] . type ) ;
V_154 = V_162 -> args [ V_57 ] . V_154 ;
while ( V_154 ) {
V_155 = V_154 -> V_155 ;
free ( V_154 ) ;
V_154 = V_155 ;
}
}
free ( V_162 -> args ) ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
}
static void F_112 ( int V_85 , bool V_100 )
{
char V_113 [ V_84 ] ;
if ( V_85 == - V_63 ) {
const char * V_178 ;
if ( ! V_100 )
V_178 = L_133 ;
else
V_178 = L_134 ;
F_7 ( L_135
L_136 ,
V_100 ? 'k' : 'u' , V_178 ) ;
} else if ( V_85 == - V_68 )
F_7 ( L_137 ) ;
else
F_7 ( L_138 ,
V_100 ? 'k' : 'u' ,
F_44 ( - V_85 , V_113 , sizeof( V_113 ) ) ) ;
}
static void F_113 ( int V_179 , int V_180 )
{
if ( V_179 == - V_68 && V_180 == - V_68 )
F_7 ( L_137 ) ;
else if ( V_179 == - V_63 && V_180 == - V_63 )
F_7 ( L_139
L_140 ) ;
else {
char V_113 [ V_84 ] ;
F_7 ( L_141 ,
F_44 ( - V_179 , V_113 , sizeof( V_113 ) ) ) ;
F_7 ( L_142 ,
F_44 ( - V_180 , V_113 , sizeof( V_113 ) ) ) ;
}
}
static int F_114 ( const char * V_181 , bool V_182 )
{
char V_45 [ V_183 ] ;
const char * V_184 ;
const char * V_185 = L_34 ;
int V_4 ;
V_184 = F_115 () ;
if ( V_184 == NULL ) {
V_185 = L_143 ;
V_184 = F_116 () ;
if ( V_184 == NULL )
return - V_68 ;
}
V_4 = F_1 ( V_45 , V_183 , L_144 ,
V_184 , V_185 , V_181 ) ;
if ( V_4 >= 0 ) {
F_4 ( L_145 , V_45 , V_182 ) ;
if ( V_182 && ! V_186 )
V_4 = F_54 ( V_45 , V_187 | V_188 , 0 ) ;
else
V_4 = F_54 ( V_45 , V_93 , 0 ) ;
if ( V_4 < 0 )
V_4 = - V_94 ;
}
return V_4 ;
}
static int F_117 ( bool V_182 )
{
return F_114 ( L_146 , V_182 ) ;
}
static int F_118 ( bool V_182 )
{
return F_114 ( L_147 , V_182 ) ;
}
static struct V_189 * F_119 ( int V_92 )
{
int V_4 , V_190 ;
T_7 * V_108 ;
char V_45 [ V_174 ] ;
char * V_164 ;
struct V_189 * V_191 ;
V_191 = F_120 ( true , NULL ) ;
V_108 = fdopen ( F_121 ( V_92 ) , L_45 ) ;
while ( ! feof ( V_108 ) ) {
V_164 = fgets ( V_45 , V_174 , V_108 ) ;
if ( ! V_164 )
break;
V_190 = strlen ( V_164 ) - 1 ;
if ( V_164 [ V_190 ] == '\n' )
V_164 [ V_190 ] = '\0' ;
V_4 = F_122 ( V_191 , V_45 ) ;
if ( V_4 < 0 ) {
F_4 ( L_148 , V_4 ) ;
F_84 ( V_191 ) ;
return NULL ;
}
}
fclose ( V_108 ) ;
return V_191 ;
}
static void F_123 ( struct V_192 * V_193 )
{
struct V_194 * V_126 ;
while ( ! F_124 ( V_193 ) ) {
V_126 = F_125 ( V_193 ,
struct V_194 , V_195 ) ;
F_126 ( & V_126 -> V_195 ) ;
free ( V_126 -> V_14 ) ;
free ( V_126 ) ;
}
}
static int F_127 ( struct V_192 * V_193 )
{
struct V_194 * V_126 ;
const char * V_184 = F_116 () ;
char V_45 [ V_183 ] , * V_164 ;
T_7 * V_108 ;
int V_4 ;
if ( V_184 == NULL )
return - V_68 ;
V_4 = F_1 ( V_45 , V_183 , L_149 , V_184 ) ;
if ( V_4 < 0 )
return V_4 ;
V_108 = fopen ( V_45 , L_45 ) ;
if ( ! V_108 )
return - V_94 ;
V_4 = 0 ;
while ( fgets ( V_45 , V_183 , V_108 ) ) {
V_126 = F_98 ( sizeof( * V_126 ) ) ;
if ( ! V_126 ) {
V_4 = - V_46 ;
break;
}
F_128 ( & V_126 -> V_195 ) ;
F_129 ( & V_126 -> V_195 , V_193 ) ;
if ( sscanf ( V_45 , L_150 , & V_126 -> V_28 , & V_126 -> V_79 ) != 2 ) {
V_4 = - V_47 ;
break;
}
V_164 = strchr ( V_45 , '\t' ) ;
if ( V_164 ) {
V_164 ++ ;
if ( V_164 [ strlen ( V_164 ) - 1 ] == '\n' )
V_164 [ strlen ( V_164 ) - 1 ] = '\0' ;
} else
V_164 = ( char * ) L_151 ;
V_126 -> V_14 = F_27 ( V_164 ) ;
if ( ! V_126 -> V_14 ) {
V_4 = - V_46 ;
break;
}
F_130 ( L_152 ,
V_126 -> V_28 , V_126 -> V_79 , V_126 -> V_14 ) ;
V_4 ++ ;
}
if ( V_4 < 0 )
F_123 ( V_193 ) ;
fclose ( V_108 ) ;
return V_4 ;
}
static struct V_194 *
F_131 ( struct V_192 * V_193 ,
unsigned long V_58 )
{
struct V_194 * V_126 ;
F_35 (node, blacklist, list) {
if ( V_126 -> V_28 <= V_58 && V_58 <= V_126 -> V_79 )
return V_126 ;
}
return NULL ;
}
static void F_132 ( void )
{
if ( ! F_124 ( & V_196 ) )
return;
if ( F_127 ( & V_196 ) < 0 )
F_4 ( L_153 ) ;
}
static void F_133 ( void )
{
F_123 ( & V_196 ) ;
}
static bool F_33 ( unsigned long V_58 )
{
return ! ! F_131 ( & V_196 , V_58 ) ;
}
static int F_134 ( const char * V_147 , const char * V_146 ,
struct V_72 * V_73 ,
const char * V_29 ,
struct V_197 * V_41 )
{
int V_57 , V_4 ;
char V_45 [ 128 ] ;
char * V_198 ;
V_198 = F_66 ( & V_73 -> V_75 ) ;
if ( ! V_198 )
return - V_47 ;
V_4 = F_1 ( V_45 , 128 , L_154 , V_147 , V_146 ) ;
if ( V_4 < 0 )
goto V_11;
F_135 ( V_41 , L_155 , V_45 , V_198 ) ;
if ( V_29 )
F_135 ( V_41 , L_156 , V_29 ) ;
if ( V_73 -> V_161 > 0 ) {
F_136 ( V_41 , L_157 ) ;
for ( V_57 = 0 ; V_57 < V_73 -> V_161 ; V_57 ++ ) {
V_4 = F_103 ( & V_73 -> args [ V_57 ] ,
V_45 , 128 ) ;
if ( V_4 < 0 )
goto V_11;
F_135 ( V_41 , L_158 , V_45 ) ;
}
}
F_137 ( V_41 , ')' ) ;
V_11:
free ( V_198 ) ;
return V_4 ;
}
static int F_138 ( const char * V_147 , const char * V_146 ,
struct V_72 * V_73 ,
const char * V_29 , bool V_199 )
{
struct V_197 V_45 = V_200 ;
int V_4 ;
V_4 = F_134 ( V_147 , V_146 , V_73 , V_29 , & V_45 ) ;
if ( V_4 >= 0 ) {
if ( V_199 )
printf ( L_92 , V_45 . V_45 ) ;
else
F_139 ( L_92 , V_45 . V_45 ) ;
}
F_140 ( & V_45 ) ;
return V_4 ;
}
static bool F_141 ( struct V_54 * V_162 ,
struct V_122 * T_8 )
{
char V_74 [ 128 ] ;
if ( F_83 ( T_8 , V_162 -> V_146 ) )
return true ;
if ( F_1 ( V_74 , 128 , L_154 , V_162 -> V_147 , V_162 -> V_146 ) < 0 )
return false ;
return F_83 ( T_8 , V_74 ) ;
}
static int F_142 ( int V_92 , bool V_100 ,
struct V_122 * T_8 )
{
int V_4 = 0 ;
struct V_54 V_162 ;
struct V_72 V_73 ;
struct V_189 * V_201 ;
struct V_125 * V_202 ;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_201 = F_119 ( V_92 ) ;
if ( ! V_201 )
return - V_46 ;
F_82 (ent, rawlist) {
V_4 = F_102 ( V_202 -> V_132 , & V_162 ) ;
if ( V_4 >= 0 ) {
if ( ! F_141 ( & V_162 , T_8 ) )
goto V_155;
V_4 = F_110 ( & V_162 , & V_73 ,
V_100 ) ;
if ( V_4 < 0 )
goto V_155;
V_4 = F_138 ( V_73 . V_147 , V_73 . V_146 ,
& V_73 , V_162 . V_75 . V_29 ,
true ) ;
}
V_155:
F_111 ( & V_73 ) ;
F_31 ( & V_162 ) ;
if ( V_4 < 0 )
break;
}
F_84 ( V_201 ) ;
F_52 () ;
return V_4 ;
}
int F_143 ( struct V_122 * T_8 )
{
int V_203 , V_204 , V_4 ;
F_73 () ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_203 = F_117 ( false ) ;
if ( V_203 >= 0 ) {
V_4 = F_142 ( V_203 , true , T_8 ) ;
F_144 ( V_203 ) ;
if ( V_4 < 0 )
goto V_11;
}
V_204 = F_118 ( false ) ;
if ( V_203 < 0 && V_204 < 0 ) {
F_113 ( V_203 , V_204 ) ;
V_4 = V_203 ;
goto V_11;
}
if ( V_204 >= 0 ) {
V_4 = F_142 ( V_204 , false , T_8 ) ;
F_144 ( V_204 ) ;
}
V_11:
F_8 () ;
return V_4 ;
}
static struct V_189 * F_145 ( int V_92 , bool V_205 )
{
char V_45 [ 128 ] ;
struct V_189 * V_191 , * V_201 ;
struct V_125 * V_202 ;
struct V_54 V_162 ;
int V_4 = 0 ;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_201 = F_119 ( V_92 ) ;
if ( ! V_201 )
return NULL ;
V_191 = F_120 ( true , NULL ) ;
F_82 (ent, rawlist) {
V_4 = F_102 ( V_202 -> V_132 , & V_162 ) ;
if ( V_4 < 0 )
break;
if ( V_205 ) {
V_4 = F_1 ( V_45 , 128 , L_154 , V_162 . V_147 ,
V_162 . V_146 ) ;
if ( V_4 >= 0 )
V_4 = F_122 ( V_191 , V_45 ) ;
} else
V_4 = F_122 ( V_191 , V_162 . V_146 ) ;
F_31 ( & V_162 ) ;
if ( V_4 < 0 )
break;
}
F_84 ( V_201 ) ;
if ( V_4 < 0 ) {
F_84 ( V_191 ) ;
return NULL ;
}
return V_191 ;
}
static int F_146 ( int V_92 , struct V_54 * V_162 )
{
int V_4 = 0 ;
char * V_45 = F_106 ( V_162 ) ;
char V_113 [ V_84 ] ;
if ( ! V_45 ) {
F_4 ( L_159 ) ;
return - V_47 ;
}
F_4 ( L_160 , V_45 ) ;
if ( ! V_186 ) {
V_4 = F_147 ( V_92 , V_45 , strlen ( V_45 ) ) ;
if ( V_4 <= 0 ) {
V_4 = - V_94 ;
F_7 ( L_161 ,
F_44 ( V_94 , V_113 , sizeof( V_113 ) ) ) ;
}
}
free ( V_45 ) ;
return V_4 ;
}
static int F_148 ( char * V_45 , T_1 V_78 , const char * V_206 ,
struct V_189 * V_207 , bool V_208 )
{
int V_57 , V_4 ;
char * V_164 ;
if ( * V_206 == '.' )
V_206 ++ ;
V_4 = F_1 ( V_45 , V_78 , L_37 , V_206 ) ;
if ( V_4 < 0 ) {
F_4 ( L_162 , V_4 ) ;
return V_4 ;
}
V_164 = strchr ( V_45 , '.' ) ;
if ( V_164 && V_164 != V_45 )
* V_164 = '\0' ;
if ( ! F_149 ( V_207 , V_45 ) )
return 0 ;
if ( ! V_208 ) {
F_7 ( L_163
L_164 , V_206 ) ;
return - V_209 ;
}
for ( V_57 = 1 ; V_57 < V_210 ; V_57 ++ ) {
V_4 = F_1 ( V_45 , V_78 , L_165 , V_206 , V_57 ) ;
if ( V_4 < 0 ) {
F_4 ( L_162 , V_4 ) ;
return V_4 ;
}
if ( ! F_149 ( V_207 , V_45 ) )
break;
}
if ( V_57 == V_210 ) {
F_7 ( L_166 ) ;
V_4 = - V_160 ;
}
return V_4 ;
}
static void F_150 ( struct V_54 * V_162 )
{
int V_57 ;
char * V_45 = F_106 ( V_162 ) ;
if ( ! V_162 -> V_67 || V_162 -> V_161 == 0 || ! V_45 )
goto V_11;
for ( V_57 = 0 ; V_57 < V_162 -> V_161 ; V_57 ++ )
if ( F_151 ( V_162 -> args [ V_57 ] . V_171 , L_167 ) ) {
F_7 ( L_168
L_169 ,
V_162 -> args [ V_57 ] . V_171 ) ;
break;
}
V_11:
free ( V_45 ) ;
}
static int F_152 ( struct V_72 * V_73 ,
struct V_54 * V_55 ,
int V_56 , bool V_208 )
{
int V_57 , V_92 , V_4 ;
struct V_54 * V_162 = NULL ;
char V_45 [ 64 ] ;
const char * V_146 = NULL , * V_147 = NULL ;
struct V_189 * V_207 ;
bool V_211 ;
if ( V_73 -> V_67 )
V_92 = F_118 ( true ) ;
else
V_92 = F_117 ( true ) ;
if ( V_92 < 0 ) {
F_112 ( V_92 , ! V_73 -> V_67 ) ;
return V_92 ;
}
V_207 = F_145 ( V_92 , false ) ;
if ( ! V_207 ) {
F_4 ( L_170 ) ;
V_4 = - V_46 ;
goto V_212;
}
V_211 = ( V_73 -> V_75 . V_52 && ! F_153 ( V_73 -> V_75 . V_52 ) ) ;
V_4 = 0 ;
F_139 ( L_171 , ( V_56 > 1 ) ? L_172 : L_105 ) ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
V_162 = & V_55 [ V_57 ] ;
if ( ! V_162 -> V_75 . V_14 )
continue;
if ( V_73 -> V_146 )
V_146 = V_73 -> V_146 ;
else
if ( V_211 )
V_146 = V_73 -> V_75 . V_52 ;
else
V_146 = V_162 -> V_75 . V_105 ;
if ( V_73 -> V_147 )
V_147 = V_73 -> V_147 ;
else
V_147 = V_48 ;
V_4 = F_148 ( V_45 , 64 , V_146 ,
V_207 , V_208 ) ;
if ( V_4 < 0 )
break;
V_146 = V_45 ;
V_162 -> V_146 = F_27 ( V_146 ) ;
V_162 -> V_147 = F_27 ( V_147 ) ;
if ( V_162 -> V_146 == NULL || V_162 -> V_147 == NULL ) {
V_4 = - V_46 ;
break;
}
V_4 = F_146 ( V_92 , V_162 ) ;
if ( V_4 < 0 )
break;
F_122 ( V_207 , V_146 ) ;
F_138 ( V_162 -> V_147 , V_162 -> V_146 , V_73 ,
V_162 -> V_75 . V_29 , false ) ;
V_146 = V_162 -> V_146 ;
V_147 = V_162 -> V_147 ;
V_208 = true ;
}
if ( V_4 == - V_47 && V_73 -> V_67 )
F_150 ( V_162 ) ;
if ( V_4 >= 0 && V_146 ) {
F_139 ( L_173 ) ;
F_139 ( L_174 , V_147 , V_146 ) ;
}
F_84 ( V_207 ) ;
V_212:
F_144 ( V_92 ) ;
return V_4 ;
}
static int F_154 ( struct V_16 * V_16 , char * V_15 ,
struct V_14 * * V_213 )
{
int V_62 = 0 ;
struct V_14 * V_25 ;
struct V_214 * V_74 ;
if ( F_15 ( V_16 , NULL ) < 0 )
return 0 ;
F_155 (map, sym, tmp) {
if ( F_151 ( V_25 -> V_15 , V_15 ) ) {
V_62 ++ ;
if ( V_213 && V_62 < V_215 . V_216 )
V_213 [ V_62 - 1 ] = V_25 ;
}
}
return V_62 ;
}
void __weak F_156 ( struct V_72 * V_73 V_135 ,
struct V_54 * V_162 V_135 ,
struct V_16 * V_16 V_135 ) { }
static int F_157 ( struct V_72 * V_73 ,
struct V_54 * * V_55 )
{
struct V_16 * V_16 = NULL ;
struct V_19 * V_24 = NULL ;
struct V_14 * V_25 ;
struct V_14 * * V_213 = NULL ;
struct V_54 * V_162 ;
struct V_49 * V_50 = & V_73 -> V_75 ;
struct V_98 * V_99 ;
int V_217 ;
int V_4 , V_57 , V_218 , V_104 = 0 ;
V_16 = F_22 ( V_73 -> V_38 , V_73 -> V_67 ) ;
if ( ! V_16 ) {
V_4 = - V_47 ;
goto V_11;
}
V_213 = malloc ( sizeof( struct V_14 * ) * V_215 . V_216 ) ;
if ( ! V_213 ) {
V_4 = - V_46 ;
goto V_11;
}
V_217 = F_154 ( V_16 , V_50 -> V_52 , V_213 ) ;
if ( V_217 == 0 ) {
F_46 ( L_175 , V_50 -> V_52 ,
V_73 -> V_38 ? : L_5 ) ;
V_4 = - V_63 ;
goto V_11;
} else if ( V_217 > V_215 . V_216 ) {
F_46 ( L_176 ,
V_73 -> V_38 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
if ( ! V_73 -> V_67 && ! V_50 -> V_71 ) {
V_24 = F_14 () ;
if ( ! V_24 ) {
F_7 ( L_25 ) ;
V_4 = - V_47 ;
goto V_11;
}
}
* V_55 = F_98 ( sizeof( * V_162 ) * V_217 ) ;
if ( ! * V_55 ) {
V_4 = - V_46 ;
goto V_11;
}
V_4 = 0 ;
for ( V_218 = 0 ; V_218 < V_217 ; V_218 ++ ) {
V_25 = V_213 [ V_218 ] ;
V_162 = ( * V_55 ) + V_4 ;
V_99 = & V_162 -> V_75 ;
if ( V_4 == V_217 ) {
F_7 ( L_177 ) ;
break;
}
V_4 ++ ;
if ( V_50 -> V_70 > V_25 -> V_79 - V_25 -> V_28 ) {
F_7 ( L_178 ,
V_50 -> V_70 , V_25 -> V_15 ) ;
V_4 = - V_63 ;
goto V_219;
}
V_99 -> V_58 = V_16 -> V_27 ( V_16 , V_25 -> V_28 ) + V_50 -> V_70 ;
if ( ! V_73 -> V_67 &&
F_32 ( V_25 -> V_15 , V_99 -> V_58 ) ) {
V_99 -> V_14 = NULL ;
V_104 ++ ;
} else if ( V_24 ) {
V_99 -> V_14 = F_158 ( V_24 -> V_15 , V_220 ) ;
V_99 -> V_70 = V_99 -> V_58 - V_24 -> V_18 ;
} else {
V_99 -> V_14 = F_158 ( V_25 -> V_15 , V_220 ) ;
V_99 -> V_70 = V_50 -> V_70 ;
}
V_99 -> V_105 = F_158 ( V_25 -> V_15 , V_220 ) ;
V_99 -> V_71 = V_50 -> V_71 ;
if ( V_73 -> V_38 )
V_162 -> V_75 . V_29 = F_158 ( V_73 -> V_38 ,
V_220 ) ;
V_162 -> V_67 = V_73 -> V_67 ;
V_162 -> V_161 = V_73 -> V_161 ;
if ( V_162 -> V_161 ) {
V_162 -> args = F_98 ( sizeof( struct V_170 ) *
V_162 -> V_161 ) ;
if ( V_162 -> args == NULL )
goto V_220;
}
for ( V_57 = 0 ; V_57 < V_162 -> V_161 ; V_57 ++ ) {
if ( V_73 -> args [ V_57 ] . V_15 )
V_162 -> args [ V_57 ] . V_15 =
F_158 ( V_73 -> args [ V_57 ] . V_15 ,
V_220 ) ;
V_162 -> args [ V_57 ] . V_171 = F_158 ( V_73 -> args [ V_57 ] . V_130 ,
V_220 ) ;
if ( V_73 -> args [ V_57 ] . type )
V_162 -> args [ V_57 ] . type =
F_158 ( V_73 -> args [ V_57 ] . type ,
V_220 ) ;
}
F_156 ( V_73 , V_162 , V_16 ) ;
}
if ( V_4 == V_104 ) {
V_4 = - V_63 ;
goto V_219;
}
V_11:
F_24 ( V_16 , V_73 -> V_67 ) ;
free ( V_213 ) ;
return V_4 ;
V_220:
V_4 = - V_46 ;
V_219:
F_30 ( * V_55 , V_217 ) ;
F_51 ( V_55 ) ;
goto V_11;
}
bool __weak F_159 ( void ) { return false ; }
static int F_160 ( struct V_72 * V_73 ,
struct V_54 * * V_55 )
{
int V_4 ;
if ( V_73 -> V_67 && ! V_73 -> V_147 ) {
V_4 = F_26 ( V_73 -> V_38 , & V_73 -> V_147 ) ;
if ( V_4 != 0 ) {
F_7 ( L_179 ) ;
return V_4 ;
}
}
if ( F_159 () && ! F_64 ( V_73 ) ) {
V_4 = F_157 ( V_73 , V_55 ) ;
if ( V_4 > 0 )
return V_4 ;
}
V_4 = F_63 ( V_73 , V_55 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_157 ( V_73 , V_55 ) ;
}
int F_161 ( struct V_72 * V_133 , int V_134 )
{
int V_57 , V_218 , V_4 ;
struct V_221 * V_222 ;
V_4 = 0 ;
V_222 = F_98 ( sizeof( struct V_221 ) * V_134 ) ;
if ( V_222 == NULL )
return - V_46 ;
V_4 = F_2 ( V_133 -> V_67 ) ;
if ( V_4 < 0 ) {
free ( V_222 ) ;
return V_4 ;
}
for ( V_57 = 0 ; V_57 < V_134 ; V_57 ++ ) {
V_222 [ V_57 ] . V_73 = & V_133 [ V_57 ] ;
if ( ! V_222 [ V_57 ] . V_73 -> V_67 )
F_132 () ;
V_4 = F_160 ( V_222 [ V_57 ] . V_73 ,
& V_222 [ V_57 ] . V_55 ) ;
if ( V_4 < 0 )
goto V_79;
V_222 [ V_57 ] . V_56 = V_4 ;
}
F_133 () ;
for ( V_57 = 0 ; V_57 < V_134 ; V_57 ++ ) {
V_4 = F_152 ( V_222 [ V_57 ] . V_73 , V_222 [ V_57 ] . V_55 ,
V_222 [ V_57 ] . V_56 ,
V_215 . V_223 ) ;
if ( V_4 < 0 )
break;
}
V_79:
for ( V_57 = 0 ; V_57 < V_134 ; V_57 ++ ) {
for ( V_218 = 0 ; V_218 < V_222 [ V_57 ] . V_56 ; V_218 ++ )
F_31 ( & V_222 [ V_57 ] . V_55 [ V_218 ] ) ;
F_51 ( & V_222 [ V_57 ] . V_55 ) ;
}
free ( V_222 ) ;
F_8 () ;
return V_4 ;
}
static int F_162 ( int V_92 , struct V_125 * V_202 )
{
char * V_164 ;
char V_45 [ 128 ] ;
int V_4 ;
V_4 = F_1 ( V_45 , 128 , L_180 , V_202 -> V_132 ) ;
if ( V_4 < 0 )
goto error;
V_164 = strchr ( V_45 + 2 , ':' ) ;
if ( ! V_164 ) {
F_4 ( L_181 ,
V_202 -> V_132 ) ;
V_4 = - V_68 ;
goto error;
}
* V_164 = '/' ;
F_4 ( L_160 , V_45 ) ;
V_4 = F_147 ( V_92 , V_45 , strlen ( V_45 ) ) ;
if ( V_4 < 0 ) {
V_4 = - V_94 ;
goto error;
}
F_139 ( L_182 , V_202 -> V_132 ) ;
return 0 ;
error:
F_7 ( L_183 ,
F_44 ( - V_4 , V_45 , sizeof( V_45 ) ) ) ;
return V_4 ;
}
static int F_163 ( int V_92 , struct V_122 * T_8 ,
struct V_189 * V_207 )
{
struct V_125 * V_202 ;
const char * V_164 ;
int V_4 = - V_63 ;
if ( ! V_207 )
return - V_63 ;
F_82 (ent, namelist) {
V_164 = strchr ( V_202 -> V_132 , ':' ) ;
if ( ( V_164 && F_83 ( T_8 , V_164 + 1 ) ) ||
F_83 ( T_8 , V_202 -> V_132 ) ) {
V_4 = F_162 ( V_92 , V_202 ) ;
if ( V_4 < 0 )
break;
}
}
return V_4 ;
}
int F_164 ( struct V_122 * T_8 )
{
int V_4 , V_224 , V_225 = - 1 , V_226 = - 1 ;
struct V_189 * V_207 = NULL , * V_227 = NULL ;
char * V_1 = F_165 ( T_8 ) ;
if ( ! V_1 )
return - V_47 ;
F_4 ( L_184 , V_1 ) ;
V_226 = F_117 ( true ) ;
if ( V_226 >= 0 )
V_207 = F_145 ( V_226 , true ) ;
V_225 = F_118 ( true ) ;
if ( V_225 >= 0 )
V_227 = F_145 ( V_225 , true ) ;
if ( V_226 < 0 && V_225 < 0 ) {
F_113 ( V_226 , V_225 ) ;
V_4 = V_226 ;
goto error;
}
V_4 = F_163 ( V_226 , T_8 , V_207 ) ;
if ( V_4 < 0 && V_4 != - V_63 )
goto error;
V_224 = F_163 ( V_225 , T_8 , V_227 ) ;
if ( V_224 < 0 && V_224 != - V_63 ) {
V_4 = V_224 ;
goto error;
}
if ( V_4 == - V_63 && V_224 == - V_63 )
F_4 ( L_185 , V_1 ) ;
V_4 = 0 ;
error:
if ( V_226 >= 0 ) {
F_84 ( V_207 ) ;
F_144 ( V_226 ) ;
}
if ( V_225 >= 0 ) {
F_84 ( V_227 ) ;
F_144 ( V_225 ) ;
}
free ( V_1 ) ;
return V_4 ;
}
static int F_166 ( struct V_16 * V_16 V_135 ,
struct V_14 * V_25 )
{
if ( F_83 ( V_228 , V_25 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_167 ( const char * V_38 , struct V_122 * V_123 ,
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
F_46 ( L_186 , ( V_38 ) ? : L_5 ) ;
return - V_47 ;
}
V_228 = V_123 ;
if ( F_15 ( V_16 , F_166 ) ) {
F_46 ( L_187 , ( V_38 ) ? : L_5 ) ;
goto V_79;
}
if ( ! F_168 ( V_16 -> V_35 , V_16 -> type ) )
F_169 ( V_16 -> V_35 , V_16 -> type ) ;
F_73 () ;
F_170 ( V_16 -> V_35 , V_16 -> type , stdout ) ;
V_79:
if ( V_39 ) {
F_25 ( V_16 ) ;
}
F_8 () ;
return V_4 ;
}
