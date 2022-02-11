static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_4 + F_3 ( 5000 ) ) ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_5 ( & V_2 -> V_5 ) ;
return ( V_5 == 0 ) ;
}
int F_6 ( struct V_1 * V_2 , int V_6 )
{
int V_7 = F_5 ( & V_2 -> V_7 ) ;
int V_5 = F_5 ( & V_2 -> V_5 ) ;
if ( F_7 ( V_5 >= 0 ) && ( V_5 - V_6 < 0 ) )
return V_8 ;
if ( V_7 >= V_2 -> V_9 )
return V_10 ;
return V_11 ;
}
void F_8 ( struct V_1 * V_2 , int V_6 )
{
int V_5 = F_5 ( & V_2 -> V_5 ) ;
if ( F_7 ( V_5 >= 0 ) )
F_9 ( V_6 , & V_2 -> V_5 ) ;
}
int F_10 ( struct V_1 * V_2 , int V_6 )
{
int V_12 = F_5 ( & V_2 -> V_12 ) ;
int V_13 ;
V_13 = F_11 ( V_2 -> V_13 ) ;
return ( ! ( V_12 >= V_2 -> V_14 && V_13 ) ) ;
}
void F_12 ( struct V_1 * V_2 , int V_6 )
{
F_13 ( V_6 , & V_2 -> V_7 ) ;
F_14 ( & V_2 -> V_13 , 1 ) ;
F_1 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 , int V_6 )
{
F_13 ( V_6 , & V_2 -> V_12 ) ;
}
void F_16 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
F_9 ( V_15 , & V_2 -> V_7 ) ;
F_9 ( V_16 , & V_2 -> V_12 ) ;
}
unsigned long F_17 ( struct V_1 * V_2 )
{
return F_5 ( & V_2 -> V_17 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned long V_18 )
{
unsigned long V_17 = F_17 ( V_2 ) ;
if ( V_17 >= V_2 -> V_19 ) {
V_2 -> V_9 = V_18 ;
V_2 -> V_14 = 0 ;
V_2 -> V_20 = V_21 ;
} else if ( V_17 < V_2 -> V_19 ) {
int V_22 = V_2 -> V_23 - V_2 -> V_24 ;
int V_25 = V_17 >> V_22 ;
int V_26 = V_25 << V_27 ;
V_2 -> V_9 = V_26 ;
V_2 -> V_14 = V_18 - V_26 ;
if ( V_17 <= V_2 -> V_28 ) {
V_2 -> V_9 = 0 ;
V_2 -> V_14 = V_18 ;
}
V_2 -> V_20 = V_29 ;
}
return V_2 -> V_20 ;
}
void F_19 ( struct V_1 * V_2 , struct V_30 * line )
{
struct V_31 * V_31 = F_20 ( V_2 , struct V_31 , V_2 ) ;
int V_32 = F_5 ( & line -> V_32 ) ;
int V_33 ;
F_13 ( V_32 , & V_2 -> V_17 ) ;
V_33 = F_18 ( V_2 , V_2 -> V_34 ) ;
if ( V_33 == ( V_35 | V_29 ) )
F_21 ( V_31 ) ;
else
F_22 ( V_31 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_30 * line )
{
int V_32 = F_5 ( & line -> V_32 ) ;
F_9 ( V_32 , & V_2 -> V_17 ) ;
}
void F_24 ( struct V_31 * V_31 )
{
struct V_1 * V_2 = & V_31 -> V_2 ;
int V_33 ;
V_33 = F_18 ( V_2 , V_2 -> V_34 ) ;
if ( V_33 == ( V_35 | V_29 ) )
F_21 ( V_31 ) ;
else
F_22 ( V_31 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
return V_2 -> V_19 ;
}
int F_26 ( struct V_1 * V_2 )
{
return V_2 -> V_36 ;
}
int F_27 ( struct V_1 * V_2 )
{
return V_2 -> V_9 ;
}
static void F_28 ( unsigned long V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
F_14 ( & V_2 -> V_13 , 0 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_3 ) ;
}
void F_31 ( struct V_1 * V_2 , int V_38 )
{
struct V_31 * V_31 = F_20 ( V_2 , struct V_31 , V_2 ) ;
struct V_39 * V_40 = & V_31 -> V_40 ;
int V_41 = V_40 -> V_42 * V_43 ;
unsigned int V_44 ;
V_2 -> V_19 = V_2 -> V_45 / V_46 ;
V_2 -> V_23 = F_32 ( V_2 -> V_19 ) ;
V_2 -> V_36 = V_2 -> V_45 / V_47 ;
if ( V_2 -> V_36 < V_41 )
V_2 -> V_36 = V_41 ;
V_2 -> V_28 = V_41 ;
V_44 = V_38 / V_48 ;
V_2 -> V_24 = F_32 ( V_44 ) ;
V_2 -> V_34 = V_38 ;
V_2 -> V_9 = V_38 ;
V_2 -> V_14 = 0 ;
V_2 -> V_20 = V_21 ;
F_33 ( & V_2 -> V_7 , 0 ) ;
F_33 ( & V_2 -> V_12 , 0 ) ;
F_33 ( & V_2 -> V_5 , - 1 ) ;
F_34 ( & V_2 -> V_3 , F_28 , ( unsigned long ) V_2 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_49 = 0 ;
}
