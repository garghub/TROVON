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
T_4 V_54 , V_55 , V_56 ;
T_5 V_57 ;
F_17 ( & V_2 -> V_16 -> V_17 ,
L_7 ,
V_28 , V_36 -> V_40 ,
V_36 -> V_58 , V_36 -> V_59 , V_36 -> V_60 ,
V_36 -> V_61 , V_36 -> V_62 , V_36 -> V_63 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
if ( V_32 -> V_64 . V_65 . V_66 ) {
V_6 = V_32 -> V_64 . V_65 . V_66 ( V_32 ) ;
if ( V_6 )
goto V_29;
}
if ( V_32 -> V_64 . V_65 . V_67 ) {
V_6 = V_32 -> V_64 . V_65 . V_67 ( V_32 , & V_54 ) ;
if ( V_6 )
goto V_29;
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
V_5 = F_20 ( V_68 ) ;
V_49 = V_68 ;
V_55 = 96000 ;
break;
case V_47 :
V_5 = F_20 ( V_69 ) ;
V_49 = V_69 ;
switch ( V_2 -> V_11 -> V_70 ) {
case V_71 :
case V_72 :
if ( V_36 -> V_60 < 18000000 )
V_55 = 96000 ;
else
V_55 = 144000 ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
if ( V_36 -> V_60 < 18000000 )
V_55 = 96000 ;
else if ( V_36 -> V_60 < 28000000 )
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
switch ( V_2 -> V_11 -> V_70 ) {
case V_71 :
V_50 = 0x00 ;
V_56 = 0 ;
V_22 = 0x46 ;
break;
case V_72 :
V_50 = 0x20 ;
V_56 = 0 ;
V_22 = 0x46 ;
break;
case V_73 :
V_56 = 24000 ;
V_22 = 0x42 ;
break;
case V_74 :
V_56 = 12000 ;
V_22 = 0x42 ;
break;
case V_75 :
V_56 = 16000 ;
V_22 = 0x42 ;
break;
case V_76 :
V_56 = 19200 ;
V_22 = 0x42 ;
break;
case V_77 :
V_56 = 6000 ;
V_22 = 0x43 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_8 , V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_6 = F_12 ( V_2 , 0xfd , V_22 ) ;
if ( V_6 )
goto V_29;
switch ( V_2 -> V_11 -> V_70 ) {
case V_71 :
case V_72 :
V_6 = F_14 ( V_2 , 0x29 , V_50 , 0x20 ) ;
if ( V_6 )
goto V_29;
}
if ( V_56 ) {
V_53 = F_21 ( V_55 , V_56 ) ;
V_50 = V_53 / 2 ;
V_51 = F_21 ( V_53 , 2 ) ;
} else {
V_53 = 0 ;
V_50 = 0 ;
V_51 = 0 ;
}
F_17 ( & V_2 -> V_16 -> V_17 ,
L_9 ,
V_28 , V_55 , V_56 , V_53 ) ;
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
case 72000 :
V_50 = 0x00 ;
V_51 = 0x03 ;
break;
case 96000 :
V_50 = 0x02 ;
V_51 = 0x01 ;
break;
case 115200 :
V_50 = 0x01 ;
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
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_10 , V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_6 = F_14 ( V_2 , 0x22 , V_50 << 6 , 0xc0 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x24 , V_51 << 6 , 0xc0 ) ;
if ( V_6 )
goto V_29;
if ( V_36 -> V_60 <= 3000000 )
V_22 = 0x20 ;
else if ( V_36 -> V_60 <= 10000000 )
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
V_52 = F_22 ( ( V_36 -> V_60 / 1000 ) << 15 , V_78 / 2 ) ;
V_7 [ 0 ] = ( V_52 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_52 >> 8 ) & 0xff ;
V_6 = F_1 ( V_2 , 0x61 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x4d , V_2 -> V_11 -> V_79 << 1 , 0x02 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x30 , V_2 -> V_11 -> V_80 << 4 , 0x10 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x33 , V_2 -> V_11 -> V_81 ) ;
if ( V_6 )
goto V_29;
F_17 ( & V_2 -> V_16 -> V_17 , L_11 , V_28 ,
( V_54 - V_36 -> V_59 ) ) ;
V_57 = 0x10000 * ( V_54 - V_36 -> V_59 ) ;
V_57 = F_22 ( V_57 , V_78 ) ;
if ( V_57 < 0 )
V_57 += 0x10000 ;
V_7 [ 0 ] = ( V_57 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_57 >> 8 ) & 0xff ;
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
int V_6 , V_5 , V_82 ;
const struct V_83 * V_84 = NULL ;
T_1 * V_85 = V_86 ;
T_1 V_22 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_12 , V_28 ) ;
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
F_17 ( & V_2 -> V_16 -> V_17 , L_13 , V_28 , V_22 ) ;
if ( V_22 )
goto V_87;
F_24 ( & V_2 -> V_16 -> V_17 , L_14 ,
V_18 , V_88 . V_89 . V_90 ) ;
V_6 = F_25 ( & V_84 , V_85 , V_2 -> V_16 -> V_17 . V_91 ) ;
if ( V_6 ) {
F_26 ( & V_2 -> V_16 -> V_17 , L_15 ,
V_18 , V_85 ) ;
goto V_29;
}
F_24 ( & V_2 -> V_16 -> V_17 , L_16 ,
V_18 , V_85 ) ;
V_6 = F_12 ( V_2 , 0xb2 , 0x01 ) ;
if ( V_6 )
goto V_29;
for ( V_82 = V_84 -> V_92 ; V_82 > 0 ;
V_82 -= ( V_2 -> V_11 -> V_30 - 1 ) ) {
V_5 = V_82 ;
if ( V_5 > ( V_2 -> V_11 -> V_30 - 1 ) )
V_5 = ( V_2 -> V_11 -> V_30 - 1 ) ;
V_6 = F_1 ( V_2 , 0xb0 ,
& V_84 -> V_93 [ V_84 -> V_92 - V_82 ] , V_5 ) ;
if ( V_6 ) {
F_26 ( & V_2 -> V_16 -> V_17 ,
L_17 ,
V_18 , V_6 ) ;
goto V_29;
}
}
V_6 = F_12 ( V_2 , 0xb2 , 0x00 ) ;
if ( V_6 )
goto V_29;
F_27 ( V_84 ) ;
V_84 = NULL ;
V_6 = F_13 ( V_2 , 0xb9 , & V_22 ) ;
if ( V_6 )
goto V_29;
if ( ! V_22 ) {
F_24 ( & V_2 -> V_16 -> V_17 , L_18 ,
V_18 ) ;
V_6 = - V_94 ;
goto V_29;
}
F_24 ( & V_2 -> V_16 -> V_17 , L_19 ,
V_18 , V_88 . V_89 . V_90 ) ;
F_24 ( & V_2 -> V_16 -> V_17 , L_20 ,
V_18 , ( V_22 >> 4 ) & 0xf , ( V_22 >> 0 & 0xf ) ) ;
V_87:
V_2 -> V_38 = true ;
return 0 ;
V_29:
if ( V_84 )
F_27 ( V_84 ) ;
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_28 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_12 , V_28 ) ;
V_2 -> V_40 = V_95 ;
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
F_17 ( & V_2 -> V_16 -> V_17 , L_12 , V_28 ) ;
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
V_36 -> V_61 = V_96 ;
break;
case 1 :
V_36 -> V_61 = V_97 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_21 ,
V_28 ) ;
}
switch ( ( V_7 [ 1 ] >> 5 ) & 0x07 ) {
case 0 :
V_36 -> V_98 = V_99 ;
break;
case 1 :
V_36 -> V_98 = V_100 ;
break;
case 2 :
V_36 -> V_98 = V_101 ;
break;
case 3 :
V_36 -> V_98 = V_102 ;
break;
case 4 :
V_36 -> V_98 = V_103 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_22 ,
V_28 ) ;
}
V_36 -> V_58 = V_104 ;
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
V_36 -> V_98 = V_105 ;
break;
case 3 :
V_36 -> V_98 = V_103 ;
break;
case 4 :
V_36 -> V_98 = V_106 ;
break;
case 5 :
V_36 -> V_98 = V_102 ;
break;
case 6 :
V_36 -> V_98 = V_101 ;
break;
case 7 :
V_36 -> V_98 = V_107 ;
break;
case 8 :
V_36 -> V_98 = V_100 ;
break;
case 9 :
V_36 -> V_98 = V_108 ;
break;
case 10 :
V_36 -> V_98 = V_109 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_22 ,
V_28 ) ;
}
switch ( ( V_7 [ 0 ] >> 5 ) & 0x01 ) {
case 0 :
V_36 -> V_62 = V_110 ;
break;
case 1 :
V_36 -> V_62 = V_111 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_23 ,
V_28 ) ;
}
switch ( ( V_7 [ 0 ] >> 6 ) & 0x07 ) {
case 0 :
V_36 -> V_58 = V_104 ;
break;
case 1 :
V_36 -> V_58 = V_112 ;
break;
case 2 :
V_36 -> V_58 = V_113 ;
break;
case 3 :
V_36 -> V_58 = V_114 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_24 ,
V_28 ) ;
}
switch ( ( V_7 [ 1 ] >> 7 ) & 0x01 ) {
case 0 :
V_36 -> V_61 = V_96 ;
break;
case 1 :
V_36 -> V_61 = V_97 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_21 ,
V_28 ) ;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 0x03 ) {
case 0 :
V_36 -> V_63 = V_115 ;
break;
case 1 :
V_36 -> V_63 = V_116 ;
break;
case 2 :
V_36 -> V_63 = V_117 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_25 ,
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
V_36 -> V_60 = 1ull * ( ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ) *
V_78 * 1000 / 0x10000 ;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_30 ( struct V_31 * V_32 , T_3 * V_118 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_32 -> V_37 ;
int V_6 , V_23 , V_119 ;
T_1 V_7 [ 3 ] ;
T_3 V_120 , signal ;
T_4 V_121 , V_122 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_12 , V_28 ) ;
#define F_31 3
switch ( V_36 -> V_40 ) {
case V_41 :
V_119 = 0 ;
for ( V_23 = 0 ; V_23 < F_31 ; V_23 ++ ) {
V_6 = F_13 ( V_2 , 0xff , & V_7 [ 0 ] ) ;
if ( V_6 )
goto V_29;
V_119 += V_7 [ 0 ] ;
}
V_119 = F_22 ( V_119 , 8 * F_31 ) ;
if ( V_119 )
* V_118 = 100ul * F_32 ( V_119 ) / F_32 ( 10 ) ;
else
* V_118 = 0 ;
break;
case V_47 :
V_121 = 0 ;
V_122 = 0 ;
for ( V_23 = 0 ; V_23 < F_31 ; V_23 ++ ) {
V_6 = F_9 ( V_2 , 0x8c , V_7 , 3 ) ;
if ( V_6 )
goto V_29;
V_120 = V_7 [ 1 ] << 6 ;
V_120 |= V_7 [ 0 ] & 0x3f ;
V_120 >>= 2 ;
signal = V_7 [ 2 ] * V_7 [ 2 ] ;
signal >>= 1 ;
V_121 += V_120 ;
V_122 += signal ;
}
V_120 = V_121 / F_31 ;
signal = V_122 / F_31 ;
if ( signal > V_120 ) {
V_119 = signal / V_120 ;
* V_118 = 100ul * F_33 ( V_119 ) / ( 1 << 24 ) ;
} else {
* V_118 = 0 ;
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
static int F_34 ( struct V_31 * V_32 ,
T_6 V_123 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 ;
T_1 V_22 , V_124 , V_125 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_26 , V_28 ,
V_123 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
switch ( V_123 ) {
case V_126 :
V_124 = 0 ;
V_125 = 0x87 ;
break;
case V_127 :
V_124 = 1 ;
V_125 = 0x00 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_27 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_22 = V_124 << 7 | V_2 -> V_11 -> V_128 << 5 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0xe0 ) ;
if ( V_6 )
goto V_29;
V_22 = 1 << 2 ;
V_6 = F_14 ( V_2 , 0xa1 , V_22 , V_125 ) ;
if ( V_6 )
goto V_29;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_35 ( struct V_31 * V_32 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 , V_23 ;
T_1 V_22 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_28 , V_28 ,
V_130 -> V_131 , V_130 -> V_9 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
if ( V_130 -> V_131 < 3 || V_130 -> V_131 > 6 ) {
V_6 = - V_14 ;
goto V_29;
}
V_22 = V_2 -> V_11 -> V_128 << 5 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0xe0 ) ;
if ( V_6 )
goto V_29;
V_6 = F_1 ( V_2 , 0xa3 , V_130 -> V_9 ,
V_130 -> V_131 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xa1 ,
( V_130 -> V_131 - 1 ) << 3 | 0x07 ) ;
if ( V_6 )
goto V_29;
F_36 ( 40000 , 60000 ) ;
for ( V_23 = 20 , V_22 = 1 ; V_23 && V_22 ; V_23 -- ) {
F_36 ( 5000 , 10000 ) ;
V_6 = F_15 ( V_2 , 0xa1 , & V_22 , 0x40 ) ;
if ( V_6 )
goto V_29;
}
F_17 ( & V_2 -> V_16 -> V_17 , L_29 , V_28 , V_23 ) ;
if ( V_23 == 0 ) {
F_17 ( & V_2 -> V_16 -> V_17 , L_30 , V_28 ) ;
V_6 = F_14 ( V_2 , 0xa1 , 0x40 , 0xc0 ) ;
if ( V_6 )
goto V_29;
}
V_6 = F_14 ( V_2 , 0xa2 , 0x80 , 0xc0 ) ;
if ( V_6 )
goto V_29;
if ( V_23 == 0 ) {
V_6 = - V_132 ;
goto V_29;
}
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_37 ( struct V_31 * V_32 ,
T_7 V_133 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 , V_23 ;
T_1 V_22 , V_134 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_31 , V_28 ,
V_133 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
V_22 = V_2 -> V_11 -> V_128 << 5 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0xe0 ) ;
if ( V_6 )
goto V_29;
switch ( V_133 ) {
case V_135 :
V_134 = 0x02 ;
break;
case V_136 :
V_134 = 0x01 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_32 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_6 = F_12 ( V_2 , 0xa1 , V_134 ) ;
if ( V_6 )
goto V_29;
F_36 ( 11000 , 20000 ) ;
for ( V_23 = 5 , V_22 = 1 ; V_23 && V_22 ; V_23 -- ) {
F_36 ( 800 , 2000 ) ;
V_6 = F_15 ( V_2 , 0xa1 , & V_22 , 0x40 ) ;
if ( V_6 )
goto V_29;
}
F_17 ( & V_2 -> V_16 -> V_17 , L_29 , V_28 , V_23 ) ;
V_6 = F_14 ( V_2 , 0xa2 , 0x80 , 0xc0 ) ;
if ( V_6 )
goto V_29;
if ( V_23 == 0 ) {
F_17 ( & V_2 -> V_16 -> V_17 , L_30 , V_28 ) ;
V_6 = - V_132 ;
goto V_29;
}
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_38 ( struct V_31 * V_32 ,
struct V_137 * V_138 )
{
V_138 -> V_139 = 3000 ;
return 0 ;
}
static void F_39 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
F_40 ( V_2 -> V_140 ) ;
F_41 ( V_2 ) ;
}
static int F_42 ( struct V_140 * V_141 , void * V_142 , T_4 V_143 )
{
struct V_1 * V_2 = V_142 ;
int V_6 ;
struct V_8 V_144 [ 1 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = 2 ,
. V_7 = L_33 ,
}
} ;
F_5 ( & V_2 -> V_15 ) ;
V_6 = F_43 ( V_2 -> V_16 , V_144 , 1 ) ;
if ( V_6 != 1 ) {
F_8 ( & V_2 -> V_16 -> V_17 , L_34 ,
V_18 , V_6 ) ;
if ( V_6 >= 0 )
V_6 = - V_19 ;
return V_6 ;
}
return 0 ;
}
static int F_44 ( struct V_140 * V_141 , void * V_142 ,
T_4 V_143 )
{
struct V_1 * V_2 = V_142 ;
F_7 ( & V_2 -> V_15 ) ;
return 0 ;
}
struct V_31 * F_45 ( const struct V_145 * V_11 ,
struct V_140 * V_16 , struct V_140 * * V_146 )
{
int V_6 ;
struct V_1 * V_2 ;
T_1 V_147 , V_22 ;
V_2 = F_46 ( sizeof( * V_2 ) , V_148 ) ;
if ( ! V_2 ) {
V_6 = - V_149 ;
F_26 ( & V_16 -> V_17 , L_35 , V_18 ) ;
goto V_29;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_16 = V_16 ;
F_47 ( & V_2 -> V_15 ) ;
V_6 = F_13 ( V_2 , 0x01 , & V_147 ) ;
if ( V_6 )
goto V_29;
F_17 ( & V_2 -> V_16 -> V_17 , L_36 , V_28 , V_147 ) ;
switch ( V_147 ) {
case 0xd0 :
break;
default:
goto V_29;
}
switch ( V_2 -> V_11 -> V_150 ) {
case V_151 :
V_22 = 0x80 ;
break;
case V_152 :
V_22 = 0x00 ;
break;
case V_153 :
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
V_2 -> V_140 = F_48 ( V_16 , & V_16 -> V_17 , V_2 , 0 , 0 , 0 ,
F_42 , F_44 ) ;
if ( V_2 -> V_140 == NULL )
goto V_29;
* V_146 = V_2 -> V_140 ;
memcpy ( & V_2 -> V_32 . V_64 , & V_88 , sizeof( struct V_154 ) ) ;
V_2 -> V_32 . V_34 = V_2 ;
return & V_2 -> V_32 ;
V_29:
F_17 ( & V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
F_41 ( V_2 ) ;
return NULL ;
}
