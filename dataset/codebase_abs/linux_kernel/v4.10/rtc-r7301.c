static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned int V_6 ;
F_3 ( V_2 -> V_5 , V_4 * V_3 , & V_6 ) ;
return V_6 & 0xf ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_6 , unsigned int V_3 )
{
int V_4 = F_2 ( V_2 -> V_5 ) ;
F_5 ( V_2 -> V_5 , V_4 * V_3 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_7 , T_1 V_6 )
{
int V_4 = F_2 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_5 , V_4 * V_3 , V_7 , V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_8 = 100 ;
while ( V_8 -- > 0 ) {
T_1 V_6 ;
V_6 = F_1 ( V_2 , V_9 ) ;
if ( ! ( V_6 & V_10 ) )
return 0 ;
F_9 ( 200 , 300 ) ;
}
return - V_11 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_9 , V_12 ,
V_12 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_9 , V_12 , 0 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_13 )
{
T_1 V_6 = 0 ;
if ( V_13 == V_2 -> V_13 )
return;
if ( V_13 & F_13 ( 0 ) )
V_6 |= V_14 ;
if ( V_13 & F_13 ( 1 ) )
V_6 |= V_15 ;
F_6 ( V_2 , V_9 ,
V_14 |
V_15 , V_6 ) ;
V_2 -> V_13 = V_13 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_16 * V_17 ,
bool V_18 )
{
int V_19 ;
V_17 -> V_20 = F_1 ( V_2 , V_21 ) ;
V_17 -> V_20 += ( F_1 ( V_2 , V_22 ) & ~ V_23 ) * 10 ;
V_17 -> V_24 = F_1 ( V_2 , V_25 ) ;
V_17 -> V_24 += ( F_1 ( V_2 , V_26 ) & ~ V_23 ) * 10 ;
V_17 -> V_27 = F_1 ( V_2 , V_28 ) ;
V_17 -> V_27 += ( F_1 ( V_2 , V_29 ) & ~ V_23 ) * 10 ;
V_17 -> V_30 = F_1 ( V_2 , V_31 ) ;
V_17 -> V_30 += ( F_1 ( V_2 , V_32 ) & ~ V_23 ) * 10 ;
if ( V_18 ) {
V_17 -> V_33 = - 1 ;
V_17 -> V_34 = - 1 ;
V_17 -> V_35 = - 1 ;
V_17 -> V_36 = - 1 ;
V_17 -> V_37 = - 1 ;
return;
}
V_17 -> V_33 = ( F_1 ( V_2 , V_38 ) & ~ V_23 ) ;
V_17 -> V_34 = F_1 ( V_2 , V_39 ) * 10 +
F_1 ( V_2 , V_40 ) - 1 ;
V_19 = F_1 ( V_2 , V_41 ) * 1000 +
F_1 ( V_2 , V_42 ) * 100 +
F_1 ( V_2 , V_43 ) * 10 +
F_1 ( V_2 , V_44 ) ;
V_17 -> V_35 = V_19 - 1900 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_16 * V_17 ,
bool V_18 )
{
int V_19 ;
F_4 ( V_2 , V_17 -> V_20 % 10 , V_21 ) ;
F_4 ( V_2 , V_17 -> V_20 / 10 , V_22 ) ;
F_4 ( V_2 , V_17 -> V_24 % 10 , V_25 ) ;
F_4 ( V_2 , V_17 -> V_24 / 10 , V_26 ) ;
F_4 ( V_2 , V_17 -> V_27 % 10 , V_28 ) ;
F_4 ( V_2 , V_17 -> V_27 / 10 , V_29 ) ;
F_4 ( V_2 , V_17 -> V_30 % 10 , V_31 ) ;
F_4 ( V_2 , V_17 -> V_30 / 10 , V_32 ) ;
F_4 ( V_2 , V_18 ? V_23 : V_17 -> V_33 ,
V_38 ) ;
if ( V_18 )
return;
F_4 ( V_2 , ( V_17 -> V_34 + 1 ) % 10 , V_40 ) ;
F_4 ( V_2 , ( V_17 -> V_34 + 1 ) / 10 , V_39 ) ;
V_19 = V_17 -> V_35 + 1900 ;
F_4 ( V_2 , V_19 % 10 , V_44 ) ;
F_4 ( V_2 , ( V_19 / 10 ) % 10 , V_43 ) ;
F_4 ( V_2 , ( V_19 / 100 ) % 10 , V_42 ) ;
F_4 ( V_2 , V_19 / 1000 , V_41 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_45 )
{
F_6 ( V_2 , V_46 ,
V_47 |
V_48 ,
V_45 ? V_48 : 0 ) ;
}
static int F_17 ( struct V_49 * V_50 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_18 ( V_50 ) ;
unsigned long V_51 ;
int V_52 ;
F_19 ( & V_2 -> V_53 , V_51 ) ;
F_12 ( V_2 , 0 ) ;
V_52 = F_8 ( V_2 ) ;
if ( ! V_52 )
F_14 ( V_2 , V_17 , false ) ;
F_20 ( & V_2 -> V_53 , V_51 ) ;
return V_52 ? V_52 : F_21 ( V_17 ) ;
}
static int F_22 ( struct V_49 * V_50 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_18 ( V_50 ) ;
unsigned long V_51 ;
F_19 ( & V_2 -> V_53 , V_51 ) ;
F_10 ( V_2 ) ;
F_9 ( 200 , 300 ) ;
F_12 ( V_2 , 0 ) ;
F_15 ( V_2 , V_17 , false ) ;
F_11 ( V_2 ) ;
F_20 ( & V_2 -> V_53 , V_51 ) ;
return 0 ;
}
static int F_23 ( struct V_49 * V_50 , struct V_54 * V_18 )
{
struct V_1 * V_2 = F_18 ( V_50 ) ;
unsigned long V_51 ;
T_1 V_55 ;
if ( V_2 -> V_56 <= 0 )
return - V_57 ;
F_19 ( & V_2 -> V_53 , V_51 ) ;
F_12 ( V_2 , 1 ) ;
F_14 ( V_2 , & V_18 -> time , true ) ;
V_55 = F_1 ( V_2 , V_46 ) ;
V_18 -> V_45 = ! ! ( V_55 & V_48 ) ;
V_18 -> V_58 = ! ! ( V_55 & V_47 ) ;
F_20 ( & V_2 -> V_53 , V_51 ) ;
return 0 ;
}
static int F_24 ( struct V_49 * V_50 , struct V_54 * V_18 )
{
struct V_1 * V_2 = F_18 ( V_50 ) ;
unsigned long V_51 ;
if ( V_2 -> V_56 <= 0 )
return - V_57 ;
F_19 ( & V_2 -> V_53 , V_51 ) ;
F_12 ( V_2 , 1 ) ;
F_15 ( V_2 , & V_18 -> time , true ) ;
F_16 ( V_2 , V_18 -> V_45 ) ;
F_20 ( & V_2 -> V_53 , V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_49 * V_50 , unsigned int V_45 )
{
struct V_1 * V_2 = F_18 ( V_50 ) ;
unsigned long V_51 ;
if ( V_2 -> V_56 <= 0 )
return - V_57 ;
F_19 ( & V_2 -> V_53 , V_51 ) ;
F_12 ( V_2 , 1 ) ;
F_16 ( V_2 , V_45 ) ;
F_20 ( & V_2 -> V_53 , V_51 ) ;
return 0 ;
}
static T_2 F_26 ( int V_56 , void * V_59 )
{
struct V_60 * V_61 = V_59 ;
struct V_1 * V_2 = F_18 ( V_61 -> V_50 . V_62 ) ;
unsigned long V_51 ;
T_2 V_63 = V_64 ;
T_1 V_55 ;
F_19 ( & V_2 -> V_53 , V_51 ) ;
F_12 ( V_2 , 1 ) ;
V_55 = F_1 ( V_2 , V_46 ) ;
if ( V_55 & V_47 ) {
V_63 = V_65 ;
F_16 ( V_2 , false ) ;
F_27 ( V_61 , 1 , V_66 | V_67 ) ;
}
F_20 ( & V_2 -> V_53 , V_51 ) ;
return V_63 ;
}
static void F_28 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
F_19 ( & V_2 -> V_53 , V_51 ) ;
F_12 ( V_2 , 2 ) ;
F_4 ( V_2 , 0 , V_68 ) ;
F_20 ( & V_2 -> V_53 , V_51 ) ;
}
static int T_3 F_29 ( struct V_69 * V_50 )
{
struct V_70 * V_71 ;
void T_4 * V_72 ;
struct V_1 * V_2 ;
struct V_60 * V_61 ;
int V_63 ;
V_71 = F_30 ( V_50 , V_73 , 0 ) ;
if ( ! V_71 )
return - V_74 ;
V_2 = F_31 ( & V_50 -> V_50 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return - V_76 ;
V_72 = F_32 ( & V_50 -> V_50 , V_71 ) ;
if ( F_33 ( V_72 ) )
return F_34 ( V_72 ) ;
V_2 -> V_5 = F_35 ( & V_50 -> V_50 , V_72 ,
& V_77 ) ;
if ( F_33 ( V_2 -> V_5 ) )
return F_34 ( V_2 -> V_5 ) ;
V_2 -> V_56 = F_36 ( V_50 , 0 ) ;
F_37 ( & V_2 -> V_53 ) ;
V_2 -> V_13 = - 1 ;
F_28 ( V_2 ) ;
F_38 ( V_50 , V_2 ) ;
V_61 = F_39 ( & V_50 -> V_50 , V_78 , & V_79 ,
V_80 ) ;
if ( F_33 ( V_61 ) )
return F_34 ( V_61 ) ;
if ( V_2 -> V_56 > 0 ) {
V_63 = F_40 ( & V_50 -> V_50 , V_2 -> V_56 ,
F_26 , V_81 ,
F_41 ( & V_50 -> V_50 ) , V_61 ) ;
if ( V_63 ) {
V_2 -> V_56 = 0 ;
F_42 ( & V_50 -> V_50 , L_1 ) ;
} else {
F_43 ( & V_50 -> V_50 , true ) ;
}
}
return 0 ;
}
static int F_44 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_18 ( V_50 ) ;
if ( F_45 ( V_50 ) )
F_46 ( V_2 -> V_56 ) ;
return 0 ;
}
static int F_47 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_18 ( V_50 ) ;
if ( F_45 ( V_50 ) )
F_48 ( V_2 -> V_56 ) ;
return 0 ;
}
