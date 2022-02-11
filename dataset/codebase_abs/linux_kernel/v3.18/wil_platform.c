void * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
void * V_5 = NULL ;
if ( ! V_4 ) {
F_2 ( V_2 , L_1 ) ;
return NULL ;
}
#ifdef F_3
V_5 = F_4 ( V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
#endif
return V_5 ;
}
