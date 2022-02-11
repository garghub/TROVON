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
T_3 V_21 , T_1 V_34 , T_1 V_35 , T_1 V_36 , T_3 V_37 ,
T_3 V_38 , T_1 V_39 , T_1 V_2 , char * V_1 ,
enum V_18 type , struct V_40 * V_40 )
{
struct V_17 * V_17 = malloc ( sizeof( * V_17 ) ) ;
if ( V_17 != NULL ) {
char V_4 [ V_11 ] ;
struct V_22 * V_22 ;
int V_41 , V_42 , V_43 , V_44 ;
V_44 = F_3 ( V_1 ) ;
V_41 = F_1 ( V_1 , V_2 ) ;
V_43 = F_10 ( V_1 ) ;
V_42 = F_2 ( V_1 ) ;
V_17 -> V_45 = V_35 ;
V_17 -> V_46 = V_36 ;
V_17 -> V_37 = V_37 ;
V_17 -> V_47 = V_38 ;
V_17 -> V_39 = V_39 ;
V_17 -> V_2 = V_2 ;
if ( ( V_41 || V_42 ) && type == V_48 ) {
snprintf ( V_4 , sizeof( V_4 ) , L_20 , V_34 ) ;
V_1 = V_4 ;
}
if ( V_44 ) {
if ( F_4 ( V_1 , V_4 ) )
V_1 = V_4 ;
}
if ( V_43 ) {
V_21 = 0 ;
V_22 = F_11 ( V_32 , V_40 ) ;
} else
V_22 = F_12 ( V_32 , V_1 ) ;
if ( V_22 == NULL )
goto V_49;
F_5 ( V_17 , type , V_19 , V_19 + V_33 , V_21 , V_22 ) ;
if ( V_41 || V_42 ) {
V_17 -> V_24 = V_17 -> V_26 = V_50 ;
if ( type != V_48 )
F_13 ( V_22 , V_17 -> type ) ;
}
F_14 ( V_22 ) ;
}
return V_17 ;
V_49:
free ( V_17 ) ;
return NULL ;
}
struct V_17 * F_15 ( T_3 V_19 , struct V_22 * V_22 , enum V_18 type )
{
struct V_17 * V_17 = calloc ( 1 , ( sizeof( * V_17 ) +
( V_22 -> V_51 ? sizeof( struct V_52 ) : 0 ) ) ) ;
if ( V_17 != NULL ) {
F_5 ( V_17 , type , V_19 , 0 , 0 , V_22 ) ;
}
return V_17 ;
}
bool F_16 ( const struct V_17 * V_17 )
{
return F_17 ( V_17 -> V_29 -> V_32 , V_17 -> type ) == V_17 ;
}
static void F_18 ( struct V_17 * V_17 )
{
F_19 ( ! F_20 ( & V_17 -> V_28 ) ) ;
F_21 ( V_17 -> V_22 ) ;
}
void F_22 ( struct V_17 * V_17 )
{
F_18 ( V_17 ) ;
free ( V_17 ) ;
}
void F_23 ( struct V_17 * V_17 )
{
if ( V_17 && F_24 ( & V_17 -> V_31 ) )
F_22 ( V_17 ) ;
}
void F_25 ( struct V_17 * V_17 )
{
struct V_53 * V_54 = & V_17 -> V_22 -> V_54 [ V_17 -> type ] ;
struct V_28 * V_55 = F_26 ( V_54 ) ;
if ( V_55 != NULL ) {
struct V_56 * V_57 = F_27 ( V_55 , struct V_56 , V_28 ) ;
V_17 -> V_19 = V_57 -> V_19 ;
}
}
void F_28 ( struct V_17 * V_17 )
{
struct V_53 * V_54 = & V_17 -> V_22 -> V_54 [ V_17 -> type ] ;
struct V_28 * V_55 = F_29 ( V_54 ) ;
if ( V_55 != NULL ) {
struct V_56 * V_57 = F_27 ( V_55 , struct V_56 , V_28 ) ;
V_17 -> V_20 = V_57 -> V_20 ;
}
}
int F_30 ( struct V_17 * V_17 )
{
const char * V_58 = V_17 -> V_22 -> V_59 ;
int V_60 ;
if ( F_31 ( V_17 -> V_22 , V_17 -> type ) )
return 0 ;
V_60 = F_32 ( V_17 -> V_22 , V_17 ) ;
if ( V_60 < 0 ) {
if ( V_17 -> V_22 -> V_61 ) {
char V_62 [ V_63 ] ;
F_33 ( V_17 -> V_22 -> V_64 ,
sizeof( V_17 -> V_22 -> V_64 ) ,
V_62 ) ;
F_34 ( L_21 ,
V_58 , V_62 ) ;
} else
F_34 ( L_22 , V_58 ) ;
F_34 ( L_23 ) ;
return - 1 ;
} else if ( V_60 == 0 ) {
#ifdef F_35
const T_2 V_33 = strlen ( V_58 ) ;
const T_2 V_65 = V_33 - sizeof( V_66 ) ;
if ( V_33 > sizeof( V_66 ) &&
strcmp ( V_58 + V_65 + 1 , V_66 ) == 0 ) {
F_34 ( L_24
L_25 ,
( int ) V_65 , V_58 ) ;
} else {
F_34 ( L_26
L_27 , V_58 ) ;
}
#endif
return - 1 ;
}
return 0 ;
}
int __weak F_36 ( const char * V_67 , const char * V_68 )
{
return strcmp ( V_67 , V_68 ) ;
}
struct V_56 * F_37 ( struct V_17 * V_17 , T_3 V_69 )
{
if ( F_30 ( V_17 ) < 0 )
return NULL ;
return F_38 ( V_17 -> V_22 , V_17 -> type , V_69 ) ;
}
struct V_56 * F_39 ( struct V_17 * V_17 , const char * V_58 )
{
if ( F_30 ( V_17 ) < 0 )
return NULL ;
if ( ! F_40 ( V_17 -> V_22 , V_17 -> type ) )
F_41 ( V_17 -> V_22 , V_17 -> type ) ;
return F_42 ( V_17 -> V_22 , V_17 -> type , V_58 ) ;
}
struct V_17 * F_43 ( struct V_17 * V_70 )
{
struct V_17 * V_17 = F_44 ( V_70 , sizeof( * V_17 ) ) ;
if ( V_17 != NULL ) {
F_8 ( & V_17 -> V_31 , 1 ) ;
F_7 ( & V_17 -> V_28 ) ;
F_6 ( V_17 -> V_22 ) ;
V_17 -> V_29 = NULL ;
}
return V_17 ;
}
int F_45 ( struct V_17 * V_71 , struct V_17 * V_72 )
{
if ( V_71 -> V_19 > V_72 -> V_19 ) {
struct V_17 * V_73 = V_71 ;
V_71 = V_72 ;
V_72 = V_73 ;
}
if ( V_71 -> V_20 > V_72 -> V_19 )
return 1 ;
return 0 ;
}
T_2 F_46 ( struct V_17 * V_17 , T_4 * V_74 )
{
return fprintf ( V_74 , L_28 V_75 L_29 V_75 L_28 V_75 L_30 ,
V_17 -> V_19 , V_17 -> V_20 , V_17 -> V_21 , V_17 -> V_22 -> V_58 ) ;
}
T_2 F_47 ( struct V_17 * V_17 , T_4 * V_74 )
{
const char * V_76 = L_31 ;
if ( V_17 && V_17 -> V_22 ) {
if ( V_77 . V_78 && V_17 -> V_22 -> V_59 )
V_76 = V_17 -> V_22 -> V_59 ;
else
V_76 = V_17 -> V_22 -> V_58 ;
}
return fprintf ( V_74 , L_32 , V_76 ) ;
}
int F_48 ( struct V_17 * V_17 , T_3 V_69 , const char * V_79 ,
T_4 * V_74 )
{
char * V_80 ;
int V_81 = 0 ;
if ( V_17 && V_17 -> V_22 ) {
V_80 = F_49 ( V_17 -> V_22 ,
F_50 ( V_17 , V_69 ) , NULL , true ) ;
if ( V_80 != V_82 )
V_81 = fprintf ( V_74 , L_33 , V_79 , V_80 ) ;
F_51 ( V_80 ) ;
}
return V_81 ;
}
T_3 F_50 ( struct V_17 * V_17 , T_3 V_83 )
{
if ( ! V_17 -> V_22 -> V_84 )
return V_83 ;
if ( V_17 -> V_22 -> V_85 )
return V_83 - V_17 -> V_21 ;
if ( V_17 -> V_22 -> V_51 == V_86 )
return V_83 + V_17 -> V_22 -> V_87 ;
return V_17 -> V_26 ( V_17 , V_83 ) - V_17 -> V_23 ;
}
T_3 F_52 ( struct V_17 * V_17 , T_3 V_88 )
{
if ( ! V_17 -> V_22 -> V_84 )
return V_17 -> V_26 ( V_17 , V_88 ) ;
if ( V_17 -> V_22 -> V_85 )
return V_17 -> V_26 ( V_17 , V_88 + V_17 -> V_21 ) ;
if ( V_17 -> V_22 -> V_51 == V_86 )
return V_17 -> V_26 ( V_17 , V_88 - V_17 -> V_22 -> V_87 ) ;
return V_88 + V_17 -> V_23 ;
}
static void F_53 ( struct V_89 * V_89 )
{
V_89 -> V_90 = V_91 ;
F_54 ( & V_89 -> V_92 , NULL ) ;
}
void F_55 ( struct V_93 * V_94 , struct V_32 * V_32 )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < V_96 ; ++ V_95 ) {
F_53 ( & V_94 -> V_89 [ V_95 ] ) ;
}
V_94 -> V_32 = V_32 ;
F_8 ( & V_94 -> V_31 , 1 ) ;
}
static void F_56 ( struct V_89 * V_89 )
{
struct V_53 * V_97 = & V_89 -> V_90 ;
struct V_28 * V_98 = F_26 ( V_97 ) ;
while ( V_98 ) {
struct V_17 * V_99 = F_27 ( V_98 , struct V_17 , V_28 ) ;
V_98 = F_57 ( & V_99 -> V_28 ) ;
F_58 ( & V_99 -> V_28 , V_97 ) ;
F_23 ( V_99 ) ;
}
}
static void F_59 ( struct V_89 * V_89 )
{
F_60 ( & V_89 -> V_92 ) ;
F_56 ( V_89 ) ;
F_61 ( & V_89 -> V_92 ) ;
}
void F_62 ( struct V_93 * V_94 )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < V_96 ; ++ V_95 )
F_59 ( & V_94 -> V_89 [ V_95 ] ) ;
}
bool F_63 ( struct V_93 * V_94 )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < V_96 ; ++ V_95 ) {
if ( F_64 ( & V_94 -> V_89 [ V_95 ] ) )
return false ;
}
return true ;
}
struct V_93 * F_65 ( struct V_32 * V_32 )
{
struct V_93 * V_94 = malloc ( sizeof( * V_94 ) ) ;
if ( V_94 != NULL )
F_55 ( V_94 , V_32 ) ;
return V_94 ;
}
void F_66 ( struct V_93 * V_94 )
{
F_62 ( V_94 ) ;
free ( V_94 ) ;
}
void F_67 ( struct V_93 * V_94 )
{
if ( V_94 && F_24 ( & V_94 -> V_31 ) )
F_66 ( V_94 ) ;
}
struct V_56 * F_68 ( struct V_93 * V_94 ,
enum V_18 type , T_3 V_69 ,
struct V_17 * * V_100 )
{
struct V_17 * V_17 = F_69 ( V_94 , type , V_69 ) ;
if ( V_17 != NULL && F_30 ( V_17 ) >= 0 ) {
if ( V_100 != NULL )
* V_100 = V_17 ;
return F_37 ( V_17 , V_17 -> V_24 ( V_17 , V_69 ) ) ;
}
return NULL ;
}
struct V_56 * F_70 ( struct V_89 * V_89 , const char * V_58 ,
struct V_17 * * V_100 )
{
struct V_56 * V_57 ;
struct V_28 * V_55 ;
F_71 ( & V_89 -> V_92 ) ;
for ( V_55 = F_26 ( & V_89 -> V_90 ) ; V_55 ; V_55 = F_57 ( V_55 ) ) {
struct V_17 * V_99 = F_27 ( V_55 , struct V_17 , V_28 ) ;
V_57 = F_39 ( V_99 , V_58 ) ;
if ( V_57 == NULL )
continue;
if ( V_100 != NULL )
* V_100 = V_99 ;
goto V_101;
}
V_57 = NULL ;
V_101:
F_61 ( & V_89 -> V_92 ) ;
return V_57 ;
}
struct V_56 * F_72 ( struct V_93 * V_94 ,
enum V_18 type ,
const char * V_58 ,
struct V_17 * * V_100 )
{
struct V_56 * V_57 = F_70 ( & V_94 -> V_89 [ type ] , V_58 , V_100 ) ;
return V_57 ;
}
int F_73 ( struct V_102 * V_103 )
{
if ( V_103 -> V_69 < V_103 -> V_17 -> V_19 || V_103 -> V_69 >= V_103 -> V_17 -> V_20 ) {
if ( V_103 -> V_17 -> V_29 == NULL )
return - 1 ;
V_103 -> V_17 = F_69 ( V_103 -> V_17 -> V_29 , V_103 -> V_17 -> type ,
V_103 -> V_69 ) ;
if ( V_103 -> V_17 == NULL )
return - 1 ;
}
V_103 -> V_104 = V_103 -> V_17 -> V_24 ( V_103 -> V_17 , V_103 -> V_69 ) ;
V_103 -> V_57 = F_37 ( V_103 -> V_17 , V_103 -> V_104 ) ;
return V_103 -> V_57 ? 0 : - 1 ;
}
static T_2 F_74 ( struct V_89 * V_89 , T_4 * V_74 )
{
T_2 V_105 = 0 ;
struct V_28 * V_55 ;
F_71 ( & V_89 -> V_92 ) ;
for ( V_55 = F_26 ( & V_89 -> V_90 ) ; V_55 ; V_55 = F_57 ( V_55 ) ) {
struct V_17 * V_99 = F_27 ( V_55 , struct V_17 , V_28 ) ;
V_105 += fprintf ( V_74 , L_34 ) ;
V_105 += F_46 ( V_99 , V_74 ) ;
if ( V_106 > 2 ) {
V_105 += F_75 ( V_99 -> V_22 , V_99 -> type , V_74 ) ;
V_105 += fprintf ( V_74 , L_35 ) ;
}
}
F_61 ( & V_89 -> V_92 ) ;
return V_105 ;
}
T_2 F_76 ( struct V_93 * V_94 , enum V_18 type ,
T_4 * V_74 )
{
T_2 V_105 = fprintf ( V_74 , L_36 , V_107 [ type ] ) ;
return V_105 += F_74 ( & V_94 -> V_89 [ type ] , V_74 ) ;
}
T_2 F_77 ( struct V_93 * V_94 , T_4 * V_74 )
{
T_2 V_105 = 0 , V_95 ;
for ( V_95 = 0 ; V_95 < V_96 ; ++ V_95 )
V_105 += F_76 ( V_94 , V_95 , V_74 ) ;
return V_105 ;
}
static void F_78 ( struct V_93 * V_94 , struct V_17 * V_17 )
{
F_79 ( & V_94 -> V_89 [ V_17 -> type ] , V_17 ) ;
V_17 -> V_29 = V_94 ;
}
static int F_80 ( struct V_89 * V_89 , struct V_17 * V_17 , T_4 * V_74 )
{
struct V_53 * V_97 ;
struct V_28 * V_98 ;
int V_108 = 0 ;
F_60 ( & V_89 -> V_92 ) ;
V_97 = & V_89 -> V_90 ;
V_98 = F_26 ( V_97 ) ;
while ( V_98 ) {
struct V_17 * V_99 = F_27 ( V_98 , struct V_17 , V_28 ) ;
V_98 = F_57 ( & V_99 -> V_28 ) ;
if ( ! F_45 ( V_99 , V_17 ) )
continue;
if ( V_106 >= 2 ) {
if ( V_109 ) {
F_34 ( L_37
L_38 ,
V_17 -> V_22 -> V_58 ) ;
} else {
fputs ( L_39 , V_74 ) ;
F_46 ( V_17 , V_74 ) ;
F_46 ( V_99 , V_74 ) ;
}
}
F_58 ( & V_99 -> V_28 , V_97 ) ;
if ( V_17 -> V_19 > V_99 -> V_19 ) {
struct V_17 * V_110 = F_43 ( V_99 ) ;
if ( V_110 == NULL ) {
V_108 = - V_111 ;
goto V_112;
}
V_110 -> V_20 = V_17 -> V_19 ;
F_78 ( V_99 -> V_29 , V_110 ) ;
if ( V_106 >= 2 && ! V_109 )
F_46 ( V_110 , V_74 ) ;
F_23 ( V_110 ) ;
}
if ( V_17 -> V_20 < V_99 -> V_20 ) {
struct V_17 * V_113 = F_43 ( V_99 ) ;
if ( V_113 == NULL ) {
V_108 = - V_111 ;
goto V_112;
}
V_113 -> V_19 = V_17 -> V_20 ;
F_78 ( V_99 -> V_29 , V_113 ) ;
if ( V_106 >= 2 && ! V_109 )
F_46 ( V_113 , V_74 ) ;
F_23 ( V_113 ) ;
}
V_112:
F_23 ( V_99 ) ;
if ( V_108 )
goto V_101;
}
V_108 = 0 ;
V_101:
F_61 ( & V_89 -> V_92 ) ;
return V_108 ;
}
int F_81 ( struct V_93 * V_94 , struct V_17 * V_17 ,
T_4 * V_74 )
{
return F_80 ( & V_94 -> V_89 [ V_17 -> type ] , V_17 , V_74 ) ;
}
int F_82 ( struct V_40 * V_40 ,
struct V_93 * V_114 , enum V_18 type )
{
struct V_93 * V_94 = V_40 -> V_94 ;
int V_108 = - V_111 ;
struct V_17 * V_17 ;
struct V_89 * V_89 = & V_114 -> V_89 [ type ] ;
F_71 ( & V_89 -> V_92 ) ;
for ( V_17 = F_64 ( V_89 ) ; V_17 ; V_17 = F_83 ( V_17 ) ) {
struct V_17 * V_115 = F_43 ( V_17 ) ;
if ( V_115 == NULL )
goto V_116;
V_108 = F_84 ( V_40 , V_115 , NULL ) ;
if ( V_108 )
goto V_116;
F_85 ( V_94 , V_115 ) ;
F_23 ( V_115 ) ;
}
V_108 = 0 ;
V_116:
F_61 ( & V_89 -> V_92 ) ;
return V_108 ;
}
static void F_79 ( struct V_89 * V_89 , struct V_17 * V_17 )
{
struct V_28 * * V_117 = & V_89 -> V_90 . V_28 ;
struct V_28 * V_114 = NULL ;
const T_3 V_88 = V_17 -> V_19 ;
struct V_17 * V_118 ;
while ( * V_117 != NULL ) {
V_114 = * V_117 ;
V_118 = F_27 ( V_114 , struct V_17 , V_28 ) ;
if ( V_88 < V_118 -> V_19 )
V_117 = & ( * V_117 ) -> V_119 ;
else
V_117 = & ( * V_117 ) -> V_120 ;
}
F_86 ( & V_17 -> V_28 , V_114 , V_117 ) ;
F_87 ( & V_17 -> V_28 , & V_89 -> V_90 ) ;
F_88 ( V_17 ) ;
}
void F_89 ( struct V_89 * V_89 , struct V_17 * V_17 )
{
F_60 ( & V_89 -> V_92 ) ;
F_79 ( V_89 , V_17 ) ;
F_61 ( & V_89 -> V_92 ) ;
}
static void F_90 ( struct V_89 * V_89 , struct V_17 * V_17 )
{
F_58 ( & V_17 -> V_28 , & V_89 -> V_90 ) ;
F_23 ( V_17 ) ;
}
void F_91 ( struct V_89 * V_89 , struct V_17 * V_17 )
{
F_60 ( & V_89 -> V_92 ) ;
F_90 ( V_89 , V_17 ) ;
F_61 ( & V_89 -> V_92 ) ;
}
struct V_17 * F_92 ( struct V_89 * V_89 , T_3 V_88 )
{
struct V_28 * * V_117 , * V_114 = NULL ;
struct V_17 * V_118 ;
F_71 ( & V_89 -> V_92 ) ;
V_117 = & V_89 -> V_90 . V_28 ;
while ( * V_117 != NULL ) {
V_114 = * V_117 ;
V_118 = F_27 ( V_114 , struct V_17 , V_28 ) ;
if ( V_88 < V_118 -> V_19 )
V_117 = & ( * V_117 ) -> V_119 ;
else if ( V_88 >= V_118 -> V_20 )
V_117 = & ( * V_117 ) -> V_120 ;
else
goto V_101;
}
V_118 = NULL ;
V_101:
F_61 ( & V_89 -> V_92 ) ;
return V_118 ;
}
struct V_17 * F_64 ( struct V_89 * V_89 )
{
struct V_28 * V_121 = F_26 ( & V_89 -> V_90 ) ;
if ( V_121 )
return F_27 ( V_121 , struct V_17 , V_28 ) ;
return NULL ;
}
struct V_17 * F_83 ( struct V_17 * V_17 )
{
struct V_28 * V_98 = F_57 ( & V_17 -> V_28 ) ;
if ( V_98 )
return F_27 ( V_98 , struct V_17 , V_28 ) ;
return NULL ;
}
struct V_52 * F_93 ( struct V_17 * V_17 )
{
if ( ! V_17 -> V_22 || ! V_17 -> V_22 -> V_51 ) {
F_94 ( L_40 ) ;
return NULL ;
}
return (struct V_52 * ) ( V_17 + 1 ) ;
}
struct V_93 * F_95 ( struct V_17 * V_17 )
{
struct V_52 * V_52 = F_93 ( V_17 ) ;
if ( ! V_52 || ! V_52 -> V_122 ) {
F_94 ( L_41 ) ;
return NULL ;
}
return V_52 -> V_122 ;
}
