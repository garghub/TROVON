static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
int V_10 ;
T_2 V_11 ;
V_6 = F_2 ( & V_2 -> V_12 , sizeof( struct V_5 ) , V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_8 = F_3 ( V_2 , V_15 , 0 ) ;
V_9 = F_4 ( & V_2 -> V_12 , V_8 ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
V_4 = V_2 -> V_12 . V_16 ;
if ( ! V_4 )
return - V_17 ;
V_10 = F_7 ( V_4 , L_1 , & V_11 ) ;
if ( V_10 == - V_17 )
V_11 = V_18 ;
else if ( V_10 )
return V_10 ;
V_10 = F_8 ( V_6 , & V_2 -> V_12 , 2 , V_9 + V_19 ,
V_9 + V_20 , NULL ,
V_9 + V_21 , NULL , 0 ) ;
if ( V_10 ) {
F_9 ( & V_2 -> V_12 , L_2 ) ;
return V_10 ;
}
V_6 -> V_22 = V_11 ;
F_10 ( V_2 , V_6 ) ;
return F_11 ( & V_2 -> V_12 , V_6 , NULL ) ;
}
