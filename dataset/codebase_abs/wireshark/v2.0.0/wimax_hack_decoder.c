static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 = 0 ;
T_5 V_5 , V_6 , V_7 ;
T_6 * V_8 = NULL ;
T_3 * V_9 = NULL ;
F_2 ( V_2 -> V_10 , V_11 , NULL , L_1 ) ;
if ( V_3 )
{
V_5 = F_3 ( V_1 ) ;
V_8 = F_4 ( V_3 , V_12 , V_1 , V_4 , V_5 , L_2 , V_5 ) ;
V_9 = F_5 ( V_8 , V_13 ) ;
V_6 = F_6 ( V_1 , V_4 ) ;
F_7 ( V_9 , V_14 , V_1 , V_4 ++ , 1 , V_15 ) ;
for( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
{
F_7 ( V_9 , V_16 , V_1 , V_4 ++ , 1 , V_15 ) ;
F_7 ( V_9 , V_17 , V_1 , V_4 ++ , 1 , V_15 ) ;
F_7 ( V_9 , V_18 , V_1 , V_4 ++ , 1 , V_15 ) ;
F_7 ( V_9 , V_19 , V_1 , V_4 ++ , 1 , V_15 ) ;
}
}
}
void F_8 ( void )
{
static T_7 V_20 [] =
{
#if 0
{
&hf_hack_burst,
{"HARQ ACK Burst", "wmx.hack.burst", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{
& V_14 ,
{ L_3 , L_4 , V_21 , V_22 , NULL , 0x0 , NULL , V_23 }
} ,
{
& V_16 ,
{ L_5 , L_6 , V_21 , V_22 , NULL , 0x0 , NULL , V_23 }
} ,
{
& V_17 ,
{ L_7 , L_8 , V_21 , V_22 , NULL , 0x0 , NULL , V_23 }
} ,
{
& V_18 ,
{ L_9 , L_10 , V_21 , V_22 , F_9 ( V_24 ) , 0x0 , NULL , V_23 }
} ,
{
& V_19 ,
{ L_11 , L_12 , V_21 , V_22 , F_9 ( V_25 ) , 0x0 , NULL , V_23 }
}
} ;
static T_4 * V_26 [] =
{
& V_13 ,
} ;
V_12 = V_27 ;
F_10 ( L_13 , F_1 , - 1 ) ;
F_11 ( V_12 , V_20 , F_12 ( V_20 ) ) ;
F_13 ( V_26 , F_12 ( V_26 ) ) ;
}
