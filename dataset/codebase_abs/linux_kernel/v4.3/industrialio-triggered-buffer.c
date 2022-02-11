int F_1 ( struct V_1 * V_2 ,
T_1 (* F_2)( int V_3 , void * V_4 ) ,
T_1 (* F_3)( int V_3 , void * V_4 ) ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_4 () ;
if ( ! V_8 ) {
V_9 = - V_10 ;
goto V_11;
}
F_5 ( V_2 , V_8 ) ;
V_2 -> V_12 = F_6 ( F_2 ,
F_3 ,
V_13 ,
V_2 ,
L_1 ,
V_2 -> V_14 ,
V_2 -> V_15 ) ;
if ( V_2 -> V_12 == NULL ) {
V_9 = - V_10 ;
goto V_16;
}
if ( V_6 )
V_2 -> V_6 = V_6 ;
else
V_2 -> V_6 = & V_17 ;
V_2 -> V_18 |= V_19 ;
return 0 ;
V_16:
F_7 ( V_2 -> V_8 ) ;
V_11:
return V_9 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 ) ;
F_7 ( V_2 -> V_8 ) ;
}
