static unsigned T_1 * F_1 ( struct V_1 * V_2 )
{
return ( unsigned T_1 * ) ( V_2 -> F_1 & ~ V_3 ) ;
}
int F_2 ( struct V_1 * V_2 , T_2 * V_4 )
{
F_3 ( & V_2 -> V_5 , 1 + V_6 ) ;
V_2 -> F_1 = ( unsigned long ) F_4 ( unsigned ) ;
if ( ! V_2 -> F_1 )
return - V_7 ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
unsigned T_1 * V_8 = F_1 ( V_2 ) ;
int V_9 ;
F_6 ( ! V_8 ) ;
F_7 ( ! F_8 ( V_2 ) ) ;
F_3 ( & V_2 -> V_5 , 1 + V_6 ) ;
F_9 ( V_9 )
* F_10 ( V_8 , V_9 ) = 0 ;
F_11 ( & V_2 -> F_1 ,
V_2 -> F_1 & ~ V_3 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
unsigned T_1 * V_8 = F_1 ( V_2 ) ;
if ( V_8 ) {
F_13 ( V_8 ) ;
V_2 -> F_1 = V_3 ;
}
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_15 ( V_11 , struct V_1 , V_11 ) ;
unsigned T_1 * V_8 = F_1 ( V_2 ) ;
unsigned V_5 = 0 ;
int V_9 ;
F_9 (cpu)
V_5 += * F_10 ( V_8 , V_9 ) ;
F_16 ( L_1 , F_17 ( & V_2 -> V_5 ) , ( int ) V_5 ) ;
F_18 ( ( int ) V_5 - V_6 , & V_2 -> V_5 ) ;
F_19 ( F_17 ( & V_2 -> V_5 ) <= 0 , L_2 ,
F_17 ( & V_2 -> V_5 ) ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 ( V_2 ) ;
F_20 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 ,
T_2 * V_12 )
{
F_19 ( V_2 -> F_1 & V_3 ,
L_3 ) ;
V_2 -> F_1 |= V_3 ;
V_2 -> V_12 = V_12 ;
F_22 ( & V_2 -> V_11 , F_14 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> F_1 & V_3 ,
L_4 ,
V_2 -> V_4 ) ;
V_2 -> F_1 |= V_3 ;
F_24 () ;
F_14 ( & V_2 -> V_11 ) ;
}
