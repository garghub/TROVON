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
static void F_5 ( struct V_1 * V_1 )
{
void T_1 * V_5 = V_1 -> V_6 . V_7 ;
T_2 V_8 ;
if ( V_1 -> V_9 ) {
V_8 = F_6 ( V_5 + V_10 ) ;
V_8 &= ~ V_1 -> V_9 ;
V_8 |= V_1 -> V_11 ;
F_7 ( V_8 , V_5 + V_10 ) ;
}
}
static int F_8 ( struct V_1 * V_1 )
{
int V_12 ;
void T_1 * V_5 = V_1 -> V_6 . V_7 ;
V_12 = F_9 ( V_5 + V_13 ) ;
if ( V_12 )
return V_12 ;
F_7 ( 0 , V_5 + V_14 ) ;
F_7 ( V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 |
V_21 ,
V_5 + V_22 ) ;
if ( V_1 -> V_2 -> V_23 & V_24 )
F_7 ( V_25 , V_5 + V_26 ) ;
F_5 ( V_1 ) ;
return 0 ;
}
static bool F_10 ( struct V_1 * V_1 )
{
unsigned int V_27 = 0 ;
if ( ! V_1 -> V_28 )
return false ;
if ( V_1 -> V_29 == 0 )
F_11 ( V_1 -> V_28 ,
V_30 ,
& V_27 ) ;
else if ( V_1 -> V_29 == 1 )
F_11 ( V_1 -> V_28 ,
V_31 ,
& V_27 ) ;
if ( V_27 & V_32 )
return true ;
else
return false ;
}
static void F_12 ( struct V_1 * V_1 , bool V_33 )
{
void T_1 * V_5 = V_1 -> V_6 . V_7 ;
T_2 V_34 ;
if ( V_33 )
F_13 ( V_35 ,
V_5 + V_36 ) ;
if ( V_1 -> V_29 == 0 ) {
V_34 = V_33 ? V_37
: V_38 ;
F_14 ( V_1 -> V_28 , V_34 ,
V_39 |
V_40 ) ;
} else if ( V_1 -> V_29 == 1 ) {
V_34 = V_33 ? V_41
: V_42 ;
F_14 ( V_1 -> V_28 , V_34 ,
V_43 |
V_44 ) ;
}
if ( ! V_33 )
F_13 ( V_35 ,
V_5 + V_45 ) ;
if ( V_33 )
F_4 ( 500 , 1000 ) ;
}
static bool F_15 ( struct V_1 * V_1 )
{
void T_1 * V_5 = V_1 -> V_6 . V_7 ;
T_2 V_46 = F_6 ( V_5 + V_13 ) ;
if ( F_16 ( V_47 ) &&
! ( V_46 & V_48 ) )
return true ;
return false ;
}
static void F_17 ( struct V_1 * V_1 , bool V_49 )
{
bool V_50 = false ;
if ( ! ( V_1 -> V_2 -> V_23 & V_51 ) )
return;
if ( ! V_1 -> V_28 )
return;
V_50 = F_10 ( V_1 ) ;
if ( V_49 && ! V_50 && ! F_15 ( V_1 ) )
F_12 ( V_1 , true ) ;
else
F_12 ( V_1 , false ) ;
}
static int F_18 ( struct V_52 * V_6 )
{
int V_12 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
F_3 () ;
V_12 = F_20 ( V_1 -> V_53 ) ;
if ( V_12 )
return V_12 ;
return F_8 ( V_1 ) ;
}
static void F_21 ( struct V_52 * V_6 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_2 V_54 = V_55 |
V_56 |
V_57 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 ;
F_7 ( V_54 , V_6 -> V_7 + V_58 ) ;
F_7 ( 0xffffffff , V_6 -> V_7 + V_14 ) ;
F_7 ( V_59 ,
V_6 -> V_7 + V_22 ) ;
F_22 ( V_1 -> V_53 ) ;
}
static bool F_23 ( struct V_1 * V_1 )
{
unsigned int V_60 ;
unsigned int V_61 = V_62 ,
V_63 = V_64 ;
unsigned int V_34 = V_65 ;
if ( ! V_1 -> V_28 )
return false ;
if ( V_1 -> V_29 == 0 )
V_34 = V_65 ;
else if ( V_1 -> V_29 == 1 )
V_34 = V_66 ;
F_11 ( V_1 -> V_28 , V_34 , & V_60 ) ;
if ( ( V_60 & ( V_61 | V_63 ) ) == V_63 )
return true ;
else
return false ;
}
static int F_24 ( struct V_52 * V_67 , int V_68 )
{
int V_12 ;
struct V_1 * V_1 = F_19 ( V_67 ) ;
bool V_69 , V_50 ;
V_69 = F_23 ( V_1 ) ;
V_50 = F_10 ( V_1 ) ;
if ( V_68 ) {
if ( V_69 & V_50 ) {
F_3 () ;
F_7 ( 0xffbfffff , V_67 -> V_7 + V_14 ) ;
} else {
F_7 ( 0xffffffff , V_67 -> V_7 + V_14 ) ;
}
F_7 ( V_59 ,
V_67 -> V_7 + V_22 ) ;
F_22 ( V_1 -> V_53 ) ;
} else {
F_3 () ;
V_12 = F_20 ( V_1 -> V_53 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_59 ,
V_67 -> V_7 + V_58 ) ;
F_7 ( 0 , V_67 -> V_7 + V_14 ) ;
}
return 0 ;
}
static int F_25 ( struct V_52 * V_67 , bool V_70 )
{
struct V_1 * V_1 = F_19 ( V_67 ) ;
T_2 V_54 = V_55 |
V_56 |
V_57 ;
if ( V_70 ) {
F_17 ( V_1 , true ) ;
F_13 ( V_54 , V_67 -> V_7 + V_22 ) ;
} else {
F_13 ( V_54 , V_67 -> V_7 + V_58 ) ;
F_17 ( V_1 , false ) ;
}
return 0 ;
}
static int F_26 ( struct V_52 * V_6 ,
enum V_71 V_72 )
{
F_27 ( V_6 -> V_73 , L_1 ,
( V_72 == V_74 ) ? L_2 : L_3 ) ;
if ( V_72 == V_74 )
F_7 ( V_75 ,
V_6 -> V_7 + V_22 ) ;
return 0 ;
}
static int F_28 ( struct V_52 * V_6 ,
enum V_71 V_72 )
{
F_27 ( V_6 -> V_73 , L_4 ,
( V_72 == V_74 ) ? L_2 : L_3 ) ;
if ( F_6 ( V_6 -> V_7 + V_13 ) &
V_75 )
F_7 ( V_75 ,
V_6 -> V_7 + V_58 ) ;
return 0 ;
}
static int F_29 ( struct V_76 * V_77 )
{
struct V_78 * V_79 ;
void T_1 * V_5 ;
struct V_53 * V_53 ;
struct V_1 * V_1 ;
int V_12 ;
const struct V_80 * V_81 ;
struct V_82 * V_83 = V_77 -> V_73 . V_84 ;
T_2 V_85 ;
V_81 = F_30 ( V_86 , & V_77 -> V_73 ) ;
if ( ! V_81 )
return - V_87 ;
V_79 = F_31 ( V_77 , V_88 , 0 ) ;
V_5 = F_32 ( & V_77 -> V_73 , V_79 ) ;
if ( F_33 ( V_5 ) )
return F_34 ( V_5 ) ;
V_53 = F_35 ( & V_77 -> V_73 , NULL ) ;
if ( F_33 ( V_53 ) ) {
F_36 ( & V_77 -> V_73 ,
L_5 , F_34 ( V_53 ) ) ;
return F_34 ( V_53 ) ;
}
V_1 = F_37 ( & V_77 -> V_73 , sizeof( * V_1 ) , V_89 ) ;
if ( ! V_1 )
return - V_90 ;
if ( F_38 ( V_83 , L_6 , NULL ) ) {
V_1 -> V_28 = F_39
( V_83 , L_6 ) ;
if ( F_33 ( V_1 -> V_28 ) ) {
F_27 ( & V_77 -> V_73 ,
L_7 ) ;
return F_34 ( V_1 -> V_28 ) ;
}
}
if ( ! F_40 ( V_83 , L_8 , & V_85 ) &&
V_85 >= V_91 && V_85 <= V_92 ) {
V_85 = ( V_92 - V_85 ) * 0xF
/ ( V_92 - V_91 ) ;
V_1 -> V_9 |= F_41 ( ~ 0 ) ;
V_1 -> V_11 |= F_41 ( V_85 ) ;
}
if ( ! F_40 ( V_83 , L_9 , & V_85 ) &&
V_85 >= V_91 && V_85 <= V_92 ) {
V_85 = ( V_92 - V_85 ) * 0xF
/ ( V_92 - V_91 ) ;
V_1 -> V_9 |= F_42 ( ~ 0 ) ;
V_1 -> V_11 |= F_42 ( V_85 ) ;
}
if ( ! F_40 ( V_83 , L_10 , & V_85 ) &&
V_85 >= V_93 && V_85 <= V_94 ) {
V_85 = ( ( V_94 - V_85 ) * 0xF
+ ( V_94 - V_93 ) * 2 / 3 )
/ ( V_94 - V_93 ) ;
V_1 -> V_9 |= F_43 ( ~ 0 ) ;
V_1 -> V_11 |= F_43 ( V_85 ) ;
}
V_12 = F_44 ( V_83 , L_11 ) ;
if ( V_12 < 0 )
F_27 ( & V_77 -> V_73 , L_12 , V_12 ) ;
V_1 -> V_29 = V_12 ;
V_1 -> V_6 . V_7 = V_5 ;
V_1 -> V_6 . V_73 = & V_77 -> V_73 ;
V_1 -> V_6 . V_95 = V_96 ;
V_1 -> V_6 . V_97 = F_18 ;
V_1 -> V_6 . V_98 = F_21 ;
V_1 -> V_6 . V_99 = F_24 ;
V_1 -> V_6 . V_100 = F_26 ;
V_1 -> V_6 . V_101 = F_28 ;
V_1 -> V_6 . type = V_102 ;
V_1 -> V_6 . V_103 = F_25 ;
V_1 -> V_53 = V_53 ;
V_1 -> V_2 = V_81 -> V_2 ;
F_45 ( V_77 , V_1 ) ;
F_46 ( & V_77 -> V_73 , true ) ;
return F_47 ( & V_1 -> V_6 ) ;
}
static int F_48 ( struct V_76 * V_77 )
{
struct V_1 * V_1 = F_49 ( V_77 ) ;
F_50 ( & V_1 -> V_6 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_1 , bool V_49 )
{
unsigned int V_34 = V_49 ? V_104 : V_105 ;
if ( ! V_1 -> V_28 )
return;
if ( F_1 ( V_1 ) )
F_14 ( V_1 -> V_28 , V_34 ,
V_106 ) ;
else if ( F_2 ( V_1 ) )
F_14 ( V_1 -> V_28 ,
V_34 , V_107 ) ;
}
static int F_52 ( struct V_108 * V_73 )
{
struct V_1 * V_1 = F_53 ( V_73 ) ;
if ( F_54 ( V_73 ) )
F_51 ( V_1 , true ) ;
return 0 ;
}
static int F_55 ( struct V_108 * V_73 )
{
struct V_1 * V_1 = F_53 ( V_73 ) ;
if ( F_54 ( V_73 ) )
F_51 ( V_1 , false ) ;
return 0 ;
}
static int T_3 F_56 ( void )
{
return F_57 ( & V_109 ) ;
}
static void T_4 F_58 ( void )
{
F_59 ( & V_109 ) ;
}
