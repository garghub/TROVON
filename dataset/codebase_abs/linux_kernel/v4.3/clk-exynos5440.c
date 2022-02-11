static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
T_1 V_5 , V_6 ;
V_6 = F_2 ( V_7 + 0xbc ) ;
V_5 = F_2 ( V_7 + 0xcc ) ;
V_5 = ( V_5 & 0xffff0000 ) | ( V_6 & 0xffff ) ;
F_3 ( V_5 , V_7 + 0xcc ) ;
return V_8 ;
}
static void T_2 F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_7 = F_5 ( V_10 , 0 ) ;
if ( ! V_7 ) {
F_6 ( L_1
L_2 , V_13 ) ;
return;
}
V_12 = F_7 ( V_10 , V_7 , V_14 ) ;
if ( ! V_12 )
F_8 ( L_3 , V_13 ) ;
F_9 ( V_12 , V_15 ,
F_10 ( V_15 ) , V_16 ) ;
F_11 ( L_4 , L_5 , V_7 + 0x1c , 0x10 ) ;
F_11 ( L_6 , L_5 , V_7 + 0x20 , 0x10 ) ;
F_12 ( V_12 , V_17 ,
F_10 ( V_17 ) ) ;
F_13 ( V_12 , V_18 ,
F_10 ( V_18 ) ) ;
F_14 ( V_12 , V_19 ,
F_10 ( V_19 ) ) ;
F_15 ( V_12 , V_20 ,
F_10 ( V_20 ) ) ;
F_16 ( V_12 , V_21 ,
F_10 ( V_21 ) ) ;
F_17 ( V_10 , V_12 ) ;
if ( F_18 ( & V_22 ) )
F_19 ( L_7 ) ;
F_20 ( L_8 , F_21 ( L_9 ) ) ;
F_20 ( L_10 ) ;
}
