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
F_9 ( V_8 , V_1 , V_4 , - 1 , L_1 ) ;
return;
}
}
}
}
void F_10 ( void ) {
static T_7 V_23 [] =
{
{ & V_18 ,
{ L_2 , L_3 , V_24 , V_25 , NULL , 0x0 , NULL , V_26 } } ,
{ & V_20 ,
{ L_4 , L_5 , V_24 , V_27 , NULL , 0x0 , NULL , V_26 } } ,
{ & V_21 ,
{ L_6 , L_7 , V_24 , V_25 , NULL , 0x0 , NULL , V_26 } } ,
{ & V_22 ,
{ L_8 , L_9 , V_24 , V_25 , NULL , 0x0 , NULL , V_26 } } ,
#include "packet-goose-hfarr.c"
} ;
static T_8 * V_28 [] = {
& V_17 ,
#include "packet-goose-ettarr.c"
} ;
V_15 = F_11 ( V_13 , V_29 , V_30 ) ;
F_12 ( L_10 , F_1 , V_15 ) ;
F_13 ( V_15 , V_23 , F_14 ( V_23 ) ) ;
F_15 ( V_28 , F_14 ( V_28 ) ) ;
}
void F_16 ( void ) {
T_9 V_31 ;
V_31 = F_17 ( L_10 ) ;
F_18 ( L_11 , V_32 , V_31 ) ;
}
