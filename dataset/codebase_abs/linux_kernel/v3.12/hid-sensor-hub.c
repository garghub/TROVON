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
T_1 V_16 , T_1 V_17 , T_1 V_18 , T_1 V_19 , T_1 V_20 )
{
V_15 -> V_16 = V_16 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_20 = V_20 / 8 ;
}
static struct V_21 * F_6 (
struct V_3 * V_4 ,
T_2 V_22 , void * * V_23 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 = F_7 ( V_4 ) ;
F_8 ( & V_27 -> V_28 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_25 -> V_22 == V_22 ) {
* V_23 = V_25 -> V_23 ;
F_9 ( & V_27 -> V_28 ) ;
return V_25 -> V_29 ;
}
F_9 ( & V_27 -> V_28 ) ;
return NULL ;
}
int F_10 ( struct V_30 * V_31 ,
T_2 V_22 ,
struct V_21 * V_29 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 = F_7 ( V_31 -> V_4 ) ;
F_8 ( & V_27 -> V_28 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_25 -> V_22 == V_22 ) {
F_9 ( & V_27 -> V_28 ) ;
return - V_32 ;
}
V_25 = F_11 ( sizeof( * V_25 ) , V_33 ) ;
if ( ! V_25 ) {
F_9 ( & V_27 -> V_28 ) ;
return - V_34 ;
}
V_25 -> V_29 = V_29 ;
V_25 -> V_22 = V_22 ;
V_25 -> V_23 = NULL ;
F_12 ( & V_25 -> V_35 , & V_27 -> V_36 ) ;
F_9 ( & V_27 -> V_28 ) ;
return 0 ;
}
int F_13 ( struct V_30 * V_31 ,
T_2 V_22 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 = F_7 ( V_31 -> V_4 ) ;
F_8 ( & V_27 -> V_28 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_25 -> V_22 == V_22 ) {
F_14 ( & V_25 -> V_35 ) ;
F_15 ( V_25 ) ;
break;
}
F_9 ( & V_27 -> V_28 ) ;
return 0 ;
}
int F_16 ( struct V_30 * V_31 , T_2 V_17 ,
T_2 V_37 , T_1 V_38 )
{
struct V_1 * V_6 ;
struct V_26 * V_39 = F_7 ( V_31 -> V_4 ) ;
int V_40 = 0 ;
F_17 ( & V_39 -> V_41 ) ;
V_6 = F_1 ( V_17 , V_31 -> V_4 , V_42 ) ;
if ( ! V_6 || ( V_37 >= V_6 -> V_12 ) ) {
V_40 = - V_32 ;
goto V_43;
}
F_18 ( V_6 -> V_10 [ V_37 ] , 0 , V_38 ) ;
F_19 ( V_31 -> V_4 , V_6 , V_44 ) ;
F_20 ( V_31 -> V_4 ) ;
V_43:
F_21 ( & V_39 -> V_41 ) ;
return V_40 ;
}
int F_22 ( struct V_30 * V_31 , T_2 V_17 ,
T_2 V_37 , T_1 * V_38 )
{
struct V_1 * V_6 ;
struct V_26 * V_39 = F_7 ( V_31 -> V_4 ) ;
int V_40 = 0 ;
F_17 ( & V_39 -> V_41 ) ;
V_6 = F_1 ( V_17 , V_31 -> V_4 , V_42 ) ;
if ( ! V_6 || ( V_37 >= V_6 -> V_12 ) ||
V_6 -> V_10 [ V_37 ] -> V_45 < 1 ) {
V_40 = - V_32 ;
goto V_43;
}
F_19 ( V_31 -> V_4 , V_6 , V_46 ) ;
F_20 ( V_31 -> V_4 ) ;
* V_38 = V_6 -> V_10 [ V_37 ] -> V_38 [ 0 ] ;
V_43:
F_21 ( & V_39 -> V_41 ) ;
return V_40 ;
}
int F_23 ( struct V_30 * V_31 ,
T_2 V_22 ,
T_2 V_47 , T_2 V_17 )
{
struct V_26 * V_39 = F_7 ( V_31 -> V_4 ) ;
unsigned long V_48 ;
struct V_1 * V_6 ;
int V_49 = 0 ;
F_17 ( & V_39 -> V_41 ) ;
memset ( & V_39 -> V_50 , 0 , sizeof( V_39 -> V_50 ) ) ;
F_24 ( & V_39 -> V_50 . V_51 ) ;
V_39 -> V_50 . V_22 = V_22 ;
V_39 -> V_50 . V_47 = V_47 ;
V_39 -> V_50 . V_52 = 0 ;
F_25 ( & V_39 -> V_53 , V_48 ) ;
V_39 -> V_50 . V_54 = true ;
V_6 = F_1 ( V_17 , V_31 -> V_4 , V_55 ) ;
if ( ! V_6 ) {
F_26 ( & V_39 -> V_53 , V_48 ) ;
goto V_56;
}
F_19 ( V_31 -> V_4 , V_6 , V_46 ) ;
F_26 ( & V_39 -> V_53 , V_48 ) ;
F_27 ( & V_39 -> V_50 . V_51 , V_57 * 5 ) ;
switch ( V_39 -> V_50 . V_52 ) {
case 1 :
V_49 = * ( V_58 * ) V_39 -> V_50 . V_59 ;
break;
case 2 :
V_49 = * ( V_60 * ) V_39 -> V_50 . V_59 ;
break;
case 4 :
V_49 = * ( T_2 * ) V_39 -> V_50 . V_59 ;
break;
default:
V_49 = 0 ;
}
F_15 ( V_39 -> V_50 . V_59 ) ;
V_56:
V_39 -> V_50 . V_54 = false ;
F_21 ( & V_39 -> V_41 ) ;
return V_49 ;
}
int F_28 ( struct V_30 * V_31 ,
V_58 type ,
T_2 V_22 ,
T_2 V_47 ,
struct V_14 * V_15 )
{
int V_40 = - 1 ;
int V_61 , V_62 ;
int V_63 = - 1 ;
struct V_1 * V_6 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
struct V_3 * V_4 = V_31 -> V_4 ;
V_15 -> V_22 = V_22 ;
V_15 -> V_64 = V_47 ;
V_15 -> V_17 = - 1 ;
V_15 -> V_16 = - 1 ;
V_15 -> V_18 = - 1 ;
V_15 -> V_19 = - 1 ;
for ( V_61 = 0 ; V_61 < V_4 -> V_65 ; ++ V_61 ) {
struct V_66 * V_67 = & V_4 -> V_67 [ V_61 ] ;
if ( V_22 == V_67 -> V_68 ) {
V_63 = V_61 ;
break;
}
}
if ( V_63 == - 1 )
goto V_69;
V_8 = & V_4 -> V_8 [ type ] ;
F_2 (report, &report_enum->report_list, list) {
for ( V_61 = 0 ; V_61 < V_6 -> V_12 ; ++ V_61 ) {
V_10 = V_6 -> V_10 [ V_61 ] ;
if ( V_10 -> V_13 == V_22 &&
V_10 -> V_70 == V_47 ) {
F_5 ( V_15 , V_61 , V_6 -> V_2 ,
V_10 -> V_71 , V_10 -> V_72 ,
V_10 -> V_73 ) ;
V_40 = 0 ;
} else {
for ( V_62 = 0 ; V_62 < V_10 -> V_74 ; ++ V_62 ) {
if ( V_10 -> V_68 [ V_62 ] . V_75 ==
V_47 &&
V_10 -> V_68 [ V_62 ] . V_63 ==
V_63 ) {
F_5 ( V_15 ,
V_61 , V_6 -> V_2 ,
V_10 -> V_71 ,
V_10 -> V_72 ,
V_10 -> V_73 ) ;
V_40 = 0 ;
break;
}
}
}
if ( V_40 == 0 )
break;
}
}
V_69:
return V_40 ;
}
static int F_29 ( struct V_3 * V_4 , T_3 V_76 )
{
struct V_26 * V_27 = F_7 ( V_4 ) ;
struct V_24 * V_25 ;
F_30 ( V_4 , L_2 ) ;
F_8 ( & V_27 -> V_28 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_25 -> V_29 -> V_77 )
V_25 -> V_29 -> V_77 (
V_27 -> V_31 , V_25 -> V_23 ) ;
}
F_9 ( & V_27 -> V_28 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_26 * V_27 = F_7 ( V_4 ) ;
struct V_24 * V_25 ;
F_30 ( V_4 , L_3 ) ;
F_8 ( & V_27 -> V_28 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_25 -> V_29 -> V_78 )
V_25 -> V_29 -> V_78 (
V_27 -> V_31 , V_25 -> V_23 ) ;
}
F_9 ( & V_27 -> V_28 ) ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_1 * V_6 , V_58 * V_59 , int V_20 )
{
int V_61 ;
V_58 * V_79 ;
int V_80 ;
struct V_26 * V_27 = F_7 ( V_4 ) ;
unsigned long V_48 ;
struct V_21 * V_25 = NULL ;
struct V_66 * V_67 = NULL ;
void * V_23 = NULL ;
F_30 ( V_4 , L_4 ,
V_6 -> V_2 , V_20 , V_6 -> type ) ;
F_30 ( V_4 , L_5 , V_6 -> V_12 ) ;
if ( V_6 -> type != V_55 )
return 1 ;
V_79 = V_59 ;
V_79 ++ ;
F_25 ( & V_27 -> V_53 , V_48 ) ;
for ( V_61 = 0 ; V_61 < V_6 -> V_12 ; ++ V_61 ) {
F_30 ( V_4 , L_6 ,
V_61 , V_6 -> V_10 [ V_61 ] -> V_68 -> V_63 ,
V_6 -> V_10 [ V_61 ] -> V_68 -> V_75 ,
V_6 -> V_10 [ V_61 ] -> V_73 / 8 ) ;
V_80 = V_6 -> V_10 [ V_61 ] -> V_73 / 8 ;
if ( V_27 -> V_50 . V_54 && V_27 -> V_50 . V_47 ==
V_6 -> V_10 [ V_61 ] -> V_68 -> V_75 ) {
F_30 ( V_4 , L_7 ) ;
V_27 -> V_50 . V_59 = F_34 ( V_79 , V_80 , V_33 ) ;
if ( V_27 -> V_50 . V_59 )
V_27 -> V_50 . V_52 = V_80 ;
else
V_27 -> V_50 . V_52 = 0 ;
F_35 ( & V_27 -> V_50 . V_51 ) ;
}
V_67 = & V_4 -> V_67 [
V_6 -> V_10 [ V_61 ] -> V_68 -> V_63 ] ;
F_30 ( V_4 , L_8 ,
V_67 -> V_68 ) ;
V_25 = F_6 ( V_27 -> V_31 -> V_4 ,
V_6 -> V_10 [ V_61 ] -> V_13 ,
& V_23 ) ;
if ( V_25 && V_25 -> V_81 ) {
if ( V_6 -> V_10 [ V_61 ] -> V_70 )
V_25 -> V_81 ( V_27 -> V_31 ,
V_6 -> V_10 [ V_61 ] -> V_70 , V_80 , V_79 ,
V_25 -> V_82 ) ;
else
V_25 -> V_81 ( V_27 -> V_31 ,
V_6 -> V_10 [ V_61 ] -> V_68 -> V_75 , V_80 , V_79 ,
V_25 -> V_82 ) ;
}
V_79 += V_80 ;
}
if ( V_25 && V_67 && V_25 -> V_83 )
V_25 -> V_83 ( V_27 -> V_31 , V_67 -> V_68 ,
V_25 -> V_82 ) ;
F_26 ( & V_27 -> V_53 , V_48 ) ;
return 1 ;
}
static int F_36 ( struct V_3 * V_4 ,
const struct V_84 * V_2 )
{
int V_40 ;
struct V_26 * V_85 ;
int V_61 ;
char * V_86 ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_87 ;
V_85 = F_37 ( & V_4 -> V_88 , sizeof( * V_85 ) , V_89 ) ;
if ( ! V_85 ) {
F_38 ( V_4 , L_9 ) ;
return - V_34 ;
}
V_85 -> V_31 = F_37 ( & V_4 -> V_88 , sizeof( * V_85 -> V_31 ) , V_89 ) ;
if ( ! V_85 -> V_31 ) {
F_38 ( V_4 , L_10 ) ;
return - V_34 ;
}
F_39 ( V_4 , V_85 ) ;
V_85 -> V_31 -> V_4 = V_4 ;
V_85 -> V_31 -> V_90 = V_4 -> V_91 ;
V_85 -> V_31 -> V_92 = V_4 -> V_93 ;
F_40 ( & V_85 -> V_53 ) ;
F_40 ( & V_85 -> V_28 ) ;
F_41 ( & V_85 -> V_41 ) ;
V_40 = F_42 ( V_4 ) ;
if ( V_40 ) {
F_38 ( V_4 , L_11 ) ;
return V_40 ;
}
F_43 ( & V_4 -> V_94 ) ;
V_40 = F_44 ( V_4 , 0 ) ;
if ( V_40 ) {
F_38 ( V_4 , L_12 ) ;
return V_40 ;
}
V_40 = F_45 ( V_4 ) ;
if ( V_40 ) {
F_38 ( V_4 , L_13 ) ;
goto V_95;
}
F_43 ( & V_85 -> V_36 ) ;
V_85 -> V_96 = 0 ;
V_8 = & V_4 -> V_8 [ V_55 ] ;
V_87 = F_4 ( V_8 ) ;
if ( V_87 > V_97 ) {
F_38 ( V_4 , L_14 ) ;
V_40 = - V_32 ;
goto V_98;
}
V_85 -> V_99 = F_11 ( V_87 *
sizeof( struct V_100 ) ,
V_89 ) ;
if ( V_85 -> V_99 == NULL ) {
F_38 ( V_4 , L_15 ) ;
V_40 = - V_34 ;
goto V_98;
}
F_2 (report, &report_enum->report_list, list) {
F_30 ( V_4 , L_16 , V_6 -> V_2 ) ;
V_10 = V_6 -> V_10 [ 0 ] ;
if ( V_6 -> V_12 && V_10 &&
V_10 -> V_13 ) {
V_86 = F_46 ( V_89 , L_17 ,
V_10 -> V_13 ) ;
if ( V_86 == NULL ) {
F_38 ( V_4 , L_18 ) ;
V_40 = - V_34 ;
goto V_101;
}
V_85 -> V_99 [
V_85 -> V_96 ] . V_86 = V_86 ;
V_85 -> V_99 [
V_85 -> V_96 ] . V_102 =
V_85 -> V_31 ;
V_85 -> V_99 [
V_85 -> V_96 ] . V_103 =
sizeof( * V_85 -> V_31 ) ;
F_30 ( V_4 , L_19 , V_86 , V_85 ) ;
V_85 -> V_96 ++ ;
}
}
V_40 = F_47 ( & V_4 -> V_88 , 0 , V_85 -> V_99 ,
V_85 -> V_96 , NULL , 0 , NULL ) ;
if ( V_40 < 0 )
goto V_101;
return V_40 ;
V_101:
for ( V_61 = 0 ; V_61 < V_85 -> V_96 ; ++ V_61 )
F_15 ( V_85 -> V_99 [ V_61 ] . V_86 ) ;
F_15 ( V_85 -> V_99 ) ;
V_98:
F_48 ( V_4 ) ;
V_95:
F_49 ( V_4 ) ;
return V_40 ;
}
static void F_50 ( struct V_3 * V_4 )
{
struct V_26 * V_39 = F_7 ( V_4 ) ;
unsigned long V_48 ;
int V_61 ;
F_30 ( V_4 , L_20 ) ;
F_48 ( V_4 ) ;
F_49 ( V_4 ) ;
F_25 ( & V_39 -> V_53 , V_48 ) ;
if ( V_39 -> V_50 . V_54 )
F_35 ( & V_39 -> V_50 . V_51 ) ;
F_26 ( & V_39 -> V_53 , V_48 ) ;
F_51 ( & V_4 -> V_88 ) ;
for ( V_61 = 0 ; V_61 < V_39 -> V_96 ; ++ V_61 )
F_15 ( V_39 -> V_99 [ V_61 ] . V_86 ) ;
F_15 ( V_39 -> V_99 ) ;
F_39 ( V_4 , NULL ) ;
F_52 ( & V_39 -> V_41 ) ;
}
