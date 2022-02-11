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
void F_3 ( struct V_2 * V_2 , enum V_3 type ,
T_1 V_4 , T_1 V_5 , T_1 V_6 , struct V_7 * V_7 )
{
V_2 -> type = type ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_8 = 0 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
F_4 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = NULL ;
V_2 -> V_15 = false ;
V_2 -> V_16 = false ;
}
struct V_2 * F_5 ( struct V_17 * V_18 , T_1 V_4 , T_1 V_19 ,
T_1 V_6 , T_2 V_20 , T_2 V_21 , T_2 V_22 , T_1 V_23 ,
T_1 V_24 , char * V_1 ,
enum V_3 type )
{
struct V_2 * V_2 = malloc ( sizeof( * V_2 ) ) ;
if ( V_2 != NULL ) {
char V_25 [ V_26 ] ;
struct V_7 * V_7 ;
int V_27 , V_28 , V_29 ;
V_27 = F_1 ( V_1 ) ;
V_29 = F_6 ( V_1 ) ;
V_28 = F_2 ( V_1 ) ;
V_2 -> V_30 = V_21 ;
V_2 -> V_31 = V_22 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_32 = V_24 ;
if ( ( V_27 || V_28 ) && type == V_33 ) {
snprintf ( V_25 , sizeof( V_25 ) , L_6 , V_20 ) ;
V_1 = V_25 ;
}
if ( V_29 ) {
V_6 = 0 ;
V_7 = F_7 ( V_18 ) ;
} else
V_7 = F_8 ( V_18 , V_1 ) ;
if ( V_7 == NULL )
goto V_34;
F_3 ( V_2 , type , V_4 , V_4 + V_19 , V_6 , V_7 ) ;
if ( V_27 || V_28 ) {
V_2 -> V_9 = V_2 -> V_11 = V_35 ;
if ( type != V_33 )
F_9 ( V_7 , V_2 -> type ) ;
}
}
return V_2 ;
V_34:
free ( V_2 ) ;
return NULL ;
}
struct V_2 * F_10 ( T_1 V_4 , struct V_7 * V_7 , enum V_3 type )
{
struct V_2 * V_2 = calloc ( 1 , ( sizeof( * V_2 ) +
( V_7 -> V_36 ? sizeof( struct V_37 ) : 0 ) ) ) ;
if ( V_2 != NULL ) {
F_3 ( V_2 , type , V_4 , 0 , 0 , V_7 ) ;
}
return V_2 ;
}
void F_11 ( struct V_2 * V_2 )
{
free ( V_2 ) ;
}
void F_12 ( struct V_2 * V_2 )
{
struct V_38 * V_39 = & V_2 -> V_7 -> V_39 [ V_2 -> type ] ;
struct V_13 * V_40 = F_13 ( V_39 ) ;
if ( V_40 != NULL ) {
struct V_41 * V_42 = F_14 ( V_40 , struct V_41 , V_13 ) ;
V_2 -> V_4 = V_42 -> V_4 ;
}
}
void F_15 ( struct V_2 * V_2 )
{
struct V_38 * V_39 = & V_2 -> V_7 -> V_39 [ V_2 -> type ] ;
struct V_13 * V_40 = F_16 ( V_39 ) ;
if ( V_40 != NULL ) {
struct V_41 * V_42 = F_14 ( V_40 , struct V_41 , V_13 ) ;
V_2 -> V_5 = V_42 -> V_5 ;
}
}
int F_17 ( struct V_2 * V_2 , T_3 V_43 )
{
const char * V_44 = V_2 -> V_7 -> V_45 ;
int V_46 ;
if ( F_18 ( V_2 -> V_7 , V_2 -> type ) )
return 0 ;
V_46 = F_19 ( V_2 -> V_7 , V_2 , V_43 ) ;
if ( V_46 < 0 ) {
if ( V_2 -> V_7 -> V_47 ) {
char V_48 [ V_49 * 2 + 1 ] ;
F_20 ( V_2 -> V_7 -> V_50 ,
sizeof( V_2 -> V_7 -> V_50 ) ,
V_48 ) ;
F_21 ( L_7 ,
V_44 , V_48 ) ;
} else
F_21 ( L_8 , V_44 ) ;
F_21 ( L_9 ) ;
return - 1 ;
} else if ( V_46 == 0 ) {
#ifdef F_22
const T_4 V_19 = strlen ( V_44 ) ;
const T_4 V_51 = V_19 - sizeof( V_52 ) ;
if ( V_19 > sizeof( V_52 ) &&
strcmp ( V_44 + V_51 + 1 , V_52 ) == 0 ) {
F_21 ( L_10
L_11 ,
( int ) V_51 , V_44 ) ;
} else {
F_21 ( L_12
L_13 , V_44 ) ;
}
#endif
return - 1 ;
}
return 0 ;
}
struct V_41 * F_23 ( struct V_2 * V_2 , T_1 V_53 ,
T_3 V_43 )
{
if ( F_17 ( V_2 , V_43 ) < 0 )
return NULL ;
return F_24 ( V_2 -> V_7 , V_2 -> type , V_53 ) ;
}
struct V_41 * F_25 ( struct V_2 * V_2 , const char * V_44 ,
T_3 V_43 )
{
if ( F_17 ( V_2 , V_43 ) < 0 )
return NULL ;
if ( ! F_26 ( V_2 -> V_7 , V_2 -> type ) )
F_27 ( V_2 -> V_7 , V_2 -> type ) ;
return F_28 ( V_2 -> V_7 , V_2 -> type , V_44 ) ;
}
struct V_2 * F_29 ( struct V_2 * V_2 )
{
return F_30 ( V_2 , sizeof( * V_2 ) ) ;
}
int F_31 ( struct V_2 * V_54 , struct V_2 * V_55 )
{
if ( V_54 -> V_4 > V_55 -> V_4 ) {
struct V_2 * V_56 = V_54 ;
V_54 = V_55 ;
V_55 = V_56 ;
}
if ( V_54 -> V_5 > V_55 -> V_4 )
return 1 ;
return 0 ;
}
T_4 F_32 ( struct V_2 * V_2 , T_5 * V_57 )
{
return fprintf ( V_57 , L_14 V_58 L_15 V_58 L_14 V_58 L_16 ,
V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_7 -> V_44 ) ;
}
T_4 F_33 ( struct V_2 * V_2 , T_5 * V_57 )
{
const char * V_59 = L_17 ;
if ( V_2 && V_2 -> V_7 && ( V_2 -> V_7 -> V_44 || V_2 -> V_7 -> V_45 ) ) {
if ( V_60 . V_61 && V_2 -> V_7 -> V_45 )
V_59 = V_2 -> V_7 -> V_45 ;
else if ( V_2 -> V_7 -> V_44 )
V_59 = V_2 -> V_7 -> V_44 ;
}
return fprintf ( V_57 , L_18 , V_59 ) ;
}
int F_34 ( struct V_2 * V_2 , T_1 V_53 , const char * V_62 ,
T_5 * V_57 )
{
char * V_63 ;
int V_64 = 0 ;
if ( V_2 && V_2 -> V_7 ) {
V_63 = F_35 ( V_2 -> V_7 ,
F_36 ( V_2 , V_53 ) ) ;
if ( V_63 != V_65 )
V_64 = fprintf ( V_57 , L_19 , V_62 , V_63 ) ;
F_37 ( V_63 ) ;
}
return V_64 ;
}
T_1 F_36 ( struct V_2 * V_2 , T_1 V_66 )
{
if ( ! V_2 -> V_7 -> V_67 )
return V_66 ;
if ( V_2 -> V_7 -> V_68 )
return V_66 - V_2 -> V_6 ;
return V_2 -> V_11 ( V_2 , V_66 ) - V_2 -> V_8 ;
}
T_1 F_38 ( struct V_2 * V_2 , T_1 V_69 )
{
if ( ! V_2 -> V_7 -> V_67 )
return V_2 -> V_11 ( V_2 , V_69 ) ;
if ( V_2 -> V_7 -> V_68 )
return V_2 -> V_11 ( V_2 , V_69 + V_2 -> V_6 ) ;
return V_69 + V_2 -> V_8 ;
}
void F_39 ( struct V_70 * V_71 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
V_71 -> V_74 [ V_72 ] = V_75 ;
F_40 ( & V_71 -> V_76 [ V_72 ] ) ;
}
V_71 -> V_77 = NULL ;
}
static void F_41 ( struct V_38 * V_74 )
{
struct V_13 * V_78 = F_13 ( V_74 ) ;
while ( V_78 ) {
struct V_2 * V_79 = F_14 ( V_78 , struct V_2 , V_13 ) ;
V_78 = F_42 ( & V_79 -> V_13 ) ;
F_43 ( & V_79 -> V_13 , V_74 ) ;
F_11 ( V_79 ) ;
}
}
static void F_44 ( struct V_17 * V_74 )
{
struct V_2 * V_79 , * V_80 ;
F_45 (pos, n, maps, node) {
F_46 ( & V_79 -> V_81 ) ;
F_11 ( V_79 ) ;
}
}
void F_47 ( struct V_70 * V_71 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
F_41 ( & V_71 -> V_74 [ V_72 ] ) ;
F_44 ( & V_71 -> V_76 [ V_72 ] ) ;
}
}
void F_48 ( struct V_70 * V_71 )
{
int type ;
for ( type = 0 ; type < V_73 ; type ++ ) {
struct V_38 * V_82 = & V_71 -> V_74 [ type ] ;
struct V_13 * V_78 = F_13 ( V_82 ) ;
while ( V_78 ) {
struct V_2 * V_79 = F_14 ( V_78 , struct V_2 , V_13 ) ;
V_78 = F_42 ( & V_79 -> V_13 ) ;
F_43 ( & V_79 -> V_13 , V_82 ) ;
F_49 ( & V_79 -> V_81 , & V_71 -> V_76 [ V_79 -> type ] ) ;
}
}
}
struct V_41 * F_50 ( struct V_70 * V_71 ,
enum V_3 type , T_1 V_53 ,
struct V_2 * * V_83 ,
T_3 V_43 )
{
struct V_2 * V_2 = F_51 ( V_71 , type , V_53 ) ;
if ( V_2 != NULL && F_17 ( V_2 , V_43 ) >= 0 ) {
if ( V_83 != NULL )
* V_83 = V_2 ;
return F_23 ( V_2 , V_2 -> V_9 ( V_2 , V_53 ) , V_43 ) ;
}
return NULL ;
}
struct V_41 * F_52 ( struct V_70 * V_71 ,
enum V_3 type ,
const char * V_44 ,
struct V_2 * * V_83 ,
T_3 V_43 )
{
struct V_13 * V_40 ;
for ( V_40 = F_13 ( & V_71 -> V_74 [ type ] ) ; V_40 ; V_40 = F_42 ( V_40 ) ) {
struct V_2 * V_79 = F_14 ( V_40 , struct V_2 , V_13 ) ;
struct V_41 * V_42 = F_25 ( V_79 , V_44 , V_43 ) ;
if ( V_42 == NULL )
continue;
if ( V_83 != NULL )
* V_83 = V_79 ;
return V_42 ;
}
return NULL ;
}
int F_53 ( struct V_84 * V_85 , T_3 V_43 )
{
if ( V_85 -> V_53 < V_85 -> V_2 -> V_4 || V_85 -> V_53 > V_85 -> V_2 -> V_5 ) {
if ( V_85 -> V_2 -> V_14 == NULL )
return - 1 ;
V_85 -> V_2 = F_51 ( V_85 -> V_2 -> V_14 , V_85 -> V_2 -> type ,
V_85 -> V_53 ) ;
if ( V_85 -> V_2 == NULL )
return - 1 ;
}
V_85 -> V_86 = V_85 -> V_2 -> V_9 ( V_85 -> V_2 , V_85 -> V_53 ) ;
V_85 -> V_42 = F_23 ( V_85 -> V_2 , V_85 -> V_86 , V_43 ) ;
return V_85 -> V_42 ? 0 : - 1 ;
}
T_4 F_54 ( struct V_70 * V_71 ,
enum V_3 type , int V_87 , T_5 * V_57 )
{
T_4 V_88 = fprintf ( V_57 , L_20 , V_89 [ type ] ) ;
struct V_13 * V_40 ;
for ( V_40 = F_13 ( & V_71 -> V_74 [ type ] ) ; V_40 ; V_40 = F_42 ( V_40 ) ) {
struct V_2 * V_79 = F_14 ( V_40 , struct V_2 , V_13 ) ;
V_88 += fprintf ( V_57 , L_21 ) ;
V_88 += F_32 ( V_79 , V_57 ) ;
if ( V_87 > 2 ) {
V_88 += F_55 ( V_79 -> V_7 , type , V_57 ) ;
V_88 += fprintf ( V_57 , L_22 ) ;
}
}
return V_88 ;
}
T_4 F_56 ( struct V_70 * V_71 , int V_87 , T_5 * V_57 )
{
T_4 V_88 = 0 , V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 )
V_88 += F_54 ( V_71 , V_72 , V_87 , V_57 ) ;
return V_88 ;
}
static T_4 F_57 ( struct V_70 * V_71 ,
enum V_3 type ,
int V_87 , T_5 * V_57 )
{
struct V_2 * V_79 ;
T_4 V_88 = 0 ;
F_58 (pos, &mg->removed_maps[type], node) {
V_88 += fprintf ( V_57 , L_21 ) ;
V_88 += F_32 ( V_79 , V_57 ) ;
if ( V_87 > 1 ) {
V_88 += F_55 ( V_79 -> V_7 , type , V_57 ) ;
V_88 += fprintf ( V_57 , L_22 ) ;
}
}
return V_88 ;
}
static T_4 F_59 ( struct V_70 * V_71 ,
int V_87 , T_5 * V_57 )
{
T_4 V_88 = 0 , V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 )
V_88 += F_57 ( V_71 , V_72 , V_87 , V_57 ) ;
return V_88 ;
}
T_4 F_60 ( struct V_70 * V_71 , int V_87 , T_5 * V_57 )
{
T_4 V_88 = F_56 ( V_71 , V_87 , V_57 ) ;
V_88 += fprintf ( V_57 , L_23 ) ;
return V_88 + F_59 ( V_71 , V_87 , V_57 ) ;
}
int F_61 ( struct V_70 * V_71 , struct V_2 * V_2 ,
int V_87 , T_5 * V_57 )
{
struct V_38 * V_82 = & V_71 -> V_74 [ V_2 -> type ] ;
struct V_13 * V_78 = F_13 ( V_82 ) ;
int V_90 = 0 ;
while ( V_78 ) {
struct V_2 * V_79 = F_14 ( V_78 , struct V_2 , V_13 ) ;
V_78 = F_42 ( & V_79 -> V_13 ) ;
if ( ! F_31 ( V_79 , V_2 ) )
continue;
if ( V_87 >= 2 ) {
fputs ( L_24 , V_57 ) ;
F_32 ( V_2 , V_57 ) ;
F_32 ( V_79 , V_57 ) ;
}
F_43 ( & V_79 -> V_13 , V_82 ) ;
if ( V_2 -> V_4 > V_79 -> V_4 ) {
struct V_2 * V_91 = F_29 ( V_79 ) ;
if ( V_91 == NULL ) {
V_90 = - V_92 ;
goto V_93;
}
V_91 -> V_5 = V_2 -> V_4 - 1 ;
F_62 ( V_71 , V_91 ) ;
if ( V_87 >= 2 )
F_32 ( V_91 , V_57 ) ;
}
if ( V_2 -> V_5 < V_79 -> V_5 ) {
struct V_2 * V_94 = F_29 ( V_79 ) ;
if ( V_94 == NULL ) {
V_90 = - V_92 ;
goto V_93;
}
V_94 -> V_4 = V_2 -> V_5 + 1 ;
F_62 ( V_71 , V_94 ) ;
if ( V_87 >= 2 )
F_32 ( V_94 , V_57 ) ;
}
V_93:
if ( V_79 -> V_15 )
F_49 ( & V_79 -> V_81 , & V_71 -> V_76 [ V_2 -> type ] ) ;
else
F_11 ( V_79 ) ;
if ( V_90 )
return V_90 ;
}
return 0 ;
}
int F_63 ( struct V_70 * V_71 ,
struct V_70 * V_95 , enum V_3 type )
{
struct V_13 * V_40 ;
for ( V_40 = F_13 ( & V_95 -> V_74 [ type ] ) ; V_40 ; V_40 = F_42 ( V_40 ) ) {
struct V_2 * V_2 = F_14 ( V_40 , struct V_2 , V_13 ) ;
struct V_2 * V_96 = F_29 ( V_2 ) ;
if ( V_96 == NULL )
return - V_92 ;
F_62 ( V_71 , V_96 ) ;
}
return 0 ;
}
void F_64 ( struct V_38 * V_74 , struct V_2 * V_2 )
{
struct V_13 * * V_97 = & V_74 -> V_13 ;
struct V_13 * V_95 = NULL ;
const T_1 V_69 = V_2 -> V_4 ;
struct V_2 * V_98 ;
while ( * V_97 != NULL ) {
V_95 = * V_97 ;
V_98 = F_14 ( V_95 , struct V_2 , V_13 ) ;
if ( V_69 < V_98 -> V_4 )
V_97 = & ( * V_97 ) -> V_99 ;
else
V_97 = & ( * V_97 ) -> V_100 ;
}
F_65 ( & V_2 -> V_13 , V_95 , V_97 ) ;
F_66 ( & V_2 -> V_13 , V_74 ) ;
}
void F_67 ( struct V_38 * V_74 , struct V_2 * V_2 )
{
F_43 ( & V_2 -> V_13 , V_74 ) ;
}
struct V_2 * F_68 ( struct V_38 * V_74 , T_1 V_69 )
{
struct V_13 * * V_97 = & V_74 -> V_13 ;
struct V_13 * V_95 = NULL ;
struct V_2 * V_98 ;
while ( * V_97 != NULL ) {
V_95 = * V_97 ;
V_98 = F_14 ( V_95 , struct V_2 , V_13 ) ;
if ( V_69 < V_98 -> V_4 )
V_97 = & ( * V_97 ) -> V_99 ;
else if ( V_69 > V_98 -> V_5 )
V_97 = & ( * V_97 ) -> V_100 ;
else
return V_98 ;
}
return NULL ;
}
struct V_2 * F_69 ( struct V_38 * V_74 )
{
struct V_13 * V_101 = F_13 ( V_74 ) ;
if ( V_101 )
return F_14 ( V_101 , struct V_2 , V_13 ) ;
return NULL ;
}
struct V_2 * F_70 ( struct V_2 * V_2 )
{
struct V_13 * V_78 = F_42 ( & V_2 -> V_13 ) ;
if ( V_78 )
return F_14 ( V_78 , struct V_2 , V_13 ) ;
return NULL ;
}
