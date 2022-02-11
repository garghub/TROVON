static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , bool assert )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_5 ;
T_1 V_6 ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_4 ( V_4 -> V_8 ) ;
if ( assert )
V_6 |= F_5 ( V_3 ) ;
else
V_6 &= ~ F_5 ( V_3 ) ;
F_6 ( V_6 , V_4 -> V_8 ) ;
F_7 ( & V_4 -> V_7 , V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , true ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , false ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 V_6 ;
V_6 = F_4 ( V_4 -> V_8 ) ;
return ! ! ( V_6 & F_5 ( V_3 ) ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_4 * V_4 ;
struct V_11 * V_12 ;
V_4 = F_12 ( & V_10 -> V_13 ,
sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
F_13 ( V_10 , V_4 ) ;
V_12 = F_14 ( V_10 , V_16 , 0 ) ;
V_4 -> V_8 = F_15 ( & V_10 -> V_13 , V_12 ) ;
if ( F_16 ( V_4 -> V_8 ) )
return F_17 ( V_4 -> V_8 ) ;
F_18 ( & V_4 -> V_7 ) ;
V_4 -> V_2 . V_17 = & V_18 ;
V_4 -> V_2 . V_19 = V_20 ;
V_4 -> V_2 . V_21 = V_10 -> V_13 . V_21 ;
V_4 -> V_2 . V_22 = 1 ;
V_4 -> V_2 . V_23 = 32 ;
return F_19 ( & V_4 -> V_2 ) ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_4 * V_4 = F_21 ( V_10 ) ;
F_22 ( & V_4 -> V_2 ) ;
return 0 ;
}
