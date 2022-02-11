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
if ( V_3 -> V_22 )
V_3 -> type -> V_23 ( V_3 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_24 ; ++ V_11 ) {
V_18 = V_3 -> V_18 [ V_11 ] ;
if ( V_18 ) {
V_18 -> V_3 = NULL ;
F_10 ( & V_18 -> V_15 ) ;
}
}
F_11 ( V_3 -> V_15 ) ;
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
struct V_20 * V_18 ;
int V_30 = - V_31 ;
V_3 = F_1 ( V_29 ) ;
if ( ! V_3 )
return V_30 ;
V_18 = V_3 -> V_18 [ V_29 - V_3 -> V_10 ] ;
if ( ! V_18 )
goto V_32;
if ( ! F_16 ( V_3 -> type -> V_26 . V_33 ) )
goto V_34;
V_30 = F_17 ( V_3 -> V_14 ) ;
if ( V_30 )
goto V_35;
V_30 = F_18 ( & V_18 -> V_18 , V_26 , V_28 ) ;
if ( V_30 )
goto V_36;
F_3 ( & V_3 -> V_6 ) ;
if ( V_3 -> type -> V_37 )
V_3 -> type -> V_37 ( V_28 ) ;
V_28 -> V_38 = V_18 ;
return V_30 ;
V_36:
F_19 ( V_3 -> V_14 ) ;
V_35:
F_20 ( V_3 -> type -> V_26 . V_33 ) ;
V_34:
V_32:
F_13 ( V_3 ) ;
F_3 ( & V_3 -> V_6 ) ;
return V_30 ;
}
static int F_21 ( struct V_39 * V_40 , struct V_27 * V_28 )
{
struct V_20 * V_18 =
F_22 ( V_40 , struct V_20 , V_18 ) ;
struct V_1 * V_3 = V_18 -> V_3 ;
int V_30 ;
F_2 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_7 )
V_30 = - V_31 ;
else
V_30 = V_18 -> V_3 -> type -> V_41 ( V_28 , V_18 ) ;
F_3 ( & V_3 -> V_6 ) ;
if ( V_30 < 0 )
V_30 = F_23 ( V_30 ) ;
return V_30 ;
}
static int F_24 ( struct V_27 * V_28 , struct V_42 * V_43 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
return F_25 ( & V_18 -> V_18 , V_28 , V_43 ) ;
}
static void F_26 ( struct V_39 * V_40 )
{
struct V_20 * V_18 =
F_22 ( V_40 , struct V_20 , V_18 ) ;
struct V_44 * V_45 = V_18 -> V_3 -> type ;
if ( V_18 -> V_18 . V_46 )
return;
if ( V_45 -> V_47 )
V_45 -> V_47 ( V_18 ) ;
}
static void F_27 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
F_28 ( & V_18 -> V_18 ) ;
}
static void F_29 ( struct V_27 * V_28 , struct V_42 * V_43 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
F_30 ( & V_18 -> V_18 , V_28 , V_43 ) ;
}
static void F_31 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
struct V_1 * V_3 ;
struct V_48 * V_33 ;
if ( V_18 -> V_18 . V_46 )
return;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
V_28 -> V_38 = NULL ;
V_3 = V_18 -> V_3 ;
V_33 = V_3 -> type -> V_26 . V_33 ;
F_2 ( & V_3 -> V_6 ) ;
if ( ! V_3 -> V_7 )
F_19 ( V_3 -> V_14 ) ;
F_3 ( & V_3 -> V_6 ) ;
F_13 ( V_3 ) ;
F_20 ( V_33 ) ;
}
static int F_32 ( struct V_27 * V_28 , const unsigned char * V_49 ,
int V_50 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
int V_30 = - V_31 ;
if ( V_18 -> V_3 -> V_15 -> V_51 == V_52 )
goto exit;
F_6 ( V_28 -> V_15 , L_4 , V_16 ,
V_18 -> V_19 , V_50 ) ;
V_30 = V_18 -> V_3 -> type -> V_53 ( V_28 , V_18 , V_49 , V_50 ) ;
if ( V_30 < 0 )
V_30 = F_23 ( V_30 ) ;
exit:
return V_30 ;
}
static int F_33 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
return V_18 -> V_3 -> type -> V_54 ( V_28 ) ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
if ( V_18 -> V_3 -> V_7 )
return 0 ;
return V_18 -> V_3 -> type -> V_55 ( V_28 ) ;
}
static void F_35 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
if ( V_18 -> V_3 -> type -> V_56 )
V_18 -> V_3 -> type -> V_56 ( V_28 ) ;
}
static void F_36 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
if ( V_18 -> V_3 -> type -> V_57 )
V_18 -> V_3 -> type -> V_57 ( V_28 ) ;
}
static int F_37 ( struct V_27 * V_28 ,
unsigned int V_58 , unsigned long V_59 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
int V_30 = - V_31 ;
F_6 ( V_28 -> V_15 , L_5 , V_16 ,
V_18 -> V_19 , V_58 ) ;
if ( V_18 -> V_3 -> type -> V_60 ) {
V_30 = V_18 -> V_3 -> type -> V_60 ( V_28 , V_58 , V_59 ) ;
} else
V_30 = - V_61 ;
return V_30 ;
}
static void F_38 ( struct V_27 * V_28 , struct V_62 * V_63 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
if ( V_18 -> V_3 -> type -> V_64 )
V_18 -> V_3 -> type -> V_64 ( V_28 , V_18 , V_63 ) ;
else
F_39 ( & V_28 -> V_65 , V_63 ) ;
}
static int F_40 ( struct V_27 * V_28 , int V_66 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
if ( V_18 -> V_3 -> type -> V_67 )
V_18 -> V_3 -> type -> V_67 ( V_28 , V_66 ) ;
return 0 ;
}
static int F_41 ( struct V_68 * V_69 , void * V_70 )
{
struct V_1 * V_3 ;
int V_11 ;
char V_71 [ 40 ] ;
F_42 ( V_69 , L_6 ) ;
for ( V_11 = 0 ; V_11 < V_17 ; ++ V_11 ) {
V_3 = F_1 ( V_11 ) ;
if ( V_3 == NULL )
continue;
F_43 ( V_69 , L_7 , V_11 ) ;
if ( V_3 -> type -> V_26 . V_33 )
F_43 ( V_69 , L_8 ,
F_44 ( V_3 -> type -> V_26 . V_33 ) ) ;
F_43 ( V_69 , L_9 ,
V_3 -> type -> V_72 ) ;
F_43 ( V_69 , L_10 ,
F_45 ( V_3 -> V_15 -> V_73 . V_74 ) ,
F_45 ( V_3 -> V_15 -> V_73 . V_75 ) ) ;
F_43 ( V_69 , L_11 , V_3 -> V_9 ) ;
F_43 ( V_69 , L_12 , V_11 - V_3 -> V_10 + 1 ) ;
F_46 ( V_3 -> V_15 , V_71 , sizeof( V_71 ) ) ;
F_43 ( V_69 , L_13 , V_71 ) ;
F_47 ( V_69 , '\n' ) ;
F_13 ( V_3 ) ;
F_3 ( & V_3 -> V_6 ) ;
}
return 0 ;
}
static int F_48 ( struct V_76 * V_76 , struct V_42 * V_42 )
{
return F_49 ( V_42 , F_41 , NULL ) ;
}
static int F_50 ( struct V_27 * V_28 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
if ( V_18 -> V_3 -> type -> V_77 )
return V_18 -> V_3 -> type -> V_77 ( V_28 ) ;
return - V_78 ;
}
static int F_51 ( struct V_27 * V_28 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
if ( V_18 -> V_3 -> type -> V_81 )
return V_18 -> V_3 -> type -> V_81 ( V_28 , V_79 , V_80 ) ;
return - V_78 ;
}
static int F_52 ( struct V_27 * V_28 ,
struct V_82 * V_83 )
{
struct V_20 * V_18 = V_28 -> V_38 ;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
if ( V_18 -> V_3 -> type -> V_84 )
return V_18 -> V_3 -> type -> V_84 ( V_28 , V_83 ) ;
return - V_78 ;
}
void F_53 ( struct V_20 * V_18 )
{
F_54 ( & V_18 -> V_85 ) ;
}
static void F_55 ( struct V_86 * V_85 )
{
struct V_20 * V_18 =
F_22 ( V_85 , struct V_20 , V_85 ) ;
struct V_27 * V_28 ;
V_28 = F_56 ( & V_18 -> V_18 ) ;
if ( ! V_28 )
return;
F_6 ( V_28 -> V_15 , L_3 , V_16 , V_18 -> V_19 ) ;
F_57 ( V_28 ) ;
F_58 ( V_28 ) ;
}
static void F_59 ( struct V_20 * V_18 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_87 ) ; ++ V_11 )
F_61 ( V_18 -> V_87 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_88 ) ; ++ V_11 )
F_61 ( V_18 -> V_88 [ V_11 ] ) ;
F_61 ( V_18 -> V_89 ) ;
F_61 ( V_18 -> V_90 ) ;
F_61 ( V_18 -> V_91 ) ;
}
static void F_62 ( struct V_92 * V_15 )
{
struct V_20 * V_18 = F_63 ( V_15 ) ;
int V_11 ;
F_6 ( V_15 , L_14 , V_16 ) ;
F_59 ( V_18 ) ;
F_64 ( & V_18 -> V_85 ) ;
F_65 ( V_18 -> V_90 ) ;
F_65 ( V_18 -> V_91 ) ;
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_87 ) ; ++ V_11 ) {
F_65 ( V_18 -> V_87 [ V_11 ] ) ;
F_12 ( V_18 -> V_93 [ V_11 ] ) ;
}
for ( V_11 = 0 ; V_11 < F_60 ( V_18 -> V_88 ) ; ++ V_11 ) {
F_65 ( V_18 -> V_88 [ V_11 ] ) ;
F_12 ( V_18 -> V_94 [ V_11 ] ) ;
}
F_66 ( & V_18 -> V_95 ) ;
F_12 ( V_18 -> V_96 ) ;
F_12 ( V_18 -> V_97 ) ;
F_67 ( & V_18 -> V_18 ) ;
F_12 ( V_18 ) ;
}
static struct V_1 * F_68 ( struct V_98 * V_15 ,
struct V_99 * V_14 ,
struct V_44 * V_26 )
{
struct V_1 * V_3 ;
V_3 = F_69 ( sizeof( * V_3 ) , V_100 ) ;
if ( ! V_3 ) {
F_70 ( & V_15 -> V_15 , L_15 , V_16 ) ;
return NULL ;
}
V_3 -> V_15 = F_71 ( V_15 ) ;
V_3 -> type = V_26 ;
V_3 -> V_14 = V_14 ;
F_72 ( & V_3 -> V_8 ) ;
F_73 ( & V_3 -> V_6 ) ;
V_3 -> V_10 = V_21 ;
return V_3 ;
}
static const struct V_101 * F_74 ( struct V_99 * V_102 ,
struct V_44 * V_45 )
{
struct V_103 * V_104 ;
F_75 ( & V_45 -> V_105 . V_106 ) ;
F_76 (dynid, &drv->dynids.list, node) {
if ( F_77 ( V_102 , & V_104 -> V_107 ) ) {
F_78 ( & V_45 -> V_105 . V_106 ) ;
return & V_104 -> V_107 ;
}
}
F_78 ( & V_45 -> V_105 . V_106 ) ;
return NULL ;
}
static const struct V_101 * F_79 ( struct V_44 * V_45 ,
struct V_99 * V_102 )
{
const struct V_101 * V_107 ;
V_107 = F_80 ( V_102 , V_45 -> V_108 ) ;
if ( V_107 ) {
F_6 ( & V_102 -> V_15 , L_16 ) ;
goto exit;
}
V_107 = F_74 ( V_102 , V_45 ) ;
if ( V_107 )
F_6 ( & V_102 -> V_15 , L_17 ) ;
exit:
return V_107 ;
}
static struct V_44 * F_81 (
struct V_99 * V_109 )
{
const struct V_101 * V_107 = NULL ;
struct V_44 * V_45 ;
struct V_110 * V_26 = F_82 ( V_109 -> V_15 . V_26 ) ;
F_76 (drv, &usb_serial_driver_list, driver_list) {
if ( V_45 -> V_110 == V_26 )
V_107 = F_79 ( V_45 , V_109 ) ;
if ( V_107 )
return V_45 ;
}
return NULL ;
}
static int F_83 ( struct V_39 * V_18 )
{
struct V_20 * V_111 = F_22 ( V_18 , struct V_20 , V_18 ) ;
struct V_44 * V_45 = V_111 -> V_3 -> type ;
if ( V_45 -> V_112 )
return V_45 -> V_112 ( V_111 ) ;
return 1 ;
}
static void F_84 ( struct V_39 * V_18 , int V_113 )
{
struct V_20 * V_111 = F_22 ( V_18 , struct V_20 , V_18 ) ;
struct V_44 * V_45 = V_111 -> V_3 -> type ;
if ( V_45 -> V_114 )
V_45 -> V_114 ( V_111 , V_113 ) ;
}
static int F_85 ( struct V_99 * V_14 ,
const struct V_101 * V_107 )
{
struct V_92 * V_115 = & V_14 -> V_15 ;
struct V_98 * V_15 = F_86 ( V_14 ) ;
struct V_1 * V_3 = NULL ;
struct V_20 * V_18 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_118 * V_120 [ V_121 ] ;
struct V_118 * V_122 [ V_121 ] ;
struct V_118 * V_123 [ V_121 ] ;
struct V_118 * V_124 [ V_121 ] ;
struct V_44 * type = NULL ;
int V_30 ;
unsigned int V_10 ;
int V_125 ;
int V_11 ;
int V_12 ;
int V_126 = 0 ;
int V_127 = 0 ;
int V_128 = 0 ;
int V_129 = 0 ;
int V_9 = 0 ;
int V_130 ;
F_2 ( & V_4 ) ;
type = F_81 ( V_14 ) ;
if ( ! type ) {
F_3 ( & V_4 ) ;
F_6 ( V_115 , L_18 ) ;
return - V_31 ;
}
if ( ! F_16 ( type -> V_26 . V_33 ) ) {
F_3 ( & V_4 ) ;
F_70 ( V_115 , L_19 ) ;
return - V_131 ;
}
F_3 ( & V_4 ) ;
V_3 = F_68 ( V_15 , V_14 , type ) ;
if ( ! V_3 ) {
F_20 ( type -> V_26 . V_33 ) ;
F_70 ( V_115 , L_15 , V_16 ) ;
return - V_132 ;
}
if ( type -> V_133 ) {
const struct V_101 * V_107 ;
V_107 = F_79 ( type , V_14 ) ;
V_30 = type -> V_133 ( V_3 , V_107 ) ;
if ( V_30 ) {
F_6 ( V_115 , L_20 ) ;
F_13 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return V_30 ;
}
}
V_117 = V_14 -> V_134 ;
for ( V_11 = 0 ; V_11 < V_117 -> V_135 . V_136 ; ++ V_11 ) {
V_119 = & V_117 -> V_119 [ V_11 ] . V_135 ;
if ( F_87 ( V_119 ) ) {
F_6 ( V_115 , L_21 , V_11 ) ;
V_123 [ V_128 ] = V_119 ;
++ V_128 ;
}
if ( F_88 ( V_119 ) ) {
F_6 ( V_115 , L_22 , V_11 ) ;
V_124 [ V_129 ] = V_119 ;
++ V_129 ;
}
if ( F_89 ( V_119 ) ) {
F_6 ( V_115 , L_23 , V_11 ) ;
V_120 [ V_126 ] = V_119 ;
++ V_126 ;
}
if ( F_90 ( V_119 ) ) {
F_6 ( V_115 , L_24 , V_11 ) ;
V_122 [ V_127 ] = V_119 ;
++ V_127 ;
}
}
#if F_91 ( V_137 ) || F_91 ( V_138 )
if ( ( ( F_45 ( V_15 -> V_73 . V_74 ) == V_139 ) &&
( F_45 ( V_15 -> V_73 . V_75 ) == V_140 ) ) ||
( ( F_45 ( V_15 -> V_73 . V_74 ) == V_141 ) &&
( F_45 ( V_15 -> V_73 . V_75 ) == V_142 ) ) ||
( ( F_45 ( V_15 -> V_73 . V_74 ) == V_143 ) &&
( F_45 ( V_15 -> V_73 . V_75 ) == V_144 ) ) ||
( ( F_45 ( V_15 -> V_73 . V_74 ) == V_145 ) &&
( F_45 ( V_15 -> V_73 . V_75 ) == V_146 ) ) ) {
if ( V_14 != V_15 -> V_147 -> V_14 [ 0 ] ) {
V_117 = V_15 -> V_147 -> V_14 [ 0 ] -> V_134 ;
for ( V_11 = 0 ; V_11 < V_117 -> V_135 . V_136 ; ++ V_11 ) {
V_119 = & V_117 -> V_119 [ V_11 ] . V_135 ;
if ( F_89 ( V_119 ) ) {
F_6 ( V_115 , L_25 ) ;
V_120 [ V_126 ] = V_119 ;
++ V_126 ;
}
}
}
if ( V_128 == 0 || V_129 == 0 ) {
F_92 ( V_115 , L_26 ) ;
F_13 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_31 ;
}
}
#endif
#ifdef F_93
if ( type == & V_148 ) {
V_9 = V_129 ;
if ( V_9 == 0 ) {
F_70 ( V_115 , L_27 ) ;
F_13 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_131 ;
}
F_92 ( V_115 , L_28 ) ;
F_92 ( V_115 , L_29 ) ;
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
F_92 ( V_115 , L_30 , type -> V_72 ) ;
V_130 = F_94 ( V_128 , V_129 ) ;
V_130 = F_94 ( V_130 , V_126 ) ;
V_130 = F_94 ( V_130 , V_127 ) ;
V_130 = F_94 ( V_130 , ( int ) V_3 -> V_9 ) ;
V_3 -> V_24 = V_130 ;
F_6 ( V_115 , L_31 , V_130 ) ;
for ( V_11 = 0 ; V_11 < V_130 ; ++ V_11 ) {
V_18 = F_69 ( sizeof( struct V_20 ) , V_100 ) ;
if ( ! V_18 )
goto V_150;
F_95 ( & V_18 -> V_18 ) ;
V_18 -> V_18 . V_151 = & V_152 ;
V_18 -> V_3 = V_3 ;
F_96 ( & V_18 -> V_106 ) ;
F_97 ( & V_18 -> V_85 , F_55 ) ;
V_3 -> V_18 [ V_11 ] = V_18 ;
V_18 -> V_15 . V_153 = & V_14 -> V_15 ;
V_18 -> V_15 . V_26 = NULL ;
V_18 -> V_15 . V_154 = & V_155 ;
V_18 -> V_15 . V_23 = & F_62 ;
F_98 ( & V_18 -> V_15 ) ;
}
for ( V_11 = 0 ; V_11 < V_128 ; ++ V_11 ) {
V_119 = V_123 [ V_11 ] ;
V_18 = V_3 -> V_18 [ V_11 ] ;
V_125 = F_99 ( int , V_3 -> type -> V_156 ,
F_100 ( V_119 ) ) ;
V_18 -> V_156 = V_125 ;
V_18 -> V_157 = V_119 -> V_158 ;
for ( V_12 = 0 ; V_12 < F_60 ( V_18 -> V_87 ) ; ++ V_12 ) {
F_101 ( V_12 , & V_18 -> V_159 ) ;
V_18 -> V_87 [ V_12 ] = F_102 ( 0 , V_100 ) ;
if ( ! V_18 -> V_87 [ V_12 ] ) {
F_70 ( V_115 , L_32 ) ;
goto V_150;
}
V_18 -> V_93 [ V_12 ] = F_103 ( V_125 ,
V_100 ) ;
if ( ! V_18 -> V_93 [ V_12 ] ) {
F_70 ( V_115 , L_33 ) ;
goto V_150;
}
F_104 ( V_18 -> V_87 [ V_12 ] , V_15 ,
F_105 ( V_15 ,
V_119 -> V_158 ) ,
V_18 -> V_93 [ V_12 ] , V_125 ,
V_3 -> type -> V_160 ,
V_18 ) ;
}
V_18 -> V_89 = V_18 -> V_87 [ 0 ] ;
V_18 -> V_161 = V_18 -> V_93 [ 0 ] ;
}
for ( V_11 = 0 ; V_11 < V_129 ; ++ V_11 ) {
V_119 = V_124 [ V_11 ] ;
V_18 = V_3 -> V_18 [ V_11 ] ;
if ( F_106 ( & V_18 -> V_95 , V_162 , V_100 ) )
goto V_150;
V_125 = V_3 -> type -> V_163 ;
if ( ! V_125 )
V_125 = F_100 ( V_119 ) ;
V_18 -> V_163 = V_125 ;
V_18 -> V_164 = V_119 -> V_158 ;
for ( V_12 = 0 ; V_12 < F_60 ( V_18 -> V_88 ) ; ++ V_12 ) {
F_101 ( V_12 , & V_18 -> V_165 ) ;
V_18 -> V_88 [ V_12 ] = F_102 ( 0 , V_100 ) ;
if ( ! V_18 -> V_88 [ V_12 ] ) {
F_70 ( V_115 , L_32 ) ;
goto V_150;
}
V_18 -> V_94 [ V_12 ] = F_103 ( V_125 ,
V_100 ) ;
if ( ! V_18 -> V_94 [ V_12 ] ) {
F_70 ( V_115 , L_34 ) ;
goto V_150;
}
F_104 ( V_18 -> V_88 [ V_12 ] , V_15 ,
F_107 ( V_15 ,
V_119 -> V_158 ) ,
V_18 -> V_94 [ V_12 ] , V_125 ,
V_3 -> type -> V_166 ,
V_18 ) ;
}
V_18 -> V_167 = V_18 -> V_88 [ 0 ] ;
V_18 -> V_168 = V_18 -> V_94 [ 0 ] ;
}
if ( V_3 -> type -> V_169 ) {
for ( V_11 = 0 ; V_11 < V_126 ; ++ V_11 ) {
V_119 = V_120 [ V_11 ] ;
V_18 = V_3 -> V_18 [ V_11 ] ;
V_18 -> V_90 = F_102 ( 0 , V_100 ) ;
if ( ! V_18 -> V_90 ) {
F_70 ( V_115 , L_32 ) ;
goto V_150;
}
V_125 = F_100 ( V_119 ) ;
V_18 -> V_170 =
V_119 -> V_158 ;
V_18 -> V_96 = F_103 ( V_125 ,
V_100 ) ;
if ( ! V_18 -> V_96 ) {
F_70 ( V_115 , L_35 ) ;
goto V_150;
}
F_108 ( V_18 -> V_90 , V_15 ,
F_109 ( V_15 ,
V_119 -> V_158 ) ,
V_18 -> V_96 , V_125 ,
V_3 -> type -> V_169 , V_18 ,
V_119 -> V_171 ) ;
}
} else if ( V_126 ) {
F_6 ( V_115 , L_36 ) ;
}
if ( V_3 -> type -> V_172 ) {
for ( V_11 = 0 ; V_11 < V_127 ; ++ V_11 ) {
V_119 = V_122 [ V_11 ] ;
V_18 = V_3 -> V_18 [ V_11 ] ;
V_18 -> V_91 = F_102 ( 0 , V_100 ) ;
if ( ! V_18 -> V_91 ) {
F_70 ( V_115 , L_32 ) ;
goto V_150;
}
V_125 = F_100 ( V_119 ) ;
V_18 -> V_173 = V_125 ;
V_18 -> V_174 =
V_119 -> V_158 ;
V_18 -> V_97 = F_103 ( V_125 ,
V_100 ) ;
if ( ! V_18 -> V_97 ) {
F_70 ( V_115 , L_37 ) ;
goto V_150;
}
F_108 ( V_18 -> V_91 , V_15 ,
F_110 ( V_15 ,
V_119 -> V_158 ) ,
V_18 -> V_97 , V_125 ,
V_3 -> type -> V_172 , V_18 ,
V_119 -> V_171 ) ;
}
} else if ( V_127 ) {
F_6 ( V_115 , L_38 ) ;
}
F_111 ( V_14 , V_3 ) ;
if ( type -> V_175 ) {
V_30 = type -> V_175 ( V_3 ) ;
if ( V_30 < 0 )
goto V_150;
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
F_70 ( V_115 , L_39 ) ;
goto V_150;
}
V_3 -> V_10 = V_10 ;
for ( V_11 = 0 ; V_11 < V_9 ; ++ V_11 ) {
V_18 = V_3 -> V_18 [ V_11 ] ;
F_112 ( & V_18 -> V_15 , L_40 , V_18 -> V_19 ) ;
F_6 ( V_115 , L_41 , F_113 ( & V_18 -> V_15 ) ) ;
F_114 ( & V_18 -> V_15 ) ;
V_30 = F_115 ( & V_18 -> V_15 ) ;
if ( V_30 )
F_70 ( V_115 , L_42 ) ;
}
V_3 -> V_7 = 0 ;
F_116 ( V_10 ) ;
exit:
F_20 ( type -> V_26 . V_33 ) ;
return 0 ;
V_150:
F_13 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_131 ;
}
static void F_117 ( struct V_99 * V_14 )
{
int V_11 ;
struct V_1 * V_3 = F_118 ( V_14 ) ;
struct V_92 * V_15 = & V_14 -> V_15 ;
struct V_20 * V_18 ;
F_119 ( V_3 ) ;
F_2 ( & V_3 -> V_6 ) ;
V_3 -> V_7 = 1 ;
F_3 ( & V_3 -> V_6 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_18 = V_3 -> V_18 [ V_11 ] ;
if ( V_18 ) {
struct V_27 * V_28 = F_56 ( & V_18 -> V_18 ) ;
if ( V_28 ) {
F_120 ( V_28 ) ;
F_58 ( V_28 ) ;
}
F_59 ( V_18 ) ;
F_64 ( & V_18 -> V_85 ) ;
if ( F_121 ( & V_18 -> V_15 ) )
F_122 ( & V_18 -> V_15 ) ;
}
}
V_3 -> type -> V_176 ( V_3 ) ;
F_13 ( V_3 ) ;
F_92 ( V_15 , L_43 ) ;
}
int F_123 ( struct V_99 * V_102 , T_1 V_177 )
{
struct V_1 * V_3 = F_118 ( V_102 ) ;
struct V_20 * V_18 ;
int V_11 , V_178 = 0 ;
V_3 -> V_179 = 1 ;
if ( V_3 -> type -> V_180 ) {
V_178 = V_3 -> type -> V_180 ( V_3 , V_177 ) ;
if ( V_178 < 0 ) {
V_3 -> V_179 = 0 ;
goto V_181;
}
}
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_18 = V_3 -> V_18 [ V_11 ] ;
if ( V_18 )
F_59 ( V_18 ) ;
}
V_181:
return V_178 ;
}
int F_124 ( struct V_99 * V_102 )
{
struct V_1 * V_3 = F_118 ( V_102 ) ;
int V_182 ;
V_3 -> V_179 = 0 ;
if ( V_3 -> type -> V_183 )
V_182 = V_3 -> type -> V_183 ( V_3 ) ;
else
V_182 = F_125 ( V_3 ) ;
return V_182 ;
}
static int F_126 ( struct V_99 * V_102 )
{
struct V_1 * V_3 = F_118 ( V_102 ) ;
int V_182 ;
V_3 -> V_179 = 0 ;
if ( V_3 -> type -> V_184 )
V_182 = V_3 -> type -> V_184 ( V_3 ) ;
else {
V_182 = - V_185 ;
V_102 -> V_186 = 1 ;
}
return V_182 ;
}
static int T_2 F_127 ( void )
{
int V_11 ;
int V_187 ;
V_188 = F_128 ( V_17 ) ;
if ( ! V_188 )
return - V_132 ;
for ( V_11 = 0 ; V_11 < V_17 ; ++ V_11 )
V_5 [ V_11 ] = NULL ;
V_187 = F_129 ( & V_155 ) ;
if ( V_187 ) {
F_130 ( L_44 , V_16 ) ;
goto V_189;
}
V_188 -> V_190 = L_45 ;
V_188 -> V_191 = L_46 ;
V_188 -> V_192 = V_193 ;
V_188 -> V_194 = 0 ;
V_188 -> type = V_195 ;
V_188 -> V_196 = V_197 ;
V_188 -> V_198 = V_199 |
V_200 ;
V_188 -> V_37 = V_201 ;
V_188 -> V_37 . V_202 = V_203 | V_204 | V_205
| V_206 | V_207 ;
V_188 -> V_37 . V_208 = 9600 ;
V_188 -> V_37 . V_209 = 9600 ;
F_131 ( V_188 , & V_210 ) ;
V_187 = F_132 ( V_188 ) ;
if ( V_187 ) {
F_130 ( L_47 , V_16 ) ;
goto V_211;
}
V_187 = F_133 ( & V_44 ) ;
if ( V_187 < 0 ) {
F_130 ( L_48 , V_16 ) ;
goto V_212;
}
V_187 = F_134 () ;
if ( V_187 < 0 ) {
F_130 ( L_49 , V_16 ) ;
goto V_213;
}
return V_187 ;
V_213:
F_135 ( & V_44 ) ;
V_212:
F_136 ( V_188 ) ;
V_211:
F_137 ( & V_155 ) ;
V_189:
F_130 ( L_50 , V_16 , V_187 ) ;
F_138 ( V_188 ) ;
return V_187 ;
}
static void T_3 F_139 ( void )
{
F_140 () ;
F_141 () ;
F_135 ( & V_44 ) ;
F_136 ( V_188 ) ;
F_138 ( V_188 ) ;
F_137 ( & V_155 ) ;
}
static void F_142 ( struct V_44 * V_92 )
{
F_143 ( V_92 , V_41 ) ;
F_143 ( V_92 , V_53 ) ;
F_143 ( V_92 , V_47 ) ;
F_143 ( V_92 , V_54 ) ;
F_143 ( V_92 , V_55 ) ;
F_143 ( V_92 , V_160 ) ;
F_143 ( V_92 , V_166 ) ;
F_143 ( V_92 , V_176 ) ;
F_143 ( V_92 , V_23 ) ;
F_143 ( V_92 , V_214 ) ;
F_143 ( V_92 , V_215 ) ;
}
static int F_144 ( struct V_44 * V_26 )
{
int V_30 ;
if ( F_145 () )
return - V_31 ;
F_142 ( V_26 ) ;
if ( ! V_26 -> V_72 )
V_26 -> V_72 = V_26 -> V_26 . V_191 ;
if ( ! V_26 -> V_110 ) {
F_146 ( 1 , L_51 ,
V_26 -> V_72 ) ;
return - V_78 ;
}
F_2 ( & V_4 ) ;
F_147 ( & V_26 -> V_216 , & V_217 ) ;
V_30 = F_148 ( V_26 ) ;
if ( V_30 ) {
F_130 ( L_52 , V_30 , V_26 -> V_72 ) ;
F_149 ( & V_26 -> V_216 ) ;
} else
F_150 ( L_53 , V_26 -> V_72 ) ;
F_3 ( & V_4 ) ;
return V_30 ;
}
static void F_151 ( struct V_44 * V_92 )
{
F_150 ( L_54 , V_92 -> V_72 ) ;
F_2 ( & V_4 ) ;
F_149 ( & V_92 -> V_216 ) ;
F_152 ( V_92 ) ;
F_3 ( & V_4 ) ;
}
int F_153 ( struct V_44 * const V_218 [] ,
const char * V_191 ,
const struct V_101 * V_108 )
{
int V_219 ;
struct V_110 * V_220 ;
struct V_44 * const * V_221 ;
V_220 = F_69 ( sizeof( * V_220 ) , V_100 ) ;
if ( ! V_220 )
return - V_132 ;
V_220 -> V_191 = V_191 ;
V_220 -> V_222 = 1 ;
V_220 -> V_223 = 1 ;
V_220 -> V_180 = F_123 ;
V_220 -> V_183 = F_124 ;
V_220 -> V_133 = F_85 ;
V_220 -> V_176 = F_117 ;
for ( V_221 = V_218 ; * V_221 ; ++ V_221 ) {
if ( ( * V_221 ) -> V_184 ) {
V_220 -> V_184 = F_126 ;
break;
}
}
V_219 = F_133 ( V_220 ) ;
if ( V_219 )
return V_219 ;
for ( V_221 = V_218 ; * V_221 ; ++ V_221 ) {
( * V_221 ) -> V_110 = V_220 ;
V_219 = F_144 ( * V_221 ) ;
if ( V_219 )
goto V_224;
}
V_220 -> V_108 = V_108 ;
V_219 = F_154 ( & V_220 -> V_225 . V_26 ) ;
return 0 ;
V_224:
while ( V_221 -- > V_218 )
F_151 ( * V_221 ) ;
F_135 ( V_220 ) ;
return V_219 ;
}
void F_155 ( struct V_44 * const V_218 [] )
{
struct V_110 * V_220 = ( * V_218 ) -> V_110 ;
for (; * V_218 ; ++ V_218 )
F_151 ( * V_218 ) ;
F_135 ( V_220 ) ;
F_12 ( V_220 ) ;
}
