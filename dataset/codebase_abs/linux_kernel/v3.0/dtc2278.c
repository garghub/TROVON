static void F_1 ( char V_1 , char V_2 )
{
int V_3 ;
for( V_3 = 0 ; V_3 < 3 ; ++ V_3 ) {
F_2 ( 0x3f6 ) ;
F_3 ( V_1 , 0xb0 ) ;
F_2 ( 0x3f6 ) ;
F_3 ( V_2 , 0xb4 ) ;
F_2 ( 0x3f6 ) ;
if( F_2 ( 0xb4 ) == V_2 ) {
F_3 ( 7 , 0xb0 ) ;
F_2 ( 0x3f6 ) ;
return;
}
}
}
static void F_4 ( T_1 * V_4 , T_2 * V_5 )
{
unsigned long V_6 ;
if ( V_5 -> V_7 >= V_8 ) {
F_5 ( & V_9 , V_6 ) ;
F_1 ( 1 , 0xc3 ) ;
F_1 ( 0 , 0xa0 ) ;
F_6 ( & V_9 , V_6 ) ;
} else {
}
}
static int T_3 F_7 ( void )
{
unsigned long V_6 ;
F_8 ( V_6 ) ;
F_3 ( 4 , 0xb0 ) ;
F_2 ( 0x3f6 ) ;
F_3 ( 0x20 , 0xb4 ) ;
F_2 ( 0x3f6 ) ;
#ifdef F_9
F_1 ( 1 , 0xc3 ) ;
F_1 ( 0 , 0xa0 ) ;
#endif
F_10 ( V_6 ) ;
return F_11 ( & V_10 , 0 ) ;
}
static int T_3 F_12 ( void )
{
if ( V_11 == 0 )
return - V_12 ;
if ( F_7 () ) {
F_13 ( V_13 L_1 ) ;
return - V_14 ;
}
return 0 ;
}
