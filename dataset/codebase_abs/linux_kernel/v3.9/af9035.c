static T_1 F_1 ( const T_2 * V_1 , T_3 V_2 )
{
T_3 V_3 ;
T_1 V_4 = 0 ;
for ( V_3 = 1 ; V_3 < V_2 ; V_3 ++ ) {
if ( V_3 % 2 )
V_4 += V_1 [ V_3 ] << 8 ;
else
V_4 += V_1 [ V_3 ] ;
}
V_4 = ~ V_4 ;
return V_4 ;
}
static int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
#define F_3 64
#define F_4 4
#define F_5 3
#define F_6 2
#define F_7 2000
struct V_9 * V_9 = F_8 ( V_6 ) ;
int V_10 , V_11 , V_12 ;
T_2 V_1 [ F_3 ] ;
T_1 V_4 , V_13 ;
if ( V_8 -> V_11 > ( F_3 - F_4 - F_6 ) ||
V_8 -> V_12 > ( F_3 - F_5 - F_6 ) ) {
F_9 ( & V_6 -> V_14 -> V_15 , L_1 ,
V_16 , V_8 -> V_11 , V_8 -> V_12 ) ;
return - V_17 ;
}
V_1 [ 0 ] = F_4 + V_8 -> V_11 + F_6 - 1 ;
V_1 [ 1 ] = V_8 -> V_18 ;
V_1 [ 2 ] = V_8 -> V_19 ;
V_1 [ 3 ] = V_9 -> V_20 ++ ;
memcpy ( & V_1 [ F_4 ] , V_8 -> V_21 , V_8 -> V_11 ) ;
V_11 = F_4 + V_8 -> V_11 + F_6 ;
V_12 = F_5 + V_8 -> V_12 + F_6 ;
V_4 = F_1 ( V_1 , V_1 [ 0 ] - 1 ) ;
V_1 [ V_1 [ 0 ] - 1 ] = ( V_4 >> 8 ) ;
V_1 [ V_1 [ 0 ] - 0 ] = ( V_4 & 0xff ) ;
if ( V_8 -> V_19 == V_22 )
V_12 = 0 ;
V_10 = F_10 ( V_6 , V_1 , V_11 , V_1 , V_12 ) ;
if ( V_10 )
goto V_23;
if ( V_8 -> V_19 == V_22 )
goto exit;
V_4 = F_1 ( V_1 , V_12 - 2 ) ;
V_13 = ( V_1 [ V_12 - 2 ] << 8 ) | V_1 [ V_12 - 1 ] ;
if ( V_13 != V_4 ) {
F_9 ( & V_6 -> V_14 -> V_15 , L_2 \
L_3 , V_24 , V_8 -> V_19 ,
V_13 , V_4 ) ;
V_10 = - V_25 ;
goto V_23;
}
if ( V_1 [ 2 ] ) {
F_11 ( & V_6 -> V_14 -> V_15 , L_4 ,
V_16 , V_8 -> V_19 , V_1 [ 2 ] ) ;
V_10 = - V_25 ;
goto V_23;
}
if ( V_8 -> V_12 )
memcpy ( V_8 -> V_26 , & V_1 [ F_5 ] , V_8 -> V_12 ) ;
exit:
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_12 ( struct V_5 * V_6 , T_4 V_27 , T_2 * V_28 , int V_2 )
{
T_2 V_21 [ 6 + V_2 ] ;
T_2 V_18 = ( V_27 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_29 , V_18 , sizeof( V_21 ) , V_21 , 0 , NULL } ;
V_21 [ 0 ] = V_2 ;
V_21 [ 1 ] = 2 ;
V_21 [ 2 ] = 0 ;
V_21 [ 3 ] = 0 ;
V_21 [ 4 ] = ( V_27 >> 8 ) & 0xff ;
V_21 [ 5 ] = ( V_27 >> 0 ) & 0xff ;
memcpy ( & V_21 [ 6 ] , V_28 , V_2 ) ;
return F_2 ( V_6 , & V_8 ) ;
}
static int F_13 ( struct V_5 * V_6 , T_4 V_27 , T_2 * V_28 , int V_2 )
{
T_2 V_21 [] = { V_2 , 2 , 0 , 0 , ( V_27 >> 8 ) & 0xff , V_27 & 0xff } ;
T_2 V_18 = ( V_27 >> 16 ) & 0xff ;
struct V_7 V_8 = { V_30 , V_18 , sizeof( V_21 ) , V_21 , V_2 , V_28 } ;
return F_2 ( V_6 , & V_8 ) ;
}
static int F_14 ( struct V_5 * V_6 , T_4 V_27 , T_2 V_28 )
{
return F_12 ( V_6 , V_27 , & V_28 , 1 ) ;
}
static int F_15 ( struct V_5 * V_6 , T_4 V_27 , T_2 * V_28 )
{
return F_13 ( V_6 , V_27 , V_28 , 1 ) ;
}
static int F_16 ( struct V_5 * V_6 , T_4 V_27 , T_2 V_28 ,
T_2 V_31 )
{
int V_10 ;
T_2 V_32 ;
if ( V_31 != 0xff ) {
V_10 = F_13 ( V_6 , V_27 , & V_32 , 1 ) ;
if ( V_10 )
return V_10 ;
V_28 &= V_31 ;
V_32 &= ~ V_31 ;
V_28 |= V_32 ;
}
return F_12 ( V_6 , V_27 , & V_28 , 1 ) ;
}
static int F_17 ( struct V_33 * V_34 ,
struct V_35 V_36 [] , int V_37 )
{
struct V_5 * V_6 = F_18 ( V_34 ) ;
struct V_9 * V_9 = F_8 ( V_6 ) ;
int V_10 ;
if ( F_19 ( & V_6 -> V_38 ) < 0 )
return - V_39 ;
if ( V_37 == 2 && ! ( V_36 [ 0 ] . V_40 & V_41 ) &&
( V_36 [ 1 ] . V_40 & V_41 ) ) {
if ( V_36 [ 0 ] . V_2 > 40 || V_36 [ 1 ] . V_2 > 40 ) {
V_10 = - V_42 ;
} else if ( ( V_36 [ 0 ] . V_43 == V_9 -> V_44 [ 0 ] . V_45 ) ||
( V_36 [ 0 ] . V_43 == V_9 -> V_44 [ 1 ] . V_45 ) ) {
T_4 V_27 = V_36 [ 0 ] . V_1 [ 0 ] << 16 | V_36 [ 0 ] . V_1 [ 1 ] << 8 |
V_36 [ 0 ] . V_1 [ 2 ] ;
if ( V_36 [ 0 ] . V_43 == V_9 -> V_44 [ 1 ] . V_45 )
V_27 |= 0x100000 ;
V_10 = F_13 ( V_6 , V_27 , & V_36 [ 1 ] . V_1 [ 0 ] ,
V_36 [ 1 ] . V_2 ) ;
} else {
T_2 V_1 [ 5 + V_36 [ 0 ] . V_2 ] ;
struct V_7 V_8 = { V_46 , 0 , sizeof( V_1 ) ,
V_1 , V_36 [ 1 ] . V_2 , V_36 [ 1 ] . V_1 } ;
V_8 . V_18 |= ( ( V_36 [ 0 ] . V_43 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_36 [ 1 ] . V_2 ;
V_1 [ 1 ] = V_36 [ 0 ] . V_43 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_36 [ 0 ] . V_1 , V_36 [ 0 ] . V_2 ) ;
V_10 = F_2 ( V_6 , & V_8 ) ;
}
} else if ( V_37 == 1 && ! ( V_36 [ 0 ] . V_40 & V_41 ) ) {
if ( V_36 [ 0 ] . V_2 > 40 ) {
V_10 = - V_42 ;
} else if ( ( V_36 [ 0 ] . V_43 == V_9 -> V_44 [ 0 ] . V_45 ) ||
( V_36 [ 0 ] . V_43 == V_9 -> V_44 [ 1 ] . V_45 ) ) {
T_4 V_27 = V_36 [ 0 ] . V_1 [ 0 ] << 16 | V_36 [ 0 ] . V_1 [ 1 ] << 8 |
V_36 [ 0 ] . V_1 [ 2 ] ;
if ( V_36 [ 0 ] . V_43 == V_9 -> V_44 [ 1 ] . V_45 )
V_27 |= 0x100000 ;
V_10 = F_12 ( V_6 , V_27 , & V_36 [ 0 ] . V_1 [ 3 ] ,
V_36 [ 0 ] . V_2 - 3 ) ;
} else {
T_2 V_1 [ 5 + V_36 [ 0 ] . V_2 ] ;
struct V_7 V_8 = { V_47 , 0 , sizeof( V_1 ) , V_1 ,
0 , NULL } ;
V_8 . V_18 |= ( ( V_36 [ 0 ] . V_43 & 0x80 ) >> 3 ) ;
V_1 [ 0 ] = V_36 [ 0 ] . V_2 ;
V_1 [ 1 ] = V_36 [ 0 ] . V_43 << 1 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
memcpy ( & V_1 [ 5 ] , V_36 [ 0 ] . V_1 , V_36 [ 0 ] . V_2 ) ;
V_10 = F_2 ( V_6 , & V_8 ) ;
}
} else {
V_10 = - V_42 ;
}
F_20 ( & V_6 -> V_38 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return V_37 ;
}
static T_4 F_21 ( struct V_33 * V_48 )
{
return V_49 ;
}
static int F_22 ( struct V_5 * V_6 , const char * * V_50 )
{
int V_10 ;
T_2 V_21 [ 1 ] = { 1 } ;
T_2 V_26 [ 4 ] ;
struct V_7 V_8 = { V_51 , 0 , sizeof( V_21 ) , V_21 ,
sizeof( V_26 ) , V_26 } ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_23;
F_11 ( & V_6 -> V_14 -> V_15 , L_6 , V_16 , 4 , V_26 ) ;
if ( V_26 [ 0 ] || V_26 [ 1 ] || V_26 [ 2 ] || V_26 [ 3 ] )
V_10 = V_52 ;
else
V_10 = V_53 ;
return V_10 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_23 ( struct V_5 * V_6 ,
const struct V_54 * V_55 )
{
int V_10 , V_3 , V_56 , V_2 ;
T_2 V_21 [ 1 ] ;
T_2 V_26 [ 4 ] ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_57 = { V_22 , 0 , 0 , V_21 , 0 , NULL } ;
struct V_7 V_58 = { V_51 , 0 , 1 , V_21 , 4 , V_26 } ;
T_2 V_59 , V_32 ;
T_1 V_60 , V_61 , V_62 ;
#define F_24 58
#define F_25 7
V_10 = F_15 ( V_6 , V_63 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
if ( V_32 ) {
V_10 = F_16 ( V_6 , 0x00d8b0 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0x00d8b1 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0x00d8af , 0x00 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
F_26 ( 10000 , 50000 ) ;
V_10 = F_16 ( V_6 , 0x00d8af , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_15 ( V_6 , V_64 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0x00417f , V_32 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0x00d81a , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
}
for ( V_3 = V_55 -> V_65 ; V_3 > F_25 ; ) {
V_59 = V_55 -> V_66 [ V_55 -> V_65 - V_3 + 0 ] ;
V_60 = V_55 -> V_66 [ V_55 -> V_65 - V_3 + 1 ] << 8 ;
V_60 |= V_55 -> V_66 [ V_55 -> V_65 - V_3 + 2 ] << 0 ;
V_61 = V_55 -> V_66 [ V_55 -> V_65 - V_3 + 3 ] << 8 ;
V_61 |= V_55 -> V_66 [ V_55 -> V_65 - V_3 + 4 ] << 0 ;
V_62 = V_55 -> V_66 [ V_55 -> V_65 - V_3 + 5 ] << 8 ;
V_62 |= V_55 -> V_66 [ V_55 -> V_65 - V_3 + 6 ] << 0 ;
F_11 ( & V_6 -> V_14 -> V_15 , L_7 \
L_8 , V_16 , V_59 , V_60 ,
V_61 , V_62 ) ;
if ( ( ( V_59 != 1 ) && ( V_59 != 2 ) ) ||
( V_61 > V_3 ) ) {
F_11 ( & V_6 -> V_14 -> V_15 , L_9 , V_16 ) ;
break;
}
V_8 . V_19 = V_67 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_23;
for ( V_56 = F_25 + V_61 ; V_56 > 0 ; V_56 -= F_24 ) {
V_2 = V_56 ;
if ( V_2 > F_24 )
V_2 = F_24 ;
V_57 . V_11 = V_2 ;
V_57 . V_21 = ( T_2 * ) & V_55 -> V_66 [ V_55 -> V_65 - V_3 +
F_25 + V_61 - V_56 ] ;
V_10 = F_2 ( V_6 , & V_57 ) ;
if ( V_10 < 0 )
goto V_23;
}
V_8 . V_19 = V_68 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_23;
V_3 -= V_61 + F_25 ;
F_11 ( & V_6 -> V_14 -> V_15 , L_10 ,
V_16 , V_55 -> V_65 - V_3 ) ;
}
if ( V_3 )
F_27 ( & V_6 -> V_14 -> V_15 , L_9 , V_24 ) ;
V_8 . V_19 = V_69 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_23;
V_21 [ 0 ] = 1 ;
V_10 = F_2 ( V_6 , & V_58 ) ;
if ( V_10 < 0 )
goto V_23;
if ( ! ( V_26 [ 0 ] || V_26 [ 1 ] || V_26 [ 2 ] || V_26 [ 3 ] ) ) {
F_9 ( & V_6 -> V_14 -> V_15 , L_11 ,
V_24 ) ;
V_10 = - V_70 ;
goto V_23;
}
F_28 ( & V_6 -> V_14 -> V_15 , L_12 ,
V_24 , V_26 [ 0 ] , V_26 [ 1 ] , V_26 [ 2 ] , V_26 [ 3 ] ) ;
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_29 ( struct V_5 * V_6 ,
const struct V_54 * V_55 )
{
int V_10 , V_3 , V_71 ;
T_2 V_21 [ 1 ] ;
T_2 V_26 [ 4 ] ;
struct V_7 V_8 = { 0 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_57 = { V_72 , 0 , 0 , NULL , 0 , NULL } ;
struct V_7 V_58 = { V_51 , 0 , 1 , V_21 , 4 , V_26 } ;
#define F_25 7
for ( V_3 = F_25 , V_71 = 0 ; V_3 <= V_55 -> V_65 ; V_3 ++ ) {
if ( V_3 == V_55 -> V_65 ||
( V_55 -> V_66 [ V_3 + 0 ] == 0x03 &&
( V_55 -> V_66 [ V_3 + 1 ] == 0x00 ||
V_55 -> V_66 [ V_3 + 1 ] == 0x01 ) &&
V_55 -> V_66 [ V_3 + 2 ] == 0x00 ) ) {
V_57 . V_11 = V_3 - V_71 ;
V_57 . V_21 = ( T_2 * ) & V_55 -> V_66 [ V_71 ] ;
V_71 = V_3 ;
V_10 = F_2 ( V_6 , & V_57 ) ;
if ( V_10 < 0 )
goto V_23;
F_11 ( & V_6 -> V_14 -> V_15 , L_13 ,
V_16 , V_3 ) ;
}
}
V_8 . V_19 = V_69 ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_23;
V_21 [ 0 ] = 1 ;
V_10 = F_2 ( V_6 , & V_58 ) ;
if ( V_10 < 0 )
goto V_23;
if ( ! ( V_26 [ 0 ] || V_26 [ 1 ] || V_26 [ 2 ] || V_26 [ 3 ] ) ) {
F_9 ( & V_6 -> V_14 -> V_15 , L_11 ,
V_24 ) ;
V_10 = - V_70 ;
goto V_23;
}
F_28 ( & V_6 -> V_14 -> V_15 , L_12 ,
V_24 , V_26 [ 0 ] , V_26 [ 1 ] , V_26 [ 2 ] , V_26 [ 3 ] ) ;
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_8 ( V_6 ) ;
int V_10 , V_3 , V_73 = 0 ;
T_2 V_32 ;
T_1 V_74 ;
V_9 -> V_44 [ 0 ] . V_45 = 0x38 ;
V_10 = F_15 ( V_6 , V_63 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
V_9 -> V_75 = V_32 ;
F_11 ( & V_6 -> V_14 -> V_15 , L_14 , V_16 ,
V_9 -> V_75 ) ;
if ( V_9 -> V_75 ) {
V_10 = F_15 ( V_6 , V_64 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
V_9 -> V_44 [ 1 ] . V_45 = V_32 ;
F_11 ( & V_6 -> V_14 -> V_15 , L_15 ,
V_16 , V_32 ) ;
}
for ( V_3 = 0 ; V_3 < V_9 -> V_75 + 1 ; V_3 ++ ) {
V_10 = F_15 ( V_6 , V_76 + V_73 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
V_9 -> V_44 [ V_3 ] . V_77 = V_32 ;
F_11 ( & V_6 -> V_14 -> V_15 , L_16 ,
V_16 , V_3 , V_32 ) ;
switch ( V_32 ) {
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_9 -> V_44 [ V_3 ] . V_84 = 1 ;
break;
default:
F_27 ( & V_6 -> V_14 -> V_15 , L_17 \
L_18 ,
V_24 , V_32 ) ;
}
if ( V_3 == 1 )
switch ( V_32 ) {
case V_83 :
break;
default:
V_9 -> V_75 = false ;
F_28 ( & V_6 -> V_14 -> V_15 , L_19 \
L_20 \
L_21 , V_24 ) ;
}
V_10 = F_15 ( V_6 , V_85 + V_73 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
V_74 = V_32 ;
V_10 = F_15 ( V_6 , V_86 + V_73 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
V_74 |= V_32 << 8 ;
F_11 ( & V_6 -> V_14 -> V_15 , L_22 , V_16 , V_3 , V_74 ) ;
V_73 = 0x10 ;
}
V_10 = F_15 ( V_6 , 0x00d800 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
V_32 = ( V_32 >> 0 ) & 0x0f ;
for ( V_3 = 0 ; V_3 < F_31 ( V_9 -> V_44 ) ; V_3 ++ )
V_9 -> V_44 [ V_3 ] . clock = V_87 [ V_32 ] ;
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_8 ( V_6 ) ;
int V_10 , V_3 ;
T_2 V_32 ;
V_9 -> V_75 = false ;
V_10 = F_15 ( V_6 , 0x00d800 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
V_32 = ( V_32 >> 0 ) & 0x0f ;
for ( V_3 = 0 ; V_3 < F_31 ( V_9 -> V_44 ) ; V_3 ++ )
V_9 -> V_44 [ V_3 ] . clock = V_88 [ V_32 ] ;
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_33 ( struct V_5 * V_6 ,
int V_19 , int V_89 )
{
int V_10 ;
T_2 V_28 ;
F_11 ( & V_6 -> V_14 -> V_15 , L_23 , V_16 , V_19 , V_89 ) ;
switch ( V_19 ) {
case V_90 :
if ( V_89 )
V_28 = 0x00 ;
else
V_28 = 0x01 ;
V_10 = F_16 ( V_6 , 0x00d8e7 , V_28 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
break;
case V_91 :
if ( V_89 )
V_28 = 0x01 ;
else
V_28 = 0x00 ;
V_10 = F_16 ( V_6 , 0x00d8eb , V_28 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
break;
}
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_34 ( struct V_5 * V_6 ,
int V_19 , int V_89 )
{
int V_10 ;
switch ( V_19 ) {
case V_92 :
V_10 = F_16 ( V_6 , 0xd8eb , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0xd8ec , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0xd8ed , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0xd8d0 , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0xd8d1 , 1 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
F_26 ( 10000 , 50000 ) ;
break;
case V_93 :
V_10 = F_14 ( V_6 , 0xd8e9 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0xd8e8 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0xd8e7 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
F_26 ( 10000 , 20000 ) ;
V_10 = F_14 ( V_6 , 0xd8e7 , 0 ) ;
if ( V_10 < 0 )
goto V_23;
F_26 ( 10000 , 20000 ) ;
break;
default:
V_10 = - V_17 ;
goto V_23;
}
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_35 ( struct V_5 * V_6 , int V_19 , int V_89 )
{
struct V_9 * V_9 = F_8 ( V_6 ) ;
switch ( V_9 -> V_44 [ 0 ] . V_77 ) {
case V_79 :
return F_34 ( V_6 , V_19 , V_89 ) ;
case V_78 :
return F_33 ( V_6 , V_19 , V_89 ) ;
default:
break;
}
return 0 ;
}
static int F_36 ( void * V_94 , int V_95 ,
int V_19 , int V_89 )
{
struct V_33 * V_34 = V_94 ;
struct V_5 * V_6 = F_18 ( V_34 ) ;
F_11 ( & V_6 -> V_14 -> V_15 , L_24 ,
V_16 , V_95 , V_19 , V_89 ) ;
switch ( V_95 ) {
case V_96 :
return F_35 ( V_6 , V_19 , V_89 ) ;
default:
break;
}
return 0 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_8 ( V_6 ) ;
return V_9 -> V_75 + 1 ;
}
static int F_38 ( struct V_97 * V_34 )
{
struct V_9 * V_9 = F_39 ( V_34 ) ;
struct V_5 * V_6 = F_40 ( V_34 ) ;
int V_10 ;
if ( ! V_9 -> V_44 [ V_34 -> V_98 ] . V_77 ) {
V_10 = - V_70 ;
goto V_23;
}
if ( V_34 -> V_98 == 0 ) {
V_9 -> V_44 [ 0 ] . V_99 = V_100 ;
V_9 -> V_44 [ 1 ] . V_99 = V_101 ;
V_10 = F_14 ( V_6 , 0x00417f ,
V_9 -> V_44 [ 1 ] . V_45 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0x00d81a , V_9 -> V_75 ) ;
if ( V_10 < 0 )
goto V_23;
}
V_34 -> V_102 [ 0 ] = F_41 ( V_103 , & V_9 -> V_44 [ V_34 -> V_98 ] ,
& V_6 -> V_104 ) ;
if ( V_34 -> V_102 [ 0 ] == NULL ) {
V_10 = - V_70 ;
goto V_23;
}
V_34 -> V_102 [ 0 ] -> V_105 . V_106 = NULL ;
V_34 -> V_102 [ 0 ] -> V_107 = F_36 ;
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_42 ( struct V_97 * V_34 )
{
struct V_9 * V_9 = F_39 ( V_34 ) ;
struct V_5 * V_6 = F_40 ( V_34 ) ;
int V_10 ;
struct V_108 * V_102 ;
struct V_35 V_36 [ 1 ] ;
T_2 V_109 ;
switch ( V_9 -> V_44 [ V_34 -> V_98 ] . V_77 ) {
case V_78 :
V_10 = F_16 ( V_6 , 0x00d8ec , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0x00d8ed , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0x00d8e8 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0x00d8e9 , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_102 = F_41 ( V_110 , V_34 -> V_102 [ 0 ] ,
& V_6 -> V_104 , & V_111 ) ;
break;
case V_79 :
V_102 = F_41 ( V_112 , V_34 -> V_102 [ 0 ] ,
& V_6 -> V_104 , & V_113 ) ;
break;
case V_80 :
if ( V_34 -> V_98 == 0 ) {
V_10 = F_14 ( V_6 , 0x00d8e0 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0x00d8e1 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0x00d8df , 0 ) ;
if ( V_10 < 0 )
goto V_23;
F_43 ( 30 ) ;
V_10 = F_14 ( V_6 , 0x00d8df , 1 ) ;
if ( V_10 < 0 )
goto V_23;
F_43 ( 300 ) ;
V_10 = F_14 ( V_6 , 0x00d8c0 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0x00d8c1 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0x00d8bf , 0 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0x00d8b4 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0x00d8b5 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_14 ( V_6 , 0x00d8b3 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
V_109 = 0x60 ;
} else {
V_109 = 0x60 | 0x80 ;
}
V_102 = F_41 ( V_114 , V_34 -> V_102 [ 0 ] , & V_6 -> V_104 ,
V_109 , & V_115 [ V_34 -> V_98 ] ) ;
break;
case V_81 :
V_102 = F_41 ( V_116 , V_34 -> V_102 [ 0 ] ,
& V_6 -> V_104 , & V_117 ) ;
break;
case V_82 :
V_10 = F_16 ( V_6 , 0xd8eb , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0xd8ec , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0xd8ed , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
F_26 ( 10000 , 50000 ) ;
V_102 = F_41 ( V_118 , V_34 -> V_102 [ 0 ] ,
& V_6 -> V_104 , & V_119 ) ;
break;
case V_83 :
if ( V_34 -> V_98 == 0 ) {
V_10 = F_16 ( V_6 , 0xd8eb , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0xd8ec , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_16 ( V_6 , 0xd8ed , 0x01 , 0x01 ) ;
if ( V_10 < 0 )
goto V_23;
} else {
V_36 [ 0 ] . V_43 = 0x63 ;
V_36 [ 0 ] . V_40 = 0 ;
V_36 [ 0 ] . V_2 = 2 ;
V_36 [ 0 ] . V_1 = L_25 ;
V_10 = F_44 ( & V_6 -> V_104 , V_36 , 1 ) ;
if ( V_10 < 0 )
goto V_23;
}
F_26 ( 10000 , 50000 ) ;
V_102 = F_41 ( V_120 , V_34 -> V_102 [ 0 ] , & V_6 -> V_104 ,
& V_121 [ V_34 -> V_98 ] ) ;
break;
default:
V_102 = NULL ;
}
if ( V_102 == NULL ) {
V_10 = - V_70 ;
goto V_23;
}
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_8 ( V_6 ) ;
int V_10 , V_3 ;
T_1 V_122 = 87 * 188 / 4 ;
T_2 V_123 = 512 / 4 ;
struct V_124 V_125 [] = {
{ 0x80f99d , 0x01 , 0x01 } ,
{ 0x80f9a4 , 0x01 , 0x01 } ,
{ 0x00dd11 , 0x00 , 0x20 } ,
{ 0x00dd11 , 0x00 , 0x40 } ,
{ 0x00dd13 , 0x00 , 0x20 } ,
{ 0x00dd13 , 0x00 , 0x40 } ,
{ 0x00dd11 , 0x20 , 0x20 } ,
{ 0x00dd88 , ( V_122 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd89 , ( V_122 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0c , V_123 , 0xff } ,
{ 0x00dd11 , V_9 -> V_75 << 6 , 0x40 } ,
{ 0x00dd8a , ( V_122 >> 0 ) & 0xff , 0xff } ,
{ 0x00dd8b , ( V_122 >> 8 ) & 0xff , 0xff } ,
{ 0x00dd0d , V_123 , 0xff } ,
{ 0x80f9a3 , V_9 -> V_75 , 0x01 } ,
{ 0x80f9cd , V_9 -> V_75 , 0x01 } ,
{ 0x80f99d , 0x00 , 0x01 } ,
{ 0x80f9a4 , 0x00 , 0x01 } ,
} ;
F_11 ( & V_6 -> V_14 -> V_15 , L_26 \
L_27 , V_16 ,
V_6 -> V_14 -> V_126 , V_122 , V_123 ) ;
for ( V_3 = 0 ; V_3 < F_31 ( V_125 ) ; V_3 ++ ) {
V_10 = F_16 ( V_6 , V_125 [ V_3 ] . V_27 , V_125 [ V_3 ] . V_28 ,
V_125 [ V_3 ] . V_31 ) ;
if ( V_10 < 0 )
goto V_23;
}
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
static int F_46 ( struct V_5 * V_6 )
{
unsigned int V_127 ;
unsigned char V_128 [ 4 ] ;
int V_10 ;
struct V_7 V_8 = { V_129 , 0 , 0 , NULL , 4 , V_128 } ;
V_10 = F_2 ( V_6 , & V_8 ) ;
if ( V_10 < 0 )
goto V_23;
if ( ( V_128 [ 2 ] + V_128 [ 3 ] ) == 0xff ) {
if ( ( V_128 [ 0 ] + V_128 [ 1 ] ) == 0xff ) {
V_127 = V_128 [ 0 ] << 8 | V_128 [ 2 ] ;
} else {
V_127 = V_128 [ 0 ] << 16 | V_128 [ 1 ] << 8 | V_128 [ 2 ] ;
}
} else {
V_127 = V_128 [ 0 ] << 24 | V_128 [ 1 ] << 16 | V_128 [ 2 ] << 8 | V_128 [ 3 ] ;
}
F_47 ( V_6 -> V_130 , V_127 , 0 ) ;
V_23:
return 0 ;
}
static int F_48 ( struct V_5 * V_6 , struct V_131 * V_132 )
{
int V_10 ;
T_2 V_32 ;
V_10 = F_15 ( V_6 , V_133 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
F_11 ( & V_6 -> V_14 -> V_15 , L_28 , V_16 , V_32 ) ;
if ( V_32 == 5 ) {
V_10 = F_15 ( V_6 , V_134 , & V_32 ) ;
if ( V_10 < 0 )
goto V_23;
F_11 ( & V_6 -> V_14 -> V_15 , L_29 , V_16 , V_32 ) ;
switch ( V_32 ) {
case 0 :
default:
V_132 -> V_135 = V_136 ;
break;
case 1 :
V_132 -> V_135 = V_137 ;
break;
}
V_132 -> V_138 = F_46 ;
V_132 -> V_139 = 500 ;
if ( ! V_132 -> V_140 )
V_132 -> V_140 = V_141 ;
}
return 0 ;
V_23:
F_11 ( & V_6 -> V_14 -> V_15 , L_5 , V_16 , V_10 ) ;
return V_10 ;
}
