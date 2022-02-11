static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
T_1 V_12 = V_4 -> V_12 ;
T_2 V_13 = V_4 -> V_13 ;
T_3 V_14 = V_4 -> V_14 ;
int V_15 ;
if ( V_14 < 0 )
return - V_16 ;
if ( V_9 -> V_17 -> V_18 )
V_15 = F_4 ( V_11 , V_12 ,
F_5 ( V_5 , F_6 ( V_13 , 0 ) ,
V_14 ) ) ;
else
V_15 = F_7 ( V_11 , V_12 ,
F_6 ( V_14 + V_13 , V_14 ) ,
V_5 << V_14 ) ;
if ( V_15 )
F_8 ( L_1 ,
F_9 ( V_2 -> V_19 ) , V_15 ) ;
return V_15 ;
}
static unsigned int F_10 ( struct V_1 * V_2 )
{
T_1 div ;
unsigned long V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
div = F_11 ( V_2 -> V_21 + V_22 ) ;
div = ( div & V_23 ) >> V_24 ;
V_20 = F_12 ( V_7 -> V_25 ) ;
V_20 /= 1 << ( V_26 + div ) ;
return V_20 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
bool V_27 = false ;
if ( clock > V_28 && ( ! F_14 ( V_9 -> V_29 ) ) )
V_27 = true ;
if ( V_27 ) {
F_15 ( & V_2 -> V_30 ) ;
F_16 ( V_9 -> V_29 ) ;
F_17 ( & V_2 -> V_30 ) ;
}
F_18 ( V_2 , clock ) ;
if ( V_27 ) {
F_15 ( & V_2 -> V_30 ) ;
F_19 ( V_9 -> V_29 ) ;
F_17 ( & V_2 -> V_30 ) ;
}
}
static void F_20 ( struct V_31 * V_19 ,
struct V_32 * V_33 )
{
T_1 V_34 ;
struct V_1 * V_2 = F_21 ( V_19 ) ;
V_34 = F_11 ( V_2 -> V_21 + V_35 ) ;
if ( V_33 -> V_36 )
V_34 |= V_37 ;
else
V_34 &= ~ V_37 ;
F_22 ( V_34 , V_2 -> V_21 + V_35 ) ;
}
static int F_23 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_24 ( V_39 ) ;
struct V_1 * V_2 = F_25 ( V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_15 ;
V_15 = F_26 ( V_2 ) ;
if ( V_15 )
return V_15 ;
if ( ! F_14 ( V_9 -> V_29 ) ) {
V_15 = F_16 ( V_9 -> V_29 ) ;
if ( V_15 ) {
F_27 ( V_39 , L_2 ) ;
F_28 ( V_2 ) ;
return V_15 ;
}
}
F_29 ( V_7 -> V_25 ) ;
F_29 ( V_9 -> V_42 ) ;
return 0 ;
}
static int F_30 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_24 ( V_39 ) ;
struct V_1 * V_2 = F_25 ( V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_15 ;
V_15 = F_31 ( V_9 -> V_42 ) ;
if ( V_15 ) {
F_27 ( V_39 , L_3 ) ;
return V_15 ;
}
V_15 = F_31 ( V_7 -> V_25 ) ;
if ( V_15 ) {
F_27 ( V_39 , L_4 ) ;
return V_15 ;
}
if ( ! F_14 ( V_9 -> V_29 ) ) {
V_15 = F_19 ( V_9 -> V_29 ) ;
if ( V_15 ) {
F_27 ( V_39 , L_5 ) ;
return V_15 ;
}
}
return F_28 ( V_2 ) ;
}
static unsigned long F_32 ( struct V_43 * V_44 ,
unsigned long V_45 )
{
struct V_8 * V_9 =
F_33 ( V_44 , struct V_8 , V_46 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
return V_2 -> V_19 -> V_47 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_48 * V_17 =
V_9 -> V_17 ;
T_1 V_49 = F_35 ( F_12 ( V_7 -> V_25 ) , 1000000 ) ;
if ( ! V_17 )
return;
if ( ! V_9 -> V_11 ) {
F_8 ( L_6 ,
F_9 ( V_2 -> V_19 ) ) ;
return;
}
F_1 ( V_2 , & V_17 -> V_50 , V_49 ) ;
}
static int F_36 ( struct V_8 * V_9 ,
struct V_25 * V_51 ,
struct V_38 * V_39 )
{
struct V_52 * V_53 = V_39 -> V_54 ;
struct V_55 V_56 ;
const char * V_57 ;
int V_15 ;
if ( ! F_37 ( V_53 , L_7 , NULL ) )
return 0 ;
V_15 = F_38 ( V_53 , L_8 , 0 ,
& V_56 . V_58 ) ;
if ( V_15 ) {
F_27 ( V_39 , L_9 ) ;
return V_15 ;
}
V_57 = F_39 ( V_51 ) ;
V_56 . V_59 = & V_57 ;
V_56 . V_60 = 1 ;
V_56 . V_61 = V_62 ;
V_56 . V_63 = & V_64 ;
V_9 -> V_46 . V_65 = & V_56 ;
V_9 -> V_66 =
F_40 ( V_39 , & V_9 -> V_46 ) ;
V_9 -> V_46 . V_65 = NULL ;
V_15 = F_41 ( V_53 , V_67 ,
V_9 -> V_66 ) ;
if ( V_15 )
F_27 ( V_39 , L_10 ) ;
return V_15 ;
}
static void F_42 ( struct V_38 * V_39 )
{
struct V_52 * V_53 = V_39 -> V_54 ;
if ( ! F_37 ( V_53 , L_7 , NULL ) )
return;
F_43 ( V_39 -> V_54 ) ;
}
static int F_44 ( struct V_40 * V_41 )
{
int V_15 ;
const struct V_68 * V_69 ;
struct V_52 * V_70 ;
struct V_25 * V_51 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_2 = F_45 ( V_41 , & V_71 ,
sizeof( * V_9 ) ) ;
if ( F_14 ( V_2 ) )
return F_46 ( V_2 ) ;
V_7 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_7 ) ;
V_9 -> V_2 = V_2 ;
V_69 = F_47 ( V_72 , V_41 -> V_39 . V_54 ) ;
V_9 -> V_17 = V_69 -> V_73 ;
V_70 = F_48 ( V_41 -> V_39 . V_54 , L_11 , 0 ) ;
if ( V_70 ) {
V_9 -> V_11 = F_49 ( V_70 ) ;
F_50 ( V_70 ) ;
if ( F_14 ( V_9 -> V_11 ) ) {
V_15 = F_46 ( V_9 -> V_11 ) ;
if ( V_15 != - V_74 )
F_27 ( & V_41 -> V_39 , L_12 ,
V_15 ) ;
goto V_75;
}
}
V_9 -> V_42 = F_51 ( & V_41 -> V_39 , L_13 ) ;
if ( F_14 ( V_9 -> V_42 ) ) {
F_27 ( & V_41 -> V_39 , L_14 ) ;
V_15 = F_46 ( V_9 -> V_42 ) ;
goto V_75;
}
V_51 = F_51 ( & V_41 -> V_39 , L_15 ) ;
if ( F_14 ( V_51 ) ) {
F_27 ( & V_41 -> V_39 , L_16 ) ;
V_15 = F_46 ( V_51 ) ;
goto V_75;
}
V_15 = F_52 ( V_9 -> V_42 ) ;
if ( V_15 ) {
F_27 ( & V_41 -> V_39 , L_17 ) ;
goto V_75;
}
V_15 = F_52 ( V_51 ) ;
if ( V_15 ) {
F_27 ( & V_41 -> V_39 , L_18 ) ;
goto V_76;
}
F_53 ( V_41 ) ;
V_7 -> V_25 = V_51 ;
F_34 ( V_2 ) ;
V_15 = F_36 ( V_9 , V_51 , & V_41 -> V_39 ) ;
if ( V_15 )
goto V_77;
V_15 = F_54 ( V_2 -> V_19 ) ;
if ( V_15 ) {
F_27 ( & V_41 -> V_39 , L_19 , V_15 ) ;
goto V_78;
}
V_9 -> V_29 = F_55 ( - V_79 ) ;
if ( F_56 ( V_41 -> V_39 . V_54 ,
L_20 ) ) {
V_9 -> V_29 = F_57 ( & V_41 -> V_39 ,
L_21 ) ;
if ( F_14 ( V_9 -> V_29 ) ) {
V_15 = F_46 ( V_9 -> V_29 ) ;
F_27 ( & V_41 -> V_39 , L_22 ) ;
goto V_78;
}
V_15 = F_58 ( V_9 -> V_29 ) ;
if ( V_15 < 0 ) {
F_27 ( & V_41 -> V_39 , L_23 ) ;
goto V_78;
}
V_15 = F_19 ( V_9 -> V_29 ) ;
if ( V_15 < 0 ) {
F_27 ( & V_41 -> V_39 , L_24 ) ;
goto V_80;
}
V_2 -> V_81 . V_82 =
F_20 ;
}
V_15 = F_59 ( V_2 ) ;
if ( V_15 )
goto V_83;
return 0 ;
V_83:
if ( ! F_14 ( V_9 -> V_29 ) )
F_16 ( V_9 -> V_29 ) ;
V_80:
if ( ! F_14 ( V_9 -> V_29 ) )
F_60 ( V_9 -> V_29 ) ;
V_78:
F_42 ( & V_41 -> V_39 ) ;
V_77:
F_61 ( V_51 ) ;
V_76:
F_61 ( V_9 -> V_42 ) ;
V_75:
F_62 ( V_41 ) ;
return V_15 ;
}
static int F_63 ( struct V_40 * V_41 )
{
int V_15 ;
struct V_1 * V_2 = F_25 ( V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_25 * V_42 = V_9 -> V_42 ;
if ( ! F_14 ( V_9 -> V_29 ) ) {
F_16 ( V_9 -> V_29 ) ;
F_60 ( V_9 -> V_29 ) ;
}
F_42 ( & V_41 -> V_39 ) ;
V_15 = F_64 ( V_41 ) ;
F_61 ( V_42 ) ;
return V_15 ;
}
