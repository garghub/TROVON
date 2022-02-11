static inline int F_1 ( const char * V_1 , T_1 V_2 )
{
return V_2 & V_3 ||
! strcmp ( V_1 , L_1 ) ||
! strncmp ( V_1 , L_2 , sizeof( L_2 ) - 1 ) ||
! strncmp ( V_1 , L_3 , sizeof( L_3 ) - 1 ) ;
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
static inline bool F_4 ( const char * V_1 , char * V_4 )
{
const char * V_5 ;
char * V_6 ;
T_2 V_7 , V_8 ;
T_2 V_9 = 0 ;
V_5 = strrchr ( V_1 , '/' ) ;
if ( V_5 )
V_9 = strlen ( V_5 ) ;
V_6 = getenv ( L_9 ) ;
if ( ! V_6 )
return false ;
V_7 = strlen ( V_6 ) ;
if ( ! strncmp ( V_1 , L_7 , 13 ) ) {
char * V_10 ;
if ( ! V_7 )
return false ;
V_8 = 7 + V_7 + V_9 ;
V_10 = getenv ( L_10 ) ;
if ( V_10 ) {
V_8 += strlen ( V_10 ) + 1 ;
if ( V_8 > V_11 )
return false ;
snprintf ( V_4 , V_8 ,
L_11 , V_10 , V_6 , V_5 ) ;
} else {
if ( V_8 > V_11 )
return false ;
snprintf ( V_4 , V_8 ,
L_12 , V_6 , V_5 ) ;
}
return true ;
}
if ( ! strncmp ( V_1 , L_13 , 11 ) ) {
char * V_12 , * V_13 ;
const char * V_14 ;
T_2 V_15 ;
T_2 V_16 ;
V_12 = getenv ( L_14 ) ;
V_13 = getenv ( L_15 ) ;
if ( ! ( V_12 && V_13 ) )
return false ;
V_15 = strlen ( V_12 ) ;
V_16 = strlen ( V_13 ) ;
if ( ! ( V_15 && V_16 && V_7 ) )
return false ;
V_14 = ! strncmp ( V_6 , L_16 , 3 ) ? L_16 :
! strncmp ( V_6 , L_17 , 4 ) ? L_17 :
! strncmp ( V_6 , L_18 , 3 ) ? L_18 : NULL ;
if ( ! V_14 )
return false ;
V_8 = 27 + V_15 +
V_16 + V_9
+ strlen ( V_14 ) ;
if ( V_8 > V_11 )
return false ;
snprintf ( V_4 , V_8 ,
L_19 ,
V_12 , V_13 , V_14 , V_5 ) ;
return true ;
}
return false ;
}
void F_5 ( struct V_17 * V_17 , enum V_18 type ,
T_3 V_19 , T_3 V_20 , T_3 V_21 , struct V_22 * V_22 )
{
V_17 -> type = type ;
V_17 -> V_19 = V_19 ;
V_17 -> V_20 = V_20 ;
V_17 -> V_21 = V_21 ;
V_17 -> V_23 = 0 ;
V_17 -> V_22 = F_6 ( V_22 ) ;
V_17 -> V_24 = V_25 ;
V_17 -> V_26 = V_27 ;
F_7 ( & V_17 -> V_28 ) ;
V_17 -> V_29 = NULL ;
V_17 -> V_30 = false ;
F_8 ( & V_17 -> V_31 , 1 ) ;
}
struct V_17 * F_9 ( struct V_32 * V_32 , T_3 V_19 , T_3 V_33 ,
T_3 V_21 , T_1 V_34 , T_1 V_35 , T_3 V_36 ,
T_3 V_37 , T_1 V_38 , T_1 V_2 , char * V_1 ,
enum V_18 type , struct V_39 * V_39 )
{
struct V_17 * V_17 = malloc ( sizeof( * V_17 ) ) ;
struct V_40 * V_41 = NULL ;
struct V_40 * V_42 ;
if ( V_17 != NULL ) {
char V_4 [ V_11 ] ;
struct V_22 * V_22 ;
int V_43 , V_44 , V_45 , V_46 ;
V_46 = F_3 ( V_1 ) ;
V_43 = F_1 ( V_1 , V_2 ) ;
V_45 = F_10 ( V_1 ) ;
V_44 = F_2 ( V_1 ) ;
V_17 -> V_47 = V_34 ;
V_17 -> V_48 = V_35 ;
V_17 -> V_36 = V_36 ;
V_17 -> V_49 = V_37 ;
V_17 -> V_38 = V_38 ;
V_17 -> V_2 = V_2 ;
V_41 = F_11 ( V_39 -> V_40 ) ;
if ( ( V_43 || V_44 ) && V_41 && type == V_50 ) {
snprintf ( V_4 , sizeof( V_4 ) ,
L_20 , V_41 -> V_51 ) ;
V_1 = V_4 ;
}
if ( V_46 ) {
if ( F_4 ( V_1 , V_4 ) )
V_1 = V_4 ;
}
if ( V_45 ) {
V_42 = F_12 ( V_41 ) ;
if ( V_42 ) {
F_13 ( V_41 ) ;
V_42 -> V_52 = false ;
V_41 = V_42 ;
}
V_21 = 0 ;
V_22 = F_14 ( V_32 , V_39 ) ;
} else
V_22 = F_15 ( V_32 , V_1 ) ;
if ( V_22 == NULL )
goto V_53;
F_5 ( V_17 , type , V_19 , V_19 + V_33 , V_21 , V_22 ) ;
if ( V_43 || V_44 ) {
V_17 -> V_24 = V_17 -> V_26 = V_54 ;
if ( type != V_50 )
F_16 ( V_22 , V_17 -> type ) ;
}
V_22 -> V_40 = V_41 ;
F_17 ( V_22 ) ;
}
return V_17 ;
V_53:
F_13 ( V_41 ) ;
free ( V_17 ) ;
return NULL ;
}
struct V_17 * F_18 ( T_3 V_19 , struct V_22 * V_22 , enum V_18 type )
{
struct V_17 * V_17 = calloc ( 1 , ( sizeof( * V_17 ) +
( V_22 -> V_55 ? sizeof( struct V_56 ) : 0 ) ) ) ;
if ( V_17 != NULL ) {
F_5 ( V_17 , type , V_19 , 0 , 0 , V_22 ) ;
}
return V_17 ;
}
bool F_19 ( const struct V_17 * V_17 )
{
return F_20 ( V_17 -> V_29 -> V_32 , V_17 -> type ) == V_17 ;
}
static void F_21 ( struct V_17 * V_17 )
{
F_22 ( ! F_23 ( & V_17 -> V_28 ) ) ;
F_24 ( V_17 -> V_22 ) ;
}
void F_25 ( struct V_17 * V_17 )
{
F_21 ( V_17 ) ;
free ( V_17 ) ;
}
void F_26 ( struct V_17 * V_17 )
{
if ( V_17 && F_27 ( & V_17 -> V_31 ) )
F_25 ( V_17 ) ;
}
void F_28 ( struct V_17 * V_17 )
{
struct V_57 * V_58 = & V_17 -> V_22 -> V_58 [ V_17 -> type ] ;
struct V_28 * V_59 = F_29 ( V_58 ) ;
if ( V_59 != NULL ) {
struct V_60 * V_61 = F_30 ( V_59 , struct V_60 , V_28 ) ;
V_17 -> V_19 = V_61 -> V_19 ;
}
}
void F_31 ( struct V_17 * V_17 )
{
struct V_57 * V_58 = & V_17 -> V_22 -> V_58 [ V_17 -> type ] ;
struct V_28 * V_59 = F_32 ( V_58 ) ;
if ( V_59 != NULL ) {
struct V_60 * V_61 = F_30 ( V_59 , struct V_60 , V_28 ) ;
V_17 -> V_20 = V_61 -> V_20 ;
}
}
int F_33 ( struct V_17 * V_17 )
{
const char * V_62 = V_17 -> V_22 -> V_63 ;
int V_64 ;
if ( F_34 ( V_17 -> V_22 , V_17 -> type ) )
return 0 ;
V_64 = F_35 ( V_17 -> V_22 , V_17 ) ;
if ( V_64 < 0 ) {
if ( V_17 -> V_22 -> V_65 ) {
char V_66 [ V_67 ] ;
F_36 ( V_17 -> V_22 -> V_68 ,
sizeof( V_17 -> V_22 -> V_68 ) ,
V_66 ) ;
F_37 ( L_21 ,
V_62 , V_66 ) ;
} else
F_37 ( L_22 , V_62 ) ;
F_37 ( L_23 ) ;
return - 1 ;
} else if ( V_64 == 0 ) {
#ifdef F_38
const T_2 V_33 = strlen ( V_62 ) ;
const T_2 V_69 = V_33 - sizeof( V_70 ) ;
if ( V_33 > sizeof( V_70 ) &&
strcmp ( V_62 + V_69 + 1 , V_70 ) == 0 ) {
F_37 ( L_24
L_25 ,
( int ) V_69 , V_62 ) ;
} else {
F_37 ( L_26
L_27 , V_62 ) ;
}
#endif
return - 1 ;
}
return 0 ;
}
struct V_60 * F_39 ( struct V_17 * V_17 , T_3 V_71 )
{
if ( F_33 ( V_17 ) < 0 )
return NULL ;
return F_40 ( V_17 -> V_22 , V_17 -> type , V_71 ) ;
}
struct V_60 * F_41 ( struct V_17 * V_17 , const char * V_62 )
{
if ( F_33 ( V_17 ) < 0 )
return NULL ;
if ( ! F_42 ( V_17 -> V_22 , V_17 -> type ) )
F_43 ( V_17 -> V_22 , V_17 -> type ) ;
return F_44 ( V_17 -> V_22 , V_17 -> type , V_62 ) ;
}
struct V_17 * F_45 ( struct V_17 * V_72 )
{
struct V_17 * V_17 = F_46 ( V_72 , sizeof( * V_17 ) ) ;
if ( V_17 != NULL ) {
F_8 ( & V_17 -> V_31 , 1 ) ;
F_7 ( & V_17 -> V_28 ) ;
F_6 ( V_17 -> V_22 ) ;
V_17 -> V_29 = NULL ;
}
return V_17 ;
}
int F_47 ( struct V_17 * V_73 , struct V_17 * V_74 )
{
if ( V_73 -> V_19 > V_74 -> V_19 ) {
struct V_17 * V_75 = V_73 ;
V_73 = V_74 ;
V_74 = V_75 ;
}
if ( V_73 -> V_20 > V_74 -> V_19 )
return 1 ;
return 0 ;
}
T_2 F_48 ( struct V_17 * V_17 , T_4 * V_76 )
{
return fprintf ( V_76 , L_28 V_77 L_29 V_77 L_28 V_77 L_30 ,
V_17 -> V_19 , V_17 -> V_20 , V_17 -> V_21 , V_17 -> V_22 -> V_62 ) ;
}
T_2 F_49 ( struct V_17 * V_17 , T_4 * V_76 )
{
const char * V_78 = L_31 ;
if ( V_17 && V_17 -> V_22 ) {
if ( V_79 . V_80 && V_17 -> V_22 -> V_63 )
V_78 = V_17 -> V_22 -> V_63 ;
else
V_78 = V_17 -> V_22 -> V_62 ;
}
return fprintf ( V_76 , L_32 , V_78 ) ;
}
int F_50 ( struct V_17 * V_17 , T_3 V_71 , const char * V_81 ,
T_4 * V_76 )
{
char * V_82 ;
int V_83 = 0 ;
if ( V_17 && V_17 -> V_22 ) {
V_82 = F_51 ( V_17 -> V_22 ,
F_52 ( V_17 , V_71 ) , NULL ,
true , true ) ;
if ( V_82 != V_84 )
V_83 = fprintf ( V_76 , L_33 , V_81 , V_82 ) ;
F_53 ( V_82 ) ;
}
return V_83 ;
}
T_3 F_52 ( struct V_17 * V_17 , T_3 V_85 )
{
if ( ! V_17 -> V_22 -> V_86 )
return V_85 ;
if ( V_17 -> V_22 -> V_87 )
return V_85 - V_17 -> V_21 ;
if ( V_17 -> V_22 -> V_55 == V_88 )
return V_85 + V_17 -> V_22 -> V_89 ;
return V_17 -> V_26 ( V_17 , V_85 ) - V_17 -> V_23 ;
}
T_3 F_54 ( struct V_17 * V_17 , T_3 V_90 )
{
if ( ! V_17 -> V_22 -> V_86 )
return V_17 -> V_26 ( V_17 , V_90 ) ;
if ( V_17 -> V_22 -> V_87 )
return V_17 -> V_26 ( V_17 , V_90 + V_17 -> V_21 ) ;
if ( V_17 -> V_22 -> V_55 == V_88 )
return V_17 -> V_26 ( V_17 , V_90 - V_17 -> V_22 -> V_89 ) ;
return V_90 + V_17 -> V_23 ;
}
static void F_55 ( struct V_91 * V_91 )
{
V_91 -> V_92 = V_93 ;
F_56 ( & V_91 -> V_94 , NULL ) ;
}
void F_57 ( struct V_95 * V_96 , struct V_32 * V_32 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 ) {
F_55 ( & V_96 -> V_91 [ V_97 ] ) ;
}
V_96 -> V_32 = V_32 ;
F_8 ( & V_96 -> V_31 , 1 ) ;
}
static void F_58 ( struct V_91 * V_91 )
{
struct V_57 * V_99 = & V_91 -> V_92 ;
struct V_28 * V_100 = F_29 ( V_99 ) ;
while ( V_100 ) {
struct V_17 * V_101 = F_30 ( V_100 , struct V_17 , V_28 ) ;
V_100 = F_59 ( & V_101 -> V_28 ) ;
F_60 ( & V_101 -> V_28 , V_99 ) ;
F_26 ( V_101 ) ;
}
}
static void F_61 ( struct V_91 * V_91 )
{
F_62 ( & V_91 -> V_94 ) ;
F_58 ( V_91 ) ;
F_63 ( & V_91 -> V_94 ) ;
}
void F_64 ( struct V_95 * V_96 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 )
F_61 ( & V_96 -> V_91 [ V_97 ] ) ;
}
bool F_65 ( struct V_95 * V_96 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 ) {
if ( F_66 ( & V_96 -> V_91 [ V_97 ] ) )
return false ;
}
return true ;
}
struct V_95 * F_67 ( struct V_32 * V_32 )
{
struct V_95 * V_96 = malloc ( sizeof( * V_96 ) ) ;
if ( V_96 != NULL )
F_57 ( V_96 , V_32 ) ;
return V_96 ;
}
void F_68 ( struct V_95 * V_96 )
{
F_64 ( V_96 ) ;
free ( V_96 ) ;
}
void F_69 ( struct V_95 * V_96 )
{
if ( V_96 && F_27 ( & V_96 -> V_31 ) )
F_68 ( V_96 ) ;
}
struct V_60 * F_70 ( struct V_95 * V_96 ,
enum V_18 type , T_3 V_71 ,
struct V_17 * * V_102 )
{
struct V_17 * V_17 = F_71 ( V_96 , type , V_71 ) ;
if ( V_17 != NULL && F_33 ( V_17 ) >= 0 ) {
if ( V_102 != NULL )
* V_102 = V_17 ;
return F_39 ( V_17 , V_17 -> V_24 ( V_17 , V_71 ) ) ;
}
return NULL ;
}
struct V_60 * F_72 ( struct V_91 * V_91 , const char * V_62 ,
struct V_17 * * V_102 )
{
struct V_60 * V_61 ;
struct V_28 * V_59 ;
F_73 ( & V_91 -> V_94 ) ;
for ( V_59 = F_29 ( & V_91 -> V_92 ) ; V_59 ; V_59 = F_59 ( V_59 ) ) {
struct V_17 * V_101 = F_30 ( V_59 , struct V_17 , V_28 ) ;
V_61 = F_41 ( V_101 , V_62 ) ;
if ( V_61 == NULL )
continue;
if ( V_102 != NULL )
* V_102 = V_101 ;
goto V_103;
}
V_61 = NULL ;
V_103:
F_63 ( & V_91 -> V_94 ) ;
return V_61 ;
}
struct V_60 * F_74 ( struct V_95 * V_96 ,
enum V_18 type ,
const char * V_62 ,
struct V_17 * * V_102 )
{
struct V_60 * V_61 = F_72 ( & V_96 -> V_91 [ type ] , V_62 , V_102 ) ;
return V_61 ;
}
int F_75 ( struct V_104 * V_105 )
{
if ( V_105 -> V_71 < V_105 -> V_17 -> V_19 || V_105 -> V_71 >= V_105 -> V_17 -> V_20 ) {
if ( V_105 -> V_17 -> V_29 == NULL )
return - 1 ;
V_105 -> V_17 = F_71 ( V_105 -> V_17 -> V_29 , V_105 -> V_17 -> type ,
V_105 -> V_71 ) ;
if ( V_105 -> V_17 == NULL )
return - 1 ;
}
V_105 -> V_106 = V_105 -> V_17 -> V_24 ( V_105 -> V_17 , V_105 -> V_71 ) ;
V_105 -> V_61 = F_39 ( V_105 -> V_17 , V_105 -> V_106 ) ;
return V_105 -> V_61 ? 0 : - 1 ;
}
static T_2 F_76 ( struct V_91 * V_91 , T_4 * V_76 )
{
T_2 V_107 = 0 ;
struct V_28 * V_59 ;
F_73 ( & V_91 -> V_94 ) ;
for ( V_59 = F_29 ( & V_91 -> V_92 ) ; V_59 ; V_59 = F_59 ( V_59 ) ) {
struct V_17 * V_101 = F_30 ( V_59 , struct V_17 , V_28 ) ;
V_107 += fprintf ( V_76 , L_34 ) ;
V_107 += F_48 ( V_101 , V_76 ) ;
if ( V_108 > 2 ) {
V_107 += F_77 ( V_101 -> V_22 , V_101 -> type , V_76 ) ;
V_107 += fprintf ( V_76 , L_35 ) ;
}
}
F_63 ( & V_91 -> V_94 ) ;
return V_107 ;
}
T_2 F_78 ( struct V_95 * V_96 , enum V_18 type ,
T_4 * V_76 )
{
T_2 V_107 = fprintf ( V_76 , L_36 , V_109 [ type ] ) ;
return V_107 += F_76 ( & V_96 -> V_91 [ type ] , V_76 ) ;
}
T_2 F_79 ( struct V_95 * V_96 , T_4 * V_76 )
{
T_2 V_107 = 0 , V_97 ;
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 )
V_107 += F_78 ( V_96 , V_97 , V_76 ) ;
return V_107 ;
}
static void F_80 ( struct V_95 * V_96 , struct V_17 * V_17 )
{
F_81 ( & V_96 -> V_91 [ V_17 -> type ] , V_17 ) ;
V_17 -> V_29 = V_96 ;
}
static int F_82 ( struct V_91 * V_91 , struct V_17 * V_17 , T_4 * V_76 )
{
struct V_57 * V_99 ;
struct V_28 * V_100 ;
int V_110 = 0 ;
F_62 ( & V_91 -> V_94 ) ;
V_99 = & V_91 -> V_92 ;
V_100 = F_29 ( V_99 ) ;
while ( V_100 ) {
struct V_17 * V_101 = F_30 ( V_100 , struct V_17 , V_28 ) ;
V_100 = F_59 ( & V_101 -> V_28 ) ;
if ( ! F_47 ( V_101 , V_17 ) )
continue;
if ( V_108 >= 2 ) {
if ( V_111 ) {
F_37 ( L_37
L_38 ,
V_17 -> V_22 -> V_62 ) ;
} else {
fputs ( L_39 , V_76 ) ;
F_48 ( V_17 , V_76 ) ;
F_48 ( V_101 , V_76 ) ;
}
}
F_60 ( & V_101 -> V_28 , V_99 ) ;
if ( V_17 -> V_19 > V_101 -> V_19 ) {
struct V_17 * V_112 = F_45 ( V_101 ) ;
if ( V_112 == NULL ) {
V_110 = - V_113 ;
goto V_114;
}
V_112 -> V_20 = V_17 -> V_19 ;
F_80 ( V_101 -> V_29 , V_112 ) ;
if ( V_108 >= 2 && ! V_111 )
F_48 ( V_112 , V_76 ) ;
F_26 ( V_112 ) ;
}
if ( V_17 -> V_20 < V_101 -> V_20 ) {
struct V_17 * V_115 = F_45 ( V_101 ) ;
if ( V_115 == NULL ) {
V_110 = - V_113 ;
goto V_114;
}
V_115 -> V_19 = V_17 -> V_20 ;
F_80 ( V_101 -> V_29 , V_115 ) ;
if ( V_108 >= 2 && ! V_111 )
F_48 ( V_115 , V_76 ) ;
F_26 ( V_115 ) ;
}
V_114:
F_26 ( V_101 ) ;
if ( V_110 )
goto V_103;
}
V_110 = 0 ;
V_103:
F_63 ( & V_91 -> V_94 ) ;
return V_110 ;
}
int F_83 ( struct V_95 * V_96 , struct V_17 * V_17 ,
T_4 * V_76 )
{
return F_82 ( & V_96 -> V_91 [ V_17 -> type ] , V_17 , V_76 ) ;
}
int F_84 ( struct V_39 * V_39 ,
struct V_95 * V_116 , enum V_18 type )
{
struct V_95 * V_96 = V_39 -> V_96 ;
int V_110 = - V_113 ;
struct V_17 * V_17 ;
struct V_91 * V_91 = & V_116 -> V_91 [ type ] ;
F_73 ( & V_91 -> V_94 ) ;
for ( V_17 = F_66 ( V_91 ) ; V_17 ; V_17 = F_85 ( V_17 ) ) {
struct V_17 * V_117 = F_45 ( V_17 ) ;
if ( V_117 == NULL )
goto V_118;
V_110 = F_86 ( V_39 , V_117 , NULL ) ;
if ( V_110 )
goto V_118;
F_87 ( V_96 , V_117 ) ;
F_26 ( V_117 ) ;
}
V_110 = 0 ;
V_118:
F_63 ( & V_91 -> V_94 ) ;
return V_110 ;
}
static void F_81 ( struct V_91 * V_91 , struct V_17 * V_17 )
{
struct V_28 * * V_119 = & V_91 -> V_92 . V_28 ;
struct V_28 * V_116 = NULL ;
const T_3 V_90 = V_17 -> V_19 ;
struct V_17 * V_120 ;
while ( * V_119 != NULL ) {
V_116 = * V_119 ;
V_120 = F_30 ( V_116 , struct V_17 , V_28 ) ;
if ( V_90 < V_120 -> V_19 )
V_119 = & ( * V_119 ) -> V_121 ;
else
V_119 = & ( * V_119 ) -> V_122 ;
}
F_88 ( & V_17 -> V_28 , V_116 , V_119 ) ;
F_89 ( & V_17 -> V_28 , & V_91 -> V_92 ) ;
F_90 ( V_17 ) ;
}
void F_91 ( struct V_91 * V_91 , struct V_17 * V_17 )
{
F_62 ( & V_91 -> V_94 ) ;
F_81 ( V_91 , V_17 ) ;
F_63 ( & V_91 -> V_94 ) ;
}
static void F_92 ( struct V_91 * V_91 , struct V_17 * V_17 )
{
F_60 ( & V_17 -> V_28 , & V_91 -> V_92 ) ;
F_26 ( V_17 ) ;
}
void F_93 ( struct V_91 * V_91 , struct V_17 * V_17 )
{
F_62 ( & V_91 -> V_94 ) ;
F_92 ( V_91 , V_17 ) ;
F_63 ( & V_91 -> V_94 ) ;
}
struct V_17 * F_94 ( struct V_91 * V_91 , T_3 V_90 )
{
struct V_28 * * V_119 , * V_116 = NULL ;
struct V_17 * V_120 ;
F_73 ( & V_91 -> V_94 ) ;
V_119 = & V_91 -> V_92 . V_28 ;
while ( * V_119 != NULL ) {
V_116 = * V_119 ;
V_120 = F_30 ( V_116 , struct V_17 , V_28 ) ;
if ( V_90 < V_120 -> V_19 )
V_119 = & ( * V_119 ) -> V_121 ;
else if ( V_90 >= V_120 -> V_20 )
V_119 = & ( * V_119 ) -> V_122 ;
else
goto V_103;
}
V_120 = NULL ;
V_103:
F_63 ( & V_91 -> V_94 ) ;
return V_120 ;
}
struct V_17 * F_66 ( struct V_91 * V_91 )
{
struct V_28 * V_123 = F_29 ( & V_91 -> V_92 ) ;
if ( V_123 )
return F_30 ( V_123 , struct V_17 , V_28 ) ;
return NULL ;
}
struct V_17 * F_85 ( struct V_17 * V_17 )
{
struct V_28 * V_100 = F_59 ( & V_17 -> V_28 ) ;
if ( V_100 )
return F_30 ( V_100 , struct V_17 , V_28 ) ;
return NULL ;
}
struct V_56 * F_95 ( struct V_17 * V_17 )
{
if ( ! V_17 -> V_22 || ! V_17 -> V_22 -> V_55 ) {
F_96 ( L_40 ) ;
return NULL ;
}
return (struct V_56 * ) ( V_17 + 1 ) ;
}
struct V_95 * F_97 ( struct V_17 * V_17 )
{
struct V_56 * V_56 = F_95 ( V_17 ) ;
if ( ! V_56 || ! V_56 -> V_124 ) {
F_96 ( L_41 ) ;
return NULL ;
}
return V_56 -> V_124 ;
}
