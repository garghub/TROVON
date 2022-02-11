int main ( int V_1 , char const * V_2 [] )
{
struct V_3 V_4 ;
int V_5 , V_6 ;
int V_7 ;
struct V_8 V_9 ;
if ( V_1 != 2 ) {
fprintf ( V_10 , L_1 ) ;
return 1 ;
}
strncpy ( V_4 . V_11 , V_2 [ 1 ] , V_12 ) ;
V_4 . V_13 = 100 ;
V_5 = F_1 ( L_2 , V_14 ) ;
if ( V_5 == - 1 ) {
perror ( L_3 ) ;
return 1 ;
}
V_6 = F_2 ( V_5 , & V_4 , sizeof( V_4 ) ) ;
if ( V_6 == - 1 ) {
perror ( L_4 ) ;
F_3 ( V_5 ) ;
return 1 ;
}
while ( 1 ) {
V_6 = F_4 ( V_5 , & V_7 , sizeof( V_7 ) ) ;
if ( V_6 == - 1 ) {
perror ( L_5 ) ;
F_3 ( V_5 ) ;
return 1 ;
}
F_5 ( V_15 , & V_9 ) ;
printf ( L_6 , V_9 . V_16 , V_9 . V_17 , V_7 ) ;
}
F_3 ( V_5 ) ;
return 0 ;
}
