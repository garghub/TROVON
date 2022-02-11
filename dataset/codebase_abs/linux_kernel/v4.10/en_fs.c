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
F_19 ( V_52 , V_33 -> V_53 , V_54 . V_55 ) ;
switch ( V_30 ) {
case V_56 :
V_47 = & V_15 -> V_42 . V_22 . V_57 ;
break;
case V_58 :
V_47 = & V_15 -> V_42 . V_22 . V_59 ;
F_20 ( V_52 , V_33 -> V_60 , V_54 . V_55 , 1 ) ;
break;
default:
V_47 = & V_15 -> V_42 . V_22 . V_61 [ V_31 ] ;
F_20 ( V_52 , V_33 -> V_60 , V_54 . V_55 , 1 ) ;
F_19 ( V_52 , V_33 -> V_53 ,
V_54 . V_62 ) ;
F_20 ( V_52 , V_33 -> V_60 , V_54 . V_62 ,
V_31 ) ;
break;
}
* V_47 = F_21 ( V_41 , V_33 , & V_35 , & V_45 , 1 ) ;
if ( F_22 ( * V_47 ) ) {
V_23 = F_23 ( * V_47 ) ;
* V_47 = NULL ;
F_17 ( V_15 -> V_18 , L_3 , V_63 ) ;
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
F_17 ( V_15 -> V_18 , L_4 , V_63 ) ;
return - V_28 ;
}
if ( V_30 == V_64 )
F_11 ( V_15 ) ;
V_23 = F_18 ( V_15 , V_30 , V_31 , V_33 ) ;
F_26 ( V_33 ) ;
return V_23 ;
}
static void F_27 ( struct V_14 * V_15 ,
enum V_29 V_30 , T_2 V_31 )
{
switch ( V_30 ) {
case V_56 :
if ( V_15 -> V_42 . V_22 . V_57 ) {
F_28 ( V_15 -> V_42 . V_22 . V_57 ) ;
V_15 -> V_42 . V_22 . V_57 = NULL ;
}
break;
case V_58 :
if ( V_15 -> V_42 . V_22 . V_59 ) {
F_28 ( V_15 -> V_42 . V_22 . V_59 ) ;
V_15 -> V_42 . V_22 . V_59 = NULL ;
}
break;
case V_64 :
F_11 ( V_15 ) ;
if ( V_15 -> V_42 . V_22 . V_61 [ V_31 ] ) {
F_28 ( V_15 -> V_42 . V_22 . V_61 [ V_31 ] ) ;
V_15 -> V_42 . V_22 . V_61 [ V_31 ] = NULL ;
}
F_11 ( V_15 ) ;
break;
}
}
void F_29 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_42 . V_22 . V_65 )
return;
V_15 -> V_42 . V_22 . V_65 = false ;
if ( V_15 -> V_18 -> V_66 & V_67 )
return;
F_27 ( V_15 , V_58 , 0 ) ;
}
void F_30 ( struct V_14 * V_15 )
{
if ( V_15 -> V_42 . V_22 . V_65 )
return;
V_15 -> V_42 . V_22 . V_65 = true ;
if ( V_15 -> V_18 -> V_66 & V_67 )
return;
F_24 ( V_15 , V_58 , 0 ) ;
}
int F_31 ( struct V_16 * V_68 , T_3 T_4 V_69 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_32 ( V_68 ) ;
F_33 ( V_31 , V_15 -> V_42 . V_22 . V_70 ) ;
return F_24 ( V_15 , V_64 , V_31 ) ;
}
int F_34 ( struct V_16 * V_68 , T_3 T_4 V_69 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_32 ( V_68 ) ;
F_35 ( V_31 , V_15 -> V_42 . V_22 . V_70 ) ;
F_27 ( V_15 , V_64 , V_31 ) ;
return 0 ;
}
static void F_36 ( struct V_14 * V_15 )
{
int V_24 ;
F_24 ( V_15 , V_56 , 0 ) ;
F_12 (i, priv->fs.vlan.active_vlans, VLAN_N_VID) {
F_24 ( V_15 , V_64 , V_24 ) ;
}
if ( V_15 -> V_42 . V_22 . V_65 &&
! ( V_15 -> V_18 -> V_66 & V_67 ) )
F_24 ( V_15 , V_58 , 0 ) ;
}
static void F_37 ( struct V_14 * V_15 )
{
int V_24 ;
F_27 ( V_15 , V_56 , 0 ) ;
F_12 (i, priv->fs.vlan.active_vlans, VLAN_N_VID) {
F_27 ( V_15 , V_64 , V_24 ) ;
}
if ( V_15 -> V_42 . V_22 . V_65 &&
! ( V_15 -> V_18 -> V_66 & V_67 ) )
F_27 ( V_15 , V_58 , 0 ) ;
}
static void F_38 ( struct V_14 * V_15 ,
struct V_4 * V_5 )
{
switch ( V_5 -> V_9 ) {
case V_12 :
F_39 ( V_15 , & V_5 -> V_8 , V_71 ) ;
V_5 -> V_9 = V_10 ;
break;
case V_72 :
F_40 ( V_15 , & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
break;
}
}
static void F_41 ( struct V_14 * V_15 )
{
struct V_16 * V_18 = V_15 -> V_18 ;
struct V_73 * V_74 ;
F_42 ( V_18 ) ;
F_2 ( V_15 -> V_42 . V_49 . V_75 ,
V_15 -> V_18 -> V_76 ) ;
F_43 (ha, netdev)
F_2 ( V_15 -> V_42 . V_49 . V_75 , V_74 -> V_1 ) ;
F_44 (ha, netdev)
F_2 ( V_15 -> V_42 . V_49 . V_77 , V_74 -> V_1 ) ;
F_45 ( V_18 ) ;
}
static void F_46 ( struct V_14 * V_15 , int V_78 ,
T_1 V_79 [] [ V_80 ] , int V_81 )
{
bool V_82 = ( V_78 == V_83 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_4 * V_5 ;
struct V_2 * V_84 ;
struct V_85 * V_86 ;
int V_24 = 0 ;
int V_87 ;
V_84 = V_82 ? V_15 -> V_42 . V_49 . V_75 : V_15 -> V_42 . V_49 . V_77 ;
if ( V_82 )
F_6 ( V_79 [ V_24 ++ ] , V_17 -> V_76 ) ;
else if ( V_15 -> V_42 . V_49 . V_88 )
F_6 ( V_79 [ V_24 ++ ] , V_17 -> V_89 ) ;
F_47 (hn, tmp, addr_list, hi) {
if ( F_48 ( V_17 -> V_76 , V_5 -> V_8 . V_1 ) )
continue;
if ( V_24 >= V_81 )
break;
F_6 ( V_79 [ V_24 ++ ] , V_5 -> V_8 . V_1 ) ;
}
}
static void F_49 ( struct V_14 * V_15 ,
int V_78 )
{
bool V_82 = ( V_78 == V_83 ) ;
struct V_4 * V_5 ;
T_1 ( * V_79 ) [ V_80 ] = NULL ;
struct V_2 * V_84 ;
struct V_85 * V_86 ;
int V_90 ;
int V_81 ;
int V_23 ;
int V_87 ;
V_81 = V_82 ? 0 : ( V_15 -> V_42 . V_49 . V_88 ? 1 : 0 ) ;
V_90 = V_82 ?
1 << F_13 ( V_15 -> V_25 , V_91 ) :
1 << F_13 ( V_15 -> V_25 , V_92 ) ;
V_84 = V_82 ? V_15 -> V_42 . V_49 . V_75 : V_15 -> V_42 . V_49 . V_77 ;
F_47 (hn, tmp, addr_list, hi)
V_81 ++ ;
if ( V_81 > V_90 ) {
F_14 ( V_15 -> V_18 ,
L_5 ,
V_82 ? L_6 : L_7 , V_81 , V_90 ) ;
V_81 = V_90 ;
}
if ( V_81 ) {
V_79 = F_15 ( V_81 , V_80 , V_27 ) ;
if ( ! V_79 ) {
V_23 = - V_28 ;
goto V_93;
}
F_46 ( V_15 , V_78 , V_79 , V_81 ) ;
}
V_23 = F_50 ( V_15 -> V_25 , V_78 , V_79 , V_81 ) ;
V_93:
if ( V_23 )
F_17 ( V_15 -> V_18 ,
L_8 ,
V_82 ? L_6 : L_7 , V_23 ) ;
F_10 ( V_79 ) ;
}
static void F_51 ( struct V_14 * V_15 )
{
struct V_94 * V_95 = & V_15 -> V_42 . V_49 ;
F_49 ( V_15 , V_83 ) ;
F_49 ( V_15 , V_96 ) ;
F_52 ( V_15 -> V_25 , 0 ,
V_95 -> V_97 ,
V_95 -> V_98 ) ;
}
static void F_53 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_85 * V_86 ;
int V_24 ;
F_47 (hn, tmp, priv->fs.l2.netdev_uc, i)
F_38 ( V_15 , V_5 ) ;
F_47 (hn, tmp, priv->fs.l2.netdev_mc, i)
F_38 ( V_15 , V_5 ) ;
}
static void F_54 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_85 * V_86 ;
int V_24 ;
F_47 (hn, tmp, priv->fs.l2.netdev_uc, i)
V_5 -> V_9 = V_72 ;
F_47 (hn, tmp, priv->fs.l2.netdev_mc, i)
V_5 -> V_9 = V_72 ;
if ( ! F_55 ( V_99 , & V_15 -> V_100 ) )
F_41 ( V_15 ) ;
F_53 ( V_15 ) ;
}
void F_56 ( struct V_101 * V_102 )
{
struct V_14 * V_15 = F_57 ( V_102 , struct V_14 ,
V_103 ) ;
struct V_94 * V_95 = & V_15 -> V_42 . V_49 ;
struct V_16 * V_17 = V_15 -> V_18 ;
bool V_104 = ! F_55 ( V_99 , & V_15 -> V_100 ) ;
bool V_98 = V_104 && ( V_17 -> V_66 & V_67 ) ;
bool V_97 = V_104 && ( V_17 -> V_66 & V_105 ) ;
bool V_88 = V_104 ;
bool V_106 = ! V_95 -> V_98 && V_98 ;
bool V_107 = V_95 -> V_98 && ! V_98 ;
bool V_108 = ! V_95 -> V_97 && V_97 ;
bool V_109 = V_95 -> V_97 && ! V_97 ;
bool V_110 = ! V_95 -> V_88 && V_88 ;
bool V_111 = V_95 -> V_88 && ! V_88 ;
if ( V_106 ) {
F_39 ( V_15 , & V_95 -> V_112 , V_113 ) ;
if ( ! V_15 -> V_42 . V_22 . V_65 )
F_24 ( V_15 , V_58 ,
0 ) ;
}
if ( V_108 )
F_39 ( V_15 , & V_95 -> V_114 , V_115 ) ;
if ( V_110 )
F_39 ( V_15 , & V_95 -> V_89 , V_71 ) ;
F_54 ( V_15 ) ;
if ( V_111 )
F_40 ( V_15 , & V_95 -> V_89 ) ;
if ( V_109 )
F_40 ( V_15 , & V_95 -> V_114 ) ;
if ( V_107 ) {
if ( ! V_15 -> V_42 . V_22 . V_65 )
F_27 ( V_15 , V_58 ,
0 ) ;
F_40 ( V_15 , & V_95 -> V_112 ) ;
}
V_95 -> V_98 = V_98 ;
V_95 -> V_97 = V_97 ;
V_95 -> V_88 = V_88 ;
F_51 ( V_15 ) ;
}
static void F_58 ( struct V_116 * V_41 )
{
int V_24 ;
for ( V_24 = V_41 -> V_117 - 1 ; V_24 >= 0 ; V_24 -- ) {
if ( ! F_59 ( V_41 -> V_118 [ V_24 ] ) )
F_60 ( V_41 -> V_118 [ V_24 ] ) ;
V_41 -> V_118 [ V_24 ] = NULL ;
}
V_41 -> V_117 = 0 ;
}
void F_61 ( struct V_14 * V_15 )
{
F_6 ( V_15 -> V_42 . V_49 . V_89 . V_1 , V_15 -> V_18 -> V_89 ) ;
}
void F_62 ( struct V_116 * V_41 )
{
F_58 ( V_41 ) ;
F_10 ( V_41 -> V_118 ) ;
F_63 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
}
static void F_64 ( struct V_119 * V_120 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_121 ; V_24 ++ ) {
if ( ! F_59 ( V_120 -> V_122 [ V_24 ] ) ) {
F_28 ( V_120 -> V_122 [ V_24 ] ) ;
V_120 -> V_122 [ V_24 ] = NULL ;
}
}
}
static struct V_46 *
F_65 ( struct V_14 * V_15 ,
struct V_40 * V_41 ,
struct V_44 * V_45 ,
T_2 V_123 ,
T_1 V_69 )
{
struct V_34 V_35 = {
. V_9 = V_36 ,
. V_37 = V_38 ,
. V_39 = 0 ,
} ;
struct V_46 * V_124 ;
struct V_32 * V_33 ;
int V_23 = 0 ;
V_33 = F_25 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_63 ) ;
return F_66 ( - V_28 ) ;
}
if ( V_69 ) {
V_33 -> V_50 = V_51 ;
F_19 ( V_52 , V_33 -> V_53 , V_54 . V_125 ) ;
F_20 ( V_52 , V_33 -> V_60 , V_54 . V_125 , V_69 ) ;
}
if ( V_123 ) {
V_33 -> V_50 = V_51 ;
F_19 ( V_52 , V_33 -> V_53 , V_54 . V_126 ) ;
F_20 ( V_52 , V_33 -> V_60 , V_54 . V_126 , V_123 ) ;
}
V_124 = F_21 ( V_41 , V_33 , & V_35 , V_45 , 1 ) ;
if ( F_22 ( V_124 ) ) {
V_23 = F_23 ( V_124 ) ;
F_17 ( V_15 -> V_18 , L_3 , V_63 ) ;
}
F_26 ( V_33 ) ;
return V_23 ? F_66 ( V_23 ) : V_124 ;
}
static int F_67 ( struct V_14 * V_15 )
{
struct V_44 V_45 ;
struct V_119 * V_120 ;
struct V_46 * * V_122 ;
struct V_40 * V_41 ;
int V_127 ;
int V_23 ;
V_120 = & V_15 -> V_42 . V_120 ;
V_41 = V_120 -> V_41 . V_43 ;
V_122 = V_120 -> V_122 ;
V_45 . type = V_128 ;
for ( V_127 = 0 ; V_127 < V_121 ; V_127 ++ ) {
if ( V_127 == V_129 )
V_45 . V_130 = V_15 -> V_131 [ 0 ] . V_132 ;
else
V_45 . V_130 = V_15 -> V_133 [ V_127 ] . V_132 ;
V_122 [ V_127 ] = F_65 ( V_15 , V_41 , & V_45 ,
V_134 [ V_127 ] . V_123 ,
V_134 [ V_127 ] . V_69 ) ;
if ( F_22 ( V_122 [ V_127 ] ) )
goto V_135;
}
return 0 ;
V_135:
V_23 = F_23 ( V_122 [ V_127 ] ) ;
V_122 [ V_127 ] = NULL ;
F_64 ( V_120 ) ;
return V_23 ;
}
static int F_68 ( struct V_119 * V_120 )
{
int V_136 = F_69 ( V_137 ) ;
struct V_116 * V_41 = & V_120 -> V_41 ;
int V_6 = 0 ;
T_5 * V_138 ;
int V_23 ;
T_1 * V_139 ;
V_41 -> V_118 = F_15 ( V_140 ,
sizeof( * V_41 -> V_118 ) , V_27 ) ;
if ( ! V_41 -> V_118 )
return - V_28 ;
V_138 = F_25 ( V_136 ) ;
if ( ! V_138 ) {
F_10 ( V_41 -> V_118 ) ;
return - V_28 ;
}
V_139 = F_70 ( V_137 , V_138 , V_53 ) ;
F_19 ( V_52 , V_139 , V_54 . V_125 ) ;
F_19 ( V_52 , V_139 , V_54 . V_126 ) ;
F_71 ( V_138 , V_50 , V_51 ) ;
F_71 ( V_138 , V_141 , V_6 ) ;
V_6 += V_142 ;
F_71 ( V_138 , V_143 , V_6 - 1 ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = F_72 ( V_41 -> V_43 , V_138 ) ;
if ( F_22 ( V_41 -> V_118 [ V_41 -> V_117 ] ) )
goto V_23;
V_41 -> V_117 ++ ;
F_20 ( V_52 , V_139 , V_54 . V_125 , 0 ) ;
F_71 ( V_138 , V_141 , V_6 ) ;
V_6 += V_144 ;
F_71 ( V_138 , V_143 , V_6 - 1 ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = F_72 ( V_41 -> V_43 , V_138 ) ;
if ( F_22 ( V_41 -> V_118 [ V_41 -> V_117 ] ) )
goto V_23;
V_41 -> V_117 ++ ;
memset ( V_138 , 0 , V_136 ) ;
F_71 ( V_138 , V_141 , V_6 ) ;
V_6 += V_145 ;
F_71 ( V_138 , V_143 , V_6 - 1 ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = F_72 ( V_41 -> V_43 , V_138 ) ;
if ( F_22 ( V_41 -> V_118 [ V_41 -> V_117 ] ) )
goto V_23;
V_41 -> V_117 ++ ;
F_26 ( V_138 ) ;
return 0 ;
V_23:
V_23 = F_23 ( V_41 -> V_118 [ V_41 -> V_117 ] ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = NULL ;
F_26 ( V_138 ) ;
return V_23 ;
}
static void F_73 ( struct V_14 * V_15 )
{
struct V_119 * V_120 = & V_15 -> V_42 . V_120 ;
F_64 ( V_120 ) ;
F_62 ( & V_120 -> V_41 ) ;
}
static int F_74 ( struct V_14 * V_15 )
{
struct V_119 * V_120 = & V_15 -> V_42 . V_120 ;
struct V_116 * V_41 = & V_120 -> V_41 ;
int V_23 ;
V_41 -> V_43 = F_75 ( V_15 -> V_42 . V_146 , V_147 ,
V_148 , V_149 , 0 ) ;
if ( F_22 ( V_41 -> V_43 ) ) {
V_23 = F_23 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
V_23 = F_68 ( V_120 ) ;
if ( V_23 )
goto V_23;
V_23 = F_67 ( V_15 ) ;
if ( V_23 )
goto V_23;
return 0 ;
V_23:
F_62 ( V_41 ) ;
return V_23 ;
}
static void F_40 ( struct V_14 * V_15 ,
struct V_150 * V_8 )
{
if ( ! F_59 ( V_8 -> V_124 ) ) {
F_28 ( V_8 -> V_124 ) ;
V_8 -> V_124 = NULL ;
}
}
static int F_39 ( struct V_14 * V_15 ,
struct V_150 * V_8 , int type )
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
T_1 * V_151 ;
T_1 * V_152 ;
V_33 = F_25 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_63 ) ;
return - V_28 ;
}
V_151 = F_70 ( V_52 , V_33 -> V_53 ,
V_54 . V_153 ) ;
V_152 = F_70 ( V_52 , V_33 -> V_60 ,
V_54 . V_153 ) ;
V_45 . type = V_48 ;
V_45 . V_41 = V_15 -> V_42 . V_120 . V_41 . V_43 ;
switch ( type ) {
case V_71 :
V_33 -> V_50 = V_51 ;
F_76 ( V_151 ) ;
F_6 ( V_152 , V_8 -> V_1 ) ;
break;
case V_115 :
V_33 -> V_50 = V_51 ;
V_151 [ 0 ] = 0x01 ;
V_152 [ 0 ] = 0x01 ;
break;
case V_113 :
break;
}
V_8 -> V_124 = F_21 ( V_41 , V_33 , & V_35 , & V_45 , 1 ) ;
if ( F_22 ( V_8 -> V_124 ) ) {
F_17 ( V_15 -> V_18 , L_9 ,
V_63 , V_152 ) ;
V_23 = F_23 ( V_8 -> V_124 ) ;
V_8 -> V_124 = NULL ;
}
F_26 ( V_33 ) ;
return V_23 ;
}
static int F_77 ( struct V_94 * V_154 )
{
int V_136 = F_69 ( V_137 ) ;
struct V_116 * V_41 = & V_154 -> V_41 ;
int V_6 = 0 ;
T_1 * V_151 ;
T_5 * V_138 ;
int V_23 ;
T_1 * V_139 ;
V_41 -> V_118 = F_15 ( V_155 , sizeof( * V_41 -> V_118 ) , V_27 ) ;
if ( ! V_41 -> V_118 )
return - V_28 ;
V_138 = F_25 ( V_136 ) ;
if ( ! V_138 ) {
F_10 ( V_41 -> V_118 ) ;
return - V_28 ;
}
V_139 = F_70 ( V_137 , V_138 , V_53 ) ;
V_151 = F_70 ( V_52 , V_139 ,
V_54 . V_153 ) ;
F_71 ( V_138 , V_141 , V_6 ) ;
V_6 += V_156 ;
F_71 ( V_138 , V_143 , V_6 - 1 ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = F_72 ( V_41 -> V_43 , V_138 ) ;
if ( F_22 ( V_41 -> V_118 [ V_41 -> V_117 ] ) )
goto V_157;
V_41 -> V_117 ++ ;
F_76 ( V_151 ) ;
F_71 ( V_138 , V_50 , V_51 ) ;
F_71 ( V_138 , V_141 , V_6 ) ;
V_6 += V_158 ;
F_71 ( V_138 , V_143 , V_6 - 1 ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = F_72 ( V_41 -> V_43 , V_138 ) ;
if ( F_22 ( V_41 -> V_118 [ V_41 -> V_117 ] ) )
goto V_157;
V_41 -> V_117 ++ ;
F_78 ( V_151 ) ;
V_151 [ 0 ] = 0x01 ;
F_71 ( V_138 , V_141 , V_6 ) ;
V_6 += V_159 ;
F_71 ( V_138 , V_143 , V_6 - 1 ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = F_72 ( V_41 -> V_43 , V_138 ) ;
if ( F_22 ( V_41 -> V_118 [ V_41 -> V_117 ] ) )
goto V_157;
V_41 -> V_117 ++ ;
F_26 ( V_138 ) ;
return 0 ;
V_157:
V_23 = F_23 ( V_41 -> V_118 [ V_41 -> V_117 ] ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = NULL ;
F_58 ( V_41 ) ;
F_26 ( V_138 ) ;
return V_23 ;
}
static void F_79 ( struct V_14 * V_15 )
{
F_62 ( & V_15 -> V_42 . V_49 . V_41 ) ;
}
static int F_80 ( struct V_14 * V_15 )
{
struct V_94 * V_154 = & V_15 -> V_42 . V_49 ;
struct V_116 * V_41 = & V_154 -> V_41 ;
int V_23 ;
V_41 -> V_117 = 0 ;
V_41 -> V_43 = F_75 ( V_15 -> V_42 . V_146 , V_147 ,
V_160 , V_161 , 0 ) ;
if ( F_22 ( V_41 -> V_43 ) ) {
V_23 = F_23 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
V_23 = F_77 ( V_154 ) ;
if ( V_23 )
goto V_162;
return 0 ;
V_162:
F_63 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
static int F_81 ( struct V_116 * V_41 , T_5 * V_138 ,
int V_136 )
{
int V_23 ;
int V_6 = 0 ;
T_1 * V_139 = F_70 ( V_137 , V_138 , V_53 ) ;
memset ( V_138 , 0 , V_136 ) ;
F_71 ( V_138 , V_50 , V_51 ) ;
F_19 ( V_52 , V_139 , V_54 . V_55 ) ;
F_19 ( V_52 , V_139 , V_54 . V_62 ) ;
F_71 ( V_138 , V_141 , V_6 ) ;
V_6 += V_163 ;
F_71 ( V_138 , V_143 , V_6 - 1 ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = F_72 ( V_41 -> V_43 , V_138 ) ;
if ( F_22 ( V_41 -> V_118 [ V_41 -> V_117 ] ) )
goto V_157;
V_41 -> V_117 ++ ;
memset ( V_138 , 0 , V_136 ) ;
F_71 ( V_138 , V_50 , V_51 ) ;
F_19 ( V_52 , V_139 , V_54 . V_55 ) ;
F_71 ( V_138 , V_141 , V_6 ) ;
V_6 += V_164 ;
F_71 ( V_138 , V_143 , V_6 - 1 ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = F_72 ( V_41 -> V_43 , V_138 ) ;
if ( F_22 ( V_41 -> V_118 [ V_41 -> V_117 ] ) )
goto V_157;
V_41 -> V_117 ++ ;
return 0 ;
V_157:
V_23 = F_23 ( V_41 -> V_118 [ V_41 -> V_117 ] ) ;
V_41 -> V_118 [ V_41 -> V_117 ] = NULL ;
F_58 ( V_41 ) ;
return V_23 ;
}
static int F_82 ( struct V_116 * V_41 )
{
T_5 * V_138 ;
int V_136 = F_69 ( V_137 ) ;
int V_23 ;
V_138 = F_25 ( V_136 ) ;
if ( ! V_138 )
return - V_28 ;
V_23 = F_81 ( V_41 , V_138 , V_136 ) ;
F_26 ( V_138 ) ;
return V_23 ;
}
static int F_83 ( struct V_14 * V_15 )
{
struct V_116 * V_41 = & V_15 -> V_42 . V_22 . V_41 ;
int V_23 ;
V_41 -> V_117 = 0 ;
V_41 -> V_43 = F_75 ( V_15 -> V_42 . V_146 , V_147 ,
V_165 , V_166 , 0 ) ;
if ( F_22 ( V_41 -> V_43 ) ) {
V_23 = F_23 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
V_41 -> V_118 = F_15 ( V_167 , sizeof( * V_41 -> V_118 ) , V_27 ) ;
if ( ! V_41 -> V_118 ) {
V_23 = - V_28 ;
goto V_168;
}
V_23 = F_82 ( V_41 ) ;
if ( V_23 )
goto V_169;
F_36 ( V_15 ) ;
return 0 ;
V_169:
F_10 ( V_41 -> V_118 ) ;
V_168:
F_63 ( V_41 -> V_43 ) ;
V_41 -> V_43 = NULL ;
return V_23 ;
}
static void F_84 ( struct V_14 * V_15 )
{
F_37 ( V_15 ) ;
F_62 ( & V_15 -> V_42 . V_22 . V_41 ) ;
}
int F_85 ( struct V_14 * V_15 )
{
int V_23 ;
V_15 -> V_42 . V_146 = F_86 ( V_15 -> V_25 ,
V_170 ) ;
if ( ! V_15 -> V_42 . V_146 )
return - V_171 ;
V_23 = F_87 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_10 ,
V_23 ) ;
V_15 -> V_18 -> V_172 &= ~ V_173 ;
}
V_23 = F_74 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_11 ,
V_23 ) ;
goto V_174;
}
V_23 = F_80 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_12 ,
V_23 ) ;
goto V_175;
}
V_23 = F_83 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_13 ,
V_23 ) ;
goto V_176;
}
F_88 ( V_15 ) ;
return 0 ;
V_176:
F_79 ( V_15 ) ;
V_175:
F_73 ( V_15 ) ;
V_174:
F_89 ( V_15 ) ;
return V_23 ;
}
void F_90 ( struct V_14 * V_15 )
{
F_84 ( V_15 ) ;
F_79 ( V_15 ) ;
F_73 ( V_15 ) ;
F_89 ( V_15 ) ;
F_91 ( V_15 ) ;
}
