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
if ( V_11 -> type == V_12 ||
V_11 -> type == V_13 )
++ V_8 ;
}
return V_8 ;
}
static void F_5 (
struct V_14 * V_15 ,
T_1 V_16 , T_1 V_17 , struct V_18 * V_19 )
{
V_15 -> V_16 = V_16 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_20 = V_19 -> V_21 ;
V_15 -> V_22 = V_19 -> V_23 ;
V_15 -> V_24 = ( V_19 -> V_25 * V_19 -> V_26 ) / 8 ;
V_15 -> V_27 = V_19 -> V_27 ;
V_15 -> V_28 = V_19 -> V_28 ;
}
static struct V_29 * F_6 (
struct V_3 * V_4 ,
T_2 V_30 ,
int V_31 ,
struct V_32 * * V_33 ,
void * * V_34 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 = F_7 ( V_4 ) ;
unsigned long V_39 ;
F_8 ( & V_38 -> V_40 , V_39 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( ( V_36 -> V_30 == V_30 ||
V_36 -> V_30 == V_41 ) &&
( V_31 >=
V_36 -> V_33 -> V_42 ) &&
( V_31 <
V_36 -> V_33 -> V_43 ) ) {
* V_34 = V_36 -> V_34 ;
* V_33 = V_36 -> V_33 ;
F_9 ( & V_38 -> V_40 ,
V_39 ) ;
return V_36 -> V_44 ;
}
F_9 ( & V_38 -> V_40 , V_39 ) ;
return NULL ;
}
int F_10 ( struct V_32 * V_33 ,
T_2 V_30 ,
struct V_29 * V_44 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 = F_7 ( V_33 -> V_4 ) ;
unsigned long V_39 ;
F_8 ( & V_38 -> V_40 , V_39 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_36 -> V_30 == V_30 &&
V_36 -> V_33 == V_33 ) {
F_9 ( & V_38 -> V_40 , V_39 ) ;
return - V_45 ;
}
V_36 = F_11 ( sizeof( * V_36 ) , V_46 ) ;
if ( ! V_36 ) {
F_9 ( & V_38 -> V_40 , V_39 ) ;
return - V_47 ;
}
V_36 -> V_33 = V_33 ;
V_36 -> V_44 = V_44 ;
V_36 -> V_30 = V_30 ;
V_36 -> V_34 = NULL ;
if ( V_30 == V_41 )
F_12 ( & V_36 -> V_48 , & V_38 -> V_49 ) ;
else
F_13 ( & V_36 -> V_48 , & V_38 -> V_49 ) ;
F_9 ( & V_38 -> V_40 , V_39 ) ;
return 0 ;
}
int F_14 ( struct V_32 * V_33 ,
T_2 V_30 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 = F_7 ( V_33 -> V_4 ) ;
unsigned long V_39 ;
F_8 ( & V_38 -> V_40 , V_39 ) ;
F_2 (callback, &pdata->dyn_callback_list, list)
if ( V_36 -> V_30 == V_30 &&
V_36 -> V_33 == V_33 ) {
F_15 ( & V_36 -> V_48 ) ;
F_16 ( V_36 ) ;
break;
}
F_9 ( & V_38 -> V_40 , V_39 ) ;
return 0 ;
}
int F_17 ( struct V_32 * V_33 , T_2 V_17 ,
T_2 V_50 , int V_51 , void * V_52 )
{
struct V_1 * V_6 ;
struct V_37 * V_53 = F_7 ( V_33 -> V_4 ) ;
T_3 * V_54 = V_52 ;
int V_7 = 0 ;
int V_55 ;
T_3 V_56 ;
int V_57 = 0 ;
F_18 ( & V_53 -> V_58 ) ;
V_6 = F_1 ( V_17 , V_33 -> V_4 , V_59 ) ;
if ( ! V_6 || ( V_50 >= V_6 -> V_60 ) ) {
V_57 = - V_45 ;
goto V_61;
}
V_55 = V_51 % sizeof( T_3 ) ;
V_51 = V_51 / sizeof( T_3 ) ;
if ( V_51 ) {
for ( V_7 = 0 ; V_7 < V_51 ; ++ V_7 ) {
F_19 ( V_6 -> V_19 [ V_50 ] , V_7 ,
( V_62 T_3 ) F_20 ( * V_54 ) ) ;
++ V_54 ;
}
}
if ( V_55 ) {
V_56 = 0 ;
memcpy ( & V_56 , ( V_63 * ) V_54 , V_55 ) ;
F_19 ( V_6 -> V_19 [ V_50 ] , V_7 ,
( V_62 T_3 ) F_20 ( V_56 ) ) ;
}
F_21 ( V_33 -> V_4 , V_6 , V_64 ) ;
F_22 ( V_33 -> V_4 ) ;
V_61:
F_23 ( & V_53 -> V_58 ) ;
return V_57 ;
}
int F_24 ( struct V_32 * V_33 , T_2 V_17 ,
T_2 V_50 , int V_51 , void * V_52 )
{
struct V_1 * V_6 ;
struct V_37 * V_53 = F_7 ( V_33 -> V_4 ) ;
int V_25 ;
int V_57 = 0 ;
F_18 ( & V_53 -> V_58 ) ;
V_6 = F_1 ( V_17 , V_33 -> V_4 , V_59 ) ;
if ( ! V_6 || ( V_50 >= V_6 -> V_60 ) ||
V_6 -> V_19 [ V_50 ] -> V_26 < 1 ) {
V_57 = - V_45 ;
goto V_61;
}
F_21 ( V_33 -> V_4 , V_6 , V_65 ) ;
F_22 ( V_33 -> V_4 ) ;
V_25 = F_25 ( V_6 -> V_19 [ V_50 ] -> V_25 ,
8 ) *
V_6 -> V_19 [ V_50 ] -> V_26 ;
if ( ! V_25 ) {
V_57 = - V_45 ;
goto V_61;
}
V_57 = F_26 ( V_25 , V_51 ) ;
memcpy ( V_52 , V_6 -> V_19 [ V_50 ] -> V_56 , V_57 ) ;
V_61:
F_23 ( & V_53 -> V_58 ) ;
return V_57 ;
}
int F_27 ( struct V_32 * V_33 ,
T_2 V_30 ,
T_2 V_66 , T_2 V_17 ,
enum V_67 V_68 )
{
struct V_37 * V_53 = F_7 ( V_33 -> V_4 ) ;
unsigned long V_39 ;
struct V_1 * V_6 ;
int V_69 = 0 ;
V_6 = F_1 ( V_17 , V_33 -> V_4 ,
V_70 ) ;
if ( ! V_6 )
return - V_45 ;
F_18 ( V_33 -> V_71 ) ;
if ( V_68 == V_72 ) {
memset ( & V_33 -> V_73 , 0 , sizeof( V_33 -> V_73 ) ) ;
F_28 ( & V_33 -> V_73 . V_74 ) ;
V_33 -> V_73 . V_30 = V_30 ;
V_33 -> V_73 . V_66 = V_66 ;
V_33 -> V_73 . V_75 = 0 ;
F_8 ( & V_53 -> V_76 , V_39 ) ;
V_33 -> V_73 . V_77 = true ;
F_9 ( & V_53 -> V_76 , V_39 ) ;
}
F_18 ( & V_53 -> V_58 ) ;
F_21 ( V_33 -> V_4 , V_6 , V_65 ) ;
F_23 ( & V_53 -> V_58 ) ;
if ( V_68 == V_72 ) {
F_29 (
& V_33 -> V_73 . V_74 , V_78 * 5 ) ;
switch ( V_33 -> V_73 . V_75 ) {
case 1 :
V_69 = * ( V_63 * ) V_33 -> V_73 . V_79 ;
break;
case 2 :
V_69 = * ( V_80 * ) V_33 -> V_73 . V_79 ;
break;
case 4 :
V_69 = * ( T_2 * ) V_33 -> V_73 . V_79 ;
break;
default:
V_69 = 0 ;
}
F_16 ( V_33 -> V_73 . V_79 ) ;
V_33 -> V_73 . V_77 = false ;
}
F_23 ( V_33 -> V_71 ) ;
return V_69 ;
}
int F_30 ( struct V_32 * V_33 ,
T_2 V_17 , int V_50 , T_2 V_30 )
{
struct V_1 * V_6 ;
struct V_18 * V_19 ;
int V_7 ;
V_6 = F_1 ( V_17 , V_33 -> V_4 , V_59 ) ;
if ( ! V_6 || ( V_50 >= V_6 -> V_60 ) )
goto V_61;
V_19 = V_6 -> V_19 [ V_50 ] ;
for ( V_7 = 0 ; V_7 < V_19 -> V_81 ; ++ V_7 ) {
if ( V_19 -> V_82 [ V_7 ] . V_83 == V_30 )
return V_19 -> V_82 [ V_7 ] . V_84 ;
}
V_61:
return - V_45 ;
}
int F_31 ( struct V_32 * V_33 ,
V_63 type ,
T_2 V_30 ,
T_2 V_66 ,
struct V_14 * V_15 )
{
int V_57 = - 1 ;
int V_7 ;
struct V_1 * V_6 ;
struct V_18 * V_19 ;
struct V_85 * V_86 ;
struct V_3 * V_4 = V_33 -> V_4 ;
V_15 -> V_30 = V_30 ;
V_15 -> V_87 = V_66 ;
V_15 -> V_17 = - 1 ;
V_15 -> V_16 = - 1 ;
V_15 -> V_20 = - 1 ;
V_15 -> V_22 = - 1 ;
V_86 = & V_4 -> V_86 [ type ] ;
F_2 (report, &report_enum->report_list, list) {
for ( V_7 = 0 ; V_7 < V_6 -> V_60 ; ++ V_7 ) {
V_19 = V_6 -> V_19 [ V_7 ] ;
if ( V_19 -> V_81 ) {
if ( V_19 -> V_88 == V_30 &&
( V_19 -> V_89 == V_66 ||
V_19 -> V_82 [ 0 ] . V_83 ==
V_66 ) &&
( V_19 -> V_82 [ 0 ] . V_31 >=
V_33 -> V_42 ) &&
( V_19 -> V_82 [ 0 ] . V_31 <
V_33 -> V_43 ) ) {
F_5 ( V_15 , V_7 ,
V_6 -> V_2 ,
V_19 ) ;
V_57 = 0 ;
break;
}
}
}
}
return V_57 ;
}
static int F_32 ( struct V_3 * V_4 , T_4 V_90 )
{
struct V_37 * V_38 = F_7 ( V_4 ) ;
struct V_35 * V_36 ;
unsigned long V_39 ;
F_33 ( V_4 , L_2 ) ;
F_8 ( & V_38 -> V_40 , V_39 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_36 -> V_44 -> V_91 )
V_36 -> V_44 -> V_91 (
V_36 -> V_33 , V_36 -> V_34 ) ;
}
F_9 ( & V_38 -> V_40 , V_39 ) ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_37 * V_38 = F_7 ( V_4 ) ;
struct V_35 * V_36 ;
unsigned long V_39 ;
F_33 ( V_4 , L_3 ) ;
F_8 ( & V_38 -> V_40 , V_39 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_36 -> V_44 -> V_92 )
V_36 -> V_44 -> V_92 (
V_36 -> V_33 , V_36 -> V_34 ) ;
}
F_9 ( & V_38 -> V_40 , V_39 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_36 ( struct V_3 * V_4 ,
struct V_1 * V_6 , V_63 * V_79 , int V_24 )
{
int V_7 ;
V_63 * V_93 ;
int V_94 ;
struct V_37 * V_38 = F_7 ( V_4 ) ;
unsigned long V_39 ;
struct V_29 * V_36 = NULL ;
struct V_10 * V_11 = NULL ;
void * V_34 = NULL ;
struct V_32 * V_33 = NULL ;
F_33 ( V_4 , L_4 ,
V_6 -> V_2 , V_24 , V_6 -> type ) ;
F_33 ( V_4 , L_5 , V_6 -> V_60 ) ;
if ( V_6 -> type != V_70 )
return 1 ;
V_93 = V_79 ;
V_93 ++ ;
F_8 ( & V_38 -> V_76 , V_39 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_60 ; ++ V_7 ) {
F_33 ( V_4 , L_6 ,
V_7 , V_6 -> V_19 [ V_7 ] -> V_82 -> V_31 ,
V_6 -> V_19 [ V_7 ] -> V_82 -> V_83 ,
( V_6 -> V_19 [ V_7 ] -> V_25 *
V_6 -> V_19 [ V_7 ] -> V_26 ) / 8 ) ;
V_94 = ( V_6 -> V_19 [ V_7 ] -> V_25 *
V_6 -> V_19 [ V_7 ] -> V_26 ) / 8 ;
V_11 = & V_4 -> V_11 [
V_6 -> V_19 [ V_7 ] -> V_82 -> V_31 ] ;
F_33 ( V_4 , L_7 ,
V_11 -> V_82 ) ;
V_36 = F_6 ( V_4 ,
V_6 -> V_19 [ V_7 ] -> V_88 ,
V_6 -> V_19 [ V_7 ] -> V_82 [ 0 ] . V_31 ,
& V_33 , & V_34 ) ;
if ( ! V_36 ) {
V_93 += V_94 ;
continue;
}
if ( V_33 -> V_73 . V_77 && ( V_33 -> V_73 . V_66 ==
V_6 -> V_19 [ V_7 ] -> V_82 -> V_83 ||
V_33 -> V_73 . V_66 ==
V_6 -> V_19 [ V_7 ] -> V_89 ) ) {
F_33 ( V_4 , L_8 ) ;
V_33 -> V_73 . V_79 = F_37 ( V_93 , V_94 , V_46 ) ;
if ( V_33 -> V_73 . V_79 )
V_33 -> V_73 . V_75 = V_94 ;
else
V_33 -> V_73 . V_75 = 0 ;
F_38 ( & V_33 -> V_73 . V_74 ) ;
}
if ( V_36 -> V_95 ) {
if ( V_6 -> V_19 [ V_7 ] -> V_89 )
V_36 -> V_95 ( V_33 ,
V_6 -> V_19 [ V_7 ] -> V_89 , V_94 , V_93 ,
V_36 -> V_96 ) ;
else
V_36 -> V_95 ( V_33 ,
V_6 -> V_19 [ V_7 ] -> V_82 -> V_83 , V_94 , V_93 ,
V_36 -> V_96 ) ;
}
V_93 += V_94 ;
}
if ( V_36 && V_11 && V_36 -> V_97 )
V_36 -> V_97 ( V_33 , V_11 -> V_82 ,
V_36 -> V_96 ) ;
F_9 ( & V_38 -> V_76 , V_39 ) ;
return 1 ;
}
int F_39 ( struct V_32 * V_33 )
{
int V_57 = 0 ;
struct V_37 * V_53 = F_7 ( V_33 -> V_4 ) ;
F_18 ( & V_53 -> V_58 ) ;
if ( ! V_53 -> V_98 ) {
V_57 = F_40 ( V_33 -> V_4 ) ;
if ( V_57 ) {
F_41 ( V_33 -> V_4 , L_9 ) ;
F_23 ( & V_53 -> V_58 ) ;
return V_57 ;
}
}
V_53 -> V_98 ++ ;
F_23 ( & V_53 -> V_58 ) ;
return V_57 ;
}
void F_42 ( struct V_32 * V_33 )
{
struct V_37 * V_53 = F_7 ( V_33 -> V_4 ) ;
F_18 ( & V_53 -> V_58 ) ;
V_53 -> V_98 -- ;
if ( ! V_53 -> V_98 )
F_43 ( V_33 -> V_4 ) ;
F_23 ( & V_53 -> V_58 ) ;
}
static T_5 * F_44 ( struct V_3 * V_4 , T_5 * V_99 ,
unsigned int * V_100 )
{
int V_16 ;
struct V_37 * V_101 = F_7 ( V_4 ) ;
unsigned char V_102 [] = {
0x0a , 0x16 , 0x03 , 0x15 , 0x00 , 0x25 , 0x05 } ;
unsigned char V_103 [] = {
0x0a , 0x19 , 0x03 , 0x15 , 0x00 , 0x25 , 0x05 } ;
if ( ! ( V_101 -> V_104 & V_105 ) ) {
F_33 ( V_4 , L_10 ) ;
return V_99 ;
}
for ( V_16 = 0 ; V_16 < * V_100 ; ++ V_16 ) {
if ( ( ( * V_100 - V_16 ) > sizeof( V_102 ) ) &&
! memcmp ( & V_99 [ V_16 ] , V_102 ,
sizeof( V_102 ) ) ) {
V_99 [ V_16 + 4 ] = 0x01 ;
V_16 += sizeof( V_102 ) ;
}
if ( ( ( * V_100 - V_16 ) > sizeof( V_103 ) ) &&
! memcmp ( & V_99 [ V_16 ] , V_103 ,
sizeof( V_103 ) ) ) {
V_99 [ V_16 + 4 ] = 0x01 ;
V_16 += sizeof( V_103 ) ;
}
}
if ( V_4 -> V_106 == V_107 &&
* V_100 == 2558 && V_99 [ 913 ] == 0x17 && V_99 [ 914 ] == 0x40 &&
V_99 [ 915 ] == 0x81 && V_99 [ 916 ] == 0x08 &&
V_99 [ 917 ] == 0x00 && V_99 [ 918 ] == 0x27 &&
V_99 [ 921 ] == 0x07 && V_99 [ 922 ] == 0x00 ) {
V_99 [ 914 ] = V_99 [ 935 ] = V_99 [ 956 ] = 0xc0 ;
V_99 [ 915 ] = V_99 [ 936 ] = V_99 [ 957 ] = 0x7e ;
V_99 [ 916 ] = V_99 [ 937 ] = V_99 [ 958 ] = 0xf7 ;
V_99 [ 917 ] = V_99 [ 938 ] = V_99 [ 959 ] = 0xff ;
}
return V_99 ;
}
static int F_45 ( struct V_3 * V_4 ,
const struct V_108 * V_2 )
{
int V_57 ;
struct V_37 * V_101 ;
int V_7 ;
char * V_109 ;
int V_110 ;
struct V_32 * V_33 ;
struct V_32 * V_111 = NULL ;
struct V_32 * V_112 = NULL ;
V_101 = F_46 ( & V_4 -> V_113 , sizeof( * V_101 ) , V_114 ) ;
if ( ! V_101 ) {
F_41 ( V_4 , L_11 ) ;
return - V_47 ;
}
F_47 ( V_4 , V_101 ) ;
V_101 -> V_104 = V_2 -> V_115 ;
F_48 ( & V_101 -> V_76 ) ;
F_48 ( & V_101 -> V_40 ) ;
F_49 ( & V_101 -> V_58 ) ;
V_57 = F_50 ( V_4 ) ;
if ( V_57 ) {
F_41 ( V_4 , L_12 ) ;
return V_57 ;
}
F_51 ( & V_4 -> V_116 ) ;
V_57 = F_52 ( V_4 , 0 ) ;
if ( V_57 ) {
F_41 ( V_4 , L_13 ) ;
return V_57 ;
}
F_51 ( & V_101 -> V_49 ) ;
V_101 -> V_117 = 0 ;
V_110 = F_4 ( V_4 ) ;
if ( V_110 > V_118 ) {
F_41 ( V_4 , L_14 ) ;
V_57 = - V_45 ;
goto V_119;
}
V_101 -> V_120 = F_46 ( & V_4 -> V_113 , V_110 *
sizeof( struct V_121 ) ,
V_114 ) ;
if ( V_101 -> V_120 == NULL ) {
F_41 ( V_4 , L_15 ) ;
V_57 = - V_47 ;
goto V_119;
}
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; ++ V_7 ) {
struct V_10 * V_11 = & V_4 -> V_11 [ V_7 ] ;
if ( V_11 -> type == V_12 ||
V_11 -> type == V_13 ) {
V_33 = F_46 ( & V_4 -> V_113 , sizeof( * V_33 ) ,
V_114 ) ;
if ( ! V_33 ) {
F_41 ( V_4 , L_16 ) ;
V_57 = - V_47 ;
goto V_119;
}
V_33 -> V_4 = V_4 ;
V_33 -> V_122 = V_4 -> V_123 ;
V_33 -> V_124 = V_4 -> V_106 ;
V_33 -> V_82 = V_11 -> V_82 ;
V_33 -> V_71 = F_46 ( & V_4 -> V_113 ,
sizeof( struct V_58 ) ,
V_114 ) ;
if ( ! V_33 -> V_71 ) {
V_57 = - V_47 ;
goto V_119;
}
F_49 ( V_33 -> V_71 ) ;
V_33 -> V_42 = V_7 ;
if ( V_111 )
V_111 -> V_43 = V_7 ;
V_111 = V_33 ;
V_109 = F_53 ( & V_4 -> V_113 , V_114 ,
L_17 ,
V_11 -> V_82 ) ;
if ( V_109 == NULL ) {
F_41 ( V_4 , L_18 ) ;
V_57 = - V_47 ;
goto V_119;
}
V_101 -> V_120 [
V_101 -> V_117 ] . V_109 = V_109 ;
V_101 -> V_120 [
V_101 -> V_117 ] . V_125 =
V_33 ;
V_101 -> V_120 [
V_101 -> V_117 ] . V_126 =
sizeof( * V_33 ) ;
F_33 ( V_4 , L_19 , V_109 ,
V_33 -> V_42 ) ;
V_101 -> V_117 ++ ;
if ( V_112 )
V_112 -> V_43 = V_7 ;
if ( V_11 -> type == V_13 &&
V_11 -> V_82 == V_41 )
V_112 = V_33 ;
}
}
if ( V_111 )
V_111 -> V_43 = V_7 ;
if ( V_112 )
V_112 -> V_43 = V_7 ;
V_57 = F_54 ( & V_4 -> V_113 ,
V_101 -> V_120 ,
V_101 -> V_117 ) ;
if ( V_57 < 0 )
goto V_119;
return V_57 ;
V_119:
F_55 ( V_4 ) ;
return V_57 ;
}
static void F_56 ( struct V_3 * V_4 )
{
struct V_37 * V_53 = F_7 ( V_4 ) ;
unsigned long V_39 ;
int V_7 ;
F_33 ( V_4 , L_20 ) ;
F_43 ( V_4 ) ;
F_55 ( V_4 ) ;
F_8 ( & V_53 -> V_76 , V_39 ) ;
for ( V_7 = 0 ; V_7 < V_53 -> V_117 ; ++ V_7 ) {
struct V_32 * V_33 =
V_53 -> V_120 [ V_7 ] . V_125 ;
if ( V_33 -> V_73 . V_77 )
F_38 ( & V_33 -> V_73 . V_74 ) ;
}
F_9 ( & V_53 -> V_76 , V_39 ) ;
F_57 ( & V_4 -> V_113 ) ;
F_47 ( V_4 , NULL ) ;
F_58 ( & V_53 -> V_58 ) ;
}
