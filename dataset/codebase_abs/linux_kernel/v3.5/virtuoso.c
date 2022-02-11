static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( F_2 ( V_2 , V_4 ) >= 0 )
return 0 ;
if ( F_3 ( V_2 , V_4 ) >= 0 )
return 0 ;
if ( F_4 ( V_2 , V_4 ) >= 0 )
return 0 ;
return - V_5 ;
}
static int T_1 F_5 ( struct V_6 * V_7 ,
const struct V_3 * V_8 )
{
static int V_9 ;
int V_10 ;
if ( V_9 >= V_11 )
return - V_12 ;
if ( ! V_13 [ V_9 ] ) {
++ V_9 ;
return - V_14 ;
}
V_10 = F_6 ( V_7 , V_15 [ V_9 ] , V_4 [ V_9 ] , V_16 ,
V_17 , F_1 ) ;
if ( V_10 >= 0 )
++ V_9 ;
return V_10 ;
}
