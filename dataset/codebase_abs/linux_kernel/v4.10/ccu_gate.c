void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
if ( ! V_3 )
return;
F_2 ( V_2 -> V_6 , V_4 ) ;
V_5 = F_3 ( V_2 -> V_7 + V_2 -> V_5 ) ;
F_4 ( V_5 & ~ V_3 , V_2 -> V_7 + V_2 -> V_5 ) ;
F_5 ( V_2 -> V_6 , V_4 ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
return F_1 ( & V_11 -> V_2 , V_11 -> V_12 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
if ( ! V_3 )
return 0 ;
F_2 ( V_2 -> V_6 , V_4 ) ;
V_5 = F_3 ( V_2 -> V_7 + V_2 -> V_5 ) ;
F_4 ( V_5 | V_3 , V_2 -> V_7 + V_2 -> V_5 ) ;
F_5 ( V_2 -> V_6 , V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
return F_8 ( & V_11 -> V_2 , V_11 -> V_12 ) ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! V_3 )
return 1 ;
return F_3 ( V_2 -> V_7 + V_2 -> V_5 ) & V_3 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
return F_10 ( & V_11 -> V_2 , V_11 -> V_12 ) ;
}
