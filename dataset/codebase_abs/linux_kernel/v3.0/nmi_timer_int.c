static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * args = (struct V_5 * ) V_4 ;
int V_6 = V_7 ;
switch ( V_3 ) {
case V_8 :
F_2 ( args -> V_9 , 0 ) ;
V_6 = V_10 ;
break;
default:
break;
}
return V_6 ;
}
static int F_3 ( void )
{
if ( F_4 ( & V_11 ) )
return 1 ;
return 0 ;
}
static void F_5 ( void )
{
F_6 ( & V_11 ) ;
F_7 () ;
}
int T_1 F_8 ( struct V_12 * V_13 )
{
V_13 -> V_14 = F_3 ;
V_13 -> V_15 = F_5 ;
V_13 -> V_16 = L_1 ;
F_9 ( V_17 L_2 ) ;
return 0 ;
}
