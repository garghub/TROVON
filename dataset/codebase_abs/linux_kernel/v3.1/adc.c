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
V_3 &= ~ V_14 ;
V_3 &= ~ V_15 ;
V_3 &= ~ V_16 ;
if ( ! V_8 -> V_17 ) {
if ( V_10 == V_18 )
F_3 ( V_8 -> V_19 & 0xf , V_2 -> V_4 + V_20 ) ;
else
V_3 |= F_6 ( V_8 -> V_19 ) ;
}
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 , L_1 ,
F_2 ( V_2 -> V_4 + V_5 ) ,
F_2 ( V_2 -> V_4 + V_21 ) ,
F_2 ( V_2 -> V_4 + V_22 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_23 = V_2 -> V_24 ;
if ( ! V_23 && ! F_10 ( & V_25 ) ) {
V_23 = F_11 ( & V_25 ,
struct V_7 , V_26 ) ;
F_12 ( & V_23 -> V_26 ) ;
} else
V_2 -> V_24 = NULL ;
if ( V_23 ) {
F_8 ( V_2 , L_2 , V_23 ) ;
V_2 -> V_27 = V_23 ;
F_4 ( V_2 , V_23 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
int F_13 ( struct V_7 * V_8 ,
unsigned int V_19 , unsigned int V_28 )
{
struct V_1 * V_2 = V_29 ;
unsigned long V_30 ;
if ( ! V_2 ) {
F_14 ( V_31 L_3 , V_32 ) ;
return - V_33 ;
}
if ( V_8 -> V_17 && V_2 -> V_24 )
return - V_34 ;
F_15 ( & V_2 -> V_35 , V_30 ) ;
V_8 -> V_19 = V_19 ;
V_8 -> V_28 = V_28 ;
if ( V_8 -> V_17 )
V_2 -> V_24 = V_8 ;
else
F_16 ( & V_8 -> V_26 , & V_25 ) ;
if ( ! V_2 -> V_27 )
F_9 ( V_2 ) ;
F_17 ( & V_2 -> V_35 , V_30 ) ;
return 0 ;
}
static void F_18 ( struct V_7 * V_8 ,
unsigned V_36 , unsigned V_37 , unsigned * V_38 )
{
V_8 -> V_39 = V_36 ;
F_19 ( V_8 -> V_40 ) ;
}
int F_20 ( struct V_7 * V_8 , unsigned int V_41 )
{
F_21 ( V_42 ) ;
int V_43 ;
V_8 -> V_44 = F_18 ;
V_8 -> V_40 = & V_42 ;
V_8 -> V_39 = - 1 ;
V_43 = F_13 ( V_8 , V_41 , 1 ) ;
if ( V_43 < 0 )
goto V_45;
V_43 = F_22 ( V_42 , V_8 -> V_39 >= 0 , V_46 / 2 ) ;
if ( V_8 -> V_39 < 0 ) {
V_43 = - V_47 ;
goto V_45;
}
V_8 -> V_44 = NULL ;
return V_8 -> V_39 ;
V_45:
return V_43 ;
}
static void F_23 ( struct V_7 * V_8 ,
unsigned V_48 )
{
}
struct V_7 * F_24 ( struct V_49 * V_11 ,
void (* V_48)( struct V_7 * V_8 ,
unsigned int V_50 ) ,
void (* F_25)( struct V_7 * V_8 ,
unsigned V_51 , unsigned V_52 ,
unsigned * V_53 ) ,
unsigned int V_17 )
{
struct V_7 * V_8 ;
F_26 ( ! V_11 ) ;
if ( ! V_48 )
V_48 = F_23 ;
if ( ! V_11 )
return F_27 ( - V_33 ) ;
V_8 = F_28 ( sizeof( struct V_7 ) , V_54 ) ;
if ( ! V_8 ) {
F_29 ( & V_11 -> V_55 , L_4 ) ;
return F_27 ( - V_56 ) ;
}
V_8 -> V_11 = V_11 ;
V_8 -> V_17 = V_17 ;
V_8 -> V_13 = V_48 ;
V_8 -> V_44 = F_25 ;
return V_8 ;
}
void F_30 ( struct V_7 * V_8 )
{
unsigned long V_30 ;
F_15 ( & V_29 -> V_35 , V_30 ) ;
if ( V_29 -> V_27 == V_8 )
V_29 -> V_27 = NULL ;
if ( V_29 -> V_24 == V_8 )
V_29 -> V_24 = NULL ;
else {
struct V_57 * V_58 , * V_59 ;
struct V_7 * V_60 ;
F_31 (p, n, &adc_pending) {
V_60 = F_32 ( V_58 , struct V_7 , V_26 ) ;
if ( V_60 == V_8 )
F_12 ( & V_60 -> V_26 ) ;
}
}
if ( V_29 -> V_27 == NULL )
F_9 ( V_29 ) ;
F_17 ( & V_29 -> V_35 , V_30 ) ;
F_33 ( V_8 ) ;
}
static T_1 F_34 ( int V_61 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
struct V_7 * V_8 = V_2 -> V_27 ;
enum V_9 V_10 = F_5 ( V_2 -> V_11 ) -> V_12 ;
unsigned V_63 , V_64 ;
if ( ! V_8 ) {
F_35 ( & V_2 -> V_11 -> V_55 , L_5 , V_32 ) ;
goto exit;
}
V_63 = F_2 ( V_2 -> V_4 + V_65 ) ;
V_64 = F_2 ( V_2 -> V_4 + V_66 ) ;
F_8 ( V_2 , L_6 , V_8 -> V_28 , V_63 , V_64 ) ;
V_8 -> V_28 -- ;
if ( V_10 != V_67 ) {
V_63 &= 0xfff ;
V_64 &= 0xfff ;
} else {
V_63 &= 0x3ff ;
V_64 &= 0x3ff ;
}
if ( V_8 -> V_44 )
( V_8 -> V_44 ) ( V_8 , V_63 , V_64 , & V_8 -> V_28 ) ;
if ( V_8 -> V_28 > 0 ) {
V_8 -> V_13 ( V_8 , 1 ) ;
F_1 ( V_2 ) ;
} else {
F_36 ( & V_2 -> V_35 ) ;
( V_8 -> V_13 ) ( V_8 , 0 ) ;
V_2 -> V_27 = NULL ;
F_9 ( V_2 ) ;
F_37 ( & V_2 -> V_35 ) ;
}
exit:
if ( V_10 != V_67 ) {
F_3 ( 0 , V_2 -> V_4 + V_68 ) ;
}
return V_69 ;
}
static int F_38 ( struct V_49 * V_11 )
{
struct V_70 * V_55 = & V_11 -> V_55 ;
struct V_1 * V_2 ;
struct V_71 * V_4 ;
int V_43 ;
unsigned V_60 ;
V_2 = F_28 ( sizeof( struct V_1 ) , V_54 ) ;
if ( V_2 == NULL ) {
F_29 ( V_55 , L_7 ) ;
return - V_56 ;
}
F_39 ( & V_2 -> V_35 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_72 = F_40 ( 49 ) ;
V_2 -> V_73 = F_41 ( V_55 , L_8 ) ;
if ( F_42 ( V_2 -> V_73 ) ) {
F_29 ( V_55 , L_9 ) ;
V_43 = F_43 ( V_2 -> V_73 ) ;
goto V_74;
}
V_2 -> V_61 = F_44 ( V_11 , 1 ) ;
if ( V_2 -> V_61 <= 0 ) {
F_29 ( V_55 , L_10 ) ;
V_43 = - V_75 ;
goto V_76;
}
V_43 = F_45 ( V_2 -> V_61 , F_34 , 0 , F_46 ( V_55 ) , V_2 ) ;
if ( V_43 < 0 ) {
F_29 ( V_55 , L_11 ) ;
goto V_76;
}
V_2 -> V_77 = F_47 ( V_55 , L_12 ) ;
if ( F_42 ( V_2 -> V_77 ) ) {
F_29 ( V_55 , L_13 ) ;
V_43 = F_43 ( V_2 -> V_77 ) ;
goto V_78;
}
V_4 = F_48 ( V_11 , V_79 , 0 ) ;
if ( ! V_4 ) {
F_29 ( V_55 , L_14 ) ;
V_43 = - V_80 ;
goto V_81;
}
V_2 -> V_4 = F_49 ( V_4 -> V_82 , F_50 ( V_4 ) ) ;
if ( ! V_2 -> V_4 ) {
F_29 ( V_55 , L_15 ) ;
V_43 = - V_80 ;
goto V_81;
}
V_43 = F_51 ( V_2 -> V_73 ) ;
if ( V_43 )
goto V_83;
F_52 ( V_2 -> V_77 ) ;
V_60 = V_2 -> V_72 | V_84 ;
if ( F_5 ( V_11 ) -> V_12 != V_67 ) {
V_60 |= V_85 ;
}
F_3 ( V_60 , V_2 -> V_4 + V_5 ) ;
F_53 ( V_55 , L_16 ) ;
F_54 ( V_11 , V_2 ) ;
V_29 = V_2 ;
return 0 ;
V_83:
F_55 ( V_2 -> V_4 ) ;
V_81:
F_56 ( V_2 -> V_77 ) ;
V_78:
F_57 ( V_2 -> V_61 , V_2 ) ;
V_76:
F_58 ( V_2 -> V_73 ) ;
V_74:
F_33 ( V_2 ) ;
return V_43 ;
}
static int T_2 F_59 ( struct V_49 * V_11 )
{
struct V_1 * V_2 = F_60 ( V_11 ) ;
F_55 ( V_2 -> V_4 ) ;
F_57 ( V_2 -> V_61 , V_2 ) ;
F_61 ( V_2 -> V_77 ) ;
F_62 ( V_2 -> V_73 ) ;
F_58 ( V_2 -> V_73 ) ;
F_56 ( V_2 -> V_77 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_70 * V_55 )
{
struct V_49 * V_11 = F_64 ( V_55 ,
struct V_49 , V_55 ) ;
struct V_1 * V_2 = F_60 ( V_11 ) ;
unsigned long V_30 ;
T_3 V_3 ;
F_15 ( & V_2 -> V_35 , V_30 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_15 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_65 ( V_2 -> V_61 ) ;
F_17 ( & V_2 -> V_35 , V_30 ) ;
F_61 ( V_2 -> V_77 ) ;
F_62 ( V_2 -> V_73 ) ;
return 0 ;
}
static int F_66 ( struct V_70 * V_55 )
{
struct V_49 * V_11 = F_64 ( V_55 ,
struct V_49 , V_55 ) ;
struct V_1 * V_2 = F_60 ( V_11 ) ;
int V_43 ;
unsigned long V_60 ;
V_43 = F_51 ( V_2 -> V_73 ) ;
if ( V_43 )
return V_43 ;
F_52 ( V_2 -> V_77 ) ;
F_67 ( V_2 -> V_61 ) ;
V_60 = V_2 -> V_72 | V_84 ;
if ( F_5 ( V_11 ) -> V_12 != V_67 )
V_60 |= V_85 ;
F_3 ( V_60 , V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static int T_4 F_68 ( void )
{
int V_43 ;
V_43 = F_69 ( & V_86 ) ;
if ( V_43 )
F_14 ( V_31 L_17 , V_32 ) ;
return V_43 ;
}
