static int T_1 F_1 ( void )
{
unsigned long V_1 ;
unsigned int V_2 = 0 ;
void * V_3 ;
int V_4 ;
for ( V_1 = V_5 ; V_1 < V_6 ; V_1 += 16 ) {
if ( V_1 == V_7 )
V_1 += V_8 ;
V_3 = F_2 ( V_1 ) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_9 ) ; V_4 ++ ) {
if ( memcmp ( V_3 , V_9 [ V_4 ] . V_10 , V_11 ) ==
0 ) {
unsigned long * V_12 =
( unsigned long * ) F_2 ( V_1 + 4 ) ;
V_2 = * V_12 ;
if ( V_1 + V_2 <= ( V_6 - 1 ) ) {
V_13 = (struct V_14 * ) V_3 ;
F_4 ( L_1 , V_1 ) ;
goto V_15;
}
}
}
}
V_15:
return V_2 ;
}
unsigned long T_1 F_5 ( unsigned long * V_16 )
{
V_13 = NULL ;
if ( ! V_17 )
F_1 () ;
if ( V_13 ) {
* V_16 = F_6 ( V_13 -> V_18 . V_19 ) ;
return ( V_20 ) F_7 ( V_13 ) ;
}
* V_16 = 0 ;
return 0 ;
}
