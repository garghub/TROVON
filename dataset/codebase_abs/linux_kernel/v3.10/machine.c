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
V_1 -> V_2 = F_5 ( V_2 ) ;
if ( V_1 -> V_2 == NULL )
return - V_12 ;
if ( V_3 != V_13 ) {
struct V_14 * V_14 = F_6 ( V_1 , V_3 ) ;
char V_15 [ 64 ] ;
if ( V_14 == NULL )
return - V_12 ;
snprintf ( V_15 , sizeof( V_15 ) , L_1 , V_3 ) ;
F_7 ( V_14 , V_15 ) ;
}
return 0 ;
}
static void F_8 ( struct V_16 * V_17 )
{
struct V_18 * V_19 , * V_20 ;
F_9 (pos, n, dsos, node) {
F_10 ( & V_19 -> V_21 ) ;
F_11 ( V_19 ) ;
}
}
void F_12 ( struct V_1 * V_1 )
{
struct V_14 * V_20 , * V_22 ;
F_9 (t, n, &machine->dead_threads, node) {
F_10 ( & V_22 -> V_21 ) ;
F_13 ( V_22 ) ;
}
}
void F_14 ( struct V_1 * V_1 )
{
struct V_5 * V_23 = F_15 ( & V_1 -> V_8 ) ;
while ( V_23 ) {
struct V_14 * V_22 = F_16 ( V_23 , struct V_14 , V_5 ) ;
F_17 ( & V_22 -> V_5 , & V_1 -> V_8 ) ;
V_23 = F_18 ( V_23 ) ;
F_13 ( V_22 ) ;
}
}
void F_19 ( struct V_1 * V_1 )
{
F_20 ( & V_1 -> V_4 ) ;
F_8 ( & V_1 -> V_6 ) ;
F_8 ( & V_1 -> V_7 ) ;
free ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
void F_21 ( struct V_1 * V_1 )
{
F_19 ( V_1 ) ;
free ( V_1 ) ;
}
void F_22 ( struct V_24 * V_24 )
{
F_1 ( & V_24 -> V_25 , L_2 , V_13 ) ;
V_24 -> V_26 = V_9 ;
}
void F_23 ( struct V_24 * V_24 )
{
F_19 ( & V_24 -> V_25 ) ;
}
struct V_1 * F_24 ( struct V_24 * V_24 , T_1 V_3 ,
const char * V_2 )
{
struct V_5 * * V_27 = & V_24 -> V_26 . V_5 ;
struct V_5 * V_28 = NULL ;
struct V_1 * V_19 , * V_1 = malloc ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_1 ( V_1 , V_2 , V_3 ) != 0 ) {
free ( V_1 ) ;
return NULL ;
}
while ( * V_27 != NULL ) {
V_28 = * V_27 ;
V_19 = F_16 ( V_28 , struct V_1 , V_5 ) ;
if ( V_3 < V_19 -> V_3 )
V_27 = & ( * V_27 ) -> V_29 ;
else
V_27 = & ( * V_27 ) -> V_30 ;
}
F_25 ( & V_1 -> V_5 , V_28 , V_27 ) ;
F_26 ( & V_1 -> V_5 , & V_24 -> V_26 ) ;
return V_1 ;
}
struct V_1 * F_27 ( struct V_24 * V_24 , T_1 V_3 )
{
struct V_5 * * V_27 = & V_24 -> V_26 . V_5 ;
struct V_5 * V_28 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_31 = NULL ;
if ( V_3 == V_13 )
return & V_24 -> V_25 ;
while ( * V_27 != NULL ) {
V_28 = * V_27 ;
V_1 = F_16 ( V_28 , struct V_1 , V_5 ) ;
if ( V_3 < V_1 -> V_3 )
V_27 = & ( * V_27 ) -> V_29 ;
else if ( V_3 > V_1 -> V_3 )
V_27 = & ( * V_27 ) -> V_30 ;
else
return V_1 ;
if ( ! V_1 -> V_3 )
V_31 = V_1 ;
}
return V_31 ;
}
struct V_1 * F_28 ( struct V_24 * V_24 , T_1 V_3 )
{
char V_32 [ V_33 ] ;
const char * V_2 = L_2 ;
struct V_1 * V_1 = F_27 ( V_24 , V_3 ) ;
if ( V_1 && ( V_1 -> V_3 == V_3 ) )
goto V_34;
if ( ( V_3 != V_13 ) &&
( V_3 != V_35 ) &&
( V_36 . V_37 ) ) {
sprintf ( V_32 , L_3 , V_36 . V_37 , V_3 ) ;
if ( F_29 ( V_32 , V_38 ) ) {
static struct V_39 * V_40 ;
if ( ! V_40 )
V_40 = F_30 ( true , NULL ) ;
if ( ! F_31 ( V_40 , V_32 ) ) {
F_32 ( L_4 , V_32 ) ;
F_33 ( V_40 , V_32 ) ;
}
V_1 = NULL ;
goto V_34;
}
V_2 = V_32 ;
}
V_1 = F_24 ( V_24 , V_3 , V_2 ) ;
V_34:
return V_1 ;
}
void F_34 ( struct V_24 * V_24 ,
T_2 V_41 , void * V_42 )
{
struct V_5 * V_23 ;
for ( V_23 = F_15 ( & V_24 -> V_26 ) ; V_23 ; V_23 = F_18 ( V_23 ) ) {
struct V_1 * V_19 = F_16 ( V_23 , struct V_1 , V_5 ) ;
V_41 ( V_19 , V_42 ) ;
}
}
char * F_35 ( struct V_1 * V_1 , char * V_43 , T_3 V_44 )
{
if ( F_36 ( V_1 ) )
snprintf ( V_43 , V_44 , L_5 , L_6 ) ;
else if ( F_37 ( V_1 ) )
snprintf ( V_43 , V_44 , L_5 , L_7 ) ;
else {
snprintf ( V_43 , V_44 , L_8 , L_7 ,
V_1 -> V_3 ) ;
}
return V_43 ;
}
void F_38 ( struct V_24 * V_24 , T_4 V_45 )
{
struct V_5 * V_21 ;
struct V_1 * V_1 ;
V_24 -> V_25 . V_45 = V_45 ;
for ( V_21 = F_15 ( & V_24 -> V_26 ) ; V_21 ; V_21 = F_18 ( V_21 ) ) {
V_1 = F_16 ( V_21 , struct V_1 , V_5 ) ;
V_1 -> V_45 = V_45 ;
}
return;
}
static struct V_14 * F_39 ( struct V_1 * V_1 , T_1 V_3 ,
bool V_46 )
{
struct V_5 * * V_27 = & V_1 -> V_8 . V_5 ;
struct V_5 * V_28 = NULL ;
struct V_14 * V_47 ;
if ( V_1 -> V_11 && V_1 -> V_11 -> V_3 == V_3 )
return V_1 -> V_11 ;
while ( * V_27 != NULL ) {
V_28 = * V_27 ;
V_47 = F_16 ( V_28 , struct V_14 , V_5 ) ;
if ( V_47 -> V_3 == V_3 ) {
V_1 -> V_11 = V_47 ;
return V_47 ;
}
if ( V_3 < V_47 -> V_3 )
V_27 = & ( * V_27 ) -> V_29 ;
else
V_27 = & ( * V_27 ) -> V_30 ;
}
if ( ! V_46 )
return NULL ;
V_47 = F_40 ( V_3 ) ;
if ( V_47 != NULL ) {
F_25 ( & V_47 -> V_5 , V_28 , V_27 ) ;
F_26 ( & V_47 -> V_5 , & V_1 -> V_8 ) ;
V_1 -> V_11 = V_47 ;
}
return V_47 ;
}
struct V_14 * F_6 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_39 ( V_1 , V_3 , true ) ;
}
struct V_14 * F_41 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_39 ( V_1 , V_3 , false ) ;
}
int F_42 ( struct V_1 * V_1 , union V_48 * V_49 )
{
struct V_14 * V_14 = F_6 ( V_1 , V_49 -> V_15 . V_50 ) ;
if ( V_51 )
F_43 ( V_49 , stdout ) ;
if ( V_14 == NULL || F_7 ( V_14 , V_49 -> V_15 . V_15 ) ) {
F_44 ( L_9 ) ;
return - 1 ;
}
return 0 ;
}
int F_45 ( struct V_1 * V_1 V_52 ,
union V_48 * V_49 )
{
F_44 ( L_10 V_53 L_11 V_53 L_12 ,
V_49 -> V_54 . V_55 , V_49 -> V_54 . V_54 ) ;
return 0 ;
}
struct V_56 * F_46 ( struct V_1 * V_1 , T_5 V_57 ,
const char * V_58 )
{
struct V_56 * V_56 ;
struct V_18 * V_18 = F_47 ( & V_1 -> V_7 , V_58 ) ;
if ( V_18 == NULL )
return NULL ;
V_56 = F_48 ( V_57 , V_18 , V_59 ) ;
if ( V_56 == NULL )
return NULL ;
if ( F_36 ( V_1 ) )
V_18 -> V_60 = V_61 ;
else
V_18 -> V_60 = V_62 ;
F_49 ( & V_1 -> V_4 , V_56 ) ;
return V_56 ;
}
T_3 F_50 ( struct V_24 * V_24 , T_6 * V_63 )
{
struct V_5 * V_23 ;
T_3 V_64 = F_51 ( & V_24 -> V_25 . V_7 , V_63 ) +
F_51 ( & V_24 -> V_25 . V_6 , V_63 ) ;
for ( V_23 = F_15 ( & V_24 -> V_26 ) ; V_23 ; V_23 = F_18 ( V_23 ) ) {
struct V_1 * V_19 = F_16 ( V_23 , struct V_1 , V_5 ) ;
V_64 += F_51 ( & V_19 -> V_7 , V_63 ) ;
V_64 += F_51 ( & V_19 -> V_6 , V_63 ) ;
}
return V_64 ;
}
T_3 F_52 ( struct V_1 * V_1 , T_6 * V_63 ,
bool (F_53)( struct V_18 * V_18 , int V_65 ) , int V_65 )
{
return F_54 ( & V_1 -> V_7 , V_63 , F_53 , V_65 ) +
F_54 ( & V_1 -> V_6 , V_63 , F_53 , V_65 ) ;
}
T_3 F_55 ( struct V_24 * V_24 , T_6 * V_63 ,
bool (F_53)( struct V_18 * V_18 , int V_65 ) , int V_65 )
{
struct V_5 * V_23 ;
T_3 V_64 = F_52 ( & V_24 -> V_25 , V_63 , F_53 , V_65 ) ;
for ( V_23 = F_15 ( & V_24 -> V_26 ) ; V_23 ; V_23 = F_18 ( V_23 ) ) {
struct V_1 * V_19 = F_16 ( V_23 , struct V_1 , V_5 ) ;
V_64 += F_52 ( V_19 , V_63 , F_53 , V_65 ) ;
}
return V_64 ;
}
T_3 F_56 ( struct V_1 * V_1 , T_6 * V_63 )
{
int V_66 ;
T_3 V_67 = 0 ;
struct V_18 * V_68 = V_1 -> V_69 [ V_59 ] -> V_18 ;
if ( V_68 -> V_70 ) {
char V_58 [ V_33 ] ;
if ( F_57 ( V_68 , V_58 , sizeof( V_58 ) ) )
V_67 += fprintf ( V_63 , L_13 , V_58 ) ;
}
for ( V_66 = 0 ; V_66 < V_71 ; ++ V_66 )
V_67 += fprintf ( V_63 , L_14 ,
V_66 + V_68 -> V_70 , V_72 [ V_66 ] ) ;
return V_67 ;
}
T_3 F_58 ( struct V_1 * V_1 , T_6 * V_63 )
{
T_3 V_64 = 0 ;
struct V_5 * V_23 ;
for ( V_23 = F_15 ( & V_1 -> V_8 ) ; V_23 ; V_23 = F_18 ( V_23 ) ) {
struct V_14 * V_19 = F_16 ( V_23 , struct V_14 , V_5 ) ;
V_64 += F_59 ( V_19 , V_63 ) ;
}
return V_64 ;
}
static struct V_18 * F_60 ( struct V_1 * V_1 )
{
const char * V_73 = NULL ;
struct V_18 * V_74 ;
if ( F_36 ( V_1 ) ) {
V_73 = V_36 . V_73 ;
if ( ! V_73 )
V_73 = L_15 ;
V_74 = F_61 ( V_1 , V_73 ,
L_16 ,
V_75 ) ;
} else {
char V_43 [ V_33 ] ;
if ( F_37 ( V_1 ) )
V_73 = V_36 . V_76 ;
if ( ! V_73 )
V_73 = F_35 ( V_1 , V_43 ,
sizeof( V_43 ) ) ;
V_74 = F_61 ( V_1 , V_73 ,
L_17 ,
V_77 ) ;
}
if ( V_74 != NULL && ( ! V_74 -> V_70 ) )
F_62 ( V_74 , V_1 ) ;
return V_74 ;
}
static int F_63 ( void * V_78 , const char * V_79 ,
char type V_52 , T_5 V_57 )
{
struct V_80 * args = V_78 ;
if ( strchr ( V_79 , '[' ) )
return 0 ;
args -> V_57 = V_57 ;
return 1 ;
}
static T_5 F_64 ( struct V_1 * V_1 )
{
const char * V_58 ;
char V_32 [ V_33 ] ;
struct V_80 args ;
if ( F_36 ( V_1 ) ) {
V_58 = L_18 ;
} else {
if ( F_37 ( V_1 ) )
V_58 = ( char * ) V_36 . V_81 ;
else {
sprintf ( V_32 , L_19 , V_1 -> V_2 ) ;
V_58 = V_32 ;
}
}
if ( F_65 ( V_58 , L_18 ) )
return 0 ;
if ( F_66 ( V_58 , & args , F_63 ) <= 0 )
return 0 ;
return args . V_57 ;
}
int F_67 ( struct V_1 * V_1 , struct V_18 * V_74 )
{
enum V_82 type ;
T_5 V_57 = F_64 ( V_1 ) ;
for ( type = 0 ; type < V_83 ; ++ type ) {
struct V_84 * V_84 ;
V_1 -> V_69 [ type ] = F_48 ( V_57 , V_74 , type ) ;
if ( V_1 -> V_69 [ type ] == NULL )
return - 1 ;
V_1 -> V_69 [ type ] -> V_85 =
V_1 -> V_69 [ type ] -> V_86 =
V_87 ;
V_84 = F_68 ( V_1 -> V_69 [ type ] ) ;
V_84 -> V_4 = & V_1 -> V_4 ;
F_49 ( & V_1 -> V_4 ,
V_1 -> V_69 [ type ] ) ;
}
return 0 ;
}
void F_69 ( struct V_1 * V_1 )
{
enum V_82 type ;
for ( type = 0 ; type < V_83 ; ++ type ) {
struct V_84 * V_84 ;
if ( V_1 -> V_69 [ type ] == NULL )
continue;
V_84 = F_68 ( V_1 -> V_69 [ type ] ) ;
F_70 ( & V_1 -> V_4 ,
V_1 -> V_69 [ type ] ) ;
if ( V_84 -> V_88 ) {
if ( type == V_59 ) {
free ( ( char * ) V_84 -> V_88 -> V_79 ) ;
V_84 -> V_88 -> V_79 = NULL ;
free ( V_84 -> V_88 ) ;
}
V_84 -> V_88 = NULL ;
}
F_71 ( V_1 -> V_69 [ type ] ) ;
V_1 -> V_69 [ type ] = NULL ;
}
}
int F_72 ( struct V_24 * V_24 )
{
int V_64 = 0 ;
struct V_89 * * V_90 = NULL ;
int V_66 , V_91 = 0 ;
char V_32 [ V_33 ] ;
T_1 V_3 ;
char * V_92 ;
if ( V_36 . V_76 ||
V_36 . V_93 ||
V_36 . V_81 ) {
F_73 ( V_24 , V_35 ) ;
}
if ( V_36 . V_37 ) {
V_91 = F_74 ( V_36 . V_37 , & V_90 , NULL , NULL ) ;
if ( V_91 <= 0 )
return - V_94 ;
for ( V_66 = 0 ; V_66 < V_91 ; V_66 ++ ) {
if ( ! isdigit ( V_90 [ V_66 ] -> V_95 [ 0 ] ) ) {
continue;
}
V_3 = ( T_1 ) strtol ( V_90 [ V_66 ] -> V_95 , & V_92 , 10 ) ;
if ( ( * V_92 != '\0' ) ||
( V_92 == V_90 [ V_66 ] -> V_95 ) ||
( V_96 == V_97 ) ) {
F_75 ( L_20 ,
V_90 [ V_66 ] -> V_95 ) ;
continue;
}
sprintf ( V_32 , L_21 ,
V_36 . V_37 ,
V_90 [ V_66 ] -> V_95 ) ;
V_64 = F_29 ( V_32 , V_38 ) ;
if ( V_64 ) {
F_75 ( L_4 , V_32 ) ;
goto V_98;
}
F_73 ( V_24 , V_3 ) ;
}
V_98:
free ( V_90 ) ;
}
return V_64 ;
}
void F_76 ( struct V_24 * V_24 )
{
struct V_5 * V_99 = F_15 ( & V_24 -> V_26 ) ;
F_69 ( & V_24 -> V_25 ) ;
while ( V_99 ) {
struct V_1 * V_19 = F_16 ( V_99 , struct V_1 , V_5 ) ;
V_99 = F_18 ( & V_19 -> V_5 ) ;
F_17 ( & V_19 -> V_5 , & V_24 -> V_26 ) ;
F_21 ( V_19 ) ;
}
}
int F_73 ( struct V_24 * V_24 , T_1 V_3 )
{
struct V_1 * V_1 = F_28 ( V_24 , V_3 ) ;
if ( V_1 == NULL )
return - 1 ;
return F_77 ( V_1 ) ;
}
int F_78 ( struct V_1 * V_1 , const char * V_58 ,
enum V_82 type , T_7 V_100 )
{
struct V_56 * V_56 = V_1 -> V_69 [ type ] ;
int V_64 = F_79 ( V_56 -> V_18 , V_58 , V_56 , V_100 ) ;
if ( V_64 > 0 ) {
F_80 ( V_56 -> V_18 , type ) ;
F_81 ( & V_1 -> V_4 , type ) ;
}
return V_64 ;
}
int F_82 ( struct V_1 * V_1 , enum V_82 type ,
T_7 V_100 )
{
struct V_56 * V_56 = V_1 -> V_69 [ type ] ;
int V_64 = F_83 ( V_56 -> V_18 , V_56 , V_100 ) ;
if ( V_64 > 0 ) {
F_80 ( V_56 -> V_18 , type ) ;
F_84 ( V_56 ) ;
}
return V_64 ;
}
static void F_85 ( struct V_101 * V_102 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_83 ; ++ V_66 )
F_81 ( V_102 , V_66 ) ;
}
static char * F_86 ( const char * V_2 )
{
char V_103 [ V_33 ] ;
T_6 * V_104 ;
char * V_79 , * V_105 ;
const char * V_106 = L_22 ;
sprintf ( V_103 , L_23 , V_2 ) ;
V_104 = fopen ( V_103 , L_24 ) ;
if ( ! V_104 )
return NULL ;
V_103 [ 0 ] = '\0' ;
V_105 = fgets ( V_103 , sizeof( V_103 ) , V_104 ) ;
fclose ( V_104 ) ;
V_79 = strstr ( V_103 , V_106 ) ;
if ( ! V_79 )
return NULL ;
V_79 += strlen ( V_106 ) ;
V_105 = strchr ( V_79 , ' ' ) ;
if ( V_105 )
* V_105 = '\0' ;
return F_5 ( V_79 ) ;
}
static int F_87 ( struct V_101 * V_102 ,
const char * V_107 )
{
struct V_89 * V_108 ;
T_8 * V_109 = F_88 ( V_107 ) ;
int V_64 = 0 ;
if ( ! V_109 ) {
F_75 ( L_25 , V_110 , V_107 ) ;
return - 1 ;
}
while ( ( V_108 = F_89 ( V_109 ) ) != NULL ) {
char V_32 [ V_33 ] ;
struct V_111 V_112 ;
snprintf ( V_32 , sizeof( V_32 ) , L_26 , V_107 , V_108 -> V_95 ) ;
if ( V_111 ( V_32 , & V_112 ) )
continue;
if ( F_90 ( V_112 . V_113 ) ) {
if ( ! strcmp ( V_108 -> V_95 , L_27 ) ||
! strcmp ( V_108 -> V_95 , L_28 ) )
continue;
V_64 = F_87 ( V_102 , V_32 ) ;
if ( V_64 < 0 )
goto V_34;
} else {
char * V_114 = strrchr ( V_108 -> V_95 , '.' ) ,
V_115 [ V_33 ] ;
struct V_56 * V_56 ;
char * V_116 ;
if ( V_114 == NULL || strcmp ( V_114 , L_29 ) )
continue;
snprintf ( V_115 , sizeof( V_115 ) , L_30 ,
( int ) ( V_114 - V_108 -> V_95 ) , V_108 -> V_95 ) ;
F_91 ( V_115 , '-' , '_' ) ;
V_56 = F_92 ( V_102 , V_59 ,
V_115 ) ;
if ( V_56 == NULL )
continue;
V_116 = F_5 ( V_32 ) ;
if ( V_116 == NULL ) {
V_64 = - 1 ;
goto V_34;
}
F_93 ( V_56 -> V_18 , V_116 ) ;
V_56 -> V_18 -> V_117 = 1 ;
F_94 ( V_56 -> V_18 , L_2 ) ;
}
}
V_34:
F_95 ( V_109 ) ;
return V_64 ;
}
static int F_96 ( struct V_1 * V_1 )
{
char * V_103 ;
char V_118 [ V_33 ] ;
V_103 = F_86 ( V_1 -> V_2 ) ;
if ( ! V_103 )
return - 1 ;
snprintf ( V_118 , sizeof( V_118 ) , L_31 ,
V_1 -> V_2 , V_103 ) ;
free ( V_103 ) ;
return F_87 ( & V_1 -> V_4 , V_118 ) ;
}
static int F_97 ( struct V_1 * V_1 )
{
char * line = NULL ;
T_3 V_20 ;
T_6 * V_104 ;
struct V_56 * V_56 ;
const char * V_119 ;
char V_32 [ V_33 ] ;
if ( F_37 ( V_1 ) )
V_119 = V_36 . V_93 ;
else {
sprintf ( V_32 , L_32 , V_1 -> V_2 ) ;
V_119 = V_32 ;
}
if ( F_65 ( V_32 , L_33 ) )
return - 1 ;
V_104 = fopen ( V_119 , L_24 ) ;
if ( V_104 == NULL )
return - 1 ;
while ( ! feof ( V_104 ) ) {
char V_79 [ V_33 ] ;
T_5 V_57 ;
char * V_120 ;
int V_121 ;
V_121 = F_98 ( & line , & V_20 , V_104 ) ;
if ( V_121 < 0 )
break;
if ( ! line )
goto V_122;
line [ -- V_121 ] = '\0' ;
V_120 = strrchr ( line , 'x' ) ;
if ( V_120 == NULL )
continue;
F_99 ( V_120 + 1 , & V_57 ) ;
V_120 = strchr ( line , ' ' ) ;
if ( V_120 == NULL )
continue;
* V_120 = '\0' ;
snprintf ( V_79 , sizeof( V_79 ) , L_5 , line ) ;
V_56 = F_46 ( V_1 , V_57 , V_79 ) ;
if ( V_56 == NULL )
goto V_123;
F_94 ( V_56 -> V_18 , V_1 -> V_2 ) ;
}
free ( line ) ;
fclose ( V_104 ) ;
return F_96 ( V_1 ) ;
V_123:
free ( line ) ;
V_122:
return - 1 ;
}
int F_77 ( struct V_1 * V_1 )
{
struct V_18 * V_74 = F_60 ( V_1 ) ;
if ( V_74 == NULL ||
F_67 ( V_1 , V_74 ) < 0 )
return - 1 ;
if ( V_36 . V_124 && F_97 ( V_1 ) < 0 ) {
if ( F_36 ( V_1 ) )
F_75 ( L_34
L_35 ) ;
else
F_75 ( L_36
L_35 , V_1 -> V_3 ) ;
}
F_85 ( & V_1 -> V_4 ) ;
return 0 ;
}
static void F_100 ( struct V_1 * V_1 ,
union V_48 * V_49 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_83 ; V_66 ++ ) {
V_1 -> V_69 [ V_66 ] -> V_57 = V_49 -> V_125 . V_57 ;
V_1 -> V_69 [ V_66 ] -> V_126 = ( V_49 -> V_125 . V_57 +
V_49 -> V_125 . V_127 ) ;
if ( V_1 -> V_69 [ V_66 ] -> V_126 == 0 )
V_1 -> V_69 [ V_66 ] -> V_126 = ~ 0ULL ;
}
}
static int F_101 ( struct V_1 * V_1 ,
union V_48 * V_49 )
{
struct V_56 * V_56 ;
char V_128 [ V_33 ] ;
enum V_129 V_130 ;
bool V_131 ;
F_35 ( V_1 , V_128 , sizeof( V_128 ) ) ;
if ( F_36 ( V_1 ) )
V_130 = V_75 ;
else
V_130 = V_77 ;
V_131 = memcmp ( V_49 -> V_125 . V_58 ,
V_128 ,
strlen ( V_128 ) - 1 ) == 0 ;
if ( V_49 -> V_125 . V_58 [ 0 ] == '/' ||
( ! V_131 && V_49 -> V_125 . V_58 [ 0 ] == '[' ) ) {
char V_132 [ 1024 ] ;
char * V_79 , * V_114 ;
if ( V_49 -> V_125 . V_58 [ 0 ] == '/' ) {
V_79 = strrchr ( V_49 -> V_125 . V_58 , '/' ) ;
if ( V_79 == NULL )
goto V_133;
++ V_79 ;
V_114 = strrchr ( V_79 , '.' ) ;
if ( V_114 == NULL )
goto V_133;
snprintf ( V_132 , sizeof( V_132 ) ,
L_30 , ( int ) ( V_114 - V_79 ) , V_79 ) ;
F_91 ( V_132 , '-' , '_' ) ;
} else
strcpy ( V_132 , V_49 -> V_125 . V_58 ) ;
V_56 = F_46 ( V_1 , V_49 -> V_125 . V_57 ,
V_49 -> V_125 . V_58 ) ;
if ( V_56 == NULL )
goto V_133;
V_79 = F_5 ( V_132 ) ;
if ( V_79 == NULL )
goto V_133;
V_56 -> V_18 -> V_134 = V_79 ;
V_56 -> V_18 -> V_135 = 1 ;
V_56 -> V_126 = V_56 -> V_57 + V_49 -> V_125 . V_127 ;
} else if ( V_131 ) {
const char * V_136 = ( V_49 -> V_125 . V_58 +
strlen ( V_128 ) ) ;
struct V_18 * V_74 = F_47 ( & V_1 -> V_7 ,
V_128 ) ;
if ( V_74 == NULL )
goto V_133;
V_74 -> V_74 = V_130 ;
if ( F_67 ( V_1 , V_74 ) < 0 )
goto V_133;
F_100 ( V_1 , V_49 ) ;
if ( V_49 -> V_125 . V_137 != 0 ) {
F_102 ( V_1 -> V_69 ,
V_136 ,
V_49 -> V_125 . V_137 ) ;
}
if ( F_37 ( V_1 ) ) {
F_103 ( V_74 , V_1 -> V_69 [ V_59 ] ,
NULL ) ;
}
}
return 0 ;
V_133:
return - 1 ;
}
int F_104 ( struct V_1 * V_1 , union V_48 * V_49 )
{
T_9 V_138 = V_49 -> V_139 . V_140 & V_141 ;
struct V_14 * V_14 ;
struct V_56 * V_56 ;
enum V_82 type ;
int V_64 = 0 ;
if ( V_51 )
F_105 ( V_49 , stdout ) ;
if ( V_138 == V_142 ||
V_138 == V_143 ) {
V_64 = F_101 ( V_1 , V_49 ) ;
if ( V_64 < 0 )
goto V_133;
return 0 ;
}
V_14 = F_6 ( V_1 , V_49 -> V_125 . V_3 ) ;
if ( V_14 == NULL )
goto V_133;
if ( V_49 -> V_139 . V_140 & V_144 )
type = V_145 ;
else
type = V_59 ;
V_56 = F_106 ( & V_1 -> V_6 , V_49 -> V_125 . V_57 ,
V_49 -> V_125 . V_127 , V_49 -> V_125 . V_137 ,
V_49 -> V_125 . V_3 , V_49 -> V_125 . V_58 ,
type ) ;
if ( V_56 == NULL )
goto V_133;
F_107 ( V_14 , V_56 ) ;
return 0 ;
V_133:
F_44 ( L_37 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_1 , union V_48 * V_49 )
{
struct V_14 * V_14 = F_6 ( V_1 , V_49 -> V_146 . V_50 ) ;
struct V_14 * V_28 = F_6 ( V_1 , V_49 -> V_146 . V_147 ) ;
if ( V_51 )
F_109 ( V_49 , stdout ) ;
if ( V_14 == NULL || V_28 == NULL ||
F_110 ( V_14 , V_28 ) < 0 ) {
F_44 ( L_38 ) ;
return - 1 ;
}
return 0 ;
}
static void F_111 ( struct V_1 * V_1 , struct V_14 * V_47 )
{
V_1 -> V_11 = NULL ;
F_17 ( & V_47 -> V_5 , & V_1 -> V_8 ) ;
F_112 ( & V_47 -> V_21 , & V_1 -> V_10 ) ;
}
int F_113 ( struct V_1 * V_1 , union V_48 * V_49 )
{
struct V_14 * V_14 = F_41 ( V_1 , V_49 -> V_146 . V_50 ) ;
if ( V_51 )
F_109 ( V_49 , stdout ) ;
if ( V_14 != NULL )
F_111 ( V_1 , V_14 ) ;
return 0 ;
}
int F_114 ( struct V_1 * V_1 , union V_48 * V_49 )
{
int V_64 ;
switch ( V_49 -> V_139 . type ) {
case V_148 :
V_64 = F_42 ( V_1 , V_49 ) ; break;
case V_149 :
V_64 = F_104 ( V_1 , V_49 ) ; break;
case V_150 :
V_64 = F_108 ( V_1 , V_49 ) ; break;
case V_151 :
V_64 = F_113 ( V_1 , V_49 ) ; break;
case V_152 :
V_64 = F_45 ( V_1 , V_49 ) ; break;
default:
V_64 = - 1 ;
break;
}
return V_64 ;
}
static bool F_115 ( struct V_153 * V_154 )
{
if ( V_154 -> V_79 && ! regexec ( & V_155 , V_154 -> V_79 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_116 ( struct V_1 * V_1 , struct V_14 * V_14 ,
struct V_156 * V_157 ,
T_5 V_158 )
{
struct V_159 V_160 ;
T_3 V_66 ;
T_9 V_161 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
for ( V_66 = 0 ; V_66 < V_162 ; V_66 ++ ) {
V_161 = V_163 [ V_66 ] ;
F_117 ( V_14 , V_1 , V_161 , V_59 ,
V_158 , & V_160 , NULL ) ;
if ( V_160 . V_154 )
goto V_164;
}
V_164:
V_157 -> V_165 = V_158 ;
V_157 -> V_166 = V_160 . V_165 ;
V_157 -> V_154 = V_160 . V_154 ;
V_157 -> V_56 = V_160 . V_56 ;
}
static void F_118 ( struct V_1 * V_1 , struct V_14 * V_14 ,
T_9 V_161 , struct V_156 * V_157 , T_5 V_165 )
{
struct V_159 V_160 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
F_117 ( V_14 , V_1 , V_161 , V_145 , V_165 , & V_160 ,
NULL ) ;
V_157 -> V_165 = V_165 ;
V_157 -> V_166 = V_160 . V_165 ;
V_157 -> V_154 = V_160 . V_154 ;
V_157 -> V_56 = V_160 . V_56 ;
}
struct V_167 * F_119 ( struct V_1 * V_1 ,
struct V_14 * V_168 ,
struct V_169 * V_170 ,
T_9 V_138 )
{
struct V_167 * V_171 = F_120 ( sizeof( * V_171 ) ) ;
if ( ! V_171 )
return NULL ;
F_116 ( V_1 , V_168 , & V_171 -> V_172 , V_170 -> V_158 ) ;
F_118 ( V_1 , V_168 , V_138 , & V_171 -> V_173 , V_170 -> V_165 ) ;
V_171 -> V_174 . V_175 = V_170 -> V_174 ;
return V_171 ;
}
struct V_176 * F_121 ( struct V_1 * V_1 ,
struct V_14 * V_168 ,
struct V_177 * V_178 )
{
struct V_176 * V_179 ;
unsigned int V_66 ;
V_179 = calloc ( V_178 -> V_180 , sizeof( struct V_176 ) ) ;
if ( ! V_179 )
return NULL ;
for ( V_66 = 0 ; V_66 < V_178 -> V_180 ; V_66 ++ ) {
F_116 ( V_1 , V_168 , & V_179 [ V_66 ] . V_181 , V_178 -> V_182 [ V_66 ] . V_181 ) ;
F_116 ( V_1 , V_168 , & V_179 [ V_66 ] . V_183 , V_178 -> V_182 [ V_66 ] . V_183 ) ;
V_179 [ V_66 ] . V_184 = V_178 -> V_182 [ V_66 ] . V_184 ;
}
return V_179 ;
}
static int F_122 ( struct V_1 * V_1 ,
struct V_14 * V_14 ,
struct V_185 * V_186 ,
struct V_153 * * V_28 )
{
T_9 V_138 = V_187 ;
unsigned int V_66 ;
int V_188 ;
F_123 ( & V_189 ) ;
if ( V_186 -> V_180 > V_190 ) {
F_124 ( L_39 ) ;
return 0 ;
}
for ( V_66 = 0 ; V_66 < V_186 -> V_180 ; V_66 ++ ) {
T_5 V_158 ;
struct V_159 V_160 ;
if ( V_191 . V_192 == V_193 )
V_158 = V_186 -> V_194 [ V_66 ] ;
else
V_158 = V_186 -> V_194 [ V_186 -> V_180 - V_66 - 1 ] ;
if ( V_158 >= V_195 ) {
switch ( V_158 ) {
case V_196 :
V_138 = V_197 ;
break;
case V_198 :
V_138 = V_143 ;
break;
case V_199 :
V_138 = V_187 ;
break;
default:
F_75 ( L_40
L_41 V_200 L_12 , ( V_201 ) V_158 ) ;
F_123 ( & V_189 ) ;
return 0 ;
}
continue;
}
V_160 . V_202 = false ;
F_117 ( V_14 , V_1 , V_138 ,
V_59 , V_158 , & V_160 , NULL ) ;
if ( V_160 . V_154 != NULL ) {
if ( V_203 && ! * V_28 &&
F_115 ( V_160 . V_154 ) )
* V_28 = V_160 . V_154 ;
if ( ! V_36 . V_204 )
break;
}
V_188 = F_125 ( & V_189 ,
V_158 , V_160 . V_56 , V_160 . V_154 ) ;
if ( V_188 )
return V_188 ;
}
return 0 ;
}
static int F_126 ( struct F_126 * V_205 , void * V_78 )
{
struct V_189 * V_206 = V_78 ;
return F_125 ( V_206 , V_205 -> V_158 ,
V_205 -> V_56 , V_205 -> V_154 ) ;
}
int F_127 ( struct V_1 * V_1 ,
struct V_207 * V_208 ,
struct V_14 * V_14 ,
struct V_169 * V_170 ,
struct V_153 * * V_28 )
{
int V_64 ;
F_123 ( & V_189 ) ;
V_64 = F_122 ( V_1 , V_14 ,
V_170 -> V_209 , V_28 ) ;
if ( V_64 )
return V_64 ;
if ( ! ( ( V_208 -> V_210 . V_211 & V_212 ) &&
( V_208 -> V_210 . V_211 & V_213 ) ) )
return 0 ;
if ( ( ! V_170 -> V_214 . V_215 ) ||
( ! V_170 -> V_216 . V_44 ) )
return 0 ;
return F_128 ( F_126 , & V_189 , V_1 ,
V_14 , V_208 -> V_210 . V_217 ,
V_170 ) ;
}
