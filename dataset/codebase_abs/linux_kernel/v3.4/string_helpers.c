int F_1 ( T_1 V_1 , const enum V_2 V_3 ,
char * V_4 , int V_5 )
{
const char * V_6 [] = { L_1 , L_2 , L_3 , L_4 , L_5 , L_6 ,
L_7 , L_8 , L_9 , NULL } ;
const char * V_7 [] = { L_1 , L_10 , L_11 , L_12 , L_13 , L_14 ,
L_15 , L_16 , L_17 , NULL } ;
const char * * V_8 [] = {
[ V_9 ] = V_6 ,
[ V_10 ] = V_7 ,
} ;
const unsigned int V_11 [] = {
[ V_9 ] = 1000 ,
[ V_10 ] = 1024 ,
} ;
int V_12 , V_13 ;
T_1 V_14 = 0 , V_15 ;
char V_16 [ 8 ] ;
V_16 [ 0 ] = '\0' ;
V_12 = 0 ;
if ( V_1 >= V_11 [ V_3 ] ) {
while ( V_1 >= V_11 [ V_3 ] && V_8 [ V_3 ] [ V_12 ] ) {
V_14 = F_2 ( V_1 , V_11 [ V_3 ] ) ;
V_12 ++ ;
}
V_15 = V_1 ;
for ( V_13 = 0 ; V_15 * 10 < 1000 ; V_13 ++ )
V_15 *= 10 ;
if ( V_13 ) {
V_14 *= 1000 ;
F_2 ( V_14 , V_11 [ V_3 ] ) ;
snprintf ( V_16 , sizeof( V_16 ) , L_18 ,
( unsigned long long ) V_14 ) ;
V_16 [ V_13 + 1 ] = '\0' ;
}
}
snprintf ( V_4 , V_5 , L_19 , ( unsigned long long ) V_1 ,
V_16 , V_8 [ V_3 ] [ V_12 ] ) ;
return 0 ;
}
