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
struct V_16 V_17 = { V_18 , V_18 } ;
char V_19 [ 256 ] ;
int V_20 ;
snprintf ( V_19 , sizeof( V_19 ) , L_3 , V_15 [ 0 ] ) ;
if ( F_7 ( V_21 , & V_17 ) ) {
perror ( L_4 ) ;
return 1 ;
}
if ( F_8 ( V_19 ) ) {
printf ( L_5 , V_22 ) ;
return 1 ;
}
for ( V_20 = 0 ; ; V_20 ++ ) {
F_3 ( V_12 [ 1 ] ) ;
F_9 ( 1 ) ;
}
return 0 ;
}
