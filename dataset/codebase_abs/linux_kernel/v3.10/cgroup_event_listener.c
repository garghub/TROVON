int main ( int V_1 , char * * V_2 )
{
int V_3 = - 1 ;
int V_4 = - 1 ;
int V_5 = - 1 ;
char V_6 [ V_7 ] ;
char line [ V_8 ] ;
int V_9 ;
if ( V_1 != 3 )
F_1 ( 1 , L_1 , V_10 ) ;
V_4 = F_2 ( V_2 [ 1 ] , V_11 ) ;
if ( V_4 == - 1 )
F_3 ( 1 , L_2 , V_2 [ 1 ] ) ;
V_9 = snprintf ( V_6 , V_7 , L_3 ,
F_4 ( V_2 [ 1 ] ) ) ;
if ( V_9 >= V_7 )
F_1 ( 1 , L_4 ) ;
V_5 = F_2 ( V_6 , V_12 ) ;
if ( V_5 == - 1 )
F_3 ( 1 , L_2 , V_6 ) ;
V_3 = F_5 ( 0 , 0 ) ;
if ( V_3 == - 1 )
F_3 ( 1 , L_5 ) ;
V_9 = snprintf ( line , V_8 , L_6 , V_3 , V_4 , V_2 [ 2 ] ) ;
if ( V_9 >= V_8 )
F_1 ( 1 , L_7 ) ;
V_9 = F_6 ( V_5 , line , strlen ( line ) + 1 ) ;
if ( V_9 == - 1 )
F_3 ( 1 , L_8 ) ;
while ( 1 ) {
T_1 V_13 ;
V_9 = F_7 ( V_3 , & V_13 , sizeof( V_13 ) ) ;
if ( V_9 == - 1 ) {
if ( V_14 == V_15 )
continue;
F_3 ( 1 , L_9 ) ;
}
assert ( V_9 == sizeof( V_13 ) ) ;
V_9 = F_8 ( V_6 , V_16 ) ;
if ( ( V_9 == - 1 ) && ( V_14 == V_17 ) ) {
puts ( L_10 ) ;
break;
}
if ( V_9 == - 1 )
F_3 ( 1 , L_11 ) ;
printf ( L_12 , V_2 [ 1 ] , V_2 [ 2 ] ) ;
}
return 0 ;
}
