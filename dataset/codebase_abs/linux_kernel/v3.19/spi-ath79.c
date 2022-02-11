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
if ( V_7 -> V_19 ) {
struct V_20 * V_21 = V_7 -> V_22 ;
F_10 ( V_21 -> V_23 , V_12 ) ;
} else {
if ( V_12 )
V_2 -> V_16 |= V_24 ;
else
V_2 -> V_16 &= ~ V_24 ;
F_3 ( V_2 , V_18 , V_2 -> V_16 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_25 , V_26 ) ;
V_2 -> V_27 = F_1 ( V_2 , V_28 ) ;
V_2 -> V_16 = F_1 ( V_2 , V_18 ) ;
F_3 ( V_2 , V_28 , 0x43 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_28 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_25 , 0 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_20 * V_21 ;
int V_29 ;
V_21 = V_7 -> V_22 ;
if ( V_7 -> V_19 && ! V_21 )
return - V_30 ;
V_29 = 0 ;
if ( V_7 -> V_19 ) {
unsigned long V_31 ;
V_31 = V_32 ;
if ( V_7 -> V_13 & V_14 )
V_31 |= V_33 ;
else
V_31 |= V_34 ;
V_29 = F_14 ( V_21 -> V_23 , V_31 ,
F_15 ( & V_7 -> V_35 ) ) ;
}
return V_29 ;
}
static void F_16 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 ) {
struct V_20 * V_21 = V_7 -> V_22 ;
F_17 ( V_21 -> V_23 ) ;
}
}
static int F_18 ( struct V_6 * V_7 )
{
int V_29 = 0 ;
if ( ! V_7 -> V_36 ) {
V_29 = F_13 ( V_7 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_19 ( V_7 ) ;
if ( V_29 && ! V_7 -> V_36 )
F_16 ( V_7 ) ;
return V_29 ;
}
static void F_20 ( struct V_6 * V_7 )
{
F_16 ( V_7 ) ;
F_21 ( V_7 ) ;
}
static T_1 F_22 ( struct V_6 * V_7 , unsigned V_9 ,
T_1 V_37 , T_2 V_38 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
T_1 V_39 = V_2 -> V_16 ;
for ( V_37 <<= ( 32 - V_38 ) ; F_23 ( V_38 ) ; V_38 -- ) {
T_1 V_40 ;
if ( V_37 & ( 1 << 31 ) )
V_40 = V_39 | V_41 ;
else
V_40 = V_39 & ~ V_41 ;
F_3 ( V_2 , V_18 , V_40 ) ;
F_7 ( V_2 , V_9 ) ;
F_3 ( V_2 , V_18 , V_40 | V_17 ) ;
F_7 ( V_2 , V_9 ) ;
if ( V_38 == 1 )
F_3 ( V_2 , V_18 , V_40 ) ;
V_37 <<= 1 ;
}
return F_1 ( V_2 , V_42 ) ;
}
static int F_24 ( struct V_43 * V_44 )
{
struct V_45 * V_8 ;
struct V_1 * V_2 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
unsigned long V_50 ;
int V_51 ;
V_8 = F_25 ( & V_44 -> V_35 , sizeof( * V_2 ) ) ;
if ( V_8 == NULL ) {
F_26 ( & V_44 -> V_35 , L_1 ) ;
return - V_52 ;
}
V_2 = F_6 ( V_8 ) ;
F_27 ( V_44 , V_2 ) ;
V_47 = F_28 ( & V_44 -> V_35 ) ;
V_8 -> V_53 = F_29 ( 1 , 32 ) ;
V_8 -> V_54 = F_18 ;
V_8 -> V_55 = F_20 ;
if ( V_47 ) {
V_8 -> V_56 = V_47 -> V_56 ;
V_8 -> V_57 = V_47 -> V_57 ;
}
V_2 -> V_58 . V_8 = V_8 ;
V_2 -> V_58 . V_59 = F_9 ;
V_2 -> V_58 . V_60 [ V_61 ] = F_22 ;
V_2 -> V_58 . V_62 = V_63 ;
V_2 -> V_58 . V_31 = V_14 ;
V_49 = F_30 ( V_44 , V_64 , 0 ) ;
if ( V_49 == NULL ) {
V_51 = - V_65 ;
goto V_66;
}
V_2 -> V_4 = F_31 ( & V_44 -> V_35 , V_49 -> V_67 , F_32 ( V_49 ) ) ;
if ( ! V_2 -> V_4 ) {
V_51 = - V_68 ;
goto V_66;
}
V_2 -> V_69 = F_33 ( & V_44 -> V_35 , L_2 ) ;
if ( F_34 ( V_2 -> V_69 ) ) {
V_51 = F_35 ( V_2 -> V_69 ) ;
goto V_66;
}
V_51 = F_36 ( V_2 -> V_69 ) ;
if ( V_51 )
goto V_66;
V_50 = F_37 ( F_38 ( V_2 -> V_69 ) , V_70 ) ;
if ( ! V_50 ) {
V_51 = - V_30 ;
goto V_71;
}
V_2 -> V_10 = V_72 / V_50 ;
F_39 ( & V_44 -> V_35 , L_3 ,
V_2 -> V_10 ) ;
F_11 ( V_2 ) ;
V_51 = F_40 ( & V_2 -> V_58 ) ;
if ( V_51 )
goto V_73;
return 0 ;
V_73:
F_12 ( V_2 ) ;
V_71:
F_41 ( V_2 -> V_69 ) ;
V_66:
F_42 ( V_2 -> V_58 . V_8 ) ;
return V_51 ;
}
static int F_43 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_44 ( V_44 ) ;
F_45 ( & V_2 -> V_58 ) ;
F_12 ( V_2 ) ;
F_41 ( V_2 -> V_69 ) ;
F_42 ( V_2 -> V_58 . V_8 ) ;
return 0 ;
}
static void F_46 ( struct V_43 * V_44 )
{
F_43 ( V_44 ) ;
}
