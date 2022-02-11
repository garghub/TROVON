static T_1 F_1 ( void )
{
struct V_1 V_2 ;
F_2 ( V_3 , & V_2 ) ;
return V_2 . V_4 * 1000000000ull + V_2 . V_5 ;
}
static void F_3 ( int V_6 )
{
long long V_7 = F_1 () ;
T_1 V_8 , V_9 ;
struct V_10 V_11 ;
V_8 = F_4 ( 1 , L_1 , 12 ) ;
V_8 = - 1 ;
while ( F_5 ( V_12 [ 0 ] , & V_8 , & V_9 ) == 0 ) {
F_6 ( V_12 [ 0 ] , & V_9 , & V_11 ) ;
V_8 = V_9 ;
if ( V_7 - V_11 . V_7 < 1000000000ll )
continue;
printf ( L_2 ,
V_9 , ( V_7 - V_11 . V_7 ) / 1000000000ll , V_11 . V_13 ) ;
}
}
int main ( int V_14 , char * * V_15 )
{
char V_16 [ 256 ] ;
int V_17 ;
snprintf ( V_16 , sizeof( V_16 ) , L_3 , V_15 [ 0 ] ) ;
if ( F_7 ( V_16 ) ) {
printf ( L_4 , V_18 ) ;
return 1 ;
}
for ( V_17 = 0 ; ; V_17 ++ ) {
F_3 ( V_12 [ 1 ] ) ;
F_8 ( 1 ) ;
}
return 0 ;
}
