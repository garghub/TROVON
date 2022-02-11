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
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = V_11 ;
F_4 ( & V_2 -> V_12 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_14 = false ;
V_2 -> V_15 = false ;
}
struct V_2 * F_5 ( struct V_16 * V_17 , T_1 V_4 , T_1 V_18 ,
T_1 V_6 , T_2 V_19 , T_2 V_20 , T_2 V_21 , T_1 V_22 ,
T_1 V_23 , char * V_1 ,
enum V_3 type )
{
struct V_2 * V_2 = malloc ( sizeof( * V_2 ) ) ;
if ( V_2 != NULL ) {
char V_24 [ V_25 ] ;
struct V_7 * V_7 ;
int V_26 , V_27 , V_28 ;
V_26 = F_1 ( V_1 ) ;
V_28 = F_6 ( V_1 ) ;
V_27 = F_2 ( V_1 ) ;
V_2 -> V_29 = V_20 ;
V_2 -> V_30 = V_21 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_31 = V_23 ;
if ( V_26 ) {
snprintf ( V_24 , sizeof( V_24 ) , L_6 , V_19 ) ;
V_1 = V_24 ;
}
if ( V_28 ) {
V_6 = 0 ;
V_7 = F_7 ( V_17 ) ;
} else
V_7 = F_8 ( V_17 , V_1 ) ;
if ( V_7 == NULL )
goto V_32;
F_3 ( V_2 , type , V_4 , V_4 + V_18 , V_6 , V_7 ) ;
if ( V_26 || V_27 ) {
V_2 -> V_8 = V_2 -> V_10 = V_33 ;
if ( V_27 )
F_9 ( V_7 , V_2 -> type ) ;
}
}
return V_2 ;
V_32:
free ( V_2 ) ;
return NULL ;
}
struct V_2 * F_10 ( T_1 V_4 , struct V_7 * V_7 , enum V_3 type )
{
struct V_2 * V_2 = calloc ( 1 , ( sizeof( * V_2 ) +
( V_7 -> V_34 ? sizeof( struct V_35 ) : 0 ) ) ) ;
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
struct V_36 * V_37 = & V_2 -> V_7 -> V_37 [ V_2 -> type ] ;
struct V_12 * V_38 = F_13 ( V_37 ) ;
if ( V_38 != NULL ) {
struct V_39 * V_40 = F_14 ( V_38 , struct V_39 , V_12 ) ;
V_2 -> V_4 = V_40 -> V_4 ;
}
}
void F_15 ( struct V_2 * V_2 )
{
struct V_36 * V_37 = & V_2 -> V_7 -> V_37 [ V_2 -> type ] ;
struct V_12 * V_38 = F_16 ( V_37 ) ;
if ( V_38 != NULL ) {
struct V_39 * V_40 = F_14 ( V_38 , struct V_39 , V_12 ) ;
V_2 -> V_5 = V_40 -> V_5 ;
}
}
int F_17 ( struct V_2 * V_2 , T_3 V_41 )
{
const char * V_42 = V_2 -> V_7 -> V_43 ;
int V_44 ;
if ( F_18 ( V_2 -> V_7 , V_2 -> type ) )
return 0 ;
V_44 = F_19 ( V_2 -> V_7 , V_2 , V_41 ) ;
if ( V_44 < 0 ) {
if ( V_2 -> V_7 -> V_45 ) {
char V_46 [ V_47 * 2 + 1 ] ;
F_20 ( V_2 -> V_7 -> V_48 ,
sizeof( V_2 -> V_7 -> V_48 ) ,
V_46 ) ;
F_21 ( L_7 ,
V_42 , V_46 ) ;
} else
F_21 ( L_8 , V_42 ) ;
F_21 ( L_9 ) ;
return - 1 ;
} else if ( V_44 == 0 ) {
#ifdef F_22
const T_4 V_18 = strlen ( V_42 ) ;
const T_4 V_49 = V_18 - sizeof( V_50 ) ;
if ( V_18 > sizeof( V_50 ) &&
strcmp ( V_42 + V_49 + 1 , V_50 ) == 0 ) {
F_21 ( L_10
L_11 ,
( int ) V_49 , V_42 ) ;
} else {
F_21 ( L_12
L_13 , V_42 ) ;
}
#endif
return - 1 ;
}
return 0 ;
}
struct V_39 * F_23 ( struct V_2 * V_2 , T_1 V_51 ,
T_3 V_41 )
{
if ( F_17 ( V_2 , V_41 ) < 0 )
return NULL ;
return F_24 ( V_2 -> V_7 , V_2 -> type , V_51 ) ;
}
struct V_39 * F_25 ( struct V_2 * V_2 , const char * V_42 ,
T_3 V_41 )
{
if ( F_17 ( V_2 , V_41 ) < 0 )
return NULL ;
if ( ! F_26 ( V_2 -> V_7 , V_2 -> type ) )
F_27 ( V_2 -> V_7 , V_2 -> type ) ;
return F_28 ( V_2 -> V_7 , V_2 -> type , V_42 ) ;
}
struct V_2 * F_29 ( struct V_2 * V_2 )
{
return F_30 ( V_2 , sizeof( * V_2 ) ) ;
}
int F_31 ( struct V_2 * V_52 , struct V_2 * V_53 )
{
if ( V_52 -> V_4 > V_53 -> V_4 ) {
struct V_2 * V_54 = V_52 ;
V_52 = V_53 ;
V_53 = V_54 ;
}
if ( V_52 -> V_5 > V_53 -> V_4 )
return 1 ;
return 0 ;
}
T_4 F_32 ( struct V_2 * V_2 , T_5 * V_55 )
{
return fprintf ( V_55 , L_14 V_56 L_15 V_56 L_14 V_56 L_16 ,
V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_7 -> V_42 ) ;
}
T_4 F_33 ( struct V_2 * V_2 , T_5 * V_55 )
{
const char * V_57 = L_17 ;
if ( V_2 && V_2 -> V_7 && ( V_2 -> V_7 -> V_42 || V_2 -> V_7 -> V_43 ) ) {
if ( V_58 . V_59 && V_2 -> V_7 -> V_43 )
V_57 = V_2 -> V_7 -> V_43 ;
else if ( V_2 -> V_7 -> V_42 )
V_57 = V_2 -> V_7 -> V_42 ;
}
return fprintf ( V_55 , L_18 , V_57 ) ;
}
T_1 F_34 ( struct V_2 * V_2 , T_1 V_60 )
{
if ( ! V_2 -> V_7 -> V_61 )
return V_60 ;
if ( V_2 -> V_7 -> V_62 )
return V_60 - V_2 -> V_6 ;
return V_2 -> V_10 ( V_2 , V_60 ) ;
}
T_1 F_35 ( struct V_2 * V_2 , T_1 V_63 )
{
if ( ! V_2 -> V_7 -> V_61 )
return V_2 -> V_10 ( V_2 , V_63 ) ;
if ( V_2 -> V_7 -> V_62 )
return V_2 -> V_10 ( V_2 , V_63 + V_2 -> V_6 ) ;
return V_63 ;
}
void F_36 ( struct V_64 * V_65 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 ) {
V_65 -> V_68 [ V_66 ] = V_69 ;
F_37 ( & V_65 -> V_70 [ V_66 ] ) ;
}
V_65 -> V_71 = NULL ;
}
static void F_38 ( struct V_36 * V_68 )
{
struct V_12 * V_72 = F_13 ( V_68 ) ;
while ( V_72 ) {
struct V_2 * V_73 = F_14 ( V_72 , struct V_2 , V_12 ) ;
V_72 = F_39 ( & V_73 -> V_12 ) ;
F_40 ( & V_73 -> V_12 , V_68 ) ;
F_11 ( V_73 ) ;
}
}
static void F_41 ( struct V_16 * V_68 )
{
struct V_2 * V_73 , * V_74 ;
F_42 (pos, n, maps, node) {
F_43 ( & V_73 -> V_75 ) ;
F_11 ( V_73 ) ;
}
}
void F_44 ( struct V_64 * V_65 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 ) {
F_38 ( & V_65 -> V_68 [ V_66 ] ) ;
F_41 ( & V_65 -> V_70 [ V_66 ] ) ;
}
}
void F_45 ( struct V_64 * V_65 )
{
int type ;
for ( type = 0 ; type < V_67 ; type ++ ) {
struct V_36 * V_76 = & V_65 -> V_68 [ type ] ;
struct V_12 * V_72 = F_13 ( V_76 ) ;
while ( V_72 ) {
struct V_2 * V_73 = F_14 ( V_72 , struct V_2 , V_12 ) ;
V_72 = F_39 ( & V_73 -> V_12 ) ;
F_40 ( & V_73 -> V_12 , V_76 ) ;
F_46 ( & V_73 -> V_75 , & V_65 -> V_70 [ V_73 -> type ] ) ;
}
}
}
struct V_39 * F_47 ( struct V_64 * V_65 ,
enum V_3 type , T_1 V_51 ,
struct V_2 * * V_77 ,
T_3 V_41 )
{
struct V_2 * V_2 = F_48 ( V_65 , type , V_51 ) ;
if ( V_2 != NULL ) {
if ( V_77 != NULL )
* V_77 = V_2 ;
return F_23 ( V_2 , V_2 -> V_8 ( V_2 , V_51 ) , V_41 ) ;
}
return NULL ;
}
struct V_39 * F_49 ( struct V_64 * V_65 ,
enum V_3 type ,
const char * V_42 ,
struct V_2 * * V_77 ,
T_3 V_41 )
{
struct V_12 * V_38 ;
for ( V_38 = F_13 ( & V_65 -> V_68 [ type ] ) ; V_38 ; V_38 = F_39 ( V_38 ) ) {
struct V_2 * V_73 = F_14 ( V_38 , struct V_2 , V_12 ) ;
struct V_39 * V_40 = F_25 ( V_73 , V_42 , V_41 ) ;
if ( V_40 == NULL )
continue;
if ( V_77 != NULL )
* V_77 = V_73 ;
return V_40 ;
}
return NULL ;
}
int F_50 ( struct V_78 * V_79 , T_3 V_41 )
{
if ( V_79 -> V_51 < V_79 -> V_2 -> V_4 || V_79 -> V_51 > V_79 -> V_2 -> V_5 ) {
if ( V_79 -> V_2 -> V_13 == NULL )
return - 1 ;
V_79 -> V_2 = F_48 ( V_79 -> V_2 -> V_13 , V_79 -> V_2 -> type ,
V_79 -> V_51 ) ;
if ( V_79 -> V_2 == NULL )
return - 1 ;
}
V_79 -> V_80 = V_79 -> V_2 -> V_8 ( V_79 -> V_2 , V_79 -> V_51 ) ;
V_79 -> V_40 = F_23 ( V_79 -> V_2 , V_79 -> V_80 , V_41 ) ;
return V_79 -> V_40 ? 0 : - 1 ;
}
T_4 F_51 ( struct V_64 * V_65 ,
enum V_3 type , int V_81 , T_5 * V_55 )
{
T_4 V_82 = fprintf ( V_55 , L_19 , V_83 [ type ] ) ;
struct V_12 * V_38 ;
for ( V_38 = F_13 ( & V_65 -> V_68 [ type ] ) ; V_38 ; V_38 = F_39 ( V_38 ) ) {
struct V_2 * V_73 = F_14 ( V_38 , struct V_2 , V_12 ) ;
V_82 += fprintf ( V_55 , L_20 ) ;
V_82 += F_32 ( V_73 , V_55 ) ;
if ( V_81 > 2 ) {
V_82 += F_52 ( V_73 -> V_7 , type , V_55 ) ;
V_82 += fprintf ( V_55 , L_21 ) ;
}
}
return V_82 ;
}
T_4 F_53 ( struct V_64 * V_65 , int V_81 , T_5 * V_55 )
{
T_4 V_82 = 0 , V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 )
V_82 += F_51 ( V_65 , V_66 , V_81 , V_55 ) ;
return V_82 ;
}
static T_4 F_54 ( struct V_64 * V_65 ,
enum V_3 type ,
int V_81 , T_5 * V_55 )
{
struct V_2 * V_73 ;
T_4 V_82 = 0 ;
F_55 (pos, &mg->removed_maps[type], node) {
V_82 += fprintf ( V_55 , L_20 ) ;
V_82 += F_32 ( V_73 , V_55 ) ;
if ( V_81 > 1 ) {
V_82 += F_52 ( V_73 -> V_7 , type , V_55 ) ;
V_82 += fprintf ( V_55 , L_21 ) ;
}
}
return V_82 ;
}
static T_4 F_56 ( struct V_64 * V_65 ,
int V_81 , T_5 * V_55 )
{
T_4 V_82 = 0 , V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 )
V_82 += F_54 ( V_65 , V_66 , V_81 , V_55 ) ;
return V_82 ;
}
T_4 F_57 ( struct V_64 * V_65 , int V_81 , T_5 * V_55 )
{
T_4 V_82 = F_53 ( V_65 , V_81 , V_55 ) ;
V_82 += fprintf ( V_55 , L_22 ) ;
return V_82 + F_56 ( V_65 , V_81 , V_55 ) ;
}
int F_58 ( struct V_64 * V_65 , struct V_2 * V_2 ,
int V_81 , T_5 * V_55 )
{
struct V_36 * V_76 = & V_65 -> V_68 [ V_2 -> type ] ;
struct V_12 * V_72 = F_13 ( V_76 ) ;
int V_84 = 0 ;
while ( V_72 ) {
struct V_2 * V_73 = F_14 ( V_72 , struct V_2 , V_12 ) ;
V_72 = F_39 ( & V_73 -> V_12 ) ;
if ( ! F_31 ( V_73 , V_2 ) )
continue;
if ( V_81 >= 2 ) {
fputs ( L_23 , V_55 ) ;
F_32 ( V_2 , V_55 ) ;
F_32 ( V_73 , V_55 ) ;
}
F_40 ( & V_73 -> V_12 , V_76 ) ;
if ( V_2 -> V_4 > V_73 -> V_4 ) {
struct V_2 * V_85 = F_29 ( V_73 ) ;
if ( V_85 == NULL ) {
V_84 = - V_86 ;
goto V_87;
}
V_85 -> V_5 = V_2 -> V_4 - 1 ;
F_59 ( V_65 , V_85 ) ;
if ( V_81 >= 2 )
F_32 ( V_85 , V_55 ) ;
}
if ( V_2 -> V_5 < V_73 -> V_5 ) {
struct V_2 * V_88 = F_29 ( V_73 ) ;
if ( V_88 == NULL ) {
V_84 = - V_86 ;
goto V_87;
}
V_88 -> V_4 = V_2 -> V_5 + 1 ;
F_59 ( V_65 , V_88 ) ;
if ( V_81 >= 2 )
F_32 ( V_88 , V_55 ) ;
}
V_87:
if ( V_73 -> V_14 )
F_46 ( & V_73 -> V_75 , & V_65 -> V_70 [ V_2 -> type ] ) ;
else
F_11 ( V_73 ) ;
if ( V_84 )
return V_84 ;
}
return 0 ;
}
int F_60 ( struct V_64 * V_65 ,
struct V_64 * V_89 , enum V_3 type )
{
struct V_12 * V_38 ;
for ( V_38 = F_13 ( & V_89 -> V_68 [ type ] ) ; V_38 ; V_38 = F_39 ( V_38 ) ) {
struct V_2 * V_2 = F_14 ( V_38 , struct V_2 , V_12 ) ;
struct V_2 * V_90 = F_29 ( V_2 ) ;
if ( V_90 == NULL )
return - V_86 ;
F_59 ( V_65 , V_90 ) ;
}
return 0 ;
}
void F_61 ( struct V_36 * V_68 , struct V_2 * V_2 )
{
struct V_12 * * V_91 = & V_68 -> V_12 ;
struct V_12 * V_89 = NULL ;
const T_1 V_63 = V_2 -> V_4 ;
struct V_2 * V_92 ;
while ( * V_91 != NULL ) {
V_89 = * V_91 ;
V_92 = F_14 ( V_89 , struct V_2 , V_12 ) ;
if ( V_63 < V_92 -> V_4 )
V_91 = & ( * V_91 ) -> V_93 ;
else
V_91 = & ( * V_91 ) -> V_94 ;
}
F_62 ( & V_2 -> V_12 , V_89 , V_91 ) ;
F_63 ( & V_2 -> V_12 , V_68 ) ;
}
void F_64 ( struct V_36 * V_68 , struct V_2 * V_2 )
{
F_40 ( & V_2 -> V_12 , V_68 ) ;
}
struct V_2 * F_65 ( struct V_36 * V_68 , T_1 V_63 )
{
struct V_12 * * V_91 = & V_68 -> V_12 ;
struct V_12 * V_89 = NULL ;
struct V_2 * V_92 ;
while ( * V_91 != NULL ) {
V_89 = * V_91 ;
V_92 = F_14 ( V_89 , struct V_2 , V_12 ) ;
if ( V_63 < V_92 -> V_4 )
V_91 = & ( * V_91 ) -> V_93 ;
else if ( V_63 > V_92 -> V_5 )
V_91 = & ( * V_91 ) -> V_94 ;
else
return V_92 ;
}
return NULL ;
}
struct V_2 * F_66 ( struct V_36 * V_68 )
{
struct V_12 * V_95 = F_13 ( V_68 ) ;
if ( V_95 )
return F_14 ( V_95 , struct V_2 , V_12 ) ;
return NULL ;
}
struct V_2 * F_67 ( struct V_2 * V_2 )
{
struct V_12 * V_72 = F_39 ( & V_2 -> V_12 ) ;
if ( V_72 )
return F_14 ( V_72 , struct V_2 , V_12 ) ;
return NULL ;
}
