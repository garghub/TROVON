static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_7 [ V_5 + 1 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_1 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
T_1 V_7 [ V_5 ] ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = V_18 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , V_7 , V_5 ) ;
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_3 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
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
T_1 V_3 , T_1 V_4 , T_1 V_19 )
{
int V_6 ;
T_1 V_20 ;
if ( V_19 != 0xff ) {
V_6 = F_4 ( V_2 , V_3 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_19 ;
V_20 &= ~ V_19 ;
V_4 |= V_20 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , T_1 V_19 )
{
int V_6 , V_21 ;
T_1 V_20 ;
V_6 = F_4 ( V_2 , V_3 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_20 &= V_19 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
if ( ( V_19 >> V_21 ) & 0x01 )
break;
}
* V_4 = V_20 >> V_21 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
int V_6 , V_21 ;
T_1 V_20 ;
if ( ! V_2 -> V_24 ) {
V_6 = - V_25 ;
goto error;
}
V_6 = F_1 ( V_2 , 0x00 , V_23 -> args , V_23 -> V_5 ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0x1f , 1 ) ;
if ( V_6 )
goto error;
for ( V_21 = 1000 , V_20 = 1 ; V_21 && V_20 ; V_21 -- ) {
V_6 = F_6 ( V_2 , 0x1f , & V_20 ) ;
if ( V_6 )
goto error;
F_10 ( 200 , 5000 ) ;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_4 , V_26 , V_21 ) ;
if ( V_21 == 0 ) {
V_6 = - V_27 ;
goto error;
}
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_28 * V_29 ,
T_2 V_30 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
int V_6 ;
T_1 V_32 ;
if ( ! V_2 -> V_24 ) {
V_6 = - V_25 ;
goto error;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_6 , V_26 ,
V_30 ) ;
switch ( V_30 ) {
case V_33 :
V_32 = 1 ;
break;
case V_34 :
V_32 = 0 ;
break;
default:
F_11 ( & V_2 -> V_14 -> V_15 , L_7 ,
V_26 ) ;
V_6 = - V_35 ;
goto error;
}
V_23 . args [ 0 ] = V_36 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = 0x00 ;
V_23 . args [ 3 ] = 0x00 ;
V_23 . args [ 4 ] = V_32 ;
V_23 . V_5 = 5 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_28 * V_29 ,
T_3 V_37 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
int V_6 ;
T_1 V_38 ;
if ( ! V_2 -> V_24 ) {
V_6 = - V_25 ;
goto error;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_8 , V_26 , V_37 ) ;
switch ( V_37 ) {
case V_39 :
V_38 = 0 ;
break;
case V_40 :
V_38 = 1 ;
break;
case V_41 :
V_38 = 0 ;
break;
default:
F_11 ( & V_2 -> V_14 -> V_15 , L_9 ,
V_26 ) ;
V_6 = - V_35 ;
goto error;
}
V_23 . args [ 0 ] = V_42 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = V_38 ;
V_23 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_28 * V_29 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
int V_6 , V_21 ;
T_1 V_20 ;
if ( ! V_2 -> V_24 ) {
V_6 = - V_25 ;
goto error;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_10 , V_26 ,
V_44 -> V_45 ) ;
if ( V_44 -> V_45 < 3 || V_44 -> V_45 > 6 ) {
V_6 = - V_35 ;
goto error;
}
for ( V_21 = 500 , V_20 = 0 ; V_21 && ! V_20 ; V_21 -- ) {
V_6 = F_8 ( V_2 , 0x47 , & V_20 , 0x01 ) ;
if ( V_6 )
goto error;
F_10 ( 10000 , 20000 ) ;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_4 , V_26 , V_21 ) ;
if ( V_21 == 0 ) {
V_6 = - V_27 ;
goto error;
}
V_6 = F_7 ( V_2 , 0x47 , 0x00 , 0x01 ) ;
if ( V_6 )
goto error;
V_23 . args [ 0 ] = V_46 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = 0 ;
V_23 . args [ 3 ] = 0 ;
V_23 . args [ 4 ] = 2 ;
V_23 . args [ 5 ] = 0 ;
V_23 . args [ 6 ] = V_44 -> V_45 ;
memcpy ( & V_23 . args [ 7 ] , V_44 -> V_9 , V_44 -> V_45 ) ;
V_23 . V_5 = 7 + V_44 -> V_45 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_28 * V_29 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
int V_6 , V_21 ;
T_1 V_20 ;
if ( ! V_2 -> V_24 ) {
V_6 = - V_25 ;
goto error;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_11 , V_26 ) ;
for ( V_21 = 500 , V_20 = 0 ; V_21 && ! V_20 ; V_21 -- ) {
V_6 = F_8 ( V_2 , 0x47 , & V_20 , 0x02 ) ;
if ( V_6 )
goto error;
F_10 ( 10000 , 20000 ) ;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_4 , V_26 , V_21 ) ;
if ( V_21 == 0 ) {
V_6 = - V_27 ;
goto error;
}
V_6 = F_6 ( V_2 , 0x46 , & V_20 ) ;
if ( V_6 )
goto error;
V_48 -> V_45 = V_20 & 0x1f ;
if ( V_48 -> V_45 > sizeof( V_48 -> V_9 ) )
V_48 -> V_45 = sizeof( V_48 -> V_9 ) ;
V_23 . args [ 0 ] = V_49 ;
V_23 . args [ 1 ] = 0 ;
V_23 . V_5 = 2 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
V_6 = F_4 ( V_2 , V_23 . V_5 , V_48 -> V_9 , V_48 -> V_45 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_28 * V_29 ,
T_4 V_50 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
int V_6 , V_21 ;
T_1 V_20 , V_51 ;
if ( ! V_2 -> V_24 ) {
V_6 = - V_25 ;
goto error;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_12 , V_26 ,
V_50 ) ;
switch ( V_50 ) {
case V_52 :
V_51 = 0 ;
break;
case V_53 :
V_51 = 1 ;
break;
default:
F_11 ( & V_2 -> V_14 -> V_15 , L_13 ,
V_26 ) ;
V_6 = - V_35 ;
goto error;
}
for ( V_21 = 500 , V_20 = 0 ; V_21 && ! V_20 ; V_21 -- ) {
V_6 = F_8 ( V_2 , 0x47 , & V_20 , 0x01 ) ;
if ( V_6 )
goto error;
F_10 ( 10000 , 20000 ) ;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_4 , V_26 , V_21 ) ;
if ( V_21 == 0 ) {
V_6 = - V_27 ;
goto error;
}
V_6 = F_7 ( V_2 , 0x47 , 0x00 , 0x01 ) ;
if ( V_6 )
goto error;
V_23 . args [ 0 ] = V_54 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = V_51 ;
V_23 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_28 * V_29 , T_5 * V_55 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
int V_6 ;
T_1 V_20 ;
* V_55 = 0 ;
if ( ! V_2 -> V_24 ) {
V_6 = 0 ;
goto error;
}
V_6 = F_6 ( V_2 , 0x39 , & V_20 ) ;
if ( V_6 )
goto error;
if ( V_20 & 0x01 )
* V_55 |= V_56 ;
if ( V_20 & 0x02 )
* V_55 |= V_57 ;
if ( V_20 & 0x04 )
* V_55 |= V_58 ;
if ( V_20 & 0x08 )
* V_55 |= V_59 | V_60 ;
V_2 -> V_61 = * V_55 ;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_28 * V_29 , T_6 * V_62 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
if ( ! V_2 -> V_24 || ! ( V_2 -> V_61 & V_60 ) ) {
* V_62 = 0 ;
V_6 = 0 ;
goto error;
}
V_6 = F_4 ( V_2 , 0x3a , V_7 , 2 ) ;
if ( V_6 )
goto error;
* V_62 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_28 * V_29 , T_6 * V_63 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
int V_6 ;
T_1 V_20 ;
if ( ! V_2 -> V_24 || ! ( V_2 -> V_61 & V_60 ) ) {
* V_63 = 0 ;
V_6 = 0 ;
goto error;
}
V_23 . args [ 0 ] = V_64 ;
V_23 . args [ 1 ] = 0 ;
V_23 . V_5 = 2 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
V_6 = F_6 ( V_2 , 0x50 , & V_20 ) ;
if ( V_6 )
goto error;
if ( V_20 < 181 )
V_20 = 181 ;
else if ( V_20 > 236 )
V_20 = 236 ;
* V_63 = ( V_20 - 181 ) * 0xffff / ( 236 - 181 ) ;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_28 * V_29 , T_7 * V_65 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
int V_6 , V_21 , V_5 ;
T_1 V_20 , V_3 , V_7 [ 8 ] ;
if ( ! V_2 -> V_24 || ! ( V_2 -> V_61 & V_60 ) ) {
* V_65 = V_2 -> V_65 = 0 ;
V_6 = 0 ;
goto error;
}
switch ( V_2 -> V_66 ) {
case V_67 :
V_3 = 0x4c ;
V_5 = 8 ;
V_21 = 1 ;
break;
case V_68 :
V_3 = 0x4d ;
V_5 = 4 ;
V_21 = 0 ;
break;
default:
* V_65 = V_2 -> V_65 = 0 ;
return 0 ;
}
V_6 = F_6 ( V_2 , V_3 , & V_20 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_69 [ V_21 ] == V_20 ) {
F_11 ( & V_2 -> V_14 -> V_15 , L_14 , V_26 ,
V_20 ) ;
* V_65 = V_2 -> V_65 ;
return 0 ;
} else {
V_2 -> V_69 [ V_21 ] = V_20 ;
}
V_23 . args [ 0 ] = V_70 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = V_21 ;
V_23 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
V_6 = F_4 ( V_2 , V_23 . V_5 , V_7 , V_5 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_66 == V_67 ) {
* V_65 = ( V_7 [ 0 ] << 24 ) | ( V_7 [ 1 ] << 16 ) | ( V_7 [ 2 ] << 8 ) | V_7 [ 3 ] ;
V_2 -> V_71 += ( V_7 [ 4 ] << 8 ) | V_7 [ 5 ] ;
} else {
* V_65 = ( V_7 [ 0 ] << 8 ) | V_7 [ 1 ] ;
}
V_2 -> V_65 = * V_65 ;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_28 * V_29 , T_7 * V_72 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
int V_6 = 0 ;
if ( ! V_2 -> V_24 || ! ( V_2 -> V_61 & V_60 ) ) {
* V_72 = 0 ;
goto error;
}
* V_72 = V_2 -> V_71 ;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
struct V_73 * V_74 = & V_29 -> V_75 ;
int V_6 , V_21 ;
T_1 V_76 , V_77 , V_78 , V_79 , div ;
F_11 ( & V_2 -> V_14 -> V_15 , L_15 \
L_16 \
L_17 , V_26 , V_74 -> V_66 , V_74 -> V_80 ,
V_74 -> V_81 , V_74 -> V_82 , V_74 -> V_79 , V_74 -> V_78 ,
V_74 -> V_77 ) ;
V_2 -> V_66 = V_83 ;
if ( ! V_2 -> V_24 ) {
V_6 = - V_25 ;
goto error;
}
switch ( V_74 -> V_79 ) {
case V_84 :
V_79 = 1 ;
break;
case V_85 :
V_79 = 0 ;
break;
case V_86 :
V_79 = 3 ;
break;
default:
F_11 ( & V_2 -> V_14 -> V_15 , L_18 , V_26 ) ;
V_6 = - V_35 ;
goto error;
}
switch ( V_74 -> V_66 ) {
case V_67 :
V_77 = 0 ;
V_78 = 2 ;
break;
case V_68 :
switch ( V_74 -> V_77 ) {
case V_87 :
V_77 = 2 ;
break;
case V_88 :
V_77 = 1 ;
break;
case V_89 :
V_77 = 0 ;
break;
case V_90 :
default:
F_11 ( & V_2 -> V_14 -> V_15 , L_19 ,
V_26 ) ;
V_6 = - V_35 ;
goto error;
}
switch ( V_74 -> V_78 ) {
case V_91 :
V_78 = 0 ;
break;
case V_92 :
V_78 = 1 ;
break;
case V_93 :
V_78 = 2 ;
break;
default:
F_11 ( & V_2 -> V_14 -> V_15 , L_20 ,
V_26 ) ;
V_6 = - V_35 ;
goto error;
}
break;
default:
F_11 ( & V_2 -> V_14 -> V_15 , L_21 ,
V_26 ) ;
V_6 = - V_35 ;
goto error;
}
for ( V_21 = 0 , V_76 = 0xff ; V_21 < F_23 ( V_94 ) ; V_21 ++ ) {
if ( V_74 -> V_66 == V_94 [ V_21 ] . V_66 &&
V_74 -> V_80 == V_94 [ V_21 ] . V_80 &&
V_74 -> V_95 == V_94 [ V_21 ] . V_96 ) {
V_76 = V_94 [ V_21 ] . V_4 ;
F_11 ( & V_2 -> V_14 -> V_15 , L_22 ,
V_26 , V_76 ) ;
break;
}
}
if ( V_76 == 0xff ) {
F_11 ( & V_2 -> V_14 -> V_15 , L_23 ,
V_26 ) ;
V_6 = - V_35 ;
goto error;
}
if ( V_74 -> V_82 <= 5000000 )
div = 14 ;
else
div = 4 ;
V_6 = F_5 ( V_2 , 0x81 , div ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0xe3 , div ) ;
if ( V_6 )
goto error;
V_23 . args [ 0 ] = V_97 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = V_76 ;
V_23 . args [ 3 ] = ( V_74 -> V_81 >> 16 ) & 0xff ;
V_23 . args [ 4 ] = ( V_74 -> V_81 >> 8 ) & 0xff ;
V_23 . args [ 5 ] = ( V_74 -> V_81 >> 0 ) & 0xff ;
V_23 . args [ 6 ] = ( ( V_74 -> V_82 / 1000 ) >> 8 ) & 0xff ;
V_23 . args [ 7 ] = ( ( V_74 -> V_82 / 1000 ) >> 0 ) & 0xff ;
V_23 . args [ 8 ] = ( V_98 . V_99 . V_100 >> 8 ) & 0xff ;
V_23 . args [ 9 ] = ( V_98 . V_99 . V_100 >> 0 ) & 0xff ;
V_23 . args [ 10 ] = V_77 ;
V_23 . args [ 11 ] = V_79 ;
V_23 . args [ 12 ] = V_78 ;
V_23 . args [ 13 ] = 0x00 ;
V_23 . args [ 14 ] = 0x00 ;
V_23 . V_5 = 15 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
V_2 -> V_66 = V_74 -> V_66 ;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_73 * V_74 = & V_29 -> V_75 ;
int V_6 , V_21 ;
T_1 V_7 [ 5 ] , V_20 ;
if ( ! V_2 -> V_24 || ! ( V_2 -> V_61 & V_60 ) ) {
V_6 = - V_25 ;
goto error;
}
V_6 = F_4 ( V_2 , 0x30 , V_7 , 5 ) ;
if ( V_6 )
goto error;
V_20 = V_7 [ 0 ] & 0x3f ;
for ( V_21 = 0 ; V_21 < F_23 ( V_94 ) ; V_21 ++ ) {
if ( V_20 == V_94 [ V_21 ] . V_4 ) {
V_74 -> V_80 = V_94 [ V_21 ] . V_80 ;
V_74 -> V_95 = V_94 [ V_21 ] . V_96 ;
V_74 -> V_66 = V_94 [ V_21 ] . V_66 ;
}
}
switch ( ( V_7 [ 1 ] >> 0 ) & 0x01 ) {
case 0 :
V_74 -> V_79 = V_84 ;
break;
case 1 :
V_74 -> V_79 = V_85 ;
break;
}
switch ( ( V_7 [ 1 ] >> 7 ) & 0x01 ) {
case 0 :
V_74 -> V_78 = V_91 ;
break;
case 1 :
V_74 -> V_78 = V_92 ;
break;
}
V_74 -> V_81 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 3 ] << 8 ) | ( V_7 [ 4 ] << 0 ) ;
V_6 = F_4 ( V_2 , 0x52 , V_7 , 3 ) ;
if ( V_6 )
goto error;
V_74 -> V_82 = ( V_7 [ 0 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | ( V_7 [ 2 ] << 0 ) ;
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_25 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
int V_6 , V_21 , V_5 , V_101 , V_102 ;
const struct V_103 * V_104 ;
T_1 * V_105 = V_106 ;
T_1 V_20 , V_7 [ 4 ] ;
struct V_107 V_108 [] = {
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
struct V_107 V_109 [] = {
{ 0xf1 , 0x70 , 0xff } ,
{ 0x88 , V_2 -> V_11 . V_110 , 0x3f } ,
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
V_6 = F_6 ( V_2 , 0x51 , & V_20 ) ;
if ( V_6 )
goto error;
if ( ! V_20 ) {
V_2 -> V_24 = 1 ;
for ( V_21 = 0 ; V_21 < F_23 ( V_108 ) ; V_21 ++ ) {
V_6 = F_7 ( V_2 , V_108 [ V_21 ] . V_3 ,
V_108 [ V_21 ] . V_4 , V_108 [ V_21 ] . V_19 ) ;
if ( V_6 )
goto error;
}
V_23 . args [ 0 ] = V_111 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = 0 ;
V_23 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
} else {
V_2 -> V_24 = 0 ;
V_6 = F_26 ( & V_104 , V_105 , V_2 -> V_14 -> V_15 . V_112 ) ;
if ( V_6 ) {
F_27 ( & V_2 -> V_14 -> V_15 , L_24 \
L_25 \
L_26 \
L_27 ,
V_16 , V_105 , V_6 ) ;
goto error;
}
for ( V_21 = 0 ; V_21 < F_23 ( V_109 ) ; V_21 ++ ) {
V_6 = F_7 ( V_2 , V_109 [ V_21 ] . V_3 ,
V_109 [ V_21 ] . V_4 , V_109 [ V_21 ] . V_19 ) ;
if ( V_6 )
goto V_113;
}
V_6 = F_5 ( V_2 , 0xe0 , 0x7f ) ;
if ( V_6 )
goto V_113;
V_6 = F_5 ( V_2 , 0xf7 , 0x81 ) ;
if ( V_6 )
goto V_113;
V_6 = F_5 ( V_2 , 0xf8 , 0x00 ) ;
if ( V_6 )
goto V_113;
V_6 = F_5 ( V_2 , 0xf9 , 0x00 ) ;
if ( V_6 )
goto V_113;
F_28 ( & V_2 -> V_14 -> V_15 , L_28 \
L_29 , V_16 ,
V_98 . V_99 . V_114 ) ;
F_28 ( & V_2 -> V_14 -> V_15 , L_30 \
L_31 , V_16 , V_105 ) ;
V_102 = V_104 -> V_115 - 1 ;
for ( V_101 = V_102 ; V_101 > 0 ;
V_101 -= ( V_2 -> V_11 . V_116 - 1 ) ) {
V_5 = V_101 ;
if ( V_5 > ( V_2 -> V_11 . V_116 - 1 ) )
V_5 = ( V_2 -> V_11 . V_116 - 1 ) ;
V_6 = F_1 ( V_2 , 0xfa ,
( T_1 * ) & V_104 -> V_117 [ V_102 - V_101 ] , V_5 ) ;
if ( V_6 ) {
F_27 ( & V_2 -> V_14 -> V_15 , L_32 \
L_33 ,
V_16 , V_6 ) ;
if ( V_6 )
goto V_113;
}
}
F_29 ( V_104 ) ;
V_6 = F_5 ( V_2 , 0xf7 , 0x0c ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0xe0 , 0x00 ) ;
if ( V_6 )
goto error;
F_30 ( 250 ) ;
V_6 = F_6 ( V_2 , 0x51 , & V_20 ) ;
if ( V_6 )
goto error;
if ( V_20 ) {
F_28 ( & V_2 -> V_14 -> V_15 , L_34 ,
V_16 ) ;
V_6 = - V_25 ;
goto error;
} else {
V_2 -> V_24 = 1 ;
}
V_23 . args [ 0 ] = V_118 ;
V_23 . V_5 = 1 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
V_6 = F_4 ( V_2 , V_23 . V_5 , V_7 , 4 ) ;
if ( V_6 )
goto error;
F_28 ( & V_2 -> V_14 -> V_15 , L_35 ,
V_16 , V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ) ;
F_28 ( & V_2 -> V_14 -> V_15 , L_36 ,
V_16 , V_98 . V_99 . V_114 ) ;
V_6 = F_4 ( V_2 , 0x81 , V_7 , 2 ) ;
if ( V_6 )
goto error;
V_23 . args [ 0 ] = V_119 ;
V_23 . args [ 1 ] = ( ( V_2 -> V_11 . V_120 / 1000 ) >> 8 ) & 0xff ;
V_23 . args [ 2 ] = ( ( V_2 -> V_11 . V_120 / 1000 ) >> 0 ) & 0xff ;
V_23 . args [ 3 ] = V_7 [ 0 ] ;
V_23 . args [ 4 ] = V_7 [ 1 ] ;
V_23 . args [ 5 ] = V_2 -> V_11 . V_110 ;
V_23 . args [ 6 ] = V_2 -> V_11 . V_121 ;
V_23 . args [ 7 ] = 0x00 ;
V_23 . V_5 = 8 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
V_23 . args [ 0 ] = V_122 ;
V_23 . args [ 1 ] = 0x00 ;
V_23 . args [ 2 ] = 0x00 ;
V_23 . args [ 3 ] = 0x00 ;
V_23 . args [ 4 ] = 0x00 ;
V_23 . args [ 5 ] = 0x14 ;
V_23 . args [ 6 ] = 0x00 ;
V_23 . args [ 7 ] = 0x03 ;
V_23 . args [ 8 ] = 0x02 ;
V_23 . args [ 9 ] = 0x02 ;
V_23 . args [ 10 ] = 0x00 ;
V_23 . args [ 11 ] = 0x00 ;
V_23 . args [ 12 ] = 0x00 ;
V_23 . args [ 13 ] = 0x00 ;
V_23 . args [ 14 ] = 0x00 ;
V_23 . V_5 = 15 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
V_23 . args [ 0 ] = V_123 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = V_2 -> V_11 . V_124 ;
V_23 . args [ 3 ] = 0x00 ;
V_23 . args [ 4 ] = 0x04 ;
V_23 . args [ 5 ] = 0x00 ;
V_23 . V_5 = 6 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
V_6 = F_7 ( V_2 , 0xf0 , 0x01 , 0x01 ) ;
if ( V_6 )
goto error;
V_23 . args [ 0 ] = V_125 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = 150 ;
V_23 . args [ 3 ] = 3 ;
V_23 . args [ 4 ] = 22 ;
V_23 . args [ 5 ] = 1 ;
V_23 . args [ 6 ] = 1 ;
V_23 . args [ 7 ] = 30 ;
V_23 . args [ 8 ] = 30 ;
V_23 . args [ 9 ] = 30 ;
V_23 . args [ 10 ] = 30 ;
V_23 . V_5 = 11 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
V_23 . args [ 0 ] = V_126 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = 14 ;
V_23 . args [ 3 ] = 14 ;
V_23 . V_5 = 4 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
}
return V_6 ;
V_113:
F_29 ( V_104 ) ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_31 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
struct V_22 V_23 ;
int V_6 , V_21 ;
struct V_107 V_108 [] = {
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
if ( ! V_2 -> V_24 ) {
V_6 = - V_25 ;
goto error;
}
V_23 . args [ 0 ] = V_111 ;
V_23 . args [ 1 ] = 0 ;
V_23 . args [ 2 ] = 1 ;
V_23 . V_5 = 3 ;
V_6 = F_9 ( V_2 , & V_23 ) ;
if ( V_6 )
goto error;
for ( V_21 = 0 ; V_21 < F_23 ( V_108 ) ; V_21 ++ ) {
V_6 = F_7 ( V_2 , V_108 [ V_21 ] . V_3 , V_108 [ V_21 ] . V_4 ,
V_108 [ V_21 ] . V_19 ) ;
if ( V_6 )
goto error;
}
return V_6 ;
error:
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_32 ( struct V_28 * V_29 ,
struct V_127 * V_128 )
{
V_128 -> V_129 = 8000 ;
V_128 -> V_130 = 0 ;
V_128 -> V_131 = 0 ;
return 0 ;
}
static void F_33 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_31 ;
F_34 ( V_2 ) ;
}
struct V_28 * F_35 ( const struct V_132 * V_133 ,
struct V_134 * V_14 )
{
int V_6 ;
struct V_1 * V_2 = NULL ;
T_1 V_20 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_135 ) ;
if ( V_2 == NULL ) {
V_6 = - V_136 ;
goto error;
}
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_133 , sizeof( struct V_132 ) ) ;
V_6 = F_6 ( V_2 , 0xff , & V_20 ) ;
if ( V_6 || V_20 != 0x0f )
goto error;
V_6 = F_6 ( V_2 , 0xdd , & V_20 ) ;
if ( V_6 || V_20 != 0x00 )
goto error;
V_6 = F_6 ( V_2 , 0xfe , & V_20 ) ;
if ( V_6 || V_20 != 0x01 )
goto error;
memcpy ( & V_2 -> V_29 . V_137 , & V_98 , sizeof( struct V_138 ) ) ;
V_2 -> V_29 . V_31 = V_2 ;
return & V_2 -> V_29 ;
error:
F_11 ( & V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
F_34 ( V_2 ) ;
return NULL ;
}
