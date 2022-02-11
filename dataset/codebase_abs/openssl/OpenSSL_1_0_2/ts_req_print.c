int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 ;
T_3 * V_4 ;
const T_4 * V_5 ;
if ( V_2 == NULL )
return 0 ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_1 , L_1 , V_3 ) ;
F_4 ( V_1 , F_5 ( V_2 ) ) ;
F_3 ( V_1 , L_2 ) ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 == NULL )
F_3 ( V_1 , L_3 ) ;
else
F_7 ( V_1 , V_4 ) ;
F_3 ( V_1 , L_4 ) ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 == NULL )
F_3 ( V_1 , L_5 ) ;
else
F_9 ( V_1 , V_5 ) ;
F_10 ( V_1 , L_6 , 1 ) ;
F_3 ( V_1 , L_7 ,
F_11 ( V_2 ) ? L_8 : L_9 ) ;
F_12 ( V_1 , F_13 ( V_2 ) ) ;
return 1 ;
}
