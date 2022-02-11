static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , const T_1 * V_4 , int V_5 )
{
#define F_2 32
#define F_3 (MAX_WR_LEN + 1)
int V_6 ;
T_1 V_7 [ F_3 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = 1 + V_5 ,
. V_7 = V_7 ,
}
} ;
if ( F_4 ( V_5 > F_2 ) )
return - V_14 ;
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
F_5 ( & V_2 -> V_15 ) ;
V_6 = F_6 ( V_2 -> V_16 , V_9 , 1 ) ;
F_7 ( & V_2 -> V_15 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_8 ( & V_2 -> V_16 -> V_17 ,
L_1 ,
V_18 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
}
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , int V_5 )
{
#define F_10 3
#define F_11 (MAX_RD_LEN)
int V_6 ;
T_1 V_7 [ F_11 ] ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = V_20 ,
. V_5 = V_5 ,
. V_7 = V_7 ,
}
} ;
if ( F_4 ( V_5 > F_10 ) )
return - V_14 ;
F_5 ( & V_2 -> V_15 ) ;
V_6 = F_6 ( V_2 -> V_16 , V_9 , 2 ) ;
F_7 ( & V_2 -> V_15 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , V_7 , V_5 ) ;
V_6 = 0 ;
} else {
F_8 ( & V_2 -> V_16 -> V_17 ,
L_2 ,
V_18 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
}
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_9 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_21 )
{
int V_6 ;
T_1 V_22 ;
if ( V_21 != 0xff ) {
V_6 = F_9 ( V_2 , V_3 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_21 ;
V_22 &= ~ V_21 ;
V_4 |= V_22 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , T_1 V_21 )
{
int V_6 , V_23 ;
T_1 V_22 ;
V_6 = F_9 ( V_2 , V_3 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_22 &= V_21 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
if ( ( V_21 >> V_23 ) & 0x01 )
break;
}
* V_4 = V_22 >> V_23 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_24 * V_25 , int V_26 )
{
int V_6 , V_23 , V_27 ;
T_1 V_7 [ 83 ] ;
F_17 ( & V_2 -> V_16 -> V_17 , L_3 , V_28 , V_26 ) ;
if ( V_26 > 83 ) {
V_6 = - V_14 ;
goto V_29;
}
for ( V_23 = 0 , V_27 = 0 ; V_23 < V_26 ; V_23 ++ , V_27 ++ ) {
V_7 [ V_27 ] = V_25 [ V_23 ] . V_4 ;
if ( V_23 == V_26 - 1 || V_25 [ V_23 ] . V_3 != V_25 [ V_23 + 1 ] . V_3 - 1 ||
! ( ( V_27 + 1 ) % ( V_2 -> V_11 -> V_30 - 1 ) ) ) {
V_6 = F_1 ( V_2 , V_25 [ V_23 ] . V_3 - V_27 , V_7 , V_27 + 1 ) ;
if ( V_6 )
goto V_29;
V_27 = - 1 ;
}
}
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_31 * V_32 , T_2 * V_33 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_32 -> V_37 ;
int V_6 ;
T_1 V_22 ;
* V_33 = 0 ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
switch ( V_36 -> V_40 ) {
case V_41 :
V_6 = F_15 ( V_2 , 0xd1 , & V_22 , 0x07 ) ;
if ( V_6 )
goto V_29;
if ( V_22 == 0x07 )
* V_33 = V_42 | V_43 |
V_44 | V_45 |
V_46 ;
break;
case V_47 :
V_6 = F_15 ( V_2 , 0x0d , & V_22 , 0x8f ) ;
if ( V_6 )
goto V_29;
if ( V_22 == 0x8f )
* V_33 = V_42 | V_43 |
V_44 | V_45 |
V_46 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_5 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_2 -> V_48 = * V_33 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_6 ,
V_28 , V_22 , * V_33 ) ;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_32 -> V_37 ;
int V_6 , V_5 ;
const struct V_24 * V_49 ;
T_1 V_22 , V_50 , V_51 ;
T_1 V_7 [ 2 ] ;
T_3 V_52 , V_53 ;
T_4 V_54 , V_55 ;
T_5 V_56 ;
F_17 ( & V_2 -> V_16 -> V_17 ,
L_7 ,
V_28 , V_36 -> V_40 ,
V_36 -> V_57 , V_36 -> V_58 , V_36 -> V_59 ,
V_36 -> V_60 , V_36 -> V_61 , V_36 -> V_62 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
if ( V_32 -> V_63 . V_64 . V_65 ) {
V_6 = V_32 -> V_63 . V_64 . V_65 ( V_32 ) ;
if ( V_6 )
goto V_29;
}
if ( V_32 -> V_63 . V_64 . V_66 ) {
V_6 = V_32 -> V_63 . V_64 . V_66 ( V_32 , & V_54 ) ;
if ( V_6 )
goto V_29;
} else {
V_54 = V_36 -> V_58 ;
}
V_6 = F_12 ( V_2 , 0x07 , 0x80 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x07 , 0x00 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xb2 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_29;
switch ( V_36 -> V_40 ) {
case V_41 :
V_5 = F_20 ( V_67 ) ;
V_49 = V_67 ;
V_55 = 96000 ;
break;
case V_47 :
V_5 = F_20 ( V_68 ) ;
V_49 = V_68 ;
switch ( V_2 -> V_11 -> V_69 ) {
case V_70 :
case V_71 :
if ( V_36 -> V_59 < 18000000 )
V_55 = 96000 ;
else
V_55 = 144000 ;
break;
case V_72 :
case V_73 :
if ( V_36 -> V_59 < 18000000 )
V_55 = 96000 ;
else if ( V_36 -> V_59 < 28000000 )
V_55 = 144000 ;
else
V_55 = 192000 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_8 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_5 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
if ( V_36 -> V_40 != V_2 -> V_40 ) {
V_6 = F_16 ( V_2 , V_49 , V_5 ) ;
if ( V_6 )
goto V_29;
}
V_50 = 0 ;
switch ( V_2 -> V_11 -> V_69 ) {
case V_70 :
V_50 = 0x00 ;
V_22 = 0x06 ;
break;
case V_71 :
V_50 = 0x20 ;
V_22 = 0x06 ;
break;
case V_72 :
V_22 = 0x02 ;
break;
case V_73 :
V_22 = 0x03 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_8 , V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
if ( V_2 -> V_11 -> V_74 )
V_22 |= 0x40 ;
V_6 = F_12 ( V_2 , 0xfd , V_22 ) ;
if ( V_6 )
goto V_29;
switch ( V_2 -> V_11 -> V_69 ) {
case V_70 :
case V_71 :
V_6 = F_14 ( V_2 , 0x29 , V_50 , 0x20 ) ;
if ( V_6 )
goto V_29;
}
if ( V_2 -> V_11 -> V_75 ) {
V_53 = F_21 ( V_55 , V_2 -> V_11 -> V_75 ) ;
V_50 = V_53 / 2 ;
V_51 = F_21 ( V_53 , 2 ) ;
} else {
V_53 = 0 ;
V_50 = 0 ;
V_51 = 0 ;
}
F_17 ( & V_2 -> V_16 -> V_17 ,
L_9 ,
V_28 , V_55 , V_2 -> V_11 -> V_75 , V_53 ) ;
V_50 -- ;
V_51 -- ;
V_50 &= 0x3f ;
V_51 &= 0x3f ;
V_6 = F_13 ( V_2 , 0xfe , & V_22 ) ;
if ( V_6 )
goto V_29;
V_22 = ( ( V_22 & 0xf0 ) << 0 ) | V_50 >> 2 ;
V_6 = F_12 ( V_2 , 0xfe , V_22 ) ;
if ( V_6 )
goto V_29;
V_22 = ( ( V_50 & 0x03 ) << 6 ) | V_51 >> 0 ;
V_6 = F_12 ( V_2 , 0xea , V_22 ) ;
if ( V_6 )
goto V_29;
switch ( V_55 ) {
case 96000 :
V_50 = 0x02 ;
V_51 = 0x01 ;
break;
case 144000 :
V_50 = 0x00 ;
V_51 = 0x01 ;
break;
case 192000 :
V_50 = 0x03 ;
V_51 = 0x00 ;
break;
}
V_6 = F_14 ( V_2 , 0x22 , V_50 << 6 , 0xc0 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x24 , V_51 << 6 , 0xc0 ) ;
if ( V_6 )
goto V_29;
if ( V_36 -> V_59 <= 3000000 )
V_22 = 0x20 ;
else if ( V_36 -> V_59 <= 10000000 )
V_22 = 0x10 ;
else
V_22 = 0x06 ;
V_6 = F_12 ( V_2 , 0xc3 , 0x08 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xc8 , V_22 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xc4 , 0x08 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xc7 , 0x00 ) ;
if ( V_6 )
goto V_29;
V_52 = F_22 ( ( V_36 -> V_59 / 1000 ) << 15 , V_76 / 2 ) ;
V_7 [ 0 ] = ( V_52 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_52 >> 8 ) & 0xff ;
V_6 = F_1 ( V_2 , 0x61 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x4d , V_2 -> V_11 -> V_77 << 1 , 0x02 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x30 , V_2 -> V_11 -> V_78 << 4 , 0x10 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x33 , V_2 -> V_11 -> V_79 ) ;
if ( V_6 )
goto V_29;
F_17 ( & V_2 -> V_16 -> V_17 , L_10 , V_28 ,
( V_54 - V_36 -> V_58 ) ) ;
V_56 = 0x10000 * ( V_54 - V_36 -> V_58 ) ;
V_56 = F_22 ( V_56 , V_76 ) ;
if ( V_56 < 0 )
V_56 += 0x10000 ;
V_7 [ 0 ] = ( V_56 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_56 >> 8 ) & 0xff ;
V_6 = F_1 ( V_2 , 0x5e , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x00 , 0x00 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xb2 , 0x00 ) ;
if ( V_6 )
goto V_29;
V_2 -> V_40 = V_36 -> V_40 ;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_23 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 , V_5 , V_80 ;
const struct V_81 * V_82 = NULL ;
T_1 * V_83 = V_84 ;
T_1 V_22 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_11 , V_28 ) ;
V_2 -> V_38 = false ;
V_6 = F_14 ( V_2 , 0x08 , 0x01 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x04 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x23 , 0x00 , 0x10 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x07 , 0x60 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x07 , 0x00 ) ;
if ( V_6 )
goto V_29;
V_6 = F_13 ( V_2 , 0xb9 , & V_22 ) ;
if ( V_6 )
goto V_29;
F_17 ( & V_2 -> V_16 -> V_17 , L_12 , V_28 , V_22 ) ;
if ( V_22 )
goto V_85;
F_24 ( & V_2 -> V_16 -> V_17 , L_13 ,
V_18 , V_86 . V_87 . V_88 ) ;
V_6 = F_25 ( & V_82 , V_83 , V_2 -> V_16 -> V_17 . V_89 ) ;
if ( V_6 ) {
F_26 ( & V_2 -> V_16 -> V_17 , L_14 ,
V_18 , V_83 ) ;
goto V_29;
}
F_24 ( & V_2 -> V_16 -> V_17 , L_15 ,
V_18 , V_83 ) ;
V_6 = F_12 ( V_2 , 0xb2 , 0x01 ) ;
if ( V_6 )
goto V_29;
for ( V_80 = V_82 -> V_90 ; V_80 > 0 ;
V_80 -= ( V_2 -> V_11 -> V_30 - 1 ) ) {
V_5 = V_80 ;
if ( V_5 > ( V_2 -> V_11 -> V_30 - 1 ) )
V_5 = ( V_2 -> V_11 -> V_30 - 1 ) ;
V_6 = F_1 ( V_2 , 0xb0 ,
& V_82 -> V_91 [ V_82 -> V_90 - V_80 ] , V_5 ) ;
if ( V_6 ) {
F_26 ( & V_2 -> V_16 -> V_17 ,
L_16 ,
V_18 , V_6 ) ;
goto V_29;
}
}
V_6 = F_12 ( V_2 , 0xb2 , 0x00 ) ;
if ( V_6 )
goto V_29;
F_27 ( V_82 ) ;
V_82 = NULL ;
V_6 = F_13 ( V_2 , 0xb9 , & V_22 ) ;
if ( V_6 )
goto V_29;
if ( ! V_22 ) {
F_24 ( & V_2 -> V_16 -> V_17 , L_17 ,
V_18 ) ;
V_6 = - V_92 ;
goto V_29;
}
F_24 ( & V_2 -> V_16 -> V_17 , L_18 ,
V_18 , V_86 . V_87 . V_88 ) ;
F_24 ( & V_2 -> V_16 -> V_17 , L_19 ,
V_18 , ( V_22 >> 4 ) & 0xf , ( V_22 >> 0 & 0xf ) ) ;
V_85:
V_2 -> V_38 = true ;
return 0 ;
V_29:
if ( V_82 )
F_27 ( V_82 ) ;
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_28 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_11 , V_28 ) ;
V_2 -> V_40 = V_93 ;
V_6 = F_14 ( V_2 , 0x27 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x08 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x04 , 0x01 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x23 , 0x10 , 0x10 ) ;
if ( V_6 )
goto V_29;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_29 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_32 -> V_37 ;
int V_6 ;
T_1 V_7 [ 3 ] ;
F_17 ( & V_2 -> V_16 -> V_17 , L_11 , V_28 ) ;
if ( ! V_2 -> V_38 || ! ( V_2 -> V_48 & V_46 ) ) {
V_6 = - V_39 ;
goto V_29;
}
switch ( V_36 -> V_40 ) {
case V_41 :
V_6 = F_13 ( V_2 , 0xe0 , & V_7 [ 0 ] ) ;
if ( V_6 )
goto V_29;
V_6 = F_13 ( V_2 , 0xe6 , & V_7 [ 1 ] ) ;
if ( V_6 )
goto V_29;
switch ( ( V_7 [ 0 ] >> 2 ) & 0x01 ) {
case 0 :
V_36 -> V_60 = V_94 ;
break;
case 1 :
V_36 -> V_60 = V_95 ;
break;
}
switch ( ( V_7 [ 1 ] >> 5 ) & 0x07 ) {
case 0 :
V_36 -> V_96 = V_97 ;
break;
case 1 :
V_36 -> V_96 = V_98 ;
break;
case 2 :
V_36 -> V_96 = V_99 ;
break;
case 3 :
V_36 -> V_96 = V_100 ;
break;
case 4 :
V_36 -> V_96 = V_101 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_20 ,
V_28 ) ;
}
V_36 -> V_57 = V_102 ;
break;
case V_47 :
V_6 = F_13 ( V_2 , 0x7e , & V_7 [ 0 ] ) ;
if ( V_6 )
goto V_29;
V_6 = F_13 ( V_2 , 0x89 , & V_7 [ 1 ] ) ;
if ( V_6 )
goto V_29;
V_6 = F_13 ( V_2 , 0xf2 , & V_7 [ 2 ] ) ;
if ( V_6 )
goto V_29;
switch ( ( V_7 [ 0 ] >> 0 ) & 0x0f ) {
case 2 :
V_36 -> V_96 = V_103 ;
break;
case 3 :
V_36 -> V_96 = V_101 ;
break;
case 4 :
V_36 -> V_96 = V_104 ;
break;
case 5 :
V_36 -> V_96 = V_100 ;
break;
case 6 :
V_36 -> V_96 = V_99 ;
break;
case 7 :
V_36 -> V_96 = V_105 ;
break;
case 8 :
V_36 -> V_96 = V_98 ;
break;
case 9 :
V_36 -> V_96 = V_106 ;
break;
case 10 :
V_36 -> V_96 = V_107 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_20 ,
V_28 ) ;
}
switch ( ( V_7 [ 0 ] >> 5 ) & 0x01 ) {
case 0 :
V_36 -> V_61 = V_108 ;
break;
case 1 :
V_36 -> V_61 = V_109 ;
break;
}
switch ( ( V_7 [ 0 ] >> 6 ) & 0x07 ) {
case 0 :
V_36 -> V_57 = V_102 ;
break;
case 1 :
V_36 -> V_57 = V_110 ;
break;
case 2 :
V_36 -> V_57 = V_111 ;
break;
case 3 :
V_36 -> V_57 = V_112 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_21 ,
V_28 ) ;
}
switch ( ( V_7 [ 1 ] >> 7 ) & 0x01 ) {
case 0 :
V_36 -> V_60 = V_94 ;
break;
case 1 :
V_36 -> V_60 = V_95 ;
break;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 0x03 ) {
case 0 :
V_36 -> V_62 = V_113 ;
break;
case 1 :
V_36 -> V_62 = V_114 ;
break;
case 2 :
V_36 -> V_62 = V_115 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_22 ,
V_28 ) ;
}
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_5 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_6 = F_9 ( V_2 , 0x6d , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_36 -> V_59 = 1ull * ( ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ) *
V_76 * 1000 / 0x10000 ;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_30 ( struct V_31 * V_32 , T_3 * V_116 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_32 -> V_37 ;
int V_6 , V_23 , V_117 ;
T_1 V_7 [ 3 ] ;
T_3 V_118 , signal ;
T_4 V_119 , V_120 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_11 , V_28 ) ;
#define F_31 3
switch ( V_36 -> V_40 ) {
case V_41 :
V_117 = 0 ;
for ( V_23 = 0 ; V_23 < F_31 ; V_23 ++ ) {
V_6 = F_13 ( V_2 , 0xff , & V_7 [ 0 ] ) ;
if ( V_6 )
goto V_29;
V_117 += V_7 [ 0 ] ;
}
V_117 = F_22 ( V_117 , 8 * F_31 ) ;
if ( V_117 )
* V_116 = F_32 ( ( V_121 ) 100 * F_33 ( V_117 ) , F_33 ( 10 ) ) ;
else
* V_116 = 0 ;
break;
case V_47 :
V_119 = 0 ;
V_120 = 0 ;
for ( V_23 = 0 ; V_23 < F_31 ; V_23 ++ ) {
V_6 = F_9 ( V_2 , 0x8c , V_7 , 3 ) ;
if ( V_6 )
goto V_29;
V_118 = V_7 [ 1 ] << 6 ;
V_118 |= V_7 [ 0 ] & 0x3f ;
V_118 >>= 2 ;
signal = V_7 [ 2 ] * V_7 [ 2 ] ;
signal >>= 1 ;
V_119 += V_118 ;
V_120 += signal ;
}
V_118 = V_119 / F_31 ;
signal = V_120 / F_31 ;
if ( signal > V_118 ) {
V_117 = signal / V_118 ;
* V_116 = F_32 ( ( V_121 ) 100 * F_34 ( V_117 ) , ( 1 << 24 ) ) ;
} else {
* V_116 = 0 ;
}
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_5 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_35 ( struct V_31 * V_32 , T_4 * V_122 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_32 -> V_37 ;
int V_6 ;
unsigned int V_123 ;
T_1 V_7 [ 3 ] , V_22 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_11 , V_28 ) ;
switch ( V_36 -> V_40 ) {
case V_41 :
V_6 = F_12 ( V_2 , 0xf9 , 0x04 ) ;
if ( V_6 )
goto V_29;
V_6 = F_13 ( V_2 , 0xf8 , & V_22 ) ;
if ( V_6 )
goto V_29;
if ( ! ( V_22 & 0x10 ) ) {
V_22 |= 0x10 ;
V_6 = F_9 ( V_2 , 0xf6 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_2 -> V_122 = ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ;
V_6 = F_12 ( V_2 , 0xf8 , V_22 ) ;
if ( V_6 )
goto V_29;
}
break;
case V_47 :
V_6 = F_9 ( V_2 , 0xd5 , V_7 , 3 ) ;
if ( V_6 )
goto V_29;
V_123 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ;
if ( V_123 > 3000 ) {
V_6 = F_9 ( V_2 , 0xf7 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_2 -> V_122 = ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ;
V_6 = F_12 ( V_2 , 0xd1 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xf9 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xf9 , 0x00 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xd1 , 0x00 ) ;
if ( V_6 )
goto V_29;
}
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_5 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
* V_122 = V_2 -> V_122 ;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_36 ( struct V_31 * V_32 ,
T_6 V_124 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 ;
T_1 V_22 , V_125 , V_126 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_23 , V_28 ,
V_124 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
switch ( V_124 ) {
case V_127 :
V_125 = 0 ;
V_126 = 0x47 ;
break;
case V_128 :
V_125 = 1 ;
V_126 = 0x00 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_24 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_22 = V_125 << 7 | V_2 -> V_11 -> V_129 << 5 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0xe0 ) ;
if ( V_6 )
goto V_29;
V_22 = 1 << 2 ;
V_6 = F_14 ( V_2 , 0xa1 , V_22 , V_126 ) ;
if ( V_6 )
goto V_29;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_37 ( struct V_31 * V_32 ,
T_7 V_130 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 ;
T_1 V_22 ;
bool V_131 , V_132 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_25 , V_28 ,
V_130 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
switch ( V_130 ) {
case V_133 :
V_131 = true ;
V_132 = false ;
break;
case V_134 :
V_131 = false ;
V_132 = false ;
break;
case V_135 :
V_131 = false ;
V_132 = true ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_26 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_131 ^= V_2 -> V_11 -> V_136 ;
V_132 ^= V_2 -> V_11 -> V_137 ;
V_22 = V_132 << 1 | V_131 << 0 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0x03 ) ;
if ( V_6 )
goto V_29;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_38 ( struct V_31 * V_32 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 , V_23 ;
T_1 V_22 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_27 , V_28 ,
V_139 -> V_140 , V_139 -> V_9 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
if ( V_139 -> V_140 < 3 || V_139 -> V_140 > 6 ) {
V_6 = - V_14 ;
goto V_29;
}
V_22 = V_2 -> V_11 -> V_129 << 5 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0xe0 ) ;
if ( V_6 )
goto V_29;
V_6 = F_1 ( V_2 , 0xa3 , V_139 -> V_9 ,
V_139 -> V_140 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xa1 ,
( V_139 -> V_140 - 1 ) << 3 | 0x07 ) ;
if ( V_6 )
goto V_29;
F_39 ( 40000 , 60000 ) ;
for ( V_23 = 20 , V_22 = 1 ; V_23 && V_22 ; V_23 -- ) {
F_39 ( 5000 , 10000 ) ;
V_6 = F_15 ( V_2 , 0xa1 , & V_22 , 0x40 ) ;
if ( V_6 )
goto V_29;
}
F_17 ( & V_2 -> V_16 -> V_17 , L_28 , V_28 , V_23 ) ;
if ( V_23 == 0 ) {
F_17 ( & V_2 -> V_16 -> V_17 , L_29 , V_28 ) ;
V_6 = F_14 ( V_2 , 0xa1 , 0x40 , 0xc0 ) ;
if ( V_6 )
goto V_29;
}
V_6 = F_14 ( V_2 , 0xa2 , 0x80 , 0xc0 ) ;
if ( V_6 )
goto V_29;
if ( V_23 == 0 ) {
V_6 = - V_141 ;
goto V_29;
}
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_40 ( struct V_31 * V_32 ,
T_8 V_142 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 , V_23 ;
T_1 V_22 , V_143 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_30 , V_28 ,
V_142 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
V_22 = V_2 -> V_11 -> V_129 << 5 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0xe0 ) ;
if ( V_6 )
goto V_29;
switch ( V_142 ) {
case V_144 :
V_143 = 0x02 ;
break;
case V_145 :
V_143 = 0x01 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_31 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_6 = F_12 ( V_2 , 0xa1 , V_143 ) ;
if ( V_6 )
goto V_29;
F_39 ( 11000 , 20000 ) ;
for ( V_23 = 5 , V_22 = 1 ; V_23 && V_22 ; V_23 -- ) {
F_39 ( 800 , 2000 ) ;
V_6 = F_15 ( V_2 , 0xa1 , & V_22 , 0x40 ) ;
if ( V_6 )
goto V_29;
}
F_17 ( & V_2 -> V_16 -> V_17 , L_28 , V_28 , V_23 ) ;
V_6 = F_14 ( V_2 , 0xa2 , 0x80 , 0xc0 ) ;
if ( V_6 )
goto V_29;
if ( V_23 == 0 ) {
F_17 ( & V_2 -> V_16 -> V_17 , L_29 , V_28 ) ;
V_6 = - V_141 ;
goto V_29;
}
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_41 ( struct V_31 * V_32 ,
struct V_146 * V_147 )
{
V_147 -> V_148 = 3000 ;
return 0 ;
}
static void F_42 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
F_43 ( V_2 -> V_149 ) ;
F_44 ( V_2 ) ;
}
static int F_45 ( struct V_149 * V_150 , void * V_151 , T_4 V_152 )
{
struct V_1 * V_2 = V_151 ;
int V_6 ;
struct V_8 V_153 [ 1 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = 2 ,
. V_7 = L_32 ,
}
} ;
F_5 ( & V_2 -> V_15 ) ;
V_6 = F_46 ( V_2 -> V_16 , V_153 , 1 ) ;
if ( V_6 != 1 ) {
F_8 ( & V_2 -> V_16 -> V_17 , L_33 ,
V_18 , V_6 ) ;
if ( V_6 >= 0 )
V_6 = - V_19 ;
return V_6 ;
}
return 0 ;
}
static int F_47 ( struct V_149 * V_150 , void * V_151 ,
T_4 V_152 )
{
struct V_1 * V_2 = V_151 ;
F_7 ( & V_2 -> V_15 ) ;
return 0 ;
}
struct V_31 * F_48 ( const struct V_154 * V_11 ,
struct V_149 * V_16 , struct V_149 * * V_155 )
{
int V_6 ;
struct V_1 * V_2 ;
T_1 V_156 , V_22 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_157 ) ;
if ( ! V_2 ) {
V_6 = - V_158 ;
F_26 ( & V_16 -> V_17 , L_34 , V_18 ) ;
goto V_29;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_16 = V_16 ;
F_50 ( & V_2 -> V_15 ) ;
V_6 = F_13 ( V_2 , 0x01 , & V_156 ) ;
if ( V_6 )
goto V_29;
F_17 ( & V_2 -> V_16 -> V_17 , L_35 , V_28 , V_156 ) ;
switch ( V_156 ) {
case 0xd0 :
break;
default:
goto V_29;
}
switch ( V_2 -> V_11 -> V_159 ) {
case V_160 :
V_22 = 0x80 ;
break;
case V_161 :
V_22 = 0x00 ;
break;
case V_162 :
V_22 = 0x10 ;
break;
default:
goto V_29;
}
V_6 = F_12 ( V_2 , 0x29 , V_22 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x08 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x04 , 0x01 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x23 , 0x10 , 0x10 ) ;
if ( V_6 )
goto V_29;
V_2 -> V_149 = F_51 ( V_16 , & V_16 -> V_17 , V_2 , 0 , 0 , 0 ,
F_45 , F_47 ) ;
if ( V_2 -> V_149 == NULL )
goto V_29;
* V_155 = V_2 -> V_149 ;
memcpy ( & V_2 -> V_32 . V_63 , & V_86 , sizeof( struct V_163 ) ) ;
V_2 -> V_32 . V_34 = V_2 ;
return & V_2 -> V_32 ;
V_29:
F_17 ( & V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
F_44 ( V_2 ) ;
return NULL ;
}
