static inline void
F_1 ( unsigned long V_1 , unsigned long V_2 , int V_3 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_8 * V_9 ;
if ( V_2 < V_1 || V_3 )
return;
F_2 ( & V_5 -> V_10 ) ;
V_9 = F_3 ( V_5 , V_1 ) ;
if ( V_9 && V_9 -> V_11 < V_2 ) {
if ( V_1 < V_9 -> V_11 )
V_1 = V_9 -> V_11 ;
if ( V_2 > V_9 -> V_12 )
V_2 = V_9 -> V_12 ;
F_4 ( & V_5 -> V_10 ) ;
F_5 ( V_1 & V_13 , F_6 ( V_2 ) ) ;
return;
}
F_4 ( & V_5 -> V_10 ) ;
}
long F_7 ( struct V_14 * V_15 )
{
unsigned int V_16 = V_15 -> V_15 [ 7 ] ;
switch ( V_16 ) {
case V_17 :
F_1 ( V_15 -> V_15 [ 0 ] , V_15 -> V_15 [ 1 ] , V_15 -> V_15 [ 2 ] ) ;
return 0 ;
case V_18 :
V_6 -> V_19 . V_20 = V_15 -> V_15 [ 0 ] ;
F_8 () ;
asm ("msr tpidrro_el0, %0" : : "r" (regs->regs[0]));
return 0 ;
default:
return - V_21 ;
}
}
