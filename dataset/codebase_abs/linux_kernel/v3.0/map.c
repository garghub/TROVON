static inline int F_1 ( const char * V_1 )
{
return strcmp ( V_1 , L_1 ) == 0 ;
}
void F_2 ( struct V_2 * V_3 , enum V_4 type ,
T_1 V_5 , T_1 V_6 , T_1 V_7 , struct V_8 * V_8 )
{
V_3 -> type = type ;
V_3 -> V_5 = V_5 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_8 = V_8 ;
V_3 -> V_9 = V_10 ;
V_3 -> V_11 = V_12 ;
F_3 ( & V_3 -> V_13 ) ;
V_3 -> V_14 = NULL ;
V_3 -> V_15 = false ;
}
struct V_2 * F_4 ( struct V_16 * V_17 , T_1 V_5 , T_1 V_18 ,
T_1 V_7 , T_2 V_19 , char * V_1 ,
enum V_4 type )
{
struct V_2 * V_3 = malloc ( sizeof( * V_3 ) ) ;
if ( V_3 != NULL ) {
char V_20 [ V_21 ] ;
struct V_8 * V_8 ;
int V_22 ;
V_22 = F_1 ( V_1 ) ;
if ( V_22 ) {
snprintf ( V_20 , sizeof( V_20 ) , L_2 , V_19 ) ;
V_1 = V_20 ;
}
V_8 = F_5 ( V_17 , V_1 ) ;
if ( V_8 == NULL )
goto V_23;
F_2 ( V_3 , type , V_5 , V_5 + V_18 , V_7 , V_8 ) ;
if ( V_22 ) {
V_24:
V_3 -> V_9 = V_3 -> V_11 = V_25 ;
} else if ( strcmp ( V_1 , L_3 ) == 0 ) {
F_6 ( V_8 , V_3 -> type ) ;
goto V_24;
}
}
return V_3 ;
V_23:
free ( V_3 ) ;
return NULL ;
}
void F_7 ( struct V_2 * V_3 )
{
free ( V_3 ) ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_26 * V_27 = & V_3 -> V_8 -> V_27 [ V_3 -> type ] ;
struct V_13 * V_28 = F_9 ( V_27 ) ;
if ( V_28 != NULL ) {
struct V_29 * V_30 = F_10 ( V_28 , struct V_29 , V_13 ) ;
V_3 -> V_5 = V_30 -> V_5 ;
}
}
void F_11 ( struct V_2 * V_3 )
{
struct V_26 * V_27 = & V_3 -> V_8 -> V_27 [ V_3 -> type ] ;
struct V_13 * V_28 = F_12 ( V_27 ) ;
if ( V_28 != NULL ) {
struct V_29 * V_30 = F_10 ( V_28 , struct V_29 , V_13 ) ;
V_3 -> V_6 = V_30 -> V_6 ;
}
}
int F_13 ( struct V_2 * V_3 , T_3 V_31 )
{
const char * V_32 = V_3 -> V_8 -> V_33 ;
int V_34 ;
if ( F_14 ( V_3 -> V_8 , V_3 -> type ) )
return 0 ;
V_34 = F_15 ( V_3 -> V_8 , V_3 , V_31 ) ;
if ( V_34 < 0 ) {
if ( V_3 -> V_8 -> V_35 ) {
char V_36 [ V_37 * 2 + 1 ] ;
F_16 ( V_3 -> V_8 -> V_38 ,
sizeof( V_3 -> V_8 -> V_38 ) ,
V_36 ) ;
F_17 ( L_4 ,
V_32 , V_36 ) ;
} else
F_17 ( L_5 , V_32 ) ;
F_17 ( L_6 ) ;
return - 1 ;
} else if ( V_34 == 0 ) {
const T_4 V_18 = strlen ( V_32 ) ;
const T_4 V_39 = V_18 - sizeof( V_40 ) ;
if ( V_18 > sizeof( V_40 ) &&
strcmp ( V_32 + V_39 + 1 , V_40 ) == 0 ) {
F_17 ( L_7
L_8 ,
( int ) V_39 , V_32 ) ;
} else {
F_17 ( L_9
L_10 , V_32 ) ;
}
return - 1 ;
}
if ( V_3 -> V_8 -> V_41 )
F_18 ( V_3 ) ;
return 0 ;
}
struct V_29 * F_19 ( struct V_2 * V_3 , T_1 V_42 ,
T_3 V_31 )
{
if ( F_13 ( V_3 , V_31 ) < 0 )
return NULL ;
return F_20 ( V_3 -> V_8 , V_3 -> type , V_42 ) ;
}
struct V_29 * F_21 ( struct V_2 * V_3 , const char * V_32 ,
T_3 V_31 )
{
if ( F_13 ( V_3 , V_31 ) < 0 )
return NULL ;
if ( ! F_22 ( V_3 -> V_8 , V_3 -> type ) )
F_23 ( V_3 -> V_8 , V_3 -> type ) ;
return F_24 ( V_3 -> V_8 , V_3 -> type , V_32 ) ;
}
struct V_2 * F_25 ( struct V_2 * V_3 )
{
struct V_2 * V_2 = malloc ( sizeof( * V_3 ) ) ;
if ( ! V_2 )
return NULL ;
memcpy ( V_2 , V_3 , sizeof( * V_3 ) ) ;
return V_2 ;
}
int F_26 ( struct V_2 * V_43 , struct V_2 * V_44 )
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
T_4 F_27 ( struct V_2 * V_3 , T_5 * V_46 )
{
return fprintf ( V_46 , L_11 V_47 L_12 V_47 L_11 V_47 L_13 ,
V_3 -> V_5 , V_3 -> V_6 , V_3 -> V_7 , V_3 -> V_8 -> V_32 ) ;
}
T_1 F_28 ( struct V_2 * V_2 , T_1 V_48 )
{
T_1 V_42 = V_2 -> V_8 -> V_49 ?
V_2 -> V_11 ( V_2 , V_48 ) :
V_48 ;
return V_42 ;
}
T_1 F_29 ( struct V_2 * V_2 , T_1 V_42 )
{
T_1 V_50 = V_2 -> V_8 -> V_49 ?
V_42 :
V_2 -> V_11 ( V_2 , V_42 ) ;
return V_50 ;
}
void F_30 ( struct V_51 * V_3 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; ++ V_52 ) {
V_3 -> V_54 [ V_52 ] = V_55 ;
F_31 ( & V_3 -> V_56 [ V_52 ] ) ;
}
V_3 -> V_57 = NULL ;
}
static void F_32 ( struct V_26 * V_3 )
{
struct V_13 * V_58 = F_9 ( V_3 ) ;
while ( V_58 ) {
struct V_2 * V_59 = F_10 ( V_58 , struct V_2 , V_13 ) ;
V_58 = F_33 ( & V_59 -> V_13 ) ;
F_34 ( & V_59 -> V_13 , V_3 ) ;
F_7 ( V_59 ) ;
}
}
static void F_35 ( struct V_16 * V_3 )
{
struct V_2 * V_59 , * V_60 ;
F_36 (pos, n, self, node) {
F_37 ( & V_59 -> V_61 ) ;
F_7 ( V_59 ) ;
}
}
void F_38 ( struct V_51 * V_3 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; ++ V_52 ) {
F_32 ( & V_3 -> V_54 [ V_52 ] ) ;
F_35 ( & V_3 -> V_56 [ V_52 ] ) ;
}
}
void F_39 ( struct V_51 * V_3 )
{
int type ;
for ( type = 0 ; type < V_53 ; type ++ ) {
struct V_26 * V_62 = & V_3 -> V_54 [ type ] ;
struct V_13 * V_58 = F_9 ( V_62 ) ;
while ( V_58 ) {
struct V_2 * V_59 = F_10 ( V_58 , struct V_2 , V_13 ) ;
V_58 = F_33 ( & V_59 -> V_13 ) ;
F_34 ( & V_59 -> V_13 , V_62 ) ;
F_40 ( & V_59 -> V_61 , & V_3 -> V_56 [ V_59 -> type ] ) ;
}
}
}
struct V_29 * F_41 ( struct V_51 * V_3 ,
enum V_4 type , T_1 V_42 ,
struct V_2 * * V_63 ,
T_3 V_31 )
{
struct V_2 * V_2 = F_42 ( V_3 , type , V_42 ) ;
if ( V_2 != NULL ) {
if ( V_63 != NULL )
* V_63 = V_2 ;
return F_19 ( V_2 , V_2 -> V_9 ( V_2 , V_42 ) , V_31 ) ;
}
return NULL ;
}
struct V_29 * F_43 ( struct V_51 * V_3 ,
enum V_4 type ,
const char * V_32 ,
struct V_2 * * V_63 ,
T_3 V_31 )
{
struct V_13 * V_28 ;
for ( V_28 = F_9 ( & V_3 -> V_54 [ type ] ) ; V_28 ; V_28 = F_33 ( V_28 ) ) {
struct V_2 * V_59 = F_10 ( V_28 , struct V_2 , V_13 ) ;
struct V_29 * V_30 = F_21 ( V_59 , V_32 , V_31 ) ;
if ( V_30 == NULL )
continue;
if ( V_63 != NULL )
* V_63 = V_59 ;
return V_30 ;
}
return NULL ;
}
T_4 F_44 ( struct V_51 * V_3 ,
enum V_4 type , int V_64 , T_5 * V_46 )
{
T_4 V_65 = fprintf ( V_46 , L_14 , V_66 [ type ] ) ;
struct V_13 * V_28 ;
for ( V_28 = F_9 ( & V_3 -> V_54 [ type ] ) ; V_28 ; V_28 = F_33 ( V_28 ) ) {
struct V_2 * V_59 = F_10 ( V_28 , struct V_2 , V_13 ) ;
V_65 += fprintf ( V_46 , L_15 ) ;
V_65 += F_27 ( V_59 , V_46 ) ;
if ( V_64 > 2 ) {
V_65 += F_45 ( V_59 -> V_8 , type , V_46 ) ;
V_65 += fprintf ( V_46 , L_16 ) ;
}
}
return V_65 ;
}
T_4 F_46 ( struct V_51 * V_3 , int V_64 , T_5 * V_46 )
{
T_4 V_65 = 0 , V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; ++ V_52 )
V_65 += F_44 ( V_3 , V_52 , V_64 , V_46 ) ;
return V_65 ;
}
static T_4 F_47 ( struct V_51 * V_3 ,
enum V_4 type ,
int V_64 , T_5 * V_46 )
{
struct V_2 * V_59 ;
T_4 V_65 = 0 ;
F_48 (pos, &self->removed_maps[type], node) {
V_65 += fprintf ( V_46 , L_15 ) ;
V_65 += F_27 ( V_59 , V_46 ) ;
if ( V_64 > 1 ) {
V_65 += F_45 ( V_59 -> V_8 , type , V_46 ) ;
V_65 += fprintf ( V_46 , L_16 ) ;
}
}
return V_65 ;
}
static T_4 F_49 ( struct V_51 * V_3 ,
int V_64 , T_5 * V_46 )
{
T_4 V_65 = 0 , V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; ++ V_52 )
V_65 += F_47 ( V_3 , V_52 , V_64 , V_46 ) ;
return V_65 ;
}
T_4 F_50 ( struct V_51 * V_3 , int V_64 , T_5 * V_46 )
{
T_4 V_65 = F_46 ( V_3 , V_64 , V_46 ) ;
V_65 += fprintf ( V_46 , L_17 ) ;
return V_65 + F_49 ( V_3 , V_64 , V_46 ) ;
}
int F_51 ( struct V_51 * V_3 , struct V_2 * V_2 ,
int V_64 , T_5 * V_46 )
{
struct V_26 * V_62 = & V_3 -> V_54 [ V_2 -> type ] ;
struct V_13 * V_58 = F_9 ( V_62 ) ;
int V_67 = 0 ;
while ( V_58 ) {
struct V_2 * V_59 = F_10 ( V_58 , struct V_2 , V_13 ) ;
V_58 = F_33 ( & V_59 -> V_13 ) ;
if ( ! F_26 ( V_59 , V_2 ) )
continue;
if ( V_64 >= 2 ) {
fputs ( L_18 , V_46 ) ;
F_27 ( V_2 , V_46 ) ;
F_27 ( V_59 , V_46 ) ;
}
F_34 ( & V_59 -> V_13 , V_62 ) ;
if ( V_2 -> V_5 > V_59 -> V_5 ) {
struct V_2 * V_68 = F_25 ( V_59 ) ;
if ( V_68 == NULL ) {
V_67 = - V_69 ;
goto V_70;
}
V_68 -> V_6 = V_2 -> V_5 - 1 ;
F_52 ( V_3 , V_68 ) ;
if ( V_64 >= 2 )
F_27 ( V_68 , V_46 ) ;
}
if ( V_2 -> V_6 < V_59 -> V_6 ) {
struct V_2 * V_71 = F_25 ( V_59 ) ;
if ( V_71 == NULL ) {
V_67 = - V_69 ;
goto V_70;
}
V_71 -> V_5 = V_2 -> V_6 + 1 ;
F_52 ( V_3 , V_71 ) ;
if ( V_64 >= 2 )
F_27 ( V_71 , V_46 ) ;
}
V_70:
if ( V_59 -> V_15 )
F_40 ( & V_59 -> V_61 , & V_3 -> V_56 [ V_2 -> type ] ) ;
else
F_7 ( V_59 ) ;
if ( V_67 )
return V_67 ;
}
return 0 ;
}
int F_53 ( struct V_51 * V_3 ,
struct V_51 * V_72 , enum V_4 type )
{
struct V_13 * V_28 ;
for ( V_28 = F_9 ( & V_72 -> V_54 [ type ] ) ; V_28 ; V_28 = F_33 ( V_28 ) ) {
struct V_2 * V_2 = F_10 ( V_28 , struct V_2 , V_13 ) ;
struct V_2 * V_73 = F_25 ( V_2 ) ;
if ( V_73 == NULL )
return - V_69 ;
F_52 ( V_3 , V_73 ) ;
}
return 0 ;
}
static T_1 F_54 ( struct V_2 * V_2 , T_1 V_50 )
{
return V_50 + ( V_74 ) V_2 -> V_7 ;
}
static T_1 F_55 ( struct V_2 * V_2 , T_1 V_50 )
{
return V_50 - ( V_74 ) V_2 -> V_7 ;
}
void F_18 ( struct V_2 * V_3 )
{
struct V_75 * V_75 = F_56 ( V_3 ) ;
V_74 V_76 ;
if ( ! V_75 -> V_77 || ! V_75 -> V_77 -> V_78 )
return;
V_76 = ( V_75 -> V_77 -> V_78 -
V_75 -> V_77 -> V_42 ) ;
if ( ! V_76 )
return;
V_3 -> V_9 = F_54 ;
V_3 -> V_11 = F_55 ;
V_3 -> V_7 = V_76 ;
}
void F_57 ( struct V_26 * V_54 , struct V_2 * V_2 )
{
struct V_13 * * V_79 = & V_54 -> V_13 ;
struct V_13 * V_72 = NULL ;
const T_1 V_50 = V_2 -> V_5 ;
struct V_2 * V_80 ;
while ( * V_79 != NULL ) {
V_72 = * V_79 ;
V_80 = F_10 ( V_72 , struct V_2 , V_13 ) ;
if ( V_50 < V_80 -> V_5 )
V_79 = & ( * V_79 ) -> V_81 ;
else
V_79 = & ( * V_79 ) -> V_82 ;
}
F_58 ( & V_2 -> V_13 , V_72 , V_79 ) ;
F_59 ( & V_2 -> V_13 , V_54 ) ;
}
void F_60 ( struct V_26 * V_3 , struct V_2 * V_2 )
{
F_34 ( & V_2 -> V_13 , V_3 ) ;
}
struct V_2 * F_61 ( struct V_26 * V_54 , T_1 V_50 )
{
struct V_13 * * V_79 = & V_54 -> V_13 ;
struct V_13 * V_72 = NULL ;
struct V_2 * V_80 ;
while ( * V_79 != NULL ) {
V_72 = * V_79 ;
V_80 = F_10 ( V_72 , struct V_2 , V_13 ) ;
if ( V_50 < V_80 -> V_5 )
V_79 = & ( * V_79 ) -> V_81 ;
else if ( V_50 > V_80 -> V_6 )
V_79 = & ( * V_79 ) -> V_82 ;
else
return V_80 ;
}
return NULL ;
}
int F_62 ( struct V_57 * V_3 , const char * V_83 , T_6 V_19 )
{
F_30 ( & V_3 -> V_84 ) ;
F_3 ( & V_3 -> V_13 ) ;
F_31 ( & V_3 -> V_85 ) ;
F_31 ( & V_3 -> V_86 ) ;
V_3 -> V_84 . V_57 = V_3 ;
V_3 -> V_19 = V_19 ;
V_3 -> V_83 = F_63 ( V_83 ) ;
return V_3 -> V_83 == NULL ? - V_69 : 0 ;
}
static void F_64 ( struct V_16 * V_3 )
{
struct V_8 * V_59 , * V_60 ;
F_36 (pos, n, self, node) {
F_37 ( & V_59 -> V_61 ) ;
F_65 ( V_59 ) ;
}
}
void F_66 ( struct V_57 * V_3 )
{
F_38 ( & V_3 -> V_84 ) ;
F_64 ( & V_3 -> V_85 ) ;
F_64 ( & V_3 -> V_86 ) ;
free ( V_3 -> V_83 ) ;
V_3 -> V_83 = NULL ;
}
void F_67 ( struct V_57 * V_3 )
{
F_66 ( V_3 ) ;
free ( V_3 ) ;
}
struct V_57 * F_68 ( struct V_26 * V_3 , T_6 V_19 ,
const char * V_83 )
{
struct V_13 * * V_79 = & V_3 -> V_13 ;
struct V_13 * V_72 = NULL ;
struct V_57 * V_59 , * V_57 = malloc ( sizeof( * V_57 ) ) ;
if ( ! V_57 )
return NULL ;
if ( F_62 ( V_57 , V_83 , V_19 ) != 0 ) {
free ( V_57 ) ;
return NULL ;
}
while ( * V_79 != NULL ) {
V_72 = * V_79 ;
V_59 = F_10 ( V_72 , struct V_57 , V_13 ) ;
if ( V_19 < V_59 -> V_19 )
V_79 = & ( * V_79 ) -> V_81 ;
else
V_79 = & ( * V_79 ) -> V_82 ;
}
F_58 ( & V_57 -> V_13 , V_72 , V_79 ) ;
F_59 ( & V_57 -> V_13 , V_3 ) ;
return V_57 ;
}
struct V_57 * F_69 ( struct V_26 * V_3 , T_6 V_19 )
{
struct V_13 * * V_79 = & V_3 -> V_13 ;
struct V_13 * V_72 = NULL ;
struct V_57 * V_57 ;
struct V_57 * V_87 = NULL ;
while ( * V_79 != NULL ) {
V_72 = * V_79 ;
V_57 = F_10 ( V_72 , struct V_57 , V_13 ) ;
if ( V_19 < V_57 -> V_19 )
V_79 = & ( * V_79 ) -> V_81 ;
else if ( V_19 > V_57 -> V_19 )
V_79 = & ( * V_79 ) -> V_82 ;
else
return V_57 ;
if ( ! V_57 -> V_19 )
V_87 = V_57 ;
}
return V_87 ;
}
struct V_57 * F_70 ( struct V_26 * V_3 , T_6 V_19 )
{
char V_88 [ V_21 ] ;
const char * V_83 ;
struct V_57 * V_57 = F_69 ( V_3 , V_19 ) ;
if ( ! V_57 || V_57 -> V_19 != V_19 ) {
if ( V_19 == V_89 || V_19 == V_90 )
V_83 = L_19 ;
else {
if ( ! V_91 . V_92 )
goto V_93;
sprintf ( V_88 , L_20 , V_91 . V_92 , V_19 ) ;
if ( F_71 ( V_88 , V_94 ) ) {
F_72 ( L_21 , V_88 ) ;
goto V_93;
}
V_83 = V_88 ;
}
V_57 = F_68 ( V_3 , V_19 , V_83 ) ;
}
V_93:
return V_57 ;
}
void F_73 ( struct V_26 * V_3 , T_7 V_95 , void * V_96 )
{
struct V_13 * V_28 ;
for ( V_28 = F_9 ( V_3 ) ; V_28 ; V_28 = F_33 ( V_28 ) ) {
struct V_57 * V_59 = F_10 ( V_28 , struct V_57 , V_13 ) ;
V_95 ( V_59 , V_96 ) ;
}
}
char * F_74 ( struct V_57 * V_3 , char * V_97 , T_4 V_98 )
{
if ( F_75 ( V_3 ) )
snprintf ( V_97 , V_98 , L_22 , L_23 ) ;
else if ( F_76 ( V_3 ) )
snprintf ( V_97 , V_98 , L_22 , L_24 ) ;
else
snprintf ( V_97 , V_98 , L_25 , L_24 , V_3 -> V_19 ) ;
return V_97 ;
}
