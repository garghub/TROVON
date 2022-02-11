static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
F_2 ( 0 , V_5 ) ;
F_3 ( 10000 ) ;
return V_6 ;
}
static void F_4 ( void )
{
F_1 ( & V_7 , 0 , NULL ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
struct V_12 * V_13 ;
V_13 = F_6 ( V_9 , V_14 , 0 ) ;
V_5 = F_7 ( V_11 , V_13 ) ;
if ( F_8 ( V_5 ) )
return F_9 ( V_5 ) ;
F_10 ( & V_7 ) ;
V_15 = F_4 ;
return 0 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_16 ) ;
}
