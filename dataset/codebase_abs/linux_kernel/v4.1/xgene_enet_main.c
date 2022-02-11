static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_5 ] ;
V_4 -> V_8 = F_2 ( V_5 |
F_3 ( V_9 , V_2 -> V_10 ) |
F_3 ( V_11 , 3 ) ) ;
}
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_12 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
T_2 V_19 ;
T_1 V_20 = V_2 -> V_20 ;
T_1 V_6 = V_2 -> V_6 - 1 ;
T_3 V_21 , V_22 ;
int V_5 ;
V_16 = V_2 -> V_16 ;
V_18 = F_5 ( V_2 -> V_16 ) ;
V_21 = V_23 | ( V_24 & F_6 ( 11 , 0 ) ) ;
V_22 = V_25 ;
for ( V_5 = 0 ; V_5 < V_12 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_20 ] ;
V_14 = F_7 ( V_16 , V_22 ) ;
if ( F_8 ( ! V_14 ) )
return - V_26 ;
V_2 -> V_27 [ V_20 ] = V_14 ;
V_19 = F_9 ( V_18 , V_14 -> V_28 , V_22 , V_29 ) ;
if ( F_10 ( V_18 , V_19 ) ) {
F_11 ( V_16 , L_1 ) ;
F_12 ( V_14 ) ;
return - V_30 ;
}
V_4 -> V_31 = F_2 ( F_3 ( V_32 , V_19 ) |
F_3 ( V_33 , V_21 ) |
F_13 ( V_34 ) ) ;
V_20 = ( V_20 + 1 ) & V_6 ;
}
F_14 ( V_12 , V_2 -> V_35 ) ;
V_2 -> V_20 = V_20 ;
return 0 ;
}
static T_3 F_15 ( struct V_1 * V_36 )
{
struct V_37 * V_38 = F_16 ( V_36 -> V_16 ) ;
return ( ( T_3 ) V_38 -> V_39 << 10 ) | V_36 -> V_40 ;
}
static T_4 F_17 ( const void * V_28 )
{
const struct V_41 * V_42 = V_28 ;
return ( V_42 -> V_43 == F_18 ( V_44 ) ) ? V_45 : V_46 ;
}
static T_1 F_19 ( struct V_1 * V_36 )
{
T_1 T_5 * V_47 = V_36 -> V_47 ;
T_1 V_48 , V_49 ;
V_48 = F_20 ( & V_47 [ 1 ] ) ;
V_49 = V_48 & F_21 ( V_50 , V_51 ) ;
return V_49 >> V_50 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_6 = V_2 -> V_6 - 1 ;
T_1 V_20 = V_2 -> V_20 ;
T_1 V_52 ;
int V_5 , V_22 ;
V_22 = F_19 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_22 ; V_5 ++ ) {
V_20 = ( V_20 - 1 ) & V_6 ;
V_4 = & V_2 -> V_7 [ V_20 ] ;
V_52 = F_23 ( V_53 , F_24 ( V_4 -> V_8 ) ) ;
F_12 ( V_2 -> V_27 [ V_52 ] ) ;
}
F_14 ( - V_22 , V_2 -> V_35 ) ;
V_2 -> V_20 = V_20 ;
}
static T_6 F_25 ( const int V_54 , void * V_28 )
{
struct V_1 * V_55 = V_28 ;
if ( F_26 ( & V_55 -> V_56 ) ) {
F_27 ( V_54 ) ;
F_28 ( & V_55 -> V_56 ) ;
}
return V_57 ;
}
static int F_29 ( struct V_1 * V_58 ,
struct V_59 * V_4 )
{
struct V_13 * V_14 ;
struct V_17 * V_18 ;
T_3 V_60 ;
T_4 V_61 ;
int V_62 = 0 ;
V_60 = F_23 ( V_53 , F_24 ( V_4 -> V_8 ) ) ;
V_14 = V_58 -> V_63 [ V_60 ] ;
V_18 = F_5 ( V_58 -> V_16 ) ;
F_30 ( V_18 , F_23 ( V_32 , F_24 ( V_4 -> V_31 ) ) ,
F_23 ( V_33 , F_24 ( V_4 -> V_31 ) ) ,
V_64 ) ;
V_61 = F_23 ( V_65 , F_24 ( V_4 -> V_8 ) ) ;
if ( F_8 ( V_61 > 2 ) ) {
F_31 ( V_58 , F_16 ( V_58 -> V_16 ) ,
V_61 ) ;
V_62 = - V_66 ;
}
if ( F_32 ( V_14 ) ) {
F_12 ( V_14 ) ;
} else {
F_11 ( V_58 -> V_16 , L_2 ) ;
V_62 = - V_66 ;
}
return V_62 ;
}
static T_7 F_33 ( struct V_13 * V_14 )
{
struct V_67 * V_68 ;
T_4 V_69 , V_70 = 0 ;
T_4 V_71 = 0 ;
T_4 V_72 = 0 ;
T_4 V_41 ;
T_7 V_73 ;
if ( F_8 ( V_14 -> V_74 != F_18 ( V_75 ) ) &&
F_8 ( V_14 -> V_74 != F_18 ( V_44 ) ) )
goto V_76;
if ( F_8 ( ! ( V_14 -> V_18 -> V_77 & V_78 ) ) )
goto V_76;
V_68 = F_34 ( V_14 ) ;
if ( F_8 ( F_35 ( V_68 ) ) )
goto V_76;
if ( F_32 ( V_68 -> V_74 == V_79 ) ) {
V_70 = F_36 ( V_14 ) >> 2 ;
V_71 = 1 ;
V_72 = V_80 ;
} else if ( V_68 -> V_74 == V_81 ) {
V_70 = V_82 ;
V_71 = 1 ;
}
V_76:
V_69 = F_37 ( V_14 ) >> 2 ;
V_41 = F_17 ( V_14 -> V_28 ) ;
V_73 = F_3 ( V_83 , V_70 ) |
F_3 ( V_84 , V_69 ) |
F_3 ( V_85 , V_41 ) |
F_3 ( V_86 , V_71 ) |
F_3 ( V_87 , V_72 ) |
F_13 ( V_88 ) |
F_13 ( V_89 ) ;
return V_73 ;
}
static int F_38 ( struct V_1 * V_90 ,
struct V_13 * V_14 )
{
struct V_17 * V_18 = F_5 ( V_90 -> V_16 ) ;
struct V_59 * V_4 ;
T_2 V_19 ;
T_3 V_20 = V_90 -> V_20 ;
T_7 V_73 ;
V_4 = & V_90 -> V_4 [ V_20 ] ;
memset ( V_4 , 0 , sizeof( struct V_59 ) ) ;
V_19 = F_9 ( V_18 , V_14 -> V_28 , V_14 -> V_22 , V_64 ) ;
if ( F_10 ( V_18 , V_19 ) ) {
F_11 ( V_90 -> V_16 , L_1 ) ;
return - V_30 ;
}
V_4 -> V_8 = F_2 ( V_20 ) ;
V_4 -> V_31 = F_2 ( F_3 ( V_32 , V_19 ) |
F_3 ( V_33 , V_14 -> V_22 ) |
F_13 ( V_34 ) ) ;
V_73 = F_33 ( V_14 ) ;
V_4 -> V_91 = F_2 ( F_3 ( V_92 , V_90 -> V_10 ) |
V_73 ) ;
V_90 -> V_58 -> V_63 [ V_20 ] = V_14 ;
return 0 ;
}
static T_8 F_39 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_1 * V_90 = V_38 -> V_90 ;
struct V_1 * V_58 = V_90 -> V_58 ;
T_1 V_93 , V_94 ;
V_93 = F_19 ( V_90 ) ;
V_94 = F_19 ( V_58 ) ;
if ( F_8 ( V_93 > V_38 -> V_95 ||
V_94 > V_38 -> V_96 ) ) {
F_40 ( V_16 ) ;
return V_97 ;
}
if ( F_38 ( V_90 , V_14 ) ) {
F_12 ( V_14 ) ;
return V_98 ;
}
F_14 ( 1 , V_90 -> V_35 ) ;
F_41 ( V_14 ) ;
V_90 -> V_20 = ( V_90 -> V_20 + 1 ) & ( V_90 -> V_6 - 1 ) ;
V_38 -> V_99 . V_100 ++ ;
V_38 -> V_99 . V_101 += V_14 -> V_22 ;
return V_98 ;
}
static void F_42 ( struct V_13 * V_14 )
{
struct V_67 * V_68 = F_34 ( V_14 ) ;
if ( ! F_35 ( V_68 ) ||
( V_68 -> V_74 != V_79 && V_68 -> V_74 != V_81 ) ) {
V_14 -> V_102 = V_103 ;
}
}
static int F_43 ( struct V_1 * V_55 ,
struct V_59 * V_4 )
{
struct V_15 * V_16 ;
struct V_37 * V_38 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
T_1 V_104 , V_60 ;
struct V_13 * V_14 ;
T_4 V_61 ;
int V_62 = 0 ;
V_16 = V_55 -> V_16 ;
V_38 = F_16 ( V_16 ) ;
V_18 = F_5 ( V_55 -> V_16 ) ;
V_2 = V_55 -> V_2 ;
F_30 ( V_18 , F_23 ( V_32 , F_24 ( V_4 -> V_31 ) ) ,
V_25 , V_29 ) ;
V_60 = F_23 ( V_53 , F_24 ( V_4 -> V_8 ) ) ;
V_14 = V_2 -> V_27 [ V_60 ] ;
V_61 = F_23 ( V_65 , F_24 ( V_4 -> V_8 ) ) ;
if ( F_8 ( V_61 > 2 ) ) {
F_12 ( V_14 ) ;
F_31 ( V_55 , F_16 ( V_55 -> V_16 ) ,
V_61 ) ;
V_38 -> V_99 . V_105 ++ ;
V_62 = - V_66 ;
goto V_76;
}
V_104 = F_23 ( V_33 , F_24 ( V_4 -> V_31 ) ) ;
V_104 -= 4 ;
F_44 ( V_14 -> V_28 - V_106 ) ;
F_45 ( V_14 , V_104 ) ;
F_46 ( V_14 ) ;
V_14 -> V_74 = F_47 ( V_14 , V_16 ) ;
if ( F_32 ( ( V_16 -> V_77 & V_78 ) &&
V_14 -> V_74 == F_18 ( V_75 ) ) ) {
F_42 ( V_14 ) ;
}
V_38 -> V_99 . V_107 ++ ;
V_38 -> V_99 . V_108 += V_104 ;
F_48 ( & V_55 -> V_56 , V_14 ) ;
V_76:
if ( -- V_55 -> V_109 == 0 ) {
V_62 = F_4 ( V_2 , V_110 ) ;
V_55 -> V_109 = V_110 ;
}
return V_62 ;
}
static bool F_49 ( struct V_59 * V_4 )
{
return F_23 ( V_9 , F_24 ( V_4 -> V_8 ) ) ? true : false ;
}
static int F_50 ( struct V_1 * V_36 ,
int V_111 )
{
struct V_37 * V_38 = F_16 ( V_36 -> V_16 ) ;
struct V_59 * V_4 ;
T_3 V_112 = V_36 -> V_112 ;
T_3 V_6 = V_36 -> V_6 - 1 ;
int V_62 , V_113 = 0 ;
do {
V_4 = & V_36 -> V_4 [ V_112 ] ;
if ( F_8 ( F_51 ( V_4 ) ) )
break;
F_52 () ;
if ( F_49 ( V_4 ) )
V_62 = F_43 ( V_36 , V_4 ) ;
else
V_62 = F_29 ( V_36 , V_4 ) ;
F_53 ( V_4 ) ;
V_112 = ( V_112 + 1 ) & V_6 ;
V_113 ++ ;
if ( V_62 )
break;
} while ( -- V_111 );
if ( F_32 ( V_113 ) ) {
F_14 ( - V_113 , V_36 -> V_35 ) ;
V_36 -> V_112 = V_112 ;
if ( F_54 ( V_36 -> V_16 ) ) {
if ( F_19 ( V_36 ) < V_38 -> V_114 )
F_55 ( V_36 -> V_16 ) ;
}
}
return V_113 ;
}
static int F_56 ( struct V_115 * V_56 , const int V_111 )
{
struct V_1 * V_36 ;
int V_116 ;
V_36 = F_57 ( V_56 , struct V_1 , V_56 ) ;
V_116 = F_50 ( V_36 , V_111 ) ;
if ( V_116 != V_111 ) {
F_58 ( V_56 ) ;
F_59 ( V_36 -> V_54 ) ;
}
return V_116 ;
}
static void F_60 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
V_38 -> V_117 -> V_118 ( V_38 ) ;
}
static int F_61 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
struct V_1 * V_36 ;
int V_62 ;
V_36 = V_38 -> V_55 ;
V_62 = F_62 ( V_18 , V_36 -> V_54 , F_25 ,
V_119 , V_36 -> V_120 , V_36 ) ;
if ( V_62 )
F_11 ( V_16 , L_3 , V_36 -> V_120 ) ;
if ( V_38 -> V_121 ) {
V_36 = V_38 -> V_90 -> V_58 ;
V_62 = F_62 ( V_18 , V_36 -> V_54 , F_25 ,
V_119 , V_36 -> V_120 , V_36 ) ;
if ( V_62 ) {
F_11 ( V_16 , L_3 ,
V_36 -> V_120 ) ;
}
}
return V_62 ;
}
static void F_63 ( struct V_15 * V_16 )
{
struct V_37 * V_38 ;
struct V_17 * V_18 ;
V_38 = F_16 ( V_16 ) ;
V_18 = F_5 ( V_16 ) ;
F_64 ( V_18 , V_38 -> V_55 -> V_54 , V_38 -> V_55 ) ;
if ( V_38 -> V_121 ) {
F_64 ( V_18 , V_38 -> V_90 -> V_58 -> V_54 ,
V_38 -> V_90 -> V_58 ) ;
}
}
static void F_65 ( struct V_37 * V_38 )
{
struct V_115 * V_56 ;
V_56 = & V_38 -> V_55 -> V_56 ;
F_66 ( V_56 ) ;
if ( V_38 -> V_121 ) {
V_56 = & V_38 -> V_90 -> V_58 -> V_56 ;
F_66 ( V_56 ) ;
}
}
static void F_67 ( struct V_37 * V_38 )
{
struct V_115 * V_56 ;
V_56 = & V_38 -> V_55 -> V_56 ;
F_68 ( V_56 ) ;
if ( V_38 -> V_121 ) {
V_56 = & V_38 -> V_90 -> V_58 -> V_56 ;
F_68 ( V_56 ) ;
}
}
static int F_69 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_122 * V_117 = V_38 -> V_117 ;
int V_62 ;
V_117 -> V_123 ( V_38 ) ;
V_117 -> V_124 ( V_38 ) ;
V_62 = F_61 ( V_16 ) ;
if ( V_62 )
return V_62 ;
F_65 ( V_38 ) ;
if ( V_38 -> V_125 == V_126 )
F_70 ( V_38 -> V_127 ) ;
else
F_71 ( & V_38 -> V_128 , V_129 ) ;
F_72 ( V_16 ) ;
return V_62 ;
}
static int F_73 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_122 * V_117 = V_38 -> V_117 ;
F_40 ( V_16 ) ;
if ( V_38 -> V_125 == V_126 )
F_74 ( V_38 -> V_127 ) ;
else
F_75 ( & V_38 -> V_128 ) ;
F_67 ( V_38 ) ;
F_63 ( V_16 ) ;
F_50 ( V_38 -> V_55 , - 1 ) ;
V_117 -> V_130 ( V_38 ) ;
V_117 -> V_131 ( V_38 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_36 )
{
struct V_37 * V_38 ;
struct V_17 * V_18 ;
V_38 = F_16 ( V_36 -> V_16 ) ;
V_18 = F_5 ( V_36 -> V_16 ) ;
F_77 ( V_36 ) ;
F_78 ( V_18 , V_36 -> V_132 , V_36 -> V_133 , V_36 -> V_134 ) ;
}
static void F_79 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
if ( V_38 -> V_90 ) {
F_76 ( V_38 -> V_90 ) ;
V_38 -> V_90 = NULL ;
}
if ( V_38 -> V_55 ) {
V_2 = V_38 -> V_55 -> V_2 ;
F_22 ( V_2 ) ;
F_76 ( V_2 ) ;
F_76 ( V_38 -> V_55 ) ;
V_38 -> V_55 = NULL ;
}
}
static int F_80 ( struct V_17 * V_18 ,
enum V_135 V_136 )
{
int V_132 = - V_30 ;
switch ( V_136 ) {
case V_137 :
V_132 = 0x200 ;
break;
case V_138 :
V_132 = 0x800 ;
break;
case V_139 :
V_132 = 0x4000 ;
break;
case V_140 :
V_132 = 0x10000 ;
break;
case V_141 :
V_132 = 0x80000 ;
break;
default:
F_81 ( V_18 , L_4 , V_136 ) ;
break;
}
return V_132 ;
}
static void F_82 ( struct V_1 * V_36 )
{
struct V_17 * V_18 ;
if ( ! V_36 )
return;
V_18 = F_5 ( V_36 -> V_16 ) ;
if ( V_36 -> V_133 ) {
F_77 ( V_36 ) ;
F_78 ( V_18 , V_36 -> V_132 , V_36 -> V_133 , V_36 -> V_134 ) ;
}
F_83 ( V_18 , V_36 ) ;
}
static void F_84 ( struct V_37 * V_38 )
{
struct V_17 * V_18 = & V_38 -> V_142 -> V_18 ;
struct V_1 * V_36 ;
V_36 = V_38 -> V_90 ;
if ( V_36 ) {
if ( V_36 -> V_58 && V_36 -> V_58 -> V_63 )
F_83 ( V_18 , V_36 -> V_58 -> V_63 ) ;
if ( V_36 -> V_58 && V_38 -> V_121 )
F_82 ( V_36 -> V_58 ) ;
F_82 ( V_36 ) ;
}
V_36 = V_38 -> V_55 ;
if ( V_36 ) {
if ( V_36 -> V_2 ) {
if ( V_36 -> V_2 -> V_27 )
F_83 ( V_18 , V_36 -> V_2 -> V_27 ) ;
F_82 ( V_36 -> V_2 ) ;
}
F_82 ( V_36 ) ;
}
}
static struct V_1 * F_85 (
struct V_15 * V_16 , T_1 V_143 ,
enum V_135 V_136 , T_1 V_144 )
{
struct V_1 * V_36 ;
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
int V_132 ;
V_132 = F_80 ( V_18 , V_136 ) ;
if ( V_132 < 0 )
return NULL ;
V_36 = F_86 ( V_18 , sizeof( struct V_1 ) ,
V_145 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_16 = V_16 ;
V_36 -> V_40 = V_143 ;
V_36 -> V_136 = V_136 ;
V_36 -> V_146 = V_144 ;
V_36 -> V_133 = F_87 ( V_18 , V_132 , & V_36 -> V_134 ,
V_145 ) ;
if ( ! V_36 -> V_133 ) {
F_83 ( V_18 , V_36 ) ;
return NULL ;
}
V_36 -> V_132 = V_132 ;
V_36 -> V_47 = V_38 -> V_147 + ( V_36 -> V_40 << 6 ) ;
V_36 -> V_35 = V_36 -> V_47 + V_148 ;
V_36 = F_88 ( V_36 ) ;
F_89 ( V_16 , L_5 ,
V_36 -> V_40 , V_36 -> V_132 , V_36 -> V_146 , V_36 -> V_6 ) ;
return V_36 ;
}
static T_3 F_90 ( enum V_149 V_150 , T_4 V_151 )
{
return ( V_150 << 6 ) | ( V_151 & F_6 ( 5 , 0 ) ) ;
}
static int F_91 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
struct V_1 * V_55 , * V_90 , * V_58 ;
struct V_1 * V_2 = NULL ;
T_4 V_152 = V_38 -> V_152 ;
T_4 V_153 = V_38 -> V_153 ;
T_4 V_154 = V_38 -> V_154 ;
T_3 V_143 = V_38 -> V_143 ;
T_3 V_144 ;
int V_62 ;
V_144 = F_90 ( V_155 , V_152 ++ ) ;
V_55 = F_85 ( V_16 , V_143 ++ ,
V_139 , V_144 ) ;
if ( ! V_55 ) {
V_62 = - V_26 ;
goto V_156;
}
V_144 = F_90 ( V_157 , V_154 ++ ) ;
V_2 = F_85 ( V_16 , V_143 ++ ,
V_138 , V_144 ) ;
if ( ! V_2 ) {
V_62 = - V_26 ;
goto V_156;
}
V_55 -> V_109 = V_110 ;
V_55 -> V_2 = V_2 ;
V_55 -> V_54 = V_38 -> V_158 ;
if ( ! V_38 -> V_121 ) {
snprintf ( V_55 -> V_120 , V_159 , L_6 ,
V_16 -> V_160 ) ;
} else {
snprintf ( V_55 -> V_120 , V_159 , L_7 , V_16 -> V_160 ) ;
}
V_2 -> V_27 = F_92 ( V_18 , V_2 -> V_6 ,
sizeof( struct V_13 * ) , V_145 ) ;
if ( ! V_2 -> V_27 ) {
V_62 = - V_26 ;
goto V_156;
}
V_2 -> V_10 = F_15 ( V_2 ) ;
V_55 -> V_2 = V_2 ;
V_38 -> V_55 = V_55 ;
V_144 = F_90 ( V_157 , V_153 ++ ) ;
V_90 = F_85 ( V_16 , V_143 ++ ,
V_139 , V_144 ) ;
if ( ! V_90 ) {
V_62 = - V_26 ;
goto V_156;
}
V_38 -> V_90 = V_90 ;
if ( ! V_38 -> V_121 ) {
V_58 = V_38 -> V_55 ;
} else {
V_144 = F_90 ( V_155 , V_152 ++ ) ;
V_58 = F_85 ( V_16 , V_143 ++ ,
V_139 ,
V_144 ) ;
if ( ! V_58 ) {
V_62 = - V_26 ;
goto V_156;
}
V_58 -> V_54 = V_38 -> V_161 ;
snprintf ( V_58 -> V_120 , V_159 , L_8 , V_16 -> V_160 ) ;
}
V_58 -> V_63 = F_92 ( V_18 , V_90 -> V_6 ,
sizeof( struct V_13 * ) , V_145 ) ;
if ( ! V_58 -> V_63 ) {
V_62 = - V_26 ;
goto V_156;
}
V_38 -> V_90 -> V_58 = V_58 ;
V_38 -> V_90 -> V_10 = F_15 ( V_58 ) ;
V_38 -> V_95 = V_38 -> V_90 -> V_6 / 2 ;
V_38 -> V_96 = V_38 -> V_55 -> V_6 / 2 ;
V_38 -> V_114 = V_38 -> V_96 / 2 ;
return 0 ;
V_156:
F_84 ( V_38 ) ;
return V_62 ;
}
static struct V_162 * F_93 (
struct V_15 * V_16 ,
struct V_162 * V_163 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_162 * V_99 = & V_38 -> V_99 ;
V_99 -> V_164 += V_99 -> V_165 +
V_99 -> V_166 +
V_99 -> V_167 +
V_99 -> V_168 ;
memcpy ( V_163 , & V_38 -> V_99 , sizeof( struct V_162 ) ) ;
return V_163 ;
}
static int F_94 ( struct V_15 * V_16 , void * V_169 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
int V_62 ;
V_62 = F_95 ( V_16 , V_169 ) ;
if ( V_62 )
return V_62 ;
V_38 -> V_117 -> V_170 ( V_38 ) ;
return V_62 ;
}
static int F_96 ( struct V_17 * V_18 , struct V_37 * V_38 )
{
T_1 V_146 = 0 ;
int V_62 ;
V_62 = F_97 ( V_18 , L_9 , & V_146 ) ;
if ( ! V_62 && V_146 > 1 ) {
F_81 ( V_18 , L_10 ) ;
return - V_171 ;
}
V_38 -> V_172 = V_146 ;
return 0 ;
}
static int F_98 ( struct V_17 * V_18 ,
unsigned char * V_169 )
{
int V_62 ;
V_62 = F_99 ( V_18 , L_11 , V_169 , 6 ) ;
if ( V_62 )
V_62 = F_99 ( V_18 , L_12 ,
V_169 , 6 ) ;
if ( V_62 )
return - V_171 ;
return V_173 ;
}
static int F_100 ( struct V_17 * V_18 )
{
int V_5 , V_62 ;
char * V_174 ;
V_62 = F_101 ( V_18 , L_13 ,
( const char * * ) & V_174 ) ;
if ( V_62 )
V_62 = F_101 ( V_18 , L_14 ,
( const char * * ) & V_174 ) ;
if ( V_62 )
return - V_171 ;
for ( V_5 = 0 ; V_5 < V_175 ; V_5 ++ ) {
if ( ! strcasecmp ( V_174 , F_102 ( V_5 ) ) )
return V_5 ;
}
return - V_171 ;
}
static int F_103 ( struct V_37 * V_38 )
{
struct V_176 * V_142 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_177 * V_178 ;
void T_5 * V_179 ;
int V_62 ;
V_142 = V_38 -> V_142 ;
V_18 = & V_142 -> V_18 ;
V_16 = V_38 -> V_16 ;
V_178 = F_104 ( V_142 , V_180 , V_181 ) ;
if ( ! V_178 ) {
F_81 ( V_18 , L_15 ) ;
return - V_171 ;
}
V_38 -> V_179 = F_105 ( V_18 , V_178 -> V_182 , F_106 ( V_178 ) ) ;
if ( ! V_38 -> V_179 ) {
F_81 ( V_18 , L_16 ) ;
return - V_26 ;
}
V_178 = F_104 ( V_142 , V_180 , V_183 ) ;
if ( ! V_178 ) {
F_81 ( V_18 , L_17 ) ;
return - V_171 ;
}
V_38 -> V_184 = F_105 ( V_18 , V_178 -> V_182 ,
F_106 ( V_178 ) ) ;
if ( ! V_38 -> V_184 ) {
F_81 ( V_18 , L_18 ) ;
return - V_26 ;
}
V_178 = F_104 ( V_142 , V_180 , V_185 ) ;
if ( ! V_178 ) {
F_81 ( V_18 , L_19 ) ;
return - V_171 ;
}
V_38 -> V_147 = F_105 ( V_18 , V_178 -> V_182 ,
F_106 ( V_178 ) ) ;
if ( ! V_38 -> V_147 ) {
F_81 ( V_18 , L_20 ) ;
return - V_26 ;
}
V_62 = F_96 ( V_18 , V_38 ) ;
if ( V_62 )
return V_62 ;
if ( F_98 ( V_18 , V_16 -> V_186 ) != V_173 )
F_107 ( V_16 ) ;
memcpy ( V_16 -> V_187 , V_16 -> V_186 , V_16 -> V_188 ) ;
V_38 -> V_125 = F_100 ( V_18 ) ;
if ( V_38 -> V_125 < 0 ) {
F_81 ( V_18 , L_21 ) ;
return V_38 -> V_125 ;
}
if ( V_38 -> V_125 != V_126 &&
V_38 -> V_125 != V_189 &&
V_38 -> V_125 != V_190 ) {
F_81 ( V_18 , L_22 ) ;
return - V_171 ;
}
V_62 = F_108 ( V_142 , 0 ) ;
if ( V_62 <= 0 ) {
F_81 ( V_18 , L_23 ) ;
V_62 = V_62 ? : - V_191 ;
return V_62 ;
}
V_38 -> V_158 = V_62 ;
if ( V_38 -> V_125 != V_126 ) {
V_62 = F_108 ( V_142 , 1 ) ;
if ( V_62 <= 0 ) {
F_81 ( V_18 , L_24 ) ;
V_62 = V_62 ? : - V_191 ;
return V_62 ;
}
V_38 -> V_161 = V_62 ;
}
V_38 -> V_192 = F_109 ( & V_142 -> V_18 , NULL ) ;
if ( F_110 ( V_38 -> V_192 ) ) {
V_38 -> V_192 = NULL ;
}
V_179 = V_38 -> V_179 - ( V_38 -> V_172 * V_193 ) ;
V_38 -> V_194 = V_179 + V_195 ;
V_38 -> V_196 = V_179 + V_197 ;
V_38 -> V_198 = V_179 + V_199 ;
if ( V_38 -> V_125 == V_126 ||
V_38 -> V_125 == V_189 ) {
V_38 -> V_200 = V_38 -> V_179 + V_201 ;
V_38 -> V_202 = V_179 + V_203 ;
} else {
V_38 -> V_200 = V_179 + V_204 ;
V_38 -> V_202 = V_179 + V_205 ;
}
V_38 -> V_206 = V_207 ;
return 0 ;
}
static int F_111 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 ;
T_3 V_10 ;
int V_62 ;
V_62 = V_38 -> V_208 -> V_118 ( V_38 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_91 ( V_16 ) ;
if ( V_62 ) {
F_11 ( V_16 , L_25 ) ;
return V_62 ;
}
V_2 = V_38 -> V_55 -> V_2 ;
F_1 ( V_2 ) ;
V_62 = F_4 ( V_2 , V_38 -> V_206 ) ;
if ( V_62 ) {
F_79 ( V_38 ) ;
return V_62 ;
}
V_10 = F_15 ( V_38 -> V_55 ) ;
V_38 -> V_208 -> V_209 ( V_38 , V_10 , V_2 -> V_146 ) ;
V_38 -> V_117 -> V_210 ( V_38 ) ;
return V_62 ;
}
static void F_112 ( struct V_37 * V_38 )
{
switch ( V_38 -> V_125 ) {
case V_126 :
V_38 -> V_117 = & V_211 ;
V_38 -> V_208 = & V_212 ;
V_38 -> V_39 = V_213 ;
break;
case V_189 :
V_38 -> V_117 = & V_214 ;
V_38 -> V_208 = & V_215 ;
V_38 -> V_39 = V_216 ;
V_38 -> V_121 = V_217 ;
break;
default:
V_38 -> V_117 = & V_218 ;
V_38 -> V_208 = & V_219 ;
V_38 -> V_39 = V_220 ;
V_38 -> V_121 = V_217 ;
break;
}
switch ( V_38 -> V_172 ) {
case 0 :
V_38 -> V_152 = V_221 ;
V_38 -> V_153 = V_222 ;
V_38 -> V_154 = V_223 ;
V_38 -> V_143 = V_224 ;
break;
case 1 :
V_38 -> V_152 = V_225 ;
V_38 -> V_153 = V_226 ;
V_38 -> V_154 = V_227 ;
V_38 -> V_143 = V_228 ;
break;
default:
break;
}
}
static void F_113 ( struct V_37 * V_38 )
{
struct V_115 * V_56 ;
V_56 = & V_38 -> V_55 -> V_56 ;
F_114 ( V_38 -> V_16 , V_56 , F_56 , V_229 ) ;
if ( V_38 -> V_121 ) {
V_56 = & V_38 -> V_90 -> V_58 -> V_56 ;
F_114 ( V_38 -> V_16 , V_56 , F_56 ,
V_229 ) ;
}
}
static void F_115 ( struct V_37 * V_38 )
{
struct V_115 * V_56 ;
V_56 = & V_38 -> V_55 -> V_56 ;
F_116 ( V_56 ) ;
if ( V_38 -> V_121 ) {
V_56 = & V_38 -> V_90 -> V_58 -> V_56 ;
F_116 ( V_56 ) ;
}
}
static int F_117 ( struct V_176 * V_142 )
{
struct V_15 * V_16 ;
struct V_37 * V_38 ;
struct V_17 * V_18 = & V_142 -> V_18 ;
struct V_122 * V_117 ;
int V_62 ;
V_16 = F_118 ( sizeof( struct V_37 ) ) ;
if ( ! V_16 )
return - V_26 ;
V_38 = F_16 ( V_16 ) ;
V_38 -> V_142 = V_142 ;
V_38 -> V_16 = V_16 ;
F_119 ( V_16 , V_18 ) ;
F_120 ( V_142 , V_38 ) ;
V_16 -> V_230 = & V_231 ;
F_121 ( V_16 ) ;
V_16 -> V_77 |= V_78 |
V_232 |
V_233 ;
V_62 = F_103 ( V_38 ) ;
if ( V_62 )
goto V_156;
F_112 ( V_38 ) ;
V_62 = F_122 ( V_16 ) ;
if ( V_62 ) {
F_11 ( V_16 , L_26 ) ;
goto V_156;
}
V_62 = F_123 ( V_18 , F_124 ( 64 ) ) ;
if ( V_62 ) {
F_11 ( V_16 , L_27 ) ;
goto V_156;
}
V_62 = F_111 ( V_38 ) ;
if ( V_62 )
goto V_156;
F_113 ( V_38 ) ;
V_117 = V_38 -> V_117 ;
if ( V_38 -> V_125 == V_126 )
V_62 = F_125 ( V_38 ) ;
else
F_126 ( & V_38 -> V_128 , V_117 -> V_234 ) ;
return V_62 ;
V_156:
F_127 ( V_16 ) ;
F_128 ( V_16 ) ;
return V_62 ;
}
static int F_129 ( struct V_176 * V_142 )
{
struct V_37 * V_38 ;
struct V_122 * V_117 ;
struct V_15 * V_16 ;
V_38 = F_130 ( V_142 ) ;
V_117 = V_38 -> V_117 ;
V_16 = V_38 -> V_16 ;
V_117 -> V_131 ( V_38 ) ;
V_117 -> V_130 ( V_38 ) ;
F_115 ( V_38 ) ;
F_131 ( V_38 ) ;
F_79 ( V_38 ) ;
F_127 ( V_16 ) ;
V_38 -> V_208 -> V_235 ( V_38 ) ;
F_128 ( V_16 ) ;
return 0 ;
}
