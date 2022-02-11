T_1 F_1 ( void T_2 * V_1 )
{
T_1 V_2 = 0 ;
F_2 ( V_1 , V_3 ) ;
return V_2 ;
}
T_1 F_3 ( void T_2 * V_1 )
{
T_1 V_2 = 0 ;
F_2 ( V_1 , V_4 ) ;
return V_2 ;
}
T_1 F_4 ( void T_2 * V_1 ,
T_3 V_5 )
{
T_1 V_2 = 0 ;
F_5 ( V_1 , V_5 ) ;
return V_2 ;
}
T_1 F_6 ( void T_2 * V_1 ,
T_3 V_6 )
{
T_1 V_2 = 0 ;
F_7 ( V_1 , V_6 ) ;
return V_2 ;
}
T_1 F_8 ( void T_2 * V_1 , T_3 V_7 )
{
T_1 V_2 = 0 ;
F_9 ( V_1 , V_7 ) ;
return V_2 ;
}
T_1 F_10 ( void T_2 * V_1 , T_3 V_7 )
{
T_1 V_2 = 0 ;
T_3 V_8 ;
V_8 = F_11 ( V_1 ) ;
F_12 ( V_1 , V_8 & ~ V_7 ) ;
return V_2 ;
}
T_1 F_13 ( void T_2 * V_1 , T_3 V_7 )
{
T_1 V_2 = 0 ;
T_3 V_8 ;
V_8 = F_11 ( V_1 ) ;
F_12 ( V_1 , V_8 | V_7 ) ;
return V_2 ;
}
T_1 F_14 ( void T_2 * V_1 , T_3 * V_7 )
{
T_1 V_2 = 0 ;
* V_7 = F_15 ( V_1 ) ;
return V_2 ;
}
T_1 F_16 ( void T_2 * V_1 , T_3 * V_9 )
{
T_1 V_2 = 0 ;
* V_9 = F_17 ( V_1 ) ;
return V_2 ;
}
T_1 F_18 ( void T_2 * V_1 , T_3 V_10 )
{
T_1 V_2 = 0 ;
T_3 V_11 ;
V_11 = V_10 & ~ 0x7FUL ;
F_19 ( V_1 , V_11 ) ;
return V_2 ;
}
T_1 F_20 ( void T_2 * V_1 )
{
T_1 V_2 = 0 ;
F_21 ( V_1 , V_3 ) ;
return V_2 ;
}
T_1 F_22 ( void T_2 * V_1 )
{
T_1 V_2 = 0 ;
F_21 ( V_1 , V_4 ) ;
return V_2 ;
}
T_1 F_23 ( void T_2 * V_1 ,
T_3 V_12 ,
T_3 V_13 ,
T_3 V_14 ,
T_3 V_15 ,
struct V_16 * V_17 ,
T_4 V_18 , T_4 V_19 )
{
T_1 V_2 = 0 ;
T_3 V_20 ;
T_3 V_21 ;
enum V_22 V_23 ;
switch ( V_14 ) {
case V_24 :
V_23 = V_25 ;
break;
case V_26 :
V_23 = V_27 ;
break;
case V_28 :
V_23 = V_29 ;
break;
case V_30 :
V_23 = V_31 ;
break;
default:
return - V_32 ;
}
V_20 = F_24 ( V_1 ) ;
V_21 = ( ( V_13 & V_33 ) >> 12 ) ;
F_25 ( V_1 , V_23 , V_18 , V_19 ,
V_21 ) ;
F_26 ( V_1 , V_12 , V_17 -> V_34 ,
V_17 -> V_35 , V_17 -> V_36 ) ;
F_7 ( V_1 , V_15 ) ;
F_27 ( V_1 , V_37 ) ;
F_28 ( V_1 , V_20 ) ;
return V_2 ;
}
T_1 F_29 ( const T_3 V_38 ,
T_3 V_12 ,
T_3 V_13 ,
T_3 V_14 , struct V_16 * V_17 )
{
T_1 V_2 = 0 ;
T_3 V_39 , V_40 ;
T_5 V_41 = 1 ;
switch ( V_14 ) {
case V_24 :
V_39 = F_30 ( V_38 ,
V_13 &
V_42 ) ;
V_40 =
( ( V_12 & V_42 ) |
( V_17 -> V_34 << 9 ) | ( V_17 ->
V_35 << 4 ) |
( V_17 -> V_36 << 11 ) | 2 ) ;
break;
case V_26 :
V_41 = 16 ;
V_39 = F_30 ( V_38 ,
V_13 &
V_43 ) ;
V_40 =
( ( V_12 & V_43 ) |
( V_17 -> V_34 << 9 ) | ( V_17 ->
V_35 << 4 ) |
( V_17 -> V_36 << 11 ) | 1 ) ;
break;
case V_28 :
V_39 = F_31 ( V_38 ,
V_13 &
V_44 ) ;
V_40 =
( ( ( ( V_12 & V_44 ) |
( V_17 -> V_34 << 15 ) | ( V_17 ->
V_35 << 10 ) |
( V_17 -> V_36 << 17 ) ) & ~ 0x40000 ) | 0x2 ) ;
break;
case V_30 :
V_41 = 16 ;
V_39 = F_31 ( V_38 ,
V_13 &
V_45 ) ;
V_40 =
( ( ( V_12 & V_45 ) |
( V_17 -> V_34 << 15 ) | ( V_17 ->
V_35 << 10 ) |
( V_17 -> V_36 << 17 )
) | 0x40000 | 0x2 ) ;
break;
case V_46 :
V_39 = F_31 ( V_38 ,
V_13 &
V_44 ) ;
V_40 = ( V_12 & V_47 ) | 1 ;
break;
default:
return - V_32 ;
}
while ( -- V_41 >= 0 )
( ( T_3 * ) V_39 ) [ V_41 ] = V_40 ;
return V_2 ;
}
T_1 F_32 ( const T_3 V_38 , T_3 V_13 , T_3 V_48 )
{
T_1 V_2 = 0 ;
T_3 V_39 ;
T_5 V_41 = 1 ;
switch ( V_48 ) {
case V_24 :
V_39 = F_30 ( V_38 ,
V_13 &
V_42 ) ;
break;
case V_26 :
V_41 = 16 ;
V_39 = F_30 ( V_38 ,
V_13 &
V_43 ) ;
break;
case V_28 :
case V_46 :
V_39 = F_31 ( V_38 ,
V_13 &
V_44 ) ;
break;
case V_30 :
V_41 = 16 ;
V_39 = F_31 ( V_38 ,
V_13 &
V_45 ) ;
break;
default:
return - V_32 ;
}
while ( -- V_41 >= 0 )
( ( T_3 * ) V_39 ) [ V_41 ] = 0 ;
return V_2 ;
}
static T_1 F_25 ( void T_2 * V_1 ,
const T_3 V_14 ,
const T_3 V_18 ,
const T_3 V_19 ,
const T_3 V_21 )
{
T_1 V_2 = 0 ;
T_3 V_49 ;
V_49 = ( V_21 << 12 ) ;
V_49 = ( V_49 ) | ( V_14 ) | ( V_19 << 2 ) |
( V_18 << 3 ) ;
F_33 ( V_1 , V_49 ) ;
return V_2 ;
}
static T_1 F_26 ( void T_2 * V_1 ,
const T_3 V_12 ,
enum V_50 V_34 ,
enum V_51 V_35 ,
enum V_52 V_36 )
{
T_1 V_2 = 0 ;
T_3 V_53 ;
V_53 = ( V_12 & V_33 ) ;
V_53 = ( V_53 ) | ( ( V_34 << 9 ) | ( V_35 << 7 ) |
( V_36 << 6 ) ) ;
F_34 ( V_1 , V_53 ) ;
return V_2 ;
}
void F_35 ( void T_2 * V_54 )
{
F_36 ( 1 , V_54 + V_55 ) ;
}
