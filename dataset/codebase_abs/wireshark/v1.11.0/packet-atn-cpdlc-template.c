static int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_4 V_4 )
{
T_5 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_6 * V_7 = NULL ;
if( ( V_2 -> V_8 ) && ( ! V_2 -> V_9 ) ) {
V_7 = F_2 (
& V_2 -> V_10 ,
V_2 -> V_8 ,
& V_2 -> V_11 ) ;
}
if( ( ! V_2 -> V_8 ) && ( V_2 -> V_9 ) ) {
V_7 = F_2 (
& V_2 -> V_11 ,
V_2 -> V_9 ,
& V_2 -> V_10 ) ;
}
if( ( V_2 -> V_8 ) && ( V_2 -> V_9 ) ) {
V_7 = F_2 (
& V_2 -> V_11 ,
V_2 -> V_9 ,
& V_2 -> V_10 ) ;
}
if( ! V_7 ) {
return 0 ; }
V_5 = F_3 (
V_3 ,
V_1 ,
0 ,
F_4 ( V_1 , 0 ) ,
V_12 ) ;
V_6 = F_5 (
V_5 ,
V_13 ) ;
switch( V_7 -> V_14 ) {
case V_15 :
if( F_6 ( V_2 ) == V_16 ) {
F_7 (
V_1 ,
V_2 ,
V_6 ) ;
} else {
F_8 (
V_1 ,
V_2 ,
V_6 ) ;
}
break;
case V_17 :
if( F_6 ( V_2 ) == V_16 ) {
F_9 (
V_1 ,
V_2 ,
V_6 ) ;
} else {
F_10 (
V_1 ,
V_2 ,
V_6 ) ;
}
break;
default:
break;
}
return F_4 ( V_1 , 0 ) ;
}
static T_7
F_11 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_4 V_4 )
{
T_6 * V_7 = NULL ;
T_7 V_18 = FALSE ;
T_7 V_19 = FALSE ;
int type = V_20 ;
type = F_6 ( V_2 ) ;
switch( type ) {
case V_16 :
F_12 {
F_7 ( V_1 , V_2 , NULL ) ;
V_18 = TRUE ;
V_19 = TRUE ; }
break;
F_13 {
V_18 = FALSE ;
V_19 = FALSE ; }
V_21 ;
F_12 {
F_9 ( V_1 , V_2 , NULL ) ;
V_19 = FALSE ;
V_18 = TRUE ;
break; }
F_13 {
V_18 = FALSE ;
V_19 = FALSE ; }
V_21 ;
break;
case V_22 :
F_12 {
F_8 ( V_1 , V_2 , NULL ) ;
V_18 = TRUE ;
V_19 = TRUE ;
break; }
F_13 {
V_18 = FALSE ;
V_19 = FALSE ; }
V_21 ;
F_12 {
F_10 ( V_1 , V_2 , NULL ) ;
V_18 = TRUE ;
V_19 = FALSE ;
break; }
F_13 {
V_18 = FALSE ;
V_19 = FALSE ; }
V_21 ;
break;
default:
break;
}
if( V_18 ) {
if( ( V_2 -> V_8 ) && ( ! V_2 -> V_9 ) ) {
V_7 = F_2 ( & V_2 -> V_10 ,
V_2 -> V_8 ,
& V_2 -> V_11 ) ;
}
if( ( ! V_2 -> V_8 ) && ( V_2 -> V_9 ) ) {
V_7 = F_2 ( & V_2 -> V_11 ,
V_2 -> V_9 ,
& V_2 -> V_10 ) ;
}
if( ( V_2 -> V_8 ) && ( V_2 -> V_9 ) ) {
V_7 = F_2 ( & V_2 -> V_11 ,
V_2 -> V_9 ,
& V_2 -> V_10 ) ;
}
if( V_7 ) {
if( V_19 == TRUE ) {
V_7 -> V_14 = V_15 ; }
else {
V_7 -> V_14 = V_17 ; }
F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
} else {
V_18 = FALSE ;
}
return V_18 ;
}
void F_14 ( void )
{
static T_8 V_23 [] = {
#include "packet-atn-cpdlc-hfarr.c"
} ;
static T_9 * V_24 [] = {
#include "packet-atn-cpdlc-ettarr.c"
& V_13
} ;
V_25 = F_15 (
V_12 ,
L_1 ,
L_2 ) ;
F_16 (
V_25 ,
V_23 ,
F_17 ( V_23 ) ) ;
F_18 (
V_24 ,
F_17 ( V_24 ) ) ;
F_19 (
L_2 ,
F_1 ,
V_25 ) ;
}
void F_20 ( void )
{
F_21 (
L_3 ,
F_11 ,
V_25 ) ;
}
