void F_1 ( unsigned long * V_1 , unsigned long V_2 , int V_3 )
{
V_1 [ 0 ] = ( V_4 [ 0 ] + V_2 ) << V_3 ;
V_1 [ 1 ] = ( V_4 [ 1 ] + V_2 ) << V_3 ;
V_1 [ 2 ] = ( V_4 [ 2 ] + V_2 ) << V_3 ;
}
long F_2 ( struct V_5 * V_6 )
{
long V_7 , V_8 = 0 ;
V_7 = V_6 -> V_9 ;
V_7 += ( long ) V_6 -> V_10 ;
if ( V_7 != V_6 -> V_11 ) {
V_8 = V_7 - V_6 -> V_11 ;
V_6 -> V_11 = V_7 ;
}
return V_8 ;
}
static unsigned long
F_3 ( unsigned long V_12 , unsigned long exp , unsigned long V_13 )
{
V_12 *= exp ;
V_12 += V_13 * ( V_14 - exp ) ;
V_12 += 1UL << ( V_15 - 1 ) ;
return V_12 >> V_15 ;
}
static inline int F_4 ( void )
{
int V_16 = V_17 ;
F_5 () ;
if ( ! F_6 ( V_18 , V_19 ) )
V_16 ++ ;
return V_16 & 1 ;
}
static inline int F_7 ( void )
{
return V_17 & 1 ;
}
void F_8 ( void )
{
struct V_5 * V_6 = V_6 () ;
long V_8 ;
V_8 = F_2 ( V_6 ) ;
if ( V_8 ) {
int V_16 = F_4 () ;
F_9 ( V_8 , & V_20 [ V_16 ] ) ;
}
}
void F_10 ( void )
{
struct V_5 * V_6 = V_6 () ;
if ( F_6 ( V_18 , V_6 -> V_19 ) )
return;
V_6 -> V_19 = V_19 ;
if ( F_6 ( V_18 , V_6 -> V_19 + 10 ) )
V_6 -> V_19 += V_21 ;
}
static long F_11 ( void )
{
int V_16 = F_7 () ;
long V_8 = 0 ;
if ( F_12 ( & V_20 [ V_16 ] ) )
V_8 = F_13 ( & V_20 [ V_16 ] , 0 ) ;
return V_8 ;
}
static unsigned long
F_14 ( unsigned long V_22 , unsigned int V_23 , unsigned int V_24 )
{
unsigned long V_25 = 1UL << V_23 ;
if ( V_24 ) {
for (; ; ) {
if ( V_24 & 1 ) {
V_25 *= V_22 ;
V_25 += 1UL << ( V_23 - 1 ) ;
V_25 >>= V_23 ;
}
V_24 >>= 1 ;
if ( ! V_24 )
break;
V_22 *= V_22 ;
V_22 += 1UL << ( V_23 - 1 ) ;
V_22 >>= V_23 ;
}
}
return V_25 ;
}
static unsigned long
F_15 ( unsigned long V_12 , unsigned long exp ,
unsigned long V_13 , unsigned int V_24 )
{
return F_3 ( V_12 , F_14 ( exp , V_15 , V_24 ) , V_13 ) ;
}
static void F_16 ( void )
{
long V_8 , V_13 , V_24 ;
if ( ! F_6 ( V_18 , V_19 + 10 ) ) {
V_8 = V_18 - V_19 - 10 ;
V_24 = 1 + ( V_8 / V_21 ) ;
V_13 = F_12 ( & V_26 ) ;
V_13 = V_13 > 0 ? V_13 * V_14 : 0 ;
V_4 [ 0 ] = F_15 ( V_4 [ 0 ] , V_27 , V_13 , V_24 ) ;
V_4 [ 1 ] = F_15 ( V_4 [ 1 ] , V_28 , V_13 , V_24 ) ;
V_4 [ 2 ] = F_15 ( V_4 [ 2 ] , V_29 , V_13 , V_24 ) ;
V_19 += V_24 * V_21 ;
}
F_17 () ;
V_17 ++ ;
}
static inline long F_11 ( void ) { return 0 ; }
static inline void F_16 ( void ) { }
void F_18 ( unsigned long V_30 )
{
long V_13 , V_8 ;
if ( F_6 ( V_18 , V_19 + 10 ) )
return;
V_8 = F_11 () ;
if ( V_8 )
F_9 ( V_8 , & V_26 ) ;
V_13 = F_12 ( & V_26 ) ;
V_13 = V_13 > 0 ? V_13 * V_14 : 0 ;
V_4 [ 0 ] = F_3 ( V_4 [ 0 ] , V_27 , V_13 ) ;
V_4 [ 1 ] = F_3 ( V_4 [ 1 ] , V_28 , V_13 ) ;
V_4 [ 2 ] = F_3 ( V_4 [ 2 ] , V_29 , V_13 ) ;
V_19 += V_21 ;
F_16 () ;
}
void F_19 ( struct V_5 * V_6 )
{
long V_8 ;
if ( F_6 ( V_18 , V_6 -> V_19 ) )
return;
V_8 = F_2 ( V_6 ) ;
if ( V_8 )
F_9 ( V_8 , & V_26 ) ;
V_6 -> V_19 += V_21 ;
}
