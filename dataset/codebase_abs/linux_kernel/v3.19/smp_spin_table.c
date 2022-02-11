static void F_1 ( T_1 V_1 )
{
void * V_2 = ( void * ) & V_3 ;
unsigned long V_4 = sizeof( V_3 ) ;
V_3 = V_1 ;
F_2 ( V_2 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , unsigned int V_7 )
{
if ( F_4 ( V_6 , L_1 ,
& V_8 [ V_7 ] ) ) {
F_5 ( L_2 ,
V_7 ) ;
return - 1 ;
}
return 0 ;
}
static int F_6 ( unsigned int V_7 )
{
T_2 T_3 * V_9 ;
if ( ! V_8 [ V_7 ] )
return - V_10 ;
V_9 = F_7 ( V_8 [ V_7 ] ,
sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_11 ;
F_8 ( F_9 ( V_12 ) , V_9 ) ;
F_2 ( ( V_13 void * ) V_9 ,
sizeof( * V_9 ) ) ;
F_10 () ;
F_11 ( V_9 ) ;
return 0 ;
}
static int F_12 ( unsigned int V_7 )
{
F_1 ( F_13 ( V_7 ) ) ;
F_10 () ;
return 0 ;
}
