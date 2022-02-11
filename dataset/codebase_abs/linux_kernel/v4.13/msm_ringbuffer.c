struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
int V_6 ;
if ( F_2 ( ! F_3 ( V_4 ) ) )
return F_4 ( - V_7 ) ;
V_5 = F_5 ( sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 ) {
V_6 = - V_9 ;
goto V_10;
}
V_5 -> V_3 = V_3 ;
V_5 -> V_11 = F_6 ( V_3 -> V_12 , V_4 , V_13 ) ;
if ( F_7 ( V_5 -> V_11 ) ) {
V_6 = F_8 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
goto V_10;
}
V_5 -> V_14 = F_9 ( V_5 -> V_11 ) ;
if ( F_7 ( V_5 -> V_14 ) ) {
V_6 = F_8 ( V_5 -> V_14 ) ;
goto V_10;
}
V_5 -> V_15 = V_5 -> V_14 + ( V_4 / 4 ) ;
V_5 -> V_16 = V_5 -> V_14 ;
V_5 -> V_4 = V_4 ;
return V_5 ;
V_10:
if ( V_5 )
F_10 ( V_5 ) ;
return F_4 ( V_6 ) ;
}
void F_10 ( struct V_1 * V_5 )
{
if ( V_5 -> V_11 ) {
F_11 ( V_5 -> V_11 ) ;
F_12 ( V_5 -> V_11 ) ;
}
F_13 ( V_5 ) ;
}
