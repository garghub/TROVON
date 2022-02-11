static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
* V_3 = V_2 -> V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_1 ,
unsigned int V_5 , void * V_6 )
{
int V_7 = 0 ;
if ( V_5 == V_8 ) {
F_3 ( & V_1 -> V_9 ) ;
V_7 = F_4 ( V_1 ) ;
F_5 ( & V_1 -> V_9 ) ;
}
return V_7 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_10 ) ;
}
static void T_2 F_8 ( void )
{
int V_7 ;
V_7 = F_9 ( & V_10 ) ;
if ( V_7 )
F_10 ( L_1 , V_11 , V_7 ) ;
return;
}
