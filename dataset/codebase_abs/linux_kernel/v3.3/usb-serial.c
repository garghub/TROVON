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
if ( V_30 < 0 )
V_30 = F_23 ( V_30 ) ;
return V_30 ;
}
static int F_24 ( struct V_27 * V_28 , struct V_45 * V_46 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
return F_25 ( & V_16 -> V_16 , V_28 , V_46 ) ;
}
static void F_26 ( struct V_42 * V_43 )
{
struct V_18 * V_16 =
F_22 ( V_43 , struct V_18 , V_16 ) ;
struct V_47 * V_48 = V_16 -> V_3 -> type ;
if ( V_16 -> V_16 . V_49 )
return;
if ( V_48 -> V_50 )
V_48 -> V_50 ( V_16 ) ;
}
static void F_27 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
F_28 ( & V_16 -> V_16 ) ;
}
static void F_29 ( struct V_27 * V_28 , struct V_45 * V_46 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
F_30 ( & V_16 -> V_16 , V_28 , V_46 ) ;
}
static void F_31 ( struct V_27 * V_28 )
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
F_32 ( V_3 -> V_36 ) ;
F_3 ( & V_3 -> V_6 ) ;
F_13 ( V_3 ) ;
F_20 ( V_33 ) ;
}
static int F_33 ( struct V_27 * V_28 , const unsigned char * V_52 ,
int V_40 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
int V_30 = - V_31 ;
if ( V_16 -> V_3 -> V_24 -> V_53 == V_54 )
goto exit;
F_6 ( L_6 , V_14 , V_16 -> V_17 , V_40 ) ;
V_30 = V_16 -> V_3 -> type -> V_55 ( V_28 , V_16 , V_52 , V_40 ) ;
if ( V_30 < 0 )
V_30 = F_23 ( V_30 ) ;
exit:
return V_30 ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
return V_16 -> V_3 -> type -> V_56 ( V_28 ) ;
}
static int F_35 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> V_7 )
return 0 ;
return V_16 -> V_3 -> type -> V_57 ( V_28 ) ;
}
static void F_36 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_58 )
V_16 -> V_3 -> type -> V_58 ( V_28 ) ;
}
static void F_37 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_59 )
V_16 -> V_3 -> type -> V_59 ( V_28 ) ;
}
static int F_38 ( struct V_27 * V_28 ,
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
static void F_39 ( struct V_27 * V_28 , struct V_64 * V_65 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_66 )
V_16 -> V_3 -> type -> V_66 ( V_28 , V_16 , V_65 ) ;
else
F_40 ( V_28 -> V_67 , V_65 ) ;
}
static int F_41 ( struct V_27 * V_28 , int V_68 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_69 )
V_16 -> V_3 -> type -> V_69 ( V_28 , V_68 ) ;
return 0 ;
}
static int F_42 ( struct V_70 * V_71 , void * V_72 )
{
struct V_1 * V_3 ;
int V_11 ;
char V_73 [ 40 ] ;
F_6 ( L_3 , V_14 ) ;
F_43 ( V_71 , L_8 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 ) {
V_3 = F_1 ( V_11 ) ;
if ( V_3 == NULL )
continue;
F_44 ( V_71 , L_9 , V_11 ) ;
if ( V_3 -> type -> V_26 . V_33 )
F_44 ( V_71 , L_10 ,
F_45 ( V_3 -> type -> V_26 . V_33 ) ) ;
F_44 ( V_71 , L_11 ,
V_3 -> type -> V_19 ) ;
F_44 ( V_71 , L_12 ,
F_46 ( V_3 -> V_24 -> V_74 . V_75 ) ,
F_46 ( V_3 -> V_24 -> V_74 . V_76 ) ) ;
F_44 ( V_71 , L_13 , V_3 -> V_9 ) ;
F_44 ( V_71 , L_14 , V_11 - V_3 -> V_10 + 1 ) ;
F_47 ( V_3 -> V_24 , V_73 , sizeof( V_73 ) ) ;
F_44 ( V_71 , L_15 , V_73 ) ;
F_48 ( V_71 , '\n' ) ;
F_13 ( V_3 ) ;
F_3 ( & V_3 -> V_6 ) ;
}
return 0 ;
}
static int F_49 ( struct V_77 * V_77 , struct V_45 * V_45 )
{
return F_50 ( V_45 , F_42 , NULL ) ;
}
static int F_51 ( struct V_27 * V_28 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_78 )
return V_16 -> V_3 -> type -> V_78 ( V_28 ) ;
return - V_79 ;
}
static int F_52 ( struct V_27 * V_28 ,
unsigned int V_80 , unsigned int V_81 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_82 )
return V_16 -> V_3 -> type -> V_82 ( V_28 , V_80 , V_81 ) ;
return - V_79 ;
}
static int F_53 ( struct V_27 * V_28 ,
struct V_83 * V_84 )
{
struct V_18 * V_16 = V_28 -> V_39 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
if ( V_16 -> V_3 -> type -> V_85 )
return V_16 -> V_3 -> type -> V_85 ( V_28 , V_84 ) ;
return - V_79 ;
}
void F_54 ( struct V_18 * V_16 )
{
F_55 ( & V_16 -> V_86 ) ;
}
static void F_56 ( struct V_87 * V_86 )
{
struct V_18 * V_16 =
F_22 ( V_86 , struct V_18 , V_86 ) ;
struct V_27 * V_28 ;
F_6 ( L_5 , V_14 , V_16 -> V_17 ) ;
V_28 = F_57 ( & V_16 -> V_16 ) ;
if ( ! V_28 )
return;
F_58 ( V_28 ) ;
F_59 ( V_28 ) ;
}
static void F_60 ( struct V_18 * V_16 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_61 ( V_16 -> V_88 ) ; ++ V_11 )
F_62 ( V_16 -> V_88 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < F_61 ( V_16 -> V_89 ) ; ++ V_11 )
F_62 ( V_16 -> V_89 [ V_11 ] ) ;
F_62 ( V_16 -> V_90 ) ;
F_62 ( V_16 -> V_91 ) ;
F_62 ( V_16 -> V_92 ) ;
}
static void F_63 ( struct V_93 * V_24 )
{
struct V_18 * V_16 = F_64 ( V_24 ) ;
int V_11 ;
F_6 ( L_4 , V_14 , F_65 ( V_24 ) ) ;
F_60 ( V_16 ) ;
F_66 ( & V_16 -> V_86 ) ;
F_67 ( V_16 -> V_91 ) ;
F_67 ( V_16 -> V_92 ) ;
for ( V_11 = 0 ; V_11 < F_61 ( V_16 -> V_88 ) ; ++ V_11 ) {
F_67 ( V_16 -> V_88 [ V_11 ] ) ;
F_12 ( V_16 -> V_94 [ V_11 ] ) ;
}
for ( V_11 = 0 ; V_11 < F_61 ( V_16 -> V_89 ) ; ++ V_11 ) {
F_67 ( V_16 -> V_89 [ V_11 ] ) ;
F_12 ( V_16 -> V_95 [ V_11 ] ) ;
}
F_68 ( & V_16 -> V_96 ) ;
F_12 ( V_16 -> V_97 ) ;
F_12 ( V_16 -> V_98 ) ;
F_12 ( V_16 ) ;
}
static struct V_1 * F_69 ( struct V_99 * V_24 ,
struct V_100 * V_36 ,
struct V_47 * V_26 )
{
struct V_1 * V_3 ;
V_3 = F_70 ( sizeof( * V_3 ) , V_101 ) ;
if ( ! V_3 ) {
F_71 ( & V_24 -> V_24 , L_16 , V_14 ) ;
return NULL ;
}
V_3 -> V_24 = F_72 ( V_24 ) ;
V_3 -> type = V_26 ;
V_3 -> V_36 = V_36 ;
F_73 ( & V_3 -> V_8 ) ;
F_74 ( & V_3 -> V_6 ) ;
V_3 -> V_10 = V_20 ;
return V_3 ;
}
static const struct V_102 * F_75 ( struct V_100 * V_103 ,
struct V_47 * V_48 )
{
struct V_104 * V_105 ;
F_76 ( & V_48 -> V_106 . V_107 ) ;
F_77 (dynid, &drv->dynids.list, node) {
if ( F_78 ( V_103 , & V_105 -> V_108 ) ) {
F_79 ( & V_48 -> V_106 . V_107 ) ;
return & V_105 -> V_108 ;
}
}
F_79 ( & V_48 -> V_106 . V_107 ) ;
return NULL ;
}
static const struct V_102 * F_80 ( struct V_47 * V_48 ,
struct V_100 * V_103 )
{
const struct V_102 * V_108 ;
V_108 = F_81 ( V_103 , V_48 -> V_109 ) ;
if ( V_108 ) {
F_6 ( L_17 ) ;
goto exit;
}
V_108 = F_75 ( V_103 , V_48 ) ;
if ( V_108 )
F_6 ( L_18 ) ;
exit:
return V_108 ;
}
static struct V_47 * F_82 (
struct V_100 * V_110 )
{
const struct V_102 * V_108 ;
struct V_47 * V_48 ;
F_77 (drv, &usb_serial_driver_list, driver_list) {
V_108 = F_80 ( V_48 , V_110 ) ;
if ( V_108 )
return V_48 ;
}
return NULL ;
}
static int F_83 ( struct V_42 * V_16 )
{
struct V_18 * V_111 = F_22 ( V_16 , struct V_18 , V_16 ) ;
struct V_47 * V_48 = V_111 -> V_3 -> type ;
if ( V_48 -> V_112 )
return V_48 -> V_112 ( V_111 ) ;
return 1 ;
}
static void F_84 ( struct V_42 * V_16 , int V_113 )
{
struct V_18 * V_111 = F_22 ( V_16 , struct V_18 , V_16 ) ;
struct V_47 * V_48 = V_111 -> V_3 -> type ;
if ( V_48 -> V_114 )
V_48 -> V_114 ( V_111 , V_113 ) ;
}
int F_85 ( struct V_100 * V_36 ,
const struct V_102 * V_108 )
{
struct V_99 * V_24 = F_86 ( V_36 ) ;
struct V_1 * V_3 = NULL ;
struct V_18 * V_16 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
struct V_117 * V_119 [ V_120 ] ;
struct V_117 * V_121 [ V_120 ] ;
struct V_117 * V_122 [ V_120 ] ;
struct V_117 * V_123 [ V_120 ] ;
struct V_47 * type = NULL ;
int V_30 ;
unsigned int V_10 ;
int V_124 ;
int V_11 ;
int V_12 ;
int V_125 = 0 ;
int V_126 = 0 ;
int V_127 = 0 ;
int V_128 = 0 ;
int V_9 = 0 ;
int V_129 ;
F_2 ( & V_4 ) ;
type = F_82 ( V_36 ) ;
if ( ! type ) {
F_3 ( & V_4 ) ;
F_6 ( L_19 ) ;
return - V_31 ;
}
if ( ! F_16 ( type -> V_26 . V_33 ) ) {
F_3 ( & V_4 ) ;
F_71 ( & V_36 -> V_24 , L_20 ) ;
return - V_130 ;
}
F_3 ( & V_4 ) ;
V_3 = F_69 ( V_24 , V_36 , type ) ;
if ( ! V_3 ) {
F_20 ( type -> V_26 . V_33 ) ;
F_71 ( & V_36 -> V_24 , L_16 , V_14 ) ;
return - V_131 ;
}
if ( type -> V_132 ) {
const struct V_102 * V_108 ;
V_108 = F_80 ( type , V_36 ) ;
V_30 = type -> V_132 ( V_3 , V_108 ) ;
if ( V_30 ) {
F_6 ( L_21 ) ;
F_12 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return V_30 ;
}
}
V_116 = V_36 -> V_133 ;
for ( V_11 = 0 ; V_11 < V_116 -> V_134 . V_135 ; ++ V_11 ) {
V_118 = & V_116 -> V_118 [ V_11 ] . V_134 ;
if ( F_87 ( V_118 ) ) {
F_6 ( L_22 , V_11 ) ;
V_122 [ V_127 ] = V_118 ;
++ V_127 ;
}
if ( F_88 ( V_118 ) ) {
F_6 ( L_23 , V_11 ) ;
V_123 [ V_128 ] = V_118 ;
++ V_128 ;
}
if ( F_89 ( V_118 ) ) {
F_6 ( L_24 , V_11 ) ;
V_119 [ V_125 ] = V_118 ;
++ V_125 ;
}
if ( F_90 ( V_118 ) ) {
F_6 ( L_25 , V_11 ) ;
V_121 [ V_126 ] = V_118 ;
++ V_126 ;
}
}
#if F_91 ( V_136 ) || F_91 ( V_137 )
if ( ( ( F_46 ( V_24 -> V_74 . V_75 ) == V_138 ) &&
( F_46 ( V_24 -> V_74 . V_76 ) == V_139 ) ) ||
( ( F_46 ( V_24 -> V_74 . V_75 ) == V_140 ) &&
( F_46 ( V_24 -> V_74 . V_76 ) == V_141 ) ) ||
( ( F_46 ( V_24 -> V_74 . V_75 ) == V_142 ) &&
( F_46 ( V_24 -> V_74 . V_76 ) == V_143 ) ) ||
( ( F_46 ( V_24 -> V_74 . V_75 ) == V_144 ) &&
( F_46 ( V_24 -> V_74 . V_76 ) == V_145 ) ) ) {
if ( V_36 != V_24 -> V_146 -> V_36 [ 0 ] ) {
V_116 = V_24 -> V_146 -> V_36 [ 0 ] -> V_133 ;
for ( V_11 = 0 ; V_11 < V_116 -> V_134 . V_135 ; ++ V_11 ) {
V_118 = & V_116 -> V_118 [ V_11 ] . V_134 ;
if ( F_89 ( V_118 ) ) {
F_6 ( L_26 ) ;
V_119 [ V_125 ] = V_118 ;
++ V_125 ;
}
}
}
if ( V_127 == 0 || V_128 == 0 ) {
F_92 ( & V_36 -> V_24 , L_27 ) ;
F_12 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_31 ;
}
}
#endif
#ifdef F_93
if ( type == & V_147 ) {
V_9 = V_128 ;
if ( V_9 == 0 ) {
F_71 ( & V_36 -> V_24 ,
L_28 ) ;
F_12 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_130 ;
}
}
#endif
if ( ! V_9 ) {
if ( type -> V_148 )
V_9 = type -> V_148 ( V_3 ) ;
if ( ! V_9 )
V_9 = type -> V_9 ;
}
V_3 -> V_9 = V_9 ;
V_3 -> V_127 = V_127 ;
V_3 -> V_128 = V_128 ;
V_3 -> V_125 = V_125 ;
V_3 -> V_126 = V_126 ;
F_92 ( & V_36 -> V_24 , L_29 ,
type -> V_19 ) ;
V_129 = F_94 ( V_127 , V_128 ) ;
V_129 = F_94 ( V_129 , V_125 ) ;
V_129 = F_94 ( V_129 , V_126 ) ;
V_129 = F_94 ( V_129 , ( int ) V_3 -> V_9 ) ;
V_3 -> V_23 = V_129 ;
F_6 ( L_30 ,
V_14 , V_129 ) ;
for ( V_11 = 0 ; V_11 < V_129 ; ++ V_11 ) {
V_16 = F_70 ( sizeof( struct V_18 ) , V_101 ) ;
if ( ! V_16 )
goto V_149;
F_95 ( & V_16 -> V_16 ) ;
V_16 -> V_16 . V_150 = & V_151 ;
V_16 -> V_3 = V_3 ;
F_96 ( & V_16 -> V_107 ) ;
F_97 ( & V_16 -> V_86 , F_56 ) ;
V_3 -> V_16 [ V_11 ] = V_16 ;
V_16 -> V_24 . V_152 = & V_36 -> V_24 ;
V_16 -> V_24 . V_26 = NULL ;
V_16 -> V_24 . V_153 = & V_154 ;
V_16 -> V_24 . V_22 = & F_63 ;
F_98 ( & V_16 -> V_24 ) ;
}
for ( V_11 = 0 ; V_11 < V_127 ; ++ V_11 ) {
V_118 = V_122 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_124 = F_99 ( int , V_3 -> type -> V_155 ,
F_100 ( V_118 ) ) ;
V_16 -> V_155 = V_124 ;
V_16 -> V_156 = V_118 -> V_157 ;
for ( V_12 = 0 ; V_12 < F_61 ( V_16 -> V_88 ) ; ++ V_12 ) {
F_101 ( V_12 , & V_16 -> V_158 ) ;
V_16 -> V_88 [ V_12 ] = F_102 ( 0 , V_101 ) ;
if ( ! V_16 -> V_88 [ V_12 ] ) {
F_71 ( & V_36 -> V_24 ,
L_31 ) ;
goto V_149;
}
V_16 -> V_94 [ V_12 ] = F_103 ( V_124 ,
V_101 ) ;
if ( ! V_16 -> V_94 [ V_12 ] ) {
F_71 ( & V_36 -> V_24 ,
L_32 ) ;
goto V_149;
}
F_104 ( V_16 -> V_88 [ V_12 ] , V_24 ,
F_105 ( V_24 ,
V_118 -> V_157 ) ,
V_16 -> V_94 [ V_12 ] , V_124 ,
V_3 -> type -> V_159 ,
V_16 ) ;
}
V_16 -> V_90 = V_16 -> V_88 [ 0 ] ;
V_16 -> V_160 = V_16 -> V_94 [ 0 ] ;
}
for ( V_11 = 0 ; V_11 < V_128 ; ++ V_11 ) {
V_118 = V_123 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
if ( F_106 ( & V_16 -> V_96 , V_161 , V_101 ) )
goto V_149;
V_124 = V_3 -> type -> V_162 ;
if ( ! V_124 )
V_124 = F_100 ( V_118 ) ;
V_16 -> V_162 = V_124 ;
V_16 -> V_163 = V_118 -> V_157 ;
for ( V_12 = 0 ; V_12 < F_61 ( V_16 -> V_89 ) ; ++ V_12 ) {
F_101 ( V_12 , & V_16 -> V_164 ) ;
V_16 -> V_89 [ V_12 ] = F_102 ( 0 , V_101 ) ;
if ( ! V_16 -> V_89 [ V_12 ] ) {
F_71 ( & V_36 -> V_24 ,
L_31 ) ;
goto V_149;
}
V_16 -> V_95 [ V_12 ] = F_103 ( V_124 ,
V_101 ) ;
if ( ! V_16 -> V_95 [ V_12 ] ) {
F_71 ( & V_36 -> V_24 ,
L_33 ) ;
goto V_149;
}
F_104 ( V_16 -> V_89 [ V_12 ] , V_24 ,
F_107 ( V_24 ,
V_118 -> V_157 ) ,
V_16 -> V_95 [ V_12 ] , V_124 ,
V_3 -> type -> V_165 ,
V_16 ) ;
}
V_16 -> V_166 = V_16 -> V_89 [ 0 ] ;
V_16 -> V_167 = V_16 -> V_95 [ 0 ] ;
}
if ( V_3 -> type -> V_168 ) {
for ( V_11 = 0 ; V_11 < V_125 ; ++ V_11 ) {
V_118 = V_119 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_16 -> V_91 = F_102 ( 0 , V_101 ) ;
if ( ! V_16 -> V_91 ) {
F_71 ( & V_36 -> V_24 ,
L_31 ) ;
goto V_149;
}
V_124 = F_100 ( V_118 ) ;
V_16 -> V_169 =
V_118 -> V_157 ;
V_16 -> V_97 = F_103 ( V_124 ,
V_101 ) ;
if ( ! V_16 -> V_97 ) {
F_71 ( & V_36 -> V_24 ,
L_34 ) ;
goto V_149;
}
F_108 ( V_16 -> V_91 , V_24 ,
F_109 ( V_24 ,
V_118 -> V_157 ) ,
V_16 -> V_97 , V_124 ,
V_3 -> type -> V_168 , V_16 ,
V_118 -> V_170 ) ;
}
} else if ( V_125 ) {
F_6 ( L_35 ) ;
}
if ( V_3 -> type -> V_171 ) {
for ( V_11 = 0 ; V_11 < V_126 ; ++ V_11 ) {
V_118 = V_121 [ V_11 ] ;
V_16 = V_3 -> V_16 [ V_11 ] ;
V_16 -> V_92 = F_102 ( 0 , V_101 ) ;
if ( ! V_16 -> V_92 ) {
F_71 ( & V_36 -> V_24 ,
L_31 ) ;
goto V_149;
}
V_124 = F_100 ( V_118 ) ;
V_16 -> V_172 = V_124 ;
V_16 -> V_173 =
V_118 -> V_157 ;
V_16 -> V_98 = F_103 ( V_124 ,
V_101 ) ;
if ( ! V_16 -> V_98 ) {
F_71 ( & V_36 -> V_24 ,
L_36 ) ;
goto V_149;
}
F_108 ( V_16 -> V_92 , V_24 ,
F_110 ( V_24 ,
V_118 -> V_157 ) ,
V_16 -> V_98 , V_124 ,
V_3 -> type -> V_171 , V_16 ,
V_118 -> V_170 ) ;
}
} else if ( V_126 ) {
F_6 ( L_37 ) ;
}
if ( type -> V_174 ) {
V_30 = type -> V_174 ( V_3 ) ;
if ( V_30 < 0 )
goto V_149;
V_3 -> V_21 = 1 ;
if ( V_30 > 0 ) {
V_3 -> V_9 = 0 ;
goto exit;
}
} else {
V_3 -> V_21 = 1 ;
}
if ( F_5 ( V_3 , V_9 , & V_10 ) == NULL ) {
F_71 ( & V_36 -> V_24 , L_38 ) ;
goto V_149;
}
V_3 -> V_10 = V_10 ;
for ( V_11 = 0 ; V_11 < V_9 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
F_111 ( & V_16 -> V_24 , L_39 , V_16 -> V_17 ) ;
F_6 ( L_40 , V_14 , F_65 ( & V_16 -> V_24 ) ) ;
V_16 -> V_175 = V_176 ;
F_112 ( & V_16 -> V_24 ) ;
V_30 = F_113 ( & V_16 -> V_24 ) ;
if ( V_30 ) {
F_71 ( & V_16 -> V_24 , L_41
L_42 ) ;
V_16 -> V_175 = V_177 ;
} else {
V_16 -> V_175 = V_178 ;
}
}
F_114 ( V_179 , V_10 ) ;
exit:
F_115 ( V_36 , V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return 0 ;
V_149:
F_13 ( V_3 ) ;
F_20 ( type -> V_26 . V_33 ) ;
return - V_130 ;
}
void F_116 ( struct V_100 * V_36 )
{
int V_11 ;
struct V_1 * V_3 = F_117 ( V_36 ) ;
struct V_93 * V_24 = & V_36 -> V_24 ;
struct V_18 * V_16 ;
F_118 ( V_3 ) ;
F_6 ( L_3 , V_14 ) ;
F_2 ( & V_3 -> V_6 ) ;
F_115 ( V_36 , NULL ) ;
V_3 -> V_7 = 1 ;
F_3 ( & V_3 -> V_6 ) ;
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
if ( V_16 ) {
struct V_27 * V_28 = F_57 ( & V_16 -> V_16 ) ;
if ( V_28 ) {
F_119 ( V_28 ) ;
F_59 ( V_28 ) ;
}
F_60 ( V_16 ) ;
F_66 ( & V_16 -> V_86 ) ;
if ( V_16 -> V_175 == V_178 ) {
if ( ! V_16 -> V_24 . V_26 ) {
int V_180 ;
V_16 -> V_24 . V_26 =
& V_3 -> type -> V_26 ;
V_180 = F_120 ( & V_16 -> V_24 ) ;
}
V_16 -> V_175 = V_181 ;
F_121 ( & V_16 -> V_24 ) ;
V_16 -> V_175 = V_177 ;
}
}
}
V_3 -> type -> V_182 ( V_3 ) ;
F_13 ( V_3 ) ;
F_92 ( V_24 , L_43 ) ;
}
int F_122 ( struct V_100 * V_103 , T_1 V_183 )
{
struct V_1 * V_3 = F_117 ( V_103 ) ;
struct V_18 * V_16 ;
int V_11 , V_184 = 0 ;
V_3 -> V_185 = 1 ;
if ( V_3 -> type -> V_186 ) {
V_184 = V_3 -> type -> V_186 ( V_3 , V_183 ) ;
if ( V_184 < 0 ) {
V_3 -> V_185 = 0 ;
goto V_187;
}
}
for ( V_11 = 0 ; V_11 < V_3 -> V_9 ; ++ V_11 ) {
V_16 = V_3 -> V_16 [ V_11 ] ;
if ( V_16 )
F_60 ( V_16 ) ;
}
V_187:
return V_184 ;
}
int F_123 ( struct V_100 * V_103 )
{
struct V_1 * V_3 = F_117 ( V_103 ) ;
int V_188 ;
V_3 -> V_185 = 0 ;
if ( V_3 -> type -> V_189 )
V_188 = V_3 -> type -> V_189 ( V_3 ) ;
else
V_188 = F_124 ( V_3 ) ;
return V_188 ;
}
static int T_2 F_125 ( void )
{
int V_11 ;
int V_190 ;
V_191 = F_126 ( V_15 ) ;
if ( ! V_191 )
return - V_131 ;
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 )
V_5 [ V_11 ] = NULL ;
V_190 = F_127 ( & V_154 ) ;
if ( V_190 ) {
F_128 ( V_192 L_44
L_45 , V_14 ) ;
goto V_193;
}
V_191 -> V_33 = V_194 ;
V_191 -> V_195 = L_46 ;
V_191 -> V_196 = L_47 ;
V_191 -> V_197 = V_198 ;
V_191 -> V_199 = 0 ;
V_191 -> type = V_200 ;
V_191 -> V_201 = V_202 ;
V_191 -> V_203 = V_204 |
V_205 ;
V_191 -> V_38 = V_206 ;
V_191 -> V_38 . V_207 = V_208 | V_209 | V_210
| V_211 | V_212 ;
V_191 -> V_38 . V_213 = 9600 ;
V_191 -> V_38 . V_214 = 9600 ;
F_129 ( V_191 , & V_215 ) ;
V_190 = F_130 ( V_191 ) ;
if ( V_190 ) {
F_128 ( V_192 L_48 ,
V_14 ) ;
goto V_216;
}
V_190 = F_131 ( & V_47 ) ;
if ( V_190 < 0 ) {
F_128 ( V_192 L_49 ,
V_14 ) ;
goto V_217;
}
V_190 = F_132 ( V_179 ) ;
if ( V_190 < 0 ) {
F_128 ( V_192 L_50
L_51 , V_14 ) ;
goto V_218;
}
F_128 (KERN_INFO KBUILD_MODNAME L_52 DRIVER_DESC L_53 ) ;
return V_190 ;
V_218:
F_133 ( & V_47 ) ;
V_217:
F_134 ( V_191 ) ;
V_216:
F_135 ( & V_154 ) ;
V_193:
F_128 ( V_192 L_54 ,
V_14 , V_190 ) ;
F_136 ( V_191 ) ;
return V_190 ;
}
static void T_3 F_137 ( void )
{
F_138 () ;
F_139 () ;
F_133 ( & V_47 ) ;
F_134 ( V_191 ) ;
F_136 ( V_191 ) ;
F_135 ( & V_154 ) ;
}
static void F_140 ( struct V_47 * V_93 )
{
F_141 ( V_93 , V_44 ) ;
F_141 ( V_93 , V_55 ) ;
F_141 ( V_93 , V_50 ) ;
F_141 ( V_93 , V_56 ) ;
F_141 ( V_93 , V_57 ) ;
F_141 ( V_93 , V_159 ) ;
F_141 ( V_93 , V_165 ) ;
F_141 ( V_93 , V_182 ) ;
F_141 ( V_93 , V_22 ) ;
F_141 ( V_93 , V_219 ) ;
F_141 ( V_93 , V_220 ) ;
}
int F_142 ( struct V_47 * V_26 )
{
int V_30 ;
if ( F_143 () )
return - V_31 ;
F_140 ( V_26 ) ;
if ( ! V_26 -> V_19 )
V_26 -> V_19 = V_26 -> V_26 . V_196 ;
if ( ! V_26 -> V_221 ) {
F_144 ( 1 , L_55 ,
V_26 -> V_19 ) ;
return - V_79 ;
}
V_26 -> V_221 -> V_222 = 1 ;
F_2 ( & V_4 ) ;
F_145 ( & V_26 -> V_223 , & V_224 ) ;
V_30 = F_146 ( V_26 ) ;
if ( V_30 ) {
F_128 ( V_192 L_56
L_57 , V_30 , V_26 -> V_19 ) ;
F_147 ( & V_26 -> V_223 ) ;
} else
F_128 ( V_225 L_58 ,
V_26 -> V_19 ) ;
F_3 ( & V_4 ) ;
return V_30 ;
}
void F_148 ( struct V_47 * V_93 )
{
F_128 ( V_225 L_59 ,
V_93 -> V_19 ) ;
F_2 ( & V_4 ) ;
F_147 ( & V_93 -> V_223 ) ;
F_149 ( V_93 ) ;
F_3 ( & V_4 ) ;
}
