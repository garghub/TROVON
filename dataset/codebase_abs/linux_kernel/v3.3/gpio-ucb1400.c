static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( V_5 -> V_6 , V_3 , 0 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 , int V_7 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_3 ( V_5 -> V_6 , V_3 , 1 ) ;
F_5 ( V_5 -> V_6 , V_3 , V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
return F_7 ( V_5 -> V_6 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_3 , int V_7 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_5 ( V_5 -> V_6 , V_3 , V_7 ) ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_4 * V_10 = V_9 -> V_9 . V_11 ;
int V_12 = 0 ;
if ( ! ( V_13 && V_13 -> V_14 ) ) {
V_12 = - V_15 ;
goto V_12;
}
F_10 ( V_9 , V_10 ) ;
V_10 -> V_2 . V_16 = L_1 ;
V_10 -> V_2 . V_17 = V_13 -> V_14 ;
V_10 -> V_2 . V_18 = 10 ;
V_10 -> V_2 . V_19 = V_20 ;
V_10 -> V_2 . V_21 = F_1 ;
V_10 -> V_2 . V_22 = F_4 ;
V_10 -> V_2 . V_23 = F_6 ;
V_10 -> V_2 . V_24 = F_8 ;
V_10 -> V_2 . V_25 = 1 ;
V_12 = F_11 ( & V_10 -> V_2 ) ;
if ( V_12 )
goto V_12;
if ( V_13 && V_13 -> V_26 )
V_12 = V_13 -> V_26 ( & V_9 -> V_9 , V_10 -> V_2 . V_18 ) ;
V_12:
return V_12 ;
}
static int F_12 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
struct V_4 * V_10 = F_13 ( V_9 ) ;
if ( V_13 && V_13 -> V_27 ) {
V_12 = V_13 -> V_27 ( & V_9 -> V_9 , V_10 -> V_2 . V_18 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_14 ( & V_10 -> V_2 ) ;
return V_12 ;
}
void T_1 F_15 ( struct V_28 * V_29 )
{
V_13 = V_29 ;
}
