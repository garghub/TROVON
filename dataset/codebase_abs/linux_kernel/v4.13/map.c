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
struct V_56 * F_36 ( struct V_17 * V_17 , T_3 V_67 )
{
if ( F_30 ( V_17 ) < 0 )
return NULL ;
return F_37 ( V_17 -> V_22 , V_17 -> type , V_67 ) ;
}
struct V_56 * F_38 ( struct V_17 * V_17 , const char * V_58 )
{
if ( F_30 ( V_17 ) < 0 )
return NULL ;
if ( ! F_39 ( V_17 -> V_22 , V_17 -> type ) )
F_40 ( V_17 -> V_22 , V_17 -> type ) ;
return F_41 ( V_17 -> V_22 , V_17 -> type , V_58 ) ;
}
struct V_17 * F_42 ( struct V_17 * V_68 )
{
struct V_17 * V_17 = F_43 ( V_68 , sizeof( * V_17 ) ) ;
if ( V_17 != NULL ) {
F_8 ( & V_17 -> V_31 , 1 ) ;
F_7 ( & V_17 -> V_28 ) ;
F_6 ( V_17 -> V_22 ) ;
V_17 -> V_29 = NULL ;
}
return V_17 ;
}
int F_44 ( struct V_17 * V_69 , struct V_17 * V_70 )
{
if ( V_69 -> V_19 > V_70 -> V_19 ) {
struct V_17 * V_71 = V_69 ;
V_69 = V_70 ;
V_70 = V_71 ;
}
if ( V_69 -> V_20 > V_70 -> V_19 )
return 1 ;
return 0 ;
}
T_2 F_45 ( struct V_17 * V_17 , T_4 * V_72 )
{
return fprintf ( V_72 , L_28 V_73 L_29 V_73 L_28 V_73 L_30 ,
V_17 -> V_19 , V_17 -> V_20 , V_17 -> V_21 , V_17 -> V_22 -> V_58 ) ;
}
T_2 F_46 ( struct V_17 * V_17 , T_4 * V_72 )
{
const char * V_74 = L_31 ;
if ( V_17 && V_17 -> V_22 ) {
if ( V_75 . V_76 && V_17 -> V_22 -> V_59 )
V_74 = V_17 -> V_22 -> V_59 ;
else
V_74 = V_17 -> V_22 -> V_58 ;
}
return fprintf ( V_72 , L_32 , V_74 ) ;
}
int F_47 ( struct V_17 * V_17 , T_3 V_67 , const char * V_77 ,
T_4 * V_72 )
{
char * V_78 ;
int V_79 = 0 ;
if ( V_17 && V_17 -> V_22 ) {
V_78 = F_48 ( V_17 -> V_22 ,
F_49 ( V_17 , V_67 ) , NULL ,
true , true ) ;
if ( V_78 != V_80 )
V_79 = fprintf ( V_72 , L_33 , V_77 , V_78 ) ;
F_50 ( V_78 ) ;
}
return V_79 ;
}
T_3 F_49 ( struct V_17 * V_17 , T_3 V_81 )
{
if ( ! V_17 -> V_22 -> V_82 )
return V_81 ;
if ( V_17 -> V_22 -> V_83 )
return V_81 - V_17 -> V_21 ;
if ( V_17 -> V_22 -> V_51 == V_84 )
return V_81 + V_17 -> V_22 -> V_85 ;
return V_17 -> V_26 ( V_17 , V_81 ) - V_17 -> V_23 ;
}
T_3 F_51 ( struct V_17 * V_17 , T_3 V_86 )
{
if ( ! V_17 -> V_22 -> V_82 )
return V_17 -> V_26 ( V_17 , V_86 ) ;
if ( V_17 -> V_22 -> V_83 )
return V_17 -> V_26 ( V_17 , V_86 + V_17 -> V_21 ) ;
if ( V_17 -> V_22 -> V_51 == V_84 )
return V_17 -> V_26 ( V_17 , V_86 - V_17 -> V_22 -> V_85 ) ;
return V_86 + V_17 -> V_23 ;
}
static void F_52 ( struct V_87 * V_87 )
{
V_87 -> V_88 = V_89 ;
F_53 ( & V_87 -> V_90 , NULL ) ;
}
void F_54 ( struct V_91 * V_92 , struct V_32 * V_32 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; ++ V_93 ) {
F_52 ( & V_92 -> V_87 [ V_93 ] ) ;
}
V_92 -> V_32 = V_32 ;
F_8 ( & V_92 -> V_31 , 1 ) ;
}
static void F_55 ( struct V_87 * V_87 )
{
struct V_53 * V_95 = & V_87 -> V_88 ;
struct V_28 * V_96 = F_26 ( V_95 ) ;
while ( V_96 ) {
struct V_17 * V_97 = F_27 ( V_96 , struct V_17 , V_28 ) ;
V_96 = F_56 ( & V_97 -> V_28 ) ;
F_57 ( & V_97 -> V_28 , V_95 ) ;
F_23 ( V_97 ) ;
}
}
static void F_58 ( struct V_87 * V_87 )
{
F_59 ( & V_87 -> V_90 ) ;
F_55 ( V_87 ) ;
F_60 ( & V_87 -> V_90 ) ;
}
void F_61 ( struct V_91 * V_92 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; ++ V_93 )
F_58 ( & V_92 -> V_87 [ V_93 ] ) ;
}
bool F_62 ( struct V_91 * V_92 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; ++ V_93 ) {
if ( F_63 ( & V_92 -> V_87 [ V_93 ] ) )
return false ;
}
return true ;
}
struct V_91 * F_64 ( struct V_32 * V_32 )
{
struct V_91 * V_92 = malloc ( sizeof( * V_92 ) ) ;
if ( V_92 != NULL )
F_54 ( V_92 , V_32 ) ;
return V_92 ;
}
void F_65 ( struct V_91 * V_92 )
{
F_61 ( V_92 ) ;
free ( V_92 ) ;
}
void F_66 ( struct V_91 * V_92 )
{
if ( V_92 && F_24 ( & V_92 -> V_31 ) )
F_65 ( V_92 ) ;
}
struct V_56 * F_67 ( struct V_91 * V_92 ,
enum V_18 type , T_3 V_67 ,
struct V_17 * * V_98 )
{
struct V_17 * V_17 = F_68 ( V_92 , type , V_67 ) ;
if ( V_17 != NULL && F_30 ( V_17 ) >= 0 ) {
if ( V_98 != NULL )
* V_98 = V_17 ;
return F_36 ( V_17 , V_17 -> V_24 ( V_17 , V_67 ) ) ;
}
return NULL ;
}
struct V_56 * F_69 ( struct V_87 * V_87 , const char * V_58 ,
struct V_17 * * V_98 )
{
struct V_56 * V_57 ;
struct V_28 * V_55 ;
F_70 ( & V_87 -> V_90 ) ;
for ( V_55 = F_26 ( & V_87 -> V_88 ) ; V_55 ; V_55 = F_56 ( V_55 ) ) {
struct V_17 * V_97 = F_27 ( V_55 , struct V_17 , V_28 ) ;
V_57 = F_38 ( V_97 , V_58 ) ;
if ( V_57 == NULL )
continue;
if ( V_98 != NULL )
* V_98 = V_97 ;
goto V_99;
}
V_57 = NULL ;
V_99:
F_60 ( & V_87 -> V_90 ) ;
return V_57 ;
}
struct V_56 * F_71 ( struct V_91 * V_92 ,
enum V_18 type ,
const char * V_58 ,
struct V_17 * * V_98 )
{
struct V_56 * V_57 = F_69 ( & V_92 -> V_87 [ type ] , V_58 , V_98 ) ;
return V_57 ;
}
int F_72 ( struct V_100 * V_101 )
{
if ( V_101 -> V_67 < V_101 -> V_17 -> V_19 || V_101 -> V_67 >= V_101 -> V_17 -> V_20 ) {
if ( V_101 -> V_17 -> V_29 == NULL )
return - 1 ;
V_101 -> V_17 = F_68 ( V_101 -> V_17 -> V_29 , V_101 -> V_17 -> type ,
V_101 -> V_67 ) ;
if ( V_101 -> V_17 == NULL )
return - 1 ;
}
V_101 -> V_102 = V_101 -> V_17 -> V_24 ( V_101 -> V_17 , V_101 -> V_67 ) ;
V_101 -> V_57 = F_36 ( V_101 -> V_17 , V_101 -> V_102 ) ;
return V_101 -> V_57 ? 0 : - 1 ;
}
static T_2 F_73 ( struct V_87 * V_87 , T_4 * V_72 )
{
T_2 V_103 = 0 ;
struct V_28 * V_55 ;
F_70 ( & V_87 -> V_90 ) ;
for ( V_55 = F_26 ( & V_87 -> V_88 ) ; V_55 ; V_55 = F_56 ( V_55 ) ) {
struct V_17 * V_97 = F_27 ( V_55 , struct V_17 , V_28 ) ;
V_103 += fprintf ( V_72 , L_34 ) ;
V_103 += F_45 ( V_97 , V_72 ) ;
if ( V_104 > 2 ) {
V_103 += F_74 ( V_97 -> V_22 , V_97 -> type , V_72 ) ;
V_103 += fprintf ( V_72 , L_35 ) ;
}
}
F_60 ( & V_87 -> V_90 ) ;
return V_103 ;
}
T_2 F_75 ( struct V_91 * V_92 , enum V_18 type ,
T_4 * V_72 )
{
T_2 V_103 = fprintf ( V_72 , L_36 , V_105 [ type ] ) ;
return V_103 += F_73 ( & V_92 -> V_87 [ type ] , V_72 ) ;
}
T_2 F_76 ( struct V_91 * V_92 , T_4 * V_72 )
{
T_2 V_103 = 0 , V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; ++ V_93 )
V_103 += F_75 ( V_92 , V_93 , V_72 ) ;
return V_103 ;
}
static void F_77 ( struct V_91 * V_92 , struct V_17 * V_17 )
{
F_78 ( & V_92 -> V_87 [ V_17 -> type ] , V_17 ) ;
V_17 -> V_29 = V_92 ;
}
static int F_79 ( struct V_87 * V_87 , struct V_17 * V_17 , T_4 * V_72 )
{
struct V_53 * V_95 ;
struct V_28 * V_96 ;
int V_106 = 0 ;
F_59 ( & V_87 -> V_90 ) ;
V_95 = & V_87 -> V_88 ;
V_96 = F_26 ( V_95 ) ;
while ( V_96 ) {
struct V_17 * V_97 = F_27 ( V_96 , struct V_17 , V_28 ) ;
V_96 = F_56 ( & V_97 -> V_28 ) ;
if ( ! F_44 ( V_97 , V_17 ) )
continue;
if ( V_104 >= 2 ) {
if ( V_107 ) {
F_34 ( L_37
L_38 ,
V_17 -> V_22 -> V_58 ) ;
} else {
fputs ( L_39 , V_72 ) ;
F_45 ( V_17 , V_72 ) ;
F_45 ( V_97 , V_72 ) ;
}
}
F_57 ( & V_97 -> V_28 , V_95 ) ;
if ( V_17 -> V_19 > V_97 -> V_19 ) {
struct V_17 * V_108 = F_42 ( V_97 ) ;
if ( V_108 == NULL ) {
V_106 = - V_109 ;
goto V_110;
}
V_108 -> V_20 = V_17 -> V_19 ;
F_77 ( V_97 -> V_29 , V_108 ) ;
if ( V_104 >= 2 && ! V_107 )
F_45 ( V_108 , V_72 ) ;
F_23 ( V_108 ) ;
}
if ( V_17 -> V_20 < V_97 -> V_20 ) {
struct V_17 * V_111 = F_42 ( V_97 ) ;
if ( V_111 == NULL ) {
V_106 = - V_109 ;
goto V_110;
}
V_111 -> V_19 = V_17 -> V_20 ;
F_77 ( V_97 -> V_29 , V_111 ) ;
if ( V_104 >= 2 && ! V_107 )
F_45 ( V_111 , V_72 ) ;
F_23 ( V_111 ) ;
}
V_110:
F_23 ( V_97 ) ;
if ( V_106 )
goto V_99;
}
V_106 = 0 ;
V_99:
F_60 ( & V_87 -> V_90 ) ;
return V_106 ;
}
int F_80 ( struct V_91 * V_92 , struct V_17 * V_17 ,
T_4 * V_72 )
{
return F_79 ( & V_92 -> V_87 [ V_17 -> type ] , V_17 , V_72 ) ;
}
int F_81 ( struct V_40 * V_40 ,
struct V_91 * V_112 , enum V_18 type )
{
struct V_91 * V_92 = V_40 -> V_92 ;
int V_106 = - V_109 ;
struct V_17 * V_17 ;
struct V_87 * V_87 = & V_112 -> V_87 [ type ] ;
F_70 ( & V_87 -> V_90 ) ;
for ( V_17 = F_63 ( V_87 ) ; V_17 ; V_17 = F_82 ( V_17 ) ) {
struct V_17 * V_113 = F_42 ( V_17 ) ;
if ( V_113 == NULL )
goto V_114;
V_106 = F_83 ( V_40 , V_113 , NULL ) ;
if ( V_106 )
goto V_114;
F_84 ( V_92 , V_113 ) ;
F_23 ( V_113 ) ;
}
V_106 = 0 ;
V_114:
F_60 ( & V_87 -> V_90 ) ;
return V_106 ;
}
static void F_78 ( struct V_87 * V_87 , struct V_17 * V_17 )
{
struct V_28 * * V_115 = & V_87 -> V_88 . V_28 ;
struct V_28 * V_112 = NULL ;
const T_3 V_86 = V_17 -> V_19 ;
struct V_17 * V_116 ;
while ( * V_115 != NULL ) {
V_112 = * V_115 ;
V_116 = F_27 ( V_112 , struct V_17 , V_28 ) ;
if ( V_86 < V_116 -> V_19 )
V_115 = & ( * V_115 ) -> V_117 ;
else
V_115 = & ( * V_115 ) -> V_118 ;
}
F_85 ( & V_17 -> V_28 , V_112 , V_115 ) ;
F_86 ( & V_17 -> V_28 , & V_87 -> V_88 ) ;
F_87 ( V_17 ) ;
}
void F_88 ( struct V_87 * V_87 , struct V_17 * V_17 )
{
F_59 ( & V_87 -> V_90 ) ;
F_78 ( V_87 , V_17 ) ;
F_60 ( & V_87 -> V_90 ) ;
}
static void F_89 ( struct V_87 * V_87 , struct V_17 * V_17 )
{
F_57 ( & V_17 -> V_28 , & V_87 -> V_88 ) ;
F_23 ( V_17 ) ;
}
void F_90 ( struct V_87 * V_87 , struct V_17 * V_17 )
{
F_59 ( & V_87 -> V_90 ) ;
F_89 ( V_87 , V_17 ) ;
F_60 ( & V_87 -> V_90 ) ;
}
struct V_17 * F_91 ( struct V_87 * V_87 , T_3 V_86 )
{
struct V_28 * * V_115 , * V_112 = NULL ;
struct V_17 * V_116 ;
F_70 ( & V_87 -> V_90 ) ;
V_115 = & V_87 -> V_88 . V_28 ;
while ( * V_115 != NULL ) {
V_112 = * V_115 ;
V_116 = F_27 ( V_112 , struct V_17 , V_28 ) ;
if ( V_86 < V_116 -> V_19 )
V_115 = & ( * V_115 ) -> V_117 ;
else if ( V_86 >= V_116 -> V_20 )
V_115 = & ( * V_115 ) -> V_118 ;
else
goto V_99;
}
V_116 = NULL ;
V_99:
F_60 ( & V_87 -> V_90 ) ;
return V_116 ;
}
struct V_17 * F_63 ( struct V_87 * V_87 )
{
struct V_28 * V_119 = F_26 ( & V_87 -> V_88 ) ;
if ( V_119 )
return F_27 ( V_119 , struct V_17 , V_28 ) ;
return NULL ;
}
struct V_17 * F_82 ( struct V_17 * V_17 )
{
struct V_28 * V_96 = F_56 ( & V_17 -> V_28 ) ;
if ( V_96 )
return F_27 ( V_96 , struct V_17 , V_28 ) ;
return NULL ;
}
struct V_52 * F_92 ( struct V_17 * V_17 )
{
if ( ! V_17 -> V_22 || ! V_17 -> V_22 -> V_51 ) {
F_93 ( L_40 ) ;
return NULL ;
}
return (struct V_52 * ) ( V_17 + 1 ) ;
}
struct V_91 * F_94 ( struct V_17 * V_17 )
{
struct V_52 * V_52 = F_92 ( V_17 ) ;
if ( ! V_52 || ! V_52 -> V_120 ) {
F_93 ( L_41 ) ;
return NULL ;
}
return V_52 -> V_120 ;
}
