static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_5 ) ;
V_3 &= ~ V_6 ;
F_3 ( V_2 , V_4 , V_5 , V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_7 ) ;
V_3 &= ~ V_6 ;
F_3 ( V_2 , V_4 , V_7 , V_3 ) ;
V_3 = F_2 ( V_2 , V_8 , V_9 ) ;
V_3 &= ~ V_10 ;
F_3 ( V_2 , V_8 , V_9 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_8 , V_9 ) ;
V_3 |= V_10 ;
F_3 ( V_2 , V_8 , V_9 , V_3 ) ;
V_3 = F_2 ( V_2 , V_4 , V_7 ) ;
V_3 |= V_6 ;
F_3 ( V_2 , V_4 , V_7 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_11 , V_12 , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_11 , V_13 , 0 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_11 , V_13 , V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_15 ) {
case V_16 :
case V_17 :
F_8 ( V_2 ) ;
break;
case V_18 :
case V_19 :
F_5 ( V_2 ) ;
break;
default:
break;
}
}
static void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 , V_20 , V_21 ) ;
V_3 |= V_22 ;
F_3 ( V_2 , V_20 , V_21 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 , V_20 , V_21 ) ;
V_3 &= ~ V_22 ;
F_3 ( V_2 , V_20 , V_21 , V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
V_2 -> V_23 . V_24 ( V_2 , V_25 ) ;
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_29 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
V_2 -> V_23 . V_24 ( V_2 , V_30 ) ;
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_31 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
V_2 -> V_23 . V_24 ( V_2 , V_32 ) ;
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_33 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 )
return F_13 ( V_2 ) ;
F_12 ( V_2 ) ;
V_2 -> V_23 . V_24 ( V_2 , V_25 ) ;
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_35 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
V_2 -> V_23 . V_24 ( V_2 , V_32 ) ;
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_36 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
V_2 -> V_23 . V_24 ( V_2 , V_32 ) ;
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_37 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
V_2 -> V_23 . V_24 ( V_2 , V_32 ) ;
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_38 ) ;
}
static enum V_39 F_20 ( struct V_1 * V_2 )
{
return V_2 -> V_26 . V_27 . V_40 ( V_2 ) ;
}
static bool F_21 ( struct V_1 * V_2 )
{
return ( F_20 ( V_2 ) == V_29 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
enum V_39 V_41 )
{
switch ( V_41 ) {
case V_33 :
F_15 ( V_2 ) ;
break;
case V_31 :
F_14 ( V_2 ) ;
break;
case V_29 :
F_13 ( V_2 ) ;
break;
case V_38 :
F_19 ( V_2 ) ;
break;
case V_37 :
F_18 ( V_2 ) ;
break;
case V_36 :
F_17 ( V_2 ) ;
break;
case V_35 :
F_16 ( V_2 ) ;
break;
case V_42 :
break;
default:
F_23 ( V_2 , V_43 , V_2 -> V_44 ,
L_1 , V_41 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_2 -> V_26 . V_27 . V_45 ( V_2 ) ) ;
}
static void F_25 ( struct V_1 * V_2 ,
enum V_39 V_41 )
{
if ( V_41 == F_20 ( V_2 ) )
return;
F_22 ( V_2 , V_41 ) ;
}
static bool F_26 ( struct V_1 * V_2 ,
enum V_39 V_41 )
{
return V_2 -> V_26 . V_27 . V_46 ( V_2 , V_41 ) ;
}
static void F_27 ( struct V_1 * V_2 , bool V_47 ,
bool V_48 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_49 ) ;
V_3 &= ~ V_50 ;
if ( V_47 )
V_3 |= V_50 ;
if ( V_48 )
V_3 |= V_51 ;
F_3 ( V_2 , V_4 , V_49 , V_3 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_27 ( V_2 , true , true ) ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_27 ( V_2 , false , false ) ;
F_4 ( V_2 ) ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_3 ) ;
}
static void F_30 ( struct V_1 * V_2 , bool V_47 ,
bool V_48 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 , V_11 , V_49 ) ;
V_3 &= ~ V_52 ;
if ( V_47 )
V_3 |= V_52 ;
if ( V_48 )
V_3 |= V_53 ;
F_3 ( V_2 , V_11 , V_49 , V_3 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_30 ( V_2 , true , true ) ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_4 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_30 ( V_2 , false , false ) ;
F_7 ( V_2 ) ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_5 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_15 ) {
case V_16 :
case V_17 :
F_31 ( V_2 ) ;
break;
case V_18 :
case V_19 :
F_28 ( V_2 ) ;
break;
default:
break;
}
}
static void F_34 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_15 ) {
case V_16 :
case V_17 :
F_32 ( V_2 ) ;
break;
case V_18 :
case V_19 :
F_29 ( V_2 ) ;
break;
default:
break;
}
}
static void F_35 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static enum V_54 F_36 ( struct V_1 * V_2 ,
enum V_55 * V_56 )
{
unsigned int V_57 , V_58 , V_3 ;
* V_56 = V_59 ;
if ( ! F_21 ( V_2 ) )
return V_60 ;
V_57 = F_2 ( V_2 , V_11 , V_61 + 2 ) ;
V_58 = F_2 ( V_2 , V_11 , V_62 + 2 ) ;
V_3 = F_2 ( V_2 , V_20 , V_63 ) ;
V_3 &= ~ ( V_64 | V_65 ) ;
if ( ( V_57 & 0xc000 ) && ( V_58 & 0xc000 ) )
V_3 |= V_2 -> V_66 ;
F_3 ( V_2 , V_20 , V_63 , V_3 ) ;
V_3 = F_2 ( V_2 , V_20 , V_21 ) ;
if ( V_3 & V_22 ) {
if ( V_2 -> V_26 . V_27 . V_67 )
V_2 -> V_26 . V_27 . V_67 ( V_2 ) ;
V_3 |= V_68 ;
F_3 ( V_2 , V_20 , V_21 ,
V_3 ) ;
if ( V_2 -> V_26 . V_27 . V_69 )
V_2 -> V_26 . V_27 . V_69 ( V_2 ) ;
F_23 ( V_2 , V_43 , V_2 -> V_44 ,
L_6 ) ;
}
return V_60 ;
}
static enum V_54 F_37 ( struct V_1 * V_2 ,
enum V_55 * V_56 )
{
T_1 V_70 ;
* V_56 = V_71 ;
V_70 = V_72 ;
V_70 |= V_73 ;
F_3 ( V_2 , V_11 , V_74 + 2 , 0 ) ;
F_3 ( V_2 , V_11 , V_74 + 1 , 0 ) ;
F_3 ( V_2 , V_11 , V_74 , V_70 ) ;
return V_60 ;
}
static enum V_54 F_38 ( struct V_1 * V_2 ,
enum V_55 * V_56 )
{
unsigned int V_75 ;
unsigned int V_3 , V_57 , V_58 ;
V_3 = F_2 ( V_2 , V_11 , V_62 + 1 ) ;
V_75 = F_21 ( V_2 ) ? 0x80 : 0x20 ;
if ( ! ( V_3 & V_75 ) )
return V_76 ;
V_57 = F_2 ( V_2 , V_11 , V_61 ) ;
V_58 = F_2 ( V_2 , V_11 , V_62 ) ;
return ( ( V_57 & V_77 ) ||
( V_58 & V_77 ) )
? F_37 ( V_2 , V_56 )
: F_36 ( V_2 , V_56 ) ;
}
static enum V_54 F_39 ( struct V_1 * V_2 ,
enum V_55 * V_56 )
{
unsigned int V_57 , V_58 ;
V_57 = F_2 ( V_2 , V_11 , V_74 ) ;
V_58 = F_2 ( V_2 , V_11 , V_78 ) ;
return ( ( V_57 & V_77 ) ||
( V_58 & V_77 ) )
? F_37 ( V_2 , V_56 )
: F_36 ( V_2 , V_56 ) ;
}
static enum V_54 F_40 ( struct V_1 * V_2 )
{
enum V_55 * V_56 ;
unsigned long V_79 ;
enum V_54 V_80 ;
if ( ! V_2 -> V_81 ) {
V_2 -> V_81 = V_82 ;
} else {
V_79 = V_2 -> V_81 +
F_41 ( V_83 ) ;
if ( F_42 ( V_82 , V_79 ) ) {
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = V_85 ;
V_2 -> V_81 = V_82 ;
F_23 ( V_2 , V_43 , V_2 -> V_44 ,
L_7 ) ;
}
}
V_56 = F_21 ( V_2 ) ? & V_2 -> V_84
: & V_2 -> V_86 ;
switch ( * V_56 ) {
case V_85 :
V_80 = F_38 ( V_2 , V_56 ) ;
break;
case V_71 :
V_80 = F_39 ( V_2 , V_56 ) ;
break;
default:
V_80 = V_87 ;
}
return V_80 ;
}
static enum V_54 F_43 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = & V_2 -> V_90 . V_89 ;
if ( F_21 ( V_2 ) ) {
V_2 -> V_84 = V_91 ;
if ( ! F_44 ( V_89 , 1000baseKX_Full ) &&
! F_44 ( V_89 , 2500baseX_Full ) )
return V_92 ;
if ( V_2 -> V_86 != V_85 )
return V_92 ;
} else {
V_2 -> V_86 = V_91 ;
if ( ! F_44 ( V_89 , 10000baseKR_Full ) )
return V_92 ;
if ( V_2 -> V_84 != V_85 )
return V_92 ;
}
F_32 ( V_2 ) ;
F_24 ( V_2 ) ;
F_31 ( V_2 ) ;
return V_76 ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
F_4 ( V_2 ) ;
V_3 = F_2 ( V_2 , V_4 , V_5 ) ;
V_2 -> V_93 = V_3 & V_6 ;
V_2 -> V_94 = V_3 & ~ V_6 ;
if ( V_2 -> V_93 ) {
V_3 &= ~ V_6 ;
F_3 ( V_2 , V_4 , V_5 , V_3 ) ;
F_46 ( V_2 -> V_95 , & V_2 -> V_96 ) ;
} else {
F_5 ( V_2 ) ;
if ( V_2 -> V_97 -> V_98 )
F_47 ( V_2 , V_99 , 1 << 3 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
V_2 -> V_93 = F_2 ( V_2 , V_11 , V_12 ) ;
if ( V_2 -> V_93 ) {
F_3 ( V_2 , V_11 , V_12 , ~ V_2 -> V_93 ) ;
F_46 ( V_2 -> V_95 , & V_2 -> V_96 ) ;
} else {
F_8 ( V_2 ) ;
if ( V_2 -> V_97 -> V_98 )
F_47 ( V_2 , V_99 , 1 << 3 ) ;
}
}
static void F_49 ( unsigned long V_100 )
{
struct V_1 * V_2 = (struct V_1 * ) V_100 ;
F_23 ( V_2 , V_101 , V_2 -> V_44 , L_8 ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
case V_17 :
F_48 ( V_2 ) ;
break;
case V_18 :
case V_19 :
F_45 ( V_2 ) ;
break;
default:
break;
}
}
static T_2 F_50 ( int V_102 , void * V_100 )
{
struct V_1 * V_2 = (struct V_1 * ) V_100 ;
if ( V_2 -> V_103 )
F_51 ( & V_2 -> V_104 ) ;
else
F_49 ( ( unsigned long ) V_2 ) ;
return V_105 ;
}
static T_2 F_52 ( struct V_1 * V_2 )
{
F_49 ( ( unsigned long ) V_2 ) ;
return V_105 ;
}
static void F_53 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_54 ( V_107 ,
struct V_1 ,
V_96 ) ;
F_55 ( & V_2 -> V_108 ) ;
F_46 ( V_2 -> V_95 , & V_2 -> V_108 ) ;
}
static const char * F_56 ( enum V_54 V_56 )
{
switch ( V_56 ) {
case V_109 :
return L_9 ;
case V_60 :
return L_10 ;
case V_76 :
return L_11 ;
case V_110 :
return L_12 ;
case V_92 :
return L_13 ;
case V_87 :
return L_14 ;
default:
return L_15 ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
enum V_54 V_111 = V_2 -> V_112 ;
if ( ! V_2 -> V_93 )
return;
if ( V_2 -> V_93 & V_113 ) {
V_2 -> V_112 = V_110 ;
V_2 -> V_93 &= ~ V_113 ;
if ( ( V_2 -> V_15 == V_19 ) &&
! ( V_2 -> V_94 & V_114 ) )
V_2 -> V_112 = V_92 ;
}
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_16 ,
F_56 ( V_2 -> V_112 ) ) ;
V_111 = V_2 -> V_112 ;
switch ( V_2 -> V_112 ) {
case V_109 :
break;
case V_110 :
F_23 ( V_2 , V_43 , V_2 -> V_44 ,
L_17 ) ;
break;
case V_92 :
break;
default:
V_2 -> V_112 = V_87 ;
}
if ( V_2 -> V_112 == V_87 ) {
F_58 ( V_2 -> V_44 ,
L_18 ,
V_111 ) ;
V_2 -> V_93 = 0 ;
F_1 ( V_2 ) ;
}
if ( V_2 -> V_112 >= V_110 ) {
V_2 -> V_115 = V_2 -> V_112 ;
V_2 -> V_112 = V_109 ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_19 ,
F_56 ( V_2 -> V_115 ) ) ;
}
F_5 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
enum V_54 V_111 = V_2 -> V_112 ;
if ( ! V_2 -> V_93 )
return;
V_116:
if ( V_2 -> V_93 & V_117 ) {
V_2 -> V_112 = V_60 ;
V_2 -> V_93 &= ~ V_117 ;
} else if ( V_2 -> V_93 & V_118 ) {
V_2 -> V_112 = V_76 ;
V_2 -> V_93 &= ~ V_118 ;
} else if ( V_2 -> V_93 & V_119 ) {
V_2 -> V_112 = V_110 ;
V_2 -> V_93 &= ~ V_119 ;
} else {
V_2 -> V_112 = V_87 ;
}
V_120:
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_20 ,
F_56 ( V_2 -> V_112 ) ) ;
V_111 = V_2 -> V_112 ;
switch ( V_2 -> V_112 ) {
case V_109 :
V_2 -> V_121 = 0 ;
break;
case V_60 :
V_2 -> V_112 = F_40 ( V_2 ) ;
V_2 -> V_121 ++ ;
break;
case V_76 :
V_2 -> V_121 = 0 ;
V_2 -> V_122 = 0 ;
V_2 -> V_112 = F_43 ( V_2 ) ;
break;
case V_110 :
V_2 -> V_122 = V_2 -> V_121 ? 0 : 1 ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_21 ,
V_2 -> V_121 ? L_22
: L_23 ) ;
break;
case V_92 :
break;
default:
V_2 -> V_112 = V_87 ;
}
if ( V_2 -> V_112 == V_92 ) {
V_2 -> V_93 = 0 ;
F_6 ( V_2 ) ;
} else if ( V_2 -> V_112 == V_87 ) {
F_58 ( V_2 -> V_44 ,
L_18 ,
V_111 ) ;
V_2 -> V_93 = 0 ;
F_6 ( V_2 ) ;
}
if ( V_2 -> V_112 >= V_110 ) {
V_2 -> V_115 = V_2 -> V_112 ;
V_2 -> V_112 = V_109 ;
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = V_85 ;
V_2 -> V_81 = 0 ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_24 ,
F_56 ( V_2 -> V_115 ) ) ;
}
if ( V_111 != V_2 -> V_112 )
goto V_120;
if ( V_2 -> V_93 )
goto V_116;
F_8 ( V_2 ) ;
}
static void F_60 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_54 ( V_107 ,
struct V_1 ,
V_108 ) ;
F_61 ( & V_2 -> V_123 ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
case V_17 :
F_59 ( V_2 ) ;
break;
case V_18 :
case V_19 :
F_57 ( V_2 ) ;
break;
default:
break;
}
if ( V_2 -> V_97 -> V_98 )
F_47 ( V_2 , V_99 , 1 << 3 ) ;
F_62 ( & V_2 -> V_123 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
unsigned int V_3 ;
V_2 -> V_26 . V_27 . V_124 ( V_2 , & V_89 ) ;
V_3 = F_2 ( V_2 , V_4 , V_125 ) ;
if ( F_44 ( & V_89 , V_126 ) )
V_3 |= 0x100 ;
else
V_3 &= ~ 0x100 ;
if ( F_44 ( & V_89 , V_127 ) )
V_3 |= 0x80 ;
else
V_3 &= ~ 0x80 ;
V_3 |= V_128 ;
V_3 &= ~ V_129 ;
F_3 ( V_2 , V_4 , V_125 , V_3 ) ;
V_3 = F_2 ( V_2 , V_4 , V_7 ) ;
V_3 &= ~ V_130 ;
V_3 &= ~ V_131 ;
switch ( V_2 -> V_15 ) {
case V_18 :
V_3 |= V_132 ;
break;
case V_19 :
V_3 |= V_133 ;
break;
default:
break;
}
V_3 |= V_134 ;
F_3 ( V_2 , V_4 , V_7 , V_3 ) ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_25 ,
( V_2 -> V_15 == V_18 ) ? L_26 : L_27 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
unsigned int V_3 ;
V_2 -> V_26 . V_27 . V_124 ( V_2 , & V_89 ) ;
V_3 = F_2 ( V_2 , V_11 , V_61 + 2 ) ;
if ( F_44 ( & V_89 , 10000baseR_FEC ) )
V_3 |= 0xc000 ;
else
V_3 &= ~ 0xc000 ;
F_3 ( V_2 , V_11 , V_61 + 2 , V_3 ) ;
V_3 = F_2 ( V_2 , V_11 , V_61 + 1 ) ;
if ( F_44 ( & V_89 , 10000baseKR_Full ) )
V_3 |= 0x80 ;
else
V_3 &= ~ 0x80 ;
if ( F_44 ( & V_89 , 1000baseKX_Full ) ||
F_44 ( & V_89 , 2500baseX_Full ) )
V_3 |= 0x20 ;
else
V_3 &= ~ 0x20 ;
F_3 ( V_2 , V_11 , V_61 + 1 , V_3 ) ;
V_3 = F_2 ( V_2 , V_11 , V_61 ) ;
if ( F_44 ( & V_89 , V_126 ) )
V_3 |= 0x400 ;
else
V_3 &= ~ 0x400 ;
if ( F_44 ( & V_89 , V_127 ) )
V_3 |= 0x800 ;
else
V_3 &= ~ 0x800 ;
V_3 &= ~ V_77 ;
F_3 ( V_2 , V_11 , V_61 , V_3 ) ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_28 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
V_2 -> V_15 = V_2 -> V_26 . V_27 . V_15 ( V_2 ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
case V_17 :
F_64 ( V_2 ) ;
break;
case V_18 :
case V_19 :
F_63 ( V_2 ) ;
break;
default:
break;
}
}
static const char * F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_135 && V_2 -> V_136 )
return L_29 ;
else if ( V_2 -> V_136 )
return L_30 ;
else if ( V_2 -> V_135 )
return L_31 ;
else
return L_32 ;
}
static const char * F_67 ( int V_137 )
{
switch ( V_137 ) {
case V_138 :
return L_33 ;
case V_32 :
return L_34 ;
case V_30 :
return L_35 ;
case V_25 :
return L_36 ;
case V_139 :
return L_37 ;
default:
return L_38 ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_90 . V_43 )
F_69 ( V_2 -> V_44 ,
L_39 ,
F_67 ( V_2 -> V_90 . V_137 ) ,
V_2 -> V_90 . V_140 == V_141 ? L_40 : L_41 ,
F_66 ( V_2 ) ) ;
else
F_69 ( V_2 -> V_44 , L_42 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
int V_142 = 0 ;
if ( V_2 -> V_90 . V_43 ) {
V_2 -> V_143 = V_2 -> V_90 . V_143 ;
if ( V_2 -> V_135 != V_2 -> V_90 . V_135 ) {
V_142 = 1 ;
V_2 -> V_23 . V_144 ( V_2 ) ;
V_2 -> V_135 = V_2 -> V_90 . V_135 ;
}
if ( V_2 -> V_136 != V_2 -> V_90 . V_136 ) {
V_142 = 1 ;
V_2 -> V_23 . V_145 ( V_2 ) ;
V_2 -> V_136 = V_2 -> V_90 . V_136 ;
}
if ( V_2 -> V_146 != V_2 -> V_90 . V_137 ) {
V_142 = 1 ;
V_2 -> V_146 = V_2 -> V_90 . V_137 ;
}
if ( V_2 -> V_147 != V_2 -> V_90 . V_43 ) {
V_142 = 1 ;
V_2 -> V_147 = V_2 -> V_90 . V_43 ;
}
} else if ( V_2 -> V_147 ) {
V_142 = 1 ;
V_2 -> V_147 = 0 ;
V_2 -> V_146 = V_139 ;
}
if ( V_142 && F_71 ( V_2 ) )
F_68 ( V_2 ) ;
}
static bool F_72 ( struct V_1 * V_2 , int V_137 )
{
return V_2 -> V_26 . V_27 . V_148 ( V_2 , V_137 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
enum V_39 V_41 ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_43 ) ;
F_34 ( V_2 ) ;
V_41 = V_2 -> V_26 . V_27 . V_149 ( V_2 , V_2 -> V_90 . V_137 ) ;
switch ( V_41 ) {
case V_33 :
case V_31 :
case V_29 :
case V_38 :
case V_37 :
case V_36 :
case V_35 :
break;
case V_42 :
default:
return - V_150 ;
}
if ( V_2 -> V_90 . V_140 != V_141 )
return - V_150 ;
F_25 ( V_2 , V_41 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_80 ;
F_75 ( V_151 , & V_2 -> V_152 ) ;
V_2 -> V_153 = V_82 ;
V_80 = V_2 -> V_26 . V_27 . V_154 ( V_2 ) ;
if ( V_80 )
return V_80 ;
if ( V_2 -> V_90 . V_155 != V_156 ) {
V_80 = F_73 ( V_2 ) ;
if ( V_80 || ! V_2 -> V_34 )
return V_80 ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_44 ) ;
} else {
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_45 ) ;
}
F_76 ( V_2 -> V_157 ) ;
if ( F_26 ( V_2 , V_29 ) ) {
F_25 ( V_2 , V_29 ) ;
} else if ( F_26 ( V_2 , V_31 ) ) {
F_25 ( V_2 , V_31 ) ;
} else if ( F_26 ( V_2 , V_33 ) ) {
F_25 ( V_2 , V_33 ) ;
} else if ( F_26 ( V_2 , V_35 ) ) {
F_25 ( V_2 , V_35 ) ;
} else if ( F_26 ( V_2 , V_36 ) ) {
F_25 ( V_2 , V_36 ) ;
} else if ( F_26 ( V_2 , V_37 ) ) {
F_25 ( V_2 , V_37 ) ;
} else if ( F_26 ( V_2 , V_38 ) ) {
F_25 ( V_2 , V_38 ) ;
} else {
F_77 ( V_2 -> V_157 ) ;
return - V_150 ;
}
F_35 ( V_2 ) ;
F_10 ( V_2 ) ;
V_2 -> V_115 = V_109 ;
V_2 -> V_112 = V_109 ;
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = V_85 ;
F_77 ( V_2 -> V_157 ) ;
F_65 ( V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_80 ;
F_61 ( & V_2 -> V_123 ) ;
V_80 = F_74 ( V_2 ) ;
if ( V_80 )
F_75 ( V_158 , & V_2 -> V_152 ) ;
else
F_79 ( V_158 , & V_2 -> V_152 ) ;
F_62 ( & V_2 -> V_123 ) ;
return V_80 ;
}
static bool F_80 ( struct V_1 * V_2 )
{
return ( V_2 -> V_115 == V_110 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
unsigned long V_159 ;
V_159 = V_2 -> V_153 + ( V_160 * V_161 ) ;
if ( F_42 ( V_82 , V_159 ) ) {
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_46 ) ;
F_78 ( V_2 ) ;
}
}
static enum V_39 F_82 ( struct V_1 * V_2 )
{
return V_2 -> V_26 . V_27 . V_162 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = & V_2 -> V_90 . V_89 ;
enum V_39 V_41 ;
F_84 ( V_89 ) ;
if ( ( V_2 -> V_90 . V_155 != V_156 ) || V_2 -> V_122 )
V_41 = F_20 ( V_2 ) ;
else
V_41 = F_82 ( V_2 ) ;
switch ( V_41 ) {
case V_38 :
V_2 -> V_90 . V_137 = V_138 ;
break;
case V_36 :
case V_33 :
case V_37 :
V_2 -> V_90 . V_137 = V_32 ;
break;
case V_31 :
V_2 -> V_90 . V_137 = V_30 ;
break;
case V_29 :
case V_35 :
V_2 -> V_90 . V_137 = V_25 ;
break;
case V_42 :
default:
V_2 -> V_90 . V_137 = V_139 ;
}
V_2 -> V_90 . V_140 = V_141 ;
F_25 ( V_2 , V_41 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned int V_163 ;
int V_164 ;
if ( F_86 ( V_158 , & V_2 -> V_152 ) ) {
F_87 ( V_2 -> V_44 ) ;
V_2 -> V_90 . V_43 = 0 ;
goto V_165;
}
V_163 = ( V_2 -> V_90 . V_155 == V_156 ) ;
V_2 -> V_90 . V_43 = V_2 -> V_26 . V_27 . V_166 ( V_2 ,
& V_164 ) ;
if ( V_164 ) {
F_78 ( V_2 ) ;
return;
}
if ( V_2 -> V_90 . V_43 ) {
if ( V_163 && ! F_80 ( V_2 ) ) {
F_81 ( V_2 ) ;
return;
}
F_83 ( V_2 ) ;
if ( F_86 ( V_151 , & V_2 -> V_152 ) )
F_79 ( V_151 , & V_2 -> V_152 ) ;
F_88 ( V_2 -> V_44 ) ;
} else {
if ( F_86 ( V_151 , & V_2 -> V_152 ) ) {
F_81 ( V_2 ) ;
if ( V_163 )
return;
}
F_83 ( V_2 ) ;
F_87 ( V_2 -> V_44 ) ;
}
V_165:
F_70 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_47 ) ;
if ( ! V_2 -> V_167 )
return;
V_2 -> V_167 = 0 ;
F_35 ( V_2 ) ;
if ( V_2 -> V_168 != V_2 -> V_157 )
F_90 ( V_2 -> V_169 , V_2 -> V_157 , V_2 ) ;
V_2 -> V_26 . V_27 . V_170 ( V_2 ) ;
V_2 -> V_90 . V_43 = 0 ;
F_87 ( V_2 -> V_44 ) ;
F_70 ( V_2 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_171 * V_44 = V_2 -> V_44 ;
int V_80 ;
F_23 ( V_2 , V_43 , V_2 -> V_44 , L_48 ) ;
V_80 = V_2 -> V_26 . V_27 . V_172 ( V_2 ) ;
if ( V_80 )
return V_80 ;
if ( V_2 -> V_168 != V_2 -> V_157 ) {
F_92 ( & V_2 -> V_104 , F_49 ,
( unsigned long ) V_2 ) ;
V_80 = F_93 ( V_2 -> V_169 , V_2 -> V_157 ,
F_50 , 0 , V_2 -> V_173 ,
V_2 ) ;
if ( V_80 ) {
F_58 ( V_44 , L_49 ) ;
goto V_174;
}
}
if ( F_26 ( V_2 , V_29 ) ) {
F_13 ( V_2 ) ;
} else if ( F_26 ( V_2 , V_31 ) ) {
F_14 ( V_2 ) ;
} else if ( F_26 ( V_2 , V_33 ) ) {
F_15 ( V_2 ) ;
} else if ( F_26 ( V_2 , V_35 ) ) {
F_16 ( V_2 ) ;
} else if ( F_26 ( V_2 , V_36 ) ) {
F_17 ( V_2 ) ;
} else if ( F_26 ( V_2 , V_37 ) ) {
F_18 ( V_2 ) ;
} else if ( F_26 ( V_2 , V_38 ) ) {
F_19 ( V_2 ) ;
} else {
V_80 = - V_150 ;
goto V_175;
}
V_2 -> V_167 = 1 ;
F_65 ( V_2 ) ;
F_9 ( V_2 ) ;
return F_78 ( V_2 ) ;
V_175:
if ( V_2 -> V_168 != V_2 -> V_157 )
F_90 ( V_2 -> V_169 , V_2 -> V_157 , V_2 ) ;
V_174:
V_2 -> V_26 . V_27 . V_170 ( V_2 ) ;
return V_80 ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_80 ;
V_80 = V_2 -> V_26 . V_27 . V_176 ( V_2 ) ;
if ( V_80 )
return V_80 ;
F_35 ( V_2 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_177 * V_169 = V_2 -> V_169 ;
F_96 ( V_169 , L_50 ) ;
F_96 ( V_169 , L_51 , V_49 ,
F_2 ( V_2 , V_8 , V_49 ) ) ;
F_96 ( V_169 , L_52 , V_178 ,
F_2 ( V_2 , V_8 , V_178 ) ) ;
F_96 ( V_169 , L_53 , V_179 ,
F_2 ( V_2 , V_8 , V_179 ) ) ;
F_96 ( V_169 , L_54 , V_180 ,
F_2 ( V_2 , V_8 , V_180 ) ) ;
F_96 ( V_169 , L_55 , V_181 ,
F_2 ( V_2 , V_8 , V_181 ) ) ;
F_96 ( V_169 , L_55 , V_182 ,
F_2 ( V_2 , V_8 , V_182 ) ) ;
F_96 ( V_169 , L_56 , V_49 ,
F_2 ( V_2 , V_11 , V_49 ) ) ;
F_96 ( V_169 , L_57 , V_178 ,
F_2 ( V_2 , V_11 , V_178 ) ) ;
F_96 ( V_169 , L_58 ,
V_61 ,
F_2 ( V_2 , V_11 , V_61 ) ) ;
F_96 ( V_169 , L_59 ,
V_61 + 1 ,
F_2 ( V_2 , V_11 , V_61 + 1 ) ) ;
F_96 ( V_169 , L_60 ,
V_61 + 2 ,
F_2 ( V_2 , V_11 , V_61 + 2 ) ) ;
F_96 ( V_169 , L_61 ,
V_183 ,
F_2 ( V_2 , V_11 , V_183 ) ) ;
F_96 ( V_169 , L_62 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = & V_2 -> V_90 . V_89 ;
if ( F_44 ( V_89 , 10000baseKR_Full ) )
return V_25 ;
else if ( F_44 ( V_89 , 10000baseT_Full ) )
return V_25 ;
else if ( F_44 ( V_89 , 2500baseX_Full ) )
return V_30 ;
else if ( F_44 ( V_89 , 2500baseT_Full ) )
return V_30 ;
else if ( F_44 ( V_89 , 1000baseKX_Full ) )
return V_32 ;
else if ( F_44 ( V_89 , 1000baseT_Full ) )
return V_32 ;
else if ( F_44 ( V_89 , 100baseT_Full ) )
return V_138 ;
return V_139 ;
}
static void F_98 ( struct V_1 * V_2 )
{
V_2 -> V_26 . V_27 . exit ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = & V_2 -> V_90 . V_89 ;
int V_80 ;
F_100 ( & V_2 -> V_123 ) ;
F_101 ( & V_2 -> V_96 , F_53 ) ;
F_101 ( & V_2 -> V_108 , F_60 ) ;
V_2 -> V_184 = V_8 ;
V_2 -> V_66 = F_2 ( V_2 , V_20 ,
V_185 ) ;
V_2 -> V_66 &= ( V_64 |
V_65 ) ;
V_80 = V_2 -> V_26 . V_27 . V_186 ( V_2 ) ;
if ( V_80 )
return V_80 ;
F_102 ( V_89 , V_187 , V_89 , V_188 ) ;
V_2 -> V_90 . V_189 = 0 ;
if ( F_44 ( V_89 , V_190 ) ) {
V_2 -> V_90 . V_155 = V_156 ;
V_2 -> V_90 . V_137 = V_139 ;
V_2 -> V_90 . V_140 = V_191 ;
} else {
V_2 -> V_90 . V_155 = V_192 ;
V_2 -> V_90 . V_137 = F_97 ( V_2 ) ;
V_2 -> V_90 . V_140 = V_141 ;
}
V_2 -> V_90 . V_43 = 0 ;
V_2 -> V_90 . V_143 = V_2 -> V_143 ;
V_2 -> V_90 . V_135 = V_2 -> V_135 ;
V_2 -> V_90 . V_136 = V_2 -> V_136 ;
F_103 ( V_89 , V_126 ) ;
F_103 ( V_89 , V_127 ) ;
if ( V_2 -> V_136 ) {
F_104 ( V_89 , V_126 ) ;
F_104 ( V_89 , V_127 ) ;
}
if ( V_2 -> V_135 ) {
if ( F_44 ( V_89 , V_127 ) )
F_103 ( V_89 , V_127 ) ;
else
F_104 ( V_89 , V_127 ) ;
}
if ( F_105 ( V_2 ) )
F_95 ( V_2 ) ;
return 0 ;
}
void F_106 ( struct V_193 * V_26 )
{
V_26 -> V_194 = F_99 ;
V_26 -> V_195 = F_98 ;
V_26 -> V_196 = F_94 ;
V_26 -> V_197 = F_91 ;
V_26 -> V_198 = F_89 ;
V_26 -> V_199 = F_85 ;
V_26 -> V_200 = F_78 ;
V_26 -> V_201 = F_72 ;
V_26 -> V_202 = F_52 ;
}
