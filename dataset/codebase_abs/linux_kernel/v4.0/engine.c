struct V_1 *
V_1 ( void * V_2 , int V_3 )
{
V_2 = F_1 ( V_2 , V_3 ) ;
if ( V_2 && F_2 ( V_2 , V_4 ) )
return F_3 ( V_2 ) ;
return NULL ;
}
int
F_4 ( struct V_5 * V_6 , struct V_5 * V_7 ,
struct V_8 * V_9 , bool V_10 ,
const char * V_11 , const char * V_12 ,
int V_13 , void * * V_14 )
{
struct V_1 * V_15 ;
int V_16 ;
V_16 = F_5 ( V_6 , V_7 , V_9 , V_4 ,
V_11 , V_12 , V_13 , V_14 ) ;
V_15 = * V_14 ;
if ( V_16 )
return V_16 ;
if ( V_6 ) {
struct V_17 * V_18 = F_6 ( V_6 ) ;
int V_19 = F_7 ( V_15 ) ;
if ( V_18 -> V_20 & ( 1ULL << V_19 ) ) {
if ( ! F_8 ( V_18 -> V_21 , V_11 , false ) ) {
F_9 ( V_15 , L_1 ) ;
return - V_22 ;
}
F_10 ( V_15 , L_2 ) ;
}
if ( ! F_8 ( V_18 -> V_21 , V_11 , V_10 ) ) {
if ( ! V_10 )
F_10 ( V_15 , L_3 , V_11 ) ;
return - V_22 ;
}
}
F_11 ( & V_15 -> V_23 ) ;
F_12 ( & V_15 -> V_24 ) ;
return 0 ;
}
