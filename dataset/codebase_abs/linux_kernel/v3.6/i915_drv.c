void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_8 << 8 , NULL ) ;
if ( V_7 ) {
if ( V_7 -> V_9 == V_10 ) {
int V_11 ;
V_11 = V_7 -> V_12 & V_13 ;
if ( V_11 == V_14 ) {
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = 2 ;
F_3 ( L_1 ) ;
} else if ( V_11 == V_18 ) {
V_4 -> V_15 = V_19 ;
V_4 -> V_17 = 2 ;
F_3 ( L_2 ) ;
} else if ( V_11 == V_20 ) {
V_4 -> V_15 = V_19 ;
V_4 -> V_17 = 2 ;
F_3 ( L_3 ) ;
} else if ( V_11 == V_21 ) {
V_4 -> V_15 = V_22 ;
V_4 -> V_17 = 0 ;
F_3 ( L_4 ) ;
}
F_4 ( V_4 -> V_17 > V_23 ) ;
}
F_5 ( V_7 ) ;
}
}
bool F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) -> V_24 < 6 )
return 0 ;
if ( V_25 >= 0 )
return V_25 ;
#ifdef F_8
if ( F_7 ( V_2 ) -> V_24 == 6 && V_26 )
return false ;
#endif
return 1 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_10 ( V_2 ) ;
F_11 ( V_2 -> V_27 ) ;
if ( F_12 ( V_2 , V_28 ) ) {
int error = F_13 ( V_2 ) ;
if ( error ) {
F_14 ( & V_2 -> V_27 -> V_2 ,
L_5 ) ;
return error ;
}
F_15 ( V_2 ) ;
}
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
V_4 -> V_29 = 0 ;
F_18 () ;
F_19 ( V_2 , 1 ) ;
F_20 () ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_30 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_22 ( L_6 , V_2 ) ;
F_22 ( L_7 ) ;
return - V_31 ;
}
if ( V_30 . V_32 == V_33 )
return 0 ;
if ( V_2 -> V_34 == V_35 )
return 0 ;
error = F_9 ( V_2 ) ;
if ( error )
return error ;
if ( V_30 . V_32 == V_36 ) {
F_23 ( V_2 -> V_27 ) ;
F_24 ( V_2 -> V_27 , V_37 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
if ( F_12 ( V_2 , V_28 ) ) {
F_26 ( & V_2 -> V_38 ) ;
F_27 ( V_2 ) ;
F_28 ( & V_2 -> V_38 ) ;
}
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
if ( F_12 ( V_2 , V_28 ) ) {
if ( F_31 ( V_2 ) || F_32 ( V_2 ) )
F_33 ( V_2 ) ;
F_26 ( & V_2 -> V_38 ) ;
V_4 -> V_39 . V_40 = 0 ;
error = F_34 ( V_2 ) ;
F_28 ( & V_2 -> V_38 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_26 ( & V_2 -> V_41 . V_42 ) ;
F_38 ( V_2 ) ;
F_28 ( & V_2 -> V_41 . V_42 ) ;
}
F_39 ( V_2 ) ;
V_4 -> V_29 = 0 ;
F_18 () ;
F_19 ( V_2 , 0 ) ;
F_20 () ;
return error ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_43 ;
if ( V_2 -> V_34 == V_35 )
return 0 ;
if ( F_41 ( V_2 -> V_27 ) )
return - V_44 ;
F_42 ( V_2 -> V_27 ) ;
V_43 = F_25 ( V_2 ) ;
if ( V_43 )
return V_43 ;
F_43 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_45 ( V_2 ) )
return - V_31 ;
F_46 ( V_45 , F_47 ( V_45 ) | V_46 ) ;
F_48 ( V_45 ) ;
if ( F_49 ( V_2 ) || F_50 ( V_2 ) ) {
F_46 ( V_47 ,
V_48 |
V_49 |
V_50 ) ;
F_48 ( V_47 ) ;
F_51 ( 1 ) ;
F_46 ( V_47 , 0 ) ;
F_48 ( V_47 ) ;
}
F_51 ( 1 ) ;
F_46 ( V_45 , F_47 ( V_45 ) & ~ V_46 ) ;
F_48 ( V_45 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
T_2 V_51 ;
F_53 ( V_2 -> V_27 , V_52 , & V_51 ) ;
return ( V_51 & V_53 ) == 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_43 ;
T_2 V_51 ;
F_53 ( V_2 -> V_27 , V_52 , & V_51 ) ;
F_55 ( V_2 -> V_27 , V_52 ,
V_51 | V_54 |
V_53 ) ;
V_43 = F_56 ( F_52 ( V_2 ) , 500 ) ;
if ( V_43 )
return V_43 ;
F_53 ( V_2 -> V_27 , V_52 , & V_51 ) ;
F_55 ( V_2 -> V_27 , V_52 ,
V_51 | V_55 |
V_53 ) ;
return F_56 ( F_52 ( V_2 ) , 500 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_51 ;
int V_43 ;
V_51 = F_47 ( V_56 + V_57 ) ;
F_46 ( V_56 + V_57 ,
V_51 | V_54 | V_53 ) ;
V_43 = F_56 ( F_47 ( V_56 + V_57 ) & 0x1 , 500 ) ;
if ( V_43 )
return V_43 ;
V_51 = F_47 ( V_56 + V_57 ) ;
F_46 ( V_56 + V_57 ,
V_51 | V_55 | V_53 ) ;
return F_56 ( F_47 ( V_56 + V_57 ) & 0x1 , 500 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_43 ;
unsigned long V_58 ;
F_59 ( & V_4 -> V_59 , V_58 ) ;
F_60 ( V_60 , V_61 ) ;
V_43 = F_56 ( ( F_61 ( V_60 ) & V_61 ) == 0 , 500 ) ;
if ( V_4 -> V_62 )
V_4 -> V_63 . V_64 ( V_4 ) ;
else
V_4 -> V_63 . V_65 ( V_4 ) ;
V_4 -> V_66 = F_61 ( V_67 ) ;
F_62 ( & V_4 -> V_59 , V_58 ) ;
return V_43 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_43 = - V_31 ;
switch ( F_7 ( V_2 ) -> V_24 ) {
case 7 :
case 6 :
V_43 = F_58 ( V_2 ) ;
break;
case 5 :
V_43 = F_57 ( V_2 ) ;
break;
case 4 :
V_43 = F_54 ( V_2 ) ;
break;
case 2 :
V_43 = F_44 ( V_2 ) ;
break;
}
if ( V_4 -> V_68 ) {
F_64 ( L_8 ) ;
V_4 -> V_68 = 0 ;
if ( V_43 == - V_31 ) {
F_22 ( L_9
L_10 ) ;
V_43 = 0 ;
}
}
return V_43 ;
}
int F_65 ( struct V_1 * V_2 )
{
T_4 * V_4 = V_2 -> V_5 ;
int V_43 ;
if ( ! V_69 )
return 0 ;
F_26 ( & V_2 -> V_38 ) ;
F_66 ( V_2 ) ;
V_43 = - V_31 ;
if ( F_67 () - V_4 -> V_70 < 5 )
F_22 ( L_11 ) ;
else
V_43 = F_63 ( V_2 ) ;
V_4 -> V_70 = F_67 () ;
if ( V_43 ) {
F_22 ( L_12 ) ;
F_28 ( & V_2 -> V_38 ) ;
return V_43 ;
}
if ( F_12 ( V_2 , V_28 ) ||
! V_4 -> V_39 . V_40 ) {
struct V_71 * V_72 ;
int V_73 ;
V_4 -> V_39 . V_40 = 0 ;
F_68 ( V_2 ) ;
F_69 (ring, dev_priv, i)
V_72 -> V_74 ( V_72 ) ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_28 ( & V_2 -> V_38 ) ;
F_15 ( V_2 ) ;
F_37 ( V_2 ) ;
} else {
F_28 ( & V_2 -> V_38 ) ;
}
return 0 ;
}
static int T_5
F_72 ( struct V_6 * V_27 , const struct V_75 * V_76 )
{
struct V_77 * V_78 =
(struct V_77 * ) V_76 -> V_79 ;
if ( F_73 ( V_27 -> V_80 ) )
return - V_31 ;
if ( V_78 -> V_24 != 3 ) {
V_81 . V_82 &=
~ ( V_83 | V_84 ) ;
} else if ( ! V_85 ) {
F_22 ( L_13 ) ;
return - V_31 ;
}
return F_74 ( V_27 , V_76 , & V_81 ) ;
}
static void
F_75 ( struct V_6 * V_27 )
{
struct V_1 * V_2 = F_76 ( V_27 ) ;
F_77 ( V_2 ) ;
}
static int F_78 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_79 ( V_2 ) ;
struct V_1 * V_86 = F_76 ( V_27 ) ;
int error ;
if ( ! V_86 || ! V_86 -> V_5 ) {
F_14 ( V_2 , L_7 ) ;
return - V_31 ;
}
if ( V_86 -> V_34 == V_35 )
return 0 ;
error = F_9 ( V_86 ) ;
if ( error )
return error ;
F_23 ( V_27 ) ;
F_24 ( V_27 , V_37 ) ;
return 0 ;
}
static int F_80 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_79 ( V_2 ) ;
struct V_1 * V_86 = F_76 ( V_27 ) ;
return F_40 ( V_86 ) ;
}
static int F_81 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_79 ( V_2 ) ;
struct V_1 * V_86 = F_76 ( V_27 ) ;
if ( ! V_86 || ! V_86 -> V_5 ) {
F_14 ( V_2 , L_7 ) ;
return - V_31 ;
}
return F_9 ( V_86 ) ;
}
static int F_82 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_79 ( V_2 ) ;
struct V_1 * V_86 = F_76 ( V_27 ) ;
return F_25 ( V_86 ) ;
}
static int F_83 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_79 ( V_2 ) ;
struct V_1 * V_86 = F_76 ( V_27 ) ;
return F_9 ( V_86 ) ;
}
static int T_6 F_84 ( void )
{
V_81 . V_87 = V_88 ;
#if F_85 ( V_89 )
if ( V_90 != 0 )
V_81 . V_82 |= V_28 ;
#endif
if ( V_90 == 1 )
V_81 . V_82 |= V_28 ;
#ifdef F_86
if ( F_87 () && V_90 == - 1 )
V_81 . V_82 &= ~ V_28 ;
#endif
if ( ! ( V_81 . V_82 & V_28 ) )
V_81 . V_91 = NULL ;
return F_88 ( & V_81 , & V_92 ) ;
}
static void T_7 F_89 ( void )
{
F_90 ( & V_81 , & V_92 ) ;
}
static bool F_91 ( T_3 V_93 )
{
if ( V_93 >= 0x180000 )
return false ;
if ( V_93 >= V_94 &&
V_93 < V_94 + 0xff )
return false ;
if ( V_93 >= V_95 &&
V_93 < V_95 + 0xff )
return false ;
if ( V_93 >= V_96 &&
V_93 < V_96 + 0xff )
return false ;
if ( V_93 == V_97 )
return false ;
if ( V_93 >= V_98 &&
V_93 < V_99 )
return false ;
if ( V_93 == V_100 )
return false ;
if ( V_93 == V_101 )
return false ;
if ( V_93 == V_102 ||
V_93 == V_103 ||
V_93 == V_104 )
return false ;
if ( V_93 == V_105 ||
V_93 == V_106 )
return false ;
if ( V_93 == V_107 )
return false ;
if ( V_93 >= 0x4000c &&
V_93 <= 0x4002c )
return false ;
if ( V_93 >= 0x4f000 &&
V_93 <= 0x4f08f )
return false ;
if ( V_93 >= 0x4f100 &&
V_93 <= 0x4f11f )
return false ;
if ( V_93 >= V_108 &&
V_93 <= V_109 )
return false ;
if ( V_93 >= V_110 &&
V_93 < ( V_110 + ( 16 * 8 ) ) )
return false ;
if ( V_93 >= V_111 &&
V_93 <= V_112 )
return false ;
if ( V_93 == V_113 ||
V_93 == V_114 )
return false ;
if ( V_93 == V_60 )
return false ;
return true ;
}
