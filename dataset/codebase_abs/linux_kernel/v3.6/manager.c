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
if ( V_2 -> V_6 -> type == V_61 )
V_60 = V_62 ;
else if ( V_2 -> V_6 -> type == V_63 )
V_60 = V_64 ;
else
V_60 = F_31 ( V_2 -> V_65 ) ;
V_17 = F_32 ( V_60 , V_59 ) ;
F_33 () ;
return V_17 ;
}
int F_34 ( struct V_66 * V_67 )
{
int V_47 , V_17 ;
V_68 = F_35 () ;
V_69 = F_36 ( sizeof( struct V_1 ) * V_68 ,
V_70 ) ;
F_9 ( V_69 == NULL ) ;
for ( V_47 = 0 ; V_47 < V_68 ; ++ V_47 ) {
struct V_1 * V_2 = & V_69 [ V_47 ] ;
switch ( V_47 ) {
case 0 :
V_2 -> V_5 = L_7 ;
V_2 -> V_65 = V_71 ;
break;
case 1 :
V_2 -> V_5 = L_8 ;
V_2 -> V_65 = V_72 ;
break;
case 2 :
V_2 -> V_5 = L_9 ;
V_2 -> V_65 = V_73 ;
break;
case 3 :
V_2 -> V_5 = L_10 ;
V_2 -> V_65 = V_74 ;
break;
}
V_2 -> V_75 = & V_76 ;
V_2 -> V_77 = & V_78 ;
V_2 -> V_19 = & V_79 ;
V_2 -> V_18 = & V_80 ;
V_2 -> V_13 = & V_81 ;
V_2 -> V_82 = & V_83 ;
V_2 -> V_84 = & F_28 ;
V_2 -> V_85 = 0 ;
V_2 -> V_86 =
F_37 ( V_2 -> V_65 ) ;
F_38 ( & V_2 -> V_87 ) ;
V_17 = F_39 ( & V_2 -> V_50 , & V_88 ,
& V_67 -> V_89 . V_50 , L_11 , V_47 ) ;
if ( V_17 )
F_40 ( L_12 ) ;
}
return 0 ;
}
void F_41 ( struct V_66 * V_67 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_68 ; ++ V_47 ) {
struct V_1 * V_2 = & V_69 [ V_47 ] ;
F_42 ( & V_2 -> V_50 ) ;
F_43 ( & V_2 -> V_50 ) ;
}
F_44 ( V_69 ) ;
V_69 = NULL ;
V_68 = 0 ;
}
int F_45 ( void )
{
return V_68 ;
}
struct V_1 * F_46 ( int V_90 )
{
if ( V_90 >= V_68 )
return NULL ;
return & V_69 [ V_90 ] ;
}
int F_47 ( struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
if ( F_19 ( V_30 ) ) {
if ( V_12 -> V_31 && V_12 -> V_28
&& V_12 -> V_22 != V_24 ) {
F_40 ( L_13 ) ;
return - V_25 ;
}
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_91 * * V_92 )
{
struct V_93 * V_94 , * V_95 ;
struct V_91 * V_96 , * V_97 ;
F_49 (ovl1, &mgr->overlays, list) {
V_96 = V_92 [ V_94 -> V_65 ] ;
if ( V_96 == NULL )
continue;
F_49 (ovl2, &mgr->overlays, list) {
if ( V_94 == V_95 )
continue;
V_97 = V_92 [ V_95 -> V_65 ] ;
if ( V_97 == NULL )
continue;
if ( V_96 -> V_98 == V_97 -> V_98 ) {
F_40 ( L_14
L_15 ,
V_94 -> V_65 , V_95 -> V_65 , V_96 -> V_98 ) ;
return - V_25 ;
}
}
}
return 0 ;
}
int F_50 ( struct V_1 * V_2 ,
const struct V_99 * V_100 )
{
if ( ! F_51 ( V_2 -> V_65 , V_100 ) ) {
F_40 ( L_16 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_101 * V_102 )
{
struct V_103 V_104 = V_102 -> V_105 ;
int V_106 = V_102 -> V_107 ;
bool V_108 = V_102 -> V_108 ;
bool V_109 = V_102 -> V_109 ;
if ( V_104 . V_110 < 1 || V_104 . V_110 > 255 )
return - V_25 ;
if ( V_104 . V_111 < 1 || V_104 . V_111 > 255 )
return - V_25 ;
if ( V_106 != 12 && V_106 != 16 && V_106 != 18 && V_106 != 24 )
return - V_25 ;
if ( V_108 == false && V_109 == true )
return - V_25 ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
const struct V_99 * V_112 ,
const struct V_101 * V_113 ,
struct V_91 * * V_92 )
{
struct V_93 * V_114 ;
int V_17 ;
if ( F_19 ( V_115 ) ) {
V_17 = F_48 ( V_2 , V_92 ) ;
if ( V_17 )
return V_17 ;
}
V_17 = F_50 ( V_2 , V_112 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_52 ( V_2 , V_113 ) ;
if ( V_17 )
return V_17 ;
F_49 (ovl, &mgr->overlays, list) {
struct V_91 * V_116 ;
int V_17 ;
V_116 = V_92 [ V_114 -> V_65 ] ;
if ( V_116 == NULL )
continue;
V_17 = F_54 ( V_114 , V_116 , V_112 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
