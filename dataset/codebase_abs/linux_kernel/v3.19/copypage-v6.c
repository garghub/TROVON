static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 , unsigned long V_4 , struct V_5 * V_6 )
{
void * V_7 , * V_8 ;
V_8 = F_2 ( V_3 ) ;
V_7 = F_2 ( V_2 ) ;
F_3 ( V_7 , V_8 ) ;
F_4 ( V_7 ) ;
F_4 ( V_8 ) ;
}
static void F_5 ( struct V_1 * V_1 , unsigned long V_4 )
{
void * V_9 = F_2 ( V_1 ) ;
F_6 ( V_9 ) ;
F_4 ( V_9 ) ;
}
static void F_7 ( void * V_7 )
{
__asm__("mcrr p15, 0, %1, %0, c6 @ 0xec401f06"
:
: "r" (kto),
"r" ((unsigned long)kto + PAGE_SIZE - 1)
: "cc");
}
static void F_8 ( struct V_1 * V_2 ,
struct V_1 * V_3 , unsigned long V_4 , struct V_5 * V_6 )
{
unsigned int V_10 = F_9 ( V_4 ) ;
unsigned long V_8 , V_7 ;
if ( ! F_10 ( V_11 , & V_3 -> V_12 ) )
F_11 ( F_12 ( V_3 ) , V_3 ) ;
F_7 ( F_13 ( V_2 ) ) ;
F_14 ( & V_13 ) ;
V_8 = V_14 + ( V_10 << V_15 ) ;
V_7 = V_16 + ( V_10 << V_15 ) ;
F_15 ( V_8 , F_16 ( V_3 , V_17 ) ) ;
F_15 ( V_7 , F_16 ( V_2 , V_17 ) ) ;
F_3 ( ( void * ) V_7 , ( void * ) V_8 ) ;
F_17 ( & V_13 ) ;
}
static void F_18 ( struct V_1 * V_1 , unsigned long V_4 )
{
unsigned long V_2 = V_16 + ( F_9 ( V_4 ) << V_15 ) ;
F_7 ( F_13 ( V_1 ) ) ;
F_14 ( & V_13 ) ;
F_15 ( V_2 , F_16 ( V_1 , V_17 ) ) ;
F_6 ( ( void * ) V_2 ) ;
F_17 ( & V_13 ) ;
}
static int T_1 F_19 ( void )
{
if ( F_20 () ) {
V_18 . V_19 = F_18 ;
V_18 . V_20 = F_8 ;
}
return 0 ;
}
