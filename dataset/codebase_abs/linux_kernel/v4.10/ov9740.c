static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
struct V_6 V_7 [] = {
{
. V_8 = V_2 -> V_8 ,
. V_9 = 0 ,
. V_10 = 2 ,
. V_11 = ( T_2 * ) & V_3 ,
} ,
{
. V_8 = V_2 -> V_8 ,
. V_9 = V_12 ,
. V_10 = 1 ,
. V_11 = V_4 ,
} ,
} ;
V_3 = F_2 ( V_3 ) ;
V_5 = F_3 ( V_2 -> V_13 , V_7 , 2 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 , L_1 , V_3 ) ;
return V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_6 V_7 ;
struct {
T_1 V_3 ;
T_2 V_4 ;
} V_15 V_11 ;
int V_5 ;
V_3 = F_2 ( V_3 ) ;
V_11 . V_3 = V_3 ;
V_11 . V_4 = V_4 ;
V_7 . V_8 = V_2 -> V_8 ;
V_7 . V_9 = 0 ;
V_7 . V_10 = 3 ;
V_7 . V_11 = ( T_2 * ) & V_11 ;
V_5 = F_3 ( V_2 -> V_13 , & V_7 , 1 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 , L_2 , V_3 ) ;
return V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_16 , T_2 V_17 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 ,
L_3 ,
V_3 ) ;
return V_5 ;
}
V_4 |= V_16 ;
V_4 &= ~ V_17 ;
V_5 = F_5 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 ,
L_4 ,
V_3 ) ;
return V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_18 * V_19 ,
int V_20 )
{
int V_21 ;
int V_5 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
V_5 = F_5 ( V_2 ,
V_19 [ V_21 ] . V_3 , V_19 [ V_21 ] . V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_8 ( struct V_22 * V_23 , int V_24 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_25 * V_26 = F_10 ( V_23 ) ;
int V_5 ;
if ( V_26 -> V_27 )
V_5 = F_6 ( V_2 , V_28 , 0x2 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_28 , 0 , 0x2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_26 -> V_29 )
V_5 = F_6 ( V_2 , V_28 , 0x1 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_28 , 0 , 0x1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_24 ) {
F_11 ( & V_2 -> V_14 , L_5 ) ;
V_5 = F_5 ( V_2 , V_30 , 0x01 ) ;
} else {
F_11 ( & V_2 -> V_14 , L_6 ) ;
V_5 = F_5 ( V_2 , V_31 , 0x01 ) ;
if ( ! V_5 )
V_5 = F_5 ( V_2 , V_30 ,
0x00 ) ;
}
V_26 -> V_32 = V_24 ;
return V_5 ;
}
static void F_12 ( T_3 * V_33 , T_3 * V_34 )
{
* V_33 = F_13 ( * V_33 , 4 ) ;
if ( * V_33 > V_35 )
* V_33 = V_35 ;
if ( * V_34 > V_36 )
* V_34 = V_36 ;
}
static int F_14 ( struct V_1 * V_2 , T_3 V_33 , T_3 V_34 )
{
T_3 V_37 ;
T_3 V_38 ;
T_3 V_39 ;
T_3 V_40 ;
bool V_41 = false ;
T_3 V_42 ;
T_3 V_43 ;
int V_5 ;
if ( ( V_33 != V_35 ) || ( V_34 != V_36 ) )
V_41 = true ;
if ( ( V_35 * V_34 ) > ( V_36 * V_33 ) ) {
V_42 = ( V_36 * V_33 ) / V_34 ;
V_43 = V_36 ;
} else {
V_42 = V_35 ;
V_43 = ( V_35 * V_34 ) / V_33 ;
}
V_37 = ( V_35 - V_42 ) / 2 ;
V_38 = ( V_36 - V_43 ) / 2 ;
V_39 = V_37 + V_42 - 1 ;
V_40 = V_38 + V_43 - 1 ;
V_5 = F_5 ( V_2 , V_44 , V_37 >> 8 ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_46 , V_37 & 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_47 , V_38 >> 8 ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_48 , V_38 & 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_49 , V_39 >> 8 ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_50 , V_39 & 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_51 , V_40 >> 8 ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_52 , V_40 & 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_53 , V_33 >> 8 ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_54 , V_33 & 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_55 , V_34 >> 8 ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_56 , V_34 & 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_57 , V_42 >> 8 ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_58 , V_42 & 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_59 , V_43 >> 8 ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_60 , V_43 & 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_61 ,
( V_42 - V_33 ) >> 8 ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_62 ,
( V_42 - V_33 ) & 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_63 , 0xff ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_64 , 0xef |
( V_41 << 4 ) ) ;
if ( V_5 )
goto V_45;
V_5 = F_5 ( V_2 , V_65 , 0xff ) ;
V_45:
return V_5 ;
}
static int F_15 ( struct V_22 * V_23 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_25 * V_26 = F_10 ( V_23 ) ;
enum V_68 V_69 ;
T_3 V_70 = V_67 -> V_70 ;
int V_5 ;
F_12 ( & V_67 -> V_33 , & V_67 -> V_34 ) ;
switch ( V_70 ) {
case V_71 :
V_69 = V_72 ;
break;
default:
return - V_73 ;
}
V_5 = F_7 ( V_2 , V_74 ,
F_16 ( V_74 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_2 , V_67 -> V_33 , V_67 -> V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
V_67 -> V_70 = V_70 ;
V_67 -> V_75 = V_69 ;
memcpy ( & V_26 -> V_76 , V_67 , sizeof( struct V_66 ) ) ;
return V_5 ;
}
static int F_17 ( struct V_22 * V_23 ,
struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_66 * V_67 = & V_80 -> V_80 ;
if ( V_80 -> V_81 )
return - V_73 ;
F_12 ( & V_67 -> V_33 , & V_67 -> V_34 ) ;
V_67 -> V_82 = V_83 ;
V_67 -> V_70 = V_71 ;
V_67 -> V_75 = V_72 ;
if ( V_80 -> V_84 == V_85 )
return F_15 ( V_23 , V_67 ) ;
V_78 -> V_86 = * V_67 ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 ,
struct V_77 * V_78 ,
struct V_87 * V_70 )
{
if ( V_70 -> V_81 || V_70 -> V_88 >= F_16 ( V_89 ) )
return - V_73 ;
V_70 -> V_70 = V_89 [ V_70 -> V_88 ] ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_77 * V_78 ,
struct V_90 * V_91 )
{
if ( V_91 -> V_84 != V_85 )
return - V_73 ;
switch ( V_91 -> V_92 ) {
case V_93 :
case V_94 :
case V_95 :
V_91 -> V_96 . V_97 = 0 ;
V_91 -> V_96 . V_98 = 0 ;
V_91 -> V_96 . V_33 = V_35 ;
V_91 -> V_96 . V_34 = V_36 ;
return 0 ;
default:
return - V_73 ;
}
}
static int F_20 ( struct V_99 * V_100 )
{
struct V_25 * V_26 =
F_21 ( V_100 -> V_101 , struct V_25 , V_102 ) ;
switch ( V_100 -> V_103 ) {
case V_104 :
V_26 -> V_27 = V_100 -> V_4 ;
break;
case V_105 :
V_26 -> V_29 = V_100 -> V_4 ;
break;
default:
return - V_73 ;
}
return 0 ;
}
static int F_22 ( struct V_22 * V_23 , int V_106 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_107 * V_108 = F_23 ( V_2 ) ;
struct V_25 * V_26 = F_10 ( V_23 ) ;
int V_5 ;
if ( V_106 ) {
V_5 = F_24 ( & V_2 -> V_14 , V_108 , V_26 -> V_109 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_26 -> V_32 ) {
F_15 ( V_23 , & V_26 -> V_76 ) ;
F_8 ( V_23 , 1 ) ;
}
} else {
if ( V_26 -> V_32 ) {
F_8 ( V_23 , 0 ) ;
V_26 -> V_32 = true ;
}
F_25 ( & V_2 -> V_14 , V_108 , V_26 -> V_109 ) ;
}
return 0 ;
}
static int F_26 ( struct V_22 * V_23 ,
struct V_110 * V_3 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
int V_5 ;
T_2 V_4 ;
if ( V_3 -> V_3 & ~ 0xffff )
return - V_73 ;
V_3 -> V_111 = 2 ;
V_5 = F_1 ( V_2 , V_3 -> V_3 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_3 -> V_4 = ( V_112 ) V_4 ;
return V_5 ;
}
static int F_27 ( struct V_22 * V_23 ,
const struct V_110 * V_3 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
if ( V_3 -> V_3 & ~ 0xffff || V_3 -> V_4 & ~ 0xff )
return - V_73 ;
return F_5 ( V_2 , V_3 -> V_3 , V_3 -> V_4 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_29 ( V_2 ) ;
struct V_25 * V_26 = F_10 ( V_23 ) ;
T_2 V_113 , V_114 ;
int V_5 ;
V_5 = F_22 ( & V_26 -> V_115 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_116 , & V_113 ) ;
if ( V_5 < 0 )
goto V_45;
V_5 = F_1 ( V_2 , V_117 , & V_114 ) ;
if ( V_5 < 0 )
goto V_45;
V_26 -> V_118 = ( V_113 << 8 ) | V_114 ;
V_5 = F_1 ( V_2 , V_119 , & V_26 -> V_120 ) ;
if ( V_5 < 0 )
goto V_45;
V_5 = F_1 ( V_2 , V_121 , & V_26 -> V_122 ) ;
if ( V_5 < 0 )
goto V_45;
V_5 = F_1 ( V_2 , V_123 , & V_26 -> V_124 ) ;
if ( V_5 < 0 )
goto V_45;
if ( V_26 -> V_118 != 0x9740 ) {
V_5 = - V_125 ;
goto V_45;
}
F_30 ( & V_2 -> V_14 , L_7 ,
V_26 -> V_118 , V_26 -> V_120 , V_26 -> V_122 , V_26 -> V_124 ) ;
V_5 = F_31 ( & V_26 -> V_102 ) ;
V_45:
F_22 ( & V_26 -> V_115 , 0 ) ;
return V_5 ;
}
static int F_32 ( struct V_22 * V_23 ,
struct V_126 * V_78 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_107 * V_108 = F_23 ( V_2 ) ;
V_78 -> V_9 = V_127 | V_128 |
V_129 | V_130 |
V_131 ;
V_78 -> type = V_132 ;
V_78 -> V_9 = F_33 ( V_108 , V_78 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_133 * V_134 )
{
struct V_25 * V_26 ;
struct V_107 * V_108 = F_23 ( V_2 ) ;
int V_5 ;
if ( ! V_108 ) {
F_4 ( & V_2 -> V_14 , L_8 ) ;
return - V_73 ;
}
V_26 = F_35 ( & V_2 -> V_14 , sizeof( struct V_25 ) , V_135 ) ;
if ( ! V_26 ) {
F_4 ( & V_2 -> V_14 , L_9 ) ;
return - V_136 ;
}
F_36 ( & V_26 -> V_115 , V_2 , & V_137 ) ;
F_37 ( & V_26 -> V_102 , 13 ) ;
F_38 ( & V_26 -> V_102 , & V_138 ,
V_104 , 0 , 1 , 1 , 0 ) ;
F_38 ( & V_26 -> V_102 , & V_138 ,
V_105 , 0 , 1 , 1 , 0 ) ;
V_26 -> V_115 . V_139 = & V_26 -> V_102 ;
if ( V_26 -> V_102 . error )
return V_26 -> V_102 . error ;
V_26 -> V_109 = F_39 ( & V_2 -> V_14 , L_10 ) ;
if ( F_40 ( V_26 -> V_109 ) ) {
V_5 = F_41 ( V_26 -> V_109 ) ;
goto V_140;
}
V_5 = F_28 ( V_2 ) ;
if ( V_5 < 0 ) {
F_42 ( V_26 -> V_109 ) ;
V_140:
F_43 ( & V_26 -> V_102 ) ;
}
return V_5 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_29 ( V_2 ) ;
F_42 ( V_26 -> V_109 ) ;
F_45 ( & V_26 -> V_115 ) ;
F_43 ( & V_26 -> V_102 ) ;
return 0 ;
}
