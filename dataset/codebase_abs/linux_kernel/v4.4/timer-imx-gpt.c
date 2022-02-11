static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
unsigned int V_5 ;
V_5 = F_4 ( V_4 -> V_6 + V_7 ) ;
F_5 ( V_5 & ~ V_8 , V_4 -> V_6 + V_7 ) ;
}
static void F_6 ( struct V_1 * V_4 )
{
F_5 ( 0 , V_4 -> V_6 + V_9 ) ;
}
static void F_7 ( struct V_1 * V_4 )
{
unsigned int V_5 ;
V_5 = F_4 ( V_4 -> V_6 + V_7 ) ;
F_5 ( V_5 | V_8 , V_4 -> V_6 + V_7 ) ;
}
static void F_8 ( struct V_1 * V_4 )
{
F_5 ( 1 << 0 , V_4 -> V_6 + V_9 ) ;
}
static void F_9 ( struct V_1 * V_4 )
{
F_5 ( 0 , V_4 -> V_6 + V_10 ) ;
}
static void F_10 ( struct V_1 * V_4 )
{
F_5 ( V_11 | V_12 ,
V_4 -> V_6 + V_10 ) ;
}
static void F_11 ( struct V_1 * V_4 )
{
F_5 ( V_13 , V_4 -> V_6 + V_14 ) ;
}
static T_1 T_2 F_12 ( void )
{
return V_15 ? F_4 ( V_15 ) : 0 ;
}
static unsigned long F_13 ( void )
{
return F_4 ( V_15 ) ;
}
static int T_3 F_14 ( struct V_1 * V_4 )
{
unsigned int V_16 = F_15 ( V_4 -> V_17 ) ;
void T_4 * V_18 = V_4 -> V_6 + V_4 -> V_19 -> V_20 ;
V_21 . V_22 = & F_13 ;
V_21 . V_23 = V_16 ;
F_16 ( & V_21 ) ;
V_15 = V_18 ;
F_17 ( F_12 , 32 , V_16 ) ;
return F_18 ( V_18 , L_1 , V_16 , 200 , 32 ,
V_24 ) ;
}
static int F_19 ( unsigned long V_25 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_26 ;
V_26 = F_4 ( V_4 -> V_6 + V_27 ) + V_25 ;
F_5 ( V_26 , V_4 -> V_6 + V_28 ) ;
return ( int ) ( V_26 - F_4 ( V_4 -> V_6 + V_27 ) ) < 0 ?
- V_29 : 0 ;
}
static int F_20 ( unsigned long V_25 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_26 ;
V_26 = F_4 ( V_4 -> V_6 + V_30 ) + V_25 ;
F_5 ( V_26 , V_4 -> V_6 + V_31 ) ;
return V_25 < 0x7fffffff &&
( int ) ( V_26 - F_4 ( V_4 -> V_6 + V_30 ) ) < 0 ?
- V_29 : 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_32 ;
T_5 V_33 ;
F_22 ( V_32 ) ;
V_4 -> V_19 -> V_34 ( V_4 ) ;
V_33 = F_4 ( V_4 -> V_6 + V_4 -> V_19 -> V_20 ) ;
F_5 ( V_33 - 3 , V_4 -> V_6 + V_4 -> V_19 -> V_35 ) ;
V_4 -> V_19 -> V_36 ( V_4 ) ;
#ifdef F_23
F_24 ( V_37 L_2 , V_38 ) ;
#endif
F_25 ( V_32 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_32 ;
F_22 ( V_32 ) ;
V_4 -> V_19 -> V_34 ( V_4 ) ;
if ( ! F_27 ( V_3 ) ) {
T_5 V_33 = F_4 ( V_4 -> V_6 + V_4 -> V_19 -> V_20 ) ;
F_5 ( V_33 - 3 , V_4 -> V_6 + V_4 -> V_19 -> V_35 ) ;
V_4 -> V_19 -> V_36 ( V_4 ) ;
}
#ifdef F_23
F_24 ( V_37 L_2 , V_38 ) ;
#endif
V_4 -> V_19 -> V_39 ( V_4 ) ;
F_25 ( V_32 ) ;
return 0 ;
}
static T_6 F_28 ( int V_40 , void * V_41 )
{
struct V_2 * V_3 = V_41 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_7 V_42 ;
V_42 = F_4 ( V_4 -> V_6 + V_4 -> V_19 -> V_43 ) ;
V_4 -> V_19 -> V_36 ( V_4 ) ;
V_3 -> V_44 ( V_3 ) ;
return V_45 ;
}
static int T_3 F_29 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_46 * V_47 = & V_4 -> V_47 ;
V_3 -> V_48 = L_1 ;
V_3 -> V_49 = V_50 | V_51 ;
V_3 -> V_52 = F_21 ;
V_3 -> V_53 = F_26 ;
V_3 -> V_54 = F_21 ;
V_3 -> V_55 = V_4 -> V_19 -> V_55 ;
V_3 -> V_56 = 200 ;
V_3 -> V_57 = F_30 ( 0 ) ;
V_3 -> V_40 = V_4 -> V_40 ;
F_31 ( V_3 , F_15 ( V_4 -> V_17 ) ,
0xff , 0xfffffffe ) ;
V_47 -> V_48 = L_3 ;
V_47 -> V_32 = V_58 | V_59 ;
V_47 -> V_60 = F_28 ;
V_47 -> V_41 = V_3 ;
return F_32 ( V_4 -> V_40 , V_47 ) ;
}
static void F_33 ( struct V_1 * V_4 )
{
T_5 V_61 ;
V_61 = V_62 | V_63 | V_64 ;
F_5 ( V_61 , V_4 -> V_6 + V_7 ) ;
}
static void F_34 ( struct V_1 * V_4 )
{
T_5 V_61 ;
V_61 = V_65 | V_66 | V_64 ;
if ( F_15 ( V_4 -> V_17 ) == V_67 )
V_61 |= V_68 ;
else
V_61 |= V_69 ;
F_5 ( V_61 , V_4 -> V_6 + V_7 ) ;
}
static void F_35 ( struct V_1 * V_4 )
{
T_5 V_61 ;
V_61 = V_65 | V_66 | V_64 ;
if ( F_15 ( V_4 -> V_17 ) == V_67 ) {
V_61 |= V_68 ;
F_5 ( 7 << V_70 , V_4 -> V_6 + V_71 ) ;
V_61 |= V_72 ;
} else {
V_61 |= V_69 ;
}
F_5 ( V_61 , V_4 -> V_6 + V_7 ) ;
}
static void T_3 F_36 ( struct V_1 * V_4 )
{
switch ( V_4 -> type ) {
case V_73 :
V_4 -> V_19 = & V_74 ;
break;
case V_75 :
V_4 -> V_19 = & V_76 ;
break;
case V_77 :
V_4 -> V_19 = & V_78 ;
break;
case V_79 :
V_4 -> V_19 = & V_80 ;
break;
default:
F_37 () ;
}
if ( F_38 ( V_4 -> V_17 ) ) {
F_39 ( L_4 ) ;
return;
}
if ( ! F_38 ( V_4 -> V_81 ) )
F_40 ( V_4 -> V_81 ) ;
F_40 ( V_4 -> V_17 ) ;
F_5 ( 0 , V_4 -> V_6 + V_7 ) ;
F_5 ( 0 , V_4 -> V_6 + V_71 ) ;
V_4 -> V_19 -> V_82 ( V_4 ) ;
F_14 ( V_4 ) ;
F_29 ( V_4 ) ;
}
void T_3 F_41 ( unsigned long V_83 , int V_40 , enum V_84 type )
{
struct V_1 * V_4 ;
V_4 = F_42 ( sizeof( * V_4 ) , V_85 ) ;
F_43 ( ! V_4 ) ;
V_4 -> V_17 = F_44 ( L_5 , L_6 ) ;
V_4 -> V_81 = F_44 ( L_5 , L_7 ) ;
V_4 -> V_6 = F_45 ( V_83 , V_86 ) ;
F_43 ( ! V_4 -> V_6 ) ;
V_4 -> type = type ;
V_4 -> V_40 = V_40 ;
F_36 ( V_4 ) ;
}
static void T_3 F_46 ( struct V_87 * V_88 , enum V_84 type )
{
struct V_1 * V_4 ;
static int V_89 ;
if ( V_89 )
return;
V_4 = F_42 ( sizeof( * V_4 ) , V_85 ) ;
F_43 ( ! V_4 ) ;
V_4 -> V_6 = F_47 ( V_88 , 0 ) ;
F_48 ( ! V_4 -> V_6 ) ;
V_4 -> V_40 = F_49 ( V_88 , 0 ) ;
V_4 -> V_81 = F_50 ( V_88 , L_7 ) ;
V_4 -> V_17 = F_50 ( V_88 , L_8 ) ;
if ( F_38 ( V_4 -> V_17 ) )
V_4 -> V_17 = F_50 ( V_88 , L_6 ) ;
V_4 -> type = type ;
F_36 ( V_4 ) ;
V_89 = 1 ;
}
static void T_3 F_51 ( struct V_87 * V_88 )
{
F_46 ( V_88 , V_73 ) ;
}
static void T_3 F_52 ( struct V_87 * V_88 )
{
F_46 ( V_88 , V_75 ) ;
}
static void T_3 F_53 ( struct V_87 * V_88 )
{
enum V_84 type = V_77 ;
if ( F_54 ( L_9 ) )
type = V_79 ;
F_46 ( V_88 , type ) ;
}
static void T_3 F_55 ( struct V_87 * V_88 )
{
F_46 ( V_88 , V_79 ) ;
}
