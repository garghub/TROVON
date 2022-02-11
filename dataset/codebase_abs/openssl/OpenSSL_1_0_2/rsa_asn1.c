static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
if ( V_1 == V_5 ) {
* V_2 = ( T_1 * ) F_2 () ;
if ( * V_2 )
return 2 ;
return 0 ;
} else if ( V_1 == V_6 ) {
F_3 ( ( V_7 * ) * V_2 ) ;
* V_2 = NULL ;
return 2 ;
}
return 1 ;
}
V_7 * F_4 ( V_7 * V_8 )
{
return F_5 ( F_6 ( V_9 ) , V_8 ) ;
}
