static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( & V_4 -> V_5 , V_4 -> V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_5 ( & V_4 -> V_5 , V_4 -> V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_7 ( & V_4 -> V_5 , V_4 -> V_6 ) ;
}
static unsigned long F_8 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_8 , V_9 ;
T_1 V_10 ;
if ( F_9 ( & V_4 -> V_5 , & V_4 -> V_11 ) )
return F_10 ( & V_4 -> V_5 , & V_4 -> V_11 ) ;
V_10 = F_11 ( V_4 -> V_5 . V_12 + V_4 -> V_5 . V_10 ) ;
V_8 = V_10 >> V_4 -> V_8 . V_13 ;
V_8 &= ( 1 << V_4 -> V_8 . V_14 ) - 1 ;
V_9 = V_10 >> V_4 -> V_9 . V_13 ;
V_9 &= ( 1 << V_4 -> V_9 . V_14 ) - 1 ;
return V_7 * ( V_8 + 1 ) / ( V_9 + 1 ) ;
}
static long F_12 ( struct V_1 * V_2 , unsigned long V_15 ,
unsigned long * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_8 , V_9 ;
F_13 ( V_15 , * V_7 ,
1 << V_4 -> V_8 . V_14 , 1 << V_4 -> V_9 . V_14 ,
& V_8 , & V_9 ) ;
return * V_7 * V_8 / V_9 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned long V_15 ,
unsigned long V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_16 ;
unsigned long V_8 , V_9 ;
T_1 V_10 ;
if ( F_15 ( & V_4 -> V_5 , & V_4 -> V_11 , V_15 ) )
return F_16 ( & V_4 -> V_5 , & V_4 -> V_11 , V_15 ) ;
else
F_17 ( & V_4 -> V_5 , & V_4 -> V_11 ) ;
F_13 ( V_15 , V_7 ,
1 << V_4 -> V_8 . V_14 , 1 << V_4 -> V_9 . V_14 ,
& V_8 , & V_9 ) ;
F_18 ( V_4 -> V_5 . V_17 , V_16 ) ;
V_10 = F_11 ( V_4 -> V_5 . V_12 + V_4 -> V_5 . V_10 ) ;
V_10 &= ~ F_19 ( V_4 -> V_8 . V_14 + V_4 -> V_8 . V_13 - 1 , V_4 -> V_8 . V_13 ) ;
V_10 &= ~ F_19 ( V_4 -> V_9 . V_14 + V_4 -> V_9 . V_13 - 1 , V_4 -> V_9 . V_13 ) ;
F_20 ( V_10 | ( ( V_9 - 1 ) << V_4 -> V_9 . V_13 ) | ( ( V_8 - 1 ) << V_4 -> V_8 . V_13 ) ,
V_4 -> V_5 . V_12 + V_4 -> V_5 . V_10 ) ;
F_21 ( V_4 -> V_5 . V_17 , V_16 ) ;
F_22 ( & V_4 -> V_5 , V_4 -> V_17 ) ;
return 0 ;
}
