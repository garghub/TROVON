static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_4 + F_3 ( 5000 ) ) ;
}
int F_4 ( struct V_1 * V_2 , int V_5 )
{
int V_6 = F_5 ( & V_2 -> V_6 ) ;
return ( ! ( V_6 + V_5 > V_2 -> V_7 ) ) ;
}
int F_6 ( struct V_1 * V_2 , int V_5 )
{
int V_8 = F_5 ( & V_2 -> V_8 ) ;
int V_9 ;
V_9 = F_7 ( V_2 -> V_9 ) ;
return ( ! ( V_8 + V_5 > V_2 -> V_10 && V_9 ) ) ;
}
void F_8 ( struct V_1 * V_2 , int V_5 )
{
F_9 ( V_5 , & V_2 -> V_6 ) ;
F_10 ( & V_2 -> V_9 , 1 ) ;
F_1 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 , int V_5 )
{
F_9 ( V_5 , & V_2 -> V_8 ) ;
}
void F_12 ( struct V_1 * V_2 , int V_11 , int V_12 )
{
F_13 ( V_11 , & V_2 -> V_6 ) ;
F_13 ( V_12 , & V_2 -> V_8 ) ;
}
unsigned long F_14 ( struct V_1 * V_2 )
{
return F_5 ( & V_2 -> V_13 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned long V_14 )
{
unsigned long V_13 = F_14 ( V_2 ) ;
if ( V_13 >= V_2 -> V_15 ) {
V_2 -> V_7 = V_14 - V_2 -> V_16 ;
V_2 -> V_10 = V_2 -> V_16 ;
V_2 -> V_17 = V_18 ;
} else if ( V_13 < V_2 -> V_15 ) {
int V_19 = V_2 -> V_20 - V_2 -> V_21 ;
int V_22 = V_13 >> V_19 ;
int V_23 = V_22 << V_24 ;
int V_25 ;
V_2 -> V_7 = V_23 ;
V_25 = V_14 - V_2 -> V_7 ;
V_2 -> V_10 = V_14 ( V_25 , V_2 -> V_16 ) ;
if ( V_13 > V_2 -> V_26 )
V_2 -> V_17 = V_27 ;
else
V_2 -> V_17 = V_28 ;
}
return V_2 -> V_17 ;
}
void F_16 ( struct V_1 * V_2 , int V_29 )
{
V_2 -> V_16 = V_2 -> V_10 = V_29 ;
}
void F_17 ( struct V_1 * V_2 , struct V_30 * line )
{
struct V_31 * V_31 = F_18 ( V_2 , struct V_31 , V_2 ) ;
int V_32 = F_5 ( & line -> V_32 ) ;
int V_33 ;
F_9 ( V_32 , & V_2 -> V_13 ) ;
V_33 = F_15 ( V_2 , V_2 -> V_34 ) ;
if ( V_33 == ( V_27 | V_28 ) )
F_19 ( V_31 ) ;
else
F_20 ( V_31 ) ;
}
void F_21 ( struct V_1 * V_2 , struct V_30 * line )
{
struct V_31 * V_31 = F_18 ( V_2 , struct V_31 , V_2 ) ;
int V_32 = F_5 ( & line -> V_32 ) ;
int V_33 ;
F_13 ( V_32 , & V_2 -> V_13 ) ;
V_33 = F_15 ( V_2 , V_2 -> V_34 ) ;
if ( V_33 == ( V_27 | V_28 ) )
F_19 ( V_31 ) ;
else
F_20 ( V_31 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_15 ;
}
int F_23 ( struct V_1 * V_2 )
{
return V_2 -> V_7 ;
}
static void F_24 ( unsigned long V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 ;
F_10 ( & V_2 -> V_9 , 0 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_3 ) ;
}
void F_27 ( struct V_1 * V_2 , int V_36 )
{
unsigned int V_37 ;
V_2 -> V_15 = V_2 -> V_38 / V_39 ;
V_2 -> V_26 = V_2 -> V_38 / V_40 ;
V_2 -> V_20 = F_28 ( V_2 -> V_15 ) ;
V_37 = V_36 / V_41 ;
V_2 -> V_21 = F_28 ( V_37 ) + 1 ;
V_2 -> V_34 = V_36 ;
V_2 -> V_7 = V_36 ;
F_29 ( & V_2 -> V_6 , 0 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_17 = V_18 ;
F_29 ( & V_2 -> V_8 , 0 ) ;
F_30 ( & V_2 -> V_3 , F_24 , ( unsigned long ) V_2 ) ;
V_2 -> V_9 = 0 ;
}
