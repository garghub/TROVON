static int F_1 ( void )
{
return 0 ;
}
static void F_2 ( unsigned char V_1 )
{
while ( ! ( F_3 ( V_2 + V_3 ) & V_4 ) ) ;
F_4 ( V_2 + V_5 , V_1 ) ;
}
static unsigned char F_5 ( void )
{
return ( F_3 ( V_2 + V_3 ) & V_6 ) != 0 ;
}
static unsigned char F_6 ( void )
{
while ( ! ( F_3 ( V_2 + V_3 ) & V_6 ) ) ;
return F_7 ( V_2 + V_5 ) ;
}
int F_8 ( void * V_7 , struct V_8 * V_9 )
{
if ( F_9 ( V_7 , & V_2 , 1 ) < 1 )
return - 1 ;
V_9 -> V_10 = F_1 ;
V_9 -> putc = F_2 ;
V_9 -> getc = F_6 ;
V_9 -> V_11 = F_5 ;
return 0 ;
}
