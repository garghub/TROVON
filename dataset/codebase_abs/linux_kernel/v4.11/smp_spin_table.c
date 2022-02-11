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
int V_8 ;
V_7 = F_4 ( V_5 , NULL ) ;
if ( ! V_7 )
return - V_9 ;
V_8 = F_5 ( V_7 , L_1 ,
& V_10 [ V_5 ] ) ;
if ( V_8 )
F_6 ( L_2 ,
V_5 ) ;
F_7 ( V_7 ) ;
return V_8 ;
}
static int F_8 ( unsigned int V_5 )
{
T_2 T_3 * V_11 ;
if ( ! V_10 [ V_5 ] )
return - V_9 ;
V_11 = F_9 ( V_10 [ V_5 ] ,
sizeof( * V_11 ) ) ;
if ( ! V_11 )
return - V_12 ;
F_10 ( F_11 ( V_13 ) , V_11 ) ;
F_2 ( ( V_14 void * ) V_11 ,
sizeof( * V_11 ) ) ;
F_12 () ;
F_13 ( V_11 ) ;
return 0 ;
}
static int F_14 ( unsigned int V_5 )
{
F_1 ( F_15 ( V_5 ) ) ;
F_12 () ;
return 0 ;
}
