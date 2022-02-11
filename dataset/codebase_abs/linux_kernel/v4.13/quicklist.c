static unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 , V_3 ;
int V_4 = F_2 () ;
struct V_5 * V_6 = F_3 ( V_4 ) -> V_7 ;
int V_8 ;
V_2 =
#ifdef F_4
F_5 ( & V_6 [ V_9 ] , V_10 ) +
#endif
#ifdef F_6
F_5 ( & V_6 [ V_11 ] , V_10 ) +
#endif
F_5 ( & V_6 [ V_12 ] , V_10 ) ;
V_3 = V_2 / V_13 ;
V_8 = F_7 ( F_8 ( V_4 ) ) ;
V_3 /= V_8 ;
return V_3 ( V_3 , V_1 ) ;
}
static long F_9 ( struct V_14 * V_15 ,
unsigned long V_1 , long V_16 )
{
long V_17 ;
V_17 = V_15 -> V_18 - F_1 ( V_1 ) ;
return F_10 ( V_17 , V_16 ) ;
}
void F_11 ( int V_19 , void (* F_12)( void * ) ,
unsigned long V_1 , unsigned long V_16 )
{
long V_17 ;
struct V_14 * V_15 ;
V_15 = & F_13 ( V_14 ) [ V_19 ] ;
if ( V_15 -> V_18 > V_1 ) {
V_17 = F_9 ( V_15 , V_1 , V_16 ) ;
while ( V_17 > 0 ) {
void * V_20 = F_14 ( V_19 , 0 , NULL ) ;
if ( F_12 )
F_12 ( V_20 ) ;
F_15 ( ( unsigned long ) V_20 ) ;
V_17 -- ;
}
}
F_16 ( V_14 ) ;
}
unsigned long F_17 ( void )
{
unsigned long V_21 = 0 ;
int V_22 ;
struct V_14 * V_23 , * V_15 ;
F_18 (cpu) {
V_23 = F_19 ( V_14 , V_22 ) ;
for ( V_15 = V_23 ; V_15 < V_23 + V_24 ; V_15 ++ )
V_21 += V_15 -> V_18 ;
}
return V_21 ;
}
