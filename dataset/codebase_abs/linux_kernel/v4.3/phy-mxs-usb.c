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
if ( ! V_1 -> V_24 )
return false ;
if ( V_1 -> V_25 == 0 )
F_9 ( V_1 -> V_24 ,
V_26 ,
& V_23 ) ;
else if ( V_1 -> V_25 == 1 )
F_9 ( V_1 -> V_24 ,
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
if ( V_1 -> V_25 == 0 ) {
V_30 = V_29 ? V_33
: V_34 ;
F_12 ( V_1 -> V_24 , V_30 ,
V_35 |
V_36 ) ;
} else if ( V_1 -> V_25 == 1 ) {
V_30 = V_29 ? V_37
: V_38 ;
F_12 ( V_1 -> V_24 , V_30 ,
V_39 |
V_40 ) ;
}
if ( ! V_29 )
F_11 ( V_31 ,
V_6 + V_41 ) ;
if ( V_29 )
F_4 ( 500 , 1000 ) ;
}
static bool F_13 ( struct V_1 * V_1 )
{
void T_1 * V_6 = V_1 -> V_7 . V_8 ;
T_2 V_42 = F_14 ( V_6 + V_9 ) ;
if ( F_15 ( V_43 ) &&
! ( V_42 & V_44 ) )
return true ;
return false ;
}
static void F_16 ( struct V_1 * V_1 , bool V_45 )
{
bool V_46 = false ;
if ( ! ( V_1 -> V_2 -> V_19 & V_47 ) )
return;
if ( ! V_1 -> V_24 )
return;
V_46 = F_8 ( V_1 ) ;
if ( V_45 && ! V_46 && ! F_13 ( V_1 ) )
F_10 ( V_1 , true ) ;
else
F_10 ( V_1 , false ) ;
}
static int F_17 ( struct V_48 * V_7 )
{
int V_5 ;
struct V_1 * V_1 = F_18 ( V_7 ) ;
F_3 () ;
V_5 = F_19 ( V_1 -> V_49 ) ;
if ( V_5 )
return V_5 ;
return F_5 ( V_1 ) ;
}
static void F_20 ( struct V_48 * V_7 )
{
struct V_1 * V_1 = F_18 ( V_7 ) ;
T_2 V_50 = V_51 |
V_52 |
V_53 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 ;
F_7 ( V_50 , V_7 -> V_8 + V_54 ) ;
F_7 ( 0xffffffff , V_7 -> V_8 + V_10 ) ;
F_7 ( V_55 ,
V_7 -> V_8 + V_18 ) ;
F_21 ( V_1 -> V_49 ) ;
}
static bool F_22 ( struct V_1 * V_1 )
{
unsigned int V_56 ;
unsigned int V_57 = V_58 ,
V_59 = V_60 ;
unsigned int V_30 = V_61 ;
if ( ! V_1 -> V_24 )
return false ;
if ( V_1 -> V_25 == 0 )
V_30 = V_61 ;
else if ( V_1 -> V_25 == 1 )
V_30 = V_62 ;
F_9 ( V_1 -> V_24 , V_30 , & V_56 ) ;
if ( ( V_56 & ( V_57 | V_59 ) ) == V_59 )
return true ;
else
return false ;
}
static int F_23 ( struct V_48 * V_63 , int V_64 )
{
int V_5 ;
struct V_1 * V_1 = F_18 ( V_63 ) ;
bool V_65 , V_46 ;
V_65 = F_22 ( V_1 ) ;
V_46 = F_8 ( V_1 ) ;
if ( V_64 ) {
if ( V_65 & V_46 ) {
F_3 () ;
F_7 ( 0xffbfffff , V_63 -> V_8 + V_10 ) ;
} else {
F_7 ( 0xffffffff , V_63 -> V_8 + V_10 ) ;
}
F_7 ( V_55 ,
V_63 -> V_8 + V_18 ) ;
F_21 ( V_1 -> V_49 ) ;
} else {
F_3 () ;
V_5 = F_19 ( V_1 -> V_49 ) ;
if ( V_5 )
return V_5 ;
F_7 ( V_55 ,
V_63 -> V_8 + V_54 ) ;
F_7 ( 0 , V_63 -> V_8 + V_10 ) ;
}
return 0 ;
}
static int F_24 ( struct V_48 * V_63 , bool V_66 )
{
struct V_1 * V_1 = F_18 ( V_63 ) ;
T_2 V_50 = V_51 |
V_52 |
V_53 ;
if ( V_66 ) {
F_16 ( V_1 , true ) ;
F_11 ( V_50 , V_63 -> V_8 + V_18 ) ;
} else {
F_11 ( V_50 , V_63 -> V_8 + V_54 ) ;
F_16 ( V_1 , false ) ;
}
return 0 ;
}
static int F_25 ( struct V_48 * V_7 ,
enum V_67 V_68 )
{
F_26 ( V_7 -> V_69 , L_1 ,
( V_68 == V_70 ) ? L_2 : L_3 ) ;
if ( V_68 == V_70 )
F_7 ( V_71 ,
V_7 -> V_8 + V_18 ) ;
return 0 ;
}
static int F_27 ( struct V_48 * V_7 ,
enum V_67 V_68 )
{
F_26 ( V_7 -> V_69 , L_4 ,
( V_68 == V_70 ) ? L_2 : L_3 ) ;
if ( F_14 ( V_7 -> V_8 + V_9 ) &
V_71 )
F_7 ( V_71 ,
V_7 -> V_8 + V_54 ) ;
return 0 ;
}
static int F_28 ( struct V_72 * V_73 )
{
struct V_74 * V_75 ;
void T_1 * V_6 ;
struct V_49 * V_49 ;
struct V_1 * V_1 ;
int V_5 ;
const struct V_76 * V_77 =
F_29 ( V_78 , & V_73 -> V_69 ) ;
struct V_79 * V_80 = V_73 -> V_69 . V_81 ;
V_75 = F_30 ( V_73 , V_82 , 0 ) ;
V_6 = F_31 ( & V_73 -> V_69 , V_75 ) ;
if ( F_32 ( V_6 ) )
return F_33 ( V_6 ) ;
V_49 = F_34 ( & V_73 -> V_69 , NULL ) ;
if ( F_32 ( V_49 ) ) {
F_35 ( & V_73 -> V_69 ,
L_5 , F_33 ( V_49 ) ) ;
return F_33 ( V_49 ) ;
}
V_1 = F_36 ( & V_73 -> V_69 , sizeof( * V_1 ) , V_83 ) ;
if ( ! V_1 )
return - V_84 ;
if ( F_37 ( V_80 , L_6 , NULL ) ) {
V_1 -> V_24 = F_38
( V_80 , L_6 ) ;
if ( F_32 ( V_1 -> V_24 ) ) {
F_26 ( & V_73 -> V_69 ,
L_7 ) ;
return F_33 ( V_1 -> V_24 ) ;
}
}
V_5 = F_39 ( V_80 , L_8 ) ;
if ( V_5 < 0 )
F_26 ( & V_73 -> V_69 , L_9 , V_5 ) ;
V_1 -> V_25 = V_5 ;
V_1 -> V_7 . V_8 = V_6 ;
V_1 -> V_7 . V_69 = & V_73 -> V_69 ;
V_1 -> V_7 . V_85 = V_86 ;
V_1 -> V_7 . V_87 = F_17 ;
V_1 -> V_7 . V_88 = F_20 ;
V_1 -> V_7 . V_89 = F_23 ;
V_1 -> V_7 . V_90 = F_25 ;
V_1 -> V_7 . V_91 = F_27 ;
V_1 -> V_7 . type = V_92 ;
V_1 -> V_7 . V_93 = F_24 ;
V_1 -> V_49 = V_49 ;
V_1 -> V_2 = V_77 -> V_2 ;
F_40 ( V_73 , V_1 ) ;
F_41 ( & V_73 -> V_69 , true ) ;
return F_42 ( & V_1 -> V_7 ) ;
}
static int F_43 ( struct V_72 * V_73 )
{
struct V_1 * V_1 = F_44 ( V_73 ) ;
F_45 ( & V_1 -> V_7 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_1 , bool V_45 )
{
unsigned int V_30 = V_45 ? V_94 : V_95 ;
if ( ! V_1 -> V_24 )
return;
if ( F_1 ( V_1 ) )
F_12 ( V_1 -> V_24 , V_30 ,
V_96 ) ;
else if ( F_2 ( V_1 ) )
F_12 ( V_1 -> V_24 ,
V_30 , V_97 ) ;
}
static int F_47 ( struct V_98 * V_69 )
{
struct V_1 * V_1 = F_48 ( V_69 ) ;
if ( F_49 ( V_69 ) )
F_46 ( V_1 , true ) ;
return 0 ;
}
static int F_50 ( struct V_98 * V_69 )
{
struct V_1 * V_1 = F_48 ( V_69 ) ;
if ( F_49 ( V_69 ) )
F_46 ( V_1 , false ) ;
return 0 ;
}
static int T_3 F_51 ( void )
{
return F_52 ( & V_99 ) ;
}
static void T_4 F_53 ( void )
{
F_54 ( & V_99 ) ;
}
