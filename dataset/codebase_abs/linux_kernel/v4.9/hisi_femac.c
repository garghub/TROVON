static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
F_3 ( V_4 | V_3 , V_2 -> V_5 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
F_3 ( V_4 & ( ~ V_3 ) , V_2 -> V_5 + V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 , unsigned int V_9 )
{
T_2 V_10 ;
V_10 = V_2 -> V_11 . V_12 [ V_9 ] ;
F_6 ( V_2 -> V_13 , V_10 , V_8 -> V_14 , V_15 ) ;
}
static void F_7 ( struct V_16 * V_13 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_17 * V_11 = & V_2 -> V_11 ;
unsigned int V_18 = 0 , V_19 = 0 ;
T_1 V_4 ;
F_9 ( V_13 ) ;
V_4 = F_2 ( V_2 -> V_20 + V_21 ) & V_22 ;
while ( V_4 < V_2 -> V_23 ) {
V_8 = V_11 -> V_8 [ V_11 -> V_24 ] ;
if ( F_10 ( ! V_8 ) ) {
F_11 ( V_13 , L_1 ,
V_4 , V_2 -> V_23 ) ;
break;
}
F_5 ( V_2 , V_8 , V_11 -> V_24 ) ;
V_19 ++ ;
V_18 += V_8 -> V_14 ;
F_12 ( V_8 ) ;
V_2 -> V_23 -- ;
V_4 = F_2 ( V_2 -> V_20 + V_21 ) & V_22 ;
V_11 -> V_8 [ V_11 -> V_24 ] = NULL ;
V_11 -> V_24 = ( V_11 -> V_24 + 1 ) % V_11 -> V_25 ;
}
F_13 ( V_13 , V_19 , V_18 ) ;
if ( F_10 ( F_14 ( V_13 ) ) && V_19 )
F_15 ( V_13 ) ;
F_16 ( V_13 ) ;
}
static void F_17 ( struct V_16 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_26 * V_27 = V_13 -> V_28 ;
T_1 V_29 = 0 ;
if ( V_27 -> V_30 )
V_29 |= V_31 ;
if ( V_27 -> V_32 == V_33 )
V_29 |= V_34 ;
if ( V_27 -> V_35 == V_36 )
V_29 |= V_37 ;
if ( ( V_29 != V_2 -> V_38 ) &&
( ( V_29 | V_2 -> V_38 ) & V_31 ) ) {
F_3 ( V_29 , V_2 -> V_20 + V_39 ) ;
V_2 -> V_38 = V_29 ;
F_18 ( V_27 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_17 * V_40 = & V_2 -> V_40 ;
struct V_7 * V_8 ;
T_1 V_9 ;
T_1 V_14 = V_41 ;
T_2 V_42 ;
V_9 = V_40 -> V_43 ;
while ( F_2 ( V_2 -> V_20 + V_21 ) & V_44 ) {
if ( ! F_20 ( V_9 , V_40 -> V_24 , V_40 -> V_25 ) )
break;
if ( F_10 ( V_40 -> V_8 [ V_9 ] ) ) {
F_11 ( V_2 -> V_45 , L_2 ,
V_9 , V_40 -> V_8 [ V_9 ] ) ;
break;
}
V_8 = F_21 ( V_2 -> V_45 , V_14 ) ;
if ( F_10 ( ! V_8 ) )
break;
V_42 = F_22 ( V_2 -> V_13 , V_8 -> V_46 , V_14 ,
V_47 ) ;
if ( F_23 ( V_2 -> V_13 , V_42 ) ) {
F_12 ( V_8 ) ;
break;
}
V_40 -> V_12 [ V_9 ] = V_42 ;
V_40 -> V_8 [ V_9 ] = V_8 ;
F_3 ( V_42 , V_2 -> V_20 + V_48 ) ;
V_9 = ( V_9 + 1 ) % V_40 -> V_25 ;
}
V_40 -> V_43 = V_9 ;
}
static int F_24 ( struct V_16 * V_13 , int V_49 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_17 * V_40 = & V_2 -> V_40 ;
struct V_7 * V_8 ;
T_2 V_42 ;
T_1 V_50 , V_9 , V_14 , V_51 = 0 ;
V_9 = V_40 -> V_24 ;
while ( F_2 ( V_2 -> V_5 + V_52 ) & V_53 ) {
V_50 = F_2 ( V_2 -> V_20 + V_54 ) ;
V_14 = V_50 & V_55 ;
V_14 -= V_56 ;
F_3 ( V_53 , V_2 -> V_5 + V_52 ) ;
V_51 ++ ;
V_8 = V_40 -> V_8 [ V_9 ] ;
if ( F_10 ( ! V_8 ) ) {
F_11 ( V_13 , L_3 , V_9 ) ;
break;
}
V_40 -> V_8 [ V_9 ] = NULL ;
V_42 = V_40 -> V_12 [ V_9 ] ;
F_6 ( V_2 -> V_13 , V_42 , V_41 ,
V_47 ) ;
F_25 ( V_8 , V_14 ) ;
if ( F_10 ( V_8 -> V_14 > V_41 ) ) {
F_11 ( V_13 , L_4 , V_8 -> V_14 ) ;
V_13 -> V_57 . V_58 ++ ;
V_13 -> V_57 . V_59 ++ ;
F_12 ( V_8 ) ;
goto V_60;
}
V_8 -> V_61 = F_26 ( V_8 , V_13 ) ;
F_27 ( & V_2 -> V_62 , V_8 ) ;
V_13 -> V_57 . V_63 ++ ;
V_13 -> V_57 . V_64 += V_8 -> V_14 ;
V_60:
V_9 = ( V_9 + 1 ) % V_40 -> V_25 ;
if ( V_51 >= V_49 )
break;
}
V_40 -> V_24 = V_9 ;
F_19 ( V_2 ) ;
return V_51 ;
}
static int F_28 ( struct V_65 * V_62 , int V_66 )
{
struct V_1 * V_2 = F_29 ( V_62 ,
struct V_1 , V_62 ) ;
struct V_16 * V_13 = V_2 -> V_45 ;
int V_67 = 0 , V_68 = V_66 ;
int V_69 , V_25 ;
do {
F_7 ( V_13 ) ;
V_25 = F_24 ( V_13 , V_68 ) ;
V_67 += V_25 ;
V_68 -= V_25 ;
if ( V_67 >= V_66 )
break;
V_69 = F_2 ( V_2 -> V_5 + V_52 ) ;
F_3 ( V_69 & V_70 ,
V_2 -> V_5 + V_52 ) ;
} while ( V_69 & V_70 );
if ( V_67 < V_66 ) {
F_30 ( V_62 ) ;
F_1 ( V_2 , V_70 &
( ~ V_71 ) ) ;
}
return V_67 ;
}
static T_3 F_31 ( int V_72 , void * V_73 )
{
int V_69 ;
struct V_16 * V_13 = (struct V_16 * ) V_73 ;
struct V_1 * V_2 = F_8 ( V_13 ) ;
V_69 = F_2 ( V_2 -> V_5 + V_52 ) ;
if ( F_32 ( V_69 & V_70 ) ) {
F_3 ( V_69 & V_70 ,
V_2 -> V_5 + V_52 ) ;
F_4 ( V_2 , V_70 ) ;
F_33 ( & V_2 -> V_62 ) ;
}
return V_74 ;
}
static int F_34 ( struct V_75 * V_13 ,
struct V_17 * V_76 ,
unsigned int V_25 )
{
V_76 -> V_8 = F_35 ( V_13 , V_25 , sizeof( struct V_7 * ) ,
V_77 ) ;
if ( ! V_76 -> V_8 )
return - V_78 ;
V_76 -> V_12 = F_35 ( V_13 , V_25 , sizeof( T_2 ) ,
V_77 ) ;
if ( ! V_76 -> V_12 )
return - V_78 ;
V_76 -> V_25 = V_25 ;
V_76 -> V_43 = 0 ;
V_76 -> V_24 = 0 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_79 ;
V_79 = F_34 ( V_2 -> V_13 , & V_2 -> V_11 , V_80 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_34 ( V_2 -> V_13 , & V_2 -> V_40 , V_81 ) ;
if ( V_79 )
return V_79 ;
V_2 -> V_23 = 0 ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_17 * V_11 = & V_2 -> V_11 ;
struct V_17 * V_40 = & V_2 -> V_40 ;
struct V_7 * V_8 ;
T_2 V_10 ;
T_1 V_9 ;
V_9 = V_40 -> V_24 ;
while ( V_9 != V_40 -> V_43 ) {
V_8 = V_40 -> V_8 [ V_9 ] ;
if ( F_10 ( ! V_8 ) ) {
F_11 ( V_2 -> V_45 , L_5 ,
V_9 , V_40 -> V_43 ) ;
continue;
}
V_10 = V_40 -> V_12 [ V_9 ] ;
F_6 ( V_2 -> V_13 , V_10 , V_41 ,
V_47 ) ;
F_12 ( V_8 ) ;
V_40 -> V_8 [ V_9 ] = NULL ;
V_9 = ( V_9 + 1 ) % V_40 -> V_25 ;
}
V_40 -> V_24 = V_9 ;
V_9 = V_11 -> V_24 ;
while ( V_9 != V_11 -> V_43 ) {
V_8 = V_11 -> V_8 [ V_9 ] ;
if ( F_10 ( ! V_8 ) ) {
F_11 ( V_2 -> V_45 , L_6 ,
V_9 , V_11 -> V_43 ) ;
continue;
}
F_5 ( V_2 , V_8 , V_9 ) ;
F_12 ( V_8 ) ;
V_11 -> V_8 [ V_9 ] = NULL ;
V_9 = ( V_9 + 1 ) % V_11 -> V_25 ;
}
V_11 -> V_24 = V_9 ;
V_2 -> V_23 = 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned char * V_82 )
{
T_1 V_83 ;
V_83 = V_82 [ 1 ] | ( V_82 [ 0 ] << 8 ) ;
F_3 ( V_83 , V_2 -> V_5 + V_84 ) ;
V_83 = V_82 [ 5 ] | ( V_82 [ 4 ] << 8 ) | ( V_82 [ 3 ] << 16 ) | ( V_82 [ 2 ] << 24 ) ;
F_3 ( V_83 , V_2 -> V_5 + V_85 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_86 ) ;
V_4 |= V_87 ;
F_3 ( V_4 , V_2 -> V_5 + V_86 ) ;
F_40 ( 500 , 800 ) ;
V_4 &= ~ V_87 ;
F_3 ( V_4 , V_2 -> V_5 + V_86 ) ;
return 0 ;
}
static int F_41 ( struct V_16 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
F_39 ( V_2 ) ;
F_38 ( V_2 , V_13 -> V_88 ) ;
F_19 ( V_2 ) ;
F_42 ( V_13 ) ;
F_43 ( V_13 ) ;
F_44 ( V_13 ) ;
F_45 ( & V_2 -> V_62 ) ;
V_2 -> V_38 = 0 ;
if ( V_13 -> V_28 )
F_46 ( V_13 -> V_28 ) ;
F_3 ( V_89 , V_2 -> V_5 + V_52 ) ;
F_1 ( V_2 , V_90 | V_91 | V_70 ) ;
return 0 ;
}
static int F_47 ( struct V_16 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
F_4 ( V_2 , V_91 ) ;
if ( V_13 -> V_28 )
F_48 ( V_13 -> V_28 ) ;
F_49 ( V_13 ) ;
F_50 ( & V_2 -> V_62 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static T_4 F_51 ( struct V_7 * V_8 ,
struct V_16 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_17 * V_11 = & V_2 -> V_11 ;
T_2 V_42 ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_20 + V_21 ) ;
V_4 &= V_92 ;
if ( ! V_4 ) {
F_1 ( V_2 , V_71 ) ;
V_13 -> V_57 . V_93 ++ ;
V_13 -> V_57 . V_94 ++ ;
F_49 ( V_13 ) ;
return V_95 ;
}
if ( F_10 ( ! F_20 ( V_11 -> V_43 , V_11 -> V_24 ,
V_11 -> V_25 ) ) ) {
F_1 ( V_2 , V_71 ) ;
V_13 -> V_57 . V_93 ++ ;
V_13 -> V_57 . V_94 ++ ;
F_49 ( V_13 ) ;
return V_95 ;
}
V_42 = F_22 ( V_2 -> V_13 , V_8 -> V_46 ,
V_8 -> V_14 , V_15 ) ;
if ( F_10 ( F_23 ( V_2 -> V_13 , V_42 ) ) ) {
F_12 ( V_8 ) ;
V_13 -> V_57 . V_93 ++ ;
return V_96 ;
}
V_11 -> V_12 [ V_11 -> V_43 ] = V_42 ;
V_11 -> V_8 [ V_11 -> V_43 ] = V_8 ;
V_11 -> V_43 = ( V_11 -> V_43 + 1 ) % V_11 -> V_25 ;
F_3 ( V_42 , V_2 -> V_20 + V_97 ) ;
F_3 ( V_8 -> V_14 + V_56 , V_2 -> V_20 + V_98 ) ;
V_2 -> V_23 ++ ;
V_13 -> V_57 . V_99 ++ ;
V_13 -> V_57 . V_100 += V_8 -> V_14 ;
F_52 ( V_13 , V_8 -> V_14 ) ;
return V_96 ;
}
static int F_53 ( struct V_16 * V_13 , void * V_101 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_102 * V_103 = V_101 ;
if ( ! F_54 ( V_103 -> V_104 ) )
return - V_105 ;
memcpy ( V_13 -> V_88 , V_103 -> V_104 , V_13 -> V_106 ) ;
V_13 -> V_107 &= ~ V_108 ;
F_38 ( V_2 , V_13 -> V_88 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 ,
unsigned int V_109 , bool V_110 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + F_56 ( V_109 ) ) ;
if ( V_110 )
V_4 |= V_111 ;
else
V_4 &= ~ V_111 ;
F_3 ( V_4 , V_2 -> V_5 + F_56 ( V_109 ) ) ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned char * V_42 ,
unsigned int V_109 )
{
unsigned int V_112 , V_113 ;
T_1 V_4 ;
V_112 = F_56 ( V_109 ) ;
V_113 = F_58 ( V_109 ) ;
V_4 = ( V_42 [ 2 ] << 24 ) | ( V_42 [ 3 ] << 16 ) | ( V_42 [ 4 ] << 8 ) | V_42 [ 5 ] ;
F_3 ( V_4 , V_2 -> V_5 + V_113 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_112 ) ;
V_4 &= ~ V_114 ;
V_4 |= ( ( V_42 [ 0 ] << 8 ) | V_42 [ 1 ] ) ;
V_4 |= ( V_111 | V_115 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_112 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
bool V_116 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_117 ) ;
if ( V_116 )
V_4 |= V_118 ;
else
V_4 &= ~ V_118 ;
F_3 ( V_4 , V_2 -> V_5 + V_117 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_16 * V_13 = V_2 -> V_45 ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_119 ) ;
if ( ( F_61 ( V_13 ) > V_120 ) ||
( V_13 -> V_121 & V_122 ) ) {
V_4 |= V_123 ;
} else {
int V_83 = V_124 ;
int V_125 ;
struct V_126 * V_127 ;
for ( V_125 = V_83 ; V_125 < V_128 ; V_125 ++ )
F_55 ( V_2 , V_125 , false ) ;
F_62 (ha, dev) {
F_57 ( V_2 , V_127 -> V_42 , V_83 ) ;
V_83 ++ ;
}
V_4 &= ~ V_123 ;
}
F_3 ( V_4 , V_2 -> V_5 + V_119 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_16 * V_13 = V_2 -> V_45 ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_119 ) ;
if ( F_64 ( V_13 ) > V_124 ) {
V_4 |= V_129 ;
} else {
int V_83 = 0 ;
int V_125 ;
struct V_126 * V_127 ;
for ( V_125 = V_83 ; V_125 < V_124 ; V_125 ++ )
F_55 ( V_2 , V_125 , false ) ;
F_65 (ha, dev) {
F_57 ( V_2 , V_127 -> V_42 , V_83 ) ;
V_83 ++ ;
}
V_4 &= ~ V_129 ;
}
F_3 ( V_4 , V_2 -> V_5 + V_119 ) ;
}
static void F_66 ( struct V_16 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
if ( V_13 -> V_121 & V_130 ) {
F_59 ( V_2 , true ) ;
} else {
F_59 ( V_2 , false ) ;
F_60 ( V_2 ) ;
F_63 ( V_2 ) ;
}
}
static int F_67 ( struct V_16 * V_13 ,
struct V_131 * V_131 , int V_132 )
{
if ( ! F_68 ( V_13 ) )
return - V_133 ;
if ( ! V_13 -> V_28 )
return - V_133 ;
return F_69 ( V_13 -> V_28 , V_131 , V_132 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_71 ( V_2 -> V_134 ) ;
F_72 ( V_2 -> V_134 ) ;
}
static void F_73 ( T_1 V_135 )
{
T_1 V_136 ;
if ( ! V_135 )
return;
V_136 = F_74 ( V_135 , 1000 ) ;
if ( V_136 < 20 )
F_40 ( V_135 , V_135 + 500 ) ;
else
F_75 ( V_136 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_72 ( V_2 -> V_137 ) ;
F_73 ( V_2 -> V_138 [ V_139 ] ) ;
F_71 ( V_2 -> V_137 ) ;
F_73 ( V_2 -> V_138 [ V_140 ] ) ;
F_72 ( V_2 -> V_137 ) ;
F_73 ( V_2 -> V_138 [ V_141 ] ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = V_142 ;
if ( V_2 -> V_45 -> V_28 -> V_143 == V_144 )
V_4 |= V_145 ;
F_3 ( V_4 , V_2 -> V_20 + V_146 ) ;
F_3 ( V_89 , V_2 -> V_5 + V_52 ) ;
F_4 ( V_2 , V_89 | V_91 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_117 ) ;
V_4 &= ~ ( V_147 | V_118 ) ;
V_4 |= V_148 ;
F_3 ( V_4 , V_2 -> V_5 + V_117 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_119 ) ;
V_4 |= ( V_149 | V_150 ) ;
F_3 ( V_4 , V_2 -> V_5 + V_119 ) ;
V_4 = F_2 ( V_2 -> V_20 + V_151 ) ;
V_4 &= ~ V_152 ;
V_4 |= V_41 ;
F_3 ( V_4 , V_2 -> V_20 + V_151 ) ;
V_4 = V_153 |
( V_154 << V_155 ) ;
F_3 ( V_4 , V_2 -> V_20 + V_156 ) ;
V_4 = ( V_157 << V_158 ) | V_159 ;
F_3 ( V_4 , V_2 -> V_20 + V_160 ) ;
}
static int F_78 ( struct V_161 * V_162 )
{
struct V_75 * V_13 = & V_162 -> V_13 ;
struct V_163 * V_164 = V_13 -> V_165 ;
struct V_166 * V_167 ;
struct V_16 * V_45 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
const char * V_168 ;
int V_79 ;
V_45 = F_79 ( sizeof( * V_2 ) ) ;
if ( ! V_45 )
return - V_78 ;
F_80 ( V_162 , V_45 ) ;
V_2 = F_8 ( V_45 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_45 = V_45 ;
V_167 = F_81 ( V_162 , V_169 , 0 ) ;
V_2 -> V_20 = F_82 ( V_13 , V_167 ) ;
if ( F_83 ( V_2 -> V_20 ) ) {
V_79 = F_84 ( V_2 -> V_20 ) ;
goto V_170;
}
V_167 = F_81 ( V_162 , V_169 , 1 ) ;
V_2 -> V_5 = F_82 ( V_13 , V_167 ) ;
if ( F_83 ( V_2 -> V_5 ) ) {
V_79 = F_84 ( V_2 -> V_5 ) ;
goto V_170;
}
V_2 -> V_171 = F_85 ( & V_162 -> V_13 , NULL ) ;
if ( F_83 ( V_2 -> V_171 ) ) {
F_86 ( V_13 , L_7 ) ;
V_79 = - V_172 ;
goto V_170;
}
V_79 = F_87 ( V_2 -> V_171 ) ;
if ( V_79 ) {
F_86 ( V_13 , L_8 , V_79 ) ;
goto V_170;
}
V_2 -> V_134 = F_88 ( V_13 , L_9 ) ;
if ( F_83 ( V_2 -> V_134 ) ) {
V_79 = F_84 ( V_2 -> V_134 ) ;
goto V_173;
}
F_70 ( V_2 ) ;
V_2 -> V_137 = F_88 ( V_13 , L_10 ) ;
if ( F_83 ( V_2 -> V_137 ) ) {
V_2 -> V_137 = NULL ;
} else {
V_79 = F_89 ( V_164 ,
V_174 ,
V_2 -> V_138 ,
V_175 ) ;
if ( V_79 )
goto V_173;
F_76 ( V_2 ) ;
}
V_27 = F_90 ( V_45 , V_164 , F_17 ) ;
if ( ! V_27 ) {
F_86 ( V_13 , L_11 ) ;
V_79 = - V_172 ;
goto V_173;
}
F_91 ( V_27 , L_12 ,
( unsigned long ) V_27 -> V_176 ,
F_92 ( V_27 -> V_143 ) ) ;
V_168 = F_93 ( V_164 ) ;
if ( V_168 )
F_94 ( V_45 -> V_88 , V_168 ) ;
if ( ! F_54 ( V_45 -> V_88 ) ) {
F_95 ( V_45 ) ;
F_96 ( V_13 , L_13 ,
V_45 -> V_88 ) ;
}
V_45 -> V_177 = 6 * V_178 ;
V_45 -> V_179 |= V_180 ;
V_45 -> V_181 = & V_182 ;
V_45 -> V_183 = & V_184 ;
F_97 ( V_45 , & V_2 -> V_62 , F_28 , V_185 ) ;
F_98 ( V_45 , & V_162 -> V_13 ) ;
F_77 ( V_2 ) ;
V_79 = F_36 ( V_2 ) ;
if ( V_79 )
goto V_186;
V_45 -> V_72 = F_99 ( V_162 , 0 ) ;
if ( V_45 -> V_72 <= 0 ) {
F_86 ( V_13 , L_14 ) ;
V_79 = - V_172 ;
goto V_186;
}
V_79 = F_100 ( V_13 , V_45 -> V_72 , F_31 ,
V_187 , V_162 -> V_188 , V_45 ) ;
if ( V_79 ) {
F_86 ( V_13 , L_15 , V_45 -> V_72 ) ;
goto V_186;
}
V_79 = F_101 ( V_45 ) ;
if ( V_79 ) {
F_86 ( V_13 , L_16 ) ;
goto V_186;
}
return V_79 ;
V_186:
F_102 ( & V_2 -> V_62 ) ;
F_103 ( V_27 ) ;
V_173:
F_104 ( V_2 -> V_171 ) ;
V_170:
F_105 ( V_45 ) ;
return V_79 ;
}
static int F_106 ( struct V_161 * V_162 )
{
struct V_16 * V_45 = F_107 ( V_162 ) ;
struct V_1 * V_2 = F_8 ( V_45 ) ;
F_102 ( & V_2 -> V_62 ) ;
F_108 ( V_45 ) ;
F_103 ( V_45 -> V_28 ) ;
F_104 ( V_2 -> V_171 ) ;
F_105 ( V_45 ) ;
return 0 ;
}
static int F_109 ( struct V_161 * V_162 ,
T_5 V_189 )
{
struct V_16 * V_45 = F_107 ( V_162 ) ;
struct V_1 * V_2 = F_8 ( V_45 ) ;
F_110 ( V_45 -> V_72 ) ;
if ( F_68 ( V_45 ) ) {
F_47 ( V_45 ) ;
F_111 ( V_45 ) ;
}
F_104 ( V_2 -> V_171 ) ;
return 0 ;
}
static int F_112 ( struct V_161 * V_162 )
{
struct V_16 * V_45 = F_107 ( V_162 ) ;
struct V_1 * V_2 = F_8 ( V_45 ) ;
F_87 ( V_2 -> V_171 ) ;
if ( V_2 -> V_137 )
F_76 ( V_2 ) ;
if ( F_68 ( V_45 ) ) {
F_77 ( V_2 ) ;
F_41 ( V_45 ) ;
F_113 ( V_45 ) ;
}
F_114 ( V_45 -> V_72 ) ;
return 0 ;
}
