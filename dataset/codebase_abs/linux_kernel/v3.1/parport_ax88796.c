static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static unsigned char
F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_3 ( V_5 -> V_6 ) ;
}
static void
F_4 ( struct V_2 * V_3 , unsigned char V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_5 ( V_7 , V_5 -> V_6 ) ;
}
static unsigned char
F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_8 = F_3 ( V_5 -> V_9 ) ;
unsigned int V_10 = 0 ;
if ( ! ( V_8 & V_11 ) )
V_10 |= V_12 ;
if ( ! ( V_8 & V_13 ) )
V_10 |= V_14 ;
if ( V_8 & V_15 )
V_10 |= V_16 ;
if ( ! ( V_8 & V_17 ) )
V_10 |= V_18 ;
return V_10 ;
}
static void
F_7 ( struct V_2 * V_3 , unsigned char V_19 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_8 = F_3 ( V_5 -> V_9 ) ;
V_8 &= V_20 ;
if ( ! ( V_19 & V_12 ) )
V_8 |= V_11 ;
if ( ! ( V_19 & V_14 ) )
V_8 |= V_13 ;
if ( V_19 & V_16 )
V_8 |= V_15 ;
if ( ! ( V_19 & V_18 ) )
V_8 |= V_17 ;
F_8 ( V_5 -> V_21 , L_1 , V_19 , V_8 ) ;
F_5 ( V_8 , V_5 -> V_9 ) ;
if ( F_6 ( V_3 ) != V_19 ) {
F_9 ( V_5 -> V_21 , L_2 ,
F_6 ( V_3 ) , V_19 ) ;
}
}
static unsigned char
F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_22 = F_3 ( V_5 -> V_23 ) ;
unsigned int V_10 = 0 ;
if ( V_22 & V_24 )
V_10 |= V_25 ;
if ( V_22 & V_26 )
V_10 |= V_27 ;
if ( V_22 & V_28 )
V_10 |= V_29 ;
if ( V_22 & V_30 )
V_10 |= V_31 ;
if ( V_22 & V_32 )
V_10 |= V_33 ;
return V_10 ;
}
static unsigned char
F_11 ( struct V_2 * V_3 , unsigned char V_34 ,
unsigned char V_35 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned char V_36 = F_6 ( V_3 ) ;
F_8 ( V_5 -> V_21 , L_3 ,
V_34 , V_35 , V_36 ) ;
F_7 ( V_3 , ( V_36 & ~ V_34 ) | V_35 ) ;
return V_36 ;
}
static void
F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_37 ;
F_13 ( V_37 ) ;
if ( ! V_5 -> V_38 ) {
F_14 ( V_3 -> V_39 ) ;
V_5 -> V_38 = 1 ;
}
F_15 ( V_37 ) ;
}
static void
F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_37 ;
F_13 ( V_37 ) ;
if ( V_5 -> V_38 ) {
F_17 ( V_3 -> V_39 ) ;
V_5 -> V_38 = 0 ;
}
F_15 ( V_37 ) ;
}
static void
F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
void T_1 * V_8 = V_5 -> V_9 ;
F_5 ( ( F_3 ( V_8 ) & ~ V_20 ) , V_8 ) ;
}
static void
F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
void T_1 * V_8 = V_5 -> V_9 ;
F_5 ( F_3 ( V_8 ) | V_20 , V_8 ) ;
}
static void
F_20 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_1 * V_5 = F_1 ( V_41 -> V_44 ) ;
memset ( V_43 , 0 , sizeof( struct V_42 ) ) ;
F_8 ( V_5 -> V_21 , L_4 , V_41 , V_43 ) ;
V_43 -> V_45 . V_46 . V_8 = F_3 ( V_5 -> V_9 ) ;
}
static void
F_21 ( struct V_2 * V_3 , struct V_42 * V_43 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_8 ( V_5 -> V_21 , L_5 , V_3 , V_43 ) ;
V_43 -> V_45 . V_46 . V_8 = F_3 ( V_5 -> V_9 ) ;
}
static void
F_22 ( struct V_2 * V_3 , struct V_42 * V_43 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_8 ( V_5 -> V_21 , L_6 , V_3 , V_43 ) ;
F_5 ( V_43 -> V_45 . V_46 . V_8 , V_5 -> V_9 ) ;
}
static int F_23 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = & V_48 -> V_21 ;
struct V_1 * V_5 ;
struct V_2 * V_51 = NULL ;
struct V_52 * V_53 ;
unsigned long V_54 ;
int V_55 ;
int V_39 ;
int V_10 ;
V_5 = F_24 ( sizeof( struct V_1 ) , V_56 ) ;
if ( V_5 == NULL ) {
F_9 ( V_50 , L_7 ) ;
return - V_57 ;
}
V_53 = F_25 ( V_48 , V_58 , 0 ) ;
if ( V_53 == NULL ) {
F_9 ( V_50 , L_8 ) ;
V_10 = - V_59 ;
goto V_60;
}
V_54 = F_26 ( V_53 ) ;
V_55 = V_54 / 3 ;
V_5 -> V_61 = F_27 ( V_53 -> V_62 , V_54 , V_48 -> V_63 ) ;
if ( V_5 -> V_61 == NULL ) {
F_9 ( V_50 , L_9 ) ;
V_10 = - V_59 ;
goto V_60;
}
V_5 -> V_64 = F_28 ( V_53 -> V_62 , V_54 ) ;
if ( V_5 -> V_64 == NULL ) {
F_9 ( V_50 , L_10 ) ;
V_10 = - V_59 ;
goto V_65;
}
V_39 = F_29 ( V_48 , 0 ) ;
if ( V_39 <= 0 )
V_39 = V_66 ;
V_51 = F_30 ( ( unsigned long ) V_5 -> V_64 , V_39 ,
V_67 ,
& V_68 ) ;
if ( V_51 == NULL ) {
F_9 ( V_50 , L_11 ) ;
V_10 = - V_57 ;
goto V_69;
}
V_51 -> V_4 = V_5 ;
V_5 -> V_2 = V_51 ;
V_5 -> V_21 = V_50 ;
V_5 -> V_6 = V_5 -> V_64 ;
V_5 -> V_23 = V_5 -> V_64 + ( V_55 * 1 ) ;
V_5 -> V_9 = V_5 -> V_64 + ( V_55 * 2 ) ;
F_5 ( V_11 , V_5 -> V_9 ) ;
if ( V_39 >= 0 ) {
V_10 = F_31 ( V_39 , V_70 ,
V_71 , V_48 -> V_63 , V_51 ) ;
if ( V_10 < 0 )
goto V_72;
V_5 -> V_38 = 1 ;
}
F_32 ( V_48 , V_51 ) ;
F_33 ( V_50 , L_12 ) ;
F_34 ( V_51 ) ;
return 0 ;
V_72:
F_35 ( V_51 ) ;
V_69:
F_36 ( V_5 -> V_64 ) ;
V_65:
F_37 ( V_5 -> V_61 ) ;
F_38 ( V_5 -> V_61 ) ;
V_60:
F_38 ( V_5 ) ;
return V_10 ;
}
static int F_39 ( struct V_47 * V_48 )
{
struct V_2 * V_3 = F_40 ( V_48 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_41 ( V_3 -> V_39 , V_3 ) ;
F_35 ( V_3 ) ;
F_36 ( V_5 -> V_64 ) ;
F_37 ( V_5 -> V_61 ) ;
F_38 ( V_5 -> V_61 ) ;
F_38 ( V_5 ) ;
return 0 ;
}
static int F_42 ( struct V_47 * V_21 ,
T_2 V_73 )
{
struct V_2 * V_3 = F_40 ( V_21 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_21 ( V_3 , & V_5 -> V_74 ) ;
F_5 ( V_20 | V_11 , V_5 -> V_9 ) ;
return 0 ;
}
static int F_43 ( struct V_47 * V_21 )
{
struct V_2 * V_3 = F_40 ( V_21 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_22 ( V_3 , & V_5 -> V_74 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_75 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_75 ) ;
}
