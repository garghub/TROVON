static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 , bool V_6 )
{
int V_7 ;
T_1 V_8 = 1 << V_5 -> V_9 -> V_10 ;
T_1 V_11 = 0 ;
if ( ! ( V_5 -> V_9 -> V_12 & V_13 ) )
return 0 ;
if ( V_6 )
V_11 = V_8 ;
V_7 = F_4 ( V_5 -> V_14 ,
V_5 -> V_9 -> V_15 ,
V_8 , V_11 ) ;
if ( V_7 < 0 )
goto error;
V_7 = F_4 ( V_5 -> V_14 ,
V_5 -> V_9 -> V_16 ,
V_8 , V_11 ) ;
error:
if ( V_7 < 0 )
F_5 ( V_5 -> V_17 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_6 ( struct V_18 * V_19 )
{
struct V_1 * V_5 = F_7 ( V_19 ) ;
F_8 ( & V_5 -> V_20 ) ;
F_9 ( V_5 -> V_21 , V_5 -> V_22 + V_23 ) ;
F_10 ( & V_5 -> V_20 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_5 )
{
unsigned long V_24 ;
V_24 = F_12 ( V_5 -> V_22 + V_25 ) ;
V_24 &= ~ ( V_26 | V_27 ) ;
F_9 ( V_24 , V_5 -> V_22 + V_25 ) ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_1 * V_5 = F_7 ( V_19 ) ;
F_8 ( & V_5 -> V_20 ) ;
F_11 ( V_5 ) ;
F_10 ( & V_5 -> V_20 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_19 )
{
unsigned long V_24 ;
struct V_1 * V_5 = F_7 ( V_19 ) ;
F_8 ( & V_5 -> V_20 ) ;
F_11 ( V_5 ) ;
V_24 = F_12 ( V_5 -> V_22 + V_25 ) ;
V_24 |= V_26 | V_28 ;
if ( V_29 ) {
V_24 |= V_30 ;
V_24 &= ~ V_27 ;
} else {
V_24 &= ~ V_30 ;
V_24 |= V_27 ;
}
F_15 ( L_2 ,
V_31 , V_5 -> V_21 , V_24 ) ;
F_9 ( V_5 -> V_21 , V_5 -> V_22 + V_32 ) ;
F_9 ( V_5 -> V_21 , V_5 -> V_22 + V_23 ) ;
F_9 ( V_24 , V_5 -> V_22 + V_25 ) ;
F_10 ( & V_5 -> V_20 ) ;
return 0 ;
}
static inline int F_16 ( struct V_1 * V_5 )
{
return F_12 ( V_5 -> V_22 + V_25 ) & V_26 ;
}
static int F_17 ( struct V_18 * V_19 , unsigned V_33 )
{
struct V_1 * V_5 = F_7 ( V_19 ) ;
unsigned long V_34 = F_18 ( V_5 -> clock ) ;
unsigned int V_21 ;
unsigned int V_35 = 1 ;
unsigned long V_24 ;
if ( V_33 < 1 )
return - V_36 ;
V_34 = F_19 ( V_34 , 128 ) ;
V_21 = V_33 * V_34 ;
F_15 ( L_3 ,
V_31 , V_21 , V_33 , V_34 ) ;
if ( V_21 >= 0x10000 ) {
V_35 = F_19 ( V_21 , 0xffff ) ;
if ( V_35 > 0x100 ) {
F_5 ( V_5 -> V_17 , L_4 , V_33 ) ;
return - V_36 ;
}
}
F_15 ( L_5 ,
V_31 , V_33 , V_35 , V_21 , F_19 ( V_21 , V_35 ) ) ;
V_21 = F_19 ( V_21 , V_35 ) ;
V_5 -> V_21 = V_21 ;
V_24 = F_12 ( V_5 -> V_22 + V_25 ) ;
V_24 &= ~ V_37 ;
V_24 |= F_20 ( V_35 - 1 ) ;
F_9 ( V_21 , V_5 -> V_22 + V_32 ) ;
F_9 ( V_24 , V_5 -> V_22 + V_25 ) ;
V_19 -> V_33 = ( V_21 * V_35 ) / V_34 ;
return 0 ;
}
static T_2 F_21 ( int V_38 , void * V_39 )
{
struct V_1 * V_5 = F_22 ( V_39 ) ;
F_23 ( V_5 -> V_17 , L_6 ) ;
F_6 ( & V_5 -> V_40 ) ;
return V_41 ;
}
static int F_24 ( struct V_2 * V_3 ,
unsigned long V_11 , void * V_42 )
{
int V_7 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! F_16 ( V_5 ) )
goto V_43;
if ( V_11 == V_44 ) {
F_6 ( & V_5 -> V_40 ) ;
} else if ( V_11 == V_45 ) {
F_13 ( & V_5 -> V_40 ) ;
V_7 = F_17 ( & V_5 -> V_40 ,
V_5 -> V_40 . V_33 ) ;
if ( V_7 >= 0 )
F_14 ( & V_5 -> V_40 ) ;
else
goto V_46;
}
V_43:
return 0 ;
V_46:
F_5 ( V_5 -> V_17 , L_7 ,
V_5 -> V_40 . V_33 ) ;
return V_7 ;
}
static inline int F_25 ( struct V_1 * V_5 )
{
V_5 -> V_4 . V_47 = F_24 ;
return F_26 ( & V_5 -> V_4 ,
V_48 ) ;
}
static inline void F_27 ( struct V_1 * V_5 )
{
V_5 -> V_4 . V_47 = F_24 ;
F_28 ( & V_5 -> V_4 ,
V_48 ) ;
}
static inline int F_25 ( struct V_1 * V_5 )
{
return 0 ;
}
static inline void F_27 ( struct V_1 * V_5 )
{
}
static inline unsigned int F_29 ( struct V_1 * V_5 )
{
unsigned int V_49 ;
int V_7 ;
if ( ! ( V_5 -> V_9 -> V_12 & V_50 ) )
return 0 ;
V_7 = F_30 ( V_5 -> V_14 , V_5 -> V_9 -> V_51 , & V_49 ) ;
if ( V_7 )
F_31 ( V_5 -> V_17 , L_8 ) ;
else if ( V_49 & F_32 ( V_5 -> V_9 -> V_52 ) )
return V_53 ;
return 0 ;
}
static inline struct V_54 *
F_33 ( struct V_55 * V_56 )
{
if ( V_56 -> V_17 . V_57 ) {
const struct V_58 * V_59 ;
V_59 = F_34 ( V_60 , V_56 -> V_17 . V_57 ) ;
return (struct V_54 * ) V_59 -> V_42 ;
} else {
return (struct V_54 * )
F_35 ( V_56 ) -> V_61 ;
}
}
static int F_36 ( struct V_55 * V_56 )
{
struct V_62 * V_17 ;
struct V_1 * V_5 ;
struct V_63 * V_64 ;
struct V_63 * V_65 ;
unsigned int V_24 ;
int V_66 = 0 ;
int V_7 ;
F_15 ( L_9 , V_31 , V_56 ) ;
V_17 = & V_56 -> V_17 ;
V_5 = F_37 ( V_17 , sizeof( * V_5 ) , V_67 ) ;
if ( ! V_5 )
return - V_68 ;
V_5 -> V_17 = & V_56 -> V_17 ;
F_38 ( & V_5 -> V_20 ) ;
V_5 -> V_40 = V_69 ;
V_5 -> V_9 = F_33 ( V_56 ) ;
if ( V_5 -> V_9 -> V_12 & V_70 ) {
V_5 -> V_14 = F_39 ( V_17 -> V_57 ,
L_10 ) ;
if ( F_40 ( V_5 -> V_14 ) ) {
F_5 ( V_17 , L_11 ) ;
return F_41 ( V_5 -> V_14 ) ;
}
}
V_65 = F_42 ( V_56 , V_71 , 0 ) ;
if ( V_65 == NULL ) {
F_5 ( V_17 , L_12 ) ;
V_7 = - V_72 ;
goto V_46;
}
V_64 = F_42 ( V_56 , V_73 , 0 ) ;
V_5 -> V_22 = F_43 ( V_17 , V_64 ) ;
if ( F_40 ( V_5 -> V_22 ) ) {
V_7 = F_41 ( V_5 -> V_22 ) ;
goto V_46;
}
F_15 ( L_13 , V_5 -> V_22 ) ;
V_5 -> clock = F_44 ( V_17 , L_14 ) ;
if ( F_40 ( V_5 -> clock ) ) {
F_5 ( V_17 , L_15 ) ;
V_7 = F_41 ( V_5 -> clock ) ;
goto V_46;
}
F_45 ( V_5 -> clock ) ;
V_7 = F_25 ( V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_17 , L_16 ) ;
goto V_74;
}
F_46 ( & V_5 -> V_40 , V_5 ) ;
F_47 ( & V_5 -> V_40 , V_75 , & V_56 -> V_17 ) ;
V_7 = F_17 ( & V_5 -> V_40 ,
V_5 -> V_40 . V_33 ) ;
if ( V_7 ) {
V_66 = F_17 ( & V_5 -> V_40 ,
V_76 ) ;
if ( V_66 == 0 )
F_23 ( V_17 ,
L_17 ,
V_76 ) ;
else
F_23 ( V_17 , L_18
L_19 ) ;
}
V_7 = F_48 ( V_17 , V_65 -> V_77 , F_21 , 0 ,
V_56 -> V_78 , V_56 ) ;
if ( V_7 != 0 ) {
F_5 ( V_17 , L_20 , V_7 ) ;
goto V_79;
}
F_49 ( & V_5 -> V_40 , V_80 ) ;
V_5 -> V_40 . V_81 = F_29 ( V_5 ) ;
V_7 = F_50 ( & V_5 -> V_40 ) ;
if ( V_7 ) {
F_5 ( V_17 , L_21 , V_7 ) ;
goto V_79;
}
V_7 = F_3 ( V_5 , false ) ;
if ( V_7 < 0 )
goto V_82;
if ( V_83 && V_66 == 0 ) {
F_23 ( V_17 , L_22 ) ;
F_14 ( & V_5 -> V_40 ) ;
} else if ( ! V_83 ) {
F_13 ( & V_5 -> V_40 ) ;
}
F_51 ( V_56 , V_5 ) ;
V_24 = F_12 ( V_5 -> V_22 + V_25 ) ;
F_23 ( V_17 , L_23 ,
( V_24 & V_26 ) ? L_24 : L_25 ,
( V_24 & V_27 ) ? L_26 : L_27 ,
( V_24 & V_30 ) ? L_26 : L_27 ) ;
return 0 ;
V_82:
F_52 ( & V_5 -> V_40 ) ;
V_79:
F_27 ( V_5 ) ;
V_74:
F_53 ( V_5 -> clock ) ;
V_5 -> clock = NULL ;
V_46:
return V_7 ;
}
static int F_54 ( struct V_55 * V_17 )
{
int V_7 ;
struct V_1 * V_5 = F_22 ( V_17 ) ;
V_7 = F_3 ( V_5 , true ) ;
if ( V_7 < 0 )
return V_7 ;
F_52 ( & V_5 -> V_40 ) ;
F_27 ( V_5 ) ;
F_53 ( V_5 -> clock ) ;
V_5 -> clock = NULL ;
return 0 ;
}
static void F_55 ( struct V_55 * V_17 )
{
struct V_1 * V_5 = F_22 ( V_17 ) ;
F_3 ( V_5 , true ) ;
F_13 ( & V_5 -> V_40 ) ;
}
static int F_56 ( struct V_62 * V_17 )
{
int V_7 ;
struct V_1 * V_5 = F_57 ( V_17 ) ;
V_5 -> V_84 = F_12 ( V_5 -> V_22 + V_25 ) ;
V_5 -> V_85 = F_12 ( V_5 -> V_22 + V_32 ) ;
V_7 = F_3 ( V_5 , true ) ;
if ( V_7 < 0 )
return V_7 ;
F_13 ( & V_5 -> V_40 ) ;
return 0 ;
}
static int F_58 ( struct V_62 * V_17 )
{
int V_7 ;
struct V_1 * V_5 = F_57 ( V_17 ) ;
F_9 ( V_5 -> V_85 , V_5 -> V_22 + V_32 ) ;
F_9 ( V_5 -> V_85 , V_5 -> V_22 + V_23 ) ;
F_9 ( V_5 -> V_84 , V_5 -> V_22 + V_25 ) ;
V_7 = F_3 ( V_5 , false ) ;
if ( V_7 < 0 )
return V_7 ;
F_23 ( V_17 , L_28 ,
( V_5 -> V_84 & V_26 ) ? L_26 : L_27 ) ;
return 0 ;
}
