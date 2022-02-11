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
F_15 ( ! V_14 -> V_20 ) ;
F_16 ( V_14 -> V_21 ) ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
struct V_23 * V_24 = & V_14 -> V_25 [ V_16 ] ;
if ( ! V_24 -> V_26 )
continue;
F_17 ( V_24 -> V_27 ) ;
if ( V_24 -> V_28 )
F_18 ( V_24 -> V_28 ) ;
F_19 ( V_24 -> V_26 -> V_29 ) ;
}
F_20 ( V_14 -> V_30 ) ;
F_21 ( V_14 -> V_31 ) ;
F_22 ( & V_14 -> V_32 ) ;
F_23 ( & V_14 -> V_17 -> V_33 , V_14 -> V_34 ) ;
F_20 ( V_14 ) ;
}
struct V_35 *
F_24 ( struct V_36 * V_37 , T_1 V_38 )
{
struct V_35 * V_29 ;
int V_5 ;
F_13 ( & V_37 -> V_19 ) ;
V_29 = F_25 ( V_37 , V_38 ) ;
if ( F_26 ( V_29 ) )
return V_29 ;
if ( F_27 ( F_28 ( V_37 ) ) ) {
V_5 = F_29 ( V_29 , V_39 ) ;
if ( F_17 ( V_5 ) ) {
F_30 ( V_29 ) ;
return F_31 ( V_5 ) ;
}
}
return V_29 ;
}
static void F_32 ( struct V_40 * V_41 )
{
struct V_42 * V_43 [] = {
& V_41 -> V_44 ,
& V_41 -> V_45 ,
& V_41 -> V_46 ,
NULL ,
} , * * V_47 ;
F_15 ( V_41 -> V_20 ) ;
V_41 -> V_20 = true ;
for ( V_47 = V_43 ; * V_47 ; V_47 ++ ) {
struct V_48 * V_49 , * V_50 ;
F_33 (vma, vn, *phase, vm_link)
if ( ! F_34 ( V_49 ) )
F_35 ( V_49 ) ;
}
}
static void F_36 ( struct V_13 * V_14 )
{
F_15 ( V_14 -> V_20 ) ;
V_14 -> V_20 = true ;
if ( V_14 -> V_21 )
F_32 ( & V_14 -> V_21 -> V_51 ) ;
V_14 -> V_52 = F_31 ( - V_53 ) ;
F_37 ( V_14 ) ;
}
static int F_38 ( struct V_1 * V_2 , unsigned * V_54 )
{
int V_5 ;
V_5 = F_39 ( & V_2 -> V_33 ,
0 , V_55 , V_56 ) ;
if ( V_5 < 0 ) {
F_40 ( V_2 ) ;
V_5 = F_39 ( & V_2 -> V_33 ,
0 , V_55 , V_56 ) ;
if ( V_5 < 0 )
return V_5 ;
}
* V_54 = V_5 ;
return 0 ;
}
static struct V_13 *
F_41 ( struct V_36 * V_37 ,
struct V_57 * V_52 )
{
struct V_1 * V_2 = F_28 ( V_37 ) ;
struct V_13 * V_14 ;
int V_5 ;
V_14 = F_42 ( sizeof( * V_14 ) , V_56 ) ;
if ( V_14 == NULL )
return F_31 ( - V_58 ) ;
V_5 = F_38 ( V_2 , & V_14 -> V_34 ) ;
if ( V_5 ) {
F_20 ( V_14 ) ;
return F_31 ( V_5 ) ;
}
F_43 ( & V_14 -> V_15 ) ;
F_44 ( & V_14 -> V_32 , & V_2 -> V_59 ) ;
V_14 -> V_17 = V_2 ;
V_14 -> V_60 = F_1 ( V_2 ) ;
if ( V_2 -> V_61 ) {
struct V_35 * V_29 ;
struct V_48 * V_49 ;
V_29 = F_24 ( V_37 ,
V_2 -> V_61 ) ;
if ( F_26 ( V_29 ) ) {
V_5 = F_45 ( V_29 ) ;
goto V_62;
}
V_49 = F_46 ( V_29 , & V_2 -> V_63 . V_51 , NULL ) ;
if ( F_26 ( V_49 ) ) {
F_30 ( V_29 ) ;
V_5 = F_45 ( V_49 ) ;
goto V_62;
}
V_14 -> V_25 [ V_64 ] . V_26 = V_49 ;
}
V_5 = V_65 ;
if ( V_52 ) {
V_5 = F_47 ( & V_52 -> V_66 , V_14 ,
V_65 , 0 , V_56 ) ;
if ( V_5 < 0 )
goto V_62;
}
V_14 -> V_67 = V_5 ;
V_14 -> V_52 = V_52 ;
if ( V_52 ) {
V_14 -> V_31 = F_48 ( V_68 , V_69 ) ;
V_14 -> V_30 = F_49 ( V_56 , L_1 ,
V_68 -> V_70 ,
F_50 ( V_14 -> V_31 ) ,
V_14 -> V_67 ) ;
if ( ! V_14 -> V_30 ) {
V_5 = - V_58 ;
goto V_71;
}
}
V_14 -> V_72 = F_51 ( V_2 ) ;
V_14 -> V_73 . V_74 = V_75 ;
V_14 -> V_76 = 4 * V_77 ;
V_14 -> V_78 = F_52 ( V_2 ) <<
V_79 ;
F_53 ( & V_14 -> V_80 ) ;
return V_14 ;
V_71:
F_21 ( V_14 -> V_31 ) ;
F_54 ( & V_52 -> V_66 , V_14 -> V_67 ) ;
V_62:
F_36 ( V_14 ) ;
return F_31 ( V_5 ) ;
}
static struct V_13 *
F_55 ( struct V_36 * V_37 ,
struct V_57 * V_52 )
{
struct V_13 * V_14 ;
F_13 ( & V_37 -> V_19 ) ;
V_14 = F_41 ( V_37 , V_52 ) ;
if ( F_26 ( V_14 ) )
return V_14 ;
if ( F_56 ( V_37 ) ) {
struct V_81 * V_21 ;
V_21 = F_57 ( F_28 ( V_37 ) , V_52 , V_14 -> V_30 ) ;
if ( F_26 ( V_21 ) ) {
F_58 ( L_2 ,
F_45 ( V_21 ) ) ;
F_54 ( & V_52 -> V_66 , V_14 -> V_67 ) ;
F_36 ( V_14 ) ;
return F_59 ( V_21 ) ;
}
V_14 -> V_21 = V_21 ;
}
F_60 ( V_14 ) ;
return V_14 ;
}
struct V_13 *
F_61 ( struct V_36 * V_37 )
{
struct V_13 * V_14 ;
int V_5 ;
if ( ! F_62 ( V_82 ) )
return F_31 ( - V_83 ) ;
V_5 = F_63 ( V_37 ) ;
if ( V_5 )
return F_31 ( V_5 ) ;
V_14 = F_55 ( V_37 , NULL ) ;
if ( F_26 ( V_14 ) )
goto V_54;
V_14 -> V_84 = true ;
V_14 -> V_76 = 512 * V_77 ;
V_54:
F_64 ( & V_37 -> V_19 ) ;
return V_14 ;
}
static void F_65 ( struct V_13 * V_14 ,
struct V_85 * V_25 )
{
if ( V_17 . V_86 ) {
F_66 ( V_14 , V_25 ) ;
} else {
struct V_23 * V_24 = & V_14 -> V_25 [ V_25 -> V_87 ] ;
if ( V_24 -> V_26 )
F_67 ( V_24 -> V_26 ) ;
F_37 ( V_14 ) ;
}
}
int F_68 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_28 ( V_37 ) ;
struct V_13 * V_14 ;
if ( F_17 ( V_2 -> V_88 ) )
return 0 ;
if ( F_69 ( V_2 ) &&
F_70 ( V_2 ) ) {
if ( ! V_17 . V_86 ) {
F_71 ( L_3 ) ;
return - V_89 ;
}
}
F_72 ( V_55 > V_90 ) ;
F_73 ( & V_2 -> V_33 ) ;
if ( V_17 . V_86 ) {
V_2 -> V_61 = 0 ;
} else if ( F_74 ( V_2 ) ) {
V_2 -> V_61 =
F_75 ( F_3 ( V_2 ) , 4096 ) ;
if ( V_2 -> V_61 > ( 1 << 20 ) ) {
F_58 ( L_4 ,
V_2 -> V_61 ) ;
V_2 -> V_61 = 0 ;
}
}
V_14 = F_55 ( V_37 , NULL ) ;
if ( F_26 ( V_14 ) ) {
F_76 ( L_5 ,
F_45 ( V_14 ) ) ;
return F_45 ( V_14 ) ;
}
V_14 -> V_91 = V_92 ;
V_2 -> V_88 = V_14 ;
F_58 ( L_6 ,
V_17 . V_86 ? L_7 :
V_2 -> V_61 ? L_8 : L_9 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_85 * V_25 ;
enum V_93 V_87 ;
F_13 ( & V_2 -> V_18 . V_19 ) ;
F_78 (engine, dev_priv, id) {
if ( V_25 -> V_94 ) {
F_65 ( V_25 -> V_94 , V_25 ) ;
V_25 -> V_94 = NULL ;
}
}
if ( ! V_17 . V_86 ) {
struct V_13 * V_14 ;
F_79 (ctx, &dev_priv->context_list, link) {
if ( ! F_80 ( V_14 ) )
continue;
F_78 (engine, dev_priv, id)
V_14 -> V_25 [ V_25 -> V_87 ] . V_95 = false ;
V_14 -> V_72 = F_51 ( V_2 ) ;
}
F_78 (engine, dev_priv, id) {
struct V_23 * V_96 =
& V_2 -> V_88 -> V_25 [ V_25 -> V_87 ] ;
V_96 -> V_95 = true ;
}
}
}
void F_81 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_28 ( V_37 ) ;
struct V_13 * V_97 = V_2 -> V_88 ;
F_13 ( & V_37 -> V_19 ) ;
F_36 ( V_97 ) ;
V_2 -> V_88 = NULL ;
F_82 ( & V_2 -> V_33 ) ;
}
static int F_83 ( int V_87 , void * V_98 , void * V_99 )
{
struct V_13 * V_14 = V_98 ;
F_36 ( V_14 ) ;
return 0 ;
}
int F_84 ( struct V_36 * V_37 , struct V_100 * V_101 )
{
struct V_57 * V_52 = V_101 -> V_102 ;
struct V_13 * V_14 ;
F_85 ( & V_52 -> V_66 ) ;
F_86 ( & V_37 -> V_19 ) ;
V_14 = F_55 ( V_37 , V_52 ) ;
F_64 ( & V_37 -> V_19 ) ;
if ( F_26 ( V_14 ) ) {
F_87 ( & V_52 -> V_66 ) ;
return F_45 ( V_14 ) ;
}
return 0 ;
}
void F_88 ( struct V_36 * V_37 , struct V_100 * V_101 )
{
struct V_57 * V_52 = V_101 -> V_102 ;
F_13 ( & V_37 -> V_19 ) ;
F_89 ( & V_52 -> V_66 , F_83 , NULL ) ;
F_87 ( & V_52 -> V_66 ) ;
}
static inline int
F_90 ( struct V_103 * V_104 , T_2 V_105 )
{
struct V_1 * V_2 = V_104 -> V_17 ;
struct V_106 * V_28 = V_104 -> V_28 ;
struct V_85 * V_25 = V_104 -> V_25 ;
enum V_93 V_87 ;
T_2 V_107 = V_105 | V_108 ;
const int V_109 =
V_17 . V_110 ?
F_91 ( V_2 ) -> V_109 - 1 :
0 ;
int V_111 , V_5 ;
if ( F_2 ( V_2 ) ) {
V_5 = V_25 -> V_112 ( V_104 , V_113 ) ;
if ( V_5 )
return V_5 ;
}
if ( F_7 ( V_2 ) || F_4 ( V_2 ) >= 8 )
V_107 |= ( V_114 | V_115 ) ;
else if ( F_4 ( V_2 ) < 8 )
V_107 |= ( V_116 | V_117 ) ;
V_111 = 4 ;
if ( F_4 ( V_2 ) >= 7 )
V_111 += 2 + ( V_109 ? 4 * V_109 + 6 : 0 ) ;
V_5 = F_92 ( V_104 , V_111 ) ;
if ( V_5 )
return V_5 ;
if ( F_4 ( V_2 ) >= 7 ) {
F_93 ( V_28 , V_118 | V_119 ) ;
if ( V_109 ) {
struct V_85 * V_120 ;
F_93 ( V_28 ,
F_94 ( V_109 ) ) ;
F_78 (signaller, dev_priv, id) {
if ( V_120 == V_25 )
continue;
F_95 ( V_28 ,
F_96 ( V_120 -> V_121 ) ) ;
F_93 ( V_28 ,
F_97 ( V_122 ) ) ;
}
}
}
F_93 ( V_28 , V_123 ) ;
F_93 ( V_28 , V_124 ) ;
F_93 ( V_28 ,
F_98 ( V_104 -> V_14 -> V_25 [ V_64 ] . V_26 ) | V_107 ) ;
F_93 ( V_28 , V_123 ) ;
if ( F_4 ( V_2 ) >= 7 ) {
if ( V_109 ) {
struct V_85 * V_120 ;
T_3 V_125 = {} ;
F_93 ( V_28 ,
F_94 ( V_109 ) ) ;
F_78 (signaller, dev_priv, id) {
if ( V_120 == V_25 )
continue;
V_125 = F_96 ( V_120 -> V_121 ) ;
F_95 ( V_28 , V_125 ) ;
F_93 ( V_28 ,
F_99 ( V_122 ) ) ;
}
F_93 ( V_28 ,
V_126 |
V_127 ) ;
F_95 ( V_28 , V_125 ) ;
F_93 ( V_28 ,
F_98 ( V_25 -> V_128 ) ) ;
F_93 ( V_28 , V_123 ) ;
}
F_93 ( V_28 , V_118 | V_129 ) ;
}
F_100 ( V_28 ) ;
return V_5 ;
}
static int F_101 ( struct V_103 * V_104 , int V_130 )
{
T_2 * V_131 = V_104 -> V_17 -> V_132 . V_131 [ V_130 ] ;
struct V_106 * V_28 = V_104 -> V_28 ;
int V_16 , V_5 ;
if ( ! V_131 )
return 0 ;
V_5 = F_92 ( V_104 , V_133 / 4 * 2 + 2 ) ;
if ( V_5 )
return V_5 ;
F_93 ( V_28 , F_94 ( V_133 / 4 ) ) ;
for ( V_16 = 0 ; V_16 < V_133 / 4 ; V_16 ++ ) {
F_95 ( V_28 , F_102 ( V_130 , V_16 ) ) ;
F_93 ( V_28 , V_131 [ V_16 ] ) ;
}
F_93 ( V_28 , V_123 ) ;
F_100 ( V_28 ) ;
return 0 ;
}
static inline bool F_103 ( struct V_81 * V_21 ,
struct V_85 * V_25 ,
struct V_13 * V_134 )
{
if ( V_134 -> V_72 )
return false ;
if ( ! V_134 -> V_25 [ V_64 ] . V_95 )
return false ;
if ( V_21 && ( F_104 ( V_25 ) & V_21 -> V_135 ) )
return false ;
return V_134 == V_25 -> V_94 ;
}
static bool
F_105 ( struct V_81 * V_21 ,
struct V_85 * V_25 ,
struct V_13 * V_134 )
{
if ( ! V_21 )
return false ;
if ( ! V_25 -> V_94 )
return true ;
if ( V_25 -> V_94 == V_134 &&
! ( F_104 ( V_25 ) & V_21 -> V_135 ) )
return false ;
if ( V_25 -> V_87 != V_64 )
return true ;
if ( F_4 ( V_25 -> V_17 ) < 8 )
return true ;
return false ;
}
static bool
F_106 ( struct V_81 * V_21 ,
struct V_13 * V_134 ,
T_2 V_105 )
{
if ( ! V_21 )
return false ;
if ( ! F_107 ( V_134 -> V_17 ) )
return false ;
if ( V_105 & V_136 )
return true ;
return false ;
}
struct V_48 *
F_108 ( struct V_13 * V_14 ,
unsigned int V_107 )
{
struct V_48 * V_49 = V_14 -> V_25 [ V_64 ] . V_26 ;
int V_5 ;
if ( ! ( V_49 -> V_107 & V_137 ) ) {
V_5 = F_109 ( V_49 -> V_29 , false ) ;
if ( V_5 )
return F_31 ( V_5 ) ;
}
V_5 = F_110 ( V_49 , 0 , V_14 -> V_60 , V_138 | V_107 ) ;
if ( V_5 )
return F_31 ( V_5 ) ;
return V_49 ;
}
static int F_111 ( struct V_103 * V_104 )
{
struct V_13 * V_134 = V_104 -> V_14 ;
struct V_85 * V_25 = V_104 -> V_25 ;
struct V_81 * V_21 = V_134 -> V_21 ? : V_104 -> V_17 -> V_139 . V_140 ;
struct V_48 * V_49 ;
struct V_13 * V_141 ;
T_2 V_105 ;
int V_5 , V_16 ;
if ( F_103 ( V_21 , V_25 , V_134 ) )
return 0 ;
V_49 = F_108 ( V_134 , 0 ) ;
if ( F_26 ( V_49 ) )
return F_45 ( V_49 ) ;
V_141 = V_25 -> V_94 ;
if ( F_105 ( V_21 , V_25 , V_134 ) ) {
F_112 ( V_25 , V_134 ) ;
V_5 = V_21 -> V_142 ( V_21 , V_104 ) ;
if ( V_5 )
goto V_143;
}
if ( ! V_134 -> V_25 [ V_64 ] . V_95 || F_80 ( V_134 ) )
V_105 = V_136 ;
else if ( V_21 && F_104 ( V_25 ) & V_21 -> V_135 )
V_105 = V_144 ;
else
V_105 = 0 ;
if ( V_134 != V_141 || ( V_105 & V_144 ) ) {
V_5 = F_90 ( V_104 , V_105 ) ;
if ( V_5 )
goto V_143;
}
if ( V_141 != NULL ) {
F_113 ( V_141 -> V_25 [ V_64 ] . V_26 , V_104 , 0 ) ;
F_67 ( V_141 -> V_25 [ V_64 ] . V_26 ) ;
F_37 ( V_141 ) ;
}
V_25 -> V_94 = F_114 ( V_134 ) ;
if ( F_106 ( V_21 , V_134 , V_105 ) ) {
F_112 ( V_25 , V_134 ) ;
V_5 = V_21 -> V_142 ( V_21 , V_104 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_21 )
V_21 -> V_135 &= ~ F_104 ( V_25 ) ;
for ( V_16 = 0 ; V_16 < V_145 ; V_16 ++ ) {
if ( ! ( V_134 -> V_72 & ( 1 << V_16 ) ) )
continue;
V_5 = F_101 ( V_104 , V_16 ) ;
if ( V_5 )
return V_5 ;
V_134 -> V_72 &= ~ ( 1 << V_16 ) ;
}
if ( ! V_134 -> V_25 [ V_64 ] . V_95 ) {
if ( V_25 -> V_146 ) {
V_5 = V_25 -> V_146 ( V_104 ) ;
if ( V_5 )
return V_5 ;
}
V_134 -> V_25 [ V_64 ] . V_95 = true ;
}
return 0 ;
V_143:
F_67 ( V_49 ) ;
return V_5 ;
}
int F_115 ( struct V_103 * V_104 )
{
struct V_85 * V_25 = V_104 -> V_25 ;
F_13 ( & V_104 -> V_17 -> V_18 . V_19 ) ;
if ( V_17 . V_86 )
return 0 ;
if ( ! V_104 -> V_14 -> V_25 [ V_25 -> V_87 ] . V_26 ) {
struct V_13 * V_134 = V_104 -> V_14 ;
struct V_81 * V_21 =
V_134 -> V_21 ? : V_104 -> V_17 -> V_139 . V_140 ;
if ( F_105 ( V_21 , V_25 , V_134 ) ) {
int V_5 ;
F_112 ( V_25 , V_134 ) ;
V_5 = V_21 -> V_142 ( V_21 , V_104 ) ;
if ( V_5 )
return V_5 ;
V_21 -> V_135 &= ~ F_104 ( V_25 ) ;
}
if ( V_134 != V_25 -> V_94 ) {
if ( V_25 -> V_94 )
F_37 ( V_25 -> V_94 ) ;
V_25 -> V_94 = F_114 ( V_134 ) ;
}
return 0 ;
}
return F_111 ( V_104 ) ;
}
int F_116 ( struct V_1 * V_2 )
{
struct V_85 * V_25 ;
struct V_147 * V_148 ;
enum V_93 V_87 ;
F_13 ( & V_2 -> V_18 . V_19 ) ;
F_78 (engine, dev_priv, id) {
struct V_103 * V_104 ;
int V_5 ;
V_104 = F_117 ( V_25 , V_2 -> V_88 ) ;
if ( F_26 ( V_104 ) )
return F_45 ( V_104 ) ;
F_79 (timeline, &dev_priv->gt.timelines, link) {
struct V_103 * V_149 ;
struct V_150 * V_151 ;
V_151 = & V_148 -> V_25 [ V_25 -> V_87 ] ;
V_149 = F_118 ( & V_151 -> V_152 ,
& V_2 -> V_18 . V_19 ) ;
if ( V_149 )
F_119 ( & V_104 -> V_153 ,
& V_149 -> V_153 ,
V_56 ) ;
}
V_5 = F_115 ( V_104 ) ;
F_120 ( V_104 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static bool F_121 ( struct V_36 * V_37 )
{
return V_17 . V_86 || F_28 ( V_37 ) -> V_61 ;
}
int F_122 ( struct V_36 * V_37 , void * V_99 ,
struct V_100 * V_101 )
{
struct V_154 * args = V_99 ;
struct V_57 * V_52 = V_101 -> V_102 ;
struct V_13 * V_14 ;
int V_5 ;
if ( ! F_121 ( V_37 ) )
return - V_83 ;
if ( args -> V_155 != 0 )
return - V_89 ;
V_5 = F_63 ( V_37 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_55 ( V_37 , V_52 ) ;
F_64 ( & V_37 -> V_19 ) ;
if ( F_26 ( V_14 ) )
return F_45 ( V_14 ) ;
args -> V_156 = V_14 -> V_67 ;
F_58 ( L_10 , args -> V_156 ) ;
return 0 ;
}
int F_123 ( struct V_36 * V_37 , void * V_99 ,
struct V_100 * V_101 )
{
struct V_157 * args = V_99 ;
struct V_57 * V_52 = V_101 -> V_102 ;
struct V_13 * V_14 ;
int V_5 ;
if ( args -> V_155 != 0 )
return - V_89 ;
if ( args -> V_156 == V_65 )
return - V_158 ;
V_5 = F_63 ( V_37 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_124 ( V_52 , args -> V_156 ) ;
if ( F_26 ( V_14 ) ) {
F_64 ( & V_37 -> V_19 ) ;
return F_45 ( V_14 ) ;
}
F_54 ( & V_52 -> V_66 , V_14 -> V_67 ) ;
F_36 ( V_14 ) ;
F_64 ( & V_37 -> V_19 ) ;
F_58 ( L_11 , args -> V_156 ) ;
return 0 ;
}
int F_125 ( struct V_36 * V_37 , void * V_99 ,
struct V_100 * V_101 )
{
struct V_57 * V_52 = V_101 -> V_102 ;
struct V_159 * args = V_99 ;
struct V_13 * V_14 ;
int V_5 ;
V_5 = F_63 ( V_37 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_124 ( V_52 , args -> V_156 ) ;
if ( F_26 ( V_14 ) ) {
F_64 ( & V_37 -> V_19 ) ;
return F_45 ( V_14 ) ;
}
args -> V_38 = 0 ;
switch ( args -> V_160 ) {
case V_161 :
args -> V_162 = V_14 -> V_73 . V_74 ;
break;
case V_163 :
args -> V_162 = V_14 -> V_107 & V_164 ;
break;
case V_165 :
if ( V_14 -> V_21 )
args -> V_162 = V_14 -> V_21 -> V_51 . V_166 ;
else if ( F_28 ( V_37 ) -> V_139 . V_140 )
args -> V_162 = F_28 ( V_37 ) -> V_139 . V_140 -> V_51 . V_166 ;
else
args -> V_162 = F_28 ( V_37 ) -> V_63 . V_51 . V_166 ;
break;
case V_167 :
args -> V_162 = ! ! ( V_14 -> V_107 & V_168 ) ;
break;
default:
V_5 = - V_89 ;
break;
}
F_64 ( & V_37 -> V_19 ) ;
return V_5 ;
}
int F_126 ( struct V_36 * V_37 , void * V_99 ,
struct V_100 * V_101 )
{
struct V_57 * V_52 = V_101 -> V_102 ;
struct V_159 * args = V_99 ;
struct V_13 * V_14 ;
int V_5 ;
V_5 = F_63 ( V_37 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_124 ( V_52 , args -> V_156 ) ;
if ( F_26 ( V_14 ) ) {
F_64 ( & V_37 -> V_19 ) ;
return F_45 ( V_14 ) ;
}
switch ( args -> V_160 ) {
case V_161 :
if ( args -> V_38 )
V_5 = - V_89 ;
else if ( args -> V_162 < V_14 -> V_73 . V_74 &&
! F_127 ( V_169 ) )
V_5 = - V_170 ;
else
V_14 -> V_73 . V_74 = args -> V_162 ;
break;
case V_163 :
if ( args -> V_38 ) {
V_5 = - V_89 ;
} else {
V_14 -> V_107 &= ~ V_164 ;
V_14 -> V_107 |= args -> V_162 ? V_164 : 0 ;
}
break;
case V_167 :
if ( args -> V_38 ) {
V_5 = - V_89 ;
} else {
if ( args -> V_162 )
V_14 -> V_107 |= V_168 ;
else
V_14 -> V_107 &= ~ V_168 ;
}
break;
default:
V_5 = - V_89 ;
break;
}
F_64 ( & V_37 -> V_19 ) ;
return V_5 ;
}
int F_128 ( struct V_36 * V_37 ,
void * V_99 , struct V_100 * V_101 )
{
struct V_1 * V_2 = F_28 ( V_37 ) ;
struct V_171 * args = V_99 ;
struct V_172 * V_173 ;
struct V_13 * V_14 ;
int V_5 ;
if ( args -> V_107 || args -> V_155 )
return - V_89 ;
if ( args -> V_156 == V_65 && ! F_127 ( V_169 ) )
return - V_170 ;
V_5 = F_63 ( V_37 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_124 ( V_101 -> V_102 , args -> V_156 ) ;
if ( F_26 ( V_14 ) ) {
F_64 ( & V_37 -> V_19 ) ;
return F_45 ( V_14 ) ;
}
V_173 = & V_14 -> V_73 ;
if ( F_127 ( V_169 ) )
args -> V_174 = F_129 ( & V_2 -> V_175 ) ;
else
args -> V_174 = 0 ;
args -> V_176 = V_173 -> V_176 ;
args -> V_177 = V_173 -> V_177 ;
F_64 ( & V_37 -> V_19 ) ;
return 0 ;
}
