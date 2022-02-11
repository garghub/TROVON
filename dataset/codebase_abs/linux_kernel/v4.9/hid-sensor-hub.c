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
memset ( V_52 , 0 , V_51 ) ;
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
V_63 * V_65 ;
int V_66 = 0 ;
int V_7 ;
F_18 ( & V_53 -> V_58 ) ;
V_6 = F_1 ( V_17 , V_33 -> V_4 , V_59 ) ;
if ( ! V_6 || ( V_50 >= V_6 -> V_60 ) ||
V_6 -> V_19 [ V_50 ] -> V_26 < 1 ) {
V_57 = - V_45 ;
goto V_61;
}
F_21 ( V_33 -> V_4 , V_6 , V_67 ) ;
F_22 ( V_33 -> V_4 ) ;
V_25 = F_25 ( V_6 -> V_19 [ V_50 ] -> V_25 ,
8 ) *
V_6 -> V_19 [ V_50 ] -> V_26 ;
if ( ! V_25 ) {
V_57 = - V_45 ;
goto V_61;
}
V_57 = F_26 ( V_25 , V_51 ) ;
V_65 = ( V_63 * ) V_6 -> V_19 [ V_50 ] -> V_56 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_19 [ V_50 ] -> V_26 ; ++ V_7 ) {
if ( V_66 >= V_57 )
break;
memcpy ( & ( ( V_63 * ) V_52 ) [ V_66 ] , V_65 ,
V_6 -> V_19 [ V_50 ] -> V_25 / 8 ) ;
V_65 += sizeof( T_3 ) ;
V_66 += ( V_6 -> V_19 [ V_50 ] -> V_25 / 8 ) ;
}
V_61:
F_23 ( & V_53 -> V_58 ) ;
return V_57 ;
}
int F_27 ( struct V_32 * V_33 ,
T_2 V_30 ,
T_2 V_68 , T_2 V_17 ,
enum V_69 V_70 )
{
struct V_37 * V_53 = F_7 ( V_33 -> V_4 ) ;
unsigned long V_39 ;
struct V_1 * V_6 ;
int V_71 = 0 ;
V_6 = F_1 ( V_17 , V_33 -> V_4 ,
V_72 ) ;
if ( ! V_6 )
return - V_45 ;
F_18 ( V_33 -> V_73 ) ;
if ( V_70 == V_74 ) {
memset ( & V_33 -> V_75 , 0 , sizeof( V_33 -> V_75 ) ) ;
F_28 ( & V_33 -> V_75 . V_76 ) ;
V_33 -> V_75 . V_30 = V_30 ;
V_33 -> V_75 . V_68 = V_68 ;
V_33 -> V_75 . V_77 = 0 ;
F_8 ( & V_53 -> V_78 , V_39 ) ;
V_33 -> V_75 . V_79 = true ;
F_9 ( & V_53 -> V_78 , V_39 ) ;
}
F_18 ( & V_53 -> V_58 ) ;
F_21 ( V_33 -> V_4 , V_6 , V_67 ) ;
F_23 ( & V_53 -> V_58 ) ;
if ( V_70 == V_74 ) {
F_29 (
& V_33 -> V_75 . V_76 , V_80 * 5 ) ;
switch ( V_33 -> V_75 . V_77 ) {
case 1 :
V_71 = * ( V_63 * ) V_33 -> V_75 . V_81 ;
break;
case 2 :
V_71 = * ( V_82 * ) V_33 -> V_75 . V_81 ;
break;
case 4 :
V_71 = * ( T_2 * ) V_33 -> V_75 . V_81 ;
break;
default:
V_71 = 0 ;
}
F_16 ( V_33 -> V_75 . V_81 ) ;
V_33 -> V_75 . V_79 = false ;
}
F_23 ( V_33 -> V_73 ) ;
return V_71 ;
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
for ( V_7 = 0 ; V_7 < V_19 -> V_83 ; ++ V_7 ) {
if ( V_19 -> V_84 [ V_7 ] . V_85 == V_30 )
return V_19 -> V_84 [ V_7 ] . V_86 ;
}
V_61:
return - V_45 ;
}
int F_31 ( struct V_32 * V_33 ,
V_63 type ,
T_2 V_30 ,
T_2 V_68 ,
struct V_14 * V_15 )
{
int V_57 = - 1 ;
int V_7 ;
struct V_1 * V_6 ;
struct V_18 * V_19 ;
struct V_87 * V_88 ;
struct V_3 * V_4 = V_33 -> V_4 ;
V_15 -> V_30 = V_30 ;
V_15 -> V_89 = V_68 ;
V_15 -> V_17 = - 1 ;
V_15 -> V_16 = - 1 ;
V_15 -> V_20 = - 1 ;
V_15 -> V_22 = - 1 ;
V_88 = & V_4 -> V_88 [ type ] ;
F_2 (report, &report_enum->report_list, list) {
for ( V_7 = 0 ; V_7 < V_6 -> V_60 ; ++ V_7 ) {
V_19 = V_6 -> V_19 [ V_7 ] ;
if ( V_19 -> V_83 ) {
if ( V_19 -> V_90 == V_30 &&
( V_19 -> V_91 == V_68 ||
V_19 -> V_84 [ 0 ] . V_85 ==
V_68 ) &&
( V_19 -> V_84 [ 0 ] . V_31 >=
V_33 -> V_42 ) &&
( V_19 -> V_84 [ 0 ] . V_31 <
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
static int F_32 ( struct V_3 * V_4 , T_4 V_92 )
{
struct V_37 * V_38 = F_7 ( V_4 ) ;
struct V_35 * V_36 ;
unsigned long V_39 ;
F_33 ( V_4 , L_2 ) ;
F_8 ( & V_38 -> V_40 , V_39 ) ;
F_2 (callback, &pdata->dyn_callback_list, list) {
if ( V_36 -> V_44 -> V_93 )
V_36 -> V_44 -> V_93 (
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
if ( V_36 -> V_44 -> V_94 )
V_36 -> V_44 -> V_94 (
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
struct V_1 * V_6 , V_63 * V_81 , int V_24 )
{
int V_7 ;
V_63 * V_95 ;
int V_96 ;
struct V_37 * V_38 = F_7 ( V_4 ) ;
unsigned long V_39 ;
struct V_29 * V_36 = NULL ;
struct V_10 * V_11 = NULL ;
void * V_34 = NULL ;
struct V_32 * V_33 = NULL ;
F_33 ( V_4 , L_4 ,
V_6 -> V_2 , V_24 , V_6 -> type ) ;
F_33 ( V_4 , L_5 , V_6 -> V_60 ) ;
if ( V_6 -> type != V_72 )
return 1 ;
V_95 = V_81 ;
V_95 ++ ;
F_8 ( & V_38 -> V_78 , V_39 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_60 ; ++ V_7 ) {
F_33 ( V_4 , L_6 ,
V_7 , V_6 -> V_19 [ V_7 ] -> V_84 -> V_31 ,
V_6 -> V_19 [ V_7 ] -> V_84 -> V_85 ,
( V_6 -> V_19 [ V_7 ] -> V_25 *
V_6 -> V_19 [ V_7 ] -> V_26 ) / 8 ) ;
V_96 = ( V_6 -> V_19 [ V_7 ] -> V_25 *
V_6 -> V_19 [ V_7 ] -> V_26 ) / 8 ;
V_11 = & V_4 -> V_11 [
V_6 -> V_19 [ V_7 ] -> V_84 -> V_31 ] ;
F_33 ( V_4 , L_7 ,
V_11 -> V_84 ) ;
V_36 = F_6 ( V_4 ,
V_6 -> V_19 [ V_7 ] -> V_90 ,
V_6 -> V_19 [ V_7 ] -> V_84 [ 0 ] . V_31 ,
& V_33 , & V_34 ) ;
if ( ! V_36 ) {
V_95 += V_96 ;
continue;
}
if ( V_33 -> V_75 . V_79 && ( V_33 -> V_75 . V_68 ==
V_6 -> V_19 [ V_7 ] -> V_84 -> V_85 ||
V_33 -> V_75 . V_68 ==
V_6 -> V_19 [ V_7 ] -> V_91 ) ) {
F_33 ( V_4 , L_8 ) ;
V_33 -> V_75 . V_81 = F_37 ( V_95 , V_96 , V_46 ) ;
if ( V_33 -> V_75 . V_81 )
V_33 -> V_75 . V_77 = V_96 ;
else
V_33 -> V_75 . V_77 = 0 ;
F_38 ( & V_33 -> V_75 . V_76 ) ;
}
if ( V_36 -> V_97 ) {
if ( V_6 -> V_19 [ V_7 ] -> V_91 )
V_36 -> V_97 ( V_33 ,
V_6 -> V_19 [ V_7 ] -> V_91 , V_96 , V_95 ,
V_36 -> V_98 ) ;
else
V_36 -> V_97 ( V_33 ,
V_6 -> V_19 [ V_7 ] -> V_84 -> V_85 , V_96 , V_95 ,
V_36 -> V_98 ) ;
}
V_95 += V_96 ;
}
if ( V_36 && V_11 && V_36 -> V_99 )
V_36 -> V_99 ( V_33 , V_11 -> V_84 ,
V_36 -> V_98 ) ;
F_9 ( & V_38 -> V_78 , V_39 ) ;
return 1 ;
}
int F_39 ( struct V_32 * V_33 )
{
int V_57 = 0 ;
struct V_37 * V_53 = F_7 ( V_33 -> V_4 ) ;
F_18 ( & V_53 -> V_58 ) ;
if ( ! V_53 -> V_100 ) {
V_57 = F_40 ( V_33 -> V_4 ) ;
if ( V_57 ) {
F_41 ( V_33 -> V_4 , L_9 ) ;
F_23 ( & V_53 -> V_58 ) ;
return V_57 ;
}
}
V_53 -> V_100 ++ ;
F_23 ( & V_53 -> V_58 ) ;
return V_57 ;
}
void F_42 ( struct V_32 * V_33 )
{
struct V_37 * V_53 = F_7 ( V_33 -> V_4 ) ;
F_18 ( & V_53 -> V_58 ) ;
V_53 -> V_100 -- ;
if ( ! V_53 -> V_100 )
F_43 ( V_33 -> V_4 ) ;
F_23 ( & V_53 -> V_58 ) ;
}
static T_5 * F_44 ( struct V_3 * V_4 , T_5 * V_101 ,
unsigned int * V_102 )
{
int V_16 ;
struct V_37 * V_103 = F_7 ( V_4 ) ;
unsigned char V_104 [] = {
0x0a , 0x16 , 0x03 , 0x15 , 0x00 , 0x25 , 0x05 } ;
unsigned char V_105 [] = {
0x0a , 0x19 , 0x03 , 0x15 , 0x00 , 0x25 , 0x05 } ;
if ( ! ( V_103 -> V_106 & V_107 ) ) {
F_33 ( V_4 , L_10 ) ;
return V_101 ;
}
for ( V_16 = 0 ; V_16 < * V_102 ; ++ V_16 ) {
if ( ( ( * V_102 - V_16 ) > sizeof( V_104 ) ) &&
! memcmp ( & V_101 [ V_16 ] , V_104 ,
sizeof( V_104 ) ) ) {
V_101 [ V_16 + 4 ] = 0x01 ;
V_16 += sizeof( V_104 ) ;
}
if ( ( ( * V_102 - V_16 ) > sizeof( V_105 ) ) &&
! memcmp ( & V_101 [ V_16 ] , V_105 ,
sizeof( V_105 ) ) ) {
V_101 [ V_16 + 4 ] = 0x01 ;
V_16 += sizeof( V_105 ) ;
}
}
if ( V_4 -> V_108 == V_109 &&
* V_102 == 2558 && V_101 [ 913 ] == 0x17 && V_101 [ 914 ] == 0x40 &&
V_101 [ 915 ] == 0x81 && V_101 [ 916 ] == 0x08 &&
V_101 [ 917 ] == 0x00 && V_101 [ 918 ] == 0x27 &&
V_101 [ 921 ] == 0x07 && V_101 [ 922 ] == 0x00 ) {
V_101 [ 914 ] = V_101 [ 935 ] = V_101 [ 956 ] = 0xc0 ;
V_101 [ 915 ] = V_101 [ 936 ] = V_101 [ 957 ] = 0x7e ;
V_101 [ 916 ] = V_101 [ 937 ] = V_101 [ 958 ] = 0xf7 ;
V_101 [ 917 ] = V_101 [ 938 ] = V_101 [ 959 ] = 0xff ;
}
return V_101 ;
}
static int F_45 ( struct V_3 * V_4 ,
const struct V_110 * V_2 )
{
int V_57 ;
struct V_37 * V_103 ;
int V_7 ;
char * V_111 ;
int V_112 ;
struct V_32 * V_33 ;
struct V_32 * V_113 = NULL ;
struct V_32 * V_114 = NULL ;
V_103 = F_46 ( & V_4 -> V_115 , sizeof( * V_103 ) , V_116 ) ;
if ( ! V_103 ) {
F_41 ( V_4 , L_11 ) ;
return - V_47 ;
}
F_47 ( V_4 , V_103 ) ;
V_103 -> V_106 = V_2 -> V_117 ;
F_48 ( & V_103 -> V_78 ) ;
F_48 ( & V_103 -> V_40 ) ;
F_49 ( & V_103 -> V_58 ) ;
V_57 = F_50 ( V_4 ) ;
if ( V_57 ) {
F_41 ( V_4 , L_12 ) ;
return V_57 ;
}
F_51 ( & V_4 -> V_118 ) ;
V_57 = F_52 ( V_4 , 0 ) ;
if ( V_57 ) {
F_41 ( V_4 , L_13 ) ;
return V_57 ;
}
F_51 ( & V_103 -> V_49 ) ;
V_103 -> V_119 = 0 ;
V_112 = F_4 ( V_4 ) ;
if ( V_112 > V_120 ) {
F_41 ( V_4 , L_14 ) ;
V_57 = - V_45 ;
goto V_121;
}
V_103 -> V_122 = F_46 ( & V_4 -> V_115 , V_112 *
sizeof( struct V_123 ) ,
V_116 ) ;
if ( V_103 -> V_122 == NULL ) {
F_41 ( V_4 , L_15 ) ;
V_57 = - V_47 ;
goto V_121;
}
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; ++ V_7 ) {
struct V_10 * V_11 = & V_4 -> V_11 [ V_7 ] ;
if ( V_11 -> type == V_12 ||
V_11 -> type == V_13 ) {
V_33 = F_46 ( & V_4 -> V_115 , sizeof( * V_33 ) ,
V_116 ) ;
if ( ! V_33 ) {
F_41 ( V_4 , L_16 ) ;
V_57 = - V_47 ;
goto V_121;
}
V_33 -> V_4 = V_4 ;
V_33 -> V_124 = V_4 -> V_125 ;
V_33 -> V_126 = V_4 -> V_108 ;
V_33 -> V_84 = V_11 -> V_84 ;
V_33 -> V_73 = F_46 ( & V_4 -> V_115 ,
sizeof( struct V_58 ) ,
V_116 ) ;
if ( ! V_33 -> V_73 ) {
V_57 = - V_47 ;
goto V_121;
}
F_49 ( V_33 -> V_73 ) ;
V_33 -> V_42 = V_7 ;
if ( V_113 )
V_113 -> V_43 = V_7 ;
V_113 = V_33 ;
V_111 = F_53 ( & V_4 -> V_115 , V_116 ,
L_17 ,
V_11 -> V_84 ) ;
if ( V_111 == NULL ) {
F_41 ( V_4 , L_18 ) ;
V_57 = - V_47 ;
goto V_121;
}
V_103 -> V_122 [
V_103 -> V_119 ] . V_111 = V_111 ;
V_103 -> V_122 [
V_103 -> V_119 ] . V_127 =
V_33 ;
V_103 -> V_122 [
V_103 -> V_119 ] . V_128 =
sizeof( * V_33 ) ;
F_33 ( V_4 , L_19 , V_111 ,
V_33 -> V_42 ) ;
V_103 -> V_119 ++ ;
if ( V_114 )
V_114 -> V_43 = V_7 ;
if ( V_11 -> type == V_13 &&
V_11 -> V_84 == V_41 )
V_114 = V_33 ;
}
}
if ( V_113 )
V_113 -> V_43 = V_7 ;
if ( V_114 )
V_114 -> V_43 = V_7 ;
V_57 = F_54 ( & V_4 -> V_115 ,
V_103 -> V_122 ,
V_103 -> V_119 ) ;
if ( V_57 < 0 )
goto V_121;
return V_57 ;
V_121:
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
F_8 ( & V_53 -> V_78 , V_39 ) ;
for ( V_7 = 0 ; V_7 < V_53 -> V_119 ; ++ V_7 ) {
struct V_32 * V_33 =
V_53 -> V_122 [ V_7 ] . V_127 ;
if ( V_33 -> V_75 . V_79 )
F_38 ( & V_33 -> V_75 . V_76 ) ;
}
F_9 ( & V_53 -> V_78 , V_39 ) ;
F_57 ( & V_4 -> V_115 ) ;
F_47 ( V_4 , NULL ) ;
F_58 ( & V_53 -> V_58 ) ;
}
