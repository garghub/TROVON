static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_4 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_9 + F_6 ( V_4 ) ) ;
if ( ! ( V_7 & F_7 ( V_4 ) ) ) {
F_8 ( & V_5 -> V_8 , V_6 ) ;
return - V_10 ;
}
V_7 &= ~ F_7 ( V_4 ) ;
F_9 ( V_7 , V_5 -> V_9 + F_6 ( V_4 ) ) ;
F_8 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_4 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_9 + F_6 ( V_4 ) ) ;
V_7 |= F_7 ( V_4 ) ;
F_9 ( V_7 , V_5 -> V_9 + F_6 ( V_4 ) ) ;
F_8 ( & V_5 -> V_8 , V_6 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
F_4 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_9 + F_12 ( V_4 ) ) ;
V_7 &= ~ F_7 ( V_4 ) ;
F_9 ( V_7 , V_5 -> V_9 + F_12 ( V_4 ) ) ;
F_8 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
unsigned V_4 , int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
F_4 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_9 + F_14 ( V_4 ) ) ;
if ( V_11 )
V_7 |= F_7 ( V_4 ) ;
else
V_7 &= ~ F_7 ( V_4 ) ;
F_9 ( V_7 , V_5 -> V_9 + F_14 ( V_4 ) ) ;
V_7 = F_5 ( V_5 -> V_9 + F_12 ( V_4 ) ) ;
V_7 |= F_7 ( V_4 ) ;
F_9 ( V_7 , V_5 -> V_9 + F_12 ( V_4 ) ) ;
F_8 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ! ! ( F_5 ( V_5 -> V_9 + F_14 ( V_4 ) ) & F_7 ( V_4 ) ) ;
}
static void F_16 ( struct V_2 * V_3 , unsigned V_4 , int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
F_4 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_5 ( V_5 -> V_9 + F_14 ( V_4 ) ) ;
if ( V_11 )
V_7 |= F_7 ( V_4 ) ;
else
V_7 &= ~ F_7 ( V_4 ) ;
F_9 ( V_7 , V_5 -> V_9 + F_14 ( V_4 ) ) ;
F_8 ( & V_5 -> V_8 , V_6 ) ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_1 * V_5 ;
struct V_14 * V_15 ;
int V_16 ;
V_5 = F_18 ( & V_13 -> V_17 , sizeof( * V_5 ) , V_18 ) ;
if ( V_5 == NULL )
return - V_19 ;
F_19 ( V_13 , V_5 ) ;
V_15 = F_20 ( V_13 , V_20 , 0 ) ;
V_5 -> V_9 = F_21 ( & V_13 -> V_17 , V_15 ) ;
if ( F_22 ( V_5 -> V_9 ) )
return F_23 ( V_5 -> V_9 ) ;
V_5 -> V_21 = F_24 ( & V_13 -> V_17 , NULL ) ;
if ( F_22 ( V_5 -> V_21 ) )
return F_23 ( V_5 -> V_21 ) ;
F_25 ( V_5 -> V_21 ) ;
F_26 ( & V_5 -> V_8 ) ;
V_5 -> V_3 . V_22 = F_13 ;
V_5 -> V_3 . V_23 = F_11 ;
V_5 -> V_3 . V_24 = F_3 ;
V_5 -> V_3 . free = F_10 ;
V_5 -> V_3 . V_25 = F_15 ;
V_5 -> V_3 . V_26 = F_16 ;
V_5 -> V_3 . V_27 = F_27 ( & V_13 -> V_17 ) ;
V_5 -> V_3 . V_28 = 32 ;
V_5 -> V_3 . V_29 = V_30 ;
V_5 -> V_3 . V_17 = & V_13 -> V_17 ;
V_5 -> V_3 . V_9 = - 1 ;
F_19 ( V_13 , V_5 ) ;
V_16 = F_28 ( & V_5 -> V_3 ) ;
if ( V_16 ) {
F_29 ( & V_13 -> V_17 , L_1 ) ;
F_30 ( V_5 -> V_21 ) ;
}
return V_16 ;
}
static int F_31 ( struct V_12 * V_13 )
{
struct V_1 * V_5 = F_32 ( V_13 ) ;
F_33 ( & V_5 -> V_3 ) ;
F_30 ( V_5 -> V_21 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_31 ) ;
}
