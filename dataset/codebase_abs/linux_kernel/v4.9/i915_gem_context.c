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
F_19 ( V_24 -> V_26 ) ;
}
F_20 ( V_14 -> V_29 ) ;
F_21 ( & V_14 -> V_30 ) ;
F_22 ( & V_14 -> V_17 -> V_31 , V_14 -> V_32 ) ;
F_23 ( V_14 ) ;
}
struct V_33 *
F_24 ( struct V_34 * V_35 , T_1 V_36 )
{
struct V_33 * V_37 ;
int V_5 ;
F_13 ( & V_35 -> V_19 ) ;
V_37 = F_25 ( V_35 , V_36 ) ;
if ( F_26 ( V_37 ) )
return V_37 ;
if ( F_27 ( V_35 ) ) {
V_5 = F_28 ( V_37 , V_38 ) ;
if ( F_17 ( V_5 ) ) {
F_29 ( V_37 ) ;
return F_30 ( V_5 ) ;
}
}
return V_37 ;
}
static void F_31 ( struct V_39 * V_40 )
{
struct V_41 * V_42 [] = {
& V_40 -> V_43 ,
& V_40 -> V_44 ,
& V_40 -> V_45 ,
NULL ,
} , * * V_46 ;
F_15 ( V_40 -> V_20 ) ;
V_40 -> V_20 = true ;
for ( V_46 = V_42 ; * V_46 ; V_46 ++ ) {
struct V_47 * V_48 , * V_49 ;
F_32 (vma, vn, *phase, vm_link)
if ( ! F_33 ( V_48 ) )
F_34 ( V_48 ) ;
}
}
static void F_35 ( struct V_13 * V_14 )
{
F_15 ( V_14 -> V_20 ) ;
V_14 -> V_20 = true ;
if ( V_14 -> V_21 )
F_31 ( & V_14 -> V_21 -> V_50 ) ;
V_14 -> V_51 = F_30 ( - V_52 ) ;
F_36 ( V_14 ) ;
}
static int F_37 ( struct V_1 * V_2 , unsigned * V_53 )
{
int V_5 ;
V_5 = F_38 ( & V_2 -> V_31 ,
0 , V_54 , V_55 ) ;
if ( V_5 < 0 ) {
F_39 ( V_2 ) ;
V_5 = F_38 ( & V_2 -> V_31 ,
0 , V_54 , V_55 ) ;
if ( V_5 < 0 )
return V_5 ;
}
* V_53 = V_5 ;
return 0 ;
}
static struct V_13 *
F_40 ( struct V_34 * V_35 ,
struct V_56 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_35 ) ;
struct V_13 * V_14 ;
int V_5 ;
V_14 = F_42 ( sizeof( * V_14 ) , V_55 ) ;
if ( V_14 == NULL )
return F_30 ( - V_57 ) ;
V_5 = F_37 ( V_2 , & V_14 -> V_32 ) ;
if ( V_5 ) {
F_23 ( V_14 ) ;
return F_30 ( V_5 ) ;
}
F_43 ( & V_14 -> V_15 ) ;
F_44 ( & V_14 -> V_30 , & V_2 -> V_58 ) ;
V_14 -> V_17 = V_2 ;
V_14 -> V_59 = F_1 ( V_2 ) ;
if ( V_2 -> V_60 ) {
struct V_33 * V_37 ;
struct V_47 * V_48 ;
V_37 = F_24 ( V_35 ,
V_2 -> V_60 ) ;
if ( F_26 ( V_37 ) ) {
V_5 = F_45 ( V_37 ) ;
goto V_61;
}
V_48 = F_46 ( V_37 , & V_2 -> V_62 . V_50 , NULL ) ;
if ( F_26 ( V_48 ) ) {
F_29 ( V_37 ) ;
V_5 = F_45 ( V_48 ) ;
goto V_61;
}
V_14 -> V_25 [ V_63 ] . V_26 = V_48 ;
}
if ( V_51 != NULL ) {
V_5 = F_47 ( & V_51 -> V_64 , V_14 ,
V_65 , 0 , V_55 ) ;
if ( V_5 < 0 )
goto V_61;
} else
V_5 = V_65 ;
V_14 -> V_51 = V_51 ;
if ( V_51 )
V_14 -> V_29 = F_48 ( V_66 , V_67 ) ;
V_14 -> V_68 = V_5 ;
V_14 -> V_69 = F_49 ( V_2 ) ;
V_14 -> V_70 . V_71 = V_72 ;
V_14 -> V_73 = 4 * V_74 ;
V_14 -> V_75 = F_50 ( V_2 ) <<
V_76 ;
F_51 ( & V_14 -> V_77 ) ;
return V_14 ;
V_61:
F_35 ( V_14 ) ;
return F_30 ( V_5 ) ;
}
static struct V_13 *
F_52 ( struct V_34 * V_35 ,
struct V_56 * V_51 )
{
struct V_13 * V_14 ;
F_13 ( & V_35 -> V_19 ) ;
V_14 = F_40 ( V_35 , V_51 ) ;
if ( F_26 ( V_14 ) )
return V_14 ;
if ( F_53 ( V_35 ) ) {
struct V_78 * V_21 =
F_54 ( F_41 ( V_35 ) , V_51 ) ;
if ( F_26 ( V_21 ) ) {
F_55 ( L_1 ,
F_45 ( V_21 ) ) ;
F_56 ( & V_51 -> V_64 , V_14 -> V_68 ) ;
F_35 ( V_14 ) ;
return F_57 ( V_21 ) ;
}
V_14 -> V_21 = V_21 ;
}
F_58 ( V_14 ) ;
return V_14 ;
}
struct V_13 *
F_59 ( struct V_34 * V_35 )
{
struct V_13 * V_14 ;
int V_5 ;
if ( ! F_60 ( V_79 ) )
return F_30 ( - V_80 ) ;
V_5 = F_61 ( V_35 ) ;
if ( V_5 )
return F_30 ( V_5 ) ;
V_14 = F_52 ( V_35 , NULL ) ;
if ( F_26 ( V_14 ) )
goto V_53;
V_14 -> V_81 = true ;
V_14 -> V_73 = 512 * V_74 ;
V_53:
F_62 ( & V_35 -> V_19 ) ;
return V_14 ;
}
static void F_63 ( struct V_13 * V_14 ,
struct V_82 * V_25 )
{
if ( V_17 . V_83 ) {
F_64 ( V_14 , V_25 ) ;
} else {
struct V_23 * V_24 = & V_14 -> V_25 [ V_25 -> V_84 ] ;
if ( V_24 -> V_26 )
F_65 ( V_24 -> V_26 ) ;
F_36 ( V_14 ) ;
}
}
int F_66 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_41 ( V_35 ) ;
struct V_13 * V_14 ;
if ( F_17 ( V_2 -> V_85 ) )
return 0 ;
if ( F_67 ( V_2 ) &&
F_68 ( V_2 ) ) {
if ( ! V_17 . V_83 ) {
F_69 ( L_2 ) ;
return - V_86 ;
}
}
F_70 ( V_54 > V_87 ) ;
F_71 ( & V_2 -> V_31 ) ;
if ( V_17 . V_83 ) {
V_2 -> V_60 = 0 ;
} else if ( F_72 ( V_2 ) ) {
V_2 -> V_60 =
F_73 ( F_3 ( V_2 ) , 4096 ) ;
if ( V_2 -> V_60 > ( 1 << 20 ) ) {
F_55 ( L_3 ,
V_2 -> V_60 ) ;
V_2 -> V_60 = 0 ;
}
}
V_14 = F_52 ( V_35 , NULL ) ;
if ( F_26 ( V_14 ) ) {
F_74 ( L_4 ,
F_45 ( V_14 ) ) ;
return F_45 ( V_14 ) ;
}
V_2 -> V_85 = V_14 ;
F_55 ( L_5 ,
V_17 . V_83 ? L_6 :
V_2 -> V_60 ? L_7 : L_8 ) ;
return 0 ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_82 * V_25 ;
F_13 ( & V_2 -> V_18 . V_19 ) ;
F_76 (engine, dev_priv) {
if ( V_25 -> V_88 ) {
F_63 ( V_25 -> V_88 , V_25 ) ;
V_25 -> V_88 = NULL ;
}
}
if ( ! V_17 . V_83 ) {
struct V_13 * V_14 ;
F_77 (ctx, &dev_priv->context_list, link) {
if ( ! F_78 ( V_14 ) )
continue;
F_76 (engine, dev_priv)
V_14 -> V_25 [ V_25 -> V_84 ] . V_89 = false ;
V_14 -> V_69 = F_49 ( V_2 ) ;
}
F_76 (engine, dev_priv) {
struct V_23 * V_90 =
& V_2 -> V_85 -> V_25 [ V_25 -> V_84 ] ;
V_90 -> V_89 = true ;
}
}
}
void F_79 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_41 ( V_35 ) ;
struct V_13 * V_91 = V_2 -> V_85 ;
F_13 ( & V_35 -> V_19 ) ;
F_35 ( V_91 ) ;
V_2 -> V_85 = NULL ;
F_80 ( & V_2 -> V_31 ) ;
}
static int F_81 ( int V_84 , void * V_92 , void * V_93 )
{
struct V_13 * V_14 = V_92 ;
F_35 ( V_14 ) ;
return 0 ;
}
int F_82 ( struct V_34 * V_35 , struct V_94 * V_95 )
{
struct V_56 * V_51 = V_95 -> V_96 ;
struct V_13 * V_14 ;
F_83 ( & V_51 -> V_64 ) ;
F_84 ( & V_35 -> V_19 ) ;
V_14 = F_52 ( V_35 , V_51 ) ;
F_62 ( & V_35 -> V_19 ) ;
if ( F_26 ( V_14 ) ) {
F_85 ( & V_51 -> V_64 ) ;
return F_45 ( V_14 ) ;
}
return 0 ;
}
void F_86 ( struct V_34 * V_35 , struct V_94 * V_95 )
{
struct V_56 * V_51 = V_95 -> V_96 ;
F_13 ( & V_35 -> V_19 ) ;
F_87 ( & V_51 -> V_64 , F_81 , NULL ) ;
F_85 ( & V_51 -> V_64 ) ;
}
static inline int
F_88 ( struct V_97 * V_98 , T_2 V_99 )
{
struct V_1 * V_2 = V_98 -> V_17 ;
struct V_100 * V_28 = V_98 -> V_28 ;
struct V_82 * V_25 = V_98 -> V_25 ;
T_2 V_101 = V_99 | V_102 ;
const int V_103 =
V_17 . V_104 ?
F_89 ( V_2 ) -> V_103 - 1 :
0 ;
int V_105 , V_5 ;
if ( F_2 ( V_2 ) ) {
V_5 = V_25 -> V_106 ( V_98 , V_107 ) ;
if ( V_5 )
return V_5 ;
}
if ( F_7 ( V_2 ) || F_4 ( V_2 ) >= 8 )
V_101 |= ( V_108 | V_109 ) ;
else if ( F_4 ( V_2 ) < 8 )
V_101 |= ( V_110 | V_111 ) ;
V_105 = 4 ;
if ( F_4 ( V_2 ) >= 7 )
V_105 += 2 + ( V_103 ? 4 * V_103 + 6 : 0 ) ;
V_5 = F_90 ( V_98 , V_105 ) ;
if ( V_5 )
return V_5 ;
if ( F_4 ( V_2 ) >= 7 ) {
F_91 ( V_28 , V_112 | V_113 ) ;
if ( V_103 ) {
struct V_82 * V_114 ;
F_91 ( V_28 ,
F_92 ( V_103 ) ) ;
F_76 (signaller, dev_priv) {
if ( V_114 == V_25 )
continue;
F_93 ( V_28 ,
F_94 ( V_114 -> V_115 ) ) ;
F_91 ( V_28 ,
F_95 ( V_116 ) ) ;
}
}
}
F_91 ( V_28 , V_117 ) ;
F_91 ( V_28 , V_118 ) ;
F_91 ( V_28 ,
F_96 ( V_98 -> V_14 -> V_25 [ V_63 ] . V_26 ) | V_101 ) ;
F_91 ( V_28 , V_117 ) ;
if ( F_4 ( V_2 ) >= 7 ) {
if ( V_103 ) {
struct V_82 * V_114 ;
T_3 V_119 = {} ;
F_91 ( V_28 ,
F_92 ( V_103 ) ) ;
F_76 (signaller, dev_priv) {
if ( V_114 == V_25 )
continue;
V_119 = F_94 ( V_114 -> V_115 ) ;
F_93 ( V_28 , V_119 ) ;
F_91 ( V_28 ,
F_97 ( V_116 ) ) ;
}
F_91 ( V_28 ,
V_120 |
V_121 ) ;
F_93 ( V_28 , V_119 ) ;
F_91 ( V_28 ,
F_96 ( V_25 -> V_122 ) ) ;
F_91 ( V_28 , V_117 ) ;
}
F_91 ( V_28 , V_112 | V_123 ) ;
}
F_98 ( V_28 ) ;
return V_5 ;
}
static int F_99 ( struct V_97 * V_98 , int V_124 )
{
T_2 * V_125 = V_98 -> V_17 -> V_126 . V_125 [ V_124 ] ;
struct V_100 * V_28 = V_98 -> V_28 ;
int V_16 , V_5 ;
if ( ! V_125 )
return 0 ;
V_5 = F_90 ( V_98 , V_127 / 4 * 2 + 2 ) ;
if ( V_5 )
return V_5 ;
F_91 ( V_28 , F_92 ( V_127 / 4 ) ) ;
for ( V_16 = 0 ; V_16 < V_127 / 4 ; V_16 ++ ) {
F_93 ( V_28 , F_100 ( V_124 , V_16 ) ) ;
F_91 ( V_28 , V_125 [ V_16 ] ) ;
}
F_91 ( V_28 , V_117 ) ;
F_98 ( V_28 ) ;
return 0 ;
}
static inline bool F_101 ( struct V_78 * V_21 ,
struct V_82 * V_25 ,
struct V_13 * V_128 )
{
if ( V_128 -> V_69 )
return false ;
if ( ! V_128 -> V_25 [ V_63 ] . V_89 )
return false ;
if ( V_21 && ( F_102 ( V_25 ) & V_21 -> V_129 ) )
return false ;
return V_128 == V_25 -> V_88 ;
}
static bool
F_103 ( struct V_78 * V_21 ,
struct V_82 * V_25 ,
struct V_13 * V_128 )
{
if ( ! V_21 )
return false ;
if ( ! V_25 -> V_88 )
return true ;
if ( V_25 -> V_88 == V_128 &&
! ( F_102 ( V_25 ) & V_21 -> V_129 ) )
return false ;
if ( V_25 -> V_84 != V_63 )
return true ;
if ( F_4 ( V_25 -> V_17 ) < 8 )
return true ;
return false ;
}
static bool
F_104 ( struct V_78 * V_21 ,
struct V_13 * V_128 ,
T_2 V_99 )
{
if ( ! V_21 )
return false ;
if ( ! F_105 ( V_128 -> V_17 ) )
return false ;
if ( V_99 & V_130 )
return true ;
return false ;
}
static int F_106 ( struct V_97 * V_98 )
{
struct V_13 * V_128 = V_98 -> V_14 ;
struct V_82 * V_25 = V_98 -> V_25 ;
struct V_78 * V_21 = V_128 -> V_21 ? : V_98 -> V_17 -> V_131 . V_132 ;
struct V_47 * V_48 = V_128 -> V_25 [ V_63 ] . V_26 ;
struct V_13 * V_133 ;
T_2 V_99 ;
int V_5 , V_16 ;
if ( F_101 ( V_21 , V_25 , V_128 ) )
return 0 ;
if ( ! ( V_48 -> V_101 & V_134 ) ) {
V_5 = F_107 ( V_48 -> V_37 , false ) ;
if ( V_5 )
return V_5 ;
}
V_5 = F_108 ( V_48 , 0 , V_128 -> V_59 , V_135 ) ;
if ( V_5 )
return V_5 ;
V_133 = V_25 -> V_88 ;
if ( F_103 ( V_21 , V_25 , V_128 ) ) {
F_109 ( V_25 , V_128 ) ;
V_5 = V_21 -> V_136 ( V_21 , V_98 ) ;
if ( V_5 )
goto V_137;
}
if ( ! V_128 -> V_25 [ V_63 ] . V_89 || F_78 ( V_128 ) )
V_99 = V_130 ;
else if ( V_21 && F_102 ( V_25 ) & V_21 -> V_129 )
V_99 = V_138 ;
else
V_99 = 0 ;
if ( V_128 != V_133 || ( V_99 & V_138 ) ) {
V_5 = F_88 ( V_98 , V_99 ) ;
if ( V_5 )
goto V_137;
}
if ( V_133 != NULL ) {
F_110 ( V_133 -> V_25 [ V_63 ] . V_26 , V_98 , 0 ) ;
F_65 ( V_133 -> V_25 [ V_63 ] . V_26 ) ;
F_36 ( V_133 ) ;
}
V_25 -> V_88 = F_111 ( V_128 ) ;
if ( F_104 ( V_21 , V_128 , V_99 ) ) {
F_109 ( V_25 , V_128 ) ;
V_5 = V_21 -> V_136 ( V_21 , V_98 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_21 )
V_21 -> V_129 &= ~ F_102 ( V_25 ) ;
for ( V_16 = 0 ; V_16 < V_139 ; V_16 ++ ) {
if ( ! ( V_128 -> V_69 & ( 1 << V_16 ) ) )
continue;
V_5 = F_99 ( V_98 , V_16 ) ;
if ( V_5 )
return V_5 ;
V_128 -> V_69 &= ~ ( 1 << V_16 ) ;
}
if ( ! V_128 -> V_25 [ V_63 ] . V_89 ) {
if ( V_25 -> V_140 ) {
V_5 = V_25 -> V_140 ( V_98 ) ;
if ( V_5 )
return V_5 ;
}
V_128 -> V_25 [ V_63 ] . V_89 = true ;
}
return 0 ;
V_137:
F_65 ( V_48 ) ;
return V_5 ;
}
int F_112 ( struct V_97 * V_98 )
{
struct V_82 * V_25 = V_98 -> V_25 ;
F_13 ( & V_98 -> V_17 -> V_18 . V_19 ) ;
if ( V_17 . V_83 )
return 0 ;
if ( ! V_98 -> V_14 -> V_25 [ V_25 -> V_84 ] . V_26 ) {
struct V_13 * V_128 = V_98 -> V_14 ;
struct V_78 * V_21 =
V_128 -> V_21 ? : V_98 -> V_17 -> V_131 . V_132 ;
if ( F_103 ( V_21 , V_25 , V_128 ) ) {
int V_5 ;
F_109 ( V_25 , V_128 ) ;
V_5 = V_21 -> V_136 ( V_21 , V_98 ) ;
if ( V_5 )
return V_5 ;
V_21 -> V_129 &= ~ F_102 ( V_25 ) ;
}
if ( V_128 != V_25 -> V_88 ) {
if ( V_25 -> V_88 )
F_36 ( V_25 -> V_88 ) ;
V_25 -> V_88 = F_111 ( V_128 ) ;
}
return 0 ;
}
return F_106 ( V_98 ) ;
}
int F_113 ( struct V_1 * V_2 )
{
struct V_82 * V_25 ;
F_76 (engine, dev_priv) {
struct V_97 * V_98 ;
int V_5 ;
if ( V_25 -> V_88 == NULL )
continue;
if ( V_25 -> V_88 == V_2 -> V_85 )
continue;
V_98 = F_114 ( V_25 , V_2 -> V_85 ) ;
if ( F_26 ( V_98 ) )
return F_45 ( V_98 ) ;
V_5 = F_112 ( V_98 ) ;
F_115 ( V_98 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static bool F_116 ( struct V_34 * V_35 )
{
return V_17 . V_83 || F_41 ( V_35 ) -> V_60 ;
}
int F_117 ( struct V_34 * V_35 , void * V_93 ,
struct V_94 * V_95 )
{
struct V_141 * args = V_93 ;
struct V_56 * V_51 = V_95 -> V_96 ;
struct V_13 * V_14 ;
int V_5 ;
if ( ! F_116 ( V_35 ) )
return - V_80 ;
if ( args -> V_142 != 0 )
return - V_86 ;
V_5 = F_61 ( V_35 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_52 ( V_35 , V_51 ) ;
F_62 ( & V_35 -> V_19 ) ;
if ( F_26 ( V_14 ) )
return F_45 ( V_14 ) ;
args -> V_143 = V_14 -> V_68 ;
F_55 ( L_9 , args -> V_143 ) ;
return 0 ;
}
int F_118 ( struct V_34 * V_35 , void * V_93 ,
struct V_94 * V_95 )
{
struct V_144 * args = V_93 ;
struct V_56 * V_51 = V_95 -> V_96 ;
struct V_13 * V_14 ;
int V_5 ;
if ( args -> V_142 != 0 )
return - V_86 ;
if ( args -> V_143 == V_65 )
return - V_145 ;
V_5 = F_61 ( V_35 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_119 ( V_51 , args -> V_143 ) ;
if ( F_26 ( V_14 ) ) {
F_62 ( & V_35 -> V_19 ) ;
return F_45 ( V_14 ) ;
}
F_56 ( & V_51 -> V_64 , V_14 -> V_68 ) ;
F_35 ( V_14 ) ;
F_62 ( & V_35 -> V_19 ) ;
F_55 ( L_10 , args -> V_143 ) ;
return 0 ;
}
int F_120 ( struct V_34 * V_35 , void * V_93 ,
struct V_94 * V_95 )
{
struct V_56 * V_51 = V_95 -> V_96 ;
struct V_146 * args = V_93 ;
struct V_13 * V_14 ;
int V_5 ;
V_5 = F_61 ( V_35 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_119 ( V_51 , args -> V_143 ) ;
if ( F_26 ( V_14 ) ) {
F_62 ( & V_35 -> V_19 ) ;
return F_45 ( V_14 ) ;
}
args -> V_36 = 0 ;
switch ( args -> V_147 ) {
case V_148 :
args -> V_149 = V_14 -> V_70 . V_71 ;
break;
case V_150 :
args -> V_149 = V_14 -> V_101 & V_151 ;
break;
case V_152 :
if ( V_14 -> V_21 )
args -> V_149 = V_14 -> V_21 -> V_50 . V_153 ;
else if ( F_41 ( V_35 ) -> V_131 . V_132 )
args -> V_149 = F_41 ( V_35 ) -> V_131 . V_132 -> V_50 . V_153 ;
else
args -> V_149 = F_41 ( V_35 ) -> V_62 . V_50 . V_153 ;
break;
case V_154 :
args -> V_149 = ! ! ( V_14 -> V_101 & V_155 ) ;
break;
default:
V_5 = - V_86 ;
break;
}
F_62 ( & V_35 -> V_19 ) ;
return V_5 ;
}
int F_121 ( struct V_34 * V_35 , void * V_93 ,
struct V_94 * V_95 )
{
struct V_56 * V_51 = V_95 -> V_96 ;
struct V_146 * args = V_93 ;
struct V_13 * V_14 ;
int V_5 ;
V_5 = F_61 ( V_35 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_119 ( V_51 , args -> V_143 ) ;
if ( F_26 ( V_14 ) ) {
F_62 ( & V_35 -> V_19 ) ;
return F_45 ( V_14 ) ;
}
switch ( args -> V_147 ) {
case V_148 :
if ( args -> V_36 )
V_5 = - V_86 ;
else if ( args -> V_149 < V_14 -> V_70 . V_71 &&
! F_122 ( V_156 ) )
V_5 = - V_157 ;
else
V_14 -> V_70 . V_71 = args -> V_149 ;
break;
case V_150 :
if ( args -> V_36 ) {
V_5 = - V_86 ;
} else {
V_14 -> V_101 &= ~ V_151 ;
V_14 -> V_101 |= args -> V_149 ? V_151 : 0 ;
}
break;
case V_154 :
if ( args -> V_36 ) {
V_5 = - V_86 ;
} else {
if ( args -> V_149 )
V_14 -> V_101 |= V_155 ;
else
V_14 -> V_101 &= ~ V_155 ;
}
break;
default:
V_5 = - V_86 ;
break;
}
F_62 ( & V_35 -> V_19 ) ;
return V_5 ;
}
int F_123 ( struct V_34 * V_35 ,
void * V_93 , struct V_94 * V_95 )
{
struct V_1 * V_2 = F_41 ( V_35 ) ;
struct V_158 * args = V_93 ;
struct V_159 * V_160 ;
struct V_13 * V_14 ;
int V_5 ;
if ( args -> V_101 || args -> V_142 )
return - V_86 ;
if ( args -> V_143 == V_65 && ! F_122 ( V_156 ) )
return - V_157 ;
V_5 = F_61 ( V_35 ) ;
if ( V_5 )
return V_5 ;
V_14 = F_119 ( V_95 -> V_96 , args -> V_143 ) ;
if ( F_26 ( V_14 ) ) {
F_62 ( & V_35 -> V_19 ) ;
return F_45 ( V_14 ) ;
}
V_160 = & V_14 -> V_70 ;
if ( F_122 ( V_156 ) )
args -> V_161 = F_124 ( & V_2 -> V_162 ) ;
else
args -> V_161 = 0 ;
args -> V_163 = V_160 -> V_163 ;
args -> V_164 = V_160 -> V_164 ;
F_62 ( & V_35 -> V_19 ) ;
return 0 ;
}
