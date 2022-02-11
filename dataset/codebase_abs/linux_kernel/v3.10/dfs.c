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
V_11 -> V_15 &= 0x03 ;
switch ( V_11 -> V_15 ) {
case V_16 :
V_3 = V_11 -> V_17 ;
F_4 ( V_9 , V_18 ) ;
V_14 = ( V_11 -> V_19 >= ( V_11 -> V_14 + 3 ) ) ? 0 : V_11 -> V_14 ;
break;
case V_20 :
V_3 = V_11 -> V_21 ;
F_4 ( V_9 , V_22 ) ;
V_14 = ( V_11 -> V_14 >= ( V_11 -> V_19 + 12 ) ) ? 0 : V_11 -> V_19 ;
break;
case ( V_16 | V_20 ) :
if ( V_11 -> V_21 >= V_11 -> V_17 )
V_3 = V_11 -> V_21 ;
else
V_3 = V_11 -> V_17 ;
F_4 ( V_9 , V_23 ) ;
V_14 = ( V_11 -> V_14 < V_11 -> V_19 ) ? V_11 -> V_19 : V_11 -> V_14 ;
break;
default:
F_4 ( V_9 , V_24 ) ;
return false ;
}
if ( V_14 == 0 ) {
F_4 ( V_9 , V_25 ) ;
return false ;
}
V_13 -> V_26 = F_1 ( V_9 -> V_27 , V_3 ) ;
V_13 -> V_14 = V_14 ;
F_4 ( V_9 , V_28 ) ;
return true ;
}
void F_5 ( struct V_8 * V_9 , void * V_29 ,
struct V_30 * V_31 , T_4 V_32 )
{
struct V_10 V_11 ;
T_3 V_33 ;
char * V_34 ;
struct V_12 V_13 ;
struct V_1 * V_2 = V_9 -> V_27 ;
struct V_35 * V_36 = F_6 ( V_2 ) ;
F_4 ( V_9 , V_37 ) ;
if ( ( V_31 -> V_38 != V_39 ) &&
( V_31 -> V_38 != V_40 ) ) {
F_7 ( V_36 , V_41 ,
L_1 ,
V_31 -> V_38 ) ;
F_4 ( V_9 , V_42 ) ;
return;
}
V_33 = V_31 -> V_43 ;
if ( V_33 == 0 ) {
F_4 ( V_9 , V_44 ) ;
return;
}
V_11 . V_14 = V_31 -> V_45 ;
V_11 . V_19 = V_31 -> V_46 ;
if ( V_11 . V_14 & 0x80 )
V_11 . V_14 = 0 ;
if ( V_11 . V_19 & 0x80 )
V_11 . V_19 = 0 ;
V_34 = ( char * ) V_29 + V_33 ;
V_11 . V_15 = V_34 [ - 1 ] ;
V_11 . V_21 = V_34 [ - 2 ] ;
V_11 . V_17 = V_34 [ - 3 ] ;
V_13 . V_47 = V_2 -> V_7 -> V_48 ;
V_13 . V_49 = V_32 ;
if ( F_3 ( V_9 , & V_11 , & V_13 ) ) {
struct V_50 * V_51 = V_9 -> V_52 ;
static T_4 V_53 ;
F_7 ( V_36 , V_41 ,
L_2
L_3 ,
V_13 . V_47 , V_13 . V_49 , V_13 . V_26 , V_13 . V_14 , V_13 . V_49 - V_53 ) ;
V_53 = V_13 . V_49 ;
F_4 ( V_9 , V_54 ) ;
if ( V_51 != NULL && V_51 -> V_55 ( V_51 , & V_13 ) ) {
F_4 ( V_9 , V_56 ) ;
F_8 ( V_9 -> V_57 ) ;
}
}
}
