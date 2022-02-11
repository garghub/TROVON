static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
int V_5 = 0 ;
int V_6 ;
T_5 V_7 ;
T_6 * V_8 = NULL ;
T_3 * V_9 = NULL ;
T_7 V_10 ;
F_2 ( & V_10 , V_11 , TRUE , V_2 ) ;
F_3 ( V_2 -> V_12 , V_13 , V_14 ) ;
F_4 ( V_2 -> V_12 , V_15 ) ;
V_8 = F_5 ( V_3 , V_16 , V_1 , 0 , - 1 , V_17 ) ;
V_9 = F_6 ( V_8 , V_18 ) ;
F_5 ( V_9 , V_19 , V_1 , V_5 , 2 , V_20 ) ;
V_7 = F_7 ( V_1 , V_5 + 2 ) ;
F_5 ( V_9 , V_21 , V_1 , V_5 + 2 , 2 , V_20 ) ;
F_5 ( V_9 , V_22 , V_1 , V_5 + 4 , 2 , V_20 ) ;
F_5 ( V_9 , V_23 , V_1 , V_5 + 6 , 2 , V_20 ) ;
V_5 = 8 ;
while ( V_5 < V_7 ) {
V_6 = V_5 ;
V_5 = F_8 ( FALSE , V_1 , V_5 , & V_10 , V_9 , - 1 ) ;
if ( V_5 == V_6 ) {
F_9 ( V_9 , V_2 , & V_24 , V_1 , V_5 , - 1 ) ;
break;
}
}
return F_10 ( V_1 ) ;
}
void F_11 ( void ) {
static T_8 V_25 [] =
{
{ & V_19 ,
{ L_1 , L_2 , V_26 , V_27 , NULL , 0x0 , NULL , V_28 } } ,
{ & V_21 ,
{ L_3 , L_4 , V_26 , V_29 , NULL , 0x0 , NULL , V_28 } } ,
{ & V_22 ,
{ L_5 , L_6 , V_26 , V_27 , NULL , 0x0 , NULL , V_28 } } ,
{ & V_23 ,
{ L_7 , L_8 , V_26 , V_27 , NULL , 0x0 , NULL , V_28 } } ,
#include "packet-goose-hfarr.c"
} ;
static T_9 * V_30 [] = {
& V_18 ,
#include "packet-goose-ettarr.c"
} ;
static T_10 V_31 [] = {
{ & V_32 , { L_9 , V_33 , V_34 , L_10 , V_35 } } ,
{ & V_24 , { L_11 , V_36 , V_37 , L_12 , V_35 } } ,
} ;
T_11 * V_38 ;
V_16 = F_12 ( V_14 , V_39 , V_40 ) ;
F_13 ( L_13 , F_1 , V_16 ) ;
F_14 ( V_16 , V_25 , F_15 ( V_25 ) ) ;
F_16 ( V_30 , F_15 ( V_30 ) ) ;
V_38 = F_17 ( V_16 ) ;
F_18 ( V_38 , V_31 , F_15 ( V_31 ) ) ;
}
void F_19 ( void ) {
T_12 V_41 ;
V_41 = F_20 ( L_13 ) ;
F_21 ( L_14 , V_42 , V_41 ) ;
}
