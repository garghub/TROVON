static int
F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
void * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_7 = V_4 ;
const struct V_2 * V_2 ;
int V_8 = 0 ;
V_6 = F_2 ( V_9 ) ;
if ( ! V_6 )
return - V_10 ;
for ( V_2 = V_3 ; V_2 -> V_11 ; V_2 ++ ) {
V_8 = V_6 -> V_12 ( V_6 , V_7 , V_1 , V_2 -> V_11 ,
V_2 -> V_13 , V_2 -> V_14 ,
V_15 ) ;
if ( V_8 < 0 )
break;
}
return V_8 ;
}
int
F_3 ( struct V_7 * V_7 , struct V_1 * V_1 , struct V_1 * V_16 )
{
if ( ! F_4 () )
return 0 ;
return F_5 ( V_1 , V_16 , NULL ,
& F_1 , V_7 ) ;
}
