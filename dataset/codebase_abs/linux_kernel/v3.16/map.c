static inline int F_1 ( const char * V_1 )
{
return ! strcmp ( V_1 , L_1 ) ||
! strcmp ( V_1 , L_2 ) ||
! strcmp ( V_1 , L_3 ) ;
}
static inline int F_2 ( const char * V_1 )
{
return ! strncmp ( V_1 , L_4 , 6 ) ||
! strcmp ( V_1 , L_5 ) ;
}
static inline int F_3 ( const char * V_1 )
{
return ! strncmp ( V_1 , L_6 , 13 ) ||
! strncmp ( V_1 , L_7 , 11 ) ;
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
V_4 = getenv ( L_8 ) ;
if ( ! V_4 )
return false ;
V_5 = strlen ( V_4 ) ;
if ( ! strncmp ( V_1 , L_6 , 13 ) ) {
char * V_8 ;
if ( ! V_5 )
return false ;
V_6 = 7 + V_5 + V_7 ;
V_8 = getenv ( L_9 ) ;
if ( V_8 ) {
V_6 += strlen ( V_8 ) + 1 ;
if ( V_6 > V_9 )
return false ;
snprintf ( V_2 , V_6 ,
L_10 , V_8 , V_4 , V_3 ) ;
} else {
if ( V_6 > V_9 )
return false ;
snprintf ( V_2 , V_6 ,
L_11 , V_4 , V_3 ) ;
}
return true ;
}
if ( ! strncmp ( V_1 , L_12 , 11 ) ) {
char * V_10 , * V_11 ;
const char * V_12 ;
T_1 V_13 ;
T_1 V_14 ;
V_10 = getenv ( L_13 ) ;
V_11 = getenv ( L_14 ) ;
if ( ! ( V_10 && V_11 ) )
return false ;
V_13 = strlen ( V_10 ) ;
V_14 = strlen ( V_11 ) ;
if ( ! ( V_13 && V_14 && V_5 ) )
return false ;
V_12 = ! strncmp ( V_4 , L_15 , 3 ) ? L_15 :
! strncmp ( V_4 , L_16 , 4 ) ? L_16 :
! strncmp ( V_4 , L_17 , 3 ) ? L_17 : NULL ;
if ( ! V_12 )
return false ;
V_6 = 27 + V_13 +
V_14 + V_7
+ strlen ( V_12 ) ;
if ( V_6 > V_9 )
return false ;
snprintf ( V_2 , V_6 ,
L_18 ,
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
struct V_15 * F_7 ( struct V_30 * V_31 , T_2 V_17 , T_2 V_32 ,
T_2 V_19 , T_3 V_33 , T_3 V_34 , T_3 V_35 , T_2 V_36 ,
T_2 V_37 , T_3 V_38 , T_3 V_39 , char * V_1 ,
enum V_16 type )
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
V_15 -> V_44 = V_34 ;
V_15 -> V_45 = V_35 ;
V_15 -> V_36 = V_36 ;
V_15 -> V_46 = V_37 ;
V_15 -> V_38 = V_38 ;
V_15 -> V_39 = V_39 ;
if ( ( V_40 || V_41 ) && type == V_47 ) {
snprintf ( V_2 , sizeof( V_2 ) , L_19 , V_33 ) ;
V_1 = V_2 ;
}
if ( V_43 ) {
if ( F_4 ( V_1 , V_2 ) )
V_1 = V_2 ;
}
if ( V_42 ) {
V_19 = 0 ;
V_20 = F_9 ( V_31 ) ;
} else
V_20 = F_10 ( V_31 , V_1 ) ;
if ( V_20 == NULL )
goto V_48;
F_5 ( V_15 , type , V_17 , V_17 + V_32 , V_19 , V_20 ) ;
if ( V_40 || V_41 ) {
V_15 -> V_22 = V_15 -> V_24 = V_49 ;
if ( type != V_47 )
F_11 ( V_20 , V_15 -> type ) ;
}
}
return V_15 ;
V_48:
free ( V_15 ) ;
return NULL ;
}
struct V_15 * F_12 ( T_2 V_17 , struct V_20 * V_20 , enum V_16 type )
{
struct V_15 * V_15 = calloc ( 1 , ( sizeof( * V_15 ) +
( V_20 -> V_50 ? sizeof( struct V_51 ) : 0 ) ) ) ;
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
struct V_52 * V_53 = & V_15 -> V_20 -> V_53 [ V_15 -> type ] ;
struct V_26 * V_54 = F_15 ( V_53 ) ;
if ( V_54 != NULL ) {
struct V_55 * V_56 = F_16 ( V_54 , struct V_55 , V_26 ) ;
V_15 -> V_17 = V_56 -> V_17 ;
}
}
void F_17 ( struct V_15 * V_15 )
{
struct V_52 * V_53 = & V_15 -> V_20 -> V_53 [ V_15 -> type ] ;
struct V_26 * V_54 = F_18 ( V_53 ) ;
if ( V_54 != NULL ) {
struct V_55 * V_56 = F_16 ( V_54 , struct V_55 , V_26 ) ;
V_15 -> V_18 = V_56 -> V_18 ;
}
}
int F_19 ( struct V_15 * V_15 , T_4 V_57 )
{
const char * V_58 = V_15 -> V_20 -> V_59 ;
int V_60 ;
if ( F_20 ( V_15 -> V_20 , V_15 -> type ) )
return 0 ;
V_60 = F_21 ( V_15 -> V_20 , V_15 , V_57 ) ;
if ( V_60 < 0 ) {
if ( V_15 -> V_20 -> V_61 ) {
char V_62 [ V_63 * 2 + 1 ] ;
F_22 ( V_15 -> V_20 -> V_64 ,
sizeof( V_15 -> V_20 -> V_64 ) ,
V_62 ) ;
F_23 ( L_20 ,
V_58 , V_62 ) ;
} else
F_23 ( L_21 , V_58 ) ;
F_23 ( L_22 ) ;
return - 1 ;
} else if ( V_60 == 0 ) {
#ifdef F_24
const T_1 V_32 = strlen ( V_58 ) ;
const T_1 V_65 = V_32 - sizeof( V_66 ) ;
if ( V_32 > sizeof( V_66 ) &&
strcmp ( V_58 + V_65 + 1 , V_66 ) == 0 ) {
F_23 ( L_23
L_24 ,
( int ) V_65 , V_58 ) ;
} else {
F_23 ( L_25
L_26 , V_58 ) ;
}
#endif
return - 1 ;
}
return 0 ;
}
struct V_55 * F_25 ( struct V_15 * V_15 , T_2 V_67 ,
T_4 V_57 )
{
if ( F_19 ( V_15 , V_57 ) < 0 )
return NULL ;
return F_26 ( V_15 -> V_20 , V_15 -> type , V_67 ) ;
}
struct V_55 * F_27 ( struct V_15 * V_15 , const char * V_58 ,
T_4 V_57 )
{
if ( F_19 ( V_15 , V_57 ) < 0 )
return NULL ;
if ( ! F_28 ( V_15 -> V_20 , V_15 -> type ) )
F_29 ( V_15 -> V_20 , V_15 -> type ) ;
return F_30 ( V_15 -> V_20 , V_15 -> type , V_58 ) ;
}
struct V_15 * F_31 ( struct V_15 * V_15 )
{
return F_32 ( V_15 , sizeof( * V_15 ) ) ;
}
int F_33 ( struct V_15 * V_68 , struct V_15 * V_69 )
{
if ( V_68 -> V_17 > V_69 -> V_17 ) {
struct V_15 * V_70 = V_68 ;
V_68 = V_69 ;
V_69 = V_70 ;
}
if ( V_68 -> V_18 > V_69 -> V_17 )
return 1 ;
return 0 ;
}
T_1 F_34 ( struct V_15 * V_15 , T_5 * V_71 )
{
return fprintf ( V_71 , L_27 V_72 L_28 V_72 L_27 V_72 L_29 ,
V_15 -> V_17 , V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 -> V_58 ) ;
}
T_1 F_35 ( struct V_15 * V_15 , T_5 * V_71 )
{
const char * V_73 = L_30 ;
if ( V_15 && V_15 -> V_20 && ( V_15 -> V_20 -> V_58 || V_15 -> V_20 -> V_59 ) ) {
if ( V_74 . V_75 && V_15 -> V_20 -> V_59 )
V_73 = V_15 -> V_20 -> V_59 ;
else if ( V_15 -> V_20 -> V_58 )
V_73 = V_15 -> V_20 -> V_58 ;
}
return fprintf ( V_71 , L_31 , V_73 ) ;
}
int F_36 ( struct V_15 * V_15 , T_2 V_67 , const char * V_76 ,
T_5 * V_71 )
{
char * V_77 ;
int V_78 = 0 ;
if ( V_15 && V_15 -> V_20 ) {
V_77 = F_37 ( V_15 -> V_20 ,
F_38 ( V_15 , V_67 ) ) ;
if ( V_77 != V_79 )
V_78 = fprintf ( V_71 , L_32 , V_76 , V_77 ) ;
F_39 ( V_77 ) ;
}
return V_78 ;
}
T_2 F_38 ( struct V_15 * V_15 , T_2 V_80 )
{
if ( ! V_15 -> V_20 -> V_81 )
return V_80 ;
if ( V_15 -> V_20 -> V_82 )
return V_80 - V_15 -> V_19 ;
return V_15 -> V_24 ( V_15 , V_80 ) - V_15 -> V_21 ;
}
T_2 F_40 ( struct V_15 * V_15 , T_2 V_83 )
{
if ( ! V_15 -> V_20 -> V_81 )
return V_15 -> V_24 ( V_15 , V_83 ) ;
if ( V_15 -> V_20 -> V_82 )
return V_15 -> V_24 ( V_15 , V_83 + V_15 -> V_19 ) ;
return V_83 + V_15 -> V_21 ;
}
void F_41 ( struct V_84 * V_85 )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < V_87 ; ++ V_86 ) {
V_85 -> V_88 [ V_86 ] = V_89 ;
F_42 ( & V_85 -> V_90 [ V_86 ] ) ;
}
V_85 -> V_91 = NULL ;
V_85 -> V_92 = 1 ;
}
static void F_43 ( struct V_52 * V_88 )
{
struct V_26 * V_93 = F_15 ( V_88 ) ;
while ( V_93 ) {
struct V_15 * V_94 = F_16 ( V_93 , struct V_15 , V_26 ) ;
V_93 = F_44 ( & V_94 -> V_26 ) ;
F_45 ( & V_94 -> V_26 , V_88 ) ;
F_13 ( V_94 ) ;
}
}
static void F_46 ( struct V_30 * V_88 )
{
struct V_15 * V_94 , * V_95 ;
F_47 (pos, n, maps, node) {
F_48 ( & V_94 -> V_96 ) ;
F_13 ( V_94 ) ;
}
}
void F_49 ( struct V_84 * V_85 )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < V_87 ; ++ V_86 ) {
F_43 ( & V_85 -> V_88 [ V_86 ] ) ;
F_46 ( & V_85 -> V_90 [ V_86 ] ) ;
}
}
struct V_84 * F_50 ( void )
{
struct V_84 * V_85 = malloc ( sizeof( * V_85 ) ) ;
if ( V_85 != NULL )
F_41 ( V_85 ) ;
return V_85 ;
}
void F_51 ( struct V_84 * V_85 )
{
F_49 ( V_85 ) ;
free ( V_85 ) ;
}
void F_52 ( struct V_84 * V_85 )
{
if ( -- V_85 -> V_92 == 0 )
F_51 ( V_85 ) ;
}
void F_53 ( struct V_84 * V_85 )
{
int type ;
for ( type = 0 ; type < V_87 ; type ++ ) {
struct V_52 * V_97 = & V_85 -> V_88 [ type ] ;
struct V_26 * V_93 = F_15 ( V_97 ) ;
while ( V_93 ) {
struct V_15 * V_94 = F_16 ( V_93 , struct V_15 , V_26 ) ;
V_93 = F_44 ( & V_94 -> V_26 ) ;
F_45 ( & V_94 -> V_26 , V_97 ) ;
F_54 ( & V_94 -> V_96 , & V_85 -> V_90 [ V_94 -> type ] ) ;
}
}
}
struct V_55 * F_55 ( struct V_84 * V_85 ,
enum V_16 type , T_2 V_67 ,
struct V_15 * * V_98 ,
T_4 V_57 )
{
struct V_15 * V_15 = F_56 ( V_85 , type , V_67 ) ;
if ( V_15 != NULL && F_19 ( V_15 , V_57 ) >= 0 ) {
if ( V_98 != NULL )
* V_98 = V_15 ;
return F_25 ( V_15 , V_15 -> V_22 ( V_15 , V_67 ) , V_57 ) ;
}
return NULL ;
}
struct V_55 * F_57 ( struct V_84 * V_85 ,
enum V_16 type ,
const char * V_58 ,
struct V_15 * * V_98 ,
T_4 V_57 )
{
struct V_26 * V_54 ;
for ( V_54 = F_15 ( & V_85 -> V_88 [ type ] ) ; V_54 ; V_54 = F_44 ( V_54 ) ) {
struct V_15 * V_94 = F_16 ( V_54 , struct V_15 , V_26 ) ;
struct V_55 * V_56 = F_27 ( V_94 , V_58 , V_57 ) ;
if ( V_56 == NULL )
continue;
if ( V_98 != NULL )
* V_98 = V_94 ;
return V_56 ;
}
return NULL ;
}
int F_58 ( struct V_99 * V_100 , T_4 V_57 )
{
if ( V_100 -> V_67 < V_100 -> V_15 -> V_17 || V_100 -> V_67 > V_100 -> V_15 -> V_18 ) {
if ( V_100 -> V_15 -> V_27 == NULL )
return - 1 ;
V_100 -> V_15 = F_56 ( V_100 -> V_15 -> V_27 , V_100 -> V_15 -> type ,
V_100 -> V_67 ) ;
if ( V_100 -> V_15 == NULL )
return - 1 ;
}
V_100 -> V_101 = V_100 -> V_15 -> V_22 ( V_100 -> V_15 , V_100 -> V_67 ) ;
V_100 -> V_56 = F_25 ( V_100 -> V_15 , V_100 -> V_101 , V_57 ) ;
return V_100 -> V_56 ? 0 : - 1 ;
}
T_1 F_59 ( struct V_84 * V_85 ,
enum V_16 type , int V_102 , T_5 * V_71 )
{
T_1 V_103 = fprintf ( V_71 , L_33 , V_104 [ type ] ) ;
struct V_26 * V_54 ;
for ( V_54 = F_15 ( & V_85 -> V_88 [ type ] ) ; V_54 ; V_54 = F_44 ( V_54 ) ) {
struct V_15 * V_94 = F_16 ( V_54 , struct V_15 , V_26 ) ;
V_103 += fprintf ( V_71 , L_34 ) ;
V_103 += F_34 ( V_94 , V_71 ) ;
if ( V_102 > 2 ) {
V_103 += F_60 ( V_94 -> V_20 , type , V_71 ) ;
V_103 += fprintf ( V_71 , L_35 ) ;
}
}
return V_103 ;
}
T_1 F_61 ( struct V_84 * V_85 , int V_102 , T_5 * V_71 )
{
T_1 V_103 = 0 , V_86 ;
for ( V_86 = 0 ; V_86 < V_87 ; ++ V_86 )
V_103 += F_59 ( V_85 , V_86 , V_102 , V_71 ) ;
return V_103 ;
}
static T_1 F_62 ( struct V_84 * V_85 ,
enum V_16 type ,
int V_102 , T_5 * V_71 )
{
struct V_15 * V_94 ;
T_1 V_103 = 0 ;
F_63 (pos, &mg->removed_maps[type], node) {
V_103 += fprintf ( V_71 , L_34 ) ;
V_103 += F_34 ( V_94 , V_71 ) ;
if ( V_102 > 1 ) {
V_103 += F_60 ( V_94 -> V_20 , type , V_71 ) ;
V_103 += fprintf ( V_71 , L_35 ) ;
}
}
return V_103 ;
}
static T_1 F_64 ( struct V_84 * V_85 ,
int V_102 , T_5 * V_71 )
{
T_1 V_103 = 0 , V_86 ;
for ( V_86 = 0 ; V_86 < V_87 ; ++ V_86 )
V_103 += F_62 ( V_85 , V_86 , V_102 , V_71 ) ;
return V_103 ;
}
T_1 F_65 ( struct V_84 * V_85 , int V_102 , T_5 * V_71 )
{
T_1 V_103 = F_61 ( V_85 , V_102 , V_71 ) ;
V_103 += fprintf ( V_71 , L_36 ) ;
return V_103 + F_64 ( V_85 , V_102 , V_71 ) ;
}
int F_66 ( struct V_84 * V_85 , struct V_15 * V_15 ,
int V_102 , T_5 * V_71 )
{
struct V_52 * V_97 = & V_85 -> V_88 [ V_15 -> type ] ;
struct V_26 * V_93 = F_15 ( V_97 ) ;
int V_105 = 0 ;
while ( V_93 ) {
struct V_15 * V_94 = F_16 ( V_93 , struct V_15 , V_26 ) ;
V_93 = F_44 ( & V_94 -> V_26 ) ;
if ( ! F_33 ( V_94 , V_15 ) )
continue;
if ( V_102 >= 2 ) {
fputs ( L_37 , V_71 ) ;
F_34 ( V_15 , V_71 ) ;
F_34 ( V_94 , V_71 ) ;
}
F_45 ( & V_94 -> V_26 , V_97 ) ;
if ( V_15 -> V_17 > V_94 -> V_17 ) {
struct V_15 * V_106 = F_31 ( V_94 ) ;
if ( V_106 == NULL ) {
V_105 = - V_107 ;
goto V_108;
}
V_106 -> V_18 = V_15 -> V_17 - 1 ;
F_67 ( V_85 , V_106 ) ;
if ( V_102 >= 2 )
F_34 ( V_106 , V_71 ) ;
}
if ( V_15 -> V_18 < V_94 -> V_18 ) {
struct V_15 * V_109 = F_31 ( V_94 ) ;
if ( V_109 == NULL ) {
V_105 = - V_107 ;
goto V_108;
}
V_109 -> V_17 = V_15 -> V_18 + 1 ;
F_67 ( V_85 , V_109 ) ;
if ( V_102 >= 2 )
F_34 ( V_109 , V_71 ) ;
}
V_108:
if ( V_94 -> V_28 )
F_54 ( & V_94 -> V_96 , & V_85 -> V_90 [ V_15 -> type ] ) ;
else
F_13 ( V_94 ) ;
if ( V_105 )
return V_105 ;
}
return 0 ;
}
int F_68 ( struct V_84 * V_85 ,
struct V_84 * V_110 , enum V_16 type )
{
struct V_26 * V_54 ;
for ( V_54 = F_15 ( & V_110 -> V_88 [ type ] ) ; V_54 ; V_54 = F_44 ( V_54 ) ) {
struct V_15 * V_15 = F_16 ( V_54 , struct V_15 , V_26 ) ;
struct V_15 * V_111 = F_31 ( V_15 ) ;
if ( V_111 == NULL )
return - V_107 ;
F_67 ( V_85 , V_111 ) ;
}
return 0 ;
}
void F_69 ( struct V_52 * V_88 , struct V_15 * V_15 )
{
struct V_26 * * V_112 = & V_88 -> V_26 ;
struct V_26 * V_110 = NULL ;
const T_2 V_83 = V_15 -> V_17 ;
struct V_15 * V_113 ;
while ( * V_112 != NULL ) {
V_110 = * V_112 ;
V_113 = F_16 ( V_110 , struct V_15 , V_26 ) ;
if ( V_83 < V_113 -> V_17 )
V_112 = & ( * V_112 ) -> V_114 ;
else
V_112 = & ( * V_112 ) -> V_115 ;
}
F_70 ( & V_15 -> V_26 , V_110 , V_112 ) ;
F_71 ( & V_15 -> V_26 , V_88 ) ;
}
void F_72 ( struct V_52 * V_88 , struct V_15 * V_15 )
{
F_45 ( & V_15 -> V_26 , V_88 ) ;
}
struct V_15 * F_73 ( struct V_52 * V_88 , T_2 V_83 )
{
struct V_26 * * V_112 = & V_88 -> V_26 ;
struct V_26 * V_110 = NULL ;
struct V_15 * V_113 ;
while ( * V_112 != NULL ) {
V_110 = * V_112 ;
V_113 = F_16 ( V_110 , struct V_15 , V_26 ) ;
if ( V_83 < V_113 -> V_17 )
V_112 = & ( * V_112 ) -> V_114 ;
else if ( V_83 > V_113 -> V_18 )
V_112 = & ( * V_112 ) -> V_115 ;
else
return V_113 ;
}
return NULL ;
}
struct V_15 * F_74 ( struct V_52 * V_88 )
{
struct V_26 * V_116 = F_15 ( V_88 ) ;
if ( V_116 )
return F_16 ( V_116 , struct V_15 , V_26 ) ;
return NULL ;
}
struct V_15 * F_75 ( struct V_15 * V_15 )
{
struct V_26 * V_93 = F_44 ( & V_15 -> V_26 ) ;
if ( V_93 )
return F_16 ( V_93 , struct V_15 , V_26 ) ;
return NULL ;
}
