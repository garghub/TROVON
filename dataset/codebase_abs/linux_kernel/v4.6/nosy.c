static inline struct V_1 *
F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
return V_2 ;
}
static void
F_3 ( struct V_3 * V_3 )
{
F_4 ( F_5 ( V_3 , struct V_1 , V_3 ) ) ;
}
static inline void
F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_3 , F_3 ) ;
}
static int
F_8 ( struct V_4 * V_5 , T_1 V_6 )
{
V_5 -> V_7 = F_9 ( V_6 , V_8 ) ;
if ( V_5 -> V_7 == NULL )
return - V_9 ;
V_5 -> V_10 = (struct V_11 * ) V_5 -> V_7 ;
V_5 -> V_12 = (struct V_11 * ) V_5 -> V_7 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_13 = 0 ;
F_10 ( & V_5 -> V_14 , 0 ) ;
F_11 ( & V_5 -> V_15 ) ;
return 0 ;
}
static void
F_12 ( struct V_4 * V_5 )
{
F_4 ( V_5 -> V_7 ) ;
}
static int
F_13 ( struct V_16 * V_16 , char T_2 * V_7 , T_1 V_17 )
{
struct V_4 * V_5 = & V_16 -> V_5 ;
T_1 V_18 ;
char * V_19 ;
if ( F_14 ( V_5 -> V_15 ,
F_15 ( & V_5 -> V_14 ) > 0 ) ||
F_16 ( & V_16 -> V_2 -> V_20 ) )
return - V_21 ;
if ( F_15 ( & V_5 -> V_14 ) == 0 )
return - V_22 ;
V_19 = V_5 -> V_7 + V_5 -> V_6 ;
V_18 = V_5 -> V_10 -> V_18 ;
if ( & V_5 -> V_10 -> V_7 [ V_18 ] < V_19 ) {
if ( F_17 ( V_7 , V_5 -> V_10 -> V_7 , V_18 ) )
return - V_23 ;
V_5 -> V_10 = (struct V_11 * ) & V_5 -> V_10 -> V_7 [ V_18 ] ;
} else {
T_1 V_24 = V_19 - V_5 -> V_10 -> V_7 ;
if ( F_17 ( V_7 , V_5 -> V_10 -> V_7 , V_24 ) )
return - V_23 ;
if ( F_17 ( V_7 + V_24 , V_5 -> V_7 , V_18 - V_24 ) )
return - V_23 ;
V_5 -> V_10 = (struct V_11 * ) & V_5 -> V_7 [ V_18 - V_24 ] ;
}
F_18 ( sizeof( struct V_11 ) + V_18 , & V_5 -> V_14 ) ;
return V_18 ;
}
static void
F_19 ( struct V_4 * V_5 , void * V_7 , T_1 V_18 )
{
char * V_19 ;
V_5 -> V_25 ++ ;
if ( V_5 -> V_6 <
F_15 ( & V_5 -> V_14 ) + sizeof( struct V_11 ) + V_18 ) {
V_5 -> V_13 ++ ;
return;
}
V_19 = V_5 -> V_7 + V_5 -> V_6 ;
V_5 -> V_12 -> V_18 = V_18 ;
if ( & V_5 -> V_12 -> V_7 [ V_18 ] < V_19 ) {
memcpy ( V_5 -> V_12 -> V_7 , V_7 , V_18 ) ;
V_5 -> V_12 = (struct V_11 * ) & V_5 -> V_12 -> V_7 [ V_18 ] ;
} else {
T_1 V_24 = V_19 - V_5 -> V_12 -> V_7 ;
memcpy ( V_5 -> V_12 -> V_7 , V_7 , V_24 ) ;
memcpy ( V_5 -> V_7 , V_7 + V_24 , V_18 - V_24 ) ;
V_5 -> V_12 = (struct V_11 * ) & V_5 -> V_7 [ V_18 - V_24 ] ;
}
F_20 ( sizeof( struct V_11 ) + V_18 , & V_5 -> V_14 ) ;
F_21 ( & V_5 -> V_15 ) ;
}
static inline void
F_22 ( struct V_1 * V_2 , int V_26 , T_3 V_7 )
{
F_23 ( V_7 , V_2 -> V_27 + V_26 ) ;
}
static inline T_3
F_24 ( struct V_1 * V_2 , int V_26 )
{
return F_25 ( V_2 -> V_27 + V_26 ) ;
}
static inline void
F_26 ( struct V_1 * V_2 , int V_26 , T_3 V_28 )
{
F_22 ( V_2 , V_26 , ( F_24 ( V_2 , V_26 ) | V_28 ) ) ;
}
static inline void
F_27 ( struct V_1 * V_2 , T_4 V_29 ,
int V_30 )
{
F_22 ( V_2 , V_31 + V_30 * 0x20 , V_29 ) ;
F_22 ( V_2 , V_32 + V_30 * 0x20 ,
V_33 | V_34 ) ;
}
static int
F_28 ( struct V_1 * V_2 , int V_35 , int V_36 )
{
if ( V_35 > 15 ) {
F_29 ( & V_2 -> V_37 -> V_38 ,
L_1 , V_35 ) ;
return - 1 ;
}
if ( V_36 > 0xff ) {
F_29 ( & V_2 -> V_37 -> V_38 ,
L_2 , V_36 ) ;
return - 1 ;
}
F_22 ( V_2 , V_39 , V_40 |
F_30 ( V_35 ) | F_31 ( V_36 ) ) ;
return 0 ;
}
static int
F_32 ( struct V_41 * V_41 , struct V_42 * V_42 )
{
int V_43 = F_33 ( V_41 ) ;
struct V_16 * V_16 ;
struct V_1 * V_44 , * V_2 = NULL ;
F_34 ( & V_45 ) ;
F_35 (tmp, &card_list, link)
if ( V_44 -> V_46 . V_43 == V_43 ) {
V_2 = F_1 ( V_44 ) ;
break;
}
F_36 ( & V_45 ) ;
if ( V_2 == NULL )
return - V_22 ;
V_16 = F_9 ( sizeof *V_16 , V_8 ) ;
if ( V_16 == NULL )
goto V_47;
V_16 -> V_48 = ~ 0 ;
V_16 -> V_2 = V_2 ;
F_37 ( & V_16 -> V_20 ) ;
if ( F_8 ( & V_16 -> V_5 , 128 * 1024 ) < 0 )
goto V_47;
V_42 -> V_49 = V_16 ;
return F_38 ( V_41 , V_42 ) ;
V_47:
F_4 ( V_16 ) ;
F_6 ( V_2 ) ;
return - V_9 ;
}
static int
F_39 ( struct V_41 * V_41 , struct V_42 * V_42 )
{
struct V_16 * V_16 = V_42 -> V_49 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_40 ( & V_2 -> V_50 ) ;
F_41 ( & V_16 -> V_20 ) ;
F_42 ( & V_2 -> V_50 ) ;
F_12 ( & V_16 -> V_5 ) ;
F_4 ( V_16 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static unsigned int
F_43 ( struct V_42 * V_42 , T_5 * V_51 )
{
struct V_16 * V_16 = V_42 -> V_49 ;
unsigned int V_52 = 0 ;
F_44 ( V_42 , & V_16 -> V_5 . V_15 , V_51 ) ;
if ( F_15 ( & V_16 -> V_5 . V_14 ) > 0 )
V_52 = V_53 | V_54 ;
if ( F_16 ( & V_16 -> V_2 -> V_20 ) )
V_52 |= V_55 ;
return V_52 ;
}
static T_6
F_45 ( struct V_42 * V_42 , char T_2 * V_5 , T_1 V_56 , T_7 * V_26 )
{
struct V_16 * V_16 = V_42 -> V_49 ;
return F_13 ( V_16 , V_5 , V_56 ) ;
}
static long
F_46 ( struct V_42 * V_42 , unsigned int V_57 , unsigned long V_58 )
{
struct V_16 * V_16 = V_42 -> V_49 ;
T_8 * V_50 = & V_16 -> V_2 -> V_50 ;
struct V_59 V_60 ;
switch ( V_57 ) {
case V_61 :
F_40 ( V_50 ) ;
V_60 . V_25 = V_16 -> V_5 . V_25 ;
V_60 . V_13 = V_16 -> V_5 . V_13 ;
F_42 ( V_50 ) ;
if ( F_17 ( ( void T_2 * ) V_58 , & V_60 , sizeof V_60 ) )
return - V_23 ;
else
return 0 ;
case V_62 :
F_40 ( V_50 ) ;
F_47 ( & V_16 -> V_20 , & V_16 -> V_2 -> V_63 ) ;
F_42 ( V_50 ) ;
return 0 ;
case V_64 :
F_40 ( V_50 ) ;
F_41 ( & V_16 -> V_20 ) ;
F_42 ( V_50 ) ;
return 0 ;
case V_65 :
F_40 ( V_50 ) ;
V_16 -> V_48 = V_58 ;
F_42 ( V_50 ) ;
return 0 ;
default:
return - V_66 ;
}
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_16 * V_16 ;
T_3 V_48 , V_67 , V_68 ;
T_1 V_18 ;
struct V_69 V_70 ;
V_18 = F_49 ( V_2 -> V_71 -> V_72 ) & 0x00001fff ;
V_67 = F_49 ( V_2 -> V_73 [ 1 ] ) >> 4 & 0xf ;
F_50 ( & V_70 ) ;
V_68 = V_70 . V_74 / V_75 ;
V_2 -> V_73 [ 0 ] = ( V_76 V_77 ) V_68 ;
if ( V_18 == V_78 )
V_48 = 1 << V_79 ;
else
V_48 = 1 << V_67 ;
F_51 ( & V_2 -> V_50 ) ;
F_35 (client, &lynx->client_list, link)
if ( V_16 -> V_48 & V_48 )
F_19 ( & V_16 -> V_5 ,
V_2 -> V_73 , V_18 + 4 ) ;
F_52 ( & V_2 -> V_50 ) ;
}
static void
F_53 ( struct V_1 * V_2 )
{
struct V_16 * V_16 ;
struct V_69 V_70 ;
T_3 V_68 ;
F_50 ( & V_70 ) ;
V_68 = V_70 . V_74 / V_75 ;
F_51 ( & V_2 -> V_50 ) ;
F_35 (client, &lynx->client_list, link)
F_19 ( & V_16 -> V_5 , & V_68 , 4 ) ;
F_52 ( & V_2 -> V_50 ) ;
}
static T_9
F_54 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
T_3 V_82 ;
V_82 = F_24 ( V_2 , V_83 ) ;
if ( V_82 == ~ 0 )
return V_84 ;
if ( ( V_82 & V_85 ) == 0 )
return V_84 ;
if ( ( V_82 & V_86 ) != 0 ) {
T_3 V_87 ;
V_87 = F_24 ( V_2 , V_88 ) ;
F_22 ( V_2 , V_88 , V_87 ) ;
if ( ( V_87 & V_89 ) > 0 )
F_53 ( V_2 ) ;
}
F_22 ( V_2 , V_83 , V_82 ) ;
if ( ( V_82 & V_90 ) > 0 ) {
F_48 ( V_2 ) ;
F_27 ( V_2 , V_2 -> V_91 , 0 ) ;
}
return V_92 ;
}
static void
F_55 ( struct V_93 * V_38 )
{
struct V_1 * V_2 = F_56 ( V_38 ) ;
struct V_16 * V_16 ;
F_34 ( & V_45 ) ;
F_41 ( & V_2 -> V_20 ) ;
F_57 ( & V_2 -> V_46 ) ;
F_36 ( & V_45 ) ;
F_22 ( V_2 , V_94 , 0 ) ;
F_58 ( V_2 -> V_37 -> V_80 , V_2 ) ;
F_40 ( & V_2 -> V_50 ) ;
F_35 (client, &lynx->client_list, link)
F_21 ( & V_16 -> V_5 . V_15 ) ;
F_42 ( & V_2 -> V_50 ) ;
F_59 ( V_2 -> V_37 , sizeof( struct V_95 ) ,
V_2 -> V_96 , V_2 -> V_91 ) ;
F_59 ( V_2 -> V_37 , sizeof( struct V_95 ) ,
V_2 -> V_71 , V_2 -> V_97 ) ;
F_59 ( V_2 -> V_37 , V_98 ,
V_2 -> V_73 , V_2 -> V_99 ) ;
F_60 ( V_2 -> V_27 ) ;
F_61 ( V_38 ) ;
F_6 ( V_2 ) ;
}
static int
F_62 ( struct V_93 * V_38 , const struct V_100 * V_101 )
{
struct V_1 * V_2 ;
T_3 V_102 , V_19 ;
int V_52 , V_103 ;
if ( F_63 ( V_38 , F_64 ( 32 ) ) ) {
F_29 ( & V_38 -> V_38 ,
L_3 ) ;
return - V_104 ;
}
if ( F_65 ( V_38 ) ) {
F_29 ( & V_38 -> V_38 , L_4 ) ;
return - V_104 ;
}
F_66 ( V_38 ) ;
V_2 = F_67 ( sizeof *V_2 , V_8 ) ;
if ( V_2 == NULL ) {
F_29 ( & V_38 -> V_38 , L_5 ) ;
V_52 = - V_9 ;
goto V_105;
}
V_2 -> V_37 = V_38 ;
F_68 ( V_38 , V_2 ) ;
F_69 ( & V_2 -> V_50 ) ;
F_37 ( & V_2 -> V_63 ) ;
F_70 ( & V_2 -> V_3 ) ;
V_2 -> V_27 = F_71 ( F_72 ( V_38 , 0 ) ,
V_106 ) ;
V_2 -> V_96 = F_73 ( V_2 -> V_37 ,
sizeof( struct V_95 ) , & V_2 -> V_91 ) ;
V_2 -> V_71 = F_73 ( V_2 -> V_37 ,
sizeof( struct V_95 ) , & V_2 -> V_97 ) ;
V_2 -> V_73 = F_73 ( V_2 -> V_37 ,
V_107 , & V_2 -> V_99 ) ;
if ( V_2 -> V_96 == NULL ||
V_2 -> V_71 == NULL ||
V_2 -> V_73 == NULL ) {
F_29 ( & V_38 -> V_38 , L_6 ) ;
V_52 = - V_9 ;
goto V_108;
}
V_2 -> V_96 -> V_109 = F_74 ( V_2 -> V_97 ) ;
V_2 -> V_71 -> V_109 = F_74 ( V_110 ) ;
V_2 -> V_71 -> V_111 = F_74 ( V_110 ) ;
V_2 -> V_71 -> V_5 [ 0 ] . V_112 =
F_74 ( V_113 | V_114 | 2044 ) ;
V_2 -> V_71 -> V_5 [ 0 ] . V_115 =
F_74 ( V_2 -> V_99 + 4 ) ;
V_102 = V_2 -> V_99 + 2048 ;
V_19 = V_2 -> V_99 + V_107 ;
for ( V_103 = 1 ; V_102 < V_19 ; V_103 ++ , V_102 += 2048 ) {
V_2 -> V_71 -> V_5 [ V_103 ] . V_112 =
F_74 ( V_113 | V_114 | 2048 ) ;
V_2 -> V_71 -> V_5 [ V_103 ] . V_115 = F_74 ( V_102 ) ;
}
V_2 -> V_71 -> V_5 [ V_103 - 1 ] . V_112 |= F_74 ( V_116 ) ;
F_26 ( V_2 , V_117 , V_118 ) ;
F_22 ( V_2 , V_32 , 0 ) ;
F_22 ( V_2 , V_119 , 0x00 << 24 ) ;
#if 0
if ((get_phy_reg(lynx, 2) & 0xe0) == 0xe0) {
lynx->phyic.reg_1394a = 1;
PRINT(KERN_INFO, lynx->id,
"found 1394a conform PHY (using extended register set)");
lynx->phyic.vendor = get_phy_vendorid(lynx);
lynx->phyic.product = get_phy_productid(lynx);
} else {
lynx->phyic.reg_1394a = 0;
PRINT(KERN_INFO, lynx->id, "found old 1394 PHY");
}
#endif
F_22 ( V_2 , V_120 , 255 ) ;
F_26 ( V_2 , V_94 , V_121 ) ;
F_22 ( V_2 , V_122 ,
V_123 | V_124 |
V_89 | V_125 |
V_126 | V_127 |
V_128 | V_129 |
V_130 | V_131 ) ;
F_28 ( V_2 , 4 , 0 ) ;
F_26 ( V_2 , V_132 , V_133 ) ;
F_27 ( V_2 , V_2 -> V_91 , 0 ) ;
if ( F_75 ( V_38 -> V_80 , F_54 , V_134 ,
V_135 , V_2 ) ) {
F_29 ( & V_38 -> V_38 ,
L_7 , V_38 -> V_80 ) ;
V_52 = - V_136 ;
goto V_108;
}
V_2 -> V_46 . V_137 = & V_38 -> V_38 ;
V_2 -> V_46 . V_43 = V_138 ;
V_2 -> V_46 . V_139 = L_8 ;
V_2 -> V_46 . V_140 = & V_141 ;
F_34 ( & V_45 ) ;
V_52 = F_76 ( & V_2 -> V_46 ) ;
if ( V_52 ) {
F_29 ( & V_38 -> V_38 , L_9 ) ;
F_36 ( & V_45 ) ;
goto V_142;
}
F_47 ( & V_2 -> V_20 , & V_143 ) ;
F_36 ( & V_45 ) ;
F_77 ( & V_38 -> V_38 ,
L_10 , V_38 -> V_80 ) ;
return 0 ;
V_142:
F_22 ( V_2 , V_94 , 0 ) ;
F_58 ( V_2 -> V_37 -> V_80 , V_2 ) ;
V_108:
if ( V_2 -> V_96 )
F_59 ( V_2 -> V_37 , sizeof( struct V_95 ) ,
V_2 -> V_96 , V_2 -> V_91 ) ;
if ( V_2 -> V_71 )
F_59 ( V_2 -> V_37 , sizeof( struct V_95 ) ,
V_2 -> V_71 , V_2 -> V_97 ) ;
if ( V_2 -> V_73 )
F_59 ( V_2 -> V_37 , V_98 ,
V_2 -> V_73 , V_2 -> V_99 ) ;
F_60 ( V_2 -> V_27 ) ;
F_4 ( V_2 ) ;
V_105:
F_61 ( V_38 ) ;
return V_52 ;
}
