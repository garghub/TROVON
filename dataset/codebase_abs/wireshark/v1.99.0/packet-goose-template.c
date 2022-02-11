static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
int V_5 ;
T_4 V_6 ;
T_5 * V_7 = NULL ;
T_3 * V_8 = NULL ;
T_6 V_9 ;
F_2 ( & V_9 , V_10 , TRUE , V_2 ) ;
F_3 ( V_2 -> V_11 , V_12 , V_13 ) ;
F_4 ( V_2 -> V_11 , V_14 ) ;
if ( V_3 ) {
V_7 = F_5 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_8 = F_6 ( V_7 , V_17 ) ;
F_5 ( V_8 , V_18 , V_1 , V_4 , 2 , V_19 ) ;
V_6 = F_7 ( V_1 , V_4 + 2 ) ;
F_5 ( V_8 , V_20 , V_1 , V_4 + 2 , 2 , V_19 ) ;
F_5 ( V_8 , V_21 , V_1 , V_4 + 4 , 2 , V_19 ) ;
F_5 ( V_8 , V_22 , V_1 , V_4 + 6 , 2 , V_19 ) ;
V_4 = 8 ;
while ( V_4 < V_6 ) {
V_5 = V_4 ;
V_4 = F_8 ( FALSE , V_1 , V_4 , & V_9 , V_8 , - 1 ) ;
if ( V_4 == V_5 ) {
F_9 ( V_8 , V_2 , & V_23 , V_1 , V_4 , - 1 ) ;
return;
}
}
}
}
void F_10 ( void ) {
static T_7 V_24 [] =
{
{ & V_18 ,
{ L_1 , L_2 , V_25 , V_26 , NULL , 0x0 , NULL , V_27 } } ,
{ & V_20 ,
{ L_3 , L_4 , V_25 , V_28 , NULL , 0x0 , NULL , V_27 } } ,
{ & V_21 ,
{ L_5 , L_6 , V_25 , V_26 , NULL , 0x0 , NULL , V_27 } } ,
{ & V_22 ,
{ L_7 , L_8 , V_25 , V_26 , NULL , 0x0 , NULL , V_27 } } ,
#include "packet-goose-hfarr.c"
} ;
static T_8 * V_29 [] = {
& V_17 ,
#include "packet-goose-ettarr.c"
} ;
static T_9 V_30 [] = {
{ & V_31 , { L_9 , V_32 , V_33 , L_10 , V_34 } } ,
{ & V_23 , { L_11 , V_35 , V_36 , L_12 , V_34 } } ,
} ;
T_10 * V_37 ;
V_15 = F_11 ( V_13 , V_38 , V_39 ) ;
F_12 ( L_13 , F_1 , V_15 ) ;
F_13 ( V_15 , V_24 , F_14 ( V_24 ) ) ;
F_15 ( V_29 , F_14 ( V_29 ) ) ;
V_37 = F_16 ( V_15 ) ;
F_17 ( V_37 , V_30 , F_14 ( V_30 ) ) ;
}
void F_18 ( void ) {
T_11 V_40 ;
V_40 = F_19 ( L_13 ) ;
F_20 ( L_14 , V_41 , V_40 ) ;
}
