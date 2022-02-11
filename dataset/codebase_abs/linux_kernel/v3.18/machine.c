static void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
V_1 -> V_3 = V_4 ;
}
int F_3 ( struct V_5 * V_5 , const char * V_6 , T_1 V_7 )
{
F_4 ( & V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_9 ) ;
F_1 ( & V_5 -> V_10 ) ;
F_1 ( & V_5 -> V_11 ) ;
V_5 -> V_12 = V_4 ;
F_2 ( & V_5 -> V_13 ) ;
V_5 -> V_14 = NULL ;
V_5 -> V_15 = NULL ;
V_5 -> V_8 . V_5 = V_5 ;
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
V_54 -> V_58 = F_47 () ;
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
V_5 -> V_14 = V_53 ;
if ( F_53 ( V_53 , V_5 ) ) {
F_16 ( V_53 ) ;
return NULL ;
}
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
if ( V_26 == NULL )
return NULL ;
V_73 = F_65 ( V_74 , V_26 , V_76 ) ;
if ( V_73 == NULL )
return NULL ;
if ( F_43 ( V_5 ) )
V_26 -> V_77 = V_78 ;
else
V_26 -> V_77 = V_79 ;
F_66 ( & V_5 -> V_8 , V_73 ) ;
return V_73 ;
}
T_4 F_67 ( struct V_32 * V_32 , T_7 * V_80 )
{
struct V_9 * V_31 ;
T_4 V_81 = F_68 ( & V_32 -> V_33 . V_11 . V_2 , V_80 ) +
F_68 ( & V_32 -> V_33 . V_10 . V_2 , V_80 ) ;
for ( V_31 = F_18 ( & V_32 -> V_34 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_5 * V_27 = F_19 ( V_31 , struct V_5 , V_9 ) ;
V_81 += F_68 ( & V_27 -> V_11 . V_2 , V_80 ) ;
V_81 += F_68 ( & V_27 -> V_10 . V_2 , V_80 ) ;
}
return V_81 ;
}
T_4 F_69 ( struct V_5 * V_82 , T_7 * V_80 ,
bool (F_70)( struct V_26 * V_26 , int V_83 ) , int V_83 )
{
return F_71 ( & V_82 -> V_11 . V_2 , V_80 , F_70 , V_83 ) +
F_71 ( & V_82 -> V_10 . V_2 , V_80 , F_70 , V_83 ) ;
}
T_4 F_72 ( struct V_32 * V_32 , T_7 * V_80 ,
bool (F_70)( struct V_26 * V_26 , int V_83 ) , int V_83 )
{
struct V_9 * V_31 ;
T_4 V_81 = F_69 ( & V_32 -> V_33 , V_80 , F_70 , V_83 ) ;
for ( V_31 = F_18 ( & V_32 -> V_34 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_5 * V_27 = F_19 ( V_31 , struct V_5 , V_9 ) ;
V_81 += F_69 ( V_27 , V_80 , F_70 , V_83 ) ;
}
return V_81 ;
}
T_4 F_73 ( struct V_5 * V_5 , T_7 * V_80 )
{
int V_84 ;
T_4 V_85 = 0 ;
struct V_26 * V_86 = V_5 -> V_87 [ V_76 ] -> V_26 ;
if ( V_86 -> V_88 ) {
char V_75 [ V_41 ] ;
if ( F_74 ( V_86 , V_75 , sizeof( V_75 ) ) )
V_85 += fprintf ( V_80 , L_15 , V_75 ) ;
}
for ( V_84 = 0 ; V_84 < V_89 ; ++ V_84 )
V_85 += fprintf ( V_80 , L_16 ,
V_84 + V_86 -> V_88 , V_90 [ V_84 ] ) ;
return V_85 ;
}
T_4 F_75 ( struct V_5 * V_5 , T_7 * V_80 )
{
T_4 V_81 = 0 ;
struct V_9 * V_31 ;
for ( V_31 = F_18 ( & V_5 -> V_12 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
struct V_22 * V_27 = F_19 ( V_31 , struct V_22 , V_9 ) ;
V_81 += F_76 ( V_27 , V_80 ) ;
}
return V_81 ;
}
static struct V_26 * F_77 ( struct V_5 * V_5 )
{
const char * V_91 = NULL ;
struct V_26 * V_92 ;
if ( F_43 ( V_5 ) ) {
V_91 = V_44 . V_91 ;
if ( ! V_91 )
V_91 = L_17 ;
V_92 = F_78 ( V_5 , V_91 ,
L_18 ,
V_93 ) ;
} else {
char V_51 [ V_41 ] ;
if ( F_44 ( V_5 ) )
V_91 = V_44 . V_94 ;
if ( ! V_91 )
V_91 = F_42 ( V_5 , V_51 ,
sizeof( V_51 ) ) ;
V_92 = F_78 ( V_5 , V_91 ,
L_19 ,
V_95 ) ;
}
if ( V_92 != NULL && ( ! V_92 -> V_88 ) )
F_79 ( V_92 , V_5 ) ;
return V_92 ;
}
static void F_80 ( struct V_5 * V_5 , char * V_96 ,
T_4 V_97 )
{
if ( F_44 ( V_5 ) )
F_81 ( V_96 , V_97 , L_20 , V_44 . V_98 ) ;
else
F_81 ( V_96 , V_97 , L_21 , V_5 -> V_6 ) ;
}
static T_6 F_82 ( struct V_5 * V_5 ,
const char * * V_99 )
{
char V_75 [ V_41 ] ;
int V_84 ;
const char * V_100 ;
T_6 V_101 = 0 ;
F_80 ( V_5 , V_75 , V_41 ) ;
if ( F_83 ( V_75 , L_22 ) )
return 0 ;
for ( V_84 = 0 ; ( V_100 = V_102 [ V_84 ] ) != NULL ; V_84 ++ ) {
V_101 = F_84 ( V_75 , V_100 ) ;
if ( V_101 )
break;
}
if ( V_99 )
* V_99 = V_100 ;
return V_101 ;
}
int F_85 ( struct V_5 * V_5 , struct V_26 * V_92 )
{
enum V_103 type ;
T_6 V_74 = F_82 ( V_5 , NULL ) ;
for ( type = 0 ; type < V_104 ; ++ type ) {
struct V_105 * V_105 ;
V_5 -> V_87 [ type ] = F_65 ( V_74 , V_92 , type ) ;
if ( V_5 -> V_87 [ type ] == NULL )
return - 1 ;
V_5 -> V_87 [ type ] -> V_106 =
V_5 -> V_87 [ type ] -> V_107 =
V_108 ;
V_105 = F_86 ( V_5 -> V_87 [ type ] ) ;
V_105 -> V_8 = & V_5 -> V_8 ;
F_66 ( & V_5 -> V_8 ,
V_5 -> V_87 [ type ] ) ;
}
return 0 ;
}
void F_87 ( struct V_5 * V_5 )
{
enum V_103 type ;
for ( type = 0 ; type < V_104 ; ++ type ) {
struct V_105 * V_105 ;
if ( V_5 -> V_87 [ type ] == NULL )
continue;
V_105 = F_86 ( V_5 -> V_87 [ type ] ) ;
F_88 ( & V_5 -> V_8 ,
V_5 -> V_87 [ type ] ) ;
if ( V_105 -> V_109 ) {
if ( type == V_76 ) {
F_25 ( ( char * * ) & V_105 -> V_109 -> V_100 ) ;
F_25 ( & V_105 -> V_109 ) ;
} else
V_105 -> V_109 = NULL ;
}
F_89 ( V_5 -> V_87 [ type ] ) ;
V_5 -> V_87 [ type ] = NULL ;
}
}
int F_90 ( struct V_32 * V_32 )
{
int V_81 = 0 ;
struct V_110 * * V_111 = NULL ;
int V_84 , V_112 = 0 ;
char V_40 [ V_41 ] ;
T_1 V_7 ;
char * V_113 ;
if ( V_44 . V_94 ||
V_44 . V_114 ||
V_44 . V_98 ) {
F_91 ( V_32 , V_43 ) ;
}
if ( V_44 . V_45 ) {
V_112 = F_92 ( V_44 . V_45 , & V_111 , NULL , NULL ) ;
if ( V_112 <= 0 )
return - V_115 ;
for ( V_84 = 0 ; V_84 < V_112 ; V_84 ++ ) {
if ( ! isdigit ( V_111 [ V_84 ] -> V_116 [ 0 ] ) ) {
continue;
}
V_7 = ( T_1 ) strtol ( V_111 [ V_84 ] -> V_116 , & V_113 , 10 ) ;
if ( ( * V_113 != '\0' ) ||
( V_113 == V_111 [ V_84 ] -> V_116 ) ||
( V_117 == V_118 ) ) {
F_93 ( L_23 ,
V_111 [ V_84 ] -> V_116 ) ;
continue;
}
sprintf ( V_40 , L_24 ,
V_44 . V_45 ,
V_111 [ V_84 ] -> V_116 ) ;
V_81 = F_36 ( V_40 , V_46 ) ;
if ( V_81 ) {
F_93 ( L_4 , V_40 ) ;
goto V_119;
}
F_91 ( V_32 , V_7 ) ;
}
V_119:
free ( V_111 ) ;
}
return V_81 ;
}
void F_94 ( struct V_32 * V_32 )
{
struct V_9 * V_120 = F_18 ( & V_32 -> V_34 ) ;
F_87 ( & V_32 -> V_33 ) ;
while ( V_120 ) {
struct V_5 * V_27 = F_19 ( V_120 , struct V_5 , V_9 ) ;
V_120 = F_21 ( & V_27 -> V_9 ) ;
F_20 ( & V_27 -> V_9 , & V_32 -> V_34 ) ;
F_26 ( V_27 ) ;
}
}
int F_91 ( struct V_32 * V_32 , T_1 V_7 )
{
struct V_5 * V_5 = F_35 ( V_32 , V_7 ) ;
if ( V_5 == NULL )
return - 1 ;
return F_10 ( V_5 ) ;
}
int F_95 ( struct V_5 * V_5 , const char * V_75 ,
enum V_103 type , T_2 V_121 )
{
struct V_73 * V_73 = V_5 -> V_87 [ type ] ;
int V_81 = F_96 ( V_73 -> V_26 , V_75 , V_73 , V_121 ) ;
if ( V_81 > 0 ) {
F_97 ( V_73 -> V_26 , type ) ;
F_98 ( & V_5 -> V_8 , type ) ;
}
return V_81 ;
}
int F_99 ( struct V_5 * V_5 , enum V_103 type ,
T_2 V_121 )
{
struct V_73 * V_73 = V_5 -> V_87 [ type ] ;
int V_81 = F_100 ( V_73 -> V_26 , V_73 , V_121 ) ;
if ( V_81 > 0 )
F_97 ( V_73 -> V_26 , type ) ;
return V_81 ;
}
static void F_101 ( struct V_122 * V_58 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_104 ; ++ V_84 )
F_98 ( V_58 , V_84 ) ;
}
static char * F_102 ( const char * V_6 )
{
char V_123 [ V_41 ] ;
T_7 * V_124 ;
char * V_100 , * V_125 ;
const char * V_126 = L_25 ;
sprintf ( V_123 , L_26 , V_6 ) ;
V_124 = fopen ( V_123 , L_27 ) ;
if ( ! V_124 )
return NULL ;
V_123 [ 0 ] = '\0' ;
V_125 = fgets ( V_123 , sizeof( V_123 ) , V_124 ) ;
fclose ( V_124 ) ;
V_100 = strstr ( V_123 , V_126 ) ;
if ( ! V_100 )
return NULL ;
V_100 += strlen ( V_126 ) ;
V_125 = strchr ( V_100 , ' ' ) ;
if ( V_125 )
* V_125 = '\0' ;
return F_6 ( V_100 ) ;
}
static int F_103 ( struct V_122 * V_58 ,
const char * V_127 , int V_128 )
{
struct V_110 * V_129 ;
T_8 * V_130 = F_104 ( V_127 ) ;
int V_81 = 0 ;
if ( ! V_130 ) {
F_93 ( L_28 , V_131 , V_127 ) ;
return - 1 ;
}
while ( ( V_129 = F_105 ( V_130 ) ) != NULL ) {
char V_40 [ V_41 ] ;
struct V_132 V_133 ;
snprintf ( V_40 , sizeof( V_40 ) , L_29 , V_127 , V_129 -> V_116 ) ;
if ( V_132 ( V_40 , & V_133 ) )
continue;
if ( F_106 ( V_133 . V_134 ) ) {
if ( ! strcmp ( V_129 -> V_116 , L_30 ) ||
! strcmp ( V_129 -> V_116 , L_31 ) )
continue;
if ( V_128 == 0 ) {
if ( ! strcmp ( V_129 -> V_116 , L_32 ) ||
! strcmp ( V_129 -> V_116 , L_33 ) )
continue;
}
V_81 = F_103 ( V_58 , V_40 ,
V_128 + 1 ) ;
if ( V_81 < 0 )
goto V_42;
} else {
char * V_135 = strrchr ( V_129 -> V_116 , '.' ) ,
V_136 [ V_41 ] ;
struct V_73 * V_73 ;
char * V_137 ;
if ( V_135 == NULL || strcmp ( V_135 , L_34 ) )
continue;
snprintf ( V_136 , sizeof( V_136 ) , L_35 ,
( int ) ( V_135 - V_129 -> V_116 ) , V_129 -> V_116 ) ;
F_107 ( V_136 , '-' , '_' ) ;
V_73 = F_108 ( V_58 , V_76 ,
V_136 ) ;
if ( V_73 == NULL )
continue;
V_137 = F_6 ( V_40 ) ;
if ( V_137 == NULL ) {
V_81 = - 1 ;
goto V_42;
}
F_109 ( V_73 -> V_26 , V_137 , true ) ;
F_110 ( V_73 -> V_26 , L_2 ) ;
}
}
V_42:
F_111 ( V_130 ) ;
return V_81 ;
}
static int F_112 ( struct V_5 * V_5 )
{
char * V_123 ;
char V_138 [ V_41 ] ;
V_123 = F_102 ( V_5 -> V_6 ) ;
if ( ! V_123 )
return - 1 ;
snprintf ( V_138 , sizeof( V_138 ) , L_36 ,
V_5 -> V_6 , V_123 ) ;
free ( V_123 ) ;
return F_103 ( & V_5 -> V_8 , V_138 , 0 ) ;
}
static int F_113 ( void * V_139 , const char * V_100 , T_6 V_74 )
{
struct V_5 * V_5 = V_139 ;
struct V_73 * V_73 ;
V_73 = F_63 ( V_5 , V_74 , V_100 ) ;
if ( V_73 == NULL )
return - 1 ;
F_110 ( V_73 -> V_26 , V_5 -> V_6 ) ;
return 0 ;
}
static int F_114 ( struct V_5 * V_5 )
{
const char * V_140 ;
char V_40 [ V_41 ] ;
if ( F_44 ( V_5 ) ) {
V_140 = V_44 . V_114 ;
} else {
snprintf ( V_40 , V_41 , L_37 , V_5 -> V_6 ) ;
V_140 = V_40 ;
}
if ( F_83 ( V_140 , L_38 ) )
return - 1 ;
if ( F_115 ( V_140 , V_5 , F_113 ) )
return - 1 ;
if ( ! F_112 ( V_5 ) )
return 0 ;
F_93 ( L_39 ) ;
return 0 ;
}
int F_10 ( struct V_5 * V_5 )
{
struct V_26 * V_92 = F_77 ( V_5 ) ;
const char * V_100 ;
T_6 V_101 = F_82 ( V_5 , & V_100 ) ;
if ( ! V_101 )
return - 1 ;
if ( V_92 == NULL ||
F_85 ( V_5 , V_92 ) < 0 )
return - 1 ;
if ( V_44 . V_141 && F_114 ( V_5 ) < 0 ) {
if ( F_43 ( V_5 ) )
F_93 ( L_40
L_41 ) ;
else
F_93 ( L_42
L_41 , V_5 -> V_7 ) ;
}
F_101 ( & V_5 -> V_8 ) ;
if ( F_116 ( V_5 -> V_87 , V_100 ,
V_101 ) ) {
F_87 ( V_5 ) ;
return - 1 ;
}
return 0 ;
}
static void F_117 ( struct V_5 * V_5 ,
union V_60 * V_61 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_104 ; V_84 ++ ) {
V_5 -> V_87 [ V_84 ] -> V_74 = V_61 -> V_142 . V_74 ;
V_5 -> V_87 [ V_84 ] -> V_143 = ( V_61 -> V_142 . V_74 +
V_61 -> V_142 . V_144 ) ;
if ( V_5 -> V_87 [ V_84 ] -> V_143 == 0 )
V_5 -> V_87 [ V_84 ] -> V_143 = ~ 0ULL ;
}
}
static bool F_118 ( struct V_5 * V_5 )
{
struct V_26 * V_26 ;
F_119 (dso, &machine->kernel_dsos.head, node) {
if ( F_120 ( V_26 ) )
return true ;
}
return false ;
}
static int F_121 ( struct V_5 * V_5 ,
union V_60 * V_61 )
{
struct V_73 * V_73 ;
char V_145 [ V_41 ] ;
enum V_146 V_147 ;
bool V_148 ;
if ( F_118 ( V_5 ) )
return 0 ;
F_42 ( V_5 , V_145 , sizeof( V_145 ) ) ;
if ( F_43 ( V_5 ) )
V_147 = V_93 ;
else
V_147 = V_95 ;
V_148 = memcmp ( V_61 -> V_142 . V_75 ,
V_145 ,
strlen ( V_145 ) - 1 ) == 0 ;
if ( V_61 -> V_142 . V_75 [ 0 ] == '/' ||
( ! V_148 && V_61 -> V_142 . V_75 [ 0 ] == '[' ) ) {
char V_149 [ 1024 ] ;
char * V_100 , * V_135 ;
if ( V_61 -> V_142 . V_75 [ 0 ] == '/' ) {
V_100 = strrchr ( V_61 -> V_142 . V_75 , '/' ) ;
if ( V_100 == NULL )
goto V_150;
++ V_100 ;
V_135 = strrchr ( V_100 , '.' ) ;
if ( V_135 == NULL )
goto V_150;
snprintf ( V_149 , sizeof( V_149 ) ,
L_35 , ( int ) ( V_135 - V_100 ) , V_100 ) ;
F_107 ( V_149 , '-' , '_' ) ;
} else
strcpy ( V_149 , V_61 -> V_142 . V_75 ) ;
V_73 = F_63 ( V_5 , V_61 -> V_142 . V_74 ,
V_61 -> V_142 . V_75 ) ;
if ( V_73 == NULL )
goto V_150;
V_100 = F_6 ( V_149 ) ;
if ( V_100 == NULL )
goto V_150;
F_122 ( V_73 -> V_26 , V_100 , true ) ;
V_73 -> V_143 = V_73 -> V_74 + V_61 -> V_142 . V_144 ;
} else if ( V_148 ) {
const char * V_99 = ( V_61 -> V_142 . V_75 +
strlen ( V_145 ) ) ;
struct V_26 * V_92 = F_64 ( & V_5 -> V_11 ,
V_145 ) ;
if ( V_92 == NULL )
goto V_150;
V_92 -> V_92 = V_147 ;
if ( F_85 ( V_5 , V_92 ) < 0 )
goto V_150;
F_117 ( V_5 , V_61 ) ;
if ( V_61 -> V_142 . V_151 != 0 ) {
F_116 ( V_5 -> V_87 ,
V_99 ,
V_61 -> V_142 . V_151 ) ;
}
if ( F_44 ( V_5 ) ) {
F_123 ( V_92 , V_5 -> V_87 [ V_76 ] ,
NULL ) ;
}
}
return 0 ;
V_150:
return - 1 ;
}
int F_124 ( struct V_5 * V_5 ,
union V_60 * V_61 ,
struct V_62 * V_63 V_69 )
{
T_9 V_152 = V_61 -> V_65 . V_66 & V_153 ;
struct V_22 * V_22 ;
struct V_73 * V_73 ;
enum V_103 type ;
int V_81 = 0 ;
if ( V_68 )
F_125 ( V_61 , stdout ) ;
if ( V_152 == V_154 ||
V_152 == V_155 ) {
V_81 = F_121 ( V_5 , V_61 ) ;
if ( V_81 < 0 )
goto V_150;
return 0 ;
}
V_22 = F_7 ( V_5 , V_61 -> V_156 . V_7 ,
V_61 -> V_156 . V_56 ) ;
if ( V_22 == NULL )
goto V_150;
if ( V_61 -> V_65 . V_66 & V_157 )
type = V_158 ;
else
type = V_76 ;
V_73 = F_126 ( V_5 , V_61 -> V_156 . V_74 ,
V_61 -> V_156 . V_144 , V_61 -> V_156 . V_151 ,
V_61 -> V_156 . V_7 , V_61 -> V_156 . V_159 ,
V_61 -> V_156 . V_160 , V_61 -> V_156 . V_161 ,
V_61 -> V_156 . V_162 ,
V_61 -> V_156 . V_163 ,
V_61 -> V_156 . V_164 ,
V_61 -> V_156 . V_75 , type , V_22 ) ;
if ( V_73 == NULL )
goto V_150;
F_127 ( V_22 , V_73 ) ;
return 0 ;
V_150:
F_61 ( L_43 ) ;
return 0 ;
}
int F_128 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 V_69 )
{
T_9 V_152 = V_61 -> V_65 . V_66 & V_153 ;
struct V_22 * V_22 ;
struct V_73 * V_73 ;
enum V_103 type ;
int V_81 = 0 ;
if ( V_68 )
F_129 ( V_61 , stdout ) ;
if ( V_152 == V_154 ||
V_152 == V_155 ) {
V_81 = F_121 ( V_5 , V_61 ) ;
if ( V_81 < 0 )
goto V_150;
return 0 ;
}
V_22 = F_7 ( V_5 , V_61 -> V_142 . V_7 ,
V_61 -> V_142 . V_56 ) ;
if ( V_22 == NULL )
goto V_150;
if ( V_61 -> V_65 . V_66 & V_157 )
type = V_158 ;
else
type = V_76 ;
V_73 = F_126 ( V_5 , V_61 -> V_142 . V_74 ,
V_61 -> V_142 . V_144 , V_61 -> V_142 . V_151 ,
V_61 -> V_142 . V_7 , 0 , 0 , 0 , 0 , 0 , 0 ,
V_61 -> V_142 . V_75 ,
type , V_22 ) ;
if ( V_73 == NULL )
goto V_150;
F_127 ( V_22 , V_73 ) ;
return 0 ;
V_150:
F_61 ( L_44 ) ;
return 0 ;
}
static void F_130 ( struct V_5 * V_5 , struct V_22 * V_53 )
{
V_5 -> V_14 = NULL ;
F_20 ( & V_53 -> V_9 , & V_5 -> V_12 ) ;
F_131 ( & V_53 -> V_29 , & V_5 -> V_13 ) ;
}
int F_132 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_22 * V_22 = F_54 ( V_5 ,
V_61 -> V_165 . V_7 ,
V_61 -> V_165 . V_56 ) ;
struct V_22 * V_36 = F_7 ( V_5 ,
V_61 -> V_165 . V_166 ,
V_61 -> V_165 . V_167 ) ;
if ( V_22 != NULL )
F_130 ( V_5 , V_22 ) ;
V_22 = F_7 ( V_5 , V_61 -> V_165 . V_7 ,
V_61 -> V_165 . V_56 ) ;
if ( V_68 )
F_133 ( V_61 , stdout ) ;
if ( V_22 == NULL || V_36 == NULL ||
F_134 ( V_22 , V_36 , V_63 -> time ) < 0 ) {
F_61 ( L_45 ) ;
return - 1 ;
}
return 0 ;
}
int F_135 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 V_69 )
{
struct V_22 * V_22 = F_54 ( V_5 ,
V_61 -> V_165 . V_7 ,
V_61 -> V_165 . V_56 ) ;
if ( V_68 )
F_133 ( V_61 , stdout ) ;
if ( V_22 != NULL )
F_136 ( V_22 ) ;
return 0 ;
}
int F_137 ( struct V_5 * V_5 , union V_60 * V_61 ,
struct V_62 * V_63 )
{
int V_81 ;
switch ( V_61 -> V_65 . type ) {
case V_168 :
V_81 = F_58 ( V_5 , V_61 , V_63 ) ; break;
case V_169 :
V_81 = F_128 ( V_5 , V_61 , V_63 ) ; break;
case V_170 :
V_81 = F_124 ( V_5 , V_61 , V_63 ) ; break;
case V_171 :
V_81 = F_132 ( V_5 , V_61 , V_63 ) ; break;
case V_172 :
V_81 = F_135 ( V_5 , V_61 , V_63 ) ; break;
case V_173 :
V_81 = F_62 ( V_5 , V_61 , V_63 ) ; break;
default:
V_81 = - 1 ;
break;
}
return V_81 ;
}
static bool F_138 ( struct V_174 * V_175 , T_10 * V_176 )
{
if ( V_175 -> V_100 && ! regexec ( V_176 , V_175 -> V_100 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_139 ( struct V_5 * V_5 , struct V_22 * V_22 ,
struct V_177 * V_178 ,
T_6 V_179 )
{
struct V_180 V_181 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
F_140 ( V_22 , V_5 , V_76 , V_179 , & V_181 ) ;
V_178 -> V_101 = V_179 ;
V_178 -> V_182 = V_181 . V_101 ;
V_178 -> V_175 = V_181 . V_175 ;
V_178 -> V_73 = V_181 . V_73 ;
}
static void F_141 ( struct V_5 * V_5 , struct V_22 * V_22 ,
T_9 V_82 , struct V_177 * V_178 , T_6 V_101 )
{
struct V_180 V_181 ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
F_142 ( V_22 , V_5 , V_82 , V_158 , V_101 ,
& V_181 ) ;
if ( V_181 . V_73 == NULL ) {
F_142 ( V_22 , V_5 , V_82 , V_76 , V_101 ,
& V_181 ) ;
}
V_178 -> V_101 = V_101 ;
V_178 -> V_182 = V_181 . V_101 ;
V_178 -> V_175 = V_181 . V_175 ;
V_178 -> V_73 = V_181 . V_73 ;
}
struct V_183 * F_143 ( struct V_62 * V_63 ,
struct V_180 * V_181 )
{
struct V_183 * V_184 = F_144 ( sizeof( * V_184 ) ) ;
if ( ! V_184 )
return NULL ;
F_139 ( V_181 -> V_5 , V_181 -> V_22 , & V_184 -> V_185 , V_63 -> V_179 ) ;
F_141 ( V_181 -> V_5 , V_181 -> V_22 , V_181 -> V_152 ,
& V_184 -> V_186 , V_63 -> V_101 ) ;
V_184 -> V_187 . V_188 = V_63 -> V_187 ;
return V_184 ;
}
struct V_189 * F_145 ( struct V_62 * V_63 ,
struct V_180 * V_181 )
{
unsigned int V_84 ;
const struct V_190 * V_191 = V_63 -> V_190 ;
struct V_189 * V_192 = calloc ( V_191 -> V_193 , sizeof( struct V_189 ) ) ;
if ( ! V_192 )
return NULL ;
for ( V_84 = 0 ; V_84 < V_191 -> V_193 ; V_84 ++ ) {
F_139 ( V_181 -> V_5 , V_181 -> V_22 , & V_192 [ V_84 ] . V_194 , V_191 -> V_195 [ V_84 ] . V_194 ) ;
F_139 ( V_181 -> V_5 , V_181 -> V_22 , & V_192 [ V_84 ] . V_196 , V_191 -> V_195 [ V_84 ] . V_196 ) ;
V_192 [ V_84 ] . V_164 = V_191 -> V_195 [ V_84 ] . V_164 ;
}
return V_192 ;
}
static int F_146 ( struct V_5 * V_5 ,
struct V_22 * V_22 ,
struct V_197 * V_198 ,
struct V_174 * * V_36 ,
struct V_180 * V_199 ,
int V_200 )
{
T_9 V_152 = V_201 ;
int V_202 = V_160 ( V_200 , ( int ) V_198 -> V_193 ) ;
int V_84 ;
int V_203 ;
int V_204 ;
int T_11 V_69 ;
F_147 ( & V_205 ) ;
if ( V_198 -> V_193 > V_206 ) {
F_148 ( L_46 ) ;
return 0 ;
}
T_11 = F_149 ( V_5 , V_22 , V_198 ) ;
for ( V_84 = 0 ; V_84 < V_202 ; V_84 ++ ) {
T_6 V_179 ;
struct V_180 V_181 ;
if ( V_207 . V_208 == V_209 )
V_203 = V_84 ;
else
V_203 = V_198 -> V_193 - V_84 - 1 ;
#ifdef F_150
if ( V_203 == T_11 )
continue;
#endif
V_179 = V_198 -> V_210 [ V_203 ] ;
if ( V_179 >= V_211 ) {
switch ( V_179 ) {
case V_212 :
V_152 = V_213 ;
break;
case V_214 :
V_152 = V_155 ;
break;
case V_215 :
V_152 = V_201 ;
break;
default:
F_93 ( L_47
L_48 V_216 L_14 , ( V_217 ) V_179 ) ;
F_147 ( & V_205 ) ;
return 0 ;
}
continue;
}
V_181 . V_218 = 0 ;
F_142 ( V_22 , V_5 , V_152 ,
V_76 , V_179 , & V_181 ) ;
if ( V_181 . V_175 != NULL ) {
if ( V_219 && ! * V_36 &&
F_138 ( V_181 . V_175 , & V_220 ) )
* V_36 = V_181 . V_175 ;
else if ( V_221 && V_199 &&
F_138 ( V_181 . V_175 , & V_222 ) ) {
* V_199 = V_181 ;
F_147 ( & V_205 ) ;
}
}
V_204 = F_151 ( & V_205 ,
V_179 , V_181 . V_73 , V_181 . V_175 ) ;
if ( V_204 )
return V_204 ;
}
return 0 ;
}
static int F_152 ( struct F_152 * V_223 , void * V_139 )
{
struct V_205 * V_224 = V_139 ;
return F_151 ( V_224 , V_223 -> V_179 ,
V_223 -> V_73 , V_223 -> V_175 ) ;
}
int F_153 ( struct V_5 * V_5 ,
struct V_225 * V_226 ,
struct V_22 * V_22 ,
struct V_62 * V_63 ,
struct V_174 * * V_36 ,
struct V_180 * V_199 ,
int V_200 )
{
int V_81 ;
V_81 = F_146 ( V_5 , V_22 ,
V_63 -> V_227 , V_36 ,
V_199 , V_200 ) ;
if ( V_81 )
return V_81 ;
if ( ! ( ( V_226 -> V_228 . V_229 & V_230 ) &&
( V_226 -> V_228 . V_229 & V_231 ) ) )
return 0 ;
if ( ( ! V_63 -> V_232 . V_233 ) ||
( ! V_63 -> V_234 . V_52 ) )
return 0 ;
return F_154 ( F_152 , & V_205 , V_5 ,
V_22 , V_63 , V_200 ) ;
}
int F_155 ( struct V_5 * V_5 ,
int (* F_156)( struct V_22 * V_22 , void * V_35 ) ,
void * V_235 )
{
struct V_9 * V_31 ;
struct V_22 * V_22 ;
int V_236 = 0 ;
for ( V_31 = F_18 ( & V_5 -> V_12 ) ; V_31 ; V_31 = F_21 ( V_31 ) ) {
V_22 = F_19 ( V_31 , struct V_22 , V_9 ) ;
V_236 = F_156 ( V_22 , V_235 ) ;
if ( V_236 != 0 )
return V_236 ;
}
F_119 (thread, &machine->dead_threads, node) {
V_236 = F_156 ( V_22 , V_235 ) ;
if ( V_236 != 0 )
return V_236 ;
}
return V_236 ;
}
int F_157 ( struct V_5 * V_5 , struct V_237 * V_238 ,
struct V_239 * V_239 , struct V_240 * V_12 ,
T_12 V_49 , bool V_241 )
{
if ( F_158 ( V_239 ) )
return F_159 ( V_238 , V_12 , V_49 , V_5 , V_241 ) ;
else if ( F_160 ( V_239 ) )
return F_161 ( V_238 , V_49 , V_5 , V_241 ) ;
return 0 ;
}
T_1 F_162 ( struct V_5 * V_5 , int V_242 )
{
if ( V_242 < 0 || V_242 >= V_243 || ! V_5 -> V_24 )
return - 1 ;
return V_5 -> V_24 [ V_242 ] ;
}
int F_163 ( struct V_5 * V_5 , int V_242 , T_1 V_7 ,
T_1 V_56 )
{
struct V_22 * V_22 ;
if ( V_242 < 0 )
return - V_244 ;
if ( ! V_5 -> V_24 ) {
int V_84 ;
V_5 -> V_24 = calloc ( V_243 , sizeof( T_1 ) ) ;
if ( ! V_5 -> V_24 )
return - V_20 ;
for ( V_84 = 0 ; V_84 < V_243 ; V_84 ++ )
V_5 -> V_24 [ V_84 ] = - 1 ;
}
if ( V_242 >= V_243 ) {
F_39 ( L_49 , V_242 ) ;
F_39 ( L_50 ) ;
return - V_244 ;
}
V_5 -> V_24 [ V_242 ] = V_56 ;
V_22 = F_7 ( V_5 , V_7 , V_56 ) ;
if ( ! V_22 )
return - V_20 ;
V_22 -> V_242 = V_242 ;
return 0 ;
}
int F_164 ( struct V_5 * V_5 )
{
struct V_73 * V_73 = F_165 ( V_5 , V_76 ) ;
int V_204 = 0 ;
V_5 -> V_19 = 1ULL << 63 ;
if ( V_73 ) {
V_204 = F_166 ( V_73 , V_5 -> V_16 ) ;
if ( V_73 -> V_74 )
V_5 -> V_19 = V_73 -> V_74 ;
}
return V_204 ;
}
