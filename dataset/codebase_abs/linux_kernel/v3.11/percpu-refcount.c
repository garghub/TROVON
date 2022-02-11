int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
F_2 ( & V_2 -> V_4 , 1 + V_5 ) ;
V_2 -> V_6 = F_3 ( unsigned ) ;
if ( ! V_2 -> V_6 )
return - V_7 ;
V_2 -> V_3 = V_3 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
unsigned T_2 * V_6 = V_2 -> V_6 ;
int V_8 ;
F_5 ( F_6 ( & V_2 -> V_4 ) != 1 + V_5 ) ;
if ( V_6 ) {
F_7 (cpu)
F_5 ( * F_8 ( V_6 , V_8 ) ) ;
F_9 ( V_2 -> V_6 ) ;
}
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 , struct V_1 , V_10 ) ;
unsigned T_2 * V_6 = V_2 -> V_6 ;
unsigned V_4 = 0 ;
int V_8 ;
V_6 = ( unsigned T_2 * )
( ( ( unsigned long ) V_6 ) & ~ V_11 ) ;
F_7 (cpu)
V_4 += * F_8 ( V_6 , V_8 ) ;
F_9 ( V_6 ) ;
F_12 ( L_1 , F_6 ( & V_2 -> V_4 ) , ( int ) V_4 ) ;
F_13 ( ( int ) V_4 - V_5 , & V_2 -> V_4 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 ( V_2 ) ;
F_14 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 ,
T_1 * V_12 )
{
F_16 ( F_17 ( V_2 -> V_6 ) == V_13 ,
L_2 ) ;
V_2 -> V_6 = ( unsigned T_2 * )
( ( ( unsigned long ) V_2 -> V_6 ) | V_13 ) ;
V_2 -> V_12 = V_12 ;
F_18 ( & V_2 -> V_10 , F_10 ) ;
}
