static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 V_7 ;
void T_1 * * V_8 ;
F_2 (lut, ln, &ctx->handles_list, ctx_link) {
F_3 ( & V_4 -> V_9 ) ;
F_4 ( V_2 -> V_10 -> V_11 , V_4 ) ;
}
F_5 () ;
F_6 (slot, &ctx->handles_vma, &iter, 0 ) {
struct V_12 * V_13 = F_7 ( * V_8 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_8 ( & V_2 -> V_16 , & V_7 , V_8 ) ;
if ( ! F_9 ( V_13 ) )
F_10 ( V_13 ) ;
F_11 ( V_15 ) ;
}
F_12 () ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_17 ;
F_14 ( & V_2 -> V_10 -> V_18 . V_19 ) ;
F_15 ( ! F_16 ( V_2 ) ) ;
F_17 ( V_2 -> V_20 ) ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
struct V_22 * V_23 = & V_2 -> V_24 [ V_17 ] ;
if ( ! V_23 -> V_25 )
continue;
F_18 ( V_23 -> V_26 ) ;
if ( V_23 -> V_27 )
F_19 ( V_23 -> V_27 ) ;
F_11 ( V_23 -> V_25 -> V_15 ) ;
}
F_20 ( V_2 -> V_28 ) ;
F_21 ( V_2 -> V_29 ) ;
F_3 ( & V_2 -> V_30 ) ;
F_22 ( & V_2 -> V_10 -> V_31 . V_32 , V_2 -> V_33 ) ;
F_23 ( V_2 , V_34 ) ;
}
static void F_24 ( struct V_35 * V_10 )
{
struct V_36 * V_37 = F_25 ( & V_10 -> V_31 . V_38 ) ;
struct V_1 * V_2 , * V_39 ;
F_14 ( & V_10 -> V_18 . V_19 ) ;
F_26 (ctx, cn, freed, free_link)
F_13 ( V_2 ) ;
}
static void F_27 ( struct V_35 * V_10 )
{
struct V_1 * V_2 ;
struct V_36 * V_37 ;
F_14 ( & V_10 -> V_18 . V_19 ) ;
V_37 = F_28 ( & V_10 -> V_31 . V_38 ) ;
if ( ! V_37 )
return;
V_2 = F_29 ( V_37 , F_30 ( * V_2 ) , V_40 ) ;
F_13 ( V_2 ) ;
}
static void F_31 ( struct V_41 * V_42 )
{
struct V_35 * V_10 =
F_29 ( V_42 , F_30 ( * V_10 ) , V_31 . V_43 ) ;
F_32 ( & V_10 -> V_18 . V_19 ) ;
F_24 ( V_10 ) ;
F_33 ( & V_10 -> V_18 . V_19 ) ;
}
void F_34 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_29 ( V_45 , F_30 ( * V_2 ) , V_45 ) ;
struct V_35 * V_10 = V_2 -> V_10 ;
F_35 ( V_2 ) ;
if ( F_36 ( & V_2 -> V_40 , & V_10 -> V_31 . V_38 ) )
F_37 ( V_10 -> V_46 , & V_10 -> V_31 . V_43 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_20 )
F_40 ( & V_2 -> V_20 -> V_47 ) ;
V_2 -> V_48 = F_41 ( - V_49 ) ;
F_42 ( V_2 ) ;
}
static int F_43 ( struct V_35 * V_50 , unsigned * V_51 )
{
int V_52 ;
V_52 = F_44 ( & V_50 -> V_31 . V_32 ,
0 , V_53 , V_54 ) ;
if ( V_52 < 0 ) {
F_45 ( V_50 ) ;
V_52 = F_44 ( & V_50 -> V_31 . V_32 ,
0 , V_53 , V_54 ) ;
if ( V_52 < 0 )
return V_52 ;
}
* V_51 = V_52 ;
return 0 ;
}
static T_2 F_46 ( const struct V_35 * V_10 ,
const struct V_55 * V_20 )
{
T_2 V_56 ;
T_2 V_57 ;
V_57 = V_58 | V_59 ;
V_56 = V_60 ;
if ( V_20 && F_47 ( & V_20 -> V_47 ) )
V_56 = V_61 ;
V_57 |= V_56 << V_62 ;
if ( F_48 ( V_10 ) )
V_57 |= V_63 ;
return V_57 ;
}
static struct V_1 *
F_49 ( struct V_35 * V_50 ,
struct V_64 * V_48 )
{
struct V_1 * V_2 ;
int V_52 ;
V_2 = F_50 ( sizeof( * V_2 ) , V_54 ) ;
if ( V_2 == NULL )
return F_41 ( - V_65 ) ;
V_52 = F_43 ( V_50 , & V_2 -> V_33 ) ;
if ( V_52 ) {
F_20 ( V_2 ) ;
return F_41 ( V_52 ) ;
}
F_51 ( & V_2 -> V_45 ) ;
F_52 ( & V_2 -> V_30 , & V_50 -> V_31 . V_66 ) ;
V_2 -> V_10 = V_50 ;
V_2 -> V_67 = V_68 ;
F_53 ( & V_2 -> V_16 , V_54 ) ;
F_54 ( & V_2 -> V_69 ) ;
V_52 = V_70 ;
if ( V_48 ) {
V_52 = F_55 ( & V_48 -> V_71 , V_2 ,
V_70 , 0 , V_54 ) ;
if ( V_52 < 0 )
goto V_72;
}
V_2 -> V_73 = V_52 ;
V_2 -> V_48 = V_48 ;
if ( V_48 ) {
V_2 -> V_29 = F_56 ( V_74 , V_75 ) ;
V_2 -> V_28 = F_57 ( V_54 , L_1 ,
V_74 -> V_76 ,
F_58 ( V_2 -> V_29 ) ,
V_2 -> V_73 ) ;
if ( ! V_2 -> V_28 ) {
V_52 = - V_65 ;
goto V_77;
}
}
V_2 -> V_78 = F_59 ( V_50 ) ;
F_60 ( V_2 ) ;
V_2 -> V_79 = 4 * V_80 ;
V_2 -> V_81 =
F_46 ( V_50 , V_50 -> V_82 . V_83 ) ;
if ( F_61 ( V_50 ) && V_10 . V_84 )
V_2 -> V_85 = V_86 ;
else
V_2 -> V_85 = V_87 ;
return V_2 ;
V_77:
F_21 ( V_2 -> V_29 ) ;
F_62 ( & V_48 -> V_71 , V_2 -> V_73 ) ;
V_72:
F_38 ( V_2 ) ;
return F_41 ( V_52 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_64 * V_48 )
{
F_62 ( & V_48 -> V_71 , V_2 -> V_73 ) ;
F_38 ( V_2 ) ;
}
static struct V_1 *
F_64 ( struct V_35 * V_50 ,
struct V_64 * V_48 )
{
struct V_1 * V_2 ;
F_14 ( & V_50 -> V_18 . V_19 ) ;
F_27 ( V_50 ) ;
V_2 = F_49 ( V_50 , V_48 ) ;
if ( F_65 ( V_2 ) )
return V_2 ;
if ( F_66 ( V_50 ) ) {
struct V_55 * V_20 ;
V_20 = F_67 ( V_50 , V_48 , V_2 -> V_28 ) ;
if ( F_65 ( V_20 ) ) {
F_68 ( L_2 ,
F_69 ( V_20 ) ) ;
F_63 ( V_2 , V_48 ) ;
return F_70 ( V_20 ) ;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_81 = F_46 ( V_50 , V_20 ) ;
}
F_71 ( V_2 ) ;
return V_2 ;
}
struct V_1 *
F_72 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
int V_52 ;
if ( ! F_73 ( V_90 ) )
return F_41 ( - V_91 ) ;
V_52 = F_74 ( V_89 ) ;
if ( V_52 )
return F_41 ( V_52 ) ;
V_2 = F_49 ( F_75 ( V_89 ) , NULL ) ;
if ( F_65 ( V_2 ) )
goto V_51;
V_2 -> V_48 = F_41 ( - V_49 ) ;
F_39 ( V_2 ) ;
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
if ( ! V_10 . V_92 )
V_2 -> V_79 = 512 * V_80 ;
F_15 ( F_78 ( V_2 ) ) ;
V_51:
F_33 ( & V_89 -> V_19 ) ;
return V_2 ;
}
int F_79 ( struct V_35 * V_50 )
{
struct V_1 * V_2 ;
if ( F_18 ( V_50 -> V_93 ) )
return 0 ;
F_54 ( & V_50 -> V_31 . V_66 ) ;
F_80 ( & V_50 -> V_31 . V_43 , F_31 ) ;
F_81 ( & V_50 -> V_31 . V_38 ) ;
if ( F_82 ( V_50 ) &&
F_83 ( V_50 ) ) {
if ( ! V_10 . V_94 ) {
F_84 ( L_3 ) ;
return - V_95 ;
}
}
F_85 ( V_53 > V_96 ) ;
F_86 ( & V_50 -> V_31 . V_32 ) ;
V_2 = F_64 ( V_50 , NULL ) ;
if ( F_65 ( V_2 ) ) {
F_87 ( L_4 ,
F_69 ( V_2 ) ) ;
return F_69 ( V_2 ) ;
}
F_15 ( V_2 -> V_33 ) ;
F_76 ( V_2 ) ;
V_2 -> V_67 = V_97 ;
V_50 -> V_93 = V_2 ;
F_15 ( ! F_78 ( V_2 ) ) ;
F_68 ( L_5 ,
V_50 -> V_24 [ V_98 ] -> V_99 ? L_6 :
L_7 ) ;
return 0 ;
}
void F_88 ( struct V_35 * V_50 )
{
struct V_100 * V_24 ;
enum V_101 V_102 ;
F_14 ( & V_50 -> V_18 . V_19 ) ;
F_89 (engine, dev_priv, id) {
V_24 -> V_103 = NULL ;
if ( ! V_24 -> V_104 )
continue;
V_24 -> V_105 ( V_24 , V_24 -> V_104 ) ;
V_24 -> V_104 = NULL ;
}
if ( ! V_10 . V_94 ) {
struct V_1 * V_2 ;
F_90 (ctx, &dev_priv->contexts.list, link) {
if ( ! F_91 ( V_2 ) )
continue;
F_89 (engine, dev_priv, id)
V_2 -> V_24 [ V_24 -> V_102 ] . V_106 = false ;
V_2 -> V_78 = F_59 ( V_50 ) ;
}
F_89 (engine, dev_priv, id) {
struct V_22 * V_107 =
& V_50 -> V_93 -> V_24 [ V_24 -> V_102 ] ;
V_107 -> V_106 = true ;
}
}
}
void F_92 ( struct V_35 * V_10 )
{
struct V_1 * V_2 ;
F_14 ( & V_10 -> V_18 . V_19 ) ;
V_2 = F_93 ( F_94 ( & V_10 -> V_93 ) ) ;
F_15 ( ! F_78 ( V_2 ) ) ;
F_38 ( V_2 ) ;
F_13 ( V_2 ) ;
F_95 ( & V_10 -> V_31 . V_32 ) ;
}
static int F_96 ( int V_102 , void * V_108 , void * V_109 )
{
struct V_1 * V_2 = V_108 ;
F_38 ( V_2 ) ;
return 0 ;
}
int F_97 ( struct V_35 * V_10 ,
struct V_110 * V_111 )
{
struct V_64 * V_48 = V_111 -> V_112 ;
struct V_1 * V_2 ;
F_98 ( & V_48 -> V_71 ) ;
F_32 ( & V_10 -> V_18 . V_19 ) ;
V_2 = F_64 ( V_10 , V_48 ) ;
F_33 ( & V_10 -> V_18 . V_19 ) ;
if ( F_65 ( V_2 ) ) {
F_99 ( & V_48 -> V_71 ) ;
return F_69 ( V_2 ) ;
}
F_15 ( F_78 ( V_2 ) ) ;
return 0 ;
}
void F_100 ( struct V_110 * V_111 )
{
struct V_64 * V_48 = V_111 -> V_112 ;
F_14 ( & V_48 -> V_50 -> V_18 . V_19 ) ;
F_101 ( & V_48 -> V_71 , F_96 , NULL ) ;
F_99 ( & V_48 -> V_71 ) ;
}
static inline int
F_102 ( struct V_113 * V_114 , T_2 V_115 )
{
struct V_35 * V_50 = V_114 -> V_10 ;
struct V_100 * V_24 = V_114 -> V_24 ;
enum V_101 V_102 ;
const int V_116 =
( V_10 . V_117 && F_103 ( V_50 ) == 7 ) ?
F_104 ( V_50 ) -> V_116 - 1 :
0 ;
int V_118 ;
T_2 * V_119 ;
V_115 |= V_120 ;
if ( F_105 ( V_50 ) || F_103 ( V_50 ) >= 8 )
V_115 |= V_121 | V_122 ;
else
V_115 |= V_123 | V_124 ;
V_118 = 4 ;
if ( F_103 ( V_50 ) >= 7 )
V_118 += 2 + ( V_116 ? 4 * V_116 + 6 : 0 ) ;
V_119 = F_106 ( V_114 , V_118 ) ;
if ( F_65 ( V_119 ) )
return F_69 ( V_119 ) ;
if ( F_103 ( V_50 ) >= 7 ) {
* V_119 ++ = V_125 | V_126 ;
if ( V_116 ) {
struct V_100 * V_127 ;
* V_119 ++ = F_107 ( V_116 ) ;
F_89 (signaller, dev_priv, id) {
if ( V_127 == V_24 )
continue;
* V_119 ++ = F_108 (
F_109 ( V_127 -> V_128 ) ) ;
* V_119 ++ = F_110 (
V_129 ) ;
}
}
}
* V_119 ++ = V_130 ;
* V_119 ++ = V_131 ;
* V_119 ++ = F_111 ( V_114 -> V_2 -> V_24 [ V_98 ] . V_25 ) | V_115 ;
* V_119 ++ = V_130 ;
if ( F_103 ( V_50 ) >= 7 ) {
if ( V_116 ) {
struct V_100 * V_127 ;
T_3 V_132 = {} ;
* V_119 ++ = F_107 ( V_116 ) ;
F_89 (signaller, dev_priv, id) {
if ( V_127 == V_24 )
continue;
V_132 = F_109 ( V_127 -> V_128 ) ;
* V_119 ++ = F_108 ( V_132 ) ;
* V_119 ++ = F_112 (
V_129 ) ;
}
* V_119 ++ = V_133 | V_134 ;
* V_119 ++ = F_108 ( V_132 ) ;
* V_119 ++ = F_111 ( V_24 -> V_135 ) ;
* V_119 ++ = V_130 ;
}
* V_119 ++ = V_125 | V_136 ;
}
F_113 ( V_114 , V_119 ) ;
return 0 ;
}
static int F_114 ( struct V_113 * V_114 , int V_137 )
{
T_2 * V_119 , * V_138 = V_114 -> V_10 -> V_139 . V_138 [ V_137 ] ;
int V_17 ;
if ( ! V_138 )
return 0 ;
V_119 = F_106 ( V_114 , V_140 / 4 * 2 + 2 ) ;
if ( F_65 ( V_119 ) )
return F_69 ( V_119 ) ;
* V_119 ++ = F_107 ( V_140 / 4 ) ;
for ( V_17 = 0 ; V_17 < V_140 / 4 ; V_17 ++ ) {
* V_119 ++ = F_108 ( F_115 ( V_137 , V_17 ) ) ;
* V_119 ++ = V_138 [ V_17 ] ;
}
* V_119 ++ = V_130 ;
F_113 ( V_114 , V_119 ) ;
return 0 ;
}
static inline bool F_116 ( struct V_55 * V_20 ,
struct V_100 * V_24 ,
struct V_1 * V_141 )
{
if ( V_141 -> V_78 )
return false ;
if ( ! V_141 -> V_24 [ V_98 ] . V_106 )
return false ;
if ( V_20 && ( F_117 ( V_24 ) & V_20 -> V_142 ) )
return false ;
return V_141 == V_24 -> V_103 ;
}
static bool
F_118 ( struct V_55 * V_20 , struct V_100 * V_24 )
{
struct V_1 * V_143 = V_24 -> V_103 ;
if ( ! V_20 )
return false ;
if ( ! V_143 )
return true ;
if ( ( ! V_143 -> V_20 || V_143 -> V_20 == V_20 ) &&
! ( F_117 ( V_24 ) & V_20 -> V_142 ) )
return false ;
if ( V_24 -> V_102 != V_98 )
return true ;
if ( F_103 ( V_24 -> V_10 ) < 8 )
return true ;
return false ;
}
static bool
F_119 ( struct V_55 * V_20 ,
struct V_1 * V_141 ,
T_2 V_144 )
{
if ( ! V_20 )
return false ;
if ( ! F_48 ( V_141 -> V_10 ) )
return false ;
if ( V_144 & V_145 )
return true ;
return false ;
}
static int F_120 ( struct V_113 * V_114 )
{
struct V_1 * V_141 = V_114 -> V_2 ;
struct V_100 * V_24 = V_114 -> V_24 ;
struct V_55 * V_20 = V_141 -> V_20 ? : V_114 -> V_10 -> V_82 . V_83 ;
struct V_1 * V_143 = V_24 -> V_103 ;
T_2 V_144 ;
int V_52 , V_17 ;
F_15 ( V_24 -> V_102 != V_98 ) ;
if ( F_116 ( V_20 , V_24 , V_141 ) )
return 0 ;
if ( F_118 ( V_20 , V_24 ) ) {
F_121 ( V_24 , V_141 ) ;
V_52 = V_20 -> V_146 ( V_20 , V_114 ) ;
if ( V_52 )
return V_52 ;
}
if ( ! V_141 -> V_24 [ V_98 ] . V_106 || F_91 ( V_141 ) )
V_144 = V_145 ;
else if ( V_20 && F_117 ( V_24 ) & V_20 -> V_142 )
V_144 = V_147 ;
else
V_144 = 0 ;
if ( V_141 != V_143 || ( V_144 & V_147 ) ) {
V_52 = F_102 ( V_114 , V_144 ) ;
if ( V_52 )
return V_52 ;
V_24 -> V_103 = V_141 ;
}
if ( F_119 ( V_20 , V_141 , V_144 ) ) {
F_121 ( V_24 , V_141 ) ;
V_52 = V_20 -> V_146 ( V_20 , V_114 ) ;
if ( V_52 )
return V_52 ;
}
if ( V_20 )
V_20 -> V_142 &= ~ F_117 ( V_24 ) ;
for ( V_17 = 0 ; V_17 < V_148 ; V_17 ++ ) {
if ( ! ( V_141 -> V_78 & ( 1 << V_17 ) ) )
continue;
V_52 = F_114 ( V_114 , V_17 ) ;
if ( V_52 )
return V_52 ;
V_141 -> V_78 &= ~ ( 1 << V_17 ) ;
}
if ( ! V_141 -> V_24 [ V_98 ] . V_106 ) {
if ( V_24 -> V_149 ) {
V_52 = V_24 -> V_149 ( V_114 ) ;
if ( V_52 )
return V_52 ;
}
V_141 -> V_24 [ V_98 ] . V_106 = true ;
}
return 0 ;
}
int F_122 ( struct V_113 * V_114 )
{
struct V_100 * V_24 = V_114 -> V_24 ;
F_14 ( & V_114 -> V_10 -> V_18 . V_19 ) ;
if ( V_10 . V_94 )
return 0 ;
if ( ! V_114 -> V_2 -> V_24 [ V_24 -> V_102 ] . V_25 ) {
struct V_1 * V_141 = V_114 -> V_2 ;
struct V_55 * V_20 =
V_141 -> V_20 ? : V_114 -> V_10 -> V_82 . V_83 ;
if ( F_118 ( V_20 , V_24 ) ) {
int V_52 ;
F_121 ( V_24 , V_141 ) ;
V_52 = V_20 -> V_146 ( V_20 , V_114 ) ;
if ( V_52 )
return V_52 ;
V_20 -> V_142 &= ~ F_117 ( V_24 ) ;
}
V_24 -> V_103 = V_141 ;
return 0 ;
}
return F_120 ( V_114 ) ;
}
static bool F_123 ( struct V_100 * V_24 )
{
struct V_150 * V_151 ;
F_90 (timeline, &engine->i915->gt.timelines, link) {
struct V_152 * V_153 ;
if ( V_151 == & V_24 -> V_10 -> V_154 . V_155 )
continue;
V_153 = & V_151 -> V_24 [ V_24 -> V_102 ] ;
if ( F_124 ( & V_153 -> V_156 ,
& V_24 -> V_10 -> V_18 . V_19 ) )
return false ;
}
return ( ! V_24 -> V_104 ||
F_78 ( V_24 -> V_104 ) ) ;
}
int F_125 ( struct V_35 * V_50 )
{
struct V_100 * V_24 ;
struct V_150 * V_151 ;
enum V_101 V_102 ;
F_14 ( & V_50 -> V_18 . V_19 ) ;
F_45 ( V_50 ) ;
F_89 (engine, dev_priv, id) {
struct V_113 * V_114 ;
int V_52 ;
if ( F_123 ( V_24 ) )
continue;
V_114 = F_126 ( V_24 , V_50 -> V_93 ) ;
if ( F_65 ( V_114 ) )
return F_69 ( V_114 ) ;
F_90 (timeline, &dev_priv->gt.timelines, link) {
struct V_113 * V_157 ;
struct V_152 * V_153 ;
V_153 = & V_151 -> V_24 [ V_24 -> V_102 ] ;
V_157 = F_127 ( & V_153 -> V_156 ,
& V_50 -> V_18 . V_19 ) ;
if ( V_157 )
F_128 ( & V_114 -> V_158 ,
& V_157 -> V_158 ,
V_54 ) ;
}
V_52 = F_122 ( V_114 ) ;
F_129 ( V_114 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static bool F_130 ( struct V_64 * V_48 )
{
return F_131 ( & V_48 -> V_159 ) > V_160 ;
}
int F_132 ( struct V_88 * V_89 , void * V_109 ,
struct V_110 * V_111 )
{
struct V_35 * V_50 = F_75 ( V_89 ) ;
struct V_161 * args = V_109 ;
struct V_64 * V_48 = V_111 -> V_112 ;
struct V_1 * V_2 ;
int V_52 ;
if ( ! V_50 -> V_24 [ V_98 ] -> V_99 )
return - V_91 ;
if ( args -> V_162 != 0 )
return - V_95 ;
if ( F_130 ( V_48 ) ) {
F_133 ( L_8 ,
V_74 -> V_76 ,
F_58 ( F_56 ( V_74 , V_75 ) ) ) ;
return - V_163 ;
}
V_52 = F_74 ( V_89 ) ;
if ( V_52 )
return V_52 ;
V_2 = F_64 ( V_50 , V_48 ) ;
F_33 ( & V_89 -> V_19 ) ;
if ( F_65 ( V_2 ) )
return F_69 ( V_2 ) ;
F_15 ( F_78 ( V_2 ) ) ;
args -> V_164 = V_2 -> V_73 ;
F_133 ( L_9 , args -> V_164 ) ;
return 0 ;
}
int F_134 ( struct V_88 * V_89 , void * V_109 ,
struct V_110 * V_111 )
{
struct V_165 * args = V_109 ;
struct V_64 * V_48 = V_111 -> V_112 ;
struct V_1 * V_2 ;
int V_52 ;
if ( args -> V_162 != 0 )
return - V_95 ;
if ( args -> V_164 == V_70 )
return - V_166 ;
V_2 = F_135 ( V_48 , args -> V_164 ) ;
if ( ! V_2 )
return - V_166 ;
V_52 = F_136 ( & V_89 -> V_19 ) ;
if ( V_52 )
goto V_51;
F_63 ( V_2 , V_48 ) ;
F_33 ( & V_89 -> V_19 ) ;
V_51:
F_42 ( V_2 ) ;
return 0 ;
}
int F_137 ( struct V_88 * V_89 , void * V_109 ,
struct V_110 * V_111 )
{
struct V_64 * V_48 = V_111 -> V_112 ;
struct V_167 * args = V_109 ;
struct V_1 * V_2 ;
int V_52 = 0 ;
V_2 = F_135 ( V_48 , args -> V_164 ) ;
if ( ! V_2 )
return - V_166 ;
args -> V_168 = 0 ;
switch ( args -> V_169 ) {
case V_170 :
V_52 = - V_95 ;
break;
case V_171 :
args -> V_172 = V_2 -> V_115 & V_173 ;
break;
case V_174 :
if ( V_2 -> V_20 )
args -> V_172 = V_2 -> V_20 -> V_47 . V_175 ;
else if ( F_75 ( V_89 ) -> V_82 . V_83 )
args -> V_172 = F_75 ( V_89 ) -> V_82 . V_83 -> V_47 . V_175 ;
else
args -> V_172 = F_75 ( V_89 ) -> V_176 . V_47 . V_175 ;
break;
case V_177 :
args -> V_172 = F_138 ( V_2 ) ;
break;
case V_178 :
args -> V_172 = F_139 ( V_2 ) ;
break;
default:
V_52 = - V_95 ;
break;
}
F_42 ( V_2 ) ;
return V_52 ;
}
int F_140 ( struct V_88 * V_89 , void * V_109 ,
struct V_110 * V_111 )
{
struct V_64 * V_48 = V_111 -> V_112 ;
struct V_167 * args = V_109 ;
struct V_1 * V_2 ;
int V_52 ;
V_2 = F_135 ( V_48 , args -> V_164 ) ;
if ( ! V_2 )
return - V_166 ;
V_52 = F_74 ( V_89 ) ;
if ( V_52 )
goto V_51;
switch ( args -> V_169 ) {
case V_170 :
V_52 = - V_95 ;
break;
case V_171 :
if ( args -> V_168 ) {
V_52 = - V_95 ;
} else {
V_2 -> V_115 &= ~ V_173 ;
V_2 -> V_115 |= args -> V_172 ? V_173 : 0 ;
}
break;
case V_177 :
if ( args -> V_168 )
V_52 = - V_95 ;
else if ( args -> V_172 )
F_141 ( V_2 ) ;
else
F_142 ( V_2 ) ;
break;
case V_178 :
if ( args -> V_168 )
V_52 = - V_95 ;
else if ( ! F_143 ( V_179 ) && ! args -> V_172 )
V_52 = - V_180 ;
else if ( args -> V_172 )
F_60 ( V_2 ) ;
else
F_76 ( V_2 ) ;
break;
default:
V_52 = - V_95 ;
break;
}
F_33 ( & V_89 -> V_19 ) ;
V_51:
F_42 ( V_2 ) ;
return V_52 ;
}
int F_144 ( struct V_88 * V_89 ,
void * V_109 , struct V_110 * V_111 )
{
struct V_35 * V_50 = F_75 ( V_89 ) ;
struct V_181 * args = V_109 ;
struct V_1 * V_2 ;
int V_52 ;
if ( args -> V_115 || args -> V_162 )
return - V_95 ;
V_52 = - V_166 ;
F_5 () ;
V_2 = F_145 ( V_111 -> V_112 , args -> V_164 ) ;
if ( ! V_2 )
goto V_51;
if ( F_143 ( V_179 ) )
args -> V_182 = F_146 ( & V_50 -> V_183 ) ;
else
args -> V_182 = 0 ;
args -> V_184 = F_131 ( & V_2 -> V_185 ) ;
args -> V_186 = F_131 ( & V_2 -> V_187 ) ;
V_52 = 0 ;
V_51:
F_12 () ;
return V_52 ;
}
