int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 ;
struct V_7 * V_7 ;
F_2 ( 3 , NULL , L_1 , V_2 , V_4 ) ;
V_5 = - V_8 ;
if ( V_4 -> V_9 [ V_10 ] == NULL ) {
F_3 ( V_11 L_2
L_3 ) ;
goto V_12;
}
V_6 = F_4 ( V_4 -> V_9 [ V_10 ] ) ;
V_7 = F_5 ( V_4 , V_6 ) ;
if ( V_7 == NULL )
goto V_12;
V_5 = F_6 ( V_7 ) ;
F_7 ( V_7 -> V_13 ) ;
V_12:
F_8 ( 3 , NULL , L_4 , V_2 , V_4 , V_5 ) ;
return V_5 ;
}
