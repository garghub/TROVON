static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , int type , T_2 * V_5 , int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_2 V_10 , V_11 ;
int V_12 , V_13 ;
if ( V_6 < 1 ) {
F_2 ( L_1 ) ;
return - V_14 ;
}
if ( V_6 > 8 ) {
F_2 ( L_2 ) ;
return - V_14 ;
}
F_3 ( & V_2 -> V_15 ) ;
V_8 -> V_16 [ 0 ] = 14 ;
V_8 -> V_16 [ 1 ] = 0 ;
V_8 -> V_16 [ 2 ] = V_17 ;
V_8 -> V_16 [ 3 ] = 12 ;
V_8 -> V_16 [ 4 ] = V_11 = V_8 -> V_18 ++ ;
V_8 -> V_16 [ 5 ] = ( T_2 ) ( V_3 >> 8 ) ;
V_8 -> V_16 [ 6 ] = ( T_2 ) ( V_3 & 0xff ) ;
if ( type == V_19 ) {
V_10 = V_20 ;
} else {
V_10 = V_21 ;
}
if ( V_6 > 1 )
V_10 |=
V_22 | V_23 | ( V_6 - 1 ) << 3 ;
V_10 |= V_4 ;
if ( V_4 == V_24 )
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
V_8 -> V_16 [ 8 + V_12 ] = V_5 [ V_12 ] ;
else if ( type == V_25 )
V_8 -> V_16 [ 8 ] = V_5 [ 0 ] ;
V_8 -> V_16 [ 7 ] = V_10 ;
V_13 = F_4 ( V_2 , V_8 -> V_16 , 16 , V_8 -> V_16 , 17 , 0 ) ;
if ( V_13 )
goto V_13;
if ( V_8 -> V_16 [ 2 ] != V_26 ) {
F_2 ( L_3 ) ;
V_13 = - V_27 ;
goto V_13;
}
if ( V_8 -> V_16 [ 3 ] != 0x0d ) {
F_2 ( L_4 ) ;
V_13 = - V_27 ;
goto V_13;
}
if ( V_8 -> V_16 [ 4 ] != V_11 ) {
F_2 ( L_5 ) ;
V_13 = - V_27 ;
goto V_13;
}
if ( V_8 -> V_16 [ 16 ] != 0x01 ) {
F_2 ( L_6 ) ;
V_13 = - V_27 ;
goto V_13;
}
if ( V_4 == V_28 )
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
V_5 [ V_12 ] = V_8 -> V_16 [ 8 + V_12 ] ;
V_13:
F_5 ( & V_2 -> V_15 ) ;
return V_13 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_29 )
{
int V_13 ;
F_7 ( L_7 , V_3 ) ;
V_13 = F_1 ( V_2 , V_3 ,
V_28 , V_19 ,
V_29 , 1 ) ;
if ( V_13 )
F_7 ( L_8 ) ;
else
F_7 ( L_9 , * V_29 ) ;
return V_13 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_5 , int V_6 )
{
int V_13 ;
F_7 ( L_10 , V_6 , V_3 ) ;
V_13 = F_1 ( V_2 , V_3 ,
V_28 , V_19 ,
V_5 , V_6 ) ;
if ( V_13 )
F_7 ( L_8 ) ;
else
F_9 ( V_5 , V_6 , F_7 ) ;
return V_13 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_29 )
{
int V_13 ;
T_2 V_30 = V_29 ;
F_7 ( L_11 , V_3 , V_29 ) ;
V_13 = F_1 ( V_2 , V_3 ,
V_24 , V_19 ,
& V_30 , 1 ) ;
if ( V_13 )
F_7 ( L_8 ) ;
else
F_7 ( L_12 ) ;
return V_13 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_5 , int V_6 )
{
int V_13 ;
F_7 ( L_13 , V_6 , V_3 ) ;
F_9 ( V_5 , V_6 , F_7 ) ;
V_13 = F_1 ( V_2 , V_3 ,
V_24 , V_19 ,
V_5 , V_6 ) ;
if ( V_13 )
F_7 ( L_8 ) ;
else
F_7 ( L_12 ) ;
return V_13 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_31 ,
T_2 V_6 , T_2 * V_29 )
{
T_2 V_30 ;
int V_13 ;
F_7 ( L_14 , V_3 , V_31 , V_6 ) ;
V_13 = F_6 ( V_2 , V_3 , & V_30 ) ;
if ( V_13 ) {
F_7 ( L_15 ) ;
return V_13 ;
}
* V_29 = ( V_30 >> V_31 ) & V_32 [ V_6 - 1 ] ;
F_7 ( L_16 , * V_29 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_31 ,
T_2 V_6 , T_2 V_29 )
{
T_2 V_30 , V_33 ;
int V_13 ;
F_7 ( L_17 , V_3 , V_31 , V_6 , V_29 ) ;
if ( V_31 == 0 && V_6 == 8 )
return F_10 ( V_2 , V_3 , V_29 ) ;
V_13 = F_6 ( V_2 , V_3 , & V_30 ) ;
if ( V_13 )
return V_13 ;
V_33 = V_32 [ V_6 - 1 ] << V_31 ;
V_30 = ( V_30 & ~ V_33 ) | ( ( V_29 << V_31 ) & V_33 ) ;
return F_10 ( V_2 , V_3 , V_30 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_5 , int V_6 )
{
return F_1 ( V_2 , V_3 ,
V_28 , V_25 ,
V_5 , V_6 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_5 , int V_6 )
{
return F_1 ( V_2 , V_3 ,
V_24 ,
V_25 , V_5 , V_6 ) ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_5 , int V_6 )
{
int V_13 , V_12 , V_34 = 0 , V_35 = 0 ;
T_2 V_30 ;
V_13 = F_15 ( V_2 , V_3 , V_5 , V_6 ) ;
if ( V_13 )
return V_13 ;
if ( V_3 != 0xffff ) {
for ( V_12 = 0 ; V_12 < 200 ; V_12 ++ ) {
V_13 =
F_6 ( V_2 ,
V_36 ,
& V_30 ) ;
if ( V_13 )
return V_13 ;
V_34 = V_30 & ( V_32 [ V_37 - 1 ]
<< V_38 ) ;
if ( V_34 )
break;
V_35 = V_30 & ( V_32 [ V_39 - 1 ]
<< V_40 ) ;
if ( V_35 )
break;
F_17 ( 50 ) ;
}
if ( V_12 == 200 )
return - V_41 ;
if ( V_35 ) {
F_13 ( V_2 ,
V_42 ,
V_40 ,
V_39 ,
1 ) ;
return - V_27 ;
}
V_13 =
F_13 ( V_2 ,
V_42 ,
V_38 ,
V_37 , 1 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_43 ,
T_2 * V_5 , int V_6 )
{
int V_13 , V_12 ;
T_2 V_30 , V_44 [ 2 ] ;
V_44 [ 0 ] = V_43 ;
V_44 [ 1 ] = V_5 [ 0 ] ;
V_5 [ 0 ] = V_43 + 0x01 ;
if ( V_3 == V_45 ) {
V_13 = F_16 ( V_2 , 0x00c0 , V_44 , 2 ) ;
if ( V_13 )
return V_13 ;
}
V_13 = F_14 ( V_2 , V_3 , V_5 , 1 ) ;
if ( V_13 )
return V_13 ;
for ( V_12 = 0 ; V_12 < 200 ; V_12 ++ ) {
V_13 = F_6 ( V_2 , 0xa408 , & V_30 ) ;
if ( V_13 )
return V_13 ;
if ( V_30 & 0x01 )
break;
F_17 ( 50 ) ;
}
if ( V_12 == 200 )
return - V_41 ;
V_13 = F_10 ( V_2 , V_46 , 1 ) ;
if ( V_13 )
return V_13 ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ ) {
V_13 = F_6 ( V_2 , 0xa400 + V_12 , & V_30 ) ;
if ( V_13 )
return V_13 ;
V_5 [ V_12 ] = V_30 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_3 ,
T_2 * V_16 , int V_6 )
{
int V_13 , V_12 ;
T_2 V_44 [ 3 ] ;
F_20 ( L_18 , V_47 ,
V_3 , V_6 ) ;
F_9 ( V_16 , V_6 , F_20 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ ) {
V_44 [ 0 ] = V_47 ;
V_44 [ 1 ] = V_3 + ( T_2 ) V_12 ;
V_44 [ 2 ] = V_16 [ V_12 ] ;
V_13 =
F_16 ( V_2 ,
V_45 ,
V_44 , 3 ) ;
if ( V_13 ) {
F_20 ( L_19 ) ;
return V_13 ;
}
}
F_20 ( L_20 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_3 ,
T_2 * V_16 , int V_6 )
{
int V_13 , V_12 ;
T_2 V_30 ;
F_20 ( L_21 , V_47 , V_3 , V_6 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ ) {
V_30 = V_3 + V_12 ;
V_13 =
F_18 ( V_2 ,
V_45 ,
V_47 , & V_30 , 1 ) ;
if ( V_13 ) {
F_20 ( L_22 ) ;
return V_13 ;
}
V_16 [ V_12 ] = V_30 ;
}
F_20 ( L_23 ) ;
F_9 ( V_16 , V_6 , F_20 ) ;
return 0 ;
}
static int F_22 ( struct V_48 * V_49 , struct V_50 V_51 [] ,
int V_52 )
{
struct V_1 * V_2 = F_23 ( V_49 ) ;
int V_13 ;
T_2 V_3 , V_43 ;
T_2 * V_29 ;
if ( F_24 ( & V_2 -> V_53 ) < 0 )
return - V_54 ;
if ( V_52 > 2 )
F_25 ( L_24 ) ;
if ( V_52 == 2 ) {
V_3 = * V_51 [ 0 ] . V_44 ;
V_43 = V_51 [ 0 ] . V_43 ;
V_29 = V_51 [ 1 ] . V_44 ;
V_13 = F_21 ( V_2 , V_43 , V_3 , V_29 , 1 ) ;
if ( V_13 == 0 )
V_13 = 2 ;
} else {
V_3 = V_51 [ 0 ] . V_44 [ 0 ] ;
V_43 = V_51 [ 0 ] . V_43 ;
V_29 = & V_51 [ 0 ] . V_44 [ 1 ] ;
V_13 = F_19 ( V_2 , V_43 , V_3 , V_29 , V_51 [ 0 ] . V_6 - 1 ) ;
if ( V_13 == 0 )
V_13 = 1 ;
}
F_5 ( & V_2 -> V_53 ) ;
return V_13 ;
}
static T_3 F_26 ( struct V_48 * V_55 )
{
return V_56 ;
}
int F_27 ( struct V_1 * V_2 , T_2 V_10 , T_2 * V_57 ,
int V_58 , T_2 * V_59 , int V_60 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_13 , V_12 , V_61 ;
T_2 V_11 ;
if ( V_58 < 0 ) {
F_2 ( L_25 ) ;
return - V_14 ;
}
if ( V_58 > 54 ) {
F_2 ( L_26 ) ;
return - V_14 ;
}
if ( V_60 > 54 ) {
F_2 ( L_27 ) ;
return - V_14 ;
}
V_61 = V_58 + 5 ;
F_3 ( & V_2 -> V_15 ) ;
V_8 -> V_16 [ 0 ] = ( T_2 ) ( V_61 & 0xff ) ;
V_8 -> V_16 [ 1 ] = ( T_2 ) ( ( V_61 & 0xff00 ) >> 8 ) ;
V_8 -> V_16 [ 2 ] = 0x26 ;
V_8 -> V_16 [ 3 ] = V_58 + 3 ;
V_8 -> V_16 [ 4 ] = V_11 = V_8 -> V_18 ++ ;
V_8 -> V_16 [ 5 ] = V_10 ;
V_8 -> V_16 [ 6 ] = V_58 ;
for ( V_12 = 0 ; V_12 < V_58 ; V_12 ++ )
V_8 -> V_16 [ 7 + V_12 ] = V_57 [ V_12 ] ;
V_13 = F_4 ( V_2 , V_8 -> V_16 , V_58 + 7 , V_8 -> V_16 , V_60 + 7 , 0 ) ;
if ( V_8 -> V_16 [ 2 ] != 0x27 ) {
F_2 ( L_28 ) ;
V_13 = - V_27 ;
} else if ( V_8 -> V_16 [ 4 ] != V_11 ) {
F_2 ( L_29 ) ;
V_13 = - V_27 ;
} else if ( V_8 -> V_16 [ 5 ] != 0x01 ) {
F_2 ( L_30 ) ;
V_13 = - V_27 ;
} else if ( V_8 -> V_16 [ 6 ] != V_60 ) {
F_2 ( L_31 ) ;
V_13 = - V_27 ;
}
if ( ! V_13 ) {
for ( V_12 = 0 ; V_12 < V_60 ; V_12 ++ )
V_59 [ V_12 ] = V_8 -> V_16 [ V_12 + 7 ] ;
}
F_5 ( & V_2 -> V_15 ) ;
return V_13 ;
}
int F_28 ( struct V_1 * V_2 , T_2 V_62 , T_2 * V_5 ,
int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_2 V_11 ;
int V_13 , V_12 ;
F_3 ( & V_2 -> V_15 ) ;
memset ( V_8 -> V_16 , 0 , sizeof( V_8 -> V_16 ) ) ;
V_8 -> V_16 [ 0 ] = 14 ;
V_8 -> V_16 [ 1 ] = 0 ;
V_8 -> V_16 [ 2 ] = 0x2a ;
V_8 -> V_16 [ 3 ] = 12 ;
V_8 -> V_16 [ 4 ] = V_11 = V_8 -> V_18 ++ ;
V_8 -> V_16 [ 5 ] = 0 ;
V_8 -> V_16 [ 6 ] = V_6 ;
V_8 -> V_16 [ 7 ] = V_62 ;
V_13 = F_4 ( V_2 , V_8 -> V_16 , 16 , V_8 -> V_16 , 14 , 0 ) ;
if ( V_8 -> V_16 [ 2 ] != 0x2b ) {
F_2 ( L_32 ) ;
V_13 = - V_27 ;
} else if ( V_8 -> V_16 [ 3 ] != 10 ) {
F_2 ( L_33 ) ;
V_13 = - V_27 ;
} else if ( V_8 -> V_16 [ 4 ] != V_11 ) {
F_2 ( L_34 ) ;
V_13 = - V_27 ;
} else if ( V_8 -> V_16 [ 5 ] != 1 ) {
F_2 ( L_35 ) ;
V_13 = - V_27 ;
}
if ( ! V_13 ) {
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
V_5 [ V_12 ] = V_8 -> V_16 [ 6 + V_12 ] ;
}
F_5 ( & V_2 -> V_15 ) ;
return V_13 ;
}
static int F_29 ( struct V_63 * V_64 , int type , T_2 * V_65 ,
T_2 * V_44 , int V_66 )
{
T_1 V_67 ;
int V_68 , V_12 , V_13 ;
memset ( V_44 , 0 , V_66 ) ;
V_44 [ 0 ] = ( T_2 ) ( V_69 & 0xff ) ;
V_44 [ 1 ] = ( T_2 ) ( ( V_69 >> 8 ) & 0xff ) ;
switch ( type ) {
case V_70 :
V_44 [ 2 ] = 0x11 ;
V_44 [ 3 ] = 0x04 ;
V_44 [ 4 ] = 0x00 ;
V_44 [ 5 ] = 0x03 ;
V_67 = V_44 [ 4 ] + V_44 [ 5 ] ;
V_44 [ 6 ] = ( T_2 ) ( ( V_67 >> 8 ) & 0xff ) ;
V_44 [ 7 ] = ( T_2 ) ( V_67 & 0xff ) ;
break;
case V_71 :
V_44 [ 2 ] = 0x11 ;
V_44 [ 3 ] = 0x04 ;
V_44 [ 4 ] = 0x00 ;
V_44 [ 5 ] = 0x01 ;
V_67 = V_44 [ 4 ] + V_44 [ 5 ] ;
V_44 [ 6 ] = ( T_2 ) ( ( V_67 >> 8 ) & 0xff ) ;
V_44 [ 7 ] = ( T_2 ) ( V_67 & 0xff ) ;
break;
case V_72 :
V_44 [ 2 ] = 0x10 ;
V_44 [ 3 ] = 0x08 ;
V_44 [ 4 ] = 0x00 ;
V_44 [ 5 ] = 0x97 ;
V_44 [ 6 ] = 0xaa ;
V_44 [ 7 ] = 0x55 ;
V_44 [ 8 ] = 0xa5 ;
V_44 [ 9 ] = 0x5a ;
V_67 = 0 ;
for ( V_12 = 4 ; V_12 <= 9 ; V_12 ++ )
V_67 += V_44 [ V_12 ] ;
V_44 [ 10 ] = ( T_2 ) ( ( V_67 >> 8 ) & 0xff ) ;
V_44 [ 11 ] = ( T_2 ) ( V_67 & 0xff ) ;
break;
default:
F_2 ( L_36 ) ;
return - V_14 ;
}
F_30 ( L_37 ) ;
F_9 ( V_44 , V_69 + 2 , F_30 ) ;
V_13 = F_31 ( V_64 ,
F_32 ( V_64 , 0x02 ) ,
V_44 , V_69 + 2 , & V_68 , 2000 ) ;
if ( V_13 )
F_2 ( L_38 , V_13 ,
V_69 + 2 , V_68 ) ;
else
V_13 = V_68 != V_69 + 2 ? - 1 : 0 ;
if ( V_13 )
return V_13 ;
memset ( V_44 , 0 , 9 ) ;
V_13 = F_31 ( V_64 ,
F_33 ( V_64 , 0x01 ) , V_44 , 9 , & V_68 , 2000 ) ;
if ( V_13 ) {
F_2 ( L_39 , V_13 ) ;
return V_13 ;
}
F_30 ( L_40 ) ;
F_9 ( V_44 , V_68 , F_30 ) ;
V_67 = 0 ;
switch ( type ) {
case V_70 :
if ( V_44 [ 2 ] != 0x11 ) {
F_2 ( L_41 ) ;
return - V_27 ;
}
if ( V_44 [ 3 ] != 0x05 ) {
F_2 ( L_42 ) ;
return - V_27 ;
}
if ( V_44 [ 4 ] != 0x00 ) {
F_2 ( L_43 ) ;
return - V_27 ;
}
if ( V_44 [ 5 ] != 0x04 ) {
F_2 ( L_44 ) ;
return - V_27 ;
}
for ( V_12 = 4 ; V_12 <= 6 ; V_12 ++ )
V_67 += V_44 [ V_12 ] ;
if ( V_44 [ 7 ] * 256 + V_44 [ 8 ] != V_67 ) {
F_2 ( L_45 ) ;
return - V_27 ;
}
* V_65 = V_44 [ 6 ] ;
break;
case V_71 :
if ( V_44 [ 2 ] != 0x11 ) {
F_2 ( L_46 ) ;
return - V_27 ;
}
if ( V_44 [ 3 ] != 0x05 ) {
F_2 ( L_47 ) ;
return - V_27 ;
}
if ( V_44 [ 4 ] != 0x00 ) {
F_2 ( L_48 ) ;
return - V_27 ;
}
if ( V_44 [ 5 ] != 0x02 ) {
F_2 ( L_49 ) ;
return - V_27 ;
}
for ( V_12 = 4 ; V_12 <= 6 ; V_12 ++ )
V_67 += V_44 [ V_12 ] ;
if ( V_44 [ 7 ] * 256 + V_44 [ 8 ] != V_67 ) {
F_2 ( L_50 ) ;
return - V_27 ;
}
* V_65 = V_44 [ 6 ] ;
break;
case V_72 :
if ( V_44 [ 2 ] != 0x10 ) {
F_2 ( L_51 ) ;
return - V_27 ;
}
if ( V_44 [ 3 ] != 0x05 ) {
F_2 ( L_52 ) ;
return - V_27 ;
}
if ( V_44 [ 4 ] != 0x00 ) {
F_2 ( L_53 ) ;
return - V_27 ;
}
if ( V_44 [ 5 ] != 0x01 ) {
F_2 ( L_54 ) ;
return - V_27 ;
}
if ( V_44 [ 6 ] != 0x10 ) {
F_2 ( L_55 ) ;
return - V_27 ;
}
for ( V_12 = 4 ; V_12 <= 6 ; V_12 ++ )
V_67 += V_44 [ V_12 ] ;
if ( V_44 [ 7 ] * 256 + V_44 [ 8 ] != V_67 ) {
F_2 ( L_56 ) ;
return - V_27 ;
}
break;
}
return 0 ;
}
static int F_34 ( struct V_63 * V_64 , const struct V_73 * V_74 )
{
int V_12 , V_75 , V_13 , V_68 ;
T_2 * V_44 ;
T_2 V_65 ;
V_44 = F_35 ( V_69 + 2 , V_76 ) ;
if ( ! V_44 )
return - V_77 ;
V_13 = F_29 ( V_64 , V_70 , & V_65 , V_44 ,
V_69 + 2 ) ;
if ( V_13 )
goto F_2;
if ( V_65 != 0x01 ) {
F_2 ( L_57 , V_65 ) ;
V_13 = - V_27 ;
goto F_2;
}
V_75 = V_74 -> V_66 / V_69 ;
V_44 [ 0 ] = ( T_2 ) ( V_69 & 0xff ) ;
V_44 [ 1 ] = ( T_2 ) ( ( V_69 >> 8 ) & 0xff ) ;
for ( V_12 = 0 ; V_12 < V_75 ; V_12 ++ ) {
memcpy ( & V_44 [ 2 ] , V_74 -> V_16 + V_12 * V_69 ,
V_69 ) ;
F_30 ( L_37 ) ;
F_9 ( V_44 , V_69 + 2 , F_30 ) ;
V_13 = F_31 ( V_64 ,
F_32 ( V_64 , 0x02 ) ,
V_44 , V_69 + 2 , & V_68 , 1000 ) ;
if ( V_13 ) {
F_2 ( L_58 , V_12 , V_13 ) ;
goto F_2;
}
}
V_13 = F_29 ( V_64 , V_71 , & V_65 ,
V_44 , V_69 + 2 ) ;
if ( V_13 )
goto F_2;
if ( V_65 != ( T_2 ) ( V_75 & 0xff ) ) {
F_2 ( L_59 , V_75 & 0xff , V_65 ) ;
V_13 = - V_27 ;
goto F_2;
}
V_13 = F_29 ( V_64 , V_72 , & V_65 , V_44 ,
V_69 + 2 ) ;
if ( V_13 )
goto F_2;
V_13 = F_29 ( V_64 , V_70 , & V_65 , V_44 ,
V_69 + 2 ) ;
if ( V_13 )
goto F_2;
if ( V_65 != 0x02 ) {
F_2 ( L_60 , V_65 ) ;
V_13 = - V_27 ;
goto F_2;
}
F_2:
F_36 ( V_44 ) ;
return V_13 ;
}
int F_37 ( struct V_1 * V_2 , int V_78 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_30 , V_13 ;
if ( V_78 && V_79 )
V_30 = 1 ;
else
V_30 = 0 ;
if ( V_8 -> V_80 != V_30 ) {
V_13 =
F_13 ( V_2 , V_81 ,
V_82 ,
V_83 , V_30 ) ;
if ( V_13 )
return V_13 ;
V_13 =
F_13 ( V_2 , V_84 ,
V_85 ,
V_86 , V_30 ) ;
if ( V_13 )
return V_13 ;
V_8 -> V_80 = V_30 ;
}
return 0 ;
}
static int F_38 ( struct V_87 * V_49 )
{
T_2 V_44 [ 8 ] ;
int V_12 ;
struct V_63 * V_64 = V_49 -> V_88 -> V_64 ;
F_39 ( V_64 , F_32 ( V_64 , 2 ) ) ;
F_39 ( V_64 , F_33 ( V_64 , 1 ) ) ;
if ( V_89 ) {
F_40 ( L_61 ) ;
for ( V_12 = 0 ; V_12 < 255 ; V_12 += 8 ) {
F_28 ( V_49 -> V_88 , V_12 , V_44 , 8 ) ;
F_40 ( L_62 , V_12 ) ;
F_9 ( V_44 , 8 , F_40 ) ;
}
}
V_49 -> V_90 [ 0 ] . V_91 = F_41 ( V_49 -> V_88 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_3 * V_92 , int * V_93 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_13 , V_6 ;
T_2 V_11 ;
* V_93 = V_94 ;
if ( V_95 == NULL ) {
return 0 ;
}
F_3 ( & V_2 -> V_15 ) ;
V_8 -> V_16 [ 0 ] = 3 ;
V_8 -> V_16 [ 1 ] = 0 ;
V_8 -> V_16 [ 2 ] = 0x40 ;
V_8 -> V_16 [ 3 ] = 1 ;
V_8 -> V_16 [ 4 ] = V_11 = V_8 -> V_18 ++ ;
V_13 = F_4 ( V_2 , V_8 -> V_16 , 5 , V_8 -> V_16 , 256 , 0 ) ;
if ( V_13 ) {
F_2 ( L_63 ) ;
goto V_13;
}
if ( V_8 -> V_16 [ 2 ] != 0x41 ) {
F_2 ( L_64 ) ;
V_13 = - V_27 ;
goto V_13;
} else if ( V_8 -> V_16 [ 4 ] != V_11 ) {
F_2 ( L_65 ) ;
V_13 = - V_27 ;
goto V_13;
}
V_6 = V_8 -> V_16 [ 5 ] ;
if ( V_6 > 246 ) {
F_2 ( L_66 ) ;
V_13 = - V_27 ;
goto V_13;
}
if ( V_6 > 0 ) {
F_43 ( L_67 , V_6 ) ;
F_9 ( ( V_8 -> V_16 + 6 ) , V_6 , F_43 ) ;
V_13 = V_95 ( V_2 , & V_8 -> V_16 [ 6 ] , V_6 , V_92 , V_93 ) ;
if ( V_13 ) {
F_2 ( L_68 ) ;
goto V_13;
} else {
F_43 ( L_69 , * V_93 , * V_92 ) ;
if ( * V_93 == V_96 )
* V_92 = V_2 -> V_97 ;
}
}
V_13:
F_5 ( & V_2 -> V_15 ) ;
return V_13 ;
}
static int F_44 ( struct V_1 * V_2 , int V_78 )
{
return 0 ;
}
static int F_45 ( struct V_87 * V_49 , int V_78 )
{
int V_13 ;
F_46 ( L_70 , V_78 ) ;
if ( V_78 ) {
V_13 =
F_10 ( V_49 -> V_88 , V_98 , 1 ) ;
if ( V_13 )
return V_13 ;
V_13 =
F_13 ( V_49 -> V_88 ,
V_98 , 1 , 1 , 1 ) ;
if ( V_13 )
return V_13 ;
V_13 =
F_10 ( V_49 -> V_88 , V_98 , 1 ) ;
} else
V_13 =
F_10 ( V_49 -> V_88 , V_98 , 0 ) ;
if ( V_13 )
return V_13 ;
F_46 ( L_71 ) ;
return 0 ;
}
static int F_47 ( struct V_87 * V_49 , int V_99 ,
T_1 V_100 , int V_78 )
{
T_2 V_101 = V_99 & 0x1f ;
int V_13 ;
F_46 ( L_72 , V_99 ,
V_100 , V_78 ) ;
if ( V_78 ) {
if ( V_49 -> V_102 == 1 ) {
F_46 ( L_73 ) ;
V_13 = F_45 ( V_49 , V_78 ) ;
if ( V_13 )
return V_13 ;
}
V_13 =
F_10 ( V_49 -> V_88 ,
V_103 ,
( T_2 ) ( V_100 & 0xff ) ) ;
if ( V_13 )
return V_13 ;
V_13 =
F_10 ( V_49 -> V_88 ,
V_104 ,
( T_2 ) ( V_100 >> 8 ) ) ;
if ( V_13 )
return V_13 ;
V_101 |= 0x20 | 0x40 ;
} else {
if ( V_49 -> V_102 == 0 ) {
F_46 ( L_74 ) ;
V_13 = F_45 ( V_49 , V_78 ) ;
if ( V_13 )
return V_13 ;
}
}
V_13 = F_10 ( V_49 -> V_88 , V_105 , V_101 ) ;
if ( V_13 )
return V_13 ;
F_46 ( L_75 ) ;
return 0 ;
}
static int F_48 ( struct V_63 * V_64 ,
struct V_106 * V_107 ,
struct V_108 * * V_109 ,
int * V_110 )
{
int V_13 ;
T_2 V_65 , * V_44 ;
V_44 = F_35 ( V_69 + 2 , V_76 ) ;
if ( ! V_44 )
return - V_77 ;
V_13 = F_29 ( V_64 , V_70 , & V_65 ,
V_44 , V_69 + 2 ) ;
if ( V_13 )
goto F_2;
F_46 ( L_76 , V_65 ) ;
if ( V_65 == 0x01 )
* V_110 = 1 ;
else if ( V_65 == 0x02 )
* V_110 = 0 ;
else
return - V_27 ;
F_46 ( L_77 , * V_110 ) ;
F_2:
F_36 ( V_44 ) ;
return V_13 ;
}
static int F_49 ( struct V_111 * V_112 ,
const struct V_113 * V_114 )
{
return F_50 ( V_112 , & V_115 ,
V_116 , NULL , V_117 ) ;
}
static int T_4 F_51 ( void )
{
int V_118 ;
if ( ( V_118 = F_52 ( & V_119 ) ) ) {
F_2 ( L_78 , V_118 ) ;
return V_118 ;
}
#if F_53 ( V_120 ) || F_54 ( V_121 )
V_95 = F_55 ( V_122 ) ;
V_123 = F_55 ( V_124 ) ;
V_125 = F_55 ( V_126 ) ;
#endif
if ( V_95 == NULL || V_123 == NULL || V_125 == NULL ) {
F_2 ( L_79 ) ;
V_115 . V_127 . V_128 . V_129 = NULL ;
} else {
V_115 . V_127 . V_128 . V_130 = V_123 ;
V_115 . V_127 . V_128 . V_131 = * V_125 ;
}
return 0 ;
}
static void T_5 F_56 ( void )
{
if ( V_95 != NULL )
F_57 ( V_122 ) ;
if ( V_123 != NULL )
F_57 ( V_124 ) ;
if ( V_125 != NULL )
F_57 ( V_126 ) ;
F_58 ( & V_119 ) ;
}
