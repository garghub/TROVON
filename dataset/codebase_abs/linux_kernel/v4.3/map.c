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
return V_15 -> V_27 -> V_30 -> V_52 [ V_15 -> type ] == V_15 ;
}
static void F_17 ( struct V_15 * V_15 )
{
F_18 ( ! F_19 ( & V_15 -> V_26 ) ) ;
F_20 ( V_15 -> V_20 ) ;
}
void F_21 ( struct V_15 * V_15 )
{
F_17 ( V_15 ) ;
free ( V_15 ) ;
}
void F_22 ( struct V_15 * V_15 )
{
if ( V_15 && F_23 ( & V_15 -> V_29 ) )
F_21 ( V_15 ) ;
}
void F_24 ( struct V_15 * V_15 )
{
struct V_53 * V_54 = & V_15 -> V_20 -> V_54 [ V_15 -> type ] ;
struct V_26 * V_55 = F_25 ( V_54 ) ;
if ( V_55 != NULL ) {
struct V_56 * V_57 = F_26 ( V_55 , struct V_56 , V_26 ) ;
V_15 -> V_17 = V_57 -> V_17 ;
}
}
void F_27 ( struct V_15 * V_15 )
{
struct V_53 * V_54 = & V_15 -> V_20 -> V_54 [ V_15 -> type ] ;
struct V_26 * V_55 = F_28 ( V_54 ) ;
if ( V_55 != NULL ) {
struct V_56 * V_57 = F_26 ( V_55 , struct V_56 , V_26 ) ;
V_15 -> V_18 = V_57 -> V_18 ;
}
}
int F_29 ( struct V_15 * V_15 , T_4 V_58 )
{
const char * V_59 = V_15 -> V_20 -> V_60 ;
int V_61 ;
if ( F_30 ( V_15 -> V_20 , V_15 -> type ) )
return 0 ;
V_61 = F_31 ( V_15 -> V_20 , V_15 , V_58 ) ;
if ( V_61 < 0 ) {
if ( V_15 -> V_20 -> V_62 ) {
char V_63 [ V_64 * 2 + 1 ] ;
F_32 ( V_15 -> V_20 -> V_65 ,
sizeof( V_15 -> V_20 -> V_65 ) ,
V_63 ) ;
F_33 ( L_21 ,
V_59 , V_63 ) ;
} else
F_33 ( L_22 , V_59 ) ;
F_33 ( L_23 ) ;
return - 1 ;
} else if ( V_61 == 0 ) {
#ifdef F_34
const T_1 V_31 = strlen ( V_59 ) ;
const T_1 V_66 = V_31 - sizeof( V_67 ) ;
if ( V_31 > sizeof( V_67 ) &&
strcmp ( V_59 + V_66 + 1 , V_67 ) == 0 ) {
F_33 ( L_24
L_25 ,
( int ) V_66 , V_59 ) ;
} else {
F_33 ( L_26
L_27 , V_59 ) ;
}
#endif
return - 1 ;
}
return 0 ;
}
int __weak F_35 ( const char * V_68 , const char * V_69 )
{
return strcmp ( V_68 , V_69 ) ;
}
struct V_56 * F_36 ( struct V_15 * V_15 , T_2 V_70 ,
T_4 V_58 )
{
if ( F_29 ( V_15 , V_58 ) < 0 )
return NULL ;
return F_37 ( V_15 -> V_20 , V_15 -> type , V_70 ) ;
}
struct V_56 * F_38 ( struct V_15 * V_15 , const char * V_59 ,
T_4 V_58 )
{
if ( F_29 ( V_15 , V_58 ) < 0 )
return NULL ;
if ( ! F_39 ( V_15 -> V_20 , V_15 -> type ) )
F_40 ( V_15 -> V_20 , V_15 -> type ) ;
return F_41 ( V_15 -> V_20 , V_15 -> type , V_59 ) ;
}
struct V_15 * F_42 ( struct V_15 * V_71 )
{
struct V_15 * V_15 = F_43 ( V_71 , sizeof( * V_15 ) ) ;
if ( V_15 != NULL ) {
F_8 ( & V_15 -> V_29 , 1 ) ;
F_7 ( & V_15 -> V_26 ) ;
F_6 ( V_15 -> V_20 ) ;
V_15 -> V_27 = NULL ;
}
return V_15 ;
}
int F_44 ( struct V_15 * V_72 , struct V_15 * V_73 )
{
if ( V_72 -> V_17 > V_73 -> V_17 ) {
struct V_15 * V_74 = V_72 ;
V_72 = V_73 ;
V_73 = V_74 ;
}
if ( V_72 -> V_18 > V_73 -> V_17 )
return 1 ;
return 0 ;
}
T_1 F_45 ( struct V_15 * V_15 , T_5 * V_75 )
{
return fprintf ( V_75 , L_28 V_76 L_29 V_76 L_28 V_76 L_30 ,
V_15 -> V_17 , V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 -> V_59 ) ;
}
T_1 F_46 ( struct V_15 * V_15 , T_5 * V_75 )
{
const char * V_77 = L_31 ;
if ( V_15 && V_15 -> V_20 && ( V_15 -> V_20 -> V_59 || V_15 -> V_20 -> V_60 ) ) {
if ( V_78 . V_79 && V_15 -> V_20 -> V_60 )
V_77 = V_15 -> V_20 -> V_60 ;
else if ( V_15 -> V_20 -> V_59 )
V_77 = V_15 -> V_20 -> V_59 ;
}
return fprintf ( V_75 , L_32 , V_77 ) ;
}
int F_47 ( struct V_15 * V_15 , T_2 V_70 , const char * V_80 ,
T_5 * V_75 )
{
char * V_81 ;
int V_82 = 0 ;
if ( V_15 && V_15 -> V_20 ) {
V_81 = F_48 ( V_15 -> V_20 ,
F_49 ( V_15 , V_70 ) , NULL , true ) ;
if ( V_81 != V_83 )
V_82 = fprintf ( V_75 , L_33 , V_80 , V_81 ) ;
F_50 ( V_81 ) ;
}
return V_82 ;
}
T_2 F_49 ( struct V_15 * V_15 , T_2 V_84 )
{
if ( ! V_15 -> V_20 -> V_85 )
return V_84 ;
if ( V_15 -> V_20 -> V_86 )
return V_84 - V_15 -> V_19 ;
return V_15 -> V_24 ( V_15 , V_84 ) - V_15 -> V_21 ;
}
T_2 F_51 ( struct V_15 * V_15 , T_2 V_87 )
{
if ( ! V_15 -> V_20 -> V_85 )
return V_15 -> V_24 ( V_15 , V_87 ) ;
if ( V_15 -> V_20 -> V_86 )
return V_15 -> V_24 ( V_15 , V_87 + V_15 -> V_19 ) ;
return V_87 + V_15 -> V_21 ;
}
static void F_52 ( struct V_88 * V_88 )
{
V_88 -> V_89 = V_90 ;
F_53 ( & V_88 -> V_91 , NULL ) ;
}
void F_54 ( struct V_92 * V_93 , struct V_30 * V_30 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_95 ; ++ V_94 ) {
F_52 ( & V_93 -> V_88 [ V_94 ] ) ;
}
V_93 -> V_30 = V_30 ;
F_8 ( & V_93 -> V_29 , 1 ) ;
}
static void F_55 ( struct V_88 * V_88 )
{
struct V_53 * V_96 = & V_88 -> V_89 ;
struct V_26 * V_97 = F_25 ( V_96 ) ;
while ( V_97 ) {
struct V_15 * V_98 = F_26 ( V_97 , struct V_15 , V_26 ) ;
V_97 = F_56 ( & V_98 -> V_26 ) ;
F_57 ( & V_98 -> V_26 , V_96 ) ;
F_22 ( V_98 ) ;
}
}
static void F_58 ( struct V_88 * V_88 )
{
F_59 ( & V_88 -> V_91 ) ;
F_55 ( V_88 ) ;
F_60 ( & V_88 -> V_91 ) ;
}
void F_61 ( struct V_92 * V_93 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_95 ; ++ V_94 )
F_58 ( & V_93 -> V_88 [ V_94 ] ) ;
}
bool F_62 ( struct V_92 * V_93 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_95 ; ++ V_94 ) {
if ( F_63 ( & V_93 -> V_88 [ V_94 ] ) )
return false ;
}
return true ;
}
struct V_92 * F_64 ( struct V_30 * V_30 )
{
struct V_92 * V_93 = malloc ( sizeof( * V_93 ) ) ;
if ( V_93 != NULL )
F_54 ( V_93 , V_30 ) ;
return V_93 ;
}
void F_65 ( struct V_92 * V_93 )
{
F_61 ( V_93 ) ;
free ( V_93 ) ;
}
void F_66 ( struct V_92 * V_93 )
{
if ( V_93 && F_23 ( & V_93 -> V_29 ) )
F_65 ( V_93 ) ;
}
struct V_56 * F_67 ( struct V_92 * V_93 ,
enum V_16 type , T_2 V_70 ,
struct V_15 * * V_99 ,
T_4 V_58 )
{
struct V_15 * V_15 = F_68 ( V_93 , type , V_70 ) ;
if ( V_15 != NULL && F_29 ( V_15 , V_58 ) >= 0 ) {
if ( V_99 != NULL )
* V_99 = V_15 ;
return F_36 ( V_15 , V_15 -> V_22 ( V_15 , V_70 ) , V_58 ) ;
}
return NULL ;
}
struct V_56 * F_69 ( struct V_92 * V_93 ,
enum V_16 type ,
const char * V_59 ,
struct V_15 * * V_99 ,
T_4 V_58 )
{
struct V_88 * V_88 = & V_93 -> V_88 [ type ] ;
struct V_56 * V_57 ;
struct V_26 * V_55 ;
F_70 ( & V_88 -> V_91 ) ;
for ( V_55 = F_25 ( & V_88 -> V_89 ) ; V_55 ; V_55 = F_56 ( V_55 ) ) {
struct V_15 * V_98 = F_26 ( V_55 , struct V_15 , V_26 ) ;
V_57 = F_38 ( V_98 , V_59 , V_58 ) ;
if ( V_57 == NULL )
continue;
if ( V_99 != NULL )
* V_99 = V_98 ;
goto V_100;
}
V_57 = NULL ;
V_100:
F_60 ( & V_88 -> V_91 ) ;
return V_57 ;
}
int F_71 ( struct V_101 * V_102 , T_4 V_58 )
{
if ( V_102 -> V_70 < V_102 -> V_15 -> V_17 || V_102 -> V_70 >= V_102 -> V_15 -> V_18 ) {
if ( V_102 -> V_15 -> V_27 == NULL )
return - 1 ;
V_102 -> V_15 = F_68 ( V_102 -> V_15 -> V_27 , V_102 -> V_15 -> type ,
V_102 -> V_70 ) ;
if ( V_102 -> V_15 == NULL )
return - 1 ;
}
V_102 -> V_103 = V_102 -> V_15 -> V_22 ( V_102 -> V_15 , V_102 -> V_70 ) ;
V_102 -> V_57 = F_36 ( V_102 -> V_15 , V_102 -> V_103 , V_58 ) ;
return V_102 -> V_57 ? 0 : - 1 ;
}
static T_1 F_72 ( struct V_88 * V_88 , T_5 * V_75 )
{
T_1 V_104 = 0 ;
struct V_26 * V_55 ;
F_70 ( & V_88 -> V_91 ) ;
for ( V_55 = F_25 ( & V_88 -> V_89 ) ; V_55 ; V_55 = F_56 ( V_55 ) ) {
struct V_15 * V_98 = F_26 ( V_55 , struct V_15 , V_26 ) ;
V_104 += fprintf ( V_75 , L_34 ) ;
V_104 += F_45 ( V_98 , V_75 ) ;
if ( V_105 > 2 ) {
V_104 += F_73 ( V_98 -> V_20 , V_98 -> type , V_75 ) ;
V_104 += fprintf ( V_75 , L_35 ) ;
}
}
F_60 ( & V_88 -> V_91 ) ;
return V_104 ;
}
T_1 F_74 ( struct V_92 * V_93 , enum V_16 type ,
T_5 * V_75 )
{
T_1 V_104 = fprintf ( V_75 , L_36 , V_106 [ type ] ) ;
return V_104 += F_72 ( & V_93 -> V_88 [ type ] , V_75 ) ;
}
T_1 F_75 ( struct V_92 * V_93 , T_5 * V_75 )
{
T_1 V_104 = 0 , V_94 ;
for ( V_94 = 0 ; V_94 < V_95 ; ++ V_94 )
V_104 += F_74 ( V_93 , V_94 , V_75 ) ;
return V_104 ;
}
static int F_76 ( struct V_88 * V_88 , struct V_15 * V_15 , T_5 * V_75 )
{
struct V_53 * V_96 ;
struct V_26 * V_97 ;
int V_107 = 0 ;
F_59 ( & V_88 -> V_91 ) ;
V_96 = & V_88 -> V_89 ;
V_97 = F_25 ( V_96 ) ;
while ( V_97 ) {
struct V_15 * V_98 = F_26 ( V_97 , struct V_15 , V_26 ) ;
V_97 = F_56 ( & V_98 -> V_26 ) ;
if ( ! F_44 ( V_98 , V_15 ) )
continue;
if ( V_105 >= 2 ) {
fputs ( L_37 , V_75 ) ;
F_45 ( V_15 , V_75 ) ;
F_45 ( V_98 , V_75 ) ;
}
F_57 ( & V_98 -> V_26 , V_96 ) ;
if ( V_15 -> V_17 > V_98 -> V_17 ) {
struct V_15 * V_108 = F_42 ( V_98 ) ;
if ( V_108 == NULL ) {
V_107 = - V_109 ;
goto V_110;
}
V_108 -> V_18 = V_15 -> V_17 ;
F_77 ( V_88 , V_108 ) ;
if ( V_105 >= 2 )
F_45 ( V_108 , V_75 ) ;
}
if ( V_15 -> V_18 < V_98 -> V_18 ) {
struct V_15 * V_111 = F_42 ( V_98 ) ;
if ( V_111 == NULL ) {
V_107 = - V_109 ;
goto V_110;
}
V_111 -> V_17 = V_15 -> V_18 ;
F_77 ( V_88 , V_111 ) ;
if ( V_105 >= 2 )
F_45 ( V_111 , V_75 ) ;
}
V_110:
F_22 ( V_98 ) ;
if ( V_107 )
goto V_100;
}
V_107 = 0 ;
V_100:
F_60 ( & V_88 -> V_91 ) ;
return V_107 ;
}
int F_78 ( struct V_92 * V_93 , struct V_15 * V_15 ,
T_5 * V_75 )
{
return F_76 ( & V_93 -> V_88 [ V_15 -> type ] , V_15 , V_75 ) ;
}
int F_79 ( struct V_92 * V_93 ,
struct V_92 * V_112 , enum V_16 type )
{
int V_107 = - V_109 ;
struct V_15 * V_15 ;
struct V_88 * V_88 = & V_112 -> V_88 [ type ] ;
F_70 ( & V_88 -> V_91 ) ;
for ( V_15 = F_63 ( V_88 ) ; V_15 ; V_15 = F_80 ( V_15 ) ) {
struct V_15 * V_113 = F_42 ( V_15 ) ;
if ( V_113 == NULL )
goto V_114;
F_81 ( V_93 , V_113 ) ;
}
V_107 = 0 ;
V_114:
F_60 ( & V_88 -> V_91 ) ;
return V_107 ;
}
static void F_77 ( struct V_88 * V_88 , struct V_15 * V_15 )
{
struct V_26 * * V_115 = & V_88 -> V_89 . V_26 ;
struct V_26 * V_112 = NULL ;
const T_2 V_87 = V_15 -> V_17 ;
struct V_15 * V_116 ;
while ( * V_115 != NULL ) {
V_112 = * V_115 ;
V_116 = F_26 ( V_112 , struct V_15 , V_26 ) ;
if ( V_87 < V_116 -> V_17 )
V_115 = & ( * V_115 ) -> V_117 ;
else
V_115 = & ( * V_115 ) -> V_118 ;
}
F_82 ( & V_15 -> V_26 , V_112 , V_115 ) ;
F_83 ( & V_15 -> V_26 , & V_88 -> V_89 ) ;
F_84 ( V_15 ) ;
}
void F_85 ( struct V_88 * V_88 , struct V_15 * V_15 )
{
F_59 ( & V_88 -> V_91 ) ;
F_77 ( V_88 , V_15 ) ;
F_60 ( & V_88 -> V_91 ) ;
}
static void F_86 ( struct V_88 * V_88 , struct V_15 * V_15 )
{
F_57 ( & V_15 -> V_26 , & V_88 -> V_89 ) ;
F_22 ( V_15 ) ;
}
void F_87 ( struct V_88 * V_88 , struct V_15 * V_15 )
{
F_59 ( & V_88 -> V_91 ) ;
F_86 ( V_88 , V_15 ) ;
F_60 ( & V_88 -> V_91 ) ;
}
struct V_15 * F_88 ( struct V_88 * V_88 , T_2 V_87 )
{
struct V_26 * * V_115 , * V_112 = NULL ;
struct V_15 * V_116 ;
F_70 ( & V_88 -> V_91 ) ;
V_115 = & V_88 -> V_89 . V_26 ;
while ( * V_115 != NULL ) {
V_112 = * V_115 ;
V_116 = F_26 ( V_112 , struct V_15 , V_26 ) ;
if ( V_87 < V_116 -> V_17 )
V_115 = & ( * V_115 ) -> V_117 ;
else if ( V_87 >= V_116 -> V_18 )
V_115 = & ( * V_115 ) -> V_118 ;
else
goto V_100;
}
V_116 = NULL ;
V_100:
F_60 ( & V_88 -> V_91 ) ;
return V_116 ;
}
struct V_15 * F_63 ( struct V_88 * V_88 )
{
struct V_26 * V_119 = F_25 ( & V_88 -> V_89 ) ;
if ( V_119 )
return F_26 ( V_119 , struct V_15 , V_26 ) ;
return NULL ;
}
struct V_15 * F_80 ( struct V_15 * V_15 )
{
struct V_26 * V_97 = F_56 ( & V_15 -> V_26 ) ;
if ( V_97 )
return F_26 ( V_97 , struct V_15 , V_26 ) ;
return NULL ;
}
struct V_51 * F_89 ( struct V_15 * V_15 )
{
if ( ! V_15 -> V_20 || ! V_15 -> V_20 -> V_50 ) {
F_90 ( L_38 ) ;
return NULL ;
}
return (struct V_51 * ) ( V_15 + 1 ) ;
}
struct V_92 * F_91 ( struct V_15 * V_15 )
{
struct V_51 * V_51 = F_89 ( V_15 ) ;
if ( ! V_51 || ! V_51 -> V_120 ) {
F_90 ( L_39 ) ;
return NULL ;
}
return V_51 -> V_120 ;
}
