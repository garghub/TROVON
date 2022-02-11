static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_6 ;
bool V_7 = false ;
F_2 () ;
if ( V_4 -> V_8 [ V_5 ] . V_9 & V_10 )
V_7 = true ;
V_6 = F_3 ( V_7 ) ;
if ( V_6 )
return V_6 ;
F_4 () ;
return V_5 ;
}
static int F_5 ( struct V_11 * V_12 )
{
F_3 = V_12 -> V_2 . V_13 ;
if ( ! strcmp ( V_12 -> V_2 . V_14 -> V_15 , L_1 ) )
return F_6 ( & V_16 , NULL ) ;
else if ( ! strcmp ( V_12 -> V_2 . V_14 -> V_15 , L_2 ) )
return F_6 ( & V_17 , NULL ) ;
else if ( ! strcmp ( V_12 -> V_2 . V_14 -> V_15 , L_3 ) )
return F_6 ( & V_18 , NULL ) ;
else
return - V_19 ;
}
