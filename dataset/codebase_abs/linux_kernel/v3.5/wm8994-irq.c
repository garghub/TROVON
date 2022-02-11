int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
if ( ! V_1 -> V_3 ) {
F_2 ( V_1 -> V_4 ,
L_1 ) ;
V_1 -> V_5 = 0 ;
return 0 ;
}
V_2 = F_3 ( V_1 -> V_6 , V_1 -> V_3 ,
V_7 | V_8 ,
V_1 -> V_5 , & V_9 ,
& V_1 -> V_10 ) ;
if ( V_2 != 0 ) {
F_4 ( V_1 -> V_4 , L_2 , V_2 ) ;
return V_2 ;
}
F_5 ( V_1 , V_11 , 0 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_1 )
{
F_7 ( V_1 -> V_3 , V_1 -> V_10 ) ;
}
