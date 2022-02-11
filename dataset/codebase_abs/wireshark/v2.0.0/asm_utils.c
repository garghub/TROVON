T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
return strcmp ( ( const char * ) V_1 , ( const char * ) V_2 ) ;
}
T_1
F_2 ( T_2 V_1 , T_2 V_2 , T_3 T_4 V_3 )
{
return strcmp ( ( const char * ) V_1 , ( const char * ) V_2 ) ;
}
T_5
F_3 ( T_2 V_1 , T_2 V_2 )
{
return ! strcmp ( ( const char * ) V_1 , ( const char * ) V_2 ) ;
}
T_6
F_4 ( const T_7 V_4 [ 256 ] , const char * V_5 )
{
const char * V_6 = V_5 ;
T_6 V_7 ;
do {
V_7 = * ( V_6 ++ ) ;
} while ( V_4 [ V_7 ] );
return V_7 ;
}
T_8
F_5 ( T_2 V_8 )
{
const signed char * V_6 = ( const signed char * ) V_8 ;
T_9 V_9 = * V_6 ;
if ( V_9 )
for ( V_6 += 1 ; * V_6 != '\0' ; V_6 ++ )
V_9 = ( V_9 << 5 ) - V_9 + * V_6 ;
return V_9 ;
}
