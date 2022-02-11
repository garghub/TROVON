static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_3 >> 8 ;
int V_7 = V_3 & 0xff ;
F_3 ( F_4 ( V_7 ) , V_5 -> V_8 + ( V_6 * 0x10 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_3 >> 8 ;
int V_7 = V_3 & 0xff ;
F_3 ( F_4 ( V_7 ) , V_5 -> V_9 + ( V_6 * 0x10 ) ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_4 * V_5 ;
struct V_12 * V_13 ;
void T_1 * V_14 ;
V_5 = F_7 ( & V_11 -> V_15 , sizeof( * V_5 ) , V_16 ) ;
if ( ! V_5 )
return - V_17 ;
V_13 = F_8 ( V_11 , V_18 , 0 ) ;
V_14 = F_9 ( & V_11 -> V_15 , V_13 ) ;
if ( F_10 ( V_14 ) )
return F_11 ( V_14 ) ;
V_5 -> V_8 = V_14 + V_19 ;
V_5 -> V_9 = V_14 + V_20 ;
V_5 -> V_2 . V_21 = V_22 ;
V_5 -> V_2 . V_23 = & V_24 ;
V_5 -> V_2 . V_25 = V_11 -> V_15 . V_25 ;
return F_12 ( & V_5 -> V_2 ) ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_26 ) ;
}
