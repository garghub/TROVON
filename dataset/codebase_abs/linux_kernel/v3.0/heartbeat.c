void F_1 ( void )
{
static unsigned int V_1 , V_2 , V_3 ;
if ( V_4 ) {
if ( V_1 == 0 || V_1 == V_3 )
F_2 ( V_4 , 1 ) ;
else if ( V_1 == 7 || V_1 == V_3 + 7 )
F_2 ( V_4 , 0 ) ;
if ( ++ V_1 > V_2 ) {
V_1 = 0 ;
V_2 = ( ( 672 << V_5 ) / ( 5 * V_6 [ 0 ] +
( 7 << V_5 ) ) ) + 30 ;
V_3 = V_2 / 4 ;
}
}
}
void F_3 ( void )
{
struct V_7 * V_8 = NULL ;
int * V_9 ;
int V_10 ;
const char * const V_11 [] = {
L_1 ,
NULL
} ;
for ( V_10 = 0 ; V_11 [ V_10 ] != NULL ; V_10 ++ ) {
V_8 = F_4 ( NULL , NULL , V_11 [ V_10 ] ) ;
if ( V_8 )
break;
}
if ( V_8 ) {
V_4 = F_5 ( F_6 ( V_8 , L_2 , NULL ) ) ;
V_4 = ( unsigned long ) F_7 ( V_4 , V_12 ) ;
F_8 ( V_13 L_3 , V_4 ) ;
V_9 = ( int * ) F_6 ( V_8 , L_4 , NULL ) ;
if ( V_9 )
F_2 ( V_4 + 4 , 0 ) ;
}
}
