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
static int F_21 ( struct V_18 * V_19 )
{
struct V_1 * V_5 = F_7 ( V_19 ) ;
void T_2 * V_38 = V_5 -> V_22 ;
F_9 ( 0 , V_38 + V_25 ) ;
F_9 ( 0x80 , V_38 + V_23 ) ;
F_9 ( 0x80 , V_38 + V_32 ) ;
F_9 ( V_26 | V_39 |
V_27 | F_20 ( 0x20 ) ,
V_38 + V_25 ) ;
F_22 ( 500 ) ;
return 0 ;
}
static T_3 F_23 ( int V_40 , void * V_41 )
{
struct V_1 * V_5 = F_24 ( V_41 ) ;
F_25 ( V_5 -> V_17 , L_6 ) ;
F_6 ( & V_5 -> V_42 ) ;
return V_43 ;
}
static int F_26 ( struct V_2 * V_3 ,
unsigned long V_11 , void * V_44 )
{
int V_7 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! F_16 ( V_5 ) )
goto V_45;
if ( V_11 == V_46 ) {
F_6 ( & V_5 -> V_42 ) ;
} else if ( V_11 == V_47 ) {
F_13 ( & V_5 -> V_42 ) ;
V_7 = F_17 ( & V_5 -> V_42 ,
V_5 -> V_42 . V_33 ) ;
if ( V_7 >= 0 )
F_14 ( & V_5 -> V_42 ) ;
else
goto V_48;
}
V_45:
return 0 ;
V_48:
F_5 ( V_5 -> V_17 , L_7 ,
V_5 -> V_42 . V_33 ) ;
return V_7 ;
}
static inline int F_27 ( struct V_1 * V_5 )
{
V_5 -> V_4 . V_49 = F_26 ;
return F_28 ( & V_5 -> V_4 ,
V_50 ) ;
}
static inline void F_29 ( struct V_1 * V_5 )
{
V_5 -> V_4 . V_49 = F_26 ;
F_30 ( & V_5 -> V_4 ,
V_50 ) ;
}
static inline int F_27 ( struct V_1 * V_5 )
{
return 0 ;
}
static inline void F_29 ( struct V_1 * V_5 )
{
}
static inline unsigned int F_31 ( struct V_1 * V_5 )
{
unsigned int V_51 ;
int V_7 ;
if ( ! ( V_5 -> V_9 -> V_12 & V_52 ) )
return 0 ;
V_7 = F_32 ( V_5 -> V_14 , V_5 -> V_9 -> V_53 , & V_51 ) ;
if ( V_7 )
F_33 ( V_5 -> V_17 , L_8 ) ;
else if ( V_51 & F_34 ( V_5 -> V_9 -> V_54 ) )
return V_55 ;
return 0 ;
}
static inline struct V_56 *
F_35 ( struct V_57 * V_58 )
{
if ( V_58 -> V_17 . V_59 ) {
const struct V_60 * V_61 ;
V_61 = F_36 ( V_62 , V_58 -> V_17 . V_59 ) ;
return (struct V_56 * ) V_61 -> V_44 ;
} else {
return (struct V_56 * )
F_37 ( V_58 ) -> V_63 ;
}
}
static int F_38 ( struct V_57 * V_58 )
{
struct V_64 * V_17 ;
struct V_1 * V_5 ;
struct V_65 * V_66 ;
struct V_65 * V_67 ;
unsigned int V_24 ;
int V_68 = 0 ;
int V_7 ;
F_15 ( L_9 , V_31 , V_58 ) ;
V_17 = & V_58 -> V_17 ;
V_5 = F_39 ( V_17 , sizeof( * V_5 ) , V_69 ) ;
if ( ! V_5 )
return - V_70 ;
V_5 -> V_17 = & V_58 -> V_17 ;
F_40 ( & V_5 -> V_20 ) ;
V_5 -> V_42 = V_71 ;
V_5 -> V_9 = F_35 ( V_58 ) ;
if ( V_5 -> V_9 -> V_12 & V_72 ) {
V_5 -> V_14 = F_41 ( V_17 -> V_59 ,
L_10 ) ;
if ( F_42 ( V_5 -> V_14 ) ) {
F_5 ( V_17 , L_11 ) ;
return F_43 ( V_5 -> V_14 ) ;
}
}
V_67 = F_44 ( V_58 , V_73 , 0 ) ;
if ( V_67 == NULL ) {
F_5 ( V_17 , L_12 ) ;
V_7 = - V_74 ;
goto V_48;
}
V_66 = F_44 ( V_58 , V_75 , 0 ) ;
V_5 -> V_22 = F_45 ( V_17 , V_66 ) ;
if ( F_42 ( V_5 -> V_22 ) ) {
V_7 = F_43 ( V_5 -> V_22 ) ;
goto V_48;
}
F_15 ( L_13 , V_5 -> V_22 ) ;
V_5 -> clock = F_46 ( V_17 , L_14 ) ;
if ( F_42 ( V_5 -> clock ) ) {
F_5 ( V_17 , L_15 ) ;
V_7 = F_43 ( V_5 -> clock ) ;
goto V_48;
}
V_7 = F_47 ( V_5 -> clock ) ;
if ( V_7 < 0 ) {
F_5 ( V_17 , L_16 ) ;
return V_7 ;
}
V_7 = F_27 ( V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_17 , L_17 ) ;
goto V_76;
}
F_48 ( & V_5 -> V_42 , V_5 ) ;
F_49 ( & V_5 -> V_42 , V_77 , & V_58 -> V_17 ) ;
V_7 = F_17 ( & V_5 -> V_42 ,
V_5 -> V_42 . V_33 ) ;
if ( V_7 ) {
V_68 = F_17 ( & V_5 -> V_42 ,
V_78 ) ;
if ( V_68 == 0 )
F_25 ( V_17 ,
L_18 ,
V_78 ) ;
else
F_25 ( V_17 , L_19
L_20 ) ;
}
V_7 = F_50 ( V_17 , V_67 -> V_79 , F_23 , 0 ,
V_58 -> V_80 , V_58 ) ;
if ( V_7 != 0 ) {
F_5 ( V_17 , L_21 , V_7 ) ;
goto V_81;
}
F_51 ( & V_5 -> V_42 , V_82 ) ;
F_52 ( & V_5 -> V_42 , 128 ) ;
V_5 -> V_42 . V_83 = F_31 ( V_5 ) ;
V_5 -> V_42 . V_84 = & V_58 -> V_17 ;
V_7 = F_53 ( & V_5 -> V_42 ) ;
if ( V_7 ) {
F_5 ( V_17 , L_22 , V_7 ) ;
goto V_81;
}
V_7 = F_3 ( V_5 , false ) ;
if ( V_7 < 0 )
goto V_85;
if ( V_86 && V_68 == 0 ) {
F_25 ( V_17 , L_23 ) ;
F_14 ( & V_5 -> V_42 ) ;
} else if ( ! V_86 ) {
F_13 ( & V_5 -> V_42 ) ;
}
F_54 ( V_58 , V_5 ) ;
V_24 = F_12 ( V_5 -> V_22 + V_25 ) ;
F_25 ( V_17 , L_24 ,
( V_24 & V_26 ) ? L_25 : L_26 ,
( V_24 & V_27 ) ? L_27 : L_28 ,
( V_24 & V_30 ) ? L_27 : L_28 ) ;
return 0 ;
V_85:
F_55 ( & V_5 -> V_42 ) ;
V_81:
F_29 ( V_5 ) ;
V_76:
F_56 ( V_5 -> clock ) ;
V_48:
return V_7 ;
}
static int F_57 ( struct V_57 * V_17 )
{
int V_7 ;
struct V_1 * V_5 = F_24 ( V_17 ) ;
V_7 = F_3 ( V_5 , true ) ;
if ( V_7 < 0 )
return V_7 ;
F_55 ( & V_5 -> V_42 ) ;
F_29 ( V_5 ) ;
F_56 ( V_5 -> clock ) ;
return 0 ;
}
static void F_58 ( struct V_57 * V_17 )
{
struct V_1 * V_5 = F_24 ( V_17 ) ;
F_3 ( V_5 , true ) ;
F_13 ( & V_5 -> V_42 ) ;
}
static int F_59 ( struct V_64 * V_17 )
{
int V_7 ;
struct V_1 * V_5 = F_60 ( V_17 ) ;
V_5 -> V_87 = F_12 ( V_5 -> V_22 + V_25 ) ;
V_5 -> V_88 = F_12 ( V_5 -> V_22 + V_32 ) ;
V_7 = F_3 ( V_5 , true ) ;
if ( V_7 < 0 )
return V_7 ;
F_13 ( & V_5 -> V_42 ) ;
return 0 ;
}
static int F_61 ( struct V_64 * V_17 )
{
int V_7 ;
struct V_1 * V_5 = F_60 ( V_17 ) ;
F_9 ( V_5 -> V_88 , V_5 -> V_22 + V_32 ) ;
F_9 ( V_5 -> V_88 , V_5 -> V_22 + V_23 ) ;
F_9 ( V_5 -> V_87 , V_5 -> V_22 + V_25 ) ;
V_7 = F_3 ( V_5 , false ) ;
if ( V_7 < 0 )
return V_7 ;
F_25 ( V_17 , L_29 ,
( V_5 -> V_87 & V_26 ) ? L_27 : L_28 ) ;
return 0 ;
}
