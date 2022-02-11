T_1 F_1 ( const void T_2 * V_1 )
{
T_1 V_2 = 0 ;
F_2 ( V_1 , V_3 ) ;
return V_2 ;
}
T_1 F_3 ( const void T_2 * V_1 )
{
T_1 V_2 = 0 ;
F_2 ( V_1 , V_4 ) ;
return V_2 ;
}
T_1 F_4 ( const void T_2 * V_1 ,
T_3 V_5 )
{
T_1 V_2 = 0 ;
F_5 ( V_1 , V_5 ) ;
return V_2 ;
}
T_1 F_6 ( const void T_2 * V_1 ,
T_3 V_6 )
{
T_1 V_2 = 0 ;
F_7 ( V_1 , V_6 ) ;
return V_2 ;
}
T_1 F_8 ( const void T_2 * V_1 , T_3 V_7 )
{
T_1 V_2 = 0 ;
F_9 ( V_1 , V_7 ) ;
return V_2 ;
}
T_1 F_10 ( const void T_2 * V_1 , T_3 V_7 )
{
T_1 V_2 = 0 ;
T_3 V_8 ;
V_8 = F_11 ( V_1 ) ;
F_12 ( V_1 , V_8 & ~ V_7 ) ;
return V_2 ;
}
T_1 F_13 ( const void T_2 * V_1 , T_3 V_7 )
{
T_1 V_2 = 0 ;
T_3 V_8 ;
V_8 = F_11 ( V_1 ) ;
F_12 ( V_1 , V_8 | V_7 ) ;
return V_2 ;
}
T_1 F_14 ( const void T_2 * V_1 , T_3 * V_7 )
{
T_1 V_2 = 0 ;
* V_7 = F_15 ( V_1 ) ;
return V_2 ;
}
T_1 F_16 ( const void T_2 * V_1 , T_3 * V_9 )
{
T_1 V_2 = 0 ;
* V_9 = F_17 ( V_1 ) ;
return V_2 ;
}
T_1 F_18 ( const void T_2 * V_1 , T_3 V_10 )
{
T_1 V_2 = 0 ;
T_3 V_11 ;
V_11 = V_10 & ~ 0x7FUL ;
F_19 ( V_1 , V_11 ) ;
return V_2 ;
}
T_1 F_20 ( const void T_2 * V_1 )
{
T_1 V_2 = 0 ;
F_21 ( V_1 , V_3 ) ;
return V_2 ;
}
T_1 F_22 ( const void T_2 * V_1 )
{
T_1 V_2 = 0 ;
F_21 ( V_1 , V_4 ) ;
return V_2 ;
}
T_1 F_23 ( const void T_2 * V_1 , T_3 V_12 ,
T_3 V_13 )
{
T_1 V_2 = 0 ;
T_3 V_14 ;
enum V_15 V_16 ;
switch ( V_13 ) {
case V_17 :
V_16 = V_18 ;
break;
case V_19 :
V_16 = V_20 ;
break;
case V_21 :
V_16 = V_22 ;
break;
case V_23 :
V_16 = V_24 ;
break;
default:
return - V_25 ;
}
V_14 = ( ( V_12 & V_26 ) >> 12 ) ;
F_24 ( V_1 , V_16 , 0 , 0 , V_14 ) ;
F_25 ( V_1 ) ;
return V_2 ;
}
T_1 F_26 ( const void T_2 * V_1 ,
T_3 V_27 ,
T_3 V_12 ,
T_3 V_13 ,
T_3 V_28 ,
struct V_29 * V_30 ,
T_4 V_31 , T_4 V_32 )
{
T_1 V_2 = 0 ;
T_3 V_33 ;
T_3 V_14 ;
enum V_15 V_34 ;
switch ( V_13 ) {
case V_17 :
V_34 = V_18 ;
break;
case V_19 :
V_34 = V_20 ;
break;
case V_21 :
V_34 = V_22 ;
break;
case V_23 :
V_34 = V_24 ;
break;
default:
return - V_25 ;
}
V_33 = F_27 ( V_1 ) ;
V_14 = ( ( V_12 & V_26 ) >> 12 ) ;
F_24 ( V_1 , V_34 , V_31 , V_32 ,
V_14 ) ;
F_28 ( V_1 , V_27 , V_30 -> V_35 ,
V_30 -> V_36 , V_30 -> V_37 ) ;
F_7 ( V_1 , V_28 ) ;
F_29 ( V_1 , V_38 ) ;
F_30 ( V_1 , V_33 ) ;
return V_2 ;
}
T_1 F_31 ( const T_3 V_39 ,
T_3 V_27 ,
T_3 V_12 ,
T_3 V_13 , struct V_29 * V_30 )
{
T_1 V_2 = 0 ;
T_3 V_40 , V_41 ;
T_5 V_42 = 1 ;
switch ( V_13 ) {
case V_17 :
V_40 = F_32 ( V_39 ,
V_12 &
V_43 ) ;
V_41 =
( ( V_27 & V_43 ) |
( V_30 -> V_35 << 9 ) | ( V_30 ->
V_36 << 4 ) |
( V_30 -> V_37 << 11 ) | 2 ) ;
break;
case V_19 :
V_42 = 16 ;
V_40 = F_32 ( V_39 ,
V_12 &
V_44 ) ;
V_41 =
( ( V_27 & V_44 ) |
( V_30 -> V_35 << 9 ) | ( V_30 ->
V_36 << 4 ) |
( V_30 -> V_37 << 11 ) | 1 ) ;
break;
case V_21 :
V_40 = F_33 ( V_39 ,
V_12 &
V_45 ) ;
V_41 =
( ( ( ( V_27 & V_45 ) |
( V_30 -> V_35 << 15 ) | ( V_30 ->
V_36 << 10 ) |
( V_30 -> V_37 << 17 ) ) & ~ 0x40000 ) | 0x2 ) ;
break;
case V_23 :
V_42 = 16 ;
V_40 = F_33 ( V_39 ,
V_12 &
V_46 ) ;
V_41 =
( ( ( V_27 & V_46 ) |
( V_30 -> V_35 << 15 ) | ( V_30 ->
V_36 << 10 ) |
( V_30 -> V_37 << 17 )
) | 0x40000 | 0x2 ) ;
break;
case V_47 :
V_40 = F_33 ( V_39 ,
V_12 &
V_45 ) ;
V_41 = ( V_27 & V_48 ) | 1 ;
break;
default:
return - V_25 ;
}
while ( -- V_42 >= 0 )
( ( T_3 * ) V_40 ) [ V_42 ] = V_41 ;
return V_2 ;
}
T_1 F_34 ( const T_3 V_39 , T_3 V_12 , T_3 V_49 )
{
T_1 V_2 = 0 ;
T_3 V_40 ;
T_5 V_42 = 1 ;
switch ( V_49 ) {
case V_17 :
V_40 = F_32 ( V_39 ,
V_12 &
V_43 ) ;
break;
case V_19 :
V_42 = 16 ;
V_40 = F_32 ( V_39 ,
V_12 &
V_44 ) ;
break;
case V_21 :
case V_47 :
V_40 = F_33 ( V_39 ,
V_12 &
V_45 ) ;
break;
case V_23 :
V_42 = 16 ;
V_40 = F_33 ( V_39 ,
V_12 &
V_46 ) ;
break;
default:
return - V_25 ;
}
while ( -- V_42 >= 0 )
( ( T_3 * ) V_40 ) [ V_42 ] = 0 ;
return V_2 ;
}
static T_1 F_25 ( const void T_2 * V_1 )
{
T_1 V_2 = 0 ;
T_3 V_50 = 0x1 ;
F_35 ( V_1 , V_50 ) ;
return V_2 ;
}
static T_1 F_24 ( const void T_2 * V_1 ,
const T_3 V_13 ,
const T_3 V_31 ,
const T_3 V_32 ,
const T_3 V_14 )
{
T_1 V_2 = 0 ;
T_3 V_51 ;
V_51 = ( V_14 << 12 ) ;
V_51 = ( V_51 ) | ( V_13 ) | ( V_32 << 2 ) |
( V_31 << 3 ) ;
F_36 ( V_1 , V_51 ) ;
return V_2 ;
}
static T_1 F_28 ( const void T_2 * V_1 ,
const T_3 V_27 ,
enum V_52 V_35 ,
enum V_53 V_36 ,
enum V_54 V_37 )
{
T_1 V_2 = 0 ;
T_3 V_55 ;
V_55 = ( V_27 & V_26 ) ;
V_55 = ( V_55 ) | ( ( V_35 << 9 ) | ( V_36 << 7 ) |
( V_37 << 6 ) ) ;
F_37 ( V_1 , V_55 ) ;
return V_2 ;
}
void F_38 ( const void T_2 * V_56 )
{
F_39 ( 1 , V_56 + V_57 ) ;
}
