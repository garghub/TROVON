struct V_1 * F_1 ( unsigned V_2 )
{
struct V_1 * V_3 ;
F_2 ( & V_4 ) ;
V_3 = V_5 [ V_2 ] ;
if ( V_3 ) {
F_2 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_7 ) {
F_3 ( & V_3 -> V_6 ) ;
V_3 = NULL ;
} else {
F_4 ( & V_3 -> V_8 ) ;
}
}
F_3 ( & V_4 ) ;
return V_3 ;
}
static struct V_1 * F_5 ( struct V_1 * V_3 ,
int V_9 , unsigned int * V_10 )
{
unsigned int V_11 , V_12 ;
int V_13 ;
F_6 ( & V_3 -> V_14 -> V_15 , L_1 , V_16 , V_9 ) ;
* V_10 = 0 ;
F_2 ( & V_4 ) ;
for ( V_11 = 0 ; V_11 < V_17 ; ++ V_11 ) {
if ( V_5 [ V_11 ] )
continue;
V_13 = 1 ;
for ( V_12 = 1 ; V_12 <= V_9 - 1 ; ++ V_12 )
if ( ( V_11 + V_12 >= V_17 ) || ( V_5 [ V_11 + V_12 ] ) ) {
V_13 = 0 ;
V_11 += V_12 ;
break;
}
if ( V_13 == 0 )
continue;
* V_10 = V_11 ;
V_12 = 0 ;
F_6 ( & V_3 -> V_14 -> V_15 , L_2 , V_16 , * V_10 ) ;
for ( V_11 = * V_10 ; ( V_11 < ( * V_10 + V_9 ) ) && ( V_11 < V_17 ) ; ++ V_11 ) {
V_5 [ V_11 ] = V_3 ;
V_3 -> V_18 [ V_12 ++ ] -> V_19 = V_11 ;
}
F_3 ( & V_4 ) ;
return V_3 ;
}
F_3 ( & V_4 ) ;
return NULL ;
}
static void F_7 ( struct V_1 * V_3 )
{
int V_11 ;
F_2 ( & V_4 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 )
V_5 [ V_3 -> V_10 + V_11 ] = NULL ;
F_3 ( & V_4 ) ;
}
static void F_8 ( struct V_8 * V_8 )
{
struct V_1 * V_3 ;
struct V_20 * V_18 ;
int V_11 ;
V_3 = F_9 ( V_8 ) ;
if ( V_3 -> V_10 != V_21 )
F_7 ( V_3 ) ;
if ( V_3 -> V_22 && V_3 -> type -> V_23 )
V_3 -> type -> V_23 ( V_3 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_24 ; ++ V_11 ) {
V_18 = V_3 -> V_18 [ V_11 ] ;
if ( V_18 ) {
V_18 -> V_3 = NULL ;
F_10 ( & V_18 -> V_15 ) ;
}
}
F_11 ( V_3 -> V_14 ) ;
F_12 ( V_3 -> V_15 ) ;
F_13 ( V_3 ) ;
}
void F_14 ( struct V_1 * V_3 )
{
F_15 ( & V_3 -> V_8 , F_8 ) ;
}
static int F_16 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
int V_29 = V_28 -> V_2 ;
struct V_1 * V_3 ;
struct V_20 * V_18 ;
int V_30 = - V_31 ;
V_3 = F_1 ( V_29 ) ;
if ( ! V_3 )
return V_30 ;
V_18 = V_3 -> V_18 [ V_29 - V_3 -> V_10 ] ;
if ( ! V_18 )
goto V_32;
if ( ! F_17 ( V_3 -> type -> V_26 . V_33 ) )
goto V_34;
V_30 = F_18 ( V_3 -> V_14 ) ;
if ( V_30 )
goto V_35;
V_30 = F_19 ( & V_18 -> V_18 , V_26 , V_28 ) ;
if ( V_30 )
goto V_36;
F_3 ( & V_3 -> V_6 ) ;
if ( V_3 -> type -> V_37 )
V_3 -> type -> V_37 ( V_28 ) ;
V_28 -> V_38 = V_18 ;
return V_30 ;
V_36:
F_20 ( V_3 -> V_14 ) ;
V_35:
F_21 ( V_3 -> type -> V_26 . V_33 ) ;
V_34:
V_32:
F_14 ( V_3 ) ;
F_3 ( & V_3 -> V_6 ) ;
return V_30 ;
}
static int F_22 ( struct V_39 * V_40 , struct V_27 * V_28 )
{
struct V_20 * V_18 =
F_23 ( V_40 , struct V_20 , V_18 ) ;
struct V_1 * V_3 = V_18 -> V_3 ;
int V_30 ;
F_2 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_7 )
V_30 = - V_31 ;
else
V_30 = V_18 -> V_3 -> type -> V_41 ( V_28 , V_18 ) ;
F_3 ( & V_3 -> V_6 ) ;
if ( V_30 < 0 )
V_30 = F_24 ( V_30 ) ;
return V_30 ;
}
static int F_25 ( struct V_27 * V_28 , struct V_42 * V_43 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
return F_26 ( & V_18 -> V_18 , V_28 , V_43 ) ;
}
static void F_27 ( struct V_39 * V_40 )
{
struct V_20 * V_18 =
F_23 ( V_40 , struct V_20 , V_18 ) ;
struct V_44 * V_45 = V_18 -> V_3 -> type ;
if ( V_45 -> V_46 )
V_45 -> V_46 ( V_18 ) ;
}
static void F_28 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
F_29 ( & V_18 -> V_18 ) ;
}
static void F_30 ( struct V_27 * V_28 , struct V_42 * V_43 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
F_31 ( & V_18 -> V_18 , V_28 , V_43 ) ;
}
static void F_32 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
struct V_1 * V_3 ;
struct V_47 * V_33 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( V_18 -> V_18 . V_48 )
return;
V_28 -> V_38 = NULL ;
V_3 = V_18 -> V_3 ;
V_33 = V_3 -> type -> V_26 . V_33 ;
F_2 ( & V_3 -> V_6 ) ;
if ( ! V_3 -> V_7 )
F_20 ( V_3 -> V_14 ) ;
F_3 ( & V_3 -> V_6 ) ;
F_14 ( V_3 ) ;
F_21 ( V_33 ) ;
}
static int F_33 ( struct V_27 * V_28 , const unsigned char * V_49 ,
int V_50 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
int V_30 = - V_31 ;
if ( V_18 -> V_3 -> V_15 -> V_51 == V_52 )
goto exit;
F_6 ( V_28 -> V_15 , L_4 , V_16 , V_50 ) ;
V_30 = V_18 -> V_3 -> type -> V_53 ( V_28 , V_18 , V_49 , V_50 ) ;
if ( V_30 < 0 )
V_30 = F_24 ( V_30 ) ;
exit:
return V_30 ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
return V_18 -> V_3 -> type -> V_54 ( V_28 ) ;
}
static int F_35 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
struct V_1 * V_3 = V_18 -> V_3 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( V_3 -> V_7 )
return 0 ;
return V_3 -> type -> V_55 ( V_28 ) ;
}
static void F_36 ( struct V_27 * V_28 , int V_56 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
struct V_1 * V_3 = V_18 -> V_3 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( ! V_18 -> V_3 -> type -> V_57 )
return;
F_2 ( & V_3 -> V_6 ) ;
if ( ! V_3 -> V_7 )
V_18 -> V_3 -> type -> V_57 ( V_28 , V_56 ) ;
F_3 ( & V_3 -> V_6 ) ;
}
static void F_37 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( V_18 -> V_3 -> type -> V_58 )
V_18 -> V_3 -> type -> V_58 ( V_28 ) ;
}
static void F_38 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( V_18 -> V_3 -> type -> V_59 )
V_18 -> V_3 -> type -> V_59 ( V_28 ) ;
}
static int F_39 ( struct V_27 * V_28 ,
unsigned int V_60 , unsigned long V_61 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
int V_30 = - V_62 ;
F_6 ( V_28 -> V_15 , L_5 , V_16 , V_60 ) ;
switch ( V_60 ) {
case V_63 :
if ( V_18 -> V_3 -> type -> V_64 )
V_30 = V_18 -> V_3 -> type -> V_64 ( V_28 , V_61 ) ;
break;
default:
if ( V_18 -> V_3 -> type -> V_65 )
V_30 = V_18 -> V_3 -> type -> V_65 ( V_28 , V_60 , V_61 ) ;
}
return V_30 ;
}
static void F_40 ( struct V_27 * V_28 , struct V_66 * V_67 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( V_18 -> V_3 -> type -> V_68 )
V_18 -> V_3 -> type -> V_68 ( V_28 , V_18 , V_67 ) ;
else
F_41 ( & V_28 -> V_69 , V_67 ) ;
}
static int F_42 ( struct V_27 * V_28 , int V_70 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( V_18 -> V_3 -> type -> V_71 )
V_18 -> V_3 -> type -> V_71 ( V_28 , V_70 ) ;
return 0 ;
}
static int F_43 ( struct V_72 * V_73 , void * V_74 )
{
struct V_1 * V_3 ;
int V_11 ;
char V_75 [ 40 ] ;
F_44 ( V_73 , L_6 ) ;
for ( V_11 = 0 ; V_11 < V_17 ; ++ V_11 ) {
V_3 = F_1 ( V_11 ) ;
if ( V_3 == NULL )
continue;
F_45 ( V_73 , L_7 , V_11 ) ;
if ( V_3 -> type -> V_26 . V_33 )
F_45 ( V_73 , L_8 ,
F_46 ( V_3 -> type -> V_26 . V_33 ) ) ;
F_45 ( V_73 , L_9 ,
V_3 -> type -> V_76 ) ;
F_45 ( V_73 , L_10 ,
F_47 ( V_3 -> V_15 -> V_77 . V_78 ) ,
F_47 ( V_3 -> V_15 -> V_77 . V_79 ) ) ;
F_45 ( V_73 , L_11 , V_3 -> V_9 ) ;
F_45 ( V_73 , L_12 , V_11 - V_3 -> V_10 + 1 ) ;
F_48 ( V_3 -> V_15 , V_75 , sizeof( V_75 ) ) ;
F_45 ( V_73 , L_13 , V_75 ) ;
F_49 ( V_73 , '\n' ) ;
F_14 ( V_3 ) ;
F_3 ( & V_3 -> V_6 ) ;
}
return 0 ;
}
static int F_50 ( struct V_80 * V_80 , struct V_42 * V_42 )
{
return F_51 ( V_42 , F_43 , NULL ) ;
}
static int F_52 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( V_18 -> V_3 -> type -> V_81 )
return V_18 -> V_3 -> type -> V_81 ( V_28 ) ;
return - V_82 ;
}
static int F_53 ( struct V_27 * V_28 ,
unsigned int V_83 , unsigned int V_84 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( V_18 -> V_3 -> type -> V_85 )
return V_18 -> V_3 -> type -> V_85 ( V_28 , V_83 , V_84 ) ;
return - V_82 ;
}
static int F_54 ( struct V_27 * V_28 ,
struct V_86 * V_87 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 ) ;
if ( V_18 -> V_3 -> type -> V_88 )
return V_18 -> V_3 -> type -> V_88 ( V_28 , V_87 ) ;
return - V_82 ;
}
void F_55 ( struct V_20 * V_18 )
{
F_56 ( & V_18 -> V_89 ) ;
}
static void F_57 ( struct V_90 * V_89 )
{
struct V_20 * V_18 =
F_23 ( V_89 , struct V_20 , V_89 ) ;
F_58 ( & V_18 -> V_18 ) ;
}
static void F_59 ( struct V_20 * V_18 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_91 ) ; ++ V_11 )
F_61 ( V_18 -> V_91 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_92 ) ; ++ V_11 )
F_61 ( V_18 -> V_92 [ V_11 ] ) ;
F_61 ( V_18 -> V_93 ) ;
F_61 ( V_18 -> V_94 ) ;
}
static void F_62 ( struct V_20 * V_18 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_91 ) ; ++ V_11 )
F_63 ( V_18 -> V_91 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_92 ) ; ++ V_11 )
F_63 ( V_18 -> V_92 [ V_11 ] ) ;
F_63 ( V_18 -> V_93 ) ;
F_63 ( V_18 -> V_94 ) ;
}
static void F_64 ( struct V_95 * V_15 )
{
struct V_20 * V_18 = F_65 ( V_15 ) ;
int V_11 ;
F_6 ( V_15 , L_3 , V_16 ) ;
F_66 ( V_18 -> V_93 ) ;
F_66 ( V_18 -> V_94 ) ;
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_91 ) ; ++ V_11 ) {
F_66 ( V_18 -> V_91 [ V_11 ] ) ;
F_13 ( V_18 -> V_96 [ V_11 ] ) ;
}
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_92 ) ; ++ V_11 ) {
F_66 ( V_18 -> V_92 [ V_11 ] ) ;
F_13 ( V_18 -> V_97 [ V_11 ] ) ;
}
F_67 ( & V_18 -> V_98 ) ;
F_13 ( V_18 -> V_99 ) ;
F_13 ( V_18 -> V_100 ) ;
F_68 ( & V_18 -> V_18 ) ;
F_13 ( V_18 ) ;
}
static struct V_1 * F_69 ( struct V_101 * V_15 ,
struct V_102 * V_14 ,
struct V_44 * V_26 )
{
struct V_1 * V_3 ;
V_3 = F_70 ( sizeof( * V_3 ) , V_103 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_15 = F_71 ( V_15 ) ;
V_3 -> type = V_26 ;
V_3 -> V_14 = F_72 ( V_14 ) ;
F_73 ( & V_3 -> V_8 ) ;
F_74 ( & V_3 -> V_6 ) ;
V_3 -> V_10 = V_21 ;
return V_3 ;
}
static const struct V_104 * F_75 ( struct V_102 * V_105 ,
struct V_44 * V_45 )
{
struct V_106 * V_107 ;
F_76 ( & V_45 -> V_108 . V_109 ) ;
F_77 (dynid, &drv->dynids.list, node) {
if ( F_78 ( V_105 , & V_107 -> V_110 ) ) {
F_79 ( & V_45 -> V_108 . V_109 ) ;
return & V_107 -> V_110 ;
}
}
F_79 ( & V_45 -> V_108 . V_109 ) ;
return NULL ;
}
static const struct V_104 * F_80 ( struct V_44 * V_45 ,
struct V_102 * V_105 )
{
const struct V_104 * V_110 ;
V_110 = F_81 ( V_105 , V_45 -> V_111 ) ;
if ( V_110 ) {
F_6 ( & V_105 -> V_15 , L_14 ) ;
goto exit;
}
V_110 = F_75 ( V_105 , V_45 ) ;
if ( V_110 )
F_6 ( & V_105 -> V_15 , L_15 ) ;
exit:
return V_110 ;
}
static struct V_44 * F_82 (
struct V_102 * V_112 )
{
const struct V_104 * V_110 = NULL ;
struct V_44 * V_45 ;
struct V_113 * V_26 = F_83 ( V_112 -> V_15 . V_26 ) ;
F_77 (drv, &usb_serial_driver_list, driver_list) {
if ( V_45 -> V_113 == V_26 )
V_110 = F_80 ( V_45 , V_112 ) ;
if ( V_110 )
return V_45 ;
}
return NULL ;
}
static int F_84 ( struct V_39 * V_18 )
{
struct V_20 * V_114 = F_23 ( V_18 , struct V_20 , V_18 ) ;
struct V_44 * V_45 = V_114 -> V_3 -> type ;
if ( V_45 -> V_115 )
return V_45 -> V_115 ( V_114 ) ;
return 1 ;
}
static void F_85 ( struct V_39 * V_18 , int V_116 )
{
struct V_20 * V_114 = F_23 ( V_18 , struct V_20 , V_18 ) ;
struct V_1 * V_3 = V_114 -> V_3 ;
struct V_44 * V_45 = V_3 -> type ;
if ( ! V_45 -> V_117 )
return;
F_2 ( & V_3 -> V_6 ) ;
if ( ! V_3 -> V_7 )
V_45 -> V_117 ( V_114 , V_116 ) ;
F_3 ( & V_3 -> V_6 ) ;
}
static int F_86 ( struct V_102 * V_14 ,
const struct V_104 * V_110 )
{
struct V_95 * V_118 = & V_14 -> V_15 ;
struct V_101 * V_15 = F_87 ( V_14 ) ;
struct V_1 * V_3 = NULL ;
struct V_20 * V_18 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_121 * V_123 [ V_124 ] ;
struct V_121 * V_125 [ V_124 ] ;
struct V_121 * V_126 [ V_124 ] ;
struct V_121 * V_127 [ V_124 ] ;
struct V_44 * type = NULL ;
int V_30 ;
unsigned int V_10 ;
int V_128 ;
int V_11 ;
int V_12 ;
int V_129 = 0 ;
int V_130 = 0 ;
int V_131 = 0 ;
int V_132 = 0 ;
int V_9 = 0 ;
int V_133 ;
F_2 ( & V_4 ) ;
type = F_82 ( V_14 ) ;
if ( ! type ) {
F_3 ( & V_4 ) ;
F_6 ( V_118 , L_16 ) ;
return - V_31 ;
}
if ( ! F_17 ( type -> V_26 . V_33 ) ) {
F_3 ( & V_4 ) ;
F_88 ( V_118 , L_17 ) ;
return - V_134 ;
}
F_3 ( & V_4 ) ;
V_3 = F_69 ( V_15 , V_14 , type ) ;
if ( ! V_3 ) {
F_21 ( type -> V_26 . V_33 ) ;
return - V_135 ;
}
if ( type -> V_136 ) {
const struct V_104 * V_110 ;
V_110 = F_80 ( type , V_14 ) ;
V_30 = type -> V_136 ( V_3 , V_110 ) ;
if ( V_30 ) {
F_6 ( V_118 , L_18 ) ;
F_14 ( V_3 ) ;
F_21 ( type -> V_26 . V_33 ) ;
return V_30 ;
}
}
V_120 = V_14 -> V_137 ;
for ( V_11 = 0 ; V_11 < V_120 -> V_138 . V_139 ; ++ V_11 ) {
V_122 = & V_120 -> V_122 [ V_11 ] . V_138 ;
if ( F_89 ( V_122 ) ) {
F_6 ( V_118 , L_19 , V_11 ) ;
V_126 [ V_131 ] = V_122 ;
++ V_131 ;
}
if ( F_90 ( V_122 ) ) {
F_6 ( V_118 , L_20 , V_11 ) ;
V_127 [ V_132 ] = V_122 ;
++ V_132 ;
}
if ( F_91 ( V_122 ) ) {
F_6 ( V_118 , L_21 , V_11 ) ;
V_123 [ V_129 ] = V_122 ;
++ V_129 ;
}
if ( F_92 ( V_122 ) ) {
F_6 ( V_118 , L_22 , V_11 ) ;
V_125 [ V_130 ] = V_122 ;
++ V_130 ;
}
}
#if F_93 ( V_140 ) || F_93 ( V_141 )
if ( ( ( F_47 ( V_15 -> V_77 . V_78 ) == V_142 ) &&
( F_47 ( V_15 -> V_77 . V_79 ) == V_143 ) ) ||
( ( F_47 ( V_15 -> V_77 . V_78 ) == V_144 ) &&
( F_47 ( V_15 -> V_77 . V_79 ) == V_145 ) ) ||
( ( F_47 ( V_15 -> V_77 . V_78 ) == V_146 ) &&
( F_47 ( V_15 -> V_77 . V_79 ) == V_147 ) ) ||
( ( F_47 ( V_15 -> V_77 . V_78 ) == V_148 ) &&
( F_47 ( V_15 -> V_77 . V_79 ) == V_149 ) ) ) {
if ( V_14 != V_15 -> V_150 -> V_14 [ 0 ] ) {
V_120 = V_15 -> V_150 -> V_14 [ 0 ] -> V_137 ;
for ( V_11 = 0 ; V_11 < V_120 -> V_138 . V_139 ; ++ V_11 ) {
V_122 = & V_120 -> V_122 [ V_11 ] . V_138 ;
if ( F_91 ( V_122 ) ) {
F_6 ( V_118 , L_23 ) ;
V_123 [ V_129 ] = V_122 ;
++ V_129 ;
}
}
}
if ( V_131 == 0 || V_132 == 0 ) {
F_94 ( V_118 , L_24 ) ;
F_14 ( V_3 ) ;
F_21 ( type -> V_26 . V_33 ) ;
return - V_31 ;
}
}
#endif
#ifdef F_95
if ( type == & V_151 ) {
V_9 = V_132 ;
if ( V_9 == 0 ) {
F_88 ( V_118 , L_25 ) ;
F_14 ( V_3 ) ;
F_21 ( type -> V_26 . V_33 ) ;
return - V_134 ;
}
F_94 ( V_118 , L_26 ) ;
F_94 ( V_118 , L_27 ) ;
}
#endif
if ( ! V_9 ) {
if ( type -> V_152 )
V_9 = type -> V_152 ( V_3 ) ;
if ( ! V_9 )
V_9 = type -> V_9 ;
}
V_3 -> V_9 = V_9 ;
V_3 -> V_131 = V_131 ;
V_3 -> V_132 = V_132 ;
V_3 -> V_129 = V_129 ;
V_3 -> V_130 = V_130 ;
F_94 ( V_118 , L_28 , type -> V_76 ) ;
V_133 = F_96 ( V_131 , V_132 ) ;
V_133 = F_96 ( V_133 , V_129 ) ;
V_133 = F_96 ( V_133 , V_130 ) ;
V_133 = F_96 ( V_133 , ( int ) V_3 -> V_9 ) ;
V_3 -> V_24 = V_133 ;
F_6 ( V_118 , L_29 , V_133 ) ;
for ( V_11 = 0 ; V_11 < V_133 ; ++ V_11 ) {
V_18 = F_70 ( sizeof( struct V_20 ) , V_103 ) ;
if ( ! V_18 )
goto V_153;
F_97 ( & V_18 -> V_18 ) ;
V_18 -> V_18 . V_154 = & V_155 ;
V_18 -> V_3 = V_3 ;
F_98 ( & V_18 -> V_109 ) ;
F_99 ( & V_18 -> V_89 , F_57 ) ;
V_3 -> V_18 [ V_11 ] = V_18 ;
V_18 -> V_15 . V_156 = & V_14 -> V_15 ;
V_18 -> V_15 . V_26 = NULL ;
V_18 -> V_15 . V_157 = & V_158 ;
V_18 -> V_15 . V_23 = & F_64 ;
F_100 ( & V_18 -> V_15 ) ;
}
for ( V_11 = 0 ; V_11 < V_131 ; ++ V_11 ) {
V_122 = V_126 [ V_11 ] ;
V_18 = V_3 -> V_18 [ V_11 ] ;
V_128 = F_101 ( int , V_3 -> type -> V_159 ,
F_102 ( V_122 ) ) ;
V_18 -> V_159 = V_128 ;
V_18 -> V_160 = V_122 -> V_161 ;
for ( V_12 = 0 ; V_12 < F_60 ( V_18 -> V_91 ) ; ++ V_12 ) {
F_103 ( V_12 , & V_18 -> V_162 ) ;
V_18 -> V_91 [ V_12 ] = F_104 ( 0 , V_103 ) ;
if ( ! V_18 -> V_91 [ V_12 ] )
goto V_153;
V_18 -> V_96 [ V_12 ] = F_105 ( V_128 ,
V_103 ) ;
if ( ! V_18 -> V_96 [ V_12 ] )
goto V_153;
F_106 ( V_18 -> V_91 [ V_12 ] , V_15 ,
F_107 ( V_15 ,
V_122 -> V_161 ) ,
V_18 -> V_96 [ V_12 ] , V_128 ,
V_3 -> type -> V_163 ,
V_18 ) ;
}
V_18 -> V_164 = V_18 -> V_91 [ 0 ] ;
V_18 -> V_165 = V_18 -> V_96 [ 0 ] ;
}
for ( V_11 = 0 ; V_11 < V_132 ; ++ V_11 ) {
V_122 = V_127 [ V_11 ] ;
V_18 = V_3 -> V_18 [ V_11 ] ;
if ( F_108 ( & V_18 -> V_98 , V_166 , V_103 ) )
goto V_153;
V_128 = V_3 -> type -> V_167 ;
if ( ! V_128 )
V_128 = F_102 ( V_122 ) ;
V_18 -> V_167 = V_128 ;
V_18 -> V_168 = V_122 -> V_161 ;
for ( V_12 = 0 ; V_12 < F_60 ( V_18 -> V_92 ) ; ++ V_12 ) {
F_103 ( V_12 , & V_18 -> V_169 ) ;
V_18 -> V_92 [ V_12 ] = F_104 ( 0 , V_103 ) ;
if ( ! V_18 -> V_92 [ V_12 ] )
goto V_153;
V_18 -> V_97 [ V_12 ] = F_105 ( V_128 ,
V_103 ) ;
if ( ! V_18 -> V_97 [ V_12 ] )
goto V_153;
F_106 ( V_18 -> V_92 [ V_12 ] , V_15 ,
F_109 ( V_15 ,
V_122 -> V_161 ) ,
V_18 -> V_97 [ V_12 ] , V_128 ,
V_3 -> type -> V_170 ,
V_18 ) ;
}
V_18 -> V_171 = V_18 -> V_92 [ 0 ] ;
V_18 -> V_172 = V_18 -> V_97 [ 0 ] ;
}
if ( V_3 -> type -> V_173 ) {
for ( V_11 = 0 ; V_11 < V_129 ; ++ V_11 ) {
V_122 = V_123 [ V_11 ] ;
V_18 = V_3 -> V_18 [ V_11 ] ;
V_18 -> V_93 = F_104 ( 0 , V_103 ) ;
if ( ! V_18 -> V_93 )
goto V_153;
V_128 = F_102 ( V_122 ) ;
V_18 -> V_174 =
V_122 -> V_161 ;
V_18 -> V_99 = F_105 ( V_128 ,
V_103 ) ;
if ( ! V_18 -> V_99 )
goto V_153;
F_110 ( V_18 -> V_93 , V_15 ,
F_111 ( V_15 ,
V_122 -> V_161 ) ,
V_18 -> V_99 , V_128 ,
V_3 -> type -> V_173 , V_18 ,
V_122 -> V_175 ) ;
}
} else if ( V_129 ) {
F_6 ( V_118 , L_30 ) ;
}
if ( V_3 -> type -> V_176 ) {
for ( V_11 = 0 ; V_11 < V_130 ; ++ V_11 ) {
V_122 = V_125 [ V_11 ] ;
V_18 = V_3 -> V_18 [ V_11 ] ;
V_18 -> V_94 = F_104 ( 0 , V_103 ) ;
if ( ! V_18 -> V_94 )
goto V_153;
V_128 = F_102 ( V_122 ) ;
V_18 -> V_177 = V_128 ;
V_18 -> V_178 =
V_122 -> V_161 ;
V_18 -> V_100 = F_105 ( V_128 ,
V_103 ) ;
if ( ! V_18 -> V_100 )
goto V_153;
F_110 ( V_18 -> V_94 , V_15 ,
F_112 ( V_15 ,
V_122 -> V_161 ) ,
V_18 -> V_100 , V_128 ,
V_3 -> type -> V_176 , V_18 ,
V_122 -> V_175 ) ;
}
} else if ( V_130 ) {
F_6 ( V_118 , L_31 ) ;
}
F_113 ( V_14 , V_3 ) ;
if ( type -> V_179 ) {
V_30 = type -> V_179 ( V_3 ) ;
if ( V_30 < 0 )
goto V_153;
V_3 -> V_22 = 1 ;
if ( V_30 > 0 ) {
V_3 -> V_9 = 0 ;
goto exit;
}
} else {
V_3 -> V_22 = 1 ;
}
V_3 -> V_7 = 1 ;
if ( F_5 ( V_3 , V_9 , & V_10 ) == NULL ) {
F_88 ( V_118 , L_32 ) ;
goto V_153;
}
V_3 -> V_10 = V_10 ;
for ( V_11 = 0 ; V_11 < V_9 ; ++ V_11 ) {
V_18 = V_3 -> V_18 [ V_11 ] ;
F_114 ( & V_18 -> V_15 , L_33 , V_18 -> V_19 ) ;
F_6 ( V_118 , L_34 , F_115 ( & V_18 -> V_15 ) ) ;
F_116 ( & V_18 -> V_15 ) ;
V_30 = F_117 ( & V_18 -> V_15 ) ;
if ( V_30 )
F_88 ( V_118 , L_35 ) ;
}
V_3 -> V_7 = 0 ;
F_118 ( V_10 ) ;
exit:
F_21 ( type -> V_26 . V_33 ) ;
return 0 ;
V_153:
F_14 ( V_3 ) ;
F_21 ( type -> V_26 . V_33 ) ;
return - V_134 ;
}
static void F_119 ( struct V_102 * V_14 )
{
int V_11 ;
struct V_1 * V_3 = F_120 ( V_14 ) ;
struct V_95 * V_15 = & V_14 -> V_15 ;
struct V_20 * V_18 ;
F_121 ( V_3 ) ;
F_2 ( & V_3 -> V_6 ) ;
V_3 -> V_7 = 1 ;
F_3 ( & V_3 -> V_6 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_18 = V_3 -> V_18 [ V_11 ] ;
if ( V_18 ) {
struct V_27 * V_28 = F_122 ( & V_18 -> V_18 ) ;
if ( V_28 ) {
F_123 ( V_28 ) ;
F_124 ( V_28 ) ;
}
F_59 ( V_18 ) ;
F_125 ( & V_18 -> V_18 . V_180 ) ;
F_126 ( & V_18 -> V_89 ) ;
if ( F_127 ( & V_18 -> V_15 ) )
F_128 ( & V_18 -> V_15 ) ;
}
}
if ( V_3 -> type -> V_181 )
V_3 -> type -> V_181 ( V_3 ) ;
F_14 ( V_3 ) ;
F_94 ( V_15 , L_36 ) ;
}
int F_129 ( struct V_102 * V_105 , T_1 V_182 )
{
struct V_1 * V_3 = F_120 ( V_105 ) ;
struct V_20 * V_18 ;
int V_11 , V_183 = 0 ;
V_3 -> V_184 = 1 ;
if ( V_3 -> type -> V_185 ) {
V_183 = V_3 -> type -> V_185 ( V_3 , V_182 ) ;
if ( V_183 < 0 ) {
V_3 -> V_184 = 0 ;
goto V_186;
}
}
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_18 = V_3 -> V_18 [ V_11 ] ;
if ( V_18 )
F_59 ( V_18 ) ;
}
V_186:
return V_183 ;
}
static void F_130 ( struct V_1 * V_3 )
{
struct V_20 * V_18 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_18 = V_3 -> V_18 [ V_11 ] ;
if ( V_18 )
F_62 ( V_18 ) ;
}
}
int F_131 ( struct V_102 * V_105 )
{
struct V_1 * V_3 = F_120 ( V_105 ) ;
int V_187 ;
F_130 ( V_3 ) ;
V_3 -> V_184 = 0 ;
if ( V_3 -> type -> V_188 )
V_187 = V_3 -> type -> V_188 ( V_3 ) ;
else
V_187 = F_132 ( V_3 ) ;
return V_187 ;
}
static int F_133 ( struct V_102 * V_105 )
{
struct V_1 * V_3 = F_120 ( V_105 ) ;
int V_187 ;
F_130 ( V_3 ) ;
V_3 -> V_184 = 0 ;
if ( V_3 -> type -> V_189 )
V_187 = V_3 -> type -> V_189 ( V_3 ) ;
else {
V_187 = - V_190 ;
V_105 -> V_191 = 1 ;
}
return V_187 ;
}
static int T_2 F_134 ( void )
{
int V_11 ;
int V_192 ;
V_193 = F_135 ( V_17 ) ;
if ( ! V_193 )
return - V_135 ;
for ( V_11 = 0 ; V_11 < V_17 ; ++ V_11 )
V_5 [ V_11 ] = NULL ;
V_192 = F_136 ( & V_158 ) ;
if ( V_192 ) {
F_137 ( L_37 , V_16 ) ;
goto V_194;
}
V_193 -> V_195 = L_38 ;
V_193 -> V_196 = L_39 ;
V_193 -> V_197 = V_198 ;
V_193 -> V_199 = 0 ;
V_193 -> type = V_200 ;
V_193 -> V_201 = V_202 ;
V_193 -> V_203 = V_204 |
V_205 ;
V_193 -> V_37 = V_206 ;
V_193 -> V_37 . V_207 = V_208 | V_209 | V_210
| V_211 | V_212 ;
V_193 -> V_37 . V_213 = 9600 ;
V_193 -> V_37 . V_214 = 9600 ;
F_138 ( V_193 , & V_215 ) ;
V_192 = F_139 ( V_193 ) ;
if ( V_192 ) {
F_137 ( L_40 , V_16 ) ;
goto V_216;
}
V_192 = F_140 ( & V_44 ) ;
if ( V_192 < 0 ) {
F_137 ( L_41 , V_16 ) ;
goto V_217;
}
V_192 = F_141 () ;
if ( V_192 < 0 ) {
F_137 ( L_42 , V_16 ) ;
goto V_218;
}
return V_192 ;
V_218:
F_142 ( & V_44 ) ;
V_217:
F_143 ( V_193 ) ;
V_216:
F_144 ( & V_158 ) ;
V_194:
F_137 ( L_43 , V_16 , V_192 ) ;
F_145 ( V_193 ) ;
return V_192 ;
}
static void T_3 F_146 ( void )
{
F_147 () ;
F_148 () ;
F_142 ( & V_44 ) ;
F_143 ( V_193 ) ;
F_145 ( V_193 ) ;
F_144 ( & V_158 ) ;
}
static void F_149 ( struct V_44 * V_95 )
{
F_150 ( V_95 , V_41 ) ;
F_150 ( V_95 , V_53 ) ;
F_150 ( V_95 , V_46 ) ;
F_150 ( V_95 , V_54 ) ;
F_150 ( V_95 , V_55 ) ;
if ( V_95 -> V_219 )
F_150 ( V_95 , V_57 ) ;
F_150 ( V_95 , V_163 ) ;
F_150 ( V_95 , V_170 ) ;
F_150 ( V_95 , V_220 ) ;
F_150 ( V_95 , V_221 ) ;
}
static int F_151 ( struct V_44 * V_26 )
{
int V_30 ;
if ( F_152 () )
return - V_31 ;
if ( ! V_26 -> V_76 )
V_26 -> V_76 = V_26 -> V_26 . V_196 ;
if ( ! V_26 -> V_113 ) {
F_153 ( 1 , L_44 ,
V_26 -> V_76 ) ;
return - V_82 ;
}
F_149 ( V_26 ) ;
F_2 ( & V_4 ) ;
F_154 ( & V_26 -> V_222 , & V_223 ) ;
V_30 = F_155 ( V_26 ) ;
if ( V_30 ) {
F_137 ( L_45 , V_30 , V_26 -> V_76 ) ;
F_156 ( & V_26 -> V_222 ) ;
} else
F_157 ( L_46 , V_26 -> V_76 ) ;
F_3 ( & V_4 ) ;
return V_30 ;
}
static void F_158 ( struct V_44 * V_95 )
{
F_157 ( L_47 , V_95 -> V_76 ) ;
F_2 ( & V_4 ) ;
F_156 ( & V_95 -> V_222 ) ;
F_159 ( V_95 ) ;
F_3 ( & V_4 ) ;
}
int F_160 ( struct V_44 * const V_224 [] ,
const char * V_196 ,
const struct V_104 * V_111 )
{
int V_225 ;
struct V_113 * V_226 ;
struct V_44 * const * V_227 ;
V_226 = F_70 ( sizeof( * V_226 ) , V_103 ) ;
if ( ! V_226 )
return - V_135 ;
V_226 -> V_196 = V_196 ;
V_226 -> V_228 = 1 ;
V_226 -> V_229 = 1 ;
V_226 -> V_185 = F_129 ;
V_226 -> V_188 = F_131 ;
V_226 -> V_136 = F_86 ;
V_226 -> V_181 = F_119 ;
for ( V_227 = V_224 ; * V_227 ; ++ V_227 ) {
if ( ( * V_227 ) -> V_189 ) {
V_226 -> V_189 = F_133 ;
break;
}
}
V_225 = F_140 ( V_226 ) ;
if ( V_225 )
return V_225 ;
for ( V_227 = V_224 ; * V_227 ; ++ V_227 ) {
( * V_227 ) -> V_113 = V_226 ;
V_225 = F_151 ( * V_227 ) ;
if ( V_225 )
goto V_230;
}
V_226 -> V_111 = V_111 ;
V_225 = F_161 ( & V_226 -> V_231 . V_26 ) ;
return 0 ;
V_230:
while ( V_227 -- > V_224 )
F_158 ( * V_227 ) ;
F_142 ( V_226 ) ;
return V_225 ;
}
void F_162 ( struct V_44 * const V_224 [] )
{
struct V_113 * V_226 = ( * V_224 ) -> V_113 ;
for (; * V_224 ; ++ V_224 )
F_158 ( * V_224 ) ;
F_142 ( V_226 ) ;
F_13 ( V_226 ) ;
}
