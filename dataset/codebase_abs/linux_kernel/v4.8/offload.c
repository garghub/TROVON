static T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
return F_2 ( V_2 , F_3 ( V_2 ) ) ;
}
static struct V_1 * F_4 ( struct V_1 * V_2 ,
T_2 V_5 )
{
struct V_1 * V_6 = F_5 ( - V_7 ) ;
struct V_8 * V_9 ;
V_9 = F_6 ( V_2 ) ;
if ( ! F_7 ( V_2 , sizeof( * V_9 ) ) )
goto V_10;
F_8 ( V_2 , sizeof( * V_9 ) ) ;
if ( F_9 ( V_2 , V_5 | V_11 ) ) {
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_1 * V_14 ;
V_13 -> V_15 = 0 ;
if ( V_2 -> V_16 != V_2 -> V_17 ) {
V_13 -> V_15 ++ ;
}
F_11 (skb, frag_iter)
V_13 -> V_15 ++ ;
V_6 = NULL ;
goto V_10;
}
V_6 = F_12 ( V_2 , V_5 | V_18 ) ;
if ( F_13 ( V_6 ) )
goto V_10;
if ( ! ( V_5 & V_19 ) ) {
for ( V_2 = V_6 ; V_2 ; V_2 = V_2 -> V_20 ) {
if ( V_2 -> V_3 == V_21 ) {
V_9 = F_6 ( V_2 ) ;
V_9 -> V_22 = F_1 ( V_2 ) ;
}
}
}
V_10:
return V_6 ;
}
int T_3 F_14 ( void )
{
int V_23 ;
V_23 = F_15 ( & V_24 , V_25 ) ;
if ( V_23 )
goto V_10;
V_23 = F_16 ( & V_26 , V_25 ) ;
if ( V_23 )
goto V_27;
return V_23 ;
V_27:
F_17 ( & V_24 , V_25 ) ;
V_10:
return V_23 ;
}
