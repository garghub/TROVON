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
static int
F_5 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
int V_13 ;
V_13 = F_6 ( V_11 -> V_14 ) ;
if ( V_13 ) {
F_7 ( L_2 ,
V_13 , V_9 ) ;
return V_13 ;
}
V_11 -> V_14 = F_8 ( V_7 -> V_15 , V_16 ,
V_7 -> V_17 ) ;
if ( F_9 ( V_11 -> V_14 ) ) {
F_7 ( L_3 ,
F_10 ( V_11 -> V_14 ) , V_9 ) ;
return F_10 ( V_11 -> V_14 ) ;
}
F_11 ( L_4 , V_18 , V_9 ) ;
V_11 -> V_19 = V_20 ;
return 0 ;
}
static void
F_12 ( struct V_21 * V_22 , struct V_8 * V_23 )
{
struct V_6 * V_7 = & V_22 -> V_24 ;
struct V_10 * V_11 = & V_23 -> V_12 ;
int V_13 ;
V_13 = F_5 ( V_7 , V_23 ) ;
F_13 ( V_7 -> V_25 , V_11 -> V_26 , V_11 -> V_27 , V_11 -> V_28 ) ;
if ( V_13 )
return;
F_14 ( V_22 , V_23 ) ;
}
static void
F_15 ( struct V_29 * V_30 )
{
struct V_8 * V_9 = F_16 ( V_30 , struct V_8 ,
V_31 ) ;
F_12 ( V_9 -> V_32 , V_9 ) ;
return;
}
static void
F_17 ( struct V_8 * V_9 )
{
F_18 ( & V_9 -> V_31 , F_15 ) ;
F_19 ( V_1 , & V_9 -> V_31 ) ;
}
static int
F_20 ( struct V_8 * V_9 , struct V_33 * V_34 , struct V_35 * V_36 ,
unsigned int V_37 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
int V_13 ;
V_11 -> V_14 = F_8 ( V_34 , V_16 , V_37 ) ;
if ( F_9 ( V_11 -> V_14 ) )
goto V_38;
V_11 -> V_26 = F_21 ( V_37 , sizeof( * V_11 -> V_26 ) , V_39 ) ;
if ( ! V_11 -> V_26 )
goto V_40;
F_22 ( V_11 -> V_26 , V_37 ) ;
F_23 ( & V_11 -> V_41 ) ;
return 0 ;
V_38:
V_13 = F_10 ( V_11 -> V_14 ) ;
F_11 ( L_5 ,
V_18 , V_13 ) ;
return V_13 ;
V_40:
V_13 = - V_3 ;
F_11 ( L_6 ,
V_18 ) ;
F_6 ( V_11 -> V_14 ) ;
return V_13 ;
}
static void
F_24 ( struct V_8 * V_9 )
{
int V_13 ;
V_13 = F_6 ( V_9 -> V_12 . V_14 ) ;
if ( V_13 )
F_11 ( L_7 ,
V_18 , V_13 ) ;
F_25 ( V_9 -> V_12 . V_26 ) ;
}
static int
F_26 ( struct V_6 * V_7 , struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_37 , V_46 ;
V_7 -> V_17 =
F_27 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
ia->ri_device->attrs.max_fast_reg_page_list_len) ;
F_11 ( L_8 ,
V_18 , V_7 -> V_17 ) ;
V_37 = 7 ;
if ( V_7 -> V_17 < V_47 ) {
V_46 = V_47 - V_7 -> V_17 ;
do {
V_37 += 2 ;
V_46 -= V_7 -> V_17 ;
} while ( V_46 > 0 );
}
V_43 -> V_48 . V_49 . V_50 *= V_37 ;
if ( V_43 -> V_48 . V_49 . V_50 > V_7 -> V_25 -> V_51 . V_52 ) {
V_45 -> V_53 = V_7 -> V_25 -> V_51 . V_52 / V_37 ;
if ( ! V_45 -> V_53 )
return - V_54 ;
V_43 -> V_48 . V_49 . V_50 = V_45 -> V_53 *
V_37 ;
}
F_28 ( V_7 , V_45 , F_29 (unsigned int, 1 ,
RPCRDMA_MAX_DATA_SEGS /
ia->ri_max_frmr_depth) ) ;
return 0 ;
}
static T_1
F_30 ( struct V_21 * V_22 )
{
struct V_6 * V_7 = & V_22 -> V_24 ;
return F_27 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS * ia->ri_max_frmr_depth) ;
}
static void
F_31 ( struct V_55 * V_56 , struct V_10 * V_12 ,
const char * V_57 )
{
V_12 -> V_19 = V_58 ;
if ( V_56 -> V_59 != V_60 )
F_32 ( L_9 ,
V_57 , F_33 ( V_56 -> V_59 ) ,
V_56 -> V_59 , V_56 -> V_61 ) ;
}
static void
F_34 ( struct V_62 * V_63 , struct V_55 * V_56 )
{
struct V_10 * V_12 ;
struct V_64 * V_65 ;
if ( V_56 -> V_59 != V_66 ) {
V_65 = V_56 -> V_67 ;
V_12 = F_16 ( V_65 , struct V_10 , V_68 ) ;
F_31 ( V_56 , V_12 , L_10 ) ;
}
}
static void
F_35 ( struct V_62 * V_63 , struct V_55 * V_56 )
{
struct V_10 * V_12 ;
struct V_64 * V_65 ;
if ( V_56 -> V_59 != V_66 ) {
V_65 = V_56 -> V_67 ;
V_12 = F_16 ( V_65 , struct V_10 , V_68 ) ;
F_31 ( V_56 , V_12 , L_11 ) ;
}
}
static void
F_36 ( struct V_62 * V_63 , struct V_55 * V_56 )
{
struct V_10 * V_12 ;
struct V_64 * V_65 ;
V_65 = V_56 -> V_67 ;
V_12 = F_16 ( V_65 , struct V_10 , V_68 ) ;
if ( V_56 -> V_59 != V_66 )
F_31 ( V_56 , V_12 , L_11 ) ;
F_37 ( & V_12 -> V_41 ) ;
}
static int
F_38 ( struct V_21 * V_22 )
{
struct V_69 * V_70 = & V_22 -> V_71 ;
struct V_35 * V_36 = V_22 -> V_24 . V_25 ;
unsigned int V_37 = V_22 -> V_24 . V_17 ;
struct V_33 * V_34 = V_22 -> V_24 . V_15 ;
int V_72 ;
F_39 ( & V_70 -> V_73 ) ;
F_40 ( & V_70 -> V_74 ) ;
F_40 ( & V_70 -> V_75 ) ;
V_72 = F_29 ( int , V_47 / V_37 , 1 ) ;
V_72 += 2 ;
V_72 *= V_70 -> V_76 ;
F_11 ( L_12 , V_18 , V_72 ) ;
while ( V_72 -- ) {
struct V_8 * V_9 ;
int V_13 ;
V_9 = F_41 ( sizeof( * V_9 ) , V_39 ) ;
if ( ! V_9 )
return - V_3 ;
V_13 = F_20 ( V_9 , V_34 , V_36 , V_37 ) ;
if ( V_13 ) {
F_25 ( V_9 ) ;
return V_13 ;
}
V_9 -> V_32 = V_22 ;
F_42 ( & V_9 -> V_77 , & V_70 -> V_74 ) ;
F_42 ( & V_9 -> V_78 , & V_70 -> V_75 ) ;
}
return 0 ;
}
static int
F_43 ( struct V_21 * V_22 , struct V_79 * V_80 ,
int V_81 , bool V_82 )
{
struct V_6 * V_7 = & V_22 -> V_24 ;
struct V_35 * V_36 = V_7 -> V_25 ;
enum V_83 V_84 = F_44 ( V_82 ) ;
struct V_79 * V_85 = V_80 ;
struct V_8 * V_23 ;
struct V_10 * V_12 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
int V_13 , V_72 , V_92 , V_93 ;
T_2 V_94 ;
V_23 = V_85 -> V_95 ;
V_85 -> V_95 = NULL ;
do {
if ( V_23 )
F_17 ( V_23 ) ;
V_23 = F_45 ( V_22 ) ;
if ( ! V_23 )
return - V_3 ;
} while ( V_23 -> V_12 . V_19 != V_20 );
V_12 = & V_23 -> V_12 ;
V_12 -> V_19 = V_96 ;
V_87 = V_12 -> V_14 ;
V_89 = & V_12 -> V_97 ;
if ( V_81 > V_7 -> V_17 )
V_81 = V_7 -> V_17 ;
for ( V_72 = 0 ; V_72 < V_81 ; ) {
if ( V_80 -> V_98 )
F_46 ( & V_12 -> V_26 [ V_72 ] ,
V_80 -> V_98 ,
V_80 -> V_99 ,
F_47 ( V_80 -> V_100 ) ) ;
else
F_48 ( & V_12 -> V_26 [ V_72 ] , V_80 -> V_100 ,
V_80 -> V_99 ) ;
++ V_80 ;
++ V_72 ;
if ( ( V_72 < V_81 && F_47 ( V_80 -> V_100 ) ) ||
F_47 ( ( V_80 - 1 ) -> V_100 + ( V_80 - 1 ) -> V_99 ) )
break;
}
V_12 -> V_27 = V_72 ;
V_12 -> V_28 = V_84 ;
V_93 = F_49 ( V_36 , V_12 -> V_26 , V_12 -> V_27 , V_84 ) ;
if ( ! V_93 ) {
F_32 ( L_13 ,
V_18 , V_12 -> V_26 , V_12 -> V_27 ) ;
return - V_3 ;
}
V_92 = F_50 ( V_87 , V_12 -> V_26 , V_12 -> V_27 , NULL , V_101 ) ;
if ( F_51 ( V_92 != V_12 -> V_27 ) ) {
F_32 ( L_14 ,
V_18 , V_12 -> V_14 , V_92 , V_12 -> V_27 ) ;
V_13 = V_92 < 0 ? V_92 : - V_54 ;
goto V_102;
}
F_11 ( L_15 ,
V_18 , V_23 , V_12 -> V_27 , V_87 -> V_103 ) ;
V_94 = ( T_2 ) ( V_87 -> V_104 & 0x000000FF ) ;
F_52 ( V_87 , ++ V_94 ) ;
V_89 -> V_57 . V_105 = NULL ;
V_89 -> V_57 . V_106 = V_107 ;
V_12 -> V_68 . V_108 = F_34 ;
V_89 -> V_57 . V_67 = & V_12 -> V_68 ;
V_89 -> V_57 . V_109 = 0 ;
V_89 -> V_57 . V_110 = 0 ;
V_89 -> V_87 = V_87 ;
V_89 -> V_94 = V_87 -> V_104 ;
V_89 -> V_111 = V_82 ?
V_112 | V_113 :
V_114 ;
F_53 ( & V_22 -> V_115 ) ;
V_13 = F_54 ( V_7 -> V_116 -> V_117 , & V_89 -> V_57 , & V_91 ) ;
if ( V_13 )
goto V_102;
V_85 -> V_95 = V_23 ;
V_85 -> V_118 = V_87 -> V_104 ;
V_85 -> V_119 = V_87 -> V_120 ;
V_85 -> V_121 = V_12 -> V_27 ;
V_85 -> V_99 = V_87 -> V_103 ;
return V_12 -> V_27 ;
V_102:
F_11 ( L_16 , V_18 , V_13 ) ;
F_17 ( V_23 ) ;
return V_13 ;
}
static struct V_90 *
F_55 ( struct V_79 * V_80 )
{
struct V_8 * V_23 = V_80 -> V_95 ;
struct V_10 * V_11 = & V_23 -> V_12 ;
struct V_90 * V_122 ;
V_11 -> V_19 = V_20 ;
V_122 = & V_11 -> V_123 ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_11 -> V_68 . V_108 = F_35 ;
V_122 -> V_67 = & V_11 -> V_68 ;
V_122 -> V_106 = V_124 ;
V_122 -> V_125 . V_126 = V_11 -> V_14 -> V_104 ;
return V_122 ;
}
static void
F_56 ( struct V_21 * V_22 , struct V_127 * V_128 )
{
struct V_90 * V_129 , * V_130 , * V_131 , * V_91 ;
struct V_6 * V_7 = & V_22 -> V_24 ;
struct V_79 * V_80 ;
unsigned int V_72 , V_132 ;
struct V_10 * V_11 ;
struct V_8 * V_23 ;
int V_13 ;
F_11 ( L_17 , V_18 , V_128 ) ;
V_129 = V_130 = V_131 = NULL ;
V_80 = NULL ;
for ( V_72 = 0 , V_132 = V_128 -> V_133 ; V_132 ; V_132 -- ) {
V_80 = & V_128 -> V_134 [ V_72 ] ;
V_130 = F_55 ( V_80 ) ;
if ( ! V_129 )
V_129 = V_130 ;
else
V_131 -> V_105 = V_130 ;
V_131 = V_130 ;
V_72 += V_80 -> V_121 ;
}
V_11 = & V_80 -> V_95 -> V_12 ;
V_11 -> V_123 . V_110 = V_135 ;
V_11 -> V_68 . V_108 = F_36 ;
F_57 ( & V_11 -> V_41 ) ;
F_58 ( & V_22 -> V_115 ) ;
V_13 = F_54 ( V_7 -> V_116 -> V_117 , V_129 , & V_91 ) ;
if ( V_13 )
goto V_136;
F_59 ( & V_11 -> V_41 ) ;
V_137:
for ( V_72 = 0 , V_132 = V_128 -> V_133 ; V_132 ; V_132 -- ) {
V_80 = & V_128 -> V_134 [ V_72 ] ;
V_23 = V_80 -> V_95 ;
V_80 -> V_95 = NULL ;
F_13 ( V_7 -> V_25 , V_11 -> V_26 , V_11 -> V_27 ,
V_11 -> V_28 ) ;
F_14 ( V_22 , V_23 ) ;
V_72 += V_80 -> V_121 ;
V_80 -> V_121 = 0 ;
}
V_128 -> V_133 = 0 ;
return;
V_136:
F_7 ( L_18 , V_18 , V_13 ) ;
for ( V_72 = 0 , V_132 = V_128 -> V_133 ; V_132 ; V_132 -- ) {
V_80 = & V_128 -> V_134 [ V_72 ] ;
V_23 = V_80 -> V_95 ;
V_11 = & V_23 -> V_12 ;
if ( V_23 -> V_12 . V_14 -> V_104 == V_91 -> V_125 . V_126 ) {
F_5 ( V_7 , V_23 ) ;
V_91 = V_91 -> V_105 ;
}
V_72 += V_80 -> V_121 ;
}
goto V_137;
}
static void
F_60 ( struct V_21 * V_22 , struct V_127 * V_128 ,
bool V_138 )
{
struct V_79 * V_80 ;
struct V_8 * V_23 ;
unsigned int V_72 ;
for ( V_72 = 0 ; V_128 -> V_133 ; V_128 -> V_133 -- ) {
V_80 = & V_128 -> V_134 [ V_72 ] ;
V_23 = V_80 -> V_95 ;
if ( V_138 )
F_12 ( V_22 , V_23 ) ;
else
F_17 ( V_23 ) ;
V_72 += V_80 -> V_121 ;
V_80 -> V_121 = 0 ;
V_80 -> V_95 = NULL ;
}
}
static void
F_61 ( struct V_69 * V_70 )
{
struct V_8 * V_9 ;
F_62 ( V_1 ) ;
while ( ! F_63 ( & V_70 -> V_75 ) ) {
V_9 = F_64 ( V_70 -> V_75 . V_105 , struct V_8 , V_78 ) ;
F_65 ( & V_9 -> V_78 ) ;
F_24 ( V_9 ) ;
F_25 ( V_9 ) ;
}
}
