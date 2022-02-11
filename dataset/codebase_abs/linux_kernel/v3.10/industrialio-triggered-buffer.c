int F_1 ( struct V_1 * V_2 ,
T_1 (* F_2)( int V_3 , void * V_4 ) ,
T_1 (* F_3)( int V_3 , void * V_4 ) ,
const struct V_5 * V_6 )
{
int V_7 ;
V_2 -> V_8 = F_4 ( V_2 ) ;
if ( ! V_2 -> V_8 ) {
V_7 = - V_9 ;
goto V_10;
}
V_2 -> V_11 = F_5 ( F_2 ,
F_3 ,
V_12 ,
V_2 ,
L_1 ,
V_2 -> V_13 ,
V_2 -> V_14 ) ;
if ( V_2 -> V_11 == NULL ) {
V_7 = - V_9 ;
goto V_15;
}
if ( V_6 )
V_2 -> V_6 = V_6 ;
else
V_2 -> V_6 = & V_16 ;
V_2 -> V_17 |= V_18 ;
V_7 = F_6 ( V_2 ,
V_2 -> V_19 ,
V_2 -> V_20 ) ;
if ( V_7 )
goto V_21;
return 0 ;
V_21:
F_7 ( V_2 -> V_11 ) ;
V_15:
F_8 ( V_2 -> V_8 ) ;
V_10:
return V_7 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_7 ( V_2 -> V_11 ) ;
F_8 ( V_2 -> V_8 ) ;
}
