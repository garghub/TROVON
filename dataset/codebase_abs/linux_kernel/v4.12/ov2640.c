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
static int F_12 ( struct V_23 * V_24 )
{
struct V_25 * V_26 =
& F_2 ( V_24 -> V_27 , struct V_1 , V_28 ) -> V_4 ;
struct V_2 * V_3 = F_13 ( V_26 ) ;
T_1 V_14 ;
int V_7 ;
V_7 = F_5 ( V_3 , V_16 , V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_24 -> V_29 ) {
case V_30 :
V_14 = V_24 -> V_14 ? V_31 | V_32 : 0x00 ;
return F_7 ( V_3 , V_33 ,
V_31 | V_32 , V_14 ) ;
case V_34 :
V_14 = V_24 -> V_14 ? V_35 : 0x00 ;
return F_7 ( V_3 , V_33 , V_35 , V_14 ) ;
}
return - V_36 ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_37 * V_11 )
{
struct V_2 * V_3 = F_13 ( V_26 ) ;
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
static int F_15 ( struct V_25 * V_26 ,
const struct V_37 * V_11 )
{
struct V_2 * V_3 = F_13 ( V_26 ) ;
if ( V_11 -> V_11 > 0xff ||
V_11 -> V_14 > 0xff )
return - V_36 ;
return F_5 ( V_3 , V_11 -> V_11 , V_11 -> V_14 ) ;
}
static int F_16 ( struct V_25 * V_26 , int V_39 )
{
#ifdef F_17
struct V_2 * V_3 = F_13 ( V_26 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
if ( V_40 -> V_41 )
F_18 ( V_40 -> V_41 , ! V_39 ) ;
if ( V_39 && V_40 -> V_42 ) {
F_18 ( V_40 -> V_42 , 1 ) ;
F_19 ( 3000 , 5000 ) ;
F_20 ( V_40 -> V_42 , 0 ) ;
}
#endif
return 0 ;
}
static const struct V_43 * F_21 ( T_3 V_44 , T_3 V_45 )
{
int V_46 , V_47 = F_22 ( V_48 ) - 1 ;
for ( V_46 = 0 ; V_46 < F_22 ( V_48 ) ; V_46 ++ ) {
if ( V_48 [ V_46 ] . V_44 >= V_44 &&
V_48 [ V_46 ] . V_45 >= V_45 )
return & V_48 [ V_46 ] ;
}
return & V_48 [ V_47 ] ;
}
static int F_23 ( struct V_2 * V_3 ,
const struct V_43 * V_49 , T_3 V_50 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
const struct V_5 * V_51 ;
T_1 V_14 ;
int V_7 ;
V_40 -> V_49 = V_49 ;
V_40 -> V_52 = 0 ;
switch ( V_50 ) {
case V_53 :
F_11 ( & V_3 -> V_10 , L_4 , V_22 ) ;
V_51 = V_54 ;
break;
case V_55 :
F_11 ( & V_3 -> V_10 , L_5 , V_22 ) ;
V_51 = V_56 ;
break;
case V_57 :
F_11 ( & V_3 -> V_10 , L_6 , V_22 ) ;
V_51 = V_58 ;
break;
case V_59 :
default:
F_11 ( & V_3 -> V_10 , L_7 , V_22 ) ;
V_51 = V_60 ;
break;
case V_61 :
F_11 ( & V_3 -> V_10 , L_8 , V_22 ) ;
V_51 = V_58 ;
break;
case V_62 :
F_11 ( & V_3 -> V_10 , L_9 , V_22 ) ;
V_51 = V_60 ;
break;
}
F_9 ( V_3 ) ;
F_11 ( & V_3 -> V_10 , L_10 , V_22 ) ;
V_7 = F_4 ( V_3 , V_63 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_11 , V_22 , V_40 -> V_49 -> V_64 ) ;
V_7 = F_4 ( V_3 , V_65 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_40 -> V_49 -> V_66 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_12 , V_22 ) ;
V_7 = F_4 ( V_3 , V_67 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_51 ) ;
if ( V_7 < 0 )
goto V_21;
V_14 = ( V_50 == V_61 )
|| ( V_50 == V_62 ) ? V_68 : 0x00 ;
V_7 = F_7 ( V_3 , V_69 , V_68 , V_14 ) ;
if ( V_7 < 0 )
goto V_21;
V_40 -> V_52 = V_50 ;
return 0 ;
V_21:
F_24 ( & V_3 -> V_10 , L_13 , V_22 , V_7 ) ;
F_9 ( V_3 ) ;
V_40 -> V_49 = NULL ;
return V_7 ;
}
static int F_25 ( struct V_25 * V_26 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 = & V_73 -> V_73 ;
struct V_2 * V_3 = F_13 ( V_26 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
if ( V_73 -> V_76 )
return - V_36 ;
if ( ! V_40 -> V_49 ) {
V_40 -> V_49 = F_21 ( V_77 , V_78 ) ;
V_40 -> V_52 = V_59 ;
}
V_75 -> V_44 = V_40 -> V_49 -> V_44 ;
V_75 -> V_45 = V_40 -> V_49 -> V_45 ;
V_75 -> V_50 = V_40 -> V_52 ;
V_75 -> V_79 = V_80 ;
V_75 -> V_81 = V_82 ;
return 0 ;
}
static int F_26 ( struct V_25 * V_26 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 = & V_73 -> V_73 ;
struct V_2 * V_3 = F_13 ( V_26 ) ;
const struct V_43 * V_49 ;
if ( V_73 -> V_76 )
return - V_36 ;
V_49 = F_21 ( V_75 -> V_44 , V_75 -> V_45 ) ;
V_75 -> V_44 = V_49 -> V_44 ;
V_75 -> V_45 = V_49 -> V_45 ;
V_75 -> V_81 = V_82 ;
V_75 -> V_79 = V_80 ;
switch ( V_75 -> V_50 ) {
case V_53 :
case V_55 :
case V_57 :
case V_59 :
case V_61 :
case V_62 :
break;
default:
V_75 -> V_50 = V_59 ;
break;
}
if ( V_73 -> V_83 == V_84 )
return F_23 ( V_3 , V_49 , V_75 -> V_50 ) ;
V_71 -> V_85 = * V_75 ;
return 0 ;
}
static int F_27 ( struct V_25 * V_26 ,
struct V_70 * V_71 ,
struct V_86 * V_50 )
{
if ( V_50 -> V_76 || V_50 -> V_87 >= F_22 ( V_88 ) )
return - V_36 ;
V_50 -> V_50 = V_88 [ V_50 -> V_87 ] ;
return 0 ;
}
static int F_28 ( struct V_25 * V_26 ,
struct V_70 * V_71 ,
struct V_89 * V_90 )
{
if ( V_90 -> V_83 != V_84 )
return - V_36 ;
switch ( V_90 -> V_91 ) {
case V_92 :
case V_93 :
case V_94 :
V_90 -> V_95 . V_96 = 0 ;
V_90 -> V_95 . V_97 = 0 ;
V_90 -> V_95 . V_44 = V_98 ;
V_90 -> V_95 . V_45 = V_99 ;
return 0 ;
default:
return - V_36 ;
}
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
T_1 V_100 , V_101 , V_102 , V_103 ;
const char * V_104 ;
int V_7 ;
V_7 = F_16 ( & V_40 -> V_4 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
F_5 ( V_3 , V_16 , V_17 ) ;
V_100 = F_8 ( V_3 , V_105 ) ;
V_101 = F_8 ( V_3 , V_106 ) ;
V_102 = F_8 ( V_3 , V_107 ) ;
V_103 = F_8 ( V_3 , V_108 ) ;
switch ( F_30 ( V_100 , V_101 ) ) {
case V_109 :
V_104 = L_14 ;
break;
default:
F_24 ( & V_3 -> V_10 ,
L_15 , V_100 , V_101 ) ;
V_7 = - V_110 ;
goto V_111;
}
F_31 ( & V_3 -> V_10 ,
L_16 ,
V_104 , V_100 , V_101 , V_102 , V_103 ) ;
V_7 = F_32 ( & V_40 -> V_28 ) ;
V_111:
F_16 ( & V_40 -> V_4 , 0 ) ;
return V_7 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_1 * V_40 )
{
int V_7 ;
V_40 -> V_42 = F_34 ( & V_3 -> V_10 , L_17 ,
V_112 ) ;
if ( ! V_40 -> V_42 )
F_11 ( & V_3 -> V_10 , L_18 ) ;
V_7 = F_35 ( V_40 -> V_42 ) ;
if ( V_7 && V_7 != - V_113 ) {
F_11 ( & V_3 -> V_10 ,
L_19 , V_7 ) ;
return V_7 ;
}
V_40 -> V_41 = F_34 ( & V_3 -> V_10 , L_20 ,
V_114 ) ;
if ( ! V_40 -> V_41 )
F_11 ( & V_3 -> V_10 , L_21 ) ;
V_7 = F_35 ( V_40 -> V_41 ) ;
if ( V_7 && V_7 != - V_113 ) {
F_11 ( & V_3 -> V_10 ,
L_22 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_36 ( struct V_2 * V_3 ,
const struct V_115 * V_116 )
{
struct V_1 * V_40 ;
struct V_117 * V_118 = F_37 ( V_3 -> V_10 . V_119 ) ;
int V_7 ;
if ( ! F_38 ( V_118 , V_120 ) ) {
F_24 ( & V_118 -> V_10 ,
L_23 ) ;
return - V_121 ;
}
V_40 = F_39 ( & V_3 -> V_10 , sizeof( struct V_1 ) , V_122 ) ;
if ( ! V_40 ) {
F_24 ( & V_118 -> V_10 ,
L_24 ) ;
return - V_123 ;
}
if ( V_3 -> V_10 . V_124 ) {
V_40 -> V_125 = F_40 ( & V_3 -> V_10 , L_25 ) ;
if ( F_41 ( V_40 -> V_125 ) )
return - V_126 ;
F_42 ( V_40 -> V_125 ) ;
}
V_7 = F_33 ( V_3 , V_40 ) ;
if ( V_7 )
goto V_127;
F_43 ( & V_40 -> V_4 , V_3 , & V_128 ) ;
V_40 -> V_4 . V_129 = V_130 ;
F_44 ( & V_40 -> V_28 , 2 ) ;
F_45 ( & V_40 -> V_28 , & V_131 ,
V_30 , 0 , 1 , 1 , 0 ) ;
F_45 ( & V_40 -> V_28 , & V_131 ,
V_34 , 0 , 1 , 1 , 0 ) ;
V_40 -> V_4 . V_132 = & V_40 -> V_28 ;
if ( V_40 -> V_28 . error ) {
V_7 = V_40 -> V_28 . error ;
goto V_133;
}
#if F_46 ( V_134 )
V_40 -> V_76 . V_129 = V_135 ;
V_40 -> V_4 . V_136 . V_137 = V_138 ;
V_7 = F_47 ( & V_40 -> V_4 . V_136 , 1 , & V_40 -> V_76 ) ;
if ( V_7 < 0 )
goto V_133;
#endif
V_7 = F_29 ( V_3 ) ;
if ( V_7 < 0 )
goto V_139;
V_7 = F_48 ( & V_40 -> V_4 ) ;
if ( V_7 < 0 )
goto V_139;
F_31 ( & V_118 -> V_10 , L_26 ) ;
return 0 ;
V_139:
#if F_46 ( V_134 )
F_49 ( & V_40 -> V_4 . V_136 ) ;
#endif
V_133:
F_50 ( & V_40 -> V_28 ) ;
V_127:
F_51 ( V_40 -> V_125 ) ;
return V_7 ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
F_53 ( & V_40 -> V_4 ) ;
F_50 ( & V_40 -> V_28 ) ;
#if F_46 ( V_134 )
F_49 ( & V_40 -> V_4 . V_136 ) ;
#endif
F_54 ( & V_40 -> V_4 ) ;
F_51 ( V_40 -> V_125 ) ;
return 0 ;
}
