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
int V_14 ;
unsigned long V_6 ;
V_14 = F_11 ( V_5 -> V_2 . V_15 ,
V_16 ) ;
if ( V_14 ) {
F_12 ( V_5 -> V_7 , L_4 ) ;
return;
}
F_5 ( & V_5 -> V_8 , V_6 ) ;
if ( V_5 -> V_9 == V_10 )
F_13 ( V_5 -> V_7 ) ;
else
F_14 ( V_5 -> V_7 ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
F_16 ( V_5 -> V_17 ) ;
F_17 ( 10 , 20 ) ;
F_18 ( V_5 -> V_17 ) ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_2 ( V_19 ) ;
int V_14 ;
F_20 ( & V_5 -> V_11 ) ;
V_14 = F_21 ( V_5 -> V_20 ) ;
if ( V_14 < 0 ) {
F_12 ( V_5 -> V_7 , L_5 , V_14 ) ;
return V_14 ;
}
V_14 = F_15 ( V_5 ) ;
if ( V_14 < 0 ) {
F_12 ( V_5 -> V_7 , L_6 , V_14 ) ;
F_22 ( V_5 -> V_20 ) ;
return V_14 ;
}
return 0 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_2 ( V_19 ) ;
F_22 ( V_5 -> V_20 ) ;
return 0 ;
}
static int F_24 ( struct V_18 * V_19 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
T_1 V_26 = V_27 | V_28 ;
if ( ( V_24 -> V_29 & V_26 ) ) {
F_25 ( L_7 ) ;
V_24 -> V_29 &= ~ V_26 ;
V_24 -> V_29 |= V_30 ;
V_24 -> V_31 = 8 ;
}
return 0 ;
}
static bool
F_26 ( struct V_1 * V_2 ,
const struct V_32 * V_33 ,
struct V_32 * V_34 )
{
return true ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_32 * V_35 )
{
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_14 ;
T_1 V_36 ;
V_14 = F_29 ( V_5 -> V_7 -> V_37 , V_2 ) ;
if ( V_14 < 0 )
return;
if ( V_14 )
V_36 = V_5 -> V_38 -> V_39 ;
else
V_36 = V_5 -> V_38 -> V_40 ;
F_4 ( V_5 -> V_7 , L_8 , ( V_14 ) ? L_9 : L_10 ) ;
V_14 = F_21 ( V_5 -> V_41 ) ;
if ( V_14 < 0 ) {
F_12 ( V_5 -> V_7 , L_11 , V_14 ) ;
return;
}
V_14 = F_30 ( V_5 -> V_42 , V_5 -> V_38 -> V_43 , V_36 ) ;
if ( V_14 != 0 )
F_12 ( V_5 -> V_7 , L_12 , V_14 ) ;
F_22 ( V_5 -> V_41 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = F_33 ( V_45 ) ;
V_49 -> V_50 = V_51 ;
V_49 -> V_52 = V_53 ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
}
static int F_36 ( struct V_4 * V_5 )
{
struct V_54 * V_7 = V_5 -> V_7 ;
struct V_55 * V_56 = V_7 -> V_37 ;
int V_14 ;
V_5 -> V_42 = F_37 ( V_56 , L_13 ) ;
if ( F_38 ( V_5 -> V_42 ) ) {
F_12 ( V_7 , L_14 ) ;
return F_39 ( V_5 -> V_42 ) ;
}
V_5 -> V_41 = F_40 ( V_7 , L_15 ) ;
if ( F_39 ( V_5 -> V_41 ) == - V_57 ) {
V_5 -> V_41 = NULL ;
} else if ( F_39 ( V_5 -> V_41 ) == - V_58 ) {
return - V_58 ;
} else if ( F_38 ( V_5 -> V_41 ) ) {
F_12 ( V_7 , L_16 ) ;
return F_39 ( V_5 -> V_41 ) ;
}
V_5 -> V_20 = F_40 ( V_7 , L_17 ) ;
if ( F_38 ( V_5 -> V_20 ) ) {
F_12 ( V_7 , L_18 ) ;
return F_39 ( V_5 -> V_20 ) ;
}
V_5 -> V_17 = F_41 ( V_7 , L_19 ) ;
if ( F_38 ( V_5 -> V_17 ) ) {
F_12 ( V_7 , L_20 ) ;
return F_39 ( V_5 -> V_17 ) ;
}
V_14 = F_21 ( V_5 -> V_20 ) ;
if ( V_14 < 0 ) {
F_12 ( V_5 -> V_7 , L_5 , V_14 ) ;
return V_14 ;
}
V_14 = F_15 ( V_5 ) ;
if ( V_14 < 0 ) {
F_12 ( V_5 -> V_7 , L_21 , V_14 ) ;
F_22 ( V_5 -> V_20 ) ;
return V_14 ;
}
return 0 ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_59 * V_60 = V_5 -> V_60 ;
struct V_54 * V_7 = V_5 -> V_7 ;
int V_14 ;
V_2 -> V_61 = F_43 ( V_60 ,
V_7 -> V_37 ) ;
F_25 ( L_22 , V_2 -> V_61 ) ;
V_14 = F_44 ( V_60 , V_2 , & V_62 ,
V_63 , NULL ) ;
if ( V_14 ) {
F_45 ( L_23 ) ;
return V_14 ;
}
F_46 ( V_2 , & V_64 ) ;
return 0 ;
}
static int F_47 ( struct V_54 * V_7 , struct V_54 * V_65 ,
void * V_38 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
const struct V_66 * V_67 ;
struct V_59 * V_60 = V_38 ;
int V_14 ;
F_49 ( V_7 , NULL ) ;
V_67 = F_50 ( V_7 ) ;
if ( ! V_67 )
return - V_68 ;
V_14 = F_36 ( V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_5 -> V_38 = V_67 ;
V_5 -> V_60 = V_60 ;
V_14 = F_42 ( V_5 ) ;
if ( V_14 ) {
F_45 ( L_24 ) ;
return V_14 ;
}
V_5 -> V_19 . V_2 = & V_5 -> V_2 ;
V_5 -> V_19 . V_69 = V_5 -> V_38 -> V_70 ;
V_5 -> V_19 . V_71 = F_19 ;
V_5 -> V_19 . V_72 = F_23 ;
V_5 -> V_19 . V_73 = F_24 ;
F_51 ( & V_5 -> V_8 ) ;
V_5 -> V_9 = ~ V_10 ;
F_52 ( & V_5 -> V_11 , F_8 ) ;
F_53 ( & V_5 -> V_2 , F_1 ) ;
return F_54 ( V_7 , V_5 -> V_60 , & V_5 -> V_19 ) ;
}
static void F_55 ( struct V_54 * V_7 , struct V_54 * V_65 ,
void * V_38 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
F_56 ( & V_5 -> V_2 ) ;
F_57 ( V_7 , V_65 , V_38 ) ;
F_22 ( V_5 -> V_20 ) ;
}
static int F_58 ( struct V_74 * V_75 )
{
struct V_54 * V_7 = & V_75 -> V_7 ;
struct V_76 * V_77 = NULL ;
struct V_4 * V_5 ;
int V_14 ;
V_14 = F_59 ( V_7 -> V_37 , 1 , 0 , & V_77 , NULL ) ;
if ( V_14 )
return V_14 ;
V_5 = F_60 ( V_7 , sizeof( * V_5 ) , V_78 ) ;
if ( ! V_5 )
return - V_79 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_19 . V_77 = V_77 ;
F_61 ( V_75 , V_5 ) ;
return F_62 ( V_7 , & V_80 ) ;
}
static int F_63 ( struct V_74 * V_75 )
{
F_64 ( & V_75 -> V_7 , & V_80 ) ;
return 0 ;
}
