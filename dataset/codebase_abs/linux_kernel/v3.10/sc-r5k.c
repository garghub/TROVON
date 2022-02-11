static inline void F_1 ( void )
{
unsigned long V_1 = V_2 ;
unsigned long V_3 = V_1 + V_4 ;
while( V_1 < V_3 ) {
F_2 ( V_5 , V_1 ) ;
V_1 += V_6 ;
}
}
static void F_3 ( unsigned long V_7 , unsigned long V_8 )
{
unsigned long V_3 , V_9 ;
F_4 ( V_8 == 0 ) ;
if ( V_8 >= V_4 ) {
F_1 () ;
return;
}
V_9 = V_7 & ~ ( V_6 - 1 ) ;
V_3 = ( V_7 + V_8 - 1 ) & ~ ( V_6 - 1 ) ;
while ( V_9 <= V_3 ) {
F_2 ( V_5 , V_9 ) ;
V_9 += V_6 ;
}
}
static void F_5 ( void )
{
unsigned long V_10 ;
F_6 ( V_10 ) ;
F_7 ( V_11 ) ;
F_1 () ;
F_8 ( V_10 ) ;
}
static void F_9 ( void )
{
unsigned long V_10 ;
F_6 ( V_10 ) ;
F_1 () ;
F_10 ( V_11 ) ;
F_8 ( V_10 ) ;
}
static inline int T_1 F_11 ( void )
{
unsigned long V_12 = F_12 () ;
if ( V_12 & V_13 )
return ( 0 ) ;
V_4 = ( 512 * 1024 ) << ( ( V_12 & V_14 ) >> 20 ) ;
F_13 ( L_1 ,
V_4 >> 10 ) ;
return 1 ;
}
void T_2 F_14 ( void )
{
if ( F_11 () ) {
F_5 () ;
V_15 = & V_16 ;
}
}
