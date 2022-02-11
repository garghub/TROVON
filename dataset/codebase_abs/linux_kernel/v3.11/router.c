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
F_1 ( T_1 * V_1 )
{
return 0 ;
}
int
F_2 ( void )
{
return V_5 ;
}
void
F_3 ( T_2 * V_6 , int V_7 , int V_8 , T_3 V_9 )
{
if ( F_4 ( V_9 , V_6 -> V_10 ) ) {
F_5 ( V_11 , L_1 ) ;
return;
}
V_6 -> V_10 = V_9 ;
V_6 -> V_12 = 0 ;
if ( V_6 -> V_13 != 0 &&
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
void
F_7 ( T_1 * V_1 , T_2 * V_6 )
{
int V_8 ;
int V_7 ;
if ( V_6 -> V_20 )
return;
V_6 -> V_20 = 1 ;
while ( V_6 -> V_15 ) {
V_8 = V_6 -> V_14 ;
V_7 = V_6 -> V_16 ;
V_6 -> V_16 = 0 ;
V_6 -> V_15 = 0 ;
if ( V_7 && V_1 -> V_21 -> V_22 != NULL ) {
F_8 ( V_6 -> V_23 ) ;
( V_1 -> V_21 -> V_22 ) ( V_1 , V_6 -> V_19 , V_8 ) ;
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
if ( V_6 -> V_25 == 0 ) {
F_11 ( F_17 ( & V_6 -> V_32 ) ) ;
if ( V_6 -> V_33 != NULL ) {
F_14 ( & V_6 -> V_33 -> V_34 ,
& V_30 . V_35 ) ;
V_6 -> V_33 = NULL ;
}
F_18 ( & V_6 -> V_29 ) ;
F_19 ( V_6 ) ;
V_30 . V_31 ++ ;
}
}
T_4 *
F_20 ( T_5 V_36 )
{
T_4 * V_37 ;
struct V_26 * V_38 ;
struct V_26 * V_39 ;
F_11 ( ! V_30 . V_40 ) ;
V_39 = F_21 ( V_36 ) ;
F_22 (tmp, rn_list) {
V_37 = F_13 ( V_38 , T_4 , V_41 ) ;
if ( V_37 -> V_42 == V_36 )
return V_37 ;
}
return NULL ;
}
static void F_23 ( void )
{
static int V_43 = 0 ;
int V_44 , V_45 [ 2 ] ;
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
return;
}
void
F_30 ( T_4 * V_37 , T_6 * V_53 )
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
if ( V_55 == 0 )
break;
V_55 -- ;
}
F_14 ( & V_53 -> V_57 , V_56 ) ;
F_14 ( & V_53 -> V_58 , & V_53 -> V_59 -> V_32 ) ;
V_30 . V_60 ++ ;
F_10 ( V_53 -> V_59 ) ;
}
int
F_32 ( T_5 V_36 , unsigned int V_61 , T_7 V_62 )
{
struct V_26 * V_56 ;
T_4 * V_37 ;
T_4 * V_63 ;
T_6 * V_53 ;
T_1 * V_1 ;
int V_64 ;
int V_65 ;
F_5 ( V_11 , L_4 ,
F_33 ( V_36 ) , V_61 , F_6 ( V_62 ) ) ;
if ( V_62 == V_66 ||
F_25 ( F_26 ( V_62 ) ) == V_50 ||
V_36 == F_26 ( V_66 ) ||
F_25 ( V_36 ) == V_50 ||
F_26 ( V_62 ) == V_36 ||
V_61 < 1 || V_61 > 255 )
return ( - V_67 ) ;
if ( F_34 ( V_36 ) )
return 0 ;
F_35 ( V_53 , sizeof( * V_53 ) ) ;
F_35 ( V_37 , sizeof( * V_37 ) ) ;
if ( V_53 == NULL || V_37 == NULL ) {
F_36 ( L_5 ,
F_33 ( V_36 ) , V_61 , F_6 ( V_62 ) ) ;
if ( V_53 != NULL )
F_37 ( V_53 , sizeof( * V_53 ) ) ;
if ( V_37 != NULL )
F_37 ( V_37 , sizeof( * V_37 ) ) ;
return - V_68 ;
}
F_38 ( & V_37 -> V_69 ) ;
V_37 -> V_42 = V_36 ;
V_53 -> V_70 = V_61 ;
V_53 -> V_71 = V_36 ;
F_9 ( V_72 ) ;
V_65 = F_39 ( & V_53 -> V_59 , V_62 , V_72 ) ;
if ( V_65 != 0 ) {
F_8 ( V_72 ) ;
F_37 ( V_53 , sizeof( * V_53 ) ) ;
F_37 ( V_37 , sizeof( * V_37 ) ) ;
if ( V_65 == - V_73 ) {
return 0 ;
} else {
F_36 ( L_6 , V_65 ,
F_33 ( V_36 ) , V_61 ,
F_6 ( V_62 ) ) ;
}
return V_65 ;
}
F_11 ( ! V_30 . V_40 ) ;
V_63 = F_20 ( V_36 ) ;
if ( V_63 == NULL ) {
F_40 ( & V_37 -> V_41 , F_21 ( V_36 ) ) ;
V_63 = V_37 ;
}
V_64 = 1 ;
F_22 (e, &rnet2->lrn_routes) {
T_6 * V_74 = F_13 ( V_56 , T_6 , V_57 ) ;
if ( V_74 -> V_59 == V_53 -> V_59 ) {
V_64 = 0 ;
break;
}
F_11 ( V_74 -> V_59 -> V_19 != V_62 ) ;
}
if ( V_64 ) {
F_15 ( V_53 -> V_59 ) ;
F_30 ( V_63 , V_53 ) ;
V_1 = V_53 -> V_59 -> V_75 ;
F_8 ( V_72 ) ;
if ( V_1 -> V_21 -> V_22 != NULL )
( V_1 -> V_21 -> V_22 ) ( V_1 , V_62 , 1 ) ;
F_9 ( V_72 ) ;
}
F_19 ( V_53 -> V_59 ) ;
F_8 ( V_72 ) ;
if ( ! V_64 )
F_37 ( V_53 , sizeof( * V_53 ) ) ;
if ( V_37 != V_63 )
F_37 ( V_37 , sizeof( * V_37 ) ) ;
return 0 ;
}
int
F_41 ( void )
{
T_4 * V_37 ;
T_6 * V_53 ;
T_6 * V_74 ;
struct V_26 * V_76 ;
struct V_26 * V_77 ;
int V_78 ;
struct V_26 * V_39 ;
int V_79 ;
V_78 = F_42 () ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
V_39 = & V_30 . V_81 [ V_79 ] ;
F_22 (e1, rn_list) {
V_37 = F_13 ( V_76 , T_4 , V_41 ) ;
V_74 = NULL ;
F_22 (e2, &rnet->lrn_routes) {
T_7 V_82 ;
T_7 V_83 ;
int V_36 ;
V_53 = F_13 ( V_77 , T_6 ,
V_57 ) ;
if ( V_74 == NULL ) {
V_74 = V_53 ;
continue;
}
if ( V_53 -> V_59 -> V_75 ==
V_74 -> V_59 -> V_75 )
continue;
V_82 = V_53 -> V_59 -> V_19 ;
V_83 = V_74 -> V_59 -> V_19 ;
V_36 = V_37 -> V_42 ;
F_8 ( V_78 ) ;
F_36 ( L_7
L_8 ,
F_33 ( V_36 ) ,
F_6 ( V_82 ) ,
F_6 ( V_83 ) ) ;
return - V_67 ;
}
}
}
F_8 ( V_78 ) ;
return 0 ;
}
int
F_43 ( T_5 V_36 , T_7 V_84 )
{
struct V_85 * V_62 ;
T_4 * V_37 ;
T_6 * V_53 ;
struct V_26 * V_76 ;
struct V_26 * V_77 ;
int V_65 = - V_86 ;
struct V_26 * V_39 ;
int V_87 = 0 ;
F_5 ( V_11 , L_9 ,
F_33 ( V_36 ) , F_6 ( V_84 ) ) ;
F_9 ( V_72 ) ;
if ( V_36 == F_26 ( V_66 ) )
V_39 = & V_30 . V_81 [ 0 ] ;
else
V_39 = F_21 ( V_36 ) ;
V_88:
F_22 (e1, rn_list) {
V_37 = F_13 ( V_76 , T_4 , V_41 ) ;
if ( ! ( V_36 == F_26 ( V_66 ) ||
V_36 == V_37 -> V_42 ) )
continue;
F_22 (e2, &rnet->lrn_routes) {
V_53 = F_13 ( V_77 , T_6 , V_57 ) ;
V_62 = V_53 -> V_59 ;
if ( ! ( V_84 == V_66 ||
V_84 == V_62 -> V_19 ) )
continue;
F_18 ( & V_53 -> V_57 ) ;
F_18 ( & V_53 -> V_58 ) ;
V_30 . V_60 ++ ;
if ( F_17 ( & V_37 -> V_69 ) )
F_18 ( & V_37 -> V_41 ) ;
else
V_37 = NULL ;
F_16 ( V_62 ) ;
F_19 ( V_62 ) ;
F_8 ( V_72 ) ;
F_37 ( V_53 , sizeof( * V_53 ) ) ;
if ( V_37 != NULL )
F_37 ( V_37 , sizeof( * V_37 ) ) ;
V_65 = 0 ;
F_9 ( V_72 ) ;
goto V_88;
}
}
if ( V_36 == F_26 ( V_66 ) &&
++ V_87 < V_80 ) {
V_39 = & V_30 . V_81 [ V_87 ] ;
goto V_88;
}
F_8 ( V_72 ) ;
return V_65 ;
}
void
F_44 ( void )
{
F_43 ( F_26 ( V_66 ) , V_66 ) ;
}
int
F_45 ( int V_87 , T_5 * V_36 , T_5 * V_61 ,
T_7 * V_62 , T_5 * V_8 )
{
struct V_26 * V_76 ;
struct V_26 * V_77 ;
T_4 * V_37 ;
T_6 * V_53 ;
int V_78 ;
int V_79 ;
struct V_26 * V_39 ;
V_78 = F_42 () ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
V_39 = & V_30 . V_81 [ V_79 ] ;
F_22 (e1, rn_list) {
V_37 = F_13 ( V_76 , T_4 , V_41 ) ;
F_22 (e2, &rnet->lrn_routes) {
V_53 = F_13 ( V_77 , T_6 ,
V_57 ) ;
if ( V_87 -- == 0 ) {
* V_36 = V_37 -> V_42 ;
* V_61 = V_53 -> V_70 ;
* V_62 = V_53 -> V_59 -> V_19 ;
* V_8 = V_53 -> V_59 -> V_14 ;
F_8 ( V_78 ) ;
return 0 ;
}
}
}
}
F_8 ( V_78 ) ;
return - V_86 ;
}
void
F_46 ( T_8 * V_89 )
{
int V_79 ;
T_9 * V_90 ;
F_47 ( & V_89 -> V_91 ) ;
F_47 ( & V_89 -> V_92 ) ;
F_47 ( & V_89 -> V_93 ) ;
F_47 ( & V_89 -> V_94 ) ;
for ( V_79 = 0 ; V_79 < V_89 -> V_94 && V_79 < V_95 ; V_79 ++ ) {
V_90 = & V_89 -> V_96 [ V_79 ] ;
F_48 ( & V_90 -> V_97 ) ;
F_47 ( & V_90 -> V_98 ) ;
}
return;
}
static void
F_49 ( T_10 * V_99 )
{
T_8 * V_89 = V_99 -> V_100 ;
struct V_85 * V_101 = V_99 -> V_102 ;
T_6 * V_28 ;
if ( ! V_101 -> V_14 )
return;
if ( V_89 -> V_91 == F_50 ( V_103 ) )
F_46 ( V_89 ) ;
if ( V_89 -> V_91 != V_103 ) {
F_5 ( V_11 , L_10 ,
F_6 ( V_101 -> V_19 ) , V_89 -> V_91 ) ;
V_101 -> V_17 = V_18 ;
return;
}
V_101 -> V_17 = V_89 -> V_92 ;
if ( ( V_101 -> V_17 & V_104 ) == 0 ) {
F_5 ( V_11 , L_11 ,
F_6 ( V_101 -> V_19 ) , V_101 -> V_17 ) ;
return;
}
if ( ( V_101 -> V_17 & V_105 ) == 0 )
return;
F_51 (rtr, &gw->lp_routes, lr_gwlist) {
int V_106 = V_107 ;
int V_108 = 0 ;
int V_109 = 0 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_89 -> V_94 && V_79 < V_95 ; V_79 ++ ) {
T_9 * V_90 = & V_89 -> V_96 [ V_79 ] ;
T_7 V_110 = V_90 -> V_97 ;
if ( V_110 == V_66 ) {
F_5 ( V_11 , L_12 ,
F_6 ( V_101 -> V_19 ) ) ;
V_101 -> V_17 = V_18 ;
return;
}
if ( F_25 ( F_26 ( V_110 ) ) == V_50 )
continue;
if ( V_90 -> V_98 == V_111 ) {
if ( F_25 ( F_26 ( V_110 ) ) != V_112 )
V_108 ++ ;
else if ( V_106 != V_113 )
V_106 = V_111 ;
continue;
}
if ( V_90 -> V_98 == V_113 ) {
if ( F_26 ( V_110 ) == V_28 -> V_71 ) {
V_109 = 1 ;
break;
}
if ( F_25 ( F_26 ( V_110 ) ) == V_112 )
V_106 = V_113 ;
continue;
}
F_5 ( V_11 , L_13 ,
F_6 ( V_101 -> V_19 ) , V_90 -> V_98 ) ;
V_101 -> V_17 = V_18 ;
return;
}
if ( V_109 ) {
V_28 -> V_114 = 0 ;
continue;
}
V_28 -> V_114 = V_108 + ( V_106 == V_111 ) ;
}
}
static void
F_52 ( T_11 * V_115 )
{
T_10 * V_99 = V_115 -> V_116 . V_117 ;
struct V_85 * V_6 ;
F_11 ( V_99 != NULL ) ;
if ( V_115 -> V_118 ) {
F_53 ( & V_99 -> V_119 ) ;
return;
}
F_11 ( V_115 -> type == V_120 ||
V_115 -> type == V_121 ) ;
V_6 = V_99 -> V_102 ;
F_11 ( V_6 != NULL ) ;
F_9 ( V_6 -> V_23 ) ;
if ( ! F_54 ( V_6 ) || V_6 -> V_33 != V_99 ) {
goto V_122;
}
if ( V_115 -> type == V_120 ) {
V_6 -> V_123 = 0 ;
if ( V_115 -> V_124 == 0 )
goto V_122;
}
F_3 ( V_6 , 1 , ( V_115 -> V_124 == 0 ) , F_55 () ) ;
if ( V_125 && V_115 -> V_124 == 0 )
F_49 ( V_99 ) ;
V_122:
F_8 ( V_6 -> V_23 ) ;
}
void
F_56 ( void )
{
T_2 * V_28 ;
struct V_26 * V_126 ;
int V_127 ;
F_11 ( V_30 . V_128 == V_129 ) ;
for (; ; ) {
int V_78 = F_42 () ;
V_127 = 1 ;
F_22 (entry, &the_lnet.ln_routers) {
V_28 = F_13 ( V_126 , T_2 , V_29 ) ;
if ( V_28 -> V_13 == 0 ) {
V_127 = 0 ;
break;
}
}
F_8 ( V_78 ) ;
if ( V_127 )
return;
F_57 ( F_58 ( 1 ) ) ;
}
}
void
F_59 ( void )
{
T_1 * V_1 ;
long V_130 ;
int V_131 ;
F_11 ( V_30 . V_132 ) ;
V_131 = V_133 +
F_60 ( V_134 , V_135 ) ;
V_130 = F_61 () ;
F_51 (ni, &the_lnet.ln_nis, ni_list) {
if ( V_1 -> V_21 -> V_44 == V_50 )
continue;
if ( V_130 < V_1 -> V_136 + V_131 )
continue;
F_62 ( V_1 ) ;
if ( V_130 < V_1 -> V_136 + V_131 ) {
F_63 ( V_1 ) ;
continue;
}
F_11 ( V_1 -> V_137 != NULL ) ;
if ( V_1 -> V_137 -> V_98 != V_111 ) {
F_5 ( V_11 , L_14 ,
F_6 ( V_1 -> V_49 ) , V_131 ) ;
V_1 -> V_137 -> V_98 = V_111 ;
}
F_63 ( V_1 ) ;
}
}
void
F_64 ( T_10 * V_99 )
{
F_11 ( F_17 ( & V_99 -> V_34 ) ) ;
F_11 ( F_65 ( V_99 -> V_119 ) ) ;
if ( V_99 -> V_102 != NULL ) {
int V_78 = V_99 -> V_102 -> V_23 ;
F_9 ( V_78 ) ;
F_19 ( V_99 -> V_102 ) ;
F_8 ( V_78 ) ;
}
if ( V_99 -> V_100 != NULL )
F_37 ( V_99 -> V_100 , V_138 ) ;
F_37 ( V_99 , sizeof( * V_99 ) ) ;
}
T_10 *
F_66 ( T_2 * V_62 )
{
T_10 * V_99 = NULL ;
T_8 * V_139 ;
int V_65 ;
int V_79 ;
F_8 ( V_62 -> V_23 ) ;
F_35 ( V_99 , sizeof( * V_99 ) ) ;
if ( V_99 == NULL )
goto V_122;
F_53 ( & V_99 -> V_119 ) ;
F_38 ( & V_99 -> V_34 ) ;
F_35 ( V_139 , V_138 ) ;
if ( V_139 == NULL )
goto V_122;
memset ( V_139 , 0 , V_138 ) ;
for ( V_79 = 0 ; V_79 < V_95 ; V_79 ++ ) {
V_139 -> V_96 [ V_79 ] . V_97 = V_66 ;
V_139 -> V_96 [ V_79 ] . V_98 = V_107 ;
}
V_99 -> V_100 = V_139 ;
F_11 ( ! F_65 ( V_30 . V_140 ) ) ;
V_65 = F_67 ((lnet_md_t){.start = pi,
.user_ptr = rcd,
.length = LNET_PINGINFO_SIZE,
.threshold = LNET_MD_THRESH_INF,
.options = LNET_MD_TRUNCATE,
.eq_handle = the_lnet.ln_rc_eqh},
LNET_UNLINK,
&rcd->rcd_mdh) ;
if ( V_65 < 0 ) {
F_36 ( L_15 , V_65 ) ;
goto V_122;
}
F_11 ( V_65 == 0 ) ;
F_9 ( V_62 -> V_23 ) ;
if ( ! F_54 ( V_62 ) || V_62 -> V_33 != NULL ) {
F_8 ( V_62 -> V_23 ) ;
goto V_122;
}
F_15 ( V_62 ) ;
V_99 -> V_102 = V_62 ;
V_62 -> V_33 = V_99 ;
V_62 -> V_123 = 0 ;
return V_99 ;
V_122:
if ( V_99 != NULL ) {
if ( ! F_65 ( V_99 -> V_119 ) ) {
V_65 = F_68 ( V_99 -> V_119 ) ;
F_11 ( V_65 == 0 ) ;
}
F_64 ( V_99 ) ;
}
F_9 ( V_62 -> V_23 ) ;
return V_62 -> V_33 ;
}
static int
F_69 ( T_2 * V_28 )
{
int V_141 ;
V_141 = V_28 -> V_14 ? V_134 :
V_135 ;
if ( V_141 < 0 )
V_141 = 0 ;
return V_141 ;
}
static void
F_70 ( T_2 * V_28 )
{
T_10 * V_99 = NULL ;
T_3 V_130 = F_55 () ;
int V_141 ;
F_15 ( V_28 ) ;
if ( V_28 -> V_12 != 0 &&
F_71 ( V_130 , V_28 -> V_12 ) )
F_3 ( V_28 , 1 , 0 , V_130 ) ;
F_7 ( V_28 -> V_75 , V_28 ) ;
if ( ! F_54 ( V_28 ) ||
V_30 . V_128 != V_129 ) {
F_19 ( V_28 ) ;
return;
}
V_99 = V_28 -> V_33 != NULL ?
V_28 -> V_33 : F_66 ( V_28 ) ;
if ( V_99 == NULL )
return;
V_141 = F_69 ( V_28 ) ;
F_5 ( V_11 ,
L_16
L_17 ,
F_6 ( V_28 -> V_19 ) , V_141 ,
V_28 -> V_12 , V_28 -> V_123 ,
V_28 -> V_14 , V_28 -> V_13 , V_28 -> V_142 ) ;
if ( V_141 != 0 && ! V_28 -> V_123 &&
F_71 ( V_130 , F_72 ( V_28 -> V_142 ,
F_58 ( V_141 ) ) ) ) {
int V_65 ;
T_12 V_143 ;
T_13 V_144 ;
V_143 . V_110 = V_28 -> V_19 ;
V_143 . V_145 = V_146 ;
F_5 ( V_11 , L_18 , F_73 ( V_143 ) ) ;
V_28 -> V_123 = 1 ;
V_28 -> V_142 = V_130 ;
V_144 = V_99 -> V_119 ;
if ( V_28 -> V_12 == 0 ) {
V_28 -> V_12 =
F_74 ( V_133 ) ;
}
F_8 ( V_28 -> V_23 ) ;
V_65 = F_75 ( V_66 , V_144 , V_143 , V_147 ,
V_148 , 0 ) ;
F_9 ( V_28 -> V_23 ) ;
if ( V_65 != 0 )
V_28 -> V_123 = 0 ;
}
F_19 ( V_28 ) ;
return;
}
int
F_76 ( void )
{
int V_65 ;
int V_149 ;
F_11 ( V_30 . V_128 == V_150 ) ;
if ( V_5 &&
V_135 <= 0 ) {
F_77 ( 0x10a , L_19
L_20
L_21 ) ;
return - V_67 ;
}
if ( ! V_30 . V_132 &&
V_134 <= 0 &&
V_135 <= 0 )
return 0 ;
F_78 ( & V_30 . V_151 , 0 ) ;
V_149 = 0 ;
V_65 = F_79 ( V_149 , F_52 ,
& V_30 . V_140 ) ;
if ( V_65 != 0 ) {
F_36 ( L_22 , V_149 , V_65 ) ;
return - V_68 ;
}
V_30 . V_128 = V_129 ;
V_65 = F_80 ( F_81 ( V_152 ,
NULL , L_23 ) ) ;
if ( F_82 ( V_65 ) ) {
F_36 ( L_24 , V_65 ) ;
V_108 ( & V_30 . V_151 ) ;
V_65 = F_83 ( V_30 . V_140 ) ;
F_11 ( V_65 == 0 ) ;
V_30 . V_128 = V_150 ;
return - V_68 ;
}
if ( V_5 ) {
F_56 () ;
}
return 0 ;
}
void
F_84 ( void )
{
int V_65 ;
if ( V_30 . V_128 == V_150 )
return;
F_11 ( V_30 . V_128 == V_129 ) ;
V_30 . V_128 = V_153 ;
V_108 ( & V_30 . V_151 ) ;
F_11 ( V_30 . V_128 == V_150 ) ;
V_65 = F_83 ( V_30 . V_140 ) ;
F_11 ( V_65 == 0 ) ;
return;
}
static void
F_85 ( int V_154 )
{
T_10 * V_99 ;
T_10 * V_38 ;
T_2 * V_6 ;
struct V_26 V_155 ;
int V_79 = 2 ;
if ( F_86 ( V_30 . V_128 == V_129 &&
F_17 ( & V_30 . V_35 ) &&
F_17 ( & V_30 . V_156 ) ) )
return;
F_38 ( & V_155 ) ;
F_9 ( V_72 ) ;
if ( V_30 . V_128 != V_129 ) {
F_51 (lp, &the_lnet.ln_routers,
lp_rtr_list) {
if ( V_6 -> V_33 == NULL )
continue;
F_11 ( F_17 ( & V_6 -> V_33 -> V_34 ) ) ;
F_14 ( & V_6 -> V_33 -> V_34 ,
& V_30 . V_35 ) ;
V_6 -> V_33 = NULL ;
}
}
F_87 ( & V_30 . V_35 , & V_155 ) ;
if ( ! F_17 ( & V_155 ) ) {
F_8 ( V_72 ) ;
F_51 (rcd, &head, rcd_list)
F_68 ( V_99 -> V_119 ) ;
F_9 ( V_72 ) ;
}
F_87 ( & V_155 , & V_30 . V_156 ) ;
while ( ! F_17 ( & V_30 . V_156 ) ) {
F_88 (rcd, tmp, &the_lnet.ln_rcd_zombie,
rcd_list) {
if ( F_65 ( V_99 -> V_119 ) )
F_89 ( & V_99 -> V_34 , & V_155 ) ;
}
V_154 = V_154 &&
! F_17 ( & V_30 . V_156 ) ;
F_8 ( V_72 ) ;
while ( ! F_17 ( & V_155 ) ) {
V_99 = F_13 ( V_155 . V_157 ,
T_10 , V_34 ) ;
F_90 ( & V_99 -> V_34 ) ;
F_64 ( V_99 ) ;
}
if ( ! V_154 )
return;
V_79 ++ ;
F_5 ( ( ( V_79 & ( - V_79 ) ) == V_79 ) ? V_158 : V_11 ,
L_25 ) ;
F_57 ( F_58 ( 1 ) / 4 ) ;
F_9 ( V_72 ) ;
}
F_8 ( V_72 ) ;
}
static int
V_152 ( void * V_159 )
{
T_2 * V_28 ;
struct V_26 * V_126 ;
F_91 () ;
F_11 ( V_30 . V_128 == V_129 ) ;
while ( V_30 . V_128 == V_129 ) {
T_14 V_160 ;
int V_78 ;
int V_161 ;
V_78 = F_42 () ;
V_162:
V_160 = V_30 . V_31 ;
F_22 (entry, &the_lnet.ln_routers) {
V_28 = F_13 ( V_126 , T_2 , V_29 ) ;
V_161 = F_92 ( V_28 -> V_19 ) ;
if ( V_78 != V_161 ) {
F_8 ( V_78 ) ;
V_78 = V_161 ;
F_9 ( V_78 ) ;
if ( V_160 != V_30 . V_31 )
goto V_162;
}
F_70 ( V_28 ) ;
if ( V_160 != V_30 . V_31 ) {
goto V_162;
}
}
if ( V_30 . V_132 )
F_59 () ;
F_8 ( V_78 ) ;
F_85 ( 0 ) ;
F_93 ( V_163 ,
F_58 ( 1 ) ) ;
}
F_11 ( V_30 . V_128 == V_153 ) ;
F_85 ( 1 ) ;
V_30 . V_128 = V_150 ;
V_109 ( & V_30 . V_151 ) ;
return 0 ;
}
void
F_94 ( T_15 * V_164 , int V_165 )
{
int V_166 = F_95 ( T_15 , V_167 [ V_165 ] ) ;
while ( -- V_165 >= 0 )
F_96 ( V_164 -> V_167 [ V_165 ] . V_168 ) ;
F_37 ( V_164 , V_166 ) ;
}
T_15 *
F_97 ( T_16 * V_169 , int V_78 )
{
int V_165 = V_169 -> V_170 ;
int V_166 = F_95 ( T_15 , V_167 [ V_165 ] ) ;
struct V_171 * V_171 ;
T_15 * V_164 ;
int V_79 ;
F_98 ( V_164 , F_99 () , V_78 , V_166 ) ;
if ( V_164 == NULL )
return NULL ;
V_164 -> V_172 = V_169 ;
for ( V_79 = 0 ; V_79 < V_165 ; V_79 ++ ) {
V_171 = F_100 (
F_101 ( F_99 () , V_78 ) ,
V_173 | V_174 , 0 ) ;
if ( V_171 == NULL ) {
while ( -- V_79 >= 0 )
F_96 ( V_164 -> V_167 [ V_79 ] . V_168 ) ;
F_37 ( V_164 , V_166 ) ;
return NULL ;
}
V_164 -> V_167 [ V_79 ] . V_175 = V_176 ;
V_164 -> V_167 [ V_79 ] . V_177 = 0 ;
V_164 -> V_167 [ V_79 ] . V_168 = V_171 ;
}
return V_164 ;
}
void
F_102 ( T_16 * V_169 )
{
int V_165 = V_169 -> V_170 ;
int V_178 = 0 ;
T_15 * V_164 ;
if ( V_169 -> V_179 == 0 )
return;
F_11 ( F_17 ( & V_169 -> V_180 ) ) ;
F_11 ( V_169 -> V_181 == V_169 -> V_179 ) ;
while ( ! F_17 ( & V_169 -> V_182 ) ) {
F_11 ( V_169 -> V_181 > 0 ) ;
V_164 = F_13 ( V_169 -> V_182 . V_157 ,
T_15 , V_183 ) ;
F_18 ( & V_164 -> V_183 ) ;
F_94 ( V_164 , V_165 ) ;
V_178 ++ ;
}
F_11 ( V_169 -> V_179 == V_178 ) ;
F_11 ( V_169 -> V_181 == V_178 ) ;
V_169 -> V_179 = V_169 -> V_181 = 0 ;
}
int
F_103 ( T_16 * V_169 , int V_184 , int V_78 )
{
T_15 * V_164 ;
int V_79 ;
if ( V_169 -> V_179 != 0 ) {
F_11 ( V_169 -> V_179 == V_184 ) ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_184 ; V_79 ++ ) {
V_164 = F_97 ( V_169 , V_78 ) ;
if ( V_164 == NULL ) {
F_36 ( L_26 ,
V_184 , V_169 -> V_170 ) ;
return - V_68 ;
}
V_169 -> V_179 ++ ;
V_169 -> V_181 ++ ;
V_169 -> V_185 ++ ;
F_14 ( & V_164 -> V_183 , & V_169 -> V_182 ) ;
F_11 ( ! V_30 . V_132 ) ;
}
F_11 ( V_169 -> V_181 == V_184 ) ;
return 0 ;
}
void
F_104 ( T_16 * V_169 , int V_165 )
{
F_38 ( & V_169 -> V_180 ) ;
F_38 ( & V_169 -> V_182 ) ;
V_169 -> V_170 = V_165 ;
V_169 -> V_181 = 0 ;
V_169 -> V_185 = 0 ;
}
void
F_105 ( void )
{
T_16 * V_186 ;
int V_79 ;
if ( V_30 . V_187 == NULL )
return;
F_106 (rtrp, i, the_lnet.ln_rtrpools) {
F_102 ( & V_186 [ 0 ] ) ;
F_102 ( & V_186 [ 1 ] ) ;
F_102 ( & V_186 [ 2 ] ) ;
}
F_107 ( V_30 . V_187 ) ;
V_30 . V_187 = NULL ;
}
static int
F_108 ( int V_165 )
{
int V_188 = V_189 ;
if ( V_190 < 0 ) {
F_77 ( 0x10c ,
L_27
L_28 , V_190 ) ;
return - 1 ;
}
if ( V_190 > 0 )
V_188 = V_190 ;
V_188 /= V_191 ;
return F_109 ( V_188 , V_192 ) ;
}
static int
F_110 ( int V_165 )
{
int V_188 = V_193 ;
if ( V_194 < 0 ) {
F_77 ( 0x10c ,
L_29
L_28 , V_194 ) ;
return - 1 ;
}
if ( V_194 > 0 )
V_188 = V_194 ;
V_188 /= V_191 ;
return F_109 ( V_188 , V_195 ) ;
}
static int
F_111 ( int V_165 )
{
int V_188 = V_196 ;
if ( V_197 < 0 ) {
F_77 ( 0x10c ,
L_30
L_28 , V_197 ) ;
return - 1 ;
}
if ( V_197 > 0 )
V_188 = V_197 ;
V_188 /= V_191 ;
return F_109 ( V_188 , V_198 ) ;
}
int
F_112 ( int V_199 )
{
T_16 * V_186 ;
int V_200 = ( V_201 + V_176 - 1 ) >> V_202 ;
int V_203 = 1 ;
int V_204 ;
int V_205 ;
int V_206 ;
int V_65 ;
int V_79 ;
if ( ! strcmp ( V_207 , L_31 ) ) {
if ( ! V_199 )
return 0 ;
} else if ( ! strcmp ( V_207 , L_32 ) ) {
return 0 ;
} else if ( ! strcmp ( V_207 , L_33 ) ) {
} else {
F_77 ( 0x10b , L_34
L_35 ) ;
return - V_67 ;
}
V_204 = F_108 ( 0 ) ;
if ( V_204 < 0 )
return - V_67 ;
V_205 = F_110 ( V_203 ) ;
if ( V_205 < 0 )
return - V_67 ;
V_206 = F_111 ( V_200 ) ;
if ( V_206 < 0 )
return - V_67 ;
V_30 . V_187 = F_113 ( F_99 () ,
V_208 *
sizeof( T_16 ) ) ;
if ( V_30 . V_187 == NULL ) {
F_77 ( 0x10c ,
L_36 ) ;
return - V_68 ;
}
F_106 (rtrp, i, the_lnet.ln_rtrpools) {
F_104 ( & V_186 [ 0 ] , 0 ) ;
V_65 = F_103 ( & V_186 [ 0 ] , V_204 , V_79 ) ;
if ( V_65 != 0 )
goto V_209;
F_104 ( & V_186 [ 1 ] , V_203 ) ;
V_65 = F_103 ( & V_186 [ 1 ] , V_205 , V_79 ) ;
if ( V_65 != 0 )
goto V_209;
F_104 ( & V_186 [ 2 ] , V_200 ) ;
V_65 = F_103 ( & V_186 [ 2 ] , V_206 , V_79 ) ;
if ( V_65 != 0 )
goto V_209;
}
F_9 ( V_72 ) ;
V_30 . V_132 = 1 ;
F_8 ( V_72 ) ;
return 0 ;
V_209:
F_105 () ;
return V_65 ;
}
int
F_114 ( T_1 * V_1 , T_7 V_110 , int V_8 , T_3 V_9 )
{
struct V_85 * V_6 = NULL ;
T_3 V_130 = F_55 () ;
int V_78 = F_115 ( V_110 ) ;
F_11 ( ! F_116 () ) ;
F_5 ( V_11 , L_37 ,
( V_1 == NULL ) ? L_38 : F_6 ( V_1 -> V_49 ) ,
F_6 ( V_110 ) ,
V_8 ? L_39 : L_40 ) ;
if ( V_1 != NULL &&
F_26 ( V_1 -> V_49 ) != F_26 ( V_110 ) ) {
F_117 ( L_41 ,
F_6 ( V_110 ) , V_8 ? L_42 : L_43 ,
F_6 ( V_1 -> V_49 ) ) ;
return - V_67 ;
}
if ( F_71 ( V_9 , V_130 ) ) {
F_117 ( L_44
L_45 ,
( V_1 == NULL ) ? L_38 : F_6 ( V_1 -> V_49 ) ,
F_6 ( V_110 ) , V_8 ? L_39 : L_40 ,
F_118 ( F_119 ( V_9 , V_130 ) ) ) ;
return - V_67 ;
}
if ( V_1 != NULL && ! V_8 &&
! V_210 ) {
F_5 ( V_11 , L_46 ) ;
return 0 ;
}
F_9 ( V_78 ) ;
if ( V_30 . V_40 ) {
F_8 ( V_78 ) ;
return - V_211 ;
}
V_6 = F_120 ( V_30 . V_212 [ V_78 ] , V_110 ) ;
if ( V_6 == NULL ) {
F_8 ( V_78 ) ;
F_5 ( V_11 , L_47 , F_6 ( V_110 ) ) ;
return 0 ;
}
if ( V_1 != NULL && ! V_8 && V_9 < V_6 -> V_213 )
V_9 = V_6 -> V_213 ;
F_3 ( V_6 , V_1 == NULL , V_8 , V_9 ) ;
F_7 ( V_1 , V_6 ) ;
F_19 ( V_6 ) ;
F_8 ( V_78 ) ;
return 0 ;
}
void
F_121 ( void )
{
return;
}
int
F_114 ( T_1 * V_1 , T_7 V_110 , int V_8 , T_3 V_9 )
{
return - V_214 ;
}
void
V_152 ( void )
{
static T_17 V_215 = 0 ;
static int V_216 = 0 ;
T_17 V_130 = F_61 () ;
int V_217 = V_130 - V_215 ;
int V_65 ;
T_14 V_160 ;
T_2 * V_28 ;
if ( V_215 != 0 && V_217 < 2 )
return;
if ( V_215 != 0 &&
V_217 > F_60 ( V_134 ,
V_135 ) )
F_122 ( L_48 ,
V_134 , V_135 ,
V_217 ) ;
F_11 ( V_191 == 1 ) ;
F_9 ( 0 ) ;
F_11 ( ! V_216 ) ;
V_216 = 1 ;
F_8 ( 0 ) ;
V_215 = V_130 ;
if ( V_30 . V_128 == V_153 )
F_85 ( 0 ) ;
while ( 1 ) {
int V_79 ;
T_11 V_218 ;
V_65 = F_123 ( & V_30 . V_140 , 1 , 0 , & V_218 , & V_79 ) ;
if ( V_65 == 0 )
break;
if ( V_65 == - V_219 ) {
F_36 ( L_49 ) ;
abort () ;
}
F_11 ( V_65 == 1 ) ;
F_52 ( & V_218 ) ;
}
if ( V_30 . V_128 == V_153 ) {
F_85 ( 1 ) ;
V_30 . V_128 = V_150 ;
V_216 = 0 ;
return;
}
F_11 ( V_30 . V_128 == V_129 ) ;
F_9 ( 0 ) ;
V_160 = V_30 . V_31 ;
F_51 (rtr, &the_lnet.ln_routers, lp_rtr_list) {
F_70 ( V_28 ) ;
F_11 ( V_160 == V_30 . V_31 ) ;
}
F_8 ( 0 ) ;
V_216 = 0 ;
return;
}
void
F_121 ( void )
{
char * V_220 ;
V_220 = getenv ( L_50 ) ;
if ( V_220 != NULL ) V_133 = atoi ( V_220 ) ;
V_220 = getenv ( L_51 ) ;
if ( V_220 != NULL ) V_134 = atoi ( V_220 ) ;
V_220 = getenv ( L_52 ) ;
if ( V_220 != NULL ) V_135 = atoi ( V_220 ) ;
V_5 = 1 ;
if ( V_135 <= 0 )
V_135 = 30 ;
}
void
F_105 ( void )
{
}
int
F_112 ( int V_221 )
{
return 0 ;
}
