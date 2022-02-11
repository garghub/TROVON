void T_1 * F_1 ( void * V_1 , T_2 V_2 ,
struct V_3 * V_4 )
{
void * V_5 ;
if ( ! V_1 ) {
F_2 ( V_6 L_1 , V_4 -> V_7 ) ;
return NULL ;
}
V_5 = F_3 ( V_1 , V_2 , V_8 ) ;
if ( ! V_5 ) {
F_2 ( V_6 L_2 , V_4 -> V_7 ) ;
return NULL ;
}
V_4 -> V_9 . V_10 = V_5 ;
return V_5 ;
}
