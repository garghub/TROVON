static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 , unsigned long V_4 , struct V_5 * V_6 )
{
void * V_7 , * V_8 ;
V_8 = F_2 ( V_3 , V_9 ) ;
V_7 = F_2 ( V_2 , V_10 ) ;
F_3 ( V_7 , V_8 ) ;
F_4 ( V_7 , V_11 ) ;
F_5 ( V_7 , V_10 ) ;
F_5 ( V_8 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_1 , unsigned long V_4 )
{
void * V_12 = F_2 ( V_1 , V_9 ) ;
F_7 ( V_12 ) ;
F_5 ( V_12 , V_9 ) ;
}
static void F_8 ( void * V_7 )
{
__asm__("mcrr p15, 0, %1, %0, c6 @ 0xec401f06"
:
: "r" (kto),
"r" ((unsigned long)kto + PAGE_SIZE - L1_CACHE_BYTES)
: "cc");
}
static void F_9 ( struct V_1 * V_2 ,
struct V_1 * V_3 , unsigned long V_4 , struct V_5 * V_6 )
{
unsigned int V_13 = F_10 ( V_4 ) ;
unsigned long V_8 , V_7 ;
if ( ! F_11 ( V_14 , & V_3 -> V_15 ) )
F_12 ( F_13 ( V_3 ) , V_3 ) ;
F_8 ( F_14 ( V_2 ) ) ;
F_15 ( & V_16 ) ;
F_16 ( F_17 ( V_17 ) + V_13 , F_18 ( F_19 ( V_3 ) , V_18 ) , 0 ) ;
F_16 ( F_17 ( V_19 ) + V_13 , F_18 ( F_19 ( V_2 ) , V_18 ) , 0 ) ;
V_8 = V_17 + ( V_13 << V_20 ) ;
V_7 = V_19 + ( V_13 << V_20 ) ;
F_20 ( V_8 ) ;
F_20 ( V_7 ) ;
F_3 ( ( void * ) V_7 , ( void * ) V_8 ) ;
F_21 ( & V_16 ) ;
}
static void F_22 ( struct V_1 * V_1 , unsigned long V_4 )
{
unsigned int V_13 = F_10 ( V_4 ) ;
unsigned long V_2 = V_19 + ( V_13 << V_20 ) ;
F_8 ( F_14 ( V_1 ) ) ;
F_15 ( & V_16 ) ;
F_16 ( F_17 ( V_19 ) + V_13 , F_18 ( F_19 ( V_1 ) , V_18 ) , 0 ) ;
F_20 ( V_2 ) ;
F_7 ( ( void * ) V_2 ) ;
F_21 ( & V_16 ) ;
}
static int T_1 F_23 ( void )
{
if ( F_24 () ) {
V_21 . V_22 = F_22 ;
V_21 . V_23 = F_9 ;
}
return 0 ;
}
