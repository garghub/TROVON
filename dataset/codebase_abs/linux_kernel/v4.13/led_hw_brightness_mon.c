int main ( int V_1 , char const * V_2 [] )
{
int V_3 , V_4 ;
char V_5 [ V_6 + 11 ] ;
struct V_7 V_7 ;
struct V_8 V_9 ;
char V_10 [ 11 ] ;
if ( V_1 != 2 ) {
fprintf ( V_11 , L_1 ) ;
return 1 ;
}
snprintf ( V_5 , V_6 ,
L_2 , V_2 [ 1 ] ) ;
V_3 = F_1 ( V_5 , V_12 ) ;
if ( V_3 == - 1 ) {
printf ( L_3 , V_5 ) ;
return 1 ;
}
F_2 ( V_3 , V_10 , sizeof( V_10 ) ) ;
V_7 . V_3 = V_3 ;
V_7 . V_13 = V_14 ;
while ( 1 ) {
V_4 = F_3 ( & V_7 , 1 , - 1 ) ;
if ( V_4 == - 1 ) {
printf ( L_4 ,
V_5 , V_4 ) ;
V_4 = 1 ;
break;
}
F_4 ( V_15 , & V_9 ) ;
V_4 = F_2 ( V_3 , V_10 , sizeof( V_10 ) ) ;
if ( V_4 < 0 )
break;
V_4 = F_5 ( V_7 . V_3 , 0 , V_16 ) ;
if ( V_4 < 0 ) {
printf ( L_5 , V_4 ) ;
break;
}
printf ( L_6 , V_9 . V_17 , V_9 . V_18 , atoi ( V_10 ) ) ;
}
F_6 ( V_3 ) ;
return V_4 ;
}
