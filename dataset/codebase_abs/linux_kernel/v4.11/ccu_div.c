static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
void * V_5 )
{
struct V_6 * V_7 = V_5 ;
unsigned long V_8 ;
V_8 = F_2 ( V_4 , V_3 , V_7 -> div . V_9 , V_7 -> div . V_10 ,
V_7 -> div . V_11 ) ;
return F_3 ( & V_7 -> V_12 . V_13 , V_3 , V_8 ,
V_7 -> div . V_9 , V_7 -> div . V_11 ) ;
}
static void F_4 ( struct V_14 * V_13 )
{
struct V_6 * V_7 = F_5 ( V_13 ) ;
return F_6 ( & V_7 -> V_12 , V_7 -> V_15 ) ;
}
static int F_7 ( struct V_14 * V_13 )
{
struct V_6 * V_7 = F_5 ( V_13 ) ;
return F_8 ( & V_7 -> V_12 , V_7 -> V_15 ) ;
}
static int F_9 ( struct V_14 * V_13 )
{
struct V_6 * V_7 = F_5 ( V_13 ) ;
return F_10 ( & V_7 -> V_12 , V_7 -> V_15 ) ;
}
static unsigned long F_11 ( struct V_14 * V_13 ,
unsigned long V_3 )
{
struct V_6 * V_7 = F_5 ( V_13 ) ;
unsigned long V_8 ;
T_1 V_16 ;
V_16 = F_12 ( V_7 -> V_12 . V_17 + V_7 -> V_12 . V_16 ) ;
V_8 = V_16 >> V_7 -> div . V_18 ;
V_8 &= ( 1 << V_7 -> div . V_10 ) - 1 ;
F_13 ( & V_7 -> V_12 , & V_7 -> V_2 , - 1 ,
& V_3 ) ;
return F_3 ( V_13 , V_3 , V_8 , V_7 -> div . V_9 ,
V_7 -> div . V_11 ) ;
}
static int F_14 ( struct V_14 * V_13 ,
struct V_19 * V_20 )
{
struct V_6 * V_7 = F_5 ( V_13 ) ;
if ( F_15 ( V_13 ) == 1 ) {
V_20 -> V_4 = F_16 ( V_13 , V_20 -> V_4 ,
& V_20 -> V_21 ,
V_7 -> div . V_9 ,
V_7 -> div . V_10 ,
V_7 -> div . V_11 ) ;
V_20 -> V_22 = F_17 ( V_13 ) ;
return 0 ;
}
return F_18 ( & V_7 -> V_12 , & V_7 -> V_2 ,
V_20 , F_1 , V_7 ) ;
}
static int F_19 ( struct V_14 * V_13 , unsigned long V_4 ,
unsigned long V_3 )
{
struct V_6 * V_7 = F_5 ( V_13 ) ;
unsigned long V_11 ;
unsigned long V_8 ;
T_1 V_16 ;
F_13 ( & V_7 -> V_12 , & V_7 -> V_2 , - 1 ,
& V_3 ) ;
V_8 = F_2 ( V_4 , V_3 , V_7 -> div . V_9 , V_7 -> div . V_10 ,
V_7 -> div . V_11 ) ;
F_20 ( V_7 -> V_12 . V_23 , V_11 ) ;
V_16 = F_12 ( V_7 -> V_12 . V_17 + V_7 -> V_12 . V_16 ) ;
V_16 &= ~ F_21 ( V_7 -> div . V_10 + V_7 -> div . V_18 - 1 , V_7 -> div . V_18 ) ;
F_22 ( V_16 | ( V_8 << V_7 -> div . V_18 ) ,
V_7 -> V_12 . V_17 + V_7 -> V_12 . V_16 ) ;
F_23 ( V_7 -> V_12 . V_23 , V_11 ) ;
return 0 ;
}
static T_2 F_24 ( struct V_14 * V_13 )
{
struct V_6 * V_7 = F_5 ( V_13 ) ;
return F_25 ( & V_7 -> V_12 , & V_7 -> V_2 ) ;
}
static int F_26 ( struct V_14 * V_13 , T_2 V_24 )
{
struct V_6 * V_7 = F_5 ( V_13 ) ;
return F_27 ( & V_7 -> V_12 , & V_7 -> V_2 , V_24 ) ;
}
