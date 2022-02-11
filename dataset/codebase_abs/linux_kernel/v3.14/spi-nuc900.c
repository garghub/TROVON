static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static void F_3 ( struct V_2 * V_5 , unsigned int V_6 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
unsigned int V_8 ;
unsigned int V_9 = V_5 -> V_10 & V_11 ? 1 : 0 ;
unsigned int V_12 = V_5 -> V_10 & V_13 ? 1 : 0 ;
unsigned long V_14 ;
F_4 ( & V_7 -> V_15 , V_14 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_17 ) ;
if ( ! V_9 )
V_8 &= ~ V_18 ;
else
V_8 |= V_18 ;
if ( ! V_6 )
V_8 &= ~ V_19 ;
else
V_8 |= V_19 ;
F_6 ( V_8 , V_7 -> V_16 + V_17 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_20 ) ;
if ( ! V_12 )
V_8 &= ~ V_21 ;
else
V_8 |= V_21 ;
F_6 ( V_8 , V_7 -> V_16 + V_20 ) ;
F_7 ( & V_7 -> V_15 , V_14 ) ;
}
static void F_8 ( struct V_2 * V_5 , int V_22 )
{
switch ( V_22 ) {
case V_23 :
F_3 ( V_5 , 0 ) ;
break;
case V_24 :
F_3 ( V_5 , 1 ) ;
break;
}
}
static void F_9 ( struct V_1 * V_7 ,
unsigned int V_25 )
{
unsigned int V_8 ;
unsigned long V_14 ;
F_4 ( & V_7 -> V_15 , V_14 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_20 ) ;
if ( ! V_25 )
V_8 &= ~ V_26 ;
else
V_8 |= V_25 << 0x08 ;
F_6 ( V_8 , V_7 -> V_16 + V_20 ) ;
F_7 ( & V_7 -> V_15 , V_14 ) ;
}
static void F_10 ( struct V_1 * V_7 ,
unsigned int V_27 )
{
unsigned int V_8 ;
unsigned long V_14 ;
F_4 ( & V_7 -> V_15 , V_14 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_20 ) ;
V_8 |= ( V_27 << 0x03 ) ;
F_6 ( V_8 , V_7 -> V_16 + V_20 ) ;
F_7 ( & V_7 -> V_15 , V_14 ) ;
}
static void F_11 ( struct V_1 * V_7 )
{
unsigned int V_8 ;
unsigned long V_14 ;
F_4 ( & V_7 -> V_15 , V_14 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_20 ) ;
V_8 |= V_28 ;
F_6 ( V_8 , V_7 -> V_16 + V_20 ) ;
F_7 ( & V_7 -> V_15 , V_14 ) ;
}
static inline unsigned int F_12 ( struct V_1 * V_7 , int V_29 )
{
return V_7 -> V_30 ? V_7 -> V_30 [ V_29 ] : 0 ;
}
static int F_13 ( struct V_2 * V_5 , struct V_31 * V_32 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
V_7 -> V_30 = V_32 -> V_33 ;
V_7 -> V_34 = V_32 -> V_35 ;
V_7 -> V_36 = V_32 -> V_36 ;
V_7 -> V_29 = 0 ;
F_6 ( F_12 ( V_7 , 0x0 ) , V_7 -> V_16 + V_37 ) ;
F_11 ( V_7 ) ;
F_14 ( & V_7 -> V_38 ) ;
return V_7 -> V_29 ;
}
static T_1 F_15 ( int V_39 , void * V_40 )
{
struct V_1 * V_7 = V_40 ;
unsigned int V_41 ;
unsigned int V_29 = V_7 -> V_29 ;
V_41 = F_5 ( V_7 -> V_16 + V_20 ) ;
F_6 ( V_41 , V_7 -> V_16 + V_20 ) ;
if ( V_41 & V_42 ) {
V_7 -> V_29 ++ ;
if ( V_7 -> V_34 )
V_7 -> V_34 [ V_29 ] = F_5 ( V_7 -> V_16 + V_43 ) ;
V_29 ++ ;
if ( V_29 < V_7 -> V_36 ) {
F_6 ( F_12 ( V_7 , V_29 ) , V_7 -> V_16 + V_37 ) ;
F_11 ( V_7 ) ;
} else {
F_16 ( & V_7 -> V_38 ) ;
}
return V_44 ;
}
F_16 ( & V_7 -> V_38 ) ;
return V_44 ;
}
static void F_17 ( struct V_1 * V_7 , unsigned int V_45 )
{
unsigned int V_8 ;
unsigned long V_14 ;
F_4 ( & V_7 -> V_15 , V_14 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_20 ) ;
if ( V_45 )
V_8 |= V_46 ;
else
V_8 &= ~ V_46 ;
F_6 ( V_8 , V_7 -> V_16 + V_20 ) ;
F_7 ( & V_7 -> V_15 , V_14 ) ;
}
static void F_18 ( struct V_1 * V_7 , unsigned int V_45 )
{
unsigned int V_8 ;
unsigned long V_14 ;
F_4 ( & V_7 -> V_15 , V_14 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_20 ) ;
if ( V_45 )
V_8 |= V_47 ;
else
V_8 &= ~ V_47 ;
F_6 ( V_8 , V_7 -> V_16 + V_20 ) ;
F_7 ( & V_7 -> V_15 , V_14 ) ;
}
static void F_19 ( struct V_1 * V_7 , unsigned int V_48 )
{
unsigned int V_8 ;
unsigned long V_14 ;
F_4 ( & V_7 -> V_15 , V_14 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_20 ) ;
if ( V_48 )
V_8 |= V_49 ;
else
V_8 &= ~ V_49 ;
F_6 ( V_8 , V_7 -> V_16 + V_20 ) ;
F_7 ( & V_7 -> V_15 , V_14 ) ;
}
static void F_20 ( struct V_1 * V_7 , unsigned int V_50 )
{
unsigned int V_8 ;
unsigned long V_14 ;
F_4 ( & V_7 -> V_15 , V_14 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_20 ) ;
if ( V_50 )
V_8 |= ( V_50 << 12 ) ;
else
V_8 &= ~ ( 0x0f << 12 ) ;
F_6 ( V_8 , V_7 -> V_16 + V_20 ) ;
F_7 ( & V_7 -> V_15 , V_14 ) ;
}
static void F_21 ( struct V_1 * V_7 )
{
unsigned int V_8 ;
unsigned long V_14 ;
F_4 ( & V_7 -> V_15 , V_14 ) ;
V_8 = F_5 ( V_7 -> V_16 + V_20 ) ;
V_8 |= V_51 ;
F_6 ( V_8 , V_7 -> V_16 + V_20 ) ;
F_7 ( & V_7 -> V_15 , V_14 ) ;
}
static void F_22 ( struct V_1 * V_7 )
{
F_6 ( V_7 -> V_52 -> V_53 , V_7 -> V_16 + V_54 ) ;
}
static void F_23 ( struct V_1 * V_7 )
{
F_24 ( V_7 -> V_55 ) ;
F_25 ( & V_7 -> V_15 ) ;
F_17 ( V_7 , V_7 -> V_52 -> V_56 ) ;
F_18 ( V_7 , V_7 -> V_52 -> V_57 ) ;
F_19 ( V_7 , V_7 -> V_52 -> V_48 ) ;
F_20 ( V_7 , V_7 -> V_52 -> V_50 ) ;
F_10 ( V_7 , V_7 -> V_52 -> V_27 ) ;
F_9 ( V_7 , V_7 -> V_52 -> V_25 ) ;
F_22 ( V_7 ) ;
F_21 ( V_7 ) ;
}
static int F_26 ( struct V_58 * V_59 )
{
struct V_1 * V_7 ;
struct V_60 * V_4 ;
int V_61 = 0 ;
V_4 = F_27 ( & V_59 -> V_40 , sizeof( struct V_1 ) ) ;
if ( V_4 == NULL ) {
F_28 ( & V_59 -> V_40 , L_1 ) ;
return - V_62 ;
}
V_7 = F_2 ( V_4 ) ;
V_7 -> V_4 = V_4 ;
V_7 -> V_52 = F_29 ( & V_59 -> V_40 ) ;
V_7 -> V_40 = & V_59 -> V_40 ;
if ( V_7 -> V_52 == NULL ) {
F_28 ( & V_59 -> V_40 , L_2 ) ;
V_61 = - V_63 ;
goto V_64;
}
F_30 ( V_59 , V_7 ) ;
F_31 ( & V_7 -> V_38 ) ;
V_4 -> V_65 = V_13 | V_66 | V_11 ;
if ( V_7 -> V_52 -> V_48 )
V_4 -> V_65 |= V_67 ;
V_4 -> V_68 = V_7 -> V_52 -> V_69 ;
V_4 -> V_70 = V_7 -> V_52 -> V_70 ;
V_7 -> V_71 . V_4 = V_7 -> V_4 ;
V_7 -> V_71 . V_72 = F_8 ;
V_7 -> V_71 . V_73 = F_13 ;
V_7 -> V_74 = F_32 ( V_59 , V_75 , 0 ) ;
V_7 -> V_16 = F_33 ( & V_59 -> V_40 , V_7 -> V_74 ) ;
if ( F_34 ( V_7 -> V_16 ) ) {
V_61 = F_35 ( V_7 -> V_16 ) ;
goto V_64;
}
V_7 -> V_39 = F_36 ( V_59 , 0 ) ;
if ( V_7 -> V_39 < 0 ) {
F_28 ( & V_59 -> V_40 , L_3 ) ;
V_61 = - V_63 ;
goto V_64;
}
V_61 = F_37 ( & V_59 -> V_40 , V_7 -> V_39 , F_15 , 0 ,
V_59 -> V_76 , V_7 ) ;
if ( V_61 ) {
F_28 ( & V_59 -> V_40 , L_4 ) ;
goto V_64;
}
V_7 -> V_55 = F_38 ( & V_59 -> V_40 , L_5 ) ;
if ( F_34 ( V_7 -> V_55 ) ) {
F_28 ( & V_59 -> V_40 , L_6 ) ;
V_61 = F_35 ( V_7 -> V_55 ) ;
goto V_64;
}
F_39 ( & V_59 -> V_40 , NULL ) ;
F_23 ( V_7 ) ;
V_61 = F_40 ( & V_7 -> V_71 ) ;
if ( V_61 ) {
F_28 ( & V_59 -> V_40 , L_7 ) ;
goto V_77;
}
return 0 ;
V_77:
F_41 ( V_7 -> V_55 ) ;
V_64:
F_42 ( V_7 -> V_4 ) ;
return V_61 ;
}
static int F_43 ( struct V_58 * V_40 )
{
struct V_1 * V_7 = F_44 ( V_40 ) ;
F_45 ( & V_7 -> V_71 ) ;
F_41 ( V_7 -> V_55 ) ;
F_42 ( V_7 -> V_4 ) ;
return 0 ;
}
