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
F_3 ( T_2 * V_6 , int V_7 , int V_8 , unsigned long V_9 )
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
static void
F_7 ( T_1 * V_1 , T_2 * V_6 )
{
int V_8 ;
int V_7 ;
if ( V_6 -> V_20 || V_1 == NULL )
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
F_32 ( T_4 V_36 , unsigned int V_61 , T_6 V_62 ,
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
V_61 < 1 || V_61 > 255 )
return - V_68 ;
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
return - V_69 ;
}
F_38 ( & V_37 -> V_70 ) ;
V_37 -> V_42 = V_36 ;
V_53 -> V_71 = V_61 ;
V_53 -> V_72 = V_36 ;
V_53 -> V_73 = V_63 ;
F_9 ( V_74 ) ;
V_66 = F_39 ( & V_53 -> V_59 , V_62 , V_74 ) ;
if ( V_66 != 0 ) {
F_8 ( V_74 ) ;
F_37 ( V_53 , sizeof( * V_53 ) ) ;
F_37 ( V_37 , sizeof( * V_37 ) ) ;
if ( V_66 == - V_75 ) {
return 0 ;
} else {
F_36 ( L_6 , V_66 ,
F_33 ( V_36 ) , V_61 ,
F_6 ( V_62 ) ) ;
}
return V_66 ;
}
F_11 ( ! V_30 . V_40 ) ;
V_64 = F_20 ( V_36 ) ;
if ( V_64 == NULL ) {
F_40 ( & V_37 -> V_41 , F_21 ( V_36 ) ) ;
V_64 = V_37 ;
}
V_65 = 1 ;
F_22 (e, &rnet2->lrn_routes) {
T_5 * V_76 = F_13 ( V_56 , T_5 , V_57 ) ;
if ( V_76 -> V_59 == V_53 -> V_59 ) {
V_65 = 0 ;
break;
}
F_11 ( V_76 -> V_59 -> V_19 != V_62 ) ;
}
if ( V_65 ) {
F_15 ( V_53 -> V_59 ) ;
F_30 ( V_64 , V_53 ) ;
V_1 = V_53 -> V_59 -> V_77 ;
F_8 ( V_74 ) ;
if ( V_1 -> V_21 -> V_22 != NULL )
( V_1 -> V_21 -> V_22 ) ( V_1 , V_62 , 1 ) ;
F_9 ( V_74 ) ;
}
F_19 ( V_53 -> V_59 ) ;
F_8 ( V_74 ) ;
if ( ! V_65 )
F_37 ( V_53 , sizeof( * V_53 ) ) ;
if ( V_37 != V_64 )
F_37 ( V_37 , sizeof( * V_37 ) ) ;
return 0 ;
}
int
F_41 ( void )
{
T_3 * V_37 ;
T_5 * V_53 ;
T_5 * V_76 ;
struct V_26 * V_78 ;
struct V_26 * V_79 ;
int V_80 ;
struct V_26 * V_39 ;
int V_81 ;
V_80 = F_42 () ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
V_39 = & V_30 . V_83 [ V_81 ] ;
F_22 (e1, rn_list) {
V_37 = F_13 ( V_78 , T_3 , V_41 ) ;
V_76 = NULL ;
F_22 (e2, &rnet->lrn_routes) {
T_6 V_84 ;
T_6 V_85 ;
int V_36 ;
V_53 = F_13 ( V_79 , T_5 ,
V_57 ) ;
if ( V_76 == NULL ) {
V_76 = V_53 ;
continue;
}
if ( V_53 -> V_59 -> V_77 ==
V_76 -> V_59 -> V_77 )
continue;
V_84 = V_53 -> V_59 -> V_19 ;
V_85 = V_76 -> V_59 -> V_19 ;
V_36 = V_37 -> V_42 ;
F_8 ( V_80 ) ;
F_36 ( L_7 ,
F_33 ( V_36 ) ,
F_6 ( V_84 ) ,
F_6 ( V_85 ) ) ;
return - V_68 ;
}
}
}
F_8 ( V_80 ) ;
return 0 ;
}
int
F_43 ( T_4 V_36 , T_6 V_86 )
{
struct V_87 * V_62 ;
T_3 * V_37 ;
T_5 * V_53 ;
struct V_26 * V_78 ;
struct V_26 * V_79 ;
int V_66 = - V_88 ;
struct V_26 * V_39 ;
int V_89 = 0 ;
F_5 ( V_11 , L_8 ,
F_33 ( V_36 ) , F_6 ( V_86 ) ) ;
F_9 ( V_74 ) ;
if ( V_36 == F_26 ( V_67 ) )
V_39 = & V_30 . V_83 [ 0 ] ;
else
V_39 = F_21 ( V_36 ) ;
V_90:
F_22 (e1, rn_list) {
V_37 = F_13 ( V_78 , T_3 , V_41 ) ;
if ( ! ( V_36 == F_26 ( V_67 ) ||
V_36 == V_37 -> V_42 ) )
continue;
F_22 (e2, &rnet->lrn_routes) {
V_53 = F_13 ( V_79 , T_5 , V_57 ) ;
V_62 = V_53 -> V_59 ;
if ( ! ( V_86 == V_67 ||
V_86 == V_62 -> V_19 ) )
continue;
F_18 ( & V_53 -> V_57 ) ;
F_18 ( & V_53 -> V_58 ) ;
V_30 . V_60 ++ ;
if ( F_17 ( & V_37 -> V_70 ) )
F_18 ( & V_37 -> V_41 ) ;
else
V_37 = NULL ;
F_16 ( V_62 ) ;
F_19 ( V_62 ) ;
F_8 ( V_74 ) ;
F_37 ( V_53 , sizeof( * V_53 ) ) ;
if ( V_37 != NULL )
F_37 ( V_37 , sizeof( * V_37 ) ) ;
V_66 = 0 ;
F_9 ( V_74 ) ;
goto V_90;
}
}
if ( V_36 == F_26 ( V_67 ) &&
++ V_89 < V_82 ) {
V_39 = & V_30 . V_83 [ V_89 ] ;
goto V_90;
}
F_8 ( V_74 ) ;
return V_66 ;
}
void
F_44 ( void )
{
F_43 ( F_26 ( V_67 ) , V_67 ) ;
}
int
F_45 ( int V_89 , T_4 * V_36 , T_4 * V_61 ,
T_6 * V_62 , T_4 * V_8 , T_4 * V_63 )
{
struct V_26 * V_78 ;
struct V_26 * V_79 ;
T_3 * V_37 ;
T_5 * V_53 ;
int V_80 ;
int V_81 ;
struct V_26 * V_39 ;
V_80 = F_42 () ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
V_39 = & V_30 . V_83 [ V_81 ] ;
F_22 (e1, rn_list) {
V_37 = F_13 ( V_78 , T_3 , V_41 ) ;
F_22 (e2, &rnet->lrn_routes) {
V_53 = F_13 ( V_79 , T_5 ,
V_57 ) ;
if ( V_89 -- == 0 ) {
* V_36 = V_37 -> V_42 ;
* V_61 = V_53 -> V_71 ;
* V_63 = V_53 -> V_73 ;
* V_62 = V_53 -> V_59 -> V_19 ;
* V_8 = V_53 -> V_59 -> V_14 ;
F_8 ( V_80 ) ;
return 0 ;
}
}
}
}
F_8 ( V_80 ) ;
return - V_88 ;
}
void
F_46 ( T_7 * V_91 )
{
int V_81 ;
T_8 * V_92 ;
F_47 ( & V_91 -> V_93 ) ;
F_47 ( & V_91 -> V_94 ) ;
F_47 ( & V_91 -> V_95 ) ;
F_47 ( & V_91 -> V_96 ) ;
for ( V_81 = 0 ; V_81 < V_91 -> V_96 && V_81 < V_97 ; V_81 ++ ) {
V_92 = & V_91 -> V_98 [ V_81 ] ;
F_48 ( & V_92 -> V_99 ) ;
F_47 ( & V_92 -> V_100 ) ;
}
return;
}
static void
F_49 ( T_9 * V_101 )
{
T_7 * V_91 = V_101 -> V_102 ;
struct V_87 * V_103 = V_101 -> V_104 ;
T_5 * V_28 ;
if ( ! V_103 -> V_14 )
return;
if ( V_91 -> V_93 == F_50 ( V_105 ) )
F_46 ( V_91 ) ;
if ( V_91 -> V_93 != V_105 ) {
F_5 ( V_11 , L_9 ,
F_6 ( V_103 -> V_19 ) , V_91 -> V_93 ) ;
V_103 -> V_17 = V_18 ;
return;
}
V_103 -> V_17 = V_91 -> V_94 ;
if ( ( V_103 -> V_17 & V_106 ) == 0 ) {
F_5 ( V_11 , L_10 ,
F_6 ( V_103 -> V_19 ) , V_103 -> V_17 ) ;
return;
}
if ( ( V_103 -> V_17 & V_107 ) == 0 )
return;
F_51 (rtr, &gw->lp_routes, lr_gwlist) {
int V_108 = V_109 ;
int V_110 = 0 ;
int V_111 = 0 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_91 -> V_96 && V_81 < V_97 ; V_81 ++ ) {
T_8 * V_92 = & V_91 -> V_98 [ V_81 ] ;
T_6 V_112 = V_92 -> V_99 ;
if ( V_112 == V_67 ) {
F_5 ( V_11 , L_11 ,
F_6 ( V_103 -> V_19 ) ) ;
V_103 -> V_17 = V_18 ;
return;
}
if ( F_25 ( F_26 ( V_112 ) ) == V_50 )
continue;
if ( V_92 -> V_100 == V_113 ) {
if ( F_25 ( F_26 ( V_112 ) ) != V_114 )
V_110 ++ ;
else if ( V_108 != V_115 )
V_108 = V_113 ;
continue;
}
if ( V_92 -> V_100 == V_115 ) {
if ( F_26 ( V_112 ) == V_28 -> V_72 ) {
V_111 = 1 ;
break;
}
if ( F_25 ( F_26 ( V_112 ) ) == V_114 )
V_108 = V_115 ;
continue;
}
F_5 ( V_11 , L_12 ,
F_6 ( V_103 -> V_19 ) , V_92 -> V_100 ) ;
V_103 -> V_17 = V_18 ;
return;
}
if ( V_111 ) {
V_28 -> V_116 = 0 ;
continue;
}
V_28 -> V_116 = V_110 + ( V_108 == V_113 ) ;
}
}
static void
F_52 ( T_10 * V_117 )
{
T_9 * V_101 = V_117 -> V_118 . V_119 ;
struct V_87 * V_6 ;
F_11 ( V_101 != NULL ) ;
if ( V_117 -> V_120 ) {
F_53 ( & V_101 -> V_121 ) ;
return;
}
F_11 ( V_117 -> type == V_122 ||
V_117 -> type == V_123 ) ;
V_6 = V_101 -> V_104 ;
F_11 ( V_6 != NULL ) ;
F_9 ( V_6 -> V_23 ) ;
if ( ! F_54 ( V_6 ) || V_6 -> V_33 != V_101 ) {
goto V_124;
}
if ( V_117 -> type == V_122 ) {
V_6 -> V_125 = 0 ;
if ( V_117 -> V_126 == 0 )
goto V_124;
}
F_3 ( V_6 , 1 , ( V_117 -> V_126 == 0 ) , F_55 () ) ;
if ( V_127 && V_117 -> V_126 == 0 )
F_49 ( V_101 ) ;
V_124:
F_8 ( V_6 -> V_23 ) ;
}
static void
F_56 ( void )
{
T_2 * V_28 ;
struct V_26 * V_128 ;
int V_129 ;
F_11 ( V_30 . V_130 == V_131 ) ;
for (; ; ) {
int V_80 = F_42 () ;
V_129 = 1 ;
F_22 (entry, &the_lnet.ln_routers) {
V_28 = F_13 ( V_128 , T_2 , V_29 ) ;
if ( V_28 -> V_13 == 0 ) {
V_129 = 0 ;
break;
}
}
F_8 ( V_80 ) ;
if ( V_129 )
return;
F_57 ( V_132 ) ;
F_58 ( F_59 ( 1 ) ) ;
}
}
static void
F_60 ( void )
{
T_1 * V_1 ;
long V_133 ;
int V_134 ;
F_11 ( V_30 . V_135 ) ;
V_134 = V_136 +
F_61 ( V_137 , V_138 ) ;
V_133 = F_62 () ;
F_51 (ni, &the_lnet.ln_nis, ni_list) {
if ( V_1 -> V_21 -> V_44 == V_50 )
continue;
if ( V_133 < V_1 -> V_139 + V_134 )
continue;
F_63 ( V_1 ) ;
if ( V_133 < V_1 -> V_139 + V_134 ) {
F_64 ( V_1 ) ;
continue;
}
F_11 ( V_1 -> V_140 != NULL ) ;
if ( V_1 -> V_140 -> V_100 != V_113 ) {
F_5 ( V_11 , L_13 ,
F_6 ( V_1 -> V_49 ) , V_134 ) ;
V_1 -> V_140 -> V_100 = V_113 ;
}
F_64 ( V_1 ) ;
}
}
static void
F_65 ( T_9 * V_101 )
{
F_11 ( F_17 ( & V_101 -> V_34 ) ) ;
F_11 ( F_66 ( V_101 -> V_121 ) ) ;
if ( V_101 -> V_104 != NULL ) {
int V_80 = V_101 -> V_104 -> V_23 ;
F_9 ( V_80 ) ;
F_19 ( V_101 -> V_104 ) ;
F_8 ( V_80 ) ;
}
if ( V_101 -> V_102 != NULL )
F_37 ( V_101 -> V_102 , V_141 ) ;
F_37 ( V_101 , sizeof( * V_101 ) ) ;
}
static T_9 *
F_67 ( T_2 * V_62 )
{
T_9 * V_101 = NULL ;
T_7 * V_142 ;
int V_66 ;
int V_81 ;
F_8 ( V_62 -> V_23 ) ;
F_35 ( V_101 , sizeof( * V_101 ) ) ;
if ( V_101 == NULL )
goto V_124;
F_53 ( & V_101 -> V_121 ) ;
F_38 ( & V_101 -> V_34 ) ;
F_35 ( V_142 , V_141 ) ;
if ( V_142 == NULL )
goto V_124;
for ( V_81 = 0 ; V_81 < V_97 ; V_81 ++ ) {
V_142 -> V_98 [ V_81 ] . V_99 = V_67 ;
V_142 -> V_98 [ V_81 ] . V_100 = V_109 ;
}
V_101 -> V_102 = V_142 ;
F_11 ( ! F_66 ( V_30 . V_143 ) ) ;
V_66 = F_68 ((lnet_md_t){.start = pi,
.user_ptr = rcd,
.length = LNET_PINGINFO_SIZE,
.threshold = LNET_MD_THRESH_INF,
.options = LNET_MD_TRUNCATE,
.eq_handle = the_lnet.ln_rc_eqh},
LNET_UNLINK,
&rcd->rcd_mdh) ;
if ( V_66 < 0 ) {
F_36 ( L_14 , V_66 ) ;
goto V_124;
}
F_11 ( V_66 == 0 ) ;
F_9 ( V_62 -> V_23 ) ;
if ( ! F_54 ( V_62 ) || V_62 -> V_33 != NULL ) {
F_8 ( V_62 -> V_23 ) ;
goto V_124;
}
F_15 ( V_62 ) ;
V_101 -> V_104 = V_62 ;
V_62 -> V_33 = V_101 ;
V_62 -> V_125 = 0 ;
return V_101 ;
V_124:
if ( V_101 != NULL ) {
if ( ! F_66 ( V_101 -> V_121 ) ) {
V_66 = F_69 ( V_101 -> V_121 ) ;
F_11 ( V_66 == 0 ) ;
}
F_65 ( V_101 ) ;
}
F_9 ( V_62 -> V_23 ) ;
return V_62 -> V_33 ;
}
static int
F_70 ( T_2 * V_28 )
{
int V_144 ;
V_144 = V_28 -> V_14 ? V_137 :
V_138 ;
if ( V_144 < 0 )
V_144 = 0 ;
return V_144 ;
}
static void
F_71 ( T_2 * V_28 )
{
T_9 * V_101 = NULL ;
unsigned long V_133 = F_55 () ;
int V_144 ;
F_15 ( V_28 ) ;
if ( V_28 -> V_12 != 0 &&
F_72 ( V_133 , V_28 -> V_12 ) )
F_3 ( V_28 , 1 , 0 , V_133 ) ;
F_7 ( V_28 -> V_77 , V_28 ) ;
if ( ! F_54 ( V_28 ) ||
V_30 . V_130 != V_131 ) {
F_19 ( V_28 ) ;
return;
}
V_101 = V_28 -> V_33 != NULL ?
V_28 -> V_33 : F_67 ( V_28 ) ;
if ( V_101 == NULL )
return;
V_144 = F_70 ( V_28 ) ;
F_5 ( V_11 ,
L_15 ,
F_6 ( V_28 -> V_19 ) , V_144 ,
V_28 -> V_12 , V_28 -> V_125 ,
V_28 -> V_14 , V_28 -> V_13 , V_28 -> V_145 ) ;
if ( V_144 != 0 && ! V_28 -> V_125 &&
F_72 ( V_133 , F_73 ( V_28 -> V_145 ,
F_59 ( V_144 ) ) ) ) {
int V_66 ;
T_11 V_146 ;
T_12 V_147 ;
V_146 . V_112 = V_28 -> V_19 ;
V_146 . V_148 = V_149 ;
F_5 ( V_11 , L_16 , F_74 ( V_146 ) ) ;
V_28 -> V_125 = 1 ;
V_28 -> V_145 = V_133 ;
V_147 = V_101 -> V_121 ;
if ( V_28 -> V_12 == 0 ) {
V_28 -> V_12 =
F_75 ( V_136 ) ;
}
F_8 ( V_28 -> V_23 ) ;
V_66 = F_76 ( V_67 , V_147 , V_146 , V_150 ,
V_151 , 0 ) ;
F_9 ( V_28 -> V_23 ) ;
if ( V_66 != 0 )
V_28 -> V_125 = 0 ;
}
F_19 ( V_28 ) ;
return;
}
int
F_77 ( void )
{
int V_66 ;
int V_152 ;
F_11 ( V_30 . V_130 == V_153 ) ;
if ( V_5 &&
V_138 <= 0 ) {
F_78 ( 0x10a , L_17 ) ;
return - V_68 ;
}
if ( ! V_30 . V_135 &&
V_137 <= 0 &&
V_138 <= 0 )
return 0 ;
F_79 ( & V_30 . V_154 , 0 ) ;
V_152 = 0 ;
V_66 = F_80 ( V_152 , F_52 ,
& V_30 . V_143 ) ;
if ( V_66 != 0 ) {
F_36 ( L_18 , V_152 , V_66 ) ;
return - V_69 ;
}
V_30 . V_130 = V_131 ;
V_66 = F_81 ( F_82 ( V_155 ,
NULL , L_19 ) ) ;
if ( F_83 ( V_66 ) ) {
F_36 ( L_20 , V_66 ) ;
V_110 ( & V_30 . V_154 ) ;
V_66 = F_84 ( V_30 . V_143 ) ;
F_11 ( V_66 == 0 ) ;
V_30 . V_130 = V_153 ;
return - V_69 ;
}
if ( V_5 ) {
F_56 () ;
}
return 0 ;
}
void
F_85 ( void )
{
int V_66 ;
if ( V_30 . V_130 == V_153 )
return;
F_11 ( V_30 . V_130 == V_131 ) ;
V_30 . V_130 = V_156 ;
V_110 ( & V_30 . V_154 ) ;
F_11 ( V_30 . V_130 == V_153 ) ;
V_66 = F_84 ( V_30 . V_143 ) ;
F_11 ( V_66 == 0 ) ;
return;
}
static void
F_86 ( int V_157 )
{
T_9 * V_101 ;
T_9 * V_38 ;
T_2 * V_6 ;
struct V_26 V_158 ;
int V_81 = 2 ;
if ( F_87 ( V_30 . V_130 == V_131 &&
F_17 ( & V_30 . V_35 ) &&
F_17 ( & V_30 . V_159 ) ) )
return;
F_38 ( & V_158 ) ;
F_9 ( V_74 ) ;
if ( V_30 . V_130 != V_131 ) {
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
F_88 ( & V_30 . V_35 , & V_158 ) ;
if ( ! F_17 ( & V_158 ) ) {
F_8 ( V_74 ) ;
F_51 (rcd, &head, rcd_list)
F_69 ( V_101 -> V_121 ) ;
F_9 ( V_74 ) ;
}
F_88 ( & V_158 , & V_30 . V_159 ) ;
while ( ! F_17 ( & V_30 . V_159 ) ) {
F_89 (rcd, tmp, &the_lnet.ln_rcd_zombie,
rcd_list) {
if ( F_66 ( V_101 -> V_121 ) )
F_90 ( & V_101 -> V_34 , & V_158 ) ;
}
V_157 = V_157 &&
! F_17 ( & V_30 . V_159 ) ;
F_8 ( V_74 ) ;
while ( ! F_17 ( & V_158 ) ) {
V_101 = F_13 ( V_158 . V_160 ,
T_9 , V_34 ) ;
F_91 ( & V_101 -> V_34 ) ;
F_65 ( V_101 ) ;
}
if ( ! V_157 )
return;
V_81 ++ ;
F_5 ( ( ( V_81 & ( - V_81 ) ) == V_81 ) ? V_161 : V_11 ,
L_21 ) ;
F_57 ( V_132 ) ;
F_58 ( F_59 ( 1 ) / 4 ) ;
F_9 ( V_74 ) ;
}
F_8 ( V_74 ) ;
}
static int
V_155 ( void * V_162 )
{
T_2 * V_28 ;
struct V_26 * V_128 ;
F_92 () ;
F_11 ( V_30 . V_130 == V_131 ) ;
while ( V_30 . V_130 == V_131 ) {
T_13 V_163 ;
int V_80 ;
int V_164 ;
V_80 = F_42 () ;
V_165:
V_163 = V_30 . V_31 ;
F_22 (entry, &the_lnet.ln_routers) {
V_28 = F_13 ( V_128 , T_2 , V_29 ) ;
V_164 = F_93 ( V_28 -> V_19 ) ;
if ( V_80 != V_164 ) {
F_8 ( V_80 ) ;
V_80 = V_164 ;
F_9 ( V_80 ) ;
if ( V_163 != V_30 . V_31 )
goto V_165;
}
F_71 ( V_28 ) ;
if ( V_163 != V_30 . V_31 ) {
goto V_165;
}
}
if ( V_30 . V_135 )
F_60 () ;
F_8 ( V_80 ) ;
F_86 ( 0 ) ;
F_57 ( V_166 ) ;
F_58 ( F_59 ( 1 ) ) ;
}
F_11 ( V_30 . V_130 == V_156 ) ;
F_86 ( 1 ) ;
V_30 . V_130 = V_153 ;
V_111 ( & V_30 . V_154 ) ;
return 0 ;
}
static void
F_94 ( T_14 * V_167 , int V_168 )
{
int V_169 = F_95 ( T_14 , V_170 [ V_168 ] ) ;
while ( -- V_168 >= 0 )
F_96 ( V_167 -> V_170 [ V_168 ] . V_171 ) ;
F_37 ( V_167 , V_169 ) ;
}
static T_14 *
F_97 ( T_15 * V_172 , int V_80 )
{
int V_168 = V_172 -> V_173 ;
int V_169 = F_95 ( T_14 , V_170 [ V_168 ] ) ;
struct V_174 * V_174 ;
T_14 * V_167 ;
int V_81 ;
F_98 ( V_167 , F_99 () , V_80 , V_169 ) ;
if ( V_167 == NULL )
return NULL ;
V_167 -> V_175 = V_172 ;
for ( V_81 = 0 ; V_81 < V_168 ; V_81 ++ ) {
V_174 = F_100 (
F_101 ( F_99 () , V_80 ) ,
V_176 | V_177 , 0 ) ;
if ( V_174 == NULL ) {
while ( -- V_81 >= 0 )
F_96 ( V_167 -> V_170 [ V_81 ] . V_171 ) ;
F_37 ( V_167 , V_169 ) ;
return NULL ;
}
V_167 -> V_170 [ V_81 ] . V_178 = V_179 ;
V_167 -> V_170 [ V_81 ] . V_180 = 0 ;
V_167 -> V_170 [ V_81 ] . V_171 = V_174 ;
}
return V_167 ;
}
static void
F_102 ( T_15 * V_172 )
{
int V_168 = V_172 -> V_173 ;
int V_181 = 0 ;
T_14 * V_167 ;
if ( V_172 -> V_182 == 0 )
return;
F_11 ( F_17 ( & V_172 -> V_183 ) ) ;
F_11 ( V_172 -> V_184 == V_172 -> V_182 ) ;
while ( ! F_17 ( & V_172 -> V_185 ) ) {
F_11 ( V_172 -> V_184 > 0 ) ;
V_167 = F_13 ( V_172 -> V_185 . V_160 ,
T_14 , V_186 ) ;
F_18 ( & V_167 -> V_186 ) ;
F_94 ( V_167 , V_168 ) ;
V_181 ++ ;
}
F_11 ( V_172 -> V_182 == V_181 ) ;
F_11 ( V_172 -> V_184 == V_181 ) ;
V_172 -> V_182 = V_172 -> V_184 = 0 ;
}
static int
F_103 ( T_15 * V_172 , int V_187 , int V_80 )
{
T_14 * V_167 ;
int V_81 ;
if ( V_172 -> V_182 != 0 ) {
F_11 ( V_172 -> V_182 == V_187 ) ;
return 0 ;
}
for ( V_81 = 0 ; V_81 < V_187 ; V_81 ++ ) {
V_167 = F_97 ( V_172 , V_80 ) ;
if ( V_167 == NULL ) {
F_36 ( L_22 ,
V_187 , V_172 -> V_173 ) ;
return - V_69 ;
}
V_172 -> V_182 ++ ;
V_172 -> V_184 ++ ;
V_172 -> V_188 ++ ;
F_14 ( & V_167 -> V_186 , & V_172 -> V_185 ) ;
F_11 ( ! V_30 . V_135 ) ;
}
F_11 ( V_172 -> V_184 == V_187 ) ;
return 0 ;
}
static void
F_104 ( T_15 * V_172 , int V_168 )
{
F_38 ( & V_172 -> V_183 ) ;
F_38 ( & V_172 -> V_185 ) ;
V_172 -> V_173 = V_168 ;
V_172 -> V_184 = 0 ;
V_172 -> V_188 = 0 ;
}
void
F_105 ( void )
{
T_15 * V_189 ;
int V_81 ;
if ( V_30 . V_190 == NULL )
return;
F_106 (rtrp, i, the_lnet.ln_rtrpools) {
F_102 ( & V_189 [ 0 ] ) ;
F_102 ( & V_189 [ 1 ] ) ;
F_102 ( & V_189 [ 2 ] ) ;
}
F_107 ( V_30 . V_190 ) ;
V_30 . V_190 = NULL ;
}
static int
F_108 ( int V_168 )
{
int V_191 = V_192 ;
if ( V_193 < 0 ) {
F_78 ( 0x10c ,
L_23 ,
V_193 ) ;
return - 1 ;
}
if ( V_193 > 0 )
V_191 = V_193 ;
V_191 /= V_194 ;
return F_109 ( V_191 , V_195 ) ;
}
static int
F_110 ( int V_168 )
{
int V_191 = V_196 ;
if ( V_197 < 0 ) {
F_78 ( 0x10c ,
L_24 ,
V_197 ) ;
return - 1 ;
}
if ( V_197 > 0 )
V_191 = V_197 ;
V_191 /= V_194 ;
return F_109 ( V_191 , V_198 ) ;
}
static int
F_111 ( int V_168 )
{
int V_191 = V_199 ;
if ( V_200 < 0 ) {
F_78 ( 0x10c ,
L_25 ,
V_200 ) ;
return - 1 ;
}
if ( V_200 > 0 )
V_191 = V_200 ;
V_191 /= V_194 ;
return F_109 ( V_191 , V_201 ) ;
}
int
F_112 ( int V_202 )
{
T_15 * V_189 ;
int V_203 = ( V_204 + V_179 - 1 ) >> V_205 ;
int V_206 = 1 ;
int V_207 ;
int V_208 ;
int V_209 ;
int V_66 ;
int V_81 ;
if ( ! strcmp ( V_210 , L_26 ) ) {
if ( ! V_202 )
return 0 ;
} else if ( ! strcmp ( V_210 , L_27 ) ) {
return 0 ;
} else if ( ! strcmp ( V_210 , L_28 ) ) {
} else {
F_78 ( 0x10b , L_29 ) ;
return - V_68 ;
}
V_207 = F_108 ( 0 ) ;
if ( V_207 < 0 )
return - V_68 ;
V_208 = F_110 ( V_206 ) ;
if ( V_208 < 0 )
return - V_68 ;
V_209 = F_111 ( V_203 ) ;
if ( V_209 < 0 )
return - V_68 ;
V_30 . V_190 = F_113 ( F_99 () ,
V_211 *
sizeof( T_15 ) ) ;
if ( V_30 . V_190 == NULL ) {
F_78 ( 0x10c ,
L_30 ) ;
return - V_69 ;
}
F_106 (rtrp, i, the_lnet.ln_rtrpools) {
F_104 ( & V_189 [ 0 ] , 0 ) ;
V_66 = F_103 ( & V_189 [ 0 ] , V_207 , V_81 ) ;
if ( V_66 != 0 )
goto V_212;
F_104 ( & V_189 [ 1 ] , V_206 ) ;
V_66 = F_103 ( & V_189 [ 1 ] , V_208 , V_81 ) ;
if ( V_66 != 0 )
goto V_212;
F_104 ( & V_189 [ 2 ] , V_203 ) ;
V_66 = F_103 ( & V_189 [ 2 ] , V_209 , V_81 ) ;
if ( V_66 != 0 )
goto V_212;
}
F_9 ( V_74 ) ;
V_30 . V_135 = 1 ;
F_8 ( V_74 ) ;
return 0 ;
V_212:
F_105 () ;
return V_66 ;
}
int
F_114 ( T_1 * V_1 , T_6 V_112 , int V_8 , unsigned long V_9 )
{
struct V_87 * V_6 = NULL ;
unsigned long V_133 = F_55 () ;
int V_80 = F_115 ( V_112 ) ;
F_11 ( ! F_116 () ) ;
F_5 ( V_11 , L_31 ,
( V_1 == NULL ) ? L_32 : F_6 ( V_1 -> V_49 ) ,
F_6 ( V_112 ) ,
V_8 ? L_33 : L_34 ) ;
if ( V_1 != NULL &&
F_26 ( V_1 -> V_49 ) != F_26 ( V_112 ) ) {
F_117 ( L_35 ,
F_6 ( V_112 ) , V_8 ? L_36 : L_37 ,
F_6 ( V_1 -> V_49 ) ) ;
return - V_68 ;
}
if ( F_72 ( V_9 , V_133 ) ) {
F_117 ( L_38 ,
( V_1 == NULL ) ? L_32 : F_6 ( V_1 -> V_49 ) ,
F_6 ( V_112 ) , V_8 ? L_33 : L_34 ,
F_118 ( F_119 ( V_9 , V_133 ) ) ) ;
return - V_68 ;
}
if ( V_1 != NULL && ! V_8 &&
! V_213 ) {
F_5 ( V_11 , L_39 ) ;
return 0 ;
}
F_9 ( V_80 ) ;
if ( V_30 . V_40 ) {
F_8 ( V_80 ) ;
return - V_214 ;
}
V_6 = F_120 ( V_30 . V_215 [ V_80 ] , V_112 ) ;
if ( V_6 == NULL ) {
F_8 ( V_80 ) ;
F_5 ( V_11 , L_40 , F_6 ( V_112 ) ) ;
return 0 ;
}
if ( V_1 != NULL && ! V_8 && V_9 < V_6 -> V_216 )
V_9 = V_6 -> V_216 ;
F_3 ( V_6 , V_1 == NULL , V_8 , V_9 ) ;
F_7 ( V_1 , V_6 ) ;
F_19 ( V_6 ) ;
F_8 ( V_80 ) ;
return 0 ;
}
void
F_121 ( void )
{
return;
}
int
F_114 ( T_1 * V_1 , T_6 V_112 , int V_8 , unsigned long V_9 )
{
return - V_217 ;
}
void
V_155 ( void )
{
static T_16 V_218 = 0 ;
static int V_219 = 0 ;
T_16 V_133 = F_62 () ;
int V_220 = V_133 - V_218 ;
int V_66 ;
T_13 V_163 ;
T_2 * V_28 ;
if ( V_218 != 0 && V_220 < 2 )
return;
if ( V_218 != 0 &&
V_220 > F_61 ( V_137 ,
V_138 ) )
F_122 ( L_41 ,
V_137 , V_138 ,
V_220 ) ;
F_11 ( V_194 == 1 ) ;
F_9 ( 0 ) ;
F_11 ( ! V_219 ) ;
V_219 = 1 ;
F_8 ( 0 ) ;
V_218 = V_133 ;
if ( V_30 . V_130 == V_156 )
F_86 ( 0 ) ;
while ( 1 ) {
int V_81 ;
T_10 V_221 ;
V_66 = F_123 ( & V_30 . V_143 , 1 , 0 , & V_221 , & V_81 ) ;
if ( V_66 == 0 )
break;
if ( V_66 == - V_222 ) {
F_36 ( L_42 ) ;
abort () ;
}
F_11 ( V_66 == 1 ) ;
F_52 ( & V_221 ) ;
}
if ( V_30 . V_130 == V_156 ) {
F_86 ( 1 ) ;
V_30 . V_130 = V_153 ;
V_219 = 0 ;
return;
}
F_11 ( V_30 . V_130 == V_131 ) ;
F_9 ( 0 ) ;
V_163 = V_30 . V_31 ;
F_51 (rtr, &the_lnet.ln_routers, lp_rtr_list) {
F_71 ( V_28 ) ;
F_11 ( V_163 == V_30 . V_31 ) ;
}
F_8 ( 0 ) ;
V_219 = 0 ;
return;
}
void
F_121 ( void )
{
char * V_223 ;
V_223 = getenv ( L_43 ) ;
if ( V_223 != NULL ) V_136 = atoi ( V_223 ) ;
V_223 = getenv ( L_44 ) ;
if ( V_223 != NULL ) V_137 = atoi ( V_223 ) ;
V_223 = getenv ( L_45 ) ;
if ( V_223 != NULL ) V_138 = atoi ( V_223 ) ;
V_5 = 1 ;
if ( V_138 <= 0 )
V_138 = 30 ;
}
void
F_105 ( void )
{
}
int
F_112 ( int V_224 )
{
return 0 ;
}
