static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , F_3 ( * V_4 ) , V_5 ) ;
unsigned int V_6 , V_7 , V_8 , V_9 ;
struct V_10 * V_11 ;
F_4 ( ! ( V_4 -> V_12 & V_13 ) ) ;
V_6 = 1 + F_5 ( 4 * V_4 -> V_14 / 3 + 1 ) ;
V_7 = F_6 (unsigned int,
max(bits, VMA_HT_BITS),
sizeof(unsigned int) * BITS_PER_BYTE - 1 ) ;
if ( V_7 == V_4 -> V_15 )
goto V_16;
V_11 = F_7 ( sizeof( * V_11 ) << V_7 , V_17 | V_18 ) ;
if ( ! V_11 )
V_11 = F_8 ( sizeof( * V_11 ) << V_7 ) ;
if ( ! V_11 )
goto V_16;
V_8 = F_9 ( V_4 -> V_15 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
struct V_19 * V_20 ;
struct V_21 * V_22 ;
F_10 (vma, tmp, &lut->ht[i], ctx_node)
F_11 ( & V_20 -> V_23 ,
& V_11 [ F_12 ( V_20 -> V_24 ,
V_7 ) ] ) ;
}
F_13 ( V_4 -> V_25 ) ;
V_4 -> V_25 = V_11 ;
V_4 -> V_15 = V_7 ;
V_16:
F_14 ( & V_4 -> V_12 , F_9 ( V_6 ) ) ;
F_4 ( V_4 -> V_12 & V_13 ) ;
}
static void F_15 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = & V_27 -> V_28 ;
unsigned int V_9 , V_8 ;
if ( V_4 -> V_12 & V_13 )
F_16 ( & V_4 -> V_5 ) ;
V_8 = F_9 ( V_4 -> V_15 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
struct V_19 * V_20 ;
F_17 (vma, &lut->ht[i], ctx_node) {
V_20 -> V_29 -> V_30 = NULL ;
V_20 -> V_27 = NULL ;
F_18 ( V_20 ) ;
}
}
F_13 ( V_4 -> V_25 ) ;
}
void F_19 ( struct V_31 * V_32 )
{
struct V_26 * V_27 = F_2 ( V_32 , F_3 ( * V_27 ) , V_33 ) ;
int V_9 ;
F_20 ( & V_27 -> V_34 -> V_35 . V_36 ) ;
F_21 ( V_27 ) ;
F_4 ( ! F_22 ( V_27 ) ) ;
F_15 ( V_27 ) ;
F_23 ( V_27 -> V_37 ) ;
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ ) {
struct V_39 * V_40 = & V_27 -> V_41 [ V_9 ] ;
if ( ! V_40 -> V_42 )
continue;
F_24 ( V_40 -> V_43 ) ;
if ( V_40 -> V_44 )
F_25 ( V_40 -> V_44 ) ;
F_26 ( V_40 -> V_42 -> V_29 ) ;
}
F_27 ( V_27 -> V_45 ) ;
F_28 ( V_27 -> V_46 ) ;
F_29 ( & V_27 -> V_47 ) ;
F_30 ( & V_27 -> V_34 -> V_48 , V_27 -> V_49 ) ;
F_27 ( V_27 ) ;
}
static void F_31 ( struct V_26 * V_27 )
{
F_32 ( V_27 ) ;
if ( V_27 -> V_37 )
F_33 ( & V_27 -> V_37 -> V_50 ) ;
V_27 -> V_51 = F_34 ( - V_52 ) ;
F_35 ( V_27 ) ;
}
static int F_36 ( struct V_53 * V_54 , unsigned * V_16 )
{
int V_55 ;
V_55 = F_37 ( & V_54 -> V_48 ,
0 , V_56 , V_17 ) ;
if ( V_55 < 0 ) {
F_38 ( V_54 ) ;
V_55 = F_37 ( & V_54 -> V_48 ,
0 , V_56 , V_17 ) ;
if ( V_55 < 0 )
return V_55 ;
}
* V_16 = V_55 ;
return 0 ;
}
static T_1 F_39 ( const struct V_53 * V_34 ,
const struct V_57 * V_37 )
{
T_1 V_58 ;
T_1 V_59 ;
V_59 = V_60 | V_61 ;
V_58 = V_62 ;
if ( V_37 && F_40 ( & V_37 -> V_50 ) )
V_58 = V_63 ;
V_59 |= V_58 << V_64 ;
if ( F_41 ( V_34 ) )
V_59 |= V_65 ;
return V_59 ;
}
static struct V_26 *
F_42 ( struct V_53 * V_54 ,
struct V_66 * V_51 )
{
struct V_26 * V_27 ;
int V_55 ;
V_27 = F_7 ( sizeof( * V_27 ) , V_17 ) ;
if ( V_27 == NULL )
return F_34 ( - V_67 ) ;
V_55 = F_36 ( V_54 , & V_27 -> V_49 ) ;
if ( V_55 ) {
F_27 ( V_27 ) ;
return F_34 ( V_55 ) ;
}
F_43 ( & V_27 -> V_33 ) ;
F_44 ( & V_27 -> V_47 , & V_54 -> V_68 ) ;
V_27 -> V_34 = V_54 ;
V_27 -> V_69 = V_70 ;
V_27 -> V_28 . V_15 = V_71 ;
V_27 -> V_28 . V_12 = F_9 ( V_71 ) ;
F_45 ( F_9 ( V_71 ) == V_13 ) ;
V_27 -> V_28 . V_25 = F_46 ( V_27 -> V_28 . V_12 ,
sizeof( * V_27 -> V_28 . V_25 ) ,
V_17 ) ;
if ( ! V_27 -> V_28 . V_25 )
goto V_72;
F_47 ( & V_27 -> V_28 . V_5 , F_1 ) ;
V_55 = V_73 ;
if ( V_51 ) {
V_55 = F_48 ( & V_51 -> V_74 , V_27 ,
V_73 , 0 , V_17 ) ;
if ( V_55 < 0 )
goto V_75;
}
V_27 -> V_76 = V_55 ;
V_27 -> V_51 = V_51 ;
if ( V_51 ) {
V_27 -> V_46 = F_49 ( V_77 , V_78 ) ;
V_27 -> V_45 = F_50 ( V_17 , L_1 ,
V_77 -> V_79 ,
F_51 ( V_27 -> V_46 ) ,
V_27 -> V_76 ) ;
if ( ! V_27 -> V_45 ) {
V_55 = - V_67 ;
goto V_80;
}
}
V_27 -> V_81 = F_52 ( V_54 ) ;
F_53 ( V_27 ) ;
V_27 -> V_82 = 4 * V_83 ;
V_27 -> V_84 =
F_39 ( V_54 , V_54 -> V_85 . V_86 ) ;
if ( F_54 ( V_54 ) && V_34 . V_87 )
V_27 -> V_88 = V_89 ;
else
V_27 -> V_88 = V_90 ;
return V_27 ;
V_80:
F_28 ( V_27 -> V_46 ) ;
F_55 ( & V_51 -> V_74 , V_27 -> V_76 ) ;
V_75:
F_13 ( V_27 -> V_28 . V_25 ) ;
V_72:
F_31 ( V_27 ) ;
return F_34 ( V_55 ) ;
}
static void F_56 ( struct V_26 * V_27 ,
struct V_66 * V_51 )
{
F_55 ( & V_51 -> V_74 , V_27 -> V_76 ) ;
F_31 ( V_27 ) ;
}
static struct V_26 *
F_57 ( struct V_53 * V_54 ,
struct V_66 * V_51 )
{
struct V_26 * V_27 ;
F_20 ( & V_54 -> V_35 . V_36 ) ;
V_27 = F_42 ( V_54 , V_51 ) ;
if ( F_58 ( V_27 ) )
return V_27 ;
if ( F_59 ( V_54 ) ) {
struct V_57 * V_37 ;
V_37 = F_60 ( V_54 , V_51 , V_27 -> V_45 ) ;
if ( F_58 ( V_37 ) ) {
F_61 ( L_2 ,
F_62 ( V_37 ) ) ;
F_56 ( V_27 , V_51 ) ;
return F_63 ( V_37 ) ;
}
V_27 -> V_37 = V_37 ;
V_27 -> V_84 = F_39 ( V_54 , V_37 ) ;
}
F_64 ( V_27 ) ;
return V_27 ;
}
struct V_26 *
F_65 ( struct V_91 * V_92 )
{
struct V_26 * V_27 ;
int V_55 ;
if ( ! F_66 ( V_93 ) )
return F_34 ( - V_94 ) ;
V_55 = F_67 ( V_92 ) ;
if ( V_55 )
return F_34 ( V_55 ) ;
V_27 = F_42 ( F_68 ( V_92 ) , NULL ) ;
if ( F_58 ( V_27 ) )
goto V_16;
V_27 -> V_51 = F_34 ( - V_52 ) ;
F_32 ( V_27 ) ;
F_69 ( V_27 ) ;
F_70 ( V_27 ) ;
if ( ! V_34 . V_95 )
V_27 -> V_82 = 512 * V_83 ;
F_4 ( F_71 ( V_27 ) ) ;
V_16:
F_72 ( & V_92 -> V_36 ) ;
return V_27 ;
}
int F_73 ( struct V_53 * V_54 )
{
struct V_26 * V_27 ;
if ( F_24 ( V_54 -> V_96 ) )
return 0 ;
if ( F_74 ( V_54 ) &&
F_75 ( V_54 ) ) {
if ( ! V_34 . V_97 ) {
F_76 ( L_3 ) ;
return - V_98 ;
}
}
F_45 ( V_56 > V_99 ) ;
F_77 ( & V_54 -> V_48 ) ;
V_27 = F_57 ( V_54 , NULL ) ;
if ( F_58 ( V_27 ) ) {
F_78 ( L_4 ,
F_62 ( V_27 ) ) ;
return F_62 ( V_27 ) ;
}
F_4 ( V_27 -> V_49 ) ;
F_69 ( V_27 ) ;
V_27 -> V_69 = V_100 ;
V_54 -> V_96 = V_27 ;
F_4 ( ! F_71 ( V_27 ) ) ;
F_61 ( L_5 ,
V_54 -> V_41 [ V_101 ] -> V_102 ? L_6 :
L_7 ) ;
return 0 ;
}
void F_79 ( struct V_53 * V_54 )
{
struct V_103 * V_41 ;
enum V_104 V_105 ;
F_20 ( & V_54 -> V_35 . V_36 ) ;
F_80 (engine, dev_priv, id) {
V_41 -> V_106 = NULL ;
if ( ! V_41 -> V_107 )
continue;
V_41 -> V_108 ( V_41 , V_41 -> V_107 ) ;
V_41 -> V_107 = NULL ;
}
if ( ! V_34 . V_97 ) {
struct V_26 * V_27 ;
F_81 (ctx, &dev_priv->context_list, link) {
if ( ! F_82 ( V_27 ) )
continue;
F_80 (engine, dev_priv, id)
V_27 -> V_41 [ V_41 -> V_105 ] . V_109 = false ;
V_27 -> V_81 = F_52 ( V_54 ) ;
}
F_80 (engine, dev_priv, id) {
struct V_39 * V_110 =
& V_54 -> V_96 -> V_41 [ V_41 -> V_105 ] ;
V_110 -> V_109 = true ;
}
}
}
void F_83 ( struct V_53 * V_54 )
{
struct V_26 * V_111 = V_54 -> V_96 ;
F_20 ( & V_54 -> V_35 . V_36 ) ;
F_4 ( ! F_71 ( V_111 ) ) ;
F_31 ( V_111 ) ;
V_54 -> V_96 = NULL ;
F_84 ( & V_54 -> V_48 ) ;
}
static int F_85 ( int V_105 , void * V_112 , void * V_113 )
{
struct V_26 * V_27 = V_112 ;
F_31 ( V_27 ) ;
return 0 ;
}
int F_86 ( struct V_91 * V_92 , struct V_114 * V_115 )
{
struct V_66 * V_51 = V_115 -> V_116 ;
struct V_26 * V_27 ;
F_87 ( & V_51 -> V_74 ) ;
F_88 ( & V_92 -> V_36 ) ;
V_27 = F_57 ( F_68 ( V_92 ) , V_51 ) ;
F_72 ( & V_92 -> V_36 ) ;
F_4 ( F_71 ( V_27 ) ) ;
if ( F_58 ( V_27 ) ) {
F_89 ( & V_51 -> V_74 ) ;
return F_62 ( V_27 ) ;
}
return 0 ;
}
void F_90 ( struct V_91 * V_92 , struct V_114 * V_115 )
{
struct V_66 * V_51 = V_115 -> V_116 ;
F_20 ( & V_92 -> V_36 ) ;
F_91 ( & V_51 -> V_74 , F_85 , NULL ) ;
F_89 ( & V_51 -> V_74 ) ;
}
static inline int
F_92 ( struct V_117 * V_118 , T_1 V_119 )
{
struct V_53 * V_54 = V_118 -> V_34 ;
struct V_103 * V_41 = V_118 -> V_41 ;
enum V_104 V_105 ;
const int V_120 =
( V_34 . V_121 && F_93 ( V_54 ) == 7 ) ?
F_94 ( V_54 ) -> V_120 - 1 :
0 ;
int V_122 ;
T_1 * V_123 ;
V_119 |= V_124 ;
if ( F_95 ( V_54 ) || F_93 ( V_54 ) >= 8 )
V_119 |= V_125 | V_126 ;
else
V_119 |= V_127 | V_128 ;
V_122 = 4 ;
if ( F_93 ( V_54 ) >= 7 )
V_122 += 2 + ( V_120 ? 4 * V_120 + 6 : 0 ) ;
V_123 = F_96 ( V_118 , V_122 ) ;
if ( F_58 ( V_123 ) )
return F_62 ( V_123 ) ;
if ( F_93 ( V_54 ) >= 7 ) {
* V_123 ++ = V_129 | V_130 ;
if ( V_120 ) {
struct V_103 * V_131 ;
* V_123 ++ = F_97 ( V_120 ) ;
F_80 (signaller, dev_priv, id) {
if ( V_131 == V_41 )
continue;
* V_123 ++ = F_98 (
F_99 ( V_131 -> V_132 ) ) ;
* V_123 ++ = F_100 (
V_133 ) ;
}
}
}
* V_123 ++ = V_134 ;
* V_123 ++ = V_135 ;
* V_123 ++ = F_101 ( V_118 -> V_27 -> V_41 [ V_101 ] . V_42 ) | V_119 ;
* V_123 ++ = V_134 ;
if ( F_93 ( V_54 ) >= 7 ) {
if ( V_120 ) {
struct V_103 * V_131 ;
T_2 V_136 = {} ;
* V_123 ++ = F_97 ( V_120 ) ;
F_80 (signaller, dev_priv, id) {
if ( V_131 == V_41 )
continue;
V_136 = F_99 ( V_131 -> V_132 ) ;
* V_123 ++ = F_98 ( V_136 ) ;
* V_123 ++ = F_102 (
V_133 ) ;
}
* V_123 ++ = V_137 | V_138 ;
* V_123 ++ = F_98 ( V_136 ) ;
* V_123 ++ = F_101 ( V_41 -> V_139 ) ;
* V_123 ++ = V_134 ;
}
* V_123 ++ = V_129 | V_140 ;
}
F_103 ( V_118 , V_123 ) ;
return 0 ;
}
static int F_104 ( struct V_117 * V_118 , int V_141 )
{
T_1 * V_123 , * V_142 = V_118 -> V_34 -> V_143 . V_142 [ V_141 ] ;
int V_9 ;
if ( ! V_142 )
return 0 ;
V_123 = F_96 ( V_118 , V_144 / 4 * 2 + 2 ) ;
if ( F_58 ( V_123 ) )
return F_62 ( V_123 ) ;
* V_123 ++ = F_97 ( V_144 / 4 ) ;
for ( V_9 = 0 ; V_9 < V_144 / 4 ; V_9 ++ ) {
* V_123 ++ = F_98 ( F_105 ( V_141 , V_9 ) ) ;
* V_123 ++ = V_142 [ V_9 ] ;
}
* V_123 ++ = V_134 ;
F_103 ( V_118 , V_123 ) ;
return 0 ;
}
static inline bool F_106 ( struct V_57 * V_37 ,
struct V_103 * V_41 ,
struct V_26 * V_145 )
{
if ( V_145 -> V_81 )
return false ;
if ( ! V_145 -> V_41 [ V_101 ] . V_109 )
return false ;
if ( V_37 && ( F_107 ( V_41 ) & V_37 -> V_146 ) )
return false ;
return V_145 == V_41 -> V_106 ;
}
static bool
F_108 ( struct V_57 * V_37 , struct V_103 * V_41 )
{
struct V_26 * V_147 = V_41 -> V_106 ;
if ( ! V_37 )
return false ;
if ( ! V_147 )
return true ;
if ( ( ! V_147 -> V_37 || V_147 -> V_37 == V_37 ) &&
! ( F_107 ( V_41 ) & V_37 -> V_146 ) )
return false ;
if ( V_41 -> V_105 != V_101 )
return true ;
if ( F_93 ( V_41 -> V_34 ) < 8 )
return true ;
return false ;
}
static bool
F_109 ( struct V_57 * V_37 ,
struct V_26 * V_145 ,
T_1 V_148 )
{
if ( ! V_37 )
return false ;
if ( ! F_41 ( V_145 -> V_34 ) )
return false ;
if ( V_148 & V_149 )
return true ;
return false ;
}
static int F_110 ( struct V_117 * V_118 )
{
struct V_26 * V_145 = V_118 -> V_27 ;
struct V_103 * V_41 = V_118 -> V_41 ;
struct V_57 * V_37 = V_145 -> V_37 ? : V_118 -> V_34 -> V_85 . V_86 ;
struct V_26 * V_147 = V_41 -> V_106 ;
T_1 V_148 ;
int V_55 , V_9 ;
F_4 ( V_41 -> V_105 != V_101 ) ;
if ( F_106 ( V_37 , V_41 , V_145 ) )
return 0 ;
if ( F_108 ( V_37 , V_41 ) ) {
F_111 ( V_41 , V_145 ) ;
V_55 = V_37 -> V_150 ( V_37 , V_118 ) ;
if ( V_55 )
return V_55 ;
}
if ( ! V_145 -> V_41 [ V_101 ] . V_109 || F_82 ( V_145 ) )
V_148 = V_149 ;
else if ( V_37 && F_107 ( V_41 ) & V_37 -> V_146 )
V_148 = V_151 ;
else
V_148 = 0 ;
if ( V_145 != V_147 || ( V_148 & V_151 ) ) {
V_55 = F_92 ( V_118 , V_148 ) ;
if ( V_55 )
return V_55 ;
V_41 -> V_106 = V_145 ;
}
if ( F_109 ( V_37 , V_145 , V_148 ) ) {
F_111 ( V_41 , V_145 ) ;
V_55 = V_37 -> V_150 ( V_37 , V_118 ) ;
if ( V_55 )
return V_55 ;
}
if ( V_37 )
V_37 -> V_146 &= ~ F_107 ( V_41 ) ;
for ( V_9 = 0 ; V_9 < V_152 ; V_9 ++ ) {
if ( ! ( V_145 -> V_81 & ( 1 << V_9 ) ) )
continue;
V_55 = F_104 ( V_118 , V_9 ) ;
if ( V_55 )
return V_55 ;
V_145 -> V_81 &= ~ ( 1 << V_9 ) ;
}
if ( ! V_145 -> V_41 [ V_101 ] . V_109 ) {
if ( V_41 -> V_153 ) {
V_55 = V_41 -> V_153 ( V_118 ) ;
if ( V_55 )
return V_55 ;
}
V_145 -> V_41 [ V_101 ] . V_109 = true ;
}
return 0 ;
}
int F_112 ( struct V_117 * V_118 )
{
struct V_103 * V_41 = V_118 -> V_41 ;
F_20 ( & V_118 -> V_34 -> V_35 . V_36 ) ;
if ( V_34 . V_97 )
return 0 ;
if ( ! V_118 -> V_27 -> V_41 [ V_41 -> V_105 ] . V_42 ) {
struct V_26 * V_145 = V_118 -> V_27 ;
struct V_57 * V_37 =
V_145 -> V_37 ? : V_118 -> V_34 -> V_85 . V_86 ;
if ( F_108 ( V_37 , V_41 ) ) {
int V_55 ;
F_111 ( V_41 , V_145 ) ;
V_55 = V_37 -> V_150 ( V_37 , V_118 ) ;
if ( V_55 )
return V_55 ;
V_37 -> V_146 &= ~ F_107 ( V_41 ) ;
}
V_41 -> V_106 = V_145 ;
return 0 ;
}
return F_110 ( V_118 ) ;
}
static bool F_113 ( struct V_103 * V_41 )
{
struct V_154 * V_155 ;
F_81 (timeline, &engine->i915->gt.timelines, link) {
struct V_156 * V_157 ;
if ( V_155 == & V_41 -> V_34 -> V_158 . V_159 )
continue;
V_157 = & V_155 -> V_41 [ V_41 -> V_105 ] ;
if ( F_114 ( & V_157 -> V_160 ,
& V_41 -> V_34 -> V_35 . V_36 ) )
return false ;
}
return ( ! V_41 -> V_107 ||
F_71 ( V_41 -> V_107 ) ) ;
}
int F_115 ( struct V_53 * V_54 )
{
struct V_103 * V_41 ;
struct V_154 * V_155 ;
enum V_104 V_105 ;
F_20 ( & V_54 -> V_35 . V_36 ) ;
F_38 ( V_54 ) ;
F_80 (engine, dev_priv, id) {
struct V_117 * V_118 ;
int V_55 ;
if ( F_113 ( V_41 ) )
continue;
V_118 = F_116 ( V_41 , V_54 -> V_96 ) ;
if ( F_58 ( V_118 ) )
return F_62 ( V_118 ) ;
F_81 (timeline, &dev_priv->gt.timelines, link) {
struct V_117 * V_161 ;
struct V_156 * V_157 ;
V_157 = & V_155 -> V_41 [ V_41 -> V_105 ] ;
V_161 = F_117 ( & V_157 -> V_160 ,
& V_54 -> V_35 . V_36 ) ;
if ( V_161 )
F_118 ( & V_118 -> V_162 ,
& V_161 -> V_162 ,
V_17 ) ;
}
V_55 = F_112 ( V_118 ) ;
F_119 ( V_118 ) ;
if ( V_55 )
return V_55 ;
}
return 0 ;
}
static bool F_120 ( struct V_66 * V_51 )
{
return V_51 -> V_163 > V_164 ;
}
int F_121 ( struct V_91 * V_92 , void * V_113 ,
struct V_114 * V_115 )
{
struct V_53 * V_54 = F_68 ( V_92 ) ;
struct V_165 * args = V_113 ;
struct V_66 * V_51 = V_115 -> V_116 ;
struct V_26 * V_27 ;
int V_55 ;
if ( ! V_54 -> V_41 [ V_101 ] -> V_102 )
return - V_94 ;
if ( args -> V_166 != 0 )
return - V_98 ;
if ( F_120 ( V_51 ) ) {
F_122 ( L_8 ,
V_77 -> V_79 ,
F_51 ( F_49 ( V_77 , V_78 ) ) ) ;
return - V_167 ;
}
V_55 = F_67 ( V_92 ) ;
if ( V_55 )
return V_55 ;
V_27 = F_57 ( V_54 , V_51 ) ;
F_72 ( & V_92 -> V_36 ) ;
if ( F_58 ( V_27 ) )
return F_62 ( V_27 ) ;
F_4 ( F_71 ( V_27 ) ) ;
args -> V_168 = V_27 -> V_76 ;
F_122 ( L_9 , args -> V_168 ) ;
return 0 ;
}
int F_123 ( struct V_91 * V_92 , void * V_113 ,
struct V_114 * V_115 )
{
struct V_169 * args = V_113 ;
struct V_66 * V_51 = V_115 -> V_116 ;
struct V_26 * V_27 ;
int V_55 ;
if ( args -> V_166 != 0 )
return - V_98 ;
if ( args -> V_168 == V_73 )
return - V_170 ;
V_55 = F_67 ( V_92 ) ;
if ( V_55 )
return V_55 ;
V_27 = F_124 ( V_51 , args -> V_168 ) ;
if ( F_58 ( V_27 ) ) {
F_72 ( & V_92 -> V_36 ) ;
return F_62 ( V_27 ) ;
}
F_56 ( V_27 , V_51 ) ;
F_72 ( & V_92 -> V_36 ) ;
F_122 ( L_10 , args -> V_168 ) ;
return 0 ;
}
int F_125 ( struct V_91 * V_92 , void * V_113 ,
struct V_114 * V_115 )
{
struct V_66 * V_51 = V_115 -> V_116 ;
struct V_171 * args = V_113 ;
struct V_26 * V_27 ;
int V_55 ;
V_55 = F_67 ( V_92 ) ;
if ( V_55 )
return V_55 ;
V_27 = F_124 ( V_51 , args -> V_168 ) ;
if ( F_58 ( V_27 ) ) {
F_72 ( & V_92 -> V_36 ) ;
return F_62 ( V_27 ) ;
}
args -> V_8 = 0 ;
switch ( args -> V_172 ) {
case V_173 :
V_55 = - V_98 ;
break;
case V_174 :
args -> V_175 = V_27 -> V_119 & V_176 ;
break;
case V_177 :
if ( V_27 -> V_37 )
args -> V_175 = V_27 -> V_37 -> V_50 . V_178 ;
else if ( F_68 ( V_92 ) -> V_85 . V_86 )
args -> V_175 = F_68 ( V_92 ) -> V_85 . V_86 -> V_50 . V_178 ;
else
args -> V_175 = F_68 ( V_92 ) -> V_179 . V_50 . V_178 ;
break;
case V_180 :
args -> V_175 = F_126 ( V_27 ) ;
break;
case V_181 :
args -> V_175 = F_127 ( V_27 ) ;
break;
default:
V_55 = - V_98 ;
break;
}
F_72 ( & V_92 -> V_36 ) ;
return V_55 ;
}
int F_128 ( struct V_91 * V_92 , void * V_113 ,
struct V_114 * V_115 )
{
struct V_66 * V_51 = V_115 -> V_116 ;
struct V_171 * args = V_113 ;
struct V_26 * V_27 ;
int V_55 ;
V_55 = F_67 ( V_92 ) ;
if ( V_55 )
return V_55 ;
V_27 = F_124 ( V_51 , args -> V_168 ) ;
if ( F_58 ( V_27 ) ) {
F_72 ( & V_92 -> V_36 ) ;
return F_62 ( V_27 ) ;
}
switch ( args -> V_172 ) {
case V_173 :
V_55 = - V_98 ;
break;
case V_174 :
if ( args -> V_8 ) {
V_55 = - V_98 ;
} else {
V_27 -> V_119 &= ~ V_176 ;
V_27 -> V_119 |= args -> V_175 ? V_176 : 0 ;
}
break;
case V_180 :
if ( args -> V_8 )
V_55 = - V_98 ;
else if ( args -> V_175 )
F_129 ( V_27 ) ;
else
F_130 ( V_27 ) ;
break;
case V_181 :
if ( args -> V_8 )
V_55 = - V_98 ;
else if ( ! F_131 ( V_182 ) && ! args -> V_175 )
V_55 = - V_183 ;
else if ( args -> V_175 )
F_53 ( V_27 ) ;
else
F_69 ( V_27 ) ;
break;
default:
V_55 = - V_98 ;
break;
}
F_72 ( & V_92 -> V_36 ) ;
return V_55 ;
}
int F_132 ( struct V_91 * V_92 ,
void * V_113 , struct V_114 * V_115 )
{
struct V_53 * V_54 = F_68 ( V_92 ) ;
struct V_184 * args = V_113 ;
struct V_26 * V_27 ;
int V_55 ;
if ( args -> V_119 || args -> V_166 )
return - V_98 ;
V_55 = F_67 ( V_92 ) ;
if ( V_55 )
return V_55 ;
V_27 = F_124 ( V_115 -> V_116 , args -> V_168 ) ;
if ( F_58 ( V_27 ) ) {
F_72 ( & V_92 -> V_36 ) ;
return F_62 ( V_27 ) ;
}
if ( F_131 ( V_182 ) )
args -> V_185 = F_133 ( & V_54 -> V_186 ) ;
else
args -> V_185 = 0 ;
args -> V_187 = V_27 -> V_188 ;
args -> V_189 = V_27 -> V_190 ;
F_72 ( & V_92 -> V_36 ) ;
return 0 ;
}
