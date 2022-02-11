static int F_1 ( void )
{
F_2 ( V_1 + V_2 , V_3 ) ;
return 0 ;
}
static void F_3 ( unsigned char V_4 )
{
T_1 V_5 = V_6 ;
while ( V_5 & V_6 )
V_5 = F_4 ( V_1 + V_7 ) ;
F_2 ( V_1 + V_8 , V_4 ) ;
}
static unsigned char F_5 ( void )
{
T_1 V_5 = 0 ;
while ( ! ( V_5 & V_9 ) )
V_5 = F_4 ( V_1 + V_7 ) ;
return F_4 ( V_1 + V_10 ) ;
}
static T_2 F_6 ( void )
{
T_1 V_5 = F_4 ( V_1 + V_7 ) ;
return V_5 & V_9 ;
}
int F_7 ( void * V_11 , struct V_12 * V_13 )
{
int V_14 ;
unsigned long V_15 ;
V_14 = F_8 ( V_11 , L_1 , & V_1 , sizeof( V_1 ) ) ;
if ( V_14 != sizeof( V_1 ) ) {
if ( ! F_9 ( V_11 , 0 , & V_15 , NULL ) )
return - 1 ;
V_1 = ( void * ) V_15 ;
}
V_13 -> V_16 = F_1 ;
V_13 -> putc = F_3 ;
V_13 -> getc = F_5 ;
V_13 -> V_17 = F_6 ;
V_13 -> V_18 = NULL ;
return 0 ;
}
