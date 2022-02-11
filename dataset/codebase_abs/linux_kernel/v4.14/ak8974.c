static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 * V_3 )
{
int V_4 ;
T_3 V_5 ;
V_4 = F_2 ( V_1 -> V_6 , V_2 , & V_5 , 2 ) ;
if ( V_4 )
return V_4 ;
* V_3 = F_3 ( V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
T_3 V_5 = F_5 ( V_3 ) ;
return F_6 ( V_1 -> V_6 , V_2 , & V_5 , 2 ) ;
}
static int F_7 ( struct V_1 * V_1 , bool V_7 )
{
int V_4 ;
T_1 V_3 ;
V_3 = V_7 ? V_8 : 0 ;
V_3 |= V_9 ;
V_4 = F_8 ( V_1 -> V_6 , V_10 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_7 )
F_9 ( V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
int V_4 ;
V_4 = F_7 ( V_1 , V_12 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_8 ( V_1 -> V_6 , V_13 , V_14 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_8 ( V_1 -> V_6 , V_15 , V_16 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_8 ( V_1 -> V_6 , V_17 ,
V_18 ) ;
if ( V_4 )
return V_4 ;
return F_7 ( V_1 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
int V_4 ;
V_4 = F_8 ( V_1 -> V_6 , V_13 , V_20 |
V_21 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_8 ( V_1 -> V_6 , V_15 , 0 ) ;
if ( V_4 )
return V_4 ;
if ( V_1 -> V_22 == V_23 ) {
V_4 = F_4 ( V_1 , V_24 , 0xA07E ) ;
if ( V_4 )
return V_4 ;
}
V_4 = F_8 ( V_1 -> V_6 , V_17 , V_25 ) ;
if ( V_4 )
return V_4 ;
return F_8 ( V_1 -> V_6 , V_26 , 0 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
unsigned int V_27 ;
T_1 V_28 ;
T_1 V_3 ;
int V_4 ;
V_4 = F_13 ( V_1 -> V_6 , V_29 , & V_27 ) ;
if ( V_4 )
return V_4 ;
if ( V_1 -> V_30 ) {
V_28 = V_21 |
V_20 |
V_31 ;
V_3 = V_20 ;
if ( ! V_1 -> V_32 )
V_3 |= V_31 ;
F_14 ( & V_1 -> V_33 ) ;
V_4 = F_15 ( V_1 -> V_6 , V_13 ,
V_28 , V_3 ) ;
if ( V_4 )
return V_4 ;
}
return F_15 ( V_1 -> V_6 ,
V_15 ,
V_34 ,
V_34 ) ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_35 = 2 ;
unsigned int V_3 ;
int V_4 ;
if ( V_1 -> V_30 ) {
V_4 = F_17 ( & V_1 -> V_33 ,
1 + F_18 ( 1000 ) ) ;
if ( ! V_4 ) {
F_19 ( & V_1 -> V_36 -> V_37 ,
L_1 ) ;
return - V_38 ;
}
return 0 ;
}
do {
F_9 ( V_39 ) ;
V_4 = F_13 ( V_1 -> V_6 , V_40 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_3 & V_41 )
return 0 ;
} while ( -- V_35 );
F_19 ( & V_1 -> V_36 -> V_37 , L_2 ) ;
return - V_38 ;
}
static int F_20 ( struct V_1 * V_1 , T_3 * V_42 )
{
unsigned int V_43 ;
int V_4 ;
V_4 = F_16 ( V_1 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_13 ( V_1 -> V_6 , V_44 , & V_43 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_43 & V_45 ) {
F_19 ( & V_1 -> V_36 -> V_37 ,
L_3 ) ;
return - V_46 ;
}
V_4 = F_2 ( V_1 -> V_6 , V_47 , V_42 , 6 ) ;
if ( V_4 )
return V_4 ;
return V_4 ;
}
static T_4 F_21 ( int V_48 , void * V_49 )
{
struct V_1 * V_1 = V_49 ;
if ( ! V_1 -> V_30 )
return V_50 ;
return V_51 ;
}
static T_4 F_22 ( int V_48 , void * V_49 )
{
struct V_1 * V_1 = V_49 ;
unsigned int V_3 ;
int V_4 ;
V_4 = F_13 ( V_1 -> V_6 , V_40 , & V_3 ) ;
if ( V_4 < 0 ) {
F_19 ( & V_1 -> V_36 -> V_37 , L_4 ) ;
return V_52 ;
}
if ( V_3 & V_41 ) {
F_23 ( & V_1 -> V_33 ) ;
return V_52 ;
}
return V_50 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_53 * V_37 = & V_1 -> V_36 -> V_37 ;
unsigned int V_3 ;
int V_4 ;
V_4 = F_13 ( V_1 -> V_6 , V_54 , & V_3 ) ;
if ( V_4 )
return V_4 ;
if ( V_3 != V_55 ) {
F_19 ( V_37 , L_5 ) ;
return - V_56 ;
}
V_4 = F_15 ( V_1 -> V_6 ,
V_15 ,
V_57 ,
V_57 ) ;
if ( V_4 ) {
F_19 ( V_37 , L_6 ) ;
return V_4 ;
}
F_9 ( V_58 ) ;
V_4 = F_13 ( V_1 -> V_6 , V_54 , & V_3 ) ;
if ( V_4 )
return V_4 ;
if ( V_3 != V_59 ) {
F_19 ( V_37 , L_7 , V_3 ) ;
return - V_56 ;
}
V_4 = F_13 ( V_1 -> V_6 , V_54 , & V_3 ) ;
if ( V_4 )
return V_4 ;
if ( V_3 != V_55 ) {
F_19 ( V_37 , L_8 , V_3 ) ;
return - V_56 ;
}
F_25 ( V_37 , L_9 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_1 , unsigned int V_2 ,
T_3 * V_60 , T_5 V_61 )
{
int V_4 = F_2 ( V_1 -> V_6 , V_2 , V_60 , V_61 ) ;
if ( V_4 ) {
memset ( V_60 , 0xFF , V_61 ) ;
F_27 ( & V_1 -> V_36 -> V_37 ,
L_10 ,
V_2 , V_2 + V_61 - 1 , V_4 ) ;
} else {
F_28 ( V_60 , V_61 ) ;
}
}
static int F_29 ( struct V_1 * V_1 )
{
unsigned int V_62 ;
const char * V_63 ;
int V_4 ;
unsigned int V_64 ;
T_2 V_65 ;
V_4 = F_13 ( V_1 -> V_6 , V_66 , & V_62 ) ;
if ( V_4 )
return V_4 ;
V_63 = L_11 ;
switch ( V_62 ) {
case V_23 :
V_63 = L_12 ;
case V_67 :
V_4 = F_13 ( V_1 -> V_6 , V_68 , & V_64 ) ;
if ( V_4 )
return V_4 ;
V_64 &= 0x7f ;
V_4 = F_1 ( V_1 , V_69 , & V_65 ) ;
if ( V_4 )
return V_4 ;
F_28 ( & V_65 , sizeof( V_65 ) ) ;
F_30 ( & V_1 -> V_36 -> V_37 ,
L_13 ,
V_63 , V_64 , V_65 ) ;
break;
case V_70 :
V_63 = L_14 ;
F_30 ( & V_1 -> V_36 -> V_37 , L_15 ) ;
break;
default:
F_19 ( & V_1 -> V_36 -> V_37 , L_16 ,
V_62 ) ;
return - V_71 ;
}
V_1 -> V_63 = V_63 ;
V_1 -> V_22 = V_62 ;
if ( V_62 == V_23 ) {
T_3 V_72 [ 9 ] , V_73 [ 3 ] ;
int V_74 ;
F_26 ( V_1 , V_75 ,
V_72 , sizeof( V_72 ) ) ;
F_26 ( V_1 , V_76 ,
V_73 , sizeof( V_73 ) ) ;
for ( V_74 = 0 ; V_74 < 3 ; ++ V_74 ) {
static const char V_77 [ 3 ] = L_17 ;
static const char V_78 [ 6 ] = L_18 ;
unsigned V_79 = F_3 ( V_73 [ V_74 ] ) & 0x7F ;
unsigned V_80 = F_3 ( V_72 [ V_74 ] ) ;
unsigned V_81 = F_3 ( V_72 [ V_74 + 3 ] ) ;
unsigned V_82 = F_3 ( V_72 [ V_74 + 6 ] ) ;
unsigned V_83 = V_82 >> 8 ;
V_82 &= 0xFF ;
F_30 ( & V_1 -> V_36 -> V_37 ,
L_19 ,
V_77 [ V_74 ] , V_79 , V_81 , V_80 , V_78 [ V_74 * 2 ] ,
V_82 , V_78 [ V_74 * 2 + 1 ] , V_83 ) ;
}
}
return 0 ;
}
static int F_31 ( struct V_84 * V_85 ,
struct V_86 const * V_87 ,
int * V_3 , int * V_88 ,
long V_28 )
{
struct V_1 * V_1 = F_32 ( V_85 ) ;
T_3 V_89 [ 3 ] ;
int V_4 = - V_90 ;
F_33 ( & V_1 -> V_36 -> V_37 ) ;
F_34 ( & V_1 -> V_91 ) ;
switch ( V_28 ) {
case V_92 :
if ( V_87 -> V_93 > 2 ) {
F_19 ( & V_1 -> V_36 -> V_37 , L_20 ) ;
V_4 = - V_56 ;
goto V_94;
}
V_4 = F_12 ( V_1 ) ;
if ( V_4 )
goto V_94;
V_4 = F_20 ( V_1 , V_89 ) ;
if ( V_4 )
goto V_94;
* V_3 = F_3 ( V_89 [ V_87 -> V_93 ] ) ;
V_4 = V_95 ;
}
V_94:
F_35 ( & V_1 -> V_91 ) ;
F_36 ( & V_1 -> V_36 -> V_37 ) ;
F_37 ( & V_1 -> V_36 -> V_37 ) ;
return V_4 ;
}
static void F_38 ( struct V_84 * V_85 )
{
struct V_1 * V_1 = F_32 ( V_85 ) ;
int V_4 ;
T_3 V_89 [ 8 ] ;
F_33 ( & V_1 -> V_36 -> V_37 ) ;
F_34 ( & V_1 -> V_91 ) ;
V_4 = F_12 ( V_1 ) ;
if ( V_4 ) {
F_19 ( & V_1 -> V_36 -> V_37 , L_21 ) ;
goto V_94;
}
V_4 = F_20 ( V_1 , V_89 ) ;
if ( V_4 ) {
F_19 ( & V_1 -> V_36 -> V_37 , L_22 ) ;
goto V_94;
}
F_39 ( V_85 , V_89 ,
F_40 ( V_85 ) ) ;
V_94:
F_35 ( & V_1 -> V_91 ) ;
F_36 ( & V_1 -> V_36 -> V_37 ) ;
F_37 ( & V_1 -> V_36 -> V_37 ) ;
}
static T_4 F_41 ( int V_48 , void * V_96 )
{
const struct V_97 * V_98 = V_96 ;
struct V_84 * V_85 = V_98 -> V_85 ;
F_38 ( V_85 ) ;
F_42 ( V_85 -> V_99 ) ;
return V_52 ;
}
static const struct V_100 *
F_43 ( const struct V_84 * V_85 ,
const struct V_86 * V_87 )
{
struct V_1 * V_1 = F_32 ( V_85 ) ;
return & V_1 -> V_101 ;
}
static bool F_44 ( struct V_53 * V_37 , unsigned int V_2 )
{
struct V_102 * V_36 = F_45 ( V_37 ) ;
struct V_84 * V_85 = F_46 ( V_36 ) ;
struct V_1 * V_1 = F_32 ( V_85 ) ;
switch ( V_2 ) {
case V_10 :
case V_13 :
case V_15 :
case V_17 :
case V_103 :
case V_103 + 1 :
case V_26 :
case V_26 + 1 :
return true ;
case V_104 :
case V_104 + 1 :
case V_105 :
case V_105 + 1 :
case V_106 :
case V_106 + 1 :
if ( V_1 -> V_22 == V_70 )
return true ;
return false ;
case V_107 :
case V_107 + 1 :
case V_108 :
case V_108 + 1 :
case V_109 :
case V_109 + 1 :
return V_1 -> V_22 == V_67 ||
V_1 -> V_22 == V_23 ;
case V_24 :
case V_24 + 1 :
return V_1 -> V_22 == V_23 ;
default:
return false ;
}
}
static bool F_47 ( struct V_53 * V_37 , unsigned int V_2 )
{
return V_2 == V_29 ;
}
static int F_48 ( struct V_102 * V_36 ,
const struct V_110 * V_111 )
{
struct V_84 * V_85 ;
struct V_1 * V_1 ;
unsigned long V_112 ;
int V_48 = V_36 -> V_48 ;
int V_4 ;
V_85 = F_49 ( & V_36 -> V_37 , sizeof( * V_1 ) ) ;
if ( V_85 == NULL )
return - V_113 ;
V_1 = F_32 ( V_85 ) ;
F_50 ( V_36 , V_85 ) ;
V_1 -> V_36 = V_36 ;
F_51 ( & V_1 -> V_91 ) ;
V_4 = F_52 ( & V_36 -> V_37 ,
L_23 ,
& V_1 -> V_101 ) ;
if ( V_4 )
return V_4 ;
V_1 -> V_114 [ 0 ] . V_115 = V_116 ;
V_1 -> V_114 [ 1 ] . V_115 = V_117 ;
V_4 = F_53 ( & V_36 -> V_37 ,
F_54 ( V_1 -> V_114 ) ,
V_1 -> V_114 ) ;
if ( V_4 < 0 ) {
F_19 ( & V_36 -> V_37 , L_24 ) ;
return V_4 ;
}
V_4 = F_55 ( F_54 ( V_1 -> V_114 ) , V_1 -> V_114 ) ;
if ( V_4 < 0 ) {
F_19 ( & V_36 -> V_37 , L_25 ) ;
return V_4 ;
}
F_56 ( & V_36 -> V_37 ) ;
F_57 ( & V_36 -> V_37 ) ;
F_58 ( & V_36 -> V_37 ) ;
V_1 -> V_6 = F_59 ( V_36 , & V_118 ) ;
if ( F_60 ( V_1 -> V_6 ) ) {
F_19 ( & V_36 -> V_37 , L_26 ) ;
return F_61 ( V_1 -> V_6 ) ;
}
V_4 = F_7 ( V_1 , V_12 ) ;
if ( V_4 ) {
F_19 ( & V_36 -> V_37 , L_27 ) ;
goto V_119;
}
V_4 = F_29 ( V_1 ) ;
if ( V_4 ) {
F_19 ( & V_36 -> V_37 , L_28 ) ;
goto V_119;
}
V_4 = F_24 ( V_1 ) ;
if ( V_4 )
F_19 ( & V_36 -> V_37 , L_29 ) ;
V_4 = F_10 ( V_1 ) ;
if ( V_4 ) {
F_19 ( & V_36 -> V_37 , L_30 ) ;
goto V_119;
}
F_62 ( & V_36 -> V_37 ,
V_120 ) ;
F_63 ( & V_36 -> V_37 ) ;
F_64 ( & V_36 -> V_37 ) ;
V_85 -> V_37 . V_121 = & V_36 -> V_37 ;
V_85 -> V_122 = V_123 ;
V_85 -> V_124 = F_54 ( V_123 ) ;
V_85 -> V_125 = & V_126 ;
V_85 -> V_127 = V_128 ;
V_85 -> V_129 = V_130 ;
V_85 -> V_63 = V_1 -> V_63 ;
V_4 = F_65 ( V_85 , NULL ,
F_41 ,
NULL ) ;
if ( V_4 ) {
F_19 ( & V_36 -> V_37 , L_31 ) ;
goto V_131;
}
if ( V_48 > 0 ) {
V_112 = F_66 ( F_67 ( V_48 ) ) ;
if ( V_112 == V_132 ) {
F_30 ( & V_36 -> V_37 , L_32 ) ;
} else if ( V_112 == V_133 ) {
V_1 -> V_32 = true ;
F_30 ( & V_36 -> V_37 , L_33 ) ;
} else {
V_112 = V_132 ;
}
V_112 |= V_134 ;
V_112 |= V_135 ;
V_4 = F_68 ( & V_36 -> V_37 ,
V_48 ,
F_21 ,
F_22 ,
V_112 ,
V_1 -> V_63 ,
V_1 ) ;
if ( V_4 ) {
F_19 ( & V_36 -> V_37 , L_34
L_35 ) ;
goto V_136;
}
V_1 -> V_30 = true ;
}
V_136:
V_4 = F_69 ( V_85 ) ;
if ( V_4 ) {
F_19 ( & V_36 -> V_37 , L_36 ) ;
goto V_137;
}
return 0 ;
V_137:
F_70 ( V_85 ) ;
V_131:
F_71 ( & V_36 -> V_37 ) ;
F_72 ( & V_36 -> V_37 ) ;
F_7 ( V_1 , V_19 ) ;
V_119:
F_73 ( F_54 ( V_1 -> V_114 ) , V_1 -> V_114 ) ;
return V_4 ;
}
static int F_74 ( struct V_102 * V_36 )
{
struct V_84 * V_85 = F_46 ( V_36 ) ;
struct V_1 * V_1 = F_32 ( V_85 ) ;
F_75 ( V_85 ) ;
F_70 ( V_85 ) ;
F_33 ( & V_36 -> V_37 ) ;
F_71 ( & V_36 -> V_37 ) ;
F_72 ( & V_36 -> V_37 ) ;
F_7 ( V_1 , V_19 ) ;
F_73 ( F_54 ( V_1 -> V_114 ) , V_1 -> V_114 ) ;
return 0 ;
}
static int T_6 F_76 ( struct V_53 * V_37 )
{
struct V_1 * V_1 =
F_32 ( F_46 ( F_45 ( V_37 ) ) ) ;
F_7 ( V_1 , V_19 ) ;
F_73 ( F_54 ( V_1 -> V_114 ) , V_1 -> V_114 ) ;
return 0 ;
}
static int T_6 F_77 ( struct V_53 * V_37 )
{
struct V_1 * V_1 =
F_32 ( F_46 ( F_45 ( V_37 ) ) ) ;
int V_4 ;
V_4 = F_55 ( F_54 ( V_1 -> V_114 ) , V_1 -> V_114 ) ;
if ( V_4 )
return V_4 ;
F_9 ( V_138 ) ;
V_4 = F_7 ( V_1 , V_12 ) ;
if ( V_4 )
goto V_139;
V_4 = F_11 ( V_1 ) ;
if ( V_4 )
goto V_140;
return 0 ;
V_140:
F_7 ( V_1 , V_19 ) ;
V_139:
F_73 ( F_54 ( V_1 -> V_114 ) , V_1 -> V_114 ) ;
return V_4 ;
}
