static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_2 -> V_3 = V_3 ;
if ( V_6 )
F_3 ( V_5 -> V_7 * V_3 ,
V_5 -> V_8 + V_9 ) ;
else
F_3 ( V_5 -> V_7 / 2 * V_3 ,
V_5 -> V_8 + V_9 ) ;
return 0 ;
}
static unsigned int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! V_6 &&
! ( F_5 ( V_5 -> V_8 + V_11 ) & V_12 ) )
V_10 += F_5 ( V_5 -> V_8 + V_9 ) ;
V_10 += F_6 ( V_5 -> V_8 + V_13 ) -
F_7 () ;
F_8 ( V_10 , V_5 -> V_7 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( 0 , V_5 -> V_14 + V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_16 , V_5 -> V_8 + V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( 0 , V_5 -> V_8 + V_11 ) ;
return 0 ;
}
static T_2 F_12 ( int V_17 , void * V_18 )
{
F_13 ( V_19 L_1 ) ;
return V_20 ;
}
static int F_14 ( struct V_21 * V_22 )
{
void T_3 * V_23 , * V_24 ;
struct V_25 * V_26 = & V_22 -> V_26 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_27 * V_28 ;
int V_29 , V_17 ;
T_4 V_30 ;
V_5 = F_15 ( V_26 , sizeof( * V_5 ) , V_31 ) ;
if ( ! V_5 )
return - V_32 ;
F_16 ( V_22 , V_5 ) ;
V_28 = F_17 ( V_22 , V_33 , 0 ) ;
V_24 = F_18 ( V_26 , V_28 ) ;
if ( F_19 ( V_24 ) )
return F_20 ( V_24 ) ;
V_28 = F_17 ( V_22 , V_33 , 1 ) ;
V_23 = F_18 ( V_26 , V_28 ) ;
if ( F_19 ( V_23 ) )
return F_20 ( V_23 ) ;
V_5 -> V_7 = F_21 () ;
V_5 -> V_14 = V_23 ;
V_5 -> V_8 = V_24 ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_34 = V_26 ;
V_2 -> V_35 = & V_36 ;
V_2 -> V_37 = & V_38 ;
V_2 -> V_39 = 1 ;
V_2 -> V_40 = V_41 / V_5 -> V_7 * 1000 ;
V_2 -> V_3 = V_42 ;
F_22 ( V_2 , V_5 ) ;
F_23 ( V_2 , V_43 ) ;
V_30 = F_5 ( V_24 + V_11 ) ;
if ( V_30 & V_44 ) {
F_24 ( V_26 , L_2 ) ;
V_2 -> V_45 |= V_46 ;
}
if ( V_30 & V_16 )
F_25 ( V_47 , & V_2 -> V_30 ) ;
if ( V_6 ) {
V_17 = F_26 ( V_22 , 0 ) ;
if ( V_17 < 0 ) {
V_6 = 0 ;
F_24 ( V_26 , L_3 ) ;
} else {
F_3 ( 0 , V_23 + V_15 ) ;
if ( F_27 ( V_26 , V_17 , F_12 , 0 ,
V_22 -> V_48 , V_5 ) ) {
V_6 = 0 ;
F_24 ( V_26 , L_4 ,
V_17 ) ;
}
}
if ( ! V_6 )
F_24 ( V_26 , L_5 ) ;
}
if ( ! V_6 )
V_2 -> V_40 *= 2 ;
F_28 ( V_2 , V_3 , V_26 ) ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_29 = F_29 ( V_2 ) ;
if ( V_29 )
return V_29 ;
F_30 ( V_26 , L_6 ,
V_2 -> V_3 , V_5 -> V_7 , V_6 ,
V_30 & V_16 ? L_7 : L_8 ) ;
return 0 ;
}
static void F_31 ( struct V_21 * V_22 )
{
struct V_4 * V_5 = F_32 ( V_22 ) ;
F_11 ( & V_5 -> V_2 ) ;
}
static int F_33 ( struct V_21 * V_22 )
{
struct V_4 * V_5 = F_32 ( V_22 ) ;
F_34 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int T_5 F_35 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_36 ( V_26 ) ;
if ( F_37 ( & V_5 -> V_2 ) )
F_11 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int T_5 F_38 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_36 ( V_26 ) ;
if ( F_37 ( & V_5 -> V_2 ) )
F_10 ( & V_5 -> V_2 ) ;
return 0 ;
}
