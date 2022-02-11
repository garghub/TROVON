static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 ;
T_1 * V_7 ;
V_5 = F_2 ( V_3 , V_8 , V_1 , 0 , - 1 , V_9 ) ;
V_6 = F_3 ( V_5 , V_10 ) ;
F_2 ( V_6 , V_11 , V_1 , 0 , 1 , V_9 ) ;
V_7 = F_4 ( V_1 , 1 , F_5 ( V_1 , 3 ) ) ;
F_6 ( V_12 , V_7 , V_2 , V_3 ) ;
return F_7 ( V_1 ) ;
}
void
F_8 ( void )
{
static T_6 V_13 [] = {
{ & V_11 ,
{ L_1 ,
L_2 ,
V_14 , V_15 , NULL , 0x0 ,
NULL ,
V_16 }
} ,
#if 0
{ &hf_openthread_psdu,
{ "PSDU",
"openthread.psdu",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL,
HFILL }
}
#endif
} ;
static T_7 * V_17 [] = {
& V_10
} ;
V_8 = F_9 ( L_3 , L_3 , L_4 ) ;
F_10 ( V_8 , V_13 , F_11 ( V_13 ) ) ;
F_12 ( V_17 , F_11 ( V_17 ) ) ;
V_18 = F_13 ( L_4 , F_1 , V_8 ) ;
}
void
F_14 ( void )
{
V_12 = F_15 ( L_5 , V_8 ) ;
F_16 ( L_6 , V_18 ) ;
}
