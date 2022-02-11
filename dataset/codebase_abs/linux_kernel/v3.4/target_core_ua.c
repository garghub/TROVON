int F_1 (
struct V_1 * V_2 ,
unsigned char * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
if ( ! V_7 )
return 0 ;
V_10 = V_7 -> V_9 ;
if ( ! V_10 )
return 0 ;
V_5 = V_10 -> V_11 [ V_2 -> V_12 ] ;
if ( ! F_2 ( & V_5 -> V_13 ) )
return 0 ;
switch ( V_3 [ 0 ] ) {
case V_14 :
case V_15 :
case V_16 :
return 0 ;
default:
return - V_17 ;
}
return - V_17 ;
}
int F_3 (
struct V_9 * V_10 ,
T_1 V_18 ,
T_2 V_19 ,
T_2 V_20 )
{
struct V_4 * V_5 ;
struct V_21 * V_22 , * V_23 , * V_24 ;
if ( ! V_10 )
return - V_17 ;
V_22 = F_4 ( V_25 , V_26 ) ;
if ( ! V_22 ) {
F_5 ( L_1 ) ;
return - V_27 ;
}
F_6 ( & V_22 -> V_28 ) ;
F_6 ( & V_22 -> V_29 ) ;
V_22 -> V_30 = V_10 ;
V_22 -> V_31 = V_19 ;
V_22 -> V_32 = V_20 ;
F_7 ( & V_10 -> V_33 ) ;
V_5 = V_10 -> V_11 [ V_18 ] ;
F_8 ( & V_5 -> V_34 ) ;
F_9 (ua_p, ua_tmp, &deve->ua_list, ua_nacl_list) {
if ( ( V_23 -> V_31 == V_19 ) && ( V_23 -> V_32 == V_20 ) ) {
F_10 ( & V_5 -> V_34 ) ;
F_11 ( & V_10 -> V_33 ) ;
F_12 ( V_25 , V_22 ) ;
return 0 ;
}
if ( V_23 -> V_31 == 0x29 ) {
if ( ( V_19 == 0x29 ) && ( V_20 > V_23 -> V_32 ) )
F_13 ( & V_22 -> V_29 ,
& V_5 -> V_35 ) ;
else
F_14 ( & V_22 -> V_29 ,
& V_5 -> V_35 ) ;
} else if ( V_23 -> V_31 == 0x2a ) {
if ( ( V_19 == 0x29 ) || ( V_20 > V_23 -> V_31 ) )
F_13 ( & V_22 -> V_29 ,
& V_5 -> V_35 ) ;
else
F_14 ( & V_22 -> V_29 ,
& V_5 -> V_35 ) ;
} else
F_14 ( & V_22 -> V_29 ,
& V_5 -> V_35 ) ;
F_10 ( & V_5 -> V_34 ) ;
F_11 ( & V_10 -> V_33 ) ;
F_15 ( & V_5 -> V_13 ) ;
F_16 () ;
return 0 ;
}
F_14 ( & V_22 -> V_29 , & V_5 -> V_35 ) ;
F_10 ( & V_5 -> V_34 ) ;
F_11 ( & V_10 -> V_33 ) ;
F_17 ( L_2
L_3 ,
V_10 -> V_36 -> V_37 -> V_38 () , V_18 ,
V_19 , V_20 ) ;
F_15 ( & V_5 -> V_13 ) ;
F_16 () ;
return 0 ;
}
void F_18 (
struct V_4 * V_5 )
{
struct V_21 * V_22 , * V_23 ;
F_8 ( & V_5 -> V_34 ) ;
F_9 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
F_19 ( & V_22 -> V_29 ) ;
F_12 ( V_25 , V_22 ) ;
F_20 ( & V_5 -> V_13 ) ;
F_21 () ;
}
F_10 ( & V_5 -> V_34 ) ;
}
void F_22 (
struct V_1 * V_2 ,
T_2 * V_19 ,
T_2 * V_20 )
{
struct V_39 * V_40 = V_2 -> V_41 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_21 * V_22 = NULL , * V_23 ;
int V_42 = 1 ;
if ( ! V_7 )
return;
V_10 = V_7 -> V_9 ;
if ( ! V_10 )
return;
F_7 ( & V_10 -> V_33 ) ;
V_5 = V_10 -> V_11 [ V_2 -> V_12 ] ;
if ( ! F_2 ( & V_5 -> V_13 ) ) {
F_11 ( & V_10 -> V_33 ) ;
return;
}
F_8 ( & V_5 -> V_34 ) ;
F_9 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
if ( V_40 -> V_43 -> V_44 . V_45 != 0 ) {
* V_19 = V_22 -> V_31 ;
* V_20 = V_22 -> V_32 ;
break;
}
if ( V_42 ) {
* V_19 = V_22 -> V_31 ;
* V_20 = V_22 -> V_32 ;
V_42 = 0 ;
}
F_19 ( & V_22 -> V_29 ) ;
F_12 ( V_25 , V_22 ) ;
F_20 ( & V_5 -> V_13 ) ;
F_21 () ;
}
F_10 ( & V_5 -> V_34 ) ;
F_11 ( & V_10 -> V_33 ) ;
F_17 ( L_4
L_5
L_6 ,
V_10 -> V_36 -> V_37 -> V_38 () ,
( V_40 -> V_43 -> V_44 . V_45 != 0 ) ? L_7 :
L_8 , V_40 -> V_43 -> V_44 . V_45 ,
V_2 -> V_12 , V_2 -> V_46 [ 0 ] , * V_19 , * V_20 ) ;
}
int F_23 (
struct V_1 * V_2 ,
T_2 * V_19 ,
T_2 * V_20 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_21 * V_22 = NULL , * V_23 ;
int V_42 = 1 ;
if ( ! V_7 )
return - V_17 ;
V_10 = V_7 -> V_9 ;
if ( ! V_10 )
return - V_17 ;
F_7 ( & V_10 -> V_33 ) ;
V_5 = V_10 -> V_11 [ V_2 -> V_12 ] ;
if ( ! F_2 ( & V_5 -> V_13 ) ) {
F_11 ( & V_10 -> V_33 ) ;
return - V_47 ;
}
F_8 ( & V_5 -> V_34 ) ;
F_9 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
if ( V_42 ) {
* V_19 = V_22 -> V_31 ;
* V_20 = V_22 -> V_32 ;
V_42 = 0 ;
}
F_19 ( & V_22 -> V_29 ) ;
F_12 ( V_25 , V_22 ) ;
F_20 ( & V_5 -> V_13 ) ;
F_21 () ;
}
F_10 ( & V_5 -> V_34 ) ;
F_11 ( & V_10 -> V_33 ) ;
F_17 ( L_9
L_10
L_11 , V_10 -> V_36 -> V_37 -> V_38 () ,
V_2 -> V_12 , * V_19 , * V_20 ) ;
return ( V_42 ) ? - V_47 : 0 ;
}
