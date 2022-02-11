static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
if ( F_2 ( ( V_4 & 0xfff0 ) != V_6 ) )
return - V_7 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_8 -> V_9 ,
L_1 ) ;
return V_5 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_10 = TRUE ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = TRUE ;
V_2 -> V_14 = V_15 ;
V_5 = F_5 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_10 = FALSE ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
