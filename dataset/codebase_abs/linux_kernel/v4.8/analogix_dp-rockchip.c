static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( 10 , 20 ) ;
F_4 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
int V_6 ;
V_6 = F_7 ( V_2 -> V_7 ) ;
if ( V_6 < 0 ) {
F_8 ( V_2 -> V_8 , L_1 , V_6 ) ;
return V_6 ;
}
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 ) {
F_8 ( V_2 -> V_8 , L_2 , V_6 ) ;
F_9 ( V_2 -> V_7 ) ;
return V_6 ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_9 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_13 ;
T_1 V_14 = V_15 | V_16 ;
if ( ( V_12 -> V_17 & V_14 ) ) {
F_12 ( L_3 ) ;
V_12 -> V_17 &= ~ V_14 ;
V_12 -> V_17 |= V_18 ;
V_12 -> V_19 = 8 ;
}
return 0 ;
}
static bool
F_13 ( struct V_20 * V_21 ,
const struct V_22 * V_23 ,
struct V_22 * V_24 )
{
return true ;
}
static void F_14 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_22 * V_25 )
{
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_6 ( V_21 ) ;
int V_6 ;
T_1 V_26 ;
V_6 = F_16 ( V_2 -> V_8 -> V_27 , V_21 ) ;
if ( V_6 < 0 )
return;
if ( V_6 )
V_26 = V_2 -> V_28 -> V_29 ;
else
V_26 = V_2 -> V_28 -> V_30 ;
F_17 ( V_2 -> V_8 , L_4 , ( V_6 ) ? L_5 : L_6 ) ;
V_6 = F_7 ( V_2 -> V_31 ) ;
if ( V_6 < 0 ) {
F_8 ( V_2 -> V_8 , L_7 , V_6 ) ;
return;
}
V_6 = F_18 ( V_2 -> V_32 , V_2 -> V_28 -> V_33 , V_26 ) ;
if ( V_6 != 0 )
F_8 ( V_2 -> V_8 , L_8 , V_6 ) ;
F_9 ( V_2 -> V_31 ) ;
}
static void F_19 ( struct V_20 * V_21 )
{
}
static int
F_20 ( struct V_20 * V_21 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = F_21 ( V_35 ) ;
struct V_1 * V_2 = F_6 ( V_21 ) ;
int V_6 ;
V_39 -> V_40 = V_41 ;
V_39 -> V_42 = V_43 ;
if ( V_2 -> V_28 -> V_44 == V_45 ) {
V_6 = F_16 ( V_2 -> V_8 -> V_27 ,
V_21 ) ;
if ( V_6 > 0 )
V_39 -> V_40 = V_46 ;
}
return 0 ;
}
static void F_22 ( struct V_20 * V_21 )
{
F_23 ( V_21 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_47 * V_8 = V_2 -> V_8 ;
struct V_48 * V_49 = V_8 -> V_27 ;
int V_6 ;
V_2 -> V_32 = F_25 ( V_49 , L_9 ) ;
if ( F_26 ( V_2 -> V_32 ) ) {
F_8 ( V_8 , L_10 ) ;
return F_27 ( V_2 -> V_32 ) ;
}
V_2 -> V_31 = F_28 ( V_8 , L_11 ) ;
if ( F_27 ( V_2 -> V_31 ) == - V_50 ) {
V_2 -> V_31 = NULL ;
} else if ( F_27 ( V_2 -> V_31 ) == - V_51 ) {
return - V_51 ;
} else if ( F_26 ( V_2 -> V_31 ) ) {
F_8 ( V_8 , L_12 ) ;
return F_27 ( V_2 -> V_31 ) ;
}
V_2 -> V_7 = F_28 ( V_8 , L_13 ) ;
if ( F_26 ( V_2 -> V_7 ) ) {
F_8 ( V_8 , L_14 ) ;
return F_27 ( V_2 -> V_7 ) ;
}
V_2 -> V_3 = F_29 ( V_8 , L_15 ) ;
if ( F_26 ( V_2 -> V_3 ) ) {
F_8 ( V_8 , L_16 ) ;
return F_27 ( V_2 -> V_3 ) ;
}
V_6 = F_7 ( V_2 -> V_7 ) ;
if ( V_6 < 0 ) {
F_8 ( V_2 -> V_8 , L_1 , V_6 ) ;
return V_6 ;
}
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 ) {
F_8 ( V_2 -> V_8 , L_17 , V_6 ) ;
F_9 ( V_2 -> V_7 ) ;
return V_6 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
struct V_52 * V_53 = V_2 -> V_53 ;
struct V_47 * V_8 = V_2 -> V_8 ;
int V_6 ;
V_21 -> V_54 = F_31 ( V_53 ,
V_8 -> V_27 ) ;
F_12 ( L_18 , V_21 -> V_54 ) ;
V_6 = F_32 ( V_53 , V_21 , & V_55 ,
V_56 , NULL ) ;
if ( V_6 ) {
F_33 ( L_19 ) ;
return V_6 ;
}
F_34 ( V_21 , & V_57 ) ;
return 0 ;
}
static int F_35 ( struct V_47 * V_8 , struct V_47 * V_58 ,
void * V_28 )
{
struct V_1 * V_2 = F_36 ( V_8 ) ;
const struct V_59 * V_60 ;
struct V_52 * V_53 = V_28 ;
int V_6 ;
F_37 ( V_8 , NULL ) ;
V_60 = F_38 ( V_8 ) ;
if ( ! V_60 )
return - V_61 ;
V_6 = F_24 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_28 = V_60 ;
V_2 -> V_53 = V_53 ;
V_6 = F_30 ( V_2 ) ;
if ( V_6 ) {
F_33 ( L_20 ) ;
return V_6 ;
}
V_2 -> V_5 . V_21 = & V_2 -> V_21 ;
V_2 -> V_5 . V_62 = V_2 -> V_28 -> V_44 ;
V_2 -> V_5 . V_63 = F_5 ;
V_2 -> V_5 . V_64 = F_10 ;
V_2 -> V_5 . V_65 = F_11 ;
return F_39 ( V_8 , V_2 -> V_53 , & V_2 -> V_5 ) ;
}
static void F_40 ( struct V_47 * V_8 , struct V_47 * V_58 ,
void * V_28 )
{
return F_41 ( V_8 , V_58 , V_28 ) ;
}
static int F_42 ( struct V_66 * V_67 )
{
struct V_47 * V_8 = & V_67 -> V_8 ;
struct V_48 * V_68 , * V_69 , * V_70 ;
struct V_71 * V_72 = NULL ;
struct V_1 * V_2 ;
V_69 = F_43 ( V_8 -> V_27 , 1 ) ;
if ( V_69 ) {
V_70 = F_44 ( V_69 , L_21 ) ;
F_45 ( V_69 ) ;
if ( ! V_70 ) {
F_8 ( V_8 , L_22 ) ;
return - V_73 ;
}
V_68 = F_46 ( V_70 ) ;
F_45 ( V_70 ) ;
if ( ! V_68 ) {
F_8 ( V_8 , L_23 ) ;
return - V_73 ;
}
V_72 = F_47 ( V_68 ) ;
F_45 ( V_68 ) ;
if ( ! V_72 ) {
F_33 ( L_24 ) ;
return - V_51 ;
}
}
V_2 = F_48 ( V_8 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_5 . V_72 = V_72 ;
F_49 ( V_67 , V_2 ) ;
return F_50 ( V_8 , & V_76 ) ;
}
static int F_51 ( struct V_66 * V_67 )
{
F_52 ( & V_67 -> V_8 , & V_76 ) ;
return 0 ;
}
