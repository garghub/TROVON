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
static void F_11 ( struct V_14 * V_15 ,
struct V_16 * V_8 )
{
void * V_17 = V_15 -> V_17 . main ;
if ( V_8 -> V_18 & ( 1 << V_19 ) )
F_12 ( V_17 , V_8 -> V_20 [ V_19 ] ) ;
if ( V_8 -> V_18 & ( 1 << V_21 ) )
F_12 ( V_17 , V_8 -> V_20 [ V_21 ] ) ;
if ( V_8 -> V_18 & ( 1 << V_22 ) )
F_12 ( V_17 , V_8 -> V_20 [ V_22 ] ) ;
if ( V_8 -> V_18 & ( 1 << V_23 ) )
F_12 ( V_17 , V_8 -> V_20 [ V_23 ] ) ;
if ( V_8 -> V_18 & ( 1 << V_24 ) )
F_12 ( V_17 , V_8 -> V_20 [ V_24 ] ) ;
if ( V_8 -> V_18 & ( 1 << V_25 ) )
F_12 ( V_17 , V_8 -> V_20 [ V_25 ] ) ;
if ( V_8 -> V_18 & ( 1 << V_26 ) )
F_12 ( V_17 , V_8 -> V_20 [ V_26 ] ) ;
}
static int F_13 ( T_1 * V_1 )
{
if ( F_14 ( V_1 ) )
return V_27 ;
if ( ( V_1 [ 0 ] == 0x01 ) &&
( V_1 [ 1 ] == 0x00 ) &&
( V_1 [ 2 ] == 0x5e ) &&
! ( V_1 [ 3 ] & 0x80 ) )
return V_28 ;
if ( ( V_1 [ 0 ] == 0x33 ) &&
( V_1 [ 1 ] == 0x33 ) )
return V_29 ;
return V_30 ;
}
static T_2 F_15 ( struct V_16 * V_8 , int type )
{
int V_31 ;
T_2 V_32 ;
switch ( type ) {
case V_33 :
V_31 = F_13 ( V_8 -> V_1 ) ;
switch ( V_31 ) {
case V_27 :
V_32 =
( 1 << V_21 ) |
( 1 << V_19 ) |
( 1 << V_23 ) |
( 1 << V_22 ) |
( 1 << V_25 ) |
( 1 << V_24 ) |
( 1 << V_26 ) |
0 ;
break;
case V_28 :
V_32 =
( 1 << V_23 ) |
( 1 << V_25 ) |
0 ;
break;
case V_29 :
V_32 =
( 1 << V_22 ) |
( 1 << V_24 ) |
0 ;
break;
case V_30 :
V_32 =
( 1 << V_26 ) |
0 ;
break;
}
break;
case V_34 :
V_32 =
( 1 << V_23 ) |
( 1 << V_22 ) |
( 1 << V_25 ) |
( 1 << V_24 ) |
( 1 << V_26 ) |
0 ;
break;
default:
V_32 =
( 1 << V_21 ) |
( 1 << V_19 ) |
( 1 << V_23 ) |
( 1 << V_22 ) |
( 1 << V_25 ) |
( 1 << V_24 ) |
( 1 << V_26 ) |
0 ;
break;
}
return V_32 ;
}
static int F_16 ( struct V_14 * V_15 ,
struct V_16 * V_8 , int type ,
void * V_35 , void * V_36 )
{
T_1 V_37 = 0 ;
void * V_38 ;
void * V_39 ;
T_1 * V_40 ;
T_1 * V_41 ;
void * V_17 = V_15 -> V_17 . main ;
T_2 * V_42 = V_15 -> V_42 ;
T_2 V_18 ;
int V_43 ;
V_38 = F_17 ( V_35 , V_35 , V_38 ) ;
V_40 = F_17 ( V_44 , V_38 ,
V_45 . V_46 ) ;
V_41 = F_17 ( V_44 , V_36 ,
V_45 . V_46 ) ;
V_39 = F_17 ( V_35 , V_35 , V_47 ) ;
F_18 ( V_35 , V_35 , V_9 ,
V_48 ) ;
F_18 ( V_35 , V_35 , V_49 , 1 ) ;
F_18 ( V_50 , V_39 , V_51 ,
V_52 ) ;
switch ( type ) {
case V_33 :
V_37 = V_53 ;
memset ( V_41 , 0xff , V_54 ) ;
F_6 ( V_40 , V_8 -> V_1 ) ;
break;
case V_34 :
V_37 = V_53 ;
V_41 [ 0 ] = 0x01 ;
V_40 [ 0 ] = 0x01 ;
break;
case V_55 :
break;
}
V_18 = F_15 ( V_8 , type ) ;
if ( V_18 & ( 1 << V_26 ) ) {
F_18 ( V_50 , V_39 , V_56 ,
V_42 [ V_26 ] ) ;
V_43 = F_19 ( V_17 , V_37 ,
V_36 , V_35 ,
& V_8 -> V_20 [ V_26 ] ) ;
if ( V_43 ) {
F_11 ( V_15 , V_8 ) ;
return V_43 ;
}
V_8 -> V_18 |= ( 1 << V_26 ) ;
}
V_37 = V_53 ;
F_20 ( V_44 , V_36 ,
V_45 . V_57 ) ;
if ( V_18 & ( 1 << V_25 ) ) {
F_18 ( V_44 , V_38 , V_45 . V_57 ,
V_58 ) ;
F_18 ( V_50 , V_39 , V_56 ,
V_42 [ V_25 ] ) ;
V_43 = F_19 ( V_17 , V_37 ,
V_36 , V_35 ,
& V_8 -> V_20 [ V_25 ] ) ;
if ( V_43 ) {
F_11 ( V_15 , V_8 ) ;
return V_43 ;
}
V_8 -> V_18 |= ( 1 << V_25 ) ;
}
if ( V_18 & ( 1 << V_24 ) ) {
F_18 ( V_44 , V_38 , V_45 . V_57 ,
V_59 ) ;
F_18 ( V_50 , V_39 , V_56 ,
V_42 [ V_24 ] ) ;
V_43 = F_19 ( V_17 , V_37 ,
V_36 , V_35 ,
& V_8 -> V_20 [ V_24 ] ) ;
if ( V_43 ) {
F_11 ( V_15 , V_8 ) ;
return V_43 ;
}
V_8 -> V_18 |= ( 1 << V_24 ) ;
}
F_20 ( V_44 , V_36 ,
V_45 . V_60 ) ;
F_18 ( V_44 , V_38 , V_45 . V_60 ,
V_61 ) ;
if ( V_18 & ( 1 << V_23 ) ) {
F_18 ( V_44 , V_38 , V_45 . V_57 ,
V_58 ) ;
F_18 ( V_50 , V_39 , V_56 ,
V_42 [ V_23 ] ) ;
V_43 = F_19 ( V_17 , V_37 ,
V_36 , V_35 ,
& V_8 -> V_20 [ V_23 ] ) ;
if ( V_43 ) {
F_11 ( V_15 , V_8 ) ;
return V_43 ;
}
V_8 -> V_18 |= ( 1 << V_23 ) ;
}
if ( V_18 & ( 1 << V_22 ) ) {
F_18 ( V_44 , V_38 , V_45 . V_57 ,
V_59 ) ;
F_18 ( V_50 , V_39 , V_56 ,
V_42 [ V_22 ] ) ;
V_43 = F_19 ( V_17 , V_37 ,
V_36 , V_35 ,
& V_8 -> V_20 [ V_22 ] ) ;
if ( V_43 ) {
F_11 ( V_15 , V_8 ) ;
return V_43 ;
}
V_8 -> V_18 |= ( 1 << V_22 ) ;
}
F_18 ( V_44 , V_38 , V_45 . V_60 ,
V_62 ) ;
if ( V_18 & ( 1 << V_21 ) ) {
F_18 ( V_44 , V_38 , V_45 . V_57 ,
V_58 ) ;
F_18 ( V_50 , V_39 , V_56 ,
V_42 [ V_21 ] ) ;
V_43 = F_19 ( V_17 , V_37 ,
V_36 , V_35 ,
& V_8 -> V_20 [ V_21 ] ) ;
if ( V_43 ) {
F_11 ( V_15 , V_8 ) ;
return V_43 ;
}
V_8 -> V_18 |= ( 1 << V_21 ) ;
}
if ( V_18 & ( 1 << V_19 ) ) {
F_18 ( V_44 , V_38 , V_45 . V_57 ,
V_59 ) ;
F_18 ( V_50 , V_39 , V_56 ,
V_42 [ V_19 ] ) ;
V_43 = F_19 ( V_17 , V_37 ,
V_36 , V_35 ,
& V_8 -> V_20 [ V_19 ] ) ;
if ( V_43 ) {
F_11 ( V_15 , V_8 ) ;
return V_43 ;
}
V_8 -> V_18 |= ( 1 << V_19 ) ;
}
return 0 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_16 * V_8 , int type )
{
T_2 * V_35 ;
T_2 * V_36 ;
int V_43 ;
V_35 = F_22 ( F_23 ( V_35 ) +
F_23 ( V_50 ) ) ;
V_36 = F_22 ( F_23 ( V_44 ) ) ;
if ( ! V_35 || ! V_36 ) {
F_24 ( V_15 -> V_63 , L_1 , V_64 ) ;
V_43 = - V_65 ;
goto V_66;
}
V_43 = F_16 ( V_15 , V_8 , type , V_35 ,
V_36 ) ;
if ( V_43 )
F_24 ( V_15 -> V_63 , L_2 , V_64 ) ;
V_66:
F_25 ( V_36 ) ;
F_25 ( V_35 ) ;
return V_43 ;
}
static int F_26 ( struct V_14 * V_15 ,
enum V_67 V_68 , T_3 V_69 )
{
T_1 V_37 = 0 ;
T_2 * V_35 ;
void * V_38 ;
void * V_39 ;
T_2 * V_36 ;
T_2 * V_20 ;
int V_43 ;
V_35 = F_22 ( F_23 ( V_35 ) +
F_23 ( V_50 ) ) ;
V_36 = F_22 ( F_23 ( V_44 ) ) ;
if ( ! V_35 || ! V_36 ) {
F_24 ( V_15 -> V_63 , L_1 , V_64 ) ;
V_43 = - V_65 ;
goto V_70;
}
V_38 = F_17 ( V_35 , V_35 , V_38 ) ;
V_39 = F_17 ( V_35 , V_35 , V_47 ) ;
F_18 ( V_35 , V_35 , V_9 ,
V_48 ) ;
F_18 ( V_35 , V_35 , V_49 , 1 ) ;
F_18 ( V_50 , V_39 , V_51 ,
V_71 ) ;
F_18 ( V_50 , V_39 , V_56 ,
F_27 ( V_15 -> V_17 . main ) ) ;
V_37 = V_53 ;
F_20 ( V_44 , V_36 ,
V_45 . V_72 ) ;
switch ( V_68 ) {
case V_73 :
V_20 = & V_15 -> V_74 . V_75 ;
break;
case V_76 :
V_20 = & V_15 -> V_74 . V_77 ;
F_18 ( V_44 , V_38 , V_45 . V_72 ,
1 ) ;
break;
default:
V_20 = & V_15 -> V_74 . V_78 [ V_69 ] ;
F_18 ( V_44 , V_38 , V_45 . V_72 ,
1 ) ;
F_20 ( V_44 , V_36 ,
V_45 . V_79 ) ;
F_18 ( V_44 , V_38 , V_45 . V_79 ,
V_69 ) ;
break;
}
V_43 = F_19 ( V_15 -> V_17 . V_74 , V_37 ,
V_36 , V_35 , V_20 ) ;
if ( V_43 )
F_24 ( V_15 -> V_63 , L_2 , V_64 ) ;
V_70:
F_25 ( V_36 ) ;
F_25 ( V_35 ) ;
return V_43 ;
}
static void F_28 ( struct V_14 * V_15 ,
enum V_67 V_68 , T_3 V_69 )
{
switch ( V_68 ) {
case V_73 :
F_12 ( V_15 -> V_17 . V_74 ,
V_15 -> V_74 . V_75 ) ;
break;
case V_76 :
F_12 ( V_15 -> V_17 . V_74 ,
V_15 -> V_74 . V_77 ) ;
break;
case V_80 :
F_12 ( V_15 -> V_17 . V_74 ,
V_15 -> V_74 . V_78 [ V_69 ] ) ;
break;
}
}
void F_29 ( struct V_14 * V_15 )
{
F_30 ( ! F_31 ( & V_15 -> V_81 ) ) ;
if ( V_15 -> V_74 . V_82 ) {
V_15 -> V_74 . V_82 = false ;
if ( F_32 ( V_83 , & V_15 -> V_84 ) )
F_28 ( V_15 , V_76 ,
0 ) ;
}
}
void F_33 ( struct V_14 * V_15 )
{
F_30 ( ! F_31 ( & V_15 -> V_81 ) ) ;
if ( ! V_15 -> V_74 . V_82 ) {
V_15 -> V_74 . V_82 = true ;
if ( F_32 ( V_83 , & V_15 -> V_84 ) )
F_26 ( V_15 , V_76 ,
0 ) ;
}
}
int F_34 ( struct V_85 * V_86 , T_4 T_5 V_87 ,
T_3 V_69 )
{
struct V_14 * V_15 = F_35 ( V_86 ) ;
int V_43 = 0 ;
F_36 ( & V_15 -> V_81 ) ;
F_37 ( V_69 , V_15 -> V_74 . V_88 ) ;
if ( F_32 ( V_83 , & V_15 -> V_84 ) )
V_43 = F_26 ( V_15 , V_80 ,
V_69 ) ;
F_38 ( & V_15 -> V_81 ) ;
return V_43 ;
}
int F_39 ( struct V_85 * V_86 , T_4 T_5 V_87 ,
T_3 V_69 )
{
struct V_14 * V_15 = F_35 ( V_86 ) ;
F_36 ( & V_15 -> V_81 ) ;
F_40 ( V_69 , V_15 -> V_74 . V_88 ) ;
if ( F_32 ( V_83 , & V_15 -> V_84 ) )
F_28 ( V_15 , V_80 , V_69 ) ;
F_38 ( & V_15 -> V_81 ) ;
return 0 ;
}
int F_41 ( struct V_14 * V_15 )
{
T_3 V_69 ;
int V_43 ;
F_42 (vid, priv->vlan.active_vlans, VLAN_N_VID) {
V_43 = F_26 ( V_15 , V_80 ,
V_69 ) ;
if ( V_43 )
return V_43 ;
}
V_43 = F_26 ( V_15 , V_73 , 0 ) ;
if ( V_43 )
return V_43 ;
if ( V_15 -> V_74 . V_82 ) {
V_43 = F_26 ( V_15 , V_76 ,
0 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
void F_43 ( struct V_14 * V_15 )
{
T_3 V_69 ;
if ( V_15 -> V_74 . V_82 )
F_28 ( V_15 , V_76 , 0 ) ;
F_28 ( V_15 , V_73 , 0 ) ;
F_42 (vid, priv->vlan.active_vlans, VLAN_N_VID)
F_28 ( V_15 , V_80 , V_69 ) ;
}
static void F_44 ( struct V_14 * V_15 ,
struct V_4 * V_5 )
{
switch ( V_5 -> V_9 ) {
case V_12 :
F_21 ( V_15 , & V_5 -> V_8 , V_33 ) ;
V_5 -> V_9 = V_10 ;
break;
case V_89 :
F_11 ( V_15 , & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
break;
}
}
static void F_45 ( struct V_14 * V_15 )
{
struct V_85 * V_63 = V_15 -> V_63 ;
struct V_90 * V_91 ;
F_46 ( V_63 ) ;
F_2 ( V_15 -> V_92 . V_93 ,
V_15 -> V_63 -> V_94 ) ;
F_47 (ha, netdev)
F_2 ( V_15 -> V_92 . V_93 , V_91 -> V_1 ) ;
F_48 (ha, netdev)
F_2 ( V_15 -> V_92 . V_95 , V_91 -> V_1 ) ;
F_49 ( V_63 ) ;
}
static void F_50 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_96 * V_97 ;
int V_98 ;
F_51 (hn, tmp, priv->eth_addr.netdev_uc, i)
F_44 ( V_15 , V_5 ) ;
F_51 (hn, tmp, priv->eth_addr.netdev_mc, i)
F_44 ( V_15 , V_5 ) ;
}
static void F_52 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
struct V_96 * V_97 ;
int V_98 ;
F_51 (hn, tmp, priv->eth_addr.netdev_uc, i)
V_5 -> V_9 = V_89 ;
F_51 (hn, tmp, priv->eth_addr.netdev_mc, i)
V_5 -> V_9 = V_89 ;
if ( F_32 ( V_83 , & V_15 -> V_84 ) )
F_45 ( V_15 ) ;
F_50 ( V_15 ) ;
}
void F_53 ( struct V_14 * V_15 )
{
struct V_99 * V_100 = & V_15 -> V_92 ;
struct V_85 * V_101 = V_15 -> V_63 ;
bool V_102 = F_32 ( V_83 , & V_15 -> V_84 ) ;
bool V_103 = V_102 && ( V_101 -> V_104 & V_105 ) ;
bool V_106 = V_102 && ( V_101 -> V_104 & V_107 ) ;
bool V_108 = V_102 ;
bool V_109 = ! V_100 -> V_103 && V_103 ;
bool V_110 = V_100 -> V_103 && ! V_103 ;
bool V_111 = ! V_100 -> V_106 && V_106 ;
bool V_112 = V_100 -> V_106 && ! V_106 ;
bool V_113 = ! V_100 -> V_108 && V_108 ;
bool V_114 = V_100 -> V_108 && ! V_108 ;
if ( V_109 )
F_21 ( V_15 , & V_100 -> V_115 , V_55 ) ;
if ( V_111 )
F_21 ( V_15 , & V_100 -> V_116 , V_34 ) ;
if ( V_113 )
F_21 ( V_15 , & V_100 -> V_117 , V_33 ) ;
F_52 ( V_15 ) ;
if ( V_114 )
F_11 ( V_15 , & V_100 -> V_117 ) ;
if ( V_112 )
F_11 ( V_15 , & V_100 -> V_116 ) ;
if ( V_110 )
F_11 ( V_15 , & V_100 -> V_115 ) ;
V_100 -> V_103 = V_103 ;
V_100 -> V_106 = V_106 ;
V_100 -> V_108 = V_108 ;
}
void F_54 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_55 ( V_119 , struct V_14 ,
V_120 ) ;
F_36 ( & V_15 -> V_81 ) ;
if ( F_32 ( V_83 , & V_15 -> V_84 ) )
F_53 ( V_15 ) ;
F_38 ( & V_15 -> V_81 ) ;
}
void F_56 ( struct V_14 * V_15 )
{
F_6 ( V_15 -> V_92 . V_117 . V_1 , V_15 -> V_63 -> V_117 ) ;
}
static int F_57 ( struct V_14 * V_15 )
{
struct V_121 * V_122 ;
T_1 * V_40 ;
V_122 = F_58 ( 9 , sizeof( * V_122 ) , V_123 ) ;
if ( ! V_122 )
return - V_65 ;
V_122 [ 0 ] . V_124 = 2 ;
V_122 [ 0 ] . V_37 = V_53 ;
F_20 ( V_44 , V_122 [ 0 ] . V_36 ,
V_45 . V_57 ) ;
F_20 ( V_44 , V_122 [ 0 ] . V_36 ,
V_45 . V_60 ) ;
V_122 [ 1 ] . V_124 = 1 ;
V_122 [ 1 ] . V_37 = V_53 ;
F_20 ( V_44 , V_122 [ 1 ] . V_36 ,
V_45 . V_57 ) ;
V_122 [ 2 ] . V_124 = 0 ;
V_122 [ 3 ] . V_124 = 14 ;
V_122 [ 3 ] . V_37 = V_53 ;
V_40 = F_17 ( V_44 , V_122 [ 3 ] . V_36 ,
V_45 . V_46 ) ;
memset ( V_40 , 0xff , V_54 ) ;
F_20 ( V_44 , V_122 [ 3 ] . V_36 ,
V_45 . V_57 ) ;
F_20 ( V_44 , V_122 [ 3 ] . V_36 ,
V_45 . V_60 ) ;
V_122 [ 4 ] . V_124 = 13 ;
V_122 [ 4 ] . V_37 = V_53 ;
V_40 = F_17 ( V_44 , V_122 [ 4 ] . V_36 ,
V_45 . V_46 ) ;
memset ( V_40 , 0xff , V_54 ) ;
F_20 ( V_44 , V_122 [ 4 ] . V_36 ,
V_45 . V_57 ) ;
V_122 [ 5 ] . V_124 = 11 ;
V_122 [ 5 ] . V_37 = V_53 ;
V_40 = F_17 ( V_44 , V_122 [ 5 ] . V_36 ,
V_45 . V_46 ) ;
memset ( V_40 , 0xff , V_54 ) ;
V_122 [ 6 ] . V_124 = 2 ;
V_122 [ 6 ] . V_37 = V_53 ;
V_40 = F_17 ( V_44 , V_122 [ 6 ] . V_36 ,
V_45 . V_46 ) ;
V_40 [ 0 ] = 0x01 ;
F_20 ( V_44 , V_122 [ 6 ] . V_36 ,
V_45 . V_57 ) ;
F_20 ( V_44 , V_122 [ 6 ] . V_36 ,
V_45 . V_60 ) ;
V_122 [ 7 ] . V_124 = 1 ;
V_122 [ 7 ] . V_37 = V_53 ;
V_40 = F_17 ( V_44 , V_122 [ 7 ] . V_36 ,
V_45 . V_46 ) ;
V_40 [ 0 ] = 0x01 ;
F_20 ( V_44 , V_122 [ 7 ] . V_36 ,
V_45 . V_57 ) ;
V_122 [ 8 ] . V_124 = 0 ;
V_122 [ 8 ] . V_37 = V_53 ;
V_40 = F_17 ( V_44 , V_122 [ 8 ] . V_36 ,
V_45 . V_46 ) ;
V_40 [ 0 ] = 0x01 ;
V_15 -> V_17 . main = F_59 ( V_15 -> V_125 , 1 ,
V_126 ,
9 , V_122 ) ;
F_10 ( V_122 ) ;
return V_15 -> V_17 . main ? 0 : - V_65 ;
}
static void F_60 ( struct V_14 * V_15 )
{
F_61 ( V_15 -> V_17 . main ) ;
}
static int F_62 ( struct V_14 * V_15 )
{
struct V_121 * V_122 ;
V_122 = F_58 ( 2 , sizeof( * V_122 ) , V_123 ) ;
if ( ! V_122 )
return - V_65 ;
V_122 [ 0 ] . V_124 = 12 ;
V_122 [ 0 ] . V_37 = V_53 ;
F_20 ( V_44 , V_122 [ 0 ] . V_36 ,
V_45 . V_72 ) ;
F_20 ( V_44 , V_122 [ 0 ] . V_36 ,
V_45 . V_79 ) ;
V_122 [ 1 ] . V_124 = 1 ;
V_122 [ 1 ] . V_37 = V_53 ;
F_20 ( V_44 , V_122 [ 1 ] . V_36 ,
V_45 . V_72 ) ;
V_15 -> V_17 . V_74 = F_59 ( V_15 -> V_125 , 0 ,
V_126 ,
2 , V_122 ) ;
F_10 ( V_122 ) ;
return V_15 -> V_17 . V_74 ? 0 : - V_65 ;
}
static void F_63 ( struct V_14 * V_15 )
{
F_61 ( V_15 -> V_17 . V_74 ) ;
}
int F_64 ( struct V_14 * V_15 )
{
int V_43 ;
V_43 = F_57 ( V_15 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_62 ( V_15 ) ;
if ( V_43 )
goto V_127;
return 0 ;
V_127:
F_60 ( V_15 ) ;
return V_43 ;
}
void F_65 ( struct V_14 * V_15 )
{
F_63 ( V_15 ) ;
F_60 ( V_15 ) ;
}
