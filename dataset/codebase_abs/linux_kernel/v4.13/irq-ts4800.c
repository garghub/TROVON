static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
T_1 V_8 = 1 << V_2 -> V_9 ;
F_4 ( V_5 | V_8 , V_4 -> V_6 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
T_1 V_8 = 1 << V_2 -> V_9 ;
F_4 ( V_5 & ~ V_8 , V_4 -> V_6 + V_7 ) ;
}
static int F_6 ( struct V_10 * V_2 , unsigned int V_11 ,
T_2 V_9 )
{
struct V_3 * V_4 = V_2 -> V_12 ;
F_7 ( V_11 , & V_4 -> V_13 , V_14 ) ;
F_8 ( V_11 , V_4 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static void F_10 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_11 ( V_16 ) ;
struct V_13 * V_17 = F_12 ( V_16 ) ;
T_1 V_18 = F_3 ( V_4 -> V_6 + V_19 ) ;
F_13 ( V_17 , V_16 ) ;
if ( F_14 ( V_18 == 0 ) ) {
F_15 ( V_16 ) ;
goto V_20;
}
do {
unsigned int V_21 = F_16 ( V_18 ) ;
int V_11 = F_17 ( V_4 -> V_22 , V_21 ) ;
V_18 &= ~ ( 1 << V_21 ) ;
F_18 ( V_11 ) ;
} while ( V_18 );
V_20:
F_19 ( V_17 , V_16 ) ;
}
static int F_20 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 . V_28 ;
struct V_3 * V_4 ;
struct V_13 * V_13 ;
struct V_29 * V_30 ;
int V_31 ;
V_4 = F_21 ( & V_24 -> V_27 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return - V_33 ;
V_30 = F_22 ( V_24 , V_34 , 0 ) ;
V_4 -> V_6 = F_23 ( & V_24 -> V_27 , V_30 ) ;
if ( F_24 ( V_4 -> V_6 ) )
return F_25 ( V_4 -> V_6 ) ;
F_4 ( 0xFFFF , V_4 -> V_6 + V_7 ) ;
V_31 = F_26 ( V_26 , 0 ) ;
if ( ! V_31 ) {
F_27 ( & V_24 -> V_27 , L_1 ) ;
return - V_35 ;
}
V_13 = & V_4 -> V_13 ;
V_13 -> V_36 = F_28 ( & V_24 -> V_27 ) ;
V_13 -> V_37 = F_1 ;
V_13 -> V_38 = F_5 ;
V_4 -> V_22 = F_29 ( V_26 , 8 , & V_39 , V_4 ) ;
if ( ! V_4 -> V_22 ) {
F_27 ( & V_24 -> V_27 , L_2 ) ;
return - V_33 ;
}
F_30 ( V_31 ,
F_10 , V_4 ) ;
F_31 ( V_24 , V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_33 ( V_24 ) ;
F_34 ( V_4 -> V_22 ) ;
return 0 ;
}
