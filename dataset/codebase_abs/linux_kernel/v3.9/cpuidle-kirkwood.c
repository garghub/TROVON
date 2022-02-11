static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_2 ( 0x7 , V_6 ) ;
F_3 () ;
return V_5 ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_5 ( V_8 , V_11 , 0 ) ;
if ( V_10 == NULL )
return - V_12 ;
V_6 = F_6 ( & V_8 -> V_2 , V_10 ) ;
if ( ! V_6 )
return - V_13 ;
V_14 = & F_7 ( V_15 , F_8 () ) ;
V_14 -> V_16 = V_17 ;
F_9 ( & V_18 ) ;
if ( F_10 ( V_14 ) ) {
F_11 ( L_1 ) ;
return - V_19 ;
}
return 0 ;
}
int F_12 ( struct V_7 * V_8 )
{
F_13 ( V_14 ) ;
F_14 ( & V_18 ) ;
return 0 ;
}
