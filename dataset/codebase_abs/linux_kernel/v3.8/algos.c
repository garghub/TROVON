static inline const struct V_1 * F_1 ( void )
{
const struct V_1 * const * V_2 ;
const struct V_1 * V_3 ;
for ( V_3 = NULL , V_2 = V_4 ; * V_2 ; V_2 ++ )
if ( ! V_3 || ( * V_2 ) -> V_5 > V_3 -> V_5 )
if ( ! ( * V_2 ) -> V_6 || ( * V_2 ) -> V_6 () )
V_3 = * V_2 ;
if ( V_3 ) {
V_7 = V_3 -> V_8 ;
V_9 = V_3 -> V_10 ;
F_2 ( L_1 , V_3 -> V_11 ) ;
} else
F_2 ( L_2 ) ;
return V_3 ;
}
int T_1 F_3 ( void )
{
const int V_12 = ( 65536 / V_13 ) + 2 ;
const struct V_14 * V_15 ;
const struct V_1 * V_16 ;
char * V_17 ;
void * V_18 [ ( 65536 / V_13 ) + 2 ] ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_12 - 2 ; V_19 ++ )
V_18 [ V_19 ] = ( ( char * ) V_20 ) + V_13 * V_19 ;
V_17 = ( void * ) F_4 ( V_21 , 1 ) ;
if ( ! V_17 ) {
F_2 ( L_3 ) ;
return - V_22 ;
}
V_18 [ V_12 - 2 ] = V_17 ;
V_18 [ V_12 - 1 ] = V_17 + V_13 ;
V_15 = F_5 ( & V_18 , V_12 ) ;
V_16 = F_1 () ;
F_6 ( ( unsigned long ) V_17 , 1 ) ;
return V_15 && V_16 ? 0 : - V_23 ;
}
static void F_7 ( void )
{
do { } while ( 0 );
}
