static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static const struct V_5 * F_4 ( enum V_6 V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_9 ) ; V_8 ++ )
if ( V_9 [ V_8 ] . V_7 == V_7 )
return V_9 + V_8 ;
return NULL ;
}
static int F_6 ( struct V_2 * V_3 , const T_1 V_10 , const T_2 V_11 )
{
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_15 V_16 ;
unsigned char V_17 [ 3 ] ;
int V_18 ;
V_16 . V_10 = V_3 -> V_10 ;
V_16 . V_19 = V_17 ;
V_16 . V_20 = 3 ;
V_16 . V_21 = 0 ;
V_17 [ 0 ] = V_10 >> 8 ;
V_17 [ 1 ] = V_10 & 0xff ;
V_17 [ 2 ] = V_11 ;
V_18 = F_7 ( V_13 , & V_16 , 1 ) ;
F_8 ( 2 ) ;
return V_18 == 1 ? 0 : - V_22 ;
}
static int F_9 ( struct V_2 * V_3 , const T_1 V_10 )
{
T_2 V_19 [ 2 ] = { V_10 >> 8 , V_10 & 0xff } ;
int V_18 ;
struct V_15 V_23 [] = {
{
. V_10 = V_3 -> V_10 ,
. V_21 = 0 ,
. V_20 = 2 ,
. V_19 = V_19 ,
} , {
. V_10 = V_3 -> V_10 ,
. V_21 = V_24 ,
. V_20 = 2 ,
. V_19 = V_19 ,
} ,
} ;
V_18 = F_7 ( V_3 -> V_14 , V_23 , F_5 ( V_23 ) ) ;
if ( V_18 < 0 ) {
F_10 ( & V_3 -> V_25 , L_1 ,
V_10 , V_3 -> V_10 ) ;
return V_18 ;
}
return V_19 [ 0 ] & 0xff ;
}
static int F_11 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
const struct V_5 * V_30 = F_4 ( V_29 -> V_7 ) ;
F_12 ( V_27 -> V_31 -> V_25 , L_2 , V_32 , V_29 -> V_7 ) ;
if ( ! V_30 ) {
V_29 -> V_7 = V_9 [ 0 ] . V_7 ;
V_29 -> V_33 = V_9 [ 0 ] . V_33 ;
}
V_29 -> V_34 = V_35 ;
V_29 -> V_36 = V_37 ;
V_29 -> V_38 = V_39 ;
return 0 ;
}
static int F_13 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
F_12 ( V_27 -> V_31 -> V_25 , L_2 , V_32 , V_29 -> V_7 ) ;
if ( ! F_4 ( V_29 -> V_7 ) )
return - V_41 ;
F_11 ( V_27 , V_29 ) ;
V_40 -> V_30 = F_4 ( V_29 -> V_7 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
const struct V_5 * V_30 = V_40 -> V_30 ;
V_29 -> V_7 = V_30 -> V_7 ;
V_29 -> V_33 = V_30 -> V_33 ;
V_29 -> V_34 = V_35 ;
V_29 -> V_36 = V_37 ;
V_29 -> V_38 = V_39 ;
return 0 ;
}
static int F_16 ( struct V_26 * V_27 , struct V_42 * V_43 )
{
struct V_44 * V_45 = & V_43 -> V_46 ;
V_43 -> type = V_47 ;
V_45 -> V_48 = 0 ;
V_45 -> V_49 = 0 ;
V_45 -> V_34 = V_35 ;
V_45 -> V_36 = V_37 ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , struct V_50 * V_43 )
{
V_43 -> V_51 . V_49 = 0 ;
V_43 -> V_51 . V_48 = 0 ;
V_43 -> V_51 . V_34 = V_35 ;
V_43 -> V_51 . V_36 = V_37 ;
V_43 -> V_52 = V_43 -> V_51 ;
V_43 -> type = V_47 ;
V_43 -> V_53 . V_54 = 1 ;
V_43 -> V_53 . V_55 = 1 ;
return 0 ;
}
static int F_18 ( struct V_26 * V_27 , unsigned int V_56 ,
enum V_6 * V_7 )
{
if ( ( unsigned int ) V_56 >= F_5 ( V_9 ) )
return - V_41 ;
* V_7 = V_9 [ V_56 ] . V_7 ;
return 0 ;
}
static int F_19 ( struct V_26 * V_27 , int V_57 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
return F_6 ( V_3 , V_58 , ! ! V_57 ) ;
}
static int F_20 ( struct V_26 * V_27 , int V_59 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
struct V_60 * V_61 = F_21 ( V_3 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
return F_22 ( & V_3 -> V_25 , V_61 , V_40 -> V_62 , V_59 ) ;
}
static int F_23 ( struct V_26 * V_27 ,
struct V_63 * V_64 )
{
V_64 -> type = V_65 ;
V_64 -> V_21 = V_66 |
V_67 |
V_68 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_26 * V_4 = F_3 ( V_3 ) ;
int V_18 ;
T_1 V_69 ;
V_18 = F_20 ( V_4 , 1 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_9 ( V_3 , 0 ) ;
if ( V_18 < 0 )
goto V_70;
V_69 = V_18 << 8 ;
V_18 = F_9 ( V_3 , 1 ) ;
if ( V_18 < 0 )
goto V_70;
V_69 |= V_18 ;
F_25 ( & V_3 -> V_25 , L_3 , V_69 ) ;
if ( V_69 != 0x74 ) {
V_18 = - V_71 ;
goto V_70;
}
F_6 ( V_3 , V_72 , 0x2D ) ;
F_6 ( V_3 , V_73 , 0x02 ) ;
F_6 ( V_3 , V_74 , 0x4B ) ;
F_6 ( V_3 , 0x3024 , 0x00 ) ;
F_6 ( V_3 , V_75 , 0x00 ) ;
F_6 ( V_3 , 0x0112 , 0x08 ) ;
F_6 ( V_3 , 0x0113 , 0x08 ) ;
F_6 ( V_3 , V_76 , 0x80 ) ;
F_6 ( V_3 , V_77 , 0x08 ) ;
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
F_6 ( V_3 , V_78 , 0x06 ) ;
F_6 ( V_3 , V_79 , 0x48 ) ;
F_6 ( V_3 , V_80 , 0x00 ) ;
F_6 ( V_3 , V_81 , 0x2F ) ;
F_6 ( V_3 , V_82 , 0x08 ) ;
F_6 ( V_3 , V_83 , 0x38 ) ;
F_6 ( V_3 , V_84 , 0x06 ) ;
F_6 ( V_3 , V_85 , 0x18 ) ;
F_6 ( V_3 , V_86 , 0x01 ) ;
F_6 ( V_3 , V_87 , 0x03 ) ;
F_6 ( V_3 , V_88 , 0x01 ) ;
F_6 ( V_3 , V_89 , 0x03 ) ;
F_6 ( V_3 , V_90 , 0x00 ) ;
F_6 ( V_3 , V_91 , 0x16 ) ;
F_6 ( V_3 , V_92 , 0x24 ) ;
F_6 ( V_3 , V_93 , 0x53 ) ;
F_6 ( V_3 , V_94 , 0x00 ) ;
F_6 ( V_3 , V_95 , 0x80 ) ;
F_6 ( V_3 , V_96 , 0x00 ) ;
F_6 ( V_3 , V_97 , 0x00 ) ;
V_18 = 0 ;
V_70:
F_20 ( V_4 , 0 ) ;
return V_18 ;
}
static int F_26 ( struct V_2 * V_3 ,
const struct V_98 * V_99 )
{
struct V_1 * V_40 ;
struct V_12 * V_14 = F_27 ( V_3 -> V_25 . V_100 ) ;
struct V_60 * V_61 = F_21 ( V_3 ) ;
int V_18 ;
if ( ! V_61 ) {
F_28 ( & V_3 -> V_25 , L_4 ) ;
return - V_41 ;
}
if ( ! F_29 ( V_14 , V_101 ) ) {
F_10 ( & V_14 -> V_25 ,
L_5 ) ;
return - V_22 ;
}
V_40 = F_30 ( & V_3 -> V_25 , sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_40 )
return - V_103 ;
F_31 ( & V_40 -> V_4 , V_3 , & V_104 ) ;
V_40 -> V_30 = & V_9 [ 0 ] ;
V_40 -> V_62 = F_32 ( & V_3 -> V_25 , L_6 ) ;
if ( F_33 ( V_40 -> V_62 ) ) {
F_25 ( & V_3 -> V_25 , L_7 , F_34 ( V_40 -> V_62 ) ) ;
return - V_105 ;
}
V_18 = F_35 ( & V_3 -> V_25 , V_61 ) ;
if ( V_18 < 0 )
goto V_106;
V_18 = F_24 ( V_3 ) ;
if ( V_18 < 0 )
goto V_107;
V_18 = F_36 ( & V_40 -> V_4 ) ;
if ( ! V_18 )
return 0 ;
V_106:
V_107:
F_37 ( V_40 -> V_62 ) ;
return V_18 ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_60 * V_61 = F_21 ( V_3 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
F_39 ( & V_40 -> V_4 ) ;
F_37 ( V_40 -> V_62 ) ;
if ( V_61 -> V_108 )
V_61 -> V_108 ( V_61 ) ;
return 0 ;
}
