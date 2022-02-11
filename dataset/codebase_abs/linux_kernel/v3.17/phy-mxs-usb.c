static inline bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 == & V_3 ;
}
static inline bool F_2 ( struct V_1 * V_1 )
{
return V_1 -> V_2 == & V_4 ;
}
static void F_3 ( void )
{
F_4 ( 300 , 400 ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_5 ;
void T_1 * V_6 = V_1 -> V_7 . V_8 ;
V_5 = F_6 ( V_6 + V_9 ) ;
if ( V_5 )
return V_5 ;
F_7 ( 0 , V_6 + V_10 ) ;
F_7 ( V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 |
V_17 ,
V_6 + V_18 ) ;
if ( V_1 -> V_2 -> V_19 & V_20 )
F_7 ( V_21 , V_6 + V_22 ) ;
return 0 ;
}
static bool F_8 ( struct V_1 * V_1 )
{
unsigned int V_23 ;
if ( V_1 -> V_24 == 0 )
F_9 ( V_1 -> V_25 ,
V_26 ,
& V_23 ) ;
else if ( V_1 -> V_24 == 1 )
F_9 ( V_1 -> V_25 ,
V_27 ,
& V_23 ) ;
if ( V_23 & V_28 )
return true ;
else
return false ;
}
static void F_10 ( struct V_1 * V_1 , bool V_29 )
{
void T_1 * V_6 = V_1 -> V_7 . V_8 ;
T_2 V_30 ;
if ( V_29 )
F_11 ( V_31 ,
V_6 + V_32 ) ;
if ( V_1 -> V_24 == 0 ) {
V_30 = V_29 ? V_33
: V_34 ;
F_12 ( V_1 -> V_25 , V_30 ,
V_35 |
V_36 ) ;
} else if ( V_1 -> V_24 == 1 ) {
V_30 = V_29 ? V_37
: V_38 ;
F_12 ( V_1 -> V_25 , V_30 ,
V_39 |
V_40 ) ;
}
if ( ! V_29 )
F_11 ( V_31 ,
V_6 + V_41 ) ;
if ( V_29 )
F_4 ( 500 , 1000 ) ;
}
static void F_13 ( struct V_1 * V_1 , bool V_42 )
{
bool V_43 = false ;
if ( ! ( V_1 -> V_2 -> V_19 & V_44 ) )
return;
if ( ! V_1 -> V_25 )
return;
V_43 = F_8 ( V_1 ) ;
if ( V_42 && ! V_43 )
F_10 ( V_1 , true ) ;
else
F_10 ( V_1 , false ) ;
}
static int F_14 ( struct V_45 * V_7 )
{
int V_5 ;
struct V_1 * V_1 = F_15 ( V_7 ) ;
F_3 () ;
V_5 = F_16 ( V_1 -> V_46 ) ;
if ( V_5 )
return V_5 ;
return F_5 ( V_1 ) ;
}
static void F_17 ( struct V_45 * V_7 )
{
struct V_1 * V_1 = F_15 ( V_7 ) ;
F_7 ( V_47 ,
V_7 -> V_8 + V_18 ) ;
F_18 ( V_1 -> V_46 ) ;
}
static int F_19 ( struct V_45 * V_48 , int V_49 )
{
int V_5 ;
struct V_1 * V_1 = F_15 ( V_48 ) ;
if ( V_49 ) {
F_7 ( 0xffffffff , V_48 -> V_8 + V_10 ) ;
F_7 ( V_47 ,
V_48 -> V_8 + V_18 ) ;
F_18 ( V_1 -> V_46 ) ;
} else {
F_3 () ;
V_5 = F_16 ( V_1 -> V_46 ) ;
if ( V_5 )
return V_5 ;
F_7 ( V_47 ,
V_48 -> V_8 + V_50 ) ;
F_7 ( 0 , V_48 -> V_8 + V_10 ) ;
}
return 0 ;
}
static int F_20 ( struct V_45 * V_48 , bool V_51 )
{
struct V_1 * V_1 = F_15 ( V_48 ) ;
T_2 V_52 = V_53 |
V_54 |
V_55 ;
if ( V_51 ) {
F_13 ( V_1 , true ) ;
F_11 ( V_52 , V_48 -> V_8 + V_18 ) ;
} else {
F_11 ( V_52 , V_48 -> V_8 + V_50 ) ;
F_13 ( V_1 , false ) ;
}
return 0 ;
}
static int F_21 ( struct V_45 * V_7 ,
enum V_56 V_57 )
{
F_22 ( V_7 -> V_58 , L_1 ,
( V_57 == V_59 ) ? L_2 : L_3 ) ;
if ( V_57 == V_59 )
F_7 ( V_60 ,
V_7 -> V_8 + V_18 ) ;
return 0 ;
}
static int F_23 ( struct V_45 * V_7 ,
enum V_56 V_57 )
{
F_22 ( V_7 -> V_58 , L_4 ,
( V_57 == V_59 ) ? L_2 : L_3 ) ;
if ( V_57 == V_59 )
F_7 ( V_60 ,
V_7 -> V_8 + V_50 ) ;
return 0 ;
}
static int F_24 ( struct V_61 * V_62 )
{
struct V_63 * V_64 ;
void T_1 * V_6 ;
struct V_46 * V_46 ;
struct V_1 * V_1 ;
int V_5 ;
const struct V_65 * V_66 =
F_25 ( V_67 , & V_62 -> V_58 ) ;
struct V_68 * V_69 = V_62 -> V_58 . V_70 ;
V_64 = F_26 ( V_62 , V_71 , 0 ) ;
V_6 = F_27 ( & V_62 -> V_58 , V_64 ) ;
if ( F_28 ( V_6 ) )
return F_29 ( V_6 ) ;
V_46 = F_30 ( & V_62 -> V_58 , NULL ) ;
if ( F_28 ( V_46 ) ) {
F_31 ( & V_62 -> V_58 ,
L_5 , F_29 ( V_46 ) ) ;
return F_29 ( V_46 ) ;
}
V_1 = F_32 ( & V_62 -> V_58 , sizeof( * V_1 ) , V_72 ) ;
if ( ! V_1 ) {
F_31 ( & V_62 -> V_58 , L_6 ) ;
return - V_73 ;
}
if ( F_33 ( V_69 , L_7 , NULL ) ) {
V_1 -> V_25 = F_34
( V_69 , L_7 ) ;
if ( F_28 ( V_1 -> V_25 ) ) {
F_22 ( & V_62 -> V_58 ,
L_8 ) ;
return F_29 ( V_1 -> V_25 ) ;
}
}
V_5 = F_35 ( V_69 , L_9 ) ;
if ( V_5 < 0 )
F_22 ( & V_62 -> V_58 , L_10 , V_5 ) ;
V_1 -> V_24 = V_5 ;
V_1 -> V_7 . V_8 = V_6 ;
V_1 -> V_7 . V_58 = & V_62 -> V_58 ;
V_1 -> V_7 . V_74 = V_75 ;
V_1 -> V_7 . V_76 = F_14 ;
V_1 -> V_7 . V_77 = F_17 ;
V_1 -> V_7 . V_78 = F_19 ;
V_1 -> V_7 . V_79 = F_21 ;
V_1 -> V_7 . V_80 = F_23 ;
V_1 -> V_7 . type = V_81 ;
V_1 -> V_7 . V_82 = F_20 ;
V_1 -> V_46 = V_46 ;
V_1 -> V_2 = V_66 -> V_2 ;
F_36 ( V_62 , V_1 ) ;
F_37 ( & V_62 -> V_58 , true ) ;
V_5 = F_38 ( & V_1 -> V_7 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_39 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = F_40 ( V_62 ) ;
F_41 ( & V_1 -> V_7 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_1 , bool V_42 )
{
unsigned int V_30 = V_42 ? V_83 : V_84 ;
if ( ! V_1 -> V_25 )
return;
if ( F_1 ( V_1 ) )
F_12 ( V_1 -> V_25 , V_30 ,
V_85 ) ;
else if ( F_2 ( V_1 ) )
F_12 ( V_1 -> V_25 ,
V_30 , V_86 ) ;
}
static int F_43 ( struct V_87 * V_58 )
{
struct V_1 * V_1 = F_44 ( V_58 ) ;
if ( F_45 ( V_58 ) )
F_42 ( V_1 , true ) ;
return 0 ;
}
static int F_46 ( struct V_87 * V_58 )
{
struct V_1 * V_1 = F_44 ( V_58 ) ;
if ( F_45 ( V_58 ) )
F_42 ( V_1 , false ) ;
return 0 ;
}
static int T_3 F_47 ( void )
{
return F_48 ( & V_88 ) ;
}
static void T_4 F_49 ( void )
{
F_50 ( & V_88 ) ;
}
