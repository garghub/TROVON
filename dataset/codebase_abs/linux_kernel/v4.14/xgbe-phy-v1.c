static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , V_4 , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , V_4 , 0 ) ;
}
static enum V_5 F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_7 ;
struct V_9 * V_10 = V_2 -> V_10 ;
enum V_5 V_11 ;
unsigned int V_12 , V_13 ;
F_5 ( V_7 , V_14 ) ;
F_5 ( V_7 , V_15 ) ;
V_12 = F_6 ( V_2 , V_16 , V_17 ) ;
V_13 = F_6 ( V_2 , V_16 , V_18 ) ;
if ( V_13 & 0x400 )
F_5 ( V_7 , V_19 ) ;
if ( V_13 & 0x800 )
F_5 ( V_7 , V_20 ) ;
if ( V_2 -> V_8 . V_21 ) {
V_2 -> V_8 . V_22 = 0 ;
V_2 -> V_8 . V_23 = 0 ;
if ( V_12 & V_13 & 0x400 ) {
V_2 -> V_8 . V_22 = 1 ;
V_2 -> V_8 . V_23 = 1 ;
} else if ( V_12 & V_13 & 0x800 ) {
if ( V_12 & 0x400 )
V_2 -> V_8 . V_23 = 1 ;
else if ( V_13 & 0x400 )
V_2 -> V_8 . V_22 = 1 ;
}
}
V_12 = F_6 ( V_2 , V_16 , V_17 + 1 ) ;
V_13 = F_6 ( V_2 , V_16 , V_18 + 1 ) ;
if ( V_13 & 0x80 )
F_5 ( V_7 , 10000baseKR_Full ) ;
if ( V_13 & 0x20 ) {
if ( V_10 -> V_24 == V_25 )
F_5 ( V_7 , 2500baseX_Full ) ;
else
F_5 ( V_7 , 1000baseKX_Full ) ;
}
V_12 &= V_13 ;
if ( V_12 & 0x80 ) {
V_11 = V_26 ;
} else if ( V_12 & 0x20 ) {
if ( V_10 -> V_24 == V_25 )
V_11 = V_27 ;
else
V_11 = V_28 ;
} else {
V_11 = V_29 ;
}
V_12 = F_6 ( V_2 , V_16 , V_17 + 2 ) ;
V_13 = F_6 ( V_2 , V_16 , V_18 + 2 ) ;
if ( V_13 & 0xc000 )
F_5 ( V_7 , 10000baseR_FEC ) ;
return V_11 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_6 * V_30 )
{
struct V_6 * V_31 = & V_2 -> V_8 . V_7 ;
F_8 ( V_30 , V_32 , V_31 , V_32 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static enum V_33 F_10 ( struct V_1 * V_2 )
{
return V_34 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_35 ;
V_35 = F_6 ( V_2 , V_36 , V_37 ) ;
V_35 |= V_38 ;
F_12 ( V_2 , V_36 , V_37 , V_35 ) ;
F_13 ( 75 , 100 ) ;
V_35 &= ~ V_38 ;
F_12 ( V_2 , V_36 , V_37 , V_35 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_39 , V_40 , 1 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
unsigned int V_41 ;
T_1 V_42 ;
F_15 ( V_2 , V_39 , V_40 , 0 ) ;
V_41 = V_43 ;
while ( V_41 -- ) {
F_13 ( 50 , 75 ) ;
V_42 = F_17 ( V_2 , V_44 ) ;
if ( F_18 ( V_42 , V_44 , V_45 ) &&
F_18 ( V_42 , V_44 , V_46 ) )
goto V_47;
}
F_19 ( V_2 , V_48 , V_2 -> V_49 , L_1 ,
V_42 ) ;
V_47:
F_20 ( V_2 , V_50 , V_51 , 0 ) ;
F_20 ( V_2 , V_50 , V_51 , 1 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int V_35 ;
V_35 = F_6 ( V_2 , V_36 , V_52 ) ;
V_35 &= ~ V_53 ;
V_35 |= V_54 ;
F_12 ( V_2 , V_36 , V_52 , V_35 ) ;
V_35 = F_6 ( V_2 , V_36 , V_37 ) ;
V_35 &= ~ V_55 ;
V_35 |= V_56 ;
F_12 ( V_2 , V_36 , V_37 , V_35 ) ;
F_11 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 , V_39 , V_57 , V_58 ) ;
F_15 ( V_2 , V_39 , V_59 , V_60 ) ;
F_15 ( V_2 , V_39 , V_61 , V_62 ) ;
F_15 ( V_2 , V_39 , V_63 ,
V_10 -> V_64 [ V_65 ] ) ;
F_15 ( V_2 , V_39 , V_66 ,
V_10 -> V_67 [ V_65 ] ) ;
F_20 ( V_2 , V_68 , V_69 ,
V_10 -> V_70 [ V_65 ] ) ;
F_20 ( V_2 , V_71 , V_72 ,
V_10 -> V_73 [ V_65 ] ) ;
F_20 ( V_2 , V_74 , V_75 ,
V_10 -> V_76 [ V_65 ] ) ;
F_22 ( V_2 , V_77 ,
V_10 -> V_78 [ V_65 ] ) ;
F_16 ( V_2 ) ;
F_19 ( V_2 , V_48 , V_2 -> V_49 , L_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int V_35 ;
V_35 = F_6 ( V_2 , V_36 , V_52 ) ;
V_35 &= ~ V_53 ;
V_35 |= V_79 ;
F_12 ( V_2 , V_36 , V_52 , V_35 ) ;
V_35 = F_6 ( V_2 , V_36 , V_37 ) ;
V_35 &= ~ V_55 ;
V_35 |= V_80 ;
F_12 ( V_2 , V_36 , V_37 , V_35 ) ;
F_11 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 , V_39 , V_57 , V_81 ) ;
F_15 ( V_2 , V_39 , V_59 , V_82 ) ;
F_15 ( V_2 , V_39 , V_61 , V_83 ) ;
F_15 ( V_2 , V_39 , V_63 ,
V_10 -> V_64 [ V_84 ] ) ;
F_15 ( V_2 , V_39 , V_66 ,
V_10 -> V_67 [ V_84 ] ) ;
F_20 ( V_2 , V_68 , V_69 ,
V_10 -> V_70 [ V_84 ] ) ;
F_20 ( V_2 , V_71 , V_72 ,
V_10 -> V_73 [ V_84 ] ) ;
F_20 ( V_2 , V_74 , V_75 ,
V_10 -> V_76 [ V_84 ] ) ;
F_22 ( V_2 , V_77 ,
V_10 -> V_78 [ V_84 ] ) ;
F_16 ( V_2 ) ;
F_19 ( V_2 , V_48 , V_2 -> V_49 , L_3 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int V_35 ;
V_35 = F_6 ( V_2 , V_36 , V_52 ) ;
V_35 &= ~ V_53 ;
V_35 |= V_79 ;
F_12 ( V_2 , V_36 , V_52 , V_35 ) ;
V_35 = F_6 ( V_2 , V_36 , V_37 ) ;
V_35 &= ~ V_55 ;
V_35 |= V_80 ;
F_12 ( V_2 , V_36 , V_37 , V_35 ) ;
F_11 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 , V_39 , V_57 , V_85 ) ;
F_15 ( V_2 , V_39 , V_59 , V_86 ) ;
F_15 ( V_2 , V_39 , V_61 , V_87 ) ;
F_15 ( V_2 , V_39 , V_63 ,
V_10 -> V_64 [ V_88 ] ) ;
F_15 ( V_2 , V_39 , V_66 ,
V_10 -> V_67 [ V_88 ] ) ;
F_20 ( V_2 , V_68 , V_69 ,
V_10 -> V_70 [ V_88 ] ) ;
F_20 ( V_2 , V_71 , V_72 ,
V_10 -> V_73 [ V_88 ] ) ;
F_20 ( V_2 , V_74 , V_75 ,
V_10 -> V_76 [ V_88 ] ) ;
F_22 ( V_2 , V_77 ,
V_10 -> V_78 [ V_88 ] ) ;
F_16 ( V_2 ) ;
F_19 ( V_2 , V_48 , V_2 -> V_49 , L_4 ) ;
}
static enum V_5 F_25 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
enum V_5 V_11 ;
unsigned int V_35 ;
V_35 = F_6 ( V_2 , V_36 , V_52 ) ;
V_35 &= V_53 ;
if ( V_35 == V_54 ) {
V_11 = V_26 ;
} else {
if ( V_10 -> V_24 == V_25 )
V_11 = V_27 ;
else
V_11 = V_28 ;
}
return V_11 ;
}
static enum V_5 F_26 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
enum V_5 V_11 ;
if ( F_25 ( V_2 ) == V_26 ) {
if ( V_10 -> V_24 == V_25 )
V_11 = V_27 ;
else
V_11 = V_28 ;
} else {
V_11 = V_26 ;
}
return V_11 ;
}
static enum V_5 F_27 ( struct V_1 * V_2 ,
int V_89 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
switch ( V_89 ) {
case V_90 :
return ( V_10 -> V_24 == V_91 )
? V_28 : V_29 ;
case V_92 :
return ( V_10 -> V_24 == V_25 )
? V_27 : V_29 ;
case V_93 :
return V_26 ;
default:
return V_29 ;
}
}
static void F_28 ( struct V_1 * V_2 , enum V_5 V_11 )
{
switch ( V_11 ) {
case V_28 :
F_24 ( V_2 ) ;
break;
case V_27 :
F_23 ( V_2 ) ;
break;
case V_26 :
F_21 ( V_2 ) ;
break;
default:
break;
}
}
static bool F_29 ( struct V_1 * V_2 ,
enum V_5 V_11 , bool V_94 )
{
if ( V_2 -> V_8 . V_95 == V_96 ) {
return V_94 ;
} else {
enum V_5 V_97 ;
V_97 = F_27 ( V_2 , V_2 -> V_8 . V_89 ) ;
if ( V_97 == V_11 )
return true ;
}
return false ;
}
static bool F_30 ( struct V_1 * V_2 , enum V_5 V_11 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_7 ;
switch ( V_11 ) {
case V_28 :
return F_29 ( V_2 , V_11 ,
F_31 ( V_7 , 1000baseKX_Full ) ) ;
case V_27 :
return F_29 ( V_2 , V_11 ,
F_31 ( V_7 , 2500baseX_Full ) ) ;
case V_26 :
return F_29 ( V_2 , V_11 ,
F_31 ( V_7 , 10000baseKR_Full ) ) ;
default:
return false ;
}
}
static bool F_32 ( struct V_1 * V_2 , int V_89 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
switch ( V_89 ) {
case V_90 :
if ( V_10 -> V_24 != V_91 )
return false ;
return true ;
case V_92 :
if ( V_10 -> V_24 != V_25 )
return false ;
return true ;
case V_93 :
return true ;
default:
return false ;
}
}
static int F_33 ( struct V_1 * V_2 , int * V_98 )
{
unsigned int V_35 ;
* V_98 = 0 ;
V_35 = F_6 ( V_2 , V_36 , V_99 ) ;
V_35 = F_6 ( V_2 , V_36 , V_99 ) ;
return ( V_35 & V_100 ) ? 1 : 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
}
static int F_35 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
unsigned int V_35 , V_101 ;
V_35 = F_6 ( V_2 , V_36 , V_37 ) ;
V_35 |= V_102 ;
F_12 ( V_2 , V_36 , V_37 , V_35 ) ;
V_101 = 50 ;
do {
F_37 ( 20 ) ;
V_35 = F_6 ( V_2 , V_36 , V_37 ) ;
} while ( ( V_35 & V_102 ) && -- V_101 );
if ( V_35 & V_102 )
return - V_103 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_7 ;
struct V_9 * V_10 ;
int V_104 ;
V_10 = F_40 ( V_2 -> V_105 , sizeof( * V_10 ) , V_106 ) ;
if ( ! V_10 )
return - V_107 ;
V_104 = F_41 ( V_2 -> V_108 , V_109 ,
& V_10 -> V_24 ) ;
if ( V_104 ) {
F_42 ( V_2 -> V_105 , L_5 ,
V_109 ) ;
return V_104 ;
}
switch ( V_10 -> V_24 ) {
case V_91 :
case V_25 :
break;
default:
F_42 ( V_2 -> V_105 , L_5 ,
V_109 ) ;
return - V_110 ;
}
if ( F_43 ( V_2 -> V_108 , V_111 ) ) {
V_104 = F_44 ( V_2 -> V_108 ,
V_111 ,
V_10 -> V_70 ,
V_112 ) ;
if ( V_104 ) {
F_42 ( V_2 -> V_105 , L_5 ,
V_111 ) ;
return V_104 ;
}
} else {
memcpy ( V_10 -> V_70 , V_113 ,
sizeof( V_10 -> V_70 ) ) ;
}
if ( F_43 ( V_2 -> V_108 , V_114 ) ) {
V_104 = F_44 ( V_2 -> V_108 ,
V_114 ,
V_10 -> V_64 ,
V_112 ) ;
if ( V_104 ) {
F_42 ( V_2 -> V_105 , L_5 ,
V_114 ) ;
return V_104 ;
}
} else {
memcpy ( V_10 -> V_64 , V_115 ,
sizeof( V_10 -> V_64 ) ) ;
}
if ( F_43 ( V_2 -> V_108 , V_116 ) ) {
V_104 = F_44 ( V_2 -> V_108 ,
V_116 ,
V_10 -> V_73 ,
V_112 ) ;
if ( V_104 ) {
F_42 ( V_2 -> V_105 , L_5 ,
V_116 ) ;
return V_104 ;
}
} else {
memcpy ( V_10 -> V_73 , V_117 ,
sizeof( V_10 -> V_73 ) ) ;
}
if ( F_43 ( V_2 -> V_108 , V_118 ) ) {
V_104 = F_44 ( V_2 -> V_108 ,
V_118 ,
V_10 -> V_67 ,
V_112 ) ;
if ( V_104 ) {
F_42 ( V_2 -> V_105 , L_5 ,
V_118 ) ;
return V_104 ;
}
} else {
memcpy ( V_10 -> V_67 , V_119 ,
sizeof( V_10 -> V_67 ) ) ;
}
if ( F_43 ( V_2 -> V_108 , V_120 ) ) {
V_104 = F_44 ( V_2 -> V_108 ,
V_120 ,
V_10 -> V_76 ,
V_112 ) ;
if ( V_104 ) {
F_42 ( V_2 -> V_105 , L_5 ,
V_120 ) ;
return V_104 ;
}
} else {
memcpy ( V_10 -> V_76 , V_121 ,
sizeof( V_10 -> V_76 ) ) ;
}
if ( F_43 ( V_2 -> V_108 , V_122 ) ) {
V_104 = F_44 ( V_2 -> V_108 ,
V_122 ,
V_10 -> V_78 ,
V_112 ) ;
if ( V_104 ) {
F_42 ( V_2 -> V_105 , L_5 ,
V_122 ) ;
return V_104 ;
}
} else {
memcpy ( V_10 -> V_78 , V_123 ,
sizeof( V_10 -> V_78 ) ) ;
}
F_45 ( V_7 ) ;
F_46 ( V_7 , V_14 ) ;
F_46 ( V_7 , V_19 ) ;
F_46 ( V_7 , V_20 ) ;
F_46 ( V_7 , V_15 ) ;
F_46 ( V_7 , 10000baseKR_Full ) ;
switch ( V_10 -> V_24 ) {
case V_91 :
F_46 ( V_7 , 1000baseKX_Full ) ;
break;
case V_25 :
F_46 ( V_7 , 2500baseX_Full ) ;
break;
}
if ( V_2 -> V_124 & V_125 )
F_46 ( V_7 , 10000baseR_FEC ) ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
void F_47 ( struct V_126 * V_127 )
{
struct V_128 * V_129 = & V_127 -> V_129 ;
V_129 -> V_130 = F_39 ;
V_129 -> exit = F_38 ;
V_129 -> V_131 = F_36 ;
V_129 -> V_132 = F_35 ;
V_129 -> V_133 = F_34 ;
V_129 -> V_134 = F_33 ;
V_129 -> V_135 = F_32 ;
V_129 -> V_136 = F_30 ;
V_129 -> V_137 = F_28 ;
V_129 -> V_138 = F_27 ;
V_129 -> V_139 = F_26 ;
V_129 -> V_97 = F_25 ;
V_129 -> V_140 = F_10 ;
V_129 -> V_141 = F_9 ;
V_129 -> V_142 = F_7 ;
V_129 -> V_143 = F_4 ;
V_129 -> V_144 = F_1 ;
V_129 -> V_145 = F_3 ;
}
