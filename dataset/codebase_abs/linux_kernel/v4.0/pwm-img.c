static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_3 ,
T_1 V_4 , T_1 V_5 )
{
F_4 ( V_5 , V_3 -> V_6 + V_4 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_3 ,
T_1 V_4 )
{
return F_6 ( V_3 -> V_6 + V_4 ) ;
}
static int F_7 ( struct V_2 * V_3 , struct V_7 * V_8 ,
int V_9 , int V_10 )
{
T_1 V_5 , div , V_11 , V_12 ;
unsigned long V_13 , V_14 , V_15 ;
struct V_1 * V_2 = F_1 ( V_3 ) ;
V_15 = F_8 ( V_2 -> V_16 ) ;
V_14 = F_9 ( V_17 , V_10 ) ;
V_13 = F_9 ( V_15 , V_14 ) ;
if ( V_13 <= V_18 ) {
div = V_19 ;
V_12 = F_9 ( V_13 , 1 ) ;
} else if ( V_13 <= V_18 * 8 ) {
div = V_20 ;
V_12 = F_9 ( V_13 , 8 ) ;
} else if ( V_13 <= V_18 * 64 ) {
div = V_21 ;
V_12 = F_9 ( V_13 , 64 ) ;
} else if ( V_13 <= V_18 * 512 ) {
div = V_22 ;
V_12 = F_9 ( V_13 , 512 ) ;
} else if ( V_13 > V_18 * 512 ) {
F_10 ( V_3 -> V_23 ,
L_1 ) ;
return - V_24 ;
}
V_11 = F_9 ( V_12 * V_9 , V_10 ) ;
V_5 = F_5 ( V_2 , V_25 ) ;
V_5 &= ~ ( V_26 << F_11 ( V_8 -> V_27 ) ) ;
V_5 |= ( div & V_26 ) <<
F_11 ( V_8 -> V_27 ) ;
F_3 ( V_2 , V_25 , V_5 ) ;
V_5 = ( V_11 << V_28 ) |
( V_12 << V_29 ) ;
F_3 ( V_2 , F_12 ( V_8 -> V_27 ) , V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
T_1 V_5 ;
struct V_1 * V_2 = F_1 ( V_3 ) ;
V_5 = F_5 ( V_2 , V_25 ) ;
V_5 |= F_14 ( V_8 -> V_27 ) ;
F_3 ( V_2 , V_25 , V_5 ) ;
F_15 ( V_2 -> V_30 , V_31 ,
V_32 <<
F_16 ( V_8 -> V_27 ) , 0 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
T_1 V_5 ;
struct V_1 * V_2 = F_1 ( V_3 ) ;
V_5 = F_5 ( V_2 , V_25 ) ;
V_5 &= ~ F_14 ( V_8 -> V_27 ) ;
F_3 ( V_2 , V_25 , V_5 ) ;
}
static int F_18 ( struct V_33 * V_34 )
{
int V_35 ;
struct V_36 * V_37 ;
struct V_1 * V_8 ;
V_8 = F_19 ( & V_34 -> V_23 , sizeof( * V_8 ) , V_38 ) ;
if ( ! V_8 )
return - V_39 ;
V_8 -> V_23 = & V_34 -> V_23 ;
V_37 = F_20 ( V_34 , V_40 , 0 ) ;
V_8 -> V_6 = F_21 ( & V_34 -> V_23 , V_37 ) ;
if ( F_22 ( V_8 -> V_6 ) )
return F_23 ( V_8 -> V_6 ) ;
V_8 -> V_30 = F_24 ( V_34 -> V_23 . V_41 ,
L_2 ) ;
if ( F_22 ( V_8 -> V_30 ) )
return F_23 ( V_8 -> V_30 ) ;
V_8 -> V_42 = F_25 ( & V_34 -> V_23 , L_3 ) ;
if ( F_22 ( V_8 -> V_42 ) ) {
F_10 ( & V_34 -> V_23 , L_4 ) ;
return F_23 ( V_8 -> V_42 ) ;
}
V_8 -> V_16 = F_25 ( & V_34 -> V_23 , L_5 ) ;
if ( F_22 ( V_8 -> V_16 ) ) {
F_10 ( & V_34 -> V_23 , L_6 ) ;
return F_23 ( V_8 -> V_16 ) ;
}
V_35 = F_26 ( V_8 -> V_42 ) ;
if ( V_35 < 0 ) {
F_10 ( & V_34 -> V_23 , L_7 ) ;
return V_35 ;
}
V_35 = F_26 ( V_8 -> V_16 ) ;
if ( V_35 < 0 ) {
F_10 ( & V_34 -> V_23 , L_8 ) ;
goto V_43;
}
V_8 -> V_3 . V_23 = & V_34 -> V_23 ;
V_8 -> V_3 . V_44 = & V_45 ;
V_8 -> V_3 . V_6 = - 1 ;
V_8 -> V_3 . V_46 = 4 ;
V_35 = F_27 ( & V_8 -> V_3 ) ;
if ( V_35 < 0 ) {
F_10 ( & V_34 -> V_23 , L_9 , V_35 ) ;
goto V_47;
}
F_28 ( V_34 , V_8 ) ;
return 0 ;
V_47:
F_29 ( V_8 -> V_16 ) ;
V_43:
F_29 ( V_8 -> V_42 ) ;
return V_35 ;
}
static int F_30 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_31 ( V_34 ) ;
T_1 V_5 ;
unsigned int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_3 . V_46 ; V_48 ++ ) {
V_5 = F_5 ( V_2 , V_25 ) ;
V_5 &= ~ F_14 ( V_48 ) ;
F_3 ( V_2 , V_25 , V_5 ) ;
}
F_29 ( V_2 -> V_16 ) ;
F_29 ( V_2 -> V_42 ) ;
return F_32 ( & V_2 -> V_3 ) ;
}
