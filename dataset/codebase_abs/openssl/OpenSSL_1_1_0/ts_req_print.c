int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 ;
T_3 * V_4 ;
if ( V_2 == NULL )
return 0 ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_1 , L_1 , V_3 ) ;
F_4 ( V_1 , V_2 -> V_5 ) ;
F_3 ( V_1 , L_2 ) ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 == NULL )
F_3 ( V_1 , L_3 ) ;
else
F_6 ( V_1 , V_4 ) ;
F_3 ( V_1 , L_4 ) ;
if ( V_2 -> V_6 == NULL )
F_3 ( V_1 , L_5 ) ;
else
F_7 ( V_1 , V_2 -> V_6 ) ;
F_8 ( V_1 , L_6 , 1 ) ;
F_3 ( V_1 , L_7 ,
V_2 -> V_7 ? L_8 : L_9 ) ;
F_9 ( V_1 , V_2 -> V_8 ) ;
return 1 ;
}
