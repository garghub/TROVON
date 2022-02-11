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
if ( V_6 -> V_12 && V_10 &&
V_10 -> V_13 )
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
if ( ! V_6 || ( V_37 >= V_6 -> V_12 ) ) {
V_40 = - V_32 ;
goto V_43;
}
F_19 ( V_31 -> V_4 , V_6 , V_45 ) ;
F_20 ( V_31 -> V_4 ) ;
* V_38 = V_6 -> V_10 [ V_37 ] -> V_38 [ 0 ] ;
V_43:
F_21 ( & V_39 -> V_41 ) ;
return V_40 ;
}
int F_23 ( struct V_30 * V_31 ,
T_2 V_22 ,
T_2 V_46 , T_2 V_17 )
{
struct V_26 * V_39 = F_7 ( V_31 -> V_4 ) ;
unsigned long V_47 ;
struct V_1 * V_6 ;
int V_48 = 0 ;
F_17 ( & V_39 -> V_41 ) ;
memset ( & V_39 -> V_49 , 0 , sizeof( V_39 -> V_49 ) ) ;
F_24 ( & V_39 -> V_49 . V_50 ) ;
V_39 -> V_49 . V_22 = V_22 ;
V_39 -> V_49 . V_46 = V_46 ;
V_39 -> V_49 . V_51 = 0 ;
F_25 ( & V_39 -> V_52 , V_47 ) ;
V_39 -> V_49 . V_53 = true ;
V_6 = F_1 ( V_17 , V_31 -> V_4 , V_54 ) ;
if ( ! V_6 ) {
F_26 ( & V_39 -> V_52 , V_47 ) ;
goto V_55;
}
F_19 ( V_31 -> V_4 , V_6 , V_45 ) ;
F_26 ( & V_39 -> V_52 , V_47 ) ;
F_27 ( & V_39 -> V_49 . V_50 , V_56 * 5 ) ;
switch ( V_39 -> V_49 . V_51 ) {
case 1 :
V_48 = * ( V_57 * ) V_39 -> V_49 . V_58 ;
break;
case 2 :
V_48 = * ( V_59 * ) V_39 -> V_49 . V_58 ;
break;
case 4 :
V_48 = * ( T_2 * ) V_39 -> V_49 . V_58 ;
break;
default:
V_48 = 0 ;
}
F_15 ( V_39 -> V_49 . V_58 ) ;
V_55:
V_39 -> V_49 . V_53 = false ;
F_21 ( & V_39 -> V_41 ) ;
return V_48 ;
}
int F_28 ( struct V_30 * V_31 ,
V_57 type ,
T_2 V_22 ,
T_2 V_46 ,
struct V_14 * V_15 )
{
int V_40 = - 1 ;
int V_60 , V_61 ;
int V_62 = - 1 ;
struct V_1 * V_6 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
struct V_3 * V_4 = V_31 -> V_4 ;
V_15 -> V_22 = V_22 ;
V_15 -> V_63 = V_46 ;
V_15 -> V_17 = - 1 ;
V_15 -> V_16 = - 1 ;
V_15 -> V_18 = - 1 ;
V_15 -> V_19 = - 1 ;
for ( V_60 = 0 ; V_60 < V_4 -> V_64 ; ++ V_60 ) {
struct V_65 * V_66 = & V_4 -> V_66 [ V_60 ] ;
if ( V_22 == V_66 -> V_67 ) {
V_62 = V_60 ;
break;
}
}
if ( V_62 == - 1 )
goto V_68;
V_8 = & V_4 -> V_8 [ type ] ;
F_2 (report, &report_enum->report_list, list) {
for ( V_60 = 0 ; V_60 < V_6 -> V_12 ; ++ V_60 ) {
V_10 = V_6 -> V_10 [ V_60 ] ;
if ( V_10 -> V_13 == V_22 &&
V_10 -> V_69 == V_46 ) {
F_5 ( V_15 , V_60 , V_6 -> V_2 ,
V_10 -> V_70 , V_10 -> V_71 ,
V_10 -> V_72 ) ;
V_40 = 0 ;
} else {
for ( V_61 = 0 ; V_61 < V_10 -> V_73 ; ++ V_61 ) {
if ( V_10 -> V_67 [ V_61 ] . V_74 ==
V_46 &&
V_10 -> V_67 [ V_61 ] . V_62 ==
V_62 ) {
F_5 ( V_15 ,
V_60 , V_6 -> V_2 ,
V_10 -> V_70 ,
V_10 -> V_71 ,
V_10 -> V_72 ) ;
V_40 = 0 ;
break;
}
}
}
if ( V_40 == 0 )
break;
}
}
V_68:
return V_40 ;
}
static int F_29 ( struct V_3 * V_4 , T_3 V_75 )
{
struct V_26 * V_27 = F_7 ( V_4 ) ;
struct V_24 * V_25 ;
F_30 ( V_4 , L_2 ) ;
F_8 ( & V_27 -> V_28 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_25 -> V_29 -> V_76 )
V_25 -> V_29 -> V_76 (
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
if ( V_25 -> V_29 -> V_77 )
V_25 -> V_29 -> V_77 (
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
struct V_1 * V_6 , V_57 * V_58 , int V_20 )
{
int V_60 ;
V_57 * V_78 ;
int V_79 ;
struct V_26 * V_27 = F_7 ( V_4 ) ;
unsigned long V_47 ;
struct V_21 * V_25 = NULL ;
struct V_65 * V_66 = NULL ;
void * V_23 = NULL ;
F_30 ( V_4 , L_4 ,
V_6 -> V_2 , V_20 , V_6 -> type ) ;
F_30 ( V_4 , L_5 , V_6 -> V_12 ) ;
if ( V_6 -> type != V_54 )
return 1 ;
V_78 = V_58 ;
V_78 ++ ;
F_25 ( & V_27 -> V_52 , V_47 ) ;
for ( V_60 = 0 ; V_60 < V_6 -> V_12 ; ++ V_60 ) {
F_30 ( V_4 , L_6 ,
V_60 , V_6 -> V_10 [ V_60 ] -> V_67 -> V_62 ,
V_6 -> V_10 [ V_60 ] -> V_67 -> V_74 ,
V_6 -> V_10 [ V_60 ] -> V_72 / 8 ) ;
V_79 = V_6 -> V_10 [ V_60 ] -> V_72 / 8 ;
if ( V_27 -> V_49 . V_53 && V_27 -> V_49 . V_46 ==
V_6 -> V_10 [ V_60 ] -> V_67 -> V_74 ) {
F_30 ( V_4 , L_7 ) ;
V_27 -> V_49 . V_58 = F_34 ( V_79 , V_33 ) ;
if ( V_27 -> V_49 . V_58 ) {
memcpy ( V_27 -> V_49 . V_58 , V_78 , V_79 ) ;
V_27 -> V_49 . V_51 = V_79 ;
} else
V_27 -> V_49 . V_51 = 0 ;
F_35 ( & V_27 -> V_49 . V_50 ) ;
}
V_66 = & V_4 -> V_66 [
V_6 -> V_10 [ V_60 ] -> V_67 -> V_62 ] ;
F_30 ( V_4 , L_8 ,
V_66 -> V_67 ) ;
V_25 = F_6 ( V_27 -> V_31 -> V_4 ,
V_6 -> V_10 [ V_60 ] -> V_13 ,
& V_23 ) ;
if ( V_25 && V_25 -> V_80 ) {
if ( V_6 -> V_10 [ V_60 ] -> V_69 )
V_25 -> V_80 ( V_27 -> V_31 ,
V_6 -> V_10 [ V_60 ] -> V_69 , V_79 , V_78 ,
V_25 -> V_81 ) ;
else
V_25 -> V_80 ( V_27 -> V_31 ,
V_6 -> V_10 [ V_60 ] -> V_67 -> V_74 , V_79 , V_78 ,
V_25 -> V_81 ) ;
}
V_78 += V_79 ;
}
if ( V_25 && V_66 && V_25 -> V_82 )
V_25 -> V_82 ( V_27 -> V_31 , V_66 -> V_67 ,
V_25 -> V_81 ) ;
F_26 ( & V_27 -> V_52 , V_47 ) ;
return 1 ;
}
static int F_36 ( struct V_3 * V_4 ,
const struct V_83 * V_2 )
{
int V_40 ;
struct V_26 * V_84 ;
int V_60 ;
char * V_85 ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_86 ;
V_84 = F_11 ( sizeof( struct V_26 ) , V_87 ) ;
if ( ! V_84 ) {
F_37 ( V_4 , L_9 ) ;
return - V_34 ;
}
V_84 -> V_31 = F_11 ( sizeof( struct V_30 ) , V_87 ) ;
if ( ! V_84 -> V_31 ) {
F_37 ( V_4 , L_10 ) ;
V_40 = - V_34 ;
goto V_88;
}
F_38 ( V_4 , V_84 ) ;
V_84 -> V_31 -> V_4 = V_4 ;
V_84 -> V_31 -> V_89 = V_4 -> V_90 ;
V_84 -> V_31 -> V_91 = V_4 -> V_92 ;
F_39 ( & V_84 -> V_52 ) ;
F_39 ( & V_84 -> V_28 ) ;
F_40 ( & V_84 -> V_41 ) ;
V_40 = F_41 ( V_4 ) ;
if ( V_40 ) {
F_37 ( V_4 , L_11 ) ;
goto V_55;
}
F_42 ( & V_4 -> V_93 ) ;
V_40 = F_43 ( V_4 , 0 ) ;
if ( V_40 ) {
F_37 ( V_4 , L_12 ) ;
goto V_55;
}
V_40 = F_44 ( V_4 ) ;
if ( V_40 ) {
F_37 ( V_4 , L_13 ) ;
goto V_94;
}
F_42 ( & V_84 -> V_36 ) ;
V_84 -> V_95 = 0 ;
V_8 = & V_4 -> V_8 [ V_54 ] ;
V_86 = F_4 ( V_8 ) ;
if ( V_86 > V_96 ) {
F_37 ( V_4 , L_14 ) ;
V_40 = - V_32 ;
goto V_97;
}
V_84 -> V_98 = F_11 ( V_86 *
sizeof( struct V_99 ) ,
V_87 ) ;
if ( V_84 -> V_98 == NULL ) {
F_37 ( V_4 , L_15 ) ;
V_40 = - V_34 ;
goto V_97;
}
F_2 (report, &report_enum->report_list, list) {
F_30 ( V_4 , L_16 , V_6 -> V_2 ) ;
V_10 = V_6 -> V_10 [ 0 ] ;
if ( V_6 -> V_12 && V_10 &&
V_10 -> V_13 ) {
V_85 = F_45 ( V_87 , L_17 ,
V_10 -> V_13 ) ;
if ( V_85 == NULL ) {
F_37 ( V_4 , L_18 ) ;
V_40 = - V_34 ;
goto V_100;
}
V_84 -> V_98 [
V_84 -> V_95 ] . V_85 = V_85 ;
V_84 -> V_98 [
V_84 -> V_95 ] . V_101 =
V_84 -> V_31 ;
V_84 -> V_98 [
V_84 -> V_95 ] . V_102 =
sizeof( * V_84 -> V_31 ) ;
F_30 ( V_4 , L_19 , V_85 , V_84 ) ;
V_84 -> V_95 ++ ;
}
}
V_40 = F_46 ( & V_4 -> V_103 , 0 , V_84 -> V_98 ,
V_84 -> V_95 , NULL , 0 , NULL ) ;
if ( V_40 < 0 )
goto V_100;
return V_40 ;
V_100:
for ( V_60 = 0 ; V_60 < V_84 -> V_95 ; ++ V_60 )
F_15 ( V_84 -> V_98 [ V_60 ] . V_85 ) ;
F_15 ( V_84 -> V_98 ) ;
V_97:
F_47 ( V_4 ) ;
V_94:
F_48 ( V_4 ) ;
V_55:
F_15 ( V_84 -> V_31 ) ;
V_88:
F_15 ( V_84 ) ;
return V_40 ;
}
static void F_49 ( struct V_3 * V_4 )
{
struct V_26 * V_39 = F_7 ( V_4 ) ;
unsigned long V_47 ;
int V_60 ;
F_30 ( V_4 , L_20 ) ;
F_47 ( V_4 ) ;
F_48 ( V_4 ) ;
F_25 ( & V_39 -> V_52 , V_47 ) ;
if ( V_39 -> V_49 . V_53 )
F_35 ( & V_39 -> V_49 . V_50 ) ;
F_26 ( & V_39 -> V_52 , V_47 ) ;
F_50 ( & V_4 -> V_103 ) ;
for ( V_60 = 0 ; V_60 < V_39 -> V_95 ; ++ V_60 )
F_15 ( V_39 -> V_98 [ V_60 ] . V_85 ) ;
F_15 ( V_39 -> V_98 ) ;
F_38 ( V_4 , NULL ) ;
F_51 ( & V_39 -> V_41 ) ;
F_15 ( V_39 -> V_31 ) ;
F_15 ( V_39 ) ;
}
