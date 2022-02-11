struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
int V_6 ;
V_4 = F_2 ( V_4 , 4 ) ;
V_5 = F_3 ( sizeof( * V_5 ) , V_7 ) ;
if ( ! V_5 ) {
V_6 = - V_8 ;
goto V_9;
}
V_5 -> V_3 = V_3 ;
V_5 -> V_10 = F_4 ( V_3 -> V_11 , V_4 , V_12 ) ;
if ( F_5 ( V_5 -> V_10 ) ) {
V_6 = F_6 ( V_5 -> V_10 ) ;
V_5 -> V_10 = NULL ;
goto V_9;
}
V_5 -> V_13 = F_7 ( V_5 -> V_10 ) ;
if ( F_5 ( V_5 -> V_13 ) ) {
V_6 = F_6 ( V_5 -> V_13 ) ;
goto V_9;
}
V_5 -> V_14 = V_5 -> V_13 + ( V_4 / 4 ) ;
V_5 -> V_15 = V_5 -> V_13 ;
V_5 -> V_4 = V_4 ;
return V_5 ;
V_9:
if ( V_5 )
F_8 ( V_5 ) ;
return F_9 ( V_6 ) ;
}
void F_8 ( struct V_1 * V_5 )
{
if ( V_5 -> V_10 ) {
F_10 ( V_5 -> V_10 ) ;
F_11 ( V_5 -> V_10 ) ;
}
F_12 ( V_5 ) ;
}
