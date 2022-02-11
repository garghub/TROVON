static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_2 -> V_4 < V_2 -> V_5 )
V_2 -> V_4 = V_2 -> V_5 ;
if ( V_3 ) {
V_2 -> V_5 = ( V_2 -> V_5 * V_3 ) / 1000 ;
V_2 -> V_4 = ( V_2 -> V_4 * V_3 + 999 ) / 1000 ;
}
}
static void F_2 ( struct V_6 * V_7 ,
unsigned int V_3 )
{
F_1 ( & V_7 -> V_8 , V_3 ) ;
F_1 ( & V_7 -> V_9 , V_3 ) ;
}
static void F_3 ( struct V_10 * V_11 ,
unsigned int V_3 )
{
F_2 ( & V_11 -> V_12 , V_3 ) ;
F_2 ( & V_11 -> V_13 , V_3 ) ;
F_2 ( & V_11 -> V_14 , V_3 ) ;
F_2 ( & V_11 -> V_15 , V_3 ) ;
F_2 ( & V_11 -> V_16 , V_3 ) ;
if ( V_3 )
V_11 -> V_17 . V_18 = ( V_11 -> V_17 . V_18 * V_3 + 999 ) / 1000 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_1 * V_19 )
{
if ( ! V_2 -> V_5 )
V_2 -> V_5 = V_19 -> V_5 ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 = V_19 -> V_4 ;
}
static void F_5 ( struct V_6 * V_7 ,
struct V_6 * V_19 )
{
F_4 ( & V_7 -> V_8 , & V_19 -> V_8 ) ;
F_4 ( & V_7 -> V_9 , & V_19 -> V_9 ) ;
}
static void F_6 ( struct V_10 * V_11 ,
struct V_10 * V_19 )
{
F_5 ( & V_11 -> V_12 , & V_19 -> V_12 ) ;
F_5 ( & V_11 -> V_13 , & V_19 -> V_13 ) ;
F_5 ( & V_11 -> V_14 , & V_19 -> V_14 ) ;
F_5 ( & V_11 -> V_15 , & V_19 -> V_15 ) ;
F_5 ( & V_11 -> V_16 , & V_19 -> V_16 ) ;
if ( ! V_11 -> V_17 . V_18 )
V_11 -> V_17 . V_18 = V_19 -> V_17 . V_18 ;
}
static T_1 F_7 ( const struct F_7 * V_20 )
{
T_1 V_21 = V_20 -> V_22 << V_23 ;
if ( V_20 -> V_24 )
V_21 |= V_25 ;
if ( V_20 -> V_26 )
V_21 |= V_27 ;
if ( V_20 -> V_28 )
V_21 |= V_29 ;
if ( V_20 -> V_30 )
V_21 |= V_31 ;
if ( V_20 -> V_32 )
V_21 |= V_33 ;
if ( V_20 -> V_34 )
V_21 |= V_35 ;
if ( V_20 -> V_36 )
V_21 |= V_37 ;
if ( V_20 -> V_38 )
V_21 |= V_39 ;
if ( V_20 -> V_40 )
V_21 |= V_41 ;
if ( V_20 -> V_42 )
V_21 |= V_43 ;
return V_21 ;
}
static void F_8 ( struct V_1 * V_44 ,
const struct V_1 * V_45 ,
unsigned int V_46 ,
unsigned long V_47 ,
unsigned int V_48 )
{
unsigned int V_5 = V_45 -> V_5 ;
unsigned int V_4 = V_45 -> V_4 ;
V_5 = V_5 - ( V_5 * V_46 >> 7 ) ;
V_4 = V_4 + ( V_4 * V_46 >> 7 ) ;
V_5 = V_5 * V_47 / 1000000 ;
V_4 = ( V_4 * V_47 + 999999 ) / 1000000 ;
V_44 -> V_5 = V_5 >> V_48 ;
V_44 -> V_4 = ( V_4 + ( ( 1 << V_48 ) - 1 ) ) >> V_48 ;
}
static T_1 V_6 ( const struct V_6 * V_7 ,
unsigned int V_46 ,
unsigned long V_47 ,
unsigned int V_49 ,
unsigned int V_50 )
{
struct V_1 V_51 , V_52 ;
V_52 . V_5 = V_7 -> V_8 . V_5 + V_7 -> V_9 . V_5 ;
V_52 . V_4 = V_7 -> V_8 . V_4 + V_7 -> V_9 . V_4 ;
F_8 ( & V_52 , & V_52 ,
V_46 , V_47 , V_49 ) ;
F_8 ( & V_51 , & V_7 -> V_8 ,
V_46 , V_47 , V_50 ) ;
return ( V_52 . V_4 << V_53 ) |
( V_52 . V_5 << V_54 ) |
( V_51 . V_4 << V_55 ) |
( V_51 . V_5 << V_56 ) ;
}
static T_1 F_9 ( const struct F_9 * V_7 ,
unsigned long V_47 )
{
unsigned int V_57 , V_58 , V_18 ;
if ( V_7 -> V_57 < 30 )
V_57 = V_7 -> V_57 & - 2 ;
else
V_57 = 30 ;
if ( V_7 -> V_58 < 48 )
V_58 = ( V_7 -> V_58 + 1 ) & - 2 ;
else
V_58 = 48 ;
V_18 = ( V_7 -> V_18 * V_47 + 999999 ) / 1000000 ;
V_18 = ( V_18 + 7 ) >> 3 ;
return ( V_58 << V_59 ) |
( V_57 << V_60 ) |
( V_18 << V_61 ) ;
}
static T_1 F_10 ( T_1 V_62 , struct V_63 * V_64 )
{
unsigned int V_57 , V_58 , V_65 , V_66 ;
V_65 = V_64 -> V_57 & - 2 ;
V_66 = ( V_64 -> V_58 + 1 ) & - 2 ;
V_57 = ( V_62 & V_67 ) >> V_60 ;
V_58 = ( V_62 & V_68 ) >> V_59 ;
if ( V_65 > V_57 ) {
V_62 &= ~ V_67 ;
V_62 |= V_65 << V_60 ;
}
if ( V_66 < V_58 ) {
V_62 &= ~ V_68 ;
V_62 |= V_66 << V_59 ;
}
return V_62 ;
}
static void F_11 ( struct V_69 * V_70 ,
const struct V_10 * V_11 ,
unsigned int V_46 ,
unsigned int V_47 )
{
V_70 -> V_12 = V_6 ( & V_11 -> V_12 , V_46 , V_47 ,
4 , 4 ) ;
V_70 -> V_13 = V_6 ( & V_11 -> V_13 , V_46 , V_47 ,
1 , 0 ) ;
V_70 -> V_14 = V_6 ( & V_11 -> V_14 , V_46 , V_47 ,
1 , 0 ) ;
V_70 -> V_15 = V_6 ( & V_11 -> V_15 , V_46 , V_47 ,
1 , 0 ) ;
V_70 -> V_16 = V_6 ( & V_11 -> V_16 , V_46 , V_47 ,
1 , 0 ) ;
V_70 -> V_17 = F_9 ( & V_11 -> V_17 , V_47 ) ;
}
static void F_12 ( struct V_71 * V_72 )
{
if ( ! V_72 -> V_46 )
V_72 -> V_46 = 10 ;
V_72 -> V_46 = V_72 -> V_46 * 128 / 100 ;
F_3 ( & V_72 -> V_11 , V_72 -> V_3 ) ;
if ( V_72 -> V_73 ) {
F_3 ( & V_72 -> V_74 , V_72 -> V_3 ) ;
F_6 ( & V_72 -> V_74 , & V_72 -> V_11 ) ;
}
}
static void F_13 ( const struct V_71 * V_72 ,
struct V_75 * V_76 ,
unsigned int V_47 )
{
V_76 -> V_21 = F_7 ( & V_72 -> V_20 ) ;
F_11 ( & V_76 -> V_11 , & V_72 -> V_11 ,
V_72 -> V_46 , V_47 ) ;
if ( V_72 -> V_73 )
F_11 ( & V_76 -> V_74 ,
& V_72 -> V_74 , V_72 -> V_46 ,
V_47 ) ;
}
static void F_14 ( struct V_77 * V_78 ,
struct V_69 * V_70 ,
enum V_79 type )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
T_1 V_17 = V_70 -> V_17 ;
if ( V_81 -> V_82 & F_15 ( type ) )
V_17 = F_10 ( V_70 -> V_17 , & V_81 -> V_83 [ type ] ) ;
F_16 ( V_78 , V_84 , V_70 -> V_12 ) ;
F_16 ( V_78 , V_85 , V_70 -> V_13 ) ;
F_16 ( V_78 , V_86 , V_70 -> V_14 ) ;
F_16 ( V_78 , V_87 , V_70 -> V_15 ) ;
F_16 ( V_78 , V_88 , V_70 -> V_16 ) ;
F_16 ( V_78 , V_89 , V_17 ) ;
F_17 ( V_78 -> V_90 , L_1 ,
V_70 -> V_12 , V_70 -> V_13 , V_70 -> V_14 , V_70 -> V_15 , V_70 -> V_16 , V_17 ) ;
}
static void F_18 ( struct V_77 * V_78 ,
struct V_63 * V_64 )
{
if ( V_64 ) {
F_17 ( V_78 -> V_90 , L_2 ,
( unsigned long long ) V_64 -> V_91 ,
( unsigned long long ) V_64 -> V_92 ) ;
F_16 ( V_78 , V_93 , ( T_1 ) V_64 -> V_91 ) ;
F_16 ( V_78 , V_94 , ( T_1 ) ( V_64 -> V_91
>> 32 ) ) ;
F_16 ( V_78 , V_95 , ( T_1 ) V_64 -> V_92 ) ;
F_16 ( V_78 , V_96 , ( T_1 ) ( V_64 -> V_92
>> 32 ) ) ;
} else {
F_17 ( V_78 -> V_90 , L_3 ) ;
F_16 ( V_78 , V_95 , 0 ) ;
F_16 ( V_78 , V_96 , 0 ) ;
}
}
static void F_19 ( struct V_77 * V_78 ,
struct V_63 * V_64 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
T_1 V_97 , V_98 ;
V_97 = F_20 ( V_78 , V_99 ) ;
if ( V_64 ) {
V_81 -> V_83 [ V_100 ] = * V_64 ;
V_81 -> V_82 |= V_101 ;
V_98 = V_102 ;
V_97 &= ~ ( V_103 | V_104 ) ;
} else {
V_81 -> V_82 &= ~ V_101 ;
V_97 &= ~ V_102 ;
V_98 = V_103 | V_104 ;
}
V_97 |= V_98 ;
F_18 ( V_78 , V_64 ) ;
F_16 ( V_78 , V_105 , V_98 ) ;
F_16 ( V_78 , V_99 , V_97 ) ;
}
static void F_21 ( struct V_77 * V_78 ,
struct V_63 * V_64 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
if ( V_64 ) {
V_81 -> V_83 [ V_106 ] = * V_64 ;
V_81 -> V_82 |= V_107 ;
} else {
V_81 -> V_82 &= ~ V_107 ;
}
}
static int F_22 ( struct V_108 * V_90 , enum V_79 type ,
struct V_109 * V_110 )
{
struct V_77 * V_78 = V_90 -> V_78 ;
struct V_80 * V_81 = & V_78 -> V_81 ;
struct V_63 V_64 , * V_111 = & V_64 ;
int V_112 = 0 ;
F_17 ( V_78 -> V_90 , L_4 ,
type == V_106 ? L_5 : L_6 ,
V_110 -> V_91 ,
V_110 -> V_92 ) ;
F_23 ( & V_78 -> V_113 ) ;
if ( ! V_110 -> V_92 ) {
V_111 = NULL ;
goto V_114;
}
if ( ! V_81 -> V_72 || ! V_81 -> V_72 -> V_64 ) {
V_112 = - V_115 ;
goto V_116;
}
V_64 . V_57 = 0 ;
V_64 . V_58 = ~ 0 ;
if ( type == V_100 ) {
V_112 = V_81 -> V_72 -> V_64 ( V_110 , & V_64 ,
V_90 -> V_117 ) ;
} else {
V_112 = V_81 -> V_72 -> V_64 ( V_110 , & V_64 ,
1ULL << V_90 -> V_118 ) ;
}
if ( V_112 )
goto V_116;
F_17 ( V_78 -> V_90 , L_7 ,
type == V_106 ? L_5 : L_6 ,
( unsigned long long ) V_64 . V_91 ,
( unsigned long long ) V_64 . V_92 ) ;
V_114:
switch ( type ) {
case V_100 :
F_19 ( V_78 , V_111 ) ;
break;
case V_106 :
F_21 ( V_78 , V_111 ) ;
break;
default:
V_112 = - V_115 ;
}
V_116:
F_24 ( & V_78 -> V_113 ) ;
return V_112 ;
}
static int F_25 ( struct V_108 * V_90 ,
struct V_109 * V_110 )
{
return F_22 ( V_90 , V_100 , V_110 ) ;
}
static int F_26 ( struct V_108 * V_90 ,
struct V_109 * V_110 )
{
return F_22 ( V_90 , V_106 , V_110 ) ;
}
static void F_27 ( struct V_77 * V_78 ,
const struct V_71 * V_72 ,
T_2 V_119 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
struct V_108 * V_120 = V_81 -> V_120 ;
T_1 V_121 , V_97 ;
F_23 ( & V_78 -> V_113 ) ;
V_81 -> V_122 = true ;
F_24 ( & V_78 -> V_113 ) ;
F_28 ( & V_81 -> V_123 ) ;
F_28 ( & V_81 -> V_124 ) ;
F_23 ( & V_78 -> V_113 ) ;
V_81 -> V_122 = false ;
F_16 ( V_78 , V_125 , 0 ) ;
V_97 = F_20 ( V_78 , V_99 ) ;
F_16 ( V_78 , V_99 , V_97 & V_126 ) ;
F_16 ( V_78 , V_105 , V_127 & ~ V_126 ) ;
V_121 = F_20 ( V_78 , V_128 ) ;
if ( V_121 & ( V_129 | V_130 ) ) {
V_121 &= ~ ( V_129 | V_130 ) ;
F_16 ( V_78 , V_128 , V_121 ) ;
}
F_20 ( V_78 , V_131 ) ;
F_20 ( V_78 , V_132 ) ;
V_81 -> V_133 = V_134 ;
V_120 -> V_135 . V_91 = 0 ;
V_120 -> V_135 . V_92 = 0 ;
V_120 -> V_118 = V_136 ;
F_19 ( V_78 , NULL ) ;
F_21 ( V_78 , NULL ) ;
V_81 -> V_117 = 0 ;
V_81 -> V_72 = V_72 ;
if ( ! V_72 )
goto V_116;
if ( ! V_119 )
V_119 = V_72 -> type ;
V_81 -> V_117 = V_119 ;
F_13 ( V_72 , & V_81 -> V_76 , V_81 -> V_137 ) ;
F_14 ( V_78 , & V_81 -> V_76 . V_11 , V_100 ) ;
F_16 ( V_78 , V_125 , V_81 -> V_76 . V_21 ) ;
V_116:
F_24 ( & V_78 -> V_113 ) ;
}
static bool F_29 ( struct V_77 * V_78 ,
const struct V_71 * V_138 )
{
unsigned int V_139 ;
V_139 = V_138 -> V_20 . V_22 ;
if ( V_78 -> V_81 . V_140 [ V_139 ] & V_141 )
return false ;
return true ;
}
static T_2 F_30 ( struct V_77 * V_78 )
{
T_2 V_142 = 0 ;
struct V_71 * * V_143 ;
for ( V_143 = V_144 ; * V_143 ; ++ V_143 ) {
const struct V_71 * V_138 = * V_143 ;
if ( F_29 ( V_78 , V_138 ) )
V_142 |= V_138 -> type ;
}
return V_142 ;
}
static int F_31 ( struct V_108 * V_90 , T_2 * V_145 )
{
struct V_77 * V_78 = V_90 -> V_78 ;
struct V_80 * V_81 = & V_78 -> V_81 ;
struct V_108 * V_120 = V_81 -> V_120 ;
struct V_71 * * V_143 ;
T_2 V_146 ;
if ( ! * V_145 ) {
F_27 ( V_78 , NULL , 0 ) ;
goto V_147;
}
for ( V_143 = V_144 ; * V_143 ; ++ V_143 ) {
const struct V_71 * V_138 = * V_143 ;
if ( ! F_29 ( V_78 , V_138 ) )
continue;
if ( * V_145 & V_138 -> type ) {
* V_145 &= V_138 -> type ;
F_27 ( V_78 , V_138 , * V_145 ) ;
goto V_147;
}
}
return - V_115 ;
V_147:
V_146 = * V_145 ;
if ( ! V_81 -> V_72 || ! V_81 -> V_72 -> V_64 )
V_146 = 0 ;
V_120 -> V_148 = V_146 ;
return 0 ;
}
static void F_32 ( struct V_77 * V_78 , T_2 V_119 )
{
struct V_108 * V_120 = V_78 -> V_81 . V_120 ;
F_33 ( & V_120 -> V_113 ) ;
V_120 -> V_117 = V_119 ;
V_120 -> V_148 = V_119 ;
F_34 ( & V_120 -> V_113 ) ;
}
static void F_35 ( void )
{
struct V_71 * * V_143 ;
F_36 ( & V_149 ) ;
if ( ! V_150 ) {
for ( V_143 = V_144 ; * V_143 ; ++ V_143 )
F_12 ( * V_143 ) ;
V_150 = true ;
}
F_37 ( & V_149 ) ;
}
static int F_38 ( struct V_77 * V_78 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
int V_112 = 0 ;
F_23 ( & V_78 -> V_113 ) ;
if ( V_81 -> V_82 & V_107 ) {
V_81 -> V_151 = F_20 ( V_78 , V_99 ) ;
F_16 ( V_78 , V_99 , V_102 ) ;
F_18 ( V_78 , & V_81 -> V_83 [ V_106 ] ) ;
F_14 ( V_78 , & V_81 -> V_76 . V_11 ,
V_106 ) ;
V_81 -> V_133 = V_152 ;
V_112 = 1 ;
}
F_24 ( & V_78 -> V_113 ) ;
return V_112 ;
}
static int F_39 ( struct V_77 * V_78 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
int V_112 = 0 ;
F_23 ( & V_78 -> V_113 ) ;
if ( V_81 -> V_82 & V_107 ) {
if ( V_81 -> V_82 & V_101 ) {
F_16 ( V_78 , V_99 ,
( V_81 -> V_151 & V_126 ) |
V_102 ) ;
F_18 ( V_78 ,
& V_81 -> V_83 [ V_100 ] ) ;
} else {
F_16 ( V_78 , V_99 ,
( V_81 -> V_151 & V_126 ) |
V_103 |
V_104 ) ;
F_18 ( V_78 , NULL ) ;
}
F_14 ( V_78 , & V_81 -> V_76 . V_11 ,
V_100 ) ;
V_81 -> V_133 = V_134 ;
V_112 = 1 ;
}
F_24 ( & V_78 -> V_113 ) ;
return V_112 ;
}
static void F_40 ( struct V_77 * V_78 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
if ( V_81 -> V_133 == V_134 ) {
F_16 ( V_78 , V_125 , 0 ) ;
V_81 -> V_133 = V_153 ;
F_14 ( V_78 , & V_81 -> V_76 . V_74 ,
V_100 ) ;
F_16 ( V_78 , V_125 , V_81 -> V_76 . V_21 ) ;
}
}
static void F_41 ( struct V_77 * V_78 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
if ( V_81 -> V_133 == V_153 ) {
F_16 ( V_78 , V_125 , 0 ) ;
V_81 -> V_133 = V_134 ;
F_14 ( V_78 , & V_81 -> V_76 . V_11 ,
V_100 ) ;
F_16 ( V_78 , V_125 , V_81 -> V_76 . V_21 ) ;
}
}
static void F_42 ( struct V_77 * V_78 , T_1 V_154 , T_2 V_155 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
const struct V_71 * V_138 = V_81 -> V_72 ;
int V_112 = V_156 ;
struct V_157 V_158 ;
V_158 . V_159 = V_136 ;
V_158 . V_160 = 0 ;
if ( V_138 -> V_161 )
V_112 = V_138 -> V_161 ( V_154 , V_155 , V_81 -> V_117 , & V_158 ) ;
else if ( V_154 >= 32 )
V_158 . V_161 = ( T_1 ) V_155 ;
else if ( V_154 < 32 )
V_158 . V_161 = ( T_1 ) V_155 & ( ( 1 << V_154 ) - 1 ) ;
F_17 ( V_78 -> V_90 , L_8 ,
V_154 , ( unsigned long long ) V_155 ) ;
if ( V_112 == V_156 ) {
F_17 ( V_78 -> V_90 , L_9 ,
V_158 . V_161 , V_158 . V_160 ) ;
F_43 ( V_81 -> V_120 , V_158 . V_159 , V_158 . V_161 ,
V_158 . V_160 ) ;
F_41 ( V_78 ) ;
} else if ( V_112 == V_162 ) {
if ( V_81 -> V_133 == V_153 ) {
F_17 ( V_78 -> V_90 , L_10 ) ;
F_44 ( V_81 -> V_120 ) ;
} else {
F_17 ( V_78 -> V_90 , L_11 ) ;
}
} else {
F_17 ( V_78 -> V_90 , L_12 , V_112 ) ;
return;
}
if ( V_138 -> V_73 && ! V_81 -> V_122 ) {
unsigned long V_163 ;
F_40 ( V_78 ) ;
V_163 = V_138 -> V_73 + ( V_138 -> V_73 >> 3 ) ;
F_45 ( & V_81 -> V_123 ,
V_164 + F_46 ( V_163 ) ) ;
}
}
static void F_47 ( unsigned long V_165 )
{
struct V_77 * V_78 = (struct V_77 * ) V_165 ;
F_23 ( & V_78 -> V_113 ) ;
F_41 ( V_78 ) ;
F_24 ( & V_78 -> V_113 ) ;
}
static void F_48 ( unsigned long V_165 )
{
struct V_77 * V_78 = (struct V_77 * ) V_165 ;
F_23 ( & V_78 -> V_113 ) ;
if ( ( V_78 -> V_81 . V_166 & V_126 ) ==
F_20 ( V_78 , V_99 ) )
F_16 ( V_78 , V_99 ,
V_78 -> V_81 . V_166 ) ;
F_16 ( V_78 , V_125 , V_78 -> V_81 . V_76 . V_21 ) ;
F_24 ( & V_78 -> V_113 ) ;
}
static void F_49 ( struct V_77 * V_78 ,
struct V_167 * V_168 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
F_17 ( V_78 -> V_90 , L_13 ,
V_168 -> V_169 , V_168 -> V_170 ) ;
F_23 ( & V_78 -> V_113 ) ;
if ( V_81 -> V_137 == V_168 -> V_170 )
goto V_116;
V_81 -> V_137 = V_168 -> V_170 ;
if ( V_81 -> V_72 ) {
F_13 ( V_81 -> V_72 , & V_81 -> V_76 ,
V_81 -> V_137 ) ;
switch ( V_81 -> V_133 ) {
case V_134 :
F_14 ( V_78 , & V_81 -> V_76 . V_11 ,
V_100 ) ;
break;
case V_153 :
F_14 ( V_78 , & V_81 -> V_76 . V_74 ,
V_100 ) ;
break;
#ifdef F_50
case V_152 :
F_14 ( V_78 , & V_81 -> V_76 . V_11 ,
V_106 ) ;
break;
#endif
}
}
V_116:
F_24 ( & V_78 -> V_113 ) ;
}
static int F_51 ( struct V_171 * V_172 , unsigned long V_173 ,
void * V_91 )
{
struct V_77 * V_78 = F_52 ( V_172 , struct V_77 ,
V_81 . V_174 ) ;
switch ( V_173 ) {
case V_175 :
F_49 ( V_78 , V_91 ) ;
break;
default:
break;
}
return V_176 ;
}
void F_53 ( struct V_77 * V_78 , T_1 V_177 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
T_1 V_121 , V_154 , V_178 , V_179 ;
unsigned int V_139 ;
if ( ! V_81 -> V_72 )
return;
V_139 = V_81 -> V_72 -> V_20 . V_22 ;
V_121 = F_20 ( V_78 , V_128 ) ;
if ( ! ( V_121 & ( V_129 | V_130 ) ) ) {
if ( ! ( V_78 -> V_81 . V_140 [ V_139 ] & V_180 ) ||
V_81 -> V_122 )
return;
F_16 ( V_78 , V_125 , 0 ) ;
V_81 -> V_166 = F_20 ( V_78 , V_99 ) ;
F_16 ( V_78 , V_99 ,
V_81 -> V_166 & V_126 ) ;
F_45 ( & V_81 -> V_124 ,
V_164 + F_46 ( 5 ) ) ;
return;
}
V_121 &= ~ ( V_129 | V_130 ) ;
F_16 ( V_78 , V_128 , V_121 ) ;
V_154 = ( V_121 & V_181 ) >> V_182 ;
if ( V_81 -> V_140 [ V_139 ] & V_183 )
++ V_154 ;
V_178 = F_20 ( V_78 , V_131 ) ;
V_179 = F_20 ( V_78 , V_132 ) ;
F_42 ( V_78 , V_154 , ( T_2 ) V_179 << 32 | V_178 ) ;
}
void F_54 ( struct V_77 * V_78 )
{
struct V_71 * * V_143 ;
if ( ! V_78 -> V_81 . V_120 )
return;
for ( V_143 = V_144 ; * V_143 ; ++ V_143 ) {
const struct V_71 * V_138 = * V_143 ;
if ( F_29 ( V_78 , V_138 ) ) {
F_32 ( V_78 , V_138 -> type ) ;
F_27 ( V_78 , V_138 , 0 ) ;
return;
}
}
F_27 ( V_78 , NULL , 0 ) ;
}
static void F_55 ( struct V_77 * V_78 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
V_81 -> V_140 [ V_184 ]
|= V_183 ;
V_81 -> V_140 [ V_185 ]
|= V_180 ;
V_81 -> V_140 [ V_186 ]
|= V_141 ;
}
int F_56 ( struct V_77 * V_78 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
struct V_108 * V_120 ;
int error ;
F_35 () ;
F_55 ( V_78 ) ;
F_57 ( & V_81 -> V_123 , F_47 , ( unsigned long ) V_78 ) ;
F_57 ( & V_81 -> V_124 , F_48 ,
( unsigned long ) V_78 ) ;
if ( ! F_58 ( V_78 -> V_187 ) ) {
V_81 -> V_137 = F_59 ( V_78 -> V_187 ) ;
#ifdef F_60
V_81 -> V_174 . V_188 = F_51 ;
error = F_61 ( V_78 -> V_187 , & V_81 -> V_174 ) ;
if ( error )
F_62 ( V_78 -> V_90 ,
L_14 ) ;
#endif
} else {
V_81 -> V_137 = 32768 ;
}
V_81 -> V_120 = V_120 = F_63 ( V_189 ) ;
if ( ! V_120 ) {
F_64 ( V_78 -> V_90 , L_15 ) ;
error = - V_190 ;
goto V_191;
}
V_120 -> V_78 = V_78 ;
V_120 -> V_192 = V_193 ;
V_120 -> V_194 = F_30 ( V_78 ) ;
V_120 -> V_195 = L_16 ;
V_120 -> V_196 = F_25 ;
V_120 -> V_197 = F_26 ;
error = F_65 ( V_120 ) ;
if ( error ) {
F_64 ( V_78 -> V_90 , L_17 ) ;
goto V_198;
}
V_120 -> V_199 = F_31 ;
F_66 ( V_78 -> V_90 , 1 ) ;
return 0 ;
V_198:
F_27 ( V_78 , NULL , 0 ) ;
V_81 -> V_120 = NULL ;
F_67 ( V_120 ) ;
V_191:
#ifdef F_60
if ( ! F_58 ( V_78 -> V_187 ) )
F_68 ( V_78 -> V_187 , & V_81 -> V_174 ) ;
#endif
return error ;
}
void F_69 ( struct V_77 * V_78 )
{
struct V_80 * V_81 = & V_78 -> V_81 ;
struct V_108 * V_120 = V_81 -> V_120 ;
if ( ! V_120 )
return;
F_27 ( V_78 , NULL , 0 ) ;
V_81 -> V_120 = NULL ;
F_70 ( V_120 ) ;
#ifdef F_60
if ( ! F_58 ( V_78 -> V_187 ) )
F_68 ( V_78 -> V_187 , & V_81 -> V_174 ) ;
#endif
}
int F_71 ( struct V_200 * V_90 )
{
struct V_77 * V_78 = F_72 ( V_90 ) ;
if ( F_73 ( V_90 ) && F_38 ( V_78 ) )
F_74 ( V_78 -> V_201 ) ;
return 0 ;
}
int F_75 ( struct V_200 * V_90 )
{
struct V_77 * V_78 = F_72 ( V_90 ) ;
if ( F_73 ( V_90 ) && F_39 ( V_78 ) )
F_76 ( V_78 -> V_201 ) ;
return 0 ;
}
