int F_1 ( struct V_1 * V_1 , const char * V_2 , T_1 V_3 )
{
F_2 ( & V_1 -> V_4 ) ;
F_3 ( & V_1 -> V_5 ) ;
F_4 ( & V_1 -> V_6 ) ;
F_4 ( & V_1 -> V_7 ) ;
V_1 -> V_8 = V_9 ;
F_4 ( & V_1 -> V_10 ) ;
V_1 -> V_11 = NULL ;
V_1 -> V_4 . V_1 = V_1 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_2 = F_5 ( V_2 ) ;
if ( V_1 -> V_2 == NULL )
return - V_12 ;
if ( V_3 != V_13 ) {
struct V_14 * V_14 = F_6 ( V_1 , V_3 ) ;
char V_15 [ 64 ] ;
if ( V_14 == NULL )
return - V_12 ;
snprintf ( V_15 , sizeof( V_15 ) , L_1 , V_3 ) ;
F_7 ( V_14 , V_15 ) ;
}
return 0 ;
}
static void F_8 ( struct V_16 * V_17 )
{
struct V_18 * V_19 , * V_20 ;
F_9 (pos, n, dsos, node) {
F_10 ( & V_19 -> V_21 ) ;
F_11 ( V_19 ) ;
}
}
void F_12 ( struct V_1 * V_1 )
{
F_13 ( & V_1 -> V_4 ) ;
F_8 ( & V_1 -> V_6 ) ;
F_8 ( & V_1 -> V_7 ) ;
free ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
void F_14 ( struct V_1 * V_1 )
{
F_12 ( V_1 ) ;
free ( V_1 ) ;
}
struct V_1 * F_15 ( struct V_22 * V_23 , T_1 V_3 ,
const char * V_2 )
{
struct V_5 * * V_24 = & V_23 -> V_5 ;
struct V_5 * V_25 = NULL ;
struct V_1 * V_19 , * V_1 = malloc ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_1 ( V_1 , V_2 , V_3 ) != 0 ) {
free ( V_1 ) ;
return NULL ;
}
while ( * V_24 != NULL ) {
V_25 = * V_24 ;
V_19 = F_16 ( V_25 , struct V_1 , V_5 ) ;
if ( V_3 < V_19 -> V_3 )
V_24 = & ( * V_24 ) -> V_26 ;
else
V_24 = & ( * V_24 ) -> V_27 ;
}
F_17 ( & V_1 -> V_5 , V_25 , V_24 ) ;
F_18 ( & V_1 -> V_5 , V_23 ) ;
return V_1 ;
}
struct V_1 * F_19 ( struct V_22 * V_23 , T_1 V_3 )
{
struct V_5 * * V_24 = & V_23 -> V_5 ;
struct V_5 * V_25 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_28 = NULL ;
while ( * V_24 != NULL ) {
V_25 = * V_24 ;
V_1 = F_16 ( V_25 , struct V_1 , V_5 ) ;
if ( V_3 < V_1 -> V_3 )
V_24 = & ( * V_24 ) -> V_26 ;
else if ( V_3 > V_1 -> V_3 )
V_24 = & ( * V_24 ) -> V_27 ;
else
return V_1 ;
if ( ! V_1 -> V_3 )
V_28 = V_1 ;
}
return V_28 ;
}
struct V_1 * F_20 ( struct V_22 * V_23 , T_1 V_3 )
{
char V_29 [ V_30 ] ;
const char * V_2 = L_2 ;
struct V_1 * V_1 = F_19 ( V_23 , V_3 ) ;
if ( V_1 && ( V_1 -> V_3 == V_3 ) )
goto V_31;
if ( ( V_3 != V_13 ) &&
( V_3 != V_32 ) &&
( V_33 . V_34 ) ) {
sprintf ( V_29 , L_3 , V_33 . V_34 , V_3 ) ;
if ( F_21 ( V_29 , V_35 ) ) {
static struct V_36 * V_37 ;
if ( ! V_37 )
V_37 = F_22 ( true , NULL ) ;
if ( ! F_23 ( V_37 , V_29 ) ) {
F_24 ( L_4 , V_29 ) ;
F_25 ( V_37 , V_29 ) ;
}
V_1 = NULL ;
goto V_31;
}
V_2 = V_29 ;
}
V_1 = F_15 ( V_23 , V_3 , V_2 ) ;
V_31:
return V_1 ;
}
void F_26 ( struct V_22 * V_23 ,
T_2 V_38 , void * V_39 )
{
struct V_5 * V_40 ;
for ( V_40 = F_27 ( V_23 ) ; V_40 ; V_40 = F_28 ( V_40 ) ) {
struct V_1 * V_19 = F_16 ( V_40 , struct V_1 , V_5 ) ;
V_38 ( V_19 , V_39 ) ;
}
}
char * F_29 ( struct V_1 * V_1 , char * V_41 , T_3 V_42 )
{
if ( F_30 ( V_1 ) )
snprintf ( V_41 , V_42 , L_5 , L_6 ) ;
else if ( F_31 ( V_1 ) )
snprintf ( V_41 , V_42 , L_5 , L_7 ) ;
else {
snprintf ( V_41 , V_42 , L_8 , L_7 ,
V_1 -> V_3 ) ;
}
return V_41 ;
}
void F_32 ( struct V_22 * V_23 , T_4 V_43 )
{
struct V_5 * V_21 ;
struct V_1 * V_1 ;
for ( V_21 = F_27 ( V_23 ) ; V_21 ; V_21 = F_28 ( V_21 ) ) {
V_1 = F_16 ( V_21 , struct V_1 , V_5 ) ;
V_1 -> V_43 = V_43 ;
}
return;
}
static struct V_14 * F_33 ( struct V_1 * V_1 , T_1 V_3 ,
bool V_44 )
{
struct V_5 * * V_24 = & V_1 -> V_8 . V_5 ;
struct V_5 * V_25 = NULL ;
struct V_14 * V_45 ;
if ( V_1 -> V_11 && V_1 -> V_11 -> V_3 == V_3 )
return V_1 -> V_11 ;
while ( * V_24 != NULL ) {
V_25 = * V_24 ;
V_45 = F_16 ( V_25 , struct V_14 , V_5 ) ;
if ( V_45 -> V_3 == V_3 ) {
V_1 -> V_11 = V_45 ;
return V_45 ;
}
if ( V_3 < V_45 -> V_3 )
V_24 = & ( * V_24 ) -> V_26 ;
else
V_24 = & ( * V_24 ) -> V_27 ;
}
if ( ! V_44 )
return NULL ;
V_45 = F_34 ( V_3 ) ;
if ( V_45 != NULL ) {
F_17 ( & V_45 -> V_5 , V_25 , V_24 ) ;
F_18 ( & V_45 -> V_5 , & V_1 -> V_8 ) ;
V_1 -> V_11 = V_45 ;
}
return V_45 ;
}
struct V_14 * F_6 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_33 ( V_1 , V_3 , true ) ;
}
struct V_14 * F_35 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_33 ( V_1 , V_3 , false ) ;
}
int F_36 ( struct V_1 * V_1 , union V_46 * V_47 )
{
struct V_14 * V_14 = F_6 ( V_1 , V_47 -> V_15 . V_48 ) ;
if ( V_49 )
F_37 ( V_47 , stdout ) ;
if ( V_14 == NULL || F_7 ( V_14 , V_47 -> V_15 . V_15 ) ) {
F_38 ( L_9 ) ;
return - 1 ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_1 V_50 ,
union V_46 * V_47 )
{
F_38 ( L_10 V_51 L_11 V_51 L_12 ,
V_47 -> V_52 . V_53 , V_47 -> V_52 . V_52 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_1 ,
union V_46 * V_47 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
V_1 -> V_56 [ V_54 ] -> V_57 = V_47 -> V_58 . V_57 ;
V_1 -> V_56 [ V_54 ] -> V_59 = ( V_47 -> V_58 . V_57 +
V_47 -> V_58 . V_60 ) ;
if ( V_1 -> V_56 [ V_54 ] -> V_59 == 0 )
V_1 -> V_56 [ V_54 ] -> V_59 = ~ 0ULL ;
}
}
static int F_41 ( struct V_1 * V_1 ,
union V_46 * V_47 )
{
struct V_61 * V_61 ;
char V_62 [ V_30 ] ;
enum V_63 V_64 ;
bool V_65 ;
F_29 ( V_1 , V_62 , sizeof( V_62 ) ) ;
if ( F_30 ( V_1 ) )
V_64 = V_66 ;
else
V_64 = V_67 ;
V_65 = memcmp ( V_47 -> V_58 . V_68 ,
V_62 ,
strlen ( V_62 ) - 1 ) == 0 ;
if ( V_47 -> V_58 . V_68 [ 0 ] == '/' ||
( ! V_65 && V_47 -> V_58 . V_68 [ 0 ] == '[' ) ) {
char V_69 [ 1024 ] ;
char * V_70 , * V_71 ;
if ( V_47 -> V_58 . V_68 [ 0 ] == '/' ) {
V_70 = strrchr ( V_47 -> V_58 . V_68 , '/' ) ;
if ( V_70 == NULL )
goto V_72;
++ V_70 ;
V_71 = strrchr ( V_70 , '.' ) ;
if ( V_71 == NULL )
goto V_72;
snprintf ( V_69 , sizeof( V_69 ) ,
L_13 , ( int ) ( V_71 - V_70 ) , V_70 ) ;
F_42 ( V_69 , '-' , '_' ) ;
} else
strcpy ( V_69 , V_47 -> V_58 . V_68 ) ;
V_61 = F_43 ( V_1 , V_47 -> V_58 . V_57 ,
V_47 -> V_58 . V_68 ) ;
if ( V_61 == NULL )
goto V_72;
V_70 = F_5 ( V_69 ) ;
if ( V_70 == NULL )
goto V_72;
V_61 -> V_18 -> V_73 = V_70 ;
V_61 -> V_18 -> V_74 = 1 ;
V_61 -> V_59 = V_61 -> V_57 + V_47 -> V_58 . V_60 ;
} else if ( V_65 ) {
const char * V_75 = ( V_47 -> V_58 . V_68 +
strlen ( V_62 ) ) ;
struct V_18 * V_76 = F_44 ( & V_1 -> V_7 ,
V_62 ) ;
if ( V_76 == NULL )
goto V_72;
V_76 -> V_76 = V_64 ;
if ( F_45 ( V_1 , V_76 ) < 0 )
goto V_72;
F_40 ( V_1 , V_47 ) ;
if ( V_47 -> V_58 . V_77 != 0 ) {
F_46 ( V_1 -> V_56 ,
V_75 ,
V_47 -> V_58 . V_77 ) ;
}
if ( F_31 ( V_1 ) ) {
F_47 ( V_76 , V_1 -> V_56 [ V_78 ] ,
NULL ) ;
}
}
return 0 ;
V_72:
return - 1 ;
}
int F_48 ( struct V_1 * V_1 , union V_46 * V_47 )
{
T_5 V_79 = V_47 -> V_80 . V_81 & V_82 ;
struct V_14 * V_14 ;
struct V_61 * V_61 ;
int V_83 = 0 ;
if ( V_49 )
F_49 ( V_47 , stdout ) ;
if ( V_79 == V_84 ||
V_79 == V_85 ) {
V_83 = F_41 ( V_1 , V_47 ) ;
if ( V_83 < 0 )
goto V_72;
return 0 ;
}
V_14 = F_6 ( V_1 , V_47 -> V_58 . V_3 ) ;
if ( V_14 == NULL )
goto V_72;
V_61 = F_50 ( & V_1 -> V_6 , V_47 -> V_58 . V_57 ,
V_47 -> V_58 . V_60 , V_47 -> V_58 . V_77 ,
V_47 -> V_58 . V_3 , V_47 -> V_58 . V_68 ,
V_78 ) ;
if ( V_61 == NULL )
goto V_72;
F_51 ( V_14 , V_61 ) ;
return 0 ;
V_72:
F_38 ( L_14 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_1 , union V_46 * V_47 )
{
struct V_14 * V_14 = F_6 ( V_1 , V_47 -> V_86 . V_48 ) ;
struct V_14 * V_25 = F_6 ( V_1 , V_47 -> V_86 . V_87 ) ;
if ( V_49 )
F_53 ( V_47 , stdout ) ;
if ( V_14 == NULL || V_25 == NULL ||
F_54 ( V_14 , V_25 ) < 0 ) {
F_38 ( L_15 ) ;
return - 1 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_1 , union V_46 * V_47 )
{
struct V_14 * V_14 = F_35 ( V_1 , V_47 -> V_86 . V_48 ) ;
if ( V_49 )
F_53 ( V_47 , stdout ) ;
if ( V_14 != NULL )
F_56 ( V_1 , V_14 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_1 , union V_46 * V_47 )
{
int V_83 ;
switch ( V_47 -> V_80 . type ) {
case V_88 :
V_83 = F_36 ( V_1 , V_47 ) ; break;
case V_89 :
V_83 = F_48 ( V_1 , V_47 ) ; break;
case V_90 :
V_83 = F_52 ( V_1 , V_47 ) ; break;
case V_91 :
V_83 = F_55 ( V_1 , V_47 ) ; break;
case V_92 :
V_83 = F_39 ( V_1 , V_47 ) ; break;
default:
V_83 = - 1 ;
break;
}
return V_83 ;
}
