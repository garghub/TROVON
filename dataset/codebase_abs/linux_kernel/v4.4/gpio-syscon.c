static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_6 , V_7 ;
int V_8 ;
V_7 = V_5 -> V_9 + V_5 -> V_10 -> V_11 + V_4 ;
V_8 = F_4 ( V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 , & V_6 ) ;
if ( V_8 )
return V_8 ;
return ! ! ( V_6 & F_5 ( V_7 % V_13 ) ) ;
}
static void F_6 ( struct V_2 * V_3 , unsigned V_4 , int V_6 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_7 ;
V_7 = V_5 -> V_9 + V_5 -> V_10 -> V_11 + V_4 ;
F_7 ( V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 ,
F_5 ( V_7 % V_13 ) ,
V_6 ? F_5 ( V_7 % V_13 ) : 0 ) ;
}
static int F_8 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_10 -> V_15 & V_16 ) {
unsigned int V_7 ;
V_7 = V_5 -> V_17 +
V_5 -> V_10 -> V_18 + V_4 ;
F_7 ( V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 ,
F_5 ( V_7 % V_13 ) , 0 ) ;
}
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_4 , int V_6 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_10 -> V_15 & V_16 ) {
unsigned int V_7 ;
V_7 = V_5 -> V_17 +
V_5 -> V_10 -> V_18 + V_4 ;
F_7 ( V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 ,
F_5 ( V_7 % V_13 ) ,
F_5 ( V_7 % V_13 ) ) ;
}
V_5 -> V_10 -> V_19 ( V_3 , V_4 , V_6 ) ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 , unsigned V_4 , int V_6 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_7 ;
int V_8 ;
V_7 = V_5 -> V_9 + V_5 -> V_10 -> V_11 + V_4 ;
if ( ! V_6 )
return;
V_8 = F_7 (
V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 ,
F_5 ( V_7 % V_13 ) | V_20 ,
F_5 ( V_7 % V_13 ) | V_20 ) ;
if ( V_8 < 0 )
F_11 ( V_3 -> V_21 , L_1 , V_8 ) ;
}
static int F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_21 = & V_23 -> V_21 ;
const struct V_25 * V_26 ;
struct V_1 * V_5 ;
struct V_27 * V_28 = V_21 -> V_29 ;
int V_8 ;
V_26 = F_13 ( V_30 , V_21 ) ;
if ( ! V_26 )
return - V_31 ;
V_5 = F_14 ( V_21 , sizeof( * V_5 ) , V_32 ) ;
if ( ! V_5 )
return - V_33 ;
V_5 -> V_10 = V_26 -> V_10 ;
if ( V_5 -> V_10 -> V_34 ) {
V_5 -> V_12 = F_15 (
V_5 -> V_10 -> V_34 ) ;
if ( F_16 ( V_5 -> V_12 ) )
return F_17 ( V_5 -> V_12 ) ;
} else {
V_5 -> V_12 =
F_18 ( V_28 , L_2 ) ;
if ( F_16 ( V_5 -> V_12 ) )
return F_17 ( V_5 -> V_12 ) ;
V_8 = F_19 ( V_28 , L_2 , 1 ,
& V_5 -> V_9 ) ;
if ( V_8 )
F_11 ( V_21 , L_3 ) ;
V_5 -> V_9 <<= 3 ;
V_8 = F_19 ( V_28 , L_2 , 2 ,
& V_5 -> V_17 ) ;
if ( V_8 )
F_20 ( V_21 , L_4 ) ;
V_5 -> V_17 <<= 3 ;
}
V_5 -> V_3 . V_21 = V_21 ;
V_5 -> V_3 . V_35 = V_36 ;
V_5 -> V_3 . V_37 = F_21 ( V_21 ) ;
V_5 -> V_3 . V_38 = - 1 ;
V_5 -> V_3 . V_39 = V_5 -> V_10 -> V_40 ;
V_5 -> V_3 . V_41 = F_3 ;
if ( V_5 -> V_10 -> V_15 & V_42 )
V_5 -> V_3 . V_43 = F_8 ;
if ( V_5 -> V_10 -> V_15 & V_44 ) {
V_5 -> V_3 . V_19 = V_5 -> V_10 -> V_19 ? : F_6 ;
V_5 -> V_3 . V_45 = F_9 ;
}
F_22 ( V_23 , V_5 ) ;
return F_23 ( & V_5 -> V_3 ) ;
}
static int F_24 ( struct V_22 * V_23 )
{
struct V_1 * V_5 = F_25 ( V_23 ) ;
F_26 ( & V_5 -> V_3 ) ;
return 0 ;
}
