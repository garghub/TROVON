static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
T_1 V_5 = 0 , V_6 = 0 ;
T_2 V_7 ;
V_7 = ( F_2 ( V_2 ) & V_8 ) >> V_9 ;
switch ( F_3 ( V_2 ) ) {
case V_10 :
case V_11 :
break;
case V_12 :
V_5 = F_4 ( V_13 ) |
F_4 ( V_14 ) |
F_4 ( V_15 ) |
F_4 ( V_16 ) ;
V_6 = 0xffff ;
break;
default:
break;
}
* V_3 = V_5 ;
* V_4 = V_6 ;
}
void F_5 ( struct V_1 * V_2 , T_3 V_17 )
{
T_1 V_18 = 0 ;
struct V_19 * V_20 ;
V_20 = F_6 ( V_2 , V_21 , 0 ) ;
switch ( F_3 ( V_2 ) ) {
case V_10 :
case V_11 :
if ( V_17 == 1 ) {
F_7 ( V_20 , F_8 ( V_22 ) ,
V_23 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x11500010 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_25 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x000C0C06 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_26 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x0F600a08 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_27 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x00000000 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_28 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x2001E920 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_29 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x88888815 ) ;
} else {
F_7 ( V_20 , F_8 ( V_22 ) ,
V_23 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x11100010 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_25 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x000c0c06 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_26 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x03000a08 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_27 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x00000000 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_28 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x200005c0 ) ;
F_7 ( V_20 , F_8 ( V_22 ) ,
V_29 ) ;
F_7 ( V_20 , F_8 ( V_24 ) ,
0x88888815 ) ;
}
V_18 = 1 << 10 ;
break;
default:
return;
}
F_9 ( V_20 , F_8 ( V_30 ) , V_18 ) ;
}
T_4 F_10 ( struct V_1 * V_2 )
{
T_2 V_31 = V_32 ;
switch ( F_3 ( V_2 ) ) {
case V_10 :
case V_11 :
case V_12 :
V_31 = 3700 ;
break;
default:
break;
}
return ( T_4 ) V_31 ;
}
T_1 F_11 ( struct V_1 * V_2 , T_2 V_33 , T_1 V_34 , T_1 V_35 )
{
F_12 ( V_2 , F_13 ( struct V_36 , V_37 ) , ~ 0 , V_33 ) ;
return F_12 ( V_2 , F_13 ( struct V_36 , V_38 ) ,
V_34 , V_35 ) ;
}
T_1 F_14 ( struct V_1 * V_2 , T_2 V_33 , T_1 V_34 , T_1 V_35 )
{
F_12 ( V_2 , F_13 ( struct V_36 , V_39 ) , ~ 0 , V_33 ) ;
return F_12 ( V_2 , F_13 ( struct V_36 , V_40 ) ,
V_34 , V_35 ) ;
}
T_1 F_15 ( struct V_1 * V_2 , T_2 V_33 , T_1 V_34 , T_1 V_35 )
{
F_12 ( V_2 , F_13 ( struct V_36 , V_22 ) , ~ 0 , V_33 ) ;
return F_12 ( V_2 , F_13 ( struct V_36 , V_24 ) ,
V_34 , V_35 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_12 ( V_2 , F_13 ( struct V_36 , V_30 ) ,
V_41 , V_41 ) ;
}
T_1 F_17 ( struct V_1 * V_2 )
{
T_1 clock = V_42 ;
if ( ! ( F_18 ( V_2 ) & V_43 ) )
return clock ;
switch ( F_3 ( V_2 ) ) {
case V_10 :
case V_11 :
case V_12 :
clock = 20000 * 1000 ;
break;
default:
break;
}
return clock ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
V_20 = F_6 ( V_2 , V_21 , 0 ) ;
if ( F_20 ( V_2 ) == 1 )
F_21 ( V_20 , F_8 ( V_30 ) ,
~ V_44 ) ;
else if ( F_20 ( V_2 ) >= 2 )
F_9 ( V_20 , F_8 ( V_30 ) , V_44 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
T_1 V_5 = 0 , V_6 = 0 ;
V_20 = F_6 ( V_2 , V_21 , 0 ) ;
F_1 ( V_2 , & V_5 , & V_6 ) ;
if ( V_6 )
F_7 ( V_20 , F_8 ( V_45 ) , V_6 ) ;
if ( V_5 )
F_7 ( V_20 , F_8 ( V_46 ) , V_5 ) ;
F_23 ( 2 ) ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
T_1 V_47 ;
if ( F_20 ( V_2 ) < 10 )
return 0 ;
V_20 = F_6 ( V_2 , V_21 , 0 ) ;
if ( F_25 ( V_20 , F_8 ( V_48 ) ) & V_49 ) {
T_1 V_50 , V_51 ;
F_7 ( V_20 , F_8 ( V_52 ) ,
1U << V_53 ) ;
F_26 ( 1000 ) ;
V_50 = F_25 ( V_20 , F_8 ( V_52 ) ) &
V_54 ;
F_7 ( V_20 , F_8 ( V_52 ) , 0 ) ;
V_51 = ( V_50 * V_55 ) / 4 ;
V_47 = ( V_51 + 50000 ) / 100000 * 100 ;
} else
V_47 = 0 ;
return V_47 ;
}
