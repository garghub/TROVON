T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
if ( ! V_6 )
return 0 ;
V_9 = V_6 -> V_8 ;
if ( ! V_9 )
return 0 ;
V_4 = V_9 -> V_10 [ V_2 -> V_11 ] ;
if ( ! F_2 ( & V_4 -> V_12 ) )
return 0 ;
switch ( V_2 -> V_13 [ 0 ] ) {
case V_14 :
case V_15 :
case V_16 :
return 0 ;
default:
return V_17 ;
}
}
int F_3 (
struct V_8 * V_9 ,
T_2 V_18 ,
T_3 V_19 ,
T_3 V_20 )
{
struct V_3 * V_4 ;
struct V_21 * V_22 , * V_23 , * V_24 ;
if ( ! V_9 )
return - V_25 ;
V_22 = F_4 ( V_26 , V_27 ) ;
if ( ! V_22 ) {
F_5 ( L_1 ) ;
return - V_28 ;
}
F_6 ( & V_22 -> V_29 ) ;
V_22 -> V_30 = V_9 ;
V_22 -> V_31 = V_19 ;
V_22 -> V_32 = V_20 ;
F_7 ( & V_9 -> V_33 ) ;
V_4 = V_9 -> V_10 [ V_18 ] ;
F_8 ( & V_4 -> V_34 ) ;
F_9 (ua_p, ua_tmp, &deve->ua_list, ua_nacl_list) {
if ( ( V_23 -> V_31 == V_19 ) && ( V_23 -> V_32 == V_20 ) ) {
F_10 ( & V_4 -> V_34 ) ;
F_11 ( & V_9 -> V_33 ) ;
F_12 ( V_26 , V_22 ) ;
return 0 ;
}
if ( V_23 -> V_31 == 0x29 ) {
if ( ( V_19 == 0x29 ) && ( V_20 > V_23 -> V_32 ) )
F_13 ( & V_22 -> V_29 ,
& V_4 -> V_35 ) ;
else
F_14 ( & V_22 -> V_29 ,
& V_4 -> V_35 ) ;
} else if ( V_23 -> V_31 == 0x2a ) {
if ( ( V_19 == 0x29 ) || ( V_20 > V_23 -> V_31 ) )
F_13 ( & V_22 -> V_29 ,
& V_4 -> V_35 ) ;
else
F_14 ( & V_22 -> V_29 ,
& V_4 -> V_35 ) ;
} else
F_14 ( & V_22 -> V_29 ,
& V_4 -> V_35 ) ;
F_10 ( & V_4 -> V_34 ) ;
F_11 ( & V_9 -> V_33 ) ;
F_15 ( & V_4 -> V_12 ) ;
return 0 ;
}
F_14 ( & V_22 -> V_29 , & V_4 -> V_35 ) ;
F_10 ( & V_4 -> V_34 ) ;
F_11 ( & V_9 -> V_33 ) ;
F_16 ( L_2
L_3 ,
V_9 -> V_36 -> V_37 -> V_38 () , V_18 ,
V_19 , V_20 ) ;
F_15 ( & V_4 -> V_12 ) ;
return 0 ;
}
void F_17 (
struct V_3 * V_4 )
{
struct V_21 * V_22 , * V_23 ;
F_8 ( & V_4 -> V_34 ) ;
F_9 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
F_18 ( & V_22 -> V_29 ) ;
F_12 ( V_26 , V_22 ) ;
F_19 ( & V_4 -> V_12 ) ;
}
F_10 ( & V_4 -> V_34 ) ;
}
void F_20 (
struct V_1 * V_2 ,
T_3 * V_19 ,
T_3 * V_20 )
{
struct V_39 * V_40 = V_2 -> V_41 ;
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_21 * V_22 = NULL , * V_23 ;
int V_42 = 1 ;
if ( ! V_6 )
return;
V_9 = V_6 -> V_8 ;
if ( ! V_9 )
return;
F_7 ( & V_9 -> V_33 ) ;
V_4 = V_9 -> V_10 [ V_2 -> V_11 ] ;
if ( ! F_2 ( & V_4 -> V_12 ) ) {
F_11 ( & V_9 -> V_33 ) ;
return;
}
F_8 ( & V_4 -> V_34 ) ;
F_9 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
if ( V_40 -> V_43 . V_44 != 0 ) {
* V_19 = V_22 -> V_31 ;
* V_20 = V_22 -> V_32 ;
break;
}
if ( V_42 ) {
* V_19 = V_22 -> V_31 ;
* V_20 = V_22 -> V_32 ;
V_42 = 0 ;
}
F_18 ( & V_22 -> V_29 ) ;
F_12 ( V_26 , V_22 ) ;
F_19 ( & V_4 -> V_12 ) ;
}
F_10 ( & V_4 -> V_34 ) ;
F_11 ( & V_9 -> V_33 ) ;
F_16 ( L_4
L_5
L_6 ,
V_9 -> V_36 -> V_37 -> V_38 () ,
( V_40 -> V_43 . V_44 != 0 ) ? L_7 :
L_8 , V_40 -> V_43 . V_44 ,
V_2 -> V_11 , V_2 -> V_13 [ 0 ] , * V_19 , * V_20 ) ;
}
int F_21 (
struct V_1 * V_2 ,
T_3 * V_19 ,
T_3 * V_20 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_21 * V_22 = NULL , * V_23 ;
int V_42 = 1 ;
if ( ! V_6 )
return - V_25 ;
V_9 = V_6 -> V_8 ;
if ( ! V_9 )
return - V_25 ;
F_7 ( & V_9 -> V_33 ) ;
V_4 = V_9 -> V_10 [ V_2 -> V_11 ] ;
if ( ! F_2 ( & V_4 -> V_12 ) ) {
F_11 ( & V_9 -> V_33 ) ;
return - V_45 ;
}
F_8 ( & V_4 -> V_34 ) ;
F_9 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
if ( V_42 ) {
* V_19 = V_22 -> V_31 ;
* V_20 = V_22 -> V_32 ;
V_42 = 0 ;
}
F_18 ( & V_22 -> V_29 ) ;
F_12 ( V_26 , V_22 ) ;
F_19 ( & V_4 -> V_12 ) ;
}
F_10 ( & V_4 -> V_34 ) ;
F_11 ( & V_9 -> V_33 ) ;
F_16 ( L_9
L_10
L_11 , V_9 -> V_36 -> V_37 -> V_38 () ,
V_2 -> V_11 , * V_19 , * V_20 ) ;
return ( V_42 ) ? - V_45 : 0 ;
}
