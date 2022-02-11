static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
unsigned long V_9 = 0 ;
int V_10 ;
V_8 = F_3 ( V_2 ) ;
if ( F_4 ( V_8 ) )
return F_5 ( V_8 ) ;
V_10 = F_6 ( V_8 ) ;
if ( V_10 )
return V_10 ;
if ( V_6 && V_6 -> V_11 ) {
V_10 = V_6 -> V_11 ( V_4 , V_8 -> V_12 ) ;
if ( V_10 )
goto V_13;
}
if ( F_7 ( V_4 -> V_14 , L_1 ) )
V_9 |= V_15 | V_16 ;
V_10 = F_8 ( V_2 , V_8 , & V_17 ,
V_9 , 0 , 0 ) ;
if ( V_10 )
goto V_18;
return 0 ;
V_18:
if ( V_6 && V_6 -> exit )
V_6 -> exit ( V_4 ) ;
V_13:
F_9 ( V_8 ) ;
return V_10 ;
}
