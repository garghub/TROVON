static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_3 * V_5 ;
T_5 * V_6 ;
int V_7 = 0 ;
if ( ( F_2 ( F_3 ( V_1 , 0 ) , V_8 ) == NULL ) ||
( F_2 ( F_4 ( V_1 , 3 ) , V_9 ) == NULL ) )
return 0 ;
F_5 ( V_2 -> V_10 , V_11 , L_1 ) ;
F_5 ( V_2 -> V_10 , V_12 , L_2 ) ;
if ( V_3 ) {
V_6 = F_6 ( V_3 , V_13 , V_1 , 0 , - 1 , V_14 ) ;
V_5 = F_7 ( V_6 , V_15 ) ;
F_6 ( V_5 , V_16 , V_1 , V_7 , 1 , V_17 ) ;
V_7 += 1 ;
F_6 ( V_5 , V_18 , V_1 , V_7 , 2 , V_17 ) ;
V_7 += 2 ;
F_6 ( V_5 , V_19 , V_1 , V_7 , 2 , V_17 ) ;
V_7 += 2 ;
F_6 ( V_5 , V_20 , V_1 , V_7 , 2 , V_17 ) ;
V_7 += 2 ;
F_6 ( V_5 , V_21 , V_1 , V_7 , 4 , V_17 ) ;
V_7 += 4 ;
F_6 ( V_5 , V_22 , V_1 , V_7 , - 1 , V_23 | V_14 ) ;
}
return F_8 ( V_1 ) ;
}
void
F_9 ( void )
{
static T_6 V_24 [] = {
{ & V_16 , {
L_3 , L_4 , V_25 , V_26 ,
F_10 ( V_8 ) , 0 , L_5 , V_27 } } ,
{ & V_18 , {
L_6 , L_7 , V_28 , V_26 ,
NULL , 0 , L_8 , V_27 } } ,
{ & V_19 , {
L_9 , L_10 , V_28 , V_29 ,
F_10 ( V_9 ) , 0 , NULL , V_27 } } ,
{ & V_20 , {
L_11 , L_12 , V_28 , V_29 ,
NULL , 0 , NULL , V_27 } } ,
{ & V_21 , {
L_13 , L_14 , V_30 , V_29 ,
NULL , 0 , NULL , V_27 } } ,
{ & V_22 , {
L_15 , L_16 , V_31 , V_32 ,
NULL , 0 , NULL , V_27 } } ,
} ;
static T_7 * V_33 [] = {
& V_15 ,
} ;
V_13 = F_11 ( L_17 , L_1 ,
L_18 ) ;
F_12 ( V_13 , V_24 , F_13 ( V_24 ) ) ;
F_14 ( V_33 , F_13 ( V_33 ) ) ;
}
void
F_15 ( void )
{
T_8 V_34 ;
V_34 = F_16 ( F_1 , V_13 ) ;
F_17 ( L_19 , V_35 , V_34 ) ;
}
