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
static int F_4 ( struct V_3 * V_4 )
{
int V_7 ;
int V_8 = 0 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; ++ V_7 ) {
struct V_10 * V_11 = & V_4 -> V_11 [ V_7 ] ;
if ( V_11 -> type == V_12 )
++ V_8 ;
}
return V_8 ;
}
static void F_5 (
struct V_13 * V_14 ,
T_1 V_15 , T_1 V_16 , struct V_17 * V_18 )
{
V_14 -> V_15 = V_15 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_19 = V_18 -> V_20 ;
V_14 -> V_21 = V_18 -> V_22 ;
V_14 -> V_23 = ( V_18 -> V_24 * V_18 -> V_25 ) / 8 ;
V_14 -> V_26 = V_18 -> V_26 ;
V_14 -> V_27 = V_18 -> V_27 ;
}
static struct V_28 * F_6 (
struct V_3 * V_4 ,
T_2 V_29 ,
int V_30 ,
struct V_31 * * V_32 ,
void * * V_33 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 = F_7 ( V_4 ) ;
F_8 ( & V_37 -> V_38 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_35 -> V_29 == V_29 &&
( V_30 >=
V_35 -> V_32 -> V_39 ) &&
( V_30 <
V_35 -> V_32 -> V_40 ) ) {
* V_33 = V_35 -> V_33 ;
* V_32 = V_35 -> V_32 ;
F_9 ( & V_37 -> V_38 ) ;
return V_35 -> V_41 ;
}
F_9 ( & V_37 -> V_38 ) ;
return NULL ;
}
int F_10 ( struct V_31 * V_32 ,
T_2 V_29 ,
struct V_28 * V_41 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 = F_7 ( V_32 -> V_4 ) ;
unsigned long V_42 ;
F_11 ( & V_37 -> V_38 , V_42 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_35 -> V_29 == V_29 &&
V_35 -> V_32 == V_32 ) {
F_12 ( & V_37 -> V_38 , V_42 ) ;
return - V_43 ;
}
V_35 = F_13 ( sizeof( * V_35 ) , V_44 ) ;
if ( ! V_35 ) {
F_12 ( & V_37 -> V_38 , V_42 ) ;
return - V_45 ;
}
V_35 -> V_32 = V_32 ;
V_35 -> V_41 = V_41 ;
V_35 -> V_29 = V_29 ;
V_35 -> V_33 = NULL ;
F_14 ( & V_35 -> V_46 , & V_37 -> V_47 ) ;
F_12 ( & V_37 -> V_38 , V_42 ) ;
return 0 ;
}
int F_15 ( struct V_31 * V_32 ,
T_2 V_29 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 = F_7 ( V_32 -> V_4 ) ;
unsigned long V_42 ;
F_11 ( & V_37 -> V_38 , V_42 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_35 -> V_29 == V_29 &&
V_35 -> V_32 == V_32 ) {
F_16 ( & V_35 -> V_46 ) ;
F_17 ( V_35 ) ;
break;
}
F_12 ( & V_37 -> V_38 , V_42 ) ;
return 0 ;
}
int F_18 ( struct V_31 * V_32 , T_2 V_16 ,
T_2 V_48 , T_1 V_49 )
{
struct V_1 * V_6 ;
struct V_36 * V_50 = F_7 ( V_32 -> V_4 ) ;
int V_51 = 0 ;
F_19 ( & V_50 -> V_52 ) ;
V_6 = F_1 ( V_16 , V_32 -> V_4 , V_53 ) ;
if ( ! V_6 || ( V_48 >= V_6 -> V_54 ) ) {
V_51 = - V_43 ;
goto V_55;
}
F_20 ( V_6 -> V_18 [ V_48 ] , 0 , V_49 ) ;
F_21 ( V_32 -> V_4 , V_6 , V_56 ) ;
F_22 ( V_32 -> V_4 ) ;
V_55:
F_23 ( & V_50 -> V_52 ) ;
return V_51 ;
}
int F_24 ( struct V_31 * V_32 , T_2 V_16 ,
T_2 V_48 , T_1 * V_49 )
{
struct V_1 * V_6 ;
struct V_36 * V_50 = F_7 ( V_32 -> V_4 ) ;
int V_51 = 0 ;
F_19 ( & V_50 -> V_52 ) ;
V_6 = F_1 ( V_16 , V_32 -> V_4 , V_53 ) ;
if ( ! V_6 || ( V_48 >= V_6 -> V_54 ) ||
V_6 -> V_18 [ V_48 ] -> V_25 < 1 ) {
V_51 = - V_43 ;
goto V_55;
}
F_21 ( V_32 -> V_4 , V_6 , V_57 ) ;
F_22 ( V_32 -> V_4 ) ;
* V_49 = V_6 -> V_18 [ V_48 ] -> V_49 [ 0 ] ;
V_55:
F_23 ( & V_50 -> V_52 ) ;
return V_51 ;
}
int F_25 ( struct V_31 * V_32 ,
T_2 V_29 ,
T_2 V_58 , T_2 V_16 )
{
struct V_36 * V_50 = F_7 ( V_32 -> V_4 ) ;
unsigned long V_42 ;
struct V_1 * V_6 ;
int V_59 = 0 ;
F_19 ( & V_50 -> V_52 ) ;
memset ( & V_50 -> V_60 , 0 , sizeof( V_50 -> V_60 ) ) ;
F_26 ( & V_50 -> V_60 . V_61 ) ;
V_50 -> V_60 . V_29 = V_29 ;
V_50 -> V_60 . V_58 = V_58 ;
V_50 -> V_60 . V_62 = 0 ;
F_11 ( & V_50 -> V_63 , V_42 ) ;
V_50 -> V_60 . V_64 = true ;
F_12 ( & V_50 -> V_63 , V_42 ) ;
V_6 = F_1 ( V_16 , V_32 -> V_4 , V_65 ) ;
if ( ! V_6 )
goto V_66;
F_21 ( V_32 -> V_4 , V_6 , V_57 ) ;
F_27 ( & V_50 -> V_60 . V_61 , V_67 * 5 ) ;
switch ( V_50 -> V_60 . V_62 ) {
case 1 :
V_59 = * ( V_68 * ) V_50 -> V_60 . V_69 ;
break;
case 2 :
V_59 = * ( V_70 * ) V_50 -> V_60 . V_69 ;
break;
case 4 :
V_59 = * ( T_2 * ) V_50 -> V_60 . V_69 ;
break;
default:
V_59 = 0 ;
}
F_17 ( V_50 -> V_60 . V_69 ) ;
V_66:
V_50 -> V_60 . V_64 = false ;
F_23 ( & V_50 -> V_52 ) ;
return V_59 ;
}
int F_28 ( struct V_31 * V_32 ,
T_2 V_16 , int V_48 , T_2 V_29 )
{
struct V_1 * V_6 ;
struct V_17 * V_18 ;
int V_7 ;
V_6 = F_1 ( V_16 , V_32 -> V_4 , V_53 ) ;
if ( ! V_6 || ( V_48 >= V_6 -> V_54 ) )
goto V_55;
V_18 = V_6 -> V_18 [ V_48 ] ;
for ( V_7 = 0 ; V_7 < V_18 -> V_71 ; ++ V_7 ) {
if ( V_18 -> V_72 [ V_7 ] . V_73 == V_29 )
return V_18 -> V_72 [ V_7 ] . V_74 ;
}
V_55:
return - V_43 ;
}
int F_29 ( struct V_31 * V_32 ,
V_68 type ,
T_2 V_29 ,
T_2 V_58 ,
struct V_13 * V_14 )
{
int V_51 = - 1 ;
int V_7 ;
struct V_1 * V_6 ;
struct V_17 * V_18 ;
struct V_75 * V_76 ;
struct V_3 * V_4 = V_32 -> V_4 ;
V_14 -> V_29 = V_29 ;
V_14 -> V_77 = V_58 ;
V_14 -> V_16 = - 1 ;
V_14 -> V_15 = - 1 ;
V_14 -> V_19 = - 1 ;
V_14 -> V_21 = - 1 ;
V_76 = & V_4 -> V_76 [ type ] ;
F_2 (report, &report_enum->report_list, list) {
for ( V_7 = 0 ; V_7 < V_6 -> V_54 ; ++ V_7 ) {
V_18 = V_6 -> V_18 [ V_7 ] ;
if ( V_18 -> V_71 ) {
if ( V_18 -> V_78 == V_29 &&
( V_18 -> V_79 == V_58 ||
V_18 -> V_72 [ 0 ] . V_73 ==
V_58 ) &&
( V_18 -> V_72 [ 0 ] . V_30 >=
V_32 -> V_39 ) &&
( V_18 -> V_72 [ 0 ] . V_30 <
V_32 -> V_40 ) ) {
F_5 ( V_14 , V_7 ,
V_6 -> V_2 ,
V_18 ) ;
V_51 = 0 ;
break;
}
}
}
}
return V_51 ;
}
static int F_30 ( struct V_3 * V_4 , T_3 V_80 )
{
struct V_36 * V_37 = F_7 ( V_4 ) ;
struct V_34 * V_35 ;
unsigned long V_42 ;
F_31 ( V_4 , L_2 ) ;
F_11 ( & V_37 -> V_38 , V_42 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_35 -> V_41 -> V_81 )
V_35 -> V_41 -> V_81 (
V_35 -> V_32 , V_35 -> V_33 ) ;
}
F_12 ( & V_37 -> V_38 , V_42 ) ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = F_7 ( V_4 ) ;
struct V_34 * V_35 ;
unsigned long V_42 ;
F_31 ( V_4 , L_3 ) ;
F_11 ( & V_37 -> V_38 , V_42 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_35 -> V_41 -> V_82 )
V_35 -> V_41 -> V_82 (
V_35 -> V_32 , V_35 -> V_33 ) ;
}
F_12 ( & V_37 -> V_38 , V_42 ) ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_34 ( struct V_3 * V_4 ,
struct V_1 * V_6 , V_68 * V_69 , int V_23 )
{
int V_7 ;
V_68 * V_83 ;
int V_84 ;
struct V_36 * V_37 = F_7 ( V_4 ) ;
unsigned long V_42 ;
struct V_28 * V_35 = NULL ;
struct V_10 * V_11 = NULL ;
void * V_33 = NULL ;
struct V_31 * V_32 = NULL ;
F_31 ( V_4 , L_4 ,
V_6 -> V_2 , V_23 , V_6 -> type ) ;
F_31 ( V_4 , L_5 , V_6 -> V_54 ) ;
if ( V_6 -> type != V_65 )
return 1 ;
V_83 = V_69 ;
V_83 ++ ;
F_11 ( & V_37 -> V_63 , V_42 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_54 ; ++ V_7 ) {
F_31 ( V_4 , L_6 ,
V_7 , V_6 -> V_18 [ V_7 ] -> V_72 -> V_30 ,
V_6 -> V_18 [ V_7 ] -> V_72 -> V_73 ,
( V_6 -> V_18 [ V_7 ] -> V_24 *
V_6 -> V_18 [ V_7 ] -> V_25 ) / 8 ) ;
V_84 = ( V_6 -> V_18 [ V_7 ] -> V_24 *
V_6 -> V_18 [ V_7 ] -> V_25 ) / 8 ;
if ( V_37 -> V_60 . V_64 && V_37 -> V_60 . V_58 ==
V_6 -> V_18 [ V_7 ] -> V_72 -> V_73 ) {
F_31 ( V_4 , L_7 ) ;
V_37 -> V_60 . V_69 = F_35 ( V_83 , V_84 , V_44 ) ;
if ( V_37 -> V_60 . V_69 )
V_37 -> V_60 . V_62 = V_84 ;
else
V_37 -> V_60 . V_62 = 0 ;
F_36 ( & V_37 -> V_60 . V_61 ) ;
}
V_11 = & V_4 -> V_11 [
V_6 -> V_18 [ V_7 ] -> V_72 -> V_30 ] ;
F_31 ( V_4 , L_8 ,
V_11 -> V_72 ) ;
V_35 = F_6 ( V_4 ,
V_6 -> V_18 [ V_7 ] -> V_78 ,
V_6 -> V_18 [ V_7 ] -> V_72 [ 0 ] . V_30 ,
& V_32 , & V_33 ) ;
if ( V_35 && V_35 -> V_85 ) {
if ( V_6 -> V_18 [ V_7 ] -> V_79 )
V_35 -> V_85 ( V_32 ,
V_6 -> V_18 [ V_7 ] -> V_79 , V_84 , V_83 ,
V_35 -> V_86 ) ;
else
V_35 -> V_85 ( V_32 ,
V_6 -> V_18 [ V_7 ] -> V_72 -> V_73 , V_84 , V_83 ,
V_35 -> V_86 ) ;
}
V_83 += V_84 ;
}
if ( V_35 && V_11 && V_35 -> V_87 )
V_35 -> V_87 ( V_32 , V_11 -> V_72 ,
V_35 -> V_86 ) ;
F_12 ( & V_37 -> V_63 , V_42 ) ;
return 1 ;
}
int F_37 ( struct V_31 * V_32 )
{
int V_51 = 0 ;
struct V_36 * V_50 = F_7 ( V_32 -> V_4 ) ;
F_19 ( & V_50 -> V_52 ) ;
if ( ! V_50 -> V_88 ) {
V_51 = F_38 ( V_32 -> V_4 ) ;
if ( V_51 ) {
F_39 ( V_32 -> V_4 , L_9 ) ;
F_23 ( & V_50 -> V_52 ) ;
return V_51 ;
}
}
V_50 -> V_88 ++ ;
F_23 ( & V_50 -> V_52 ) ;
return V_51 ;
}
void F_40 ( struct V_31 * V_32 )
{
struct V_36 * V_50 = F_7 ( V_32 -> V_4 ) ;
F_19 ( & V_50 -> V_52 ) ;
V_50 -> V_88 -- ;
if ( ! V_50 -> V_88 )
F_41 ( V_32 -> V_4 ) ;
F_23 ( & V_50 -> V_52 ) ;
}
static T_4 * F_42 ( struct V_3 * V_4 , T_4 * V_89 ,
unsigned int * V_90 )
{
int V_15 ;
struct V_36 * V_91 = F_7 ( V_4 ) ;
unsigned char V_92 [] = {
0x0a , 0x16 , 0x03 , 0x15 , 0x00 , 0x25 , 0x05 } ;
unsigned char V_93 [] = {
0x0a , 0x19 , 0x03 , 0x15 , 0x00 , 0x25 , 0x05 } ;
if ( ! ( V_91 -> V_94 & V_95 ) ) {
F_31 ( V_4 , L_10 ) ;
return V_89 ;
}
for ( V_15 = 0 ; V_15 < * V_90 ; ++ V_15 ) {
if ( ( ( * V_90 - V_15 ) > sizeof( V_92 ) ) &&
! memcmp ( & V_89 [ V_15 ] , V_92 ,
sizeof( V_92 ) ) ) {
V_89 [ V_15 + 4 ] = 0x01 ;
V_15 += sizeof( V_92 ) ;
}
if ( ( ( * V_90 - V_15 ) > sizeof( V_93 ) ) &&
! memcmp ( & V_89 [ V_15 ] , V_93 ,
sizeof( V_93 ) ) ) {
V_89 [ V_15 + 4 ] = 0x01 ;
V_15 += sizeof( V_93 ) ;
}
}
return V_89 ;
}
static int F_43 ( struct V_3 * V_4 ,
const struct V_96 * V_2 )
{
int V_51 ;
struct V_36 * V_91 ;
int V_7 ;
char * V_97 ;
int V_98 ;
struct V_31 * V_32 ;
struct V_31 * V_99 = NULL ;
V_91 = F_44 ( & V_4 -> V_100 , sizeof( * V_91 ) , V_101 ) ;
if ( ! V_91 ) {
F_39 ( V_4 , L_11 ) ;
return - V_45 ;
}
F_45 ( V_4 , V_91 ) ;
V_91 -> V_94 = V_2 -> V_102 ;
F_46 ( & V_91 -> V_63 ) ;
F_46 ( & V_91 -> V_38 ) ;
F_47 ( & V_91 -> V_52 ) ;
V_51 = F_48 ( V_4 ) ;
if ( V_51 ) {
F_39 ( V_4 , L_12 ) ;
return V_51 ;
}
F_49 ( & V_4 -> V_103 ) ;
V_51 = F_50 ( V_4 , 0 ) ;
if ( V_51 ) {
F_39 ( V_4 , L_13 ) ;
return V_51 ;
}
F_49 ( & V_91 -> V_47 ) ;
V_91 -> V_104 = 0 ;
V_98 = F_4 ( V_4 ) ;
if ( V_98 > V_105 ) {
F_39 ( V_4 , L_14 ) ;
V_51 = - V_43 ;
goto V_106;
}
V_91 -> V_107 = F_13 ( V_98 *
sizeof( struct V_108 ) ,
V_101 ) ;
if ( V_91 -> V_107 == NULL ) {
F_39 ( V_4 , L_15 ) ;
V_51 = - V_45 ;
goto V_106;
}
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; ++ V_7 ) {
struct V_10 * V_11 = & V_4 -> V_11 [ V_7 ] ;
if ( V_11 -> type == V_12 ) {
V_32 = F_13 ( sizeof( * V_32 ) , V_101 ) ;
if ( ! V_32 ) {
F_39 ( V_4 , L_16 ) ;
V_51 = - V_45 ;
goto V_109;
}
V_32 -> V_4 = V_4 ;
V_32 -> V_110 = V_4 -> V_111 ;
V_32 -> V_112 = V_4 -> V_113 ;
V_32 -> V_39 = V_7 ;
if ( V_99 )
V_99 -> V_40 = V_7 ;
V_99 = V_32 ;
V_97 = F_51 ( V_101 , L_17 ,
V_11 -> V_72 ) ;
if ( V_97 == NULL ) {
F_39 ( V_4 , L_18 ) ;
V_51 = - V_45 ;
F_17 ( V_32 ) ;
goto V_109;
}
V_91 -> V_107 [
V_91 -> V_104 ] . V_2 =
V_114 ;
V_91 -> V_107 [
V_91 -> V_104 ] . V_97 = V_97 ;
V_91 -> V_107 [
V_91 -> V_104 ] . V_115 =
V_32 ;
V_91 -> V_107 [
V_91 -> V_104 ] . V_116 =
sizeof( * V_32 ) ;
F_31 ( V_4 , L_19 , V_97 ,
V_32 -> V_39 ) ;
V_91 -> V_104 ++ ;
}
}
if ( V_99 )
V_99 -> V_40 = V_7 ;
V_51 = F_52 ( & V_4 -> V_100 , 0 , V_91 -> V_107 ,
V_91 -> V_104 , NULL , 0 , NULL ) ;
if ( V_51 < 0 )
goto V_109;
return V_51 ;
V_109:
for ( V_7 = 0 ; V_7 < V_91 -> V_104 ; ++ V_7 ) {
F_17 ( V_91 -> V_107 [ V_7 ] . V_97 ) ;
F_17 ( V_91 -> V_107 [ V_7 ] . V_115 ) ;
}
F_17 ( V_91 -> V_107 ) ;
V_106:
F_53 ( V_4 ) ;
return V_51 ;
}
static void F_54 ( struct V_3 * V_4 )
{
struct V_36 * V_50 = F_7 ( V_4 ) ;
unsigned long V_42 ;
int V_7 ;
F_31 ( V_4 , L_20 ) ;
F_41 ( V_4 ) ;
F_53 ( V_4 ) ;
F_11 ( & V_50 -> V_63 , V_42 ) ;
if ( V_50 -> V_60 . V_64 )
F_36 ( & V_50 -> V_60 . V_61 ) ;
F_12 ( & V_50 -> V_63 , V_42 ) ;
F_55 ( & V_4 -> V_100 ) ;
for ( V_7 = 0 ; V_7 < V_50 -> V_104 ; ++ V_7 ) {
F_17 ( V_50 -> V_107 [ V_7 ] . V_97 ) ;
F_17 ( V_50 -> V_107 [ V_7 ] . V_115 ) ;
}
F_17 ( V_50 -> V_107 ) ;
F_45 ( V_4 , NULL ) ;
F_56 ( & V_50 -> V_52 ) ;
}
