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
static int F_13 ( struct V_26 * V_27 ,
unsigned long V_28 )
{
struct V_29 * V_30 = F_14 ( V_27 ) ;
unsigned long V_31 = V_28 & V_32 ;
if ( ! F_15 ( V_31 ) )
return - V_33 ;
if ( V_30 -> V_34 )
return V_30 -> V_34 ( V_30 , V_31 ) ;
if ( V_31 & ( V_35 | V_36 ) )
return 0 ;
return 0 ;
}
static unsigned long F_16 ( struct V_26 * V_27 )
{
struct V_29 * V_30 = F_14 ( V_27 ) ;
unsigned long V_28 = V_37 | V_38 |
V_39 | V_40 |
V_41 ;
if ( V_30 -> V_42 )
V_28 |= V_30 -> V_42 ( V_30 ) & V_32 ;
else
V_28 |= V_35 ;
return F_17 ( V_30 , V_28 ) ;
}
static int F_18 ( struct V_23 * V_24 , struct V_43 * V_44 )
{
struct V_2 * V_3 = F_19 ( V_24 ) ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
switch ( V_44 -> V_46 ) {
case V_47 :
V_44 -> V_9 = V_45 -> V_48 ;
break;
case V_49 :
V_44 -> V_9 = V_45 -> V_50 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_23 * V_24 , struct V_43 * V_44 )
{
struct V_2 * V_3 = F_19 ( V_24 ) ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
int V_7 = 0 ;
T_1 V_14 ;
switch ( V_44 -> V_46 ) {
case V_47 :
V_14 = V_44 -> V_9 ? V_51 : 0x00 ;
V_45 -> V_48 = V_44 -> V_9 ? 1 : 0 ;
V_7 = F_7 ( V_3 , V_52 , V_51 , V_14 ) ;
break;
case V_49 :
V_14 = V_44 -> V_9 ? V_53 : 0x00 ;
V_45 -> V_50 = V_44 -> V_9 ? 1 : 0 ;
V_7 = F_7 ( V_3 , V_52 , V_53 , V_14 ) ;
break;
}
return V_7 ;
}
static int F_21 ( struct V_23 * V_24 ,
struct V_54 * V_46 )
{
struct V_2 * V_3 = F_19 ( V_24 ) ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
V_46 -> V_55 = V_45 -> V_56 ;
V_46 -> V_57 = 0 ;
return 0 ;
}
static int F_22 ( struct V_23 * V_24 ,
struct V_58 * V_11 )
{
struct V_2 * V_3 = F_19 ( V_24 ) ;
int V_7 ;
V_11 -> V_59 = 1 ;
if ( V_11 -> V_11 > 0xff )
return - V_33 ;
V_7 = F_8 ( V_3 , V_11 -> V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
V_11 -> V_14 = V_7 ;
return 0 ;
}
static int F_23 ( struct V_23 * V_24 ,
struct V_58 * V_11 )
{
struct V_2 * V_3 = F_19 ( V_24 ) ;
if ( V_11 -> V_11 > 0xff ||
V_11 -> V_14 > 0xff )
return - V_33 ;
return F_5 ( V_3 , V_11 -> V_11 , V_11 -> V_14 ) ;
}
static const struct V_60 * F_24 ( T_3 * V_61 , T_3 * V_62 )
{
int V_63 , V_64 = F_25 ( V_65 ) - 1 ;
for ( V_63 = 0 ; V_63 < F_25 ( V_65 ) ; V_63 ++ ) {
if ( V_65 [ V_63 ] . V_61 >= * V_61 &&
V_65 [ V_63 ] . V_62 >= * V_62 ) {
* V_61 = V_65 [ V_63 ] . V_61 ;
* V_62 = V_65 [ V_63 ] . V_62 ;
return & V_65 [ V_63 ] ;
}
}
* V_61 = V_65 [ V_64 ] . V_61 ;
* V_62 = V_65 [ V_64 ] . V_62 ;
return & V_65 [ V_64 ] ;
}
static int F_26 ( struct V_2 * V_3 , T_3 * V_61 , T_3 * V_62 ,
enum V_66 V_67 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
const struct V_5 * V_68 ;
int V_7 ;
V_45 -> V_69 = F_24 ( V_61 , V_62 ) ;
V_45 -> V_70 = 0 ;
switch ( V_67 ) {
case V_71 :
F_11 ( & V_3 -> V_10 , L_4 , V_22 ) ;
V_68 = V_72 ;
break;
default:
case V_73 :
F_11 ( & V_3 -> V_10 , L_5 , V_22 ) ;
V_68 = V_74 ;
}
F_9 ( V_3 ) ;
F_11 ( & V_3 -> V_10 , L_6 , V_22 ) ;
V_7 = F_4 ( V_3 , V_75 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_7 , V_22 , V_45 -> V_69 -> V_76 ) ;
V_7 = F_4 ( V_3 , V_77 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_45 -> V_69 -> V_78 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_8 , V_22 ) ;
V_7 = F_4 ( V_3 , V_79 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_68 ) ;
if ( V_7 < 0 )
goto V_21;
V_45 -> V_70 = V_67 ;
* V_61 = V_45 -> V_69 -> V_61 ;
* V_62 = V_45 -> V_69 -> V_62 ;
return 0 ;
V_21:
F_27 ( & V_3 -> V_10 , L_9 , V_22 , V_7 ) ;
F_9 ( V_3 ) ;
V_45 -> V_69 = NULL ;
return V_7 ;
}
static int F_28 ( struct V_23 * V_24 ,
struct V_80 * V_81 )
{
struct V_2 * V_3 = F_19 ( V_24 ) ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
if ( ! V_45 -> V_69 ) {
T_3 V_61 = V_82 , V_62 = V_83 ;
int V_7 = F_26 ( V_3 , & V_61 , & V_62 ,
V_73 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_81 -> V_61 = V_45 -> V_69 -> V_61 ;
V_81 -> V_62 = V_45 -> V_69 -> V_62 ;
V_81 -> V_67 = V_45 -> V_70 ;
switch ( V_81 -> V_67 ) {
case V_71 :
V_81 -> V_84 = V_85 ;
break;
default:
case V_73 :
V_81 -> V_84 = V_86 ;
}
V_81 -> V_87 = V_88 ;
return 0 ;
}
static int F_29 ( struct V_23 * V_24 ,
struct V_80 * V_81 )
{
struct V_2 * V_3 = F_19 ( V_24 ) ;
int V_7 ;
switch ( V_81 -> V_67 ) {
case V_71 :
V_81 -> V_84 = V_85 ;
break;
default:
V_81 -> V_67 = V_73 ;
case V_73 :
V_81 -> V_84 = V_86 ;
}
V_7 = F_26 ( V_3 , & V_81 -> V_61 , & V_81 -> V_62 , V_81 -> V_67 ) ;
return V_7 ;
}
static int F_30 ( struct V_23 * V_24 ,
struct V_80 * V_81 )
{
const struct V_60 * V_69 ;
V_69 = F_24 ( & V_81 -> V_61 , & V_81 -> V_62 ) ;
V_81 -> V_87 = V_88 ;
switch ( V_81 -> V_67 ) {
case V_71 :
V_81 -> V_84 = V_85 ;
break;
default:
V_81 -> V_67 = V_73 ;
case V_73 :
V_81 -> V_84 = V_86 ;
}
return 0 ;
}
static int F_31 ( struct V_23 * V_24 , unsigned int V_89 ,
enum V_66 * V_67 )
{
if ( V_89 >= F_25 ( V_90 ) )
return - V_33 ;
* V_67 = V_90 [ V_89 ] ;
return 0 ;
}
static int F_32 ( struct V_23 * V_24 , struct V_91 * V_92 )
{
V_92 -> V_93 . V_94 = 0 ;
V_92 -> V_93 . V_95 = 0 ;
V_92 -> V_93 . V_61 = V_96 ;
V_92 -> V_93 . V_62 = V_97 ;
V_92 -> type = V_98 ;
return 0 ;
}
static int F_33 ( struct V_23 * V_24 , struct V_99 * V_92 )
{
V_92 -> V_100 . V_94 = 0 ;
V_92 -> V_100 . V_95 = 0 ;
V_92 -> V_100 . V_61 = V_96 ;
V_92 -> V_100 . V_62 = V_97 ;
V_92 -> V_101 = V_92 -> V_100 ;
V_92 -> type = V_98 ;
V_92 -> V_102 . V_103 = 1 ;
V_92 -> V_102 . V_104 = 1 ;
return 0 ;
}
static int F_34 ( struct V_26 * V_27 ,
struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_1 V_105 , V_106 , V_107 , V_108 ;
const char * V_109 ;
int V_7 ;
F_35 ( ! V_27 -> V_110 ||
F_36 ( V_27 -> V_110 ) -> V_111 != V_27 -> V_112 ) ;
F_5 ( V_3 , V_16 , V_17 ) ;
V_105 = F_8 ( V_3 , V_113 ) ;
V_106 = F_8 ( V_3 , V_114 ) ;
V_107 = F_8 ( V_3 , V_115 ) ;
V_108 = F_8 ( V_3 , V_116 ) ;
switch ( F_37 ( V_105 , V_106 ) ) {
case V_117 :
V_109 = L_10 ;
V_45 -> V_56 = V_118 ;
break;
default:
F_27 ( & V_3 -> V_10 ,
L_11 , V_105 , V_106 ) ;
V_7 = - V_119 ;
goto V_21;
}
F_38 ( & V_3 -> V_10 ,
L_12 ,
V_109 , V_105 , V_106 , V_107 , V_108 ) ;
return 0 ;
V_21:
return V_7 ;
}
static int F_39 ( struct V_2 * V_3 ,
const struct V_120 * V_121 )
{
struct V_1 * V_45 ;
struct V_26 * V_27 = V_3 -> V_10 . V_122 ;
struct V_123 * V_124 = F_40 ( V_3 -> V_10 . V_110 ) ;
struct V_29 * V_30 ;
int V_7 ;
if ( ! V_27 ) {
F_27 ( & V_124 -> V_10 , L_13 ) ;
return - V_33 ;
}
V_30 = F_14 ( V_27 ) ;
if ( ! V_30 ) {
F_27 ( & V_124 -> V_10 ,
L_14 ) ;
return - V_33 ;
}
if ( ! F_41 ( V_124 , V_125 ) ) {
F_27 ( & V_124 -> V_10 ,
L_15 ) ;
return - V_126 ;
}
V_45 = F_42 ( sizeof( struct V_1 ) , V_127 ) ;
if ( ! V_45 ) {
F_27 ( & V_124 -> V_10 ,
L_16 ) ;
return - V_128 ;
}
V_45 -> V_129 = V_30 -> V_45 ;
F_43 ( & V_45 -> V_4 , V_3 , & V_130 ) ;
V_27 -> V_131 = & V_132 ;
V_7 = F_34 ( V_27 , V_3 ) ;
if ( V_7 ) {
V_27 -> V_131 = NULL ;
F_44 ( V_45 ) ;
} else {
F_38 ( & V_124 -> V_10 , L_17 ) ;
}
return V_7 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_26 * V_27 = V_3 -> V_10 . V_122 ;
V_27 -> V_131 = NULL ;
F_44 ( V_45 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
return F_47 ( & V_133 ) ;
}
static void T_5 F_48 ( void )
{
F_49 ( & V_133 ) ;
}
