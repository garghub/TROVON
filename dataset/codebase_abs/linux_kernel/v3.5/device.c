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
F_9 ( V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_15 ;
int V_38 = 0 ;
int V_7 = 1 ;
V_15 = F_11 ( sizeof *V_15 , V_39 ) ;
if ( ! V_15 ) {
V_38 = - V_40 ;
goto V_41;
}
V_15 -> V_42 = V_35 -> V_43 ;
V_15 -> V_12 = 0 ;
F_12 ( & V_15 -> V_42 -> V_44 ) ;
F_13 ( & V_15 -> V_42 -> V_45 , F_1 , & V_7 ) ;
F_14 ( & V_15 -> V_42 -> V_44 ) ;
V_15 -> V_21 = V_7 * 128 ;
V_15 -> V_6 = F_15 ( V_15 -> V_21 ) ;
if ( ! V_15 -> V_6 ) {
V_38 = - V_40 ;
goto V_46;
}
F_12 ( & V_15 -> V_42 -> V_44 ) ;
F_13 ( & V_15 -> V_42 -> V_45 , F_4 , V_15 ) ;
F_14 ( & V_15 -> V_42 -> V_44 ) ;
V_15 -> V_6 [ V_15 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_15 ;
goto V_41;
V_46:
F_9 ( V_15 ) ;
V_41:
return V_38 ;
}
static int F_16 ( int V_1 , void * V_2 , void * V_3 )
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
static int F_17 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_47 = V_5 -> V_11 ;
if ( ! V_47 ) {
F_7 ( V_36 L_6 , V_37 ) ;
return 0 ;
}
F_9 ( V_47 -> V_6 ) ;
F_9 ( V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_47 ;
int V_38 = 0 ;
int V_7 = 1 ;
V_47 = F_11 ( sizeof *V_47 , V_39 ) ;
if ( ! V_47 ) {
V_38 = - V_40 ;
goto V_41;
}
V_47 -> V_42 = V_35 -> V_43 ;
V_47 -> V_12 = 0 ;
F_12 ( & V_47 -> V_42 -> V_44 ) ;
F_13 ( & V_47 -> V_42 -> V_48 , F_1 , & V_7 ) ;
F_14 ( & V_47 -> V_42 -> V_44 ) ;
V_47 -> V_21 = V_7 * sizeof( L_7 ) ;
V_47 -> V_6 = F_11 ( V_47 -> V_21 , V_39 ) ;
if ( ! V_47 -> V_6 ) {
V_38 = - V_40 ;
goto V_46;
}
F_12 ( & V_47 -> V_42 -> V_44 ) ;
F_13 ( & V_47 -> V_42 -> V_48 , F_16 , V_47 ) ;
F_14 ( & V_47 -> V_42 -> V_44 ) ;
V_47 -> V_6 [ V_47 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_47 ;
goto V_41;
V_46:
F_9 ( V_47 ) ;
V_41:
return V_38 ;
}
static int F_19 ( struct V_49 * V_50 , void * V_51 )
{
struct V_52 * V_53 = V_50 -> V_54 ;
F_20 ( V_50 , L_8 , L_9 , L_10 ,
L_11 , L_12 ) ;
F_20 ( V_50 , L_13 ,
V_53 -> V_55 . V_56 . V_57 . V_58 , V_53 -> V_55 . V_56 . V_57 . V_59 ,
V_53 -> V_55 . V_56 . V_57 . V_60 , V_53 -> V_55 . V_56 . V_57 . V_61 ) ;
F_20 ( V_50 , L_14 ,
V_53 -> V_55 . V_56 . V_20 . V_58 , V_53 -> V_55 . V_56 . V_20 . V_59 ,
V_53 -> V_55 . V_56 . V_20 . V_60 , V_53 -> V_55 . V_56 . V_20 . V_61 ) ;
F_20 ( V_50 , L_15 ,
V_53 -> V_55 . V_56 . V_62 . V_58 , V_53 -> V_55 . V_56 . V_62 . V_59 ,
V_53 -> V_55 . V_56 . V_62 . V_60 , V_53 -> V_55 . V_56 . V_62 . V_61 ) ;
F_20 ( V_50 , L_16 ,
V_53 -> V_55 . V_56 . V_63 . V_58 , V_53 -> V_55 . V_56 . V_63 . V_59 ,
V_53 -> V_55 . V_56 . V_63 . V_60 , V_53 -> V_55 . V_56 . V_63 . V_61 ) ;
F_20 ( V_50 , L_17 ,
V_53 -> V_55 . V_56 . V_64 . V_58 , V_53 -> V_55 . V_56 . V_64 . V_59 ,
V_53 -> V_55 . V_56 . V_64 . V_60 , V_53 -> V_55 . V_56 . V_64 . V_61 ) ;
F_20 ( V_50 , L_18 ,
V_53 -> V_55 . V_56 . V_65 . V_58 , V_53 -> V_55 . V_56 . V_65 . V_59 ,
V_53 -> V_55 . V_56 . V_65 . V_60 , V_53 -> V_55 . V_56 . V_65 . V_61 ) ;
F_20 ( V_50 , L_19 , V_53 -> V_55 . V_56 . V_66 ) ;
F_20 ( V_50 , L_20 , V_53 -> V_55 . V_56 . V_67 ) ;
F_20 ( V_50 , L_21 , V_53 -> V_55 . V_56 . V_68 ) ;
F_20 ( V_50 , L_22 ,
V_69 [ V_53 -> V_70 ] ,
V_53 -> V_55 . V_56 . V_71 ) ;
return 0 ;
}
static int F_21 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
return F_22 ( V_5 , F_19 , V_35 -> V_43 ) ;
}
static T_1 F_23 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_12 )
{
struct V_52 * V_53 = ( (struct V_49 * ) V_5 -> V_11 ) -> V_54 ;
F_24 ( & V_53 -> V_55 . V_56 . V_44 ) ;
V_53 -> V_55 . V_56 . V_57 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_57 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_20 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_20 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_62 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_62 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_63 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_63 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_64 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_64 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_65 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_65 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_66 = 0 ;
V_53 -> V_55 . V_56 . V_67 = 0 ;
V_53 -> V_55 . V_56 . V_68 = 0 ;
V_53 -> V_55 . V_56 . V_71 = 0 ;
F_25 ( & V_53 -> V_55 . V_56 . V_44 ) ;
return V_7 ;
}
static int F_26 ( struct V_52 * V_42 )
{
struct V_72 * V_73 ;
if ( ! V_42 -> V_74 )
return - 1 ;
V_73 = F_27 ( L_23 , V_75 , V_42 -> V_74 ,
( void * ) V_42 , & V_76 ) ;
if ( V_73 && V_73 -> V_77 )
V_73 -> V_77 -> V_78 = 4096 ;
V_73 = F_27 ( L_24 , V_75 , V_42 -> V_74 ,
( void * ) V_42 , & V_79 ) ;
if ( V_73 && V_73 -> V_77 )
V_73 -> V_77 -> V_78 = 4096 ;
V_73 = F_27 ( L_25 , V_75 , V_42 -> V_74 ,
( void * ) V_42 , & V_80 ) ;
if ( V_73 && V_73 -> V_77 )
V_73 -> V_77 -> V_78 = 4096 ;
return 0 ;
}
void F_28 ( struct V_81 * V_55 ,
struct V_82 * V_83 )
{
struct V_84 * V_12 , * V_85 ;
struct V_86 * V_87 ;
F_24 ( & V_83 -> V_44 ) ;
F_29 (pos, nxt, &uctx->qpids) {
V_87 = F_30 ( V_12 , struct V_86 , V_87 ) ;
F_31 ( & V_87 -> V_87 ) ;
if ( ! ( V_87 -> V_20 & V_55 -> V_88 ) ) {
F_32 ( & V_55 -> V_89 . V_90 ,
V_87 -> V_20 ) ;
F_24 ( & V_55 -> V_56 . V_44 ) ;
V_55 -> V_56 . V_20 . V_59 -= V_55 -> V_88 + 1 ;
F_25 ( & V_55 -> V_56 . V_44 ) ;
}
F_9 ( V_87 ) ;
}
F_29 (pos, nxt, &uctx->qpids) {
V_87 = F_30 ( V_12 , struct V_86 , V_87 ) ;
F_31 ( & V_87 -> V_87 ) ;
F_9 ( V_87 ) ;
}
F_25 ( & V_83 -> V_44 ) ;
}
void F_33 ( struct V_81 * V_55 ,
struct V_82 * V_83 )
{
F_34 ( & V_83 -> V_91 ) ;
F_34 ( & V_83 -> V_92 ) ;
F_35 ( & V_83 -> V_44 ) ;
}
static int F_36 ( struct V_81 * V_55 )
{
int V_93 ;
F_33 ( V_55 , & V_55 -> V_83 ) ;
V_55 -> V_94 = V_95 - F_37 ( V_55 -> V_96 . V_97 ) ;
V_55 -> V_88 = V_55 -> V_96 . V_97 - 1 ;
V_55 -> V_98 = V_95 - F_37 ( V_55 -> V_96 . V_99 ) ;
V_55 -> V_100 = V_55 -> V_96 . V_99 - 1 ;
F_38 ( L_26
L_27
L_28 ,
V_37 , F_39 ( V_55 -> V_96 . V_101 ) , V_55 -> V_96 . V_102 -> V_62 . V_103 ,
V_55 -> V_96 . V_102 -> V_62 . V_104 , F_40 ( V_55 ) ,
V_55 -> V_96 . V_102 -> V_63 . V_103 ,
V_55 -> V_96 . V_102 -> V_63 . V_104 , V_55 -> V_96 . V_102 -> V_23 . V_103 ,
V_55 -> V_96 . V_102 -> V_23 . V_104 ,
V_55 -> V_96 . V_102 -> V_14 . V_103 ,
V_55 -> V_96 . V_102 -> V_14 . V_104 ,
V_55 -> V_96 . V_102 -> V_105 . V_103 ,
V_55 -> V_96 . V_102 -> V_105 . V_104 ) ;
F_38 ( L_29
L_30 ,
( unsigned ) F_41 ( V_55 -> V_96 . V_101 , 2 ) ,
( void * ) F_42 ( V_55 -> V_96 . V_101 , 2 ) ,
V_55 -> V_96 . V_106 ,
V_55 -> V_96 . V_107 ,
V_55 -> V_94 , V_55 -> V_88 ,
V_55 -> V_98 , V_55 -> V_100 ) ;
if ( F_40 ( V_55 ) == 0 ) {
V_93 = - V_108 ;
goto V_46;
}
V_55 -> V_56 . V_57 . V_58 = V_109 ;
V_55 -> V_56 . V_62 . V_58 = V_55 -> V_96 . V_102 -> V_62 . V_104 ;
V_55 -> V_56 . V_63 . V_58 = V_55 -> V_96 . V_102 -> V_63 . V_104 ;
V_55 -> V_56 . V_64 . V_58 = V_55 -> V_96 . V_102 -> V_23 . V_104 ;
V_55 -> V_56 . V_65 . V_58 = V_55 -> V_96 . V_102 -> V_110 . V_104 ;
V_55 -> V_56 . V_20 . V_58 = V_55 -> V_96 . V_102 -> V_14 . V_104 ;
V_93 = F_43 ( V_55 , F_40 ( V_55 ) , V_109 ) ;
if ( V_93 ) {
F_7 (KERN_ERR MOD L_31 , err) ;
goto V_46;
}
V_93 = F_44 ( V_55 ) ;
if ( V_93 ) {
F_7 (KERN_ERR MOD L_32 , err) ;
goto V_111;
}
V_93 = F_45 ( V_55 ) ;
if ( V_93 ) {
F_7 (KERN_ERR MOD L_33 , err) ;
goto V_112;
}
V_93 = F_46 ( V_55 ) ;
if ( V_93 ) {
F_7 (KERN_ERR MOD L_34 , err) ;
goto V_113;
}
return 0 ;
V_113:
F_47 ( V_55 ) ;
V_112:
F_48 ( V_55 ) ;
V_111:
F_49 ( & V_55 -> V_89 ) ;
V_46:
return V_93 ;
}
static void F_50 ( struct V_81 * V_55 )
{
F_48 ( V_55 ) ;
F_47 ( V_55 ) ;
F_49 ( & V_55 -> V_89 ) ;
}
static void F_51 ( struct V_114 * V_115 )
{
F_50 ( & V_115 -> V_53 -> V_55 ) ;
F_52 ( & V_115 -> V_53 -> V_116 ) ;
F_52 ( & V_115 -> V_53 -> V_45 ) ;
F_52 ( & V_115 -> V_53 -> V_48 ) ;
F_53 ( V_115 -> V_53 -> V_55 . V_117 ) ;
F_54 ( & V_115 -> V_53 -> V_118 ) ;
V_115 -> V_53 = NULL ;
}
static void F_55 ( struct V_114 * V_115 )
{
F_38 ( L_35 , V_37 , V_115 -> V_53 ) ;
F_56 ( V_115 -> V_53 ) ;
F_51 ( V_115 ) ;
}
static int F_57 ( const struct V_119 * V_120 )
{
return V_120 -> V_102 -> V_62 . V_104 > 0 && V_120 -> V_102 -> V_63 . V_104 > 0 &&
V_120 -> V_102 -> V_23 . V_104 > 0 && V_120 -> V_102 -> V_14 . V_104 > 0 &&
V_120 -> V_102 -> V_105 . V_104 > 0 && V_120 -> V_102 -> V_110 . V_104 > 0 ;
}
static struct V_52 * F_58 ( const struct V_119 * V_120 )
{
struct V_52 * V_42 ;
int V_38 ;
if ( ! F_57 ( V_120 ) ) {
F_7 (KERN_INFO MOD L_36 ,
pci_name(infop->pdev)) ;
return F_59 ( - V_121 ) ;
}
V_42 = (struct V_52 * ) F_60 ( sizeof( * V_42 ) ) ;
if ( ! V_42 ) {
F_7 (KERN_ERR MOD L_37 ) ;
return F_59 ( - V_40 ) ;
}
V_42 -> V_55 . V_96 = * V_120 ;
V_42 -> V_55 . V_122 = F_42 ( V_42 -> V_55 . V_96 . V_101 , 2 ) +
( F_41 ( V_42 -> V_55 . V_96 . V_101 , 2 ) -
F_61 ( V_42 -> V_55 . V_96 . V_102 -> V_110 . V_104 ) ) ;
V_42 -> V_55 . V_117 = F_62 ( V_42 -> V_55 . V_122 ,
V_42 -> V_55 . V_96 . V_102 -> V_110 . V_104 ) ;
F_38 (KERN_INFO MOD L_38
L_39 ,
devp->rdev.lldi.vr->ocq.start, devp->rdev.lldi.vr->ocq.size,
devp->rdev.oc_mw_pa, devp->rdev.oc_mw_kva) ;
V_38 = F_36 ( & V_42 -> V_55 ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD L_40 , ret) ;
F_54 ( & V_42 -> V_118 ) ;
return F_59 ( V_38 ) ;
}
F_63 ( & V_42 -> V_116 ) ;
F_63 ( & V_42 -> V_45 ) ;
F_63 ( & V_42 -> V_48 ) ;
F_64 ( & V_42 -> V_44 ) ;
F_35 ( & V_42 -> V_55 . V_56 . V_44 ) ;
F_35 ( & V_42 -> V_123 ) ;
if ( V_124 ) {
V_42 -> V_74 = F_65 (
F_39 ( V_42 -> V_55 . V_96 . V_101 ) ,
V_124 ) ;
F_26 ( V_42 ) ;
}
return V_42 ;
}
static void * F_66 ( const struct V_119 * V_120 )
{
struct V_114 * V_115 ;
static int V_125 ;
int V_126 ;
if ( ! V_125 ++ )
F_7 (KERN_INFO MOD L_41 ,
DRV_VERSION) ;
V_115 = F_67 ( sizeof *V_115 , V_39 ) ;
if ( ! V_115 ) {
V_115 = F_59 ( - V_40 ) ;
goto V_41;
}
V_115 -> V_96 = * V_120 ;
F_38 ( L_42 ,
V_37 , F_39 ( V_115 -> V_96 . V_101 ) ,
V_115 -> V_96 . V_127 , V_115 -> V_96 . V_128 ,
V_115 -> V_96 . V_129 , V_115 -> V_96 . V_130 ) ;
F_24 ( & V_131 ) ;
F_68 ( & V_115 -> V_87 , & V_132 ) ;
F_25 ( & V_131 ) ;
for ( V_126 = 0 ; V_126 < V_115 -> V_96 . V_128 ; V_126 ++ )
F_38 ( L_43 , V_126 , V_115 -> V_96 . V_133 [ V_126 ] ) ;
V_41:
return V_115 ;
}
static int F_69 ( void * V_134 , const T_5 * V_135 ,
const struct V_136 * V_137 )
{
struct V_114 * V_115 = V_134 ;
struct V_52 * V_53 = V_115 -> V_53 ;
struct V_138 * V_139 ;
const struct V_140 * V_141 ;
unsigned int V_142 ;
if ( V_137 == NULL ) {
unsigned int V_143 = 64 - sizeof( struct V_144 ) - 8 ;
V_139 = F_70 ( 256 , V_145 ) ;
if ( ! V_139 )
goto V_146;
F_71 ( V_139 , V_143 ) ;
F_72 ( V_139 , & V_135 [ 1 ] , V_143 ) ;
} else if ( V_137 == V_147 ) {
const struct V_144 * V_148 = ( void * ) V_135 ;
T_6 V_20 = F_73 ( V_148 -> V_149 ) ;
F_74 ( V_53 , V_20 ) ;
return 0 ;
} else {
V_139 = F_75 ( V_137 , 128 , 128 ) ;
if ( F_76 ( ! V_139 ) )
goto V_146;
}
V_141 = F_77 ( V_139 ) ;
V_142 = V_141 -> V_150 . V_142 ;
if ( V_151 [ V_142 ] )
V_151 [ V_142 ] ( V_53 , V_139 ) ;
else
F_7 ( V_36 L_44 , V_37 ,
V_142 ) ;
return 0 ;
V_146:
return - 1 ;
}
static int F_78 ( void * V_134 , enum V_152 V_153 )
{
struct V_114 * V_115 = V_134 ;
F_38 ( L_45 , V_37 , V_153 ) ;
switch ( V_153 ) {
case V_154 :
F_7 (KERN_INFO MOD L_46 , pci_name(ctx->lldi.pdev)) ;
if ( ! V_115 -> V_53 ) {
int V_38 ;
V_115 -> V_53 = F_58 ( & V_115 -> V_96 ) ;
if ( F_79 ( V_115 -> V_53 ) ) {
F_7 (KERN_ERR MOD
L_47 ,
pci_name(ctx->lldi.pdev),
PTR_ERR(ctx->dev)) ;
V_115 -> V_53 = NULL ;
break;
}
V_38 = F_80 ( V_115 -> V_53 ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD
L_48 ,
pci_name(ctx->lldi.pdev), ret) ;
F_51 ( V_115 ) ;
}
}
break;
case V_155 :
F_7 (KERN_INFO MOD L_49 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_115 -> V_53 )
F_55 ( V_115 ) ;
break;
case V_156 :
F_7 (KERN_INFO MOD L_50 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_115 -> V_53 ) {
struct V_157 V_158 ;
V_115 -> V_53 -> V_55 . V_26 |= V_159 ;
memset ( & V_158 , 0 , sizeof V_158 ) ;
V_158 . V_158 = V_160 ;
V_158 . V_161 = & V_115 -> V_53 -> V_118 ;
F_81 ( & V_158 ) ;
F_55 ( V_115 ) ;
}
break;
case V_162 :
F_7 (KERN_INFO MOD L_51 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_115 -> V_53 )
F_55 ( V_115 ) ;
break;
}
return 0 ;
}
static int F_82 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_83 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_84 ( struct V_114 * V_115 )
{
F_12 ( & V_115 -> V_53 -> V_44 ) ;
if ( V_115 -> V_53 -> V_70 == V_163 ) {
V_115 -> V_53 -> V_55 . V_56 . V_71 ++ ;
V_115 -> V_53 -> V_70 = V_164 ;
F_13 ( & V_115 -> V_53 -> V_45 , F_82 , NULL ) ;
}
F_14 ( & V_115 -> V_53 -> V_44 ) ;
}
static int F_85 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_86 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_87 ( struct V_114 * V_115 )
{
F_12 ( & V_115 -> V_53 -> V_44 ) ;
if ( V_115 -> V_53 -> V_165 <= V_166 &&
V_115 -> V_53 -> V_70 == V_164 ) {
V_115 -> V_53 -> V_70 = V_163 ;
V_115 -> V_53 -> V_55 . V_56 . V_71 ++ ;
F_13 ( & V_115 -> V_53 -> V_45 , F_85 , NULL ) ;
}
F_14 ( & V_115 -> V_53 -> V_44 ) ;
}
static int F_88 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_167 * V_168 = V_3 ;
struct V_13 * V_14 = V_2 ;
F_89 ( & V_14 -> V_169 ) ;
V_168 -> V_170 [ V_168 -> V_171 ++ ] = V_14 ;
return 0 ;
}
static int F_90 ( int V_1 , void * V_2 , void * V_3 )
{
unsigned * V_4 = V_3 ;
( * V_4 ) ++ ;
return 0 ;
}
static void F_91 ( struct V_167 V_167 )
{
int V_171 ;
for ( V_171 = 0 ; V_171 < V_167 . V_171 ; V_171 ++ )
F_92 ( & V_167 . V_170 [ V_171 ] -> V_169 ) ;
}
static void F_93 ( struct V_114 * V_115 , struct V_167 * V_167 )
{
int V_171 ;
int V_38 ;
for ( V_171 = 0 ; V_171 < V_167 -> V_171 ; V_171 ++ ) {
struct V_13 * V_14 = V_167 -> V_170 [ V_171 ] ;
V_38 = F_94 ( V_14 -> V_172 -> V_55 . V_96 . V_173 [ 0 ] ,
V_14 -> V_18 . V_19 . V_20 ,
F_95 ( & V_14 -> V_18 ) ,
F_96 ( & V_14 -> V_18 ) ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD L_52
L_53
L_54 ,
pci_name(ctx->lldi.pdev), qp->wq.sq.qid) ;
return;
}
V_38 = F_94 ( V_14 -> V_172 -> V_55 . V_96 . V_173 [ 0 ] ,
V_14 -> V_18 . V_23 . V_20 ,
F_97 ( & V_14 -> V_18 ) ,
F_98 ( & V_14 -> V_18 ) ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD L_52
L_53
L_55 ,
pci_name(ctx->lldi.pdev), qp->wq.rq.qid) ;
return;
}
while ( F_99 ( V_14 -> V_172 -> V_55 . V_96 . V_173 [ 0 ] , 1 ) > 0 ) {
F_100 ( V_174 ) ;
F_101 ( F_102 ( 10 ) ) ;
}
}
}
static void F_103 ( struct V_114 * V_115 )
{
int V_7 = 0 ;
struct V_167 V_167 ;
int V_38 ;
F_24 ( & V_115 -> V_53 -> V_123 ) ;
F_12 ( & V_115 -> V_53 -> V_44 ) ;
V_115 -> V_53 -> V_70 = V_175 ;
V_115 -> V_53 -> V_55 . V_56 . V_71 ++ ;
F_13 ( & V_115 -> V_53 -> V_45 , F_82 , NULL ) ;
F_14 ( & V_115 -> V_53 -> V_44 ) ;
F_100 ( V_174 ) ;
F_101 ( F_102 ( 1000 ) ) ;
while ( F_99 ( V_115 -> V_53 -> V_55 . V_96 . V_173 [ 0 ] , 1 ) > 0 ) {
F_100 ( V_174 ) ;
F_101 ( F_102 ( 10 ) ) ;
}
V_38 = F_104 ( V_115 -> V_53 -> V_55 . V_96 . V_173 [ 0 ] ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD L_56 ,
pci_name(ctx->lldi.pdev)) ;
goto V_41;
}
F_12 ( & V_115 -> V_53 -> V_44 ) ;
F_13 ( & V_115 -> V_53 -> V_45 , F_90 , & V_7 ) ;
V_167 . V_170 = F_67 ( V_7 * sizeof * V_167 . V_170 , V_145 ) ;
if ( ! V_167 . V_170 ) {
F_7 (KERN_ERR MOD L_56 ,
pci_name(ctx->lldi.pdev)) ;
F_14 ( & V_115 -> V_53 -> V_44 ) ;
goto V_41;
}
V_167 . V_171 = 0 ;
F_13 ( & V_115 -> V_53 -> V_45 , F_88 , & V_167 ) ;
F_14 ( & V_115 -> V_53 -> V_44 ) ;
F_93 ( V_115 , & V_167 ) ;
F_91 ( V_167 ) ;
F_9 ( V_167 . V_170 ) ;
while ( F_99 ( V_115 -> V_53 -> V_55 . V_96 . V_173 [ 0 ] , 1 ) > 0 ) {
F_100 ( V_174 ) ;
F_101 ( F_102 ( 10 ) ) ;
}
F_12 ( & V_115 -> V_53 -> V_44 ) ;
if ( V_115 -> V_53 -> V_165 > V_166 )
V_115 -> V_53 -> V_70 = V_164 ;
else {
V_115 -> V_53 -> V_70 = V_163 ;
F_13 ( & V_115 -> V_53 -> V_45 , F_85 , NULL ) ;
}
V_115 -> V_53 -> V_55 . V_56 . V_71 ++ ;
F_14 ( & V_115 -> V_53 -> V_44 ) ;
V_41:
F_25 ( & V_115 -> V_53 -> V_123 ) ;
}
static int F_105 ( void * V_134 , enum V_176 V_177 , ... )
{
struct V_114 * V_115 = V_134 ;
switch ( V_177 ) {
case V_178 :
F_84 ( V_115 ) ;
F_24 ( & V_115 -> V_53 -> V_55 . V_56 . V_44 ) ;
V_115 -> V_53 -> V_55 . V_56 . V_66 ++ ;
F_25 ( & V_115 -> V_53 -> V_55 . V_56 . V_44 ) ;
break;
case V_179 :
F_87 ( V_115 ) ;
F_24 ( & V_115 -> V_53 -> V_55 . V_56 . V_44 ) ;
V_115 -> V_53 -> V_55 . V_56 . V_67 ++ ;
F_25 ( & V_115 -> V_53 -> V_55 . V_56 . V_44 ) ;
break;
case V_180 :
F_103 ( V_115 ) ;
F_24 ( & V_115 -> V_53 -> V_55 . V_56 . V_44 ) ;
V_115 -> V_53 -> V_55 . V_56 . V_68 ++ ;
F_25 ( & V_115 -> V_53 -> V_55 . V_56 . V_44 ) ;
break;
default:
F_7 (KERN_WARNING MOD L_57 ,
pci_name(ctx->lldi.pdev), control) ;
break;
}
return 0 ;
}
static int T_7 F_106 ( void )
{
int V_93 ;
V_93 = F_107 () ;
if ( V_93 )
return V_93 ;
V_124 = F_65 ( V_181 , NULL ) ;
if ( ! V_124 )
F_7 (KERN_WARNING MOD
L_58 ) ;
F_108 ( V_182 , & V_183 ) ;
return 0 ;
}
static void T_8 F_109 ( void )
{
struct V_114 * V_115 , * V_184 ;
F_24 ( & V_131 ) ;
F_110 (ctx, tmp, &uld_ctx_list, entry) {
if ( V_115 -> V_53 )
F_55 ( V_115 ) ;
F_9 ( V_115 ) ;
}
F_25 ( & V_131 ) ;
F_111 ( V_182 ) ;
F_112 () ;
F_113 ( V_124 ) ;
}
