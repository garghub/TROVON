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
struct V_34 * V_35 = V_15 -> V_36 . V_22 . V_35 . V_37 ;
struct V_38 V_39 ;
struct V_40 * * V_41 ;
F_19 ( V_42 ) ;
int V_23 = 0 ;
V_39 . type = V_43 ;
V_39 . V_35 = V_15 -> V_36 . V_44 . V_35 . V_37 ;
V_33 -> V_45 = V_46 ;
switch ( V_30 ) {
case V_47 :
V_41 = & V_15 -> V_36 . V_22 . V_48 ;
F_20 ( V_49 , V_33 -> V_50 ,
V_51 . V_52 ) ;
break;
case V_53 :
V_41 = & V_15 -> V_36 . V_22 . V_54 ;
F_20 ( V_49 , V_33 -> V_50 ,
V_51 . V_52 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_51 . V_52 , 1 ) ;
break;
case V_56 :
V_41 = & V_15 -> V_36 . V_22 . V_57 ;
F_20 ( V_49 , V_33 -> V_50 ,
V_51 . V_58 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_51 . V_58 , 1 ) ;
break;
default:
V_41 = & V_15 -> V_36 . V_22 . V_59 [ V_31 ] ;
F_20 ( V_49 , V_33 -> V_50 ,
V_51 . V_52 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_51 . V_52 , 1 ) ;
F_20 ( V_49 , V_33 -> V_50 ,
V_51 . V_60 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_51 . V_60 ,
V_31 ) ;
break;
}
* V_41 = F_22 ( V_35 , V_33 , & V_42 , & V_39 , 1 ) ;
if ( F_23 ( * V_41 ) ) {
V_23 = F_24 ( * V_41 ) ;
* V_41 = NULL ;
F_17 ( V_15 -> V_18 , L_3 , V_61 ) ;
}
return V_23 ;
}
static int F_25 ( struct V_14 * V_15 ,
enum V_29 V_30 , T_2 V_31 )
{
struct V_32 * V_33 ;
int V_23 = 0 ;
V_33 = F_26 ( sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return - V_28 ;
if ( V_30 == V_62 )
F_11 ( V_15 ) ;
V_23 = F_18 ( V_15 , V_30 , V_31 , V_33 ) ;
F_27 ( V_33 ) ;
return V_23 ;
}
static void F_28 ( struct V_14 * V_15 ,
enum V_29 V_30 , T_2 V_31 )
{
switch ( V_30 ) {
case V_47 :
if ( V_15 -> V_36 . V_22 . V_48 ) {
F_29 ( V_15 -> V_36 . V_22 . V_48 ) ;
V_15 -> V_36 . V_22 . V_48 = NULL ;
}
break;
case V_53 :
if ( V_15 -> V_36 . V_22 . V_54 ) {
F_29 ( V_15 -> V_36 . V_22 . V_54 ) ;
V_15 -> V_36 . V_22 . V_54 = NULL ;
}
break;
case V_56 :
if ( V_15 -> V_36 . V_22 . V_57 ) {
F_29 ( V_15 -> V_36 . V_22 . V_57 ) ;
V_15 -> V_36 . V_22 . V_57 = NULL ;
}
break;
case V_62 :
F_11 ( V_15 ) ;
if ( V_15 -> V_36 . V_22 . V_59 [ V_31 ] ) {
F_29 ( V_15 -> V_36 . V_22 . V_59 [ V_31 ] ) ;
V_15 -> V_36 . V_22 . V_59 [ V_31 ] = NULL ;
}
F_11 ( V_15 ) ;
break;
}
}
static void F_30 ( struct V_14 * V_15 )
{
F_28 ( V_15 , V_53 , 0 ) ;
F_28 ( V_15 , V_56 , 0 ) ;
}
static int F_31 ( struct V_14 * V_15 )
{
int V_23 ;
V_23 = F_25 ( V_15 , V_53 , 0 ) ;
if ( V_23 )
return V_23 ;
return F_25 ( V_15 , V_56 , 0 ) ;
}
void F_32 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_36 . V_22 . V_63 )
return;
V_15 -> V_36 . V_22 . V_63 = false ;
if ( V_15 -> V_18 -> V_64 & V_65 )
return;
F_28 ( V_15 , V_53 , 0 ) ;
}
void F_33 ( struct V_14 * V_15 )
{
if ( V_15 -> V_36 . V_22 . V_63 )
return;
V_15 -> V_36 . V_22 . V_63 = true ;
if ( V_15 -> V_18 -> V_64 & V_65 )
return;
F_25 ( V_15 , V_53 , 0 ) ;
}
int F_34 ( struct V_16 * V_66 , T_3 T_4 V_67 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_35 ( V_66 ) ;
F_36 ( V_31 , V_15 -> V_36 . V_22 . V_68 ) ;
return F_25 ( V_15 , V_62 , V_31 ) ;
}
int F_37 ( struct V_16 * V_66 , T_3 T_4 V_67 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_35 ( V_66 ) ;
F_38 ( V_31 , V_15 -> V_36 . V_22 . V_68 ) ;
F_28 ( V_15 , V_62 , V_31 ) ;
return 0 ;
}
static void F_39 ( struct V_14 * V_15 )
{
int V_24 ;
F_25 ( V_15 , V_47 , 0 ) ;
F_12 (i, priv->fs.vlan.active_vlans, VLAN_N_VID) {
F_25 ( V_15 , V_62 , V_24 ) ;
}
if ( V_15 -> V_36 . V_22 . V_63 &&
! ( V_15 -> V_18 -> V_64 & V_65 ) )
F_31 ( V_15 ) ;
}
static void F_40 ( struct V_14 * V_15 )
{
int V_24 ;
F_28 ( V_15 , V_47 , 0 ) ;
F_12 (i, priv->fs.vlan.active_vlans, VLAN_N_VID) {
F_28 ( V_15 , V_62 , V_24 ) ;
}
if ( V_15 -> V_36 . V_22 . V_63 &&
! ( V_15 -> V_18 -> V_64 & V_65 ) )
F_30 ( V_15 ) ;
}
static void F_41 ( struct V_14 * V_15 ,
struct V_4 * V_5 )
{
T_1 V_9 = V_5 -> V_9 ;
T_1 V_69 [ V_70 ] ;
int V_71 = 0 ;
F_6 ( V_69 , V_5 -> V_8 . V_1 ) ;
switch ( V_9 ) {
case V_12 :
F_42 ( V_15 , & V_5 -> V_8 , V_72 ) ;
if ( ! F_43 ( V_69 ) ) {
V_71 = F_44 ( V_15 -> V_25 , V_69 ) ;
V_5 -> V_73 = ! V_71 ;
}
V_5 -> V_9 = V_10 ;
break;
case V_74 :
if ( ! F_43 ( V_69 ) && V_5 -> V_73 )
V_71 = F_45 ( V_15 -> V_25 , V_69 ) ;
F_46 ( V_15 , & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
break;
}
if ( V_71 )
F_14 ( V_15 -> V_18 , L_4 ,
V_9 == V_12 ? L_5 : L_6 , V_69 , V_71 ) ;
}
static void F_47 ( struct V_14 * V_15 )
{
struct V_16 * V_18 = V_15 -> V_18 ;
struct V_75 * V_76 ;
F_48 ( V_18 ) ;
F_2 ( V_15 -> V_36 . V_44 . V_77 ,
V_15 -> V_18 -> V_78 ) ;
F_49 (ha, netdev)
F_2 ( V_15 -> V_36 . V_44 . V_77 , V_76 -> V_1 ) ;
F_50 (ha, netdev)
F_2 ( V_15 -> V_36 . V_44 . V_79 , V_76 -> V_1 ) ;
F_51 ( V_18 ) ;
}
static void F_52 ( struct V_14 * V_15 , int V_80 ,
T_1 V_81 [] [ V_70 ] , int V_82 )
{
bool V_83 = ( V_80 == V_84 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_4 * V_5 ;
struct V_2 * V_85 ;
struct V_86 * V_87 ;
int V_24 = 0 ;
int V_88 ;
V_85 = V_83 ? V_15 -> V_36 . V_44 . V_77 : V_15 -> V_36 . V_44 . V_79 ;
if ( V_83 )
F_6 ( V_81 [ V_24 ++ ] , V_17 -> V_78 ) ;
else if ( V_15 -> V_36 . V_44 . V_89 )
F_6 ( V_81 [ V_24 ++ ] , V_17 -> V_90 ) ;
F_53 (hn, tmp, addr_list, hi) {
if ( F_54 ( V_17 -> V_78 , V_5 -> V_8 . V_1 ) )
continue;
if ( V_24 >= V_82 )
break;
F_6 ( V_81 [ V_24 ++ ] , V_5 -> V_8 . V_1 ) ;
}
}
static void F_55 ( struct V_14 * V_15 ,
int V_80 )
{
bool V_83 = ( V_80 == V_84 ) ;
struct V_4 * V_5 ;
T_1 ( * V_81 ) [ V_70 ] = NULL ;
struct V_2 * V_85 ;
struct V_86 * V_87 ;
int V_91 ;
int V_82 ;
int V_23 ;
int V_88 ;
V_82 = V_83 ? 0 : ( V_15 -> V_36 . V_44 . V_89 ? 1 : 0 ) ;
V_91 = V_83 ?
1 << F_13 ( V_15 -> V_25 , V_92 ) :
1 << F_13 ( V_15 -> V_25 , V_93 ) ;
V_85 = V_83 ? V_15 -> V_36 . V_44 . V_77 : V_15 -> V_36 . V_44 . V_79 ;
F_53 (hn, tmp, addr_list, hi)
V_82 ++ ;
if ( V_82 > V_91 ) {
F_14 ( V_15 -> V_18 ,
L_7 ,
V_83 ? L_8 : L_9 , V_82 , V_91 ) ;
V_82 = V_91 ;
}
if ( V_82 ) {
V_81 = F_15 ( V_82 , V_70 , V_27 ) ;
if ( ! V_81 ) {
V_23 = - V_28 ;
goto V_94;
}
F_52 ( V_15 , V_80 , V_81 , V_82 ) ;
}
V_23 = F_56 ( V_15 -> V_25 , V_80 , V_81 , V_82 ) ;
V_94:
if ( V_23 )
F_17 ( V_15 -> V_18 ,
L_10 ,
V_83 ? L_8 : L_9 , V_23 ) ;
F_10 ( V_81 ) ;
}
static void F_57 ( struct V_14 * V_15 )
{
struct V_95 * V_96 = & V_15 -> V_36 . V_44 ;
F_55 ( V_15 , V_84 ) ;
F_55 ( V_15 , V_97 ) ;
F_58 ( V_15 -> V_25 , 0 ,
V_96 -> V_98 ,
V_96 -> V_99 ) ;
}
static void F_59 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_86 * V_87 ;
int V_24 ;
F_53 (hn, tmp, priv->fs.l2.netdev_uc, i)
F_41 ( V_15 , V_5 ) ;
F_53 (hn, tmp, priv->fs.l2.netdev_mc, i)
F_41 ( V_15 , V_5 ) ;
}
static void F_60 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_86 * V_87 ;
int V_24 ;
F_53 (hn, tmp, priv->fs.l2.netdev_uc, i)
V_5 -> V_9 = V_74 ;
F_53 (hn, tmp, priv->fs.l2.netdev_mc, i)
V_5 -> V_9 = V_74 ;
if ( ! F_61 ( V_100 , & V_15 -> V_101 ) )
F_47 ( V_15 ) ;
F_59 ( V_15 ) ;
}
void F_62 ( struct V_102 * V_103 )
{
struct V_14 * V_15 = F_63 ( V_103 , struct V_14 ,
V_104 ) ;
struct V_95 * V_96 = & V_15 -> V_36 . V_44 ;
struct V_16 * V_17 = V_15 -> V_18 ;
bool V_105 = ! F_61 ( V_100 , & V_15 -> V_101 ) ;
bool V_99 = V_105 && ( V_17 -> V_64 & V_65 ) ;
bool V_98 = V_105 && ( V_17 -> V_64 & V_106 ) ;
bool V_89 = V_105 ;
bool V_107 = ! V_96 -> V_99 && V_99 ;
bool V_108 = V_96 -> V_99 && ! V_99 ;
bool V_109 = ! V_96 -> V_98 && V_98 ;
bool V_110 = V_96 -> V_98 && ! V_98 ;
bool V_111 = ! V_96 -> V_89 && V_89 ;
bool V_112 = V_96 -> V_89 && ! V_89 ;
if ( V_107 ) {
F_42 ( V_15 , & V_96 -> V_113 , V_114 ) ;
if ( ! V_15 -> V_36 . V_22 . V_63 )
F_31 ( V_15 ) ;
}
if ( V_109 )
F_42 ( V_15 , & V_96 -> V_115 , V_116 ) ;
if ( V_111 )
F_42 ( V_15 , & V_96 -> V_90 , V_72 ) ;
F_60 ( V_15 ) ;
if ( V_112 )
F_46 ( V_15 , & V_96 -> V_90 ) ;
if ( V_110 )
F_46 ( V_15 , & V_96 -> V_115 ) ;
if ( V_108 ) {
if ( ! V_15 -> V_36 . V_22 . V_63 )
F_30 ( V_15 ) ;
F_46 ( V_15 , & V_96 -> V_113 ) ;
}
V_96 -> V_99 = V_99 ;
V_96 -> V_98 = V_98 ;
V_96 -> V_89 = V_89 ;
F_57 ( V_15 ) ;
}
static void F_64 ( struct V_117 * V_35 )
{
int V_24 ;
for ( V_24 = V_35 -> V_118 - 1 ; V_24 >= 0 ; V_24 -- ) {
if ( ! F_65 ( V_35 -> V_119 [ V_24 ] ) )
F_66 ( V_35 -> V_119 [ V_24 ] ) ;
V_35 -> V_119 [ V_24 ] = NULL ;
}
V_35 -> V_118 = 0 ;
}
void F_67 ( struct V_14 * V_15 )
{
F_6 ( V_15 -> V_36 . V_44 . V_90 . V_1 , V_15 -> V_18 -> V_90 ) ;
}
void F_68 ( struct V_117 * V_35 )
{
F_64 ( V_35 ) ;
F_10 ( V_35 -> V_119 ) ;
F_69 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
}
static void F_70 ( struct V_120 * V_121 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_122 ; V_24 ++ ) {
if ( ! F_65 ( V_121 -> V_123 [ V_24 ] ) ) {
F_29 ( V_121 -> V_123 [ V_24 ] ) ;
V_121 -> V_123 [ V_24 ] = NULL ;
}
}
for ( V_24 = 0 ; V_24 < V_124 ; V_24 ++ ) {
if ( ! F_65 ( V_121 -> V_125 [ V_24 ] ) ) {
F_29 ( V_121 -> V_125 [ V_24 ] ) ;
V_121 -> V_125 [ V_24 ] = NULL ;
}
}
}
static T_1 F_71 ( T_2 V_126 )
{
if ( V_126 == V_127 )
return 4 ;
if ( V_126 == V_128 )
return 6 ;
return 0 ;
}
static struct V_40 *
F_72 ( struct V_14 * V_15 ,
struct V_34 * V_35 ,
struct V_38 * V_39 ,
T_2 V_129 ,
T_1 V_67 )
{
int V_130 = F_73 ( V_15 -> V_25 , V_131 . V_132 ) ;
F_19 ( V_42 ) ;
struct V_40 * V_133 ;
struct V_32 * V_33 ;
int V_23 = 0 ;
T_1 V_134 ;
V_33 = F_26 ( sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return F_74 ( - V_28 ) ;
if ( V_67 ) {
V_33 -> V_45 = V_46 ;
F_20 ( V_49 , V_33 -> V_50 , V_51 . V_135 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_51 . V_135 , V_67 ) ;
}
V_134 = F_71 ( V_129 ) ;
if ( V_130 && V_134 ) {
V_33 -> V_45 = V_46 ;
F_20 ( V_49 , V_33 -> V_50 , V_51 . V_136 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_51 . V_136 , V_134 ) ;
} else if ( V_129 ) {
V_33 -> V_45 = V_46 ;
F_20 ( V_49 , V_33 -> V_50 , V_51 . V_126 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_51 . V_126 , V_129 ) ;
}
V_133 = F_22 ( V_35 , V_33 , & V_42 , V_39 , 1 ) ;
if ( F_23 ( V_133 ) ) {
V_23 = F_24 ( V_133 ) ;
F_17 ( V_15 -> V_18 , L_3 , V_61 ) ;
}
F_27 ( V_33 ) ;
return V_23 ? F_74 ( V_23 ) : V_133 ;
}
static int F_75 ( struct V_14 * V_15 )
{
struct V_38 V_39 ;
struct V_120 * V_121 ;
struct V_40 * * V_123 ;
struct V_34 * V_35 ;
int V_137 ;
int V_23 ;
V_121 = & V_15 -> V_36 . V_121 ;
V_35 = V_121 -> V_35 . V_37 ;
V_123 = V_121 -> V_123 ;
V_39 . type = V_138 ;
for ( V_137 = 0 ; V_137 < V_122 ; V_137 ++ ) {
if ( V_137 == V_139 )
V_39 . V_140 = V_15 -> V_141 [ 0 ] . V_142 ;
else
V_39 . V_140 = V_15 -> V_143 [ V_137 ] . V_142 ;
V_123 [ V_137 ] = F_72 ( V_15 , V_35 , & V_39 ,
V_144 [ V_137 ] . V_129 ,
V_144 [ V_137 ] . V_67 ) ;
if ( F_23 ( V_123 [ V_137 ] ) )
goto V_145;
}
if ( ! F_76 ( V_15 -> V_25 ) )
return 0 ;
V_123 = V_121 -> V_125 ;
V_39 . type = V_43 ;
V_39 . V_35 = V_15 -> V_36 . V_146 . V_35 . V_37 ;
for ( V_137 = 0 ; V_137 < V_124 ; V_137 ++ ) {
V_123 [ V_137 ] = F_72 ( V_15 , V_35 , & V_39 ,
V_147 [ V_137 ] . V_129 ,
V_147 [ V_137 ] . V_67 ) ;
if ( F_23 ( V_123 [ V_137 ] ) )
goto V_145;
}
return 0 ;
V_145:
V_23 = F_24 ( V_123 [ V_137 ] ) ;
V_123 [ V_137 ] = NULL ;
F_70 ( V_121 ) ;
return V_23 ;
}
static int F_77 ( struct V_120 * V_121 ,
bool V_148 )
{
int V_149 = F_78 ( V_150 ) ;
struct V_117 * V_35 = & V_121 -> V_35 ;
int V_6 = 0 ;
T_5 * V_151 ;
int V_23 ;
T_1 * V_152 ;
V_35 -> V_119 = F_15 ( V_153 ,
sizeof( * V_35 -> V_119 ) , V_27 ) ;
if ( ! V_35 -> V_119 )
return - V_28 ;
V_151 = F_26 ( V_149 , V_27 ) ;
if ( ! V_151 ) {
F_10 ( V_35 -> V_119 ) ;
return - V_28 ;
}
V_152 = F_79 ( V_150 , V_151 , V_50 ) ;
F_20 ( V_49 , V_152 , V_51 . V_135 ) ;
if ( V_148 )
F_20 ( V_49 , V_152 , V_51 . V_136 ) ;
else
F_20 ( V_49 , V_152 , V_51 . V_126 ) ;
F_80 ( V_151 , V_45 , V_46 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_155 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_23;
V_35 -> V_118 ++ ;
F_21 ( V_49 , V_152 , V_51 . V_135 , 0 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_157 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_23;
V_35 -> V_118 ++ ;
memset ( V_151 , 0 , V_149 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_158 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_23;
V_35 -> V_118 ++ ;
F_27 ( V_151 ) ;
return 0 ;
V_23:
V_23 = F_24 ( V_35 -> V_119 [ V_35 -> V_118 ] ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = NULL ;
F_27 ( V_151 ) ;
return V_23 ;
}
static struct V_40 *
F_82 ( struct V_14 * V_15 ,
struct V_34 * V_35 ,
struct V_38 * V_39 ,
T_2 V_129 , T_1 V_67 )
{
F_19 ( V_42 ) ;
struct V_40 * V_133 ;
struct V_32 * V_33 ;
int V_23 = 0 ;
T_1 V_134 ;
V_33 = F_26 ( sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return F_74 ( - V_28 ) ;
V_134 = F_71 ( V_129 ) ;
if ( V_129 && V_134 ) {
V_33 -> V_45 = V_159 ;
F_20 ( V_49 , V_33 -> V_50 , V_160 . V_136 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_160 . V_136 , V_134 ) ;
}
if ( V_67 ) {
V_33 -> V_45 = V_159 ;
F_20 ( V_49 , V_33 -> V_50 , V_160 . V_135 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_160 . V_135 , V_67 ) ;
}
V_133 = F_22 ( V_35 , V_33 , & V_42 , V_39 , 1 ) ;
if ( F_23 ( V_133 ) ) {
V_23 = F_24 ( V_133 ) ;
F_17 ( V_15 -> V_18 , L_3 , V_61 ) ;
}
F_27 ( V_33 ) ;
return V_23 ? F_74 ( V_23 ) : V_133 ;
}
static int F_83 ( struct V_14 * V_15 )
{
struct V_38 V_39 ;
struct V_40 * * V_123 ;
struct V_120 * V_121 ;
struct V_34 * V_35 ;
int V_23 ;
int V_137 ;
V_121 = & V_15 -> V_36 . V_146 ;
V_35 = V_121 -> V_35 . V_37 ;
V_123 = V_121 -> V_123 ;
V_39 . type = V_138 ;
for ( V_137 = 0 ; V_137 < V_122 ; V_137 ++ ) {
if ( V_137 == V_139 )
V_39 . V_140 = V_15 -> V_141 [ 0 ] . V_142 ;
else
V_39 . V_140 = V_15 -> V_161 [ V_137 ] . V_142 ;
V_123 [ V_137 ] = F_82 ( V_15 , V_35 , & V_39 ,
V_144 [ V_137 ] . V_129 ,
V_144 [ V_137 ] . V_67 ) ;
if ( F_23 ( V_123 [ V_137 ] ) )
goto V_145;
}
return 0 ;
V_145:
V_23 = F_24 ( V_123 [ V_137 ] ) ;
V_123 [ V_137 ] = NULL ;
F_70 ( V_121 ) ;
return V_23 ;
}
static int F_84 ( struct V_120 * V_121 )
{
int V_149 = F_78 ( V_150 ) ;
struct V_117 * V_35 = & V_121 -> V_35 ;
int V_6 = 0 ;
T_5 * V_151 ;
int V_23 ;
T_1 * V_152 ;
V_35 -> V_119 = F_15 ( V_162 , sizeof( * V_35 -> V_119 ) , V_27 ) ;
if ( ! V_35 -> V_119 )
return - V_28 ;
V_151 = F_26 ( V_149 , V_27 ) ;
if ( ! V_151 ) {
F_10 ( V_35 -> V_119 ) ;
return - V_28 ;
}
V_152 = F_79 ( V_150 , V_151 , V_50 ) ;
F_20 ( V_49 , V_152 , V_160 . V_135 ) ;
F_20 ( V_49 , V_152 , V_160 . V_136 ) ;
F_80 ( V_151 , V_45 , V_159 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_163 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_23;
V_35 -> V_118 ++ ;
F_21 ( V_49 , V_152 , V_160 . V_135 , 0 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_164 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_23;
V_35 -> V_118 ++ ;
memset ( V_151 , 0 , V_149 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_165 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_23;
V_35 -> V_118 ++ ;
F_27 ( V_151 ) ;
return 0 ;
V_23:
V_23 = F_24 ( V_35 -> V_119 [ V_35 -> V_118 ] ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = NULL ;
F_27 ( V_151 ) ;
return V_23 ;
}
static int F_85 ( struct V_14 * V_15 )
{
struct V_120 * V_121 = & V_15 -> V_36 . V_146 ;
struct V_166 V_167 = {} ;
struct V_117 * V_35 = & V_121 -> V_35 ;
int V_23 ;
if ( ! F_76 ( V_15 -> V_25 ) )
return 0 ;
V_167 . V_168 = V_169 ;
V_167 . V_170 = V_171 ;
V_167 . V_172 = V_173 ;
V_35 -> V_37 = F_86 ( V_15 -> V_36 . V_174 , & V_167 ) ;
if ( F_23 ( V_35 -> V_37 ) ) {
V_23 = F_24 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_23 = F_84 ( V_121 ) ;
if ( V_23 )
goto V_23;
V_23 = F_83 ( V_15 ) ;
if ( V_23 )
goto V_23;
return 0 ;
V_23:
F_68 ( V_35 ) ;
return V_23 ;
}
static void F_87 ( struct V_14 * V_15 )
{
struct V_120 * V_121 = & V_15 -> V_36 . V_146 ;
if ( ! F_76 ( V_15 -> V_25 ) )
return;
F_70 ( V_121 ) ;
F_68 ( & V_121 -> V_35 ) ;
}
void F_88 ( struct V_14 * V_15 )
{
struct V_120 * V_121 = & V_15 -> V_36 . V_121 ;
F_70 ( V_121 ) ;
F_68 ( & V_121 -> V_35 ) ;
}
int F_89 ( struct V_14 * V_15 )
{
bool V_130 = F_73 ( V_15 -> V_25 , V_131 . V_132 ) ;
struct V_120 * V_121 = & V_15 -> V_36 . V_121 ;
struct V_166 V_167 = {} ;
struct V_117 * V_35 = & V_121 -> V_35 ;
int V_23 ;
V_167 . V_168 = V_175 ;
V_167 . V_170 = V_176 ;
V_167 . V_172 = V_173 ;
V_35 -> V_37 = F_86 ( V_15 -> V_36 . V_174 , & V_167 ) ;
if ( F_23 ( V_35 -> V_37 ) ) {
V_23 = F_24 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_23 = F_77 ( V_121 , V_130 ) ;
if ( V_23 )
goto V_23;
V_23 = F_75 ( V_15 ) ;
if ( V_23 )
goto V_23;
return 0 ;
V_23:
F_68 ( V_35 ) ;
return V_23 ;
}
static void F_46 ( struct V_14 * V_15 ,
struct V_177 * V_8 )
{
if ( ! F_65 ( V_8 -> V_133 ) ) {
F_29 ( V_8 -> V_133 ) ;
V_8 -> V_133 = NULL ;
}
}
static int F_42 ( struct V_14 * V_15 ,
struct V_177 * V_8 , int type )
{
struct V_34 * V_35 = V_15 -> V_36 . V_44 . V_35 . V_37 ;
struct V_38 V_39 ;
F_19 ( V_42 ) ;
struct V_32 * V_33 ;
int V_23 = 0 ;
T_1 * V_178 ;
T_1 * V_179 ;
V_33 = F_26 ( sizeof( * V_33 ) , V_27 ) ;
if ( ! V_33 )
return - V_28 ;
V_178 = F_79 ( V_49 , V_33 -> V_50 ,
V_51 . V_180 ) ;
V_179 = F_79 ( V_49 , V_33 -> V_55 ,
V_51 . V_180 ) ;
V_39 . type = V_43 ;
V_39 . V_35 = V_15 -> V_36 . V_121 . V_35 . V_37 ;
switch ( type ) {
case V_72 :
V_33 -> V_45 = V_46 ;
F_90 ( V_178 ) ;
F_6 ( V_179 , V_8 -> V_1 ) ;
break;
case V_116 :
V_33 -> V_45 = V_46 ;
V_178 [ 0 ] = 0x01 ;
V_179 [ 0 ] = 0x01 ;
break;
case V_114 :
break;
}
V_8 -> V_133 = F_22 ( V_35 , V_33 , & V_42 , & V_39 , 1 ) ;
if ( F_23 ( V_8 -> V_133 ) ) {
F_17 ( V_15 -> V_18 , L_11 ,
V_61 , V_179 ) ;
V_23 = F_24 ( V_8 -> V_133 ) ;
V_8 -> V_133 = NULL ;
}
F_27 ( V_33 ) ;
return V_23 ;
}
static int F_91 ( struct V_95 * V_181 )
{
int V_149 = F_78 ( V_150 ) ;
struct V_117 * V_35 = & V_181 -> V_35 ;
int V_6 = 0 ;
T_1 * V_178 ;
T_5 * V_151 ;
int V_23 ;
T_1 * V_152 ;
V_35 -> V_119 = F_15 ( V_182 , sizeof( * V_35 -> V_119 ) , V_27 ) ;
if ( ! V_35 -> V_119 )
return - V_28 ;
V_151 = F_26 ( V_149 , V_27 ) ;
if ( ! V_151 ) {
F_10 ( V_35 -> V_119 ) ;
return - V_28 ;
}
V_152 = F_79 ( V_150 , V_151 , V_50 ) ;
V_178 = F_79 ( V_49 , V_152 ,
V_51 . V_180 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_183 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_184;
V_35 -> V_118 ++ ;
F_90 ( V_178 ) ;
F_80 ( V_151 , V_45 , V_46 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_185 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_184;
V_35 -> V_118 ++ ;
F_92 ( V_178 ) ;
V_178 [ 0 ] = 0x01 ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_186 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_184;
V_35 -> V_118 ++ ;
F_27 ( V_151 ) ;
return 0 ;
V_184:
V_23 = F_24 ( V_35 -> V_119 [ V_35 -> V_118 ] ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = NULL ;
F_64 ( V_35 ) ;
F_27 ( V_151 ) ;
return V_23 ;
}
static void F_93 ( struct V_14 * V_15 )
{
F_68 ( & V_15 -> V_36 . V_44 . V_35 ) ;
}
static int F_94 ( struct V_14 * V_15 )
{
struct V_95 * V_181 = & V_15 -> V_36 . V_44 ;
struct V_117 * V_35 = & V_181 -> V_35 ;
struct V_166 V_167 = {} ;
int V_23 ;
V_35 -> V_118 = 0 ;
V_167 . V_168 = V_187 ;
V_167 . V_170 = V_188 ;
V_167 . V_172 = V_173 ;
V_35 -> V_37 = F_86 ( V_15 -> V_36 . V_174 , & V_167 ) ;
if ( F_23 ( V_35 -> V_37 ) ) {
V_23 = F_24 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_23 = F_91 ( V_181 ) ;
if ( V_23 )
goto V_189;
return 0 ;
V_189:
F_69 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
static int F_95 ( struct V_117 * V_35 , T_5 * V_151 ,
int V_149 )
{
int V_23 ;
int V_6 = 0 ;
T_1 * V_152 = F_79 ( V_150 , V_151 , V_50 ) ;
memset ( V_151 , 0 , V_149 ) ;
F_80 ( V_151 , V_45 , V_46 ) ;
F_20 ( V_49 , V_152 , V_51 . V_52 ) ;
F_20 ( V_49 , V_152 , V_51 . V_60 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_190 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_184;
V_35 -> V_118 ++ ;
memset ( V_151 , 0 , V_149 ) ;
F_80 ( V_151 , V_45 , V_46 ) ;
F_20 ( V_49 , V_152 , V_51 . V_52 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_191 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_184;
V_35 -> V_118 ++ ;
memset ( V_151 , 0 , V_149 ) ;
F_80 ( V_151 , V_45 , V_46 ) ;
F_20 ( V_49 , V_152 , V_51 . V_58 ) ;
F_80 ( V_151 , V_154 , V_6 ) ;
V_6 += V_192 ;
F_80 ( V_151 , V_156 , V_6 - 1 ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = F_81 ( V_35 -> V_37 , V_151 ) ;
if ( F_23 ( V_35 -> V_119 [ V_35 -> V_118 ] ) )
goto V_184;
V_35 -> V_118 ++ ;
return 0 ;
V_184:
V_23 = F_24 ( V_35 -> V_119 [ V_35 -> V_118 ] ) ;
V_35 -> V_119 [ V_35 -> V_118 ] = NULL ;
F_64 ( V_35 ) ;
return V_23 ;
}
static int F_96 ( struct V_117 * V_35 )
{
T_5 * V_151 ;
int V_149 = F_78 ( V_150 ) ;
int V_23 ;
V_151 = F_26 ( V_149 , V_27 ) ;
if ( ! V_151 )
return - V_28 ;
V_23 = F_95 ( V_35 , V_151 , V_149 ) ;
F_27 ( V_151 ) ;
return V_23 ;
}
static int F_97 ( struct V_14 * V_15 )
{
struct V_117 * V_35 = & V_15 -> V_36 . V_22 . V_35 ;
struct V_166 V_167 = {} ;
int V_23 ;
V_35 -> V_118 = 0 ;
V_167 . V_168 = V_193 ;
V_167 . V_170 = V_194 ;
V_167 . V_172 = V_173 ;
V_35 -> V_37 = F_86 ( V_15 -> V_36 . V_174 , & V_167 ) ;
if ( F_23 ( V_35 -> V_37 ) ) {
V_23 = F_24 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_35 -> V_119 = F_15 ( V_195 , sizeof( * V_35 -> V_119 ) , V_27 ) ;
if ( ! V_35 -> V_119 ) {
V_23 = - V_28 ;
goto V_196;
}
V_23 = F_96 ( V_35 ) ;
if ( V_23 )
goto V_197;
F_39 ( V_15 ) ;
return 0 ;
V_197:
F_10 ( V_35 -> V_119 ) ;
V_196:
F_69 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
static void F_98 ( struct V_14 * V_15 )
{
F_40 ( V_15 ) ;
F_68 ( & V_15 -> V_36 . V_22 . V_35 ) ;
}
int F_99 ( struct V_14 * V_15 )
{
int V_23 ;
V_15 -> V_36 . V_174 = F_100 ( V_15 -> V_25 ,
V_198 ) ;
if ( ! V_15 -> V_36 . V_174 )
return - V_199 ;
V_23 = F_101 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_12 ,
V_23 ) ;
V_15 -> V_18 -> V_200 &= ~ V_201 ;
}
V_23 = F_85 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_13 ,
V_23 ) ;
goto V_202;
}
V_23 = F_89 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_14 ,
V_23 ) ;
goto V_203;
}
V_23 = F_94 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_15 ,
V_23 ) ;
goto V_204;
}
V_23 = F_97 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_16 ,
V_23 ) ;
goto V_205;
}
F_102 ( V_15 ) ;
return 0 ;
V_205:
F_93 ( V_15 ) ;
V_204:
F_88 ( V_15 ) ;
V_203:
F_87 ( V_15 ) ;
V_202:
F_103 ( V_15 ) ;
return V_23 ;
}
void F_104 ( struct V_14 * V_15 )
{
F_98 ( V_15 ) ;
F_93 ( V_15 ) ;
F_88 ( V_15 ) ;
F_87 ( V_15 ) ;
F_103 ( V_15 ) ;
F_105 ( V_15 ) ;
}
