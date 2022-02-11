static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 ;
F_2 ( L_1 , V_3 , V_4 ) ;
if ( ( V_3 > 0 ) && ( V_3 < 8 ) ) {
V_5 = F_3 ( V_2 , 0x19 , & V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_6 &= ~ ( 1 << ( V_3 - 1 ) ) ;
V_6 |= ( V_4 << ( V_3 - 1 ) ) ;
V_5 = F_5 ( V_2 , 0x19 , V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
} else if ( V_3 <= 10 ) {
if ( V_3 == 0 )
V_3 += 7 ;
V_5 = F_3 ( V_2 , 0x30 , & V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_6 &= ~ ( 1 << ( V_3 - 3 ) ) ;
V_6 |= ( V_4 << ( V_3 - 3 ) ) ;
V_5 = F_5 ( V_2 , 0x30 , V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
} else
V_5 = - V_8 ;
V_7:
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
T_1 V_6 ;
F_7 ( L_2 , V_3 ) ;
* V_4 = 0 ;
switch ( V_3 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_5 = F_3 ( V_2 , 0x23 , & V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
* V_4 = ( V_6 >> ( V_3 + 4 ) ) & 0x01 ;
break;
case 4 :
case 5 :
case 6 :
case 7 :
V_5 = F_3 ( V_2 , 0x2f , & V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
* V_4 = ( V_6 >> V_3 ) & 0x01 ;
break;
case 8 :
case 9 :
case 10 :
V_5 = F_3 ( V_2 , 0x22 , & V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
* V_4 = ( V_6 >> ( V_3 - 3 ) ) & 0x01 ;
break;
default:
return - V_8 ;
}
V_7:
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
int V_5 ;
T_1 V_6 ;
F_2 ( L_1 , V_10 -> V_3 , V_10 -> V_11 ) ;
switch ( V_10 -> V_3 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_5 = F_3 ( V_2 , V_12 , & V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_6 &= ~ ( 1 << ( V_10 -> V_3 + 4 ) ) ;
V_6 |= ( V_10 -> V_11 << ( V_10 -> V_3 + 4 ) ) ;
V_5 = F_5 ( V_2 , V_12 , V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
break;
case 4 :
case 5 :
case 6 :
case 7 :
V_5 = F_3 ( V_2 , V_13 , & V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_6 &= ~ ( 1 << V_10 -> V_3 ) ;
V_6 |= ( V_10 -> V_11 << V_10 -> V_3 ) ;
V_5 = F_5 ( V_2 , V_13 , V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
break;
case 8 :
case 9 :
case 10 :
V_5 = F_3 ( V_2 , V_14 , & V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_6 &= ~ ( 1 << ( V_10 -> V_3 - 3 ) ) ;
V_6 |= ( V_10 -> V_11 << ( V_10 -> V_3 - 3 ) ) ;
V_5 = F_5 ( V_2 , V_14 , V_6 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
break;
default:
return - V_8 ;
}
V_5 = ( V_15 == V_10 -> V_11 ) ?
F_1 ( V_2 ,
V_10 -> V_3 , V_10 -> V_4 ) :
F_6 ( V_2 ,
V_10 -> V_3 , & V_10 -> V_4 ) ;
F_4 ( V_5 ) ;
V_7:
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_16 , int V_17 , int V_4 )
{
struct V_9 V_18 = {
. V_3 = V_16 ,
. V_11 = V_17 ,
. V_4 = V_4 ,
} ;
F_7 ( L_3 , V_16 , V_17 , V_4 ) ;
return F_8 ( V_2 , & V_18 ) ;
}
int F_10 ( struct V_1 * V_2 ,
enum V_19 V_20 )
{
T_1 V_21 , V_22 , V_23 , V_24 , V_25 , V_26 , V_27 , V_28 ;
int V_5 ;
F_7 ( L_4 , V_20 ) ;
V_5 = F_3 ( V_2 , 0x17 , & V_23 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_3 ( V_2 , 0x18 , & V_24 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_3 ( V_2 , 0x12 , & V_21 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_3 ( V_2 , 0x15 , & V_22 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_3 ( V_2 , 0x82 , & V_26 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_3 ( V_2 , 0x84 , & V_27 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_3 ( V_2 , 0x89 , & V_28 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_3 ( V_2 , 0x3D , & V_25 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
switch ( V_20 ) {
case V_29 :
V_23 |= V_30 ;
V_24 |= V_31 ;
V_24 &= ~ V_32 ;
V_25 &= ~ V_33 ;
V_21 &= ~ V_34 ;
V_22 &= ~ V_35 ;
V_25 &= ~ V_36 ;
V_26 |= V_37 ;
V_26 |= V_38 ;
V_26 |= V_39 ;
V_26 |= V_40 ;
V_27 |= 0xF0 ;
V_28 |= 0xF0 ;
break;
case V_41 :
V_23 |= V_30 ;
V_24 &= ~ V_31 ;
V_24 |= V_32 ;
V_25 &= ~ V_33 ;
V_21 &= ~ V_34 ;
V_22 &= ~ V_35 ;
V_25 &= ~ V_36 ;
V_26 |= V_37 ;
V_26 |= V_38 ;
V_26 |= V_39 ;
V_26 |= V_40 ;
V_27 |= 0xF0 ;
V_28 |= 0xF0 ;
break;
case V_42 :
V_23 &= ~ V_30 ;
V_24 &= ~ V_31 ;
V_24 &= ~ V_32 ;
V_25 &= ~ V_33 ;
V_21 &= ~ V_34 ;
V_22 &= ~ V_35 ;
V_25 &= ~ V_36 ;
V_26 &= ~ V_37 ;
V_26 &= ~ V_38 ;
V_26 &= ~ V_39 ;
V_26 &= ~ V_40 ;
V_27 &= 0x0F ;
V_28 &= 0x0F ;
break;
case V_43 :
V_23 &= ~ V_30 ;
V_24 &= ~ V_31 ;
V_24 |= V_32 ;
V_25 &= ~ V_33 ;
V_21 &= ~ V_34 ;
V_22 &= ~ V_35 ;
V_25 &= ~ V_36 ;
V_26 &= ~ V_37 ;
V_26 &= ~ V_38 ;
V_26 &= ~ V_39 ;
V_26 &= ~ V_40 ;
V_27 &= 0x0F ;
V_28 &= 0x0F ;
break;
case V_44 :
V_23 &= ~ V_30 ;
V_24 &= ~ V_31 ;
V_24 |= V_32 ;
V_25 |= V_33 ;
V_21 &= ~ V_34 ;
V_22 &= ~ V_35 ;
V_25 &= ~ V_36 ;
V_26 &= ~ V_37 ;
V_26 &= ~ V_38 ;
V_26 &= ~ V_39 ;
V_26 &= ~ V_40 ;
V_27 &= 0x0F ;
V_28 &= 0x0F ;
break;
case V_45 :
V_23 &= ~ V_30 ;
V_24 &= ~ V_31 ;
V_24 |= V_32 ;
V_25 |= V_33 ;
V_21 &= ~ V_34 ;
V_22 |= V_35 ;
V_25 |= V_36 ;
V_26 &= ~ V_37 ;
V_26 &= ~ V_38 ;
V_26 &= ~ V_39 ;
V_26 &= ~ V_40 ;
V_27 &= 0x0F ;
V_28 &= 0x0F ;
break;
case V_46 :
V_23 &= ~ V_30 ;
V_24 &= ~ V_31 ;
V_24 |= V_32 ;
V_25 &= ~ V_33 ;
V_21 &= ~ V_34 ;
V_22 |= V_35 ;
V_25 |= V_36 ;
V_26 &= ~ V_37 ;
V_26 &= ~ V_38 ;
V_26 &= ~ V_39 ;
V_26 &= ~ V_40 ;
V_27 &= 0x0F ;
V_28 &= 0x0F ;
break;
case V_47 :
V_23 &= ~ V_30 ;
V_24 |= V_31 ;
V_24 &= ~ V_32 ;
V_25 &= ~ V_33 ;
V_21 &= ~ V_34 ;
V_22 &= ~ V_35 ;
V_25 &= ~ V_36 ;
V_26 &= ~ V_37 ;
V_26 &= ~ V_38 ;
V_26 &= ~ V_39 ;
V_26 &= ~ V_40 ;
V_27 &= 0x0F ;
V_28 &= 0x0F ;
break;
case V_48 :
V_23 &= ~ V_30 ;
V_24 &= ~ V_31 ;
V_24 &= ~ V_32 ;
V_25 &= ~ V_33 ;
V_21 |= V_34 ;
V_22 |= V_35 ;
V_25 &= ~ V_36 ;
V_26 &= ~ V_37 ;
V_26 &= ~ V_38 ;
V_26 &= ~ V_39 ;
V_26 &= ~ V_40 ;
V_27 &= 0x0F ;
V_28 &= 0x0F ;
break;
case V_49 :
default:
V_23 |= V_30 ;
V_24 &= ~ V_31 ;
V_24 &= ~ V_32 ;
V_25 &= ~ V_33 ;
V_21 &= ~ V_34 ;
V_22 &= ~ V_35 ;
V_25 &= ~ V_36 ;
V_26 &= ~ V_37 ;
V_26 &= ~ V_38 ;
V_26 &= ~ V_39 ;
V_26 &= ~ V_40 ;
V_27 &= 0x0F ;
V_28 &= 0x0F ;
break;
}
V_5 = F_5 ( V_2 , 0x17 , V_23 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_5 ( V_2 , 0x18 , V_24 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_5 ( V_2 , 0x12 , V_21 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_5 ( V_2 , 0x15 , V_22 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_5 ( V_2 , 0x82 , V_26 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_5 ( V_2 , 0x84 , V_27 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_5 ( V_2 , 0x89 , V_28 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_5 = F_5 ( V_2 , 0x3D , V_25 ) ;
if ( F_4 ( V_5 ) )
goto V_7;
V_7:
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 , int V_16 , int V_4 )
{
return F_9 ( V_2 , V_16 , V_15 , V_4 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_50 = 0x07 ;
int V_51 , V_5 ;
F_7 ( L_5 ) ;
for ( V_51 = 3 ; V_51 < 8 ; V_51 ++ ) {
V_5 = F_11 ( V_2 , V_51 , ( V_50 >> V_51 ) & 0x01 ) ;
if ( F_4 ( V_5 ) )
break;
}
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 , int V_16 , int V_4 )
{
T_1 V_52 [ 2 ] = { 1 , 0 } ;
T_1 V_53 = 0 ;
struct V_54 V_55 [] = {
{ . V_56 = V_57 ,
. V_58 = 0 , . V_59 = V_52 , . V_60 = 1 } ,
{ . V_56 = V_57 ,
. V_58 = V_61 , . V_59 = & V_53 , . V_60 = 1 } ,
} ;
F_7 ( L_1 , V_16 , V_4 ) ;
F_14 ( & V_2 -> V_62 -> V_63 , V_55 , 2 ) ;
V_55 [ 0 ] . V_60 = 2 ;
#if 0
w[0] = 1;
#endif
V_52 [ 1 ] = V_53 ;
V_52 [ 1 ] &= ~ ( 1 << V_16 ) ;
V_52 [ 1 ] |= ( ( V_4 ? 1 : 0 ) << V_16 ) ;
F_14 ( & V_2 -> V_62 -> V_63 , & V_55 [ 0 ] , 1 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_52 [ 2 ] = { 1 , 0x07 } ;
struct V_54 V_55 = {
. V_56 = V_57 ,
. V_58 = 0 , . V_59 = V_52 , . V_60 = 2
} ;
F_7 ( L_5 ) ;
F_14 ( & V_2 -> V_62 -> V_63 , & V_55 , 1 ) ;
V_52 [ 0 ] = 3 ;
V_52 [ 1 ] = 0 ;
F_14 ( & V_2 -> V_62 -> V_63 , & V_55 , 1 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , int V_16 , int V_4 )
{
F_7 ( L_1 , V_16 , V_4 ) ;
switch ( V_2 -> V_64 ) {
default:
F_17 ( V_65 ,
L_6 ) ;
case V_66 :
return F_13 ( V_2 , V_16 , V_4 ) ;
case V_67 :
return F_11 ( V_2 , V_16 , V_4 ) ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_52 = 1 ;
T_1 V_53 = 0 ;
struct V_54 V_55 [] = {
{ . V_58 = 0 , . V_59 = & V_52 , . V_60 = 1 } ,
{ . V_58 = V_61 , . V_59 = & V_53 , . V_60 = 1 } ,
} ;
F_7 ( L_5 ) ;
V_55 [ 0 ] . V_56 = 0x70 >> 1 ;
V_55 [ 1 ] . V_56 = 0x70 >> 1 ;
V_5 = F_14 ( & V_2 -> V_62 -> V_63 , V_55 , 2 ) ;
if ( V_5 == 2 ) {
V_2 -> V_68 = V_55 [ 0 ] . V_56 ;
V_2 -> V_64 = V_66 ;
F_7 ( L_7 ,
V_2 -> V_68 ) ;
return 0 ;
}
V_55 [ 0 ] . V_56 = 0x40 >> 1 ;
V_55 [ 1 ] . V_56 = 0x40 >> 1 ;
V_5 = F_14 ( & V_2 -> V_62 -> V_63 , V_55 , 2 ) ;
if ( V_5 == 2 ) {
V_2 -> V_68 = V_55 [ 0 ] . V_56 ;
V_2 -> V_64 = V_66 ;
F_7 ( L_7 ,
V_2 -> V_68 ) ;
return 0 ;
}
V_2 -> V_68 = 0xff ;
V_2 -> V_64 = V_67 ;
F_7 ( L_8 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
F_7 ( L_5 ) ;
if ( 0x00 == V_2 -> V_68 )
F_18 ( V_2 ) ;
switch ( V_2 -> V_64 ) {
default:
F_17 ( V_65 ,
L_6 ) ;
case V_66 :
return F_15 ( V_2 ) ;
case V_67 :
return F_12 ( V_2 ) ;
}
}
int F_20 ( struct V_1 * V_2 , unsigned int V_69 )
{
F_7 ( L_4 , V_69 ) ;
switch ( V_69 ) {
case V_70 :
F_16 ( V_2 , 4 , 0 ) ;
F_16 ( V_2 , 5 , 0 ) ;
F_21 ( 50 ) ;
F_16 ( V_2 , 7 , 1 ) ;
F_21 ( 50 ) ;
F_16 ( V_2 , 6 , 1 ) ;
F_21 ( 50 ) ;
F_16 ( V_2 , 3 , 0 ) ;
break;
case V_71 :
F_16 ( V_2 , 6 , 0 ) ;
F_16 ( V_2 , 7 , 0 ) ;
F_21 ( 50 ) ;
F_16 ( V_2 , 5 , 1 ) ;
F_21 ( 50 ) ;
F_16 ( V_2 , 4 , 1 ) ;
F_21 ( 50 ) ;
F_16 ( V_2 , 3 , 1 ) ;
break;
default:
F_19 ( V_2 ) ;
break;
}
return 0 ;
}
