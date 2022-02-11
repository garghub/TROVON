static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
unsigned long V_6 ;
F_3 ( & V_4 -> V_7 , V_6 ) ;
F_4 ( V_8 | ( F_5 ( V_2 -> V_9 ) &
V_10 ) , V_4 -> V_11 + V_12 ) ;
V_5 = F_6 ( V_4 -> V_11 + V_13 ) ;
F_4 ( V_8 | ( V_5 & V_14 ) |
V_15 , V_4 -> V_11 + V_13 ) ;
F_7 ( & V_4 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( V_8 | V_16 , V_4 -> V_11 + V_13 ) ;
F_9 ( V_2 -> V_17 , L_1 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_18 )
{
V_2 -> V_9 = V_18 ;
return 0 ;
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_19 = F_6 ( V_4 -> V_11 + V_12 ) ;
return F_12 ( V_19 & V_10 ) ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_22 * V_17 = & V_21 -> V_17 ;
struct V_23 * V_24 = V_17 -> V_25 ;
struct V_3 * V_4 ;
int V_26 ;
V_4 = F_14 ( V_17 , sizeof( struct V_3 ) , V_27 ) ;
if ( ! V_4 ) {
F_15 ( V_17 , L_2 ) ;
return - V_28 ;
}
F_16 ( V_21 , V_4 ) ;
F_17 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = F_18 ( V_24 , 0 ) ;
if ( ! V_4 -> V_11 ) {
F_15 ( V_17 , L_3 ) ;
return - V_29 ;
}
F_19 ( & V_30 , V_4 ) ;
F_20 ( & V_30 , V_31 , V_17 ) ;
F_21 ( & V_30 , V_32 ) ;
V_26 = F_22 ( & V_30 ) ;
if ( V_26 ) {
F_15 ( V_17 , L_4 ) ;
F_23 ( V_4 -> V_11 ) ;
return V_26 ;
}
F_9 ( V_17 , L_5 ) ;
return 0 ;
}
static int F_24 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_25 ( V_21 ) ;
F_26 ( & V_30 ) ;
F_23 ( V_4 -> V_11 ) ;
return 0 ;
}
static void F_27 ( struct V_20 * V_21 )
{
F_8 ( & V_30 ) ;
}
