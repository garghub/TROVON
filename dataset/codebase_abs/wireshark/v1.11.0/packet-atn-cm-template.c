static int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_4 V_4 )
{
int type = V_5 ;
T_5 * V_6 = NULL ;
T_3 * V_7 = NULL ;
V_6 = F_2 (
V_3 ,
V_1 ,
0 ,
F_3 ( V_1 , 0 ) ,
V_8 ) ;
V_7 = F_4 (
V_6 ,
V_9 ) ;
type = F_5 ( V_2 ) ;
switch( type ) {
case V_10 :
F_6 (
V_1 ,
V_2 ,
V_7 ) ;
break;
case V_11 :
F_7 (
V_1 ,
V_2 ,
V_7 ) ;
break;
default:
break;
}
return F_3 ( V_1 , 0 ) ;
}
static T_6
F_8 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
void * T_4 V_4 )
{
T_7 * V_12 = NULL ;
T_6 V_13 = FALSE ;
int type ;
type = F_5 ( V_2 ) ;
switch( type ) {
case V_10 :
F_9 {
F_6 (
V_1 ,
V_2 ,
NULL ) ;
V_13 = TRUE ; }
F_10 {
V_13 = FALSE ; }
V_14 ;
break;
case V_11 :
F_9 {
F_7 (
V_1 ,
V_2 ,
NULL ) ;
V_13 = TRUE ; }
F_10 {
V_13 = FALSE ; }
V_14 ;
break;
default:
break;
}
if ( V_13 == TRUE ) {
if( ( V_2 -> V_15 ) &&
( ! V_2 -> V_16 ) ) {
V_12 = F_11 (
& V_2 -> V_17 ,
V_2 -> V_15 ,
& V_2 -> V_18 ) ;
}
if( ( ! V_2 -> V_15 ) &&
( V_2 -> V_16 ) ) {
V_12 = F_11 (
& V_2 -> V_18 ,
V_2 -> V_16 ,
& V_2 -> V_17 ) ;
}
if( ( V_2 -> V_15 ) &&
( V_2 -> V_16 ) ) {
V_12 = F_11 (
& V_2 -> V_18 ,
V_2 -> V_16 ,
& V_2 -> V_17 ) ;
}
if( V_12 ) {
V_12 -> V_19 = V_20 ;
}
F_1 (
V_1 ,
V_2 ,
V_3 ,
NULL ) ;
}
return V_13 ;
}
void F_12 ( void )
{
static T_8 V_21 [] = {
#include "packet-atn-cm-hfarr.c"
} ;
static T_9 * V_22 [] = {
#include "packet-atn-cm-ettarr.c"
& V_9
} ;
V_23 = F_13 (
V_8 ,
L_1 ,
L_2 ) ;
F_14 (
V_23 ,
V_21 ,
F_15 ( V_21 ) ) ;
F_16 (
V_22 ,
F_15 ( V_22 ) ) ;
F_17 (
L_2 ,
F_1 ,
V_23 ) ;
}
void F_18 ( void )
{
F_19 (
L_3 ,
F_8 ,
V_23 ) ;
}
