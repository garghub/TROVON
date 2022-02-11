static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ==
( V_2 -> V_4 + 1 ) % V_5 ;
}
static void F_2 ( struct V_1 * V_2 , const char * V_6 ,
T_1 args )
{
char V_7 [ V_8 ] ;
T_2 V_9 = F_3 () ;
unsigned long V_10 ;
if ( ! V_2 -> V_11 [ V_2 -> V_4 ] ) {
V_2 -> V_11 [ V_2 -> V_4 ] =
F_4 ( V_8 , V_12 ) ;
if ( ! V_2 -> V_11 [ V_2 -> V_4 ] )
return;
}
vsnprintf ( V_7 , sizeof( V_7 ) , V_6 , args ) ;
F_5 ( & V_2 -> V_13 ) ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_4 = F_6 ( V_2 -> V_4 - 1 , 0 ) ;
F_7 ( V_7 , L_1 , sizeof( V_7 ) ) ;
}
if ( V_2 -> V_4 < 0 ||
V_2 -> V_4 >= V_5 ) {
F_8 ( V_2 -> V_14 ,
L_2 , V_2 -> V_4 ) ;
goto abort;
}
if ( ! V_2 -> V_11 [ V_2 -> V_4 ] ) {
F_8 ( V_2 -> V_14 ,
L_3 , V_2 -> V_4 ) ;
goto abort;
}
V_10 = F_9 ( V_9 , 1000000000 ) ;
F_10 ( V_2 -> V_11 [ V_2 -> V_4 ] ,
V_8 , L_4 ,
( unsigned long ) V_9 , V_10 / 1000 ,
V_7 ) ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) % V_5 ;
abort:
F_11 ( & V_2 -> V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 , const char * V_6 , ... )
{
T_1 args ;
va_start ( args , V_6 ) ;
F_2 ( V_2 , V_6 , args ) ;
va_end ( args ) ;
}
static int F_13 ( struct V_15 * V_16 , void * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_18 ;
int V_19 ;
F_5 ( & V_2 -> V_13 ) ;
V_19 = V_2 -> V_3 ;
while ( V_19 != V_2 -> V_4 ) {
F_14 ( V_16 , L_5 , V_2 -> V_11 [ V_19 ] ) ;
V_19 = ( V_19 + 1 ) % V_5 ;
}
if ( ! F_15 ( V_16 ) )
V_2 -> V_3 = V_19 ;
F_11 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
return F_17 ( V_21 , F_13 , V_20 -> V_22 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_13 ) ;
if ( ! V_23 ) {
V_23 = F_20 ( L_6 , NULL ) ;
if ( ! V_23 )
return - V_24 ;
}
V_2 -> V_25 = F_21 ( F_22 ( V_2 -> V_14 ) ,
V_26 | 0444 , V_23 ,
V_2 , & V_27 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_25 ) ;
}
static void F_12 ( const struct V_1 * V_2 ,
const char * V_6 , ... ) { }
static int F_18 ( const struct V_1 * V_2 ) { return 0 ; }
static void F_23 ( const struct V_1 * V_2 ) { }
static bool F_25 ( struct V_1 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
if ( F_26 ( & V_2 -> V_30 ) ) {
F_27 ( V_2 -> V_14 , L_7 ,
V_28 + 1 , V_29 ) ;
F_28 ( V_31 ) ;
} else {
return false ;
}
}
return true ;
}
static int F_29 ( struct V_1 * V_2 ,
T_3 V_32 , T_3 V_33 )
{
int V_34 = 0 ;
F_30 ( & V_2 -> V_35 , 1 ) ;
if ( F_25 ( V_2 ) ) {
F_30 ( & V_2 -> V_35 , 0 ) ;
return - V_36 ;
}
V_34 = F_31 ( V_2 -> V_37 , V_32 , V_33 ) ;
if ( V_34 < 0 )
F_12 ( V_2 , L_8 ,
V_33 , V_32 , V_34 ) ;
F_30 ( & V_2 -> V_35 , 0 ) ;
return V_34 ;
}
static int F_32 ( struct V_1 * V_2 , T_3 V_32 ,
T_3 V_38 , const T_3 * V_33 )
{
int V_34 = 0 ;
if ( V_38 <= 0 )
return V_34 ;
F_30 ( & V_2 -> V_35 , 1 ) ;
if ( F_25 ( V_2 ) ) {
F_30 ( & V_2 -> V_35 , 0 ) ;
return - V_36 ;
}
V_34 = F_33 ( V_2 -> V_37 , V_32 ,
V_38 , V_33 ) ;
if ( V_34 < 0 )
F_12 ( V_2 , L_9 ,
V_32 , V_38 , V_34 ) ;
F_30 ( & V_2 -> V_35 , 0 ) ;
return V_34 ;
}
static int F_34 ( struct V_1 * V_2 ,
T_3 V_32 , T_3 * V_33 )
{
int V_34 = 0 ;
F_30 ( & V_2 -> V_35 , 1 ) ;
if ( F_25 ( V_2 ) ) {
F_30 ( & V_2 -> V_35 , 0 ) ;
return - V_36 ;
}
V_34 = F_35 ( V_2 -> V_37 , V_32 ) ;
* V_33 = ( T_3 ) V_34 ;
if ( V_34 < 0 )
F_12 ( V_2 , L_10 , V_32 , V_34 ) ;
F_30 ( & V_2 -> V_35 , 0 ) ;
return V_34 ;
}
static int F_36 ( struct V_1 * V_2 , T_3 V_32 ,
T_3 V_38 , T_3 * V_33 )
{
int V_34 = 0 ;
if ( V_38 <= 0 )
return V_34 ;
F_30 ( & V_2 -> V_35 , 1 ) ;
if ( F_25 ( V_2 ) ) {
F_30 ( & V_2 -> V_35 , 0 ) ;
return - V_36 ;
}
V_34 = F_37 ( V_2 -> V_37 , V_32 ,
V_38 , V_33 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_11 ,
V_32 , V_38 , V_34 ) ;
goto V_39;
}
if ( V_34 != V_38 ) {
F_12 ( V_2 , L_12 ,
V_34 , V_38 , V_32 ) ;
V_34 = - V_40 ;
}
V_39:
F_30 ( & V_2 -> V_35 , 0 ) ;
return V_34 ;
}
static int F_38 ( struct V_1 * V_2 , T_3 V_32 ,
T_3 V_41 , T_3 V_42 )
{
int V_34 = 0 ;
T_3 V_33 ;
V_34 = F_34 ( V_2 , V_32 , & V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
V_33 &= ~ V_41 ;
V_33 |= V_42 ;
V_34 = F_29 ( V_2 , V_32 , V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
return V_34 ;
}
static int F_39 ( struct V_1 * V_2 , T_3 V_32 ,
T_3 V_43 )
{
return F_38 ( V_2 , V_32 , 0x00 , V_43 ) ;
}
static int F_40 ( struct V_1 * V_2 , T_3 V_32 ,
T_3 V_44 )
{
return F_38 ( V_2 , V_32 , V_44 , 0x00 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
V_34 = F_29 ( V_2 , V_45 ,
V_46 ) ;
if ( V_34 < 0 )
F_12 ( V_2 , L_13 , V_34 ) ;
else
F_12 ( V_2 , L_14 ) ;
return V_34 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
V_34 = F_39 ( V_2 , V_47 ,
V_48 |
V_49 ) ;
return V_34 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
V_34 = F_29 ( V_2 , V_50 ,
0xFF & ~ V_51 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_29 ( V_2 , V_52 , 0xFF ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_29 ( V_2 , V_53 , 0xFF ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_40 ( V_2 , V_54 ,
V_55 ) ;
if ( V_34 < 0 )
return V_34 ;
return V_34 ;
}
static int F_44 ( struct V_1 * V_2 , T_3 V_56 )
{
int V_34 = 0 ;
V_34 = F_29 ( V_2 , V_57 , V_56 ) ;
return V_34 ;
}
static int F_45 ( struct V_58 * V_14 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
T_3 V_33 ;
V_34 = F_41 ( V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_42 ( V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_43 ( V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_44 ( V_2 , V_59 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_34 ( V_2 , V_60 , & V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_61 = ! ! ( V_33 & V_62 ) ;
V_34 = F_34 ( V_2 , V_63 , & V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
F_12 ( V_2 , L_15 , V_33 ) ;
return V_34 ;
}
static int F_47 ( struct V_58 * V_14 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
F_5 ( & V_2 -> V_64 ) ;
V_34 = V_2 -> V_61 ? 1 : 0 ;
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_48 ( struct V_1 * V_2 ,
bool V_65 , bool V_66 )
{
int V_34 = 0 ;
T_3 V_33 = 0x00 ;
T_3 V_41 = V_67 |
V_68 |
V_69 |
V_70 ;
if ( V_65 )
V_33 |= ( V_2 -> V_71 == V_72 ) ?
V_67 :
V_68 ;
if ( V_66 )
V_33 |= V_69 |
V_70 ;
V_34 = F_38 ( V_2 , V_73 ,
V_41 , V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_65 = V_65 ;
return V_34 ;
}
static int F_49 ( struct V_1 * V_2 ,
enum V_74 V_75 )
{
int V_34 = 0 ;
V_2 -> V_74 = V_75 ;
switch ( V_75 ) {
case V_76 :
V_34 = F_38 ( V_2 , V_54 ,
V_77 ,
V_78 ) ;
break;
case V_79 :
V_34 = F_38 ( V_2 , V_54 ,
V_77 ,
V_80 ) ;
break;
case V_81 :
V_34 = F_38 ( V_2 , V_54 ,
V_77 ,
V_82 ) ;
break;
default:
break;
}
return V_34 ;
}
static int F_50 ( struct V_1 * V_2 ,
enum V_83 V_84 )
{
int V_34 = 0 ;
V_34 = F_40 ( V_2 , V_85 ,
V_86 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_39 ( V_2 , V_50 ,
V_87 |
V_88 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_89 = false ;
V_2 -> V_90 = false ;
switch ( V_84 ) {
case V_91 :
V_34 = F_38 ( V_2 , V_85 ,
V_92 ,
V_93 ) ;
if ( V_34 < 0 )
return V_34 ;
break;
case V_94 :
V_34 = F_38 ( V_2 , V_85 ,
V_92 ,
V_95 ) ;
if ( V_34 < 0 )
return V_34 ;
break;
case V_96 :
V_34 = F_38 ( V_2 , V_85 ,
V_92 ,
V_97 ) ;
if ( V_34 < 0 )
return V_34 ;
break;
case V_98 :
V_34 = F_38 ( V_2 , V_85 ,
V_92 ,
V_99 ) ;
if ( V_34 < 0 )
return V_34 ;
break;
default:
break;
}
if ( V_84 == V_91 ) {
V_34 = F_39 ( V_2 , V_52 ,
V_100 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_101 = false ;
} else {
V_34 = F_40 ( V_2 , V_52 ,
V_100 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_101 = true ;
V_34 = F_39 ( V_2 , V_85 ,
V_86 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_102 = V_103 ;
V_2 -> V_104 = V_103 ;
}
V_2 -> V_83 = V_84 ;
return V_34 ;
}
static int F_51 ( struct V_58 * V_14 , enum V_105 V_106 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
bool V_65 , V_66 ;
T_3 V_107 ;
F_5 ( & V_2 -> V_64 ) ;
switch ( V_106 ) {
case V_103 :
V_65 = false ;
V_66 = false ;
break;
case V_108 :
V_65 = false ;
V_66 = true ;
break;
case V_109 :
case V_110 :
case V_111 :
V_65 = true ;
V_66 = false ;
break;
default:
F_12 ( V_2 , L_16 ,
V_112 [ V_106 ] ) ;
V_34 = - V_113 ;
goto V_39;
}
V_34 = F_50 ( V_2 , V_91 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_17 , V_34 ) ;
goto V_39;
}
V_34 = F_48 ( V_2 , V_65 , V_66 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_18 ,
V_65 ? L_19 : L_20 ,
V_66 ? L_19 : L_20 ,
V_34 ) ;
goto V_39;
}
V_2 -> V_102 = V_103 ;
V_2 -> V_104 = V_103 ;
if ( V_65 ) {
V_34 = F_49 ( V_2 , V_114 [ V_106 ] ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_21 ,
V_112 [ V_106 ] , V_34 ) ;
goto V_39;
}
}
if ( V_65 ) {
V_107 = V_115 [ V_114 [ V_106 ] ] ;
V_34 = F_29 ( V_2 , V_116 , V_107 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_22 ,
V_34 ) ;
goto V_39;
}
V_34 = F_38 ( V_2 , V_50 ,
V_87 |
V_88 ,
V_88 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_23 ,
V_34 ) ;
goto V_39;
}
V_2 -> V_89 = false ;
V_2 -> V_90 = true ;
}
if ( V_66 ) {
V_34 = F_38 ( V_2 , V_50 ,
V_87 |
V_88 ,
V_87 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_23 ,
V_34 ) ;
goto V_39;
}
V_2 -> V_89 = true ;
V_2 -> V_90 = false ;
}
F_12 ( V_2 , L_24 , V_112 [ V_106 ] ) ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_52 ( struct V_58 * V_14 , enum V_105 * V_102 ,
enum V_105 * V_104 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
F_5 ( & V_2 -> V_64 ) ;
* V_102 = V_2 -> V_102 ;
* V_104 = V_2 -> V_104 ;
F_12 ( V_2 , L_25 , V_112 [ * V_102 ] ,
V_112 [ * V_104 ] ) ;
F_11 ( & V_2 -> V_64 ) ;
return 0 ;
}
static int F_53 ( struct V_58 * V_14 ,
enum V_117 V_118 )
{
return 0 ;
}
static int F_54 ( struct V_58 * V_14 , bool V_119 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
T_3 V_120 = 0x00 ;
T_3 V_121 = V_122 |
V_123 ;
F_5 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_124 == V_119 ) {
F_12 ( V_2 , L_26 , V_119 ? L_27 : L_28 ) ;
goto V_39;
}
if ( V_119 ) {
V_120 = ( V_2 -> V_71 == V_72 ) ?
V_123 :
V_122 ;
}
V_34 = F_38 ( V_2 , V_73 ,
V_121 , V_120 ) ;
if ( V_34 < 0 )
goto V_39;
V_2 -> V_124 = V_119 ;
F_12 ( V_2 , L_29 , V_119 ? L_27 : L_28 ) ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_55 ( struct V_58 * V_14 , bool V_119 , bool V_125 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
F_5 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_126 == V_119 ) {
F_12 ( V_2 , L_30 , V_119 ? L_27 : L_28 ) ;
} else {
if ( V_119 )
V_34 = F_56 ( V_2 -> V_127 ) ;
else
V_34 = F_57 ( V_2 -> V_127 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_31 ,
V_119 ? L_32 : L_33 , V_34 ) ;
goto V_39;
}
V_2 -> V_126 = V_119 ;
F_12 ( V_2 , L_34 , V_119 ? L_27 : L_28 ) ;
}
if ( V_2 -> V_128 == V_125 )
F_12 ( V_2 , L_35 ,
V_125 ? L_27 : L_28 ) ;
else
V_2 -> V_128 = V_125 ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_58 ( struct V_58 * V_14 , T_4 V_129 , T_4 V_130 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
F_12 ( V_2 , L_36 ,
V_129 , V_130 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_54 ,
V_131 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_132 ,
V_133 ) ;
}
static int F_61 ( struct V_1 * V_2 , bool V_119 )
{
if ( V_119 )
return F_39 ( V_2 , V_134 ,
V_135 ) ;
return F_40 ( V_2 , V_134 ,
V_135 ) ;
}
static int F_62 ( struct V_1 * V_2 , bool V_119 )
{
int V_34 = 0 ;
T_3 V_136 = V_137 ;
T_3 V_138 = V_139 |
V_140 |
V_141 |
V_142 ;
T_3 V_143 = V_144 ;
V_34 = V_119 ?
F_40 ( V_2 , V_50 , V_136 ) :
F_39 ( V_2 , V_50 , V_136 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = V_119 ?
F_40 ( V_2 , V_52 , V_138 ) :
F_39 ( V_2 , V_52 , V_138 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = V_119 ?
F_40 ( V_2 , V_53 , V_143 ) :
F_39 ( V_2 , V_53 , V_143 ) ;
return V_34 ;
}
static int F_63 ( struct V_58 * V_14 , bool V_119 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
F_5 ( & V_2 -> V_64 ) ;
V_34 = F_60 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_37 , V_34 ) ;
goto V_39;
}
V_34 = F_59 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_38 , V_34 ) ;
goto V_39;
}
V_34 = F_61 ( V_2 , V_119 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_39 ,
V_119 ? L_40 : L_41 , V_34 ) ;
goto V_39;
}
V_34 = F_62 ( V_2 , V_119 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_42 ,
V_119 ? L_40 : L_41 , V_34 ) ;
goto V_39;
}
F_12 ( V_2 , L_43 , V_119 ? L_40 : L_41 ) ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_64 ( struct V_58 * V_14 , bool V_145 ,
enum V_146 V_147 , enum V_148 V_33 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
T_3 V_149 = V_150 |
V_151 ;
T_3 V_152 = 0x00 ;
F_5 ( & V_2 -> V_64 ) ;
if ( V_147 == V_153 )
V_152 |= V_150 ;
if ( V_33 == V_154 )
V_152 |= V_151 ;
V_34 = F_38 ( V_2 , V_134 ,
V_149 , V_152 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_44 ,
V_155 [ V_147 ] , V_156 [ V_33 ] ,
V_34 ) ;
goto V_39;
}
F_12 ( V_2 , L_45 , V_155 [ V_147 ] ,
V_156 [ V_33 ] ) ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_65 ( struct V_58 * V_14 ,
enum V_105 V_106 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
F_5 ( & V_2 -> V_64 ) ;
V_34 = F_49 ( V_2 , V_114 [ V_106 ] ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_46 ,
V_112 [ V_106 ] , V_34 ) ;
goto V_39;
}
V_34 = F_50 ( V_2 , V_98 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_47 , V_34 ) ;
goto V_39;
}
F_12 ( V_2 , L_48 ) ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_157 * V_158 )
{
int V_34 = 0 ;
T_3 V_159 [ 40 ] ;
T_3 V_160 = 0 ;
int V_161 ;
V_159 [ V_160 ++ ] = V_162 ;
V_159 [ V_160 ++ ] = V_162 ;
V_159 [ V_160 ++ ] = V_162 ;
V_159 [ V_160 ++ ] = V_163 ;
V_161 = F_67 ( V_158 -> V_164 ) * 4 ;
V_161 += 2 ;
if ( V_161 > 0x1F ) {
F_12 ( V_2 ,
L_49 , V_161 ) ;
return - V_113 ;
}
V_159 [ V_160 ++ ] = V_165 | ( V_161 & 0x1F ) ;
memcpy ( & V_159 [ V_160 ] , & V_158 -> V_164 , sizeof( V_158 -> V_164 ) ) ;
V_160 += sizeof( V_158 -> V_164 ) ;
V_161 -= 2 ;
memcpy ( & V_159 [ V_160 ] , V_158 -> V_166 , V_161 ) ;
V_160 += V_161 ;
V_159 [ V_160 ++ ] = V_167 ;
V_159 [ V_160 ++ ] = V_168 ;
V_159 [ V_160 ++ ] = V_169 ;
V_159 [ V_160 ++ ] = V_170 ;
V_34 = F_32 ( V_2 , V_171 , V_160 , V_159 ) ;
if ( V_34 < 0 )
return V_34 ;
F_12 ( V_2 , L_50 , V_158 -> V_164 ) ;
F_12 ( V_2 , L_51 , V_161 ) ;
return V_34 ;
}
static int F_68 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_47 ,
V_172 ) ;
}
static int F_69 ( struct V_58 * V_14 , enum V_173 type ,
const struct V_157 * V_158 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
F_5 ( & V_2 -> V_64 ) ;
switch ( type ) {
case V_174 :
V_34 = F_66 ( V_2 , V_158 ) ;
if ( V_34 < 0 )
F_12 ( V_2 ,
L_52 , V_34 ) ;
break;
case V_175 :
V_34 = F_68 ( V_2 ) ;
if ( V_34 < 0 )
F_12 ( V_2 ,
L_53 , V_34 ) ;
break;
default:
F_12 ( V_2 , L_54 ,
V_176 [ type ] ) ;
V_34 = - V_113 ;
}
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static enum V_105 F_70 ( T_3 V_177 )
{
if ( V_177 == V_178 )
return V_111 ;
if ( V_177 == V_179 )
return V_110 ;
if ( V_177 == V_180 )
return V_109 ;
return V_103 ;
}
static void F_71 ( struct V_181 * V_182 )
{
struct V_1 * V_2 = F_46 ( V_182 , struct V_1 ,
V_183 . V_182 ) ;
int V_34 = 0 ;
T_3 V_184 ;
T_3 V_177 ;
enum V_105 V_185 ;
F_5 ( & V_2 -> V_64 ) ;
if ( ! V_2 -> V_89 ) {
F_12 ( V_2 , L_55 ) ;
goto V_39;
}
V_34 = F_34 ( V_2 , V_60 , & V_184 ) ;
if ( V_34 < 0 )
goto V_39;
F_12 ( V_2 , L_56 , V_184 ) ;
if ( V_184 & V_186 ) {
F_12 ( V_2 , L_57 ) ;
F_72 ( V_2 -> V_187 , & V_2 -> V_183 ,
F_73 ( V_188 ) ) ;
goto V_39;
}
V_177 = V_184 & V_189 ;
V_185 = F_70 ( V_177 ) ;
if ( V_2 -> V_71 == V_72 ) {
if ( V_2 -> V_102 != V_185 ) {
F_12 ( V_2 , L_58 ,
V_112 [ V_2 -> V_102 ] ,
V_112 [ V_185 ] ) ;
V_2 -> V_102 = V_185 ;
F_74 ( V_2 -> V_190 ) ;
}
} else {
if ( V_2 -> V_104 != V_185 ) {
F_12 ( V_2 , L_59 ,
V_112 [ V_2 -> V_104 ] ,
V_112 [ V_185 ] ) ;
V_2 -> V_104 = V_185 ;
F_74 ( V_2 -> V_190 ) ;
}
}
V_39:
F_11 ( & V_2 -> V_64 ) ;
}
static void F_75 ( struct V_58 * V_191 )
{
V_191 -> V_192 = & V_193 ;
V_191 -> V_194 = F_45 ;
V_191 -> V_195 = F_47 ;
V_191 -> V_196 = F_51 ;
V_191 -> V_197 = F_52 ;
V_191 -> V_198 = F_53 ;
V_191 -> V_199 = F_54 ;
V_191 -> V_200 = F_55 ;
V_191 -> V_201 = F_58 ;
V_191 -> V_202 = F_63 ;
V_191 -> V_203 = F_64 ;
V_191 -> V_204 = F_65 ;
V_191 -> V_205 = F_69 ;
V_191 -> V_206 = NULL ;
}
static int F_76 ( struct V_1 * V_2 ,
enum V_117 V_71 )
{
int V_34 = 0 ;
T_3 V_121 = V_67 |
V_68 |
V_122 |
V_123 |
V_207 |
V_208 ;
T_3 V_120 = 0x00 ;
T_3 V_149 = V_209 |
V_210 ;
T_3 V_152 = 0x00 ;
if ( V_71 == V_72 ) {
V_120 = V_207 ;
if ( V_2 -> V_124 )
V_120 |= V_123 ;
if ( V_2 -> V_65 )
V_120 |= V_67 ;
V_152 = V_209 ;
} else {
V_120 = V_208 ;
if ( V_2 -> V_124 )
V_120 |= V_122 ;
if ( V_2 -> V_65 )
V_120 |= V_68 ;
V_152 = V_210 ;
}
V_34 = F_38 ( V_2 , V_73 ,
V_121 , V_120 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_38 ( V_2 , V_134 ,
V_149 , V_152 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_71 = V_71 ;
return V_34 ;
}
static int F_77 ( struct V_1 * V_2 ,
T_3 V_211 )
{
int V_34 = 0 ;
T_3 V_184 ;
T_3 V_177 ;
enum V_117 V_71 ;
enum V_105 V_212 , V_102 , V_104 ;
V_34 = F_48 ( V_2 , false , true ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_60 , V_34 ) ;
return V_34 ;
}
V_71 = ( V_211 == V_213 ) ?
V_72 : V_214 ;
V_34 = F_76 ( V_2 , V_71 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_61 ,
V_215 [ V_71 ] , V_34 ) ;
return V_34 ;
}
V_34 = F_34 ( V_2 , V_60 , & V_184 ) ;
if ( V_34 < 0 )
return V_34 ;
V_177 = V_184 & V_189 ;
V_212 = F_70 ( V_177 ) ;
if ( V_212 == V_103 ) {
F_12 ( V_2 , L_62 ) ;
V_34 = F_50 ( V_2 , V_2 -> V_83 ) ;
return V_34 ;
}
V_102 = ( V_71 == V_72 ) ?
V_212 : V_103 ;
V_104 = ( V_71 == V_214 ) ?
V_212 : V_103 ;
if ( ( V_2 -> V_102 != V_102 ) || ( V_2 -> V_104 != V_104 ) ) {
V_2 -> V_102 = V_102 ;
V_2 -> V_104 = V_104 ;
F_74 ( V_2 -> V_190 ) ;
}
V_34 = F_50 ( V_2 , V_91 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_63 , V_34 ) ;
return V_34 ;
}
V_34 = F_40 ( V_2 , V_50 , V_87 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_64 , V_34 ) ;
return V_34 ;
}
V_2 -> V_89 = true ;
F_12 ( V_2 , L_65 ,
V_112 [ V_102 ] ,
V_112 [ V_104 ] ) ;
return V_34 ;
}
static int F_78 ( struct V_1 * V_2 ,
T_3 V_211 )
{
int V_34 = 0 ;
T_3 V_184 ;
T_3 V_216 = V_217 [ V_2 -> V_74 ] ;
T_3 V_107 = V_115 [ V_2 -> V_74 ] ;
bool V_218 , V_219 ;
enum V_117 V_71 ;
enum V_105 V_212 , V_102 , V_104 ;
V_34 = F_48 ( V_2 , true , false ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_66 , V_34 ) ;
return V_34 ;
}
V_71 = ( V_211 == V_220 ) ?
V_72 : V_214 ;
V_34 = F_76 ( V_2 , V_71 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_61 ,
V_215 [ V_71 ] , V_34 ) ;
return V_34 ;
}
V_34 = F_29 ( V_2 , V_116 , V_107 ) ;
if ( V_34 < 0 )
return V_34 ;
F_79 ( 50 , 100 ) ;
V_34 = F_34 ( V_2 , V_60 , & V_184 ) ;
if ( V_34 < 0 )
return V_34 ;
V_219 = ! ! ( V_184 & V_221 ) ;
if ( ! V_219 ) {
V_34 = F_29 ( V_2 , V_116 , V_216 ) ;
if ( V_34 < 0 )
return V_34 ;
F_79 ( 50 , 100 ) ;
V_34 = F_34 ( V_2 , V_60 , & V_184 ) ;
if ( V_34 < 0 )
return V_34 ;
V_218 = ! ! ( V_184 & V_221 ) ;
}
if ( V_219 )
V_212 = V_103 ;
else if ( V_218 )
V_212 = V_108 ;
else
V_212 = V_103 ;
if ( V_212 == V_103 ) {
F_12 ( V_2 , L_62 ) ;
V_34 = F_50 ( V_2 , V_2 -> V_83 ) ;
return V_34 ;
}
V_102 = ( V_71 == V_72 ) ?
V_212 : V_103 ;
V_104 = ( V_71 == V_214 ) ?
V_212 : V_103 ;
if ( ( V_2 -> V_102 != V_102 ) || ( V_2 -> V_104 != V_104 ) ) {
V_2 -> V_102 = V_102 ;
V_2 -> V_104 = V_104 ;
F_74 ( V_2 -> V_190 ) ;
}
V_34 = F_50 ( V_2 , V_91 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_63 , V_34 ) ;
return V_34 ;
}
V_34 = F_29 ( V_2 , V_116 , V_107 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_40 ( V_2 , V_50 ,
V_88 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_64 , V_34 ) ;
return V_34 ;
}
V_2 -> V_90 = true ;
F_12 ( V_2 , L_65 ,
V_112 [ V_102 ] ,
V_112 [ V_104 ] ) ;
return V_34 ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
T_3 V_222 ;
T_3 V_211 ;
V_34 = F_34 ( V_2 , V_223 , & V_222 ) ;
if ( V_34 < 0 )
return V_34 ;
V_211 = ( V_222 >> V_224 ) &
V_225 ;
switch ( V_211 ) {
case V_213 :
case V_226 :
return F_77 ( V_2 , V_211 ) ;
case V_220 :
case V_227 :
return F_78 ( V_2 , V_211 ) ;
case V_228 :
F_12 ( V_2 , L_67 ) ;
F_50 ( V_2 , V_2 -> V_83 ) ;
break;
default:
F_12 ( V_2 , L_68 ,
V_211 ) ;
F_50 ( V_2 , V_2 -> V_83 ) ;
break;
}
return V_34 ;
}
static int F_81 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_45 ,
V_229 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_157 * V_158 )
{
int V_34 = 0 ;
T_3 V_230 ;
T_3 V_231 [ 4 ] ;
int V_161 ;
V_34 = F_34 ( V_2 , V_171 , & V_230 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_36 ( V_2 , V_171 , 2 ,
( T_3 * ) & V_158 -> V_164 ) ;
if ( V_34 < 0 )
return V_34 ;
V_161 = F_67 ( V_158 -> V_164 ) * 4 ;
if ( V_161 > V_232 * 4 ) {
F_12 ( V_2 , L_69 , V_161 ) ;
return - V_113 ;
}
if ( V_161 > 0 ) {
V_34 = F_36 ( V_2 , V_171 , V_161 ,
( T_3 * ) V_158 -> V_166 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_34 = F_36 ( V_2 , V_171 , 4 , V_231 ) ;
if ( V_34 < 0 )
return V_34 ;
F_12 ( V_2 , L_70 , V_158 -> V_164 ) ;
F_12 ( V_2 , L_71 , V_161 ) ;
return V_34 ;
}
static T_5 F_83 ( int V_233 , void * V_234 )
{
struct V_1 * V_2 = V_234 ;
int V_34 = 0 ;
T_3 V_235 ;
T_3 V_236 ;
T_3 V_237 ;
T_3 V_184 ;
bool V_61 ;
bool V_238 ;
bool V_101 ;
bool V_89 ;
bool V_90 ;
struct V_157 V_239 ;
F_5 ( & V_2 -> V_64 ) ;
V_101 = V_2 -> V_101 ;
V_89 = V_2 -> V_89 ;
V_90 = V_2 -> V_90 ;
V_34 = F_34 ( V_2 , V_240 , & V_235 ) ;
if ( V_34 < 0 )
goto V_39;
V_34 = F_34 ( V_2 , V_241 , & V_236 ) ;
if ( V_34 < 0 )
goto V_39;
V_34 = F_34 ( V_2 , V_242 , & V_237 ) ;
if ( V_34 < 0 )
goto V_39;
V_34 = F_34 ( V_2 , V_60 , & V_184 ) ;
if ( V_34 < 0 )
goto V_39;
F_12 ( V_2 ,
L_72 ,
V_235 , V_236 , V_237 , V_184 ) ;
if ( V_235 & V_243 ) {
V_61 = ! ! ( V_184 & V_62 ) ;
F_12 ( V_2 , L_73 ,
V_61 ? L_27 : L_28 ) ;
if ( V_61 != V_2 -> V_61 ) {
V_2 -> V_61 = V_61 ;
F_84 ( V_2 -> V_190 ) ;
}
}
if ( ( V_236 & V_244 ) && V_101 ) {
F_12 ( V_2 , L_74 ) ;
V_34 = F_80 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_75 , V_34 ) ;
goto V_39;
}
}
if ( ( V_235 & V_245 ) && V_89 ) {
F_12 ( V_2 , L_76 ) ;
F_72 ( V_2 -> V_187 , & V_2 -> V_183 ,
F_73 ( V_188 ) ) ;
}
if ( ( V_235 & V_246 ) && V_90 ) {
V_238 = ! ! ( V_184 & V_221 ) ;
F_12 ( V_2 , L_77 ,
V_238 ? L_78 : L_79 ) ;
if ( V_238 ) {
if ( V_2 -> V_71 == V_72 )
V_2 -> V_102 = V_103 ;
else
V_2 -> V_104 = V_103 ;
F_74 ( V_2 -> V_190 ) ;
}
}
if ( V_235 & V_247 ) {
F_12 ( V_2 , L_80 ) ;
F_85 ( V_2 -> V_190 , V_248 ) ;
}
if ( V_236 & V_249 ) {
F_12 ( V_2 , L_81 ) ;
F_85 ( V_2 -> V_190 , V_248 ) ;
}
if ( V_236 & V_250 ) {
F_12 ( V_2 , L_82 ) ;
V_34 = F_81 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_83 , V_34 ) ;
goto V_39;
}
F_85 ( V_2 -> V_190 , V_251 ) ;
}
if ( V_236 & V_252 ) {
F_12 ( V_2 , L_84 ) ;
V_34 = F_82 ( V_2 , & V_239 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_85 , V_34 ) ;
goto V_39;
}
F_85 ( V_2 -> V_190 , V_251 ) ;
}
if ( V_236 & V_253 ) {
F_12 ( V_2 , L_86 ) ;
V_34 = F_81 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_83 , V_34 ) ;
goto V_39;
}
F_86 ( V_2 -> V_190 ) ;
}
if ( V_237 & V_254 ) {
F_12 ( V_2 , L_87 ) ;
V_34 = F_82 ( V_2 , & V_239 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_88 , V_34 ) ;
goto V_39;
}
F_87 ( V_2 -> V_190 , & V_239 ) ;
}
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_255 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_256 * V_257 ;
int V_34 = 0 ;
V_257 = V_2 -> V_14 -> V_258 ;
V_2 -> V_259 = F_89 ( V_257 , L_89 , 0 ) ;
if ( ! F_90 ( V_2 -> V_259 ) ) {
V_34 = V_2 -> V_259 ;
F_12 ( V_2 , L_90 , V_34 ) ;
return V_34 ;
}
V_34 = F_91 ( V_2 -> V_14 , V_2 -> V_259 , L_89 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_91 , V_34 ) ;
return V_34 ;
}
V_34 = F_92 ( V_2 -> V_259 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_92 , V_34 ) ;
return V_34 ;
}
V_34 = F_93 ( V_2 -> V_259 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_93 , V_34 ) ;
return V_34 ;
}
V_2 -> V_260 = V_34 ;
return 0 ;
}
static int F_94 ( struct V_37 * V_261 ,
const struct V_262 * V_263 )
{
struct V_1 * V_2 ;
struct V_264 * V_265 ;
int V_34 = 0 ;
V_265 = F_95 ( V_261 -> V_14 . V_266 ) ;
if ( ! F_96 ( V_265 , V_267 ) ) {
F_27 ( & V_261 -> V_14 ,
L_94 ) ;
return - V_268 ;
}
V_2 = F_97 ( & V_261 -> V_14 , sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_37 = V_261 ;
F_98 ( V_261 , V_2 ) ;
V_2 -> V_14 = & V_261 -> V_14 ;
F_19 ( & V_2 -> V_64 ) ;
V_34 = F_18 ( V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_187 = F_99 ( F_22 ( V_2 -> V_14 ) ) ;
if ( ! V_2 -> V_187 ) {
V_34 = - V_24 ;
goto V_269;
}
F_100 ( & V_2 -> V_183 , F_71 ) ;
F_75 ( & V_2 -> V_58 ) ;
V_2 -> V_127 = F_101 ( V_2 -> V_14 , L_95 ) ;
if ( F_102 ( V_2 -> V_127 ) ) {
V_34 = F_103 ( V_2 -> V_127 ) ;
goto V_270;
}
V_34 = F_88 ( V_2 ) ;
if ( V_34 < 0 )
goto V_270;
V_2 -> V_190 = F_104 ( & V_261 -> V_14 , & V_2 -> V_58 ) ;
if ( F_102 ( V_2 -> V_190 ) ) {
V_34 = F_103 ( V_2 -> V_190 ) ;
F_12 ( V_2 , L_96 , V_34 ) ;
goto V_270;
}
V_34 = F_105 ( V_2 -> V_14 , V_2 -> V_260 ,
NULL , F_83 ,
V_271 | V_272 ,
L_97 , V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_93 , V_34 ) ;
goto V_273;
}
F_106 ( V_2 -> V_260 ) ;
return V_34 ;
V_273:
V_273 ( V_2 -> V_190 ) ;
V_270:
V_270 ( V_2 -> V_187 ) ;
V_269:
F_98 ( V_261 , NULL ) ;
F_23 ( V_2 ) ;
return V_34 ;
}
static int F_107 ( struct V_37 * V_261 )
{
struct V_1 * V_2 = F_108 ( V_261 ) ;
V_273 ( V_2 -> V_190 ) ;
V_270 ( V_2 -> V_187 ) ;
F_98 ( V_261 , NULL ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_109 ( struct V_274 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_275 ;
if ( F_26 ( & V_2 -> V_35 ) )
return - V_276 ;
F_30 ( & V_2 -> V_30 , 1 ) ;
return 0 ;
}
static int F_110 ( struct V_274 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_275 ;
F_30 ( & V_2 -> V_30 , 0 ) ;
return 0 ;
}
