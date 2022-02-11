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
int V_23 , V_24 ;
V_23 = F_1 ( V_1 ) ;
V_24 = F_2 ( V_1 ) ;
if ( V_23 ) {
snprintf ( V_21 , sizeof( V_21 ) , L_5 , V_20 ) ;
V_1 = V_21 ;
}
V_8 = F_6 ( V_18 , V_1 ) ;
if ( V_8 == NULL )
goto V_25;
F_3 ( V_3 , type , V_5 , V_5 + V_19 , V_7 , V_8 ) ;
if ( V_23 || V_24 ) {
V_3 -> V_9 = V_3 -> V_11 = V_26 ;
if ( V_24 )
F_7 ( V_8 , V_3 -> type ) ;
}
}
return V_3 ;
V_25:
free ( V_3 ) ;
return NULL ;
}
void F_8 ( struct V_2 * V_3 )
{
free ( V_3 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = & V_3 -> V_8 -> V_28 [ V_3 -> type ] ;
struct V_13 * V_29 = F_10 ( V_28 ) ;
if ( V_29 != NULL ) {
struct V_30 * V_31 = F_11 ( V_29 , struct V_30 , V_13 ) ;
V_3 -> V_5 = V_31 -> V_5 ;
}
}
void F_12 ( struct V_2 * V_3 )
{
struct V_27 * V_28 = & V_3 -> V_8 -> V_28 [ V_3 -> type ] ;
struct V_13 * V_29 = F_13 ( V_28 ) ;
if ( V_29 != NULL ) {
struct V_30 * V_31 = F_11 ( V_29 , struct V_30 , V_13 ) ;
V_3 -> V_6 = V_31 -> V_6 ;
}
}
int F_14 ( struct V_2 * V_3 , T_3 V_32 )
{
const char * V_33 = V_3 -> V_8 -> V_34 ;
int V_35 ;
if ( F_15 ( V_3 -> V_8 , V_3 -> type ) )
return 0 ;
V_35 = F_16 ( V_3 -> V_8 , V_3 , V_32 ) ;
if ( V_35 < 0 ) {
if ( V_3 -> V_8 -> V_36 ) {
char V_37 [ V_38 * 2 + 1 ] ;
F_17 ( V_3 -> V_8 -> V_39 ,
sizeof( V_3 -> V_8 -> V_39 ) ,
V_37 ) ;
F_18 ( L_6 ,
V_33 , V_37 ) ;
} else
F_18 ( L_7 , V_33 ) ;
F_18 ( L_8 ) ;
return - 1 ;
} else if ( V_35 == 0 ) {
const T_4 V_19 = strlen ( V_33 ) ;
const T_4 V_40 = V_19 - sizeof( V_41 ) ;
if ( V_19 > sizeof( V_41 ) &&
strcmp ( V_33 + V_40 + 1 , V_41 ) == 0 ) {
F_18 ( L_9
L_10 ,
( int ) V_40 , V_33 ) ;
} else {
F_18 ( L_11
L_12 , V_33 ) ;
}
return - 1 ;
}
if ( V_3 -> V_8 -> V_42 )
F_19 ( V_3 ) ;
return 0 ;
}
struct V_30 * F_20 ( struct V_2 * V_3 , T_1 V_43 ,
T_3 V_32 )
{
if ( F_14 ( V_3 , V_32 ) < 0 )
return NULL ;
return F_21 ( V_3 -> V_8 , V_3 -> type , V_43 ) ;
}
struct V_30 * F_22 ( struct V_2 * V_3 , const char * V_33 ,
T_3 V_32 )
{
if ( F_14 ( V_3 , V_32 ) < 0 )
return NULL ;
if ( ! F_23 ( V_3 -> V_8 , V_3 -> type ) )
F_24 ( V_3 -> V_8 , V_3 -> type ) ;
return F_25 ( V_3 -> V_8 , V_3 -> type , V_33 ) ;
}
struct V_2 * F_26 ( struct V_2 * V_3 )
{
struct V_2 * V_2 = malloc ( sizeof( * V_3 ) ) ;
if ( ! V_2 )
return NULL ;
memcpy ( V_2 , V_3 , sizeof( * V_3 ) ) ;
return V_2 ;
}
int F_27 ( struct V_2 * V_44 , struct V_2 * V_45 )
{
if ( V_44 -> V_5 > V_45 -> V_5 ) {
struct V_2 * V_46 = V_44 ;
V_44 = V_45 ;
V_45 = V_46 ;
}
if ( V_44 -> V_6 > V_45 -> V_5 )
return 1 ;
return 0 ;
}
T_4 F_28 ( struct V_2 * V_3 , T_5 * V_47 )
{
return fprintf ( V_47 , L_13 V_48 L_14 V_48 L_13 V_48 L_15 ,
V_3 -> V_5 , V_3 -> V_6 , V_3 -> V_7 , V_3 -> V_8 -> V_33 ) ;
}
T_4 F_29 ( struct V_2 * V_2 , T_5 * V_47 )
{
const char * V_49 ;
if ( V_2 && V_2 -> V_8 && ( V_2 -> V_8 -> V_33 || V_2 -> V_8 -> V_34 ) ) {
if ( V_50 . V_51 && V_2 -> V_8 -> V_34 )
V_49 = V_2 -> V_8 -> V_34 ;
else if ( V_2 -> V_8 -> V_33 )
V_49 = V_2 -> V_8 -> V_33 ;
} else
V_49 = L_16 ;
return fprintf ( V_47 , L_17 , V_49 ) ;
}
T_1 F_30 ( struct V_2 * V_2 , T_1 V_52 )
{
T_1 V_43 = V_2 -> V_8 -> V_53 ?
V_2 -> V_11 ( V_2 , V_52 ) :
V_52 ;
return V_43 ;
}
T_1 F_31 ( struct V_2 * V_2 , T_1 V_43 )
{
T_1 V_54 = V_2 -> V_8 -> V_53 ?
V_43 :
V_2 -> V_11 ( V_2 , V_43 ) ;
return V_54 ;
}
void F_32 ( struct V_55 * V_56 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; ++ V_57 ) {
V_56 -> V_59 [ V_57 ] = V_60 ;
F_33 ( & V_56 -> V_61 [ V_57 ] ) ;
}
V_56 -> V_62 = NULL ;
}
static void F_34 ( struct V_27 * V_59 )
{
struct V_13 * V_63 = F_10 ( V_59 ) ;
while ( V_63 ) {
struct V_2 * V_64 = F_11 ( V_63 , struct V_2 , V_13 ) ;
V_63 = F_35 ( & V_64 -> V_13 ) ;
F_36 ( & V_64 -> V_13 , V_59 ) ;
F_8 ( V_64 ) ;
}
}
static void F_37 ( struct V_17 * V_59 )
{
struct V_2 * V_64 , * V_65 ;
F_38 (pos, n, maps, node) {
F_39 ( & V_64 -> V_66 ) ;
F_8 ( V_64 ) ;
}
}
void F_40 ( struct V_55 * V_56 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; ++ V_57 ) {
F_34 ( & V_56 -> V_59 [ V_57 ] ) ;
F_37 ( & V_56 -> V_61 [ V_57 ] ) ;
}
}
void F_41 ( struct V_55 * V_56 )
{
int type ;
for ( type = 0 ; type < V_58 ; type ++ ) {
struct V_27 * V_67 = & V_56 -> V_59 [ type ] ;
struct V_13 * V_63 = F_10 ( V_67 ) ;
while ( V_63 ) {
struct V_2 * V_64 = F_11 ( V_63 , struct V_2 , V_13 ) ;
V_63 = F_35 ( & V_64 -> V_13 ) ;
F_36 ( & V_64 -> V_13 , V_67 ) ;
F_42 ( & V_64 -> V_66 , & V_56 -> V_61 [ V_64 -> type ] ) ;
}
}
}
struct V_30 * F_43 ( struct V_55 * V_56 ,
enum V_4 type , T_1 V_43 ,
struct V_2 * * V_68 ,
T_3 V_32 )
{
struct V_2 * V_2 = F_44 ( V_56 , type , V_43 ) ;
if ( V_2 != NULL ) {
if ( V_68 != NULL )
* V_68 = V_2 ;
return F_20 ( V_2 , V_2 -> V_9 ( V_2 , V_43 ) , V_32 ) ;
}
return NULL ;
}
struct V_30 * F_45 ( struct V_55 * V_56 ,
enum V_4 type ,
const char * V_33 ,
struct V_2 * * V_68 ,
T_3 V_32 )
{
struct V_13 * V_29 ;
for ( V_29 = F_10 ( & V_56 -> V_59 [ type ] ) ; V_29 ; V_29 = F_35 ( V_29 ) ) {
struct V_2 * V_64 = F_11 ( V_29 , struct V_2 , V_13 ) ;
struct V_30 * V_31 = F_22 ( V_64 , V_33 , V_32 ) ;
if ( V_31 == NULL )
continue;
if ( V_68 != NULL )
* V_68 = V_64 ;
return V_31 ;
}
return NULL ;
}
T_4 F_46 ( struct V_55 * V_56 ,
enum V_4 type , int V_69 , T_5 * V_47 )
{
T_4 V_70 = fprintf ( V_47 , L_18 , V_71 [ type ] ) ;
struct V_13 * V_29 ;
for ( V_29 = F_10 ( & V_56 -> V_59 [ type ] ) ; V_29 ; V_29 = F_35 ( V_29 ) ) {
struct V_2 * V_64 = F_11 ( V_29 , struct V_2 , V_13 ) ;
V_70 += fprintf ( V_47 , L_19 ) ;
V_70 += F_28 ( V_64 , V_47 ) ;
if ( V_69 > 2 ) {
V_70 += F_47 ( V_64 -> V_8 , type , V_47 ) ;
V_70 += fprintf ( V_47 , L_20 ) ;
}
}
return V_70 ;
}
T_4 F_48 ( struct V_55 * V_56 , int V_69 , T_5 * V_47 )
{
T_4 V_70 = 0 , V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; ++ V_57 )
V_70 += F_46 ( V_56 , V_57 , V_69 , V_47 ) ;
return V_70 ;
}
static T_4 F_49 ( struct V_55 * V_56 ,
enum V_4 type ,
int V_69 , T_5 * V_47 )
{
struct V_2 * V_64 ;
T_4 V_70 = 0 ;
F_50 (pos, &mg->removed_maps[type], node) {
V_70 += fprintf ( V_47 , L_19 ) ;
V_70 += F_28 ( V_64 , V_47 ) ;
if ( V_69 > 1 ) {
V_70 += F_47 ( V_64 -> V_8 , type , V_47 ) ;
V_70 += fprintf ( V_47 , L_20 ) ;
}
}
return V_70 ;
}
static T_4 F_51 ( struct V_55 * V_56 ,
int V_69 , T_5 * V_47 )
{
T_4 V_70 = 0 , V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; ++ V_57 )
V_70 += F_49 ( V_56 , V_57 , V_69 , V_47 ) ;
return V_70 ;
}
T_4 F_52 ( struct V_55 * V_56 , int V_69 , T_5 * V_47 )
{
T_4 V_70 = F_48 ( V_56 , V_69 , V_47 ) ;
V_70 += fprintf ( V_47 , L_21 ) ;
return V_70 + F_51 ( V_56 , V_69 , V_47 ) ;
}
int F_53 ( struct V_55 * V_56 , struct V_2 * V_2 ,
int V_69 , T_5 * V_47 )
{
struct V_27 * V_67 = & V_56 -> V_59 [ V_2 -> type ] ;
struct V_13 * V_63 = F_10 ( V_67 ) ;
int V_72 = 0 ;
while ( V_63 ) {
struct V_2 * V_64 = F_11 ( V_63 , struct V_2 , V_13 ) ;
V_63 = F_35 ( & V_64 -> V_13 ) ;
if ( ! F_27 ( V_64 , V_2 ) )
continue;
if ( V_69 >= 2 ) {
fputs ( L_22 , V_47 ) ;
F_28 ( V_2 , V_47 ) ;
F_28 ( V_64 , V_47 ) ;
}
F_36 ( & V_64 -> V_13 , V_67 ) ;
if ( V_2 -> V_5 > V_64 -> V_5 ) {
struct V_2 * V_73 = F_26 ( V_64 ) ;
if ( V_73 == NULL ) {
V_72 = - V_74 ;
goto V_75;
}
V_73 -> V_6 = V_2 -> V_5 - 1 ;
F_54 ( V_56 , V_73 ) ;
if ( V_69 >= 2 )
F_28 ( V_73 , V_47 ) ;
}
if ( V_2 -> V_6 < V_64 -> V_6 ) {
struct V_2 * V_76 = F_26 ( V_64 ) ;
if ( V_76 == NULL ) {
V_72 = - V_74 ;
goto V_75;
}
V_76 -> V_5 = V_2 -> V_6 + 1 ;
F_54 ( V_56 , V_76 ) ;
if ( V_69 >= 2 )
F_28 ( V_76 , V_47 ) ;
}
V_75:
if ( V_64 -> V_15 )
F_42 ( & V_64 -> V_66 , & V_56 -> V_61 [ V_2 -> type ] ) ;
else
F_8 ( V_64 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
int F_55 ( struct V_55 * V_56 ,
struct V_55 * V_77 , enum V_4 type )
{
struct V_13 * V_29 ;
for ( V_29 = F_10 ( & V_77 -> V_59 [ type ] ) ; V_29 ; V_29 = F_35 ( V_29 ) ) {
struct V_2 * V_2 = F_11 ( V_29 , struct V_2 , V_13 ) ;
struct V_2 * V_78 = F_26 ( V_2 ) ;
if ( V_78 == NULL )
return - V_74 ;
F_54 ( V_56 , V_78 ) ;
}
return 0 ;
}
static T_1 F_56 ( struct V_2 * V_2 , T_1 V_54 )
{
return V_54 + ( V_79 ) V_2 -> V_7 ;
}
static T_1 F_57 ( struct V_2 * V_2 , T_1 V_54 )
{
return V_54 - ( V_79 ) V_2 -> V_7 ;
}
void F_19 ( struct V_2 * V_3 )
{
struct V_80 * V_80 = F_58 ( V_3 ) ;
V_79 V_81 ;
if ( ! V_80 -> V_82 || ! V_80 -> V_82 -> V_83 )
return;
V_81 = ( V_80 -> V_82 -> V_83 -
V_80 -> V_82 -> V_43 ) ;
if ( ! V_81 )
return;
V_3 -> V_9 = F_56 ;
V_3 -> V_11 = F_57 ;
V_3 -> V_7 = V_81 ;
}
void F_59 ( struct V_27 * V_59 , struct V_2 * V_2 )
{
struct V_13 * * V_84 = & V_59 -> V_13 ;
struct V_13 * V_77 = NULL ;
const T_1 V_54 = V_2 -> V_5 ;
struct V_2 * V_85 ;
while ( * V_84 != NULL ) {
V_77 = * V_84 ;
V_85 = F_11 ( V_77 , struct V_2 , V_13 ) ;
if ( V_54 < V_85 -> V_5 )
V_84 = & ( * V_84 ) -> V_86 ;
else
V_84 = & ( * V_84 ) -> V_87 ;
}
F_60 ( & V_2 -> V_13 , V_77 , V_84 ) ;
F_61 ( & V_2 -> V_13 , V_59 ) ;
}
void F_62 ( struct V_27 * V_3 , struct V_2 * V_2 )
{
F_36 ( & V_2 -> V_13 , V_3 ) ;
}
struct V_2 * F_63 ( struct V_27 * V_59 , T_1 V_54 )
{
struct V_13 * * V_84 = & V_59 -> V_13 ;
struct V_13 * V_77 = NULL ;
struct V_2 * V_85 ;
while ( * V_84 != NULL ) {
V_77 = * V_84 ;
V_85 = F_11 ( V_77 , struct V_2 , V_13 ) ;
if ( V_54 < V_85 -> V_5 )
V_84 = & ( * V_84 ) -> V_86 ;
else if ( V_54 > V_85 -> V_6 )
V_84 = & ( * V_84 ) -> V_87 ;
else
return V_85 ;
}
return NULL ;
}
int F_64 ( struct V_62 * V_3 , const char * V_88 , T_6 V_20 )
{
F_32 ( & V_3 -> V_89 ) ;
F_4 ( & V_3 -> V_13 ) ;
F_33 ( & V_3 -> V_90 ) ;
F_33 ( & V_3 -> V_91 ) ;
V_3 -> V_92 = V_60 ;
F_33 ( & V_3 -> V_93 ) ;
V_3 -> V_94 = NULL ;
V_3 -> V_89 . V_62 = V_3 ;
V_3 -> V_20 = V_20 ;
V_3 -> V_88 = F_65 ( V_88 ) ;
return V_3 -> V_88 == NULL ? - V_74 : 0 ;
}
static void F_66 ( struct V_17 * V_3 )
{
struct V_8 * V_64 , * V_65 ;
F_38 (pos, n, self, node) {
F_39 ( & V_64 -> V_66 ) ;
F_67 ( V_64 ) ;
}
}
void F_68 ( struct V_62 * V_3 )
{
F_40 ( & V_3 -> V_89 ) ;
F_66 ( & V_3 -> V_90 ) ;
F_66 ( & V_3 -> V_91 ) ;
free ( V_3 -> V_88 ) ;
V_3 -> V_88 = NULL ;
}
void F_69 ( struct V_62 * V_3 )
{
F_68 ( V_3 ) ;
free ( V_3 ) ;
}
struct V_62 * F_70 ( struct V_27 * V_3 , T_6 V_20 ,
const char * V_88 )
{
struct V_13 * * V_84 = & V_3 -> V_13 ;
struct V_13 * V_77 = NULL ;
struct V_62 * V_64 , * V_62 = malloc ( sizeof( * V_62 ) ) ;
if ( ! V_62 )
return NULL ;
if ( F_64 ( V_62 , V_88 , V_20 ) != 0 ) {
free ( V_62 ) ;
return NULL ;
}
while ( * V_84 != NULL ) {
V_77 = * V_84 ;
V_64 = F_11 ( V_77 , struct V_62 , V_13 ) ;
if ( V_20 < V_64 -> V_20 )
V_84 = & ( * V_84 ) -> V_86 ;
else
V_84 = & ( * V_84 ) -> V_87 ;
}
F_60 ( & V_62 -> V_13 , V_77 , V_84 ) ;
F_61 ( & V_62 -> V_13 , V_3 ) ;
return V_62 ;
}
struct V_62 * F_71 ( struct V_27 * V_3 , T_6 V_20 )
{
struct V_13 * * V_84 = & V_3 -> V_13 ;
struct V_13 * V_77 = NULL ;
struct V_62 * V_62 ;
struct V_62 * V_95 = NULL ;
while ( * V_84 != NULL ) {
V_77 = * V_84 ;
V_62 = F_11 ( V_77 , struct V_62 , V_13 ) ;
if ( V_20 < V_62 -> V_20 )
V_84 = & ( * V_84 ) -> V_86 ;
else if ( V_20 > V_62 -> V_20 )
V_84 = & ( * V_84 ) -> V_87 ;
else
return V_62 ;
if ( ! V_62 -> V_20 )
V_95 = V_62 ;
}
return V_95 ;
}
struct V_62 * F_72 ( struct V_27 * V_3 , T_6 V_20 )
{
char V_96 [ V_22 ] ;
const char * V_88 = L_23 ;
struct V_62 * V_62 = F_71 ( V_3 , V_20 ) ;
if ( V_62 && ( V_62 -> V_20 == V_20 ) )
goto V_97;
if ( ( V_20 != V_98 ) &&
( V_20 != V_99 ) &&
( V_50 . V_100 ) ) {
sprintf ( V_96 , L_24 , V_50 . V_100 , V_20 ) ;
if ( F_73 ( V_96 , V_101 ) ) {
F_74 ( L_25 , V_96 ) ;
V_62 = NULL ;
goto V_97;
}
V_88 = V_96 ;
}
V_62 = F_70 ( V_3 , V_20 , V_88 ) ;
V_97:
return V_62 ;
}
void F_75 ( struct V_27 * V_3 , T_7 V_102 , void * V_103 )
{
struct V_13 * V_29 ;
for ( V_29 = F_10 ( V_3 ) ; V_29 ; V_29 = F_35 ( V_29 ) ) {
struct V_62 * V_64 = F_11 ( V_29 , struct V_62 , V_13 ) ;
V_102 ( V_64 , V_103 ) ;
}
}
char * F_76 ( struct V_62 * V_3 , char * V_104 , T_4 V_105 )
{
if ( F_77 ( V_3 ) )
snprintf ( V_104 , V_105 , L_26 , L_27 ) ;
else if ( F_78 ( V_3 ) )
snprintf ( V_104 , V_105 , L_26 , L_28 ) ;
else
snprintf ( V_104 , V_105 , L_29 , L_28 , V_3 -> V_20 ) ;
return V_104 ;
}
