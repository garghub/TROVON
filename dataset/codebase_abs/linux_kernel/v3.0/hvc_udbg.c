static int F_1 ( T_1 V_1 , const char * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
F_2 ( V_2 [ V_4 ] ) ;
return V_4 ;
}
static int F_3 ( T_1 V_1 , char * V_2 , int V_3 )
{
int V_4 , V_5 ;
if ( ! V_6 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( ( V_5 = V_6 () ) == - 1 )
break;
V_2 [ V_4 ] = V_5 ;
}
return V_4 ;
}
static int T_2 F_4 ( void )
{
struct V_7 * V_8 ;
F_5 ( V_9 ) ;
V_8 = F_6 ( 0 , V_10 , & V_11 , 16 ) ;
if ( F_7 ( V_8 ) )
return F_8 ( V_8 ) ;
V_9 = V_8 ;
return 0 ;
}
static void T_3 F_9 ( void )
{
if ( V_9 )
F_10 ( V_9 ) ;
}
static int T_2 F_11 ( void )
{
F_12 ( 0 , 0 , & V_11 ) ;
F_13 ( L_1 , 0 , NULL ) ;
return 0 ;
}
