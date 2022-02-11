static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
unsigned long V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_7 -> V_8 ) ;
F_4 ( 0 , V_7 -> V_9 + V_10 ) ;
F_4 ( 0 , V_7 -> V_9 + V_11 ) ;
V_3 = V_12 | V_13 | V_14 ;
F_4 ( V_3 , V_7 -> V_9 + V_11 ) ;
F_4 ( 0 , V_7 -> V_9 + V_15 ) ;
F_4 ( 0 , V_7 -> V_9 + V_16 ) ;
V_4 = ( ( ( V_17 ) V_2 -> V_18 * V_5 ) & 0xffffffff ) ;
F_4 ( V_4 , V_7 -> V_9 + V_19 ) ;
V_4 = ( ( ( V_17 ) V_2 -> V_18 * V_5 ) >> 32 ) ;
F_4 ( V_4 , V_7 -> V_9 + V_20 ) ;
F_4 ( V_21 , V_7 -> V_9 + V_10 ) ;
F_4 ( V_22 | V_23 , V_7 -> V_9 + V_24 ) ;
F_4 ( V_25 | V_23 , V_7 -> V_9 + V_24 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_4 ( V_22 , V_7 -> V_9 + V_24 ) ;
F_4 ( V_25 , V_7 -> V_9 + V_24 ) ;
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
V_17 V_26 ;
unsigned long V_27 ;
T_1 V_28 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_28 = F_7 ( V_7 -> V_9 + V_24 ) ;
if ( V_28 & V_29 )
return 0 ;
V_27 = F_3 ( V_7 -> V_8 ) ;
if ( ! V_27 )
return 0 ;
V_26 = F_7 ( V_7 -> V_9 + V_15 ) ;
V_26 |= ( ( V_17 ) F_7 ( V_7 -> V_9 + V_16 ) << 32 ) ;
F_8 ( V_26 , V_27 ) ;
return V_2 -> V_18 - V_26 ;
}
static int F_9 ( struct V_30 * V_31 )
{
int V_32 = 0 ;
struct V_33 * V_34 = & V_31 -> V_34 ;
struct V_35 * V_36 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_7 = F_10 ( V_34 , sizeof( * V_7 ) , V_37 ) ;
if ( ! V_7 )
return - V_38 ;
V_7 -> V_8 = F_11 ( V_34 , NULL ) ;
if ( F_12 ( F_13 ( V_7 -> V_8 ) ) )
return F_14 ( V_7 -> V_8 ) ;
F_15 ( V_7 -> V_8 ) ;
F_16 ( V_31 , V_7 ) ;
V_2 = & V_7 -> V_2 ;
V_2 -> V_39 = & V_40 ;
V_2 -> V_41 = & V_42 ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_18 = V_46 ;
F_17 ( V_2 , V_47 , V_34 ) ;
F_18 ( V_34 , L_1 , V_2 -> V_18 ) ;
F_19 ( V_2 , V_7 ) ;
F_20 ( V_2 , 1 ) ;
V_36 = F_21 ( V_31 , V_48 , 0 ) ;
V_7 -> V_9 = F_22 ( V_34 , V_36 ) ;
if ( F_13 ( V_7 -> V_9 ) )
return F_14 ( V_7 -> V_9 ) ;
V_32 = F_23 ( V_2 ) ;
if ( V_32 < 0 )
F_24 ( V_34 , L_2 ) ;
return V_32 ;
}
static int F_25 ( struct V_30 * V_31 )
{
struct V_6 * V_7 = F_26 ( V_31 ) ;
F_27 ( & V_7 -> V_2 ) ;
F_28 ( V_7 -> V_8 ) ;
return 0 ;
}
