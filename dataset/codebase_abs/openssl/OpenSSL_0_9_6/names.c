int F_1 ( T_1 * V_1 )
{
int V_2 ;
V_2 = F_2 ( F_3 ( V_1 -> V_3 ) , V_4 , ( char * ) V_1 ) ;
if ( V_2 == 0 ) return ( 0 ) ;
V_2 = F_2 ( F_4 ( V_1 -> V_3 ) , V_4 , ( char * ) V_1 ) ;
return ( V_2 ) ;
}
int F_5 ( T_2 * V_5 )
{
int V_2 ;
const char * V_6 ;
V_6 = F_3 ( V_5 -> type ) ;
V_2 = F_2 ( V_6 , V_7 , ( char * ) V_5 ) ;
if ( V_2 == 0 ) return ( 0 ) ;
V_2 = F_2 ( F_4 ( V_5 -> type ) , V_7 , ( char * ) V_5 ) ;
if ( V_2 == 0 ) return ( 0 ) ;
if ( V_5 -> type != V_5 -> V_8 )
{
V_2 = F_2 ( F_3 ( V_5 -> V_8 ) ,
V_7 | V_9 , V_6 ) ;
if ( V_2 == 0 ) return ( 0 ) ;
V_2 = F_2 ( F_4 ( V_5 -> V_8 ) ,
V_7 | V_9 , V_6 ) ;
}
return ( V_2 ) ;
}
const T_1 * F_6 ( const char * V_6 )
{
const T_1 * V_10 ;
V_10 = ( const T_1 * ) F_7 ( V_6 , V_4 ) ;
return ( V_10 ) ;
}
const T_2 * F_8 ( const char * V_6 )
{
const T_2 * V_10 ;
V_10 = ( const T_2 * ) F_7 ( V_6 , V_7 ) ;
return ( V_10 ) ;
}
void F_9 ( void )
{
F_10 ( V_4 ) ;
F_10 ( V_7 ) ;
F_10 ( - 1 ) ;
F_11 () ;
}
