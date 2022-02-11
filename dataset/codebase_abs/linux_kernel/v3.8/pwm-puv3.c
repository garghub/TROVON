static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
unsigned long V_8 , V_9 , V_10 , V_11 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned long long V_13 ;
V_13 = F_4 ( V_12 -> V_14 ) ;
V_13 = V_13 * V_7 ;
F_5 ( V_13 , 1000000000 ) ;
V_8 = V_13 ;
if ( V_8 < 1 )
V_8 = 1 ;
V_9 = ( V_8 - 1 ) / 1024 ;
V_10 = V_8 / ( V_9 + 1 ) - 1 ;
if ( V_9 > 63 )
return - V_15 ;
if ( V_6 == V_7 )
V_11 = V_16 ;
else
V_11 = ( V_10 + 1 ) * V_6 / V_7 ;
F_6 ( V_12 -> V_14 ) ;
F_7 ( V_9 , V_12 -> V_17 + V_18 ) ;
F_7 ( V_10 - V_11 , V_12 -> V_17 + V_19 ) ;
F_7 ( V_10 , V_12 -> V_17 + V_20 ) ;
F_8 ( V_12 -> V_14 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_6 ( V_12 -> V_14 ) ;
}
static void F_10 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_8 ( V_12 -> V_14 ) ;
}
static int F_11 ( struct V_21 * V_22 )
{
struct V_1 * V_12 ;
struct V_23 * V_24 ;
int V_25 ;
V_12 = F_12 ( & V_22 -> V_26 , sizeof( * V_12 ) , V_27 ) ;
if ( V_12 == NULL ) {
F_13 ( & V_22 -> V_26 , L_1 ) ;
return - V_28 ;
}
V_12 -> V_14 = F_14 ( & V_22 -> V_26 , L_2 ) ;
if ( F_15 ( V_12 -> V_14 ) )
return F_16 ( V_12 -> V_14 ) ;
V_24 = F_17 ( V_22 , V_29 , 0 ) ;
if ( V_24 == NULL ) {
F_13 ( & V_22 -> V_26 , L_3 ) ;
return - V_30 ;
}
V_12 -> V_17 = F_18 ( & V_22 -> V_26 , V_24 ) ;
if ( V_12 -> V_17 == NULL )
return - V_31 ;
V_12 -> V_3 . V_26 = & V_22 -> V_26 ;
V_12 -> V_3 . V_32 = & V_33 ;
V_12 -> V_3 . V_17 = - 1 ;
V_12 -> V_3 . V_34 = 1 ;
V_25 = F_19 ( & V_12 -> V_3 ) ;
if ( V_25 < 0 ) {
F_13 ( & V_22 -> V_26 , L_4 , V_25 ) ;
return V_25 ;
}
F_20 ( V_22 , V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_21 * V_22 )
{
struct V_1 * V_12 = F_22 ( V_22 ) ;
return F_23 ( & V_12 -> V_3 ) ;
}
