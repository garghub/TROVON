static void F_1 ( int V_1 )
{
T_1 V_2 = 0 ;
T_1 V_3 ;
if ( F_2 ( V_1 , & V_2 , & V_3 ) != 0 ) {
fprintf ( V_4 , L_1 , strerror ( V_5 ) ) ;
return;
}
if ( V_3 == 0 )
fprintf ( V_4 , L_2 , V_1 ) ;
}
int main ( int V_6 , char * * V_7 )
{
struct V_8 V_9 = { V_10 , V_10 } ;
char V_11 [ 256 ] ;
int V_12 ;
F_3 ( V_13 , & V_9 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_3 , V_7 [ 0 ] ) ;
if ( F_4 ( V_11 ) ) {
fprintf ( V_4 , L_4 , V_14 ) ;
return 1 ;
}
V_12 = F_5 ( V_11 , V_15 ) ;
if ( V_12 < 0 ) {
fprintf ( V_4 , L_5 , strerror ( V_5 ) ) ;
return 1 ;
}
F_6 ( V_12 ) ;
F_1 ( V_16 [ 0 ] ) ;
F_1 ( V_16 [ 1 ] ) ;
return 0 ;
}
