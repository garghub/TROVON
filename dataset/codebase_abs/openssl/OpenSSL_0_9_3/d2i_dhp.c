T_1 * F_1 ( T_1 * * V_1 , unsigned char * * V_2 , long V_3 )
{
int V_4 = V_5 ;
T_2 * V_6 = NULL ;
long V_7 = 0 ;
F_2 ( V_1 , T_1 * , V_8 ) ;
F_3 () ;
F_4 () ;
F_5 ( V_6 , V_9 ) ;
if ( ( V_10 -> V_11 = F_6 ( V_6 -> V_12 , V_6 -> V_3 , V_10 -> V_11 ) ) == NULL ) goto V_13;
F_5 ( V_6 , V_9 ) ;
if ( ( V_10 -> V_14 = F_6 ( V_6 -> V_12 , V_6 -> V_3 , V_10 -> V_14 ) ) == NULL ) goto V_13;
if ( ! F_7 () )
{
F_5 ( V_6 , V_9 ) ;
for ( V_4 = 0 ; V_4 < V_6 -> V_3 ; V_4 ++ )
V_7 = ( V_7 << 8 ) | ( V_6 -> V_12 [ V_4 ] ) ;
V_10 -> V_3 = ( int ) V_7 ;
}
F_8 ( V_6 ) ;
F_9 ( V_1 ) ;
V_13:
V_4 = V_15 ;
V_16:
F_10 ( V_17 , V_4 ) ;
if ( ( V_10 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_10 ) ) ) F_11 ( V_10 ) ;
if ( V_6 != NULL ) F_8 ( V_6 ) ;
return ( NULL ) ;
}
