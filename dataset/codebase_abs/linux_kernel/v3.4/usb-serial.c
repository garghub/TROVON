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
F_6 ( L_1 , V_14 , V_9 ) ;
* V_10 = 0 ;
F_2 ( & V_4 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 ) {
if ( V_5 [ V_11 ] )
continue;
V_13 = 1 ;
for ( V_12 = 1 ; V_12 <= V_9 - 1 ; ++ V_12 )
if ( ( V_11 + V_12 >= V_15 ) || ( V_5 [ V_11 + V_12 ] ) ) {
V_13 = 0 ;
V_11 += V_12 ;
break;
}
if ( V_13 == 0 )
continue;
* V_10 = V_11 ;
V_12 = 0 ;
F_6 ( L_2 , V_14 , * V_10 ) ;
for ( V_11 = * V_10 ; ( V_11 < ( * V_10 + V_9 ) ) && ( V_11 < V_15 ) ; ++ V_11 ) {
V_5 [ V_11 ] = V_3 ;
V_3 -> V_16 [ V_12 ++ ] -> V_17 = V_11 ;
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
F_6 ( L_3 , V_14 ) ;
F_2 ( & V_4 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 )
V_5 [ V_3 -> V_10 + V_11 ] = NULL ;
F_3 ( & V_4 ) ;
}
static void F_8 ( struct V_8 * V_8 )
{
struct V_1 * V_3 ;
struct V_18 * V_16 ;
int V_11 ;
V_3 = F_9 ( V_8 ) ;
F_6 ( L_4 , V_14 , V_3 -> type -> V_19 ) ;
if ( V_3 -> V_10 != V_20 )
F_7 ( V_3 ) ;
if ( V_3 -> V_21 )
V_3 -> type -> V_22 ( V_3 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_23 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
if ( V_16 ) {
V_16 -> V_3 = NULL ;
F_10 ( & V_16 -> V_24 ) ;
}
}
F_11 ( V_3 -> V_24 ) ;
F_12 ( V_3 ) ;
}
void F_13 ( struct V_1 * V_3 )
{
F_14 ( & V_3 -> V_8 , F_8 ) ;
}
static int F_15 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
int V_29 = V_28 -> V_2 ;
struct V_1 * V_3 ;
struct V_18 * V_16 ;
int V_30 = - V_31 ;
F_6 ( L_3 , V_14 ) ;
V_3 = F_1 ( V_29 ) ;
if ( ! V_3 )
return V_30 ;
V_16 = V_3 -> V_16 [ V_29 - V_3 -> V_10 ] ;
if ( ! V_16 )
goto V_32;
if ( ! F_16 ( V_3 -> type -> V_26 . V_33 ) )
goto V_34;
V_30 = F_17 ( V_3 -> V_35 ) ;
if ( V_30 )
goto V_36;
V_30 = F_18 ( V_26 , V_28 ) ;
if ( V_30 )
goto V_37;
F_3 ( & V_3 -> V_6 ) ;
if ( V_3 -> type -> V_38 )
V_3 -> type -> V_38 ( V_28 ) ;
V_28 -> V_39 = V_16 ;
return V_30 ;
V_37:
F_19 ( V_3 -> V_35 ) ;
V_36:
F_20 ( V_3 -> type -> V_26 . V_33 ) ;
V_34:
V_32:
F_13 ( V_3 ) ;
F_3 ( & V_3 -> V_6 ) ;
return V_30 ;
}
static int F_21 ( struct V_40 * V_41 , struct V_27 * V_28 )
{
struct V_18 * V_16 =
F_22 ( V_41 , struct V_18 , V_16 ) ;
struct V_1 * V_3 = V_16 -> V_3 ;
int V_30 ;
F_2 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_7 )
V_30 = - V_31 ;
else
V_30 = V_16 -> V_3 -> type -> V_42 ( V_28 , V_16 ) ;
F_3 ( & V_3 -> V_6 ) ;
if ( V_30 < 0 )
V_30 = F_23 ( V_30 ) ;
return V_30 ;
}
static int F_24 ( struct V_27 * V_28 , struct V_43 * V_44 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
return F_25 ( & V_16 -> V_16 , V_28 , V_44 ) ;
}
static void F_26 ( struct V_40 * V_41 )
{
struct V_18 * V_16 =
F_22 ( V_41 , struct V_18 , V_16 ) ;
struct V_45 * V_46 = V_16 -> V_3 -> type ;
if ( V_16 -> V_16 . V_47 )
return;
if ( V_46 -> V_48 )
V_46 -> V_48 ( V_16 ) ;
}
static void F_27 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
F_28 ( & V_16 -> V_16 ) ;
}
static void F_29 ( struct V_27 * V_28 , struct V_43 * V_44 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
F_30 ( & V_16 -> V_16 , V_28 , V_44 ) ;
}
static void F_31 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
struct V_1 * V_3 ;
struct V_49 * V_33 ;
if ( V_16 -> V_16 . V_47 )
return;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
V_28 -> V_39 = NULL ;
V_3 = V_16 -> V_3 ;
V_33 = V_3 -> type -> V_26 . V_33 ;
F_2 ( & V_3 -> V_6 ) ;
if ( ! V_3 -> V_7 )
F_19 ( V_3 -> V_35 ) ;
F_3 ( & V_3 -> V_6 ) ;
F_13 ( V_3 ) ;
F_20 ( V_33 ) ;
}
static int F_32 ( struct V_27 * V_28 , const unsigned char * V_50 ,
int V_51 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
int V_30 = - V_31 ;
if ( V_16 -> V_3 -> V_24 -> V_52 == V_53 )
goto exit;
F_6 ( L_6 , V_14 , V_16 -> V_17 , V_51 ) ;
V_30 = V_16 -> V_3 -> type -> V_54 ( V_28 , V_16 , V_50 , V_51 ) ;
if ( V_30 < 0 )
V_30 = F_23 ( V_30 ) ;
exit:
return V_30 ;
}
static int F_33 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
return V_16 -> V_3 -> type -> V_55 ( V_28 ) ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> V_7 )
return 0 ;
return V_16 -> V_3 -> type -> V_56 ( V_28 ) ;
}
static void F_35 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_57 )
V_16 -> V_3 -> type -> V_57 ( V_28 ) ;
}
static void F_36 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_58 )
V_16 -> V_3 -> type -> V_58 ( V_28 ) ;
}
static int F_37 ( struct V_27 * V_28 ,
unsigned int V_59 , unsigned long V_60 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
int V_30 = - V_31 ;
F_6 ( L_7 , V_14 , V_16 -> V_17 , V_59 ) ;
if ( V_16 -> V_3 -> type -> V_61 ) {
V_30 = V_16 -> V_3 -> type -> V_61 ( V_28 , V_59 , V_60 ) ;
} else
V_30 = - V_62 ;
return V_30 ;
}
static void F_38 ( struct V_27 * V_28 , struct V_63 * V_64 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_65 )
V_16 -> V_3 -> type -> V_65 ( V_28 , V_16 , V_64 ) ;
else
F_39 ( V_28 -> V_66 , V_64 ) ;
}
static int F_40 ( struct V_27 * V_28 , int V_67 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_68 )
V_16 -> V_3 -> type -> V_68 ( V_28 , V_67 ) ;
return 0 ;
}
static int F_41 ( struct V_69 * V_70 , void * V_71 )
{
struct V_1 * V_3 ;
int V_11 ;
char V_72 [ 40 ] ;
F_6 ( L_3 , V_14 ) ;
F_42 ( V_70 , L_8 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 ) {
V_3 = F_1 ( V_11 ) ;
if ( V_3 == NULL )
continue;
F_43 ( V_70 , L_9 , V_11 ) ;
if ( V_3 -> type -> V_26 . V_33 )
F_43 ( V_70 , L_10 ,
F_44 ( V_3 -> type -> V_26 . V_33 ) ) ;
F_43 ( V_70 , L_11 ,
V_3 -> type -> V_19 ) ;
F_43 ( V_70 , L_12 ,
F_45 ( V_3 -> V_24 -> V_73 . V_74 ) ,
F_45 ( V_3 -> V_24 -> V_73 . V_75 ) ) ;
F_43 ( V_70 , L_13 , V_3 -> V_9 ) ;
F_43 ( V_70 , L_14 , V_11 - V_3 -> V_10 + 1 ) ;
F_46 ( V_3 -> V_24 , V_72 , sizeof( V_72 ) ) ;
F_43 ( V_70 , L_15 , V_72 ) ;
F_47 ( V_70 , '\n' ) ;
F_13 ( V_3 ) ;
F_3 ( & V_3 -> V_6 ) ;
}
return 0 ;
}
static int F_48 ( struct V_76 * V_76 , struct V_43 * V_43 )
{
return F_49 ( V_43 , F_41 , NULL ) ;
}
static int F_50 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_77 )
return V_16 -> V_3 -> type -> V_77 ( V_28 ) ;
return - V_78 ;
}
static int F_51 ( struct V_27 * V_28 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_81 )
return V_16 -> V_3 -> type -> V_81 ( V_28 , V_79 , V_80 ) ;
return - V_78 ;
}
static int F_52 ( struct V_27 * V_28 ,
struct V_82 * V_83 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_84 )
return V_16 -> V_3 -> type -> V_84 ( V_28 , V_83 ) ;
return - V_78 ;
}
void F_53 ( struct V_18 * V_16 )
{
F_54 ( & V_16 -> V_85 ) ;
}
static void F_55 ( struct V_86 * V_85 )
{
struct V_18 * V_16 =
F_22 ( V_85 , struct V_18 , V_85 ) ;
struct V_27 * V_28 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
V_28 = F_56 ( & V_16 -> V_16 ) ;
if ( ! V_28 )
return;
F_57 ( V_28 ) ;
F_58 ( V_28 ) ;
}
static void F_59 ( struct V_18 * V_16 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_60 ( V_16 -> V_87 ) ; ++ V_11 )
F_61 ( V_16 -> V_87 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < F_60 ( V_16 -> V_88 ) ; ++ V_11 )
F_61 ( V_16 -> V_88 [ V_11 ] ) ;
F_61 ( V_16 -> V_89 ) ;
F_61 ( V_16 -> V_90 ) ;
F_61 ( V_16 -> V_91 ) ;
}
static void F_62 ( struct V_92 * V_24 )
{
struct V_18 * V_16 = F_63 ( V_24 ) ;
int V_11 ;
F_6 ( L_4 , V_14 , F_64 ( V_24 ) ) ;
F_59 ( V_16 ) ;
F_65 ( & V_16 -> V_85 ) ;
F_66 ( V_16 -> V_90 ) ;
F_66 ( V_16 -> V_91 ) ;
for ( V_11 = 0 ; V_11 < F_60 ( V_16 -> V_87 ) ; ++ V_11 ) {
F_66 ( V_16 -> V_87 [ V_11 ] ) ;
F_12 ( V_16 -> V_93 [ V_11 ] ) ;
}
for ( V_11 = 0 ; V_11 < F_60 ( V_16 -> V_88 ) ; ++ V_11 ) {
F_66 ( V_16 -> V_88 [ V_11 ] ) ;
F_12 ( V_16 -> V_94 [ V_11 ] ) ;
}
F_67 ( & V_16 -> V_95 ) ;
F_12 ( V_16 -> V_96 ) ;
F_12 ( V_16 -> V_97 ) ;
F_12 ( V_16 ) ;
}
static struct V_1 * F_68 ( struct V_98 * V_24 ,
struct V_99 * V_35 ,
struct V_45 * V_26 )
{
struct V_1 * V_3 ;
V_3 = F_69 ( sizeof( * V_3 ) , V_100 ) ;
if ( ! V_3 ) {
F_70 ( & V_24 -> V_24 , L_16 , V_14 ) ;
return NULL ;
}
V_3 -> V_24 = F_71 ( V_24 ) ;
V_3 -> type = V_26 ;
V_3 -> V_35 = V_35 ;
F_72 ( & V_3 -> V_8 ) ;
F_73 ( & V_3 -> V_6 ) ;
V_3 -> V_10 = V_20 ;
return V_3 ;
}
static const struct V_101 * F_74 ( struct V_99 * V_102 ,
struct V_45 * V_46 )
{
struct V_103 * V_104 ;
F_75 ( & V_46 -> V_105 . V_106 ) ;
F_76 (dynid, &drv->dynids.list, node) {
if ( F_77 ( V_102 , & V_104 -> V_107 ) ) {
F_78 ( & V_46 -> V_105 . V_106 ) ;
return & V_104 -> V_107 ;
}
}
F_78 ( & V_46 -> V_105 . V_106 ) ;
return NULL ;
}
static const struct V_101 * F_79 ( struct V_45 * V_46 ,
struct V_99 * V_102 )
{
const struct V_101 * V_107 ;
V_107 = F_80 ( V_102 , V_46 -> V_108 ) ;
if ( V_107 ) {
F_6 ( L_17 ) ;
goto exit;
}
V_107 = F_74 ( V_102 , V_46 ) ;
if ( V_107 )
F_6 ( L_18 ) ;
exit:
return V_107 ;
}
static struct V_45 * F_81 (
struct V_99 * V_109 )
{
const struct V_101 * V_107 ;
struct V_45 * V_46 ;
F_76 (drv, &usb_serial_driver_list, driver_list) {
V_107 = F_79 ( V_46 , V_109 ) ;
if ( V_107 )
return V_46 ;
}
return NULL ;
}
static int F_82 ( struct V_40 * V_16 )
{
struct V_18 * V_110 = F_22 ( V_16 , struct V_18 , V_16 ) ;
struct V_45 * V_46 = V_110 -> V_3 -> type ;
if ( V_46 -> V_111 )
return V_46 -> V_111 ( V_110 ) ;
return 1 ;
}
static void F_83 ( struct V_40 * V_16 , int V_112 )
{
struct V_18 * V_110 = F_22 ( V_16 , struct V_18 , V_16 ) ;
struct V_45 * V_46 = V_110 -> V_3 -> type ;
if ( V_46 -> V_113 )
V_46 -> V_113 ( V_110 , V_112 ) ;
}
int F_84 ( struct V_99 * V_35 ,
const struct V_101 * V_107 )
{
struct V_98 * V_24 = F_85 ( V_35 ) ;
struct V_1 * V_3 = NULL ;
struct V_18 * V_16 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
struct V_116 * V_118 [ V_119 ] ;
struct V_116 * V_120 [ V_119 ] ;
struct V_116 * V_121 [ V_119 ] ;
struct V_116 * V_122 [ V_119 ] ;
struct V_45 * type = NULL ;
int V_30 ;
unsigned int V_10 ;
int V_123 ;
int V_11 ;
int V_12 ;
int V_124 = 0 ;
int V_125 = 0 ;
int V_126 = 0 ;
int V_127 = 0 ;
int V_9 = 0 ;
int V_128 ;
F_2 ( & V_4 ) ;
type = F_81 ( V_35 ) ;
if ( ! type ) {
F_3 ( & V_4 ) ;
F_6 ( L_19 ) ;
return - V_31 ;
}
if ( ! F_16 ( type -> V_26 . V_33 ) ) {
F_3 ( & V_4 ) ;
F_70 ( & V_35 -> V_24 , L_20 ) ;
return - V_129 ;
}
F_3 ( & V_4 ) ;
V_3 = F_68 ( V_24 , V_35 , type ) ;
if ( ! V_3 ) {
F_20 ( type -> V_26 . V_33 ) ;
F_70 ( & V_35 -> V_24 , L_16 , V_14 ) ;
return - V_130 ;
}
if ( type -> V_131 ) {
const struct V_101 * V_107 ;
V_107 = F_79 ( type , V_35 ) ;
V_30 = type -> V_131 ( V_3 , V_107 ) ;
if ( V_30 ) {
F_6 ( L_21 ) ;
F_12 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return V_30 ;
}
}
V_115 = V_35 -> V_132 ;
for ( V_11 = 0 ; V_11 < V_115 -> V_133 . V_134 ; ++ V_11 ) {
V_117 = & V_115 -> V_117 [ V_11 ] . V_133 ;
if ( F_86 ( V_117 ) ) {
F_6 ( L_22 , V_11 ) ;
V_121 [ V_126 ] = V_117 ;
++ V_126 ;
}
if ( F_87 ( V_117 ) ) {
F_6 ( L_23 , V_11 ) ;
V_122 [ V_127 ] = V_117 ;
++ V_127 ;
}
if ( F_88 ( V_117 ) ) {
F_6 ( L_24 , V_11 ) ;
V_118 [ V_124 ] = V_117 ;
++ V_124 ;
}
if ( F_89 ( V_117 ) ) {
F_6 ( L_25 , V_11 ) ;
V_120 [ V_125 ] = V_117 ;
++ V_125 ;
}
}
#if F_90 ( V_135 ) || F_90 ( V_136 )
if ( ( ( F_45 ( V_24 -> V_73 . V_74 ) == V_137 ) &&
( F_45 ( V_24 -> V_73 . V_75 ) == V_138 ) ) ||
( ( F_45 ( V_24 -> V_73 . V_74 ) == V_139 ) &&
( F_45 ( V_24 -> V_73 . V_75 ) == V_140 ) ) ||
( ( F_45 ( V_24 -> V_73 . V_74 ) == V_141 ) &&
( F_45 ( V_24 -> V_73 . V_75 ) == V_142 ) ) ||
( ( F_45 ( V_24 -> V_73 . V_74 ) == V_143 ) &&
( F_45 ( V_24 -> V_73 . V_75 ) == V_144 ) ) ) {
if ( V_35 != V_24 -> V_145 -> V_35 [ 0 ] ) {
V_115 = V_24 -> V_145 -> V_35 [ 0 ] -> V_132 ;
for ( V_11 = 0 ; V_11 < V_115 -> V_133 . V_134 ; ++ V_11 ) {
V_117 = & V_115 -> V_117 [ V_11 ] . V_133 ;
if ( F_88 ( V_117 ) ) {
F_6 ( L_26 ) ;
V_118 [ V_124 ] = V_117 ;
++ V_124 ;
}
}
}
if ( V_126 == 0 || V_127 == 0 ) {
F_91 ( & V_35 -> V_24 , L_27 ) ;
F_12 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_31 ;
}
}
#endif
#ifdef F_92
if ( type == & V_146 ) {
V_9 = V_127 ;
if ( V_9 == 0 ) {
F_70 ( & V_35 -> V_24 ,
L_28 ) ;
F_12 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_129 ;
}
}
#endif
if ( ! V_9 ) {
if ( type -> V_147 )
V_9 = type -> V_147 ( V_3 ) ;
if ( ! V_9 )
V_9 = type -> V_9 ;
}
V_3 -> V_9 = V_9 ;
V_3 -> V_126 = V_126 ;
V_3 -> V_127 = V_127 ;
V_3 -> V_124 = V_124 ;
V_3 -> V_125 = V_125 ;
F_91 ( & V_35 -> V_24 , L_29 ,
type -> V_19 ) ;
V_128 = F_93 ( V_126 , V_127 ) ;
V_128 = F_93 ( V_128 , V_124 ) ;
V_128 = F_93 ( V_128 , V_125 ) ;
V_128 = F_93 ( V_128 , ( int ) V_3 -> V_9 ) ;
V_3 -> V_23 = V_128 ;
F_6 ( L_30 ,
V_14 , V_128 ) ;
for ( V_11 = 0 ; V_11 < V_128 ; ++ V_11 ) {
V_16 = F_69 ( sizeof( struct V_18 ) , V_100 ) ;
if ( ! V_16 )
goto V_148;
F_94 ( & V_16 -> V_16 ) ;
V_16 -> V_16 . V_149 = & V_150 ;
V_16 -> V_3 = V_3 ;
F_95 ( & V_16 -> V_106 ) ;
F_96 ( & V_16 -> V_85 , F_55 ) ;
V_3 -> V_16 [ V_11 ] = V_16 ;
V_16 -> V_24 . V_151 = & V_35 -> V_24 ;
V_16 -> V_24 . V_26 = NULL ;
V_16 -> V_24 . V_152 = & V_153 ;
V_16 -> V_24 . V_22 = & F_62 ;
F_97 ( & V_16 -> V_24 ) ;
}
for ( V_11 = 0 ; V_11 < V_126 ; ++ V_11 ) {
V_117 = V_121 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_123 = F_98 ( int , V_3 -> type -> V_154 ,
F_99 ( V_117 ) ) ;
V_16 -> V_154 = V_123 ;
V_16 -> V_155 = V_117 -> V_156 ;
for ( V_12 = 0 ; V_12 < F_60 ( V_16 -> V_87 ) ; ++ V_12 ) {
F_100 ( V_12 , & V_16 -> V_157 ) ;
V_16 -> V_87 [ V_12 ] = F_101 ( 0 , V_100 ) ;
if ( ! V_16 -> V_87 [ V_12 ] ) {
F_70 ( & V_35 -> V_24 ,
L_31 ) ;
goto V_148;
}
V_16 -> V_93 [ V_12 ] = F_102 ( V_123 ,
V_100 ) ;
if ( ! V_16 -> V_93 [ V_12 ] ) {
F_70 ( & V_35 -> V_24 ,
L_32 ) ;
goto V_148;
}
F_103 ( V_16 -> V_87 [ V_12 ] , V_24 ,
F_104 ( V_24 ,
V_117 -> V_156 ) ,
V_16 -> V_93 [ V_12 ] , V_123 ,
V_3 -> type -> V_158 ,
V_16 ) ;
}
V_16 -> V_89 = V_16 -> V_87 [ 0 ] ;
V_16 -> V_159 = V_16 -> V_93 [ 0 ] ;
}
for ( V_11 = 0 ; V_11 < V_127 ; ++ V_11 ) {
V_117 = V_122 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
if ( F_105 ( & V_16 -> V_95 , V_160 , V_100 ) )
goto V_148;
V_123 = V_3 -> type -> V_161 ;
if ( ! V_123 )
V_123 = F_99 ( V_117 ) ;
V_16 -> V_161 = V_123 ;
V_16 -> V_162 = V_117 -> V_156 ;
for ( V_12 = 0 ; V_12 < F_60 ( V_16 -> V_88 ) ; ++ V_12 ) {
F_100 ( V_12 , & V_16 -> V_163 ) ;
V_16 -> V_88 [ V_12 ] = F_101 ( 0 , V_100 ) ;
if ( ! V_16 -> V_88 [ V_12 ] ) {
F_70 ( & V_35 -> V_24 ,
L_31 ) ;
goto V_148;
}
V_16 -> V_94 [ V_12 ] = F_102 ( V_123 ,
V_100 ) ;
if ( ! V_16 -> V_94 [ V_12 ] ) {
F_70 ( & V_35 -> V_24 ,
L_33 ) ;
goto V_148;
}
F_103 ( V_16 -> V_88 [ V_12 ] , V_24 ,
F_106 ( V_24 ,
V_117 -> V_156 ) ,
V_16 -> V_94 [ V_12 ] , V_123 ,
V_3 -> type -> V_164 ,
V_16 ) ;
}
V_16 -> V_165 = V_16 -> V_88 [ 0 ] ;
V_16 -> V_166 = V_16 -> V_94 [ 0 ] ;
}
if ( V_3 -> type -> V_167 ) {
for ( V_11 = 0 ; V_11 < V_124 ; ++ V_11 ) {
V_117 = V_118 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_16 -> V_90 = F_101 ( 0 , V_100 ) ;
if ( ! V_16 -> V_90 ) {
F_70 ( & V_35 -> V_24 ,
L_31 ) ;
goto V_148;
}
V_123 = F_99 ( V_117 ) ;
V_16 -> V_168 =
V_117 -> V_156 ;
V_16 -> V_96 = F_102 ( V_123 ,
V_100 ) ;
if ( ! V_16 -> V_96 ) {
F_70 ( & V_35 -> V_24 ,
L_34 ) ;
goto V_148;
}
F_107 ( V_16 -> V_90 , V_24 ,
F_108 ( V_24 ,
V_117 -> V_156 ) ,
V_16 -> V_96 , V_123 ,
V_3 -> type -> V_167 , V_16 ,
V_117 -> V_169 ) ;
}
} else if ( V_124 ) {
F_6 ( L_35 ) ;
}
if ( V_3 -> type -> V_170 ) {
for ( V_11 = 0 ; V_11 < V_125 ; ++ V_11 ) {
V_117 = V_120 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_16 -> V_91 = F_101 ( 0 , V_100 ) ;
if ( ! V_16 -> V_91 ) {
F_70 ( & V_35 -> V_24 ,
L_31 ) ;
goto V_148;
}
V_123 = F_99 ( V_117 ) ;
V_16 -> V_171 = V_123 ;
V_16 -> V_172 =
V_117 -> V_156 ;
V_16 -> V_97 = F_102 ( V_123 ,
V_100 ) ;
if ( ! V_16 -> V_97 ) {
F_70 ( & V_35 -> V_24 ,
L_36 ) ;
goto V_148;
}
F_107 ( V_16 -> V_91 , V_24 ,
F_109 ( V_24 ,
V_117 -> V_156 ) ,
V_16 -> V_97 , V_123 ,
V_3 -> type -> V_170 , V_16 ,
V_117 -> V_169 ) ;
}
} else if ( V_125 ) {
F_6 ( L_37 ) ;
}
if ( type -> V_173 ) {
V_30 = type -> V_173 ( V_3 ) ;
if ( V_30 < 0 )
goto V_148;
V_3 -> V_21 = 1 ;
if ( V_30 > 0 ) {
V_3 -> V_9 = 0 ;
goto exit;
}
} else {
V_3 -> V_21 = 1 ;
}
V_3 -> V_7 = 1 ;
if ( F_5 ( V_3 , V_9 , & V_10 ) == NULL ) {
F_70 ( & V_35 -> V_24 , L_38 ) ;
goto V_148;
}
V_3 -> V_10 = V_10 ;
for ( V_11 = 0 ; V_11 < V_9 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
F_110 ( & V_16 -> V_24 , L_39 , V_16 -> V_17 ) ;
F_6 ( L_40 , V_14 , F_64 ( & V_16 -> V_24 ) ) ;
F_111 ( & V_16 -> V_24 ) ;
V_30 = F_112 ( & V_16 -> V_24 ) ;
if ( V_30 )
F_70 ( & V_16 -> V_24 , L_41
L_42 ) ;
}
V_3 -> V_7 = 0 ;
F_113 ( V_174 , V_10 ) ;
exit:
F_114 ( V_35 , V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return 0 ;
V_148:
F_13 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_129 ;
}
void F_115 ( struct V_99 * V_35 )
{
int V_11 ;
struct V_1 * V_3 = F_116 ( V_35 ) ;
struct V_92 * V_24 = & V_35 -> V_24 ;
struct V_18 * V_16 ;
F_117 ( V_3 ) ;
F_6 ( L_3 , V_14 ) ;
F_2 ( & V_3 -> V_6 ) ;
F_114 ( V_35 , NULL ) ;
V_3 -> V_7 = 1 ;
F_3 ( & V_3 -> V_6 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
if ( V_16 ) {
struct V_27 * V_28 = F_56 ( & V_16 -> V_16 ) ;
if ( V_28 ) {
F_118 ( V_28 ) ;
F_58 ( V_28 ) ;
}
F_59 ( V_16 ) ;
F_65 ( & V_16 -> V_85 ) ;
if ( F_119 ( & V_16 -> V_24 ) )
F_120 ( & V_16 -> V_24 ) ;
}
}
V_3 -> type -> V_175 ( V_3 ) ;
F_13 ( V_3 ) ;
F_91 ( V_24 , L_43 ) ;
}
int F_121 ( struct V_99 * V_102 , T_1 V_176 )
{
struct V_1 * V_3 = F_116 ( V_102 ) ;
struct V_18 * V_16 ;
int V_11 , V_177 = 0 ;
V_3 -> V_178 = 1 ;
if ( V_3 -> type -> V_179 ) {
V_177 = V_3 -> type -> V_179 ( V_3 , V_176 ) ;
if ( V_177 < 0 ) {
V_3 -> V_178 = 0 ;
goto V_180;
}
}
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
if ( V_16 )
F_59 ( V_16 ) ;
}
V_180:
return V_177 ;
}
int F_122 ( struct V_99 * V_102 )
{
struct V_1 * V_3 = F_116 ( V_102 ) ;
int V_181 ;
V_3 -> V_178 = 0 ;
if ( V_3 -> type -> V_182 )
V_181 = V_3 -> type -> V_182 ( V_3 ) ;
else
V_181 = F_123 ( V_3 ) ;
return V_181 ;
}
static int T_2 F_124 ( void )
{
int V_11 ;
int V_183 ;
V_184 = F_125 ( V_15 ) ;
if ( ! V_184 )
return - V_130 ;
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 )
V_5 [ V_11 ] = NULL ;
V_183 = F_126 ( & V_153 ) ;
if ( V_183 ) {
F_127 ( V_185 L_44
L_45 , V_14 ) ;
goto V_186;
}
V_184 -> V_187 = L_46 ;
V_184 -> V_188 = L_47 ;
V_184 -> V_189 = V_190 ;
V_184 -> V_191 = 0 ;
V_184 -> type = V_192 ;
V_184 -> V_193 = V_194 ;
V_184 -> V_195 = V_196 |
V_197 ;
V_184 -> V_38 = V_198 ;
V_184 -> V_38 . V_199 = V_200 | V_201 | V_202
| V_203 | V_204 ;
V_184 -> V_38 . V_205 = 9600 ;
V_184 -> V_38 . V_206 = 9600 ;
F_128 ( V_184 , & V_207 ) ;
V_183 = F_129 ( V_184 ) ;
if ( V_183 ) {
F_127 ( V_185 L_48 ,
V_14 ) ;
goto V_208;
}
V_183 = F_130 ( & V_45 ) ;
if ( V_183 < 0 ) {
F_127 ( V_185 L_49 ,
V_14 ) ;
goto V_209;
}
V_183 = F_131 ( V_174 ) ;
if ( V_183 < 0 ) {
F_127 ( V_185 L_50
L_51 , V_14 ) ;
goto V_210;
}
F_127 (KERN_INFO KBUILD_MODNAME L_52 DRIVER_DESC L_53 ) ;
return V_183 ;
V_210:
F_132 ( & V_45 ) ;
V_209:
F_133 ( V_184 ) ;
V_208:
F_134 ( & V_153 ) ;
V_186:
F_127 ( V_185 L_54 ,
V_14 , V_183 ) ;
F_135 ( V_184 ) ;
return V_183 ;
}
static void T_3 F_136 ( void )
{
F_137 () ;
F_138 () ;
F_132 ( & V_45 ) ;
F_133 ( V_184 ) ;
F_135 ( V_184 ) ;
F_134 ( & V_153 ) ;
}
static void F_139 ( struct V_45 * V_92 )
{
F_140 ( V_92 , V_42 ) ;
F_140 ( V_92 , V_54 ) ;
F_140 ( V_92 , V_48 ) ;
F_140 ( V_92 , V_55 ) ;
F_140 ( V_92 , V_56 ) ;
F_140 ( V_92 , V_158 ) ;
F_140 ( V_92 , V_164 ) ;
F_140 ( V_92 , V_175 ) ;
F_140 ( V_92 , V_22 ) ;
F_140 ( V_92 , V_211 ) ;
F_140 ( V_92 , V_212 ) ;
}
static int F_141 ( struct V_45 * V_26 )
{
int V_30 ;
if ( F_142 () )
return - V_31 ;
F_139 ( V_26 ) ;
if ( ! V_26 -> V_19 )
V_26 -> V_19 = V_26 -> V_26 . V_188 ;
if ( ! V_26 -> V_213 ) {
F_143 ( 1 , L_55 ,
V_26 -> V_19 ) ;
return - V_78 ;
}
V_26 -> V_213 -> V_214 = 1 ;
F_2 ( & V_4 ) ;
F_144 ( & V_26 -> V_215 , & V_216 ) ;
V_30 = F_145 ( V_26 ) ;
if ( V_30 ) {
F_127 ( V_185 L_56
L_57 , V_30 , V_26 -> V_19 ) ;
F_146 ( & V_26 -> V_215 ) ;
} else
F_127 ( V_217 L_58 ,
V_26 -> V_19 ) ;
F_3 ( & V_4 ) ;
return V_30 ;
}
static void F_147 ( struct V_45 * V_92 )
{
F_127 ( V_217 L_59 ,
V_92 -> V_19 ) ;
F_2 ( & V_4 ) ;
F_146 ( & V_92 -> V_215 ) ;
F_148 ( V_92 ) ;
F_3 ( & V_4 ) ;
}
int F_149 ( struct V_213 * V_218 ,
struct V_45 * const V_219 [] )
{
int V_220 ;
const struct V_101 * V_221 ;
struct V_45 * const * V_222 ;
V_221 = V_218 -> V_108 ;
V_218 -> V_108 = NULL ;
V_218 -> V_223 = 1 ;
V_220 = F_130 ( V_218 ) ;
if ( V_220 )
return V_220 ;
for ( V_222 = V_219 ; * V_222 ; ++ V_222 ) {
( * V_222 ) -> V_213 = V_218 ;
V_220 = F_141 ( * V_222 ) ;
if ( V_220 )
goto V_224;
}
V_218 -> V_108 = V_221 ;
V_220 = F_150 ( & V_218 -> V_225 . V_26 ) ;
return 0 ;
V_224:
while ( V_222 -- > V_219 )
F_147 ( * V_222 ) ;
F_132 ( V_218 ) ;
return V_220 ;
}
void F_151 ( struct V_213 * V_218 ,
struct V_45 * const V_219 [] )
{
for (; * V_219 ; ++ V_219 )
F_147 ( * V_219 ) ;
F_132 ( V_218 ) ;
}
