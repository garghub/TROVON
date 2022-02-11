static long F_1 ( unsigned long V_1 ,
unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_4 = ( V_5 * V_3 ) + V_2 ;
if ( V_3 < V_6 )
return - V_7 ;
return F_2 ( ( V_8 ) V_1 * V_5 , V_4 ) ;
}
static void F_3 ( unsigned long V_9 ,
unsigned long V_1 ,
unsigned long * V_2 ,
unsigned long * V_3 )
{
T_1 div = V_1 ;
unsigned long V_10 = F_4 ( div , V_9 ) ;
if ( div < V_6 ) {
* V_3 = V_6 ;
* V_2 = 0 ;
} else if ( div > V_11 ) {
* V_3 = V_11 ;
* V_2 = V_5 - 1 ;
} else {
* V_3 = div ;
* V_2 = F_5 ( V_10 * V_5 , V_9 ) ;
}
}
static unsigned long F_6 ( struct V_12 * V_13 ,
unsigned long V_1 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_16 * V_17 ;
unsigned long V_18 , V_2 , V_3 ;
long V_19 ;
V_17 = & V_15 -> V_2 ;
V_18 = F_8 ( V_15 -> V_20 + V_17 -> V_21 ) ;
V_2 = F_9 ( V_17 -> V_22 , V_17 -> V_23 , V_18 ) ;
V_17 = & V_15 -> V_3 ;
V_18 = F_8 ( V_15 -> V_20 + V_17 -> V_21 ) ;
V_3 = F_9 ( V_17 -> V_22 , V_17 -> V_23 , V_18 ) ;
V_19 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_19 < 0 )
return 0 ;
return V_19 ;
}
static long F_10 ( struct V_12 * V_13 ,
unsigned long V_19 ,
unsigned long * V_1 )
{
unsigned long V_2 , V_3 ;
F_3 ( V_19 , * V_1 , & V_2 , & V_3 ) ;
return F_1 ( * V_1 , V_2 , V_3 ) ;
}
static int F_11 ( struct V_12 * V_13 ,
unsigned long V_19 ,
unsigned long V_1 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_16 * V_17 ;
unsigned long V_18 , V_2 , V_3 ;
unsigned long V_24 = 0 ;
F_3 ( V_19 , V_1 , & V_2 , & V_3 ) ;
if ( V_15 -> V_25 )
F_12 ( V_15 -> V_25 , V_24 ) ;
else
F_13 ( V_15 -> V_25 ) ;
V_17 = & V_15 -> V_2 ;
V_18 = F_8 ( V_15 -> V_20 + V_17 -> V_21 ) ;
V_18 = F_14 ( V_17 -> V_22 , V_17 -> V_23 , V_18 , V_2 ) ;
F_15 ( V_18 , V_15 -> V_20 + V_17 -> V_21 ) ;
V_17 = & V_15 -> V_26 ;
V_18 = F_8 ( V_15 -> V_20 + V_17 -> V_21 ) ;
V_18 = F_14 ( V_17 -> V_22 , V_17 -> V_23 , V_18 , 1 ) ;
F_15 ( V_18 , V_15 -> V_20 + V_17 -> V_21 ) ;
V_17 = & V_15 -> V_27 ;
if ( V_17 -> V_22 != 0 ) {
V_18 = F_8 ( V_15 -> V_20 + V_17 -> V_21 ) ;
V_18 = F_14 ( V_17 -> V_22 , V_17 -> V_23 , V_18 , 1 ) ;
F_15 ( V_18 , V_15 -> V_20 + V_17 -> V_21 ) ;
}
V_17 = & V_15 -> V_3 ;
V_18 = F_8 ( V_15 -> V_20 + V_17 -> V_21 ) ;
V_18 = F_14 ( V_17 -> V_22 , V_17 -> V_23 , V_18 , V_3 ) ;
F_15 ( V_18 , V_15 -> V_20 + V_17 -> V_21 ) ;
if ( V_15 -> V_25 )
F_16 ( V_15 -> V_25 , V_24 ) ;
else
F_17 ( V_15 -> V_25 ) ;
return 0 ;
}
static void F_18 ( struct V_12 * V_13 , int V_28 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_16 * V_17 ;
unsigned long V_18 ;
unsigned long V_24 = 0 ;
if ( V_15 -> V_25 )
F_12 ( V_15 -> V_25 , V_24 ) ;
else
F_13 ( V_15 -> V_25 ) ;
V_17 = & V_15 -> V_29 ;
V_18 = F_8 ( V_15 -> V_20 + V_17 -> V_21 ) ;
V_18 = F_14 ( V_17 -> V_22 , V_17 -> V_23 , V_18 , V_28 ? 1 : 0 ) ;
F_15 ( V_18 , V_15 -> V_20 + V_17 -> V_21 ) ;
if ( V_15 -> V_25 )
F_16 ( V_15 -> V_25 , V_24 ) ;
else
F_17 ( V_15 -> V_25 ) ;
}
static int F_19 ( struct V_12 * V_13 )
{
F_18 ( V_13 , 1 ) ;
return 0 ;
}
static void F_20 ( struct V_12 * V_13 )
{
F_18 ( V_13 , 0 ) ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_16 * V_17 ;
unsigned long V_18 ;
int V_29 ;
V_17 = & V_15 -> V_29 ;
V_18 = F_8 ( V_15 -> V_20 + V_17 -> V_21 ) ;
V_29 = F_9 ( V_17 -> V_22 , V_17 -> V_23 , V_18 ) ;
return V_29 ;
}
