static struct V_1 * F_1 ( int V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_1 * V_6 ;
F_2 (report, &hdev->report_enum[dir].report_list, list) {
if ( V_6 -> V_2 == V_2 )
return V_6 ;
}
F_3 ( V_4 , L_1 , V_2 ) ;
return NULL ;
}
static int F_4 (
struct V_7 * V_8 )
{
struct V_1 * V_6 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
F_2 (report, &report_enum->report_list, list) {
V_10 = V_6 -> V_10 [ 0 ] ;
if ( V_6 -> V_12 && V_10 && V_10 -> V_13 )
V_11 ++ ;
}
return V_11 ;
}
static void F_5 (
struct V_14 * V_15 ,
T_1 V_16 , T_1 V_17 , struct V_9 * V_10 )
{
V_15 -> V_16 = V_16 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_18 = V_10 -> V_19 ;
V_15 -> V_20 = V_10 -> V_21 ;
V_15 -> V_22 = ( V_10 -> V_23 * V_10 -> V_24 ) / 8 ;
V_15 -> V_25 = V_10 -> V_25 ;
V_15 -> V_26 = V_10 -> V_26 ;
}
static struct V_27 * F_6 (
struct V_3 * V_4 ,
T_2 V_28 , void * * V_29 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 = F_7 ( V_4 ) ;
F_8 ( & V_33 -> V_34 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_31 -> V_28 == V_28 ) {
* V_29 = V_31 -> V_29 ;
F_9 ( & V_33 -> V_34 ) ;
return V_31 -> V_35 ;
}
F_9 ( & V_33 -> V_34 ) ;
return NULL ;
}
int F_10 ( struct V_36 * V_37 ,
T_2 V_28 ,
struct V_27 * V_35 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 = F_7 ( V_37 -> V_4 ) ;
F_8 ( & V_33 -> V_34 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_31 -> V_28 == V_28 ) {
F_9 ( & V_33 -> V_34 ) ;
return - V_38 ;
}
V_31 = F_11 ( sizeof( * V_31 ) , V_39 ) ;
if ( ! V_31 ) {
F_9 ( & V_33 -> V_34 ) ;
return - V_40 ;
}
V_31 -> V_35 = V_35 ;
V_31 -> V_28 = V_28 ;
V_31 -> V_29 = NULL ;
F_12 ( & V_31 -> V_41 , & V_33 -> V_42 ) ;
F_9 ( & V_33 -> V_34 ) ;
return 0 ;
}
int F_13 ( struct V_36 * V_37 ,
T_2 V_28 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 = F_7 ( V_37 -> V_4 ) ;
F_8 ( & V_33 -> V_34 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_31 -> V_28 == V_28 ) {
F_14 ( & V_31 -> V_41 ) ;
F_15 ( V_31 ) ;
break;
}
F_9 ( & V_33 -> V_34 ) ;
return 0 ;
}
int F_16 ( struct V_36 * V_37 , T_2 V_17 ,
T_2 V_43 , T_1 V_44 )
{
struct V_1 * V_6 ;
struct V_32 * V_45 = F_7 ( V_37 -> V_4 ) ;
int V_46 = 0 ;
F_17 ( & V_45 -> V_47 ) ;
V_6 = F_1 ( V_17 , V_37 -> V_4 , V_48 ) ;
if ( ! V_6 || ( V_43 >= V_6 -> V_12 ) ) {
V_46 = - V_38 ;
goto V_49;
}
F_18 ( V_6 -> V_10 [ V_43 ] , 0 , V_44 ) ;
F_19 ( V_37 -> V_4 , V_6 , V_50 ) ;
F_20 ( V_37 -> V_4 ) ;
V_49:
F_21 ( & V_45 -> V_47 ) ;
return V_46 ;
}
int F_22 ( struct V_36 * V_37 , T_2 V_17 ,
T_2 V_43 , T_1 * V_44 )
{
struct V_1 * V_6 ;
struct V_32 * V_45 = F_7 ( V_37 -> V_4 ) ;
int V_46 = 0 ;
F_17 ( & V_45 -> V_47 ) ;
V_6 = F_1 ( V_17 , V_37 -> V_4 , V_48 ) ;
if ( ! V_6 || ( V_43 >= V_6 -> V_12 ) ||
V_6 -> V_10 [ V_43 ] -> V_24 < 1 ) {
V_46 = - V_38 ;
goto V_49;
}
F_19 ( V_37 -> V_4 , V_6 , V_51 ) ;
F_20 ( V_37 -> V_4 ) ;
* V_44 = V_6 -> V_10 [ V_43 ] -> V_44 [ 0 ] ;
V_49:
F_21 ( & V_45 -> V_47 ) ;
return V_46 ;
}
int F_23 ( struct V_36 * V_37 ,
T_2 V_28 ,
T_2 V_52 , T_2 V_17 )
{
struct V_32 * V_45 = F_7 ( V_37 -> V_4 ) ;
unsigned long V_53 ;
struct V_1 * V_6 ;
int V_54 = 0 ;
F_17 ( & V_45 -> V_47 ) ;
memset ( & V_45 -> V_55 , 0 , sizeof( V_45 -> V_55 ) ) ;
F_24 ( & V_45 -> V_55 . V_56 ) ;
V_45 -> V_55 . V_28 = V_28 ;
V_45 -> V_55 . V_52 = V_52 ;
V_45 -> V_55 . V_57 = 0 ;
F_25 ( & V_45 -> V_58 , V_53 ) ;
V_45 -> V_55 . V_59 = true ;
V_6 = F_1 ( V_17 , V_37 -> V_4 , V_60 ) ;
if ( ! V_6 ) {
F_26 ( & V_45 -> V_58 , V_53 ) ;
goto V_61;
}
F_19 ( V_37 -> V_4 , V_6 , V_51 ) ;
F_26 ( & V_45 -> V_58 , V_53 ) ;
F_27 ( & V_45 -> V_55 . V_56 , V_62 * 5 ) ;
switch ( V_45 -> V_55 . V_57 ) {
case 1 :
V_54 = * ( V_63 * ) V_45 -> V_55 . V_64 ;
break;
case 2 :
V_54 = * ( V_65 * ) V_45 -> V_55 . V_64 ;
break;
case 4 :
V_54 = * ( T_2 * ) V_45 -> V_55 . V_64 ;
break;
default:
V_54 = 0 ;
}
F_15 ( V_45 -> V_55 . V_64 ) ;
V_61:
V_45 -> V_55 . V_59 = false ;
F_21 ( & V_45 -> V_47 ) ;
return V_54 ;
}
int F_28 ( struct V_36 * V_37 ,
V_63 type ,
T_2 V_28 ,
T_2 V_52 ,
struct V_14 * V_15 )
{
int V_46 = - 1 ;
int V_66 , V_67 ;
int V_68 = - 1 ;
struct V_1 * V_6 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
struct V_3 * V_4 = V_37 -> V_4 ;
V_15 -> V_28 = V_28 ;
V_15 -> V_69 = V_52 ;
V_15 -> V_17 = - 1 ;
V_15 -> V_16 = - 1 ;
V_15 -> V_18 = - 1 ;
V_15 -> V_20 = - 1 ;
for ( V_66 = 0 ; V_66 < V_4 -> V_70 ; ++ V_66 ) {
struct V_71 * V_72 = & V_4 -> V_72 [ V_66 ] ;
if ( V_28 == V_72 -> V_73 ) {
V_68 = V_66 ;
break;
}
}
if ( V_68 == - 1 )
goto V_74;
V_8 = & V_4 -> V_8 [ type ] ;
F_2 (report, &report_enum->report_list, list) {
for ( V_66 = 0 ; V_66 < V_6 -> V_12 ; ++ V_66 ) {
V_10 = V_6 -> V_10 [ V_66 ] ;
if ( V_10 -> V_13 == V_28 &&
V_10 -> V_75 == V_52 ) {
F_5 ( V_15 , V_66 , V_6 -> V_2 ,
V_10 ) ;
V_46 = 0 ;
} else {
for ( V_67 = 0 ; V_67 < V_10 -> V_76 ; ++ V_67 ) {
if ( V_10 -> V_73 [ V_67 ] . V_77 ==
V_52 &&
V_10 -> V_73 [ V_67 ] . V_68 ==
V_68 ) {
F_5 ( V_15 ,
V_66 , V_6 -> V_2 , V_10 ) ;
V_46 = 0 ;
break;
}
}
}
if ( V_46 == 0 )
break;
}
}
V_74:
return V_46 ;
}
static int F_29 ( struct V_3 * V_4 , T_3 V_78 )
{
struct V_32 * V_33 = F_7 ( V_4 ) ;
struct V_30 * V_31 ;
F_30 ( V_4 , L_2 ) ;
F_8 ( & V_33 -> V_34 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_31 -> V_35 -> V_79 )
V_31 -> V_35 -> V_79 (
V_33 -> V_37 , V_31 -> V_29 ) ;
}
F_9 ( & V_33 -> V_34 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_4 ) ;
struct V_30 * V_31 ;
F_30 ( V_4 , L_3 ) ;
F_8 ( & V_33 -> V_34 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_31 -> V_35 -> V_80 )
V_31 -> V_35 -> V_80 (
V_33 -> V_37 , V_31 -> V_29 ) ;
}
F_9 ( & V_33 -> V_34 ) ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_1 * V_6 , V_63 * V_64 , int V_22 )
{
int V_66 ;
V_63 * V_81 ;
int V_82 ;
struct V_32 * V_33 = F_7 ( V_4 ) ;
unsigned long V_53 ;
struct V_27 * V_31 = NULL ;
struct V_71 * V_72 = NULL ;
void * V_29 = NULL ;
F_30 ( V_4 , L_4 ,
V_6 -> V_2 , V_22 , V_6 -> type ) ;
F_30 ( V_4 , L_5 , V_6 -> V_12 ) ;
if ( V_6 -> type != V_60 )
return 1 ;
V_81 = V_64 ;
V_81 ++ ;
F_25 ( & V_33 -> V_58 , V_53 ) ;
for ( V_66 = 0 ; V_66 < V_6 -> V_12 ; ++ V_66 ) {
F_30 ( V_4 , L_6 ,
V_66 , V_6 -> V_10 [ V_66 ] -> V_73 -> V_68 ,
V_6 -> V_10 [ V_66 ] -> V_73 -> V_77 ,
( V_6 -> V_10 [ V_66 ] -> V_23 *
V_6 -> V_10 [ V_66 ] -> V_24 ) / 8 ) ;
V_82 = ( V_6 -> V_10 [ V_66 ] -> V_23 *
V_6 -> V_10 [ V_66 ] -> V_24 ) / 8 ;
if ( V_33 -> V_55 . V_59 && V_33 -> V_55 . V_52 ==
V_6 -> V_10 [ V_66 ] -> V_73 -> V_77 ) {
F_30 ( V_4 , L_7 ) ;
V_33 -> V_55 . V_64 = F_34 ( V_81 , V_82 , V_39 ) ;
if ( V_33 -> V_55 . V_64 )
V_33 -> V_55 . V_57 = V_82 ;
else
V_33 -> V_55 . V_57 = 0 ;
F_35 ( & V_33 -> V_55 . V_56 ) ;
}
V_72 = & V_4 -> V_72 [
V_6 -> V_10 [ V_66 ] -> V_73 -> V_68 ] ;
F_30 ( V_4 , L_8 ,
V_72 -> V_73 ) ;
V_31 = F_6 ( V_33 -> V_37 -> V_4 ,
V_6 -> V_10 [ V_66 ] -> V_13 ,
& V_29 ) ;
if ( V_31 && V_31 -> V_83 ) {
if ( V_6 -> V_10 [ V_66 ] -> V_75 )
V_31 -> V_83 ( V_33 -> V_37 ,
V_6 -> V_10 [ V_66 ] -> V_75 , V_82 , V_81 ,
V_31 -> V_84 ) ;
else
V_31 -> V_83 ( V_33 -> V_37 ,
V_6 -> V_10 [ V_66 ] -> V_73 -> V_77 , V_82 , V_81 ,
V_31 -> V_84 ) ;
}
V_81 += V_82 ;
}
if ( V_31 && V_72 && V_31 -> V_85 )
V_31 -> V_85 ( V_33 -> V_37 , V_72 -> V_73 ,
V_31 -> V_84 ) ;
F_26 ( & V_33 -> V_58 , V_53 ) ;
return 1 ;
}
int F_36 ( struct V_36 * V_37 )
{
int V_46 = 0 ;
struct V_32 * V_45 = F_7 ( V_37 -> V_4 ) ;
F_17 ( & V_45 -> V_47 ) ;
if ( ! V_37 -> V_86 ) {
V_46 = F_37 ( V_37 -> V_4 ) ;
if ( V_46 ) {
F_38 ( V_37 -> V_4 , L_9 ) ;
F_21 ( & V_45 -> V_47 ) ;
return V_46 ;
}
}
V_37 -> V_86 ++ ;
F_21 ( & V_45 -> V_47 ) ;
return V_46 ;
}
void F_39 ( struct V_36 * V_37 )
{
struct V_32 * V_45 = F_7 ( V_37 -> V_4 ) ;
F_17 ( & V_45 -> V_47 ) ;
V_37 -> V_86 -- ;
if ( ! V_37 -> V_86 )
F_40 ( V_37 -> V_4 ) ;
F_21 ( & V_45 -> V_47 ) ;
}
static int F_41 ( struct V_3 * V_4 ,
const struct V_87 * V_2 )
{
int V_46 ;
struct V_32 * V_88 ;
int V_66 ;
char * V_89 ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_90 ;
V_88 = F_42 ( & V_4 -> V_91 , sizeof( * V_88 ) , V_92 ) ;
if ( ! V_88 ) {
F_38 ( V_4 , L_10 ) ;
return - V_40 ;
}
V_88 -> V_37 = F_42 ( & V_4 -> V_91 , sizeof( * V_88 -> V_37 ) , V_92 ) ;
if ( ! V_88 -> V_37 ) {
F_38 ( V_4 , L_11 ) ;
return - V_40 ;
}
F_43 ( V_4 , V_88 ) ;
V_88 -> V_37 -> V_4 = V_4 ;
V_88 -> V_37 -> V_93 = V_4 -> V_94 ;
V_88 -> V_37 -> V_95 = V_4 -> V_96 ;
F_44 ( & V_88 -> V_58 ) ;
F_44 ( & V_88 -> V_34 ) ;
F_45 ( & V_88 -> V_47 ) ;
V_46 = F_46 ( V_4 ) ;
if ( V_46 ) {
F_38 ( V_4 , L_12 ) ;
return V_46 ;
}
F_47 ( & V_4 -> V_97 ) ;
V_46 = F_48 ( V_4 , 0 ) ;
if ( V_46 ) {
F_38 ( V_4 , L_13 ) ;
return V_46 ;
}
F_47 ( & V_88 -> V_42 ) ;
V_88 -> V_98 = 0 ;
V_8 = & V_4 -> V_8 [ V_60 ] ;
V_90 = F_4 ( V_8 ) ;
if ( V_90 > V_99 ) {
F_38 ( V_4 , L_14 ) ;
V_46 = - V_38 ;
goto V_100;
}
V_88 -> V_101 = F_11 ( V_90 *
sizeof( struct V_102 ) ,
V_92 ) ;
if ( V_88 -> V_101 == NULL ) {
F_38 ( V_4 , L_15 ) ;
V_46 = - V_40 ;
goto V_100;
}
F_2 (report, &report_enum->report_list, list) {
F_30 ( V_4 , L_16 , V_6 -> V_2 ) ;
V_10 = V_6 -> V_10 [ 0 ] ;
if ( V_6 -> V_12 && V_10 &&
V_10 -> V_13 ) {
V_89 = F_49 ( V_92 , L_17 ,
V_10 -> V_13 ) ;
if ( V_89 == NULL ) {
F_38 ( V_4 , L_18 ) ;
V_46 = - V_40 ;
goto V_103;
}
V_88 -> V_101 [
V_88 -> V_98 ] . V_2 = V_104 ;
V_88 -> V_101 [
V_88 -> V_98 ] . V_89 = V_89 ;
V_88 -> V_101 [
V_88 -> V_98 ] . V_105 =
V_88 -> V_37 ;
V_88 -> V_101 [
V_88 -> V_98 ] . V_106 =
sizeof( * V_88 -> V_37 ) ;
F_30 ( V_4 , L_19 , V_89 , V_88 ) ;
V_88 -> V_98 ++ ;
}
}
V_46 = F_50 ( & V_4 -> V_91 , 0 , V_88 -> V_101 ,
V_88 -> V_98 , NULL , 0 , NULL ) ;
if ( V_46 < 0 )
goto V_103;
return V_46 ;
V_103:
for ( V_66 = 0 ; V_66 < V_88 -> V_98 ; ++ V_66 )
F_15 ( V_88 -> V_101 [ V_66 ] . V_89 ) ;
F_15 ( V_88 -> V_101 ) ;
V_100:
F_51 ( V_4 ) ;
return V_46 ;
}
static void F_52 ( struct V_3 * V_4 )
{
struct V_32 * V_45 = F_7 ( V_4 ) ;
unsigned long V_53 ;
int V_66 ;
F_30 ( V_4 , L_20 ) ;
F_40 ( V_4 ) ;
F_51 ( V_4 ) ;
F_25 ( & V_45 -> V_58 , V_53 ) ;
if ( V_45 -> V_55 . V_59 )
F_35 ( & V_45 -> V_55 . V_56 ) ;
F_26 ( & V_45 -> V_58 , V_53 ) ;
F_53 ( & V_4 -> V_91 ) ;
for ( V_66 = 0 ; V_66 < V_45 -> V_98 ; ++ V_66 )
F_15 ( V_45 -> V_101 [ V_66 ] . V_89 ) ;
F_15 ( V_45 -> V_101 ) ;
F_43 ( V_4 , NULL ) ;
F_54 ( & V_45 -> V_47 ) ;
}
