static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned long int V_5 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_4 -> V_6 ;
F_5 ( V_6 , V_7 ,
F_6 ( 3 ) ) ;
if ( V_5 == 27000000 ) {
F_5 ( V_6 , V_8 ,
F_7 ( 5 ) |
F_8 ( 3 ) ) ;
} else {
F_5 ( V_6 , V_8 ,
F_7 ( 5 ) |
F_8 ( 4 ) ) ;
}
F_5 ( V_6 , V_9 ,
V_10 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 ) ;
F_5 ( V_6 , V_9 ,
V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 ) ;
F_5 ( V_6 , V_9 ,
V_12 |
V_13 |
V_14 |
V_15 |
V_16 ) ;
F_5 ( V_6 , V_17 ,
V_18 ) ;
F_5 ( V_6 , V_19 , 0 ) ;
F_5 ( V_6 , V_20 ,
V_21 |
V_22 ) ;
F_5 ( V_6 , V_9 ,
V_16 ) ;
F_5 ( V_6 , V_9 ,
V_23 |
V_16 ) ;
F_5 ( V_6 , V_24 , 0 ) ;
F_5 ( V_6 , V_25 , 0 ) ;
F_5 ( V_6 , V_26 , 0 ) ;
F_5 ( V_6 , V_27 , 0 ) ;
F_5 ( V_6 , V_28 , 0 ) ;
F_5 ( V_6 , V_19 , 0 ) ;
F_5 ( V_6 , V_29 , 0 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_20 ,
V_21 |
V_22 |
V_31 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_4 -> V_6 ;
F_5 ( V_6 , V_32 ,
V_33 ) ;
F_10 ( 10 ) ;
F_5 ( V_6 , V_32 , 0 ) ;
F_5 ( V_6 , V_9 ,
V_12 |
V_13 |
V_14 |
V_15 |
V_16 ) ;
F_10 ( 10 ) ;
F_5 ( V_6 , V_17 , 0 ) ;
F_5 ( V_6 , V_9 ,
V_23 |
V_10 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 ) ;
}
struct V_1 * F_11 ( struct V_6 * V_6 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = NULL ;
int V_34 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 ) {
V_34 = - V_36 ;
goto V_37;
}
V_2 = & V_4 -> V_38 ;
V_2 -> V_39 = & V_40 ;
V_4 -> V_6 = V_6 ;
return V_2 ;
V_37:
if ( V_2 )
F_1 ( V_2 ) ;
return F_13 ( V_34 ) ;
}
