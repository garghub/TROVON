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
static void
F_5 ( struct V_8 * V_9 , struct V_12 * V_13 )
{
struct V_29 * V_30 = V_9 -> V_31 ;
F_4 ( V_9 , V_32 ) ;
if ( V_30 == NULL )
return;
if ( ! V_30 -> V_33 ( V_30 , V_13 ) )
return;
F_4 ( V_9 , V_34 ) ;
F_6 ( V_9 -> V_35 ) ;
}
void F_7 ( struct V_8 * V_9 , void * V_36 ,
struct V_37 * V_38 , T_4 V_39 )
{
struct V_10 V_11 ;
T_3 V_40 ;
char * V_41 ;
struct V_12 V_13 ;
struct V_1 * V_2 = V_9 -> V_27 ;
struct V_42 * V_43 = F_8 ( V_2 ) ;
F_4 ( V_9 , V_44 ) ;
if ( ( V_38 -> V_45 != V_46 ) &&
( V_38 -> V_45 != V_47 ) ) {
F_9 ( V_43 , V_48 ,
L_1 ,
V_38 -> V_45 ) ;
F_4 ( V_9 , V_49 ) ;
return;
}
V_40 = V_38 -> V_50 ;
if ( V_40 == 0 ) {
F_4 ( V_9 , V_51 ) ;
return;
}
V_11 . V_14 = V_38 -> V_52 [ 0 ] ;
V_11 . V_19 = V_38 -> V_53 [ 0 ] ;
if ( V_11 . V_14 & 0x80 )
V_11 . V_14 = 0 ;
if ( V_11 . V_19 & 0x80 )
V_11 . V_19 = 0 ;
V_41 = ( char * ) V_36 + V_40 ;
V_11 . V_15 = V_41 [ - 1 ] ;
V_11 . V_21 = V_41 [ - 2 ] ;
V_11 . V_17 = V_41 [ - 3 ] ;
V_13 . V_54 = V_2 -> V_7 -> V_55 ;
V_13 . V_56 = V_39 ;
if ( ! F_3 ( V_9 , & V_11 , & V_13 ) )
return;
F_9 ( V_43 , V_48 ,
L_2
L_3 ,
V_11 . V_15 , V_13 . V_54 , V_13 . V_56 , V_13 . V_26 , V_13 . V_14 ,
V_13 . V_56 - V_9 -> V_57 ) ;
V_9 -> V_57 = V_13 . V_56 ;
if ( V_11 . V_15 & V_16 )
F_5 ( V_9 , & V_13 ) ;
if ( V_11 . V_15 & V_20 ) {
V_13 . V_54 += F_10 ( V_2 -> V_7 ) ? 20 : - 20 ;
F_5 ( V_9 , & V_13 ) ;
}
}
