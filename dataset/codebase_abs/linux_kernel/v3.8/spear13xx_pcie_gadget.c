static void F_1 ( struct V_1 T_1 * V_2 )
{
F_2 ( F_3 ( & V_2 -> V_3 ) | ( 1 << V_4 ) ,
& V_2 -> V_3 ) ;
F_2 ( F_3 ( & V_2 -> V_5 ) | ( 1 << V_4 ) ,
& V_2 -> V_5 ) ;
}
static void F_4 ( struct V_1 T_1 * V_2 )
{
F_2 ( F_3 ( & V_2 -> V_3 ) & ~ ( 1 << V_4 ) ,
& V_2 -> V_3 ) ;
F_2 ( F_3 ( & V_2 -> V_5 ) & ~ ( 1 << V_4 ) ,
& V_2 -> V_5 ) ;
}
static void F_5 ( struct V_6 * V_7 ,
int V_8 , int V_9 , T_2 * V_10 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_3 V_12 ;
F_1 ( V_2 ) ;
V_12 = ( T_3 ) V_7 -> V_13 + ( V_8 & ~ 0x3 ) ;
* V_10 = F_3 ( V_12 ) ;
if ( V_9 == 1 )
* V_10 = ( * V_10 >> ( 8 * ( V_8 & 3 ) ) ) & 0xff ;
else if ( V_9 == 2 )
* V_10 = ( * V_10 >> ( 8 * ( V_8 & 3 ) ) ) & 0xffff ;
F_4 ( V_2 ) ;
}
static void F_6 ( struct V_6 * V_7 ,
int V_8 , int V_9 , T_2 V_10 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_3 V_12 ;
F_1 ( V_2 ) ;
V_12 = ( T_3 ) V_7 -> V_13 + ( V_8 & ~ 0x3 ) ;
if ( V_9 == 4 )
F_2 ( V_10 , V_12 ) ;
else if ( V_9 == 2 )
F_7 ( V_10 , V_12 + ( V_8 & 2 ) ) ;
else if ( V_9 == 1 )
F_8 ( V_10 , V_12 + ( V_8 & 3 ) ) ;
F_4 ( V_2 ) ;
}
static int F_9 ( struct V_6 * V_7 ,
T_2 V_14 , int V_15 , int * V_16 )
{
T_2 V_17 ;
while ( ( * V_16 ) -- ) {
F_5 ( V_7 , V_14 , 1 , & V_14 ) ;
if ( V_14 < 0x40 )
break;
V_14 &= ~ 3 ;
F_5 ( V_7 , V_14 + V_18 , 1 , & V_17 ) ;
if ( V_17 == 0xff )
break;
if ( V_17 == V_15 )
return V_14 ;
V_14 += V_19 ;
}
return 0 ;
}
static int F_10 ( struct V_6 * V_7 ,
T_2 V_14 , int V_15 )
{
int V_16 = V_20 ;
return F_9 ( V_7 , V_14 , V_15 , & V_16 ) ;
}
static int F_11 ( struct V_6 * V_7 ,
T_4 V_21 )
{
T_2 V_22 ;
F_5 ( V_7 , V_23 , 2 , & V_22 ) ;
if ( ! ( V_22 & V_24 ) )
return 0 ;
switch ( V_21 ) {
case V_25 :
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
default:
return 0 ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
int V_15 )
{
T_2 V_14 ;
T_2 V_21 ;
F_5 ( V_7 , V_30 , 1 , & V_21 ) ;
V_14 = F_11 ( V_7 , V_21 ) ;
if ( V_14 )
V_14 = F_10 ( V_7 , V_14 , V_15 ) ;
return V_14 ;
}
static T_5 F_13 ( int V_31 , void * V_32 )
{
return 0 ;
}
static T_6 F_14 (
struct V_6 * V_7 ,
char * V_33 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
if ( F_3 ( & V_2 -> V_34 ) & ( ( T_2 ) 1 << V_35 ) )
return sprintf ( V_33 , L_1 ) ;
else
return sprintf ( V_33 , L_2 ) ;
}
static T_6 F_15 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
if ( F_16 ( V_33 , L_1 ) )
F_2 ( F_3 ( & V_2 -> V_37 ) | ( 1 << V_38 ) ,
& V_2 -> V_37 ) ;
else if ( F_16 ( V_33 , L_2 ) )
F_2 ( F_3 ( & V_2 -> V_37 )
& ~ ( 1 << V_38 ) ,
& V_2 -> V_37 ) ;
else
return - V_39 ;
return V_36 ;
}
static T_6 F_17 (
struct V_6 * V_7 ,
char * V_33 )
{
return sprintf ( V_33 , L_3 , V_7 -> V_40 ) ;
}
static T_6 F_18 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
T_2 V_15 , V_41 , V_42 ;
T_3 V_43 ;
if ( F_16 ( V_33 , L_4 ) )
F_6 ( V_7 , V_44 , 1 , 1 ) ;
else if ( F_16 ( V_33 , L_5 ) ) {
V_43 = V_7 -> V_45 ;
V_41 = 0 ;
while ( V_43 > 1 ) {
V_43 /= 2 ;
V_41 ++ ;
}
F_6 ( V_7 , V_44 , 1 , 0 ) ;
V_15 = F_12 ( V_7 , V_46 ) ;
F_5 ( V_7 , V_15 + V_47 , 1 , & V_42 ) ;
V_42 &= ~ V_48 ;
V_42 |= V_41 << 1 ;
F_6 ( V_7 , V_15 + V_47 , 1 , V_42 ) ;
} else
return - V_39 ;
strcpy ( V_7 -> V_40 , V_33 ) ;
return V_36 ;
}
static T_6 F_19 (
struct V_6 * V_7 ,
char * V_33 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_2 V_15 , V_41 , V_42 ;
T_3 V_43 ;
if ( ( F_3 ( & V_2 -> V_49 ) & ( 1 << V_50 ) )
!= ( 1 << V_50 ) )
V_43 = 0 ;
else {
V_15 = F_12 ( V_7 , V_46 ) ;
F_5 ( V_7 , V_15 + V_47 , 1 , & V_42 ) ;
V_42 &= ~ V_51 ;
V_41 = V_42 >> 4 ;
V_43 = 1 ;
while ( V_41 -- )
V_43 *= 2 ;
}
V_7 -> V_52 = V_43 ;
return sprintf ( V_33 , L_6 , V_43 ) ;
}
static T_6 F_20 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
if ( F_21 ( V_33 , 0 , & V_7 -> V_45 ) )
return - V_39 ;
if ( V_7 -> V_45 > 32 )
V_7 -> V_45 = 32 ;
return V_36 ;
}
static T_6 F_22 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_3 V_53 ;
if ( F_21 ( V_33 , 0 , & V_53 ) )
return - V_39 ;
if ( V_53 )
F_2 ( F_3 ( & V_2 -> V_37 ) | ( 1 << V_54 ) ,
& V_2 -> V_37 ) ;
else
F_2 ( F_3 ( & V_2 -> V_37 ) & ~ ( 1 << V_54 ) ,
& V_2 -> V_37 ) ;
return V_36 ;
}
static T_6 F_23 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_3 V_43 ;
T_2 V_55 ;
if ( F_21 ( V_33 , 0 , & V_43 ) )
return - V_39 ;
if ( ! V_7 -> V_52 )
return - V_39 ;
if ( V_43 >= V_7 -> V_52 )
return - V_39 ;
V_55 = F_3 ( & V_2 -> V_56 ) ;
V_55 &= ~ V_57 ;
V_55 |= 0 << V_58 ;
V_55 &= ~ V_59 ;
V_55 |= 0 << V_60 ;
V_55 &= ~ V_61 ;
V_55 |= V_43 << V_62 ;
V_55 |= V_63 ;
F_2 ( V_55 , & V_2 -> V_56 ) ;
F_24 ( 1 ) ;
V_55 &= ~ V_63 ;
F_2 ( V_55 , & V_2 -> V_56 ) ;
return V_36 ;
}
static T_6 F_25 (
struct V_6 * V_7 ,
char * V_33 )
{
T_2 V_17 ;
F_5 ( V_7 , V_64 , 2 , & V_17 ) ;
return sprintf ( V_33 , L_7 , V_17 ) ;
}
static T_6 F_26 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
T_3 V_17 ;
if ( F_21 ( V_33 , 0 , & V_17 ) )
return - V_39 ;
F_6 ( V_7 , V_64 , 2 , V_17 ) ;
return V_36 ;
}
static T_6 F_27 (
struct V_6 * V_7 ,
char * V_33 )
{
T_2 V_17 ;
F_5 ( V_7 , V_65 , 2 , & V_17 ) ;
return sprintf ( V_33 , L_7 , V_17 ) ;
}
static T_6 F_28 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
T_3 V_17 ;
if ( F_21 ( V_33 , 0 , & V_17 ) )
return - V_39 ;
F_6 ( V_7 , V_65 , 2 , V_17 ) ;
return V_36 ;
}
static T_6 F_29 (
struct V_6 * V_7 ,
char * V_33 )
{
return sprintf ( V_33 , L_8 , V_7 -> V_66 ) ;
}
static T_6 F_30 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
T_3 V_9 ;
T_2 V_14 , V_67 ;
T_2 V_68 = 0 ;
if ( F_21 ( V_33 , 0 , & V_9 ) )
return - V_39 ;
if ( V_9 <= 0x100 )
V_9 = 0x100 ;
else if ( V_9 >= 0x100000 )
V_9 = 0x100000 ;
else {
V_14 = 0 ;
V_67 = 0 ;
while ( V_14 < 21 ) {
V_14 = F_31 ( ( T_3 * ) & V_9 , 21 , V_14 ) ;
if ( V_14 != 21 )
V_67 = V_14 + 1 ;
V_14 ++ ;
V_68 ++ ;
}
if ( V_68 == 2 )
V_67 -- ;
V_9 = 1 << V_67 ;
}
V_7 -> V_66 = V_9 ;
F_6 ( V_7 , V_69 , 4 , V_9 - 1 ) ;
return V_36 ;
}
static T_6 F_32 (
struct V_6 * V_7 ,
char * V_33 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_2 V_70 = F_3 ( & V_2 -> V_71 ) ;
return sprintf ( V_33 , L_7 , V_70 ) ;
}
static T_6 F_33 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_3 V_70 ;
if ( F_21 ( V_33 , 0 , & V_70 ) )
return - V_39 ;
V_70 &= ~ ( V_7 -> V_66 - 1 ) ;
if ( V_7 -> V_72 )
F_34 ( V_7 -> V_72 ) ;
V_7 -> V_72 = F_35 ( V_70 , V_7 -> V_66 ) ;
if ( ! V_7 -> V_72 )
return - V_73 ;
F_2 ( V_70 , & V_2 -> V_71 ) ;
return V_36 ;
}
static T_6 F_36 (
struct V_6 * V_7 ,
char * V_33 )
{
return sprintf ( V_33 , L_8 , V_7 -> V_74 ) ;
}
static T_6 F_37 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
T_3 V_75 ;
if ( F_21 ( V_33 , 0 , & V_75 ) )
return - V_39 ;
if ( V_75 % 4 )
return - V_39 ;
V_7 -> V_74 = V_75 ;
return V_36 ;
}
static T_6 F_38 (
struct V_6 * V_7 ,
char * V_33 )
{
T_3 V_76 ;
if ( ! V_7 -> V_72 )
return - V_73 ;
V_76 = F_3 ( ( T_3 ) V_7 -> V_72 + V_7 -> V_74 ) ;
return sprintf ( V_33 , L_8 , V_76 ) ;
}
static T_6 F_39 (
struct V_6 * V_7 ,
const char * V_33 , T_7 V_36 )
{
T_3 V_76 ;
if ( F_21 ( V_33 , 0 , & V_76 ) )
return - V_39 ;
if ( ! V_7 -> V_72 )
return - V_73 ;
F_2 ( V_76 , ( T_3 ) V_7 -> V_72 + V_7 -> V_74 ) ;
return V_36 ;
}
static struct V_77 * F_40 ( struct V_78 * V_79 )
{
return V_79 ?
F_41 ( F_42 ( F_43 ( V_79 ) ) ,
struct V_77 , V_80 ) : NULL ;
}
static T_6 F_44 ( struct V_78 * V_79 ,
struct V_81 * V_82 ,
char * V_33 )
{
T_6 V_83 = - V_39 ;
struct V_77 * V_84 = F_40 ( V_79 ) ;
struct V_85 * V_86 =
F_41 ( V_82 , struct V_85 , V_82 ) ;
if ( V_86 -> V_87 )
V_83 = V_86 -> V_87 ( & V_84 -> V_7 , V_33 ) ;
return V_83 ;
}
static T_6 F_45 ( struct V_78 * V_79 ,
struct V_81 * V_82 ,
const char * V_33 ,
T_7 V_36 )
{
T_6 V_83 = - V_39 ;
struct V_77 * V_84 = F_40 ( V_79 ) ;
struct V_85 * V_86 =
F_41 ( V_82 , struct V_85 , V_82 ) ;
if ( V_86 -> V_88 )
V_83 = V_86 -> V_88 ( & V_84 -> V_7 , V_33 , V_36 ) ;
return V_83 ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
F_2 ( V_7 -> V_89 , & V_2 -> V_90 ) ;
F_2 ( V_2 -> V_90 + V_91 ,
& V_2 -> V_92 ) ;
F_2 ( V_2 -> V_92 + 1 , & V_2 -> V_93 ) ;
F_2 ( V_2 -> V_93 + V_94 ,
& V_2 -> V_95 ) ;
F_2 ( V_2 -> V_95 + 1 , & V_2 -> V_96 ) ;
F_2 ( V_2 -> V_96 + V_97 ,
& V_2 -> V_98 ) ;
F_2 ( V_2 -> V_98 + 1 , & V_2 -> V_99 ) ;
F_2 ( V_2 -> V_99 + V_100 ,
& V_2 -> V_101 ) ;
F_2 ( V_2 -> V_101 + 1 , & V_2 -> V_102 ) ;
F_2 ( V_2 -> V_102 + V_103 ,
& V_2 -> V_104 ) ;
F_2 ( V_2 -> V_104 + 1 , & V_2 -> V_105 ) ;
F_2 ( V_2 -> V_105 + V_106 ,
& V_2 -> V_107 ) ;
F_2 ( V_2 -> V_90 , & V_2 -> V_108 ) ;
F_2 ( V_2 -> V_93 , & V_2 -> V_109 ) ;
F_2 ( V_2 -> V_96 , & V_2 -> V_110 ) ;
V_7 -> V_66 = V_111 + 1 ;
F_6 ( V_7 , V_69 , 4 , V_111 ) ;
F_6 ( V_7 , V_112 , 4 , 0xC ) ;
V_7 -> V_72 = F_35 ( V_113 ,
V_7 -> V_66 ) ;
F_2 ( V_113 , & V_2 -> V_71 ) ;
F_2 ( 0 , & V_2 -> V_114 ) ;
F_2 ( V_111 + 1 , & V_2 -> V_115 ) ;
F_2 ( 0x0 , & V_2 -> V_116 ) ;
F_2 ( 0x0 , & V_2 -> V_116 ) ;
F_2 ( 0x0 , & V_2 -> V_117 ) ;
F_2 ( V_118 | ( 1 << V_119 )
| ( ( T_2 ) 1 << V_120 ) ,
& V_2 -> V_37 ) ;
F_2 ( 0 , & V_2 -> V_121 ) ;
F_6 ( V_7 , V_44 , 1 , 1 ) ;
}
static int F_47 ( struct V_122 * V_123 )
{
struct V_124 * V_125 , * V_126 ;
unsigned int V_22 = 0 ;
int V_31 ;
struct V_127 * V_127 ;
static struct V_77 * V_84 ;
struct V_6 * V_7 ;
struct V_78 * V_128 ;
struct V_129 * V_80 ;
V_125 = F_48 ( V_123 , V_130 , 0 ) ;
if ( ! V_125 ) {
F_49 ( & V_123 -> V_131 , L_9 ) ;
return - V_132 ;
}
if ( ! F_50 ( V_125 -> V_133 , F_51 ( V_125 ) ,
V_123 -> V_134 ) ) {
F_49 ( & V_123 -> V_131 , L_10 ) ;
return - V_132 ;
}
V_126 = F_48 ( V_123 , V_130 , 1 ) ;
if ( ! V_126 ) {
F_49 ( & V_123 -> V_131 , L_9 ) ;
goto V_135;
}
if ( ! F_50 ( V_126 -> V_133 , F_51 ( V_126 ) ,
V_123 -> V_134 ) ) {
F_49 ( & V_123 -> V_131 , L_10 ) ;
goto V_135;
}
V_84 = F_52 ( sizeof( * V_84 ) , V_136 ) ;
if ( ! V_84 ) {
F_49 ( & V_123 -> V_131 , L_11 ) ;
V_22 = - V_73 ;
goto V_137;
}
V_128 = & V_84 -> V_80 . V_138 . V_128 ;
sprintf ( V_128 -> V_139 , L_12 , V_123 -> V_17 ) ;
V_128 -> V_140 = & V_141 ;
V_7 = & V_84 -> V_7 ;
V_7 -> V_11 = ( void T_1 * ) F_35 ( V_125 -> V_133 ,
F_51 ( V_125 ) ) ;
if ( ! V_7 -> V_11 ) {
F_49 ( & V_123 -> V_131 , L_13 ) ;
V_22 = - V_73 ;
goto V_142;
}
V_7 -> V_89 = ( void T_1 * ) V_126 -> V_133 ;
V_7 -> V_13 = ( void T_1 * ) F_35 ( V_126 -> V_133 ,
F_51 ( V_126 ) ) ;
if ( ! V_7 -> V_13 ) {
F_49 ( & V_123 -> V_131 , L_13 ) ;
V_22 = - V_73 ;
goto V_143;
}
F_53 ( & V_123 -> V_131 , V_84 ) ;
V_31 = F_54 ( V_123 , 0 ) ;
if ( V_31 < 0 ) {
F_49 ( & V_123 -> V_131 , L_14 ) ;
V_22 = V_31 ;
goto V_144;
}
V_22 = F_55 ( V_31 , F_13 , 0 , V_123 -> V_134 , NULL ) ;
if ( V_22 ) {
F_49 ( & V_123 -> V_131 ,
L_15 , V_31 ) ;
goto V_144;
}
V_80 = & V_84 -> V_80 ;
F_56 ( & V_80 -> V_138 ) ;
F_57 ( & V_80 -> V_145 ) ;
V_22 = F_58 ( V_80 ) ;
if ( V_22 )
goto V_146;
if ( V_123 -> V_17 == 1 ) {
V_127 = F_59 ( L_16 , NULL ) ;
if ( F_60 ( V_127 ) ) {
F_61 ( L_17 , V_147 ) ;
goto V_146;
}
if ( F_62 ( V_127 ) ) {
F_61 ( L_18 , V_147 ) ;
goto V_146;
}
} else if ( V_123 -> V_17 == 2 ) {
V_127 = F_59 ( L_19 , NULL ) ;
if ( F_60 ( V_127 ) ) {
F_61 ( L_20 , V_147 ) ;
goto V_146;
}
if ( F_62 ( V_127 ) ) {
F_61 ( L_21 , V_147 ) ;
goto V_146;
}
}
F_46 ( V_7 ) ;
return 0 ;
V_146:
F_63 ( V_31 , NULL ) ;
V_144:
F_34 ( V_7 -> V_13 ) ;
V_143:
F_34 ( V_7 -> V_11 ) ;
V_142:
F_64 ( V_84 ) ;
V_137:
F_65 ( V_126 -> V_133 , F_51 ( V_126 ) ) ;
V_135:
F_65 ( V_125 -> V_133 , F_51 ( V_125 ) ) ;
return V_22 ;
}
static int F_66 ( struct V_122 * V_123 )
{
struct V_124 * V_125 , * V_126 ;
static struct V_77 * V_84 ;
struct V_6 * V_7 ;
int V_31 ;
V_125 = F_48 ( V_123 , V_130 , 0 ) ;
V_126 = F_48 ( V_123 , V_130 , 1 ) ;
V_31 = F_54 ( V_123 , 0 ) ;
V_84 = F_67 ( & V_123 -> V_131 ) ;
V_7 = & V_84 -> V_7 ;
F_63 ( V_31 , NULL ) ;
F_34 ( V_7 -> V_13 ) ;
F_34 ( V_7 -> V_11 ) ;
F_65 ( V_126 -> V_133 , F_51 ( V_126 ) ) ;
F_65 ( V_125 -> V_133 , F_51 ( V_125 ) ) ;
F_68 ( & V_84 -> V_80 ) ;
F_64 ( V_84 ) ;
return 0 ;
}
static void F_69 ( struct V_122 * V_123 )
{
}
