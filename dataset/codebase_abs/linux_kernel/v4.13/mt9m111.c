static const struct V_1 * F_1 ( struct V_2 * V_2 ,
T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ )
if ( V_5 [ V_4 ] . V_3 == V_3 )
return V_5 + V_4 ;
return V_2 -> V_6 ;
}
static struct V_2 * F_3 ( const struct V_7 * V_8 )
{
return F_4 ( F_5 ( V_8 ) , struct V_2 , V_9 ) ;
}
static int F_6 ( struct V_7 * V_8 , const T_2 V_10 )
{
int V_11 ;
T_2 V_12 ;
struct V_2 * V_2 = F_3 ( V_8 ) ;
V_12 = ( V_10 >> 8 ) ;
if ( V_12 == V_2 -> V_13 )
return 0 ;
if ( V_12 > 2 )
return - V_14 ;
V_11 = F_7 ( V_8 , V_15 , V_12 ) ;
if ( ! V_11 )
V_2 -> V_13 = V_12 ;
return V_11 ;
}
static int F_8 ( struct V_7 * V_8 , const T_2 V_10 )
{
int V_11 ;
V_11 = F_6 ( V_8 , V_10 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_8 , V_10 & 0xff ) ;
F_10 ( & V_8 -> V_16 , L_1 , V_10 , V_11 ) ;
return V_11 ;
}
static int F_11 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_2 V_17 )
{
int V_11 ;
V_11 = F_6 ( V_8 , V_10 ) ;
if ( ! V_11 )
V_11 = F_7 ( V_8 , V_10 & 0xff , V_17 ) ;
F_10 ( & V_8 -> V_16 , L_2 , V_10 , V_17 , V_11 ) ;
return V_11 ;
}
static int F_12 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_2 V_17 )
{
int V_11 ;
V_11 = F_8 ( V_8 , V_10 ) ;
if ( V_11 >= 0 )
V_11 = F_11 ( V_8 , V_10 , V_11 | V_17 ) ;
return V_11 ;
}
static int F_13 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_2 V_17 )
{
int V_11 ;
V_11 = F_8 ( V_8 , V_10 ) ;
if ( V_11 >= 0 )
V_11 = F_11 ( V_8 , V_10 , V_11 & ~ V_17 ) ;
return V_11 ;
}
static int F_14 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_2 V_17 , const T_2 V_18 )
{
int V_11 ;
V_11 = F_8 ( V_8 , V_10 ) ;
if ( V_11 >= 0 )
V_11 = F_11 ( V_8 , V_10 , ( V_11 & ~ V_18 ) | V_17 ) ;
return V_11 ;
}
static int F_15 ( struct V_2 * V_2 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
return F_17 ( V_21 , V_20 -> V_22 ) ;
}
static int F_18 ( struct V_2 * V_2 ,
struct V_19 * V_20 , struct V_23 * V_24 ,
unsigned int V_25 , unsigned int V_26 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 = F_11 ( V_8 , V_20 -> V_27 , V_24 -> V_25 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_20 -> V_28 , V_24 -> V_26 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_20 -> V_29 , V_25 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_8 , V_20 -> V_30 , V_26 ) ;
return V_11 ;
}
static int F_19 ( struct V_2 * V_2 , struct V_23 * V_24 ,
int V_25 , int V_26 , T_1 V_3 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 ;
V_11 = F_17 ( V_31 , V_24 -> V_32 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_33 , V_24 -> V_34 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_35 , V_24 -> V_25 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_36 , V_24 -> V_26 ) ;
if ( V_3 != V_37 ) {
if ( ! V_11 )
V_11 = F_18 ( V_2 , & V_38 ,
V_24 , V_25 , V_26 ) ;
if ( ! V_11 )
V_11 = F_18 ( V_2 , & V_39 ,
V_24 , V_25 , V_26 ) ;
}
F_10 ( & V_8 -> V_16 , L_3 ,
V_40 , V_3 , V_24 -> V_25 , V_24 -> V_26 , V_24 -> V_32 , V_24 -> V_34 ,
V_25 , V_26 , V_11 ) ;
return V_11 ;
}
static int F_20 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
return F_17 ( V_41 , V_42 ) ;
}
static int F_21 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 ;
V_11 = F_22 ( V_41 , V_43 ) ;
if ( ! V_11 )
V_11 = F_22 ( V_41 , V_44 ) ;
if ( ! V_11 )
V_11 = F_23 ( V_41 , V_43
| V_44 ) ;
return V_11 ;
}
static int F_24 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_7 * V_8 = F_16 ( V_46 ) ;
struct V_2 * V_2 = F_3 ( V_8 ) ;
struct V_23 V_24 = V_50 -> V_51 ;
int V_25 , V_26 ;
int V_11 , V_52 = 0 ;
if ( V_50 -> V_53 != V_54 ||
V_50 -> V_55 != V_56 )
return - V_14 ;
if ( V_2 -> V_6 -> V_3 == V_57 ||
V_2 -> V_6 -> V_3 == V_37 ) {
V_52 = 1 ;
}
F_25 ( & V_24 . V_25 , 2 , V_58 , V_52 ,
& V_24 . V_26 , 2 , V_59 , V_52 , 0 ) ;
V_24 . V_32 = F_26 ( V_24 . V_32 , V_60 ,
V_60 + V_58 -
( V_61 ) V_24 . V_25 ) ;
V_24 . V_34 = F_26 ( V_24 . V_34 , V_62 ,
V_62 + V_59 -
( V_61 ) V_24 . V_26 ) ;
V_25 = F_27 ( V_2 -> V_25 , V_24 . V_25 ) ;
V_26 = F_27 ( V_2 -> V_26 , V_24 . V_26 ) ;
V_11 = F_19 ( V_2 , & V_24 , V_25 , V_26 , V_2 -> V_6 -> V_3 ) ;
if ( ! V_11 ) {
V_2 -> V_24 = V_24 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = V_26 ;
}
return V_11 ;
}
static int F_28 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_7 * V_8 = F_16 ( V_46 ) ;
struct V_2 * V_2 = F_3 ( V_8 ) ;
if ( V_50 -> V_53 != V_54 )
return - V_14 ;
switch ( V_50 -> V_55 ) {
case V_63 :
case V_64 :
V_50 -> V_51 . V_32 = V_60 ;
V_50 -> V_51 . V_34 = V_62 ;
V_50 -> V_51 . V_25 = V_58 ;
V_50 -> V_51 . V_26 = V_59 ;
return 0 ;
case V_56 :
V_50 -> V_51 = V_2 -> V_24 ;
return 0 ;
default:
return - V_14 ;
}
}
static int F_29 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_65 * V_66 )
{
struct V_67 * V_68 = & V_66 -> V_66 ;
struct V_2 * V_2 = F_4 ( V_46 , struct V_2 , V_9 ) ;
if ( V_66 -> V_69 )
return - V_14 ;
V_68 -> V_25 = V_2 -> V_25 ;
V_68 -> V_26 = V_2 -> V_26 ;
V_68 -> V_3 = V_2 -> V_6 -> V_3 ;
V_68 -> V_70 = V_2 -> V_6 -> V_70 ;
V_68 -> V_71 = V_72 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_2 ,
T_1 V_3 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
T_2 V_73 , V_74 = V_75 |
V_76 | V_77 |
V_78 | V_79 |
V_80 | V_81 |
V_82 |
V_83 ;
int V_11 ;
switch ( V_3 ) {
case V_57 :
V_73 = V_75 |
V_77 ;
break;
case V_37 :
V_73 = V_76 | V_77 ;
break;
case V_84 :
V_73 = V_77 | V_79 |
V_82 ;
break;
case V_85 :
V_73 = V_77 | V_79 ;
break;
case V_86 :
V_73 = V_77 | V_78 |
V_82 ;
break;
case V_87 :
V_73 = V_77 | V_78 ;
break;
case V_88 :
V_73 = V_77 | V_78 |
V_83 ;
break;
case V_89 :
V_73 = V_77 | V_78 |
V_82 |
V_83 ;
break;
case V_90 :
V_73 = 0 ;
break;
case V_91 :
V_73 = V_83 ;
break;
case V_92 :
V_73 = V_82 ;
break;
case V_93 :
V_73 = V_82 |
V_83 ;
break;
default:
F_31 ( & V_8 -> V_16 , L_4 , V_3 ) ;
return - V_14 ;
}
V_11 = F_14 ( V_8 , V_39 . V_94 ,
V_73 , V_74 ) ;
if ( ! V_11 )
V_11 = F_14 ( V_8 , V_38 . V_94 ,
V_73 , V_74 ) ;
return V_11 ;
}
static int F_32 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_65 * V_66 )
{
struct V_67 * V_68 = & V_66 -> V_66 ;
struct V_7 * V_8 = F_16 ( V_46 ) ;
struct V_2 * V_2 = F_4 ( V_46 , struct V_2 , V_9 ) ;
const struct V_1 * V_6 ;
struct V_23 * V_24 = & V_2 -> V_24 ;
bool V_95 ;
int V_11 ;
if ( V_66 -> V_69 )
return - V_14 ;
V_6 = F_1 ( V_2 , V_68 -> V_3 ) ;
V_95 = V_6 -> V_3 == V_57 ||
V_6 -> V_3 == V_37 ;
if ( V_95 ) {
V_24 -> V_25 = F_33 ( V_24 -> V_25 , 2 ) ;
V_24 -> V_26 = F_33 ( V_24 -> V_26 , 2 ) ;
}
if ( V_6 -> V_3 == V_37 ) {
V_68 -> V_25 = V_24 -> V_25 ;
V_68 -> V_26 = V_24 -> V_26 ;
} else {
if ( V_68 -> V_25 > V_24 -> V_25 )
V_68 -> V_25 = V_24 -> V_25 ;
if ( V_68 -> V_26 > V_24 -> V_26 )
V_68 -> V_26 = V_24 -> V_26 ;
}
F_10 ( & V_8 -> V_16 , L_5 , V_40 ,
V_68 -> V_25 , V_68 -> V_26 , V_6 -> V_3 ) ;
V_68 -> V_3 = V_6 -> V_3 ;
V_68 -> V_70 = V_6 -> V_70 ;
if ( V_66 -> V_53 == V_96 ) {
V_48 -> V_97 = * V_68 ;
return 0 ;
}
V_11 = F_19 ( V_2 , V_24 , V_68 -> V_25 , V_68 -> V_26 , V_68 -> V_3 ) ;
if ( ! V_11 )
V_11 = F_30 ( V_2 , V_68 -> V_3 ) ;
if ( ! V_11 ) {
V_2 -> V_25 = V_68 -> V_25 ;
V_2 -> V_26 = V_68 -> V_26 ;
V_2 -> V_6 = V_6 ;
}
return V_11 ;
}
static int F_34 ( struct V_45 * V_46 ,
struct V_98 * V_10 )
{
struct V_7 * V_8 = F_16 ( V_46 ) ;
int V_99 ;
if ( V_10 -> V_10 > 0x2ff )
return - V_14 ;
V_99 = F_8 ( V_8 , V_10 -> V_10 ) ;
V_10 -> V_100 = 2 ;
V_10 -> V_99 = ( V_101 ) V_99 ;
if ( V_10 -> V_99 > 0xffff )
return - V_102 ;
return 0 ;
}
static int F_35 ( struct V_45 * V_46 ,
const struct V_98 * V_10 )
{
struct V_7 * V_8 = F_16 ( V_46 ) ;
if ( V_10 -> V_10 > 0x2ff )
return - V_14 ;
if ( F_11 ( V_8 , V_10 -> V_10 , V_10 -> V_99 ) < 0 )
return - V_102 ;
return 0 ;
}
static int F_36 ( struct V_2 * V_2 , int V_103 , int V_18 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 ;
if ( V_103 )
V_11 = F_12 ( V_8 , V_2 -> V_20 -> V_104 , V_18 ) ;
else
V_11 = F_13 ( V_8 , V_2 -> V_20 -> V_104 , V_18 ) ;
return V_11 ;
}
static int F_37 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_17 ;
V_17 = F_38 ( V_105 ) ;
if ( V_17 >= 0 )
return ( V_17 & 0x2f ) * ( 1 << ( ( V_17 >> 10 ) & 1 ) ) *
( 1 << ( ( V_17 >> 9 ) & 1 ) ) ;
return V_17 ;
}
static int F_39 ( struct V_2 * V_2 , int V_106 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
T_2 V_99 ;
if ( V_106 > 63 * 2 * 2 )
return - V_14 ;
if ( ( V_106 >= 64 * 2 ) && ( V_106 < 63 * 2 * 2 ) )
V_99 = ( 1 << 10 ) | ( 1 << 9 ) | ( V_106 / 4 ) ;
else if ( ( V_106 >= 64 ) && ( V_106 < 64 * 2 ) )
V_99 = ( 1 << 9 ) | ( V_106 / 2 ) ;
else
V_99 = V_106 ;
return F_17 ( V_105 , V_99 ) ;
}
static int F_40 ( struct V_2 * V_2 , int V_99 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
if ( V_99 == V_107 )
return F_22 ( V_108 , V_109 ) ;
return F_23 ( V_108 , V_109 ) ;
}
static int F_41 ( struct V_2 * V_2 , int V_110 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
if ( V_110 )
return F_22 ( V_108 , V_111 ) ;
return F_23 ( V_108 , V_111 ) ;
}
static int F_42 ( struct V_112 * V_113 )
{
struct V_2 * V_2 = F_4 ( V_113 -> V_114 ,
struct V_2 , V_115 ) ;
switch ( V_113 -> V_116 ) {
case V_117 :
return F_36 ( V_2 , V_113 -> V_99 ,
V_118 ) ;
case V_119 :
return F_36 ( V_2 , V_113 -> V_99 ,
V_120 ) ;
case V_121 :
return F_39 ( V_2 , V_113 -> V_99 ) ;
case V_122 :
return F_40 ( V_2 , V_113 -> V_99 ) ;
case V_123 :
return F_41 ( V_2 , V_113 -> V_99 ) ;
}
return - V_14 ;
}
static int F_43 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 ;
F_44 ( V_2 -> V_106 , F_37 ( V_2 ) ) ;
V_11 = F_22 ( V_41 , V_43 ) ;
if ( ! V_11 )
V_11 = F_22 ( V_41 , V_44 |
V_124 |
V_125 ) ;
if ( ! V_11 )
V_11 = F_23 ( V_41 , V_42 ) ;
return V_11 ;
}
static void F_45 ( struct V_2 * V_2 )
{
F_15 ( V_2 , V_2 -> V_20 ) ;
F_30 ( V_2 , V_2 -> V_6 -> V_3 ) ;
F_19 ( V_2 , & V_2 -> V_24 ,
V_2 -> V_25 , V_2 -> V_26 , V_2 -> V_6 -> V_3 ) ;
F_46 ( & V_2 -> V_115 ) ;
}
static int F_47 ( struct V_2 * V_2 )
{
int V_11 = F_20 ( V_2 ) ;
if ( ! V_11 )
V_11 = F_21 ( V_2 ) ;
if ( ! V_11 )
F_45 ( V_2 ) ;
return V_11 ;
}
static int F_48 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 ;
V_11 = F_20 ( V_2 ) ;
if ( ! V_11 )
V_11 = F_21 ( V_2 ) ;
if ( ! V_11 )
V_11 = F_15 ( V_2 , V_2 -> V_20 ) ;
if ( V_11 )
F_31 ( & V_8 -> V_16 , L_6 , V_11 ) ;
return V_11 ;
}
static int F_49 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 ;
V_11 = F_50 ( V_2 -> V_126 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_47 ( V_2 ) ;
if ( V_11 < 0 ) {
F_31 ( & V_8 -> V_16 , L_7 , V_11 ) ;
F_51 ( V_2 -> V_126 ) ;
}
return V_11 ;
}
static void F_52 ( struct V_2 * V_2 )
{
F_43 ( V_2 ) ;
F_51 ( V_2 -> V_126 ) ;
}
static int F_53 ( struct V_45 * V_46 , int V_110 )
{
struct V_2 * V_2 = F_4 ( V_46 , struct V_2 , V_9 ) ;
int V_11 = 0 ;
F_54 ( & V_2 -> V_127 ) ;
if ( V_2 -> V_128 == ! V_110 ) {
if ( V_110 )
V_11 = F_49 ( V_2 ) ;
else
F_52 ( V_2 ) ;
}
if ( ! V_11 ) {
V_2 -> V_128 += V_110 ? 1 : - 1 ;
F_55 ( V_2 -> V_128 < 0 ) ;
}
F_56 ( & V_2 -> V_127 ) ;
return V_11 ;
}
static int F_57 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_129 * V_3 )
{
if ( V_3 -> V_69 || V_3 -> V_130 >= F_2 ( V_5 ) )
return - V_14 ;
V_3 -> V_3 = V_5 [ V_3 -> V_130 ] . V_3 ;
return 0 ;
}
static int F_58 ( struct V_45 * V_46 ,
struct V_131 * V_48 )
{
V_48 -> V_132 = V_133 | V_134 |
V_135 | V_136 |
V_137 ;
V_48 -> type = V_138 ;
return 0 ;
}
static int F_59 ( struct V_7 * V_8 )
{
struct V_2 * V_2 = F_3 ( V_8 ) ;
T_3 V_17 ;
int V_11 ;
V_11 = F_53 ( & V_2 -> V_9 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_17 = F_38 ( V_139 ) ;
switch ( V_17 ) {
case 0x143a :
F_60 ( & V_8 -> V_16 ,
L_8 , V_17 ) ;
break;
case 0x148c :
F_60 ( & V_8 -> V_16 , L_9 , V_17 ) ;
break;
default:
F_31 ( & V_8 -> V_16 ,
L_10 ,
V_17 ) ;
V_11 = - V_140 ;
goto V_141;
}
V_11 = F_48 ( V_2 ) ;
if ( V_11 )
goto V_141;
V_11 = F_46 ( & V_2 -> V_115 ) ;
V_141:
F_53 ( & V_2 -> V_9 , 0 ) ;
return V_11 ;
}
static int F_61 ( struct V_7 * V_8 ,
const struct V_142 * V_143 )
{
struct V_2 * V_2 ;
struct V_144 * V_145 = F_62 ( V_8 -> V_16 . V_146 ) ;
int V_11 ;
if ( ! F_63 ( V_145 , V_147 ) ) {
F_64 ( & V_145 -> V_16 ,
L_11 ) ;
return - V_102 ;
}
V_2 = F_65 ( & V_8 -> V_16 , sizeof( struct V_2 ) , V_148 ) ;
if ( ! V_2 )
return - V_149 ;
V_2 -> V_126 = F_66 ( & V_8 -> V_16 , L_12 ) ;
if ( F_67 ( V_2 -> V_126 ) )
return - V_150 ;
V_2 -> V_20 = & V_38 ;
F_68 ( & V_2 -> V_9 , V_8 , & V_151 ) ;
F_69 ( & V_2 -> V_115 , 5 ) ;
F_70 ( & V_2 -> V_115 , & V_152 ,
V_117 , 0 , 1 , 1 , 0 ) ;
F_70 ( & V_2 -> V_115 , & V_152 ,
V_119 , 0 , 1 , 1 , 0 ) ;
F_70 ( & V_2 -> V_115 , & V_152 ,
V_123 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_106 = F_70 ( & V_2 -> V_115 , & V_152 ,
V_121 , 0 , 63 * 2 * 2 , 1 , 32 ) ;
F_71 ( & V_2 -> V_115 ,
& V_152 , V_122 , 1 , 0 ,
V_107 ) ;
V_2 -> V_9 . V_153 = & V_2 -> V_115 ;
if ( V_2 -> V_115 . error ) {
V_11 = V_2 -> V_115 . error ;
goto V_154;
}
V_2 -> V_24 . V_32 = V_60 ;
V_2 -> V_24 . V_34 = V_62 ;
V_2 -> V_24 . V_25 = V_58 ;
V_2 -> V_24 . V_26 = V_59 ;
V_2 -> V_6 = & V_5 [ 0 ] ;
V_2 -> V_13 = - 1 ;
F_72 ( & V_2 -> V_127 ) ;
V_11 = F_59 ( V_8 ) ;
if ( V_11 < 0 )
goto V_155;
V_2 -> V_9 . V_16 = & V_8 -> V_16 ;
V_11 = F_73 ( & V_2 -> V_9 ) ;
if ( V_11 < 0 )
goto V_155;
return 0 ;
V_155:
F_74 ( & V_2 -> V_115 ) ;
V_154:
F_75 ( V_2 -> V_126 ) ;
return V_11 ;
}
static int F_76 ( struct V_7 * V_8 )
{
struct V_2 * V_2 = F_3 ( V_8 ) ;
F_77 ( & V_2 -> V_9 ) ;
F_75 ( V_2 -> V_126 ) ;
F_74 ( & V_2 -> V_115 ) ;
return 0 ;
}
