int main ( int V_1 , char * V_2 [] )
{
unsigned long long V_3 , V_4 , V_5 ;
struct V_6 V_7 ;
if ( V_1 != 3 ) {
fprintf ( V_8 , L_1 ,
V_2 [ 0 ] ) ;
return V_9 ;
}
if ( V_6 ( V_2 [ 1 ] , & V_7 ) == - 1 ) {
perror ( L_2 ) ;
return V_9 ;
}
V_10 = 0 ;
if ( sscanf ( V_2 [ 2 ] , L_3 , & V_4 ) != 1 ) {
if ( V_10 != 0 )
perror ( L_4 ) ;
else
fprintf ( V_8 , L_5 ) ;
return V_9 ;
}
V_3 = ( V_11 ) V_7 . V_12 ;
V_5 = V_4 + V_3 ;
V_5 += ( 16 - V_3 % 16 ) ;
printf ( L_6 , V_5 ) ;
return V_13 ;
}
