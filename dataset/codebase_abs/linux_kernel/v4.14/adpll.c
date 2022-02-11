static const char * F_1 ( struct V_1 * V_2 ,
int V_3 ,
const char * V_4 )
{
const char * V_5 ;
int V_6 ;
if ( V_3 >= 0 ) {
V_6 = F_2 ( V_2 -> V_7 ,
L_1 ,
V_3 ,
& V_5 ) ;
if ( V_6 )
return NULL ;
} else {
const char * V_8 = L_2 ;
char * V_9 ;
V_9 = F_3 ( V_2 -> V_10 , 8 + 1 + strlen ( V_8 ) + 1 +
strlen ( V_4 ) , V_11 ) ;
if ( ! V_9 )
return NULL ;
sprintf ( V_9 , L_3 , V_2 -> V_12 , V_8 , V_4 ) ;
V_5 = V_9 ;
}
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_13 * clock ,
int V_14 , int V_3 , const char * V_5 ,
void (* F_5)( struct V_13 * V_13 ) )
{
struct V_15 * V_16 ;
const char * V_4 = NULL ;
char V_17 [ V_18 ] ;
V_2 -> V_19 [ V_14 ] . V_13 = clock ;
V_2 -> V_19 [ V_14 ] . F_5 = F_5 ;
V_4 = strrchr ( V_5 , '.' ) ;
if ( V_4 && strlen ( V_4 ) > 1 ) {
if ( strlen ( V_4 ) > V_18 )
F_6 ( V_2 -> V_10 , L_4 ,
V_5 ) ;
snprintf ( V_17 , 16 , L_5 , V_2 -> V_12 & 0xfff , V_4 + 1 ) ;
V_16 = F_7 ( clock , V_17 , NULL ) ;
if ( ! V_16 )
return - V_20 ;
V_2 -> V_19 [ V_14 ] . V_16 = V_16 ;
} else {
F_6 ( V_2 -> V_10 , L_6 , V_5 ) ;
}
if ( V_3 < 0 )
return 0 ;
V_2 -> V_21 . V_22 [ V_3 ] = clock ;
V_2 -> V_21 . V_23 ++ ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
enum V_24 V_14 ,
int V_3 , char * V_5 ,
struct V_13 * V_25 ,
void T_1 * V_26 ,
T_2 V_27 , T_2 V_28 ,
T_2 V_29 )
{
const char * V_30 ;
const char * V_31 ;
struct V_13 * clock ;
V_30 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( ! V_30 )
return - V_32 ;
V_31 = F_9 ( V_25 ) ;
clock = F_10 ( V_2 -> V_10 , V_30 , V_31 , 0 ,
V_26 , V_27 , V_28 , V_29 ,
& V_2 -> V_33 ) ;
if ( F_11 ( clock ) ) {
F_12 ( V_2 -> V_10 , L_7 ,
V_5 , F_13 ( clock ) ) ;
return F_13 ( clock ) ;
}
return F_4 ( V_2 , clock , V_14 , V_3 , V_30 ,
V_34 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_24 V_14 ,
char * V_5 , struct V_13 * V_35 ,
struct V_13 * V_36 ,
void T_1 * V_26 ,
T_2 V_27 )
{
const char * V_30 ;
const char * V_37 [ 2 ] ;
struct V_13 * clock ;
V_30 = F_1 ( V_2 , - V_38 , V_5 ) ;
if ( ! V_30 )
return - V_20 ;
V_37 [ 0 ] = F_9 ( V_35 ) ;
V_37 [ 1 ] = F_9 ( V_36 ) ;
clock = F_15 ( V_2 -> V_10 , V_30 , V_37 , 2 , 0 ,
V_26 , V_27 , 1 , 0 , & V_2 -> V_33 ) ;
if ( F_11 ( clock ) ) {
F_12 ( V_2 -> V_10 , L_8 ,
V_5 , F_13 ( clock ) ) ;
return F_13 ( clock ) ;
}
return F_4 ( V_2 , clock , V_14 , - V_38 , V_30 ,
V_39 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_24 V_14 ,
int V_3 , char * V_5 ,
struct V_13 * V_25 ,
void T_1 * V_26 ,
T_2 V_40 ,
T_2 V_41 )
{
const char * V_30 ;
const char * V_31 ;
struct V_13 * clock ;
V_30 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( ! V_30 )
return - V_32 ;
V_31 = F_9 ( V_25 ) ;
clock = F_17 ( V_2 -> V_10 , V_30 , V_31 , 0 ,
V_26 , V_40 , V_41 ,
& V_2 -> V_33 ) ;
if ( F_11 ( clock ) ) {
F_12 ( V_2 -> V_10 , L_9 ,
V_5 , F_13 ( clock ) ) ;
return F_13 ( clock ) ;
}
return F_4 ( V_2 , clock , V_14 , V_3 , V_30 ,
V_42 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_24 V_14 ,
char * V_5 ,
struct V_13 * V_25 ,
unsigned int V_43 ,
unsigned int div )
{
const char * V_30 ;
const char * V_31 ;
struct V_13 * clock ;
V_30 = F_1 ( V_2 , - V_38 , V_5 ) ;
if ( ! V_30 )
return - V_20 ;
V_31 = F_9 ( V_25 ) ;
clock = F_19 ( V_2 -> V_10 , V_30 , V_31 ,
0 , V_43 , div ) ;
if ( F_11 ( clock ) )
return F_13 ( clock ) ;
return F_4 ( V_2 , clock , V_14 , - V_38 , V_30 ,
V_44 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
T_3 V_46 ;
F_21 ( & V_2 -> V_33 , V_45 ) ;
V_46 = F_22 ( V_2 -> V_47 + V_48 ) ;
V_46 |= F_23 ( V_49 ) ;
F_24 ( V_46 , V_2 -> V_47 + V_48 ) ;
F_25 ( & V_2 -> V_33 , V_45 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
T_3 V_46 ;
F_21 ( & V_2 -> V_33 , V_45 ) ;
V_46 = F_22 ( V_2 -> V_47 + V_48 ) ;
V_46 &= ~ F_23 ( V_49 ) ;
F_24 ( V_46 , V_2 -> V_47 + V_48 ) ;
F_25 ( & V_2 -> V_33 , V_45 ) ;
}
static bool F_27 ( struct V_1 * V_2 )
{
T_3 V_46 ;
V_46 = F_22 ( V_2 -> V_47 + V_50 ) ;
return V_46 & F_23 ( V_51 ) ;
}
static bool F_28 ( struct V_1 * V_2 )
{
T_3 V_46 = F_22 ( V_2 -> V_47 + V_50 ) ;
return ( V_46 & V_52 ) == V_52 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_53 = V_54 ;
do {
if ( F_28 ( V_2 ) )
return 0 ;
F_30 ( 200 , 300 ) ;
} while ( V_53 -- );
F_12 ( V_2 -> V_10 , L_10 ) ;
return - V_55 ;
}
static int F_31 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_32 ( V_57 ) ;
struct V_1 * V_2 = F_33 ( V_59 ) ;
F_26 ( V_2 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static void F_34 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_32 ( V_57 ) ;
struct V_1 * V_2 = F_33 ( V_59 ) ;
F_20 ( V_2 ) ;
}
static int F_35 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_32 ( V_57 ) ;
struct V_1 * V_2 = F_33 ( V_59 ) ;
return F_28 ( V_2 ) ;
}
static unsigned long F_36 ( struct V_56 * V_57 ,
unsigned long V_60 )
{
struct V_58 * V_59 = F_32 ( V_57 ) ;
struct V_1 * V_2 = F_33 ( V_59 ) ;
T_3 V_61 , V_62 , V_46 ;
T_4 V_63 ;
unsigned long V_45 ;
if ( F_27 ( V_2 ) )
return 0 ;
F_21 ( & V_2 -> V_33 , V_45 ) ;
V_61 = F_22 ( V_2 -> V_47 + V_64 ) ;
V_61 &= V_65 ;
V_63 = ( T_4 ) F_37 ( V_2 -> V_47 + V_66 ) << 18 ;
V_63 += V_61 ;
V_63 *= V_60 ;
V_62 = ( F_37 ( V_2 -> V_47 + V_67 ) + 1 ) << 18 ;
F_25 ( & V_2 -> V_33 , V_45 ) ;
F_38 ( V_63 , V_62 ) ;
if ( V_2 -> V_68 -> V_69 ) {
V_46 = F_22 ( V_2 -> V_47 + V_48 ) ;
if ( V_46 & F_23 ( V_70 ) )
V_63 *= 4 ;
V_63 *= 2 ;
}
return V_63 ;
}
static T_2 F_39 ( struct V_56 * V_57 )
{
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_71 V_72 ;
struct V_13 * clock ;
const char * V_4 ;
int V_28 , V_6 ;
V_2 -> V_21 . V_22 = F_3 ( V_2 -> V_10 , sizeof( struct V_13 * ) *
V_73 ,
V_11 ) ;
if ( ! V_2 -> V_21 . V_22 )
return - V_20 ;
if ( V_2 -> V_68 -> V_3 < 0 )
V_4 = L_11 ;
else
V_4 = NULL ;
V_72 . V_5 = F_1 ( V_2 , V_2 -> V_68 -> V_3 , V_4 ) ;
if ( ! V_72 . V_5 )
return - V_32 ;
V_72 . V_74 = V_2 -> V_74 ;
V_72 . V_75 = V_2 -> V_68 -> V_76 ;
V_72 . V_77 = & V_78 ;
V_72 . V_45 = V_79 ;
V_2 -> V_59 . V_57 . V_72 = & V_72 ;
if ( V_2 -> V_68 -> V_69 )
V_28 = 5 ;
else
V_28 = 4 ;
V_6 = F_8 ( V_2 , V_80 , - V_38 , L_12 ,
V_2 -> V_81 [ V_82 ] ,
V_2 -> V_47 + V_66 ,
V_83 , V_28 , 0 ) ;
if ( V_6 )
return V_6 ;
clock = F_41 ( V_2 -> V_10 , & V_2 -> V_59 . V_57 ) ;
if ( F_11 ( clock ) )
return F_13 ( clock ) ;
return F_4 ( V_2 , clock , V_84 , V_2 -> V_68 -> V_3 ,
V_72 . V_5 , NULL ) ;
}
static int F_42 ( struct V_56 * V_57 )
{
struct V_85 * V_86 = F_43 ( V_57 ) ;
struct V_56 * V_87 = & V_86 -> V_88 . V_57 ;
F_44 ( V_87 , V_57 ) ;
return V_89 . V_90 ( V_87 ) ;
}
static void F_45 ( struct V_56 * V_57 )
{
struct V_85 * V_86 = F_43 ( V_57 ) ;
struct V_56 * V_87 = & V_86 -> V_88 . V_57 ;
F_44 ( V_87 , V_57 ) ;
V_89 . V_91 ( V_87 ) ;
}
static int F_46 ( struct V_56 * V_57 )
{
struct V_85 * V_86 = F_43 ( V_57 ) ;
struct V_56 * V_87 = & V_86 -> V_88 . V_57 ;
F_44 ( V_87 , V_57 ) ;
return V_89 . V_92 ( V_87 ) ;
}
static T_2 F_47 ( struct V_56 * V_57 )
{
struct V_85 * V_86 = F_43 ( V_57 ) ;
struct V_1 * V_2 = V_86 -> V_93 ;
return F_27 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
enum V_24 V_14 ,
int V_3 , int V_94 ,
char * V_5 , struct V_13 * V_35 ,
struct V_13 * V_36 )
{
struct V_85 * V_86 ;
struct V_71 V_72 ;
struct V_95 * V_77 ;
const char * V_74 [ 2 ] ;
const char * V_30 ;
struct V_13 * clock ;
int V_6 ;
V_86 = F_3 ( V_2 -> V_10 , sizeof( * V_86 ) , V_11 ) ;
if ( ! V_86 )
return - V_20 ;
V_86 -> V_93 = V_2 ;
V_6 = F_2 ( V_2 -> V_7 ,
L_1 ,
V_3 ,
& V_30 ) ;
if ( V_6 )
return V_6 ;
V_77 = F_3 ( V_2 -> V_10 , sizeof( * V_77 ) , V_11 ) ;
if ( ! V_77 )
return - V_20 ;
V_72 . V_5 = V_30 ;
V_72 . V_77 = V_77 ;
V_72 . V_45 = V_96 ;
V_86 -> V_57 . V_72 = & V_72 ;
V_74 [ 0 ] = F_9 ( V_35 ) ;
V_74 [ 1 ] = F_9 ( V_36 ) ;
V_72 . V_74 = V_74 ;
V_72 . V_75 = 2 ;
V_77 -> V_97 = F_47 ;
V_77 -> V_98 = V_99 ;
if ( V_94 ) {
V_86 -> V_88 . V_33 = & V_2 -> V_33 ;
V_86 -> V_88 . V_26 = V_2 -> V_47 + V_48 ;
V_86 -> V_88 . V_40 = V_94 ;
V_77 -> V_90 = F_42 ;
V_77 -> V_91 = F_45 ;
V_77 -> V_92 = F_46 ;
}
clock = F_41 ( V_2 -> V_10 , & V_86 -> V_57 ) ;
if ( F_11 ( clock ) ) {
F_12 ( V_2 -> V_10 , L_13 ,
V_5 , F_13 ( clock ) ) ;
return F_13 ( clock ) ;
}
return F_4 ( V_2 , clock , V_14 , V_3 , V_30 ,
NULL ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_68 -> V_69 )
return 0 ;
V_6 = F_14 ( V_2 , V_100 , L_14 ,
V_2 -> V_19 [ V_80 ] . V_13 ,
V_2 -> V_81 [ V_101 ] ,
V_2 -> V_47 + V_48 ,
V_102 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_8 ( V_2 , V_103 , - V_38 , L_15 ,
V_2 -> V_19 [ V_84 ] . V_13 ,
V_2 -> V_47 + V_67 ,
V_104 ,
V_105 ,
V_106 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_18 ( V_2 , V_107 , L_16 ,
V_2 -> V_19 [ V_103 ] . V_13 ,
1 , 2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_48 ( V_2 , V_108 , V_109 ,
V_110 , L_17 ,
V_2 -> V_19 [ V_107 ] . V_13 ,
V_2 -> V_19 [ V_100 ] . V_13 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_48 ( V_2 , V_111 , V_112 , 0 ,
L_18 , V_2 -> V_19 [ V_103 ] . V_13 ,
V_2 -> V_19 [ V_100 ] . V_13 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_81 [ V_113 ] ) {
V_6 = F_14 ( V_2 , V_114 , L_19 ,
V_2 -> V_19 [ V_84 ] . V_13 ,
V_2 -> V_81 [ V_113 ] ,
V_2 -> V_47 + V_48 ,
V_115 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_8 ( V_2 , V_116 , V_117 , L_20 ,
V_2 -> V_19 [ V_114 ] . V_13 ,
V_2 -> V_47 + V_118 ,
V_119 ,
V_120 ,
V_106 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_68 -> V_69 )
return 0 ;
V_6 = F_16 ( V_2 , V_121 , V_122 ,
L_21 , V_2 -> V_19 [ V_84 ] . V_13 ,
V_2 -> V_47 + V_48 ,
V_123 , 0 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_8 ( V_2 , V_103 , - V_38 ,
L_15 , V_2 -> V_19 [ V_84 ] . V_13 ,
V_2 -> V_47 + V_67 ,
V_104 ,
V_124 ,
V_106 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_16 ( V_2 , V_125 , V_126 ,
L_22 , V_2 -> V_19 [ V_103 ] . V_13 ,
V_2 -> V_47 + V_48 ,
V_127 ,
0 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_14 ( V_2 , V_100 , L_14 ,
V_2 -> V_19 [ V_80 ] . V_13 ,
V_2 -> V_81 [ V_101 ] ,
V_2 -> V_47 + V_48 ,
V_102 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_48 ( V_2 , V_108 , V_109 ,
V_110 , L_17 ,
V_2 -> V_19 [ V_103 ] . V_13 ,
V_2 -> V_19 [ V_100 ] . V_13 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_128 ;
for ( V_128 = V_116 ; V_128 >= 0 ; V_128 -- ) {
struct V_129 * V_130 = & V_2 -> V_19 [ V_128 ] ;
if ( ! V_130 || F_52 ( V_130 -> V_13 ) )
continue;
if ( V_130 -> V_16 )
F_53 ( V_130 -> V_16 ) ;
if ( V_130 -> F_5 )
V_130 -> F_5 ( V_130 -> V_13 ) ;
}
}
static void F_54 ( void T_1 * V_26 )
{
T_3 V_46 ;
V_46 = F_22 ( V_26 ) ;
if ( V_46 == V_131 )
F_24 ( V_132 , V_26 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_133 = 0 ;
if ( V_2 -> V_68 -> V_69 ) {
V_133 = 8 ;
F_54 ( V_2 -> V_134 + V_135 ) ;
}
V_2 -> V_47 = V_2 -> V_134 + V_133 + V_136 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
const char * error = L_23 ;
struct V_13 * clock ;
int V_137 ;
V_137 = F_57 ( V_2 -> V_7 ) ;
if ( V_137 < V_2 -> V_68 -> V_76 ) {
F_12 ( V_2 -> V_10 , error , V_137 ) ;
return - V_32 ;
}
F_58 ( V_2 -> V_7 , V_2 -> V_74 , V_137 ) ;
clock = F_59 ( V_2 -> V_10 , V_2 -> V_74 [ 0 ] ) ;
if ( F_11 ( clock ) ) {
F_12 ( V_2 -> V_10 , L_24 ) ;
return F_13 ( clock ) ;
}
V_2 -> V_81 [ V_82 ] = clock ;
clock = F_59 ( V_2 -> V_10 , V_2 -> V_74 [ 1 ] ) ;
if ( F_11 ( clock ) ) {
F_12 ( V_2 -> V_10 , L_25 ) ;
return F_13 ( clock ) ;
}
V_2 -> V_81 [ V_101 ] = clock ;
if ( V_2 -> V_68 -> V_69 ) {
clock = F_59 ( V_2 -> V_10 , V_2 -> V_74 [ 2 ] ) ;
if ( F_11 ( clock ) ) {
F_12 ( V_2 -> V_10 , L_26 ) ;
return F_13 ( clock ) ;
}
V_2 -> V_81 [ V_113 ] = clock ;
}
return 0 ;
}
static int F_60 ( struct V_138 * V_139 )
{
struct V_140 * V_141 = V_139 -> V_10 . V_142 ;
struct V_143 * V_10 = & V_139 -> V_10 ;
const struct V_144 * V_145 ;
const struct V_146 * V_147 ;
struct V_1 * V_2 ;
struct V_148 * V_149 ;
int V_6 ;
V_145 = F_61 ( V_150 , V_10 ) ;
if ( V_145 )
V_147 = V_145 -> V_151 ;
else
return - V_38 ;
V_2 = F_3 ( V_10 , sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_7 = V_141 ;
V_2 -> V_68 = V_147 ;
F_62 ( V_2 -> V_10 , V_2 ) ;
F_63 ( & V_2 -> V_33 ) ;
V_149 = F_64 ( V_139 , V_152 , 0 ) ;
if ( ! V_149 )
return - V_38 ;
V_2 -> V_12 = V_149 -> V_153 ;
V_2 -> V_134 = F_65 ( V_10 , V_149 ) ;
if ( F_11 ( V_2 -> V_134 ) ) {
F_12 ( V_10 , L_27 ,
F_13 ( V_2 -> V_134 ) ) ;
return F_13 ( V_2 -> V_134 ) ;
}
V_6 = F_55 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_56 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_19 = F_3 ( V_2 -> V_10 , sizeof( struct V_129 ) *
V_154 ,
V_11 ) ;
if ( ! V_2 -> V_19 )
return - V_20 ;
V_6 = F_40 ( V_2 ) ;
if ( V_6 ) {
F_12 ( V_10 , L_28 , V_6 ) ;
goto free;
}
V_6 = F_49 ( V_2 ) ;
if ( V_6 )
goto free;
V_6 = F_50 ( V_2 ) ;
if ( V_6 )
goto free;
V_6 = F_66 ( V_2 -> V_7 , V_155 , & V_2 -> V_21 ) ;
if ( V_6 )
goto free;
return 0 ;
free:
F_67 ( 1 ) ;
F_51 ( V_2 ) ;
return V_6 ;
}
static int F_68 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_69 ( & V_139 -> V_10 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_156 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_156 ) ;
}
