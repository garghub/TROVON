void *
F_1 ( const struct V_1 * V_2 , const char * V_3 ,
T_1 V_4 )
{
const struct V_5 * V_6 ;
void * V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 -> V_9 , V_3 , & V_6 ) ;
if ( V_8 )
return F_3 ( V_8 ) ;
if ( V_6 -> V_10 < V_4 ) {
F_4 ( V_2 , L_1 ,
V_3 , V_4 ) ;
F_5 ( V_6 ) ;
return F_3 ( - V_11 ) ;
}
V_7 = F_6 ( V_6 -> V_12 , V_6 -> V_10 , V_13 ) ;
F_5 ( V_6 ) ;
if ( ! V_7 )
return F_3 ( - V_14 ) ;
return V_7 ;
}
