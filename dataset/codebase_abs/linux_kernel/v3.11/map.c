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
T_1 V_6 , T_2 V_19 , char * V_1 ,
enum V_3 type )
{
struct V_2 * V_2 = malloc ( sizeof( * V_2 ) ) ;
if ( V_2 != NULL ) {
char V_20 [ V_21 ] ;
struct V_7 * V_7 ;
int V_22 , V_23 , V_24 ;
V_22 = F_1 ( V_1 ) ;
V_24 = F_6 ( V_1 ) ;
V_23 = F_2 ( V_1 ) ;
if ( V_22 ) {
snprintf ( V_20 , sizeof( V_20 ) , L_6 , V_19 ) ;
V_1 = V_20 ;
}
if ( V_24 ) {
V_6 = 0 ;
V_7 = F_7 ( V_17 ) ;
} else
V_7 = F_8 ( V_17 , V_1 ) ;
if ( V_7 == NULL )
goto V_25;
F_3 ( V_2 , type , V_4 , V_4 + V_18 , V_6 , V_7 ) ;
if ( V_22 || V_23 ) {
V_2 -> V_8 = V_2 -> V_10 = V_26 ;
if ( V_23 )
F_9 ( V_7 , V_2 -> type ) ;
}
}
return V_2 ;
V_25:
free ( V_2 ) ;
return NULL ;
}
struct V_2 * F_10 ( T_1 V_4 , struct V_7 * V_7 , enum V_3 type )
{
struct V_2 * V_2 = calloc ( 1 , ( sizeof( * V_2 ) +
( V_7 -> V_27 ? sizeof( struct V_28 ) : 0 ) ) ) ;
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
struct V_29 * V_30 = & V_2 -> V_7 -> V_30 [ V_2 -> type ] ;
struct V_12 * V_31 = F_13 ( V_30 ) ;
if ( V_31 != NULL ) {
struct V_32 * V_33 = F_14 ( V_31 , struct V_32 , V_12 ) ;
V_2 -> V_4 = V_33 -> V_4 ;
}
}
void F_15 ( struct V_2 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_7 -> V_30 [ V_2 -> type ] ;
struct V_12 * V_31 = F_16 ( V_30 ) ;
if ( V_31 != NULL ) {
struct V_32 * V_33 = F_14 ( V_31 , struct V_32 , V_12 ) ;
V_2 -> V_5 = V_33 -> V_5 ;
}
}
int F_17 ( struct V_2 * V_2 , T_3 V_34 )
{
const char * V_35 = V_2 -> V_7 -> V_36 ;
int V_37 ;
if ( F_18 ( V_2 -> V_7 , V_2 -> type ) )
return 0 ;
V_37 = F_19 ( V_2 -> V_7 , V_2 , V_34 ) ;
if ( V_37 < 0 ) {
if ( V_2 -> V_7 -> V_38 ) {
char V_39 [ V_40 * 2 + 1 ] ;
F_20 ( V_2 -> V_7 -> V_41 ,
sizeof( V_2 -> V_7 -> V_41 ) ,
V_39 ) ;
F_21 ( L_7 ,
V_35 , V_39 ) ;
} else
F_21 ( L_8 , V_35 ) ;
F_21 ( L_9 ) ;
return - 1 ;
} else if ( V_37 == 0 ) {
#ifdef F_22
const T_4 V_18 = strlen ( V_35 ) ;
const T_4 V_42 = V_18 - sizeof( V_43 ) ;
if ( V_18 > sizeof( V_43 ) &&
strcmp ( V_35 + V_42 + 1 , V_43 ) == 0 ) {
F_21 ( L_10
L_11 ,
( int ) V_42 , V_35 ) ;
} else {
F_21 ( L_12
L_13 , V_35 ) ;
}
#endif
return - 1 ;
}
if ( V_2 -> V_7 -> V_27 )
F_23 ( V_2 ) ;
return 0 ;
}
struct V_32 * F_24 ( struct V_2 * V_2 , T_1 V_44 ,
T_3 V_34 )
{
if ( F_17 ( V_2 , V_34 ) < 0 )
return NULL ;
return F_25 ( V_2 -> V_7 , V_2 -> type , V_44 ) ;
}
struct V_32 * F_26 ( struct V_2 * V_2 , const char * V_35 ,
T_3 V_34 )
{
if ( F_17 ( V_2 , V_34 ) < 0 )
return NULL ;
if ( ! F_27 ( V_2 -> V_7 , V_2 -> type ) )
F_28 ( V_2 -> V_7 , V_2 -> type ) ;
return F_29 ( V_2 -> V_7 , V_2 -> type , V_35 ) ;
}
struct V_2 * F_30 ( struct V_2 * V_2 )
{
return F_31 ( V_2 , sizeof( * V_2 ) ) ;
}
int F_32 ( struct V_2 * V_45 , struct V_2 * V_46 )
{
if ( V_45 -> V_4 > V_46 -> V_4 ) {
struct V_2 * V_47 = V_45 ;
V_45 = V_46 ;
V_46 = V_47 ;
}
if ( V_45 -> V_5 > V_46 -> V_4 )
return 1 ;
return 0 ;
}
T_4 F_33 ( struct V_2 * V_2 , T_5 * V_48 )
{
return fprintf ( V_48 , L_14 V_49 L_15 V_49 L_14 V_49 L_16 ,
V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_7 -> V_35 ) ;
}
T_4 F_34 ( struct V_2 * V_2 , T_5 * V_48 )
{
const char * V_50 = L_17 ;
if ( V_2 && V_2 -> V_7 && ( V_2 -> V_7 -> V_35 || V_2 -> V_7 -> V_36 ) ) {
if ( V_51 . V_52 && V_2 -> V_7 -> V_36 )
V_50 = V_2 -> V_7 -> V_36 ;
else if ( V_2 -> V_7 -> V_35 )
V_50 = V_2 -> V_7 -> V_35 ;
}
return fprintf ( V_48 , L_18 , V_50 ) ;
}
T_1 F_35 ( struct V_2 * V_2 , T_1 V_53 )
{
T_1 V_44 = V_2 -> V_7 -> V_54 ?
V_2 -> V_10 ( V_2 , V_53 ) :
V_53 ;
return V_44 ;
}
void F_36 ( struct V_55 * V_56 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; ++ V_57 ) {
V_56 -> V_59 [ V_57 ] = V_60 ;
F_37 ( & V_56 -> V_61 [ V_57 ] ) ;
}
V_56 -> V_62 = NULL ;
}
static void F_38 ( struct V_29 * V_59 )
{
struct V_12 * V_63 = F_13 ( V_59 ) ;
while ( V_63 ) {
struct V_2 * V_64 = F_14 ( V_63 , struct V_2 , V_12 ) ;
V_63 = F_39 ( & V_64 -> V_12 ) ;
F_40 ( & V_64 -> V_12 , V_59 ) ;
F_11 ( V_64 ) ;
}
}
static void F_41 ( struct V_16 * V_59 )
{
struct V_2 * V_64 , * V_65 ;
F_42 (pos, n, maps, node) {
F_43 ( & V_64 -> V_66 ) ;
F_11 ( V_64 ) ;
}
}
void F_44 ( struct V_55 * V_56 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; ++ V_57 ) {
F_38 ( & V_56 -> V_59 [ V_57 ] ) ;
F_41 ( & V_56 -> V_61 [ V_57 ] ) ;
}
}
void F_45 ( struct V_55 * V_56 )
{
int type ;
for ( type = 0 ; type < V_58 ; type ++ ) {
struct V_29 * V_67 = & V_56 -> V_59 [ type ] ;
struct V_12 * V_63 = F_13 ( V_67 ) ;
while ( V_63 ) {
struct V_2 * V_64 = F_14 ( V_63 , struct V_2 , V_12 ) ;
V_63 = F_39 ( & V_64 -> V_12 ) ;
F_40 ( & V_64 -> V_12 , V_67 ) ;
F_46 ( & V_64 -> V_66 , & V_56 -> V_61 [ V_64 -> type ] ) ;
}
}
}
struct V_32 * F_47 ( struct V_55 * V_56 ,
enum V_3 type , T_1 V_44 ,
struct V_2 * * V_68 ,
T_3 V_34 )
{
struct V_2 * V_2 = F_48 ( V_56 , type , V_44 ) ;
if ( V_2 != NULL ) {
if ( V_68 != NULL )
* V_68 = V_2 ;
return F_24 ( V_2 , V_2 -> V_8 ( V_2 , V_44 ) , V_34 ) ;
}
return NULL ;
}
struct V_32 * F_49 ( struct V_55 * V_56 ,
enum V_3 type ,
const char * V_35 ,
struct V_2 * * V_68 ,
T_3 V_34 )
{
struct V_12 * V_31 ;
for ( V_31 = F_13 ( & V_56 -> V_59 [ type ] ) ; V_31 ; V_31 = F_39 ( V_31 ) ) {
struct V_2 * V_64 = F_14 ( V_31 , struct V_2 , V_12 ) ;
struct V_32 * V_33 = F_26 ( V_64 , V_35 , V_34 ) ;
if ( V_33 == NULL )
continue;
if ( V_68 != NULL )
* V_68 = V_64 ;
return V_33 ;
}
return NULL ;
}
T_4 F_50 ( struct V_55 * V_56 ,
enum V_3 type , int V_69 , T_5 * V_48 )
{
T_4 V_70 = fprintf ( V_48 , L_19 , V_71 [ type ] ) ;
struct V_12 * V_31 ;
for ( V_31 = F_13 ( & V_56 -> V_59 [ type ] ) ; V_31 ; V_31 = F_39 ( V_31 ) ) {
struct V_2 * V_64 = F_14 ( V_31 , struct V_2 , V_12 ) ;
V_70 += fprintf ( V_48 , L_20 ) ;
V_70 += F_33 ( V_64 , V_48 ) ;
if ( V_69 > 2 ) {
V_70 += F_51 ( V_64 -> V_7 , type , V_48 ) ;
V_70 += fprintf ( V_48 , L_21 ) ;
}
}
return V_70 ;
}
T_4 F_52 ( struct V_55 * V_56 , int V_69 , T_5 * V_48 )
{
T_4 V_70 = 0 , V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; ++ V_57 )
V_70 += F_50 ( V_56 , V_57 , V_69 , V_48 ) ;
return V_70 ;
}
static T_4 F_53 ( struct V_55 * V_56 ,
enum V_3 type ,
int V_69 , T_5 * V_48 )
{
struct V_2 * V_64 ;
T_4 V_70 = 0 ;
F_54 (pos, &mg->removed_maps[type], node) {
V_70 += fprintf ( V_48 , L_20 ) ;
V_70 += F_33 ( V_64 , V_48 ) ;
if ( V_69 > 1 ) {
V_70 += F_51 ( V_64 -> V_7 , type , V_48 ) ;
V_70 += fprintf ( V_48 , L_21 ) ;
}
}
return V_70 ;
}
static T_4 F_55 ( struct V_55 * V_56 ,
int V_69 , T_5 * V_48 )
{
T_4 V_70 = 0 , V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; ++ V_57 )
V_70 += F_53 ( V_56 , V_57 , V_69 , V_48 ) ;
return V_70 ;
}
T_4 F_56 ( struct V_55 * V_56 , int V_69 , T_5 * V_48 )
{
T_4 V_70 = F_52 ( V_56 , V_69 , V_48 ) ;
V_70 += fprintf ( V_48 , L_22 ) ;
return V_70 + F_55 ( V_56 , V_69 , V_48 ) ;
}
int F_57 ( struct V_55 * V_56 , struct V_2 * V_2 ,
int V_69 , T_5 * V_48 )
{
struct V_29 * V_67 = & V_56 -> V_59 [ V_2 -> type ] ;
struct V_12 * V_63 = F_13 ( V_67 ) ;
int V_72 = 0 ;
while ( V_63 ) {
struct V_2 * V_64 = F_14 ( V_63 , struct V_2 , V_12 ) ;
V_63 = F_39 ( & V_64 -> V_12 ) ;
if ( ! F_32 ( V_64 , V_2 ) )
continue;
if ( V_69 >= 2 ) {
fputs ( L_23 , V_48 ) ;
F_33 ( V_2 , V_48 ) ;
F_33 ( V_64 , V_48 ) ;
}
F_40 ( & V_64 -> V_12 , V_67 ) ;
if ( V_2 -> V_4 > V_64 -> V_4 ) {
struct V_2 * V_73 = F_30 ( V_64 ) ;
if ( V_73 == NULL ) {
V_72 = - V_74 ;
goto V_75;
}
V_73 -> V_5 = V_2 -> V_4 - 1 ;
F_58 ( V_56 , V_73 ) ;
if ( V_69 >= 2 )
F_33 ( V_73 , V_48 ) ;
}
if ( V_2 -> V_5 < V_64 -> V_5 ) {
struct V_2 * V_76 = F_30 ( V_64 ) ;
if ( V_76 == NULL ) {
V_72 = - V_74 ;
goto V_75;
}
V_76 -> V_4 = V_2 -> V_5 + 1 ;
F_58 ( V_56 , V_76 ) ;
if ( V_69 >= 2 )
F_33 ( V_76 , V_48 ) ;
}
V_75:
if ( V_64 -> V_14 )
F_46 ( & V_64 -> V_66 , & V_56 -> V_61 [ V_2 -> type ] ) ;
else
F_11 ( V_64 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
int F_59 ( struct V_55 * V_56 ,
struct V_55 * V_77 , enum V_3 type )
{
struct V_12 * V_31 ;
for ( V_31 = F_13 ( & V_77 -> V_59 [ type ] ) ; V_31 ; V_31 = F_39 ( V_31 ) ) {
struct V_2 * V_2 = F_14 ( V_31 , struct V_2 , V_12 ) ;
struct V_2 * V_78 = F_30 ( V_2 ) ;
if ( V_78 == NULL )
return - V_74 ;
F_58 ( V_56 , V_78 ) ;
}
return 0 ;
}
static T_1 F_60 ( struct V_2 * V_2 , T_1 V_79 )
{
return V_79 + ( V_80 ) V_2 -> V_6 ;
}
static T_1 F_61 ( struct V_2 * V_2 , T_1 V_79 )
{
return V_79 - ( V_80 ) V_2 -> V_6 ;
}
void F_23 ( struct V_2 * V_2 )
{
struct V_28 * V_28 = F_62 ( V_2 ) ;
V_80 V_81 ;
if ( ! V_28 -> V_82 || ! V_28 -> V_82 -> V_83 )
return;
V_81 = ( V_28 -> V_82 -> V_83 -
V_28 -> V_82 -> V_44 ) ;
if ( ! V_81 )
return;
V_2 -> V_8 = F_60 ;
V_2 -> V_10 = F_61 ;
V_2 -> V_6 = V_81 ;
}
void F_63 ( struct V_29 * V_59 , struct V_2 * V_2 )
{
struct V_12 * * V_84 = & V_59 -> V_12 ;
struct V_12 * V_77 = NULL ;
const T_1 V_79 = V_2 -> V_4 ;
struct V_2 * V_85 ;
while ( * V_84 != NULL ) {
V_77 = * V_84 ;
V_85 = F_14 ( V_77 , struct V_2 , V_12 ) ;
if ( V_79 < V_85 -> V_4 )
V_84 = & ( * V_84 ) -> V_86 ;
else
V_84 = & ( * V_84 ) -> V_87 ;
}
F_64 ( & V_2 -> V_12 , V_77 , V_84 ) ;
F_65 ( & V_2 -> V_12 , V_59 ) ;
}
void F_66 ( struct V_29 * V_59 , struct V_2 * V_2 )
{
F_40 ( & V_2 -> V_12 , V_59 ) ;
}
struct V_2 * F_67 ( struct V_29 * V_59 , T_1 V_79 )
{
struct V_12 * * V_84 = & V_59 -> V_12 ;
struct V_12 * V_77 = NULL ;
struct V_2 * V_85 ;
while ( * V_84 != NULL ) {
V_77 = * V_84 ;
V_85 = F_14 ( V_77 , struct V_2 , V_12 ) ;
if ( V_79 < V_85 -> V_4 )
V_84 = & ( * V_84 ) -> V_86 ;
else if ( V_79 > V_85 -> V_5 )
V_84 = & ( * V_84 ) -> V_87 ;
else
return V_85 ;
}
return NULL ;
}
