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
static void F_10 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 , * V_17 ;
if ( ! V_14 )
return;
F_11 (vma, next, &ppgtt->base.inactive_list,
vm_link) {
if ( F_12 ( F_13 ( V_16 ) ) )
break;
}
}
void F_14 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_15 ( V_19 , F_16 ( * V_12 ) , V_20 ) ;
int V_21 ;
F_17 ( & V_12 -> V_22 -> V_23 . V_24 ) ;
F_18 ( V_12 ) ;
F_10 ( V_12 ) ;
F_19 ( V_12 -> V_14 ) ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
struct V_26 * V_27 = & V_12 -> V_28 [ V_21 ] ;
if ( ! V_27 -> V_29 )
continue;
F_12 ( V_27 -> V_30 ) ;
if ( V_27 -> V_31 )
F_20 ( V_27 -> V_31 ) ;
F_21 ( & V_27 -> V_29 -> V_32 ) ;
}
F_22 ( & V_12 -> V_33 ) ;
F_23 ( & V_12 -> V_22 -> V_34 , V_12 -> V_35 ) ;
F_24 ( V_12 ) ;
}
struct V_36 *
F_25 ( struct V_37 * V_38 , T_1 V_39 )
{
struct V_36 * V_40 ;
int V_5 ;
F_17 ( & V_38 -> V_24 ) ;
V_40 = F_26 ( V_38 , V_39 ) ;
if ( F_27 ( V_40 ) )
return V_40 ;
if ( F_28 ( V_38 ) ) {
V_5 = F_29 ( V_40 , V_41 ) ;
if ( F_12 ( V_5 ) ) {
F_21 ( & V_40 -> V_32 ) ;
return F_30 ( V_5 ) ;
}
}
return V_40 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned * V_42 )
{
int V_5 ;
V_5 = F_32 ( & V_2 -> V_34 ,
0 , V_43 , V_44 ) ;
if ( V_5 < 0 ) {
F_33 ( V_2 ) ;
V_5 = F_32 ( & V_2 -> V_34 ,
0 , V_43 , V_44 ) ;
if ( V_5 < 0 )
return V_5 ;
}
* V_42 = V_5 ;
return 0 ;
}
static struct V_11 *
F_34 ( struct V_37 * V_38 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = F_35 ( V_38 ) ;
struct V_11 * V_12 ;
int V_5 ;
V_12 = F_36 ( sizeof( * V_12 ) , V_44 ) ;
if ( V_12 == NULL )
return F_30 ( - V_47 ) ;
V_5 = F_31 ( V_2 , & V_12 -> V_35 ) ;
if ( V_5 ) {
F_24 ( V_12 ) ;
return F_30 ( V_5 ) ;
}
F_37 ( & V_12 -> V_20 ) ;
F_38 ( & V_12 -> V_33 , & V_2 -> V_48 ) ;
V_12 -> V_22 = V_2 ;
V_12 -> V_49 = F_1 ( V_2 ) ;
if ( V_2 -> V_50 ) {
struct V_36 * V_40 =
F_25 ( V_38 , V_2 -> V_50 ) ;
if ( F_27 ( V_40 ) ) {
V_5 = F_39 ( V_40 ) ;
goto V_51;
}
V_12 -> V_28 [ V_52 ] . V_29 = V_40 ;
}
if ( V_46 != NULL ) {
V_5 = F_40 ( & V_46 -> V_53 , V_12 ,
V_54 , 0 , V_44 ) ;
if ( V_5 < 0 )
goto V_51;
} else
V_5 = V_54 ;
V_12 -> V_46 = V_46 ;
V_12 -> V_55 = V_5 ;
V_12 -> V_56 = F_41 ( V_2 ) ;
V_12 -> V_57 . V_58 = V_59 ;
V_12 -> V_60 = 4 * V_61 ;
V_12 -> V_62 = F_42 ( V_2 ) <<
V_63 ;
F_43 ( & V_12 -> V_64 ) ;
return V_12 ;
V_51:
F_44 ( V_12 ) ;
return F_30 ( V_5 ) ;
}
static struct V_11 *
F_45 ( struct V_37 * V_38 ,
struct V_45 * V_46 )
{
struct V_11 * V_12 ;
F_17 ( & V_38 -> V_24 ) ;
V_12 = F_34 ( V_38 , V_46 ) ;
if ( F_27 ( V_12 ) )
return V_12 ;
if ( F_46 ( V_38 ) ) {
struct V_13 * V_14 = F_47 ( V_38 , V_46 ) ;
if ( F_27 ( V_14 ) ) {
F_48 ( L_1 ,
F_39 ( V_14 ) ) ;
F_49 ( & V_46 -> V_53 , V_12 -> V_55 ) ;
F_44 ( V_12 ) ;
return F_50 ( V_14 ) ;
}
V_12 -> V_14 = V_14 ;
}
F_51 ( V_12 ) ;
return V_12 ;
}
struct V_11 *
F_52 ( struct V_37 * V_38 )
{
struct V_11 * V_12 ;
int V_5 ;
if ( ! F_53 ( V_65 ) )
return F_30 ( - V_66 ) ;
V_5 = F_54 ( V_38 ) ;
if ( V_5 )
return F_30 ( V_5 ) ;
V_12 = F_45 ( V_38 , NULL ) ;
if ( F_27 ( V_12 ) )
goto V_42;
V_12 -> V_67 = true ;
V_12 -> V_60 = 512 * V_61 ;
V_42:
F_55 ( & V_38 -> V_24 ) ;
return V_12 ;
}
static void F_56 ( struct V_11 * V_12 ,
struct V_68 * V_28 )
{
if ( V_22 . V_69 ) {
F_57 ( V_12 , V_28 ) ;
} else {
struct V_26 * V_27 = & V_12 -> V_28 [ V_28 -> V_70 ] ;
if ( V_27 -> V_29 )
F_58 ( V_27 -> V_29 ) ;
F_44 ( V_12 ) ;
}
}
void F_59 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_35 ( V_38 ) ;
F_17 ( & V_38 -> V_24 ) ;
if ( V_22 . V_69 ) {
struct V_11 * V_12 ;
F_60 (ctx, &dev_priv->context_list, link)
F_61 ( V_2 , V_12 ) ;
}
F_62 ( V_2 ) ;
}
int F_63 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_35 ( V_38 ) ;
struct V_11 * V_12 ;
if ( F_12 ( V_2 -> V_71 ) )
return 0 ;
if ( F_64 ( V_2 ) &&
F_65 ( V_2 ) ) {
if ( ! V_22 . V_69 ) {
F_66 ( L_2 ) ;
return - V_72 ;
}
}
F_67 ( V_43 > V_73 ) ;
F_68 ( & V_2 -> V_34 ) ;
if ( V_22 . V_69 ) {
V_2 -> V_50 = 0 ;
} else if ( F_69 ( V_2 ) ) {
V_2 -> V_50 =
F_70 ( F_3 ( V_2 ) , 4096 ) ;
if ( V_2 -> V_50 > ( 1 << 20 ) ) {
F_48 ( L_3 ,
V_2 -> V_50 ) ;
V_2 -> V_50 = 0 ;
}
}
V_12 = F_45 ( V_38 , NULL ) ;
if ( F_27 ( V_12 ) ) {
F_71 ( L_4 ,
F_39 ( V_12 ) ) ;
return F_39 ( V_12 ) ;
}
V_2 -> V_71 = V_12 ;
F_48 ( L_5 ,
V_22 . V_69 ? L_6 :
V_2 -> V_50 ? L_7 : L_8 ) ;
return 0 ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_68 * V_28 ;
F_17 ( & V_2 -> V_23 . V_24 ) ;
F_72 (engine, dev_priv) {
if ( V_28 -> V_74 ) {
F_56 ( V_28 -> V_74 , V_28 ) ;
V_28 -> V_74 = NULL ;
}
}
if ( ! V_22 . V_69 ) {
struct V_11 * V_12 ;
F_60 (ctx, &dev_priv->context_list, link) {
if ( ! F_73 ( V_12 ) )
continue;
F_72 (engine, dev_priv)
V_12 -> V_28 [ V_28 -> V_70 ] . V_75 = false ;
V_12 -> V_56 = F_41 ( V_2 ) ;
}
F_72 (engine, dev_priv) {
struct V_26 * V_76 =
& V_2 -> V_71 -> V_28 [ V_28 -> V_70 ] ;
V_76 -> V_75 = true ;
}
}
}
void F_74 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_35 ( V_38 ) ;
struct V_11 * V_77 = V_2 -> V_71 ;
F_17 ( & V_38 -> V_24 ) ;
F_44 ( V_77 ) ;
V_2 -> V_71 = NULL ;
F_75 ( & V_2 -> V_34 ) ;
}
static int F_76 ( int V_70 , void * V_78 , void * V_79 )
{
struct V_11 * V_12 = V_78 ;
V_12 -> V_46 = F_30 ( - V_80 ) ;
F_44 ( V_12 ) ;
return 0 ;
}
int F_77 ( struct V_37 * V_38 , struct V_81 * V_82 )
{
struct V_45 * V_46 = V_82 -> V_83 ;
struct V_11 * V_12 ;
F_78 ( & V_46 -> V_53 ) ;
F_79 ( & V_38 -> V_24 ) ;
V_12 = F_45 ( V_38 , V_46 ) ;
F_55 ( & V_38 -> V_24 ) ;
if ( F_27 ( V_12 ) ) {
F_80 ( & V_46 -> V_53 ) ;
return F_39 ( V_12 ) ;
}
return 0 ;
}
void F_81 ( struct V_37 * V_38 , struct V_81 * V_82 )
{
struct V_45 * V_46 = V_82 -> V_83 ;
F_17 ( & V_38 -> V_24 ) ;
F_82 ( & V_46 -> V_53 , F_76 , NULL ) ;
F_80 ( & V_46 -> V_53 ) ;
}
static inline int
F_83 ( struct V_84 * V_85 , T_2 V_86 )
{
struct V_1 * V_2 = V_85 -> V_22 ;
struct V_68 * V_28 = V_85 -> V_28 ;
T_2 V_87 = V_86 | V_88 ;
const int V_89 =
F_84 ( V_2 ) ?
F_85 ( F_86 ( V_2 ) -> V_90 ) - 1 :
0 ;
int V_91 , V_5 ;
if ( F_2 ( V_2 ) ) {
V_5 = V_28 -> V_92 ( V_85 , V_93 , 0 ) ;
if ( V_5 )
return V_5 ;
}
if ( F_7 ( V_2 ) || F_4 ( V_2 ) >= 8 )
V_87 |= ( V_94 | V_95 ) ;
else if ( F_4 ( V_2 ) < 8 )
V_87 |= ( V_96 | V_97 ) ;
V_91 = 4 ;
if ( F_4 ( V_2 ) >= 7 )
V_91 += 2 + ( V_89 ? 4 * V_89 + 6 : 0 ) ;
V_5 = F_87 ( V_85 , V_91 ) ;
if ( V_5 )
return V_5 ;
if ( F_4 ( V_2 ) >= 7 ) {
F_88 ( V_28 , V_98 | V_99 ) ;
if ( V_89 ) {
struct V_68 * V_100 ;
F_88 ( V_28 ,
F_89 ( V_89 ) ) ;
F_72 (signaller, dev_priv) {
if ( V_100 == V_28 )
continue;
F_90 ( V_28 ,
F_91 ( V_100 -> V_101 ) ) ;
F_88 ( V_28 ,
F_92 ( V_102 ) ) ;
}
}
}
F_88 ( V_28 , V_103 ) ;
F_88 ( V_28 , V_104 ) ;
F_88 ( V_28 ,
F_93 ( V_85 -> V_12 -> V_28 [ V_52 ] . V_29 ) |
V_87 ) ;
F_88 ( V_28 , V_103 ) ;
if ( F_4 ( V_2 ) >= 7 ) {
if ( V_89 ) {
struct V_68 * V_100 ;
T_3 V_105 = {} ;
F_88 ( V_28 ,
F_89 ( V_89 ) ) ;
F_72 (signaller, dev_priv) {
if ( V_100 == V_28 )
continue;
V_105 = F_91 ( V_100 -> V_101 ) ;
F_90 ( V_28 , V_105 ) ;
F_88 ( V_28 ,
F_94 ( V_102 ) ) ;
}
F_88 ( V_28 ,
V_106 |
V_107 ) ;
F_90 ( V_28 , V_105 ) ;
F_88 ( V_28 , V_28 -> V_108 . V_109 ) ;
F_88 ( V_28 , V_103 ) ;
}
F_88 ( V_28 , V_98 | V_110 ) ;
}
F_95 ( V_28 ) ;
return V_5 ;
}
static int F_96 ( struct V_84 * V_85 , int V_111 )
{
T_2 * V_112 = V_85 -> V_22 -> V_113 . V_112 [ V_111 ] ;
struct V_68 * V_28 = V_85 -> V_28 ;
int V_21 , V_5 ;
if ( ! V_112 )
return 0 ;
V_5 = F_87 ( V_85 , V_114 / 4 * 2 + 2 ) ;
if ( V_5 )
return V_5 ;
F_88 ( V_28 , F_89 ( V_114 / 4 ) ) ;
for ( V_21 = 0 ; V_21 < V_114 / 4 ; V_21 ++ ) {
F_90 ( V_28 , F_97 ( V_111 , V_21 ) ) ;
F_88 ( V_28 , V_112 [ V_21 ] ) ;
}
F_88 ( V_28 , V_103 ) ;
F_95 ( V_28 ) ;
return 0 ;
}
static inline bool F_98 ( struct V_13 * V_14 ,
struct V_68 * V_28 ,
struct V_11 * V_115 )
{
if ( V_115 -> V_56 )
return false ;
if ( ! V_115 -> V_28 [ V_52 ] . V_75 )
return false ;
if ( V_14 && ( F_99 ( V_28 ) & V_14 -> V_116 ) )
return false ;
return V_115 == V_28 -> V_74 ;
}
static bool
F_100 ( struct V_13 * V_14 ,
struct V_68 * V_28 ,
struct V_11 * V_115 )
{
if ( ! V_14 )
return false ;
if ( ! V_28 -> V_74 )
return true ;
if ( V_28 -> V_74 == V_115 &&
! ( F_99 ( V_28 ) & V_14 -> V_116 ) )
return false ;
if ( V_28 -> V_70 != V_52 )
return true ;
if ( F_4 ( V_28 -> V_22 ) < 8 )
return true ;
return false ;
}
static bool
F_101 ( struct V_13 * V_14 ,
struct V_11 * V_115 ,
T_2 V_86 )
{
if ( ! V_14 )
return false ;
if ( ! F_102 ( V_115 -> V_22 ) )
return false ;
if ( V_86 & V_117 )
return true ;
return false ;
}
static int F_103 ( struct V_84 * V_85 )
{
struct V_11 * V_115 = V_85 -> V_12 ;
struct V_68 * V_28 = V_85 -> V_28 ;
struct V_13 * V_14 = V_115 -> V_14 ? : V_85 -> V_22 -> V_118 . V_119 ;
struct V_11 * V_120 ;
T_2 V_86 ;
int V_5 , V_21 ;
if ( F_98 ( V_14 , V_28 , V_115 ) )
return 0 ;
V_5 = F_104 ( V_115 -> V_28 [ V_52 ] . V_29 ,
V_115 -> V_49 ,
0 ) ;
if ( V_5 )
return V_5 ;
V_120 = V_28 -> V_74 ;
V_5 = F_105 ( V_115 -> V_28 [ V_52 ] . V_29 , false ) ;
if ( V_5 )
goto V_121;
if ( F_100 ( V_14 , V_28 , V_115 ) ) {
F_106 ( V_28 , V_115 ) ;
V_5 = V_14 -> V_122 ( V_14 , V_85 ) ;
if ( V_5 )
goto V_121;
}
if ( ! V_115 -> V_28 [ V_52 ] . V_75 || F_73 ( V_115 ) )
V_86 = V_117 ;
else if ( V_14 && F_99 ( V_28 ) & V_14 -> V_116 )
V_86 = V_123 ;
else
V_86 = 0 ;
if ( V_115 != V_120 || ( V_86 & V_123 ) ) {
V_5 = F_83 ( V_85 , V_86 ) ;
if ( V_5 )
goto V_121;
}
if ( V_120 != NULL ) {
V_120 -> V_28 [ V_52 ] . V_29 -> V_32 . V_124 = V_125 ;
F_107 ( F_108 ( V_120 -> V_28 [ V_52 ] . V_29 ) , V_85 ) ;
V_120 -> V_28 [ V_52 ] . V_29 -> V_126 = 1 ;
F_58 ( V_120 -> V_28 [ V_52 ] . V_29 ) ;
F_44 ( V_120 ) ;
}
F_109 ( V_115 ) ;
V_28 -> V_74 = V_115 ;
if ( F_101 ( V_14 , V_115 , V_86 ) ) {
F_106 ( V_28 , V_115 ) ;
V_5 = V_14 -> V_122 ( V_14 , V_85 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_14 )
V_14 -> V_116 &= ~ F_99 ( V_28 ) ;
for ( V_21 = 0 ; V_21 < V_127 ; V_21 ++ ) {
if ( ! ( V_115 -> V_56 & ( 1 << V_21 ) ) )
continue;
V_5 = F_96 ( V_85 , V_21 ) ;
if ( V_5 )
return V_5 ;
V_115 -> V_56 &= ~ ( 1 << V_21 ) ;
}
if ( ! V_115 -> V_28 [ V_52 ] . V_75 ) {
if ( V_28 -> V_128 ) {
V_5 = V_28 -> V_128 ( V_85 ) ;
if ( V_5 )
return V_5 ;
}
V_115 -> V_28 [ V_52 ] . V_75 = true ;
}
return 0 ;
V_121:
F_58 ( V_115 -> V_28 [ V_52 ] . V_29 ) ;
return V_5 ;
}
int F_110 ( struct V_84 * V_85 )
{
struct V_68 * V_28 = V_85 -> V_28 ;
F_12 ( V_22 . V_69 ) ;
F_17 ( & V_85 -> V_22 -> V_23 . V_24 ) ;
if ( ! V_85 -> V_12 -> V_28 [ V_28 -> V_70 ] . V_29 ) {
struct V_11 * V_115 = V_85 -> V_12 ;
struct V_13 * V_14 =
V_115 -> V_14 ? : V_85 -> V_22 -> V_118 . V_119 ;
if ( F_100 ( V_14 , V_28 , V_115 ) ) {
int V_5 ;
F_106 ( V_28 , V_115 ) ;
V_5 = V_14 -> V_122 ( V_14 , V_85 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_116 &= ~ F_99 ( V_28 ) ;
}
if ( V_115 != V_28 -> V_74 ) {
F_109 ( V_115 ) ;
if ( V_28 -> V_74 )
F_44 ( V_28 -> V_74 ) ;
V_28 -> V_74 = V_115 ;
}
return 0 ;
}
return F_103 ( V_85 ) ;
}
static bool F_111 ( struct V_37 * V_38 )
{
return V_22 . V_69 || F_35 ( V_38 ) -> V_50 ;
}
int F_112 ( struct V_37 * V_38 , void * V_79 ,
struct V_81 * V_82 )
{
struct V_129 * args = V_79 ;
struct V_45 * V_46 = V_82 -> V_83 ;
struct V_11 * V_12 ;
int V_5 ;
if ( ! F_111 ( V_38 ) )
return - V_66 ;
if ( args -> V_130 != 0 )
return - V_72 ;
V_5 = F_54 ( V_38 ) ;
if ( V_5 )
return V_5 ;
V_12 = F_45 ( V_38 , V_46 ) ;
F_55 ( & V_38 -> V_24 ) ;
if ( F_27 ( V_12 ) )
return F_39 ( V_12 ) ;
args -> V_131 = V_12 -> V_55 ;
F_48 ( L_9 , args -> V_131 ) ;
return 0 ;
}
int F_113 ( struct V_37 * V_38 , void * V_79 ,
struct V_81 * V_82 )
{
struct V_132 * args = V_79 ;
struct V_45 * V_46 = V_82 -> V_83 ;
struct V_11 * V_12 ;
int V_5 ;
if ( args -> V_130 != 0 )
return - V_72 ;
if ( args -> V_131 == V_54 )
return - V_133 ;
V_5 = F_54 ( V_38 ) ;
if ( V_5 )
return V_5 ;
V_12 = F_114 ( V_46 , args -> V_131 ) ;
if ( F_27 ( V_12 ) ) {
F_55 ( & V_38 -> V_24 ) ;
return F_39 ( V_12 ) ;
}
F_49 ( & V_46 -> V_53 , V_12 -> V_55 ) ;
F_44 ( V_12 ) ;
F_55 ( & V_38 -> V_24 ) ;
F_48 ( L_10 , args -> V_131 ) ;
return 0 ;
}
int F_115 ( struct V_37 * V_38 , void * V_79 ,
struct V_81 * V_82 )
{
struct V_45 * V_46 = V_82 -> V_83 ;
struct V_134 * args = V_79 ;
struct V_11 * V_12 ;
int V_5 ;
V_5 = F_54 ( V_38 ) ;
if ( V_5 )
return V_5 ;
V_12 = F_114 ( V_46 , args -> V_131 ) ;
if ( F_27 ( V_12 ) ) {
F_55 ( & V_38 -> V_24 ) ;
return F_39 ( V_12 ) ;
}
args -> V_39 = 0 ;
switch ( args -> V_135 ) {
case V_136 :
args -> V_137 = V_12 -> V_57 . V_58 ;
break;
case V_138 :
args -> V_137 = V_12 -> V_87 & V_139 ;
break;
case V_140 :
if ( V_12 -> V_14 )
args -> V_137 = V_12 -> V_14 -> V_32 . V_141 ;
else if ( F_35 ( V_38 ) -> V_118 . V_119 )
args -> V_137 = F_35 ( V_38 ) -> V_118 . V_119 -> V_32 . V_141 ;
else
args -> V_137 = F_35 ( V_38 ) -> V_142 . V_32 . V_141 ;
break;
case V_143 :
args -> V_137 = ! ! ( V_12 -> V_87 & V_144 ) ;
break;
default:
V_5 = - V_72 ;
break;
}
F_55 ( & V_38 -> V_24 ) ;
return V_5 ;
}
int F_116 ( struct V_37 * V_38 , void * V_79 ,
struct V_81 * V_82 )
{
struct V_45 * V_46 = V_82 -> V_83 ;
struct V_134 * args = V_79 ;
struct V_11 * V_12 ;
int V_5 ;
V_5 = F_54 ( V_38 ) ;
if ( V_5 )
return V_5 ;
V_12 = F_114 ( V_46 , args -> V_131 ) ;
if ( F_27 ( V_12 ) ) {
F_55 ( & V_38 -> V_24 ) ;
return F_39 ( V_12 ) ;
}
switch ( args -> V_135 ) {
case V_136 :
if ( args -> V_39 )
V_5 = - V_72 ;
else if ( args -> V_137 < V_12 -> V_57 . V_58 &&
! F_117 ( V_145 ) )
V_5 = - V_146 ;
else
V_12 -> V_57 . V_58 = args -> V_137 ;
break;
case V_138 :
if ( args -> V_39 ) {
V_5 = - V_72 ;
} else {
V_12 -> V_87 &= ~ V_139 ;
V_12 -> V_87 |= args -> V_137 ? V_139 : 0 ;
}
break;
case V_143 :
if ( args -> V_39 ) {
V_5 = - V_72 ;
} else {
if ( args -> V_137 )
V_12 -> V_87 |= V_144 ;
else
V_12 -> V_87 &= ~ V_144 ;
}
break;
default:
V_5 = - V_72 ;
break;
}
F_55 ( & V_38 -> V_24 ) ;
return V_5 ;
}
int F_118 ( struct V_37 * V_38 ,
void * V_79 , struct V_81 * V_82 )
{
struct V_1 * V_2 = F_35 ( V_38 ) ;
struct V_147 * args = V_79 ;
struct V_148 * V_149 ;
struct V_11 * V_12 ;
int V_5 ;
if ( args -> V_87 || args -> V_130 )
return - V_72 ;
if ( args -> V_131 == V_54 && ! F_117 ( V_145 ) )
return - V_146 ;
V_5 = F_54 ( V_38 ) ;
if ( V_5 )
return V_5 ;
V_12 = F_114 ( V_82 -> V_83 , args -> V_131 ) ;
if ( F_27 ( V_12 ) ) {
F_55 ( & V_38 -> V_24 ) ;
return F_39 ( V_12 ) ;
}
V_149 = & V_12 -> V_57 ;
if ( F_117 ( V_145 ) )
args -> V_150 = F_119 ( & V_2 -> V_151 ) ;
else
args -> V_150 = 0 ;
args -> V_152 = V_149 -> V_152 ;
args -> V_153 = V_149 -> V_153 ;
F_55 ( & V_38 -> V_24 ) ;
return 0 ;
}
