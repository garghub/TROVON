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
F_16 ( V_2 ) ;
}
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_4 -> V_29 = 0 ;
F_19 () ;
F_20 ( V_2 , 1 ) ;
F_21 () ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_30 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_23 ( L_6 , V_2 ) ;
F_23 ( L_7 ) ;
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
F_24 ( V_2 -> V_27 ) ;
F_25 ( V_2 -> V_27 , V_37 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
if ( F_12 ( V_2 , V_28 ) ) {
F_27 ( & V_2 -> V_38 ) ;
F_28 ( V_2 ) ;
F_29 ( & V_2 -> V_38 ) ;
}
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
if ( F_12 ( V_2 , V_28 ) ) {
if ( F_32 ( V_2 ) || F_33 ( V_2 ) )
F_34 ( V_2 ) ;
F_27 ( & V_2 -> V_38 ) ;
V_4 -> V_39 . V_40 = 0 ;
error = F_35 ( V_2 ) ;
F_29 ( & V_2 -> V_38 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
}
F_40 ( V_2 ) ;
V_4 -> V_29 = 0 ;
F_19 () ;
F_20 ( V_2 , 0 ) ;
F_21 () ;
return error ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_41 ;
if ( V_2 -> V_34 == V_35 )
return 0 ;
if ( F_42 ( V_2 -> V_27 ) )
return - V_42 ;
F_43 ( V_2 -> V_27 ) ;
V_41 = F_26 ( V_2 ) ;
if ( V_41 )
return V_41 ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_46 ( V_2 ) )
return - V_31 ;
F_47 ( V_43 , F_48 ( V_43 ) | V_44 ) ;
F_49 ( V_43 ) ;
if ( F_50 ( V_2 ) || F_51 ( V_2 ) ) {
F_47 ( V_45 ,
V_46 |
V_47 |
V_48 ) ;
F_49 ( V_45 ) ;
F_52 ( 1 ) ;
F_47 ( V_45 , 0 ) ;
F_49 ( V_45 ) ;
}
F_52 ( 1 ) ;
F_47 ( V_43 , F_48 ( V_43 ) & ~ V_44 ) ;
F_49 ( V_43 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
T_2 V_49 ;
F_54 ( V_2 -> V_27 , V_50 , & V_49 ) ;
return ( V_49 & V_51 ) == 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_41 ;
T_2 V_49 ;
F_54 ( V_2 -> V_27 , V_50 , & V_49 ) ;
F_56 ( V_2 -> V_27 , V_50 ,
V_49 | V_52 |
V_51 ) ;
V_41 = F_57 ( F_53 ( V_2 ) , 500 ) ;
if ( V_41 )
return V_41 ;
F_54 ( V_2 -> V_27 , V_50 , & V_49 ) ;
F_56 ( V_2 -> V_27 , V_50 ,
V_49 | V_53 |
V_51 ) ;
return F_57 ( F_53 ( V_2 ) , 500 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_49 ;
int V_41 ;
V_49 = F_48 ( V_54 + V_55 ) ;
F_47 ( V_54 + V_55 ,
V_49 | V_52 | V_51 ) ;
V_41 = F_57 ( F_48 ( V_54 + V_55 ) & 0x1 , 500 ) ;
if ( V_41 )
return V_41 ;
V_49 = F_48 ( V_54 + V_55 ) ;
F_47 ( V_54 + V_55 ,
V_49 | V_53 | V_51 ) ;
return F_57 ( F_48 ( V_54 + V_55 ) & 0x1 , 500 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_41 ;
unsigned long V_56 ;
F_60 ( & V_4 -> V_57 , V_56 ) ;
F_61 ( V_58 , V_59 ) ;
V_41 = F_57 ( ( F_62 ( V_58 ) & V_59 ) == 0 , 500 ) ;
if ( V_4 -> V_60 )
V_4 -> V_61 . V_62 ( V_4 ) ;
else
V_4 -> V_61 . V_63 ( V_4 ) ;
V_4 -> V_64 = F_62 ( V_65 ) ;
F_63 ( & V_4 -> V_57 , V_56 ) ;
return V_41 ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_41 = - V_31 ;
switch ( F_7 ( V_2 ) -> V_24 ) {
case 7 :
case 6 :
V_41 = F_59 ( V_2 ) ;
break;
case 5 :
V_41 = F_58 ( V_2 ) ;
break;
case 4 :
V_41 = F_55 ( V_2 ) ;
break;
case 2 :
V_41 = F_45 ( V_2 ) ;
break;
}
if ( V_4 -> V_66 ) {
F_65 ( L_8 ) ;
V_4 -> V_66 = 0 ;
if ( V_41 == - V_31 ) {
F_23 ( L_9
L_10 ) ;
V_41 = 0 ;
}
}
return V_41 ;
}
int F_66 ( struct V_1 * V_2 )
{
T_4 * V_4 = V_2 -> V_5 ;
int V_41 ;
if ( ! V_67 )
return 0 ;
F_27 ( & V_2 -> V_38 ) ;
F_67 ( V_2 ) ;
V_41 = - V_31 ;
if ( F_68 () - V_4 -> V_68 < 5 )
F_23 ( L_11 ) ;
else
V_41 = F_64 ( V_2 ) ;
V_4 -> V_68 = F_68 () ;
if ( V_41 ) {
F_23 ( L_12 ) ;
F_29 ( & V_2 -> V_38 ) ;
return V_41 ;
}
if ( F_12 ( V_2 , V_28 ) ||
! V_4 -> V_39 . V_40 ) {
struct V_69 * V_70 ;
int V_71 ;
V_4 -> V_39 . V_40 = 0 ;
F_69 ( V_2 ) ;
F_70 (ring, dev_priv, i)
V_70 -> V_72 ( V_70 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
F_29 ( & V_2 -> V_38 ) ;
F_16 ( V_2 ) ;
F_39 ( V_2 ) ;
} else {
F_29 ( & V_2 -> V_38 ) ;
}
return 0 ;
}
static int T_5
F_73 ( struct V_6 * V_27 , const struct V_73 * V_74 )
{
struct V_75 * V_76 =
(struct V_75 * ) V_74 -> V_77 ;
if ( V_76 -> V_78 || V_76 -> V_79 )
if( ! V_80 ) {
F_23 ( L_13 ) ;
return - V_31 ;
}
if ( F_74 ( V_27 -> V_81 ) )
return - V_31 ;
if ( V_76 -> V_24 != 3 ) {
V_82 . V_83 &=
~ ( V_84 | V_85 ) ;
} else if ( ! V_86 ) {
F_23 ( L_14 ) ;
return - V_31 ;
}
return F_75 ( V_27 , V_74 , & V_82 ) ;
}
static void
F_76 ( struct V_6 * V_27 )
{
struct V_1 * V_2 = F_77 ( V_27 ) ;
F_78 ( V_2 ) ;
}
static int F_79 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_80 ( V_2 ) ;
struct V_1 * V_87 = F_77 ( V_27 ) ;
int error ;
if ( ! V_87 || ! V_87 -> V_5 ) {
F_14 ( V_2 , L_7 ) ;
return - V_31 ;
}
if ( V_87 -> V_34 == V_35 )
return 0 ;
error = F_9 ( V_87 ) ;
if ( error )
return error ;
F_24 ( V_27 ) ;
F_25 ( V_27 , V_37 ) ;
return 0 ;
}
static int F_81 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_80 ( V_2 ) ;
struct V_1 * V_87 = F_77 ( V_27 ) ;
return F_41 ( V_87 ) ;
}
static int F_82 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_80 ( V_2 ) ;
struct V_1 * V_87 = F_77 ( V_27 ) ;
if ( ! V_87 || ! V_87 -> V_5 ) {
F_14 ( V_2 , L_7 ) ;
return - V_31 ;
}
return F_9 ( V_87 ) ;
}
static int F_83 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_80 ( V_2 ) ;
struct V_1 * V_87 = F_77 ( V_27 ) ;
return F_26 ( V_87 ) ;
}
static int F_84 ( struct V_12 * V_2 )
{
struct V_6 * V_27 = F_80 ( V_2 ) ;
struct V_1 * V_87 = F_77 ( V_27 ) ;
return F_9 ( V_87 ) ;
}
static int T_6 F_85 ( void )
{
V_82 . V_88 = V_89 ;
#if F_86 ( V_90 )
if ( V_91 != 0 )
V_82 . V_83 |= V_28 ;
#endif
if ( V_91 == 1 )
V_82 . V_83 |= V_28 ;
#ifdef F_87
if ( F_88 () && V_91 == - 1 )
V_82 . V_83 &= ~ V_28 ;
#endif
if ( ! ( V_82 . V_83 & V_28 ) )
V_82 . V_92 = NULL ;
return F_89 ( & V_82 , & V_93 ) ;
}
static void T_7 F_90 ( void )
{
F_91 ( & V_82 , & V_93 ) ;
}
static bool F_92 ( T_3 V_94 )
{
if ( V_94 >= V_95 )
return false ;
if ( V_94 >= V_96 &&
V_94 < V_96 + 0xff )
return false ;
if ( V_94 >= V_97 &&
V_94 < V_97 + 0xff )
return false ;
if ( V_94 >= V_98 &&
V_94 < V_98 + 0xff )
return false ;
if ( V_94 == V_99 )
return false ;
if ( V_94 >= V_100 &&
V_94 < V_101 )
return false ;
if ( V_94 == V_102 )
return false ;
if ( V_94 == V_103 )
return false ;
if ( V_94 == V_104 ||
V_94 == V_105 ||
V_94 == V_106 )
return false ;
if ( V_94 == V_107 ||
V_94 == V_108 )
return false ;
if ( V_94 == V_109 )
return false ;
if ( V_94 >= 0x4000c &&
V_94 <= 0x4002c )
return false ;
if ( V_94 >= 0x4f000 &&
V_94 <= 0x4f08f )
return false ;
if ( V_94 >= 0x4f100 &&
V_94 <= 0x4f11f )
return false ;
if ( V_94 >= V_110 &&
V_94 <= V_111 )
return false ;
if ( V_94 >= V_112 &&
V_94 < ( V_112 + ( 16 * 8 ) ) )
return false ;
if ( V_94 >= V_113 &&
V_94 <= V_114 )
return false ;
if ( V_94 == V_115 ||
V_94 == V_116 )
return false ;
if ( V_94 == V_58 )
return false ;
return true ;
}
int F_93 ( struct V_1 * V_2 ,
void * V_117 , struct V_118 * V_119 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_120 * V_94 = V_117 ;
struct V_121 const * V_122 = V_123 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < F_94 ( V_123 ) ; V_71 ++ , V_122 ++ ) {
if ( V_122 -> V_124 == V_94 -> V_124 &&
( 1 << F_7 ( V_2 ) -> V_24 & V_122 -> V_125 ) )
break;
}
if ( V_71 == F_94 ( V_123 ) )
return - V_126 ;
switch ( V_122 -> V_127 ) {
case 8 :
V_94 -> V_128 = F_95 ( V_94 -> V_124 ) ;
break;
case 4 :
V_94 -> V_128 = F_48 ( V_94 -> V_124 ) ;
break;
case 2 :
V_94 -> V_128 = F_96 ( V_94 -> V_124 ) ;
break;
case 1 :
V_94 -> V_128 = F_97 ( V_94 -> V_124 ) ;
break;
default:
F_98 ( 1 ) ;
return - V_126 ;
}
return 0 ;
}
