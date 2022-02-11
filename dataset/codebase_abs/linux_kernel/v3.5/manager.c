static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 , V_2 -> V_5 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_6 ? V_2 -> V_6 -> V_5 : L_2 ) ;
}
int F_3 ( struct V_7 * V_8 , void * V_9 )
{
const char * V_10 = V_9 ;
return F_4 ( V_8 -> V_5 , V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 , L_3 , V_12 . V_14 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
T_3 V_16 ;
int V_17 ;
V_17 = F_7 ( V_3 , 0 , & V_16 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_14 = V_16 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
char * V_3 )
{
enum V_20 V_21 ;
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_21 = V_12 . V_22 ;
F_9 ( V_21 >= F_10 ( V_23 ) ) ;
return snprintf ( V_3 , V_4 , L_1 , V_23 [ V_21 ] ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
enum V_20 V_21 ;
struct V_11 V_12 ;
int V_17 ;
for ( V_21 = V_24 ;
V_21 < F_10 ( V_23 ) ; V_21 ++ ) {
if ( F_4 ( V_3 , V_23 [ V_21 ] ) )
break;
}
if ( V_21 == F_10 ( V_23 ) )
return - V_25 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_22 = V_21 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 , L_3 , V_12 . V_26 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
T_3 V_27 ;
int V_17 ;
V_17 = F_7 ( V_3 , 0 , & V_27 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_26 = V_27 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 , L_4 , V_12 . V_28 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
bool V_29 ;
int V_17 ;
V_17 = F_16 ( V_3 , & V_29 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_28 = V_29 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_17 (
struct V_1 * V_2 , char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
F_18 ( ! F_19 ( V_30 ) ) ;
return snprintf ( V_3 , V_4 , L_4 ,
V_12 . V_31 ) ;
}
static T_1 F_20 (
struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
bool V_29 ;
int V_17 ;
F_18 ( ! F_19 ( V_30 ) ) ;
V_17 = F_16 ( V_3 , & V_29 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_31 = V_29 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 , L_4 , V_12 . V_32 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
int V_17 ;
bool V_29 ;
if ( ! F_19 ( V_33 ) )
return - V_34 ;
V_17 = F_16 ( V_3 , & V_29 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
if ( V_12 . V_32 == V_29 )
return V_15 ;
V_12 . V_32 = V_29 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 ,
L_5 ,
V_12 . V_35 . V_36 ,
V_12 . V_35 . V_37 ,
V_12 . V_35 . V_38 ,
V_12 . V_35 . V_39 ,
V_12 . V_35 . V_40 ,
V_12 . V_35 . V_41 ,
V_12 . V_35 . V_42 ,
V_12 . V_35 . V_43 ,
V_12 . V_35 . V_44 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
struct V_45 V_46 ;
int V_17 , V_47 ;
T_4 * V_48 ;
if ( ! F_19 ( V_33 ) )
return - V_34 ;
if ( sscanf ( V_3 , L_6 ,
& V_46 . V_36 , & V_46 . V_37 , & V_46 . V_38 ,
& V_46 . V_39 , & V_46 . V_40 , & V_46 . V_41 ,
& V_46 . V_42 , & V_46 . V_43 , & V_46 . V_44 ) != 9 )
return - V_25 ;
V_48 = ( T_4 [] ) { V_46 . V_36 , V_46 . V_37 , V_46 . V_38 ,
V_46 . V_39 , V_46 . V_40 , V_46 . V_41 ,
V_46 . V_42 , V_46 . V_43 , V_46 . V_44 } ;
for ( V_47 = 0 ; V_47 < 9 ; ++ V_47 ) {
if ( V_48 [ V_47 ] < - 512 || V_48 [ V_47 ] > 511 )
return - V_25 ;
}
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_35 = V_46 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_25 ( struct V_49 * V_50 , struct V_51 * V_52 ,
char * V_3 )
{
struct V_1 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_26 ( V_50 , struct V_1 , V_50 ) ;
V_55 = F_26 ( V_52 , struct V_54 , V_52 ) ;
if ( ! V_55 -> V_56 )
return - V_57 ;
return V_55 -> V_56 ( V_53 , V_3 ) ;
}
static T_1 F_27 ( struct V_49 * V_50 , struct V_51 * V_52 ,
const char * V_3 , T_2 V_15 )
{
struct V_1 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_26 ( V_50 , struct V_1 , V_50 ) ;
V_55 = F_26 ( V_52 , struct V_54 , V_52 ) ;
if ( ! V_55 -> V_58 )
return - V_57 ;
return V_55 -> V_58 ( V_53 , V_3 , V_15 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
unsigned long V_59 = F_29 ( 500 ) ;
T_3 V_60 ;
int V_17 ;
V_17 = F_30 () ;
if ( V_17 )
return V_17 ;
if ( V_2 -> V_6 -> type == V_61 ) {
V_60 = V_62 ;
} else if ( V_2 -> V_6 -> type == V_63 ) {
V_60 = V_64 ;
} else {
if ( V_2 -> V_65 == V_66 )
V_60 = V_67 ;
else
V_60 = V_68 ;
}
V_17 = F_31 ( V_60 , V_59 ) ;
F_32 () ;
return V_17 ;
}
int F_33 ( struct V_69 * V_70 )
{
int V_47 , V_17 ;
V_71 = F_34 () ;
V_72 = F_35 ( sizeof( struct V_1 ) * V_71 ,
V_73 ) ;
F_9 ( V_72 == NULL ) ;
for ( V_47 = 0 ; V_47 < V_71 ; ++ V_47 ) {
struct V_1 * V_2 = & V_72 [ V_47 ] ;
switch ( V_47 ) {
case 0 :
V_2 -> V_5 = L_7 ;
V_2 -> V_65 = V_66 ;
break;
case 1 :
V_2 -> V_5 = L_8 ;
V_2 -> V_65 = V_74 ;
break;
case 2 :
V_2 -> V_5 = L_9 ;
V_2 -> V_65 = V_75 ;
break;
}
V_2 -> V_76 = & V_77 ;
V_2 -> V_78 = & V_79 ;
V_2 -> V_19 = & V_80 ;
V_2 -> V_18 = & V_81 ;
V_2 -> V_13 = & V_82 ;
V_2 -> V_83 = & V_84 ;
V_2 -> V_85 = & F_28 ;
V_2 -> V_86 = 0 ;
V_2 -> V_87 =
F_36 ( V_2 -> V_65 ) ;
F_37 ( & V_2 -> V_88 ) ;
V_17 = F_38 ( & V_2 -> V_50 , & V_89 ,
& V_70 -> V_90 . V_50 , L_10 , V_47 ) ;
if ( V_17 )
F_39 ( L_11 ) ;
}
return 0 ;
}
void F_40 ( struct V_69 * V_70 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_71 ; ++ V_47 ) {
struct V_1 * V_2 = & V_72 [ V_47 ] ;
F_41 ( & V_2 -> V_50 ) ;
F_42 ( & V_2 -> V_50 ) ;
}
F_43 ( V_72 ) ;
V_72 = NULL ;
V_71 = 0 ;
}
int F_44 ( void )
{
return V_71 ;
}
struct V_1 * F_45 ( int V_91 )
{
if ( V_91 >= V_71 )
return NULL ;
return & V_72 [ V_91 ] ;
}
int F_46 ( struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
if ( F_19 ( V_30 ) ) {
if ( V_12 -> V_31 && V_12 -> V_28
&& V_12 -> V_22 != V_24 ) {
F_39 ( L_12 ) ;
return - V_25 ;
}
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_92 * * V_93 )
{
struct V_94 * V_95 , * V_96 ;
struct V_92 * V_97 , * V_98 ;
F_48 (ovl1, &mgr->overlays, list) {
V_97 = V_93 [ V_95 -> V_65 ] ;
if ( V_97 == NULL )
continue;
F_48 (ovl2, &mgr->overlays, list) {
if ( V_95 == V_96 )
continue;
V_98 = V_93 [ V_96 -> V_65 ] ;
if ( V_98 == NULL )
continue;
if ( V_97 -> V_99 == V_98 -> V_99 ) {
F_39 ( L_13
L_14 ,
V_95 -> V_65 , V_96 -> V_65 , V_97 -> V_99 ) ;
return - V_25 ;
}
}
}
return 0 ;
}
int F_49 ( struct V_1 * V_2 ,
const struct V_100 * V_101 )
{
if ( ! F_50 ( V_2 -> V_65 , V_101 ) ) {
F_39 ( L_15 ) ;
return - V_25 ;
}
return 0 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
const struct V_100 * V_102 ,
struct V_92 * * V_93 )
{
struct V_94 * V_103 ;
int V_17 ;
if ( F_19 ( V_104 ) ) {
V_17 = F_47 ( V_2 , V_93 ) ;
if ( V_17 )
return V_17 ;
}
V_17 = F_49 ( V_2 , V_102 ) ;
if ( V_17 )
return V_17 ;
F_48 (ovl, &mgr->overlays, list) {
struct V_92 * V_105 ;
int V_17 ;
V_105 = V_93 [ V_103 -> V_65 ] ;
if ( V_105 == NULL )
continue;
V_17 = F_52 ( V_103 , V_105 , V_102 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
