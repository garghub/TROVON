static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = - V_5 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ ) {
struct V_7 * V_8 = & V_2 -> V_9 [ V_3 ] ;
if ( V_8 -> type == V_10 &&
( V_8 -> V_11 & V_12 ) == V_13 ) {
V_4 = 0 ;
break;
}
}
return V_4 ;
}
static struct V_14 * F_2 ( int V_15 , struct V_1 * V_2 ,
int V_16 )
{
struct V_14 * V_17 ;
F_3 (report, &hdev->report_enum[dir].report_list, list) {
if ( V_17 -> V_15 == V_15 )
return V_17 ;
}
F_4 ( V_2 , L_1 , V_15 ) ;
return NULL ;
}
static int F_5 (
struct V_18 * V_19 )
{
struct V_14 * V_17 ;
struct V_20 * V_21 ;
int V_22 = 0 ;
F_3 (report, &report_enum->report_list, list) {
V_21 = V_17 -> V_21 [ 0 ] ;
if ( V_17 -> V_23 && V_21 &&
V_21 -> V_24 )
V_22 ++ ;
}
return V_22 ;
}
static void F_6 (
struct V_25 * V_26 ,
T_1 V_27 , T_1 V_28 , T_1 V_29 , T_1 V_30 , T_1 V_31 )
{
V_26 -> V_27 = V_27 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_29 = V_29 ;
V_26 -> V_30 = V_30 ;
V_26 -> V_31 = V_31 / 8 ;
}
static struct V_32 * F_7 (
struct V_1 * V_2 ,
T_2 V_33 , void * * V_34 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 = F_8 ( V_2 ) ;
F_9 ( & V_38 -> V_39 ) ;
F_3 (callback, &pdata->dyn_callback_list, list)
if ( V_36 -> V_33 == V_33 ) {
* V_34 = V_36 -> V_34 ;
F_10 ( & V_38 -> V_39 ) ;
return V_36 -> V_40 ;
}
F_10 ( & V_38 -> V_39 ) ;
return NULL ;
}
int F_11 ( struct V_41 * V_42 ,
T_2 V_33 ,
struct V_32 * V_40 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 = F_8 ( V_42 -> V_2 ) ;
F_9 ( & V_38 -> V_39 ) ;
F_3 (callback, &pdata->dyn_callback_list, list)
if ( V_36 -> V_33 == V_33 ) {
F_10 ( & V_38 -> V_39 ) ;
return - V_5 ;
}
V_36 = F_12 ( sizeof( * V_36 ) , V_43 ) ;
if ( ! V_36 ) {
F_10 ( & V_38 -> V_39 ) ;
return - V_44 ;
}
V_36 -> V_40 = V_40 ;
V_36 -> V_33 = V_33 ;
V_36 -> V_34 = NULL ;
F_13 ( & V_36 -> V_45 , & V_38 -> V_46 ) ;
F_10 ( & V_38 -> V_39 ) ;
return 0 ;
}
int F_14 ( struct V_41 * V_42 ,
T_2 V_33 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 = F_8 ( V_42 -> V_2 ) ;
F_9 ( & V_38 -> V_39 ) ;
F_3 (callback, &pdata->dyn_callback_list, list)
if ( V_36 -> V_33 == V_33 ) {
F_15 ( & V_36 -> V_45 ) ;
F_16 ( V_36 ) ;
break;
}
F_10 ( & V_38 -> V_39 ) ;
return 0 ;
}
int F_17 ( struct V_41 * V_42 , T_2 V_28 ,
T_2 V_47 , T_1 V_48 )
{
struct V_14 * V_17 ;
struct V_37 * V_49 = F_8 ( V_42 -> V_2 ) ;
int V_4 = 0 ;
F_18 ( & V_49 -> V_50 ) ;
V_17 = F_2 ( V_28 , V_42 -> V_2 , V_51 ) ;
if ( ! V_17 || ( V_47 >= V_17 -> V_23 ) ) {
V_4 = - V_5 ;
goto V_52;
}
F_19 ( V_17 -> V_21 [ V_47 ] , 0 , V_48 ) ;
F_20 ( V_42 -> V_2 , V_17 , V_53 ) ;
F_21 ( V_42 -> V_2 ) ;
V_52:
F_22 ( & V_49 -> V_50 ) ;
return V_4 ;
}
int F_23 ( struct V_41 * V_42 , T_2 V_28 ,
T_2 V_47 , T_1 * V_48 )
{
struct V_14 * V_17 ;
struct V_37 * V_49 = F_8 ( V_42 -> V_2 ) ;
int V_4 = 0 ;
F_18 ( & V_49 -> V_50 ) ;
V_17 = F_2 ( V_28 , V_42 -> V_2 , V_51 ) ;
if ( ! V_17 || ( V_47 >= V_17 -> V_23 ) ) {
V_4 = - V_5 ;
goto V_52;
}
F_20 ( V_42 -> V_2 , V_17 , V_54 ) ;
F_21 ( V_42 -> V_2 ) ;
* V_48 = V_17 -> V_21 [ V_47 ] -> V_48 [ 0 ] ;
V_52:
F_22 ( & V_49 -> V_50 ) ;
return V_4 ;
}
int F_24 ( struct V_41 * V_42 ,
T_2 V_33 ,
T_2 V_55 , T_2 V_28 )
{
struct V_37 * V_49 = F_8 ( V_42 -> V_2 ) ;
unsigned long V_56 ;
struct V_14 * V_17 ;
int V_57 = 0 ;
F_18 ( & V_49 -> V_50 ) ;
memset ( & V_49 -> V_58 , 0 , sizeof( V_49 -> V_58 ) ) ;
F_25 ( & V_49 -> V_58 . V_59 ) ;
V_49 -> V_58 . V_33 = V_33 ;
V_49 -> V_58 . V_55 = V_55 ;
V_49 -> V_58 . V_60 = 0 ;
F_26 ( & V_49 -> V_61 , V_56 ) ;
V_49 -> V_58 . V_62 = true ;
V_17 = F_2 ( V_28 , V_42 -> V_2 , V_63 ) ;
if ( ! V_17 ) {
F_27 ( & V_49 -> V_61 , V_56 ) ;
goto V_64;
}
F_20 ( V_42 -> V_2 , V_17 , V_54 ) ;
F_27 ( & V_49 -> V_61 , V_56 ) ;
F_28 ( & V_49 -> V_58 . V_59 , V_65 * 5 ) ;
switch ( V_49 -> V_58 . V_60 ) {
case 1 :
V_57 = * ( V_66 * ) V_49 -> V_58 . V_67 ;
break;
case 2 :
V_57 = * ( V_68 * ) V_49 -> V_58 . V_67 ;
break;
case 4 :
V_57 = * ( T_2 * ) V_49 -> V_58 . V_67 ;
break;
default:
V_57 = 0 ;
}
F_16 ( V_49 -> V_58 . V_67 ) ;
V_64:
V_49 -> V_58 . V_62 = false ;
F_22 ( & V_49 -> V_50 ) ;
return V_57 ;
}
int F_29 ( struct V_41 * V_42 ,
V_66 type ,
T_2 V_33 ,
T_2 V_55 ,
struct V_25 * V_26 )
{
int V_4 = - 1 ;
int V_3 , V_69 ;
int V_70 = - 1 ;
struct V_14 * V_17 ;
struct V_20 * V_21 ;
struct V_18 * V_19 ;
struct V_1 * V_2 = V_42 -> V_2 ;
V_26 -> V_33 = V_33 ;
V_26 -> V_71 = V_55 ;
V_26 -> V_28 = - 1 ;
V_26 -> V_27 = - 1 ;
V_26 -> V_29 = - 1 ;
V_26 -> V_30 = - 1 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; ++ V_3 ) {
struct V_7 * V_9 = & V_2 -> V_9 [ V_3 ] ;
if ( V_33 == V_9 -> V_11 ) {
V_70 = V_3 ;
break;
}
}
if ( V_70 == - 1 )
goto V_72;
V_19 = & V_2 -> V_19 [ type ] ;
F_3 (report, &report_enum->report_list, list) {
for ( V_3 = 0 ; V_3 < V_17 -> V_23 ; ++ V_3 ) {
V_21 = V_17 -> V_21 [ V_3 ] ;
if ( V_21 -> V_24 == V_33 &&
V_21 -> V_73 == V_55 ) {
F_6 ( V_26 , V_3 , V_17 -> V_15 ,
V_21 -> V_74 , V_21 -> V_75 ,
V_21 -> V_76 ) ;
V_4 = 0 ;
} else {
for ( V_69 = 0 ; V_69 < V_21 -> V_77 ; ++ V_69 ) {
if ( V_21 -> V_11 [ V_69 ] . V_78 ==
V_55 &&
V_21 -> V_11 [ V_69 ] . V_70 ==
V_70 ) {
F_6 ( V_26 ,
V_3 , V_17 -> V_15 ,
V_21 -> V_74 ,
V_21 -> V_75 ,
V_21 -> V_76 ) ;
V_4 = 0 ;
break;
}
}
}
if ( V_4 == 0 )
break;
}
}
V_72:
return V_4 ;
}
static int F_30 ( struct V_1 * V_2 , T_3 V_79 )
{
struct V_37 * V_38 = F_8 ( V_2 ) ;
struct V_35 * V_36 ;
F_31 ( V_2 , L_2 ) ;
F_9 ( & V_38 -> V_39 ) ;
F_3 (callback, &pdata->dyn_callback_list, list) {
if ( V_36 -> V_40 -> V_80 )
V_36 -> V_40 -> V_80 (
V_38 -> V_42 , V_36 -> V_34 ) ;
}
F_10 ( & V_38 -> V_39 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_8 ( V_2 ) ;
struct V_35 * V_36 ;
F_31 ( V_2 , L_3 ) ;
F_9 ( & V_38 -> V_39 ) ;
F_3 (callback, &pdata->dyn_callback_list, list) {
if ( V_36 -> V_40 -> V_81 )
V_36 -> V_40 -> V_81 (
V_38 -> V_42 , V_36 -> V_34 ) ;
}
F_10 ( & V_38 -> V_39 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_14 * V_17 , V_66 * V_67 , int V_31 )
{
int V_3 ;
V_66 * V_82 ;
int V_83 ;
struct V_37 * V_38 = F_8 ( V_2 ) ;
unsigned long V_56 ;
struct V_32 * V_36 = NULL ;
struct V_7 * V_9 = NULL ;
void * V_34 = NULL ;
F_31 ( V_2 , L_4 ,
V_17 -> V_15 , V_31 , V_17 -> type ) ;
F_31 ( V_2 , L_5 , V_17 -> V_23 ) ;
if ( V_17 -> type != V_63 )
return 1 ;
V_82 = V_67 ;
V_82 ++ ;
if ( ! V_17 )
goto V_84;
F_26 ( & V_38 -> V_61 , V_56 ) ;
for ( V_3 = 0 ; V_3 < V_17 -> V_23 ; ++ V_3 ) {
F_31 ( V_2 , L_6 ,
V_3 , V_17 -> V_21 [ V_3 ] -> V_11 -> V_70 ,
V_17 -> V_21 [ V_3 ] -> V_11 -> V_78 ,
V_17 -> V_21 [ V_3 ] -> V_76 / 8 ) ;
V_83 = V_17 -> V_21 [ V_3 ] -> V_76 / 8 ;
if ( V_38 -> V_58 . V_62 && V_38 -> V_58 . V_55 ==
V_17 -> V_21 [ V_3 ] -> V_11 -> V_78 ) {
F_31 ( V_2 , L_7 ) ;
V_38 -> V_58 . V_67 = F_35 ( V_83 , V_43 ) ;
if ( V_38 -> V_58 . V_67 ) {
memcpy ( V_38 -> V_58 . V_67 , V_82 , V_83 ) ;
V_38 -> V_58 . V_60 = V_83 ;
} else
V_38 -> V_58 . V_60 = 0 ;
F_36 ( & V_38 -> V_58 . V_59 ) ;
}
V_9 = & V_2 -> V_9 [
V_17 -> V_21 [ V_3 ] -> V_11 -> V_70 ] ;
F_31 ( V_2 , L_8 ,
V_9 -> V_11 ) ;
V_36 = F_7 ( V_38 -> V_42 -> V_2 ,
V_17 -> V_21 [ V_3 ] -> V_24 ,
& V_34 ) ;
if ( V_36 && V_36 -> V_85 ) {
if ( V_17 -> V_21 [ V_3 ] -> V_73 )
V_36 -> V_85 ( V_38 -> V_42 ,
V_17 -> V_21 [ V_3 ] -> V_73 , V_83 , V_82 ,
V_36 -> V_86 ) ;
else
V_36 -> V_85 ( V_38 -> V_42 ,
V_17 -> V_21 [ V_3 ] -> V_11 -> V_78 , V_83 , V_82 ,
V_36 -> V_86 ) ;
}
V_82 += V_83 ;
}
if ( V_36 && V_9 && V_36 -> V_87 )
V_36 -> V_87 ( V_38 -> V_42 , V_9 -> V_11 ,
V_36 -> V_86 ) ;
F_27 ( & V_38 -> V_61 , V_56 ) ;
V_84:
return 1 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_88 * V_15 )
{
int V_4 ;
struct V_37 * V_89 ;
int V_3 ;
char * V_90 ;
struct V_14 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_91 ;
V_89 = F_12 ( sizeof( struct V_37 ) , V_92 ) ;
if ( ! V_89 ) {
F_38 ( V_2 , L_9 ) ;
return - V_44 ;
}
V_89 -> V_42 = F_12 ( sizeof( struct V_41 ) , V_92 ) ;
if ( ! V_89 -> V_42 ) {
F_38 ( V_2 , L_10 ) ;
V_4 = - V_44 ;
goto V_93;
}
F_39 ( V_2 , V_89 ) ;
V_89 -> V_42 -> V_2 = V_2 ;
V_89 -> V_42 -> V_94 = V_2 -> V_95 ;
V_89 -> V_42 -> V_96 = V_2 -> V_97 ;
F_40 ( & V_89 -> V_61 ) ;
F_40 ( & V_89 -> V_39 ) ;
F_41 ( & V_89 -> V_50 ) ;
V_4 = F_42 ( V_2 ) ;
if ( V_4 ) {
F_38 ( V_2 , L_11 ) ;
goto V_64;
}
if ( F_1 ( V_2 ) < 0 ) {
F_38 ( V_2 , L_12 ) ;
goto V_64;
}
F_43 ( & V_2 -> V_98 ) ;
V_4 = F_44 ( V_2 , 0 ) ;
if ( V_4 ) {
F_38 ( V_2 , L_13 ) ;
goto V_64;
}
V_4 = F_45 ( V_2 ) ;
if ( V_4 ) {
F_38 ( V_2 , L_14 ) ;
goto V_99;
}
F_43 ( & V_89 -> V_46 ) ;
V_89 -> V_100 = 0 ;
V_19 = & V_2 -> V_19 [ V_63 ] ;
V_91 = F_5 ( V_19 ) ;
if ( V_91 > V_101 ) {
F_38 ( V_2 , L_15 ) ;
V_4 = - V_5 ;
goto V_102;
}
V_89 -> V_103 = F_12 ( V_91 *
sizeof( struct V_104 ) ,
V_92 ) ;
if ( V_89 -> V_103 == NULL ) {
F_38 ( V_2 , L_16 ) ;
V_4 = - V_44 ;
goto V_102;
}
F_3 (report, &report_enum->report_list, list) {
F_31 ( V_2 , L_17 , V_17 -> V_15 ) ;
V_21 = V_17 -> V_21 [ 0 ] ;
if ( V_17 -> V_23 && V_21 &&
V_21 -> V_24 ) {
V_90 = F_46 ( V_92 , L_18 ,
V_21 -> V_24 ) ;
if ( V_90 == NULL ) {
F_38 ( V_2 , L_19 ) ;
V_4 = - V_44 ;
goto V_105;
}
V_89 -> V_103 [
V_89 -> V_100 ] . V_90 = V_90 ;
V_89 -> V_103 [
V_89 -> V_100 ] . V_106 =
V_89 -> V_42 ;
V_89 -> V_103 [
V_89 -> V_100 ] . V_107 =
sizeof( * V_89 -> V_42 ) ;
F_31 ( V_2 , L_20 , V_90 , V_89 ) ;
V_89 -> V_100 ++ ;
}
}
V_4 = F_47 ( & V_2 -> V_108 , 0 , V_89 -> V_103 ,
V_89 -> V_100 , NULL , 0 , NULL ) ;
if ( V_4 < 0 )
goto V_105;
return V_4 ;
V_105:
for ( V_3 = 0 ; V_3 < V_89 -> V_100 ; ++ V_3 )
F_16 ( V_89 -> V_103 [ V_3 ] . V_90 ) ;
F_16 ( V_89 -> V_103 ) ;
V_102:
F_48 ( V_2 ) ;
V_99:
F_49 ( V_2 ) ;
V_64:
F_16 ( V_89 -> V_42 ) ;
V_93:
F_16 ( V_89 ) ;
return V_4 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_37 * V_49 = F_8 ( V_2 ) ;
unsigned long V_56 ;
int V_3 ;
F_31 ( V_2 , L_21 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_26 ( & V_49 -> V_61 , V_56 ) ;
if ( V_49 -> V_58 . V_62 )
F_36 ( & V_49 -> V_58 . V_59 ) ;
F_27 ( & V_49 -> V_61 , V_56 ) ;
F_51 ( & V_2 -> V_108 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_100 ; ++ V_3 )
F_16 ( V_49 -> V_103 [ V_3 ] . V_90 ) ;
F_16 ( V_49 -> V_103 ) ;
F_39 ( V_2 , NULL ) ;
F_52 ( & V_49 -> V_50 ) ;
F_16 ( V_49 -> V_42 ) ;
F_16 ( V_49 ) ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_109 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_109 ) ;
}
