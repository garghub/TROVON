static T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = 0 ;
return F_2 ( V_2 , F_3 ( V_2 ) ) ;
}
static struct V_1 * F_4 ( struct V_1 * V_2 ,
T_2 V_6 )
{
struct V_1 * V_7 = F_5 ( - V_8 ) ;
struct V_9 * V_10 ;
V_10 = F_6 ( V_2 ) ;
if ( ! F_7 ( V_2 , sizeof( * V_10 ) ) )
goto V_11;
F_8 ( V_2 , sizeof( * V_10 ) ) ;
if ( F_9 ( V_2 , V_6 | V_12 ) ) {
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_1 * V_15 ;
V_14 -> V_16 = 0 ;
if ( V_2 -> V_17 != V_2 -> V_18 ) {
V_14 -> V_16 ++ ;
}
F_11 (skb, frag_iter)
V_14 -> V_16 ++ ;
V_7 = NULL ;
goto V_11;
}
V_7 = F_12 ( V_2 , V_6 | V_19 | V_20 ) ;
if ( F_13 ( V_7 ) )
goto V_11;
if ( ! ( V_6 & V_21 ) ) {
for ( V_2 = V_7 ; V_2 ; V_2 = V_2 -> V_22 ) {
if ( V_2 -> V_3 == V_23 ) {
V_10 = F_6 ( V_2 ) ;
V_10 -> V_24 = F_1 ( V_2 ) ;
}
}
}
V_11:
return V_7 ;
}
int T_3 F_14 ( void )
{
int V_25 ;
V_25 = F_15 ( & V_26 , V_27 ) ;
if ( V_25 )
goto V_11;
V_25 = F_16 ( & V_28 , V_27 ) ;
if ( V_25 )
goto V_29;
V_30 = & V_31 ;
return V_25 ;
V_29:
F_17 ( & V_26 , V_27 ) ;
V_11:
return V_25 ;
}
