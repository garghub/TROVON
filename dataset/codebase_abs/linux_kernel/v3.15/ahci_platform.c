static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_3 ( V_2 ) ;
if ( F_4 ( V_8 ) )
return F_5 ( V_8 ) ;
V_9 = F_6 ( V_8 ) ;
if ( V_9 )
return V_9 ;
if ( V_6 && V_6 -> V_10 ) {
V_9 = V_6 -> V_10 ( V_4 , V_8 -> V_11 ) ;
if ( V_9 )
goto V_12;
}
V_9 = F_7 ( V_2 , V_8 , & V_13 , 0 , 0 ) ;
if ( V_9 )
goto V_14;
return 0 ;
V_14:
if ( V_6 && V_6 -> exit )
V_6 -> exit ( V_4 ) ;
V_12:
F_8 ( V_8 ) ;
return V_9 ;
}
