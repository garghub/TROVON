static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
F_2 ( V_2 -> V_4 , V_5 , L_1 ) ;
F_3 ( V_2 -> V_4 , V_6 ) ;
if ( V_3 != NULL ) {
unsigned V_7 = 0 ;
unsigned V_8 ;
T_3 * V_9 = F_4 ( V_3 , V_10 , V_1 ,
V_7 , - 1 , FALSE ) ;
T_3 * V_11 = F_5 ( V_9 , V_12 ) ;
F_4 ( V_11 , V_13 , V_1 ,
V_7 , 1 , V_14 ) ;
V_7 ++ ;
F_4 ( V_11 , V_15 , V_1 ,
V_7 , 1 , V_14 ) ;
V_7 ++ ;
V_8 = F_6 ( V_1 , V_7 ) ;
F_4 ( V_11 , V_16 , V_1 ,
V_7 , V_8 , V_14 ) ;
V_7 += V_8 ;
}
}
void
F_7 ( void )
{
static T_4 V_17 [] = {
{ & V_13 ,
{ L_2 ,
L_3 ,
V_18 , V_19 , NULL , 0x0 ,
NULL , V_20 } } ,
{ & V_15 ,
{ L_4 ,
L_5 ,
V_18 , V_19 , NULL , 0x0 ,
NULL , V_20 } } ,
{ & V_16 ,
{ L_6 ,
L_7 ,
V_21 , V_22 , NULL , 0x0 ,
NULL , V_20 } } ,
} ;
static T_5 * V_23 [] = {
& V_12
} ;
V_10 = F_8 ( L_8 , L_8 , L_9 ) ;
F_9 ( V_10 , V_17 , F_10 ( V_17 ) ) ;
F_11 ( V_23 , F_10 ( V_23 ) ) ;
F_12 ( L_9 , F_1 , V_10 ) ;
}
void
F_13 ( void )
{
}
