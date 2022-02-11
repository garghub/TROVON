static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
if ( ! V_7 )
return - V_10 ;
V_3 = V_7 -> V_11 ;
F_2 ( & V_5 , F_3 ( 0 ) , 1 , 0 ) ;
if ( F_4 ( V_3 , V_12 , & V_5 ) <= 0 ) {
F_5 ( & V_2 -> V_8 , L_1 ,
V_3 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_6 ( struct V_13 * V_14 ,
unsigned long V_15 , void * V_16 )
{
if ( V_15 == V_17 ) {
F_7 ( & V_18 ) ;
return 0 ;
}
return F_8 ( & V_18 ) ;
}
static int T_1 F_9 ( void )
{
if ( F_10 () != V_19 )
return - V_20 ;
V_18 . V_8 . V_9 = & V_21 ;
F_11 ( & V_22 ) ;
return 0 ;
}
