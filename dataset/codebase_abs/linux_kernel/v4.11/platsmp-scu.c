static int F_1 ( unsigned int V_1 )
{
F_2 ( V_1 , F_3 ( V_2 ) ,
V_3 ) ;
return 0 ;
}
void T_1 F_4 ( T_2 V_4 ,
unsigned int V_5 )
{
V_6 = F_3 ( V_7 ) ;
V_3 = V_4 ;
V_8 = F_5 ( V_4 , V_9 ) ;
F_6 ( V_8 ) ;
F_7 ( V_8 , V_10 ) ;
F_8 ( V_11 ,
L_1 ,
F_1 , NULL ) ;
}
void F_9 ( unsigned int V_1 )
{
F_2 ( V_1 , 0 , 0 ) ;
F_10 () ;
F_11 () ;
F_7 ( V_8 , V_12 ) ;
F_12 () ;
}
static int F_13 ( int V_1 )
{
unsigned long V_13 = V_12 << ( V_1 * 8 ) ;
if ( ( F_14 ( V_8 + 8 ) & V_13 ) == V_13 )
return 1 ;
return 0 ;
}
int F_15 ( unsigned int V_1 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 1000 ; V_14 ++ ) {
if ( F_13 ( V_1 ) )
return 1 ;
F_16 ( 1 ) ;
}
return 0 ;
}
