void F_1 ( unsigned long * V_1 , unsigned long V_2 , int V_3 )
{
V_1 [ 0 ] = ( V_4 [ 0 ] + V_2 ) << V_3 ;
V_1 [ 1 ] = ( V_4 [ 1 ] + V_2 ) << V_3 ;
V_1 [ 2 ] = ( V_4 [ 2 ] + V_2 ) << V_3 ;
}
long F_2 ( struct V_5 * V_6 , long V_7 )
{
long V_8 , V_9 = 0 ;
V_8 = V_6 -> V_10 - V_7 ;
V_8 += ( long ) V_6 -> V_11 ;
if ( V_8 != V_6 -> V_12 ) {
V_9 = V_8 - V_6 -> V_12 ;
V_6 -> V_12 = V_8 ;
}
return V_9 ;
}
static unsigned long
F_3 ( unsigned long V_13 , unsigned long exp , unsigned long V_14 )
{
unsigned long V_15 ;
V_15 = V_13 * exp + V_14 * ( V_16 - exp ) ;
if ( V_14 >= V_13 )
V_15 += V_16 - 1 ;
return V_15 / V_16 ;
}
static inline int F_4 ( void )
{
int V_17 = V_18 ;
F_5 () ;
if ( ! F_6 ( V_19 , F_7 ( V_20 ) ) )
V_17 ++ ;
return V_17 & 1 ;
}
static inline int F_8 ( void )
{
return V_18 & 1 ;
}
void F_9 ( void )
{
struct V_5 * V_6 = V_6 () ;
long V_9 ;
V_9 = F_2 ( V_6 , 0 ) ;
if ( V_9 ) {
int V_17 = F_4 () ;
F_10 ( V_9 , & V_21 [ V_17 ] ) ;
}
}
void F_11 ( void )
{
struct V_5 * V_6 = V_6 () ;
V_6 -> V_20 = F_7 ( V_20 ) ;
if ( F_6 ( V_19 , V_6 -> V_20 ) )
return;
if ( F_6 ( V_19 , V_6 -> V_20 + 10 ) )
V_6 -> V_20 += V_22 ;
}
static long F_12 ( void )
{
int V_17 = F_8 () ;
long V_9 = 0 ;
if ( F_13 ( & V_21 [ V_17 ] ) )
V_9 = F_14 ( & V_21 [ V_17 ] , 0 ) ;
return V_9 ;
}
static unsigned long
F_15 ( unsigned long V_23 , unsigned int V_24 , unsigned int V_25 )
{
unsigned long V_26 = 1UL << V_24 ;
if ( V_25 ) {
for (; ; ) {
if ( V_25 & 1 ) {
V_26 *= V_23 ;
V_26 += 1UL << ( V_24 - 1 ) ;
V_26 >>= V_24 ;
}
V_25 >>= 1 ;
if ( ! V_25 )
break;
V_23 *= V_23 ;
V_23 += 1UL << ( V_24 - 1 ) ;
V_23 >>= V_24 ;
}
}
return V_26 ;
}
static unsigned long
F_16 ( unsigned long V_13 , unsigned long exp ,
unsigned long V_14 , unsigned int V_25 )
{
return F_3 ( V_13 , F_15 ( exp , V_27 , V_25 ) , V_14 ) ;
}
static void F_17 ( void )
{
unsigned long V_28 ;
long V_9 , V_14 , V_25 ;
V_28 = F_7 ( V_20 ) ;
if ( ! F_6 ( V_19 , V_28 + 10 ) ) {
V_9 = V_19 - V_28 - 10 ;
V_25 = 1 + ( V_9 / V_22 ) ;
V_14 = F_13 ( & V_29 ) ;
V_14 = V_14 > 0 ? V_14 * V_16 : 0 ;
V_4 [ 0 ] = F_16 ( V_4 [ 0 ] , V_30 , V_14 , V_25 ) ;
V_4 [ 1 ] = F_16 ( V_4 [ 1 ] , V_31 , V_14 , V_25 ) ;
V_4 [ 2 ] = F_16 ( V_4 [ 2 ] , V_32 , V_14 , V_25 ) ;
F_18 ( V_20 , V_28 + V_25 * V_22 ) ;
}
F_19 () ;
V_18 ++ ;
}
static inline long F_12 ( void ) { return 0 ; }
static inline void F_17 ( void ) { }
void F_20 ( unsigned long V_33 )
{
unsigned long V_28 ;
long V_14 , V_9 ;
V_28 = F_7 ( V_20 ) ;
if ( F_6 ( V_19 , V_28 + 10 ) )
return;
V_9 = F_12 () ;
if ( V_9 )
F_10 ( V_9 , & V_29 ) ;
V_14 = F_13 ( & V_29 ) ;
V_14 = V_14 > 0 ? V_14 * V_16 : 0 ;
V_4 [ 0 ] = F_3 ( V_4 [ 0 ] , V_30 , V_14 ) ;
V_4 [ 1 ] = F_3 ( V_4 [ 1 ] , V_31 , V_14 ) ;
V_4 [ 2 ] = F_3 ( V_4 [ 2 ] , V_32 , V_14 ) ;
F_18 ( V_20 , V_28 + V_22 ) ;
F_17 () ;
}
void F_21 ( struct V_5 * V_6 )
{
long V_9 ;
if ( F_6 ( V_19 , V_6 -> V_20 ) )
return;
V_9 = F_2 ( V_6 , 0 ) ;
if ( V_9 )
F_10 ( V_9 , & V_29 ) ;
V_6 -> V_20 += V_22 ;
}
