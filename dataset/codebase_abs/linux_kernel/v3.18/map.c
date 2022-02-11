static inline int F_1 ( const char * V_1 )
{
return ! strcmp ( V_1 , L_1 ) ||
! strcmp ( V_1 , L_2 ) ||
! strcmp ( V_1 , L_3 ) ;
}
static inline int F_2 ( const char * V_1 )
{
return ! strncmp ( V_1 , L_4 , 6 ) ||
! strncmp ( V_1 , L_5 , 5 ) ||
! strcmp ( V_1 , L_6 ) ;
}
static inline int F_3 ( const char * V_1 )
{
return ! strncmp ( V_1 , L_7 , 13 ) ||
! strncmp ( V_1 , L_8 , 11 ) ;
}
static inline bool F_4 ( const char * V_1 , char * V_2 )
{
const char * V_3 ;
char * V_4 ;
T_1 V_5 , V_6 ;
T_1 V_7 = 0 ;
V_3 = strrchr ( V_1 , '/' ) ;
if ( V_3 )
V_7 = strlen ( V_3 ) ;
V_4 = getenv ( L_9 ) ;
if ( ! V_4 )
return false ;
V_5 = strlen ( V_4 ) ;
if ( ! strncmp ( V_1 , L_7 , 13 ) ) {
char * V_8 ;
if ( ! V_5 )
return false ;
V_6 = 7 + V_5 + V_7 ;
V_8 = getenv ( L_10 ) ;
if ( V_8 ) {
V_6 += strlen ( V_8 ) + 1 ;
if ( V_6 > V_9 )
return false ;
snprintf ( V_2 , V_6 ,
L_11 , V_8 , V_4 , V_3 ) ;
} else {
if ( V_6 > V_9 )
return false ;
snprintf ( V_2 , V_6 ,
L_12 , V_4 , V_3 ) ;
}
return true ;
}
if ( ! strncmp ( V_1 , L_13 , 11 ) ) {
char * V_10 , * V_11 ;
const char * V_12 ;
T_1 V_13 ;
T_1 V_14 ;
V_10 = getenv ( L_14 ) ;
V_11 = getenv ( L_15 ) ;
if ( ! ( V_10 && V_11 ) )
return false ;
V_13 = strlen ( V_10 ) ;
V_14 = strlen ( V_11 ) ;
if ( ! ( V_13 && V_14 && V_5 ) )
return false ;
V_12 = ! strncmp ( V_4 , L_16 , 3 ) ? L_16 :
! strncmp ( V_4 , L_17 , 4 ) ? L_17 :
! strncmp ( V_4 , L_18 , 3 ) ? L_18 : NULL ;
if ( ! V_12 )
return false ;
V_6 = 27 + V_13 +
V_14 + V_7
+ strlen ( V_12 ) ;
if ( V_6 > V_9 )
return false ;
snprintf ( V_2 , V_6 ,
L_19 ,
V_10 , V_11 , V_12 , V_3 ) ;
return true ;
}
return false ;
}
void F_5 ( struct V_15 * V_15 , enum V_16 type ,
T_2 V_17 , T_2 V_18 , T_2 V_19 , struct V_20 * V_20 )
{
V_15 -> type = type ;
V_15 -> V_17 = V_17 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_21 = 0 ;
V_15 -> V_20 = V_20 ;
V_15 -> V_22 = V_23 ;
V_15 -> V_24 = V_25 ;
F_6 ( & V_15 -> V_26 ) ;
V_15 -> V_27 = NULL ;
V_15 -> V_28 = false ;
V_15 -> V_29 = false ;
}
struct V_15 * F_7 ( struct V_30 * V_30 , T_2 V_17 , T_2 V_31 ,
T_2 V_19 , T_3 V_32 , T_3 V_33 , T_3 V_34 , T_2 V_35 ,
T_2 V_36 , T_3 V_37 , T_3 V_38 , char * V_1 ,
enum V_16 type , struct V_39 * V_39 )
{
struct V_15 * V_15 = malloc ( sizeof( * V_15 ) ) ;
if ( V_15 != NULL ) {
char V_2 [ V_9 ] ;
struct V_20 * V_20 ;
int V_40 , V_41 , V_42 , V_43 ;
V_43 = F_3 ( V_1 ) ;
V_40 = F_1 ( V_1 ) ;
V_42 = F_8 ( V_1 ) ;
V_41 = F_2 ( V_1 ) ;
V_15 -> V_44 = V_33 ;
V_15 -> V_45 = V_34 ;
V_15 -> V_35 = V_35 ;
V_15 -> V_46 = V_36 ;
V_15 -> V_37 = V_37 ;
V_15 -> V_38 = V_38 ;
if ( ( V_40 || V_41 ) && type == V_47 ) {
snprintf ( V_2 , sizeof( V_2 ) , L_20 , V_32 ) ;
V_1 = V_2 ;
}
if ( V_43 ) {
if ( F_4 ( V_1 , V_2 ) )
V_1 = V_2 ;
}
if ( V_42 ) {
V_19 = 0 ;
V_20 = F_9 ( V_30 , V_39 ) ;
} else
V_20 = F_10 ( & V_30 -> V_48 , V_1 ) ;
if ( V_20 == NULL )
goto V_49;
F_5 ( V_15 , type , V_17 , V_17 + V_31 , V_19 , V_20 ) ;
if ( V_40 || V_41 ) {
V_15 -> V_22 = V_15 -> V_24 = V_50 ;
if ( type != V_47 )
F_11 ( V_20 , V_15 -> type ) ;
}
}
return V_15 ;
V_49:
free ( V_15 ) ;
return NULL ;
}
struct V_15 * F_12 ( T_2 V_17 , struct V_20 * V_20 , enum V_16 type )
{
struct V_15 * V_15 = calloc ( 1 , ( sizeof( * V_15 ) +
( V_20 -> V_51 ? sizeof( struct V_52 ) : 0 ) ) ) ;
if ( V_15 != NULL ) {
F_5 ( V_15 , type , V_17 , 0 , 0 , V_20 ) ;
}
return V_15 ;
}
void F_13 ( struct V_15 * V_15 )
{
free ( V_15 ) ;
}
void F_14 ( struct V_15 * V_15 )
{
struct V_53 * V_54 = & V_15 -> V_20 -> V_54 [ V_15 -> type ] ;
struct V_26 * V_55 = F_15 ( V_54 ) ;
if ( V_55 != NULL ) {
struct V_56 * V_57 = F_16 ( V_55 , struct V_56 , V_26 ) ;
V_15 -> V_17 = V_57 -> V_17 ;
}
}
void F_17 ( struct V_15 * V_15 )
{
struct V_53 * V_54 = & V_15 -> V_20 -> V_54 [ V_15 -> type ] ;
struct V_26 * V_55 = F_18 ( V_54 ) ;
if ( V_55 != NULL ) {
struct V_56 * V_57 = F_16 ( V_55 , struct V_56 , V_26 ) ;
V_15 -> V_18 = V_57 -> V_18 ;
}
}
int F_19 ( struct V_15 * V_15 , T_4 V_58 )
{
const char * V_59 = V_15 -> V_20 -> V_60 ;
int V_61 ;
if ( F_20 ( V_15 -> V_20 , V_15 -> type ) )
return 0 ;
V_61 = F_21 ( V_15 -> V_20 , V_15 , V_58 ) ;
if ( V_61 < 0 ) {
if ( V_15 -> V_20 -> V_62 ) {
char V_63 [ V_64 * 2 + 1 ] ;
F_22 ( V_15 -> V_20 -> V_65 ,
sizeof( V_15 -> V_20 -> V_65 ) ,
V_63 ) ;
F_23 ( L_21 ,
V_59 , V_63 ) ;
} else
F_23 ( L_22 , V_59 ) ;
F_23 ( L_23 ) ;
return - 1 ;
} else if ( V_61 == 0 ) {
#ifdef F_24
const T_1 V_31 = strlen ( V_59 ) ;
const T_1 V_66 = V_31 - sizeof( V_67 ) ;
if ( V_31 > sizeof( V_67 ) &&
strcmp ( V_59 + V_66 + 1 , V_67 ) == 0 ) {
F_23 ( L_24
L_25 ,
( int ) V_66 , V_59 ) ;
} else {
F_23 ( L_26
L_27 , V_59 ) ;
}
#endif
return - 1 ;
}
return 0 ;
}
struct V_56 * F_25 ( struct V_15 * V_15 , T_2 V_68 ,
T_4 V_58 )
{
if ( F_19 ( V_15 , V_58 ) < 0 )
return NULL ;
return F_26 ( V_15 -> V_20 , V_15 -> type , V_68 ) ;
}
struct V_56 * F_27 ( struct V_15 * V_15 , const char * V_59 ,
T_4 V_58 )
{
if ( F_19 ( V_15 , V_58 ) < 0 )
return NULL ;
if ( ! F_28 ( V_15 -> V_20 , V_15 -> type ) )
F_29 ( V_15 -> V_20 , V_15 -> type ) ;
return F_30 ( V_15 -> V_20 , V_15 -> type , V_59 ) ;
}
struct V_15 * F_31 ( struct V_15 * V_15 )
{
return F_32 ( V_15 , sizeof( * V_15 ) ) ;
}
int F_33 ( struct V_15 * V_69 , struct V_15 * V_70 )
{
if ( V_69 -> V_17 > V_70 -> V_17 ) {
struct V_15 * V_71 = V_69 ;
V_69 = V_70 ;
V_70 = V_71 ;
}
if ( V_69 -> V_18 > V_70 -> V_17 )
return 1 ;
return 0 ;
}
T_1 F_34 ( struct V_15 * V_15 , T_5 * V_72 )
{
return fprintf ( V_72 , L_28 V_73 L_29 V_73 L_28 V_73 L_30 ,
V_15 -> V_17 , V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 -> V_59 ) ;
}
T_1 F_35 ( struct V_15 * V_15 , T_5 * V_72 )
{
const char * V_74 = L_31 ;
if ( V_15 && V_15 -> V_20 && ( V_15 -> V_20 -> V_59 || V_15 -> V_20 -> V_60 ) ) {
if ( V_75 . V_76 && V_15 -> V_20 -> V_60 )
V_74 = V_15 -> V_20 -> V_60 ;
else if ( V_15 -> V_20 -> V_59 )
V_74 = V_15 -> V_20 -> V_59 ;
}
return fprintf ( V_72 , L_32 , V_74 ) ;
}
int F_36 ( struct V_15 * V_15 , T_2 V_68 , const char * V_77 ,
T_5 * V_72 )
{
char * V_78 ;
int V_79 = 0 ;
if ( V_15 && V_15 -> V_20 ) {
V_78 = F_37 ( V_15 -> V_20 ,
F_38 ( V_15 , V_68 ) ) ;
if ( V_78 != V_80 )
V_79 = fprintf ( V_72 , L_33 , V_77 , V_78 ) ;
F_39 ( V_78 ) ;
}
return V_79 ;
}
T_2 F_38 ( struct V_15 * V_15 , T_2 V_81 )
{
if ( ! V_15 -> V_20 -> V_82 )
return V_81 ;
if ( V_15 -> V_20 -> V_83 )
return V_81 - V_15 -> V_19 ;
return V_15 -> V_24 ( V_15 , V_81 ) - V_15 -> V_21 ;
}
T_2 F_40 ( struct V_15 * V_15 , T_2 V_84 )
{
if ( ! V_15 -> V_20 -> V_82 )
return V_15 -> V_24 ( V_15 , V_84 ) ;
if ( V_15 -> V_20 -> V_83 )
return V_15 -> V_24 ( V_15 , V_84 + V_15 -> V_19 ) ;
return V_84 + V_15 -> V_21 ;
}
void F_41 ( struct V_85 * V_86 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_88 ; ++ V_87 ) {
V_86 -> V_89 [ V_87 ] = V_90 ;
F_42 ( & V_86 -> V_91 [ V_87 ] ) ;
}
V_86 -> V_30 = NULL ;
V_86 -> V_92 = 1 ;
}
static void F_43 ( struct V_53 * V_89 )
{
struct V_26 * V_93 = F_15 ( V_89 ) ;
while ( V_93 ) {
struct V_15 * V_94 = F_16 ( V_93 , struct V_15 , V_26 ) ;
V_93 = F_44 ( & V_94 -> V_26 ) ;
F_45 ( & V_94 -> V_26 , V_89 ) ;
F_13 ( V_94 ) ;
}
}
static void F_46 ( struct V_95 * V_89 )
{
struct V_15 * V_94 , * V_96 ;
F_47 (pos, n, maps, node) {
F_48 ( & V_94 -> V_97 ) ;
F_13 ( V_94 ) ;
}
}
void F_49 ( struct V_85 * V_86 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_88 ; ++ V_87 ) {
F_43 ( & V_86 -> V_89 [ V_87 ] ) ;
F_46 ( & V_86 -> V_91 [ V_87 ] ) ;
}
}
bool F_50 ( struct V_85 * V_86 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_88 ; ++ V_87 ) {
if ( F_51 ( & V_86 -> V_89 [ V_87 ] ) )
return false ;
if ( ! F_52 ( & V_86 -> V_91 [ V_87 ] ) )
return false ;
}
return true ;
}
struct V_85 * F_53 ( void )
{
struct V_85 * V_86 = malloc ( sizeof( * V_86 ) ) ;
if ( V_86 != NULL )
F_41 ( V_86 ) ;
return V_86 ;
}
void F_54 ( struct V_85 * V_86 )
{
F_49 ( V_86 ) ;
free ( V_86 ) ;
}
void F_55 ( struct V_85 * V_86 )
{
if ( -- V_86 -> V_92 == 0 )
F_54 ( V_86 ) ;
}
void F_56 ( struct V_85 * V_86 )
{
int type ;
for ( type = 0 ; type < V_88 ; type ++ ) {
struct V_53 * V_98 = & V_86 -> V_89 [ type ] ;
struct V_26 * V_93 = F_15 ( V_98 ) ;
while ( V_93 ) {
struct V_15 * V_94 = F_16 ( V_93 , struct V_15 , V_26 ) ;
V_93 = F_44 ( & V_94 -> V_26 ) ;
F_45 ( & V_94 -> V_26 , V_98 ) ;
F_57 ( & V_94 -> V_97 , & V_86 -> V_91 [ V_94 -> type ] ) ;
}
}
}
struct V_56 * F_58 ( struct V_85 * V_86 ,
enum V_16 type , T_2 V_68 ,
struct V_15 * * V_99 ,
T_4 V_58 )
{
struct V_15 * V_15 = F_59 ( V_86 , type , V_68 ) ;
if ( V_15 != NULL && F_19 ( V_15 , V_58 ) >= 0 ) {
if ( V_99 != NULL )
* V_99 = V_15 ;
return F_25 ( V_15 , V_15 -> V_22 ( V_15 , V_68 ) , V_58 ) ;
}
return NULL ;
}
struct V_56 * F_60 ( struct V_85 * V_86 ,
enum V_16 type ,
const char * V_59 ,
struct V_15 * * V_99 ,
T_4 V_58 )
{
struct V_26 * V_55 ;
for ( V_55 = F_15 ( & V_86 -> V_89 [ type ] ) ; V_55 ; V_55 = F_44 ( V_55 ) ) {
struct V_15 * V_94 = F_16 ( V_55 , struct V_15 , V_26 ) ;
struct V_56 * V_57 = F_27 ( V_94 , V_59 , V_58 ) ;
if ( V_57 == NULL )
continue;
if ( V_99 != NULL )
* V_99 = V_94 ;
return V_57 ;
}
return NULL ;
}
int F_61 ( struct V_100 * V_101 , T_4 V_58 )
{
if ( V_101 -> V_68 < V_101 -> V_15 -> V_17 || V_101 -> V_68 >= V_101 -> V_15 -> V_18 ) {
if ( V_101 -> V_15 -> V_27 == NULL )
return - 1 ;
V_101 -> V_15 = F_59 ( V_101 -> V_15 -> V_27 , V_101 -> V_15 -> type ,
V_101 -> V_68 ) ;
if ( V_101 -> V_15 == NULL )
return - 1 ;
}
V_101 -> V_102 = V_101 -> V_15 -> V_22 ( V_101 -> V_15 , V_101 -> V_68 ) ;
V_101 -> V_57 = F_25 ( V_101 -> V_15 , V_101 -> V_102 , V_58 ) ;
return V_101 -> V_57 ? 0 : - 1 ;
}
T_1 F_62 ( struct V_85 * V_86 , enum V_16 type ,
T_5 * V_72 )
{
T_1 V_103 = fprintf ( V_72 , L_34 , V_104 [ type ] ) ;
struct V_26 * V_55 ;
for ( V_55 = F_15 ( & V_86 -> V_89 [ type ] ) ; V_55 ; V_55 = F_44 ( V_55 ) ) {
struct V_15 * V_94 = F_16 ( V_55 , struct V_15 , V_26 ) ;
V_103 += fprintf ( V_72 , L_35 ) ;
V_103 += F_34 ( V_94 , V_72 ) ;
if ( V_105 > 2 ) {
V_103 += F_63 ( V_94 -> V_20 , type , V_72 ) ;
V_103 += fprintf ( V_72 , L_36 ) ;
}
}
return V_103 ;
}
static T_1 F_64 ( struct V_85 * V_86 , T_5 * V_72 )
{
T_1 V_103 = 0 , V_87 ;
for ( V_87 = 0 ; V_87 < V_88 ; ++ V_87 )
V_103 += F_62 ( V_86 , V_87 , V_72 ) ;
return V_103 ;
}
static T_1 F_65 ( struct V_85 * V_86 ,
enum V_16 type , T_5 * V_72 )
{
struct V_15 * V_94 ;
T_1 V_103 = 0 ;
F_66 (pos, &mg->removed_maps[type], node) {
V_103 += fprintf ( V_72 , L_35 ) ;
V_103 += F_34 ( V_94 , V_72 ) ;
if ( V_105 > 1 ) {
V_103 += F_63 ( V_94 -> V_20 , type , V_72 ) ;
V_103 += fprintf ( V_72 , L_36 ) ;
}
}
return V_103 ;
}
static T_1 F_67 ( struct V_85 * V_86 ,
T_5 * V_72 )
{
T_1 V_103 = 0 , V_87 ;
for ( V_87 = 0 ; V_87 < V_88 ; ++ V_87 )
V_103 += F_65 ( V_86 , V_87 , V_72 ) ;
return V_103 ;
}
T_1 F_68 ( struct V_85 * V_86 , T_5 * V_72 )
{
T_1 V_103 = F_64 ( V_86 , V_72 ) ;
V_103 += fprintf ( V_72 , L_37 ) ;
return V_103 + F_67 ( V_86 , V_72 ) ;
}
int F_69 ( struct V_85 * V_86 , struct V_15 * V_15 ,
T_5 * V_72 )
{
struct V_53 * V_98 = & V_86 -> V_89 [ V_15 -> type ] ;
struct V_26 * V_93 = F_15 ( V_98 ) ;
int V_106 = 0 ;
while ( V_93 ) {
struct V_15 * V_94 = F_16 ( V_93 , struct V_15 , V_26 ) ;
V_93 = F_44 ( & V_94 -> V_26 ) ;
if ( ! F_33 ( V_94 , V_15 ) )
continue;
if ( V_105 >= 2 ) {
fputs ( L_38 , V_72 ) ;
F_34 ( V_15 , V_72 ) ;
F_34 ( V_94 , V_72 ) ;
}
F_45 ( & V_94 -> V_26 , V_98 ) ;
if ( V_15 -> V_17 > V_94 -> V_17 ) {
struct V_15 * V_107 = F_31 ( V_94 ) ;
if ( V_107 == NULL ) {
V_106 = - V_108 ;
goto V_109;
}
V_107 -> V_18 = V_15 -> V_17 ;
F_70 ( V_86 , V_107 ) ;
if ( V_105 >= 2 )
F_34 ( V_107 , V_72 ) ;
}
if ( V_15 -> V_18 < V_94 -> V_18 ) {
struct V_15 * V_110 = F_31 ( V_94 ) ;
if ( V_110 == NULL ) {
V_106 = - V_108 ;
goto V_109;
}
V_110 -> V_17 = V_15 -> V_18 ;
F_70 ( V_86 , V_110 ) ;
if ( V_105 >= 2 )
F_34 ( V_110 , V_72 ) ;
}
V_109:
if ( V_94 -> V_28 )
F_57 ( & V_94 -> V_97 , & V_86 -> V_91 [ V_15 -> type ] ) ;
else
F_13 ( V_94 ) ;
if ( V_106 )
return V_106 ;
}
return 0 ;
}
int F_71 ( struct V_85 * V_86 ,
struct V_85 * V_111 , enum V_16 type )
{
struct V_26 * V_55 ;
for ( V_55 = F_15 ( & V_111 -> V_89 [ type ] ) ; V_55 ; V_55 = F_44 ( V_55 ) ) {
struct V_15 * V_15 = F_16 ( V_55 , struct V_15 , V_26 ) ;
struct V_15 * V_112 = F_31 ( V_15 ) ;
if ( V_112 == NULL )
return - V_108 ;
F_70 ( V_86 , V_112 ) ;
}
return 0 ;
}
void F_72 ( struct V_53 * V_89 , struct V_15 * V_15 )
{
struct V_26 * * V_113 = & V_89 -> V_26 ;
struct V_26 * V_111 = NULL ;
const T_2 V_84 = V_15 -> V_17 ;
struct V_15 * V_114 ;
while ( * V_113 != NULL ) {
V_111 = * V_113 ;
V_114 = F_16 ( V_111 , struct V_15 , V_26 ) ;
if ( V_84 < V_114 -> V_17 )
V_113 = & ( * V_113 ) -> V_115 ;
else
V_113 = & ( * V_113 ) -> V_116 ;
}
F_73 ( & V_15 -> V_26 , V_111 , V_113 ) ;
F_74 ( & V_15 -> V_26 , V_89 ) ;
}
void F_75 ( struct V_53 * V_89 , struct V_15 * V_15 )
{
F_45 ( & V_15 -> V_26 , V_89 ) ;
}
struct V_15 * F_76 ( struct V_53 * V_89 , T_2 V_84 )
{
struct V_26 * * V_113 = & V_89 -> V_26 ;
struct V_26 * V_111 = NULL ;
struct V_15 * V_114 ;
while ( * V_113 != NULL ) {
V_111 = * V_113 ;
V_114 = F_16 ( V_111 , struct V_15 , V_26 ) ;
if ( V_84 < V_114 -> V_17 )
V_113 = & ( * V_113 ) -> V_115 ;
else if ( V_84 >= V_114 -> V_18 )
V_113 = & ( * V_113 ) -> V_116 ;
else
return V_114 ;
}
return NULL ;
}
struct V_15 * F_51 ( struct V_53 * V_89 )
{
struct V_26 * V_117 = F_15 ( V_89 ) ;
if ( V_117 )
return F_16 ( V_117 , struct V_15 , V_26 ) ;
return NULL ;
}
struct V_15 * F_77 ( struct V_15 * V_15 )
{
struct V_26 * V_93 = F_44 ( & V_15 -> V_26 ) ;
if ( V_93 )
return F_16 ( V_93 , struct V_15 , V_26 ) ;
return NULL ;
}
