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
struct V_30 * V_31 ;
struct V_32 * V_33 = & V_12 -> V_34 ;
if ( V_29 && strchr ( V_29 , '/' ) )
return F_19 ( V_12 , 0 , V_29 ) ;
if ( ! V_29 )
V_29 = L_5 ;
for ( V_31 = F_20 ( & V_33 -> V_35 [ V_22 ] ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_16 * V_36 = F_22 ( V_31 , struct V_16 , V_30 ) ;
if ( strncmp ( V_36 -> V_37 -> V_38 + 1 , V_29 ,
V_36 -> V_37 -> V_39 - 2 ) == 0 ) {
return V_36 ;
}
}
return NULL ;
}
static struct V_16 * F_23 ( const char * V_40 , bool V_41 )
{
if ( V_41 )
return F_24 ( V_40 ) ;
else
return F_18 ( V_40 ) ;
}
static void F_25 ( struct V_16 * V_16 , bool V_41 )
{
if ( V_16 && V_41 ) {
F_26 ( V_16 -> V_37 ) ;
F_27 ( V_16 ) ;
}
}
static struct V_37 * F_28 ( const char * V_29 )
{
struct V_37 * V_37 ;
struct V_16 * V_16 ;
const char * V_13 ;
if ( V_29 ) {
F_29 (dso, &host_machine->kernel_dsos.head,
node) {
if ( strncmp ( V_37 -> V_38 + 1 , V_29 ,
V_37 -> V_39 - 2 ) == 0 )
goto V_42;
}
F_4 ( L_6 , V_29 ) ;
return NULL ;
}
V_16 = V_12 -> V_21 [ V_22 ] ;
V_37 = V_16 -> V_37 ;
V_13 = V_8 . V_13 ;
if ( V_13 ) {
if ( F_30 ( V_37 , V_16 , V_13 , false , NULL ) <= 0 )
return NULL ;
} else {
if ( F_31 ( V_37 , V_16 , NULL ) <= 0 ) {
F_4 ( L_7 ) ;
return NULL ;
}
}
V_42:
return V_37 ;
}
const char * F_32 ( const char * V_29 )
{
struct V_37 * V_37 = F_28 ( V_29 ) ;
return ( V_37 ) ? V_37 -> V_43 : NULL ;
}
static int F_33 ( const char * V_44 , char * * V_45 )
{
char * V_46 , * V_47 , * V_48 ;
char V_49 [ 64 ] ;
int V_4 ;
V_48 = F_34 ( V_44 ) ;
if ( ! V_48 )
return - V_50 ;
V_46 = F_35 ( V_48 ) ;
if ( ! V_46 ) {
V_4 = - V_51 ;
goto V_11;
}
V_47 = strpbrk ( V_46 , L_8 ) ;
if ( V_47 )
* V_47 = '\0' ;
V_4 = F_1 ( V_49 , 64 , L_9 , V_52 , V_46 ) ;
if ( V_4 < 0 )
goto V_11;
* V_45 = F_34 ( V_49 ) ;
V_4 = * V_45 ? 0 : - V_50 ;
V_11:
free ( V_48 ) ;
return V_4 ;
}
static void F_36 ( struct V_53 * V_54 )
{
free ( V_54 -> V_55 ) ;
free ( V_54 -> V_56 ) ;
free ( V_54 -> V_57 ) ;
}
static void F_37 ( struct V_58 * V_59 , int V_60 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ )
F_38 ( V_59 + V_61 ) ;
}
static int F_39 ( struct V_62 * V_63 ,
struct V_53 * V_54 ,
struct V_53 * V_45 ,
const char * V_40 , bool V_64 )
{
struct V_16 * V_16 = NULL ;
struct V_14 * V_25 ;
T_3 V_65 = 0 ;
int V_4 = - V_66 ;
if ( ! V_54 -> V_56 || V_54 -> V_55 )
return - V_67 ;
V_16 = F_23 ( V_40 , V_64 ) ;
if ( ! V_16 )
return - V_51 ;
F_40 (map, pp->function, sym) {
if ( V_64 )
V_65 = V_25 -> V_28 ;
else
V_65 = V_16 -> V_27 ( V_16 , V_25 -> V_28 ) ;
break;
}
if ( ! V_65 ) {
V_4 = - V_66 ;
goto V_11;
}
F_4 ( L_10 V_68 L_11 ,
V_54 -> V_56 , V_65 ) ;
V_4 = F_41 ( V_63 , ( unsigned long ) V_65 ,
V_45 ) ;
if ( V_4 <= 0 )
V_4 = ( ! V_4 ) ? - V_66 : V_4 ;
else {
V_45 -> V_69 += V_54 -> V_69 ;
V_45 -> line += V_54 -> line ;
V_45 -> V_70 = V_54 -> V_70 ;
V_4 = 0 ;
}
V_11:
F_25 ( V_16 , V_64 ) ;
return V_4 ;
}
static int F_42 ( struct V_62 * V_63 ,
struct V_71 * V_72 ,
struct V_53 * V_73 ,
const char * V_40 )
{
int V_4 ;
memcpy ( V_73 , & V_72 -> V_74 , sizeof( * V_73 ) ) ;
memset ( & V_72 -> V_74 , 0 , sizeof( V_72 -> V_74 ) ) ;
V_4 = F_39 ( V_63 , V_73 , & V_72 -> V_74 ,
V_40 , V_72 -> V_64 ) ;
if ( V_4 < 0 )
memcpy ( & V_72 -> V_74 , V_73 , sizeof( * V_73 ) ) ;
return V_4 ;
}
static int F_43 ( struct V_62 * V_63 ,
struct V_75 * V_76 ,
const char * V_40 , bool V_41 )
{
struct V_53 V_54 = { . V_56 = V_76 -> V_56 ,
. V_55 = V_76 -> V_55 ,
. line = V_76 -> V_28 } ;
struct V_53 V_45 ;
int V_4 , V_77 = 0 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
if ( V_76 -> V_78 != V_79 )
V_77 = V_76 -> V_78 - V_76 -> V_28 ;
V_4 = F_39 ( V_63 , & V_54 , & V_45 ,
V_40 , V_41 ) ;
if ( ! V_4 ) {
V_76 -> V_56 = V_45 . V_56 ;
V_76 -> V_55 = V_45 . V_55 ;
V_76 -> V_28 = V_45 . line ;
if ( V_76 -> V_78 != V_79 )
V_76 -> V_78 = V_76 -> V_28 + V_77 ;
F_36 ( & V_54 ) ;
}
return V_4 ;
}
static struct V_62 * F_44 ( const char * V_29 , bool V_80 )
{
const char * V_81 = V_29 ;
struct V_62 * V_4 ;
if ( ! V_29 || ! strchr ( V_29 , '/' ) ) {
V_81 = F_32 ( V_29 ) ;
if ( ! V_81 ) {
if ( ! V_80 )
F_45 ( L_12 ,
V_29 ? : L_5 ) ;
return NULL ;
}
}
V_4 = F_46 ( V_81 ) ;
if ( ! V_4 && ! V_80 ) {
F_7 ( L_13 , V_81 ) ;
if ( ! V_29 || ! F_47 ( V_81 , L_14 ) )
F_7 ( L_15 ) ;
else
F_7 ( L_16 ) ;
F_7 ( L_17 ) ;
}
return V_4 ;
}
static int F_48 ( const char * V_44 , unsigned long * V_65 )
{
T_4 * V_82 ;
T_5 V_83 ;
T_6 V_84 ;
int V_85 , V_4 = - V_66 ;
V_85 = F_49 ( V_44 , V_86 ) ;
if ( V_85 < 0 )
return - V_87 ;
V_82 = F_50 ( V_85 , V_88 , NULL ) ;
if ( V_82 == NULL )
return - V_51 ;
if ( F_51 ( V_82 , & V_83 ) == NULL )
goto V_11;
if ( ! F_52 ( V_82 , & V_83 , & V_84 , L_18 , NULL ) )
goto V_11;
* V_65 = V_84 . V_89 - V_84 . V_90 ;
V_4 = 0 ;
V_11:
F_53 ( V_82 ) ;
return V_4 ;
}
static int F_54 ( struct V_91 * V_92 ,
struct V_53 * V_54 ,
bool V_93 )
{
struct V_62 * V_63 = NULL ;
unsigned long V_94 = 0 ;
T_3 V_18 = V_92 -> V_65 ;
int V_4 = - V_66 ;
if ( ! V_93 ) {
if ( ! V_18 ) {
V_4 = - V_51 ;
goto error;
}
V_4 = F_48 ( V_92 -> V_29 , & V_94 ) ;
if ( V_4 < 0 )
goto error;
V_18 += V_94 ;
} else {
V_18 = F_17 ( V_92 -> V_14 , false ) ;
if ( V_18 == 0 )
goto error;
V_18 += V_92 -> V_69 ;
}
F_4 ( L_19 V_68 L_20 , V_18 ,
V_92 -> V_29 ? : L_5 ) ;
V_63 = F_44 ( V_92 -> V_29 , V_95 == 0 ) ;
if ( V_63 ) {
V_4 = F_41 ( V_63 ,
( unsigned long ) V_18 , V_54 ) ;
F_55 ( V_63 ) ;
} else
V_4 = - V_66 ;
if ( V_4 > 0 ) {
V_54 -> V_70 = V_92 -> V_70 ;
return 0 ;
}
error:
F_4 ( L_21 ) ;
return V_4 ? : - V_66 ;
}
static int F_56 ( struct V_58 * V_59 ,
int V_60 , const char * V_44 )
{
int V_61 , V_4 = 0 ;
unsigned long V_94 = 0 ;
if ( ! V_44 )
return 0 ;
V_4 = F_48 ( V_44 , & V_94 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_61 = 0 ; V_61 < V_60 && V_4 >= 0 ; V_61 ++ ) {
V_59 [ V_61 ] . V_74 . V_65 -= V_94 ;
V_59 [ V_61 ] . V_74 . V_29 = F_34 ( V_44 ) ;
if ( ! V_59 [ V_61 ] . V_74 . V_29 ) {
V_4 = - V_50 ;
break;
}
V_59 [ V_61 ] . V_64 = true ;
}
return V_4 ;
}
static int F_57 ( struct V_58 * V_59 ,
int V_60 , const char * V_29 )
{
int V_61 , V_4 = 0 ;
char * V_73 ;
if ( ! V_29 )
return 0 ;
V_73 = strrchr ( V_29 , '/' ) ;
if ( V_73 ) {
V_29 = F_34 ( V_73 + 1 ) ;
if ( ! V_29 )
return - V_50 ;
V_73 = strchr ( V_29 , '.' ) ;
if ( V_73 )
* V_73 = '\0' ;
V_73 = ( char * ) V_29 ;
}
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
V_59 [ V_61 ] . V_74 . V_29 = F_34 ( V_29 ) ;
if ( ! V_59 [ V_61 ] . V_74 . V_29 ) {
V_4 = - V_50 ;
break;
}
}
free ( V_73 ) ;
return V_4 ;
}
static int F_58 ( struct V_58 * V_59 ,
int V_60 , const char * V_29 ,
bool V_96 )
{
struct V_19 * V_24 ;
char * V_73 ;
int V_61 ;
if ( V_96 )
return F_56 ( V_59 , V_60 , V_29 ) ;
if ( V_29 )
return F_57 ( V_59 , V_60 , V_29 ) ;
V_24 = F_14 () ;
if ( ! V_24 ) {
F_7 ( L_22 ) ;
return - V_51 ;
}
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
if ( V_59 [ V_61 ] . V_74 . V_65 && ! V_59 [ V_61 ] . V_74 . V_70 ) {
V_73 = F_34 ( V_24 -> V_15 ) ;
if ( ! V_73 )
return - V_50 ;
free ( V_59 [ V_61 ] . V_74 . V_14 ) ;
V_59 [ V_61 ] . V_74 . V_14 = V_73 ;
V_59 [ V_61 ] . V_74 . V_69 = V_59 [ V_61 ] . V_74 . V_65 -
V_24 -> V_26 ;
}
}
return 0 ;
}
static int F_59 ( struct V_71 * V_72 ,
struct V_58 * * V_59 ,
int V_97 , const char * V_40 )
{
bool V_98 = F_60 ( V_72 ) ;
struct V_53 V_73 ;
struct V_62 * V_63 ;
int V_60 , V_4 = 0 ;
V_63 = F_44 ( V_40 , ! V_98 ) ;
if ( ! V_63 ) {
if ( V_98 )
return - V_66 ;
F_4 ( L_23 ) ;
return 0 ;
}
F_4 ( L_24 ) ;
V_60 = F_61 ( V_63 , V_72 , V_59 , V_97 ) ;
if ( V_60 == 0 ) {
V_4 = F_42 ( V_63 , V_72 , & V_73 , V_40 ) ;
if ( ! V_4 ) {
V_60 = F_61 ( V_63 , V_72 ,
V_59 , V_97 ) ;
F_36 ( & V_72 -> V_74 ) ;
memcpy ( & V_72 -> V_74 , & V_73 , sizeof( V_73 ) ) ;
}
}
F_55 ( V_63 ) ;
if ( V_60 > 0 ) {
F_4 ( L_25 , V_60 ) ;
V_4 = F_58 ( * V_59 , V_60 ,
V_40 , V_72 -> V_64 ) ;
if ( V_4 < 0 ) {
F_37 ( * V_59 , V_60 ) ;
F_62 ( V_59 ) ;
}
return V_4 < 0 ? V_4 : V_60 ;
}
if ( V_60 == 0 ) {
F_7 ( L_26 ,
F_63 ( & V_72 -> V_74 ) ) ;
return - V_66 ;
}
F_4 ( L_27 , V_60 ) ;
if ( V_60 == - V_99 ) {
F_7 ( L_28
L_29 ) ;
if ( ! V_98 ) {
F_4 ( L_30 ) ;
return 0 ;
}
}
return V_60 ;
}
static int F_64 ( T_7 * V_100 , int V_101 , bool V_102 , bool V_103 )
{
char V_49 [ V_104 ] , V_105 [ V_106 ] ;
const char * V_107 = V_103 ? L_31 : V_108 ;
const char * V_109 = NULL ;
do {
if ( fgets ( V_49 , V_104 , V_100 ) == NULL )
goto error;
if ( V_102 )
continue;
if ( ! V_109 ) {
V_109 = V_103 ? L_32 : L_33 ;
F_65 ( stdout , V_107 , V_109 , V_101 ) ;
}
F_65 ( stdout , V_107 , L_34 , V_49 ) ;
} while ( strchr ( V_49 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_100 ) ) {
F_7 ( L_35 ,
F_66 ( V_87 , V_105 , sizeof( V_105 ) ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_67 ( T_7 * V_100 , int V_101 , bool V_102 , bool V_103 )
{
int V_110 = F_64 ( V_100 , V_101 , V_102 , V_103 ) ;
if ( V_110 == 0 ) {
F_7 ( L_36 ) ;
V_110 = - 1 ;
}
return V_110 ;
}
static int F_68 ( struct V_75 * V_76 , const char * V_29 ,
bool V_41 )
{
int V_101 = 1 ;
struct V_111 * V_112 ;
struct V_62 * V_63 ;
T_7 * V_100 ;
int V_4 ;
char * V_73 ;
char V_105 [ V_106 ] ;
V_63 = F_44 ( V_29 , false ) ;
if ( ! V_63 )
return - V_66 ;
V_4 = F_69 ( V_63 , V_76 ) ;
if ( ! V_4 ) {
V_4 = F_43 ( V_63 , V_76 , V_29 , V_41 ) ;
if ( ! V_4 )
V_4 = F_69 ( V_63 , V_76 ) ;
}
F_55 ( V_63 ) ;
if ( V_4 == 0 || V_4 == - V_66 ) {
F_7 ( L_37 ) ;
return - V_66 ;
} else if ( V_4 < 0 ) {
F_7 ( L_38 ) ;
return V_4 ;
}
V_73 = V_76 -> V_81 ;
V_4 = F_70 ( V_73 , V_76 -> V_113 , & V_76 -> V_81 ) ;
if ( V_73 != V_76 -> V_81 )
free ( V_73 ) ;
if ( V_4 < 0 ) {
F_7 ( L_39 ) ;
return V_4 ;
}
F_71 () ;
if ( V_76 -> V_56 )
fprintf ( stdout , L_40 , V_76 -> V_56 , V_76 -> V_81 ,
V_76 -> V_28 - V_76 -> V_69 ) ;
else
fprintf ( stdout , L_41 , V_76 -> V_81 , V_76 -> V_28 ) ;
V_100 = fopen ( V_76 -> V_81 , L_42 ) ;
if ( V_100 == NULL ) {
F_7 ( L_43 , V_76 -> V_81 ,
F_66 ( V_87 , V_105 , sizeof( V_105 ) ) ) ;
return - V_87 ;
}
while ( V_101 < V_76 -> V_28 ) {
V_4 = F_72 ( V_100 , V_101 ++ ) ;
if ( V_4 < 0 )
goto V_78;
}
F_73 (ln, lr->line_list) {
for (; V_112 -> V_61 > V_101 ; V_101 ++ ) {
V_4 = F_74 ( V_100 , V_101 - V_76 -> V_69 ) ;
if ( V_4 < 0 )
goto V_78;
}
V_4 = F_75 ( V_100 , V_101 ++ - V_76 -> V_69 ) ;
if ( V_4 < 0 )
goto V_78;
}
if ( V_76 -> V_78 == V_79 )
V_76 -> V_78 = V_101 + V_114 ;
while ( V_101 <= V_76 -> V_78 ) {
V_4 = F_76 ( V_100 , V_101 ++ - V_76 -> V_69 ) ;
if ( V_4 <= 0 )
break;
}
V_78:
fclose ( V_100 ) ;
return V_4 ;
}
int F_77 ( struct V_75 * V_76 , const char * V_29 , bool V_41 )
{
int V_4 ;
V_4 = F_2 ( V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_68 ( V_76 , V_29 , V_41 ) ;
F_8 () ;
return V_4 ;
}
static int F_78 ( struct V_62 * V_63 ,
struct V_71 * V_72 ,
int V_115 , struct V_116 * V_117 ,
bool V_118 , const char * V_40 )
{
char * V_49 ;
int V_4 , V_61 , V_119 ;
struct V_120 * V_121 ;
struct V_122 * V_123 = NULL , * V_124 ;
struct V_53 V_73 ;
const char * V_125 ;
V_49 = F_63 ( & V_72 -> V_74 ) ;
if ( ! V_49 )
return - V_51 ;
F_4 ( L_44 , V_49 ) ;
V_4 = F_79 ( V_63 , V_72 , & V_123 ,
V_115 , V_118 ) ;
if ( ! V_4 ) {
V_4 = F_42 ( V_63 , V_72 , & V_73 , V_40 ) ;
if ( ! V_4 ) {
V_4 = F_79 ( V_63 , V_72 ,
& V_123 , V_115 , V_118 ) ;
F_36 ( & V_73 ) ;
}
}
if ( V_4 <= 0 ) {
if ( V_4 == 0 || V_4 == - V_66 ) {
F_45 ( L_45 , V_49 ) ;
V_4 = - V_66 ;
} else
F_7 ( L_38 ) ;
goto V_78;
}
fprintf ( stdout , L_46 , V_49 ) ;
for ( V_61 = 0 ; V_61 < V_4 ; V_61 ++ ) {
V_124 = & V_123 [ V_61 ] ;
fprintf ( stdout , L_47 , V_124 -> V_74 . V_14 ,
V_124 -> V_74 . V_69 ) ;
F_62 ( & V_124 -> V_74 . V_14 ) ;
V_119 = 0 ;
if ( V_124 -> V_126 ) {
F_80 (node, vl->vars) {
V_125 = strchr ( V_121 -> V_127 , '\t' ) + 1 ;
if ( F_81 ( V_117 , V_125 ) ) {
fprintf ( stdout , L_48 , V_121 -> V_127 ) ;
V_119 ++ ;
}
}
F_82 ( V_124 -> V_126 ) ;
}
if ( V_119 == 0 )
fprintf ( stdout , L_49 ) ;
}
free ( V_123 ) ;
V_78:
free ( V_49 ) ;
return V_4 ;
}
int F_83 ( struct V_71 * V_128 , int V_129 ,
int V_115 , const char * V_29 ,
struct V_116 * V_117 , bool V_118 )
{
int V_61 , V_4 = 0 ;
struct V_62 * V_63 ;
V_4 = F_2 ( V_128 -> V_64 ) ;
if ( V_4 < 0 )
return V_4 ;
V_63 = F_44 ( V_29 , false ) ;
if ( ! V_63 ) {
V_4 = - V_66 ;
goto V_11;
}
F_71 () ;
for ( V_61 = 0 ; V_61 < V_129 && V_4 >= 0 ; V_61 ++ )
V_4 = F_78 ( V_63 , & V_128 [ V_61 ] , V_115 , V_117 ,
V_118 , V_29 ) ;
F_55 ( V_63 ) ;
V_11:
F_8 () ;
return V_4 ;
}
static int
F_54 ( struct V_91 * V_92 V_130 ,
struct V_53 * V_54 V_130 ,
bool V_93 V_130 )
{
return - V_131 ;
}
static int F_59 ( struct V_71 * V_72 ,
struct V_58 * * V_59 V_130 ,
int V_97 V_130 ,
const char * V_40 V_130 )
{
if ( F_60 ( V_72 ) ) {
F_7 ( L_50 ) ;
return - V_131 ;
}
return 0 ;
}
int F_77 ( struct V_75 * V_76 V_130 ,
const char * V_29 V_130 ,
bool V_41 V_130 )
{
F_7 ( L_50 ) ;
return - V_131 ;
}
int F_83 ( struct V_71 * V_128 V_130 ,
int V_129 V_130 , int V_115 V_130 ,
const char * V_29 V_130 ,
struct V_116 * T_8 V_130 ,
bool V_118 V_130 )
{
F_7 ( L_50 ) ;
return - V_131 ;
}
void F_84 ( struct V_75 * V_76 )
{
free ( V_76 -> V_56 ) ;
free ( V_76 -> V_55 ) ;
free ( V_76 -> V_81 ) ;
free ( V_76 -> V_113 ) ;
F_85 ( V_76 -> V_132 ) ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
}
int F_86 ( struct V_75 * V_76 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_132 = F_87 ( NULL ) ;
if ( ! V_76 -> V_132 )
return - V_50 ;
else
return 0 ;
}
static int F_88 ( char * * V_133 , int * V_134 , const char * V_135 )
{
const char * V_28 = * V_133 ;
V_87 = 0 ;
* V_134 = strtol ( * V_133 , V_133 , 0 ) ;
if ( V_87 || * V_133 == V_28 ) {
F_89 ( L_51 , V_135 ) ;
return - V_51 ;
}
return 0 ;
}
int F_90 ( const char * V_136 , struct V_75 * V_76 )
{
char * V_137 , * V_55 , * V_15 = F_34 ( V_136 ) ;
int V_138 ;
if ( ! V_15 )
return - V_50 ;
V_76 -> V_28 = 0 ;
V_76 -> V_78 = V_79 ;
V_137 = strchr ( V_15 , ':' ) ;
if ( V_137 ) {
* V_137 ++ = '\0' ;
V_138 = F_88 ( & V_137 , & V_76 -> V_28 , L_52 ) ;
if ( V_138 )
goto V_138;
if ( * V_137 == '+' || * V_137 == '-' ) {
const char V_139 = * V_137 ++ ;
V_138 = F_88 ( & V_137 , & V_76 -> V_78 , L_53 ) ;
if ( V_138 )
goto V_138;
if ( V_139 == '+' ) {
V_76 -> V_78 += V_76 -> V_28 ;
V_76 -> V_78 -- ;
}
}
F_4 ( L_54 , V_76 -> V_28 , V_76 -> V_78 ) ;
V_138 = - V_51 ;
if ( V_76 -> V_28 > V_76 -> V_78 ) {
F_89 ( L_55
L_56 ) ;
goto V_138;
}
if ( * V_137 != '\0' ) {
F_89 ( L_57 , V_137 ) ;
goto V_138;
}
}
V_55 = strchr ( V_15 , '@' ) ;
if ( V_55 ) {
* V_55 = '\0' ;
V_76 -> V_55 = F_34 ( ++ V_55 ) ;
if ( V_76 -> V_55 == NULL ) {
V_138 = - V_50 ;
goto V_138;
}
V_76 -> V_56 = V_15 ;
} else if ( strchr ( V_15 , '.' ) )
V_76 -> V_55 = V_15 ;
else
V_76 -> V_56 = V_15 ;
return 0 ;
V_138:
free ( V_15 ) ;
return V_138 ;
}
static bool F_91 ( const char * V_15 )
{
if ( ! isalpha ( * V_15 ) && * V_15 != '_' )
return false ;
while ( * ++ V_15 != '\0' ) {
if ( ! isalpha ( * V_15 ) && ! isdigit ( * V_15 ) && * V_15 != '_' )
return false ;
}
return true ;
}
static int F_92 ( char * V_136 , struct V_71 * V_72 )
{
struct V_53 * V_54 = & V_72 -> V_74 ;
char * V_133 , * V_73 ;
char V_139 , V_140 = 0 ;
if ( ! V_136 )
return - V_51 ;
V_133 = strpbrk ( V_136 , L_58 ) ;
if ( V_133 && * V_133 == '=' ) {
* V_133 = '\0' ;
V_73 = V_133 + 1 ;
if ( strchr ( V_136 , ':' ) ) {
F_89 ( L_59 ) ;
return - V_67 ;
}
if ( ! F_91 ( V_136 ) ) {
F_89 ( L_60
L_61 , V_136 ) ;
return - V_51 ;
}
V_72 -> V_141 = F_34 ( V_136 ) ;
if ( V_72 -> V_141 == NULL )
return - V_50 ;
V_72 -> V_142 = NULL ;
V_136 = V_73 ;
}
V_133 = strpbrk ( V_136 , L_62 ) ;
if ( V_133 ) {
V_140 = * V_133 ;
* V_133 ++ = '\0' ;
}
V_73 = F_34 ( V_136 ) ;
if ( V_73 == NULL )
return - V_50 ;
if ( strchr ( V_73 , '.' ) )
V_54 -> V_55 = V_73 ;
else
V_54 -> V_56 = V_73 ;
while ( V_133 ) {
V_136 = V_133 ;
V_139 = V_140 ;
if ( V_139 == ';' ) {
V_54 -> V_57 = F_34 ( V_136 ) ;
if ( V_54 -> V_57 == NULL )
return - V_50 ;
break;
}
V_133 = strpbrk ( V_136 , L_62 ) ;
if ( V_133 ) {
V_140 = * V_133 ;
* V_133 ++ = '\0' ;
}
switch ( V_139 ) {
case ':' :
V_54 -> line = strtoul ( V_136 , & V_73 , 0 ) ;
if ( * V_73 != '\0' ) {
F_89 ( L_63
L_64 ) ;
return - V_51 ;
}
break;
case '+' :
V_54 -> V_69 = strtoul ( V_136 , & V_73 , 0 ) ;
if ( * V_73 != '\0' ) {
F_89 ( L_65
L_66 ) ;
return - V_51 ;
}
break;
case '@' :
if ( V_54 -> V_55 ) {
F_89 ( L_67 ) ;
return - V_51 ;
}
V_54 -> V_55 = F_34 ( V_136 ) ;
if ( V_54 -> V_55 == NULL )
return - V_50 ;
break;
case '%' :
if ( strcmp ( V_136 , L_68 ) == 0 ) {
V_54 -> V_70 = 1 ;
} else {
F_89 ( L_69 , V_136 ) ;
return - V_67 ;
}
break;
default:
F_45 ( L_70 ,
__FILE__ , __LINE__ ) ;
return - V_67 ;
break;
}
}
if ( V_54 -> V_57 && V_54 -> line ) {
F_89 ( L_71
L_72 ) ;
return - V_51 ;
}
if ( V_54 -> V_57 && V_54 -> V_69 ) {
F_89 ( L_73 ) ;
return - V_51 ;
}
if ( V_54 -> line && V_54 -> V_69 ) {
F_89 ( L_74 ) ;
return - V_51 ;
}
if ( ! V_54 -> line && ! V_54 -> V_57 && V_54 -> V_55 && ! V_54 -> V_56 ) {
F_89 ( L_75
L_76 ) ;
return - V_51 ;
}
if ( V_54 -> V_69 && ! V_54 -> V_56 ) {
F_89 ( L_77 ) ;
return - V_51 ;
}
if ( V_54 -> V_70 && ! V_54 -> V_56 ) {
F_89 ( L_78 ) ;
return - V_51 ;
}
if ( ( V_54 -> V_69 || V_54 -> line || V_54 -> V_57 ) && V_54 -> V_70 ) {
F_89 ( L_79
L_80 ) ;
return - V_51 ;
}
F_4 ( L_81 ,
V_54 -> V_56 , V_54 -> V_55 , V_54 -> line , V_54 -> V_69 , V_54 -> V_70 ,
V_54 -> V_57 ) ;
return 0 ;
}
static int F_93 ( char * V_1 , struct V_143 * V_136 )
{
char * V_73 , * V_144 ;
struct V_145 * * V_146 ;
F_4 ( L_82 , V_1 ) ;
V_73 = strchr ( V_1 , '=' ) ;
if ( V_73 ) {
V_136 -> V_15 = F_94 ( V_1 , V_73 - V_1 ) ;
if ( V_136 -> V_15 == NULL )
return - V_50 ;
F_4 ( L_83 , V_136 -> V_15 ) ;
V_1 = V_73 + 1 ;
}
V_73 = strchr ( V_1 , ':' ) ;
if ( V_73 ) {
* V_73 = '\0' ;
V_136 -> type = F_34 ( V_73 + 1 ) ;
if ( V_136 -> type == NULL )
return - V_50 ;
F_4 ( L_84 , V_136 -> type ) ;
}
V_73 = strpbrk ( V_1 , L_85 ) ;
if ( ! F_95 ( V_1 ) || ! V_73 ) {
V_136 -> V_125 = F_34 ( V_1 ) ;
if ( V_136 -> V_125 == NULL )
return - V_50 ;
F_4 ( L_86 , V_136 -> V_125 ) ;
return 0 ;
}
V_136 -> V_125 = F_94 ( V_1 , V_73 - V_1 ) ;
if ( V_136 -> V_125 == NULL )
return - V_50 ;
V_144 = V_136 -> V_125 ;
F_4 ( L_87 , V_136 -> V_125 ) ;
V_146 = & V_136 -> V_147 ;
do {
* V_146 = F_96 ( sizeof( struct V_145 ) ) ;
if ( * V_146 == NULL )
return - V_50 ;
if ( * V_73 == '[' ) {
V_1 = V_73 ;
( * V_146 ) -> V_148 = strtol ( V_1 + 1 , & V_73 , 0 ) ;
( * V_146 ) -> V_149 = true ;
if ( * V_73 != ']' || V_73 == V_1 + 1 ) {
F_89 ( L_88
L_89 ) ;
return - V_51 ;
}
V_73 ++ ;
if ( * V_73 == '\0' )
V_73 = NULL ;
} else {
if ( * V_73 == '.' ) {
V_1 = V_73 + 1 ;
( * V_146 ) -> V_149 = false ;
} else if ( V_73 [ 1 ] == '>' ) {
V_1 = V_73 + 2 ;
( * V_146 ) -> V_149 = true ;
} else {
F_89 ( L_90 ,
V_1 ) ;
return - V_51 ;
}
V_73 = strpbrk ( V_1 , L_85 ) ;
}
if ( V_73 ) {
( * V_146 ) -> V_15 = F_94 ( V_1 , V_73 - V_1 ) ;
if ( ( * V_146 ) -> V_15 == NULL )
return - V_50 ;
if ( * V_1 != '[' )
V_144 = ( * V_146 ) -> V_15 ;
F_4 ( L_91 , ( * V_146 ) -> V_15 , ( * V_146 ) -> V_149 ) ;
V_146 = & ( * V_146 ) -> V_150 ;
}
} while ( V_73 );
( * V_146 ) -> V_15 = F_34 ( V_1 ) ;
if ( ( * V_146 ) -> V_15 == NULL )
return - V_50 ;
if ( * V_1 != '[' )
V_144 = ( * V_146 ) -> V_15 ;
F_4 ( L_92 , ( * V_146 ) -> V_15 , ( * V_146 ) -> V_149 ) ;
if ( ! V_136 -> V_15 ) {
V_136 -> V_15 = F_34 ( V_144 ) ;
if ( V_136 -> V_15 == NULL )
return - V_50 ;
}
return 0 ;
}
int F_97 ( const char * V_151 , struct V_71 * V_72 )
{
char * * V_152 ;
int V_153 , V_61 , V_4 = 0 ;
V_152 = F_98 ( V_151 , & V_153 ) ;
if ( ! V_152 ) {
F_4 ( L_93 ) ;
return - V_50 ;
}
if ( V_153 - 1 > V_154 ) {
F_89 ( L_94 , V_153 - 1 ) ;
V_4 = - V_155 ;
goto V_11;
}
V_4 = F_92 ( V_152 [ 0 ] , V_72 ) ;
if ( V_4 < 0 )
goto V_11;
V_72 -> V_156 = V_153 - 1 ;
V_72 -> args = F_96 ( sizeof( struct V_143 ) * V_72 -> V_156 ) ;
if ( V_72 -> args == NULL ) {
V_4 = - V_50 ;
goto V_11;
}
for ( V_61 = 0 ; V_61 < V_72 -> V_156 && V_4 >= 0 ; V_61 ++ ) {
V_4 = F_93 ( V_152 [ V_61 + 1 ] , & V_72 -> args [ V_61 ] ) ;
if ( V_4 >= 0 &&
F_95 ( V_72 -> args [ V_61 ] . V_125 ) && V_72 -> V_74 . V_70 ) {
F_89 ( L_95
L_96 ) ;
V_4 = - V_51 ;
}
}
V_11:
F_99 ( V_152 ) ;
return V_4 ;
}
bool F_60 ( struct V_71 * V_72 )
{
int V_61 ;
if ( V_72 -> V_74 . V_55 || V_72 -> V_74 . line || V_72 -> V_74 . V_57 )
return true ;
for ( V_61 = 0 ; V_61 < V_72 -> V_156 ; V_61 ++ )
if ( F_95 ( V_72 -> args [ V_61 ] . V_125 ) )
return true ;
return false ;
}
static int F_100 ( const char * V_151 ,
struct V_58 * V_157 )
{
struct V_91 * V_92 = & V_157 -> V_74 ;
char V_158 ;
char * V_159 ;
char * V_160 = NULL , * V_161 , * V_162 , * V_163 , * V_164 ;
int V_4 , V_61 , V_153 ;
char * * V_152 ;
F_4 ( L_97 , V_151 ) ;
V_152 = F_98 ( V_151 , & V_153 ) ;
if ( ! V_152 ) {
F_4 ( L_93 ) ;
return - V_50 ;
}
if ( V_153 < 2 ) {
F_89 ( L_98 ) ;
V_4 = - V_155 ;
goto V_11;
}
V_160 = F_34 ( V_152 [ 0 ] ) ;
if ( V_160 == NULL ) {
V_4 = - V_50 ;
goto V_11;
}
V_162 = strtok_r ( V_160 , L_99 , & V_161 ) ;
V_163 = strtok_r ( NULL , L_100 , & V_161 ) ;
V_164 = strtok_r ( NULL , L_101 , & V_161 ) ;
if ( V_162 == NULL || strlen ( V_162 ) != 1 || V_163 == NULL
|| V_164 == NULL ) {
F_89 ( L_102 , V_152 [ 0 ] ) ;
V_4 = - V_51 ;
goto V_11;
}
V_158 = V_162 [ 0 ] ;
V_157 -> V_142 = F_34 ( V_163 ) ;
V_157 -> V_141 = F_34 ( V_164 ) ;
if ( V_157 -> V_142 == NULL || V_157 -> V_141 == NULL ) {
V_4 = - V_50 ;
goto V_11;
}
F_4 ( L_103 , V_157 -> V_142 , V_157 -> V_141 , V_158 ) ;
V_92 -> V_70 = ( V_158 == 'r' ) ;
V_159 = strchr ( V_152 [ 1 ] , ':' ) ;
if ( V_159 ) {
V_92 -> V_29 = F_94 ( V_152 [ 1 ] , V_159 - V_152 [ 1 ] ) ;
V_159 ++ ;
} else
V_159 = V_152 [ 1 ] ;
V_162 = strtok_r ( V_159 , L_104 , & V_161 ) ;
if ( V_162 [ 0 ] == '0' )
V_92 -> V_65 = strtoul ( V_162 , NULL , 0 ) ;
else {
V_92 -> V_14 = F_34 ( V_162 ) ;
if ( V_92 -> V_14 == NULL ) {
V_4 = - V_50 ;
goto V_11;
}
V_163 = strtok_r ( NULL , L_31 , & V_161 ) ;
if ( V_163 == NULL )
V_92 -> V_69 = 0 ;
else
V_92 -> V_69 = strtoul ( V_163 , NULL , 10 ) ;
}
V_157 -> V_156 = V_153 - 2 ;
V_157 -> args = F_96 ( sizeof( struct V_165 ) * V_157 -> V_156 ) ;
if ( V_157 -> args == NULL ) {
V_4 = - V_50 ;
goto V_11;
}
for ( V_61 = 0 ; V_61 < V_157 -> V_156 ; V_61 ++ ) {
V_159 = strchr ( V_152 [ V_61 + 2 ] , '=' ) ;
if ( V_159 )
* V_159 ++ = '\0' ;
else
V_159 = V_152 [ V_61 + 2 ] ;
V_157 -> args [ V_61 ] . V_15 = F_34 ( V_152 [ V_61 + 2 ] ) ;
V_157 -> args [ V_61 ] . V_166 = F_34 ( V_159 ) ;
if ( V_157 -> args [ V_61 ] . V_15 == NULL || V_157 -> args [ V_61 ] . V_166 == NULL ) {
V_4 = - V_50 ;
goto V_11;
}
}
V_4 = 0 ;
V_11:
free ( V_160 ) ;
F_99 ( V_152 ) ;
return V_4 ;
}
int F_101 ( struct V_143 * V_167 , char * V_49 , T_1 V_77 )
{
struct V_145 * V_147 = V_167 -> V_147 ;
int V_4 ;
char * V_73 = V_49 ;
if ( V_167 -> V_15 && V_167 -> V_125 )
V_4 = F_1 ( V_73 , V_77 , L_105 , V_167 -> V_15 , V_167 -> V_125 ) ;
else
V_4 = F_1 ( V_73 , V_77 , L_34 , V_167 -> V_15 ? V_167 -> V_15 : V_167 -> V_125 ) ;
if ( V_4 <= 0 )
goto error;
V_73 += V_4 ;
V_77 -= V_4 ;
while ( V_147 ) {
if ( V_147 -> V_15 [ 0 ] == '[' )
V_4 = F_1 ( V_73 , V_77 , L_34 , V_147 -> V_15 ) ;
else
V_4 = F_1 ( V_73 , V_77 , L_106 ,
V_147 -> V_149 ? L_107 : L_108 , V_147 -> V_15 ) ;
if ( V_4 <= 0 )
goto error;
V_73 += V_4 ;
V_77 -= V_4 ;
V_147 = V_147 -> V_150 ;
}
if ( V_167 -> type ) {
V_4 = F_1 ( V_73 , V_77 , L_109 , V_167 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_73 += V_4 ;
V_77 -= V_4 ;
}
return V_73 - V_49 ;
error:
F_4 ( L_110 , V_4 ) ;
return V_4 ;
}
static char * F_63 ( struct V_53 * V_54 )
{
char * V_49 , * V_73 ;
char V_168 [ 32 ] = L_31 , line [ 32 ] = L_31 , V_55 [ 32 ] = L_31 ;
int V_4 , V_77 ;
V_49 = F_96 ( V_169 ) ;
if ( V_49 == NULL ) {
V_4 = - V_50 ;
goto error;
}
if ( V_54 -> V_69 ) {
V_4 = F_1 ( V_168 , 32 , L_111 , V_54 -> V_69 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_54 -> line ) {
V_4 = F_1 ( line , 32 , L_112 , V_54 -> line ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_54 -> V_55 ) {
V_73 = V_54 -> V_55 ;
V_77 = strlen ( V_73 ) ;
if ( V_77 > 30 ) {
V_73 = strchr ( V_54 -> V_55 + V_77 - 30 , '/' ) ;
V_73 = V_73 ? V_73 + 1 : V_54 -> V_55 + V_77 - 30 ;
}
V_4 = F_1 ( V_55 , 32 , L_113 , V_73 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_54 -> V_56 )
V_4 = F_1 ( V_49 , V_169 , L_114 , V_54 -> V_56 ,
V_168 , V_54 -> V_70 ? L_115 : L_31 , line ,
V_55 ) ;
else
V_4 = F_1 ( V_49 , V_169 , L_106 , V_55 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_49 ;
error:
F_4 ( L_116 , V_4 ) ;
free ( V_49 ) ;
return NULL ;
}
static int F_102 ( struct V_170 * V_149 ,
char * * V_49 , T_1 * V_171 ,
int V_172 )
{
int V_4 ;
if ( V_149 -> V_150 ) {
V_172 = F_102 ( V_149 -> V_150 , V_49 ,
V_171 , V_172 + 1 ) ;
if ( V_172 < 0 )
goto V_11;
}
V_4 = F_1 ( * V_49 , * V_171 , L_117 , V_149 -> V_69 ) ;
if ( V_4 < 0 )
V_172 = V_4 ;
else {
* V_49 += V_4 ;
* V_171 -= V_4 ;
}
V_11:
return V_172 ;
}
static int F_103 ( struct V_165 * V_136 ,
char * V_49 , T_1 V_171 )
{
struct V_170 * V_149 = V_136 -> V_149 ;
int V_4 , V_172 = 0 ;
char * V_73 = V_49 ;
if ( V_136 -> V_15 )
V_4 = F_1 ( V_49 , V_171 , L_118 , V_136 -> V_15 ) ;
else
V_4 = F_1 ( V_49 , V_171 , L_119 ) ;
if ( V_4 < 0 )
return V_4 ;
V_49 += V_4 ;
V_171 -= V_4 ;
if ( V_136 -> V_166 [ 0 ] == '@' && V_136 -> V_149 )
V_149 = V_149 -> V_150 ;
if ( V_149 ) {
V_172 = F_102 ( V_149 , & V_49 ,
& V_171 , 1 ) ;
if ( V_172 < 0 )
return V_172 ;
}
if ( V_136 -> V_166 [ 0 ] == '@' && V_136 -> V_149 )
V_4 = F_1 ( V_49 , V_171 , L_120 , V_136 -> V_166 ,
V_136 -> V_149 -> V_69 ) ;
else
V_4 = F_1 ( V_49 , V_171 , L_34 , V_136 -> V_166 ) ;
if ( V_4 < 0 )
return V_4 ;
V_49 += V_4 ;
V_171 -= V_4 ;
while ( V_172 -- ) {
V_4 = F_1 ( V_49 , V_171 , L_121 ) ;
if ( V_4 < 0 )
return V_4 ;
V_49 += V_4 ;
V_171 -= V_4 ;
}
if ( V_136 -> type ) {
V_4 = F_1 ( V_49 , V_171 , L_109 , V_136 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_49 += V_4 ;
}
return V_49 - V_73 ;
}
char * F_104 ( struct V_58 * V_157 )
{
struct V_91 * V_92 = & V_157 -> V_74 ;
char * V_49 ;
int V_61 , V_77 , V_4 ;
V_49 = F_96 ( V_169 ) ;
if ( V_49 == NULL )
return NULL ;
V_77 = F_1 ( V_49 , V_169 , L_122 , V_92 -> V_70 ? 'r' : 'p' ,
V_157 -> V_142 , V_157 -> V_141 ) ;
if ( V_77 <= 0 )
goto error;
if ( V_157 -> V_64 && ( ! V_92 -> V_65 || ! V_92 -> V_29 ) )
goto error;
if ( V_157 -> V_64 )
V_4 = F_1 ( V_49 + V_77 , V_169 - V_77 , L_123 ,
V_92 -> V_29 , V_92 -> V_65 ) ;
else
V_4 = F_1 ( V_49 + V_77 , V_169 - V_77 , L_124 ,
V_92 -> V_29 ? : L_31 , V_92 -> V_29 ? L_99 : L_31 ,
V_92 -> V_14 , V_92 -> V_69 ) ;
if ( V_4 <= 0 )
goto error;
V_77 += V_4 ;
for ( V_61 = 0 ; V_61 < V_157 -> V_156 ; V_61 ++ ) {
V_4 = F_103 ( & V_157 -> args [ V_61 ] , V_49 + V_77 ,
V_169 - V_77 ) ;
if ( V_4 <= 0 )
goto error;
V_77 += V_4 ;
}
return V_49 ;
error:
free ( V_49 ) ;
return NULL ;
}
static int F_105 ( struct V_91 * V_92 ,
struct V_53 * V_54 ,
bool V_93 )
{
struct V_14 * V_25 = NULL ;
struct V_16 * V_16 ;
T_3 V_18 ;
int V_4 = - V_66 ;
if ( ! V_93 ) {
V_16 = F_24 ( V_92 -> V_29 ) ;
if ( ! V_16 )
goto V_11;
V_18 = V_92 -> V_65 ;
V_25 = F_106 ( V_16 , V_18 , NULL ) ;
} else {
V_18 = F_17 ( V_92 -> V_14 , true ) ;
if ( V_18 ) {
V_18 += V_92 -> V_69 ;
V_25 = F_12 ( V_18 , & V_16 ) ;
}
}
if ( ! V_25 )
goto V_11;
V_54 -> V_70 = V_92 -> V_70 ;
V_54 -> V_69 = V_18 - V_16 -> V_27 ( V_16 , V_25 -> V_28 ) ;
V_54 -> V_56 = F_34 ( V_25 -> V_15 ) ;
V_4 = V_54 -> V_56 ? 0 : - V_50 ;
V_11:
if ( V_16 && ! V_93 ) {
F_26 ( V_16 -> V_37 ) ;
F_27 ( V_16 ) ;
}
return V_4 ;
}
static int F_107 ( struct V_91 * V_92 ,
struct V_53 * V_54 ,
bool V_93 )
{
char V_49 [ 128 ] ;
int V_4 ;
V_4 = F_54 ( V_92 , V_54 , V_93 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_105 ( V_92 , V_54 , V_93 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( L_125 ) ;
if ( V_92 -> V_14 ) {
V_54 -> V_56 = F_34 ( V_92 -> V_14 ) ;
V_54 -> V_69 = V_92 -> V_69 ;
} else if ( ! V_92 -> V_29 && ! V_93 ) {
V_4 = F_1 ( V_49 , 128 , L_126 V_68 , ( T_3 ) V_92 -> V_65 ) ;
if ( V_4 < 0 )
return V_4 ;
V_54 -> V_56 = F_34 ( V_49 ) ;
V_54 -> V_69 = 0 ;
}
if ( V_54 -> V_56 == NULL )
return - V_50 ;
V_54 -> V_70 = V_92 -> V_70 ;
return 0 ;
}
static int F_108 ( struct V_58 * V_157 ,
struct V_71 * V_72 , bool V_93 )
{
char V_49 [ 64 ] = L_31 ;
int V_61 , V_4 ;
V_72 -> V_141 = F_34 ( V_157 -> V_141 ) ;
V_72 -> V_142 = F_34 ( V_157 -> V_142 ) ;
if ( V_72 -> V_141 == NULL || V_72 -> V_142 == NULL )
return - V_50 ;
V_4 = F_107 ( & V_157 -> V_74 , & V_72 -> V_74 , V_93 ) ;
if ( V_4 < 0 )
return V_4 ;
V_72 -> V_156 = V_157 -> V_156 ;
V_72 -> args = F_96 ( sizeof( struct V_143 ) * V_72 -> V_156 ) ;
if ( V_72 -> args == NULL )
return - V_50 ;
for ( V_61 = 0 ; V_61 < V_157 -> V_156 && V_4 >= 0 ; V_61 ++ ) {
if ( V_157 -> args [ V_61 ] . V_15 )
V_72 -> args [ V_61 ] . V_15 = F_34 ( V_157 -> args [ V_61 ] . V_15 ) ;
else {
V_4 = F_103 ( & V_157 -> args [ V_61 ] ,
V_49 , 64 ) ;
V_72 -> args [ V_61 ] . V_15 = F_34 ( V_49 ) ;
}
if ( V_72 -> args [ V_61 ] . V_15 == NULL && V_4 >= 0 )
V_4 = - V_50 ;
}
if ( V_4 < 0 )
F_109 ( V_72 ) ;
return V_4 ;
}
void F_109 ( struct V_71 * V_72 )
{
struct V_145 * V_147 , * V_150 ;
int V_61 ;
free ( V_72 -> V_141 ) ;
free ( V_72 -> V_142 ) ;
free ( V_72 -> V_40 ) ;
F_36 ( & V_72 -> V_74 ) ;
for ( V_61 = 0 ; V_61 < V_72 -> V_156 ; V_61 ++ ) {
free ( V_72 -> args [ V_61 ] . V_15 ) ;
free ( V_72 -> args [ V_61 ] . V_125 ) ;
free ( V_72 -> args [ V_61 ] . type ) ;
V_147 = V_72 -> args [ V_61 ] . V_147 ;
while ( V_147 ) {
V_150 = V_147 -> V_150 ;
F_62 ( & V_147 -> V_15 ) ;
free ( V_147 ) ;
V_147 = V_150 ;
}
}
free ( V_72 -> args ) ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
}
static void F_38 ( struct V_58 * V_157 )
{
struct V_170 * V_149 , * V_150 ;
int V_61 ;
free ( V_157 -> V_141 ) ;
free ( V_157 -> V_142 ) ;
free ( V_157 -> V_74 . V_14 ) ;
free ( V_157 -> V_74 . V_29 ) ;
for ( V_61 = 0 ; V_61 < V_157 -> V_156 ; V_61 ++ ) {
free ( V_157 -> args [ V_61 ] . V_15 ) ;
free ( V_157 -> args [ V_61 ] . V_166 ) ;
free ( V_157 -> args [ V_61 ] . type ) ;
V_149 = V_157 -> args [ V_61 ] . V_149 ;
while ( V_149 ) {
V_150 = V_149 -> V_150 ;
free ( V_149 ) ;
V_149 = V_150 ;
}
}
free ( V_157 -> args ) ;
memset ( V_157 , 0 , sizeof( * V_157 ) ) ;
}
static void F_110 ( int V_138 , bool V_93 )
{
char V_105 [ V_106 ] ;
if ( V_138 == - V_66 ) {
const char * V_173 ;
if ( ! V_93 )
V_173 = L_127 ;
else
V_173 = L_128 ;
F_7 ( L_129
L_130 ,
V_93 ? 'k' : 'u' , V_173 ) ;
} else if ( V_138 == - V_67 )
F_7 ( L_131 ) ;
else
F_7 ( L_132 ,
V_93 ? 'k' : 'u' ,
F_66 ( - V_138 , V_105 , sizeof( V_105 ) ) ) ;
}
static void F_111 ( int V_174 , int V_175 )
{
if ( V_174 == - V_67 && V_175 == - V_67 )
F_7 ( L_131 ) ;
else if ( V_174 == - V_66 && V_175 == - V_66 )
F_7 ( L_133
L_134 ) ;
else {
char V_105 [ V_106 ] ;
F_7 ( L_135 ,
F_66 ( - V_174 , V_105 , sizeof( V_105 ) ) ) ;
F_7 ( L_136 ,
F_66 ( - V_175 , V_105 , sizeof( V_105 ) ) ) ;
}
}
static int F_112 ( const char * V_176 , bool V_177 )
{
char V_49 [ V_178 ] ;
const char * V_179 ;
const char * V_180 = L_31 ;
int V_4 ;
V_179 = F_113 () ;
if ( V_179 == NULL ) {
V_180 = L_137 ;
V_179 = F_114 () ;
if ( V_179 == NULL )
return - V_67 ;
}
V_4 = F_1 ( V_49 , V_178 , L_138 ,
V_179 , V_180 , V_176 ) ;
if ( V_4 >= 0 ) {
F_4 ( L_139 , V_49 , V_177 ) ;
if ( V_177 && ! V_181 )
V_4 = F_49 ( V_49 , V_182 , V_183 ) ;
else
V_4 = F_49 ( V_49 , V_86 , 0 ) ;
if ( V_4 < 0 )
V_4 = - V_87 ;
}
return V_4 ;
}
static int F_115 ( bool V_177 )
{
return F_112 ( L_140 , V_177 ) ;
}
static int F_116 ( bool V_177 )
{
return F_112 ( L_141 , V_177 ) ;
}
static struct V_184 * F_117 ( int V_85 )
{
int V_4 , V_185 ;
T_7 * V_100 ;
char V_49 [ V_169 ] ;
char * V_159 ;
struct V_184 * V_186 ;
V_186 = F_118 ( true , NULL ) ;
V_100 = fdopen ( F_119 ( V_85 ) , L_42 ) ;
while ( ! feof ( V_100 ) ) {
V_159 = fgets ( V_49 , V_169 , V_100 ) ;
if ( ! V_159 )
break;
V_185 = strlen ( V_159 ) - 1 ;
if ( V_159 [ V_185 ] == '\n' )
V_159 [ V_185 ] = '\0' ;
V_4 = F_120 ( V_186 , V_49 ) ;
if ( V_4 < 0 ) {
F_4 ( L_142 , V_4 ) ;
F_82 ( V_186 ) ;
return NULL ;
}
}
fclose ( V_100 ) ;
return V_186 ;
}
static void F_121 ( struct V_187 * V_188 )
{
struct V_189 * V_121 ;
while ( ! F_122 ( V_188 ) ) {
V_121 = F_123 ( V_188 ,
struct V_189 , V_190 ) ;
F_124 ( & V_121 -> V_190 ) ;
free ( V_121 -> V_14 ) ;
free ( V_121 ) ;
}
}
static int F_125 ( struct V_187 * V_188 )
{
struct V_189 * V_121 ;
const char * V_179 = F_114 () ;
char V_49 [ V_178 ] , * V_159 ;
T_7 * V_100 ;
int V_4 ;
if ( V_179 == NULL )
return - V_67 ;
V_4 = F_1 ( V_49 , V_178 , L_143 , V_179 ) ;
if ( V_4 < 0 )
return V_4 ;
V_100 = fopen ( V_49 , L_42 ) ;
if ( ! V_100 )
return - V_87 ;
V_4 = 0 ;
while ( fgets ( V_49 , V_178 , V_100 ) ) {
V_121 = F_96 ( sizeof( * V_121 ) ) ;
if ( ! V_121 ) {
V_4 = - V_50 ;
break;
}
F_126 ( & V_121 -> V_190 ) ;
F_127 ( & V_121 -> V_190 , V_188 ) ;
if ( sscanf ( V_49 , L_144 , & V_121 -> V_28 , & V_121 -> V_78 ) != 2 ) {
V_4 = - V_51 ;
break;
}
V_159 = strchr ( V_49 , '\t' ) ;
if ( V_159 ) {
V_159 ++ ;
if ( V_159 [ strlen ( V_159 ) - 1 ] == '\n' )
V_159 [ strlen ( V_159 ) - 1 ] = '\0' ;
} else
V_159 = ( char * ) L_145 ;
V_121 -> V_14 = F_34 ( V_159 ) ;
if ( ! V_121 -> V_14 ) {
V_4 = - V_50 ;
break;
}
F_128 ( L_146 ,
V_121 -> V_28 , V_121 -> V_78 , V_121 -> V_14 ) ;
V_4 ++ ;
}
if ( V_4 < 0 )
F_121 ( V_188 ) ;
fclose ( V_100 ) ;
return V_4 ;
}
static struct V_189 *
F_129 ( struct V_187 * V_188 ,
unsigned long V_65 )
{
struct V_189 * V_121 ;
F_29 (node, blacklist, list) {
if ( V_121 -> V_28 <= V_65 && V_65 <= V_121 -> V_78 )
return V_121 ;
}
return NULL ;
}
static int F_130 ( struct V_71 * V_72 ,
const char * V_29 )
{
int V_61 , V_4 ;
char V_49 [ 128 ] ;
char * V_191 ;
V_191 = F_63 ( & V_72 -> V_74 ) ;
if ( ! V_191 )
return - V_51 ;
V_4 = F_1 ( V_49 , 128 , L_147 , V_72 -> V_142 , V_72 -> V_141 ) ;
if ( V_4 < 0 )
return V_4 ;
F_131 ( L_148 , V_49 , V_191 ) ;
if ( V_29 )
F_131 ( L_149 , V_29 ) ;
if ( V_72 -> V_156 > 0 ) {
F_131 ( L_150 ) ;
for ( V_61 = 0 ; V_61 < V_72 -> V_156 ; V_61 ++ ) {
V_4 = F_101 ( & V_72 -> args [ V_61 ] ,
V_49 , 128 ) ;
if ( V_4 < 0 )
break;
F_131 ( L_151 , V_49 ) ;
}
}
F_131 ( L_152 ) ;
free ( V_191 ) ;
return V_4 ;
}
static int F_132 ( int V_85 , bool V_93 )
{
int V_4 = 0 ;
struct V_58 V_157 ;
struct V_71 V_72 ;
struct V_184 * V_192 ;
struct V_120 * V_193 ;
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_192 = F_117 ( V_85 ) ;
if ( ! V_192 )
return - V_50 ;
F_80 (ent, rawlist) {
V_4 = F_100 ( V_193 -> V_127 , & V_157 ) ;
if ( V_4 >= 0 ) {
V_4 = F_108 ( & V_157 , & V_72 ,
V_93 ) ;
if ( V_4 >= 0 )
V_4 = F_130 ( & V_72 ,
V_157 . V_74 . V_29 ) ;
}
F_109 ( & V_72 ) ;
F_38 ( & V_157 ) ;
if ( V_4 < 0 )
break;
}
F_82 ( V_192 ) ;
return V_4 ;
}
int F_133 ( void )
{
int V_194 , V_195 , V_4 ;
F_71 () ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_194 = F_115 ( false ) ;
if ( V_194 >= 0 ) {
V_4 = F_132 ( V_194 , true ) ;
F_134 ( V_194 ) ;
if ( V_4 < 0 )
goto V_11;
}
V_195 = F_116 ( false ) ;
if ( V_194 < 0 && V_195 < 0 ) {
F_111 ( V_194 , V_195 ) ;
V_4 = V_194 ;
goto V_11;
}
if ( V_195 >= 0 ) {
V_4 = F_132 ( V_195 , false ) ;
F_134 ( V_195 ) ;
}
V_11:
F_8 () ;
return V_4 ;
}
static struct V_184 * F_135 ( int V_85 , bool V_196 )
{
char V_49 [ 128 ] ;
struct V_184 * V_186 , * V_192 ;
struct V_120 * V_193 ;
struct V_58 V_157 ;
int V_4 = 0 ;
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
V_192 = F_117 ( V_85 ) ;
if ( ! V_192 )
return NULL ;
V_186 = F_118 ( true , NULL ) ;
F_80 (ent, rawlist) {
V_4 = F_100 ( V_193 -> V_127 , & V_157 ) ;
if ( V_4 < 0 )
break;
if ( V_196 ) {
V_4 = F_1 ( V_49 , 128 , L_147 , V_157 . V_142 ,
V_157 . V_141 ) ;
if ( V_4 >= 0 )
V_4 = F_120 ( V_186 , V_49 ) ;
} else
V_4 = F_120 ( V_186 , V_157 . V_141 ) ;
F_38 ( & V_157 ) ;
if ( V_4 < 0 )
break;
}
F_82 ( V_192 ) ;
if ( V_4 < 0 ) {
F_82 ( V_186 ) ;
return NULL ;
}
return V_186 ;
}
static int F_136 ( int V_85 , struct V_58 * V_157 )
{
int V_4 = 0 ;
char * V_49 = F_104 ( V_157 ) ;
char V_105 [ V_106 ] ;
if ( ! V_49 ) {
F_4 ( L_153 ) ;
return - V_51 ;
}
F_4 ( L_154 , V_49 ) ;
if ( ! V_181 ) {
V_4 = F_137 ( V_85 , V_49 , strlen ( V_49 ) ) ;
if ( V_4 <= 0 ) {
V_4 = - V_87 ;
F_7 ( L_155 ,
F_66 ( V_87 , V_105 , sizeof( V_105 ) ) ) ;
}
}
free ( V_49 ) ;
return V_4 ;
}
static int F_138 ( char * V_49 , T_1 V_77 , const char * V_197 ,
struct V_184 * V_198 , bool V_199 )
{
int V_61 , V_4 ;
V_4 = F_1 ( V_49 , V_77 , L_34 , V_197 ) ;
if ( V_4 < 0 ) {
F_4 ( L_156 , V_4 ) ;
return V_4 ;
}
if ( ! F_139 ( V_198 , V_49 ) )
return 0 ;
if ( ! V_199 ) {
F_7 ( L_157
L_158 , V_197 ) ;
return - V_200 ;
}
for ( V_61 = 1 ; V_61 < V_201 ; V_61 ++ ) {
V_4 = F_1 ( V_49 , V_77 , L_159 , V_197 , V_61 ) ;
if ( V_4 < 0 ) {
F_4 ( L_156 , V_4 ) ;
return V_4 ;
}
if ( ! F_139 ( V_198 , V_49 ) )
break;
}
if ( V_61 == V_201 ) {
F_7 ( L_160 ) ;
V_4 = - V_155 ;
}
return V_4 ;
}
static void F_140 ( struct V_58 * V_157 )
{
int V_61 ;
char * V_49 = F_104 ( V_157 ) ;
if ( ! V_157 -> V_64 || V_157 -> V_156 == 0 || ! V_49 )
goto V_11;
for ( V_61 = 0 ; V_61 < V_157 -> V_156 ; V_61 ++ )
if ( F_141 ( V_157 -> args [ V_61 ] . V_166 , L_161 ) ) {
F_7 ( L_162
L_163 ,
V_157 -> args [ V_61 ] . V_166 ) ;
break;
}
V_11:
free ( V_49 ) ;
}
static int F_142 ( struct V_71 * V_72 ,
struct V_58 * V_59 ,
int V_60 , bool V_199 )
{
int V_61 , V_85 , V_4 ;
struct V_58 * V_157 = NULL ;
char V_49 [ 64 ] ;
const char * V_141 , * V_142 ;
struct V_184 * V_198 ;
F_143 ( V_188 ) ;
struct V_189 * V_121 ;
if ( V_72 -> V_64 )
V_85 = F_116 ( true ) ;
else
V_85 = F_115 ( true ) ;
if ( V_85 < 0 ) {
F_110 ( V_85 , ! V_72 -> V_64 ) ;
return V_85 ;
}
V_198 = F_135 ( V_85 , false ) ;
if ( ! V_198 ) {
F_4 ( L_164 ) ;
return - V_202 ;
}
if ( ! V_72 -> V_64 ) {
V_4 = F_125 ( & V_188 ) ;
if ( V_4 < 0 )
F_4 ( L_165 ) ;
}
V_4 = 0 ;
F_131 ( L_166 , ( V_60 > 1 ) ? L_167 : L_99 ) ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
V_157 = & V_59 [ V_61 ] ;
V_121 = F_129 ( & V_188 ,
V_157 -> V_74 . V_65 ) ;
if ( V_121 ) {
F_7 ( L_168 , V_121 -> V_14 ) ;
continue;
}
if ( V_72 -> V_141 )
V_141 = V_72 -> V_141 ;
else
if ( V_72 -> V_74 . V_56 )
V_141 = V_72 -> V_74 . V_56 ;
else
V_141 = V_157 -> V_74 . V_14 ;
if ( V_72 -> V_142 )
V_142 = V_72 -> V_142 ;
else
V_142 = V_52 ;
V_4 = F_138 ( V_49 , 64 , V_141 ,
V_198 , V_199 ) ;
if ( V_4 < 0 )
break;
V_141 = V_49 ;
V_157 -> V_141 = F_34 ( V_141 ) ;
V_157 -> V_142 = F_34 ( V_142 ) ;
if ( V_157 -> V_141 == NULL || V_157 -> V_142 == NULL ) {
V_4 = - V_50 ;
break;
}
V_4 = F_136 ( V_85 , V_157 ) ;
if ( V_4 < 0 )
break;
F_120 ( V_198 , V_141 ) ;
V_141 = V_72 -> V_141 ;
V_142 = V_72 -> V_142 ;
V_72 -> V_141 = V_157 -> V_141 ;
V_72 -> V_142 = V_157 -> V_142 ;
F_130 ( V_72 , V_157 -> V_74 . V_29 ) ;
V_72 -> V_141 = ( char * ) V_141 ;
V_72 -> V_142 = ( char * ) V_142 ;
V_199 = true ;
}
if ( V_4 == - V_51 && V_72 -> V_64 )
F_140 ( V_157 ) ;
if ( V_4 >= 0 && V_157 -> V_141 ) {
F_131 ( L_169 ) ;
F_131 ( L_170 , V_157 -> V_142 ,
V_157 -> V_141 ) ;
}
F_121 ( & V_188 ) ;
F_82 ( V_198 ) ;
F_134 ( V_85 ) ;
return V_4 ;
}
static int F_144 ( struct V_16 * V_16 , char * V_15 )
{
int V_42 = 0 ;
struct V_14 * V_25 ;
F_40 (map, name, sym) {
V_42 ++ ;
}
return V_42 ;
}
static int F_145 ( struct V_71 * V_72 ,
struct V_58 * * V_59 ,
int V_97 , const char * V_40 )
{
struct V_16 * V_16 = NULL ;
struct V_19 * V_24 = NULL ;
struct V_14 * V_25 ;
struct V_58 * V_157 ;
struct V_53 * V_54 = & V_72 -> V_74 ;
struct V_91 * V_92 ;
int V_203 ;
int V_4 , V_61 ;
V_16 = F_23 ( V_40 , V_72 -> V_64 ) ;
if ( ! V_16 ) {
V_4 = - V_51 ;
goto V_11;
}
V_203 = F_144 ( V_16 , V_54 -> V_56 ) ;
if ( V_203 == 0 ) {
F_45 ( L_171 , V_54 -> V_56 ,
V_40 ? : L_5 ) ;
V_4 = - V_66 ;
goto V_11;
} else if ( V_203 > V_97 ) {
F_45 ( L_172 ,
V_40 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_11;
}
if ( ! V_72 -> V_64 && ! V_54 -> V_70 ) {
V_24 = F_14 () ;
if ( ! V_24 ) {
F_7 ( L_22 ) ;
V_4 = - V_51 ;
goto V_11;
}
}
* V_59 = F_96 ( sizeof( * V_157 ) * V_203 ) ;
if ( ! * V_59 ) {
V_4 = - V_50 ;
goto V_11;
}
V_4 = 0 ;
F_40 (map, pp->function, sym) {
V_157 = ( * V_59 ) + V_4 ;
V_92 = & V_157 -> V_74 ;
if ( V_4 == V_203 ) {
F_7 ( L_173 ) ;
break;
}
V_4 ++ ;
if ( V_54 -> V_69 > V_25 -> V_78 - V_25 -> V_28 ) {
F_7 ( L_174 ,
V_54 -> V_69 , V_25 -> V_15 ) ;
V_4 = - V_66 ;
goto V_204;
}
V_92 -> V_65 = V_16 -> V_27 ( V_16 , V_25 -> V_28 ) + V_54 -> V_69 ;
if ( V_24 ) {
V_92 -> V_14 = F_146 ( V_24 -> V_15 , V_205 ) ;
V_92 -> V_69 = V_92 -> V_65 - V_24 -> V_18 ;
} else {
V_92 -> V_14 = F_146 ( V_25 -> V_15 , V_205 ) ;
V_92 -> V_69 = V_54 -> V_69 ;
}
V_92 -> V_70 = V_54 -> V_70 ;
if ( V_40 )
V_157 -> V_74 . V_29 = F_146 ( V_40 , V_205 ) ;
V_157 -> V_64 = V_72 -> V_64 ;
V_157 -> V_156 = V_72 -> V_156 ;
if ( V_157 -> V_156 ) {
V_157 -> args = F_96 ( sizeof( struct V_165 ) *
V_157 -> V_156 ) ;
if ( V_157 -> args == NULL )
goto V_205;
}
for ( V_61 = 0 ; V_61 < V_157 -> V_156 ; V_61 ++ ) {
if ( V_72 -> args [ V_61 ] . V_15 )
V_157 -> args [ V_61 ] . V_15 =
F_146 ( V_72 -> args [ V_61 ] . V_15 ,
V_205 ) ;
V_157 -> args [ V_61 ] . V_166 = F_146 ( V_72 -> args [ V_61 ] . V_125 ,
V_205 ) ;
if ( V_72 -> args [ V_61 ] . type )
V_157 -> args [ V_61 ] . type =
F_146 ( V_72 -> args [ V_61 ] . type ,
V_205 ) ;
}
}
V_11:
F_25 ( V_16 , V_72 -> V_64 ) ;
return V_4 ;
V_205:
V_4 = - V_50 ;
V_204:
F_37 ( * V_59 , V_203 ) ;
F_62 ( V_59 ) ;
goto V_11;
}
static int F_147 ( struct V_71 * V_72 ,
struct V_58 * * V_59 ,
int V_97 , const char * V_40 )
{
int V_4 ;
if ( V_72 -> V_64 && ! V_72 -> V_142 ) {
V_4 = F_33 ( V_40 , & V_72 -> V_142 ) ;
if ( V_4 != 0 ) {
F_7 ( L_175 ) ;
return V_4 ;
}
}
V_4 = F_59 ( V_72 , V_59 , V_97 , V_40 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_145 ( V_72 , V_59 , V_97 , V_40 ) ;
}
int F_148 ( struct V_71 * V_128 , int V_129 ,
int V_97 , bool V_206 )
{
int V_61 , V_207 , V_4 ;
struct V_208 * V_209 ;
V_4 = 0 ;
V_209 = F_96 ( sizeof( struct V_208 ) * V_129 ) ;
if ( V_209 == NULL )
return - V_50 ;
V_4 = F_2 ( V_128 -> V_64 ) ;
if ( V_4 < 0 ) {
free ( V_209 ) ;
return V_4 ;
}
for ( V_61 = 0 ; V_61 < V_129 ; V_61 ++ ) {
V_209 [ V_61 ] . V_72 = & V_128 [ V_61 ] ;
V_4 = F_147 ( V_209 [ V_61 ] . V_72 ,
& V_209 [ V_61 ] . V_59 ,
V_97 ,
V_209 [ V_61 ] . V_72 -> V_40 ) ;
if ( V_4 < 0 )
goto V_78;
V_209 [ V_61 ] . V_60 = V_4 ;
}
for ( V_61 = 0 ; V_61 < V_129 ; V_61 ++ ) {
V_4 = F_142 ( V_209 [ V_61 ] . V_72 , V_209 [ V_61 ] . V_59 ,
V_209 [ V_61 ] . V_60 , V_206 ) ;
if ( V_4 < 0 )
break;
}
V_78:
for ( V_61 = 0 ; V_61 < V_129 ; V_61 ++ ) {
for ( V_207 = 0 ; V_207 < V_209 [ V_61 ] . V_60 ; V_207 ++ )
F_38 ( & V_209 [ V_61 ] . V_59 [ V_207 ] ) ;
F_62 ( & V_209 [ V_61 ] . V_59 ) ;
}
free ( V_209 ) ;
F_8 () ;
return V_4 ;
}
static int F_149 ( int V_85 , struct V_120 * V_193 )
{
char * V_159 ;
char V_49 [ 128 ] ;
int V_4 ;
V_4 = F_1 ( V_49 , 128 , L_176 , V_193 -> V_127 ) ;
if ( V_4 < 0 )
goto error;
V_159 = strchr ( V_49 + 2 , ':' ) ;
if ( ! V_159 ) {
F_4 ( L_177 ,
V_193 -> V_127 ) ;
V_4 = - V_67 ;
goto error;
}
* V_159 = '/' ;
F_4 ( L_154 , V_49 ) ;
V_4 = F_137 ( V_85 , V_49 , strlen ( V_49 ) ) ;
if ( V_4 < 0 ) {
V_4 = - V_87 ;
goto error;
}
F_131 ( L_178 , V_193 -> V_127 ) ;
return 0 ;
error:
F_7 ( L_179 ,
F_66 ( - V_4 , V_49 , sizeof( V_49 ) ) ) ;
return V_4 ;
}
static int F_150 ( int V_85 , const char * V_49 ,
struct V_184 * V_198 )
{
struct V_120 * V_193 , * V_210 ;
int V_4 = - 1 ;
if ( strpbrk ( V_49 , L_180 ) ) {
F_151 (ent, n, namelist)
if ( F_141 ( V_193 -> V_127 , V_49 ) ) {
V_4 = F_149 ( V_85 , V_193 ) ;
if ( V_4 < 0 )
break;
F_152 ( V_198 , V_193 ) ;
}
} else {
V_193 = F_153 ( V_198 , V_49 ) ;
if ( V_193 ) {
V_4 = F_149 ( V_85 , V_193 ) ;
if ( V_4 >= 0 )
F_152 ( V_198 , V_193 ) ;
}
}
return V_4 ;
}
int F_154 ( struct V_184 * V_211 )
{
int V_4 = - 1 , V_212 = - 1 , V_213 = - 1 ;
char V_49 [ 128 ] ;
const char * V_142 , * V_141 ;
char * V_159 , * V_1 ;
struct V_120 * V_193 ;
struct V_184 * V_198 = NULL , * V_214 = NULL ;
V_213 = F_115 ( true ) ;
if ( V_213 >= 0 )
V_198 = F_135 ( V_213 , true ) ;
V_212 = F_116 ( true ) ;
if ( V_212 >= 0 )
V_214 = F_135 ( V_212 , true ) ;
if ( V_213 < 0 && V_212 < 0 ) {
F_111 ( V_213 , V_212 ) ;
goto error;
}
if ( V_198 == NULL && V_214 == NULL )
goto error;
F_80 (ent, dellist) {
V_1 = F_34 ( V_193 -> V_127 ) ;
if ( V_1 == NULL ) {
V_4 = - V_50 ;
goto error;
}
F_4 ( L_181 , V_1 ) ;
V_159 = strchr ( V_1 , ':' ) ;
if ( V_159 ) {
V_142 = V_1 ;
* V_159 = '\0' ;
V_141 = V_159 + 1 ;
} else {
V_142 = L_182 ;
V_141 = V_1 ;
}
V_4 = F_1 ( V_49 , 128 , L_147 , V_142 , V_141 ) ;
if ( V_4 < 0 ) {
F_45 ( L_183 ) ;
free ( V_1 ) ;
goto error;
}
F_4 ( L_184 , V_142 , V_141 ) ;
if ( V_198 )
V_4 = F_150 ( V_213 , V_49 , V_198 ) ;
if ( V_214 && V_4 != 0 )
V_4 = F_150 ( V_212 , V_49 , V_214 ) ;
if ( V_4 != 0 )
F_131 ( L_185 , V_49 ) ;
free ( V_1 ) ;
}
error:
if ( V_213 >= 0 ) {
F_82 ( V_198 ) ;
F_134 ( V_213 ) ;
}
if ( V_212 >= 0 ) {
F_82 ( V_214 ) ;
F_134 ( V_212 ) ;
}
return V_4 ;
}
static int F_155 ( struct V_16 * V_16 V_130 ,
struct V_14 * V_25 )
{
if ( F_81 ( V_215 , V_25 -> V_15 ) )
return 0 ;
return 1 ;
}
int F_156 ( const char * V_40 , struct V_116 * V_117 ,
bool V_41 )
{
struct V_16 * V_16 ;
int V_4 ;
V_4 = F_2 ( V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_41 )
V_16 = F_24 ( V_40 ) ;
else
V_16 = F_18 ( V_40 ) ;
if ( ! V_16 ) {
F_45 ( L_186 , ( V_40 ) ? : L_5 ) ;
return - V_51 ;
}
V_215 = V_117 ;
if ( F_15 ( V_16 , F_155 ) ) {
F_45 ( L_187 , ( V_40 ) ? : L_5 ) ;
goto V_78;
}
if ( ! F_157 ( V_16 -> V_37 , V_16 -> type ) )
F_158 ( V_16 -> V_37 , V_16 -> type ) ;
F_71 () ;
F_159 ( V_16 -> V_37 , V_16 -> type , stdout ) ;
V_78:
if ( V_41 ) {
F_26 ( V_16 -> V_37 ) ;
F_27 ( V_16 ) ;
}
F_8 () ;
return V_4 ;
}
