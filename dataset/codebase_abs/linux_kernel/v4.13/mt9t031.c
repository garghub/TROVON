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
static int F_21 ( struct V_13 * V_14 ,
struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_20 V_21 = V_51 -> V_52 ;
if ( V_51 -> V_53 != V_54 ||
V_51 -> V_17 != V_55 )
return - V_56 ;
V_21 . V_34 = F_22 ( V_21 . V_34 , 2 ) ;
V_21 . V_35 = F_22 ( V_21 . V_35 , 2 ) ;
F_23 ( & V_21 . V_30 , & V_21 . V_34 ,
V_31 , V_57 , V_58 ) ;
F_23 ( & V_21 . V_32 , & V_21 . V_35 ,
V_59 , V_60 , V_61 ) ;
return F_17 ( V_3 , & V_21 , V_1 -> V_22 , V_1 -> V_23 ) ;
}
static int F_24 ( struct V_13 * V_14 ,
struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_51 -> V_53 != V_54 )
return - V_56 ;
switch ( V_51 -> V_17 ) {
case V_62 :
case V_63 :
V_51 -> V_52 . V_30 = V_31 ;
V_51 -> V_52 . V_32 = V_59 ;
V_51 -> V_52 . V_34 = V_58 ;
V_51 -> V_52 . V_35 = V_61 ;
return 0 ;
case V_55 :
V_51 -> V_52 = V_1 -> V_21 ;
return 0 ;
default:
return - V_56 ;
}
}
static int F_25 ( struct V_13 * V_14 ,
struct V_48 * V_49 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 = & V_65 -> V_65 ;
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_65 -> V_68 )
return - V_56 ;
V_67 -> V_34 = V_1 -> V_21 . V_34 / V_1 -> V_22 ;
V_67 -> V_35 = V_1 -> V_21 . V_35 / V_1 -> V_23 ;
V_67 -> V_69 = V_70 ;
V_67 -> V_71 = V_72 ;
V_67 -> V_73 = V_74 ;
return 0 ;
}
static int F_26 ( struct V_13 * V_14 ,
struct V_48 * V_49 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 = & V_65 -> V_65 ;
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_22 , V_23 ;
struct V_20 V_21 = V_1 -> V_21 ;
if ( V_65 -> V_68 )
return - V_56 ;
V_67 -> V_69 = V_70 ;
V_67 -> V_71 = V_72 ;
F_27 (
& V_67 -> V_34 , V_57 , V_58 , 1 ,
& V_67 -> V_35 , V_60 , V_61 , 1 , 0 ) ;
if ( V_65 -> V_53 == V_75 ) {
V_49 -> V_76 = * V_67 ;
return 0 ;
}
V_22 = F_15 ( & V_21 . V_34 , V_67 -> V_34 , V_58 ) ;
V_23 = F_15 ( & V_21 . V_35 , V_67 -> V_35 , V_61 ) ;
V_67 -> V_69 = V_70 ;
V_67 -> V_71 = V_72 ;
return F_17 ( V_3 , & V_21 , V_22 , V_23 ) ;
}
static int F_28 ( struct V_13 * V_14 ,
struct V_77 * V_5 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
if ( V_5 -> V_5 > 0xff )
return - V_56 ;
V_5 -> V_78 = 1 ;
V_5 -> V_79 = F_4 ( V_3 , V_5 -> V_5 ) ;
if ( V_5 -> V_79 > 0xffff )
return - V_12 ;
return 0 ;
}
static int F_29 ( struct V_13 * V_14 ,
const struct V_77 * V_5 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
if ( V_5 -> V_5 > 0xff )
return - V_56 ;
if ( F_6 ( V_3 , V_5 -> V_5 , V_5 -> V_79 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_30 ( struct V_80 * V_81 )
{
struct V_1 * V_1 = F_2 ( V_81 -> V_82 ,
struct V_1 , V_83 ) ;
const T_3 V_84 = V_61 + V_29 ;
T_4 F_16 , V_18 ;
switch ( V_81 -> V_85 ) {
case V_86 :
F_16 = V_1 -> V_87 -> V_88 ;
V_18 = V_1 -> V_87 -> V_89 ;
V_1 -> V_87 -> V_79 =
( V_84 / 2 + ( V_1 -> V_47 - 1 ) * ( V_18 - F_16 ) )
/ V_84 + F_16 ;
break;
}
return 0 ;
}
static int F_31 ( struct V_80 * V_81 )
{
struct V_1 * V_1 = F_2 ( V_81 -> V_82 ,
struct V_1 , V_83 ) ;
struct V_13 * V_14 = & V_1 -> V_4 ;
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_80 * exp = V_1 -> V_87 ;
int V_6 ;
switch ( V_81 -> V_85 ) {
case V_90 :
if ( V_81 -> V_79 )
V_6 = F_8 ( V_3 , V_91 , 0x8000 ) ;
else
V_6 = F_9 ( V_3 , V_91 , 0x8000 ) ;
if ( V_6 < 0 )
return - V_12 ;
return 0 ;
case V_92 :
if ( V_81 -> V_79 )
V_6 = F_8 ( V_3 , V_91 , 0x4000 ) ;
else
V_6 = F_9 ( V_3 , V_91 , 0x4000 ) ;
if ( V_6 < 0 )
return - V_12 ;
return 0 ;
case V_93 :
if ( V_81 -> V_79 <= V_81 -> V_94 ) {
unsigned long V_95 = V_81 -> V_94 - V_81 -> V_88 ;
V_6 = ( ( V_81 -> V_79 - ( T_4 ) V_81 -> V_88 ) * 8 + V_95 / 2 ) / V_95 ;
F_19 ( & V_3 -> V_33 , L_3 , V_6 ) ;
V_6 = F_6 ( V_3 , V_96 , V_6 ) ;
if ( V_6 < 0 )
return - V_12 ;
} else {
unsigned long V_95 = V_81 -> V_89 - V_81 -> V_94 - 1 ;
unsigned long V_97 = ( ( V_81 -> V_79 - ( T_4 ) V_81 -> V_94 - 1 ) *
1015 + V_95 / 2 ) / V_95 + 9 ;
if ( V_97 <= 32 )
V_6 = V_97 ;
else if ( V_97 <= 64 )
V_6 = ( ( V_97 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_6 = ( ( ( V_97 - 64 + 7 ) * 32 ) & 0xff00 ) | 0x60 ;
F_19 ( & V_3 -> V_33 , L_4 ,
F_4 ( V_3 , V_96 ) , V_6 ) ;
V_6 = F_6 ( V_3 , V_96 , V_6 ) ;
if ( V_6 < 0 )
return - V_12 ;
}
return 0 ;
case V_86 :
if ( V_81 -> V_79 == V_98 ) {
unsigned int V_95 = exp -> V_89 - exp -> V_88 ;
unsigned int V_99 = ( ( exp -> V_79 - ( T_4 ) exp -> V_88 ) * 1048 +
V_95 / 2 ) / V_95 + 1 ;
T_3 V_100 ;
F_11 ( V_3 , & V_100 ) ;
F_19 ( & V_3 -> V_33 , L_5 ,
V_100 , V_99 ) ;
if ( F_10 ( V_3 , V_99 ) < 0 )
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
return - V_56 ;
}
return 0 ;
}
static int F_32 ( struct V_101 * V_33 )
{
return 0 ;
}
static int F_33 ( struct V_101 * V_33 )
{
struct V_102 * V_103 = F_34 ( V_33 ) ;
struct V_13 * V_14 = F_35 ( V_103 ) ;
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
static int F_36 ( struct V_13 * V_14 , int V_104 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_105 * V_106 = F_37 ( V_3 ) ;
struct V_102 * V_103 = F_38 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_7 ;
if ( V_104 ) {
V_7 = F_39 ( & V_3 -> V_33 , V_106 , V_1 -> V_107 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_103 )
V_103 -> V_33 . type = & V_108 ;
} else {
if ( V_103 )
V_103 -> V_33 . type = NULL ;
F_40 ( & V_3 -> V_33 , V_106 , V_1 -> V_107 ) ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_4 V_6 ;
int V_7 ;
V_7 = F_36 ( & V_1 -> V_4 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_3 ) ;
if ( V_7 < 0 ) {
F_42 ( & V_3 -> V_33 , L_6 ) ;
goto V_109;
}
V_6 = F_4 ( V_3 , V_110 ) ;
switch ( V_6 ) {
case 0x1621 :
break;
default:
F_42 ( & V_3 -> V_33 ,
L_7 , V_6 ) ;
V_7 = - V_111 ;
goto V_109;
}
F_43 ( & V_3 -> V_33 , L_8 , V_6 ) ;
V_7 = F_44 ( & V_1 -> V_83 ) ;
V_109:
F_36 ( & V_1 -> V_4 , 0 ) ;
return V_7 ;
}
static int F_45 ( struct V_13 * V_14 , T_3 * V_112 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
* V_112 = V_1 -> V_44 ;
return 0 ;
}
static int F_46 ( struct V_13 * V_14 ,
struct V_48 * V_49 ,
struct V_113 * V_69 )
{
if ( V_69 -> V_68 || V_69 -> V_114 )
return - V_56 ;
V_69 -> V_69 = V_70 ;
return 0 ;
}
static int F_47 ( struct V_13 * V_14 ,
struct V_115 * V_49 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_105 * V_106 = F_37 ( V_3 ) ;
V_49 -> V_116 = V_117 | V_118 |
V_119 | V_120 |
V_121 | V_122 ;
V_49 -> type = V_123 ;
V_49 -> V_116 = F_48 ( V_106 , V_49 ) ;
return 0 ;
}
static int F_49 ( struct V_13 * V_14 ,
const struct V_115 * V_49 )
{
struct V_2 * V_3 = F_14 ( V_14 ) ;
struct V_105 * V_106 = F_37 ( V_3 ) ;
if ( F_48 ( V_106 , V_49 ) &
V_119 )
return F_9 ( V_3 , V_124 , 0x8000 ) ;
else
return F_8 ( V_3 , V_124 , 0x8000 ) ;
}
static int F_50 ( struct V_2 * V_3 ,
const struct V_125 * V_126 )
{
struct V_1 * V_1 ;
struct V_105 * V_106 = F_37 ( V_3 ) ;
struct V_127 * V_128 = F_51 ( V_3 -> V_33 . V_129 ) ;
int V_7 ;
if ( ! V_106 ) {
F_42 ( & V_3 -> V_33 , L_9 ) ;
return - V_56 ;
}
if ( ! F_52 ( V_128 , V_130 ) ) {
F_53 ( & V_128 -> V_33 ,
L_10 ) ;
return - V_12 ;
}
V_1 = F_54 ( & V_3 -> V_33 , sizeof( struct V_1 ) , V_131 ) ;
if ( ! V_1 )
return - V_132 ;
F_55 ( & V_1 -> V_4 , V_3 , & V_133 ) ;
F_56 ( & V_1 -> V_83 , 5 ) ;
F_57 ( & V_1 -> V_83 , & V_134 ,
V_90 , 0 , 1 , 1 , 0 ) ;
F_57 ( & V_1 -> V_83 , & V_134 ,
V_92 , 0 , 1 , 1 , 0 ) ;
F_57 ( & V_1 -> V_83 , & V_134 ,
V_93 , 0 , 127 , 1 , 64 ) ;
V_1 -> V_45 = F_58 ( & V_1 -> V_83 ,
& V_134 , V_86 , 1 , 0 ,
V_46 ) ;
V_1 -> V_87 = F_57 ( & V_1 -> V_83 , & V_134 ,
V_135 , 1 , 255 , 1 , 255 ) ;
V_1 -> V_4 . V_136 = & V_1 -> V_83 ;
if ( V_1 -> V_83 . error )
return V_1 -> V_83 . error ;
F_59 ( 2 , & V_1 -> V_45 ,
V_98 , true ) ;
V_1 -> V_44 = 0 ;
V_1 -> V_21 . V_30 = V_31 ;
V_1 -> V_21 . V_32 = V_59 ;
V_1 -> V_21 . V_34 = V_58 ;
V_1 -> V_21 . V_35 = V_61 ;
V_1 -> V_22 = 1 ;
V_1 -> V_23 = 1 ;
V_1 -> V_107 = F_60 ( & V_3 -> V_33 , L_11 ) ;
if ( F_61 ( V_1 -> V_107 ) ) {
V_7 = F_62 ( V_1 -> V_107 ) ;
goto V_137;
}
V_7 = F_41 ( V_3 ) ;
if ( V_7 ) {
F_63 ( V_1 -> V_107 ) ;
V_137:
F_64 ( & V_1 -> V_83 ) ;
}
return V_7 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_63 ( V_1 -> V_107 ) ;
F_66 ( & V_1 -> V_4 ) ;
F_64 ( & V_1 -> V_83 ) ;
return 0 ;
}
