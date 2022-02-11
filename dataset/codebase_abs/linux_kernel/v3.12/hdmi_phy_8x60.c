static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
V_6 = F_5 ( V_5 , V_7 ) ;
if ( V_6 & V_8 ) {
F_6 ( V_5 , V_7 ,
V_6 & ~ V_9 ) ;
} else {
F_6 ( V_5 , V_7 ,
V_6 | V_9 ) ;
}
F_7 ( 100 ) ;
if ( V_6 & V_8 ) {
F_6 ( V_5 , V_7 ,
V_6 | V_9 ) ;
} else {
F_6 ( V_5 , V_7 ,
V_6 & ~ V_9 ) ;
}
}
static void F_8 ( struct V_1 * V_2 ,
unsigned long int V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
F_6 ( V_5 , V_11 ,
F_9 ( 3 ) ) ;
if ( V_10 == 27000000 ) {
F_6 ( V_5 , V_12 ,
F_10 ( 5 ) |
F_11 ( 3 ) ) ;
} else {
F_6 ( V_5 , V_12 ,
F_10 ( 5 ) |
F_11 ( 4 ) ) ;
}
F_6 ( V_5 , V_13 ,
V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 ) ;
F_6 ( V_5 , V_13 ,
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 ) ;
F_6 ( V_5 , V_13 ,
V_16 |
V_17 |
V_18 |
V_19 |
V_20 ) ;
F_6 ( V_5 , V_21 ,
V_22 ) ;
F_6 ( V_5 , V_23 , 0 ) ;
F_6 ( V_5 , V_24 ,
V_25 |
V_26 ) ;
F_6 ( V_5 , V_13 ,
V_20 ) ;
F_6 ( V_5 , V_13 ,
V_27 |
V_20 ) ;
F_6 ( V_5 , V_28 , 0 ) ;
F_6 ( V_5 , V_29 , 0 ) ;
F_6 ( V_5 , V_30 , 0 ) ;
F_6 ( V_5 , V_31 , 0 ) ;
F_6 ( V_5 , V_32 , 0 ) ;
F_6 ( V_5 , V_23 , 0 ) ;
F_6 ( V_5 , V_33 , 0 ) ;
F_6 ( V_5 , V_34 , 0 ) ;
F_6 ( V_5 , V_24 ,
V_25 |
V_26 |
V_35 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
F_6 ( V_5 , V_7 ,
V_9 ) ;
F_13 ( 10 ) ;
F_6 ( V_5 , V_7 , 0 ) ;
F_6 ( V_5 , V_13 ,
V_16 |
V_17 |
V_18 |
V_19 |
V_20 ) ;
F_13 ( 10 ) ;
F_6 ( V_5 , V_21 , 0 ) ;
F_6 ( V_5 , V_13 ,
V_27 |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 ) ;
}
struct V_1 * F_14 ( struct V_5 * V_5 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = NULL ;
int V_36 ;
V_4 = F_15 ( sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 ) {
V_36 = - V_38 ;
goto V_39;
}
V_2 = & V_4 -> V_40 ;
V_2 -> V_41 = & V_42 ;
V_4 -> V_5 = V_5 ;
return V_2 ;
V_39:
if ( V_2 )
F_1 ( V_2 ) ;
return F_16 ( V_36 ) ;
}
