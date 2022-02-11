bool
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
if ( ! ( V_4 -> V_6 & V_7 ) )
goto V_8;
if ( V_4 -> V_9 == 0 )
goto V_8;
return true ;
V_8:
F_2 ( L_1 ,
V_2 -> V_5 -> V_10 ) ;
return false ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned int V_13 = V_2 -> V_14 ;
struct V_15 * V_16 = & V_12 -> V_17 ;
int V_18 ;
V_16 -> V_19 = F_4 ( V_2 -> V_20 , V_2 -> V_21 , V_13 ) ;
if ( F_5 ( V_16 -> V_19 ) )
goto V_22;
V_12 -> V_23 = F_6 ( V_13 , sizeof( * V_12 -> V_23 ) , V_24 ) ;
if ( ! V_12 -> V_23 )
goto V_25;
F_7 ( V_12 -> V_23 , V_13 ) ;
F_8 ( & V_16 -> V_26 ) ;
return 0 ;
V_22:
V_18 = F_9 ( V_16 -> V_19 ) ;
F_10 ( L_2 ,
V_27 , V_18 ) ;
return V_18 ;
V_25:
V_18 = - V_28 ;
F_10 ( L_3 ,
V_27 ) ;
F_11 ( V_16 -> V_19 ) ;
return V_18 ;
}
static void
F_12 ( struct V_11 * V_12 )
{
int V_18 ;
if ( ! F_13 ( & V_12 -> V_29 ) )
F_14 ( & V_12 -> V_29 ) ;
V_18 = F_11 ( V_12 -> V_17 . V_19 ) ;
if ( V_18 )
F_15 ( L_4 ,
V_12 , V_18 ) ;
F_16 ( V_12 -> V_23 ) ;
F_16 ( V_12 ) ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_15 * V_16 = & V_12 -> V_17 ;
int V_18 ;
V_18 = F_11 ( V_16 -> V_19 ) ;
if ( V_18 ) {
F_18 ( L_5 ,
V_18 , V_12 ) ;
return V_18 ;
}
V_16 -> V_19 = F_4 ( V_2 -> V_20 , V_2 -> V_21 ,
V_2 -> V_14 ) ;
if ( F_5 ( V_16 -> V_19 ) ) {
F_18 ( L_6 ,
F_9 ( V_16 -> V_19 ) , V_12 ) ;
return F_9 ( V_16 -> V_19 ) ;
}
F_10 ( L_7 , V_27 , V_16 ) ;
V_16 -> V_30 = V_31 ;
return 0 ;
}
static void
F_19 ( struct V_11 * V_32 )
{
enum V_33 V_34 = V_32 -> V_17 . V_30 ;
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_1 * V_2 = & V_36 -> V_38 ;
int V_18 ;
V_18 = F_17 ( V_2 , V_32 ) ;
if ( V_34 != V_39 )
F_20 ( V_2 -> V_5 ,
V_32 -> V_23 , V_32 -> V_40 , V_32 -> V_41 ) ;
if ( V_18 )
goto V_42;
F_21 ( V_36 , V_32 ) ;
V_36 -> V_43 . V_44 ++ ;
return;
V_42:
F_15 ( L_8 , V_18 , V_32 ) ;
V_36 -> V_43 . V_45 ++ ;
F_22 ( & V_36 -> V_46 . V_47 ) ;
F_14 ( & V_32 -> V_48 ) ;
F_23 ( & V_36 -> V_46 . V_47 ) ;
F_12 ( V_32 ) ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int V_13 , V_53 ;
V_2 -> V_21 = V_54 ;
if ( V_4 -> V_6 & V_55 )
V_2 -> V_21 = V_56 ;
V_2 -> V_14 =
F_25 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
attrs->max_fast_reg_page_list_len) ;
F_10 ( L_9 ,
V_27 , V_2 -> V_14 ) ;
V_13 = 7 ;
if ( V_2 -> V_14 < V_57 ) {
V_53 = V_57 - V_2 -> V_14 ;
do {
V_13 += 2 ;
V_53 -= V_2 -> V_14 ;
} while ( V_53 > 0 );
}
V_50 -> V_58 . V_59 . V_60 *= V_13 ;
if ( V_50 -> V_58 . V_59 . V_60 > V_4 -> V_61 ) {
V_52 -> V_62 = V_4 -> V_61 / V_13 ;
if ( ! V_52 -> V_62 )
return - V_63 ;
V_50 -> V_58 . V_59 . V_60 = V_52 -> V_62 *
V_13 ;
}
V_2 -> V_64 = F_26 (unsigned int, 1 , RPCRDMA_MAX_DATA_SEGS /
ia->ri_max_frmr_depth) ;
return 0 ;
}
static T_1
F_27 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = & V_36 -> V_38 ;
return F_25 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS * ia->ri_max_frmr_depth) ;
}
static void
F_28 ( struct V_65 * V_66 , const char * V_67 )
{
if ( V_66 -> V_68 != V_69 )
F_15 ( L_10 ,
V_67 , F_29 ( V_66 -> V_68 ) ,
V_66 -> V_68 , V_66 -> V_70 ) ;
}
static void
F_30 ( struct V_71 * V_72 , struct V_65 * V_66 )
{
struct V_15 * V_17 ;
struct V_73 * V_74 ;
if ( V_66 -> V_68 != V_75 ) {
V_74 = V_66 -> V_76 ;
V_17 = F_31 ( V_74 , struct V_15 , V_77 ) ;
V_17 -> V_30 = V_78 ;
F_28 ( V_66 , L_11 ) ;
}
}
static void
F_32 ( struct V_71 * V_72 , struct V_65 * V_66 )
{
struct V_15 * V_17 ;
struct V_73 * V_74 ;
if ( V_66 -> V_68 != V_75 ) {
V_74 = V_66 -> V_76 ;
V_17 = F_31 ( V_74 , struct V_15 , V_77 ) ;
V_17 -> V_30 = V_39 ;
F_28 ( V_66 , L_12 ) ;
}
}
static void
F_33 ( struct V_71 * V_72 , struct V_65 * V_66 )
{
struct V_15 * V_17 ;
struct V_73 * V_74 ;
V_74 = V_66 -> V_76 ;
V_17 = F_31 ( V_74 , struct V_15 , V_77 ) ;
if ( V_66 -> V_68 != V_75 ) {
V_17 -> V_30 = V_39 ;
F_28 ( V_66 , L_12 ) ;
}
F_34 ( & V_17 -> V_26 ) ;
}
static int
F_35 ( struct V_35 * V_36 , struct V_79 * V_80 ,
int V_81 , bool V_82 , struct V_11 * * V_83 )
{
struct V_1 * V_2 = & V_36 -> V_38 ;
bool V_84 = V_2 -> V_21 == V_56 ;
struct V_11 * V_32 ;
struct V_15 * V_17 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
int V_18 , V_91 , V_92 , V_93 ;
T_2 V_94 ;
V_32 = NULL ;
do {
if ( V_32 )
F_36 ( V_32 ) ;
V_32 = F_37 ( V_36 ) ;
if ( ! V_32 )
return - V_95 ;
} while ( V_32 -> V_17 . V_30 != V_31 );
V_17 = & V_32 -> V_17 ;
V_17 -> V_30 = V_96 ;
V_86 = V_17 -> V_19 ;
V_88 = & V_17 -> V_97 ;
if ( V_81 > V_2 -> V_14 )
V_81 = V_2 -> V_14 ;
for ( V_91 = 0 ; V_91 < V_81 ; ) {
if ( V_80 -> V_98 )
F_38 ( & V_32 -> V_23 [ V_91 ] ,
V_80 -> V_98 ,
V_80 -> V_99 ,
F_39 ( V_80 -> V_100 ) ) ;
else
F_40 ( & V_32 -> V_23 [ V_91 ] , V_80 -> V_100 ,
V_80 -> V_99 ) ;
++ V_80 ;
++ V_91 ;
if ( V_84 )
continue;
if ( ( V_91 < V_81 && F_39 ( V_80 -> V_100 ) ) ||
F_39 ( ( V_80 - 1 ) -> V_100 + ( V_80 - 1 ) -> V_99 ) )
break;
}
V_32 -> V_40 = V_91 ;
V_32 -> V_41 = F_41 ( V_82 ) ;
if ( V_91 == 0 )
goto V_101;
V_93 = F_42 ( V_2 -> V_5 ,
V_32 -> V_23 , V_32 -> V_40 , V_32 -> V_41 ) ;
if ( ! V_93 )
goto V_101;
V_92 = F_43 ( V_86 , V_32 -> V_23 , V_32 -> V_40 , NULL , V_102 ) ;
if ( F_44 ( V_92 != V_32 -> V_40 ) )
goto V_103;
F_10 ( L_13 ,
V_27 , V_17 , V_32 -> V_40 , V_86 -> V_104 ) ;
V_94 = ( T_2 ) ( V_86 -> V_105 & 0x000000FF ) ;
F_45 ( V_86 , ++ V_94 ) ;
V_88 -> V_67 . V_106 = NULL ;
V_88 -> V_67 . V_107 = V_108 ;
V_17 -> V_77 . V_109 = F_30 ;
V_88 -> V_67 . V_76 = & V_17 -> V_77 ;
V_88 -> V_67 . V_110 = 0 ;
V_88 -> V_67 . V_111 = 0 ;
V_88 -> V_86 = V_86 ;
V_88 -> V_94 = V_86 -> V_105 ;
V_88 -> V_112 = V_82 ?
V_113 | V_114 :
V_115 ;
F_46 ( & V_36 -> V_116 , & V_88 -> V_67 ) ;
V_18 = F_47 ( V_2 -> V_117 -> V_118 , & V_88 -> V_67 , & V_90 ) ;
if ( V_18 )
goto V_119;
V_32 -> V_120 = V_86 -> V_105 ;
V_32 -> V_121 = V_86 -> V_104 ;
V_32 -> V_122 = V_86 -> V_123 ;
* V_83 = V_32 ;
return V_32 -> V_40 ;
V_101:
F_15 ( L_14 ,
V_32 -> V_23 , V_32 -> V_40 ) ;
F_36 ( V_32 ) ;
return - V_124 ;
V_103:
F_15 ( L_15 ,
V_17 -> V_19 , V_92 , V_32 -> V_40 ) ;
F_36 ( V_32 ) ;
return - V_124 ;
V_119:
F_15 ( L_16 , V_18 ) ;
F_36 ( V_32 ) ;
return - V_125 ;
}
static void
F_48 ( struct V_35 * V_36 , struct V_126 * V_127 )
{
struct V_89 * V_128 , * * V_129 , * V_130 , * V_90 ;
struct V_131 * V_132 = V_127 -> V_133 ;
struct V_1 * V_2 = & V_36 -> V_38 ;
struct V_15 * V_16 ;
struct V_11 * V_32 ;
int V_134 , V_18 ;
F_10 ( L_17 , V_27 , V_127 ) ;
V_16 = NULL ;
V_134 = 0 ;
V_129 = & V_128 ;
F_49 (mw, &req->rl_registered, mw_list) {
V_32 -> V_17 . V_30 = V_31 ;
if ( ( V_132 -> V_135 & V_136 ) &&
( V_32 -> V_120 == V_132 -> V_137 ) )
continue;
V_16 = & V_32 -> V_17 ;
F_10 ( L_18 ,
V_27 , V_16 ) ;
V_16 -> V_77 . V_109 = F_32 ;
V_130 = & V_16 -> V_138 ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_76 = & V_16 -> V_77 ;
V_130 -> V_107 = V_139 ;
V_130 -> V_140 . V_141 = V_32 -> V_120 ;
V_134 ++ ;
* V_129 = V_130 ;
V_129 = & V_130 -> V_106 ;
}
if ( ! V_16 )
goto V_142;
V_130 -> V_111 = V_143 ;
V_16 -> V_77 . V_109 = F_33 ;
F_50 ( & V_16 -> V_26 ) ;
F_51 ( & V_36 -> V_116 , V_134 ) ;
V_36 -> V_43 . V_144 ++ ;
V_18 = F_47 ( V_2 -> V_117 -> V_118 , V_128 , & V_90 ) ;
if ( V_18 )
goto V_145;
F_52 ( & V_16 -> V_26 ) ;
V_142:
while ( ! F_13 ( & V_127 -> V_146 ) ) {
V_32 = F_53 ( & V_127 -> V_146 ) ;
F_10 ( L_19 ,
V_27 , & V_32 -> V_17 ) ;
F_20 ( V_2 -> V_5 ,
V_32 -> V_23 , V_32 -> V_40 , V_32 -> V_41 ) ;
F_21 ( V_36 , V_32 ) ;
}
return;
V_145:
F_15 ( L_20 , V_18 ) ;
F_54 ( V_2 -> V_117 ) ;
F_49 (mw, &req->rl_registered, mw_list) {
V_16 = & V_32 -> V_17 ;
if ( V_32 -> V_120 == V_90 -> V_140 . V_141 ) {
F_17 ( V_2 , V_32 ) ;
V_90 = V_90 -> V_106 ;
}
}
goto V_142;
}
static void
F_55 ( struct V_35 * V_36 , struct V_126 * V_127 ,
bool V_147 )
{
struct V_11 * V_32 ;
while ( ! F_13 ( & V_127 -> V_146 ) ) {
V_32 = F_53 ( & V_127 -> V_146 ) ;
if ( V_147 )
F_19 ( V_32 ) ;
else
F_36 ( V_32 ) ;
}
}
