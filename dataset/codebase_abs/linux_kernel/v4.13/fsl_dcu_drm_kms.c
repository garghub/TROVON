int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 -> V_5 . V_6 = 0 ;
V_2 -> V_4 -> V_5 . V_7 = 0 ;
V_2 -> V_4 -> V_5 . V_8 = 2031 ;
V_2 -> V_4 -> V_5 . V_9 = 2047 ;
V_2 -> V_4 -> V_5 . V_10 = & V_11 ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
goto V_12;
V_3 = F_4 ( V_2 , & V_2 -> V_13 ) ;
if ( V_3 )
goto V_12;
V_3 = F_5 ( V_2 ) ;
if ( V_3 )
goto V_12;
F_6 ( V_2 -> V_4 ) ;
F_7 ( V_2 -> V_4 ) ;
return 0 ;
V_12:
F_8 ( V_2 -> V_4 ) ;
return V_3 ;
}
