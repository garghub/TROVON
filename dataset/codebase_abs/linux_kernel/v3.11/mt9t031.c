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
static int F_13 ( struct V_13 * V_14 , int V_15 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
int V_7 ;
if ( V_15 )
V_7 = F_8 ( V_3 , V_11 , 2 ) ;
else
V_7 = F_9 ( V_3 , V_11 , 2 ) ;
if ( V_7 < 0 )
return - V_12 ;
return 0 ;
}
static T_2 F_15 ( T_4 * V_16 , T_4 V_17 , T_4 V_18 )
{
unsigned int V_19 ;
if ( * V_16 < V_17 + V_17 / 2 ) {
* V_16 = V_17 ;
return 1 ;
}
V_19 = F_16 ( V_18 , * V_16 + V_17 / 2 ) / V_17 ;
if ( V_19 > 8 )
V_19 = 8 ;
* V_16 = V_17 * V_19 ;
return V_19 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_2 V_22 , T_2 V_23 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_7 ;
T_2 V_24 , V_25 ;
const T_2 V_26 = V_27 ,
V_28 = V_29 ;
V_24 = F_16 ( V_22 , ( T_2 ) 3 ) ;
V_25 = F_16 ( V_23 , ( T_2 ) 3 ) ;
switch ( V_24 ) {
case 1 :
V_21 -> V_30 &= ~ 1 ;
break;
case 2 :
V_21 -> V_30 &= ~ 3 ;
break;
case 3 :
V_21 -> V_30 = V_21 -> V_30 > F_18 ( V_31 , 6 ) ?
( V_21 -> V_30 / 6 ) * 6 : F_18 ( V_31 , 6 ) ;
}
V_21 -> V_32 &= ~ 1 ;
F_19 ( & V_3 -> V_33 , L_1 ,
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
F_19 ( & V_3 -> V_33 , L_2 ,
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
if ( V_7 >= 0 && F_20 ( V_1 -> V_45 ) == V_46 ) {
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
static int F_21 ( struct V_13 * V_14 , const struct V_48 * V_49 )
{
struct V_20 V_21 = V_49 -> V_50 ;
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_21 . V_34 = F_22 ( V_21 . V_34 , 2 ) ;
V_21 . V_35 = F_22 ( V_21 . V_35 , 2 ) ;
F_23 ( & V_21 . V_30 , & V_21 . V_34 ,
V_31 , V_51 , V_52 ) ;
F_23 ( & V_21 . V_32 , & V_21 . V_35 ,
V_53 , V_54 , V_55 ) ;
return F_17 ( V_3 , & V_21 , V_1 -> V_22 , V_1 -> V_23 ) ;
}
static int F_24 ( struct V_13 * V_14 , struct V_48 * V_49 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_49 -> V_50 = V_1 -> V_21 ;
V_49 -> type = V_56 ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , struct V_57 * V_49 )
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
static int F_26 ( struct V_13 * V_14 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_64 -> V_34 = V_1 -> V_21 . V_34 / V_1 -> V_22 ;
V_64 -> V_35 = V_1 -> V_21 . V_35 / V_1 -> V_23 ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
V_64 -> V_69 = V_70 ;
return 0 ;
}
static int F_27 ( struct V_13 * V_14 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_22 , V_23 ;
struct V_20 V_21 = V_1 -> V_21 ;
V_22 = F_15 ( & V_21 . V_34 , V_64 -> V_34 , V_52 ) ;
V_23 = F_15 ( & V_21 . V_35 , V_64 -> V_35 , V_55 ) ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
return F_17 ( V_3 , & V_21 , V_22 , V_23 ) ;
}
static int F_28 ( struct V_13 * V_14 ,
struct V_63 * V_64 )
{
F_29 (
& V_64 -> V_34 , V_51 , V_52 , 1 ,
& V_64 -> V_35 , V_54 , V_55 , 1 , 0 ) ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
return 0 ;
}
static int F_30 ( struct V_13 * V_14 ,
struct V_71 * V_5 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
if ( V_5 -> V_5 > 0xff )
return - V_72 ;
V_5 -> V_73 = 1 ;
V_5 -> V_74 = F_4 ( V_3 , V_5 -> V_5 ) ;
if ( V_5 -> V_74 > 0xffff )
return - V_12 ;
return 0 ;
}
static int F_31 ( struct V_13 * V_14 ,
const struct V_71 * V_5 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
if ( V_5 -> V_5 > 0xff )
return - V_72 ;
if ( F_6 ( V_3 , V_5 -> V_5 , V_5 -> V_74 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_32 ( struct V_75 * V_76 )
{
struct V_1 * V_1 = F_2 ( V_76 -> V_77 ,
struct V_1 , V_78 ) ;
const T_3 V_79 = V_55 + V_29 ;
T_4 F_16 , V_18 ;
switch ( V_76 -> V_80 ) {
case V_81 :
F_16 = V_1 -> V_82 -> V_83 ;
V_18 = V_1 -> V_82 -> V_84 ;
V_1 -> V_82 -> V_74 =
( V_79 / 2 + ( V_1 -> V_47 - 1 ) * ( V_18 - F_16 ) )
/ V_79 + F_16 ;
break;
}
return 0 ;
}
static int F_33 ( struct V_75 * V_76 )
{
struct V_1 * V_1 = F_2 ( V_76 -> V_77 ,
struct V_1 , V_78 ) ;
struct V_13 * V_14 = & V_1 -> V_4 ;
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_75 * exp = V_1 -> V_82 ;
int V_6 ;
switch ( V_76 -> V_80 ) {
case V_85 :
if ( V_76 -> V_74 )
V_6 = F_8 ( V_3 , V_86 , 0x8000 ) ;
else
V_6 = F_9 ( V_3 , V_86 , 0x8000 ) ;
if ( V_6 < 0 )
return - V_12 ;
return 0 ;
case V_87 :
if ( V_76 -> V_74 )
V_6 = F_8 ( V_3 , V_86 , 0x4000 ) ;
else
V_6 = F_9 ( V_3 , V_86 , 0x4000 ) ;
if ( V_6 < 0 )
return - V_12 ;
return 0 ;
case V_88 :
if ( V_76 -> V_74 <= V_76 -> V_89 ) {
unsigned long V_90 = V_76 -> V_89 - V_76 -> V_83 ;
V_6 = ( ( V_76 -> V_74 - V_76 -> V_83 ) * 8 + V_90 / 2 ) / V_90 ;
F_19 ( & V_3 -> V_33 , L_3 , V_6 ) ;
V_6 = F_6 ( V_3 , V_91 , V_6 ) ;
if ( V_6 < 0 )
return - V_12 ;
} else {
unsigned long V_90 = V_76 -> V_84 - V_76 -> V_89 - 1 ;
unsigned long V_92 = ( ( V_76 -> V_74 - V_76 -> V_89 - 1 ) *
1015 + V_90 / 2 ) / V_90 + 9 ;
if ( V_92 <= 32 )
V_6 = V_92 ;
else if ( V_92 <= 64 )
V_6 = ( ( V_92 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_6 = ( ( ( V_92 - 64 + 7 ) * 32 ) & 0xff00 ) | 0x60 ;
F_19 ( & V_3 -> V_33 , L_4 ,
F_4 ( V_3 , V_91 ) , V_6 ) ;
V_6 = F_6 ( V_3 , V_91 , V_6 ) ;
if ( V_6 < 0 )
return - V_12 ;
}
return 0 ;
case V_81 :
if ( V_76 -> V_74 == V_93 ) {
unsigned int V_90 = exp -> V_84 - exp -> V_83 ;
unsigned int V_94 = ( ( exp -> V_74 - exp -> V_83 ) * 1048 +
V_90 / 2 ) / V_90 + 1 ;
T_3 V_95 ;
F_11 ( V_3 , & V_95 ) ;
F_19 ( & V_3 -> V_33 , L_5 ,
V_95 , V_94 ) ;
if ( F_10 ( V_3 , V_94 ) < 0 )
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
return - V_72 ;
}
return 0 ;
}
static int F_34 ( struct V_96 * V_33 )
{
return 0 ;
}
static int F_35 ( struct V_96 * V_33 )
{
struct V_97 * V_98 = F_36 ( V_33 ) ;
struct V_13 * V_14 = F_37 ( V_98 ) ;
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_7 ;
T_2 V_24 , V_25 ;
V_24 = F_16 ( V_1 -> V_22 , ( T_2 ) 3 ) ;
V_25 = F_16 ( V_1 -> V_23 , ( T_2 ) 3 ) ;
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
static int F_38 ( struct V_13 * V_14 , int V_99 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_100 * V_101 = F_39 ( V_3 ) ;
struct V_97 * V_98 = F_40 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_7 ;
if ( V_99 ) {
V_7 = F_41 ( & V_3 -> V_33 , V_101 , V_1 -> V_102 ) ;
if ( V_7 < 0 )
return V_7 ;
V_98 -> V_33 . type = & V_103 ;
} else {
V_98 -> V_33 . type = NULL ;
F_42 ( & V_3 -> V_33 , V_101 , V_1 -> V_102 ) ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_4 V_6 ;
int V_7 ;
V_7 = F_38 ( & V_1 -> V_4 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_3 ) ;
if ( V_7 < 0 ) {
F_44 ( & V_3 -> V_33 , L_6 ) ;
goto V_104;
}
V_6 = F_4 ( V_3 , V_105 ) ;
switch ( V_6 ) {
case 0x1621 :
break;
default:
F_44 ( & V_3 -> V_33 ,
L_7 , V_6 ) ;
V_7 = - V_106 ;
goto V_104;
}
F_45 ( & V_3 -> V_33 , L_8 , V_6 ) ;
V_7 = F_46 ( & V_1 -> V_78 ) ;
V_104:
F_38 ( & V_1 -> V_4 , 0 ) ;
return V_7 ;
}
static int F_47 ( struct V_13 * V_14 , T_3 * V_107 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
* V_107 = V_1 -> V_44 ;
return 0 ;
}
static int F_48 ( struct V_13 * V_14 , unsigned int V_108 ,
enum V_109 * V_65 )
{
if ( V_108 )
return - V_72 ;
* V_65 = V_66 ;
return 0 ;
}
static int F_49 ( struct V_13 * V_14 ,
struct V_110 * V_111 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_100 * V_101 = F_39 ( V_3 ) ;
V_111 -> V_112 = V_113 | V_114 |
V_115 | V_116 |
V_117 | V_118 ;
V_111 -> type = V_119 ;
V_111 -> V_112 = F_50 ( V_101 , V_111 ) ;
return 0 ;
}
static int F_51 ( struct V_13 * V_14 ,
const struct V_110 * V_111 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_100 * V_101 = F_39 ( V_3 ) ;
if ( F_50 ( V_101 , V_111 ) &
V_115 )
return F_9 ( V_3 , V_120 , 0x8000 ) ;
else
return F_8 ( V_3 , V_120 , 0x8000 ) ;
}
static int F_52 ( struct V_2 * V_3 ,
const struct V_121 * V_122 )
{
struct V_1 * V_1 ;
struct V_100 * V_101 = F_39 ( V_3 ) ;
struct V_123 * V_124 = F_53 ( V_3 -> V_33 . V_125 ) ;
int V_7 ;
if ( ! V_101 ) {
F_44 ( & V_3 -> V_33 , L_9 ) ;
return - V_72 ;
}
if ( ! F_54 ( V_124 , V_126 ) ) {
F_55 ( & V_124 -> V_33 ,
L_10 ) ;
return - V_12 ;
}
V_1 = F_56 ( & V_3 -> V_33 , sizeof( struct V_1 ) , V_127 ) ;
if ( ! V_1 )
return - V_128 ;
F_57 ( & V_1 -> V_4 , V_3 , & V_129 ) ;
F_58 ( & V_1 -> V_78 , 5 ) ;
F_59 ( & V_1 -> V_78 , & V_130 ,
V_85 , 0 , 1 , 1 , 0 ) ;
F_59 ( & V_1 -> V_78 , & V_130 ,
V_87 , 0 , 1 , 1 , 0 ) ;
F_59 ( & V_1 -> V_78 , & V_130 ,
V_88 , 0 , 127 , 1 , 64 ) ;
V_1 -> V_45 = F_60 ( & V_1 -> V_78 ,
& V_130 , V_81 , 1 , 0 ,
V_46 ) ;
V_1 -> V_82 = F_59 ( & V_1 -> V_78 , & V_130 ,
V_131 , 1 , 255 , 1 , 255 ) ;
V_1 -> V_4 . V_132 = & V_1 -> V_78 ;
if ( V_1 -> V_78 . error )
return V_1 -> V_78 . error ;
F_61 ( 2 , & V_1 -> V_45 ,
V_93 , true ) ;
V_1 -> V_44 = 0 ;
V_1 -> V_21 . V_30 = V_31 ;
V_1 -> V_21 . V_32 = V_53 ;
V_1 -> V_21 . V_34 = V_52 ;
V_1 -> V_21 . V_35 = V_55 ;
V_1 -> V_22 = 1 ;
V_1 -> V_23 = 1 ;
V_1 -> V_102 = F_62 ( & V_3 -> V_33 , L_11 ) ;
if ( F_63 ( V_1 -> V_102 ) ) {
V_7 = F_64 ( V_1 -> V_102 ) ;
goto V_133;
}
V_7 = F_43 ( V_3 ) ;
if ( V_7 ) {
F_65 ( V_1 -> V_102 ) ;
V_133:
F_66 ( & V_1 -> V_78 ) ;
}
return V_7 ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_65 ( V_1 -> V_102 ) ;
F_68 ( & V_1 -> V_4 ) ;
F_66 ( & V_1 -> V_78 ) ;
return 0 ;
}
