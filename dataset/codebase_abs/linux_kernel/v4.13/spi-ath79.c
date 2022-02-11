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
static inline void F_7 ( struct V_1 * V_2 , unsigned V_9 )
{
if ( V_9 > V_2 -> V_10 )
F_8 ( V_9 - V_2 -> V_10 ) ;
}
static void F_9 ( struct V_6 * V_7 , int V_11 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_12 = ( V_7 -> V_13 & V_14 ) ? V_11 : ! V_11 ;
if ( V_11 ) {
if ( V_7 -> V_13 & V_15 )
V_2 -> V_16 |= V_17 ;
else
V_2 -> V_16 &= ~ V_17 ;
F_3 ( V_2 , V_18 , V_2 -> V_16 ) ;
}
if ( F_10 ( V_7 -> V_19 ) ) {
F_11 ( V_7 -> V_19 , V_12 ) ;
} else {
T_1 V_20 = F_12 ( V_7 -> V_21 ) ;
if ( V_12 )
V_2 -> V_16 |= V_20 ;
else
V_2 -> V_16 &= ~ V_20 ;
F_3 ( V_2 , V_18 , V_2 -> V_16 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_22 , V_23 ) ;
V_2 -> V_24 = F_1 ( V_2 , V_25 ) ;
V_2 -> V_16 = F_1 ( V_2 , V_18 ) ;
F_3 ( V_2 , V_25 , 0x43 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_25 , V_2 -> V_24 ) ;
F_3 ( V_2 , V_22 , 0 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_26 ;
V_26 = 0 ;
if ( F_10 ( V_7 -> V_19 ) ) {
unsigned long V_27 ;
V_27 = V_28 ;
if ( V_7 -> V_13 & V_14 )
V_27 |= V_29 ;
else
V_27 |= V_30 ;
V_26 = F_16 ( V_7 -> V_19 , V_27 ,
F_17 ( & V_7 -> V_31 ) ) ;
} else {
T_1 V_20 = F_12 ( V_7 -> V_21 ) ;
if ( V_7 -> V_13 & V_14 )
V_2 -> V_16 &= ~ V_20 ;
else
V_2 -> V_16 |= V_20 ;
F_3 ( V_2 , V_18 , V_2 -> V_16 ) ;
}
return V_26 ;
}
static void F_18 ( struct V_6 * V_7 )
{
if ( F_10 ( V_7 -> V_19 ) ) {
F_19 ( V_7 -> V_19 ) ;
}
}
static int F_20 ( struct V_6 * V_7 )
{
int V_26 = 0 ;
if ( ! V_7 -> V_32 ) {
V_26 = F_15 ( V_7 ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_21 ( V_7 ) ;
if ( V_26 && ! V_7 -> V_32 )
F_18 ( V_7 ) ;
return V_26 ;
}
static void F_22 ( struct V_6 * V_7 )
{
F_18 ( V_7 ) ;
F_23 ( V_7 ) ;
}
static T_1 F_24 ( struct V_6 * V_7 , unsigned V_9 ,
T_1 V_33 , T_2 V_34 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
T_1 V_35 = V_2 -> V_16 ;
for ( V_33 <<= ( 32 - V_34 ) ; F_25 ( V_34 ) ; V_34 -- ) {
T_1 V_36 ;
if ( V_33 & ( 1 << 31 ) )
V_36 = V_35 | V_37 ;
else
V_36 = V_35 & ~ V_37 ;
F_3 ( V_2 , V_18 , V_36 ) ;
F_7 ( V_2 , V_9 ) ;
F_3 ( V_2 , V_18 , V_36 | V_17 ) ;
F_7 ( V_2 , V_9 ) ;
if ( V_34 == 1 )
F_3 ( V_2 , V_18 , V_36 ) ;
V_33 <<= 1 ;
}
return F_1 ( V_2 , V_38 ) ;
}
static int F_26 ( struct V_39 * V_40 )
{
struct V_41 * V_8 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
unsigned long V_46 ;
int V_47 ;
V_8 = F_27 ( & V_40 -> V_31 , sizeof( * V_2 ) ) ;
if ( V_8 == NULL ) {
F_28 ( & V_40 -> V_31 , L_1 ) ;
return - V_48 ;
}
V_2 = F_6 ( V_8 ) ;
V_8 -> V_31 . V_49 = V_40 -> V_31 . V_49 ;
F_29 ( V_40 , V_2 ) ;
V_43 = F_30 ( & V_40 -> V_31 ) ;
V_8 -> V_50 = F_31 ( 1 , 32 ) ;
V_8 -> V_51 = F_20 ;
V_8 -> V_52 = F_22 ;
if ( V_43 ) {
V_8 -> V_53 = V_43 -> V_53 ;
V_8 -> V_54 = V_43 -> V_54 ;
}
V_2 -> V_55 . V_8 = V_8 ;
V_2 -> V_55 . V_56 = F_9 ;
V_2 -> V_55 . V_57 [ V_58 ] = F_24 ;
V_2 -> V_55 . V_59 = V_60 ;
V_2 -> V_55 . V_27 = V_14 ;
V_45 = F_32 ( V_40 , V_61 , 0 ) ;
V_2 -> V_4 = F_33 ( & V_40 -> V_31 , V_45 ) ;
if ( F_34 ( V_2 -> V_4 ) ) {
V_47 = F_35 ( V_2 -> V_4 ) ;
goto V_62;
}
V_2 -> V_63 = F_36 ( & V_40 -> V_31 , L_2 ) ;
if ( F_34 ( V_2 -> V_63 ) ) {
V_47 = F_35 ( V_2 -> V_63 ) ;
goto V_62;
}
V_47 = F_37 ( V_2 -> V_63 ) ;
if ( V_47 )
goto V_62;
V_46 = F_38 ( F_39 ( V_2 -> V_63 ) , V_64 ) ;
if ( ! V_46 ) {
V_47 = - V_65 ;
goto V_66;
}
V_2 -> V_10 = V_67 / V_46 ;
F_40 ( & V_40 -> V_31 , L_3 ,
V_2 -> V_10 ) ;
F_13 ( V_2 ) ;
V_47 = F_41 ( & V_2 -> V_55 ) ;
if ( V_47 )
goto V_68;
return 0 ;
V_68:
F_14 ( V_2 ) ;
V_66:
F_42 ( V_2 -> V_63 ) ;
V_62:
F_43 ( V_2 -> V_55 . V_8 ) ;
return V_47 ;
}
static int F_44 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_45 ( V_40 ) ;
F_46 ( & V_2 -> V_55 ) ;
F_14 ( V_2 ) ;
F_42 ( V_2 -> V_63 ) ;
F_43 ( V_2 -> V_55 . V_8 ) ;
return 0 ;
}
static void F_47 ( struct V_39 * V_40 )
{
F_44 ( V_40 ) ;
}
