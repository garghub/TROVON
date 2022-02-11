static unsigned long T_1 * F_1 ( struct V_1 * V_2 )
{
return ( unsigned long T_1 * )
( V_2 -> F_1 & ~ V_3 ) ;
}
int F_2 ( struct V_1 * V_2 , T_2 * V_4 ,
unsigned int V_5 , T_3 V_6 )
{
T_4 V_7 = F_3 ( T_4 , 1 << V_8 ,
F_4 (unsigned long) ) ;
unsigned long V_9 = 0 ;
V_2 -> F_1 = ( unsigned long )
F_5 ( sizeof( unsigned long ) , V_7 , V_6 ) ;
if ( ! V_2 -> F_1 )
return - V_10 ;
V_2 -> V_11 = V_5 & V_12 ;
if ( V_5 & ( V_12 | V_13 ) )
V_2 -> F_1 |= V_14 ;
else
V_9 += V_15 ;
if ( V_5 & V_13 )
V_2 -> F_1 |= V_16 ;
else
V_9 ++ ;
F_6 ( & V_2 -> V_17 , V_9 ) ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
unsigned long T_1 * V_18 = F_1 ( V_2 ) ;
if ( V_18 ) {
F_8 ( V_18 ) ;
V_2 -> F_1 = V_3 ;
}
}
static void F_9 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 , struct V_1 , V_20 ) ;
V_2 -> V_21 ( V_2 ) ;
V_2 -> V_21 = NULL ;
F_11 ( & V_22 ) ;
F_12 ( V_2 ) ;
}
static void F_13 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 , struct V_1 , V_20 ) ;
unsigned long T_1 * V_18 = F_1 ( V_2 ) ;
unsigned long V_17 = 0 ;
int V_23 ;
F_14 (cpu)
V_17 += * F_15 ( V_18 , V_23 ) ;
F_16 ( L_1 ,
F_17 ( & V_2 -> V_17 ) , ( long ) V_17 ) ;
F_18 ( ( long ) V_17 - V_15 , & V_2 -> V_17 ) ;
F_19 ( F_17 ( & V_2 -> V_17 ) <= 0 ,
L_2 ,
V_2 -> V_4 , F_17 ( & V_2 -> V_17 ) ) ;
F_9 ( V_20 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
}
static void F_21 ( struct V_1 * V_2 ,
T_2 * V_21 )
{
if ( ! ( V_2 -> F_1 & V_14 ) ) {
V_2 -> F_1 |= V_14 ;
F_22 ( V_2 -> V_21 ) ;
V_2 -> V_21 =
V_21 ? : F_20 ;
F_23 ( V_2 ) ;
F_24 ( & V_2 -> V_20 , F_13 ) ;
} else if ( V_21 ) {
F_25 ( V_22 , ! V_2 -> V_21 ) ;
V_2 -> V_21 = V_21 ;
F_23 ( V_2 ) ;
F_24 ( & V_2 -> V_20 , F_9 ) ;
}
}
void F_26 ( struct V_1 * V_2 ,
T_2 * V_21 )
{
V_2 -> V_11 = true ;
F_21 ( V_2 , V_21 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned long T_1 * V_18 = F_1 ( V_2 ) ;
int V_23 ;
F_28 ( ! V_18 ) ;
if ( ! ( V_2 -> F_1 & V_14 ) )
return;
F_25 ( V_22 , ! V_2 -> V_21 ) ;
F_18 ( V_15 , & V_2 -> V_17 ) ;
F_14 ( V_23 )
* F_15 ( V_18 , V_23 ) = 0 ;
F_29 ( & V_2 -> F_1 ,
V_2 -> F_1 & ~ V_14 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_11 = false ;
if ( ! ( V_2 -> F_1 & V_16 ) )
F_27 ( V_2 ) ;
}
void F_31 ( struct V_1 * V_2 ,
T_2 * V_24 )
{
F_19 ( V_2 -> F_1 & V_16 ,
L_3 , V_25 , V_2 -> V_4 ) ;
V_2 -> F_1 |= V_16 ;
F_21 ( V_2 , V_24 ) ;
F_12 ( V_2 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_22 ( ! F_33 ( V_2 ) ) ;
V_2 -> F_1 &= ~ V_16 ;
F_23 ( V_2 ) ;
if ( ! V_2 -> V_11 )
F_27 ( V_2 ) ;
}
