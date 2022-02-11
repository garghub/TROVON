static T_1 F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_3 ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_6 ;
switch ( F_4 ( V_2 ) ) {
case 6 :
V_6 = F_5 ( V_7 ) ;
V_5 = F_6 ( V_6 ) * 64 ;
break;
case 7 :
V_6 = F_5 ( V_8 ) ;
if ( F_7 ( V_2 ) )
V_5 = V_9 ;
else
V_5 = F_8 ( V_6 ) * 64 ;
break;
case 8 :
V_5 = V_10 ;
break;
default:
F_9 () ;
}
return V_5 ;
}
void F_10 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_11 ( V_12 , F_12 ( * V_14 ) , V_15 ) ;
int V_16 ;
F_13 ( & V_14 -> V_17 -> V_18 . V_19 ) ;
F_14 ( V_14 ) ;
F_15 ( ! F_16 ( V_14 ) ) ;
F_17 ( V_14 -> V_20 ) ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ ) {
struct V_22 * V_23 = & V_14 -> V_24 [ V_16 ] ;
if ( ! V_23 -> V_25 )
continue;
F_18 ( V_23 -> V_26 ) ;
if ( V_23 -> V_27 )
F_19 ( V_23 -> V_27 ) ;
F_20 ( V_23 -> V_25 -> V_28 ) ;
}
F_21 ( V_14 -> V_29 ) ;
F_22 ( V_14 -> V_30 ) ;
F_23 ( & V_14 -> V_31 ) ;
F_24 ( & V_14 -> V_17 -> V_32 , V_14 -> V_33 ) ;
F_21 ( V_14 ) ;
}
static struct V_34 *
F_25 ( struct V_1 * V_2 , T_3 V_35 )
{
struct V_34 * V_28 ;
int V_5 ;
F_13 ( & V_2 -> V_18 . V_19 ) ;
V_28 = F_26 ( V_2 , V_35 ) ;
if ( F_27 ( V_28 ) )
return V_28 ;
if ( F_28 ( V_2 ) ) {
V_5 = F_29 ( V_28 , V_36 ) ;
if ( F_18 ( V_5 ) ) {
F_30 ( V_28 ) ;
return F_31 ( V_5 ) ;
}
}
return V_28 ;
}
static void F_32 ( struct V_13 * V_14 )
{
F_33 ( V_14 ) ;
if ( V_14 -> V_20 )
F_34 ( & V_14 -> V_20 -> V_37 ) ;
V_14 -> V_38 = F_31 ( - V_39 ) ;
F_35 ( V_14 ) ;
}
static int F_36 ( struct V_1 * V_2 , unsigned * V_40 )
{
int V_5 ;
V_5 = F_37 ( & V_2 -> V_32 ,
0 , V_41 , V_42 ) ;
if ( V_5 < 0 ) {
F_38 ( V_2 ) ;
V_5 = F_37 ( & V_2 -> V_32 ,
0 , V_41 , V_42 ) ;
if ( V_5 < 0 )
return V_5 ;
}
* V_40 = V_5 ;
return 0 ;
}
static struct V_13 *
F_39 ( struct V_1 * V_2 ,
struct V_43 * V_38 )
{
struct V_13 * V_14 ;
int V_5 ;
V_14 = F_40 ( sizeof( * V_14 ) , V_42 ) ;
if ( V_14 == NULL )
return F_31 ( - V_44 ) ;
V_5 = F_36 ( V_2 , & V_14 -> V_33 ) ;
if ( V_5 ) {
F_21 ( V_14 ) ;
return F_31 ( V_5 ) ;
}
F_41 ( & V_14 -> V_15 ) ;
F_42 ( & V_14 -> V_31 , & V_2 -> V_45 ) ;
V_14 -> V_17 = V_2 ;
V_14 -> V_46 = F_1 ( V_2 ) ;
if ( V_2 -> V_47 ) {
struct V_34 * V_28 ;
struct V_48 * V_49 ;
V_28 = F_25 ( V_2 , V_2 -> V_47 ) ;
if ( F_27 ( V_28 ) ) {
V_5 = F_43 ( V_28 ) ;
goto V_50;
}
V_49 = F_44 ( V_28 , & V_2 -> V_51 . V_37 , NULL ) ;
if ( F_27 ( V_49 ) ) {
F_30 ( V_28 ) ;
V_5 = F_43 ( V_49 ) ;
goto V_50;
}
V_14 -> V_24 [ V_52 ] . V_25 = V_49 ;
}
V_5 = V_53 ;
if ( V_38 ) {
V_5 = F_45 ( & V_38 -> V_54 , V_14 ,
V_53 , 0 , V_42 ) ;
if ( V_5 < 0 )
goto V_50;
}
V_14 -> V_55 = V_5 ;
V_14 -> V_38 = V_38 ;
if ( V_38 ) {
V_14 -> V_30 = F_46 ( V_56 , V_57 ) ;
V_14 -> V_29 = F_47 ( V_42 , L_1 ,
V_56 -> V_58 ,
F_48 ( V_14 -> V_30 ) ,
V_14 -> V_55 ) ;
if ( ! V_14 -> V_29 ) {
V_5 = - V_44 ;
goto V_59;
}
}
V_14 -> V_60 = F_49 ( V_2 ) ;
F_50 ( V_14 ) ;
V_14 -> V_61 = 4 * V_62 ;
V_14 -> V_63 = F_51 ( V_2 ) <<
V_64 ;
if ( F_52 ( V_2 ) && V_17 . V_65 )
V_14 -> V_66 = V_67 ;
else
V_14 -> V_66 = V_68 ;
return V_14 ;
V_59:
F_22 ( V_14 -> V_30 ) ;
F_53 ( & V_38 -> V_54 , V_14 -> V_55 ) ;
V_50:
F_32 ( V_14 ) ;
return F_31 ( V_5 ) ;
}
static struct V_13 *
F_54 ( struct V_1 * V_2 ,
struct V_43 * V_38 )
{
struct V_13 * V_14 ;
F_13 ( & V_2 -> V_18 . V_19 ) ;
V_14 = F_39 ( V_2 , V_38 ) ;
if ( F_27 ( V_14 ) )
return V_14 ;
if ( F_55 ( V_2 ) ) {
struct V_69 * V_20 ;
V_20 = F_56 ( V_2 , V_38 , V_14 -> V_29 ) ;
if ( F_27 ( V_20 ) ) {
F_57 ( L_2 ,
F_43 ( V_20 ) ) ;
F_53 ( & V_38 -> V_54 , V_14 -> V_55 ) ;
F_32 ( V_14 ) ;
return F_58 ( V_20 ) ;
}
V_14 -> V_20 = V_20 ;
}
F_59 ( V_14 ) ;
return V_14 ;
}
struct V_13 *
F_60 ( struct V_70 * V_71 )
{
struct V_13 * V_14 ;
int V_5 ;
if ( ! F_61 ( V_72 ) )
return F_31 ( - V_73 ) ;
V_5 = F_62 ( V_71 ) ;
if ( V_5 )
return F_31 ( V_5 ) ;
V_14 = F_39 ( F_63 ( V_71 ) , NULL ) ;
if ( F_27 ( V_14 ) )
goto V_40;
V_14 -> V_38 = F_31 ( - V_39 ) ;
F_33 ( V_14 ) ;
F_64 ( V_14 ) ;
F_65 ( V_14 ) ;
V_14 -> V_61 = 512 * V_62 ;
F_15 ( F_66 ( V_14 ) ) ;
V_40:
F_67 ( & V_71 -> V_19 ) ;
return V_14 ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
if ( F_18 ( V_2 -> V_74 ) )
return 0 ;
if ( F_69 ( V_2 ) &&
F_70 ( V_2 ) ) {
if ( ! V_17 . V_75 ) {
F_71 ( L_3 ) ;
return - V_76 ;
}
}
F_72 ( V_41 > V_77 ) ;
F_73 ( & V_2 -> V_32 ) ;
if ( V_17 . V_75 ) {
V_2 -> V_47 = 0 ;
} else if ( F_74 ( V_2 ) ) {
V_2 -> V_47 =
F_75 ( F_3 ( V_2 ) ,
V_68 ) ;
if ( V_2 -> V_47 > ( 1 << 20 ) ) {
F_57 ( L_4 ,
V_2 -> V_47 ) ;
V_2 -> V_47 = 0 ;
}
}
V_14 = F_54 ( V_2 , NULL ) ;
if ( F_27 ( V_14 ) ) {
F_76 ( L_5 ,
F_43 ( V_14 ) ) ;
return F_43 ( V_14 ) ;
}
F_64 ( V_14 ) ;
V_14 -> V_78 = V_79 ;
V_2 -> V_74 = V_14 ;
F_15 ( ! F_66 ( V_14 ) ) ;
F_57 ( L_6 ,
V_17 . V_75 ? L_7 :
V_2 -> V_47 ? L_8 : L_9 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_80 * V_24 ;
enum V_81 V_82 ;
F_13 ( & V_2 -> V_18 . V_19 ) ;
F_78 (engine, dev_priv, id) {
V_24 -> V_83 = NULL ;
if ( ! V_24 -> V_84 )
continue;
V_24 -> V_85 ( V_24 , V_24 -> V_84 ) ;
V_24 -> V_84 = NULL ;
}
if ( ! V_17 . V_75 ) {
struct V_13 * V_14 ;
F_79 (ctx, &dev_priv->context_list, link) {
if ( ! F_80 ( V_14 ) )
continue;
F_78 (engine, dev_priv, id)
V_14 -> V_24 [ V_24 -> V_82 ] . V_86 = false ;
V_14 -> V_60 = F_49 ( V_2 ) ;
}
F_78 (engine, dev_priv, id) {
struct V_22 * V_87 =
& V_2 -> V_74 -> V_24 [ V_24 -> V_82 ] ;
V_87 -> V_86 = true ;
}
}
}
void F_81 ( struct V_1 * V_2 )
{
struct V_13 * V_88 = V_2 -> V_74 ;
F_13 ( & V_2 -> V_18 . V_19 ) ;
F_15 ( ! F_66 ( V_88 ) ) ;
F_32 ( V_88 ) ;
V_2 -> V_74 = NULL ;
F_82 ( & V_2 -> V_32 ) ;
}
static int F_83 ( int V_82 , void * V_89 , void * V_90 )
{
struct V_13 * V_14 = V_89 ;
F_32 ( V_14 ) ;
return 0 ;
}
int F_84 ( struct V_70 * V_71 , struct V_91 * V_92 )
{
struct V_43 * V_38 = V_92 -> V_93 ;
struct V_13 * V_14 ;
F_85 ( & V_38 -> V_54 ) ;
F_86 ( & V_71 -> V_19 ) ;
V_14 = F_54 ( F_63 ( V_71 ) , V_38 ) ;
F_67 ( & V_71 -> V_19 ) ;
F_15 ( F_66 ( V_14 ) ) ;
if ( F_27 ( V_14 ) ) {
F_87 ( & V_38 -> V_54 ) ;
return F_43 ( V_14 ) ;
}
return 0 ;
}
void F_88 ( struct V_70 * V_71 , struct V_91 * V_92 )
{
struct V_43 * V_38 = V_92 -> V_93 ;
F_13 ( & V_71 -> V_19 ) ;
F_89 ( & V_38 -> V_54 , F_83 , NULL ) ;
F_87 ( & V_38 -> V_54 ) ;
}
static inline int
F_90 ( struct V_94 * V_95 , T_2 V_96 )
{
struct V_1 * V_2 = V_95 -> V_17 ;
struct V_97 * V_27 = V_95 -> V_27 ;
struct V_80 * V_24 = V_95 -> V_24 ;
enum V_81 V_82 ;
T_2 V_98 = V_96 | V_99 ;
const int V_100 =
V_17 . V_101 ?
F_91 ( V_2 ) -> V_100 - 1 :
0 ;
int V_102 , V_5 ;
if ( F_2 ( V_2 ) ) {
V_5 = V_24 -> V_103 ( V_95 , V_104 ) ;
if ( V_5 )
return V_5 ;
}
if ( F_7 ( V_2 ) || F_4 ( V_2 ) >= 8 )
V_98 |= ( V_105 | V_106 ) ;
else if ( F_4 ( V_2 ) < 8 )
V_98 |= ( V_107 | V_108 ) ;
V_102 = 4 ;
if ( F_4 ( V_2 ) >= 7 )
V_102 += 2 + ( V_100 ? 4 * V_100 + 6 : 0 ) ;
V_5 = F_92 ( V_95 , V_102 ) ;
if ( V_5 )
return V_5 ;
if ( F_4 ( V_2 ) >= 7 ) {
F_93 ( V_27 , V_109 | V_110 ) ;
if ( V_100 ) {
struct V_80 * V_111 ;
F_93 ( V_27 ,
F_94 ( V_100 ) ) ;
F_78 (signaller, dev_priv, id) {
if ( V_111 == V_24 )
continue;
F_95 ( V_27 ,
F_96 ( V_111 -> V_112 ) ) ;
F_93 ( V_27 ,
F_97 ( V_113 ) ) ;
}
}
}
F_93 ( V_27 , V_114 ) ;
F_93 ( V_27 , V_115 ) ;
F_93 ( V_27 ,
F_98 ( V_95 -> V_14 -> V_24 [ V_52 ] . V_25 ) | V_98 ) ;
F_93 ( V_27 , V_114 ) ;
if ( F_4 ( V_2 ) >= 7 ) {
if ( V_100 ) {
struct V_80 * V_111 ;
T_4 V_116 = {} ;
F_93 ( V_27 ,
F_94 ( V_100 ) ) ;
F_78 (signaller, dev_priv, id) {
if ( V_111 == V_24 )
continue;
V_116 = F_96 ( V_111 -> V_112 ) ;
F_95 ( V_27 , V_116 ) ;
F_93 ( V_27 ,
F_99 ( V_113 ) ) ;
}
F_93 ( V_27 ,
V_117 |
V_118 ) ;
F_95 ( V_27 , V_116 ) ;
F_93 ( V_27 ,
F_98 ( V_24 -> V_119 ) ) ;
F_93 ( V_27 , V_114 ) ;
}
F_93 ( V_27 , V_109 | V_120 ) ;
}
F_100 ( V_27 ) ;
return V_5 ;
}
static int F_101 ( struct V_94 * V_95 , int V_121 )
{
T_2 * V_122 = V_95 -> V_17 -> V_123 . V_122 [ V_121 ] ;
struct V_97 * V_27 = V_95 -> V_27 ;
int V_16 , V_5 ;
if ( ! V_122 )
return 0 ;
V_5 = F_92 ( V_95 , V_124 / 4 * 2 + 2 ) ;
if ( V_5 )
return V_5 ;
F_93 ( V_27 , F_94 ( V_124 / 4 ) ) ;
for ( V_16 = 0 ; V_16 < V_124 / 4 ; V_16 ++ ) {
F_95 ( V_27 , F_102 ( V_121 , V_16 ) ) ;
F_93 ( V_27 , V_122 [ V_16 ] ) ;
}
F_93 ( V_27 , V_114 ) ;
F_100 ( V_27 ) ;
return 0 ;
}
static inline bool F_103 ( struct V_69 * V_20 ,
struct V_80 * V_24 ,
struct V_13 * V_125 )
{
if ( V_125 -> V_60 )
return false ;
if ( ! V_125 -> V_24 [ V_52 ] . V_86 )
return false ;
if ( V_20 && ( F_104 ( V_24 ) & V_20 -> V_126 ) )
return false ;
return V_125 == V_24 -> V_83 ;
}
static bool
F_105 ( struct V_69 * V_20 ,
struct V_80 * V_24 ,
struct V_13 * V_125 )
{
if ( ! V_20 )
return false ;
if ( ! V_24 -> V_83 )
return true ;
if ( V_24 -> V_83 == V_125 &&
! ( F_104 ( V_24 ) & V_20 -> V_126 ) )
return false ;
if ( V_24 -> V_82 != V_52 )
return true ;
if ( F_4 ( V_24 -> V_17 ) < 8 )
return true ;
return false ;
}
static bool
F_106 ( struct V_69 * V_20 ,
struct V_13 * V_125 ,
T_2 V_96 )
{
if ( ! V_20 )
return false ;
if ( ! F_107 ( V_125 -> V_17 ) )
return false ;
if ( V_96 & V_127 )
return true ;
return false ;
}
static int F_108 ( struct V_94 * V_95 )
{
struct V_13 * V_125 = V_95 -> V_14 ;
struct V_80 * V_24 = V_95 -> V_24 ;
struct V_69 * V_20 = V_125 -> V_20 ? : V_95 -> V_17 -> V_128 . V_129 ;
struct V_13 * V_130 = V_24 -> V_83 ;
T_2 V_96 ;
int V_5 , V_16 ;
F_15 ( V_24 -> V_82 != V_52 ) ;
if ( F_103 ( V_20 , V_24 , V_125 ) )
return 0 ;
if ( F_105 ( V_20 , V_24 , V_125 ) ) {
F_109 ( V_24 , V_125 ) ;
V_5 = V_20 -> V_131 ( V_20 , V_95 ) ;
if ( V_5 )
return V_5 ;
}
if ( ! V_125 -> V_24 [ V_52 ] . V_86 || F_80 ( V_125 ) )
V_96 = V_127 ;
else if ( V_20 && F_104 ( V_24 ) & V_20 -> V_126 )
V_96 = V_132 ;
else
V_96 = 0 ;
if ( V_125 != V_130 || ( V_96 & V_132 ) ) {
V_5 = F_90 ( V_95 , V_96 ) ;
if ( V_5 )
return V_5 ;
V_24 -> V_83 = V_125 ;
}
if ( F_106 ( V_20 , V_125 , V_96 ) ) {
F_109 ( V_24 , V_125 ) ;
V_5 = V_20 -> V_131 ( V_20 , V_95 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_20 )
V_20 -> V_126 &= ~ F_104 ( V_24 ) ;
for ( V_16 = 0 ; V_16 < V_133 ; V_16 ++ ) {
if ( ! ( V_125 -> V_60 & ( 1 << V_16 ) ) )
continue;
V_5 = F_101 ( V_95 , V_16 ) ;
if ( V_5 )
return V_5 ;
V_125 -> V_60 &= ~ ( 1 << V_16 ) ;
}
if ( ! V_125 -> V_24 [ V_52 ] . V_86 ) {
if ( V_24 -> V_134 ) {
V_5 = V_24 -> V_134 ( V_95 ) ;
if ( V_5 )
return V_5 ;
}
V_125 -> V_24 [ V_52 ] . V_86 = true ;
}
return 0 ;
}
int F_110 ( struct V_94 * V_95 )
{
struct V_80 * V_24 = V_95 -> V_24 ;
F_13 ( & V_95 -> V_17 -> V_18 . V_19 ) ;
if ( V_17 . V_75 )
return 0 ;
if ( ! V_95 -> V_14 -> V_24 [ V_24 -> V_82 ] . V_25 ) {
struct V_13 * V_125 = V_95 -> V_14 ;
struct V_69 * V_20 =
V_125 -> V_20 ? : V_95 -> V_17 -> V_128 . V_129 ;
if ( F_105 ( V_20 , V_24 , V_125 ) ) {
int V_5 ;
F_109 ( V_24 , V_125 ) ;
V_5 = V_20 -> V_131 ( V_20 , V_95 ) ;
if ( V_5 )
return V_5 ;
V_20 -> V_126 &= ~ F_104 ( V_24 ) ;
}
return 0 ;
}
return F_108 ( V_95 ) ;
}
static bool F_111 ( struct V_80 * V_24 )
{
struct V_135 * V_136 ;
F_79 (timeline, &engine->i915->gt.timelines, link) {
struct V_137 * V_138 ;
if ( V_136 == & V_24 -> V_17 -> V_139 . V_140 )
continue;
V_138 = & V_136 -> V_24 [ V_24 -> V_82 ] ;
if ( F_112 ( & V_138 -> V_141 ,
& V_24 -> V_17 -> V_18 . V_19 ) )
return false ;
}
return ( ! V_24 -> V_84 ||
F_66 ( V_24 -> V_84 ) ) ;
}
int F_113 ( struct V_1 * V_2 )
{
struct V_80 * V_24 ;
struct V_135 * V_136 ;
enum V_81 V_82 ;
F_13 ( & V_2 -> V_18 . V_19 ) ;
F_38 ( V_2 ) ;
F_78 (engine, dev_priv, id) {
struct V_94 * V_95 ;
int V_5 ;
if ( F_111 ( V_24 ) )
continue;
V_95 = F_114 ( V_24 , V_2 -> V_74 ) ;
if ( F_27 ( V_95 ) )
return F_43 ( V_95 ) ;
F_79 (timeline, &dev_priv->gt.timelines, link) {
struct V_94 * V_142 ;
struct V_137 * V_138 ;
V_138 = & V_136 -> V_24 [ V_24 -> V_82 ] ;
V_142 = F_115 ( & V_138 -> V_141 ,
& V_2 -> V_18 . V_19 ) ;
if ( V_142 )
F_116 ( & V_95 -> V_143 ,
& V_142 -> V_143 ,
V_42 ) ;
}
V_5 = F_110 ( V_95 ) ;
F_117 ( V_95 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static bool F_118 ( struct V_70 * V_71 )
{
return V_17 . V_75 || F_63 ( V_71 ) -> V_47 ;
}
static bool F_119 ( struct V_43 * V_38 )
{
return V_38 -> V_144 > V_145 ;
}
int F_120 ( struct V_70 * V_71 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_146 * args = V_90 ;
struct V_43 * V_38 = V_92 -> V_93 ;
struct V_13 * V_14 ;
int V_5 ;
if ( ! F_118 ( V_71 ) )
return - V_73 ;
if ( args -> V_147 != 0 )
return - V_76 ;
if ( F_119 ( V_38 ) ) {
F_121 ( L_10 ,
V_56 -> V_58 ,
F_48 ( F_46 ( V_56 , V_57 ) ) ) ;
return - V_148 ;
}
V_5 = F_62 ( V_71 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_54 ( F_63 ( V_71 ) , V_38 ) ;
F_67 ( & V_71 -> V_19 ) ;
if ( F_27 ( V_14 ) )
return F_43 ( V_14 ) ;
F_15 ( F_66 ( V_14 ) ) ;
args -> V_149 = V_14 -> V_55 ;
F_121 ( L_11 , args -> V_149 ) ;
return 0 ;
}
int F_122 ( struct V_70 * V_71 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_150 * args = V_90 ;
struct V_43 * V_38 = V_92 -> V_93 ;
struct V_13 * V_14 ;
int V_5 ;
if ( args -> V_147 != 0 )
return - V_76 ;
if ( args -> V_149 == V_53 )
return - V_151 ;
V_5 = F_62 ( V_71 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_123 ( V_38 , args -> V_149 ) ;
if ( F_27 ( V_14 ) ) {
F_67 ( & V_71 -> V_19 ) ;
return F_43 ( V_14 ) ;
}
F_53 ( & V_38 -> V_54 , V_14 -> V_55 ) ;
F_32 ( V_14 ) ;
F_67 ( & V_71 -> V_19 ) ;
F_121 ( L_12 , args -> V_149 ) ;
return 0 ;
}
int F_124 ( struct V_70 * V_71 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_43 * V_38 = V_92 -> V_93 ;
struct V_152 * args = V_90 ;
struct V_13 * V_14 ;
int V_5 ;
V_5 = F_62 ( V_71 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_123 ( V_38 , args -> V_149 ) ;
if ( F_27 ( V_14 ) ) {
F_67 ( & V_71 -> V_19 ) ;
return F_43 ( V_14 ) ;
}
args -> V_35 = 0 ;
switch ( args -> V_153 ) {
case V_154 :
V_5 = - V_76 ;
break;
case V_155 :
args -> V_156 = V_14 -> V_98 & V_157 ;
break;
case V_158 :
if ( V_14 -> V_20 )
args -> V_156 = V_14 -> V_20 -> V_37 . V_159 ;
else if ( F_63 ( V_71 ) -> V_128 . V_129 )
args -> V_156 = F_63 ( V_71 ) -> V_128 . V_129 -> V_37 . V_159 ;
else
args -> V_156 = F_63 ( V_71 ) -> V_51 . V_37 . V_159 ;
break;
case V_160 :
args -> V_156 = F_125 ( V_14 ) ;
break;
case V_161 :
args -> V_156 = F_126 ( V_14 ) ;
break;
default:
V_5 = - V_76 ;
break;
}
F_67 ( & V_71 -> V_19 ) ;
return V_5 ;
}
int F_127 ( struct V_70 * V_71 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_43 * V_38 = V_92 -> V_93 ;
struct V_152 * args = V_90 ;
struct V_13 * V_14 ;
int V_5 ;
V_5 = F_62 ( V_71 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_123 ( V_38 , args -> V_149 ) ;
if ( F_27 ( V_14 ) ) {
F_67 ( & V_71 -> V_19 ) ;
return F_43 ( V_14 ) ;
}
switch ( args -> V_153 ) {
case V_154 :
V_5 = - V_76 ;
break;
case V_155 :
if ( args -> V_35 ) {
V_5 = - V_76 ;
} else {
V_14 -> V_98 &= ~ V_157 ;
V_14 -> V_98 |= args -> V_156 ? V_157 : 0 ;
}
break;
case V_160 :
if ( args -> V_35 )
V_5 = - V_76 ;
else if ( args -> V_156 )
F_128 ( V_14 ) ;
else
F_129 ( V_14 ) ;
break;
case V_161 :
if ( args -> V_35 )
V_5 = - V_76 ;
else if ( ! F_130 ( V_162 ) && ! args -> V_156 )
V_5 = - V_163 ;
else if ( args -> V_156 )
F_50 ( V_14 ) ;
else
F_64 ( V_14 ) ;
break;
default:
V_5 = - V_76 ;
break;
}
F_67 ( & V_71 -> V_19 ) ;
return V_5 ;
}
int F_131 ( struct V_70 * V_71 ,
void * V_90 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_63 ( V_71 ) ;
struct V_164 * args = V_90 ;
struct V_13 * V_14 ;
int V_5 ;
if ( args -> V_98 || args -> V_147 )
return - V_76 ;
if ( args -> V_149 == V_53 && ! F_130 ( V_162 ) )
return - V_163 ;
V_5 = F_62 ( V_71 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_123 ( V_92 -> V_93 , args -> V_149 ) ;
if ( F_27 ( V_14 ) ) {
F_67 ( & V_71 -> V_19 ) ;
return F_43 ( V_14 ) ;
}
if ( F_130 ( V_162 ) )
args -> V_165 = F_132 ( & V_2 -> V_166 ) ;
else
args -> V_165 = 0 ;
args -> V_167 = V_14 -> V_168 ;
args -> V_169 = V_14 -> V_170 ;
F_67 ( & V_71 -> V_19 ) ;
return 0 ;
}
