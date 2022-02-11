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
int V_23 = 0 ;
V_39 . type = V_42 ;
V_39 . V_35 = V_15 -> V_36 . V_43 . V_35 . V_37 ;
V_33 -> V_44 = V_45 ;
F_19 ( V_46 , V_33 -> V_47 , V_48 . V_49 ) ;
switch ( V_30 ) {
case V_50 :
V_41 = & V_15 -> V_36 . V_22 . V_51 ;
break;
case V_52 :
V_41 = & V_15 -> V_36 . V_22 . V_53 ;
F_20 ( V_46 , V_33 -> V_54 , V_48 . V_49 , 1 ) ;
break;
default:
V_41 = & V_15 -> V_36 . V_22 . V_55 [ V_31 ] ;
F_20 ( V_46 , V_33 -> V_54 , V_48 . V_49 , 1 ) ;
F_19 ( V_46 , V_33 -> V_47 ,
V_48 . V_56 ) ;
F_20 ( V_46 , V_33 -> V_54 , V_48 . V_56 ,
V_31 ) ;
break;
}
* V_41 = F_21 ( V_35 , V_33 ,
V_57 ,
V_58 ,
& V_39 ) ;
if ( F_22 ( * V_41 ) ) {
V_23 = F_23 ( * V_41 ) ;
* V_41 = NULL ;
F_17 ( V_15 -> V_18 , L_3 , V_59 ) ;
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
F_17 ( V_15 -> V_18 , L_4 , V_59 ) ;
return - V_28 ;
}
if ( V_30 == V_60 )
F_11 ( V_15 ) ;
V_23 = F_18 ( V_15 , V_30 , V_31 , V_33 ) ;
F_26 ( V_33 ) ;
return V_23 ;
}
static void F_27 ( struct V_14 * V_15 ,
enum V_29 V_30 , T_2 V_31 )
{
switch ( V_30 ) {
case V_50 :
if ( V_15 -> V_36 . V_22 . V_51 ) {
F_28 ( V_15 -> V_36 . V_22 . V_51 ) ;
V_15 -> V_36 . V_22 . V_51 = NULL ;
}
break;
case V_52 :
if ( V_15 -> V_36 . V_22 . V_53 ) {
F_28 ( V_15 -> V_36 . V_22 . V_53 ) ;
V_15 -> V_36 . V_22 . V_53 = NULL ;
}
break;
case V_60 :
F_11 ( V_15 ) ;
if ( V_15 -> V_36 . V_22 . V_55 [ V_31 ] ) {
F_28 ( V_15 -> V_36 . V_22 . V_55 [ V_31 ] ) ;
V_15 -> V_36 . V_22 . V_55 [ V_31 ] = NULL ;
}
F_11 ( V_15 ) ;
break;
}
}
void F_29 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_36 . V_22 . V_61 )
return;
V_15 -> V_36 . V_22 . V_61 = false ;
if ( V_15 -> V_18 -> V_62 & V_63 )
return;
F_27 ( V_15 , V_52 , 0 ) ;
}
void F_30 ( struct V_14 * V_15 )
{
if ( V_15 -> V_36 . V_22 . V_61 )
return;
V_15 -> V_36 . V_22 . V_61 = true ;
if ( V_15 -> V_18 -> V_62 & V_63 )
return;
F_24 ( V_15 , V_52 , 0 ) ;
}
int F_31 ( struct V_16 * V_64 , T_3 T_4 V_65 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_32 ( V_64 ) ;
F_33 ( V_31 , V_15 -> V_36 . V_22 . V_66 ) ;
return F_24 ( V_15 , V_60 , V_31 ) ;
}
int F_34 ( struct V_16 * V_64 , T_3 T_4 V_65 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_32 ( V_64 ) ;
F_35 ( V_31 , V_15 -> V_36 . V_22 . V_66 ) ;
F_27 ( V_15 , V_60 , V_31 ) ;
return 0 ;
}
static void F_36 ( struct V_14 * V_15 )
{
int V_24 ;
F_24 ( V_15 , V_50 , 0 ) ;
F_12 (i, priv->fs.vlan.active_vlans, VLAN_N_VID) {
F_24 ( V_15 , V_60 , V_24 ) ;
}
if ( V_15 -> V_36 . V_22 . V_61 &&
! ( V_15 -> V_18 -> V_62 & V_63 ) )
F_24 ( V_15 , V_52 , 0 ) ;
}
static void F_37 ( struct V_14 * V_15 )
{
int V_24 ;
F_27 ( V_15 , V_50 , 0 ) ;
F_12 (i, priv->fs.vlan.active_vlans, VLAN_N_VID) {
F_27 ( V_15 , V_60 , V_24 ) ;
}
if ( V_15 -> V_36 . V_22 . V_61 &&
! ( V_15 -> V_18 -> V_62 & V_63 ) )
F_27 ( V_15 , V_52 , 0 ) ;
}
static void F_38 ( struct V_14 * V_15 ,
struct V_4 * V_5 )
{
switch ( V_5 -> V_9 ) {
case V_12 :
F_39 ( V_15 , & V_5 -> V_8 , V_67 ) ;
V_5 -> V_9 = V_10 ;
break;
case V_68 :
F_40 ( V_15 , & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
break;
}
}
static void F_41 ( struct V_14 * V_15 )
{
struct V_16 * V_18 = V_15 -> V_18 ;
struct V_69 * V_70 ;
F_42 ( V_18 ) ;
F_2 ( V_15 -> V_36 . V_43 . V_71 ,
V_15 -> V_18 -> V_72 ) ;
F_43 (ha, netdev)
F_2 ( V_15 -> V_36 . V_43 . V_71 , V_70 -> V_1 ) ;
F_44 (ha, netdev)
F_2 ( V_15 -> V_36 . V_43 . V_73 , V_70 -> V_1 ) ;
F_45 ( V_18 ) ;
}
static void F_46 ( struct V_14 * V_15 , int V_74 ,
T_1 V_75 [] [ V_76 ] , int V_77 )
{
bool V_78 = ( V_74 == V_79 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_4 * V_5 ;
struct V_2 * V_80 ;
struct V_81 * V_82 ;
int V_24 = 0 ;
int V_83 ;
V_80 = V_78 ? V_15 -> V_36 . V_43 . V_71 : V_15 -> V_36 . V_43 . V_73 ;
if ( V_78 )
F_6 ( V_75 [ V_24 ++ ] , V_17 -> V_72 ) ;
else if ( V_15 -> V_36 . V_43 . V_84 )
F_6 ( V_75 [ V_24 ++ ] , V_17 -> V_85 ) ;
F_47 (hn, tmp, addr_list, hi) {
if ( F_48 ( V_17 -> V_72 , V_5 -> V_8 . V_1 ) )
continue;
if ( V_24 >= V_77 )
break;
F_6 ( V_75 [ V_24 ++ ] , V_5 -> V_8 . V_1 ) ;
}
}
static void F_49 ( struct V_14 * V_15 ,
int V_74 )
{
bool V_78 = ( V_74 == V_79 ) ;
struct V_4 * V_5 ;
T_1 ( * V_75 ) [ V_76 ] = NULL ;
struct V_2 * V_80 ;
struct V_81 * V_82 ;
int V_86 ;
int V_77 ;
int V_23 ;
int V_83 ;
V_77 = V_78 ? 0 : ( V_15 -> V_36 . V_43 . V_84 ? 1 : 0 ) ;
V_86 = V_78 ?
1 << F_13 ( V_15 -> V_25 , V_87 ) :
1 << F_13 ( V_15 -> V_25 , V_88 ) ;
V_80 = V_78 ? V_15 -> V_36 . V_43 . V_71 : V_15 -> V_36 . V_43 . V_73 ;
F_47 (hn, tmp, addr_list, hi)
V_77 ++ ;
if ( V_77 > V_86 ) {
F_14 ( V_15 -> V_18 ,
L_5 ,
V_78 ? L_6 : L_7 , V_77 , V_86 ) ;
V_77 = V_86 ;
}
if ( V_77 ) {
V_75 = F_15 ( V_77 , V_76 , V_27 ) ;
if ( ! V_75 ) {
V_23 = - V_28 ;
goto V_89;
}
F_46 ( V_15 , V_74 , V_75 , V_77 ) ;
}
V_23 = F_50 ( V_15 -> V_25 , V_74 , V_75 , V_77 ) ;
V_89:
if ( V_23 )
F_17 ( V_15 -> V_18 ,
L_8 ,
V_78 ? L_6 : L_7 , V_23 ) ;
F_10 ( V_75 ) ;
}
static void F_51 ( struct V_14 * V_15 )
{
struct V_90 * V_91 = & V_15 -> V_36 . V_43 ;
F_49 ( V_15 , V_79 ) ;
F_49 ( V_15 , V_92 ) ;
F_52 ( V_15 -> V_25 , 0 ,
V_91 -> V_93 ,
V_91 -> V_94 ) ;
}
static void F_53 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_81 * V_82 ;
int V_24 ;
F_47 (hn, tmp, priv->fs.l2.netdev_uc, i)
F_38 ( V_15 , V_5 ) ;
F_47 (hn, tmp, priv->fs.l2.netdev_mc, i)
F_38 ( V_15 , V_5 ) ;
}
static void F_54 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_81 * V_82 ;
int V_24 ;
F_47 (hn, tmp, priv->fs.l2.netdev_uc, i)
V_5 -> V_9 = V_68 ;
F_47 (hn, tmp, priv->fs.l2.netdev_mc, i)
V_5 -> V_9 = V_68 ;
if ( ! F_55 ( V_95 , & V_15 -> V_96 ) )
F_41 ( V_15 ) ;
F_53 ( V_15 ) ;
}
void F_56 ( struct V_97 * V_98 )
{
struct V_14 * V_15 = F_57 ( V_98 , struct V_14 ,
V_99 ) ;
struct V_90 * V_91 = & V_15 -> V_36 . V_43 ;
struct V_16 * V_17 = V_15 -> V_18 ;
bool V_100 = ! F_55 ( V_95 , & V_15 -> V_96 ) ;
bool V_94 = V_100 && ( V_17 -> V_62 & V_63 ) ;
bool V_93 = V_100 && ( V_17 -> V_62 & V_101 ) ;
bool V_84 = V_100 ;
bool V_102 = ! V_91 -> V_94 && V_94 ;
bool V_103 = V_91 -> V_94 && ! V_94 ;
bool V_104 = ! V_91 -> V_93 && V_93 ;
bool V_105 = V_91 -> V_93 && ! V_93 ;
bool V_106 = ! V_91 -> V_84 && V_84 ;
bool V_107 = V_91 -> V_84 && ! V_84 ;
if ( V_102 ) {
F_39 ( V_15 , & V_91 -> V_108 , V_109 ) ;
if ( ! V_15 -> V_36 . V_22 . V_61 )
F_24 ( V_15 , V_52 ,
0 ) ;
}
if ( V_104 )
F_39 ( V_15 , & V_91 -> V_110 , V_111 ) ;
if ( V_106 )
F_39 ( V_15 , & V_91 -> V_85 , V_67 ) ;
F_54 ( V_15 ) ;
if ( V_107 )
F_40 ( V_15 , & V_91 -> V_85 ) ;
if ( V_105 )
F_40 ( V_15 , & V_91 -> V_110 ) ;
if ( V_103 ) {
if ( ! V_15 -> V_36 . V_22 . V_61 )
F_27 ( V_15 , V_52 ,
0 ) ;
F_40 ( V_15 , & V_91 -> V_108 ) ;
}
V_91 -> V_94 = V_94 ;
V_91 -> V_93 = V_93 ;
V_91 -> V_84 = V_84 ;
F_51 ( V_15 ) ;
}
static void F_58 ( struct V_112 * V_35 )
{
int V_24 ;
for ( V_24 = V_35 -> V_113 - 1 ; V_24 >= 0 ; V_24 -- ) {
if ( ! F_59 ( V_35 -> V_114 [ V_24 ] ) )
F_60 ( V_35 -> V_114 [ V_24 ] ) ;
V_35 -> V_114 [ V_24 ] = NULL ;
}
V_35 -> V_113 = 0 ;
}
void F_61 ( struct V_14 * V_15 )
{
F_6 ( V_15 -> V_36 . V_43 . V_85 . V_1 , V_15 -> V_18 -> V_85 ) ;
}
void F_62 ( struct V_112 * V_35 )
{
F_58 ( V_35 ) ;
F_10 ( V_35 -> V_114 ) ;
F_63 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
}
static void F_64 ( struct V_115 * V_116 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_117 ; V_24 ++ ) {
if ( ! F_59 ( V_116 -> V_118 [ V_24 ] ) ) {
F_28 ( V_116 -> V_118 [ V_24 ] ) ;
V_116 -> V_118 [ V_24 ] = NULL ;
}
}
}
static struct V_40 * F_65 ( struct V_14 * V_15 ,
struct V_34 * V_35 ,
struct V_38 * V_39 ,
T_2 V_119 ,
T_1 V_65 )
{
struct V_40 * V_120 ;
struct V_32 * V_33 ;
int V_23 = 0 ;
V_33 = F_25 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_59 ) ;
return F_66 ( - V_28 ) ;
}
if ( V_65 ) {
V_33 -> V_44 = V_45 ;
F_19 ( V_46 , V_33 -> V_47 , V_48 . V_121 ) ;
F_20 ( V_46 , V_33 -> V_54 , V_48 . V_121 , V_65 ) ;
}
if ( V_119 ) {
V_33 -> V_44 = V_45 ;
F_19 ( V_46 , V_33 -> V_47 , V_48 . V_122 ) ;
F_20 ( V_46 , V_33 -> V_54 , V_48 . V_122 , V_119 ) ;
}
V_120 = F_21 ( V_35 , V_33 ,
V_57 ,
V_58 ,
V_39 ) ;
if ( F_22 ( V_120 ) ) {
V_23 = F_23 ( V_120 ) ;
F_17 ( V_15 -> V_18 , L_3 , V_59 ) ;
}
F_26 ( V_33 ) ;
return V_23 ? F_66 ( V_23 ) : V_120 ;
}
static int F_67 ( struct V_14 * V_15 )
{
struct V_38 V_39 ;
struct V_115 * V_116 ;
struct V_40 * * V_118 ;
struct V_34 * V_35 ;
int V_123 ;
int V_23 ;
V_116 = & V_15 -> V_36 . V_116 ;
V_35 = V_116 -> V_35 . V_37 ;
V_118 = V_116 -> V_118 ;
V_39 . type = V_124 ;
for ( V_123 = 0 ; V_123 < V_117 ; V_123 ++ ) {
if ( V_123 == V_125 )
V_39 . V_126 = V_15 -> V_127 [ 0 ] . V_128 ;
else
V_39 . V_126 = V_15 -> V_129 [ V_123 ] . V_128 ;
V_118 [ V_123 ] = F_65 ( V_15 , V_35 , & V_39 ,
V_130 [ V_123 ] . V_119 ,
V_130 [ V_123 ] . V_65 ) ;
if ( F_22 ( V_118 [ V_123 ] ) )
goto V_131;
}
return 0 ;
V_131:
V_23 = F_23 ( V_118 [ V_123 ] ) ;
V_118 [ V_123 ] = NULL ;
F_64 ( V_116 ) ;
return V_23 ;
}
static int F_68 ( struct V_115 * V_116 )
{
int V_132 = F_69 ( V_133 ) ;
struct V_112 * V_35 = & V_116 -> V_35 ;
int V_6 = 0 ;
T_5 * V_134 ;
int V_23 ;
T_1 * V_135 ;
V_35 -> V_114 = F_15 ( V_136 ,
sizeof( * V_35 -> V_114 ) , V_27 ) ;
if ( ! V_35 -> V_114 )
return - V_28 ;
V_134 = F_25 ( V_132 ) ;
if ( ! V_134 ) {
F_10 ( V_35 -> V_114 ) ;
return - V_28 ;
}
V_135 = F_70 ( V_133 , V_134 , V_47 ) ;
F_19 ( V_46 , V_135 , V_48 . V_121 ) ;
F_19 ( V_46 , V_135 , V_48 . V_122 ) ;
F_71 ( V_134 , V_44 , V_45 ) ;
F_71 ( V_134 , V_137 , V_6 ) ;
V_6 += V_138 ;
F_71 ( V_134 , V_139 , V_6 - 1 ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = F_72 ( V_35 -> V_37 , V_134 ) ;
if ( F_22 ( V_35 -> V_114 [ V_35 -> V_113 ] ) )
goto V_23;
V_35 -> V_113 ++ ;
F_20 ( V_46 , V_135 , V_48 . V_121 , 0 ) ;
F_71 ( V_134 , V_137 , V_6 ) ;
V_6 += V_140 ;
F_71 ( V_134 , V_139 , V_6 - 1 ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = F_72 ( V_35 -> V_37 , V_134 ) ;
if ( F_22 ( V_35 -> V_114 [ V_35 -> V_113 ] ) )
goto V_23;
V_35 -> V_113 ++ ;
memset ( V_134 , 0 , V_132 ) ;
F_71 ( V_134 , V_137 , V_6 ) ;
V_6 += V_141 ;
F_71 ( V_134 , V_139 , V_6 - 1 ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = F_72 ( V_35 -> V_37 , V_134 ) ;
if ( F_22 ( V_35 -> V_114 [ V_35 -> V_113 ] ) )
goto V_23;
V_35 -> V_113 ++ ;
F_26 ( V_134 ) ;
return 0 ;
V_23:
V_23 = F_23 ( V_35 -> V_114 [ V_35 -> V_113 ] ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = NULL ;
F_26 ( V_134 ) ;
return V_23 ;
}
static void F_73 ( struct V_14 * V_15 )
{
struct V_115 * V_116 = & V_15 -> V_36 . V_116 ;
F_64 ( V_116 ) ;
F_62 ( & V_116 -> V_35 ) ;
}
static int F_74 ( struct V_14 * V_15 )
{
struct V_115 * V_116 = & V_15 -> V_36 . V_116 ;
struct V_112 * V_35 = & V_116 -> V_35 ;
int V_23 ;
V_35 -> V_37 = F_75 ( V_15 -> V_36 . V_142 , V_143 ,
V_144 , V_145 ) ;
if ( F_22 ( V_35 -> V_37 ) ) {
V_23 = F_23 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_23 = F_68 ( V_116 ) ;
if ( V_23 )
goto V_23;
V_23 = F_67 ( V_15 ) ;
if ( V_23 )
goto V_23;
return 0 ;
V_23:
F_62 ( V_35 ) ;
return V_23 ;
}
static void F_40 ( struct V_14 * V_15 ,
struct V_146 * V_8 )
{
if ( ! F_59 ( V_8 -> V_120 ) ) {
F_28 ( V_8 -> V_120 ) ;
V_8 -> V_120 = NULL ;
}
}
static int F_39 ( struct V_14 * V_15 ,
struct V_146 * V_8 , int type )
{
struct V_34 * V_35 = V_15 -> V_36 . V_43 . V_35 . V_37 ;
struct V_38 V_39 ;
struct V_32 * V_33 ;
int V_23 = 0 ;
T_1 * V_147 ;
T_1 * V_148 ;
V_33 = F_25 ( sizeof( * V_33 ) ) ;
if ( ! V_33 ) {
F_17 ( V_15 -> V_18 , L_4 , V_59 ) ;
return - V_28 ;
}
V_147 = F_70 ( V_46 , V_33 -> V_47 ,
V_48 . V_149 ) ;
V_148 = F_70 ( V_46 , V_33 -> V_54 ,
V_48 . V_149 ) ;
V_39 . type = V_42 ;
V_39 . V_35 = V_15 -> V_36 . V_116 . V_35 . V_37 ;
switch ( type ) {
case V_67 :
V_33 -> V_44 = V_45 ;
F_76 ( V_147 ) ;
F_6 ( V_148 , V_8 -> V_1 ) ;
break;
case V_111 :
V_33 -> V_44 = V_45 ;
V_147 [ 0 ] = 0x01 ;
V_148 [ 0 ] = 0x01 ;
break;
case V_109 :
break;
}
V_8 -> V_120 = F_21 ( V_35 , V_33 ,
V_57 ,
V_58 , & V_39 ) ;
if ( F_22 ( V_8 -> V_120 ) ) {
F_17 ( V_15 -> V_18 , L_9 ,
V_59 , V_148 ) ;
V_23 = F_23 ( V_8 -> V_120 ) ;
V_8 -> V_120 = NULL ;
}
F_26 ( V_33 ) ;
return V_23 ;
}
static int F_77 ( struct V_90 * V_150 )
{
int V_132 = F_69 ( V_133 ) ;
struct V_112 * V_35 = & V_150 -> V_35 ;
int V_6 = 0 ;
T_1 * V_147 ;
T_5 * V_134 ;
int V_23 ;
T_1 * V_135 ;
V_35 -> V_114 = F_15 ( V_151 , sizeof( * V_35 -> V_114 ) , V_27 ) ;
if ( ! V_35 -> V_114 )
return - V_28 ;
V_134 = F_25 ( V_132 ) ;
if ( ! V_134 ) {
F_10 ( V_35 -> V_114 ) ;
return - V_28 ;
}
V_135 = F_70 ( V_133 , V_134 , V_47 ) ;
V_147 = F_70 ( V_46 , V_135 ,
V_48 . V_149 ) ;
F_71 ( V_134 , V_137 , V_6 ) ;
V_6 += V_152 ;
F_71 ( V_134 , V_139 , V_6 - 1 ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = F_72 ( V_35 -> V_37 , V_134 ) ;
if ( F_22 ( V_35 -> V_114 [ V_35 -> V_113 ] ) )
goto V_153;
V_35 -> V_113 ++ ;
F_76 ( V_147 ) ;
F_71 ( V_134 , V_44 , V_45 ) ;
F_71 ( V_134 , V_137 , V_6 ) ;
V_6 += V_154 ;
F_71 ( V_134 , V_139 , V_6 - 1 ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = F_72 ( V_35 -> V_37 , V_134 ) ;
if ( F_22 ( V_35 -> V_114 [ V_35 -> V_113 ] ) )
goto V_153;
V_35 -> V_113 ++ ;
F_78 ( V_147 ) ;
V_147 [ 0 ] = 0x01 ;
F_71 ( V_134 , V_137 , V_6 ) ;
V_6 += V_155 ;
F_71 ( V_134 , V_139 , V_6 - 1 ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = F_72 ( V_35 -> V_37 , V_134 ) ;
if ( F_22 ( V_35 -> V_114 [ V_35 -> V_113 ] ) )
goto V_153;
V_35 -> V_113 ++ ;
F_26 ( V_134 ) ;
return 0 ;
V_153:
V_23 = F_23 ( V_35 -> V_114 [ V_35 -> V_113 ] ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = NULL ;
F_58 ( V_35 ) ;
F_26 ( V_134 ) ;
return V_23 ;
}
static void F_79 ( struct V_14 * V_15 )
{
F_62 ( & V_15 -> V_36 . V_43 . V_35 ) ;
}
static int F_80 ( struct V_14 * V_15 )
{
struct V_90 * V_150 = & V_15 -> V_36 . V_43 ;
struct V_112 * V_35 = & V_150 -> V_35 ;
int V_23 ;
V_35 -> V_113 = 0 ;
V_35 -> V_37 = F_75 ( V_15 -> V_36 . V_142 , V_143 ,
V_156 , V_157 ) ;
if ( F_22 ( V_35 -> V_37 ) ) {
V_23 = F_23 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_23 = F_77 ( V_150 ) ;
if ( V_23 )
goto V_158;
return 0 ;
V_158:
F_63 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
static int F_81 ( struct V_112 * V_35 , T_5 * V_134 ,
int V_132 )
{
int V_23 ;
int V_6 = 0 ;
T_1 * V_135 = F_70 ( V_133 , V_134 , V_47 ) ;
memset ( V_134 , 0 , V_132 ) ;
F_71 ( V_134 , V_44 , V_45 ) ;
F_19 ( V_46 , V_135 , V_48 . V_49 ) ;
F_19 ( V_46 , V_135 , V_48 . V_56 ) ;
F_71 ( V_134 , V_137 , V_6 ) ;
V_6 += V_159 ;
F_71 ( V_134 , V_139 , V_6 - 1 ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = F_72 ( V_35 -> V_37 , V_134 ) ;
if ( F_22 ( V_35 -> V_114 [ V_35 -> V_113 ] ) )
goto V_153;
V_35 -> V_113 ++ ;
memset ( V_134 , 0 , V_132 ) ;
F_71 ( V_134 , V_44 , V_45 ) ;
F_19 ( V_46 , V_135 , V_48 . V_49 ) ;
F_71 ( V_134 , V_137 , V_6 ) ;
V_6 += V_160 ;
F_71 ( V_134 , V_139 , V_6 - 1 ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = F_72 ( V_35 -> V_37 , V_134 ) ;
if ( F_22 ( V_35 -> V_114 [ V_35 -> V_113 ] ) )
goto V_153;
V_35 -> V_113 ++ ;
return 0 ;
V_153:
V_23 = F_23 ( V_35 -> V_114 [ V_35 -> V_113 ] ) ;
V_35 -> V_114 [ V_35 -> V_113 ] = NULL ;
F_58 ( V_35 ) ;
return V_23 ;
}
static int F_82 ( struct V_112 * V_35 )
{
T_5 * V_134 ;
int V_132 = F_69 ( V_133 ) ;
int V_23 ;
V_134 = F_25 ( V_132 ) ;
if ( ! V_134 )
return - V_28 ;
V_23 = F_81 ( V_35 , V_134 , V_132 ) ;
F_26 ( V_134 ) ;
return V_23 ;
}
static int F_83 ( struct V_14 * V_15 )
{
struct V_112 * V_35 = & V_15 -> V_36 . V_22 . V_35 ;
int V_23 ;
V_35 -> V_113 = 0 ;
V_35 -> V_37 = F_75 ( V_15 -> V_36 . V_142 , V_143 ,
V_161 , V_162 ) ;
if ( F_22 ( V_35 -> V_37 ) ) {
V_23 = F_23 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_35 -> V_114 = F_15 ( V_163 , sizeof( * V_35 -> V_114 ) , V_27 ) ;
if ( ! V_35 -> V_114 ) {
V_23 = - V_28 ;
goto V_164;
}
V_23 = F_82 ( V_35 ) ;
if ( V_23 )
goto V_165;
F_36 ( V_15 ) ;
return 0 ;
V_165:
F_10 ( V_35 -> V_114 ) ;
V_164:
F_63 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
static void F_84 ( struct V_14 * V_15 )
{
F_37 ( V_15 ) ;
F_62 ( & V_15 -> V_36 . V_22 . V_35 ) ;
}
int F_85 ( struct V_14 * V_15 )
{
int V_23 ;
V_15 -> V_36 . V_142 = F_86 ( V_15 -> V_25 ,
V_166 ) ;
if ( ! V_15 -> V_36 . V_142 )
return - V_167 ;
V_23 = F_87 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_10 ,
V_23 ) ;
V_15 -> V_18 -> V_168 &= ~ V_169 ;
}
V_23 = F_74 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_11 ,
V_23 ) ;
goto V_170;
}
V_23 = F_80 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_12 ,
V_23 ) ;
goto V_171;
}
V_23 = F_83 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_13 ,
V_23 ) ;
goto V_172;
}
F_88 ( V_15 ) ;
return 0 ;
V_172:
F_79 ( V_15 ) ;
V_171:
F_73 ( V_15 ) ;
V_170:
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
