static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 -> V_8 ) ;
return F_5 ( V_7 ) ;
}
static void F_6 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 -> V_8 ) ;
F_7 ( V_7 ) ;
}
static int F_8 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_9 , int V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
void T_1 * V_11 = V_1 -> V_11 ;
unsigned long long V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_15 ;
int V_16 = 0 ;
if ( ! F_9 ( V_17 , & V_5 -> V_18 ) ) {
V_16 = F_10 ( V_1 -> V_19 ) ;
if ( V_16 )
return V_16 ;
}
V_12 = F_11 ( V_1 -> V_19 ) ;
V_12 *= V_10 ;
F_12 ( V_12 , 1000000000 ) ;
V_13 = V_12 ;
V_12 = V_13 ;
V_12 *= V_9 ;
F_12 ( V_12 , V_10 ) ;
V_14 = V_12 ;
if ( V_13 < 0x10000 && V_14 < 0x10000 ) {
V_15 = F_13 ( V_11 + V_20 ) ;
if ( V_13 > V_15 ) {
F_14 ( V_13 , V_11 + V_20 ) ;
F_14 ( V_14 , V_11 + V_21 ) ;
} else {
F_14 ( V_14 , V_11 + V_21 ) ;
F_14 ( V_13 , V_11 + V_20 ) ;
}
} else {
V_16 = - V_22 ;
}
if ( ! F_9 ( V_17 , & V_5 -> V_18 ) )
F_15 ( V_1 -> V_19 ) ;
return V_16 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_23 V_24 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_16 ;
V_16 = F_10 ( V_1 -> V_19 ) ;
if ( V_16 )
return V_16 ;
if ( V_24 == V_25 )
F_14 ( 0x1 , V_1 -> V_11 + V_26 ) ;
else
F_14 ( 0x0 , V_1 -> V_11 + V_26 ) ;
F_15 ( V_1 -> V_19 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_16 ;
V_16 = F_10 ( V_1 -> V_19 ) ;
if ( V_16 )
return V_16 ;
F_14 ( 0x1 , V_1 -> V_11 + V_27 ) ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( 0x0 , V_1 -> V_11 + V_27 ) ;
F_15 ( V_1 -> V_19 ) ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_1 * V_1 ;
struct V_28 * V_29 ;
int V_16 ;
V_1 = F_20 ( & V_7 -> V_8 , sizeof( * V_1 ) , V_30 ) ;
if ( ! V_1 )
return - V_31 ;
V_29 = F_21 ( V_7 , V_32 , 0 ) ;
V_1 -> V_11 = F_22 ( & V_7 -> V_8 , V_29 ) ;
if ( F_23 ( V_1 -> V_11 ) )
return F_24 ( V_1 -> V_11 ) ;
V_1 -> V_19 = F_25 ( & V_7 -> V_8 , L_1 ) ;
if ( F_23 ( V_1 -> V_19 ) )
return F_24 ( V_1 -> V_19 ) ;
V_1 -> V_3 . V_8 = & V_7 -> V_8 ;
V_1 -> V_3 . V_33 = & V_34 ;
V_1 -> V_3 . V_11 = - 1 ;
V_1 -> V_3 . V_35 = 1 ;
V_16 = F_26 ( & V_1 -> V_3 ) ;
if ( V_16 < 0 )
return V_16 ;
F_27 ( V_7 , V_1 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_29 ( V_7 ) ;
return F_30 ( & V_1 -> V_3 ) ;
}
