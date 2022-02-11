static void F_1 ( char * V_1 , long V_2 , long V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < ( V_4 * V_2 / V_3 ) - 1 && V_5 < V_4 - 1 ; V_5 ++ )
V_1 [ V_5 ] = '*' ;
if ( V_2 > V_3 )
V_1 [ V_5 - 1 ] = '+' ;
V_1 [ V_5 ] = '\0' ;
}
int main ( int V_6 , char * * V_7 )
{
unsigned int V_8 = F_2 () ;
const char * V_9 = L_1 ;
T_1 V_10 [ V_8 ] , V_11 , V_12 = 0 , V_13 [ V_14 ] = {} ;
T_1 V_15 = 0 , V_16 , V_17 = 0 ;
char V_18 [ V_19 ] ;
int V_5 , V_20 ;
V_20 = F_3 ( V_9 ) ;
if ( V_20 < 0 ) {
fprintf ( V_21 , L_2 ,
V_9 , strerror ( V_22 ) , V_22 ) ;
return - 1 ;
}
while ( F_4 ( V_20 , & V_15 , & V_16 ) == 0 ) {
if ( V_16 >= V_14 ) {
fprintf ( V_21 , L_3 , V_16 ) ;
continue;
}
F_5 ( V_20 , & V_16 , V_10 ) ;
V_11 = 0 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ )
V_11 += V_10 [ V_5 ] ;
V_13 [ V_16 ] = V_11 ;
if ( V_11 && V_16 > V_17 )
V_17 = V_16 ;
if ( V_11 > V_12 )
V_12 = V_11 ;
V_15 = V_16 ;
}
for ( V_5 = 1 ; V_5 <= V_17 + 1 ; V_5 ++ ) {
F_1 ( V_18 , V_13 [ V_5 - 1 ] , V_12 , V_19 ) ;
printf ( L_4 ,
( 1l << V_5 ) >> 1 , ( 1l << V_5 ) - 1 , V_13 [ V_5 - 1 ] ,
V_19 , V_18 ) ;
}
F_6 ( V_20 ) ;
return 0 ;
}
