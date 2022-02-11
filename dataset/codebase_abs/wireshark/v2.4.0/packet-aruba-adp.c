static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_3 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_5 type ;
const T_6 * V_7 ;
const T_6 * V_8 ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
F_3 ( V_2 -> V_9 , V_11 ) ;
if ( V_3 ) {
V_5 = F_4 ( V_3 , V_12 , V_1 , 0 , 0 , V_13 ) ;
V_6 = F_5 ( V_5 , V_14 ) ;
}
F_4 ( V_6 , V_15 , V_1 , 0 , 2 , V_16 ) ;
F_4 ( V_6 , V_17 , V_1 , 2 , 2 , V_16 ) ;
type = F_6 ( V_1 , 2 ) ;
F_4 ( V_6 , V_18 , V_1 , 4 , 2 , V_16 ) ;
switch( type ) {
case V_19 :
F_4 ( V_6 , V_20 , V_1 , 6 , 6 , V_13 ) ;
V_7 = F_7 ( V_1 , 6 ) ;
F_8 ( V_2 -> V_9 , V_11 , L_2 , V_7 ) ;
F_9 ( V_5 , L_3 , V_7 ) ;
break;
case V_21 :
F_4 ( V_6 , V_22 , V_1 , 6 , 4 , V_16 ) ;
V_8 = F_10 ( V_1 , 6 ) ;
F_8 ( V_2 -> V_9 , V_11 , L_4 , V_8 ) ;
F_9 ( V_5 , L_5 , V_8 ) ;
break;
default:
break;
}
return F_11 ( V_1 ) ;
}
void
F_12 ( void )
{
static T_7 V_23 [] = {
{ & V_15 ,
{ L_6 , L_7 , V_24 , V_25 , NULL , 0x0 ,
L_8 , V_26 } } ,
{ & V_17 ,
{ L_9 , L_10 , V_24 , V_25 , F_13 ( V_27 ) , 0x0 ,
L_11 , V_26 } } ,
{ & V_18 ,
{ L_12 , L_13 , V_24 , V_25 , NULL , 0x0 ,
L_14 , V_26 } } ,
{ & V_20 ,
{ L_15 , L_16 , V_28 , V_29 , NULL , 0x0 ,
NULL , V_26 } } ,
{ & V_22 ,
{ L_17 , L_18 , V_30 , V_29 , NULL , 0x0 ,
L_19 , V_26 } } ,
} ;
static T_8 * V_31 [] = {
& V_14 ,
} ;
V_12 = F_14 ( L_20 ,
L_1 , L_21 ) ;
F_15 ( V_12 , V_23 , F_16 ( V_23 ) ) ;
F_17 ( V_31 , F_16 ( V_31 ) ) ;
}
void
F_18 ( void )
{
T_9 V_32 ;
V_32 = F_19 ( F_1 , V_12 ) ;
F_20 ( L_22 , V_33 , V_32 ) ;
}
