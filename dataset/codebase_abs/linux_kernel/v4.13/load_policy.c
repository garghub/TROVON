static int T_1 F_1 ( char * V_1 )
{
V_2 = V_1 ;
return 0 ;
}
static bool F_2 ( void )
{
struct V_3 V_3 ;
if ( ! V_2 )
V_2 = V_4 ;
if ( F_3 ( V_2 , V_5 , & V_3 ) ) {
F_4 ( V_6 L_1
L_2 , V_2 ) ;
return false ;
}
F_5 ( & V_3 ) ;
return true ;
}
static int T_1 F_6 ( char * V_1 )
{
V_7 = V_1 ;
return 0 ;
}
void F_7 ( const char * V_8 )
{
static bool V_9 ;
char * V_10 [ 2 ] ;
char * V_11 [ 3 ] ;
if ( V_12 || V_9 )
return;
if ( ! V_7 )
V_7 = V_13 ;
if ( strcmp ( V_8 , V_7 ) )
return;
if ( ! F_2 () )
return;
V_9 = true ;
F_4 ( V_6 L_3 ,
V_2 ) ;
V_10 [ 0 ] = ( char * ) V_2 ;
V_10 [ 1 ] = NULL ;
V_11 [ 0 ] = L_4 ;
V_11 [ 1 ] = L_5 ;
V_11 [ 2 ] = NULL ;
F_8 ( V_10 [ 0 ] , V_10 , V_11 , V_14 ) ;
F_9 () ;
}
