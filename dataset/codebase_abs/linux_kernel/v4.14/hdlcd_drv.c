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
F_22 ( V_5 -> V_31 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
V_2 -> V_32 . V_33 = 0 ;
V_2 -> V_32 . V_34 = 0 ;
V_2 -> V_32 . V_35 = V_36 ;
V_2 -> V_32 . V_37 = V_38 ;
V_2 -> V_32 . V_39 = & V_40 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_26 ( V_5 -> V_31 ) ;
}
static T_2 F_27 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_43 ;
V_43 = F_11 ( V_5 , V_44 ) ;
#ifdef F_6
if ( V_43 & V_45 )
F_28 ( & V_5 -> V_15 ) ;
if ( V_43 & V_46 )
F_28 ( & V_5 -> V_18 ) ;
if ( V_43 & V_47 )
F_28 ( & V_5 -> V_16 ) ;
if ( V_43 & V_48 )
F_28 ( & V_5 -> V_17 ) ;
#endif
if ( V_43 & V_48 )
F_29 ( & V_5 -> V_30 ) ;
F_30 ( V_5 , V_49 , V_43 ) ;
return V_50 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_30 ( V_5 , V_51 , 0 ) ;
F_30 ( V_5 , V_49 , ~ 0 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
#ifdef F_6
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_52 = F_11 ( V_5 , V_51 ) ;
V_52 |= V_53 ;
F_30 ( V_5 , V_51 , V_52 ) ;
#endif
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_52 = F_11 ( V_5 , V_51 ) ;
#ifdef F_6
V_52 &= ~ V_53 ;
#endif
V_52 &= ~ V_48 ;
F_30 ( V_5 , V_51 , V_52 ) ;
}
static int F_34 ( struct V_54 * V_55 , void * V_42 )
{
struct V_56 * V_57 = (struct V_56 * ) V_55 -> V_58 ;
struct V_1 * V_2 = V_57 -> V_59 -> V_9 ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_35 ( V_55 , L_7 , F_36 ( & V_5 -> V_15 ) ) ;
F_35 ( V_55 , L_8 , F_36 ( & V_5 -> V_18 ) ) ;
F_35 ( V_55 , L_9 , F_36 ( & V_5 -> V_16 ) ) ;
F_35 ( V_55 , L_10 , F_36 ( & V_5 -> V_17 ) ) ;
return 0 ;
}
static int F_37 ( struct V_54 * V_55 , void * V_42 )
{
struct V_56 * V_57 = (struct V_56 * ) V_55 -> V_58 ;
struct V_1 * V_2 = V_57 -> V_59 -> V_9 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_60 = F_38 ( V_5 -> V_14 ) ;
unsigned long V_61 = V_5 -> V_30 . V_62 . V_63 * 1000 ;
F_35 ( V_55 , L_11 , V_60 ) ;
F_35 ( V_55 , L_12 , V_61 ) ;
return 0 ;
}
static int F_39 ( struct V_64 * V_59 )
{
return F_40 ( V_65 ,
F_41 ( V_65 ) , V_59 -> V_66 , V_59 ) ;
}
static int F_42 ( struct V_67 * V_9 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_13 ;
V_5 = F_43 ( V_9 , sizeof( * V_5 ) , V_68 ) ;
if ( ! V_5 )
return - V_69 ;
V_2 = F_44 ( & V_70 , V_9 ) ;
if ( F_4 ( V_2 ) )
return F_5 ( V_2 ) ;
V_2 -> V_6 = V_5 ;
F_45 ( V_9 , V_2 ) ;
F_23 ( V_2 ) ;
V_13 = F_1 ( V_2 , 0 ) ;
if ( V_13 )
goto V_71;
V_5 -> V_30 . V_72 = F_46 ( V_9 -> V_73 , 0 ) ;
V_13 = F_47 ( V_9 , V_2 ) ;
if ( V_13 ) {
F_10 ( L_13 ) ;
goto V_74;
}
V_13 = F_48 ( V_9 ) ;
if ( V_13 )
goto V_75;
F_49 ( V_9 ) ;
V_13 = F_50 ( V_2 , V_2 -> V_32 . V_76 ) ;
if ( V_13 < 0 ) {
F_10 ( L_14 ) ;
goto V_77;
}
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_5 -> V_31 = F_53 ( V_2 , 32 ,
V_2 -> V_32 . V_78 ) ;
if ( F_4 ( V_5 -> V_31 ) ) {
V_13 = F_5 ( V_5 -> V_31 ) ;
V_5 -> V_31 = NULL ;
goto V_79;
}
V_13 = F_54 ( V_2 , 0 ) ;
if ( V_13 )
goto V_80;
return 0 ;
V_80:
if ( V_5 -> V_31 ) {
F_55 ( V_5 -> V_31 ) ;
V_5 -> V_31 = NULL ;
}
V_79:
F_56 ( V_2 ) ;
V_77:
F_57 ( V_2 -> V_9 ) ;
V_75:
F_58 ( V_9 , V_2 ) ;
V_74:
F_59 ( V_5 -> V_30 . V_72 ) ;
V_5 -> V_30 . V_72 = NULL ;
F_60 ( V_2 ) ;
F_20 ( V_2 -> V_9 ) ;
V_71:
F_61 ( V_2 ) ;
F_45 ( V_9 , NULL ) ;
F_62 ( V_2 ) ;
return V_13 ;
}
static void F_63 ( struct V_67 * V_9 )
{
struct V_1 * V_2 = F_64 ( V_9 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_65 ( V_2 ) ;
if ( V_5 -> V_31 ) {
F_55 ( V_5 -> V_31 ) ;
V_5 -> V_31 = NULL ;
}
F_56 ( V_2 ) ;
F_58 ( V_9 , V_2 ) ;
F_59 ( V_5 -> V_30 . V_72 ) ;
V_5 -> V_30 . V_72 = NULL ;
F_66 ( V_2 -> V_9 ) ;
F_60 ( V_2 ) ;
F_67 ( V_2 -> V_9 ) ;
F_57 ( V_2 -> V_9 ) ;
F_20 ( V_2 -> V_9 ) ;
F_61 ( V_2 ) ;
F_62 ( V_2 ) ;
V_2 -> V_6 = NULL ;
F_45 ( V_9 , NULL ) ;
}
static int F_68 ( struct V_67 * V_9 , void * V_81 )
{
return V_9 -> V_73 == V_81 ;
}
static int F_69 ( struct V_7 * V_8 )
{
struct V_82 * V_72 ;
struct V_83 * V_84 = NULL ;
V_72 = F_70 ( V_8 -> V_9 . V_73 , 0 , 0 ) ;
if ( ! V_72 )
return - V_27 ;
F_71 ( & V_8 -> V_9 , & V_84 , F_68 , V_72 ) ;
F_59 ( V_72 ) ;
return F_72 ( & V_8 -> V_9 , & V_85 ,
V_84 ) ;
}
static int F_73 ( struct V_7 * V_8 )
{
F_74 ( & V_8 -> V_9 , & V_85 ) ;
return 0 ;
}
static int T_3 F_75 ( struct V_67 * V_9 )
{
struct V_1 * V_2 = F_64 ( V_9 ) ;
struct V_4 * V_5 = V_2 ? V_2 -> V_6 : NULL ;
if ( ! V_5 )
return 0 ;
F_76 ( V_2 ) ;
V_5 -> V_86 = F_77 ( V_2 ) ;
if ( F_4 ( V_5 -> V_86 ) ) {
F_78 ( V_2 ) ;
return F_5 ( V_5 -> V_86 ) ;
}
return 0 ;
}
static int T_3 F_79 ( struct V_67 * V_9 )
{
struct V_1 * V_2 = F_64 ( V_9 ) ;
struct V_4 * V_5 = V_2 ? V_2 -> V_6 : NULL ;
if ( ! V_5 )
return 0 ;
F_80 ( V_2 , V_5 -> V_86 ) ;
F_78 ( V_2 ) ;
F_48 ( V_9 ) ;
return 0 ;
}
