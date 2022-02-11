static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
T_1 V_5 = 0 , V_6 = 0 ;
T_2 V_7 ;
V_7 = ( V_2 -> V_8 & V_9 ) >> V_10 ;
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
break;
case V_14 :
V_5 = F_2 ( V_15 ) |
F_2 ( V_16 ) |
F_2 ( V_17 ) |
F_2 ( V_18 ) ;
V_6 = 0xffff ;
break;
default:
break;
}
* V_3 = V_5 ;
* V_4 = V_6 ;
}
static void
F_3 ( struct V_1 * V_2 , struct V_19 T_3 * V_20 ,
T_4 V_21 )
{
T_1 V_22 = 0 ;
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
if ( V_21 == 1 ) {
F_4 ( & V_20 -> V_23 , V_24 ) ;
F_4 ( & V_20 -> V_25 , 0x11500010 ) ;
F_4 ( & V_20 -> V_23 , V_26 ) ;
F_4 ( & V_20 -> V_25 , 0x000C0C06 ) ;
F_4 ( & V_20 -> V_23 , V_27 ) ;
F_4 ( & V_20 -> V_25 , 0x0F600a08 ) ;
F_4 ( & V_20 -> V_23 , V_28 ) ;
F_4 ( & V_20 -> V_25 , 0x00000000 ) ;
F_4 ( & V_20 -> V_23 , V_29 ) ;
F_4 ( & V_20 -> V_25 , 0x2001E920 ) ;
F_4 ( & V_20 -> V_23 , V_30 ) ;
F_4 ( & V_20 -> V_25 , 0x88888815 ) ;
} else {
F_4 ( & V_20 -> V_23 , V_24 ) ;
F_4 ( & V_20 -> V_25 , 0x11100010 ) ;
F_4 ( & V_20 -> V_23 , V_26 ) ;
F_4 ( & V_20 -> V_25 , 0x000c0c06 ) ;
F_4 ( & V_20 -> V_23 , V_27 ) ;
F_4 ( & V_20 -> V_25 , 0x03000a08 ) ;
F_4 ( & V_20 -> V_23 , V_28 ) ;
F_4 ( & V_20 -> V_25 , 0x00000000 ) ;
F_4 ( & V_20 -> V_23 , V_29 ) ;
F_4 ( & V_20 -> V_25 , 0x200005c0 ) ;
F_4 ( & V_20 -> V_23 , V_30 ) ;
F_4 ( & V_20 -> V_25 , 0x88888815 ) ;
}
V_22 = 1 << 10 ;
break;
F_4 ( & V_20 -> V_23 , V_24 ) ;
F_4 ( & V_20 -> V_25 , 0x11100008 ) ;
F_4 ( & V_20 -> V_23 , V_26 ) ;
F_4 ( & V_20 -> V_25 , 0x0c000c06 ) ;
F_4 ( & V_20 -> V_23 , V_27 ) ;
F_4 ( & V_20 -> V_25 , 0x03000a08 ) ;
F_4 ( & V_20 -> V_23 , V_28 ) ;
F_4 ( & V_20 -> V_25 , 0x00000000 ) ;
F_4 ( & V_20 -> V_23 , V_29 ) ;
F_4 ( & V_20 -> V_25 , 0x200005c0 ) ;
F_4 ( & V_20 -> V_23 , V_30 ) ;
F_4 ( & V_20 -> V_25 , 0x88888855 ) ;
V_22 = 1 << 10 ;
break;
default:
return;
}
V_22 |= F_5 ( & V_20 -> V_31 ) ;
F_4 ( & V_20 -> V_31 , V_22 ) ;
}
T_5 F_6 ( struct V_1 * V_2 )
{
T_2 V_32 = V_33 ;
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
V_32 = 3700 ;
break;
default:
break;
}
return ( T_5 ) V_32 ;
}
void F_7 ( struct V_1 * V_2 , bool V_34 )
{
struct V_19 T_3 * V_20 ;
T_2 V_35 ;
V_35 = F_8 ( V_2 ) ;
V_20 = F_9 ( V_2 , V_36 ) ;
F_9 ( V_2 , V_35 ) ;
}
T_1 F_10 ( struct V_1 * V_2 , T_2 V_37 , T_1 V_38 , T_1 V_39 )
{
F_11 ( V_2 , V_36 , F_12 ( struct V_19 , V_40 ) ,
~ 0 , V_37 ) ;
return F_11 ( V_2 , V_36 ,
F_12 ( struct V_19 , V_41 ) , V_38 ,
V_39 ) ;
}
T_1 F_13 ( struct V_1 * V_2 , T_2 V_37 , T_1 V_38 , T_1 V_39 )
{
F_11 ( V_2 , V_36 , F_12 ( struct V_19 , V_42 ) ,
~ 0 , V_37 ) ;
return F_11 ( V_2 , V_36 ,
F_12 ( struct V_19 , V_43 ) , V_38 ,
V_39 ) ;
}
T_1 F_14 ( struct V_1 * V_2 , T_2 V_37 , T_1 V_38 , T_1 V_39 )
{
F_11 ( V_2 , V_36 , F_12 ( struct V_19 , V_23 ) ,
~ 0 , V_37 ) ;
return F_11 ( V_2 , V_36 ,
F_12 ( struct V_19 , V_25 ) , V_38 ,
V_39 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_36 , F_12 ( struct V_19 , V_31 ) ,
V_44 , V_44 ) ;
}
T_1 F_16 ( struct V_1 * V_2 )
{
T_1 clock = V_45 ;
if ( ! ( V_2 -> V_46 & V_47 ) )
return clock ;
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
clock = 20000 * 1000 ;
break;
default:
break;
}
return clock ;
}
void F_17 ( struct V_1 * V_2 , T_4 V_21 )
{
struct V_19 T_3 * V_20 ;
T_2 V_35 , V_48 ;
V_20 = (struct V_19 T_3 * )
F_18 ( V_2 , V_49 , & V_35 , & V_48 ) ;
F_3 ( V_2 , V_20 , V_21 ) ;
F_19 ( V_2 , V_35 , V_48 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_19 T_3 * V_20 ;
T_2 V_35 ;
V_35 = F_8 ( V_2 ) ;
V_20 = F_9 ( V_2 , V_36 ) ;
if ( V_2 -> V_50 == 1 )
F_21 ( & V_20 -> V_31 , ~ V_51 ) ;
else if ( V_2 -> V_50 >= 2 )
F_22 ( & V_20 -> V_31 , V_51 ) ;
F_9 ( V_2 , V_35 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
T_2 V_35 ;
F_7 ( V_2 , false ) ;
V_35 = F_8 ( V_2 ) ;
F_9 ( V_2 , V_35 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
}
void F_25 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_19 T_3 * V_20 ;
T_2 V_35 ;
V_35 = F_8 ( V_2 ) ;
V_20 = F_9 ( V_2 , V_36 ) ;
switch ( V_2 -> V_11 ) {
case V_14 :
case V_12 :
case V_13 :
break;
default:
break;
}
F_9 ( V_2 , V_35 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_19 T_3 * V_20 ;
T_2 V_35 ;
T_1 V_5 = 0 , V_6 = 0 ;
V_35 = F_8 ( V_2 ) ;
V_20 = F_9 ( V_2 , V_36 ) ;
F_1 ( V_2 , & V_5 , & V_6 ) ;
if ( V_6 )
F_4 ( & V_20 -> V_53 , V_6 ) ;
if ( V_5 )
F_4 ( & V_20 -> V_54 , V_5 ) ;
F_27 ( 2 ) ;
F_9 ( V_2 , V_35 ) ;
}
T_1 F_28 ( struct V_1 * V_2 )
{
struct V_19 T_3 * V_20 ;
T_2 V_35 ;
T_1 V_55 ;
if ( V_2 -> V_50 < 10 )
return 0 ;
V_35 = F_8 ( V_2 ) ;
V_20 = F_9 ( V_2 , V_36 ) ;
if ( F_5 ( & V_20 -> V_56 ) & V_57 ) {
T_1 V_58 , V_59 ;
F_4 ( & V_20 -> V_60 ,
1U << V_61 ) ;
F_29 ( 1000 ) ;
V_58 =
F_5 ( & V_20 -> V_60 ) & V_62 ;
F_4 ( & V_20 -> V_60 , 0 ) ;
V_59 = ( V_58 * V_63 ) / 4 ;
V_55 = ( V_59 + 50000 ) / 100000 * 100 ;
} else
V_55 = 0 ;
F_9 ( V_2 , V_35 ) ;
return V_55 ;
}
