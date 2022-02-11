int F_1 ( struct V_1 * V_1 , const char * V_2 , T_1 V_3 )
{
F_2 ( & V_1 -> V_4 ) ;
F_3 ( & V_1 -> V_5 ) ;
F_4 ( & V_1 -> V_6 ) ;
F_4 ( & V_1 -> V_7 ) ;
V_1 -> V_8 = V_9 ;
F_4 ( & V_1 -> V_10 ) ;
V_1 -> V_11 = NULL ;
V_1 -> V_12 = NULL ;
V_1 -> V_4 . V_1 = V_1 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_13 = NULL ;
V_1 -> V_14 = 0 ;
V_1 -> V_2 = F_5 ( V_2 ) ;
if ( V_1 -> V_2 == NULL )
return - V_15 ;
if ( V_3 != V_16 ) {
struct V_17 * V_17 = F_6 ( V_1 , - 1 ,
V_3 ) ;
char V_18 [ 64 ] ;
if ( V_17 == NULL )
return - V_15 ;
snprintf ( V_18 , sizeof( V_18 ) , L_1 , V_3 ) ;
F_7 ( V_17 , V_18 , 0 ) ;
}
V_1 -> V_19 = NULL ;
return 0 ;
}
struct V_1 * F_8 ( void )
{
struct V_1 * V_1 = malloc ( sizeof( * V_1 ) ) ;
if ( V_1 != NULL ) {
F_1 ( V_1 , L_2 , V_16 ) ;
if ( F_9 ( V_1 ) < 0 )
goto V_20;
}
return V_1 ;
V_20:
free ( V_1 ) ;
return NULL ;
}
static void F_10 ( struct V_21 * V_22 )
{
struct V_23 * V_24 , * V_25 ;
F_11 (pos, n, dsos, node) {
F_12 ( & V_24 -> V_26 ) ;
F_13 ( V_24 ) ;
}
}
void F_14 ( struct V_1 * V_1 )
{
struct V_17 * V_25 , * V_27 ;
F_11 (t, n, &machine->dead_threads, node) {
F_12 ( & V_27 -> V_26 ) ;
F_15 ( V_27 ) ;
}
}
void F_16 ( struct V_1 * V_1 )
{
struct V_5 * V_28 = F_17 ( & V_1 -> V_8 ) ;
while ( V_28 ) {
struct V_17 * V_27 = F_18 ( V_28 , struct V_17 , V_5 ) ;
F_19 ( & V_27 -> V_5 , & V_1 -> V_8 ) ;
V_28 = F_20 ( V_28 ) ;
F_15 ( V_27 ) ;
}
}
void F_21 ( struct V_1 * V_1 )
{
F_22 ( & V_1 -> V_4 ) ;
F_10 ( & V_1 -> V_6 ) ;
F_10 ( & V_1 -> V_7 ) ;
F_23 ( V_1 ) ;
F_24 ( & V_1 -> V_2 ) ;
F_24 ( & V_1 -> V_19 ) ;
}
void F_25 ( struct V_1 * V_1 )
{
F_21 ( V_1 ) ;
free ( V_1 ) ;
}
void F_26 ( struct V_29 * V_29 )
{
F_1 ( & V_29 -> V_30 , L_2 , V_16 ) ;
V_29 -> V_31 = V_9 ;
V_29 -> V_13 = NULL ;
}
void F_27 ( struct V_29 * V_29 )
{
F_21 ( & V_29 -> V_30 ) ;
}
struct V_1 * F_28 ( struct V_29 * V_29 , T_1 V_3 ,
const char * V_2 )
{
struct V_5 * * V_32 = & V_29 -> V_31 . V_5 ;
struct V_5 * V_33 = NULL ;
struct V_1 * V_24 , * V_1 = malloc ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_1 ( V_1 , V_2 , V_3 ) != 0 ) {
free ( V_1 ) ;
return NULL ;
}
V_1 -> V_13 = V_29 -> V_13 ;
while ( * V_32 != NULL ) {
V_33 = * V_32 ;
V_24 = F_18 ( V_33 , struct V_1 , V_5 ) ;
if ( V_3 < V_24 -> V_3 )
V_32 = & ( * V_32 ) -> V_34 ;
else
V_32 = & ( * V_32 ) -> V_35 ;
}
F_29 ( & V_1 -> V_5 , V_33 , V_32 ) ;
F_30 ( & V_1 -> V_5 , & V_29 -> V_31 ) ;
return V_1 ;
}
void F_31 ( struct V_29 * V_29 ,
T_2 V_13 )
{
struct V_5 * V_28 ;
V_29 -> V_13 = V_13 ;
V_29 -> V_30 . V_13 = V_13 ;
for ( V_28 = F_17 ( & V_29 -> V_31 ) ; V_28 ; V_28 = F_20 ( V_28 ) ) {
struct V_1 * V_1 = F_18 ( V_28 , struct V_1 , V_5 ) ;
V_1 -> V_13 = V_13 ;
}
}
struct V_1 * F_32 ( struct V_29 * V_29 , T_1 V_3 )
{
struct V_5 * * V_32 = & V_29 -> V_31 . V_5 ;
struct V_5 * V_33 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_36 = NULL ;
if ( V_3 == V_16 )
return & V_29 -> V_30 ;
while ( * V_32 != NULL ) {
V_33 = * V_32 ;
V_1 = F_18 ( V_33 , struct V_1 , V_5 ) ;
if ( V_3 < V_1 -> V_3 )
V_32 = & ( * V_32 ) -> V_34 ;
else if ( V_3 > V_1 -> V_3 )
V_32 = & ( * V_32 ) -> V_35 ;
else
return V_1 ;
if ( ! V_1 -> V_3 )
V_36 = V_1 ;
}
return V_36 ;
}
struct V_1 * F_33 ( struct V_29 * V_29 , T_1 V_3 )
{
char V_37 [ V_38 ] ;
const char * V_2 = L_2 ;
struct V_1 * V_1 = F_32 ( V_29 , V_3 ) ;
if ( V_1 && ( V_1 -> V_3 == V_3 ) )
goto V_39;
if ( ( V_3 != V_16 ) &&
( V_3 != V_40 ) &&
( V_41 . V_42 ) ) {
sprintf ( V_37 , L_3 , V_41 . V_42 , V_3 ) ;
if ( F_34 ( V_37 , V_43 ) ) {
static struct V_44 * V_45 ;
if ( ! V_45 )
V_45 = F_35 ( true , NULL ) ;
if ( ! F_36 ( V_45 , V_37 ) ) {
F_37 ( L_4 , V_37 ) ;
F_38 ( V_45 , V_37 ) ;
}
V_1 = NULL ;
goto V_39;
}
V_2 = V_37 ;
}
V_1 = F_28 ( V_29 , V_3 , V_2 ) ;
V_39:
return V_1 ;
}
void F_39 ( struct V_29 * V_29 ,
T_3 V_46 , void * V_47 )
{
struct V_5 * V_28 ;
for ( V_28 = F_17 ( & V_29 -> V_31 ) ; V_28 ; V_28 = F_20 ( V_28 ) ) {
struct V_1 * V_24 = F_18 ( V_28 , struct V_1 , V_5 ) ;
V_46 ( V_24 , V_47 ) ;
}
}
char * F_40 ( struct V_1 * V_1 , char * V_48 , T_4 V_49 )
{
if ( F_41 ( V_1 ) )
snprintf ( V_48 , V_49 , L_5 , L_6 ) ;
else if ( F_42 ( V_1 ) )
snprintf ( V_48 , V_49 , L_5 , L_7 ) ;
else {
snprintf ( V_48 , V_49 , L_8 , L_7 ,
V_1 -> V_3 ) ;
}
return V_48 ;
}
void F_43 ( struct V_29 * V_29 , T_5 V_14 )
{
struct V_5 * V_26 ;
struct V_1 * V_1 ;
V_29 -> V_30 . V_14 = V_14 ;
for ( V_26 = F_17 ( & V_29 -> V_31 ) ; V_26 ; V_26 = F_20 ( V_26 ) ) {
V_1 = F_18 ( V_26 , struct V_1 , V_5 ) ;
V_1 -> V_14 = V_14 ;
}
return;
}
static void F_44 ( struct V_1 * V_1 ,
struct V_17 * V_50 , T_1 V_3 )
{
struct V_17 * V_51 ;
if ( V_3 == V_50 -> V_52 || V_3 == - 1 || V_50 -> V_52 != - 1 )
return;
V_50 -> V_52 = V_3 ;
if ( V_50 -> V_52 == V_50 -> V_53 )
return;
V_51 = F_6 ( V_1 , V_50 -> V_52 , V_50 -> V_52 ) ;
if ( ! V_51 )
goto V_54;
if ( ! V_51 -> V_55 )
V_51 -> V_55 = F_45 () ;
if ( ! V_51 -> V_55 )
goto V_54;
if ( V_50 -> V_55 == V_51 -> V_55 )
return;
if ( V_50 -> V_55 ) {
if ( ! F_46 ( V_50 -> V_55 ) )
F_37 ( L_9 ,
V_50 -> V_52 , V_50 -> V_53 ) ;
F_47 ( V_50 -> V_55 ) ;
}
V_50 -> V_55 = F_48 ( V_51 -> V_55 ) ;
return;
V_54:
F_37 ( L_10 , V_50 -> V_52 , V_50 -> V_53 ) ;
}
static struct V_17 * F_49 ( struct V_1 * V_1 ,
T_1 V_3 , T_1 V_53 ,
bool V_56 )
{
struct V_5 * * V_32 = & V_1 -> V_8 . V_5 ;
struct V_5 * V_33 = NULL ;
struct V_17 * V_50 ;
V_50 = V_1 -> V_11 ;
if ( V_50 && V_50 -> V_53 == V_53 ) {
F_44 ( V_1 , V_50 , V_3 ) ;
return V_50 ;
}
while ( * V_32 != NULL ) {
V_33 = * V_32 ;
V_50 = F_18 ( V_33 , struct V_17 , V_5 ) ;
if ( V_50 -> V_53 == V_53 ) {
V_1 -> V_11 = V_50 ;
F_44 ( V_1 , V_50 , V_3 ) ;
return V_50 ;
}
if ( V_53 < V_50 -> V_53 )
V_32 = & ( * V_32 ) -> V_34 ;
else
V_32 = & ( * V_32 ) -> V_35 ;
}
if ( ! V_56 )
return NULL ;
V_50 = F_50 ( V_3 , V_53 ) ;
if ( V_50 != NULL ) {
F_29 ( & V_50 -> V_5 , V_33 , V_32 ) ;
F_30 ( & V_50 -> V_5 , & V_1 -> V_8 ) ;
V_1 -> V_11 = V_50 ;
if ( F_51 ( V_50 , V_1 ) ) {
F_15 ( V_50 ) ;
return NULL ;
}
}
return V_50 ;
}
struct V_17 * F_6 ( struct V_1 * V_1 , T_1 V_3 ,
T_1 V_53 )
{
return F_49 ( V_1 , V_3 , V_53 , true ) ;
}
struct V_17 * F_52 ( struct V_1 * V_1 , T_1 V_3 ,
T_1 V_53 )
{
return F_49 ( V_1 , V_3 , V_53 , false ) ;
}
int F_53 ( struct V_1 * V_1 , union V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_17 * V_17 = F_6 ( V_1 ,
V_58 -> V_18 . V_3 ,
V_58 -> V_18 . V_53 ) ;
if ( V_61 )
F_54 ( V_58 , stdout ) ;
if ( V_17 == NULL || F_7 ( V_17 , V_58 -> V_18 . V_18 , V_60 -> time ) ) {
F_55 ( L_11 ) ;
return - 1 ;
}
return 0 ;
}
int F_56 ( struct V_1 * V_1 V_62 ,
union V_57 * V_58 , struct V_59 * V_60 V_62 )
{
F_55 ( L_12 V_63 L_13 V_63 L_14 ,
V_58 -> V_64 . V_65 , V_58 -> V_64 . V_64 ) ;
return 0 ;
}
struct V_66 * F_57 ( struct V_1 * V_1 , T_6 V_67 ,
const char * V_68 )
{
struct V_66 * V_66 ;
struct V_23 * V_23 = F_58 ( & V_1 -> V_7 , V_68 ) ;
if ( V_23 == NULL )
return NULL ;
V_66 = F_59 ( V_67 , V_23 , V_69 ) ;
if ( V_66 == NULL )
return NULL ;
if ( F_41 ( V_1 ) )
V_23 -> V_70 = V_71 ;
else
V_23 -> V_70 = V_72 ;
F_60 ( & V_1 -> V_4 , V_66 ) ;
return V_66 ;
}
T_4 F_61 ( struct V_29 * V_29 , T_7 * V_73 )
{
struct V_5 * V_28 ;
T_4 V_74 = F_62 ( & V_29 -> V_30 . V_7 , V_73 ) +
F_62 ( & V_29 -> V_30 . V_6 , V_73 ) ;
for ( V_28 = F_17 ( & V_29 -> V_31 ) ; V_28 ; V_28 = F_20 ( V_28 ) ) {
struct V_1 * V_24 = F_18 ( V_28 , struct V_1 , V_5 ) ;
V_74 += F_62 ( & V_24 -> V_7 , V_73 ) ;
V_74 += F_62 ( & V_24 -> V_6 , V_73 ) ;
}
return V_74 ;
}
T_4 F_63 ( struct V_1 * V_1 , T_7 * V_73 ,
bool (F_64)( struct V_23 * V_23 , int V_75 ) , int V_75 )
{
return F_65 ( & V_1 -> V_7 , V_73 , F_64 , V_75 ) +
F_65 ( & V_1 -> V_6 , V_73 , F_64 , V_75 ) ;
}
T_4 F_66 ( struct V_29 * V_29 , T_7 * V_73 ,
bool (F_64)( struct V_23 * V_23 , int V_75 ) , int V_75 )
{
struct V_5 * V_28 ;
T_4 V_74 = F_63 ( & V_29 -> V_30 , V_73 , F_64 , V_75 ) ;
for ( V_28 = F_17 ( & V_29 -> V_31 ) ; V_28 ; V_28 = F_20 ( V_28 ) ) {
struct V_1 * V_24 = F_18 ( V_28 , struct V_1 , V_5 ) ;
V_74 += F_63 ( V_24 , V_73 , F_64 , V_75 ) ;
}
return V_74 ;
}
T_4 F_67 ( struct V_1 * V_1 , T_7 * V_73 )
{
int V_76 ;
T_4 V_77 = 0 ;
struct V_23 * V_78 = V_1 -> V_79 [ V_69 ] -> V_23 ;
if ( V_78 -> V_80 ) {
char V_68 [ V_38 ] ;
if ( F_68 ( V_78 , V_68 , sizeof( V_68 ) ) )
V_77 += fprintf ( V_73 , L_15 , V_68 ) ;
}
for ( V_76 = 0 ; V_76 < V_81 ; ++ V_76 )
V_77 += fprintf ( V_73 , L_16 ,
V_76 + V_78 -> V_80 , V_82 [ V_76 ] ) ;
return V_77 ;
}
T_4 F_69 ( struct V_1 * V_1 , T_7 * V_73 )
{
T_4 V_74 = 0 ;
struct V_5 * V_28 ;
for ( V_28 = F_17 ( & V_1 -> V_8 ) ; V_28 ; V_28 = F_20 ( V_28 ) ) {
struct V_17 * V_24 = F_18 ( V_28 , struct V_17 , V_5 ) ;
V_74 += F_70 ( V_24 , V_73 ) ;
}
return V_74 ;
}
static struct V_23 * F_71 ( struct V_1 * V_1 )
{
const char * V_83 = NULL ;
struct V_23 * V_84 ;
if ( F_41 ( V_1 ) ) {
V_83 = V_41 . V_83 ;
if ( ! V_83 )
V_83 = L_17 ;
V_84 = F_72 ( V_1 , V_83 ,
L_18 ,
V_85 ) ;
} else {
char V_48 [ V_38 ] ;
if ( F_42 ( V_1 ) )
V_83 = V_41 . V_86 ;
if ( ! V_83 )
V_83 = F_40 ( V_1 , V_48 ,
sizeof( V_48 ) ) ;
V_84 = F_72 ( V_1 , V_83 ,
L_19 ,
V_87 ) ;
}
if ( V_84 != NULL && ( ! V_84 -> V_80 ) )
F_73 ( V_84 , V_1 ) ;
return V_84 ;
}
static void F_74 ( struct V_1 * V_1 , char * V_88 ,
T_4 V_89 )
{
if ( F_42 ( V_1 ) )
F_75 ( V_88 , V_89 , L_20 , V_41 . V_90 ) ;
else
F_75 ( V_88 , V_89 , L_21 , V_1 -> V_2 ) ;
}
static T_6 F_76 ( struct V_1 * V_1 ,
const char * * V_91 )
{
char V_68 [ V_38 ] ;
int V_76 ;
const char * V_92 ;
T_6 V_93 = 0 ;
F_74 ( V_1 , V_68 , V_38 ) ;
if ( F_77 ( V_68 , L_22 ) )
return 0 ;
for ( V_76 = 0 ; ( V_92 = V_94 [ V_76 ] ) != NULL ; V_76 ++ ) {
V_93 = F_78 ( V_68 , V_92 ) ;
if ( V_93 )
break;
}
if ( V_91 )
* V_91 = V_92 ;
return V_93 ;
}
int F_79 ( struct V_1 * V_1 , struct V_23 * V_84 )
{
enum V_95 type ;
T_6 V_67 = F_76 ( V_1 , NULL ) ;
for ( type = 0 ; type < V_96 ; ++ type ) {
struct V_97 * V_97 ;
V_1 -> V_79 [ type ] = F_59 ( V_67 , V_84 , type ) ;
if ( V_1 -> V_79 [ type ] == NULL )
return - 1 ;
V_1 -> V_79 [ type ] -> V_98 =
V_1 -> V_79 [ type ] -> V_99 =
V_100 ;
V_97 = F_80 ( V_1 -> V_79 [ type ] ) ;
V_97 -> V_4 = & V_1 -> V_4 ;
F_60 ( & V_1 -> V_4 ,
V_1 -> V_79 [ type ] ) ;
}
return 0 ;
}
void F_81 ( struct V_1 * V_1 )
{
enum V_95 type ;
for ( type = 0 ; type < V_96 ; ++ type ) {
struct V_97 * V_97 ;
if ( V_1 -> V_79 [ type ] == NULL )
continue;
V_97 = F_80 ( V_1 -> V_79 [ type ] ) ;
F_82 ( & V_1 -> V_4 ,
V_1 -> V_79 [ type ] ) ;
if ( V_97 -> V_101 ) {
if ( type == V_69 ) {
F_24 ( ( char * * ) & V_97 -> V_101 -> V_92 ) ;
F_24 ( & V_97 -> V_101 ) ;
} else
V_97 -> V_101 = NULL ;
}
F_83 ( V_1 -> V_79 [ type ] ) ;
V_1 -> V_79 [ type ] = NULL ;
}
}
int F_84 ( struct V_29 * V_29 )
{
int V_74 = 0 ;
struct V_102 * * V_103 = NULL ;
int V_76 , V_104 = 0 ;
char V_37 [ V_38 ] ;
T_1 V_3 ;
char * V_105 ;
if ( V_41 . V_86 ||
V_41 . V_106 ||
V_41 . V_90 ) {
F_85 ( V_29 , V_40 ) ;
}
if ( V_41 . V_42 ) {
V_104 = F_86 ( V_41 . V_42 , & V_103 , NULL , NULL ) ;
if ( V_104 <= 0 )
return - V_107 ;
for ( V_76 = 0 ; V_76 < V_104 ; V_76 ++ ) {
if ( ! isdigit ( V_103 [ V_76 ] -> V_108 [ 0 ] ) ) {
continue;
}
V_3 = ( T_1 ) strtol ( V_103 [ V_76 ] -> V_108 , & V_105 , 10 ) ;
if ( ( * V_105 != '\0' ) ||
( V_105 == V_103 [ V_76 ] -> V_108 ) ||
( V_109 == V_110 ) ) {
F_87 ( L_23 ,
V_103 [ V_76 ] -> V_108 ) ;
continue;
}
sprintf ( V_37 , L_24 ,
V_41 . V_42 ,
V_103 [ V_76 ] -> V_108 ) ;
V_74 = F_34 ( V_37 , V_43 ) ;
if ( V_74 ) {
F_87 ( L_4 , V_37 ) ;
goto V_111;
}
F_85 ( V_29 , V_3 ) ;
}
V_111:
free ( V_103 ) ;
}
return V_74 ;
}
void F_88 ( struct V_29 * V_29 )
{
struct V_5 * V_112 = F_17 ( & V_29 -> V_31 ) ;
F_81 ( & V_29 -> V_30 ) ;
while ( V_112 ) {
struct V_1 * V_24 = F_18 ( V_112 , struct V_1 , V_5 ) ;
V_112 = F_20 ( & V_24 -> V_5 ) ;
F_19 ( & V_24 -> V_5 , & V_29 -> V_31 ) ;
F_25 ( V_24 ) ;
}
}
int F_85 ( struct V_29 * V_29 , T_1 V_3 )
{
struct V_1 * V_1 = F_33 ( V_29 , V_3 ) ;
if ( V_1 == NULL )
return - 1 ;
return F_9 ( V_1 ) ;
}
int F_89 ( struct V_1 * V_1 , const char * V_68 ,
enum V_95 type , T_2 V_113 )
{
struct V_66 * V_66 = V_1 -> V_79 [ type ] ;
int V_74 = F_90 ( V_66 -> V_23 , V_68 , V_66 , V_113 ) ;
if ( V_74 > 0 ) {
F_91 ( V_66 -> V_23 , type ) ;
F_92 ( & V_1 -> V_4 , type ) ;
}
return V_74 ;
}
int F_93 ( struct V_1 * V_1 , enum V_95 type ,
T_2 V_113 )
{
struct V_66 * V_66 = V_1 -> V_79 [ type ] ;
int V_74 = F_94 ( V_66 -> V_23 , V_66 , V_113 ) ;
if ( V_74 > 0 )
F_91 ( V_66 -> V_23 , type ) ;
return V_74 ;
}
static void F_95 ( struct V_114 * V_55 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_96 ; ++ V_76 )
F_92 ( V_55 , V_76 ) ;
}
static char * F_96 ( const char * V_2 )
{
char V_115 [ V_38 ] ;
T_7 * V_116 ;
char * V_92 , * V_117 ;
const char * V_118 = L_25 ;
sprintf ( V_115 , L_26 , V_2 ) ;
V_116 = fopen ( V_115 , L_27 ) ;
if ( ! V_116 )
return NULL ;
V_115 [ 0 ] = '\0' ;
V_117 = fgets ( V_115 , sizeof( V_115 ) , V_116 ) ;
fclose ( V_116 ) ;
V_92 = strstr ( V_115 , V_118 ) ;
if ( ! V_92 )
return NULL ;
V_92 += strlen ( V_118 ) ;
V_117 = strchr ( V_92 , ' ' ) ;
if ( V_117 )
* V_117 = '\0' ;
return F_5 ( V_92 ) ;
}
static int F_97 ( struct V_114 * V_55 ,
const char * V_119 , int V_120 )
{
struct V_102 * V_121 ;
T_8 * V_122 = F_98 ( V_119 ) ;
int V_74 = 0 ;
if ( ! V_122 ) {
F_87 ( L_28 , V_123 , V_119 ) ;
return - 1 ;
}
while ( ( V_121 = F_99 ( V_122 ) ) != NULL ) {
char V_37 [ V_38 ] ;
struct V_124 V_125 ;
snprintf ( V_37 , sizeof( V_37 ) , L_29 , V_119 , V_121 -> V_108 ) ;
if ( V_124 ( V_37 , & V_125 ) )
continue;
if ( F_100 ( V_125 . V_126 ) ) {
if ( ! strcmp ( V_121 -> V_108 , L_30 ) ||
! strcmp ( V_121 -> V_108 , L_31 ) )
continue;
if ( V_120 == 0 ) {
if ( ! strcmp ( V_121 -> V_108 , L_32 ) ||
! strcmp ( V_121 -> V_108 , L_33 ) )
continue;
}
V_74 = F_97 ( V_55 , V_37 ,
V_120 + 1 ) ;
if ( V_74 < 0 )
goto V_39;
} else {
char * V_127 = strrchr ( V_121 -> V_108 , '.' ) ,
V_128 [ V_38 ] ;
struct V_66 * V_66 ;
char * V_129 ;
if ( V_127 == NULL || strcmp ( V_127 , L_34 ) )
continue;
snprintf ( V_128 , sizeof( V_128 ) , L_35 ,
( int ) ( V_127 - V_121 -> V_108 ) , V_121 -> V_108 ) ;
F_101 ( V_128 , '-' , '_' ) ;
V_66 = F_102 ( V_55 , V_69 ,
V_128 ) ;
if ( V_66 == NULL )
continue;
V_129 = F_5 ( V_37 ) ;
if ( V_129 == NULL ) {
V_74 = - 1 ;
goto V_39;
}
F_103 ( V_66 -> V_23 , V_129 , true ) ;
F_104 ( V_66 -> V_23 , L_2 ) ;
}
}
V_39:
F_105 ( V_122 ) ;
return V_74 ;
}
static int F_106 ( struct V_1 * V_1 )
{
char * V_115 ;
char V_130 [ V_38 ] ;
V_115 = F_96 ( V_1 -> V_2 ) ;
if ( ! V_115 )
return - 1 ;
snprintf ( V_130 , sizeof( V_130 ) , L_36 ,
V_1 -> V_2 , V_115 ) ;
free ( V_115 ) ;
return F_97 ( & V_1 -> V_4 , V_130 , 0 ) ;
}
static int F_107 ( void * V_131 , const char * V_92 , T_6 V_67 )
{
struct V_1 * V_1 = V_131 ;
struct V_66 * V_66 ;
V_66 = F_57 ( V_1 , V_67 , V_92 ) ;
if ( V_66 == NULL )
return - 1 ;
F_104 ( V_66 -> V_23 , V_1 -> V_2 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_1 )
{
const char * V_132 ;
char V_37 [ V_38 ] ;
if ( F_42 ( V_1 ) ) {
V_132 = V_41 . V_106 ;
} else {
snprintf ( V_37 , V_38 , L_37 , V_1 -> V_2 ) ;
V_132 = V_37 ;
}
if ( F_77 ( V_132 , L_38 ) )
return - 1 ;
if ( F_109 ( V_132 , V_1 , F_107 ) )
return - 1 ;
if ( ! F_106 ( V_1 ) )
return 0 ;
F_87 ( L_39 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 )
{
struct V_23 * V_84 = F_71 ( V_1 ) ;
const char * V_92 ;
T_6 V_93 = F_76 ( V_1 , & V_92 ) ;
if ( ! V_93 )
return - 1 ;
if ( V_84 == NULL ||
F_79 ( V_1 , V_84 ) < 0 )
return - 1 ;
if ( V_41 . V_133 && F_108 ( V_1 ) < 0 ) {
if ( F_41 ( V_1 ) )
F_87 ( L_40
L_41 ) ;
else
F_87 ( L_42
L_41 , V_1 -> V_3 ) ;
}
F_95 ( & V_1 -> V_4 ) ;
if ( F_110 ( V_1 -> V_79 , V_92 ,
V_93 ) ) {
F_81 ( V_1 ) ;
return - 1 ;
}
return 0 ;
}
static void F_111 ( struct V_1 * V_1 ,
union V_57 * V_58 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_96 ; V_76 ++ ) {
V_1 -> V_79 [ V_76 ] -> V_67 = V_58 -> V_134 . V_67 ;
V_1 -> V_79 [ V_76 ] -> V_135 = ( V_58 -> V_134 . V_67 +
V_58 -> V_134 . V_136 ) ;
if ( V_1 -> V_79 [ V_76 ] -> V_135 == 0 )
V_1 -> V_79 [ V_76 ] -> V_135 = ~ 0ULL ;
}
}
static bool F_112 ( struct V_1 * V_1 )
{
struct V_23 * V_23 ;
F_113 (dso, &machine->kernel_dsos, node) {
if ( F_114 ( V_23 ) )
return true ;
}
return false ;
}
static int F_115 ( struct V_1 * V_1 ,
union V_57 * V_58 )
{
struct V_66 * V_66 ;
char V_137 [ V_38 ] ;
enum V_138 V_139 ;
bool V_140 ;
if ( F_112 ( V_1 ) )
return 0 ;
F_40 ( V_1 , V_137 , sizeof( V_137 ) ) ;
if ( F_41 ( V_1 ) )
V_139 = V_85 ;
else
V_139 = V_87 ;
V_140 = memcmp ( V_58 -> V_134 . V_68 ,
V_137 ,
strlen ( V_137 ) - 1 ) == 0 ;
if ( V_58 -> V_134 . V_68 [ 0 ] == '/' ||
( ! V_140 && V_58 -> V_134 . V_68 [ 0 ] == '[' ) ) {
char V_141 [ 1024 ] ;
char * V_92 , * V_127 ;
if ( V_58 -> V_134 . V_68 [ 0 ] == '/' ) {
V_92 = strrchr ( V_58 -> V_134 . V_68 , '/' ) ;
if ( V_92 == NULL )
goto V_142;
++ V_92 ;
V_127 = strrchr ( V_92 , '.' ) ;
if ( V_127 == NULL )
goto V_142;
snprintf ( V_141 , sizeof( V_141 ) ,
L_35 , ( int ) ( V_127 - V_92 ) , V_92 ) ;
F_101 ( V_141 , '-' , '_' ) ;
} else
strcpy ( V_141 , V_58 -> V_134 . V_68 ) ;
V_66 = F_57 ( V_1 , V_58 -> V_134 . V_67 ,
V_58 -> V_134 . V_68 ) ;
if ( V_66 == NULL )
goto V_142;
V_92 = F_5 ( V_141 ) ;
if ( V_92 == NULL )
goto V_142;
F_116 ( V_66 -> V_23 , V_92 , true ) ;
V_66 -> V_135 = V_66 -> V_67 + V_58 -> V_134 . V_136 ;
} else if ( V_140 ) {
const char * V_91 = ( V_58 -> V_134 . V_68 +
strlen ( V_137 ) ) ;
struct V_23 * V_84 = F_58 ( & V_1 -> V_7 ,
V_137 ) ;
if ( V_84 == NULL )
goto V_142;
V_84 -> V_84 = V_139 ;
if ( F_79 ( V_1 , V_84 ) < 0 )
goto V_142;
F_111 ( V_1 , V_58 ) ;
if ( V_58 -> V_134 . V_143 != 0 ) {
F_110 ( V_1 -> V_79 ,
V_91 ,
V_58 -> V_134 . V_143 ) ;
}
if ( F_42 ( V_1 ) ) {
F_117 ( V_84 , V_1 -> V_79 [ V_69 ] ,
NULL ) ;
}
}
return 0 ;
V_142:
return - 1 ;
}
int F_118 ( struct V_1 * V_1 ,
union V_57 * V_58 ,
struct V_59 * V_60 V_62 )
{
T_9 V_144 = V_58 -> V_145 . V_146 & V_147 ;
struct V_17 * V_17 ;
struct V_66 * V_66 ;
enum V_95 type ;
int V_74 = 0 ;
if ( V_61 )
F_119 ( V_58 , stdout ) ;
if ( V_144 == V_148 ||
V_144 == V_149 ) {
V_74 = F_115 ( V_1 , V_58 ) ;
if ( V_74 < 0 )
goto V_142;
return 0 ;
}
V_17 = F_6 ( V_1 , V_58 -> V_150 . V_3 ,
V_58 -> V_150 . V_53 ) ;
if ( V_17 == NULL )
goto V_142;
if ( V_58 -> V_145 . V_146 & V_151 )
type = V_152 ;
else
type = V_69 ;
V_66 = F_120 ( V_1 , V_58 -> V_150 . V_67 ,
V_58 -> V_150 . V_136 , V_58 -> V_150 . V_143 ,
V_58 -> V_150 . V_3 , V_58 -> V_150 . V_153 ,
V_58 -> V_150 . V_154 , V_58 -> V_150 . V_155 ,
V_58 -> V_150 . V_156 ,
V_58 -> V_150 . V_157 ,
V_58 -> V_150 . V_158 ,
V_58 -> V_150 . V_68 , type , V_17 ) ;
if ( V_66 == NULL )
goto V_142;
F_121 ( V_17 , V_66 ) ;
return 0 ;
V_142:
F_55 ( L_43 ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_1 , union V_57 * V_58 ,
struct V_59 * V_60 V_62 )
{
T_9 V_144 = V_58 -> V_145 . V_146 & V_147 ;
struct V_17 * V_17 ;
struct V_66 * V_66 ;
enum V_95 type ;
int V_74 = 0 ;
if ( V_61 )
F_123 ( V_58 , stdout ) ;
if ( V_144 == V_148 ||
V_144 == V_149 ) {
V_74 = F_115 ( V_1 , V_58 ) ;
if ( V_74 < 0 )
goto V_142;
return 0 ;
}
V_17 = F_6 ( V_1 , V_58 -> V_134 . V_3 ,
V_58 -> V_134 . V_53 ) ;
if ( V_17 == NULL )
goto V_142;
if ( V_58 -> V_145 . V_146 & V_151 )
type = V_152 ;
else
type = V_69 ;
V_66 = F_120 ( V_1 , V_58 -> V_134 . V_67 ,
V_58 -> V_134 . V_136 , V_58 -> V_134 . V_143 ,
V_58 -> V_134 . V_3 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_58 -> V_134 . V_68 ,
type , V_17 ) ;
if ( V_66 == NULL )
goto V_142;
F_121 ( V_17 , V_66 ) ;
return 0 ;
V_142:
F_55 ( L_44 ) ;
return 0 ;
}
static void F_124 ( struct V_1 * V_1 , struct V_17 * V_50 )
{
V_1 -> V_11 = NULL ;
F_19 ( & V_50 -> V_5 , & V_1 -> V_8 ) ;
F_125 ( & V_50 -> V_26 , & V_1 -> V_10 ) ;
}
int F_126 ( struct V_1 * V_1 , union V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_17 * V_17 = F_52 ( V_1 ,
V_58 -> V_159 . V_3 ,
V_58 -> V_159 . V_53 ) ;
struct V_17 * V_33 = F_6 ( V_1 ,
V_58 -> V_159 . V_160 ,
V_58 -> V_159 . V_161 ) ;
if ( V_17 != NULL )
F_124 ( V_1 , V_17 ) ;
V_17 = F_6 ( V_1 , V_58 -> V_159 . V_3 ,
V_58 -> V_159 . V_53 ) ;
if ( V_61 )
F_127 ( V_58 , stdout ) ;
if ( V_17 == NULL || V_33 == NULL ||
F_128 ( V_17 , V_33 , V_60 -> time ) < 0 ) {
F_55 ( L_45 ) ;
return - 1 ;
}
return 0 ;
}
int F_129 ( struct V_1 * V_1 , union V_57 * V_58 ,
struct V_59 * V_60 V_62 )
{
struct V_17 * V_17 = F_52 ( V_1 ,
V_58 -> V_159 . V_3 ,
V_58 -> V_159 . V_53 ) ;
if ( V_61 )
F_127 ( V_58 , stdout ) ;
if ( V_17 != NULL )
F_130 ( V_17 ) ;
return 0 ;
}
int F_131 ( struct V_1 * V_1 , union V_57 * V_58 ,
struct V_59 * V_60 )
{
int V_74 ;
switch ( V_58 -> V_145 . type ) {
case V_162 :
V_74 = F_53 ( V_1 , V_58 , V_60 ) ; break;
case V_163 :
V_74 = F_122 ( V_1 , V_58 , V_60 ) ; break;
case V_164 :
V_74 = F_118 ( V_1 , V_58 , V_60 ) ; break;
case V_165 :
V_74 = F_126 ( V_1 , V_58 , V_60 ) ; break;
case V_166 :
V_74 = F_129 ( V_1 , V_58 , V_60 ) ; break;
case V_167 :
V_74 = F_56 ( V_1 , V_58 , V_60 ) ; break;
default:
V_74 = - 1 ;
break;
}
return V_74 ;
}
static bool F_132 ( struct V_168 * V_169 , T_10 * V_170 )
{
if ( V_169 -> V_92 && ! regexec ( V_170 , V_169 -> V_92 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_133 ( struct V_1 * V_1 , struct V_17 * V_17 ,
struct V_171 * V_172 ,
T_6 V_173 )
{
struct V_174 V_175 ;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
F_134 ( V_17 , V_1 , V_69 , V_173 , & V_175 ) ;
V_172 -> V_93 = V_173 ;
V_172 -> V_176 = V_175 . V_93 ;
V_172 -> V_169 = V_175 . V_169 ;
V_172 -> V_66 = V_175 . V_66 ;
}
static void F_135 ( struct V_1 * V_1 , struct V_17 * V_17 ,
T_9 V_177 , struct V_171 * V_172 , T_6 V_93 )
{
struct V_174 V_175 ;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
F_136 ( V_17 , V_1 , V_177 , V_152 , V_93 ,
& V_175 ) ;
V_172 -> V_93 = V_93 ;
V_172 -> V_176 = V_175 . V_93 ;
V_172 -> V_169 = V_175 . V_169 ;
V_172 -> V_66 = V_175 . V_66 ;
}
struct V_178 * F_137 ( struct V_59 * V_60 ,
struct V_174 * V_175 )
{
struct V_178 * V_179 = F_138 ( sizeof( * V_179 ) ) ;
if ( ! V_179 )
return NULL ;
F_133 ( V_175 -> V_1 , V_175 -> V_17 , & V_179 -> V_180 , V_60 -> V_173 ) ;
F_135 ( V_175 -> V_1 , V_175 -> V_17 , V_175 -> V_144 ,
& V_179 -> V_181 , V_60 -> V_93 ) ;
V_179 -> V_182 . V_183 = V_60 -> V_182 ;
return V_179 ;
}
struct V_184 * F_139 ( struct V_59 * V_60 ,
struct V_174 * V_175 )
{
unsigned int V_76 ;
const struct V_185 * V_186 = V_60 -> V_185 ;
struct V_184 * V_187 = calloc ( V_186 -> V_188 , sizeof( struct V_184 ) ) ;
if ( ! V_187 )
return NULL ;
for ( V_76 = 0 ; V_76 < V_186 -> V_188 ; V_76 ++ ) {
F_133 ( V_175 -> V_1 , V_175 -> V_17 , & V_187 [ V_76 ] . V_189 , V_186 -> V_190 [ V_76 ] . V_189 ) ;
F_133 ( V_175 -> V_1 , V_175 -> V_17 , & V_187 [ V_76 ] . V_191 , V_186 -> V_190 [ V_76 ] . V_191 ) ;
V_187 [ V_76 ] . V_158 = V_186 -> V_190 [ V_76 ] . V_158 ;
}
return V_187 ;
}
static int F_140 ( struct V_1 * V_1 ,
struct V_17 * V_17 ,
struct V_192 * V_193 ,
struct V_168 * * V_33 ,
struct V_174 * V_194 ,
int V_195 )
{
T_9 V_144 = V_196 ;
int V_197 = V_154 ( V_195 , ( int ) V_193 -> V_188 ) ;
int V_76 ;
int V_198 ;
int V_199 ;
int T_11 V_62 ;
F_141 ( & V_200 ) ;
if ( V_193 -> V_188 > V_201 ) {
F_142 ( L_46 ) ;
return 0 ;
}
T_11 = F_143 ( V_1 , V_17 , V_193 ) ;
for ( V_76 = 0 ; V_76 < V_197 ; V_76 ++ ) {
T_6 V_173 ;
struct V_174 V_175 ;
if ( V_202 . V_203 == V_204 )
V_198 = V_76 ;
else
V_198 = V_193 -> V_188 - V_76 - 1 ;
#ifdef F_144
if ( V_198 == T_11 )
continue;
#endif
V_173 = V_193 -> V_205 [ V_198 ] ;
if ( V_173 >= V_206 ) {
switch ( V_173 ) {
case V_207 :
V_144 = V_208 ;
break;
case V_209 :
V_144 = V_149 ;
break;
case V_210 :
V_144 = V_196 ;
break;
default:
F_87 ( L_47
L_48 V_211 L_14 , ( V_212 ) V_173 ) ;
F_141 ( & V_200 ) ;
return 0 ;
}
continue;
}
V_175 . V_213 = 0 ;
F_136 ( V_17 , V_1 , V_144 ,
V_69 , V_173 , & V_175 ) ;
if ( V_175 . V_169 != NULL ) {
if ( V_214 && ! * V_33 &&
F_132 ( V_175 . V_169 , & V_215 ) )
* V_33 = V_175 . V_169 ;
else if ( V_216 && V_194 &&
F_132 ( V_175 . V_169 , & V_217 ) ) {
* V_194 = V_175 ;
F_141 ( & V_200 ) ;
}
}
V_199 = F_145 ( & V_200 ,
V_173 , V_175 . V_66 , V_175 . V_169 ) ;
if ( V_199 )
return V_199 ;
}
return 0 ;
}
static int F_146 ( struct F_146 * V_218 , void * V_131 )
{
struct V_200 * V_219 = V_131 ;
return F_145 ( V_219 , V_218 -> V_173 ,
V_218 -> V_66 , V_218 -> V_169 ) ;
}
int F_147 ( struct V_1 * V_1 ,
struct V_220 * V_221 ,
struct V_17 * V_17 ,
struct V_59 * V_60 ,
struct V_168 * * V_33 ,
struct V_174 * V_194 ,
int V_195 )
{
int V_74 ;
V_74 = F_140 ( V_1 , V_17 ,
V_60 -> V_222 , V_33 ,
V_194 , V_195 ) ;
if ( V_74 )
return V_74 ;
if ( ! ( ( V_221 -> V_223 . V_224 & V_225 ) &&
( V_221 -> V_223 . V_224 & V_226 ) ) )
return 0 ;
if ( ( ! V_60 -> V_227 . V_228 ) ||
( ! V_60 -> V_229 . V_49 ) )
return 0 ;
return F_148 ( F_146 , & V_200 , V_1 ,
V_17 , V_60 , V_195 ) ;
}
int F_149 ( struct V_1 * V_1 ,
int (* F_150)( struct V_17 * V_17 , void * V_32 ) ,
void * V_230 )
{
struct V_5 * V_28 ;
struct V_17 * V_17 ;
int V_231 = 0 ;
for ( V_28 = F_17 ( & V_1 -> V_8 ) ; V_28 ; V_28 = F_20 ( V_28 ) ) {
V_17 = F_18 ( V_28 , struct V_17 , V_5 ) ;
V_231 = F_150 ( V_17 , V_230 ) ;
if ( V_231 != 0 )
return V_231 ;
}
F_113 (thread, &machine->dead_threads, node) {
V_231 = F_150 ( V_17 , V_230 ) ;
if ( V_231 != 0 )
return V_231 ;
}
return V_231 ;
}
int F_151 ( struct V_1 * V_1 , struct V_232 * V_233 ,
struct V_234 * V_234 , struct V_235 * V_8 ,
T_12 V_46 , bool V_236 )
{
if ( F_152 ( V_234 ) )
return F_153 ( V_233 , V_8 , V_46 , V_1 , V_236 ) ;
else if ( F_154 ( V_234 ) )
return F_155 ( V_233 , V_46 , V_1 , V_236 ) ;
return 0 ;
}
T_1 F_156 ( struct V_1 * V_1 , int V_237 )
{
if ( V_237 < 0 || V_237 >= V_238 || ! V_1 -> V_19 )
return - 1 ;
return V_1 -> V_19 [ V_237 ] ;
}
int F_157 ( struct V_1 * V_1 , int V_237 , T_1 V_3 ,
T_1 V_53 )
{
struct V_17 * V_17 ;
if ( V_237 < 0 )
return - V_239 ;
if ( ! V_1 -> V_19 ) {
int V_76 ;
V_1 -> V_19 = calloc ( V_238 , sizeof( T_1 ) ) ;
if ( ! V_1 -> V_19 )
return - V_15 ;
for ( V_76 = 0 ; V_76 < V_238 ; V_76 ++ )
V_1 -> V_19 [ V_76 ] = - 1 ;
}
if ( V_237 >= V_238 ) {
F_37 ( L_49 , V_237 ) ;
F_37 ( L_50 ) ;
return - V_239 ;
}
V_1 -> V_19 [ V_237 ] = V_53 ;
V_17 = F_6 ( V_1 , V_3 , V_53 ) ;
if ( ! V_17 )
return - V_15 ;
V_17 -> V_237 = V_237 ;
return 0 ;
}
