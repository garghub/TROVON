static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 ;
unsigned int V_6 ;
do {
V_5 = F_2 ( V_4 -> V_7 + V_8 ) & V_4 -> V_9 ;
F_3 (bit, &pending, CPLDS_NB_IRQ) {
F_4 ( F_5 ( V_4 -> V_10 ,
V_6 ) ) ;
}
} while ( V_5 );
return V_11 ;
}
static void F_6 ( struct V_12 * V_2 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
unsigned int V_13 = F_8 ( V_2 ) ;
unsigned int V_6 = F_9 ( V_13 ) ;
V_4 -> V_9 &= ~ V_6 ;
F_10 ( V_4 -> V_9 , V_4 -> V_7 + V_14 ) ;
}
static void F_11 ( struct V_12 * V_2 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
unsigned int V_13 = F_8 ( V_2 ) ;
unsigned int V_15 , V_6 = F_9 ( V_13 ) ;
V_15 = F_2 ( V_4 -> V_7 + V_8 ) ;
F_10 ( V_15 & ~ V_6 , V_4 -> V_7 + V_8 ) ;
V_4 -> V_9 |= V_6 ;
F_10 ( V_4 -> V_9 , V_4 -> V_7 + V_14 ) ;
}
static int F_12 ( struct V_16 * V_2 , unsigned int V_17 ,
T_2 V_18 )
{
struct V_3 * V_4 = V_2 -> V_19 ;
F_13 ( V_17 , & V_20 , V_21 ) ;
F_14 ( V_17 , V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = F_16 ( V_23 ) ;
F_10 ( V_4 -> V_9 , V_4 -> V_7 + V_14 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
struct V_3 * V_4 ;
int V_26 ;
int V_27 ;
unsigned long V_28 = 0 ;
V_4 = F_18 ( & V_23 -> V_29 , sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_17 = F_19 ( V_23 , 0 ) ;
if ( V_4 -> V_17 <= 0 )
return V_4 -> V_17 ;
V_27 = F_19 ( V_23 , 1 ) ;
if ( V_27 < 0 )
V_27 = 0 ;
V_25 = F_20 ( V_23 , V_32 , 0 ) ;
V_4 -> V_7 = F_21 ( & V_23 -> V_29 , V_25 ) ;
if ( F_22 ( V_4 -> V_7 ) )
return F_23 ( V_4 -> V_7 ) ;
F_24 ( V_23 , V_4 ) ;
F_10 ( V_4 -> V_9 , V_4 -> V_7 + V_14 ) ;
F_10 ( 0 , V_4 -> V_7 + V_8 ) ;
V_28 = F_25 ( V_4 -> V_17 ) ;
V_26 = F_26 ( & V_23 -> V_29 , V_4 -> V_17 , F_1 ,
V_28 , F_27 ( & V_23 -> V_29 ) , V_4 ) ;
if ( V_26 == - V_33 )
return - V_34 ;
if ( V_26 ) {
F_28 ( & V_23 -> V_29 , L_1 ,
V_4 -> V_17 , V_26 ) ;
return V_26 ;
}
F_29 ( V_4 -> V_17 , 1 ) ;
V_4 -> V_10 = F_30 ( V_23 -> V_29 . V_35 ,
V_36 ,
& V_37 , V_4 ) ;
if ( ! V_4 -> V_10 )
return - V_38 ;
if ( V_27 ) {
V_26 = F_31 ( V_4 -> V_10 , V_27 , 0 ,
V_36 ) ;
if ( V_26 ) {
F_28 ( & V_23 -> V_29 , L_2 ,
V_27 , V_27 + V_36 ) ;
return V_26 ;
}
}
return 0 ;
}
static int F_32 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = F_16 ( V_23 ) ;
F_13 ( V_4 -> V_17 , NULL , NULL ) ;
return 0 ;
}
