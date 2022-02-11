void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_8 << 8 , NULL ) ;
if ( V_7 ) {
if ( V_7 -> V_9 == V_10 ) {
unsigned short V_11 ;
V_11 = V_7 -> V_12 & V_13 ;
V_4 -> V_14 = V_11 ;
if ( V_11 == V_15 ) {
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = 2 ;
F_3 ( L_1 ) ;
F_4 ( ! F_5 ( V_2 ) ) ;
} else if ( V_11 == V_19 ) {
V_4 -> V_16 = V_20 ;
V_4 -> V_18 = 2 ;
F_3 ( L_2 ) ;
F_4 ( ! ( F_6 ( V_2 ) || F_7 ( V_2 ) ) ) ;
} else if ( V_11 == V_21 ) {
V_4 -> V_16 = V_20 ;
V_4 -> V_18 = 2 ;
F_3 ( L_3 ) ;
F_4 ( ! ( F_6 ( V_2 ) || F_7 ( V_2 ) ) ) ;
} else if ( V_11 == V_22 ) {
V_4 -> V_16 = V_23 ;
V_4 -> V_18 = 0 ;
F_3 ( L_4 ) ;
F_4 ( ! F_8 ( V_2 ) ) ;
} else if ( V_11 == V_24 ) {
V_4 -> V_16 = V_23 ;
V_4 -> V_18 = 0 ;
F_3 ( L_5 ) ;
F_4 ( ! F_8 ( V_2 ) ) ;
}
F_9 ( V_4 -> V_18 > V_25 ) ;
}
F_10 ( V_7 ) ;
}
}
bool F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) -> V_26 < 6 )
return 0 ;
if ( V_27 >= 0 )
return V_27 ;
#ifdef F_13
if ( F_12 ( V_2 ) -> V_26 == 6 && V_28 )
return false ;
#endif
return 1 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_15 ( V_2 ) ;
F_16 ( V_2 -> V_29 ) ;
if ( F_17 ( V_2 , V_30 ) ) {
int error = F_18 ( V_2 ) ;
if ( error ) {
F_19 ( & V_2 -> V_29 -> V_2 ,
L_6 ) ;
return error ;
}
F_20 ( & V_4 -> V_31 . V_32 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
}
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
V_4 -> V_33 = 0 ;
F_25 () ;
F_26 ( V_2 , 1 ) ;
F_27 () ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_34 )
{
int error ;
if ( ! V_2 || ! V_2 -> V_5 ) {
F_29 ( L_7 , V_2 ) ;
F_29 ( L_8 ) ;
return - V_35 ;
}
if ( V_34 . V_36 == V_37 )
return 0 ;
if ( V_2 -> V_38 == V_39 )
return 0 ;
error = F_14 ( V_2 ) ;
if ( error )
return error ;
if ( V_34 . V_36 == V_40 ) {
F_30 ( V_2 -> V_29 ) ;
F_31 ( V_2 -> V_29 , V_41 ) ;
}
return 0 ;
}
void F_32 ( struct V_42 * V_43 )
{
struct V_3 * V_4 =
F_33 ( V_43 , struct V_3 ,
V_44 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_25 () ;
F_26 ( V_2 , 0 ) ;
F_27 () ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int error = 0 ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
if ( F_17 ( V_2 , V_30 ) ) {
F_37 ( V_2 ) ;
F_38 ( & V_2 -> V_45 ) ;
V_4 -> V_46 . V_47 = 0 ;
error = F_39 ( V_2 ) ;
F_40 ( & V_2 -> V_45 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 , false ) ;
F_43 ( V_2 ) ;
}
F_44 ( V_2 ) ;
V_4 -> V_33 = 0 ;
if ( F_45 () ) {
F_26 ( V_2 , 0 ) ;
F_27 () ;
} else {
F_46 ( & V_4 -> V_44 ) ;
}
return error ;
}
static int F_47 ( struct V_1 * V_2 )
{
int error = 0 ;
F_48 ( V_2 ) ;
if ( F_17 ( V_2 , V_30 ) ) {
F_38 ( & V_2 -> V_45 ) ;
F_49 ( V_2 ) ;
F_40 ( & V_2 -> V_45 ) ;
}
F_34 ( V_2 ) ;
return error ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_48 ;
if ( V_2 -> V_38 == V_39 )
return 0 ;
if ( F_51 ( V_2 -> V_29 ) )
return - V_49 ;
F_52 ( V_2 -> V_29 ) ;
F_48 ( V_2 ) ;
if ( F_17 ( V_2 , V_30 ) &&
! V_4 -> V_50 . V_51 ) {
F_38 ( & V_2 -> V_45 ) ;
F_49 ( V_2 ) ;
F_40 ( & V_2 -> V_45 ) ;
}
V_48 = F_34 ( V_2 ) ;
if ( V_48 )
return V_48 ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_55 ( V_2 ) )
return - V_35 ;
F_56 ( V_52 , F_57 ( V_52 ) | V_53 ) ;
F_58 ( V_52 ) ;
if ( F_59 ( V_2 ) || F_60 ( V_2 ) ) {
F_56 ( V_54 ,
V_55 |
V_56 |
V_57 ) ;
F_58 ( V_54 ) ;
F_61 ( 1 ) ;
F_56 ( V_54 , 0 ) ;
F_58 ( V_54 ) ;
}
F_61 ( 1 ) ;
F_56 ( V_52 , F_57 ( V_52 ) & ~ V_53 ) ;
F_58 ( V_52 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
T_2 V_58 ;
F_63 ( V_2 -> V_29 , V_59 , & V_58 ) ;
return ( V_58 & V_60 ) == 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_48 ;
T_2 V_58 ;
F_63 ( V_2 -> V_29 , V_59 , & V_58 ) ;
F_65 ( V_2 -> V_29 , V_59 ,
V_58 | V_61 |
V_60 ) ;
V_48 = F_66 ( F_62 ( V_2 ) , 500 ) ;
if ( V_48 )
return V_48 ;
F_63 ( V_2 -> V_29 , V_59 , & V_58 ) ;
F_65 ( V_2 -> V_29 , V_59 ,
V_58 | V_62 |
V_60 ) ;
return F_66 ( F_62 ( V_2 ) , 500 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_3 V_58 ;
int V_48 ;
V_58 = F_57 ( V_63 + V_64 ) ;
F_56 ( V_63 + V_64 ,
V_58 | V_61 | V_60 ) ;
V_48 = F_66 ( F_57 ( V_63 + V_64 ) & 0x1 , 500 ) ;
if ( V_48 )
return V_48 ;
V_58 = F_57 ( V_63 + V_64 ) ;
F_56 ( V_63 + V_64 ,
V_58 | V_62 | V_60 ) ;
return F_66 ( F_57 ( V_63 + V_64 ) & 0x1 , 500 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_48 ;
unsigned long V_65 ;
F_69 ( & V_4 -> V_66 , V_65 ) ;
F_70 ( V_67 , V_68 ) ;
V_48 = F_66 ( ( F_71 ( V_67 ) & V_68 ) == 0 , 500 ) ;
if ( V_4 -> V_69 )
V_4 -> V_70 . V_71 ( V_4 ) ;
else
V_4 -> V_70 . V_72 ( V_4 ) ;
V_4 -> V_73 = F_71 ( V_74 ) ;
F_72 ( & V_4 -> V_66 , V_65 ) ;
return V_48 ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_48 = - V_35 ;
switch ( F_12 ( V_2 ) -> V_26 ) {
case 7 :
case 6 :
V_48 = F_68 ( V_2 ) ;
break;
case 5 :
V_48 = F_67 ( V_2 ) ;
break;
case 4 :
V_48 = F_64 ( V_2 ) ;
break;
case 2 :
V_48 = F_54 ( V_2 ) ;
break;
}
if ( V_4 -> V_75 ) {
F_74 ( L_9 ) ;
V_4 -> V_75 = 0 ;
if ( V_48 == - V_35 ) {
F_29 ( L_10
L_11 ) ;
V_48 = 0 ;
}
}
return V_48 ;
}
int F_75 ( struct V_1 * V_2 )
{
T_4 * V_4 = V_2 -> V_5 ;
int V_48 ;
if ( ! V_76 )
return 0 ;
F_38 ( & V_2 -> V_45 ) ;
F_76 ( V_2 ) ;
V_48 = - V_35 ;
if ( F_77 () - V_4 -> V_77 < 5 )
F_29 ( L_12 ) ;
else
V_48 = F_73 ( V_2 ) ;
V_4 -> V_77 = F_77 () ;
if ( V_48 ) {
F_29 ( L_13 ) ;
F_40 ( & V_2 -> V_45 ) ;
return V_48 ;
}
if ( F_17 ( V_2 , V_30 ) ||
! V_4 -> V_46 . V_47 ) {
struct V_78 * V_79 ;
int V_80 ;
V_4 -> V_46 . V_47 = 0 ;
F_78 ( V_2 ) ;
F_79 (ring, dev_priv, i)
V_79 -> V_81 ( V_79 ) ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_40 ( & V_2 -> V_45 ) ;
F_22 ( V_2 ) ;
F_43 ( V_2 ) ;
} else {
F_40 ( & V_2 -> V_45 ) ;
}
return 0 ;
}
static int F_82 ( struct V_6 * V_29 , const struct V_82 * V_83 )
{
struct V_84 * V_85 =
(struct V_84 * ) V_83 -> V_86 ;
if ( V_85 -> V_87 )
if( ! V_88 ) {
F_29 ( L_14 ) ;
return - V_35 ;
}
if ( F_83 ( V_29 -> V_89 ) )
return - V_35 ;
if ( V_85 -> V_26 != 3 ) {
V_90 . V_91 &=
~ ( V_92 | V_93 ) ;
} else if ( ! V_94 ) {
F_29 ( L_15 ) ;
return - V_35 ;
}
return F_84 ( V_29 , V_83 , & V_90 ) ;
}
static void
F_85 ( struct V_6 * V_29 )
{
struct V_1 * V_2 = F_86 ( V_29 ) ;
F_87 ( V_2 ) ;
}
static int F_88 ( struct V_12 * V_2 )
{
struct V_6 * V_29 = F_89 ( V_2 ) ;
struct V_1 * V_95 = F_86 ( V_29 ) ;
int error ;
if ( ! V_95 || ! V_95 -> V_5 ) {
F_19 ( V_2 , L_8 ) ;
return - V_35 ;
}
if ( V_95 -> V_38 == V_39 )
return 0 ;
error = F_14 ( V_95 ) ;
if ( error )
return error ;
F_30 ( V_29 ) ;
F_31 ( V_29 , V_41 ) ;
return 0 ;
}
static int F_90 ( struct V_12 * V_2 )
{
struct V_6 * V_29 = F_89 ( V_2 ) ;
struct V_1 * V_95 = F_86 ( V_29 ) ;
return F_50 ( V_95 ) ;
}
static int F_91 ( struct V_12 * V_2 )
{
struct V_6 * V_29 = F_89 ( V_2 ) ;
struct V_1 * V_95 = F_86 ( V_29 ) ;
if ( ! V_95 || ! V_95 -> V_5 ) {
F_19 ( V_2 , L_8 ) ;
return - V_35 ;
}
return F_14 ( V_95 ) ;
}
static int F_92 ( struct V_12 * V_2 )
{
struct V_6 * V_29 = F_89 ( V_2 ) ;
struct V_1 * V_95 = F_86 ( V_29 ) ;
return F_47 ( V_95 ) ;
}
static int F_93 ( struct V_12 * V_2 )
{
struct V_6 * V_29 = F_89 ( V_2 ) ;
struct V_1 * V_95 = F_86 ( V_29 ) ;
return F_14 ( V_95 ) ;
}
static int T_5 F_94 ( void )
{
V_90 . V_96 = V_97 ;
#if F_95 ( V_98 )
if ( V_99 != 0 )
V_90 . V_91 |= V_30 ;
#endif
if ( V_99 == 1 )
V_90 . V_91 |= V_30 ;
#ifdef F_96
if ( F_97 () && V_99 == - 1 )
V_90 . V_91 &= ~ V_30 ;
#endif
if ( ! ( V_90 . V_91 & V_30 ) )
V_90 . V_100 = NULL ;
return F_98 ( & V_90 , & V_101 ) ;
}
static void T_6 F_99 ( void )
{
F_100 ( & V_90 , & V_101 ) ;
}
static bool F_101 ( T_3 V_102 )
{
if ( V_102 >= V_103 )
return false ;
if ( V_102 >= V_104 &&
V_102 < V_104 + 0xff )
return false ;
if ( V_102 >= V_105 &&
V_102 < V_105 + 0xff )
return false ;
if ( V_102 >= V_106 &&
V_102 < V_106 + 0xff )
return false ;
if ( V_102 == V_107 )
return false ;
if ( V_102 >= V_108 &&
V_102 < V_109 )
return false ;
if ( V_102 == V_110 )
return false ;
if ( V_102 == V_111 )
return false ;
if ( V_102 == V_112 ||
V_102 == V_113 ||
V_102 == V_114 )
return false ;
if ( V_102 == V_115 ||
V_102 == V_116 )
return false ;
if ( V_102 == V_117 )
return false ;
if ( V_102 >= 0x4000c &&
V_102 <= 0x4002c )
return false ;
if ( V_102 >= 0x4f000 &&
V_102 <= 0x4f08f )
return false ;
if ( V_102 >= 0x4f100 &&
V_102 <= 0x4f11f )
return false ;
if ( V_102 >= V_118 &&
V_102 <= V_119 )
return false ;
if ( V_102 >= V_120 &&
V_102 < ( V_120 + ( 16 * 8 ) ) )
return false ;
if ( V_102 >= V_121 &&
V_102 <= V_122 )
return false ;
if ( V_102 == V_123 ||
V_102 == V_124 )
return false ;
if ( V_102 == V_67 )
return false ;
switch ( V_102 ) {
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
return false ;
default:
break;
}
return true ;
}
static void
F_102 ( struct V_3 * V_4 )
{
F_70 ( V_110 , 0 ) ;
}
int F_103 ( struct V_1 * V_2 ,
void * V_136 , struct V_137 * V_138 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_139 * V_102 = V_136 ;
struct V_140 const * V_141 = V_142 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < F_104 ( V_142 ) ; V_80 ++ , V_141 ++ ) {
if ( V_141 -> V_143 == V_102 -> V_143 &&
( 1 << F_12 ( V_2 ) -> V_26 & V_141 -> V_144 ) )
break;
}
if ( V_80 == F_104 ( V_142 ) )
return - V_145 ;
switch ( V_141 -> V_146 ) {
case 8 :
V_102 -> V_147 = F_105 ( V_102 -> V_143 ) ;
break;
case 4 :
V_102 -> V_147 = F_57 ( V_102 -> V_143 ) ;
break;
case 2 :
V_102 -> V_147 = F_106 ( V_102 -> V_143 ) ;
break;
case 1 :
V_102 -> V_147 = F_107 ( V_102 -> V_143 ) ;
break;
default:
F_4 ( 1 ) ;
return - V_145 ;
}
return 0 ;
}
