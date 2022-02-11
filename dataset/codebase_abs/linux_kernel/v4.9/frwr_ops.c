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
V_16 -> V_19 = F_4 ( V_2 -> V_20 , V_21 , V_13 ) ;
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
V_16 -> V_19 = F_4 ( V_2 -> V_20 , V_21 ,
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
int V_13 , V_53 ;
V_2 -> V_14 =
F_25 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
ia->ri_device->attrs.max_fast_reg_page_list_len) ;
F_10 ( L_9 ,
V_27 , V_2 -> V_14 ) ;
V_13 = 7 ;
if ( V_2 -> V_14 < V_54 ) {
V_53 = V_54 - V_2 -> V_14 ;
do {
V_13 += 2 ;
V_53 -= V_2 -> V_14 ;
} while ( V_53 > 0 );
}
V_50 -> V_55 . V_56 . V_57 *= V_13 ;
if ( V_50 -> V_55 . V_56 . V_57 > V_2 -> V_5 -> V_4 . V_58 ) {
V_52 -> V_59 = V_2 -> V_5 -> V_4 . V_58 / V_13 ;
if ( ! V_52 -> V_59 )
return - V_60 ;
V_50 -> V_55 . V_56 . V_57 = V_52 -> V_59 *
V_13 ;
}
V_2 -> V_61 = F_26 (unsigned int, 1 , RPCRDMA_MAX_DATA_SEGS /
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
F_28 ( struct V_62 * V_63 , const char * V_64 )
{
if ( V_63 -> V_65 != V_66 )
F_15 ( L_10 ,
V_64 , F_29 ( V_63 -> V_65 ) ,
V_63 -> V_65 , V_63 -> V_67 ) ;
}
static void
F_30 ( struct V_68 * V_69 , struct V_62 * V_63 )
{
struct V_15 * V_17 ;
struct V_70 * V_71 ;
if ( V_63 -> V_65 != V_72 ) {
V_71 = V_63 -> V_73 ;
V_17 = F_31 ( V_71 , struct V_15 , V_74 ) ;
V_17 -> V_30 = V_75 ;
F_28 ( V_63 , L_11 ) ;
}
}
static void
F_32 ( struct V_68 * V_69 , struct V_62 * V_63 )
{
struct V_15 * V_17 ;
struct V_70 * V_71 ;
if ( V_63 -> V_65 != V_72 ) {
V_71 = V_63 -> V_73 ;
V_17 = F_31 ( V_71 , struct V_15 , V_74 ) ;
V_17 -> V_30 = V_39 ;
F_28 ( V_63 , L_12 ) ;
}
}
static void
F_33 ( struct V_68 * V_69 , struct V_62 * V_63 )
{
struct V_15 * V_17 ;
struct V_70 * V_71 ;
V_71 = V_63 -> V_73 ;
V_17 = F_31 ( V_71 , struct V_15 , V_74 ) ;
if ( V_63 -> V_65 != V_72 ) {
V_17 -> V_30 = V_39 ;
F_28 ( V_63 , L_12 ) ;
}
F_34 ( & V_17 -> V_26 ) ;
}
static int
F_35 ( struct V_35 * V_36 , struct V_76 * V_77 ,
int V_78 , bool V_79 , struct V_11 * * V_80 )
{
struct V_1 * V_2 = & V_36 -> V_38 ;
struct V_11 * V_32 ;
struct V_15 * V_17 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
int V_18 , V_87 , V_88 , V_89 ;
T_2 V_90 ;
V_32 = NULL ;
do {
if ( V_32 )
F_36 ( V_32 ) ;
V_32 = F_37 ( V_36 ) ;
if ( ! V_32 )
return - V_91 ;
} while ( V_32 -> V_17 . V_30 != V_31 );
V_17 = & V_32 -> V_17 ;
V_17 -> V_30 = V_92 ;
V_82 = V_17 -> V_19 ;
V_84 = & V_17 -> V_93 ;
if ( V_78 > V_2 -> V_14 )
V_78 = V_2 -> V_14 ;
for ( V_87 = 0 ; V_87 < V_78 ; ) {
if ( V_77 -> V_94 )
F_38 ( & V_32 -> V_23 [ V_87 ] ,
V_77 -> V_94 ,
V_77 -> V_95 ,
F_39 ( V_77 -> V_96 ) ) ;
else
F_40 ( & V_32 -> V_23 [ V_87 ] , V_77 -> V_96 ,
V_77 -> V_95 ) ;
++ V_77 ;
++ V_87 ;
if ( ( V_87 < V_78 && F_39 ( V_77 -> V_96 ) ) ||
F_39 ( ( V_77 - 1 ) -> V_96 + ( V_77 - 1 ) -> V_95 ) )
break;
}
V_32 -> V_40 = V_87 ;
V_32 -> V_41 = F_41 ( V_79 ) ;
if ( V_87 == 0 )
goto V_97;
V_89 = F_42 ( V_2 -> V_5 ,
V_32 -> V_23 , V_32 -> V_40 , V_32 -> V_41 ) ;
if ( ! V_89 )
goto V_97;
V_88 = F_43 ( V_82 , V_32 -> V_23 , V_32 -> V_40 , NULL , V_98 ) ;
if ( F_44 ( V_88 != V_32 -> V_40 ) )
goto V_99;
F_10 ( L_13 ,
V_27 , V_17 , V_32 -> V_40 , V_82 -> V_100 ) ;
V_90 = ( T_2 ) ( V_82 -> V_101 & 0x000000FF ) ;
F_45 ( V_82 , ++ V_90 ) ;
V_84 -> V_64 . V_102 = NULL ;
V_84 -> V_64 . V_103 = V_104 ;
V_17 -> V_74 . V_105 = F_30 ;
V_84 -> V_64 . V_73 = & V_17 -> V_74 ;
V_84 -> V_64 . V_106 = 0 ;
V_84 -> V_64 . V_107 = 0 ;
V_84 -> V_82 = V_82 ;
V_84 -> V_90 = V_82 -> V_101 ;
V_84 -> V_108 = V_79 ?
V_109 | V_110 :
V_111 ;
F_46 ( & V_36 -> V_112 ) ;
V_18 = F_47 ( V_2 -> V_113 -> V_114 , & V_84 -> V_64 , & V_86 ) ;
if ( V_18 )
goto V_115;
V_32 -> V_116 = V_82 -> V_101 ;
V_32 -> V_117 = V_82 -> V_100 ;
V_32 -> V_118 = V_82 -> V_119 ;
* V_80 = V_32 ;
return V_32 -> V_40 ;
V_97:
F_15 ( L_14 ,
V_32 -> V_23 , V_32 -> V_40 ) ;
F_36 ( V_32 ) ;
return - V_120 ;
V_99:
F_15 ( L_15 ,
V_17 -> V_19 , V_88 , V_32 -> V_40 ) ;
F_36 ( V_32 ) ;
return - V_120 ;
V_115:
F_15 ( L_16 , V_18 ) ;
F_36 ( V_32 ) ;
return - V_121 ;
}
static struct V_85 *
F_48 ( struct V_11 * V_32 )
{
struct V_15 * V_16 = & V_32 -> V_17 ;
struct V_85 * V_122 ;
F_10 ( L_17 , V_27 , V_16 ) ;
V_16 -> V_30 = V_31 ;
V_122 = & V_16 -> V_123 ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_16 -> V_74 . V_105 = F_32 ;
V_122 -> V_73 = & V_16 -> V_74 ;
V_122 -> V_103 = V_124 ;
V_122 -> V_125 . V_126 = V_16 -> V_19 -> V_101 ;
return V_122 ;
}
static void
F_49 ( struct V_35 * V_36 , struct V_127 * V_128 )
{
struct V_85 * V_129 , * V_130 , * V_131 , * V_86 ;
struct V_132 * V_133 = V_128 -> V_134 ;
struct V_1 * V_2 = & V_36 -> V_38 ;
struct V_11 * V_32 , * V_135 ;
struct V_15 * V_16 ;
int V_18 ;
F_10 ( L_18 , V_27 , V_128 ) ;
V_16 = NULL ;
V_129 = V_130 = V_131 = NULL ;
F_50 (mw, &req->rl_registered, mw_list) {
if ( ( V_133 -> V_136 & V_137 ) &&
( V_32 -> V_116 == V_133 -> V_138 ) ) {
V_32 -> V_17 . V_30 = V_31 ;
continue;
}
V_130 = F_48 ( V_32 ) ;
if ( ! V_129 )
V_129 = V_130 ;
else
V_131 -> V_102 = V_130 ;
V_131 = V_130 ;
V_16 = & V_32 -> V_17 ;
}
if ( ! V_16 )
goto V_139;
V_16 -> V_123 . V_107 = V_140 ;
V_16 -> V_74 . V_105 = F_33 ;
F_51 ( & V_16 -> V_26 ) ;
F_52 ( & V_36 -> V_112 ) ;
V_36 -> V_43 . V_141 ++ ;
V_18 = F_47 ( V_2 -> V_113 -> V_114 , V_129 , & V_86 ) ;
if ( V_18 )
goto V_142;
F_53 ( & V_16 -> V_26 ) ;
V_139:
F_54 (mw, tmp, &req->rl_registered, mw_list) {
F_10 ( L_19 ,
V_27 , & V_32 -> V_17 ) ;
F_55 ( & V_32 -> V_29 ) ;
F_20 ( V_2 -> V_5 ,
V_32 -> V_23 , V_32 -> V_40 , V_32 -> V_41 ) ;
F_21 ( V_36 , V_32 ) ;
}
return;
V_142:
F_15 ( L_20 , V_18 ) ;
F_56 ( V_2 -> V_113 ) ;
F_50 (mw, &req->rl_registered, mw_list) {
V_16 = & V_32 -> V_17 ;
if ( V_32 -> V_17 . V_19 -> V_101 == V_86 -> V_125 . V_126 ) {
F_17 ( V_2 , V_32 ) ;
V_86 = V_86 -> V_102 ;
}
}
goto V_139;
}
static void
F_57 ( struct V_35 * V_36 , struct V_127 * V_128 ,
bool V_143 )
{
struct V_11 * V_32 ;
while ( ! F_13 ( & V_128 -> V_144 ) ) {
V_32 = F_58 ( & V_128 -> V_144 ,
struct V_11 , V_29 ) ;
F_55 ( & V_32 -> V_29 ) ;
if ( V_143 )
F_19 ( V_32 ) ;
else
F_36 ( V_32 ) ;
}
}
