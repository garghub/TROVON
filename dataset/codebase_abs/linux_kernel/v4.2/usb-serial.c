struct V_1 * F_1 ( unsigned V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
F_2 ( & V_6 ) ;
V_5 = F_3 ( & V_7 , V_2 ) ;
if ( ! V_5 )
goto exit;
V_4 = V_5 -> V_4 ;
F_2 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_9 ) {
F_4 ( & V_4 -> V_8 ) ;
V_5 = NULL ;
} else {
F_5 ( & V_4 -> V_10 ) ;
}
exit:
F_4 ( & V_6 ) ;
return V_5 ;
}
static int F_6 ( struct V_3 * V_4 , int V_11 )
{
struct V_1 * V_5 ;
unsigned int V_12 , V_13 ;
int V_2 ;
F_7 ( & V_4 -> V_14 -> V_15 , L_1 , V_16 , V_11 ) ;
F_2 ( & V_6 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; ++ V_12 ) {
V_5 = V_4 -> V_5 [ V_12 ] ;
V_2 = F_8 ( & V_7 , V_5 , 0 , 0 , V_17 ) ;
if ( V_2 < 0 )
goto error;
V_5 -> V_2 = V_2 ;
V_5 -> V_18 = V_12 ;
}
V_4 -> V_19 = 1 ;
F_4 ( & V_6 ) ;
return 0 ;
error:
for ( V_13 = 0 ; V_13 < V_12 ; ++ V_13 )
F_9 ( & V_7 , V_4 -> V_5 [ V_13 ] -> V_2 ) ;
F_4 ( & V_6 ) ;
return V_2 ;
}
static void F_10 ( struct V_3 * V_4 )
{
int V_12 ;
F_2 ( & V_6 ) ;
for ( V_12 = 0 ; V_12 < V_4 -> V_11 ; ++ V_12 )
F_9 ( & V_7 , V_4 -> V_5 [ V_12 ] -> V_2 ) ;
F_4 ( & V_6 ) ;
V_4 -> V_19 = 0 ;
}
static void F_11 ( struct V_10 * V_10 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
int V_12 ;
V_4 = F_12 ( V_10 ) ;
if ( V_4 -> V_19 )
F_10 ( V_4 ) ;
if ( V_4 -> V_20 && V_4 -> type -> V_21 )
V_4 -> type -> V_21 ( V_4 ) ;
for ( V_12 = 0 ; V_12 < V_4 -> V_22 ; ++ V_12 ) {
V_5 = V_4 -> V_5 [ V_12 ] ;
if ( V_5 ) {
V_5 -> V_4 = NULL ;
F_13 ( & V_5 -> V_15 ) ;
}
}
F_14 ( V_4 -> V_14 ) ;
F_15 ( V_4 -> V_15 ) ;
F_16 ( V_4 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_18 ( & V_4 -> V_10 , F_11 ) ;
}
static int F_19 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
int V_27 = V_26 -> V_28 ;
struct V_3 * V_4 ;
struct V_1 * V_5 ;
int V_29 = - V_30 ;
V_5 = F_1 ( V_27 ) ;
if ( ! V_5 )
return V_29 ;
V_4 = V_5 -> V_4 ;
if ( ! F_20 ( V_4 -> type -> V_24 . V_31 ) )
goto V_32;
V_29 = F_21 ( V_4 -> V_14 ) ;
if ( V_29 )
goto V_33;
V_29 = F_22 ( & V_5 -> V_5 , V_24 , V_26 ) ;
if ( V_29 )
goto V_34;
F_4 ( & V_4 -> V_8 ) ;
if ( V_4 -> type -> V_35 )
V_4 -> type -> V_35 ( V_26 ) ;
V_26 -> V_36 = V_5 ;
return V_29 ;
V_34:
F_23 ( V_4 -> V_14 ) ;
V_33:
F_24 ( V_4 -> type -> V_24 . V_31 ) ;
V_32:
F_17 ( V_4 ) ;
F_4 ( & V_4 -> V_8 ) ;
return V_29 ;
}
static int F_25 ( struct V_37 * V_38 , struct V_25 * V_26 )
{
struct V_1 * V_5 =
F_26 ( V_38 , struct V_1 , V_5 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
int V_29 ;
F_2 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_9 )
V_29 = - V_30 ;
else
V_29 = V_5 -> V_4 -> type -> V_39 ( V_26 , V_5 ) ;
F_4 ( & V_4 -> V_8 ) ;
if ( V_29 < 0 )
V_29 = F_27 ( V_29 ) ;
return V_29 ;
}
static int F_28 ( struct V_25 * V_26 , struct V_40 * V_41 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
return F_29 ( & V_5 -> V_5 , V_26 , V_41 ) ;
}
static void F_30 ( struct V_37 * V_38 )
{
struct V_1 * V_5 =
F_26 ( V_38 , struct V_1 , V_5 ) ;
struct V_42 * V_43 = V_5 -> V_4 -> type ;
if ( V_43 -> V_44 )
V_43 -> V_44 ( V_5 ) ;
}
static void F_31 ( struct V_25 * V_26 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
F_32 ( & V_5 -> V_5 ) ;
}
static void F_33 ( struct V_25 * V_26 , struct V_40 * V_41 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
F_34 ( & V_5 -> V_5 , V_26 , V_41 ) ;
}
static void F_35 ( struct V_25 * V_26 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
struct V_3 * V_4 ;
struct V_45 * V_31 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( V_5 -> V_5 . V_46 )
return;
V_26 -> V_36 = NULL ;
V_4 = V_5 -> V_4 ;
V_31 = V_4 -> type -> V_24 . V_31 ;
F_2 ( & V_4 -> V_8 ) ;
if ( ! V_4 -> V_9 )
F_23 ( V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_17 ( V_4 ) ;
F_24 ( V_31 ) ;
}
static int F_36 ( struct V_25 * V_26 , const unsigned char * V_47 ,
int V_48 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
int V_29 = - V_30 ;
if ( V_5 -> V_4 -> V_15 -> V_49 == V_50 )
goto exit;
F_7 ( V_26 -> V_15 , L_3 , V_16 , V_48 ) ;
V_29 = V_5 -> V_4 -> type -> V_51 ( V_26 , V_5 , V_47 , V_48 ) ;
if ( V_29 < 0 )
V_29 = F_27 ( V_29 ) ;
exit:
return V_29 ;
}
static int F_37 ( struct V_25 * V_26 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
return V_5 -> V_4 -> type -> V_52 ( V_26 ) ;
}
static int F_38 ( struct V_25 * V_26 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
struct V_3 * V_4 = V_5 -> V_4 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( V_4 -> V_9 )
return 0 ;
return V_4 -> type -> V_53 ( V_26 ) ;
}
static void F_39 ( struct V_25 * V_26 , int V_54 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
struct V_3 * V_4 = V_5 -> V_4 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( ! V_5 -> V_4 -> type -> V_55 )
return;
F_2 ( & V_4 -> V_8 ) ;
if ( ! V_4 -> V_9 )
V_5 -> V_4 -> type -> V_55 ( V_26 , V_54 ) ;
F_4 ( & V_4 -> V_8 ) ;
}
static void F_40 ( struct V_25 * V_26 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( V_5 -> V_4 -> type -> V_56 )
V_5 -> V_4 -> type -> V_56 ( V_26 ) ;
}
static void F_41 ( struct V_25 * V_26 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( V_5 -> V_4 -> type -> V_57 )
V_5 -> V_4 -> type -> V_57 ( V_26 ) ;
}
static int F_42 ( struct V_25 * V_26 ,
unsigned int V_58 , unsigned long V_59 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
int V_29 = - V_60 ;
F_7 ( V_26 -> V_15 , L_4 , V_16 , V_58 ) ;
switch ( V_58 ) {
case V_61 :
if ( V_5 -> V_4 -> type -> V_62 )
V_29 = V_5 -> V_4 -> type -> V_62 ( V_26 , V_59 ) ;
break;
default:
if ( V_5 -> V_4 -> type -> V_63 )
V_29 = V_5 -> V_4 -> type -> V_63 ( V_26 , V_58 , V_59 ) ;
}
return V_29 ;
}
static void F_43 ( struct V_25 * V_26 , struct V_64 * V_65 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( V_5 -> V_4 -> type -> V_66 )
V_5 -> V_4 -> type -> V_66 ( V_26 , V_5 , V_65 ) ;
else
F_44 ( & V_26 -> V_67 , V_65 ) ;
}
static int F_45 ( struct V_25 * V_26 , int V_68 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( V_5 -> V_4 -> type -> V_69 )
V_5 -> V_4 -> type -> V_69 ( V_26 , V_68 ) ;
return 0 ;
}
static int F_46 ( struct V_70 * V_71 , void * V_72 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
int V_12 ;
char V_73 [ 40 ] ;
F_47 ( V_71 , L_5 ) ;
for ( V_12 = 0 ; V_12 < V_74 ; ++ V_12 ) {
V_5 = F_1 ( V_12 ) ;
if ( V_5 == NULL )
continue;
V_4 = V_5 -> V_4 ;
F_48 ( V_71 , L_6 , V_12 ) ;
if ( V_4 -> type -> V_24 . V_31 )
F_48 ( V_71 , L_7 ,
F_49 ( V_4 -> type -> V_24 . V_31 ) ) ;
F_48 ( V_71 , L_8 ,
V_4 -> type -> V_75 ) ;
F_48 ( V_71 , L_9 ,
F_50 ( V_4 -> V_15 -> V_76 . V_77 ) ,
F_50 ( V_4 -> V_15 -> V_76 . V_78 ) ) ;
F_48 ( V_71 , L_10 , V_4 -> V_11 ) ;
F_48 ( V_71 , L_11 , V_5 -> V_18 ) ;
F_51 ( V_4 -> V_15 , V_73 , sizeof( V_73 ) ) ;
F_48 ( V_71 , L_12 , V_73 ) ;
F_52 ( V_71 , '\n' ) ;
F_17 ( V_4 ) ;
F_4 ( & V_4 -> V_8 ) ;
}
return 0 ;
}
static int F_53 ( struct V_79 * V_79 , struct V_40 * V_40 )
{
return F_54 ( V_40 , F_46 , NULL ) ;
}
static int F_55 ( struct V_25 * V_26 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( V_5 -> V_4 -> type -> V_80 )
return V_5 -> V_4 -> type -> V_80 ( V_26 ) ;
return - V_81 ;
}
static int F_56 ( struct V_25 * V_26 ,
unsigned int V_82 , unsigned int V_83 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( V_5 -> V_4 -> type -> V_84 )
return V_5 -> V_4 -> type -> V_84 ( V_26 , V_82 , V_83 ) ;
return - V_81 ;
}
static int F_57 ( struct V_25 * V_26 ,
struct V_85 * V_86 )
{
struct V_1 * V_5 = V_26 -> V_36 ;
F_7 ( V_26 -> V_15 , L_2 , V_16 ) ;
if ( V_5 -> V_4 -> type -> V_87 )
return V_5 -> V_4 -> type -> V_87 ( V_26 , V_86 ) ;
return - V_81 ;
}
void F_58 ( struct V_1 * V_5 )
{
F_59 ( & V_5 -> V_88 ) ;
}
static void F_60 ( struct V_89 * V_88 )
{
struct V_1 * V_5 =
F_26 ( V_88 , struct V_1 , V_88 ) ;
F_61 ( & V_5 -> V_5 ) ;
}
static void F_62 ( struct V_1 * V_5 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_63 ( V_5 -> V_90 ) ; ++ V_12 )
F_64 ( V_5 -> V_90 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < F_63 ( V_5 -> V_91 ) ; ++ V_12 )
F_64 ( V_5 -> V_91 [ V_12 ] ) ;
F_64 ( V_5 -> V_92 ) ;
F_64 ( V_5 -> V_93 ) ;
}
static void F_65 ( struct V_1 * V_5 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_63 ( V_5 -> V_90 ) ; ++ V_12 )
F_66 ( V_5 -> V_90 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < F_63 ( V_5 -> V_91 ) ; ++ V_12 )
F_66 ( V_5 -> V_91 [ V_12 ] ) ;
F_66 ( V_5 -> V_92 ) ;
F_66 ( V_5 -> V_93 ) ;
}
static void F_67 ( struct V_94 * V_15 )
{
struct V_1 * V_5 = F_68 ( V_15 ) ;
int V_12 ;
F_7 ( V_15 , L_2 , V_16 ) ;
F_69 ( V_5 -> V_92 ) ;
F_69 ( V_5 -> V_93 ) ;
for ( V_12 = 0 ; V_12 < F_63 ( V_5 -> V_90 ) ; ++ V_12 ) {
F_69 ( V_5 -> V_90 [ V_12 ] ) ;
F_16 ( V_5 -> V_95 [ V_12 ] ) ;
}
for ( V_12 = 0 ; V_12 < F_63 ( V_5 -> V_91 ) ; ++ V_12 ) {
F_69 ( V_5 -> V_91 [ V_12 ] ) ;
F_16 ( V_5 -> V_96 [ V_12 ] ) ;
}
F_70 ( & V_5 -> V_97 ) ;
F_16 ( V_5 -> V_98 ) ;
F_16 ( V_5 -> V_99 ) ;
F_71 ( & V_5 -> V_5 ) ;
F_16 ( V_5 ) ;
}
static struct V_3 * F_72 ( struct V_100 * V_15 ,
struct V_101 * V_14 ,
struct V_42 * V_24 )
{
struct V_3 * V_4 ;
V_4 = F_73 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_15 = F_74 ( V_15 ) ;
V_4 -> type = V_24 ;
V_4 -> V_14 = F_75 ( V_14 ) ;
F_76 ( & V_4 -> V_10 ) ;
F_77 ( & V_4 -> V_8 ) ;
V_4 -> V_19 = 0 ;
return V_4 ;
}
static const struct V_102 * F_78 ( struct V_101 * V_103 ,
struct V_42 * V_43 )
{
struct V_104 * V_105 ;
F_79 ( & V_43 -> V_106 . V_107 ) ;
F_80 (dynid, &drv->dynids.list, node) {
if ( F_81 ( V_103 , & V_105 -> V_108 ) ) {
F_82 ( & V_43 -> V_106 . V_107 ) ;
return & V_105 -> V_108 ;
}
}
F_82 ( & V_43 -> V_106 . V_107 ) ;
return NULL ;
}
static const struct V_102 * F_83 ( struct V_42 * V_43 ,
struct V_101 * V_103 )
{
const struct V_102 * V_108 ;
V_108 = F_84 ( V_103 , V_43 -> V_109 ) ;
if ( V_108 ) {
F_7 ( & V_103 -> V_15 , L_13 ) ;
goto exit;
}
V_108 = F_78 ( V_103 , V_43 ) ;
if ( V_108 )
F_7 ( & V_103 -> V_15 , L_14 ) ;
exit:
return V_108 ;
}
static struct V_42 * F_85 (
struct V_101 * V_110 )
{
const struct V_102 * V_108 = NULL ;
struct V_42 * V_43 ;
struct V_111 * V_24 = F_86 ( V_110 -> V_15 . V_24 ) ;
F_80 (drv, &usb_serial_driver_list, driver_list) {
if ( V_43 -> V_111 == V_24 )
V_108 = F_83 ( V_43 , V_110 ) ;
if ( V_108 )
return V_43 ;
}
return NULL ;
}
static int F_87 ( struct V_37 * V_5 )
{
struct V_1 * V_112 = F_26 ( V_5 , struct V_1 , V_5 ) ;
struct V_42 * V_43 = V_112 -> V_4 -> type ;
if ( V_43 -> V_113 )
return V_43 -> V_113 ( V_112 ) ;
return 1 ;
}
static void F_88 ( struct V_37 * V_5 , int V_114 )
{
struct V_1 * V_112 = F_26 ( V_5 , struct V_1 , V_5 ) ;
struct V_42 * V_43 = V_112 -> V_4 -> type ;
if ( V_43 -> V_115 )
V_43 -> V_115 ( V_112 , V_114 ) ;
}
static T_1 F_89 ( struct V_94 * V_15 ,
struct V_116 * V_117 , char * V_47 )
{
struct V_1 * V_5 = F_68 ( V_15 ) ;
return sprintf ( V_47 , L_15 , V_5 -> V_18 ) ;
}
static int F_90 ( struct V_101 * V_14 ,
const struct V_102 * V_108 )
{
struct V_94 * V_118 = & V_14 -> V_15 ;
struct V_100 * V_15 = F_91 ( V_14 ) ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_5 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_121 * V_123 [ V_124 ] ;
struct V_121 * V_125 [ V_124 ] ;
struct V_121 * V_126 [ V_124 ] ;
struct V_121 * V_127 [ V_124 ] ;
struct V_42 * type = NULL ;
int V_29 ;
int V_128 ;
int V_12 ;
int V_13 ;
int V_129 = 0 ;
int V_130 = 0 ;
int V_131 = 0 ;
int V_132 = 0 ;
int V_11 = 0 ;
int V_133 ;
F_2 ( & V_6 ) ;
type = F_85 ( V_14 ) ;
if ( ! type ) {
F_4 ( & V_6 ) ;
F_7 ( V_118 , L_16 ) ;
return - V_30 ;
}
if ( ! F_20 ( type -> V_24 . V_31 ) ) {
F_4 ( & V_6 ) ;
F_92 ( V_118 , L_17 ) ;
return - V_134 ;
}
F_4 ( & V_6 ) ;
V_4 = F_72 ( V_15 , V_14 , type ) ;
if ( ! V_4 ) {
F_24 ( type -> V_24 . V_31 ) ;
return - V_135 ;
}
if ( type -> V_136 ) {
const struct V_102 * V_108 ;
V_108 = F_83 ( type , V_14 ) ;
V_29 = type -> V_136 ( V_4 , V_108 ) ;
if ( V_29 ) {
F_7 ( V_118 , L_18 ) ;
F_17 ( V_4 ) ;
F_24 ( type -> V_24 . V_31 ) ;
return V_29 ;
}
}
V_120 = V_14 -> V_137 ;
for ( V_12 = 0 ; V_12 < V_120 -> V_138 . V_139 ; ++ V_12 ) {
V_122 = & V_120 -> V_122 [ V_12 ] . V_138 ;
if ( F_93 ( V_122 ) ) {
F_7 ( V_118 , L_19 , V_12 ) ;
if ( V_131 < V_124 ) {
V_126 [ V_131 ] = V_122 ;
++ V_131 ;
}
}
if ( F_94 ( V_122 ) ) {
F_7 ( V_118 , L_20 , V_12 ) ;
if ( V_132 < V_124 ) {
V_127 [ V_132 ] = V_122 ;
++ V_132 ;
}
}
if ( F_95 ( V_122 ) ) {
F_7 ( V_118 , L_21 , V_12 ) ;
if ( V_129 < V_124 ) {
V_123 [ V_129 ] =
V_122 ;
++ V_129 ;
}
}
if ( F_96 ( V_122 ) ) {
F_7 ( V_118 , L_22 , V_12 ) ;
if ( V_130 < V_124 ) {
V_125 [ V_130 ] =
V_122 ;
++ V_130 ;
}
}
}
#if F_97 ( V_140 ) || F_97 ( V_141 )
if ( ( ( F_50 ( V_15 -> V_76 . V_77 ) == V_142 ) &&
( F_50 ( V_15 -> V_76 . V_78 ) == V_143 ) ) ||
( ( F_50 ( V_15 -> V_76 . V_77 ) == V_144 ) &&
( F_50 ( V_15 -> V_76 . V_78 ) == V_145 ) ) ||
( ( F_50 ( V_15 -> V_76 . V_77 ) == V_146 ) &&
( F_50 ( V_15 -> V_76 . V_78 ) == V_147 ) ) ||
( ( F_50 ( V_15 -> V_76 . V_77 ) == V_148 ) &&
( F_50 ( V_15 -> V_76 . V_78 ) == V_149 ) ) ) {
if ( V_14 != V_15 -> V_150 -> V_14 [ 0 ] ) {
V_120 = V_15 -> V_150 -> V_14 [ 0 ] -> V_137 ;
for ( V_12 = 0 ; V_12 < V_120 -> V_138 . V_139 ; ++ V_12 ) {
V_122 = & V_120 -> V_122 [ V_12 ] . V_138 ;
if ( F_95 ( V_122 ) ) {
F_7 ( V_118 , L_23 ) ;
if ( V_129 < V_124 ) {
V_123 [ V_129 ] = V_122 ;
++ V_129 ;
}
}
}
}
if ( V_131 == 0 || V_132 == 0 ) {
F_98 ( V_118 , L_24 ) ;
F_17 ( V_4 ) ;
F_24 ( type -> V_24 . V_31 ) ;
return - V_30 ;
}
}
#endif
#ifdef F_99
if ( type == & V_151 ) {
V_11 = V_132 ;
if ( V_11 == 0 ) {
F_92 ( V_118 , L_25 ) ;
F_17 ( V_4 ) ;
F_24 ( type -> V_24 . V_31 ) ;
return - V_134 ;
}
F_98 ( V_118 , L_26 ) ;
F_98 ( V_118 , L_27 ) ;
}
#endif
if ( ! V_11 ) {
if ( type -> V_152 )
V_11 = type -> V_152 ( V_4 ) ;
if ( ! V_11 )
V_11 = type -> V_11 ;
}
if ( V_11 > V_124 ) {
F_100 ( V_118 , L_28 , V_11 ) ;
V_11 = V_124 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_131 = V_131 ;
V_4 -> V_132 = V_132 ;
V_4 -> V_129 = V_129 ;
V_4 -> V_130 = V_130 ;
F_98 ( V_118 , L_29 , type -> V_75 ) ;
V_133 = F_101 ( V_131 , V_132 ) ;
V_133 = F_101 ( V_133 , V_129 ) ;
V_133 = F_101 ( V_133 , V_130 ) ;
V_133 = F_101 ( V_133 , ( int ) V_4 -> V_11 ) ;
V_4 -> V_22 = V_133 ;
F_7 ( V_118 , L_30 , V_133 ) ;
for ( V_12 = 0 ; V_12 < V_133 ; ++ V_12 ) {
V_5 = F_73 ( sizeof( struct V_1 ) , V_17 ) ;
if ( ! V_5 )
goto V_153;
F_102 ( & V_5 -> V_5 ) ;
V_5 -> V_5 . V_154 = & V_155 ;
V_5 -> V_4 = V_4 ;
F_103 ( & V_5 -> V_107 ) ;
F_104 ( & V_5 -> V_88 , F_60 ) ;
V_4 -> V_5 [ V_12 ] = V_5 ;
V_5 -> V_15 . V_156 = & V_14 -> V_15 ;
V_5 -> V_15 . V_24 = NULL ;
V_5 -> V_15 . V_157 = & V_158 ;
V_5 -> V_15 . V_21 = & F_67 ;
V_5 -> V_15 . V_159 = V_160 ;
F_105 ( & V_5 -> V_15 ) ;
}
for ( V_12 = 0 ; V_12 < V_131 ; ++ V_12 ) {
V_122 = V_126 [ V_12 ] ;
V_5 = V_4 -> V_5 [ V_12 ] ;
V_128 = F_106 ( int , V_4 -> type -> V_161 ,
F_107 ( V_122 ) ) ;
V_5 -> V_161 = V_128 ;
V_5 -> V_162 = V_122 -> V_163 ;
for ( V_13 = 0 ; V_13 < F_63 ( V_5 -> V_90 ) ; ++ V_13 ) {
F_108 ( V_13 , & V_5 -> V_164 ) ;
V_5 -> V_90 [ V_13 ] = F_109 ( 0 , V_17 ) ;
if ( ! V_5 -> V_90 [ V_13 ] )
goto V_153;
V_5 -> V_95 [ V_13 ] = F_110 ( V_128 ,
V_17 ) ;
if ( ! V_5 -> V_95 [ V_13 ] )
goto V_153;
F_111 ( V_5 -> V_90 [ V_13 ] , V_15 ,
F_112 ( V_15 ,
V_122 -> V_163 ) ,
V_5 -> V_95 [ V_13 ] , V_128 ,
V_4 -> type -> V_165 ,
V_5 ) ;
}
V_5 -> V_166 = V_5 -> V_90 [ 0 ] ;
V_5 -> V_167 = V_5 -> V_95 [ 0 ] ;
}
for ( V_12 = 0 ; V_12 < V_132 ; ++ V_12 ) {
V_122 = V_127 [ V_12 ] ;
V_5 = V_4 -> V_5 [ V_12 ] ;
if ( F_113 ( & V_5 -> V_97 , V_168 , V_17 ) )
goto V_153;
V_128 = V_4 -> type -> V_169 ;
if ( ! V_128 )
V_128 = F_107 ( V_122 ) ;
V_5 -> V_169 = V_128 ;
V_5 -> V_170 = V_122 -> V_163 ;
for ( V_13 = 0 ; V_13 < F_63 ( V_5 -> V_91 ) ; ++ V_13 ) {
F_108 ( V_13 , & V_5 -> V_171 ) ;
V_5 -> V_91 [ V_13 ] = F_109 ( 0 , V_17 ) ;
if ( ! V_5 -> V_91 [ V_13 ] )
goto V_153;
V_5 -> V_96 [ V_13 ] = F_110 ( V_128 ,
V_17 ) ;
if ( ! V_5 -> V_96 [ V_13 ] )
goto V_153;
F_111 ( V_5 -> V_91 [ V_13 ] , V_15 ,
F_114 ( V_15 ,
V_122 -> V_163 ) ,
V_5 -> V_96 [ V_13 ] , V_128 ,
V_4 -> type -> V_172 ,
V_5 ) ;
}
V_5 -> V_173 = V_5 -> V_91 [ 0 ] ;
V_5 -> V_174 = V_5 -> V_96 [ 0 ] ;
}
if ( V_4 -> type -> V_175 ) {
for ( V_12 = 0 ; V_12 < V_129 ; ++ V_12 ) {
V_122 = V_123 [ V_12 ] ;
V_5 = V_4 -> V_5 [ V_12 ] ;
V_5 -> V_92 = F_109 ( 0 , V_17 ) ;
if ( ! V_5 -> V_92 )
goto V_153;
V_128 = F_107 ( V_122 ) ;
V_5 -> V_176 =
V_122 -> V_163 ;
V_5 -> V_98 = F_110 ( V_128 ,
V_17 ) ;
if ( ! V_5 -> V_98 )
goto V_153;
F_115 ( V_5 -> V_92 , V_15 ,
F_116 ( V_15 ,
V_122 -> V_163 ) ,
V_5 -> V_98 , V_128 ,
V_4 -> type -> V_175 , V_5 ,
V_122 -> V_177 ) ;
}
} else if ( V_129 ) {
F_7 ( V_118 , L_31 ) ;
}
if ( V_4 -> type -> V_178 ) {
for ( V_12 = 0 ; V_12 < V_130 ; ++ V_12 ) {
V_122 = V_125 [ V_12 ] ;
V_5 = V_4 -> V_5 [ V_12 ] ;
V_5 -> V_93 = F_109 ( 0 , V_17 ) ;
if ( ! V_5 -> V_93 )
goto V_153;
V_128 = F_107 ( V_122 ) ;
V_5 -> V_179 = V_128 ;
V_5 -> V_180 =
V_122 -> V_163 ;
V_5 -> V_99 = F_110 ( V_128 ,
V_17 ) ;
if ( ! V_5 -> V_99 )
goto V_153;
F_115 ( V_5 -> V_93 , V_15 ,
F_117 ( V_15 ,
V_122 -> V_163 ) ,
V_5 -> V_99 , V_128 ,
V_4 -> type -> V_178 , V_5 ,
V_122 -> V_177 ) ;
}
} else if ( V_130 ) {
F_7 ( V_118 , L_32 ) ;
}
F_118 ( V_14 , V_4 ) ;
if ( type -> V_181 ) {
V_29 = type -> V_181 ( V_4 ) ;
if ( V_29 < 0 )
goto V_153;
V_4 -> V_20 = 1 ;
if ( V_29 > 0 ) {
V_4 -> V_11 = 0 ;
goto exit;
}
} else {
V_4 -> V_20 = 1 ;
}
V_4 -> V_9 = 1 ;
if ( F_6 ( V_4 , V_11 ) ) {
F_92 ( V_118 , L_33 ) ;
goto V_153;
}
for ( V_12 = 0 ; V_12 < V_11 ; ++ V_12 ) {
V_5 = V_4 -> V_5 [ V_12 ] ;
F_119 ( & V_5 -> V_15 , L_34 , V_5 -> V_2 ) ;
F_7 ( V_118 , L_35 , F_120 ( & V_5 -> V_15 ) ) ;
F_121 ( & V_5 -> V_15 ) ;
V_29 = F_122 ( & V_5 -> V_15 ) ;
if ( V_29 )
F_92 ( V_118 , L_36 ) ;
}
V_4 -> V_9 = 0 ;
F_123 ( V_4 -> V_5 [ 0 ] -> V_2 ) ;
exit:
F_24 ( type -> V_24 . V_31 ) ;
return 0 ;
V_153:
F_17 ( V_4 ) ;
F_24 ( type -> V_24 . V_31 ) ;
return - V_134 ;
}
static void F_124 ( struct V_101 * V_14 )
{
int V_12 ;
struct V_3 * V_4 = F_125 ( V_14 ) ;
struct V_94 * V_15 = & V_14 -> V_15 ;
struct V_1 * V_5 ;
struct V_25 * V_26 ;
F_126 ( V_4 ) ;
F_2 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = 1 ;
F_4 ( & V_4 -> V_8 ) ;
for ( V_12 = 0 ; V_12 < V_4 -> V_11 ; ++ V_12 ) {
V_5 = V_4 -> V_5 [ V_12 ] ;
V_26 = F_127 ( & V_5 -> V_5 ) ;
if ( V_26 ) {
F_128 ( V_26 ) ;
F_129 ( V_26 ) ;
}
F_62 ( V_5 ) ;
F_130 ( & V_5 -> V_5 . V_182 ) ;
F_131 ( & V_5 -> V_88 ) ;
if ( F_132 ( & V_5 -> V_15 ) )
F_133 ( & V_5 -> V_15 ) ;
}
if ( V_4 -> type -> V_183 )
V_4 -> type -> V_183 ( V_4 ) ;
F_17 ( V_4 ) ;
F_98 ( V_15 , L_37 ) ;
}
int F_134 ( struct V_101 * V_103 , T_2 V_184 )
{
struct V_3 * V_4 = F_125 ( V_103 ) ;
int V_12 , V_185 = 0 ;
V_4 -> V_186 = 1 ;
if ( V_4 -> type -> V_187 ) {
V_185 = V_4 -> type -> V_187 ( V_4 , V_184 ) ;
if ( V_185 < 0 ) {
V_4 -> V_186 = 0 ;
goto V_188;
}
}
for ( V_12 = 0 ; V_12 < V_4 -> V_11 ; ++ V_12 )
F_62 ( V_4 -> V_5 [ V_12 ] ) ;
V_188:
return V_185 ;
}
static void F_135 ( struct V_3 * V_4 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_11 ; ++ V_12 )
F_65 ( V_4 -> V_5 [ V_12 ] ) ;
}
int F_136 ( struct V_101 * V_103 )
{
struct V_3 * V_4 = F_125 ( V_103 ) ;
int V_189 ;
F_135 ( V_4 ) ;
V_4 -> V_186 = 0 ;
if ( V_4 -> type -> V_190 )
V_189 = V_4 -> type -> V_190 ( V_4 ) ;
else
V_189 = F_137 ( V_4 ) ;
return V_189 ;
}
static int F_138 ( struct V_101 * V_103 )
{
struct V_3 * V_4 = F_125 ( V_103 ) ;
int V_189 ;
F_135 ( V_4 ) ;
V_4 -> V_186 = 0 ;
if ( V_4 -> type -> V_191 ) {
V_189 = V_4 -> type -> V_191 ( V_4 ) ;
} else {
V_189 = - V_192 ;
V_103 -> V_193 = 1 ;
}
return V_189 ;
}
static int T_3 F_139 ( void )
{
int V_194 ;
V_195 = F_140 ( V_74 ) ;
if ( ! V_195 )
return - V_135 ;
V_194 = F_141 ( & V_158 ) ;
if ( V_194 ) {
F_142 ( L_38 , V_16 ) ;
goto V_196;
}
V_195 -> V_197 = L_39 ;
V_195 -> V_198 = L_40 ;
V_195 -> V_199 = V_200 ;
V_195 -> V_201 = 0 ;
V_195 -> type = V_202 ;
V_195 -> V_203 = V_204 ;
V_195 -> V_205 = V_206 |
V_207 ;
V_195 -> V_35 = V_208 ;
V_195 -> V_35 . V_209 = V_210 | V_211 | V_212
| V_213 | V_214 ;
V_195 -> V_35 . V_215 = 9600 ;
V_195 -> V_35 . V_216 = 9600 ;
F_143 ( V_195 , & V_217 ) ;
V_194 = F_144 ( V_195 ) ;
if ( V_194 ) {
F_142 ( L_41 , V_16 ) ;
goto V_218;
}
V_194 = F_145 ( & V_42 ) ;
if ( V_194 < 0 ) {
F_142 ( L_42 , V_16 ) ;
goto V_219;
}
V_194 = F_146 () ;
if ( V_194 < 0 ) {
F_142 ( L_43 , V_16 ) ;
goto V_220;
}
return V_194 ;
V_220:
F_147 ( & V_42 ) ;
V_219:
F_148 ( V_195 ) ;
V_218:
F_149 ( & V_158 ) ;
V_196:
F_142 ( L_44 , V_16 , V_194 ) ;
F_150 ( V_195 ) ;
return V_194 ;
}
static void T_4 F_151 ( void )
{
F_152 () ;
F_153 () ;
F_147 ( & V_42 ) ;
F_148 ( V_195 ) ;
F_150 ( V_195 ) ;
F_149 ( & V_158 ) ;
F_154 ( & V_7 ) ;
}
static void F_155 ( struct V_42 * V_94 )
{
F_156 ( V_94 , V_39 ) ;
F_156 ( V_94 , V_51 ) ;
F_156 ( V_94 , V_44 ) ;
F_156 ( V_94 , V_52 ) ;
F_156 ( V_94 , V_53 ) ;
if ( V_94 -> V_221 )
F_156 ( V_94 , V_55 ) ;
F_156 ( V_94 , V_165 ) ;
F_156 ( V_94 , V_172 ) ;
F_156 ( V_94 , V_222 ) ;
F_156 ( V_94 , V_223 ) ;
}
static int F_157 ( struct V_42 * V_24 )
{
int V_29 ;
if ( F_158 () )
return - V_30 ;
if ( ! V_24 -> V_75 )
V_24 -> V_75 = V_24 -> V_24 . V_198 ;
if ( ! V_24 -> V_111 ) {
F_159 ( 1 , L_45 ,
V_24 -> V_75 ) ;
return - V_81 ;
}
F_155 ( V_24 ) ;
F_2 ( & V_6 ) ;
F_160 ( & V_24 -> V_224 , & V_225 ) ;
V_29 = F_161 ( V_24 ) ;
if ( V_29 ) {
F_142 ( L_46 , V_29 , V_24 -> V_75 ) ;
F_162 ( & V_24 -> V_224 ) ;
} else {
F_163 ( L_47 , V_24 -> V_75 ) ;
}
F_4 ( & V_6 ) ;
return V_29 ;
}
static void F_164 ( struct V_42 * V_94 )
{
F_163 ( L_48 , V_94 -> V_75 ) ;
F_2 ( & V_6 ) ;
F_162 ( & V_94 -> V_224 ) ;
F_4 ( & V_6 ) ;
F_165 ( V_94 ) ;
}
int F_166 ( struct V_42 * const V_226 [] ,
const char * V_198 ,
const struct V_102 * V_109 )
{
int V_227 ;
struct V_111 * V_228 ;
struct V_42 * const * V_229 ;
V_228 = F_73 ( sizeof( * V_228 ) , V_17 ) ;
if ( ! V_228 )
return - V_135 ;
V_228 -> V_198 = V_198 ;
V_228 -> V_230 = 1 ;
V_228 -> V_231 = 1 ;
V_228 -> V_187 = F_134 ;
V_228 -> V_190 = F_136 ;
V_228 -> V_136 = F_90 ;
V_228 -> V_183 = F_124 ;
for ( V_229 = V_226 ; * V_229 ; ++ V_229 ) {
if ( ( * V_229 ) -> V_191 ) {
V_228 -> V_191 = F_138 ;
break;
}
}
V_227 = F_145 ( V_228 ) ;
if ( V_227 )
return V_227 ;
for ( V_229 = V_226 ; * V_229 ; ++ V_229 ) {
( * V_229 ) -> V_111 = V_228 ;
V_227 = F_157 ( * V_229 ) ;
if ( V_227 )
goto V_232;
}
V_228 -> V_109 = V_109 ;
V_227 = F_167 ( & V_228 -> V_233 . V_24 ) ;
return 0 ;
V_232:
while ( V_229 -- > V_226 )
F_164 ( * V_229 ) ;
F_147 ( V_228 ) ;
return V_227 ;
}
void F_168 ( struct V_42 * const V_226 [] )
{
struct V_111 * V_228 = ( * V_226 ) -> V_111 ;
for (; * V_226 ; ++ V_226 )
F_164 ( * V_226 ) ;
F_147 ( V_228 ) ;
F_16 ( V_228 ) ;
}
