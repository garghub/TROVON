static int F_1 ( void )
{
F_2 ( V_1 + ( V_2 << V_3 ) , 0x06 ) ;
return 0 ;
}
static void F_3 ( unsigned char V_4 )
{
while ( ( F_4 ( V_1 + ( V_5 << V_3 ) ) & V_6 ) == 0 ) ;
F_2 ( V_1 , V_4 ) ;
}
static unsigned char F_5 ( void )
{
while ( ( F_4 ( V_1 + ( V_5 << V_3 ) ) & V_7 ) == 0 ) ;
return F_4 ( V_1 ) ;
}
static T_1 F_6 ( void )
{
return ( ( F_4 ( V_1 + ( V_5 << V_3 ) ) & V_7 ) != 0 ) ;
}
int F_7 ( void * V_8 , struct V_9 * V_10 )
{
int V_11 ;
T_2 V_12 ;
if ( F_8 ( V_8 , ( void * * ) & V_1 , 1 ) < 1 )
return - 1 ;
V_11 = F_9 ( V_8 , L_1 , & V_12 , sizeof( V_12 ) ) ;
if ( V_11 == sizeof( V_12 ) )
V_1 += V_12 ;
V_11 = F_9 ( V_8 , L_2 , & V_3 , sizeof( V_3 ) ) ;
if ( V_11 != sizeof( V_3 ) )
V_3 = 0 ;
V_10 -> V_13 = F_1 ;
V_10 -> putc = F_3 ;
V_10 -> getc = F_5 ;
V_10 -> V_14 = F_6 ;
V_10 -> V_15 = NULL ;
return 0 ;
}
