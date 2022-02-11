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
T_2 V_31 , T_3 * V_32 , T_3 * V_33 )
{
struct V_34 * V_35 = V_15 -> V_36 . V_22 . V_35 . V_37 ;
struct V_38 V_39 ;
T_1 V_40 = 0 ;
struct V_41 * * V_42 ;
int V_23 = 0 ;
V_39 . type = V_43 ;
V_39 . V_35 = V_15 -> V_36 . V_44 . V_35 . V_37 ;
V_40 = V_45 ;
F_19 ( V_46 , V_32 , V_47 . V_48 ) ;
switch ( V_30 ) {
case V_49 :
V_42 = & V_15 -> V_36 . V_22 . V_50 ;
break;
case V_51 :
V_42 = & V_15 -> V_36 . V_22 . V_52 ;
F_20 ( V_46 , V_33 , V_47 . V_48 , 1 ) ;
break;
default:
V_42 = & V_15 -> V_36 . V_22 . V_53 [ V_31 ] ;
F_20 ( V_46 , V_33 , V_47 . V_48 , 1 ) ;
F_19 ( V_46 , V_32 , V_47 . V_54 ) ;
F_20 ( V_46 , V_33 , V_47 . V_54 , V_31 ) ;
break;
}
* V_42 = F_21 ( V_35 , V_40 , V_32 , V_33 ,
V_55 ,
V_56 ,
& V_39 ) ;
if ( F_22 ( * V_42 ) ) {
V_23 = F_23 ( * V_42 ) ;
* V_42 = NULL ;
F_17 ( V_15 -> V_18 , L_3 , V_57 ) ;
}
return V_23 ;
}
static int F_24 ( struct V_14 * V_15 ,
enum V_29 V_30 , T_2 V_31 )
{
T_3 * V_58 ;
T_3 * V_59 ;
int V_23 = 0 ;
V_59 = F_25 ( F_26 ( V_46 ) ) ;
V_58 = F_25 ( F_26 ( V_46 ) ) ;
if ( ! V_59 || ! V_58 ) {
F_17 ( V_15 -> V_18 , L_4 , V_57 ) ;
V_23 = - V_28 ;
goto V_60;
}
if ( V_30 == V_61 )
F_11 ( V_15 ) ;
V_23 = F_18 ( V_15 , V_30 , V_31 , V_58 ,
V_59 ) ;
V_60:
F_27 ( V_58 ) ;
F_27 ( V_59 ) ;
return V_23 ;
}
static void F_28 ( struct V_14 * V_15 ,
enum V_29 V_30 , T_2 V_31 )
{
switch ( V_30 ) {
case V_49 :
if ( V_15 -> V_36 . V_22 . V_50 ) {
F_29 ( V_15 -> V_36 . V_22 . V_50 ) ;
V_15 -> V_36 . V_22 . V_50 = NULL ;
}
break;
case V_51 :
if ( V_15 -> V_36 . V_22 . V_52 ) {
F_29 ( V_15 -> V_36 . V_22 . V_52 ) ;
V_15 -> V_36 . V_22 . V_52 = NULL ;
}
break;
case V_61 :
F_11 ( V_15 ) ;
if ( V_15 -> V_36 . V_22 . V_53 [ V_31 ] ) {
F_29 ( V_15 -> V_36 . V_22 . V_53 [ V_31 ] ) ;
V_15 -> V_36 . V_22 . V_53 [ V_31 ] = NULL ;
}
F_11 ( V_15 ) ;
break;
}
}
void F_30 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_36 . V_22 . V_62 )
return;
V_15 -> V_36 . V_22 . V_62 = false ;
if ( V_15 -> V_18 -> V_63 & V_64 )
return;
F_28 ( V_15 , V_51 , 0 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
if ( V_15 -> V_36 . V_22 . V_62 )
return;
V_15 -> V_36 . V_22 . V_62 = true ;
if ( V_15 -> V_18 -> V_63 & V_64 )
return;
F_24 ( V_15 , V_51 , 0 ) ;
}
int F_32 ( struct V_16 * V_65 , T_4 T_5 V_66 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_33 ( V_65 ) ;
F_34 ( V_31 , V_15 -> V_36 . V_22 . V_67 ) ;
return F_24 ( V_15 , V_61 , V_31 ) ;
}
int F_35 ( struct V_16 * V_65 , T_4 T_5 V_66 ,
T_2 V_31 )
{
struct V_14 * V_15 = F_33 ( V_65 ) ;
F_36 ( V_31 , V_15 -> V_36 . V_22 . V_67 ) ;
F_28 ( V_15 , V_61 , V_31 ) ;
return 0 ;
}
static void F_37 ( struct V_14 * V_15 ,
struct V_4 * V_5 )
{
switch ( V_5 -> V_9 ) {
case V_12 :
F_38 ( V_15 , & V_5 -> V_8 , V_68 ) ;
V_5 -> V_9 = V_10 ;
break;
case V_69 :
F_39 ( V_15 , & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
break;
}
}
static void F_40 ( struct V_14 * V_15 )
{
struct V_16 * V_18 = V_15 -> V_18 ;
struct V_70 * V_71 ;
F_41 ( V_18 ) ;
F_2 ( V_15 -> V_36 . V_44 . V_72 ,
V_15 -> V_18 -> V_73 ) ;
F_42 (ha, netdev)
F_2 ( V_15 -> V_36 . V_44 . V_72 , V_71 -> V_1 ) ;
F_43 (ha, netdev)
F_2 ( V_15 -> V_36 . V_44 . V_74 , V_71 -> V_1 ) ;
F_44 ( V_18 ) ;
}
static void F_45 ( struct V_14 * V_15 , int V_75 ,
T_1 V_76 [] [ V_77 ] , int V_78 )
{
bool V_79 = ( V_75 == V_80 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_4 * V_5 ;
struct V_2 * V_81 ;
struct V_82 * V_83 ;
int V_24 = 0 ;
int V_84 ;
V_81 = V_79 ? V_15 -> V_36 . V_44 . V_72 : V_15 -> V_36 . V_44 . V_74 ;
if ( V_79 )
F_6 ( V_76 [ V_24 ++ ] , V_17 -> V_73 ) ;
else if ( V_15 -> V_36 . V_44 . V_85 )
F_6 ( V_76 [ V_24 ++ ] , V_17 -> V_86 ) ;
F_46 (hn, tmp, addr_list, hi) {
if ( F_47 ( V_17 -> V_73 , V_5 -> V_8 . V_1 ) )
continue;
if ( V_24 >= V_78 )
break;
F_6 ( V_76 [ V_24 ++ ] , V_5 -> V_8 . V_1 ) ;
}
}
static void F_48 ( struct V_14 * V_15 ,
int V_75 )
{
bool V_79 = ( V_75 == V_80 ) ;
struct V_4 * V_5 ;
T_1 ( * V_76 ) [ V_77 ] = NULL ;
struct V_2 * V_81 ;
struct V_82 * V_83 ;
int V_87 ;
int V_78 ;
int V_23 ;
int V_84 ;
V_78 = V_79 ? 0 : ( V_15 -> V_36 . V_44 . V_85 ? 1 : 0 ) ;
V_87 = V_79 ?
1 << F_13 ( V_15 -> V_25 , V_88 ) :
1 << F_13 ( V_15 -> V_25 , V_89 ) ;
V_81 = V_79 ? V_15 -> V_36 . V_44 . V_72 : V_15 -> V_36 . V_44 . V_74 ;
F_46 (hn, tmp, addr_list, hi)
V_78 ++ ;
if ( V_78 > V_87 ) {
F_14 ( V_15 -> V_18 ,
L_5 ,
V_79 ? L_6 : L_7 , V_78 , V_87 ) ;
V_78 = V_87 ;
}
if ( V_78 ) {
V_76 = F_15 ( V_78 , V_77 , V_27 ) ;
if ( ! V_76 ) {
V_23 = - V_28 ;
goto V_90;
}
F_45 ( V_15 , V_75 , V_76 , V_78 ) ;
}
V_23 = F_49 ( V_15 -> V_25 , V_75 , V_76 , V_78 ) ;
V_90:
if ( V_23 )
F_17 ( V_15 -> V_18 ,
L_8 ,
V_79 ? L_6 : L_7 , V_23 ) ;
F_10 ( V_76 ) ;
}
static void F_50 ( struct V_14 * V_15 )
{
struct V_91 * V_92 = & V_15 -> V_36 . V_44 ;
F_48 ( V_15 , V_80 ) ;
F_48 ( V_15 , V_93 ) ;
F_51 ( V_15 -> V_25 , 0 ,
V_92 -> V_94 ,
V_92 -> V_95 ) ;
}
static void F_52 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_82 * V_83 ;
int V_24 ;
F_46 (hn, tmp, priv->fs.l2.netdev_uc, i)
F_37 ( V_15 , V_5 ) ;
F_46 (hn, tmp, priv->fs.l2.netdev_mc, i)
F_37 ( V_15 , V_5 ) ;
}
static void F_53 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_82 * V_83 ;
int V_24 ;
F_46 (hn, tmp, priv->fs.l2.netdev_uc, i)
V_5 -> V_9 = V_69 ;
F_46 (hn, tmp, priv->fs.l2.netdev_mc, i)
V_5 -> V_9 = V_69 ;
if ( ! F_54 ( V_96 , & V_15 -> V_97 ) )
F_40 ( V_15 ) ;
F_52 ( V_15 ) ;
}
void F_55 ( struct V_98 * V_99 )
{
struct V_14 * V_15 = F_56 ( V_99 , struct V_14 ,
V_100 ) ;
struct V_91 * V_92 = & V_15 -> V_36 . V_44 ;
struct V_16 * V_17 = V_15 -> V_18 ;
bool V_101 = ! F_54 ( V_96 , & V_15 -> V_97 ) ;
bool V_95 = V_101 && ( V_17 -> V_63 & V_64 ) ;
bool V_94 = V_101 && ( V_17 -> V_63 & V_102 ) ;
bool V_85 = V_101 ;
bool V_103 = ! V_92 -> V_95 && V_95 ;
bool V_104 = V_92 -> V_95 && ! V_95 ;
bool V_105 = ! V_92 -> V_94 && V_94 ;
bool V_106 = V_92 -> V_94 && ! V_94 ;
bool V_107 = ! V_92 -> V_85 && V_85 ;
bool V_108 = V_92 -> V_85 && ! V_85 ;
if ( V_103 ) {
F_38 ( V_15 , & V_92 -> V_109 , V_110 ) ;
if ( ! V_15 -> V_36 . V_22 . V_62 )
F_24 ( V_15 , V_51 ,
0 ) ;
}
if ( V_105 )
F_38 ( V_15 , & V_92 -> V_111 , V_112 ) ;
if ( V_107 )
F_38 ( V_15 , & V_92 -> V_86 , V_68 ) ;
F_53 ( V_15 ) ;
if ( V_108 )
F_39 ( V_15 , & V_92 -> V_86 ) ;
if ( V_106 )
F_39 ( V_15 , & V_92 -> V_111 ) ;
if ( V_104 ) {
if ( ! V_15 -> V_36 . V_22 . V_62 )
F_28 ( V_15 , V_51 ,
0 ) ;
F_39 ( V_15 , & V_92 -> V_109 ) ;
}
V_92 -> V_95 = V_95 ;
V_92 -> V_94 = V_94 ;
V_92 -> V_85 = V_85 ;
F_50 ( V_15 ) ;
}
static void F_57 ( struct V_113 * V_35 )
{
int V_24 ;
for ( V_24 = V_35 -> V_114 - 1 ; V_24 >= 0 ; V_24 -- ) {
if ( ! F_58 ( V_35 -> V_115 [ V_24 ] ) )
F_59 ( V_35 -> V_115 [ V_24 ] ) ;
V_35 -> V_115 [ V_24 ] = NULL ;
}
V_35 -> V_114 = 0 ;
}
void F_60 ( struct V_14 * V_15 )
{
F_6 ( V_15 -> V_36 . V_44 . V_86 . V_1 , V_15 -> V_18 -> V_86 ) ;
}
void F_61 ( struct V_113 * V_35 )
{
F_57 ( V_35 ) ;
F_10 ( V_35 -> V_115 ) ;
F_62 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
}
static void F_63 ( struct V_116 * V_117 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_118 ; V_24 ++ ) {
if ( ! F_58 ( V_117 -> V_119 [ V_24 ] ) ) {
F_29 ( V_117 -> V_119 [ V_24 ] ) ;
V_117 -> V_119 [ V_24 ] = NULL ;
}
}
}
static struct V_41 * F_64 ( struct V_14 * V_15 ,
struct V_34 * V_35 ,
struct V_38 * V_39 ,
T_2 V_120 ,
T_1 V_66 )
{
struct V_41 * V_121 ;
T_1 V_40 = 0 ;
T_3 * V_58 ;
T_3 * V_59 ;
int V_23 = 0 ;
V_59 = F_25 ( F_26 ( V_46 ) ) ;
V_58 = F_25 ( F_26 ( V_46 ) ) ;
if ( ! V_59 || ! V_58 ) {
F_17 ( V_15 -> V_18 , L_4 , V_57 ) ;
V_23 = - V_28 ;
goto V_90;
}
if ( V_66 ) {
V_40 = V_45 ;
F_19 ( V_46 , V_58 , V_47 . V_122 ) ;
F_20 ( V_46 , V_59 , V_47 . V_122 , V_66 ) ;
}
if ( V_120 ) {
V_40 = V_45 ;
F_19 ( V_46 , V_58 , V_47 . V_123 ) ;
F_20 ( V_46 , V_59 , V_47 . V_123 , V_120 ) ;
}
V_121 = F_21 ( V_35 , V_40 ,
V_58 , V_59 ,
V_55 ,
V_56 ,
V_39 ) ;
if ( F_22 ( V_121 ) ) {
V_23 = F_23 ( V_121 ) ;
F_17 ( V_15 -> V_18 , L_3 , V_57 ) ;
}
V_90:
F_27 ( V_58 ) ;
F_27 ( V_59 ) ;
return V_23 ? F_65 ( V_23 ) : V_121 ;
}
static int F_66 ( struct V_14 * V_15 )
{
struct V_38 V_39 ;
struct V_116 * V_117 ;
struct V_41 * * V_119 ;
struct V_34 * V_35 ;
int V_124 ;
int V_23 ;
V_117 = & V_15 -> V_36 . V_117 ;
V_35 = V_117 -> V_35 . V_37 ;
V_119 = V_117 -> V_119 ;
V_39 . type = V_125 ;
for ( V_124 = 0 ; V_124 < V_118 ; V_124 ++ ) {
if ( V_124 == V_126 )
V_39 . V_127 = V_15 -> V_128 [ 0 ] . V_129 ;
else
V_39 . V_127 = V_15 -> V_130 [ V_124 ] ;
V_119 [ V_124 ] = F_64 ( V_15 , V_35 , & V_39 ,
V_131 [ V_124 ] . V_120 ,
V_131 [ V_124 ] . V_66 ) ;
if ( F_22 ( V_119 [ V_124 ] ) )
goto V_132;
}
return 0 ;
V_132:
V_23 = F_23 ( V_119 [ V_124 ] ) ;
V_119 [ V_124 ] = NULL ;
F_63 ( V_117 ) ;
return V_23 ;
}
static int F_67 ( struct V_116 * V_117 )
{
int V_133 = F_26 ( V_134 ) ;
struct V_113 * V_35 = & V_117 -> V_35 ;
int V_6 = 0 ;
T_3 * V_135 ;
int V_23 ;
T_1 * V_32 ;
V_35 -> V_115 = F_15 ( V_136 ,
sizeof( * V_35 -> V_115 ) , V_27 ) ;
if ( ! V_35 -> V_115 )
return - V_28 ;
V_135 = F_25 ( V_133 ) ;
if ( ! V_135 ) {
F_10 ( V_35 -> V_115 ) ;
return - V_28 ;
}
V_32 = F_68 ( V_134 , V_135 , V_58 ) ;
F_19 ( V_46 , V_32 , V_47 . V_122 ) ;
F_19 ( V_46 , V_32 , V_47 . V_123 ) ;
F_69 ( V_135 , V_40 , V_45 ) ;
F_69 ( V_135 , V_137 , V_6 ) ;
V_6 += V_138 ;
F_69 ( V_135 , V_139 , V_6 - 1 ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = F_70 ( V_35 -> V_37 , V_135 ) ;
if ( F_22 ( V_35 -> V_115 [ V_35 -> V_114 ] ) )
goto V_23;
V_35 -> V_114 ++ ;
F_20 ( V_46 , V_32 , V_47 . V_122 , 0 ) ;
F_69 ( V_135 , V_137 , V_6 ) ;
V_6 += V_140 ;
F_69 ( V_135 , V_139 , V_6 - 1 ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = F_70 ( V_35 -> V_37 , V_135 ) ;
if ( F_22 ( V_35 -> V_115 [ V_35 -> V_114 ] ) )
goto V_23;
V_35 -> V_114 ++ ;
memset ( V_135 , 0 , V_133 ) ;
F_69 ( V_135 , V_137 , V_6 ) ;
V_6 += V_141 ;
F_69 ( V_135 , V_139 , V_6 - 1 ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = F_70 ( V_35 -> V_37 , V_135 ) ;
if ( F_22 ( V_35 -> V_115 [ V_35 -> V_114 ] ) )
goto V_23;
V_35 -> V_114 ++ ;
F_27 ( V_135 ) ;
return 0 ;
V_23:
V_23 = F_23 ( V_35 -> V_115 [ V_35 -> V_114 ] ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = NULL ;
F_27 ( V_135 ) ;
return V_23 ;
}
static void F_71 ( struct V_14 * V_15 )
{
struct V_116 * V_117 = & V_15 -> V_36 . V_117 ;
F_63 ( V_117 ) ;
F_61 ( & V_117 -> V_35 ) ;
}
static int F_72 ( struct V_14 * V_15 )
{
struct V_116 * V_117 = & V_15 -> V_36 . V_117 ;
struct V_113 * V_35 = & V_117 -> V_35 ;
int V_23 ;
V_35 -> V_37 = F_73 ( V_15 -> V_36 . V_142 , V_143 ,
V_144 , V_145 ) ;
if ( F_22 ( V_35 -> V_37 ) ) {
V_23 = F_23 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_23 = F_67 ( V_117 ) ;
if ( V_23 )
goto V_23;
V_23 = F_66 ( V_15 ) ;
if ( V_23 )
goto V_23;
return 0 ;
V_23:
F_61 ( V_35 ) ;
return V_23 ;
}
static void F_39 ( struct V_14 * V_15 ,
struct V_146 * V_8 )
{
if ( ! F_58 ( V_8 -> V_121 ) ) {
F_29 ( V_8 -> V_121 ) ;
V_8 -> V_121 = NULL ;
}
}
static int F_38 ( struct V_14 * V_15 ,
struct V_146 * V_8 , int type )
{
struct V_34 * V_35 = V_15 -> V_36 . V_44 . V_35 . V_37 ;
struct V_38 V_39 ;
T_1 V_40 = 0 ;
T_3 * V_58 ;
T_3 * V_59 ;
int V_23 = 0 ;
T_1 * V_147 ;
T_1 * V_148 ;
V_59 = F_25 ( F_26 ( V_46 ) ) ;
V_58 = F_25 ( F_26 ( V_46 ) ) ;
if ( ! V_59 || ! V_58 ) {
F_17 ( V_15 -> V_18 , L_4 , V_57 ) ;
V_23 = - V_28 ;
goto V_149;
}
V_147 = F_68 ( V_46 , V_58 ,
V_47 . V_150 ) ;
V_148 = F_68 ( V_46 , V_59 ,
V_47 . V_150 ) ;
V_39 . type = V_43 ;
V_39 . V_35 = V_15 -> V_36 . V_117 . V_35 . V_37 ;
switch ( type ) {
case V_68 :
V_40 = V_45 ;
F_74 ( V_147 ) ;
F_6 ( V_148 , V_8 -> V_1 ) ;
break;
case V_112 :
V_40 = V_45 ;
V_147 [ 0 ] = 0x01 ;
V_148 [ 0 ] = 0x01 ;
break;
case V_110 :
break;
}
V_8 -> V_121 = F_21 ( V_35 , V_40 , V_58 ,
V_59 ,
V_55 ,
V_56 , & V_39 ) ;
if ( F_22 ( V_8 -> V_121 ) ) {
F_17 ( V_15 -> V_18 , L_9 ,
V_57 , V_148 ) ;
V_23 = F_23 ( V_8 -> V_121 ) ;
V_8 -> V_121 = NULL ;
}
V_149:
F_27 ( V_58 ) ;
F_27 ( V_59 ) ;
return V_23 ;
}
static int F_75 ( struct V_91 * V_151 )
{
int V_133 = F_26 ( V_134 ) ;
struct V_113 * V_35 = & V_151 -> V_35 ;
int V_6 = 0 ;
T_1 * V_147 ;
T_3 * V_135 ;
int V_23 ;
T_1 * V_32 ;
V_35 -> V_115 = F_15 ( V_152 , sizeof( * V_35 -> V_115 ) , V_27 ) ;
if ( ! V_35 -> V_115 )
return - V_28 ;
V_135 = F_25 ( V_133 ) ;
if ( ! V_135 ) {
F_10 ( V_35 -> V_115 ) ;
return - V_28 ;
}
V_32 = F_68 ( V_134 , V_135 , V_58 ) ;
V_147 = F_68 ( V_46 , V_32 ,
V_47 . V_150 ) ;
F_69 ( V_135 , V_137 , V_6 ) ;
V_6 += V_153 ;
F_69 ( V_135 , V_139 , V_6 - 1 ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = F_70 ( V_35 -> V_37 , V_135 ) ;
if ( F_22 ( V_35 -> V_115 [ V_35 -> V_114 ] ) )
goto V_154;
V_35 -> V_114 ++ ;
F_74 ( V_147 ) ;
F_69 ( V_135 , V_40 , V_45 ) ;
F_69 ( V_135 , V_137 , V_6 ) ;
V_6 += V_155 ;
F_69 ( V_135 , V_139 , V_6 - 1 ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = F_70 ( V_35 -> V_37 , V_135 ) ;
if ( F_22 ( V_35 -> V_115 [ V_35 -> V_114 ] ) )
goto V_154;
V_35 -> V_114 ++ ;
F_76 ( V_147 ) ;
V_147 [ 0 ] = 0x01 ;
F_69 ( V_135 , V_137 , V_6 ) ;
V_6 += V_156 ;
F_69 ( V_135 , V_139 , V_6 - 1 ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = F_70 ( V_35 -> V_37 , V_135 ) ;
if ( F_22 ( V_35 -> V_115 [ V_35 -> V_114 ] ) )
goto V_154;
V_35 -> V_114 ++ ;
F_27 ( V_135 ) ;
return 0 ;
V_154:
V_23 = F_23 ( V_35 -> V_115 [ V_35 -> V_114 ] ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = NULL ;
F_57 ( V_35 ) ;
F_27 ( V_135 ) ;
return V_23 ;
}
static void F_77 ( struct V_14 * V_15 )
{
F_61 ( & V_15 -> V_36 . V_44 . V_35 ) ;
}
static int F_78 ( struct V_14 * V_15 )
{
struct V_91 * V_151 = & V_15 -> V_36 . V_44 ;
struct V_113 * V_35 = & V_151 -> V_35 ;
int V_23 ;
V_35 -> V_114 = 0 ;
V_35 -> V_37 = F_73 ( V_15 -> V_36 . V_142 , V_143 ,
V_157 , V_158 ) ;
if ( F_22 ( V_35 -> V_37 ) ) {
V_23 = F_23 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_23 = F_75 ( V_151 ) ;
if ( V_23 )
goto V_159;
return 0 ;
V_159:
F_62 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
static int F_79 ( struct V_113 * V_35 , T_3 * V_135 ,
int V_133 )
{
int V_23 ;
int V_6 = 0 ;
T_1 * V_32 = F_68 ( V_134 , V_135 , V_58 ) ;
memset ( V_135 , 0 , V_133 ) ;
F_69 ( V_135 , V_40 , V_45 ) ;
F_19 ( V_46 , V_32 , V_47 . V_48 ) ;
F_19 ( V_46 , V_32 , V_47 . V_54 ) ;
F_69 ( V_135 , V_137 , V_6 ) ;
V_6 += V_160 ;
F_69 ( V_135 , V_139 , V_6 - 1 ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = F_70 ( V_35 -> V_37 , V_135 ) ;
if ( F_22 ( V_35 -> V_115 [ V_35 -> V_114 ] ) )
goto V_154;
V_35 -> V_114 ++ ;
memset ( V_135 , 0 , V_133 ) ;
F_69 ( V_135 , V_40 , V_45 ) ;
F_19 ( V_46 , V_32 , V_47 . V_48 ) ;
F_69 ( V_135 , V_137 , V_6 ) ;
V_6 += V_161 ;
F_69 ( V_135 , V_139 , V_6 - 1 ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = F_70 ( V_35 -> V_37 , V_135 ) ;
if ( F_22 ( V_35 -> V_115 [ V_35 -> V_114 ] ) )
goto V_154;
V_35 -> V_114 ++ ;
return 0 ;
V_154:
V_23 = F_23 ( V_35 -> V_115 [ V_35 -> V_114 ] ) ;
V_35 -> V_115 [ V_35 -> V_114 ] = NULL ;
F_57 ( V_35 ) ;
return V_23 ;
}
static int F_80 ( struct V_113 * V_35 )
{
T_3 * V_135 ;
int V_133 = F_26 ( V_134 ) ;
int V_23 ;
V_135 = F_25 ( V_133 ) ;
if ( ! V_135 )
return - V_28 ;
V_23 = F_79 ( V_35 , V_135 , V_133 ) ;
F_27 ( V_135 ) ;
return V_23 ;
}
static int F_81 ( struct V_14 * V_15 )
{
struct V_113 * V_35 = & V_15 -> V_36 . V_22 . V_35 ;
int V_23 ;
V_35 -> V_114 = 0 ;
V_35 -> V_37 = F_73 ( V_15 -> V_36 . V_142 , V_143 ,
V_162 , V_163 ) ;
if ( F_22 ( V_35 -> V_37 ) ) {
V_23 = F_23 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
V_35 -> V_115 = F_15 ( V_164 , sizeof( * V_35 -> V_115 ) , V_27 ) ;
if ( ! V_35 -> V_115 ) {
V_23 = - V_28 ;
goto V_165;
}
V_23 = F_80 ( V_35 ) ;
if ( V_23 )
goto V_166;
V_23 = F_24 ( V_15 , V_49 , 0 ) ;
if ( V_23 )
goto V_167;
return 0 ;
V_167:
F_57 ( V_35 ) ;
V_166:
F_10 ( V_35 -> V_115 ) ;
V_165:
F_62 ( V_35 -> V_37 ) ;
V_35 -> V_37 = NULL ;
return V_23 ;
}
static void F_82 ( struct V_14 * V_15 )
{
F_61 ( & V_15 -> V_36 . V_22 . V_35 ) ;
}
int F_83 ( struct V_14 * V_15 )
{
int V_23 ;
V_15 -> V_36 . V_142 = F_84 ( V_15 -> V_25 ,
V_168 ) ;
if ( ! V_15 -> V_36 . V_142 )
return - V_169 ;
V_23 = F_85 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_10 ,
V_23 ) ;
V_15 -> V_18 -> V_170 &= ~ V_171 ;
}
V_23 = F_72 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_11 ,
V_23 ) ;
goto V_172;
}
V_23 = F_78 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_12 ,
V_23 ) ;
goto V_173;
}
V_23 = F_81 ( V_15 ) ;
if ( V_23 ) {
F_17 ( V_15 -> V_18 , L_13 ,
V_23 ) ;
goto V_174;
}
return 0 ;
V_174:
F_77 ( V_15 ) ;
V_173:
F_71 ( V_15 ) ;
V_172:
F_86 ( V_15 ) ;
return V_23 ;
}
void F_87 ( struct V_14 * V_15 )
{
F_28 ( V_15 , V_49 , 0 ) ;
F_82 ( V_15 ) ;
F_77 ( V_15 ) ;
F_71 ( V_15 ) ;
F_86 ( V_15 ) ;
}
