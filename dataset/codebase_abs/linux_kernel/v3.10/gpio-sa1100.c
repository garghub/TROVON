static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return V_4 & F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 , int V_5 )
{
if ( V_5 )
V_6 = F_2 ( V_3 ) ;
else
V_7 = F_2 ( V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
unsigned long V_8 ;
F_5 ( V_8 ) ;
V_9 &= ~ F_2 ( V_3 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 , int V_5 )
{
unsigned long V_8 ;
F_5 ( V_8 ) ;
F_3 ( V_2 , V_3 , V_5 ) ;
V_9 |= F_2 ( V_3 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
return V_3 < 11 ? ( V_10 + V_3 ) : ( V_11 - 11 + V_3 ) ;
}
void T_1 F_9 ( void )
{
F_10 ( & V_12 ) ;
}
