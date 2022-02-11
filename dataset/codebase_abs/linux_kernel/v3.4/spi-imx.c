static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_5 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_6 ;
}
static inline unsigned F_3 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 -> V_4 == V_7 ) ? 64 : 8 ;
}
static unsigned int F_4 ( unsigned int V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
int V_11 ;
for ( V_11 = 2 ; V_11 < V_10 ; V_11 ++ )
if ( V_9 * V_12 [ V_11 ] >= V_8 )
return V_11 ;
return V_10 ;
}
static unsigned int F_5 ( unsigned int V_8 ,
unsigned int V_9 )
{
int V_11 , div = 4 ;
for ( V_11 = 0 ; V_11 < 7 ; V_11 ++ ) {
if ( V_9 * div >= V_8 )
return V_11 ;
div <<= 1 ;
}
return 7 ;
}
static unsigned int F_6 ( unsigned int V_8 , unsigned int V_9 )
{
unsigned int V_13 , V_14 ;
if ( F_7 ( V_9 > V_8 ) )
return 0 ;
V_14 = F_8 ( V_8 ) - F_8 ( V_9 ) ;
if ( V_8 > V_9 << V_14 )
V_14 ++ ;
V_14 = V_10 ( 4U , V_14 ) - 4 ;
if ( F_7 ( V_14 > 0xf ) ) {
F_9 ( L_1 ,
V_15 , V_9 , V_8 ) ;
return 0xff ;
}
V_13 = F_10 ( V_8 , V_9 << V_14 ) - 1 ;
F_11 ( L_2 ,
V_15 , V_8 , V_9 , V_14 , V_13 ) ;
return ( V_13 << V_16 ) |
( V_14 << V_17 ) ;
}
static void T_1 F_12 ( struct V_1 * V_18 , int V_19 )
{
unsigned V_20 = 0 ;
if ( V_19 & V_21 )
V_20 |= V_22 ;
if ( V_19 & V_23 )
V_20 |= V_24 ;
F_13 ( V_20 , V_18 -> V_25 + V_26 ) ;
}
static void T_1 F_14 ( struct V_1 * V_18 )
{
T_2 V_27 ;
V_27 = F_15 ( V_18 -> V_25 + V_28 ) ;
V_27 |= V_29 ;
F_13 ( V_27 , V_18 -> V_25 + V_28 ) ;
}
static int T_1 F_16 ( struct V_1 * V_18 ,
struct V_30 * V_31 )
{
T_2 V_32 = V_33 , V_34 = 0 ;
V_32 |= V_35 ;
V_32 |= F_6 ( V_18 -> V_36 , V_31 -> V_37 ) ;
V_32 |= F_17 ( V_31 -> V_38 ) ;
V_32 |= ( V_31 -> V_39 - 1 ) << V_40 ;
V_34 |= F_18 ( V_31 -> V_38 ) ;
if ( V_31 -> V_41 & V_42 )
V_34 |= F_19 ( V_31 -> V_38 ) ;
if ( V_31 -> V_41 & V_43 )
V_34 |= F_20 ( V_31 -> V_38 ) ;
if ( V_31 -> V_41 & V_44 )
V_34 |= F_21 ( V_31 -> V_38 ) ;
F_13 ( V_32 , V_18 -> V_25 + V_28 ) ;
F_13 ( V_34 , V_18 -> V_25 + V_45 ) ;
return 0 ;
}
static int T_1 F_22 ( struct V_1 * V_18 )
{
return F_15 ( V_18 -> V_25 + V_46 ) & V_47 ;
}
static void T_1 F_23 ( struct V_1 * V_18 )
{
while ( F_22 ( V_18 ) )
F_15 ( V_18 -> V_25 + V_48 ) ;
}
static void T_1 F_24 ( struct V_1 * V_18 , int V_19 )
{
unsigned int V_20 = 0 ;
if ( V_19 & V_21 )
V_20 |= V_49 ;
if ( V_19 & V_23 )
V_20 |= V_50 ;
F_13 ( V_20 , V_18 -> V_25 + V_51 ) ;
}
static void T_1 F_25 ( struct V_1 * V_18 )
{
unsigned int V_27 ;
V_27 = F_15 ( V_18 -> V_25 + V_52 ) ;
V_27 |= V_53 ;
F_13 ( V_27 , V_18 -> V_25 + V_52 ) ;
}
static int T_1 F_26 ( struct V_1 * V_18 ,
struct V_30 * V_31 )
{
unsigned int V_27 = V_54 | V_55 ;
int V_38 = V_18 -> V_56 [ V_31 -> V_38 ] ;
V_27 |= F_5 ( V_18 -> V_36 , V_31 -> V_37 ) <<
V_57 ;
if ( F_2 ( V_18 ) ) {
V_27 |= ( V_31 -> V_39 - 1 ) << V_58 ;
V_27 |= V_59 ;
} else {
V_27 |= ( V_31 -> V_39 - 1 ) << V_60 ;
}
if ( V_31 -> V_41 & V_42 )
V_27 |= V_61 ;
if ( V_31 -> V_41 & V_43 )
V_27 |= V_62 ;
if ( V_31 -> V_41 & V_44 )
V_27 |= V_63 ;
if ( V_38 < 0 )
V_27 |= ( V_38 + 32 ) <<
( F_2 ( V_18 ) ? V_64 :
V_65 ) ;
F_13 ( V_27 , V_18 -> V_25 + V_52 ) ;
return 0 ;
}
static int T_1 F_27 ( struct V_1 * V_18 )
{
return F_15 ( V_18 -> V_25 + V_66 ) & V_67 ;
}
static void T_1 F_28 ( struct V_1 * V_18 )
{
while ( F_15 ( V_18 -> V_25 + V_66 ) & V_67 )
F_15 ( V_18 -> V_25 + V_48 ) ;
}
static void T_1 F_29 ( struct V_1 * V_18 , int V_19 )
{
unsigned int V_20 = 0 ;
if ( V_19 & V_21 )
V_20 |= V_68 ;
if ( V_19 & V_23 )
V_20 |= V_69 ;
F_13 ( V_20 , V_18 -> V_25 + V_51 ) ;
}
static void T_1 F_30 ( struct V_1 * V_18 )
{
unsigned int V_27 ;
V_27 = F_15 ( V_18 -> V_25 + V_52 ) ;
V_27 |= V_70 ;
F_13 ( V_27 , V_18 -> V_25 + V_52 ) ;
}
static int T_1 F_31 ( struct V_1 * V_18 ,
struct V_30 * V_31 )
{
unsigned int V_27 = V_71 | V_72 ;
int V_38 = V_18 -> V_56 [ V_31 -> V_38 ] ;
unsigned int V_10 = F_1 ( V_18 ) ? 16 : 18 ;
V_27 |= F_4 ( V_18 -> V_36 , V_31 -> V_37 , V_10 ) <<
V_73 ;
V_27 |= V_31 -> V_39 - 1 ;
if ( V_31 -> V_41 & V_42 )
V_27 |= V_74 ;
if ( V_31 -> V_41 & V_43 )
V_27 |= V_75 ;
if ( V_31 -> V_41 & V_44 )
V_27 |= V_76 ;
if ( V_38 < 0 )
V_27 |= ( V_38 + 32 ) << V_77 ;
F_13 ( V_27 , V_18 -> V_25 + V_52 ) ;
return 0 ;
}
static int T_1 F_32 ( struct V_1 * V_18 )
{
return F_15 ( V_18 -> V_25 + V_51 ) & V_78 ;
}
static void T_1 F_33 ( struct V_1 * V_18 )
{
F_13 ( 1 , V_18 -> V_25 + V_79 ) ;
}
static void T_1 F_34 ( struct V_1 * V_18 , int V_19 )
{
unsigned int V_20 = 0 ;
if ( V_19 & V_21 )
V_20 |= V_80 ;
if ( V_19 & V_23 )
V_20 |= V_81 ;
F_13 ( V_20 , V_18 -> V_25 + V_51 ) ;
}
static void T_1 F_35 ( struct V_1 * V_18 )
{
unsigned int V_27 ;
V_27 = F_15 ( V_18 -> V_25 + V_52 ) ;
V_27 |= V_82 ;
F_13 ( V_27 , V_18 -> V_25 + V_52 ) ;
}
static int T_1 F_36 ( struct V_1 * V_18 ,
struct V_30 * V_31 )
{
unsigned int V_27 = V_83 | V_84 ;
V_27 |= F_5 ( V_18 -> V_36 , V_31 -> V_37 ) <<
V_85 ;
V_27 |= V_31 -> V_39 - 1 ;
if ( V_31 -> V_41 & V_42 )
V_27 |= V_86 ;
if ( V_31 -> V_41 & V_43 )
V_27 |= V_87 ;
F_13 ( V_27 , V_18 -> V_25 + V_52 ) ;
return 0 ;
}
static int T_1 F_37 ( struct V_1 * V_18 )
{
return F_15 ( V_18 -> V_25 + V_51 ) & V_88 ;
}
static void T_1 F_38 ( struct V_1 * V_18 )
{
F_13 ( 1 , V_18 -> V_25 + V_79 ) ;
}
static void F_39 ( struct V_89 * V_90 , int V_91 )
{
struct V_1 * V_18 = F_40 ( V_90 -> V_92 ) ;
int V_93 = V_18 -> V_56 [ V_90 -> V_94 ] ;
int V_95 = V_91 != V_96 ;
int V_97 = ! ( V_90 -> V_41 & V_44 ) ;
if ( V_93 < 0 )
return;
F_41 ( V_93 , V_97 ^ V_95 ) ;
}
static void F_42 ( struct V_1 * V_18 )
{
while ( V_18 -> V_98 < F_3 ( V_18 ) ) {
if ( ! V_18 -> V_99 )
break;
V_18 -> V_100 ( V_18 ) ;
V_18 -> V_98 ++ ;
}
V_18 -> V_3 -> V_101 ( V_18 ) ;
}
static T_3 F_43 ( int V_102 , void * V_103 )
{
struct V_1 * V_18 = V_103 ;
while ( V_18 -> V_3 -> V_104 ( V_18 ) ) {
V_18 -> V_105 ( V_18 ) ;
V_18 -> V_98 -- ;
}
if ( V_18 -> V_99 ) {
F_42 ( V_18 ) ;
return V_106 ;
}
if ( V_18 -> V_98 ) {
V_18 -> V_3 -> V_107 (
V_18 , V_23 ) ;
return V_106 ;
}
V_18 -> V_3 -> V_107 ( V_18 , 0 ) ;
F_44 ( & V_18 -> V_108 ) ;
return V_106 ;
}
static int F_45 ( struct V_89 * V_90 ,
struct V_109 * V_110 )
{
struct V_1 * V_18 = F_40 ( V_90 -> V_92 ) ;
struct V_30 V_31 ;
V_31 . V_39 = V_110 ? V_110 -> V_111 : V_90 -> V_111 ;
V_31 . V_37 = V_110 ? V_110 -> V_37 : V_90 -> V_112 ;
V_31 . V_41 = V_90 -> V_41 ;
V_31 . V_38 = V_90 -> V_94 ;
if ( ! V_31 . V_37 )
V_31 . V_37 = V_90 -> V_112 ;
if ( ! V_31 . V_39 )
V_31 . V_39 = V_90 -> V_111 ;
if ( ! V_31 . V_37 )
V_31 . V_37 = V_90 -> V_112 ;
if ( V_31 . V_39 <= 8 ) {
V_18 -> V_105 = V_113 ;
V_18 -> V_100 = V_114 ;
} else if ( V_31 . V_39 <= 16 ) {
V_18 -> V_105 = V_115 ;
V_18 -> V_100 = V_116 ;
} else if ( V_31 . V_39 <= 32 ) {
V_18 -> V_105 = V_117 ;
V_18 -> V_100 = V_118 ;
} else
F_46 () ;
V_18 -> V_3 -> V_31 ( V_18 , & V_31 ) ;
return 0 ;
}
static int F_47 ( struct V_89 * V_90 ,
struct V_109 * V_119 )
{
struct V_1 * V_18 = F_40 ( V_90 -> V_92 ) ;
V_18 -> V_120 = V_119 -> V_120 ;
V_18 -> V_121 = V_119 -> V_121 ;
V_18 -> V_99 = V_119 -> V_122 ;
V_18 -> V_98 = 0 ;
F_48 ( & V_18 -> V_108 ) ;
F_42 ( V_18 ) ;
V_18 -> V_3 -> V_107 ( V_18 , V_21 ) ;
F_49 ( & V_18 -> V_108 ) ;
return V_119 -> V_122 ;
}
static int F_50 ( struct V_89 * V_90 )
{
struct V_1 * V_18 = F_40 ( V_90 -> V_92 ) ;
int V_93 = V_18 -> V_56 [ V_90 -> V_94 ] ;
F_51 ( & V_90 -> V_123 , L_3 , V_15 ,
V_90 -> V_41 , V_90 -> V_111 , V_90 -> V_112 ) ;
if ( V_93 >= 0 )
F_52 ( V_93 , V_90 -> V_41 & V_44 ? 0 : 1 ) ;
F_39 ( V_90 , V_96 ) ;
return 0 ;
}
static void F_53 ( struct V_89 * V_90 )
{
}
static int T_4 F_54 ( struct V_124 * V_125 )
{
struct V_126 * V_127 = V_125 -> V_123 . V_128 ;
const struct V_129 * V_130 =
F_55 ( V_131 , & V_125 -> V_123 ) ;
struct V_132 * V_133 =
F_56 ( & V_125 -> V_123 ) ;
struct V_134 * V_92 ;
struct V_1 * V_18 ;
struct V_135 * V_136 ;
int V_11 , V_137 , V_138 ;
if ( ! V_127 && ! V_133 ) {
F_57 ( & V_125 -> V_123 , L_4 ) ;
return - V_139 ;
}
V_137 = F_58 ( V_127 , L_5 , & V_138 ) ;
if ( V_137 < 0 ) {
if ( V_133 )
V_138 = V_133 -> V_140 ;
else
return V_137 ;
}
V_92 = F_59 ( & V_125 -> V_123 ,
sizeof( struct V_1 ) + sizeof( int ) * V_138 ) ;
if ( ! V_92 )
return - V_141 ;
F_60 ( V_125 , V_92 ) ;
V_92 -> V_142 = V_125 -> V_143 ;
V_92 -> V_140 = V_138 ;
V_18 = F_40 ( V_92 ) ;
V_18 -> V_144 . V_92 = F_61 ( V_92 ) ;
for ( V_11 = 0 ; V_11 < V_92 -> V_140 ; V_11 ++ ) {
int V_145 = F_62 ( V_127 , L_6 , V_11 ) ;
if ( V_145 < 0 && V_133 )
V_145 = V_133 -> V_56 [ V_11 ] ;
V_18 -> V_56 [ V_11 ] = V_145 ;
if ( V_145 < 0 )
continue;
V_137 = F_63 ( V_18 -> V_56 [ V_11 ] , V_146 ) ;
if ( V_137 ) {
F_57 ( & V_125 -> V_123 , L_7 ) ;
goto V_147;
}
}
V_18 -> V_144 . V_56 = F_39 ;
V_18 -> V_144 . V_148 = F_45 ;
V_18 -> V_144 . V_149 = F_47 ;
V_18 -> V_144 . V_92 -> V_150 = F_50 ;
V_18 -> V_144 . V_92 -> V_151 = F_53 ;
V_18 -> V_144 . V_92 -> V_152 = V_43 | V_42 | V_44 ;
F_48 ( & V_18 -> V_108 ) ;
V_18 -> V_3 = V_130 ? V_130 -> V_153 :
(struct V_154 * ) V_125 -> V_155 -> V_156 ;
V_136 = F_64 ( V_125 , V_157 , 0 ) ;
if ( ! V_136 ) {
F_57 ( & V_125 -> V_123 , L_8 ) ;
V_137 = - V_141 ;
goto V_147;
}
if ( ! F_65 ( V_136 -> V_158 , F_66 ( V_136 ) , V_125 -> V_159 ) ) {
F_57 ( & V_125 -> V_123 , L_9 ) ;
V_137 = - V_160 ;
goto V_147;
}
V_18 -> V_25 = F_67 ( V_136 -> V_158 , F_66 ( V_136 ) ) ;
if ( ! V_18 -> V_25 ) {
V_137 = - V_139 ;
goto V_161;
}
V_18 -> V_102 = F_68 ( V_125 , 0 ) ;
if ( V_18 -> V_102 < 0 ) {
V_137 = - V_139 ;
goto V_162;
}
V_137 = F_69 ( V_18 -> V_102 , F_43 , 0 , V_146 , V_18 ) ;
if ( V_137 ) {
F_57 ( & V_125 -> V_123 , L_10 , V_18 -> V_102 , V_137 ) ;
goto V_162;
}
V_18 -> V_163 = F_70 ( & V_125 -> V_123 , NULL ) ;
if ( F_71 ( V_18 -> V_163 ) ) {
F_57 ( & V_125 -> V_123 , L_11 ) ;
V_137 = F_72 ( V_18 -> V_163 ) ;
goto V_164;
}
F_73 ( V_18 -> V_163 ) ;
V_18 -> V_36 = F_74 ( V_18 -> V_163 ) ;
V_18 -> V_3 -> V_165 ( V_18 ) ;
V_18 -> V_3 -> V_107 ( V_18 , 0 ) ;
V_92 -> V_123 . V_128 = V_125 -> V_123 . V_128 ;
V_137 = F_75 ( & V_18 -> V_144 ) ;
if ( V_137 ) {
F_57 ( & V_125 -> V_123 , L_12 , V_137 ) ;
goto V_166;
}
F_76 ( & V_125 -> V_123 , L_13 ) ;
return V_137 ;
V_166:
F_77 ( V_18 -> V_163 ) ;
F_78 ( V_18 -> V_163 ) ;
V_164:
F_79 ( V_18 -> V_102 , V_18 ) ;
V_162:
F_80 ( V_18 -> V_25 ) ;
V_161:
F_81 ( V_136 -> V_158 , F_66 ( V_136 ) ) ;
V_147:
while ( -- V_11 >= 0 ) {
if ( V_18 -> V_56 [ V_11 ] >= 0 )
F_82 ( V_18 -> V_56 [ V_11 ] ) ;
}
F_83 ( V_92 ) ;
F_84 ( V_92 ) ;
F_60 ( V_125 , NULL ) ;
return V_137 ;
}
static int T_5 F_85 ( struct V_124 * V_125 )
{
struct V_134 * V_92 = F_86 ( V_125 ) ;
struct V_135 * V_136 = F_64 ( V_125 , V_157 , 0 ) ;
struct V_1 * V_18 = F_40 ( V_92 ) ;
int V_11 ;
F_87 ( & V_18 -> V_144 ) ;
F_13 ( 0 , V_18 -> V_25 + V_52 ) ;
F_77 ( V_18 -> V_163 ) ;
F_78 ( V_18 -> V_163 ) ;
F_79 ( V_18 -> V_102 , V_18 ) ;
F_80 ( V_18 -> V_25 ) ;
for ( V_11 = 0 ; V_11 < V_92 -> V_140 ; V_11 ++ )
if ( V_18 -> V_56 [ V_11 ] >= 0 )
F_82 ( V_18 -> V_56 [ V_11 ] ) ;
F_83 ( V_92 ) ;
F_81 ( V_136 -> V_158 , F_66 ( V_136 ) ) ;
F_60 ( V_125 , NULL ) ;
return 0 ;
}
