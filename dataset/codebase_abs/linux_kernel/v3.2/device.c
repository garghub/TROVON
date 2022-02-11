static int F_1 ( int V_1 , void * V_2 , void * V_3 )
{
int * V_4 = V_3 ;
* V_4 = * V_4 + 1 ;
return 0 ;
}
static T_1 F_2 ( struct V_5 * V_5 , char T_2 * V_6 , T_3 V_7 ,
T_4 * V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
return F_3 ( V_6 , V_7 , V_8 , V_10 -> V_6 , V_10 -> V_12 ) ;
}
static int F_4 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
struct V_9 * V_15 = V_3 ;
int V_16 ;
int V_17 ;
if ( V_1 != V_14 -> V_18 . V_19 . V_20 )
return 0 ;
V_16 = V_15 -> V_21 - V_15 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
if ( V_14 -> V_22 )
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_1
L_2 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_23 . V_20 , ( int ) V_14 -> V_24 . V_25 ,
V_14 -> V_18 . V_19 . V_26 & V_27 ,
V_14 -> V_22 -> V_28 , ( int ) V_14 -> V_22 -> V_29 . V_25 ,
& V_14 -> V_22 -> V_29 . V_30 . V_31 . V_32 ,
F_5 ( V_14 -> V_22 -> V_29 . V_30 . V_33 ) ,
& V_14 -> V_22 -> V_29 . V_34 . V_31 . V_32 ,
F_5 ( V_14 -> V_22 -> V_29 . V_34 . V_33 ) ) ;
else
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_3 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_23 . V_20 ,
( int ) V_14 -> V_24 . V_25 ,
V_14 -> V_18 . V_19 . V_26 & V_27 ) ;
if ( V_17 < V_16 )
V_15 -> V_12 += V_17 ;
return 0 ;
}
static int F_6 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_15 = V_5 -> V_11 ;
if ( ! V_15 ) {
F_7 ( V_36 L_4 , V_37 ) ;
return 0 ;
}
F_8 ( V_15 -> V_6 ) ;
F_8 ( V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_15 ;
int V_38 = 0 ;
int V_7 = 1 ;
V_15 = F_10 ( sizeof *V_15 , V_39 ) ;
if ( ! V_15 ) {
V_38 = - V_40 ;
goto V_41;
}
V_15 -> V_42 = V_35 -> V_43 ;
V_15 -> V_12 = 0 ;
F_11 ( & V_15 -> V_42 -> V_44 ) ;
F_12 ( & V_15 -> V_42 -> V_45 , F_1 , & V_7 ) ;
F_13 ( & V_15 -> V_42 -> V_44 ) ;
V_15 -> V_21 = V_7 * 128 ;
V_15 -> V_6 = F_10 ( V_15 -> V_21 , V_39 ) ;
if ( ! V_15 -> V_6 ) {
V_38 = - V_40 ;
goto V_46;
}
F_11 ( & V_15 -> V_42 -> V_44 ) ;
F_12 ( & V_15 -> V_42 -> V_45 , F_4 , V_15 ) ;
F_13 ( & V_15 -> V_42 -> V_44 ) ;
V_15 -> V_6 [ V_15 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_15 ;
goto V_41;
V_46:
F_8 ( V_15 ) ;
V_41:
return V_38 ;
}
static int F_14 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_9 * V_47 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_47 -> V_21 - V_47 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
V_17 = snprintf ( V_47 -> V_6 + V_47 -> V_12 , V_16 , L_5 , V_1 << 8 ) ;
if ( V_17 < V_16 )
V_47 -> V_12 += V_17 ;
return 0 ;
}
static int F_15 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_47 = V_5 -> V_11 ;
if ( ! V_47 ) {
F_7 ( V_36 L_6 , V_37 ) ;
return 0 ;
}
F_8 ( V_47 -> V_6 ) ;
F_8 ( V_47 ) ;
return 0 ;
}
static int F_16 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_47 ;
int V_38 = 0 ;
int V_7 = 1 ;
V_47 = F_10 ( sizeof *V_47 , V_39 ) ;
if ( ! V_47 ) {
V_38 = - V_40 ;
goto V_41;
}
V_47 -> V_42 = V_35 -> V_43 ;
V_47 -> V_12 = 0 ;
F_11 ( & V_47 -> V_42 -> V_44 ) ;
F_12 ( & V_47 -> V_42 -> V_48 , F_1 , & V_7 ) ;
F_13 ( & V_47 -> V_42 -> V_44 ) ;
V_47 -> V_21 = V_7 * sizeof( L_7 ) ;
V_47 -> V_6 = F_10 ( V_47 -> V_21 , V_39 ) ;
if ( ! V_47 -> V_6 ) {
V_38 = - V_40 ;
goto V_46;
}
F_11 ( & V_47 -> V_42 -> V_44 ) ;
F_12 ( & V_47 -> V_42 -> V_48 , F_14 , V_47 ) ;
F_13 ( & V_47 -> V_42 -> V_44 ) ;
V_47 -> V_6 [ V_47 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_47 ;
goto V_41;
V_46:
F_8 ( V_47 ) ;
V_41:
return V_38 ;
}
static int F_17 ( struct V_49 * V_42 )
{
struct V_50 * V_51 ;
if ( ! V_42 -> V_52 )
return - 1 ;
V_51 = F_18 ( L_8 , V_53 , V_42 -> V_52 ,
( void * ) V_42 , & V_54 ) ;
if ( V_51 && V_51 -> V_55 )
V_51 -> V_55 -> V_56 = 4096 ;
V_51 = F_18 ( L_9 , V_53 , V_42 -> V_52 ,
( void * ) V_42 , & V_57 ) ;
if ( V_51 && V_51 -> V_55 )
V_51 -> V_55 -> V_56 = 4096 ;
return 0 ;
}
void F_19 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_62 * V_12 , * V_63 ;
struct V_64 * V_65 ;
F_20 ( & V_61 -> V_44 ) ;
F_21 (pos, nxt, &uctx->qpids) {
V_65 = F_22 ( V_12 , struct V_64 , V_65 ) ;
F_23 ( & V_65 -> V_65 ) ;
if ( ! ( V_65 -> V_20 & V_59 -> V_66 ) )
F_24 ( & V_59 -> V_67 . V_68 , V_65 -> V_20 ,
& V_59 -> V_67 . V_69 ) ;
F_8 ( V_65 ) ;
}
F_21 (pos, nxt, &uctx->qpids) {
V_65 = F_22 ( V_12 , struct V_64 , V_65 ) ;
F_23 ( & V_65 -> V_65 ) ;
F_8 ( V_65 ) ;
}
F_25 ( & V_61 -> V_44 ) ;
}
void F_26 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
F_27 ( & V_61 -> V_70 ) ;
F_27 ( & V_61 -> V_71 ) ;
F_28 ( & V_61 -> V_44 ) ;
}
static int F_29 ( struct V_58 * V_59 )
{
int V_72 ;
F_26 ( V_59 , & V_59 -> V_61 ) ;
V_59 -> V_73 = V_74 - F_30 ( V_59 -> V_75 . V_76 ) ;
V_59 -> V_66 = V_59 -> V_75 . V_76 - 1 ;
V_59 -> V_77 = V_74 - F_30 ( V_59 -> V_75 . V_78 ) ;
V_59 -> V_79 = V_59 -> V_75 . V_78 - 1 ;
F_31 ( L_10
L_11
L_12 ,
V_37 , F_32 ( V_59 -> V_75 . V_80 ) , V_59 -> V_75 . V_81 -> V_82 . V_83 ,
V_59 -> V_75 . V_81 -> V_82 . V_84 , F_33 ( V_59 ) ,
V_59 -> V_75 . V_81 -> V_85 . V_83 ,
V_59 -> V_75 . V_81 -> V_85 . V_84 , V_59 -> V_75 . V_81 -> V_23 . V_83 ,
V_59 -> V_75 . V_81 -> V_23 . V_84 ,
V_59 -> V_75 . V_81 -> V_14 . V_83 ,
V_59 -> V_75 . V_81 -> V_14 . V_84 ,
V_59 -> V_75 . V_81 -> V_86 . V_83 ,
V_59 -> V_75 . V_81 -> V_86 . V_84 ) ;
F_31 ( L_13
L_14 ,
( unsigned ) F_34 ( V_59 -> V_75 . V_80 , 2 ) ,
( void * ) F_35 ( V_59 -> V_75 . V_80 , 2 ) ,
V_59 -> V_75 . V_87 ,
V_59 -> V_75 . V_88 ,
V_59 -> V_73 , V_59 -> V_66 ,
V_59 -> V_77 , V_59 -> V_79 ) ;
if ( F_33 ( V_59 ) == 0 ) {
V_72 = - V_89 ;
goto V_46;
}
V_72 = F_36 ( V_59 , F_33 ( V_59 ) , V_90 ) ;
if ( V_72 ) {
F_7 (KERN_ERR MOD L_15 , err) ;
goto V_46;
}
V_72 = F_37 ( V_59 ) ;
if ( V_72 ) {
F_7 (KERN_ERR MOD L_16 , err) ;
goto V_91;
}
V_72 = F_38 ( V_59 ) ;
if ( V_72 ) {
F_7 (KERN_ERR MOD L_17 , err) ;
goto V_92;
}
V_72 = F_39 ( V_59 ) ;
if ( V_72 ) {
F_7 (KERN_ERR MOD L_18 , err) ;
goto V_93;
}
return 0 ;
V_93:
F_40 ( V_59 ) ;
V_92:
F_41 ( V_59 ) ;
V_91:
F_42 ( & V_59 -> V_67 ) ;
V_46:
return V_72 ;
}
static void F_43 ( struct V_58 * V_59 )
{
F_41 ( V_59 ) ;
F_40 ( V_59 ) ;
F_42 ( & V_59 -> V_67 ) ;
}
static void F_44 ( struct V_94 * V_95 )
{
F_43 ( & V_95 -> V_96 -> V_59 ) ;
F_45 ( & V_95 -> V_96 -> V_97 ) ;
F_45 ( & V_95 -> V_96 -> V_45 ) ;
F_45 ( & V_95 -> V_96 -> V_48 ) ;
F_46 ( V_95 -> V_96 -> V_59 . V_98 ) ;
F_47 ( & V_95 -> V_96 -> V_99 ) ;
V_95 -> V_96 = NULL ;
}
static void F_48 ( struct V_94 * V_95 )
{
F_31 ( L_19 , V_37 , V_95 -> V_96 ) ;
F_49 ( V_95 -> V_96 ) ;
F_44 ( V_95 ) ;
}
static int F_50 ( const struct V_100 * V_101 )
{
return V_101 -> V_81 -> V_82 . V_84 > 0 && V_101 -> V_81 -> V_85 . V_84 > 0 &&
V_101 -> V_81 -> V_23 . V_84 > 0 && V_101 -> V_81 -> V_14 . V_84 > 0 &&
V_101 -> V_81 -> V_86 . V_84 > 0 && V_101 -> V_81 -> V_102 . V_84 > 0 ;
}
static struct V_49 * F_51 ( const struct V_100 * V_101 )
{
struct V_49 * V_42 ;
int V_38 ;
if ( ! F_50 ( V_101 ) ) {
F_7 (KERN_INFO MOD L_20 ,
pci_name(infop->pdev)) ;
return F_52 ( - V_103 ) ;
}
V_42 = (struct V_49 * ) F_53 ( sizeof( * V_42 ) ) ;
if ( ! V_42 ) {
F_7 (KERN_ERR MOD L_21 ) ;
return F_52 ( - V_40 ) ;
}
V_42 -> V_59 . V_75 = * V_101 ;
V_42 -> V_59 . V_104 = F_35 ( V_42 -> V_59 . V_75 . V_80 , 2 ) +
( F_34 ( V_42 -> V_59 . V_75 . V_80 , 2 ) -
F_54 ( V_42 -> V_59 . V_75 . V_81 -> V_102 . V_84 ) ) ;
V_42 -> V_59 . V_98 = F_55 ( V_42 -> V_59 . V_104 ,
V_42 -> V_59 . V_75 . V_81 -> V_102 . V_84 ) ;
F_31 (KERN_INFO MOD L_22
L_23 ,
devp->rdev.lldi.vr->ocq.start, devp->rdev.lldi.vr->ocq.size,
devp->rdev.oc_mw_pa, devp->rdev.oc_mw_kva) ;
V_38 = F_29 ( & V_42 -> V_59 ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD L_24 , ret) ;
F_47 ( & V_42 -> V_99 ) ;
return F_52 ( V_38 ) ;
}
F_56 ( & V_42 -> V_97 ) ;
F_56 ( & V_42 -> V_45 ) ;
F_56 ( & V_42 -> V_48 ) ;
F_57 ( & V_42 -> V_44 ) ;
if ( V_105 ) {
V_42 -> V_52 = F_58 (
F_32 ( V_42 -> V_59 . V_75 . V_80 ) ,
V_105 ) ;
F_17 ( V_42 ) ;
}
return V_42 ;
}
static void * F_59 ( const struct V_100 * V_101 )
{
struct V_94 * V_95 ;
static int V_106 ;
int V_107 ;
if ( ! V_106 ++ )
F_7 (KERN_INFO MOD L_25 ,
DRV_VERSION) ;
V_95 = F_60 ( sizeof *V_95 , V_39 ) ;
if ( ! V_95 ) {
V_95 = F_52 ( - V_40 ) ;
goto V_41;
}
V_95 -> V_75 = * V_101 ;
F_31 ( L_26 ,
V_37 , F_32 ( V_95 -> V_75 . V_80 ) ,
V_95 -> V_75 . V_108 , V_95 -> V_75 . V_109 ,
V_95 -> V_75 . V_110 , V_95 -> V_75 . V_111 ) ;
F_20 ( & V_112 ) ;
F_61 ( & V_95 -> V_65 , & V_113 ) ;
F_25 ( & V_112 ) ;
for ( V_107 = 0 ; V_107 < V_95 -> V_75 . V_109 ; V_107 ++ )
F_31 ( L_27 , V_107 , V_95 -> V_75 . V_114 [ V_107 ] ) ;
V_41:
return V_95 ;
}
static int F_62 ( void * V_115 , const T_5 * V_116 ,
const struct V_117 * V_118 )
{
struct V_94 * V_95 = V_115 ;
struct V_49 * V_96 = V_95 -> V_96 ;
struct V_119 * V_120 ;
const struct V_121 * V_122 ;
unsigned int V_123 ;
if ( V_118 == NULL ) {
unsigned int V_124 = 64 - sizeof( struct V_125 ) - 8 ;
V_120 = F_63 ( 256 , V_126 ) ;
if ( ! V_120 )
goto V_127;
F_64 ( V_120 , V_124 ) ;
F_65 ( V_120 , & V_116 [ 1 ] , V_124 ) ;
} else if ( V_118 == V_128 ) {
const struct V_125 * V_129 = ( void * ) V_116 ;
T_6 V_20 = F_66 ( V_129 -> V_130 ) ;
F_67 ( V_96 , V_20 ) ;
return 0 ;
} else {
V_120 = F_68 ( V_118 , 128 , 128 ) ;
if ( F_69 ( ! V_120 ) )
goto V_127;
}
V_122 = F_70 ( V_120 ) ;
V_123 = V_122 -> V_131 . V_123 ;
if ( V_132 [ V_123 ] )
V_132 [ V_123 ] ( V_96 , V_120 ) ;
else
F_7 ( V_36 L_28 , V_37 ,
V_123 ) ;
return 0 ;
V_127:
return - 1 ;
}
static int F_71 ( void * V_115 , enum V_133 V_134 )
{
struct V_94 * V_95 = V_115 ;
F_31 ( L_29 , V_37 , V_134 ) ;
switch ( V_134 ) {
case V_135 :
F_7 (KERN_INFO MOD L_30 , pci_name(ctx->lldi.pdev)) ;
if ( ! V_95 -> V_96 ) {
int V_38 ;
V_95 -> V_96 = F_51 ( & V_95 -> V_75 ) ;
if ( F_72 ( V_95 -> V_96 ) ) {
F_7 (KERN_ERR MOD
L_31 ,
pci_name(ctx->lldi.pdev),
PTR_ERR(ctx->dev)) ;
V_95 -> V_96 = NULL ;
break;
}
V_38 = F_73 ( V_95 -> V_96 ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD
L_32 ,
pci_name(ctx->lldi.pdev), ret) ;
F_44 ( V_95 ) ;
}
}
break;
case V_136 :
F_7 (KERN_INFO MOD L_33 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_95 -> V_96 )
F_48 ( V_95 ) ;
break;
case V_137 :
F_7 (KERN_INFO MOD L_34 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_95 -> V_96 ) {
struct V_138 V_139 ;
V_95 -> V_96 -> V_59 . V_26 |= V_140 ;
memset ( & V_139 , 0 , sizeof V_139 ) ;
V_139 . V_139 = V_141 ;
V_139 . V_142 = & V_95 -> V_96 -> V_99 ;
F_74 ( & V_139 ) ;
F_48 ( V_95 ) ;
}
break;
case V_143 :
F_7 (KERN_INFO MOD L_35 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_95 -> V_96 )
F_48 ( V_95 ) ;
break;
}
return 0 ;
}
static int T_7 F_75 ( void )
{
int V_72 ;
V_72 = F_76 () ;
if ( V_72 )
return V_72 ;
V_105 = F_58 ( V_144 , NULL ) ;
if ( ! V_105 )
F_7 (KERN_WARNING MOD
L_36 ) ;
F_77 ( V_145 , & V_146 ) ;
return 0 ;
}
static void T_8 F_78 ( void )
{
struct V_94 * V_95 , * V_147 ;
F_20 ( & V_112 ) ;
F_79 (ctx, tmp, &uld_ctx_list, entry) {
if ( V_95 -> V_96 )
F_48 ( V_95 ) ;
F_8 ( V_95 ) ;
}
F_25 ( & V_112 ) ;
F_80 ( V_145 ) ;
F_81 () ;
F_82 ( V_105 ) ;
}
