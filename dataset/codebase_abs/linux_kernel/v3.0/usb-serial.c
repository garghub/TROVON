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
V_30 = F_17 ( V_28 ) ;
if ( V_30 )
goto V_35;
V_30 = F_18 ( V_3 -> V_36 ) ;
if ( V_30 )
goto V_37;
F_3 ( & V_3 -> V_6 ) ;
if ( V_3 -> type -> V_38 )
V_3 -> type -> V_38 ( V_28 ) ;
V_28 -> V_39 = V_16 ;
F_19 ( V_26 ) ;
V_28 -> V_40 ++ ;
V_26 -> V_41 [ V_29 ] = V_28 ;
return V_30 ;
V_37:
V_35:
F_20 ( V_3 -> type -> V_26 . V_33 ) ;
V_34:
V_32:
F_13 ( V_3 ) ;
F_3 ( & V_3 -> V_6 ) ;
return V_30 ;
}
static int F_21 ( struct V_42 * V_43 , struct V_27 * V_28 )
{
struct V_18 * V_16 =
F_22 ( V_43 , struct V_18 , V_16 ) ;
struct V_1 * V_3 = V_16 -> V_3 ;
int V_30 ;
F_2 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_7 )
V_30 = - V_31 ;
else
V_30 = V_16 -> V_3 -> type -> V_44 ( V_28 , V_16 ) ;
F_3 ( & V_3 -> V_6 ) ;
return V_30 ;
}
static int F_23 ( struct V_27 * V_28 , struct V_45 * V_46 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
return F_24 ( & V_16 -> V_16 , V_28 , V_46 ) ;
}
static void F_25 ( struct V_42 * V_43 )
{
struct V_18 * V_16 =
F_22 ( V_43 , struct V_18 , V_16 ) ;
struct V_47 * V_48 = V_16 -> V_3 -> type ;
if ( V_16 -> V_16 . V_49 )
return;
if ( V_48 -> V_50 )
V_48 -> V_50 ( V_16 ) ;
}
static void F_26 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
F_27 ( & V_16 -> V_16 ) ;
}
static void F_28 ( struct V_27 * V_28 , struct V_45 * V_46 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
F_29 ( & V_16 -> V_16 , V_28 , V_46 ) ;
}
static void F_30 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
struct V_1 * V_3 ;
struct V_51 * V_33 ;
if ( V_16 -> V_16 . V_49 )
return;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
V_28 -> V_39 = NULL ;
V_3 = V_16 -> V_3 ;
V_33 = V_3 -> type -> V_26 . V_33 ;
F_2 ( & V_3 -> V_6 ) ;
if ( ! V_3 -> V_7 )
F_31 ( V_3 -> V_36 ) ;
F_3 ( & V_3 -> V_6 ) ;
F_13 ( V_3 ) ;
F_20 ( V_33 ) ;
}
static int F_32 ( struct V_27 * V_28 , const unsigned char * V_52 ,
int V_40 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
int V_30 = - V_31 ;
if ( V_16 -> V_3 -> V_24 -> V_53 == V_54 )
goto exit;
F_6 ( L_6 , V_14 , V_16 -> V_17 , V_40 ) ;
V_30 = V_16 -> V_3 -> type -> V_55 ( V_28 , V_16 , V_52 , V_40 ) ;
exit:
return V_30 ;
}
static int F_33 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
return V_16 -> V_3 -> type -> V_56 ( V_28 ) ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> V_7 )
return 0 ;
return V_16 -> V_3 -> type -> V_57 ( V_28 ) ;
}
static void F_35 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_58 )
V_16 -> V_3 -> type -> V_58 ( V_28 ) ;
}
static void F_36 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_59 )
V_16 -> V_3 -> type -> V_59 ( V_28 ) ;
}
static int F_37 ( struct V_27 * V_28 ,
unsigned int V_60 , unsigned long V_61 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
int V_30 = - V_31 ;
F_6 ( L_7 , V_14 , V_16 -> V_17 , V_60 ) ;
if ( V_16 -> V_3 -> type -> V_62 ) {
V_30 = V_16 -> V_3 -> type -> V_62 ( V_28 , V_60 , V_61 ) ;
} else
V_30 = - V_63 ;
return V_30 ;
}
static void F_38 ( struct V_27 * V_28 , struct V_64 * V_65 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_66 )
V_16 -> V_3 -> type -> V_66 ( V_28 , V_16 , V_65 ) ;
else
F_39 ( V_28 -> V_67 , V_65 ) ;
}
static int F_40 ( struct V_27 * V_28 , int V_68 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_69 )
V_16 -> V_3 -> type -> V_69 ( V_28 , V_68 ) ;
return 0 ;
}
static int F_41 ( struct V_70 * V_71 , void * V_72 )
{
struct V_1 * V_3 ;
int V_11 ;
char V_73 [ 40 ] ;
F_6 ( L_3 , V_14 ) ;
F_42 ( V_71 , L_8 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 ) {
V_3 = F_1 ( V_11 ) ;
if ( V_3 == NULL )
continue;
F_43 ( V_71 , L_9 , V_11 ) ;
if ( V_3 -> type -> V_26 . V_33 )
F_43 ( V_71 , L_10 ,
F_44 ( V_3 -> type -> V_26 . V_33 ) ) ;
F_43 ( V_71 , L_11 ,
V_3 -> type -> V_19 ) ;
F_43 ( V_71 , L_12 ,
F_45 ( V_3 -> V_24 -> V_74 . V_75 ) ,
F_45 ( V_3 -> V_24 -> V_74 . V_76 ) ) ;
F_43 ( V_71 , L_13 , V_3 -> V_9 ) ;
F_43 ( V_71 , L_14 , V_11 - V_3 -> V_10 + 1 ) ;
F_46 ( V_3 -> V_24 , V_73 , sizeof( V_73 ) ) ;
F_43 ( V_71 , L_15 , V_73 ) ;
F_47 ( V_71 , '\n' ) ;
F_13 ( V_3 ) ;
F_3 ( & V_3 -> V_6 ) ;
}
return 0 ;
}
static int F_48 ( struct V_77 * V_77 , struct V_45 * V_45 )
{
return F_49 ( V_45 , F_41 , NULL ) ;
}
static int F_50 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_78 )
return V_16 -> V_3 -> type -> V_78 ( V_28 ) ;
return - V_79 ;
}
static int F_51 ( struct V_27 * V_28 ,
unsigned int V_80 , unsigned int V_81 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_82 )
return V_16 -> V_3 -> type -> V_82 ( V_28 , V_80 , V_81 ) ;
return - V_79 ;
}
static int F_52 ( struct V_27 * V_28 ,
struct V_83 * V_84 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_85 )
return V_16 -> V_3 -> type -> V_85 ( V_28 , V_84 ) ;
return - V_79 ;
}
void F_53 ( struct V_18 * V_16 )
{
F_54 ( & V_16 -> V_86 ) ;
}
static void F_55 ( struct V_87 * V_86 )
{
struct V_18 * V_16 =
F_22 ( V_86 , struct V_18 , V_86 ) ;
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
F_60 ( V_16 -> V_88 ) ;
F_60 ( V_16 -> V_89 ) ;
for ( V_11 = 0 ; V_11 < F_61 ( V_16 -> V_90 ) ; ++ V_11 )
F_60 ( V_16 -> V_90 [ V_11 ] ) ;
F_60 ( V_16 -> V_88 ) ;
F_60 ( V_16 -> V_91 ) ;
F_60 ( V_16 -> V_92 ) ;
}
static void F_62 ( struct V_93 * V_24 )
{
struct V_18 * V_16 = F_63 ( V_24 ) ;
int V_11 ;
F_6 ( L_4 , V_14 , F_64 ( V_24 ) ) ;
F_59 ( V_16 ) ;
F_65 ( & V_16 -> V_86 ) ;
F_66 ( V_16 -> V_88 ) ;
F_66 ( V_16 -> V_89 ) ;
F_66 ( V_16 -> V_91 ) ;
F_66 ( V_16 -> V_92 ) ;
for ( V_11 = 0 ; V_11 < F_61 ( V_16 -> V_90 ) ; ++ V_11 ) {
F_66 ( V_16 -> V_90 [ V_11 ] ) ;
F_12 ( V_16 -> V_94 [ V_11 ] ) ;
}
F_67 ( & V_16 -> V_95 ) ;
F_12 ( V_16 -> V_96 ) ;
F_12 ( V_16 -> V_97 ) ;
F_12 ( V_16 -> V_98 ) ;
F_12 ( V_16 -> V_99 ) ;
F_12 ( V_16 ) ;
}
static struct V_1 * F_68 ( struct V_100 * V_24 ,
struct V_101 * V_36 ,
struct V_47 * V_26 )
{
struct V_1 * V_3 ;
V_3 = F_69 ( sizeof( * V_3 ) , V_102 ) ;
if ( ! V_3 ) {
F_70 ( & V_24 -> V_24 , L_16 , V_14 ) ;
return NULL ;
}
V_3 -> V_24 = F_71 ( V_24 ) ;
V_3 -> type = V_26 ;
V_3 -> V_36 = V_36 ;
F_72 ( & V_3 -> V_8 ) ;
F_73 ( & V_3 -> V_6 ) ;
V_3 -> V_10 = V_20 ;
return V_3 ;
}
static const struct V_103 * F_74 ( struct V_101 * V_104 ,
struct V_47 * V_48 )
{
struct V_105 * V_106 ;
F_75 ( & V_48 -> V_107 . V_108 ) ;
F_76 (dynid, &drv->dynids.list, node) {
if ( F_77 ( V_104 , & V_106 -> V_109 ) ) {
F_78 ( & V_48 -> V_107 . V_108 ) ;
return & V_106 -> V_109 ;
}
}
F_78 ( & V_48 -> V_107 . V_108 ) ;
return NULL ;
}
static const struct V_103 * F_79 ( struct V_47 * V_48 ,
struct V_101 * V_104 )
{
const struct V_103 * V_109 ;
V_109 = F_80 ( V_104 , V_48 -> V_110 ) ;
if ( V_109 ) {
F_6 ( L_17 ) ;
goto exit;
}
V_109 = F_74 ( V_104 , V_48 ) ;
if ( V_109 )
F_6 ( L_18 ) ;
exit:
return V_109 ;
}
static struct V_47 * F_81 (
struct V_101 * V_111 )
{
const struct V_103 * V_109 ;
struct V_47 * V_48 ;
F_76 (drv, &usb_serial_driver_list, driver_list) {
V_109 = F_79 ( V_48 , V_111 ) ;
if ( V_109 )
return V_48 ;
}
return NULL ;
}
static int F_82 ( struct V_42 * V_16 )
{
struct V_18 * V_112 = F_22 ( V_16 , struct V_18 , V_16 ) ;
struct V_47 * V_48 = V_112 -> V_3 -> type ;
if ( V_48 -> V_113 )
return V_48 -> V_113 ( V_112 ) ;
return 1 ;
}
static void F_83 ( struct V_42 * V_16 , int V_114 )
{
struct V_18 * V_112 = F_22 ( V_16 , struct V_18 , V_16 ) ;
struct V_47 * V_48 = V_112 -> V_3 -> type ;
if ( V_48 -> V_115 )
V_48 -> V_115 ( V_112 , V_114 ) ;
}
int F_84 ( struct V_101 * V_36 ,
const struct V_103 * V_109 )
{
struct V_100 * V_24 = F_85 ( V_36 ) ;
struct V_1 * V_3 = NULL ;
struct V_18 * V_16 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_118 * V_120 [ V_121 ] ;
struct V_118 * V_122 [ V_121 ] ;
struct V_118 * V_123 [ V_121 ] ;
struct V_118 * V_124 [ V_121 ] ;
struct V_47 * type = NULL ;
int V_30 ;
unsigned int V_10 ;
int V_125 ;
int V_11 ;
int V_126 = 0 ;
int V_127 = 0 ;
int V_128 = 0 ;
int V_129 = 0 ;
int V_9 = 0 ;
int V_130 ;
F_2 ( & V_4 ) ;
type = F_81 ( V_36 ) ;
if ( ! type ) {
F_3 ( & V_4 ) ;
F_6 ( L_19 ) ;
return - V_31 ;
}
if ( ! F_16 ( type -> V_26 . V_33 ) ) {
F_3 ( & V_4 ) ;
F_70 ( & V_36 -> V_24 , L_20 ) ;
return - V_131 ;
}
F_3 ( & V_4 ) ;
V_3 = F_68 ( V_24 , V_36 , type ) ;
if ( ! V_3 ) {
F_20 ( type -> V_26 . V_33 ) ;
F_70 ( & V_36 -> V_24 , L_16 , V_14 ) ;
return - V_132 ;
}
if ( type -> V_133 ) {
const struct V_103 * V_109 ;
V_109 = F_79 ( type , V_36 ) ;
V_30 = type -> V_133 ( V_3 , V_109 ) ;
if ( V_30 ) {
F_6 ( L_21 ) ;
F_12 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return V_30 ;
}
}
V_117 = V_36 -> V_134 ;
for ( V_11 = 0 ; V_11 < V_117 -> V_135 . V_136 ; ++ V_11 ) {
V_119 = & V_117 -> V_119 [ V_11 ] . V_135 ;
if ( F_86 ( V_119 ) ) {
F_6 ( L_22 , V_11 ) ;
V_123 [ V_128 ] = V_119 ;
++ V_128 ;
}
if ( F_87 ( V_119 ) ) {
F_6 ( L_23 , V_11 ) ;
V_124 [ V_129 ] = V_119 ;
++ V_129 ;
}
if ( F_88 ( V_119 ) ) {
F_6 ( L_24 , V_11 ) ;
V_120 [ V_126 ] = V_119 ;
++ V_126 ;
}
if ( F_89 ( V_119 ) ) {
F_6 ( L_25 , V_11 ) ;
V_122 [ V_127 ] = V_119 ;
++ V_127 ;
}
}
#if F_90 ( V_137 ) || F_90 ( V_138 )
if ( ( ( F_45 ( V_24 -> V_74 . V_75 ) == V_139 ) &&
( F_45 ( V_24 -> V_74 . V_76 ) == V_140 ) ) ||
( ( F_45 ( V_24 -> V_74 . V_75 ) == V_141 ) &&
( F_45 ( V_24 -> V_74 . V_76 ) == V_142 ) ) ||
( ( F_45 ( V_24 -> V_74 . V_75 ) == V_143 ) &&
( F_45 ( V_24 -> V_74 . V_76 ) == V_144 ) ) ||
( ( F_45 ( V_24 -> V_74 . V_75 ) == V_145 ) &&
( F_45 ( V_24 -> V_74 . V_76 ) == V_146 ) ) ) {
if ( V_36 != V_24 -> V_147 -> V_36 [ 0 ] ) {
V_117 = V_24 -> V_147 -> V_36 [ 0 ] -> V_134 ;
for ( V_11 = 0 ; V_11 < V_117 -> V_135 . V_136 ; ++ V_11 ) {
V_119 = & V_117 -> V_119 [ V_11 ] . V_135 ;
if ( F_88 ( V_119 ) ) {
F_6 ( L_26 ) ;
V_120 [ V_126 ] = V_119 ;
++ V_126 ;
}
}
}
if ( V_128 == 0 || V_129 == 0 ) {
F_91 ( & V_36 -> V_24 , L_27 ) ;
F_12 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_31 ;
}
}
#endif
#ifdef F_92
if ( type == & V_148 ) {
V_9 = V_129 ;
if ( V_9 == 0 ) {
F_70 ( & V_36 -> V_24 ,
L_28 ) ;
F_12 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_131 ;
}
}
#endif
if ( ! V_9 ) {
if ( type -> V_149 )
V_9 = type -> V_149 ( V_3 ) ;
if ( ! V_9 )
V_9 = type -> V_9 ;
}
V_3 -> V_9 = V_9 ;
V_3 -> V_128 = V_128 ;
V_3 -> V_129 = V_129 ;
V_3 -> V_126 = V_126 ;
V_3 -> V_127 = V_127 ;
F_91 ( & V_36 -> V_24 , L_29 ,
type -> V_19 ) ;
V_130 = F_93 ( V_128 , V_129 ) ;
V_130 = F_93 ( V_130 , V_126 ) ;
V_130 = F_93 ( V_130 , V_127 ) ;
V_130 = F_93 ( V_130 , ( int ) V_3 -> V_9 ) ;
V_3 -> V_23 = V_130 ;
F_6 ( L_30 ,
V_14 , V_130 ) ;
for ( V_11 = 0 ; V_11 < V_130 ; ++ V_11 ) {
V_16 = F_69 ( sizeof( struct V_18 ) , V_102 ) ;
if ( ! V_16 )
goto V_150;
F_94 ( & V_16 -> V_16 ) ;
V_16 -> V_16 . V_151 = & V_152 ;
V_16 -> V_3 = V_3 ;
F_95 ( & V_16 -> V_108 ) ;
F_96 ( & V_16 -> V_86 , F_55 ) ;
V_3 -> V_16 [ V_11 ] = V_16 ;
V_16 -> V_24 . V_153 = & V_36 -> V_24 ;
V_16 -> V_24 . V_26 = NULL ;
V_16 -> V_24 . V_154 = & V_155 ;
V_16 -> V_24 . V_22 = & F_62 ;
F_97 ( & V_16 -> V_24 ) ;
}
for ( V_11 = 0 ; V_11 < V_128 ; ++ V_11 ) {
V_119 = V_123 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_16 -> V_88 = F_98 ( 0 , V_102 ) ;
if ( ! V_16 -> V_88 ) {
F_70 ( & V_36 -> V_24 , L_31 ) ;
goto V_150;
}
V_125 = F_99 ( int , V_3 -> type -> V_156 ,
F_45 ( V_119 -> V_157 ) ) ;
V_16 -> V_156 = V_125 ;
V_16 -> V_158 = V_119 -> V_159 ;
V_16 -> V_96 = F_100 ( V_125 , V_102 ) ;
if ( ! V_16 -> V_96 ) {
F_70 ( & V_36 -> V_24 ,
L_32 ) ;
goto V_150;
}
F_101 ( V_16 -> V_88 , V_24 ,
F_102 ( V_24 ,
V_119 -> V_159 ) ,
V_16 -> V_96 , V_125 ,
V_3 -> type -> V_160 , V_16 ) ;
}
for ( V_11 = 0 ; V_11 < V_129 ; ++ V_11 ) {
int V_12 ;
V_119 = V_124 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_16 -> V_89 = F_98 ( 0 , V_102 ) ;
if ( ! V_16 -> V_89 ) {
F_70 ( & V_36 -> V_24 , L_31 ) ;
goto V_150;
}
if ( F_103 ( & V_16 -> V_95 , V_161 , V_102 ) )
goto V_150;
V_125 = V_3 -> type -> V_162 ;
if ( ! V_125 )
V_125 = F_45 ( V_119 -> V_157 ) ;
V_16 -> V_162 = V_125 ;
V_16 -> V_163 = V_119 -> V_159 ;
V_16 -> V_97 = F_100 ( V_125 , V_102 ) ;
if ( ! V_16 -> V_97 ) {
F_70 ( & V_36 -> V_24 ,
L_33 ) ;
goto V_150;
}
F_101 ( V_16 -> V_89 , V_24 ,
F_104 ( V_24 ,
V_119 -> V_159 ) ,
V_16 -> V_97 , V_125 ,
V_3 -> type -> V_164 , V_16 ) ;
for ( V_12 = 0 ; V_12 < F_61 ( V_16 -> V_90 ) ; ++ V_12 ) {
F_105 ( V_12 , & V_16 -> V_165 ) ;
V_16 -> V_90 [ V_12 ] = F_98 ( 0 , V_102 ) ;
if ( ! V_16 -> V_90 [ V_12 ] ) {
F_70 ( & V_36 -> V_24 ,
L_31 ) ;
goto V_150;
}
V_16 -> V_94 [ V_12 ] = F_100 ( V_125 ,
V_102 ) ;
if ( ! V_16 -> V_94 [ V_12 ] ) {
F_70 ( & V_36 -> V_24 ,
L_33 ) ;
goto V_150;
}
F_101 ( V_16 -> V_90 [ V_12 ] , V_24 ,
F_104 ( V_24 ,
V_119 -> V_159 ) ,
V_16 -> V_94 [ V_12 ] , V_125 ,
V_3 -> type -> V_164 ,
V_16 ) ;
}
}
if ( V_3 -> type -> V_166 ) {
for ( V_11 = 0 ; V_11 < V_126 ; ++ V_11 ) {
V_119 = V_120 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_16 -> V_91 = F_98 ( 0 , V_102 ) ;
if ( ! V_16 -> V_91 ) {
F_70 ( & V_36 -> V_24 ,
L_31 ) ;
goto V_150;
}
V_125 = F_45 ( V_119 -> V_157 ) ;
V_16 -> V_167 =
V_119 -> V_159 ;
V_16 -> V_98 = F_100 ( V_125 ,
V_102 ) ;
if ( ! V_16 -> V_98 ) {
F_70 ( & V_36 -> V_24 ,
L_34 ) ;
goto V_150;
}
F_106 ( V_16 -> V_91 , V_24 ,
F_107 ( V_24 ,
V_119 -> V_159 ) ,
V_16 -> V_98 , V_125 ,
V_3 -> type -> V_166 , V_16 ,
V_119 -> V_168 ) ;
}
} else if ( V_126 ) {
F_6 ( L_35 ) ;
}
if ( V_3 -> type -> V_169 ) {
for ( V_11 = 0 ; V_11 < V_127 ; ++ V_11 ) {
V_119 = V_122 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_16 -> V_92 = F_98 ( 0 , V_102 ) ;
if ( ! V_16 -> V_92 ) {
F_70 ( & V_36 -> V_24 ,
L_31 ) ;
goto V_150;
}
V_125 = F_45 ( V_119 -> V_157 ) ;
V_16 -> V_170 = V_125 ;
V_16 -> V_171 =
V_119 -> V_159 ;
V_16 -> V_99 = F_100 ( V_125 ,
V_102 ) ;
if ( ! V_16 -> V_99 ) {
F_70 ( & V_36 -> V_24 ,
L_36 ) ;
goto V_150;
}
F_106 ( V_16 -> V_92 , V_24 ,
F_108 ( V_24 ,
V_119 -> V_159 ) ,
V_16 -> V_99 , V_125 ,
V_3 -> type -> V_169 , V_16 ,
V_119 -> V_168 ) ;
}
} else if ( V_127 ) {
F_6 ( L_37 ) ;
}
if ( type -> V_172 ) {
V_30 = type -> V_172 ( V_3 ) ;
if ( V_30 < 0 )
goto V_150;
V_3 -> V_21 = 1 ;
if ( V_30 > 0 ) {
V_3 -> V_9 = 0 ;
goto exit;
}
} else {
V_3 -> V_21 = 1 ;
}
if ( F_5 ( V_3 , V_9 , & V_10 ) == NULL ) {
F_70 ( & V_36 -> V_24 , L_38 ) ;
goto V_150;
}
V_3 -> V_10 = V_10 ;
for ( V_11 = 0 ; V_11 < V_9 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
F_109 ( & V_16 -> V_24 , L_39 , V_16 -> V_17 ) ;
F_6 ( L_40 , V_14 , F_64 ( & V_16 -> V_24 ) ) ;
V_16 -> V_173 = V_174 ;
F_110 ( & V_16 -> V_24 ) ;
V_30 = F_111 ( & V_16 -> V_24 ) ;
if ( V_30 ) {
F_70 ( & V_16 -> V_24 , L_41
L_42 ) ;
V_16 -> V_173 = V_175 ;
} else {
V_16 -> V_173 = V_176 ;
}
}
F_112 ( V_177 , V_10 ) ;
exit:
F_113 ( V_36 , V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return 0 ;
V_150:
F_13 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_131 ;
}
void F_114 ( struct V_101 * V_36 )
{
int V_11 ;
struct V_1 * V_3 = F_115 ( V_36 ) ;
struct V_93 * V_24 = & V_36 -> V_24 ;
struct V_18 * V_16 ;
F_116 ( V_3 ) ;
F_6 ( L_3 , V_14 ) ;
F_2 ( & V_3 -> V_6 ) ;
F_113 ( V_36 , NULL ) ;
V_3 -> V_7 = 1 ;
F_3 ( & V_3 -> V_6 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
if ( V_16 ) {
struct V_27 * V_28 = F_56 ( & V_16 -> V_16 ) ;
if ( V_28 ) {
F_117 ( V_28 ) ;
F_58 ( V_28 ) ;
}
F_59 ( V_16 ) ;
F_65 ( & V_16 -> V_86 ) ;
if ( V_16 -> V_173 == V_176 ) {
if ( ! V_16 -> V_24 . V_26 ) {
int V_178 ;
V_16 -> V_24 . V_26 =
& V_3 -> type -> V_26 ;
V_178 = F_118 ( & V_16 -> V_24 ) ;
}
V_16 -> V_173 = V_179 ;
F_119 ( & V_16 -> V_24 ) ;
V_16 -> V_173 = V_175 ;
}
}
}
V_3 -> type -> V_180 ( V_3 ) ;
F_13 ( V_3 ) ;
F_91 ( V_24 , L_43 ) ;
}
int F_120 ( struct V_101 * V_104 , T_1 V_181 )
{
struct V_1 * V_3 = F_115 ( V_104 ) ;
struct V_18 * V_16 ;
int V_11 , V_182 = 0 ;
V_3 -> V_183 = 1 ;
if ( V_3 -> type -> V_184 ) {
V_182 = V_3 -> type -> V_184 ( V_3 , V_181 ) ;
if ( V_182 < 0 ) {
V_3 -> V_183 = 0 ;
goto V_185;
}
}
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
if ( V_16 )
F_59 ( V_16 ) ;
}
V_185:
return V_182 ;
}
int F_121 ( struct V_101 * V_104 )
{
struct V_1 * V_3 = F_115 ( V_104 ) ;
int V_186 ;
V_3 -> V_183 = 0 ;
if ( V_3 -> type -> V_187 )
V_186 = V_3 -> type -> V_187 ( V_3 ) ;
else
V_186 = F_122 ( V_3 ) ;
return V_186 ;
}
static int T_2 F_123 ( void )
{
int V_11 ;
int V_188 ;
V_189 = F_124 ( V_15 ) ;
if ( ! V_189 )
return - V_132 ;
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 )
V_5 [ V_11 ] = NULL ;
V_188 = F_125 ( & V_155 ) ;
if ( V_188 ) {
F_126 ( V_190 L_44
L_45 , V_14 ) ;
goto V_191;
}
V_189 -> V_33 = V_192 ;
V_189 -> V_193 = L_46 ;
V_189 -> V_194 = L_47 ;
V_189 -> V_195 = V_196 ;
V_189 -> V_197 = 0 ;
V_189 -> type = V_198 ;
V_189 -> V_199 = V_200 ;
V_189 -> V_201 = V_202 |
V_203 ;
V_189 -> V_38 = V_204 ;
V_189 -> V_38 . V_205 = V_206 | V_207 | V_208
| V_209 | V_210 ;
V_189 -> V_38 . V_211 = 9600 ;
V_189 -> V_38 . V_212 = 9600 ;
F_127 ( V_189 , & V_213 ) ;
V_188 = F_128 ( V_189 ) ;
if ( V_188 ) {
F_126 ( V_190 L_48 ,
V_14 ) ;
goto V_214;
}
V_188 = F_129 ( & V_47 ) ;
if ( V_188 < 0 ) {
F_126 ( V_190 L_49 ,
V_14 ) ;
goto V_215;
}
V_188 = F_130 ( V_177 ) ;
if ( V_188 < 0 ) {
F_126 ( V_190 L_50
L_51 , V_14 ) ;
goto V_216;
}
F_126 (KERN_INFO KBUILD_MODNAME L_52 DRIVER_DESC L_53 ) ;
return V_188 ;
V_216:
F_131 ( & V_47 ) ;
V_215:
F_132 ( V_189 ) ;
V_214:
F_133 ( & V_155 ) ;
V_191:
F_126 ( V_190 L_54 ,
V_14 , V_188 ) ;
F_134 ( V_189 ) ;
return V_188 ;
}
static void T_3 F_135 ( void )
{
F_136 () ;
F_137 () ;
F_131 ( & V_47 ) ;
F_132 ( V_189 ) ;
F_134 ( V_189 ) ;
F_133 ( & V_155 ) ;
}
static void F_138 ( struct V_47 * V_93 )
{
F_139 ( V_93 , V_44 ) ;
F_139 ( V_93 , V_55 ) ;
F_139 ( V_93 , V_50 ) ;
F_139 ( V_93 , V_56 ) ;
F_139 ( V_93 , V_57 ) ;
F_139 ( V_93 , V_160 ) ;
F_139 ( V_93 , V_164 ) ;
F_139 ( V_93 , V_180 ) ;
F_139 ( V_93 , V_22 ) ;
F_139 ( V_93 , V_217 ) ;
F_139 ( V_93 , V_218 ) ;
}
int F_140 ( struct V_47 * V_26 )
{
int V_30 ;
if ( F_141 () )
return - V_31 ;
F_138 ( V_26 ) ;
if ( ! V_26 -> V_19 )
V_26 -> V_19 = V_26 -> V_26 . V_194 ;
if ( ! V_26 -> V_219 ) {
F_142 ( 1 , L_55 ,
V_26 -> V_19 ) ;
return - V_79 ;
}
V_26 -> V_219 -> V_220 = 1 ;
F_2 ( & V_4 ) ;
F_143 ( & V_26 -> V_221 , & V_222 ) ;
V_30 = F_144 ( V_26 ) ;
if ( V_30 ) {
F_126 ( V_190 L_56
L_57 , V_30 , V_26 -> V_19 ) ;
F_145 ( & V_26 -> V_221 ) ;
} else
F_126 ( V_223 L_58 ,
V_26 -> V_19 ) ;
F_3 ( & V_4 ) ;
return V_30 ;
}
void F_146 ( struct V_47 * V_93 )
{
F_126 ( V_223 L_59 ,
V_93 -> V_19 ) ;
F_2 ( & V_4 ) ;
F_145 ( & V_93 -> V_221 ) ;
F_147 ( V_93 ) ;
F_3 ( & V_4 ) ;
}
