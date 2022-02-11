int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , bool V_6 ,
const char * V_7 , const char * V_8 ,
int V_9 , void * * V_10 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
int V_15 ;
V_15 = F_3 ( V_2 , V_3 , V_5 , V_16 ,
V_7 , V_8 , V_9 , V_10 ) ;
V_14 = * V_10 ;
if ( V_15 )
return V_15 ;
if ( ! F_4 ( V_12 -> V_17 , V_7 , V_6 ) ) {
if ( ! V_6 )
F_5 ( V_14 , L_1 , V_7 ) ;
return - V_18 ;
}
F_6 ( & V_14 -> V_19 ) ;
F_7 ( & V_14 -> V_20 ) ;
return 0 ;
}
