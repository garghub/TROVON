static inline unsigned int F_1 ( struct V_1 * clock )
{
unsigned long V_2 = F_2 ( clock ) ;
return V_3 / ( V_2 / ( V_4 + 1 )
/ V_5 ) ;
}
static inline struct V_6 * F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 , struct V_6 , V_9 ) ;
}
static int F_5 ( struct V_6 * V_10 , bool V_11 )
{
int V_12 ;
T_1 V_13 = 1 << V_10 -> V_14 -> V_15 ;
T_1 V_16 = 0 ;
if ( ! ( V_10 -> V_14 -> V_17 & V_18 ) )
return 0 ;
if ( V_11 )
V_16 = V_13 ;
V_12 = F_6 ( V_10 -> V_19 ,
V_10 -> V_14 -> V_20 ,
V_13 , V_16 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_6 ( V_10 -> V_19 ,
V_10 -> V_14 -> V_21 ,
V_13 , V_16 ) ;
error:
if ( V_12 < 0 )
F_7 ( V_10 -> V_22 , L_1 , V_12 ) ;
return V_12 ;
}
static int F_8 ( struct V_23 * V_24 )
{
struct V_6 * V_10 = F_9 ( V_24 ) ;
F_10 ( & V_10 -> V_25 ) ;
F_11 ( V_10 -> V_26 , V_10 -> V_27 + V_28 ) ;
F_12 ( & V_10 -> V_25 ) ;
return 0 ;
}
static void F_13 ( struct V_6 * V_10 )
{
unsigned long V_29 ;
V_29 = F_14 ( V_10 -> V_27 + V_30 ) ;
V_29 &= ~ ( V_31 | V_32 ) ;
F_11 ( V_29 , V_10 -> V_27 + V_30 ) ;
}
static int F_15 ( struct V_23 * V_24 )
{
struct V_6 * V_10 = F_9 ( V_24 ) ;
F_10 ( & V_10 -> V_25 ) ;
F_13 ( V_10 ) ;
F_12 ( & V_10 -> V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_23 * V_24 )
{
unsigned long V_29 ;
struct V_6 * V_10 = F_9 ( V_24 ) ;
F_10 ( & V_10 -> V_25 ) ;
F_13 ( V_10 ) ;
V_29 = F_14 ( V_10 -> V_27 + V_30 ) ;
V_29 |= V_31 | V_33 ;
if ( V_34 ) {
V_29 |= V_35 ;
V_29 &= ~ V_32 ;
} else {
V_29 &= ~ V_35 ;
V_29 |= V_32 ;
}
F_17 ( V_10 -> V_22 , L_2 ,
V_10 -> V_26 , V_29 ) ;
F_11 ( V_10 -> V_26 , V_10 -> V_27 + V_36 ) ;
F_11 ( V_10 -> V_26 , V_10 -> V_27 + V_28 ) ;
F_11 ( V_29 , V_10 -> V_27 + V_30 ) ;
F_12 ( & V_10 -> V_25 ) ;
return 0 ;
}
static inline int F_18 ( struct V_6 * V_10 )
{
return F_14 ( V_10 -> V_27 + V_30 ) & V_31 ;
}
static int F_19 ( struct V_23 * V_24 , unsigned V_37 )
{
struct V_6 * V_10 = F_9 ( V_24 ) ;
unsigned long V_2 = F_2 ( V_10 -> clock ) ;
unsigned int V_26 ;
unsigned int V_38 = 1 ;
unsigned long V_29 ;
if ( V_37 < 1 )
return - V_39 ;
V_2 = F_20 ( V_2 , 128 ) ;
V_26 = V_37 * V_2 ;
F_17 ( V_10 -> V_22 , L_3 ,
V_26 , V_37 , V_2 ) ;
if ( V_26 >= 0x10000 ) {
V_38 = F_20 ( V_26 , 0xffff ) ;
if ( V_38 > 0x100 ) {
F_7 ( V_10 -> V_22 , L_4 , V_37 ) ;
return - V_39 ;
}
}
F_17 ( V_10 -> V_22 , L_5 ,
V_37 , V_38 , V_26 , F_20 ( V_26 , V_38 ) ) ;
V_26 = F_20 ( V_26 , V_38 ) ;
V_10 -> V_26 = V_26 ;
V_29 = F_14 ( V_10 -> V_27 + V_30 ) ;
V_29 &= ~ V_40 ;
V_29 |= F_21 ( V_38 - 1 ) ;
F_11 ( V_26 , V_10 -> V_27 + V_36 ) ;
F_11 ( V_29 , V_10 -> V_27 + V_30 ) ;
V_24 -> V_37 = ( V_26 * V_38 ) / V_2 ;
return 0 ;
}
static int F_22 ( struct V_23 * V_24 , unsigned long V_41 ,
void * V_42 )
{
struct V_6 * V_10 = F_9 ( V_24 ) ;
void T_2 * V_43 = V_10 -> V_27 ;
F_11 ( 0 , V_43 + V_30 ) ;
F_11 ( 0x80 , V_43 + V_28 ) ;
F_11 ( 0x80 , V_43 + V_36 ) ;
F_11 ( V_31 | V_44 |
V_32 | F_21 ( 0x20 ) ,
V_43 + V_30 ) ;
F_23 ( 500 ) ;
return 0 ;
}
static T_3 F_24 ( int V_45 , void * V_46 )
{
struct V_6 * V_10 = F_25 ( V_46 ) ;
F_26 ( V_10 -> V_22 , L_6 ) ;
F_8 ( & V_10 -> V_47 ) ;
if ( V_10 -> V_14 -> V_17 & V_48 )
F_11 ( 0x1 , V_10 -> V_27 + V_49 ) ;
return V_50 ;
}
static int F_27 ( struct V_7 * V_8 ,
unsigned long V_16 , void * V_42 )
{
int V_12 ;
struct V_6 * V_10 = F_3 ( V_8 ) ;
if ( ! F_18 ( V_10 ) )
goto V_51;
if ( V_16 == V_52 ) {
F_8 ( & V_10 -> V_47 ) ;
} else if ( V_16 == V_53 ) {
F_15 ( & V_10 -> V_47 ) ;
V_12 = F_19 ( & V_10 -> V_47 ,
V_10 -> V_47 . V_37 ) ;
if ( V_12 >= 0 )
F_16 ( & V_10 -> V_47 ) ;
else
goto V_54;
}
V_51:
return 0 ;
V_54:
F_7 ( V_10 -> V_22 , L_7 ,
V_10 -> V_47 . V_37 ) ;
return V_12 ;
}
static inline int F_28 ( struct V_6 * V_10 )
{
V_10 -> V_9 . V_55 = F_27 ;
return F_29 ( & V_10 -> V_9 ,
V_56 ) ;
}
static inline void F_30 ( struct V_6 * V_10 )
{
V_10 -> V_9 . V_55 = F_27 ;
F_31 ( & V_10 -> V_9 ,
V_56 ) ;
}
static inline int F_28 ( struct V_6 * V_10 )
{
return 0 ;
}
static inline void F_30 ( struct V_6 * V_10 )
{
}
static inline unsigned int F_32 ( struct V_6 * V_10 )
{
unsigned int V_57 ;
int V_12 ;
if ( ! ( V_10 -> V_14 -> V_17 & V_58 ) )
return 0 ;
V_12 = F_33 ( V_10 -> V_19 , V_10 -> V_14 -> V_59 , & V_57 ) ;
if ( V_12 )
F_34 ( V_10 -> V_22 , L_8 ) ;
else if ( V_57 & F_35 ( V_10 -> V_14 -> V_60 ) )
return V_61 ;
return 0 ;
}
static inline struct V_62 *
F_36 ( struct V_63 * V_64 )
{
if ( V_64 -> V_22 . V_65 ) {
const struct V_66 * V_67 ;
V_67 = F_37 ( V_68 , V_64 -> V_22 . V_65 ) ;
return (struct V_62 * ) V_67 -> V_42 ;
} else {
return (struct V_62 * )
F_38 ( V_64 ) -> V_69 ;
}
}
static int F_39 ( struct V_63 * V_64 )
{
struct V_70 * V_22 ;
struct V_6 * V_10 ;
struct V_71 * V_72 ;
struct V_71 * V_73 ;
unsigned int V_29 ;
int V_74 = 0 ;
int V_12 ;
V_22 = & V_64 -> V_22 ;
V_10 = F_40 ( V_22 , sizeof( * V_10 ) , V_75 ) ;
if ( ! V_10 )
return - V_76 ;
V_10 -> V_22 = & V_64 -> V_22 ;
F_41 ( & V_10 -> V_25 ) ;
V_10 -> V_47 = V_77 ;
V_10 -> V_14 = F_36 ( V_64 ) ;
if ( V_10 -> V_14 -> V_17 & V_78 ) {
V_10 -> V_19 = F_42 ( V_22 -> V_65 ,
L_9 ) ;
if ( F_43 ( V_10 -> V_19 ) ) {
F_7 ( V_22 , L_10 ) ;
return F_44 ( V_10 -> V_19 ) ;
}
}
V_73 = F_45 ( V_64 , V_79 , 0 ) ;
if ( V_73 == NULL ) {
F_7 ( V_22 , L_11 ) ;
V_12 = - V_80 ;
goto V_54;
}
V_72 = F_45 ( V_64 , V_81 , 0 ) ;
V_10 -> V_27 = F_46 ( V_22 , V_72 ) ;
if ( F_43 ( V_10 -> V_27 ) ) {
V_12 = F_44 ( V_10 -> V_27 ) ;
goto V_54;
}
V_10 -> clock = F_47 ( V_22 , L_12 ) ;
if ( F_43 ( V_10 -> clock ) ) {
F_7 ( V_22 , L_13 ) ;
V_12 = F_44 ( V_10 -> clock ) ;
goto V_54;
}
V_12 = F_48 ( V_10 -> clock ) ;
if ( V_12 < 0 ) {
F_7 ( V_22 , L_14 ) ;
return V_12 ;
}
V_10 -> V_47 . V_82 = 1 ;
V_10 -> V_47 . V_83 = F_1 ( V_10 -> clock ) ;
V_12 = F_28 ( V_10 ) ;
if ( V_12 < 0 ) {
F_7 ( V_22 , L_15 ) ;
goto V_84;
}
F_49 ( & V_10 -> V_47 , V_10 ) ;
F_50 ( & V_10 -> V_47 , V_85 , & V_64 -> V_22 ) ;
V_12 = F_19 ( & V_10 -> V_47 ,
V_10 -> V_47 . V_37 ) ;
if ( V_12 ) {
V_74 = F_19 ( & V_10 -> V_47 ,
V_86 ) ;
if ( V_74 == 0 )
F_26 ( V_22 ,
L_16 ,
V_86 ) ;
else
F_26 ( V_22 , L_17
L_18 ) ;
}
V_12 = F_51 ( V_22 , V_73 -> V_87 , F_24 , 0 ,
V_64 -> V_88 , V_64 ) ;
if ( V_12 != 0 ) {
F_7 ( V_22 , L_19 , V_12 ) ;
goto V_89;
}
F_52 ( & V_10 -> V_47 , V_90 ) ;
F_53 ( & V_10 -> V_47 , 128 ) ;
V_10 -> V_47 . V_91 = F_32 ( V_10 ) ;
V_10 -> V_47 . V_92 = & V_64 -> V_22 ;
V_12 = F_54 ( & V_10 -> V_47 ) ;
if ( V_12 ) {
F_7 ( V_22 , L_20 , V_12 ) ;
goto V_89;
}
V_12 = F_5 ( V_10 , false ) ;
if ( V_12 < 0 )
goto V_93;
if ( V_94 && V_74 == 0 ) {
F_26 ( V_22 , L_21 ) ;
F_16 ( & V_10 -> V_47 ) ;
} else if ( ! V_94 ) {
F_15 ( & V_10 -> V_47 ) ;
}
F_55 ( V_64 , V_10 ) ;
V_29 = F_14 ( V_10 -> V_27 + V_30 ) ;
F_26 ( V_22 , L_22 ,
( V_29 & V_31 ) ? L_23 : L_24 ,
( V_29 & V_32 ) ? L_25 : L_26 ,
( V_29 & V_35 ) ? L_25 : L_26 ) ;
return 0 ;
V_93:
F_56 ( & V_10 -> V_47 ) ;
V_89:
F_30 ( V_10 ) ;
V_84:
F_57 ( V_10 -> clock ) ;
V_54:
return V_12 ;
}
static int F_58 ( struct V_63 * V_22 )
{
int V_12 ;
struct V_6 * V_10 = F_25 ( V_22 ) ;
V_12 = F_5 ( V_10 , true ) ;
if ( V_12 < 0 )
return V_12 ;
F_56 ( & V_10 -> V_47 ) ;
F_30 ( V_10 ) ;
F_57 ( V_10 -> clock ) ;
return 0 ;
}
static void F_59 ( struct V_63 * V_22 )
{
struct V_6 * V_10 = F_25 ( V_22 ) ;
F_5 ( V_10 , true ) ;
F_15 ( & V_10 -> V_47 ) ;
}
static int F_60 ( struct V_70 * V_22 )
{
int V_12 ;
struct V_6 * V_10 = F_61 ( V_22 ) ;
V_10 -> V_95 = F_14 ( V_10 -> V_27 + V_30 ) ;
V_10 -> V_96 = F_14 ( V_10 -> V_27 + V_36 ) ;
V_12 = F_5 ( V_10 , true ) ;
if ( V_12 < 0 )
return V_12 ;
F_15 ( & V_10 -> V_47 ) ;
return 0 ;
}
static int F_62 ( struct V_70 * V_22 )
{
int V_12 ;
struct V_6 * V_10 = F_61 ( V_22 ) ;
F_11 ( V_10 -> V_96 , V_10 -> V_27 + V_36 ) ;
F_11 ( V_10 -> V_96 , V_10 -> V_27 + V_28 ) ;
F_11 ( V_10 -> V_95 , V_10 -> V_27 + V_30 ) ;
V_12 = F_5 ( V_10 , false ) ;
if ( V_12 < 0 )
return V_12 ;
F_26 ( V_22 , L_27 ,
( V_10 -> V_95 & V_31 ) ? L_25 : L_26 ) ;
return 0 ;
}
