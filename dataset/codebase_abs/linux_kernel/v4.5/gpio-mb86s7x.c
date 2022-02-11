static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_9 + F_5 ( V_3 ) ) ;
if ( ! ( V_7 & F_6 ( V_3 ) ) ) {
F_7 ( & V_5 -> V_8 , V_6 ) ;
return - V_10 ;
}
V_7 &= ~ F_6 ( V_3 ) ;
F_8 ( V_7 , V_5 -> V_9 + F_5 ( V_3 ) ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_9 + F_5 ( V_3 ) ) ;
V_7 |= F_6 ( V_3 ) ;
F_8 ( V_7 , V_5 -> V_9 + F_5 ( V_3 ) ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_9 + F_11 ( V_3 ) ) ;
V_7 &= ~ F_6 ( V_3 ) ;
F_8 ( V_7 , V_5 -> V_9 + F_11 ( V_3 ) ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_3 , int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_9 + F_13 ( V_3 ) ) ;
if ( V_11 )
V_7 |= F_6 ( V_3 ) ;
else
V_7 &= ~ F_6 ( V_3 ) ;
F_8 ( V_7 , V_5 -> V_9 + F_13 ( V_3 ) ) ;
V_7 = F_4 ( V_5 -> V_9 + F_11 ( V_3 ) ) ;
V_7 |= F_6 ( V_3 ) ;
F_8 ( V_7 , V_5 -> V_9 + F_11 ( V_3 ) ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return ! ! ( F_4 ( V_5 -> V_9 + F_13 ( V_3 ) ) & F_6 ( V_3 ) ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned V_3 , int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_9 + F_13 ( V_3 ) ) ;
if ( V_11 )
V_7 |= F_6 ( V_3 ) ;
else
V_7 &= ~ F_6 ( V_3 ) ;
F_8 ( V_7 , V_5 -> V_9 + F_13 ( V_3 ) ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_16 ;
V_5 = F_17 ( & V_13 -> V_17 , sizeof( * V_5 ) , V_18 ) ;
if ( V_5 == NULL )
return - V_19 ;
F_18 ( V_13 , V_5 ) ;
V_15 = F_19 ( V_13 , V_20 , 0 ) ;
V_5 -> V_9 = F_20 ( & V_13 -> V_17 , V_15 ) ;
if ( F_21 ( V_5 -> V_9 ) )
return F_22 ( V_5 -> V_9 ) ;
V_5 -> V_21 = F_23 ( & V_13 -> V_17 , NULL ) ;
if ( F_21 ( V_5 -> V_21 ) )
return F_22 ( V_5 -> V_21 ) ;
F_24 ( V_5 -> V_21 ) ;
F_25 ( & V_5 -> V_8 ) ;
V_5 -> V_2 . V_22 = F_12 ;
V_5 -> V_2 . V_23 = F_10 ;
V_5 -> V_2 . V_24 = F_1 ;
V_5 -> V_2 . free = F_9 ;
V_5 -> V_2 . V_25 = F_14 ;
V_5 -> V_2 . V_26 = F_15 ;
V_5 -> V_2 . V_27 = F_26 ( & V_13 -> V_17 ) ;
V_5 -> V_2 . V_28 = 32 ;
V_5 -> V_2 . V_29 = V_30 ;
V_5 -> V_2 . V_31 = & V_13 -> V_17 ;
V_5 -> V_2 . V_9 = - 1 ;
F_18 ( V_13 , V_5 ) ;
V_16 = F_27 ( & V_5 -> V_2 , V_5 ) ;
if ( V_16 ) {
F_28 ( & V_13 -> V_17 , L_1 ) ;
F_29 ( V_5 -> V_21 ) ;
}
return V_16 ;
}
static int F_30 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_31 ( V_13 ) ;
F_32 ( & V_5 -> V_2 ) ;
F_29 ( V_5 -> V_21 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_32 ) ;
}
