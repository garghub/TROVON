int T_1 F_1 ( void )
{
const struct V_1 * const * V_2 ;
const struct V_1 * V_3 ;
char * V_4 ;
void * V_5 [ ( 65536 / V_6 ) + 2 ] ;
int V_7 , V_8 ;
unsigned long V_9 , V_10 ;
int V_11 ;
unsigned long j0 , j1 ;
V_8 = ( 65536 / V_6 ) + 2 ;
for ( V_7 = 0 ; V_7 < V_8 - 2 ; V_7 ++ ) {
V_5 [ V_7 ] = ( ( char * ) V_12 ) + V_6 * V_7 ;
}
V_4 = ( void * ) F_2 ( V_13 , 1 ) ;
if ( ! V_4 ) {
F_3 ( L_1 ) ;
return - V_14 ;
}
V_5 [ V_8 - 2 ] = V_4 ;
V_5 [ V_8 - 1 ] = V_4 + V_6 ;
V_10 = 0 ; V_11 = 0 ; V_3 = NULL ;
for ( V_2 = V_15 ; * V_2 ; V_2 ++ ) {
if ( ! ( * V_2 ) -> V_16 || ( * V_2 ) -> V_16 () ) {
V_9 = 0 ;
F_4 () ;
j0 = V_17 ;
while ( ( j1 = V_17 ) == j0 )
F_5 () ;
while ( F_6 ( V_17 ,
j1 + ( 1 << V_18 ) ) ) {
( * V_2 ) -> V_19 ( V_8 , V_6 , V_5 ) ;
V_9 ++ ;
}
F_7 () ;
if ( ( * V_2 ) -> V_20 > V_11 ||
( ( * V_2 ) -> V_20 == V_11 &&
V_9 > V_10 ) ) {
V_3 = * V_2 ;
V_11 = V_3 -> V_20 ;
V_10 = V_9 ;
}
F_3 ( L_2 , ( * V_2 ) -> V_21 ,
( V_9 * V_22 ) >> ( 20 - 16 + V_18 ) ) ;
}
}
if ( V_3 ) {
F_3 ( L_3 ,
V_3 -> V_21 ,
( V_10 * V_22 ) >> ( 20 - 16 + V_18 ) ) ;
V_23 = * V_3 ;
} else
F_3 ( L_4 ) ;
F_8 ( ( unsigned long ) V_4 , 1 ) ;
return V_3 ? 0 : - V_24 ;
}
static void F_9 ( void )
{
do { } while ( 0 );
}
