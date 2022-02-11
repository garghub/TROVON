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
static unsigned long F_12 ( struct V_8 * V_9 ,
unsigned long V_13 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
unsigned long V_14 = V_13 ;
if ( V_11 -> V_2 . V_15 & V_16 )
V_14 /= V_11 -> V_2 . V_17 ;
return V_14 ;
}
static long F_13 ( struct V_8 * V_9 , unsigned long V_14 ,
unsigned long * V_18 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
int div = 1 ;
if ( V_11 -> V_2 . V_15 & V_16 )
div = V_11 -> V_2 . V_17 ;
if ( F_14 ( V_9 ) & V_19 ) {
unsigned long V_20 = V_14 ;
if ( V_11 -> V_2 . V_15 & V_16 )
V_20 *= div ;
* V_18 = F_15 ( F_16 ( V_9 ) , V_20 ) ;
}
return * V_18 / div ;
}
static int F_17 ( struct V_8 * V_9 , unsigned long V_14 ,
unsigned long V_13 )
{
return 0 ;
}
