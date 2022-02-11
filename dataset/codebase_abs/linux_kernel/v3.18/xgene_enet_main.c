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
if ( F_49 ( V_4 ) )
V_62 = F_43 ( V_36 , V_4 ) ;
else
V_62 = F_29 ( V_36 , V_4 ) ;
F_52 ( V_4 ) ;
V_112 = ( V_112 + 1 ) & V_6 ;
V_113 ++ ;
if ( V_62 )
break;
} while ( -- V_111 );
if ( F_32 ( V_113 ) ) {
F_14 ( - V_113 , V_36 -> V_35 ) ;
V_36 -> V_112 = V_112 ;
if ( F_53 ( V_36 -> V_16 ) ) {
if ( F_19 ( V_36 ) < V_38 -> V_114 )
F_54 ( V_36 -> V_16 ) ;
}
}
return V_113 ;
}
static int F_55 ( struct V_115 * V_56 , const int V_111 )
{
struct V_1 * V_36 ;
int V_116 ;
V_36 = F_56 ( V_56 , struct V_1 , V_56 ) ;
V_116 = F_50 ( V_36 , V_111 ) ;
if ( V_116 != V_111 ) {
F_57 ( V_56 ) ;
F_58 ( V_36 -> V_54 ) ;
}
return V_116 ;
}
static void F_59 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
V_38 -> V_117 -> V_118 ( V_38 ) ;
}
static int F_60 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
int V_62 ;
V_62 = F_61 ( V_18 , V_38 -> V_55 -> V_54 , F_25 ,
V_119 , V_16 -> V_120 , V_38 -> V_55 ) ;
if ( V_62 ) {
F_11 ( V_16 , L_3 ,
V_38 -> V_55 -> V_54 ) ;
}
return V_62 ;
}
static void F_62 ( struct V_15 * V_16 )
{
struct V_37 * V_38 ;
struct V_17 * V_18 ;
V_38 = F_16 ( V_16 ) ;
V_18 = F_5 ( V_16 ) ;
F_63 ( V_18 , V_38 -> V_55 -> V_54 , V_38 -> V_55 ) ;
}
static int F_64 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_121 * V_117 = V_38 -> V_117 ;
int V_62 ;
V_117 -> V_122 ( V_38 ) ;
V_117 -> V_123 ( V_38 ) ;
V_62 = F_60 ( V_16 ) ;
if ( V_62 )
return V_62 ;
F_65 ( & V_38 -> V_55 -> V_56 ) ;
if ( V_38 -> V_124 == V_125 )
F_66 ( V_38 -> V_126 ) ;
else
F_67 ( & V_38 -> V_127 , V_128 ) ;
F_68 ( V_16 ) ;
return V_62 ;
}
static int F_69 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_121 * V_117 = V_38 -> V_117 ;
F_40 ( V_16 ) ;
if ( V_38 -> V_124 == V_125 )
F_70 ( V_38 -> V_126 ) ;
else
F_71 ( & V_38 -> V_127 ) ;
F_72 ( & V_38 -> V_55 -> V_56 ) ;
F_62 ( V_16 ) ;
F_50 ( V_38 -> V_55 , - 1 ) ;
V_117 -> V_129 ( V_38 ) ;
V_117 -> V_130 ( V_38 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_36 )
{
struct V_37 * V_38 ;
struct V_17 * V_18 ;
V_38 = F_16 ( V_36 -> V_16 ) ;
V_18 = F_5 ( V_36 -> V_16 ) ;
F_74 ( V_36 ) ;
F_75 ( V_18 , V_36 -> V_131 , V_36 -> V_132 , V_36 -> V_133 ) ;
}
static void F_76 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
if ( V_38 -> V_90 ) {
F_73 ( V_38 -> V_90 ) ;
V_38 -> V_90 = NULL ;
}
if ( V_38 -> V_55 ) {
V_2 = V_38 -> V_55 -> V_2 ;
F_22 ( V_2 ) ;
F_73 ( V_2 ) ;
F_73 ( V_38 -> V_55 ) ;
V_38 -> V_55 = NULL ;
}
}
static int F_77 ( struct V_17 * V_18 ,
enum V_134 V_135 )
{
int V_131 = - V_30 ;
switch ( V_135 ) {
case V_136 :
V_131 = 0x200 ;
break;
case V_137 :
V_131 = 0x800 ;
break;
case V_138 :
V_131 = 0x4000 ;
break;
case V_139 :
V_131 = 0x10000 ;
break;
case V_140 :
V_131 = 0x80000 ;
break;
default:
F_78 ( V_18 , L_4 , V_135 ) ;
break;
}
return V_131 ;
}
static void F_79 ( struct V_1 * V_36 )
{
struct V_17 * V_18 ;
if ( ! V_36 )
return;
V_18 = F_5 ( V_36 -> V_16 ) ;
if ( V_36 -> V_132 ) {
F_74 ( V_36 ) ;
F_75 ( V_18 , V_36 -> V_131 , V_36 -> V_132 , V_36 -> V_133 ) ;
}
F_80 ( V_18 , V_36 ) ;
}
static void F_81 ( struct V_37 * V_38 )
{
struct V_17 * V_18 = & V_38 -> V_141 -> V_18 ;
struct V_1 * V_36 ;
V_36 = V_38 -> V_90 ;
if ( V_36 ) {
if ( V_36 -> V_58 && V_36 -> V_58 -> V_63 )
F_80 ( V_18 , V_36 -> V_58 -> V_63 ) ;
F_79 ( V_36 ) ;
}
V_36 = V_38 -> V_55 ;
if ( V_36 ) {
if ( V_36 -> V_2 ) {
if ( V_36 -> V_2 -> V_27 )
F_80 ( V_18 , V_36 -> V_2 -> V_27 ) ;
F_79 ( V_36 -> V_2 ) ;
}
F_79 ( V_36 ) ;
}
}
static struct V_1 * F_82 (
struct V_15 * V_16 , T_1 V_142 ,
enum V_134 V_135 , T_1 V_143 )
{
struct V_1 * V_36 ;
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
int V_131 ;
V_131 = F_77 ( V_18 , V_135 ) ;
if ( V_131 < 0 )
return NULL ;
V_36 = F_83 ( V_18 , sizeof( struct V_1 ) ,
V_144 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_16 = V_16 ;
V_36 -> V_40 = V_142 ;
V_36 -> V_135 = V_135 ;
V_36 -> V_145 = V_143 ;
V_36 -> V_132 = F_84 ( V_18 , V_131 , & V_36 -> V_133 ,
V_144 ) ;
if ( ! V_36 -> V_132 ) {
F_80 ( V_18 , V_36 ) ;
return NULL ;
}
V_36 -> V_131 = V_131 ;
V_36 -> V_47 = V_38 -> V_146 + ( V_36 -> V_40 << 6 ) ;
V_36 -> V_35 = V_36 -> V_47 + V_147 ;
V_36 = F_85 ( V_36 ) ;
F_86 ( V_16 , L_5 ,
V_36 -> V_40 , V_36 -> V_131 , V_36 -> V_145 , V_36 -> V_6 ) ;
return V_36 ;
}
static T_3 F_87 ( enum V_148 V_149 , T_4 V_150 )
{
return ( V_149 << 6 ) | ( V_150 & F_6 ( 5 , 0 ) ) ;
}
static int F_88 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
struct V_1 * V_55 , * V_90 , * V_58 ;
struct V_1 * V_2 = NULL ;
T_4 V_151 = 0 , V_152 = V_153 ;
T_4 V_154 = V_155 ;
T_3 V_143 , V_142 = V_156 ;
int V_62 ;
V_143 = F_87 ( V_157 , V_151 ++ ) ;
V_55 = F_82 ( V_16 , V_142 ++ ,
V_138 , V_143 ) ;
if ( ! V_55 ) {
V_62 = - V_26 ;
goto V_158;
}
V_143 = F_87 ( V_159 , V_154 ++ ) ;
V_2 = F_82 ( V_16 , V_142 ++ ,
V_137 , V_143 ) ;
if ( ! V_2 ) {
V_62 = - V_26 ;
goto V_158;
}
V_55 -> V_109 = V_110 ;
V_55 -> V_2 = V_2 ;
V_55 -> V_54 = V_38 -> V_160 ;
V_2 -> V_27 = F_89 ( V_18 , V_2 -> V_6 ,
sizeof( struct V_13 * ) , V_144 ) ;
if ( ! V_2 -> V_27 ) {
V_62 = - V_26 ;
goto V_158;
}
V_2 -> V_10 = F_15 ( V_2 ) ;
V_55 -> V_2 = V_2 ;
V_38 -> V_55 = V_55 ;
V_143 = F_87 ( V_159 , V_152 ++ ) ;
V_90 = F_82 ( V_16 , V_142 ++ ,
V_138 , V_143 ) ;
if ( ! V_90 ) {
V_62 = - V_26 ;
goto V_158;
}
V_38 -> V_90 = V_90 ;
V_58 = V_38 -> V_55 ;
V_58 -> V_63 = F_89 ( V_18 , V_90 -> V_6 ,
sizeof( struct V_13 * ) , V_144 ) ;
if ( ! V_58 -> V_63 ) {
V_62 = - V_26 ;
goto V_158;
}
V_38 -> V_90 -> V_58 = V_58 ;
V_38 -> V_90 -> V_10 = F_15 ( V_58 ) ;
V_38 -> V_95 = V_38 -> V_90 -> V_6 / 2 ;
V_38 -> V_96 = V_38 -> V_55 -> V_6 / 2 ;
V_38 -> V_114 = V_38 -> V_96 / 2 ;
return 0 ;
V_158:
F_81 ( V_38 ) ;
return V_62 ;
}
static struct V_161 * F_90 (
struct V_15 * V_16 ,
struct V_161 * V_162 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
struct V_161 * V_99 = & V_38 -> V_99 ;
V_99 -> V_163 += V_99 -> V_164 +
V_99 -> V_165 +
V_99 -> V_166 +
V_99 -> V_167 ;
memcpy ( V_162 , & V_38 -> V_99 , sizeof( struct V_161 ) ) ;
return V_162 ;
}
static int F_91 ( struct V_15 * V_16 , void * V_168 )
{
struct V_37 * V_38 = F_16 ( V_16 ) ;
int V_62 ;
V_62 = F_92 ( V_16 , V_168 ) ;
if ( V_62 )
return V_62 ;
V_38 -> V_117 -> V_169 ( V_38 ) ;
return V_62 ;
}
static int F_93 ( struct V_37 * V_38 )
{
struct V_170 * V_141 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_171 * V_172 ;
void T_5 * V_173 ;
const char * V_174 ;
int V_62 ;
V_141 = V_38 -> V_141 ;
V_18 = & V_141 -> V_18 ;
V_16 = V_38 -> V_16 ;
V_172 = F_94 ( V_141 , V_175 , L_6 ) ;
if ( ! V_172 ) {
F_78 ( V_18 , L_7 ) ;
return - V_176 ;
}
V_38 -> V_173 = F_95 ( V_18 , V_172 ) ;
if ( F_96 ( V_38 -> V_173 ) ) {
F_78 ( V_18 , L_8 ) ;
return F_97 ( V_38 -> V_173 ) ;
}
V_172 = F_94 ( V_141 , V_175 , L_9 ) ;
if ( ! V_172 ) {
F_78 ( V_18 , L_10 ) ;
return - V_176 ;
}
V_38 -> V_177 = F_95 ( V_18 , V_172 ) ;
if ( F_96 ( V_38 -> V_177 ) ) {
F_78 ( V_18 , L_11 ) ;
return F_97 ( V_38 -> V_177 ) ;
}
V_172 = F_94 ( V_141 , V_175 , L_12 ) ;
if ( ! V_172 ) {
F_78 ( V_18 , L_13 ) ;
return - V_176 ;
}
V_38 -> V_146 = F_95 ( V_18 , V_172 ) ;
if ( F_96 ( V_38 -> V_146 ) ) {
F_78 ( V_18 , L_14 ) ;
return F_97 ( V_38 -> V_146 ) ;
}
V_62 = F_98 ( V_141 , 0 ) ;
if ( V_62 <= 0 ) {
F_78 ( V_18 , L_15 ) ;
V_62 = V_62 ? : - V_178 ;
return V_62 ;
}
V_38 -> V_160 = V_62 ;
V_174 = F_99 ( V_18 -> V_179 ) ;
if ( V_174 )
memcpy ( V_16 -> V_180 , V_174 , V_16 -> V_181 ) ;
else
F_100 ( V_16 ) ;
memcpy ( V_16 -> V_182 , V_16 -> V_180 , V_16 -> V_181 ) ;
V_38 -> V_124 = F_101 ( V_141 -> V_18 . V_179 ) ;
if ( V_38 -> V_124 < 0 ) {
F_78 ( V_18 , L_16 ) ;
return V_38 -> V_124 ;
}
if ( V_38 -> V_124 != V_125 &&
V_38 -> V_124 != V_183 &&
V_38 -> V_124 != V_184 ) {
F_78 ( V_18 , L_17 ) ;
return - V_176 ;
}
V_38 -> V_185 = F_102 ( & V_141 -> V_18 , NULL ) ;
V_62 = F_96 ( V_38 -> V_185 ) ;
if ( F_96 ( V_38 -> V_185 ) ) {
F_78 ( & V_141 -> V_18 , L_18 ) ;
V_62 = F_97 ( V_38 -> V_185 ) ;
return V_62 ;
}
V_173 = V_38 -> V_173 ;
V_38 -> V_186 = V_173 + V_187 ;
V_38 -> V_188 = V_173 + V_189 ;
V_38 -> V_190 = V_173 + V_191 ;
if ( V_38 -> V_124 == V_125 ||
V_38 -> V_124 == V_183 ) {
V_38 -> V_192 = V_173 + V_193 ;
V_38 -> V_194 = V_173 + V_195 ;
} else {
V_38 -> V_192 = V_173 + V_196 ;
V_38 -> V_194 = V_173 + V_197 ;
}
V_38 -> V_198 = V_199 ;
return 0 ;
}
static int F_103 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_16 ;
struct V_1 * V_2 ;
T_3 V_10 ;
int V_62 ;
V_62 = V_38 -> V_200 -> V_118 ( V_38 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_88 ( V_16 ) ;
if ( V_62 ) {
F_11 ( V_16 , L_19 ) ;
return V_62 ;
}
V_2 = V_38 -> V_55 -> V_2 ;
F_1 ( V_2 ) ;
V_62 = F_4 ( V_2 , V_38 -> V_198 ) ;
if ( V_62 ) {
F_76 ( V_38 ) ;
return V_62 ;
}
V_10 = F_15 ( V_38 -> V_55 ) ;
V_38 -> V_200 -> V_201 ( V_38 , V_10 , V_2 -> V_145 ) ;
V_38 -> V_117 -> V_202 ( V_38 ) ;
return V_62 ;
}
static void F_104 ( struct V_37 * V_38 )
{
switch ( V_38 -> V_124 ) {
case V_125 :
V_38 -> V_117 = & V_203 ;
V_38 -> V_200 = & V_204 ;
V_38 -> V_39 = V_205 ;
break;
case V_183 :
V_38 -> V_117 = & V_206 ;
V_38 -> V_200 = & V_207 ;
V_38 -> V_39 = V_208 ;
break;
default:
V_38 -> V_117 = & V_209 ;
V_38 -> V_200 = & V_210 ;
V_38 -> V_39 = V_211 ;
break;
}
}
static int F_105 ( struct V_170 * V_141 )
{
struct V_15 * V_16 ;
struct V_37 * V_38 ;
struct V_17 * V_18 = & V_141 -> V_18 ;
struct V_115 * V_56 ;
struct V_121 * V_117 ;
int V_62 ;
V_16 = F_106 ( sizeof( struct V_37 ) ) ;
if ( ! V_16 )
return - V_26 ;
V_38 = F_16 ( V_16 ) ;
V_38 -> V_141 = V_141 ;
V_38 -> V_16 = V_16 ;
F_107 ( V_16 , V_18 ) ;
F_108 ( V_141 , V_38 ) ;
V_16 -> V_212 = & V_213 ;
F_109 ( V_16 ) ;
V_16 -> V_77 |= V_78 |
V_214 |
V_215 ;
V_62 = F_93 ( V_38 ) ;
if ( V_62 )
goto V_158;
F_104 ( V_38 ) ;
V_62 = F_110 ( V_16 ) ;
if ( V_62 ) {
F_11 ( V_16 , L_20 ) ;
goto V_158;
}
V_62 = F_111 ( V_18 , F_112 ( 64 ) ) ;
if ( V_62 ) {
F_11 ( V_16 , L_21 ) ;
goto V_158;
}
V_62 = F_103 ( V_38 ) ;
if ( V_62 )
goto V_158;
V_56 = & V_38 -> V_55 -> V_56 ;
F_113 ( V_16 , V_56 , F_55 , V_216 ) ;
V_117 = V_38 -> V_117 ;
if ( V_38 -> V_124 == V_125 )
V_62 = F_114 ( V_38 ) ;
else
F_115 ( & V_38 -> V_127 , V_117 -> V_217 ) ;
return V_62 ;
V_158:
F_116 ( V_16 ) ;
F_117 ( V_16 ) ;
return V_62 ;
}
static int F_118 ( struct V_170 * V_141 )
{
struct V_37 * V_38 ;
struct V_121 * V_117 ;
struct V_15 * V_16 ;
V_38 = F_119 ( V_141 ) ;
V_117 = V_38 -> V_117 ;
V_16 = V_38 -> V_16 ;
V_117 -> V_130 ( V_38 ) ;
V_117 -> V_129 ( V_38 ) ;
F_120 ( & V_38 -> V_55 -> V_56 ) ;
F_121 ( V_38 ) ;
F_76 ( V_38 ) ;
F_116 ( V_16 ) ;
V_38 -> V_200 -> V_218 ( V_38 ) ;
F_117 ( V_16 ) ;
return 0 ;
}
