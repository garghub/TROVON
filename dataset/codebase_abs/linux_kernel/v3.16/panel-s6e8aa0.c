static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> error ;
V_2 -> error = 0 ;
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 -> V_8 ) ;
int V_3 ;
if ( V_2 -> error < 0 )
return;
V_3 = F_4 ( V_7 , V_7 -> V_9 , V_4 , V_5 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_8 , L_1 , V_3 , V_5 ,
V_4 ) ;
V_2 -> error = V_3 ;
}
}
static int F_6 ( struct V_1 * V_2 , T_2 V_10 , void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 -> V_8 ) ;
int V_3 ;
if ( V_2 -> error < 0 )
return V_2 -> error ;
V_3 = F_7 ( V_7 , V_7 -> V_9 , V_10 , V_4 , V_5 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_8 , L_2 , V_3 , V_10 ) ;
V_2 -> error = V_3 ;
}
return V_3 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0xf0 , 0x5a , 0x5a ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
static const T_2 V_11 [] = {
0x04 , 0x04 , 0x04 , 0x04 , 0x04 , 0x60 , 0x80 , 0xA0
} ;
T_2 V_12 = V_11 [ V_2 -> V_13 >> 5 ] ;
T_2 V_14 = 0x3d ;
T_2 V_15 = 0xc8 ;
T_2 V_16 = 0x08 ;
T_2 V_17 = 0x48 ;
T_2 V_18 = 0xff ;
T_2 V_19 = 0xff ;
T_2 V_20 = 0xc8 ;
if ( V_2 -> V_21 ) {
V_14 &= ~ ( V_22 ) ;
V_14 |= ( V_23 ) ;
}
if ( V_2 -> V_24 ) {
V_14 &= ~ ( V_25 ) ;
V_14 |= ( V_26 ) ;
}
if ( V_2 -> V_24 || V_2 -> V_21 ) {
V_15 &= ~ ( V_27 |
V_28 ) ;
V_15 |= ( V_29 | V_30 ) ;
V_16 &= ~ ( V_31 |
V_32 ) ;
V_16 |= ( V_33 | V_34 ) ;
V_17 &= ~ ( V_35 |
V_36 ) ;
V_17 |= ( V_37 |
V_38 ) ;
V_18 &= ~ ( V_39 |
V_40 ) ;
V_18 |= ( V_41 |
V_42 ) ;
V_19 &= ~ ( V_43 |
V_44 ) ;
V_19 |= ( V_45 |
V_46 ) ;
V_20 &= ~ ( V_47 |
V_48 ) ;
V_20 |= ( V_49 |
V_50 ) ;
}
F_11 ( V_2 ,
0xf8 , V_14 , 0x35 , 0x00 , 0x00 , 0x00 , 0x93 , 0x00 ,
0x3c , 0x78 , 0x08 , 0x27 , 0x7d , 0x3f , 0x00 , 0x00 ,
0x00 , 0x20 , V_12 , 0x08 , 0x6e , 0x00 , 0x00 , 0x00 ,
0x02 , 0x07 , 0x07 , 0x23 , 0x23 , 0xc0 , V_15 , V_16 ,
V_17 , 0xc1 , 0x00 , 0xc1 , V_18 , V_19 ,
V_20 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 < 142 )
F_9 ( V_2 ,
0xf8 , 0x19 , 0x35 , 0x00 , 0x00 , 0x00 , 0x94 , 0x00 ,
0x3c , 0x78 , 0x10 , 0x27 , 0x08 , 0x6e , 0x00 , 0x00 ,
0x00 , 0x00 , 0x04 , 0x08 , 0x6e , 0x00 , 0x00 , 0x00 ,
0x00 , 0x07 , 0x07 , 0x23 , 0x6e , 0xc0 , 0xc1 , 0x01 ,
0x81 , 0xc1 , 0x00 , 0xc3 , 0xf6 , 0xf6 , 0xc1
) ;
else
F_10 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0xf2 , 0x80 , 0x03 , 0x0d ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0xf6 , 0x00 , 0x02 , 0x00 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
static const T_2 V_52 [] = {
0xb6 , 0x0c , 0x02 , 0x03 , 0x32 , 0xc0 , 0x44 , 0x44 , 0xc0 , 0x00
} ;
static const T_2 V_53 [] = {
0xb6 , 0x0c , 0x02 , 0x03 , 0x32 , 0xff , 0x44 , 0x44 , 0xc0 , 0x00
} ;
if ( V_2 -> V_51 < 142 )
F_2 ( V_2 , V_52 , F_16 ( V_52 ) ) ;
else
F_2 ( V_2 , V_53 , F_16 ( V_53 ) ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
static const T_2 V_54 [] = {
0xf4 , 0xcf , 0x0a , 0x12 , 0x10 , 0x1e , 0x33 , 0x02
} ;
static const T_2 V_55 [] = {
0xf4 , 0xcf , 0x0a , 0x15 , 0x10 , 0x19 , 0x33 , 0x02
} ;
if ( V_2 -> V_51 < 142 )
F_2 ( V_2 , V_55 , F_16 ( V_55 ) ) ;
else
F_2 ( V_2 , V_54 , F_16 ( V_54 ) ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 V_13 = V_2 -> V_13 ? 0 : 0x95 ;
F_11 ( V_2 , 0xb1 , 0x04 , V_13 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_2 V_56 ;
switch ( V_2 -> V_57 ) {
case 0 ... 6 :
V_56 = 0xdf ;
break;
case 7 ... 11 :
V_56 = 0xdd ;
break;
case 12 ... 15 :
default:
V_56 = 0xd9 ;
break;
case 16 ... 24 :
V_56 = 0xd0 ;
break;
}
F_11 ( V_2 , 0xd9 , 0x14 , 0x40 , 0x0c , 0xcb , 0xce , 0x6e ,
0xc4 , 0x0f , 0x40 , 0x41 , V_56 , 0x00 , 0x60 , 0x19 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 < 142 )
F_9 ( V_2 ,
0xd9 , 0x14 , 0x40 , 0x0c , 0xcb , 0xce , 0x6e , 0xc4 , 0x07 ,
0x40 , 0x41 , 0xc1 , 0x00 , 0x60 , 0x19 ) ;
else
F_19 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0xfc , 0x5a , 0x5a ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
const T_2 * gamma ;
if ( V_2 -> error )
return;
gamma = V_2 -> V_58 -> V_59 [ V_2 -> V_57 ] ;
if ( V_2 -> V_51 >= 142 )
F_20 ( V_2 ) ;
F_2 ( V_2 , gamma , V_60 ) ;
F_9 ( V_2 , 0xf7 , 0x03 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_21 ( V_2 ) ;
F_24 ( 20 ) ;
F_9 ( V_2 , V_61 ) ;
F_24 ( 40 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_22 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
F_20 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_24 ( V_2 -> V_62 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
int V_63 )
{
struct V_6 * V_7 = F_3 ( V_2 -> V_8 ) ;
const struct V_64 * V_65 = V_7 -> V_66 -> V_65 ;
T_2 V_67 [] = { V_63 , 0 } ;
struct V_68 V_69 = {
. V_9 = V_7 -> V_9 ,
. type = V_70 ,
. V_71 = sizeof( V_67 ) ,
. V_72 = V_67
} ;
int V_3 ;
if ( V_2 -> error < 0 )
return;
if ( ! V_65 || ! V_65 -> V_73 )
V_3 = - V_74 ;
else
V_3 = V_65 -> V_73 ( V_7 -> V_66 , & V_69 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_8 ,
L_3 ,
V_3 , V_63 ) ;
V_2 -> error = V_3 ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
T_2 V_13 [ 3 ] ;
int V_3 , V_75 ;
V_3 = F_6 ( V_2 , 0xd1 , V_13 , F_16 ( V_13 ) ) ;
if ( V_3 < F_16 ( V_13 ) || V_13 [ 0 ] == 0x00 ) {
F_5 ( V_2 -> V_8 , L_4 ) ;
V_2 -> error = - V_74 ;
return;
}
F_27 ( V_2 -> V_8 , L_5 , V_13 [ 0 ] , V_13 [ 1 ] , V_13 [ 2 ] ) ;
for ( V_75 = 0 ; V_75 < F_16 ( V_76 ) ; ++ V_75 ) {
if ( V_13 [ 1 ] == V_76 [ V_75 ] . V_51 )
break;
}
if ( V_75 >= F_16 ( V_76 ) ) {
F_5 ( V_2 -> V_8 , L_6 , V_13 [ 1 ] ) ;
V_2 -> error = - V_77 ;
return;
}
V_2 -> V_58 = & V_76 [ V_75 ] ;
V_2 -> V_51 = V_13 [ 1 ] ;
V_2 -> V_13 = V_13 [ 2 ] ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_25 ( V_2 , 3 ) ;
F_26 ( V_2 ) ;
F_23 ( V_2 ) ;
F_9 ( V_2 , V_78 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_30 ( F_16 ( V_2 -> V_79 ) , V_2 -> V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
F_24 ( V_2 -> V_80 ) ;
F_31 ( V_2 -> V_81 , 0 ) ;
F_32 ( 10000 , 11000 ) ;
F_31 ( V_2 -> V_81 , 1 ) ;
F_24 ( V_2 -> V_82 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
return F_34 ( F_16 ( V_2 -> V_79 ) , V_2 -> V_79 ) ;
}
static int F_35 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_36 ( V_84 ) ;
F_9 ( V_2 , V_85 ) ;
F_9 ( V_2 , V_86 ) ;
F_24 ( 40 ) ;
F_1 ( V_2 ) ;
return F_33 ( V_2 ) ;
}
static int F_37 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_36 ( V_84 ) ;
int V_3 ;
V_3 = F_29 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_28 ( V_2 ) ;
V_3 = V_2 -> error ;
if ( V_3 < 0 )
F_35 ( V_84 ) ;
return V_3 ;
}
static int F_38 ( struct V_83 * V_84 )
{
struct V_87 * V_88 = V_84 -> V_88 ;
struct V_1 * V_2 = F_36 ( V_84 ) ;
struct V_89 * V_90 ;
V_90 = F_39 ( V_88 -> V_8 ) ;
if ( ! V_90 ) {
F_40 ( L_7 ) ;
return 0 ;
}
F_41 ( & V_2 -> V_91 , V_90 ) ;
V_90 -> V_92 = V_2 -> V_92 ;
V_90 -> V_93 = V_2 -> V_93 ;
V_88 -> V_94 . V_92 = V_90 -> V_92 ;
V_88 -> V_94 . V_93 = V_90 -> V_93 ;
V_90 -> type = V_95 | V_96 ;
F_42 ( V_88 , V_90 ) ;
return 1 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_97 * V_8 = V_2 -> V_8 ;
struct V_98 * V_99 = V_8 -> V_100 ;
int V_3 ;
V_3 = F_44 ( V_99 , & V_2 -> V_91 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
F_45 ( V_99 , L_8 , & V_2 -> V_80 ) ;
F_45 ( V_99 , L_9 , & V_2 -> V_82 ) ;
F_45 ( V_99 , L_10 , & V_2 -> V_62 ) ;
F_45 ( V_99 , L_11 , & V_2 -> V_92 ) ;
F_45 ( V_99 , L_12 , & V_2 -> V_93 ) ;
V_2 -> V_24 = F_46 ( V_99 , L_13 ) ;
V_2 -> V_21 = F_46 ( V_99 , L_14 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_97 * V_8 = & V_7 -> V_8 ;
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_48 ( V_8 , sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_2 )
return - V_102 ;
F_49 ( V_7 , V_2 ) ;
V_2 -> V_8 = V_8 ;
V_7 -> V_103 = 4 ;
V_7 -> V_104 = V_105 ;
V_7 -> V_106 = V_107 | V_108
| V_109 | V_110
| V_111 | V_112
| V_113 | V_114 ;
V_3 = F_43 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_79 [ 0 ] . V_115 = L_15 ;
V_2 -> V_79 [ 1 ] . V_115 = L_16 ;
V_3 = F_50 ( V_8 , F_16 ( V_2 -> V_79 ) ,
V_2 -> V_79 ) ;
if ( V_3 < 0 ) {
F_5 ( V_8 , L_17 , V_3 ) ;
return V_3 ;
}
V_2 -> V_81 = F_51 ( V_8 , L_18 ) ;
if ( F_52 ( V_2 -> V_81 ) ) {
F_5 ( V_8 , L_19 ,
F_53 ( V_2 -> V_81 ) ) ;
return F_53 ( V_2 -> V_81 ) ;
}
V_3 = F_54 ( V_2 -> V_81 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_8 , L_20 , V_3 ) ;
return V_3 ;
}
V_2 -> V_57 = V_116 - 1 ;
F_55 ( & V_2 -> V_84 ) ;
V_2 -> V_84 . V_8 = V_8 ;
V_2 -> V_84 . V_117 = & V_118 ;
V_3 = F_56 ( & V_2 -> V_84 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_57 ( V_7 ) ;
if ( V_3 < 0 )
F_58 ( & V_2 -> V_84 ) ;
return V_3 ;
}
static int F_59 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_60 ( V_7 ) ;
F_61 ( V_7 ) ;
F_58 ( & V_2 -> V_84 ) ;
return 0 ;
}
