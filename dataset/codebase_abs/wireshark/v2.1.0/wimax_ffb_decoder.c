static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 = 0 ;
T_6 V_6 , V_7 , V_8 ;
T_7 * V_9 = NULL ;
T_3 * V_10 = NULL ;
F_2 ( V_2 -> V_11 , V_12 , NULL , L_1 ) ;
if ( V_3 )
{
V_6 = F_3 ( V_1 ) ;
V_9 = F_4 ( V_3 , V_13 , V_1 , V_5 , V_6 , L_2 , V_6 ) ;
V_10 = F_5 ( V_9 , V_14 ) ;
V_7 = F_6 ( V_1 , V_5 ) ;
F_7 ( V_10 , V_15 , V_1 , V_5 ++ , 1 , V_16 ) ;
F_7 ( V_10 , V_17 , V_1 , V_5 ++ , 1 , V_16 ) ;
for( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
{
F_7 ( V_10 , V_18 , V_1 , V_5 ++ , 1 , V_16 ) ;
F_7 ( V_10 , V_19 , V_1 , V_5 ++ , 1 , V_16 ) ;
F_7 ( V_10 , V_20 , V_1 , V_5 ++ , 1 , V_16 ) ;
}
}
return F_8 ( V_1 ) ;
}
void F_9 ( void )
{
static T_8 V_21 [] =
{
#if 0
{
&hf_ffb_burst,
{"Fast Feedback Burst", "wmx.ffb.burst", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{
& V_15 ,
{ L_3 , L_4 , V_22 , V_23 , NULL , 0x0 , NULL , V_24 }
} ,
{
& V_17 ,
{ L_5 , L_6 , V_22 , V_25 , NULL , 0x0 , NULL , V_24 }
} ,
{
& V_18 ,
{ L_7 , L_8 , V_22 , V_23 , NULL , 0x0 , NULL , V_24 }
} ,
{
& V_19 ,
{ L_9 , L_10 , V_22 , V_23 , NULL , 0x0 , NULL , V_24 }
} ,
{
& V_20 ,
{ L_11 , L_12 , V_22 , V_25 , NULL , 0x0 , NULL , V_24 }
}
} ;
static T_5 * V_26 [] =
{
& V_14 ,
} ;
V_13 = V_27 ;
F_10 ( V_13 , V_21 , F_11 ( V_21 ) ) ;
F_12 ( V_26 , F_11 ( V_26 ) ) ;
F_13 ( L_13 , F_1 , - 1 ) ;
}
