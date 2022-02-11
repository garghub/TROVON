void T_1 F_1 ( unsigned int V_1 )
{
V_2 = F_2 ( V_3 ) ;
V_4 = V_5 ;
F_3 ( V_6 ) ;
F_4 ( V_6 , V_7 ) ;
}
int F_5 ( unsigned int V_8 , struct V_9 * V_10 )
{
F_6 ( V_8 , F_2 ( V_11 ) ,
( unsigned long ) V_6 ) ;
return 0 ;
}
void F_7 ( unsigned int V_8 )
{
F_6 ( V_8 , 0 , 0 ) ;
F_8 () ;
F_9 () ;
F_4 ( V_6 , V_12 ) ;
F_10 () ;
}
static int F_11 ( int V_8 )
{
unsigned long V_13 = V_12 << ( V_8 * 8 ) ;
if ( ( F_12 ( V_6 + 8 ) & V_13 ) == V_13 )
return 1 ;
return 0 ;
}
int F_13 ( unsigned int V_8 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 1000 ; V_14 ++ ) {
if ( F_11 ( V_8 ) )
return 1 ;
F_14 ( 1 ) ;
}
return 0 ;
}
