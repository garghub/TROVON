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
F_2 () ;
V_4 = F_3 ( V_9 , V_2 -> V_10 ) ;
if ( ! V_4 ) {
F_4 () ;
return 0 ;
}
if ( ! F_5 ( & V_4 -> V_11 ) ) {
F_4 () ;
return 0 ;
}
F_4 () ;
switch ( V_2 -> V_12 [ 0 ] ) {
case V_13 :
case V_14 :
case V_15 :
return 0 ;
default:
return V_16 ;
}
}
int F_6 (
struct V_3 * V_4 ,
T_2 V_17 ,
T_2 V_18 )
{
struct V_19 * V_20 , * V_21 , * V_22 ;
V_20 = F_7 ( V_23 , V_24 ) ;
if ( ! V_20 ) {
F_8 ( L_1 ) ;
return - V_25 ;
}
F_9 ( & V_20 -> V_26 ) ;
V_20 -> V_27 = V_17 ;
V_20 -> V_28 = V_18 ;
F_10 ( & V_4 -> V_29 ) ;
F_11 (ua_p, ua_tmp, &deve->ua_list, ua_nacl_list) {
if ( ( V_21 -> V_27 == V_17 ) && ( V_21 -> V_28 == V_18 ) ) {
F_12 ( & V_4 -> V_29 ) ;
F_13 ( V_23 , V_20 ) ;
return 0 ;
}
if ( V_21 -> V_27 == 0x29 ) {
if ( ( V_17 == 0x29 ) && ( V_18 > V_21 -> V_28 ) )
F_14 ( & V_20 -> V_26 ,
& V_4 -> V_30 ) ;
else
F_15 ( & V_20 -> V_26 ,
& V_4 -> V_30 ) ;
} else if ( V_21 -> V_27 == 0x2a ) {
if ( ( V_17 == 0x29 ) || ( V_18 > V_21 -> V_27 ) )
F_14 ( & V_20 -> V_26 ,
& V_4 -> V_30 ) ;
else
F_15 ( & V_20 -> V_26 ,
& V_4 -> V_30 ) ;
} else
F_15 ( & V_20 -> V_26 ,
& V_4 -> V_30 ) ;
F_12 ( & V_4 -> V_29 ) ;
F_16 ( & V_4 -> V_11 ) ;
return 0 ;
}
F_15 ( & V_20 -> V_26 , & V_4 -> V_30 ) ;
F_12 ( & V_4 -> V_29 ) ;
F_17 ( L_2
L_3 , V_4 -> V_31 ,
V_17 , V_18 ) ;
F_16 ( & V_4 -> V_11 ) ;
return 0 ;
}
void F_18 ( struct V_8 * V_9 ,
T_3 V_32 , T_2 V_17 , T_2 V_18 )
{
struct V_3 * V_4 ;
if ( ! V_9 )
return;
F_2 () ;
V_4 = F_3 ( V_9 , V_32 ) ;
if ( ! V_4 ) {
F_4 () ;
return;
}
F_6 ( V_4 , V_17 , V_18 ) ;
F_4 () ;
}
void F_19 (
struct V_3 * V_4 )
{
struct V_19 * V_20 , * V_21 ;
F_10 ( & V_4 -> V_29 ) ;
F_11 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
F_20 ( & V_20 -> V_26 ) ;
F_13 ( V_23 , V_20 ) ;
F_21 ( & V_4 -> V_11 ) ;
}
F_12 ( & V_4 -> V_29 ) ;
}
void F_22 (
struct V_1 * V_2 ,
T_2 * V_17 ,
T_2 * V_18 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_19 * V_20 = NULL , * V_21 ;
int V_36 = 1 ;
if ( ! V_6 )
return;
V_9 = V_6 -> V_8 ;
if ( ! V_9 )
return;
F_2 () ;
V_4 = F_3 ( V_9 , V_2 -> V_10 ) ;
if ( ! V_4 ) {
F_4 () ;
return;
}
if ( ! F_5 ( & V_4 -> V_11 ) ) {
F_4 () ;
return;
}
F_10 ( & V_4 -> V_29 ) ;
F_11 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
if ( V_34 -> V_37 . V_38 != 0 ) {
* V_17 = V_20 -> V_27 ;
* V_18 = V_20 -> V_28 ;
break;
}
if ( V_36 ) {
* V_17 = V_20 -> V_27 ;
* V_18 = V_20 -> V_28 ;
V_36 = 0 ;
}
F_20 ( & V_20 -> V_26 ) ;
F_13 ( V_23 , V_20 ) ;
F_21 ( & V_4 -> V_11 ) ;
}
F_12 ( & V_4 -> V_29 ) ;
F_4 () ;
F_17 ( L_4
L_5
L_6 ,
V_9 -> V_39 -> V_40 -> V_41 () ,
( V_34 -> V_37 . V_38 != 0 ) ? L_7 :
L_8 , V_34 -> V_37 . V_38 ,
V_2 -> V_10 , V_2 -> V_12 [ 0 ] , * V_17 , * V_18 ) ;
}
int F_23 (
struct V_1 * V_2 ,
T_2 * V_17 ,
T_2 * V_18 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_19 * V_20 = NULL , * V_21 ;
int V_36 = 1 ;
if ( ! V_6 )
return - V_42 ;
V_9 = V_6 -> V_8 ;
if ( ! V_9 )
return - V_42 ;
F_2 () ;
V_4 = F_3 ( V_9 , V_2 -> V_10 ) ;
if ( ! V_4 ) {
F_4 () ;
return - V_42 ;
}
if ( ! F_5 ( & V_4 -> V_11 ) ) {
F_4 () ;
return - V_43 ;
}
F_10 ( & V_4 -> V_29 ) ;
F_11 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
if ( V_36 ) {
* V_17 = V_20 -> V_27 ;
* V_18 = V_20 -> V_28 ;
V_36 = 0 ;
}
F_20 ( & V_20 -> V_26 ) ;
F_13 ( V_23 , V_20 ) ;
F_21 ( & V_4 -> V_11 ) ;
}
F_12 ( & V_4 -> V_29 ) ;
F_4 () ;
F_17 ( L_9
L_10
L_11 , V_9 -> V_39 -> V_40 -> V_41 () ,
V_2 -> V_10 , * V_17 , * V_18 ) ;
return ( V_36 ) ? - V_43 : 0 ;
}
