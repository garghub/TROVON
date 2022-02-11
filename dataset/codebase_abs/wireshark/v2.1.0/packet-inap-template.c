static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 = NULL ;
T_3 * V_6 = NULL ;
int V_7 = 0 ;
T_6 V_8 ;
F_2 ( & V_8 , V_9 , TRUE , V_2 ) ;
F_3 ( V_2 -> V_10 , V_11 , L_1 ) ;
if( V_3 ) {
V_5 = F_4 ( V_3 , V_12 , V_1 , 0 , - 1 , V_13 ) ;
V_6 = F_5 ( V_5 , V_14 ) ;
}
V_15 = F_6 ( V_1 , V_7 ) & 0x0f ;
V_16 = F_6 ( V_1 , V_7 + 1 ) + 2 ;
V_17 = 0 ;
F_7 ( TRUE , V_1 , V_7 , & V_8 , V_6 , - 1 ) ;
return V_16 ;
}
static void F_8 ( T_7 V_18 )
{
if ( V_18 ) {
F_9 ( V_18 , V_19 ) ;
}
}
static void F_10 ( T_7 V_18 )
{
if ( V_18 ) {
F_11 ( V_18 , V_19 ) ;
}
}
void F_12 ( void ) {
static T_8 V_20 = FALSE ;
static T_9 * V_21 ;
if ( ! V_20 ) {
V_20 = TRUE ;
V_19 = F_13 ( L_2 ) ;
F_14 ( L_3 , L_4 ) ;
F_14 ( L_5 , L_6 ) ;
F_14 ( L_7 , L_8 ) ;
F_14 ( L_9 , L_10 ) ;
F_14 ( L_11 , L_12 ) ;
}
else {
F_15 ( V_21 , F_8 ) ;
F_16 ( V_21 ) ;
}
V_21 = F_17 ( V_22 ) ;
F_15 ( V_21 , F_10 ) ;
}
void F_18 ( void ) {
T_10 * V_23 ;
static T_11 V_24 [] = {
{ & V_25 ,
{ L_13 , L_14 ,
V_26 , V_27 | V_28 , & V_29 , 0x7f ,
NULL , V_30 } } ,
#include "packet-inap-hfarr.c"
} ;
static T_12 * V_31 [] = {
& V_14 ,
& V_32 ,
& V_33 ,
& V_34 ,
& V_35 ,
#include "packet-inap-ettarr.c"
} ;
static T_13 V_36 [] = {
{ & V_37 , { L_15 , V_38 , V_39 , L_16 , V_40 } } ,
{ & V_41 , { L_17 , V_38 , V_39 , L_18 , V_40 } } ,
{ & V_42 , { L_19 , V_38 , V_39 , L_18 , V_40 } } ,
} ;
T_14 * V_43 ;
V_12 = F_19 ( V_44 , V_45 , V_46 ) ;
F_20 ( L_2 , F_1 , V_12 ) ;
F_21 ( V_12 , V_24 , F_22 ( V_24 ) ) ;
F_23 ( V_31 , F_22 ( V_31 ) ) ;
V_43 = F_24 ( V_12 ) ;
F_25 ( V_43 , V_36 , F_22 ( V_36 ) ) ;
F_26 ( L_20 , F_1 , V_12 , L_21 ) ;
F_27 ( & V_22 , L_22 , V_47 ) ;
V_23 = F_28 ( V_12 , F_12 ) ;
F_29 ( V_23 , L_23 ) ;
F_29 ( V_23 , L_24 ) ;
F_30 ( V_23 , L_25 , L_26 ,
L_27 ,
& V_22 , V_47 ) ;
}
