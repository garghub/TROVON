static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_6 + ( V_2 -> V_7 * V_8 ) ;
}
static void F_2 ( void T_1 * V_9 , T_2 V_10 , T_2 V_11 ,
T_2 V_12 , T_2 V_13 )
{
T_2 V_14 ;
F_3 ( V_10 , V_9 + V_15 ) ;
V_14 = F_4 ( V_9 + F_5 ( V_11 ) ) ;
V_14 = ( V_14 & V_12 ) | V_13 ;
F_3 ( V_14 , V_9 + F_5 ( V_11 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
void T_1 * V_16 = F_1 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_14 ;
V_14 = V_17 | V_18 ;
F_2 ( V_16 , V_19 , V_20 , ~ V_14 , V_14 ) ;
F_2 ( V_16 , V_19 , V_21 ,
~ V_22 ,
V_23 ) ;
if ( V_2 -> V_24 ) {
F_7 ( V_4 -> V_25 , L_1 , V_2 -> V_7 ) ;
V_14 = V_26 ;
} else {
V_14 = V_27 ;
}
F_2 ( V_16 , V_19 , V_28 ,
~ V_29 , V_14 ) ;
}
static int F_8 ( struct V_30 * V_30 )
{
struct V_1 * V_2 = F_9 ( V_30 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_31 * V_32 )
{
struct V_33 * V_25 = & V_32 -> V_25 ;
struct V_34 * V_35 = V_25 -> V_36 , * V_37 ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
int V_42 = 0 ;
if ( F_11 ( V_35 ) == 0 )
return - V_43 ;
V_4 = F_12 ( V_25 , sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
F_13 ( V_25 , V_4 ) ;
V_4 -> V_25 = V_25 ;
V_39 = F_14 ( V_32 , V_46 , L_2 ) ;
V_4 -> V_6 = F_15 ( V_25 , V_39 ) ;
if ( F_16 ( V_4 -> V_6 ) )
return F_17 ( V_4 -> V_6 ) ;
F_18 (dn, child) {
unsigned int V_47 ;
struct V_1 * V_2 ;
if ( F_19 ( V_37 , L_3 , & V_47 ) ) {
F_20 ( V_25 , L_4 ,
V_37 -> V_48 ) ;
return - V_49 ;
}
if ( V_47 >= V_50 ) {
F_20 ( V_25 , L_5 , V_47 ) ;
return - V_49 ;
}
if ( V_4 -> V_51 [ V_47 ] . V_30 ) {
F_20 ( V_25 , L_6 , V_47 ) ;
return - V_49 ;
}
V_2 = & V_4 -> V_51 [ V_47 ] ;
V_2 -> V_7 = V_47 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_30 = F_21 ( V_25 , V_37 , & V_52 ) ;
V_2 -> V_24 = F_22 ( V_37 , L_7 ) ;
if ( F_16 ( V_2 -> V_30 ) ) {
F_20 ( V_25 , L_8 ) ;
return F_17 ( V_2 -> V_30 ) ;
}
F_23 ( V_2 -> V_30 , V_2 ) ;
V_42 ++ ;
}
V_41 = F_24 ( V_25 , V_53 ) ;
if ( F_16 ( V_41 ) ) {
F_20 ( V_25 , L_9 ) ;
return F_17 ( V_41 ) ;
}
F_7 ( V_25 , L_10 , V_42 ) ;
return 0 ;
}
