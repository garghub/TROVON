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
struct V_10 * V_1 ,
unsigned long * V_11 ,
unsigned long V_2 ,
void * V_12 )
{
struct V_13 * V_14 = V_12 ;
struct V_3 V_15 ;
V_15 . V_6 = V_14 -> V_4 . V_6 ;
if ( V_14 -> V_4 . V_7 )
V_15 . V_7 = V_14 -> V_4 . V_7 ;
else
V_15 . V_7 = ( 1 << V_14 -> V_4 . V_16 ) + V_14 -> V_4 . V_17 - 1 ;
F_1 ( * V_11 , V_2 , & V_15 ) ;
return * V_11 * V_15 . V_4 ;
}
static void F_3 ( struct V_10 * V_18 )
{
struct V_13 * V_14 = F_4 ( V_18 ) ;
return F_5 ( & V_14 -> V_19 , V_14 -> V_20 ) ;
}
static int F_6 ( struct V_10 * V_18 )
{
struct V_13 * V_14 = F_4 ( V_18 ) ;
return F_7 ( & V_14 -> V_19 , V_14 -> V_20 ) ;
}
static int F_8 ( struct V_10 * V_18 )
{
struct V_13 * V_14 = F_4 ( V_18 ) ;
return F_9 ( & V_14 -> V_19 , V_14 -> V_20 ) ;
}
static unsigned long F_10 ( struct V_10 * V_18 ,
unsigned long V_11 )
{
struct V_13 * V_14 = F_4 ( V_18 ) ;
unsigned long V_21 ;
T_1 V_22 ;
if ( F_11 ( & V_14 -> V_19 , & V_14 -> V_23 ) )
return F_12 ( & V_14 -> V_19 , & V_14 -> V_23 ) ;
V_22 = F_13 ( V_14 -> V_19 . V_24 + V_14 -> V_19 . V_22 ) ;
V_21 = V_22 >> V_14 -> V_4 . V_25 ;
V_21 &= ( 1 << V_14 -> V_4 . V_16 ) - 1 ;
V_11 = F_14 ( & V_14 -> V_19 , & V_14 -> V_9 , - 1 ,
V_11 ) ;
return V_11 * ( V_21 + V_14 -> V_4 . V_17 ) ;
}
static int F_15 ( struct V_10 * V_18 ,
struct V_26 * V_27 )
{
struct V_13 * V_14 = F_4 ( V_18 ) ;
return F_16 ( & V_14 -> V_19 , & V_14 -> V_9 ,
V_27 , F_2 , V_14 ) ;
}
static int F_17 ( struct V_10 * V_18 , unsigned long V_2 ,
unsigned long V_11 )
{
struct V_13 * V_14 = F_4 ( V_18 ) ;
struct V_3 V_15 ;
unsigned long V_28 ;
T_1 V_22 ;
if ( F_18 ( & V_14 -> V_19 , & V_14 -> V_23 , V_2 ) ) {
F_19 ( & V_14 -> V_19 , & V_14 -> V_23 ) ;
return F_20 ( & V_14 -> V_19 , & V_14 -> V_23 ,
V_2 , V_14 -> V_29 ) ;
} else {
F_21 ( & V_14 -> V_19 , & V_14 -> V_23 ) ;
}
V_11 = F_14 ( & V_14 -> V_19 , & V_14 -> V_9 , - 1 ,
V_11 ) ;
V_15 . V_6 = V_14 -> V_4 . V_6 ;
if ( V_14 -> V_4 . V_7 )
V_15 . V_7 = V_14 -> V_4 . V_7 ;
else
V_15 . V_7 = ( 1 << V_14 -> V_4 . V_16 ) + V_14 -> V_4 . V_17 - 1 ;
F_1 ( V_11 , V_2 , & V_15 ) ;
F_22 ( V_14 -> V_19 . V_29 , V_28 ) ;
V_22 = F_13 ( V_14 -> V_19 . V_24 + V_14 -> V_19 . V_22 ) ;
V_22 &= ~ F_23 ( V_14 -> V_4 . V_16 + V_14 -> V_4 . V_25 - 1 , V_14 -> V_4 . V_25 ) ;
V_22 |= ( ( V_15 . V_4 - V_14 -> V_4 . V_17 ) << V_14 -> V_4 . V_25 ) ;
F_24 ( V_22 , V_14 -> V_19 . V_24 + V_14 -> V_19 . V_22 ) ;
F_25 ( V_14 -> V_19 . V_29 , V_28 ) ;
F_26 ( & V_14 -> V_19 , V_14 -> V_29 ) ;
return 0 ;
}
static T_2 F_27 ( struct V_10 * V_18 )
{
struct V_13 * V_14 = F_4 ( V_18 ) ;
return F_28 ( & V_14 -> V_19 , & V_14 -> V_9 ) ;
}
static int F_29 ( struct V_10 * V_18 , T_2 V_30 )
{
struct V_13 * V_14 = F_4 ( V_18 ) ;
return F_30 ( & V_14 -> V_19 , & V_14 -> V_9 , V_30 ) ;
}
