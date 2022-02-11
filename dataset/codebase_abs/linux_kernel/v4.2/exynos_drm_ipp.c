int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , struct V_8 * V_9 , void * V_10 )
{
int V_11 ;
F_2 ( V_9 ) ;
V_11 = F_8 ( V_7 , V_10 , 1 , 0 , V_12 ) ;
F_4 ( V_9 ) ;
return V_11 ;
}
static void F_9 ( struct V_6 * V_7 , struct V_8 * V_9 , T_1 V_13 )
{
F_2 ( V_9 ) ;
F_10 ( V_7 , V_13 ) ;
F_4 ( V_9 ) ;
}
static void * F_11 ( struct V_6 * V_7 , struct V_8 * V_9 , T_1 V_13 )
{
void * V_10 ;
F_2 ( V_9 ) ;
V_10 = F_12 ( V_7 , V_13 ) ;
F_4 ( V_9 ) ;
return V_10 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
if ( V_2 -> V_16 || ( ! F_14 ( V_15 -> V_17 ) &&
! F_15 ( V_2 -> V_18 ) ) )
return - V_19 ;
if ( V_2 -> V_20 &&
V_2 -> V_20 ( V_2 -> V_18 , V_15 ) )
return - V_21 ;
return 0 ;
}
static struct V_1 * F_16 ( struct V_22 * V_23 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 ;
T_1 V_24 = V_15 -> V_24 ;
int V_11 ;
if ( V_24 ) {
V_2 = F_11 ( & V_23 -> V_25 , & V_23 -> V_26 , V_24 ) ;
if ( ! V_2 ) {
F_17 ( L_1 , V_24 ) ;
return F_18 ( - V_27 ) ;
}
V_11 = F_13 ( V_2 , V_15 ) ;
if ( V_11 < 0 ) {
F_17 ( L_2 , V_24 , V_11 ) ;
return F_18 ( V_11 ) ;
}
return V_2 ;
} else {
F_19 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
V_11 = F_13 ( V_2 , V_15 ) ;
if ( V_11 == 0 )
return V_2 ;
}
F_17 ( L_3 ) ;
}
return F_18 ( - V_27 ) ;
}
static struct V_1 * F_20 ( T_1 V_28 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_31 = 0 ;
F_21 ( L_4 , V_28 ) ;
F_19 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_21 ( L_5 , V_31 ++ , ( int ) V_2 ) ;
F_2 ( & V_2 -> V_32 ) ;
F_19 (c_node, &ippdrv->cmd_list, list) {
if ( V_30 -> V_15 . V_28 == V_28 ) {
F_4 ( & V_2 -> V_32 ) ;
return V_2 ;
}
}
F_4 ( & V_2 -> V_32 ) ;
}
return F_18 ( - V_27 ) ;
}
int F_22 ( struct V_33 * V_34 , void * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_41 * V_18 = V_39 -> V_42 ;
struct V_22 * V_23 = F_23 ( V_18 ) ;
struct V_43 * V_44 = V_35 ;
struct V_1 * V_2 ;
int V_31 = 0 ;
if ( ! V_23 ) {
F_24 ( L_6 ) ;
return - V_21 ;
}
if ( ! V_44 ) {
F_24 ( L_7 ) ;
return - V_21 ;
}
F_21 ( L_8 , V_44 -> V_24 ) ;
if ( ! V_44 -> V_24 ) {
F_19 (ippdrv, &exynos_drm_ippdrv_list, drv_list)
V_31 ++ ;
V_44 -> V_31 = V_31 ;
} else {
V_2 = F_11 ( & V_23 -> V_25 , & V_23 -> V_26 ,
V_44 -> V_24 ) ;
if ( ! V_2 ) {
F_24 ( L_9 ,
V_44 -> V_24 ) ;
return - V_27 ;
}
* V_44 = V_2 -> V_44 ;
}
return 0 ;
}
static void F_25 ( struct V_14 * V_15 ,
int V_45 )
{
struct V_46 * V_47 = & V_15 -> V_47 [ V_45 ] ;
struct V_48 * V_49 = & V_47 -> V_49 ;
struct V_50 * V_51 = & V_47 -> V_51 ;
F_21 ( L_10 ,
V_15 -> V_28 , V_45 ? L_11 : L_12 , V_47 -> V_52 ) ;
F_21 ( L_13 ,
V_49 -> V_53 , V_49 -> V_54 , V_49 -> V_55 , V_49 -> V_56 ,
V_51 -> V_57 , V_51 -> V_58 , V_47 -> V_59 , V_47 -> V_60 ) ;
}
static struct V_61 * F_26 ( void )
{
struct V_61 * V_62 ;
V_62 = F_27 ( sizeof( * V_62 ) , V_12 ) ;
if ( ! V_62 )
return F_18 ( - V_63 ) ;
F_28 ( (struct V_64 * ) V_62 , V_65 ) ;
return V_62 ;
}
static struct V_66 * F_29 ( void )
{
struct V_66 * V_67 ;
V_67 = F_27 ( sizeof( * V_67 ) , V_12 ) ;
if ( ! V_67 )
return F_18 ( - V_63 ) ;
F_28 ( & V_67 -> V_68 , V_69 ) ;
return V_67 ;
}
int F_30 ( struct V_33 * V_34 , void * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_41 * V_18 = V_39 -> V_42 ;
struct V_22 * V_23 = F_23 ( V_18 ) ;
struct V_14 * V_15 = V_35 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
T_1 V_28 ;
int V_11 , V_70 ;
if ( ! V_23 ) {
F_24 ( L_6 ) ;
return - V_21 ;
}
if ( ! V_15 ) {
F_24 ( L_7 ) ;
return - V_21 ;
}
V_28 = V_15 -> V_28 ;
F_31 (i)
F_25 ( V_15 , V_70 ) ;
if ( V_28 ) {
V_30 = F_11 ( & V_23 -> V_71 , & V_23 -> V_72 , V_28 ) ;
if ( ! V_30 || V_30 -> V_73 != V_37 ) {
F_21 ( L_14 , V_28 ) ;
return - V_21 ;
}
if ( V_30 -> V_74 != V_75 ) {
F_21 ( L_15 , V_28 ) ;
return - V_21 ;
}
V_30 -> V_15 = * V_15 ;
return 0 ;
}
V_2 = F_16 ( V_23 , V_15 ) ;
if ( F_32 ( V_2 ) ) {
F_24 ( L_16 ) ;
return - V_21 ;
}
V_30 = F_27 ( sizeof( * V_30 ) , V_12 ) ;
if ( ! V_30 )
return - V_63 ;
V_11 = F_7 ( & V_23 -> V_71 , & V_23 -> V_72 , V_30 ) ;
if ( V_11 < 0 ) {
F_24 ( L_17 ) ;
goto V_76;
}
V_15 -> V_28 = V_11 ;
F_21 ( L_18 ,
V_15 -> V_28 , V_15 -> V_17 , ( int ) V_2 ) ;
V_30 -> V_15 = * V_15 ;
V_30 -> V_74 = V_77 ;
V_30 -> V_73 = V_37 ;
V_30 -> V_78 = F_26 () ;
if ( F_32 ( V_30 -> V_78 ) ) {
F_24 ( L_19 ) ;
V_11 = F_33 ( V_30 -> V_78 ) ;
goto V_79;
}
V_30 -> V_80 = F_26 () ;
if ( F_32 ( V_30 -> V_80 ) ) {
F_24 ( L_20 ) ;
V_11 = F_33 ( V_30 -> V_80 ) ;
goto V_81;
}
V_30 -> V_67 = F_29 () ;
if ( F_32 ( V_30 -> V_67 ) ) {
F_24 ( L_21 ) ;
V_11 = F_33 ( V_30 -> V_67 ) ;
goto V_82;
}
F_34 ( & V_30 -> V_9 ) ;
F_34 ( & V_30 -> V_83 ) ;
F_34 ( & V_30 -> V_84 ) ;
F_35 ( & V_30 -> V_85 ) ;
F_35 ( & V_30 -> V_86 ) ;
F_31 (i)
F_36 ( & V_30 -> V_87 [ V_70 ] ) ;
F_36 ( & V_30 -> V_88 ) ;
F_2 ( & V_2 -> V_32 ) ;
F_3 ( & V_30 -> V_89 , & V_2 -> V_90 ) ;
F_4 ( & V_2 -> V_32 ) ;
if ( ! F_14 ( V_15 -> V_17 ) )
V_2 -> V_16 = true ;
return 0 ;
V_82:
F_37 ( V_30 -> V_80 ) ;
V_81:
F_37 ( V_30 -> V_78 ) ;
V_79:
F_9 ( & V_23 -> V_71 , & V_23 -> V_72 , V_15 -> V_28 ) ;
V_76:
F_37 ( V_30 ) ;
return V_11 ;
}
static int F_38 ( struct V_33 * V_34 ,
struct V_91 * V_92 ,
struct V_29 * V_30 )
{
struct V_46 * V_93 ;
unsigned int V_94 ;
unsigned long V_95 , V_96 = 0 , V_97 , V_98 = 0 ;
unsigned int V_99 , V_100 , V_101 ;
int V_70 ;
V_93 = & V_30 -> V_15 . V_47 [ V_92 -> V_102 ] ;
V_94 = F_39 ( V_93 -> V_52 ) ;
for ( V_70 = 0 ; V_70 < V_94 ; ++ V_70 ) {
V_100 = V_93 -> V_51 . V_57 ;
V_101 = V_93 -> V_51 . V_58 ;
V_99 = F_40 ( V_93 -> V_52 , V_70 ) ;
if ( V_70 > 0 ) {
V_100 /= F_41 (
V_93 -> V_52 ) ;
V_101 /= F_42 (
V_93 -> V_52 ) ;
}
V_97 = V_100 * V_101 * V_99 ;
V_98 += V_97 ;
if ( V_92 -> V_103 . V_104 [ V_70 ] ) {
V_95 = F_43 ( V_34 ,
V_92 -> V_103 . V_104 [ V_70 ] ,
V_30 -> V_73 ) ;
if ( V_97 > V_95 ) {
F_24 (
L_22 ,
V_70 ) ;
return - V_21 ;
}
V_96 += V_95 ;
}
}
if ( V_96 < V_98 ) {
F_24 ( L_23 ,
V_96 , V_98 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_44 ( struct V_33 * V_34 ,
struct V_29 * V_30 ,
struct V_91 * V_92 )
{
int V_70 ;
F_21 ( L_24 , ( int ) V_92 ) ;
if ( ! V_92 ) {
F_24 ( L_25 ) ;
return - V_105 ;
}
F_21 ( L_26 , V_92 -> V_102 ) ;
F_45 (i) {
unsigned long V_106 = V_92 -> V_103 . V_104 [ V_70 ] ;
if ( V_106 )
F_46 ( V_34 , V_106 ,
V_30 -> V_73 ) ;
}
F_6 ( & V_92 -> V_89 ) ;
F_37 ( V_92 ) ;
return 0 ;
}
static struct V_91
* F_47 ( struct V_33 * V_34 ,
struct V_29 * V_30 ,
struct V_107 * V_108 )
{
struct V_91 * V_92 ;
struct V_109 * V_103 ;
int V_70 ;
V_92 = F_27 ( sizeof( * V_92 ) , V_12 ) ;
if ( ! V_92 )
return F_18 ( - V_63 ) ;
V_103 = & V_92 -> V_103 ;
V_92 -> V_102 = V_108 -> V_102 ;
V_92 -> V_28 = V_108 -> V_28 ;
V_92 -> V_110 = V_108 -> V_110 ;
F_36 ( & V_92 -> V_89 ) ;
F_21 ( L_27 , ( int ) V_92 , V_108 -> V_102 ) ;
F_21 ( L_28 , V_108 -> V_28 , V_92 -> V_110 ) ;
F_45 (i) {
F_21 ( L_29 , V_70 , V_108 -> V_106 [ V_70 ] ) ;
if ( V_108 -> V_106 [ V_70 ] ) {
T_2 * V_111 ;
V_111 = F_48 ( V_34 ,
V_108 -> V_106 [ V_70 ] , V_30 -> V_73 ) ;
if ( F_32 ( V_111 ) ) {
F_24 ( L_30 ) ;
F_44 ( V_34 , V_30 , V_92 ) ;
return F_18 ( - V_105 ) ;
}
V_103 -> V_104 [ V_70 ] = V_108 -> V_106 [ V_70 ] ;
V_103 -> V_112 [ V_70 ] = * V_111 ;
F_21 ( L_31 , V_70 ,
V_103 -> V_112 [ V_70 ] , V_103 -> V_104 [ V_70 ] ) ;
}
}
F_2 ( & V_30 -> V_83 ) ;
if ( F_38 ( V_34 , V_92 , V_30 ) ) {
F_44 ( V_34 , V_30 , V_92 ) ;
F_4 ( & V_30 -> V_83 ) ;
return F_18 ( - V_105 ) ;
}
F_3 ( & V_92 -> V_89 , & V_30 -> V_87 [ V_108 -> V_102 ] ) ;
F_4 ( & V_30 -> V_83 ) ;
return V_92 ;
}
static void F_49 ( struct V_33 * V_34 ,
struct V_29 * V_30 , int V_113 )
{
struct V_91 * V_92 , * V_114 ;
struct V_115 * V_116 = & V_30 -> V_87 [ V_113 ] ;
F_2 ( & V_30 -> V_83 ) ;
F_50 (m_node, tm_node, head, list) {
int V_11 ;
V_11 = F_44 ( V_34 , V_30 , V_92 ) ;
if ( V_11 )
F_24 ( L_32 ) ;
}
F_4 ( & V_30 -> V_83 ) ;
}
static void F_51 ( struct V_117 * V_118 )
{
F_37 ( V_118 ) ;
}
static int F_52 ( struct V_33 * V_34 ,
struct V_29 * V_30 ,
struct V_107 * V_108 )
{
struct V_119 * V_120 ;
unsigned long V_121 ;
F_21 ( L_33 , V_108 -> V_102 , V_108 -> V_110 ) ;
V_120 = F_27 ( sizeof( * V_120 ) , V_12 ) ;
if ( ! V_120 ) {
F_53 ( & V_34 -> V_84 , V_121 ) ;
V_30 -> V_73 -> V_122 += sizeof( V_120 -> V_118 ) ;
F_54 ( & V_34 -> V_84 , V_121 ) ;
return - V_63 ;
}
V_120 -> V_118 . V_112 . type = V_123 ;
V_120 -> V_118 . V_112 . V_124 = sizeof( V_120 -> V_118 ) ;
V_120 -> V_118 . V_125 = V_108 -> V_125 ;
V_120 -> V_118 . V_28 = V_108 -> V_28 ;
V_120 -> V_118 . V_110 [ V_126 ] = V_108 -> V_110 ;
V_120 -> V_112 . V_118 = & V_120 -> V_118 . V_112 ;
V_120 -> V_112 . V_39 = V_30 -> V_73 ;
V_120 -> V_112 . V_127 = F_51 ;
F_2 ( & V_30 -> V_84 ) ;
F_3 ( & V_120 -> V_112 . V_128 , & V_30 -> V_88 ) ;
F_4 ( & V_30 -> V_84 ) ;
return 0 ;
}
static void F_55 ( struct V_29 * V_30 ,
struct V_107 * V_108 )
{
struct V_119 * V_120 , * V_129 ;
int V_31 = 0 ;
F_2 ( & V_30 -> V_84 ) ;
F_50 (e, te, &c_node->event_list, base.link) {
F_21 ( L_34 , V_31 ++ , ( int ) V_120 ) ;
if ( ! V_108 ) {
F_6 ( & V_120 -> V_112 . V_128 ) ;
F_37 ( V_120 ) ;
}
if ( V_108 && ( V_108 -> V_110 ==
V_120 -> V_118 . V_110 [ V_126 ] ) ) {
F_6 ( & V_120 -> V_112 . V_128 ) ;
F_37 ( V_120 ) ;
goto V_130;
}
}
V_130:
F_4 ( & V_30 -> V_84 ) ;
return;
}
static void F_56 ( struct V_22 * V_23 ,
struct V_29 * V_30 )
{
int V_70 ;
F_57 ( & V_30 -> V_78 -> V_68 ) ;
F_57 ( & V_30 -> V_80 -> V_68 ) ;
F_57 ( & V_30 -> V_67 -> V_68 ) ;
F_55 ( V_30 , NULL ) ;
F_31 (i)
F_49 ( V_23 -> V_131 . V_34 , V_30 , V_70 ) ;
F_6 ( & V_30 -> V_89 ) ;
F_9 ( & V_23 -> V_71 , & V_23 -> V_72 ,
V_30 -> V_15 . V_28 ) ;
F_58 ( & V_30 -> V_9 ) ;
F_58 ( & V_30 -> V_83 ) ;
F_58 ( & V_30 -> V_84 ) ;
F_37 ( V_30 -> V_78 ) ;
F_37 ( V_30 -> V_80 ) ;
F_37 ( V_30 -> V_67 ) ;
F_37 ( V_30 ) ;
}
static bool F_59 ( struct V_29 * V_30 )
{
switch ( V_30 -> V_15 . V_17 ) {
case V_132 :
return ! F_60 ( & V_30 -> V_87 [ V_126 ] ) ;
case V_133 :
return ! F_60 ( & V_30 -> V_87 [ V_134 ] ) ;
case V_135 :
default:
return ! F_60 ( & V_30 -> V_87 [ V_134 ] ) &&
! F_60 ( & V_30 -> V_87 [ V_126 ] ) ;
}
}
static struct V_91
* F_61 ( struct V_29 * V_30 ,
struct V_107 * V_108 )
{
struct V_91 * V_92 ;
struct V_115 * V_116 ;
int V_31 = 0 ;
F_21 ( L_35 , V_108 -> V_110 ) ;
V_116 = & V_30 -> V_87 [ V_108 -> V_102 ] ;
F_19 (m_node, head, list) {
F_21 ( L_36 , V_31 ++ , ( int ) V_92 ) ;
if ( V_92 -> V_110 == V_108 -> V_110 )
return V_92 ;
}
return NULL ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_91 * V_92 )
{
struct V_136 * V_113 = NULL ;
int V_11 = 0 ;
F_21 ( L_24 , ( int ) V_92 ) ;
if ( ! V_92 ) {
F_24 ( L_37 ) ;
return - V_105 ;
}
F_21 ( L_26 , V_92 -> V_102 ) ;
V_113 = V_2 -> V_113 [ V_92 -> V_102 ] ;
if ( ! V_113 ) {
F_24 ( L_38 ) ;
return - V_105 ;
}
if ( V_113 -> V_137 ) {
V_11 = V_113 -> V_137 ( V_2 -> V_18 , & V_92 -> V_103 ,
V_92 -> V_110 , V_138 ) ;
if ( V_11 ) {
F_24 ( L_39 ) ;
return V_11 ;
}
}
return V_11 ;
}
static void F_63 ( struct V_41 * V_18 ,
struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_29 * V_30 )
{
struct V_22 * V_23 = F_23 ( V_18 ) ;
V_62 -> V_2 = V_2 ;
V_62 -> V_30 = V_30 ;
F_64 ( V_23 -> V_139 , & V_62 -> V_68 ) ;
}
static int F_65 ( struct V_41 * V_18 ,
struct V_29 * V_30 ,
struct V_91 * V_92 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_136 * V_113 ;
int V_11 ;
V_2 = F_20 ( V_108 -> V_28 ) ;
if ( F_32 ( V_2 ) ) {
F_24 ( L_16 ) ;
return - V_105 ;
}
V_113 = V_2 -> V_113 [ V_108 -> V_102 ] ;
if ( ! V_113 ) {
F_24 ( L_40 ) ;
return - V_105 ;
}
V_15 = & V_30 -> V_15 ;
if ( V_30 -> V_74 != V_140 ) {
F_21 ( L_41 ) ;
return 0 ;
}
F_2 ( & V_30 -> V_83 ) ;
if ( ! F_59 ( V_30 ) ) {
F_4 ( & V_30 -> V_83 ) ;
F_21 ( L_42 ) ;
return 0 ;
}
if ( F_14 ( V_15 -> V_17 ) ) {
struct V_61 * V_62 = V_30 -> V_78 ;
V_62 -> V_141 = V_142 ;
F_63 ( V_18 , V_2 , V_62 , V_30 ) ;
} else {
V_11 = F_62 ( V_2 , V_30 , V_92 ) ;
if ( V_11 ) {
F_4 ( & V_30 -> V_83 ) ;
F_24 ( L_43 ) ;
return V_11 ;
}
}
F_4 ( & V_30 -> V_83 ) ;
return 0 ;
}
static void F_66 ( struct V_33 * V_34 ,
struct V_29 * V_30 ,
struct V_107 * V_108 )
{
struct V_91 * V_92 , * V_114 ;
F_2 ( & V_30 -> V_83 ) ;
F_50 (m_node, tm_node,
&c_node->mem_list[qbuf->ops_id], list) {
if ( V_92 -> V_110 == V_108 -> V_110 &&
V_92 -> V_102 == V_108 -> V_102 )
F_44 ( V_34 , V_30 , V_92 ) ;
}
F_4 ( & V_30 -> V_83 ) ;
}
int F_67 ( struct V_33 * V_34 , void * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_41 * V_18 = V_39 -> V_42 ;
struct V_22 * V_23 = F_23 ( V_18 ) ;
struct V_107 * V_108 = V_35 ;
struct V_29 * V_30 ;
struct V_91 * V_92 ;
int V_11 ;
if ( ! V_108 ) {
F_24 ( L_44 ) ;
return - V_21 ;
}
if ( V_108 -> V_102 >= V_143 ) {
F_24 ( L_45 ) ;
return - V_21 ;
}
F_21 ( L_46 ,
V_108 -> V_28 , V_108 -> V_102 ? L_11 : L_12 ,
V_108 -> V_110 , V_108 -> V_144 ) ;
V_30 = F_11 ( & V_23 -> V_71 , & V_23 -> V_72 ,
V_108 -> V_28 ) ;
if ( ! V_30 || V_30 -> V_73 != V_37 ) {
F_24 ( L_47 ) ;
return - V_27 ;
}
switch ( V_108 -> V_144 ) {
case V_138 :
V_92 = F_47 ( V_34 , V_30 , V_108 ) ;
if ( F_32 ( V_92 ) ) {
F_24 ( L_48 ) ;
return F_33 ( V_92 ) ;
}
if ( V_108 -> V_102 == V_126 ) {
V_11 = F_52 ( V_34 , V_30 , V_108 ) ;
if ( V_11 ) {
F_24 ( L_49 ) ;
goto V_145;
}
V_11 = F_65 ( V_18 , V_30 , V_92 , V_108 ) ;
if ( V_11 ) {
F_24 ( L_50 ) ;
goto V_145;
}
}
break;
case V_146 :
F_2 ( & V_30 -> V_9 ) ;
if ( V_108 -> V_102 == V_126 )
F_55 ( V_30 , V_108 ) ;
F_66 ( V_34 , V_30 , V_108 ) ;
F_4 ( & V_30 -> V_9 ) ;
break;
default:
F_24 ( L_51 ) ;
return - V_21 ;
}
return 0 ;
V_145:
F_24 ( L_52 ) ;
F_66 ( V_34 , V_30 , V_108 ) ;
return V_11 ;
}
static bool F_68 ( struct V_41 * V_18 ,
enum V_147 V_141 , enum V_148 V_74 )
{
if ( V_141 != V_142 ) {
if ( F_15 ( V_18 ) ) {
F_24 ( L_53 ) ;
goto V_149;
}
}
switch ( V_141 ) {
case V_142 :
if ( V_74 != V_77 )
goto V_149;
break;
case V_150 :
if ( V_74 == V_75 )
goto V_149;
break;
case V_151 :
if ( V_74 != V_140 )
goto V_149;
break;
case V_152 :
if ( V_74 != V_75 )
goto V_149;
break;
default:
F_24 ( L_54 ) ;
goto V_149;
}
return true ;
V_149:
F_24 ( L_55 , V_141 , V_74 ) ;
return false ;
}
int F_69 ( struct V_33 * V_34 , void * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_1 * V_2 = NULL ;
struct V_41 * V_18 = V_39 -> V_42 ;
struct V_22 * V_23 = F_23 ( V_18 ) ;
struct V_153 * V_154 = V_35 ;
struct V_61 * V_62 ;
struct V_29 * V_30 ;
if ( ! V_23 ) {
F_24 ( L_6 ) ;
return - V_21 ;
}
if ( ! V_154 ) {
F_24 ( L_56 ) ;
return - V_21 ;
}
F_21 ( L_57 ,
V_154 -> V_141 , V_154 -> V_28 ) ;
V_2 = F_20 ( V_154 -> V_28 ) ;
if ( F_32 ( V_2 ) ) {
F_24 ( L_16 ) ;
return F_33 ( V_2 ) ;
}
V_30 = F_11 ( & V_23 -> V_71 , & V_23 -> V_72 ,
V_154 -> V_28 ) ;
if ( ! V_30 || V_30 -> V_73 != V_37 ) {
F_24 ( L_58 ) ;
return - V_27 ;
}
if ( ! F_68 ( V_2 -> V_18 , V_154 -> V_141 ,
V_30 -> V_74 ) ) {
F_24 ( L_54 ) ;
return - V_21 ;
}
switch ( V_154 -> V_141 ) {
case V_142 :
if ( F_15 ( V_2 -> V_18 ) )
F_70 ( V_2 -> V_18 ) ;
V_30 -> V_74 = V_140 ;
V_62 = V_30 -> V_78 ;
V_62 -> V_141 = V_154 -> V_141 ;
F_63 ( V_18 , V_2 , V_62 , V_30 ) ;
break;
case V_150 :
V_62 = V_30 -> V_80 ;
V_62 -> V_141 = V_154 -> V_141 ;
F_63 ( V_18 , V_2 , V_62 , V_30 ) ;
if ( ! F_71 ( & V_30 -> V_86 ,
F_72 ( 300 ) ) ) {
F_24 ( L_59 ,
V_30 -> V_15 . V_28 ) ;
}
V_30 -> V_74 = V_75 ;
V_2 -> V_16 = false ;
F_2 ( & V_2 -> V_32 ) ;
F_56 ( V_23 , V_30 ) ;
if ( F_60 ( & V_2 -> V_90 ) )
F_73 ( V_2 -> V_18 ) ;
F_4 ( & V_2 -> V_32 ) ;
break;
case V_151 :
V_62 = V_30 -> V_80 ;
V_62 -> V_141 = V_154 -> V_141 ;
F_63 ( V_18 , V_2 , V_62 , V_30 ) ;
if ( ! F_71 ( & V_30 -> V_86 ,
F_72 ( 200 ) ) ) {
F_24 ( L_59 ,
V_30 -> V_15 . V_28 ) ;
}
V_30 -> V_74 = V_75 ;
break;
case V_152 :
V_30 -> V_74 = V_140 ;
V_62 = V_30 -> V_78 ;
V_62 -> V_141 = V_154 -> V_141 ;
F_63 ( V_18 , V_2 , V_62 , V_30 ) ;
break;
default:
F_24 ( L_60 ) ;
return - V_21 ;
}
F_21 ( L_61 ,
V_154 -> V_141 , V_154 -> V_28 ) ;
return 0 ;
}
int F_74 ( struct V_155 * V_156 )
{
return F_75 (
& V_157 , V_156 ) ;
}
int F_76 ( struct V_155 * V_156 )
{
return F_77 (
& V_157 , V_156 ) ;
}
int F_78 ( unsigned long V_158 , void * V_159 )
{
return F_79 (
& V_157 , V_158 , V_159 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_136 * V_113 = NULL ;
bool V_160 = false ;
int V_11 , V_70 ;
if ( ! V_15 ) {
F_24 ( L_7 ) ;
return - V_21 ;
}
F_21 ( L_4 , V_15 -> V_28 ) ;
if ( V_2 -> V_161 &&
V_2 -> V_161 ( V_2 -> V_18 ) ) {
return - V_21 ;
}
F_31 (i) {
struct V_46 * V_47 =
& V_15 -> V_47 [ V_70 ] ;
V_113 = V_2 -> V_113 [ V_70 ] ;
if ( ! V_113 || ! V_47 ) {
F_24 ( L_62 ) ;
return - V_21 ;
}
if ( V_113 -> V_162 ) {
V_11 = V_113 -> V_162 ( V_2 -> V_18 , V_47 -> V_52 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_113 -> V_163 ) {
V_11 = V_113 -> V_163 ( V_2 -> V_18 , V_47 -> V_60 ,
V_47 -> V_59 , & V_160 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_113 -> V_164 ) {
V_11 = V_113 -> V_164 ( V_2 -> V_18 , V_160 , & V_47 -> V_49 ,
& V_47 -> V_51 ) ;
if ( V_11 )
return V_11 ;
}
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_91 * V_92 ;
struct V_14 * V_15 = & V_30 -> V_15 ;
struct V_115 * V_116 ;
int V_11 , V_70 ;
F_21 ( L_4 , V_15 -> V_28 ) ;
V_2 -> V_30 = V_30 ;
F_2 ( & V_30 -> V_83 ) ;
if ( ! F_59 ( V_30 ) ) {
F_21 ( L_42 ) ;
V_11 = - V_63 ;
goto V_165;
}
V_11 = F_80 ( V_2 , V_15 ) ;
if ( V_11 ) {
F_24 ( L_63 ) ;
V_2 -> V_30 = NULL ;
goto V_165;
}
switch ( V_15 -> V_17 ) {
case V_135 :
F_31 (i) {
V_116 = & V_30 -> V_87 [ V_70 ] ;
V_92 = F_82 ( V_116 ,
struct V_91 , V_89 ) ;
F_21 ( L_64 , ( int ) V_92 ) ;
V_11 = F_62 ( V_2 , V_30 , V_92 ) ;
if ( V_11 ) {
F_24 ( L_43 ) ;
goto V_165;
}
}
break;
case V_132 :
V_116 = & V_30 -> V_87 [ V_126 ] ;
F_19 (m_node, head, list) {
V_11 = F_62 ( V_2 , V_30 , V_92 ) ;
if ( V_11 ) {
F_24 ( L_43 ) ;
goto V_165;
}
}
break;
case V_133 :
V_116 = & V_30 -> V_87 [ V_134 ] ;
F_19 (m_node, head, list) {
V_11 = F_62 ( V_2 , V_30 , V_92 ) ;
if ( V_11 ) {
F_24 ( L_43 ) ;
goto V_165;
}
}
break;
default:
F_24 ( L_65 ) ;
V_11 = - V_21 ;
goto V_165;
}
F_4 ( & V_30 -> V_83 ) ;
F_21 ( L_66 , V_15 -> V_17 ) ;
if ( V_2 -> V_166 ) {
V_11 = V_2 -> V_166 ( V_2 -> V_18 , V_15 -> V_17 ) ;
if ( V_11 ) {
F_24 ( L_67 ) ;
V_2 -> V_30 = NULL ;
return V_11 ;
}
}
return 0 ;
V_165:
F_4 ( & V_30 -> V_83 ) ;
V_2 -> V_30 = NULL ;
return V_11 ;
}
static int F_83 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_14 * V_15 = & V_30 -> V_15 ;
int V_70 ;
F_21 ( L_4 , V_15 -> V_28 ) ;
if ( V_2 -> V_167 )
V_2 -> V_167 ( V_2 -> V_18 , V_15 -> V_17 ) ;
switch ( V_15 -> V_17 ) {
case V_135 :
F_31 (i)
F_49 ( V_34 , V_30 , V_70 ) ;
break;
case V_132 :
F_49 ( V_34 , V_30 , V_126 ) ;
break;
case V_133 :
F_49 ( V_34 , V_30 , V_134 ) ;
break;
default:
F_24 ( L_65 ) ;
return - V_21 ;
}
return 0 ;
}
void V_65 ( struct V_64 * V_68 )
{
struct V_61 * V_62 =
F_84 ( V_68 , struct V_61 , V_68 ) ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
struct V_14 * V_15 ;
int V_11 ;
V_2 = V_62 -> V_2 ;
if ( ! V_2 ) {
F_24 ( L_68 ) ;
return;
}
V_30 = V_62 -> V_30 ;
if ( ! V_30 ) {
F_24 ( L_58 ) ;
return;
}
F_2 ( & V_30 -> V_9 ) ;
V_15 = & V_30 -> V_15 ;
switch ( V_62 -> V_141 ) {
case V_142 :
case V_152 :
V_11 = F_81 ( V_2 , V_30 ) ;
if ( V_11 ) {
F_24 ( L_69 ,
V_30 -> V_15 . V_28 ) ;
goto V_165;
}
if ( F_14 ( V_15 -> V_17 ) ) {
if ( ! F_71
( & V_30 -> V_85 , F_72 ( 200 ) ) ) {
F_24 ( L_70 ,
V_30 -> V_15 . V_28 ) ;
goto V_165;
}
}
break;
case V_150 :
case V_151 :
V_11 = F_83 ( V_2 -> V_34 , V_2 ,
V_30 ) ;
if ( V_11 ) {
F_24 ( L_71 ) ;
goto V_165;
}
F_85 ( & V_30 -> V_86 ) ;
break;
default:
F_24 ( L_72 ) ;
break;
}
F_21 ( L_73 , V_62 -> V_141 ) ;
V_165:
F_4 ( & V_30 -> V_9 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_29 * V_30 , int * V_110 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
struct V_14 * V_15 = & V_30 -> V_15 ;
struct V_91 * V_92 ;
struct V_107 V_108 ;
struct V_119 * V_120 ;
struct V_115 * V_116 ;
struct V_168 V_169 ;
unsigned long V_121 ;
T_1 V_170 [ V_143 ] = { 0 , } ;
int V_11 , V_70 ;
F_31 (i)
F_21 ( L_74 , V_70 ? L_11 : L_12 , V_110 [ V_70 ] ) ;
if ( ! V_34 ) {
F_24 ( L_75 ) ;
return - V_21 ;
}
if ( ! V_15 ) {
F_24 ( L_76 ) ;
return - V_21 ;
}
F_2 ( & V_30 -> V_84 ) ;
if ( F_60 ( & V_30 -> V_88 ) ) {
F_21 ( L_77 ) ;
V_11 = 0 ;
goto V_171;
}
F_2 ( & V_30 -> V_83 ) ;
if ( ! F_59 ( V_30 ) ) {
F_21 ( L_42 ) ;
V_11 = 0 ;
goto V_172;
}
switch ( V_15 -> V_17 ) {
case V_135 :
F_31 (i) {
V_116 = & V_30 -> V_87 [ V_70 ] ;
V_92 = F_82 ( V_116 ,
struct V_91 , V_89 ) ;
V_170 [ V_70 ] = V_92 -> V_110 ;
F_21 ( L_74 ,
V_70 ? L_11 : L_12 , V_170 [ V_70 ] ) ;
V_11 = F_44 ( V_34 , V_30 , V_92 ) ;
if ( V_11 )
F_24 ( L_32 ) ;
}
break;
case V_132 :
memset ( & V_108 , 0x0 , sizeof( V_108 ) ) ;
V_108 . V_102 = V_126 ;
V_108 . V_110 = V_110 [ V_126 ] ;
V_92 = F_61 ( V_30 , & V_108 ) ;
if ( ! V_92 ) {
F_24 ( L_78 ) ;
V_11 = - V_63 ;
goto V_172;
}
V_170 [ V_126 ] = V_92 -> V_110 ;
V_11 = F_44 ( V_34 , V_30 , V_92 ) ;
if ( V_11 )
F_24 ( L_32 ) ;
break;
case V_133 :
V_116 = & V_30 -> V_87 [ V_134 ] ;
V_92 = F_82 ( V_116 ,
struct V_91 , V_89 ) ;
V_170 [ V_134 ] = V_92 -> V_110 ;
V_11 = F_44 ( V_34 , V_30 , V_92 ) ;
if ( V_11 )
F_24 ( L_32 ) ;
break;
default:
F_24 ( L_65 ) ;
V_11 = - V_21 ;
goto V_172;
}
F_4 ( & V_30 -> V_83 ) ;
if ( V_170 [ V_126 ] != V_110 [ V_126 ] )
F_24 ( L_79 ,
V_170 [ 1 ] , V_110 [ 1 ] , V_15 -> V_28 ) ;
V_120 = F_82 ( & V_30 -> V_88 ,
struct V_119 , V_112 . V_128 ) ;
F_87 ( & V_169 ) ;
F_21 ( L_80 , V_169 . V_173 , V_169 . V_174 ) ;
V_120 -> V_118 . V_173 = V_169 . V_173 ;
V_120 -> V_118 . V_174 = V_169 . V_174 ;
V_120 -> V_118 . V_28 = V_15 -> V_28 ;
F_31 (i)
V_120 -> V_118 . V_110 [ V_70 ] = V_170 [ V_70 ] ;
F_53 ( & V_34 -> V_84 , V_121 ) ;
F_88 ( & V_120 -> V_112 . V_128 , & V_120 -> V_112 . V_39 -> V_88 ) ;
F_89 ( & V_120 -> V_112 . V_39 -> V_175 ) ;
F_54 ( & V_34 -> V_84 , V_121 ) ;
F_4 ( & V_30 -> V_84 ) ;
F_21 ( L_81 ,
V_15 -> V_17 , V_15 -> V_28 , V_170 [ V_126 ] ) ;
return 0 ;
V_172:
F_4 ( & V_30 -> V_83 ) ;
V_171:
F_4 ( & V_30 -> V_84 ) ;
return V_11 ;
}
void V_69 ( struct V_64 * V_68 )
{
struct V_66 * V_67 =
F_84 ( V_68 , struct V_66 , V_68 ) ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_11 ;
if ( ! V_67 ) {
F_24 ( L_82 ) ;
return;
}
F_21 ( L_35 , V_67 -> V_110 [ V_126 ] ) ;
V_2 = V_67 -> V_2 ;
if ( ! V_2 ) {
F_24 ( L_16 ) ;
return;
}
V_30 = V_2 -> V_30 ;
if ( ! V_30 ) {
F_24 ( L_47 ) ;
return;
}
if ( V_30 -> V_74 != V_140 ) {
F_21 ( L_83 ,
V_30 -> V_74 , V_30 -> V_15 . V_28 ) ;
goto V_176;
}
V_11 = F_86 ( V_2 , V_30 , V_67 -> V_110 ) ;
if ( V_11 ) {
F_24 ( L_84 ) ;
goto V_176;
}
V_176:
if ( F_14 ( V_30 -> V_15 . V_17 ) )
F_85 ( & V_30 -> V_85 ) ;
}
static int F_90 ( struct V_33 * V_34 , struct V_41 * V_18 )
{
struct V_22 * V_23 = F_23 ( V_18 ) ;
struct V_1 * V_2 ;
int V_11 , V_31 = 0 ;
F_19 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
V_2 -> V_34 = V_34 ;
V_11 = F_7 ( & V_23 -> V_25 , & V_23 -> V_26 , V_2 ) ;
if ( V_11 < 0 ) {
F_24 ( L_17 ) ;
goto V_177;
}
V_2 -> V_44 . V_24 = V_11 ;
F_21 ( L_85 ,
V_31 ++ , ( int ) V_2 , V_11 ) ;
V_2 -> V_178 = V_18 ;
V_2 -> V_179 = V_23 -> V_179 ;
V_2 -> V_180 = V_69 ;
F_36 ( & V_2 -> V_90 ) ;
F_34 ( & V_2 -> V_32 ) ;
if ( F_91 ( V_34 ) ) {
V_11 = F_92 ( V_34 , V_2 -> V_18 ) ;
if ( V_11 ) {
F_24 ( L_86 ) ;
goto V_177;
}
}
}
return 0 ;
V_177:
F_93 (ippdrv, &exynos_drm_ippdrv_list,
drv_list) {
if ( F_91 ( V_34 ) )
F_94 ( V_34 , V_2 -> V_18 ) ;
F_9 ( & V_23 -> V_25 , & V_23 -> V_26 ,
V_2 -> V_44 . V_24 ) ;
}
return V_11 ;
}
static void F_95 ( struct V_33 * V_34 , struct V_41 * V_18 )
{
struct V_1 * V_2 , * V_181 ;
struct V_22 * V_23 = F_23 ( V_18 ) ;
F_50 (ippdrv, t, &exynos_drm_ippdrv_list, drv_list) {
if ( F_91 ( V_34 ) )
F_94 ( V_34 , V_2 -> V_18 ) ;
F_9 ( & V_23 -> V_25 , & V_23 -> V_26 ,
V_2 -> V_44 . V_24 ) ;
V_2 -> V_34 = NULL ;
F_5 ( V_2 ) ;
}
}
static int F_96 ( struct V_33 * V_34 , struct V_41 * V_18 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
V_39 -> V_42 = V_18 ;
F_21 ( L_87 , ( int ) V_18 ) ;
return 0 ;
}
static void F_97 ( struct V_33 * V_34 , struct V_41 * V_18 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 = F_23 ( V_18 ) ;
struct V_29 * V_30 , * V_182 ;
int V_31 = 0 ;
F_19 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_2 ( & V_2 -> V_32 ) ;
F_50 (c_node, tc_node,
&ippdrv->cmd_list, list) {
F_21 ( L_5 ,
V_31 ++ , ( int ) V_2 ) ;
if ( V_30 -> V_73 == V_37 ) {
if ( V_30 -> V_74 == V_140 ) {
F_83 ( V_34 , V_2 ,
V_30 ) ;
V_30 -> V_74 = V_75 ;
}
V_2 -> V_16 = false ;
F_56 ( V_23 , V_30 ) ;
if ( F_60 ( & V_2 -> V_90 ) )
F_73 ( V_2 -> V_18 ) ;
}
}
F_4 ( & V_2 -> V_32 ) ;
}
return;
}
static int F_98 ( struct V_183 * V_184 )
{
struct V_41 * V_18 = & V_184 -> V_18 ;
struct V_22 * V_23 ;
struct V_185 * V_131 ;
int V_11 ;
V_23 = F_99 ( V_18 , sizeof( * V_23 ) , V_12 ) ;
if ( ! V_23 )
return - V_63 ;
F_34 ( & V_23 -> V_26 ) ;
F_34 ( & V_23 -> V_72 ) ;
F_100 ( & V_23 -> V_25 ) ;
F_100 ( & V_23 -> V_71 ) ;
V_23 -> V_179 = F_101 ( L_88 ) ;
if ( ! V_23 -> V_179 ) {
F_102 ( V_18 , L_89 ) ;
return - V_21 ;
}
V_23 -> V_139 = F_101 ( L_90 ) ;
if ( ! V_23 -> V_139 ) {
F_102 ( V_18 , L_91 ) ;
V_11 = - V_21 ;
goto V_186;
}
V_131 = & V_23 -> V_131 ;
V_131 -> V_18 = V_18 ;
V_131 -> V_187 = F_90 ;
V_131 -> remove = F_95 ;
V_131 -> V_188 = F_96 ;
V_131 -> V_189 = F_97 ;
F_103 ( V_184 , V_23 ) ;
V_11 = F_104 ( V_131 ) ;
if ( V_11 < 0 ) {
F_24 ( L_92 ) ;
goto V_190;
}
F_105 ( V_18 , L_93 ) ;
return 0 ;
V_190:
F_106 ( V_23 -> V_139 ) ;
V_186:
F_106 ( V_23 -> V_179 ) ;
return V_11 ;
}
static int F_107 ( struct V_183 * V_184 )
{
struct V_22 * V_23 = F_108 ( V_184 ) ;
F_109 ( & V_23 -> V_131 ) ;
F_110 ( & V_23 -> V_25 ) ;
F_110 ( & V_23 -> V_71 ) ;
F_58 ( & V_23 -> V_26 ) ;
F_58 ( & V_23 -> V_72 ) ;
F_106 ( V_23 -> V_139 ) ;
F_106 ( V_23 -> V_179 ) ;
return 0 ;
}
