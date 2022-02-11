static int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_4 V_4 )
{
int type ;
T_3 * V_5 ;
V_5 = F_2 (
V_3 , V_1 , 0 , - 1 , V_6 , NULL , V_7 ) ;
type = F_3 ( V_2 ) ;
switch( type ) {
case V_8 :
F_4 (
V_1 ,
V_2 ,
V_5 , NULL ) ;
break;
case V_9 :
F_5 (
V_1 ,
V_2 ,
V_5 , NULL ) ;
break;
default:
break;
}
return F_6 ( V_1 , 0 ) ;
}
static T_5
F_7 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_4 V_4 )
{
T_6 * volatile V_10 = NULL ;
volatile T_5 V_11 = FALSE ;
int type ;
type = F_3 ( V_2 ) ;
switch( type ) {
case V_8 :
F_8 {
F_4 (
V_1 ,
V_2 ,
NULL , NULL ) ;
V_11 = TRUE ; }
F_9 {
V_11 = FALSE ; }
V_12 ;
break;
case V_9 :
F_8 {
F_5 (
V_1 ,
V_2 ,
NULL , NULL ) ;
V_11 = TRUE ; }
F_9 {
V_11 = FALSE ; }
V_12 ;
break;
default:
break;
}
if ( V_11 == TRUE ) {
if( ( V_2 -> V_13 ) &&
( ! V_2 -> V_14 ) ) {
V_10 = F_10 (
& V_2 -> V_15 ,
V_2 -> V_13 ,
& V_2 -> V_16 ) ;
}
if( ( ! V_2 -> V_13 ) &&
( V_2 -> V_14 ) ) {
V_10 = F_10 (
& V_2 -> V_16 ,
V_2 -> V_14 ,
& V_2 -> V_15 ) ;
}
if( ( V_2 -> V_13 ) &&
( V_2 -> V_14 ) ) {
V_10 = F_10 (
& V_2 -> V_16 ,
V_2 -> V_14 ,
& V_2 -> V_15 ) ;
}
if( V_10 ) {
V_10 -> V_17 = V_18 ;
}
F_1 (
V_1 ,
V_2 ,
V_3 ,
NULL ) ;
}
return V_11 ;
}
void F_11 ( void )
{
static T_7 V_19 [] = {
#include "packet-atn-cm-hfarr.c"
} ;
static T_8 * V_20 [] = {
#include "packet-atn-cm-ettarr.c"
& V_6
} ;
V_21 = F_12 (
V_7 ,
L_1 ,
L_2 ) ;
F_13 (
V_21 ,
V_19 ,
F_14 ( V_19 ) ) ;
F_15 (
V_20 ,
F_14 ( V_20 ) ) ;
F_16 (
L_2 ,
F_1 ,
V_21 ) ;
}
void F_17 ( void )
{
F_18 (
L_3 ,
F_7 ,
L_4 ,
L_5 ,
V_21 , V_22 ) ;
}
