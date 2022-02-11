static int F_1 ( T_1 V_1 , const char * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 && V_5 ; V_4 ++ )
V_5 ( V_2 [ V_4 ] ) ;
return V_4 ;
}
static int F_2 ( T_1 V_1 , char * V_2 , int V_3 )
{
int V_4 , V_6 ;
if ( ! V_7 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( ( V_6 = V_7 () ) == - 1 )
break;
V_2 [ V_4 ] = V_6 ;
}
return V_4 ;
}
static int T_2 F_3 ( void )
{
struct V_8 * V_9 ;
if ( ! V_5 )
return - V_10 ;
F_4 ( V_11 ) ;
V_9 = F_5 ( 0 , 0 , & V_12 , 16 ) ;
if ( F_6 ( V_9 ) )
return F_7 ( V_9 ) ;
V_11 = V_9 ;
return 0 ;
}
static int T_2 F_8 ( void )
{
if ( ! V_5 )
return - V_10 ;
F_9 ( 0 , 0 , & V_12 ) ;
F_10 ( L_1 , 0 , NULL ) ;
return 0 ;
}
