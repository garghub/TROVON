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
static int F_16 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
F_17 ( & V_2 -> V_6 ) ;
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_14 * V_15 , * V_30 ;
struct V_31 * V_32 ;
int V_5 , V_33 ;
V_15 = F_18 ( & V_2 -> V_6 , V_29 -> V_34 * sizeof( * V_15 ) ,
V_35 ) ;
if ( V_15 == NULL )
return - V_36 ;
V_5 = F_4 ( V_2 , V_37 , V_29 -> V_38 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_25 ,
( V_29 -> V_39 & 0x3 ) << 6 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_40 ,
F_19 ( V_29 -> V_41 , V_29 -> V_42 ) ) ;
if ( V_5 )
return V_5 ;
for ( V_33 = 0 ; V_33 < V_29 -> V_34 ; ++ V_33 ) {
V_32 = & V_29 -> V_43 [ V_33 ] ;
V_30 = & V_15 [ V_33 ] ;
V_30 -> V_17 = V_32 -> V_26 & V_44 ;
if ( V_30 -> V_17 > 7 || V_30 -> V_17 < 1 ) {
F_3 ( & V_2 -> V_6 , L_3 ,
V_30 -> V_17 ) ;
V_5 = - V_45 ;
goto V_46;
}
if ( V_29 -> V_47 & ( 1 << ( V_30 -> V_17 - 1 ) ) ) {
F_3 ( & V_2 -> V_6 , L_4 ,
V_30 -> V_17 ) ;
V_5 = - V_48 ;
goto V_46;
}
V_30 -> V_23 . V_49 = V_32 -> V_49 ;
V_30 -> V_23 . V_50 = V_32 -> V_50 ;
V_30 -> V_23 . V_51 = F_13 ;
V_30 -> V_23 . V_52 = V_53 ;
V_30 -> V_26 = V_32 -> V_26 >> V_54 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_18 = V_53 ;
F_20 ( & V_30 -> V_13 , F_11 ) ;
V_5 = F_21 ( & V_2 -> V_6 , & V_30 -> V_23 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_5 ,
V_30 -> V_17 ) ;
goto V_46;
}
V_5 = F_15 ( V_30 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_2 ) ;
V_33 ++ ;
goto V_46;
}
}
V_9 -> V_15 = V_15 ;
return 0 ;
V_46:
for ( V_33 = V_33 - 1 ; V_33 >= 0 ; -- V_33 ) {
F_22 ( & V_15 [ V_33 ] . V_23 ) ;
F_23 ( & V_15 [ V_33 ] . V_13 ) ;
}
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
F_17 ( & V_2 -> V_6 ) ;
struct V_8 * V_9 = F_7 ( V_2 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_29 -> V_34 ; V_33 ++ ) {
F_22 ( & V_9 -> V_15 [ V_33 ] . V_23 ) ;
F_23 ( & V_9 -> V_15 [ V_33 ] . V_13 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_25 ( struct V_55 * V_56 , int V_52 )
{
struct V_8 * V_9 = F_26 ( V_56 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_5 = 0 ;
if ( V_9 -> V_29 -> V_57 ) {
if ( ( V_52 > 0 ) && ( V_52 < V_58 ) ) {
V_5 = F_10 ( V_2 , V_59 ,
V_60 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_61 , V_52 ) ;
if ( V_5 )
return V_5 ;
} else {
V_5 = F_4 ( V_2 , V_61 ,
V_9 -> V_62 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_2 , V_59 ,
V_60 ) ;
if ( V_5 )
return V_5 ;
}
} else {
V_5 = F_4 ( V_2 , V_61 , V_52 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_9 -> V_63 && V_52 == 0 )
V_5 = F_6 ( V_2 ,
V_59 , V_64 ) ;
else if ( V_9 -> V_63 == 0 && V_52 )
V_5 = F_10 ( V_2 ,
V_59 , V_64 ) ;
if ( ! V_5 )
V_9 -> V_63 = V_52 ;
return V_5 ;
}
static int F_27 ( struct V_55 * V_56 )
{
int V_52 = V_56 -> V_65 . V_52 ;
if ( V_56 -> V_65 . V_66 != V_67 )
V_52 = 0 ;
if ( V_56 -> V_65 . V_68 != V_67 )
V_52 = 0 ;
return F_25 ( V_56 , V_52 ) ;
}
static int F_28 ( struct V_55 * V_56 )
{
struct V_8 * V_9 = F_26 ( V_56 ) ;
return V_9 -> V_63 ;
}
static int F_29 ( struct V_55 * V_56 )
{
struct V_8 * V_9 = F_26 ( V_56 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_28 * V_29 = V_9 -> V_29 ;
int V_5 = 0 ;
V_5 = F_4 ( V_2 , V_69 , ~ V_29 -> V_47 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_70 , V_29 -> V_71 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_61 , V_29 -> V_72 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_73 , V_29 -> V_74 ) ;
if ( V_5 )
return V_5 ;
if ( V_29 -> V_57 ) {
V_9 -> V_62 = V_29 -> V_72 ;
V_5 = F_4 ( V_2 , V_75 ,
V_29 -> V_76 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_77 ,
V_29 -> V_78 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_79 ,
V_29 -> V_80 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_81 ,
V_29 -> V_82 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_83 ,
V_29 -> V_84 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_85 ,
V_29 -> V_86 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_87 ,
V_29 -> V_88 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_89 ,
V_29 -> V_90 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_91 , V_29 -> V_92 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_93 , V_29 -> V_94 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_95 , V_29 -> V_96 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_97 , V_29 -> V_98 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_99 , V_29 -> V_100 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_101 , V_29 -> V_102 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_103 , V_29 -> V_104 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_105 , V_29 -> V_106 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_107 , V_108 | V_109 |
V_110 | V_111 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_112 ,
F_30 ( V_29 -> V_113 ) ) ;
if ( V_5 )
return V_5 ;
}
V_5 = F_4 ( V_2 , V_114 ,
F_31 ( V_29 -> V_115 , 0 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_116 , F_19 ( V_29 -> V_117 ,
V_29 -> V_118 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_2 , V_59 , V_119 | V_64 | V_120 |
( V_9 -> V_121 == 0 ? V_122 : 0 ) ) ;
return V_5 ;
}
static T_3 F_32 ( struct V_123 * V_6 , char * V_124 , int V_3 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
int error ;
T_1 V_10 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_3 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
return sprintf ( V_124 , L_6 , V_10 ) ;
}
static T_3 F_34 ( struct V_123 * V_6 , const char * V_124 ,
T_4 V_125 , int V_3 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
unsigned long V_4 ;
int V_5 ;
V_5 = F_35 ( V_124 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_9 -> V_11 ) ;
F_4 ( V_9 -> V_2 , V_3 , V_4 ) ;
F_9 ( & V_9 -> V_11 ) ;
return V_125 ;
}
static T_3 F_36 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_87 ) ;
}
static T_3 F_37 ( struct V_123 * V_6 ,
struct V_126 * V_127 , const char * V_124 , T_4 V_125 )
{
return F_34 ( V_6 , V_124 , V_125 , V_87 ) ;
}
static T_3 F_38 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_83 ) ;
}
static T_3 F_39 ( struct V_123 * V_6 ,
struct V_126 * V_127 , const char * V_124 , T_4 V_125 )
{
return F_34 ( V_6 , V_124 , V_125 , V_83 ) ;
}
static T_3 F_40 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_79 ) ;
}
static T_3 F_41 ( struct V_123 * V_6 ,
struct V_126 * V_127 , const char * V_124 , T_4 V_125 )
{
return F_34 ( V_6 , V_124 , V_125 , V_79 ) ;
}
static T_3 F_42 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_75 ) ;
}
static T_3 F_43 ( struct V_123 * V_6 ,
struct V_126 * V_127 , const char * V_124 , T_4 V_125 )
{
return F_34 ( V_6 , V_124 , V_125 , V_75 ) ;
}
static T_3 F_44 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_61 ) ;
}
static T_3 F_45 ( struct V_123 * V_6 ,
struct V_126 * V_127 , const char * V_124 , T_4 V_125 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
int V_5 = F_35 ( V_124 , 10 , & V_9 -> V_62 ) ;
if ( V_5 )
return V_5 ;
return F_34 ( V_6 , V_124 , V_125 , V_61 ) ;
}
static T_3 F_46 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_89 ) ;
}
static T_3 F_47 ( struct V_123 * V_6 ,
struct V_126 * V_127 ,
const char * V_124 , T_4 V_125 )
{
return F_34 ( V_6 , V_124 , V_125 , V_89 ) ;
}
static T_3 F_48 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_85 ) ;
}
static T_3 F_49 ( struct V_123 * V_6 ,
struct V_126 * V_127 ,
const char * V_124 , T_4 V_125 )
{
return F_34 ( V_6 , V_124 , V_125 , V_85 ) ;
}
static T_3 F_50 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_81 ) ;
}
static T_3 F_51 ( struct V_123 * V_6 ,
struct V_126 * V_127 ,
const char * V_124 , T_4 V_125 )
{
return F_34 ( V_6 , V_124 , V_125 , V_81 ) ;
}
static T_3 F_52 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_77 ) ;
}
static T_3 F_53 ( struct V_123 * V_6 ,
struct V_126 * V_127 ,
const char * V_124 , T_4 V_125 )
{
return F_34 ( V_6 , V_124 , V_125 , V_77 ) ;
}
static T_3 F_54 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
return F_32 ( V_6 , V_124 , V_73 ) ;
}
static T_3 F_55 ( struct V_123 * V_6 ,
struct V_126 * V_127 ,
const char * V_124 , T_4 V_125 )
{
return F_34 ( V_6 , V_124 , V_125 , V_73 ) ;
}
static T_3 F_56 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
int error ;
T_1 V_10 ;
T_5 V_128 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_129 , & V_10 ) ;
if ( error < 0 ) {
F_9 ( & V_9 -> V_11 ) ;
return error ;
}
V_128 = V_10 ;
error = F_1 ( V_9 -> V_2 , V_130 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
V_128 += ( V_10 & 0x1F ) << 8 ;
return sprintf ( V_124 , L_6 , V_128 ) ;
}
static T_3 F_57 ( struct V_123 * V_6 ,
struct V_126 * V_127 , char * V_124 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
int error ;
T_1 V_10 ;
F_8 ( & V_9 -> V_11 ) ;
error = F_1 ( V_9 -> V_2 , V_114 , & V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
if ( error < 0 )
return error ;
return sprintf ( V_124 , L_6 ,
( ( V_10 >> V_131 ) & V_132 ) + 1 ) ;
}
static T_3 F_58 ( struct V_123 * V_6 ,
struct V_126 * V_127 ,
const char * V_124 , T_4 V_125 )
{
struct V_8 * V_9 = F_33 ( V_6 ) ;
unsigned long V_4 ;
T_1 V_10 ;
int V_5 ;
V_5 = F_35 ( V_124 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 == 0 ) {
F_6 ( V_9 -> V_2 , V_59 , V_60 ) ;
} else if ( ( V_4 > 0 ) && ( V_4 < 6 ) ) {
F_10 ( V_9 -> V_2 , V_59 , V_60 ) ;
F_8 ( & V_9 -> V_11 ) ;
F_1 ( V_9 -> V_2 , V_114 , & V_10 ) ;
V_10 &= ~ ( V_132 << V_131 ) ;
V_10 |= ( V_4 - 1 ) << V_131 ;
F_4 ( V_9 -> V_2 , V_114 , V_10 ) ;
F_9 ( & V_9 -> V_11 ) ;
}
return V_125 ;
}
static int F_59 ( struct V_1 * V_2 ,
const struct V_133 * V_17 )
{
struct V_134 V_65 ;
struct V_55 * V_56 ;
struct V_8 * V_9 ;
struct V_28 * V_29 =
F_17 ( & V_2 -> V_6 ) ;
T_1 V_10 ;
int V_5 ;
if ( ! F_60 ( V_2 -> V_135 ,
V_136 ) ) {
F_3 ( & V_2 -> V_6 , L_7 ) ;
return - V_137 ;
}
if ( ! V_29 ) {
F_3 ( & V_2 -> V_6 , L_8 ) ;
return - V_45 ;
}
V_5 = F_1 ( V_2 , V_138 , & V_10 ) ;
if ( V_5 < 0 )
return - V_137 ;
if ( F_61 ( V_10 ) != V_139 ) {
F_3 ( & V_2 -> V_6 , L_9 ) ;
return - V_140 ;
}
V_9 = F_18 ( & V_2 -> V_6 , sizeof( * V_9 ) , V_35 ) ;
if ( V_9 == NULL )
return - V_36 ;
V_9 -> V_121 = F_62 ( V_10 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_29 = V_29 ;
V_9 -> V_17 = V_17 -> V_141 ;
V_9 -> V_63 = 0 ;
F_63 ( V_2 , V_9 ) ;
F_64 ( & V_9 -> V_11 ) ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . type = V_142 ;
V_65 . V_143 = V_65 . V_52 = V_58 ;
V_56 = F_65 ( & V_2 -> V_6 ,
F_66 ( & V_2 -> V_6 ) ,
& V_2 -> V_6 , V_9 , & V_144 , & V_65 ) ;
if ( F_67 ( V_56 ) ) {
F_3 ( & V_2 -> V_6 , L_10 ) ;
return F_68 ( V_56 ) ;
}
V_9 -> V_56 = V_56 ;
if ( V_29 -> V_57 ) {
V_5 = F_69 ( & V_56 -> V_6 . V_145 ,
& V_146 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_11 ) ;
return V_5 ;
}
}
V_5 = F_29 ( V_56 ) ;
if ( V_5 ) {
V_5 = - V_137 ;
goto V_147;
}
F_70 ( V_56 ) ;
F_71 ( & V_2 -> V_6 , L_12 , V_9 -> V_121 ) ;
if ( V_29 -> V_34 )
F_16 ( V_2 ) ;
return 0 ;
V_147:
if ( V_9 -> V_29 -> V_57 )
F_72 ( & V_9 -> V_56 -> V_6 . V_145 ,
& V_146 ) ;
return V_5 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
F_10 ( V_2 , V_59 , V_120 ) ;
if ( V_9 -> V_15 )
F_24 ( V_2 ) ;
if ( V_9 -> V_29 -> V_57 )
F_72 ( & V_9 -> V_56 -> V_6 . V_145 ,
& V_146 ) ;
return 0 ;
}
static int F_74 ( struct V_123 * V_6 )
{
struct V_1 * V_2 = F_75 ( V_6 ) ;
F_10 ( V_2 , V_59 , V_120 ) ;
return 0 ;
}
static int F_76 ( struct V_123 * V_6 )
{
struct V_1 * V_2 = F_75 ( V_6 ) ;
F_6 ( V_2 , V_59 , V_120 | V_119 ) ;
return 0 ;
}
