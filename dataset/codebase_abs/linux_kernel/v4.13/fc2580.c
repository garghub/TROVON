static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_4 == 0xff )
return 0 ;
else
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 , V_9 ;
unsigned int V_10 , V_11 , V_12 , V_13 , V_14 , V_15 , V_16 ;
T_2 V_17 ;
T_1 V_18 ;
unsigned long V_19 ;
if ( ! V_2 -> V_20 ) {
F_4 ( & V_7 -> V_2 , L_1 ) ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < F_5 ( V_21 ) ; V_9 ++ ) {
if ( V_2 -> V_22 <= V_21 [ V_9 ] . V_23 )
break;
}
if ( V_9 == F_5 ( V_21 ) ) {
V_8 = - V_24 ;
goto V_25;
}
#define F_6 2
#define F_7 dev->clk
V_16 = V_21 [ V_9 ] . V_16 ;
V_17 = ( T_2 ) V_2 -> V_22 * V_16 ;
V_18 = V_21 [ V_9 ] . V_26 ;
if ( V_17 < 2600000000ULL )
V_18 |= 0x06 ;
else
V_18 |= 0x0e ;
#define F_8 76
if ( V_17 >= F_9 ( ( T_2 ) F_6 * F_8 * F_7 , 1 ) ) {
V_11 = 1 ;
V_12 = 0x00 ;
} else if ( V_17 >= F_9 ( ( T_2 ) F_6 * F_8 * F_7 , 2 ) ) {
V_11 = 2 ;
V_12 = 0x10 ;
} else {
V_11 = 4 ;
V_12 = 0x20 ;
}
V_10 = F_6 * F_7 / V_11 ;
V_13 = F_10 ( V_17 , V_10 , & V_14 ) ;
V_15 = F_9 ( ( T_2 ) V_14 * 0x100000 , V_10 ) ;
F_4 ( & V_7 -> V_2 ,
L_2 ,
V_2 -> V_22 , V_2 -> V_27 , V_17 , F_7 , V_11 ,
V_13 , V_14 , V_16 , V_15 ) ;
V_8 = F_2 ( V_2 -> V_5 , 0x02 , V_18 ) ;
if ( V_8 )
goto V_25;
V_8 = F_2 ( V_2 -> V_5 , 0x18 , V_12 << 0 | V_15 >> 16 ) ;
if ( V_8 )
goto V_25;
V_8 = F_2 ( V_2 -> V_5 , 0x1a , ( V_15 >> 8 ) & 0xff ) ;
if ( V_8 )
goto V_25;
V_8 = F_2 ( V_2 -> V_5 , 0x1b , ( V_15 >> 0 ) & 0xff ) ;
if ( V_8 )
goto V_25;
V_8 = F_2 ( V_2 -> V_5 , 0x1c , V_13 ) ;
if ( V_8 )
goto V_25;
for ( V_9 = 0 ; V_9 < F_5 ( V_28 ) ; V_9 ++ ) {
if ( V_2 -> V_22 <= V_28 [ V_9 ] . V_23 )
break;
}
if ( V_9 == F_5 ( V_28 ) ) {
V_8 = - V_24 ;
goto V_25;
}
V_8 = F_1 ( V_2 , 0x25 , V_28 [ V_9 ] . V_29 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x27 , V_28 [ V_9 ] . V_30 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x28 , V_28 [ V_9 ] . V_31 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x29 , V_28 [ V_9 ] . V_32 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x2b , V_28 [ V_9 ] . V_33 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x2c , V_28 [ V_9 ] . V_34 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x2d , V_28 [ V_9 ] . V_35 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x30 , V_28 [ V_9 ] . V_36 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x44 , V_28 [ V_9 ] . V_37 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x50 , V_28 [ V_9 ] . V_38 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x53 , V_28 [ V_9 ] . V_39 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x5f , V_28 [ V_9 ] . V_40 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x61 , V_28 [ V_9 ] . V_41 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x62 , V_28 [ V_9 ] . V_42 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x63 , V_28 [ V_9 ] . V_43 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x67 , V_28 [ V_9 ] . V_44 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x68 , V_28 [ V_9 ] . V_45 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x69 , V_28 [ V_9 ] . V_46 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x6a , V_28 [ V_9 ] . V_47 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x6b , V_28 [ V_9 ] . V_48 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x6c , V_28 [ V_9 ] . V_49 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x6d , V_28 [ V_9 ] . V_50 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x6e , V_28 [ V_9 ] . V_51 ) ;
if ( V_8 )
goto V_25;
V_8 = F_1 ( V_2 , 0x6f , V_28 [ V_9 ] . V_52 ) ;
if ( V_8 )
goto V_25;
for ( V_9 = 0 ; V_9 < F_5 ( V_53 ) ; V_9 ++ ) {
if ( V_2 -> V_27 <= V_53 [ V_9 ] . V_23 )
break;
}
if ( V_9 == F_5 ( V_53 ) ) {
V_8 = - V_24 ;
goto V_25;
}
V_8 = F_2 ( V_2 -> V_5 , 0x36 , V_53 [ V_9 ] . V_54 ) ;
if ( V_8 )
goto V_25;
V_10 = ( unsigned int ) 8058000 - ( V_2 -> V_27 * 122 / 100 / 2 ) ;
V_10 = F_11 ( ( T_2 ) V_2 -> V_55 * V_10 , 1000000000000ULL ) ;
V_8 = F_2 ( V_2 -> V_5 , 0x37 , V_10 ) ;
if ( V_8 )
goto V_25;
V_8 = F_2 ( V_2 -> V_5 , 0x39 , V_53 [ V_9 ] . V_56 ) ;
if ( V_8 )
goto V_25;
V_19 = V_57 + F_12 ( 30 ) ;
for ( V_10 = ~ 0xc0 ; ! F_13 ( V_57 , V_19 ) && V_10 != 0xc0 ; ) {
V_8 = F_2 ( V_2 -> V_5 , 0x2e , 0x09 ) ;
if ( V_8 )
goto V_25;
V_8 = F_14 ( V_2 -> V_5 , 0x2f , & V_10 ) ;
if ( V_8 )
goto V_25;
V_10 &= 0xc0 ;
V_8 = F_2 ( V_2 -> V_5 , 0x2e , 0x01 ) ;
if ( V_8 )
goto V_25;
}
if ( V_10 != 0xc0 )
F_4 ( & V_7 -> V_2 , L_3 , V_10 ) ;
return 0 ;
V_25:
F_4 ( & V_7 -> V_2 , L_4 , V_8 ) ;
return V_8 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 , V_9 ;
F_4 ( & V_7 -> V_2 , L_5 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_58 ) ; V_9 ++ ) {
V_8 = F_2 ( V_2 -> V_5 , V_58 [ V_9 ] . V_3 ,
V_58 [ V_9 ] . V_4 ) ;
if ( V_8 )
goto V_25;
}
V_2 -> V_20 = true ;
return 0 ;
V_25:
F_4 ( & V_7 -> V_2 , L_4 , V_8 ) ;
return V_8 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
F_4 ( & V_7 -> V_2 , L_5 ) ;
V_2 -> V_20 = false ;
V_8 = F_2 ( V_2 -> V_5 , 0x02 , 0x0a ) ;
if ( V_8 )
goto V_25;
return 0 ;
V_25:
F_4 ( & V_7 -> V_2 , L_4 , V_8 ) ;
return V_8 ;
}
static int F_17 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_62 * V_63 = & V_60 -> V_64 ;
V_2 -> V_22 = V_63 -> V_65 ;
V_2 -> V_27 = V_63 -> V_66 ;
return F_3 ( V_2 ) ;
}
static int F_18 ( struct V_59 * V_60 )
{
return F_15 ( V_60 -> V_61 ) ;
}
static int F_19 ( struct V_59 * V_60 )
{
return F_16 ( V_60 -> V_61 ) ;
}
static int F_20 ( struct V_59 * V_60 , T_3 * V_65 )
{
* V_65 = 0 ;
return 0 ;
}
static inline struct V_1 * F_21 ( struct V_67 * V_68 )
{
return F_22 ( V_68 , struct V_1 , V_69 ) ;
}
static int F_23 ( struct V_67 * V_68 , int V_70 )
{
struct V_1 * V_2 = F_21 ( V_68 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
F_4 ( & V_7 -> V_2 , L_6 , V_70 ) ;
if ( V_70 )
V_8 = F_15 ( V_2 ) ;
else
V_8 = F_16 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return F_3 ( V_2 ) ;
}
static int F_24 ( struct V_67 * V_68 , struct V_71 * V_72 )
{
struct V_1 * V_2 = F_21 ( V_68 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_4 ( & V_7 -> V_2 , L_7 , V_72 -> V_73 ) ;
F_25 ( V_72 -> V_74 , L_8 , sizeof( V_72 -> V_74 ) ) ;
V_72 -> type = V_75 ;
V_72 -> V_76 = V_77 | V_78 ;
V_72 -> V_79 = V_80 [ 0 ] . V_79 ;
V_72 -> V_81 = V_80 [ 0 ] . V_81 ;
return 0 ;
}
static int F_26 ( struct V_67 * V_68 , const struct V_71 * V_72 )
{
struct V_1 * V_2 = F_21 ( V_68 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_4 ( & V_7 -> V_2 , L_7 , V_72 -> V_73 ) ;
return 0 ;
}
static int F_27 ( struct V_67 * V_68 , struct V_82 * V_83 )
{
struct V_1 * V_2 = F_21 ( V_68 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_4 ( & V_7 -> V_2 , L_9 , V_83 -> V_84 ) ;
V_83 -> V_65 = V_2 -> V_22 ;
return 0 ;
}
static int F_28 ( struct V_67 * V_68 ,
const struct V_82 * V_83 )
{
struct V_1 * V_2 = F_21 ( V_68 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_4 ( & V_7 -> V_2 , L_10 ,
V_83 -> V_84 , V_83 -> type , V_83 -> V_65 ) ;
V_2 -> V_22 = F_29 (unsigned int, f->frequency,
bands[0].rangelow, bands[0].rangehigh) ;
return F_3 ( V_2 ) ;
}
static int F_30 ( struct V_67 * V_68 ,
struct V_85 * V_26 )
{
struct V_1 * V_2 = F_21 ( V_68 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_4 ( & V_7 -> V_2 , L_11 ,
V_26 -> V_84 , V_26 -> type , V_26 -> V_73 ) ;
if ( V_26 -> V_73 >= F_5 ( V_80 ) )
return - V_24 ;
V_26 -> V_76 = V_80 [ V_26 -> V_73 ] . V_76 ;
V_26 -> V_79 = V_80 [ V_26 -> V_73 ] . V_79 ;
V_26 -> V_81 = V_80 [ V_26 -> V_73 ] . V_81 ;
return 0 ;
}
static int F_31 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_22 ( V_87 -> V_88 , struct V_1 , V_89 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
F_4 ( & V_7 -> V_2 , L_12 ,
V_87 -> V_90 , V_87 -> V_74 , V_87 -> V_91 . V_4 , V_87 -> V_4 ) ;
switch ( V_87 -> V_90 ) {
case V_92 :
case V_93 :
V_2 -> V_27 = V_2 -> V_94 -> V_4 ;
V_8 = F_3 ( V_2 ) ;
break;
default:
F_4 ( & V_7 -> V_2 , L_13 ) ;
V_8 = - V_24 ;
}
return V_8 ;
}
static struct V_67 * F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_33 ( V_7 ) ;
if ( V_2 -> V_69 . V_95 )
return & V_2 -> V_69 ;
else
return NULL ;
}
static int F_34 ( struct V_6 * V_7 ,
const struct V_96 * V_90 )
{
struct V_1 * V_2 ;
struct V_97 * V_98 = V_7 -> V_2 . V_99 ;
struct V_59 * V_60 = V_98 -> V_59 ;
int V_8 ;
unsigned int V_10 ;
static const struct V_100 V_100 = {
. V_101 = 8 ,
. V_102 = 8 ,
} ;
V_2 = F_35 ( sizeof( * V_2 ) , V_103 ) ;
if ( ! V_2 ) {
V_8 = - V_104 ;
goto V_25;
}
if ( V_98 -> V_55 )
V_2 -> V_55 = V_98 -> V_55 ;
else
V_2 -> V_55 = 16384000 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_5 = F_36 ( V_7 , & V_100 ) ;
if ( F_37 ( V_2 -> V_5 ) ) {
V_8 = F_38 ( V_2 -> V_5 ) ;
goto V_105;
}
V_8 = F_14 ( V_2 -> V_5 , 0x01 , & V_10 ) ;
if ( V_8 )
goto V_105;
F_4 ( & V_7 -> V_2 , L_14 , V_10 ) ;
switch ( V_10 ) {
case 0x56 :
case 0x5a :
break;
default:
V_8 = - V_106 ;
goto V_105;
}
#if F_39 ( V_107 )
F_40 ( & V_2 -> V_89 , 2 ) ;
V_2 -> V_108 = F_41 ( & V_2 -> V_89 , & V_109 ,
V_92 ,
0 , 1 , 1 , 1 ) ;
V_2 -> V_94 = F_41 ( & V_2 -> V_89 , & V_109 ,
V_93 ,
3000 , 10000000 , 1 , 3000 ) ;
F_42 ( 2 , & V_2 -> V_108 , 0 , false ) ;
if ( V_2 -> V_89 . error ) {
V_8 = V_2 -> V_89 . error ;
F_43 ( & V_7 -> V_2 , L_15 ) ;
F_44 ( & V_2 -> V_89 ) ;
goto V_105;
}
V_2 -> V_69 . V_110 = & V_2 -> V_89 ;
V_2 -> V_22 = V_80 [ 0 ] . V_79 ;
V_2 -> V_27 = V_2 -> V_94 -> V_4 ;
F_45 ( & V_2 -> V_69 , V_7 , & V_111 ) ;
#endif
V_60 -> V_61 = V_2 ;
memcpy ( & V_60 -> V_95 . V_112 , & V_113 ,
sizeof( V_60 -> V_95 . V_112 ) ) ;
V_98 -> V_114 = F_32 ;
F_46 ( V_7 , V_2 ) ;
F_47 ( & V_7 -> V_2 , L_16 ) ;
return 0 ;
V_105:
F_48 ( V_2 ) ;
V_25:
F_4 ( & V_7 -> V_2 , L_4 , V_8 ) ;
return V_8 ;
}
static int F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_33 ( V_7 ) ;
F_4 ( & V_7 -> V_2 , L_5 ) ;
#if F_39 ( V_107 )
F_44 ( & V_2 -> V_89 ) ;
#endif
F_48 ( V_2 ) ;
return 0 ;
}
