static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_7 [ V_8 ] ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = 1 + V_5 ,
. V_7 = V_7 ,
}
} ;
if ( 1 + V_5 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_1 ,
V_17 , V_3 , V_5 ) ;
return - V_18 ;
}
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_3 ( V_2 -> V_15 , V_10 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_2 ,
V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_7 [ V_8 ] ;
struct V_9 V_10 [ 2 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = V_20 ,
. V_5 = V_5 ,
. V_7 = V_7 ,
}
} ;
if ( V_5 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_1 ,
V_17 , V_3 , V_5 ) ;
return - V_18 ;
}
V_6 = F_3 ( V_2 -> V_15 , V_10 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , V_7 , V_5 ) ;
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_3 ,
V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_4 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_21 )
{
int V_6 ;
T_1 V_22 ;
if ( V_21 != 0xff ) {
V_6 = F_4 ( V_2 , V_3 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_21 ;
V_22 &= ~ V_21 ;
V_4 |= V_22 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , T_1 V_21 )
{
int V_6 , V_23 ;
T_1 V_22 ;
V_6 = F_4 ( V_2 , V_3 , & V_22 , 1 ) ;
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
static int F_9 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_6 , V_23 ;
T_1 V_22 ;
if ( ! V_2 -> V_26 ) {
V_6 = - V_27 ;
goto error;
}
V_6 = F_1 ( V_2 , 0x00 , V_25 -> args , V_25 -> V_5 ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0x1f , 1 ) ;
if ( V_6 )
goto error;
for ( V_23 = 1000 , V_22 = 1 ; V_23 && V_22 ; V_23 -- ) {
V_6 = F_6 ( V_2 , 0x1f , & V_22 ) ;
if ( V_6 )
goto error;
F_10 ( 200 , 5000 ) ;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_4 , V_28 , V_23 ) ;
if ( V_23 == 0 ) {
V_6 = - V_29 ;
goto error;
}
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_30 * V_31 ,
T_2 V_32 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
int V_6 ;
T_1 V_34 ;
if ( ! V_2 -> V_26 ) {
V_6 = - V_27 ;
goto error;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_6 , V_28 ,
V_32 ) ;
switch ( V_32 ) {
case V_35 :
V_34 = 1 ;
break;
case V_36 :
V_34 = 0 ;
break;
default:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 ,
V_28 ) ;
V_6 = - V_18 ;
goto error;
}
V_25 . args [ 0 ] = V_37 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = 0x00 ;
V_25 . args [ 3 ] = 0x00 ;
V_25 . args [ 4 ] = V_34 ;
V_25 . V_5 = 5 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_30 * V_31 ,
T_3 V_38 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
int V_6 ;
T_1 V_39 ;
if ( ! V_2 -> V_26 ) {
V_6 = - V_27 ;
goto error;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_8 , V_28 , V_38 ) ;
switch ( V_38 ) {
case V_40 :
V_39 = 0 ;
break;
case V_41 :
V_39 = 1 ;
break;
case V_42 :
V_39 = 0 ;
break;
default:
F_11 ( & V_2 -> V_15 -> V_16 , L_9 ,
V_28 ) ;
V_6 = - V_18 ;
goto error;
}
V_25 . args [ 0 ] = V_43 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = V_39 ;
V_25 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_30 * V_31 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
int V_6 , V_23 ;
T_1 V_22 ;
if ( ! V_2 -> V_26 ) {
V_6 = - V_27 ;
goto error;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_10 , V_28 ,
V_45 -> V_46 ) ;
if ( V_45 -> V_46 < 3 || V_45 -> V_46 > 6 ) {
V_6 = - V_18 ;
goto error;
}
for ( V_23 = 500 , V_22 = 0 ; V_23 && ! V_22 ; V_23 -- ) {
V_6 = F_8 ( V_2 , 0x47 , & V_22 , 0x01 ) ;
if ( V_6 )
goto error;
F_10 ( 10000 , 20000 ) ;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_4 , V_28 , V_23 ) ;
if ( V_23 == 0 ) {
V_6 = - V_29 ;
goto error;
}
V_6 = F_7 ( V_2 , 0x47 , 0x00 , 0x01 ) ;
if ( V_6 )
goto error;
V_25 . args [ 0 ] = V_47 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = 0 ;
V_25 . args [ 3 ] = 0 ;
V_25 . args [ 4 ] = 2 ;
V_25 . args [ 5 ] = 0 ;
V_25 . args [ 6 ] = V_45 -> V_46 ;
memcpy ( & V_25 . args [ 7 ] , V_45 -> V_10 , V_45 -> V_46 ) ;
V_25 . V_5 = 7 + V_45 -> V_46 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_30 * V_31 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
int V_6 , V_23 ;
T_1 V_22 ;
if ( ! V_2 -> V_26 ) {
V_6 = - V_27 ;
goto error;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_11 , V_28 ) ;
for ( V_23 = 500 , V_22 = 0 ; V_23 && ! V_22 ; V_23 -- ) {
V_6 = F_8 ( V_2 , 0x47 , & V_22 , 0x02 ) ;
if ( V_6 )
goto error;
F_10 ( 10000 , 20000 ) ;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_4 , V_28 , V_23 ) ;
if ( V_23 == 0 ) {
V_6 = - V_29 ;
goto error;
}
V_6 = F_6 ( V_2 , 0x46 , & V_22 ) ;
if ( V_6 )
goto error;
V_49 -> V_46 = V_22 & 0x1f ;
if ( V_49 -> V_46 > sizeof( V_49 -> V_10 ) )
V_49 -> V_46 = sizeof( V_49 -> V_10 ) ;
V_25 . args [ 0 ] = V_50 ;
V_25 . args [ 1 ] = 0 ;
V_25 . V_5 = 2 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
V_6 = F_4 ( V_2 , V_25 . V_5 , V_49 -> V_10 , V_49 -> V_46 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_30 * V_31 ,
T_4 V_51 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
int V_6 , V_23 ;
T_1 V_22 , V_52 ;
if ( ! V_2 -> V_26 ) {
V_6 = - V_27 ;
goto error;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_12 , V_28 ,
V_51 ) ;
switch ( V_51 ) {
case V_53 :
V_52 = 0 ;
break;
case V_54 :
V_52 = 1 ;
break;
default:
F_11 ( & V_2 -> V_15 -> V_16 , L_13 ,
V_28 ) ;
V_6 = - V_18 ;
goto error;
}
for ( V_23 = 500 , V_22 = 0 ; V_23 && ! V_22 ; V_23 -- ) {
V_6 = F_8 ( V_2 , 0x47 , & V_22 , 0x01 ) ;
if ( V_6 )
goto error;
F_10 ( 10000 , 20000 ) ;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_4 , V_28 , V_23 ) ;
if ( V_23 == 0 ) {
V_6 = - V_29 ;
goto error;
}
V_6 = F_7 ( V_2 , 0x47 , 0x00 , 0x01 ) ;
if ( V_6 )
goto error;
V_25 . args [ 0 ] = V_55 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = V_52 ;
V_25 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_30 * V_31 , T_5 * V_56 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
int V_6 ;
T_1 V_22 ;
* V_56 = 0 ;
if ( ! V_2 -> V_26 ) {
V_6 = 0 ;
goto error;
}
V_6 = F_6 ( V_2 , 0x39 , & V_22 ) ;
if ( V_6 )
goto error;
if ( V_22 & 0x02 )
* V_56 |= V_57 | V_58 ;
if ( V_22 & 0x04 )
* V_56 |= V_59 ;
if ( V_22 & 0x08 )
* V_56 |= V_60 | V_61 ;
V_2 -> V_62 = * V_56 ;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_30 * V_31 , T_6 * V_63 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
if ( ! V_2 -> V_26 || ! ( V_2 -> V_62 & V_61 ) ) {
* V_63 = 0 ;
V_6 = 0 ;
goto error;
}
V_6 = F_4 ( V_2 , 0x3a , V_7 , 2 ) ;
if ( V_6 )
goto error;
* V_63 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_30 * V_31 , T_6 * V_64 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
int V_6 ;
T_1 V_22 ;
if ( ! V_2 -> V_26 || ! ( V_2 -> V_62 & V_61 ) ) {
* V_64 = 0 ;
V_6 = 0 ;
goto error;
}
V_25 . args [ 0 ] = V_65 ;
V_25 . args [ 1 ] = 0 ;
V_25 . V_5 = 2 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
V_6 = F_6 ( V_2 , 0x50 , & V_22 ) ;
if ( V_6 )
goto error;
if ( V_22 < 181 )
V_22 = 181 ;
else if ( V_22 > 236 )
V_22 = 236 ;
* V_64 = ( V_22 - 181 ) * 0xffff / ( 236 - 181 ) ;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_30 * V_31 , T_7 * V_66 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
int V_6 , V_23 , V_5 ;
T_1 V_22 , V_3 , V_7 [ 8 ] ;
if ( ! V_2 -> V_26 || ! ( V_2 -> V_62 & V_61 ) ) {
* V_66 = V_2 -> V_66 = 0 ;
V_6 = 0 ;
goto error;
}
switch ( V_2 -> V_67 ) {
case V_68 :
V_3 = 0x4c ;
V_5 = 8 ;
V_23 = 1 ;
break;
case V_69 :
V_3 = 0x4d ;
V_5 = 4 ;
V_23 = 0 ;
break;
default:
* V_66 = V_2 -> V_66 = 0 ;
return 0 ;
}
V_6 = F_6 ( V_2 , V_3 , & V_22 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_70 [ V_23 ] == V_22 ) {
F_11 ( & V_2 -> V_15 -> V_16 , L_14 , V_28 ,
V_22 ) ;
* V_66 = V_2 -> V_66 ;
return 0 ;
} else {
V_2 -> V_70 [ V_23 ] = V_22 ;
}
V_25 . args [ 0 ] = V_71 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = V_23 ;
V_25 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
V_6 = F_4 ( V_2 , V_25 . V_5 , V_7 , V_5 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_67 == V_68 ) {
* V_66 = ( V_7 [ 0 ] << 24 ) | ( V_7 [ 1 ] << 16 ) | ( V_7 [ 2 ] << 8 ) | V_7 [ 3 ] ;
V_2 -> V_72 += ( V_7 [ 4 ] << 8 ) | V_7 [ 5 ] ;
} else {
* V_66 = ( V_7 [ 0 ] << 8 ) | V_7 [ 1 ] ;
}
V_2 -> V_66 = * V_66 ;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_30 * V_31 , T_7 * V_73 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
int V_6 = 0 ;
if ( ! V_2 -> V_26 || ! ( V_2 -> V_62 & V_61 ) ) {
* V_73 = 0 ;
goto error;
}
* V_73 = V_2 -> V_72 ;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
struct V_74 * V_75 = & V_31 -> V_76 ;
int V_6 , V_23 ;
T_1 V_77 , V_78 , V_79 , V_80 , div ;
T_8 V_81 ;
F_11 ( & V_2 -> V_15 -> V_16 ,
L_15 ,
V_28 , V_75 -> V_67 , V_75 -> V_81 ,
V_75 -> V_82 , V_75 -> V_83 , V_75 -> V_80 , V_75 -> V_79 ,
V_75 -> V_78 ) ;
V_2 -> V_67 = V_84 ;
if ( ! V_2 -> V_26 ) {
V_6 = - V_27 ;
goto error;
}
switch ( V_75 -> V_80 ) {
case V_85 :
V_80 = 1 ;
break;
case V_86 :
V_80 = 0 ;
break;
case V_87 :
V_80 = 3 ;
break;
default:
F_11 ( & V_2 -> V_15 -> V_16 , L_16 , V_28 ) ;
V_6 = - V_18 ;
goto error;
}
switch ( V_75 -> V_67 ) {
case V_68 :
V_81 = V_88 ;
V_78 = 0 ;
V_79 = 2 ;
break;
case V_69 :
V_81 = V_75 -> V_81 ;
switch ( V_75 -> V_78 ) {
case V_89 :
V_78 = 2 ;
break;
case V_90 :
V_78 = 1 ;
break;
case V_91 :
V_78 = 0 ;
break;
case V_92 :
default:
F_11 ( & V_2 -> V_15 -> V_16 , L_17 ,
V_28 ) ;
V_6 = - V_18 ;
goto error;
}
switch ( V_75 -> V_79 ) {
case V_93 :
V_79 = 0 ;
break;
case V_94 :
V_79 = 1 ;
break;
case V_95 :
V_79 = 2 ;
break;
default:
F_11 ( & V_2 -> V_15 -> V_16 , L_18 ,
V_28 ) ;
V_6 = - V_18 ;
goto error;
}
break;
default:
F_11 ( & V_2 -> V_15 -> V_16 , L_19 ,
V_28 ) ;
V_6 = - V_18 ;
goto error;
}
for ( V_23 = 0 , V_77 = 0xff ; V_23 < F_23 ( V_96 ) ; V_23 ++ ) {
if ( V_75 -> V_67 == V_96 [ V_23 ] . V_67 &&
V_81 == V_96 [ V_23 ] . V_81 &&
V_75 -> V_97 == V_96 [ V_23 ] . V_98 ) {
V_77 = V_96 [ V_23 ] . V_4 ;
F_11 ( & V_2 -> V_15 -> V_16 , L_20 ,
V_28 , V_77 ) ;
break;
}
}
if ( V_77 == 0xff ) {
F_11 ( & V_2 -> V_15 -> V_16 , L_21 ,
V_28 ) ;
V_6 = - V_18 ;
goto error;
}
if ( V_75 -> V_83 <= 5000000 )
div = 14 ;
else
div = 4 ;
V_6 = F_5 ( V_2 , 0x81 , div ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0xe3 , div ) ;
if ( V_6 )
goto error;
V_25 . args [ 0 ] = V_99 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = V_77 ;
V_25 . args [ 3 ] = ( V_75 -> V_82 >> 16 ) & 0xff ;
V_25 . args [ 4 ] = ( V_75 -> V_82 >> 8 ) & 0xff ;
V_25 . args [ 5 ] = ( V_75 -> V_82 >> 0 ) & 0xff ;
V_25 . args [ 6 ] = ( ( V_75 -> V_83 / 1000 ) >> 8 ) & 0xff ;
V_25 . args [ 7 ] = ( ( V_75 -> V_83 / 1000 ) >> 0 ) & 0xff ;
V_25 . args [ 8 ] = ( V_100 . V_101 . V_102 >> 8 ) & 0xff ;
V_25 . args [ 9 ] = ( V_100 . V_101 . V_102 >> 0 ) & 0xff ;
V_25 . args [ 10 ] = V_78 ;
V_25 . args [ 11 ] = V_80 ;
V_25 . args [ 12 ] = V_79 ;
V_25 . args [ 13 ] = 0x00 ;
V_25 . args [ 14 ] = 0x00 ;
V_25 . V_5 = 15 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
V_2 -> V_67 = V_75 -> V_67 ;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_74 * V_75 = & V_31 -> V_76 ;
int V_6 , V_23 ;
T_1 V_7 [ 5 ] , V_22 ;
if ( ! V_2 -> V_26 || ! ( V_2 -> V_62 & V_61 ) ) {
V_6 = - V_27 ;
goto error;
}
V_6 = F_4 ( V_2 , 0x30 , V_7 , 5 ) ;
if ( V_6 )
goto error;
V_22 = V_7 [ 0 ] & 0x3f ;
for ( V_23 = 0 ; V_23 < F_23 ( V_96 ) ; V_23 ++ ) {
if ( V_22 == V_96 [ V_23 ] . V_4 ) {
V_75 -> V_81 = V_96 [ V_23 ] . V_81 ;
V_75 -> V_97 = V_96 [ V_23 ] . V_98 ;
V_75 -> V_67 = V_96 [ V_23 ] . V_67 ;
}
}
switch ( ( V_7 [ 1 ] >> 0 ) & 0x01 ) {
case 0 :
V_75 -> V_80 = V_86 ;
break;
case 1 :
V_75 -> V_80 = V_85 ;
break;
}
switch ( ( V_7 [ 1 ] >> 7 ) & 0x01 ) {
case 0 :
V_75 -> V_79 = V_93 ;
break;
case 1 :
V_75 -> V_79 = V_94 ;
break;
}
V_75 -> V_82 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 3 ] << 8 ) | ( V_7 [ 4 ] << 0 ) ;
V_6 = F_4 ( V_2 , 0x52 , V_7 , 3 ) ;
if ( V_6 )
goto error;
V_75 -> V_83 = ( ( V_7 [ 0 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | ( V_7 [ 2 ] << 0 ) ) * 1000 ;
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_25 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
int V_6 , V_23 , V_5 , V_103 , V_104 ;
const struct V_105 * V_106 ;
T_1 * V_107 = V_108 ;
T_1 V_22 , V_7 [ 4 ] ;
struct V_109 V_110 [] = {
{ 0xcd , 0x00 , 0x07 } ,
{ 0x80 , 0x00 , 0x02 } ,
{ 0xcd , 0x00 , 0xc0 } ,
{ 0xce , 0x00 , 0x1b } ,
{ 0x9d , 0x00 , 0x01 } ,
{ 0x9d , 0x00 , 0x02 } ,
{ 0x9e , 0x00 , 0x01 } ,
{ 0x87 , 0x00 , 0x80 } ,
{ 0xce , 0x00 , 0x08 } ,
{ 0xce , 0x00 , 0x10 } ,
} ;
struct V_109 V_111 [] = {
{ 0xf1 , 0x70 , 0xff } ,
{ 0x88 , V_2 -> V_12 . V_112 , 0x3f } ,
{ 0x89 , 0x00 , 0x10 } ,
{ 0x89 , 0x10 , 0x10 } ,
{ 0xc0 , 0x01 , 0x01 } ,
{ 0xc0 , 0x00 , 0x01 } ,
{ 0xe0 , 0xff , 0xff } ,
{ 0xe0 , 0x00 , 0xff } ,
{ 0x96 , 0x1e , 0x7e } ,
{ 0x8b , 0x08 , 0x08 } ,
{ 0x8b , 0x00 , 0x08 } ,
{ 0x8f , 0x1a , 0x7e } ,
{ 0x8c , 0x68 , 0xff } ,
{ 0x8d , 0x08 , 0xff } ,
{ 0x8e , 0x4c , 0xff } ,
{ 0x8f , 0x01 , 0x01 } ,
{ 0x8b , 0x04 , 0x04 } ,
{ 0x8b , 0x00 , 0x04 } ,
{ 0x87 , 0x05 , 0x07 } ,
{ 0x80 , 0x00 , 0x20 } ,
{ 0xc8 , 0x01 , 0xff } ,
{ 0xb4 , 0x47 , 0xff } ,
{ 0xb5 , 0x9c , 0xff } ,
{ 0xb6 , 0x7d , 0xff } ,
{ 0xba , 0x00 , 0x03 } ,
{ 0xb7 , 0x47 , 0xff } ,
{ 0xb8 , 0x9c , 0xff } ,
{ 0xb9 , 0x7d , 0xff } ,
{ 0xba , 0x00 , 0x0c } ,
{ 0xc8 , 0x00 , 0xff } ,
{ 0xcd , 0x00 , 0x04 } ,
{ 0xcd , 0x00 , 0x20 } ,
{ 0xe8 , 0x02 , 0xff } ,
{ 0xcf , 0x20 , 0xff } ,
{ 0x9b , 0xd7 , 0xff } ,
{ 0x9a , 0x01 , 0x03 } ,
{ 0xa8 , 0x05 , 0x0f } ,
{ 0xa8 , 0x65 , 0xf0 } ,
{ 0xa6 , 0xa0 , 0xf0 } ,
{ 0x9d , 0x50 , 0xfc } ,
{ 0x9e , 0x20 , 0xe0 } ,
{ 0xa3 , 0x1c , 0x7c } ,
{ 0xd5 , 0x03 , 0x03 } ,
} ;
if ( V_2 -> V_26 ) {
for ( V_23 = 0 ; V_23 < F_23 ( V_110 ) ; V_23 ++ ) {
V_6 = F_7 ( V_2 , V_110 [ V_23 ] . V_3 ,
V_110 [ V_23 ] . V_4 , V_110 [ V_23 ] . V_21 ) ;
if ( V_6 )
goto error;
}
V_25 . args [ 0 ] = V_113 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = 0 ;
V_25 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
} else {
V_6 = F_26 ( & V_106 , V_107 , V_2 -> V_15 -> V_16 . V_114 ) ;
if ( V_6 ) {
F_27 ( & V_2 -> V_15 -> V_16 ,
L_22 ,
V_17 , V_107 , V_6 ) ;
goto error;
}
for ( V_23 = 0 ; V_23 < F_23 ( V_111 ) ; V_23 ++ ) {
V_6 = F_7 ( V_2 , V_111 [ V_23 ] . V_3 ,
V_111 [ V_23 ] . V_4 , V_111 [ V_23 ] . V_21 ) ;
if ( V_6 )
goto V_115;
}
V_6 = F_5 ( V_2 , 0xe0 , 0x7f ) ;
if ( V_6 )
goto V_115;
V_6 = F_5 ( V_2 , 0xf7 , 0x81 ) ;
if ( V_6 )
goto V_115;
V_6 = F_5 ( V_2 , 0xf8 , 0x00 ) ;
if ( V_6 )
goto V_115;
V_6 = F_5 ( V_2 , 0xf9 , 0x00 ) ;
if ( V_6 )
goto V_115;
F_28 ( & V_2 -> V_15 -> V_16 ,
L_23 ,
V_17 , V_100 . V_101 . V_116 ) ;
F_28 ( & V_2 -> V_15 -> V_16 ,
L_24 ,
V_17 , V_107 ) ;
V_104 = V_106 -> V_117 - 1 ;
for ( V_103 = V_104 ; V_103 > 0 ;
V_103 -= ( V_2 -> V_12 . V_118 - 1 ) ) {
V_5 = V_103 ;
if ( V_5 > ( V_2 -> V_12 . V_118 - 1 ) )
V_5 = ( V_2 -> V_12 . V_118 - 1 ) ;
V_6 = F_1 ( V_2 , 0xfa ,
( T_1 * ) & V_106 -> V_119 [ V_104 - V_103 ] , V_5 ) ;
if ( V_6 ) {
F_27 ( & V_2 -> V_15 -> V_16 ,
L_25 ,
V_17 , V_6 ) ;
goto V_115;
}
}
F_29 ( V_106 ) ;
V_6 = F_5 ( V_2 , 0xf7 , 0x0c ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0xe0 , 0x00 ) ;
if ( V_6 )
goto error;
F_30 ( 250 ) ;
V_6 = F_6 ( V_2 , 0x51 , & V_22 ) ;
if ( V_6 )
goto error;
if ( V_22 ) {
F_28 ( & V_2 -> V_15 -> V_16 , L_26 ,
V_17 ) ;
V_6 = - V_27 ;
goto error;
} else {
V_2 -> V_26 = true ;
}
V_25 . args [ 0 ] = V_120 ;
V_25 . V_5 = 1 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
V_6 = F_4 ( V_2 , V_25 . V_5 , V_7 , 4 ) ;
if ( V_6 )
goto error;
F_28 ( & V_2 -> V_15 -> V_16 , L_27 ,
V_17 , V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ) ;
F_28 ( & V_2 -> V_15 -> V_16 , L_28 ,
V_17 , V_100 . V_101 . V_116 ) ;
V_6 = F_4 ( V_2 , 0x81 , V_7 , 2 ) ;
if ( V_6 )
goto error;
V_25 . args [ 0 ] = V_121 ;
V_25 . args [ 1 ] = ( ( V_2 -> V_12 . V_122 / 1000 ) >> 8 ) & 0xff ;
V_25 . args [ 2 ] = ( ( V_2 -> V_12 . V_122 / 1000 ) >> 0 ) & 0xff ;
V_25 . args [ 3 ] = V_7 [ 0 ] ;
V_25 . args [ 4 ] = V_7 [ 1 ] ;
V_25 . args [ 5 ] = V_2 -> V_12 . V_112 ;
V_25 . args [ 6 ] = V_2 -> V_12 . V_123 ;
V_25 . args [ 7 ] = 0x00 ;
V_25 . V_5 = 8 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_12 . V_124 )
V_22 = V_2 -> V_12 . V_124 ;
else
V_22 = 0x14 ;
V_25 . args [ 0 ] = V_125 ;
V_25 . args [ 1 ] = 0x00 ;
V_25 . args [ 2 ] = 0x00 ;
V_25 . args [ 3 ] = 0x00 ;
V_25 . args [ 4 ] = 0x00 ;
V_25 . args [ 5 ] = V_22 ;
V_25 . args [ 6 ] = 0x00 ;
V_25 . args [ 7 ] = 0x03 ;
V_25 . args [ 8 ] = 0x02 ;
V_25 . args [ 9 ] = 0x02 ;
V_25 . args [ 10 ] = 0x00 ;
V_25 . args [ 11 ] = 0x00 ;
V_25 . args [ 12 ] = 0x00 ;
V_25 . args [ 13 ] = 0x00 ;
V_25 . args [ 14 ] = 0x00 ;
V_25 . V_5 = 15 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
V_25 . args [ 0 ] = V_126 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = V_2 -> V_12 . V_127 ;
V_25 . args [ 3 ] = 0x00 ;
V_25 . args [ 4 ] = 0x04 ;
V_25 . args [ 5 ] = 0x00 ;
V_25 . V_5 = 6 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
V_6 = F_7 ( V_2 , 0xf0 , 0x01 , 0x01 ) ;
if ( V_6 )
goto error;
V_25 . args [ 0 ] = V_128 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = 150 ;
V_25 . args [ 3 ] = 3 ;
V_25 . args [ 4 ] = 22 ;
V_25 . args [ 5 ] = 1 ;
V_25 . args [ 6 ] = 1 ;
V_25 . args [ 7 ] = 30 ;
V_25 . args [ 8 ] = 30 ;
V_25 . args [ 9 ] = 30 ;
V_25 . args [ 10 ] = 30 ;
V_25 . V_5 = 11 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
V_25 . args [ 0 ] = V_129 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = 14 ;
V_25 . args [ 3 ] = 14 ;
V_25 . V_5 = 4 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
}
return V_6 ;
V_115:
F_29 ( V_106 ) ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_31 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
struct V_24 V_25 ;
int V_6 , V_23 ;
struct V_109 V_110 [] = {
{ 0xcd , 0x07 , 0x07 } ,
{ 0x80 , 0x02 , 0x02 } ,
{ 0xcd , 0xc0 , 0xc0 } ,
{ 0xce , 0x1b , 0x1b } ,
{ 0x9d , 0x01 , 0x01 } ,
{ 0x9d , 0x02 , 0x02 } ,
{ 0x9e , 0x01 , 0x01 } ,
{ 0x87 , 0x80 , 0x80 } ,
{ 0xce , 0x08 , 0x08 } ,
{ 0xce , 0x10 , 0x10 } ,
} ;
if ( ! V_2 -> V_26 ) {
V_6 = - V_27 ;
goto error;
}
V_25 . args [ 0 ] = V_113 ;
V_25 . args [ 1 ] = 0 ;
V_25 . args [ 2 ] = 1 ;
V_25 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_25 ) ;
if ( V_6 )
goto error;
for ( V_23 = 0 ; V_23 < F_23 ( V_110 ) ; V_23 ++ ) {
V_6 = F_7 ( V_2 , V_110 [ V_23 ] . V_3 , V_110 [ V_23 ] . V_4 ,
V_110 [ V_23 ] . V_21 ) ;
if ( V_6 )
goto error;
}
return V_6 ;
error:
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_32 ( struct V_30 * V_31 ,
struct V_130 * V_131 )
{
V_131 -> V_132 = 8000 ;
V_131 -> V_133 = 0 ;
V_131 -> V_134 = 0 ;
return 0 ;
}
static void F_33 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_33 ;
F_34 ( V_2 ) ;
}
struct V_30 * F_35 ( const struct V_135 * V_136 ,
struct V_137 * V_15 )
{
int V_6 ;
struct V_1 * V_2 = NULL ;
T_1 V_22 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_138 ) ;
if ( V_2 == NULL ) {
V_6 = - V_139 ;
goto error;
}
if ( ! V_136 -> V_13 ) {
F_11 ( & V_15 -> V_16 , L_29 , V_28 ) ;
V_6 = - V_18 ;
goto error;
}
if ( ! V_136 -> V_124 ) {
F_11 ( & V_15 -> V_16 , L_30 , V_28 ) ;
V_6 = - V_18 ;
goto error;
}
V_2 -> V_15 = V_15 ;
memcpy ( & V_2 -> V_12 , V_136 , sizeof( struct V_135 ) ) ;
V_6 = F_6 ( V_2 , 0xff , & V_22 ) ;
if ( V_6 || V_22 != 0x0f )
goto error;
V_6 = F_6 ( V_2 , 0xdd , & V_22 ) ;
if ( V_6 || V_22 != 0x00 )
goto error;
V_6 = F_6 ( V_2 , 0xfe , & V_22 ) ;
if ( V_6 || V_22 != 0x01 )
goto error;
memcpy ( & V_2 -> V_31 . V_140 , & V_100 , sizeof( struct V_141 ) ) ;
V_2 -> V_31 . V_33 = V_2 ;
return & V_2 -> V_31 ;
error:
F_11 ( & V_15 -> V_16 , L_5 , V_28 , V_6 ) ;
F_34 ( V_2 ) ;
return NULL ;
}
