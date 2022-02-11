static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void T_2 * V_5 = V_4 -> V_6 ;
int V_7 ;
T_1 V_8 = 0 , V_9 = 0 ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
if ( F_3 ( V_4 -> V_11 , V_5 + ( V_7 * 4 ) ) )
V_8 |= 1UL << V_7 ;
}
if ( V_8 & V_12 )
V_9 |= V_13 ;
if ( V_8 & V_14 )
V_9 |= V_15 ;
if ( V_8 & V_16 )
V_9 |= V_17 ;
return V_9 ;
}
static void F_4 ( struct V_1 * V_2 , int type )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void T_2 * V_5 = V_4 -> V_6 ;
T_1 V_18 = F_5 ( type ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
if ( V_18 & ( 1UL << V_7 ) )
F_6 ( V_4 -> V_11 , 1 , V_5 + ( V_7 * 4 ) ) ;
}
}
static void F_7 ( struct V_1 * V_2 , int type ,
bool V_19 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
void T_2 * V_5 = V_4 -> V_20 ;
T_1 V_18 = F_5 ( type ) ;
T_1 V_8 ;
unsigned long V_21 ;
F_8 ( & V_4 -> V_22 , V_21 ) ;
V_8 = F_3 ( V_4 -> V_11 , V_5 ) ;
if ( V_19 )
V_8 = V_8 | ( V_18 << V_23 ) ;
else
V_8 = V_8 & ~ ( V_18 << V_23 ) ;
F_6 ( V_4 -> V_11 , V_8 , V_5 ) ;
F_9 ( & V_4 -> V_22 , V_21 ) ;
}
static int F_10 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_25 -> V_27 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
V_4 = F_11 ( V_27 , sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_2 = & V_4 -> V_2 ;
V_4 -> V_25 = V_25 ;
F_12 ( & V_4 -> V_22 ) ;
V_29 = F_13 ( V_25 , V_32 , L_1 ) ;
V_4 -> V_20 = F_14 ( V_27 , V_29 ) ;
if ( F_15 ( V_4 -> V_20 ) )
return F_16 ( V_4 -> V_20 ) ;
V_29 = F_13 ( V_25 , V_32 ,
L_2 ) ;
V_4 -> V_6 = F_14 ( V_27 , V_29 ) ;
if ( F_15 ( V_4 -> V_6 ) )
return F_16 ( V_4 -> V_6 ) ;
V_4 -> V_11 = F_17 ( V_27 -> V_33 ) ;
F_4 ( V_2 , V_34 ) ;
F_7 ( V_2 , V_34 , false ) ;
V_2 -> V_35 = F_4 ;
V_2 -> V_36 = F_7 ;
V_2 -> V_37 = F_1 ;
return F_18 ( V_25 , V_2 ) ;
}
static int F_19 ( struct V_24 * V_25 )
{
return F_20 ( V_25 ) ;
}
