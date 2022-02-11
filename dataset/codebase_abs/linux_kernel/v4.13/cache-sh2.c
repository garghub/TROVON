static void F_1 ( void * V_1 , int V_2 )
{
unsigned long V_3 ;
unsigned long V_4 , V_5 ;
V_4 = ( unsigned long ) V_1 & ~ ( V_6 - 1 ) ;
V_5 = ( ( unsigned long ) V_1 + V_2 + V_6 - 1 )
& ~ ( V_6 - 1 ) ;
for ( V_3 = V_4 ; V_3 < V_5 ; V_3 += V_6 ) {
unsigned long V_7 = V_8 | ( V_3 & 0x00000ff0 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
unsigned long V_10 = F_2 ( V_7 | ( V_9 << 12 ) ) ;
if ( ( V_10 & V_11 ) == ( V_3 & V_11 ) ) {
V_10 &= ~ V_12 ;
F_3 ( V_10 , V_7 | ( V_9 << 12 ) ) ;
}
}
}
}
static void F_4 ( void * V_1 , int V_2 )
{
unsigned long V_3 ;
unsigned long V_4 , V_5 ;
V_4 = ( unsigned long ) V_1 & ~ ( V_6 - 1 ) ;
V_5 = ( ( unsigned long ) V_1 + V_2 + V_6 - 1 )
& ~ ( V_6 - 1 ) ;
for ( V_3 = V_4 ; V_3 < V_5 ; V_3 += V_6 )
F_3 ( ( V_3 & V_11 ) ,
V_8 | ( V_3 & 0x00000ff0 ) | 0x00000008 ) ;
}
static void F_5 ( void * V_1 , int V_2 )
{
#ifdef F_6
unsigned long V_13 ;
unsigned long V_14 ;
F_7 ( V_14 ) ;
F_8 () ;
V_13 = F_2 ( V_15 ) ;
V_13 |= V_16 ;
F_3 ( V_13 , V_15 ) ;
F_9 () ;
F_10 ( V_14 ) ;
#else
unsigned long V_3 ;
unsigned long V_4 , V_5 ;
V_4 = ( unsigned long ) V_1 & ~ ( V_6 - 1 ) ;
V_5 = ( ( unsigned long ) V_1 + V_2 + V_6 - 1 )
& ~ ( V_6 - 1 ) ;
for ( V_3 = V_4 ; V_3 < V_5 ; V_3 += V_6 )
F_3 ( ( V_3 & V_11 ) ,
V_8 | ( V_3 & 0x00000ff0 ) | 0x00000008 ) ;
#endif
}
void T_1 F_11 ( void )
{
V_17 = F_1 ;
V_18 = F_4 ;
V_19 = F_5 ;
}
