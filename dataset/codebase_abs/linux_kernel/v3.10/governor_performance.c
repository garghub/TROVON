static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
if ( ! V_2 -> V_4 )
* V_3 = V_5 ;
else
* V_3 = V_2 -> V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_1 ,
unsigned int V_6 , void * V_7 )
{
int V_8 = 0 ;
if ( V_6 == V_9 ) {
F_3 ( & V_1 -> V_10 ) ;
V_8 = F_4 ( V_1 ) ;
F_5 ( & V_1 -> V_10 ) ;
}
return V_8 ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_11 ) ;
}
static void T_2 F_8 ( void )
{
int V_8 ;
V_8 = F_9 ( & V_11 ) ;
if ( V_8 )
F_10 ( L_1 , V_12 , V_8 ) ;
return;
}
