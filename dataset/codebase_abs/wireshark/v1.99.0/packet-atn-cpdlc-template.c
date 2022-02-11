static int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_4 V_4 )
{
T_3 * V_5 = NULL ;
T_5 * V_6 = NULL ;
if( ( V_2 -> V_7 ) && ( ! V_2 -> V_8 ) ) {
V_6 = F_2 (
& V_2 -> V_9 ,
V_2 -> V_7 ,
& V_2 -> V_10 ) ;
}
if( ( ! V_2 -> V_7 ) && ( V_2 -> V_8 ) ) {
V_6 = F_2 (
& V_2 -> V_10 ,
V_2 -> V_8 ,
& V_2 -> V_9 ) ;
}
if( ( V_2 -> V_7 ) && ( V_2 -> V_8 ) ) {
V_6 = F_2 (
& V_2 -> V_10 ,
V_2 -> V_8 ,
& V_2 -> V_9 ) ;
}
if( ! V_6 ) {
return 0 ; }
V_5 = F_3 (
V_3 , V_1 , 0 , - 1 , V_11 , NULL ,
V_12 ) ;
switch( V_6 -> V_13 ) {
case V_14 :
if( F_4 ( V_2 ) == V_15 ) {
F_5 (
V_1 ,
V_2 ,
V_5 ) ;
} else {
F_6 (
V_1 ,
V_2 ,
V_5 ) ;
}
break;
case V_16 :
if( F_4 ( V_2 ) == V_15 ) {
F_7 (
V_1 ,
V_2 ,
V_5 ) ;
} else {
F_8 (
V_1 ,
V_2 ,
V_5 ) ;
}
break;
default:
break;
}
return F_9 ( V_1 , 0 ) ;
}
static T_6
F_10 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_4 V_4 )
{
T_5 * V_6 = NULL ;
volatile T_6 V_17 = FALSE ;
volatile T_6 V_18 = FALSE ;
int type ;
type = F_4 ( V_2 ) ;
switch( type ) {
case V_15 :
F_11 {
F_5 ( V_1 , V_2 , NULL ) ;
V_17 = TRUE ;
V_18 = TRUE ;
break; }
F_12 {
V_17 = FALSE ;
V_18 = FALSE ; }
V_19 ;
F_11 {
F_7 ( V_1 , V_2 , NULL ) ;
V_18 = FALSE ;
V_17 = TRUE ;
break; }
F_12 {
V_17 = FALSE ;
V_18 = FALSE ; }
V_19 ;
break;
case V_20 :
F_11 {
F_6 ( V_1 , V_2 , NULL ) ;
V_17 = TRUE ;
V_18 = TRUE ;
break; }
F_12 {
V_17 = FALSE ;
V_18 = FALSE ; }
V_19 ;
F_11 {
F_8 ( V_1 , V_2 , NULL ) ;
V_17 = TRUE ;
V_18 = FALSE ;
break; }
F_12 {
V_17 = FALSE ;
V_18 = FALSE ; }
V_19 ;
break;
default:
break;
}
if( V_17 ) {
if( ( V_2 -> V_7 ) && ( ! V_2 -> V_8 ) ) {
V_6 = F_2 ( & V_2 -> V_9 ,
V_2 -> V_7 ,
& V_2 -> V_10 ) ;
}
if( ( ! V_2 -> V_7 ) && ( V_2 -> V_8 ) ) {
V_6 = F_2 ( & V_2 -> V_10 ,
V_2 -> V_8 ,
& V_2 -> V_9 ) ;
}
if( ( V_2 -> V_7 ) && ( V_2 -> V_8 ) ) {
V_6 = F_2 ( & V_2 -> V_10 ,
V_2 -> V_8 ,
& V_2 -> V_9 ) ;
}
if( V_6 ) {
if( V_18 == TRUE ) {
V_6 -> V_13 = V_14 ; }
else {
V_6 -> V_13 = V_16 ; }
F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
} else {
V_17 = FALSE ;
}
return V_17 ;
}
void F_13 ( void )
{
static T_7 V_21 [] = {
#include "packet-atn-cpdlc-hfarr.c"
} ;
static T_8 * V_22 [] = {
#include "packet-atn-cpdlc-ettarr.c"
& V_11
} ;
V_23 = F_14 (
V_12 ,
L_1 ,
L_2 ) ;
F_15 (
V_23 ,
V_21 ,
F_16 ( V_21 ) ) ;
F_17 (
V_22 ,
F_16 ( V_22 ) ) ;
F_18 (
L_2 ,
F_1 ,
V_23 ) ;
}
void F_19 ( void )
{
F_20 (
L_3 ,
F_10 ,
V_23 ) ;
}
