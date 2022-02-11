static struct V_1 * F_1 (
struct V_2 * V_3 ,
char const * V_4 )
{
int V_5 , V_6 ;
char V_7 [ V_8 ] ;
struct V_1 * V_9 ;
if ( ! V_4 )
return NULL ;
V_6 = sscanf ( V_4 , L_1 , V_7 , & V_5 ) ;
F_2 ( V_3 -> V_10 , L_2 , V_11 , V_5 ) ;
F_3 ( & V_3 -> V_12 ) ;
F_4 (module, &codec->module_list, list) {
if ( V_9 -> V_5 == V_5 ) {
F_5 ( & V_3 -> V_12 ) ;
return V_9 ;
}
}
F_5 ( & V_3 -> V_12 ) ;
F_6 ( V_3 -> V_10 , L_3 , V_4 ,
V_5 ) ;
return NULL ;
}
static const char * F_7 ( struct V_1 * V_9 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 ;
if ( V_13 == V_17 )
return NULL ;
F_4 (control, &module->ctl_list, list) {
if ( V_16 -> V_18 == V_13 ) {
if ( V_14 == V_17 )
return V_16 -> V_4 ;
if ( V_14 >= V_16 -> V_19 )
return NULL ;
return V_16 -> V_20 [ V_14 ] ;
}
}
F_4 (control, &module->widget_ctl_list, list) {
if ( V_16 -> V_18 == V_13 ) {
if ( V_14 == V_17 )
return V_16 -> V_4 ;
if ( V_14 >= V_16 -> V_19 )
return NULL ;
return V_16 -> V_20 [ V_14 ] ;
}
}
return NULL ;
}
static int F_8 ( struct V_1 * V_9 ,
const char * V_4 )
{
struct V_15 * V_16 ;
F_4 (control, &module->ctl_list, list) {
if ( ! strncmp ( V_16 -> V_4 , V_4 , V_8 ) )
return V_16 -> V_18 ;
}
F_6 ( V_9 -> V_10 , L_4 , V_4 ) ;
return - V_21 ;
}
static int F_9 ( struct V_1 * V_9 ,
const char * V_4 )
{
struct V_15 * V_16 ;
F_4 (control, &module->widget_ctl_list, list) {
if ( ! strncmp ( V_16 -> V_22 , V_4 , V_8 ) )
return V_16 -> V_18 ;
}
F_6 ( V_9 -> V_10 , L_4 , V_4 ) ;
return - V_21 ;
}
static int F_10 ( struct V_1 * V_9 ,
const char * V_4 )
{
struct V_23 * V_24 ;
F_4 (widget, &module->widget_list, list) {
if ( ! strncmp ( V_24 -> V_4 , V_4 , V_8 ) )
return V_24 -> V_18 ;
}
F_6 ( V_9 -> V_10 , L_5 , V_4 ) ;
return - V_21 ;
}
static const char * F_11 ( struct V_1 * V_9 ,
T_1 V_25 )
{
struct V_23 * V_24 ;
F_4 (widget, &module->widget_list, list) {
if ( V_24 -> V_18 == V_25 )
return V_24 -> V_4 ;
}
return NULL ;
}
static const char * * F_12 ( struct V_1 * V_26 ,
struct V_27 * V_28 )
{
const char * * V_29 ;
int V_30 ;
unsigned int V_19 ;
T_1 * V_31 ;
V_19 = F_13 ( V_28 -> V_19 ) ;
V_29 = F_14 ( V_26 -> V_10 , sizeof( char * ) * V_19 , V_32 ) ;
V_31 = V_28 -> V_33 ;
for ( V_30 = 0 ; V_30 < V_19 ; V_30 ++ ) {
V_29 [ V_30 ] = ( const char * ) V_31 ;
while ( * V_31 != '\0' )
V_31 ++ ;
V_31 ++ ;
}
return V_29 ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
unsigned int V_38 ;
const char * V_4 ;
struct V_39 * V_31 ;
struct V_40 * V_41 ;
struct V_1 * V_9 ;
struct V_42 * V_3 = F_16 ( V_35 ) ;
struct V_2 * V_43 = F_17 ( V_3 ) ;
F_2 ( V_3 -> V_10 , L_6 , V_11 , V_35 -> V_18 . V_4 ) ;
V_31 = (struct V_39 * ) V_35 -> V_44 ;
V_41 = (struct V_40 * ) V_31 -> V_41 ;
if ( ! V_41 ) {
F_18 ( V_3 -> V_10 , L_7 , V_37 -> V_18 . V_4 ) ;
return - V_21 ;
}
V_37 -> V_45 = V_31 -> V_45 ;
V_37 -> V_46 = V_31 -> V_47 ;
V_37 -> type = ( V_48 ) V_41 -> type ;
switch ( V_41 -> type ) {
case V_49 :
case V_50 :
V_37 -> V_51 . integer . V_52 = F_13 ( V_41 -> V_51 . integer . V_52 ) ;
V_37 -> V_51 . integer . V_38 = F_13 ( V_41 -> V_51 . integer . V_38 ) ;
break;
case V_53 :
V_38 = F_13 ( V_41 -> V_51 . V_54 . V_19 ) ;
V_37 -> V_51 . V_54 . V_19 = V_38 ;
if ( V_37 -> V_51 . V_54 . V_55 > V_38 - 1 )
V_37 -> V_51 . V_54 . V_55 = V_38 - 1 ;
V_9 = F_1 ( V_43 , V_35 -> V_18 . V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_4 = F_7 ( V_9 , V_31 -> V_56 ,
V_37 -> V_51 . V_54 . V_55 ) ;
F_19 ( V_37 -> V_51 . V_54 . V_4 , V_4 , V_8 ) ;
break;
default:
F_18 ( V_3 -> V_10 , L_8 ,
V_41 -> type , V_35 -> V_18 . V_4 ) ;
break;
}
return 0 ;
}
static int F_20 ( struct V_34 * V_35 ,
struct V_57 * V_58 )
{
int V_6 ;
struct V_40 * V_41 ;
struct V_39 * V_31 ;
struct V_59 V_60 ;
struct V_1 * V_9 ;
struct V_42 * V_3 = F_16 ( V_35 ) ;
struct V_2 * V_26 = F_17 ( V_3 ) ;
struct V_61 * V_62 ;
F_2 ( V_3 -> V_10 , L_6 , V_11 , V_35 -> V_18 . V_4 ) ;
V_9 = F_1 ( V_26 , V_35 -> V_18 . V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_31 = (struct V_39 * ) V_35 -> V_44 ;
V_41 = (struct V_40 * ) V_31 -> V_41 ;
V_62 = F_21 ( V_9 -> V_10 ) ;
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_23 ( V_9 -> V_63 , V_31 -> V_56 ,
V_64 , & V_60 ) ;
F_24 ( V_62 ) ;
if ( V_6 ) {
F_25 ( V_3 -> V_10 , L_9 , V_6 ,
V_11 , V_35 -> V_18 . V_4 ) ;
return V_6 ;
}
switch ( V_41 -> type ) {
case V_49 :
case V_50 :
V_58 -> V_51 . integer . V_51 [ 0 ] =
F_13 ( V_60 . V_51 . V_65 [ 0 ] ) ;
if ( V_31 -> V_47 == 2 )
V_58 -> V_51 . integer . V_51 [ 1 ] =
F_13 ( V_60 . V_51 . V_65 [ 1 ] ) ;
break;
case V_53 :
V_58 -> V_51 . V_54 . V_55 [ 0 ] =
F_13 ( V_60 . V_51 . V_66 [ 0 ] ) ;
if ( V_31 -> V_47 == 2 )
V_58 -> V_51 . V_54 . V_55 [ 1 ] =
F_13 ( V_60 . V_51 . V_66 [ 1 ] ) ;
break;
default:
F_18 ( V_3 -> V_10 , L_8 ,
V_41 -> type , V_35 -> V_18 . V_4 ) ;
V_6 = - V_21 ;
break;
}
return V_6 ;
}
static int F_26 ( struct V_34 * V_35 ,
struct V_57 * V_58 )
{
int V_6 = 0 ;
struct V_40 * V_41 ;
struct V_39 * V_31 ;
struct V_59 V_60 ;
struct V_1 * V_9 ;
struct V_42 * V_3 = F_16 ( V_35 ) ;
struct V_2 * V_26 = F_17 ( V_3 ) ;
struct V_61 * V_62 ;
F_2 ( V_3 -> V_10 , L_6 , V_11 , V_35 -> V_18 . V_4 ) ;
V_9 = F_1 ( V_26 , V_35 -> V_18 . V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_31 = (struct V_39 * ) V_35 -> V_44 ;
V_41 = (struct V_40 * ) V_31 -> V_41 ;
V_62 = F_21 ( V_9 -> V_10 ) ;
switch ( V_41 -> type ) {
case V_49 :
case V_50 :
V_60 . V_51 . V_65 [ 0 ] =
F_27 ( V_58 -> V_51 . integer . V_51 [ 0 ] ) ;
if ( V_31 -> V_47 == 2 )
V_60 . V_51 . V_65 [ 1 ] =
F_27 ( V_58 -> V_51 . integer . V_51 [ 1 ] ) ;
break;
case V_53 :
V_60 . V_51 . V_66 [ 0 ] =
F_27 ( V_58 -> V_51 . V_54 . V_55 [ 0 ] ) ;
if ( V_31 -> V_47 == 2 )
V_60 . V_51 . V_66 [ 1 ] =
F_27 ( V_58 -> V_51 . V_54 . V_55 [ 1 ] ) ;
break;
default:
F_18 ( V_3 -> V_10 , L_8 ,
V_41 -> type , V_35 -> V_18 . V_4 ) ;
V_6 = - V_21 ;
break;
}
if ( V_6 )
return V_6 ;
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_28 ( V_9 -> V_63 , V_31 -> V_56 ,
V_64 , & V_60 ) ;
F_24 ( V_62 ) ;
if ( V_6 ) {
F_25 ( V_3 -> V_10 , L_9 , V_6 ,
V_11 , V_35 -> V_18 . V_4 ) ;
}
return V_6 ;
}
static int F_29 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
int V_67 , V_68 ;
struct V_39 * V_31 ;
struct V_40 * V_41 ;
struct V_69 * V_70 = F_16 ( V_35 ) ;
struct V_71 * V_24 = V_70 -> V_72 [ 0 ] ;
struct V_42 * V_3 = V_24 -> V_3 ;
F_2 ( V_3 -> V_10 , L_6 , V_11 , V_35 -> V_18 . V_4 ) ;
V_31 = (struct V_39 * ) V_35 -> V_44 ;
V_41 = (struct V_40 * ) V_31 -> V_41 ;
V_67 = F_13 ( V_41 -> V_51 . integer . V_38 ) ;
V_68 = F_13 ( V_41 -> V_51 . integer . V_52 ) ;
if ( V_67 == 1 &&
! F_30 ( V_35 -> V_18 . V_4 , L_10 , V_8 ) )
V_37 -> type = V_73 ;
else
V_37 -> type = V_74 ;
V_37 -> V_46 = V_31 -> V_47 ;
V_37 -> V_51 . integer . V_52 = V_68 ;
V_37 -> V_51 . integer . V_38 = V_67 ;
return 0 ;
}
static int F_31 ( struct V_34 * V_35 ,
struct V_57 * V_58 )
{
int V_6 ;
struct V_40 * V_41 ;
struct V_39 * V_31 ;
struct V_59 V_60 ;
struct V_1 * V_9 ;
struct V_69 * V_70 = F_16 ( V_35 ) ;
struct V_71 * V_24 = V_70 -> V_72 [ 0 ] ;
struct V_42 * V_3 = V_24 -> V_3 ;
struct V_2 * V_26 = F_17 ( V_3 ) ;
struct V_61 * V_62 ;
F_2 ( V_3 -> V_10 , L_6 , V_11 , V_35 -> V_18 . V_4 ) ;
V_9 = F_1 ( V_26 , V_35 -> V_18 . V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_31 = (struct V_39 * ) V_35 -> V_44 ;
V_41 = (struct V_40 * ) V_31 -> V_41 ;
V_62 = F_21 ( V_9 -> V_10 ) ;
if ( V_31 -> V_47 == 2 )
F_6 ( V_24 -> V_75 -> V_10 ,
L_11 ,
V_35 -> V_18 . V_4 ) ;
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_23 ( V_9 -> V_63 , V_31 -> V_56 ,
V_64 , & V_60 ) ;
F_24 ( V_62 ) ;
if ( V_6 ) {
F_25 ( V_3 -> V_10 , L_9 , V_6 ,
V_11 , V_35 -> V_18 . V_4 ) ;
return V_6 ;
}
V_58 -> V_51 . integer . V_51 [ 0 ] =
F_13 ( V_60 . V_51 . V_65 [ 0 ] ) ;
return V_6 ;
}
static int F_32 ( struct V_34 * V_35 ,
struct V_57 * V_58 )
{
int V_6 , V_76 , V_38 , V_77 ;
unsigned int V_78 , V_79 ;
struct V_40 * V_41 ;
struct V_39 * V_31 ;
struct V_59 V_60 ;
struct V_1 * V_9 ;
struct V_69 * V_70 = F_16 ( V_35 ) ;
struct V_71 * V_24 = V_70 -> V_72 [ 0 ] ;
struct V_42 * V_3 = V_24 -> V_3 ;
struct V_2 * V_26 = F_17 ( V_3 ) ;
struct V_61 * V_62 ;
F_2 ( V_3 -> V_10 , L_6 , V_11 , V_35 -> V_18 . V_4 ) ;
V_9 = F_1 ( V_26 , V_35 -> V_18 . V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_31 = (struct V_39 * ) V_35 -> V_44 ;
V_41 = (struct V_40 * ) V_31 -> V_41 ;
V_62 = F_21 ( V_9 -> V_10 ) ;
if ( V_31 -> V_47 == 2 )
F_6 ( V_24 -> V_75 -> V_10 ,
L_11 ,
V_35 -> V_18 . V_4 ) ;
V_38 = F_13 ( V_41 -> V_51 . integer . V_38 ) ;
V_78 = ( 1 << F_33 ( V_38 ) ) - 1 ;
V_79 = V_58 -> V_51 . integer . V_51 [ 0 ] & V_78 ;
V_77 = ! ! V_79 ;
if ( V_60 . V_51 . V_65 [ 0 ] != V_79 ) {
for ( V_76 = 0 ; V_76 < V_70 -> V_80 ; V_76 ++ ) {
V_24 = V_70 -> V_72 [ V_76 ] ;
V_24 -> V_51 = V_79 ;
V_24 -> V_75 -> V_81 = NULL ;
F_34 ( V_24 , V_35 ,
V_77 ) ;
}
V_60 . V_51 . V_65 [ 0 ] =
F_27 ( V_58 -> V_51 . integer . V_51 [ 0 ] ) ;
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_28 ( V_9 -> V_63 ,
V_31 -> V_56 ,
V_64 , & V_60 ) ;
F_24 ( V_62 ) ;
if ( V_6 ) {
F_25 ( V_3 -> V_10 ,
L_9 , V_6 ,
V_11 , V_35 -> V_18 . V_4 ) ;
return V_6 ;
}
}
return 0 ;
}
static int F_35 ( struct V_71 * V_82 ,
struct V_34 * V_83 , int V_84 )
{
return 0 ;
}
static int F_36 ( struct V_71 * V_82 ,
struct V_34 * V_83 , int V_84 )
{
return 0 ;
}
static int F_37 ( struct V_71 * V_82 ,
struct V_34 * V_83 , int V_84 )
{
return 0 ;
}
static int F_38 ( struct V_85 * V_82 )
{
int V_6 = 0 ;
switch ( V_82 -> type ) {
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
if ( V_82 -> V_91 )
V_6 = - V_21 ;
break;
case V_92 :
case V_93 :
if ( V_82 -> V_91 != 1 )
V_6 = - V_21 ;
break;
default:
break;
}
return V_6 ;
}
static int F_39 ( struct V_34 * V_35 ,
struct V_57 * V_58 )
{
int V_6 , V_56 ;
struct V_42 * V_3 = F_16 ( V_35 ) ;
struct V_94 * V_95 = (struct V_94 * ) V_35 -> V_44 ;
struct V_59 V_60 ;
struct V_1 * V_9 ;
struct V_2 * V_26 = F_17 ( V_3 ) ;
struct V_61 * V_62 ;
V_9 = F_1 ( V_26 , V_35 -> V_18 . V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_56 = F_8 ( V_9 , V_35 -> V_18 . V_4 ) ;
if ( V_56 < 0 )
return - V_21 ;
V_62 = F_21 ( V_9 -> V_10 ) ;
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_23 ( V_9 -> V_63 , V_56 ,
V_64 , & V_60 ) ;
F_24 ( V_62 ) ;
if ( V_6 ) {
F_25 ( V_3 -> V_10 , L_9 , V_6 ,
V_11 , V_35 -> V_18 . V_4 ) ;
return V_6 ;
}
V_58 -> V_51 . V_54 . V_55 [ 0 ] =
F_13 ( V_60 . V_51 . V_66 [ 0 ] ) ;
if ( V_95 -> V_96 != V_95 -> V_97 )
V_58 -> V_51 . V_54 . V_55 [ 1 ] =
F_13 ( V_60 . V_51 . V_66 [ 1 ] ) ;
return 0 ;
}
static int F_40 ( struct V_34 * V_35 ,
struct V_57 * V_58 )
{
int V_6 , V_56 ;
struct V_42 * V_3 = F_16 ( V_35 ) ;
struct V_94 * V_95 = (struct V_94 * ) V_35 -> V_44 ;
struct V_59 V_60 ;
struct V_1 * V_9 ;
struct V_2 * V_26 = F_17 ( V_3 ) ;
struct V_61 * V_62 ;
V_9 = F_1 ( V_26 , V_35 -> V_18 . V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_56 = F_8 ( V_9 , V_35 -> V_18 . V_4 ) ;
if ( V_56 < 0 )
return - V_21 ;
if ( V_58 -> V_51 . V_54 . V_55 [ 0 ] > V_95 -> V_38 - 1 )
return - V_21 ;
V_60 . V_51 . V_66 [ 0 ] =
F_27 ( V_58 -> V_51 . V_54 . V_55 [ 0 ] ) ;
if ( V_95 -> V_96 != V_95 -> V_97 ) {
if ( V_58 -> V_51 . V_54 . V_55 [ 1 ] > V_95 -> V_38 - 1 )
return - V_21 ;
V_60 . V_51 . V_66 [ 1 ] =
F_27 ( V_58 -> V_51 . V_54 . V_55 [ 1 ] ) ;
}
V_62 = F_21 ( V_9 -> V_10 ) ;
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_28 ( V_9 -> V_63 , V_56 ,
V_64 , & V_60 ) ;
F_24 ( V_62 ) ;
if ( V_6 ) {
F_25 ( V_3 -> V_10 , L_9 , V_6 ,
V_11 , V_35 -> V_18 . V_4 ) ;
}
return V_6 ;
}
static int F_41 ( struct V_1 * V_26 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_94 * V_102 ;
struct V_27 * V_103 ;
int V_30 ;
V_102 = F_14 ( V_26 -> V_10 , sizeof( * V_102 ) , V_32 ) ;
if ( ! V_102 )
return - V_104 ;
V_103 = & V_101 -> V_41 . V_51 . V_54 ;
V_102 -> V_38 = F_13 ( V_103 -> V_19 ) ;
V_102 -> V_20 = F_12 ( V_26 , V_103 ) ;
F_2 ( V_26 -> V_10 , L_12 , V_102 -> V_38 ,
F_42 ( V_103 -> V_105 ) ) ;
for ( V_30 = 0 ; V_30 < V_102 -> V_38 ; V_30 ++ )
F_2 ( V_26 -> V_10 , L_13 , V_30 , V_102 -> V_20 [ V_30 ] ) ;
* V_99 = (struct V_98 )
F_43 ( V_101 -> V_4 , * V_102 , F_39 ,
F_40 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_26 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
int V_6 = 0 ;
struct V_39 * V_106 ;
switch ( V_101 -> V_107 ) {
case V_108 :
switch ( V_101 -> V_41 . type ) {
case V_53 :
V_6 = F_41 ( V_26 , V_99 , V_101 ) ;
break;
default:
V_106 = F_14 ( V_26 -> V_10 ,
sizeof( struct V_39 ) ,
V_32 ) ;
if ( ! V_106 )
return - V_104 ;
V_106 -> V_56 = V_101 -> V_18 ;
V_106 -> V_109 = F_42 ( V_101 -> V_109 ) ;
V_106 -> V_45 = V_101 -> V_45 ;
V_106 -> V_47 = V_101 -> V_110 ;
V_106 -> V_41 = & V_101 -> V_41 ;
* V_99 = (struct V_98 )
F_45 ( V_101 -> V_4 , V_101 -> V_46 , V_106 ) ;
V_106 = NULL ;
break;
}
break;
default:
return - V_21 ;
}
F_2 ( V_26 -> V_10 , L_14 , V_101 -> V_4 , V_101 -> V_18 ) ;
return V_6 ;
}
static int F_46 ( struct V_34 * V_35 ,
struct V_57 * V_58 )
{
int V_6 , V_56 ;
struct V_69 * V_70 = F_16 ( V_35 ) ;
struct V_71 * V_24 = V_70 -> V_72 [ 0 ] ;
struct V_1 * V_9 ;
struct V_59 V_60 ;
struct V_42 * V_3 = V_24 -> V_3 ;
struct V_2 * V_26 = F_17 ( V_3 ) ;
struct V_94 * V_95 = (struct V_94 * ) V_35 -> V_44 ;
struct V_61 * V_62 ;
V_9 = F_1 ( V_26 , V_35 -> V_18 . V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_56 = F_9 ( V_9 , V_35 -> V_18 . V_4 ) ;
if ( V_56 < 0 )
return - V_21 ;
V_62 = F_21 ( V_9 -> V_10 ) ;
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_23 ( V_9 -> V_63 , V_56 ,
V_64 , & V_60 ) ;
F_24 ( V_62 ) ;
if ( V_6 ) {
F_25 ( V_3 -> V_10 , L_9 , V_6 ,
V_11 , V_35 -> V_18 . V_4 ) ;
return V_6 ;
}
V_58 -> V_51 . V_54 . V_55 [ 0 ] = V_60 . V_51 . V_66 [ 0 ] ;
if ( V_95 -> V_96 != V_95 -> V_97 )
V_58 -> V_51 . V_54 . V_55 [ 1 ] =
V_60 . V_51 . V_66 [ 1 ] ;
return 0 ;
}
static int F_47 ( struct V_34 * V_35 ,
struct V_57 * V_58 )
{
int V_6 , V_76 , V_56 ;
unsigned int V_79 , V_111 , V_112 ;
unsigned int V_78 ;
struct V_69 * V_70 = F_16 ( V_35 ) ;
struct V_71 * V_24 = V_70 -> V_72 [ 0 ] ;
struct V_59 V_60 ;
struct V_1 * V_9 ;
struct V_42 * V_3 = V_24 -> V_3 ;
struct V_2 * V_26 = F_17 ( V_3 ) ;
struct V_94 * V_95 = (struct V_94 * ) V_35 -> V_44 ;
struct V_61 * V_62 ;
if ( V_58 -> V_51 . V_54 . V_55 [ 0 ] > V_95 -> V_38 - 1 )
return - V_21 ;
V_9 = F_1 ( V_26 , V_35 -> V_18 . V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_56 = F_9 ( V_9 , V_35 -> V_18 . V_4 ) ;
if ( V_56 < 0 )
return - V_21 ;
V_112 = 0 ;
V_62 = F_21 ( V_9 -> V_10 ) ;
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_23 ( V_9 -> V_63 , V_56 ,
V_64 , & V_60 ) ;
F_24 ( V_62 ) ;
if ( V_6 ) {
F_25 ( V_3 -> V_10 , L_9 , V_6 ,
V_11 , V_35 -> V_18 . V_4 ) ;
return V_6 ;
}
V_111 = V_58 -> V_51 . V_54 . V_55 [ 0 ] ;
V_79 = V_111 << V_95 -> V_96 ;
V_78 = V_95 -> V_78 << V_95 -> V_96 ;
if ( V_60 . V_51 . V_66 [ 0 ] !=
V_58 -> V_51 . V_54 . V_55 [ 0 ] ) {
V_112 = 1 ;
V_60 . V_51 . V_66 [ 0 ] =
V_58 -> V_51 . V_54 . V_55 [ 0 ] ;
}
if ( V_95 -> V_96 != V_95 -> V_97 ) {
if ( V_58 -> V_51 . V_54 . V_55 [ 1 ] > V_95 -> V_38 - 1 )
return - V_21 ;
V_79 |= V_58 -> V_51 . V_54 . V_55 [ 1 ] << V_95 -> V_97 ;
V_78 |= V_95 -> V_78 << V_95 -> V_97 ;
if ( V_60 . V_51 . V_66 [ 1 ] !=
V_58 -> V_51 . V_54 . V_55 [ 1 ] ) {
V_112 = 1 ;
V_60 . V_51 . V_66 [ 1 ] =
V_58 -> V_51 . V_54 . V_55 [ 1 ] ;
}
}
if ( V_112 ) {
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_28 ( V_9 -> V_63 , V_56 ,
V_64 , & V_60 ) ;
F_24 ( V_62 ) ;
if ( V_6 ) {
F_25 ( V_3 -> V_10 ,
L_9 , V_6 ,
V_11 , V_35 -> V_18 . V_4 ) ;
}
for ( V_76 = 0 ; V_76 < V_70 -> V_80 ; V_76 ++ ) {
V_24 = V_70 -> V_72 [ V_76 ] ;
V_24 -> V_51 = V_79 ;
V_24 -> V_75 -> V_81 = NULL ;
F_48 ( V_24 , V_35 , V_111 , V_95 ) ;
}
}
return V_112 ;
}
static int F_49 ( struct V_1 * V_26 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_94 * V_102 ;
struct V_27 * V_103 ;
int V_30 ;
V_102 = F_14 ( V_26 -> V_10 , sizeof( * V_102 ) , V_32 ) ;
if ( ! V_102 )
return - V_104 ;
V_103 = & V_101 -> V_41 . V_51 . V_54 ;
V_102 -> V_38 = F_13 ( V_103 -> V_19 ) ;
V_102 -> V_20 = F_12 ( V_26 , V_103 ) ;
F_2 ( V_26 -> V_10 , L_12 , V_102 -> V_38 ,
F_42 ( V_103 -> V_105 ) ) ;
for ( V_30 = 0 ; V_30 < V_102 -> V_38 ; V_30 ++ )
F_2 ( V_26 -> V_10 , L_13 , V_30 , V_102 -> V_20 [ V_30 ] ) ;
* V_99 = (struct V_98 )
F_50 ( V_101 -> V_4 , * V_102 , F_46 ,
F_47 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_26 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_39 * V_106 ;
V_106 = F_14 ( V_26 -> V_10 , sizeof( struct V_39 ) ,
V_32 ) ;
if ( ! V_106 )
return - V_104 ;
V_106 -> V_56 = V_101 -> V_18 ;
V_106 -> V_109 = F_42 ( V_101 -> V_109 ) ;
V_106 -> V_45 = V_101 -> V_45 ;
V_106 -> V_47 = V_101 -> V_110 ;
V_106 -> V_41 = & V_101 -> V_41 ;
* V_99 = (struct V_98 )
F_52 ( V_101 -> V_4 , V_101 -> V_46 , V_106 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_26 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
int V_6 ;
switch ( V_101 -> V_107 ) {
case V_108 :
switch ( V_101 -> V_41 . type ) {
case V_53 :
V_6 = F_49 ( V_26 , V_99 , V_101 ) ;
break;
default:
V_6 = F_51 ( V_26 , V_99 , V_101 ) ;
break;
}
break;
default:
return - V_21 ;
}
F_2 ( V_26 -> V_10 , L_15 , V_101 -> V_4 ,
V_101 -> V_18 , V_6 ) ;
return V_6 ;
}
static int F_54 ( struct V_71 * V_82 ,
struct V_34 * V_35 , int V_84 )
{
int V_113 ;
int V_6 ;
struct V_42 * V_3 = V_82 -> V_3 ;
struct V_2 * V_43 = F_17 ( V_3 ) ;
struct V_1 * V_9 ;
struct V_61 * V_62 ;
F_2 ( V_3 -> V_10 , L_16 , V_11 , V_82 -> V_4 , V_84 ) ;
V_9 = F_1 ( V_43 , V_82 -> V_4 ) ;
if ( ! V_9 )
return - V_21 ;
V_113 = F_10 ( V_9 , V_82 -> V_4 ) ;
if ( V_113 < 0 ) {
F_18 ( V_3 -> V_10 , L_17 , V_82 -> V_4 ) ;
return - V_21 ;
}
V_62 = F_21 ( V_9 -> V_10 ) ;
V_6 = F_22 ( V_62 ) ;
if ( V_6 )
return V_6 ;
switch ( V_84 ) {
case V_114 :
V_6 = F_55 ( V_9 -> V_63 , V_113 ) ;
if ( ! V_6 )
V_6 = F_56 ( V_43 , V_82 , V_9 , 1 ) ;
break;
case V_115 :
V_6 = F_57 ( V_9 -> V_63 , V_113 ) ;
if ( ! V_6 )
V_6 = F_56 ( V_43 , V_82 , V_9 , 0 ) ;
break;
}
if ( V_6 )
F_25 ( V_3 -> V_10 ,
L_18 , V_113 ,
V_84 , V_6 ) ;
F_24 ( V_62 ) ;
return V_6 ;
}
static int F_58 ( struct V_1 * V_9 ,
struct V_71 * V_116 ,
struct V_85 * V_82 , int * V_117 )
{
int V_30 , V_6 , V_118 ;
struct V_98 * V_119 ;
struct V_100 * V_120 ;
struct V_15 * V_16 , * V_121 ;
T_2 V_122 ;
char V_123 [ V_8 ] ;
V_6 = F_38 ( V_82 ) ;
if ( V_6 ) {
F_18 ( V_9 -> V_10 , L_19 ,
V_82 -> V_91 , V_82 -> V_4 ) ;
return V_6 ;
}
if ( V_82 -> V_91 ) {
V_122 = sizeof( struct V_98 ) * V_82 -> V_91 ;
V_119 = F_14 ( V_9 -> V_10 , V_122 , V_32 ) ;
if ( ! V_119 )
return - V_104 ;
}
* V_117 = sizeof( struct V_85 ) ;
V_120 = V_82 -> V_101 ;
for ( V_30 = 0 ; V_30 < V_82 -> V_91 ; V_30 ++ ) {
V_6 = F_53 ( V_9 , & V_119 [ V_30 ] ,
V_120 ) ;
if ( V_6 ) {
F_18 ( V_9 -> V_10 ,
L_20 ,
V_120 -> V_4 , V_120 -> V_107 ) ;
goto error;
}
V_16 = F_14 ( V_9 -> V_10 ,
sizeof( struct V_15 ) ,
V_32 ) ;
if ( ! V_16 ) {
V_6 = - V_104 ;
goto error;
}
V_16 -> V_18 = V_120 -> V_18 ;
V_16 -> V_4 = V_120 -> V_4 ;
V_16 -> V_22 = V_82 -> V_4 ;
if ( V_120 -> V_41 . type == V_53 ) {
struct V_27 * V_28 =
& V_120 -> V_41 . V_51 . V_54 ;
V_118 = F_59 ( struct V_100 , V_41 ) ;
V_118 += F_59 ( struct V_40 , V_51 ) ;
V_118 += F_59 ( struct V_27 , V_33 ) ;
V_118 += F_42 ( V_28 -> V_105 ) ;
V_16 -> V_20 = ( const char * const * )
F_12 ( V_9 , V_28 ) ;
V_16 -> V_19 = F_13 ( V_28 -> V_19 ) ;
} else {
V_118 = sizeof( struct V_100 ) ;
}
* V_117 += V_118 ;
V_120 = ( void * ) V_120 + V_118 ;
F_60 ( & V_16 -> V_124 , & V_9 -> V_125 ) ;
F_2 ( V_9 -> V_10 , L_21 ,
V_119 [ V_30 ] . V_4 , V_119 [ V_30 ] . V_107 ) ;
}
F_19 ( V_123 , V_82 -> V_4 , V_8 ) ;
snprintf ( V_82 -> V_4 , V_8 , L_22 , V_9 -> V_5 , V_123 ) ;
switch ( V_82 -> type ) {
case V_86 :
* V_116 = (struct V_71 )
F_61 ( V_82 -> V_4 , F_35 ) ;
V_9 -> V_126 |= V_127 ;
break;
case V_87 :
* V_116 = (struct V_71 )
F_62 ( V_82 -> V_4 , F_36 ) ;
V_9 -> V_126 |= ( V_128
| V_129 ) ;
V_9 -> V_130 |= V_131 ;
break;
case V_88 :
* V_116 = (struct V_71 )
F_63 ( V_82 -> V_4 , F_37 ) ;
V_9 -> V_130 |= V_132 ;
break;
case V_89 :
* V_116 = (struct V_71 ) F_64 ( V_82 -> V_4 ) ;
break;
case V_90 :
* V_116 = (struct V_71 ) F_65 ( V_82 -> V_4 ) ;
break;
case V_92 :
* V_116 = (struct V_71 )
F_66 ( V_82 -> V_4 , V_133 , 0 , 0 ,
V_119 , F_54 ,
V_114 |
V_115 ) ;
break;
case V_134 :
* V_116 = (struct V_71 )
F_67 ( V_82 -> V_4 , V_133 , 0 , 0 , NULL , 0 ,
F_54 ,
V_114 |
V_115 ) ;
break;
case V_135 :
* V_116 = (struct V_71 )
F_68 ( V_82 -> V_4 , V_133 , 0 , 0 , NULL ,
0 , F_54 ,
V_114 |
V_115 ) ;
break;
case V_93 :
* V_116 = (struct V_71 )
F_69 ( V_82 -> V_4 , V_133 , 0 , 0 ,
V_119 , F_54 ,
V_114 |
V_115 ) ;
break;
case V_136 :
* V_116 = (struct V_71 )
F_70 ( V_82 -> V_4 , V_82 -> V_137 , 0 ,
V_133 ,
0 , 0 , F_54 ,
V_114 |
V_115 ) ;
break;
case V_138 :
* V_116 = (struct V_71 )
F_71 ( V_82 -> V_4 , V_82 -> V_137 , 0 ,
V_133 ,
0 , 0 , F_54 ,
V_114 |
V_115 ) ;
break;
default:
V_6 = - V_21 ;
goto error;
}
F_2 ( V_9 -> V_10 , L_23 , V_116 -> V_4 ,
V_116 -> V_18 ) ;
return 0 ;
error:
F_72 (control, _control, &module->widget_ctl_list,
list) {
F_73 ( & V_16 -> V_124 ) ;
F_74 ( V_9 -> V_10 , V_16 ) ;
}
return V_6 ;
}
static int F_75 ( struct V_1 * V_9 ,
struct V_100 * V_139 )
{
int V_30 , V_118 , V_6 ;
struct V_98 * V_140 ;
struct V_100 * V_120 ;
struct V_15 * V_16 , * V_121 ;
T_2 V_122 ;
char V_123 [ V_8 ] ;
V_122 = sizeof( struct V_98 ) * V_9 -> V_141 ;
V_140 = F_14 ( V_9 -> V_10 , V_122 , V_32 ) ;
if ( ! V_140 )
return - V_104 ;
V_120 = V_139 ;
for ( V_30 = 0 ; V_30 < V_9 -> V_141 ; V_30 ++ ) {
V_6 = F_44 ( V_9 , & V_140 [ V_30 ] ,
V_120 ) ;
if ( V_6 ) {
F_18 ( V_9 -> V_10 , L_24 ,
V_120 -> V_4 , V_120 -> V_107 ) ;
goto error;
}
V_16 = F_14 ( V_9 -> V_10 , sizeof( struct
V_15 ) ,
V_32 ) ;
if ( ! V_16 ) {
V_6 = - V_104 ;
goto error;
}
V_16 -> V_18 = V_120 -> V_18 ;
F_19 ( V_123 , V_120 -> V_4 , V_8 ) ;
snprintf ( V_120 -> V_4 , V_8 , L_22 , V_9 -> V_5 ,
V_123 ) ;
V_16 -> V_4 = V_120 -> V_4 ;
if ( V_120 -> V_41 . type == V_53 ) {
struct V_27 * V_28 =
& V_120 -> V_41 . V_51 . V_54 ;
V_118 = F_59 ( struct V_100 , V_41 ) ;
V_118 += F_59 ( struct V_40 , V_51 ) ;
V_118 += F_59 ( struct V_27 , V_33 ) ;
V_118 += F_42 ( V_28 -> V_105 ) ;
V_16 -> V_20 = ( const char * const * )
F_12 ( V_9 , V_28 ) ;
V_16 -> V_19 = F_13 ( V_28 -> V_19 ) ;
} else {
V_118 = sizeof( struct V_100 ) ;
}
F_60 ( & V_16 -> V_124 , & V_9 -> V_142 ) ;
F_2 ( V_9 -> V_10 , L_25 , V_120 -> V_18 ,
V_120 -> V_4 , V_120 -> V_41 . type ) ;
V_120 = ( void * ) V_120 + V_118 ;
}
V_9 -> V_139 = V_140 ;
return 0 ;
error:
F_72 (control, _control, &module->ctl_list,
list) {
F_73 ( & V_16 -> V_124 ) ;
F_74 ( V_9 -> V_10 , V_16 ) ;
}
F_74 ( V_9 -> V_10 , V_140 ) ;
return V_6 ;
}
static int F_76 ( struct V_1 * V_9 ,
struct V_85 * V_72 )
{
int V_30 , V_6 , V_117 ;
struct V_71 * V_143 ;
struct V_85 * V_120 ;
struct V_23 * V_24 , * V_144 ;
T_2 V_122 ;
V_122 = sizeof( struct V_71 ) * V_9 -> V_145 ;
V_143 = F_14 ( V_9 -> V_10 , V_122 , V_32 ) ;
if ( ! V_143 )
return - V_104 ;
V_120 = V_72 ;
for ( V_30 = 0 ; V_30 < V_9 -> V_145 ; V_30 ++ ) {
V_6 = F_58 ( V_9 , & V_143 [ V_30 ] ,
V_120 , & V_117 ) ;
if ( V_6 ) {
F_18 ( V_9 -> V_10 , L_24 ,
V_120 -> V_4 , V_120 -> type ) ;
goto error;
}
V_24 = F_14 ( V_9 -> V_10 , sizeof( struct
V_23 ) ,
V_32 ) ;
if ( ! V_24 ) {
V_6 = - V_104 ;
goto error;
}
V_24 -> V_18 = V_120 -> V_18 ;
V_24 -> V_4 = V_120 -> V_4 ;
F_60 ( & V_24 -> V_124 , & V_9 -> V_146 ) ;
V_120 = ( void * ) V_120 + V_117 ;
}
V_9 -> V_143 = V_143 ;
return 0 ;
error:
F_72 (widget, _widget, &module->widget_list,
list) {
F_73 ( & V_24 -> V_124 ) ;
F_74 ( V_9 -> V_10 , V_24 ) ;
}
F_74 ( V_9 -> V_10 , V_143 ) ;
return V_6 ;
}
static int F_77 ( struct V_1 * V_9 ,
struct V_147 * V_148 )
{
int V_30 , V_6 ;
struct V_149 * V_150 ;
struct V_147 * V_120 ;
T_2 V_122 ;
V_122 = sizeof( struct V_149 ) * V_9 -> V_151 ;
V_150 = F_14 ( V_9 -> V_10 , V_122 , V_32 ) ;
if ( ! V_150 )
return - V_104 ;
V_9 -> V_150 = V_150 ;
V_120 = V_148 ;
for ( V_30 = 0 ; V_30 < V_9 -> V_151 ; V_30 ++ ) {
V_150 -> V_152 =
F_11 ( V_9 , V_120 -> V_153 ) ;
if ( ! V_150 -> V_152 ) {
F_18 ( V_9 -> V_10 , L_26 ,
V_120 -> V_154 , V_120 -> V_153 ,
V_120 -> V_13 , V_120 -> V_14 ) ;
V_6 = - V_21 ;
goto error;
}
V_150 -> V_155 =
F_11 ( V_9 , V_120 -> V_154 ) ;
if ( ! V_150 -> V_155 ) {
F_18 ( V_9 -> V_10 , L_27 ,
V_120 -> V_154 , V_120 -> V_153 ,
V_120 -> V_13 , V_120 -> V_14 ) ;
V_6 = - V_21 ;
goto error;
}
V_150 -> V_16 =
F_7 ( V_9 ,
V_120 -> V_13 ,
V_120 -> V_14 ) ;
if ( ( V_120 -> V_13 != V_17 ) &&
! V_150 -> V_16 ) {
F_18 ( V_9 -> V_10 , L_28 ,
V_120 -> V_154 , V_120 -> V_153 ,
V_120 -> V_13 , V_120 -> V_14 ) ;
V_6 = - V_21 ;
goto error;
}
F_2 ( V_9 -> V_10 , L_29 , V_150 -> V_152 ,
( V_150 -> V_16 ) ? V_150 -> V_16 : L_30 ,
V_150 -> V_155 ) ;
V_150 ++ ;
V_120 ++ ;
}
return 0 ;
error:
F_74 ( V_9 -> V_10 , V_9 -> V_150 ) ;
return V_6 ;
}
static int F_78 ( struct V_1 * V_9 ,
struct V_156 * V_157 )
{
V_9 -> V_141 = V_157 -> V_141 ;
V_9 -> V_145 = V_157 -> V_80 ;
V_9 -> V_151 = V_157 -> V_158 ;
V_9 -> V_159 = ( unsigned long ) & V_157 -> V_31 ;
V_9 -> V_160 = V_9 -> V_159 +
F_13 ( V_157 -> V_161 ) ;
V_9 -> V_162 = V_9 -> V_160 +
F_13 ( V_157 -> V_163 ) ;
V_9 -> V_164 = V_9 -> V_162 +
F_13 ( V_157 -> V_165 ) ;
F_2 ( V_9 -> V_10 , L_31 , V_9 -> V_159 ) ;
F_2 ( V_9 -> V_10 , L_32 ,
V_9 -> V_160 ) ;
F_2 ( V_9 -> V_10 , L_33 , V_9 -> V_162 ) ;
F_2 ( V_9 -> V_10 , L_34 , V_9 -> V_164 ) ;
return 0 ;
}
int F_79 ( struct V_1 * V_9 ,
struct V_156 * V_157 )
{
int V_6 ;
struct V_100 * V_139 ;
struct V_85 * V_72 ;
struct V_147 * V_148 ;
unsigned int V_166 ;
if ( ! V_157 )
return - V_21 ;
V_6 = F_78 ( V_9 , V_157 ) ;
if ( V_6 ) {
F_18 ( V_9 -> V_10 , L_35 ,
V_6 ) ;
return V_6 ;
}
V_139 = (struct V_100 * ) V_9 -> V_160 ;
V_6 = F_75 ( V_9 , V_139 ) ;
if ( V_6 ) {
F_18 ( V_9 -> V_10 ,
L_36 , V_6 ) ;
return V_6 ;
}
F_2 ( V_9 -> V_10 , L_37 ) ;
V_72 = (struct V_85 * ) V_9 -> V_162 ;
V_6 = F_76 ( V_9 , V_72 ) ;
if ( V_6 ) {
F_18 ( V_9 -> V_10 ,
L_38 , V_6 ) ;
return V_6 ;
}
F_2 ( V_9 -> V_10 , L_39 ) ;
V_148 = (struct V_147 * ) V_9 -> V_164 ;
V_6 = F_77 ( V_9 , V_148 ) ;
if ( V_6 ) {
F_18 ( V_9 -> V_10 ,
L_40 , V_6 ) ;
return V_6 ;
}
F_2 ( V_9 -> V_10 , L_41 ) ;
V_166 = F_13 ( V_157 -> V_166 ) ;
if ( V_166 ) {
V_9 -> V_167 = V_166 & V_168 ;
V_9 -> V_169 = V_166 & V_170 ;
}
return V_6 ;
}
void F_80 ( struct V_1 * V_9 )
{
struct V_15 * V_16 , * V_121 ;
struct V_23 * V_24 , * V_144 ;
if ( ! V_9 -> V_171 )
return;
F_72 (control, _control, &module->ctl_list,
list) {
F_73 ( & V_16 -> V_124 ) ;
F_74 ( V_9 -> V_10 , V_16 ) ;
}
if ( V_9 -> V_139 )
F_74 ( V_9 -> V_10 , V_9 -> V_139 ) ;
F_72 (control, _control, &module->widget_ctl_list,
list) {
F_73 ( & V_16 -> V_124 ) ;
F_74 ( V_9 -> V_10 , V_16 ) ;
}
F_72 (widget, _widget, &module->widget_list,
list) {
F_73 ( & V_24 -> V_124 ) ;
F_74 ( V_9 -> V_10 , V_24 ) ;
}
if ( V_9 -> V_143 )
F_74 ( V_9 -> V_10 , V_9 -> V_143 ) ;
if ( V_9 -> V_150 )
F_74 ( V_9 -> V_10 , V_9 -> V_150 ) ;
}
