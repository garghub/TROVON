static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [] = { 0x00 } ;
T_1 V_6 [] = { 0x00 } ;
struct V_7 V_8 [ 2 ] ;
V_8 [ 0 ] . V_9 = 0 ;
V_8 [ 1 ] . V_9 = V_10 ;
V_8 [ 0 ] . V_11 = V_8 [ 1 ] . V_11 = V_3 / 2 ;
V_5 [ 0 ] = V_4 ;
V_8 [ 0 ] . V_12 = 1 ;
V_8 [ 1 ] . V_12 = 1 ;
V_8 [ 0 ] . V_13 = V_5 ;
V_8 [ 1 ] . V_13 = V_6 ;
F_2 ( V_2 , V_8 , 2 ) ;
return V_6 [ 0 ] ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_13 , T_1 V_12 )
{
T_1 V_5 [] = { V_4 } ;
struct V_7 V_8 [ 2 ] = {
{ . V_11 = V_3 / 2 , . V_9 = 0 , . V_13 = V_5 , . V_12 = 1 } ,
{ . V_11 = V_3 / 2 , . V_9 = V_10 , . V_13 = V_13 , . V_12 = V_12 }
} ;
if ( F_2 ( V_2 , V_8 , 2 ) != 2 )
return - V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_15 )
{
T_1 V_16 [ 2 ] = { V_4 , V_15 } ;
struct V_7 V_8 ;
V_8 . V_9 = 0 ;
V_8 . V_11 = V_3 / 2 ;
V_8 . V_12 = 2 ;
V_8 . V_13 = V_16 ;
return F_2 ( V_2 , & V_8 , 1 ) ;
}
static int F_5 ( struct V_17 * V_18 , int V_19 , int V_20 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
int V_23 ;
if ( V_19 != 0 )
return - V_24 ;
F_6 ( V_21 -> V_25 . V_26 , 1 , V_27 ) ;
F_7 ( 1 ) ;
V_23 = F_8 ( & V_21 -> V_25 , V_28 , V_20 & 0xfff , 1 , 0 , 1 ) ;
if ( V_23 == - V_29 ) {
F_9 ( V_18 , V_19 ) ;
F_10 ( V_30 L_1 ) ;
}
return V_23 ;
}
static int F_11 ( struct V_17 * V_18 , int V_19 , int V_20 , T_1 V_31 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
int V_23 ;
if ( V_19 != 0 )
return - V_24 ;
F_6 ( V_21 -> V_25 . V_26 , 1 , V_27 ) ;
F_7 ( 1 ) ;
V_23 = F_12 ( & V_21 -> V_25 , V_28 , V_20 & 0xfff , 1 , V_31 , 0 , 1 ) ;
if ( V_23 == - V_29 ) {
F_9 ( V_18 , V_19 ) ;
F_10 ( V_30 L_2 ) ;
}
return V_23 ;
}
static int F_13 ( struct V_17 * V_18 , int V_19 , T_1 V_20 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
int V_23 ;
if ( V_19 != 0 )
return - V_24 ;
F_6 ( V_21 -> V_25 . V_26 , 1 , V_32 ) ;
F_7 ( 1 ) ;
V_23 = F_8 ( & V_21 -> V_25 , V_28 , V_20 & 3 , 1 , 0 , 0 ) ;
if ( V_23 == - V_29 ) {
F_9 ( V_18 , V_19 ) ;
F_10 ( V_30 L_3 ) ;
return - V_29 ;
}
return V_23 ;
}
static int F_14 ( struct V_17 * V_18 , int V_19 , T_1 V_20 , T_1 V_31 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
int V_23 ;
if ( V_19 != 0 )
return - V_24 ;
F_6 ( V_21 -> V_25 . V_26 , 1 , V_32 ) ;
F_7 ( 1 ) ;
V_23 = F_12 ( & V_21 -> V_25 , V_28 , V_20 & 3 , 1 , V_31 , 0 , 0 ) ;
if ( V_23 == - V_29 ) {
F_9 ( V_18 , V_19 ) ;
F_10 ( V_30 L_4 ) ;
}
return V_23 ;
}
static int F_15 ( struct V_17 * V_18 , int V_19 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
struct V_33 * V_34 = V_21 -> V_25 . V_26 ;
if ( V_19 != 0 )
return - V_24 ;
F_16 ( 1 , L_5 ) ;
V_21 -> V_35 = V_36 ;
F_6 ( V_34 , 2 , V_27 ) ;
F_6 ( V_34 , 0 , V_27 ) ;
F_17 ( 2 ) ;
F_6 ( V_34 , 0 , V_32 ) ;
F_17 ( 20 ) ;
F_6 ( V_34 , 2 , V_32 ) ;
F_18 ( V_34 , V_37 ) ;
F_17 ( 20 ) ;
if ( V_21 -> V_38 )
F_19 ( V_21 -> V_25 . V_39 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , int V_19 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
struct V_33 * V_34 = V_21 -> V_25 . V_26 ;
if ( V_19 != 0 )
return - V_24 ;
F_16 ( 1 , L_6 ) ;
F_18 ( V_34 , V_37 ) ;
V_21 -> V_35 = V_40 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 , int V_19 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
struct V_33 * V_34 = V_21 -> V_25 . V_26 ;
if ( V_19 != 0 )
return - V_24 ;
F_16 ( 1 , L_7 , V_21 -> V_35 ) ;
F_18 ( V_34 , V_41 ) ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 , int V_19 , int V_42 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
struct V_33 * V_34 = V_21 -> V_25 . V_26 ;
int V_23 ;
if ( V_19 != 0 )
return - V_24 ;
if ( V_21 -> V_35 == V_40 ) {
F_6 ( V_34 , 3 , V_43 ) ;
F_7 ( 1 ) ;
if ( F_22 ( V_34 , V_44 ) & V_45 ) {
if ( V_21 -> V_35 == V_40 ) {
V_21 -> V_35 = V_46 ;
F_10 ( V_30 L_8 ) ;
}
}
F_6 ( V_34 , 3 , V_32 ) ;
}
if ( ( V_21 -> V_35 == V_40 ) || ( ! V_42 ) ) {
F_6 ( V_21 -> V_25 . V_26 , 1 , V_32 ) ;
V_23 = F_8 ( & V_21 -> V_25 , V_28 , 0 , 1 , 0 , 1 ) ;
if ( ( V_23 >= 0 ) && ( V_21 -> V_35 == V_40 ) ) {
V_21 -> V_35 = V_46 ;
F_10 ( V_30 L_9 ) ;
} else if ( V_23 < 0 ) {
if ( V_21 -> V_35 != V_40 ) {
F_9 ( V_18 , V_19 ) ;
F_10 ( V_30 L_4 ) ;
return 0 ;
}
}
}
if ( V_21 -> V_35 == V_36 ) {
V_23 = F_5 ( V_18 , V_19 , 0 ) ;
if ( V_23 == 0x1d ) {
V_21 -> V_35 = V_47 ;
}
}
if ( V_21 -> V_35 != V_40 ) {
if ( V_21 -> V_35 & V_47 ) {
return V_48 | V_49 ;
}
return V_48 ;
}
return 0 ;
}
static int F_23 ( struct V_21 * V_21 )
{
struct V_33 * V_34 = V_21 -> V_25 . V_26 ;
int V_23 ;
memset ( & V_21 -> V_18 , 0 , sizeof( struct V_17 ) ) ;
F_6 ( V_34 , 0 , V_32 ) ;
F_6 ( V_34 , 1 , V_32 ) ;
F_6 ( V_34 , 2 , V_32 ) ;
F_6 ( V_34 , 3 , V_32 ) ;
F_24 ( V_34 , V_50 , V_51 | V_52 ) ;
V_21 -> V_18 . V_53 = V_54 ;
V_21 -> V_18 . V_55 = F_5 ;
V_21 -> V_18 . V_56 = F_11 ;
V_21 -> V_18 . V_57 = F_13 ;
V_21 -> V_18 . V_58 = F_14 ;
V_21 -> V_18 . V_59 = F_15 ;
V_21 -> V_18 . V_60 = F_9 ;
V_21 -> V_18 . V_61 = F_20 ;
V_21 -> V_18 . V_62 = F_21 ;
V_21 -> V_18 . V_22 = V_21 ;
V_21 -> V_25 . V_63 = 1 ;
V_21 -> V_35 = V_40 ;
if ( ( V_23 = F_25 ( & V_21 -> V_25 . V_64 ,
& V_21 -> V_18 , 0 , 1 ) ) != 0 ) {
F_10 ( V_65 L_10 ) ;
goto error;
}
F_10 ( V_30 L_11 ) ;
return 0 ;
error:
F_24 ( V_34 , V_50 , V_51 ) ;
return V_23 ;
}
static void F_26 ( struct V_21 * V_21 )
{
struct V_33 * V_34 = V_21 -> V_25 . V_26 ;
F_6 ( V_34 , 0 , V_43 ) ;
F_6 ( V_34 , 1 , V_43 ) ;
F_6 ( V_34 , 2 , V_43 ) ;
F_6 ( V_34 , 3 , V_43 ) ;
F_27 ( & V_21 -> V_18 ) ;
F_24 ( V_34 , V_50 , V_51 ) ;
}
static int F_28 ( struct V_21 * V_21 )
{
struct V_25 * V_25 = & V_21 -> V_25 ;
struct V_33 * V_34 = V_25 -> V_26 ;
const T_1 * V_22 = V_66 ;
F_6 ( V_34 , 0 , V_27 ) ;
F_17 ( 200 ) ;
if ( F_4 ( & V_25 -> V_67 , 0x4a , 0x01 , 0x08 ) != 1 ) {
F_16 ( 1 , L_12 ) ;
return - V_68 ;
}
F_16 ( 1 , L_13 ) ;
while ( * V_22 != 0xff ) {
F_4 ( & V_25 -> V_67 , 0x4a , * V_22 , * ( V_22 + 1 ) ) ;
V_22 += 2 ;
}
F_16 ( 1 , L_14 , F_1 ( & V_25 -> V_67 , 0x4a , 0x1f ) ) ;
return 0 ;
}
static int F_29 ( struct V_21 * V_21 , int V_69 )
{
struct V_25 * V_25 = & V_21 -> V_25 ;
if ( 1 != V_21 -> V_70 )
return - V_68 ;
if ( V_69 == 1 ) {
F_4 ( & V_25 -> V_67 , 0x4a , 0x02 , 0xc7 ) ;
F_4 ( & V_25 -> V_67 , 0x4a , 0x09 , 0x80 ) ;
} else if ( V_69 == 0 ) {
F_4 ( & V_25 -> V_67 , 0x4a , 0x02 , 0xc0 ) ;
F_4 ( & V_25 -> V_67 , 0x4a , 0x09 , 0x00 ) ;
} else
return - V_24 ;
V_21 -> V_71 = V_69 ;
return 0 ;
}
static int F_30 ( struct V_39 * V_72 , T_2 V_73 , T_2 V_74 )
{
T_1 V_75 = 0 ;
T_1 V_76 = 0 ;
T_1 V_77 ;
V_75 = 0xb5 ;
if ( V_73 < 2000000 )
V_76 = 0x86 ;
else if ( V_73 < 5000000 )
V_76 = 0x89 ;
else if ( V_73 < 15000000 )
V_76 = 0x8f ;
else if ( V_73 < 45000000 )
V_76 = 0x95 ;
V_77 = 0x14 ;
if ( V_73 < 4000000 )
V_77 = 0x10 ;
F_31 ( V_72 , 0x13 , V_75 ) ;
F_31 ( V_72 , 0x14 , V_76 ) ;
F_31 ( V_72 , 0x1f , ( V_74 >> 16 ) & 0xff ) ;
F_31 ( V_72 , 0x20 , ( V_74 >> 8 ) & 0xff ) ;
F_31 ( V_72 , 0x21 , ( V_74 ) & 0xf0 ) ;
F_31 ( V_72 , 0x0f , 0x80 | V_77 ) ;
return 0 ;
}
static int F_32 ( struct V_39 * V_72 ,
struct V_78 * V_79 )
{
T_2 div ;
T_1 V_13 [ 4 ] ;
struct V_25 * V_25 = (struct V_25 * ) V_72 -> V_80 -> V_81 ;
struct V_7 V_16 = { . V_11 = 0x61 , . V_9 = 0 , . V_13 = V_13 , . V_12 = sizeof( V_13 ) } ;
if ( ( V_79 -> V_82 < 950000 ) || ( V_79 -> V_82 > 2150000 ) )
return - V_24 ;
div = ( V_79 -> V_82 + ( 125 - 1 ) ) / 125 ;
V_13 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_13 [ 1 ] = div & 0xff ;
V_13 [ 2 ] = 0x80 | ( ( div & 0x18000 ) >> 10 ) | 4 ;
V_13 [ 3 ] = 0x20 ;
if ( V_79 -> V_83 . V_84 . V_85 < 4000000 )
V_13 [ 3 ] |= 1 ;
if ( V_79 -> V_82 < 1250000 )
V_13 [ 3 ] |= 0 ;
else if ( V_79 -> V_82 < 1550000 )
V_13 [ 3 ] |= 0x40 ;
else if ( V_79 -> V_82 < 2050000 )
V_13 [ 3 ] |= 0x80 ;
else if ( V_79 -> V_82 < 2150000 )
V_13 [ 3 ] |= 0xC0 ;
if ( V_72 -> V_86 . V_87 )
V_72 -> V_86 . V_87 ( V_72 , 1 ) ;
if ( F_2 ( & V_25 -> V_67 , & V_16 , 1 ) != 1 )
return - V_14 ;
return 0 ;
}
static int F_33 ( struct V_39 * V_72 , struct V_78 * V_79 )
{
struct V_25 * V_25 = (struct V_25 * ) V_72 -> V_80 -> V_81 ;
T_1 V_13 [ 6 ] ;
struct V_7 V_16 = { . V_11 = 0x60 , . V_9 = 0 , . V_13 = V_13 , . V_12 = sizeof( V_13 ) } ;
int V_88 ;
#define F_34 36125000
#define F_35 62500
T_2 div = ( V_79 -> V_82 + F_34 + F_35 / 2 ) / F_35 ;
V_13 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_13 [ 1 ] = div & 0xff ;
V_13 [ 2 ] = 0xce ;
V_13 [ 3 ] = ( V_79 -> V_82 < 150000000 ? 0x01 :
V_79 -> V_82 < 445000000 ? 0x02 : 0x04 ) ;
V_13 [ 4 ] = 0xde ;
V_13 [ 5 ] = 0x20 ;
if ( V_72 -> V_86 . V_87 )
V_72 -> V_86 . V_87 ( V_72 , 1 ) ;
if ( F_2 ( & V_25 -> V_67 , & V_16 , 1 ) != 1 )
return - V_14 ;
V_16 . V_9 = V_10 ;
V_16 . V_12 = 1 ;
for ( V_88 = 0 ; V_88 < 20 ; V_88 ++ ) {
if ( V_72 -> V_86 . V_87 )
V_72 -> V_86 . V_87 ( V_72 , 1 ) ;
if ( F_2 ( & V_25 -> V_67 , & V_16 , 1 ) == 1 && ( V_13 [ 0 ] & 0x40 ) )
break;
F_17 ( 10 ) ;
}
V_16 . V_9 = 0 ;
V_16 . V_12 = 2 ;
V_16 . V_13 = & V_13 [ 2 ] ;
V_13 [ 2 ] &= ~ 0x40 ;
if ( V_72 -> V_86 . V_87 )
V_72 -> V_86 . V_87 ( V_72 , 1 ) ;
if ( F_2 ( & V_25 -> V_67 , & V_16 , 1 ) != 1 )
return - V_14 ;
return 0 ;
}
static int F_36 ( struct V_39 * V_72 )
{
struct V_25 * V_25 = (struct V_25 * ) V_72 -> V_80 -> V_81 ;
static T_1 V_89 [] = { 0x0b , 0xf5 , 0x85 , 0xab } ;
struct V_7 V_90 = { . V_11 = 0x60 , . V_9 = 0 , . V_13 = V_89 , . V_12 = sizeof( V_89 ) } ;
if ( V_72 -> V_86 . V_87 )
V_72 -> V_86 . V_87 ( V_72 , 1 ) ;
if ( F_2 ( & V_25 -> V_67 , & V_90 , 1 ) != 1 )
return - V_14 ;
F_17 ( 1 ) ;
return 0 ;
}
static int F_37 ( struct V_39 * V_72 , struct V_78 * V_79 )
{
struct V_25 * V_25 = (struct V_25 * ) V_72 -> V_80 -> V_81 ;
T_1 V_91 [ 4 ] ;
struct V_7 V_90 = { . V_11 = 0x60 , . V_9 = 0 , . V_13 = V_91 , . V_12 =
sizeof( V_91 ) } ;
int V_92 = 0 ;
T_1 V_93 , V_94 , V_95 ;
V_92 = V_79 -> V_82 + 36166000 ;
if ( V_92 < 87000000 )
return - V_24 ;
else if ( V_92 < 130000000 )
V_94 = 3 ;
else if ( V_92 < 160000000 )
V_94 = 5 ;
else if ( V_92 < 200000000 )
V_94 = 6 ;
else if ( V_92 < 290000000 )
V_94 = 3 ;
else if ( V_92 < 420000000 )
V_94 = 5 ;
else if ( V_92 < 480000000 )
V_94 = 6 ;
else if ( V_92 < 620000000 )
V_94 = 3 ;
else if ( V_92 < 830000000 )
V_94 = 5 ;
else if ( V_92 < 895000000 )
V_94 = 7 ;
else
return - V_24 ;
if ( V_79 -> V_82 < 49000000 )
return - V_24 ;
else if ( V_79 -> V_82 < 161000000 )
V_93 = 1 ;
else if ( V_79 -> V_82 < 444000000 )
V_93 = 2 ;
else if ( V_79 -> V_82 < 861000000 )
V_93 = 4 ;
else
return - V_24 ;
switch ( V_79 -> V_83 . V_96 . V_97 ) {
case V_98 :
V_95 = 0 ;
break;
case V_99 :
V_95 = 0 ;
break;
case V_100 :
V_95 = 1 ;
break;
default:
return - V_24 ;
}
V_92 = ( ( ( V_79 -> V_82 / 1000 ) * 6 ) + 217496 ) / 1000 ;
V_91 [ 0 ] = ( V_92 >> 8 ) & 0x7f ;
V_91 [ 1 ] = V_92 & 0xff ;
V_91 [ 2 ] = 0xca ;
V_91 [ 3 ] = ( V_94 << 5 ) | ( V_95 << 3 ) | V_93 ;
if ( V_72 -> V_86 . V_87 )
V_72 -> V_86 . V_87 ( V_72 , 1 ) ;
if ( F_2 ( & V_25 -> V_67 , & V_90 , 1 ) != 1 )
return - V_14 ;
F_17 ( 1 ) ;
return 0 ;
}
static int F_38 ( struct V_39 * V_72 ,
const struct V_101 * * V_102 , char * V_103 )
{
struct V_25 * V_25 = (struct V_25 * ) V_72 -> V_80 -> V_81 ;
return F_39 ( V_102 , V_103 , & V_25 -> V_26 -> V_104 -> V_26 ) ;
}
static int F_40 ( struct V_39 * V_72 ,
T_2 V_73 , T_2 V_74 )
{
T_1 V_75 = 0 ;
T_1 V_76 = 0 ;
T_1 V_77 ;
V_75 = 0xb5 ;
if ( V_73 < 2000000 )
V_76 = 0x86 ;
else if ( V_73 < 5000000 )
V_76 = 0x89 ;
else if ( V_73 < 15000000 )
V_76 = 0x8f ;
else if ( V_73 < 45000000 )
V_76 = 0x95 ;
V_77 = 0x14 ;
if ( V_73 < 4000000 )
V_77 = 0x10 ;
F_31 ( V_72 , 0x0e , 0x23 ) ;
F_31 ( V_72 , 0x0f , 0x94 ) ;
F_31 ( V_72 , 0x10 , 0x39 ) ;
F_31 ( V_72 , 0x13 , V_75 ) ;
F_31 ( V_72 , 0x14 , V_76 ) ;
F_31 ( V_72 , 0x15 , 0xc9 ) ;
F_31 ( V_72 , 0x1f , ( V_74 >> 16 ) & 0xff ) ;
F_31 ( V_72 , 0x20 , ( V_74 >> 8 ) & 0xff ) ;
F_31 ( V_72 , 0x21 , ( V_74 ) & 0xf0 ) ;
F_31 ( V_72 , 0x0f , 0x80 | V_77 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_21 * V_21 )
{
T_1 V_105 = 0xff ;
T_1 V_106 ;
struct V_7 V_16 [] = { { . V_11 = 0x50 , . V_9 = 0 , . V_13 = & V_105 , . V_12 = 1 } ,
{ . V_11 = 0x50 , . V_9 = V_10 , . V_13 = & V_106 , . V_12 = 1 }
} ;
if ( ( F_2 ( & V_21 -> V_25 . V_67 , V_16 , 2 ) != 2 )
|| ( V_106 == 0xff ) )
V_106 = 0x48 ;
return V_106 ;
}
static void F_42 ( struct V_21 * V_21 )
{
struct V_33 * V_34 = V_21 -> V_25 . V_26 ;
struct V_39 * V_72 = NULL ;
F_6 ( V_34 , 0 , V_32 ) ;
F_17 ( 100 ) ;
switch ( V_34 -> V_104 -> V_107 ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_6 ( V_34 , 3 , V_27 ) ;
break;
}
switch ( V_34 -> V_104 -> V_107 ) {
case V_116 :
V_21 -> V_38 = 1 ;
case V_108 :
case V_117 :
if ( V_34 -> V_104 -> V_118 == 0x1894 ) {
V_72 = F_43 ( V_119 , & V_120 ,
& V_21 -> V_25 . V_67 ) ;
if ( V_72 ) {
F_43 ( V_121 , V_72 , 0x60 , & V_21 -> V_25 . V_67 ) ;
}
} else {
V_72 = F_43 ( V_119 , & V_122 ,
& V_21 -> V_25 . V_67 ) ;
if ( V_72 ) {
V_72 -> V_86 . V_123 . V_124 = F_32 ;
}
}
break;
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_72 = F_43 ( V_119 , & V_131 ,
& V_21 -> V_25 . V_67 ) ;
if ( V_72 ) {
F_43 ( V_132 , V_72 , 0x60 ,
& V_21 -> V_25 . V_67 ,
V_133 ) ;
}
break;
case V_134 :
V_72 = F_43 ( V_119 , & V_122 ,
& V_21 -> V_25 . V_67 ) ;
if ( V_72 ) {
V_72 -> V_86 . V_123 . V_124 = F_32 ;
}
break;
case V_113 :
case V_114 :
case V_115 :
V_21 -> V_38 = 1 ;
if ( ( V_72 = F_43 ( V_135 , & V_136 , & V_21 -> V_25 . V_67 ) ) )
F_43 ( V_137 , V_72 , & V_138 , & V_21 -> V_25 . V_67 ) ;
break;
case V_139 :
V_72 = F_43 ( V_119 , & V_140 ,
& V_21 -> V_25 . V_67 ) ;
if ( V_72 ) {
V_72 -> V_86 . V_123 . V_124 = F_32 ;
}
break;
case V_141 :
case V_109 :
case V_142 :
case V_111 :
V_21 -> V_38 = 1 ;
V_21 -> V_25 . V_26 -> V_143 = V_144 ;
V_72 = F_43 ( V_145 , & V_146 ,
& V_21 -> V_25 . V_67 ,
F_41 ( V_21 ) ) ;
if ( V_72 == NULL )
V_72 = F_43 ( V_145 , & V_147 ,
& V_21 -> V_25 . V_67 ,
F_41 ( V_21 ) ) ;
if ( V_72 ) {
V_72 -> V_86 . V_123 . V_124 = F_33 ;
}
break;
case V_148 :
case V_149 :
case V_150 :
case V_112 :
V_21 -> V_38 = 1 ;
V_21 -> V_25 . V_26 -> V_143 = V_144 ;
V_72 = F_43 ( V_151 ,
& V_152 ,
& V_21 -> V_25 . V_67 ,
F_41 ( V_21 ) ) ;
if ( V_72 ) {
V_72 -> V_86 . V_123 . V_124 = F_33 ;
}
break;
case V_153 :
case V_154 :
case V_110 :
case V_155 :
V_21 -> V_38 = 1 ;
V_72 = F_43 ( V_156 , & V_157 ,
& V_21 -> V_25 . V_67 ) ;
if ( V_72 ) {
V_72 -> V_86 . V_123 . V_158 = F_36 ;
V_72 -> V_86 . V_123 . V_124 = F_37 ;
}
break;
}
if ( V_72 == NULL ) {
F_10 ( V_65 L_15
L_16 ,
V_34 -> V_104 -> V_159 ,
V_34 -> V_104 -> V_160 ,
V_34 -> V_104 -> V_118 ,
V_34 -> V_104 -> V_107 ) ;
return;
}
V_21 -> V_25 . V_39 = V_72 ;
if ( F_44 ( & V_21 -> V_25 . V_64 ,
V_21 -> V_25 . V_39 ) ) {
F_10 ( V_65 L_17 ) ;
F_45 ( V_21 -> V_25 . V_39 ) ;
V_21 -> V_25 . V_39 = NULL ;
}
}
static void F_46 ( struct V_33 * V_26 , T_2 * V_161 )
{
struct V_21 * V_21 = (struct V_21 * ) V_26 -> V_162 ;
F_16 ( 8 , L_18 , V_26 , V_21 ) ;
if ( * V_161 & V_163 )
F_47 ( V_26 , V_161 ) ;
}
static int F_48 ( struct V_33 * V_26 )
{
struct V_21 * V_21 = (struct V_21 * ) V_26 -> V_162 ;
int V_164 ;
F_16 ( 2 , L_19 , V_26 ) ;
if ( 1 == V_21 -> V_70 ) {
F_6 ( V_26 , 0 , V_32 ) ;
F_17 ( 200 ) ;
F_49 ( & V_21 -> V_165 , V_26 ) ;
F_50 ( V_26 ) ;
}
if ( V_21 -> V_25 . V_63 )
F_26 ( V_21 ) ;
if ( V_21 -> V_25 . V_39 != NULL ) {
F_51 ( V_21 -> V_25 . V_39 ) ;
F_45 ( V_21 -> V_25 . V_39 ) ;
}
V_164 = F_52 ( & V_21 -> V_25 ) ;
F_53 ( V_21 ) ;
return V_164 ;
}
static int F_54 ( struct V_166 * V_166 , void * V_167 , struct V_168 * V_88 )
{
F_16 ( 1 , L_20 , V_88 -> V_169 ) ;
if ( V_88 -> V_169 >= V_170 )
return - V_24 ;
memcpy ( V_88 , & V_171 [ V_88 -> V_169 ] , sizeof( struct V_168 ) ) ;
return 0 ;
}
static int F_55 ( struct V_166 * V_166 , void * V_167 , unsigned int * V_88 )
{
struct V_33 * V_26 = ( (struct V_172 * ) V_167 ) -> V_26 ;
struct V_21 * V_21 = (struct V_21 * ) V_26 -> V_162 ;
* V_88 = V_21 -> V_71 ;
F_16 ( 1 , L_21 , * V_88 ) ;
return 0 ;
}
static int F_56 ( struct V_166 * V_166 , void * V_167 , unsigned int V_69 )
{
struct V_33 * V_26 = ( (struct V_172 * ) V_167 ) -> V_26 ;
struct V_21 * V_21 = (struct V_21 * ) V_26 -> V_162 ;
F_16 ( 1 , L_22 , V_69 ) ;
return F_29 ( V_21 , V_69 ) ;
}
static int F_57 ( struct V_33 * V_26 , struct V_173 * V_174 )
{
struct V_21 * V_21 ;
T_1 * V_175 ;
int V_164 ;
F_16 ( 2 , L_19 , V_26 ) ;
if ( ! ( V_21 = F_58 ( sizeof( struct V_21 ) , V_176 ) ) )
return - V_177 ;
V_21 -> V_70 = 0 ;
V_21 -> V_25 . V_63 = 0 ;
V_26 -> V_162 = V_21 ;
V_164 = F_59 ( & V_21 -> V_25 , V_26 , V_174 , V_54 ,
V_178 ) ;
if ( V_164 ) {
F_53 ( V_21 ) ;
return V_164 ;
}
F_24 ( V_26 , V_179 , 0x04000000 ) ;
F_24 ( V_26 , V_180 , 0x07000600 ) ;
F_24 ( V_26 , V_181 , V_182 | V_183 | V_163 | V_184 ) ;
if ( F_28 ( V_21 ) == 0 ) {
V_21 -> V_70 = 1 ;
if ( 0 != F_60 ( V_26 , & V_185 ) ) {
F_61 ( ( L_23 ) ) ;
return V_164 ;
}
V_185 . V_86 . F_54 = F_54 ;
V_185 . V_86 . F_55 = F_55 ;
V_185 . V_86 . F_56 = F_56 ;
if ( ( V_164 = F_62 ( & V_21 -> V_165 , V_26 , L_24 , V_186 ) ) ) {
F_61 ( ( L_25 ) ) ;
F_50 ( V_26 ) ;
return V_164 ;
}
F_63 ( V_26 , V_187 ,
V_188 ) ;
F_29 ( V_21 , 0 ) ;
}
F_24 ( V_26 , V_189 , 0x1c00101f ) ;
V_175 = V_21 -> V_25 . V_64 . V_190 ;
if ( F_3 ( & V_21 -> V_25 . V_67 , 0xa0 , 0x30 , V_175 , 6 ) ) {
F_10 ( V_65 L_26 ,
V_21 -> V_25 . V_64 . V_191 ) ;
memset ( V_175 , 0 , 6 ) ;
} else {
F_10 ( V_30 L_27 ,
V_21 -> V_25 . V_64 . V_191 ,
V_175 [ 0 ] , V_175 [ 1 ] , V_175 [ 2 ] , V_175 [ 3 ] , V_175 [ 4 ] , V_175 [ 5 ] ) ;
}
V_21 -> V_25 . V_64 . V_81 = V_21 ;
F_42 ( V_21 ) ;
F_23 ( V_21 ) ;
F_64 ( & V_21 -> V_25 ) ;
return 0 ;
}
static int T_3 F_65 ( void )
{
return F_66 ( & V_192 ) ;
}
static void T_4 F_67 ( void )
{
F_68 ( & V_192 ) ;
}
