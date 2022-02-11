static inline int F_1 ( T_1 * V_1 )
{
return V_1 [ 5 ] ;
}
static void F_2 ( struct V_2 * V_3 , T_1 * V_1 )
{
struct V_4 * V_5 ;
int V_6 = F_1 ( V_1 ) ;
int V_7 = 0 ;
F_3 (hn, &hash[ix], hlist)
if ( F_4 ( V_5 -> V_8 . V_1 , V_1 ) ) {
V_7 = 1 ;
break;
}
if ( V_7 ) {
V_5 -> V_9 = V_10 ;
return;
}
V_5 = F_5 ( sizeof( * V_5 ) , V_11 ) ;
if ( ! V_5 )
return;
F_6 ( V_5 -> V_8 . V_1 , V_1 ) ;
V_5 -> V_9 = V_12 ;
F_7 ( & V_5 -> V_13 , & V_3 [ V_6 ] ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
F_9 ( & V_5 -> V_13 ) ;
F_10 ( V_5 ) ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_19 ;
int V_20 ;
T_2 * V_21 ;
int V_22 ;
int V_23 ;
int V_24 ;
V_20 = 0 ;
F_12 (vlan, priv->fs.vlan.active_vlans, VLAN_N_VID)
V_20 ++ ;
V_19 = 1 << F_13 ( V_15 -> V_25 , V_26 ) ;
if ( V_20 > V_19 ) {
F_14 ( V_17 ,
L_1 ,
V_20 , V_19 ) ;
V_20 = V_19 ;
}
V_21 = F_15 ( V_20 , sizeof( * V_21 ) , V_27 ) ;
if ( ! V_21 )
return - V_28 ;
V_24 = 0 ;
F_12 (vlan, priv->fs.vlan.active_vlans, VLAN_N_VID) {
if ( V_24 >= V_20 )
break;
V_21 [ V_24 ++ ] = V_22 ;
}
V_23 = F_16 ( V_15 -> V_25 , V_21 , V_20 ) ;
if ( V_23 )
F_17 ( V_17 , L_2 ,
V_23 ) ;
F_10 ( V_21 ) ;
return V_23 ;
}
static int F_18 ( struct V_14 * V_15 ,
enum V_29 V_30 ,
T_2 V_31 , struct V_32 * V_33 )
{
struct V_34 V_35 = {
. V_9 = V_36 ,
. V_37 = V_38 ,
. V_39 = 0 ,
} ;
struct V_40 * V_41 = V_15 -> V_42 . V_22 . V_41 . V_43 ;
struct V_44 V_45 ;
struct V_46 * * V_47 ;
int V_23 = 0 ;
V_45 . type = V_48 ;
V_45 . V_41 = V_15 -> V_42 . V_49 . V_41 . V_43 ;
V_33 -> V_50 = V_51 ;
switch ( V_30 ) {
case V_52 :
V_47 = & V_15 -> V_42 . V_22 . V_53 ;
F_19 ( V_54 , V_33 -> V_55 ,
V_56 . V_57 ) ;
break;
case V_58 :
V_47 = & V_15 -> V_42 . V_22 . V_59 ;
F_19 ( V_54 , V_33 -> V_55 ,
V_56 . V_57 ) ;
F_20 ( V_54 , V_33 -> V_60 , V_56 . V_57 , 1 ) ;
break;
case V_61 :
V_47 = & V_15 -> V_42 . V_22 . V_62 ;
F_19 ( V_54 , V_33 -> V_55 ,
V_56 . V_63 ) ;
F_20 ( V_54 , V_33 -> V_60 , V_56 . V_63 , 1 ) ;
break;
default:
V_47 = & V_15 -> V_42 . V_22 . V_64 [ V_31 ] ;
F_19 ( V_54 , V_33 -> V_55 ,
V_56 . V_57 ) ;
F_20 ( V_54 , V_33 -> V_60 , V_56 . V_57 , 1 ) ;
F_19 ( V_54 , V_33 -> V_55 ,
V_56 . V_65 ) ;
F_20 ( V_54 , V_33 -> V_60 , V_56 . V_65 ,
V_31 ) ;
break;
}
* V_47 = F_21 ( V_41 , V_33 , & V_35 , & V_45 , 1 ) ;
if ( F_22 ( * V_47 ) ) {
V_23 = F_23 ( * V_47 ) ;
* V_47 = NULL ;
F_17 ( V_15 -> V_18 , L_3 , V_66 ) ;
}
return V_23 ;
}
static int F_24 ( struct V_14 * V_15 ,
enum V_29 V_30 , T_2 V_31 )
{
struct V_32 * V_33 ;
int V_23 = 0 ;
V_33 = F_25 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_66 ) ;
return - V_28 ;
}
if ( V_30 == V_67 )
F_11 ( V_15 ) ;
V_23 = F_18 ( V_15 , V_30 , V_31 , V_33 ) ;
F_26 ( V_33 ) ;
return V_23 ;
}
static void F_27 ( struct V_14 * V_15 ,
enum V_29 V_30 , T_2 V_31 )
{
switch ( V_30 ) {
case V_52 :
if ( V_15 -> V_42 . V_22 . V_53 ) {
F_28 ( V_15 -> V_42 . V_22 . V_53 ) ;
V_15 -> V_42 . V_22 . V_53 = NULL ;
}
break;
case V_58 :
if ( V_15 -> V_42 . V_22 . V_59 ) {
F_28 ( V_15 -> V_42 . V_22 . V_59 ) ;
V_15 -> V_42 . V_22 . V_59 = NULL ;
}
break;
case V_61 :
if ( V_15 -> V_42 . V_22 . V_62 ) {
F_28 ( V_15 -> V_42 . V_22 . V_62 ) ;
V_15 -> V_42 . V_22 . V_62 = NULL ;
}
break;
case V_67 :
F_11 ( V_15 ) ;
if ( V_15 -> V_42 . V_22 . V_64 [ V_31 ] ) {
F_28 ( V_15 -> V_42 . V_22 . V_64 [ V_31 ] ) ;
V_15 -> V_42 . V_22 . V_64 [ V_31 ] = NULL ;
}
F_11 ( V_15 ) ;
break;
}
}
static void F_29 ( struct V_14 * V_15 )
{
F_27 ( V_15 , V_58 , 0 ) ;
F_27 ( V_15 , V_61 , 0 ) ;
}
static int F_30 ( struct V_14 * V_15 )
{
int V_23 ;
V_23 = F_24 ( V_15 , V_58 , 0 ) ;
if ( V_23 )
return V_23 ;
return F_24 ( V_15 , V_61 , 0 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_42 . V_22 . V_68 )
return;
V_15 -> V_42 . V_22 . V_68 = false ;
if ( V_15 -> V_18 -> V_69 & V_70 )
return;
F_29 ( V_15 ) ;
}
void F_32 ( struct V_14 * V_15 )
{
if ( V_15 -> V_42 . V_22 . V_68 )
return;
V_15 -> V_42 . V_22 . V_68 = true ;
if ( V_15 -> V_18 -> V_69 & V_70 )
return;
F_30 ( V_15 ) ;
}
int F_33 ( struct V_16 * V_71 , T_3 T_4 V_72 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_34 ( V_71 ) ;
F_35 ( V_31 , V_15 -> V_42 . V_22 . V_73 ) ;
return F_24 ( V_15 , V_67 , V_31 ) ;
}
int F_36 ( struct V_16 * V_71 , T_3 T_4 V_72 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_34 ( V_71 ) ;
F_37 ( V_31 , V_15 -> V_42 . V_22 . V_73 ) ;
F_27 ( V_15 , V_67 , V_31 ) ;
return 0 ;
}
static void F_38 ( struct V_14 * V_15 )
{
int V_24 ;
F_24 ( V_15 , V_52 , 0 ) ;
F_12 (i, priv->fs.vlan.active_vlans, VLAN_N_VID) {
F_24 ( V_15 , V_67 , V_24 ) ;
}
if ( V_15 -> V_42 . V_22 . V_68 &&
! ( V_15 -> V_18 -> V_69 & V_70 ) )
F_30 ( V_15 ) ;
}
static void F_39 ( struct V_14 * V_15 )
{
int V_24 ;
F_27 ( V_15 , V_52 , 0 ) ;
F_12 (i, priv->fs.vlan.active_vlans, VLAN_N_VID) {
F_27 ( V_15 , V_67 , V_24 ) ;
}
if ( V_15 -> V_42 . V_22 . V_68 &&
! ( V_15 -> V_18 -> V_69 & V_70 ) )
F_29 ( V_15 ) ;
}
static void F_40 ( struct V_14 * V_15 ,
struct V_4 * V_5 )
{
switch ( V_5 -> V_9 ) {
case V_12 :
F_41 ( V_15 , & V_5 -> V_8 , V_74 ) ;
V_5 -> V_9 = V_10 ;
break;
case V_75 :
F_42 ( V_15 , & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
break;
}
}
static void F_43 ( struct V_14 * V_15 )
{
struct V_16 * V_18 = V_15 -> V_18 ;
struct V_76 * V_77 ;
F_44 ( V_18 ) ;
F_2 ( V_15 -> V_42 . V_49 . V_78 ,
V_15 -> V_18 -> V_79 ) ;
F_45 (ha, netdev)
F_2 ( V_15 -> V_42 . V_49 . V_78 , V_77 -> V_1 ) ;
F_46 (ha, netdev)
F_2 ( V_15 -> V_42 . V_49 . V_80 , V_77 -> V_1 ) ;
F_47 ( V_18 ) ;
}
static void F_48 ( struct V_14 * V_15 , int V_81 ,
T_1 V_82 [] [ V_83 ] , int V_84 )
{
bool V_85 = ( V_81 == V_86 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_4 * V_5 ;
struct V_2 * V_87 ;
struct V_88 * V_89 ;
int V_24 = 0 ;
int V_90 ;
V_87 = V_85 ? V_15 -> V_42 . V_49 . V_78 : V_15 -> V_42 . V_49 . V_80 ;
if ( V_85 )
F_6 ( V_82 [ V_24 ++ ] , V_17 -> V_79 ) ;
else if ( V_15 -> V_42 . V_49 . V_91 )
F_6 ( V_82 [ V_24 ++ ] , V_17 -> V_92 ) ;
F_49 (hn, tmp, addr_list, hi) {
if ( F_50 ( V_17 -> V_79 , V_5 -> V_8 . V_1 ) )
continue;
if ( V_24 >= V_84 )
break;
F_6 ( V_82 [ V_24 ++ ] , V_5 -> V_8 . V_1 ) ;
}
}
static void F_51 ( struct V_14 * V_15 ,
int V_81 )
{
bool V_85 = ( V_81 == V_86 ) ;
struct V_4 * V_5 ;
T_1 ( * V_82 ) [ V_83 ] = NULL ;
struct V_2 * V_87 ;
struct V_88 * V_89 ;
int V_93 ;
int V_84 ;
int V_23 ;
int V_90 ;
V_84 = V_85 ? 0 : ( V_15 -> V_42 . V_49 . V_91 ? 1 : 0 ) ;
V_93 = V_85 ?
1 << F_13 ( V_15 -> V_25 , V_94 ) :
1 << F_13 ( V_15 -> V_25 , V_95 ) ;
V_87 = V_85 ? V_15 -> V_42 . V_49 . V_78 : V_15 -> V_42 . V_49 . V_80 ;
F_49 (hn, tmp, addr_list, hi)
V_84 ++ ;
if ( V_84 > V_93 ) {
F_14 ( V_15 -> V_18 ,
L_5 ,
V_85 ? L_6 : L_7 , V_84 , V_93 ) ;
V_84 = V_93 ;
}
if ( V_84 ) {
V_82 = F_15 ( V_84 , V_83 , V_27 ) ;
if ( ! V_82 ) {
V_23 = - V_28 ;
goto V_96;
}
F_48 ( V_15 , V_81 , V_82 , V_84 ) ;
}
V_23 = F_52 ( V_15 -> V_25 , V_81 , V_82 , V_84 ) ;
V_96:
if ( V_23 )
F_17 ( V_15 -> V_18 ,
L_8 ,
V_85 ? L_6 : L_7 , V_23 ) ;
F_10 ( V_82 ) ;
}
static void F_53 ( struct V_14 * V_15 )
{
struct V_97 * V_98 = & V_15 -> V_42 . V_49 ;
F_51 ( V_15 , V_86 ) ;
F_51 ( V_15 , V_99 ) ;
F_54 ( V_15 -> V_25 , 0 ,
V_98 -> V_100 ,
V_98 -> V_101 ) ;
}
static void F_55 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_88 * V_89 ;
int V_24 ;
F_49 (hn, tmp, priv->fs.l2.netdev_uc, i)
F_40 ( V_15 , V_5 ) ;
F_49 (hn, tmp, priv->fs.l2.netdev_mc, i)
F_40 ( V_15 , V_5 ) ;
}
static void F_56 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_88 * V_89 ;
int V_24 ;
F_49 (hn, tmp, priv->fs.l2.netdev_uc, i)
V_5 -> V_9 = V_75 ;
F_49 (hn, tmp, priv->fs.l2.netdev_mc, i)
V_5 -> V_9 = V_75 ;
if ( ! F_57 ( V_102 , & V_15 -> V_103 ) )
F_43 ( V_15 ) ;
F_55 ( V_15 ) ;
}
void F_58 ( struct V_104 * V_105 )
{
struct V_14 * V_15 = F_59 ( V_105 , struct V_14 ,
V_106 ) ;
struct V_97 * V_98 = & V_15 -> V_42 . V_49 ;
struct V_16 * V_17 = V_15 -> V_18 ;
bool V_107 = ! F_57 ( V_102 , & V_15 -> V_103 ) ;
bool V_101 = V_107 && ( V_17 -> V_69 & V_70 ) ;
bool V_100 = V_107 && ( V_17 -> V_69 & V_108 ) ;
bool V_91 = V_107 ;
bool V_109 = ! V_98 -> V_101 && V_101 ;
bool V_110 = V_98 -> V_101 && ! V_101 ;
bool V_111 = ! V_98 -> V_100 && V_100 ;
bool V_112 = V_98 -> V_100 && ! V_100 ;
bool V_113 = ! V_98 -> V_91 && V_91 ;
bool V_114 = V_98 -> V_91 && ! V_91 ;
if ( V_109 ) {
F_41 ( V_15 , & V_98 -> V_115 , V_116 ) ;
if ( ! V_15 -> V_42 . V_22 . V_68 )
F_30 ( V_15 ) ;
}
if ( V_111 )
F_41 ( V_15 , & V_98 -> V_117 , V_118 ) ;
if ( V_113 )
F_41 ( V_15 , & V_98 -> V_92 , V_74 ) ;
F_56 ( V_15 ) ;
if ( V_114 )
F_42 ( V_15 , & V_98 -> V_92 ) ;
if ( V_112 )
F_42 ( V_15 , & V_98 -> V_117 ) ;
if ( V_110 ) {
if ( ! V_15 -> V_42 . V_22 . V_68 )
F_29 ( V_15 ) ;
F_42 ( V_15 , & V_98 -> V_115 ) ;
}
V_98 -> V_101 = V_101 ;
V_98 -> V_100 = V_100 ;
V_98 -> V_91 = V_91 ;
F_53 ( V_15 ) ;
}
static void F_60 ( struct V_119 * V_41 )
{
int V_24 ;
for ( V_24 = V_41 -> V_120 - 1 ; V_24 >= 0 ; V_24 -- ) {
if ( ! F_61 ( V_41 -> V_121 [ V_24 ] ) )
F_62 ( V_41 -> V_121 [ V_24 ] ) ;
V_41 -> V_121 [ V_24 ] = NULL ;
}
V_41 -> V_120 = 0 ;
}
void F_63 ( struct V_14 * V_15 )
{
F_6 ( V_15 -> V_42 . V_49 . V_92 . V_1 , V_15 -> V_18 -> V_92 ) ;
}
void F_64 ( struct V_119 * V_41 )
{
F_60 ( V_41 ) ;
F_10 ( V_41 -> V_121 ) ;
F_65 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
}
static void F_66 ( struct V_122 * V_123 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_124 ; V_24 ++ ) {
if ( ! F_61 ( V_123 -> V_125 [ V_24 ] ) ) {
F_28 ( V_123 -> V_125 [ V_24 ] ) ;
V_123 -> V_125 [ V_24 ] = NULL ;
}
}
}
static struct V_46 *
F_67 ( struct V_14 * V_15 ,
struct V_40 * V_41 ,
struct V_44 * V_45 ,
T_2 V_126 ,
T_1 V_72 )
{
struct V_34 V_35 = {
. V_9 = V_36 ,
. V_37 = V_38 ,
. V_39 = 0 ,
} ;
struct V_46 * V_127 ;
struct V_32 * V_33 ;
int V_23 = 0 ;
V_33 = F_25 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_66 ) ;
return F_68 ( - V_28 ) ;
}
if ( V_72 ) {
V_33 -> V_50 = V_51 ;
F_19 ( V_54 , V_33 -> V_55 , V_56 . V_128 ) ;
F_20 ( V_54 , V_33 -> V_60 , V_56 . V_128 , V_72 ) ;
}
if ( V_126 ) {
V_33 -> V_50 = V_51 ;
F_19 ( V_54 , V_33 -> V_55 , V_56 . V_129 ) ;
F_20 ( V_54 , V_33 -> V_60 , V_56 . V_129 , V_126 ) ;
}
V_127 = F_21 ( V_41 , V_33 , & V_35 , V_45 , 1 ) ;
if ( F_22 ( V_127 ) ) {
V_23 = F_23 ( V_127 ) ;
F_17 ( V_15 -> V_18 , L_3 , V_66 ) ;
}
F_26 ( V_33 ) ;
return V_23 ? F_68 ( V_23 ) : V_127 ;
}
static int F_69 ( struct V_14 * V_15 )
{
struct V_44 V_45 ;
struct V_122 * V_123 ;
struct V_46 * * V_125 ;
struct V_40 * V_41 ;
int V_130 ;
int V_23 ;
V_123 = & V_15 -> V_42 . V_123 ;
V_41 = V_123 -> V_41 . V_43 ;
V_125 = V_123 -> V_125 ;
V_45 . type = V_131 ;
for ( V_130 = 0 ; V_130 < V_124 ; V_130 ++ ) {
if ( V_130 == V_132 )
V_45 . V_133 = V_15 -> V_134 [ 0 ] . V_135 ;
else
V_45 . V_133 = V_15 -> V_136 [ V_130 ] . V_135 ;
V_125 [ V_130 ] = F_67 ( V_15 , V_41 , & V_45 ,
V_137 [ V_130 ] . V_126 ,
V_137 [ V_130 ] . V_72 ) ;
if ( F_22 ( V_125 [ V_130 ] ) )
goto V_138;
}
return 0 ;
V_138:
V_23 = F_23 ( V_125 [ V_130 ] ) ;
V_125 [ V_130 ] = NULL ;
F_66 ( V_123 ) ;
return V_23 ;
}
static int F_70 ( struct V_122 * V_123 )
{
int V_139 = F_71 ( V_140 ) ;
struct V_119 * V_41 = & V_123 -> V_41 ;
int V_6 = 0 ;
T_5 * V_141 ;
int V_23 ;
T_1 * V_142 ;
V_41 -> V_121 = F_15 ( V_143 ,
sizeof( * V_41 -> V_121 ) , V_27 ) ;
if ( ! V_41 -> V_121 )
return - V_28 ;
V_141 = F_25 ( V_139 ) ;
if ( ! V_141 ) {
F_10 ( V_41 -> V_121 ) ;
return - V_28 ;
}
V_142 = F_72 ( V_140 , V_141 , V_55 ) ;
F_19 ( V_54 , V_142 , V_56 . V_128 ) ;
F_19 ( V_54 , V_142 , V_56 . V_129 ) ;
F_73 ( V_141 , V_50 , V_51 ) ;
F_73 ( V_141 , V_144 , V_6 ) ;
V_6 += V_145 ;
F_73 ( V_141 , V_146 , V_6 - 1 ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = F_74 ( V_41 -> V_43 , V_141 ) ;
if ( F_22 ( V_41 -> V_121 [ V_41 -> V_120 ] ) )
goto V_23;
V_41 -> V_120 ++ ;
F_20 ( V_54 , V_142 , V_56 . V_128 , 0 ) ;
F_73 ( V_141 , V_144 , V_6 ) ;
V_6 += V_147 ;
F_73 ( V_141 , V_146 , V_6 - 1 ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = F_74 ( V_41 -> V_43 , V_141 ) ;
if ( F_22 ( V_41 -> V_121 [ V_41 -> V_120 ] ) )
goto V_23;
V_41 -> V_120 ++ ;
memset ( V_141 , 0 , V_139 ) ;
F_73 ( V_141 , V_144 , V_6 ) ;
V_6 += V_148 ;
F_73 ( V_141 , V_146 , V_6 - 1 ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = F_74 ( V_41 -> V_43 , V_141 ) ;
if ( F_22 ( V_41 -> V_121 [ V_41 -> V_120 ] ) )
goto V_23;
V_41 -> V_120 ++ ;
F_26 ( V_141 ) ;
return 0 ;
V_23:
V_23 = F_23 ( V_41 -> V_121 [ V_41 -> V_120 ] ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = NULL ;
F_26 ( V_141 ) ;
return V_23 ;
}
static void F_75 ( struct V_14 * V_15 )
{
struct V_122 * V_123 = & V_15 -> V_42 . V_123 ;
F_66 ( V_123 ) ;
F_64 ( & V_123 -> V_41 ) ;
}
static int F_76 ( struct V_14 * V_15 )
{
struct V_122 * V_123 = & V_15 -> V_42 . V_123 ;
struct V_119 * V_41 = & V_123 -> V_41 ;
int V_23 ;
V_41 -> V_43 = F_77 ( V_15 -> V_42 . V_149 , V_150 ,
V_151 , V_152 , 0 ) ;
if ( F_22 ( V_41 -> V_43 ) ) {
V_23 = F_23 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
V_23 = F_70 ( V_123 ) ;
if ( V_23 )
goto V_23;
V_23 = F_69 ( V_15 ) ;
if ( V_23 )
goto V_23;
return 0 ;
V_23:
F_64 ( V_41 ) ;
return V_23 ;
}
static void F_42 ( struct V_14 * V_15 ,
struct V_153 * V_8 )
{
if ( ! F_61 ( V_8 -> V_127 ) ) {
F_28 ( V_8 -> V_127 ) ;
V_8 -> V_127 = NULL ;
}
}
static int F_41 ( struct V_14 * V_15 ,
struct V_153 * V_8 , int type )
{
struct V_34 V_35 = {
. V_9 = V_36 ,
. V_37 = V_38 ,
. V_39 = 0 ,
} ;
struct V_40 * V_41 = V_15 -> V_42 . V_49 . V_41 . V_43 ;
struct V_44 V_45 ;
struct V_32 * V_33 ;
int V_23 = 0 ;
T_1 * V_154 ;
T_1 * V_155 ;
V_33 = F_25 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_66 ) ;
return - V_28 ;
}
V_154 = F_72 ( V_54 , V_33 -> V_55 ,
V_56 . V_156 ) ;
V_155 = F_72 ( V_54 , V_33 -> V_60 ,
V_56 . V_156 ) ;
V_45 . type = V_48 ;
V_45 . V_41 = V_15 -> V_42 . V_123 . V_41 . V_43 ;
switch ( type ) {
case V_74 :
V_33 -> V_50 = V_51 ;
F_78 ( V_154 ) ;
F_6 ( V_155 , V_8 -> V_1 ) ;
break;
case V_118 :
V_33 -> V_50 = V_51 ;
V_154 [ 0 ] = 0x01 ;
V_155 [ 0 ] = 0x01 ;
break;
case V_116 :
break;
}
V_8 -> V_127 = F_21 ( V_41 , V_33 , & V_35 , & V_45 , 1 ) ;
if ( F_22 ( V_8 -> V_127 ) ) {
F_17 ( V_15 -> V_18 , L_9 ,
V_66 , V_155 ) ;
V_23 = F_23 ( V_8 -> V_127 ) ;
V_8 -> V_127 = NULL ;
}
F_26 ( V_33 ) ;
return V_23 ;
}
static int F_79 ( struct V_97 * V_157 )
{
int V_139 = F_71 ( V_140 ) ;
struct V_119 * V_41 = & V_157 -> V_41 ;
int V_6 = 0 ;
T_1 * V_154 ;
T_5 * V_141 ;
int V_23 ;
T_1 * V_142 ;
V_41 -> V_121 = F_15 ( V_158 , sizeof( * V_41 -> V_121 ) , V_27 ) ;
if ( ! V_41 -> V_121 )
return - V_28 ;
V_141 = F_25 ( V_139 ) ;
if ( ! V_141 ) {
F_10 ( V_41 -> V_121 ) ;
return - V_28 ;
}
V_142 = F_72 ( V_140 , V_141 , V_55 ) ;
V_154 = F_72 ( V_54 , V_142 ,
V_56 . V_156 ) ;
F_73 ( V_141 , V_144 , V_6 ) ;
V_6 += V_159 ;
F_73 ( V_141 , V_146 , V_6 - 1 ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = F_74 ( V_41 -> V_43 , V_141 ) ;
if ( F_22 ( V_41 -> V_121 [ V_41 -> V_120 ] ) )
goto V_160;
V_41 -> V_120 ++ ;
F_78 ( V_154 ) ;
F_73 ( V_141 , V_50 , V_51 ) ;
F_73 ( V_141 , V_144 , V_6 ) ;
V_6 += V_161 ;
F_73 ( V_141 , V_146 , V_6 - 1 ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = F_74 ( V_41 -> V_43 , V_141 ) ;
if ( F_22 ( V_41 -> V_121 [ V_41 -> V_120 ] ) )
goto V_160;
V_41 -> V_120 ++ ;
F_80 ( V_154 ) ;
V_154 [ 0 ] = 0x01 ;
F_73 ( V_141 , V_144 , V_6 ) ;
V_6 += V_162 ;
F_73 ( V_141 , V_146 , V_6 - 1 ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = F_74 ( V_41 -> V_43 , V_141 ) ;
if ( F_22 ( V_41 -> V_121 [ V_41 -> V_120 ] ) )
goto V_160;
V_41 -> V_120 ++ ;
F_26 ( V_141 ) ;
return 0 ;
V_160:
V_23 = F_23 ( V_41 -> V_121 [ V_41 -> V_120 ] ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = NULL ;
F_60 ( V_41 ) ;
F_26 ( V_141 ) ;
return V_23 ;
}
static void F_81 ( struct V_14 * V_15 )
{
F_64 ( & V_15 -> V_42 . V_49 . V_41 ) ;
}
static int F_82 ( struct V_14 * V_15 )
{
struct V_97 * V_157 = & V_15 -> V_42 . V_49 ;
struct V_119 * V_41 = & V_157 -> V_41 ;
int V_23 ;
V_41 -> V_120 = 0 ;
V_41 -> V_43 = F_77 ( V_15 -> V_42 . V_149 , V_150 ,
V_163 , V_164 , 0 ) ;
if ( F_22 ( V_41 -> V_43 ) ) {
V_23 = F_23 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
V_23 = F_79 ( V_157 ) ;
if ( V_23 )
goto V_165;
return 0 ;
V_165:
F_65 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
static int F_83 ( struct V_119 * V_41 , T_5 * V_141 ,
int V_139 )
{
int V_23 ;
int V_6 = 0 ;
T_1 * V_142 = F_72 ( V_140 , V_141 , V_55 ) ;
memset ( V_141 , 0 , V_139 ) ;
F_73 ( V_141 , V_50 , V_51 ) ;
F_19 ( V_54 , V_142 , V_56 . V_57 ) ;
F_19 ( V_54 , V_142 , V_56 . V_65 ) ;
F_73 ( V_141 , V_144 , V_6 ) ;
V_6 += V_166 ;
F_73 ( V_141 , V_146 , V_6 - 1 ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = F_74 ( V_41 -> V_43 , V_141 ) ;
if ( F_22 ( V_41 -> V_121 [ V_41 -> V_120 ] ) )
goto V_160;
V_41 -> V_120 ++ ;
memset ( V_141 , 0 , V_139 ) ;
F_73 ( V_141 , V_50 , V_51 ) ;
F_19 ( V_54 , V_142 , V_56 . V_57 ) ;
F_73 ( V_141 , V_144 , V_6 ) ;
V_6 += V_167 ;
F_73 ( V_141 , V_146 , V_6 - 1 ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = F_74 ( V_41 -> V_43 , V_141 ) ;
if ( F_22 ( V_41 -> V_121 [ V_41 -> V_120 ] ) )
goto V_160;
V_41 -> V_120 ++ ;
memset ( V_141 , 0 , V_139 ) ;
F_73 ( V_141 , V_50 , V_51 ) ;
F_19 ( V_54 , V_142 , V_56 . V_63 ) ;
F_73 ( V_141 , V_144 , V_6 ) ;
V_6 += V_168 ;
F_73 ( V_141 , V_146 , V_6 - 1 ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = F_74 ( V_41 -> V_43 , V_141 ) ;
if ( F_22 ( V_41 -> V_121 [ V_41 -> V_120 ] ) )
goto V_160;
V_41 -> V_120 ++ ;
return 0 ;
V_160:
V_23 = F_23 ( V_41 -> V_121 [ V_41 -> V_120 ] ) ;
V_41 -> V_121 [ V_41 -> V_120 ] = NULL ;
F_60 ( V_41 ) ;
return V_23 ;
}
static int F_84 ( struct V_119 * V_41 )
{
T_5 * V_141 ;
int V_139 = F_71 ( V_140 ) ;
int V_23 ;
V_141 = F_25 ( V_139 ) ;
if ( ! V_141 )
return - V_28 ;
V_23 = F_83 ( V_41 , V_141 , V_139 ) ;
F_26 ( V_141 ) ;
return V_23 ;
}
static int F_85 ( struct V_14 * V_15 )
{
struct V_119 * V_41 = & V_15 -> V_42 . V_22 . V_41 ;
int V_23 ;
V_41 -> V_120 = 0 ;
V_41 -> V_43 = F_77 ( V_15 -> V_42 . V_149 , V_150 ,
V_169 , V_170 , 0 ) ;
if ( F_22 ( V_41 -> V_43 ) ) {
V_23 = F_23 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
V_41 -> V_121 = F_15 ( V_171 , sizeof( * V_41 -> V_121 ) , V_27 ) ;
if ( ! V_41 -> V_121 ) {
V_23 = - V_28 ;
goto V_172;
}
V_23 = F_84 ( V_41 ) ;
if ( V_23 )
goto V_173;
F_38 ( V_15 ) ;
return 0 ;
V_173:
F_10 ( V_41 -> V_121 ) ;
V_172:
F_65 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
static void F_86 ( struct V_14 * V_15 )
{
F_39 ( V_15 ) ;
F_64 ( & V_15 -> V_42 . V_22 . V_41 ) ;
}
int F_87 ( struct V_14 * V_15 )
{
int V_23 ;
V_15 -> V_42 . V_149 = F_88 ( V_15 -> V_25 ,
V_174 ) ;
if ( ! V_15 -> V_42 . V_149 )
return - V_175 ;
V_23 = F_89 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_10 ,
V_23 ) ;
V_15 -> V_18 -> V_176 &= ~ V_177 ;
}
V_23 = F_76 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_11 ,
V_23 ) ;
goto V_178;
}
V_23 = F_82 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_12 ,
V_23 ) ;
goto V_179;
}
V_23 = F_85 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_13 ,
V_23 ) ;
goto V_180;
}
F_90 ( V_15 ) ;
return 0 ;
V_180:
F_81 ( V_15 ) ;
V_179:
F_75 ( V_15 ) ;
V_178:
F_91 ( V_15 ) ;
return V_23 ;
}
void F_92 ( struct V_14 * V_15 )
{
F_86 ( V_15 ) ;
F_81 ( V_15 ) ;
F_75 ( V_15 ) ;
F_91 ( V_15 ) ;
F_93 ( V_15 ) ;
}
