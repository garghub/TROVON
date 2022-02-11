static inline void F_1 ( struct V_1 * V_2 )
{
unsigned V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
unsigned V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_8 -> V_9 ( V_8 , 1 ) ;
V_3 &= ~ V_10 ;
V_3 &= ~ V_11 ;
V_3 &= ~ V_12 ;
if ( ! V_8 -> V_13 )
V_3 |= F_5 ( V_8 -> V_14 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 , L_1 ,
F_2 ( V_2 -> V_4 + V_5 ) ,
F_2 ( V_2 -> V_4 + V_15 ) ,
F_2 ( V_2 -> V_4 + V_16 ) ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_17 = V_2 -> V_18 ;
if ( ! V_17 && ! F_9 ( & V_19 ) ) {
V_17 = F_10 ( & V_19 ,
struct V_7 , V_20 ) ;
F_11 ( & V_17 -> V_20 ) ;
} else
V_2 -> V_18 = NULL ;
if ( V_17 ) {
F_7 ( V_2 , L_2 , V_17 ) ;
V_2 -> V_21 = V_17 ;
F_4 ( V_2 , V_17 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 ) ;
}
}
int F_12 ( struct V_7 * V_8 ,
unsigned int V_14 , unsigned int V_22 )
{
struct V_1 * V_2 = V_23 ;
unsigned long V_24 ;
if ( ! V_2 ) {
F_13 ( V_25 L_3 , V_26 ) ;
return - V_27 ;
}
if ( V_8 -> V_13 && V_2 -> V_18 )
return - V_28 ;
F_14 ( & V_2 -> V_29 , V_24 ) ;
V_8 -> V_14 = V_14 ;
V_8 -> V_22 = V_22 ;
if ( V_8 -> V_13 )
V_2 -> V_18 = V_8 ;
else
F_15 ( & V_8 -> V_20 , & V_19 ) ;
if ( ! V_2 -> V_21 )
F_8 ( V_2 ) ;
F_16 ( & V_2 -> V_29 , V_24 ) ;
return 0 ;
}
static void F_17 ( struct V_7 * V_8 ,
unsigned V_30 , unsigned V_31 , unsigned * V_32 )
{
V_8 -> V_33 = V_30 ;
F_18 ( V_8 -> V_34 ) ;
}
int F_19 ( struct V_7 * V_8 , unsigned int V_35 )
{
F_20 ( V_36 ) ;
int V_37 ;
V_8 -> V_38 = F_17 ;
V_8 -> V_34 = & V_36 ;
V_8 -> V_33 = - 1 ;
V_37 = F_12 ( V_8 , V_35 , 1 ) ;
if ( V_37 < 0 )
goto V_39;
V_37 = F_21 ( V_36 , V_8 -> V_33 >= 0 , V_40 / 2 ) ;
if ( V_8 -> V_33 < 0 ) {
V_37 = - V_41 ;
goto V_39;
}
V_8 -> V_38 = NULL ;
return V_8 -> V_33 ;
V_39:
return V_37 ;
}
static void F_22 ( struct V_7 * V_8 ,
unsigned V_42 )
{
}
struct V_7 * F_23 ( struct V_43 * V_44 ,
void (* V_42)( struct V_7 * V_8 ,
unsigned int V_45 ) ,
void (* F_24)( struct V_7 * V_8 ,
unsigned V_46 , unsigned V_47 ,
unsigned * V_48 ) ,
unsigned int V_13 )
{
struct V_7 * V_8 ;
F_25 ( ! V_44 ) ;
if ( ! V_42 )
V_42 = F_22 ;
if ( ! V_44 )
return F_26 ( - V_27 ) ;
V_8 = F_27 ( sizeof( struct V_7 ) , V_49 ) ;
if ( ! V_8 ) {
F_28 ( & V_44 -> V_50 , L_4 ) ;
return F_26 ( - V_51 ) ;
}
V_8 -> V_44 = V_44 ;
V_8 -> V_13 = V_13 ;
V_8 -> V_9 = V_42 ;
V_8 -> V_38 = F_24 ;
return V_8 ;
}
void F_29 ( struct V_7 * V_8 )
{
unsigned long V_24 ;
F_14 ( & V_23 -> V_29 , V_24 ) ;
if ( V_23 -> V_21 == V_8 )
V_23 -> V_21 = NULL ;
if ( V_23 -> V_18 == V_8 )
V_23 -> V_18 = NULL ;
else {
struct V_52 * V_53 , * V_54 ;
struct V_7 * V_55 ;
F_30 (p, n, &adc_pending) {
V_55 = F_31 ( V_53 , struct V_7 , V_20 ) ;
if ( V_55 == V_8 )
F_11 ( & V_55 -> V_20 ) ;
}
}
if ( V_23 -> V_21 == NULL )
F_8 ( V_23 ) ;
F_16 ( & V_23 -> V_29 , V_24 ) ;
F_32 ( V_8 ) ;
}
static T_1 F_33 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
struct V_7 * V_8 = V_2 -> V_21 ;
enum V_58 V_59 = F_34 ( V_2 -> V_44 ) -> V_60 ;
unsigned V_61 , V_62 ;
if ( ! V_8 ) {
F_35 ( & V_2 -> V_44 -> V_50 , L_5 , V_26 ) ;
goto exit;
}
V_61 = F_2 ( V_2 -> V_4 + V_63 ) ;
V_62 = F_2 ( V_2 -> V_4 + V_64 ) ;
F_7 ( V_2 , L_6 , V_8 -> V_22 , V_61 , V_62 ) ;
V_8 -> V_22 -- ;
if ( V_59 == V_65 ) {
V_61 &= 0xfff ;
V_62 &= 0xfff ;
} else {
V_61 &= 0x3ff ;
V_62 &= 0x3ff ;
}
if ( V_8 -> V_38 )
( V_8 -> V_38 ) ( V_8 , V_61 , V_62 , & V_8 -> V_22 ) ;
if ( V_8 -> V_22 > 0 ) {
V_8 -> V_9 ( V_8 , 1 ) ;
F_1 ( V_2 ) ;
} else {
F_36 ( & V_2 -> V_29 ) ;
( V_8 -> V_9 ) ( V_8 , 0 ) ;
V_2 -> V_21 = NULL ;
F_8 ( V_2 ) ;
F_37 ( & V_2 -> V_29 ) ;
}
exit:
if ( V_59 == V_65 ) {
F_3 ( 0 , V_2 -> V_4 + V_66 ) ;
}
return V_67 ;
}
static int F_38 ( struct V_43 * V_44 )
{
struct V_68 * V_50 = & V_44 -> V_50 ;
struct V_1 * V_2 ;
struct V_69 * V_4 ;
int V_37 ;
unsigned V_55 ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_49 ) ;
if ( V_2 == NULL ) {
F_28 ( V_50 , L_7 ) ;
return - V_51 ;
}
F_39 ( & V_2 -> V_29 ) ;
V_2 -> V_44 = V_44 ;
V_2 -> V_70 = F_40 ( 49 ) ;
V_2 -> V_56 = F_41 ( V_44 , 1 ) ;
if ( V_2 -> V_56 <= 0 ) {
F_28 ( V_50 , L_8 ) ;
V_37 = - V_71 ;
goto V_72;
}
V_37 = F_42 ( V_2 -> V_56 , F_33 , 0 , F_43 ( V_50 ) , V_2 ) ;
if ( V_37 < 0 ) {
F_28 ( V_50 , L_9 ) ;
goto V_72;
}
V_2 -> V_73 = F_44 ( V_50 , L_10 ) ;
if ( F_45 ( V_2 -> V_73 ) ) {
F_28 ( V_50 , L_11 ) ;
V_37 = F_46 ( V_2 -> V_73 ) ;
goto V_74;
}
V_4 = F_47 ( V_44 , V_75 , 0 ) ;
if ( ! V_4 ) {
F_28 ( V_50 , L_12 ) ;
V_37 = - V_76 ;
goto V_77;
}
V_2 -> V_4 = F_48 ( V_4 -> V_78 , F_49 ( V_4 ) ) ;
if ( ! V_2 -> V_4 ) {
F_28 ( V_50 , L_13 ) ;
V_37 = - V_76 ;
goto V_77;
}
F_50 ( V_2 -> V_73 ) ;
V_55 = V_2 -> V_70 | V_79 ;
if ( F_34 ( V_44 ) -> V_60 == V_65 ) {
V_55 |= V_80 ;
}
F_3 ( V_55 , V_2 -> V_4 + V_5 ) ;
F_51 ( V_50 , L_14 ) ;
F_52 ( V_44 , V_2 ) ;
V_23 = V_2 ;
return 0 ;
V_77:
F_53 ( V_2 -> V_73 ) ;
V_74:
F_54 ( V_2 -> V_56 , V_2 ) ;
V_72:
F_32 ( V_2 ) ;
return V_37 ;
}
static int T_2 F_55 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_56 ( V_44 ) ;
F_57 ( V_2 -> V_4 ) ;
F_54 ( V_2 -> V_56 , V_2 ) ;
F_58 ( V_2 -> V_73 ) ;
F_53 ( V_2 -> V_73 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_43 * V_44 , T_3 V_81 )
{
struct V_1 * V_2 = F_56 ( V_44 ) ;
unsigned long V_24 ;
T_4 V_3 ;
F_14 ( & V_2 -> V_29 , V_24 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_11 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_60 ( V_2 -> V_56 ) ;
F_16 ( & V_2 -> V_29 , V_24 ) ;
F_58 ( V_2 -> V_73 ) ;
return 0 ;
}
static int F_61 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_56 ( V_44 ) ;
F_50 ( V_2 -> V_73 ) ;
F_62 ( V_2 -> V_56 ) ;
F_3 ( V_2 -> V_70 | V_79 ,
V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static int T_5 F_63 ( void )
{
int V_37 ;
V_37 = F_64 ( & V_82 ) ;
if ( V_37 )
F_13 ( V_25 L_15 , V_26 ) ;
return V_37 ;
}
