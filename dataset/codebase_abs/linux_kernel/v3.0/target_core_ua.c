int F_1 (
struct V_1 * V_2 ,
unsigned char * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
if ( ! ( V_7 ) )
return 0 ;
V_10 = V_7 -> V_9 ;
if ( ! ( V_10 ) )
return 0 ;
V_5 = & V_10 -> V_11 [ V_2 -> V_12 ] ;
if ( ! ( F_2 ( & V_5 -> V_13 ) ) )
return 0 ;
switch ( V_3 [ 0 ] ) {
case V_14 :
case V_15 :
case V_16 :
return 0 ;
default:
return - 1 ;
}
return - 1 ;
}
int F_3 (
struct V_9 * V_10 ,
T_1 V_17 ,
T_2 V_18 ,
T_2 V_19 )
{
struct V_4 * V_5 ;
struct V_20 * V_21 , * V_22 , * V_23 ;
if ( ! ( V_10 ) )
return - 1 ;
V_21 = F_4 ( V_24 , V_25 ) ;
if ( ! ( V_21 ) ) {
F_5 ( V_26 L_1 ) ;
return - 1 ;
}
F_6 ( & V_21 -> V_27 ) ;
F_6 ( & V_21 -> V_28 ) ;
V_21 -> V_29 = V_10 ;
V_21 -> V_30 = V_18 ;
V_21 -> V_31 = V_19 ;
F_7 ( & V_10 -> V_32 ) ;
V_5 = & V_10 -> V_11 [ V_17 ] ;
F_8 ( & V_5 -> V_33 ) ;
F_9 (ua_p, ua_tmp, &deve->ua_list, ua_nacl_list) {
if ( ( V_22 -> V_30 == V_18 ) && ( V_22 -> V_31 == V_19 ) ) {
F_10 ( & V_5 -> V_33 ) ;
F_11 ( & V_10 -> V_32 ) ;
F_12 ( V_24 , V_21 ) ;
return 0 ;
}
if ( V_22 -> V_30 == 0x29 ) {
if ( ( V_18 == 0x29 ) && ( V_19 > V_22 -> V_31 ) )
F_13 ( & V_21 -> V_28 ,
& V_5 -> V_34 ) ;
else
F_14 ( & V_21 -> V_28 ,
& V_5 -> V_34 ) ;
} else if ( V_22 -> V_30 == 0x2a ) {
if ( ( V_18 == 0x29 ) || ( V_19 > V_22 -> V_30 ) )
F_13 ( & V_21 -> V_28 ,
& V_5 -> V_34 ) ;
else
F_14 ( & V_21 -> V_28 ,
& V_5 -> V_34 ) ;
} else
F_14 ( & V_21 -> V_28 ,
& V_5 -> V_34 ) ;
F_10 ( & V_5 -> V_33 ) ;
F_11 ( & V_10 -> V_32 ) ;
F_15 ( & V_5 -> V_13 ) ;
F_16 () ;
return 0 ;
}
F_14 ( & V_21 -> V_28 , & V_5 -> V_34 ) ;
F_10 ( & V_5 -> V_33 ) ;
F_11 ( & V_10 -> V_32 ) ;
F_5 ( V_35 L_2
L_3 ,
F_17 ( V_10 -> V_36 ) -> F_18 () , V_17 ,
V_18 , V_19 ) ;
F_15 ( & V_5 -> V_13 ) ;
F_16 () ;
return 0 ;
}
void F_19 (
struct V_4 * V_5 )
{
struct V_20 * V_21 , * V_22 ;
F_8 ( & V_5 -> V_33 ) ;
F_9 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
F_20 ( & V_21 -> V_28 ) ;
F_12 ( V_24 , V_21 ) ;
F_21 ( & V_5 -> V_13 ) ;
F_22 () ;
}
F_10 ( & V_5 -> V_33 ) ;
}
void F_23 (
struct V_1 * V_2 ,
T_2 * V_18 ,
T_2 * V_19 )
{
struct V_37 * V_38 = F_24 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_20 * V_21 = NULL , * V_22 ;
int V_39 = 1 ;
if ( ! ( V_7 ) )
return;
V_10 = V_7 -> V_9 ;
if ( ! ( V_10 ) )
return;
F_7 ( & V_10 -> V_32 ) ;
V_5 = & V_10 -> V_11 [ V_2 -> V_12 ] ;
if ( ! ( F_2 ( & V_5 -> V_13 ) ) ) {
F_11 ( & V_10 -> V_32 ) ;
return;
}
F_8 ( & V_5 -> V_33 ) ;
F_9 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
if ( F_25 ( V_38 ) -> V_40 != 0 ) {
* V_18 = V_21 -> V_30 ;
* V_19 = V_21 -> V_31 ;
break;
}
if ( V_39 ) {
* V_18 = V_21 -> V_30 ;
* V_19 = V_21 -> V_31 ;
V_39 = 0 ;
}
F_20 ( & V_21 -> V_28 ) ;
F_12 ( V_24 , V_21 ) ;
F_21 ( & V_5 -> V_13 ) ;
F_22 () ;
}
F_10 ( & V_5 -> V_33 ) ;
F_11 ( & V_10 -> V_32 ) ;
F_5 ( V_35 L_4
L_5
L_6 ,
F_17 ( V_10 -> V_36 ) -> F_18 () ,
( F_25 ( V_38 ) -> V_40 != 0 ) ? L_7 :
L_8 , F_25 ( V_38 ) -> V_40 ,
V_2 -> V_12 , F_26 ( V_2 ) -> V_41 [ 0 ] , * V_18 , * V_19 ) ;
}
int F_27 (
struct V_1 * V_2 ,
T_2 * V_18 ,
T_2 * V_19 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_20 * V_21 = NULL , * V_22 ;
int V_39 = 1 ;
if ( ! ( V_7 ) )
return - 1 ;
V_10 = V_7 -> V_9 ;
if ( ! ( V_10 ) )
return - 1 ;
F_7 ( & V_10 -> V_32 ) ;
V_5 = & V_10 -> V_11 [ V_2 -> V_12 ] ;
if ( ! ( F_2 ( & V_5 -> V_13 ) ) ) {
F_11 ( & V_10 -> V_32 ) ;
return - 1 ;
}
F_8 ( & V_5 -> V_33 ) ;
F_9 (ua, ua_p, &deve->ua_list, ua_nacl_list) {
if ( V_39 ) {
* V_18 = V_21 -> V_30 ;
* V_19 = V_21 -> V_31 ;
V_39 = 0 ;
}
F_20 ( & V_21 -> V_28 ) ;
F_12 ( V_24 , V_21 ) ;
F_21 ( & V_5 -> V_13 ) ;
F_22 () ;
}
F_10 ( & V_5 -> V_33 ) ;
F_11 ( & V_10 -> V_32 ) ;
F_5 ( V_35 L_9
L_10
L_11 , F_17 ( V_10 -> V_36 ) -> F_18 () ,
V_2 -> V_12 , * V_18 , * V_19 ) ;
return ( V_39 ) ? - 1 : 0 ;
}
