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
static int F_12 ( struct V_33 * V_34 ,
unsigned long V_9 )
{
return 0 ;
}
static unsigned long F_13 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_14 ( V_34 ) ;
unsigned long V_9 = V_37 | V_38 |
V_39 | V_40 |
V_41 | V_42 ;
return F_15 ( V_36 , V_9 ) ;
}
static void F_16 ( T_3 * V_43 , T_3 * V_44 )
{
* V_43 = F_17 ( * V_43 , 4 ) ;
if ( * V_43 > V_45 )
* V_43 = V_45 ;
if ( * V_44 > V_46 )
* V_44 = V_46 ;
}
static int F_18 ( struct V_1 * V_2 , T_3 V_43 , T_3 V_44 )
{
T_3 V_47 ;
T_3 V_48 ;
T_3 V_49 ;
T_3 V_50 ;
bool V_51 = 0 ;
T_3 V_52 ;
T_3 V_53 ;
int V_5 ;
if ( ( V_43 != V_45 ) || ( V_44 != V_46 ) )
V_51 = 1 ;
if ( ( V_45 * V_44 ) > ( V_46 * V_43 ) ) {
V_52 = ( V_46 * V_43 ) / V_44 ;
V_53 = V_46 ;
} else {
V_52 = V_45 ;
V_53 = ( V_45 * V_44 ) / V_43 ;
}
V_47 = ( V_45 - V_52 ) / 2 ;
V_48 = ( V_46 - V_53 ) / 2 ;
V_49 = V_47 + V_52 - 1 ;
V_50 = V_48 + V_53 - 1 ;
V_5 = F_5 ( V_2 , V_54 , V_47 >> 8 ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_56 , V_47 & 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_57 , V_48 >> 8 ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_58 , V_48 & 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_59 , V_49 >> 8 ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_60 , V_49 & 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_61 , V_50 >> 8 ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_62 , V_50 & 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_63 , V_43 >> 8 ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_64 , V_43 & 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_65 , V_44 >> 8 ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_66 , V_44 & 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_67 , V_52 >> 8 ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_68 , V_52 & 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_69 , V_53 >> 8 ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_70 , V_53 & 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_71 ,
( V_52 - V_43 ) >> 8 ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_72 ,
( V_52 - V_43 ) & 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_73 , 0xff ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_74 , 0xef |
( V_51 << 4 ) ) ;
if ( V_5 )
goto V_55;
V_5 = F_5 ( V_2 , V_75 , 0xff ) ;
V_55:
return V_5 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_25 * V_26 = F_10 ( V_23 ) ;
enum V_78 V_79 ;
enum V_80 V_81 = V_77 -> V_81 ;
int V_5 ;
F_16 ( & V_77 -> V_43 , & V_77 -> V_44 ) ;
switch ( V_81 ) {
case V_82 :
V_79 = V_83 ;
break;
default:
return - V_84 ;
}
V_5 = F_7 ( V_2 , V_85 ,
F_20 ( V_85 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_18 ( V_2 , V_77 -> V_43 , V_77 -> V_44 ) ;
if ( V_5 < 0 )
return V_5 ;
V_77 -> V_81 = V_81 ;
V_77 -> V_86 = V_79 ;
memcpy ( & V_26 -> V_87 , V_77 , sizeof( struct V_76 ) ) ;
return V_5 ;
}
static int F_21 ( struct V_22 * V_23 ,
struct V_76 * V_77 )
{
F_16 ( & V_77 -> V_43 , & V_77 -> V_44 ) ;
V_77 -> V_88 = V_89 ;
V_77 -> V_81 = V_82 ;
V_77 -> V_86 = V_83 ;
return 0 ;
}
static int F_22 ( struct V_22 * V_23 , unsigned int V_90 ,
enum V_80 * V_81 )
{
if ( V_90 >= F_20 ( V_91 ) )
return - V_84 ;
* V_81 = V_91 [ V_90 ] ;
return 0 ;
}
static int F_23 ( struct V_22 * V_23 , struct V_92 * V_93 )
{
V_93 -> V_94 . V_95 = 0 ;
V_93 -> V_94 . V_96 = 0 ;
V_93 -> V_94 . V_43 = V_45 ;
V_93 -> V_94 . V_44 = V_46 ;
V_93 -> V_97 = V_93 -> V_94 ;
V_93 -> type = V_98 ;
V_93 -> V_99 . V_100 = 1 ;
V_93 -> V_99 . V_101 = 1 ;
return 0 ;
}
static int F_24 ( struct V_22 * V_23 , struct V_102 * V_93 )
{
V_93 -> V_103 . V_95 = 0 ;
V_93 -> V_103 . V_96 = 0 ;
V_93 -> V_103 . V_43 = V_45 ;
V_93 -> V_103 . V_44 = V_46 ;
V_93 -> type = V_98 ;
return 0 ;
}
static int F_25 ( struct V_22 * V_23 , struct V_104 * V_105 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
switch ( V_105 -> V_106 ) {
case V_107 :
V_105 -> V_108 = V_26 -> V_27 ;
break;
case V_109 :
V_105 -> V_108 = V_26 -> V_29 ;
break;
default:
return - V_84 ;
}
return 0 ;
}
static int F_26 ( struct V_22 * V_23 , struct V_104 * V_105 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
switch ( V_105 -> V_106 ) {
case V_107 :
V_26 -> V_27 = V_105 -> V_108 ;
break;
case V_109 :
V_26 -> V_29 = V_105 -> V_108 ;
break;
default:
return - V_84 ;
}
return 0 ;
}
static int F_27 ( struct V_22 * V_23 ,
struct V_110 * V_106 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
V_106 -> V_111 = V_26 -> V_111 ;
V_106 -> V_112 = V_26 -> V_112 ;
return 0 ;
}
static int F_28 ( struct V_22 * V_23 , int V_113 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
if ( ! V_26 -> V_32 )
return 0 ;
if ( V_113 ) {
F_19 ( V_23 , & V_26 -> V_87 ) ;
F_8 ( V_23 , V_26 -> V_32 ) ;
} else {
F_8 ( V_23 , 0 ) ;
V_26 -> V_32 = true ;
}
return 0 ;
}
static int F_29 ( struct V_22 * V_23 ,
struct V_114 * V_3 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
int V_5 ;
T_2 V_4 ;
if ( V_3 -> V_3 & ~ 0xffff )
return - V_84 ;
V_3 -> V_115 = 2 ;
V_5 = F_1 ( V_2 , V_3 -> V_3 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_3 -> V_4 = ( V_116 ) V_4 ;
return V_5 ;
}
static int F_30 ( struct V_22 * V_23 ,
struct V_114 * V_3 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
if ( V_3 -> V_3 & ~ 0xffff || V_3 -> V_4 & ~ 0xff )
return - V_84 ;
return F_5 ( V_2 , V_3 -> V_3 , V_3 -> V_4 ) ;
}
static int F_31 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = F_32 ( V_2 ) ;
struct V_25 * V_26 = F_10 ( V_23 ) ;
T_2 V_117 , V_118 ;
int V_5 ;
F_33 ( ! V_34 -> V_119 ||
F_34 ( V_34 -> V_119 ) -> V_120 != V_34 -> V_121 ) ;
V_5 = F_1 ( V_2 , V_122 , & V_117 ) ;
if ( V_5 < 0 )
goto V_123;
V_5 = F_1 ( V_2 , V_124 , & V_118 ) ;
if ( V_5 < 0 )
goto V_123;
V_26 -> V_125 = ( V_117 << 8 ) | V_118 ;
V_5 = F_1 ( V_2 , V_126 , & V_26 -> V_112 ) ;
if ( V_5 < 0 )
goto V_123;
V_5 = F_1 ( V_2 , V_127 , & V_26 -> V_128 ) ;
if ( V_5 < 0 )
goto V_123;
V_5 = F_1 ( V_2 , V_129 , & V_26 -> V_130 ) ;
if ( V_5 < 0 )
goto V_123;
if ( V_26 -> V_125 != 0x9740 ) {
V_5 = - V_131 ;
goto V_123;
}
V_26 -> V_111 = V_132 ;
F_35 ( & V_2 -> V_14 , L_7
L_8 ,
V_26 -> V_125 , V_26 -> V_112 , V_26 -> V_128 , V_26 -> V_130 ) ;
V_123:
return V_5 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_133 * V_134 )
{
struct V_25 * V_26 ;
struct V_33 * V_34 = V_2 -> V_14 . V_135 ;
struct V_35 * V_36 ;
int V_5 ;
if ( ! V_34 ) {
F_4 ( & V_2 -> V_14 , L_9 ) ;
return - V_84 ;
}
V_36 = F_14 ( V_34 ) ;
if ( ! V_36 ) {
F_4 ( & V_2 -> V_14 , L_10 ) ;
return - V_84 ;
}
V_26 = F_37 ( sizeof( struct V_25 ) , V_136 ) ;
if ( ! V_26 ) {
F_4 ( & V_2 -> V_14 , L_11 ) ;
return - V_137 ;
}
F_38 ( & V_26 -> V_138 , V_2 , & V_139 ) ;
V_34 -> V_140 = & V_141 ;
V_5 = F_31 ( V_34 , V_2 ) ;
if ( V_5 < 0 ) {
V_34 -> V_140 = NULL ;
F_39 ( V_26 ) ;
}
return V_5 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_32 ( V_2 ) ;
F_39 ( V_26 ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_142 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( & V_142 ) ;
}
