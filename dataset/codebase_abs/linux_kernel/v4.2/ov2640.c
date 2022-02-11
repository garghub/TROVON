static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 ,
const struct V_5 * V_6 )
{
int V_7 ;
while ( ( V_6 -> V_8 != 0xff ) || ( V_6 -> V_9 != 0xff ) ) {
V_7 = F_5 ( V_3 ,
V_6 -> V_8 , V_6 -> V_9 ) ;
F_6 ( & V_3 -> V_10 , L_1 ,
V_6 -> V_8 , V_6 -> V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 ++ ;
}
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
T_1 V_11 , T_1 V_12 , T_1 V_13 )
{
T_2 V_14 = F_8 ( V_3 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ V_12 ;
V_14 |= V_13 & V_12 ;
F_6 ( & V_3 -> V_10 , L_2 , V_11 , V_14 ) ;
return F_5 ( V_3 , V_11 , V_14 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
int V_7 ;
const struct V_5 V_15 [] = {
{ V_16 , V_17 } ,
{ V_18 , V_19 } ,
V_20 ,
} ;
V_7 = F_4 ( V_3 , V_15 ) ;
if ( V_7 )
goto V_21;
F_10 ( 5 ) ;
V_21:
F_11 ( & V_3 -> V_10 , L_3 , V_22 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_23 * V_24 , int V_25 )
{
return 0 ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_23 * V_24 =
& F_2 ( V_27 -> V_28 , struct V_1 , V_29 ) -> V_4 ;
struct V_2 * V_3 = F_14 ( V_24 ) ;
T_1 V_14 ;
int V_7 ;
V_7 = F_5 ( V_3 , V_16 , V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_27 -> V_30 ) {
case V_31 :
V_14 = V_27 -> V_14 ? V_32 : 0x00 ;
return F_7 ( V_3 , V_33 , V_32 , V_14 ) ;
case V_34 :
V_14 = V_27 -> V_14 ? V_35 : 0x00 ;
return F_7 ( V_3 , V_33 , V_35 , V_14 ) ;
}
return - V_36 ;
}
static int F_15 ( struct V_23 * V_24 ,
struct V_37 * V_11 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
int V_7 ;
V_11 -> V_38 = 1 ;
if ( V_11 -> V_11 > 0xff )
return - V_36 ;
V_7 = F_8 ( V_3 , V_11 -> V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
V_11 -> V_14 = V_7 ;
return 0 ;
}
static int F_16 ( struct V_23 * V_24 ,
const struct V_37 * V_11 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
if ( V_11 -> V_11 > 0xff ||
V_11 -> V_14 > 0xff )
return - V_36 ;
return F_5 ( V_3 , V_11 -> V_11 , V_11 -> V_14 ) ;
}
static int F_17 ( struct V_23 * V_24 , int V_39 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_40 * V_41 = F_18 ( V_3 ) ;
struct V_1 * V_42 = F_1 ( V_3 ) ;
return F_19 ( & V_3 -> V_10 , V_41 , V_42 -> V_43 , V_39 ) ;
}
static const struct V_44 * F_20 ( T_3 * V_45 , T_3 * V_46 )
{
int V_47 , V_48 = F_21 ( V_49 ) - 1 ;
for ( V_47 = 0 ; V_47 < F_21 ( V_49 ) ; V_47 ++ ) {
if ( V_49 [ V_47 ] . V_45 >= * V_45 &&
V_49 [ V_47 ] . V_46 >= * V_46 ) {
* V_45 = V_49 [ V_47 ] . V_45 ;
* V_46 = V_49 [ V_47 ] . V_46 ;
return & V_49 [ V_47 ] ;
}
}
* V_45 = V_49 [ V_48 ] . V_45 ;
* V_46 = V_49 [ V_48 ] . V_46 ;
return & V_49 [ V_48 ] ;
}
static int F_22 ( struct V_2 * V_3 , T_3 * V_45 , T_3 * V_46 ,
T_3 V_50 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
const struct V_5 * V_51 ;
int V_7 ;
V_42 -> V_52 = F_20 ( V_45 , V_46 ) ;
V_42 -> V_53 = 0 ;
switch ( V_50 ) {
case V_54 :
F_11 ( & V_3 -> V_10 , L_4 , V_22 ) ;
V_51 = V_55 ;
break;
case V_56 :
F_11 ( & V_3 -> V_10 , L_5 , V_22 ) ;
V_51 = V_57 ;
break;
case V_58 :
F_11 ( & V_3 -> V_10 , L_6 , V_22 ) ;
V_51 = V_59 ;
break;
default:
case V_60 :
F_11 ( & V_3 -> V_10 , L_7 , V_22 ) ;
V_51 = V_61 ;
}
F_9 ( V_3 ) ;
F_11 ( & V_3 -> V_10 , L_8 , V_22 ) ;
V_7 = F_4 ( V_3 , V_62 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_9 , V_22 , V_42 -> V_52 -> V_63 ) ;
V_7 = F_4 ( V_3 , V_64 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_42 -> V_52 -> V_65 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_10 , V_22 ) ;
V_7 = F_4 ( V_3 , V_66 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_51 ) ;
if ( V_7 < 0 )
goto V_21;
V_42 -> V_53 = V_50 ;
* V_45 = V_42 -> V_52 -> V_45 ;
* V_46 = V_42 -> V_52 -> V_46 ;
return 0 ;
V_21:
F_23 ( & V_3 -> V_10 , L_11 , V_22 , V_7 ) ;
F_9 ( V_3 ) ;
V_42 -> V_52 = NULL ;
return V_7 ;
}
static int F_24 ( struct V_23 * V_24 ,
struct V_67 * V_68 ,
struct V_69 * V_70 )
{
struct V_71 * V_72 = & V_70 -> V_70 ;
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_1 * V_42 = F_1 ( V_3 ) ;
if ( V_70 -> V_73 )
return - V_36 ;
if ( ! V_42 -> V_52 ) {
T_3 V_45 = V_74 , V_46 = V_75 ;
V_42 -> V_52 = F_20 ( & V_45 , & V_46 ) ;
V_42 -> V_53 = V_60 ;
}
V_72 -> V_45 = V_42 -> V_52 -> V_45 ;
V_72 -> V_46 = V_42 -> V_52 -> V_46 ;
V_72 -> V_50 = V_42 -> V_53 ;
switch ( V_72 -> V_50 ) {
case V_54 :
case V_56 :
V_72 -> V_76 = V_77 ;
break;
default:
case V_58 :
case V_60 :
V_72 -> V_76 = V_78 ;
}
V_72 -> V_79 = V_80 ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 ,
struct V_67 * V_68 ,
struct V_69 * V_70 )
{
struct V_71 * V_72 = & V_70 -> V_70 ;
struct V_2 * V_3 = F_14 ( V_24 ) ;
if ( V_70 -> V_73 )
return - V_36 ;
F_20 ( & V_72 -> V_45 , & V_72 -> V_46 ) ;
V_72 -> V_79 = V_80 ;
switch ( V_72 -> V_50 ) {
case V_54 :
case V_56 :
V_72 -> V_76 = V_77 ;
break;
default:
V_72 -> V_50 = V_60 ;
case V_58 :
case V_60 :
V_72 -> V_76 = V_78 ;
}
if ( V_70 -> V_81 == V_82 )
return F_22 ( V_3 , & V_72 -> V_45 ,
& V_72 -> V_46 , V_72 -> V_50 ) ;
V_68 -> V_83 = * V_72 ;
return 0 ;
}
static int F_26 ( struct V_23 * V_24 ,
struct V_67 * V_68 ,
struct V_84 * V_50 )
{
if ( V_50 -> V_73 || V_50 -> V_85 >= F_21 ( V_86 ) )
return - V_36 ;
V_50 -> V_50 = V_86 [ V_50 -> V_85 ] ;
return 0 ;
}
static int F_27 ( struct V_23 * V_24 , struct V_87 * V_88 )
{
V_88 -> V_89 . V_90 = 0 ;
V_88 -> V_89 . V_91 = 0 ;
V_88 -> V_89 . V_45 = V_92 ;
V_88 -> V_89 . V_46 = V_93 ;
V_88 -> type = V_94 ;
return 0 ;
}
static int F_28 ( struct V_23 * V_24 , struct V_95 * V_88 )
{
V_88 -> V_96 . V_90 = 0 ;
V_88 -> V_96 . V_91 = 0 ;
V_88 -> V_96 . V_45 = V_92 ;
V_88 -> V_96 . V_46 = V_93 ;
V_88 -> V_97 = V_88 -> V_96 ;
V_88 -> type = V_94 ;
V_88 -> V_98 . V_99 = 1 ;
V_88 -> V_98 . V_100 = 1 ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
T_1 V_101 , V_102 , V_103 , V_104 ;
const char * V_105 ;
int V_7 ;
V_7 = F_17 ( & V_42 -> V_4 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
F_5 ( V_3 , V_16 , V_17 ) ;
V_101 = F_8 ( V_3 , V_106 ) ;
V_102 = F_8 ( V_3 , V_107 ) ;
V_103 = F_8 ( V_3 , V_108 ) ;
V_104 = F_8 ( V_3 , V_109 ) ;
switch ( F_30 ( V_101 , V_102 ) ) {
case V_110 :
V_105 = L_12 ;
break;
default:
F_23 ( & V_3 -> V_10 ,
L_13 , V_101 , V_102 ) ;
V_7 = - V_111 ;
goto V_112;
}
F_31 ( & V_3 -> V_10 ,
L_14 ,
V_105 , V_101 , V_102 , V_103 , V_104 ) ;
V_7 = F_32 ( & V_42 -> V_29 ) ;
V_112:
F_17 ( & V_42 -> V_4 , 0 ) ;
return V_7 ;
}
static int F_33 ( struct V_23 * V_24 ,
struct V_113 * V_68 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_40 * V_41 = F_18 ( V_3 ) ;
V_68 -> V_114 = V_115 | V_116 |
V_117 | V_118 |
V_119 ;
V_68 -> type = V_120 ;
V_68 -> V_114 = F_34 ( V_41 , V_68 ) ;
return 0 ;
}
static int F_35 ( struct V_121 * V_10 , int V_39 )
{
struct V_2 * V_3 = F_36 ( V_10 ) ;
struct V_1 * V_42 = F_1 ( V_3 ) ;
F_11 ( & V_3 -> V_10 , L_15 ,
V_22 , V_39 ? L_16 : L_17 ) ;
if ( V_42 -> V_122 )
F_37 ( V_42 -> V_122 , ! V_39 ) ;
return 0 ;
}
static int F_38 ( struct V_121 * V_10 )
{
struct V_2 * V_3 = F_36 ( V_10 ) ;
struct V_1 * V_42 = F_1 ( V_3 ) ;
if ( V_42 -> V_123 ) {
F_37 ( V_42 -> V_123 , 1 ) ;
F_39 ( 3000 , 5000 ) ;
F_37 ( V_42 -> V_123 , 0 ) ;
}
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_1 * V_42 )
{
V_42 -> V_123 = F_41 ( & V_3 -> V_10 , L_18 ,
V_124 ) ;
if ( ! V_42 -> V_123 )
F_11 ( & V_3 -> V_10 , L_19 ) ;
else if ( F_42 ( V_42 -> V_123 ) )
return F_43 ( V_42 -> V_123 ) ;
V_42 -> V_122 = F_41 ( & V_3 -> V_10 , L_20 ,
V_125 ) ;
if ( ! V_42 -> V_122 )
F_11 ( & V_3 -> V_10 , L_21 ) ;
else if ( F_42 ( V_42 -> V_122 ) )
return F_43 ( V_42 -> V_122 ) ;
V_42 -> V_126 . V_127 = F_35 ;
V_42 -> V_126 . V_128 = F_38 ;
V_3 -> V_10 . V_129 = & V_42 -> V_126 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 ,
const struct V_130 * V_131 )
{
struct V_1 * V_42 ;
struct V_40 * V_41 = F_18 ( V_3 ) ;
struct V_132 * V_133 = F_45 ( V_3 -> V_10 . V_134 ) ;
int V_7 ;
if ( ! F_46 ( V_133 , V_135 ) ) {
F_23 ( & V_133 -> V_10 ,
L_22 ) ;
return - V_136 ;
}
V_42 = F_47 ( & V_3 -> V_10 , sizeof( struct V_1 ) , V_137 ) ;
if ( ! V_42 ) {
F_23 ( & V_133 -> V_10 ,
L_23 ) ;
return - V_138 ;
}
V_42 -> V_43 = F_48 ( & V_3 -> V_10 , L_24 ) ;
if ( F_42 ( V_42 -> V_43 ) )
return - V_139 ;
if ( ! V_41 && ! V_3 -> V_10 . V_140 ) {
F_23 ( & V_3 -> V_10 , L_25 ) ;
V_7 = - V_36 ;
goto V_141;
}
if ( ! V_41 ) {
V_7 = F_40 ( V_3 , V_42 ) ;
if ( V_7 )
goto V_141;
}
F_49 ( & V_42 -> V_4 , V_3 , & V_142 ) ;
F_50 ( & V_42 -> V_29 , 2 ) ;
F_51 ( & V_42 -> V_29 , & V_143 ,
V_31 , 0 , 1 , 1 , 0 ) ;
F_51 ( & V_42 -> V_29 , & V_143 ,
V_34 , 0 , 1 , 1 , 0 ) ;
V_42 -> V_4 . V_144 = & V_42 -> V_29 ;
if ( V_42 -> V_29 . error ) {
V_7 = V_42 -> V_29 . error ;
goto V_141;
}
V_7 = F_29 ( V_3 ) ;
if ( V_7 < 0 )
goto V_145;
V_7 = F_52 ( & V_42 -> V_4 ) ;
if ( V_7 < 0 )
goto V_145;
F_31 ( & V_133 -> V_10 , L_26 ) ;
return 0 ;
V_145:
F_53 ( & V_42 -> V_29 ) ;
V_141:
F_54 ( V_42 -> V_43 ) ;
return V_7 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
F_56 ( & V_42 -> V_4 ) ;
F_54 ( V_42 -> V_43 ) ;
F_57 ( & V_42 -> V_4 ) ;
F_53 ( & V_42 -> V_29 ) ;
return 0 ;
}
