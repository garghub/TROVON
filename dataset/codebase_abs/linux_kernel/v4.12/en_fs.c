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
V_33 = F_26 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_61 ) ;
return - V_28 ;
}
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
F_30 ( V_15 ) ;
}
void F_33 ( struct V_14 * V_15 )
{
if ( V_15 -> V_36 . V_22 . V_63 )
return;
V_15 -> V_36 . V_22 . V_63 = true ;
if ( V_15 -> V_18 -> V_64 & V_65 )
return;
F_31 ( V_15 ) ;
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
switch ( V_5 -> V_9 ) {
case V_12 :
F_42 ( V_15 , & V_5 -> V_8 , V_69 ) ;
V_5 -> V_9 = V_10 ;
break;
case V_70 :
F_43 ( V_15 , & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
break;
}
}
static void F_44 ( struct V_14 * V_15 )
{
struct V_16 * V_18 = V_15 -> V_18 ;
struct V_71 * V_72 ;
F_45 ( V_18 ) ;
F_2 ( V_15 -> V_36 . V_44 . V_73 ,
V_15 -> V_18 -> V_74 ) ;
F_46 (ha, netdev)
F_2 ( V_15 -> V_36 . V_44 . V_73 , V_72 -> V_1 ) ;
F_47 (ha, netdev)
F_2 ( V_15 -> V_36 . V_44 . V_75 , V_72 -> V_1 ) ;
F_48 ( V_18 ) ;
}
static void F_49 ( struct V_14 * V_15 , int V_76 ,
T_1 V_77 [] [ V_78 ] , int V_79 )
{
bool V_80 = ( V_76 == V_81 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_4 * V_5 ;
struct V_2 * V_82 ;
struct V_83 * V_84 ;
int V_24 = 0 ;
int V_85 ;
V_82 = V_80 ? V_15 -> V_36 . V_44 . V_73 : V_15 -> V_36 . V_44 . V_75 ;
if ( V_80 )
F_6 ( V_77 [ V_24 ++ ] , V_17 -> V_74 ) ;
else if ( V_15 -> V_36 . V_44 . V_86 )
F_6 ( V_77 [ V_24 ++ ] , V_17 -> V_87 ) ;
F_50 (hn, tmp, addr_list, hi) {
if ( F_51 ( V_17 -> V_74 , V_5 -> V_8 . V_1 ) )
continue;
if ( V_24 >= V_79 )
break;
F_6 ( V_77 [ V_24 ++ ] , V_5 -> V_8 . V_1 ) ;
}
}
static void F_52 ( struct V_14 * V_15 ,
int V_76 )
{
bool V_80 = ( V_76 == V_81 ) ;
struct V_4 * V_5 ;
T_1 ( * V_77 ) [ V_78 ] = NULL ;
struct V_2 * V_82 ;
struct V_83 * V_84 ;
int V_88 ;
int V_79 ;
int V_23 ;
int V_85 ;
V_79 = V_80 ? 0 : ( V_15 -> V_36 . V_44 . V_86 ? 1 : 0 ) ;
V_88 = V_80 ?
1 << F_13 ( V_15 -> V_25 , V_89 ) :
1 << F_13 ( V_15 -> V_25 , V_90 ) ;
V_82 = V_80 ? V_15 -> V_36 . V_44 . V_73 : V_15 -> V_36 . V_44 . V_75 ;
F_50 (hn, tmp, addr_list, hi)
V_79 ++ ;
if ( V_79 > V_88 ) {
F_14 ( V_15 -> V_18 ,
L_5 ,
V_80 ? L_6 : L_7 , V_79 , V_88 ) ;
V_79 = V_88 ;
}
if ( V_79 ) {
V_77 = F_15 ( V_79 , V_78 , V_27 ) ;
if ( ! V_77 ) {
V_23 = - V_28 ;
goto V_91;
}
F_49 ( V_15 , V_76 , V_77 , V_79 ) ;
}
V_23 = F_53 ( V_15 -> V_25 , V_76 , V_77 , V_79 ) ;
V_91:
if ( V_23 )
F_17 ( V_15 -> V_18 ,
L_8 ,
V_80 ? L_6 : L_7 , V_23 ) ;
F_10 ( V_77 ) ;
}
static void F_54 ( struct V_14 * V_15 )
{
struct V_92 * V_93 = & V_15 -> V_36 . V_44 ;
F_52 ( V_15 , V_81 ) ;
F_52 ( V_15 , V_94 ) ;
F_55 ( V_15 -> V_25 , 0 ,
V_93 -> V_95 ,
V_93 -> V_96 ) ;
}
static void F_56 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_83 * V_84 ;
int V_24 ;
F_50 (hn, tmp, priv->fs.l2.netdev_uc, i)
F_41 ( V_15 , V_5 ) ;
F_50 (hn, tmp, priv->fs.l2.netdev_mc, i)
F_41 ( V_15 , V_5 ) ;
}
static void F_57 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_83 * V_84 ;
int V_24 ;
F_50 (hn, tmp, priv->fs.l2.netdev_uc, i)
V_5 -> V_9 = V_70 ;
F_50 (hn, tmp, priv->fs.l2.netdev_mc, i)
V_5 -> V_9 = V_70 ;
if ( ! F_58 ( V_97 , & V_15 -> V_98 ) )
F_44 ( V_15 ) ;
F_56 ( V_15 ) ;
}
void F_59 ( struct V_99 * V_100 )
{
struct V_14 * V_15 = F_60 ( V_100 , struct V_14 ,
V_101 ) ;
struct V_92 * V_93 = & V_15 -> V_36 . V_44 ;
struct V_16 * V_17 = V_15 -> V_18 ;
bool V_102 = ! F_58 ( V_97 , & V_15 -> V_98 ) ;
bool V_96 = V_102 && ( V_17 -> V_64 & V_65 ) ;
bool V_95 = V_102 && ( V_17 -> V_64 & V_103 ) ;
bool V_86 = V_102 ;
bool V_104 = ! V_93 -> V_96 && V_96 ;
bool V_105 = V_93 -> V_96 && ! V_96 ;
bool V_106 = ! V_93 -> V_95 && V_95 ;
bool V_107 = V_93 -> V_95 && ! V_95 ;
bool V_108 = ! V_93 -> V_86 && V_86 ;
bool V_109 = V_93 -> V_86 && ! V_86 ;
if ( V_104 ) {
F_42 ( V_15 , & V_93 -> V_110 , V_111 ) ;
if ( ! V_15 -> V_36 . V_22 . V_63 )
F_31 ( V_15 ) ;
}
if ( V_106 )
F_42 ( V_15 , & V_93 -> V_112 , V_113 ) ;
if ( V_108 )
F_42 ( V_15 , & V_93 -> V_87 , V_69 ) ;
F_57 ( V_15 ) ;
if ( V_109 )
F_43 ( V_15 , & V_93 -> V_87 ) ;
if ( V_107 )
F_43 ( V_15 , & V_93 -> V_112 ) ;
if ( V_105 ) {
if ( ! V_15 -> V_36 . V_22 . V_63 )
F_30 ( V_15 ) ;
F_43 ( V_15 , & V_93 -> V_110 ) ;
}
V_93 -> V_96 = V_96 ;
V_93 -> V_95 = V_95 ;
V_93 -> V_86 = V_86 ;
F_54 ( V_15 ) ;
}
static void F_61 ( struct V_114 * V_35 )
{
int V_24 ;
for ( V_24 = V_35 -> V_115 - 1 ; V_24 >= 0 ; V_24 -- ) {
if ( ! F_62 ( V_35 -> V_116 [ V_24 ] ) )
F_63 ( V_35 -> V_116 [ V_24 ] ) ;
V_35 -> V_116 [ V_24 ] = NULL ;
}
V_35 -> V_115 = 0 ;
}
void F_64 ( struct V_14 * V_15 )
{
F_6 ( V_15 -> V_36 . V_44 . V_87 . V_1 , V_15 -> V_18 -> V_87 ) ;
}
void F_65 ( struct V_114 * V_35 )
{
F_61 ( V_35 ) ;
F_10 ( V_35 -> V_116 ) ;
F_66 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
}
static void F_67 ( struct V_117 * V_118 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_119 ; V_24 ++ ) {
if ( ! F_62 ( V_118 -> V_120 [ V_24 ] ) ) {
F_29 ( V_118 -> V_120 [ V_24 ] ) ;
V_118 -> V_120 [ V_24 ] = NULL ;
}
}
}
static struct V_40 *
F_68 ( struct V_14 * V_15 ,
struct V_34 * V_35 ,
struct V_38 * V_39 ,
T_2 V_121 ,
T_1 V_67 )
{
F_19 ( V_42 ) ;
struct V_40 * V_122 ;
struct V_32 * V_33 ;
int V_23 = 0 ;
V_33 = F_26 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_61 ) ;
return F_69 ( - V_28 ) ;
}
if ( V_67 ) {
V_33 -> V_45 = V_46 ;
F_20 ( V_49 , V_33 -> V_50 , V_51 . V_123 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_51 . V_123 , V_67 ) ;
}
if ( V_121 ) {
V_33 -> V_45 = V_46 ;
F_20 ( V_49 , V_33 -> V_50 , V_51 . V_124 ) ;
F_21 ( V_49 , V_33 -> V_55 , V_51 . V_124 , V_121 ) ;
}
V_122 = F_22 ( V_35 , V_33 , & V_42 , V_39 , 1 ) ;
if ( F_23 ( V_122 ) ) {
V_23 = F_24 ( V_122 ) ;
F_17 ( V_15 -> V_18 , L_3 , V_61 ) ;
}
F_27 ( V_33 ) ;
return V_23 ? F_69 ( V_23 ) : V_122 ;
}
static int F_70 ( struct V_14 * V_15 )
{
struct V_38 V_39 ;
struct V_117 * V_118 ;
struct V_40 * * V_120 ;
struct V_34 * V_35 ;
int V_125 ;
int V_23 ;
V_118 = & V_15 -> V_36 . V_118 ;
V_35 = V_118 -> V_35 . V_37 ;
V_120 = V_118 -> V_120 ;
V_39 . type = V_126 ;
for ( V_125 = 0 ; V_125 < V_119 ; V_125 ++ ) {
if ( V_125 == V_127 )
V_39 . V_128 = V_15 -> V_129 [ 0 ] . V_130 ;
else
V_39 . V_128 = V_15 -> V_131 [ V_125 ] . V_130 ;
V_120 [ V_125 ] = F_68 ( V_15 , V_35 , & V_39 ,
V_132 [ V_125 ] . V_121 ,
V_132 [ V_125 ] . V_67 ) ;
if ( F_23 ( V_120 [ V_125 ] ) )
goto V_133;
}
return 0 ;
V_133:
V_23 = F_24 ( V_120 [ V_125 ] ) ;
V_120 [ V_125 ] = NULL ;
F_67 ( V_118 ) ;
return V_23 ;
}
static int F_71 ( struct V_117 * V_118 )
{
int V_134 = F_72 ( V_135 ) ;
struct V_114 * V_35 = & V_118 -> V_35 ;
int V_6 = 0 ;
T_5 * V_136 ;
int V_23 ;
T_1 * V_137 ;
V_35 -> V_116 = F_15 ( V_138 ,
sizeof( * V_35 -> V_116 ) , V_27 ) ;
if ( ! V_35 -> V_116 )
return - V_28 ;
V_136 = F_26 ( V_134 ) ;
if ( ! V_136 ) {
F_10 ( V_35 -> V_116 ) ;
return - V_28 ;
}
V_137 = F_73 ( V_135 , V_136 , V_50 ) ;
F_20 ( V_49 , V_137 , V_51 . V_123 ) ;
F_20 ( V_49 , V_137 , V_51 . V_124 ) ;
F_74 ( V_136 , V_45 , V_46 ) ;
F_74 ( V_136 , V_139 , V_6 ) ;
V_6 += V_140 ;
F_74 ( V_136 , V_141 , V_6 - 1 ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = F_75 ( V_35 -> V_37 , V_136 ) ;
if ( F_23 ( V_35 -> V_116 [ V_35 -> V_115 ] ) )
goto V_23;
V_35 -> V_115 ++ ;
F_21 ( V_49 , V_137 , V_51 . V_123 , 0 ) ;
F_74 ( V_136 , V_139 , V_6 ) ;
V_6 += V_142 ;
F_74 ( V_136 , V_141 , V_6 - 1 ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = F_75 ( V_35 -> V_37 , V_136 ) ;
if ( F_23 ( V_35 -> V_116 [ V_35 -> V_115 ] ) )
goto V_23;
V_35 -> V_115 ++ ;
memset ( V_136 , 0 , V_134 ) ;
F_74 ( V_136 , V_139 , V_6 ) ;
V_6 += V_143 ;
F_74 ( V_136 , V_141 , V_6 - 1 ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = F_75 ( V_35 -> V_37 , V_136 ) ;
if ( F_23 ( V_35 -> V_116 [ V_35 -> V_115 ] ) )
goto V_23;
V_35 -> V_115 ++ ;
F_27 ( V_136 ) ;
return 0 ;
V_23:
V_23 = F_24 ( V_35 -> V_116 [ V_35 -> V_115 ] ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = NULL ;
F_27 ( V_136 ) ;
return V_23 ;
}
void F_76 ( struct V_14 * V_15 )
{
struct V_117 * V_118 = & V_15 -> V_36 . V_118 ;
F_67 ( V_118 ) ;
F_65 ( & V_118 -> V_35 ) ;
}
int F_77 ( struct V_14 * V_15 )
{
struct V_117 * V_118 = & V_15 -> V_36 . V_118 ;
struct V_144 V_145 = {} ;
struct V_114 * V_35 = & V_118 -> V_35 ;
int V_23 ;
V_145 . V_146 = V_147 ;
V_145 . V_148 = V_149 ;
V_145 . V_150 = V_151 ;
V_35 -> V_37 = F_78 ( V_15 -> V_36 . V_152 , & V_145 ) ;
if ( F_23 ( V_35 -> V_37 ) ) {
V_23 = F_24 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_23 = F_71 ( V_118 ) ;
if ( V_23 )
goto V_23;
V_23 = F_70 ( V_15 ) ;
if ( V_23 )
goto V_23;
return 0 ;
V_23:
F_65 ( V_35 ) ;
return V_23 ;
}
static void F_43 ( struct V_14 * V_15 ,
struct V_153 * V_8 )
{
if ( ! F_62 ( V_8 -> V_122 ) ) {
F_29 ( V_8 -> V_122 ) ;
V_8 -> V_122 = NULL ;
}
}
static int F_42 ( struct V_14 * V_15 ,
struct V_153 * V_8 , int type )
{
struct V_34 * V_35 = V_15 -> V_36 . V_44 . V_35 . V_37 ;
struct V_38 V_39 ;
F_19 ( V_42 ) ;
struct V_32 * V_33 ;
int V_23 = 0 ;
T_1 * V_154 ;
T_1 * V_155 ;
V_33 = F_26 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_61 ) ;
return - V_28 ;
}
V_154 = F_73 ( V_49 , V_33 -> V_50 ,
V_51 . V_156 ) ;
V_155 = F_73 ( V_49 , V_33 -> V_55 ,
V_51 . V_156 ) ;
V_39 . type = V_43 ;
V_39 . V_35 = V_15 -> V_36 . V_118 . V_35 . V_37 ;
switch ( type ) {
case V_69 :
V_33 -> V_45 = V_46 ;
F_79 ( V_154 ) ;
F_6 ( V_155 , V_8 -> V_1 ) ;
break;
case V_113 :
V_33 -> V_45 = V_46 ;
V_154 [ 0 ] = 0x01 ;
V_155 [ 0 ] = 0x01 ;
break;
case V_111 :
break;
}
V_8 -> V_122 = F_22 ( V_35 , V_33 , & V_42 , & V_39 , 1 ) ;
if ( F_23 ( V_8 -> V_122 ) ) {
F_17 ( V_15 -> V_18 , L_9 ,
V_61 , V_155 ) ;
V_23 = F_24 ( V_8 -> V_122 ) ;
V_8 -> V_122 = NULL ;
}
F_27 ( V_33 ) ;
return V_23 ;
}
static int F_80 ( struct V_92 * V_157 )
{
int V_134 = F_72 ( V_135 ) ;
struct V_114 * V_35 = & V_157 -> V_35 ;
int V_6 = 0 ;
T_1 * V_154 ;
T_5 * V_136 ;
int V_23 ;
T_1 * V_137 ;
V_35 -> V_116 = F_15 ( V_158 , sizeof( * V_35 -> V_116 ) , V_27 ) ;
if ( ! V_35 -> V_116 )
return - V_28 ;
V_136 = F_26 ( V_134 ) ;
if ( ! V_136 ) {
F_10 ( V_35 -> V_116 ) ;
return - V_28 ;
}
V_137 = F_73 ( V_135 , V_136 , V_50 ) ;
V_154 = F_73 ( V_49 , V_137 ,
V_51 . V_156 ) ;
F_74 ( V_136 , V_139 , V_6 ) ;
V_6 += V_159 ;
F_74 ( V_136 , V_141 , V_6 - 1 ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = F_75 ( V_35 -> V_37 , V_136 ) ;
if ( F_23 ( V_35 -> V_116 [ V_35 -> V_115 ] ) )
goto V_160;
V_35 -> V_115 ++ ;
F_79 ( V_154 ) ;
F_74 ( V_136 , V_45 , V_46 ) ;
F_74 ( V_136 , V_139 , V_6 ) ;
V_6 += V_161 ;
F_74 ( V_136 , V_141 , V_6 - 1 ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = F_75 ( V_35 -> V_37 , V_136 ) ;
if ( F_23 ( V_35 -> V_116 [ V_35 -> V_115 ] ) )
goto V_160;
V_35 -> V_115 ++ ;
F_81 ( V_154 ) ;
V_154 [ 0 ] = 0x01 ;
F_74 ( V_136 , V_139 , V_6 ) ;
V_6 += V_162 ;
F_74 ( V_136 , V_141 , V_6 - 1 ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = F_75 ( V_35 -> V_37 , V_136 ) ;
if ( F_23 ( V_35 -> V_116 [ V_35 -> V_115 ] ) )
goto V_160;
V_35 -> V_115 ++ ;
F_27 ( V_136 ) ;
return 0 ;
V_160:
V_23 = F_24 ( V_35 -> V_116 [ V_35 -> V_115 ] ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = NULL ;
F_61 ( V_35 ) ;
F_27 ( V_136 ) ;
return V_23 ;
}
static void F_82 ( struct V_14 * V_15 )
{
F_65 ( & V_15 -> V_36 . V_44 . V_35 ) ;
}
static int F_83 ( struct V_14 * V_15 )
{
struct V_92 * V_157 = & V_15 -> V_36 . V_44 ;
struct V_114 * V_35 = & V_157 -> V_35 ;
struct V_144 V_145 = {} ;
int V_23 ;
V_35 -> V_115 = 0 ;
V_145 . V_146 = V_163 ;
V_145 . V_148 = V_164 ;
V_145 . V_150 = V_151 ;
V_35 -> V_37 = F_78 ( V_15 -> V_36 . V_152 , & V_145 ) ;
if ( F_23 ( V_35 -> V_37 ) ) {
V_23 = F_24 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_23 = F_80 ( V_157 ) ;
if ( V_23 )
goto V_165;
return 0 ;
V_165:
F_66 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
static int F_84 ( struct V_114 * V_35 , T_5 * V_136 ,
int V_134 )
{
int V_23 ;
int V_6 = 0 ;
T_1 * V_137 = F_73 ( V_135 , V_136 , V_50 ) ;
memset ( V_136 , 0 , V_134 ) ;
F_74 ( V_136 , V_45 , V_46 ) ;
F_20 ( V_49 , V_137 , V_51 . V_52 ) ;
F_20 ( V_49 , V_137 , V_51 . V_60 ) ;
F_74 ( V_136 , V_139 , V_6 ) ;
V_6 += V_166 ;
F_74 ( V_136 , V_141 , V_6 - 1 ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = F_75 ( V_35 -> V_37 , V_136 ) ;
if ( F_23 ( V_35 -> V_116 [ V_35 -> V_115 ] ) )
goto V_160;
V_35 -> V_115 ++ ;
memset ( V_136 , 0 , V_134 ) ;
F_74 ( V_136 , V_45 , V_46 ) ;
F_20 ( V_49 , V_137 , V_51 . V_52 ) ;
F_74 ( V_136 , V_139 , V_6 ) ;
V_6 += V_167 ;
F_74 ( V_136 , V_141 , V_6 - 1 ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = F_75 ( V_35 -> V_37 , V_136 ) ;
if ( F_23 ( V_35 -> V_116 [ V_35 -> V_115 ] ) )
goto V_160;
V_35 -> V_115 ++ ;
memset ( V_136 , 0 , V_134 ) ;
F_74 ( V_136 , V_45 , V_46 ) ;
F_20 ( V_49 , V_137 , V_51 . V_58 ) ;
F_74 ( V_136 , V_139 , V_6 ) ;
V_6 += V_168 ;
F_74 ( V_136 , V_141 , V_6 - 1 ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = F_75 ( V_35 -> V_37 , V_136 ) ;
if ( F_23 ( V_35 -> V_116 [ V_35 -> V_115 ] ) )
goto V_160;
V_35 -> V_115 ++ ;
return 0 ;
V_160:
V_23 = F_24 ( V_35 -> V_116 [ V_35 -> V_115 ] ) ;
V_35 -> V_116 [ V_35 -> V_115 ] = NULL ;
F_61 ( V_35 ) ;
return V_23 ;
}
static int F_85 ( struct V_114 * V_35 )
{
T_5 * V_136 ;
int V_134 = F_72 ( V_135 ) ;
int V_23 ;
V_136 = F_26 ( V_134 ) ;
if ( ! V_136 )
return - V_28 ;
V_23 = F_84 ( V_35 , V_136 , V_134 ) ;
F_27 ( V_136 ) ;
return V_23 ;
}
static int F_86 ( struct V_14 * V_15 )
{
struct V_114 * V_35 = & V_15 -> V_36 . V_22 . V_35 ;
struct V_144 V_145 = {} ;
int V_23 ;
V_35 -> V_115 = 0 ;
V_145 . V_146 = V_169 ;
V_145 . V_148 = V_170 ;
V_145 . V_150 = V_151 ;
V_35 -> V_37 = F_78 ( V_15 -> V_36 . V_152 , & V_145 ) ;
if ( F_23 ( V_35 -> V_37 ) ) {
V_23 = F_24 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_35 -> V_116 = F_15 ( V_171 , sizeof( * V_35 -> V_116 ) , V_27 ) ;
if ( ! V_35 -> V_116 ) {
V_23 = - V_28 ;
goto V_172;
}
V_23 = F_85 ( V_35 ) ;
if ( V_23 )
goto V_173;
F_39 ( V_15 ) ;
return 0 ;
V_173:
F_10 ( V_35 -> V_116 ) ;
V_172:
F_66 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
static void F_87 ( struct V_14 * V_15 )
{
F_40 ( V_15 ) ;
F_65 ( & V_15 -> V_36 . V_22 . V_35 ) ;
}
int F_88 ( struct V_14 * V_15 )
{
int V_23 ;
V_15 -> V_36 . V_152 = F_89 ( V_15 -> V_25 ,
V_174 ) ;
if ( ! V_15 -> V_36 . V_152 )
return - V_175 ;
V_23 = F_90 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_10 ,
V_23 ) ;
V_15 -> V_18 -> V_176 &= ~ V_177 ;
}
V_23 = F_77 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_11 ,
V_23 ) ;
goto V_178;
}
V_23 = F_83 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_12 ,
V_23 ) ;
goto V_179;
}
V_23 = F_86 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_13 ,
V_23 ) ;
goto V_180;
}
F_91 ( V_15 ) ;
return 0 ;
V_180:
F_82 ( V_15 ) ;
V_179:
F_76 ( V_15 ) ;
V_178:
F_92 ( V_15 ) ;
return V_23 ;
}
void F_93 ( struct V_14 * V_15 )
{
F_87 ( V_15 ) ;
F_82 ( V_15 ) ;
F_76 ( V_15 ) ;
F_92 ( V_15 ) ;
F_94 ( V_15 ) ;
}
