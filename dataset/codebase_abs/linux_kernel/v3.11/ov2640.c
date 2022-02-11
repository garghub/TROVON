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
enum V_50 V_51 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
const struct V_5 * V_52 ;
int V_7 ;
V_42 -> V_53 = F_20 ( V_45 , V_46 ) ;
V_42 -> V_54 = 0 ;
switch ( V_51 ) {
case V_55 :
F_11 ( & V_3 -> V_10 , L_4 , V_22 ) ;
V_52 = V_56 ;
break;
case V_57 :
F_11 ( & V_3 -> V_10 , L_5 , V_22 ) ;
V_52 = V_58 ;
break;
case V_59 :
F_11 ( & V_3 -> V_10 , L_6 , V_22 ) ;
V_52 = V_60 ;
break;
default:
case V_61 :
F_11 ( & V_3 -> V_10 , L_7 , V_22 ) ;
V_52 = V_62 ;
}
F_9 ( V_3 ) ;
F_11 ( & V_3 -> V_10 , L_8 , V_22 ) ;
V_7 = F_4 ( V_3 , V_63 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_9 , V_22 , V_42 -> V_53 -> V_64 ) ;
V_7 = F_4 ( V_3 , V_65 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_42 -> V_53 -> V_66 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_10 , V_22 ) ;
V_7 = F_4 ( V_3 , V_67 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_52 ) ;
if ( V_7 < 0 )
goto V_21;
V_42 -> V_54 = V_51 ;
* V_45 = V_42 -> V_53 -> V_45 ;
* V_46 = V_42 -> V_53 -> V_46 ;
return 0 ;
V_21:
F_23 ( & V_3 -> V_10 , L_11 , V_22 , V_7 ) ;
F_9 ( V_3 ) ;
V_42 -> V_53 = NULL ;
return V_7 ;
}
static int F_24 ( struct V_23 * V_24 ,
struct V_68 * V_69 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_1 * V_42 = F_1 ( V_3 ) ;
if ( ! V_42 -> V_53 ) {
T_3 V_45 = V_70 , V_46 = V_71 ;
V_42 -> V_53 = F_20 ( & V_45 , & V_46 ) ;
V_42 -> V_54 = V_61 ;
}
V_69 -> V_45 = V_42 -> V_53 -> V_45 ;
V_69 -> V_46 = V_42 -> V_53 -> V_46 ;
V_69 -> V_51 = V_42 -> V_54 ;
switch ( V_69 -> V_51 ) {
case V_55 :
case V_57 :
V_69 -> V_72 = V_73 ;
break;
default:
case V_59 :
case V_61 :
V_69 -> V_72 = V_74 ;
}
V_69 -> V_75 = V_76 ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 ,
struct V_68 * V_69 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
int V_7 ;
switch ( V_69 -> V_51 ) {
case V_55 :
case V_57 :
V_69 -> V_72 = V_73 ;
break;
default:
V_69 -> V_51 = V_61 ;
case V_59 :
case V_61 :
V_69 -> V_72 = V_74 ;
}
V_7 = F_22 ( V_3 , & V_69 -> V_45 , & V_69 -> V_46 , V_69 -> V_51 ) ;
return V_7 ;
}
static int F_26 ( struct V_23 * V_24 ,
struct V_68 * V_69 )
{
F_20 ( & V_69 -> V_45 , & V_69 -> V_46 ) ;
V_69 -> V_75 = V_76 ;
switch ( V_69 -> V_51 ) {
case V_55 :
case V_57 :
V_69 -> V_72 = V_73 ;
break;
default:
V_69 -> V_51 = V_61 ;
case V_59 :
case V_61 :
V_69 -> V_72 = V_74 ;
}
return 0 ;
}
static int F_27 ( struct V_23 * V_24 , unsigned int V_77 ,
enum V_50 * V_51 )
{
if ( V_77 >= F_21 ( V_78 ) )
return - V_36 ;
* V_51 = V_78 [ V_77 ] ;
return 0 ;
}
static int F_28 ( struct V_23 * V_24 , struct V_79 * V_80 )
{
V_80 -> V_81 . V_82 = 0 ;
V_80 -> V_81 . V_83 = 0 ;
V_80 -> V_81 . V_45 = V_84 ;
V_80 -> V_81 . V_46 = V_85 ;
V_80 -> type = V_86 ;
return 0 ;
}
static int F_29 ( struct V_23 * V_24 , struct V_87 * V_80 )
{
V_80 -> V_88 . V_82 = 0 ;
V_80 -> V_88 . V_83 = 0 ;
V_80 -> V_88 . V_45 = V_84 ;
V_80 -> V_88 . V_46 = V_85 ;
V_80 -> V_89 = V_80 -> V_88 ;
V_80 -> type = V_86 ;
V_80 -> V_90 . V_91 = 1 ;
V_80 -> V_90 . V_92 = 1 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
T_1 V_93 , V_94 , V_95 , V_96 ;
const char * V_97 ;
int V_7 ;
V_7 = F_17 ( & V_42 -> V_4 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
F_5 ( V_3 , V_16 , V_17 ) ;
V_93 = F_8 ( V_3 , V_98 ) ;
V_94 = F_8 ( V_3 , V_99 ) ;
V_95 = F_8 ( V_3 , V_100 ) ;
V_96 = F_8 ( V_3 , V_101 ) ;
switch ( F_31 ( V_93 , V_94 ) ) {
case V_102 :
V_97 = L_12 ;
break;
default:
F_23 ( & V_3 -> V_10 ,
L_13 , V_93 , V_94 ) ;
V_7 = - V_103 ;
goto V_104;
}
F_32 ( & V_3 -> V_10 ,
L_14 ,
V_97 , V_93 , V_94 , V_95 , V_96 ) ;
V_7 = F_33 ( & V_42 -> V_29 ) ;
V_104:
F_17 ( & V_42 -> V_4 , 0 ) ;
return V_7 ;
}
static int F_34 ( struct V_23 * V_24 ,
struct V_105 * V_106 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_40 * V_41 = F_18 ( V_3 ) ;
V_106 -> V_107 = V_108 | V_109 |
V_110 | V_111 |
V_112 ;
V_106 -> type = V_113 ;
V_106 -> V_107 = F_35 ( V_41 , V_106 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 ,
const struct V_114 * V_115 )
{
struct V_1 * V_42 ;
struct V_40 * V_41 = F_18 ( V_3 ) ;
struct V_116 * V_117 = F_37 ( V_3 -> V_10 . V_118 ) ;
int V_7 ;
if ( ! V_41 ) {
F_23 ( & V_117 -> V_10 ,
L_15 ) ;
return - V_36 ;
}
if ( ! F_38 ( V_117 , V_119 ) ) {
F_23 ( & V_117 -> V_10 ,
L_16 ) ;
return - V_120 ;
}
V_42 = F_39 ( & V_3 -> V_10 , sizeof( struct V_1 ) , V_121 ) ;
if ( ! V_42 ) {
F_23 ( & V_117 -> V_10 ,
L_17 ) ;
return - V_122 ;
}
F_40 ( & V_42 -> V_4 , V_3 , & V_123 ) ;
F_41 ( & V_42 -> V_29 , 2 ) ;
F_42 ( & V_42 -> V_29 , & V_124 ,
V_31 , 0 , 1 , 1 , 0 ) ;
F_42 ( & V_42 -> V_29 , & V_124 ,
V_34 , 0 , 1 , 1 , 0 ) ;
V_42 -> V_4 . V_125 = & V_42 -> V_29 ;
if ( V_42 -> V_29 . error )
return V_42 -> V_29 . error ;
V_42 -> V_43 = F_43 ( & V_3 -> V_10 , L_18 ) ;
if ( F_44 ( V_42 -> V_43 ) ) {
V_7 = F_45 ( V_42 -> V_43 ) ;
goto V_126;
}
V_7 = F_30 ( V_3 ) ;
if ( V_7 ) {
F_46 ( V_42 -> V_43 ) ;
V_126:
F_47 ( & V_42 -> V_29 ) ;
} else {
F_32 ( & V_117 -> V_10 , L_19 ) ;
}
return V_7 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
F_46 ( V_42 -> V_43 ) ;
F_49 ( & V_42 -> V_4 ) ;
F_47 ( & V_42 -> V_29 ) ;
return 0 ;
}
