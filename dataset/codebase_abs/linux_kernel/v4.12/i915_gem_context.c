static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
switch ( F_2 ( V_2 ) ) {
case 6 :
V_4 = F_3 ( V_5 ) ;
V_3 = F_4 ( V_4 ) * 64 ;
break;
case 7 :
V_4 = F_3 ( V_6 ) ;
if ( F_5 ( V_2 ) )
V_3 = V_7 ;
else
V_3 = F_6 ( V_4 ) * 64 ;
break;
case 8 :
V_3 = V_8 ;
break;
default:
F_7 () ;
}
return V_3 ;
}
void F_8 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_9 ( V_10 , F_10 ( * V_12 ) , V_13 ) ;
int V_14 ;
F_11 ( & V_12 -> V_15 -> V_16 . V_17 ) ;
F_12 ( V_12 ) ;
F_13 ( ! F_14 ( V_12 ) ) ;
F_15 ( V_12 -> V_18 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ ) {
struct V_20 * V_21 = & V_12 -> V_22 [ V_14 ] ;
if ( ! V_21 -> V_23 )
continue;
F_16 ( V_21 -> V_24 ) ;
if ( V_21 -> V_25 )
F_17 ( V_21 -> V_25 ) ;
F_18 ( V_21 -> V_23 -> V_26 ) ;
}
F_19 ( V_12 -> V_27 ) ;
F_20 ( V_12 -> V_28 ) ;
F_21 ( & V_12 -> V_29 ) ;
F_22 ( & V_12 -> V_15 -> V_30 , V_12 -> V_31 ) ;
F_19 ( V_12 ) ;
}
static struct V_32 *
F_23 ( struct V_1 * V_2 , T_2 V_33 )
{
struct V_32 * V_26 ;
int V_3 ;
F_11 ( & V_2 -> V_16 . V_17 ) ;
V_26 = F_24 ( V_2 , V_33 ) ;
if ( F_25 ( V_26 ) )
return V_26 ;
if ( F_26 ( V_2 ) ) {
V_3 = F_27 ( V_26 , V_34 ) ;
if ( F_16 ( V_3 ) ) {
F_28 ( V_26 ) ;
return F_29 ( V_3 ) ;
}
}
return V_26 ;
}
static void F_30 ( struct V_11 * V_12 )
{
F_31 ( V_12 ) ;
if ( V_12 -> V_18 )
F_32 ( & V_12 -> V_18 -> V_35 ) ;
V_12 -> V_36 = F_29 ( - V_37 ) ;
F_33 ( V_12 ) ;
}
static int F_34 ( struct V_1 * V_2 , unsigned * V_38 )
{
int V_3 ;
V_3 = F_35 ( & V_2 -> V_30 ,
0 , V_39 , V_40 ) ;
if ( V_3 < 0 ) {
F_36 ( V_2 ) ;
V_3 = F_35 ( & V_2 -> V_30 ,
0 , V_39 , V_40 ) ;
if ( V_3 < 0 )
return V_3 ;
}
* V_38 = V_3 ;
return 0 ;
}
static T_1 F_37 ( const struct V_1 * V_15 ,
const struct V_41 * V_18 )
{
T_1 V_42 ;
T_1 V_43 ;
V_43 = V_44 | V_45 ;
V_42 = V_46 ;
if ( V_18 && F_38 ( & V_18 -> V_35 ) )
V_42 = V_47 ;
V_43 |= V_42 << V_48 ;
if ( F_39 ( V_15 ) )
V_43 |= V_49 ;
return V_43 ;
}
static struct V_11 *
F_40 ( struct V_1 * V_2 ,
struct V_50 * V_36 )
{
struct V_11 * V_12 ;
int V_3 ;
V_12 = F_41 ( sizeof( * V_12 ) , V_40 ) ;
if ( V_12 == NULL )
return F_29 ( - V_51 ) ;
V_3 = F_34 ( V_2 , & V_12 -> V_31 ) ;
if ( V_3 ) {
F_19 ( V_12 ) ;
return F_29 ( V_3 ) ;
}
F_42 ( & V_12 -> V_13 ) ;
F_43 ( & V_12 -> V_29 , & V_2 -> V_52 ) ;
V_12 -> V_15 = V_2 ;
if ( V_2 -> V_53 ) {
struct V_32 * V_26 ;
struct V_54 * V_55 ;
V_26 = F_23 ( V_2 , V_2 -> V_53 ) ;
if ( F_25 ( V_26 ) ) {
V_3 = F_44 ( V_26 ) ;
goto V_56;
}
V_55 = F_45 ( V_26 , & V_2 -> V_57 . V_35 , NULL ) ;
if ( F_25 ( V_55 ) ) {
F_28 ( V_26 ) ;
V_3 = F_44 ( V_55 ) ;
goto V_56;
}
V_12 -> V_22 [ V_58 ] . V_23 = V_55 ;
}
V_3 = V_59 ;
if ( V_36 ) {
V_3 = F_46 ( & V_36 -> V_60 , V_12 ,
V_59 , 0 , V_40 ) ;
if ( V_3 < 0 )
goto V_56;
}
V_12 -> V_61 = V_3 ;
V_12 -> V_36 = V_36 ;
if ( V_36 ) {
V_12 -> V_28 = F_47 ( V_62 , V_63 ) ;
V_12 -> V_27 = F_48 ( V_40 , L_1 ,
V_62 -> V_64 ,
F_49 ( V_12 -> V_28 ) ,
V_12 -> V_61 ) ;
if ( ! V_12 -> V_27 ) {
V_3 = - V_51 ;
goto V_65;
}
}
V_12 -> V_66 = F_50 ( V_2 ) ;
F_51 ( V_12 ) ;
V_12 -> V_67 = 4 * V_68 ;
V_12 -> V_69 =
F_37 ( V_2 , V_2 -> V_70 . V_71 ) ;
if ( F_52 ( V_2 ) && V_15 . V_72 )
V_12 -> V_73 = V_74 ;
else
V_12 -> V_73 = V_75 ;
return V_12 ;
V_65:
F_20 ( V_12 -> V_28 ) ;
F_53 ( & V_36 -> V_60 , V_12 -> V_61 ) ;
V_56:
F_30 ( V_12 ) ;
return F_29 ( V_3 ) ;
}
static void F_54 ( struct V_11 * V_12 ,
struct V_50 * V_36 )
{
F_53 ( & V_36 -> V_60 , V_12 -> V_61 ) ;
F_30 ( V_12 ) ;
}
static struct V_11 *
F_55 ( struct V_1 * V_2 ,
struct V_50 * V_36 )
{
struct V_11 * V_12 ;
F_11 ( & V_2 -> V_16 . V_17 ) ;
V_12 = F_40 ( V_2 , V_36 ) ;
if ( F_25 ( V_12 ) )
return V_12 ;
if ( F_56 ( V_2 ) ) {
struct V_41 * V_18 ;
V_18 = F_57 ( V_2 , V_36 , V_12 -> V_27 ) ;
if ( F_25 ( V_18 ) ) {
F_58 ( L_2 ,
F_44 ( V_18 ) ) ;
F_54 ( V_12 , V_36 ) ;
return F_59 ( V_18 ) ;
}
V_12 -> V_18 = V_18 ;
V_12 -> V_69 = F_37 ( V_2 , V_18 ) ;
}
F_60 ( V_12 ) ;
return V_12 ;
}
struct V_11 *
F_61 ( struct V_76 * V_77 )
{
struct V_11 * V_12 ;
int V_3 ;
if ( ! F_62 ( V_78 ) )
return F_29 ( - V_79 ) ;
V_3 = F_63 ( V_77 ) ;
if ( V_3 )
return F_29 ( V_3 ) ;
V_12 = F_40 ( F_64 ( V_77 ) , NULL ) ;
if ( F_25 ( V_12 ) )
goto V_38;
V_12 -> V_36 = F_29 ( - V_37 ) ;
F_31 ( V_12 ) ;
F_65 ( V_12 ) ;
F_66 ( V_12 ) ;
if ( ! V_15 . V_80 )
V_12 -> V_67 = 512 * V_68 ;
F_13 ( F_67 ( V_12 ) ) ;
V_38:
F_68 ( & V_77 -> V_17 ) ;
return V_12 ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
if ( F_16 ( V_2 -> V_81 ) )
return 0 ;
if ( F_70 ( V_2 ) &&
F_71 ( V_2 ) ) {
if ( ! V_15 . V_82 ) {
F_72 ( L_3 ) ;
return - V_83 ;
}
}
F_73 ( V_39 > V_84 ) ;
F_74 ( & V_2 -> V_30 ) ;
if ( V_15 . V_82 ) {
V_2 -> V_53 = 0 ;
} else if ( F_75 ( V_2 ) ) {
V_2 -> V_53 =
F_76 ( F_1 ( V_2 ) ,
V_75 ) ;
if ( V_2 -> V_53 > ( 1 << 20 ) ) {
F_58 ( L_4 ,
V_2 -> V_53 ) ;
V_2 -> V_53 = 0 ;
}
}
V_12 = F_55 ( V_2 , NULL ) ;
if ( F_25 ( V_12 ) ) {
F_77 ( L_5 ,
F_44 ( V_12 ) ) ;
return F_44 ( V_12 ) ;
}
F_13 ( V_12 -> V_31 ) ;
F_65 ( V_12 ) ;
V_12 -> V_85 = V_86 ;
V_2 -> V_81 = V_12 ;
F_13 ( ! F_67 ( V_12 ) ) ;
F_58 ( L_6 ,
V_15 . V_82 ? L_7 :
V_2 -> V_53 ? L_8 : L_9 ) ;
return 0 ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_87 * V_22 ;
enum V_88 V_89 ;
F_11 ( & V_2 -> V_16 . V_17 ) ;
F_79 (engine, dev_priv, id) {
V_22 -> V_90 = NULL ;
if ( ! V_22 -> V_91 )
continue;
V_22 -> V_92 ( V_22 , V_22 -> V_91 ) ;
V_22 -> V_91 = NULL ;
}
if ( ! V_15 . V_82 ) {
struct V_11 * V_12 ;
F_80 (ctx, &dev_priv->context_list, link) {
if ( ! F_81 ( V_12 ) )
continue;
F_79 (engine, dev_priv, id)
V_12 -> V_22 [ V_22 -> V_89 ] . V_93 = false ;
V_12 -> V_66 = F_50 ( V_2 ) ;
}
F_79 (engine, dev_priv, id) {
struct V_20 * V_94 =
& V_2 -> V_81 -> V_22 [ V_22 -> V_89 ] ;
V_94 -> V_93 = true ;
}
}
}
void F_82 ( struct V_1 * V_2 )
{
struct V_11 * V_95 = V_2 -> V_81 ;
F_11 ( & V_2 -> V_16 . V_17 ) ;
F_13 ( ! F_67 ( V_95 ) ) ;
F_30 ( V_95 ) ;
V_2 -> V_81 = NULL ;
F_83 ( & V_2 -> V_30 ) ;
}
static int F_84 ( int V_89 , void * V_96 , void * V_97 )
{
struct V_11 * V_12 = V_96 ;
F_30 ( V_12 ) ;
return 0 ;
}
int F_85 ( struct V_76 * V_77 , struct V_98 * V_99 )
{
struct V_50 * V_36 = V_99 -> V_100 ;
struct V_11 * V_12 ;
F_86 ( & V_36 -> V_60 ) ;
F_87 ( & V_77 -> V_17 ) ;
V_12 = F_55 ( F_64 ( V_77 ) , V_36 ) ;
F_68 ( & V_77 -> V_17 ) ;
F_13 ( F_67 ( V_12 ) ) ;
if ( F_25 ( V_12 ) ) {
F_88 ( & V_36 -> V_60 ) ;
return F_44 ( V_12 ) ;
}
return 0 ;
}
void F_89 ( struct V_76 * V_77 , struct V_98 * V_99 )
{
struct V_50 * V_36 = V_99 -> V_100 ;
F_11 ( & V_77 -> V_17 ) ;
F_90 ( & V_36 -> V_60 , F_84 , NULL ) ;
F_88 ( & V_36 -> V_60 ) ;
}
static inline int
F_91 ( struct V_101 * V_102 , T_1 V_103 )
{
struct V_1 * V_2 = V_102 -> V_15 ;
struct V_87 * V_22 = V_102 -> V_22 ;
enum V_88 V_89 ;
const int V_104 =
( V_15 . V_105 && F_2 ( V_2 ) == 7 ) ?
F_92 ( V_2 ) -> V_104 - 1 :
0 ;
int V_106 ;
T_1 * V_107 ;
V_103 |= V_108 ;
if ( F_5 ( V_2 ) || F_2 ( V_2 ) >= 8 )
V_103 |= V_109 | V_110 ;
else
V_103 |= V_111 | V_112 ;
V_106 = 4 ;
if ( F_2 ( V_2 ) >= 7 )
V_106 += 2 + ( V_104 ? 4 * V_104 + 6 : 0 ) ;
V_107 = F_93 ( V_102 , V_106 ) ;
if ( F_25 ( V_107 ) )
return F_44 ( V_107 ) ;
if ( F_2 ( V_2 ) >= 7 ) {
* V_107 ++ = V_113 | V_114 ;
if ( V_104 ) {
struct V_87 * V_115 ;
* V_107 ++ = F_94 ( V_104 ) ;
F_79 (signaller, dev_priv, id) {
if ( V_115 == V_22 )
continue;
* V_107 ++ = F_95 (
F_96 ( V_115 -> V_116 ) ) ;
* V_107 ++ = F_97 (
V_117 ) ;
}
}
}
* V_107 ++ = V_118 ;
* V_107 ++ = V_119 ;
* V_107 ++ = F_98 ( V_102 -> V_12 -> V_22 [ V_58 ] . V_23 ) | V_103 ;
* V_107 ++ = V_118 ;
if ( F_2 ( V_2 ) >= 7 ) {
if ( V_104 ) {
struct V_87 * V_115 ;
T_3 V_120 = {} ;
* V_107 ++ = F_94 ( V_104 ) ;
F_79 (signaller, dev_priv, id) {
if ( V_115 == V_22 )
continue;
V_120 = F_96 ( V_115 -> V_116 ) ;
* V_107 ++ = F_95 ( V_120 ) ;
* V_107 ++ = F_99 (
V_117 ) ;
}
* V_107 ++ = V_121 | V_122 ;
* V_107 ++ = F_95 ( V_120 ) ;
* V_107 ++ = F_98 ( V_22 -> V_123 ) ;
* V_107 ++ = V_118 ;
}
* V_107 ++ = V_113 | V_124 ;
}
F_100 ( V_102 , V_107 ) ;
return 0 ;
}
static int F_101 ( struct V_101 * V_102 , int V_125 )
{
T_1 * V_107 , * V_126 = V_102 -> V_15 -> V_127 . V_126 [ V_125 ] ;
int V_14 ;
if ( ! V_126 )
return 0 ;
V_107 = F_93 ( V_102 , V_128 / 4 * 2 + 2 ) ;
if ( F_25 ( V_107 ) )
return F_44 ( V_107 ) ;
* V_107 ++ = F_94 ( V_128 / 4 ) ;
for ( V_14 = 0 ; V_14 < V_128 / 4 ; V_14 ++ ) {
* V_107 ++ = F_95 ( F_102 ( V_125 , V_14 ) ) ;
* V_107 ++ = V_126 [ V_14 ] ;
}
* V_107 ++ = V_118 ;
F_100 ( V_102 , V_107 ) ;
return 0 ;
}
static inline bool F_103 ( struct V_41 * V_18 ,
struct V_87 * V_22 ,
struct V_11 * V_129 )
{
if ( V_129 -> V_66 )
return false ;
if ( ! V_129 -> V_22 [ V_58 ] . V_93 )
return false ;
if ( V_18 && ( F_104 ( V_22 ) & V_18 -> V_130 ) )
return false ;
return V_129 == V_22 -> V_90 ;
}
static bool
F_105 ( struct V_41 * V_18 ,
struct V_87 * V_22 ,
struct V_11 * V_129 )
{
if ( ! V_18 )
return false ;
if ( ! V_22 -> V_90 )
return true ;
if ( V_22 -> V_90 == V_129 &&
! ( F_104 ( V_22 ) & V_18 -> V_130 ) )
return false ;
if ( V_22 -> V_89 != V_58 )
return true ;
if ( F_2 ( V_22 -> V_15 ) < 8 )
return true ;
return false ;
}
static bool
F_106 ( struct V_41 * V_18 ,
struct V_11 * V_129 ,
T_1 V_131 )
{
if ( ! V_18 )
return false ;
if ( ! F_39 ( V_129 -> V_15 ) )
return false ;
if ( V_131 & V_132 )
return true ;
return false ;
}
static int F_107 ( struct V_101 * V_102 )
{
struct V_11 * V_129 = V_102 -> V_12 ;
struct V_87 * V_22 = V_102 -> V_22 ;
struct V_41 * V_18 = V_129 -> V_18 ? : V_102 -> V_15 -> V_70 . V_71 ;
struct V_11 * V_133 = V_22 -> V_90 ;
T_1 V_131 ;
int V_3 , V_14 ;
F_13 ( V_22 -> V_89 != V_58 ) ;
if ( F_103 ( V_18 , V_22 , V_129 ) )
return 0 ;
if ( F_105 ( V_18 , V_22 , V_129 ) ) {
F_108 ( V_22 , V_129 ) ;
V_3 = V_18 -> V_134 ( V_18 , V_102 ) ;
if ( V_3 )
return V_3 ;
}
if ( ! V_129 -> V_22 [ V_58 ] . V_93 || F_81 ( V_129 ) )
V_131 = V_132 ;
else if ( V_18 && F_104 ( V_22 ) & V_18 -> V_130 )
V_131 = V_135 ;
else
V_131 = 0 ;
if ( V_129 != V_133 || ( V_131 & V_135 ) ) {
V_3 = F_91 ( V_102 , V_131 ) ;
if ( V_3 )
return V_3 ;
V_22 -> V_90 = V_129 ;
}
if ( F_106 ( V_18 , V_129 , V_131 ) ) {
F_108 ( V_22 , V_129 ) ;
V_3 = V_18 -> V_134 ( V_18 , V_102 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_18 )
V_18 -> V_130 &= ~ F_104 ( V_22 ) ;
for ( V_14 = 0 ; V_14 < V_136 ; V_14 ++ ) {
if ( ! ( V_129 -> V_66 & ( 1 << V_14 ) ) )
continue;
V_3 = F_101 ( V_102 , V_14 ) ;
if ( V_3 )
return V_3 ;
V_129 -> V_66 &= ~ ( 1 << V_14 ) ;
}
if ( ! V_129 -> V_22 [ V_58 ] . V_93 ) {
if ( V_22 -> V_137 ) {
V_3 = V_22 -> V_137 ( V_102 ) ;
if ( V_3 )
return V_3 ;
}
V_129 -> V_22 [ V_58 ] . V_93 = true ;
}
return 0 ;
}
int F_109 ( struct V_101 * V_102 )
{
struct V_87 * V_22 = V_102 -> V_22 ;
F_11 ( & V_102 -> V_15 -> V_16 . V_17 ) ;
if ( V_15 . V_82 )
return 0 ;
if ( ! V_102 -> V_12 -> V_22 [ V_22 -> V_89 ] . V_23 ) {
struct V_11 * V_129 = V_102 -> V_12 ;
struct V_41 * V_18 =
V_129 -> V_18 ? : V_102 -> V_15 -> V_70 . V_71 ;
if ( F_105 ( V_18 , V_22 , V_129 ) ) {
int V_3 ;
F_108 ( V_22 , V_129 ) ;
V_3 = V_18 -> V_134 ( V_18 , V_102 ) ;
if ( V_3 )
return V_3 ;
V_18 -> V_130 &= ~ F_104 ( V_22 ) ;
}
return 0 ;
}
return F_107 ( V_102 ) ;
}
static bool F_110 ( struct V_87 * V_22 )
{
struct V_138 * V_139 ;
F_80 (timeline, &engine->i915->gt.timelines, link) {
struct V_140 * V_141 ;
if ( V_139 == & V_22 -> V_15 -> V_142 . V_143 )
continue;
V_141 = & V_139 -> V_22 [ V_22 -> V_89 ] ;
if ( F_111 ( & V_141 -> V_144 ,
& V_22 -> V_15 -> V_16 . V_17 ) )
return false ;
}
return ( ! V_22 -> V_91 ||
F_67 ( V_22 -> V_91 ) ) ;
}
int F_112 ( struct V_1 * V_2 )
{
struct V_87 * V_22 ;
struct V_138 * V_139 ;
enum V_88 V_89 ;
F_11 ( & V_2 -> V_16 . V_17 ) ;
F_36 ( V_2 ) ;
F_79 (engine, dev_priv, id) {
struct V_101 * V_102 ;
int V_3 ;
if ( F_110 ( V_22 ) )
continue;
V_102 = F_113 ( V_22 , V_2 -> V_81 ) ;
if ( F_25 ( V_102 ) )
return F_44 ( V_102 ) ;
F_80 (timeline, &dev_priv->gt.timelines, link) {
struct V_101 * V_145 ;
struct V_140 * V_141 ;
V_141 = & V_139 -> V_22 [ V_22 -> V_89 ] ;
V_145 = F_114 ( & V_141 -> V_144 ,
& V_2 -> V_16 . V_17 ) ;
if ( V_145 )
F_115 ( & V_102 -> V_146 ,
& V_145 -> V_146 ,
V_40 ) ;
}
V_3 = F_109 ( V_102 ) ;
F_116 ( V_102 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static bool F_117 ( struct V_76 * V_77 )
{
return V_15 . V_82 || F_64 ( V_77 ) -> V_53 ;
}
static bool F_118 ( struct V_50 * V_36 )
{
return V_36 -> V_147 > V_148 ;
}
int F_119 ( struct V_76 * V_77 , void * V_97 ,
struct V_98 * V_99 )
{
struct V_149 * args = V_97 ;
struct V_50 * V_36 = V_99 -> V_100 ;
struct V_11 * V_12 ;
int V_3 ;
if ( ! F_117 ( V_77 ) )
return - V_79 ;
if ( args -> V_150 != 0 )
return - V_83 ;
if ( F_118 ( V_36 ) ) {
F_120 ( L_10 ,
V_62 -> V_64 ,
F_49 ( F_47 ( V_62 , V_63 ) ) ) ;
return - V_151 ;
}
V_3 = F_63 ( V_77 ) ;
if ( V_3 )
return V_3 ;
V_12 = F_55 ( F_64 ( V_77 ) , V_36 ) ;
F_68 ( & V_77 -> V_17 ) ;
if ( F_25 ( V_12 ) )
return F_44 ( V_12 ) ;
F_13 ( F_67 ( V_12 ) ) ;
args -> V_152 = V_12 -> V_61 ;
F_120 ( L_11 , args -> V_152 ) ;
return 0 ;
}
int F_121 ( struct V_76 * V_77 , void * V_97 ,
struct V_98 * V_99 )
{
struct V_153 * args = V_97 ;
struct V_50 * V_36 = V_99 -> V_100 ;
struct V_11 * V_12 ;
int V_3 ;
if ( args -> V_150 != 0 )
return - V_83 ;
if ( args -> V_152 == V_59 )
return - V_154 ;
V_3 = F_63 ( V_77 ) ;
if ( V_3 )
return V_3 ;
V_12 = F_122 ( V_36 , args -> V_152 ) ;
if ( F_25 ( V_12 ) ) {
F_68 ( & V_77 -> V_17 ) ;
return F_44 ( V_12 ) ;
}
F_54 ( V_12 , V_36 ) ;
F_68 ( & V_77 -> V_17 ) ;
F_120 ( L_12 , args -> V_152 ) ;
return 0 ;
}
int F_123 ( struct V_76 * V_77 , void * V_97 ,
struct V_98 * V_99 )
{
struct V_50 * V_36 = V_99 -> V_100 ;
struct V_155 * args = V_97 ;
struct V_11 * V_12 ;
int V_3 ;
V_3 = F_63 ( V_77 ) ;
if ( V_3 )
return V_3 ;
V_12 = F_122 ( V_36 , args -> V_152 ) ;
if ( F_25 ( V_12 ) ) {
F_68 ( & V_77 -> V_17 ) ;
return F_44 ( V_12 ) ;
}
args -> V_33 = 0 ;
switch ( args -> V_156 ) {
case V_157 :
V_3 = - V_83 ;
break;
case V_158 :
args -> V_159 = V_12 -> V_103 & V_160 ;
break;
case V_161 :
if ( V_12 -> V_18 )
args -> V_159 = V_12 -> V_18 -> V_35 . V_162 ;
else if ( F_64 ( V_77 ) -> V_70 . V_71 )
args -> V_159 = F_64 ( V_77 ) -> V_70 . V_71 -> V_35 . V_162 ;
else
args -> V_159 = F_64 ( V_77 ) -> V_57 . V_35 . V_162 ;
break;
case V_163 :
args -> V_159 = F_124 ( V_12 ) ;
break;
case V_164 :
args -> V_159 = F_125 ( V_12 ) ;
break;
default:
V_3 = - V_83 ;
break;
}
F_68 ( & V_77 -> V_17 ) ;
return V_3 ;
}
int F_126 ( struct V_76 * V_77 , void * V_97 ,
struct V_98 * V_99 )
{
struct V_50 * V_36 = V_99 -> V_100 ;
struct V_155 * args = V_97 ;
struct V_11 * V_12 ;
int V_3 ;
V_3 = F_63 ( V_77 ) ;
if ( V_3 )
return V_3 ;
V_12 = F_122 ( V_36 , args -> V_152 ) ;
if ( F_25 ( V_12 ) ) {
F_68 ( & V_77 -> V_17 ) ;
return F_44 ( V_12 ) ;
}
switch ( args -> V_156 ) {
case V_157 :
V_3 = - V_83 ;
break;
case V_158 :
if ( args -> V_33 ) {
V_3 = - V_83 ;
} else {
V_12 -> V_103 &= ~ V_160 ;
V_12 -> V_103 |= args -> V_159 ? V_160 : 0 ;
}
break;
case V_163 :
if ( args -> V_33 )
V_3 = - V_83 ;
else if ( args -> V_159 )
F_127 ( V_12 ) ;
else
F_128 ( V_12 ) ;
break;
case V_164 :
if ( args -> V_33 )
V_3 = - V_83 ;
else if ( ! F_129 ( V_165 ) && ! args -> V_159 )
V_3 = - V_166 ;
else if ( args -> V_159 )
F_51 ( V_12 ) ;
else
F_65 ( V_12 ) ;
break;
default:
V_3 = - V_83 ;
break;
}
F_68 ( & V_77 -> V_17 ) ;
return V_3 ;
}
int F_130 ( struct V_76 * V_77 ,
void * V_97 , struct V_98 * V_99 )
{
struct V_1 * V_2 = F_64 ( V_77 ) ;
struct V_167 * args = V_97 ;
struct V_11 * V_12 ;
int V_3 ;
if ( args -> V_103 || args -> V_150 )
return - V_83 ;
if ( args -> V_152 == V_59 && ! F_129 ( V_165 ) )
return - V_166 ;
V_3 = F_63 ( V_77 ) ;
if ( V_3 )
return V_3 ;
V_12 = F_122 ( V_99 -> V_100 , args -> V_152 ) ;
if ( F_25 ( V_12 ) ) {
F_68 ( & V_77 -> V_17 ) ;
return F_44 ( V_12 ) ;
}
if ( F_129 ( V_165 ) )
args -> V_168 = F_131 ( & V_2 -> V_169 ) ;
else
args -> V_168 = 0 ;
args -> V_170 = V_12 -> V_171 ;
args -> V_172 = V_12 -> V_173 ;
F_68 ( & V_77 -> V_17 ) ;
return 0 ;
}
