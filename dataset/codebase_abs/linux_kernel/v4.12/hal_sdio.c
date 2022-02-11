T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 < 8 )
V_4 -> V_5 = 8 ;
return V_4 -> V_5 ;
}
T_1 F_3 (
struct V_1 * V_2 , T_1 V_6 , T_1 V_7
)
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_4 -> V_8 [ V_6 ] + V_4 -> V_8 [ V_9 ] ) >= ( V_7 ) )
return true ;
else
return false ;
}
void F_4 (
struct V_1 * V_2 , T_1 V_6 , T_1 V_7
)
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
V_10 = V_4 -> V_8 [ V_6 ] ;
if ( V_7 <= V_10 ) {
V_4 -> V_8 [ V_6 ] -= V_7 ;
} else {
V_4 -> V_8 [ V_6 ] = 0 ;
V_11 = V_7 - V_10 ;
V_4 -> V_8 [ V_9 ] -= V_11 ;
}
}
void F_5 (
struct V_1 * V_2 , T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15
)
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_16 ;
T_2 V_17 , V_18 , V_19 ;
F_6 ( V_2 , V_20 , & V_16 ) ;
V_17 = ( ( V_12 + V_15 ) >> 1 ) * V_16 ;
V_18 = ( ( V_13 + V_15 ) >> 1 ) * V_16 ;
V_19 = ( ( V_14 + V_15 ) >> 1 ) * V_16 ;
V_4 -> V_21 [ V_22 ] =
( V_17 > V_23 ) ? V_23 : V_17 ;
V_4 -> V_21 [ V_24 ] =
( V_18 > V_23 ) ? V_23 : V_18 ;
V_4 -> V_21 [ V_25 ] =
( V_19 > V_23 ) ? V_23 : V_19 ;
}
T_2 F_7 ( struct V_1 * V_2 , T_1 V_26 )
{
struct V_27 * V_28 = F_8 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_29 , V_30 ;
V_29 = F_9 ( V_28 , V_26 ) ;
switch ( V_29 ) {
case V_31 :
V_30 = V_4 -> V_21 [ V_22 ] ;
break;
case V_32 :
V_30 = V_4 -> V_21 [ V_24 ] ;
break;
case V_33 :
V_30 = V_4 -> V_21 [ V_25 ] ;
break;
default:
V_30 = V_4 -> V_21 [ V_24 ] ;
break;
}
return V_30 ;
}
