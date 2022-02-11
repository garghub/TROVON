static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_4 ) ;
return F_3 ( V_2 , V_5 ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_4 ) ;
F_2 ( V_2 , V_5 , V_6 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 ,
T_1 V_8 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_4 ) ;
F_6 ( V_2 , V_5 , V_7 , V_8 ) ;
}
void F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_7 , T_1 V_8 )
{
F_2 ( V_2 , V_9 , V_3 ) ;
F_3 ( V_2 , V_9 ) ;
F_6 ( V_2 , V_10 , V_7 , V_8 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 ,
T_1 V_8 )
{
F_2 ( V_2 , V_11 , V_3 ) ;
F_3 ( V_2 , V_11 ) ;
F_6 ( V_2 , V_12 , V_7 , V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_16 . V_17 ) {
case 0x4313 :
case 0x4331 :
case 43224 :
case 43225 :
break;
default:
F_10 ( L_1 ,
V_14 -> V_16 . V_17 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
T_1 V_18 = 0 , V_19 = 0 ;
switch ( V_14 -> V_16 . V_17 ) {
case 0x4313 :
V_18 = 0x200D ;
V_19 = 0xFFFF ;
break;
case 0x4331 :
case 43224 :
case 43225 :
break;
default:
F_10 ( L_2 ,
V_14 -> V_16 . V_17 ) ;
}
if ( V_18 )
F_2 ( V_2 , V_20 , V_18 ) ;
if ( V_19 )
F_2 ( V_2 , V_21 , V_19 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_16 . V_17 ) {
case 0x4313 :
case 0x4331 :
case 43224 :
case 43225 :
break;
default:
F_10 ( L_3
L_4 , V_14 -> V_16 . V_17 ) ;
}
}
void F_13 ( struct V_1 * V_2 , bool V_22 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
T_1 V_23 ;
V_23 = F_3 ( V_2 , V_24 ) ;
if ( V_22 ) {
V_23 |= V_25 ;
if ( V_14 -> V_16 . V_26 == 9 || V_14 -> V_16 . V_26 == 11 )
V_23 |= V_27 ;
} else {
V_23 &= ~ V_25 ;
V_23 &= ~ V_27 ;
}
F_2 ( V_2 , V_24 , V_23 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_16 . V_17 ) {
case 0x4313 :
F_7 ( V_2 , 0 , ~ 0 , 0x7 ) ;
break;
case 0x4331 :
break;
case 43224 :
if ( V_14 -> V_16 . V_28 == 0 ) {
F_10 ( L_5
L_6 ) ;
F_7 ( V_2 , 0 , ~ 0 , 0x00F000F0 ) ;
} else {
F_7 ( V_2 , 0 , ~ 0 , 0xF0 ) ;
}
break;
case 43225 :
break;
default:
F_10 ( L_7 ,
V_14 -> V_16 . V_17 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
T_1 V_29 ;
V_29 = F_3 ( V_2 , V_30 ) ;
V_2 -> V_31 . V_28 = ( V_29 & V_32 ) ;
F_16 ( L_8 , V_2 -> V_31 . V_28 ,
V_29 ) ;
if ( V_2 -> V_31 . V_28 == 1 )
F_17 ( V_2 , V_33 ,
~ V_34 ) ;
else
F_18 ( V_2 , V_33 ,
V_34 ) ;
if ( V_2 -> V_15 -> V_17 . V_17 == 0x4329 && V_2 -> V_15 -> V_17 . V_28 == 2 )
F_10 ( L_9 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
}
T_1 F_19 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_16 . V_17 ) {
case 0x4716 :
case 0x4748 :
case 47162 :
case 0x4313 :
case 0x5357 :
case 0x4749 :
case 53572 :
return 20000 * 1000 ;
case 0x5356 :
case 0x5300 :
return 25000 * 1000 ;
default:
F_20 ( L_10
L_11 ,
V_14 -> V_16 . V_17 , V_2 -> V_31 . V_28 , V_35 ) ;
}
return V_35 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_1 V_36 , T_1 V_37 )
{
T_1 V_38 , div , V_39 , V_40 , V_41 , V_42 ;
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
F_22 ( ( V_36 & 3 ) || ( V_36 > V_43 ) ) ;
F_22 ( ! V_37 || V_37 > 4 ) ;
if ( V_14 -> V_16 . V_17 == 0x5357 || V_14 -> V_16 . V_17 == 0x4749 ) {
V_38 = F_3 ( V_2 , V_44 ) ;
if ( V_38 & 0x40000 )
return 133 * 1000000 ;
}
V_38 = F_1 ( V_2 , V_36 + V_45 ) ;
V_40 = ( V_38 & V_46 ) >> V_47 ;
V_41 = ( V_38 & V_48 ) >> V_49 ;
V_38 = F_1 ( V_2 , V_36 + V_50 ) ;
div = ( V_38 >> ( ( V_37 - 1 ) * V_51 ) ) &
V_52 ;
V_38 = F_1 ( V_2 , V_36 + V_53 ) ;
V_39 = ( V_38 & V_54 ) >> V_55 ;
V_42 = F_19 ( V_2 ) / 1000000 ;
V_42 = ( V_40 * V_39 * V_42 ) / V_41 ;
return ( V_42 / div ) * 1000000 ;
}
T_1 F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
switch ( V_14 -> V_16 . V_17 ) {
case 0x4716 :
case 0x4748 :
case 47162 :
return F_21 ( V_2 , V_43 ,
V_56 ) ;
case 0x5356 :
return F_21 ( V_2 , V_57 ,
V_56 ) ;
case 0x5357 :
case 0x4749 :
return F_21 ( V_2 , V_58 ,
V_56 ) ;
case 0x5300 :
return F_21 ( V_2 , V_59 ,
V_56 ) ;
case 53572 :
return 75000000 ;
default:
F_20 ( L_12
L_11 ,
V_14 -> V_16 . V_17 , V_2 -> V_31 . V_28 , V_60 ) ;
}
return V_60 ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_14 ;
if ( V_14 -> V_16 . V_17 == 53572 )
return 300000000 ;
if ( V_2 -> V_31 . V_28 >= 5 ) {
T_1 V_61 ;
switch ( V_14 -> V_16 . V_17 ) {
case 0x5356 :
V_61 = V_57 ;
break;
case 0x5357 :
case 0x4749 :
V_61 = V_58 ;
break;
default:
V_61 = V_43 ;
break;
}
return F_21 ( V_2 , V_61 , V_62 ) ;
}
return F_23 ( V_2 ) ;
}
