static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 * V_6 = V_2 -> V_7 . V_8 ;
int V_9 = V_10 ;
int V_11 ;
if ( ! V_6 )
return - V_12 ;
F_2 ( & V_4 , F_3 ( 0 ) , 1 , 0 ) ;
V_11 = F_4 ( V_9 , V_13 , & V_4 ) ;
if ( V_11 < 0 ) {
F_5 ( & V_2 -> V_7 , L_1 , V_9 ) ;
return V_11 ;
}
V_6 -> V_11 = V_11 ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 ,
unsigned long V_16 , void * V_17 )
{
if ( V_16 == V_18 ) {
F_7 ( & V_19 ) ;
return 0 ;
}
return F_8 ( & V_19 ) ;
}
static int T_1 F_9 ( void )
{
if ( F_10 () != V_20 )
return - V_21 ;
V_19 . V_7 . V_8 = & V_22 ;
F_11 ( & V_23 ) ;
return 0 ;
}
