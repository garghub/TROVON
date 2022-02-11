static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , unsigned int V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_2 -> V_7 + V_5 ) ;
V_6 = ( V_6 & ~ V_4 ) | V_3 ;
F_3 ( V_6 , V_2 -> V_7 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , unsigned int V_5 )
{
F_3 ( V_3 , V_2 -> V_7 + V_5 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , unsigned int V_5 )
{
return F_2 ( V_2 -> V_7 + V_5 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_3 ;
V_3 = F_5 ( V_2 , V_8 ) ;
F_4 ( V_2 , V_3 & ~ V_4 , V_8 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_3 ;
V_3 = F_5 ( V_2 , V_8 ) ;
F_4 ( V_2 , V_3 | V_4 , V_8 ) ;
}
static T_2 F_8 ( int V_9 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
T_3 V_11 = 0 ;
T_1 V_12 , V_13 , V_3 ;
F_9 ( V_14 ) ;
F_10 ( V_2 -> V_15 ) ;
V_14 . V_16 = false ;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
V_3 = F_5 ( V_2 , F_11 ( V_12 ) ) ;
F_12 ( V_2 -> V_18 , L_1 , V_12 , V_3 ) ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_11 = ( V_3 & ( V_19 << V_13 * 8 ) ) >> V_13 * 8 ;
V_14 . V_16 = ! V_14 . V_16 ;
V_14 . V_20 = V_11 * ( V_21 + 1 ) ;
F_13 ( V_2 -> V_15 , & V_14 ) ;
}
}
if ( ! F_14 ( V_11 , V_14 . V_16 ) ) {
V_14 . V_16 = false ;
V_14 . V_20 = V_22 * ( V_21 + 1 ) ;
F_13 ( V_2 -> V_15 , & V_14 ) ;
}
F_15 ( V_2 -> V_15 ) ;
F_1 ( V_2 , 0x1 , V_23 , V_24 ) ;
F_1 ( V_2 , 0x1 , V_25 , V_26 ) ;
return V_27 ;
}
static int F_16 ( struct V_28 * V_29 )
{
struct V_30 * V_18 = & V_29 -> V_18 ;
struct V_31 * V_32 = V_18 -> V_33 ;
struct V_34 * V_35 ;
struct V_1 * V_2 ;
T_1 V_3 ;
int V_36 = 0 ;
const char * V_37 ;
V_2 = F_17 ( V_18 , sizeof( struct V_1 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_2 -> V_18 = V_18 ;
if ( ! F_18 ( V_32 , L_2 ) )
return - V_40 ;
V_2 -> V_41 = F_19 ( V_18 , L_3 ) ;
if ( F_20 ( V_2 -> V_41 ) ) {
F_21 ( V_18 , L_4 ) ;
return F_22 ( V_2 -> V_41 ) ;
}
V_35 = F_23 ( V_29 , V_42 , 0 ) ;
V_2 -> V_7 = F_24 ( V_18 , V_35 ) ;
if ( F_20 ( V_2 -> V_7 ) ) {
F_21 ( V_18 , L_5 ) ;
return F_22 ( V_2 -> V_7 ) ;
}
V_2 -> V_15 = F_25 ( V_18 , V_43 ) ;
if ( ! V_2 -> V_15 ) {
F_21 ( V_18 , L_6 ) ;
return - V_39 ;
}
V_2 -> V_15 -> V_44 = V_2 ;
V_2 -> V_15 -> V_45 = V_46 ;
V_2 -> V_15 -> V_47 = V_46 L_7 ;
V_2 -> V_15 -> V_48 . V_49 = V_50 ;
V_2 -> V_15 -> V_48 . V_51 = 0x0001 ;
V_2 -> V_15 -> V_48 . V_52 = 0x0001 ;
V_2 -> V_15 -> V_48 . V_53 = 0x0001 ;
V_37 = F_26 ( V_32 , L_8 , NULL ) ;
V_2 -> V_15 -> V_37 = V_37 ? : V_54 ;
V_2 -> V_15 -> V_18 . V_55 = V_18 ;
V_2 -> V_15 -> V_56 = V_46 ;
V_2 -> V_15 -> V_57 = V_58 ;
V_2 -> V_15 -> V_59 = V_21 ;
V_2 -> V_15 -> V_60 = V_22 * ( V_21 + 1 ) ;
V_36 = F_27 ( V_18 , V_2 -> V_15 ) ;
if ( V_36 ) {
F_21 ( V_18 , L_9 ) ;
return V_36 ;
}
F_28 ( V_29 , V_2 ) ;
V_2 -> V_61 = F_29 ( V_29 , 0 ) ;
if ( V_2 -> V_61 < 0 ) {
F_21 ( V_18 , L_10 ) ;
return - V_40 ;
}
if ( F_30 ( V_2 -> V_41 ) ) {
F_21 ( V_18 , L_11 ) ;
V_36 = - V_62 ;
goto V_63;
}
F_6 ( V_2 , V_64 ) ;
V_36 = F_31 ( V_18 , V_2 -> V_61 , F_8 , 0 , V_46 , V_2 ) ;
if ( V_36 ) {
F_21 ( V_18 , L_12 ) ;
goto V_63;
}
V_3 = F_5 ( V_2 , V_65 ) ;
V_3 |= V_66 | V_67 ;
F_4 ( V_2 , V_3 , V_65 ) ;
F_1 ( V_2 , V_68 , V_69 ,
V_70 ) ;
F_7 ( V_2 , V_64 ) ;
F_32 ( V_18 , L_13 ,
F_33 ( V_21 , 1000 ) ) ;
return 0 ;
V_63:
F_34 ( V_2 -> V_41 ) ;
return V_36 ;
}
static int F_35 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_36 ( V_29 ) ;
F_6 ( V_2 , V_64 ) ;
F_37 ( V_2 -> V_61 ) ;
F_34 ( V_2 -> V_41 ) ;
return 0 ;
}
