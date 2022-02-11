int
F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 > 0 )
return V_2 -> V_3 ;
if ( V_4 > 0 )
return V_4 ;
return V_2 -> V_5 ;
}
int
F_2 ( void )
{
return V_6 ;
}
void
F_3 ( struct V_7 * V_8 , int V_9 , int V_10 ,
unsigned long V_11 )
{
if ( F_4 ( V_11 , V_8 -> V_12 ) ) {
F_5 ( V_13 , L_1 ) ;
return;
}
V_8 -> V_12 = V_11 ;
V_8 -> V_14 = 0 ;
if ( V_8 -> V_15 &&
( ! V_8 -> V_16 ) == ( ! V_10 ) ) {
F_5 ( V_13 , L_2 ) ;
return;
}
V_8 -> V_15 ++ ;
V_8 -> V_16 = ! ( ! V_10 ) ;
V_8 -> V_17 = 1 ;
V_8 -> V_18 |= V_9 ;
if ( V_8 -> V_16 )
V_8 -> V_19 = V_20 ;
F_5 ( V_13 , L_3 , F_6 ( V_8 -> V_21 ) , V_10 ) ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
int V_10 ;
int V_9 ;
if ( V_8 -> V_22 || ! V_2 )
return;
V_8 -> V_22 = 1 ;
while ( V_8 -> V_17 ) {
V_10 = V_8 -> V_16 ;
V_9 = V_8 -> V_18 ;
V_8 -> V_18 = 0 ;
V_8 -> V_17 = 0 ;
if ( V_9 && V_2 -> V_23 -> V_24 ) {
F_8 ( V_8 -> V_25 ) ;
V_2 -> V_23 -> V_24 ( V_2 , V_8 -> V_21 , V_10 ) ;
F_9 ( V_8 -> V_25 ) ;
}
}
V_8 -> V_22 = 0 ;
}
static void
F_10 ( struct V_7 * V_8 )
{
F_11 ( V_8 -> V_26 > 0 ) ;
F_11 ( V_8 -> V_27 >= 0 ) ;
V_8 -> V_27 ++ ;
if ( V_8 -> V_27 == 1 ) {
struct V_28 * V_29 ;
F_12 (pos, &the_lnet.ln_routers) {
struct V_7 * V_30 ;
V_30 = F_13 ( V_29 , struct V_7 , V_31 ) ;
if ( V_30 -> V_21 < V_8 -> V_21 )
break;
}
F_14 ( & V_8 -> V_31 , V_29 ) ;
F_15 ( V_8 ) ;
V_32 . V_33 ++ ;
}
}
static void
F_16 ( struct V_7 * V_8 )
{
F_11 ( V_8 -> V_26 > 0 ) ;
F_11 ( V_8 -> V_27 > 0 ) ;
V_8 -> V_27 -- ;
if ( ! V_8 -> V_27 ) {
F_11 ( F_17 ( & V_8 -> V_34 ) ) ;
if ( V_8 -> V_35 ) {
F_14 ( & V_8 -> V_35 -> V_36 ,
& V_32 . V_37 ) ;
V_8 -> V_35 = NULL ;
}
F_18 ( & V_8 -> V_31 ) ;
F_19 ( V_8 ) ;
V_32 . V_33 ++ ;
}
}
struct V_38 *
F_20 ( T_1 V_39 )
{
struct V_38 * V_40 ;
struct V_28 * V_41 ;
struct V_28 * V_42 ;
F_11 ( ! V_32 . V_43 ) ;
V_42 = F_21 ( V_39 ) ;
F_22 (tmp, rn_list) {
V_40 = F_13 ( V_41 , struct V_38 , V_44 ) ;
if ( V_40 -> V_45 == V_39 )
return V_40 ;
}
return NULL ;
}
static void F_23 ( void )
{
static int V_46 ;
T_1 V_47 , V_48 [ 2 ] ;
struct V_49 V_50 ;
struct V_1 * V_2 ;
struct V_28 * V_41 ;
if ( V_46 )
return;
F_24 ( V_48 , sizeof( V_48 ) ) ;
F_22 (tmp, &the_lnet.ln_nis) {
V_2 = F_13 ( V_41 , struct V_1 , V_51 ) ;
V_47 = F_25 ( F_26 ( V_2 -> V_52 ) ) ;
if ( V_47 != V_53 )
V_48 [ 0 ] ^= ( F_27 ( V_2 -> V_52 ) | V_47 ) ;
}
F_28 ( & V_50 ) ;
F_29 ( V_50 . V_54 ^ V_48 [ 0 ] , V_50 . V_55 ^ V_48 [ 1 ] ) ;
V_46 = 1 ;
}
static void
F_30 ( struct V_38 * V_40 , struct V_56 * V_57 )
{
unsigned int V_58 = 0 ;
unsigned int V_59 = 0 ;
struct V_28 * V_60 ;
F_23 () ;
F_22 (e, &rnet->lrn_routes) {
V_58 ++ ;
}
V_59 = F_31 () % ( V_58 + 1 ) ;
F_22 (e, &rnet->lrn_routes) {
if ( ! V_59 )
break;
V_59 -- ;
}
F_14 ( & V_57 -> V_61 , V_60 ) ;
F_14 ( & V_57 -> V_62 , & V_57 -> V_63 -> V_34 ) ;
V_32 . V_64 ++ ;
F_10 ( V_57 -> V_63 ) ;
}
int
F_32 ( T_1 V_39 , T_1 V_65 , T_2 V_66 ,
unsigned int V_67 )
{
struct V_28 * V_60 ;
struct V_38 * V_40 ;
struct V_38 * V_68 ;
struct V_56 * V_57 ;
struct V_1 * V_2 ;
int V_69 ;
int V_70 ;
F_5 ( V_13 , L_4 ,
F_33 ( V_39 ) , V_65 , V_67 , F_6 ( V_66 ) ) ;
if ( V_66 == V_71 ||
F_25 ( F_26 ( V_66 ) ) == V_53 ||
V_39 == F_26 ( V_71 ) ||
F_25 ( V_39 ) == V_53 ||
F_26 ( V_66 ) == V_39 ||
( V_65 != V_72 && ( V_65 < 1 || V_65 > 255 ) ) )
return - V_73 ;
if ( F_34 ( V_39 ) )
return - V_74 ;
F_35 ( V_57 , sizeof( * V_57 ) ) ;
F_35 ( V_40 , sizeof( * V_40 ) ) ;
if ( ! V_57 || ! V_40 ) {
F_36 ( L_5 ,
F_33 ( V_39 ) , V_65 , F_6 ( V_66 ) ) ;
if ( V_57 )
F_37 ( V_57 , sizeof( * V_57 ) ) ;
if ( V_40 )
F_37 ( V_40 , sizeof( * V_40 ) ) ;
return - V_75 ;
}
F_38 ( & V_40 -> V_76 ) ;
V_40 -> V_45 = V_39 ;
V_57 -> V_77 = V_65 ;
V_57 -> V_78 = V_39 ;
V_57 -> V_79 = V_67 ;
F_9 ( V_80 ) ;
V_70 = F_39 ( & V_57 -> V_63 , V_66 , V_80 ) ;
if ( V_70 ) {
F_8 ( V_80 ) ;
F_37 ( V_57 , sizeof( * V_57 ) ) ;
F_37 ( V_40 , sizeof( * V_40 ) ) ;
if ( V_70 == - V_81 )
return V_70 ;
F_36 ( L_6 , V_70 ,
F_33 ( V_39 ) , V_65 ,
F_6 ( V_66 ) ) ;
return V_70 ;
}
F_11 ( ! V_32 . V_43 ) ;
V_68 = F_20 ( V_39 ) ;
if ( ! V_68 ) {
F_40 ( & V_40 -> V_44 , F_21 ( V_39 ) ) ;
V_68 = V_40 ;
}
V_69 = 1 ;
F_22 (e, &rnet2->lrn_routes) {
struct V_56 * V_82 ;
V_82 = F_13 ( V_60 , struct V_56 , V_61 ) ;
if ( V_82 -> V_63 == V_57 -> V_63 ) {
V_69 = 0 ;
break;
}
F_11 ( V_82 -> V_63 -> V_21 != V_66 ) ;
}
if ( V_69 ) {
F_15 ( V_57 -> V_63 ) ;
F_30 ( V_68 , V_57 ) ;
V_2 = V_57 -> V_63 -> V_83 ;
F_8 ( V_80 ) ;
if ( V_2 -> V_23 -> V_24 )
V_2 -> V_23 -> V_24 ( V_2 , V_66 , 1 ) ;
F_9 ( V_80 ) ;
}
F_19 ( V_57 -> V_63 ) ;
F_8 ( V_80 ) ;
V_70 = 0 ;
if ( ! V_69 ) {
V_70 = - V_74 ;
F_37 ( V_57 , sizeof( * V_57 ) ) ;
}
if ( V_40 != V_68 )
F_37 ( V_40 , sizeof( * V_40 ) ) ;
F_41 ( & V_32 . V_84 ) ;
return V_70 ;
}
int
F_42 ( void )
{
struct V_38 * V_40 ;
struct V_56 * V_57 ;
struct V_56 * V_82 ;
struct V_28 * V_85 ;
struct V_28 * V_86 ;
int V_87 ;
struct V_28 * V_42 ;
int V_88 ;
V_87 = F_43 () ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ ) {
V_42 = & V_32 . V_90 [ V_88 ] ;
F_22 (e1, rn_list) {
V_40 = F_13 ( V_85 , struct V_38 , V_44 ) ;
V_82 = NULL ;
F_22 (e2, &rnet->lrn_routes) {
T_2 V_91 ;
T_2 V_92 ;
int V_39 ;
V_57 = F_13 ( V_86 , struct V_56 , V_61 ) ;
if ( ! V_82 ) {
V_82 = V_57 ;
continue;
}
if ( V_57 -> V_63 -> V_83 ==
V_82 -> V_63 -> V_83 )
continue;
V_91 = V_57 -> V_63 -> V_21 ;
V_92 = V_82 -> V_63 -> V_21 ;
V_39 = V_40 -> V_45 ;
F_8 ( V_87 ) ;
F_36 ( L_7 ,
F_33 ( V_39 ) ,
F_6 ( V_91 ) ,
F_6 ( V_92 ) ) ;
return - V_73 ;
}
}
}
F_8 ( V_87 ) ;
return 0 ;
}
int
F_44 ( T_1 V_39 , T_2 V_93 )
{
struct V_7 * V_66 ;
struct V_38 * V_40 ;
struct V_56 * V_57 ;
struct V_28 * V_85 ;
struct V_28 * V_86 ;
int V_70 = - V_94 ;
struct V_28 * V_42 ;
int V_95 = 0 ;
F_5 ( V_13 , L_8 ,
F_33 ( V_39 ) , F_6 ( V_93 ) ) ;
F_9 ( V_80 ) ;
if ( V_39 == F_26 ( V_71 ) )
V_42 = & V_32 . V_90 [ 0 ] ;
else
V_42 = F_21 ( V_39 ) ;
V_96:
F_22 (e1, rn_list) {
V_40 = F_13 ( V_85 , struct V_38 , V_44 ) ;
if ( ! ( V_39 == F_26 ( V_71 ) ||
V_39 == V_40 -> V_45 ) )
continue;
F_22 (e2, &rnet->lrn_routes) {
V_57 = F_13 ( V_86 , struct V_56 , V_61 ) ;
V_66 = V_57 -> V_63 ;
if ( ! ( V_93 == V_71 ||
V_93 == V_66 -> V_21 ) )
continue;
F_18 ( & V_57 -> V_61 ) ;
F_18 ( & V_57 -> V_62 ) ;
V_32 . V_64 ++ ;
if ( F_17 ( & V_40 -> V_76 ) )
F_18 ( & V_40 -> V_44 ) ;
else
V_40 = NULL ;
F_16 ( V_66 ) ;
F_19 ( V_66 ) ;
F_8 ( V_80 ) ;
F_37 ( V_57 , sizeof( * V_57 ) ) ;
if ( V_40 )
F_37 ( V_40 , sizeof( * V_40 ) ) ;
V_70 = 0 ;
F_9 ( V_80 ) ;
goto V_96;
}
}
if ( V_39 == F_26 ( V_71 ) &&
++ V_95 < V_89 ) {
V_42 = & V_32 . V_90 [ V_95 ] ;
goto V_96;
}
F_8 ( V_80 ) ;
return V_70 ;
}
void
F_45 ( void )
{
F_44 ( F_26 ( V_71 ) , V_71 ) ;
}
int F_46 ( int V_95 , struct V_97 * V_98 )
{
int V_88 , V_70 = - V_94 , V_99 ;
if ( ! V_32 . V_100 )
return V_70 ;
for ( V_88 = 0 ; V_88 < V_101 ; V_88 ++ ) {
struct V_102 * V_103 ;
F_9 ( V_80 ) ;
F_47 (rbp, j, the_lnet.ln_rtrpools) {
if ( V_88 ++ != V_95 )
continue;
V_98 -> V_104 [ V_88 ] . V_105 = V_103 [ V_88 ] . V_106 ;
V_98 -> V_104 [ V_88 ] . V_107 = V_103 [ V_88 ] . V_108 ;
V_98 -> V_104 [ V_88 ] . V_109 = V_103 [ V_88 ] . V_110 ;
V_98 -> V_104 [ V_88 ] . V_111 = V_103 [ V_88 ] . V_112 ;
V_70 = 0 ;
break;
}
F_8 ( V_80 ) ;
}
F_9 ( V_80 ) ;
V_98 -> V_113 = V_32 . V_114 ;
F_8 ( V_80 ) ;
return V_70 ;
}
int
F_48 ( int V_95 , T_1 * V_39 , T_1 * V_65 ,
T_2 * V_66 , T_1 * V_10 , T_1 * V_67 )
{
struct V_28 * V_85 ;
struct V_28 * V_86 ;
struct V_38 * V_40 ;
struct V_56 * V_57 ;
int V_87 ;
int V_88 ;
struct V_28 * V_42 ;
V_87 = F_43 () ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ ) {
V_42 = & V_32 . V_90 [ V_88 ] ;
F_22 (e1, rn_list) {
V_40 = F_13 ( V_85 , struct V_38 , V_44 ) ;
F_22 (e2, &rnet->lrn_routes) {
V_57 = F_13 ( V_86 , struct V_56 ,
V_61 ) ;
if ( ! V_95 -- ) {
* V_39 = V_40 -> V_45 ;
* V_65 = V_57 -> V_77 ;
* V_67 = V_57 -> V_79 ;
* V_66 = V_57 -> V_63 -> V_21 ;
* V_10 = F_49 ( V_57 ) ;
F_8 ( V_87 ) ;
return 0 ;
}
}
}
}
F_8 ( V_87 ) ;
return - V_94 ;
}
void
F_50 ( struct V_115 * V_116 )
{
int V_88 ;
struct V_117 * V_118 ;
F_51 ( & V_116 -> V_119 ) ;
F_51 ( & V_116 -> V_120 ) ;
F_51 ( & V_116 -> V_121 ) ;
F_51 ( & V_116 -> V_122 ) ;
for ( V_88 = 0 ; V_88 < V_116 -> V_122 && V_88 < V_123 ; V_88 ++ ) {
V_118 = & V_116 -> V_124 [ V_88 ] ;
F_52 ( & V_118 -> V_125 ) ;
F_51 ( & V_118 -> V_126 ) ;
}
}
static void
F_53 ( struct V_127 * V_128 )
{
struct V_115 * V_116 = V_128 -> V_129 ;
struct V_7 * V_130 = V_128 -> V_131 ;
struct V_56 * V_132 ;
if ( ! V_130 -> V_16 )
return;
if ( V_116 -> V_119 == F_54 ( V_133 ) )
F_50 ( V_116 ) ;
if ( V_116 -> V_119 != V_133 ) {
F_5 ( V_13 , L_9 ,
F_6 ( V_130 -> V_21 ) , V_116 -> V_119 ) ;
V_130 -> V_19 = V_20 ;
return;
}
V_130 -> V_19 = V_116 -> V_120 ;
if ( ! ( V_130 -> V_19 & V_134 ) ) {
F_5 ( V_13 , L_10 ,
F_6 ( V_130 -> V_21 ) , V_130 -> V_19 ) ;
return;
}
if ( ! ( V_130 -> V_19 & V_135 ) )
return;
F_55 (rte, &gw->lp_routes, lr_gwlist) {
int V_136 = 0 ;
int V_137 = 0 ;
int V_88 ;
if ( V_130 -> V_19 & V_138 ) {
V_132 -> V_139 = 1 ;
continue;
}
for ( V_88 = 0 ; V_88 < V_116 -> V_122 && V_88 < V_123 ; V_88 ++ ) {
struct V_117 * V_118 = & V_116 -> V_124 [ V_88 ] ;
T_2 V_140 = V_118 -> V_125 ;
if ( V_140 == V_71 ) {
F_5 ( V_13 , L_11 ,
F_6 ( V_130 -> V_21 ) ) ;
V_130 -> V_19 = V_20 ;
return;
}
if ( F_25 ( F_26 ( V_140 ) ) == V_53 )
continue;
if ( V_118 -> V_126 == V_141 ) {
V_136 ++ ;
continue;
}
if ( V_118 -> V_126 == V_142 ) {
if ( F_26 ( V_140 ) == V_132 -> V_78 ) {
V_137 = 1 ;
break;
}
continue;
}
F_5 ( V_13 , L_12 ,
F_6 ( V_130 -> V_21 ) , V_118 -> V_126 ) ;
V_130 -> V_19 = V_20 ;
return;
}
if ( V_137 ) {
V_132 -> V_139 = 0 ;
continue;
}
if ( ! V_136 && V_132 -> V_77 == 1 )
V_136 = 1 ;
V_132 -> V_139 = V_136 ;
}
}
static void
F_56 ( struct V_143 * V_144 )
{
struct V_127 * V_128 = V_144 -> V_145 . V_146 ;
struct V_7 * V_8 ;
F_11 ( V_128 ) ;
if ( V_144 -> V_147 ) {
F_57 ( & V_128 -> V_148 ) ;
return;
}
F_11 ( V_144 -> type == V_149 ||
V_144 -> type == V_150 ) ;
V_8 = V_128 -> V_131 ;
F_11 ( V_8 ) ;
F_9 ( V_8 -> V_25 ) ;
if ( ! F_58 ( V_8 ) || V_8 -> V_35 != V_128 ) {
goto V_151;
}
if ( V_144 -> type == V_149 ) {
V_8 -> V_152 = 0 ;
if ( ! V_144 -> V_153 )
goto V_151;
}
F_3 ( V_8 , 1 , ! V_144 -> V_153 , F_59 () ) ;
if ( V_154 && ! V_144 -> V_153 )
F_53 ( V_128 ) ;
V_151:
F_8 ( V_8 -> V_25 ) ;
}
static void
F_60 ( void )
{
struct V_7 * V_30 ;
struct V_28 * V_155 ;
int V_156 ;
F_11 ( V_32 . V_157 == V_158 ) ;
for (; ; ) {
int V_87 = F_43 () ;
V_156 = 1 ;
F_22 (entry, &the_lnet.ln_routers) {
V_30 = F_13 ( V_155 , struct V_7 , V_31 ) ;
if ( ! V_30 -> V_15 ) {
V_156 = 0 ;
break;
}
}
F_8 ( V_87 ) ;
if ( V_156 )
return;
F_61 ( V_159 ) ;
F_62 ( F_63 ( 1 ) ) ;
}
}
void
F_64 ( struct V_7 * V_130 , T_1 V_39 )
{
struct V_56 * V_132 ;
if ( ( V_130 -> V_19 & V_135 ) ) {
F_55 (rte, &gw->lp_routes, lr_gwlist) {
if ( V_132 -> V_78 == V_39 ) {
V_132 -> V_139 = 0 ;
break;
}
}
}
}
static void
F_65 ( void )
{
struct V_1 * V_2 ;
T_3 V_160 ;
int V_161 ;
F_11 ( V_32 . V_114 ) ;
V_161 = V_162 +
F_66 ( V_163 , V_164 ) ;
V_160 = F_67 () ;
F_55 (ni, &the_lnet.ln_nis, ni_list) {
if ( V_2 -> V_23 -> V_47 == V_53 )
continue;
if ( V_160 < V_2 -> V_165 + V_161 )
continue;
F_68 ( V_2 ) ;
if ( V_160 < V_2 -> V_165 + V_161 ) {
F_69 ( V_2 ) ;
continue;
}
F_11 ( V_2 -> V_166 ) ;
if ( V_2 -> V_166 -> V_126 != V_141 ) {
F_5 ( V_13 , L_13 ,
F_6 ( V_2 -> V_52 ) , V_161 ) ;
V_2 -> V_166 -> V_126 = V_141 ;
}
F_69 ( V_2 ) ;
}
}
static void
F_70 ( struct V_127 * V_128 )
{
F_11 ( F_17 ( & V_128 -> V_36 ) ) ;
F_11 ( F_71 ( V_128 -> V_148 ) ) ;
if ( V_128 -> V_131 ) {
int V_87 = V_128 -> V_131 -> V_25 ;
F_9 ( V_87 ) ;
F_19 ( V_128 -> V_131 ) ;
F_8 ( V_87 ) ;
}
if ( V_128 -> V_129 )
F_37 ( V_128 -> V_129 , V_167 ) ;
F_37 ( V_128 , sizeof( * V_128 ) ) ;
}
static struct V_127 *
F_72 ( struct V_7 * V_66 )
{
struct V_127 * V_128 = NULL ;
struct V_115 * V_168 ;
struct V_169 V_145 ;
int V_70 ;
int V_88 ;
F_8 ( V_66 -> V_25 ) ;
F_35 ( V_128 , sizeof( * V_128 ) ) ;
if ( ! V_128 )
goto V_151;
F_57 ( & V_128 -> V_148 ) ;
F_38 ( & V_128 -> V_36 ) ;
F_35 ( V_168 , V_167 ) ;
if ( ! V_168 )
goto V_151;
for ( V_88 = 0 ; V_88 < V_123 ; V_88 ++ ) {
V_168 -> V_124 [ V_88 ] . V_125 = V_71 ;
V_168 -> V_124 [ V_88 ] . V_126 = V_170 ;
}
V_128 -> V_129 = V_168 ;
V_145 . V_171 = V_168 ;
V_145 . V_146 = V_128 ;
V_145 . V_172 = V_167 ;
V_145 . V_173 = V_174 ;
V_145 . V_175 = V_176 ;
V_145 . V_177 = V_32 . V_178 ;
F_11 ( ! F_73 ( V_32 . V_178 ) ) ;
V_70 = F_74 ( V_145 , V_179 , & V_128 -> V_148 ) ;
if ( V_70 < 0 ) {
F_36 ( L_14 , V_70 ) ;
goto V_151;
}
F_11 ( ! V_70 ) ;
F_9 ( V_66 -> V_25 ) ;
if ( ! F_58 ( V_66 ) || V_66 -> V_35 ) {
F_8 ( V_66 -> V_25 ) ;
goto V_151;
}
F_15 ( V_66 ) ;
V_128 -> V_131 = V_66 ;
V_66 -> V_35 = V_128 ;
V_66 -> V_152 = 0 ;
return V_128 ;
V_151:
if ( V_128 ) {
if ( ! F_71 ( V_128 -> V_148 ) ) {
V_70 = F_75 ( V_128 -> V_148 ) ;
F_11 ( ! V_70 ) ;
}
F_70 ( V_128 ) ;
}
F_9 ( V_66 -> V_25 ) ;
return V_66 -> V_35 ;
}
static int
F_76 ( struct V_7 * V_30 )
{
int V_180 ;
V_180 = V_30 -> V_16 ? V_163 :
V_164 ;
if ( V_180 < 0 )
V_180 = 0 ;
return V_180 ;
}
static void
F_77 ( struct V_7 * V_30 )
{
struct V_127 * V_128 = NULL ;
unsigned long V_160 = F_59 () ;
int V_180 ;
F_15 ( V_30 ) ;
if ( V_30 -> V_14 &&
F_78 ( V_160 , V_30 -> V_14 ) )
F_3 ( V_30 , 1 , 0 , V_160 ) ;
F_7 ( V_30 -> V_83 , V_30 ) ;
if ( ! F_58 ( V_30 ) ||
V_32 . V_157 != V_158 ) {
F_19 ( V_30 ) ;
return;
}
V_128 = V_30 -> V_35 ?
V_30 -> V_35 : F_72 ( V_30 ) ;
if ( ! V_128 )
return;
V_180 = F_76 ( V_30 ) ;
F_5 ( V_13 ,
L_15 ,
F_6 ( V_30 -> V_21 ) , V_180 ,
V_30 -> V_14 , V_30 -> V_152 ,
V_30 -> V_16 , V_30 -> V_15 , V_30 -> V_181 ) ;
if ( V_180 && ! V_30 -> V_152 &&
F_78 ( V_160 , F_79 ( V_30 -> V_181 ,
F_63 ( V_180 ) ) ) ) {
int V_70 ;
struct V_182 V_183 ;
struct V_184 V_185 ;
V_183 . V_140 = V_30 -> V_21 ;
V_183 . V_186 = V_187 ;
F_5 ( V_13 , L_16 , F_80 ( V_183 ) ) ;
V_30 -> V_152 = 1 ;
V_30 -> V_181 = V_160 ;
V_185 = V_128 -> V_148 ;
if ( ! V_30 -> V_14 ) {
V_30 -> V_14 =
F_81 ( V_162 ) ;
}
F_8 ( V_30 -> V_25 ) ;
V_70 = F_82 ( V_71 , V_185 , V_183 , V_188 ,
V_189 , 0 ) ;
F_9 ( V_30 -> V_25 ) ;
if ( V_70 )
V_30 -> V_152 = 0 ;
}
F_19 ( V_30 ) ;
}
int
F_83 ( void )
{
struct V_190 * V_191 ;
int V_70 ;
int V_192 = 0 ;
F_11 ( V_32 . V_157 == V_193 ) ;
if ( V_6 &&
V_164 <= 0 ) {
F_84 ( 0x10a , L_17 ) ;
return - V_73 ;
}
F_85 ( & V_32 . V_194 ) ;
V_70 = F_86 ( 0 , F_56 , & V_32 . V_178 ) ;
if ( V_70 ) {
F_36 ( L_18 , V_192 , V_70 ) ;
return - V_75 ;
}
V_32 . V_157 = V_158 ;
V_191 = F_87 ( V_195 , NULL , L_19 ) ;
if ( F_88 ( V_191 ) ) {
V_70 = F_89 ( V_191 ) ;
F_36 ( L_20 , V_70 ) ;
F_90 ( & V_32 . V_194 ) ;
V_70 = F_91 ( V_32 . V_178 ) ;
F_11 ( ! V_70 ) ;
V_32 . V_157 = V_193 ;
return - V_75 ;
}
if ( V_6 ) {
F_60 () ;
}
return 0 ;
}
void
F_92 ( void )
{
int V_70 ;
if ( V_32 . V_157 == V_193 )
return;
F_11 ( V_32 . V_157 == V_158 ) ;
V_32 . V_157 = V_196 ;
F_41 ( & V_32 . V_84 ) ;
F_90 ( & V_32 . V_194 ) ;
F_11 ( V_32 . V_157 == V_193 ) ;
V_70 = F_91 ( V_32 . V_178 ) ;
F_11 ( ! V_70 ) ;
}
static void
F_93 ( int V_197 )
{
struct V_127 * V_128 ;
struct V_127 * V_41 ;
struct V_7 * V_8 ;
struct V_28 V_198 ;
int V_88 = 2 ;
if ( F_94 ( V_32 . V_157 == V_158 &&
F_17 ( & V_32 . V_37 ) &&
F_17 ( & V_32 . V_199 ) ) )
return;
F_38 ( & V_198 ) ;
F_9 ( V_80 ) ;
if ( V_32 . V_157 != V_158 ) {
F_55 (lp, &the_lnet.ln_routers,
lp_rtr_list) {
if ( ! V_8 -> V_35 )
continue;
F_11 ( F_17 ( & V_8 -> V_35 -> V_36 ) ) ;
F_14 ( & V_8 -> V_35 -> V_36 ,
& V_32 . V_37 ) ;
V_8 -> V_35 = NULL ;
}
}
F_95 ( & V_32 . V_37 , & V_198 ) ;
if ( ! F_17 ( & V_198 ) ) {
F_8 ( V_80 ) ;
F_55 (rcd, &head, rcd_list)
F_75 ( V_128 -> V_148 ) ;
F_9 ( V_80 ) ;
}
F_95 ( & V_198 , & V_32 . V_199 ) ;
while ( ! F_17 ( & V_32 . V_199 ) ) {
F_96 (rcd, tmp, &the_lnet.ln_rcd_zombie,
rcd_list) {
if ( F_71 ( V_128 -> V_148 ) )
F_97 ( & V_128 -> V_36 , & V_198 ) ;
}
V_197 = V_197 &&
! F_17 ( & V_32 . V_199 ) ;
F_8 ( V_80 ) ;
while ( ! F_17 ( & V_198 ) ) {
V_128 = F_13 ( V_198 . V_200 ,
struct V_127 , V_36 ) ;
F_98 ( & V_128 -> V_36 ) ;
F_70 ( V_128 ) ;
}
if ( ! V_197 )
return;
V_88 ++ ;
F_5 ( ( ( V_88 & ( - V_88 ) ) == V_88 ) ? V_201 : V_13 ,
L_21 ) ;
F_61 ( V_159 ) ;
F_62 ( F_63 ( 1 ) / 4 ) ;
F_9 ( V_80 ) ;
}
F_8 ( V_80 ) ;
}
static inline bool
F_99 ( void )
{
if ( V_32 . V_157 != V_158 )
return true ;
if ( V_32 . V_114 )
return true ;
return ! F_17 ( & V_32 . V_202 ) &&
( V_163 > 0 ||
V_164 > 0 ) ;
}
static int
V_195 ( void * V_203 )
{
struct V_7 * V_30 ;
struct V_28 * V_155 ;
F_100 () ;
while ( V_32 . V_157 == V_158 ) {
T_4 V_204 ;
int V_87 ;
int V_205 ;
V_87 = F_43 () ;
V_206:
V_204 = V_32 . V_33 ;
F_22 (entry, &the_lnet.ln_routers) {
V_30 = F_13 ( V_155 , struct V_7 , V_31 ) ;
V_205 = F_101 ( V_30 -> V_21 ) ;
if ( V_87 != V_205 ) {
F_8 ( V_87 ) ;
V_87 = V_205 ;
F_9 ( V_87 ) ;
if ( V_204 != V_32 . V_33 )
goto V_206;
}
F_77 ( V_30 ) ;
if ( V_204 != V_32 . V_33 ) {
goto V_206;
}
}
if ( V_32 . V_114 )
F_65 () ;
F_8 ( V_87 ) ;
F_93 ( 0 ) ;
if ( ! F_99 () )
F_102 ( V_32 . V_84 ,
F_99 () ) ;
else
F_103 ( V_32 . V_84 ,
false ,
F_63 ( 1 ) ) ;
}
F_93 ( 1 ) ;
V_32 . V_157 = V_193 ;
F_104 ( & V_32 . V_194 ) ;
return 0 ;
}
void
F_105 ( struct V_207 * V_208 , int V_209 )
{
int V_210 = F_106 ( struct V_207 , V_211 [ V_209 ] ) ;
while ( -- V_209 >= 0 )
F_107 ( V_208 -> V_211 [ V_209 ] . V_212 ) ;
F_37 ( V_208 , V_210 ) ;
}
static struct V_207 *
F_108 ( struct V_102 * V_103 , int V_87 )
{
int V_209 = V_103 -> V_106 ;
int V_210 = F_106 ( struct V_207 , V_211 [ V_209 ] ) ;
struct V_213 * V_213 ;
struct V_207 * V_208 ;
int V_88 ;
F_109 ( V_208 , F_110 () , V_87 , V_210 ) ;
if ( ! V_208 )
return NULL ;
V_208 -> V_214 = V_103 ;
for ( V_88 = 0 ; V_88 < V_209 ; V_88 ++ ) {
V_213 = F_111 (
F_112 ( F_110 () , V_87 ) ,
V_215 | V_216 , 0 ) ;
if ( ! V_213 ) {
while ( -- V_88 >= 0 )
F_107 ( V_208 -> V_211 [ V_88 ] . V_212 ) ;
F_37 ( V_208 , V_210 ) ;
return NULL ;
}
V_208 -> V_211 [ V_88 ] . V_217 = V_218 ;
V_208 -> V_211 [ V_88 ] . V_219 = 0 ;
V_208 -> V_211 [ V_88 ] . V_212 = V_213 ;
}
return V_208 ;
}
static void
F_113 ( struct V_102 * V_103 , int V_87 )
{
int V_209 = V_103 -> V_106 ;
struct V_28 V_41 ;
struct V_207 * V_208 ;
struct V_207 * V_220 ;
if ( ! V_103 -> V_108 )
return;
F_38 ( & V_41 ) ;
F_9 ( V_87 ) ;
F_114 ( & V_103 -> V_221 , V_87 ) ;
F_95 ( & V_103 -> V_222 , & V_41 ) ;
V_103 -> V_223 = 0 ;
V_103 -> V_108 = 0 ;
V_103 -> V_110 = 0 ;
V_103 -> V_112 = 0 ;
F_8 ( V_87 ) ;
F_96 (rb, temp, &tmp, rb_list) {
F_18 ( & V_208 -> V_224 ) ;
F_105 ( V_208 , V_209 ) ;
}
}
static int
F_115 ( struct V_102 * V_103 , int V_225 , int V_87 )
{
struct V_28 V_224 ;
struct V_207 * V_208 ;
int V_226 ;
int V_227 = 0 ;
int V_228 ;
int V_209 = V_103 -> V_106 ;
F_9 ( V_87 ) ;
V_226 = V_225 - V_103 -> V_108 ;
if ( V_225 <= V_103 -> V_223 || V_226 <= 0 ) {
V_103 -> V_223 = V_225 ;
F_8 ( V_87 ) ;
return 0 ;
}
V_228 = V_103 -> V_223 ;
V_103 -> V_223 = V_225 ;
F_8 ( V_87 ) ;
F_38 ( & V_224 ) ;
while ( V_226 -- > 0 ) {
V_208 = F_108 ( V_103 , V_87 ) ;
if ( ! V_208 ) {
F_36 ( L_22 ,
V_225 , V_209 ) ;
F_9 ( V_87 ) ;
V_103 -> V_223 = V_228 ;
F_8 ( V_87 ) ;
goto V_229;
}
F_14 ( & V_208 -> V_224 , & V_224 ) ;
V_227 ++ ;
}
F_9 ( V_87 ) ;
F_116 ( & V_224 , & V_103 -> V_222 ) ;
V_103 -> V_108 += V_227 ;
V_103 -> V_110 += V_227 ;
V_103 -> V_112 = V_103 -> V_110 ;
while ( ! F_17 ( & V_103 -> V_222 ) &&
! F_17 ( & V_103 -> V_221 ) )
F_117 ( V_103 ) ;
F_8 ( V_87 ) ;
return 0 ;
V_229:
while ( ! F_17 ( & V_224 ) ) {
V_208 = F_13 ( V_224 . V_200 , struct V_207 , V_224 ) ;
F_18 ( & V_208 -> V_224 ) ;
F_105 ( V_208 , V_209 ) ;
}
return - V_75 ;
}
static void
F_118 ( struct V_102 * V_103 , int V_209 )
{
F_38 ( & V_103 -> V_221 ) ;
F_38 ( & V_103 -> V_222 ) ;
V_103 -> V_106 = V_209 ;
V_103 -> V_110 = 0 ;
V_103 -> V_112 = 0 ;
}
void
F_119 ( int V_230 )
{
struct V_102 * V_231 ;
int V_88 ;
if ( ! V_32 . V_100 )
return;
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
F_113 ( & V_231 [ V_232 ] , V_88 ) ;
F_113 ( & V_231 [ V_233 ] , V_88 ) ;
F_113 ( & V_231 [ V_234 ] , V_88 ) ;
}
if ( ! V_230 ) {
F_120 ( V_32 . V_100 ) ;
V_32 . V_100 = NULL ;
}
}
static int
F_121 ( void )
{
int V_235 = V_236 ;
if ( V_237 < 0 ) {
F_84 ( 0x10c ,
L_23 ,
V_237 ) ;
return - V_73 ;
}
if ( V_237 > 0 )
V_235 = V_237 ;
V_235 /= V_238 ;
return F_66 ( V_235 , V_239 ) ;
}
static int
F_122 ( void )
{
int V_235 = V_240 ;
if ( V_241 < 0 ) {
F_84 ( 0x10c ,
L_24 ,
V_241 ) ;
return - V_73 ;
}
if ( V_241 > 0 )
V_235 = V_241 ;
V_235 /= V_238 ;
return F_66 ( V_235 , V_242 ) ;
}
static int
F_123 ( void )
{
int V_235 = V_243 ;
if ( V_244 < 0 ) {
F_84 ( 0x10c ,
L_25 ,
V_244 ) ;
return - V_73 ;
}
if ( V_244 > 0 )
V_235 = V_244 ;
V_235 /= V_238 ;
return F_66 ( V_235 , V_245 ) ;
}
int
F_124 ( int V_246 )
{
struct V_102 * V_231 ;
int V_247 ;
int V_248 ;
int V_249 ;
int V_70 ;
int V_88 ;
if ( ! strcmp ( V_250 , L_26 ) ) {
if ( ! V_246 )
return 0 ;
} else if ( ! strcmp ( V_250 , L_27 ) ) {
return 0 ;
} else if ( ! strcmp ( V_250 , L_28 ) ) {
} else {
F_84 ( 0x10b , L_29 ) ;
return - V_73 ;
}
V_247 = F_121 () ;
if ( V_247 < 0 )
return - V_73 ;
V_248 = F_122 () ;
if ( V_248 < 0 )
return - V_73 ;
V_249 = F_123 () ;
if ( V_249 < 0 )
return - V_73 ;
V_32 . V_100 = F_125 ( F_110 () ,
V_101 *
sizeof( struct V_102 ) ) ;
if ( ! V_32 . V_100 ) {
F_84 ( 0x10c ,
L_30 ) ;
return - V_75 ;
}
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
F_118 ( & V_231 [ V_232 ] , 0 ) ;
V_70 = F_115 ( & V_231 [ V_232 ] ,
V_247 , V_88 ) ;
if ( V_70 )
goto V_229;
F_118 ( & V_231 [ V_233 ] ,
V_251 ) ;
V_70 = F_115 ( & V_231 [ V_233 ] ,
V_248 , V_88 ) ;
if ( V_70 )
goto V_229;
F_118 ( & V_231 [ V_234 ] ,
V_252 ) ;
V_70 = F_115 ( & V_231 [ V_234 ] ,
V_249 , V_88 ) ;
if ( V_70 )
goto V_229;
}
F_9 ( V_80 ) ;
V_32 . V_114 = 1 ;
F_8 ( V_80 ) ;
return 0 ;
V_229:
F_119 ( 0 ) ;
return V_70 ;
}
static int
F_126 ( int V_253 , int V_254 , int V_255 )
{
int V_256 = 0 ;
int V_70 = 0 ;
int V_88 ;
struct V_102 * V_231 ;
if ( V_253 >= 0 ) {
V_237 = V_253 ;
V_256 = F_121 () ;
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
V_70 = F_115 ( & V_231 [ V_232 ] ,
V_256 , V_88 ) ;
if ( V_70 )
return V_70 ;
}
}
if ( V_254 >= 0 ) {
V_241 = V_254 ;
V_256 = F_122 () ;
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
V_70 = F_115 ( & V_231 [ V_233 ] ,
V_256 , V_88 ) ;
if ( V_70 )
return V_70 ;
}
}
if ( V_255 >= 0 ) {
V_244 = V_255 ;
V_256 = F_123 () ;
F_47 (rtrp, i, the_lnet.ln_rtrpools) {
V_70 = F_115 ( & V_231 [ V_234 ] ,
V_256 , V_88 ) ;
if ( V_70 )
return V_70 ;
}
}
return 0 ;
}
int
F_127 ( int V_253 , int V_254 , int V_255 )
{
if ( ! V_32 . V_114 )
return 0 ;
return F_126 ( V_253 , V_254 , V_255 ) ;
}
int
F_128 ( void )
{
int V_70 = 0 ;
if ( V_32 . V_114 )
return 0 ;
if ( ! V_32 . V_100 )
V_70 = F_124 ( 1 ) ;
else
V_70 = F_126 ( 0 , 0 , 0 ) ;
if ( V_70 )
return V_70 ;
F_9 ( V_80 ) ;
V_32 . V_114 = 1 ;
V_32 . V_257 -> V_120 &= ~ V_138 ;
F_8 ( V_80 ) ;
return V_70 ;
}
void
F_129 ( void )
{
if ( ! V_32 . V_114 )
return;
F_9 ( V_80 ) ;
V_32 . V_114 = 0 ;
V_32 . V_257 -> V_120 |= V_138 ;
V_237 = 0 ;
V_241 = 0 ;
V_244 = 0 ;
F_8 ( V_80 ) ;
F_119 ( 1 ) ;
}
int
F_130 ( struct V_1 * V_2 , T_2 V_140 , int V_10 , unsigned long V_11 )
{
struct V_7 * V_8 = NULL ;
unsigned long V_160 = F_59 () ;
int V_87 = F_131 ( V_140 ) ;
F_11 ( ! F_132 () ) ;
F_5 ( V_13 , L_31 ,
! V_2 ? L_32 : F_6 ( V_2 -> V_52 ) ,
F_6 ( V_140 ) ,
V_10 ? L_33 : L_34 ) ;
if ( V_2 &&
F_26 ( V_2 -> V_52 ) != F_26 ( V_140 ) ) {
F_133 ( L_35 ,
F_6 ( V_140 ) , V_10 ? L_36 : L_37 ,
F_6 ( V_2 -> V_52 ) ) ;
return - V_73 ;
}
if ( F_78 ( V_11 , V_160 ) ) {
F_133 ( L_38 ,
! V_2 ? L_32 : F_6 ( V_2 -> V_52 ) ,
F_6 ( V_140 ) , V_10 ? L_33 : L_34 ,
F_134 ( F_135 ( V_11 , V_160 ) ) ) ;
return - V_73 ;
}
if ( V_2 && ! V_10 &&
! V_258 ) {
F_5 ( V_13 , L_39 ) ;
return 0 ;
}
F_9 ( V_87 ) ;
if ( V_32 . V_43 ) {
F_8 ( V_87 ) ;
return - V_259 ;
}
V_8 = F_136 ( V_32 . V_260 [ V_87 ] , V_140 ) ;
if ( ! V_8 ) {
F_8 ( V_87 ) ;
F_5 ( V_13 , L_40 , F_6 ( V_140 ) ) ;
return 0 ;
}
if ( V_2 && ! V_10 && V_11 < V_8 -> V_261 )
V_11 = V_8 -> V_261 ;
F_3 ( V_8 , ! V_2 , V_10 , V_11 ) ;
if ( V_2 )
F_7 ( V_2 , V_8 ) ;
F_19 ( V_8 ) ;
F_8 ( V_87 ) ;
return 0 ;
}
