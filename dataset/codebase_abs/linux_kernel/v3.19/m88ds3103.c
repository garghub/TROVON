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
if ( V_26 > 86 ) {
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
T_1 V_22 , V_50 = 0 , V_51 = 0 ;
T_1 V_7 [ 3 ] ;
T_3 V_52 , V_53 = 0 ;
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
V_6 = F_12 ( V_2 , 0x07 , 0x80 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x07 , 0x00 ) ;
if ( V_6 )
goto V_29;
if ( V_2 -> V_63 == V_64 ) {
V_6 = F_12 ( V_2 , 0x06 , 0xe0 ) ;
if ( V_6 )
goto V_29;
}
if ( V_32 -> V_65 . V_66 . V_67 ) {
V_6 = V_32 -> V_65 . V_66 . V_67 ( V_32 ) ;
if ( V_6 )
goto V_29;
}
if ( V_32 -> V_65 . V_66 . V_68 ) {
V_6 = V_32 -> V_65 . V_66 . V_68 ( V_32 , & V_54 ) ;
if ( V_6 )
goto V_29;
} else {
V_54 = V_36 -> V_58 ;
}
if ( V_2 -> V_63 == V_64 ) {
if ( V_36 -> V_59 > 45010000 )
V_2 -> V_69 = 110250 ;
else
V_2 -> V_69 = 96000 ;
if ( V_36 -> V_40 == V_41 )
V_55 = 96000 ;
else
V_55 = 144000 ;
V_6 = F_12 ( V_2 , 0x06 , 0x00 ) ;
if ( V_6 )
goto V_29;
F_20 ( 10000 , 20000 ) ;
} else {
V_2 -> V_69 = 96000 ;
switch ( V_2 -> V_11 -> V_70 ) {
case V_71 :
case V_72 :
V_55 = V_2 -> V_11 -> V_73 ;
break;
case V_74 :
case V_75 :
if ( V_36 -> V_40 == V_41 )
V_55 = 96000 ;
else {
if ( V_36 -> V_59 < 18000000 )
V_55 = 96000 ;
else if ( V_36 -> V_59 < 28000000 )
V_55 = 144000 ;
else
V_55 = 192000 ;
}
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_8 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
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
}
V_6 = F_12 ( V_2 , 0xb2 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_29;
switch ( V_36 -> V_40 ) {
case V_41 :
if ( V_2 -> V_63 == V_64 ) {
V_5 = F_21 ( V_76 ) ;
V_49 = V_76 ;
} else {
V_5 = F_21 ( V_77 ) ;
V_49 = V_77 ;
}
break;
case V_47 :
if ( V_2 -> V_63 == V_64 ) {
V_5 = F_21 ( V_78 ) ;
V_49 = V_78 ;
} else {
V_5 = F_21 ( V_79 ) ;
V_49 = V_79 ;
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
if ( V_2 -> V_63 == V_64 ) {
if ( ( V_36 -> V_40 == V_47 )
&& ( ( V_36 -> V_59 / 1000 ) <= 5000 ) ) {
V_6 = F_12 ( V_2 , 0xc0 , 0x04 ) ;
if ( V_6 )
goto V_29;
V_7 [ 0 ] = 0x09 ;
V_7 [ 1 ] = 0x22 ;
V_7 [ 2 ] = 0x88 ;
V_6 = F_1 ( V_2 , 0x8a , V_7 , 3 ) ;
if ( V_6 )
goto V_29;
}
V_6 = F_14 ( V_2 , 0x9d , 0x08 , 0x08 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xf1 , 0x01 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x30 , 0x80 , 0x80 ) ;
if ( V_6 )
goto V_29;
}
switch ( V_2 -> V_11 -> V_70 ) {
case V_71 :
V_50 = 0x00 ;
V_22 = 0x06 ;
break;
case V_72 :
V_50 = 0x20 ;
V_22 = 0x06 ;
break;
case V_74 :
V_22 = 0x02 ;
break;
case V_75 :
V_22 = 0x03 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_8 , V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
if ( V_2 -> V_11 -> V_80 )
V_22 |= 0x40 ;
V_6 = F_12 ( V_2 , 0xfd , V_22 ) ;
if ( V_6 )
goto V_29;
switch ( V_2 -> V_11 -> V_70 ) {
case V_71 :
case V_72 :
V_6 = F_14 ( V_2 , 0x29 , V_50 , 0x20 ) ;
if ( V_6 )
goto V_29;
V_50 = 0 ;
V_51 = 0 ;
break;
default:
if ( V_2 -> V_11 -> V_73 ) {
V_53 = F_22 ( V_55 , V_2 -> V_11 -> V_73 ) ;
V_50 = V_53 / 2 ;
V_51 = F_22 ( V_53 , 2 ) ;
}
}
F_17 ( & V_2 -> V_16 -> V_17 ,
L_9 ,
V_28 , V_55 , V_2 -> V_11 -> V_73 , V_53 ) ;
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
V_52 = F_23 ( ( V_36 -> V_59 / 1000 ) << 15 , V_2 -> V_69 / 2 ) ;
V_7 [ 0 ] = ( V_52 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_52 >> 8 ) & 0xff ;
V_6 = F_1 ( V_2 , 0x61 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x4d , V_2 -> V_11 -> V_81 << 1 , 0x02 ) ;
if ( V_6 )
goto V_29;
V_6 = F_14 ( V_2 , 0x30 , V_2 -> V_11 -> V_82 << 4 , 0x10 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x33 , V_2 -> V_11 -> V_83 ) ;
if ( V_6 )
goto V_29;
F_17 ( & V_2 -> V_16 -> V_17 , L_10 , V_28 ,
( V_54 - V_36 -> V_58 ) ) ;
V_56 = 0x10000 * ( V_54 - V_36 -> V_58 ) ;
V_56 = F_23 ( V_56 , V_2 -> V_69 ) ;
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
static int F_24 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 , V_5 , V_84 ;
const struct V_85 * V_86 = NULL ;
T_1 * V_87 ;
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
V_6 = F_13 ( V_2 , 0xb9 , & V_22 ) ;
if ( V_6 )
goto V_29;
F_17 ( & V_2 -> V_16 -> V_17 , L_12 , V_28 , V_22 ) ;
if ( V_22 )
goto V_88;
V_6 = F_12 ( V_2 , 0x07 , 0xe0 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0x07 , 0x00 ) ;
if ( V_6 )
goto V_29;
F_25 ( & V_2 -> V_16 -> V_17 , L_13 ,
V_18 , V_89 . V_90 . V_91 ) ;
if ( V_2 -> V_63 == V_64 )
V_87 = V_92 ;
else
V_87 = V_93 ;
V_6 = F_26 ( & V_86 , V_87 , V_2 -> V_16 -> V_17 . V_94 ) ;
if ( V_6 ) {
F_27 ( & V_2 -> V_16 -> V_17 , L_14 ,
V_18 , V_87 ) ;
goto V_29;
}
F_25 ( & V_2 -> V_16 -> V_17 , L_15 ,
V_18 , V_87 ) ;
V_6 = F_12 ( V_2 , 0xb2 , 0x01 ) ;
if ( V_6 )
goto V_95;
for ( V_84 = V_86 -> V_96 ; V_84 > 0 ;
V_84 -= ( V_2 -> V_11 -> V_30 - 1 ) ) {
V_5 = V_84 ;
if ( V_5 > ( V_2 -> V_11 -> V_30 - 1 ) )
V_5 = ( V_2 -> V_11 -> V_30 - 1 ) ;
V_6 = F_1 ( V_2 , 0xb0 ,
& V_86 -> V_97 [ V_86 -> V_96 - V_84 ] , V_5 ) ;
if ( V_6 ) {
F_27 ( & V_2 -> V_16 -> V_17 ,
L_16 ,
V_18 , V_6 ) ;
goto V_95;
}
}
V_6 = F_12 ( V_2 , 0xb2 , 0x00 ) ;
if ( V_6 )
goto V_95;
F_28 ( V_86 ) ;
V_86 = NULL ;
V_6 = F_13 ( V_2 , 0xb9 , & V_22 ) ;
if ( V_6 )
goto V_29;
if ( ! V_22 ) {
F_25 ( & V_2 -> V_16 -> V_17 , L_17 ,
V_18 ) ;
V_6 = - V_98 ;
goto V_29;
}
F_25 ( & V_2 -> V_16 -> V_17 , L_18 ,
V_18 , V_89 . V_90 . V_91 ) ;
F_25 ( & V_2 -> V_16 -> V_17 , L_19 ,
V_18 , ( V_22 >> 4 ) & 0xf , ( V_22 >> 0 & 0xf ) ) ;
V_88:
V_2 -> V_38 = true ;
return 0 ;
V_95:
F_28 ( V_86 ) ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_29 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 ;
T_1 V_22 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_11 , V_28 ) ;
V_2 -> V_40 = V_99 ;
if ( V_2 -> V_63 == V_64 )
V_22 = 0x29 ;
else
V_22 = 0x27 ;
V_6 = F_14 ( V_2 , V_22 , 0x00 , 0x01 ) ;
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
static int F_30 ( struct V_31 * V_32 )
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
V_36 -> V_60 = V_100 ;
break;
case 1 :
V_36 -> V_60 = V_101 ;
break;
}
switch ( ( V_7 [ 1 ] >> 5 ) & 0x07 ) {
case 0 :
V_36 -> V_102 = V_103 ;
break;
case 1 :
V_36 -> V_102 = V_104 ;
break;
case 2 :
V_36 -> V_102 = V_105 ;
break;
case 3 :
V_36 -> V_102 = V_106 ;
break;
case 4 :
V_36 -> V_102 = V_107 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_20 ,
V_28 ) ;
}
V_36 -> V_57 = V_108 ;
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
V_36 -> V_102 = V_109 ;
break;
case 3 :
V_36 -> V_102 = V_107 ;
break;
case 4 :
V_36 -> V_102 = V_110 ;
break;
case 5 :
V_36 -> V_102 = V_106 ;
break;
case 6 :
V_36 -> V_102 = V_105 ;
break;
case 7 :
V_36 -> V_102 = V_111 ;
break;
case 8 :
V_36 -> V_102 = V_104 ;
break;
case 9 :
V_36 -> V_102 = V_112 ;
break;
case 10 :
V_36 -> V_102 = V_113 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_20 ,
V_28 ) ;
}
switch ( ( V_7 [ 0 ] >> 5 ) & 0x01 ) {
case 0 :
V_36 -> V_61 = V_114 ;
break;
case 1 :
V_36 -> V_61 = V_115 ;
break;
}
switch ( ( V_7 [ 0 ] >> 6 ) & 0x07 ) {
case 0 :
V_36 -> V_57 = V_108 ;
break;
case 1 :
V_36 -> V_57 = V_116 ;
break;
case 2 :
V_36 -> V_57 = V_117 ;
break;
case 3 :
V_36 -> V_57 = V_118 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_21 ,
V_28 ) ;
}
switch ( ( V_7 [ 1 ] >> 7 ) & 0x01 ) {
case 0 :
V_36 -> V_60 = V_100 ;
break;
case 1 :
V_36 -> V_60 = V_101 ;
break;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 0x03 ) {
case 0 :
V_36 -> V_62 = V_119 ;
break;
case 1 :
V_36 -> V_62 = V_120 ;
break;
case 2 :
V_36 -> V_62 = V_121 ;
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
V_2 -> V_69 * 1000 / 0x10000 ;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_31 ( struct V_31 * V_32 , T_3 * V_122 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_32 -> V_37 ;
int V_6 , V_23 , V_123 ;
T_1 V_7 [ 3 ] ;
T_3 V_124 , signal ;
T_4 V_125 , V_126 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_11 , V_28 ) ;
#define F_32 3
switch ( V_36 -> V_40 ) {
case V_41 :
V_123 = 0 ;
for ( V_23 = 0 ; V_23 < F_32 ; V_23 ++ ) {
V_6 = F_13 ( V_2 , 0xff , & V_7 [ 0 ] ) ;
if ( V_6 )
goto V_29;
V_123 += V_7 [ 0 ] ;
}
V_123 = F_23 ( V_123 , 8 * F_32 ) ;
if ( V_123 )
* V_122 = F_33 ( ( V_127 ) 100 * F_34 ( V_123 ) , F_34 ( 10 ) ) ;
else
* V_122 = 0 ;
break;
case V_47 :
V_125 = 0 ;
V_126 = 0 ;
for ( V_23 = 0 ; V_23 < F_32 ; V_23 ++ ) {
V_6 = F_9 ( V_2 , 0x8c , V_7 , 3 ) ;
if ( V_6 )
goto V_29;
V_124 = V_7 [ 1 ] << 6 ;
V_124 |= V_7 [ 0 ] & 0x3f ;
V_124 >>= 2 ;
signal = V_7 [ 2 ] * V_7 [ 2 ] ;
signal >>= 1 ;
V_125 += V_124 ;
V_126 += signal ;
}
V_124 = V_125 / F_32 ;
signal = V_126 / F_32 ;
if ( signal > V_124 ) {
V_123 = signal / V_124 ;
* V_122 = F_33 ( ( V_127 ) 100 * F_35 ( V_123 ) , ( 1 << 24 ) ) ;
} else {
* V_122 = 0 ;
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
static int F_36 ( struct V_31 * V_32 , T_4 * V_128 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_32 -> V_37 ;
int V_6 ;
unsigned int V_129 ;
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
V_2 -> V_128 = ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ;
V_6 = F_12 ( V_2 , 0xf8 , V_22 ) ;
if ( V_6 )
goto V_29;
}
break;
case V_47 :
V_6 = F_9 ( V_2 , 0xd5 , V_7 , 3 ) ;
if ( V_6 )
goto V_29;
V_129 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ;
if ( V_129 > 3000 ) {
V_6 = F_9 ( V_2 , 0xf7 , V_7 , 2 ) ;
if ( V_6 )
goto V_29;
V_2 -> V_128 = ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ;
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
* V_128 = V_2 -> V_128 ;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_37 ( struct V_31 * V_32 ,
T_6 V_130 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 ;
T_1 V_22 , V_131 , V_132 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_23 , V_28 ,
V_130 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
switch ( V_130 ) {
case V_133 :
V_131 = 0 ;
V_132 = 0x47 ;
break;
case V_134 :
V_131 = 1 ;
V_132 = 0x00 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_24 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_22 = V_131 << 7 | V_2 -> V_11 -> V_135 << 5 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0xe0 ) ;
if ( V_6 )
goto V_29;
V_22 = 1 << 2 ;
V_6 = F_14 ( V_2 , 0xa1 , V_22 , V_132 ) ;
if ( V_6 )
goto V_29;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_38 ( struct V_31 * V_32 ,
T_7 V_136 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 ;
T_1 V_22 ;
bool V_137 , V_138 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_25 , V_28 ,
V_136 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
switch ( V_136 ) {
case V_139 :
V_137 = true ;
V_138 = false ;
break;
case V_140 :
V_137 = false ;
V_138 = false ;
break;
case V_141 :
V_137 = false ;
V_138 = true ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_26 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_137 ^= V_2 -> V_11 -> V_142 ;
V_138 ^= V_2 -> V_11 -> V_143 ;
V_22 = V_138 << 1 | V_137 << 0 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0x03 ) ;
if ( V_6 )
goto V_29;
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_39 ( struct V_31 * V_32 ,
struct V_144 * V_145 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 , V_23 ;
T_1 V_22 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_27 , V_28 ,
V_145 -> V_146 , V_145 -> V_9 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
if ( V_145 -> V_146 < 3 || V_145 -> V_146 > 6 ) {
V_6 = - V_14 ;
goto V_29;
}
V_22 = V_2 -> V_11 -> V_135 << 5 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0xe0 ) ;
if ( V_6 )
goto V_29;
V_6 = F_1 ( V_2 , 0xa3 , V_145 -> V_9 ,
V_145 -> V_146 ) ;
if ( V_6 )
goto V_29;
V_6 = F_12 ( V_2 , 0xa1 ,
( V_145 -> V_146 - 1 ) << 3 | 0x07 ) ;
if ( V_6 )
goto V_29;
F_20 ( 40000 , 60000 ) ;
for ( V_23 = 20 , V_22 = 1 ; V_23 && V_22 ; V_23 -- ) {
F_20 ( 5000 , 10000 ) ;
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
V_6 = - V_147 ;
goto V_29;
}
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_40 ( struct V_31 * V_32 ,
T_8 V_148 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
int V_6 , V_23 ;
T_1 V_22 , V_149 ;
F_17 ( & V_2 -> V_16 -> V_17 , L_30 , V_28 ,
V_148 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = - V_39 ;
goto V_29;
}
V_22 = V_2 -> V_11 -> V_135 << 5 ;
V_6 = F_14 ( V_2 , 0xa2 , V_22 , 0xe0 ) ;
if ( V_6 )
goto V_29;
switch ( V_148 ) {
case V_150 :
V_149 = 0x02 ;
break;
case V_151 :
V_149 = 0x01 ;
break;
default:
F_17 ( & V_2 -> V_16 -> V_17 , L_31 ,
V_28 ) ;
V_6 = - V_14 ;
goto V_29;
}
V_6 = F_12 ( V_2 , 0xa1 , V_149 ) ;
if ( V_6 )
goto V_29;
F_20 ( 11000 , 20000 ) ;
for ( V_23 = 5 , V_22 = 1 ; V_23 && V_22 ; V_23 -- ) {
F_20 ( 800 , 2000 ) ;
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
V_6 = - V_147 ;
goto V_29;
}
return 0 ;
V_29:
F_17 ( & V_2 -> V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_41 ( struct V_31 * V_32 ,
struct V_152 * V_153 )
{
V_153 -> V_154 = 3000 ;
return 0 ;
}
static void F_42 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
F_43 ( V_2 -> V_155 ) ;
F_44 ( V_2 ) ;
}
static int F_45 ( struct V_155 * V_156 , void * V_157 , T_4 V_158 )
{
struct V_1 * V_2 = V_157 ;
int V_6 ;
struct V_8 V_159 [ 1 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = 2 ,
. V_7 = L_32 ,
}
} ;
F_5 ( & V_2 -> V_15 ) ;
V_6 = F_46 ( V_2 -> V_16 , V_159 , 1 ) ;
if ( V_6 != 1 ) {
F_8 ( & V_2 -> V_16 -> V_17 , L_33 ,
V_18 , V_6 ) ;
if ( V_6 >= 0 )
V_6 = - V_19 ;
return V_6 ;
}
return 0 ;
}
static int F_47 ( struct V_155 * V_156 , void * V_157 ,
T_4 V_158 )
{
struct V_1 * V_2 = V_157 ;
F_7 ( & V_2 -> V_15 ) ;
return 0 ;
}
struct V_31 * F_48 ( const struct V_160 * V_11 ,
struct V_155 * V_16 , struct V_155 * * V_161 )
{
int V_6 ;
struct V_1 * V_2 ;
T_1 V_63 , V_22 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_162 ) ;
if ( ! V_2 ) {
V_6 = - V_163 ;
F_27 ( & V_16 -> V_17 , L_34 , V_18 ) ;
goto V_29;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_16 = V_16 ;
F_50 ( & V_2 -> V_15 ) ;
V_6 = F_13 ( V_2 , 0x00 , & V_63 ) ;
if ( V_6 )
goto V_29;
V_63 >>= 1 ;
F_25 ( & V_2 -> V_16 -> V_17 , L_35 , V_28 , V_63 ) ;
switch ( V_63 ) {
case V_64 :
case V_164 :
break;
default:
goto V_29;
}
V_2 -> V_63 = V_63 ;
switch ( V_2 -> V_11 -> V_165 ) {
case V_166 :
V_22 = 0x80 ;
break;
case V_167 :
V_22 = 0x00 ;
break;
case V_168 :
V_22 = 0x10 ;
break;
default:
goto V_29;
}
if ( V_63 == V_64 )
V_22 = 0x00 ;
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
V_2 -> V_155 = F_51 ( V_16 , & V_16 -> V_17 , V_2 , 0 , 0 , 0 ,
F_45 , F_47 ) ;
if ( V_2 -> V_155 == NULL )
goto V_29;
* V_161 = V_2 -> V_155 ;
memcpy ( & V_2 -> V_32 . V_65 , & V_89 , sizeof( struct V_169 ) ) ;
if ( V_2 -> V_63 == V_64 )
strncpy ( V_2 -> V_32 . V_65 . V_90 . V_91 ,
L_36 , sizeof( V_2 -> V_32 . V_65 . V_90 . V_91 ) ) ;
V_2 -> V_32 . V_34 = V_2 ;
return & V_2 -> V_32 ;
V_29:
F_17 ( & V_16 -> V_17 , L_4 , V_28 , V_6 ) ;
F_44 ( V_2 ) ;
return NULL ;
}
