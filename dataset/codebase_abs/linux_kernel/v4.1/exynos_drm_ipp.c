int F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 )
return - V_4 ;
V_2 = F_2 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_3 ( V_2 ) )
return F_4 ( V_2 ) ;
V_3 = V_2 ;
return 0 ;
}
void F_5 ( void )
{
if ( V_3 ) {
F_6 ( V_3 ) ;
V_3 = NULL ;
}
}
int F_7 ( struct V_5 * V_6 )
{
F_8 ( & V_7 ) ;
F_9 ( & V_6 -> V_8 , & V_9 ) ;
F_10 ( & V_7 ) ;
return 0 ;
}
int F_11 ( struct V_5 * V_6 )
{
F_8 ( & V_7 ) ;
F_12 ( & V_6 -> V_8 ) ;
F_10 ( & V_7 ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , struct V_12 * V_13 , void * V_14 )
{
int V_15 ;
F_8 ( V_13 ) ;
V_15 = F_14 ( V_11 , V_14 , 1 , 0 , V_16 ) ;
F_10 ( V_13 ) ;
return V_15 ;
}
static void F_15 ( struct V_10 * V_11 , struct V_12 * V_13 , T_1 V_17 )
{
F_8 ( V_13 ) ;
F_16 ( V_11 , V_17 ) ;
F_10 ( V_13 ) ;
}
static void * F_17 ( struct V_10 * V_11 , struct V_12 * V_13 , T_1 V_17 )
{
void * V_14 ;
F_8 ( V_13 ) ;
V_14 = F_18 ( V_11 , V_17 ) ;
F_10 ( V_13 ) ;
return V_14 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
if ( V_6 -> V_20 || ( ! F_20 ( V_19 -> V_21 ) &&
! F_21 ( V_6 -> V_22 ) ) )
return - V_23 ;
if ( V_6 -> V_24 &&
V_6 -> V_24 ( V_6 -> V_22 , V_19 ) )
return - V_25 ;
return 0 ;
}
static struct V_5 * F_22 ( struct V_26 * V_27 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 ;
T_1 V_28 = V_19 -> V_28 ;
int V_15 ;
if ( V_28 ) {
V_6 = F_17 ( & V_27 -> V_29 , & V_27 -> V_30 , V_28 ) ;
if ( ! V_6 ) {
F_23 ( L_2 , V_28 ) ;
return F_24 ( - V_31 ) ;
}
V_15 = F_19 ( V_6 , V_19 ) ;
if ( V_15 < 0 ) {
F_23 ( L_3 , V_28 , V_15 ) ;
return F_24 ( V_15 ) ;
}
return V_6 ;
} else {
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
V_15 = F_19 ( V_6 , V_19 ) ;
if ( V_15 == 0 )
return V_6 ;
}
F_23 ( L_4 ) ;
}
return F_24 ( - V_31 ) ;
}
static struct V_5 * F_26 ( T_1 V_32 )
{
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int V_35 = 0 ;
F_27 ( L_5 , V_32 ) ;
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_27 ( L_6 , V_35 ++ , ( int ) V_6 ) ;
F_8 ( & V_6 -> V_36 ) ;
F_25 (c_node, &ippdrv->cmd_list, list) {
if ( V_34 -> V_19 . V_32 == V_32 ) {
F_10 ( & V_6 -> V_36 ) ;
return V_6 ;
}
}
F_10 ( & V_6 -> V_36 ) ;
}
return F_24 ( - V_31 ) ;
}
int F_28 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_47 * V_48 = V_39 ;
struct V_5 * V_6 ;
int V_35 = 0 ;
if ( ! V_27 ) {
F_30 ( L_7 ) ;
return - V_25 ;
}
if ( ! V_48 ) {
F_30 ( L_8 ) ;
return - V_25 ;
}
F_27 ( L_9 , V_48 -> V_28 ) ;
if ( ! V_48 -> V_28 ) {
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list)
V_35 ++ ;
V_48 -> V_35 = V_35 ;
} else {
V_6 = F_17 ( & V_27 -> V_29 , & V_27 -> V_30 ,
V_48 -> V_28 ) ;
if ( ! V_6 ) {
F_30 ( L_10 ,
V_48 -> V_28 ) ;
return - V_31 ;
}
* V_48 = V_6 -> V_48 ;
}
return 0 ;
}
static void F_31 ( struct V_18 * V_19 ,
int V_49 )
{
struct V_50 * V_51 = & V_19 -> V_51 [ V_49 ] ;
struct V_52 * V_53 = & V_51 -> V_53 ;
struct V_54 * V_55 = & V_51 -> V_55 ;
F_27 ( L_11 ,
V_19 -> V_32 , V_49 ? L_12 : L_13 , V_51 -> V_56 ) ;
F_27 ( L_14 ,
V_53 -> V_57 , V_53 -> V_58 , V_53 -> V_59 , V_53 -> V_60 ,
V_55 -> V_61 , V_55 -> V_62 , V_51 -> V_63 , V_51 -> V_64 ) ;
}
static struct V_65 * F_32 ( void )
{
struct V_65 * V_66 ;
V_66 = F_33 ( sizeof( * V_66 ) , V_16 ) ;
if ( ! V_66 )
return F_24 ( - V_67 ) ;
F_34 ( (struct V_68 * ) V_66 , V_69 ) ;
return V_66 ;
}
static struct V_70 * F_35 ( void )
{
struct V_70 * V_71 ;
V_71 = F_33 ( sizeof( * V_71 ) , V_16 ) ;
if ( ! V_71 )
return F_24 ( - V_67 ) ;
F_34 ( & V_71 -> V_72 , V_73 ) ;
return V_71 ;
}
int F_36 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_18 * V_19 = V_39 ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
T_1 V_32 ;
int V_15 , V_74 ;
if ( ! V_27 ) {
F_30 ( L_7 ) ;
return - V_25 ;
}
if ( ! V_19 ) {
F_30 ( L_8 ) ;
return - V_25 ;
}
V_32 = V_19 -> V_32 ;
F_37 (i)
F_31 ( V_19 , V_74 ) ;
if ( V_32 ) {
V_34 = F_17 ( & V_27 -> V_75 , & V_27 -> V_76 , V_32 ) ;
if ( ! V_34 || V_34 -> V_77 != V_41 ) {
F_27 ( L_15 , V_32 ) ;
return - V_25 ;
}
if ( V_34 -> V_78 != V_79 ) {
F_27 ( L_16 , V_32 ) ;
return - V_25 ;
}
V_34 -> V_19 = * V_19 ;
return 0 ;
}
V_6 = F_22 ( V_27 , V_19 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_17 ) ;
return - V_25 ;
}
V_34 = F_33 ( sizeof( * V_34 ) , V_16 ) ;
if ( ! V_34 )
return - V_67 ;
V_15 = F_13 ( & V_27 -> V_75 , & V_27 -> V_76 , V_34 ) ;
if ( V_15 < 0 ) {
F_30 ( L_18 ) ;
goto V_80;
}
V_19 -> V_32 = V_15 ;
F_27 ( L_19 ,
V_19 -> V_32 , V_19 -> V_21 , ( int ) V_6 ) ;
V_34 -> V_19 = * V_19 ;
V_34 -> V_78 = V_81 ;
V_34 -> V_77 = V_41 ;
V_34 -> V_82 = F_32 () ;
if ( F_3 ( V_34 -> V_82 ) ) {
F_30 ( L_20 ) ;
V_15 = F_4 ( V_34 -> V_82 ) ;
goto V_83;
}
V_34 -> V_84 = F_32 () ;
if ( F_3 ( V_34 -> V_84 ) ) {
F_30 ( L_21 ) ;
V_15 = F_4 ( V_34 -> V_84 ) ;
goto V_85;
}
V_34 -> V_71 = F_35 () ;
if ( F_3 ( V_34 -> V_71 ) ) {
F_30 ( L_22 ) ;
V_15 = F_4 ( V_34 -> V_71 ) ;
goto V_86;
}
F_38 ( & V_34 -> V_13 ) ;
F_38 ( & V_34 -> V_87 ) ;
F_38 ( & V_34 -> V_88 ) ;
F_39 ( & V_34 -> V_89 ) ;
F_39 ( & V_34 -> V_90 ) ;
F_37 (i)
F_40 ( & V_34 -> V_91 [ V_74 ] ) ;
F_40 ( & V_34 -> V_92 ) ;
F_8 ( & V_6 -> V_36 ) ;
F_9 ( & V_34 -> V_93 , & V_6 -> V_94 ) ;
F_10 ( & V_6 -> V_36 ) ;
if ( ! F_20 ( V_19 -> V_21 ) )
V_6 -> V_20 = true ;
return 0 ;
V_86:
F_41 ( V_34 -> V_84 ) ;
V_85:
F_41 ( V_34 -> V_82 ) ;
V_83:
F_15 ( & V_27 -> V_75 , & V_27 -> V_76 , V_19 -> V_32 ) ;
V_80:
F_41 ( V_34 ) ;
return V_15 ;
}
static int F_42 ( struct V_37 * V_38 ,
struct V_95 * V_96 ,
struct V_33 * V_34 )
{
struct V_50 * V_97 ;
unsigned int V_98 ;
unsigned long V_99 , V_100 ;
unsigned int V_101 ;
int V_74 ;
V_97 = & V_34 -> V_19 . V_51 [ V_96 -> V_32 ] ;
V_98 = F_43 ( V_97 -> V_56 ) ;
for ( V_74 = 0 ; V_74 < V_98 ; ++ V_74 ) {
if ( ! V_96 -> V_102 . V_103 [ V_74 ] ) {
F_30 ( L_23 , V_74 ) ;
return - V_25 ;
}
V_101 = F_44 ( V_97 -> V_56 , V_74 ) ;
V_99 = ( V_97 -> V_55 . V_61 * V_97 -> V_55 . V_62 * V_101 ) >> 3 ;
V_100 = F_45 ( V_38 ,
V_96 -> V_102 . V_103 [ V_74 ] ,
V_34 -> V_77 ) ;
if ( V_99 > V_100 ) {
F_30 ( L_24 , V_74 ) ;
return - V_25 ;
}
}
return 0 ;
}
static int F_46 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_95 * V_96 )
{
int V_74 ;
F_27 ( L_25 , ( int ) V_96 ) ;
if ( ! V_96 ) {
F_30 ( L_26 ) ;
return - V_104 ;
}
F_27 ( L_27 , V_96 -> V_105 ) ;
F_47 (i) {
unsigned long V_106 = V_96 -> V_102 . V_103 [ V_74 ] ;
if ( V_106 )
F_48 ( V_38 , V_106 ,
V_34 -> V_77 ) ;
}
F_12 ( & V_96 -> V_93 ) ;
F_41 ( V_96 ) ;
return 0 ;
}
static struct V_95
* F_49 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_107 * V_108 )
{
struct V_95 * V_96 ;
struct V_109 * V_102 ;
int V_74 ;
V_96 = F_33 ( sizeof( * V_96 ) , V_16 ) ;
if ( ! V_96 )
return F_24 ( - V_67 ) ;
V_102 = & V_96 -> V_102 ;
V_96 -> V_105 = V_108 -> V_105 ;
V_96 -> V_32 = V_108 -> V_32 ;
V_96 -> V_110 = V_108 -> V_110 ;
F_40 ( & V_96 -> V_93 ) ;
F_27 ( L_28 , ( int ) V_96 , V_108 -> V_105 ) ;
F_27 ( L_29 , V_108 -> V_32 , V_96 -> V_110 ) ;
F_47 (i) {
F_27 ( L_30 , V_74 , V_108 -> V_106 [ V_74 ] ) ;
if ( V_108 -> V_106 [ V_74 ] ) {
T_2 * V_111 ;
V_111 = F_50 ( V_38 ,
V_108 -> V_106 [ V_74 ] , V_34 -> V_77 ) ;
if ( F_3 ( V_111 ) ) {
F_30 ( L_31 ) ;
F_46 ( V_38 , V_34 , V_96 ) ;
return F_24 ( - V_104 ) ;
}
V_102 -> V_103 [ V_74 ] = V_108 -> V_106 [ V_74 ] ;
V_102 -> V_112 [ V_74 ] = * V_111 ;
F_27 ( L_32 , V_74 ,
V_102 -> V_112 [ V_74 ] , V_102 -> V_103 [ V_74 ] ) ;
}
}
F_8 ( & V_34 -> V_87 ) ;
if ( F_42 ( V_38 , V_96 , V_34 ) ) {
F_46 ( V_38 , V_34 , V_96 ) ;
F_10 ( & V_34 -> V_87 ) ;
return F_24 ( - V_104 ) ;
}
F_9 ( & V_96 -> V_93 , & V_34 -> V_91 [ V_108 -> V_105 ] ) ;
F_10 ( & V_34 -> V_87 ) ;
return V_96 ;
}
static void F_51 ( struct V_37 * V_38 ,
struct V_33 * V_34 , int V_113 )
{
struct V_95 * V_96 , * V_114 ;
struct V_115 * V_116 = & V_34 -> V_91 [ V_113 ] ;
F_8 ( & V_34 -> V_87 ) ;
F_52 (m_node, tm_node, head, list) {
int V_15 ;
V_15 = F_46 ( V_38 , V_34 , V_96 ) ;
if ( V_15 )
F_30 ( L_33 ) ;
}
F_10 ( & V_34 -> V_87 ) ;
}
static void F_53 ( struct V_117 * V_118 )
{
F_41 ( V_118 ) ;
}
static int F_54 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_107 * V_108 )
{
struct V_119 * V_120 ;
unsigned long V_121 ;
F_27 ( L_34 , V_108 -> V_105 , V_108 -> V_110 ) ;
V_120 = F_33 ( sizeof( * V_120 ) , V_16 ) ;
if ( ! V_120 ) {
F_55 ( & V_38 -> V_88 , V_121 ) ;
V_34 -> V_77 -> V_122 += sizeof( V_120 -> V_118 ) ;
F_56 ( & V_38 -> V_88 , V_121 ) ;
return - V_67 ;
}
V_120 -> V_118 . V_112 . type = V_123 ;
V_120 -> V_118 . V_112 . V_124 = sizeof( V_120 -> V_118 ) ;
V_120 -> V_118 . V_125 = V_108 -> V_125 ;
V_120 -> V_118 . V_32 = V_108 -> V_32 ;
V_120 -> V_118 . V_110 [ V_126 ] = V_108 -> V_110 ;
V_120 -> V_112 . V_118 = & V_120 -> V_118 . V_112 ;
V_120 -> V_112 . V_43 = V_34 -> V_77 ;
V_120 -> V_112 . V_127 = F_53 ;
F_8 ( & V_34 -> V_88 ) ;
F_9 ( & V_120 -> V_112 . V_128 , & V_34 -> V_92 ) ;
F_10 ( & V_34 -> V_88 ) ;
return 0 ;
}
static void F_57 ( struct V_33 * V_34 ,
struct V_107 * V_108 )
{
struct V_119 * V_120 , * V_129 ;
int V_35 = 0 ;
F_8 ( & V_34 -> V_88 ) ;
F_52 (e, te, &c_node->event_list, base.link) {
F_27 ( L_35 , V_35 ++ , ( int ) V_120 ) ;
if ( ! V_108 ) {
F_12 ( & V_120 -> V_112 . V_128 ) ;
F_41 ( V_120 ) ;
}
if ( V_108 && ( V_108 -> V_110 ==
V_120 -> V_118 . V_110 [ V_126 ] ) ) {
F_12 ( & V_120 -> V_112 . V_128 ) ;
F_41 ( V_120 ) ;
goto V_130;
}
}
V_130:
F_10 ( & V_34 -> V_88 ) ;
return;
}
static void F_58 ( struct V_26 * V_27 ,
struct V_33 * V_34 )
{
int V_74 ;
F_59 ( & V_34 -> V_82 -> V_72 ) ;
F_59 ( & V_34 -> V_84 -> V_72 ) ;
F_59 ( & V_34 -> V_71 -> V_72 ) ;
F_57 ( V_34 , NULL ) ;
F_37 (i)
F_51 ( V_27 -> V_131 . V_38 , V_34 , V_74 ) ;
F_12 ( & V_34 -> V_93 ) ;
F_15 ( & V_27 -> V_75 , & V_27 -> V_76 ,
V_34 -> V_19 . V_32 ) ;
F_60 ( & V_34 -> V_13 ) ;
F_60 ( & V_34 -> V_87 ) ;
F_60 ( & V_34 -> V_88 ) ;
F_41 ( V_34 -> V_82 ) ;
F_41 ( V_34 -> V_84 ) ;
F_41 ( V_34 -> V_71 ) ;
F_41 ( V_34 ) ;
}
static bool F_61 ( struct V_33 * V_34 )
{
switch ( V_34 -> V_19 . V_21 ) {
case V_132 :
return ! F_62 ( & V_34 -> V_91 [ V_126 ] ) ;
case V_133 :
return ! F_62 ( & V_34 -> V_91 [ V_134 ] ) ;
case V_135 :
default:
return ! F_62 ( & V_34 -> V_91 [ V_134 ] ) &&
! F_62 ( & V_34 -> V_91 [ V_126 ] ) ;
}
}
static struct V_95
* F_63 ( struct V_33 * V_34 ,
struct V_107 * V_108 )
{
struct V_95 * V_96 ;
struct V_115 * V_116 ;
int V_35 = 0 ;
F_27 ( L_36 , V_108 -> V_110 ) ;
V_116 = & V_34 -> V_91 [ V_108 -> V_105 ] ;
F_25 (m_node, head, list) {
F_27 ( L_37 , V_35 ++ , ( int ) V_96 ) ;
if ( V_96 -> V_110 == V_108 -> V_110 )
return V_96 ;
}
return NULL ;
}
static int F_64 ( struct V_5 * V_6 ,
struct V_33 * V_34 ,
struct V_95 * V_96 )
{
struct V_136 * V_113 = NULL ;
int V_15 = 0 ;
F_27 ( L_25 , ( int ) V_96 ) ;
if ( ! V_96 ) {
F_30 ( L_38 ) ;
return - V_104 ;
}
F_27 ( L_27 , V_96 -> V_105 ) ;
V_113 = V_6 -> V_113 [ V_96 -> V_105 ] ;
if ( ! V_113 ) {
F_30 ( L_39 ) ;
return - V_104 ;
}
if ( V_113 -> V_137 ) {
V_15 = V_113 -> V_137 ( V_6 -> V_22 , & V_96 -> V_102 ,
V_96 -> V_110 , V_138 ) ;
if ( V_15 ) {
F_30 ( L_40 ) ;
return V_15 ;
}
}
return V_15 ;
}
static void F_65 ( struct V_45 * V_22 ,
struct V_5 * V_6 ,
struct V_65 * V_66 ,
struct V_33 * V_34 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
V_66 -> V_6 = V_6 ;
V_66 -> V_34 = V_34 ;
F_66 ( V_27 -> V_139 , & V_66 -> V_72 ) ;
}
static int F_67 ( struct V_45 * V_22 ,
struct V_33 * V_34 ,
struct V_95 * V_96 ,
struct V_107 * V_108 )
{
struct V_5 * V_6 ;
struct V_18 * V_19 ;
struct V_136 * V_113 ;
int V_15 ;
V_6 = F_26 ( V_108 -> V_32 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_17 ) ;
return - V_104 ;
}
V_113 = V_6 -> V_113 [ V_108 -> V_105 ] ;
if ( ! V_113 ) {
F_30 ( L_41 ) ;
return - V_104 ;
}
V_19 = & V_34 -> V_19 ;
if ( V_34 -> V_78 != V_140 ) {
F_27 ( L_42 ) ;
return 0 ;
}
F_8 ( & V_34 -> V_87 ) ;
if ( ! F_61 ( V_34 ) ) {
F_10 ( & V_34 -> V_87 ) ;
F_27 ( L_43 ) ;
return 0 ;
}
if ( F_20 ( V_19 -> V_21 ) ) {
struct V_65 * V_66 = V_34 -> V_82 ;
V_66 -> V_141 = V_142 ;
F_65 ( V_22 , V_6 , V_66 , V_34 ) ;
} else {
V_15 = F_64 ( V_6 , V_34 , V_96 ) ;
if ( V_15 ) {
F_10 ( & V_34 -> V_87 ) ;
F_30 ( L_44 ) ;
return V_15 ;
}
}
F_10 ( & V_34 -> V_87 ) ;
return 0 ;
}
static void F_68 ( struct V_37 * V_38 ,
struct V_33 * V_34 ,
struct V_107 * V_108 )
{
struct V_95 * V_96 , * V_114 ;
F_8 ( & V_34 -> V_87 ) ;
F_52 (m_node, tm_node,
&c_node->mem_list[qbuf->ops_id], list) {
if ( V_96 -> V_110 == V_108 -> V_110 &&
V_96 -> V_105 == V_108 -> V_105 )
F_46 ( V_38 , V_34 , V_96 ) ;
}
F_10 ( & V_34 -> V_87 ) ;
}
int F_69 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_107 * V_108 = V_39 ;
struct V_33 * V_34 ;
struct V_95 * V_96 ;
int V_15 ;
if ( ! V_108 ) {
F_30 ( L_45 ) ;
return - V_25 ;
}
if ( V_108 -> V_105 >= V_143 ) {
F_30 ( L_46 ) ;
return - V_25 ;
}
F_27 ( L_47 ,
V_108 -> V_32 , V_108 -> V_105 ? L_12 : L_13 ,
V_108 -> V_110 , V_108 -> V_144 ) ;
V_34 = F_17 ( & V_27 -> V_75 , & V_27 -> V_76 ,
V_108 -> V_32 ) ;
if ( ! V_34 || V_34 -> V_77 != V_41 ) {
F_30 ( L_48 ) ;
return - V_31 ;
}
switch ( V_108 -> V_144 ) {
case V_138 :
V_96 = F_49 ( V_38 , V_34 , V_108 ) ;
if ( F_3 ( V_96 ) ) {
F_30 ( L_49 ) ;
return F_4 ( V_96 ) ;
}
if ( V_108 -> V_105 == V_126 ) {
V_15 = F_54 ( V_38 , V_34 , V_108 ) ;
if ( V_15 ) {
F_30 ( L_50 ) ;
goto V_145;
}
V_15 = F_67 ( V_22 , V_34 , V_96 , V_108 ) ;
if ( V_15 ) {
F_30 ( L_51 ) ;
goto V_145;
}
}
break;
case V_146 :
F_8 ( & V_34 -> V_13 ) ;
if ( V_108 -> V_105 == V_126 )
F_57 ( V_34 , V_108 ) ;
F_68 ( V_38 , V_34 , V_108 ) ;
F_10 ( & V_34 -> V_13 ) ;
break;
default:
F_30 ( L_52 ) ;
return - V_25 ;
}
return 0 ;
V_145:
F_30 ( L_53 ) ;
F_68 ( V_38 , V_34 , V_108 ) ;
return V_15 ;
}
static bool F_70 ( struct V_45 * V_22 ,
enum V_147 V_141 , enum V_148 V_78 )
{
if ( V_141 != V_142 ) {
if ( F_21 ( V_22 ) ) {
F_30 ( L_54 ) ;
goto V_149;
}
}
switch ( V_141 ) {
case V_142 :
if ( V_78 != V_81 )
goto V_149;
break;
case V_150 :
if ( V_78 == V_79 )
goto V_149;
break;
case V_151 :
if ( V_78 != V_140 )
goto V_149;
break;
case V_152 :
if ( V_78 != V_79 )
goto V_149;
break;
default:
F_30 ( L_55 ) ;
goto V_149;
}
return true ;
V_149:
F_30 ( L_56 , V_141 , V_78 ) ;
return false ;
}
int F_71 ( struct V_37 * V_38 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
struct V_5 * V_6 = NULL ;
struct V_45 * V_22 = V_43 -> V_46 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_153 * V_154 = V_39 ;
struct V_65 * V_66 ;
struct V_33 * V_34 ;
if ( ! V_27 ) {
F_30 ( L_7 ) ;
return - V_25 ;
}
if ( ! V_154 ) {
F_30 ( L_57 ) ;
return - V_25 ;
}
F_27 ( L_58 ,
V_154 -> V_141 , V_154 -> V_32 ) ;
V_6 = F_26 ( V_154 -> V_32 ) ;
if ( F_3 ( V_6 ) ) {
F_30 ( L_17 ) ;
return F_4 ( V_6 ) ;
}
V_34 = F_17 ( & V_27 -> V_75 , & V_27 -> V_76 ,
V_154 -> V_32 ) ;
if ( ! V_34 || V_34 -> V_77 != V_41 ) {
F_30 ( L_59 ) ;
return - V_31 ;
}
if ( ! F_70 ( V_6 -> V_22 , V_154 -> V_141 ,
V_34 -> V_78 ) ) {
F_30 ( L_55 ) ;
return - V_25 ;
}
switch ( V_154 -> V_141 ) {
case V_142 :
if ( F_21 ( V_6 -> V_22 ) )
F_72 ( V_6 -> V_22 ) ;
V_34 -> V_78 = V_140 ;
V_66 = V_34 -> V_82 ;
V_66 -> V_141 = V_154 -> V_141 ;
F_65 ( V_22 , V_6 , V_66 , V_34 ) ;
break;
case V_150 :
V_66 = V_34 -> V_84 ;
V_66 -> V_141 = V_154 -> V_141 ;
F_65 ( V_22 , V_6 , V_66 , V_34 ) ;
if ( ! F_73 ( & V_34 -> V_90 ,
F_74 ( 300 ) ) ) {
F_30 ( L_60 ,
V_34 -> V_19 . V_32 ) ;
}
V_34 -> V_78 = V_79 ;
V_6 -> V_20 = false ;
F_8 ( & V_6 -> V_36 ) ;
F_58 ( V_27 , V_34 ) ;
if ( F_62 ( & V_6 -> V_94 ) )
F_75 ( V_6 -> V_22 ) ;
F_10 ( & V_6 -> V_36 ) ;
break;
case V_151 :
V_66 = V_34 -> V_84 ;
V_66 -> V_141 = V_154 -> V_141 ;
F_65 ( V_22 , V_6 , V_66 , V_34 ) ;
if ( ! F_73 ( & V_34 -> V_90 ,
F_74 ( 200 ) ) ) {
F_30 ( L_60 ,
V_34 -> V_19 . V_32 ) ;
}
V_34 -> V_78 = V_79 ;
break;
case V_152 :
V_34 -> V_78 = V_140 ;
V_66 = V_34 -> V_82 ;
V_66 -> V_141 = V_154 -> V_141 ;
F_65 ( V_22 , V_6 , V_66 , V_34 ) ;
break;
default:
F_30 ( L_61 ) ;
return - V_25 ;
}
F_27 ( L_62 ,
V_154 -> V_141 , V_154 -> V_32 ) ;
return 0 ;
}
int F_76 ( struct V_155 * V_156 )
{
return F_77 (
& V_157 , V_156 ) ;
}
int F_78 ( struct V_155 * V_156 )
{
return F_79 (
& V_157 , V_156 ) ;
}
int F_80 ( unsigned long V_158 , void * V_159 )
{
return F_81 (
& V_157 , V_158 , V_159 ) ;
}
static int F_82 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_136 * V_113 = NULL ;
bool V_160 = false ;
int V_15 , V_74 ;
if ( ! V_19 ) {
F_30 ( L_8 ) ;
return - V_25 ;
}
F_27 ( L_5 , V_19 -> V_32 ) ;
if ( V_6 -> V_161 &&
V_6 -> V_161 ( V_6 -> V_22 ) ) {
return - V_25 ;
}
F_37 (i) {
struct V_50 * V_51 =
& V_19 -> V_51 [ V_74 ] ;
V_113 = V_6 -> V_113 [ V_74 ] ;
if ( ! V_113 || ! V_51 ) {
F_30 ( L_63 ) ;
return - V_25 ;
}
if ( V_113 -> V_162 ) {
V_15 = V_113 -> V_162 ( V_6 -> V_22 , V_51 -> V_56 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_113 -> V_163 ) {
V_15 = V_113 -> V_163 ( V_6 -> V_22 , V_51 -> V_64 ,
V_51 -> V_63 , & V_160 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_113 -> V_164 ) {
V_15 = V_113 -> V_164 ( V_6 -> V_22 , V_160 , & V_51 -> V_53 ,
& V_51 -> V_55 ) ;
if ( V_15 )
return V_15 ;
}
}
return 0 ;
}
static int F_83 ( struct V_5 * V_6 ,
struct V_33 * V_34 )
{
struct V_95 * V_96 ;
struct V_18 * V_19 = & V_34 -> V_19 ;
struct V_115 * V_116 ;
int V_15 , V_74 ;
F_27 ( L_5 , V_19 -> V_32 ) ;
V_6 -> V_34 = V_34 ;
F_8 ( & V_34 -> V_87 ) ;
if ( ! F_61 ( V_34 ) ) {
F_27 ( L_43 ) ;
V_15 = - V_67 ;
goto V_165;
}
V_15 = F_82 ( V_6 , V_19 ) ;
if ( V_15 ) {
F_30 ( L_64 ) ;
V_6 -> V_34 = NULL ;
goto V_165;
}
switch ( V_19 -> V_21 ) {
case V_135 :
F_37 (i) {
V_116 = & V_34 -> V_91 [ V_74 ] ;
V_96 = F_84 ( V_116 ,
struct V_95 , V_93 ) ;
F_27 ( L_65 , ( int ) V_96 ) ;
V_15 = F_64 ( V_6 , V_34 , V_96 ) ;
if ( V_15 ) {
F_30 ( L_44 ) ;
goto V_165;
}
}
break;
case V_132 :
V_116 = & V_34 -> V_91 [ V_126 ] ;
F_25 (m_node, head, list) {
V_15 = F_64 ( V_6 , V_34 , V_96 ) ;
if ( V_15 ) {
F_30 ( L_44 ) ;
goto V_165;
}
}
break;
case V_133 :
V_116 = & V_34 -> V_91 [ V_134 ] ;
F_25 (m_node, head, list) {
V_15 = F_64 ( V_6 , V_34 , V_96 ) ;
if ( V_15 ) {
F_30 ( L_44 ) ;
goto V_165;
}
}
break;
default:
F_30 ( L_66 ) ;
V_15 = - V_25 ;
goto V_165;
}
F_10 ( & V_34 -> V_87 ) ;
F_27 ( L_67 , V_19 -> V_21 ) ;
if ( V_6 -> V_166 ) {
V_15 = V_6 -> V_166 ( V_6 -> V_22 , V_19 -> V_21 ) ;
if ( V_15 ) {
F_30 ( L_68 ) ;
V_6 -> V_34 = NULL ;
return V_15 ;
}
}
return 0 ;
V_165:
F_10 ( & V_34 -> V_87 ) ;
V_6 -> V_34 = NULL ;
return V_15 ;
}
static int F_85 ( struct V_37 * V_38 ,
struct V_5 * V_6 ,
struct V_33 * V_34 )
{
struct V_18 * V_19 = & V_34 -> V_19 ;
int V_74 ;
F_27 ( L_5 , V_19 -> V_32 ) ;
if ( V_6 -> V_167 )
V_6 -> V_167 ( V_6 -> V_22 , V_19 -> V_21 ) ;
switch ( V_19 -> V_21 ) {
case V_135 :
F_37 (i)
F_51 ( V_38 , V_34 , V_74 ) ;
break;
case V_132 :
F_51 ( V_38 , V_34 , V_126 ) ;
break;
case V_133 :
F_51 ( V_38 , V_34 , V_134 ) ;
break;
default:
F_30 ( L_66 ) ;
return - V_25 ;
}
return 0 ;
}
void V_69 ( struct V_68 * V_72 )
{
struct V_65 * V_66 =
F_86 ( V_72 , struct V_65 , V_72 ) ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
struct V_18 * V_19 ;
int V_15 ;
V_6 = V_66 -> V_6 ;
if ( ! V_6 ) {
F_30 ( L_69 ) ;
return;
}
V_34 = V_66 -> V_34 ;
if ( ! V_34 ) {
F_30 ( L_59 ) ;
return;
}
F_8 ( & V_34 -> V_13 ) ;
V_19 = & V_34 -> V_19 ;
switch ( V_66 -> V_141 ) {
case V_142 :
case V_152 :
V_15 = F_83 ( V_6 , V_34 ) ;
if ( V_15 ) {
F_30 ( L_70 ,
V_34 -> V_19 . V_32 ) ;
goto V_165;
}
if ( F_20 ( V_19 -> V_21 ) ) {
if ( ! F_73
( & V_34 -> V_89 , F_74 ( 200 ) ) ) {
F_30 ( L_71 ,
V_34 -> V_19 . V_32 ) ;
goto V_165;
}
}
break;
case V_150 :
case V_151 :
V_15 = F_85 ( V_6 -> V_38 , V_6 ,
V_34 ) ;
if ( V_15 ) {
F_30 ( L_72 ) ;
goto V_165;
}
F_87 ( & V_34 -> V_90 ) ;
break;
default:
F_30 ( L_73 ) ;
break;
}
F_27 ( L_74 , V_66 -> V_141 ) ;
V_165:
F_10 ( & V_34 -> V_13 ) ;
}
static int F_88 ( struct V_5 * V_6 ,
struct V_33 * V_34 , int * V_110 )
{
struct V_37 * V_38 = V_6 -> V_38 ;
struct V_18 * V_19 = & V_34 -> V_19 ;
struct V_95 * V_96 ;
struct V_107 V_108 ;
struct V_119 * V_120 ;
struct V_115 * V_116 ;
struct V_168 V_169 ;
unsigned long V_121 ;
T_1 V_170 [ V_143 ] = { 0 , } ;
int V_15 , V_74 ;
F_37 (i)
F_27 ( L_75 , V_74 ? L_12 : L_13 , V_110 [ V_74 ] ) ;
if ( ! V_38 ) {
F_30 ( L_76 ) ;
return - V_25 ;
}
if ( ! V_19 ) {
F_30 ( L_77 ) ;
return - V_25 ;
}
F_8 ( & V_34 -> V_88 ) ;
if ( F_62 ( & V_34 -> V_92 ) ) {
F_27 ( L_78 ) ;
V_15 = 0 ;
goto V_171;
}
F_8 ( & V_34 -> V_87 ) ;
if ( ! F_61 ( V_34 ) ) {
F_27 ( L_43 ) ;
V_15 = 0 ;
goto V_172;
}
switch ( V_19 -> V_21 ) {
case V_135 :
F_37 (i) {
V_116 = & V_34 -> V_91 [ V_74 ] ;
V_96 = F_84 ( V_116 ,
struct V_95 , V_93 ) ;
V_170 [ V_74 ] = V_96 -> V_110 ;
F_27 ( L_75 ,
V_74 ? L_12 : L_13 , V_170 [ V_74 ] ) ;
V_15 = F_46 ( V_38 , V_34 , V_96 ) ;
if ( V_15 )
F_30 ( L_33 ) ;
}
break;
case V_132 :
memset ( & V_108 , 0x0 , sizeof( V_108 ) ) ;
V_108 . V_105 = V_126 ;
V_108 . V_110 = V_110 [ V_126 ] ;
V_96 = F_63 ( V_34 , & V_108 ) ;
if ( ! V_96 ) {
F_30 ( L_79 ) ;
V_15 = - V_67 ;
goto V_172;
}
V_170 [ V_126 ] = V_96 -> V_110 ;
V_15 = F_46 ( V_38 , V_34 , V_96 ) ;
if ( V_15 )
F_30 ( L_33 ) ;
break;
case V_133 :
V_116 = & V_34 -> V_91 [ V_134 ] ;
V_96 = F_84 ( V_116 ,
struct V_95 , V_93 ) ;
V_170 [ V_134 ] = V_96 -> V_110 ;
V_15 = F_46 ( V_38 , V_34 , V_96 ) ;
if ( V_15 )
F_30 ( L_33 ) ;
break;
default:
F_30 ( L_66 ) ;
V_15 = - V_25 ;
goto V_172;
}
F_10 ( & V_34 -> V_87 ) ;
if ( V_170 [ V_126 ] != V_110 [ V_126 ] )
F_30 ( L_80 ,
V_170 [ 1 ] , V_110 [ 1 ] , V_19 -> V_32 ) ;
V_120 = F_84 ( & V_34 -> V_92 ,
struct V_119 , V_112 . V_128 ) ;
F_89 ( & V_169 ) ;
F_27 ( L_81 , V_169 . V_173 , V_169 . V_174 ) ;
V_120 -> V_118 . V_173 = V_169 . V_173 ;
V_120 -> V_118 . V_174 = V_169 . V_174 ;
V_120 -> V_118 . V_32 = V_19 -> V_32 ;
F_37 (i)
V_120 -> V_118 . V_110 [ V_74 ] = V_170 [ V_74 ] ;
F_55 ( & V_38 -> V_88 , V_121 ) ;
F_90 ( & V_120 -> V_112 . V_128 , & V_120 -> V_112 . V_43 -> V_92 ) ;
F_91 ( & V_120 -> V_112 . V_43 -> V_175 ) ;
F_56 ( & V_38 -> V_88 , V_121 ) ;
F_10 ( & V_34 -> V_88 ) ;
F_27 ( L_82 ,
V_19 -> V_21 , V_19 -> V_32 , V_170 [ V_126 ] ) ;
return 0 ;
V_172:
F_10 ( & V_34 -> V_87 ) ;
V_171:
F_10 ( & V_34 -> V_88 ) ;
return V_15 ;
}
void V_73 ( struct V_68 * V_72 )
{
struct V_70 * V_71 =
F_86 ( V_72 , struct V_70 , V_72 ) ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
int V_15 ;
if ( ! V_71 ) {
F_30 ( L_83 ) ;
return;
}
F_27 ( L_36 , V_71 -> V_110 [ V_126 ] ) ;
V_6 = V_71 -> V_6 ;
if ( ! V_6 ) {
F_30 ( L_17 ) ;
return;
}
V_34 = V_6 -> V_34 ;
if ( ! V_34 ) {
F_30 ( L_48 ) ;
return;
}
if ( V_34 -> V_78 != V_140 ) {
F_27 ( L_84 ,
V_34 -> V_78 , V_34 -> V_19 . V_32 ) ;
goto V_176;
}
V_15 = F_88 ( V_6 , V_34 , V_71 -> V_110 ) ;
if ( V_15 ) {
F_30 ( L_85 ) ;
goto V_176;
}
V_176:
if ( F_20 ( V_34 -> V_19 . V_21 ) )
F_87 ( & V_34 -> V_89 ) ;
}
static int F_92 ( struct V_37 * V_38 , struct V_45 * V_22 )
{
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_5 * V_6 ;
int V_15 , V_35 = 0 ;
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
V_6 -> V_38 = V_38 ;
V_15 = F_13 ( & V_27 -> V_29 , & V_27 -> V_30 , V_6 ) ;
if ( V_15 < 0 ) {
F_30 ( L_18 ) ;
goto V_177;
}
V_6 -> V_48 . V_28 = V_15 ;
F_27 ( L_86 ,
V_35 ++ , ( int ) V_6 , V_15 ) ;
V_6 -> V_178 = V_22 ;
V_6 -> V_179 = V_27 -> V_179 ;
V_6 -> V_180 = V_73 ;
F_40 ( & V_6 -> V_94 ) ;
F_38 ( & V_6 -> V_36 ) ;
if ( F_93 ( V_38 ) ) {
V_15 = F_94 ( V_38 , V_6 -> V_22 ) ;
if ( V_15 ) {
F_30 ( L_87 ) ;
goto V_177;
}
}
}
return 0 ;
V_177:
F_95 (ippdrv, &exynos_drm_ippdrv_list,
drv_list) {
if ( F_93 ( V_38 ) )
F_96 ( V_38 , V_6 -> V_22 ) ;
F_15 ( & V_27 -> V_29 , & V_27 -> V_30 ,
V_6 -> V_48 . V_28 ) ;
}
return V_15 ;
}
static void F_97 ( struct V_37 * V_38 , struct V_45 * V_22 )
{
struct V_5 * V_6 , * V_181 ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
F_52 (ippdrv, t, &exynos_drm_ippdrv_list, drv_list) {
if ( F_93 ( V_38 ) )
F_96 ( V_38 , V_6 -> V_22 ) ;
F_15 ( & V_27 -> V_29 , & V_27 -> V_30 ,
V_6 -> V_48 . V_28 ) ;
V_6 -> V_38 = NULL ;
F_11 ( V_6 ) ;
}
}
static int F_98 ( struct V_37 * V_38 , struct V_45 * V_22 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_44 ;
V_43 -> V_46 = V_22 ;
F_27 ( L_88 , ( int ) V_22 ) ;
return 0 ;
}
static void F_99 ( struct V_37 * V_38 , struct V_45 * V_22 ,
struct V_40 * V_41 )
{
struct V_5 * V_6 = NULL ;
struct V_26 * V_27 = F_29 ( V_22 ) ;
struct V_33 * V_34 , * V_182 ;
int V_35 = 0 ;
F_25 (ippdrv, &exynos_drm_ippdrv_list, drv_list) {
F_8 ( & V_6 -> V_36 ) ;
F_52 (c_node, tc_node,
&ippdrv->cmd_list, list) {
F_27 ( L_6 ,
V_35 ++ , ( int ) V_6 ) ;
if ( V_34 -> V_77 == V_41 ) {
if ( V_34 -> V_78 == V_140 ) {
F_85 ( V_38 , V_6 ,
V_34 ) ;
V_34 -> V_78 = V_79 ;
}
V_6 -> V_20 = false ;
F_58 ( V_27 , V_34 ) ;
if ( F_62 ( & V_6 -> V_94 ) )
F_75 ( V_6 -> V_22 ) ;
}
}
F_10 ( & V_6 -> V_36 ) ;
}
return;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_45 * V_22 = & V_2 -> V_22 ;
struct V_26 * V_27 ;
struct V_183 * V_131 ;
int V_15 ;
V_27 = F_101 ( V_22 , sizeof( * V_27 ) , V_16 ) ;
if ( ! V_27 )
return - V_67 ;
F_38 ( & V_27 -> V_30 ) ;
F_38 ( & V_27 -> V_76 ) ;
F_102 ( & V_27 -> V_29 ) ;
F_102 ( & V_27 -> V_75 ) ;
V_27 -> V_179 = F_103 ( L_89 ) ;
if ( ! V_27 -> V_179 ) {
F_104 ( V_22 , L_90 ) ;
return - V_25 ;
}
V_27 -> V_139 = F_103 ( L_91 ) ;
if ( ! V_27 -> V_139 ) {
F_104 ( V_22 , L_92 ) ;
V_15 = - V_25 ;
goto V_184;
}
V_131 = & V_27 -> V_131 ;
V_131 -> V_22 = V_22 ;
V_131 -> V_185 = F_92 ;
V_131 -> remove = F_97 ;
V_131 -> V_186 = F_98 ;
V_131 -> V_187 = F_99 ;
F_105 ( V_2 , V_27 ) ;
V_15 = F_106 ( V_131 ) ;
if ( V_15 < 0 ) {
F_30 ( L_93 ) ;
goto V_188;
}
F_107 ( V_22 , L_94 ) ;
return 0 ;
V_188:
F_108 ( V_27 -> V_139 ) ;
V_184:
F_108 ( V_27 -> V_179 ) ;
return V_15 ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_110 ( V_2 ) ;
F_111 ( & V_27 -> V_131 ) ;
F_112 ( & V_27 -> V_29 ) ;
F_112 ( & V_27 -> V_75 ) ;
F_60 ( & V_27 -> V_30 ) ;
F_60 ( & V_27 -> V_76 ) ;
F_108 ( V_27 -> V_139 ) ;
F_108 ( V_27 -> V_179 ) ;
return 0 ;
}
