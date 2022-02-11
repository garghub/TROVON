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
unsigned int V_16 = V_2 -> V_17 -> V_16 ;
if ( V_10 < V_2 -> V_18 ||
V_10 > V_2 -> V_19 ) {
F_8 ( V_3 -> V_20 , L_1 ) ;
return - V_21 ;
}
V_15 = F_9 ( V_2 -> V_22 ) ;
V_14 = F_10 ( V_23 , V_10 ) ;
V_13 = F_10 ( V_15 , V_14 ) ;
if ( V_13 <= V_16 ) {
div = V_24 ;
V_12 = F_10 ( V_13 , 1 ) ;
} else if ( V_13 <= V_16 * 8 ) {
div = V_25 ;
V_12 = F_10 ( V_13 , 8 ) ;
} else if ( V_13 <= V_16 * 64 ) {
div = V_26 ;
V_12 = F_10 ( V_13 , 64 ) ;
} else if ( V_13 <= V_16 * 512 ) {
div = V_27 ;
V_12 = F_10 ( V_13 , 512 ) ;
} else if ( V_13 > V_16 * 512 ) {
F_8 ( V_3 -> V_20 ,
L_2 ) ;
return - V_28 ;
}
V_11 = F_10 ( V_12 * V_9 , V_10 ) ;
V_5 = F_5 ( V_2 , V_29 ) ;
V_5 &= ~ ( V_30 << F_11 ( V_8 -> V_31 ) ) ;
V_5 |= ( div & V_30 ) <<
F_11 ( V_8 -> V_31 ) ;
F_3 ( V_2 , V_29 , V_5 ) ;
V_5 = ( V_11 << V_32 ) |
( V_12 << V_33 ) ;
F_3 ( V_2 , F_12 ( V_8 -> V_31 ) , V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
T_1 V_5 ;
struct V_1 * V_2 = F_1 ( V_3 ) ;
V_5 = F_5 ( V_2 , V_29 ) ;
V_5 |= F_14 ( V_8 -> V_31 ) ;
F_3 ( V_2 , V_29 , V_5 ) ;
F_15 ( V_2 -> V_34 , V_35 ,
V_36 <<
F_16 ( V_8 -> V_31 ) , 0 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
T_1 V_5 ;
struct V_1 * V_2 = F_1 ( V_3 ) ;
V_5 = F_5 ( V_2 , V_29 ) ;
V_5 &= ~ F_14 ( V_8 -> V_31 ) ;
F_3 ( V_2 , V_29 , V_5 ) ;
}
static int F_18 ( struct V_37 * V_38 )
{
int V_39 ;
T_2 V_5 ;
unsigned long V_40 ;
struct V_41 * V_42 ;
struct V_1 * V_8 ;
const struct V_43 * V_44 ;
V_8 = F_19 ( & V_38 -> V_20 , sizeof( * V_8 ) , V_45 ) ;
if ( ! V_8 )
return - V_46 ;
V_8 -> V_20 = & V_38 -> V_20 ;
V_42 = F_20 ( V_38 , V_47 , 0 ) ;
V_8 -> V_6 = F_21 ( & V_38 -> V_20 , V_42 ) ;
if ( F_22 ( V_8 -> V_6 ) )
return F_23 ( V_8 -> V_6 ) ;
V_44 = F_24 ( V_48 , & V_38 -> V_20 ) ;
if ( ! V_44 )
return - V_49 ;
V_8 -> V_17 = V_44 -> V_17 ;
V_8 -> V_34 = F_25 ( V_38 -> V_20 . V_50 ,
L_3 ) ;
if ( F_22 ( V_8 -> V_34 ) )
return F_23 ( V_8 -> V_34 ) ;
V_8 -> V_51 = F_26 ( & V_38 -> V_20 , L_4 ) ;
if ( F_22 ( V_8 -> V_51 ) ) {
F_8 ( & V_38 -> V_20 , L_5 ) ;
return F_23 ( V_8 -> V_51 ) ;
}
V_8 -> V_22 = F_26 ( & V_38 -> V_20 , L_6 ) ;
if ( F_22 ( V_8 -> V_22 ) ) {
F_8 ( & V_38 -> V_20 , L_7 ) ;
return F_23 ( V_8 -> V_22 ) ;
}
V_39 = F_27 ( V_8 -> V_51 ) ;
if ( V_39 < 0 ) {
F_8 ( & V_38 -> V_20 , L_8 ) ;
return V_39 ;
}
V_39 = F_27 ( V_8 -> V_22 ) ;
if ( V_39 < 0 ) {
F_8 ( & V_38 -> V_20 , L_9 ) ;
goto V_52;
}
V_40 = F_9 ( V_8 -> V_22 ) ;
if ( ! V_40 ) {
F_8 ( & V_38 -> V_20 , L_10 ) ;
V_39 = - V_28 ;
goto V_53;
}
V_5 = ( T_2 ) V_23 * 512 * V_8 -> V_17 -> V_16 ;
F_28 ( V_5 , V_40 ) ;
V_8 -> V_19 = V_5 ;
V_5 = ( T_2 ) V_23 * V_54 ;
F_28 ( V_5 , V_40 ) ;
V_8 -> V_18 = V_5 ;
V_8 -> V_3 . V_20 = & V_38 -> V_20 ;
V_8 -> V_3 . V_55 = & V_56 ;
V_8 -> V_3 . V_6 = - 1 ;
V_8 -> V_3 . V_57 = 4 ;
V_39 = F_29 ( & V_8 -> V_3 ) ;
if ( V_39 < 0 ) {
F_8 ( & V_38 -> V_20 , L_11 , V_39 ) ;
goto V_53;
}
F_30 ( V_38 , V_8 ) ;
return 0 ;
V_53:
F_31 ( V_8 -> V_22 ) ;
V_52:
F_31 ( V_8 -> V_51 ) ;
return V_39 ;
}
static int F_32 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_33 ( V_38 ) ;
T_1 V_5 ;
unsigned int V_58 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_3 . V_57 ; V_58 ++ ) {
V_5 = F_5 ( V_2 , V_29 ) ;
V_5 &= ~ F_14 ( V_58 ) ;
F_3 ( V_2 , V_29 , V_5 ) ;
}
F_31 ( V_2 -> V_22 ) ;
F_31 ( V_2 -> V_51 ) ;
return F_34 ( & V_2 -> V_3 ) ;
}
