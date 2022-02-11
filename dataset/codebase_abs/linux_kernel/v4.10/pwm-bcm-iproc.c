static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , unsigned int V_5 )
{
T_1 V_6 ;
V_6 = F_4 ( V_4 -> V_7 + V_8 ) ;
V_6 |= 1 << F_5 ( V_5 ) ;
F_6 ( V_6 , V_4 -> V_7 + V_8 ) ;
F_7 ( 400 ) ;
}
static void F_8 ( struct V_1 * V_4 , unsigned int V_5 )
{
T_1 V_6 ;
V_6 = F_4 ( V_4 -> V_7 + V_8 ) ;
V_6 &= ~ ( 1 << F_5 ( V_5 ) ) ;
F_6 ( V_6 , V_4 -> V_7 + V_8 ) ;
F_7 ( 400 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_13 , V_14 , V_15 ;
T_1 V_6 , V_16 ;
V_15 = F_10 ( V_4 -> V_17 ) ;
V_6 = F_4 ( V_4 -> V_7 + V_8 ) ;
if ( V_6 & F_11 ( F_5 ( V_10 -> V_18 ) ) )
V_12 -> V_19 = true ;
else
V_12 -> V_19 = false ;
if ( V_6 & F_11 ( F_12 ( V_10 -> V_18 ) ) )
V_12 -> V_20 = V_21 ;
else
V_12 -> V_20 = V_22 ;
V_6 = F_4 ( V_4 -> V_7 + V_23 ) ;
V_16 = V_6 >> F_13 ( V_10 -> V_18 ) ;
V_16 &= V_24 ;
V_14 = V_25 * ( V_16 + 1 ) ;
V_6 = F_4 ( V_4 -> V_7 + F_14 ( V_10 -> V_18 ) ) ;
V_13 = ( V_6 & V_26 ) * V_14 ;
V_12 -> V_27 = F_15 ( V_13 , V_15 ) ;
V_6 = F_4 ( V_4 -> V_7 + F_16 ( V_10 -> V_18 ) ) ;
V_13 = ( V_6 & V_26 ) * V_14 ;
V_12 -> V_28 = F_15 ( V_13 , V_15 ) ;
}
static int F_17 ( struct V_2 * V_3 , struct V_9 * V_10 ,
struct V_11 * V_12 )
{
unsigned long V_16 = V_29 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_6 , V_27 , V_30 ;
T_2 V_15 ;
V_15 = F_10 ( V_4 -> V_17 ) ;
while ( 1 ) {
T_2 V_6 , div ;
div = V_25 * ( V_16 + 1 ) ;
V_6 = V_15 * V_12 -> V_27 ;
V_27 = F_15 ( V_6 , div ) ;
V_6 = V_15 * V_12 -> V_28 ;
V_30 = F_15 ( V_6 , div ) ;
if ( V_27 < V_31 ||
V_30 < V_32 )
return - V_33 ;
if ( V_27 <= V_26 &&
V_30 <= V_34 )
break;
if ( ++ V_16 > V_24 )
return - V_33 ;
}
F_8 ( V_4 , V_10 -> V_18 ) ;
V_6 = F_4 ( V_4 -> V_7 + V_23 ) ;
V_6 &= ~ F_18 ( V_10 -> V_18 ) ;
V_6 |= V_16 << F_13 ( V_10 -> V_18 ) ;
F_6 ( V_6 , V_4 -> V_7 + V_23 ) ;
F_6 ( V_27 , V_4 -> V_7 + F_14 ( V_10 -> V_18 ) ) ;
F_6 ( V_30 , V_4 -> V_7 + F_16 ( V_10 -> V_18 ) ) ;
V_6 = F_4 ( V_4 -> V_7 + V_8 ) ;
if ( V_12 -> V_20 == V_21 )
V_6 |= 1 << F_12 ( V_10 -> V_18 ) ;
else
V_6 &= ~ ( 1 << F_12 ( V_10 -> V_18 ) ) ;
F_6 ( V_6 , V_4 -> V_7 + V_8 ) ;
if ( V_12 -> V_19 )
F_3 ( V_4 , V_10 -> V_18 ) ;
return 0 ;
}
static int F_19 ( struct V_35 * V_36 )
{
struct V_1 * V_4 ;
struct V_37 * V_38 ;
unsigned int V_39 ;
T_1 V_6 ;
int V_40 ;
V_4 = F_20 ( & V_36 -> V_41 , sizeof( * V_4 ) , V_42 ) ;
if ( ! V_4 )
return - V_43 ;
F_21 ( V_36 , V_4 ) ;
V_4 -> V_3 . V_41 = & V_36 -> V_41 ;
V_4 -> V_3 . V_44 = & V_45 ;
V_4 -> V_3 . V_7 = - 1 ;
V_4 -> V_3 . V_46 = 4 ;
V_4 -> V_3 . V_47 = V_48 ;
V_4 -> V_3 . V_49 = 3 ;
V_38 = F_22 ( V_36 , V_50 , 0 ) ;
V_4 -> V_7 = F_23 ( & V_36 -> V_41 , V_38 ) ;
if ( F_24 ( V_4 -> V_7 ) )
return F_25 ( V_4 -> V_7 ) ;
V_4 -> V_17 = F_26 ( & V_36 -> V_41 , NULL ) ;
if ( F_24 ( V_4 -> V_17 ) ) {
F_27 ( & V_36 -> V_41 , L_1 ,
F_25 ( V_4 -> V_17 ) ) ;
return F_25 ( V_4 -> V_17 ) ;
}
V_40 = F_28 ( V_4 -> V_17 ) ;
if ( V_40 < 0 ) {
F_27 ( & V_36 -> V_41 , L_2 , V_40 ) ;
return V_40 ;
}
V_6 = F_4 ( V_4 -> V_7 + V_8 ) ;
for ( V_39 = 0 ; V_39 < V_4 -> V_3 . V_46 ; V_39 ++ ) {
V_6 &= ~ ( 1 << F_29 ( V_39 ) ) ;
V_6 |= 1 << F_12 ( V_39 ) ;
}
F_6 ( V_6 , V_4 -> V_7 + V_8 ) ;
V_40 = F_30 ( & V_4 -> V_3 ) ;
if ( V_40 < 0 ) {
F_27 ( & V_36 -> V_41 , L_3 , V_40 ) ;
F_31 ( V_4 -> V_17 ) ;
}
return V_40 ;
}
static int F_32 ( struct V_35 * V_36 )
{
struct V_1 * V_4 = F_33 ( V_36 ) ;
F_31 ( V_4 -> V_17 ) ;
return F_34 ( & V_4 -> V_3 ) ;
}
