int
F_1 ( void )
{
V_1 = F_2 ( L_1 ,
V_2 , 0 ) ;
return ! V_1 ? - V_3 : 0 ;
}
void
F_3 ( void )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return;
V_5 = V_1 ;
V_1 = NULL ;
F_4 ( V_5 ) ;
}
static void
F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 , struct V_8 ,
V_10 . V_11 ) ;
struct V_12 * V_13 = V_9 -> V_10 . V_14 ;
unsigned int V_15 = V_13 -> V_16 . V_17 ;
struct V_18 * V_19 = V_13 -> V_16 . V_20 ;
if ( F_7 ( V_9 -> V_10 . V_21 ) )
goto V_22;
V_9 -> V_10 . V_21 = F_8 ( V_19 , V_23 , V_15 ) ;
if ( F_9 ( V_9 -> V_10 . V_21 ) )
goto V_22;
F_10 ( L_2 , V_24 , V_9 ) ;
V_9 -> V_10 . V_25 = V_26 ;
F_11 ( V_13 , V_9 ) ;
return;
V_22:
F_12 ( L_3 ,
V_24 , V_9 ) ;
}
static void
F_13 ( struct V_8 * V_9 )
{
F_14 ( & V_9 -> V_10 . V_11 , F_5 ) ;
F_15 ( V_1 , & V_9 -> V_10 . V_11 ) ;
}
static int
F_16 ( struct V_8 * V_9 , struct V_18 * V_19 , struct V_27 * V_28 ,
unsigned int V_15 )
{
struct V_29 * V_30 = & V_9 -> V_10 ;
int V_31 ;
V_30 -> V_21 = F_8 ( V_19 , V_23 , V_15 ) ;
if ( F_9 ( V_30 -> V_21 ) )
goto V_32;
V_30 -> V_33 = F_17 ( V_15 , sizeof( * V_30 -> V_33 ) , V_34 ) ;
if ( ! V_30 -> V_33 )
goto V_35;
F_18 ( V_30 -> V_33 , V_15 ) ;
F_19 ( & V_30 -> V_36 ) ;
return 0 ;
V_32:
V_31 = F_20 ( V_30 -> V_21 ) ;
F_10 ( L_4 ,
V_24 , V_31 ) ;
return V_31 ;
V_35:
V_31 = - V_3 ;
F_10 ( L_5 ,
V_24 ) ;
F_7 ( V_30 -> V_21 ) ;
return V_31 ;
}
static void
F_21 ( struct V_8 * V_9 )
{
int V_31 ;
V_31 = F_7 ( V_9 -> V_10 . V_21 ) ;
if ( V_31 )
F_10 ( L_6 ,
V_24 , V_31 ) ;
F_22 ( V_9 -> V_10 . V_33 ) ;
}
static int
F_23 ( struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_41 * V_42 )
{
int V_15 , V_43 ;
V_38 -> V_17 =
F_24 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
ia->ri_device->attrs.max_fast_reg_page_list_len) ;
F_10 ( L_7 ,
V_24 , V_38 -> V_17 ) ;
V_15 = 7 ;
if ( V_38 -> V_17 < V_44 ) {
V_43 = V_44 - V_38 -> V_17 ;
do {
V_15 += 2 ;
V_43 -= V_38 -> V_17 ;
} while ( V_43 > 0 );
}
V_40 -> V_45 . V_46 . V_47 *= V_15 ;
if ( V_40 -> V_45 . V_46 . V_47 > V_38 -> V_48 -> V_49 . V_50 ) {
V_42 -> V_51 = V_38 -> V_48 -> V_49 . V_50 / V_15 ;
if ( ! V_42 -> V_51 )
return - V_52 ;
V_40 -> V_45 . V_46 . V_47 = V_42 -> V_51 *
V_15 ;
}
return 0 ;
}
static T_1
F_25 ( struct V_12 * V_13 )
{
struct V_37 * V_38 = & V_13 -> V_16 ;
return F_24 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt) * ia->ri_max_frmr_depth) ;
}
static void
F_26 ( struct V_53 * V_54 , struct V_29 * V_10 ,
const char * V_55 )
{
V_10 -> V_25 = V_56 ;
if ( V_54 -> V_57 != V_58 )
F_27 ( L_8 ,
V_55 , F_28 ( V_54 -> V_57 ) ,
V_54 -> V_57 , V_54 -> V_59 ) ;
}
static void
F_29 ( struct V_60 * V_61 , struct V_53 * V_54 )
{
struct V_29 * V_10 ;
struct V_62 * V_63 ;
if ( V_54 -> V_57 != V_64 ) {
V_63 = V_54 -> V_65 ;
V_10 = F_6 ( V_63 , struct V_29 , V_66 ) ;
F_26 ( V_54 , V_10 , L_9 ) ;
}
}
static void
F_30 ( struct V_60 * V_61 , struct V_53 * V_54 )
{
struct V_29 * V_10 ;
struct V_62 * V_63 ;
if ( V_54 -> V_57 != V_64 ) {
V_63 = V_54 -> V_65 ;
V_10 = F_6 ( V_63 , struct V_29 , V_66 ) ;
F_26 ( V_54 , V_10 , L_10 ) ;
}
}
static void
F_31 ( struct V_60 * V_61 , struct V_53 * V_54 )
{
struct V_29 * V_10 ;
struct V_62 * V_63 ;
V_63 = V_54 -> V_65 ;
V_10 = F_6 ( V_63 , struct V_29 , V_66 ) ;
if ( V_54 -> V_57 != V_64 )
F_26 ( V_54 , V_10 , L_10 ) ;
F_32 ( & V_10 -> V_36 ) ;
}
static int
F_33 ( struct V_12 * V_13 )
{
struct V_67 * V_68 = & V_13 -> V_69 ;
struct V_27 * V_28 = V_13 -> V_16 . V_48 ;
unsigned int V_15 = V_13 -> V_16 . V_17 ;
struct V_18 * V_19 = V_13 -> V_16 . V_20 ;
int V_70 ;
F_34 ( & V_68 -> V_71 ) ;
F_35 ( & V_68 -> V_72 ) ;
F_35 ( & V_68 -> V_73 ) ;
V_70 = F_36 ( int , V_44 / V_15 , 1 ) ;
V_70 += 2 ;
V_70 *= V_68 -> V_74 ;
F_10 ( L_11 , V_24 , V_70 ) ;
while ( V_70 -- ) {
struct V_8 * V_9 ;
int V_31 ;
V_9 = F_37 ( sizeof( * V_9 ) , V_34 ) ;
if ( ! V_9 )
return - V_3 ;
V_31 = F_16 ( V_9 , V_19 , V_28 , V_15 ) ;
if ( V_31 ) {
F_22 ( V_9 ) ;
return V_31 ;
}
F_38 ( & V_9 -> V_75 , & V_68 -> V_72 ) ;
F_38 ( & V_9 -> V_76 , & V_68 -> V_73 ) ;
V_9 -> V_10 . V_14 = V_13 ;
}
return 0 ;
}
static int
F_39 ( struct V_12 * V_13 , struct V_77 * V_78 ,
int V_79 , bool V_80 )
{
struct V_37 * V_38 = & V_13 -> V_16 ;
struct V_27 * V_28 = V_38 -> V_48 ;
enum V_81 V_82 = F_40 ( V_80 ) ;
struct V_77 * V_83 = V_78 ;
struct V_8 * V_84 ;
struct V_29 * V_10 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
int V_31 , V_70 , V_91 , V_92 ;
T_2 V_93 ;
V_84 = V_83 -> V_94 ;
V_83 -> V_94 = NULL ;
do {
if ( V_84 )
F_13 ( V_84 ) ;
V_84 = F_41 ( V_13 ) ;
if ( ! V_84 )
return - V_3 ;
} while ( V_84 -> V_10 . V_25 != V_26 );
V_10 = & V_84 -> V_10 ;
V_10 -> V_25 = V_95 ;
V_86 = V_10 -> V_21 ;
V_88 = & V_10 -> V_96 ;
if ( V_79 > V_38 -> V_17 )
V_79 = V_38 -> V_17 ;
for ( V_70 = 0 ; V_70 < V_79 ; ) {
if ( V_78 -> V_97 )
F_42 ( & V_10 -> V_33 [ V_70 ] ,
V_78 -> V_97 ,
V_78 -> V_98 ,
F_43 ( V_78 -> V_99 ) ) ;
else
F_44 ( & V_10 -> V_33 [ V_70 ] , V_78 -> V_99 ,
V_78 -> V_98 ) ;
++ V_78 ;
++ V_70 ;
if ( ( V_70 < V_79 && F_43 ( V_78 -> V_99 ) ) ||
F_43 ( ( V_78 - 1 ) -> V_99 + ( V_78 - 1 ) -> V_98 ) )
break;
}
V_10 -> V_100 = V_70 ;
V_92 = F_45 ( V_28 , V_10 -> V_33 , V_10 -> V_100 , V_82 ) ;
if ( ! V_92 ) {
F_27 ( L_12 ,
V_24 , V_10 -> V_33 , V_10 -> V_100 ) ;
return - V_3 ;
}
V_91 = F_46 ( V_86 , V_10 -> V_33 , V_10 -> V_100 , V_101 ) ;
if ( F_47 ( V_91 != V_10 -> V_100 ) ) {
F_27 ( L_13 ,
V_24 , V_10 -> V_21 , V_91 , V_10 -> V_100 ) ;
V_31 = V_91 < 0 ? V_91 : - V_52 ;
goto V_102;
}
F_10 ( L_14 ,
V_24 , V_84 , V_10 -> V_100 , V_86 -> V_103 ) ;
V_93 = ( T_2 ) ( V_86 -> V_104 & 0x000000FF ) ;
F_48 ( V_86 , ++ V_93 ) ;
V_88 -> V_55 . V_105 = NULL ;
V_88 -> V_55 . V_106 = V_107 ;
V_10 -> V_66 . V_108 = F_29 ;
V_88 -> V_55 . V_65 = & V_10 -> V_66 ;
V_88 -> V_55 . V_109 = 0 ;
V_88 -> V_55 . V_110 = 0 ;
V_88 -> V_86 = V_86 ;
V_88 -> V_93 = V_86 -> V_104 ;
V_88 -> V_111 = V_80 ?
V_112 | V_113 :
V_114 ;
F_49 ( & V_13 -> V_115 ) ;
V_31 = F_50 ( V_38 -> V_116 -> V_117 , & V_88 -> V_55 , & V_90 ) ;
if ( V_31 )
goto V_102;
V_83 -> V_118 = V_82 ;
V_83 -> V_94 = V_84 ;
V_83 -> V_119 = V_86 -> V_104 ;
V_83 -> V_120 = V_86 -> V_121 ;
V_83 -> V_122 = V_10 -> V_100 ;
V_83 -> V_98 = V_86 -> V_103 ;
return V_10 -> V_100 ;
V_102:
F_10 ( L_15 , V_24 , V_31 ) ;
F_51 ( V_28 , V_10 -> V_33 , V_92 , V_82 ) ;
F_13 ( V_84 ) ;
return V_31 ;
}
static struct V_89 *
F_52 ( struct V_77 * V_78 )
{
struct V_8 * V_84 = V_78 -> V_94 ;
struct V_29 * V_30 = & V_84 -> V_10 ;
struct V_89 * V_123 ;
V_30 -> V_25 = V_26 ;
V_123 = & V_30 -> V_124 ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
V_30 -> V_66 . V_108 = F_30 ;
V_123 -> V_65 = & V_30 -> V_66 ;
V_123 -> V_106 = V_125 ;
V_123 -> V_126 . V_127 = V_30 -> V_21 -> V_104 ;
return V_123 ;
}
static void
F_53 ( struct V_12 * V_13 , struct V_77 * V_78 ,
int V_31 )
{
struct V_27 * V_28 = V_13 -> V_16 . V_48 ;
struct V_8 * V_84 = V_78 -> V_94 ;
struct V_29 * V_30 = & V_84 -> V_10 ;
V_78 -> V_94 = NULL ;
F_51 ( V_28 , V_30 -> V_33 , V_30 -> V_100 , V_78 -> V_118 ) ;
if ( ! V_31 )
F_11 ( V_13 , V_84 ) ;
else
F_13 ( V_84 ) ;
}
static void
F_54 ( struct V_12 * V_13 , struct V_128 * V_129 )
{
struct V_89 * V_130 , * V_131 , * V_132 , * V_90 ;
struct V_37 * V_38 = & V_13 -> V_16 ;
struct V_77 * V_78 ;
unsigned int V_70 , V_133 ;
struct V_29 * V_30 ;
int V_31 ;
F_10 ( L_16 , V_24 , V_129 ) ;
V_130 = V_131 = V_132 = NULL ;
V_78 = NULL ;
for ( V_70 = 0 , V_133 = V_129 -> V_134 ; V_133 ; V_133 -- ) {
V_78 = & V_129 -> V_135 [ V_70 ] ;
V_131 = F_52 ( V_78 ) ;
if ( ! V_130 )
V_130 = V_131 ;
else
V_132 -> V_105 = V_131 ;
V_132 = V_131 ;
V_70 += V_78 -> V_122 ;
}
V_30 = & V_78 -> V_94 -> V_10 ;
V_30 -> V_124 . V_110 = V_136 ;
V_30 -> V_66 . V_108 = F_31 ;
F_55 ( & V_30 -> V_36 ) ;
F_56 ( & V_13 -> V_115 ) ;
V_31 = F_50 ( V_38 -> V_116 -> V_117 , V_130 , & V_90 ) ;
if ( V_31 ) {
F_12 ( L_17 , V_24 , V_31 ) ;
F_57 ( V_38 -> V_116 ) ;
goto V_137;
}
F_58 ( & V_30 -> V_36 ) ;
V_137:
for ( V_70 = 0 , V_133 = V_129 -> V_134 ; V_133 ; V_133 -- ) {
V_78 = & V_129 -> V_135 [ V_70 ] ;
F_53 ( V_13 , V_78 , V_31 ) ;
V_70 += V_78 -> V_122 ;
V_78 -> V_122 = 0 ;
}
V_129 -> V_134 = 0 ;
}
static int
F_59 ( struct V_12 * V_13 , struct V_77 * V_78 )
{
struct V_77 * V_83 = V_78 ;
struct V_37 * V_38 = & V_13 -> V_16 ;
struct V_8 * V_84 = V_83 -> V_94 ;
struct V_29 * V_10 = & V_84 -> V_10 ;
struct V_89 * V_123 , * V_90 ;
int V_31 , V_79 = V_78 -> V_122 ;
F_10 ( L_18 , V_24 , V_84 ) ;
V_83 -> V_94 = NULL ;
V_10 -> V_25 = V_26 ;
V_123 = & V_84 -> V_10 . V_124 ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
V_10 -> V_66 . V_108 = F_30 ;
V_123 -> V_65 = & V_10 -> V_66 ;
V_123 -> V_106 = V_125 ;
V_123 -> V_126 . V_127 = V_10 -> V_21 -> V_104 ;
F_49 ( & V_13 -> V_115 ) ;
F_51 ( V_38 -> V_48 , V_10 -> V_33 , V_10 -> V_100 , V_83 -> V_118 ) ;
F_60 ( & V_38 -> V_138 ) ;
V_31 = F_50 ( V_38 -> V_116 -> V_117 , V_123 , & V_90 ) ;
F_61 ( & V_38 -> V_138 ) ;
if ( V_31 )
goto V_139;
F_11 ( V_13 , V_84 ) ;
return V_79 ;
V_139:
F_10 ( L_15 , V_24 , V_31 ) ;
F_13 ( V_84 ) ;
return V_79 ;
}
static void
F_62 ( struct V_67 * V_68 )
{
struct V_8 * V_9 ;
F_63 ( V_1 ) ;
while ( ! F_64 ( & V_68 -> V_73 ) ) {
V_9 = F_65 ( V_68 -> V_73 . V_105 , struct V_8 , V_76 ) ;
F_66 ( & V_9 -> V_76 ) ;
F_21 ( V_9 ) ;
F_22 ( V_9 ) ;
}
}
