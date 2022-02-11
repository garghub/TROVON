static int F_1 ( T_1 V_1 , const char * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
while ( F_2 () & V_5 )
F_3 () ;
F_4 ( V_2 [ V_4 ] ) ;
}
return V_3 ;
}
static int F_5 ( T_1 V_1 , char * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; ++ V_4 )
if ( F_2 () & V_6 )
V_2 [ V_4 ] = F_6 () ;
else
break;
return V_4 ;
}
static bool F_7 ( void )
{
unsigned long time = V_7 + ( V_8 / 10 ) ;
F_4 ( '\n' ) ;
while ( F_8 ( time ) ) {
if ( ! ( F_2 () & V_5 ) )
return true ;
}
return false ;
}
static int T_2 F_9 ( void )
{
int V_9 ;
if ( ! F_7 () )
return - V_10 ;
V_9 = F_10 ( 0 , 0 , & V_11 ) ;
return V_9 < 0 ? - V_10 : 0 ;
}
static int T_2 F_11 ( void )
{
struct V_12 * V_13 ;
if ( ! F_7 () )
return - V_10 ;
V_13 = F_12 ( 0 , 0 , & V_11 , 128 ) ;
return F_13 ( V_13 ) ;
}
