static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_7 = F_5 ( V_6 ) ;
if ( V_7 )
return V_7 ;
if ( F_6 ( V_4 -> V_8 , L_1 ) )
V_6 -> V_9 |= V_10 | V_11 ;
V_7 = F_7 ( V_2 , V_6 , & V_12 ,
& V_13 ) ;
if ( V_7 )
goto V_14;
return 0 ;
V_14:
F_8 ( V_6 ) ;
return V_7 ;
}
