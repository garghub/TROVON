static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
if ( F_2 () )
return - V_10 ;
if ( ! V_2 -> V_11 . V_12 )
V_2 -> V_11 . V_12 = & V_13 ;
if ( V_2 -> V_7 [ 1 ] . V_14 != V_15 ) {
F_3 ( L_1 ) ;
return - V_16 ;
}
V_4 = F_4 ( & V_17 , & V_2 -> V_11 , L_2 ) ;
if ( ! V_4 )
return - V_16 ;
V_8 = F_5 ( V_2 , V_18 , 0 ) ;
V_4 -> V_19 = V_8 -> V_20 ;
V_4 -> V_21 = F_6 ( V_8 ) ;
V_4 -> V_22 = F_7 ( & V_2 -> V_11 , V_8 ) ;
if ( ! V_4 -> V_22 ) {
F_3 ( L_3 ) ;
V_9 = - V_16 ;
goto V_23;
}
V_6 = F_8 ( V_4 ) ;
V_6 -> V_24 = V_4 -> V_22 ;
V_9 = F_9 ( V_4 , V_2 -> V_7 [ 1 ] . V_20 ,
V_25 ) ;
if ( V_9 == 0 ) {
F_10 ( V_2 , V_4 ) ;
return V_9 ;
}
V_23:
F_11 ( V_4 ) ;
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_13 ( V_2 ) ;
F_14 ( V_4 ) ;
F_11 ( V_4 ) ;
F_10 ( V_2 , NULL ) ;
return 0 ;
}
