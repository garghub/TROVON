static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static const struct V_5
* F_4 ( enum V_6 V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_9 ) ; V_8 ++ )
if ( V_9 [ V_8 ] . V_7 == V_7 )
return V_9 + V_8 ;
return NULL ;
}
static int F_6 ( struct V_2 * V_3 , T_1 V_10 , T_2 * V_11 )
{
int V_12 ;
unsigned char V_13 [ 2 ] = { V_10 >> 8 , V_10 & 0xff } ;
V_12 = F_7 ( V_3 , V_13 , 2 ) ;
if ( V_12 < 2 ) {
F_8 ( & V_3 -> V_14 , L_1 ,
V_15 , V_10 ) ;
return V_12 < 0 ? V_12 : - V_16 ;
}
V_12 = F_9 ( V_3 , V_11 , 1 ) ;
if ( V_12 < 1 ) {
F_8 ( & V_3 -> V_14 , L_1 ,
V_15 , V_10 ) ;
return V_12 < 0 ? V_12 : - V_16 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_10 , T_2 V_11 )
{
int V_12 ;
unsigned char V_13 [ 3 ] = { V_10 >> 8 , V_10 & 0xff , V_11 } ;
V_12 = F_7 ( V_3 , V_13 , 3 ) ;
if ( V_12 < 3 ) {
F_8 ( & V_3 -> V_14 , L_2 ,
V_15 , V_10 ) ;
return V_12 < 0 ? V_12 : - V_16 ;
}
return 0 ;
}
static int F_11 ( struct V_17 * V_18 , struct V_19 * V_10 )
{
struct V_2 * V_3 = F_12 ( V_18 ) ;
int V_12 ;
T_2 V_11 ;
if ( V_10 -> V_10 & ~ 0xffff )
return - V_20 ;
V_10 -> V_21 = 1 ;
V_12 = F_6 ( V_3 , V_10 -> V_10 , & V_11 ) ;
if ( ! V_12 )
V_10 -> V_11 = ( V_22 ) V_11 ;
return V_12 ;
}
static int F_13 ( struct V_17 * V_18 , struct V_19 * V_10 )
{
struct V_2 * V_3 = F_12 ( V_18 ) ;
if ( V_10 -> V_10 & ~ 0xffff || V_10 -> V_11 & ~ 0xff )
return - V_20 ;
return F_10 ( V_3 , V_10 -> V_10 , V_10 -> V_11 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_23 * V_24 )
{
while ( V_24 -> V_25 != 0xffff || V_24 -> V_26 != 0xff ) {
int V_12 = F_10 ( V_3 , V_24 -> V_25 , V_24 -> V_26 ) ;
if ( V_12 < 0 )
return V_12 ;
V_24 ++ ;
}
F_15 ( & V_3 -> V_14 , L_3 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
int V_12 ;
T_2 V_27 = ( ( V_28 - V_29 ) / 2 ) >> 8 ;
T_2 V_30 = ( ( V_28 - V_29 ) / 2 ) & 0xff ;
T_2 V_31 = ( ( V_32 - V_33 ) / 2 ) >> 8 ;
T_2 V_34 = ( ( V_32 - V_33 ) / 2 ) & 0xff ;
T_2 V_35 = V_29 >> 8 ;
T_2 V_36 = V_29 & 0xff ;
T_2 V_37 = V_33 >> 8 ;
T_2 V_38 = V_33 & 0xff ;
T_2 V_39 = V_40 >> 8 ;
T_2 V_41 = V_40 & 0xff ;
T_2 V_42 = V_43 >> 8 ;
T_2 V_44 = V_43 & 0xff ;
V_12 = F_10 ( V_3 , V_45 , V_27 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_46 , V_30 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_47 , V_31 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_48 , V_34 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_49 , V_35 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_50 , V_36 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_51 , V_37 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_52 , V_38 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_53 , V_35 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_54 , V_36 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_55 , V_37 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_56 , V_38 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_57 , V_39 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_58 , V_41 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_59 , V_42 ) ;
if ( ! V_12 )
V_12 = F_10 ( V_3 , V_60 , V_44 ) ;
return V_12 ;
}
static int F_17 ( struct V_17 * V_18 ,
struct V_61 * V_62 )
{
const struct V_5 * V_63 = F_4 ( V_62 -> V_7 ) ;
F_15 ( V_18 -> V_64 -> V_14 , L_4 ,
V_15 , V_62 -> V_7 , V_62 -> V_65 , V_62 -> V_66 ) ;
if ( ! V_63 ) {
V_62 -> V_7 = V_9 [ 0 ] . V_7 ;
V_62 -> V_67 = V_9 [ 0 ] . V_67 ;
}
V_62 -> V_65 = V_29 ;
V_62 -> V_66 = V_33 ;
V_62 -> V_68 = V_69 ;
return 0 ;
}
static int F_18 ( struct V_17 * V_18 ,
struct V_61 * V_62 )
{
struct V_2 * V_3 = F_12 ( V_18 ) ;
struct V_1 * V_70 = F_1 ( V_3 ) ;
F_15 ( V_18 -> V_64 -> V_14 , L_5 , V_15 , V_62 -> V_7 ) ;
if ( ! F_4 ( V_62 -> V_7 ) )
return - V_20 ;
F_17 ( V_18 , V_62 ) ;
V_70 -> V_63 = F_4 ( V_62 -> V_7 ) ;
F_14 ( V_3 , V_71 ) ;
F_16 ( V_3 ) ;
F_14 ( V_3 , V_72 ) ;
return 0 ;
}
static int F_19 ( struct V_17 * V_18 ,
struct V_61 * V_62 )
{
struct V_2 * V_3 = F_12 ( V_18 ) ;
struct V_1 * V_70 = F_1 ( V_3 ) ;
const struct V_5 * V_63 = V_70 -> V_63 ;
V_62 -> V_7 = V_63 -> V_7 ;
V_62 -> V_67 = V_63 -> V_67 ;
V_62 -> V_65 = V_29 ;
V_62 -> V_66 = V_33 ;
V_62 -> V_68 = V_69 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 , unsigned int V_73 ,
enum V_6 * V_7 )
{
if ( V_73 >= F_5 ( V_9 ) )
return - V_20 ;
* V_7 = V_9 [ V_73 ] . V_7 ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_12 ( V_18 ) ;
if ( V_75 -> V_76 . type != V_77 )
return - V_20 ;
if ( V_75 -> V_76 . V_78 != V_3 -> V_78 )
return - V_79 ;
V_75 -> V_80 = V_81 ;
V_75 -> V_82 = 0 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 , struct V_83 * V_84 )
{
struct V_85 * V_86 = & V_84 -> V_87 ;
V_84 -> type = V_88 ;
V_86 -> V_89 = 0 ;
V_86 -> V_90 = 0 ;
V_86 -> V_65 = V_29 ;
V_86 -> V_66 = V_33 ;
return 0 ;
}
static int F_23 ( struct V_17 * V_18 , struct V_91 * V_84 )
{
V_84 -> V_92 . V_90 = 0 ;
V_84 -> V_92 . V_89 = 0 ;
V_84 -> V_92 . V_65 = V_29 ;
V_84 -> V_92 . V_66 = V_33 ;
V_84 -> V_93 = V_84 -> V_92 ;
V_84 -> type = V_88 ;
V_84 -> V_94 . V_95 = 1 ;
V_84 -> V_94 . V_96 = 1 ;
return 0 ;
}
static unsigned long F_24 ( struct V_97 * V_98 )
{
return 0 ;
}
static int F_25 ( struct V_97 * V_98 ,
unsigned long V_99 )
{
return - V_20 ;
}
static int F_26 ( struct V_97 * V_98 ,
struct V_2 * V_3 )
{
int V_12 ;
T_2 V_100 , V_101 ;
T_1 V_75 ;
V_12 = F_6 ( V_3 , V_102 , & V_100 ) ;
if ( V_12 < 0 )
return V_12 ;
V_75 = V_100 << 8 ;
V_12 = F_6 ( V_3 , V_103 , & V_101 ) ;
if ( V_12 < 0 )
return V_12 ;
V_75 |= V_101 ;
F_27 ( & V_3 -> V_14 , L_6 , V_75 ) ;
if ( V_75 != 0x5642 )
return - V_79 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
const struct V_104 * V_105 )
{
struct V_1 * V_70 ;
struct V_97 * V_98 = V_3 -> V_14 . V_106 ;
struct V_107 * V_108 ;
int V_12 ;
if ( ! V_98 ) {
F_8 ( & V_3 -> V_14 , L_7 ) ;
return - V_20 ;
}
V_108 = F_29 ( V_98 ) ;
if ( ! V_108 ) {
F_8 ( & V_3 -> V_14 , L_8 ) ;
return - V_20 ;
}
V_70 = F_30 ( sizeof( struct V_1 ) , V_109 ) ;
if ( ! V_70 )
return - V_110 ;
F_31 ( & V_70 -> V_4 , V_3 , & V_111 ) ;
V_98 -> V_112 = & V_113 ;
V_70 -> V_63 = & V_9 [ 0 ] ;
V_12 = F_26 ( V_98 , V_3 ) ;
if ( V_12 < 0 )
goto error;
return 0 ;
error:
V_98 -> V_112 = NULL ;
F_32 ( V_70 ) ;
return V_12 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_70 = F_1 ( V_3 ) ;
struct V_97 * V_98 = V_3 -> V_14 . V_106 ;
struct V_107 * V_108 = F_29 ( V_98 ) ;
V_98 -> V_112 = NULL ;
if ( V_108 -> V_114 )
V_108 -> V_114 ( V_108 ) ;
F_32 ( V_70 ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
return F_35 ( & V_115 ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_115 ) ;
}
