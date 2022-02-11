static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 V_8 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
F_3 ( & V_6 -> V_9 ) ;
V_6 -> V_10 -> V_11 ( V_2 , & V_8 . V_12 ) ;
F_4 ( & V_6 -> V_9 ) ;
memcpy ( V_4 , & V_8 . V_12 , sizeof( * V_4 ) ) ;
}
static T_1 F_5 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_6 ( L_1 , V_14 -> V_15 , V_14 -> V_16 ) ;
if ( F_7 ( V_14 -> V_16 < V_17 ) ) {
if ( F_8 ( V_14 , V_17 ) )
return V_18 ;
F_9 ( V_14 , V_17 - V_14 -> V_16 ) ;
}
F_10 ( V_6 , V_14 ) ;
return V_6 -> V_10 -> V_19 ( V_14 , V_2 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 , struct V_13 * V_14 ,
void * V_20 ,
T_3 V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_22 * V_23 ;
int V_24 ;
V_23 = F_12 ( V_14 , sizeof( * V_23 ) ) ;
V_23 -> V_25 = F_13 ( V_6 , V_14 ) ;
V_23 -> V_26 = F_14 ( V_6 , V_14 ) ;
V_24 = V_6 -> V_10 -> V_27 ( V_2 , V_14 ,
V_20 , V_21 ) ;
F_15 ( V_14 , sizeof( * V_23 ) ) ;
return V_24 ;
}
void F_16 ( struct V_5 * V_6 )
{
struct V_28 * V_29 = & V_6 -> V_29 ;
struct V_30 * V_31 = F_17 ( V_6 -> V_2 ) ;
T_4 V_32 [ V_33 ] = { 0 } ;
struct V_1 * V_2 = V_6 -> V_2 ;
T_4 V_34 , V_35 = 0 ;
T_2 V_36 ;
if ( memcmp ( V_29 -> V_37 . V_38 , V_6 -> V_39 ,
F_18 ( V_29 -> V_37 . V_38 ) ) ) {
struct V_40 V_41 ;
memcpy ( V_41 . V_42 , V_29 -> V_37 . V_38 ,
F_18 ( V_29 -> V_37 . V_38 ) ) ;
F_19 ( & V_6 -> V_43 ) ;
F_20 ( V_2 , & V_41 ) ;
memcpy ( V_6 -> V_39 ,
V_29 -> V_37 . V_38 , V_44 ) ;
F_21 ( & V_6 -> V_43 ) ;
}
V_31 -> V_45 ( V_2 , V_29 -> V_46 . V_47 ) ;
F_22 () ;
V_2 -> V_48 = F_23 (unsigned int, info->vesw.eth_mtu_non_vlan,
netdev->min_mtu) ;
if ( V_2 -> V_49 > V_2 -> V_48 )
F_24 ( V_2 , V_2 -> V_48 ) ;
F_25 () ;
V_36 = V_29 -> V_46 . V_50 ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
if ( V_36 & 1 )
V_32 [ V_35 ++ ] = V_34 ;
V_36 >>= 1 ;
}
for ( V_34 = 0 ; V_34 < V_51 ; V_34 ++ )
V_6 -> V_52 [ V_34 ] = V_35 ? V_32 [ V_34 % V_35 ] :
V_53 ;
if ( V_29 -> V_37 . V_54 == V_55 ) {
V_29 -> V_37 . V_56 = V_55 ;
F_26 ( V_2 ) ;
} else {
V_29 -> V_37 . V_56 = V_57 ;
F_27 ( V_2 ) ;
}
}
static inline void F_28 ( struct V_5 * V_6 )
{
V_6 -> V_29 . V_37 . V_58 = V_59 ;
V_6 -> V_29 . V_37 . V_60 = V_61 ;
V_6 -> V_29 . V_37 . V_54 = V_57 ;
V_6 -> V_29 . V_37 . V_62 = V_63 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_64 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_40 * V_65 = V_64 ;
int V_24 ;
if ( ! memcmp ( V_2 -> V_66 , V_65 -> V_42 , V_44 ) )
return 0 ;
F_19 ( & V_6 -> V_43 ) ;
V_24 = F_20 ( V_2 , V_64 ) ;
F_21 ( & V_6 -> V_43 ) ;
if ( V_24 )
return V_24 ;
V_6 -> V_29 . V_37 . V_67 ++ ;
F_30 ( V_6 ,
V_68 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , T_4 V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
T_5 * V_74 ;
T_5 V_75 , V_76 = 0 ;
switch ( V_69 ) {
case V_68 :
V_73 = & V_2 -> V_77 ;
V_6 -> V_29 . V_37 . V_67 ++ ;
V_74 = & V_6 -> V_78 ;
break;
case V_79 :
V_73 = & V_2 -> V_80 ;
V_6 -> V_29 . V_37 . V_81 ++ ;
V_74 = & V_6 -> V_82 ;
break;
default:
return;
}
F_32 (ha, hw_list) {
V_76 = F_33 ( V_76 , V_71 -> V_64 , V_44 ) ;
}
V_75 = F_34 ( V_73 ) * V_44 ;
V_76 = ~ F_33 ( V_76 , ( void * ) & V_75 , sizeof( V_75 ) ) ;
if ( V_76 != * V_74 ) {
* V_74 = V_76 ;
F_30 ( V_6 , V_69 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
F_31 ( V_2 ,
V_68 ) ;
F_31 ( V_2 ,
V_79 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_24 ;
V_24 = V_6 -> V_10 -> V_83 ( V_6 -> V_2 ) ;
if ( V_24 ) {
F_6 ( L_2 , V_24 ) ;
return V_24 ;
}
V_6 -> V_29 . V_37 . V_62 = V_84 ;
F_30 ( V_6 ,
V_85 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_24 ;
V_24 = V_6 -> V_10 -> V_86 ( V_6 -> V_2 ) ;
if ( V_24 ) {
F_6 ( L_3 , V_24 ) ;
return V_24 ;
}
V_6 -> V_29 . V_37 . V_62 = V_63 ;
F_30 ( V_6 ,
V_85 ) ;
return 0 ;
}
struct V_5 * F_38 ( struct V_87 * V_88 ,
T_4 V_32 , T_4 V_89 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
int V_24 ;
V_2 = V_88 -> V_90 ( V_88 , V_32 ,
V_91 ,
L_4 , V_92 ,
V_93 ) ;
if ( ! V_2 )
return F_39 ( - V_94 ) ;
else if ( F_40 ( V_2 ) )
return F_41 ( V_2 ) ;
V_31 = F_17 ( V_2 ) ;
V_6 = F_42 ( sizeof( * V_6 ) , V_95 ) ;
if ( ! V_6 ) {
V_24 = - V_94 ;
goto V_96;
}
V_31 -> V_97 = V_6 ;
V_31 -> V_98 = V_88 ;
V_31 -> V_32 = V_32 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_88 = V_88 ;
V_6 -> V_32 = V_32 ;
V_6 -> V_89 = V_89 ;
V_6 -> V_10 = V_2 -> V_99 ;
V_2 -> V_99 = & V_100 ;
V_2 -> V_101 |= V_102 ;
V_2 -> V_103 += V_104 ;
F_43 ( & V_6 -> V_43 ) ;
F_43 ( & V_6 -> V_105 ) ;
F_44 ( & V_6 -> V_9 ) ;
F_45 ( V_2 , V_88 -> V_106 . V_107 ) ;
F_46 ( V_2 ) ;
F_28 ( V_6 ) ;
V_24 = F_47 ( V_2 ) ;
if ( V_24 )
goto V_108;
F_48 ( V_2 ) ;
F_27 ( V_2 ) ;
F_49 ( L_5 ) ;
return V_6 ;
V_108:
F_50 ( & V_6 -> V_43 ) ;
F_50 ( & V_6 -> V_105 ) ;
F_51 ( V_6 ) ;
V_96:
V_31 -> V_109 ( V_2 ) ;
return F_39 ( V_24 ) ;
}
void F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_30 * V_31 = F_17 ( V_2 ) ;
F_49 ( L_6 ) ;
F_53 ( V_2 ) ;
F_54 ( V_6 ) ;
F_50 ( & V_6 -> V_43 ) ;
F_50 ( & V_6 -> V_105 ) ;
F_51 ( V_6 ) ;
V_31 -> V_109 ( V_2 ) ;
}
