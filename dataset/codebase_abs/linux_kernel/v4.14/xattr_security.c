static int
F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
void * V_4 )
{
struct V_5 * V_5 = V_4 ;
const struct V_2 * V_2 ;
int V_6 = 0 ;
for ( V_2 = V_3 ; V_2 -> V_7 ; V_2 ++ ) {
char * V_8 ;
V_8 = F_2 ( V_9 , L_1 ,
V_10 , V_2 -> V_7 ) ;
if ( ! V_8 ) {
V_6 = - V_11 ;
break;
}
V_6 = F_3 ( V_5 , V_1 , V_8 , V_2 -> V_12 ,
V_2 -> V_13 , V_14 ) ;
F_4 ( V_8 ) ;
if ( V_6 < 0 )
break;
}
return V_6 ;
}
int
F_5 ( struct V_5 * V_5 , struct V_1 * V_1 , struct V_1 * V_15 )
{
if ( ! F_6 () )
return 0 ;
return F_7 ( V_1 , V_15 , NULL ,
& F_1 , V_5 ) ;
}
