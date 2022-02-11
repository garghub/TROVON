static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_4 -> V_6 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_4 -> V_7 ) ;
if ( V_5 )
goto V_8;
V_5 = F_5 ( V_4 -> V_7 ) ;
if ( V_5 )
goto V_9;
return 0 ;
V_9:
F_6 ( V_4 -> V_7 ) ;
V_8:
F_7 ( V_4 -> V_6 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( V_4 -> V_7 ) ;
F_6 ( V_4 -> V_7 ) ;
F_7 ( V_4 -> V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
struct V_15 * V_16 = F_11 ( V_12 ) ;
int V_5 ;
if ( V_16 && V_16 -> V_17 )
return V_16 -> V_17 ( 1 , V_10 ) ;
if ( ! V_4 -> V_18 )
return 0 ;
if ( V_10 && ! V_4 -> V_19 ) {
V_5 = F_12 ( V_4 -> V_18 ) ;
if ( V_5 ) {
F_13 ( V_12 , L_1 , V_5 ) ;
return V_5 ;
}
V_4 -> V_19 = 1 ;
} else if ( ! V_10 && V_4 -> V_19 ) {
V_5 = F_14 ( V_4 -> V_18 ) ;
if ( V_5 ) {
F_13 ( V_12 , L_2 , V_5 ) ;
return V_5 ;
}
V_4 -> V_19 = 0 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
struct V_15 * V_16 = F_11 ( V_12 ) ;
if ( V_16 && V_16 -> V_20 )
return V_16 -> V_20 ( 1 ) ;
if ( V_4 -> V_18 )
return F_16 ( V_4 -> V_18 ) ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
struct V_15 * V_16 = F_11 ( V_12 ) ;
unsigned int V_21 ;
int V_5 ;
if ( V_16 && V_16 -> V_22 )
return V_16 -> V_22 ( 1 ) ;
if ( ! V_4 -> V_18 )
return 0 ;
V_5 = F_18 ( V_4 -> V_18 , & V_21 ) ;
if ( V_5 )
return V_5 ;
if ( V_21 & V_23 )
return 1 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
struct V_15 * V_16 = F_11 ( V_12 ) ;
if ( V_16 && V_16 -> V_17 )
return 1 ;
if ( V_4 -> V_18 )
return 1 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
struct V_15 * V_16 = F_11 ( V_12 ) ;
if ( V_16 && V_16 -> V_22 )
return 1 ;
if ( V_4 -> V_18 )
return 1 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
struct V_15 * V_16 = F_11 ( V_12 ) ;
if ( V_16 && V_16 -> V_24 )
return 1 ;
return 0 ;
}
static void F_22 ( struct V_15 * V_16 ,
unsigned V_25 )
{
V_26 |= 1 << V_25 ;
if ( V_16 -> V_22 ( V_25 ) > 0 )
V_16 -> V_17 ( V_25 , 0 ) ;
}
static int F_23 ( struct V_27 * V_28 ,
unsigned long V_29 , void * V_30 )
{
struct V_3 * V_4 =
F_24 ( V_28 , struct V_3 , V_28 ) ;
if ( V_29 & V_31 ) {
V_26 |= 1 << 1 ;
F_10 ( V_4 -> V_2 , 0 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
struct V_15 * V_16 = F_11 ( V_12 ) ;
int V_5 = 0 ;
if ( V_16 && V_16 -> V_32 ) {
V_5 = V_16 -> V_32 ( F_22 ) ;
} else if ( V_4 -> V_18 ) {
V_4 -> V_28 . V_33 = F_23 ;
V_5 = F_26 ( V_4 -> V_18 ,
& V_4 -> V_28 ) ;
}
if ( V_5 )
F_13 ( V_12 , L_3 , V_5 ) ;
return V_5 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
struct V_15 * V_16 = F_11 ( V_12 ) ;
if ( V_16 && V_16 -> V_32 )
V_16 -> V_32 ( NULL ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
struct V_15 * V_16 = F_11 ( V_12 ) ;
struct V_34 * V_35 = F_29 ( V_2 ) ;
int V_36 ;
T_1 V_37 ;
F_30 ( V_12 , L_4 ) ;
V_36 = F_1 ( V_2 ) ;
if ( V_36 < 0 )
return V_36 ;
V_35 -> V_38 = 1 ;
V_36 = F_31 ( V_2 ) ;
if ( V_36 < 0 ) {
F_8 ( V_2 ) ;
return V_36 ;
}
V_37 = F_32 ( V_35 , & V_35 -> V_39 -> V_40 . V_41 ) ;
if ( F_19 ( V_2 ) ) {
V_37 &= ~ V_42 ;
V_37 |= V_43 ;
}
if ( F_20 ( V_2 ) ) {
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
}
if ( F_21 ( V_2 ) ) {
V_37 &= ~ V_46 ;
V_37 |= V_16 -> V_24 << 24 ;
}
F_33 ( V_35 , V_37 , & V_35 -> V_39 -> V_40 . V_41 ) ;
return V_36 ;
}
static int F_34 ( struct V_1 * V_2 , char * V_47 )
{
int V_48 = F_35 ( V_2 , V_47 ) ;
if ( V_26 & ( 1 << 1 ) ) {
F_30 ( V_2 -> V_13 . V_14 , L_5
L_6 ) ;
if ( ! V_48 )
V_48 = 1 ;
V_47 [ 0 ] |= 1 << 1 ;
}
return V_48 ;
}
static int F_36 ( struct V_1 * V_2 , T_2 V_49 , T_2 V_50 ,
T_2 V_51 , char * V_47 , T_2 V_52 )
{
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
int V_53 ;
switch ( V_49 ) {
case V_54 :
if ( V_51 != 1 )
break;
F_30 ( V_12 , L_7 , V_51 ) ;
V_53 = F_37 ( F_29 ( V_2 ) , V_51 - 1 ) ;
if ( ! F_15 ( V_2 ) )
V_53 &= ~ V_55 ;
if ( F_17 ( V_2 ) > 0 )
V_53 |= V_56 ;
if ( V_26 & ( 1 << V_51 ) )
V_53 |= V_57 ;
F_38 ( F_39 ( V_53 ) , ( V_58 * ) V_47 ) ;
return 0 ;
case V_59 :
V_53 = 1 ;
goto V_60;
case V_61 :
V_53 = 0 ;
V_60:
if ( V_51 != 1 )
break;
switch ( V_50 ) {
case V_62 :
F_30 ( V_12 , L_8 ,
V_53 ? L_9 : L_10 , V_51 , L_11 ) ;
return F_10 ( V_2 , V_53 ) ? - V_63 : 0 ;
case V_64 :
F_30 ( V_12 , L_8 ,
V_53 ? L_9 : L_10 , V_51 ,
L_12 ) ;
if ( V_53 )
V_26 |= 1 << V_51 ;
else
V_26 &= ~ ( 1 << V_51 ) ;
return 0 ;
}
}
return F_40 ( V_2 , V_49 , V_50 ,
V_51 , V_47 , V_52 ) ;
}
static int F_41 ( struct V_65 * V_66 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
int error , V_69 ;
V_2 = F_42 ( & V_70 , & V_66 -> V_12 ,
F_43 ( & V_66 -> V_12 ) ) ;
if ( ! V_2 )
return - V_71 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_6 = F_44 ( & V_66 -> V_12 , L_13 ) ;
if ( F_45 ( V_4 -> V_6 ) ) {
error = F_46 ( V_4 -> V_6 ) ;
if ( error != - V_72 )
F_13 ( & V_66 -> V_12 , L_14 ) ;
goto V_73;
}
V_4 -> V_7 = F_47 ( & V_66 -> V_12 , L_15 ) ;
if ( F_45 ( V_4 -> V_7 ) ) {
error = F_46 ( V_4 -> V_7 ) ;
if ( error != - V_72 )
F_13 ( & V_66 -> V_12 , L_16 ) ;
goto V_73;
}
V_4 -> V_18 = F_48 ( & V_66 -> V_12 , L_17 ) ;
if ( F_45 ( V_4 -> V_18 ) ) {
error = F_46 ( V_4 -> V_18 ) ;
if ( error == - V_74 ) {
V_4 -> V_18 = NULL ;
} else if ( error == - V_72 ) {
goto V_73;
} else {
F_13 ( & V_66 -> V_12 , L_18 ) ;
goto V_73;
}
}
V_68 = F_49 ( V_66 , V_75 , 0 ) ;
V_2 -> V_39 = F_50 ( & V_66 -> V_12 , V_68 ) ;
if ( F_45 ( V_2 -> V_39 ) ) {
error = F_46 ( V_2 -> V_39 ) ;
goto V_73;
}
V_2 -> V_76 = V_68 -> V_77 ;
V_2 -> V_78 = F_51 ( V_68 ) ;
V_69 = F_52 ( V_66 , 0 ) ;
if ( V_69 < 0 ) {
error = - V_74 ;
goto V_73;
}
error = F_53 ( V_2 , V_69 , 0 ) ;
if ( error )
goto V_73;
F_54 ( V_2 -> V_13 . V_14 ) ;
error = F_25 ( V_2 ) ;
if ( error )
goto V_79;
return 0 ;
V_79:
F_55 ( V_2 ) ;
V_73:
F_56 ( V_2 ) ;
return error ;
}
static int F_57 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_58 ( V_66 ) ;
F_27 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_65 * V_66 ,
T_3 V_80 )
{
struct V_1 * V_2 = F_58 ( V_66 ) ;
struct V_34 * V_35 = F_29 ( V_2 ) ;
bool V_81 = F_60 ( & V_66 -> V_12 ) ;
int V_5 ;
if ( F_61 ( V_82 , V_35 -> V_83 ) )
F_62 ( 5 ) ;
V_35 -> V_83 = V_82 ;
V_5 = F_63 ( V_2 , V_81 ) ;
if ( V_5 )
return V_5 ;
F_8 ( V_2 ) ;
V_2 -> V_84 = V_85 ;
return V_5 ;
}
static int F_64 ( struct V_65 * V_12 )
{
struct V_1 * V_2 = F_58 ( V_12 ) ;
struct V_34 * V_35 = F_29 ( V_2 ) ;
int V_5 ;
if ( F_61 ( V_82 , V_35 -> V_83 ) )
F_62 ( 5 ) ;
V_35 -> V_83 = V_82 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_65 ( V_2 , false ) ;
return 0 ;
}
static int T_4 F_66 ( void )
{
if ( F_67 () )
return - V_74 ;
F_68 ( L_19 V_86 L_20 , V_87 ) ;
F_69 ( & V_70 , & V_88 ) ;
F_40 = V_70 . V_89 ;
F_35 = V_70 . V_90 ;
V_70 . V_90 = F_34 ;
V_70 . V_89 = F_36 ;
return F_70 ( & V_91 ) ;
}
static void T_5 F_71 ( void )
{
F_72 ( & V_91 ) ;
}
