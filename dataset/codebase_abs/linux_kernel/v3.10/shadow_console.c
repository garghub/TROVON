T_1 void F_1 ( struct V_1 * V_2 , const char * V_3 ,
unsigned int V_4 )
{
unsigned int V_5 ;
if ( ( V_6 + V_4 ) <= ( char * ) ( V_7 - 2 ) ) {
for ( V_5 = 0 ; V_5 <= V_4 ; V_5 ++ )
V_6 [ V_5 ] = V_3 [ V_5 ] ;
V_6 += V_4 ;
V_6 [ 0 ] = 0 ;
V_6 [ 1 ] = 0 ;
} else
V_6 = ( char * ) V_7 ;
}
T_1 int F_2 ( void )
{
return V_8 . V_9 & V_10 ;
}
T_1 void F_3 ( void )
{
int * V_11 = ( int * ) V_12 ;
V_11 [ 0 ] = V_13 ;
V_11 [ 1 ] = V_14 ;
}
T_1 void F_4 ( void )
{
if ( ! F_2 () ) {
F_5 ( & V_8 ) ;
F_3 () ;
}
}
static T_1 int F_6 ( void )
{
int * V_11 = ( int * ) V_12 ;
V_11 [ 0 ] = 0 ;
return 0 ;
}
T_1 void F_7 ( unsigned long V_15 , unsigned int V_4 )
{
int V_5 ;
char V_16 [ 11 ] = L_1 ;
V_4 = V_4 / 4 ;
V_15 = V_15 << ( ( 8 - V_4 ) * 4 ) ;
V_4 += 3 ;
for ( V_5 = 3 ; V_5 <= V_4 ; V_5 ++ ) {
V_16 [ V_5 ] = F_8 ( V_15 >> 28 ) ;
V_15 <<= 4 ;
}
F_1 ( NULL , V_16 , V_4 ) ;
}
