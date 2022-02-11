static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_5 , V_2 -> V_3 + V_6 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_2 ( 1 << V_8 -> V_9 , V_2 -> V_3 + V_6 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_10 ;
V_10 = F_6 ( V_2 -> V_3 + V_4 ) ;
V_10 |= ( 1 << V_8 -> V_9 ) ;
F_2 ( V_10 , V_2 -> V_3 + V_4 ) ;
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_10 ;
V_10 = F_6 ( V_2 -> V_3 + V_4 ) ;
V_10 &= ~ ( 1 << V_8 -> V_9 ) ;
F_2 ( V_10 , V_2 -> V_3 + V_4 ) ;
}
static int F_8 ( struct V_11 * V_12 , unsigned int V_13 ,
T_2 V_9 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
F_9 ( V_13 ) ;
F_10 ( V_13 , V_2 ) ;
F_11 ( V_13 , & V_2 -> V_15 ,
V_16 ) ;
F_12 ( V_13 , V_17 ) ;
F_13 ( V_13 ) ;
return 0 ;
}
static void F_14 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
struct V_15 * V_20 = F_16 ( V_19 ) ;
unsigned long V_21 , V_22 ;
unsigned int V_23 ;
V_21 = F_17 ( V_2 -> V_3 + V_6 ) ;
F_18 ( V_20 , V_19 ) ;
F_19 (irqn, &irqmap, BITS_PER_LONG) {
V_23 = F_20 ( V_2 -> V_12 , V_22 ) ;
F_21 ( V_23 ) ;
}
F_22 ( V_20 , V_19 ) ;
}
static void F_23 ( void * V_24 )
{
struct V_1 * V_2 = V_24 ;
F_1 ( V_2 ) ;
F_24 ( V_2 -> V_25 , V_26 ) ;
}
static void F_25 ( void * V_24 )
{
struct V_1 * V_2 = V_24 ;
F_26 ( V_2 -> V_25 ) ;
}
static int F_27 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 . V_32 ;
struct V_1 * V_2 ;
struct V_15 * V_15 ;
struct V_33 * V_34 ;
V_2 = F_28 ( & V_28 -> V_31 , sizeof( struct V_1 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_34 = F_29 ( V_28 , V_37 , 0 ) ;
V_2 -> V_3 = F_30 ( & V_28 -> V_31 , V_34 ) ;
if ( F_31 ( V_2 -> V_3 ) )
return F_32 ( V_2 -> V_3 ) ;
V_15 = & V_2 -> V_15 ;
V_15 -> V_38 = F_33 ( & V_28 -> V_31 ) ;
V_15 -> V_39 = F_5 ;
V_15 -> V_40 = F_7 ;
V_15 -> V_41 = F_3 ;
V_2 -> V_25 = F_34 ( V_30 , 0 ) ;
if ( V_2 -> V_25 <= 0 ) {
F_35 ( & V_28 -> V_31 , L_1 ) ;
return - V_42 ;
}
V_2 -> V_12 = F_36 ( V_30 , V_43 ,
& V_44 , V_2 ) ;
if ( ! V_2 -> V_12 ) {
F_35 ( & V_28 -> V_31 , L_2 ) ;
return - V_36 ;
}
F_37 ( V_2 -> V_25 , F_14 ) ;
F_38 ( V_2 -> V_25 , V_2 ) ;
F_39 ( F_23 , V_2 , 1 ) ;
F_40 ( V_28 , V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_42 ( V_28 ) ;
F_39 ( F_25 , V_2 , 1 ) ;
F_43 ( V_2 -> V_12 ) ;
return 0 ;
}
