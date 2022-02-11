static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , int type , T_2 * V_5 , int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_2 V_10 [ 16 ] = { 0 } ;
T_2 V_11 [ 17 ] = { 0 } ;
T_2 V_12 ;
int V_13 ;
int V_14 ;
if ( V_6 < 1 ) {
F_2 ( L_1 ) ;
return - V_15 ;
}
if ( V_6 > 8 ) {
F_2 ( L_2 ) ;
return - V_15 ;
}
V_10 [ 0 ] = 14 ;
V_10 [ 1 ] = 0 ;
V_10 [ 2 ] = V_16 ;
V_10 [ 3 ] = 12 ;
V_10 [ 4 ] = V_8 -> V_17 ++ ;
V_10 [ 5 ] = ( T_2 ) ( V_3 >> 8 ) ;
V_10 [ 6 ] = ( T_2 ) ( V_3 & 0xff ) ;
if ( type == V_18 ) {
V_12 = V_19 ;
} else {
V_12 = V_20 ;
}
if ( V_6 > 1 )
V_12 |=
V_21 | V_22 | ( V_6 - 1 ) << 3 ;
V_12 |= V_4 ;
if ( V_4 == V_23 )
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ )
V_10 [ 8 + V_13 ] = V_5 [ V_13 ] ;
else if ( type == V_24 )
V_10 [ 8 ] = V_5 [ 0 ] ;
V_10 [ 7 ] = V_12 ;
V_14 = F_3 ( V_2 , V_10 , 16 , V_11 , 17 , 0 ) ;
if ( V_14 )
return V_14 ;
if ( V_11 [ 2 ] != V_25 ) {
F_2 ( L_3 ) ;
return - V_26 ;
}
if ( V_11 [ 3 ] != 0x0d ) {
F_2 ( L_4 ) ;
return - V_26 ;
}
if ( V_11 [ 4 ] != V_10 [ 4 ] ) {
F_2 ( L_5 ) ;
return - V_26 ;
}
if ( V_11 [ 16 ] != 0x01 ) {
F_2 ( L_6 ) ;
return - V_26 ;
}
if ( V_4 == V_27 )
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ )
V_5 [ V_13 ] = V_11 [ 8 + V_13 ] ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_28 )
{
int V_14 ;
F_5 ( L_7 , V_3 ) ;
V_14 = F_1 ( V_2 , V_3 ,
V_27 , V_18 ,
V_28 , 1 ) ;
if ( V_14 )
F_5 ( L_8 ) ;
else
F_5 ( L_9 , * V_28 ) ;
return V_14 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_5 , int V_6 )
{
int V_14 ;
F_5 ( L_10 , V_6 , V_3 ) ;
V_14 = F_1 ( V_2 , V_3 ,
V_27 , V_18 ,
V_5 , V_6 ) ;
if ( V_14 )
F_5 ( L_8 ) ;
else
F_7 ( V_5 , V_6 , F_5 ) ;
return V_14 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_28 )
{
int V_14 ;
T_2 V_29 = V_28 ;
F_5 ( L_11 , V_3 , V_28 ) ;
V_14 = F_1 ( V_2 , V_3 ,
V_23 , V_18 ,
& V_29 , 1 ) ;
if ( V_14 )
F_5 ( L_8 ) ;
else
F_5 ( L_12 ) ;
return V_14 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_5 , int V_6 )
{
int V_14 ;
F_5 ( L_13 , V_6 , V_3 ) ;
F_7 ( V_5 , V_6 , F_5 ) ;
V_14 = F_1 ( V_2 , V_3 ,
V_23 , V_18 ,
V_5 , V_6 ) ;
if ( V_14 )
F_5 ( L_8 ) ;
else
F_5 ( L_12 ) ;
return V_14 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_30 ,
T_2 V_6 , T_2 * V_28 )
{
T_2 V_29 ;
int V_14 ;
F_5 ( L_14 , V_3 , V_30 , V_6 ) ;
V_14 = F_4 ( V_2 , V_3 , & V_29 ) ;
if ( V_14 ) {
F_5 ( L_15 ) ;
return V_14 ;
}
* V_28 = ( V_29 >> V_30 ) & V_31 [ V_6 - 1 ] ;
F_5 ( L_16 , * V_28 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_30 ,
T_2 V_6 , T_2 V_28 )
{
T_2 V_29 , V_32 ;
int V_14 ;
F_5 ( L_17 , V_3 , V_30 , V_6 , V_28 ) ;
if ( V_30 == 0 && V_6 == 8 )
return F_8 ( V_2 , V_3 , V_28 ) ;
V_14 = F_4 ( V_2 , V_3 , & V_29 ) ;
if ( V_14 )
return V_14 ;
V_32 = V_31 [ V_6 - 1 ] << V_30 ;
V_29 = ( V_29 & ~ V_32 ) | ( ( V_28 << V_30 ) & V_32 ) ;
return F_8 ( V_2 , V_3 , V_29 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_5 , int V_6 )
{
return F_1 ( V_2 , V_3 ,
V_27 , V_24 ,
V_5 , V_6 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_5 , int V_6 )
{
return F_1 ( V_2 , V_3 ,
V_23 ,
V_24 , V_5 , V_6 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_5 , int V_6 )
{
int V_14 , V_13 , V_33 = 0 , V_34 = 0 ;
T_2 V_29 ;
V_14 = F_13 ( V_2 , V_3 , V_5 , V_6 ) ;
if ( V_14 )
return V_14 ;
if ( V_3 != 0xffff ) {
for ( V_13 = 0 ; V_13 < 200 ; V_13 ++ ) {
V_14 =
F_4 ( V_2 ,
V_35 ,
& V_29 ) ;
if ( V_14 )
return V_14 ;
V_33 = V_29 & ( V_31 [ V_36 - 1 ]
<< V_37 ) ;
if ( V_33 )
break;
V_34 = V_29 & ( V_31 [ V_38 - 1 ]
<< V_39 ) ;
if ( V_34 )
break;
F_15 ( 50 ) ;
}
if ( V_13 == 200 )
return - V_40 ;
if ( V_34 ) {
F_11 ( V_2 ,
V_41 ,
V_39 ,
V_38 ,
1 ) ;
return - V_26 ;
}
V_14 =
F_11 ( V_2 ,
V_41 ,
V_37 ,
V_36 , 1 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_42 ,
T_2 * V_5 , int V_6 )
{
int V_14 , V_13 ;
T_2 V_29 , V_43 [ 2 ] ;
V_43 [ 0 ] = V_42 ;
V_43 [ 1 ] = V_5 [ 0 ] ;
V_5 [ 0 ] = V_42 + 0x01 ;
if ( V_3 == V_44 ) {
V_14 = F_14 ( V_2 , 0x00c0 , V_43 , 2 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_12 ( V_2 , V_3 , V_5 , 1 ) ;
if ( V_14 )
return V_14 ;
for ( V_13 = 0 ; V_13 < 200 ; V_13 ++ ) {
V_14 = F_4 ( V_2 , 0xa408 , & V_29 ) ;
if ( V_14 )
return V_14 ;
if ( V_29 & 0x01 )
break;
F_15 ( 50 ) ;
}
if ( V_13 == 200 )
return - V_40 ;
V_14 = F_8 ( V_2 , V_45 , 1 ) ;
if ( V_14 )
return V_14 ;
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ ) {
V_14 = F_4 ( V_2 , 0xa400 + V_13 , & V_29 ) ;
if ( V_14 )
return V_14 ;
V_5 [ V_13 ] = V_29 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_46 , T_2 V_3 ,
T_2 * V_47 , int V_6 )
{
int V_14 , V_13 ;
T_2 V_43 [ 3 ] ;
F_18 ( L_18 , V_46 ,
V_3 , V_6 ) ;
F_7 ( V_47 , V_6 , F_18 ) ;
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ ) {
V_43 [ 0 ] = V_46 ;
V_43 [ 1 ] = V_3 + ( T_2 ) V_13 ;
V_43 [ 2 ] = V_47 [ V_13 ] ;
V_14 =
F_14 ( V_2 ,
V_44 ,
V_43 , 3 ) ;
if ( V_14 ) {
F_18 ( L_19 ) ;
return V_14 ;
}
}
F_18 ( L_20 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_46 , T_2 V_3 ,
T_2 * V_47 , int V_6 )
{
int V_14 , V_13 ;
T_2 V_29 ;
F_18 ( L_21 , V_46 , V_3 , V_6 ) ;
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ ) {
V_29 = V_3 + V_13 ;
V_14 =
F_16 ( V_2 ,
V_44 ,
V_46 , & V_29 , 1 ) ;
if ( V_14 ) {
F_18 ( L_22 ) ;
return V_14 ;
}
V_47 [ V_13 ] = V_29 ;
}
F_18 ( L_23 ) ;
F_7 ( V_47 , V_6 , F_18 ) ;
return 0 ;
}
static int F_20 ( struct V_48 * V_49 , struct V_50 V_51 [] ,
int V_52 )
{
struct V_1 * V_2 = F_21 ( V_49 ) ;
int V_14 ;
T_2 V_3 , V_42 ;
T_2 * V_28 ;
if ( F_22 ( & V_2 -> V_53 ) < 0 )
return - V_54 ;
if ( V_52 > 2 )
F_23 ( L_24 ) ;
if ( V_52 == 2 ) {
V_3 = * V_51 [ 0 ] . V_43 ;
V_42 = V_51 [ 0 ] . V_42 ;
V_28 = V_51 [ 1 ] . V_43 ;
V_14 = F_19 ( V_2 , V_42 , V_3 , V_28 , 1 ) ;
if ( V_14 == 0 )
V_14 = 2 ;
} else {
V_3 = V_51 [ 0 ] . V_43 [ 0 ] ;
V_42 = V_51 [ 0 ] . V_42 ;
V_28 = & V_51 [ 0 ] . V_43 [ 1 ] ;
V_14 = F_17 ( V_2 , V_42 , V_3 , V_28 , V_51 [ 0 ] . V_6 - 1 ) ;
if ( V_14 == 0 )
V_14 = 1 ;
}
F_24 ( & V_2 -> V_53 ) ;
return V_14 ;
}
static T_3 F_25 ( struct V_48 * V_55 )
{
return V_56 ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_12 , T_2 * V_57 ,
int V_58 , T_2 * V_59 , int V_60 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_14 , V_13 , V_61 ;
T_2 V_43 [ 64 ] ;
T_2 V_11 [ 64 ] ;
if ( V_58 < 0 ) {
F_2 ( L_25 ) ;
return - V_15 ;
}
if ( V_58 > 54 ) {
F_2 ( L_26 ) ;
return - V_15 ;
}
if ( V_60 > 54 ) {
F_2 ( L_27 ) ;
return - V_15 ;
}
V_61 = V_58 + 5 ;
V_43 [ 0 ] = ( T_2 ) ( V_61 & 0xff ) ;
V_43 [ 1 ] = ( T_2 ) ( ( V_61 & 0xff00 ) >> 8 ) ;
V_43 [ 2 ] = 0x26 ;
V_43 [ 3 ] = V_58 + 3 ;
V_43 [ 4 ] = V_8 -> V_17 ++ ;
V_43 [ 5 ] = V_12 ;
V_43 [ 6 ] = V_58 ;
for ( V_13 = 0 ; V_13 < V_58 ; V_13 ++ )
V_43 [ 7 + V_13 ] = V_57 [ V_13 ] ;
V_14 = F_3 ( V_2 , V_43 , V_58 + 7 , V_11 , V_60 + 7 , 0 ) ;
if ( V_14 )
return V_14 ;
if ( V_11 [ 2 ] != 0x27 ) {
F_2 ( L_28 ) ;
return - V_26 ;
}
if ( V_11 [ 4 ] != V_43 [ 4 ] ) {
F_2 ( L_29 ) ;
return - V_26 ;
}
if ( V_11 [ 5 ] != 0x01 ) {
F_2 ( L_30 ) ;
return - V_26 ;
}
if ( V_11 [ 6 ] != V_60 ) {
F_2 ( L_31 ) ;
return - V_26 ;
}
for ( V_13 = 0 ; V_13 < V_60 ; V_13 ++ )
V_59 [ V_13 ] = V_11 [ V_13 + 7 ] ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , T_2 V_62 , T_2 * V_5 ,
int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_2 V_10 [ 16 ] , V_11 [ 14 ] ;
int V_14 , V_13 ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
memset ( V_11 , 0 , sizeof( V_11 ) ) ;
V_10 [ 0 ] = 14 ;
V_10 [ 1 ] = 0 ;
V_10 [ 2 ] = 0x2a ;
V_10 [ 3 ] = 12 ;
V_10 [ 4 ] = V_8 -> V_17 ++ ;
V_10 [ 5 ] = 0 ;
V_10 [ 6 ] = V_6 ;
V_10 [ 7 ] = V_62 ;
V_14 = F_3 ( V_2 , V_10 , 16 , V_11 , 14 , 0 ) ;
if ( V_14 )
return V_14 ;
if ( V_11 [ 2 ] != 0x2b ) {
F_2 ( L_32 ) ;
return - V_26 ;
}
if ( V_11 [ 3 ] != 10 ) {
F_2 ( L_33 ) ;
return - V_26 ;
}
if ( V_11 [ 4 ] != V_10 [ 4 ] ) {
F_2 ( L_34 ) ;
return - V_26 ;
}
if ( V_11 [ 5 ] != 1 ) {
F_2 ( L_35 ) ;
return - V_26 ;
}
for ( V_13 = 0 ; V_13 < V_6 ; V_13 ++ ) {
V_5 [ V_13 ] = V_11 [ 6 + V_13 ] ;
}
return 0 ;
}
static int F_28 ( struct V_63 * V_64 , int type , T_2 * V_65 )
{
T_2 V_43 [ V_66 + 2 ] ;
T_1 V_67 ;
int V_68 , V_13 , V_14 ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
V_43 [ 0 ] = ( T_2 ) ( V_66 & 0xff ) ;
V_43 [ 1 ] = ( T_2 ) ( ( V_66 >> 8 ) & 0xff ) ;
switch ( type ) {
case V_69 :
V_43 [ 2 ] = 0x11 ;
V_43 [ 3 ] = 0x04 ;
V_43 [ 4 ] = 0x00 ;
V_43 [ 5 ] = 0x03 ;
V_67 = V_43 [ 4 ] + V_43 [ 5 ] ;
V_43 [ 6 ] = ( T_2 ) ( ( V_67 >> 8 ) & 0xff ) ;
V_43 [ 7 ] = ( T_2 ) ( V_67 & 0xff ) ;
break;
case V_70 :
V_43 [ 2 ] = 0x11 ;
V_43 [ 3 ] = 0x04 ;
V_43 [ 4 ] = 0x00 ;
V_43 [ 5 ] = 0x01 ;
V_67 = V_43 [ 4 ] + V_43 [ 5 ] ;
V_43 [ 6 ] = ( T_2 ) ( ( V_67 >> 8 ) & 0xff ) ;
V_43 [ 7 ] = ( T_2 ) ( V_67 & 0xff ) ;
break;
case V_71 :
V_43 [ 2 ] = 0x10 ;
V_43 [ 3 ] = 0x08 ;
V_43 [ 4 ] = 0x00 ;
V_43 [ 5 ] = 0x97 ;
V_43 [ 6 ] = 0xaa ;
V_43 [ 7 ] = 0x55 ;
V_43 [ 8 ] = 0xa5 ;
V_43 [ 9 ] = 0x5a ;
V_67 = 0 ;
for ( V_13 = 4 ; V_13 <= 9 ; V_13 ++ )
V_67 += V_43 [ V_13 ] ;
V_43 [ 10 ] = ( T_2 ) ( ( V_67 >> 8 ) & 0xff ) ;
V_43 [ 11 ] = ( T_2 ) ( V_67 & 0xff ) ;
break;
default:
F_2 ( L_36 ) ;
return - V_15 ;
}
F_29 ( L_37 ) ;
F_7 ( V_43 , V_66 + 2 , F_29 ) ;
V_14 = F_30 ( V_64 ,
F_31 ( V_64 , 0x02 ) ,
V_43 , V_66 + 2 , & V_68 , 2000 ) ;
if ( V_14 )
F_2 ( L_38 , V_14 ,
V_66 + 2 , V_68 ) ;
else
V_14 = V_68 != V_66 + 2 ? - 1 : 0 ;
if ( V_14 )
return V_14 ;
memset ( V_43 , 0 , 9 ) ;
V_14 = F_30 ( V_64 ,
F_32 ( V_64 , 0x01 ) , V_43 , 9 , & V_68 , 2000 ) ;
if ( V_14 ) {
F_2 ( L_39 , V_14 ) ;
return V_14 ;
}
F_29 ( L_40 ) ;
F_7 ( V_43 , V_68 , F_29 ) ;
V_67 = 0 ;
switch ( type ) {
case V_69 :
if ( V_43 [ 2 ] != 0x11 ) {
F_2 ( L_41 ) ;
return - V_26 ;
}
if ( V_43 [ 3 ] != 0x05 ) {
F_2 ( L_42 ) ;
return - V_26 ;
}
if ( V_43 [ 4 ] != 0x00 ) {
F_2 ( L_43 ) ;
return - V_26 ;
}
if ( V_43 [ 5 ] != 0x04 ) {
F_2 ( L_44 ) ;
return - V_26 ;
}
for ( V_13 = 4 ; V_13 <= 6 ; V_13 ++ )
V_67 += V_43 [ V_13 ] ;
if ( V_43 [ 7 ] * 256 + V_43 [ 8 ] != V_67 ) {
F_2 ( L_45 ) ;
return - V_26 ;
}
* V_65 = V_43 [ 6 ] ;
break;
case V_70 :
if ( V_43 [ 2 ] != 0x11 ) {
F_2 ( L_46 ) ;
return - V_26 ;
}
if ( V_43 [ 3 ] != 0x05 ) {
F_2 ( L_47 ) ;
return - V_26 ;
}
if ( V_43 [ 4 ] != 0x00 ) {
F_2 ( L_48 ) ;
return - V_26 ;
}
if ( V_43 [ 5 ] != 0x02 ) {
F_2 ( L_49 ) ;
return - V_26 ;
}
for ( V_13 = 4 ; V_13 <= 6 ; V_13 ++ )
V_67 += V_43 [ V_13 ] ;
if ( V_43 [ 7 ] * 256 + V_43 [ 8 ] != V_67 ) {
F_2 ( L_50 ) ;
return - V_26 ;
}
* V_65 = V_43 [ 6 ] ;
break;
case V_71 :
if ( V_43 [ 2 ] != 0x10 ) {
F_2 ( L_51 ) ;
return - V_26 ;
}
if ( V_43 [ 3 ] != 0x05 ) {
F_2 ( L_52 ) ;
return - V_26 ;
}
if ( V_43 [ 4 ] != 0x00 ) {
F_2 ( L_53 ) ;
return - V_26 ;
}
if ( V_43 [ 5 ] != 0x01 ) {
F_2 ( L_54 ) ;
return - V_26 ;
}
if ( V_43 [ 6 ] != 0x10 ) {
F_2 ( L_55 ) ;
return - V_26 ;
}
for ( V_13 = 4 ; V_13 <= 6 ; V_13 ++ )
V_67 += V_43 [ V_13 ] ;
if ( V_43 [ 7 ] * 256 + V_43 [ 8 ] != V_67 ) {
F_2 ( L_56 ) ;
return - V_26 ;
}
break;
}
return 0 ;
}
static int F_33 ( struct V_63 * V_64 , const struct V_72 * V_73 )
{
int V_13 , V_74 , V_14 , V_68 ;
T_2 V_43 [ V_66 + 2 ] ;
T_2 V_65 ;
V_14 = F_28 ( V_64 , V_69 , & V_65 ) ;
if ( V_14 )
return V_14 ;
if ( V_65 != 0x01 ) {
F_2 ( L_57 , V_65 ) ;
return - V_26 ;
}
V_74 = V_73 -> V_75 / V_66 ;
V_43 [ 0 ] = ( T_2 ) ( V_66 & 0xff ) ;
V_43 [ 1 ] = ( T_2 ) ( ( V_66 >> 8 ) & 0xff ) ;
for ( V_13 = 0 ; V_13 < V_74 ; V_13 ++ ) {
memcpy ( & V_43 [ 2 ] , V_73 -> V_47 + V_13 * V_66 ,
V_66 ) ;
F_29 ( L_37 ) ;
F_7 ( V_43 , V_66 + 2 , F_29 ) ;
V_14 = F_30 ( V_64 ,
F_31 ( V_64 , 0x02 ) ,
V_43 , V_66 + 2 , & V_68 , 1000 ) ;
if ( V_14 ) {
F_2 ( L_58 , V_13 , V_14 ) ;
return V_14 ;
}
}
V_14 = F_28 ( V_64 , V_70 , & V_65 ) ;
if ( V_14 )
return V_14 ;
if ( V_65 != ( T_2 ) ( V_74 & 0xff ) ) {
F_2 ( L_59 , V_74 & 0xff , V_65 ) ;
return - V_26 ;
}
V_14 = F_28 ( V_64 , V_71 , & V_65 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_28 ( V_64 , V_69 , & V_65 ) ;
if ( V_14 )
return V_14 ;
if ( V_65 != 0x02 ) {
F_2 ( L_60 , V_65 ) ;
return - V_26 ;
}
return 0 ;
}
int F_34 ( struct V_1 * V_2 , int V_76 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_29 , V_14 ;
if ( V_76 && V_77 )
V_29 = 1 ;
else
V_29 = 0 ;
if ( V_8 -> V_78 != V_29 ) {
V_14 =
F_11 ( V_2 , V_79 ,
V_80 ,
V_81 , V_29 ) ;
if ( V_14 )
return V_14 ;
V_14 =
F_11 ( V_2 , V_82 ,
V_83 ,
V_84 , V_29 ) ;
if ( V_14 )
return V_14 ;
V_8 -> V_78 = V_29 ;
}
return 0 ;
}
static int F_35 ( struct V_85 * V_49 )
{
T_2 V_43 [ 8 ] ;
int V_13 ;
struct V_63 * V_64 = V_49 -> V_86 -> V_64 ;
F_36 ( V_64 , F_31 ( V_64 , 2 ) ) ;
F_36 ( V_64 , F_32 ( V_64 , 1 ) ) ;
if ( V_87 ) {
F_37 ( L_61 ) ;
for ( V_13 = 0 ; V_13 < 255 ; V_13 += 8 ) {
F_27 ( V_49 -> V_86 , V_13 , V_43 , 8 ) ;
F_37 ( L_62 , V_13 ) ;
F_7 ( V_43 , 8 , F_37 ) ;
}
}
V_49 -> V_88 [ 0 ] . V_89 = F_38 ( V_49 -> V_86 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_3 * V_90 , int * V_91 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_14 , V_6 ;
T_2 V_10 [ 5 ] ;
T_2 V_11 [ 256 ] ;
* V_91 = V_92 ;
if ( V_93 == NULL ) {
return 0 ;
}
V_10 [ 0 ] = 3 ;
V_10 [ 1 ] = 0 ;
V_10 [ 2 ] = 0x40 ;
V_10 [ 3 ] = 1 ;
V_10 [ 4 ] = V_8 -> V_17 ++ ;
V_14 = F_3 ( V_2 , V_10 , 5 , V_11 , 256 , 0 ) ;
if ( V_14 ) {
F_2 ( L_63 ) ;
return V_14 ;
}
if ( V_11 [ 2 ] != 0x41 ) {
F_2 ( L_64 ) ;
return - V_26 ;
}
if ( V_11 [ 4 ] != V_10 [ 4 ] ) {
F_2 ( L_65 ) ;
return - V_26 ;
}
V_6 = V_11 [ 5 ] ;
if ( V_6 > 246 ) {
F_2 ( L_66 ) ;
return - V_26 ;
}
if ( V_6 > 0 ) {
F_40 ( L_67 , V_6 ) ;
F_7 ( ( V_11 + 6 ) , V_6 , F_40 ) ;
V_14 = V_93 ( V_2 , & V_11 [ 6 ] , V_6 , V_90 , V_91 ) ;
if ( V_14 ) {
F_2 ( L_68 ) ;
return V_14 ;
} else {
F_40 ( L_69 , * V_91 , * V_90 ) ;
if ( * V_91 == V_94 )
* V_90 = V_2 -> V_95 ;
}
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_76 )
{
return 0 ;
}
static int F_42 ( struct V_85 * V_49 , int V_76 )
{
int V_14 ;
F_43 ( L_70 , V_76 ) ;
if ( V_76 ) {
V_14 =
F_8 ( V_49 -> V_86 , V_96 , 1 ) ;
if ( V_14 )
return V_14 ;
V_14 =
F_11 ( V_49 -> V_86 ,
V_96 , 1 , 1 , 1 ) ;
if ( V_14 )
return V_14 ;
V_14 =
F_8 ( V_49 -> V_86 , V_96 , 1 ) ;
} else
V_14 =
F_8 ( V_49 -> V_86 , V_96 , 0 ) ;
if ( V_14 )
return V_14 ;
F_43 ( L_71 ) ;
return 0 ;
}
static int F_44 ( struct V_85 * V_49 , int V_97 ,
T_1 V_98 , int V_76 )
{
T_2 V_99 = V_97 & 0x1f ;
int V_14 ;
F_43 ( L_72 , V_97 ,
V_98 , V_76 ) ;
if ( V_76 ) {
if ( V_49 -> V_100 == 1 ) {
F_43 ( L_73 ) ;
V_14 = F_42 ( V_49 , V_76 ) ;
if ( V_14 )
return V_14 ;
}
V_14 =
F_8 ( V_49 -> V_86 ,
V_101 ,
( T_2 ) ( V_98 & 0xff ) ) ;
if ( V_14 )
return V_14 ;
V_14 =
F_8 ( V_49 -> V_86 ,
V_102 ,
( T_2 ) ( V_98 >> 8 ) ) ;
if ( V_14 )
return V_14 ;
V_99 |= 0x20 | 0x40 ;
} else {
if ( V_49 -> V_100 == 0 ) {
F_43 ( L_74 ) ;
V_14 = F_42 ( V_49 , V_76 ) ;
if ( V_14 )
return V_14 ;
}
}
V_14 = F_8 ( V_49 -> V_86 , V_103 , V_99 ) ;
if ( V_14 )
return V_14 ;
F_43 ( L_75 ) ;
return 0 ;
}
static int F_45 ( struct V_63 * V_64 ,
struct V_104 * V_105 ,
struct V_106 * * V_107 ,
int * V_108 )
{
int V_14 ;
T_2 V_65 ;
V_14 = F_28 ( V_64 , V_69 , & V_65 ) ;
if ( V_14 )
return V_14 ;
F_43 ( L_76 , V_65 ) ;
if ( V_65 == 0x01 )
* V_108 = 1 ;
else if ( V_65 == 0x02 )
* V_108 = 0 ;
else
return - V_26 ;
F_43 ( L_77 , * V_108 ) ;
return 0 ;
}
static int F_46 ( struct V_109 * V_110 ,
const struct V_111 * V_112 )
{
return F_47 ( V_110 , & V_113 ,
V_114 , NULL , V_115 ) ;
}
static int T_4 F_48 ( void )
{
int V_116 ;
if ( ( V_116 = F_49 ( & V_117 ) ) ) {
F_2 ( L_78 , V_116 ) ;
return V_116 ;
}
#if F_50 ( V_118 ) || F_51 ( V_119 )
V_93 = F_52 ( V_120 ) ;
V_121 = F_52 ( V_122 ) ;
V_123 = F_52 ( V_124 ) ;
#endif
if ( V_93 == NULL || V_121 == NULL || V_123 == NULL ) {
F_2 ( L_79 ) ;
V_113 . V_125 . V_126 . V_127 = NULL ;
} else {
V_113 . V_125 . V_126 . V_128 = V_121 ;
V_113 . V_125 . V_126 . V_129 = * V_123 ;
}
return 0 ;
}
static void T_5 F_53 ( void )
{
if ( V_93 != NULL )
F_54 ( V_120 ) ;
if ( V_121 != NULL )
F_54 ( V_122 ) ;
if ( V_123 != NULL )
F_54 ( V_124 ) ;
F_55 ( & V_117 ) ;
}
