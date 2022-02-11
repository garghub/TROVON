int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_2 -> V_5 , V_6 , 0 ,
& V_7 , & V_2 -> V_8 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_9 , V_10 , V_11 ,
F_4 ( V_11 ) , NULL , 0 ,
F_5 ( V_2 -> V_8 ) ) ;
if ( V_3 ) {
F_6 ( V_2 -> V_5 , V_2 -> V_8 ) ;
return V_3 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_5 , V_2 -> V_8 ) ;
return 0 ;
}
