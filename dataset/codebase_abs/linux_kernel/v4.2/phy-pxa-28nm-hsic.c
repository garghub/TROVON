static bool F_1 ( void T_1 * V_1 , T_2 V_2 , unsigned long V_3 )
{
V_3 += V_4 ;
while ( F_2 ( V_3 ) ) {
if ( ( F_3 ( V_1 ) & V_2 ) == V_2 )
return true ;
F_4 ( 1 ) ;
}
return false ;
}
static int F_5 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
void T_1 * V_10 = V_7 -> V_10 ;
F_7 ( V_7 -> V_11 ) ;
F_8 ( 0x1 << V_12 |
0xf0 << V_13 |
0xd << V_14 ,
V_10 + V_15 ) ;
F_8 ( F_3 ( V_10 + V_16 ) |
V_17 ,
V_10 + V_16 ) ;
if ( ! F_1 ( V_10 + V_16 ,
V_18 , V_19 / 10 ) ) {
F_9 ( & V_9 -> V_20 , L_1 ) ;
F_10 ( V_7 -> V_11 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_11 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
void T_1 * V_10 = V_7 -> V_10 ;
T_2 V_1 ;
V_1 = F_3 ( V_10 + V_22 ) ;
V_1 &= ~ V_23 ;
V_1 |= V_24 ;
F_8 ( V_1 , V_10 + V_22 ) ;
if ( ! F_1 ( V_10 + V_25 ,
V_26 , V_19 / 10 ) ) {
F_12 ( & V_9 -> V_20 , L_2 ) ;
return - V_21 ;
}
if ( ! F_1 ( V_10 + V_27 ,
V_28 , V_19 / 5 ) ) {
F_12 ( & V_9 -> V_20 , L_3 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_13 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
void T_1 * V_10 = V_7 -> V_10 ;
F_8 ( F_3 ( V_10 + V_22 ) & ~ V_24 ,
V_10 + V_22 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
void T_1 * V_10 = V_7 -> V_10 ;
F_8 ( F_3 ( V_10 + V_16 ) &
~ V_17 ,
V_10 + V_16 ) ;
F_10 ( V_7 -> V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_29 * V_29 ;
struct V_6 * V_7 ;
struct V_30 * V_31 ;
V_7 = F_16 ( & V_9 -> V_20 , sizeof( * V_7 ) , V_32 ) ;
if ( ! V_7 )
return - V_33 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_11 = F_17 ( & V_9 -> V_20 , NULL ) ;
if ( F_18 ( V_7 -> V_11 ) ) {
F_9 ( & V_9 -> V_20 , L_4 ) ;
return F_19 ( V_7 -> V_11 ) ;
}
V_31 = F_20 ( V_9 , V_34 , 0 ) ;
V_7 -> V_10 = F_21 ( & V_9 -> V_20 , V_31 ) ;
if ( F_18 ( V_7 -> V_10 ) )
return F_19 ( V_7 -> V_10 ) ;
V_7 -> V_5 = F_22 ( & V_9 -> V_20 , V_9 -> V_20 . V_35 , & V_36 ) ;
if ( F_18 ( V_7 -> V_5 ) )
return F_19 ( V_7 -> V_5 ) ;
F_23 ( V_7 -> V_5 , V_7 ) ;
V_29 = F_24 ( & V_9 -> V_20 , V_37 ) ;
return F_25 ( V_29 ) ;
}
