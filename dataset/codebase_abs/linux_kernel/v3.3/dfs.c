static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const T_1 V_4 = 800 ;
const T_1 V_5 = ( 8000 / 11 ) ;
T_1 V_6 ;
if ( F_2 ( V_2 , V_2 -> V_7 ) )
V_6 = V_3 * V_5 ;
else
V_6 = V_3 * V_4 ;
return ( V_6 + 500 ) / 1000 ;
}
static bool
F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
T_2 V_14 ;
T_3 V_3 ;
F_4 ( F_5 ( V_9 -> V_15 ) , V_16 ,
L_1 ,
V_11 -> V_17 ,
V_11 -> V_18 , V_11 -> V_14 ,
V_11 -> V_19 , V_11 -> V_20 ) ;
V_11 -> V_17 &= 0x03 ;
switch ( V_11 -> V_17 ) {
case V_21 :
V_3 = V_11 -> V_18 ;
F_6 ( V_9 , V_22 ) ;
V_14 = ( V_11 -> V_20 >= ( V_11 -> V_14 + 3 ) ) ? 0 : V_11 -> V_14 ;
break;
case V_23 :
V_3 = V_11 -> V_19 ;
F_6 ( V_9 , V_24 ) ;
V_14 = ( V_11 -> V_14 >= ( V_11 -> V_20 + 12 ) ) ? 0 : V_11 -> V_20 ;
break;
case ( V_21 | V_23 ) :
if ( V_11 -> V_19 >= V_11 -> V_18 )
V_3 = V_11 -> V_19 ;
else
V_3 = V_11 -> V_18 ;
F_6 ( V_9 , V_25 ) ;
V_14 = ( V_11 -> V_14 < V_11 -> V_20 ) ? V_11 -> V_20 : V_11 -> V_14 ;
break;
default:
F_6 ( V_9 , V_26 ) ;
return false ;
}
if ( V_14 == 0 ) {
F_6 ( V_9 , V_27 ) ;
return false ;
}
V_13 -> V_28 = F_1 ( V_9 -> V_15 , V_3 ) ;
V_13 -> V_14 = V_14 ;
F_6 ( V_9 , V_29 ) ;
return true ;
}
void F_7 ( struct V_8 * V_9 , void * V_30 ,
struct V_31 * V_32 , T_4 V_33 )
{
struct V_10 V_34 ;
T_3 V_35 ;
char * V_36 ;
struct V_12 V_13 ;
struct V_1 * V_2 = V_9 -> V_15 ;
struct V_37 * V_38 = F_5 ( V_2 ) ;
if ( ( ! ( V_32 -> V_39 != V_40 ) ) &&
( ! ( V_32 -> V_39 != V_41 ) ) ) {
F_4 ( V_38 , V_16 ,
L_2 ,
V_32 -> V_39 ) ;
return;
}
V_35 = V_32 -> V_42 ;
if ( V_35 == 0 ) {
F_6 ( V_9 , V_43 ) ;
return;
}
V_34 . V_14 = V_32 -> V_44 ;
V_34 . V_20 = V_32 -> V_45 ;
if ( V_34 . V_14 & 0x80 )
V_34 . V_14 = 0 ;
if ( V_34 . V_20 & 0x80 )
V_34 . V_20 = 0 ;
V_36 = ( char * ) V_30 + V_35 ;
V_34 . V_17 = V_36 [ - 1 ] ;
V_34 . V_19 = V_36 [ - 2 ] ;
V_34 . V_18 = V_36 [ - 3 ] ;
F_4 ( V_38 , V_16 ,
L_3
L_4 ,
V_34 . V_17 , V_34 . V_18 , V_34 . V_19 ,
V_34 . V_14 , V_34 . V_20 ) ;
V_13 . V_46 = V_2 -> V_7 -> V_47 ;
V_13 . V_48 = V_33 ;
if ( F_3 ( V_9 , & V_34 , & V_13 ) ) {
static T_4 V_49 ;
F_4 ( V_38 , V_16 ,
L_5
L_6 ,
V_13 . V_46 , V_13 . V_48 , V_13 . V_28 , V_13 . V_14 , V_13 . V_48 - V_49 ) ;
V_49 = V_13 . V_48 ;
}
}
