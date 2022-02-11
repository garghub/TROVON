int F_1 ( unsigned V_1 , unsigned V_2 , ... )
{
T_1 V_3 ;
unsigned V_4 ;
unsigned V_5 ;
#ifdef F_2
F_3 () ;
#endif
F_4 ( 0 ) = V_1 ;
if ( V_1 == V_6 ) {
int V_4 ;
char * V_7 ;
F_4 ( 1 ) = V_2 ;
va_start ( V_3 , V_2 ) ;
V_7 = ( char * ) va_arg ( V_3 , unsigned ) ;
for ( V_4 = 0 ; V_4 != V_2 ; V_4 ++ )
F_5 ( 8 + V_4 ) = V_7 [ V_4 ] ;
F_5 ( 8 + V_4 ) = 0 ;
} else {
va_start ( V_3 , V_2 ) ;
for ( V_4 = 1 ; V_4 <= V_2 ; V_4 ++ )
F_4 ( V_4 ) = va_arg ( V_3 , unsigned ) ;
va_end ( V_3 ) ;
}
V_5 = * ( ( volatile unsigned * ) V_8 ) ;
F_6 ( V_1 ) ;
while ( F_7 ( 0 ) > 0 ) ;
V_5 = F_7 ( 1 ) ;
#ifdef F_2
F_8 () ;
#endif
return V_5 ;
}
unsigned F_9 ( unsigned V_4 )
{
return ( F_4 ( V_4 ) ) ;
}
void F_10 ( const char * V_7 )
{
int V_4 ;
for ( V_4 = 1 ; V_7 [ V_4 ] ; V_4 ++ ) ;
F_1 ( V_6 , V_4 , V_7 ) ;
}
void F_11 ( void )
{
( void ) F_1 ( V_9 , 0 ) ;
}
void F_12 ( unsigned V_10 )
{
( void ) F_1 ( V_11 , 1 , V_10 ) ;
}
