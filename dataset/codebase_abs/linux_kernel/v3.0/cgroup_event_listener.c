int main ( int V_1 , char * * V_2 )
{
int V_3 = - 1 ;
int V_4 = - 1 ;
int V_5 = - 1 ;
char V_6 [ V_7 ] ;
char line [ V_8 ] ;
int V_9 ;
if ( V_1 != 3 ) {
fputs ( V_10 , V_11 ) ;
return 1 ;
}
V_4 = F_1 ( V_2 [ 1 ] , V_12 ) ;
if ( V_4 == - 1 ) {
fprintf ( V_11 , L_1 , V_2 [ 1 ] ,
strerror ( V_13 ) ) ;
goto V_14;
}
V_9 = snprintf ( V_6 , V_7 , L_2 ,
F_2 ( V_2 [ 1 ] ) ) ;
if ( V_9 >= V_7 ) {
fputs ( L_3 , V_11 ) ;
goto V_14;
}
V_5 = F_1 ( V_6 , V_15 ) ;
if ( V_5 == - 1 ) {
fprintf ( V_11 , L_1 , V_6 ,
strerror ( V_13 ) ) ;
goto V_14;
}
V_3 = F_3 ( 0 , 0 ) ;
if ( V_3 == - 1 ) {
perror ( L_4 ) ;
goto V_14;
}
V_9 = snprintf ( line , V_8 , L_5 , V_3 , V_4 , V_2 [ 2 ] ) ;
if ( V_9 >= V_8 ) {
fputs ( L_6 , V_11 ) ;
goto V_14;
}
V_9 = F_4 ( V_5 , line , strlen ( line ) + 1 ) ;
if ( V_9 == - 1 ) {
perror ( L_7 ) ;
goto V_14;
}
while ( 1 ) {
T_1 V_16 ;
V_9 = F_5 ( V_3 , & V_16 , sizeof( V_16 ) ) ;
if ( V_9 == - 1 ) {
if ( V_13 == V_17 )
continue;
perror ( L_8 ) ;
break;
}
assert ( V_9 == sizeof( V_16 ) ) ;
V_9 = F_6 ( V_6 , V_18 ) ;
if ( ( V_9 == - 1 ) && ( V_13 == V_19 ) ) {
puts ( L_9 ) ;
V_9 = 0 ;
break;
}
if ( V_9 == - 1 ) {
perror ( L_10
L_11 ) ;
break;
}
printf ( L_12 , V_2 [ 1 ] , V_2 [ 2 ] ) ;
}
V_14:
if ( V_3 >= 0 )
F_7 ( V_3 ) ;
if ( V_5 >= 0 )
F_7 ( V_5 ) ;
if ( V_4 >= 0 )
F_7 ( V_4 ) ;
return ( V_9 != 0 ) ;
}
