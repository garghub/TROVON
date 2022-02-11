int
F_1 ( T_1 * V_1 )
{
if ( V_1 -> V_2 > 0 )
return V_1 -> V_2 ;
if ( V_3 > 0 )
return V_3 ;
return V_1 -> V_4 ;
}
int
F_2 ( void )
{
return V_5 ;
}
void
F_3 ( T_2 * V_6 , int V_7 , int V_8 ,
unsigned long V_9 )
{
if ( F_4 ( V_9 , V_6 -> V_10 ) ) {
F_5 ( V_11 , L_1 ) ;
return;
}
V_6 -> V_10 = V_9 ;
V_6 -> V_12 = 0 ;
if ( V_6 -> V_13 &&
( ! V_6 -> V_14 ) == ( ! V_8 ) ) {
F_5 ( V_11 , L_2 ) ;
return;
}
V_6 -> V_13 ++ ;
V_6 -> V_14 = ! ( ! V_8 ) ;
V_6 -> V_15 = 1 ;
V_6 -> V_16 |= V_7 ;
if ( V_6 -> V_14 )
V_6 -> V_17 = V_18 ;
F_5 ( V_11 , L_3 , F_6 ( V_6 -> V_19 ) , V_8 ) ;
}
static void
F_7 ( T_1 * V_1 , T_2 * V_6 )
{
int V_8 ;
int V_7 ;
if ( V_6 -> V_20 || ! V_1 )
return;
V_6 -> V_20 = 1 ;
while ( V_6 -> V_15 ) {
V_8 = V_6 -> V_14 ;
V_7 = V_6 -> V_16 ;
V_6 -> V_16 = 0 ;
V_6 -> V_15 = 0 ;
if ( V_7 && V_1 -> V_21 -> V_22 ) {
F_8 ( V_6 -> V_23 ) ;
V_1 -> V_21 -> V_22 ( V_1 , V_6 -> V_19 , V_8 ) ;
F_9 ( V_6 -> V_23 ) ;
}
}
V_6 -> V_20 = 0 ;
}
static void
F_10 ( T_2 * V_6 )
{
F_11 ( V_6 -> V_24 > 0 ) ;
F_11 ( V_6 -> V_25 >= 0 ) ;
V_6 -> V_25 ++ ;
if ( V_6 -> V_25 == 1 ) {
struct V_26 * V_27 ;
F_12 (pos, &the_lnet.ln_routers) {
T_2 * V_28 = F_13 ( V_27 , T_2 ,
V_29 ) ;
if ( V_28 -> V_19 < V_6 -> V_19 )
break;
}
F_14 ( & V_6 -> V_29 , V_27 ) ;
F_15 ( V_6 ) ;
V_30 . V_31 ++ ;
}
}
static void
F_16 ( T_2 * V_6 )
{
F_11 ( V_6 -> V_24 > 0 ) ;
F_11 ( V_6 -> V_25 > 0 ) ;
V_6 -> V_25 -- ;
if ( ! V_6 -> V_25 ) {
F_11 ( F_17 ( & V_6 -> V_32 ) ) ;
if ( V_6 -> V_33 ) {
F_14 ( & V_6 -> V_33 -> V_34 ,
& V_30 . V_35 ) ;
V_6 -> V_33 = NULL ;
}
F_18 ( & V_6 -> V_29 ) ;
F_19 ( V_6 ) ;
V_30 . V_31 ++ ;
}
}
T_3 *
F_20 ( T_4 V_36 )
{
T_3 * V_37 ;
struct V_26 * V_38 ;
struct V_26 * V_39 ;
F_11 ( ! V_30 . V_40 ) ;
V_39 = F_21 ( V_36 ) ;
F_22 (tmp, rn_list) {
V_37 = F_13 ( V_38 , T_3 , V_41 ) ;
if ( V_37 -> V_42 == V_36 )
return V_37 ;
}
return NULL ;
}
static void F_23 ( void )
{
static int V_43 ;
T_4 V_44 , V_45 [ 2 ] ;
struct V_46 V_47 ;
T_1 * V_1 ;
struct V_26 * V_38 ;
if ( V_43 )
return;
F_24 ( V_45 , sizeof( V_45 ) ) ;
F_22 (tmp, &the_lnet.ln_nis) {
V_1 = F_13 ( V_38 , T_1 , V_48 ) ;
V_44 = F_25 ( F_26 ( V_1 -> V_49 ) ) ;
if ( V_44 != V_50 )
V_45 [ 0 ] ^= ( F_27 ( V_1 -> V_49 ) | V_44 ) ;
}
F_28 ( & V_47 ) ;
F_29 ( V_47 . V_51 ^ V_45 [ 0 ] , V_47 . V_52 ^ V_45 [ 1 ] ) ;
V_43 = 1 ;
}
static void
F_30 ( T_3 * V_37 , T_5 * V_53 )
{
unsigned int V_54 = 0 ;
unsigned int V_55 = 0 ;
struct V_26 * V_56 ;
F_23 () ;
F_22 (e, &rnet->lrn_routes) {
V_54 ++ ;
}
V_55 = F_31 () % ( V_54 + 1 ) ;
F_22 (e, &rnet->lrn_routes) {
if ( ! V_55 )
break;
V_55 -- ;
}
F_14 ( & V_53 -> V_57 , V_56 ) ;
F_14 ( & V_53 -> V_58 , & V_53 -> V_59 -> V_32 ) ;
V_30 . V_60 ++ ;
F_10 ( V_53 -> V_59 ) ;
}
int
F_32 ( T_4 V_36 , T_4 V_61 , T_6 V_62 ,
unsigned int V_63 )
{
struct V_26 * V_56 ;
T_3 * V_37 ;
T_3 * V_64 ;
T_5 * V_53 ;
T_1 * V_1 ;
int V_65 ;
int V_66 ;
F_5 ( V_11 , L_4 ,
F_33 ( V_36 ) , V_61 , V_63 , F_6 ( V_62 ) ) ;
if ( V_62 == V_67 ||
F_25 ( F_26 ( V_62 ) ) == V_50 ||
V_36 == F_26 ( V_67 ) ||
F_25 ( V_36 ) == V_50 ||
F_26 ( V_62 ) == V_36 ||
( V_61 != V_68 && ( V_61 < 1 || V_61 > 255 ) ) )
return - V_69 ;
if ( F_34 ( V_36 ) )
return - V_70 ;
F_35 ( V_53 , sizeof( * V_53 ) ) ;
F_35 ( V_37 , sizeof( * V_37 ) ) ;
if ( ! V_53 || ! V_37 ) {
F_36 ( L_5 ,
F_33 ( V_36 ) , V_61 , F_6 ( V_62 ) ) ;
if ( V_53 )
F_37 ( V_53 , sizeof( * V_53 ) ) ;
if ( V_37 )
F_37 ( V_37 , sizeof( * V_37 ) ) ;
return - V_71 ;
}
F_38 ( & V_37 -> V_72 ) ;
V_37 -> V_42 = V_36 ;
V_53 -> V_73 = V_61 ;
V_53 -> V_74 = V_36 ;
V_53 -> V_75 = V_63 ;
F_9 ( V_76 ) ;
V_66 = F_39 ( & V_53 -> V_59 , V_62 , V_76 ) ;
if ( V_66 ) {
F_8 ( V_76 ) ;
F_37 ( V_53 , sizeof( * V_53 ) ) ;
F_37 ( V_37 , sizeof( * V_37 ) ) ;
if ( V_66 == - V_77 )
return V_66 ;
F_36 ( L_6 , V_66 ,
F_33 ( V_36 ) , V_61 ,
F_6 ( V_62 ) ) ;
return V_66 ;
}
F_11 ( ! V_30 . V_40 ) ;
V_64 = F_20 ( V_36 ) ;
if ( ! V_64 ) {
F_40 ( & V_37 -> V_41 , F_21 ( V_36 ) ) ;
V_64 = V_37 ;
}
V_65 = 1 ;
F_22 (e, &rnet2->lrn_routes) {
T_5 * V_78 = F_13 ( V_56 , T_5 , V_57 ) ;
if ( V_78 -> V_59 == V_53 -> V_59 ) {
V_65 = 0 ;
break;
}
F_11 ( V_78 -> V_59 -> V_19 != V_62 ) ;
}
if ( V_65 ) {
F_15 ( V_53 -> V_59 ) ;
F_30 ( V_64 , V_53 ) ;
V_1 = V_53 -> V_59 -> V_79 ;
F_8 ( V_76 ) ;
if ( V_1 -> V_21 -> V_22 )
V_1 -> V_21 -> V_22 ( V_1 , V_62 , 1 ) ;
F_9 ( V_76 ) ;
}
F_19 ( V_53 -> V_59 ) ;
F_8 ( V_76 ) ;
V_66 = 0 ;
if ( ! V_65 ) {
V_66 = - V_70 ;
F_37 ( V_53 , sizeof( * V_53 ) ) ;
}
if ( V_37 != V_64 )
F_37 ( V_37 , sizeof( * V_37 ) ) ;
F_41 ( & V_30 . V_80 ) ;
return V_66 ;
}
int
F_42 ( void )
{
T_3 * V_37 ;
T_5 * V_53 ;
T_5 * V_78 ;
struct V_26 * V_81 ;
struct V_26 * V_82 ;
int V_83 ;
struct V_26 * V_39 ;
int V_84 ;
V_83 = F_43 () ;
for ( V_84 = 0 ; V_84 < V_85 ; V_84 ++ ) {
V_39 = & V_30 . V_86 [ V_84 ] ;
F_22 (e1, rn_list) {
V_37 = F_13 ( V_81 , T_3 , V_41 ) ;
V_78 = NULL ;
F_22 (e2, &rnet->lrn_routes) {
T_6 V_87 ;
T_6 V_88 ;
int V_36 ;
V_53 = F_13 ( V_82 , T_5 , V_57 ) ;
if ( ! V_78 ) {
V_78 = V_53 ;
continue;
}
if ( V_53 -> V_59 -> V_79 ==
V_78 -> V_59 -> V_79 )
continue;
V_87 = V_53 -> V_59 -> V_19 ;
V_88 = V_78 -> V_59 -> V_19 ;
V_36 = V_37 -> V_42 ;
F_8 ( V_83 ) ;
F_36 ( L_7 ,
F_33 ( V_36 ) ,
F_6 ( V_87 ) ,
F_6 ( V_88 ) ) ;
return - V_69 ;
}
}
}
F_8 ( V_83 ) ;
return 0 ;
}
int
F_44 ( T_4 V_36 , T_6 V_89 )
{
struct V_90 * V_62 ;
T_3 * V_37 ;
T_5 * V_53 ;
struct V_26 * V_81 ;
struct V_26 * V_82 ;
int V_66 = - V_91 ;
struct V_26 * V_39 ;
int V_92 = 0 ;
F_5 ( V_11 , L_8 ,
F_33 ( V_36 ) , F_6 ( V_89 ) ) ;
F_9 ( V_76 ) ;
if ( V_36 == F_26 ( V_67 ) )
V_39 = & V_30 . V_86 [ 0 ] ;
else
V_39 = F_21 ( V_36 ) ;
V_93:
F_22 (e1, rn_list) {
V_37 = F_13 ( V_81 , T_3 , V_41 ) ;
if ( ! ( V_36 == F_26 ( V_67 ) ||
V_36 == V_37 -> V_42 ) )
continue;
F_22 (e2, &rnet->lrn_routes) {
V_53 = F_13 ( V_82 , T_5 , V_57 ) ;
V_62 = V_53 -> V_59 ;
if ( ! ( V_89 == V_67 ||
V_89 == V_62 -> V_19 ) )
continue;
F_18 ( & V_53 -> V_57 ) ;
F_18 ( & V_53 -> V_58 ) ;
V_30 . V_60 ++ ;
if ( F_17 ( & V_37 -> V_72 ) )
F_18 ( & V_37 -> V_41 ) ;
else
V_37 = NULL ;
F_16 ( V_62 ) ;
F_19 ( V_62 ) ;
F_8 ( V_76 ) ;
F_37 ( V_53 , sizeof( * V_53 ) ) ;
if ( V_37 )
F_37 ( V_37 , sizeof( * V_37 ) ) ;
V_66 = 0 ;
F_9 ( V_76 ) ;
goto V_93;
}
}
if ( V_36 == F_26 ( V_67 ) &&
++ V_92 < V_85 ) {
V_39 = & V_30 . V_86 [ V_92 ] ;
goto V_93;
}
F_8 ( V_76 ) ;
return V_66 ;
}
void
F_45 ( void )
{
F_44 ( F_26 ( V_67 ) , V_67 ) ;
}
int F_46 ( int V_92 , struct V_94 * V_95 )
{
int V_84 , V_66 = - V_91 , V_96 ;
if ( ! V_30 . V_97 )
return V_66 ;
for ( V_84 = 0 ; V_84 < V_98 ; V_84 ++ ) {
T_7 * V_99 ;
F_9 ( V_76 ) ;
F_47 (rbp, j, the_lnet.ln_rtrpools) {
if ( V_84 ++ != V_92 )
continue;
V_95 -> V_100 [ V_84 ] . V_101 = V_99 [ V_84 ] . V_102 ;
V_95 -> V_100 [ V_84 ] . V_103 = V_99 [ V_84 ] . V_104 ;
V_95 -> V_100 [ V_84 ] . V_105 = V_99 [ V_84 ] . V_106 ;
V_95 -> V_100 [ V_84 ] . V_107 = V_99 [ V_84 ] . V_108 ;
V_66 = 0 ;
break;
}
F_8 ( V_76 ) ;
}
F_9 ( V_76 ) ;
V_95 -> V_109 = V_30 . V_110 ;
F_8 ( V_76 ) ;
return V_66 ;
}
int
F_48 ( int V_92 , T_4 * V_36 , T_4 * V_61 ,
T_6 * V_62 , T_4 * V_8 , T_4 * V_63 )
{
struct V_26 * V_81 ;
struct V_26 * V_82 ;
T_3 * V_37 ;
T_5 * V_53 ;
int V_83 ;
int V_84 ;
struct V_26 * V_39 ;
V_83 = F_43 () ;
for ( V_84 = 0 ; V_84 < V_85 ; V_84 ++ ) {
V_39 = & V_30 . V_86 [ V_84 ] ;
F_22 (e1, rn_list) {
V_37 = F_13 ( V_81 , T_3 , V_41 ) ;
F_22 (e2, &rnet->lrn_routes) {
V_53 = F_13 ( V_82 , T_5 , V_57 ) ;
if ( ! V_92 -- ) {
* V_36 = V_37 -> V_42 ;
* V_61 = V_53 -> V_73 ;
* V_63 = V_53 -> V_75 ;
* V_62 = V_53 -> V_59 -> V_19 ;
* V_8 = F_49 ( V_53 ) ;
F_8 ( V_83 ) ;
return 0 ;
}
}
}
}
F_8 ( V_83 ) ;
return - V_91 ;
}
void
F_50 ( T_8 * V_111 )
{
int V_84 ;
T_9 * V_112 ;
F_51 ( & V_111 -> V_113 ) ;
F_51 ( & V_111 -> V_114 ) ;
F_51 ( & V_111 -> V_115 ) ;
F_51 ( & V_111 -> V_116 ) ;
for ( V_84 = 0 ; V_84 < V_111 -> V_116 && V_84 < V_117 ; V_84 ++ ) {
V_112 = & V_111 -> V_118 [ V_84 ] ;
F_52 ( & V_112 -> V_119 ) ;
F_51 ( & V_112 -> V_120 ) ;
}
}
static void
F_53 ( T_10 * V_121 )
{
T_8 * V_111 = V_121 -> V_122 ;
struct V_90 * V_123 = V_121 -> V_124 ;
T_5 * V_125 ;
if ( ! V_123 -> V_14 )
return;
if ( V_111 -> V_113 == F_54 ( V_126 ) )
F_50 ( V_111 ) ;
if ( V_111 -> V_113 != V_126 ) {
F_5 ( V_11 , L_9 ,
F_6 ( V_123 -> V_19 ) , V_111 -> V_113 ) ;
V_123 -> V_17 = V_18 ;
return;
}
V_123 -> V_17 = V_111 -> V_114 ;
if ( ! ( V_123 -> V_17 & V_127 ) ) {
F_5 ( V_11 , L_10 ,
F_6 ( V_123 -> V_19 ) , V_123 -> V_17 ) ;
return;
}
if ( ! ( V_123 -> V_17 & V_128 ) )
return;
F_55 (rte, &gw->lp_routes, lr_gwlist) {
int V_129 = 0 ;
int V_130 = 0 ;
int V_84 ;
if ( V_123 -> V_17 & V_131 ) {
V_125 -> V_132 = 1 ;
continue;
}
for ( V_84 = 0 ; V_84 < V_111 -> V_116 && V_84 < V_117 ; V_84 ++ ) {
T_9 * V_112 = & V_111 -> V_118 [ V_84 ] ;
T_6 V_133 = V_112 -> V_119 ;
if ( V_133 == V_67 ) {
F_5 ( V_11 , L_11 ,
F_6 ( V_123 -> V_19 ) ) ;
V_123 -> V_17 = V_18 ;
return;
}
if ( F_25 ( F_26 ( V_133 ) ) == V_50 )
continue;
if ( V_112 -> V_120 == V_134 ) {
V_129 ++ ;
continue;
}
if ( V_112 -> V_120 == V_135 ) {
if ( F_26 ( V_133 ) == V_125 -> V_74 ) {
V_130 = 1 ;
break;
}
continue;
}
F_5 ( V_11 , L_12 ,
F_6 ( V_123 -> V_19 ) , V_112 -> V_120 ) ;
V_123 -> V_17 = V_18 ;
return;
}
if ( V_130 ) {
V_125 -> V_132 = 0 ;
continue;
}
if ( ! V_129 && V_125 -> V_73 == 1 )
V_129 = 1 ;
V_125 -> V_132 = V_129 ;
}
}
static void
F_56 ( T_11 * V_136 )
{
T_10 * V_121 = V_136 -> V_137 . V_138 ;
struct V_90 * V_6 ;
F_11 ( V_121 ) ;
if ( V_136 -> V_139 ) {
F_57 ( & V_121 -> V_140 ) ;
return;
}
F_11 ( V_136 -> type == V_141 ||
V_136 -> type == V_142 ) ;
V_6 = V_121 -> V_124 ;
F_11 ( V_6 ) ;
F_9 ( V_6 -> V_23 ) ;
if ( ! F_58 ( V_6 ) || V_6 -> V_33 != V_121 ) {
goto V_143;
}
if ( V_136 -> type == V_141 ) {
V_6 -> V_144 = 0 ;
if ( ! V_136 -> V_145 )
goto V_143;
}
F_3 ( V_6 , 1 , ! V_136 -> V_145 , F_59 () ) ;
if ( V_146 && ! V_136 -> V_145 )
F_53 ( V_121 ) ;
V_143:
F_8 ( V_6 -> V_23 ) ;
}
static void
F_60 ( void )
{
T_2 * V_28 ;
struct V_26 * V_147 ;
int V_148 ;
F_11 ( V_30 . V_149 == V_150 ) ;
for (; ; ) {
int V_83 = F_43 () ;
V_148 = 1 ;
F_22 (entry, &the_lnet.ln_routers) {
V_28 = F_13 ( V_147 , T_2 , V_29 ) ;
if ( ! V_28 -> V_13 ) {
V_148 = 0 ;
break;
}
}
F_8 ( V_83 ) ;
if ( V_148 )
return;
F_61 ( V_151 ) ;
F_62 ( F_63 ( 1 ) ) ;
}
}
void
F_64 ( T_2 * V_123 , T_4 V_36 )
{
T_5 * V_125 ;
if ( ( V_123 -> V_17 & V_128 ) ) {
F_55 (rte, &gw->lp_routes, lr_gwlist) {
if ( V_125 -> V_74 == V_36 ) {
V_125 -> V_132 = 0 ;
break;
}
}
}
}
static void
F_65 ( void )
{
T_1 * V_1 ;
T_12 V_152 ;
int V_153 ;
F_11 ( V_30 . V_110 ) ;
V_153 = V_154 +
F_66 ( V_155 , V_156 ) ;
V_152 = F_67 () ;
F_55 (ni, &the_lnet.ln_nis, ni_list) {
if ( V_1 -> V_21 -> V_44 == V_50 )
continue;
if ( V_152 < V_1 -> V_157 + V_153 )
continue;
F_68 ( V_1 ) ;
if ( V_152 < V_1 -> V_157 + V_153 ) {
F_69 ( V_1 ) ;
continue;
}
F_11 ( V_1 -> V_158 ) ;
if ( V_1 -> V_158 -> V_120 != V_134 ) {
F_5 ( V_11 , L_13 ,
F_6 ( V_1 -> V_49 ) , V_153 ) ;
V_1 -> V_158 -> V_120 = V_134 ;
}
F_69 ( V_1 ) ;
}
}
static void
F_70 ( T_10 * V_121 )
{
F_11 ( F_17 ( & V_121 -> V_34 ) ) ;
F_11 ( F_71 ( V_121 -> V_140 ) ) ;
if ( V_121 -> V_124 ) {
int V_83 = V_121 -> V_124 -> V_23 ;
F_9 ( V_83 ) ;
F_19 ( V_121 -> V_124 ) ;
F_8 ( V_83 ) ;
}
if ( V_121 -> V_122 )
F_37 ( V_121 -> V_122 , V_159 ) ;
F_37 ( V_121 , sizeof( * V_121 ) ) ;
}
static T_10 *
F_72 ( T_2 * V_62 )
{
T_10 * V_121 = NULL ;
T_8 * V_160 ;
int V_66 ;
int V_84 ;
F_8 ( V_62 -> V_23 ) ;
F_35 ( V_121 , sizeof( * V_121 ) ) ;
if ( ! V_121 )
goto V_143;
F_57 ( & V_121 -> V_140 ) ;
F_38 ( & V_121 -> V_34 ) ;
F_35 ( V_160 , V_159 ) ;
if ( ! V_160 )
goto V_143;
for ( V_84 = 0 ; V_84 < V_117 ; V_84 ++ ) {
V_160 -> V_118 [ V_84 ] . V_119 = V_67 ;
V_160 -> V_118 [ V_84 ] . V_120 = V_161 ;
}
V_121 -> V_122 = V_160 ;
F_11 ( ! F_71 ( V_30 . V_162 ) ) ;
V_66 = F_73 ((lnet_md_t){.start = pi,
.user_ptr = rcd,
.length = LNET_PINGINFO_SIZE,
.threshold = LNET_MD_THRESH_INF,
.options = LNET_MD_TRUNCATE,
.eq_handle = the_lnet.ln_rc_eqh},
LNET_UNLINK,
&rcd->rcd_mdh) ;
if ( V_66 < 0 ) {
F_36 ( L_14 , V_66 ) ;
goto V_143;
}
F_11 ( ! V_66 ) ;
F_9 ( V_62 -> V_23 ) ;
if ( ! F_58 ( V_62 ) || V_62 -> V_33 ) {
F_8 ( V_62 -> V_23 ) ;
goto V_143;
}
F_15 ( V_62 ) ;
V_121 -> V_124 = V_62 ;
V_62 -> V_33 = V_121 ;
V_62 -> V_144 = 0 ;
return V_121 ;
V_143:
if ( V_121 ) {
if ( ! F_71 ( V_121 -> V_140 ) ) {
V_66 = F_74 ( V_121 -> V_140 ) ;
F_11 ( ! V_66 ) ;
}
F_70 ( V_121 ) ;
}
F_9 ( V_62 -> V_23 ) ;
return V_62 -> V_33 ;
}
static int
F_75 ( T_2 * V_28 )
{
int V_163 ;
V_163 = V_28 -> V_14 ? V_155 :
V_156 ;
if ( V_163 < 0 )
V_163 = 0 ;
return V_163 ;
}
static void
F_76 ( T_2 * V_28 )
{
T_10 * V_121 = NULL ;
unsigned long V_152 = F_59 () ;
int V_163 ;
F_15 ( V_28 ) ;
if ( V_28 -> V_12 &&
F_77 ( V_152 , V_28 -> V_12 ) )
F_3 ( V_28 , 1 , 0 , V_152 ) ;
F_7 ( V_28 -> V_79 , V_28 ) ;
if ( ! F_58 ( V_28 ) ||
V_30 . V_149 != V_150 ) {
F_19 ( V_28 ) ;
return;
}
V_121 = V_28 -> V_33 ?
V_28 -> V_33 : F_72 ( V_28 ) ;
if ( ! V_121 )
return;
V_163 = F_75 ( V_28 ) ;
F_5 ( V_11 ,
L_15 ,
F_6 ( V_28 -> V_19 ) , V_163 ,
V_28 -> V_12 , V_28 -> V_144 ,
V_28 -> V_14 , V_28 -> V_13 , V_28 -> V_164 ) ;
if ( V_163 && ! V_28 -> V_144 &&
F_77 ( V_152 , F_78 ( V_28 -> V_164 ,
F_63 ( V_163 ) ) ) ) {
int V_66 ;
T_13 V_165 ;
T_14 V_166 ;
V_165 . V_133 = V_28 -> V_19 ;
V_165 . V_167 = V_168 ;
F_5 ( V_11 , L_16 , F_79 ( V_165 ) ) ;
V_28 -> V_144 = 1 ;
V_28 -> V_164 = V_152 ;
V_166 = V_121 -> V_140 ;
if ( ! V_28 -> V_12 ) {
V_28 -> V_12 =
F_80 ( V_154 ) ;
}
F_8 ( V_28 -> V_23 ) ;
V_66 = F_81 ( V_67 , V_166 , V_165 , V_169 ,
V_170 , 0 ) ;
F_9 ( V_28 -> V_23 ) ;
if ( V_66 )
V_28 -> V_144 = 0 ;
}
F_19 ( V_28 ) ;
}
int
F_82 ( void )
{
struct V_171 * V_172 ;
int V_66 ;
int V_173 = 0 ;
F_11 ( V_30 . V_149 == V_174 ) ;
if ( V_5 &&
V_156 <= 0 ) {
F_83 ( 0x10a , L_17 ) ;
return - V_69 ;
}
F_84 ( & V_30 . V_175 ) ;
V_66 = F_85 ( 0 , F_56 , & V_30 . V_162 ) ;
if ( V_66 ) {
F_36 ( L_18 , V_173 , V_66 ) ;
return - V_71 ;
}
V_30 . V_149 = V_150 ;
V_172 = F_86 ( V_176 , NULL , L_19 ) ;
if ( F_87 ( V_172 ) ) {
V_66 = F_88 ( V_172 ) ;
F_36 ( L_20 , V_66 ) ;
F_89 ( & V_30 . V_175 ) ;
V_66 = F_90 ( V_30 . V_162 ) ;
F_11 ( ! V_66 ) ;
V_30 . V_149 = V_174 ;
return - V_71 ;
}
if ( V_5 ) {
F_60 () ;
}
return 0 ;
}
void
F_91 ( void )
{
int V_66 ;
if ( V_30 . V_149 == V_174 )
return;
F_11 ( V_30 . V_149 == V_150 ) ;
V_30 . V_149 = V_177 ;
F_41 ( & V_30 . V_80 ) ;
F_89 ( & V_30 . V_175 ) ;
F_11 ( V_30 . V_149 == V_174 ) ;
V_66 = F_90 ( V_30 . V_162 ) ;
F_11 ( ! V_66 ) ;
}
static void
F_92 ( int V_178 )
{
T_10 * V_121 ;
T_10 * V_38 ;
T_2 * V_6 ;
struct V_26 V_179 ;
int V_84 = 2 ;
if ( F_93 ( V_30 . V_149 == V_150 &&
F_17 ( & V_30 . V_35 ) &&
F_17 ( & V_30 . V_180 ) ) )
return;
F_38 ( & V_179 ) ;
F_9 ( V_76 ) ;
if ( V_30 . V_149 != V_150 ) {
F_55 (lp, &the_lnet.ln_routers,
lp_rtr_list) {
if ( ! V_6 -> V_33 )
continue;
F_11 ( F_17 ( & V_6 -> V_33 -> V_34 ) ) ;
F_14 ( & V_6 -> V_33 -> V_34 ,
& V_30 . V_35 ) ;
V_6 -> V_33 = NULL ;
}
}
F_94 ( & V_30 . V_35 , & V_179 ) ;
if ( ! F_17 ( & V_179 ) ) {
F_8 ( V_76 ) ;
F_55 (rcd, &head, rcd_list)
F_74 ( V_121 -> V_140 ) ;
F_9 ( V_76 ) ;
}
F_94 ( & V_179 , & V_30 . V_180 ) ;
while ( ! F_17 ( & V_30 . V_180 ) ) {
F_95 (rcd, tmp, &the_lnet.ln_rcd_zombie,
rcd_list) {
if ( F_71 ( V_121 -> V_140 ) )
F_96 ( & V_121 -> V_34 , & V_179 ) ;
}
V_178 = V_178 &&
! F_17 ( & V_30 . V_180 ) ;
F_8 ( V_76 ) ;
while ( ! F_17 ( & V_179 ) ) {
V_121 = F_13 ( V_179 . V_181 ,
T_10 , V_34 ) ;
F_97 ( & V_121 -> V_34 ) ;
F_70 ( V_121 ) ;
}
if ( ! V_178 )
return;
V_84 ++ ;
F_5 ( ( ( V_84 & ( - V_84 ) ) == V_84 ) ? V_182 : V_11 ,
L_21 ) ;
F_61 ( V_151 ) ;
F_62 ( F_63 ( 1 ) / 4 ) ;
F_9 ( V_76 ) ;
}
F_8 ( V_76 ) ;
}
static inline bool
F_98 ( void )
{
if ( V_30 . V_149 != V_150 )
return true ;
if ( V_30 . V_110 )
return true ;
return ! F_17 ( & V_30 . V_183 ) &&
( V_155 > 0 ||
V_156 > 0 ) ;
}
static int
V_176 ( void * V_184 )
{
T_2 * V_28 ;
struct V_26 * V_147 ;
F_99 () ;
while ( V_30 . V_149 == V_150 ) {
T_15 V_185 ;
int V_83 ;
int V_186 ;
V_83 = F_43 () ;
V_187:
V_185 = V_30 . V_31 ;
F_22 (entry, &the_lnet.ln_routers) {
V_28 = F_13 ( V_147 , T_2 , V_29 ) ;
V_186 = F_100 ( V_28 -> V_19 ) ;
if ( V_83 != V_186 ) {
F_8 ( V_83 ) ;
V_83 = V_186 ;
F_9 ( V_83 ) ;
if ( V_185 != V_30 . V_31 )
goto V_187;
}
F_76 ( V_28 ) ;
if ( V_185 != V_30 . V_31 ) {
goto V_187;
}
}
if ( V_30 . V_110 )
F_65 () ;
F_8 ( V_83 ) ;
F_92 ( 0 ) ;
if ( ! F_98 () )
F_101 ( V_30 . V_80 ,
F_98 () ) ;
else
F_102 ( V_30 . V_80 ,
false ,
F_63 ( 1 ) ) ;
}
F_92 ( 1 ) ;
V_30 . V_149 = V_174 ;
F_103 ( & V_30 . V_175 ) ;
return 0 ;
}
void
F_104 ( T_16 * V_188 , int V_189 )
{
int V_190 = F_105 ( T_16 , V_191 [ V_189 ] ) ;
while ( -- V_189 >= 0 )
F_106 ( V_188 -> V_191 [ V_189 ] . V_192 ) ;
F_37 ( V_188 , V_190 ) ;
}
static T_16 *
F_107 ( T_7 * V_99 , int V_83 )
{
int V_189 = V_99 -> V_102 ;
int V_190 = F_105 ( T_16 , V_191 [ V_189 ] ) ;
struct V_193 * V_193 ;
T_16 * V_188 ;
int V_84 ;
F_108 ( V_188 , F_109 () , V_83 , V_190 ) ;
if ( ! V_188 )
return NULL ;
V_188 -> V_194 = V_99 ;
for ( V_84 = 0 ; V_84 < V_189 ; V_84 ++ ) {
V_193 = F_110 (
F_111 ( F_109 () , V_83 ) ,
V_195 | V_196 , 0 ) ;
if ( ! V_193 ) {
while ( -- V_84 >= 0 )
F_106 ( V_188 -> V_191 [ V_84 ] . V_192 ) ;
F_37 ( V_188 , V_190 ) ;
return NULL ;
}
V_188 -> V_191 [ V_84 ] . V_197 = V_198 ;
V_188 -> V_191 [ V_84 ] . V_199 = 0 ;
V_188 -> V_191 [ V_84 ] . V_192 = V_193 ;
}
return V_188 ;
}
static void
F_112 ( T_7 * V_99 , int V_83 )
{
int V_189 = V_99 -> V_102 ;
struct V_26 V_38 ;
T_16 * V_188 ;
T_16 * V_200 ;
if ( ! V_99 -> V_104 )
return;
F_38 ( & V_38 ) ;
F_9 ( V_83 ) ;
F_113 ( & V_99 -> V_201 , V_83 ) ;
F_94 ( & V_99 -> V_202 , & V_38 ) ;
V_99 -> V_203 = 0 ;
V_99 -> V_104 = 0 ;
V_99 -> V_106 = 0 ;
V_99 -> V_108 = 0 ;
F_8 ( V_83 ) ;
F_95 (rb, temp, &tmp, rb_list) {
F_18 ( & V_188 -> V_204 ) ;
F_104 ( V_188 , V_189 ) ;
}
}
static int
F_114 ( T_7 * V_99 , int V_205 , int V_83 )
{
struct V_26 V_204 ;
T_16 * V_188 ;
int V_206 ;
int V_207 = 0 ;
int V_208 ;
int V_189 = V_99 -> V_102 ;
F_9 ( V_83 ) ;
V_206 = V_205 - V_99 -> V_104 ;
if ( V_205 <= V_99 -> V_203 || V_206 <= 0 ) {
V_99 -> V_203 = V_205 ;
F_8 ( V_83 ) ;
return 0 ;
}
V_208 = V_99 -> V_203 ;
V_99 -> V_203 = V_205 ;
F_8 ( V_83 ) ;
F_38 ( & V_204 ) ;
while ( V_206 -- > 0 ) {
V_188 = F_107 ( V_99 , V_83 ) ;
if ( ! V_188 ) {
F_36 ( L_22 ,
V_205 , V_189 ) ;
F_9 ( V_83 ) ;
V_99 -> V_203 = V_208 ;
F_8 ( V_83 ) ;
goto V_209;
}
F_14 ( & V_188 -> V_204 , & V_204 ) ;
V_207 ++ ;
}
F_9 ( V_83 ) ;
F_115 ( & V_204 , & V_99 -> V_202 ) ;
V_99 -> V_104 += V_207 ;
V_99 -> V_106 += V_207 ;
V_99 -> V_108 = V_99 -> V_106 ;
while ( ! F_17 ( & V_99 -> V_202 ) &&
! F_17 ( & V_99 -> V_201 ) )
F_116 ( V_99 ) ;
F_8 ( V_83 ) ;
return 0 ;
V_209:
while ( ! F_17 ( & V_204 ) ) {
V_188 = F_13 ( V_204 . V_181 , T_16 , V_204 ) ;
F_18 ( & V_188 -> V_204 ) ;
F_104 ( V_188 , V_189 ) ;
}
return - V_71 ;
}
static void
F_117 ( T_7 * V_99 , int V_189 )
{
F_38 ( & V_99 -> V_201 ) ;
F_38 ( & V_99 -> V_202 ) ;
V_99 -> V_102 = V_189 ;
V_99 -> V_106 = 0 ;
V_99 -> V_108 = 0 ;
}
void
F_118 ( int V_210 )
{
T_7 * V_211 ;
int V_84 ;
if ( ! V_30 . V_97 )
return;
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
F_112 ( & V_211 [ V_212 ] , V_84 ) ;
F_112 ( & V_211 [ V_213 ] , V_84 ) ;
F_112 ( & V_211 [ V_214 ] , V_84 ) ;
}
if ( ! V_210 ) {
F_119 ( V_30 . V_97 ) ;
V_30 . V_97 = NULL ;
}
}
static int
F_120 ( void )
{
int V_215 = V_216 ;
if ( V_217 < 0 ) {
F_83 ( 0x10c ,
L_23 ,
V_217 ) ;
return - V_69 ;
}
if ( V_217 > 0 )
V_215 = V_217 ;
V_215 /= V_218 ;
return F_66 ( V_215 , V_219 ) ;
}
static int
F_121 ( void )
{
int V_215 = V_220 ;
if ( V_221 < 0 ) {
F_83 ( 0x10c ,
L_24 ,
V_221 ) ;
return - V_69 ;
}
if ( V_221 > 0 )
V_215 = V_221 ;
V_215 /= V_218 ;
return F_66 ( V_215 , V_222 ) ;
}
static int
F_122 ( void )
{
int V_215 = V_223 ;
if ( V_224 < 0 ) {
F_83 ( 0x10c ,
L_25 ,
V_224 ) ;
return - V_69 ;
}
if ( V_224 > 0 )
V_215 = V_224 ;
V_215 /= V_218 ;
return F_66 ( V_215 , V_225 ) ;
}
int
F_123 ( int V_226 )
{
T_7 * V_211 ;
int V_227 ;
int V_228 ;
int V_229 ;
int V_66 ;
int V_84 ;
if ( ! strcmp ( V_230 , L_26 ) ) {
if ( ! V_226 )
return 0 ;
} else if ( ! strcmp ( V_230 , L_27 ) ) {
return 0 ;
} else if ( ! strcmp ( V_230 , L_28 ) ) {
} else {
F_83 ( 0x10b , L_29 ) ;
return - V_69 ;
}
V_227 = F_120 () ;
if ( V_227 < 0 )
return - V_69 ;
V_228 = F_121 () ;
if ( V_228 < 0 )
return - V_69 ;
V_229 = F_122 () ;
if ( V_229 < 0 )
return - V_69 ;
V_30 . V_97 = F_124 ( F_109 () ,
V_98 *
sizeof( T_7 ) ) ;
if ( ! V_30 . V_97 ) {
F_83 ( 0x10c ,
L_30 ) ;
return - V_71 ;
}
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
F_117 ( & V_211 [ V_212 ] , 0 ) ;
V_66 = F_114 ( & V_211 [ V_212 ] ,
V_227 , V_84 ) ;
if ( V_66 )
goto V_209;
F_117 ( & V_211 [ V_213 ] ,
V_231 ) ;
V_66 = F_114 ( & V_211 [ V_213 ] ,
V_228 , V_84 ) ;
if ( V_66 )
goto V_209;
F_117 ( & V_211 [ V_214 ] ,
V_232 ) ;
V_66 = F_114 ( & V_211 [ V_214 ] ,
V_229 , V_84 ) ;
if ( V_66 )
goto V_209;
}
F_9 ( V_76 ) ;
V_30 . V_110 = 1 ;
F_8 ( V_76 ) ;
return 0 ;
V_209:
F_118 ( 0 ) ;
return V_66 ;
}
static int
F_125 ( int V_233 , int V_234 , int V_235 )
{
int V_236 = 0 ;
int V_66 = 0 ;
int V_84 ;
T_7 * V_211 ;
if ( V_233 >= 0 ) {
V_217 = V_233 ;
V_236 = F_120 () ;
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
V_66 = F_114 ( & V_211 [ V_212 ] ,
V_236 , V_84 ) ;
if ( V_66 )
return V_66 ;
}
}
if ( V_234 >= 0 ) {
V_221 = V_234 ;
V_236 = F_121 () ;
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
V_66 = F_114 ( & V_211 [ V_213 ] ,
V_236 , V_84 ) ;
if ( V_66 )
return V_66 ;
}
}
if ( V_235 >= 0 ) {
V_224 = V_235 ;
V_236 = F_122 () ;
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
V_66 = F_114 ( & V_211 [ V_214 ] ,
V_236 , V_84 ) ;
if ( V_66 )
return V_66 ;
}
}
return 0 ;
}
int
F_126 ( int V_233 , int V_234 , int V_235 )
{
if ( ! V_30 . V_110 )
return 0 ;
return F_125 ( V_233 , V_234 , V_235 ) ;
}
int
F_127 ( void )
{
int V_66 = 0 ;
if ( V_30 . V_110 )
return 0 ;
if ( ! V_30 . V_97 )
V_66 = F_123 ( 1 ) ;
else
V_66 = F_125 ( 0 , 0 , 0 ) ;
if ( V_66 )
return V_66 ;
F_9 ( V_76 ) ;
V_30 . V_110 = 1 ;
V_30 . V_237 -> V_114 &= ~ V_131 ;
F_8 ( V_76 ) ;
return V_66 ;
}
void
F_128 ( void )
{
if ( ! V_30 . V_110 )
return;
F_9 ( V_76 ) ;
V_30 . V_110 = 0 ;
V_30 . V_237 -> V_114 |= V_131 ;
V_217 = 0 ;
V_221 = 0 ;
V_224 = 0 ;
F_8 ( V_76 ) ;
F_118 ( 1 ) ;
}
int
F_129 ( T_1 * V_1 , T_6 V_133 , int V_8 , unsigned long V_9 )
{
struct V_90 * V_6 = NULL ;
unsigned long V_152 = F_59 () ;
int V_83 = F_130 ( V_133 ) ;
F_11 ( ! F_131 () ) ;
F_5 ( V_11 , L_31 ,
! V_1 ? L_32 : F_6 ( V_1 -> V_49 ) ,
F_6 ( V_133 ) ,
V_8 ? L_33 : L_34 ) ;
if ( V_1 &&
F_26 ( V_1 -> V_49 ) != F_26 ( V_133 ) ) {
F_132 ( L_35 ,
F_6 ( V_133 ) , V_8 ? L_36 : L_37 ,
F_6 ( V_1 -> V_49 ) ) ;
return - V_69 ;
}
if ( F_77 ( V_9 , V_152 ) ) {
F_132 ( L_38 ,
! V_1 ? L_32 : F_6 ( V_1 -> V_49 ) ,
F_6 ( V_133 ) , V_8 ? L_33 : L_34 ,
F_133 ( F_134 ( V_9 , V_152 ) ) ) ;
return - V_69 ;
}
if ( V_1 && ! V_8 &&
! V_238 ) {
F_5 ( V_11 , L_39 ) ;
return 0 ;
}
F_9 ( V_83 ) ;
if ( V_30 . V_40 ) {
F_8 ( V_83 ) ;
return - V_239 ;
}
V_6 = F_135 ( V_30 . V_240 [ V_83 ] , V_133 ) ;
if ( ! V_6 ) {
F_8 ( V_83 ) ;
F_5 ( V_11 , L_40 , F_6 ( V_133 ) ) ;
return 0 ;
}
if ( V_1 && ! V_8 && V_9 < V_6 -> V_241 )
V_9 = V_6 -> V_241 ;
F_3 ( V_6 , ! V_1 , V_8 , V_9 ) ;
if ( V_1 )
F_7 ( V_1 , V_6 ) ;
F_19 ( V_6 ) ;
F_8 ( V_83 ) ;
return 0 ;
}
