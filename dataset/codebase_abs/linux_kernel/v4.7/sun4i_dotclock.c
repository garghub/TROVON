static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_4 -> V_5 , V_6 ,
F_5 ( V_7 ) , 0 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_4 ( V_4 -> V_5 , V_6 ,
F_5 ( V_7 ) ,
F_5 ( V_7 ) ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 ;
F_8 ( V_4 -> V_5 , V_6 , & V_8 ) ;
return V_8 & F_5 ( V_7 ) ;
}
static unsigned long F_9 ( struct V_2 * V_3 ,
unsigned long V_9 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 ;
F_8 ( V_4 -> V_5 , V_6 , & V_8 ) ;
V_8 >>= V_10 ;
V_8 &= V_11 ;
if ( ! V_8 )
V_8 = 1 ;
return V_9 / V_8 ;
}
static long F_10 ( struct V_2 * V_3 , unsigned long V_12 ,
unsigned long * V_9 )
{
unsigned long V_13 = 0 ;
T_2 V_14 = 1 ;
int V_15 ;
for ( V_15 = 6 ; V_15 < 127 ; V_15 ++ ) {
unsigned long V_16 = V_12 * V_15 ;
unsigned long V_17 ;
V_17 = F_11 ( F_12 ( V_3 ) ,
V_16 ) ;
if ( V_17 == V_16 ) {
V_13 = V_17 ;
V_14 = V_15 ;
goto V_18;
}
if ( ( V_17 < V_16 ) && ( V_17 > V_13 ) ) {
V_13 = V_17 ;
V_14 = V_15 ;
}
}
V_18:
* V_9 = V_13 ;
return V_13 / V_14 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned long V_12 ,
unsigned long V_9 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 div = V_9 / V_12 ;
return F_4 ( V_4 -> V_5 , V_6 ,
F_14 ( 6 , 0 ) , div ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 ;
F_8 ( V_4 -> V_5 , V_19 , & V_8 ) ;
V_8 >>= 28 ;
V_8 &= 3 ;
return V_8 * 120 ;
}
static int F_16 ( struct V_2 * V_3 , int V_20 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_4 -> V_5 , V_19 ,
F_14 ( 29 , 28 ) ,
V_20 / 120 ) ;
return 0 ;
}
int F_17 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
const char * V_25 , * V_26 ;
struct V_27 V_28 ;
struct V_1 * V_4 ;
int V_29 ;
V_26 = F_18 ( V_24 -> V_30 ) ;
V_29 = F_19 ( V_22 -> V_31 ,
L_1 , 0 ,
& V_25 ) ;
if ( V_29 )
return V_29 ;
V_4 = F_20 ( V_22 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return - V_33 ;
V_28 . V_34 = V_25 ;
V_28 . V_35 = & V_36 ;
V_28 . V_37 = & V_26 ;
V_28 . V_38 = 1 ;
V_28 . V_39 = V_40 ;
V_4 -> V_5 = V_24 -> V_41 ;
V_4 -> V_3 . V_28 = & V_28 ;
V_24 -> V_4 = F_21 ( V_22 , & V_4 -> V_3 ) ;
if ( F_22 ( V_24 -> V_4 ) )
return F_23 ( V_24 -> V_4 ) ;
return 0 ;
}
int F_24 ( struct V_23 * V_24 )
{
F_25 ( V_24 -> V_4 ) ;
return 0 ;
}
