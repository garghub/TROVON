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
static int F_48 ( struct V_58 * V_14 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_65 = 0 ;
unsigned long V_66 ;
if ( ! V_2 -> V_67 )
return 0 ;
V_66 = V_68 + F_49 ( 800 ) ;
do {
if ( F_50 ( V_2 -> V_67 , V_69 ) == 1 )
V_65 = 500 ;
if ( F_50 ( V_2 -> V_67 , V_70 ) == 1 ||
F_50 ( V_2 -> V_67 , V_71 ) == 1 )
V_65 = 1500 ;
if ( F_50 ( V_2 -> V_67 , V_72 ) == 1 )
V_65 = 2000 ;
F_28 ( 50 ) ;
} while ( V_65 == 0 && F_51 ( V_68 , V_66 ) );
return V_65 ;
}
static int F_52 ( struct V_1 * V_2 ,
bool V_73 , bool V_74 )
{
int V_34 = 0 ;
T_3 V_33 = 0x00 ;
T_3 V_41 = V_75 |
V_76 |
V_77 |
V_78 ;
if ( V_73 )
V_33 |= ( V_2 -> V_79 == V_80 ) ?
V_75 :
V_76 ;
if ( V_74 )
V_33 |= V_77 |
V_78 ;
V_34 = F_38 ( V_2 , V_81 ,
V_41 , V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_73 = V_73 ;
return V_34 ;
}
static int F_53 ( struct V_1 * V_2 ,
enum V_82 V_83 )
{
int V_34 = 0 ;
V_2 -> V_82 = V_83 ;
switch ( V_83 ) {
case V_84 :
V_34 = F_38 ( V_2 , V_54 ,
V_85 ,
V_86 ) ;
break;
case V_87 :
V_34 = F_38 ( V_2 , V_54 ,
V_85 ,
V_88 ) ;
break;
case V_89 :
V_34 = F_38 ( V_2 , V_54 ,
V_85 ,
V_90 ) ;
break;
default:
break;
}
return V_34 ;
}
static int F_54 ( struct V_1 * V_2 ,
enum V_91 V_92 )
{
int V_34 = 0 ;
V_34 = F_40 ( V_2 , V_93 ,
V_94 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_39 ( V_2 , V_50 ,
V_95 |
V_96 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_97 = false ;
V_2 -> V_98 = false ;
switch ( V_92 ) {
case V_99 :
V_34 = F_38 ( V_2 , V_93 ,
V_100 ,
V_101 ) ;
if ( V_34 < 0 )
return V_34 ;
break;
case V_102 :
V_34 = F_38 ( V_2 , V_93 ,
V_100 ,
V_103 ) ;
if ( V_34 < 0 )
return V_34 ;
break;
case V_104 :
V_34 = F_38 ( V_2 , V_93 ,
V_100 ,
V_105 ) ;
if ( V_34 < 0 )
return V_34 ;
break;
case V_106 :
V_34 = F_38 ( V_2 , V_93 ,
V_100 ,
V_107 ) ;
if ( V_34 < 0 )
return V_34 ;
break;
default:
break;
}
if ( V_92 == V_99 ) {
V_34 = F_39 ( V_2 , V_52 ,
V_108 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_109 = false ;
} else {
V_34 = F_40 ( V_2 , V_52 ,
V_108 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_109 = true ;
V_34 = F_39 ( V_2 , V_93 ,
V_94 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_110 = V_111 ;
V_2 -> V_112 = V_111 ;
}
V_2 -> V_91 = V_92 ;
return V_34 ;
}
static int F_55 ( struct V_58 * V_14 , enum V_113 V_114 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
bool V_73 , V_74 ;
T_3 V_115 ;
F_5 ( & V_2 -> V_64 ) ;
switch ( V_114 ) {
case V_111 :
V_73 = false ;
V_74 = false ;
break;
case V_116 :
V_73 = false ;
V_74 = true ;
break;
case V_117 :
case V_118 :
case V_119 :
V_73 = true ;
V_74 = false ;
break;
default:
F_12 ( V_2 , L_16 ,
V_120 [ V_114 ] ) ;
V_34 = - V_121 ;
goto V_39;
}
V_34 = F_54 ( V_2 , V_99 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_17 , V_34 ) ;
goto V_39;
}
V_34 = F_52 ( V_2 , V_73 , V_74 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_18 ,
V_73 ? L_19 : L_20 ,
V_74 ? L_19 : L_20 ,
V_34 ) ;
goto V_39;
}
V_2 -> V_110 = V_111 ;
V_2 -> V_112 = V_111 ;
if ( V_73 ) {
V_34 = F_53 ( V_2 , V_122 [ V_114 ] ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_21 ,
V_120 [ V_114 ] , V_34 ) ;
goto V_39;
}
}
if ( V_73 ) {
V_115 = V_123 [ V_122 [ V_114 ] ] ;
V_34 = F_29 ( V_2 , V_124 , V_115 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_22 ,
V_34 ) ;
goto V_39;
}
V_34 = F_38 ( V_2 , V_50 ,
V_95 |
V_96 ,
V_96 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_23 ,
V_34 ) ;
goto V_39;
}
V_2 -> V_97 = false ;
V_2 -> V_98 = true ;
}
if ( V_74 ) {
V_34 = F_38 ( V_2 , V_50 ,
V_95 |
V_96 ,
V_95 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_23 ,
V_34 ) ;
goto V_39;
}
V_2 -> V_97 = true ;
V_2 -> V_98 = false ;
}
F_12 ( V_2 , L_24 , V_120 [ V_114 ] ) ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_56 ( struct V_58 * V_14 , enum V_113 * V_110 ,
enum V_113 * V_112 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
F_5 ( & V_2 -> V_64 ) ;
* V_110 = V_2 -> V_110 ;
* V_112 = V_2 -> V_112 ;
F_12 ( V_2 , L_25 , V_120 [ * V_110 ] ,
V_120 [ * V_112 ] ) ;
F_11 ( & V_2 -> V_64 ) ;
return 0 ;
}
static int F_57 ( struct V_58 * V_14 ,
enum V_125 V_126 )
{
return 0 ;
}
static int F_58 ( struct V_58 * V_14 , bool V_127 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
T_3 V_128 = 0x00 ;
T_3 V_129 = V_130 |
V_131 ;
F_5 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_132 == V_127 ) {
F_12 ( V_2 , L_26 , V_127 ? L_27 : L_28 ) ;
goto V_39;
}
if ( V_127 ) {
V_128 = ( V_2 -> V_79 == V_80 ) ?
V_131 :
V_130 ;
}
V_34 = F_38 ( V_2 , V_81 ,
V_129 , V_128 ) ;
if ( V_34 < 0 )
goto V_39;
V_2 -> V_132 = V_127 ;
F_12 ( V_2 , L_29 , V_127 ? L_27 : L_28 ) ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_59 ( struct V_58 * V_14 , bool V_127 , bool V_133 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
F_5 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_134 == V_127 ) {
F_12 ( V_2 , L_30 , V_127 ? L_27 : L_28 ) ;
} else {
if ( V_127 )
V_34 = F_60 ( V_2 -> V_135 ) ;
else
V_34 = F_61 ( V_2 -> V_135 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_31 ,
V_127 ? L_32 : L_33 , V_34 ) ;
goto V_39;
}
V_2 -> V_134 = V_127 ;
F_12 ( V_2 , L_34 , V_127 ? L_27 : L_28 ) ;
}
if ( V_2 -> V_136 == V_133 ) {
F_12 ( V_2 , L_35 ,
V_133 ? L_27 : L_28 ) ;
} else {
V_2 -> V_136 = V_133 ;
F_62 ( V_2 -> V_137 ) ;
}
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_63 ( struct V_58 * V_14 , T_4 V_138 , T_4 V_139 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
F_12 ( V_2 , L_36 ,
V_138 , V_139 ) ;
V_2 -> V_140 = V_139 ;
V_2 -> V_65 = V_138 ;
F_62 ( V_2 -> V_137 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_54 ,
V_141 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_142 ,
V_143 ) ;
}
static int F_66 ( struct V_1 * V_2 , bool V_127 )
{
if ( V_127 )
return F_39 ( V_2 , V_144 ,
V_145 ) ;
return F_40 ( V_2 , V_144 ,
V_145 ) ;
}
static int F_67 ( struct V_1 * V_2 , bool V_127 )
{
int V_34 = 0 ;
T_3 V_146 = V_147 ;
T_3 V_148 = V_149 |
V_150 |
V_151 |
V_152 ;
T_3 V_153 = V_154 ;
V_34 = V_127 ?
F_40 ( V_2 , V_50 , V_146 ) :
F_39 ( V_2 , V_50 , V_146 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = V_127 ?
F_40 ( V_2 , V_52 , V_148 ) :
F_39 ( V_2 , V_52 , V_148 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = V_127 ?
F_40 ( V_2 , V_53 , V_153 ) :
F_39 ( V_2 , V_53 , V_153 ) ;
return V_34 ;
}
static int F_68 ( struct V_58 * V_14 , bool V_127 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
F_5 ( & V_2 -> V_64 ) ;
V_34 = F_65 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_37 , V_34 ) ;
goto V_39;
}
V_34 = F_64 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_38 , V_34 ) ;
goto V_39;
}
V_34 = F_66 ( V_2 , V_127 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_39 ,
V_127 ? L_40 : L_41 , V_34 ) ;
goto V_39;
}
V_34 = F_67 ( V_2 , V_127 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_42 ,
V_127 ? L_40 : L_41 , V_34 ) ;
goto V_39;
}
F_12 ( V_2 , L_43 , V_127 ? L_40 : L_41 ) ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_69 ( struct V_58 * V_14 , bool V_155 ,
enum V_156 V_157 , enum V_158 V_33 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
T_3 V_159 = V_160 |
V_161 ;
T_3 V_162 = 0x00 ;
F_5 ( & V_2 -> V_64 ) ;
if ( V_157 == V_163 )
V_162 |= V_160 ;
if ( V_33 == V_164 )
V_162 |= V_161 ;
V_34 = F_38 ( V_2 , V_144 ,
V_159 , V_162 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_44 ,
V_165 [ V_157 ] , V_166 [ V_33 ] ,
V_34 ) ;
goto V_39;
}
F_12 ( V_2 , L_45 , V_165 [ V_157 ] ,
V_166 [ V_33 ] ) ;
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static int F_70 ( struct V_58 * V_14 ,
enum V_113 V_114 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
F_5 ( & V_2 -> V_64 ) ;
V_34 = F_53 ( V_2 , V_122 [ V_114 ] ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_46 ,
V_120 [ V_114 ] , V_34 ) ;
goto V_39;
}
V_34 = F_54 ( V_2 , V_106 ) ;
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
static int F_71 ( struct V_1 * V_2 ,
const struct V_167 * V_168 )
{
int V_34 = 0 ;
T_3 V_169 [ 40 ] ;
T_3 V_170 = 0 ;
int V_171 ;
V_169 [ V_170 ++ ] = V_172 ;
V_169 [ V_170 ++ ] = V_172 ;
V_169 [ V_170 ++ ] = V_172 ;
V_169 [ V_170 ++ ] = V_173 ;
V_171 = F_72 ( V_168 -> V_174 ) * 4 ;
V_171 += 2 ;
if ( V_171 > 0x1F ) {
F_12 ( V_2 ,
L_49 , V_171 ) ;
return - V_121 ;
}
V_169 [ V_170 ++ ] = V_175 | ( V_171 & 0x1F ) ;
memcpy ( & V_169 [ V_170 ] , & V_168 -> V_174 , sizeof( V_168 -> V_174 ) ) ;
V_170 += sizeof( V_168 -> V_174 ) ;
V_171 -= 2 ;
memcpy ( & V_169 [ V_170 ] , V_168 -> V_176 , V_171 ) ;
V_170 += V_171 ;
V_169 [ V_170 ++ ] = V_177 ;
V_169 [ V_170 ++ ] = V_178 ;
V_169 [ V_170 ++ ] = V_179 ;
V_169 [ V_170 ++ ] = V_180 ;
V_34 = F_32 ( V_2 , V_181 , V_170 , V_169 ) ;
if ( V_34 < 0 )
return V_34 ;
F_12 ( V_2 , L_50 , V_168 -> V_174 ) ;
F_12 ( V_2 , L_51 , V_171 ) ;
return V_34 ;
}
static int F_73 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_47 ,
V_182 ) ;
}
static int F_74 ( struct V_58 * V_14 , enum V_183 type ,
const struct V_167 * V_168 )
{
struct V_1 * V_2 = F_46 ( V_14 , struct V_1 ,
V_58 ) ;
int V_34 = 0 ;
F_5 ( & V_2 -> V_64 ) ;
switch ( type ) {
case V_184 :
V_34 = F_71 ( V_2 , V_168 ) ;
if ( V_34 < 0 )
F_12 ( V_2 ,
L_52 , V_34 ) ;
break;
case V_185 :
V_34 = F_73 ( V_2 ) ;
if ( V_34 < 0 )
F_12 ( V_2 ,
L_53 , V_34 ) ;
break;
default:
F_12 ( V_2 , L_54 ,
V_186 [ type ] ) ;
V_34 = - V_121 ;
}
F_11 ( & V_2 -> V_64 ) ;
return V_34 ;
}
static enum V_113 F_75 ( T_3 V_187 )
{
if ( V_187 == V_188 )
return V_119 ;
if ( V_187 == V_189 )
return V_118 ;
if ( V_187 == V_190 )
return V_117 ;
return V_111 ;
}
static void F_76 ( struct V_191 * V_192 )
{
struct V_1 * V_2 = F_46 ( V_192 , struct V_1 ,
V_193 . V_192 ) ;
int V_34 = 0 ;
T_3 V_194 ;
T_3 V_187 ;
enum V_113 V_195 ;
F_5 ( & V_2 -> V_64 ) ;
if ( ! V_2 -> V_97 ) {
F_12 ( V_2 , L_55 ) ;
goto V_39;
}
V_34 = F_34 ( V_2 , V_60 , & V_194 ) ;
if ( V_34 < 0 )
goto V_39;
F_12 ( V_2 , L_56 , V_194 ) ;
if ( V_194 & V_196 ) {
F_12 ( V_2 , L_57 ) ;
F_77 ( V_2 -> V_197 , & V_2 -> V_193 ,
F_49 ( V_198 ) ) ;
goto V_39;
}
V_187 = V_194 & V_199 ;
V_195 = F_75 ( V_187 ) ;
if ( V_2 -> V_79 == V_80 ) {
if ( V_2 -> V_110 != V_195 ) {
F_12 ( V_2 , L_58 ,
V_120 [ V_2 -> V_110 ] ,
V_120 [ V_195 ] ) ;
V_2 -> V_110 = V_195 ;
F_78 ( V_2 -> V_200 ) ;
}
} else {
if ( V_2 -> V_112 != V_195 ) {
F_12 ( V_2 , L_59 ,
V_120 [ V_2 -> V_112 ] ,
V_120 [ V_195 ] ) ;
V_2 -> V_112 = V_195 ;
F_78 ( V_2 -> V_200 ) ;
}
}
V_39:
F_11 ( & V_2 -> V_64 ) ;
}
static void F_79 ( struct V_58 * V_201 )
{
V_201 -> V_202 = F_45 ;
V_201 -> V_203 = F_47 ;
V_201 -> V_204 = F_48 ;
V_201 -> V_205 = F_55 ;
V_201 -> V_206 = F_56 ;
V_201 -> V_207 = F_57 ;
V_201 -> V_208 = F_58 ;
V_201 -> V_209 = F_59 ;
V_201 -> V_210 = F_63 ;
V_201 -> V_211 = F_68 ;
V_201 -> V_212 = F_69 ;
V_201 -> V_213 = F_70 ;
V_201 -> V_214 = F_74 ;
V_201 -> V_215 = NULL ;
}
static int F_80 ( struct V_1 * V_2 ,
enum V_125 V_79 )
{
int V_34 = 0 ;
T_3 V_129 = V_75 |
V_76 |
V_130 |
V_131 |
V_216 |
V_217 ;
T_3 V_128 = 0x00 ;
T_3 V_159 = V_218 |
V_219 ;
T_3 V_162 = 0x00 ;
if ( V_79 == V_80 ) {
V_128 = V_216 ;
if ( V_2 -> V_132 )
V_128 |= V_131 ;
if ( V_2 -> V_73 )
V_128 |= V_75 ;
V_162 = V_218 ;
} else {
V_128 = V_217 ;
if ( V_2 -> V_132 )
V_128 |= V_130 ;
if ( V_2 -> V_73 )
V_128 |= V_76 ;
V_162 = V_219 ;
}
V_34 = F_38 ( V_2 , V_81 ,
V_129 , V_128 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_38 ( V_2 , V_144 ,
V_159 , V_162 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_79 = V_79 ;
return V_34 ;
}
static int F_81 ( struct V_1 * V_2 ,
T_3 V_220 )
{
int V_34 = 0 ;
T_3 V_194 ;
T_3 V_187 ;
enum V_125 V_79 ;
enum V_113 V_221 , V_110 , V_112 ;
V_34 = F_52 ( V_2 , false , true ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_60 , V_34 ) ;
return V_34 ;
}
V_79 = ( V_220 == V_222 ) ?
V_80 : V_223 ;
V_34 = F_80 ( V_2 , V_79 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_61 ,
V_224 [ V_79 ] , V_34 ) ;
return V_34 ;
}
V_34 = F_34 ( V_2 , V_60 , & V_194 ) ;
if ( V_34 < 0 )
return V_34 ;
V_187 = V_194 & V_199 ;
V_221 = F_75 ( V_187 ) ;
if ( V_221 == V_111 ) {
F_12 ( V_2 , L_62 ) ;
V_34 = F_54 ( V_2 , V_2 -> V_91 ) ;
return V_34 ;
}
V_110 = ( V_79 == V_80 ) ?
V_221 : V_111 ;
V_112 = ( V_79 == V_223 ) ?
V_221 : V_111 ;
if ( ( V_2 -> V_110 != V_110 ) || ( V_2 -> V_112 != V_112 ) ) {
V_2 -> V_110 = V_110 ;
V_2 -> V_112 = V_112 ;
F_78 ( V_2 -> V_200 ) ;
}
V_34 = F_54 ( V_2 , V_99 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_63 , V_34 ) ;
return V_34 ;
}
V_34 = F_40 ( V_2 , V_50 , V_95 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_64 , V_34 ) ;
return V_34 ;
}
V_2 -> V_97 = true ;
F_12 ( V_2 , L_65 ,
V_120 [ V_110 ] ,
V_120 [ V_112 ] ) ;
return V_34 ;
}
static int F_82 ( struct V_1 * V_2 ,
T_3 V_220 )
{
int V_34 = 0 ;
T_3 V_194 ;
T_3 V_225 = V_226 [ V_2 -> V_82 ] ;
T_3 V_115 = V_123 [ V_2 -> V_82 ] ;
bool V_227 , V_228 ;
enum V_125 V_79 ;
enum V_113 V_221 , V_110 , V_112 ;
V_34 = F_52 ( V_2 , true , false ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_66 , V_34 ) ;
return V_34 ;
}
V_79 = ( V_220 == V_229 ) ?
V_80 : V_223 ;
V_34 = F_80 ( V_2 , V_79 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_61 ,
V_224 [ V_79 ] , V_34 ) ;
return V_34 ;
}
V_34 = F_29 ( V_2 , V_124 , V_115 ) ;
if ( V_34 < 0 )
return V_34 ;
F_83 ( 50 , 100 ) ;
V_34 = F_34 ( V_2 , V_60 , & V_194 ) ;
if ( V_34 < 0 )
return V_34 ;
V_228 = ! ! ( V_194 & V_230 ) ;
if ( ! V_228 ) {
V_34 = F_29 ( V_2 , V_124 , V_225 ) ;
if ( V_34 < 0 )
return V_34 ;
F_83 ( 50 , 100 ) ;
V_34 = F_34 ( V_2 , V_60 , & V_194 ) ;
if ( V_34 < 0 )
return V_34 ;
V_227 = ! ! ( V_194 & V_230 ) ;
}
if ( V_228 )
V_221 = V_111 ;
else if ( V_227 )
V_221 = V_116 ;
else
V_221 = V_111 ;
if ( V_221 == V_111 ) {
F_12 ( V_2 , L_62 ) ;
V_34 = F_54 ( V_2 , V_2 -> V_91 ) ;
return V_34 ;
}
V_110 = ( V_79 == V_80 ) ?
V_221 : V_111 ;
V_112 = ( V_79 == V_223 ) ?
V_221 : V_111 ;
if ( ( V_2 -> V_110 != V_110 ) || ( V_2 -> V_112 != V_112 ) ) {
V_2 -> V_110 = V_110 ;
V_2 -> V_112 = V_112 ;
F_78 ( V_2 -> V_200 ) ;
}
V_34 = F_54 ( V_2 , V_99 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_63 , V_34 ) ;
return V_34 ;
}
V_34 = F_29 ( V_2 , V_124 , V_115 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_40 ( V_2 , V_50 ,
V_96 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_64 , V_34 ) ;
return V_34 ;
}
V_2 -> V_98 = true ;
F_12 ( V_2 , L_65 ,
V_120 [ V_110 ] ,
V_120 [ V_112 ] ) ;
return V_34 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_34 = 0 ;
T_3 V_231 ;
T_3 V_220 ;
V_34 = F_34 ( V_2 , V_232 , & V_231 ) ;
if ( V_34 < 0 )
return V_34 ;
V_220 = ( V_231 >> V_233 ) &
V_234 ;
switch ( V_220 ) {
case V_222 :
case V_235 :
return F_81 ( V_2 , V_220 ) ;
case V_229 :
case V_236 :
return F_82 ( V_2 , V_220 ) ;
case V_237 :
F_12 ( V_2 , L_67 ) ;
F_54 ( V_2 , V_2 -> V_91 ) ;
break;
default:
F_12 ( V_2 , L_68 ,
V_220 ) ;
F_54 ( V_2 , V_2 -> V_91 ) ;
break;
}
return V_34 ;
}
static int F_85 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_45 ,
V_238 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_167 * V_168 )
{
int V_34 = 0 ;
T_3 V_239 ;
T_3 V_240 [ 4 ] ;
int V_171 ;
V_34 = F_34 ( V_2 , V_181 , & V_239 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_36 ( V_2 , V_181 , 2 ,
( T_3 * ) & V_168 -> V_174 ) ;
if ( V_34 < 0 )
return V_34 ;
V_171 = F_72 ( V_168 -> V_174 ) * 4 ;
if ( V_171 > V_241 * 4 ) {
F_12 ( V_2 , L_69 , V_171 ) ;
return - V_121 ;
}
if ( V_171 > 0 ) {
V_34 = F_36 ( V_2 , V_181 , V_171 ,
( T_3 * ) V_168 -> V_176 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_34 = F_36 ( V_2 , V_181 , 4 , V_240 ) ;
if ( V_34 < 0 )
return V_34 ;
F_12 ( V_2 , L_70 , V_168 -> V_174 ) ;
F_12 ( V_2 , L_71 , V_171 ) ;
return V_34 ;
}
static T_5 F_87 ( int V_242 , void * V_243 )
{
struct V_1 * V_2 = V_243 ;
int V_34 = 0 ;
T_3 V_244 ;
T_3 V_245 ;
T_3 V_246 ;
T_3 V_194 ;
bool V_61 ;
bool V_247 ;
bool V_109 ;
bool V_97 ;
bool V_98 ;
struct V_167 V_248 ;
F_5 ( & V_2 -> V_64 ) ;
V_109 = V_2 -> V_109 ;
V_97 = V_2 -> V_97 ;
V_98 = V_2 -> V_98 ;
V_34 = F_34 ( V_2 , V_249 , & V_244 ) ;
if ( V_34 < 0 )
goto V_39;
V_34 = F_34 ( V_2 , V_250 , & V_245 ) ;
if ( V_34 < 0 )
goto V_39;
V_34 = F_34 ( V_2 , V_251 , & V_246 ) ;
if ( V_34 < 0 )
goto V_39;
V_34 = F_34 ( V_2 , V_60 , & V_194 ) ;
if ( V_34 < 0 )
goto V_39;
F_12 ( V_2 ,
L_72 ,
V_244 , V_245 , V_246 , V_194 ) ;
if ( V_244 & V_252 ) {
V_61 = ! ! ( V_194 & V_62 ) ;
F_12 ( V_2 , L_73 ,
V_61 ? L_27 : L_28 ) ;
if ( V_61 != V_2 -> V_61 ) {
V_2 -> V_61 = V_61 ;
F_88 ( V_2 -> V_200 ) ;
}
}
if ( ( V_245 & V_253 ) && V_109 ) {
F_12 ( V_2 , L_74 ) ;
V_34 = F_84 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_75 , V_34 ) ;
goto V_39;
}
}
if ( ( V_244 & V_254 ) && V_97 ) {
F_12 ( V_2 , L_76 ) ;
F_77 ( V_2 -> V_197 , & V_2 -> V_193 ,
F_49 ( V_198 ) ) ;
}
if ( ( V_244 & V_255 ) && V_98 ) {
V_247 = ! ! ( V_194 & V_230 ) ;
F_12 ( V_2 , L_77 ,
V_247 ? L_78 : L_79 ) ;
if ( V_247 ) {
if ( V_2 -> V_79 == V_80 )
V_2 -> V_110 = V_111 ;
else
V_2 -> V_112 = V_111 ;
F_78 ( V_2 -> V_200 ) ;
}
}
if ( V_244 & V_256 ) {
F_12 ( V_2 , L_80 ) ;
F_89 ( V_2 -> V_200 , V_257 ) ;
}
if ( V_245 & V_258 ) {
F_12 ( V_2 , L_81 ) ;
F_89 ( V_2 -> V_200 , V_257 ) ;
}
if ( V_245 & V_259 ) {
F_12 ( V_2 , L_82 ) ;
V_34 = F_85 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_83 , V_34 ) ;
goto V_39;
}
F_89 ( V_2 -> V_200 , V_260 ) ;
}
if ( V_245 & V_261 ) {
F_12 ( V_2 , L_84 ) ;
V_34 = F_86 ( V_2 , & V_248 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_85 , V_34 ) ;
goto V_39;
}
F_89 ( V_2 -> V_200 , V_260 ) ;
}
if ( V_245 & V_262 ) {
F_12 ( V_2 , L_86 ) ;
V_34 = F_85 ( V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_83 , V_34 ) ;
goto V_39;
}
F_90 ( V_2 -> V_200 ) ;
}
if ( V_246 & V_263 ) {
F_12 ( V_2 , L_87 ) ;
V_34 = F_86 ( V_2 , & V_248 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_88 , V_34 ) ;
goto V_39;
}
F_91 ( V_2 -> V_200 , & V_248 ) ;
}
V_39:
F_11 ( & V_2 -> V_64 ) ;
return V_264 ;
}
static int F_92 ( struct V_265 * V_137 ,
enum V_266 V_267 ,
union V_268 * V_269 )
{
struct V_1 * V_2 = F_93 ( V_137 ) ;
switch ( V_267 ) {
case V_270 :
V_269 -> V_271 = V_2 -> V_136 ;
break;
case V_272 :
V_269 -> V_271 = V_2 -> V_140 * 1000 ;
break;
case V_273 :
V_269 -> V_271 = V_2 -> V_65 * 1000 ;
break;
default:
return - V_274 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_275 * V_276 ;
int V_34 = 0 ;
V_276 = V_2 -> V_14 -> V_277 ;
V_2 -> V_278 = F_95 ( V_276 , L_89 , 0 ) ;
if ( ! F_96 ( V_2 -> V_278 ) ) {
V_34 = V_2 -> V_278 ;
F_12 ( V_2 , L_90 , V_34 ) ;
return V_34 ;
}
V_34 = F_97 ( V_2 -> V_14 , V_2 -> V_278 , L_89 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 , L_91 , V_34 ) ;
return V_34 ;
}
V_34 = F_98 ( V_2 -> V_278 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_92 , V_34 ) ;
return V_34 ;
}
V_34 = F_99 ( V_2 -> V_278 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_93 , V_34 ) ;
return V_34 ;
}
V_2 -> V_279 = V_34 ;
return 0 ;
}
static int F_100 ( struct V_37 * V_280 ,
const struct V_281 * V_282 )
{
struct V_1 * V_2 ;
struct V_283 * V_284 ;
struct V_285 * V_14 = & V_280 -> V_14 ;
struct V_286 V_287 = {} ;
const char * V_288 ;
int V_34 = 0 ;
T_4 V_17 ;
V_284 = F_101 ( V_280 -> V_14 . V_289 ) ;
if ( ! F_102 ( V_284 , V_290 ) ) {
F_27 ( & V_280 -> V_14 ,
L_94 ) ;
return - V_291 ;
}
V_2 = F_103 ( & V_280 -> V_14 , sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_37 = V_280 ;
F_104 ( V_280 , V_2 ) ;
V_2 -> V_14 = & V_280 -> V_14 ;
V_2 -> V_292 = V_293 ;
V_2 -> V_58 . V_294 = & V_2 -> V_292 ;
F_19 ( & V_2 -> V_64 ) ;
if ( ! F_105 ( V_14 , L_95 , & V_17 ) )
V_2 -> V_292 . V_295 = V_17 / 1000 ;
if ( ! F_105 ( V_14 , L_96 , & V_17 ) )
V_2 -> V_292 . V_296 = V_17 / 1000 ;
if ( ! F_105 ( V_14 , L_97 , & V_17 ) )
V_2 -> V_292 . V_297 = V_17 / 1000 ;
if ( ! F_105 ( V_14 , L_98 , & V_17 ) )
V_2 -> V_292 . V_298 = V_17 / 1000 ;
if ( F_106 ( V_14 , L_99 , & V_288 ) == 0 ) {
V_2 -> V_67 = F_107 ( V_288 ) ;
if ( ! V_2 -> V_67 )
return - V_299 ;
}
V_287 . V_300 = V_2 ;
V_2 -> V_137 = F_108 ( V_14 , & V_301 , & V_287 ) ;
if ( F_109 ( V_2 -> V_137 ) ) {
V_34 = F_110 ( V_2 -> V_137 ) ;
F_27 ( V_2 -> V_14 , L_100 , V_34 ) ;
return V_34 ;
}
V_34 = F_18 ( V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_197 = F_111 ( F_22 ( V_2 -> V_14 ) ) ;
if ( ! V_2 -> V_197 ) {
V_34 = - V_24 ;
goto V_302;
}
F_112 ( & V_2 -> V_193 , F_76 ) ;
F_79 ( & V_2 -> V_58 ) ;
V_2 -> V_135 = F_113 ( V_2 -> V_14 , L_101 ) ;
if ( F_109 ( V_2 -> V_135 ) ) {
V_34 = F_110 ( V_2 -> V_135 ) ;
goto V_303;
}
if ( V_280 -> V_242 ) {
V_2 -> V_279 = V_280 -> V_242 ;
} else {
V_34 = F_94 ( V_2 ) ;
if ( V_34 < 0 )
goto V_303;
}
V_2 -> V_200 = F_114 ( & V_280 -> V_14 , & V_2 -> V_58 ) ;
if ( F_109 ( V_2 -> V_200 ) ) {
V_34 = F_110 ( V_2 -> V_200 ) ;
F_12 ( V_2 , L_102 , V_34 ) ;
goto V_303;
}
V_34 = F_115 ( V_2 -> V_14 , V_2 -> V_279 ,
NULL , F_87 ,
V_304 | V_305 ,
L_103 , V_2 ) ;
if ( V_34 < 0 ) {
F_12 ( V_2 ,
L_93 , V_34 ) ;
goto V_306;
}
F_116 ( V_2 -> V_279 ) ;
return V_34 ;
V_306:
V_306 ( V_2 -> V_200 ) ;
V_303:
V_303 ( V_2 -> V_197 ) ;
V_302:
F_104 ( V_280 , NULL ) ;
F_23 ( V_2 ) ;
return V_34 ;
}
static int F_117 ( struct V_37 * V_280 )
{
struct V_1 * V_2 = F_118 ( V_280 ) ;
V_306 ( V_2 -> V_200 ) ;
V_303 ( V_2 -> V_197 ) ;
F_104 ( V_280 , NULL ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_119 ( struct V_285 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_307 ;
if ( F_26 ( & V_2 -> V_35 ) )
return - V_308 ;
F_30 ( & V_2 -> V_30 , 1 ) ;
return 0 ;
}
static int F_120 ( struct V_285 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_307 ;
F_30 ( & V_2 -> V_30 , 0 ) ;
return 0 ;
}
