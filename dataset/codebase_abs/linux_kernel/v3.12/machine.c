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
F_7 ( V_15 , V_16 ) ;
}
return 0 ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_19 * V_20 , * V_21 ;
F_9 (pos, n, dsos, node) {
F_10 ( & V_20 -> V_22 ) ;
F_11 ( V_20 ) ;
}
}
void F_12 ( struct V_1 * V_1 )
{
struct V_15 * V_21 , * V_23 ;
F_9 (t, n, &machine->dead_threads, node) {
F_10 ( & V_23 -> V_22 ) ;
F_13 ( V_23 ) ;
}
}
void F_14 ( struct V_1 * V_1 )
{
struct V_5 * V_24 = F_15 ( & V_1 -> V_8 ) ;
while ( V_24 ) {
struct V_15 * V_23 = F_16 ( V_24 , struct V_15 , V_5 ) ;
F_17 ( & V_23 -> V_5 , & V_1 -> V_8 ) ;
V_24 = F_18 ( V_24 ) ;
F_13 ( V_23 ) ;
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
void F_22 ( struct V_25 * V_25 )
{
F_1 ( & V_25 -> V_26 , L_2 , V_14 ) ;
V_25 -> V_27 = V_9 ;
V_25 -> V_12 = NULL ;
}
void F_23 ( struct V_25 * V_25 )
{
F_19 ( & V_25 -> V_26 ) ;
}
struct V_1 * F_24 ( struct V_25 * V_25 , T_1 V_3 ,
const char * V_2 )
{
struct V_5 * * V_28 = & V_25 -> V_27 . V_5 ;
struct V_5 * V_29 = NULL ;
struct V_1 * V_20 , * V_1 = malloc ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_1 ( V_1 , V_2 , V_3 ) != 0 ) {
free ( V_1 ) ;
return NULL ;
}
V_1 -> V_12 = V_25 -> V_12 ;
while ( * V_28 != NULL ) {
V_29 = * V_28 ;
V_20 = F_16 ( V_29 , struct V_1 , V_5 ) ;
if ( V_3 < V_20 -> V_3 )
V_28 = & ( * V_28 ) -> V_30 ;
else
V_28 = & ( * V_28 ) -> V_31 ;
}
F_25 ( & V_1 -> V_5 , V_29 , V_28 ) ;
F_26 ( & V_1 -> V_5 , & V_25 -> V_27 ) ;
return V_1 ;
}
void F_27 ( struct V_25 * V_25 ,
T_2 V_12 )
{
struct V_5 * V_24 ;
V_25 -> V_12 = V_12 ;
V_25 -> V_26 . V_12 = V_12 ;
for ( V_24 = F_15 ( & V_25 -> V_27 ) ; V_24 ; V_24 = F_18 ( V_24 ) ) {
struct V_1 * V_1 = F_16 ( V_24 , struct V_1 , V_5 ) ;
V_1 -> V_12 = V_12 ;
}
}
struct V_1 * F_28 ( struct V_25 * V_25 , T_1 V_3 )
{
struct V_5 * * V_28 = & V_25 -> V_27 . V_5 ;
struct V_5 * V_29 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_32 = NULL ;
if ( V_3 == V_14 )
return & V_25 -> V_26 ;
while ( * V_28 != NULL ) {
V_29 = * V_28 ;
V_1 = F_16 ( V_29 , struct V_1 , V_5 ) ;
if ( V_3 < V_1 -> V_3 )
V_28 = & ( * V_28 ) -> V_30 ;
else if ( V_3 > V_1 -> V_3 )
V_28 = & ( * V_28 ) -> V_31 ;
else
return V_1 ;
if ( ! V_1 -> V_3 )
V_32 = V_1 ;
}
return V_32 ;
}
struct V_1 * F_29 ( struct V_25 * V_25 , T_1 V_3 )
{
char V_33 [ V_34 ] ;
const char * V_2 = L_2 ;
struct V_1 * V_1 = F_28 ( V_25 , V_3 ) ;
if ( V_1 && ( V_1 -> V_3 == V_3 ) )
goto V_35;
if ( ( V_3 != V_14 ) &&
( V_3 != V_36 ) &&
( V_37 . V_38 ) ) {
sprintf ( V_33 , L_3 , V_37 . V_38 , V_3 ) ;
if ( F_30 ( V_33 , V_39 ) ) {
static struct V_40 * V_41 ;
if ( ! V_41 )
V_41 = F_31 ( true , NULL ) ;
if ( ! F_32 ( V_41 , V_33 ) ) {
F_33 ( L_4 , V_33 ) ;
F_34 ( V_41 , V_33 ) ;
}
V_1 = NULL ;
goto V_35;
}
V_2 = V_33 ;
}
V_1 = F_24 ( V_25 , V_3 , V_2 ) ;
V_35:
return V_1 ;
}
void F_35 ( struct V_25 * V_25 ,
T_3 V_42 , void * V_43 )
{
struct V_5 * V_24 ;
for ( V_24 = F_15 ( & V_25 -> V_27 ) ; V_24 ; V_24 = F_18 ( V_24 ) ) {
struct V_1 * V_20 = F_16 ( V_24 , struct V_1 , V_5 ) ;
V_42 ( V_20 , V_43 ) ;
}
}
char * F_36 ( struct V_1 * V_1 , char * V_44 , T_4 V_45 )
{
if ( F_37 ( V_1 ) )
snprintf ( V_44 , V_45 , L_5 , L_6 ) ;
else if ( F_38 ( V_1 ) )
snprintf ( V_44 , V_45 , L_5 , L_7 ) ;
else {
snprintf ( V_44 , V_45 , L_8 , L_7 ,
V_1 -> V_3 ) ;
}
return V_44 ;
}
void F_39 ( struct V_25 * V_25 , T_5 V_46 )
{
struct V_5 * V_22 ;
struct V_1 * V_1 ;
V_25 -> V_26 . V_46 = V_46 ;
for ( V_22 = F_15 ( & V_25 -> V_27 ) ; V_22 ; V_22 = F_18 ( V_22 ) ) {
V_1 = F_16 ( V_22 , struct V_1 , V_5 ) ;
V_1 -> V_46 = V_46 ;
}
return;
}
static struct V_15 * F_40 ( struct V_1 * V_1 ,
T_1 V_3 , T_1 V_47 ,
bool V_48 )
{
struct V_5 * * V_28 = & V_1 -> V_8 . V_5 ;
struct V_5 * V_29 = NULL ;
struct V_15 * V_49 ;
if ( V_1 -> V_11 && V_1 -> V_11 -> V_47 == V_47 ) {
if ( V_3 && V_3 != V_1 -> V_11 -> V_50 )
V_1 -> V_11 -> V_50 = V_3 ;
return V_1 -> V_11 ;
}
while ( * V_28 != NULL ) {
V_29 = * V_28 ;
V_49 = F_16 ( V_29 , struct V_15 , V_5 ) ;
if ( V_49 -> V_47 == V_47 ) {
V_1 -> V_11 = V_49 ;
if ( V_3 && V_3 != V_49 -> V_50 )
V_49 -> V_50 = V_3 ;
return V_49 ;
}
if ( V_47 < V_49 -> V_47 )
V_28 = & ( * V_28 ) -> V_30 ;
else
V_28 = & ( * V_28 ) -> V_31 ;
}
if ( ! V_48 )
return NULL ;
V_49 = F_41 ( V_3 , V_47 ) ;
if ( V_49 != NULL ) {
F_25 ( & V_49 -> V_5 , V_29 , V_28 ) ;
F_26 ( & V_49 -> V_5 , & V_1 -> V_8 ) ;
V_1 -> V_11 = V_49 ;
}
return V_49 ;
}
struct V_15 * F_6 ( struct V_1 * V_1 , T_1 V_3 ,
T_1 V_47 )
{
return F_40 ( V_1 , V_3 , V_47 , true ) ;
}
struct V_15 * F_42 ( struct V_1 * V_1 , T_1 V_47 )
{
return F_40 ( V_1 , 0 , V_47 , false ) ;
}
int F_43 ( struct V_1 * V_1 , union V_51 * V_52 )
{
struct V_15 * V_15 = F_6 ( V_1 ,
V_52 -> V_16 . V_3 ,
V_52 -> V_16 . V_47 ) ;
if ( V_53 )
F_44 ( V_52 , stdout ) ;
if ( V_15 == NULL || F_7 ( V_15 , V_52 -> V_16 . V_16 ) ) {
F_45 ( L_9 ) ;
return - 1 ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_1 V_54 ,
union V_51 * V_52 )
{
F_45 ( L_10 V_55 L_11 V_55 L_12 ,
V_52 -> V_56 . V_57 , V_52 -> V_56 . V_56 ) ;
return 0 ;
}
struct V_58 * F_47 ( struct V_1 * V_1 , T_6 V_59 ,
const char * V_60 )
{
struct V_58 * V_58 ;
struct V_19 * V_19 = F_48 ( & V_1 -> V_7 , V_60 ) ;
if ( V_19 == NULL )
return NULL ;
V_58 = F_49 ( V_59 , V_19 , V_61 ) ;
if ( V_58 == NULL )
return NULL ;
if ( F_37 ( V_1 ) )
V_19 -> V_62 = V_63 ;
else
V_19 -> V_62 = V_64 ;
F_50 ( & V_1 -> V_4 , V_58 ) ;
return V_58 ;
}
T_4 F_51 ( struct V_25 * V_25 , T_7 * V_65 )
{
struct V_5 * V_24 ;
T_4 V_66 = F_52 ( & V_25 -> V_26 . V_7 , V_65 ) +
F_52 ( & V_25 -> V_26 . V_6 , V_65 ) ;
for ( V_24 = F_15 ( & V_25 -> V_27 ) ; V_24 ; V_24 = F_18 ( V_24 ) ) {
struct V_1 * V_20 = F_16 ( V_24 , struct V_1 , V_5 ) ;
V_66 += F_52 ( & V_20 -> V_7 , V_65 ) ;
V_66 += F_52 ( & V_20 -> V_6 , V_65 ) ;
}
return V_66 ;
}
T_4 F_53 ( struct V_1 * V_1 , T_7 * V_65 ,
bool (F_54)( struct V_19 * V_19 , int V_67 ) , int V_67 )
{
return F_55 ( & V_1 -> V_7 , V_65 , F_54 , V_67 ) +
F_55 ( & V_1 -> V_6 , V_65 , F_54 , V_67 ) ;
}
T_4 F_56 ( struct V_25 * V_25 , T_7 * V_65 ,
bool (F_54)( struct V_19 * V_19 , int V_67 ) , int V_67 )
{
struct V_5 * V_24 ;
T_4 V_66 = F_53 ( & V_25 -> V_26 , V_65 , F_54 , V_67 ) ;
for ( V_24 = F_15 ( & V_25 -> V_27 ) ; V_24 ; V_24 = F_18 ( V_24 ) ) {
struct V_1 * V_20 = F_16 ( V_24 , struct V_1 , V_5 ) ;
V_66 += F_53 ( V_20 , V_65 , F_54 , V_67 ) ;
}
return V_66 ;
}
T_4 F_57 ( struct V_1 * V_1 , T_7 * V_65 )
{
int V_68 ;
T_4 V_69 = 0 ;
struct V_19 * V_70 = V_1 -> V_71 [ V_61 ] -> V_19 ;
if ( V_70 -> V_72 ) {
char V_60 [ V_34 ] ;
if ( F_58 ( V_70 , V_60 , sizeof( V_60 ) ) )
V_69 += fprintf ( V_65 , L_13 , V_60 ) ;
}
for ( V_68 = 0 ; V_68 < V_73 ; ++ V_68 )
V_69 += fprintf ( V_65 , L_14 ,
V_68 + V_70 -> V_72 , V_74 [ V_68 ] ) ;
return V_69 ;
}
T_4 F_59 ( struct V_1 * V_1 , T_7 * V_65 )
{
T_4 V_66 = 0 ;
struct V_5 * V_24 ;
for ( V_24 = F_15 ( & V_1 -> V_8 ) ; V_24 ; V_24 = F_18 ( V_24 ) ) {
struct V_15 * V_20 = F_16 ( V_24 , struct V_15 , V_5 ) ;
V_66 += F_60 ( V_20 , V_65 ) ;
}
return V_66 ;
}
static struct V_19 * F_61 ( struct V_1 * V_1 )
{
const char * V_75 = NULL ;
struct V_19 * V_76 ;
if ( F_37 ( V_1 ) ) {
V_75 = V_37 . V_75 ;
if ( ! V_75 )
V_75 = L_15 ;
V_76 = F_62 ( V_1 , V_75 ,
L_16 ,
V_77 ) ;
} else {
char V_44 [ V_34 ] ;
if ( F_38 ( V_1 ) )
V_75 = V_37 . V_78 ;
if ( ! V_75 )
V_75 = F_36 ( V_1 , V_44 ,
sizeof( V_44 ) ) ;
V_76 = F_62 ( V_1 , V_75 ,
L_17 ,
V_79 ) ;
}
if ( V_76 != NULL && ( ! V_76 -> V_72 ) )
F_63 ( V_76 , V_1 ) ;
return V_76 ;
}
static int F_64 ( void * V_80 , const char * V_81 ,
char type V_54 , T_6 V_59 )
{
struct V_82 * args = V_80 ;
if ( strchr ( V_81 , '[' ) )
return 0 ;
args -> V_59 = V_59 ;
return 1 ;
}
static T_6 F_65 ( struct V_1 * V_1 )
{
const char * V_60 ;
char V_33 [ V_34 ] ;
struct V_82 args ;
if ( F_37 ( V_1 ) ) {
V_60 = L_18 ;
} else {
if ( F_38 ( V_1 ) )
V_60 = ( char * ) V_37 . V_83 ;
else {
sprintf ( V_33 , L_19 , V_1 -> V_2 ) ;
V_60 = V_33 ;
}
}
if ( F_66 ( V_60 , L_18 ) )
return 0 ;
if ( F_67 ( V_60 , & args , F_64 ) <= 0 )
return 0 ;
return args . V_59 ;
}
int F_68 ( struct V_1 * V_1 , struct V_19 * V_76 )
{
enum V_84 type ;
T_6 V_59 = F_65 ( V_1 ) ;
for ( type = 0 ; type < V_85 ; ++ type ) {
struct V_86 * V_86 ;
V_1 -> V_71 [ type ] = F_49 ( V_59 , V_76 , type ) ;
if ( V_1 -> V_71 [ type ] == NULL )
return - 1 ;
V_1 -> V_71 [ type ] -> V_87 =
V_1 -> V_71 [ type ] -> V_88 =
V_89 ;
V_86 = F_69 ( V_1 -> V_71 [ type ] ) ;
V_86 -> V_4 = & V_1 -> V_4 ;
F_50 ( & V_1 -> V_4 ,
V_1 -> V_71 [ type ] ) ;
}
return 0 ;
}
void F_70 ( struct V_1 * V_1 )
{
enum V_84 type ;
for ( type = 0 ; type < V_85 ; ++ type ) {
struct V_86 * V_86 ;
if ( V_1 -> V_71 [ type ] == NULL )
continue;
V_86 = F_69 ( V_1 -> V_71 [ type ] ) ;
F_71 ( & V_1 -> V_4 ,
V_1 -> V_71 [ type ] ) ;
if ( V_86 -> V_90 ) {
if ( type == V_61 ) {
free ( ( char * ) V_86 -> V_90 -> V_81 ) ;
V_86 -> V_90 -> V_81 = NULL ;
free ( V_86 -> V_90 ) ;
}
V_86 -> V_90 = NULL ;
}
F_72 ( V_1 -> V_71 [ type ] ) ;
V_1 -> V_71 [ type ] = NULL ;
}
}
int F_73 ( struct V_25 * V_25 )
{
int V_66 = 0 ;
struct V_91 * * V_92 = NULL ;
int V_68 , V_93 = 0 ;
char V_33 [ V_34 ] ;
T_1 V_3 ;
char * V_94 ;
if ( V_37 . V_78 ||
V_37 . V_95 ||
V_37 . V_83 ) {
F_74 ( V_25 , V_36 ) ;
}
if ( V_37 . V_38 ) {
V_93 = F_75 ( V_37 . V_38 , & V_92 , NULL , NULL ) ;
if ( V_93 <= 0 )
return - V_96 ;
for ( V_68 = 0 ; V_68 < V_93 ; V_68 ++ ) {
if ( ! isdigit ( V_92 [ V_68 ] -> V_97 [ 0 ] ) ) {
continue;
}
V_3 = ( T_1 ) strtol ( V_92 [ V_68 ] -> V_97 , & V_94 , 10 ) ;
if ( ( * V_94 != '\0' ) ||
( V_94 == V_92 [ V_68 ] -> V_97 ) ||
( V_98 == V_99 ) ) {
F_76 ( L_20 ,
V_92 [ V_68 ] -> V_97 ) ;
continue;
}
sprintf ( V_33 , L_21 ,
V_37 . V_38 ,
V_92 [ V_68 ] -> V_97 ) ;
V_66 = F_30 ( V_33 , V_39 ) ;
if ( V_66 ) {
F_76 ( L_4 , V_33 ) ;
goto V_100;
}
F_74 ( V_25 , V_3 ) ;
}
V_100:
free ( V_92 ) ;
}
return V_66 ;
}
void F_77 ( struct V_25 * V_25 )
{
struct V_5 * V_101 = F_15 ( & V_25 -> V_27 ) ;
F_70 ( & V_25 -> V_26 ) ;
while ( V_101 ) {
struct V_1 * V_20 = F_16 ( V_101 , struct V_1 , V_5 ) ;
V_101 = F_18 ( & V_20 -> V_5 ) ;
F_17 ( & V_20 -> V_5 , & V_25 -> V_27 ) ;
F_21 ( V_20 ) ;
}
}
int F_74 ( struct V_25 * V_25 , T_1 V_3 )
{
struct V_1 * V_1 = F_29 ( V_25 , V_3 ) ;
if ( V_1 == NULL )
return - 1 ;
return F_78 ( V_1 ) ;
}
int F_79 ( struct V_1 * V_1 , const char * V_60 ,
enum V_84 type , T_2 V_102 )
{
struct V_58 * V_58 = V_1 -> V_71 [ type ] ;
int V_66 = F_80 ( V_58 -> V_19 , V_60 , V_58 , V_102 ) ;
if ( V_66 > 0 ) {
F_81 ( V_58 -> V_19 , type ) ;
F_82 ( & V_1 -> V_4 , type ) ;
}
return V_66 ;
}
int F_83 ( struct V_1 * V_1 , enum V_84 type ,
T_2 V_102 )
{
struct V_58 * V_58 = V_1 -> V_71 [ type ] ;
int V_66 = F_84 ( V_58 -> V_19 , V_58 , V_102 ) ;
if ( V_66 > 0 )
F_81 ( V_58 -> V_19 , type ) ;
return V_66 ;
}
static void F_85 ( struct V_103 * V_104 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_85 ; ++ V_68 )
F_82 ( V_104 , V_68 ) ;
}
static char * F_86 ( const char * V_2 )
{
char V_105 [ V_34 ] ;
T_7 * V_106 ;
char * V_81 , * V_107 ;
const char * V_108 = L_22 ;
sprintf ( V_105 , L_23 , V_2 ) ;
V_106 = fopen ( V_105 , L_24 ) ;
if ( ! V_106 )
return NULL ;
V_105 [ 0 ] = '\0' ;
V_107 = fgets ( V_105 , sizeof( V_105 ) , V_106 ) ;
fclose ( V_106 ) ;
V_81 = strstr ( V_105 , V_108 ) ;
if ( ! V_81 )
return NULL ;
V_81 += strlen ( V_108 ) ;
V_107 = strchr ( V_81 , ' ' ) ;
if ( V_107 )
* V_107 = '\0' ;
return F_5 ( V_81 ) ;
}
static int F_87 ( struct V_103 * V_104 ,
const char * V_109 )
{
struct V_91 * V_110 ;
T_8 * V_111 = F_88 ( V_109 ) ;
int V_66 = 0 ;
if ( ! V_111 ) {
F_76 ( L_25 , V_112 , V_109 ) ;
return - 1 ;
}
while ( ( V_110 = F_89 ( V_111 ) ) != NULL ) {
char V_33 [ V_34 ] ;
struct V_113 V_114 ;
snprintf ( V_33 , sizeof( V_33 ) , L_26 , V_109 , V_110 -> V_97 ) ;
if ( V_113 ( V_33 , & V_114 ) )
continue;
if ( F_90 ( V_114 . V_115 ) ) {
if ( ! strcmp ( V_110 -> V_97 , L_27 ) ||
! strcmp ( V_110 -> V_97 , L_28 ) )
continue;
V_66 = F_87 ( V_104 , V_33 ) ;
if ( V_66 < 0 )
goto V_35;
} else {
char * V_116 = strrchr ( V_110 -> V_97 , '.' ) ,
V_117 [ V_34 ] ;
struct V_58 * V_58 ;
char * V_118 ;
if ( V_116 == NULL || strcmp ( V_116 , L_29 ) )
continue;
snprintf ( V_117 , sizeof( V_117 ) , L_30 ,
( int ) ( V_116 - V_110 -> V_97 ) , V_110 -> V_97 ) ;
F_91 ( V_117 , '-' , '_' ) ;
V_58 = F_92 ( V_104 , V_61 ,
V_117 ) ;
if ( V_58 == NULL )
continue;
V_118 = F_5 ( V_33 ) ;
if ( V_118 == NULL ) {
V_66 = - 1 ;
goto V_35;
}
F_93 ( V_58 -> V_19 , V_118 ) ;
V_58 -> V_19 -> V_119 = 1 ;
F_94 ( V_58 -> V_19 , L_2 ) ;
}
}
V_35:
F_95 ( V_111 ) ;
return V_66 ;
}
static int F_96 ( struct V_1 * V_1 )
{
char * V_105 ;
char V_120 [ V_34 ] ;
V_105 = F_86 ( V_1 -> V_2 ) ;
if ( ! V_105 )
return - 1 ;
snprintf ( V_120 , sizeof( V_120 ) , L_31 ,
V_1 -> V_2 , V_105 ) ;
free ( V_105 ) ;
return F_87 ( & V_1 -> V_4 , V_120 ) ;
}
static int F_97 ( struct V_1 * V_1 )
{
char * line = NULL ;
T_4 V_21 ;
T_7 * V_106 ;
struct V_58 * V_58 ;
const char * V_121 ;
char V_33 [ V_34 ] ;
if ( F_38 ( V_1 ) )
V_121 = V_37 . V_95 ;
else {
sprintf ( V_33 , L_32 , V_1 -> V_2 ) ;
V_121 = V_33 ;
}
if ( F_66 ( V_121 , L_33 ) )
return - 1 ;
V_106 = fopen ( V_121 , L_24 ) ;
if ( V_106 == NULL )
return - 1 ;
while ( ! feof ( V_106 ) ) {
char V_81 [ V_34 ] ;
T_6 V_59 ;
char * V_122 ;
int V_123 ;
V_123 = F_98 ( & line , & V_21 , V_106 ) ;
if ( V_123 < 0 )
break;
if ( ! line )
goto V_124;
line [ -- V_123 ] = '\0' ;
V_122 = strrchr ( line , 'x' ) ;
if ( V_122 == NULL )
continue;
F_99 ( V_122 + 1 , & V_59 ) ;
V_122 = strchr ( line , ' ' ) ;
if ( V_122 == NULL )
continue;
* V_122 = '\0' ;
snprintf ( V_81 , sizeof( V_81 ) , L_5 , line ) ;
V_58 = F_47 ( V_1 , V_59 , V_81 ) ;
if ( V_58 == NULL )
goto V_125;
F_94 ( V_58 -> V_19 , V_1 -> V_2 ) ;
}
free ( line ) ;
fclose ( V_106 ) ;
if ( F_96 ( V_1 ) < 0 ) {
F_76 ( L_34 ) ;
}
return 0 ;
V_125:
free ( line ) ;
V_124:
return - 1 ;
}
int F_78 ( struct V_1 * V_1 )
{
struct V_19 * V_76 = F_61 ( V_1 ) ;
if ( V_76 == NULL ||
F_68 ( V_1 , V_76 ) < 0 )
return - 1 ;
if ( V_37 . V_126 && F_97 ( V_1 ) < 0 ) {
if ( F_37 ( V_1 ) )
F_76 ( L_35
L_36 ) ;
else
F_76 ( L_37
L_36 , V_1 -> V_3 ) ;
}
F_85 ( & V_1 -> V_4 ) ;
return 0 ;
}
static void F_100 ( struct V_1 * V_1 ,
union V_51 * V_52 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_85 ; V_68 ++ ) {
V_1 -> V_71 [ V_68 ] -> V_59 = V_52 -> V_127 . V_59 ;
V_1 -> V_71 [ V_68 ] -> V_128 = ( V_52 -> V_127 . V_59 +
V_52 -> V_127 . V_129 ) ;
if ( V_1 -> V_71 [ V_68 ] -> V_128 == 0 )
V_1 -> V_71 [ V_68 ] -> V_128 = ~ 0ULL ;
}
}
static bool F_101 ( struct V_1 * V_1 )
{
struct V_19 * V_19 ;
F_102 (dso, &machine->kernel_dsos, node) {
if ( F_103 ( V_19 ) )
return true ;
}
return false ;
}
static int F_104 ( struct V_1 * V_1 ,
union V_51 * V_52 )
{
struct V_58 * V_58 ;
char V_130 [ V_34 ] ;
enum V_131 V_132 ;
bool V_133 ;
if ( F_101 ( V_1 ) )
return 0 ;
F_36 ( V_1 , V_130 , sizeof( V_130 ) ) ;
if ( F_37 ( V_1 ) )
V_132 = V_77 ;
else
V_132 = V_79 ;
V_133 = memcmp ( V_52 -> V_127 . V_60 ,
V_130 ,
strlen ( V_130 ) - 1 ) == 0 ;
if ( V_52 -> V_127 . V_60 [ 0 ] == '/' ||
( ! V_133 && V_52 -> V_127 . V_60 [ 0 ] == '[' ) ) {
char V_134 [ 1024 ] ;
char * V_81 , * V_116 ;
if ( V_52 -> V_127 . V_60 [ 0 ] == '/' ) {
V_81 = strrchr ( V_52 -> V_127 . V_60 , '/' ) ;
if ( V_81 == NULL )
goto V_135;
++ V_81 ;
V_116 = strrchr ( V_81 , '.' ) ;
if ( V_116 == NULL )
goto V_135;
snprintf ( V_134 , sizeof( V_134 ) ,
L_30 , ( int ) ( V_116 - V_81 ) , V_81 ) ;
F_91 ( V_134 , '-' , '_' ) ;
} else
strcpy ( V_134 , V_52 -> V_127 . V_60 ) ;
V_58 = F_47 ( V_1 , V_52 -> V_127 . V_59 ,
V_52 -> V_127 . V_60 ) ;
if ( V_58 == NULL )
goto V_135;
V_81 = F_5 ( V_134 ) ;
if ( V_81 == NULL )
goto V_135;
V_58 -> V_19 -> V_136 = V_81 ;
V_58 -> V_19 -> V_137 = 1 ;
V_58 -> V_128 = V_58 -> V_59 + V_52 -> V_127 . V_129 ;
} else if ( V_133 ) {
const char * V_138 = ( V_52 -> V_127 . V_60 +
strlen ( V_130 ) ) ;
struct V_19 * V_76 = F_48 ( & V_1 -> V_7 ,
V_130 ) ;
if ( V_76 == NULL )
goto V_135;
V_76 -> V_76 = V_132 ;
if ( F_68 ( V_1 , V_76 ) < 0 )
goto V_135;
F_100 ( V_1 , V_52 ) ;
if ( V_52 -> V_127 . V_139 != 0 ) {
F_105 ( V_1 -> V_71 ,
V_138 ,
V_52 -> V_127 . V_139 ) ;
}
if ( F_38 ( V_1 ) ) {
F_106 ( V_76 , V_1 -> V_71 [ V_61 ] ,
NULL ) ;
}
}
return 0 ;
V_135:
return - 1 ;
}
int F_107 ( struct V_1 * V_1 ,
union V_51 * V_52 )
{
T_9 V_140 = V_52 -> V_141 . V_142 & V_143 ;
struct V_15 * V_15 ;
struct V_58 * V_58 ;
enum V_84 type ;
int V_66 = 0 ;
if ( V_53 )
F_108 ( V_52 , stdout ) ;
if ( V_140 == V_144 ||
V_140 == V_145 ) {
V_66 = F_104 ( V_1 , V_52 ) ;
if ( V_66 < 0 )
goto V_135;
return 0 ;
}
V_15 = F_6 ( V_1 , V_52 -> V_146 . V_3 ,
V_52 -> V_146 . V_3 ) ;
if ( V_15 == NULL )
goto V_135;
if ( V_52 -> V_141 . V_142 & V_147 )
type = V_148 ;
else
type = V_61 ;
V_58 = F_109 ( & V_1 -> V_6 , V_52 -> V_146 . V_59 ,
V_52 -> V_146 . V_129 , V_52 -> V_146 . V_139 ,
V_52 -> V_146 . V_3 , V_52 -> V_146 . V_149 ,
V_52 -> V_146 . V_150 , V_52 -> V_146 . V_151 ,
V_52 -> V_146 . V_152 ,
V_52 -> V_146 . V_60 , type ) ;
if ( V_58 == NULL )
goto V_135;
F_110 ( V_15 , V_58 ) ;
return 0 ;
V_135:
F_45 ( L_38 ) ;
return 0 ;
}
int F_111 ( struct V_1 * V_1 , union V_51 * V_52 )
{
T_9 V_140 = V_52 -> V_141 . V_142 & V_143 ;
struct V_15 * V_15 ;
struct V_58 * V_58 ;
enum V_84 type ;
int V_66 = 0 ;
if ( V_53 )
F_112 ( V_52 , stdout ) ;
if ( V_140 == V_144 ||
V_140 == V_145 ) {
V_66 = F_104 ( V_1 , V_52 ) ;
if ( V_66 < 0 )
goto V_135;
return 0 ;
}
V_15 = F_6 ( V_1 , V_52 -> V_127 . V_3 ,
V_52 -> V_127 . V_3 ) ;
if ( V_15 == NULL )
goto V_135;
if ( V_52 -> V_141 . V_142 & V_147 )
type = V_148 ;
else
type = V_61 ;
V_58 = F_109 ( & V_1 -> V_6 , V_52 -> V_127 . V_59 ,
V_52 -> V_127 . V_129 , V_52 -> V_127 . V_139 ,
V_52 -> V_127 . V_3 , 0 , 0 , 0 , 0 ,
V_52 -> V_127 . V_60 ,
type ) ;
if ( V_58 == NULL )
goto V_135;
F_110 ( V_15 , V_58 ) ;
return 0 ;
V_135:
F_45 ( L_39 ) ;
return 0 ;
}
static void F_113 ( struct V_1 * V_1 , struct V_15 * V_49 )
{
V_1 -> V_11 = NULL ;
F_17 ( & V_49 -> V_5 , & V_1 -> V_8 ) ;
F_114 ( & V_49 -> V_22 , & V_1 -> V_10 ) ;
}
int F_115 ( struct V_1 * V_1 , union V_51 * V_52 )
{
struct V_15 * V_15 = F_42 ( V_1 , V_52 -> V_153 . V_47 ) ;
struct V_15 * V_29 = F_6 ( V_1 ,
V_52 -> V_153 . V_154 ,
V_52 -> V_153 . V_155 ) ;
if ( V_15 != NULL )
F_113 ( V_1 , V_15 ) ;
V_15 = F_6 ( V_1 , V_52 -> V_153 . V_3 ,
V_52 -> V_153 . V_47 ) ;
if ( V_53 )
F_116 ( V_52 , stdout ) ;
if ( V_15 == NULL || V_29 == NULL ||
F_117 ( V_15 , V_29 ) < 0 ) {
F_45 ( L_40 ) ;
return - 1 ;
}
return 0 ;
}
int F_118 ( struct V_1 * V_1 V_54 ,
union V_51 * V_52 )
{
struct V_15 * V_15 = F_42 ( V_1 , V_52 -> V_153 . V_47 ) ;
if ( V_53 )
F_116 ( V_52 , stdout ) ;
if ( V_15 != NULL )
F_119 ( V_15 ) ;
return 0 ;
}
int F_120 ( struct V_1 * V_1 , union V_51 * V_52 )
{
int V_66 ;
switch ( V_52 -> V_141 . type ) {
case V_156 :
V_66 = F_43 ( V_1 , V_52 ) ; break;
case V_157 :
V_66 = F_111 ( V_1 , V_52 ) ; break;
case V_158 :
V_66 = F_107 ( V_1 , V_52 ) ; break;
case V_159 :
V_66 = F_115 ( V_1 , V_52 ) ; break;
case V_160 :
V_66 = F_118 ( V_1 , V_52 ) ; break;
case V_161 :
V_66 = F_46 ( V_1 , V_52 ) ; break;
default:
V_66 = - 1 ;
break;
}
return V_66 ;
}
static bool F_121 ( struct V_162 * V_163 , T_10 * V_164 )
{
if ( V_163 -> V_81 && ! regexec ( V_164 , V_163 -> V_81 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_122 ( struct V_1 * V_1 , struct V_15 * V_15 ,
struct V_165 * V_166 ,
T_6 V_167 )
{
struct V_168 V_169 ;
T_4 V_68 ;
T_9 V_170 ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
for ( V_68 = 0 ; V_68 < V_171 ; V_68 ++ ) {
V_170 = V_172 [ V_68 ] ;
F_123 ( V_15 , V_1 , V_170 , V_61 ,
V_167 , & V_169 ) ;
if ( V_169 . V_163 )
goto V_173;
}
V_173:
V_166 -> V_174 = V_167 ;
V_166 -> V_175 = V_169 . V_174 ;
V_166 -> V_163 = V_169 . V_163 ;
V_166 -> V_58 = V_169 . V_58 ;
}
static void F_124 ( struct V_1 * V_1 , struct V_15 * V_15 ,
T_9 V_170 , struct V_165 * V_166 , T_6 V_174 )
{
struct V_168 V_169 ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
F_123 ( V_15 , V_1 , V_170 , V_148 , V_174 ,
& V_169 ) ;
V_166 -> V_174 = V_174 ;
V_166 -> V_175 = V_169 . V_174 ;
V_166 -> V_163 = V_169 . V_163 ;
V_166 -> V_58 = V_169 . V_58 ;
}
struct V_176 * F_125 ( struct V_1 * V_1 ,
struct V_15 * V_177 ,
struct V_178 * V_179 ,
T_9 V_140 )
{
struct V_176 * V_180 = F_126 ( sizeof( * V_180 ) ) ;
if ( ! V_180 )
return NULL ;
F_122 ( V_1 , V_177 , & V_180 -> V_181 , V_179 -> V_167 ) ;
F_124 ( V_1 , V_177 , V_140 , & V_180 -> V_182 , V_179 -> V_174 ) ;
V_180 -> V_183 . V_184 = V_179 -> V_183 ;
return V_180 ;
}
struct V_185 * F_127 ( struct V_1 * V_1 ,
struct V_15 * V_177 ,
struct V_186 * V_187 )
{
struct V_185 * V_188 ;
unsigned int V_68 ;
V_188 = calloc ( V_187 -> V_189 , sizeof( struct V_185 ) ) ;
if ( ! V_188 )
return NULL ;
for ( V_68 = 0 ; V_68 < V_187 -> V_189 ; V_68 ++ ) {
F_122 ( V_1 , V_177 , & V_188 [ V_68 ] . V_190 , V_187 -> V_191 [ V_68 ] . V_190 ) ;
F_122 ( V_1 , V_177 , & V_188 [ V_68 ] . V_192 , V_187 -> V_191 [ V_68 ] . V_192 ) ;
V_188 [ V_68 ] . V_193 = V_187 -> V_191 [ V_68 ] . V_193 ;
}
return V_188 ;
}
static int F_128 ( struct V_1 * V_1 ,
struct V_15 * V_15 ,
struct V_194 * V_195 ,
struct V_162 * * V_29 ,
struct V_168 * V_196 )
{
T_9 V_140 = V_197 ;
unsigned int V_68 ;
int V_198 ;
F_129 ( & V_199 ) ;
if ( V_195 -> V_189 > V_200 ) {
F_130 ( L_41 ) ;
return 0 ;
}
for ( V_68 = 0 ; V_68 < V_195 -> V_189 ; V_68 ++ ) {
T_6 V_167 ;
struct V_168 V_169 ;
if ( V_201 . V_202 == V_203 )
V_167 = V_195 -> V_204 [ V_68 ] ;
else
V_167 = V_195 -> V_204 [ V_195 -> V_189 - V_68 - 1 ] ;
if ( V_167 >= V_205 ) {
switch ( V_167 ) {
case V_206 :
V_140 = V_207 ;
break;
case V_208 :
V_140 = V_145 ;
break;
case V_209 :
V_140 = V_197 ;
break;
default:
F_76 ( L_42
L_43 V_210 L_12 , ( V_211 ) V_167 ) ;
F_129 ( & V_199 ) ;
return 0 ;
}
continue;
}
V_169 . V_212 = false ;
F_123 ( V_15 , V_1 , V_140 ,
V_61 , V_167 , & V_169 ) ;
if ( V_169 . V_163 != NULL ) {
if ( V_213 && ! * V_29 &&
F_121 ( V_169 . V_163 , & V_214 ) )
* V_29 = V_169 . V_163 ;
else if ( V_215 && V_196 &&
F_121 ( V_169 . V_163 , & V_216 ) ) {
* V_196 = V_169 ;
F_129 ( & V_199 ) ;
}
if ( ! V_37 . V_217 )
break;
}
V_198 = F_131 ( & V_199 ,
V_167 , V_169 . V_58 , V_169 . V_163 ) ;
if ( V_198 )
return V_198 ;
}
return 0 ;
}
static int F_132 ( struct F_132 * V_218 , void * V_80 )
{
struct V_199 * V_219 = V_80 ;
return F_131 ( V_219 , V_218 -> V_167 ,
V_218 -> V_58 , V_218 -> V_163 ) ;
}
int F_133 ( struct V_1 * V_1 ,
struct V_220 * V_221 ,
struct V_15 * V_15 ,
struct V_178 * V_179 ,
struct V_162 * * V_29 ,
struct V_168 * V_196 )
{
int V_66 ;
V_66 = F_128 ( V_1 , V_15 ,
V_179 -> V_222 , V_29 , V_196 ) ;
if ( V_66 )
return V_66 ;
if ( ! ( ( V_221 -> V_223 . V_224 & V_225 ) &&
( V_221 -> V_223 . V_224 & V_226 ) ) )
return 0 ;
if ( ( ! V_179 -> V_227 . V_228 ) ||
( ! V_179 -> V_229 . V_45 ) )
return 0 ;
return F_134 ( F_132 , & V_199 , V_1 ,
V_15 , V_221 -> V_223 . V_230 ,
V_179 ) ;
}
