static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 , V_5 ;
V_4 = F_2 ( V_6 ) ;
V_5 = ( ( V_4 >> 8 ) & 0xff ) + ( ( V_4 >> 16 ) & 0xff ) ;
V_5 *= V_7 ;
V_5 >>= 2 ;
return V_5 ;
}
void T_2 F_3 ( void )
{
struct V_1 * V_2 ;
V_2 = F_4 ( NULL , L_1 , NULL , 0 , V_7 ) ;
F_5 ( V_2 , L_1 , NULL ) ;
V_2 = F_6 ( NULL , L_2 , L_1 ,
& V_8 , 0 ) ;
F_5 ( V_2 , L_2 , NULL ) ;
V_2 = F_7 ( NULL , L_3 , L_2 ,
V_9 , V_10 ,
V_11 , V_12 ,
V_13 |
V_14 , & V_15 ) ;
F_5 ( V_2 , L_3 , NULL ) ;
V_2 = F_8 ( NULL , L_4 , L_3 ,
0 , 1 , 1 ) ;
F_5 ( V_2 , L_4 , NULL ) ;
V_2 = F_7 ( NULL , L_5 , L_2 ,
0 , V_10 , V_16 ,
V_17 , V_13 , & V_15 ) ;
F_5 ( V_2 , L_5 , NULL ) ;
V_2 = F_8 ( NULL , L_6 , L_5 ,
0 , 1 , 1 ) ;
F_5 ( V_2 , L_6 , NULL ) ;
V_2 = F_9 ( NULL , L_7 , L_3 ,
0 , V_6 , V_18 ,
V_19 , V_20 ,
V_21 , & V_15 ) ;
F_5 ( V_2 , L_7 , NULL ) ;
V_2 = F_8 ( NULL , L_8 , L_7 ,
0 , 1 , 1 ) ;
F_5 ( V_2 , L_8 , NULL ) ;
F_5 ( V_2 , L_9 , NULL ) ;
F_5 ( V_2 , L_10 , NULL ) ;
V_2 = F_8 ( NULL , L_11 , L_8 , 0 , 1 ,
V_22 ) ;
F_5 ( V_2 , L_11 , NULL ) ;
F_5 ( V_2 , L_12 , NULL ) ;
F_5 ( V_2 , L_13 , NULL ) ;
F_5 ( V_2 , L_14 , NULL ) ;
F_5 ( V_2 , L_15 , NULL ) ;
F_5 ( V_2 , L_16 , NULL ) ;
F_5 ( V_2 , L_17 , NULL ) ;
F_5 ( V_2 , L_18 , NULL ) ;
}
