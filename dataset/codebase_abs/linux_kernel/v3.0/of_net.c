const void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , L_1 , NULL ) ;
if ( V_4 && ( V_4 -> V_5 == 6 ) && F_3 ( V_4 -> V_6 ) )
return V_4 -> V_6 ;
V_4 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_4 && ( V_4 -> V_5 == 6 ) && F_3 ( V_4 -> V_6 ) )
return V_4 -> V_6 ;
V_4 = F_2 ( V_2 , L_3 , NULL ) ;
if ( V_4 && ( V_4 -> V_5 == 6 ) && F_3 ( V_4 -> V_6 ) )
return V_4 -> V_6 ;
return NULL ;
}
