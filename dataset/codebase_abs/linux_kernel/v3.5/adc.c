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
enum V_9 V_10 = F_5 ( V_2 -> V_11 ) -> V_12 ;
V_8 -> V_13 ( V_8 , 1 ) ;
if ( V_10 == V_14 || V_10 == V_15 )
V_3 &= ~ V_16 ;
V_3 &= ~ V_17 ;
V_3 &= ~ V_18 ;
if ( ! V_8 -> V_19 ) {
if ( V_10 == V_20 )
F_3 ( V_8 -> V_21 & 0xf , V_2 -> V_4 + V_22 ) ;
else if ( V_10 == V_23 || V_10 == V_24 )
F_3 ( V_8 -> V_21 & 0xf ,
V_2 -> V_4 + V_25 ) ;
else
V_3 |= F_6 ( V_8 -> V_21 ) ;
}
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 , L_1 ,
F_2 ( V_2 -> V_4 + V_5 ) ,
F_2 ( V_2 -> V_4 + V_26 ) ,
F_2 ( V_2 -> V_4 + V_27 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_28 = V_2 -> V_29 ;
if ( ! V_28 && ! F_10 ( & V_30 ) ) {
V_28 = F_11 ( & V_30 ,
struct V_7 , V_31 ) ;
F_12 ( & V_28 -> V_31 ) ;
} else
V_2 -> V_29 = NULL ;
if ( V_28 ) {
F_8 ( V_2 , L_2 , V_28 ) ;
V_2 -> V_32 = V_28 ;
F_4 ( V_2 , V_28 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
int F_13 ( struct V_7 * V_8 ,
unsigned int V_21 , unsigned int V_33 )
{
struct V_1 * V_2 = V_34 ;
unsigned long V_35 ;
if ( ! V_2 ) {
F_14 ( V_36 L_3 , V_37 ) ;
return - V_38 ;
}
F_15 ( & V_2 -> V_39 , V_35 ) ;
if ( V_8 -> V_19 && V_2 -> V_29 ) {
F_16 ( & V_2 -> V_39 , V_35 ) ;
return - V_40 ;
}
V_8 -> V_21 = V_21 ;
V_8 -> V_33 = V_33 ;
if ( V_8 -> V_19 )
V_2 -> V_29 = V_8 ;
else
F_17 ( & V_8 -> V_31 , & V_30 ) ;
if ( ! V_2 -> V_32 )
F_9 ( V_2 ) ;
F_16 ( & V_2 -> V_39 , V_35 ) ;
return 0 ;
}
static void F_18 ( struct V_7 * V_8 ,
unsigned V_41 , unsigned V_42 , unsigned * V_43 )
{
V_8 -> V_44 = V_41 ;
F_19 ( V_8 -> V_45 ) ;
}
int F_20 ( struct V_7 * V_8 , unsigned int V_46 )
{
F_21 ( V_47 ) ;
int V_48 ;
V_8 -> V_49 = F_18 ;
V_8 -> V_45 = & V_47 ;
V_8 -> V_44 = - 1 ;
V_48 = F_13 ( V_8 , V_46 , 1 ) ;
if ( V_48 < 0 )
goto V_50;
V_48 = F_22 ( V_47 , V_8 -> V_44 >= 0 , V_51 / 2 ) ;
if ( V_8 -> V_44 < 0 ) {
V_48 = - V_52 ;
goto V_50;
}
V_8 -> V_49 = NULL ;
return V_8 -> V_44 ;
V_50:
return V_48 ;
}
static void F_23 ( struct V_7 * V_8 ,
unsigned V_53 )
{
}
struct V_7 * F_24 ( struct V_54 * V_11 ,
void (* V_53)( struct V_7 * V_8 ,
unsigned int V_55 ) ,
void (* F_25)( struct V_7 * V_8 ,
unsigned V_56 , unsigned V_57 ,
unsigned * V_58 ) ,
unsigned int V_19 )
{
struct V_7 * V_8 ;
F_26 ( ! V_11 ) ;
if ( ! V_53 )
V_53 = F_23 ;
if ( ! V_11 )
return F_27 ( - V_38 ) ;
V_8 = F_28 ( sizeof( struct V_7 ) , V_59 ) ;
if ( ! V_8 ) {
F_29 ( & V_11 -> V_60 , L_4 ) ;
return F_27 ( - V_61 ) ;
}
V_8 -> V_11 = V_11 ;
V_8 -> V_19 = V_19 ;
V_8 -> V_13 = V_53 ;
V_8 -> V_49 = F_25 ;
return V_8 ;
}
void F_30 ( struct V_7 * V_8 )
{
unsigned long V_35 ;
F_15 ( & V_34 -> V_39 , V_35 ) ;
if ( V_34 -> V_32 == V_8 )
V_34 -> V_32 = NULL ;
if ( V_34 -> V_29 == V_8 )
V_34 -> V_29 = NULL ;
else {
struct V_62 * V_63 , * V_64 ;
struct V_7 * V_65 ;
F_31 (p, n, &adc_pending) {
V_65 = F_32 ( V_63 , struct V_7 , V_31 ) ;
if ( V_65 == V_8 )
F_12 ( & V_65 -> V_31 ) ;
}
}
if ( V_34 -> V_32 == NULL )
F_9 ( V_34 ) ;
F_16 ( & V_34 -> V_39 , V_35 ) ;
F_33 ( V_8 ) ;
}
static T_1 F_34 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
struct V_7 * V_8 = V_2 -> V_32 ;
enum V_9 V_10 = F_5 ( V_2 -> V_11 ) -> V_12 ;
unsigned V_68 , V_69 ;
if ( ! V_8 ) {
F_35 ( & V_2 -> V_11 -> V_60 , L_5 , V_37 ) ;
goto exit;
}
V_68 = F_2 ( V_2 -> V_4 + V_70 ) ;
V_69 = F_2 ( V_2 -> V_4 + V_71 ) ;
F_8 ( V_2 , L_6 , V_8 -> V_33 , V_68 , V_69 ) ;
V_8 -> V_33 -- ;
if ( V_10 == V_14 || V_10 == V_23 ) {
V_68 &= 0x3ff ;
V_69 &= 0x3ff ;
} else {
V_68 &= 0xfff ;
V_69 &= 0xfff ;
}
if ( V_8 -> V_49 )
( V_8 -> V_49 ) ( V_8 , V_68 , V_69 , & V_8 -> V_33 ) ;
if ( V_8 -> V_33 > 0 ) {
V_8 -> V_13 ( V_8 , 1 ) ;
F_1 ( V_2 ) ;
} else {
F_36 ( & V_2 -> V_39 ) ;
( V_8 -> V_13 ) ( V_8 , 0 ) ;
V_2 -> V_32 = NULL ;
F_9 ( V_2 ) ;
F_37 ( & V_2 -> V_39 ) ;
}
exit:
if ( V_10 == V_15 || V_10 == V_20 ) {
F_3 ( 0 , V_2 -> V_4 + V_72 ) ;
}
return V_73 ;
}
static int F_38 ( struct V_54 * V_11 )
{
struct V_74 * V_60 = & V_11 -> V_60 ;
struct V_1 * V_2 ;
struct V_75 * V_4 ;
enum V_9 V_10 = F_5 ( V_11 ) -> V_12 ;
int V_48 ;
unsigned V_65 ;
V_2 = F_28 ( sizeof( struct V_1 ) , V_59 ) ;
if ( V_2 == NULL ) {
F_29 ( V_60 , L_7 ) ;
return - V_61 ;
}
F_39 ( & V_2 -> V_39 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_76 = F_40 ( 49 ) ;
V_2 -> V_77 = F_41 ( V_60 , L_8 ) ;
if ( F_42 ( V_2 -> V_77 ) ) {
F_29 ( V_60 , L_9 ) ;
V_48 = F_43 ( V_2 -> V_77 ) ;
goto V_78;
}
V_2 -> V_66 = F_44 ( V_11 , 1 ) ;
if ( V_2 -> V_66 <= 0 ) {
F_29 ( V_60 , L_10 ) ;
V_48 = - V_79 ;
goto V_80;
}
V_48 = F_45 ( V_2 -> V_66 , F_34 , 0 , F_46 ( V_60 ) , V_2 ) ;
if ( V_48 < 0 ) {
F_29 ( V_60 , L_11 ) ;
goto V_80;
}
V_2 -> V_81 = F_47 ( V_60 , L_12 ) ;
if ( F_42 ( V_2 -> V_81 ) ) {
F_29 ( V_60 , L_13 ) ;
V_48 = F_43 ( V_2 -> V_81 ) ;
goto V_82;
}
V_4 = F_48 ( V_11 , V_83 , 0 ) ;
if ( ! V_4 ) {
F_29 ( V_60 , L_14 ) ;
V_48 = - V_84 ;
goto V_85;
}
V_2 -> V_4 = F_49 ( V_4 -> V_86 , F_50 ( V_4 ) ) ;
if ( ! V_2 -> V_4 ) {
F_29 ( V_60 , L_15 ) ;
V_48 = - V_84 ;
goto V_85;
}
V_48 = F_51 ( V_2 -> V_77 ) ;
if ( V_48 )
goto V_87;
F_52 ( V_2 -> V_81 ) ;
V_65 = V_2 -> V_76 | V_88 ;
if ( V_10 == V_24 )
V_65 |= V_89 ;
if ( V_10 == V_15 || V_10 == V_20 )
V_65 |= V_90 ;
F_3 ( V_65 , V_2 -> V_4 + V_5 ) ;
F_53 ( V_60 , L_16 ) ;
F_54 ( V_11 , V_2 ) ;
V_34 = V_2 ;
return 0 ;
V_87:
F_55 ( V_2 -> V_4 ) ;
V_85:
F_56 ( V_2 -> V_81 ) ;
V_82:
F_57 ( V_2 -> V_66 , V_2 ) ;
V_80:
F_58 ( V_2 -> V_77 ) ;
V_78:
F_33 ( V_2 ) ;
return V_48 ;
}
static int T_2 F_59 ( struct V_54 * V_11 )
{
struct V_1 * V_2 = F_60 ( V_11 ) ;
F_55 ( V_2 -> V_4 ) ;
F_57 ( V_2 -> V_66 , V_2 ) ;
F_61 ( V_2 -> V_81 ) ;
F_62 ( V_2 -> V_77 ) ;
F_58 ( V_2 -> V_77 ) ;
F_56 ( V_2 -> V_81 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_74 * V_60 )
{
struct V_54 * V_11 = F_64 ( V_60 ,
struct V_54 , V_60 ) ;
struct V_1 * V_2 = F_60 ( V_11 ) ;
unsigned long V_35 ;
T_3 V_3 ;
F_15 ( & V_2 -> V_39 , V_35 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_17 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_65 ( V_2 -> V_66 ) ;
F_16 ( & V_2 -> V_39 , V_35 ) ;
F_61 ( V_2 -> V_81 ) ;
F_62 ( V_2 -> V_77 ) ;
return 0 ;
}
static int F_66 ( struct V_74 * V_60 )
{
struct V_54 * V_11 = F_64 ( V_60 ,
struct V_54 , V_60 ) ;
struct V_1 * V_2 = F_60 ( V_11 ) ;
enum V_9 V_10 = F_5 ( V_11 ) -> V_12 ;
int V_48 ;
unsigned long V_65 ;
V_48 = F_51 ( V_2 -> V_77 ) ;
if ( V_48 )
return V_48 ;
F_52 ( V_2 -> V_81 ) ;
F_67 ( V_2 -> V_66 ) ;
V_65 = V_2 -> V_76 | V_88 ;
if ( V_10 == V_24 )
V_65 |= V_89 ;
if ( V_10 == V_15 || V_10 == V_20 )
V_65 |= V_90 ;
F_3 ( V_65 , V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static int T_4 F_68 ( void )
{
int V_48 ;
V_48 = F_69 ( & V_91 ) ;
if ( V_48 )
F_14 ( V_36 L_17 , V_37 ) ;
return V_48 ;
}
