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
struct V_67 * V_68 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_1 * V_42 = F_1 ( V_3 ) ;
if ( ! V_42 -> V_52 ) {
T_3 V_45 = V_69 , V_46 = V_70 ;
V_42 -> V_52 = F_20 ( & V_45 , & V_46 ) ;
V_42 -> V_53 = V_60 ;
}
V_68 -> V_45 = V_42 -> V_52 -> V_45 ;
V_68 -> V_46 = V_42 -> V_52 -> V_46 ;
V_68 -> V_50 = V_42 -> V_53 ;
switch ( V_68 -> V_50 ) {
case V_54 :
case V_56 :
V_68 -> V_71 = V_72 ;
break;
default:
case V_58 :
case V_60 :
V_68 -> V_71 = V_73 ;
}
V_68 -> V_74 = V_75 ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 ,
struct V_67 * V_68 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
int V_7 ;
switch ( V_68 -> V_50 ) {
case V_54 :
case V_56 :
V_68 -> V_71 = V_72 ;
break;
default:
V_68 -> V_50 = V_60 ;
case V_58 :
case V_60 :
V_68 -> V_71 = V_73 ;
}
V_7 = F_22 ( V_3 , & V_68 -> V_45 , & V_68 -> V_46 , V_68 -> V_50 ) ;
return V_7 ;
}
static int F_26 ( struct V_23 * V_24 ,
struct V_67 * V_68 )
{
F_20 ( & V_68 -> V_45 , & V_68 -> V_46 ) ;
V_68 -> V_74 = V_75 ;
switch ( V_68 -> V_50 ) {
case V_54 :
case V_56 :
V_68 -> V_71 = V_72 ;
break;
default:
V_68 -> V_50 = V_60 ;
case V_58 :
case V_60 :
V_68 -> V_71 = V_73 ;
}
return 0 ;
}
static int F_27 ( struct V_23 * V_24 , unsigned int V_76 ,
T_3 * V_50 )
{
if ( V_76 >= F_21 ( V_77 ) )
return - V_36 ;
* V_50 = V_77 [ V_76 ] ;
return 0 ;
}
static int F_28 ( struct V_23 * V_24 , struct V_78 * V_79 )
{
V_79 -> V_80 . V_81 = 0 ;
V_79 -> V_80 . V_82 = 0 ;
V_79 -> V_80 . V_45 = V_83 ;
V_79 -> V_80 . V_46 = V_84 ;
V_79 -> type = V_85 ;
return 0 ;
}
static int F_29 ( struct V_23 * V_24 , struct V_86 * V_79 )
{
V_79 -> V_87 . V_81 = 0 ;
V_79 -> V_87 . V_82 = 0 ;
V_79 -> V_87 . V_45 = V_83 ;
V_79 -> V_87 . V_46 = V_84 ;
V_79 -> V_88 = V_79 -> V_87 ;
V_79 -> type = V_85 ;
V_79 -> V_89 . V_90 = 1 ;
V_79 -> V_89 . V_91 = 1 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
T_1 V_92 , V_93 , V_94 , V_95 ;
const char * V_96 ;
int V_7 ;
V_7 = F_17 ( & V_42 -> V_4 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
F_5 ( V_3 , V_16 , V_17 ) ;
V_92 = F_8 ( V_3 , V_97 ) ;
V_93 = F_8 ( V_3 , V_98 ) ;
V_94 = F_8 ( V_3 , V_99 ) ;
V_95 = F_8 ( V_3 , V_100 ) ;
switch ( F_31 ( V_92 , V_93 ) ) {
case V_101 :
V_96 = L_12 ;
break;
default:
F_23 ( & V_3 -> V_10 ,
L_13 , V_92 , V_93 ) ;
V_7 = - V_102 ;
goto V_103;
}
F_32 ( & V_3 -> V_10 ,
L_14 ,
V_96 , V_92 , V_93 , V_94 , V_95 ) ;
V_7 = F_33 ( & V_42 -> V_29 ) ;
V_103:
F_17 ( & V_42 -> V_4 , 0 ) ;
return V_7 ;
}
static int F_34 ( struct V_23 * V_24 ,
struct V_104 * V_105 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_40 * V_41 = F_18 ( V_3 ) ;
V_105 -> V_106 = V_107 | V_108 |
V_109 | V_110 |
V_111 ;
V_105 -> type = V_112 ;
V_105 -> V_106 = F_35 ( V_41 , V_105 ) ;
return 0 ;
}
static int F_36 ( struct V_113 * V_10 , int V_39 )
{
struct V_2 * V_3 = F_37 ( V_10 ) ;
struct V_1 * V_42 = F_1 ( V_3 ) ;
F_11 ( & V_3 -> V_10 , L_15 ,
V_22 , V_39 ? L_16 : L_17 ) ;
if ( V_42 -> V_114 )
F_38 ( V_42 -> V_114 , ! V_39 ) ;
return 0 ;
}
static int F_39 ( struct V_113 * V_10 )
{
struct V_2 * V_3 = F_37 ( V_10 ) ;
struct V_1 * V_42 = F_1 ( V_3 ) ;
if ( V_42 -> V_115 ) {
F_38 ( V_42 -> V_115 , 1 ) ;
F_40 ( 3000 , 5000 ) ;
F_38 ( V_42 -> V_115 , 0 ) ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_1 * V_42 )
{
V_42 -> V_115 = F_42 ( & V_3 -> V_10 , L_18 ,
V_116 ) ;
if ( ! V_42 -> V_115 )
F_11 ( & V_3 -> V_10 , L_19 ) ;
else if ( F_43 ( V_42 -> V_115 ) )
return F_44 ( V_42 -> V_115 ) ;
V_42 -> V_114 = F_42 ( & V_3 -> V_10 , L_20 ,
V_117 ) ;
if ( ! V_42 -> V_114 )
F_11 ( & V_3 -> V_10 , L_21 ) ;
else if ( F_43 ( V_42 -> V_114 ) )
return F_44 ( V_42 -> V_114 ) ;
V_42 -> V_118 . V_119 = F_36 ;
V_42 -> V_118 . V_120 = F_39 ;
V_3 -> V_10 . V_121 = & V_42 -> V_118 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 ,
const struct V_122 * V_123 )
{
struct V_1 * V_42 ;
struct V_40 * V_41 = F_18 ( V_3 ) ;
struct V_124 * V_125 = F_46 ( V_3 -> V_10 . V_126 ) ;
int V_7 ;
if ( ! F_47 ( V_125 , V_127 ) ) {
F_23 ( & V_125 -> V_10 ,
L_22 ) ;
return - V_128 ;
}
V_42 = F_48 ( & V_3 -> V_10 , sizeof( struct V_1 ) , V_129 ) ;
if ( ! V_42 ) {
F_23 ( & V_125 -> V_10 ,
L_23 ) ;
return - V_130 ;
}
V_42 -> V_43 = F_49 ( & V_3 -> V_10 , L_24 ) ;
if ( F_43 ( V_42 -> V_43 ) )
return - V_131 ;
if ( ! V_41 && ! V_3 -> V_10 . V_132 ) {
F_23 ( & V_3 -> V_10 , L_25 ) ;
V_7 = - V_36 ;
goto V_133;
}
if ( ! V_41 ) {
V_7 = F_41 ( V_3 , V_42 ) ;
if ( V_7 )
goto V_133;
}
F_50 ( & V_42 -> V_4 , V_3 , & V_134 ) ;
F_51 ( & V_42 -> V_29 , 2 ) ;
F_52 ( & V_42 -> V_29 , & V_135 ,
V_31 , 0 , 1 , 1 , 0 ) ;
F_52 ( & V_42 -> V_29 , & V_135 ,
V_34 , 0 , 1 , 1 , 0 ) ;
V_42 -> V_4 . V_136 = & V_42 -> V_29 ;
if ( V_42 -> V_29 . error ) {
V_7 = V_42 -> V_29 . error ;
goto V_133;
}
V_7 = F_30 ( V_3 ) ;
if ( V_7 < 0 )
goto V_137;
V_7 = F_53 ( & V_42 -> V_4 ) ;
if ( V_7 < 0 )
goto V_137;
F_32 ( & V_125 -> V_10 , L_26 ) ;
return 0 ;
V_137:
F_54 ( & V_42 -> V_29 ) ;
V_133:
F_55 ( V_42 -> V_43 ) ;
return V_7 ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
F_57 ( & V_42 -> V_4 ) ;
F_55 ( V_42 -> V_43 ) ;
F_58 ( & V_42 -> V_4 ) ;
F_54 ( & V_42 -> V_29 ) ;
return 0 ;
}
