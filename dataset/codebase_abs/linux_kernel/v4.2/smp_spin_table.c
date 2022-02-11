static void F_1 ( T_1 V_1 )
{
void * V_2 = ( void * ) & V_3 ;
unsigned long V_4 = sizeof( V_3 ) ;
V_3 = V_1 ;
F_2 ( V_2 , V_4 ) ;
}
static int F_3 ( unsigned int V_5 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 , NULL ) ;
if ( ! V_7 )
return - V_8 ;
if ( F_5 ( V_7 , L_1 ,
& V_9 [ V_5 ] ) ) {
F_6 ( L_2 ,
V_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_7 ( unsigned int V_5 )
{
T_2 T_3 * V_10 ;
if ( ! V_9 [ V_5 ] )
return - V_8 ;
V_10 = F_8 ( V_9 [ V_5 ] ,
sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_11 ;
F_9 ( F_10 ( V_12 ) , V_10 ) ;
F_2 ( ( V_13 void * ) V_10 ,
sizeof( * V_10 ) ) ;
F_11 () ;
F_12 ( V_10 ) ;
return 0 ;
}
static int F_13 ( unsigned int V_5 )
{
F_1 ( F_14 ( V_5 ) ) ;
F_11 () ;
return 0 ;
}
