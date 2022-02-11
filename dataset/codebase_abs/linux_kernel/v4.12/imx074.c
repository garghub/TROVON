static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static const struct V_5 * F_4 ( T_1 V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_5 ( V_8 ) ; V_7 ++ )
if ( V_8 [ V_7 ] . V_6 == V_6 )
return V_8 + V_7 ;
return NULL ;
}
static int F_6 ( struct V_2 * V_3 , const T_2 V_9 , const T_3 V_10 )
{
struct V_11 * V_12 = V_3 -> V_13 ;
struct V_14 V_15 ;
unsigned char V_16 [ 3 ] ;
int V_17 ;
V_15 . V_9 = V_3 -> V_9 ;
V_15 . V_18 = V_16 ;
V_15 . V_19 = 3 ;
V_15 . V_20 = 0 ;
V_16 [ 0 ] = V_9 >> 8 ;
V_16 [ 1 ] = V_9 & 0xff ;
V_16 [ 2 ] = V_10 ;
V_17 = F_7 ( V_12 , & V_15 , 1 ) ;
F_8 ( 2 ) ;
return V_17 == 1 ? 0 : - V_21 ;
}
static int F_9 ( struct V_2 * V_3 , const T_2 V_9 )
{
T_3 V_18 [ 2 ] = { V_9 >> 8 , V_9 & 0xff } ;
int V_17 ;
struct V_14 V_22 [] = {
{
. V_9 = V_3 -> V_9 ,
. V_20 = 0 ,
. V_19 = 2 ,
. V_18 = V_18 ,
} , {
. V_9 = V_3 -> V_9 ,
. V_20 = V_23 ,
. V_19 = 2 ,
. V_18 = V_18 ,
} ,
} ;
V_17 = F_7 ( V_3 -> V_13 , V_22 , F_5 ( V_22 ) ) ;
if ( V_17 < 0 ) {
F_10 ( & V_3 -> V_24 , L_1 ,
V_9 , V_3 -> V_9 ) ;
return V_17 ;
}
return V_18 [ 0 ] & 0xff ;
}
static int F_11 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = & V_30 -> V_30 ;
const struct V_5 * V_33 = F_4 ( V_32 -> V_6 ) ;
struct V_2 * V_3 = F_12 ( V_26 ) ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
if ( V_30 -> V_35 )
return - V_36 ;
F_13 ( V_26 -> V_37 -> V_24 , L_2 , V_38 , V_32 -> V_6 ) ;
if ( ! V_33 ) {
if ( V_30 -> V_39 == V_40 )
return - V_36 ;
V_32 -> V_6 = V_8 [ 0 ] . V_6 ;
V_32 -> V_41 = V_8 [ 0 ] . V_41 ;
}
V_32 -> V_42 = V_43 ;
V_32 -> V_44 = V_45 ;
V_32 -> V_46 = V_47 ;
if ( V_30 -> V_39 == V_40 )
V_34 -> V_33 = V_33 ;
else
V_28 -> V_48 = * V_32 ;
return 0 ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = & V_30 -> V_30 ;
struct V_2 * V_3 = F_12 ( V_26 ) ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
const struct V_5 * V_33 = V_34 -> V_33 ;
if ( V_30 -> V_35 )
return - V_36 ;
V_32 -> V_6 = V_33 -> V_6 ;
V_32 -> V_41 = V_33 -> V_41 ;
V_32 -> V_42 = V_43 ;
V_32 -> V_44 = V_45 ;
V_32 -> V_46 = V_47 ;
return 0 ;
}
static int F_15 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_49 * V_50 )
{
if ( V_50 -> V_39 != V_40 )
return - V_36 ;
V_50 -> V_51 . V_52 = 0 ;
V_50 -> V_51 . V_53 = 0 ;
V_50 -> V_51 . V_42 = V_43 ;
V_50 -> V_51 . V_44 = V_45 ;
switch ( V_50 -> V_54 ) {
case V_55 :
case V_56 :
case V_57 :
return 0 ;
default:
return - V_36 ;
}
}
static int F_16 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_58 * V_6 )
{
if ( V_6 -> V_35 ||
( unsigned int ) V_6 -> V_59 >= F_5 ( V_8 ) )
return - V_36 ;
V_6 -> V_6 = V_8 [ V_6 -> V_59 ] . V_6 ;
return 0 ;
}
static int F_17 ( struct V_25 * V_26 , int V_60 )
{
struct V_2 * V_3 = F_12 ( V_26 ) ;
return F_6 ( V_3 , V_61 , ! ! V_60 ) ;
}
static int F_18 ( struct V_25 * V_26 , int V_62 )
{
struct V_2 * V_3 = F_12 ( V_26 ) ;
struct V_63 * V_64 = F_19 ( V_3 ) ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
return F_20 ( & V_3 -> V_24 , V_64 , V_34 -> V_65 , V_62 ) ;
}
static int F_21 ( struct V_25 * V_26 ,
struct V_66 * V_28 )
{
V_28 -> type = V_67 ;
V_28 -> V_20 = V_68 |
V_69 |
V_70 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_25 * V_4 = F_3 ( V_3 ) ;
int V_17 ;
T_2 V_71 ;
V_17 = F_18 ( V_4 , 1 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_9 ( V_3 , 0 ) ;
if ( V_17 < 0 )
goto V_72;
V_71 = V_17 << 8 ;
V_17 = F_9 ( V_3 , 1 ) ;
if ( V_17 < 0 )
goto V_72;
V_71 |= V_17 ;
F_23 ( & V_3 -> V_24 , L_3 , V_71 ) ;
if ( V_71 != 0x74 ) {
V_17 = - V_73 ;
goto V_72;
}
F_6 ( V_3 , V_74 , 0x2D ) ;
F_6 ( V_3 , V_75 , 0x02 ) ;
F_6 ( V_3 , V_76 , 0x4B ) ;
F_6 ( V_3 , 0x3024 , 0x00 ) ;
F_6 ( V_3 , V_77 , 0x00 ) ;
F_6 ( V_3 , 0x0112 , 0x08 ) ;
F_6 ( V_3 , 0x0113 , 0x08 ) ;
F_6 ( V_3 , V_78 , 0x80 ) ;
F_6 ( V_3 , V_79 , 0x08 ) ;
F_6 ( V_3 , 0x3015 , 0x37 ) ;
F_6 ( V_3 , 0x301C , 0x01 ) ;
F_6 ( V_3 , 0x302C , 0x05 ) ;
F_6 ( V_3 , 0x3031 , 0x26 ) ;
F_6 ( V_3 , 0x3041 , 0x60 ) ;
F_6 ( V_3 , 0x3051 , 0x24 ) ;
F_6 ( V_3 , 0x3053 , 0x34 ) ;
F_6 ( V_3 , 0x3057 , 0xC0 ) ;
F_6 ( V_3 , 0x305C , 0x09 ) ;
F_6 ( V_3 , 0x305D , 0x07 ) ;
F_6 ( V_3 , 0x3060 , 0x30 ) ;
F_6 ( V_3 , 0x3065 , 0x00 ) ;
F_6 ( V_3 , 0x30AA , 0x08 ) ;
F_6 ( V_3 , 0x30AB , 0x1C ) ;
F_6 ( V_3 , 0x30B0 , 0x32 ) ;
F_6 ( V_3 , 0x30B2 , 0x83 ) ;
F_6 ( V_3 , 0x30D3 , 0x04 ) ;
F_6 ( V_3 , 0x3106 , 0x78 ) ;
F_6 ( V_3 , 0x310C , 0x82 ) ;
F_6 ( V_3 , 0x3304 , 0x05 ) ;
F_6 ( V_3 , 0x3305 , 0x04 ) ;
F_6 ( V_3 , 0x3306 , 0x11 ) ;
F_6 ( V_3 , 0x3307 , 0x02 ) ;
F_6 ( V_3 , 0x3308 , 0x0C ) ;
F_6 ( V_3 , 0x3309 , 0x06 ) ;
F_6 ( V_3 , 0x330A , 0x08 ) ;
F_6 ( V_3 , 0x330B , 0x04 ) ;
F_6 ( V_3 , 0x330C , 0x08 ) ;
F_6 ( V_3 , 0x330D , 0x06 ) ;
F_6 ( V_3 , 0x330E , 0x01 ) ;
F_6 ( V_3 , 0x3381 , 0x00 ) ;
F_6 ( V_3 , V_80 , 0x06 ) ;
F_6 ( V_3 , V_81 , 0x48 ) ;
F_6 ( V_3 , V_82 , 0x00 ) ;
F_6 ( V_3 , V_83 , 0x2F ) ;
F_6 ( V_3 , V_84 , 0x08 ) ;
F_6 ( V_3 , V_85 , 0x38 ) ;
F_6 ( V_3 , V_86 , 0x06 ) ;
F_6 ( V_3 , V_87 , 0x18 ) ;
F_6 ( V_3 , V_88 , 0x01 ) ;
F_6 ( V_3 , V_89 , 0x03 ) ;
F_6 ( V_3 , V_90 , 0x01 ) ;
F_6 ( V_3 , V_91 , 0x03 ) ;
F_6 ( V_3 , V_92 , 0x00 ) ;
F_6 ( V_3 , V_93 , 0x16 ) ;
F_6 ( V_3 , V_94 , 0x24 ) ;
F_6 ( V_3 , V_95 , 0x53 ) ;
F_6 ( V_3 , V_96 , 0x00 ) ;
F_6 ( V_3 , V_97 , 0x80 ) ;
F_6 ( V_3 , V_98 , 0x00 ) ;
F_6 ( V_3 , V_99 , 0x00 ) ;
V_17 = 0 ;
V_72:
F_18 ( V_4 , 0 ) ;
return V_17 ;
}
static int F_24 ( struct V_2 * V_3 ,
const struct V_100 * V_101 )
{
struct V_1 * V_34 ;
struct V_11 * V_13 = F_25 ( V_3 -> V_24 . V_102 ) ;
struct V_63 * V_64 = F_19 ( V_3 ) ;
int V_17 ;
if ( ! V_64 ) {
F_26 ( & V_3 -> V_24 , L_4 ) ;
return - V_36 ;
}
if ( ! F_27 ( V_13 , V_103 ) ) {
F_10 ( & V_13 -> V_24 ,
L_5 ) ;
return - V_21 ;
}
V_34 = F_28 ( & V_3 -> V_24 , sizeof( struct V_1 ) , V_104 ) ;
if ( ! V_34 )
return - V_105 ;
F_29 ( & V_34 -> V_4 , V_3 , & V_106 ) ;
V_34 -> V_33 = & V_8 [ 0 ] ;
V_34 -> V_65 = F_30 ( & V_3 -> V_24 , L_6 ) ;
if ( F_31 ( V_34 -> V_65 ) ) {
F_23 ( & V_3 -> V_24 , L_7 , F_32 ( V_34 -> V_65 ) ) ;
return - V_107 ;
}
V_17 = F_33 ( & V_3 -> V_24 , V_64 ) ;
if ( V_17 < 0 )
goto V_108;
V_17 = F_22 ( V_3 ) ;
if ( V_17 < 0 )
goto V_109;
V_17 = F_34 ( & V_34 -> V_4 ) ;
if ( ! V_17 )
return 0 ;
V_108:
V_109:
F_35 ( V_34 -> V_65 ) ;
return V_17 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_63 * V_64 = F_19 ( V_3 ) ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_37 ( & V_34 -> V_4 ) ;
F_35 ( V_34 -> V_65 ) ;
if ( V_64 -> V_110 )
V_64 -> V_110 ( V_64 ) ;
return 0 ;
}
