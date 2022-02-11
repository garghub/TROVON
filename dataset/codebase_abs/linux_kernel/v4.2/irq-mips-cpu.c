static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
F_3 () ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
F_6 () ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_8 () ;
F_9 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
F_10 ( V_5 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_8 () ;
F_9 ( 0x100 << ( V_2 -> V_3 - V_4 ) ) ;
F_10 ( V_5 ) ;
F_4 ( V_2 ) ;
}
T_1 void __weak F_12 ( void )
{
unsigned long V_6 = F_13 () & F_14 () & V_7 ;
int V_3 ;
if ( ! V_6 ) {
F_15 () ;
return;
}
V_6 >>= V_8 ;
while ( V_6 ) {
V_3 = F_16 ( V_6 ) - 1 ;
F_17 ( V_4 + V_3 ) ;
V_6 &= ~ F_18 ( V_3 ) ;
}
}
static int F_19 ( struct V_9 * V_2 , unsigned int V_3 ,
T_2 V_10 )
{
static struct V_11 * V_12 ;
if ( V_10 < 2 && V_13 ) {
V_12 = & V_14 ;
} else {
V_12 = & V_15 ;
}
if ( V_16 )
F_20 ( V_10 , F_12 ) ;
F_21 ( V_3 , V_12 , V_17 ) ;
return 0 ;
}
static void T_3 F_22 ( struct V_18 * V_19 )
{
struct V_9 * V_20 ;
F_5 ( V_7 ) ;
F_9 ( V_21 ) ;
V_20 = F_23 ( V_19 , 8 , V_4 , 0 ,
& V_22 , NULL ) ;
if ( ! V_20 )
F_24 ( L_1 ) ;
}
void T_3 F_25 ( void )
{
F_22 ( NULL ) ;
}
int T_3 F_26 ( struct V_18 * V_19 ,
struct V_18 * V_23 )
{
F_22 ( V_19 ) ;
return 0 ;
}
