static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 )
{
int V_5 ;
struct V_6 V_7 [] = {
{
. V_8 = 0x50 ,
. V_9 = 0 ,
. V_10 = V_3 ,
. V_11 = 1
} , {
. V_8 = 0x50 ,
. V_9 = V_12 ,
. V_10 = V_3 ,
. V_11 = V_4
} ,
} ;
V_5 = F_2 ( & V_2 -> V_13 , V_7 , 2 ) ;
if ( V_5 < 0 ) {
F_3 ( V_14 , V_15 , 1 ,
L_1 ,
V_5 , V_3 [ 0 ] , V_3 [ 1 ] ) ;
return V_5 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 )
{
int V_5 ;
struct V_6 V_7 = {
. V_8 = 0x50 ,
. V_9 = 0 ,
. V_10 = V_3 ,
. V_11 = V_4
} ;
V_5 = F_2 ( & V_2 -> V_13 , & V_7 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( V_14 , V_15 , 1 ,
L_2 ,
V_5 , V_4 , V_3 [ 0 ] , V_3 [ 1 ] ) ;
return V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_16 [ 0 ] = 0x08 ;
V_5 = F_1 ( V_2 , & V_2 -> V_16 [ 0 ] , 6 ) ;
if ( V_5 < 0 ) {
F_3 ( V_14 , V_15 , 1 , L_3 ) ;
return V_5 ;
}
F_3 ( V_14 , V_15 , 0 ,
L_4 , V_2 -> V_16 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_17 ) {
case V_18 :
V_2 -> V_19 = & V_20 ;
break;
case V_21 :
V_2 -> V_19 = & V_22 ;
break;
case V_23 :
case V_24 :
V_2 -> V_19 = & V_25 ;
break;
case V_26 :
V_2 -> V_19 = & V_27 ;
break;
case V_28 :
case V_29 :
case V_30 :
V_2 -> V_19 = & V_31 ;
break;
case V_32 :
V_2 -> V_19 = & V_33 ;
break;
default:
V_2 -> V_19 = & V_34 ;
break;
}
}
int F_7 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
F_6 ( V_2 ) ;
F_3 ( V_14 , V_15 , 0 , L_5 ,
V_2 -> V_19 -> V_35 , V_2 -> V_19 -> V_36 ,
V_2 -> V_37 -> V_38 -> V_39 , F_8 ( V_2 -> V_37 -> V_40 ) , F_9 ( V_2 -> V_37 -> V_40 ) ) ;
F_3 ( V_14 , V_15 , 0 , L_6 ,
V_2 -> V_41 ,
V_2 -> V_42 , V_2 -> V_17 ) ;
F_3 ( V_14 , V_15 , 0 ,
L_7 ,
V_2 -> V_37 -> V_43 , V_2 -> V_44 ,
V_2 -> V_45 , V_2 -> V_46 ) ;
V_5 = F_10 ( V_2 ) ;
if ( V_5 < 0 ) {
F_3 ( V_14 , V_15 , 1 , L_8 ) ;
return V_5 ;
}
V_5 = F_5 ( V_2 ) ;
if ( V_5 < 0 ) {
F_3 ( V_14 , V_15 , 1 , L_9 ) ;
return V_5 ;
}
V_5 = F_11 ( V_2 ) ;
if ( V_5 < 0 ) {
F_3 ( V_14 , V_15 , 1 , L_10 ) ;
return V_5 ;
}
V_5 = F_12 ( V_2 ) ;
if ( V_5 < 0 ) {
F_3 ( V_14 , V_47 , 1 , L_11 ) ;
return V_5 ;
}
V_5 = F_13 ( V_2 ) ;
if ( V_5 < 0 ) {
F_3 ( V_14 , V_47 , 1 , L_12 ) ;
return V_5 ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
F_3 ( V_14 , V_15 , 1 , L_13 ) ;
F_16 ( V_2 ) ;
F_3 ( V_14 , V_15 , 1 , L_14 ) ;
if ( F_17 ( V_2 ) < 0 )
F_3 ( V_14 , V_15 , 1 , L_15 ) ;
if ( F_18 ( V_2 ) < 0 )
F_3 ( V_14 , V_15 , 1 , L_16 ) ;
if ( F_19 ( V_2 ) < 0 )
F_3 ( V_14 , V_15 , 1 , L_17 ) ;
return 0 ;
}
void F_20 ( struct V_1 * V_2 , T_2 V_48 , T_1 V_49 )
{
T_2 V_50 ;
V_50 = F_21 ( V_51 ) ;
if ( V_49 )
V_2 -> V_52 = V_50 | ( 1 << V_48 ) ;
else
V_2 -> V_52 = V_50 & ( ~ ( 1 << V_48 ) ) ;
F_22 ( V_2 -> V_52 , V_51 ) ;
F_22 ( 0x00 , V_53 ) ;
F_23 ( 100 ) ;
}
void F_24 ( struct V_1 * V_2 , int V_54 )
{
T_2 V_55 ;
V_55 = F_21 ( 0x28 ) ;
F_3 ( V_14 , V_47 , 1 , L_18 ) ;
if ( V_54 == 0x01 ) {
V_55 |= 0x04 ;
F_22 ( V_55 , 0x28 ) ;
V_55 &= 0xff - 0x04 ;
F_22 ( V_55 , 0x28 ) ;
} else {
V_55 &= 0xff - 0x04 ;
F_22 ( V_55 , 0x28 ) ;
V_55 |= 0x04 ;
F_22 ( V_55 , 0x28 ) ;
}
}
