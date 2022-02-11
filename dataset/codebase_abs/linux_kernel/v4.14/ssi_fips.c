static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
void T_2 * V_4 = V_2 -> V_4 ;
V_3 = F_2 ( F_3 ( V_5 , V_6 ) ) ;
return ( V_3 == ( V_7 | V_8 ) ) ;
}
void F_4 ( struct V_1 * V_2 , bool V_9 )
{
void T_2 * V_4 = V_2 -> V_4 ;
int V_10 = V_11 ;
V_10 |= ( V_9 ? V_8 : V_12 ) ;
F_5 ( F_3 ( V_5 , V_13 ) , V_10 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
if ( ! V_15 )
return;
F_7 ( & V_15 -> V_17 ) ;
F_8 ( V_15 ) ;
V_2 -> V_16 = NULL ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_14 * V_18 =
V_2 -> V_16 ;
F_10 ( & V_18 -> V_17 ) ;
}
static inline void F_11 ( void )
{
if ( V_19 )
F_12 ( L_1 ) ;
else
F_13 ( L_2 ) ;
}
static void F_14 ( unsigned long V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
void T_2 * V_4 = V_2 -> V_4 ;
T_1 V_21 , V_22 , V_10 ;
V_21 = ( V_2 -> V_21 & ( V_23 ) ) ;
if ( V_21 ) {
V_22 = F_2 ( F_3 ( V_5 , V_6 ) ) ;
if ( V_22 != ( V_7 | V_8 ) )
F_11 () ;
}
V_10 = ( F_3 ( V_5 , V_24 ) & ~ V_21 ) ;
F_5 ( F_3 ( V_5 , V_24 ) , V_10 ) ;
}
int F_15 ( struct V_1 * V_25 )
{
struct V_14 * V_15 ;
V_15 = F_16 ( sizeof( * V_15 ) , V_26 ) ;
if ( ! V_15 )
return - V_27 ;
V_25 -> V_16 = V_15 ;
F_17 ( L_3 ) ;
F_18 ( & V_15 -> V_17 , F_14 , ( unsigned long ) V_25 ) ;
if ( ! F_1 ( V_25 ) )
F_11 () ;
return 0 ;
}
