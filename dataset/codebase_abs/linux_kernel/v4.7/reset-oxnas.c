static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( V_5 -> V_6 , V_7 , F_4 ( V_3 ) ) ;
F_5 ( 50 ) ;
F_3 ( V_5 -> V_6 , V_8 , F_4 ( V_3 ) ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( V_5 -> V_6 , V_7 , F_4 ( V_3 ) ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( V_5 -> V_6 , V_8 , F_4 ( V_3 ) ) ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
V_12 = V_10 -> V_13 . V_12 ;
if ( ! V_12 ) {
F_9 ( & V_10 -> V_13 , L_1 ) ;
return - V_14 ;
}
V_5 = F_10 ( & V_10 -> V_13 , sizeof( * V_5 ) , V_15 ) ;
if ( ! V_5 )
return - V_16 ;
V_5 -> V_6 = F_11 ( V_12 -> V_17 ) ;
if ( F_12 ( V_5 -> V_6 ) ) {
F_9 ( & V_10 -> V_13 , L_2 ) ;
return F_13 ( V_5 -> V_6 ) ;
}
F_14 ( V_10 , V_5 ) ;
V_5 -> V_2 . V_18 = V_19 ;
V_5 -> V_2 . V_20 = 32 ;
V_5 -> V_2 . V_21 = & V_22 ;
V_5 -> V_2 . V_17 = V_10 -> V_13 . V_17 ;
return F_15 ( & V_5 -> V_2 ) ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = F_17 ( V_10 ) ;
F_18 ( & V_5 -> V_2 ) ;
return 0 ;
}
