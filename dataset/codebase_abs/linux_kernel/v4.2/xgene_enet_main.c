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
struct V_19 * V_20 ;
T_2 V_21 ;
T_1 V_22 = V_2 -> V_22 ;
T_1 V_6 = V_2 -> V_6 - 1 ;
T_3 V_23 , V_24 ;
int V_5 ;
V_18 = V_2 -> V_18 ;
V_20 = F_5 ( V_2 -> V_18 ) ;
V_16 = F_6 ( V_18 ) ;
V_23 = V_25 | ( V_26 & F_7 ( 11 , 0 ) ) ;
V_24 = V_27 ;
for ( V_5 = 0 ; V_5 < V_12 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_22 ] ;
V_14 = F_8 ( V_18 , V_24 ) ;
if ( F_9 ( ! V_14 ) )
return - V_28 ;
V_2 -> V_29 [ V_22 ] = V_14 ;
V_21 = F_10 ( V_20 , V_14 -> V_30 , V_24 , V_31 ) ;
if ( F_11 ( V_20 , V_21 ) ) {
F_12 ( V_18 , L_1 ) ;
F_13 ( V_14 ) ;
return - V_32 ;
}
V_4 -> V_33 = F_2 ( F_3 ( V_34 , V_21 ) |
F_3 ( V_35 , V_23 ) |
F_14 ( V_36 ) ) ;
V_22 = ( V_22 + 1 ) & V_6 ;
}
V_16 -> V_37 -> V_38 ( V_2 , V_12 ) ;
V_2 -> V_22 = V_22 ;
return 0 ;
}
static T_3 F_15 ( struct V_1 * V_39 )
{
struct V_15 * V_16 = F_6 ( V_39 -> V_18 ) ;
return ( ( T_3 ) V_16 -> V_40 << 10 ) | V_39 -> V_41 ;
}
static T_4 F_16 ( const void * V_30 )
{
const struct V_42 * V_43 = V_30 ;
return ( V_43 -> V_44 == F_17 ( V_45 ) ) ? V_46 : V_47 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_6 ( V_2 -> V_18 ) ;
struct V_3 * V_4 ;
T_1 V_6 = V_2 -> V_6 - 1 ;
T_1 V_22 = V_2 -> V_22 ;
T_1 V_48 ;
int V_5 , V_24 ;
V_24 = V_16 -> V_37 -> V_24 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
V_22 = ( V_22 - 1 ) & V_6 ;
V_4 = & V_2 -> V_7 [ V_22 ] ;
V_48 = F_19 ( V_49 , F_20 ( V_4 -> V_8 ) ) ;
F_13 ( V_2 -> V_29 [ V_48 ] ) ;
}
V_16 -> V_37 -> V_38 ( V_2 , - V_24 ) ;
V_2 -> V_22 = V_22 ;
}
static T_5 F_21 ( const int V_50 , void * V_30 )
{
struct V_1 * V_51 = V_30 ;
if ( F_22 ( & V_51 -> V_52 ) ) {
F_23 ( V_50 ) ;
F_24 ( & V_51 -> V_52 ) ;
}
return V_53 ;
}
static int F_25 ( struct V_1 * V_54 ,
struct V_55 * V_4 )
{
struct V_13 * V_14 ;
struct V_19 * V_20 ;
T_3 V_56 ;
T_4 V_57 ;
int V_58 = 0 ;
V_56 = F_19 ( V_49 , F_20 ( V_4 -> V_8 ) ) ;
V_14 = V_54 -> V_59 [ V_56 ] ;
V_20 = F_5 ( V_54 -> V_18 ) ;
F_26 ( V_20 , F_19 ( V_34 , F_20 ( V_4 -> V_33 ) ) ,
F_19 ( V_35 , F_20 ( V_4 -> V_33 ) ) ,
V_60 ) ;
V_57 = F_19 ( V_61 , F_20 ( V_4 -> V_8 ) ) ;
if ( F_9 ( V_57 > 2 ) ) {
F_27 ( V_54 , F_6 ( V_54 -> V_18 ) ,
V_57 ) ;
V_58 = - V_62 ;
}
if ( F_28 ( V_14 ) ) {
F_13 ( V_14 ) ;
} else {
F_12 ( V_54 -> V_18 , L_2 ) ;
V_58 = - V_62 ;
}
return V_58 ;
}
static T_6 F_29 ( struct V_13 * V_14 )
{
struct V_63 * V_64 ;
T_4 V_65 , V_66 = 0 ;
T_4 V_67 = 0 ;
T_4 V_68 = 0 ;
T_4 V_42 ;
T_6 V_69 ;
if ( F_9 ( V_14 -> V_70 != F_17 ( V_71 ) ) &&
F_9 ( V_14 -> V_70 != F_17 ( V_45 ) ) )
goto V_72;
if ( F_9 ( ! ( V_14 -> V_20 -> V_73 & V_74 ) ) )
goto V_72;
V_64 = F_30 ( V_14 ) ;
if ( F_9 ( F_31 ( V_64 ) ) )
goto V_72;
if ( F_28 ( V_64 -> V_70 == V_75 ) ) {
V_66 = F_32 ( V_14 ) >> 2 ;
V_67 = 1 ;
V_68 = V_76 ;
} else if ( V_64 -> V_70 == V_77 ) {
V_66 = V_78 ;
V_67 = 1 ;
}
V_72:
V_65 = F_33 ( V_14 ) >> 2 ;
V_42 = F_16 ( V_14 -> V_30 ) ;
V_69 = F_3 ( V_79 , V_66 ) |
F_3 ( V_80 , V_65 ) |
F_3 ( V_81 , V_42 ) |
F_3 ( V_82 , V_67 ) |
F_3 ( V_83 , V_68 ) |
F_14 ( V_84 ) |
F_14 ( V_85 ) ;
return V_69 ;
}
static int F_34 ( struct V_1 * V_86 ,
struct V_13 * V_14 )
{
struct V_19 * V_20 = F_5 ( V_86 -> V_18 ) ;
struct V_55 * V_4 ;
T_2 V_21 ;
T_3 V_22 = V_86 -> V_22 ;
T_6 V_69 ;
V_4 = & V_86 -> V_4 [ V_22 ] ;
memset ( V_4 , 0 , sizeof( struct V_55 ) ) ;
V_21 = F_10 ( V_20 , V_14 -> V_30 , V_14 -> V_24 , V_60 ) ;
if ( F_11 ( V_20 , V_21 ) ) {
F_12 ( V_86 -> V_18 , L_1 ) ;
return - V_32 ;
}
V_4 -> V_8 = F_2 ( V_22 ) ;
V_4 -> V_33 = F_2 ( F_3 ( V_34 , V_21 ) |
F_3 ( V_35 , V_14 -> V_24 ) |
F_14 ( V_36 ) ) ;
V_69 = F_29 ( V_14 ) ;
V_4 -> V_87 = F_2 ( F_3 ( V_88 , V_86 -> V_10 ) |
V_69 ) ;
V_86 -> V_54 -> V_59 [ V_22 ] = V_14 ;
return 0 ;
}
static T_7 F_35 ( struct V_13 * V_14 ,
struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_1 * V_86 = V_16 -> V_86 ;
struct V_1 * V_54 = V_86 -> V_54 ;
T_1 V_89 , V_90 ;
V_89 = V_16 -> V_37 -> V_24 ( V_86 ) ;
V_90 = V_16 -> V_37 -> V_24 ( V_54 ) ;
if ( F_9 ( V_89 > V_16 -> V_91 ||
V_90 > V_16 -> V_92 ) ) {
F_36 ( V_18 ) ;
return V_93 ;
}
if ( F_34 ( V_86 , V_14 ) ) {
F_13 ( V_14 ) ;
return V_94 ;
}
V_16 -> V_37 -> V_38 ( V_86 , 1 ) ;
F_37 ( V_14 ) ;
V_86 -> V_22 = ( V_86 -> V_22 + 1 ) & ( V_86 -> V_6 - 1 ) ;
V_16 -> V_95 . V_96 ++ ;
V_16 -> V_95 . V_97 += V_14 -> V_24 ;
return V_94 ;
}
static void F_38 ( struct V_13 * V_14 )
{
struct V_63 * V_64 = F_30 ( V_14 ) ;
if ( ! F_31 ( V_64 ) ||
( V_64 -> V_70 != V_75 && V_64 -> V_70 != V_77 ) ) {
V_14 -> V_98 = V_99 ;
}
}
static int F_39 ( struct V_1 * V_51 ,
struct V_55 * V_4 )
{
struct V_17 * V_18 ;
struct V_15 * V_16 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
T_1 V_100 , V_56 ;
struct V_13 * V_14 ;
T_4 V_57 ;
int V_58 = 0 ;
V_18 = V_51 -> V_18 ;
V_16 = F_6 ( V_18 ) ;
V_20 = F_5 ( V_51 -> V_18 ) ;
V_2 = V_51 -> V_2 ;
F_26 ( V_20 , F_19 ( V_34 , F_20 ( V_4 -> V_33 ) ) ,
V_27 , V_31 ) ;
V_56 = F_19 ( V_49 , F_20 ( V_4 -> V_8 ) ) ;
V_14 = V_2 -> V_29 [ V_56 ] ;
V_57 = F_19 ( V_61 , F_20 ( V_4 -> V_8 ) ) ;
if ( F_9 ( V_57 > 2 ) ) {
F_13 ( V_14 ) ;
F_27 ( V_51 , F_6 ( V_51 -> V_18 ) ,
V_57 ) ;
V_16 -> V_95 . V_101 ++ ;
V_58 = - V_62 ;
goto V_72;
}
V_100 = F_19 ( V_35 , F_20 ( V_4 -> V_33 ) ) ;
V_100 -= 4 ;
F_40 ( V_14 -> V_30 - V_102 ) ;
F_41 ( V_14 , V_100 ) ;
F_42 ( V_14 ) ;
V_14 -> V_70 = F_43 ( V_14 , V_18 ) ;
if ( F_28 ( ( V_18 -> V_73 & V_74 ) &&
V_14 -> V_70 == F_17 ( V_71 ) ) ) {
F_38 ( V_14 ) ;
}
V_16 -> V_95 . V_103 ++ ;
V_16 -> V_95 . V_104 += V_100 ;
F_44 ( & V_51 -> V_52 , V_14 ) ;
V_72:
if ( -- V_51 -> V_105 == 0 ) {
V_58 = F_4 ( V_2 , V_106 ) ;
V_51 -> V_105 = V_106 ;
}
return V_58 ;
}
static bool F_45 ( struct V_55 * V_4 )
{
return F_19 ( V_9 , F_20 ( V_4 -> V_8 ) ) ? true : false ;
}
static int F_46 ( struct V_1 * V_39 ,
int V_107 )
{
struct V_15 * V_16 = F_6 ( V_39 -> V_18 ) ;
struct V_55 * V_4 ;
T_3 V_108 = V_39 -> V_108 ;
T_3 V_6 = V_39 -> V_6 - 1 ;
int V_58 , V_109 = 0 ;
do {
V_4 = & V_39 -> V_4 [ V_108 ] ;
if ( F_9 ( F_47 ( V_4 ) ) )
break;
F_48 () ;
if ( F_45 ( V_4 ) )
V_58 = F_39 ( V_39 , V_4 ) ;
else
V_58 = F_25 ( V_39 , V_4 ) ;
F_49 ( V_4 ) ;
V_108 = ( V_108 + 1 ) & V_6 ;
V_109 ++ ;
if ( V_58 )
break;
} while ( -- V_107 );
if ( F_28 ( V_109 ) ) {
V_16 -> V_37 -> V_38 ( V_39 , - V_109 ) ;
V_39 -> V_108 = V_108 ;
if ( F_50 ( V_39 -> V_18 ) ) {
if ( V_16 -> V_37 -> V_24 ( V_39 ) < V_16 -> V_110 )
F_51 ( V_39 -> V_18 ) ;
}
}
return V_109 ;
}
static int F_52 ( struct V_111 * V_52 , const int V_107 )
{
struct V_1 * V_39 ;
int V_112 ;
V_39 = F_53 ( V_52 , struct V_1 , V_52 ) ;
V_112 = F_46 ( V_39 , V_107 ) ;
if ( V_112 != V_107 ) {
F_54 ( V_52 ) ;
F_55 ( V_39 -> V_50 ) ;
}
return V_112 ;
}
static void F_56 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
V_16 -> V_113 -> V_114 ( V_16 ) ;
}
static int F_57 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_19 * V_20 = F_5 ( V_18 ) ;
struct V_1 * V_39 ;
int V_58 ;
V_39 = V_16 -> V_51 ;
V_58 = F_58 ( V_20 , V_39 -> V_50 , F_21 ,
V_115 , V_39 -> V_116 , V_39 ) ;
if ( V_58 )
F_12 ( V_18 , L_3 , V_39 -> V_116 ) ;
if ( V_16 -> V_117 ) {
V_39 = V_16 -> V_86 -> V_54 ;
V_58 = F_58 ( V_20 , V_39 -> V_50 , F_21 ,
V_115 , V_39 -> V_116 , V_39 ) ;
if ( V_58 ) {
F_12 ( V_18 , L_3 ,
V_39 -> V_116 ) ;
}
}
return V_58 ;
}
static void F_59 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
V_16 = F_6 ( V_18 ) ;
V_20 = F_5 ( V_18 ) ;
F_60 ( V_20 , V_16 -> V_51 -> V_50 , V_16 -> V_51 ) ;
if ( V_16 -> V_117 ) {
F_60 ( V_20 , V_16 -> V_86 -> V_54 -> V_50 ,
V_16 -> V_86 -> V_54 ) ;
}
}
static void F_61 ( struct V_15 * V_16 )
{
struct V_111 * V_52 ;
V_52 = & V_16 -> V_51 -> V_52 ;
F_62 ( V_52 ) ;
if ( V_16 -> V_117 ) {
V_52 = & V_16 -> V_86 -> V_54 -> V_52 ;
F_62 ( V_52 ) ;
}
}
static void F_63 ( struct V_15 * V_16 )
{
struct V_111 * V_52 ;
V_52 = & V_16 -> V_51 -> V_52 ;
F_64 ( V_52 ) ;
if ( V_16 -> V_117 ) {
V_52 = & V_16 -> V_86 -> V_54 -> V_52 ;
F_64 ( V_52 ) ;
}
}
static int F_65 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_118 * V_113 = V_16 -> V_113 ;
int V_58 ;
V_113 -> V_119 ( V_16 ) ;
V_113 -> V_120 ( V_16 ) ;
V_58 = F_57 ( V_18 ) ;
if ( V_58 )
return V_58 ;
F_61 ( V_16 ) ;
if ( V_16 -> V_121 == V_122 )
F_66 ( V_16 -> V_123 ) ;
else
F_67 ( & V_16 -> V_124 , V_125 ) ;
F_68 ( V_18 ) ;
F_69 ( V_18 ) ;
return V_58 ;
}
static int F_70 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_118 * V_113 = V_16 -> V_113 ;
F_36 ( V_18 ) ;
if ( V_16 -> V_121 == V_122 )
F_71 ( V_16 -> V_123 ) ;
else
F_72 ( & V_16 -> V_124 ) ;
F_63 ( V_16 ) ;
F_59 ( V_18 ) ;
F_46 ( V_16 -> V_51 , - 1 ) ;
V_113 -> V_126 ( V_16 ) ;
V_113 -> V_127 ( V_16 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_39 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
V_16 = F_6 ( V_39 -> V_18 ) ;
V_20 = F_5 ( V_39 -> V_18 ) ;
V_16 -> V_37 -> V_128 ( V_39 ) ;
F_74 ( V_20 , V_39 -> V_129 , V_39 -> V_130 , V_39 -> V_131 ) ;
}
static void F_75 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
if ( V_16 -> V_86 ) {
F_73 ( V_16 -> V_86 ) ;
V_16 -> V_86 = NULL ;
}
if ( V_16 -> V_51 ) {
V_2 = V_16 -> V_51 -> V_2 ;
F_18 ( V_2 ) ;
F_73 ( V_2 ) ;
F_73 ( V_16 -> V_51 ) ;
V_16 -> V_51 = NULL ;
}
}
static int F_76 ( struct V_19 * V_20 ,
enum V_132 V_133 )
{
int V_129 = - V_32 ;
switch ( V_133 ) {
case V_134 :
V_129 = 0x200 ;
break;
case V_135 :
V_129 = 0x800 ;
break;
case V_136 :
V_129 = 0x4000 ;
break;
case V_137 :
V_129 = 0x10000 ;
break;
case V_138 :
V_129 = 0x80000 ;
break;
default:
F_77 ( V_20 , L_4 , V_133 ) ;
break;
}
return V_129 ;
}
static void F_78 ( struct V_1 * V_39 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
if ( ! V_39 )
return;
V_20 = F_5 ( V_39 -> V_18 ) ;
V_16 = F_6 ( V_39 -> V_18 ) ;
if ( V_39 -> V_130 ) {
V_16 -> V_37 -> V_128 ( V_39 ) ;
F_74 ( V_20 , V_39 -> V_129 , V_39 -> V_130 , V_39 -> V_131 ) ;
}
F_79 ( V_20 , V_39 ) ;
}
static void F_80 ( struct V_15 * V_16 )
{
struct V_19 * V_20 = & V_16 -> V_139 -> V_20 ;
struct V_1 * V_39 ;
V_39 = V_16 -> V_86 ;
if ( V_39 ) {
if ( V_39 -> V_54 && V_39 -> V_54 -> V_59 )
F_79 ( V_20 , V_39 -> V_54 -> V_59 ) ;
if ( V_39 -> V_54 && V_16 -> V_117 )
F_78 ( V_39 -> V_54 ) ;
F_78 ( V_39 ) ;
}
V_39 = V_16 -> V_51 ;
if ( V_39 ) {
if ( V_39 -> V_2 ) {
if ( V_39 -> V_2 -> V_29 )
F_79 ( V_20 , V_39 -> V_2 -> V_29 ) ;
F_78 ( V_39 -> V_2 ) ;
}
F_78 ( V_39 ) ;
}
}
static bool F_81 ( struct V_15 * V_16 ,
struct V_1 * V_39 )
{
if ( ( V_16 -> V_140 == V_141 ) &&
( F_82 ( V_39 -> V_142 ) == V_143 ) ) {
return true ;
}
return false ;
}
static void T_8 * F_83 ( struct V_15 * V_16 ,
struct V_1 * V_39 )
{
T_4 V_144 = V_16 -> V_37 -> V_144 ;
return V_16 -> V_145 + ( V_39 -> V_41 << V_144 ) ;
}
static struct V_1 * F_84 (
struct V_17 * V_18 , T_1 V_146 ,
enum V_132 V_133 , T_1 V_147 )
{
struct V_1 * V_39 ;
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_19 * V_20 = F_5 ( V_18 ) ;
int V_129 ;
V_129 = F_76 ( V_20 , V_133 ) ;
if ( V_129 < 0 )
return NULL ;
V_39 = F_85 ( V_20 , sizeof( struct V_1 ) ,
V_148 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_18 = V_18 ;
V_39 -> V_41 = V_146 ;
V_39 -> V_133 = V_133 ;
V_39 -> V_142 = V_147 ;
V_39 -> V_130 = F_86 ( V_20 , V_129 , & V_39 -> V_131 ,
V_148 ) ;
if ( ! V_39 -> V_130 ) {
F_79 ( V_20 , V_39 ) ;
return NULL ;
}
V_39 -> V_129 = V_129 ;
if ( F_81 ( V_16 , V_39 ) ) {
V_39 -> V_149 = F_86 ( V_20 , V_150 ,
& V_39 -> V_151 , V_148 ) ;
if ( ! V_39 -> V_149 ) {
F_74 ( V_20 , V_129 , V_39 -> V_130 ,
V_39 -> V_131 ) ;
F_79 ( V_20 , V_39 ) ;
return NULL ;
}
}
V_39 -> V_152 = F_83 ( V_16 , V_39 ) ;
V_39 -> V_153 = V_39 -> V_152 + V_154 ;
V_39 = V_16 -> V_37 -> V_155 ( V_39 ) ;
F_87 ( V_18 , L_5 ,
V_39 -> V_41 , V_39 -> V_129 , V_39 -> V_142 , V_39 -> V_6 ) ;
return V_39 ;
}
static T_3 F_88 ( enum V_156 V_157 , T_4 V_158 )
{
return ( V_157 << 6 ) | ( V_158 & F_7 ( 5 , 0 ) ) ;
}
static enum V_156 F_89 ( struct V_15 * V_159 )
{
enum V_156 V_157 ;
if ( V_159 -> V_140 == V_160 ) {
switch ( V_159 -> V_121 ) {
case V_161 :
V_157 = V_162 ;
break;
default:
V_157 = ( ! V_159 -> V_163 ) ? V_162 :
V_164 ;
break;
}
} else {
V_157 = ( ! V_159 -> V_163 ) ? V_162 : V_164 ;
}
return V_157 ;
}
static int F_90 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_19 * V_20 = F_5 ( V_18 ) ;
struct V_1 * V_51 , * V_86 , * V_54 ;
struct V_1 * V_2 = NULL ;
enum V_156 V_157 ;
T_4 V_165 = V_16 -> V_165 ;
T_4 V_166 = V_16 -> V_166 ;
T_4 V_167 = V_16 -> V_167 ;
T_3 V_146 = V_16 -> V_146 ;
T_3 V_147 ;
int V_58 ;
V_157 = F_89 ( V_16 ) ;
V_147 = F_88 ( V_143 , V_165 ++ ) ;
V_51 = F_84 ( V_18 , V_146 ++ ,
V_136 , V_147 ) ;
if ( ! V_51 ) {
V_58 = - V_28 ;
goto V_168;
}
V_157 = F_89 ( V_16 ) ;
V_147 = F_88 ( V_157 , V_167 ++ ) ;
V_2 = F_84 ( V_18 , V_146 ++ ,
V_135 , V_147 ) ;
if ( ! V_2 ) {
V_58 = - V_28 ;
goto V_168;
}
V_51 -> V_105 = V_106 ;
V_51 -> V_2 = V_2 ;
V_51 -> V_50 = V_16 -> V_169 ;
if ( ! V_16 -> V_117 ) {
snprintf ( V_51 -> V_116 , V_170 , L_6 ,
V_18 -> V_171 ) ;
} else {
snprintf ( V_51 -> V_116 , V_170 , L_7 , V_18 -> V_171 ) ;
}
V_2 -> V_29 = F_91 ( V_20 , V_2 -> V_6 ,
sizeof( struct V_13 * ) , V_148 ) ;
if ( ! V_2 -> V_29 ) {
V_58 = - V_28 ;
goto V_168;
}
V_2 -> V_10 = F_15 ( V_2 ) ;
V_51 -> V_2 = V_2 ;
V_16 -> V_51 = V_51 ;
V_157 = F_89 ( V_16 ) ;
V_147 = F_88 ( V_157 , V_166 ++ ) ;
V_86 = F_84 ( V_18 , V_146 ++ ,
V_136 , V_147 ) ;
if ( ! V_86 ) {
V_58 = - V_28 ;
goto V_168;
}
V_16 -> V_86 = V_86 ;
if ( ! V_16 -> V_117 ) {
V_54 = V_16 -> V_51 ;
} else {
V_147 = F_88 ( V_143 , V_165 ++ ) ;
V_54 = F_84 ( V_18 , V_146 ++ ,
V_136 ,
V_147 ) ;
if ( ! V_54 ) {
V_58 = - V_28 ;
goto V_168;
}
V_54 -> V_50 = V_16 -> V_172 ;
snprintf ( V_54 -> V_116 , V_170 , L_8 , V_18 -> V_171 ) ;
}
V_54 -> V_59 = F_91 ( V_20 , V_86 -> V_6 ,
sizeof( struct V_13 * ) , V_148 ) ;
if ( ! V_54 -> V_59 ) {
V_58 = - V_28 ;
goto V_168;
}
V_16 -> V_86 -> V_54 = V_54 ;
V_16 -> V_86 -> V_10 = F_15 ( V_54 ) ;
V_16 -> V_91 = V_16 -> V_86 -> V_6 / 2 ;
V_16 -> V_92 = V_16 -> V_51 -> V_6 / 2 ;
V_16 -> V_110 = V_16 -> V_92 / 2 ;
return 0 ;
V_168:
F_80 ( V_16 ) ;
return V_58 ;
}
static struct V_173 * F_92 (
struct V_17 * V_18 ,
struct V_173 * V_174 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_173 * V_95 = & V_16 -> V_95 ;
V_95 -> V_175 += V_95 -> V_176 +
V_95 -> V_177 +
V_95 -> V_178 +
V_95 -> V_179 ;
memcpy ( V_174 , & V_16 -> V_95 , sizeof( struct V_173 ) ) ;
return V_174 ;
}
static int F_93 ( struct V_17 * V_18 , void * V_180 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
int V_58 ;
V_58 = F_94 ( V_18 , V_180 ) ;
if ( V_58 )
return V_58 ;
V_16 -> V_113 -> V_181 ( V_16 ) ;
return V_58 ;
}
static int F_95 ( struct V_19 * V_20 ,
struct V_15 * V_16 )
{
T_9 V_57 ;
T_6 V_182 ;
V_57 = F_96 ( F_97 ( V_20 ) , L_9 , NULL , & V_182 ) ;
if ( F_98 ( V_57 ) ) {
V_16 -> V_163 = 0 ;
} else {
V_16 -> V_163 = V_182 ;
}
return 0 ;
}
static int F_99 ( struct V_19 * V_20 , struct V_15 * V_16 )
{
T_1 V_142 = 0 ;
int V_58 ;
V_58 = F_100 ( V_20 -> V_183 , L_10 , & V_142 ) ;
if ( V_58 ) {
V_16 -> V_163 = 0 ;
V_58 = 0 ;
} else {
V_16 -> V_163 = V_142 & F_101 ( 0 ) ;
}
return V_58 ;
}
static int F_102 ( struct V_19 * V_20 ,
unsigned char * V_180 )
{
int V_58 ;
V_58 = F_103 ( V_20 , L_11 , V_180 , 6 ) ;
if ( V_58 )
V_58 = F_103 ( V_20 , L_12 ,
V_180 , 6 ) ;
if ( V_58 )
return - V_184 ;
return V_185 ;
}
static int F_104 ( struct V_19 * V_20 )
{
int V_5 , V_58 ;
char * V_186 ;
V_58 = F_105 ( V_20 , L_13 ,
( const char * * ) & V_186 ) ;
if ( V_58 )
V_58 = F_105 ( V_20 , L_14 ,
( const char * * ) & V_186 ) ;
if ( V_58 )
return - V_184 ;
for ( V_5 = 0 ; V_5 < V_187 ; V_5 ++ ) {
if ( ! strcasecmp ( V_186 , F_106 ( V_5 ) ) )
return V_5 ;
}
return - V_184 ;
}
static int F_107 ( struct V_15 * V_16 )
{
struct V_188 * V_139 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_189 * V_190 ;
void T_8 * V_191 ;
T_1 V_192 ;
int V_58 = 0 ;
V_139 = V_16 -> V_139 ;
V_20 = & V_139 -> V_20 ;
V_18 = V_16 -> V_18 ;
V_190 = F_108 ( V_139 , V_193 , V_194 ) ;
if ( ! V_190 ) {
F_77 ( V_20 , L_15 ) ;
return - V_184 ;
}
V_16 -> V_191 = F_109 ( V_20 , V_190 -> V_195 , F_110 ( V_190 ) ) ;
if ( ! V_16 -> V_191 ) {
F_77 ( V_20 , L_16 ) ;
return - V_28 ;
}
V_190 = F_108 ( V_139 , V_193 , V_196 ) ;
if ( ! V_190 ) {
F_77 ( V_20 , L_17 ) ;
return - V_184 ;
}
V_16 -> V_197 = F_109 ( V_20 , V_190 -> V_195 ,
F_110 ( V_190 ) ) ;
if ( ! V_16 -> V_197 ) {
F_77 ( V_20 , L_18 ) ;
return - V_28 ;
}
V_190 = F_108 ( V_139 , V_193 , V_198 ) ;
if ( ! V_190 ) {
F_77 ( V_20 , L_19 ) ;
return - V_184 ;
}
V_16 -> V_145 = F_109 ( V_20 , V_190 -> V_195 ,
F_110 ( V_190 ) ) ;
if ( ! V_16 -> V_145 ) {
F_77 ( V_20 , L_20 ) ;
return - V_28 ;
}
if ( V_20 -> V_183 )
V_58 = F_99 ( V_20 , V_16 ) ;
#ifdef F_111
else
V_58 = F_95 ( V_20 , V_16 ) ;
#endif
if ( V_58 )
return V_58 ;
if ( F_102 ( V_20 , V_18 -> V_199 ) != V_185 )
F_112 ( V_18 ) ;
memcpy ( V_18 -> V_200 , V_18 -> V_199 , V_18 -> V_201 ) ;
V_16 -> V_121 = F_104 ( V_20 ) ;
if ( V_16 -> V_121 < 0 ) {
F_77 ( V_20 , L_21 ) ;
return V_16 -> V_121 ;
}
if ( V_16 -> V_121 != V_122 &&
V_16 -> V_121 != V_161 &&
V_16 -> V_121 != V_202 ) {
F_77 ( V_20 , L_22 ) ;
return - V_184 ;
}
V_58 = F_113 ( V_139 , 0 ) ;
if ( V_58 <= 0 ) {
F_77 ( V_20 , L_23 ) ;
V_58 = V_58 ? : - V_203 ;
return V_58 ;
}
V_16 -> V_169 = V_58 ;
if ( V_16 -> V_121 != V_122 ) {
V_58 = F_113 ( V_139 , 1 ) ;
if ( V_58 <= 0 ) {
V_16 -> V_117 = 0 ;
F_114 ( V_20 , L_24
L_25 ) ;
} else {
V_16 -> V_117 = V_204 ;
V_16 -> V_172 = V_58 ;
}
}
V_16 -> V_205 = F_115 ( & V_139 -> V_20 , NULL ) ;
if ( F_116 ( V_16 -> V_205 ) ) {
F_114 ( V_20 , L_26 ) ;
}
if ( V_16 -> V_121 != V_202 )
V_191 = V_16 -> V_191 - ( V_16 -> V_163 * V_206 ) ;
else
V_191 = V_16 -> V_191 ;
V_16 -> V_207 = V_191 + V_208 ;
V_16 -> V_209 = V_191 + V_210 ;
V_16 -> V_211 = V_191 + V_212 ;
if ( V_16 -> V_121 == V_122 ||
V_16 -> V_121 == V_161 ) {
V_16 -> V_213 = V_16 -> V_191 + V_214 ;
V_192 = ( V_16 -> V_140 == V_160 ) ?
V_215 :
V_216 ;
V_16 -> V_217 = V_191 + V_192 ;
} else {
V_16 -> V_213 = V_191 + V_218 ;
V_16 -> V_217 = V_191 + V_219 ;
}
V_16 -> V_220 = V_221 ;
return 0 ;
}
static int F_117 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 ;
T_3 V_10 ;
int V_58 ;
V_58 = V_16 -> V_222 -> V_114 ( V_16 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_90 ( V_18 ) ;
if ( V_58 ) {
F_12 ( V_18 , L_27 ) ;
return V_58 ;
}
V_2 = V_16 -> V_51 -> V_2 ;
F_1 ( V_2 ) ;
V_58 = F_4 ( V_2 , V_16 -> V_220 ) ;
if ( V_58 ) {
F_75 ( V_16 ) ;
return V_58 ;
}
V_10 = F_15 ( V_16 -> V_51 ) ;
V_16 -> V_222 -> V_223 ( V_16 , V_10 , V_2 -> V_142 ) ;
V_16 -> V_113 -> V_224 ( V_16 ) ;
return V_58 ;
}
static void F_118 ( struct V_15 * V_16 )
{
switch ( V_16 -> V_121 ) {
case V_122 :
V_16 -> V_113 = & V_225 ;
V_16 -> V_222 = & V_226 ;
V_16 -> V_40 = V_227 ;
break;
case V_161 :
V_16 -> V_113 = & V_228 ;
V_16 -> V_222 = & V_229 ;
V_16 -> V_40 = V_230 ;
break;
default:
V_16 -> V_113 = & V_231 ;
V_16 -> V_222 = & V_232 ;
V_16 -> V_40 = V_233 ;
break;
}
if ( V_16 -> V_140 == V_160 ) {
switch ( V_16 -> V_163 ) {
case 0 :
V_16 -> V_165 = V_234 ;
V_16 -> V_166 = V_235 ;
V_16 -> V_167 = V_236 ;
V_16 -> V_146 = V_237 ;
break;
case 1 :
V_16 -> V_165 = V_238 ;
V_16 -> V_166 = V_239 ;
V_16 -> V_167 = V_240 ;
V_16 -> V_146 = V_241 ;
break;
default:
break;
}
V_16 -> V_37 = & V_242 ;
} else {
switch ( V_16 -> V_163 ) {
case 0 :
V_16 -> V_165 = V_243 ;
V_16 -> V_166 = V_244 ;
V_16 -> V_167 = V_245 ;
V_16 -> V_146 = V_246 ;
break;
case 1 :
V_16 -> V_165 = V_247 ;
V_16 -> V_166 = V_248 ;
V_16 -> V_167 = V_249 ;
V_16 -> V_146 = V_250 ;
break;
default:
break;
}
V_16 -> V_40 = V_233 ;
V_16 -> V_37 = & V_251 ;
}
}
static void F_119 ( struct V_15 * V_16 )
{
struct V_111 * V_52 ;
V_52 = & V_16 -> V_51 -> V_52 ;
F_120 ( V_16 -> V_18 , V_52 , F_52 , V_252 ) ;
if ( V_16 -> V_117 ) {
V_52 = & V_16 -> V_86 -> V_54 -> V_52 ;
F_120 ( V_16 -> V_18 , V_52 , F_52 ,
V_252 ) ;
}
}
static void F_121 ( struct V_15 * V_16 )
{
struct V_111 * V_52 ;
V_52 = & V_16 -> V_51 -> V_52 ;
F_122 ( V_52 ) ;
if ( V_16 -> V_117 ) {
V_52 = & V_16 -> V_86 -> V_54 -> V_52 ;
F_122 ( V_52 ) ;
}
}
static int F_123 ( struct V_188 * V_139 )
{
struct V_17 * V_18 ;
struct V_15 * V_16 ;
struct V_19 * V_20 = & V_139 -> V_20 ;
struct V_118 * V_113 ;
const struct V_253 * V_254 ;
int V_58 ;
V_18 = F_124 ( sizeof( struct V_15 ) ) ;
if ( ! V_18 )
return - V_28 ;
V_16 = F_6 ( V_18 ) ;
V_16 -> V_139 = V_139 ;
V_16 -> V_18 = V_18 ;
F_125 ( V_18 , V_20 ) ;
F_126 ( V_139 , V_16 ) ;
V_18 -> V_255 = & V_256 ;
F_127 ( V_18 ) ;
V_18 -> V_73 |= V_74 |
V_257 |
V_258 ;
V_254 = F_128 ( V_259 , & V_139 -> V_20 ) ;
if ( V_254 ) {
V_16 -> V_140 = (enum V_260 ) V_254 -> V_30 ;
}
#ifdef F_111
else {
const struct V_261 * V_262 ;
V_262 = F_129 ( V_263 , & V_139 -> V_20 ) ;
if ( V_262 )
V_16 -> V_140 = (enum V_260 ) V_262 -> V_264 ;
}
#endif
if ( ! V_16 -> V_140 ) {
F_130 ( V_18 ) ;
return - V_184 ;
}
V_58 = F_107 ( V_16 ) ;
if ( V_58 )
goto V_168;
F_118 ( V_16 ) ;
V_58 = F_131 ( V_18 ) ;
if ( V_58 ) {
F_12 ( V_18 , L_28 ) ;
goto V_168;
}
V_58 = F_132 ( V_20 , F_133 ( 64 ) ) ;
if ( V_58 ) {
F_12 ( V_18 , L_29 ) ;
goto V_168;
}
V_58 = F_117 ( V_16 ) ;
if ( V_58 )
goto V_168;
F_119 ( V_16 ) ;
V_113 = V_16 -> V_113 ;
if ( V_16 -> V_121 == V_122 )
V_58 = F_134 ( V_16 ) ;
else
F_135 ( & V_16 -> V_124 , V_113 -> V_265 ) ;
return V_58 ;
V_168:
F_136 ( V_18 ) ;
F_130 ( V_18 ) ;
return V_58 ;
}
static int F_137 ( struct V_188 * V_139 )
{
struct V_15 * V_16 ;
struct V_118 * V_113 ;
struct V_17 * V_18 ;
V_16 = F_138 ( V_139 ) ;
V_113 = V_16 -> V_113 ;
V_18 = V_16 -> V_18 ;
V_113 -> V_127 ( V_16 ) ;
V_113 -> V_126 ( V_16 ) ;
F_121 ( V_16 ) ;
if ( V_16 -> V_121 == V_122 )
F_139 ( V_16 ) ;
F_136 ( V_18 ) ;
F_75 ( V_16 ) ;
V_16 -> V_222 -> V_266 ( V_16 ) ;
F_130 ( V_18 ) ;
return 0 ;
}
