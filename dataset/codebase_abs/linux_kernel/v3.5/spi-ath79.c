static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline struct V_1 * F_5 ( struct V_6 * V_7 )
{
return F_6 ( V_7 -> V_8 ) ;
}
static void F_7 ( struct V_6 * V_7 , int V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_10 = ( V_7 -> V_11 & V_12 ) ? V_9 : ! V_9 ;
if ( V_9 ) {
if ( V_7 -> V_11 & V_13 )
V_2 -> V_14 |= V_15 ;
else
V_2 -> V_14 &= ~ V_15 ;
F_3 ( V_2 , V_16 , V_2 -> V_14 ) ;
}
if ( V_7 -> V_17 ) {
struct V_18 * V_19 = V_7 -> V_20 ;
F_8 ( V_19 -> V_21 , V_10 ) ;
} else {
if ( V_10 )
V_2 -> V_14 |= V_22 ;
else
V_2 -> V_14 &= ~ V_22 ;
F_3 ( V_2 , V_16 , V_2 -> V_14 ) ;
}
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_18 * V_19 ;
V_19 = V_7 -> V_20 ;
if ( V_7 -> V_17 && ! V_19 )
return - V_23 ;
F_3 ( V_2 , V_24 , V_25 ) ;
V_2 -> V_26 = F_1 ( V_2 , V_27 ) ;
V_2 -> V_14 = F_1 ( V_2 , V_16 ) ;
F_3 ( V_2 , V_27 , 0x43 ) ;
if ( V_7 -> V_17 ) {
int V_28 = 0 ;
V_28 = F_10 ( V_19 -> V_21 , F_11 ( & V_7 -> V_29 ) ) ;
if ( V_28 )
return V_28 ;
V_28 = F_12 ( V_19 -> V_21 ,
V_7 -> V_11 & V_12 ) ;
if ( V_28 ) {
F_13 ( V_19 -> V_21 ) ;
return V_28 ;
}
} else {
if ( V_7 -> V_11 & V_12 )
V_2 -> V_14 |= V_22 ;
else
V_2 -> V_14 &= ~ V_22 ;
F_3 ( V_2 , V_16 , V_2 -> V_14 ) ;
}
return 0 ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
if ( V_7 -> V_17 ) {
struct V_18 * V_19 = V_7 -> V_20 ;
F_13 ( V_19 -> V_21 ) ;
}
F_3 ( V_2 , V_27 , V_2 -> V_26 ) ;
F_3 ( V_2 , V_24 , 0 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
int V_28 = 0 ;
if ( V_7 -> V_30 > 32 )
return - V_23 ;
if ( ! V_7 -> V_31 ) {
V_28 = F_9 ( V_7 ) ;
if ( V_28 )
return V_28 ;
}
V_28 = F_16 ( V_7 ) ;
if ( V_28 && ! V_7 -> V_31 )
F_14 ( V_7 ) ;
return V_28 ;
}
static void F_17 ( struct V_6 * V_7 )
{
F_14 ( V_7 ) ;
F_18 ( V_7 ) ;
}
static T_1 F_19 ( struct V_6 * V_7 , unsigned V_32 ,
T_1 V_33 , T_2 V_34 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
T_1 V_35 = V_2 -> V_14 ;
for ( V_33 <<= ( 32 - V_34 ) ; F_20 ( V_34 ) ; V_34 -- ) {
T_1 V_36 ;
if ( V_33 & ( 1 << 31 ) )
V_36 = V_35 | V_37 ;
else
V_36 = V_35 & ~ V_37 ;
F_3 ( V_2 , V_16 , V_36 ) ;
F_3 ( V_2 , V_16 , V_36 | V_15 ) ;
V_33 <<= 1 ;
}
return F_1 ( V_2 , V_38 ) ;
}
static T_3 int F_21 ( struct V_39 * V_40 )
{
struct V_41 * V_8 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_46 ;
V_8 = F_22 ( & V_40 -> V_29 , sizeof( * V_2 ) ) ;
if ( V_8 == NULL ) {
F_23 ( & V_40 -> V_29 , L_1 ) ;
return - V_47 ;
}
V_2 = F_6 ( V_8 ) ;
F_24 ( V_40 , V_2 ) ;
V_43 = V_40 -> V_29 . V_48 ;
V_8 -> V_49 = F_15 ;
V_8 -> V_50 = F_17 ;
if ( V_43 ) {
V_8 -> V_51 = V_43 -> V_51 ;
V_8 -> V_52 = V_43 -> V_52 ;
}
V_2 -> V_53 . V_8 = F_25 ( V_8 ) ;
V_2 -> V_53 . V_54 = F_7 ;
V_2 -> V_53 . V_55 [ V_56 ] = F_19 ;
V_2 -> V_53 . V_57 = V_58 ;
V_2 -> V_53 . V_59 = V_12 ;
V_45 = F_26 ( V_40 , V_60 , 0 ) ;
if ( V_45 == NULL ) {
V_46 = - V_61 ;
goto V_62;
}
V_2 -> V_4 = F_27 ( V_45 -> V_63 , F_28 ( V_45 ) ) ;
if ( ! V_2 -> V_4 ) {
V_46 = - V_64 ;
goto V_62;
}
V_46 = F_29 ( & V_2 -> V_53 ) ;
if ( V_46 )
goto V_65;
return 0 ;
V_65:
F_30 ( V_2 -> V_4 ) ;
V_62:
F_24 ( V_40 , NULL ) ;
F_31 ( V_2 -> V_53 . V_8 ) ;
return V_46 ;
}
static T_4 int F_32 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
F_34 ( & V_2 -> V_53 ) ;
F_30 ( V_2 -> V_4 ) ;
F_24 ( V_40 , NULL ) ;
F_31 ( V_2 -> V_53 . V_8 ) ;
return 0 ;
}
