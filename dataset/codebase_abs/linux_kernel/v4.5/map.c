static inline int F_1 ( const char * V_1 )
{
return ! strcmp ( V_1 , L_1 ) ||
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
V_15 -> V_20 = F_6 ( V_20 ) ;
V_15 -> V_22 = V_23 ;
V_15 -> V_24 = V_25 ;
F_7 ( & V_15 -> V_26 ) ;
V_15 -> V_27 = NULL ;
V_15 -> V_28 = false ;
F_8 ( & V_15 -> V_29 , 1 ) ;
}
struct V_15 * F_9 ( struct V_30 * V_30 , T_2 V_17 , T_2 V_31 ,
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
V_42 = F_10 ( V_1 ) ;
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
V_20 = F_11 ( V_30 , V_39 ) ;
} else
V_20 = F_12 ( V_30 , V_1 ) ;
if ( V_20 == NULL )
goto V_48;
F_5 ( V_15 , type , V_17 , V_17 + V_31 , V_19 , V_20 ) ;
if ( V_40 || V_41 ) {
V_15 -> V_22 = V_15 -> V_24 = V_49 ;
if ( type != V_47 )
F_13 ( V_20 , V_15 -> type ) ;
}
F_14 ( V_20 ) ;
}
return V_15 ;
V_48:
free ( V_15 ) ;
return NULL ;
}
struct V_15 * F_15 ( T_2 V_17 , struct V_20 * V_20 , enum V_16 type )
{
struct V_15 * V_15 = calloc ( 1 , ( sizeof( * V_15 ) +
( V_20 -> V_50 ? sizeof( struct V_51 ) : 0 ) ) ) ;
if ( V_15 != NULL ) {
F_5 ( V_15 , type , V_17 , 0 , 0 , V_20 ) ;
}
return V_15 ;
}
bool F_16 ( const struct V_15 * V_15 )
{
return F_17 ( V_15 -> V_27 -> V_30 , V_15 -> type ) == V_15 ;
}
static void F_18 ( struct V_15 * V_15 )
{
F_19 ( ! F_20 ( & V_15 -> V_26 ) ) ;
F_21 ( V_15 -> V_20 ) ;
}
void F_22 ( struct V_15 * V_15 )
{
F_18 ( V_15 ) ;
free ( V_15 ) ;
}
void F_23 ( struct V_15 * V_15 )
{
if ( V_15 && F_24 ( & V_15 -> V_29 ) )
F_22 ( V_15 ) ;
}
void F_25 ( struct V_15 * V_15 )
{
struct V_52 * V_53 = & V_15 -> V_20 -> V_53 [ V_15 -> type ] ;
struct V_26 * V_54 = F_26 ( V_53 ) ;
if ( V_54 != NULL ) {
struct V_55 * V_56 = F_27 ( V_54 , struct V_55 , V_26 ) ;
V_15 -> V_17 = V_56 -> V_17 ;
}
}
void F_28 ( struct V_15 * V_15 )
{
struct V_52 * V_53 = & V_15 -> V_20 -> V_53 [ V_15 -> type ] ;
struct V_26 * V_54 = F_29 ( V_53 ) ;
if ( V_54 != NULL ) {
struct V_55 * V_56 = F_27 ( V_54 , struct V_55 , V_26 ) ;
V_15 -> V_18 = V_56 -> V_18 ;
}
}
int F_30 ( struct V_15 * V_15 , T_4 V_57 )
{
const char * V_58 = V_15 -> V_20 -> V_59 ;
int V_60 ;
if ( F_31 ( V_15 -> V_20 , V_15 -> type ) )
return 0 ;
V_60 = F_32 ( V_15 -> V_20 , V_15 , V_57 ) ;
if ( V_60 < 0 ) {
if ( V_15 -> V_20 -> V_61 ) {
char V_62 [ V_63 * 2 + 1 ] ;
F_33 ( V_15 -> V_20 -> V_64 ,
sizeof( V_15 -> V_20 -> V_64 ) ,
V_62 ) ;
F_34 ( L_21 ,
V_58 , V_62 ) ;
} else
F_34 ( L_22 , V_58 ) ;
F_34 ( L_23 ) ;
return - 1 ;
} else if ( V_60 == 0 ) {
#ifdef F_35
const T_1 V_31 = strlen ( V_58 ) ;
const T_1 V_65 = V_31 - sizeof( V_66 ) ;
if ( V_31 > sizeof( V_66 ) &&
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
struct V_55 * F_37 ( struct V_15 * V_15 , T_2 V_69 ,
T_4 V_57 )
{
if ( F_30 ( V_15 , V_57 ) < 0 )
return NULL ;
return F_38 ( V_15 -> V_20 , V_15 -> type , V_69 ) ;
}
struct V_55 * F_39 ( struct V_15 * V_15 , const char * V_58 ,
T_4 V_57 )
{
if ( F_30 ( V_15 , V_57 ) < 0 )
return NULL ;
if ( ! F_40 ( V_15 -> V_20 , V_15 -> type ) )
F_41 ( V_15 -> V_20 , V_15 -> type ) ;
return F_42 ( V_15 -> V_20 , V_15 -> type , V_58 ) ;
}
struct V_15 * F_43 ( struct V_15 * V_70 )
{
struct V_15 * V_15 = F_44 ( V_70 , sizeof( * V_15 ) ) ;
if ( V_15 != NULL ) {
F_8 ( & V_15 -> V_29 , 1 ) ;
F_7 ( & V_15 -> V_26 ) ;
F_6 ( V_15 -> V_20 ) ;
V_15 -> V_27 = NULL ;
}
return V_15 ;
}
int F_45 ( struct V_15 * V_71 , struct V_15 * V_72 )
{
if ( V_71 -> V_17 > V_72 -> V_17 ) {
struct V_15 * V_73 = V_71 ;
V_71 = V_72 ;
V_72 = V_73 ;
}
if ( V_71 -> V_18 > V_72 -> V_17 )
return 1 ;
return 0 ;
}
T_1 F_46 ( struct V_15 * V_15 , T_5 * V_74 )
{
return fprintf ( V_74 , L_28 V_75 L_29 V_75 L_28 V_75 L_30 ,
V_15 -> V_17 , V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 -> V_58 ) ;
}
T_1 F_47 ( struct V_15 * V_15 , T_5 * V_74 )
{
const char * V_76 = L_31 ;
if ( V_15 && V_15 -> V_20 && ( V_15 -> V_20 -> V_58 || V_15 -> V_20 -> V_59 ) ) {
if ( V_77 . V_78 && V_15 -> V_20 -> V_59 )
V_76 = V_15 -> V_20 -> V_59 ;
else if ( V_15 -> V_20 -> V_58 )
V_76 = V_15 -> V_20 -> V_58 ;
}
return fprintf ( V_74 , L_32 , V_76 ) ;
}
int F_48 ( struct V_15 * V_15 , T_2 V_69 , const char * V_79 ,
T_5 * V_74 )
{
char * V_80 ;
int V_81 = 0 ;
if ( V_15 && V_15 -> V_20 ) {
V_80 = F_49 ( V_15 -> V_20 ,
F_50 ( V_15 , V_69 ) , NULL , true ) ;
if ( V_80 != V_82 )
V_81 = fprintf ( V_74 , L_33 , V_79 , V_80 ) ;
F_51 ( V_80 ) ;
}
return V_81 ;
}
T_2 F_50 ( struct V_15 * V_15 , T_2 V_83 )
{
if ( ! V_15 -> V_20 -> V_84 )
return V_83 ;
if ( V_15 -> V_20 -> V_85 )
return V_83 - V_15 -> V_19 ;
return V_15 -> V_24 ( V_15 , V_83 ) - V_15 -> V_21 ;
}
T_2 F_52 ( struct V_15 * V_15 , T_2 V_86 )
{
if ( ! V_15 -> V_20 -> V_84 )
return V_15 -> V_24 ( V_15 , V_86 ) ;
if ( V_15 -> V_20 -> V_85 )
return V_15 -> V_24 ( V_15 , V_86 + V_15 -> V_19 ) ;
return V_86 + V_15 -> V_21 ;
}
static void F_53 ( struct V_87 * V_87 )
{
V_87 -> V_88 = V_89 ;
F_54 ( & V_87 -> V_90 , NULL ) ;
}
void F_55 ( struct V_91 * V_92 , struct V_30 * V_30 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; ++ V_93 ) {
F_53 ( & V_92 -> V_87 [ V_93 ] ) ;
}
V_92 -> V_30 = V_30 ;
F_8 ( & V_92 -> V_29 , 1 ) ;
}
static void F_56 ( struct V_87 * V_87 )
{
struct V_52 * V_95 = & V_87 -> V_88 ;
struct V_26 * V_96 = F_26 ( V_95 ) ;
while ( V_96 ) {
struct V_15 * V_97 = F_27 ( V_96 , struct V_15 , V_26 ) ;
V_96 = F_57 ( & V_97 -> V_26 ) ;
F_58 ( & V_97 -> V_26 , V_95 ) ;
F_23 ( V_97 ) ;
}
}
static void F_59 ( struct V_87 * V_87 )
{
F_60 ( & V_87 -> V_90 ) ;
F_56 ( V_87 ) ;
F_61 ( & V_87 -> V_90 ) ;
}
void F_62 ( struct V_91 * V_92 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; ++ V_93 )
F_59 ( & V_92 -> V_87 [ V_93 ] ) ;
}
bool F_63 ( struct V_91 * V_92 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; ++ V_93 ) {
if ( F_64 ( & V_92 -> V_87 [ V_93 ] ) )
return false ;
}
return true ;
}
struct V_91 * F_65 ( struct V_30 * V_30 )
{
struct V_91 * V_92 = malloc ( sizeof( * V_92 ) ) ;
if ( V_92 != NULL )
F_55 ( V_92 , V_30 ) ;
return V_92 ;
}
void F_66 ( struct V_91 * V_92 )
{
F_62 ( V_92 ) ;
free ( V_92 ) ;
}
void F_67 ( struct V_91 * V_92 )
{
if ( V_92 && F_24 ( & V_92 -> V_29 ) )
F_66 ( V_92 ) ;
}
struct V_55 * F_68 ( struct V_91 * V_92 ,
enum V_16 type , T_2 V_69 ,
struct V_15 * * V_98 ,
T_4 V_57 )
{
struct V_15 * V_15 = F_69 ( V_92 , type , V_69 ) ;
if ( V_15 != NULL && F_30 ( V_15 , V_57 ) >= 0 ) {
if ( V_98 != NULL )
* V_98 = V_15 ;
return F_37 ( V_15 , V_15 -> V_22 ( V_15 , V_69 ) , V_57 ) ;
}
return NULL ;
}
struct V_55 * F_70 ( struct V_87 * V_87 , const char * V_58 ,
struct V_15 * * V_98 , T_4 V_57 )
{
struct V_55 * V_56 ;
struct V_26 * V_54 ;
F_71 ( & V_87 -> V_90 ) ;
for ( V_54 = F_26 ( & V_87 -> V_88 ) ; V_54 ; V_54 = F_57 ( V_54 ) ) {
struct V_15 * V_97 = F_27 ( V_54 , struct V_15 , V_26 ) ;
V_56 = F_39 ( V_97 , V_58 , V_57 ) ;
if ( V_56 == NULL )
continue;
if ( V_98 != NULL )
* V_98 = V_97 ;
goto V_99;
}
V_56 = NULL ;
V_99:
F_61 ( & V_87 -> V_90 ) ;
return V_56 ;
}
struct V_55 * F_72 ( struct V_91 * V_92 ,
enum V_16 type ,
const char * V_58 ,
struct V_15 * * V_98 ,
T_4 V_57 )
{
struct V_55 * V_56 = F_70 ( & V_92 -> V_87 [ type ] , V_58 , V_98 , V_57 ) ;
return V_56 ;
}
int F_73 ( struct V_100 * V_101 , T_4 V_57 )
{
if ( V_101 -> V_69 < V_101 -> V_15 -> V_17 || V_101 -> V_69 >= V_101 -> V_15 -> V_18 ) {
if ( V_101 -> V_15 -> V_27 == NULL )
return - 1 ;
V_101 -> V_15 = F_69 ( V_101 -> V_15 -> V_27 , V_101 -> V_15 -> type ,
V_101 -> V_69 ) ;
if ( V_101 -> V_15 == NULL )
return - 1 ;
}
V_101 -> V_102 = V_101 -> V_15 -> V_22 ( V_101 -> V_15 , V_101 -> V_69 ) ;
V_101 -> V_56 = F_37 ( V_101 -> V_15 , V_101 -> V_102 , V_57 ) ;
return V_101 -> V_56 ? 0 : - 1 ;
}
static T_1 F_74 ( struct V_87 * V_87 , T_5 * V_74 )
{
T_1 V_103 = 0 ;
struct V_26 * V_54 ;
F_71 ( & V_87 -> V_90 ) ;
for ( V_54 = F_26 ( & V_87 -> V_88 ) ; V_54 ; V_54 = F_57 ( V_54 ) ) {
struct V_15 * V_97 = F_27 ( V_54 , struct V_15 , V_26 ) ;
V_103 += fprintf ( V_74 , L_34 ) ;
V_103 += F_46 ( V_97 , V_74 ) ;
if ( V_104 > 2 ) {
V_103 += F_75 ( V_97 -> V_20 , V_97 -> type , V_74 ) ;
V_103 += fprintf ( V_74 , L_35 ) ;
}
}
F_61 ( & V_87 -> V_90 ) ;
return V_103 ;
}
T_1 F_76 ( struct V_91 * V_92 , enum V_16 type ,
T_5 * V_74 )
{
T_1 V_103 = fprintf ( V_74 , L_36 , V_105 [ type ] ) ;
return V_103 += F_74 ( & V_92 -> V_87 [ type ] , V_74 ) ;
}
T_1 F_77 ( struct V_91 * V_92 , T_5 * V_74 )
{
T_1 V_103 = 0 , V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; ++ V_93 )
V_103 += F_76 ( V_92 , V_93 , V_74 ) ;
return V_103 ;
}
static void F_78 ( struct V_91 * V_92 , struct V_15 * V_15 )
{
F_79 ( & V_92 -> V_87 [ V_15 -> type ] , V_15 ) ;
V_15 -> V_27 = V_92 ;
}
static int F_80 ( struct V_87 * V_87 , struct V_15 * V_15 , T_5 * V_74 )
{
struct V_52 * V_95 ;
struct V_26 * V_96 ;
int V_106 = 0 ;
F_60 ( & V_87 -> V_90 ) ;
V_95 = & V_87 -> V_88 ;
V_96 = F_26 ( V_95 ) ;
while ( V_96 ) {
struct V_15 * V_97 = F_27 ( V_96 , struct V_15 , V_26 ) ;
V_96 = F_57 ( & V_97 -> V_26 ) ;
if ( ! F_45 ( V_97 , V_15 ) )
continue;
if ( V_104 >= 2 ) {
fputs ( L_37 , V_74 ) ;
F_46 ( V_15 , V_74 ) ;
F_46 ( V_97 , V_74 ) ;
}
F_58 ( & V_97 -> V_26 , V_95 ) ;
if ( V_15 -> V_17 > V_97 -> V_17 ) {
struct V_15 * V_107 = F_43 ( V_97 ) ;
if ( V_107 == NULL ) {
V_106 = - V_108 ;
goto V_109;
}
V_107 -> V_18 = V_15 -> V_17 ;
F_78 ( V_97 -> V_27 , V_107 ) ;
if ( V_104 >= 2 )
F_46 ( V_107 , V_74 ) ;
F_23 ( V_107 ) ;
}
if ( V_15 -> V_18 < V_97 -> V_18 ) {
struct V_15 * V_110 = F_43 ( V_97 ) ;
if ( V_110 == NULL ) {
V_106 = - V_108 ;
goto V_109;
}
V_110 -> V_17 = V_15 -> V_18 ;
F_78 ( V_97 -> V_27 , V_110 ) ;
if ( V_104 >= 2 )
F_46 ( V_110 , V_74 ) ;
F_23 ( V_110 ) ;
}
V_109:
F_23 ( V_97 ) ;
if ( V_106 )
goto V_99;
}
V_106 = 0 ;
V_99:
F_61 ( & V_87 -> V_90 ) ;
return V_106 ;
}
int F_81 ( struct V_91 * V_92 , struct V_15 * V_15 ,
T_5 * V_74 )
{
return F_80 ( & V_92 -> V_87 [ V_15 -> type ] , V_15 , V_74 ) ;
}
int F_82 ( struct V_91 * V_92 ,
struct V_91 * V_111 , enum V_16 type )
{
int V_106 = - V_108 ;
struct V_15 * V_15 ;
struct V_87 * V_87 = & V_111 -> V_87 [ type ] ;
F_71 ( & V_87 -> V_90 ) ;
for ( V_15 = F_64 ( V_87 ) ; V_15 ; V_15 = F_83 ( V_15 ) ) {
struct V_15 * V_112 = F_43 ( V_15 ) ;
if ( V_112 == NULL )
goto V_113;
F_84 ( V_92 , V_112 ) ;
F_23 ( V_112 ) ;
}
V_106 = 0 ;
V_113:
F_61 ( & V_87 -> V_90 ) ;
return V_106 ;
}
static void F_79 ( struct V_87 * V_87 , struct V_15 * V_15 )
{
struct V_26 * * V_114 = & V_87 -> V_88 . V_26 ;
struct V_26 * V_111 = NULL ;
const T_2 V_86 = V_15 -> V_17 ;
struct V_15 * V_115 ;
while ( * V_114 != NULL ) {
V_111 = * V_114 ;
V_115 = F_27 ( V_111 , struct V_15 , V_26 ) ;
if ( V_86 < V_115 -> V_17 )
V_114 = & ( * V_114 ) -> V_116 ;
else
V_114 = & ( * V_114 ) -> V_117 ;
}
F_85 ( & V_15 -> V_26 , V_111 , V_114 ) ;
F_86 ( & V_15 -> V_26 , & V_87 -> V_88 ) ;
F_87 ( V_15 ) ;
}
void F_88 ( struct V_87 * V_87 , struct V_15 * V_15 )
{
F_60 ( & V_87 -> V_90 ) ;
F_79 ( V_87 , V_15 ) ;
F_61 ( & V_87 -> V_90 ) ;
}
static void F_89 ( struct V_87 * V_87 , struct V_15 * V_15 )
{
F_58 ( & V_15 -> V_26 , & V_87 -> V_88 ) ;
F_23 ( V_15 ) ;
}
void F_90 ( struct V_87 * V_87 , struct V_15 * V_15 )
{
F_60 ( & V_87 -> V_90 ) ;
F_89 ( V_87 , V_15 ) ;
F_61 ( & V_87 -> V_90 ) ;
}
struct V_15 * F_91 ( struct V_87 * V_87 , T_2 V_86 )
{
struct V_26 * * V_114 , * V_111 = NULL ;
struct V_15 * V_115 ;
F_71 ( & V_87 -> V_90 ) ;
V_114 = & V_87 -> V_88 . V_26 ;
while ( * V_114 != NULL ) {
V_111 = * V_114 ;
V_115 = F_27 ( V_111 , struct V_15 , V_26 ) ;
if ( V_86 < V_115 -> V_17 )
V_114 = & ( * V_114 ) -> V_116 ;
else if ( V_86 >= V_115 -> V_18 )
V_114 = & ( * V_114 ) -> V_117 ;
else
goto V_99;
}
V_115 = NULL ;
V_99:
F_61 ( & V_87 -> V_90 ) ;
return V_115 ;
}
struct V_15 * F_64 ( struct V_87 * V_87 )
{
struct V_26 * V_118 = F_26 ( & V_87 -> V_88 ) ;
if ( V_118 )
return F_27 ( V_118 , struct V_15 , V_26 ) ;
return NULL ;
}
struct V_15 * F_83 ( struct V_15 * V_15 )
{
struct V_26 * V_96 = F_57 ( & V_15 -> V_26 ) ;
if ( V_96 )
return F_27 ( V_96 , struct V_15 , V_26 ) ;
return NULL ;
}
struct V_51 * F_92 ( struct V_15 * V_15 )
{
if ( ! V_15 -> V_20 || ! V_15 -> V_20 -> V_50 ) {
F_93 ( L_38 ) ;
return NULL ;
}
return (struct V_51 * ) ( V_15 + 1 ) ;
}
struct V_91 * F_94 ( struct V_15 * V_15 )
{
struct V_51 * V_51 = F_92 ( V_15 ) ;
if ( ! V_51 || ! V_51 -> V_119 ) {
F_93 ( L_39 ) ;
return NULL ;
}
return V_51 -> V_119 ;
}
