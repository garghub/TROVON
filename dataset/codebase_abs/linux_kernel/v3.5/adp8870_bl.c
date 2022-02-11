static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_1 , V_3 ) ;
return V_5 ;
}
* V_4 = V_5 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
int V_5 = F_5 ( V_2 , V_3 , V_4 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_6 , L_2 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
T_1 V_10 ;
int V_5 ;
F_8 ( & V_9 -> V_11 ) ;
V_5 = F_1 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_5 && ( ( V_10 & V_7 ) != V_7 ) ) {
V_10 |= V_7 ;
V_5 = F_4 ( V_2 , V_3 , V_10 ) ;
}
F_9 ( & V_9 -> V_11 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
T_1 V_10 ;
int V_5 ;
F_8 ( & V_9 -> V_11 ) ;
V_5 = F_1 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_5 && ( V_10 & V_7 ) ) {
V_10 &= ~ V_7 ;
V_5 = F_4 ( V_2 , V_3 , V_10 ) ;
}
F_9 ( & V_9 -> V_11 ) ;
return V_5 ;
}
static void F_11 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_12 ( V_13 , struct V_14 , V_13 ) ;
F_4 ( V_15 -> V_2 , V_16 + V_15 -> V_17 - 1 ,
V_15 -> V_18 >> 1 ) ;
}
static void F_13 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
struct V_14 * V_15 ;
V_15 = F_12 ( V_20 , struct V_14 , V_23 ) ;
V_15 -> V_18 = V_22 ;
F_14 ( & V_15 -> V_13 ) ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
int V_5 = 0 ;
V_5 = F_4 ( V_2 , V_16 + V_15 -> V_17 - 1 , 0 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_2 , V_24 , 1 << ( V_15 -> V_17 - 1 ) ) ;
if ( V_5 )
return V_5 ;
if ( V_15 -> V_17 > 4 )
V_5 = F_6 ( V_2 , V_25 ,
( V_15 -> V_26 & 0x3 ) << ( ( V_15 -> V_17 - 5 ) * 2 ) ) ;
else
V_5 = F_6 ( V_2 , V_27 ,
( V_15 -> V_26 & 0x3 ) << ( ( V_15 -> V_17 - 1 ) * 2 ) ) ;
return V_5 ;
}
static int T_3 F_16 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
V_2 -> V_6 . V_30 ;
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_14 * V_15 , * V_31 ;
struct V_32 * V_33 ;
int V_5 , V_34 ;
V_15 = F_17 ( & V_2 -> V_6 , V_29 -> V_35 * sizeof( * V_15 ) ,
V_36 ) ;
if ( V_15 == NULL ) {
F_3 ( & V_2 -> V_6 , L_3 ) ;
return - V_37 ;
}
V_5 = F_4 ( V_2 , V_38 , V_29 -> V_39 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_25 ,
( V_29 -> V_40 & 0x3 ) << 6 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_41 ,
F_18 ( V_29 -> V_42 , V_29 -> V_43 ) ) ;
if ( V_5 )
return V_5 ;
for ( V_34 = 0 ; V_34 < V_29 -> V_35 ; ++ V_34 ) {
V_33 = & V_29 -> V_44 [ V_34 ] ;
V_31 = & V_15 [ V_34 ] ;
V_31 -> V_17 = V_33 -> V_26 & V_45 ;
if ( V_31 -> V_17 > 7 || V_31 -> V_17 < 1 ) {
F_3 ( & V_2 -> V_6 , L_4 ,
V_31 -> V_17 ) ;
goto V_46;
}
if ( V_29 -> V_47 & ( 1 << ( V_31 -> V_17 - 1 ) ) ) {
F_3 ( & V_2 -> V_6 , L_5 ,
V_31 -> V_17 ) ;
goto V_46;
}
V_31 -> V_23 . V_48 = V_33 -> V_48 ;
V_31 -> V_23 . V_49 = V_33 -> V_49 ;
V_31 -> V_23 . V_50 = F_13 ;
V_31 -> V_23 . V_51 = V_52 ;
V_31 -> V_26 = V_33 -> V_26 >> V_53 ;
V_31 -> V_2 = V_2 ;
V_31 -> V_18 = V_52 ;
F_19 ( & V_31 -> V_13 , F_11 ) ;
V_5 = F_20 ( & V_2 -> V_6 , & V_31 -> V_23 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_6 ,
V_31 -> V_17 ) ;
goto V_46;
}
V_5 = F_15 ( V_31 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_2 ) ;
V_34 ++ ;
goto V_46;
}
}
V_9 -> V_15 = V_15 ;
return 0 ;
V_46:
for ( V_34 = V_34 - 1 ; V_34 >= 0 ; -- V_34 ) {
F_21 ( & V_15 [ V_34 ] . V_23 ) ;
F_22 ( & V_15 [ V_34 ] . V_13 ) ;
}
return V_5 ;
}
static int T_4 F_23 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
V_2 -> V_6 . V_30 ;
struct V_8 * V_9 = F_7 ( V_2 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_29 -> V_35 ; V_34 ++ ) {
F_21 ( & V_9 -> V_15 [ V_34 ] . V_23 ) ;
F_22 ( & V_9 -> V_15 [ V_34 ] . V_13 ) ;
}
return 0 ;
}
static int T_3 F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_4 F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_24 ( struct V_54 * V_55 , int V_51 )
{
struct V_8 * V_9 = F_25 ( V_55 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_5 = 0 ;
if ( V_9 -> V_29 -> V_56 ) {
if ( ( V_51 > 0 ) && ( V_51 < V_57 ) ) {
V_5 = F_10 ( V_2 , V_58 ,
V_59 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_60 , V_51 ) ;
if ( V_5 )
return V_5 ;
} else {
V_5 = F_4 ( V_2 , V_60 ,
V_9 -> V_61 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_2 , V_58 ,
V_59 ) ;
if ( V_5 )
return V_5 ;
}
} else {
V_5 = F_4 ( V_2 , V_60 , V_51 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_9 -> V_62 && V_51 == 0 )
V_5 = F_6 ( V_2 ,
V_58 , V_63 ) ;
else if ( V_9 -> V_62 == 0 && V_51 )
V_5 = F_10 ( V_2 ,
V_58 , V_63 ) ;
if ( ! V_5 )
V_9 -> V_62 = V_51 ;
return V_5 ;
}
static int F_26 ( struct V_54 * V_55 )
{
int V_51 = V_55 -> V_64 . V_51 ;
if ( V_55 -> V_64 . V_65 != V_66 )
V_51 = 0 ;
if ( V_55 -> V_64 . V_67 != V_66 )
V_51 = 0 ;
return F_24 ( V_55 , V_51 ) ;
}
static int F_27 ( struct V_54 * V_55 )
{
struct V_8 * V_9 = F_25 ( V_55 ) ;
return V_9 -> V_62 ;
}
static int F_28 ( struct V_54 * V_55 )
{
struct V_8 * V_9 = F_25 ( V_55 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_28 * V_29 = V_9 -> V_29 ;
int V_5 = 0 ;
V_5 = F_4 ( V_2 , V_68 , ~ V_29 -> V_47 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_69 , V_29 -> V_70 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_60 , V_29 -> V_71 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_72 , V_29 -> V_73 ) ;
if ( V_5 )
return V_5 ;
if ( V_29 -> V_56 ) {
V_9 -> V_61 = V_29 -> V_71 ;
V_5 = F_4 ( V_2 , V_74 ,
V_29 -> V_75 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_76 ,
V_29 -> V_77 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_78 ,
V_29 -> V_79 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_80 ,
V_29 -> V_81 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_82 ,
V_29 -> V_83 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_84 ,
V_29 -> V_85 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_86 ,
V_29 -> V_87 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_88 ,
V_29 -> V_89 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_90 , V_29 -> V_91 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_92 , V_29 -> V_93 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_94 , V_29 -> V_95 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_96 , V_29 -> V_97 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_98 , V_29 -> V_99 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_100 , V_29 -> V_101 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_102 , V_29 -> V_103 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_104 , V_29 -> V_105 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_106 , V_107 | V_108 |
V_109 | V_110 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_111 ,
F_29 ( V_29 -> V_112 ) ) ;
if ( V_5 )
return V_5 ;
}
V_5 = F_4 ( V_2 , V_113 ,
F_30 ( V_29 -> V_114 , 0 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_115 , F_18 ( V_29 -> V_116 ,
V_29 -> V_117 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_2 , V_58 , V_118 | V_63 | V_119 |
( V_9 -> V_120 == 0 ? V_121 : 0 ) ) ;
return V_5 ;
}
static T_5 F_31 ( struct V_122 * V_6 , char * V_123 , int V_3 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
int error ;
T_1 V_10 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_3 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
return sprintf ( V_123 , L_7 , V_10 ) ;
}
static T_5 F_33 ( struct V_122 * V_6 , const char * V_123 ,
T_6 V_124 , int V_3 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
unsigned long V_4 ;
int V_5 ;
V_5 = F_34 ( V_123 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_9 -> V_11 ) ;
F_4 ( V_9 -> V_2 , V_3 , V_4 ) ;
F_9 ( & V_9 -> V_11 ) ;
return V_124 ;
}
static T_5 F_35 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_86 ) ;
}
static T_5 F_36 ( struct V_122 * V_6 ,
struct V_125 * V_126 , const char * V_123 , T_6 V_124 )
{
return F_33 ( V_6 , V_123 , V_124 , V_86 ) ;
}
static T_5 F_37 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_82 ) ;
}
static T_5 F_38 ( struct V_122 * V_6 ,
struct V_125 * V_126 , const char * V_123 , T_6 V_124 )
{
return F_33 ( V_6 , V_123 , V_124 , V_82 ) ;
}
static T_5 F_39 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_78 ) ;
}
static T_5 F_40 ( struct V_122 * V_6 ,
struct V_125 * V_126 , const char * V_123 , T_6 V_124 )
{
return F_33 ( V_6 , V_123 , V_124 , V_78 ) ;
}
static T_5 F_41 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_74 ) ;
}
static T_5 F_42 ( struct V_122 * V_6 ,
struct V_125 * V_126 , const char * V_123 , T_6 V_124 )
{
return F_33 ( V_6 , V_123 , V_124 , V_74 ) ;
}
static T_5 F_43 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_60 ) ;
}
static T_5 F_44 ( struct V_122 * V_6 ,
struct V_125 * V_126 , const char * V_123 , T_6 V_124 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
int V_5 = F_34 ( V_123 , 10 , & V_9 -> V_61 ) ;
if ( V_5 )
return V_5 ;
return F_33 ( V_6 , V_123 , V_124 , V_60 ) ;
}
static T_5 F_45 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_88 ) ;
}
static T_5 F_46 ( struct V_122 * V_6 ,
struct V_125 * V_126 ,
const char * V_123 , T_6 V_124 )
{
return F_33 ( V_6 , V_123 , V_124 , V_88 ) ;
}
static T_5 F_47 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_84 ) ;
}
static T_5 F_48 ( struct V_122 * V_6 ,
struct V_125 * V_126 ,
const char * V_123 , T_6 V_124 )
{
return F_33 ( V_6 , V_123 , V_124 , V_84 ) ;
}
static T_5 F_49 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_80 ) ;
}
static T_5 F_50 ( struct V_122 * V_6 ,
struct V_125 * V_126 ,
const char * V_123 , T_6 V_124 )
{
return F_33 ( V_6 , V_123 , V_124 , V_80 ) ;
}
static T_5 F_51 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_76 ) ;
}
static T_5 F_52 ( struct V_122 * V_6 ,
struct V_125 * V_126 ,
const char * V_123 , T_6 V_124 )
{
return F_33 ( V_6 , V_123 , V_124 , V_76 ) ;
}
static T_5 F_53 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
return F_31 ( V_6 , V_123 , V_72 ) ;
}
static T_5 F_54 ( struct V_122 * V_6 ,
struct V_125 * V_126 ,
const char * V_123 , T_6 V_124 )
{
return F_33 ( V_6 , V_123 , V_124 , V_72 ) ;
}
static T_5 F_55 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
int error ;
T_1 V_10 ;
T_7 V_127 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_128 , & V_10 ) ;
if ( error < 0 ) {
F_9 ( & V_9 -> V_11 ) ;
return error ;
}
V_127 = V_10 ;
error = F_1 ( V_9 -> V_2 , V_129 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
V_127 += ( V_10 & 0x1F ) << 8 ;
return sprintf ( V_123 , L_7 , V_127 ) ;
}
static T_5 F_56 ( struct V_122 * V_6 ,
struct V_125 * V_126 , char * V_123 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
int error ;
T_1 V_10 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_113 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
return sprintf ( V_123 , L_7 ,
( ( V_10 >> V_130 ) & V_131 ) + 1 ) ;
}
static T_5 F_57 ( struct V_122 * V_6 ,
struct V_125 * V_126 ,
const char * V_123 , T_6 V_124 )
{
struct V_8 * V_9 = F_32 ( V_6 ) ;
unsigned long V_4 ;
T_1 V_10 ;
int V_5 ;
V_5 = F_34 ( V_123 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 == 0 ) {
F_6 ( V_9 -> V_2 , V_58 , V_59 ) ;
} else if ( ( V_4 > 0 ) && ( V_4 < 6 ) ) {
F_10 ( V_9 -> V_2 , V_58 , V_59 ) ;
F_8 ( & V_9 -> V_11 ) ;
F_1 ( V_9 -> V_2 , V_113 , & V_10 ) ;
V_10 &= ~ ( V_131 << V_130 ) ;
V_10 |= ( V_4 - 1 ) << V_130 ;
F_4 ( V_9 -> V_2 , V_113 , V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
}
return V_124 ;
}
static int T_3 F_58 ( struct V_1 * V_2 ,
const struct V_132 * V_17 )
{
struct V_133 V_64 ;
struct V_54 * V_55 ;
struct V_8 * V_9 ;
struct V_28 * V_29 =
V_2 -> V_6 . V_30 ;
T_1 V_10 ;
int V_5 ;
if ( ! F_59 ( V_2 -> V_134 ,
V_135 ) ) {
F_3 ( & V_2 -> V_6 , L_8 ) ;
return - V_136 ;
}
if ( ! V_29 ) {
F_3 ( & V_2 -> V_6 , L_9 ) ;
return - V_137 ;
}
V_5 = F_1 ( V_2 , V_138 , & V_10 ) ;
if ( V_5 < 0 )
return - V_136 ;
if ( F_60 ( V_10 ) != V_139 ) {
F_3 ( & V_2 -> V_6 , L_10 ) ;
return - V_140 ;
}
V_9 = F_17 ( & V_2 -> V_6 , sizeof( * V_9 ) , V_36 ) ;
if ( V_9 == NULL )
return - V_37 ;
V_9 -> V_120 = F_61 ( V_10 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_29 = V_29 ;
V_9 -> V_17 = V_17 -> V_141 ;
V_9 -> V_62 = 0 ;
F_62 ( V_2 , V_9 ) ;
F_63 ( & V_9 -> V_11 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . type = V_142 ;
V_64 . V_143 = V_64 . V_51 = V_57 ;
V_55 = F_64 ( F_65 ( & V_2 -> V_6 ) ,
& V_2 -> V_6 , V_9 , & V_144 , & V_64 ) ;
if ( F_66 ( V_55 ) ) {
F_3 ( & V_2 -> V_6 , L_11 ) ;
return F_67 ( V_55 ) ;
}
V_9 -> V_55 = V_55 ;
if ( V_29 -> V_56 )
V_5 = F_68 ( & V_55 -> V_6 . V_145 ,
& V_146 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_12 ) ;
goto V_147;
}
V_5 = F_28 ( V_55 ) ;
if ( V_5 ) {
V_5 = - V_136 ;
goto V_148;
}
F_69 ( V_55 ) ;
F_70 ( & V_2 -> V_6 , L_13 , V_9 -> V_120 ) ;
if ( V_29 -> V_35 )
F_16 ( V_2 ) ;
return 0 ;
V_148:
if ( V_9 -> V_29 -> V_56 )
F_71 ( & V_9 -> V_55 -> V_6 . V_145 ,
& V_146 ) ;
V_147:
F_72 ( V_55 ) ;
return V_5 ;
}
static int T_4 F_73 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
F_10 ( V_2 , V_58 , V_119 ) ;
if ( V_9 -> V_15 )
F_23 ( V_2 ) ;
if ( V_9 -> V_29 -> V_56 )
F_71 ( & V_9 -> V_55 -> V_6 . V_145 ,
& V_146 ) ;
F_72 ( V_9 -> V_55 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , T_8 V_149 )
{
F_10 ( V_2 , V_58 , V_119 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_58 , V_119 ) ;
return 0 ;
}
