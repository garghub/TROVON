static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 ;
int V_7 ;
T_6 V_8 ;
T_1 * V_9 ;
F_2 ( V_2 -> V_10 , V_11 , L_1 ) ;
F_3 ( V_2 -> V_10 , V_12 ) ;
V_7 = 0 ;
V_8 = F_4 ( V_1 , V_7 ) ;
F_5 ( V_2 -> V_10 , V_12 , L_2 , V_8 ) ;
if ( V_3 )
{
V_7 = 0 ;
V_5 = F_6 ( V_3 , V_13 , V_1 , V_7 , V_14 ,
L_3 ,
V_8 & 0xfff
) ;
V_6 = F_7 ( V_5 , V_15 ) ;
F_8 ( V_6 , V_16 , V_1 , V_7 , V_14 , V_17 ) ;
}
V_7 += V_14 ;
V_9 = F_9 ( V_1 , V_7 ) ;
F_10 ( V_18 , V_9 , V_2 , V_3 ) ;
return F_11 ( V_1 ) ;
}
static T_7
F_12 ( const T_8 * V_19 , int V_7 , int V_20 , T_9 * V_21 , const union V_22 * V_23 )
{
int V_24 ;
if ( ! F_13 ( V_7 , V_20 , V_14 ) )
return FALSE ;
V_24 = V_7 ;
V_24 += V_14 ;
return F_14 ( V_19 , V_24 , V_20 , V_21 , V_23 ) ;
}
void
F_15 ( void )
{
static T_10 V_25 [] = {
{ & V_16 ,
{ L_4 , L_5 ,
V_26 , V_27 , NULL , 0x0 ,
NULL , V_28 }
} ,
} ;
static T_11 * V_29 [] = {
& V_15 ,
} ;
V_13 = F_16 ( L_6 , L_1 , L_7 ) ;
V_30 = F_17 ( L_7 , F_1 , V_13 ) ;
F_18 ( V_13 , V_25 , F_19 ( V_25 ) ) ;
F_20 ( V_29 , F_19 ( V_29 ) ) ;
}
void
F_21 ( void )
{
F_22 ( L_8 , V_31 , V_30 ) ;
F_23 ( L_8 , V_31 , F_12 , V_13 ) ;
V_18 = F_24 ( L_9 , V_13 ) ;
}
