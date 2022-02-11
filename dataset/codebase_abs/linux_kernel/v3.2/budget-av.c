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
F_10 ( L_1 ) ;
}
return V_23 ;
}
static int F_11 ( struct V_17 * V_18 , int V_19 , int V_20 , T_1 V_30 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
int V_23 ;
if ( V_19 != 0 )
return - V_24 ;
F_6 ( V_21 -> V_25 . V_26 , 1 , V_27 ) ;
F_7 ( 1 ) ;
V_23 = F_12 ( & V_21 -> V_25 , V_28 , V_20 & 0xfff , 1 , V_30 , 0 , 1 ) ;
if ( V_23 == - V_29 ) {
F_9 ( V_18 , V_19 ) ;
F_10 ( L_2 ) ;
}
return V_23 ;
}
static int F_13 ( struct V_17 * V_18 , int V_19 , T_1 V_20 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
int V_23 ;
if ( V_19 != 0 )
return - V_24 ;
F_6 ( V_21 -> V_25 . V_26 , 1 , V_31 ) ;
F_7 ( 1 ) ;
V_23 = F_8 ( & V_21 -> V_25 , V_28 , V_20 & 3 , 1 , 0 , 0 ) ;
if ( V_23 == - V_29 ) {
F_9 ( V_18 , V_19 ) ;
F_10 ( L_3 ) ;
return - V_29 ;
}
return V_23 ;
}
static int F_14 ( struct V_17 * V_18 , int V_19 , T_1 V_20 , T_1 V_30 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
int V_23 ;
if ( V_19 != 0 )
return - V_24 ;
F_6 ( V_21 -> V_25 . V_26 , 1 , V_31 ) ;
F_7 ( 1 ) ;
V_23 = F_12 ( & V_21 -> V_25 , V_28 , V_20 & 3 , 1 , V_30 , 0 , 0 ) ;
if ( V_23 == - V_29 ) {
F_9 ( V_18 , V_19 ) ;
F_10 ( L_4 ) ;
}
return V_23 ;
}
static int F_15 ( struct V_17 * V_18 , int V_19 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
struct V_32 * V_33 = V_21 -> V_25 . V_26 ;
if ( V_19 != 0 )
return - V_24 ;
F_16 ( 1 , L_5 ) ;
V_21 -> V_34 = V_35 ;
F_6 ( V_33 , 2 , V_27 ) ;
F_6 ( V_33 , 0 , V_27 ) ;
F_17 ( 2 ) ;
F_6 ( V_33 , 0 , V_31 ) ;
F_17 ( 20 ) ;
F_6 ( V_33 , 2 , V_31 ) ;
F_18 ( V_33 , V_36 ) ;
F_17 ( 20 ) ;
if ( V_21 -> V_37 )
F_19 ( V_21 -> V_25 . V_38 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , int V_19 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
struct V_32 * V_33 = V_21 -> V_25 . V_26 ;
if ( V_19 != 0 )
return - V_24 ;
F_16 ( 1 , L_6 ) ;
F_18 ( V_33 , V_36 ) ;
V_21 -> V_34 = V_39 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 , int V_19 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
struct V_32 * V_33 = V_21 -> V_25 . V_26 ;
if ( V_19 != 0 )
return - V_24 ;
F_16 ( 1 , L_7 , V_21 -> V_34 ) ;
F_18 ( V_33 , V_40 ) ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 , int V_19 , int V_41 )
{
struct V_21 * V_21 = (struct V_21 * ) V_18 -> V_22 ;
struct V_32 * V_33 = V_21 -> V_25 . V_26 ;
int V_23 ;
if ( V_19 != 0 )
return - V_24 ;
if ( V_21 -> V_34 == V_39 ) {
F_6 ( V_33 , 3 , V_42 ) ;
F_7 ( 1 ) ;
if ( F_22 ( V_33 , V_43 ) & V_44 ) {
if ( V_21 -> V_34 == V_39 ) {
V_21 -> V_34 = V_45 ;
F_10 ( L_8 ) ;
}
}
F_6 ( V_33 , 3 , V_31 ) ;
}
if ( ( V_21 -> V_34 == V_39 ) || ( ! V_41 ) ) {
F_6 ( V_21 -> V_25 . V_26 , 1 , V_31 ) ;
V_23 = F_8 ( & V_21 -> V_25 , V_28 , 0 , 1 , 0 , 1 ) ;
if ( ( V_23 >= 0 ) && ( V_21 -> V_34 == V_39 ) ) {
V_21 -> V_34 = V_45 ;
F_10 ( L_9 ) ;
} else if ( V_23 < 0 ) {
if ( V_21 -> V_34 != V_39 ) {
F_9 ( V_18 , V_19 ) ;
F_10 ( L_4 ) ;
return 0 ;
}
}
}
if ( V_21 -> V_34 == V_35 ) {
V_23 = F_5 ( V_18 , V_19 , 0 ) ;
if ( V_23 == 0x1d ) {
V_21 -> V_34 = V_46 ;
}
}
if ( V_21 -> V_34 != V_39 ) {
if ( V_21 -> V_34 & V_46 ) {
return V_47 | V_48 ;
}
return V_47 ;
}
return 0 ;
}
static int F_23 ( struct V_21 * V_21 )
{
struct V_32 * V_33 = V_21 -> V_25 . V_26 ;
int V_23 ;
memset ( & V_21 -> V_18 , 0 , sizeof( struct V_17 ) ) ;
F_6 ( V_33 , 0 , V_31 ) ;
F_6 ( V_33 , 1 , V_31 ) ;
F_6 ( V_33 , 2 , V_31 ) ;
F_6 ( V_33 , 3 , V_31 ) ;
F_24 ( V_33 , V_49 , V_50 | V_51 ) ;
V_21 -> V_18 . V_52 = V_53 ;
V_21 -> V_18 . V_54 = F_5 ;
V_21 -> V_18 . V_55 = F_11 ;
V_21 -> V_18 . V_56 = F_13 ;
V_21 -> V_18 . V_57 = F_14 ;
V_21 -> V_18 . V_58 = F_15 ;
V_21 -> V_18 . V_59 = F_9 ;
V_21 -> V_18 . V_60 = F_20 ;
V_21 -> V_18 . V_61 = F_21 ;
V_21 -> V_18 . V_22 = V_21 ;
V_21 -> V_25 . V_62 = 1 ;
V_21 -> V_34 = V_39 ;
if ( ( V_23 = F_25 ( & V_21 -> V_25 . V_63 ,
& V_21 -> V_18 , 0 , 1 ) ) != 0 ) {
F_26 ( L_10 ) ;
goto error;
}
F_10 ( L_11 ) ;
return 0 ;
error:
F_24 ( V_33 , V_49 , V_50 ) ;
return V_23 ;
}
static void F_27 ( struct V_21 * V_21 )
{
struct V_32 * V_33 = V_21 -> V_25 . V_26 ;
F_6 ( V_33 , 0 , V_42 ) ;
F_6 ( V_33 , 1 , V_42 ) ;
F_6 ( V_33 , 2 , V_42 ) ;
F_6 ( V_33 , 3 , V_42 ) ;
F_28 ( & V_21 -> V_18 ) ;
F_24 ( V_33 , V_49 , V_50 ) ;
}
static int F_29 ( struct V_21 * V_21 )
{
struct V_25 * V_25 = & V_21 -> V_25 ;
struct V_32 * V_33 = V_25 -> V_26 ;
const T_1 * V_22 = V_64 ;
F_6 ( V_33 , 0 , V_27 ) ;
F_17 ( 200 ) ;
if ( F_4 ( & V_25 -> V_65 , 0x4a , 0x01 , 0x08 ) != 1 ) {
F_16 ( 1 , L_12 ) ;
return - V_66 ;
}
F_16 ( 1 , L_13 ) ;
while ( * V_22 != 0xff ) {
F_4 ( & V_25 -> V_65 , 0x4a , * V_22 , * ( V_22 + 1 ) ) ;
V_22 += 2 ;
}
F_16 ( 1 , L_14 , F_1 ( & V_25 -> V_65 , 0x4a , 0x1f ) ) ;
return 0 ;
}
static int F_30 ( struct V_21 * V_21 , int V_67 )
{
struct V_25 * V_25 = & V_21 -> V_25 ;
if ( 1 != V_21 -> V_68 )
return - V_66 ;
if ( V_67 == 1 ) {
F_4 ( & V_25 -> V_65 , 0x4a , 0x02 , 0xc7 ) ;
F_4 ( & V_25 -> V_65 , 0x4a , 0x09 , 0x80 ) ;
} else if ( V_67 == 0 ) {
F_4 ( & V_25 -> V_65 , 0x4a , 0x02 , 0xc0 ) ;
F_4 ( & V_25 -> V_65 , 0x4a , 0x09 , 0x00 ) ;
} else
return - V_24 ;
V_21 -> V_69 = V_67 ;
return 0 ;
}
static int F_31 ( struct V_38 * V_70 , T_2 V_71 , T_2 V_72 )
{
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
T_1 V_75 ;
V_73 = 0xb5 ;
if ( V_71 < 2000000 )
V_74 = 0x86 ;
else if ( V_71 < 5000000 )
V_74 = 0x89 ;
else if ( V_71 < 15000000 )
V_74 = 0x8f ;
else if ( V_71 < 45000000 )
V_74 = 0x95 ;
V_75 = 0x14 ;
if ( V_71 < 4000000 )
V_75 = 0x10 ;
F_32 ( V_70 , 0x13 , V_73 ) ;
F_32 ( V_70 , 0x14 , V_74 ) ;
F_32 ( V_70 , 0x1f , ( V_72 >> 16 ) & 0xff ) ;
F_32 ( V_70 , 0x20 , ( V_72 >> 8 ) & 0xff ) ;
F_32 ( V_70 , 0x21 , ( V_72 ) & 0xf0 ) ;
F_32 ( V_70 , 0x0f , 0x80 | V_75 ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_70 ,
struct V_76 * V_77 )
{
T_2 div ;
T_1 V_13 [ 4 ] ;
struct V_25 * V_25 = (struct V_25 * ) V_70 -> V_78 -> V_79 ;
struct V_7 V_16 = { . V_11 = 0x61 , . V_9 = 0 , . V_13 = V_13 , . V_12 = sizeof( V_13 ) } ;
if ( ( V_77 -> V_80 < 950000 ) || ( V_77 -> V_80 > 2150000 ) )
return - V_24 ;
div = ( V_77 -> V_80 + ( 125 - 1 ) ) / 125 ;
V_13 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_13 [ 1 ] = div & 0xff ;
V_13 [ 2 ] = 0x80 | ( ( div & 0x18000 ) >> 10 ) | 4 ;
V_13 [ 3 ] = 0x20 ;
if ( V_77 -> V_81 . V_82 . V_83 < 4000000 )
V_13 [ 3 ] |= 1 ;
if ( V_77 -> V_80 < 1250000 )
V_13 [ 3 ] |= 0 ;
else if ( V_77 -> V_80 < 1550000 )
V_13 [ 3 ] |= 0x40 ;
else if ( V_77 -> V_80 < 2050000 )
V_13 [ 3 ] |= 0x80 ;
else if ( V_77 -> V_80 < 2150000 )
V_13 [ 3 ] |= 0xC0 ;
if ( V_70 -> V_84 . V_85 )
V_70 -> V_84 . V_85 ( V_70 , 1 ) ;
if ( F_2 ( & V_25 -> V_65 , & V_16 , 1 ) != 1 )
return - V_14 ;
return 0 ;
}
static int F_34 ( struct V_38 * V_70 , struct V_76 * V_77 )
{
struct V_25 * V_25 = (struct V_25 * ) V_70 -> V_78 -> V_79 ;
T_1 V_13 [ 6 ] ;
struct V_7 V_16 = { . V_11 = 0x60 , . V_9 = 0 , . V_13 = V_13 , . V_12 = sizeof( V_13 ) } ;
int V_86 ;
#define F_35 36125000
#define F_36 62500
T_2 div = ( V_77 -> V_80 + F_35 + F_36 / 2 ) / F_36 ;
V_13 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_13 [ 1 ] = div & 0xff ;
V_13 [ 2 ] = 0xce ;
V_13 [ 3 ] = ( V_77 -> V_80 < 150000000 ? 0x01 :
V_77 -> V_80 < 445000000 ? 0x02 : 0x04 ) ;
V_13 [ 4 ] = 0xde ;
V_13 [ 5 ] = 0x20 ;
if ( V_70 -> V_84 . V_85 )
V_70 -> V_84 . V_85 ( V_70 , 1 ) ;
if ( F_2 ( & V_25 -> V_65 , & V_16 , 1 ) != 1 )
return - V_14 ;
V_16 . V_9 = V_10 ;
V_16 . V_12 = 1 ;
for ( V_86 = 0 ; V_86 < 20 ; V_86 ++ ) {
if ( V_70 -> V_84 . V_85 )
V_70 -> V_84 . V_85 ( V_70 , 1 ) ;
if ( F_2 ( & V_25 -> V_65 , & V_16 , 1 ) == 1 && ( V_13 [ 0 ] & 0x40 ) )
break;
F_17 ( 10 ) ;
}
V_16 . V_9 = 0 ;
V_16 . V_12 = 2 ;
V_16 . V_13 = & V_13 [ 2 ] ;
V_13 [ 2 ] &= ~ 0x40 ;
if ( V_70 -> V_84 . V_85 )
V_70 -> V_84 . V_85 ( V_70 , 1 ) ;
if ( F_2 ( & V_25 -> V_65 , & V_16 , 1 ) != 1 )
return - V_14 ;
return 0 ;
}
static int F_37 ( struct V_38 * V_70 )
{
struct V_25 * V_25 = (struct V_25 * ) V_70 -> V_78 -> V_79 ;
static T_1 V_87 [] = { 0x0b , 0xf5 , 0x85 , 0xab } ;
struct V_7 V_88 = { . V_11 = 0x60 , . V_9 = 0 , . V_13 = V_87 , . V_12 = sizeof( V_87 ) } ;
if ( V_70 -> V_84 . V_85 )
V_70 -> V_84 . V_85 ( V_70 , 1 ) ;
if ( F_2 ( & V_25 -> V_65 , & V_88 , 1 ) != 1 )
return - V_14 ;
F_17 ( 1 ) ;
return 0 ;
}
static int F_38 ( struct V_38 * V_70 , struct V_76 * V_77 )
{
struct V_25 * V_25 = (struct V_25 * ) V_70 -> V_78 -> V_79 ;
T_1 V_89 [ 4 ] ;
struct V_7 V_88 = { . V_11 = 0x60 , . V_9 = 0 , . V_13 = V_89 , . V_12 =
sizeof( V_89 ) } ;
int V_90 = 0 ;
T_1 V_91 , V_92 , V_93 ;
V_90 = V_77 -> V_80 + 36166000 ;
if ( V_90 < 87000000 )
return - V_24 ;
else if ( V_90 < 130000000 )
V_92 = 3 ;
else if ( V_90 < 160000000 )
V_92 = 5 ;
else if ( V_90 < 200000000 )
V_92 = 6 ;
else if ( V_90 < 290000000 )
V_92 = 3 ;
else if ( V_90 < 420000000 )
V_92 = 5 ;
else if ( V_90 < 480000000 )
V_92 = 6 ;
else if ( V_90 < 620000000 )
V_92 = 3 ;
else if ( V_90 < 830000000 )
V_92 = 5 ;
else if ( V_90 < 895000000 )
V_92 = 7 ;
else
return - V_24 ;
if ( V_77 -> V_80 < 49000000 )
return - V_24 ;
else if ( V_77 -> V_80 < 161000000 )
V_91 = 1 ;
else if ( V_77 -> V_80 < 444000000 )
V_91 = 2 ;
else if ( V_77 -> V_80 < 861000000 )
V_91 = 4 ;
else
return - V_24 ;
switch ( V_77 -> V_81 . V_94 . V_95 ) {
case V_96 :
V_93 = 0 ;
break;
case V_97 :
V_93 = 0 ;
break;
case V_98 :
V_93 = 1 ;
break;
default:
return - V_24 ;
}
V_90 = ( ( ( V_77 -> V_80 / 1000 ) * 6 ) + 217496 ) / 1000 ;
V_89 [ 0 ] = ( V_90 >> 8 ) & 0x7f ;
V_89 [ 1 ] = V_90 & 0xff ;
V_89 [ 2 ] = 0xca ;
V_89 [ 3 ] = ( V_92 << 5 ) | ( V_93 << 3 ) | V_91 ;
if ( V_70 -> V_84 . V_85 )
V_70 -> V_84 . V_85 ( V_70 , 1 ) ;
if ( F_2 ( & V_25 -> V_65 , & V_88 , 1 ) != 1 )
return - V_14 ;
F_17 ( 1 ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_70 ,
const struct V_99 * * V_100 , char * V_101 )
{
struct V_25 * V_25 = (struct V_25 * ) V_70 -> V_78 -> V_79 ;
return F_40 ( V_100 , V_101 , & V_25 -> V_26 -> V_102 -> V_26 ) ;
}
static int F_41 ( struct V_38 * V_70 ,
T_2 V_71 , T_2 V_72 )
{
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
T_1 V_75 ;
V_73 = 0xb5 ;
if ( V_71 < 2000000 )
V_74 = 0x86 ;
else if ( V_71 < 5000000 )
V_74 = 0x89 ;
else if ( V_71 < 15000000 )
V_74 = 0x8f ;
else if ( V_71 < 45000000 )
V_74 = 0x95 ;
V_75 = 0x14 ;
if ( V_71 < 4000000 )
V_75 = 0x10 ;
F_32 ( V_70 , 0x0e , 0x23 ) ;
F_32 ( V_70 , 0x0f , 0x94 ) ;
F_32 ( V_70 , 0x10 , 0x39 ) ;
F_32 ( V_70 , 0x13 , V_73 ) ;
F_32 ( V_70 , 0x14 , V_74 ) ;
F_32 ( V_70 , 0x15 , 0xc9 ) ;
F_32 ( V_70 , 0x1f , ( V_72 >> 16 ) & 0xff ) ;
F_32 ( V_70 , 0x20 , ( V_72 >> 8 ) & 0xff ) ;
F_32 ( V_70 , 0x21 , ( V_72 ) & 0xf0 ) ;
F_32 ( V_70 , 0x0f , 0x80 | V_75 ) ;
return 0 ;
}
static T_1 F_42 ( struct V_21 * V_21 )
{
T_1 V_103 = 0xff ;
T_1 V_104 ;
struct V_7 V_16 [] = { { . V_11 = 0x50 , . V_9 = 0 , . V_13 = & V_103 , . V_12 = 1 } ,
{ . V_11 = 0x50 , . V_9 = V_10 , . V_13 = & V_104 , . V_12 = 1 }
} ;
if ( ( F_2 ( & V_21 -> V_25 . V_65 , V_16 , 2 ) != 2 )
|| ( V_104 == 0xff ) )
V_104 = 0x48 ;
return V_104 ;
}
static void F_43 ( struct V_21 * V_21 )
{
struct V_32 * V_33 = V_21 -> V_25 . V_26 ;
struct V_38 * V_70 = NULL ;
F_6 ( V_33 , 0 , V_31 ) ;
F_17 ( 100 ) ;
switch ( V_33 -> V_102 -> V_105 ) {
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
F_6 ( V_33 , 3 , V_27 ) ;
break;
}
switch ( V_33 -> V_102 -> V_105 ) {
case V_114 :
V_21 -> V_37 = 1 ;
case V_106 :
case V_115 :
if ( V_33 -> V_102 -> V_116 == 0x1894 ) {
V_70 = F_44 ( V_117 , & V_118 ,
& V_21 -> V_25 . V_65 ) ;
if ( V_70 ) {
F_44 ( V_119 , V_70 , 0x60 , & V_21 -> V_25 . V_65 ) ;
}
} else {
V_70 = F_44 ( V_117 , & V_120 ,
& V_21 -> V_25 . V_65 ) ;
if ( V_70 ) {
V_70 -> V_84 . V_121 . V_122 = F_33 ;
}
}
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
V_70 = F_44 ( V_117 , & V_129 ,
& V_21 -> V_25 . V_65 ) ;
if ( V_70 ) {
F_44 ( V_130 , V_70 , 0x60 ,
& V_21 -> V_25 . V_65 ,
V_131 ) ;
}
break;
case V_132 :
V_70 = F_44 ( V_117 , & V_120 ,
& V_21 -> V_25 . V_65 ) ;
if ( V_70 ) {
V_70 -> V_84 . V_121 . V_122 = F_33 ;
}
break;
case V_111 :
case V_112 :
case V_113 :
V_21 -> V_37 = 1 ;
if ( ( V_70 = F_44 ( V_133 , & V_134 , & V_21 -> V_25 . V_65 ) ) )
F_44 ( V_135 , V_70 , & V_136 , & V_21 -> V_25 . V_65 ) ;
break;
case V_137 :
V_70 = F_44 ( V_117 , & V_138 ,
& V_21 -> V_25 . V_65 ) ;
if ( V_70 ) {
V_70 -> V_84 . V_121 . V_122 = F_33 ;
}
break;
case V_139 :
case V_107 :
case V_140 :
case V_109 :
V_21 -> V_37 = 1 ;
V_21 -> V_25 . V_26 -> V_141 = V_142 ;
V_70 = F_44 ( V_143 , & V_144 ,
& V_21 -> V_25 . V_65 ,
F_42 ( V_21 ) ) ;
if ( V_70 == NULL )
V_70 = F_44 ( V_143 , & V_145 ,
& V_21 -> V_25 . V_65 ,
F_42 ( V_21 ) ) ;
if ( V_70 ) {
V_70 -> V_84 . V_121 . V_122 = F_34 ;
}
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_110 :
V_21 -> V_37 = 1 ;
V_21 -> V_25 . V_26 -> V_141 = V_142 ;
V_70 = F_44 ( V_150 ,
& V_151 ,
& V_21 -> V_25 . V_65 ,
F_42 ( V_21 ) ) ;
if ( V_70 ) {
V_70 -> V_84 . V_121 . V_122 = F_34 ;
}
break;
case V_152 :
case V_153 :
case V_108 :
case V_154 :
V_21 -> V_37 = 1 ;
V_70 = F_44 ( V_155 , & V_156 ,
& V_21 -> V_25 . V_65 ) ;
if ( V_70 ) {
V_70 -> V_84 . V_121 . V_157 = F_37 ;
V_70 -> V_84 . V_121 . V_122 = F_38 ;
}
break;
}
if ( V_70 == NULL ) {
F_26 ( L_15 ,
V_33 -> V_102 -> V_158 ,
V_33 -> V_102 -> V_159 ,
V_33 -> V_102 -> V_116 ,
V_33 -> V_102 -> V_105 ) ;
return;
}
V_21 -> V_25 . V_38 = V_70 ;
if ( F_45 ( & V_21 -> V_25 . V_63 ,
V_21 -> V_25 . V_38 ) ) {
F_26 ( L_16 ) ;
F_46 ( V_21 -> V_25 . V_38 ) ;
V_21 -> V_25 . V_38 = NULL ;
}
}
static void F_47 ( struct V_32 * V_26 , T_2 * V_160 )
{
struct V_21 * V_21 = (struct V_21 * ) V_26 -> V_161 ;
F_16 ( 8 , L_17 , V_26 , V_21 ) ;
if ( * V_160 & V_162 )
F_48 ( V_26 , V_160 ) ;
}
static int F_49 ( struct V_32 * V_26 )
{
struct V_21 * V_21 = (struct V_21 * ) V_26 -> V_161 ;
int V_163 ;
F_16 ( 2 , L_18 , V_26 ) ;
if ( 1 == V_21 -> V_68 ) {
F_6 ( V_26 , 0 , V_31 ) ;
F_17 ( 200 ) ;
F_50 ( & V_21 -> V_164 , V_26 ) ;
F_51 ( V_26 ) ;
}
if ( V_21 -> V_25 . V_62 )
F_27 ( V_21 ) ;
if ( V_21 -> V_25 . V_38 != NULL ) {
F_52 ( V_21 -> V_25 . V_38 ) ;
F_46 ( V_21 -> V_25 . V_38 ) ;
}
V_163 = F_53 ( & V_21 -> V_25 ) ;
F_54 ( V_21 ) ;
return V_163 ;
}
static int F_55 ( struct V_165 * V_165 , void * V_166 , struct V_167 * V_86 )
{
F_16 ( 1 , L_19 , V_86 -> V_168 ) ;
if ( V_86 -> V_168 >= V_169 )
return - V_24 ;
memcpy ( V_86 , & V_170 [ V_86 -> V_168 ] , sizeof( struct V_167 ) ) ;
return 0 ;
}
static int F_56 ( struct V_165 * V_165 , void * V_166 , unsigned int * V_86 )
{
struct V_32 * V_26 = ( (struct V_171 * ) V_166 ) -> V_26 ;
struct V_21 * V_21 = (struct V_21 * ) V_26 -> V_161 ;
* V_86 = V_21 -> V_69 ;
F_16 ( 1 , L_20 , * V_86 ) ;
return 0 ;
}
static int F_57 ( struct V_165 * V_165 , void * V_166 , unsigned int V_67 )
{
struct V_32 * V_26 = ( (struct V_171 * ) V_166 ) -> V_26 ;
struct V_21 * V_21 = (struct V_21 * ) V_26 -> V_161 ;
F_16 ( 1 , L_21 , V_67 ) ;
return F_30 ( V_21 , V_67 ) ;
}
static int F_58 ( struct V_32 * V_26 , struct V_172 * V_173 )
{
struct V_21 * V_21 ;
T_1 * V_174 ;
int V_163 ;
F_16 ( 2 , L_18 , V_26 ) ;
if ( ! ( V_21 = F_59 ( sizeof( struct V_21 ) , V_175 ) ) )
return - V_176 ;
V_21 -> V_68 = 0 ;
V_21 -> V_25 . V_62 = 0 ;
V_26 -> V_161 = V_21 ;
V_163 = F_60 ( & V_21 -> V_25 , V_26 , V_173 , V_53 ,
V_177 ) ;
if ( V_163 ) {
F_54 ( V_21 ) ;
return V_163 ;
}
F_24 ( V_26 , V_178 , 0x04000000 ) ;
F_24 ( V_26 , V_179 , 0x07000600 ) ;
F_24 ( V_26 , V_180 , V_181 | V_182 | V_162 | V_183 ) ;
if ( F_29 ( V_21 ) == 0 ) {
V_21 -> V_68 = 1 ;
if ( 0 != F_61 ( V_26 , & V_184 ) ) {
F_62 ( L_22 ) ;
return V_163 ;
}
V_184 . V_84 . F_55 = F_55 ;
V_184 . V_84 . F_56 = F_56 ;
V_184 . V_84 . F_57 = F_57 ;
if ( ( V_163 = F_63 ( & V_21 -> V_164 , V_26 , L_23 , V_185 ) ) ) {
F_62 ( L_24 ) ;
F_51 ( V_26 ) ;
return V_163 ;
}
F_64 ( V_26 , V_186 ,
V_187 ) ;
F_30 ( V_21 , 0 ) ;
}
F_24 ( V_26 , V_188 , 0x1c00101f ) ;
V_174 = V_21 -> V_25 . V_63 . V_189 ;
if ( F_3 ( & V_21 -> V_25 . V_65 , 0xa0 , 0x30 , V_174 , 6 ) ) {
F_26 ( L_25 ,
V_21 -> V_25 . V_63 . V_190 ) ;
memset ( V_174 , 0 , 6 ) ;
} else {
F_10 ( L_26 ,
V_21 -> V_25 . V_63 . V_190 , V_174 ) ;
}
V_21 -> V_25 . V_63 . V_79 = V_21 ;
F_43 ( V_21 ) ;
F_23 ( V_21 ) ;
F_65 ( & V_21 -> V_25 ) ;
return 0 ;
}
static int T_3 F_66 ( void )
{
return F_67 ( & V_191 ) ;
}
static void T_4 F_68 ( void )
{
F_69 ( & V_191 ) ;
}
