static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 -> V_4 . V_5 )
return - V_6 ;
V_3 = F_2 ( & V_2 -> V_4 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( & V_2 -> V_4 , L_1 ) ;
if ( V_3 )
goto V_7;
V_3 = F_3 ( & V_2 -> V_4 , L_2 ) ;
if ( V_3 )
goto V_7;
F_4 ( & V_2 -> V_4 ) ;
F_5 ( V_2 -> V_4 . V_5 , NULL , NULL , & V_2 -> V_4 ) ;
F_6 ( & V_2 -> V_4 , L_3 ) ;
return 0 ;
V_7:
F_7 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_4 ) ;
F_7 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_4 )
{
return F_11 ( V_4 ) ;
}
static int F_12 ( struct V_8 * V_4 )
{
return F_13 ( V_4 ) ;
}
