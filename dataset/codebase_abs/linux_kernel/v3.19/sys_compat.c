static long
F_1 ( unsigned long V_1 , unsigned long V_2 )
{
long V_3 ;
do {
unsigned long V_4 = F_2 ( V_5 , V_2 - V_1 ) ;
if ( F_3 ( V_6 ) )
return 0 ;
V_3 = F_4 ( V_1 , V_1 + V_4 ) ;
if ( V_3 )
return V_3 ;
F_5 () ;
V_1 += V_4 ;
} while ( V_1 < V_2 );
return 0 ;
}
static inline long
F_6 ( unsigned long V_1 , unsigned long V_2 , int V_7 )
{
if ( V_2 < V_1 || V_7 )
return - V_8 ;
if ( ! F_7 ( V_9 , V_1 , V_2 - V_1 ) )
return - V_10 ;
return F_1 ( V_1 , V_2 ) ;
}
long F_8 ( struct V_11 * V_12 )
{
unsigned int V_13 = V_12 -> V_12 [ 7 ] ;
switch ( V_13 ) {
case V_14 :
return F_6 ( V_12 -> V_12 [ 0 ] , V_12 -> V_12 [ 1 ] , V_12 -> V_12 [ 2 ] ) ;
case V_15 :
V_6 -> V_16 . V_17 = V_12 -> V_12 [ 0 ] ;
F_9 () ;
asm ("msr tpidrro_el0, %0" : : "r" (regs->regs[0]));
return 0 ;
default:
return - V_18 ;
}
}
