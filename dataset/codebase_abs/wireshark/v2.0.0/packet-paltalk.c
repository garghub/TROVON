static T_1
F_1 ( T_2 * T_3 V_1 , T_4 * V_2 ,
int V_3 , void * T_5 V_1 )
{
return F_2 ( V_2 , V_3 + 4 ) + V_4 ;
}
static int
F_3 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_5 , void * T_5 V_1 )
{
T_7 * V_6 = NULL ;
T_6 * V_7 = NULL ;
F_4 ( T_3 -> V_8 , V_9 , L_1 ) ;
F_5 ( T_3 -> V_8 , V_10 ) ;
if ( V_5 )
{
V_6 = F_6 ( V_5 , V_11 , V_2 , 0 , - 1 , V_12 ) ;
V_7 = F_7 ( V_6 , V_13 ) ;
F_6 ( V_7 , V_14 , V_2 , 0 , 2 , V_15 ) ;
F_6 ( V_7 , V_16 , V_2 , 2 , 2 , V_15 ) ;
F_6 ( V_7 , V_17 , V_2 , 4 , 2 , V_15 ) ;
F_6 ( V_7 , V_18 , V_2 , 6 , F_2 ( V_2 , 4 ) , V_12 ) ;
}
return F_8 ( V_2 ) ;
}
static T_8
F_9 ( T_4 * V_2 , T_2 * T_3 , T_6 * V_5 , void * T_5 )
{
T_9 V_19 , V_20 ;
if ( ( T_3 -> V_21 . type != V_22 )
|| ( T_3 -> V_23 . type != V_22 )
|| ( T_3 -> V_21 . V_24 != 4 )
|| ( T_3 -> V_23 . V_24 != 4 )
|| ! T_3 -> V_21 . T_5
|| ! T_3 -> V_23 . T_5 )
return FALSE ;
memcpy ( ( V_25 * ) & V_19 , T_3 -> V_21 . T_5 , 4 ) ;
memcpy ( ( V_25 * ) & V_20 , T_3 -> V_23 . T_5 , 4 ) ;
if ( ( ( V_19 & V_26 ) != V_27 )
&&
( ( V_20 & V_26 ) != V_27 ) )
return FALSE ;
F_10 ( V_2 , T_3 , V_5 , TRUE , V_4 ,
F_1 , F_3 , T_5 ) ;
return TRUE ;
}
void
F_11 ( void )
{
static T_10 V_28 [] = {
{ & V_14 , { L_2 , L_3 ,
V_29 , V_30 , NULL , 0x00 , NULL , V_31 } } ,
{ & V_16 , { L_4 , L_5 ,
V_32 , V_33 , NULL , 0x00 , NULL , V_31 } } ,
{ & V_17 , { L_6 , L_7 ,
V_32 , V_33 , NULL , 0x00 , NULL , V_31 } } ,
{ & V_18 , { L_8 , L_9 ,
V_34 , V_35 , NULL , 0x00 , NULL , V_31 } }
} ;
static T_11 * V_36 [] = { & V_13 } ;
V_11 = F_12 ( L_10 , L_1 , L_11 ) ;
F_13 ( V_11 , V_28 , F_14 ( V_28 ) ) ;
F_15 ( V_36 , F_14 ( V_36 ) ) ;
}
void
F_16 ( void )
{
F_17 ( L_12 , F_9 , L_13 , L_14 , V_11 , V_37 ) ;
}
