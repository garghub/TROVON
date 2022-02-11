static int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_4 , int V_5 )
{
int V_6 ;
V_6 = F_2 ( ( V_3 * V_4 ) , V_7 ) - 1 ;
F_3 ( & V_2 -> V_8 , L_1 , V_9 , V_6 ,
V_4 , V_3 ) ;
if ( V_6 < 0 )
V_6 = 0 ;
else if ( V_6 > V_5 )
V_6 = - V_10 ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , int V_11 )
{
struct V_12 * V_13 = F_5 ( V_2 ) ;
struct V_14 * V_15 = & V_13 -> V_16 [ V_11 ] ;
int V_17 , V_18 , V_19 , V_20 , V_21 , V_22 , V_23 ;
unsigned long V_24 = V_13 -> V_24 ;
unsigned V_25 ;
T_1 V_26 , V_27 ;
V_25 = V_28 + ( V_15 -> V_29 - V_13 -> V_30 ) * 4 ;
V_17 = F_1 ( V_2 , V_15 -> V_17 , V_24 , V_31 ) ;
V_18 = F_1 ( V_2 , V_15 -> V_18 , V_24 , V_32 ) ;
V_19 = F_1 ( V_2 , V_15 -> V_19 , V_24 , V_33 ) ;
V_20 = F_1 ( V_2 , V_15 -> V_20 , V_24 , V_34 ) ;
V_21 = F_1 ( V_2 , V_15 -> V_21 , V_24 , V_35 ) ;
V_22 = F_1 ( V_2 , V_15 -> V_22 , V_24 , V_36 ) ;
V_23 = F_1 ( V_2 , V_15 -> V_23 , V_24 , V_37 ) ;
if ( V_17 < 0 || V_18 < 0 || V_19 < 0 || V_20 < 0 ||
V_21 < 0 || V_22 < 0 || V_23 < 0 ) {
F_6 ( & V_2 -> V_8 , L_2 ,
V_9 ) ;
return - V_10 ;
}
V_26 = F_7 ( V_17 ) | F_8 ( V_18 ) | F_9 ( V_19 ) | F_10 ( V_20 ) |
F_11 ( V_21 ) | F_12 ( V_22 ) | F_13 ( V_23 ) ;
V_26 |= ( V_15 -> V_38 & V_39 ) ;
if ( V_15 -> V_40 )
V_26 |= V_41 ;
if ( V_15 -> V_42 )
V_26 |= V_43 ;
V_27 = F_14 ( V_13 -> V_44 + V_25 ) ;
V_27 &= ~ V_45 ;
V_27 |= V_26 ;
F_15 ( V_27 , V_13 -> V_44 + V_25 ) ;
return 0 ;
}
static inline int F_16 ( int V_27 , unsigned long V_24 )
{
return ( ( V_27 + 1 ) * V_7 ) / V_24 ;
}
static void F_17 ( struct V_1 * V_2 , int V_11 )
{
struct V_12 * V_13 = F_5 ( V_2 ) ;
struct V_14 * V_15 = & V_13 -> V_16 [ V_11 ] ;
unsigned long V_24 = V_13 -> V_24 ;
T_1 V_27 , V_25 ;
V_25 = V_28 + ( V_15 -> V_29 - V_13 -> V_30 ) * 4 ;
V_27 = F_14 ( V_13 -> V_44 + V_25 ) ;
V_15 -> V_17 = F_16 ( F_18 ( V_27 ) , V_24 ) ;
V_15 -> V_18 = F_16 ( F_19 ( V_27 ) , V_24 ) ;
V_15 -> V_19 = F_16 ( F_20 ( V_27 ) , V_24 ) ;
V_15 -> V_20 = F_16 ( F_21 ( V_27 ) , V_24 ) ;
V_15 -> V_21 = F_16 ( F_22 ( V_27 ) , V_24 ) ;
V_15 -> V_22 = F_16 ( F_23 ( V_27 ) , V_24 ) ;
V_15 -> V_23 = F_16 ( F_24 ( V_27 ) , V_24 ) ;
V_15 -> V_40 = F_25 ( V_27 ) ;
V_15 -> V_42 = F_26 ( V_27 ) ;
V_15 -> V_38 = V_27 & V_46 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_12 * V_13 = F_5 ( V_2 ) ;
struct V_14 * V_15 ;
T_1 V_29 ;
T_1 V_27 ;
if ( F_28 ( V_48 , L_3 , & V_29 ) ) {
F_3 ( & V_2 -> V_8 , L_4 ) ;
return - V_10 ;
}
if ( V_29 - V_13 -> V_30 >= V_49 || V_29 < V_13 -> V_30 ) {
F_3 ( & V_2 -> V_8 , L_5 , V_29 ) ;
return - V_10 ;
}
if ( V_13 -> V_50 >= V_49 ) {
F_3 ( & V_2 -> V_8 , L_6 , V_49 ) ;
return - V_10 ;
}
V_15 = & V_13 -> V_16 [ V_13 -> V_50 ] ;
V_15 -> V_29 = V_29 ;
F_17 ( V_2 , V_13 -> V_50 ++ ) ;
if ( ! F_28 ( V_48 , L_7 , & V_27 ) )
V_15 -> V_17 = V_27 ;
if ( ! F_28 ( V_48 , L_8 , & V_27 ) )
V_15 -> V_18 = V_27 ;
if ( ! F_28 ( V_48 , L_9 , & V_27 ) )
V_15 -> V_19 = V_27 ;
if ( ! F_28 ( V_48 , L_10 , & V_27 ) )
V_15 -> V_20 = V_27 ;
if ( ! F_28 ( V_48 , L_11 , & V_27 ) )
V_15 -> V_21 = V_27 ;
if ( ! F_28 ( V_48 , L_12 , & V_27 ) )
V_15 -> V_22 = V_27 ;
if ( ! F_28 ( V_48 , L_13 , & V_27 ) )
V_15 -> V_23 = V_27 ;
if ( ! F_28 ( V_48 , L_14 , & V_27 ) )
if ( V_27 == 16 )
V_15 -> V_38 = 1 ;
V_15 -> V_40 = F_29 ( V_48 , L_15 ) ;
V_15 -> V_42 = F_29 ( V_48 , L_16 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_51 ;
int V_52 = - V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_8 = & V_2 -> V_8 ;
struct V_47 * V_48 = V_8 -> V_57 ;
struct V_47 * V_58 ;
struct V_12 * V_13 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
if ( V_48 == NULL )
return 0 ;
V_13 = F_31 ( V_8 , sizeof( * V_13 ) , V_63 ) ;
if ( ! V_13 )
return - V_64 ;
V_60 = F_32 ( & V_2 -> V_8 ) ;
V_62 = V_60 ? V_60 -> V_62 : NULL ;
F_33 ( V_2 , V_13 ) ;
V_13 -> V_4 = F_34 ( V_8 , NULL ) ;
if ( F_35 ( V_13 -> V_4 ) ) {
F_6 ( V_8 , L_17 ) ;
return F_36 ( V_13 -> V_4 ) ;
}
F_37 ( V_13 -> V_4 ) ;
V_13 -> V_24 = F_38 ( V_13 -> V_4 ) / V_65 ;
if ( F_39 ( V_48 , L_18 ) )
V_13 -> V_30 = 2 ;
V_55 = F_40 ( V_2 , V_66 , 0 ) ;
V_13 -> V_44 = F_41 ( V_8 , V_55 ) ;
if ( F_35 ( V_13 -> V_44 ) ) {
V_52 = F_36 ( V_13 -> V_44 ) ;
goto error;
}
F_42 (np, child_np) {
V_52 = F_27 ( V_2 , V_58 ) ;
if ( V_52 < 0 )
goto error;
}
for ( V_51 = 0 ; V_51 < V_13 -> V_50 ; V_51 ++ ) {
V_52 = F_4 ( V_2 , V_51 ) ;
if ( V_52 < 0 ) {
F_6 ( V_8 , L_19 ,
V_13 -> V_16 [ V_51 ] . V_29 ) ;
goto error;
}
}
F_42 (np, child_np) {
V_52 = F_43 ( V_58 , NULL , V_62 , V_8 ) ;
if ( V_52 < 0 )
goto error;
}
return 0 ;
error:
F_44 ( V_13 -> V_4 ) ;
return V_52 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_5 ( V_2 ) ;
F_44 ( V_13 -> V_4 ) ;
return 0 ;
}
