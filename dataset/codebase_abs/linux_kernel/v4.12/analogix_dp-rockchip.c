static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
if ( ! F_3 ( V_5 -> V_7 ) )
return;
F_4 ( V_5 -> V_7 , L_1 , V_3 ? L_2 : L_3 ) ;
F_5 ( & V_5 -> V_8 , V_6 ) ;
if ( V_3 )
V_5 -> V_9 = V_10 ;
else
V_5 -> V_9 = ~ V_10 ;
F_6 ( & V_5 -> V_11 ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_4 * V_5 =
F_9 ( V_13 , F_10 ( * V_5 ) , V_11 ) ;
struct V_14 * V_15 = V_5 -> V_2 . V_15 ;
int V_9 = V_5 -> V_9 ;
int V_16 ;
int V_17 ;
unsigned long V_6 ;
if ( ! V_15 )
return;
V_16 = V_15 -> V_18 . V_19 - V_15 -> V_18 . V_20 + V_15 -> V_18 . V_21 ;
V_17 = F_11 ( V_5 -> V_2 . V_15 , V_16 ,
V_22 ) ;
if ( V_17 ) {
F_12 ( V_5 -> V_7 , L_4 ) ;
return;
}
F_5 ( & V_5 -> V_8 , V_6 ) ;
if ( V_9 == V_10 )
F_13 ( V_5 -> V_7 ) ;
else
F_14 ( V_5 -> V_7 ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
F_16 ( V_5 -> V_23 ) ;
F_17 ( 10 , 20 ) ;
F_18 ( V_5 -> V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_2 ( V_25 ) ;
int V_17 ;
F_20 ( & V_5 -> V_11 ) ;
V_17 = F_21 ( V_5 -> V_26 ) ;
if ( V_17 < 0 ) {
F_12 ( V_5 -> V_7 , L_5 , V_17 ) ;
return V_17 ;
}
V_17 = F_15 ( V_5 ) ;
if ( V_17 < 0 ) {
F_12 ( V_5 -> V_7 , L_6 , V_17 ) ;
F_22 ( V_5 -> V_26 ) ;
return V_17 ;
}
return 0 ;
}
static int F_23 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_2 ( V_25 ) ;
F_22 ( V_5 -> V_26 ) ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = & V_28 -> V_31 ;
T_1 V_32 = V_33 | V_34 ;
if ( ( V_30 -> V_35 & V_32 ) ) {
F_25 ( L_7 ) ;
V_30 -> V_35 &= ~ V_32 ;
V_30 -> V_35 |= V_36 ;
V_30 -> V_37 = 8 ;
}
return 0 ;
}
static bool
F_26 ( struct V_1 * V_2 ,
const struct V_38 * V_18 ,
struct V_38 * V_39 )
{
return true ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_38 * V_18 ,
struct V_38 * V_40 )
{
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_17 ;
T_1 V_41 ;
V_17 = F_29 ( V_5 -> V_7 -> V_42 , V_2 ) ;
if ( V_17 < 0 )
return;
if ( V_17 )
V_41 = V_5 -> V_43 -> V_44 ;
else
V_41 = V_5 -> V_43 -> V_45 ;
F_4 ( V_5 -> V_7 , L_8 , ( V_17 ) ? L_9 : L_10 ) ;
V_17 = F_21 ( V_5 -> V_46 ) ;
if ( V_17 < 0 ) {
F_12 ( V_5 -> V_7 , L_11 , V_17 ) ;
return;
}
V_17 = F_30 ( V_5 -> V_47 , V_5 -> V_43 -> V_48 , V_41 ) ;
if ( V_17 != 0 )
F_12 ( V_5 -> V_7 , L_12 , V_17 ) ;
F_22 ( V_5 -> V_46 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = F_33 ( V_50 ) ;
V_54 -> V_55 = V_56 ;
V_54 -> V_57 = V_58 ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
}
static int F_36 ( struct V_4 * V_5 )
{
struct V_59 * V_7 = V_5 -> V_7 ;
struct V_60 * V_61 = V_7 -> V_42 ;
int V_17 ;
V_5 -> V_47 = F_37 ( V_61 , L_13 ) ;
if ( F_38 ( V_5 -> V_47 ) ) {
F_12 ( V_7 , L_14 ) ;
return F_39 ( V_5 -> V_47 ) ;
}
V_5 -> V_46 = F_40 ( V_7 , L_15 ) ;
if ( F_39 ( V_5 -> V_46 ) == - V_62 ) {
V_5 -> V_46 = NULL ;
} else if ( F_39 ( V_5 -> V_46 ) == - V_63 ) {
return - V_63 ;
} else if ( F_38 ( V_5 -> V_46 ) ) {
F_12 ( V_7 , L_16 ) ;
return F_39 ( V_5 -> V_46 ) ;
}
V_5 -> V_26 = F_40 ( V_7 , L_17 ) ;
if ( F_38 ( V_5 -> V_26 ) ) {
F_12 ( V_7 , L_18 ) ;
return F_39 ( V_5 -> V_26 ) ;
}
V_5 -> V_23 = F_41 ( V_7 , L_19 ) ;
if ( F_38 ( V_5 -> V_23 ) ) {
F_12 ( V_7 , L_20 ) ;
return F_39 ( V_5 -> V_23 ) ;
}
V_17 = F_21 ( V_5 -> V_26 ) ;
if ( V_17 < 0 ) {
F_12 ( V_5 -> V_7 , L_5 , V_17 ) ;
return V_17 ;
}
V_17 = F_15 ( V_5 ) ;
if ( V_17 < 0 ) {
F_12 ( V_5 -> V_7 , L_21 , V_17 ) ;
F_22 ( V_5 -> V_26 ) ;
return V_17 ;
}
return 0 ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_64 * V_65 = V_5 -> V_65 ;
struct V_59 * V_7 = V_5 -> V_7 ;
int V_17 ;
V_2 -> V_66 = F_43 ( V_65 ,
V_7 -> V_42 ) ;
F_25 ( L_22 , V_2 -> V_66 ) ;
V_17 = F_44 ( V_65 , V_2 , & V_67 ,
V_68 , NULL ) ;
if ( V_17 ) {
F_45 ( L_23 ) ;
return V_17 ;
}
F_46 ( V_2 , & V_69 ) ;
return 0 ;
}
static int F_47 ( struct V_59 * V_7 , struct V_59 * V_70 ,
void * V_43 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
const struct V_71 * V_72 ;
struct V_64 * V_65 = V_43 ;
int V_17 ;
F_49 ( V_7 , NULL ) ;
V_72 = F_50 ( V_7 ) ;
if ( ! V_72 )
return - V_73 ;
V_17 = F_36 ( V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
V_5 -> V_43 = V_72 ;
V_5 -> V_65 = V_65 ;
V_17 = F_42 ( V_5 ) ;
if ( V_17 ) {
F_45 ( L_24 ) ;
return V_17 ;
}
V_5 -> V_25 . V_2 = & V_5 -> V_2 ;
V_5 -> V_25 . V_74 = V_5 -> V_43 -> V_75 ;
V_5 -> V_25 . V_76 = F_19 ;
V_5 -> V_25 . V_77 = F_23 ;
V_5 -> V_25 . V_78 = F_24 ;
F_51 ( & V_5 -> V_8 ) ;
V_5 -> V_9 = ~ V_10 ;
F_52 ( & V_5 -> V_11 , F_8 ) ;
F_53 ( & V_5 -> V_2 , F_1 ) ;
return F_54 ( V_7 , V_5 -> V_65 , & V_5 -> V_25 ) ;
}
static void F_55 ( struct V_59 * V_7 , struct V_59 * V_70 ,
void * V_43 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
F_56 ( & V_5 -> V_2 ) ;
F_57 ( V_7 , V_70 , V_43 ) ;
F_22 ( V_5 -> V_26 ) ;
}
static int F_58 ( struct V_79 * V_80 )
{
struct V_59 * V_7 = & V_80 -> V_7 ;
struct V_81 * V_82 = NULL ;
struct V_4 * V_5 ;
int V_17 ;
V_17 = F_59 ( V_7 -> V_42 , 1 , 0 , & V_82 , NULL ) ;
if ( V_17 )
return V_17 ;
V_5 = F_60 ( V_7 , sizeof( * V_5 ) , V_83 ) ;
if ( ! V_5 )
return - V_84 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_25 . V_82 = V_82 ;
F_61 ( V_80 , V_5 ) ;
return F_62 ( V_7 , & V_85 ) ;
}
static int F_63 ( struct V_79 * V_80 )
{
F_64 ( & V_80 -> V_7 , & V_85 ) ;
return 0 ;
}
