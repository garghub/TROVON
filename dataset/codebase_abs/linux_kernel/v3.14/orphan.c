int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 V_9 ;
int V_10 = 0 ;
V_9 . V_11 = V_12 ;
F_2 ( & V_9 , V_13 ) ;
V_9 . V_5 = V_5 ;
V_7 = F_3 () ;
if ( ! V_7 )
return - V_14 ;
V_10 = F_4 ( V_2 , V_4 , V_7 , & V_9 , 0 ) ;
F_5 ( V_7 ) ;
return V_10 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 V_9 ;
int V_10 = 0 ;
V_9 . V_11 = V_12 ;
F_2 ( & V_9 , V_13 ) ;
V_9 . V_5 = V_5 ;
V_7 = F_3 () ;
if ( ! V_7 )
return - V_14 ;
V_10 = F_7 ( V_2 , V_4 , & V_9 , V_7 , - 1 , 1 ) ;
if ( V_10 < 0 )
goto V_15;
if ( V_10 ) {
V_10 = - V_16 ;
goto V_15;
}
V_10 = F_8 ( V_2 , V_4 , V_7 ) ;
V_15:
F_5 ( V_7 ) ;
return V_10 ;
}
