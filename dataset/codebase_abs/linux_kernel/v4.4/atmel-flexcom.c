static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_7 ;
struct V_8 * V_9 ;
void T_1 * V_10 ;
T_2 V_11 ;
int V_12 ;
V_12 = F_2 ( V_4 , L_1 , & V_11 ) ;
if ( V_12 )
return V_12 ;
if ( V_11 < V_13 ||
V_11 > V_14 )
return - V_15 ;
V_9 = F_3 ( V_2 , V_16 , 0 ) ;
V_10 = F_4 ( & V_2 -> V_5 , V_9 ) ;
if ( F_5 ( V_10 ) )
return F_6 ( V_10 ) ;
V_7 = F_7 ( & V_2 -> V_5 , NULL ) ;
if ( F_5 ( V_7 ) )
return F_6 ( V_7 ) ;
V_12 = F_8 ( V_7 ) ;
if ( V_12 )
return V_12 ;
F_9 ( F_10 ( V_11 ) , V_10 + V_17 ) ;
F_11 ( V_7 ) ;
return F_12 ( V_4 , NULL , NULL , & V_2 -> V_5 ) ;
}
