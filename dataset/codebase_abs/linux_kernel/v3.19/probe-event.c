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
V_4 = F_3 ( NULL ) ;
if ( V_4 < 0 ) {
F_4 ( L_1 ) ;
goto V_10;
}
if ( V_11 || V_7 )
return 0 ;
if ( V_8 . V_12 )
F_4 ( L_2 , V_8 . V_12 ) ;
V_11 = F_5 () ;
if ( ! V_11 ) {
F_4 ( L_3 ) ;
F_6 () ;
V_4 = - 1 ;
}
V_10:
if ( V_4 < 0 )
F_7 ( L_4 ) ;
return V_4 ;
}
static void F_8 ( void )
{
if ( V_11 ) {
F_9 ( V_11 ) ;
V_11 = NULL ;
}
F_6 () ;
}
static struct V_13 * F_10 ( const char * V_14 ,
struct V_15 * * V_16 )
{
return F_11 ( V_11 , V_14 , V_16 ,
NULL ) ;
}
static struct V_13 * F_12 ( T_3 V_17 , struct V_15 * * V_16 )
{
return F_13 ( V_11 , V_17 , V_16 , NULL ) ;
}
static struct V_18 * F_14 ( void )
{
struct V_19 * V_19 ;
if ( F_15 ( V_11 -> V_20 [ V_21 ] , NULL ) < 0 )
return NULL ;
V_19 = F_16 ( V_11 -> V_20 [ V_21 ] ) ;
return V_19 -> V_18 ;
}
static T_3 F_17 ( const char * V_14 , bool V_22 )
{
struct V_18 * V_23 ;
struct V_13 * V_24 ;
struct V_15 * V_15 ;
V_23 = F_14 () ;
if ( V_23 && strcmp ( V_14 , V_23 -> V_14 ) == 0 )
return ( V_22 ) ? V_23 -> V_17 : V_23 -> V_25 ;
else {
V_24 = F_10 ( V_14 , & V_15 ) ;
if ( V_24 )
return V_15 -> V_26 ( V_15 , V_24 -> V_27 ) -
( V_22 ) ? 0 : V_15 -> V_22 ;
}
return 0 ;
}
static struct V_15 * F_18 ( const char * V_28 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 = & V_11 -> V_33 ;
if ( V_28 && strchr ( V_28 , '/' ) )
return F_19 ( V_11 , 0 , V_28 ) ;
if ( ! V_28 )
V_28 = L_5 ;
for ( V_30 = F_20 ( & V_32 -> V_34 [ V_21 ] ) ; V_30 ; V_30 = F_21 ( V_30 ) ) {
struct V_15 * V_35 = F_22 ( V_30 , struct V_15 , V_29 ) ;
if ( strncmp ( V_35 -> V_36 -> V_37 + 1 , V_28 ,
V_35 -> V_36 -> V_38 - 2 ) == 0 ) {
return V_35 ;
}
}
return NULL ;
}
static struct V_36 * F_23 ( const char * V_28 )
{
struct V_36 * V_36 ;
struct V_15 * V_15 ;
const char * V_12 ;
if ( V_28 ) {
F_24 (dso, &host_machine->kernel_dsos.head,
node) {
if ( strncmp ( V_36 -> V_37 + 1 , V_28 ,
V_36 -> V_38 - 2 ) == 0 )
goto V_39;
}
F_4 ( L_6 , V_28 ) ;
return NULL ;
}
V_15 = V_11 -> V_20 [ V_21 ] ;
V_36 = V_15 -> V_36 ;
V_12 = V_8 . V_12 ;
if ( V_12 ) {
if ( F_25 ( V_36 , V_15 , V_12 , false , NULL ) <= 0 )
return NULL ;
} else {
if ( F_26 ( V_36 , V_15 , NULL ) <= 0 ) {
F_4 ( L_7 ) ;
return NULL ;
}
}
V_39:
return V_36 ;
}
const char * F_27 ( const char * V_28 )
{
struct V_36 * V_36 = F_23 ( V_28 ) ;
return ( V_36 ) ? V_36 -> V_40 : NULL ;
}
static int F_28 ( const char * V_41 , char * * V_42 )
{
char * V_43 , * V_44 , * V_45 ;
char V_46 [ 64 ] ;
int V_4 ;
V_45 = F_29 ( V_41 ) ;
if ( ! V_45 )
return - V_47 ;
V_43 = F_30 ( V_45 ) ;
if ( ! V_43 ) {
V_4 = - V_48 ;
goto V_10;
}
V_44 = strpbrk ( V_43 , L_8 ) ;
if ( V_44 )
* V_44 = '\0' ;
V_4 = F_1 ( V_46 , 64 , L_9 , V_49 , V_43 ) ;
if ( V_4 < 0 )
goto V_10;
* V_42 = F_29 ( V_46 ) ;
V_4 = * V_42 ? 0 : - V_47 ;
V_10:
free ( V_45 ) ;
return V_4 ;
}
static void F_31 ( struct V_50 * V_51 , int V_52 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ )
F_32 ( V_51 + V_53 ) ;
}
static struct V_54 * F_33 ( const char * V_28 , bool V_55 )
{
const char * V_56 = V_28 ;
struct V_54 * V_4 ;
if ( ! V_28 || ! strchr ( V_28 , '/' ) ) {
V_56 = F_27 ( V_28 ) ;
if ( ! V_56 ) {
if ( ! V_55 )
F_34 ( L_10 ,
V_28 ? : L_5 ) ;
return NULL ;
}
}
V_4 = F_35 ( V_56 ) ;
if ( ! V_4 && ! V_55 ) {
F_7 ( L_11 , V_56 ) ;
if ( ! V_28 || ! F_36 ( V_56 , L_12 ) )
F_7 ( L_13 ) ;
else
F_7 ( L_14 ) ;
F_7 ( L_15 ) ;
}
return V_4 ;
}
static int F_37 ( const char * V_41 , unsigned long * V_57 )
{
T_4 * V_58 ;
T_5 V_59 ;
T_6 V_60 ;
int V_61 , V_4 = - V_62 ;
V_61 = F_38 ( V_41 , V_63 ) ;
if ( V_61 < 0 )
return - V_64 ;
V_58 = F_39 ( V_61 , V_65 , NULL ) ;
if ( V_58 == NULL )
return - V_48 ;
if ( F_40 ( V_58 , & V_59 ) == NULL )
goto V_10;
if ( ! F_41 ( V_58 , & V_59 , & V_60 , L_16 , NULL ) )
goto V_10;
* V_57 = V_60 . V_66 - V_60 . V_67 ;
V_4 = 0 ;
V_10:
F_42 ( V_58 ) ;
return V_4 ;
}
static int F_43 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
bool V_72 )
{
struct V_54 * V_73 = NULL ;
unsigned long V_74 = 0 ;
T_3 V_17 = V_69 -> V_57 ;
int V_4 = - V_62 ;
if ( ! V_72 ) {
if ( ! V_17 ) {
V_4 = - V_48 ;
goto error;
}
V_4 = F_37 ( V_69 -> V_28 , & V_74 ) ;
if ( V_4 < 0 )
goto error;
V_17 += V_74 ;
} else {
V_17 = F_17 ( V_69 -> V_13 , false ) ;
if ( V_17 == 0 )
goto error;
V_17 += V_69 -> V_75 ;
}
F_4 ( L_17 V_76 L_18 , V_17 ,
V_69 -> V_28 ? : L_5 ) ;
V_73 = F_33 ( V_69 -> V_28 , V_77 == 0 ) ;
if ( V_73 ) {
V_4 = F_44 ( V_73 ,
( unsigned long ) V_17 , V_71 ) ;
F_45 ( V_73 ) ;
} else
V_4 = - V_62 ;
if ( V_4 > 0 ) {
V_71 -> V_78 = V_69 -> V_78 ;
return 0 ;
}
error:
F_4 ( L_19 ) ;
return V_4 ? : - V_62 ;
}
static int F_46 ( struct V_50 * V_51 ,
int V_52 , const char * V_41 )
{
int V_53 , V_4 = 0 ;
unsigned long V_74 = 0 ;
if ( ! V_41 )
return 0 ;
V_4 = F_37 ( V_41 , & V_74 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_53 = 0 ; V_53 < V_52 && V_4 >= 0 ; V_53 ++ ) {
V_51 [ V_53 ] . V_79 . V_57 -= V_74 ;
V_51 [ V_53 ] . V_79 . V_28 = F_29 ( V_41 ) ;
if ( ! V_51 [ V_53 ] . V_79 . V_28 ) {
V_4 = - V_47 ;
break;
}
V_51 [ V_53 ] . V_80 = true ;
}
return V_4 ;
}
static int F_47 ( struct V_50 * V_51 ,
int V_52 , const char * V_28 )
{
int V_53 , V_4 = 0 ;
char * V_81 ;
if ( ! V_28 )
return 0 ;
V_81 = strrchr ( V_28 , '/' ) ;
if ( V_81 ) {
V_28 = F_29 ( V_81 + 1 ) ;
if ( ! V_28 )
return - V_47 ;
V_81 = strchr ( V_28 , '.' ) ;
if ( V_81 )
* V_81 = '\0' ;
V_81 = ( char * ) V_28 ;
}
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_51 [ V_53 ] . V_79 . V_28 = F_29 ( V_28 ) ;
if ( ! V_51 [ V_53 ] . V_79 . V_28 ) {
V_4 = - V_47 ;
break;
}
}
free ( V_81 ) ;
return V_4 ;
}
static int F_48 ( struct V_50 * V_51 ,
int V_52 , const char * V_28 ,
bool V_82 )
{
struct V_18 * V_23 ;
char * V_81 ;
int V_53 ;
if ( V_82 )
return F_46 ( V_51 , V_52 , V_28 ) ;
if ( V_28 )
return F_47 ( V_51 , V_52 , V_28 ) ;
V_23 = F_14 () ;
if ( ! V_23 ) {
F_7 ( L_20 ) ;
return - V_48 ;
}
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
if ( V_51 [ V_53 ] . V_79 . V_57 && ! V_51 [ V_53 ] . V_79 . V_78 ) {
V_81 = F_29 ( V_23 -> V_14 ) ;
if ( ! V_81 )
return - V_47 ;
free ( V_51 [ V_53 ] . V_79 . V_13 ) ;
V_51 [ V_53 ] . V_79 . V_13 = V_81 ;
V_51 [ V_53 ] . V_79 . V_75 = V_51 [ V_53 ] . V_79 . V_57 -
V_23 -> V_25 ;
}
}
return 0 ;
}
static int F_49 ( struct V_83 * V_84 ,
struct V_50 * * V_51 ,
int V_85 , const char * V_86 )
{
bool V_87 = F_50 ( V_84 ) ;
struct V_54 * V_73 ;
int V_52 , V_4 = 0 ;
V_73 = F_33 ( V_86 , ! V_87 ) ;
if ( ! V_73 ) {
if ( V_87 )
return - V_62 ;
F_4 ( L_21 ) ;
return 0 ;
}
F_4 ( L_22 ) ;
V_52 = F_51 ( V_73 , V_84 , V_51 , V_85 ) ;
F_45 ( V_73 ) ;
if ( V_52 > 0 ) {
F_4 ( L_23 , V_52 ) ;
V_4 = F_48 ( * V_51 , V_52 ,
V_86 , V_84 -> V_80 ) ;
if ( V_4 < 0 ) {
F_31 ( * V_51 , V_52 ) ;
F_52 ( V_51 ) ;
}
return V_4 < 0 ? V_4 : V_52 ;
}
if ( V_52 == 0 ) {
F_7 ( L_24 ,
F_53 ( & V_84 -> V_79 ) ) ;
if ( V_87 )
return - V_62 ;
return 0 ;
}
F_4 ( L_25 , V_52 ) ;
if ( V_52 == - V_88 ) {
F_7 ( L_26
L_27 ) ;
if ( ! V_87 ) {
F_4 ( L_28 ) ;
return 0 ;
}
}
return V_52 ;
}
static int F_54 ( const char * V_89 , const char * V_90 ,
char * * V_91 )
{
const char * V_92 = V_8 . V_93 ;
if ( ! V_92 ) {
if ( V_89 [ 0 ] != '/' && V_90 )
V_92 = V_90 ;
else {
if ( F_55 ( V_89 , V_94 ) == 0 ) {
* V_91 = F_29 ( V_89 ) ;
return 0 ;
} else
return - V_64 ;
}
}
* V_91 = malloc ( ( strlen ( V_92 ) + strlen ( V_89 ) + 2 ) ) ;
if ( ! * V_91 )
return - V_47 ;
for (; ; ) {
sprintf ( * V_91 , L_29 , V_92 , V_89 ) ;
if ( F_55 ( * V_91 , V_94 ) == 0 )
return 0 ;
if ( ! V_8 . V_93 )
return - V_64 ;
switch ( V_64 ) {
case V_95 :
case V_62 :
case V_96 :
case V_97 :
V_89 = strchr ( ++ V_89 , '/' ) ;
if ( ! V_89 ) {
F_52 ( V_91 ) ;
return - V_62 ;
}
continue;
default:
F_52 ( V_91 ) ;
return - V_64 ;
}
}
}
static int F_56 ( T_7 * V_98 , int V_99 , bool V_100 , bool V_101 )
{
char V_46 [ V_102 ] , V_103 [ V_104 ] ;
const char * V_105 = V_101 ? L_30 : V_106 ;
const char * V_92 = NULL ;
do {
if ( fgets ( V_46 , V_102 , V_98 ) == NULL )
goto error;
if ( V_100 )
continue;
if ( ! V_92 ) {
V_92 = V_101 ? L_31 : L_32 ;
F_57 ( stdout , V_105 , V_92 , V_99 ) ;
}
F_57 ( stdout , V_105 , L_33 , V_46 ) ;
} while ( strchr ( V_46 , '\n' ) == NULL );
return 1 ;
error:
if ( ferror ( V_98 ) ) {
F_7 ( L_34 ,
F_58 ( V_64 , V_103 , sizeof( V_103 ) ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_59 ( T_7 * V_98 , int V_99 , bool V_100 , bool V_101 )
{
int V_107 = F_56 ( V_98 , V_99 , V_100 , V_101 ) ;
if ( V_107 == 0 ) {
F_7 ( L_35 ) ;
V_107 = - 1 ;
}
return V_107 ;
}
static int F_60 ( struct V_108 * V_109 , const char * V_28 )
{
int V_99 = 1 ;
struct V_110 * V_111 ;
struct V_54 * V_73 ;
T_7 * V_98 ;
int V_4 ;
char * V_81 ;
char V_103 [ V_104 ] ;
V_73 = F_33 ( V_28 , false ) ;
if ( ! V_73 )
return - V_62 ;
V_4 = F_61 ( V_73 , V_109 ) ;
F_45 ( V_73 ) ;
if ( V_4 == 0 || V_4 == - V_62 ) {
F_7 ( L_36 ) ;
return - V_62 ;
} else if ( V_4 < 0 ) {
F_7 ( L_37 ) ;
return V_4 ;
}
V_81 = V_109 -> V_56 ;
V_4 = F_54 ( V_81 , V_109 -> V_90 , & V_109 -> V_56 ) ;
free ( V_81 ) ;
if ( V_4 < 0 ) {
F_7 ( L_38 ) ;
return V_4 ;
}
F_62 () ;
if ( V_109 -> V_112 )
fprintf ( stdout , L_39 , V_109 -> V_112 , V_109 -> V_56 ,
V_109 -> V_27 - V_109 -> V_75 ) ;
else
fprintf ( stdout , L_40 , V_109 -> V_56 , V_109 -> V_27 ) ;
V_98 = fopen ( V_109 -> V_56 , L_41 ) ;
if ( V_98 == NULL ) {
F_7 ( L_42 , V_109 -> V_56 ,
F_58 ( V_64 , V_103 , sizeof( V_103 ) ) ) ;
return - V_64 ;
}
while ( V_99 < V_109 -> V_27 ) {
V_4 = F_63 ( V_98 , V_99 ++ ) ;
if ( V_4 < 0 )
goto V_113;
}
F_64 (ln, lr->line_list) {
for (; V_111 -> V_53 > V_99 ; V_99 ++ ) {
V_4 = F_65 ( V_98 , V_99 - V_109 -> V_75 ) ;
if ( V_4 < 0 )
goto V_113;
}
V_4 = F_66 ( V_98 , V_99 ++ - V_109 -> V_75 ) ;
if ( V_4 < 0 )
goto V_113;
}
if ( V_109 -> V_113 == V_114 )
V_109 -> V_113 = V_99 + V_115 ;
while ( V_99 <= V_109 -> V_113 ) {
V_4 = F_67 ( V_98 , V_99 ++ - V_109 -> V_75 ) ;
if ( V_4 <= 0 )
break;
}
V_113:
fclose ( V_98 ) ;
return V_4 ;
}
int F_68 ( struct V_108 * V_109 , const char * V_28 , bool V_116 )
{
int V_4 ;
V_4 = F_2 ( V_116 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_60 ( V_109 , V_28 ) ;
F_8 () ;
return V_4 ;
}
static int F_69 ( struct V_54 * V_73 ,
struct V_83 * V_84 ,
int V_117 , struct V_118 * V_119 ,
bool V_120 )
{
char * V_46 ;
int V_4 , V_53 , V_121 ;
struct V_122 * V_123 ;
struct V_124 * V_125 = NULL , * V_126 ;
const char * V_127 ;
V_46 = F_53 ( & V_84 -> V_79 ) ;
if ( ! V_46 )
return - V_48 ;
F_4 ( L_43 , V_46 ) ;
V_4 = F_70 ( V_73 , V_84 , & V_125 ,
V_117 , V_120 ) ;
if ( V_4 <= 0 ) {
if ( V_4 == 0 || V_4 == - V_62 ) {
F_34 ( L_44 , V_46 ) ;
V_4 = - V_62 ;
} else
F_7 ( L_37 ) ;
goto V_113;
}
fprintf ( stdout , L_45 , V_46 ) ;
for ( V_53 = 0 ; V_53 < V_4 ; V_53 ++ ) {
V_126 = & V_125 [ V_53 ] ;
fprintf ( stdout , L_46 , V_126 -> V_79 . V_13 ,
V_126 -> V_79 . V_75 ) ;
F_52 ( & V_126 -> V_79 . V_13 ) ;
V_121 = 0 ;
if ( V_126 -> V_128 ) {
F_71 (node, vl->vars) {
V_127 = strchr ( V_123 -> V_129 , '\t' ) + 1 ;
if ( F_72 ( V_119 , V_127 ) ) {
fprintf ( stdout , L_47 , V_123 -> V_129 ) ;
V_121 ++ ;
}
}
F_73 ( V_126 -> V_128 ) ;
}
if ( V_121 == 0 )
fprintf ( stdout , L_48 ) ;
}
free ( V_125 ) ;
V_113:
free ( V_46 ) ;
return V_4 ;
}
int F_74 ( struct V_83 * V_130 , int V_131 ,
int V_117 , const char * V_28 ,
struct V_118 * V_119 , bool V_120 )
{
int V_53 , V_4 = 0 ;
struct V_54 * V_73 ;
V_4 = F_2 ( V_130 -> V_80 ) ;
if ( V_4 < 0 )
return V_4 ;
V_73 = F_33 ( V_28 , false ) ;
if ( ! V_73 ) {
V_4 = - V_62 ;
goto V_10;
}
F_62 () ;
for ( V_53 = 0 ; V_53 < V_131 && V_4 >= 0 ; V_53 ++ )
V_4 = F_69 ( V_73 , & V_130 [ V_53 ] , V_117 , V_119 ,
V_120 ) ;
F_45 ( V_73 ) ;
V_10:
F_8 () ;
return V_4 ;
}
static int
F_43 ( struct V_68 * V_69 V_132 ,
struct V_70 * V_71 V_132 ,
bool V_72 V_132 )
{
return - V_133 ;
}
static int F_49 ( struct V_83 * V_84 ,
struct V_50 * * V_51 V_132 ,
int V_85 V_132 ,
const char * V_86 V_132 )
{
if ( F_50 ( V_84 ) ) {
F_7 ( L_49 ) ;
return - V_133 ;
}
return 0 ;
}
int F_68 ( struct V_108 * V_109 V_132 ,
const char * V_28 V_132 ,
bool V_116 V_132 )
{
F_7 ( L_49 ) ;
return - V_133 ;
}
int F_74 ( struct V_83 * V_130 V_132 ,
int V_131 V_132 , int V_117 V_132 ,
const char * V_28 V_132 ,
struct V_118 * T_8 V_132 ,
bool V_120 V_132 )
{
F_7 ( L_49 ) ;
return - V_133 ;
}
void F_75 ( struct V_108 * V_109 )
{
free ( V_109 -> V_112 ) ;
free ( V_109 -> V_134 ) ;
free ( V_109 -> V_56 ) ;
free ( V_109 -> V_90 ) ;
F_76 ( V_109 -> V_135 ) ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
}
int F_77 ( struct V_108 * V_109 )
{
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_135 = F_78 ( NULL ) ;
if ( ! V_109 -> V_135 )
return - V_47 ;
else
return 0 ;
}
static int F_79 ( char * * V_136 , int * V_137 , const char * V_138 )
{
const char * V_27 = * V_136 ;
V_64 = 0 ;
* V_137 = strtol ( * V_136 , V_136 , 0 ) ;
if ( V_64 || * V_136 == V_27 ) {
F_80 ( L_50 , V_138 ) ;
return - V_48 ;
}
return 0 ;
}
int F_81 ( const char * V_139 , struct V_108 * V_109 )
{
char * V_140 , * V_134 , * V_14 = F_29 ( V_139 ) ;
int V_141 ;
if ( ! V_14 )
return - V_47 ;
V_109 -> V_27 = 0 ;
V_109 -> V_113 = V_114 ;
V_140 = strchr ( V_14 , ':' ) ;
if ( V_140 ) {
* V_140 ++ = '\0' ;
V_141 = F_79 ( & V_140 , & V_109 -> V_27 , L_51 ) ;
if ( V_141 )
goto V_141;
if ( * V_140 == '+' || * V_140 == '-' ) {
const char V_142 = * V_140 ++ ;
V_141 = F_79 ( & V_140 , & V_109 -> V_113 , L_52 ) ;
if ( V_141 )
goto V_141;
if ( V_142 == '+' ) {
V_109 -> V_113 += V_109 -> V_27 ;
V_109 -> V_113 -- ;
}
}
F_4 ( L_53 , V_109 -> V_27 , V_109 -> V_113 ) ;
V_141 = - V_48 ;
if ( V_109 -> V_27 > V_109 -> V_113 ) {
F_80 ( L_54
L_55 ) ;
goto V_141;
}
if ( * V_140 != '\0' ) {
F_80 ( L_56 , V_140 ) ;
goto V_141;
}
}
V_134 = strchr ( V_14 , '@' ) ;
if ( V_134 ) {
* V_134 = '\0' ;
V_109 -> V_134 = F_29 ( ++ V_134 ) ;
if ( V_109 -> V_134 == NULL ) {
V_141 = - V_47 ;
goto V_141;
}
V_109 -> V_112 = V_14 ;
} else if ( strchr ( V_14 , '.' ) )
V_109 -> V_134 = V_14 ;
else
V_109 -> V_112 = V_14 ;
return 0 ;
V_141:
free ( V_14 ) ;
return V_141 ;
}
static bool F_82 ( const char * V_14 )
{
if ( ! isalpha ( * V_14 ) && * V_14 != '_' )
return false ;
while ( * ++ V_14 != '\0' ) {
if ( ! isalpha ( * V_14 ) && ! isdigit ( * V_14 ) && * V_14 != '_' )
return false ;
}
return true ;
}
static int F_83 ( char * V_139 , struct V_83 * V_84 )
{
struct V_70 * V_71 = & V_84 -> V_79 ;
char * V_136 , * V_81 ;
char V_142 , V_143 = 0 ;
V_136 = strpbrk ( V_139 , L_57 ) ;
if ( V_136 && * V_136 == '=' ) {
* V_136 = '\0' ;
V_81 = V_136 + 1 ;
if ( strchr ( V_139 , ':' ) ) {
F_80 ( L_58 ) ;
return - V_144 ;
}
if ( ! F_82 ( V_139 ) ) {
F_80 ( L_59
L_60 , V_139 ) ;
return - V_48 ;
}
V_84 -> V_145 = F_29 ( V_139 ) ;
if ( V_84 -> V_145 == NULL )
return - V_47 ;
V_84 -> V_146 = NULL ;
V_139 = V_81 ;
}
V_136 = strpbrk ( V_139 , L_61 ) ;
if ( V_136 ) {
V_143 = * V_136 ;
* V_136 ++ = '\0' ;
}
V_81 = F_29 ( V_139 ) ;
if ( V_81 == NULL )
return - V_47 ;
if ( strchr ( V_81 , '.' ) )
V_71 -> V_134 = V_81 ;
else
V_71 -> V_112 = V_81 ;
while ( V_136 ) {
V_139 = V_136 ;
V_142 = V_143 ;
if ( V_142 == ';' ) {
V_71 -> V_147 = F_29 ( V_139 ) ;
if ( V_71 -> V_147 == NULL )
return - V_47 ;
break;
}
V_136 = strpbrk ( V_139 , L_61 ) ;
if ( V_136 ) {
V_143 = * V_136 ;
* V_136 ++ = '\0' ;
}
switch ( V_142 ) {
case ':' :
V_71 -> line = strtoul ( V_139 , & V_81 , 0 ) ;
if ( * V_81 != '\0' ) {
F_80 ( L_62
L_63 ) ;
return - V_48 ;
}
break;
case '+' :
V_71 -> V_75 = strtoul ( V_139 , & V_81 , 0 ) ;
if ( * V_81 != '\0' ) {
F_80 ( L_64
L_65 ) ;
return - V_48 ;
}
break;
case '@' :
if ( V_71 -> V_134 ) {
F_80 ( L_66 ) ;
return - V_48 ;
}
V_71 -> V_134 = F_29 ( V_139 ) ;
if ( V_71 -> V_134 == NULL )
return - V_47 ;
break;
case '%' :
if ( strcmp ( V_139 , L_67 ) == 0 ) {
V_71 -> V_78 = 1 ;
} else {
F_80 ( L_68 , V_139 ) ;
return - V_144 ;
}
break;
default:
F_34 ( L_69 ,
__FILE__ , __LINE__ ) ;
return - V_144 ;
break;
}
}
if ( V_71 -> V_147 && V_71 -> line ) {
F_80 ( L_70
L_71 ) ;
return - V_48 ;
}
if ( V_71 -> V_147 && V_71 -> V_75 ) {
F_80 ( L_72 ) ;
return - V_48 ;
}
if ( V_71 -> line && V_71 -> V_75 ) {
F_80 ( L_73 ) ;
return - V_48 ;
}
if ( ! V_71 -> line && ! V_71 -> V_147 && V_71 -> V_134 && ! V_71 -> V_112 ) {
F_80 ( L_74
L_75 ) ;
return - V_48 ;
}
if ( V_71 -> V_75 && ! V_71 -> V_112 ) {
F_80 ( L_76 ) ;
return - V_48 ;
}
if ( V_71 -> V_78 && ! V_71 -> V_112 ) {
F_80 ( L_77 ) ;
return - V_48 ;
}
if ( ( V_71 -> V_75 || V_71 -> line || V_71 -> V_147 ) && V_71 -> V_78 ) {
F_80 ( L_78
L_79 ) ;
return - V_48 ;
}
F_4 ( L_80 ,
V_71 -> V_112 , V_71 -> V_134 , V_71 -> line , V_71 -> V_75 , V_71 -> V_78 ,
V_71 -> V_147 ) ;
return 0 ;
}
static int F_84 ( char * V_1 , struct V_148 * V_139 )
{
char * V_81 , * V_149 ;
struct V_150 * * V_151 ;
F_4 ( L_81 , V_1 ) ;
V_81 = strchr ( V_1 , '=' ) ;
if ( V_81 ) {
V_139 -> V_14 = F_85 ( V_1 , V_81 - V_1 ) ;
if ( V_139 -> V_14 == NULL )
return - V_47 ;
F_4 ( L_82 , V_139 -> V_14 ) ;
V_1 = V_81 + 1 ;
}
V_81 = strchr ( V_1 , ':' ) ;
if ( V_81 ) {
* V_81 = '\0' ;
V_139 -> type = F_29 ( V_81 + 1 ) ;
if ( V_139 -> type == NULL )
return - V_47 ;
F_4 ( L_83 , V_139 -> type ) ;
}
V_81 = strpbrk ( V_1 , L_84 ) ;
if ( ! F_86 ( V_1 ) || ! V_81 ) {
V_139 -> V_127 = F_29 ( V_1 ) ;
if ( V_139 -> V_127 == NULL )
return - V_47 ;
F_4 ( L_85 , V_139 -> V_127 ) ;
return 0 ;
}
V_139 -> V_127 = F_85 ( V_1 , V_81 - V_1 ) ;
if ( V_139 -> V_127 == NULL )
return - V_47 ;
V_149 = V_139 -> V_127 ;
F_4 ( L_86 , V_139 -> V_127 ) ;
V_151 = & V_139 -> V_152 ;
do {
* V_151 = F_87 ( sizeof( struct V_150 ) ) ;
if ( * V_151 == NULL )
return - V_47 ;
if ( * V_81 == '[' ) {
V_1 = V_81 ;
( * V_151 ) -> V_153 = strtol ( V_1 + 1 , & V_81 , 0 ) ;
( * V_151 ) -> V_154 = true ;
if ( * V_81 != ']' || V_81 == V_1 + 1 ) {
F_80 ( L_87
L_88 ) ;
return - V_48 ;
}
V_81 ++ ;
if ( * V_81 == '\0' )
V_81 = NULL ;
} else {
if ( * V_81 == '.' ) {
V_1 = V_81 + 1 ;
( * V_151 ) -> V_154 = false ;
} else if ( V_81 [ 1 ] == '>' ) {
V_1 = V_81 + 2 ;
( * V_151 ) -> V_154 = true ;
} else {
F_80 ( L_89 ,
V_1 ) ;
return - V_48 ;
}
V_81 = strpbrk ( V_1 , L_84 ) ;
}
if ( V_81 ) {
( * V_151 ) -> V_14 = F_85 ( V_1 , V_81 - V_1 ) ;
if ( ( * V_151 ) -> V_14 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_149 = ( * V_151 ) -> V_14 ;
F_4 ( L_90 , ( * V_151 ) -> V_14 , ( * V_151 ) -> V_154 ) ;
V_151 = & ( * V_151 ) -> V_155 ;
}
} while ( V_81 );
( * V_151 ) -> V_14 = F_29 ( V_1 ) ;
if ( ( * V_151 ) -> V_14 == NULL )
return - V_47 ;
if ( * V_1 != '[' )
V_149 = ( * V_151 ) -> V_14 ;
F_4 ( L_91 , ( * V_151 ) -> V_14 , ( * V_151 ) -> V_154 ) ;
if ( ! V_139 -> V_14 ) {
V_139 -> V_14 = F_29 ( V_149 ) ;
if ( V_139 -> V_14 == NULL )
return - V_47 ;
}
return 0 ;
}
int F_88 ( const char * V_156 , struct V_83 * V_84 )
{
char * * V_157 ;
int V_158 , V_53 , V_4 = 0 ;
V_157 = F_89 ( V_156 , & V_158 ) ;
if ( ! V_157 ) {
F_4 ( L_92 ) ;
return - V_47 ;
}
if ( V_158 - 1 > V_159 ) {
F_80 ( L_93 , V_158 - 1 ) ;
V_4 = - V_160 ;
goto V_10;
}
V_4 = F_83 ( V_157 [ 0 ] , V_84 ) ;
if ( V_4 < 0 )
goto V_10;
V_84 -> V_161 = V_158 - 1 ;
V_84 -> args = F_87 ( sizeof( struct V_148 ) * V_84 -> V_161 ) ;
if ( V_84 -> args == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
for ( V_53 = 0 ; V_53 < V_84 -> V_161 && V_4 >= 0 ; V_53 ++ ) {
V_4 = F_84 ( V_157 [ V_53 + 1 ] , & V_84 -> args [ V_53 ] ) ;
if ( V_4 >= 0 &&
F_86 ( V_84 -> args [ V_53 ] . V_127 ) && V_84 -> V_79 . V_78 ) {
F_80 ( L_94
L_95 ) ;
V_4 = - V_48 ;
}
}
V_10:
F_90 ( V_157 ) ;
return V_4 ;
}
bool F_50 ( struct V_83 * V_84 )
{
int V_53 ;
if ( V_84 -> V_79 . V_134 || V_84 -> V_79 . line || V_84 -> V_79 . V_147 )
return true ;
for ( V_53 = 0 ; V_53 < V_84 -> V_161 ; V_53 ++ )
if ( F_86 ( V_84 -> args [ V_53 ] . V_127 ) )
return true ;
return false ;
}
static int F_91 ( const char * V_156 ,
struct V_50 * V_162 )
{
struct V_68 * V_69 = & V_162 -> V_79 ;
char V_163 ;
char * V_164 ;
char * V_165 = NULL , * V_166 , * V_167 , * V_168 , * V_169 ;
int V_4 , V_53 , V_158 ;
char * * V_157 ;
F_4 ( L_96 , V_156 ) ;
V_157 = F_89 ( V_156 , & V_158 ) ;
if ( ! V_157 ) {
F_4 ( L_92 ) ;
return - V_47 ;
}
if ( V_158 < 2 ) {
F_80 ( L_97 ) ;
V_4 = - V_160 ;
goto V_10;
}
V_165 = F_29 ( V_157 [ 0 ] ) ;
if ( V_165 == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
V_167 = strtok_r ( V_165 , L_98 , & V_166 ) ;
V_168 = strtok_r ( NULL , L_99 , & V_166 ) ;
V_169 = strtok_r ( NULL , L_100 , & V_166 ) ;
if ( V_167 == NULL || strlen ( V_167 ) != 1 || V_168 == NULL
|| V_169 == NULL ) {
F_80 ( L_101 , V_157 [ 0 ] ) ;
V_4 = - V_48 ;
goto V_10;
}
V_163 = V_167 [ 0 ] ;
V_162 -> V_146 = F_29 ( V_168 ) ;
V_162 -> V_145 = F_29 ( V_169 ) ;
if ( V_162 -> V_146 == NULL || V_162 -> V_145 == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
F_4 ( L_102 , V_162 -> V_146 , V_162 -> V_145 , V_163 ) ;
V_69 -> V_78 = ( V_163 == 'r' ) ;
V_164 = strchr ( V_157 [ 1 ] , ':' ) ;
if ( V_164 ) {
V_69 -> V_28 = F_85 ( V_157 [ 1 ] , V_164 - V_157 [ 1 ] ) ;
V_164 ++ ;
} else
V_164 = V_157 [ 1 ] ;
V_167 = strtok_r ( V_164 , L_103 , & V_166 ) ;
if ( V_167 [ 0 ] == '0' )
V_69 -> V_57 = strtoul ( V_167 , NULL , 0 ) ;
else {
V_69 -> V_13 = F_29 ( V_167 ) ;
if ( V_69 -> V_13 == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
V_168 = strtok_r ( NULL , L_30 , & V_166 ) ;
if ( V_168 == NULL )
V_69 -> V_75 = 0 ;
else
V_69 -> V_75 = strtoul ( V_168 , NULL , 10 ) ;
}
V_162 -> V_161 = V_158 - 2 ;
V_162 -> args = F_87 ( sizeof( struct V_170 ) * V_162 -> V_161 ) ;
if ( V_162 -> args == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
for ( V_53 = 0 ; V_53 < V_162 -> V_161 ; V_53 ++ ) {
V_164 = strchr ( V_157 [ V_53 + 2 ] , '=' ) ;
if ( V_164 )
* V_164 ++ = '\0' ;
else
V_164 = V_157 [ V_53 + 2 ] ;
V_162 -> args [ V_53 ] . V_14 = F_29 ( V_157 [ V_53 + 2 ] ) ;
V_162 -> args [ V_53 ] . V_171 = F_29 ( V_164 ) ;
if ( V_162 -> args [ V_53 ] . V_14 == NULL || V_162 -> args [ V_53 ] . V_171 == NULL ) {
V_4 = - V_47 ;
goto V_10;
}
}
V_4 = 0 ;
V_10:
free ( V_165 ) ;
F_90 ( V_157 ) ;
return V_4 ;
}
int F_92 ( struct V_148 * V_172 , char * V_46 , T_1 V_173 )
{
struct V_150 * V_152 = V_172 -> V_152 ;
int V_4 ;
char * V_81 = V_46 ;
if ( V_172 -> V_14 && V_172 -> V_127 )
V_4 = F_1 ( V_81 , V_173 , L_104 , V_172 -> V_14 , V_172 -> V_127 ) ;
else
V_4 = F_1 ( V_81 , V_173 , L_33 , V_172 -> V_14 ? V_172 -> V_14 : V_172 -> V_127 ) ;
if ( V_4 <= 0 )
goto error;
V_81 += V_4 ;
V_173 -= V_4 ;
while ( V_152 ) {
if ( V_152 -> V_14 [ 0 ] == '[' )
V_4 = F_1 ( V_81 , V_173 , L_33 , V_152 -> V_14 ) ;
else
V_4 = F_1 ( V_81 , V_173 , L_105 ,
V_152 -> V_154 ? L_106 : L_107 , V_152 -> V_14 ) ;
if ( V_4 <= 0 )
goto error;
V_81 += V_4 ;
V_173 -= V_4 ;
V_152 = V_152 -> V_155 ;
}
if ( V_172 -> type ) {
V_4 = F_1 ( V_81 , V_173 , L_108 , V_172 -> type ) ;
if ( V_4 <= 0 )
goto error;
V_81 += V_4 ;
V_173 -= V_4 ;
}
return V_81 - V_46 ;
error:
F_4 ( L_109 , V_4 ) ;
return V_4 ;
}
static char * F_53 ( struct V_70 * V_71 )
{
char * V_46 , * V_81 ;
char V_174 [ 32 ] = L_30 , line [ 32 ] = L_30 , V_134 [ 32 ] = L_30 ;
int V_4 , V_173 ;
V_46 = F_87 ( V_175 ) ;
if ( V_46 == NULL ) {
V_4 = - V_47 ;
goto error;
}
if ( V_71 -> V_75 ) {
V_4 = F_1 ( V_174 , 32 , L_110 , V_71 -> V_75 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_71 -> line ) {
V_4 = F_1 ( line , 32 , L_111 , V_71 -> line ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_71 -> V_134 ) {
V_81 = V_71 -> V_134 ;
V_173 = strlen ( V_81 ) ;
if ( V_173 > 30 ) {
V_81 = strchr ( V_71 -> V_134 + V_173 - 30 , '/' ) ;
V_81 = V_81 ? V_81 + 1 : V_71 -> V_134 + V_173 - 30 ;
}
V_4 = F_1 ( V_134 , 32 , L_112 , V_81 ) ;
if ( V_4 <= 0 )
goto error;
}
if ( V_71 -> V_112 )
V_4 = F_1 ( V_46 , V_175 , L_113 , V_71 -> V_112 ,
V_174 , V_71 -> V_78 ? L_114 : L_30 , line ,
V_134 ) ;
else
V_4 = F_1 ( V_46 , V_175 , L_105 , V_134 , line ) ;
if ( V_4 <= 0 )
goto error;
return V_46 ;
error:
F_4 ( L_115 , V_4 ) ;
free ( V_46 ) ;
return NULL ;
}
static int F_93 ( struct V_176 * V_154 ,
char * * V_46 , T_1 * V_177 ,
int V_178 )
{
int V_4 ;
if ( V_154 -> V_155 ) {
V_178 = F_93 ( V_154 -> V_155 , V_46 ,
V_177 , V_178 + 1 ) ;
if ( V_178 < 0 )
goto V_10;
}
V_4 = F_1 ( * V_46 , * V_177 , L_116 , V_154 -> V_75 ) ;
if ( V_4 < 0 )
V_178 = V_4 ;
else {
* V_46 += V_4 ;
* V_177 -= V_4 ;
}
V_10:
return V_178 ;
}
static int F_94 ( struct V_170 * V_139 ,
char * V_46 , T_1 V_177 )
{
struct V_176 * V_154 = V_139 -> V_154 ;
int V_4 , V_178 = 0 ;
char * V_81 = V_46 ;
if ( V_139 -> V_14 )
V_4 = F_1 ( V_46 , V_177 , L_117 , V_139 -> V_14 ) ;
else
V_4 = F_1 ( V_46 , V_177 , L_118 ) ;
if ( V_4 < 0 )
return V_4 ;
V_46 += V_4 ;
V_177 -= V_4 ;
if ( V_139 -> V_171 [ 0 ] == '@' && V_139 -> V_154 )
V_154 = V_154 -> V_155 ;
if ( V_154 ) {
V_178 = F_93 ( V_154 , & V_46 ,
& V_177 , 1 ) ;
if ( V_178 < 0 )
return V_178 ;
}
if ( V_139 -> V_171 [ 0 ] == '@' && V_139 -> V_154 )
V_4 = F_1 ( V_46 , V_177 , L_119 , V_139 -> V_171 ,
V_139 -> V_154 -> V_75 ) ;
else
V_4 = F_1 ( V_46 , V_177 , L_33 , V_139 -> V_171 ) ;
if ( V_4 < 0 )
return V_4 ;
V_46 += V_4 ;
V_177 -= V_4 ;
while ( V_178 -- ) {
V_4 = F_1 ( V_46 , V_177 , L_120 ) ;
if ( V_4 < 0 )
return V_4 ;
V_46 += V_4 ;
V_177 -= V_4 ;
}
if ( V_139 -> type ) {
V_4 = F_1 ( V_46 , V_177 , L_108 , V_139 -> type ) ;
if ( V_4 <= 0 )
return V_4 ;
V_46 += V_4 ;
}
return V_46 - V_81 ;
}
char * F_95 ( struct V_50 * V_162 )
{
struct V_68 * V_69 = & V_162 -> V_79 ;
char * V_46 ;
int V_53 , V_173 , V_4 ;
V_46 = F_87 ( V_175 ) ;
if ( V_46 == NULL )
return NULL ;
V_173 = F_1 ( V_46 , V_175 , L_121 , V_69 -> V_78 ? 'r' : 'p' ,
V_162 -> V_146 , V_162 -> V_145 ) ;
if ( V_173 <= 0 )
goto error;
if ( V_162 -> V_80 && ( ! V_69 -> V_57 || ! V_69 -> V_28 ) )
goto error;
if ( V_162 -> V_80 )
V_4 = F_1 ( V_46 + V_173 , V_175 - V_173 , L_122 ,
V_69 -> V_28 , V_69 -> V_57 ) ;
else
V_4 = F_1 ( V_46 + V_173 , V_175 - V_173 , L_123 ,
V_69 -> V_28 ? : L_30 , V_69 -> V_28 ? L_98 : L_30 ,
V_69 -> V_13 , V_69 -> V_75 ) ;
if ( V_4 <= 0 )
goto error;
V_173 += V_4 ;
for ( V_53 = 0 ; V_53 < V_162 -> V_161 ; V_53 ++ ) {
V_4 = F_94 ( & V_162 -> args [ V_53 ] , V_46 + V_173 ,
V_175 - V_173 ) ;
if ( V_4 <= 0 )
goto error;
V_173 += V_4 ;
}
return V_46 ;
error:
free ( V_46 ) ;
return NULL ;
}
static int F_96 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
bool V_72 )
{
struct V_13 * V_24 = NULL ;
struct V_15 * V_15 ;
T_3 V_17 ;
int V_4 = - V_62 ;
if ( ! V_72 ) {
V_15 = F_97 ( V_69 -> V_28 ) ;
if ( ! V_15 )
goto V_10;
V_17 = V_69 -> V_57 ;
V_24 = F_98 ( V_15 , V_17 , NULL ) ;
} else {
V_17 = F_17 ( V_69 -> V_13 , true ) ;
if ( V_17 ) {
V_17 += V_69 -> V_75 ;
V_24 = F_12 ( V_17 , & V_15 ) ;
}
}
if ( ! V_24 )
goto V_10;
V_71 -> V_78 = V_69 -> V_78 ;
V_71 -> V_75 = V_17 - V_15 -> V_26 ( V_15 , V_24 -> V_27 ) ;
V_71 -> V_112 = F_29 ( V_24 -> V_14 ) ;
V_4 = V_71 -> V_112 ? 0 : - V_47 ;
V_10:
if ( V_15 && ! V_72 ) {
F_99 ( V_15 -> V_36 ) ;
F_100 ( V_15 ) ;
}
return V_4 ;
}
static int F_101 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
bool V_72 )
{
char V_46 [ 128 ] ;
int V_4 ;
V_4 = F_43 ( V_69 , V_71 , V_72 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_96 ( V_69 , V_71 , V_72 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( L_124 ) ;
if ( V_69 -> V_13 ) {
V_71 -> V_112 = F_29 ( V_69 -> V_13 ) ;
V_71 -> V_75 = V_69 -> V_75 ;
} else if ( ! V_69 -> V_28 && ! V_72 ) {
V_4 = F_1 ( V_46 , 128 , L_125 V_76 , ( T_3 ) V_69 -> V_57 ) ;
if ( V_4 < 0 )
return V_4 ;
V_71 -> V_112 = F_29 ( V_46 ) ;
V_71 -> V_75 = 0 ;
}
if ( V_71 -> V_112 == NULL )
return - V_47 ;
V_71 -> V_78 = V_69 -> V_78 ;
return 0 ;
}
static int F_102 ( struct V_50 * V_162 ,
struct V_83 * V_84 , bool V_72 )
{
char V_46 [ 64 ] = L_30 ;
int V_53 , V_4 ;
V_84 -> V_145 = F_29 ( V_162 -> V_145 ) ;
V_84 -> V_146 = F_29 ( V_162 -> V_146 ) ;
if ( V_84 -> V_145 == NULL || V_84 -> V_146 == NULL )
return - V_47 ;
V_4 = F_101 ( & V_162 -> V_79 , & V_84 -> V_79 , V_72 ) ;
if ( V_4 < 0 )
return V_4 ;
V_84 -> V_161 = V_162 -> V_161 ;
V_84 -> args = F_87 ( sizeof( struct V_148 ) * V_84 -> V_161 ) ;
if ( V_84 -> args == NULL )
return - V_47 ;
for ( V_53 = 0 ; V_53 < V_162 -> V_161 && V_4 >= 0 ; V_53 ++ ) {
if ( V_162 -> args [ V_53 ] . V_14 )
V_84 -> args [ V_53 ] . V_14 = F_29 ( V_162 -> args [ V_53 ] . V_14 ) ;
else {
V_4 = F_94 ( & V_162 -> args [ V_53 ] ,
V_46 , 64 ) ;
V_84 -> args [ V_53 ] . V_14 = F_29 ( V_46 ) ;
}
if ( V_84 -> args [ V_53 ] . V_14 == NULL && V_4 >= 0 )
V_4 = - V_47 ;
}
if ( V_4 < 0 )
F_103 ( V_84 ) ;
return V_4 ;
}
void F_103 ( struct V_83 * V_84 )
{
struct V_70 * V_71 = & V_84 -> V_79 ;
struct V_150 * V_152 , * V_155 ;
int V_53 ;
free ( V_84 -> V_145 ) ;
free ( V_84 -> V_146 ) ;
free ( V_71 -> V_134 ) ;
free ( V_71 -> V_112 ) ;
free ( V_71 -> V_147 ) ;
for ( V_53 = 0 ; V_53 < V_84 -> V_161 ; V_53 ++ ) {
free ( V_84 -> args [ V_53 ] . V_14 ) ;
free ( V_84 -> args [ V_53 ] . V_127 ) ;
free ( V_84 -> args [ V_53 ] . type ) ;
V_152 = V_84 -> args [ V_53 ] . V_152 ;
while ( V_152 ) {
V_155 = V_152 -> V_155 ;
F_52 ( & V_152 -> V_14 ) ;
free ( V_152 ) ;
V_152 = V_155 ;
}
}
free ( V_84 -> args ) ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
}
static void F_32 ( struct V_50 * V_162 )
{
struct V_176 * V_154 , * V_155 ;
int V_53 ;
free ( V_162 -> V_145 ) ;
free ( V_162 -> V_146 ) ;
free ( V_162 -> V_79 . V_13 ) ;
free ( V_162 -> V_79 . V_28 ) ;
for ( V_53 = 0 ; V_53 < V_162 -> V_161 ; V_53 ++ ) {
free ( V_162 -> args [ V_53 ] . V_14 ) ;
free ( V_162 -> args [ V_53 ] . V_171 ) ;
free ( V_162 -> args [ V_53 ] . type ) ;
V_154 = V_162 -> args [ V_53 ] . V_154 ;
while ( V_154 ) {
V_155 = V_154 -> V_155 ;
free ( V_154 ) ;
V_154 = V_155 ;
}
}
free ( V_162 -> args ) ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
}
static void F_104 ( int V_141 , bool V_72 )
{
char V_103 [ V_104 ] ;
if ( V_141 == - V_62 ) {
const char * V_179 ;
if ( ! V_72 )
V_179 = L_126 ;
else
V_179 = L_127 ;
F_7 ( L_128
L_129 ,
V_72 ? 'k' : 'u' , V_179 ) ;
} else if ( V_141 == - V_144 )
F_7 ( L_130 ) ;
else
F_7 ( L_131 ,
V_72 ? 'k' : 'u' ,
F_58 ( - V_141 , V_103 , sizeof( V_103 ) ) ) ;
}
static void F_105 ( int V_180 , int V_181 )
{
if ( V_180 == - V_144 && V_181 == - V_144 )
F_7 ( L_130 ) ;
else if ( V_180 == - V_62 && V_181 == - V_62 )
F_7 ( L_132
L_133 ) ;
else {
char V_103 [ V_104 ] ;
F_7 ( L_134 ,
F_58 ( - V_180 , V_103 , sizeof( V_103 ) ) ) ;
F_7 ( L_135 ,
F_58 ( - V_181 , V_103 , sizeof( V_103 ) ) ) ;
}
}
static int F_106 ( const char * V_182 , bool V_183 )
{
char V_46 [ V_184 ] ;
const char * V_185 ;
int V_4 ;
V_185 = F_107 () ;
if ( V_185 == NULL )
return - V_144 ;
V_4 = F_1 ( V_46 , V_184 , L_29 , V_185 , V_182 ) ;
if ( V_4 >= 0 ) {
F_4 ( L_136 , V_46 , V_183 ) ;
if ( V_183 && ! V_186 )
V_4 = F_38 ( V_46 , V_187 , V_188 ) ;
else
V_4 = F_38 ( V_46 , V_63 , 0 ) ;
if ( V_4 < 0 )
V_4 = - V_64 ;
}
return V_4 ;
}
static int F_108 ( bool V_183 )
{
return F_106 ( L_137 , V_183 ) ;
}
static int F_109 ( bool V_183 )
{
return F_106 ( L_138 , V_183 ) ;
}
static struct V_189 * F_110 ( int V_61 )
{
int V_4 , V_190 ;
T_7 * V_98 ;
char V_46 [ V_175 ] ;
char * V_164 ;
struct V_189 * V_191 ;
V_191 = F_111 ( true , NULL ) ;
V_98 = fdopen ( F_112 ( V_61 ) , L_41 ) ;
while ( ! feof ( V_98 ) ) {
V_164 = fgets ( V_46 , V_175 , V_98 ) ;
if ( ! V_164 )
break;
V_190 = strlen ( V_164 ) - 1 ;
if ( V_164 [ V_190 ] == '\n' )
V_164 [ V_190 ] = '\0' ;
V_4 = F_113 ( V_191 , V_46 ) ;
if ( V_4 < 0 ) {
F_4 ( L_139 , V_4 ) ;
F_73 ( V_191 ) ;
return NULL ;
}
}
fclose ( V_98 ) ;
return V_191 ;
}
static int F_114 ( struct V_83 * V_84 ,
const char * V_28 )
{
int V_53 , V_4 ;
char V_46 [ 128 ] ;
char * V_192 ;
V_192 = F_53 ( & V_84 -> V_79 ) ;
if ( ! V_192 )
return - V_48 ;
V_4 = F_1 ( V_46 , 128 , L_140 , V_84 -> V_146 , V_84 -> V_145 ) ;
if ( V_4 < 0 )
return V_4 ;
F_115 ( L_141 , V_46 , V_192 ) ;
if ( V_28 )
F_115 ( L_142 , V_28 ) ;
if ( V_84 -> V_161 > 0 ) {
F_115 ( L_143 ) ;
for ( V_53 = 0 ; V_53 < V_84 -> V_161 ; V_53 ++ ) {
V_4 = F_92 ( & V_84 -> args [ V_53 ] ,
V_46 , 128 ) ;
if ( V_4 < 0 )
break;
F_115 ( L_144 , V_46 ) ;
}
}
F_115 ( L_145 ) ;
free ( V_192 ) ;
return V_4 ;
}
static int F_116 ( int V_61 , bool V_72 )
{
int V_4 = 0 ;
struct V_50 V_162 ;
struct V_83 V_84 ;
struct V_189 * V_193 ;
struct V_122 * V_194 ;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_193 = F_110 ( V_61 ) ;
if ( ! V_193 )
return - V_47 ;
F_71 (ent, rawlist) {
V_4 = F_91 ( V_194 -> V_129 , & V_162 ) ;
if ( V_4 >= 0 ) {
V_4 = F_102 ( & V_162 , & V_84 ,
V_72 ) ;
if ( V_4 >= 0 )
V_4 = F_114 ( & V_84 ,
V_162 . V_79 . V_28 ) ;
}
F_103 ( & V_84 ) ;
F_32 ( & V_162 ) ;
if ( V_4 < 0 )
break;
}
F_73 ( V_193 ) ;
return V_4 ;
}
int F_117 ( void )
{
int V_195 , V_196 , V_4 ;
F_62 () ;
V_4 = F_2 ( false ) ;
if ( V_4 < 0 )
return V_4 ;
V_195 = F_108 ( false ) ;
if ( V_195 >= 0 ) {
V_4 = F_116 ( V_195 , true ) ;
F_118 ( V_195 ) ;
if ( V_4 < 0 )
goto V_10;
}
V_196 = F_109 ( false ) ;
if ( V_195 < 0 && V_196 < 0 ) {
F_105 ( V_195 , V_196 ) ;
V_4 = V_195 ;
goto V_10;
}
if ( V_196 >= 0 ) {
V_4 = F_116 ( V_196 , false ) ;
F_118 ( V_196 ) ;
}
V_10:
F_8 () ;
return V_4 ;
}
static struct V_189 * F_119 ( int V_61 , bool V_197 )
{
char V_46 [ 128 ] ;
struct V_189 * V_191 , * V_193 ;
struct V_122 * V_194 ;
struct V_50 V_162 ;
int V_4 = 0 ;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_193 = F_110 ( V_61 ) ;
if ( ! V_193 )
return NULL ;
V_191 = F_111 ( true , NULL ) ;
F_71 (ent, rawlist) {
V_4 = F_91 ( V_194 -> V_129 , & V_162 ) ;
if ( V_4 < 0 )
break;
if ( V_197 ) {
V_4 = F_1 ( V_46 , 128 , L_140 , V_162 . V_146 ,
V_162 . V_145 ) ;
if ( V_4 >= 0 )
V_4 = F_113 ( V_191 , V_46 ) ;
} else
V_4 = F_113 ( V_191 , V_162 . V_145 ) ;
F_32 ( & V_162 ) ;
if ( V_4 < 0 )
break;
}
F_73 ( V_193 ) ;
if ( V_4 < 0 ) {
F_73 ( V_191 ) ;
return NULL ;
}
return V_191 ;
}
static int F_120 ( int V_61 , struct V_50 * V_162 )
{
int V_4 = 0 ;
char * V_46 = F_95 ( V_162 ) ;
char V_103 [ V_104 ] ;
if ( ! V_46 ) {
F_4 ( L_146 ) ;
return - V_48 ;
}
F_4 ( L_147 , V_46 ) ;
if ( ! V_186 ) {
V_4 = F_121 ( V_61 , V_46 , strlen ( V_46 ) ) ;
if ( V_4 <= 0 ) {
V_4 = - V_64 ;
F_7 ( L_148 ,
F_58 ( V_64 , V_103 , sizeof( V_103 ) ) ) ;
}
}
free ( V_46 ) ;
return V_4 ;
}
static int F_122 ( char * V_46 , T_1 V_173 , const char * V_198 ,
struct V_189 * V_199 , bool V_200 )
{
int V_53 , V_4 ;
V_4 = F_1 ( V_46 , V_173 , L_33 , V_198 ) ;
if ( V_4 < 0 ) {
F_4 ( L_149 , V_4 ) ;
return V_4 ;
}
if ( ! F_123 ( V_199 , V_46 ) )
return 0 ;
if ( ! V_200 ) {
F_7 ( L_150
L_151 , V_198 ) ;
return - V_201 ;
}
for ( V_53 = 1 ; V_53 < V_202 ; V_53 ++ ) {
V_4 = F_1 ( V_46 , V_173 , L_152 , V_198 , V_53 ) ;
if ( V_4 < 0 ) {
F_4 ( L_149 , V_4 ) ;
return V_4 ;
}
if ( ! F_123 ( V_199 , V_46 ) )
break;
}
if ( V_53 == V_202 ) {
F_7 ( L_153 ) ;
V_4 = - V_160 ;
}
return V_4 ;
}
static int F_124 ( struct V_83 * V_84 ,
struct V_50 * V_51 ,
int V_52 , bool V_200 )
{
int V_53 , V_61 , V_4 ;
struct V_50 * V_162 = NULL ;
char V_46 [ 64 ] ;
const char * V_145 , * V_146 ;
struct V_189 * V_199 ;
if ( V_84 -> V_80 )
V_61 = F_109 ( true ) ;
else
V_61 = F_108 ( true ) ;
if ( V_61 < 0 ) {
F_104 ( V_61 , ! V_84 -> V_80 ) ;
return V_61 ;
}
V_199 = F_119 ( V_61 , false ) ;
if ( ! V_199 ) {
F_4 ( L_154 ) ;
return - V_203 ;
}
V_4 = 0 ;
F_115 ( L_155 , ( V_52 > 1 ) ? L_156 : L_98 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
V_162 = & V_51 [ V_53 ] ;
if ( V_84 -> V_145 )
V_145 = V_84 -> V_145 ;
else
if ( V_84 -> V_79 . V_112 )
V_145 = V_84 -> V_79 . V_112 ;
else
V_145 = V_162 -> V_79 . V_13 ;
if ( V_84 -> V_146 )
V_146 = V_84 -> V_146 ;
else
V_146 = V_49 ;
V_4 = F_122 ( V_46 , 64 , V_145 ,
V_199 , V_200 ) ;
if ( V_4 < 0 )
break;
V_145 = V_46 ;
V_162 -> V_145 = F_29 ( V_145 ) ;
V_162 -> V_146 = F_29 ( V_146 ) ;
if ( V_162 -> V_145 == NULL || V_162 -> V_146 == NULL ) {
V_4 = - V_47 ;
break;
}
V_4 = F_120 ( V_61 , V_162 ) ;
if ( V_4 < 0 )
break;
F_113 ( V_199 , V_145 ) ;
V_145 = V_84 -> V_145 ;
V_146 = V_84 -> V_146 ;
V_84 -> V_145 = V_162 -> V_145 ;
V_84 -> V_146 = V_162 -> V_146 ;
F_114 ( V_84 , V_162 -> V_79 . V_28 ) ;
V_84 -> V_145 = ( char * ) V_145 ;
V_84 -> V_146 = ( char * ) V_146 ;
V_200 = true ;
}
if ( V_4 >= 0 ) {
F_115 ( L_157 ) ;
F_115 ( L_158 , V_162 -> V_146 ,
V_162 -> V_145 ) ;
}
F_73 ( V_199 ) ;
F_118 ( V_61 ) ;
return V_4 ;
}
static int F_125 ( struct V_15 * V_15 , char * V_14 )
{
int V_39 = 0 ;
struct V_13 * V_24 ;
F_126 (map, name, sym) {
if ( V_24 -> V_204 == V_205 || V_24 -> V_204 == V_206 )
V_39 ++ ;
}
return V_39 ;
}
static int F_127 ( struct V_83 * V_84 ,
struct V_50 * * V_51 ,
int V_85 , const char * V_86 )
{
struct V_15 * V_15 = NULL ;
struct V_19 * V_19 = NULL ;
struct V_18 * V_23 = NULL ;
struct V_13 * V_24 ;
struct V_50 * V_162 ;
struct V_70 * V_71 = & V_84 -> V_79 ;
struct V_68 * V_69 ;
int V_207 ;
int V_4 , V_53 ;
if ( V_84 -> V_80 )
V_15 = F_97 ( V_86 ) ;
else
V_15 = F_18 ( V_86 ) ;
if ( ! V_15 ) {
V_4 = - V_48 ;
goto V_10;
}
V_207 = F_125 ( V_15 , V_71 -> V_112 ) ;
if ( V_207 == 0 ) {
F_34 ( L_159 , V_71 -> V_112 ,
V_86 ? : L_5 ) ;
V_4 = - V_62 ;
goto V_10;
} else if ( V_207 > V_85 ) {
F_34 ( L_160 ,
V_86 ? : L_5 ) ;
V_4 = - V_6 ;
goto V_10;
}
if ( ! V_84 -> V_80 && ! V_71 -> V_78 ) {
V_19 = F_16 ( V_15 ) ;
V_23 = V_19 -> V_18 ;
if ( ! V_23 ) {
F_7 ( L_20 ) ;
V_4 = - V_48 ;
goto V_10;
}
}
* V_51 = F_87 ( sizeof( * V_162 ) * V_207 ) ;
if ( ! * V_51 ) {
V_4 = - V_47 ;
goto V_10;
}
V_4 = 0 ;
F_126 (map, pp->function, sym) {
V_162 = ( * V_51 ) + V_4 ;
V_69 = & V_162 -> V_79 ;
if ( V_4 == V_207 ) {
F_7 ( L_161 ) ;
break;
}
V_4 ++ ;
if ( V_71 -> V_75 > V_24 -> V_113 - V_24 -> V_27 ) {
F_7 ( L_162 ,
V_71 -> V_75 , V_24 -> V_14 ) ;
V_4 = - V_62 ;
goto V_208;
}
V_69 -> V_57 = V_15 -> V_26 ( V_15 , V_24 -> V_27 ) + V_71 -> V_75 ;
if ( V_23 ) {
V_69 -> V_13 = F_128 ( V_23 -> V_14 , V_209 ) ;
V_69 -> V_75 = V_69 -> V_57 - V_23 -> V_17 ;
} else {
V_69 -> V_13 = F_128 ( V_24 -> V_14 , V_209 ) ;
V_69 -> V_75 = V_71 -> V_75 ;
}
V_69 -> V_78 = V_71 -> V_78 ;
if ( V_86 )
V_162 -> V_79 . V_28 = F_128 ( V_86 , V_209 ) ;
V_162 -> V_80 = V_84 -> V_80 ;
V_162 -> V_161 = V_84 -> V_161 ;
if ( V_162 -> V_161 ) {
V_162 -> args = F_87 ( sizeof( struct V_170 ) *
V_162 -> V_161 ) ;
if ( V_162 -> args == NULL )
goto V_209;
}
for ( V_53 = 0 ; V_53 < V_162 -> V_161 ; V_53 ++ ) {
if ( V_84 -> args [ V_53 ] . V_14 )
V_162 -> args [ V_53 ] . V_14 =
F_128 ( V_84 -> args [ V_53 ] . V_14 ,
V_209 ) ;
V_162 -> args [ V_53 ] . V_171 = F_128 ( V_84 -> args [ V_53 ] . V_127 ,
V_209 ) ;
if ( V_84 -> args [ V_53 ] . type )
V_162 -> args [ V_53 ] . type =
F_128 ( V_84 -> args [ V_53 ] . type ,
V_209 ) ;
}
}
V_10:
if ( V_15 && V_84 -> V_80 ) {
F_99 ( V_15 -> V_36 ) ;
F_100 ( V_15 ) ;
}
return V_4 ;
V_209:
V_4 = - V_47 ;
V_208:
F_31 ( * V_51 , V_207 ) ;
F_52 ( V_51 ) ;
goto V_10;
}
static int F_129 ( struct V_83 * V_84 ,
struct V_50 * * V_51 ,
int V_85 , const char * V_86 )
{
int V_4 ;
if ( V_84 -> V_80 && ! V_84 -> V_146 ) {
V_4 = F_28 ( V_86 , & V_84 -> V_146 ) ;
if ( V_4 != 0 ) {
F_7 ( L_163 ) ;
return V_4 ;
}
}
V_4 = F_49 ( V_84 , V_51 , V_85 , V_86 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_127 ( V_84 , V_51 , V_85 , V_86 ) ;
}
int F_130 ( struct V_83 * V_130 , int V_131 ,
int V_85 , const char * V_86 , bool V_210 )
{
int V_53 , V_211 , V_4 ;
struct V_212 * V_213 ;
V_4 = 0 ;
V_213 = F_87 ( sizeof( struct V_212 ) * V_131 ) ;
if ( V_213 == NULL )
return - V_47 ;
V_4 = F_2 ( V_130 -> V_80 ) ;
if ( V_4 < 0 ) {
free ( V_213 ) ;
return V_4 ;
}
for ( V_53 = 0 ; V_53 < V_131 ; V_53 ++ ) {
V_213 [ V_53 ] . V_84 = & V_130 [ V_53 ] ;
V_4 = F_129 ( V_213 [ V_53 ] . V_84 ,
& V_213 [ V_53 ] . V_51 ,
V_85 ,
V_86 ) ;
if ( V_4 < 0 )
goto V_113;
V_213 [ V_53 ] . V_52 = V_4 ;
}
for ( V_53 = 0 ; V_53 < V_131 ; V_53 ++ ) {
V_4 = F_124 ( V_213 [ V_53 ] . V_84 , V_213 [ V_53 ] . V_51 ,
V_213 [ V_53 ] . V_52 , V_210 ) ;
if ( V_4 < 0 )
break;
}
V_113:
for ( V_53 = 0 ; V_53 < V_131 ; V_53 ++ ) {
for ( V_211 = 0 ; V_211 < V_213 [ V_53 ] . V_52 ; V_211 ++ )
F_32 ( & V_213 [ V_53 ] . V_51 [ V_211 ] ) ;
F_52 ( & V_213 [ V_53 ] . V_51 ) ;
}
free ( V_213 ) ;
F_8 () ;
return V_4 ;
}
static int F_131 ( int V_61 , struct V_122 * V_194 )
{
char * V_164 ;
char V_46 [ 128 ] ;
int V_4 ;
V_4 = F_1 ( V_46 , 128 , L_164 , V_194 -> V_129 ) ;
if ( V_4 < 0 )
goto error;
V_164 = strchr ( V_46 + 2 , ':' ) ;
if ( ! V_164 ) {
F_4 ( L_165 ,
V_194 -> V_129 ) ;
V_4 = - V_144 ;
goto error;
}
* V_164 = '/' ;
F_4 ( L_147 , V_46 ) ;
V_4 = F_121 ( V_61 , V_46 , strlen ( V_46 ) ) ;
if ( V_4 < 0 ) {
V_4 = - V_64 ;
goto error;
}
F_115 ( L_166 , V_194 -> V_129 ) ;
return 0 ;
error:
F_7 ( L_167 ,
F_58 ( - V_4 , V_46 , sizeof( V_46 ) ) ) ;
return V_4 ;
}
static int F_132 ( int V_61 , const char * V_46 ,
struct V_189 * V_199 )
{
struct V_122 * V_194 , * V_214 ;
int V_4 = - 1 ;
if ( strpbrk ( V_46 , L_168 ) ) {
F_133 (ent, n, namelist)
if ( F_134 ( V_194 -> V_129 , V_46 ) ) {
V_4 = F_131 ( V_61 , V_194 ) ;
if ( V_4 < 0 )
break;
F_135 ( V_199 , V_194 ) ;
}
} else {
V_194 = F_136 ( V_199 , V_46 ) ;
if ( V_194 ) {
V_4 = F_131 ( V_61 , V_194 ) ;
if ( V_4 >= 0 )
F_135 ( V_199 , V_194 ) ;
}
}
return V_4 ;
}
int F_137 ( struct V_189 * V_215 )
{
int V_4 = - 1 , V_216 = - 1 , V_217 = - 1 ;
char V_46 [ 128 ] ;
const char * V_146 , * V_145 ;
char * V_164 , * V_1 ;
struct V_122 * V_194 ;
struct V_189 * V_199 = NULL , * V_218 = NULL ;
V_217 = F_108 ( true ) ;
if ( V_217 >= 0 )
V_199 = F_119 ( V_217 , true ) ;
V_216 = F_109 ( true ) ;
if ( V_216 >= 0 )
V_218 = F_119 ( V_216 , true ) ;
if ( V_217 < 0 && V_216 < 0 ) {
F_105 ( V_217 , V_216 ) ;
goto error;
}
if ( V_199 == NULL && V_218 == NULL )
goto error;
F_71 (ent, dellist) {
V_1 = F_29 ( V_194 -> V_129 ) ;
if ( V_1 == NULL ) {
V_4 = - V_47 ;
goto error;
}
F_4 ( L_169 , V_1 ) ;
V_164 = strchr ( V_1 , ':' ) ;
if ( V_164 ) {
V_146 = V_1 ;
* V_164 = '\0' ;
V_145 = V_164 + 1 ;
} else {
V_146 = L_170 ;
V_145 = V_1 ;
}
V_4 = F_1 ( V_46 , 128 , L_140 , V_146 , V_145 ) ;
if ( V_4 < 0 ) {
F_34 ( L_171 ) ;
free ( V_1 ) ;
goto error;
}
F_4 ( L_172 , V_146 , V_145 ) ;
if ( V_199 )
V_4 = F_132 ( V_217 , V_46 , V_199 ) ;
if ( V_218 && V_4 != 0 )
V_4 = F_132 ( V_216 , V_46 , V_218 ) ;
if ( V_4 != 0 )
F_115 ( L_173 , V_46 ) ;
free ( V_1 ) ;
}
error:
if ( V_217 >= 0 ) {
F_73 ( V_199 ) ;
F_118 ( V_217 ) ;
}
if ( V_216 >= 0 ) {
F_73 ( V_218 ) ;
F_118 ( V_216 ) ;
}
return V_4 ;
}
static int F_138 ( struct V_15 * V_15 V_132 ,
struct V_13 * V_24 )
{
if ( ( V_24 -> V_204 == V_205 || V_24 -> V_204 == V_206 ) &&
F_72 ( V_219 , V_24 -> V_14 ) )
return 0 ;
return 1 ;
}
int F_139 ( const char * V_86 , struct V_118 * V_119 ,
bool V_116 )
{
struct V_15 * V_15 ;
int V_4 ;
V_4 = F_2 ( V_116 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_116 )
V_15 = F_97 ( V_86 ) ;
else
V_15 = F_18 ( V_86 ) ;
if ( ! V_15 ) {
F_34 ( L_174 , ( V_86 ) ? : L_5 ) ;
return - V_48 ;
}
V_219 = V_119 ;
if ( F_15 ( V_15 , F_138 ) ) {
F_34 ( L_175 , ( V_86 ) ? : L_5 ) ;
goto V_113;
}
if ( ! F_140 ( V_15 -> V_36 , V_15 -> type ) )
F_141 ( V_15 -> V_36 , V_15 -> type ) ;
F_62 () ;
F_142 ( V_15 -> V_36 , V_15 -> type , stdout ) ;
V_113:
if ( V_116 ) {
F_99 ( V_15 -> V_36 ) ;
F_100 ( V_15 ) ;
}
F_8 () ;
return V_4 ;
}
