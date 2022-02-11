static inline int F_1 ( const char * V_1 )
{
return strcmp ( V_1 , L_1 ) == 0 ;
}
static inline int F_2 ( const char * V_1 )
{
return ! strcmp ( V_1 , L_2 ) ||
! strcmp ( V_1 , L_3 ) ||
! strcmp ( V_1 , L_4 ) ;
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
}
struct V_2 * F_5 ( struct V_16 * V_17 , T_1 V_5 , T_1 V_18 ,
T_1 V_7 , T_2 V_19 , char * V_1 ,
enum V_4 type )
{
struct V_2 * V_3 = malloc ( sizeof( * V_3 ) ) ;
if ( V_3 != NULL ) {
char V_20 [ V_21 ] ;
struct V_8 * V_8 ;
int V_22 , V_23 ;
V_22 = F_1 ( V_1 ) ;
V_23 = F_2 ( V_1 ) ;
if ( V_22 ) {
snprintf ( V_20 , sizeof( V_20 ) , L_5 , V_19 ) ;
V_1 = V_20 ;
}
V_8 = F_6 ( V_17 , V_1 ) ;
if ( V_8 == NULL )
goto V_24;
F_3 ( V_3 , type , V_5 , V_5 + V_18 , V_7 , V_8 ) ;
if ( V_22 || V_23 ) {
V_3 -> V_9 = V_3 -> V_11 = V_25 ;
if ( V_23 )
F_7 ( V_8 , V_3 -> type ) ;
}
}
return V_3 ;
V_24:
free ( V_3 ) ;
return NULL ;
}
void F_8 ( struct V_2 * V_3 )
{
free ( V_3 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_26 * V_27 = & V_3 -> V_8 -> V_27 [ V_3 -> type ] ;
struct V_13 * V_28 = F_10 ( V_27 ) ;
if ( V_28 != NULL ) {
struct V_29 * V_30 = F_11 ( V_28 , struct V_29 , V_13 ) ;
V_3 -> V_5 = V_30 -> V_5 ;
}
}
void F_12 ( struct V_2 * V_3 )
{
struct V_26 * V_27 = & V_3 -> V_8 -> V_27 [ V_3 -> type ] ;
struct V_13 * V_28 = F_13 ( V_27 ) ;
if ( V_28 != NULL ) {
struct V_29 * V_30 = F_11 ( V_28 , struct V_29 , V_13 ) ;
V_3 -> V_6 = V_30 -> V_6 ;
}
}
int F_14 ( struct V_2 * V_3 , T_3 V_31 )
{
const char * V_32 = V_3 -> V_8 -> V_33 ;
int V_34 ;
if ( F_15 ( V_3 -> V_8 , V_3 -> type ) )
return 0 ;
V_34 = F_16 ( V_3 -> V_8 , V_3 , V_31 ) ;
if ( V_34 < 0 ) {
if ( V_3 -> V_8 -> V_35 ) {
char V_36 [ V_37 * 2 + 1 ] ;
F_17 ( V_3 -> V_8 -> V_38 ,
sizeof( V_3 -> V_8 -> V_38 ) ,
V_36 ) ;
F_18 ( L_6 ,
V_32 , V_36 ) ;
} else
F_18 ( L_7 , V_32 ) ;
F_18 ( L_8 ) ;
return - 1 ;
} else if ( V_34 == 0 ) {
const T_4 V_18 = strlen ( V_32 ) ;
const T_4 V_39 = V_18 - sizeof( V_40 ) ;
if ( V_18 > sizeof( V_40 ) &&
strcmp ( V_32 + V_39 + 1 , V_40 ) == 0 ) {
F_18 ( L_9
L_10 ,
( int ) V_39 , V_32 ) ;
} else {
F_18 ( L_11
L_12 , V_32 ) ;
}
return - 1 ;
}
if ( V_3 -> V_8 -> V_41 )
F_19 ( V_3 ) ;
return 0 ;
}
struct V_29 * F_20 ( struct V_2 * V_3 , T_1 V_42 ,
T_3 V_31 )
{
if ( F_14 ( V_3 , V_31 ) < 0 )
return NULL ;
return F_21 ( V_3 -> V_8 , V_3 -> type , V_42 ) ;
}
struct V_29 * F_22 ( struct V_2 * V_3 , const char * V_32 ,
T_3 V_31 )
{
if ( F_14 ( V_3 , V_31 ) < 0 )
return NULL ;
if ( ! F_23 ( V_3 -> V_8 , V_3 -> type ) )
F_24 ( V_3 -> V_8 , V_3 -> type ) ;
return F_25 ( V_3 -> V_8 , V_3 -> type , V_32 ) ;
}
struct V_2 * F_26 ( struct V_2 * V_3 )
{
struct V_2 * V_2 = malloc ( sizeof( * V_3 ) ) ;
if ( ! V_2 )
return NULL ;
memcpy ( V_2 , V_3 , sizeof( * V_3 ) ) ;
return V_2 ;
}
int F_27 ( struct V_2 * V_43 , struct V_2 * V_44 )
{
if ( V_43 -> V_5 > V_44 -> V_5 ) {
struct V_2 * V_45 = V_43 ;
V_43 = V_44 ;
V_44 = V_45 ;
}
if ( V_43 -> V_6 > V_44 -> V_5 )
return 1 ;
return 0 ;
}
T_4 F_28 ( struct V_2 * V_3 , T_5 * V_46 )
{
return fprintf ( V_46 , L_13 V_47 L_14 V_47 L_13 V_47 L_15 ,
V_3 -> V_5 , V_3 -> V_6 , V_3 -> V_7 , V_3 -> V_8 -> V_32 ) ;
}
T_1 F_29 ( struct V_2 * V_2 , T_1 V_48 )
{
T_1 V_42 = V_2 -> V_8 -> V_49 ?
V_2 -> V_11 ( V_2 , V_48 ) :
V_48 ;
return V_42 ;
}
T_1 F_30 ( struct V_2 * V_2 , T_1 V_42 )
{
T_1 V_50 = V_2 -> V_8 -> V_49 ?
V_42 :
V_2 -> V_11 ( V_2 , V_42 ) ;
return V_50 ;
}
void F_31 ( struct V_51 * V_52 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_54 ; ++ V_53 ) {
V_52 -> V_55 [ V_53 ] = V_56 ;
F_32 ( & V_52 -> V_57 [ V_53 ] ) ;
}
V_52 -> V_58 = NULL ;
}
static void F_33 ( struct V_26 * V_55 )
{
struct V_13 * V_59 = F_10 ( V_55 ) ;
while ( V_59 ) {
struct V_2 * V_60 = F_11 ( V_59 , struct V_2 , V_13 ) ;
V_59 = F_34 ( & V_60 -> V_13 ) ;
F_35 ( & V_60 -> V_13 , V_55 ) ;
F_8 ( V_60 ) ;
}
}
static void F_36 ( struct V_16 * V_55 )
{
struct V_2 * V_60 , * V_61 ;
F_37 (pos, n, maps, node) {
F_38 ( & V_60 -> V_62 ) ;
F_8 ( V_60 ) ;
}
}
void F_39 ( struct V_51 * V_52 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_54 ; ++ V_53 ) {
F_33 ( & V_52 -> V_55 [ V_53 ] ) ;
F_36 ( & V_52 -> V_57 [ V_53 ] ) ;
}
}
void F_40 ( struct V_51 * V_52 )
{
int type ;
for ( type = 0 ; type < V_54 ; type ++ ) {
struct V_26 * V_63 = & V_52 -> V_55 [ type ] ;
struct V_13 * V_59 = F_10 ( V_63 ) ;
while ( V_59 ) {
struct V_2 * V_60 = F_11 ( V_59 , struct V_2 , V_13 ) ;
V_59 = F_34 ( & V_60 -> V_13 ) ;
F_35 ( & V_60 -> V_13 , V_63 ) ;
F_41 ( & V_60 -> V_62 , & V_52 -> V_57 [ V_60 -> type ] ) ;
}
}
}
struct V_29 * F_42 ( struct V_51 * V_52 ,
enum V_4 type , T_1 V_42 ,
struct V_2 * * V_64 ,
T_3 V_31 )
{
struct V_2 * V_2 = F_43 ( V_52 , type , V_42 ) ;
if ( V_2 != NULL ) {
if ( V_64 != NULL )
* V_64 = V_2 ;
return F_20 ( V_2 , V_2 -> V_9 ( V_2 , V_42 ) , V_31 ) ;
}
return NULL ;
}
struct V_29 * F_44 ( struct V_51 * V_52 ,
enum V_4 type ,
const char * V_32 ,
struct V_2 * * V_64 ,
T_3 V_31 )
{
struct V_13 * V_28 ;
for ( V_28 = F_10 ( & V_52 -> V_55 [ type ] ) ; V_28 ; V_28 = F_34 ( V_28 ) ) {
struct V_2 * V_60 = F_11 ( V_28 , struct V_2 , V_13 ) ;
struct V_29 * V_30 = F_22 ( V_60 , V_32 , V_31 ) ;
if ( V_30 == NULL )
continue;
if ( V_64 != NULL )
* V_64 = V_60 ;
return V_30 ;
}
return NULL ;
}
T_4 F_45 ( struct V_51 * V_52 ,
enum V_4 type , int V_65 , T_5 * V_46 )
{
T_4 V_66 = fprintf ( V_46 , L_16 , V_67 [ type ] ) ;
struct V_13 * V_28 ;
for ( V_28 = F_10 ( & V_52 -> V_55 [ type ] ) ; V_28 ; V_28 = F_34 ( V_28 ) ) {
struct V_2 * V_60 = F_11 ( V_28 , struct V_2 , V_13 ) ;
V_66 += fprintf ( V_46 , L_17 ) ;
V_66 += F_28 ( V_60 , V_46 ) ;
if ( V_65 > 2 ) {
V_66 += F_46 ( V_60 -> V_8 , type , V_46 ) ;
V_66 += fprintf ( V_46 , L_18 ) ;
}
}
return V_66 ;
}
T_4 F_47 ( struct V_51 * V_52 , int V_65 , T_5 * V_46 )
{
T_4 V_66 = 0 , V_53 ;
for ( V_53 = 0 ; V_53 < V_54 ; ++ V_53 )
V_66 += F_45 ( V_52 , V_53 , V_65 , V_46 ) ;
return V_66 ;
}
static T_4 F_48 ( struct V_51 * V_52 ,
enum V_4 type ,
int V_65 , T_5 * V_46 )
{
struct V_2 * V_60 ;
T_4 V_66 = 0 ;
F_49 (pos, &mg->removed_maps[type], node) {
V_66 += fprintf ( V_46 , L_17 ) ;
V_66 += F_28 ( V_60 , V_46 ) ;
if ( V_65 > 1 ) {
V_66 += F_46 ( V_60 -> V_8 , type , V_46 ) ;
V_66 += fprintf ( V_46 , L_18 ) ;
}
}
return V_66 ;
}
static T_4 F_50 ( struct V_51 * V_52 ,
int V_65 , T_5 * V_46 )
{
T_4 V_66 = 0 , V_53 ;
for ( V_53 = 0 ; V_53 < V_54 ; ++ V_53 )
V_66 += F_48 ( V_52 , V_53 , V_65 , V_46 ) ;
return V_66 ;
}
T_4 F_51 ( struct V_51 * V_52 , int V_65 , T_5 * V_46 )
{
T_4 V_66 = F_47 ( V_52 , V_65 , V_46 ) ;
V_66 += fprintf ( V_46 , L_19 ) ;
return V_66 + F_50 ( V_52 , V_65 , V_46 ) ;
}
int F_52 ( struct V_51 * V_52 , struct V_2 * V_2 ,
int V_65 , T_5 * V_46 )
{
struct V_26 * V_63 = & V_52 -> V_55 [ V_2 -> type ] ;
struct V_13 * V_59 = F_10 ( V_63 ) ;
int V_68 = 0 ;
while ( V_59 ) {
struct V_2 * V_60 = F_11 ( V_59 , struct V_2 , V_13 ) ;
V_59 = F_34 ( & V_60 -> V_13 ) ;
if ( ! F_27 ( V_60 , V_2 ) )
continue;
if ( V_65 >= 2 ) {
fputs ( L_20 , V_46 ) ;
F_28 ( V_2 , V_46 ) ;
F_28 ( V_60 , V_46 ) ;
}
F_35 ( & V_60 -> V_13 , V_63 ) ;
if ( V_2 -> V_5 > V_60 -> V_5 ) {
struct V_2 * V_69 = F_26 ( V_60 ) ;
if ( V_69 == NULL ) {
V_68 = - V_70 ;
goto V_71;
}
V_69 -> V_6 = V_2 -> V_5 - 1 ;
F_53 ( V_52 , V_69 ) ;
if ( V_65 >= 2 )
F_28 ( V_69 , V_46 ) ;
}
if ( V_2 -> V_6 < V_60 -> V_6 ) {
struct V_2 * V_72 = F_26 ( V_60 ) ;
if ( V_72 == NULL ) {
V_68 = - V_70 ;
goto V_71;
}
V_72 -> V_5 = V_2 -> V_6 + 1 ;
F_53 ( V_52 , V_72 ) ;
if ( V_65 >= 2 )
F_28 ( V_72 , V_46 ) ;
}
V_71:
if ( V_60 -> V_15 )
F_41 ( & V_60 -> V_62 , & V_52 -> V_57 [ V_2 -> type ] ) ;
else
F_8 ( V_60 ) ;
if ( V_68 )
return V_68 ;
}
return 0 ;
}
int F_54 ( struct V_51 * V_52 ,
struct V_51 * V_73 , enum V_4 type )
{
struct V_13 * V_28 ;
for ( V_28 = F_10 ( & V_73 -> V_55 [ type ] ) ; V_28 ; V_28 = F_34 ( V_28 ) ) {
struct V_2 * V_2 = F_11 ( V_28 , struct V_2 , V_13 ) ;
struct V_2 * V_74 = F_26 ( V_2 ) ;
if ( V_74 == NULL )
return - V_70 ;
F_53 ( V_52 , V_74 ) ;
}
return 0 ;
}
static T_1 F_55 ( struct V_2 * V_2 , T_1 V_50 )
{
return V_50 + ( V_75 ) V_2 -> V_7 ;
}
static T_1 F_56 ( struct V_2 * V_2 , T_1 V_50 )
{
return V_50 - ( V_75 ) V_2 -> V_7 ;
}
void F_19 ( struct V_2 * V_3 )
{
struct V_76 * V_76 = F_57 ( V_3 ) ;
V_75 V_77 ;
if ( ! V_76 -> V_78 || ! V_76 -> V_78 -> V_79 )
return;
V_77 = ( V_76 -> V_78 -> V_79 -
V_76 -> V_78 -> V_42 ) ;
if ( ! V_77 )
return;
V_3 -> V_9 = F_55 ;
V_3 -> V_11 = F_56 ;
V_3 -> V_7 = V_77 ;
}
void F_58 ( struct V_26 * V_55 , struct V_2 * V_2 )
{
struct V_13 * * V_80 = & V_55 -> V_13 ;
struct V_13 * V_73 = NULL ;
const T_1 V_50 = V_2 -> V_5 ;
struct V_2 * V_81 ;
while ( * V_80 != NULL ) {
V_73 = * V_80 ;
V_81 = F_11 ( V_73 , struct V_2 , V_13 ) ;
if ( V_50 < V_81 -> V_5 )
V_80 = & ( * V_80 ) -> V_82 ;
else
V_80 = & ( * V_80 ) -> V_83 ;
}
F_59 ( & V_2 -> V_13 , V_73 , V_80 ) ;
F_60 ( & V_2 -> V_13 , V_55 ) ;
}
void F_61 ( struct V_26 * V_3 , struct V_2 * V_2 )
{
F_35 ( & V_2 -> V_13 , V_3 ) ;
}
struct V_2 * F_62 ( struct V_26 * V_55 , T_1 V_50 )
{
struct V_13 * * V_80 = & V_55 -> V_13 ;
struct V_13 * V_73 = NULL ;
struct V_2 * V_81 ;
while ( * V_80 != NULL ) {
V_73 = * V_80 ;
V_81 = F_11 ( V_73 , struct V_2 , V_13 ) ;
if ( V_50 < V_81 -> V_5 )
V_80 = & ( * V_80 ) -> V_82 ;
else if ( V_50 > V_81 -> V_6 )
V_80 = & ( * V_80 ) -> V_83 ;
else
return V_81 ;
}
return NULL ;
}
int F_63 ( struct V_58 * V_3 , const char * V_84 , T_6 V_19 )
{
F_31 ( & V_3 -> V_85 ) ;
F_4 ( & V_3 -> V_13 ) ;
F_32 ( & V_3 -> V_86 ) ;
F_32 ( & V_3 -> V_87 ) ;
V_3 -> V_85 . V_58 = V_3 ;
V_3 -> V_19 = V_19 ;
V_3 -> V_84 = F_64 ( V_84 ) ;
return V_3 -> V_84 == NULL ? - V_70 : 0 ;
}
static void F_65 ( struct V_16 * V_3 )
{
struct V_8 * V_60 , * V_61 ;
F_37 (pos, n, self, node) {
F_38 ( & V_60 -> V_62 ) ;
F_66 ( V_60 ) ;
}
}
void F_67 ( struct V_58 * V_3 )
{
F_39 ( & V_3 -> V_85 ) ;
F_65 ( & V_3 -> V_86 ) ;
F_65 ( & V_3 -> V_87 ) ;
free ( V_3 -> V_84 ) ;
V_3 -> V_84 = NULL ;
}
void F_68 ( struct V_58 * V_3 )
{
F_67 ( V_3 ) ;
free ( V_3 ) ;
}
struct V_58 * F_69 ( struct V_26 * V_3 , T_6 V_19 ,
const char * V_84 )
{
struct V_13 * * V_80 = & V_3 -> V_13 ;
struct V_13 * V_73 = NULL ;
struct V_58 * V_60 , * V_58 = malloc ( sizeof( * V_58 ) ) ;
if ( ! V_58 )
return NULL ;
if ( F_63 ( V_58 , V_84 , V_19 ) != 0 ) {
free ( V_58 ) ;
return NULL ;
}
while ( * V_80 != NULL ) {
V_73 = * V_80 ;
V_60 = F_11 ( V_73 , struct V_58 , V_13 ) ;
if ( V_19 < V_60 -> V_19 )
V_80 = & ( * V_80 ) -> V_82 ;
else
V_80 = & ( * V_80 ) -> V_83 ;
}
F_59 ( & V_58 -> V_13 , V_73 , V_80 ) ;
F_60 ( & V_58 -> V_13 , V_3 ) ;
return V_58 ;
}
struct V_58 * F_70 ( struct V_26 * V_3 , T_6 V_19 )
{
struct V_13 * * V_80 = & V_3 -> V_13 ;
struct V_13 * V_73 = NULL ;
struct V_58 * V_58 ;
struct V_58 * V_88 = NULL ;
while ( * V_80 != NULL ) {
V_73 = * V_80 ;
V_58 = F_11 ( V_73 , struct V_58 , V_13 ) ;
if ( V_19 < V_58 -> V_19 )
V_80 = & ( * V_80 ) -> V_82 ;
else if ( V_19 > V_58 -> V_19 )
V_80 = & ( * V_80 ) -> V_83 ;
else
return V_58 ;
if ( ! V_58 -> V_19 )
V_88 = V_58 ;
}
return V_88 ;
}
struct V_58 * F_71 ( struct V_26 * V_3 , T_6 V_19 )
{
char V_89 [ V_21 ] ;
const char * V_84 ;
struct V_58 * V_58 = F_70 ( V_3 , V_19 ) ;
if ( ! V_58 || V_58 -> V_19 != V_19 ) {
if ( V_19 == V_90 || V_19 == V_91 )
V_84 = L_21 ;
else {
if ( ! V_92 . V_93 )
goto V_94;
sprintf ( V_89 , L_22 , V_92 . V_93 , V_19 ) ;
if ( F_72 ( V_89 , V_95 ) ) {
F_73 ( L_23 , V_89 ) ;
goto V_94;
}
V_84 = V_89 ;
}
V_58 = F_69 ( V_3 , V_19 , V_84 ) ;
}
V_94:
return V_58 ;
}
void F_74 ( struct V_26 * V_3 , T_7 V_96 , void * V_97 )
{
struct V_13 * V_28 ;
for ( V_28 = F_10 ( V_3 ) ; V_28 ; V_28 = F_34 ( V_28 ) ) {
struct V_58 * V_60 = F_11 ( V_28 , struct V_58 , V_13 ) ;
V_96 ( V_60 , V_97 ) ;
}
}
char * F_75 ( struct V_58 * V_3 , char * V_98 , T_4 V_99 )
{
if ( F_76 ( V_3 ) )
snprintf ( V_98 , V_99 , L_24 , L_25 ) ;
else if ( F_77 ( V_3 ) )
snprintf ( V_98 , V_99 , L_24 , L_26 ) ;
else
snprintf ( V_98 , V_99 , L_27 , L_26 , V_3 -> V_19 ) ;
return V_98 ;
}
