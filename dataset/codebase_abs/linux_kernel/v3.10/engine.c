int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , bool V_6 ,
const char * V_7 , const char * V_8 ,
int V_9 , void * * V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_2 ( V_2 , V_3 , V_5 , V_14 ,
V_7 , V_8 , V_9 , V_10 ) ;
V_12 = * V_10 ;
if ( V_13 )
return V_13 ;
if ( V_2 &&
! F_3 ( F_4 ( V_2 ) -> V_15 , V_7 , V_6 ) ) {
if ( ! V_6 )
F_5 ( V_12 , L_1 , V_7 ) ;
return - V_16 ;
}
F_6 ( & V_12 -> V_17 ) ;
F_7 ( & V_12 -> V_18 ) ;
return 0 ;
}
