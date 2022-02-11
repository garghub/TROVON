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
static int F_24 ( struct V_45 * V_46 , const struct V_47 * V_48 )
{
struct V_23 V_24 = V_48 -> V_49 ;
struct V_2 * V_2 = F_4 ( V_46 , struct V_2 , V_9 ) ;
int V_25 , V_26 ;
int V_11 ;
if ( V_48 -> type != V_50 )
return - V_14 ;
if ( V_2 -> V_6 -> V_3 == V_51 ||
V_2 -> V_6 -> V_3 == V_37 ) {
V_24 . V_25 = F_25 ( V_24 . V_25 , 2 ) ;
V_24 . V_26 = F_25 ( V_24 . V_26 , 2 ) ;
}
F_26 ( & V_24 . V_32 , & V_24 . V_25 ,
V_52 , 2 , V_53 ) ;
F_26 ( & V_24 . V_34 , & V_24 . V_26 ,
V_54 , 2 , V_55 ) ;
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
static int F_28 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_2 * V_2 = F_4 ( V_46 , struct V_2 , V_9 ) ;
V_48 -> V_49 = V_2 -> V_24 ;
V_48 -> type = V_50 ;
return 0 ;
}
static int F_29 ( struct V_45 * V_46 , struct V_56 * V_48 )
{
if ( V_48 -> type != V_50 )
return - V_14 ;
V_48 -> V_57 . V_32 = V_52 ;
V_48 -> V_57 . V_34 = V_54 ;
V_48 -> V_57 . V_25 = V_53 ;
V_48 -> V_57 . V_26 = V_55 ;
V_48 -> V_58 = V_48 -> V_57 ;
V_48 -> V_59 . V_60 = 1 ;
V_48 -> V_59 . V_61 = 1 ;
return 0 ;
}
static int F_30 ( struct V_45 * V_46 ,
struct V_62 * V_63 )
{
struct V_2 * V_2 = F_4 ( V_46 , struct V_2 , V_9 ) ;
V_63 -> V_25 = V_2 -> V_25 ;
V_63 -> V_26 = V_2 -> V_26 ;
V_63 -> V_3 = V_2 -> V_6 -> V_3 ;
V_63 -> V_64 = V_2 -> V_6 -> V_64 ;
V_63 -> V_65 = V_66 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_2 ,
T_1 V_3 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
T_2 V_67 , V_68 = V_69 |
V_70 | V_71 |
V_72 | V_73 |
V_74 | V_75 |
V_76 |
V_77 ;
int V_11 ;
switch ( V_3 ) {
case V_51 :
V_67 = V_69 |
V_71 ;
break;
case V_37 :
V_67 = V_70 | V_71 ;
break;
case V_78 :
V_67 = V_71 | V_73 |
V_76 ;
break;
case V_79 :
V_67 = V_71 | V_73 ;
break;
case V_80 :
V_67 = V_71 | V_72 |
V_76 ;
break;
case V_81 :
V_67 = V_71 | V_72 ;
break;
case V_82 :
V_67 = V_71 | V_72 |
V_77 ;
break;
case V_83 :
V_67 = V_71 | V_72 |
V_76 |
V_77 ;
break;
case V_84 :
V_67 = 0 ;
break;
case V_85 :
V_67 = V_77 ;
break;
case V_86 :
V_67 = V_76 ;
break;
case V_87 :
V_67 = V_76 |
V_77 ;
break;
default:
F_32 ( & V_8 -> V_16 , L_4 , V_3 ) ;
return - V_14 ;
}
V_11 = F_14 ( V_8 , V_39 . V_88 ,
V_67 , V_68 ) ;
if ( ! V_11 )
V_11 = F_14 ( V_8 , V_38 . V_88 ,
V_67 , V_68 ) ;
return V_11 ;
}
static int F_33 ( struct V_45 * V_46 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 = F_16 ( V_46 ) ;
struct V_2 * V_2 = F_4 ( V_46 , struct V_2 , V_9 ) ;
const struct V_1 * V_6 ;
struct V_23 * V_24 = & V_2 -> V_24 ;
bool V_89 ;
V_6 = F_1 ( V_2 , V_63 -> V_3 ) ;
V_89 = V_6 -> V_3 == V_51 ||
V_6 -> V_3 == V_37 ;
if ( V_89 ) {
V_24 -> V_25 = F_25 ( V_24 -> V_25 , 2 ) ;
V_24 -> V_26 = F_25 ( V_24 -> V_26 , 2 ) ;
}
if ( V_6 -> V_3 == V_37 ) {
V_63 -> V_25 = V_24 -> V_25 ;
V_63 -> V_26 = V_24 -> V_26 ;
} else {
if ( V_63 -> V_25 > V_24 -> V_25 )
V_63 -> V_25 = V_24 -> V_25 ;
if ( V_63 -> V_26 > V_24 -> V_26 )
V_63 -> V_26 = V_24 -> V_26 ;
}
F_10 ( & V_8 -> V_16 , L_5 , V_40 ,
V_63 -> V_25 , V_63 -> V_26 , V_6 -> V_3 ) ;
V_63 -> V_3 = V_6 -> V_3 ;
V_63 -> V_64 = V_6 -> V_64 ;
return 0 ;
}
static int F_34 ( struct V_45 * V_46 ,
struct V_62 * V_63 )
{
const struct V_1 * V_6 ;
struct V_2 * V_2 = F_4 ( V_46 , struct V_2 , V_9 ) ;
struct V_23 * V_24 = & V_2 -> V_24 ;
int V_11 ;
F_33 ( V_46 , V_63 ) ;
V_6 = F_1 ( V_2 , V_63 -> V_3 ) ;
V_11 = F_19 ( V_2 , V_24 , V_63 -> V_25 , V_63 -> V_26 , V_63 -> V_3 ) ;
if ( ! V_11 )
V_11 = F_31 ( V_2 , V_63 -> V_3 ) ;
if ( ! V_11 ) {
V_2 -> V_25 = V_63 -> V_25 ;
V_2 -> V_26 = V_63 -> V_26 ;
V_2 -> V_6 = V_6 ;
}
return V_11 ;
}
static int F_35 ( struct V_45 * V_46 ,
struct V_90 * V_10 )
{
struct V_7 * V_8 = F_16 ( V_46 ) ;
int V_91 ;
if ( V_10 -> V_10 > 0x2ff )
return - V_14 ;
V_91 = F_8 ( V_8 , V_10 -> V_10 ) ;
V_10 -> V_92 = 2 ;
V_10 -> V_91 = ( V_93 ) V_91 ;
if ( V_10 -> V_91 > 0xffff )
return - V_94 ;
return 0 ;
}
static int F_36 ( struct V_45 * V_46 ,
const struct V_90 * V_10 )
{
struct V_7 * V_8 = F_16 ( V_46 ) ;
if ( V_10 -> V_10 > 0x2ff )
return - V_14 ;
if ( F_11 ( V_8 , V_10 -> V_10 , V_10 -> V_91 ) < 0 )
return - V_94 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_2 , int V_95 , int V_18 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 ;
if ( V_95 )
V_11 = F_12 ( V_8 , V_2 -> V_20 -> V_96 , V_18 ) ;
else
V_11 = F_13 ( V_8 , V_2 -> V_20 -> V_96 , V_18 ) ;
return V_11 ;
}
static int F_38 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_17 ;
V_17 = F_39 ( V_97 ) ;
if ( V_17 >= 0 )
return ( V_17 & 0x2f ) * ( 1 << ( ( V_17 >> 10 ) & 1 ) ) *
( 1 << ( ( V_17 >> 9 ) & 1 ) ) ;
return V_17 ;
}
static int F_40 ( struct V_2 * V_2 , int V_98 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
T_2 V_91 ;
if ( V_98 > 63 * 2 * 2 )
return - V_14 ;
if ( ( V_98 >= 64 * 2 ) && ( V_98 < 63 * 2 * 2 ) )
V_91 = ( 1 << 10 ) | ( 1 << 9 ) | ( V_98 / 4 ) ;
else if ( ( V_98 >= 64 ) && ( V_98 < 64 * 2 ) )
V_91 = ( 1 << 9 ) | ( V_98 / 2 ) ;
else
V_91 = V_98 ;
return F_17 ( V_97 , V_91 ) ;
}
static int F_41 ( struct V_2 * V_2 , int V_91 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
if ( V_91 == V_99 )
return F_22 ( V_100 , V_101 ) ;
return F_23 ( V_100 , V_101 ) ;
}
static int F_42 ( struct V_2 * V_2 , int V_102 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
if ( V_102 )
return F_22 ( V_100 , V_103 ) ;
return F_23 ( V_100 , V_103 ) ;
}
static int F_43 ( struct V_104 * V_105 )
{
struct V_2 * V_2 = F_4 ( V_105 -> V_106 ,
struct V_2 , V_107 ) ;
switch ( V_105 -> V_108 ) {
case V_109 :
return F_37 ( V_2 , V_105 -> V_91 ,
V_110 ) ;
case V_111 :
return F_37 ( V_2 , V_105 -> V_91 ,
V_112 ) ;
case V_113 :
return F_40 ( V_2 , V_105 -> V_91 ) ;
case V_114 :
return F_41 ( V_2 , V_105 -> V_91 ) ;
case V_115 :
return F_42 ( V_2 , V_105 -> V_91 ) ;
}
return - V_14 ;
}
static int F_44 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 ;
F_45 ( V_2 -> V_98 , F_38 ( V_2 ) ) ;
V_11 = F_22 ( V_41 , V_43 ) ;
if ( ! V_11 )
V_11 = F_22 ( V_41 , V_44 |
V_116 |
V_117 ) ;
if ( ! V_11 )
V_11 = F_23 ( V_41 , V_42 ) ;
return V_11 ;
}
static void F_46 ( struct V_2 * V_2 )
{
F_15 ( V_2 , V_2 -> V_20 ) ;
F_31 ( V_2 , V_2 -> V_6 -> V_3 ) ;
F_19 ( V_2 , & V_2 -> V_24 ,
V_2 -> V_25 , V_2 -> V_26 , V_2 -> V_6 -> V_3 ) ;
F_47 ( & V_2 -> V_107 ) ;
}
static int F_48 ( struct V_2 * V_2 )
{
int V_11 = F_20 ( V_2 ) ;
if ( ! V_11 )
V_11 = F_21 ( V_2 ) ;
if ( ! V_11 )
F_46 ( V_2 ) ;
return V_11 ;
}
static int F_49 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
int V_11 ;
V_11 = F_20 ( V_2 ) ;
if ( ! V_11 )
V_11 = F_21 ( V_2 ) ;
if ( ! V_11 )
V_11 = F_15 ( V_2 , V_2 -> V_20 ) ;
if ( V_11 )
F_32 ( & V_8 -> V_16 , L_6 , V_11 ) ;
return V_11 ;
}
static int F_50 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
struct V_118 * V_119 = F_51 ( V_8 ) ;
int V_11 ;
V_11 = F_52 ( & V_8 -> V_16 , V_119 , V_2 -> V_120 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_48 ( V_2 ) ;
if ( V_11 < 0 ) {
F_32 ( & V_8 -> V_16 , L_7 , V_11 ) ;
F_53 ( & V_8 -> V_16 , V_119 , V_2 -> V_120 ) ;
}
return V_11 ;
}
static void F_54 ( struct V_2 * V_2 )
{
struct V_7 * V_8 = F_16 ( & V_2 -> V_9 ) ;
struct V_118 * V_119 = F_51 ( V_8 ) ;
F_44 ( V_2 ) ;
F_53 ( & V_8 -> V_16 , V_119 , V_2 -> V_120 ) ;
}
static int F_55 ( struct V_45 * V_46 , int V_102 )
{
struct V_2 * V_2 = F_4 ( V_46 , struct V_2 , V_9 ) ;
int V_11 = 0 ;
F_56 ( & V_2 -> V_121 ) ;
if ( V_2 -> V_122 == ! V_102 ) {
if ( V_102 )
V_11 = F_50 ( V_2 ) ;
else
F_54 ( V_2 ) ;
}
if ( ! V_11 ) {
V_2 -> V_122 += V_102 ? 1 : - 1 ;
F_57 ( V_2 -> V_122 < 0 ) ;
}
F_58 ( & V_2 -> V_121 ) ;
return V_11 ;
}
static int F_59 ( struct V_45 * V_46 , unsigned int V_123 ,
T_1 * V_3 )
{
if ( V_123 >= F_2 ( V_5 ) )
return - V_14 ;
* V_3 = V_5 [ V_123 ] . V_3 ;
return 0 ;
}
static int F_60 ( struct V_45 * V_46 ,
struct V_124 * V_125 )
{
struct V_7 * V_8 = F_16 ( V_46 ) ;
struct V_118 * V_119 = F_51 ( V_8 ) ;
V_125 -> V_126 = V_127 | V_128 |
V_129 | V_130 |
V_131 ;
V_125 -> type = V_132 ;
V_125 -> V_126 = F_61 ( V_119 , V_125 ) ;
return 0 ;
}
static int F_62 ( struct V_7 * V_8 )
{
struct V_2 * V_2 = F_3 ( V_8 ) ;
T_3 V_17 ;
int V_11 ;
V_11 = F_55 ( & V_2 -> V_9 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_17 = F_39 ( V_133 ) ;
switch ( V_17 ) {
case 0x143a :
F_63 ( & V_8 -> V_16 ,
L_8 , V_17 ) ;
break;
case 0x148c :
F_63 ( & V_8 -> V_16 , L_9 , V_17 ) ;
break;
default:
F_32 ( & V_8 -> V_16 ,
L_10 ,
V_17 ) ;
V_11 = - V_134 ;
goto V_135;
}
V_11 = F_49 ( V_2 ) ;
if ( V_11 )
goto V_135;
V_11 = F_47 ( & V_2 -> V_107 ) ;
V_135:
F_55 ( & V_2 -> V_9 , 0 ) ;
return V_11 ;
}
static int F_64 ( struct V_7 * V_8 ,
const struct V_136 * V_137 )
{
struct V_2 * V_2 ;
struct V_138 * V_139 = F_65 ( V_8 -> V_16 . V_140 ) ;
struct V_118 * V_119 = F_51 ( V_8 ) ;
int V_11 ;
if ( V_8 -> V_16 . V_141 ) {
V_119 = F_66 ( & V_8 -> V_16 , sizeof( * V_119 ) , V_142 ) ;
if ( ! V_119 )
return - V_143 ;
V_8 -> V_16 . V_144 = V_119 ;
}
if ( ! V_119 ) {
F_32 ( & V_8 -> V_16 , L_11 ) ;
return - V_14 ;
}
if ( ! F_67 ( V_139 , V_145 ) ) {
F_68 ( & V_139 -> V_16 ,
L_12 ) ;
return - V_94 ;
}
V_2 = F_66 ( & V_8 -> V_16 , sizeof( struct V_2 ) , V_142 ) ;
if ( ! V_2 )
return - V_143 ;
V_2 -> V_120 = F_69 ( & V_8 -> V_16 , L_13 ) ;
if ( F_70 ( V_2 -> V_120 ) )
return - V_146 ;
V_2 -> V_20 = & V_38 ;
F_71 ( & V_2 -> V_9 , V_8 , & V_147 ) ;
F_72 ( & V_2 -> V_107 , 5 ) ;
F_73 ( & V_2 -> V_107 , & V_148 ,
V_109 , 0 , 1 , 1 , 0 ) ;
F_73 ( & V_2 -> V_107 , & V_148 ,
V_111 , 0 , 1 , 1 , 0 ) ;
F_73 ( & V_2 -> V_107 , & V_148 ,
V_115 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_98 = F_73 ( & V_2 -> V_107 , & V_148 ,
V_113 , 0 , 63 * 2 * 2 , 1 , 32 ) ;
F_74 ( & V_2 -> V_107 ,
& V_148 , V_114 , 1 , 0 ,
V_99 ) ;
V_2 -> V_9 . V_149 = & V_2 -> V_107 ;
if ( V_2 -> V_107 . error ) {
V_11 = V_2 -> V_107 . error ;
goto V_150;
}
V_2 -> V_24 . V_32 = V_52 ;
V_2 -> V_24 . V_34 = V_54 ;
V_2 -> V_24 . V_25 = V_53 ;
V_2 -> V_24 . V_26 = V_55 ;
V_2 -> V_6 = & V_5 [ 0 ] ;
V_2 -> V_13 = - 1 ;
F_75 ( & V_2 -> V_121 ) ;
V_11 = F_76 ( & V_8 -> V_16 , V_119 ) ;
if ( V_11 < 0 )
goto V_151;
V_11 = F_62 ( V_8 ) ;
if ( V_11 < 0 )
goto V_151;
V_2 -> V_9 . V_16 = & V_8 -> V_16 ;
V_11 = F_77 ( & V_2 -> V_9 ) ;
if ( V_11 < 0 )
goto V_151;
return 0 ;
V_151:
F_78 ( & V_2 -> V_107 ) ;
V_150:
F_79 ( V_2 -> V_120 ) ;
return V_11 ;
}
static int F_80 ( struct V_7 * V_8 )
{
struct V_2 * V_2 = F_3 ( V_8 ) ;
F_81 ( & V_2 -> V_9 ) ;
F_79 ( V_2 -> V_120 ) ;
F_78 ( & V_2 -> V_107 ) ;
return 0 ;
}
