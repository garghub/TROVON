static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_3 * V_5 = NULL ;
T_5 * V_6 ;
T_6 V_7 ;
T_6 V_8 ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
if ( F_3 ( V_1 ) >= 8 )
{
V_7 = F_4 ( V_1 , 0 ) ;
if ( V_7 == V_11 || V_7 == V_12 )
{
V_8 = F_4 ( V_1 , 4 ) ;
F_5 ( V_2 -> V_9 , V_13 , F_6 ( V_8 , V_14 , L_2 ) ) ;
if ( V_3 )
{
V_6 = F_7 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_5 = F_8 ( V_6 , V_17 ) ;
F_7 ( V_5 , V_18 , V_1 , 0 , 4 , V_19 ) ;
F_7 ( V_5 , V_20 , V_1 , 4 , 4 , V_19 ) ;
}
}
else
{
F_2 ( V_2 -> V_9 , V_13 , L_3 ) ;
if ( V_3 )
{
F_7 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
}
}
}
return F_9 ( V_1 ) ;
}
static T_7
F_10 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
if ( F_9 ( V_1 ) >= 8 )
{
T_6 V_7 ;
V_7 = F_4 ( V_1 , 0 ) ;
if ( V_7 == V_11 || V_7 == V_12 )
{
T_8 * V_21 = NULL ;
V_21 = F_11 ( V_2 ) ;
F_12 ( V_21 , V_22 ) ;
F_1 ( V_1 , V_2 , V_3 , T_4 ) ;
return TRUE ;
}
}
return FALSE ;
}
void
F_13 ( void )
{
static T_9 V_23 [] = {
{ & V_18 ,
{ L_4 , L_5 , V_24 , V_25 , NULL , 0x0 , L_6 , V_26 } } ,
{ & V_20 ,
{ L_7 , L_8 , V_24 , V_25 , F_14 ( V_14 ) , 0x0 , L_9 , V_26 } }
} ;
static T_10 * V_27 [] = {
& V_17 ,
} ;
V_15 = F_15 ( L_10 , L_1 , L_11 ) ;
F_16 ( V_15 , V_23 , F_17 ( V_23 ) ) ;
F_18 ( V_27 , F_17 ( V_27 ) ) ;
}
void
F_19 ( void )
{
V_22 = F_20 ( F_1 , V_15 ) ;
F_21 ( L_12 , V_22 ) ;
F_22 ( L_13 , F_10 , L_14 , L_15 , V_15 , V_28 ) ;
}
