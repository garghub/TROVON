static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned int V_3 , unsigned int * V_4 )
{
* V_4 = V_2 / V_1 ;
}
static unsigned long F_2 ( struct V_5 * V_6 ,
unsigned long V_7 ,
unsigned long V_2 ,
void * V_8 )
{
struct V_9 * V_10 = V_8 ;
unsigned int V_4 ;
F_1 ( V_7 , V_2 , 1 << V_10 -> V_11 . V_12 , & V_4 ) ;
return V_7 * V_4 ;
}
static void F_3 ( struct V_13 * V_14 )
{
struct V_9 * V_10 = F_4 ( V_14 ) ;
return F_5 ( & V_10 -> V_15 , V_10 -> V_16 ) ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_9 * V_10 = F_4 ( V_14 ) ;
return F_7 ( & V_10 -> V_15 , V_10 -> V_16 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_9 * V_10 = F_4 ( V_14 ) ;
return F_9 ( & V_10 -> V_15 , V_10 -> V_16 ) ;
}
static unsigned long F_10 ( struct V_13 * V_14 ,
unsigned long V_7 )
{
struct V_9 * V_10 = F_4 ( V_14 ) ;
unsigned long V_17 ;
T_1 V_18 ;
V_18 = F_11 ( V_10 -> V_15 . V_19 + V_10 -> V_15 . V_18 ) ;
V_17 = V_18 >> V_10 -> V_11 . V_20 ;
V_17 &= ( 1 << V_10 -> V_11 . V_12 ) - 1 ;
F_12 ( & V_10 -> V_15 , & V_10 -> V_6 , - 1 ,
& V_7 ) ;
return V_7 * ( V_17 + 1 ) ;
}
static int F_13 ( struct V_13 * V_14 ,
struct V_21 * V_22 )
{
struct V_9 * V_10 = F_4 ( V_14 ) ;
return F_14 ( & V_10 -> V_15 , & V_10 -> V_6 ,
V_22 , F_2 , V_10 ) ;
}
static int F_15 ( struct V_13 * V_14 , unsigned long V_2 ,
unsigned long V_7 )
{
struct V_9 * V_10 = F_4 ( V_14 ) ;
unsigned long V_23 ;
unsigned int V_4 ;
T_1 V_18 ;
F_12 ( & V_10 -> V_15 , & V_10 -> V_6 , - 1 ,
& V_7 ) ;
F_1 ( V_7 , V_2 , 1 << V_10 -> V_11 . V_12 , & V_4 ) ;
F_16 ( V_10 -> V_15 . V_24 , V_23 ) ;
V_18 = F_11 ( V_10 -> V_15 . V_19 + V_10 -> V_15 . V_18 ) ;
V_18 &= ~ F_17 ( V_10 -> V_11 . V_12 + V_10 -> V_11 . V_20 - 1 , V_10 -> V_11 . V_20 ) ;
F_18 ( V_18 | ( ( V_4 - 1 ) << V_10 -> V_11 . V_20 ) ,
V_10 -> V_15 . V_19 + V_10 -> V_15 . V_18 ) ;
F_19 ( V_10 -> V_15 . V_24 , V_23 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_13 * V_14 )
{
struct V_9 * V_10 = F_4 ( V_14 ) ;
return F_21 ( & V_10 -> V_15 , & V_10 -> V_6 ) ;
}
static int F_22 ( struct V_13 * V_14 , T_2 V_25 )
{
struct V_9 * V_10 = F_4 ( V_14 ) ;
return F_23 ( & V_10 -> V_15 , & V_10 -> V_6 , V_25 ) ;
}
