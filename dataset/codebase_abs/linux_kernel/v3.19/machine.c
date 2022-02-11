static void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
V_1 -> V_3 = V_4 ;
}
int F_3 ( struct V_5 * V_5 , const char * V_6 , T_1 V_7 )
{
F_4 ( & V_5 -> V_8 , V_5 ) ;
F_5 ( & V_5 -> V_9 ) ;
F_1 ( & V_5 -> V_10 ) ;
F_1 ( & V_5 -> V_11 ) ;
V_5 -> V_12 = V_4 ;
F_2 ( & V_5 -> V_13 ) ;
V_5 -> V_14 = NULL ;
V_5 -> V_15 = NULL ;
V_5 -> V_7 = V_7 ;
V_5 -> V_16 = NULL ;
V_5 -> V_17 = 0 ;
V_5 -> V_18 = false ;
V_5 -> V_19 = 0 ;
V_5 -> V_6 = F_6 ( V_6 ) ;
if ( V_5 -> V_6 == NULL )
return - V_20 ;
if ( V_7 != V_21 ) {
struct V_22 * V_22 = F_7 ( V_5 , - 1 ,
V_7 ) ;
char V_23 [ 64 ] ;
if ( V_22 == NULL )
return - V_20 ;
snprintf ( V_23 , sizeof( V_23 ) , L_1 , V_7 ) ;
F_8 ( V_22 , V_23 , 0 ) ;
}
V_5 -> V_24 = NULL ;
return 0 ;
}
struct V_5 * F_9 ( void )
{
struct V_5 * V_5 = malloc ( sizeof( * V_5 ) ) ;
if ( V_5 != NULL ) {
F_3 ( V_5 , L_2 , V_21 ) ;
if ( F_10 ( V_5 ) < 0 )
goto V_25;
}
return V_5 ;
V_25:
free ( V_5 ) ;
return NULL ;
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_26 * V_27 , * V_28 ;
F_12 (pos, n, &dsos->head, node) {
F_5 ( & V_27 -> V_9 ) ;
F_13 ( & V_27 -> V_29 ) ;
F_14 ( V_27 ) ;
}
}
void F_15 ( struct V_5 * V_5 )
{
struct V_22 * V_28 , * V_30 ;
F_12 (t, n, &machine->dead_threads, node) {
F_13 ( & V_30 -> V_29 ) ;
F_16 ( V_30 ) ;
}
}
void F_17 ( struct V_5 * V_5 )
{
struct V_9 * V_31 = F_18 ( & V_5 -> V_12 ) ;
while ( V_31 ) {
struct V_22 * V_30 = F_19 ( V_31 , struct V_22 , V_9 ) ;
F_20 ( & V_30 -> V_9 , & V_5 -> V_12 ) ;
V_31 = F_21 ( V_31 ) ;
F_16 ( V_30 ) ;
}
}
void F_22 ( struct V_5 * V_5 )
{
F_23 ( & V_5 -> V_8 ) ;
F_11 ( & V_5 -> V_10 ) ;
F_11 ( & V_5 -> V_11 ) ;
F_24 ( V_5 ) ;
F_25 ( & V_5 -> V_6 ) ;
F_25 ( & V_5 -> V_24 ) ;
}
void F_26 ( struct V_5 * V_5 )
{
F_22 ( V_5 ) ;
free ( V_5 ) ;
}
void F_27 ( struct V_32 * V_32 )
{
F_3 ( & V_32 -> V_33 , L_2 , V_21 ) ;
V_32 -> V_34 = V_4 ;
V_32 -> V_16 = NULL ;
}
void F_28 ( struct V_32 * V_32 )
{
F_22 ( & V_32 -> V_33 ) ;
}
struct V_5 * F_29 ( struct V_32 * V_32 , T_1 V_7 ,
const char * V_6 )
{
struct V_9 * * V_35 = & V_32 -> V_34 . V_9 ;
struct V_9 * V_36 = NULL ;
struct V_5 * V_27 , * V_5 = malloc ( sizeof( * V_5 ) ) ;
if ( V_5 == NULL )
return NULL ;
if ( F_3 ( V_5 , V_6 , V_7 ) != 0 ) {
free ( V_5 ) ;
return NULL ;
}
V_5 -> V_16 = V_32 -> V_16 ;
while ( * V_35 != NULL ) {
V_36 = * V_35 ;
V_27 = F_19 ( V_36 , struct V_5 , V_9 ) ;
if ( V_7 < V_27 -> V_7 )
V_35 = & ( * V_35 ) -> V_37 ;
else
V_35 = & ( * V_35 ) -> V_38 ;
}
F_30 ( & V_5 -> V_9 , V_36 , V_35 ) ;
F_31 ( & V_5 -> V_9 , & V_32 -> V_34 ) ;
return V_5 ;
}
void F_32 ( struct V_32 * V_32 ,
T_2 V_16 )
{
struct V_9 * V_31 ;
V_32 -> V_16 = V_16 ;
V_32 -> V_33 . V_16 = V_16 ;
for ( V_31 = F_18 ( & V_32 -> V_34 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_5 * V_5 = F_19 ( V_31 , struct V_5 , V_9 ) ;
V_5 -> V_16 = V_16 ;
}
}
void F_33 ( struct V_32 * V_32 , bool V_18 )
{
struct V_9 * V_31 ;
V_32 -> V_33 . V_18 = V_18 ;
for ( V_31 = F_18 ( & V_32 -> V_34 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_5 * V_5 = F_19 ( V_31 , struct V_5 , V_9 ) ;
V_5 -> V_18 = V_18 ;
}
}
struct V_5 * F_34 ( struct V_32 * V_32 , T_1 V_7 )
{
struct V_9 * * V_35 = & V_32 -> V_34 . V_9 ;
struct V_9 * V_36 = NULL ;
struct V_5 * V_5 ;
struct V_5 * V_39 = NULL ;
if ( V_7 == V_21 )
return & V_32 -> V_33 ;
while ( * V_35 != NULL ) {
V_36 = * V_35 ;
V_5 = F_19 ( V_36 , struct V_5 , V_9 ) ;
if ( V_7 < V_5 -> V_7 )
V_35 = & ( * V_35 ) -> V_37 ;
else if ( V_7 > V_5 -> V_7 )
V_35 = & ( * V_35 ) -> V_38 ;
else
return V_5 ;
if ( ! V_5 -> V_7 )
V_39 = V_5 ;
}
return V_39 ;
}
struct V_5 * F_35 ( struct V_32 * V_32 , T_1 V_7 )
{
char V_40 [ V_41 ] ;
const char * V_6 = L_2 ;
struct V_5 * V_5 = F_34 ( V_32 , V_7 ) ;
if ( V_5 && ( V_5 -> V_7 == V_7 ) )
goto V_42;
if ( ( V_7 != V_21 ) &&
( V_7 != V_43 ) &&
( V_44 . V_45 ) ) {
sprintf ( V_40 , L_3 , V_44 . V_45 , V_7 ) ;
if ( F_36 ( V_40 , V_46 ) ) {
static struct V_47 * V_48 ;
if ( ! V_48 )
V_48 = F_37 ( true , NULL ) ;
if ( ! F_38 ( V_48 , V_40 ) ) {
F_39 ( L_4 , V_40 ) ;
F_40 ( V_48 , V_40 ) ;
}
V_5 = NULL ;
goto V_42;
}
V_6 = V_40 ;
}
V_5 = F_29 ( V_32 , V_7 , V_6 ) ;
V_42:
return V_5 ;
}
void F_41 ( struct V_32 * V_32 ,
T_3 V_49 , void * V_50 )
{
struct V_9 * V_31 ;
for ( V_31 = F_18 ( & V_32 -> V_34 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_5 * V_27 = F_19 ( V_31 , struct V_5 , V_9 ) ;
V_49 ( V_27 , V_50 ) ;
}
}
char * F_42 ( struct V_5 * V_5 , char * V_51 , T_4 V_52 )
{
if ( F_43 ( V_5 ) )
snprintf ( V_51 , V_52 , L_5 , L_6 ) ;
else if ( F_44 ( V_5 ) )
snprintf ( V_51 , V_52 , L_5 , L_7 ) ;
else {
snprintf ( V_51 , V_52 , L_8 , L_7 ,
V_5 -> V_7 ) ;
}
return V_51 ;
}
void F_45 ( struct V_32 * V_32 , T_5 V_17 )
{
struct V_9 * V_29 ;
struct V_5 * V_5 ;
V_32 -> V_33 . V_17 = V_17 ;
for ( V_29 = F_18 ( & V_32 -> V_34 ) ; V_29 ; V_29 = F_21 ( V_29 ) ) {
V_5 = F_19 ( V_29 , struct V_5 , V_9 ) ;
V_5 -> V_17 = V_17 ;
}
return;
}
static void F_46 ( struct V_5 * V_5 ,
struct V_22 * V_53 , T_1 V_7 )
{
struct V_22 * V_54 ;
if ( V_7 == V_53 -> V_55 || V_7 == - 1 || V_53 -> V_55 != - 1 )
return;
V_53 -> V_55 = V_7 ;
if ( V_53 -> V_55 == V_53 -> V_56 )
return;
V_54 = F_7 ( V_5 , V_53 -> V_55 , V_53 -> V_55 ) ;
if ( ! V_54 )
goto V_57;
if ( ! V_54 -> V_58 )
V_54 -> V_58 = F_47 ( V_5 ) ;
if ( ! V_54 -> V_58 )
goto V_57;
if ( V_53 -> V_58 == V_54 -> V_58 )
return;
if ( V_53 -> V_58 ) {
if ( ! F_48 ( V_53 -> V_58 ) )
F_39 ( L_9 ,
V_53 -> V_55 , V_53 -> V_56 ) ;
F_49 ( V_53 -> V_58 ) ;
}
V_53 -> V_58 = F_50 ( V_54 -> V_58 ) ;
return;
V_57:
F_39 ( L_10 , V_53 -> V_55 , V_53 -> V_56 ) ;
}
static struct V_22 * F_51 ( struct V_5 * V_5 ,
T_1 V_7 , T_1 V_56 ,
bool V_59 )
{
struct V_9 * * V_35 = & V_5 -> V_12 . V_9 ;
struct V_9 * V_36 = NULL ;
struct V_22 * V_53 ;
V_53 = V_5 -> V_14 ;
if ( V_53 && V_53 -> V_56 == V_56 ) {
F_46 ( V_5 , V_53 , V_7 ) ;
return V_53 ;
}
while ( * V_35 != NULL ) {
V_36 = * V_35 ;
V_53 = F_19 ( V_36 , struct V_22 , V_9 ) ;
if ( V_53 -> V_56 == V_56 ) {
V_5 -> V_14 = V_53 ;
F_46 ( V_5 , V_53 , V_7 ) ;
return V_53 ;
}
if ( V_56 < V_53 -> V_56 )
V_35 = & ( * V_35 ) -> V_37 ;
else
V_35 = & ( * V_35 ) -> V_38 ;
}
if ( ! V_59 )
return NULL ;
V_53 = F_52 ( V_7 , V_56 ) ;
if ( V_53 != NULL ) {
F_30 ( & V_53 -> V_9 , V_36 , V_35 ) ;
F_31 ( & V_53 -> V_9 , & V_5 -> V_12 ) ;
if ( F_53 ( V_53 , V_5 ) ) {
F_20 ( & V_53 -> V_9 , & V_5 -> V_12 ) ;
F_16 ( V_53 ) ;
return NULL ;
}
V_5 -> V_14 = V_53 ;
}
return V_53 ;
}
struct V_22 * F_7 ( struct V_5 * V_5 , T_1 V_7 ,
T_1 V_56 )
{
return F_51 ( V_5 , V_7 , V_56 , true ) ;
}
struct V_22 * F_54 ( struct V_5 * V_5 , T_1 V_7 ,
T_1 V_56 )
{
return F_51 ( V_5 , V_7 , V_56 , false ) ;
}
struct V_23 * F_55 ( struct V_5 * V_5 ,
struct V_22 * V_22 )
{
if ( V_5 -> V_18 )
return F_56 ( V_22 ) ;
else
return F_57 ( V_22 ) ;
}
int F_58 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_22 * V_22 = F_7 ( V_5 ,
V_61 -> V_23 . V_7 ,
V_61 -> V_23 . V_56 ) ;
bool V_64 = V_61 -> V_65 . V_66 & V_67 ;
if ( V_64 )
V_5 -> V_18 = true ;
if ( V_68 )
F_59 ( V_61 , stdout ) ;
if ( V_22 == NULL ||
F_60 ( V_22 , V_61 -> V_23 . V_23 , V_63 -> time , V_64 ) ) {
F_61 ( L_11 ) ;
return - 1 ;
}
return 0 ;
}
int F_62 ( struct V_5 * V_5 V_69 ,
union V_60 * V_61 , struct V_62 * V_63 V_69 )
{
F_61 ( L_12 V_70 L_13 V_70 L_14 ,
V_61 -> V_71 . V_72 , V_61 -> V_71 . V_71 ) ;
return 0 ;
}
struct V_73 * F_63 ( struct V_5 * V_5 , T_6 V_74 ,
const char * V_75 )
{
struct V_73 * V_73 ;
struct V_26 * V_26 = F_64 ( & V_5 -> V_11 , V_75 ) ;
bool V_76 ;
if ( V_26 == NULL )
return NULL ;
V_73 = F_65 ( V_74 , V_26 , V_77 ) ;
if ( V_73 == NULL )
return NULL ;
if ( F_43 ( V_5 ) )
V_26 -> V_78 = V_79 ;
else
V_26 -> V_78 = V_80 ;
if ( F_66 ( V_75 , & V_76 ) && V_76 )
V_26 -> V_78 ++ ;
F_67 ( & V_5 -> V_8 , V_73 ) ;
return V_73 ;
}
T_4 F_68 ( struct V_32 * V_32 , T_7 * V_81 )
{
struct V_9 * V_31 ;
T_4 V_82 = F_69 ( & V_32 -> V_33 . V_11 . V_2 , V_81 ) +
F_69 ( & V_32 -> V_33 . V_10 . V_2 , V_81 ) ;
for ( V_31 = F_18 ( & V_32 -> V_34 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_5 * V_27 = F_19 ( V_31 , struct V_5 , V_9 ) ;
V_82 += F_69 ( & V_27 -> V_11 . V_2 , V_81 ) ;
V_82 += F_69 ( & V_27 -> V_10 . V_2 , V_81 ) ;
}
return V_82 ;
}
T_4 F_70 ( struct V_5 * V_83 , T_7 * V_81 ,
bool (F_71)( struct V_26 * V_26 , int V_84 ) , int V_84 )
{
return F_72 ( & V_83 -> V_11 . V_2 , V_81 , F_71 , V_84 ) +
F_72 ( & V_83 -> V_10 . V_2 , V_81 , F_71 , V_84 ) ;
}
T_4 F_73 ( struct V_32 * V_32 , T_7 * V_81 ,
bool (F_71)( struct V_26 * V_26 , int V_84 ) , int V_84 )
{
struct V_9 * V_31 ;
T_4 V_82 = F_70 ( & V_32 -> V_33 , V_81 , F_71 , V_84 ) ;
for ( V_31 = F_18 ( & V_32 -> V_34 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_5 * V_27 = F_19 ( V_31 , struct V_5 , V_9 ) ;
V_82 += F_70 ( V_27 , V_81 , F_71 , V_84 ) ;
}
return V_82 ;
}
T_4 F_74 ( struct V_5 * V_5 , T_7 * V_81 )
{
int V_85 ;
T_4 V_86 = 0 ;
struct V_26 * V_87 = V_5 -> V_88 [ V_77 ] -> V_26 ;
if ( V_87 -> V_89 ) {
char V_75 [ V_41 ] ;
if ( F_75 ( V_87 , V_75 , sizeof( V_75 ) ) )
V_86 += fprintf ( V_81 , L_15 , V_75 ) ;
}
for ( V_85 = 0 ; V_85 < V_90 ; ++ V_85 )
V_86 += fprintf ( V_81 , L_16 ,
V_85 + V_87 -> V_89 , V_91 [ V_85 ] ) ;
return V_86 ;
}
T_4 F_76 ( struct V_5 * V_5 , T_7 * V_81 )
{
T_4 V_82 = 0 ;
struct V_9 * V_31 ;
for ( V_31 = F_18 ( & V_5 -> V_12 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_22 * V_27 = F_19 ( V_31 , struct V_22 , V_9 ) ;
V_82 += F_77 ( V_27 , V_81 ) ;
}
return V_82 ;
}
static struct V_26 * F_78 ( struct V_5 * V_5 )
{
const char * V_92 = NULL ;
struct V_26 * V_93 ;
if ( F_43 ( V_5 ) ) {
V_92 = V_44 . V_92 ;
if ( ! V_92 )
V_92 = L_17 ;
V_93 = F_79 ( V_5 , V_92 ,
L_18 ,
V_94 ) ;
} else {
char V_51 [ V_41 ] ;
if ( F_44 ( V_5 ) )
V_92 = V_44 . V_95 ;
if ( ! V_92 )
V_92 = F_42 ( V_5 , V_51 ,
sizeof( V_51 ) ) ;
V_93 = F_79 ( V_5 , V_92 ,
L_19 ,
V_96 ) ;
}
if ( V_93 != NULL && ( ! V_93 -> V_89 ) )
F_80 ( V_93 , V_5 ) ;
return V_93 ;
}
static void F_81 ( struct V_5 * V_5 , char * V_97 ,
T_4 V_98 )
{
if ( F_44 ( V_5 ) )
F_82 ( V_97 , V_98 , L_20 , V_44 . V_99 ) ;
else
F_82 ( V_97 , V_98 , L_21 , V_5 -> V_6 ) ;
}
static T_6 F_83 ( struct V_5 * V_5 ,
const char * * V_100 )
{
char V_75 [ V_41 ] ;
int V_85 ;
const char * V_101 ;
T_6 V_102 = 0 ;
F_81 ( V_5 , V_75 , V_41 ) ;
if ( F_84 ( V_75 , L_22 ) )
return 0 ;
for ( V_85 = 0 ; ( V_101 = V_103 [ V_85 ] ) != NULL ; V_85 ++ ) {
V_102 = F_85 ( V_75 , V_101 ) ;
if ( V_102 )
break;
}
if ( V_100 )
* V_100 = V_101 ;
return V_102 ;
}
int F_86 ( struct V_5 * V_5 , struct V_26 * V_93 )
{
enum V_104 type ;
T_6 V_74 = F_83 ( V_5 , NULL ) ;
for ( type = 0 ; type < V_105 ; ++ type ) {
struct V_106 * V_106 ;
V_5 -> V_88 [ type ] = F_65 ( V_74 , V_93 , type ) ;
if ( V_5 -> V_88 [ type ] == NULL )
return - 1 ;
V_5 -> V_88 [ type ] -> V_107 =
V_5 -> V_88 [ type ] -> V_108 =
V_109 ;
V_106 = F_87 ( V_5 -> V_88 [ type ] ) ;
V_106 -> V_8 = & V_5 -> V_8 ;
F_67 ( & V_5 -> V_8 ,
V_5 -> V_88 [ type ] ) ;
}
return 0 ;
}
void F_88 ( struct V_5 * V_5 )
{
enum V_104 type ;
for ( type = 0 ; type < V_105 ; ++ type ) {
struct V_106 * V_106 ;
if ( V_5 -> V_88 [ type ] == NULL )
continue;
V_106 = F_87 ( V_5 -> V_88 [ type ] ) ;
F_89 ( & V_5 -> V_8 ,
V_5 -> V_88 [ type ] ) ;
if ( V_106 -> V_110 ) {
if ( type == V_77 ) {
F_25 ( ( char * * ) & V_106 -> V_110 -> V_101 ) ;
F_25 ( & V_106 -> V_110 ) ;
} else
V_106 -> V_110 = NULL ;
}
F_90 ( V_5 -> V_88 [ type ] ) ;
V_5 -> V_88 [ type ] = NULL ;
}
}
int F_91 ( struct V_32 * V_32 )
{
int V_82 = 0 ;
struct V_111 * * V_112 = NULL ;
int V_85 , V_113 = 0 ;
char V_40 [ V_41 ] ;
T_1 V_7 ;
char * V_114 ;
if ( V_44 . V_95 ||
V_44 . V_115 ||
V_44 . V_99 ) {
F_92 ( V_32 , V_43 ) ;
}
if ( V_44 . V_45 ) {
V_113 = F_93 ( V_44 . V_45 , & V_112 , NULL , NULL ) ;
if ( V_113 <= 0 )
return - V_116 ;
for ( V_85 = 0 ; V_85 < V_113 ; V_85 ++ ) {
if ( ! isdigit ( V_112 [ V_85 ] -> V_117 [ 0 ] ) ) {
continue;
}
V_7 = ( T_1 ) strtol ( V_112 [ V_85 ] -> V_117 , & V_114 , 10 ) ;
if ( ( * V_114 != '\0' ) ||
( V_114 == V_112 [ V_85 ] -> V_117 ) ||
( V_118 == V_119 ) ) {
F_94 ( L_23 ,
V_112 [ V_85 ] -> V_117 ) ;
continue;
}
sprintf ( V_40 , L_24 ,
V_44 . V_45 ,
V_112 [ V_85 ] -> V_117 ) ;
V_82 = F_36 ( V_40 , V_46 ) ;
if ( V_82 ) {
F_94 ( L_4 , V_40 ) ;
goto V_120;
}
F_92 ( V_32 , V_7 ) ;
}
V_120:
free ( V_112 ) ;
}
return V_82 ;
}
void F_95 ( struct V_32 * V_32 )
{
struct V_9 * V_121 = F_18 ( & V_32 -> V_34 ) ;
F_88 ( & V_32 -> V_33 ) ;
while ( V_121 ) {
struct V_5 * V_27 = F_19 ( V_121 , struct V_5 , V_9 ) ;
V_121 = F_21 ( & V_27 -> V_9 ) ;
F_20 ( & V_27 -> V_9 , & V_32 -> V_34 ) ;
F_26 ( V_27 ) ;
}
}
int F_92 ( struct V_32 * V_32 , T_1 V_7 )
{
struct V_5 * V_5 = F_35 ( V_32 , V_7 ) ;
if ( V_5 == NULL )
return - 1 ;
return F_10 ( V_5 ) ;
}
int F_96 ( struct V_5 * V_5 , const char * V_75 ,
enum V_104 type , T_2 V_122 )
{
struct V_73 * V_73 = V_5 -> V_88 [ type ] ;
int V_82 = F_97 ( V_73 -> V_26 , V_75 , V_73 , V_122 ) ;
if ( V_82 > 0 ) {
F_98 ( V_73 -> V_26 , type ) ;
F_99 ( & V_5 -> V_8 , type ) ;
}
return V_82 ;
}
int F_100 ( struct V_5 * V_5 , enum V_104 type ,
T_2 V_122 )
{
struct V_73 * V_73 = V_5 -> V_88 [ type ] ;
int V_82 = F_101 ( V_73 -> V_26 , V_73 , V_122 ) ;
if ( V_82 > 0 )
F_98 ( V_73 -> V_26 , type ) ;
return V_82 ;
}
static void F_102 ( struct V_123 * V_58 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_105 ; ++ V_85 )
F_99 ( V_58 , V_85 ) ;
}
static char * F_103 ( const char * V_6 )
{
char V_124 [ V_41 ] ;
T_7 * V_125 ;
char * V_101 , * V_126 ;
const char * V_127 = L_25 ;
sprintf ( V_124 , L_26 , V_6 ) ;
V_125 = fopen ( V_124 , L_27 ) ;
if ( ! V_125 )
return NULL ;
V_124 [ 0 ] = '\0' ;
V_126 = fgets ( V_124 , sizeof( V_124 ) , V_125 ) ;
fclose ( V_125 ) ;
V_101 = strstr ( V_124 , V_127 ) ;
if ( ! V_101 )
return NULL ;
V_101 += strlen ( V_127 ) ;
V_126 = strchr ( V_101 , ' ' ) ;
if ( V_126 )
* V_126 = '\0' ;
return F_6 ( V_101 ) ;
}
static int F_104 ( struct V_123 * V_58 ,
const char * V_128 , int V_129 )
{
struct V_111 * V_130 ;
T_8 * V_131 = F_105 ( V_128 ) ;
int V_82 = 0 ;
if ( ! V_131 ) {
F_94 ( L_28 , V_132 , V_128 ) ;
return - 1 ;
}
while ( ( V_130 = F_106 ( V_131 ) ) != NULL ) {
char V_40 [ V_41 ] ;
struct V_133 V_134 ;
snprintf ( V_40 , sizeof( V_40 ) , L_29 , V_128 , V_130 -> V_117 ) ;
if ( V_133 ( V_40 , & V_134 ) )
continue;
if ( F_107 ( V_134 . V_135 ) ) {
if ( ! strcmp ( V_130 -> V_117 , L_30 ) ||
! strcmp ( V_130 -> V_117 , L_31 ) )
continue;
if ( V_129 == 0 ) {
if ( ! strcmp ( V_130 -> V_117 , L_32 ) ||
! strcmp ( V_130 -> V_117 , L_33 ) )
continue;
}
V_82 = F_104 ( V_58 , V_40 ,
V_129 + 1 ) ;
if ( V_82 < 0 )
goto V_42;
} else {
char * V_136 = strrchr ( V_130 -> V_117 , '.' ) ,
V_137 [ V_41 ] ;
struct V_73 * V_73 ;
char * V_138 ;
if ( V_136 == NULL )
continue;
if ( F_108 ( V_136 + 1 ) &&
F_109 ( V_136 - 2 ) )
V_136 -= 3 ;
snprintf ( V_137 , sizeof( V_137 ) , L_34 ,
( int ) ( V_136 - V_130 -> V_117 ) , V_130 -> V_117 ) ;
F_110 ( V_137 , '-' , '_' ) ;
V_73 = F_111 ( V_58 , V_77 ,
V_137 ) ;
if ( V_73 == NULL )
continue;
V_138 = F_6 ( V_40 ) ;
if ( V_138 == NULL ) {
V_82 = - 1 ;
goto V_42;
}
F_112 ( V_73 -> V_26 , V_138 , true ) ;
F_113 ( V_73 -> V_26 , L_2 ) ;
}
}
V_42:
F_114 ( V_131 ) ;
return V_82 ;
}
static int F_115 ( struct V_5 * V_5 )
{
char * V_124 ;
char V_139 [ V_41 ] ;
V_124 = F_103 ( V_5 -> V_6 ) ;
if ( ! V_124 )
return - 1 ;
snprintf ( V_139 , sizeof( V_139 ) , L_35 ,
V_5 -> V_6 , V_124 ) ;
free ( V_124 ) ;
return F_104 ( & V_5 -> V_8 , V_139 , 0 ) ;
}
static int F_116 ( void * V_140 , const char * V_101 , T_6 V_74 )
{
struct V_5 * V_5 = V_140 ;
struct V_73 * V_73 ;
V_73 = F_63 ( V_5 , V_74 , V_101 ) ;
if ( V_73 == NULL )
return - 1 ;
F_113 ( V_73 -> V_26 , V_5 -> V_6 ) ;
return 0 ;
}
static int F_117 ( struct V_5 * V_5 )
{
const char * V_141 ;
char V_40 [ V_41 ] ;
if ( F_44 ( V_5 ) ) {
V_141 = V_44 . V_115 ;
} else {
snprintf ( V_40 , V_41 , L_36 , V_5 -> V_6 ) ;
V_141 = V_40 ;
}
if ( F_84 ( V_141 , L_37 ) )
return - 1 ;
if ( F_118 ( V_141 , V_5 , F_116 ) )
return - 1 ;
if ( ! F_115 ( V_5 ) )
return 0 ;
F_94 ( L_38 ) ;
return 0 ;
}
int F_10 ( struct V_5 * V_5 )
{
struct V_26 * V_93 = F_78 ( V_5 ) ;
const char * V_101 ;
T_6 V_102 = F_83 ( V_5 , & V_101 ) ;
if ( ! V_102 )
return - 1 ;
if ( V_93 == NULL ||
F_86 ( V_5 , V_93 ) < 0 )
return - 1 ;
if ( V_44 . V_142 && F_117 ( V_5 ) < 0 ) {
if ( F_43 ( V_5 ) )
F_94 ( L_39
L_40 ) ;
else
F_94 ( L_41
L_40 , V_5 -> V_7 ) ;
}
F_102 ( & V_5 -> V_8 ) ;
if ( F_119 ( V_5 -> V_88 , V_101 ,
V_102 ) ) {
F_88 ( V_5 ) ;
return - 1 ;
}
return 0 ;
}
static void F_120 ( struct V_5 * V_5 ,
union V_60 * V_61 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_105 ; V_85 ++ ) {
V_5 -> V_88 [ V_85 ] -> V_74 = V_61 -> V_143 . V_74 ;
V_5 -> V_88 [ V_85 ] -> V_144 = ( V_61 -> V_143 . V_74 +
V_61 -> V_143 . V_145 ) ;
if ( V_5 -> V_88 [ V_85 ] -> V_144 == 0 )
V_5 -> V_88 [ V_85 ] -> V_144 = ~ 0ULL ;
}
}
static bool F_121 ( struct V_5 * V_5 )
{
struct V_26 * V_26 ;
F_122 (dso, &machine->kernel_dsos.head, node) {
if ( F_123 ( V_26 ) )
return true ;
}
return false ;
}
static int F_124 ( struct V_5 * V_5 ,
union V_60 * V_61 )
{
struct V_73 * V_73 ;
char V_146 [ V_41 ] ;
enum V_147 V_148 ;
bool V_149 ;
if ( F_121 ( V_5 ) )
return 0 ;
F_42 ( V_5 , V_146 , sizeof( V_146 ) ) ;
if ( F_43 ( V_5 ) )
V_148 = V_94 ;
else
V_148 = V_96 ;
V_149 = memcmp ( V_61 -> V_143 . V_75 ,
V_146 ,
strlen ( V_146 ) - 1 ) == 0 ;
if ( V_61 -> V_143 . V_75 [ 0 ] == '/' ||
( ! V_149 && V_61 -> V_143 . V_75 [ 0 ] == '[' ) ) {
char V_150 [ 1024 ] ;
char * V_101 , * V_136 ;
if ( V_61 -> V_143 . V_75 [ 0 ] == '/' ) {
V_101 = strrchr ( V_61 -> V_143 . V_75 , '/' ) ;
if ( V_101 == NULL )
goto V_151;
++ V_101 ;
V_136 = strrchr ( V_101 , '.' ) ;
if ( V_136 == NULL )
goto V_151;
if ( F_108 ( V_136 + 1 ) )
V_136 -= 3 ;
if ( ! F_109 ( V_136 + 1 ) )
goto V_151;
snprintf ( V_150 , sizeof( V_150 ) ,
L_34 , ( int ) ( V_136 - V_101 ) , V_101 ) ;
F_110 ( V_150 , '-' , '_' ) ;
} else
strcpy ( V_150 , V_61 -> V_143 . V_75 ) ;
V_73 = F_63 ( V_5 , V_61 -> V_143 . V_74 ,
V_61 -> V_143 . V_75 ) ;
if ( V_73 == NULL )
goto V_151;
V_101 = F_6 ( V_150 ) ;
if ( V_101 == NULL )
goto V_151;
F_125 ( V_73 -> V_26 , V_101 , true ) ;
V_73 -> V_144 = V_73 -> V_74 + V_61 -> V_143 . V_145 ;
} else if ( V_149 ) {
const char * V_100 = ( V_61 -> V_143 . V_75 +
strlen ( V_146 ) ) ;
struct V_26 * V_93 = NULL ;
struct V_26 * V_26 ;
F_122 (dso, &machine->kernel_dsos.head, node) {
if ( F_66 ( V_26 -> V_138 , NULL ) )
continue;
V_93 = V_26 ;
break;
}
if ( V_93 == NULL )
V_93 = F_64 ( & V_5 -> V_11 ,
V_146 ) ;
if ( V_93 == NULL )
goto V_151;
V_93 -> V_93 = V_148 ;
if ( F_86 ( V_5 , V_93 ) < 0 )
goto V_151;
if ( strstr ( V_93 -> V_138 , L_42 ) )
F_125 ( V_93 , L_43 , false ) ;
F_120 ( V_5 , V_61 ) ;
if ( V_61 -> V_143 . V_152 != 0 ) {
F_119 ( V_5 -> V_88 ,
V_100 ,
V_61 -> V_143 . V_152 ) ;
}
if ( F_44 ( V_5 ) ) {
F_126 ( V_93 , V_5 -> V_88 [ V_77 ] ,
NULL ) ;
}
}
return 0 ;
V_151:
return - 1 ;
}
int F_127 ( struct V_5 * V_5 ,
union V_60 * V_61 ,
struct V_62 * V_63 V_69 )
{
T_9 V_153 = V_61 -> V_65 . V_66 & V_154 ;
struct V_22 * V_22 ;
struct V_73 * V_73 ;
enum V_104 type ;
int V_82 = 0 ;
if ( V_68 )
F_128 ( V_61 , stdout ) ;
if ( V_153 == V_155 ||
V_153 == V_156 ) {
V_82 = F_124 ( V_5 , V_61 ) ;
if ( V_82 < 0 )
goto V_151;
return 0 ;
}
V_22 = F_7 ( V_5 , V_61 -> V_157 . V_7 ,
V_61 -> V_157 . V_56 ) ;
if ( V_22 == NULL )
goto V_151;
if ( V_61 -> V_65 . V_66 & V_158 )
type = V_159 ;
else
type = V_77 ;
V_73 = F_129 ( V_5 , V_61 -> V_157 . V_74 ,
V_61 -> V_157 . V_145 , V_61 -> V_157 . V_152 ,
V_61 -> V_157 . V_7 , V_61 -> V_157 . V_160 ,
V_61 -> V_157 . V_161 , V_61 -> V_157 . V_162 ,
V_61 -> V_157 . V_163 ,
V_61 -> V_157 . V_164 ,
V_61 -> V_157 . V_165 ,
V_61 -> V_157 . V_75 , type , V_22 ) ;
if ( V_73 == NULL )
goto V_151;
F_130 ( V_22 , V_73 ) ;
return 0 ;
V_151:
F_61 ( L_44 ) ;
return 0 ;
}
int F_131 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 V_69 )
{
T_9 V_153 = V_61 -> V_65 . V_66 & V_154 ;
struct V_22 * V_22 ;
struct V_73 * V_73 ;
enum V_104 type ;
int V_82 = 0 ;
if ( V_68 )
F_132 ( V_61 , stdout ) ;
if ( V_153 == V_155 ||
V_153 == V_156 ) {
V_82 = F_124 ( V_5 , V_61 ) ;
if ( V_82 < 0 )
goto V_151;
return 0 ;
}
V_22 = F_7 ( V_5 , V_61 -> V_143 . V_7 ,
V_61 -> V_143 . V_56 ) ;
if ( V_22 == NULL )
goto V_151;
if ( V_61 -> V_65 . V_66 & V_158 )
type = V_159 ;
else
type = V_77 ;
V_73 = F_129 ( V_5 , V_61 -> V_143 . V_74 ,
V_61 -> V_143 . V_145 , V_61 -> V_143 . V_152 ,
V_61 -> V_143 . V_7 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_61 -> V_143 . V_75 ,
type , V_22 ) ;
if ( V_73 == NULL )
goto V_151;
F_130 ( V_22 , V_73 ) ;
return 0 ;
V_151:
F_61 ( L_45 ) ;
return 0 ;
}
static void F_133 ( struct V_5 * V_5 , struct V_22 * V_53 )
{
V_5 -> V_14 = NULL ;
F_20 ( & V_53 -> V_9 , & V_5 -> V_12 ) ;
F_134 ( & V_53 -> V_29 , & V_5 -> V_13 ) ;
}
int F_135 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_22 * V_22 = F_54 ( V_5 ,
V_61 -> V_166 . V_7 ,
V_61 -> V_166 . V_56 ) ;
struct V_22 * V_36 = F_7 ( V_5 ,
V_61 -> V_166 . V_167 ,
V_61 -> V_166 . V_168 ) ;
if ( V_22 != NULL )
F_133 ( V_5 , V_22 ) ;
V_22 = F_7 ( V_5 , V_61 -> V_166 . V_7 ,
V_61 -> V_166 . V_56 ) ;
if ( V_68 )
F_136 ( V_61 , stdout ) ;
if ( V_22 == NULL || V_36 == NULL ||
F_137 ( V_22 , V_36 , V_63 -> time ) < 0 ) {
F_61 ( L_46 ) ;
return - 1 ;
}
return 0 ;
}
int F_138 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 V_69 )
{
struct V_22 * V_22 = F_54 ( V_5 ,
V_61 -> V_166 . V_7 ,
V_61 -> V_166 . V_56 ) ;
if ( V_68 )
F_136 ( V_61 , stdout ) ;
if ( V_22 != NULL )
F_139 ( V_22 ) ;
return 0 ;
}
int F_140 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
int V_82 ;
switch ( V_61 -> V_65 . type ) {
case V_169 :
V_82 = F_58 ( V_5 , V_61 , V_63 ) ; break;
case V_170 :
V_82 = F_131 ( V_5 , V_61 , V_63 ) ; break;
case V_171 :
V_82 = F_127 ( V_5 , V_61 , V_63 ) ; break;
case V_172 :
V_82 = F_135 ( V_5 , V_61 , V_63 ) ; break;
case V_173 :
V_82 = F_138 ( V_5 , V_61 , V_63 ) ; break;
case V_174 :
V_82 = F_62 ( V_5 , V_61 , V_63 ) ; break;
default:
V_82 = - 1 ;
break;
}
return V_82 ;
}
static bool F_141 ( struct V_175 * V_176 , T_10 * V_177 )
{
if ( V_176 -> V_101 && ! regexec ( V_177 , V_176 -> V_101 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_142 ( struct V_22 * V_22 ,
struct V_178 * V_179 ,
T_6 V_180 )
{
struct V_181 V_182 ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
F_143 ( V_22 , V_77 , V_180 , & V_182 ) ;
V_179 -> V_102 = V_180 ;
V_179 -> V_183 = V_182 . V_102 ;
V_179 -> V_176 = V_182 . V_176 ;
V_179 -> V_73 = V_182 . V_73 ;
}
static void F_144 ( struct V_22 * V_22 ,
T_9 V_83 , struct V_178 * V_179 , T_6 V_102 )
{
struct V_181 V_182 ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
F_145 ( V_22 , V_83 , V_159 , V_102 , & V_182 ) ;
if ( V_182 . V_73 == NULL ) {
F_145 ( V_22 , V_83 , V_77 , V_102 , & V_182 ) ;
}
V_179 -> V_102 = V_102 ;
V_179 -> V_183 = V_182 . V_102 ;
V_179 -> V_176 = V_182 . V_176 ;
V_179 -> V_73 = V_182 . V_73 ;
}
struct V_184 * F_146 ( struct V_62 * V_63 ,
struct V_181 * V_182 )
{
struct V_184 * V_185 = F_147 ( sizeof( * V_185 ) ) ;
if ( ! V_185 )
return NULL ;
F_142 ( V_182 -> V_22 , & V_185 -> V_186 , V_63 -> V_180 ) ;
F_144 ( V_182 -> V_22 , V_182 -> V_153 , & V_185 -> V_187 , V_63 -> V_102 ) ;
V_185 -> V_188 . V_189 = V_63 -> V_188 ;
return V_185 ;
}
static int F_148 ( struct V_22 * V_22 ,
struct V_175 * * V_36 ,
struct V_181 * V_190 ,
bool V_191 ,
T_6 V_180 )
{
struct V_181 V_182 ;
V_182 . V_192 = 0 ;
V_182 . V_176 = NULL ;
if ( V_191 )
F_143 ( V_22 , V_77 ,
V_180 , & V_182 ) ;
else {
T_9 V_153 = V_193 ;
if ( V_180 >= V_194 ) {
switch ( V_180 ) {
case V_195 :
V_153 = V_196 ;
break;
case V_197 :
V_153 = V_156 ;
break;
case V_198 :
V_153 = V_193 ;
break;
default:
F_94 ( L_47
L_48 V_199 L_14 , ( V_200 ) V_180 ) ;
F_149 ( & V_201 ) ;
return 1 ;
}
return 0 ;
}
F_145 ( V_22 , V_153 , V_77 ,
V_180 , & V_182 ) ;
}
if ( V_182 . V_176 != NULL ) {
if ( V_202 && ! * V_36 &&
F_141 ( V_182 . V_176 , & V_203 ) )
* V_36 = V_182 . V_176 ;
else if ( V_204 && V_190 &&
F_141 ( V_182 . V_176 , & V_205 ) ) {
* V_190 = V_182 ;
F_149 ( & V_201 ) ;
}
}
return F_150 ( & V_201 , V_182 . V_102 , V_182 . V_73 , V_182 . V_176 ) ;
}
struct V_206 * F_151 ( struct V_62 * V_63 ,
struct V_181 * V_182 )
{
unsigned int V_85 ;
const struct V_207 * V_208 = V_63 -> V_207 ;
struct V_206 * V_209 = calloc ( V_208 -> V_210 , sizeof( struct V_206 ) ) ;
if ( ! V_209 )
return NULL ;
for ( V_85 = 0 ; V_85 < V_208 -> V_210 ; V_85 ++ ) {
F_142 ( V_182 -> V_22 , & V_209 [ V_85 ] . V_211 , V_208 -> V_212 [ V_85 ] . V_211 ) ;
F_142 ( V_182 -> V_22 , & V_209 [ V_85 ] . V_213 , V_208 -> V_212 [ V_85 ] . V_213 ) ;
V_209 [ V_85 ] . V_165 = V_208 -> V_212 [ V_85 ] . V_165 ;
}
return V_209 ;
}
static int F_152 ( struct V_214 * V_215 , int V_210 )
{
int V_85 , V_216 , V_217 ;
unsigned char V_218 [ V_219 ] ;
memset ( V_218 , V_220 , sizeof( V_218 ) ) ;
F_153 ( V_221 > 255 ) ;
for ( V_85 = 0 ; V_85 < V_210 ; V_85 ++ ) {
int V_222 = F_154 ( V_215 [ V_85 ] . V_213 , V_223 ) % V_219 ;
if ( V_218 [ V_222 ] == V_220 ) {
V_218 [ V_222 ] = V_85 ;
} else if ( V_215 [ V_218 [ V_222 ] ] . V_213 == V_215 [ V_85 ] . V_213 ) {
bool V_224 = true ;
V_217 = 0 ;
for ( V_216 = V_218 [ V_222 ] ; V_216 < V_85 && V_85 + V_217 < V_210 ; V_216 ++ , V_217 ++ )
if ( V_215 [ V_216 ] . V_213 != V_215 [ V_85 + V_217 ] . V_213 ) {
V_224 = false ;
break;
}
if ( V_224 ) {
memmove ( V_215 + V_85 , V_215 + V_85 + V_217 ,
( V_210 - ( V_85 + V_217 ) ) * sizeof( * V_215 ) ) ;
V_210 -= V_217 ;
}
}
}
return V_210 ;
}
static int F_155 ( struct V_22 * V_22 ,
struct V_225 * V_226 ,
struct V_207 * V_227 ,
struct V_175 * * V_36 ,
struct V_181 * V_190 ,
int V_228 )
{
int V_229 = V_161 ( V_228 , ( int ) V_226 -> V_210 ) ;
int V_85 , V_216 , V_230 ;
int V_231 = - 1 ;
int V_232 = 0 ;
if ( V_226 -> V_210 < V_233 )
V_231 = F_156 ( V_22 , V_226 ) ;
F_149 ( & V_201 ) ;
if ( V_227 && V_234 . V_235 ) {
int V_210 = V_161 ( V_228 , ( int ) V_227 -> V_210 ) ;
struct V_214 V_236 [ V_210 ] ;
if ( V_227 -> V_210 > V_221 ) {
F_157 ( L_49 ) ;
goto V_237;
}
for ( V_85 = 0 ; V_85 < V_210 ; V_85 ++ ) {
if ( V_234 . V_238 == V_239 ) {
V_236 [ V_85 ] = V_227 -> V_212 [ V_85 ] ;
if ( V_85 == V_231 ||
V_226 -> V_240 [ V_232 ] >= V_194 )
V_232 ++ ;
else if ( V_236 [ V_85 ] . V_213 < V_226 -> V_240 [ V_232 ] &&
V_236 [ V_85 ] . V_213 >= V_226 -> V_240 [ V_232 ] - 8 )
V_232 ++ ;
} else
V_236 [ V_85 ] = V_227 -> V_212 [ V_227 -> V_210 - V_85 - 1 ] ;
}
V_210 = F_152 ( V_236 , V_210 ) ;
for ( V_85 = 0 ; V_85 < V_210 ; V_85 ++ ) {
V_230 = F_148 ( V_22 , V_36 , V_190 ,
true , V_236 [ V_85 ] . V_211 ) ;
if ( ! V_230 )
V_230 = F_148 ( V_22 , V_36 , V_190 ,
true , V_236 [ V_85 ] . V_213 ) ;
if ( V_230 == - V_241 )
break;
if ( V_230 )
return V_230 ;
}
V_229 -= V_210 ;
}
V_237:
if ( V_226 -> V_210 > V_233 ) {
F_157 ( L_50 ) ;
return 0 ;
}
for ( V_85 = V_232 ; V_85 < V_229 ; V_85 ++ ) {
T_6 V_180 ;
if ( V_234 . V_238 == V_239 )
V_216 = V_85 ;
else
V_216 = V_226 -> V_210 - V_85 - 1 ;
#ifdef F_158
if ( V_216 == V_231 )
continue;
#endif
V_180 = V_226 -> V_240 [ V_216 ] ;
V_230 = F_148 ( V_22 , V_36 , V_190 , false , V_180 ) ;
if ( V_230 )
return ( V_230 < 0 ) ? V_230 : 0 ;
}
return 0 ;
}
static int F_159 ( struct F_159 * V_242 , void * V_140 )
{
struct V_201 * V_243 = V_140 ;
return F_150 ( V_243 , V_242 -> V_180 ,
V_242 -> V_73 , V_242 -> V_176 ) ;
}
int F_160 ( struct V_22 * V_22 ,
struct V_244 * V_245 ,
struct V_62 * V_63 ,
struct V_175 * * V_36 ,
struct V_181 * V_190 ,
int V_228 )
{
int V_82 = F_155 ( V_22 , V_63 -> V_246 ,
V_63 -> V_207 ,
V_36 , V_190 , V_228 ) ;
if ( V_82 )
return V_82 ;
if ( ! ( ( V_245 -> V_247 . V_248 & V_249 ) &&
( V_245 -> V_247 . V_248 & V_250 ) ) )
return 0 ;
if ( ( ! V_63 -> V_251 . V_252 ) ||
( ! V_63 -> V_253 . V_52 ) )
return 0 ;
return F_161 ( F_159 , & V_201 ,
V_22 , V_63 , V_228 ) ;
}
int F_162 ( struct V_5 * V_5 ,
int (* F_163)( struct V_22 * V_22 , void * V_35 ) ,
void * V_254 )
{
struct V_9 * V_31 ;
struct V_22 * V_22 ;
int V_255 = 0 ;
for ( V_31 = F_18 ( & V_5 -> V_12 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
V_22 = F_19 ( V_31 , struct V_22 , V_9 ) ;
V_255 = F_163 ( V_22 , V_254 ) ;
if ( V_255 != 0 )
return V_255 ;
}
F_122 (thread, &machine->dead_threads, node) {
V_255 = F_163 ( V_22 , V_254 ) ;
if ( V_255 != 0 )
return V_255 ;
}
return V_255 ;
}
int F_164 ( struct V_5 * V_5 , struct V_256 * V_257 ,
struct V_258 * V_258 , struct V_259 * V_12 ,
T_11 V_49 , bool V_260 )
{
if ( F_165 ( V_258 ) )
return F_166 ( V_257 , V_12 , V_49 , V_5 , V_260 ) ;
else if ( F_167 ( V_258 ) )
return F_168 ( V_257 , V_49 , V_5 , V_260 ) ;
return 0 ;
}
T_1 F_169 ( struct V_5 * V_5 , int V_261 )
{
if ( V_261 < 0 || V_261 >= V_262 || ! V_5 -> V_24 )
return - 1 ;
return V_5 -> V_24 [ V_261 ] ;
}
int F_170 ( struct V_5 * V_5 , int V_261 , T_1 V_7 ,
T_1 V_56 )
{
struct V_22 * V_22 ;
if ( V_261 < 0 )
return - V_241 ;
if ( ! V_5 -> V_24 ) {
int V_85 ;
V_5 -> V_24 = calloc ( V_262 , sizeof( T_1 ) ) ;
if ( ! V_5 -> V_24 )
return - V_20 ;
for ( V_85 = 0 ; V_85 < V_262 ; V_85 ++ )
V_5 -> V_24 [ V_85 ] = - 1 ;
}
if ( V_261 >= V_262 ) {
F_39 ( L_51 , V_261 ) ;
F_39 ( L_52 ) ;
return - V_241 ;
}
V_5 -> V_24 [ V_261 ] = V_56 ;
V_22 = F_7 ( V_5 , V_7 , V_56 ) ;
if ( ! V_22 )
return - V_20 ;
V_22 -> V_261 = V_261 ;
return 0 ;
}
int F_171 ( struct V_5 * V_5 )
{
struct V_73 * V_73 = F_172 ( V_5 , V_77 ) ;
int V_230 = 0 ;
V_5 -> V_19 = 1ULL << 63 ;
if ( V_73 ) {
V_230 = F_173 ( V_73 , V_5 -> V_16 ) ;
if ( V_73 -> V_74 )
V_5 -> V_19 = V_73 -> V_74 ;
}
return V_230 ;
}
