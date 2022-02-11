int F_1 ( T_1 * V_1 , const char * V_2 )
{
char V_3 [ V_4 ] ;
snprintf ( V_3 , V_4 , L_1 ,
( int ) strlen ( V_2 ) - 2 , V_2 + 1 ) ;
if ( F_2 ( V_3 , ( unsigned long long * ) V_1 ) < 0 )
return - 1 ;
return 0 ;
}
