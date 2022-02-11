void F_1 ( void )
{
int V_1 ;
unsigned int V_2 ;
printf ( L_1 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
V_2 = ( ( 1UL << 32 ) - 1 ) * pow ( V_4 , V_1 ) ;
if ( V_1 % 6 == 0 ) printf ( L_2 ) ;
printf ( L_3 , V_2 ) ;
}
printf ( L_4 ) ;
}
void F_2 ( void )
{
int V_1 ;
printf ( L_5 ) ;
for ( V_1 = 1 ; V_1 <= V_3 ; V_1 ++ ) {
if ( V_1 == 1 )
V_5 *= V_4 ;
else
V_5 = V_5 * V_4 + 1024 * V_4 ;
if ( V_1 % 11 == 0 )
printf ( L_2 ) ;
printf ( L_6 , V_5 ) ;
}
printf ( L_4 ) ;
}
void F_3 ( void )
{
long V_6 = 0 , V_7 = ( ( 1UL << 32 ) - 1 ) * V_4 ;
for (; ; V_8 ++ ) {
if ( V_8 > - 1 )
V_9 = ( ( V_9 * V_7 ) >> V_10 ) + 1024 ;
if ( V_6 == V_9 )
break;
V_6 = V_9 ;
}
V_8 -- ;
printf ( L_7 , V_3 ) ;
printf ( L_8 , V_9 ) ;
}
void F_4 ( void )
{
int V_1 , V_2 = V_5 ;
printf ( L_9 ) ;
for ( V_1 = 1 ; V_1 <= V_8 / V_3 + 1 ; V_1 ++ ) {
if ( V_1 > 1 )
V_2 = V_2 / 2 + V_5 ;
if ( V_1 % 6 == 0 )
printf ( L_2 ) ;
printf ( L_10 , V_2 ) ;
}
printf ( L_4 ) ;
}
void main ( void )
{
printf ( L_11 ) ;
V_4 = pow ( 0.5 , 1 / ( double ) V_3 ) ;
F_1 () ;
F_3 () ;
}
