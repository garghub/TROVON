static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = V_2 / V_1 ;
if ( V_5 < V_4 -> V_6 )
V_5 = V_4 -> V_6 ;
if ( V_5 > V_4 -> V_7 )
V_5 = V_4 -> V_7 ;
V_4 -> V_4 = V_5 ;
}
static unsigned long F_2 ( struct V_8 * V_9 ,
unsigned long V_10 ,
unsigned long V_2 ,
void * V_11 )
{
struct V_12 * V_13 = V_11 ;
struct V_3 V_14 ;
V_14 . V_6 = V_13 -> V_4 . V_6 ;
if ( V_13 -> V_4 . V_7 )
V_14 . V_7 = V_13 -> V_4 . V_7 ;
else
V_14 . V_7 = ( 1 << V_13 -> V_4 . V_15 ) + V_13 -> V_4 . V_16 - 1 ;
F_1 ( V_10 , V_2 , & V_14 ) ;
return V_10 * V_14 . V_4 ;
}
static void F_3 ( struct V_17 * V_18 )
{
struct V_12 * V_13 = F_4 ( V_18 ) ;
return F_5 ( & V_13 -> V_19 , V_13 -> V_20 ) ;
}
static int F_6 ( struct V_17 * V_18 )
{
struct V_12 * V_13 = F_4 ( V_18 ) ;
return F_7 ( & V_13 -> V_19 , V_13 -> V_20 ) ;
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_12 * V_13 = F_4 ( V_18 ) ;
return F_9 ( & V_13 -> V_19 , V_13 -> V_20 ) ;
}
static unsigned long F_10 ( struct V_17 * V_18 ,
unsigned long V_10 )
{
struct V_12 * V_13 = F_4 ( V_18 ) ;
unsigned long V_21 ;
T_1 V_22 ;
if ( F_11 ( & V_13 -> V_19 , & V_13 -> V_23 ) )
return F_12 ( & V_13 -> V_19 , & V_13 -> V_23 ) ;
V_22 = F_13 ( V_13 -> V_19 . V_24 + V_13 -> V_19 . V_22 ) ;
V_21 = V_22 >> V_13 -> V_4 . V_25 ;
V_21 &= ( 1 << V_13 -> V_4 . V_15 ) - 1 ;
F_14 ( & V_13 -> V_19 , & V_13 -> V_9 , - 1 ,
& V_10 ) ;
return V_10 * ( V_21 + V_13 -> V_4 . V_16 ) ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = F_4 ( V_18 ) ;
return F_16 ( & V_13 -> V_19 , & V_13 -> V_9 ,
V_27 , F_2 , V_13 ) ;
}
static int F_17 ( struct V_17 * V_18 , unsigned long V_2 ,
unsigned long V_10 )
{
struct V_12 * V_13 = F_4 ( V_18 ) ;
struct V_3 V_14 ;
unsigned long V_28 ;
T_1 V_22 ;
if ( F_18 ( & V_13 -> V_19 , & V_13 -> V_23 , V_2 ) )
return F_19 ( & V_13 -> V_19 , & V_13 -> V_23 , V_2 ) ;
else
F_20 ( & V_13 -> V_19 , & V_13 -> V_23 ) ;
F_14 ( & V_13 -> V_19 , & V_13 -> V_9 , - 1 ,
& V_10 ) ;
V_14 . V_6 = V_13 -> V_4 . V_6 ;
if ( V_13 -> V_4 . V_7 )
V_14 . V_7 = V_13 -> V_4 . V_7 ;
else
V_14 . V_7 = ( 1 << V_13 -> V_4 . V_15 ) + V_13 -> V_4 . V_16 - 1 ;
F_1 ( V_10 , V_2 , & V_14 ) ;
F_21 ( V_13 -> V_19 . V_29 , V_28 ) ;
V_22 = F_13 ( V_13 -> V_19 . V_24 + V_13 -> V_19 . V_22 ) ;
V_22 &= ~ F_22 ( V_13 -> V_4 . V_15 + V_13 -> V_4 . V_25 - 1 , V_13 -> V_4 . V_25 ) ;
V_22 |= ( ( V_14 . V_4 - V_13 -> V_4 . V_16 ) << V_13 -> V_4 . V_25 ) ;
F_23 ( V_22 , V_13 -> V_19 . V_24 + V_13 -> V_19 . V_22 ) ;
F_24 ( V_13 -> V_19 . V_29 , V_28 ) ;
return 0 ;
}
static T_2 F_25 ( struct V_17 * V_18 )
{
struct V_12 * V_13 = F_4 ( V_18 ) ;
return F_26 ( & V_13 -> V_19 , & V_13 -> V_9 ) ;
}
static int F_27 ( struct V_17 * V_18 , T_2 V_30 )
{
struct V_12 * V_13 = F_4 ( V_18 ) ;
return F_28 ( & V_13 -> V_19 , & V_13 -> V_9 , V_30 ) ;
}
