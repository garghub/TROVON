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
static unsigned int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_16 = F_5 ( V_5 -> V_8 + V_11 ) ;
return ( V_16 & V_17 ) << V_18 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_17 , V_5 -> V_8 + V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( 0 , V_5 -> V_8 + V_11 ) ;
return 0 ;
}
static T_3 F_13 ( int V_19 , void * V_20 )
{
F_14 ( V_21 L_1 ) ;
return V_22 ;
}
static int F_15 ( struct V_23 * V_24 )
{
void T_4 * V_25 , * V_26 ;
struct V_27 * V_28 = & V_24 -> V_28 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_29 * V_30 ;
int V_31 , V_19 ;
T_2 V_16 ;
V_5 = F_16 ( V_28 , sizeof( * V_5 ) , V_32 ) ;
if ( ! V_5 )
return - V_33 ;
F_17 ( V_24 , V_5 ) ;
V_30 = F_18 ( V_24 , V_34 , 0 ) ;
V_26 = F_19 ( V_28 , V_30 ) ;
if ( F_20 ( V_26 ) )
return F_21 ( V_26 ) ;
V_30 = F_18 ( V_24 , V_34 , 1 ) ;
V_25 = F_19 ( V_28 , V_30 ) ;
if ( F_20 ( V_25 ) )
return F_21 ( V_25 ) ;
V_5 -> V_7 = F_22 () ;
V_5 -> V_14 = V_25 ;
V_5 -> V_8 = V_26 ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_35 = V_28 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = & V_39 ;
V_2 -> V_40 = 1 ;
V_2 -> V_41 = V_42 / V_5 -> V_7 ;
V_2 -> V_3 = V_43 ;
F_23 ( V_2 , V_5 ) ;
F_24 ( V_2 , V_44 ) ;
V_16 = F_5 ( V_26 + V_11 ) ;
if ( V_16 & V_45 ) {
F_25 ( V_28 , L_2 ) ;
V_2 -> V_46 |= V_47 ;
}
if ( V_6 ) {
V_19 = F_26 ( V_24 , 0 ) ;
if ( V_19 < 0 ) {
V_6 = 0 ;
F_25 ( V_28 , L_3 ) ;
} else {
F_3 ( 0 , V_25 + V_15 ) ;
if ( F_27 ( V_28 , V_19 , F_13 , 0 ,
V_24 -> V_48 , V_5 ) ) {
V_6 = 0 ;
F_25 ( V_28 , L_4 ,
V_19 ) ;
}
}
if ( ! V_6 )
F_25 ( V_28 , L_5 ) ;
}
if ( ! V_6 )
V_2 -> V_41 *= 2 ;
F_28 ( V_2 , V_3 , V_28 ) ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_31 = F_29 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_30 ( V_28 , L_6 ,
V_2 -> V_3 , V_5 -> V_7 , V_6 ,
V_16 & V_17 ? L_7 : L_8 ) ;
return 0 ;
}
static void F_31 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_32 ( V_24 ) ;
F_12 ( & V_5 -> V_2 ) ;
}
static int F_33 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_32 ( V_24 ) ;
F_34 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int T_5 F_35 ( struct V_27 * V_28 )
{
struct V_4 * V_5 = F_36 ( V_28 ) ;
if ( F_37 ( & V_5 -> V_2 ) )
F_12 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int T_5 F_38 ( struct V_27 * V_28 )
{
struct V_4 * V_5 = F_36 ( V_28 ) ;
if ( F_37 ( & V_5 -> V_2 ) )
F_11 ( & V_5 -> V_2 ) ;
return 0 ;
}
