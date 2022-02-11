static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 , const T_1 V_5 )
{
return F_5 ( V_3 , V_5 ) ;
}
static int F_6 ( struct V_2 * V_3 , const T_1 V_5 ,
const T_2 V_6 )
{
return F_7 ( V_3 , V_5 , V_6 ) ;
}
static int F_8 ( struct V_2 * V_3 , const T_1 V_5 ,
const T_2 V_6 )
{
int V_7 ;
V_7 = F_4 ( V_3 , V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_6 ( V_3 , V_5 , V_7 | V_6 ) ;
}
static int F_9 ( struct V_2 * V_3 , const T_1 V_5 ,
const T_2 V_6 )
{
int V_7 ;
V_7 = F_4 ( V_3 , V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_6 ( V_3 , V_5 , V_7 & ~ V_6 ) ;
}
static int F_10 ( struct V_2 * V_3 , const T_3 V_6 )
{
int V_7 ;
V_7 = F_6 ( V_3 , V_8 , V_6 >> 16 ) ;
if ( V_7 >= 0 )
V_7 = F_6 ( V_3 , V_9 , V_6 & 0xffff ) ;
return V_7 ;
}
static int F_11 ( struct V_2 * V_3 , T_3 * V_6 )
{
int V_7 ;
V_7 = F_4 ( V_3 , V_8 ) ;
* V_6 = V_7 << 16 ;
if ( V_7 >= 0 )
V_7 = F_4 ( V_3 , V_9 ) ;
* V_6 |= V_7 & 0xffff ;
return V_7 < 0 ? V_7 : 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
int V_7 ;
V_7 = F_6 ( V_3 , V_10 , 1 ) ;
if ( V_7 >= 0 )
V_7 = F_6 ( V_3 , V_10 , 0 ) ;
if ( V_7 >= 0 )
V_7 = F_9 ( V_3 , V_11 , 2 ) ;
return V_7 >= 0 ? 0 : - V_12 ;
}
static int F_13 ( struct V_2 * V_3 )
{
F_9 ( V_3 , V_11 , 2 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 , int V_15 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
int V_7 ;
if ( V_15 )
V_7 = F_8 ( V_3 , V_11 , 2 ) ;
else
V_7 = F_9 ( V_3 , V_11 , 2 ) ;
if ( V_7 < 0 )
return - V_12 ;
return 0 ;
}
static T_2 F_16 ( T_4 * V_16 , T_4 V_17 , T_4 V_18 )
{
unsigned int V_19 ;
if ( * V_16 < V_17 + V_17 / 2 ) {
* V_16 = V_17 ;
return 1 ;
}
V_19 = F_17 ( V_18 , * V_16 + V_17 / 2 ) / V_17 ;
if ( V_19 > 8 )
V_19 = 8 ;
* V_16 = V_17 * V_19 ;
return V_19 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_2 V_22 , T_2 V_23 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_7 ;
T_2 V_24 , V_25 ;
const T_2 V_26 = V_27 ,
V_28 = V_29 ;
V_24 = F_17 ( V_22 , ( T_2 ) 3 ) ;
V_25 = F_17 ( V_23 , ( T_2 ) 3 ) ;
switch ( V_24 ) {
case 1 :
V_21 -> V_30 &= ~ 1 ;
break;
case 2 :
V_21 -> V_30 &= ~ 3 ;
break;
case 3 :
V_21 -> V_30 = V_21 -> V_30 > F_19 ( V_31 , 6 ) ?
( V_21 -> V_30 / 6 ) * 6 : F_19 ( V_31 , 6 ) ;
}
V_21 -> V_32 &= ~ 1 ;
F_20 ( & V_3 -> V_33 , L_1 ,
V_22 , V_23 , V_21 -> V_34 , V_21 -> V_35 , V_21 -> V_30 , V_21 -> V_32 ) ;
V_7 = F_8 ( V_3 , V_11 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_3 , V_36 , V_26 ) ;
if ( V_7 >= 0 )
V_7 = F_6 ( V_3 , V_37 , V_28 ) ;
if ( V_23 != V_1 -> V_23 || V_22 != V_1 -> V_22 ) {
if ( V_7 >= 0 )
V_7 = F_6 ( V_3 , V_38 ,
( ( V_24 - 1 ) << 4 ) | ( V_22 - 1 ) ) ;
if ( V_7 >= 0 )
V_7 = F_6 ( V_3 , V_39 ,
( ( V_25 - 1 ) << 4 ) | ( V_23 - 1 ) ) ;
}
F_20 ( & V_3 -> V_33 , L_2 ,
V_21 -> V_30 , V_21 -> V_32 ) ;
if ( V_7 >= 0 )
V_7 = F_6 ( V_3 , V_40 , V_21 -> V_30 ) ;
if ( V_7 >= 0 )
V_7 = F_6 ( V_3 , V_41 , V_21 -> V_32 ) ;
if ( V_7 >= 0 )
V_7 = F_6 ( V_3 , V_42 , V_21 -> V_34 - 1 ) ;
if ( V_7 >= 0 )
V_7 = F_6 ( V_3 , V_43 ,
V_21 -> V_35 + V_1 -> V_44 - 1 ) ;
if ( V_7 >= 0 && F_21 ( V_1 -> V_45 ) == V_46 ) {
V_1 -> V_47 = V_21 -> V_35 + V_1 -> V_44 + V_28 ;
V_7 = F_10 ( V_3 , V_1 -> V_47 ) ;
}
if ( V_7 >= 0 )
V_7 = F_9 ( V_3 , V_11 , 1 ) ;
if ( V_7 >= 0 ) {
V_1 -> V_21 = * V_21 ;
V_1 -> V_22 = V_22 ;
V_1 -> V_23 = V_23 ;
}
return V_7 < 0 ? V_7 : 0 ;
}
static int F_22 ( struct V_13 * V_14 , struct V_48 * V_49 )
{
struct V_20 V_21 = V_49 -> V_50 ;
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_21 . V_34 = F_23 ( V_21 . V_34 , 2 ) ;
V_21 . V_35 = F_23 ( V_21 . V_35 , 2 ) ;
F_24 ( & V_21 . V_30 , & V_21 . V_34 ,
V_31 , V_51 , V_52 ) ;
F_24 ( & V_21 . V_32 , & V_21 . V_35 ,
V_53 , V_54 , V_55 ) ;
return F_18 ( V_3 , & V_21 , V_1 -> V_22 , V_1 -> V_23 ) ;
}
static int F_25 ( struct V_13 * V_14 , struct V_48 * V_49 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_49 -> V_50 = V_1 -> V_21 ;
V_49 -> type = V_56 ;
return 0 ;
}
static int F_26 ( struct V_13 * V_14 , struct V_57 * V_49 )
{
V_49 -> V_58 . V_30 = V_31 ;
V_49 -> V_58 . V_32 = V_53 ;
V_49 -> V_58 . V_34 = V_52 ;
V_49 -> V_58 . V_35 = V_55 ;
V_49 -> V_59 = V_49 -> V_58 ;
V_49 -> type = V_56 ;
V_49 -> V_60 . V_61 = 1 ;
V_49 -> V_60 . V_62 = 1 ;
return 0 ;
}
static int F_27 ( struct V_13 * V_14 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_64 -> V_34 = V_1 -> V_21 . V_34 / V_1 -> V_22 ;
V_64 -> V_35 = V_1 -> V_21 . V_35 / V_1 -> V_23 ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
V_64 -> V_69 = V_70 ;
return 0 ;
}
static int F_28 ( struct V_13 * V_14 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_22 , V_23 ;
struct V_20 V_21 = V_1 -> V_21 ;
V_22 = F_16 ( & V_21 . V_34 , V_64 -> V_34 , V_52 ) ;
V_23 = F_16 ( & V_21 . V_35 , V_64 -> V_35 , V_55 ) ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
return F_18 ( V_3 , & V_21 , V_22 , V_23 ) ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_63 * V_64 )
{
F_30 (
& V_64 -> V_34 , V_51 , V_52 , 1 ,
& V_64 -> V_35 , V_54 , V_55 , 1 , 0 ) ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
return 0 ;
}
static int F_31 ( struct V_13 * V_14 ,
struct V_71 * V_72 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_72 -> V_73 . type != V_74 )
return - V_75 ;
if ( V_72 -> V_73 . V_76 != V_3 -> V_76 )
return - V_77 ;
V_72 -> V_78 = V_1 -> V_79 ;
V_72 -> V_80 = 0 ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 ,
struct V_81 * V_5 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
if ( V_5 -> V_73 . type != V_74 || V_5 -> V_5 > 0xff )
return - V_75 ;
if ( V_5 -> V_73 . V_76 != V_3 -> V_76 )
return - V_77 ;
V_5 -> V_82 = F_4 ( V_3 , V_5 -> V_5 ) ;
if ( V_5 -> V_82 > 0xffff )
return - V_12 ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 ,
struct V_81 * V_5 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
if ( V_5 -> V_73 . type != V_74 || V_5 -> V_5 > 0xff )
return - V_75 ;
if ( V_5 -> V_73 . V_76 != V_3 -> V_76 )
return - V_77 ;
if ( F_6 ( V_3 , V_5 -> V_5 , V_5 -> V_82 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_34 ( struct V_83 * V_84 )
{
struct V_1 * V_1 = F_2 ( V_84 -> V_85 ,
struct V_1 , V_86 ) ;
const T_3 V_87 = V_55 + V_29 ;
T_4 F_17 , V_18 ;
switch ( V_84 -> V_72 ) {
case V_88 :
F_17 = V_1 -> V_89 -> V_90 ;
V_18 = V_1 -> V_89 -> V_91 ;
V_1 -> V_89 -> V_82 =
( V_87 / 2 + ( V_1 -> V_47 - 1 ) * ( V_18 - F_17 ) )
/ V_87 + F_17 ;
break;
}
return 0 ;
}
static int F_35 ( struct V_83 * V_84 )
{
struct V_1 * V_1 = F_2 ( V_84 -> V_85 ,
struct V_1 , V_86 ) ;
struct V_13 * V_14 = & V_1 -> V_4 ;
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_83 * exp = V_1 -> V_89 ;
int V_6 ;
switch ( V_84 -> V_72 ) {
case V_92 :
if ( V_84 -> V_82 )
V_6 = F_8 ( V_3 , V_93 , 0x8000 ) ;
else
V_6 = F_9 ( V_3 , V_93 , 0x8000 ) ;
if ( V_6 < 0 )
return - V_12 ;
return 0 ;
case V_94 :
if ( V_84 -> V_82 )
V_6 = F_8 ( V_3 , V_93 , 0x4000 ) ;
else
V_6 = F_9 ( V_3 , V_93 , 0x4000 ) ;
if ( V_6 < 0 )
return - V_12 ;
return 0 ;
case V_95 :
if ( V_84 -> V_82 <= V_84 -> V_96 ) {
unsigned long V_97 = V_84 -> V_96 - V_84 -> V_90 ;
V_6 = ( ( V_84 -> V_82 - V_84 -> V_90 ) * 8 + V_97 / 2 ) / V_97 ;
F_20 ( & V_3 -> V_33 , L_3 , V_6 ) ;
V_6 = F_6 ( V_3 , V_98 , V_6 ) ;
if ( V_6 < 0 )
return - V_12 ;
} else {
unsigned long V_97 = V_84 -> V_91 - V_84 -> V_96 - 1 ;
unsigned long V_99 = ( ( V_84 -> V_82 - V_84 -> V_96 - 1 ) *
1015 + V_97 / 2 ) / V_97 + 9 ;
if ( V_99 <= 32 )
V_6 = V_99 ;
else if ( V_99 <= 64 )
V_6 = ( ( V_99 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_6 = ( ( ( V_99 - 64 + 7 ) * 32 ) & 0xff00 ) | 0x60 ;
F_20 ( & V_3 -> V_33 , L_4 ,
F_4 ( V_3 , V_98 ) , V_6 ) ;
V_6 = F_6 ( V_3 , V_98 , V_6 ) ;
if ( V_6 < 0 )
return - V_12 ;
}
return 0 ;
case V_88 :
if ( V_84 -> V_82 == V_100 ) {
unsigned int V_97 = exp -> V_91 - exp -> V_90 ;
unsigned int V_101 = ( ( exp -> V_82 - exp -> V_90 ) * 1048 +
V_97 / 2 ) / V_97 + 1 ;
T_3 V_102 ;
F_11 ( V_3 , & V_102 ) ;
F_20 ( & V_3 -> V_33 , L_5 ,
V_102 , V_101 ) ;
if ( F_10 ( V_3 , V_101 ) < 0 )
return - V_12 ;
} else {
const T_2 V_28 = V_29 ;
V_1 -> V_47 = V_1 -> V_21 . V_35 +
V_1 -> V_44 + V_28 ;
if ( F_10 ( V_3 , V_1 -> V_47 ) < 0 )
return - V_12 ;
}
return 0 ;
default:
return - V_75 ;
}
return 0 ;
}
static int F_36 ( struct V_103 * V_33 )
{
return 0 ;
}
static int F_37 ( struct V_103 * V_33 )
{
struct V_104 * V_105 = F_38 ( V_33 ) ;
struct V_13 * V_14 = F_39 ( V_105 ) ;
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_7 ;
T_2 V_24 , V_25 ;
V_24 = F_17 ( V_1 -> V_22 , ( T_2 ) 3 ) ;
V_25 = F_17 ( V_1 -> V_23 , ( T_2 ) 3 ) ;
V_7 = F_6 ( V_3 , V_38 ,
( ( V_24 - 1 ) << 4 ) | ( V_1 -> V_22 - 1 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_3 , V_39 ,
( ( V_25 - 1 ) << 4 ) | ( V_1 -> V_23 - 1 ) ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_40 ( struct V_13 * V_14 , int V_106 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_104 * V_105 = F_41 ( V_3 ) ;
if ( V_106 )
V_105 -> V_33 . type = & V_107 ;
else
V_105 -> V_33 . type = NULL ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_4 V_6 ;
int V_7 ;
V_6 = F_6 ( V_3 , V_108 , 1 ) ;
F_20 ( & V_3 -> V_33 , L_6 , V_6 ) ;
V_6 = F_4 ( V_3 , V_109 ) ;
switch ( V_6 ) {
case 0x1621 :
V_1 -> V_79 = V_110 ;
break;
default:
F_43 ( & V_3 -> V_33 ,
L_7 , V_6 ) ;
return - V_77 ;
}
F_44 ( & V_3 -> V_33 , L_8 , V_6 ) ;
V_7 = F_12 ( V_3 ) ;
if ( V_7 < 0 )
F_43 ( & V_3 -> V_33 , L_9 ) ;
else
F_45 ( & V_1 -> V_86 ) ;
return V_7 ;
}
static int F_46 ( struct V_13 * V_14 , T_3 * V_111 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
* V_111 = V_1 -> V_44 ;
return 0 ;
}
static int F_47 ( struct V_13 * V_14 , unsigned int V_112 ,
enum V_113 * V_65 )
{
if ( V_112 )
return - V_75 ;
* V_65 = V_66 ;
return 0 ;
}
static int F_48 ( struct V_13 * V_14 ,
struct V_114 * V_115 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_116 * V_117 = F_49 ( V_3 ) ;
V_115 -> V_118 = V_119 | V_120 |
V_121 | V_122 |
V_123 | V_124 ;
V_115 -> type = V_125 ;
V_115 -> V_118 = F_50 ( V_117 , V_115 ) ;
return 0 ;
}
static int F_51 ( struct V_13 * V_14 ,
const struct V_114 * V_115 )
{
struct V_2 * V_3 = F_15 ( V_14 ) ;
struct V_116 * V_117 = F_49 ( V_3 ) ;
if ( F_50 ( V_117 , V_115 ) &
V_121 )
return F_9 ( V_3 , V_126 , 0x8000 ) ;
else
return F_8 ( V_3 , V_126 , 0x8000 ) ;
}
static int F_52 ( struct V_2 * V_3 ,
const struct V_127 * V_128 )
{
struct V_1 * V_1 ;
struct V_116 * V_117 = F_49 ( V_3 ) ;
struct V_129 * V_130 = F_53 ( V_3 -> V_33 . V_131 ) ;
int V_7 ;
if ( ! V_117 ) {
F_43 ( & V_3 -> V_33 , L_10 ) ;
return - V_75 ;
}
if ( ! F_54 ( V_130 , V_132 ) ) {
F_55 ( & V_130 -> V_33 ,
L_11 ) ;
return - V_12 ;
}
V_1 = F_56 ( sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_1 )
return - V_134 ;
F_57 ( & V_1 -> V_4 , V_3 , & V_135 ) ;
F_58 ( & V_1 -> V_86 , 5 ) ;
F_59 ( & V_1 -> V_86 , & V_136 ,
V_92 , 0 , 1 , 1 , 0 ) ;
F_59 ( & V_1 -> V_86 , & V_136 ,
V_94 , 0 , 1 , 1 , 0 ) ;
F_59 ( & V_1 -> V_86 , & V_136 ,
V_95 , 0 , 127 , 1 , 64 ) ;
V_1 -> V_45 = F_60 ( & V_1 -> V_86 ,
& V_136 , V_88 , 1 , 0 ,
V_46 ) ;
V_1 -> V_89 = F_59 ( & V_1 -> V_86 , & V_136 ,
V_137 , 1 , 255 , 1 , 255 ) ;
V_1 -> V_4 . V_138 = & V_1 -> V_86 ;
if ( V_1 -> V_86 . error ) {
int V_139 = V_1 -> V_86 . error ;
F_61 ( V_1 ) ;
return V_139 ;
}
F_62 ( 2 , & V_1 -> V_45 ,
V_100 , true ) ;
V_1 -> V_44 = 0 ;
V_1 -> V_21 . V_30 = V_31 ;
V_1 -> V_21 . V_32 = V_53 ;
V_1 -> V_21 . V_34 = V_52 ;
V_1 -> V_21 . V_35 = V_55 ;
V_1 -> V_22 = 1 ;
V_1 -> V_23 = 1 ;
F_12 ( V_3 ) ;
V_7 = F_42 ( V_3 ) ;
F_13 ( V_3 ) ;
if ( V_7 ) {
F_63 ( & V_1 -> V_86 ) ;
F_61 ( V_1 ) ;
}
return V_7 ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_65 ( & V_1 -> V_4 ) ;
F_63 ( & V_1 -> V_86 ) ;
F_61 ( V_1 ) ;
return 0 ;
}
static int T_5 F_66 ( void )
{
return F_67 ( & V_140 ) ;
}
static void T_6 F_68 ( void )
{
F_69 ( & V_140 ) ;
}
