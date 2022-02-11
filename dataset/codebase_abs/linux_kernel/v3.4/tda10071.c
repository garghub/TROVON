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
F_3 ( L_1 , V_6 , V_3 , V_5 ) ;
V_6 = - V_15 ;
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
. V_13 = V_16 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , V_7 , V_5 ) ;
V_6 = 0 ;
} else {
F_3 ( L_2 , V_6 , V_3 , V_5 ) ;
V_6 = - V_15 ;
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
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_17 )
{
int V_6 ;
T_1 V_18 ;
if ( V_17 != 0xff ) {
V_6 = F_4 ( V_2 , V_3 , & V_18 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_17 ;
V_18 &= ~ V_17 ;
V_4 |= V_18 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_17 )
{
int V_6 , V_19 ;
T_1 V_18 ;
V_6 = F_4 ( V_2 , V_3 , & V_18 , 1 ) ;
if ( V_6 )
return V_6 ;
V_18 &= V_17 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( ( V_17 >> V_19 ) & 0x01 )
break;
}
* V_4 = V_18 >> V_19 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_6 , V_19 ;
T_1 V_18 ;
if ( ! V_2 -> V_22 ) {
V_6 = - V_23 ;
goto error;
}
V_6 = F_1 ( V_2 , 0x00 , V_21 -> args , V_21 -> V_5 ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0x1f , 1 ) ;
if ( V_6 )
goto error;
for ( V_19 = 1000 , V_18 = 1 ; V_19 && V_18 ; V_19 -- ) {
V_6 = F_6 ( V_2 , 0x1f , & V_18 ) ;
if ( V_6 )
goto error;
F_10 ( 200 , 5000 ) ;
}
F_11 ( L_3 , V_24 , V_19 ) ;
if ( V_19 == 0 ) {
V_6 = - V_25 ;
goto error;
}
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_26 * V_27 ,
T_2 V_28 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
int V_6 ;
T_1 V_30 ;
if ( ! V_2 -> V_22 ) {
V_6 = - V_23 ;
goto error;
}
F_11 ( L_5 , V_24 , V_28 ) ;
switch ( V_28 ) {
case V_31 :
V_30 = 1 ;
break;
case V_32 :
V_30 = 0 ;
break;
default:
F_11 ( L_6 , V_24 ) ;
V_6 = - V_33 ;
goto error;
}
V_21 . args [ 0x00 ] = V_34 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = 0x00 ;
V_21 . args [ 0x03 ] = 0x00 ;
V_21 . args [ 0x04 ] = V_30 ;
V_21 . V_5 = 0x05 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_26 * V_27 ,
T_3 V_35 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
int V_6 ;
T_1 V_36 ;
if ( ! V_2 -> V_22 ) {
V_6 = - V_23 ;
goto error;
}
F_11 ( L_7 , V_24 , V_35 ) ;
switch ( V_35 ) {
case V_37 :
V_36 = 0 ;
break;
case V_38 :
V_36 = 1 ;
break;
case V_39 :
V_36 = 0 ;
break;
default:
F_11 ( L_8 , V_24 ) ;
V_6 = - V_33 ;
goto error;
} ;
V_21 . args [ 0x00 ] = V_40 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = V_36 ;
V_21 . V_5 = 0x03 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_26 * V_27 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
int V_6 , V_19 ;
T_1 V_18 ;
if ( ! V_2 -> V_22 ) {
V_6 = - V_23 ;
goto error;
}
F_11 ( L_9 , V_24 , V_42 -> V_43 ) ;
if ( V_42 -> V_43 < 3 || V_42 -> V_43 > 16 ) {
V_6 = - V_33 ;
goto error;
}
for ( V_19 = 500 , V_18 = 0 ; V_19 && ! V_18 ; V_19 -- ) {
V_6 = F_8 ( V_2 , 0x47 , & V_18 , 0x01 ) ;
if ( V_6 )
goto error;
F_10 ( 10000 , 20000 ) ;
}
F_11 ( L_3 , V_24 , V_19 ) ;
if ( V_19 == 0 ) {
V_6 = - V_25 ;
goto error;
}
V_6 = F_7 ( V_2 , 0x47 , 0x00 , 0x01 ) ;
if ( V_6 )
goto error;
V_21 . args [ 0x00 ] = V_44 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = 0 ;
V_21 . args [ 0x03 ] = 0 ;
V_21 . args [ 0x04 ] = 2 ;
V_21 . args [ 0x05 ] = 0 ;
V_21 . args [ 0x06 ] = V_42 -> V_43 ;
memcpy ( & V_21 . args [ 0x07 ] , V_42 -> V_9 , V_42 -> V_43 ) ;
V_21 . V_5 = 0x07 + V_42 -> V_43 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_26 * V_27 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
int V_6 , V_19 ;
T_1 V_18 ;
if ( ! V_2 -> V_22 ) {
V_6 = - V_23 ;
goto error;
}
F_11 ( L_10 , V_24 ) ;
for ( V_19 = 500 , V_18 = 0 ; V_19 && ! V_18 ; V_19 -- ) {
V_6 = F_8 ( V_2 , 0x47 , & V_18 , 0x02 ) ;
if ( V_6 )
goto error;
F_10 ( 10000 , 20000 ) ;
}
F_11 ( L_3 , V_24 , V_19 ) ;
if ( V_19 == 0 ) {
V_6 = - V_25 ;
goto error;
}
V_6 = F_6 ( V_2 , 0x46 , & V_18 ) ;
if ( V_6 )
goto error;
V_46 -> V_43 = V_18 & 0x1f ; ;
if ( V_46 -> V_43 > sizeof( V_46 -> V_9 ) )
V_46 -> V_43 = sizeof( V_46 -> V_9 ) ;
V_21 . args [ 0x00 ] = V_47 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . V_5 = 0x02 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
V_6 = F_4 ( V_2 , V_21 . V_5 , V_46 -> V_9 , V_46 -> V_43 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_26 * V_27 ,
T_4 V_48 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
int V_6 , V_19 ;
T_1 V_18 , V_49 ;
if ( ! V_2 -> V_22 ) {
V_6 = - V_23 ;
goto error;
}
F_11 ( L_11 , V_24 , V_48 ) ;
switch ( V_48 ) {
case V_50 :
V_49 = 0 ;
break;
case V_51 :
V_49 = 1 ;
break;
default:
F_11 ( L_12 , V_24 ) ;
V_6 = - V_33 ;
goto error;
}
for ( V_19 = 500 , V_18 = 0 ; V_19 && ! V_18 ; V_19 -- ) {
V_6 = F_8 ( V_2 , 0x47 , & V_18 , 0x01 ) ;
if ( V_6 )
goto error;
F_10 ( 10000 , 20000 ) ;
}
F_11 ( L_3 , V_24 , V_19 ) ;
if ( V_19 == 0 ) {
V_6 = - V_25 ;
goto error;
}
V_6 = F_7 ( V_2 , 0x47 , 0x00 , 0x01 ) ;
if ( V_6 )
goto error;
V_21 . args [ 0x00 ] = V_52 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = V_49 ;
V_21 . V_5 = 0x03 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_26 * V_27 , T_5 * V_53 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_6 ;
T_1 V_18 ;
* V_53 = 0 ;
if ( ! V_2 -> V_22 ) {
V_6 = 0 ;
goto error;
}
V_6 = F_6 ( V_2 , 0x39 , & V_18 ) ;
if ( V_6 )
goto error;
if ( V_18 & 0x01 )
* V_53 |= V_54 ;
if ( V_18 & 0x02 )
* V_53 |= V_55 ;
if ( V_18 & 0x04 )
* V_53 |= V_56 ;
if ( V_18 & 0x08 )
* V_53 |= V_57 | V_58 ;
V_2 -> V_59 = * V_53 ;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_26 * V_27 , T_6 * V_60 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_6 ;
T_1 V_7 [ 2 ] ;
if ( ! V_2 -> V_22 || ! ( V_2 -> V_59 & V_58 ) ) {
* V_60 = 0 ;
V_6 = 0 ;
goto error;
}
V_6 = F_4 ( V_2 , 0x3a , V_7 , 2 ) ;
if ( V_6 )
goto error;
* V_60 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_26 * V_27 , T_6 * V_61 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
int V_6 ;
T_1 V_18 ;
if ( ! V_2 -> V_22 || ! ( V_2 -> V_59 & V_58 ) ) {
* V_61 = 0 ;
V_6 = 0 ;
goto error;
}
V_21 . args [ 0x00 ] = V_62 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . V_5 = 0x02 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
V_6 = F_6 ( V_2 , 0x50 , & V_18 ) ;
if ( V_6 )
goto error;
if ( V_18 < 181 )
V_18 = 181 ;
else if ( V_18 > 236 )
V_18 = 236 ;
* V_61 = ( V_18 - 181 ) * 0xffff / ( 236 - 181 ) ;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_26 * V_27 , T_7 * V_63 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
int V_6 , V_19 , V_5 ;
T_1 V_18 , V_3 , V_7 [ 8 ] ;
if ( ! V_2 -> V_22 || ! ( V_2 -> V_59 & V_58 ) ) {
* V_63 = V_2 -> V_63 = 0 ;
V_6 = 0 ;
goto error;
}
switch ( V_2 -> V_64 ) {
case V_65 :
V_3 = 0x4c ;
V_5 = 8 ;
V_19 = 1 ;
break;
case V_66 :
V_3 = 0x4d ;
V_5 = 4 ;
V_19 = 0 ;
break;
default:
* V_63 = V_2 -> V_63 = 0 ;
return 0 ;
}
V_6 = F_6 ( V_2 , V_3 , & V_18 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_67 [ V_19 ] == V_18 ) {
F_11 ( L_13 , V_24 , V_18 ) ;
* V_63 = V_2 -> V_63 ;
return 0 ;
} else {
V_2 -> V_67 [ V_19 ] = V_18 ;
}
V_21 . args [ 0x00 ] = V_68 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = V_19 ;
V_21 . V_5 = 0x03 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
V_6 = F_4 ( V_2 , V_21 . V_5 , V_7 , V_5 ) ;
if ( V_6 )
goto error;
if ( V_2 -> V_64 == V_65 ) {
* V_63 = ( V_7 [ 0 ] << 24 ) | ( V_7 [ 1 ] << 16 ) | ( V_7 [ 2 ] << 8 ) | V_7 [ 3 ] ;
V_2 -> V_69 += ( V_7 [ 4 ] << 8 ) | V_7 [ 5 ] ;
} else {
* V_63 = ( V_7 [ 0 ] << 8 ) | V_7 [ 1 ] ;
}
V_2 -> V_63 = * V_63 ;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_26 * V_27 , T_7 * V_70 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_6 = 0 ;
if ( ! V_2 -> V_22 || ! ( V_2 -> V_59 & V_58 ) ) {
* V_70 = 0 ;
goto error;
}
* V_70 = V_2 -> V_69 ;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
struct V_71 * V_72 = & V_27 -> V_73 ;
int V_6 , V_19 ;
T_1 V_74 , V_75 , V_76 , V_77 , div ;
F_11 ( L_14 \
L_15 , V_24 ,
V_72 -> V_64 , V_72 -> V_78 , V_72 -> V_79 ,
V_72 -> V_80 , V_72 -> V_77 , V_72 -> V_76 , V_72 -> V_75 ) ;
V_2 -> V_64 = V_81 ;
if ( ! V_2 -> V_22 ) {
V_6 = - V_23 ;
goto error;
}
switch ( V_72 -> V_77 ) {
case V_82 :
V_77 = 1 ;
break;
case V_83 :
V_77 = 0 ;
break;
case V_84 :
V_77 = 3 ;
break;
default:
F_11 ( L_16 , V_24 ) ;
V_6 = - V_33 ;
goto error;
}
switch ( V_72 -> V_64 ) {
case V_65 :
V_75 = 0 ;
V_76 = 2 ;
break;
case V_66 :
switch ( V_72 -> V_75 ) {
case V_85 :
V_75 = 2 ;
break;
case V_86 :
V_75 = 1 ;
break;
case V_87 :
V_75 = 0 ;
break;
case V_88 :
default:
F_11 ( L_17 , V_24 ) ;
V_6 = - V_33 ;
goto error;
}
switch ( V_72 -> V_76 ) {
case V_89 :
V_76 = 0 ;
break;
case V_90 :
V_76 = 1 ;
break;
case V_91 :
V_76 = 2 ;
break;
default:
F_11 ( L_18 , V_24 ) ;
V_6 = - V_33 ;
goto error;
}
break;
default:
F_11 ( L_19 , V_24 ) ;
V_6 = - V_33 ;
goto error;
}
for ( V_19 = 0 , V_74 = 0xff ; V_19 < F_23 ( V_92 ) ; V_19 ++ ) {
if ( V_72 -> V_64 == V_92 [ V_19 ] . V_64 &&
V_72 -> V_78 == V_92 [ V_19 ] . V_78 &&
V_72 -> V_93 == V_92 [ V_19 ] . V_94 ) {
V_74 = V_92 [ V_19 ] . V_4 ;
F_11 ( L_20 , V_24 , V_74 ) ;
break;
}
}
if ( V_74 == 0xff ) {
F_11 ( L_21 , V_24 ) ;
V_6 = - V_33 ;
goto error;
}
if ( V_72 -> V_80 <= 5000000 )
div = 14 ;
else
div = 4 ;
V_6 = F_5 ( V_2 , 0x81 , div ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0xe3 , div ) ;
if ( V_6 )
goto error;
V_21 . args [ 0x00 ] = V_95 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = V_74 ;
V_21 . args [ 0x03 ] = ( V_72 -> V_79 >> 16 ) & 0xff ;
V_21 . args [ 0x04 ] = ( V_72 -> V_79 >> 8 ) & 0xff ;
V_21 . args [ 0x05 ] = ( V_72 -> V_79 >> 0 ) & 0xff ;
V_21 . args [ 0x06 ] = ( ( V_72 -> V_80 / 1000 ) >> 8 ) & 0xff ;
V_21 . args [ 0x07 ] = ( ( V_72 -> V_80 / 1000 ) >> 0 ) & 0xff ;
V_21 . args [ 0x08 ] = ( V_96 . V_97 . V_98 >> 8 ) & 0xff ;
V_21 . args [ 0x09 ] = ( V_96 . V_97 . V_98 >> 0 ) & 0xff ;
V_21 . args [ 0x0a ] = V_75 ;
V_21 . args [ 0x0b ] = V_77 ;
V_21 . args [ 0x0c ] = V_76 ;
V_21 . args [ 0x0d ] = 0x00 ;
V_21 . args [ 0x0e ] = 0x00 ;
V_21 . V_5 = 0x0f ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
V_2 -> V_64 = V_72 -> V_64 ;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_71 * V_72 = & V_27 -> V_73 ;
int V_6 , V_19 ;
T_1 V_7 [ 5 ] , V_18 ;
if ( ! V_2 -> V_22 || ! ( V_2 -> V_59 & V_58 ) ) {
V_6 = - V_23 ;
goto error;
}
V_6 = F_4 ( V_2 , 0x30 , V_7 , 5 ) ;
if ( V_6 )
goto error;
V_18 = V_7 [ 0 ] & 0x3f ;
for ( V_19 = 0 ; V_19 < F_23 ( V_92 ) ; V_19 ++ ) {
if ( V_18 == V_92 [ V_19 ] . V_4 ) {
V_72 -> V_78 = V_92 [ V_19 ] . V_78 ;
V_72 -> V_93 = V_92 [ V_19 ] . V_94 ;
V_72 -> V_64 = V_92 [ V_19 ] . V_64 ;
}
}
switch ( ( V_7 [ 1 ] >> 0 ) & 0x01 ) {
case 0 :
V_72 -> V_77 = V_82 ;
break;
case 1 :
V_72 -> V_77 = V_83 ;
break;
}
switch ( ( V_7 [ 1 ] >> 7 ) & 0x01 ) {
case 0 :
V_72 -> V_76 = V_89 ;
break;
case 1 :
V_72 -> V_76 = V_90 ;
break;
}
V_72 -> V_79 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 3 ] << 8 ) | ( V_7 [ 4 ] << 0 ) ;
V_6 = F_4 ( V_2 , 0x52 , V_7 , 3 ) ;
if ( V_6 )
goto error;
V_72 -> V_80 = ( V_7 [ 0 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | ( V_7 [ 2 ] << 0 ) ;
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_25 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
int V_6 , V_19 , V_5 , V_99 , V_100 ;
const struct V_101 * V_102 ;
T_1 * V_103 = V_104 ;
T_1 V_18 , V_7 [ 4 ] ;
struct V_105 V_106 [] = {
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
struct V_105 V_107 [] = {
{ 0xf1 , 0x70 , 0xff } ,
{ 0x88 , V_2 -> V_11 . V_108 , 0x3f } ,
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
V_6 = F_6 ( V_2 , 0x51 , & V_18 ) ;
if ( V_6 )
goto error;
if ( ! V_18 ) {
V_2 -> V_22 = 1 ;
for ( V_19 = 0 ; V_19 < F_23 ( V_106 ) ; V_19 ++ ) {
V_6 = F_7 ( V_2 , V_106 [ V_19 ] . V_3 ,
V_106 [ V_19 ] . V_4 , V_106 [ V_19 ] . V_17 ) ;
if ( V_6 )
goto error;
}
V_21 . args [ 0x00 ] = V_109 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = 0 ;
V_21 . V_5 = 0x03 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
} else {
V_2 -> V_22 = 0 ;
V_6 = F_26 ( & V_102 , V_103 , V_2 -> V_14 -> V_110 . V_111 ) ;
if ( V_6 ) {
F_27 ( L_22
L_23 \
L_24 ,
V_103 , V_6 ) ;
goto error;
}
for ( V_19 = 0 ; V_19 < F_23 ( V_107 ) ; V_19 ++ ) {
V_6 = F_7 ( V_2 , V_107 [ V_19 ] . V_3 ,
V_107 [ V_19 ] . V_4 , V_107 [ V_19 ] . V_17 ) ;
if ( V_6 )
goto V_112;
}
V_6 = F_5 ( V_2 , 0xe0 , 0x7f ) ;
if ( V_6 )
goto V_112;
V_6 = F_5 ( V_2 , 0xf7 , 0x81 ) ;
if ( V_6 )
goto V_112;
V_6 = F_5 ( V_2 , 0xf8 , 0x00 ) ;
if ( V_6 )
goto V_112;
V_6 = F_5 ( V_2 , 0xf9 , 0x00 ) ;
if ( V_6 )
goto V_112;
V_97 ( L_25 ,
V_96 . V_97 . V_113 ) ;
V_97 ( L_26 , V_103 ) ;
V_100 = V_102 -> V_114 - 1 ;
for ( V_99 = V_100 ; V_99 > 0 ;
V_99 -= ( V_2 -> V_11 . V_115 - 1 ) ) {
V_5 = V_99 ;
if ( V_5 > ( V_2 -> V_11 . V_115 - 1 ) )
V_5 = ( V_2 -> V_11 . V_115 - 1 ) ;
V_6 = F_1 ( V_2 , 0xfa ,
( T_1 * ) & V_102 -> V_116 [ V_100 - V_99 ] , V_5 ) ;
if ( V_6 ) {
F_27 ( L_27 , V_6 ) ;
if ( V_6 )
goto V_112;
}
}
F_28 ( V_102 ) ;
V_6 = F_5 ( V_2 , 0xf7 , 0x0c ) ;
if ( V_6 )
goto error;
V_6 = F_5 ( V_2 , 0xe0 , 0x00 ) ;
if ( V_6 )
goto error;
F_29 ( 250 ) ;
V_6 = F_6 ( V_2 , 0x51 , & V_18 ) ;
if ( V_6 )
goto error;
if ( V_18 ) {
V_97 ( L_28 ) ;
V_6 = - V_23 ;
goto error;
} else {
V_2 -> V_22 = 1 ;
}
V_21 . args [ 0x00 ] = V_117 ;
V_21 . V_5 = 0x01 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
V_6 = F_4 ( V_2 , V_21 . V_5 , V_7 , 4 ) ;
if ( V_6 )
goto error;
V_97 ( L_29 ,
V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ) ;
V_97 ( L_30 , V_96 . V_97 . V_113 ) ;
V_6 = F_4 ( V_2 , 0x81 , V_7 , 2 ) ;
if ( V_6 )
goto error;
V_21 . args [ 0x00 ] = V_118 ;
V_21 . args [ 0x01 ] = ( ( V_2 -> V_11 . V_119 / 1000 ) >> 8 ) & 0xff ;
V_21 . args [ 0x02 ] = ( ( V_2 -> V_11 . V_119 / 1000 ) >> 0 ) & 0xff ;
V_21 . args [ 0x03 ] = V_7 [ 0 ] ;
V_21 . args [ 0x04 ] = V_7 [ 1 ] ;
V_21 . args [ 0x05 ] = V_2 -> V_11 . V_108 ;
V_21 . args [ 0x06 ] = V_2 -> V_11 . V_120 ;
V_21 . args [ 0x07 ] = 0x00 ;
V_21 . V_5 = 0x08 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
V_21 . args [ 0x00 ] = V_121 ;
V_21 . args [ 0x01 ] = 0x00 ;
V_21 . args [ 0x02 ] = 0x00 ;
V_21 . args [ 0x03 ] = 0x00 ;
V_21 . args [ 0x04 ] = 0x00 ;
V_21 . args [ 0x05 ] = 0x14 ;
V_21 . args [ 0x06 ] = 0x00 ;
V_21 . args [ 0x07 ] = 0x03 ;
V_21 . args [ 0x08 ] = 0x02 ;
V_21 . args [ 0x09 ] = 0x02 ;
V_21 . args [ 0x0a ] = 0x00 ;
V_21 . args [ 0x0b ] = 0x00 ;
V_21 . args [ 0x0c ] = 0x00 ;
V_21 . args [ 0x0d ] = 0x00 ;
V_21 . args [ 0x0e ] = 0x00 ;
V_21 . V_5 = 0x0f ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
V_21 . args [ 0x00 ] = V_122 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = V_2 -> V_11 . V_123 ;
V_21 . args [ 0x03 ] = 0x00 ;
V_21 . args [ 0x04 ] = 0x04 ;
V_21 . args [ 0x05 ] = 0x00 ;
V_21 . V_5 = 0x06 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
V_6 = F_7 ( V_2 , 0xf0 , 0x01 , 0x01 ) ;
if ( V_6 )
goto error;
V_21 . args [ 0x00 ] = V_124 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = 150 ;
V_21 . args [ 0x03 ] = 3 ;
V_21 . args [ 0x04 ] = 22 ;
V_21 . args [ 0x05 ] = 1 ;
V_21 . args [ 0x06 ] = 1 ;
V_21 . args [ 0x07 ] = 30 ;
V_21 . args [ 0x08 ] = 30 ;
V_21 . args [ 0x09 ] = 30 ;
V_21 . args [ 0x0a ] = 30 ;
V_21 . V_5 = 0x0b ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
V_21 . args [ 0x00 ] = V_125 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = 14 ;
V_21 . args [ 0x03 ] = 14 ;
V_21 . V_5 = 0x04 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
}
return V_6 ;
V_112:
F_28 ( V_102 ) ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_30 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_20 V_21 ;
int V_6 , V_19 ;
struct V_105 V_106 [] = {
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
if ( ! V_2 -> V_22 ) {
V_6 = - V_23 ;
goto error;
}
V_21 . args [ 0x00 ] = V_109 ;
V_21 . args [ 0x01 ] = 0 ;
V_21 . args [ 0x02 ] = 1 ;
V_21 . V_5 = 0x03 ;
V_6 = F_9 ( V_2 , & V_21 ) ;
if ( V_6 )
goto error;
for ( V_19 = 0 ; V_19 < F_23 ( V_106 ) ; V_19 ++ ) {
V_6 = F_7 ( V_2 , V_106 [ V_19 ] . V_3 , V_106 [ V_19 ] . V_4 ,
V_106 [ V_19 ] . V_17 ) ;
if ( V_6 )
goto error;
}
return V_6 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_31 ( struct V_26 * V_27 ,
struct V_126 * V_127 )
{
V_127 -> V_128 = 8000 ;
V_127 -> V_129 = 0 ;
V_127 -> V_130 = 0 ;
return 0 ;
}
static void F_32 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
F_33 ( V_2 ) ;
}
struct V_26 * F_34 ( const struct V_131 * V_132 ,
struct V_133 * V_14 )
{
int V_6 ;
struct V_1 * V_2 = NULL ;
T_1 V_18 ;
V_2 = F_35 ( sizeof( struct V_1 ) , V_134 ) ;
if ( V_2 == NULL ) {
V_6 = - V_135 ;
goto error;
}
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_132 , sizeof( struct V_131 ) ) ;
V_6 = F_6 ( V_2 , 0xff , & V_18 ) ;
if ( V_6 || V_18 != 0x0f )
goto error;
V_6 = F_6 ( V_2 , 0xdd , & V_18 ) ;
if ( V_6 || V_18 != 0x00 )
goto error;
V_6 = F_6 ( V_2 , 0xfe , & V_18 ) ;
if ( V_6 || V_18 != 0x01 )
goto error;
memcpy ( & V_2 -> V_27 . V_136 , & V_96 , sizeof( struct V_137 ) ) ;
V_2 -> V_27 . V_29 = V_2 ;
return & V_2 -> V_27 ;
error:
F_11 ( L_4 , V_24 , V_6 ) ;
F_33 ( V_2 ) ;
return NULL ;
}
