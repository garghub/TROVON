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
static void F_16 ( struct V_15 * V_15 )
{
F_17 ( ! F_18 ( & V_15 -> V_26 ) ) ;
F_19 ( V_15 -> V_20 ) ;
}
void F_20 ( struct V_15 * V_15 )
{
F_16 ( V_15 ) ;
free ( V_15 ) ;
}
void F_21 ( struct V_15 * V_15 )
{
if ( V_15 && F_22 ( & V_15 -> V_29 ) )
F_20 ( V_15 ) ;
}
void F_23 ( struct V_15 * V_15 )
{
struct V_52 * V_53 = & V_15 -> V_20 -> V_53 [ V_15 -> type ] ;
struct V_26 * V_54 = F_24 ( V_53 ) ;
if ( V_54 != NULL ) {
struct V_55 * V_56 = F_25 ( V_54 , struct V_55 , V_26 ) ;
V_15 -> V_17 = V_56 -> V_17 ;
}
}
void F_26 ( struct V_15 * V_15 )
{
struct V_52 * V_53 = & V_15 -> V_20 -> V_53 [ V_15 -> type ] ;
struct V_26 * V_54 = F_27 ( V_53 ) ;
if ( V_54 != NULL ) {
struct V_55 * V_56 = F_25 ( V_54 , struct V_55 , V_26 ) ;
V_15 -> V_18 = V_56 -> V_18 ;
}
}
int F_28 ( struct V_15 * V_15 , T_4 V_57 )
{
const char * V_58 = V_15 -> V_20 -> V_59 ;
int V_60 ;
if ( F_29 ( V_15 -> V_20 , V_15 -> type ) )
return 0 ;
V_60 = F_30 ( V_15 -> V_20 , V_15 , V_57 ) ;
if ( V_60 < 0 ) {
if ( V_15 -> V_20 -> V_61 ) {
char V_62 [ V_63 * 2 + 1 ] ;
F_31 ( V_15 -> V_20 -> V_64 ,
sizeof( V_15 -> V_20 -> V_64 ) ,
V_62 ) ;
F_32 ( L_21 ,
V_58 , V_62 ) ;
} else
F_32 ( L_22 , V_58 ) ;
F_32 ( L_23 ) ;
return - 1 ;
} else if ( V_60 == 0 ) {
#ifdef F_33
const T_1 V_31 = strlen ( V_58 ) ;
const T_1 V_65 = V_31 - sizeof( V_66 ) ;
if ( V_31 > sizeof( V_66 ) &&
strcmp ( V_58 + V_65 + 1 , V_66 ) == 0 ) {
F_32 ( L_24
L_25 ,
( int ) V_65 , V_58 ) ;
} else {
F_32 ( L_26
L_27 , V_58 ) ;
}
#endif
return - 1 ;
}
return 0 ;
}
int __weak F_34 ( const char * V_67 , const char * V_68 )
{
return strcmp ( V_67 , V_68 ) ;
}
struct V_55 * F_35 ( struct V_15 * V_15 , T_2 V_69 ,
T_4 V_57 )
{
if ( F_28 ( V_15 , V_57 ) < 0 )
return NULL ;
return F_36 ( V_15 -> V_20 , V_15 -> type , V_69 ) ;
}
struct V_55 * F_37 ( struct V_15 * V_15 , const char * V_58 ,
T_4 V_57 )
{
if ( F_28 ( V_15 , V_57 ) < 0 )
return NULL ;
if ( ! F_38 ( V_15 -> V_20 , V_15 -> type ) )
F_39 ( V_15 -> V_20 , V_15 -> type ) ;
return F_40 ( V_15 -> V_20 , V_15 -> type , V_58 ) ;
}
struct V_15 * F_41 ( struct V_15 * V_15 )
{
return F_42 ( V_15 , sizeof( * V_15 ) ) ;
}
int F_43 ( struct V_15 * V_70 , struct V_15 * V_71 )
{
if ( V_70 -> V_17 > V_71 -> V_17 ) {
struct V_15 * V_72 = V_70 ;
V_70 = V_71 ;
V_71 = V_72 ;
}
if ( V_70 -> V_18 > V_71 -> V_17 )
return 1 ;
return 0 ;
}
T_1 F_44 ( struct V_15 * V_15 , T_5 * V_73 )
{
return fprintf ( V_73 , L_28 V_74 L_29 V_74 L_28 V_74 L_30 ,
V_15 -> V_17 , V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 -> V_58 ) ;
}
T_1 F_45 ( struct V_15 * V_15 , T_5 * V_73 )
{
const char * V_75 = L_31 ;
if ( V_15 && V_15 -> V_20 && ( V_15 -> V_20 -> V_58 || V_15 -> V_20 -> V_59 ) ) {
if ( V_76 . V_77 && V_15 -> V_20 -> V_59 )
V_75 = V_15 -> V_20 -> V_59 ;
else if ( V_15 -> V_20 -> V_58 )
V_75 = V_15 -> V_20 -> V_58 ;
}
return fprintf ( V_73 , L_32 , V_75 ) ;
}
int F_46 ( struct V_15 * V_15 , T_2 V_69 , const char * V_78 ,
T_5 * V_73 )
{
char * V_79 ;
int V_80 = 0 ;
if ( V_15 && V_15 -> V_20 ) {
V_79 = F_47 ( V_15 -> V_20 ,
F_48 ( V_15 , V_69 ) , NULL , true ) ;
if ( V_79 != V_81 )
V_80 = fprintf ( V_73 , L_33 , V_78 , V_79 ) ;
F_49 ( V_79 ) ;
}
return V_80 ;
}
T_2 F_48 ( struct V_15 * V_15 , T_2 V_82 )
{
if ( ! V_15 -> V_20 -> V_83 )
return V_82 ;
if ( V_15 -> V_20 -> V_84 )
return V_82 - V_15 -> V_19 ;
return V_15 -> V_24 ( V_15 , V_82 ) - V_15 -> V_21 ;
}
T_2 F_50 ( struct V_15 * V_15 , T_2 V_85 )
{
if ( ! V_15 -> V_20 -> V_83 )
return V_15 -> V_24 ( V_15 , V_85 ) ;
if ( V_15 -> V_20 -> V_84 )
return V_15 -> V_24 ( V_15 , V_85 + V_15 -> V_19 ) ;
return V_85 + V_15 -> V_21 ;
}
static void F_51 ( struct V_86 * V_86 )
{
V_86 -> V_87 = V_88 ;
F_52 ( & V_86 -> V_89 , NULL ) ;
}
void F_53 ( struct V_90 * V_91 , struct V_30 * V_30 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_93 ; ++ V_92 ) {
F_51 ( & V_91 -> V_86 [ V_92 ] ) ;
}
V_91 -> V_30 = V_30 ;
F_8 ( & V_91 -> V_29 , 1 ) ;
}
static void F_54 ( struct V_86 * V_86 )
{
struct V_52 * V_94 = & V_86 -> V_87 ;
struct V_26 * V_95 = F_24 ( V_94 ) ;
while ( V_95 ) {
struct V_15 * V_96 = F_25 ( V_95 , struct V_15 , V_26 ) ;
V_95 = F_55 ( & V_96 -> V_26 ) ;
F_56 ( & V_96 -> V_26 , V_94 ) ;
F_21 ( V_96 ) ;
}
}
static void F_57 ( struct V_86 * V_86 )
{
F_58 ( & V_86 -> V_89 ) ;
F_54 ( V_86 ) ;
F_59 ( & V_86 -> V_89 ) ;
}
void F_60 ( struct V_90 * V_91 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_93 ; ++ V_92 )
F_57 ( & V_91 -> V_86 [ V_92 ] ) ;
}
bool F_61 ( struct V_90 * V_91 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_93 ; ++ V_92 ) {
if ( F_62 ( & V_91 -> V_86 [ V_92 ] ) )
return false ;
}
return true ;
}
struct V_90 * F_63 ( struct V_30 * V_30 )
{
struct V_90 * V_91 = malloc ( sizeof( * V_91 ) ) ;
if ( V_91 != NULL )
F_53 ( V_91 , V_30 ) ;
return V_91 ;
}
void F_64 ( struct V_90 * V_91 )
{
F_60 ( V_91 ) ;
free ( V_91 ) ;
}
void F_65 ( struct V_90 * V_91 )
{
if ( V_91 && F_22 ( & V_91 -> V_29 ) )
F_64 ( V_91 ) ;
}
struct V_55 * F_66 ( struct V_90 * V_91 ,
enum V_16 type , T_2 V_69 ,
struct V_15 * * V_97 ,
T_4 V_57 )
{
struct V_15 * V_15 = F_67 ( V_91 , type , V_69 ) ;
if ( V_15 != NULL && F_28 ( V_15 , V_57 ) >= 0 ) {
if ( V_97 != NULL )
* V_97 = V_15 ;
return F_35 ( V_15 , V_15 -> V_22 ( V_15 , V_69 ) , V_57 ) ;
}
return NULL ;
}
struct V_55 * F_68 ( struct V_90 * V_91 ,
enum V_16 type ,
const char * V_58 ,
struct V_15 * * V_97 ,
T_4 V_57 )
{
struct V_86 * V_86 = & V_91 -> V_86 [ type ] ;
struct V_55 * V_56 ;
struct V_26 * V_54 ;
F_69 ( & V_86 -> V_89 ) ;
for ( V_54 = F_24 ( & V_86 -> V_87 ) ; V_54 ; V_54 = F_55 ( V_54 ) ) {
struct V_15 * V_96 = F_25 ( V_54 , struct V_15 , V_26 ) ;
V_56 = F_37 ( V_96 , V_58 , V_57 ) ;
if ( V_56 == NULL )
continue;
if ( V_97 != NULL )
* V_97 = V_96 ;
goto V_98;
}
V_56 = NULL ;
V_98:
F_59 ( & V_86 -> V_89 ) ;
return V_56 ;
}
int F_70 ( struct V_99 * V_100 , T_4 V_57 )
{
if ( V_100 -> V_69 < V_100 -> V_15 -> V_17 || V_100 -> V_69 >= V_100 -> V_15 -> V_18 ) {
if ( V_100 -> V_15 -> V_27 == NULL )
return - 1 ;
V_100 -> V_15 = F_67 ( V_100 -> V_15 -> V_27 , V_100 -> V_15 -> type ,
V_100 -> V_69 ) ;
if ( V_100 -> V_15 == NULL )
return - 1 ;
}
V_100 -> V_101 = V_100 -> V_15 -> V_22 ( V_100 -> V_15 , V_100 -> V_69 ) ;
V_100 -> V_56 = F_35 ( V_100 -> V_15 , V_100 -> V_101 , V_57 ) ;
return V_100 -> V_56 ? 0 : - 1 ;
}
static T_1 F_71 ( struct V_86 * V_86 , T_5 * V_73 )
{
T_1 V_102 = 0 ;
struct V_26 * V_54 ;
F_69 ( & V_86 -> V_89 ) ;
for ( V_54 = F_24 ( & V_86 -> V_87 ) ; V_54 ; V_54 = F_55 ( V_54 ) ) {
struct V_15 * V_96 = F_25 ( V_54 , struct V_15 , V_26 ) ;
V_102 += fprintf ( V_73 , L_34 ) ;
V_102 += F_44 ( V_96 , V_73 ) ;
if ( V_103 > 2 ) {
V_102 += F_72 ( V_96 -> V_20 , V_96 -> type , V_73 ) ;
V_102 += fprintf ( V_73 , L_35 ) ;
}
}
F_59 ( & V_86 -> V_89 ) ;
return V_102 ;
}
T_1 F_73 ( struct V_90 * V_91 , enum V_16 type ,
T_5 * V_73 )
{
T_1 V_102 = fprintf ( V_73 , L_36 , V_104 [ type ] ) ;
return V_102 += F_71 ( & V_91 -> V_86 [ type ] , V_73 ) ;
}
T_1 F_74 ( struct V_90 * V_91 , T_5 * V_73 )
{
T_1 V_102 = 0 , V_92 ;
for ( V_92 = 0 ; V_92 < V_93 ; ++ V_92 )
V_102 += F_73 ( V_91 , V_92 , V_73 ) ;
return V_102 ;
}
static int F_75 ( struct V_86 * V_86 , struct V_15 * V_15 , T_5 * V_73 )
{
struct V_52 * V_94 ;
struct V_26 * V_95 ;
int V_105 = 0 ;
F_58 ( & V_86 -> V_89 ) ;
V_94 = & V_86 -> V_87 ;
V_95 = F_24 ( V_94 ) ;
while ( V_95 ) {
struct V_15 * V_96 = F_25 ( V_95 , struct V_15 , V_26 ) ;
V_95 = F_55 ( & V_96 -> V_26 ) ;
if ( ! F_43 ( V_96 , V_15 ) )
continue;
if ( V_103 >= 2 ) {
fputs ( L_37 , V_73 ) ;
F_44 ( V_15 , V_73 ) ;
F_44 ( V_96 , V_73 ) ;
}
F_56 ( & V_96 -> V_26 , V_94 ) ;
if ( V_15 -> V_17 > V_96 -> V_17 ) {
struct V_15 * V_106 = F_41 ( V_96 ) ;
if ( V_106 == NULL ) {
V_105 = - V_107 ;
goto V_108;
}
V_106 -> V_18 = V_15 -> V_17 ;
F_76 ( V_86 , V_106 ) ;
if ( V_103 >= 2 )
F_44 ( V_106 , V_73 ) ;
}
if ( V_15 -> V_18 < V_96 -> V_18 ) {
struct V_15 * V_109 = F_41 ( V_96 ) ;
if ( V_109 == NULL ) {
V_105 = - V_107 ;
goto V_108;
}
V_109 -> V_17 = V_15 -> V_18 ;
F_76 ( V_86 , V_109 ) ;
if ( V_103 >= 2 )
F_44 ( V_109 , V_73 ) ;
}
V_108:
F_21 ( V_96 ) ;
if ( V_105 )
goto V_98;
}
V_105 = 0 ;
V_98:
F_59 ( & V_86 -> V_89 ) ;
return V_105 ;
}
int F_77 ( struct V_90 * V_91 , struct V_15 * V_15 ,
T_5 * V_73 )
{
return F_75 ( & V_91 -> V_86 [ V_15 -> type ] , V_15 , V_73 ) ;
}
int F_78 ( struct V_90 * V_91 ,
struct V_90 * V_110 , enum V_16 type )
{
int V_105 = - V_107 ;
struct V_15 * V_15 ;
struct V_86 * V_86 = & V_110 -> V_86 [ type ] ;
F_69 ( & V_86 -> V_89 ) ;
for ( V_15 = F_62 ( V_86 ) ; V_15 ; V_15 = F_79 ( V_15 ) ) {
struct V_15 * V_111 = F_41 ( V_15 ) ;
if ( V_111 == NULL )
goto V_112;
F_80 ( V_91 , V_111 ) ;
}
V_105 = 0 ;
V_112:
F_59 ( & V_86 -> V_89 ) ;
return V_105 ;
}
static void F_76 ( struct V_86 * V_86 , struct V_15 * V_15 )
{
struct V_26 * * V_113 = & V_86 -> V_87 . V_26 ;
struct V_26 * V_110 = NULL ;
const T_2 V_85 = V_15 -> V_17 ;
struct V_15 * V_114 ;
while ( * V_113 != NULL ) {
V_110 = * V_113 ;
V_114 = F_25 ( V_110 , struct V_15 , V_26 ) ;
if ( V_85 < V_114 -> V_17 )
V_113 = & ( * V_113 ) -> V_115 ;
else
V_113 = & ( * V_113 ) -> V_116 ;
}
F_81 ( & V_15 -> V_26 , V_110 , V_113 ) ;
F_82 ( & V_15 -> V_26 , & V_86 -> V_87 ) ;
F_83 ( V_15 ) ;
}
void F_84 ( struct V_86 * V_86 , struct V_15 * V_15 )
{
F_58 ( & V_86 -> V_89 ) ;
F_76 ( V_86 , V_15 ) ;
F_59 ( & V_86 -> V_89 ) ;
}
static void F_85 ( struct V_86 * V_86 , struct V_15 * V_15 )
{
F_56 ( & V_15 -> V_26 , & V_86 -> V_87 ) ;
F_21 ( V_15 ) ;
}
void F_86 ( struct V_86 * V_86 , struct V_15 * V_15 )
{
F_58 ( & V_86 -> V_89 ) ;
F_85 ( V_86 , V_15 ) ;
F_59 ( & V_86 -> V_89 ) ;
}
struct V_15 * F_87 ( struct V_86 * V_86 , T_2 V_85 )
{
struct V_26 * * V_113 , * V_110 = NULL ;
struct V_15 * V_114 ;
F_69 ( & V_86 -> V_89 ) ;
V_113 = & V_86 -> V_87 . V_26 ;
while ( * V_113 != NULL ) {
V_110 = * V_113 ;
V_114 = F_25 ( V_110 , struct V_15 , V_26 ) ;
if ( V_85 < V_114 -> V_17 )
V_113 = & ( * V_113 ) -> V_115 ;
else if ( V_85 >= V_114 -> V_18 )
V_113 = & ( * V_113 ) -> V_116 ;
else
goto V_98;
}
V_114 = NULL ;
V_98:
F_59 ( & V_86 -> V_89 ) ;
return V_114 ;
}
struct V_15 * F_62 ( struct V_86 * V_86 )
{
struct V_26 * V_117 = F_24 ( & V_86 -> V_87 ) ;
if ( V_117 )
return F_25 ( V_117 , struct V_15 , V_26 ) ;
return NULL ;
}
struct V_15 * F_79 ( struct V_15 * V_15 )
{
struct V_26 * V_95 = F_55 ( & V_15 -> V_26 ) ;
if ( V_95 )
return F_25 ( V_95 , struct V_15 , V_26 ) ;
return NULL ;
}
struct V_51 * F_88 ( struct V_15 * V_15 )
{
if ( ! V_15 -> V_20 || ! V_15 -> V_20 -> V_50 ) {
F_89 ( L_38 ) ;
return NULL ;
}
return (struct V_51 * ) ( V_15 + 1 ) ;
}
struct V_90 * F_90 ( struct V_15 * V_15 )
{
struct V_51 * V_51 = F_88 ( V_15 ) ;
if ( ! V_51 || ! V_51 -> V_118 ) {
F_89 ( L_39 ) ;
return NULL ;
}
return V_51 -> V_118 ;
}
