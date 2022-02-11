static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , bool assert )
{
struct V_4 * V_5 = NULL ;
int V_6 = V_3 / 32 ;
int V_7 = V_3 % 32 ;
T_1 V_8 ;
unsigned long V_9 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( & V_5 -> V_10 , V_9 ) ;
V_8 = F_4 ( V_5 -> V_11 + ( V_6 * 4 ) ) ;
if ( assert )
V_8 &= ~ F_5 ( V_7 ) ;
else
V_8 |= F_5 ( V_7 ) ;
F_6 ( V_8 , V_5 -> V_11 + ( V_6 * 4 ) ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
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
static int F_10 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
struct V_14 * V_15 ;
V_5 = F_11 ( & V_13 -> V_16 , sizeof( * V_5 ) , V_17 ) ;
if ( ! V_5 )
return - V_18 ;
V_15 = F_12 ( V_13 , V_19 , 0 ) ;
V_5 -> V_11 = F_13 ( & V_13 -> V_16 , V_15 ) ;
if ( F_14 ( V_5 -> V_11 ) )
return F_15 ( V_5 -> V_11 ) ;
F_16 ( & V_5 -> V_10 ) ;
V_5 -> V_2 . V_20 = V_21 ;
V_5 -> V_2 . V_22 = F_17 ( V_15 ) * 8 ;
V_5 -> V_2 . V_23 = & V_24 ;
V_5 -> V_2 . V_25 = V_13 -> V_16 . V_25 ;
return F_18 ( & V_13 -> V_16 , & V_5 -> V_2 ) ;
}
