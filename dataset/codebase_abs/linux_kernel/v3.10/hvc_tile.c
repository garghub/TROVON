static int F_1 ( T_1 V_1 , const char * V_2 , int V_3 )
{
return F_2 ( ( V_4 ) V_2 , V_3 ) ;
}
static int F_3 ( T_1 V_1 , char * V_2 , int V_3 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_3 ; ++ V_5 ) {
V_6 = F_4 () ;
if ( V_6 < 0 )
break;
V_2 [ V_5 ] = V_6 ;
}
return V_5 ;
}
static int T_2 F_5 ( void )
{
extern void V_7 ( void ) ;
F_6 ( 0 , 0 , & V_8 ) ;
F_7 ( L_1 , 0 , NULL ) ;
V_7 () ;
return 0 ;
}
static int T_2 F_8 ( void )
{
struct V_9 * V_10 ;
V_10 = F_9 ( 0 , 0 , & V_8 , 128 ) ;
return F_10 ( V_10 ) ? F_11 ( V_10 ) : 0 ;
}
