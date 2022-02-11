static int T_1 F_1 ( struct V_1 * V_2 )
{
V_3 = (struct V_4 * ) V_2 ;
return 0 ;
}
static int T_1 F_2 ( void )
{
unsigned long V_5 ;
unsigned int V_6 = 0 ;
void * V_7 ;
int V_8 ;
for ( V_5 = V_9 ; V_5 < V_10 ; V_5 += 16 ) {
if ( V_5 == V_11 )
V_5 += V_12 ;
V_7 = F_3 ( V_5 ) ;
for ( V_8 = 0 ; V_8 < F_4 ( V_13 ) ; V_8 ++ ) {
if ( memcmp ( V_7 , V_13 [ V_8 ] . V_14 , V_15 ) ==
0 ) {
unsigned long * V_16 =
( unsigned long * ) F_3 ( V_5 + 4 ) ;
V_6 = * V_16 ;
if ( V_5 + V_6 <= ( V_10 - 1 ) ) {
V_3 = (struct V_4 * ) V_7 ;
goto V_17;
}
}
}
}
V_17:
return V_6 ;
}
unsigned long T_1 F_5 ( unsigned long * V_18 )
{
#ifdef F_6
int V_8 ;
#endif
V_3 = NULL ;
#ifdef F_6
for ( V_8 = 0 ; V_8 < F_4 ( V_13 ) && ! V_3 ; V_8 ++ )
F_7 ( V_13 [ V_8 ] . V_14 , F_1 ) ;
#endif
if ( ! V_3 && ! V_19 )
F_2 () ;
if ( V_3 ) {
* V_18 = F_8 ( V_3 -> V_2 . V_20 ) ;
return ( V_21 ) F_9 ( V_3 ) ;
}
* V_18 = 0 ;
return 0 ;
}
