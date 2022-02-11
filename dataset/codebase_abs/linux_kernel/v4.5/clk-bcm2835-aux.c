static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
const char * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
void T_1 * V_12 , * V_13 ;
V_9 = F_2 ( V_4 , NULL ) ;
if ( F_3 ( V_9 ) )
return F_4 ( V_9 ) ;
V_7 = F_5 ( V_9 ) ;
V_11 = F_6 ( V_2 , V_14 , 0 ) ;
V_12 = F_7 ( V_4 , V_11 ) ;
if ( ! V_12 )
return - V_15 ;
V_6 = F_8 ( V_4 , sizeof( * V_6 ) , V_16 ) ;
if ( ! V_6 )
return - V_17 ;
V_6 -> V_18 = V_19 ;
V_6 -> V_20 = F_9 ( V_4 , V_19 ,
sizeof( * V_6 -> V_20 ) , V_16 ) ;
if ( ! V_6 -> V_20 )
return - V_17 ;
V_13 = V_12 + V_21 ;
V_6 -> V_20 [ V_22 ] =
F_10 ( V_4 , L_1 , V_7 , 0 , V_13 , 0 , 0 , NULL ) ;
V_6 -> V_20 [ V_23 ] =
F_10 ( V_4 , L_2 , V_7 , 0 , V_13 , 1 , 0 , NULL ) ;
V_6 -> V_20 [ V_24 ] =
F_10 ( V_4 , L_3 , V_7 , 0 , V_13 , 2 , 0 , NULL ) ;
F_11 ( V_2 -> V_4 . V_25 , V_26 , V_6 ) ;
return 0 ;
}
