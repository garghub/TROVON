static inline int F_1 ( const char * V_1 )
{
return strcmp ( V_1 , L_1 ) == 0 ;
}
static inline int F_2 ( const char * V_1 )
{
return ! strncmp ( V_1 , L_2 , 6 ) ||
! strcmp ( V_1 , L_3 ) ;
}
void F_3 ( struct V_2 * V_3 , enum V_4 type ,
T_1 V_5 , T_1 V_6 , T_1 V_7 , struct V_8 * V_8 )
{
V_3 -> type = type ;
V_3 -> V_5 = V_5 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_8 = V_8 ;
V_3 -> V_9 = V_10 ;
V_3 -> V_11 = V_12 ;
F_4 ( & V_3 -> V_13 ) ;
V_3 -> V_14 = NULL ;
V_3 -> V_15 = false ;
V_3 -> V_16 = false ;
}
struct V_2 * F_5 ( struct V_17 * V_18 , T_1 V_5 , T_1 V_19 ,
T_1 V_7 , T_2 V_20 , char * V_1 ,
enum V_4 type )
{
struct V_2 * V_3 = malloc ( sizeof( * V_3 ) ) ;
if ( V_3 != NULL ) {
char V_21 [ V_22 ] ;
struct V_8 * V_8 ;
int V_23 , V_24 , V_25 ;
V_23 = F_1 ( V_1 ) ;
V_25 = F_6 ( V_1 ) ;
V_24 = F_2 ( V_1 ) ;
if ( V_23 ) {
snprintf ( V_21 , sizeof( V_21 ) , L_4 , V_20 ) ;
V_1 = V_21 ;
}
if ( V_25 ) {
V_7 = 0 ;
V_8 = F_7 ( V_18 ) ;
} else
V_8 = F_8 ( V_18 , V_1 ) ;
if ( V_8 == NULL )
goto V_26;
F_3 ( V_3 , type , V_5 , V_5 + V_19 , V_7 , V_8 ) ;
if ( V_23 || V_24 ) {
V_3 -> V_9 = V_3 -> V_11 = V_27 ;
if ( V_24 )
F_9 ( V_8 , V_3 -> type ) ;
}
}
return V_3 ;
V_26:
free ( V_3 ) ;
return NULL ;
}
struct V_2 * F_10 ( T_1 V_5 , struct V_8 * V_8 , enum V_4 type )
{
struct V_2 * V_2 = calloc ( 1 , ( sizeof( * V_2 ) +
( V_8 -> V_28 ? sizeof( struct V_29 ) : 0 ) ) ) ;
if ( V_2 != NULL ) {
F_3 ( V_2 , type , V_5 , 0 , 0 , V_8 ) ;
}
return V_2 ;
}
void F_11 ( struct V_2 * V_3 )
{
free ( V_3 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_30 * V_31 = & V_3 -> V_8 -> V_31 [ V_3 -> type ] ;
struct V_13 * V_32 = F_13 ( V_31 ) ;
if ( V_32 != NULL ) {
struct V_33 * V_34 = F_14 ( V_32 , struct V_33 , V_13 ) ;
V_3 -> V_5 = V_34 -> V_5 ;
}
}
void F_15 ( struct V_2 * V_3 )
{
struct V_30 * V_31 = & V_3 -> V_8 -> V_31 [ V_3 -> type ] ;
struct V_13 * V_32 = F_16 ( V_31 ) ;
if ( V_32 != NULL ) {
struct V_33 * V_34 = F_14 ( V_32 , struct V_33 , V_13 ) ;
V_3 -> V_6 = V_34 -> V_6 ;
}
}
int F_17 ( struct V_2 * V_3 , T_3 V_35 )
{
const char * V_36 = V_3 -> V_8 -> V_37 ;
int V_38 ;
if ( F_18 ( V_3 -> V_8 , V_3 -> type ) )
return 0 ;
V_38 = F_19 ( V_3 -> V_8 , V_3 , V_35 ) ;
if ( V_38 < 0 ) {
if ( V_3 -> V_8 -> V_39 ) {
char V_40 [ V_41 * 2 + 1 ] ;
F_20 ( V_3 -> V_8 -> V_42 ,
sizeof( V_3 -> V_8 -> V_42 ) ,
V_40 ) ;
F_21 ( L_5 ,
V_36 , V_40 ) ;
} else
F_21 ( L_6 , V_36 ) ;
F_21 ( L_7 ) ;
return - 1 ;
} else if ( V_38 == 0 ) {
#ifdef F_22
const T_4 V_19 = strlen ( V_36 ) ;
const T_4 V_43 = V_19 - sizeof( V_44 ) ;
if ( V_19 > sizeof( V_44 ) &&
strcmp ( V_36 + V_43 + 1 , V_44 ) == 0 ) {
F_21 ( L_8
L_9 ,
( int ) V_43 , V_36 ) ;
} else {
F_21 ( L_10
L_11 , V_36 ) ;
}
#endif
return - 1 ;
}
if ( V_3 -> V_8 -> V_28 )
F_23 ( V_3 ) ;
return 0 ;
}
struct V_33 * F_24 ( struct V_2 * V_3 , T_1 V_45 ,
T_3 V_35 )
{
if ( F_17 ( V_3 , V_35 ) < 0 )
return NULL ;
return F_25 ( V_3 -> V_8 , V_3 -> type , V_45 ) ;
}
struct V_33 * F_26 ( struct V_2 * V_3 , const char * V_36 ,
T_3 V_35 )
{
if ( F_17 ( V_3 , V_35 ) < 0 )
return NULL ;
if ( ! F_27 ( V_3 -> V_8 , V_3 -> type ) )
F_28 ( V_3 -> V_8 , V_3 -> type ) ;
return F_29 ( V_3 -> V_8 , V_3 -> type , V_36 ) ;
}
struct V_2 * F_30 ( struct V_2 * V_3 )
{
struct V_2 * V_2 = malloc ( sizeof( * V_3 ) ) ;
if ( ! V_2 )
return NULL ;
memcpy ( V_2 , V_3 , sizeof( * V_3 ) ) ;
return V_2 ;
}
int F_31 ( struct V_2 * V_46 , struct V_2 * V_47 )
{
if ( V_46 -> V_5 > V_47 -> V_5 ) {
struct V_2 * V_48 = V_46 ;
V_46 = V_47 ;
V_47 = V_48 ;
}
if ( V_46 -> V_6 > V_47 -> V_5 )
return 1 ;
return 0 ;
}
T_4 F_32 ( struct V_2 * V_3 , T_5 * V_49 )
{
return fprintf ( V_49 , L_12 V_50 L_13 V_50 L_12 V_50 L_14 ,
V_3 -> V_5 , V_3 -> V_6 , V_3 -> V_7 , V_3 -> V_8 -> V_36 ) ;
}
T_4 F_33 ( struct V_2 * V_2 , T_5 * V_49 )
{
const char * V_51 = L_15 ;
if ( V_2 && V_2 -> V_8 && ( V_2 -> V_8 -> V_36 || V_2 -> V_8 -> V_37 ) ) {
if ( V_52 . V_53 && V_2 -> V_8 -> V_37 )
V_51 = V_2 -> V_8 -> V_37 ;
else if ( V_2 -> V_8 -> V_36 )
V_51 = V_2 -> V_8 -> V_36 ;
}
return fprintf ( V_49 , L_16 , V_51 ) ;
}
T_1 F_34 ( struct V_2 * V_2 , T_1 V_54 )
{
T_1 V_45 = V_2 -> V_8 -> V_55 ?
V_2 -> V_11 ( V_2 , V_54 ) :
V_54 ;
return V_45 ;
}
void F_35 ( struct V_56 * V_57 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; ++ V_58 ) {
V_57 -> V_60 [ V_58 ] = V_61 ;
F_36 ( & V_57 -> V_62 [ V_58 ] ) ;
}
V_57 -> V_63 = NULL ;
}
static void F_37 ( struct V_30 * V_60 )
{
struct V_13 * V_64 = F_13 ( V_60 ) ;
while ( V_64 ) {
struct V_2 * V_65 = F_14 ( V_64 , struct V_2 , V_13 ) ;
V_64 = F_38 ( & V_65 -> V_13 ) ;
F_39 ( & V_65 -> V_13 , V_60 ) ;
F_11 ( V_65 ) ;
}
}
static void F_40 ( struct V_17 * V_60 )
{
struct V_2 * V_65 , * V_66 ;
F_41 (pos, n, maps, node) {
F_42 ( & V_65 -> V_67 ) ;
F_11 ( V_65 ) ;
}
}
void F_43 ( struct V_56 * V_57 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; ++ V_58 ) {
F_37 ( & V_57 -> V_60 [ V_58 ] ) ;
F_40 ( & V_57 -> V_62 [ V_58 ] ) ;
}
}
void F_44 ( struct V_56 * V_57 )
{
int type ;
for ( type = 0 ; type < V_59 ; type ++ ) {
struct V_30 * V_68 = & V_57 -> V_60 [ type ] ;
struct V_13 * V_64 = F_13 ( V_68 ) ;
while ( V_64 ) {
struct V_2 * V_65 = F_14 ( V_64 , struct V_2 , V_13 ) ;
V_64 = F_38 ( & V_65 -> V_13 ) ;
F_39 ( & V_65 -> V_13 , V_68 ) ;
F_45 ( & V_65 -> V_67 , & V_57 -> V_62 [ V_65 -> type ] ) ;
}
}
}
struct V_33 * F_46 ( struct V_56 * V_57 ,
enum V_4 type , T_1 V_45 ,
struct V_2 * * V_69 ,
T_3 V_35 )
{
struct V_2 * V_2 = F_47 ( V_57 , type , V_45 ) ;
if ( V_2 != NULL ) {
if ( V_69 != NULL )
* V_69 = V_2 ;
return F_24 ( V_2 , V_2 -> V_9 ( V_2 , V_45 ) , V_35 ) ;
}
return NULL ;
}
struct V_33 * F_48 ( struct V_56 * V_57 ,
enum V_4 type ,
const char * V_36 ,
struct V_2 * * V_69 ,
T_3 V_35 )
{
struct V_13 * V_32 ;
for ( V_32 = F_13 ( & V_57 -> V_60 [ type ] ) ; V_32 ; V_32 = F_38 ( V_32 ) ) {
struct V_2 * V_65 = F_14 ( V_32 , struct V_2 , V_13 ) ;
struct V_33 * V_34 = F_26 ( V_65 , V_36 , V_35 ) ;
if ( V_34 == NULL )
continue;
if ( V_69 != NULL )
* V_69 = V_65 ;
return V_34 ;
}
return NULL ;
}
T_4 F_49 ( struct V_56 * V_57 ,
enum V_4 type , int V_70 , T_5 * V_49 )
{
T_4 V_71 = fprintf ( V_49 , L_17 , V_72 [ type ] ) ;
struct V_13 * V_32 ;
for ( V_32 = F_13 ( & V_57 -> V_60 [ type ] ) ; V_32 ; V_32 = F_38 ( V_32 ) ) {
struct V_2 * V_65 = F_14 ( V_32 , struct V_2 , V_13 ) ;
V_71 += fprintf ( V_49 , L_18 ) ;
V_71 += F_32 ( V_65 , V_49 ) ;
if ( V_70 > 2 ) {
V_71 += F_50 ( V_65 -> V_8 , type , V_49 ) ;
V_71 += fprintf ( V_49 , L_19 ) ;
}
}
return V_71 ;
}
T_4 F_51 ( struct V_56 * V_57 , int V_70 , T_5 * V_49 )
{
T_4 V_71 = 0 , V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; ++ V_58 )
V_71 += F_49 ( V_57 , V_58 , V_70 , V_49 ) ;
return V_71 ;
}
static T_4 F_52 ( struct V_56 * V_57 ,
enum V_4 type ,
int V_70 , T_5 * V_49 )
{
struct V_2 * V_65 ;
T_4 V_71 = 0 ;
F_53 (pos, &mg->removed_maps[type], node) {
V_71 += fprintf ( V_49 , L_18 ) ;
V_71 += F_32 ( V_65 , V_49 ) ;
if ( V_70 > 1 ) {
V_71 += F_50 ( V_65 -> V_8 , type , V_49 ) ;
V_71 += fprintf ( V_49 , L_19 ) ;
}
}
return V_71 ;
}
static T_4 F_54 ( struct V_56 * V_57 ,
int V_70 , T_5 * V_49 )
{
T_4 V_71 = 0 , V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; ++ V_58 )
V_71 += F_52 ( V_57 , V_58 , V_70 , V_49 ) ;
return V_71 ;
}
T_4 F_55 ( struct V_56 * V_57 , int V_70 , T_5 * V_49 )
{
T_4 V_71 = F_51 ( V_57 , V_70 , V_49 ) ;
V_71 += fprintf ( V_49 , L_20 ) ;
return V_71 + F_54 ( V_57 , V_70 , V_49 ) ;
}
int F_56 ( struct V_56 * V_57 , struct V_2 * V_2 ,
int V_70 , T_5 * V_49 )
{
struct V_30 * V_68 = & V_57 -> V_60 [ V_2 -> type ] ;
struct V_13 * V_64 = F_13 ( V_68 ) ;
int V_73 = 0 ;
while ( V_64 ) {
struct V_2 * V_65 = F_14 ( V_64 , struct V_2 , V_13 ) ;
V_64 = F_38 ( & V_65 -> V_13 ) ;
if ( ! F_31 ( V_65 , V_2 ) )
continue;
if ( V_70 >= 2 ) {
fputs ( L_21 , V_49 ) ;
F_32 ( V_2 , V_49 ) ;
F_32 ( V_65 , V_49 ) ;
}
F_39 ( & V_65 -> V_13 , V_68 ) ;
if ( V_2 -> V_5 > V_65 -> V_5 ) {
struct V_2 * V_74 = F_30 ( V_65 ) ;
if ( V_74 == NULL ) {
V_73 = - V_75 ;
goto V_76;
}
V_74 -> V_6 = V_2 -> V_5 - 1 ;
F_57 ( V_57 , V_74 ) ;
if ( V_70 >= 2 )
F_32 ( V_74 , V_49 ) ;
}
if ( V_2 -> V_6 < V_65 -> V_6 ) {
struct V_2 * V_77 = F_30 ( V_65 ) ;
if ( V_77 == NULL ) {
V_73 = - V_75 ;
goto V_76;
}
V_77 -> V_5 = V_2 -> V_6 + 1 ;
F_57 ( V_57 , V_77 ) ;
if ( V_70 >= 2 )
F_32 ( V_77 , V_49 ) ;
}
V_76:
if ( V_65 -> V_15 )
F_45 ( & V_65 -> V_67 , & V_57 -> V_62 [ V_2 -> type ] ) ;
else
F_11 ( V_65 ) ;
if ( V_73 )
return V_73 ;
}
return 0 ;
}
int F_58 ( struct V_56 * V_57 ,
struct V_56 * V_78 , enum V_4 type )
{
struct V_13 * V_32 ;
for ( V_32 = F_13 ( & V_78 -> V_60 [ type ] ) ; V_32 ; V_32 = F_38 ( V_32 ) ) {
struct V_2 * V_2 = F_14 ( V_32 , struct V_2 , V_13 ) ;
struct V_2 * V_79 = F_30 ( V_2 ) ;
if ( V_79 == NULL )
return - V_75 ;
F_57 ( V_57 , V_79 ) ;
}
return 0 ;
}
static T_1 F_59 ( struct V_2 * V_2 , T_1 V_80 )
{
return V_80 + ( V_81 ) V_2 -> V_7 ;
}
static T_1 F_60 ( struct V_2 * V_2 , T_1 V_80 )
{
return V_80 - ( V_81 ) V_2 -> V_7 ;
}
void F_23 ( struct V_2 * V_3 )
{
struct V_29 * V_29 = F_61 ( V_3 ) ;
V_81 V_82 ;
if ( ! V_29 -> V_83 || ! V_29 -> V_83 -> V_84 )
return;
V_82 = ( V_29 -> V_83 -> V_84 -
V_29 -> V_83 -> V_45 ) ;
if ( ! V_82 )
return;
V_3 -> V_9 = F_59 ;
V_3 -> V_11 = F_60 ;
V_3 -> V_7 = V_82 ;
}
void F_62 ( struct V_30 * V_60 , struct V_2 * V_2 )
{
struct V_13 * * V_85 = & V_60 -> V_13 ;
struct V_13 * V_78 = NULL ;
const T_1 V_80 = V_2 -> V_5 ;
struct V_2 * V_86 ;
while ( * V_85 != NULL ) {
V_78 = * V_85 ;
V_86 = F_14 ( V_78 , struct V_2 , V_13 ) ;
if ( V_80 < V_86 -> V_5 )
V_85 = & ( * V_85 ) -> V_87 ;
else
V_85 = & ( * V_85 ) -> V_88 ;
}
F_63 ( & V_2 -> V_13 , V_78 , V_85 ) ;
F_64 ( & V_2 -> V_13 , V_60 ) ;
}
void F_65 ( struct V_30 * V_3 , struct V_2 * V_2 )
{
F_39 ( & V_2 -> V_13 , V_3 ) ;
}
struct V_2 * F_66 ( struct V_30 * V_60 , T_1 V_80 )
{
struct V_13 * * V_85 = & V_60 -> V_13 ;
struct V_13 * V_78 = NULL ;
struct V_2 * V_86 ;
while ( * V_85 != NULL ) {
V_78 = * V_85 ;
V_86 = F_14 ( V_78 , struct V_2 , V_13 ) ;
if ( V_80 < V_86 -> V_5 )
V_85 = & ( * V_85 ) -> V_87 ;
else if ( V_80 > V_86 -> V_6 )
V_85 = & ( * V_85 ) -> V_88 ;
else
return V_86 ;
}
return NULL ;
}
