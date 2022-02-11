int F_1 ( struct V_1 * V_1 , const char * V_2 , T_1 V_3 )
{
F_2 ( & V_1 -> V_4 ) ;
F_3 ( & V_1 -> V_5 ) ;
F_4 ( & V_1 -> V_6 ) ;
F_4 ( & V_1 -> V_7 ) ;
V_1 -> V_8 = V_9 ;
F_4 ( & V_1 -> V_10 ) ;
V_1 -> V_11 = NULL ;
V_1 -> V_4 . V_1 = V_1 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_12 = NULL ;
V_1 -> V_2 = F_5 ( V_2 ) ;
if ( V_1 -> V_2 == NULL )
return - V_13 ;
if ( V_3 != V_14 ) {
struct V_15 * V_15 = F_6 ( V_1 , 0 ,
V_3 ) ;
char V_16 [ 64 ] ;
if ( V_15 == NULL )
return - V_13 ;
snprintf ( V_16 , sizeof( V_16 ) , L_1 , V_3 ) ;
F_7 ( V_15 , V_16 , 0 ) ;
}
return 0 ;
}
struct V_1 * F_8 ( void )
{
struct V_1 * V_1 = malloc ( sizeof( * V_1 ) ) ;
if ( V_1 != NULL ) {
F_1 ( V_1 , L_2 , V_14 ) ;
if ( F_9 ( V_1 ) < 0 )
goto V_17;
}
return V_1 ;
V_17:
free ( V_1 ) ;
return NULL ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_20 * V_21 , * V_22 ;
F_11 (pos, n, dsos, node) {
F_12 ( & V_21 -> V_23 ) ;
F_13 ( V_21 ) ;
}
}
void F_14 ( struct V_1 * V_1 )
{
struct V_15 * V_22 , * V_24 ;
F_11 (t, n, &machine->dead_threads, node) {
F_12 ( & V_24 -> V_23 ) ;
F_15 ( V_24 ) ;
}
}
void F_16 ( struct V_1 * V_1 )
{
struct V_5 * V_25 = F_17 ( & V_1 -> V_8 ) ;
while ( V_25 ) {
struct V_15 * V_24 = F_18 ( V_25 , struct V_15 , V_5 ) ;
F_19 ( & V_24 -> V_5 , & V_1 -> V_8 ) ;
V_25 = F_20 ( V_25 ) ;
F_15 ( V_24 ) ;
}
}
void F_21 ( struct V_1 * V_1 )
{
F_22 ( & V_1 -> V_4 ) ;
F_10 ( & V_1 -> V_6 ) ;
F_10 ( & V_1 -> V_7 ) ;
free ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
void F_23 ( struct V_1 * V_1 )
{
F_21 ( V_1 ) ;
free ( V_1 ) ;
}
void F_24 ( struct V_26 * V_26 )
{
F_1 ( & V_26 -> V_27 , L_2 , V_14 ) ;
V_26 -> V_28 = V_9 ;
V_26 -> V_12 = NULL ;
}
void F_25 ( struct V_26 * V_26 )
{
F_21 ( & V_26 -> V_27 ) ;
}
struct V_1 * F_26 ( struct V_26 * V_26 , T_1 V_3 ,
const char * V_2 )
{
struct V_5 * * V_29 = & V_26 -> V_28 . V_5 ;
struct V_5 * V_30 = NULL ;
struct V_1 * V_21 , * V_1 = malloc ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_1 ( V_1 , V_2 , V_3 ) != 0 ) {
free ( V_1 ) ;
return NULL ;
}
V_1 -> V_12 = V_26 -> V_12 ;
while ( * V_29 != NULL ) {
V_30 = * V_29 ;
V_21 = F_18 ( V_30 , struct V_1 , V_5 ) ;
if ( V_3 < V_21 -> V_3 )
V_29 = & ( * V_29 ) -> V_31 ;
else
V_29 = & ( * V_29 ) -> V_32 ;
}
F_27 ( & V_1 -> V_5 , V_30 , V_29 ) ;
F_28 ( & V_1 -> V_5 , & V_26 -> V_28 ) ;
return V_1 ;
}
void F_29 ( struct V_26 * V_26 ,
T_2 V_12 )
{
struct V_5 * V_25 ;
V_26 -> V_12 = V_12 ;
V_26 -> V_27 . V_12 = V_12 ;
for ( V_25 = F_17 ( & V_26 -> V_28 ) ; V_25 ; V_25 = F_20 ( V_25 ) ) {
struct V_1 * V_1 = F_18 ( V_25 , struct V_1 , V_5 ) ;
V_1 -> V_12 = V_12 ;
}
}
struct V_1 * F_30 ( struct V_26 * V_26 , T_1 V_3 )
{
struct V_5 * * V_29 = & V_26 -> V_28 . V_5 ;
struct V_5 * V_30 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_33 = NULL ;
if ( V_3 == V_14 )
return & V_26 -> V_27 ;
while ( * V_29 != NULL ) {
V_30 = * V_29 ;
V_1 = F_18 ( V_30 , struct V_1 , V_5 ) ;
if ( V_3 < V_1 -> V_3 )
V_29 = & ( * V_29 ) -> V_31 ;
else if ( V_3 > V_1 -> V_3 )
V_29 = & ( * V_29 ) -> V_32 ;
else
return V_1 ;
if ( ! V_1 -> V_3 )
V_33 = V_1 ;
}
return V_33 ;
}
struct V_1 * F_31 ( struct V_26 * V_26 , T_1 V_3 )
{
char V_34 [ V_35 ] ;
const char * V_2 = L_2 ;
struct V_1 * V_1 = F_30 ( V_26 , V_3 ) ;
if ( V_1 && ( V_1 -> V_3 == V_3 ) )
goto V_36;
if ( ( V_3 != V_14 ) &&
( V_3 != V_37 ) &&
( V_38 . V_39 ) ) {
sprintf ( V_34 , L_3 , V_38 . V_39 , V_3 ) ;
if ( F_32 ( V_34 , V_40 ) ) {
static struct V_41 * V_42 ;
if ( ! V_42 )
V_42 = F_33 ( true , NULL ) ;
if ( ! F_34 ( V_42 , V_34 ) ) {
F_35 ( L_4 , V_34 ) ;
F_36 ( V_42 , V_34 ) ;
}
V_1 = NULL ;
goto V_36;
}
V_2 = V_34 ;
}
V_1 = F_26 ( V_26 , V_3 , V_2 ) ;
V_36:
return V_1 ;
}
void F_37 ( struct V_26 * V_26 ,
T_3 V_43 , void * V_44 )
{
struct V_5 * V_25 ;
for ( V_25 = F_17 ( & V_26 -> V_28 ) ; V_25 ; V_25 = F_20 ( V_25 ) ) {
struct V_1 * V_21 = F_18 ( V_25 , struct V_1 , V_5 ) ;
V_43 ( V_21 , V_44 ) ;
}
}
char * F_38 ( struct V_1 * V_1 , char * V_45 , T_4 V_46 )
{
if ( F_39 ( V_1 ) )
snprintf ( V_45 , V_46 , L_5 , L_6 ) ;
else if ( F_40 ( V_1 ) )
snprintf ( V_45 , V_46 , L_5 , L_7 ) ;
else {
snprintf ( V_45 , V_46 , L_8 , L_7 ,
V_1 -> V_3 ) ;
}
return V_45 ;
}
void F_41 ( struct V_26 * V_26 , T_5 V_47 )
{
struct V_5 * V_23 ;
struct V_1 * V_1 ;
V_26 -> V_27 . V_47 = V_47 ;
for ( V_23 = F_17 ( & V_26 -> V_28 ) ; V_23 ; V_23 = F_20 ( V_23 ) ) {
V_1 = F_18 ( V_23 , struct V_1 , V_5 ) ;
V_1 -> V_47 = V_47 ;
}
return;
}
static struct V_15 * F_42 ( struct V_1 * V_1 ,
T_1 V_3 , T_1 V_48 ,
bool V_49 )
{
struct V_5 * * V_29 = & V_1 -> V_8 . V_5 ;
struct V_5 * V_30 = NULL ;
struct V_15 * V_50 ;
if ( V_1 -> V_11 && V_1 -> V_11 -> V_48 == V_48 ) {
if ( V_3 && V_3 != V_1 -> V_11 -> V_51 )
V_1 -> V_11 -> V_51 = V_3 ;
return V_1 -> V_11 ;
}
while ( * V_29 != NULL ) {
V_30 = * V_29 ;
V_50 = F_18 ( V_30 , struct V_15 , V_5 ) ;
if ( V_50 -> V_48 == V_48 ) {
V_1 -> V_11 = V_50 ;
if ( V_3 && V_3 != V_50 -> V_51 )
V_50 -> V_51 = V_3 ;
return V_50 ;
}
if ( V_48 < V_50 -> V_48 )
V_29 = & ( * V_29 ) -> V_31 ;
else
V_29 = & ( * V_29 ) -> V_32 ;
}
if ( ! V_49 )
return NULL ;
V_50 = F_43 ( V_3 , V_48 ) ;
if ( V_50 != NULL ) {
F_27 ( & V_50 -> V_5 , V_30 , V_29 ) ;
F_28 ( & V_50 -> V_5 , & V_1 -> V_8 ) ;
V_1 -> V_11 = V_50 ;
}
return V_50 ;
}
struct V_15 * F_6 ( struct V_1 * V_1 , T_1 V_3 ,
T_1 V_48 )
{
return F_42 ( V_1 , V_3 , V_48 , true ) ;
}
struct V_15 * F_44 ( struct V_1 * V_1 , T_1 V_48 )
{
return F_42 ( V_1 , 0 , V_48 , false ) ;
}
int F_45 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_15 * V_15 = F_6 ( V_1 ,
V_53 -> V_16 . V_3 ,
V_53 -> V_16 . V_48 ) ;
if ( V_56 )
F_46 ( V_53 , stdout ) ;
if ( V_15 == NULL || F_7 ( V_15 , V_53 -> V_16 . V_16 , V_55 -> time ) ) {
F_47 ( L_9 ) ;
return - 1 ;
}
return 0 ;
}
int F_48 ( struct V_1 * V_1 V_57 ,
union V_52 * V_53 , struct V_54 * V_55 V_57 )
{
F_47 ( L_10 V_58 L_11 V_58 L_12 ,
V_53 -> V_59 . V_60 , V_53 -> V_59 . V_59 ) ;
return 0 ;
}
struct V_61 * F_49 ( struct V_1 * V_1 , T_6 V_62 ,
const char * V_63 )
{
struct V_61 * V_61 ;
struct V_20 * V_20 = F_50 ( & V_1 -> V_7 , V_63 ) ;
if ( V_20 == NULL )
return NULL ;
V_61 = F_51 ( V_62 , V_20 , V_64 ) ;
if ( V_61 == NULL )
return NULL ;
if ( F_39 ( V_1 ) )
V_20 -> V_65 = V_66 ;
else
V_20 -> V_65 = V_67 ;
F_52 ( & V_1 -> V_4 , V_61 ) ;
return V_61 ;
}
T_4 F_53 ( struct V_26 * V_26 , T_7 * V_68 )
{
struct V_5 * V_25 ;
T_4 V_69 = F_54 ( & V_26 -> V_27 . V_7 , V_68 ) +
F_54 ( & V_26 -> V_27 . V_6 , V_68 ) ;
for ( V_25 = F_17 ( & V_26 -> V_28 ) ; V_25 ; V_25 = F_20 ( V_25 ) ) {
struct V_1 * V_21 = F_18 ( V_25 , struct V_1 , V_5 ) ;
V_69 += F_54 ( & V_21 -> V_7 , V_68 ) ;
V_69 += F_54 ( & V_21 -> V_6 , V_68 ) ;
}
return V_69 ;
}
T_4 F_55 ( struct V_1 * V_1 , T_7 * V_68 ,
bool (F_56)( struct V_20 * V_20 , int V_70 ) , int V_70 )
{
return F_57 ( & V_1 -> V_7 , V_68 , F_56 , V_70 ) +
F_57 ( & V_1 -> V_6 , V_68 , F_56 , V_70 ) ;
}
T_4 F_58 ( struct V_26 * V_26 , T_7 * V_68 ,
bool (F_56)( struct V_20 * V_20 , int V_70 ) , int V_70 )
{
struct V_5 * V_25 ;
T_4 V_69 = F_55 ( & V_26 -> V_27 , V_68 , F_56 , V_70 ) ;
for ( V_25 = F_17 ( & V_26 -> V_28 ) ; V_25 ; V_25 = F_20 ( V_25 ) ) {
struct V_1 * V_21 = F_18 ( V_25 , struct V_1 , V_5 ) ;
V_69 += F_55 ( V_21 , V_68 , F_56 , V_70 ) ;
}
return V_69 ;
}
T_4 F_59 ( struct V_1 * V_1 , T_7 * V_68 )
{
int V_71 ;
T_4 V_72 = 0 ;
struct V_20 * V_73 = V_1 -> V_74 [ V_64 ] -> V_20 ;
if ( V_73 -> V_75 ) {
char V_63 [ V_35 ] ;
if ( F_60 ( V_73 , V_63 , sizeof( V_63 ) ) )
V_72 += fprintf ( V_68 , L_13 , V_63 ) ;
}
for ( V_71 = 0 ; V_71 < V_76 ; ++ V_71 )
V_72 += fprintf ( V_68 , L_14 ,
V_71 + V_73 -> V_75 , V_77 [ V_71 ] ) ;
return V_72 ;
}
T_4 F_61 ( struct V_1 * V_1 , T_7 * V_68 )
{
T_4 V_69 = 0 ;
struct V_5 * V_25 ;
for ( V_25 = F_17 ( & V_1 -> V_8 ) ; V_25 ; V_25 = F_20 ( V_25 ) ) {
struct V_15 * V_21 = F_18 ( V_25 , struct V_15 , V_5 ) ;
V_69 += F_62 ( V_21 , V_68 ) ;
}
return V_69 ;
}
static struct V_20 * F_63 ( struct V_1 * V_1 )
{
const char * V_78 = NULL ;
struct V_20 * V_79 ;
if ( F_39 ( V_1 ) ) {
V_78 = V_38 . V_78 ;
if ( ! V_78 )
V_78 = L_15 ;
V_79 = F_64 ( V_1 , V_78 ,
L_16 ,
V_80 ) ;
} else {
char V_45 [ V_35 ] ;
if ( F_40 ( V_1 ) )
V_78 = V_38 . V_81 ;
if ( ! V_78 )
V_78 = F_38 ( V_1 , V_45 ,
sizeof( V_45 ) ) ;
V_79 = F_64 ( V_1 , V_78 ,
L_17 ,
V_82 ) ;
}
if ( V_79 != NULL && ( ! V_79 -> V_75 ) )
F_65 ( V_79 , V_1 ) ;
return V_79 ;
}
static int F_66 ( void * V_83 , const char * V_84 ,
char type V_57 , T_6 V_62 )
{
struct V_85 * args = V_83 ;
if ( strchr ( V_84 , '[' ) )
return 0 ;
args -> V_62 = V_62 ;
return 1 ;
}
static T_6 F_67 ( struct V_1 * V_1 )
{
const char * V_63 ;
char V_34 [ V_35 ] ;
struct V_85 args ;
if ( F_39 ( V_1 ) ) {
V_63 = L_18 ;
} else {
if ( F_40 ( V_1 ) )
V_63 = ( char * ) V_38 . V_86 ;
else {
sprintf ( V_34 , L_19 , V_1 -> V_2 ) ;
V_63 = V_34 ;
}
}
if ( F_68 ( V_63 , L_18 ) )
return 0 ;
if ( F_69 ( V_63 , & args , F_66 ) <= 0 )
return 0 ;
return args . V_62 ;
}
int F_70 ( struct V_1 * V_1 , struct V_20 * V_79 )
{
enum V_87 type ;
T_6 V_62 = F_67 ( V_1 ) ;
for ( type = 0 ; type < V_88 ; ++ type ) {
struct V_89 * V_89 ;
V_1 -> V_74 [ type ] = F_51 ( V_62 , V_79 , type ) ;
if ( V_1 -> V_74 [ type ] == NULL )
return - 1 ;
V_1 -> V_74 [ type ] -> V_90 =
V_1 -> V_74 [ type ] -> V_91 =
V_92 ;
V_89 = F_71 ( V_1 -> V_74 [ type ] ) ;
V_89 -> V_4 = & V_1 -> V_4 ;
F_52 ( & V_1 -> V_4 ,
V_1 -> V_74 [ type ] ) ;
}
return 0 ;
}
void F_72 ( struct V_1 * V_1 )
{
enum V_87 type ;
for ( type = 0 ; type < V_88 ; ++ type ) {
struct V_89 * V_89 ;
if ( V_1 -> V_74 [ type ] == NULL )
continue;
V_89 = F_71 ( V_1 -> V_74 [ type ] ) ;
F_73 ( & V_1 -> V_4 ,
V_1 -> V_74 [ type ] ) ;
if ( V_89 -> V_93 ) {
if ( type == V_64 ) {
free ( ( char * ) V_89 -> V_93 -> V_84 ) ;
V_89 -> V_93 -> V_84 = NULL ;
free ( V_89 -> V_93 ) ;
}
V_89 -> V_93 = NULL ;
}
F_74 ( V_1 -> V_74 [ type ] ) ;
V_1 -> V_74 [ type ] = NULL ;
}
}
int F_75 ( struct V_26 * V_26 )
{
int V_69 = 0 ;
struct V_94 * * V_95 = NULL ;
int V_71 , V_96 = 0 ;
char V_34 [ V_35 ] ;
T_1 V_3 ;
char * V_97 ;
if ( V_38 . V_81 ||
V_38 . V_98 ||
V_38 . V_86 ) {
F_76 ( V_26 , V_37 ) ;
}
if ( V_38 . V_39 ) {
V_96 = F_77 ( V_38 . V_39 , & V_95 , NULL , NULL ) ;
if ( V_96 <= 0 )
return - V_99 ;
for ( V_71 = 0 ; V_71 < V_96 ; V_71 ++ ) {
if ( ! isdigit ( V_95 [ V_71 ] -> V_100 [ 0 ] ) ) {
continue;
}
V_3 = ( T_1 ) strtol ( V_95 [ V_71 ] -> V_100 , & V_97 , 10 ) ;
if ( ( * V_97 != '\0' ) ||
( V_97 == V_95 [ V_71 ] -> V_100 ) ||
( V_101 == V_102 ) ) {
F_78 ( L_20 ,
V_95 [ V_71 ] -> V_100 ) ;
continue;
}
sprintf ( V_34 , L_21 ,
V_38 . V_39 ,
V_95 [ V_71 ] -> V_100 ) ;
V_69 = F_32 ( V_34 , V_40 ) ;
if ( V_69 ) {
F_78 ( L_4 , V_34 ) ;
goto V_103;
}
F_76 ( V_26 , V_3 ) ;
}
V_103:
free ( V_95 ) ;
}
return V_69 ;
}
void F_79 ( struct V_26 * V_26 )
{
struct V_5 * V_104 = F_17 ( & V_26 -> V_28 ) ;
F_72 ( & V_26 -> V_27 ) ;
while ( V_104 ) {
struct V_1 * V_21 = F_18 ( V_104 , struct V_1 , V_5 ) ;
V_104 = F_20 ( & V_21 -> V_5 ) ;
F_19 ( & V_21 -> V_5 , & V_26 -> V_28 ) ;
F_23 ( V_21 ) ;
}
}
int F_76 ( struct V_26 * V_26 , T_1 V_3 )
{
struct V_1 * V_1 = F_31 ( V_26 , V_3 ) ;
if ( V_1 == NULL )
return - 1 ;
return F_9 ( V_1 ) ;
}
int F_80 ( struct V_1 * V_1 , const char * V_63 ,
enum V_87 type , T_2 V_105 )
{
struct V_61 * V_61 = V_1 -> V_74 [ type ] ;
int V_69 = F_81 ( V_61 -> V_20 , V_63 , V_61 , V_105 ) ;
if ( V_69 > 0 ) {
F_82 ( V_61 -> V_20 , type ) ;
F_83 ( & V_1 -> V_4 , type ) ;
}
return V_69 ;
}
int F_84 ( struct V_1 * V_1 , enum V_87 type ,
T_2 V_105 )
{
struct V_61 * V_61 = V_1 -> V_74 [ type ] ;
int V_69 = F_85 ( V_61 -> V_20 , V_61 , V_105 ) ;
if ( V_69 > 0 )
F_82 ( V_61 -> V_20 , type ) ;
return V_69 ;
}
static void F_86 ( struct V_106 * V_107 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_88 ; ++ V_71 )
F_83 ( V_107 , V_71 ) ;
}
static char * F_87 ( const char * V_2 )
{
char V_108 [ V_35 ] ;
T_7 * V_109 ;
char * V_84 , * V_110 ;
const char * V_111 = L_22 ;
sprintf ( V_108 , L_23 , V_2 ) ;
V_109 = fopen ( V_108 , L_24 ) ;
if ( ! V_109 )
return NULL ;
V_108 [ 0 ] = '\0' ;
V_110 = fgets ( V_108 , sizeof( V_108 ) , V_109 ) ;
fclose ( V_109 ) ;
V_84 = strstr ( V_108 , V_111 ) ;
if ( ! V_84 )
return NULL ;
V_84 += strlen ( V_111 ) ;
V_110 = strchr ( V_84 , ' ' ) ;
if ( V_110 )
* V_110 = '\0' ;
return F_5 ( V_84 ) ;
}
static int F_88 ( struct V_106 * V_107 ,
const char * V_112 )
{
struct V_94 * V_113 ;
T_8 * V_114 = F_89 ( V_112 ) ;
int V_69 = 0 ;
if ( ! V_114 ) {
F_78 ( L_25 , V_115 , V_112 ) ;
return - 1 ;
}
while ( ( V_113 = F_90 ( V_114 ) ) != NULL ) {
char V_34 [ V_35 ] ;
struct V_116 V_117 ;
snprintf ( V_34 , sizeof( V_34 ) , L_26 , V_112 , V_113 -> V_100 ) ;
if ( V_116 ( V_34 , & V_117 ) )
continue;
if ( F_91 ( V_117 . V_118 ) ) {
if ( ! strcmp ( V_113 -> V_100 , L_27 ) ||
! strcmp ( V_113 -> V_100 , L_28 ) )
continue;
V_69 = F_88 ( V_107 , V_34 ) ;
if ( V_69 < 0 )
goto V_36;
} else {
char * V_119 = strrchr ( V_113 -> V_100 , '.' ) ,
V_120 [ V_35 ] ;
struct V_61 * V_61 ;
char * V_121 ;
if ( V_119 == NULL || strcmp ( V_119 , L_29 ) )
continue;
snprintf ( V_120 , sizeof( V_120 ) , L_30 ,
( int ) ( V_119 - V_113 -> V_100 ) , V_113 -> V_100 ) ;
F_92 ( V_120 , '-' , '_' ) ;
V_61 = F_93 ( V_107 , V_64 ,
V_120 ) ;
if ( V_61 == NULL )
continue;
V_121 = F_5 ( V_34 ) ;
if ( V_121 == NULL ) {
V_69 = - 1 ;
goto V_36;
}
F_94 ( V_61 -> V_20 , V_121 ) ;
V_61 -> V_20 -> V_122 = 1 ;
F_95 ( V_61 -> V_20 , L_2 ) ;
}
}
V_36:
F_96 ( V_114 ) ;
return V_69 ;
}
static int F_97 ( struct V_1 * V_1 )
{
char * V_108 ;
char V_123 [ V_35 ] ;
V_108 = F_87 ( V_1 -> V_2 ) ;
if ( ! V_108 )
return - 1 ;
snprintf ( V_123 , sizeof( V_123 ) , L_31 ,
V_1 -> V_2 , V_108 ) ;
free ( V_108 ) ;
return F_88 ( & V_1 -> V_4 , V_123 ) ;
}
static int F_98 ( void * V_83 , const char * V_84 , T_6 V_62 )
{
struct V_1 * V_1 = V_83 ;
struct V_61 * V_61 ;
V_61 = F_49 ( V_1 , V_62 , V_84 ) ;
if ( V_61 == NULL )
return - 1 ;
F_95 ( V_61 -> V_20 , V_1 -> V_2 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_1 )
{
const char * V_124 ;
char V_34 [ V_35 ] ;
if ( F_40 ( V_1 ) ) {
V_124 = V_38 . V_98 ;
} else {
snprintf ( V_34 , V_35 , L_32 , V_1 -> V_2 ) ;
V_124 = V_34 ;
}
if ( F_68 ( V_124 , L_33 ) )
return - 1 ;
if ( F_100 ( V_124 , V_1 , F_98 ) )
return - 1 ;
if ( ! F_97 ( V_1 ) )
return 0 ;
F_78 ( L_34 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 )
{
struct V_20 * V_79 = F_63 ( V_1 ) ;
if ( V_79 == NULL ||
F_70 ( V_1 , V_79 ) < 0 )
return - 1 ;
if ( V_38 . V_125 && F_99 ( V_1 ) < 0 ) {
if ( F_39 ( V_1 ) )
F_78 ( L_35
L_36 ) ;
else
F_78 ( L_37
L_36 , V_1 -> V_3 ) ;
}
F_86 ( & V_1 -> V_4 ) ;
return 0 ;
}
static void F_101 ( struct V_1 * V_1 ,
union V_52 * V_53 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_88 ; V_71 ++ ) {
V_1 -> V_74 [ V_71 ] -> V_62 = V_53 -> V_126 . V_62 ;
V_1 -> V_74 [ V_71 ] -> V_127 = ( V_53 -> V_126 . V_62 +
V_53 -> V_126 . V_128 ) ;
if ( V_1 -> V_74 [ V_71 ] -> V_127 == 0 )
V_1 -> V_74 [ V_71 ] -> V_127 = ~ 0ULL ;
}
}
static bool F_102 ( struct V_1 * V_1 )
{
struct V_20 * V_20 ;
F_103 (dso, &machine->kernel_dsos, node) {
if ( F_104 ( V_20 ) )
return true ;
}
return false ;
}
static int F_105 ( struct V_1 * V_1 ,
union V_52 * V_53 )
{
struct V_61 * V_61 ;
char V_129 [ V_35 ] ;
enum V_130 V_131 ;
bool V_132 ;
if ( F_102 ( V_1 ) )
return 0 ;
F_38 ( V_1 , V_129 , sizeof( V_129 ) ) ;
if ( F_39 ( V_1 ) )
V_131 = V_80 ;
else
V_131 = V_82 ;
V_132 = memcmp ( V_53 -> V_126 . V_63 ,
V_129 ,
strlen ( V_129 ) - 1 ) == 0 ;
if ( V_53 -> V_126 . V_63 [ 0 ] == '/' ||
( ! V_132 && V_53 -> V_126 . V_63 [ 0 ] == '[' ) ) {
char V_133 [ 1024 ] ;
char * V_84 , * V_119 ;
if ( V_53 -> V_126 . V_63 [ 0 ] == '/' ) {
V_84 = strrchr ( V_53 -> V_126 . V_63 , '/' ) ;
if ( V_84 == NULL )
goto V_134;
++ V_84 ;
V_119 = strrchr ( V_84 , '.' ) ;
if ( V_119 == NULL )
goto V_134;
snprintf ( V_133 , sizeof( V_133 ) ,
L_30 , ( int ) ( V_119 - V_84 ) , V_84 ) ;
F_92 ( V_133 , '-' , '_' ) ;
} else
strcpy ( V_133 , V_53 -> V_126 . V_63 ) ;
V_61 = F_49 ( V_1 , V_53 -> V_126 . V_62 ,
V_53 -> V_126 . V_63 ) ;
if ( V_61 == NULL )
goto V_134;
V_84 = F_5 ( V_133 ) ;
if ( V_84 == NULL )
goto V_134;
V_61 -> V_20 -> V_135 = V_84 ;
V_61 -> V_20 -> V_136 = 1 ;
V_61 -> V_127 = V_61 -> V_62 + V_53 -> V_126 . V_128 ;
} else if ( V_132 ) {
const char * V_137 = ( V_53 -> V_126 . V_63 +
strlen ( V_129 ) ) ;
struct V_20 * V_79 = F_50 ( & V_1 -> V_7 ,
V_129 ) ;
if ( V_79 == NULL )
goto V_134;
V_79 -> V_79 = V_131 ;
if ( F_70 ( V_1 , V_79 ) < 0 )
goto V_134;
F_101 ( V_1 , V_53 ) ;
if ( V_53 -> V_126 . V_138 != 0 ) {
F_106 ( V_1 -> V_74 ,
V_137 ,
V_53 -> V_126 . V_138 ) ;
}
if ( F_40 ( V_1 ) ) {
F_107 ( V_79 , V_1 -> V_74 [ V_64 ] ,
NULL ) ;
}
}
return 0 ;
V_134:
return - 1 ;
}
int F_108 ( struct V_1 * V_1 ,
union V_52 * V_53 ,
struct V_54 * V_55 V_57 )
{
T_9 V_139 = V_53 -> V_140 . V_141 & V_142 ;
struct V_15 * V_15 ;
struct V_61 * V_61 ;
enum V_87 type ;
int V_69 = 0 ;
if ( V_56 )
F_109 ( V_53 , stdout ) ;
if ( V_139 == V_143 ||
V_139 == V_144 ) {
V_69 = F_105 ( V_1 , V_53 ) ;
if ( V_69 < 0 )
goto V_134;
return 0 ;
}
V_15 = F_6 ( V_1 , V_53 -> V_145 . V_3 ,
V_53 -> V_145 . V_3 ) ;
if ( V_15 == NULL )
goto V_134;
if ( V_53 -> V_140 . V_141 & V_146 )
type = V_147 ;
else
type = V_64 ;
V_61 = F_110 ( & V_1 -> V_6 , V_53 -> V_145 . V_62 ,
V_53 -> V_145 . V_128 , V_53 -> V_145 . V_138 ,
V_53 -> V_145 . V_3 , V_53 -> V_145 . V_148 ,
V_53 -> V_145 . V_149 , V_53 -> V_145 . V_150 ,
V_53 -> V_145 . V_151 ,
V_53 -> V_145 . V_63 , type ) ;
if ( V_61 == NULL )
goto V_134;
F_111 ( V_15 , V_61 ) ;
return 0 ;
V_134:
F_47 ( L_38 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 V_57 )
{
T_9 V_139 = V_53 -> V_140 . V_141 & V_142 ;
struct V_15 * V_15 ;
struct V_61 * V_61 ;
enum V_87 type ;
int V_69 = 0 ;
if ( V_56 )
F_113 ( V_53 , stdout ) ;
if ( V_139 == V_143 ||
V_139 == V_144 ) {
V_69 = F_105 ( V_1 , V_53 ) ;
if ( V_69 < 0 )
goto V_134;
return 0 ;
}
V_15 = F_6 ( V_1 , V_53 -> V_126 . V_3 ,
V_53 -> V_126 . V_3 ) ;
if ( V_15 == NULL )
goto V_134;
if ( V_53 -> V_140 . V_141 & V_146 )
type = V_147 ;
else
type = V_64 ;
V_61 = F_110 ( & V_1 -> V_6 , V_53 -> V_126 . V_62 ,
V_53 -> V_126 . V_128 , V_53 -> V_126 . V_138 ,
V_53 -> V_126 . V_3 , 0 , 0 , 0 , 0 ,
V_53 -> V_126 . V_63 ,
type ) ;
if ( V_61 == NULL )
goto V_134;
F_111 ( V_15 , V_61 ) ;
return 0 ;
V_134:
F_47 ( L_39 ) ;
return 0 ;
}
static void F_114 ( struct V_1 * V_1 , struct V_15 * V_50 )
{
V_1 -> V_11 = NULL ;
F_19 ( & V_50 -> V_5 , & V_1 -> V_8 ) ;
F_115 ( & V_50 -> V_23 , & V_1 -> V_10 ) ;
}
int F_116 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_15 * V_15 = F_44 ( V_1 , V_53 -> V_152 . V_48 ) ;
struct V_15 * V_30 = F_6 ( V_1 ,
V_53 -> V_152 . V_153 ,
V_53 -> V_152 . V_154 ) ;
if ( V_15 != NULL )
F_114 ( V_1 , V_15 ) ;
V_15 = F_6 ( V_1 , V_53 -> V_152 . V_3 ,
V_53 -> V_152 . V_48 ) ;
if ( V_56 )
F_117 ( V_53 , stdout ) ;
if ( V_15 == NULL || V_30 == NULL ||
F_118 ( V_15 , V_30 , V_55 -> time ) < 0 ) {
F_47 ( L_40 ) ;
return - 1 ;
}
return 0 ;
}
int F_119 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 V_57 )
{
struct V_15 * V_15 = F_44 ( V_1 , V_53 -> V_152 . V_48 ) ;
if ( V_56 )
F_117 ( V_53 , stdout ) ;
if ( V_15 != NULL )
F_120 ( V_15 ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 )
{
int V_69 ;
switch ( V_53 -> V_140 . type ) {
case V_155 :
V_69 = F_45 ( V_1 , V_53 , V_55 ) ; break;
case V_156 :
V_69 = F_112 ( V_1 , V_53 , V_55 ) ; break;
case V_157 :
V_69 = F_108 ( V_1 , V_53 , V_55 ) ; break;
case V_158 :
V_69 = F_116 ( V_1 , V_53 , V_55 ) ; break;
case V_159 :
V_69 = F_119 ( V_1 , V_53 , V_55 ) ; break;
case V_160 :
V_69 = F_48 ( V_1 , V_53 , V_55 ) ; break;
default:
V_69 = - 1 ;
break;
}
return V_69 ;
}
static bool F_122 ( struct V_161 * V_162 , T_10 * V_163 )
{
if ( V_162 -> V_84 && ! regexec ( V_163 , V_162 -> V_84 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_123 ( struct V_1 * V_1 , struct V_15 * V_15 ,
struct V_164 * V_165 ,
T_6 V_166 )
{
struct V_167 V_168 ;
T_4 V_71 ;
T_9 V_169 ;
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
for ( V_71 = 0 ; V_71 < V_170 ; V_71 ++ ) {
V_169 = V_171 [ V_71 ] ;
F_124 ( V_15 , V_1 , V_169 , V_64 ,
V_166 , & V_168 ) ;
if ( V_168 . V_162 )
goto V_172;
}
V_172:
V_165 -> V_173 = V_166 ;
V_165 -> V_174 = V_168 . V_173 ;
V_165 -> V_162 = V_168 . V_162 ;
V_165 -> V_61 = V_168 . V_61 ;
}
static void F_125 ( struct V_1 * V_1 , struct V_15 * V_15 ,
T_9 V_169 , struct V_164 * V_165 , T_6 V_173 )
{
struct V_167 V_168 ;
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
F_124 ( V_15 , V_1 , V_169 , V_147 , V_173 ,
& V_168 ) ;
V_165 -> V_173 = V_173 ;
V_165 -> V_174 = V_168 . V_173 ;
V_165 -> V_162 = V_168 . V_162 ;
V_165 -> V_61 = V_168 . V_61 ;
}
struct V_175 * F_126 ( struct V_1 * V_1 ,
struct V_15 * V_176 ,
struct V_54 * V_55 ,
T_9 V_139 )
{
struct V_175 * V_177 = F_127 ( sizeof( * V_177 ) ) ;
if ( ! V_177 )
return NULL ;
F_123 ( V_1 , V_176 , & V_177 -> V_178 , V_55 -> V_166 ) ;
F_125 ( V_1 , V_176 , V_139 , & V_177 -> V_179 , V_55 -> V_173 ) ;
V_177 -> V_180 . V_181 = V_55 -> V_180 ;
return V_177 ;
}
struct V_182 * F_128 ( struct V_1 * V_1 ,
struct V_15 * V_176 ,
struct V_183 * V_184 )
{
struct V_182 * V_185 ;
unsigned int V_71 ;
V_185 = calloc ( V_184 -> V_186 , sizeof( struct V_182 ) ) ;
if ( ! V_185 )
return NULL ;
for ( V_71 = 0 ; V_71 < V_184 -> V_186 ; V_71 ++ ) {
F_123 ( V_1 , V_176 , & V_185 [ V_71 ] . V_187 , V_184 -> V_188 [ V_71 ] . V_187 ) ;
F_123 ( V_1 , V_176 , & V_185 [ V_71 ] . V_189 , V_184 -> V_188 [ V_71 ] . V_189 ) ;
V_185 [ V_71 ] . V_190 = V_184 -> V_188 [ V_71 ] . V_190 ;
}
return V_185 ;
}
static int F_129 ( struct V_1 * V_1 ,
struct V_15 * V_15 ,
struct V_191 * V_192 ,
struct V_161 * * V_30 ,
struct V_167 * V_193 ,
int V_194 )
{
T_9 V_139 = V_195 ;
int V_196 = V_149 ( V_194 , ( int ) V_192 -> V_186 ) ;
int V_71 ;
int V_197 ;
F_130 ( & V_198 ) ;
if ( V_192 -> V_186 > V_199 ) {
F_131 ( L_41 ) ;
return 0 ;
}
for ( V_71 = 0 ; V_71 < V_196 ; V_71 ++ ) {
T_6 V_166 ;
struct V_167 V_168 ;
if ( V_200 . V_201 == V_202 )
V_166 = V_192 -> V_203 [ V_71 ] ;
else
V_166 = V_192 -> V_203 [ V_192 -> V_186 - V_71 - 1 ] ;
if ( V_166 >= V_204 ) {
switch ( V_166 ) {
case V_205 :
V_139 = V_206 ;
break;
case V_207 :
V_139 = V_144 ;
break;
case V_208 :
V_139 = V_195 ;
break;
default:
F_78 ( L_42
L_43 V_209 L_12 , ( V_210 ) V_166 ) ;
F_130 ( & V_198 ) ;
return 0 ;
}
continue;
}
V_168 . V_211 = false ;
F_124 ( V_15 , V_1 , V_139 ,
V_64 , V_166 , & V_168 ) ;
if ( V_168 . V_162 != NULL ) {
if ( V_212 && ! * V_30 &&
F_122 ( V_168 . V_162 , & V_213 ) )
* V_30 = V_168 . V_162 ;
else if ( V_214 && V_193 &&
F_122 ( V_168 . V_162 , & V_215 ) ) {
* V_193 = V_168 ;
F_130 ( & V_198 ) ;
}
if ( ! V_38 . V_216 )
break;
}
V_197 = F_132 ( & V_198 ,
V_166 , V_168 . V_61 , V_168 . V_162 ) ;
if ( V_197 )
return V_197 ;
}
return 0 ;
}
static int F_133 ( struct F_133 * V_217 , void * V_83 )
{
struct V_198 * V_218 = V_83 ;
return F_132 ( V_218 , V_217 -> V_166 ,
V_217 -> V_61 , V_217 -> V_162 ) ;
}
int F_134 ( struct V_1 * V_1 ,
struct V_219 * V_220 ,
struct V_15 * V_15 ,
struct V_54 * V_55 ,
struct V_161 * * V_30 ,
struct V_167 * V_193 ,
int V_194 )
{
int V_69 ;
V_69 = F_129 ( V_1 , V_15 ,
V_55 -> V_221 , V_30 ,
V_193 , V_194 ) ;
if ( V_69 )
return V_69 ;
if ( ! ( ( V_220 -> V_222 . V_223 & V_224 ) &&
( V_220 -> V_222 . V_223 & V_225 ) ) )
return 0 ;
if ( ( ! V_55 -> V_226 . V_227 ) ||
( ! V_55 -> V_228 . V_46 ) )
return 0 ;
return F_135 ( F_133 , & V_198 , V_1 ,
V_15 , V_220 -> V_222 . V_229 ,
V_55 , V_194 ) ;
}
int F_136 ( struct V_1 * V_1 ,
int (* F_137)( struct V_15 * V_15 , void * V_29 ) ,
void * V_230 )
{
struct V_5 * V_25 ;
struct V_15 * V_15 ;
int V_231 = 0 ;
for ( V_25 = F_17 ( & V_1 -> V_8 ) ; V_25 ; V_25 = F_20 ( V_25 ) ) {
V_15 = F_18 ( V_25 , struct V_15 , V_5 ) ;
V_231 = F_137 ( V_15 , V_230 ) ;
if ( V_231 != 0 )
return V_231 ;
}
F_103 (thread, &machine->dead_threads, node) {
V_231 = F_137 ( V_15 , V_230 ) ;
if ( V_231 != 0 )
return V_231 ;
}
return V_231 ;
}
int F_138 ( struct V_1 * V_1 , struct V_232 * V_233 ,
struct V_234 * V_234 , struct V_235 * V_8 ,
T_11 V_43 , bool V_236 )
{
if ( F_139 ( V_234 ) )
return F_140 ( V_233 , V_8 , V_43 , V_1 , V_236 ) ;
else if ( F_141 ( V_234 ) )
return F_142 ( V_233 , V_43 , V_1 , V_236 ) ;
return 0 ;
}
