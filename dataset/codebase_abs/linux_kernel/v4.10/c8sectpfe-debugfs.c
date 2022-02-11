void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 ;
V_4 = F_2 ( L_1 , NULL ) ;
if ( ! V_4 )
goto V_6;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = F_3 ( V_2 -> V_8 , sizeof( * V_2 -> V_7 ) , V_9 ) ;
if ( ! V_2 -> V_7 )
goto V_6;
V_2 -> V_7 -> V_10 = V_11 ;
V_2 -> V_7 -> V_12 = F_4 ( V_11 ) ;
V_2 -> V_7 -> V_13 = V_2 -> V_14 ;
V_5 = F_5 ( L_2 , V_15 , V_4 ,
V_2 -> V_7 ) ;
if ( ! V_5 ) {
F_6 ( V_2 -> V_8 ,
L_3
, V_16 ) ;
goto V_6;
}
return;
V_6:
F_7 ( V_4 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
