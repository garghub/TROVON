T_1 * F_1 ( int V_1 , unsigned long V_2 ,
void (* F_2)( int , int , void * ) , void * V_3 )
{
T_2 V_4 ;
int V_5 ;
T_1 * V_6 = F_3 () ;
T_3 * V_7 = F_4 () ;
if( ! V_6 || ! V_7 ) goto V_8;
for ( V_5 = 0 ; V_5 < ( int )sizeof( unsigned long ) * 8 ; V_5 ++ )
{
if ( V_2 & ( 1UL << V_5 ) )
if ( F_5 ( V_7 , V_5 ) == 0 )
goto V_8;
}
F_6 ( & V_4 , F_2 , V_3 ) ;
if( F_7 ( V_6 , V_1 , V_7 , & V_4 ) ) {
F_8 ( V_7 ) ;
return V_6 ;
}
V_8:
if( V_7 ) F_8 ( V_7 ) ;
if( V_6 ) F_9 ( V_6 ) ;
return 0 ;
}
