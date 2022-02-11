static void F_1 ( char V_1 )
{
unsigned long V_2 ;
if ( V_1 == '\n' )
F_1 ( '\r' ) ;
V_2 = F_2 ( V_3 , 1 , ( V_4 ) V_1 << 56 , 0 ) ;
}
static int F_3 ( void )
{
char V_5 , * V_6 = ( char * ) V_7 ;
int V_8 ;
long V_2 ;
if ( V_9 == 0 ) {
V_9 = 0 ;
V_2 = F_4 ( V_3 , & V_9 ,
V_7 + 0 , V_7 + 1 ) ;
if ( V_2 != 0 )
V_9 = 0 ;
}
if ( V_9 <= 0 || V_9 > 16 ) {
V_9 = 0 ;
return - 1 ;
}
V_5 = V_6 [ 0 ] ;
for ( V_8 = 1 ; V_8 < V_9 ; V_8 ++ )
V_6 [ V_8 - 1 ] = V_6 [ V_8 ] ;
V_9 -- ;
return V_5 ;
}
static int F_5 ( void )
{
int V_5 ;
for (; ; ) {
V_5 = F_3 () ;
if ( V_5 == - 1 ) {
volatile unsigned long V_10 ;
for ( V_10 = 0 ; V_10 < 2000000 ; V_10 ++ )
;
} else {
return V_5 ;
}
}
}
void T_1 F_6 ( void )
{
V_11 = F_1 ;
V_12 = F_5 ;
V_13 = F_3 ;
}
