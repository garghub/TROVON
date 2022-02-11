static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 , V_7 ;
int V_8 ;
V_7 = V_5 -> V_9 + V_5 -> V_10 -> V_11 + V_3 ;
V_8 = F_3 ( V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 , & V_6 ) ;
if ( V_8 )
return V_8 ;
return ! ! ( V_6 & F_4 ( V_7 % V_13 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_6 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = V_5 -> V_9 + V_5 -> V_10 -> V_11 + V_3 ;
F_6 ( V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 ,
F_4 ( V_7 % V_13 ) ,
V_6 ? F_4 ( V_7 % V_13 ) : 0 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_10 -> V_15 & V_16 ) {
unsigned int V_7 ;
V_7 = V_5 -> V_17 +
V_5 -> V_10 -> V_18 + V_3 ;
F_6 ( V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 ,
F_4 ( V_7 % V_13 ) , 0 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 , int V_6 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_10 -> V_15 & V_16 ) {
unsigned int V_7 ;
V_7 = V_5 -> V_17 +
V_5 -> V_10 -> V_18 + V_3 ;
F_6 ( V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 ,
F_4 ( V_7 % V_13 ) ,
F_4 ( V_7 % V_13 ) ) ;
}
V_5 -> V_10 -> V_19 ( V_2 , V_3 , V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 , int V_6 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_7 ;
int V_8 ;
V_7 = V_5 -> V_9 + V_5 -> V_10 -> V_11 + V_3 ;
if ( ! V_6 )
return;
V_8 = F_6 (
V_5 -> V_12 ,
( V_7 / V_13 ) * V_14 ,
F_4 ( V_7 % V_13 ) | V_20 ,
F_4 ( V_7 % V_13 ) | V_20 ) ;
if ( V_8 < 0 )
F_10 ( V_2 -> V_21 , L_1 , V_8 ) ;
}
static int F_11 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_25 ;
const struct V_26 * V_27 ;
struct V_4 * V_5 ;
struct V_28 * V_29 = V_25 -> V_30 ;
int V_8 ;
V_27 = F_12 ( V_31 , V_25 ) ;
if ( ! V_27 )
return - V_32 ;
V_5 = F_13 ( V_25 , sizeof( * V_5 ) , V_33 ) ;
if ( ! V_5 )
return - V_34 ;
V_5 -> V_10 = V_27 -> V_10 ;
if ( V_5 -> V_10 -> V_35 ) {
V_5 -> V_12 = F_14 (
V_5 -> V_10 -> V_35 ) ;
if ( F_15 ( V_5 -> V_12 ) )
return F_16 ( V_5 -> V_12 ) ;
} else {
V_5 -> V_12 =
F_17 ( V_29 , L_2 ) ;
if ( F_15 ( V_5 -> V_12 ) )
return F_16 ( V_5 -> V_12 ) ;
V_8 = F_18 ( V_29 , L_2 , 1 ,
& V_5 -> V_9 ) ;
if ( V_8 )
F_10 ( V_25 , L_3 ) ;
V_5 -> V_9 <<= 3 ;
V_8 = F_18 ( V_29 , L_2 , 2 ,
& V_5 -> V_17 ) ;
if ( V_8 )
F_19 ( V_25 , L_4 ) ;
V_5 -> V_17 <<= 3 ;
}
V_5 -> V_2 . V_21 = V_25 ;
V_5 -> V_2 . V_36 = V_37 ;
V_5 -> V_2 . V_38 = F_20 ( V_25 ) ;
V_5 -> V_2 . V_39 = - 1 ;
V_5 -> V_2 . V_40 = V_5 -> V_10 -> V_41 ;
V_5 -> V_2 . V_42 = F_1 ;
if ( V_5 -> V_10 -> V_15 & V_43 )
V_5 -> V_2 . V_44 = F_7 ;
if ( V_5 -> V_10 -> V_15 & V_45 ) {
V_5 -> V_2 . V_19 = V_5 -> V_10 -> V_19 ? : F_5 ;
V_5 -> V_2 . V_46 = F_8 ;
}
F_21 ( V_23 , V_5 ) ;
return F_22 ( & V_23 -> V_25 , & V_5 -> V_2 , V_5 ) ;
}
