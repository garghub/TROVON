static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
T_4 V_5 ;
T_5 * V_6 ;
T_3 * V_7 ;
F_2 ( V_2 -> V_8 , V_9 , L_1 ) ;
if ( V_3 ) {
V_6 = F_3 ( V_3 , V_10 , V_1 , 0 , - 1 , V_11 ) ;
V_7 = F_4 ( V_6 , V_12 ) ;
V_5 = F_5 ( V_1 , V_4 ) ;
F_3 ( V_7 , V_13 , V_1 , V_4 , 1 , V_14 ) ;
F_3 ( V_7 , V_15 , V_1 , V_4 , 1 , V_14 ) ;
if ( ( V_5 & 0x1 ) == 1 )
return;
}
}
void
F_6 ( void )
{
T_6 V_16 ;
V_16 = F_7 ( F_1 , V_10 ) ;
F_8 ( L_2 , V_17 , V_16 ) ;
}
void
F_9 ( void )
{
static T_7 V_18 [] = {
{ & V_13 ,
{ L_3 , L_4 ,
V_19 , V_20 , F_10 ( V_21 ) , 0x03 ,
L_5 , V_22 }
} ,
{ & V_15 ,
{ L_6 , L_7 ,
V_19 , V_20 , NULL , 0xfc ,
NULL , V_22 }
} ,
} ;
static T_8 * V_23 [] = {
& V_12 ,
} ;
V_10 = F_11 ( L_8 , L_8 , L_9 ) ;
F_12 ( V_10 , V_18 , F_13 ( V_18 ) ) ;
F_14 ( V_23 , F_13 ( V_23 ) ) ;
}
