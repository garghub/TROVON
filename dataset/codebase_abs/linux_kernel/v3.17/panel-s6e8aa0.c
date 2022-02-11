static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 )
{
int V_5 = V_4 -> error ;
V_4 -> error = 0 ;
return V_5 ;
}
static void F_4 ( struct V_1 * V_4 , const void * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = F_5 ( V_4 -> V_10 ) ;
T_2 V_5 ;
if ( V_4 -> error < 0 )
return;
V_5 = F_6 ( V_9 , V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_7 ( V_4 -> V_10 , L_1 , V_5 , V_7 ,
V_6 ) ;
V_4 -> error = V_5 ;
}
}
static int F_8 ( struct V_1 * V_4 , T_3 V_11 , void * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = F_5 ( V_4 -> V_10 ) ;
int V_5 ;
if ( V_4 -> error < 0 )
return V_4 -> error ;
V_5 = F_9 ( V_9 , V_11 , V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_7 ( V_4 -> V_10 , L_2 , V_5 , V_11 ) ;
V_4 -> error = V_5 ;
}
return V_5 ;
}
static void F_10 ( struct V_1 * V_4 )
{
F_11 ( V_4 , 0xf0 , 0x5a , 0x5a ) ;
}
static void F_12 ( struct V_1 * V_4 )
{
static const T_3 V_12 [] = {
0x04 , 0x04 , 0x04 , 0x04 , 0x04 , 0x60 , 0x80 , 0xA0
} ;
T_3 V_13 = V_12 [ V_4 -> V_14 >> 5 ] ;
T_3 V_15 = 0x3d ;
T_3 V_16 = 0xc8 ;
T_3 V_17 = 0x08 ;
T_3 V_18 = 0x48 ;
T_3 V_19 = 0xff ;
T_3 V_20 = 0xff ;
T_3 V_21 = 0xc8 ;
if ( V_4 -> V_22 ) {
V_15 &= ~ ( V_23 ) ;
V_15 |= ( V_24 ) ;
}
if ( V_4 -> V_25 ) {
V_15 &= ~ ( V_26 ) ;
V_15 |= ( V_27 ) ;
}
if ( V_4 -> V_25 || V_4 -> V_22 ) {
V_16 &= ~ ( V_28 |
V_29 ) ;
V_16 |= ( V_30 | V_31 ) ;
V_17 &= ~ ( V_32 |
V_33 ) ;
V_17 |= ( V_34 | V_35 ) ;
V_18 &= ~ ( V_36 |
V_37 ) ;
V_18 |= ( V_38 |
V_39 ) ;
V_19 &= ~ ( V_40 |
V_41 ) ;
V_19 |= ( V_42 |
V_43 ) ;
V_20 &= ~ ( V_44 |
V_45 ) ;
V_20 |= ( V_46 |
V_47 ) ;
V_21 &= ~ ( V_48 |
V_49 ) ;
V_21 |= ( V_50 |
V_51 ) ;
}
F_13 ( V_4 ,
0xf8 , V_15 , 0x35 , 0x00 , 0x00 , 0x00 , 0x93 , 0x00 ,
0x3c , 0x78 , 0x08 , 0x27 , 0x7d , 0x3f , 0x00 , 0x00 ,
0x00 , 0x20 , V_13 , 0x08 , 0x6e , 0x00 , 0x00 , 0x00 ,
0x02 , 0x07 , 0x07 , 0x23 , 0x23 , 0xc0 , V_16 , V_17 ,
V_18 , 0xc1 , 0x00 , 0xc1 , V_19 , V_20 ,
V_21 ) ;
}
static void F_14 ( struct V_1 * V_4 )
{
if ( V_4 -> V_52 < 142 )
F_11 ( V_4 ,
0xf8 , 0x19 , 0x35 , 0x00 , 0x00 , 0x00 , 0x94 , 0x00 ,
0x3c , 0x78 , 0x10 , 0x27 , 0x08 , 0x6e , 0x00 , 0x00 ,
0x00 , 0x00 , 0x04 , 0x08 , 0x6e , 0x00 , 0x00 , 0x00 ,
0x00 , 0x07 , 0x07 , 0x23 , 0x6e , 0xc0 , 0xc1 , 0x01 ,
0x81 , 0xc1 , 0x00 , 0xc3 , 0xf6 , 0xf6 , 0xc1
) ;
else
F_12 ( V_4 ) ;
}
static void F_15 ( struct V_1 * V_4 )
{
F_11 ( V_4 , 0xf2 , 0x80 , 0x03 , 0x0d ) ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_11 ( V_4 , 0xf6 , 0x00 , 0x02 , 0x00 ) ;
}
static void F_17 ( struct V_1 * V_4 )
{
static const T_3 V_53 [] = {
0xb6 , 0x0c , 0x02 , 0x03 , 0x32 , 0xc0 , 0x44 , 0x44 , 0xc0 , 0x00
} ;
static const T_3 V_54 [] = {
0xb6 , 0x0c , 0x02 , 0x03 , 0x32 , 0xff , 0x44 , 0x44 , 0xc0 , 0x00
} ;
if ( V_4 -> V_52 < 142 )
F_4 ( V_4 , V_53 , F_18 ( V_53 ) ) ;
else
F_4 ( V_4 , V_54 , F_18 ( V_54 ) ) ;
}
static void F_19 ( struct V_1 * V_4 )
{
static const T_3 V_55 [] = {
0xf4 , 0xcf , 0x0a , 0x12 , 0x10 , 0x1e , 0x33 , 0x02
} ;
static const T_3 V_56 [] = {
0xf4 , 0xcf , 0x0a , 0x15 , 0x10 , 0x19 , 0x33 , 0x02
} ;
if ( V_4 -> V_52 < 142 )
F_4 ( V_4 , V_56 , F_18 ( V_56 ) ) ;
else
F_4 ( V_4 , V_55 , F_18 ( V_55 ) ) ;
}
static void F_20 ( struct V_1 * V_4 )
{
T_3 V_14 = V_4 -> V_14 ? 0 : 0x95 ;
F_13 ( V_4 , 0xb1 , 0x04 , V_14 ) ;
}
static void F_21 ( struct V_1 * V_4 )
{
T_3 V_57 ;
switch ( V_4 -> V_58 ) {
case 0 ... 6 :
V_57 = 0xdf ;
break;
case 7 ... 11 :
V_57 = 0xdd ;
break;
case 12 ... 15 :
default:
V_57 = 0xd9 ;
break;
case 16 ... 24 :
V_57 = 0xd0 ;
break;
}
F_13 ( V_4 , 0xd9 , 0x14 , 0x40 , 0x0c , 0xcb , 0xce , 0x6e ,
0xc4 , 0x0f , 0x40 , 0x41 , V_57 , 0x00 , 0x60 , 0x19 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
if ( V_4 -> V_52 < 142 )
F_11 ( V_4 ,
0xd9 , 0x14 , 0x40 , 0x0c , 0xcb , 0xce , 0x6e , 0xc4 , 0x07 ,
0x40 , 0x41 , 0xc1 , 0x00 , 0x60 , 0x19 ) ;
else
F_21 ( V_4 ) ;
}
static void F_23 ( struct V_1 * V_4 )
{
F_11 ( V_4 , 0xfc , 0x5a , 0x5a ) ;
}
static void F_24 ( struct V_1 * V_4 )
{
const T_3 * gamma ;
if ( V_4 -> error )
return;
gamma = V_4 -> V_59 -> V_60 [ V_4 -> V_58 ] ;
if ( V_4 -> V_52 >= 142 )
F_22 ( V_4 ) ;
F_4 ( V_4 , gamma , V_61 ) ;
F_11 ( V_4 , 0xf7 , 0x03 ) ;
}
static void F_25 ( struct V_1 * V_4 )
{
F_10 ( V_4 ) ;
F_23 ( V_4 ) ;
F_26 ( 20 ) ;
F_11 ( V_4 , V_62 ) ;
F_26 ( 40 ) ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
F_24 ( V_4 ) ;
F_16 ( V_4 ) ;
F_17 ( V_4 ) ;
F_22 ( V_4 ) ;
F_19 ( V_4 ) ;
F_20 ( V_4 ) ;
F_26 ( V_4 -> V_63 ) ;
}
static void F_27 ( struct V_1 * V_4 ,
int V_64 )
{
struct V_8 * V_9 = F_5 ( V_4 -> V_10 ) ;
const struct V_65 * V_66 = V_9 -> V_67 -> V_66 ;
T_3 V_68 [] = { V_64 , 0 } ;
struct V_69 V_70 = {
. V_71 = V_9 -> V_71 ,
. type = V_72 ,
. V_73 = sizeof( V_68 ) ,
. V_74 = V_68
} ;
int V_5 ;
if ( V_4 -> error < 0 )
return;
if ( ! V_66 || ! V_66 -> V_75 )
V_5 = - V_76 ;
else
V_5 = V_66 -> V_75 ( V_9 -> V_67 , & V_70 ) ;
if ( V_5 < 0 ) {
F_7 ( V_4 -> V_10 ,
L_3 ,
V_5 , V_64 ) ;
V_4 -> error = V_5 ;
}
}
static void F_28 ( struct V_1 * V_4 )
{
T_3 V_14 [ 3 ] ;
int V_5 , V_77 ;
V_5 = F_8 ( V_4 , 0xd1 , V_14 , F_18 ( V_14 ) ) ;
if ( V_5 < F_18 ( V_14 ) || V_14 [ 0 ] == 0x00 ) {
F_7 ( V_4 -> V_10 , L_4 ) ;
V_4 -> error = - V_76 ;
return;
}
F_29 ( V_4 -> V_10 , L_5 , V_14 [ 0 ] , V_14 [ 1 ] , V_14 [ 2 ] ) ;
for ( V_77 = 0 ; V_77 < F_18 ( V_78 ) ; ++ V_77 ) {
if ( V_14 [ 1 ] == V_78 [ V_77 ] . V_52 )
break;
}
if ( V_77 >= F_18 ( V_78 ) ) {
F_7 ( V_4 -> V_10 , L_6 , V_14 [ 1 ] ) ;
V_4 -> error = - V_79 ;
return;
}
V_4 -> V_59 = & V_78 [ V_77 ] ;
V_4 -> V_52 = V_14 [ 1 ] ;
V_4 -> V_14 = V_14 [ 2 ] ;
}
static void F_30 ( struct V_1 * V_4 )
{
F_27 ( V_4 , 3 ) ;
F_28 ( V_4 ) ;
F_25 ( V_4 ) ;
F_11 ( V_4 , V_80 ) ;
}
static int F_31 ( struct V_1 * V_4 )
{
int V_5 ;
V_5 = F_32 ( F_18 ( V_4 -> V_81 ) , V_4 -> V_81 ) ;
if ( V_5 < 0 )
return V_5 ;
F_26 ( V_4 -> V_82 ) ;
F_33 ( V_4 -> V_83 , 0 ) ;
F_34 ( 10000 , 11000 ) ;
F_33 ( V_4 -> V_83 , 1 ) ;
F_26 ( V_4 -> V_84 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_4 )
{
return F_36 ( F_18 ( V_4 -> V_81 ) , V_4 -> V_81 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_11 ( V_4 , V_85 ) ;
F_11 ( V_4 , V_86 ) ;
F_26 ( 40 ) ;
F_3 ( V_4 ) ;
return F_35 ( V_4 ) ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_5 ;
V_5 = F_31 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
F_30 ( V_4 ) ;
V_5 = V_4 -> error ;
if ( V_5 < 0 )
F_38 ( V_3 ) ;
return V_5 ;
}
static int F_40 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_87 * V_88 = V_3 -> V_88 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_89 * V_90 ;
V_90 = F_42 ( V_88 -> V_10 ) ;
if ( ! V_90 ) {
F_43 ( L_7 ) ;
return 0 ;
}
F_44 ( & V_4 -> V_91 , V_90 ) ;
V_90 -> V_92 = V_4 -> V_92 ;
V_90 -> V_93 = V_4 -> V_93 ;
V_88 -> V_94 . V_92 = V_90 -> V_92 ;
V_88 -> V_94 . V_93 = V_90 -> V_93 ;
V_90 -> type = V_95 | V_96 ;
F_45 ( V_88 , V_90 ) ;
return 1 ;
}
static int F_46 ( struct V_1 * V_4 )
{
struct V_97 * V_10 = V_4 -> V_10 ;
struct V_98 * V_99 = V_10 -> V_100 ;
int V_5 ;
V_5 = F_47 ( V_99 , & V_4 -> V_91 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
F_48 ( V_99 , L_8 , & V_4 -> V_82 ) ;
F_48 ( V_99 , L_9 , & V_4 -> V_84 ) ;
F_48 ( V_99 , L_10 , & V_4 -> V_63 ) ;
F_48 ( V_99 , L_11 , & V_4 -> V_92 ) ;
F_48 ( V_99 , L_12 , & V_4 -> V_93 ) ;
V_4 -> V_25 = F_49 ( V_99 , L_13 ) ;
V_4 -> V_22 = F_49 ( V_99 , L_14 ) ;
return 0 ;
}
static int F_50 ( struct V_8 * V_9 )
{
struct V_97 * V_10 = & V_9 -> V_10 ;
struct V_1 * V_4 ;
int V_5 ;
V_4 = F_51 ( V_10 , sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_4 )
return - V_102 ;
F_52 ( V_9 , V_4 ) ;
V_4 -> V_10 = V_10 ;
V_9 -> V_103 = 4 ;
V_9 -> V_104 = V_105 ;
V_9 -> V_106 = V_107 | V_108
| V_109 | V_110
| V_111 | V_112
| V_113 | V_114 ;
V_5 = F_46 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 -> V_81 [ 0 ] . V_115 = L_15 ;
V_4 -> V_81 [ 1 ] . V_115 = L_16 ;
V_5 = F_53 ( V_10 , F_18 ( V_4 -> V_81 ) ,
V_4 -> V_81 ) ;
if ( V_5 < 0 ) {
F_7 ( V_10 , L_17 , V_5 ) ;
return V_5 ;
}
V_4 -> V_83 = F_54 ( V_10 , L_18 ) ;
if ( F_55 ( V_4 -> V_83 ) ) {
F_7 ( V_10 , L_19 ,
F_56 ( V_4 -> V_83 ) ) ;
return F_56 ( V_4 -> V_83 ) ;
}
V_5 = F_57 ( V_4 -> V_83 , 1 ) ;
if ( V_5 < 0 ) {
F_7 ( V_10 , L_20 , V_5 ) ;
return V_5 ;
}
V_4 -> V_58 = V_116 - 1 ;
F_58 ( & V_4 -> V_3 ) ;
V_4 -> V_3 . V_10 = V_10 ;
V_4 -> V_3 . V_117 = & V_118 ;
V_5 = F_59 ( & V_4 -> V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_60 ( V_9 ) ;
if ( V_5 < 0 )
F_61 ( & V_4 -> V_3 ) ;
return V_5 ;
}
static int F_62 ( struct V_8 * V_9 )
{
struct V_1 * V_4 = F_63 ( V_9 ) ;
F_64 ( V_9 ) ;
F_61 ( & V_4 -> V_3 ) ;
return 0 ;
}
