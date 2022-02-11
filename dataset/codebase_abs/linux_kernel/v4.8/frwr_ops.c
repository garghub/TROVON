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
F_10 ( L_7 , V_27 , V_12 ) ;
V_16 -> V_30 = V_31 ;
return 0 ;
}
static void
F_19 ( struct V_11 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = & V_34 -> V_36 ;
int V_18 ;
V_18 = F_17 ( V_2 , V_32 ) ;
F_20 ( V_2 -> V_5 , V_32 -> V_23 , V_32 -> V_37 , V_32 -> V_38 ) ;
if ( V_18 )
goto V_39;
F_21 ( V_34 , V_32 ) ;
V_34 -> V_40 . V_41 ++ ;
return;
V_39:
F_15 ( L_8 , V_18 , V_32 ) ;
V_34 -> V_40 . V_42 ++ ;
F_22 ( & V_34 -> V_43 . V_44 ) ;
F_14 ( & V_32 -> V_45 ) ;
F_23 ( & V_34 -> V_43 . V_44 ) ;
F_12 ( V_32 ) ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_46 * V_47 ,
struct V_48 * V_49 )
{
int V_13 , V_50 ;
V_2 -> V_14 =
F_25 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
ia->ri_device->attrs.max_fast_reg_page_list_len) ;
F_10 ( L_9 ,
V_27 , V_2 -> V_14 ) ;
V_13 = 7 ;
if ( V_2 -> V_14 < V_51 ) {
V_50 = V_51 - V_2 -> V_14 ;
do {
V_13 += 2 ;
V_50 -= V_2 -> V_14 ;
} while ( V_50 > 0 );
}
V_47 -> V_52 . V_53 . V_54 *= V_13 ;
if ( V_47 -> V_52 . V_53 . V_54 > V_2 -> V_5 -> V_4 . V_55 ) {
V_49 -> V_56 = V_2 -> V_5 -> V_4 . V_55 / V_13 ;
if ( ! V_49 -> V_56 )
return - V_57 ;
V_47 -> V_52 . V_53 . V_54 = V_49 -> V_56 *
V_13 ;
}
F_26 ( V_2 , V_49 , F_27 (unsigned int, 1 ,
RPCRDMA_MAX_DATA_SEGS /
ia->ri_max_frmr_depth) ) ;
return 0 ;
}
static T_1
F_28 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = & V_34 -> V_36 ;
return F_25 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS * ia->ri_max_frmr_depth) ;
}
static void
F_29 ( struct V_58 * V_59 , struct V_15 * V_17 ,
const char * V_60 )
{
V_17 -> V_30 = V_61 ;
if ( V_59 -> V_62 != V_63 )
F_15 ( L_10 ,
V_60 , F_30 ( V_59 -> V_62 ) ,
V_59 -> V_62 , V_59 -> V_64 ) ;
}
static void
F_31 ( struct V_65 * V_66 , struct V_58 * V_59 )
{
struct V_15 * V_17 ;
struct V_67 * V_68 ;
if ( V_59 -> V_62 != V_69 ) {
V_68 = V_59 -> V_70 ;
V_17 = F_32 ( V_68 , struct V_15 , V_71 ) ;
F_29 ( V_59 , V_17 , L_11 ) ;
}
}
static void
F_33 ( struct V_65 * V_66 , struct V_58 * V_59 )
{
struct V_15 * V_17 ;
struct V_67 * V_68 ;
if ( V_59 -> V_62 != V_69 ) {
V_68 = V_59 -> V_70 ;
V_17 = F_32 ( V_68 , struct V_15 , V_71 ) ;
F_29 ( V_59 , V_17 , L_12 ) ;
}
}
static void
F_34 ( struct V_65 * V_66 , struct V_58 * V_59 )
{
struct V_15 * V_17 ;
struct V_67 * V_68 ;
V_68 = V_59 -> V_70 ;
V_17 = F_32 ( V_68 , struct V_15 , V_71 ) ;
if ( V_59 -> V_62 != V_69 )
F_29 ( V_59 , V_17 , L_12 ) ;
F_35 ( & V_17 -> V_26 ) ;
}
static int
F_36 ( struct V_33 * V_34 , struct V_72 * V_73 ,
int V_74 , bool V_75 , struct V_11 * * V_76 )
{
struct V_1 * V_2 = & V_34 -> V_36 ;
struct V_11 * V_32 ;
struct V_15 * V_17 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
int V_18 , V_83 , V_84 , V_85 ;
T_2 V_86 ;
V_32 = NULL ;
do {
if ( V_32 )
F_37 ( V_32 ) ;
V_32 = F_38 ( V_34 ) ;
if ( ! V_32 )
return - V_87 ;
} while ( V_32 -> V_17 . V_30 != V_31 );
V_17 = & V_32 -> V_17 ;
V_17 -> V_30 = V_88 ;
V_78 = V_17 -> V_19 ;
V_80 = & V_17 -> V_89 ;
if ( V_74 > V_2 -> V_14 )
V_74 = V_2 -> V_14 ;
for ( V_83 = 0 ; V_83 < V_74 ; ) {
if ( V_73 -> V_90 )
F_39 ( & V_32 -> V_23 [ V_83 ] ,
V_73 -> V_90 ,
V_73 -> V_91 ,
F_40 ( V_73 -> V_92 ) ) ;
else
F_41 ( & V_32 -> V_23 [ V_83 ] , V_73 -> V_92 ,
V_73 -> V_91 ) ;
++ V_73 ;
++ V_83 ;
if ( ( V_83 < V_74 && F_40 ( V_73 -> V_92 ) ) ||
F_40 ( ( V_73 - 1 ) -> V_92 + ( V_73 - 1 ) -> V_91 ) )
break;
}
V_32 -> V_37 = V_83 ;
V_32 -> V_38 = F_42 ( V_75 ) ;
if ( V_83 == 0 )
goto V_93;
V_85 = F_43 ( V_2 -> V_5 ,
V_32 -> V_23 , V_32 -> V_37 , V_32 -> V_38 ) ;
if ( ! V_85 )
goto V_93;
V_84 = F_44 ( V_78 , V_32 -> V_23 , V_32 -> V_37 , NULL , V_94 ) ;
if ( F_45 ( V_84 != V_32 -> V_37 ) )
goto V_95;
F_10 ( L_13 ,
V_27 , V_32 , V_32 -> V_37 , V_78 -> V_96 ) ;
V_86 = ( T_2 ) ( V_78 -> V_97 & 0x000000FF ) ;
F_46 ( V_78 , ++ V_86 ) ;
V_80 -> V_60 . V_98 = NULL ;
V_80 -> V_60 . V_99 = V_100 ;
V_17 -> V_71 . V_101 = F_31 ;
V_80 -> V_60 . V_70 = & V_17 -> V_71 ;
V_80 -> V_60 . V_102 = 0 ;
V_80 -> V_60 . V_103 = 0 ;
V_80 -> V_78 = V_78 ;
V_80 -> V_86 = V_78 -> V_97 ;
V_80 -> V_104 = V_75 ?
V_105 | V_106 :
V_107 ;
F_47 ( & V_34 -> V_108 ) ;
V_18 = F_48 ( V_2 -> V_109 -> V_110 , & V_80 -> V_60 , & V_82 ) ;
if ( V_18 )
goto V_111;
V_32 -> V_112 = V_78 -> V_97 ;
V_32 -> V_113 = V_78 -> V_96 ;
V_32 -> V_114 = V_78 -> V_115 ;
* V_76 = V_32 ;
return V_32 -> V_37 ;
V_93:
F_15 ( L_14 ,
V_32 -> V_23 , V_32 -> V_37 ) ;
F_37 ( V_32 ) ;
return - V_116 ;
V_95:
F_15 ( L_15 ,
V_17 -> V_19 , V_84 , V_32 -> V_37 ) ;
F_37 ( V_32 ) ;
return - V_116 ;
V_111:
F_15 ( L_16 , V_18 ) ;
F_37 ( V_32 ) ;
return - V_117 ;
}
static struct V_81 *
F_49 ( struct V_11 * V_32 )
{
struct V_15 * V_16 = & V_32 -> V_17 ;
struct V_81 * V_118 ;
V_16 -> V_30 = V_31 ;
V_118 = & V_16 -> V_119 ;
memset ( V_118 , 0 , sizeof( * V_118 ) ) ;
V_16 -> V_71 . V_101 = F_33 ;
V_118 -> V_70 = & V_16 -> V_71 ;
V_118 -> V_99 = V_120 ;
V_118 -> V_121 . V_122 = V_16 -> V_19 -> V_97 ;
return V_118 ;
}
static void
F_50 ( struct V_33 * V_34 , struct V_123 * V_124 )
{
struct V_81 * V_125 , * V_126 , * V_127 , * V_82 ;
struct V_1 * V_2 = & V_34 -> V_36 ;
struct V_11 * V_32 , * V_128 ;
struct V_15 * V_16 ;
int V_18 ;
F_10 ( L_17 , V_27 , V_124 ) ;
V_16 = NULL ;
V_125 = V_126 = V_127 = NULL ;
F_51 (mw, &req->rl_registered, mw_list) {
V_126 = F_49 ( V_32 ) ;
if ( ! V_125 )
V_125 = V_126 ;
else
V_127 -> V_98 = V_126 ;
V_127 = V_126 ;
V_16 = & V_32 -> V_17 ;
}
V_16 -> V_119 . V_103 = V_129 ;
V_16 -> V_71 . V_101 = F_34 ;
F_52 ( & V_16 -> V_26 ) ;
F_53 ( & V_34 -> V_108 ) ;
V_18 = F_48 ( V_2 -> V_109 -> V_110 , V_125 , & V_82 ) ;
if ( V_18 )
goto V_130;
F_54 ( & V_16 -> V_26 ) ;
V_131:
F_55 (mw, tmp, &req->rl_registered, mw_list) {
F_56 ( & V_32 -> V_29 ) ;
F_20 ( V_2 -> V_5 ,
V_32 -> V_23 , V_32 -> V_37 , V_32 -> V_38 ) ;
F_21 ( V_34 , V_32 ) ;
}
return;
V_130:
F_15 ( L_18 , V_18 ) ;
F_57 ( V_2 -> V_109 ) ;
F_51 (mw, &req->rl_registered, mw_list) {
V_16 = & V_32 -> V_17 ;
if ( V_32 -> V_17 . V_19 -> V_97 == V_82 -> V_121 . V_122 ) {
F_17 ( V_2 , V_32 ) ;
V_82 = V_82 -> V_98 ;
}
}
goto V_131;
}
static void
F_58 ( struct V_33 * V_34 , struct V_123 * V_124 ,
bool V_132 )
{
struct V_11 * V_32 ;
while ( ! F_13 ( & V_124 -> V_133 ) ) {
V_32 = F_59 ( & V_124 -> V_133 ,
struct V_11 , V_29 ) ;
F_56 ( & V_32 -> V_29 ) ;
if ( V_132 )
F_19 ( V_32 ) ;
else
F_37 ( V_32 ) ;
}
}
