static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_2 -> V_9 ) ;
struct V_10 * V_11 ;
T_1 V_12 ;
int V_13 ;
V_5 -> V_14 = F_3 ( V_2 -> V_9 , L_1 ) ;
if ( F_4 ( V_5 -> V_14 ) )
return F_5 ( V_5 -> V_14 ) ;
#ifdef F_6
F_7 ( & V_5 -> V_15 , 0 ) ;
F_7 ( & V_5 -> V_16 , 0 ) ;
F_7 ( & V_5 -> V_17 , 0 ) ;
F_7 ( & V_5 -> V_18 , 0 ) ;
#endif
V_11 = F_8 ( V_8 , V_19 , 0 ) ;
V_5 -> V_20 = F_9 ( V_2 -> V_9 , V_11 ) ;
if ( F_4 ( V_5 -> V_20 ) ) {
F_10 ( L_2 ) ;
V_13 = F_5 ( V_5 -> V_20 ) ;
V_5 -> V_20 = NULL ;
return V_13 ;
}
V_12 = F_11 ( V_5 , V_21 ) ;
if ( ( V_12 & V_22 ) != V_23 ) {
F_10 ( L_3 , V_12 ) ;
return - V_24 ;
}
F_12 ( L_4 ,
( V_12 & V_25 ) >> 8 ,
V_12 & V_26 ) ;
V_13 = F_13 ( V_2 -> V_9 ) ;
if ( V_13 && V_13 != - V_27 )
return V_13 ;
V_13 = F_14 ( V_2 -> V_9 , F_15 ( 32 ) ) ;
if ( V_13 )
goto V_28;
V_13 = F_16 ( V_2 ) ;
if ( V_13 < 0 ) {
F_10 ( L_5 ) ;
goto V_28;
}
V_13 = F_17 ( V_2 , F_18 ( V_8 , 0 ) ) ;
if ( V_13 < 0 ) {
F_10 ( L_6 ) ;
goto V_29;
}
return 0 ;
V_29:
F_19 ( & V_5 -> V_30 ) ;
V_28:
F_20 ( V_2 -> V_9 ) ;
return V_13 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_31 )
F_22 ( V_5 -> V_31 ) ;
}
static int F_23 ( struct V_1 * V_9 ,
struct V_32 * V_33 , bool V_34 )
{
return F_24 ( V_9 , V_33 , false ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
V_2 -> V_35 . V_36 = 0 ;
V_2 -> V_35 . V_37 = 0 ;
V_2 -> V_35 . V_38 = V_39 ;
V_2 -> V_35 . V_40 = V_41 ;
V_2 -> V_35 . V_42 = & V_43 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_28 ( V_5 -> V_31 ) ;
}
static T_2 F_29 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_46 ;
V_46 = F_11 ( V_5 , V_47 ) ;
#ifdef F_6
if ( V_46 & V_48 )
F_30 ( & V_5 -> V_15 ) ;
if ( V_46 & V_49 )
F_30 ( & V_5 -> V_18 ) ;
if ( V_46 & V_50 )
F_30 ( & V_5 -> V_16 ) ;
if ( V_46 & V_51 )
F_30 ( & V_5 -> V_17 ) ;
#endif
if ( V_46 & V_51 )
F_31 ( & V_5 -> V_30 ) ;
F_32 ( V_5 , V_52 , V_46 ) ;
return V_53 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_32 ( V_5 , V_54 , 0 ) ;
F_32 ( V_5 , V_52 , ~ 0 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
#ifdef F_6
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_55 = F_11 ( V_5 , V_54 ) ;
V_55 |= V_56 ;
F_32 ( V_5 , V_54 , V_55 ) ;
#endif
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_55 = F_11 ( V_5 , V_54 ) ;
#ifdef F_6
V_55 &= ~ V_56 ;
#endif
V_55 &= ~ V_51 ;
F_32 ( V_5 , V_54 , V_55 ) ;
}
static int F_36 ( struct V_1 * V_2 , unsigned int V_30 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_57 = F_11 ( V_5 , V_54 ) ;
F_32 ( V_5 , V_54 , V_57 | V_51 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , unsigned int V_30 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_57 = F_11 ( V_5 , V_54 ) ;
F_32 ( V_5 , V_54 , V_57 & ~ V_51 ) ;
}
static int F_38 ( struct V_58 * V_59 , void * V_45 )
{
struct V_60 * V_61 = (struct V_60 * ) V_59 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_63 -> V_9 ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_39 ( V_59 , L_7 , F_40 ( & V_5 -> V_15 ) ) ;
F_39 ( V_59 , L_8 , F_40 ( & V_5 -> V_18 ) ) ;
F_39 ( V_59 , L_9 , F_40 ( & V_5 -> V_16 ) ) ;
F_39 ( V_59 , L_10 , F_40 ( & V_5 -> V_17 ) ) ;
return 0 ;
}
static int F_41 ( struct V_58 * V_59 , void * V_45 )
{
struct V_60 * V_61 = (struct V_60 * ) V_59 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_63 -> V_9 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_64 = F_42 ( V_5 -> V_14 ) ;
unsigned long V_65 = V_5 -> V_30 . V_66 . V_67 * 1000 ;
F_39 ( V_59 , L_11 , V_64 ) ;
F_39 ( V_59 , L_12 , V_65 ) ;
return 0 ;
}
static int F_43 ( struct V_68 * V_63 )
{
return F_44 ( V_69 ,
F_45 ( V_69 ) , V_63 -> V_70 , V_63 ) ;
}
static void F_46 ( struct V_68 * V_63 )
{
F_47 ( V_69 ,
F_45 ( V_69 ) , V_63 ) ;
}
static int F_48 ( struct V_71 * V_9 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_13 ;
V_5 = F_49 ( V_9 , sizeof( * V_5 ) , V_72 ) ;
if ( ! V_5 )
return - V_73 ;
V_2 = F_50 ( & V_74 , V_9 ) ;
if ( ! V_2 )
return - V_73 ;
V_2 -> V_6 = V_5 ;
F_51 ( V_9 , V_2 ) ;
F_25 ( V_2 ) ;
V_13 = F_1 ( V_2 , 0 ) ;
if ( V_13 )
goto V_75;
V_13 = F_52 ( V_2 , 0 ) ;
if ( V_13 )
goto V_76;
V_13 = F_53 ( V_9 , V_2 ) ;
if ( V_13 ) {
F_10 ( L_13 ) ;
goto V_77;
}
V_13 = F_54 ( V_9 ) ;
if ( V_13 )
goto V_78;
F_55 ( V_9 ) ;
V_13 = F_56 ( V_2 , V_2 -> V_35 . V_79 ) ;
if ( V_13 < 0 ) {
F_10 ( L_14 ) ;
goto V_80;
}
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
V_5 -> V_31 = F_59 ( V_2 , 32 , V_2 -> V_35 . V_79 ,
V_2 -> V_35 . V_81 ) ;
if ( F_4 ( V_5 -> V_31 ) ) {
V_13 = F_5 ( V_5 -> V_31 ) ;
V_5 -> V_31 = NULL ;
goto V_82;
}
return 0 ;
V_82:
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
V_80:
F_63 ( V_2 -> V_9 ) ;
V_78:
F_64 ( V_9 , V_2 ) ;
V_77:
F_65 ( V_2 ) ;
V_76:
F_66 ( V_2 ) ;
F_20 ( V_2 -> V_9 ) ;
V_75:
F_51 ( V_9 , NULL ) ;
F_67 ( V_2 ) ;
return V_13 ;
}
static void F_68 ( struct V_71 * V_9 )
{
struct V_1 * V_2 = F_69 ( V_9 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_31 ) {
F_70 ( V_5 -> V_31 ) ;
V_5 -> V_31 = NULL ;
}
F_60 ( V_2 ) ;
F_64 ( V_9 , V_2 ) ;
F_62 ( V_2 ) ;
F_71 ( V_2 -> V_9 ) ;
F_66 ( V_2 ) ;
F_72 ( V_2 -> V_9 ) ;
F_63 ( V_2 -> V_9 ) ;
F_20 ( V_2 -> V_9 ) ;
F_61 ( V_2 ) ;
F_65 ( V_2 ) ;
F_67 ( V_2 ) ;
V_2 -> V_6 = NULL ;
F_51 ( V_9 , NULL ) ;
}
static int F_73 ( struct V_71 * V_9 , void * V_83 )
{
return V_9 -> V_84 == V_83 ;
}
static int F_74 ( struct V_7 * V_8 )
{
struct V_85 * V_86 , * V_87 ;
struct V_88 * V_89 = NULL ;
if ( ! V_8 -> V_9 . V_84 )
return - V_27 ;
V_87 = F_75 ( V_8 -> V_9 . V_84 , NULL ) ;
if ( ! V_87 )
return - V_27 ;
if ( ! F_76 ( V_87 ) ) {
F_77 ( V_87 ) ;
return - V_27 ;
}
V_86 = F_78 ( V_87 ) ;
F_77 ( V_87 ) ;
if ( ! V_86 || ! F_76 ( V_86 ) ) {
F_77 ( V_86 ) ;
return - V_90 ;
}
F_79 ( & V_8 -> V_9 , & V_89 , F_73 , V_86 ) ;
return F_80 ( & V_8 -> V_9 , & V_91 ,
V_89 ) ;
}
static int F_81 ( struct V_7 * V_8 )
{
F_82 ( & V_8 -> V_9 , & V_91 ) ;
return 0 ;
}
static int T_3 F_83 ( struct V_71 * V_9 )
{
struct V_1 * V_2 = F_69 ( V_9 ) ;
struct V_4 * V_5 = V_2 ? V_2 -> V_6 : NULL ;
if ( ! V_5 )
return 0 ;
F_84 ( V_2 ) ;
V_5 -> V_33 = F_85 ( V_2 ) ;
if ( F_4 ( V_5 -> V_33 ) ) {
F_86 ( V_2 ) ;
return F_5 ( V_5 -> V_33 ) ;
}
return 0 ;
}
static int T_3 F_87 ( struct V_71 * V_9 )
{
struct V_1 * V_2 = F_69 ( V_9 ) ;
struct V_4 * V_5 = V_2 ? V_2 -> V_6 : NULL ;
if ( ! V_5 )
return 0 ;
F_88 ( V_2 , V_5 -> V_33 ) ;
F_86 ( V_2 ) ;
F_54 ( V_9 ) ;
return 0 ;
}
