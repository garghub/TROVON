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
static void F_21 ( enum V_32 V_33 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_34 ;
F_22 ( V_34 ) ;
V_4 -> V_19 -> V_35 ( V_4 ) ;
if ( V_33 != V_4 -> V_36 ) {
T_5 V_37 = F_4 ( V_4 -> V_6 + V_4 -> V_19 -> V_20 ) ;
F_5 ( V_37 - 3 , V_4 -> V_6 + V_4 -> V_19 -> V_38 ) ;
V_4 -> V_19 -> V_39 ( V_4 ) ;
}
#ifdef F_23
F_24 ( V_40 L_2 ,
V_41 [ V_4 -> V_36 ] ,
V_41 [ V_33 ] ) ;
#endif
V_4 -> V_36 = V_33 ;
F_25 ( V_34 ) ;
switch ( V_33 ) {
case V_42 :
F_24 ( V_43 L_3
L_4 ) ;
break;
case V_44 :
F_22 ( V_34 ) ;
V_4 -> V_19 -> V_45 ( V_4 ) ;
F_25 ( V_34 ) ;
break;
case V_46 :
case V_47 :
case V_48 :
break;
}
}
static T_6 F_26 ( int V_49 , void * V_50 )
{
struct V_2 * V_3 = V_50 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_7 V_51 ;
V_51 = F_4 ( V_4 -> V_6 + V_4 -> V_19 -> V_52 ) ;
V_4 -> V_19 -> V_39 ( V_4 ) ;
V_3 -> V_53 ( V_3 ) ;
return V_54 ;
}
static int T_3 F_27 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
struct V_55 * V_56 = & V_4 -> V_56 ;
V_4 -> V_36 = V_47 ;
V_3 -> V_57 = L_1 ;
V_3 -> V_58 = V_59 ;
V_3 -> V_60 = F_21 ;
V_3 -> V_61 = V_4 -> V_19 -> V_61 ;
V_3 -> V_62 = 200 ;
V_3 -> V_63 = F_28 ( 0 ) ;
F_29 ( V_3 , F_15 ( V_4 -> V_17 ) ,
0xff , 0xfffffffe ) ;
V_56 -> V_57 = L_5 ;
V_56 -> V_34 = V_64 | V_65 ;
V_56 -> V_66 = F_26 ;
V_56 -> V_50 = V_3 ;
return F_30 ( V_4 -> V_49 , V_56 ) ;
}
static void F_31 ( struct V_1 * V_4 )
{
T_5 V_67 ;
V_67 = V_68 | V_69 | V_70 ;
F_5 ( V_67 , V_4 -> V_6 + V_7 ) ;
}
static void F_32 ( struct V_1 * V_4 )
{
T_5 V_67 ;
V_67 = V_71 | V_72 | V_70 ;
if ( F_15 ( V_4 -> V_17 ) == V_73 )
V_67 |= V_74 ;
else
V_67 |= V_75 ;
F_5 ( V_67 , V_4 -> V_6 + V_7 ) ;
}
static void F_33 ( struct V_1 * V_4 )
{
T_5 V_67 ;
V_67 = V_71 | V_72 | V_70 ;
if ( F_15 ( V_4 -> V_17 ) == V_73 ) {
V_67 |= V_74 ;
F_5 ( 7 << V_76 , V_4 -> V_6 + V_77 ) ;
V_67 |= V_78 ;
} else {
V_67 |= V_75 ;
}
F_5 ( V_67 , V_4 -> V_6 + V_7 ) ;
}
static void T_3 F_34 ( struct V_1 * V_4 )
{
switch ( V_4 -> type ) {
case V_79 :
V_4 -> V_19 = & V_80 ;
break;
case V_81 :
V_4 -> V_19 = & V_82 ;
break;
case V_83 :
V_4 -> V_19 = & V_84 ;
break;
case V_85 :
V_4 -> V_19 = & V_86 ;
break;
default:
F_35 () ;
}
if ( F_36 ( V_4 -> V_17 ) ) {
F_37 ( L_6 ) ;
return;
}
if ( ! F_36 ( V_4 -> V_87 ) )
F_38 ( V_4 -> V_87 ) ;
F_38 ( V_4 -> V_17 ) ;
F_5 ( 0 , V_4 -> V_6 + V_7 ) ;
F_5 ( 0 , V_4 -> V_6 + V_77 ) ;
V_4 -> V_19 -> V_88 ( V_4 ) ;
F_14 ( V_4 ) ;
F_27 ( V_4 ) ;
}
void T_3 F_39 ( unsigned long V_89 , int V_49 , enum V_90 type )
{
struct V_1 * V_4 ;
V_4 = F_40 ( sizeof( * V_4 ) , V_91 ) ;
F_41 ( ! V_4 ) ;
V_4 -> V_17 = F_42 ( L_7 , L_8 ) ;
V_4 -> V_87 = F_42 ( L_7 , L_9 ) ;
V_4 -> V_6 = F_43 ( V_89 , V_92 ) ;
F_41 ( ! V_4 -> V_6 ) ;
V_4 -> type = type ;
V_4 -> V_49 = V_49 ;
F_34 ( V_4 ) ;
}
static void T_3 F_44 ( struct V_93 * V_94 , enum V_90 type )
{
struct V_1 * V_4 ;
static int V_95 ;
if ( V_95 )
return;
V_4 = F_40 ( sizeof( * V_4 ) , V_91 ) ;
F_41 ( ! V_4 ) ;
V_4 -> V_6 = F_45 ( V_94 , 0 ) ;
F_46 ( ! V_4 -> V_6 ) ;
V_4 -> V_49 = F_47 ( V_94 , 0 ) ;
V_4 -> V_87 = F_48 ( V_94 , L_9 ) ;
V_4 -> V_17 = F_48 ( V_94 , L_10 ) ;
if ( F_36 ( V_4 -> V_17 ) )
V_4 -> V_17 = F_48 ( V_94 , L_8 ) ;
V_4 -> type = type ;
F_34 ( V_4 ) ;
V_95 = 1 ;
}
static void T_3 F_49 ( struct V_93 * V_94 )
{
F_44 ( V_94 , V_79 ) ;
}
static void T_3 F_50 ( struct V_93 * V_94 )
{
F_44 ( V_94 , V_81 ) ;
}
static void T_3 F_51 ( struct V_93 * V_94 )
{
enum V_90 type = V_83 ;
if ( F_52 ( L_11 ) )
type = V_85 ;
F_44 ( V_94 , type ) ;
}
static void T_3 F_53 ( struct V_93 * V_94 )
{
F_44 ( V_94 , V_85 ) ;
}
