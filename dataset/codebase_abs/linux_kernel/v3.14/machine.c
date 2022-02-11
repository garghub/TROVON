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
V_1 -> V_13 = 0 ;
V_1 -> V_2 = F_5 ( V_2 ) ;
if ( V_1 -> V_2 == NULL )
return - V_14 ;
if ( V_3 != V_15 ) {
struct V_16 * V_16 = F_6 ( V_1 , 0 ,
V_3 ) ;
char V_17 [ 64 ] ;
if ( V_16 == NULL )
return - V_14 ;
snprintf ( V_17 , sizeof( V_17 ) , L_1 , V_3 ) ;
F_7 ( V_16 , V_17 , 0 ) ;
}
return 0 ;
}
struct V_1 * F_8 ( void )
{
struct V_1 * V_1 = malloc ( sizeof( * V_1 ) ) ;
if ( V_1 != NULL ) {
F_1 ( V_1 , L_2 , V_15 ) ;
if ( F_9 ( V_1 ) < 0 )
goto V_18;
}
return V_1 ;
V_18:
free ( V_1 ) ;
return NULL ;
}
static void F_10 ( struct V_19 * V_20 )
{
struct V_21 * V_22 , * V_23 ;
F_11 (pos, n, dsos, node) {
F_12 ( & V_22 -> V_24 ) ;
F_13 ( V_22 ) ;
}
}
void F_14 ( struct V_1 * V_1 )
{
struct V_16 * V_23 , * V_25 ;
F_11 (t, n, &machine->dead_threads, node) {
F_12 ( & V_25 -> V_24 ) ;
F_15 ( V_25 ) ;
}
}
void F_16 ( struct V_1 * V_1 )
{
struct V_5 * V_26 = F_17 ( & V_1 -> V_8 ) ;
while ( V_26 ) {
struct V_16 * V_25 = F_18 ( V_26 , struct V_16 , V_5 ) ;
F_19 ( & V_25 -> V_5 , & V_1 -> V_8 ) ;
V_26 = F_20 ( V_26 ) ;
F_15 ( V_25 ) ;
}
}
void F_21 ( struct V_1 * V_1 )
{
F_22 ( & V_1 -> V_4 ) ;
F_10 ( & V_1 -> V_6 ) ;
F_10 ( & V_1 -> V_7 ) ;
F_23 ( & V_1 -> V_2 ) ;
}
void F_24 ( struct V_1 * V_1 )
{
F_21 ( V_1 ) ;
free ( V_1 ) ;
}
void F_25 ( struct V_27 * V_27 )
{
F_1 ( & V_27 -> V_28 , L_2 , V_15 ) ;
V_27 -> V_29 = V_9 ;
V_27 -> V_12 = NULL ;
}
void F_26 ( struct V_27 * V_27 )
{
F_21 ( & V_27 -> V_28 ) ;
}
struct V_1 * F_27 ( struct V_27 * V_27 , T_1 V_3 ,
const char * V_2 )
{
struct V_5 * * V_30 = & V_27 -> V_29 . V_5 ;
struct V_5 * V_31 = NULL ;
struct V_1 * V_22 , * V_1 = malloc ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_1 ( V_1 , V_2 , V_3 ) != 0 ) {
free ( V_1 ) ;
return NULL ;
}
V_1 -> V_12 = V_27 -> V_12 ;
while ( * V_30 != NULL ) {
V_31 = * V_30 ;
V_22 = F_18 ( V_31 , struct V_1 , V_5 ) ;
if ( V_3 < V_22 -> V_3 )
V_30 = & ( * V_30 ) -> V_32 ;
else
V_30 = & ( * V_30 ) -> V_33 ;
}
F_28 ( & V_1 -> V_5 , V_31 , V_30 ) ;
F_29 ( & V_1 -> V_5 , & V_27 -> V_29 ) ;
return V_1 ;
}
void F_30 ( struct V_27 * V_27 ,
T_2 V_12 )
{
struct V_5 * V_26 ;
V_27 -> V_12 = V_12 ;
V_27 -> V_28 . V_12 = V_12 ;
for ( V_26 = F_17 ( & V_27 -> V_29 ) ; V_26 ; V_26 = F_20 ( V_26 ) ) {
struct V_1 * V_1 = F_18 ( V_26 , struct V_1 , V_5 ) ;
V_1 -> V_12 = V_12 ;
}
}
struct V_1 * F_31 ( struct V_27 * V_27 , T_1 V_3 )
{
struct V_5 * * V_30 = & V_27 -> V_29 . V_5 ;
struct V_5 * V_31 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_34 = NULL ;
if ( V_3 == V_15 )
return & V_27 -> V_28 ;
while ( * V_30 != NULL ) {
V_31 = * V_30 ;
V_1 = F_18 ( V_31 , struct V_1 , V_5 ) ;
if ( V_3 < V_1 -> V_3 )
V_30 = & ( * V_30 ) -> V_32 ;
else if ( V_3 > V_1 -> V_3 )
V_30 = & ( * V_30 ) -> V_33 ;
else
return V_1 ;
if ( ! V_1 -> V_3 )
V_34 = V_1 ;
}
return V_34 ;
}
struct V_1 * F_32 ( struct V_27 * V_27 , T_1 V_3 )
{
char V_35 [ V_36 ] ;
const char * V_2 = L_2 ;
struct V_1 * V_1 = F_31 ( V_27 , V_3 ) ;
if ( V_1 && ( V_1 -> V_3 == V_3 ) )
goto V_37;
if ( ( V_3 != V_15 ) &&
( V_3 != V_38 ) &&
( V_39 . V_40 ) ) {
sprintf ( V_35 , L_3 , V_39 . V_40 , V_3 ) ;
if ( F_33 ( V_35 , V_41 ) ) {
static struct V_42 * V_43 ;
if ( ! V_43 )
V_43 = F_34 ( true , NULL ) ;
if ( ! F_35 ( V_43 , V_35 ) ) {
F_36 ( L_4 , V_35 ) ;
F_37 ( V_43 , V_35 ) ;
}
V_1 = NULL ;
goto V_37;
}
V_2 = V_35 ;
}
V_1 = F_27 ( V_27 , V_3 , V_2 ) ;
V_37:
return V_1 ;
}
void F_38 ( struct V_27 * V_27 ,
T_3 V_44 , void * V_45 )
{
struct V_5 * V_26 ;
for ( V_26 = F_17 ( & V_27 -> V_29 ) ; V_26 ; V_26 = F_20 ( V_26 ) ) {
struct V_1 * V_22 = F_18 ( V_26 , struct V_1 , V_5 ) ;
V_44 ( V_22 , V_45 ) ;
}
}
char * F_39 ( struct V_1 * V_1 , char * V_46 , T_4 V_47 )
{
if ( F_40 ( V_1 ) )
snprintf ( V_46 , V_47 , L_5 , L_6 ) ;
else if ( F_41 ( V_1 ) )
snprintf ( V_46 , V_47 , L_5 , L_7 ) ;
else {
snprintf ( V_46 , V_47 , L_8 , L_7 ,
V_1 -> V_3 ) ;
}
return V_46 ;
}
void F_42 ( struct V_27 * V_27 , T_5 V_13 )
{
struct V_5 * V_24 ;
struct V_1 * V_1 ;
V_27 -> V_28 . V_13 = V_13 ;
for ( V_24 = F_17 ( & V_27 -> V_29 ) ; V_24 ; V_24 = F_20 ( V_24 ) ) {
V_1 = F_18 ( V_24 , struct V_1 , V_5 ) ;
V_1 -> V_13 = V_13 ;
}
return;
}
static struct V_16 * F_43 ( struct V_1 * V_1 ,
T_1 V_3 , T_1 V_48 ,
bool V_49 )
{
struct V_5 * * V_30 = & V_1 -> V_8 . V_5 ;
struct V_5 * V_31 = NULL ;
struct V_16 * V_50 ;
if ( V_1 -> V_11 && V_1 -> V_11 -> V_48 == V_48 ) {
if ( V_3 && V_3 != V_1 -> V_11 -> V_51 )
V_1 -> V_11 -> V_51 = V_3 ;
return V_1 -> V_11 ;
}
while ( * V_30 != NULL ) {
V_31 = * V_30 ;
V_50 = F_18 ( V_31 , struct V_16 , V_5 ) ;
if ( V_50 -> V_48 == V_48 ) {
V_1 -> V_11 = V_50 ;
if ( V_3 && V_3 != V_50 -> V_51 )
V_50 -> V_51 = V_3 ;
return V_50 ;
}
if ( V_48 < V_50 -> V_48 )
V_30 = & ( * V_30 ) -> V_32 ;
else
V_30 = & ( * V_30 ) -> V_33 ;
}
if ( ! V_49 )
return NULL ;
V_50 = F_44 ( V_3 , V_48 ) ;
if ( V_50 != NULL ) {
F_28 ( & V_50 -> V_5 , V_31 , V_30 ) ;
F_29 ( & V_50 -> V_5 , & V_1 -> V_8 ) ;
V_1 -> V_11 = V_50 ;
}
return V_50 ;
}
struct V_16 * F_6 ( struct V_1 * V_1 , T_1 V_3 ,
T_1 V_48 )
{
return F_43 ( V_1 , V_3 , V_48 , true ) ;
}
struct V_16 * F_45 ( struct V_1 * V_1 , T_1 V_48 )
{
return F_43 ( V_1 , 0 , V_48 , false ) ;
}
int F_46 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_16 * V_16 = F_6 ( V_1 ,
V_53 -> V_17 . V_3 ,
V_53 -> V_17 . V_48 ) ;
if ( V_56 )
F_47 ( V_53 , stdout ) ;
if ( V_16 == NULL || F_7 ( V_16 , V_53 -> V_17 . V_17 , V_55 -> time ) ) {
F_48 ( L_9 ) ;
return - 1 ;
}
return 0 ;
}
int F_49 ( struct V_1 * V_1 V_57 ,
union V_52 * V_53 , struct V_54 * V_55 V_57 )
{
F_48 ( L_10 V_58 L_11 V_58 L_12 ,
V_53 -> V_59 . V_60 , V_53 -> V_59 . V_59 ) ;
return 0 ;
}
struct V_61 * F_50 ( struct V_1 * V_1 , T_6 V_62 ,
const char * V_63 )
{
struct V_61 * V_61 ;
struct V_21 * V_21 = F_51 ( & V_1 -> V_7 , V_63 ) ;
if ( V_21 == NULL )
return NULL ;
V_61 = F_52 ( V_62 , V_21 , V_64 ) ;
if ( V_61 == NULL )
return NULL ;
if ( F_40 ( V_1 ) )
V_21 -> V_65 = V_66 ;
else
V_21 -> V_65 = V_67 ;
F_53 ( & V_1 -> V_4 , V_61 ) ;
return V_61 ;
}
T_4 F_54 ( struct V_27 * V_27 , T_7 * V_68 )
{
struct V_5 * V_26 ;
T_4 V_69 = F_55 ( & V_27 -> V_28 . V_7 , V_68 ) +
F_55 ( & V_27 -> V_28 . V_6 , V_68 ) ;
for ( V_26 = F_17 ( & V_27 -> V_29 ) ; V_26 ; V_26 = F_20 ( V_26 ) ) {
struct V_1 * V_22 = F_18 ( V_26 , struct V_1 , V_5 ) ;
V_69 += F_55 ( & V_22 -> V_7 , V_68 ) ;
V_69 += F_55 ( & V_22 -> V_6 , V_68 ) ;
}
return V_69 ;
}
T_4 F_56 ( struct V_1 * V_1 , T_7 * V_68 ,
bool (F_57)( struct V_21 * V_21 , int V_70 ) , int V_70 )
{
return F_58 ( & V_1 -> V_7 , V_68 , F_57 , V_70 ) +
F_58 ( & V_1 -> V_6 , V_68 , F_57 , V_70 ) ;
}
T_4 F_59 ( struct V_27 * V_27 , T_7 * V_68 ,
bool (F_57)( struct V_21 * V_21 , int V_70 ) , int V_70 )
{
struct V_5 * V_26 ;
T_4 V_69 = F_56 ( & V_27 -> V_28 , V_68 , F_57 , V_70 ) ;
for ( V_26 = F_17 ( & V_27 -> V_29 ) ; V_26 ; V_26 = F_20 ( V_26 ) ) {
struct V_1 * V_22 = F_18 ( V_26 , struct V_1 , V_5 ) ;
V_69 += F_56 ( V_22 , V_68 , F_57 , V_70 ) ;
}
return V_69 ;
}
T_4 F_60 ( struct V_1 * V_1 , T_7 * V_68 )
{
int V_71 ;
T_4 V_72 = 0 ;
struct V_21 * V_73 = V_1 -> V_74 [ V_64 ] -> V_21 ;
if ( V_73 -> V_75 ) {
char V_63 [ V_36 ] ;
if ( F_61 ( V_73 , V_63 , sizeof( V_63 ) ) )
V_72 += fprintf ( V_68 , L_13 , V_63 ) ;
}
for ( V_71 = 0 ; V_71 < V_76 ; ++ V_71 )
V_72 += fprintf ( V_68 , L_14 ,
V_71 + V_73 -> V_75 , V_77 [ V_71 ] ) ;
return V_72 ;
}
T_4 F_62 ( struct V_1 * V_1 , T_7 * V_68 )
{
T_4 V_69 = 0 ;
struct V_5 * V_26 ;
for ( V_26 = F_17 ( & V_1 -> V_8 ) ; V_26 ; V_26 = F_20 ( V_26 ) ) {
struct V_16 * V_22 = F_18 ( V_26 , struct V_16 , V_5 ) ;
V_69 += F_63 ( V_22 , V_68 ) ;
}
return V_69 ;
}
static struct V_21 * F_64 ( struct V_1 * V_1 )
{
const char * V_78 = NULL ;
struct V_21 * V_79 ;
if ( F_40 ( V_1 ) ) {
V_78 = V_39 . V_78 ;
if ( ! V_78 )
V_78 = L_15 ;
V_79 = F_65 ( V_1 , V_78 ,
L_16 ,
V_80 ) ;
} else {
char V_46 [ V_36 ] ;
if ( F_41 ( V_1 ) )
V_78 = V_39 . V_81 ;
if ( ! V_78 )
V_78 = F_39 ( V_1 , V_46 ,
sizeof( V_46 ) ) ;
V_79 = F_65 ( V_1 , V_78 ,
L_17 ,
V_82 ) ;
}
if ( V_79 != NULL && ( ! V_79 -> V_75 ) )
F_66 ( V_79 , V_1 ) ;
return V_79 ;
}
static int F_67 ( void * V_83 , const char * V_84 ,
char type V_57 , T_6 V_62 )
{
struct V_85 * args = V_83 ;
if ( strchr ( V_84 , '[' ) )
return 0 ;
args -> V_62 = V_62 ;
return 1 ;
}
static void F_68 ( struct V_1 * V_1 , char * V_86 ,
T_4 V_87 )
{
if ( F_41 ( V_1 ) )
F_69 ( V_86 , V_87 , L_18 , V_39 . V_88 ) ;
else
F_69 ( V_86 , V_87 , L_19 , V_1 -> V_2 ) ;
}
static T_6 F_70 ( struct V_1 * V_1 )
{
char V_63 [ V_36 ] ;
struct V_85 args ;
F_68 ( V_1 , V_63 , V_36 ) ;
if ( F_71 ( V_63 , L_20 ) )
return 0 ;
if ( F_72 ( V_63 , & args , F_67 ) <= 0 )
return 0 ;
return args . V_62 ;
}
int F_73 ( struct V_1 * V_1 , struct V_21 * V_79 )
{
enum V_89 type ;
T_6 V_62 = F_70 ( V_1 ) ;
for ( type = 0 ; type < V_90 ; ++ type ) {
struct V_91 * V_91 ;
V_1 -> V_74 [ type ] = F_52 ( V_62 , V_79 , type ) ;
if ( V_1 -> V_74 [ type ] == NULL )
return - 1 ;
V_1 -> V_74 [ type ] -> V_92 =
V_1 -> V_74 [ type ] -> V_93 =
V_94 ;
V_91 = F_74 ( V_1 -> V_74 [ type ] ) ;
V_91 -> V_4 = & V_1 -> V_4 ;
F_53 ( & V_1 -> V_4 ,
V_1 -> V_74 [ type ] ) ;
}
return 0 ;
}
void F_75 ( struct V_1 * V_1 )
{
enum V_89 type ;
for ( type = 0 ; type < V_90 ; ++ type ) {
struct V_91 * V_91 ;
if ( V_1 -> V_74 [ type ] == NULL )
continue;
V_91 = F_74 ( V_1 -> V_74 [ type ] ) ;
F_76 ( & V_1 -> V_4 ,
V_1 -> V_74 [ type ] ) ;
if ( V_91 -> V_95 ) {
if ( type == V_64 ) {
F_23 ( ( char * * ) & V_91 -> V_95 -> V_84 ) ;
F_23 ( & V_91 -> V_95 ) ;
} else
V_91 -> V_95 = NULL ;
}
F_77 ( V_1 -> V_74 [ type ] ) ;
V_1 -> V_74 [ type ] = NULL ;
}
}
int F_78 ( struct V_27 * V_27 )
{
int V_69 = 0 ;
struct V_96 * * V_97 = NULL ;
int V_71 , V_98 = 0 ;
char V_35 [ V_36 ] ;
T_1 V_3 ;
char * V_99 ;
if ( V_39 . V_81 ||
V_39 . V_100 ||
V_39 . V_88 ) {
F_79 ( V_27 , V_38 ) ;
}
if ( V_39 . V_40 ) {
V_98 = F_80 ( V_39 . V_40 , & V_97 , NULL , NULL ) ;
if ( V_98 <= 0 )
return - V_101 ;
for ( V_71 = 0 ; V_71 < V_98 ; V_71 ++ ) {
if ( ! isdigit ( V_97 [ V_71 ] -> V_102 [ 0 ] ) ) {
continue;
}
V_3 = ( T_1 ) strtol ( V_97 [ V_71 ] -> V_102 , & V_99 , 10 ) ;
if ( ( * V_99 != '\0' ) ||
( V_99 == V_97 [ V_71 ] -> V_102 ) ||
( V_103 == V_104 ) ) {
F_81 ( L_21 ,
V_97 [ V_71 ] -> V_102 ) ;
continue;
}
sprintf ( V_35 , L_22 ,
V_39 . V_40 ,
V_97 [ V_71 ] -> V_102 ) ;
V_69 = F_33 ( V_35 , V_41 ) ;
if ( V_69 ) {
F_81 ( L_4 , V_35 ) ;
goto V_105;
}
F_79 ( V_27 , V_3 ) ;
}
V_105:
free ( V_97 ) ;
}
return V_69 ;
}
void F_82 ( struct V_27 * V_27 )
{
struct V_5 * V_106 = F_17 ( & V_27 -> V_29 ) ;
F_75 ( & V_27 -> V_28 ) ;
while ( V_106 ) {
struct V_1 * V_22 = F_18 ( V_106 , struct V_1 , V_5 ) ;
V_106 = F_20 ( & V_22 -> V_5 ) ;
F_19 ( & V_22 -> V_5 , & V_27 -> V_29 ) ;
F_24 ( V_22 ) ;
}
}
int F_79 ( struct V_27 * V_27 , T_1 V_3 )
{
struct V_1 * V_1 = F_32 ( V_27 , V_3 ) ;
if ( V_1 == NULL )
return - 1 ;
return F_9 ( V_1 ) ;
}
int F_83 ( struct V_1 * V_1 , const char * V_63 ,
enum V_89 type , T_2 V_107 )
{
struct V_61 * V_61 = V_1 -> V_74 [ type ] ;
int V_69 = F_84 ( V_61 -> V_21 , V_63 , V_61 , V_107 ) ;
if ( V_69 > 0 ) {
F_85 ( V_61 -> V_21 , type ) ;
F_86 ( & V_1 -> V_4 , type ) ;
}
return V_69 ;
}
int F_87 ( struct V_1 * V_1 , enum V_89 type ,
T_2 V_107 )
{
struct V_61 * V_61 = V_1 -> V_74 [ type ] ;
int V_69 = F_88 ( V_61 -> V_21 , V_61 , V_107 ) ;
if ( V_69 > 0 )
F_85 ( V_61 -> V_21 , type ) ;
return V_69 ;
}
static void F_89 ( struct V_108 * V_109 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_90 ; ++ V_71 )
F_86 ( V_109 , V_71 ) ;
}
static char * F_90 ( const char * V_2 )
{
char V_110 [ V_36 ] ;
T_7 * V_111 ;
char * V_84 , * V_112 ;
const char * V_113 = L_23 ;
sprintf ( V_110 , L_24 , V_2 ) ;
V_111 = fopen ( V_110 , L_25 ) ;
if ( ! V_111 )
return NULL ;
V_110 [ 0 ] = '\0' ;
V_112 = fgets ( V_110 , sizeof( V_110 ) , V_111 ) ;
fclose ( V_111 ) ;
V_84 = strstr ( V_110 , V_113 ) ;
if ( ! V_84 )
return NULL ;
V_84 += strlen ( V_113 ) ;
V_112 = strchr ( V_84 , ' ' ) ;
if ( V_112 )
* V_112 = '\0' ;
return F_5 ( V_84 ) ;
}
static int F_91 ( struct V_108 * V_109 ,
const char * V_114 )
{
struct V_96 * V_115 ;
T_8 * V_116 = F_92 ( V_114 ) ;
int V_69 = 0 ;
if ( ! V_116 ) {
F_81 ( L_26 , V_117 , V_114 ) ;
return - 1 ;
}
while ( ( V_115 = F_93 ( V_116 ) ) != NULL ) {
char V_35 [ V_36 ] ;
struct V_118 V_119 ;
snprintf ( V_35 , sizeof( V_35 ) , L_27 , V_114 , V_115 -> V_102 ) ;
if ( V_118 ( V_35 , & V_119 ) )
continue;
if ( F_94 ( V_119 . V_120 ) ) {
if ( ! strcmp ( V_115 -> V_102 , L_28 ) ||
! strcmp ( V_115 -> V_102 , L_29 ) )
continue;
V_69 = F_91 ( V_109 , V_35 ) ;
if ( V_69 < 0 )
goto V_37;
} else {
char * V_121 = strrchr ( V_115 -> V_102 , '.' ) ,
V_122 [ V_36 ] ;
struct V_61 * V_61 ;
char * V_123 ;
if ( V_121 == NULL || strcmp ( V_121 , L_30 ) )
continue;
snprintf ( V_122 , sizeof( V_122 ) , L_31 ,
( int ) ( V_121 - V_115 -> V_102 ) , V_115 -> V_102 ) ;
F_95 ( V_122 , '-' , '_' ) ;
V_61 = F_96 ( V_109 , V_64 ,
V_122 ) ;
if ( V_61 == NULL )
continue;
V_123 = F_5 ( V_35 ) ;
if ( V_123 == NULL ) {
V_69 = - 1 ;
goto V_37;
}
F_97 ( V_61 -> V_21 , V_123 , true ) ;
F_98 ( V_61 -> V_21 , L_2 ) ;
}
}
V_37:
F_99 ( V_116 ) ;
return V_69 ;
}
static int F_100 ( struct V_1 * V_1 )
{
char * V_110 ;
char V_124 [ V_36 ] ;
V_110 = F_90 ( V_1 -> V_2 ) ;
if ( ! V_110 )
return - 1 ;
snprintf ( V_124 , sizeof( V_124 ) , L_32 ,
V_1 -> V_2 , V_110 ) ;
free ( V_110 ) ;
return F_91 ( & V_1 -> V_4 , V_124 ) ;
}
static int F_101 ( void * V_83 , const char * V_84 , T_6 V_62 )
{
struct V_1 * V_1 = V_83 ;
struct V_61 * V_61 ;
V_61 = F_50 ( V_1 , V_62 , V_84 ) ;
if ( V_61 == NULL )
return - 1 ;
F_98 ( V_61 -> V_21 , V_1 -> V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_1 )
{
const char * V_125 ;
char V_35 [ V_36 ] ;
if ( F_41 ( V_1 ) ) {
V_125 = V_39 . V_100 ;
} else {
snprintf ( V_35 , V_36 , L_33 , V_1 -> V_2 ) ;
V_125 = V_35 ;
}
if ( F_71 ( V_125 , L_34 ) )
return - 1 ;
if ( F_103 ( V_125 , V_1 , F_101 ) )
return - 1 ;
if ( ! F_100 ( V_1 ) )
return 0 ;
F_81 ( L_35 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 )
{
struct V_21 * V_79 = F_64 ( V_1 ) ;
char V_63 [ V_36 ] ;
const char * V_84 ;
T_6 V_126 = 0 ;
int V_71 ;
F_68 ( V_1 , V_63 , V_36 ) ;
for ( V_71 = 0 ; ( V_84 = V_127 [ V_71 ] ) != NULL ; V_71 ++ ) {
V_126 = F_104 ( V_63 , V_84 ) ;
if ( V_126 )
break;
}
if ( ! V_126 )
return - 1 ;
if ( V_79 == NULL ||
F_73 ( V_1 , V_79 ) < 0 )
return - 1 ;
if ( V_39 . V_128 && F_102 ( V_1 ) < 0 ) {
if ( F_40 ( V_1 ) )
F_81 ( L_36
L_37 ) ;
else
F_81 ( L_38
L_37 , V_1 -> V_3 ) ;
}
F_89 ( & V_1 -> V_4 ) ;
if ( F_105 ( V_1 -> V_74 , V_84 ,
V_126 ) ) {
F_75 ( V_1 ) ;
return - 1 ;
}
return 0 ;
}
static void F_106 ( struct V_1 * V_1 ,
union V_52 * V_53 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_90 ; V_71 ++ ) {
V_1 -> V_74 [ V_71 ] -> V_62 = V_53 -> V_129 . V_62 ;
V_1 -> V_74 [ V_71 ] -> V_130 = ( V_53 -> V_129 . V_62 +
V_53 -> V_129 . V_131 ) ;
if ( V_1 -> V_74 [ V_71 ] -> V_130 == 0 )
V_1 -> V_74 [ V_71 ] -> V_130 = ~ 0ULL ;
}
}
static bool F_107 ( struct V_1 * V_1 )
{
struct V_21 * V_21 ;
F_108 (dso, &machine->kernel_dsos, node) {
if ( F_109 ( V_21 ) )
return true ;
}
return false ;
}
static int F_110 ( struct V_1 * V_1 ,
union V_52 * V_53 )
{
struct V_61 * V_61 ;
char V_132 [ V_36 ] ;
enum V_133 V_134 ;
bool V_135 ;
if ( F_107 ( V_1 ) )
return 0 ;
F_39 ( V_1 , V_132 , sizeof( V_132 ) ) ;
if ( F_40 ( V_1 ) )
V_134 = V_80 ;
else
V_134 = V_82 ;
V_135 = memcmp ( V_53 -> V_129 . V_63 ,
V_132 ,
strlen ( V_132 ) - 1 ) == 0 ;
if ( V_53 -> V_129 . V_63 [ 0 ] == '/' ||
( ! V_135 && V_53 -> V_129 . V_63 [ 0 ] == '[' ) ) {
char V_136 [ 1024 ] ;
char * V_84 , * V_121 ;
if ( V_53 -> V_129 . V_63 [ 0 ] == '/' ) {
V_84 = strrchr ( V_53 -> V_129 . V_63 , '/' ) ;
if ( V_84 == NULL )
goto V_137;
++ V_84 ;
V_121 = strrchr ( V_84 , '.' ) ;
if ( V_121 == NULL )
goto V_137;
snprintf ( V_136 , sizeof( V_136 ) ,
L_31 , ( int ) ( V_121 - V_84 ) , V_84 ) ;
F_95 ( V_136 , '-' , '_' ) ;
} else
strcpy ( V_136 , V_53 -> V_129 . V_63 ) ;
V_61 = F_50 ( V_1 , V_53 -> V_129 . V_62 ,
V_53 -> V_129 . V_63 ) ;
if ( V_61 == NULL )
goto V_137;
V_84 = F_5 ( V_136 ) ;
if ( V_84 == NULL )
goto V_137;
F_111 ( V_61 -> V_21 , V_84 , true ) ;
V_61 -> V_130 = V_61 -> V_62 + V_53 -> V_129 . V_131 ;
} else if ( V_135 ) {
const char * V_138 = ( V_53 -> V_129 . V_63 +
strlen ( V_132 ) ) ;
struct V_21 * V_79 = F_51 ( & V_1 -> V_7 ,
V_132 ) ;
if ( V_79 == NULL )
goto V_137;
V_79 -> V_79 = V_134 ;
if ( F_73 ( V_1 , V_79 ) < 0 )
goto V_137;
F_106 ( V_1 , V_53 ) ;
if ( V_53 -> V_129 . V_139 != 0 ) {
F_105 ( V_1 -> V_74 ,
V_138 ,
V_53 -> V_129 . V_139 ) ;
}
if ( F_41 ( V_1 ) ) {
F_112 ( V_79 , V_1 -> V_74 [ V_64 ] ,
NULL ) ;
}
}
return 0 ;
V_137:
return - 1 ;
}
int F_113 ( struct V_1 * V_1 ,
union V_52 * V_53 ,
struct V_54 * V_55 V_57 )
{
T_9 V_140 = V_53 -> V_141 . V_142 & V_143 ;
struct V_16 * V_16 ;
struct V_61 * V_61 ;
enum V_89 type ;
int V_69 = 0 ;
if ( V_56 )
F_114 ( V_53 , stdout ) ;
if ( V_140 == V_144 ||
V_140 == V_145 ) {
V_69 = F_110 ( V_1 , V_53 ) ;
if ( V_69 < 0 )
goto V_137;
return 0 ;
}
V_16 = F_6 ( V_1 , V_53 -> V_146 . V_3 ,
V_53 -> V_146 . V_3 ) ;
if ( V_16 == NULL )
goto V_137;
if ( V_53 -> V_141 . V_142 & V_147 )
type = V_148 ;
else
type = V_64 ;
V_61 = F_115 ( & V_1 -> V_6 , V_53 -> V_146 . V_62 ,
V_53 -> V_146 . V_131 , V_53 -> V_146 . V_139 ,
V_53 -> V_146 . V_3 , V_53 -> V_146 . V_149 ,
V_53 -> V_146 . V_150 , V_53 -> V_146 . V_151 ,
V_53 -> V_146 . V_152 ,
V_53 -> V_146 . V_63 , type ) ;
if ( V_61 == NULL )
goto V_137;
F_116 ( V_16 , V_61 ) ;
return 0 ;
V_137:
F_48 ( L_39 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 V_57 )
{
T_9 V_140 = V_53 -> V_141 . V_142 & V_143 ;
struct V_16 * V_16 ;
struct V_61 * V_61 ;
enum V_89 type ;
int V_69 = 0 ;
if ( V_56 )
F_118 ( V_53 , stdout ) ;
if ( V_140 == V_144 ||
V_140 == V_145 ) {
V_69 = F_110 ( V_1 , V_53 ) ;
if ( V_69 < 0 )
goto V_137;
return 0 ;
}
V_16 = F_6 ( V_1 , V_53 -> V_129 . V_3 ,
V_53 -> V_129 . V_3 ) ;
if ( V_16 == NULL )
goto V_137;
if ( V_53 -> V_141 . V_142 & V_147 )
type = V_148 ;
else
type = V_64 ;
V_61 = F_115 ( & V_1 -> V_6 , V_53 -> V_129 . V_62 ,
V_53 -> V_129 . V_131 , V_53 -> V_129 . V_139 ,
V_53 -> V_129 . V_3 , 0 , 0 , 0 , 0 ,
V_53 -> V_129 . V_63 ,
type ) ;
if ( V_61 == NULL )
goto V_137;
F_116 ( V_16 , V_61 ) ;
return 0 ;
V_137:
F_48 ( L_40 ) ;
return 0 ;
}
static void F_119 ( struct V_1 * V_1 , struct V_16 * V_50 )
{
V_1 -> V_11 = NULL ;
F_19 ( & V_50 -> V_5 , & V_1 -> V_8 ) ;
F_120 ( & V_50 -> V_24 , & V_1 -> V_10 ) ;
}
int F_121 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_16 * V_16 = F_45 ( V_1 , V_53 -> V_153 . V_48 ) ;
struct V_16 * V_31 = F_6 ( V_1 ,
V_53 -> V_153 . V_154 ,
V_53 -> V_153 . V_155 ) ;
if ( V_16 != NULL )
F_119 ( V_1 , V_16 ) ;
V_16 = F_6 ( V_1 , V_53 -> V_153 . V_3 ,
V_53 -> V_153 . V_48 ) ;
if ( V_56 )
F_122 ( V_53 , stdout ) ;
if ( V_16 == NULL || V_31 == NULL ||
F_123 ( V_16 , V_31 , V_55 -> time ) < 0 ) {
F_48 ( L_41 ) ;
return - 1 ;
}
return 0 ;
}
int F_124 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 V_57 )
{
struct V_16 * V_16 = F_45 ( V_1 , V_53 -> V_153 . V_48 ) ;
if ( V_56 )
F_122 ( V_53 , stdout ) ;
if ( V_16 != NULL )
F_125 ( V_16 ) ;
return 0 ;
}
int F_126 ( struct V_1 * V_1 , union V_52 * V_53 ,
struct V_54 * V_55 )
{
int V_69 ;
switch ( V_53 -> V_141 . type ) {
case V_156 :
V_69 = F_46 ( V_1 , V_53 , V_55 ) ; break;
case V_157 :
V_69 = F_117 ( V_1 , V_53 , V_55 ) ; break;
case V_158 :
V_69 = F_113 ( V_1 , V_53 , V_55 ) ; break;
case V_159 :
V_69 = F_121 ( V_1 , V_53 , V_55 ) ; break;
case V_160 :
V_69 = F_124 ( V_1 , V_53 , V_55 ) ; break;
case V_161 :
V_69 = F_49 ( V_1 , V_53 , V_55 ) ; break;
default:
V_69 = - 1 ;
break;
}
return V_69 ;
}
static bool F_127 ( struct V_162 * V_163 , T_10 * V_164 )
{
if ( V_163 -> V_84 && ! regexec ( V_164 , V_163 -> V_84 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_128 ( struct V_1 * V_1 , struct V_16 * V_16 ,
struct V_165 * V_166 ,
T_6 V_167 )
{
struct V_168 V_169 ;
T_4 V_71 ;
T_9 V_170 ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
for ( V_71 = 0 ; V_71 < V_171 ; V_71 ++ ) {
V_170 = V_172 [ V_71 ] ;
F_129 ( V_16 , V_1 , V_170 , V_64 ,
V_167 , & V_169 ) ;
if ( V_169 . V_61 )
goto V_173;
}
V_173:
V_166 -> V_126 = V_167 ;
V_166 -> V_174 = V_169 . V_126 ;
V_166 -> V_163 = V_169 . V_163 ;
V_166 -> V_61 = V_169 . V_61 ;
}
static void F_130 ( struct V_1 * V_1 , struct V_16 * V_16 ,
T_9 V_170 , struct V_165 * V_166 , T_6 V_126 )
{
struct V_168 V_169 ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
F_129 ( V_16 , V_1 , V_170 , V_148 , V_126 ,
& V_169 ) ;
V_166 -> V_126 = V_126 ;
V_166 -> V_174 = V_169 . V_126 ;
V_166 -> V_163 = V_169 . V_163 ;
V_166 -> V_61 = V_169 . V_61 ;
}
struct V_175 * F_131 ( struct V_1 * V_1 ,
struct V_16 * V_176 ,
struct V_54 * V_55 ,
T_9 V_140 )
{
struct V_175 * V_177 = F_132 ( sizeof( * V_177 ) ) ;
if ( ! V_177 )
return NULL ;
F_128 ( V_1 , V_176 , & V_177 -> V_178 , V_55 -> V_167 ) ;
F_130 ( V_1 , V_176 , V_140 , & V_177 -> V_179 , V_55 -> V_126 ) ;
V_177 -> V_180 . V_181 = V_55 -> V_180 ;
return V_177 ;
}
struct V_182 * F_133 ( struct V_1 * V_1 ,
struct V_16 * V_176 ,
struct V_183 * V_184 )
{
struct V_182 * V_185 ;
unsigned int V_71 ;
V_185 = calloc ( V_184 -> V_186 , sizeof( struct V_182 ) ) ;
if ( ! V_185 )
return NULL ;
for ( V_71 = 0 ; V_71 < V_184 -> V_186 ; V_71 ++ ) {
F_128 ( V_1 , V_176 , & V_185 [ V_71 ] . V_187 , V_184 -> V_188 [ V_71 ] . V_187 ) ;
F_128 ( V_1 , V_176 , & V_185 [ V_71 ] . V_189 , V_184 -> V_188 [ V_71 ] . V_189 ) ;
V_185 [ V_71 ] . V_190 = V_184 -> V_188 [ V_71 ] . V_190 ;
}
return V_185 ;
}
static int F_134 ( struct V_1 * V_1 ,
struct V_16 * V_16 ,
struct V_191 * V_192 ,
struct V_162 * * V_31 ,
struct V_168 * V_193 ,
int V_194 )
{
T_9 V_140 = V_195 ;
int V_196 = V_150 ( V_194 , ( int ) V_192 -> V_186 ) ;
int V_71 ;
int V_197 ;
F_135 ( & V_198 ) ;
if ( V_192 -> V_186 > V_199 ) {
F_136 ( L_42 ) ;
return 0 ;
}
for ( V_71 = 0 ; V_71 < V_196 ; V_71 ++ ) {
T_6 V_167 ;
struct V_168 V_169 ;
if ( V_200 . V_201 == V_202 )
V_167 = V_192 -> V_203 [ V_71 ] ;
else
V_167 = V_192 -> V_203 [ V_192 -> V_186 - V_71 - 1 ] ;
if ( V_167 >= V_204 ) {
switch ( V_167 ) {
case V_205 :
V_140 = V_206 ;
break;
case V_207 :
V_140 = V_145 ;
break;
case V_208 :
V_140 = V_195 ;
break;
default:
F_81 ( L_43
L_44 V_209 L_12 , ( V_210 ) V_167 ) ;
F_135 ( & V_198 ) ;
return 0 ;
}
continue;
}
V_169 . V_211 = false ;
F_129 ( V_16 , V_1 , V_140 ,
V_64 , V_167 , & V_169 ) ;
if ( V_169 . V_163 != NULL ) {
if ( V_212 && ! * V_31 &&
F_127 ( V_169 . V_163 , & V_213 ) )
* V_31 = V_169 . V_163 ;
else if ( V_214 && V_193 &&
F_127 ( V_169 . V_163 , & V_215 ) ) {
* V_193 = V_169 ;
F_135 ( & V_198 ) ;
}
}
V_197 = F_137 ( & V_198 ,
V_167 , V_169 . V_61 , V_169 . V_163 ) ;
if ( V_197 )
return V_197 ;
}
return 0 ;
}
static int F_138 ( struct F_138 * V_216 , void * V_83 )
{
struct V_198 * V_217 = V_83 ;
return F_137 ( V_217 , V_216 -> V_167 ,
V_216 -> V_61 , V_216 -> V_163 ) ;
}
int F_139 ( struct V_1 * V_1 ,
struct V_218 * V_219 ,
struct V_16 * V_16 ,
struct V_54 * V_55 ,
struct V_162 * * V_31 ,
struct V_168 * V_193 ,
int V_194 )
{
int V_69 ;
V_69 = F_134 ( V_1 , V_16 ,
V_55 -> V_220 , V_31 ,
V_193 , V_194 ) ;
if ( V_69 )
return V_69 ;
if ( ! ( ( V_219 -> V_221 . V_222 & V_223 ) &&
( V_219 -> V_221 . V_222 & V_224 ) ) )
return 0 ;
if ( ( ! V_55 -> V_225 . V_226 ) ||
( ! V_55 -> V_227 . V_47 ) )
return 0 ;
return F_140 ( F_138 , & V_198 , V_1 ,
V_16 , V_219 -> V_221 . V_228 ,
V_55 , V_194 ) ;
}
int F_141 ( struct V_1 * V_1 ,
int (* F_142)( struct V_16 * V_16 , void * V_30 ) ,
void * V_229 )
{
struct V_5 * V_26 ;
struct V_16 * V_16 ;
int V_230 = 0 ;
for ( V_26 = F_17 ( & V_1 -> V_8 ) ; V_26 ; V_26 = F_20 ( V_26 ) ) {
V_16 = F_18 ( V_26 , struct V_16 , V_5 ) ;
V_230 = F_142 ( V_16 , V_229 ) ;
if ( V_230 != 0 )
return V_230 ;
}
F_108 (thread, &machine->dead_threads, node) {
V_230 = F_142 ( V_16 , V_229 ) ;
if ( V_230 != 0 )
return V_230 ;
}
return V_230 ;
}
int F_143 ( struct V_1 * V_1 , struct V_231 * V_232 ,
struct V_233 * V_233 , struct V_234 * V_8 ,
T_11 V_44 , bool V_235 )
{
if ( F_144 ( V_233 ) )
return F_145 ( V_232 , V_8 , V_44 , V_1 , V_235 ) ;
else if ( F_146 ( V_233 ) )
return F_147 ( V_232 , V_44 , V_1 , V_235 ) ;
return 0 ;
}
