static bool F_1 ( void )
{
struct V_1 V_1 ;
if ( F_2 ( V_2 , V_3 , & V_1 ) ) {
F_3 ( V_4 L_1
L_2 , V_2 ) ;
return false ;
}
F_4 ( & V_1 ) ;
return true ;
}
void F_5 ( const char * V_5 )
{
char * V_6 [ 2 ] ;
char * V_7 [ 3 ] ;
if ( V_8 )
return;
if ( strcmp ( V_5 , L_3 ) &&
strcmp ( V_5 , L_4 ) )
return;
if ( ! F_1 () )
return;
F_3 ( V_4 L_5 ,
V_2 ) ;
V_6 [ 0 ] = ( char * ) V_2 ;
V_6 [ 1 ] = NULL ;
V_7 [ 0 ] = L_6 ;
V_7 [ 1 ] = L_7 ;
V_7 [ 2 ] = NULL ;
F_6 ( V_6 [ 0 ] , V_6 , V_7 , 1 ) ;
F_7 () ;
}
