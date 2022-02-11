static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , int V_4 ,
int V_5 )
{
int V_6 = - V_7 ;
if ( V_1 != & V_8 )
return - V_9 ;
if ( V_4 < 0 || V_4 >= V_10 )
return - V_11 ;
F_2 ( & V_12 ) ;
if ( V_13 [ V_4 ] && F_3 ( V_13 [ V_4 ] -> V_14 ) ) {
V_6 = V_13 [ V_4 ] -> F_4 ( V_1 , V_3 , V_13 [ V_4 ] , V_5 ) ;
F_5 ( V_13 [ V_4 ] -> V_14 ) ;
}
F_6 ( & V_12 ) ;
return V_6 ;
}
int F_7 ( const struct V_15 * V_16 )
{
int V_6 ;
if ( V_16 -> V_17 < 0 || V_16 -> V_17 >= V_10 )
return - V_11 ;
V_6 = F_8 ( V_16 -> V_4 , 0 ) ;
if ( V_6 )
return V_6 ;
F_9 ( & V_12 ) ;
if ( V_13 [ V_16 -> V_17 ] )
V_6 = - V_18 ;
else
V_13 [ V_16 -> V_17 ] = V_16 ;
F_10 ( & V_12 ) ;
return V_6 ;
}
void F_11 ( const struct V_15 * V_16 )
{
F_9 ( & V_12 ) ;
V_13 [ V_16 -> V_17 ] = NULL ;
F_10 ( & V_12 ) ;
F_12 ( V_16 -> V_4 ) ;
}
int T_1 F_13 ( void )
{
return F_14 ( & V_19 ) ;
}
void F_15 ( void )
{
F_16 ( V_20 ) ;
}
