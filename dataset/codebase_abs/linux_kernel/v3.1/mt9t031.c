static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 , const T_1 V_5 )
{
T_2 V_6 = F_5 ( V_3 , V_5 ) ;
return V_6 < 0 ? V_6 : F_6 ( V_6 ) ;
}
static int F_7 ( struct V_2 * V_3 , const T_1 V_5 ,
const T_3 V_6 )
{
return F_8 ( V_3 , V_5 , F_6 ( V_6 ) ) ;
}
static int F_9 ( struct V_2 * V_3 , const T_1 V_5 ,
const T_3 V_6 )
{
int V_7 ;
V_7 = F_4 ( V_3 , V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_7 ( V_3 , V_5 , V_7 | V_6 ) ;
}
static int F_10 ( struct V_2 * V_3 , const T_1 V_5 ,
const T_3 V_6 )
{
int V_7 ;
V_7 = F_4 ( V_3 , V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_7 ( V_3 , V_5 , V_7 & ~ V_6 ) ;
}
static int F_11 ( struct V_2 * V_3 , const T_4 V_6 )
{
int V_7 ;
V_7 = F_7 ( V_3 , V_8 , V_6 >> 16 ) ;
if ( V_7 >= 0 )
V_7 = F_7 ( V_3 , V_9 , V_6 & 0xffff ) ;
return V_7 ;
}
static int F_12 ( struct V_2 * V_3 , T_4 * V_6 )
{
int V_7 ;
V_7 = F_4 ( V_3 , V_8 ) ;
* V_6 = V_7 << 16 ;
if ( V_7 >= 0 )
V_7 = F_4 ( V_3 , V_9 ) ;
* V_6 |= V_7 & 0xffff ;
return V_7 < 0 ? V_7 : 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_7 ;
V_7 = F_7 ( V_3 , V_10 , 1 ) ;
if ( V_7 >= 0 )
V_7 = F_7 ( V_3 , V_10 , 0 ) ;
if ( V_7 >= 0 )
V_7 = F_10 ( V_3 , V_11 , 2 ) ;
return V_7 >= 0 ? 0 : - V_12 ;
}
static int F_14 ( struct V_2 * V_3 )
{
F_10 ( V_3 , V_11 , 2 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , int V_15 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
int V_7 ;
if ( V_15 )
V_7 = F_9 ( V_3 , V_11 , 2 ) ;
else
V_7 = F_10 ( V_3 , V_11 , 2 ) ;
if ( V_7 < 0 )
return - V_12 ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 ,
unsigned long V_18 )
{
struct V_2 * V_3 = F_18 ( F_19 ( V_17 ) ) ;
if ( V_18 & ~ V_19 )
return - V_20 ;
if ( V_18 & V_21 )
F_10 ( V_3 , V_22 , 0x8000 ) ;
else
F_9 ( V_3 , V_22 , 0x8000 ) ;
return 0 ;
}
static unsigned long F_20 ( struct V_16 * V_17 )
{
struct V_23 * V_24 = F_21 ( V_17 ) ;
return F_22 ( V_24 , V_19 ) ;
}
static T_3 F_23 ( T_2 * V_25 , T_2 V_26 , T_2 V_27 )
{
unsigned int V_28 ;
if ( * V_25 < V_26 + V_26 / 2 ) {
* V_25 = V_26 ;
return 1 ;
}
V_28 = F_24 ( V_27 , * V_25 + V_26 / 2 ) / V_26 ;
if ( V_28 > 8 )
V_28 = 8 ;
* V_25 = V_26 * V_28 ;
return V_28 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_29 * V_30 , T_3 V_31 , T_3 V_32 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_7 ;
T_3 V_33 , V_34 ;
const T_3 V_35 = V_36 ,
V_37 = V_38 ;
V_33 = F_24 ( V_31 , ( T_3 ) 3 ) ;
V_34 = F_24 ( V_32 , ( T_3 ) 3 ) ;
switch ( V_33 ) {
case 1 :
V_30 -> V_39 &= ~ 1 ;
break;
case 2 :
V_30 -> V_39 &= ~ 3 ;
break;
case 3 :
V_30 -> V_39 = V_30 -> V_39 > F_26 ( V_40 , 6 ) ?
( V_30 -> V_39 / 6 ) * 6 : F_26 ( V_40 , 6 ) ;
}
V_30 -> V_41 &= ~ 1 ;
F_27 ( & V_3 -> V_42 , L_1 ,
V_31 , V_32 , V_30 -> V_43 , V_30 -> V_44 , V_30 -> V_39 , V_30 -> V_41 ) ;
V_7 = F_9 ( V_3 , V_11 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_3 , V_45 , V_35 ) ;
if ( V_7 >= 0 )
V_7 = F_7 ( V_3 , V_46 , V_37 ) ;
if ( V_32 != V_1 -> V_32 || V_31 != V_1 -> V_31 ) {
if ( V_7 >= 0 )
V_7 = F_7 ( V_3 , V_47 ,
( ( V_33 - 1 ) << 4 ) | ( V_31 - 1 ) ) ;
if ( V_7 >= 0 )
V_7 = F_7 ( V_3 , V_48 ,
( ( V_34 - 1 ) << 4 ) | ( V_32 - 1 ) ) ;
}
F_27 ( & V_3 -> V_42 , L_2 ,
V_30 -> V_39 , V_30 -> V_41 ) ;
if ( V_7 >= 0 )
V_7 = F_7 ( V_3 , V_49 , V_30 -> V_39 ) ;
if ( V_7 >= 0 )
V_7 = F_7 ( V_3 , V_50 , V_30 -> V_41 ) ;
if ( V_7 >= 0 )
V_7 = F_7 ( V_3 , V_51 , V_30 -> V_43 - 1 ) ;
if ( V_7 >= 0 )
V_7 = F_7 ( V_3 , V_52 ,
V_30 -> V_44 + V_1 -> V_53 - 1 ) ;
if ( V_7 >= 0 && V_1 -> V_54 ) {
unsigned int V_55 = V_30 -> V_44 + V_1 -> V_53 + V_37 ;
V_7 = F_11 ( V_3 , V_55 ) ;
if ( V_7 >= 0 ) {
const T_4 V_56 = V_57 + V_37 ;
const struct V_58 * V_59 =
& V_60 [ V_61 ] ;
V_1 -> V_62 = ( V_56 / 2 + ( V_55 - 1 ) *
( V_59 -> V_63 - V_59 -> V_64 ) ) /
V_56 + V_59 -> V_64 ;
}
}
if ( V_7 >= 0 )
V_7 = F_10 ( V_3 , V_11 , 1 ) ;
if ( V_7 >= 0 ) {
V_1 -> V_30 = * V_30 ;
V_1 -> V_31 = V_31 ;
V_1 -> V_32 = V_32 ;
}
return V_7 < 0 ? V_7 : 0 ;
}
static int F_28 ( struct V_13 * V_14 , struct V_65 * V_66 )
{
struct V_29 V_30 = V_66 -> V_67 ;
struct V_2 * V_3 = F_16 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_30 . V_43 = F_29 ( V_30 . V_43 , 2 ) ;
V_30 . V_44 = F_29 ( V_30 . V_44 , 2 ) ;
F_30 ( & V_30 . V_39 , & V_30 . V_43 ,
V_40 , V_68 , V_69 ) ;
F_30 ( & V_30 . V_41 , & V_30 . V_44 ,
V_70 , V_71 , V_57 ) ;
return F_25 ( V_3 , & V_30 , V_1 -> V_31 , V_1 -> V_32 ) ;
}
static int F_31 ( struct V_13 * V_14 , struct V_65 * V_66 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_66 -> V_67 = V_1 -> V_30 ;
V_66 -> type = V_72 ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 , struct V_73 * V_66 )
{
V_66 -> V_74 . V_39 = V_40 ;
V_66 -> V_74 . V_41 = V_70 ;
V_66 -> V_74 . V_43 = V_69 ;
V_66 -> V_74 . V_44 = V_57 ;
V_66 -> V_75 = V_66 -> V_74 ;
V_66 -> type = V_72 ;
V_66 -> V_76 . V_77 = 1 ;
V_66 -> V_76 . V_78 = 1 ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 ,
struct V_79 * V_80 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_80 -> V_43 = V_1 -> V_30 . V_43 / V_1 -> V_31 ;
V_80 -> V_44 = V_1 -> V_30 . V_44 / V_1 -> V_32 ;
V_80 -> V_81 = V_82 ;
V_80 -> V_83 = V_84 ;
V_80 -> V_85 = V_86 ;
return 0 ;
}
static int F_34 ( struct V_13 * V_14 ,
struct V_79 * V_80 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_31 , V_32 ;
struct V_29 V_30 = V_1 -> V_30 ;
V_31 = F_23 ( & V_30 . V_43 , V_80 -> V_43 , V_69 ) ;
V_32 = F_23 ( & V_30 . V_44 , V_80 -> V_44 , V_57 ) ;
V_80 -> V_81 = V_82 ;
V_80 -> V_83 = V_84 ;
return F_25 ( V_3 , & V_30 , V_31 , V_32 ) ;
}
static int F_35 ( struct V_13 * V_14 ,
struct V_79 * V_80 )
{
F_36 (
& V_80 -> V_43 , V_68 , V_69 , 1 ,
& V_80 -> V_44 , V_71 , V_57 , 1 , 0 ) ;
V_80 -> V_81 = V_82 ;
V_80 -> V_83 = V_84 ;
return 0 ;
}
static int F_37 ( struct V_13 * V_14 ,
struct V_87 * V_88 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_88 -> V_89 . type != V_90 )
return - V_20 ;
if ( V_88 -> V_89 . V_91 != V_3 -> V_91 )
return - V_92 ;
V_88 -> V_93 = V_1 -> V_94 ;
V_88 -> V_95 = 0 ;
return 0 ;
}
static int F_38 ( struct V_13 * V_14 ,
struct V_96 * V_5 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
if ( V_5 -> V_89 . type != V_90 || V_5 -> V_5 > 0xff )
return - V_20 ;
if ( V_5 -> V_89 . V_91 != V_3 -> V_91 )
return - V_92 ;
V_5 -> V_97 = F_4 ( V_3 , V_5 -> V_5 ) ;
if ( V_5 -> V_97 > 0xffff )
return - V_12 ;
return 0 ;
}
static int F_39 ( struct V_13 * V_14 ,
struct V_96 * V_5 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
if ( V_5 -> V_89 . type != V_90 || V_5 -> V_5 > 0xff )
return - V_20 ;
if ( V_5 -> V_89 . V_91 != V_3 -> V_91 )
return - V_92 ;
if ( F_7 ( V_3 , V_5 -> V_5 , V_5 -> V_97 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_40 ( struct V_13 * V_14 , struct V_98 * V_99 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_6 ;
switch ( V_99 -> V_88 ) {
case V_100 :
V_6 = F_4 ( V_3 , V_101 ) ;
if ( V_6 < 0 )
return - V_12 ;
V_99 -> V_102 = ! ! ( V_6 & 0x8000 ) ;
break;
case V_103 :
V_6 = F_4 ( V_3 , V_101 ) ;
if ( V_6 < 0 )
return - V_12 ;
V_99 -> V_102 = ! ! ( V_6 & 0x4000 ) ;
break;
case V_104 :
V_99 -> V_102 = V_1 -> V_54 ;
break;
case V_105 :
V_99 -> V_102 = V_1 -> V_106 ;
break;
case V_107 :
V_99 -> V_102 = V_1 -> V_62 ;
break;
}
return 0 ;
}
static int F_41 ( struct V_13 * V_14 , struct V_98 * V_99 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_58 * V_59 ;
int V_6 ;
switch ( V_99 -> V_88 ) {
case V_100 :
if ( V_99 -> V_102 )
V_6 = F_9 ( V_3 , V_101 , 0x8000 ) ;
else
V_6 = F_10 ( V_3 , V_101 , 0x8000 ) ;
if ( V_6 < 0 )
return - V_12 ;
break;
case V_103 :
if ( V_99 -> V_102 )
V_6 = F_9 ( V_3 , V_101 , 0x4000 ) ;
else
V_6 = F_10 ( V_3 , V_101 , 0x4000 ) ;
if ( V_6 < 0 )
return - V_12 ;
break;
case V_105 :
V_59 = & V_60 [ V_108 ] ;
if ( V_99 -> V_102 > V_59 -> V_63 || V_99 -> V_102 < V_59 -> V_64 )
return - V_20 ;
if ( V_99 -> V_102 <= V_59 -> V_109 ) {
unsigned long V_110 = V_59 -> V_109 - V_59 -> V_64 ;
V_6 = ( ( V_99 -> V_102 - V_59 -> V_64 ) * 8 + V_110 / 2 ) / V_110 ;
F_27 ( & V_3 -> V_42 , L_3 , V_6 ) ;
V_6 = F_7 ( V_3 , V_111 , V_6 ) ;
if ( V_6 < 0 )
return - V_12 ;
} else {
unsigned long V_110 = V_59 -> V_63 - V_59 -> V_109 - 1 ;
unsigned long V_106 = ( ( V_99 -> V_102 - V_59 -> V_109 - 1 ) *
1015 + V_110 / 2 ) / V_110 + 9 ;
if ( V_106 <= 32 )
V_6 = V_106 ;
else if ( V_106 <= 64 )
V_6 = ( ( V_106 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_6 = ( ( ( V_106 - 64 + 7 ) * 32 ) & 0xff00 ) | 0x60 ;
F_27 ( & V_3 -> V_42 , L_4 ,
F_4 ( V_3 , V_111 ) , V_6 ) ;
V_6 = F_7 ( V_3 , V_111 , V_6 ) ;
if ( V_6 < 0 )
return - V_12 ;
}
V_1 -> V_106 = V_99 -> V_102 ;
break;
case V_107 :
V_59 = & V_60 [ V_61 ] ;
if ( V_99 -> V_102 > V_59 -> V_63 || V_99 -> V_102 < V_59 -> V_64 )
return - V_20 ;
else {
const unsigned long V_110 = V_59 -> V_63 - V_59 -> V_64 ;
const T_4 V_112 = ( ( V_99 -> V_102 - V_59 -> V_64 ) * 1048 +
V_110 / 2 ) / V_110 + 1 ;
T_4 V_113 ;
F_12 ( V_3 , & V_113 ) ;
F_27 ( & V_3 -> V_42 , L_5 ,
V_113 , V_112 ) ;
if ( F_11 ( V_3 , V_112 ) < 0 )
return - V_12 ;
V_1 -> V_62 = V_99 -> V_102 ;
V_1 -> V_54 = 0 ;
}
break;
case V_104 :
if ( V_99 -> V_102 ) {
const T_3 V_37 = V_38 ;
const T_4 V_56 = V_57 + V_37 ;
unsigned int V_55 = V_1 -> V_30 . V_44 +
V_1 -> V_53 + V_37 ;
if ( F_11 ( V_3 , V_55 ) < 0 )
return - V_12 ;
V_59 = & V_60 [ V_61 ] ;
V_1 -> V_62 = ( V_56 / 2 + ( V_55 - 1 ) *
( V_59 -> V_63 - V_59 -> V_64 ) ) /
V_56 + V_59 -> V_64 ;
V_1 -> V_54 = 1 ;
} else
V_1 -> V_54 = 0 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_42 ( struct V_114 * V_42 )
{
return 0 ;
}
static int F_43 ( struct V_114 * V_42 )
{
struct V_115 * V_116 = F_44 ( V_42 ) ;
struct V_16 * V_17 = F_45 ( V_116 -> V_117 ) ;
struct V_13 * V_14 = F_46 ( V_17 ) ;
struct V_2 * V_3 = F_16 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_7 ;
T_3 V_33 , V_34 ;
V_33 = F_24 ( V_1 -> V_31 , ( T_3 ) 3 ) ;
V_34 = F_24 ( V_1 -> V_32 , ( T_3 ) 3 ) ;
V_7 = F_7 ( V_3 , V_47 ,
( ( V_33 - 1 ) << 4 ) | ( V_1 -> V_31 - 1 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_3 , V_48 ,
( ( V_34 - 1 ) << 4 ) | ( V_1 -> V_32 - 1 ) ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_115 * V_116 = F_48 ( V_3 ) ;
T_2 V_6 ;
int V_7 ;
V_6 = F_7 ( V_3 , V_118 , 1 ) ;
F_27 ( & V_3 -> V_42 , L_6 , V_6 ) ;
V_6 = F_4 ( V_3 , V_119 ) ;
switch ( V_6 ) {
case 0x1621 :
V_1 -> V_94 = V_120 ;
break;
default:
F_49 ( & V_3 -> V_42 ,
L_7 , V_6 ) ;
return - V_92 ;
}
F_50 ( & V_3 -> V_42 , L_8 , V_6 ) ;
V_7 = F_13 ( V_3 ) ;
if ( V_7 < 0 )
F_49 ( & V_3 -> V_42 , L_9 ) ;
else
V_116 -> V_42 . type = & V_121 ;
V_1 -> V_62 = 255 ;
V_1 -> V_106 = 64 ;
return V_7 ;
}
static int F_51 ( struct V_13 * V_14 , T_4 * V_122 )
{
struct V_2 * V_3 = F_16 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
* V_122 = V_1 -> V_53 ;
return 0 ;
}
static int F_52 ( struct V_13 * V_14 , unsigned int V_123 ,
enum V_124 * V_81 )
{
if ( V_123 )
return - V_20 ;
* V_81 = V_82 ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 ,
const struct V_125 * V_126 )
{
struct V_1 * V_1 ;
struct V_16 * V_17 = V_3 -> V_42 . V_127 ;
struct V_128 * V_129 = F_54 ( V_3 -> V_42 . V_117 ) ;
int V_7 ;
if ( V_17 ) {
struct V_23 * V_24 = F_21 ( V_17 ) ;
if ( ! V_24 ) {
F_49 ( & V_3 -> V_42 , L_10 ) ;
return - V_20 ;
}
V_17 -> V_130 = & V_131 ;
}
if ( ! F_55 ( V_129 , V_132 ) ) {
F_56 ( & V_129 -> V_42 ,
L_11 ) ;
return - V_12 ;
}
V_1 = F_57 ( sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_1 )
return - V_134 ;
F_58 ( & V_1 -> V_4 , V_3 , & V_135 ) ;
V_1 -> V_53 = 0 ;
V_1 -> V_30 . V_39 = V_40 ;
V_1 -> V_30 . V_41 = V_70 ;
V_1 -> V_30 . V_43 = V_69 ;
V_1 -> V_30 . V_44 = V_57 ;
V_1 -> V_54 = 1 ;
V_1 -> V_31 = 1 ;
V_1 -> V_32 = 1 ;
F_13 ( V_3 ) ;
V_7 = F_47 ( V_3 ) ;
F_14 ( V_3 ) ;
if ( V_7 ) {
if ( V_17 )
V_17 -> V_130 = NULL ;
F_59 ( V_1 ) ;
}
return V_7 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_3 -> V_42 . V_127 ;
if ( V_17 )
V_17 -> V_130 = NULL ;
F_59 ( V_1 ) ;
return 0 ;
}
static int T_5 F_61 ( void )
{
return F_62 ( & V_136 ) ;
}
static void T_6 F_63 ( void )
{
F_64 ( & V_136 ) ;
}
