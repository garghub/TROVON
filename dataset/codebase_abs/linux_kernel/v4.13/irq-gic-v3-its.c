static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
return V_6 -> V_7 + V_3 -> V_8 . V_9 [ V_4 ] ;
}
static void F_2 ( T_2 * V_10 , T_2 V_11 , int V_12 , int V_13 )
{
T_2 V_14 = F_3 ( V_12 , V_13 ) ;
* V_10 &= ~ V_14 ;
* V_10 |= ( V_11 << V_13 ) & V_14 ;
}
static void F_4 ( struct V_15 * V_16 , T_3 V_17 )
{
F_2 ( & V_16 -> V_10 [ 0 ] , V_17 , 7 , 0 ) ;
}
static void F_5 ( struct V_15 * V_16 , T_1 V_18 )
{
F_2 ( & V_16 -> V_10 [ 0 ] , V_18 , 63 , 32 ) ;
}
static void F_6 ( struct V_15 * V_16 , T_1 V_19 )
{
F_2 ( & V_16 -> V_10 [ 1 ] , V_19 , 31 , 0 ) ;
}
static void F_7 ( struct V_15 * V_16 , T_1 V_20 )
{
F_2 ( & V_16 -> V_10 [ 1 ] , V_20 , 63 , 32 ) ;
}
static void F_8 ( struct V_15 * V_16 , T_3 V_21 )
{
F_2 ( & V_16 -> V_10 [ 1 ] , V_21 , 4 , 0 ) ;
}
static void F_9 ( struct V_15 * V_16 , T_2 V_22 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , V_22 >> 8 , 50 , 8 ) ;
}
static void F_10 ( struct V_15 * V_16 , int V_23 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , ! ! V_23 , 63 , 63 ) ;
}
static void F_11 ( struct V_15 * V_16 , T_2 V_24 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , V_24 >> 16 , 50 , 16 ) ;
}
static void F_12 ( struct V_15 * V_16 , T_4 V_25 )
{
F_2 ( & V_16 -> V_10 [ 2 ] , V_25 , 15 , 0 ) ;
}
static inline void F_13 ( struct V_15 * V_16 )
{
V_16 -> V_10 [ 0 ] = F_14 ( V_16 -> V_10 [ 0 ] ) ;
V_16 -> V_10 [ 1 ] = F_14 ( V_16 -> V_10 [ 1 ] ) ;
V_16 -> V_10 [ 2 ] = F_14 ( V_16 -> V_10 [ 2 ] ) ;
V_16 -> V_10 [ 3 ] = F_14 ( V_16 -> V_10 [ 3 ] ) ;
}
static struct V_1 * F_15 ( struct V_15 * V_16 ,
struct V_26 * V_27 )
{
unsigned long V_22 ;
T_3 V_21 = F_16 ( V_27 -> V_28 . V_29 -> V_30 ) ;
V_22 = F_17 ( V_27 -> V_28 . V_29 -> V_31 ) ;
V_22 = F_18 ( V_22 , V_32 ) ;
F_4 ( V_16 , V_33 ) ;
F_5 ( V_16 , V_27 -> V_28 . V_29 -> V_34 ) ;
F_8 ( V_16 , V_21 - 1 ) ;
F_9 ( V_16 , V_22 ) ;
F_10 ( V_16 , V_27 -> V_28 . V_23 ) ;
F_13 ( V_16 ) ;
return NULL ;
}
static struct V_1 * F_19 ( struct V_15 * V_16 ,
struct V_26 * V_27 )
{
F_4 ( V_16 , V_35 ) ;
F_12 ( V_16 , V_27 -> V_36 . V_25 -> V_37 ) ;
F_11 ( V_16 , V_27 -> V_36 . V_25 -> V_38 ) ;
F_10 ( V_16 , V_27 -> V_36 . V_23 ) ;
F_13 ( V_16 ) ;
return V_27 -> V_36 . V_25 ;
}
static struct V_1 * F_20 ( struct V_15 * V_16 ,
struct V_26 * V_27 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_27 -> V_39 . V_29 ,
V_27 -> V_39 . V_40 ) ;
F_4 ( V_16 , V_41 ) ;
F_5 ( V_16 , V_27 -> V_39 . V_29 -> V_34 ) ;
F_6 ( V_16 , V_27 -> V_39 . V_40 ) ;
F_7 ( V_16 , V_27 -> V_39 . V_20 ) ;
F_12 ( V_16 , V_25 -> V_37 ) ;
F_13 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_21 ( struct V_15 * V_16 ,
struct V_26 * V_27 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_27 -> V_42 . V_29 ,
V_27 -> V_42 . V_40 ) ;
F_4 ( V_16 , V_43 ) ;
F_5 ( V_16 , V_27 -> V_42 . V_29 -> V_34 ) ;
F_6 ( V_16 , V_27 -> V_42 . V_40 ) ;
F_12 ( V_16 , V_27 -> V_42 . V_25 -> V_37 ) ;
F_13 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_22 ( struct V_15 * V_16 ,
struct V_26 * V_27 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_27 -> V_44 . V_29 ,
V_27 -> V_44 . V_40 ) ;
F_4 ( V_16 , V_45 ) ;
F_5 ( V_16 , V_27 -> V_44 . V_29 -> V_34 ) ;
F_6 ( V_16 , V_27 -> V_44 . V_40 ) ;
F_13 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_23 ( struct V_15 * V_16 ,
struct V_26 * V_27 )
{
struct V_1 * V_25 ;
V_25 = F_1 ( V_27 -> V_46 . V_29 ,
V_27 -> V_46 . V_40 ) ;
F_4 ( V_16 , V_47 ) ;
F_5 ( V_16 , V_27 -> V_46 . V_29 -> V_34 ) ;
F_6 ( V_16 , V_27 -> V_46 . V_40 ) ;
F_13 ( V_16 ) ;
return V_25 ;
}
static struct V_1 * F_24 ( struct V_15 * V_16 ,
struct V_26 * V_27 )
{
F_4 ( V_16 , V_48 ) ;
F_12 ( V_16 , V_27 -> V_36 . V_25 -> V_37 ) ;
F_13 ( V_16 ) ;
return NULL ;
}
static T_2 F_25 ( struct V_5 * V_6 ,
struct V_15 * V_49 )
{
return ( V_49 - V_6 -> V_50 ) * sizeof( * V_49 ) ;
}
static int F_26 ( struct V_5 * V_6 )
{
int V_51 ;
int V_52 ;
V_51 = V_6 -> V_53 - V_6 -> V_50 ;
V_52 = F_27 ( V_6 -> V_54 + V_55 ) / sizeof( struct V_15 ) ;
if ( ( ( V_51 + 1 ) % V_56 ) == V_52 )
return 1 ;
return 0 ;
}
static struct V_15 * F_28 ( struct V_5 * V_6 )
{
struct V_15 * V_16 ;
T_1 V_57 = 1000000 ;
while ( F_26 ( V_6 ) ) {
V_57 -- ;
if ( ! V_57 ) {
F_29 ( L_1 ) ;
return NULL ;
}
F_30 () ;
F_31 ( 1 ) ;
}
V_16 = V_6 -> V_53 ++ ;
if ( V_6 -> V_53 == ( V_6 -> V_50 + V_56 ) )
V_6 -> V_53 = V_6 -> V_50 ;
V_16 -> V_10 [ 0 ] = 0 ;
V_16 -> V_10 [ 1 ] = 0 ;
V_16 -> V_10 [ 2 ] = 0 ;
V_16 -> V_10 [ 3 ] = 0 ;
return V_16 ;
}
static struct V_15 * F_32 ( struct V_5 * V_6 )
{
T_2 V_58 = F_25 ( V_6 , V_6 -> V_53 ) ;
F_33 ( V_58 , V_6 -> V_54 + V_59 ) ;
return V_6 -> V_53 ;
}
static void F_34 ( struct V_5 * V_6 , struct V_15 * V_16 )
{
if ( V_6 -> V_60 & V_61 )
F_35 ( V_16 , sizeof( * V_16 ) ) ;
else
F_36 ( V_62 ) ;
}
static void F_37 ( struct V_5 * V_6 ,
struct V_15 * V_63 ,
struct V_15 * V_64 )
{
T_2 V_65 , V_66 , V_67 ;
T_1 V_57 = 1000000 ;
V_66 = F_25 ( V_6 , V_63 ) ;
V_67 = F_25 ( V_6 , V_64 ) ;
while ( 1 ) {
V_65 = F_27 ( V_6 -> V_54 + V_55 ) ;
if ( V_65 >= V_67 || V_65 < V_66 )
break;
V_57 -- ;
if ( ! V_57 ) {
F_29 ( L_2 ) ;
return;
}
F_30 () ;
F_31 ( 1 ) ;
}
}
static void F_38 ( struct V_5 * V_6 ,
T_5 V_68 ,
struct V_26 * V_27 )
{
struct V_15 * V_16 , * V_69 , * V_70 ;
struct V_1 * V_71 ;
unsigned long V_60 ;
F_39 ( & V_6 -> V_72 , V_60 ) ;
V_16 = F_28 ( V_6 ) ;
if ( ! V_16 ) {
F_29 ( L_3 ) ;
F_40 ( & V_6 -> V_72 , V_60 ) ;
return;
}
V_71 = V_68 ( V_16 , V_27 ) ;
F_34 ( V_6 , V_16 ) ;
if ( V_71 ) {
V_69 = F_28 ( V_6 ) ;
if ( ! V_69 ) {
F_29 ( L_4 ) ;
goto V_73;
}
F_4 ( V_69 , V_74 ) ;
F_11 ( V_69 , V_71 -> V_38 ) ;
F_13 ( V_69 ) ;
F_34 ( V_6 , V_69 ) ;
}
V_73:
V_70 = F_32 ( V_6 ) ;
F_40 ( & V_6 -> V_72 , V_60 ) ;
F_37 ( V_6 , V_16 , V_70 ) ;
}
static void F_41 ( struct V_2 * V_29 , T_1 V_40 )
{
struct V_26 V_27 ;
V_27 . V_46 . V_29 = V_29 ;
V_27 . V_46 . V_40 = V_40 ;
F_38 ( V_29 -> V_6 , F_23 , & V_27 ) ;
}
static void F_42 ( struct V_2 * V_29 , int V_23 )
{
struct V_26 V_27 ;
V_27 . V_28 . V_29 = V_29 ;
V_27 . V_28 . V_23 = ! ! V_23 ;
F_38 ( V_29 -> V_6 , F_15 , & V_27 ) ;
}
static void F_43 ( struct V_5 * V_6 , struct V_1 * V_25 ,
int V_23 )
{
struct V_26 V_27 ;
V_27 . V_36 . V_25 = V_25 ;
V_27 . V_36 . V_23 = ! ! V_23 ;
F_38 ( V_6 , F_19 , & V_27 ) ;
}
static void F_44 ( struct V_2 * V_29 , T_1 V_75 , T_1 V_19 )
{
struct V_26 V_27 ;
V_27 . V_39 . V_29 = V_29 ;
V_27 . V_39 . V_20 = V_75 ;
V_27 . V_39 . V_40 = V_19 ;
F_38 ( V_29 -> V_6 , F_20 , & V_27 ) ;
}
static void F_45 ( struct V_2 * V_29 ,
struct V_1 * V_25 , T_1 V_19 )
{
struct V_26 V_27 ;
V_27 . V_42 . V_29 = V_29 ;
V_27 . V_42 . V_25 = V_25 ;
V_27 . V_42 . V_40 = V_19 ;
F_38 ( V_29 -> V_6 , F_21 , & V_27 ) ;
}
static void F_46 ( struct V_2 * V_29 , T_1 V_19 )
{
struct V_26 V_27 ;
V_27 . V_44 . V_29 = V_29 ;
V_27 . V_44 . V_40 = V_19 ;
F_38 ( V_29 -> V_6 , F_22 , & V_27 ) ;
}
static void F_47 ( struct V_5 * V_6 , struct V_1 * V_25 )
{
struct V_26 V_27 ;
V_27 . V_76 . V_25 = V_25 ;
F_38 ( V_6 , F_24 , & V_27 ) ;
}
static inline T_1 F_48 ( struct V_77 * V_78 )
{
struct V_2 * V_3 = F_49 ( V_78 ) ;
return V_78 -> V_79 - V_3 -> V_8 . V_80 ;
}
static void F_50 ( struct V_77 * V_78 , bool V_81 )
{
struct V_2 * V_3 = F_49 ( V_78 ) ;
T_6 V_79 = V_78 -> V_79 ;
T_1 V_19 = F_48 ( V_78 ) ;
T_3 * V_82 = F_51 ( V_83 -> V_84 ) + V_79 - 8192 ;
if ( V_81 )
* V_82 |= V_85 ;
else
* V_82 &= ~ V_85 ;
if ( V_83 -> V_60 & V_86 )
F_35 ( V_82 , sizeof( * V_82 ) ) ;
else
F_36 ( V_62 ) ;
F_41 ( V_3 , V_19 ) ;
}
static void F_52 ( struct V_77 * V_78 )
{
F_50 ( V_78 , false ) ;
}
static void F_53 ( struct V_77 * V_78 )
{
F_50 ( V_78 , true ) ;
}
static int F_54 ( struct V_77 * V_78 , const struct V_87 * V_88 ,
bool V_89 )
{
unsigned int V_90 ;
const struct V_87 * V_91 = V_92 ;
struct V_2 * V_3 = F_49 ( V_78 ) ;
struct V_1 * V_93 ;
T_1 V_19 = F_48 ( V_78 ) ;
if ( V_3 -> V_6 -> V_60 & V_94 ) {
if ( V_3 -> V_6 -> V_95 >= 0 ) {
V_91 = F_55 ( V_3 -> V_6 -> V_95 ) ;
if ( ! F_56 ( V_88 , V_91 ) )
return - V_96 ;
}
}
V_90 = F_57 ( V_88 , V_91 ) ;
if ( V_90 >= V_97 )
return - V_96 ;
if ( V_90 != V_3 -> V_8 . V_9 [ V_19 ] ) {
V_93 = & V_3 -> V_6 -> V_7 [ V_90 ] ;
F_45 ( V_3 , V_93 , V_19 ) ;
V_3 -> V_8 . V_9 [ V_19 ] = V_90 ;
}
return V_98 ;
}
static void F_58 ( struct V_77 * V_78 , struct V_99 * V_100 )
{
struct V_2 * V_3 = F_49 ( V_78 ) ;
struct V_5 * V_6 ;
T_2 V_101 ;
V_6 = V_3 -> V_6 ;
V_101 = V_6 -> V_102 + V_103 ;
V_100 -> V_104 = F_59 ( V_101 ) ;
V_100 -> V_105 = F_60 ( V_101 ) ;
V_100 -> V_106 = F_48 ( V_78 ) ;
F_61 ( V_78 -> V_107 , V_100 ) ;
}
static int F_62 ( int V_108 )
{
return ( V_108 - 8192 ) >> V_109 ;
}
static int F_63 ( int V_110 )
{
return ( V_110 << V_109 ) + 8192 ;
}
static int T_7 F_64 ( T_1 V_111 )
{
V_112 = F_62 ( 1UL << V_111 ) ;
V_113 = F_65 ( F_66 ( V_112 ) * sizeof( long ) ,
V_114 ) ;
if ( ! V_113 ) {
V_112 = 0 ;
return - V_115 ;
}
F_67 ( L_5 , ( int ) V_112 ) ;
return 0 ;
}
static unsigned long * F_68 ( int V_116 , int * V_54 , int * V_117 )
{
unsigned long * V_118 = NULL ;
int V_119 ;
int V_120 ;
int V_121 ;
V_120 = F_69 ( V_116 , V_122 ) ;
F_70 ( & V_123 ) ;
do {
V_119 = F_71 ( V_113 , V_112 ,
0 , V_120 , 0 ) ;
if ( V_119 < V_112 )
break;
V_120 -- ;
} while ( V_120 > 0 );
if ( ! V_120 )
goto V_124;
V_118 = F_65 ( F_66 ( V_120 * V_122 ) * sizeof ( long ) ,
V_125 ) ;
if ( ! V_118 )
goto V_124;
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ )
F_72 ( V_119 + V_121 , V_113 ) ;
* V_54 = F_63 ( V_119 ) ;
* V_117 = V_120 * V_122 ;
V_124:
F_73 ( & V_123 ) ;
if ( ! V_118 )
* V_54 = * V_117 = 0 ;
return V_118 ;
}
static void F_74 ( struct V_126 * V_127 )
{
int V_54 = V_127 -> V_80 ;
int V_117 = V_127 -> V_128 ;
int V_108 ;
F_70 ( & V_123 ) ;
for ( V_108 = V_54 ; V_108 < ( V_54 + V_117 ) ; V_108 += V_122 ) {
int V_110 = F_62 ( V_108 ) ;
F_75 ( V_110 > V_112 ) ;
if ( F_76 ( V_110 , V_113 ) ) {
F_77 ( V_110 , V_113 ) ;
} else {
F_78 ( L_6 , V_110 ) ;
}
}
F_73 ( & V_123 ) ;
F_79 ( V_127 -> V_129 ) ;
F_79 ( V_127 -> V_9 ) ;
}
static int T_7 F_80 ( void )
{
T_8 V_130 ;
V_131 = F_81 ( T_1 , V_83 -> V_111 , V_132 ) ;
V_83 -> V_84 = F_82 ( V_133 ,
F_83 ( V_134 ) ) ;
if ( ! V_83 -> V_84 ) {
F_78 ( L_7 ) ;
return - V_115 ;
}
V_130 = F_84 ( V_83 -> V_84 ) ;
F_67 ( L_8 , & V_130 ) ;
memset ( F_51 ( V_83 -> V_84 ) ,
V_135 | V_136 ,
V_134 ) ;
F_35 ( F_51 ( V_83 -> V_84 ) , V_134 ) ;
return F_64 ( V_131 ) ;
}
static T_2 F_85 ( struct V_5 * V_6 , struct V_137 * V_138 )
{
T_1 V_139 = V_138 - V_6 -> V_140 ;
return F_86 ( V_6 -> V_54 + V_141 + ( V_139 << 3 ) ) ;
}
static void F_87 ( struct V_5 * V_6 , struct V_137 * V_138 ,
T_2 V_11 )
{
T_1 V_139 = V_138 - V_6 -> V_140 ;
F_88 ( V_11 , V_6 -> V_54 + V_141 + ( V_139 << 3 ) ) ;
V_138 -> V_11 = F_85 ( V_6 , V_138 ) ;
}
static int F_89 ( struct V_5 * V_6 , struct V_137 * V_138 ,
T_2 V_142 , T_2 V_143 , T_1 V_144 , T_1 V_145 ,
bool V_146 )
{
T_2 V_11 = F_85 ( V_6 , V_138 ) ;
T_2 V_147 = F_90 ( V_11 ) ;
T_2 type = F_91 ( V_11 ) ;
T_1 F_82 ;
void * V_54 ;
T_2 V_148 ;
V_149:
F_82 = ( F_92 ( V_145 ) / V_144 ) ;
if ( F_82 > V_150 ) {
F_93 ( L_9 ,
& V_6 -> V_102 , V_151 [ type ] ,
F_82 , V_150 ) ;
F_82 = V_150 ;
V_145 = F_83 ( V_150 * V_144 ) ;
}
V_54 = ( void * ) F_94 ( V_114 | V_152 , V_145 ) ;
if ( ! V_54 )
return - V_115 ;
V_153:
V_11 = ( F_17 ( V_54 ) |
( type << V_154 ) |
( ( V_147 - 1 ) << V_155 ) |
( ( F_82 - 1 ) << V_156 ) |
V_142 |
V_143 |
V_157 ) ;
V_11 |= V_146 ? V_158 : 0x0 ;
switch ( V_144 ) {
case V_159 :
V_11 |= V_160 ;
break;
case V_161 :
V_11 |= V_162 ;
break;
case V_163 :
V_11 |= V_164 ;
break;
}
F_87 ( V_6 , V_138 , V_11 ) ;
V_148 = V_138 -> V_11 ;
if ( ( V_11 ^ V_148 ) & V_165 ) {
V_143 = V_148 & V_165 ;
if ( ! V_143 ) {
V_142 = V_166 ;
F_35 ( V_54 , F_92 ( V_145 ) ) ;
}
goto V_153;
}
if ( ( V_11 ^ V_148 ) & V_167 ) {
F_95 ( ( unsigned long ) V_54 , V_145 ) ;
V_138 -> V_54 = NULL ;
switch ( V_144 ) {
case V_161 :
V_144 = V_159 ;
goto V_149;
case V_163 :
V_144 = V_161 ;
goto V_149;
}
}
if ( V_11 != V_148 ) {
F_78 ( L_10 ,
& V_6 -> V_102 , V_151 [ type ] ,
V_11 , V_148 ) ;
F_95 ( ( unsigned long ) V_54 , V_145 ) ;
return - V_168 ;
}
V_138 -> V_145 = V_145 ;
V_138 -> V_54 = V_54 ;
V_138 -> V_144 = V_144 ;
V_148 = V_146 ? V_169 : V_147 ;
F_67 ( L_11 ,
& V_6 -> V_102 , ( int ) ( F_92 ( V_145 ) / ( int ) V_148 ) ,
V_151 [ type ] ,
( unsigned long ) F_17 ( V_54 ) ,
V_146 ? L_12 : L_13 , ( int ) V_147 ,
V_144 / V_170 , ( int ) V_143 >> V_171 ) ;
return 0 ;
}
static bool F_96 ( struct V_5 * V_6 , struct V_137 * V_138 ,
T_1 V_144 , T_1 * V_145 )
{
T_2 V_147 = F_90 ( F_85 ( V_6 , V_138 ) ) ;
T_2 V_11 = V_172 | V_173 ;
T_1 V_174 = V_6 -> V_175 ;
T_1 V_176 = * V_145 ;
bool V_146 = false ;
if ( ( V_147 << V_174 ) > ( V_144 * 2 ) ) {
F_87 ( V_6 , V_138 , V_11 | V_158 ) ;
V_146 = ! ! ( V_138 -> V_11 & V_158 ) ;
if ( V_146 ) {
V_174 -= F_16 ( V_144 / ( int ) V_147 ) ;
V_147 = V_169 ;
}
}
V_176 = F_97 ( T_1 , F_83 ( V_147 << V_174 ) , V_176 ) ;
if ( V_176 >= V_177 ) {
V_176 = V_177 - 1 ;
V_174 = F_16 ( F_92 ( V_176 ) / ( int ) V_147 ) ;
F_93 ( L_14 ,
& V_6 -> V_102 , V_6 -> V_175 , V_174 ) ;
}
* V_145 = V_176 ;
return V_146 ;
}
static void F_98 ( struct V_5 * V_6 )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_178 ; V_121 ++ ) {
if ( V_6 -> V_140 [ V_121 ] . V_54 ) {
F_95 ( ( unsigned long ) V_6 -> V_140 [ V_121 ] . V_54 ,
V_6 -> V_140 [ V_121 ] . V_145 ) ;
V_6 -> V_140 [ V_121 ] . V_54 = NULL ;
}
}
}
static int F_99 ( struct V_5 * V_6 )
{
T_2 V_179 = F_100 ( V_6 -> V_54 + V_180 ) ;
T_1 V_174 = F_101 ( V_179 ) ;
T_2 V_143 = V_172 ;
T_2 V_142 = V_173 ;
T_1 V_144 = V_163 ;
int V_181 , V_121 ;
if ( V_6 -> V_60 & V_182 ) {
V_142 = V_183 ;
V_174 = 0x14 ;
}
V_6 -> V_175 = V_174 ;
for ( V_121 = 0 ; V_121 < V_178 ; V_121 ++ ) {
struct V_137 * V_138 = V_6 -> V_140 + V_121 ;
T_2 V_11 = F_85 ( V_6 , V_138 ) ;
T_2 type = F_91 ( V_11 ) ;
T_1 V_145 = F_83 ( V_144 ) ;
bool V_146 = false ;
if ( type == V_184 )
continue;
if ( type == V_185 )
V_146 = F_96 ( V_6 , V_138 , V_144 , & V_145 ) ;
V_181 = F_89 ( V_6 , V_138 , V_142 , V_143 , V_144 , V_145 , V_146 ) ;
if ( V_181 < 0 ) {
F_98 ( V_6 ) ;
return V_181 ;
}
V_144 = V_138 -> V_144 ;
V_142 = V_138 -> V_11 & V_186 ;
V_143 = V_138 -> V_11 & V_165 ;
}
return 0 ;
}
static int F_102 ( struct V_5 * V_6 )
{
V_6 -> V_7 = F_65 ( V_97 * sizeof( * V_6 -> V_7 ) ,
V_114 ) ;
if ( ! V_6 -> V_7 )
return - V_115 ;
return 0 ;
}
static void F_103 ( void )
{
void T_9 * V_187 = F_104 () ;
struct V_188 * V_189 ;
T_2 V_11 , V_148 ;
V_189 = F_105 () -> V_189 ;
if ( ! V_189 ) {
T_8 V_130 ;
V_189 = F_82 ( V_133 | V_152 ,
F_83 ( F_97 ( T_1 , V_190 , V_163 ) ) ) ;
if ( ! V_189 ) {
F_78 ( L_15 ,
F_106 () ) ;
return;
}
F_35 ( F_51 ( V_189 ) , V_190 ) ;
V_130 = F_84 ( V_189 ) ;
F_67 ( L_16 ,
F_106 () , & V_130 ) ;
F_105 () -> V_189 = V_189 ;
}
V_11 = F_27 ( V_187 + V_191 ) ;
V_11 &= ~ V_192 ;
F_33 ( V_11 , V_187 + V_191 ) ;
F_36 ( V_193 ) ;
V_11 = ( F_84 ( V_83 -> V_84 ) |
V_194 |
V_195 |
( ( V_196 - 1 ) & V_197 ) ) ;
F_107 ( V_11 , V_187 + V_198 ) ;
V_148 = F_108 ( V_187 + V_198 ) ;
if ( ( V_148 ^ V_11 ) & V_199 ) {
if ( ! ( V_148 & V_199 ) ) {
V_11 &= ~ ( V_199 |
V_200 ) ;
V_11 |= V_201 ;
F_107 ( V_11 , V_187 + V_198 ) ;
}
F_109 ( L_17 ) ;
V_83 -> V_60 |= V_86 ;
}
V_11 = ( F_84 ( V_189 ) |
V_202 |
V_203 ) ;
F_110 ( V_11 , V_187 + V_204 ) ;
V_148 = F_111 ( V_187 + V_204 ) ;
if ( ! ( V_148 & V_205 ) ) {
V_11 &= ~ ( V_205 |
V_206 ) ;
V_11 |= V_207 ;
F_110 ( V_11 , V_187 + V_204 ) ;
}
V_11 = F_27 ( V_187 + V_191 ) ;
V_11 |= V_192 ;
F_33 ( V_11 , V_187 + V_191 ) ;
F_36 ( V_193 ) ;
}
static void F_112 ( void )
{
struct V_5 * V_6 ;
int V_90 ;
F_70 ( & V_208 ) ;
V_90 = F_106 () ;
F_113 (its, &its_nodes, entry) {
T_2 V_209 ;
if ( V_6 -> V_60 & V_94 ) {
struct V_210 * V_211 ;
V_211 = F_114 ( V_90 , NULL ) ;
if ( V_6 -> V_95 != V_212 &&
V_6 -> V_95 != F_115 ( V_211 ) )
continue;
}
if ( F_100 ( V_6 -> V_54 + V_180 ) & V_213 ) {
V_209 = F_105 () -> V_102 ;
} else {
V_209 = F_100 ( F_104 () + V_214 ) ;
V_209 = F_116 ( V_209 ) << 16 ;
}
V_6 -> V_7 [ V_90 ] . V_38 = V_209 ;
V_6 -> V_7 [ V_90 ] . V_37 = V_90 ;
F_43 ( V_6 , & V_6 -> V_7 [ V_90 ] , 1 ) ;
F_47 ( V_6 , & V_6 -> V_7 [ V_90 ] ) ;
}
F_73 ( & V_208 ) ;
}
static struct V_2 * F_117 ( struct V_5 * V_6 , T_1 V_215 )
{
struct V_2 * V_3 = NULL , * V_148 ;
unsigned long V_60 ;
F_39 ( & V_6 -> V_72 , V_60 ) ;
F_113 (tmp, &its->its_device_list, entry) {
if ( V_148 -> V_34 == V_215 ) {
V_3 = V_148 ;
break;
}
}
F_40 ( & V_6 -> V_72 , V_60 ) ;
return V_3 ;
}
static struct V_137 * F_118 ( struct V_5 * V_6 , T_1 type )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_178 ; V_121 ++ ) {
if ( F_91 ( V_6 -> V_140 [ V_121 ] . V_11 ) == type )
return & V_6 -> V_140 [ V_121 ] ;
}
return NULL ;
}
static bool F_119 ( struct V_5 * V_6 , T_1 V_215 )
{
struct V_137 * V_138 ;
struct V_188 * V_188 ;
T_1 V_147 , V_139 ;
T_10 * V_216 ;
V_138 = F_118 ( V_6 , V_185 ) ;
if ( ! V_138 )
return ( F_16 ( V_215 ) < V_6 -> V_175 ) ;
V_147 = F_90 ( V_138 -> V_11 ) ;
if ( ! ( V_138 -> V_11 & V_158 ) )
return ( V_215 < ( F_92 ( V_138 -> V_145 ) / V_147 ) ) ;
V_139 = V_215 >> F_16 ( V_138 -> V_144 / V_147 ) ;
if ( V_139 >= ( F_92 ( V_138 -> V_145 ) / V_169 ) )
return false ;
V_216 = V_138 -> V_54 ;
if ( ! V_216 [ V_139 ] ) {
V_188 = F_82 ( V_114 | V_152 , F_83 ( V_138 -> V_144 ) ) ;
if ( ! V_188 )
return false ;
if ( ! ( V_138 -> V_11 & V_165 ) )
F_35 ( F_51 ( V_188 ) , V_138 -> V_144 ) ;
V_216 [ V_139 ] = F_14 ( F_84 ( V_188 ) | V_157 ) ;
if ( ! ( V_138 -> V_11 & V_165 ) )
F_35 ( V_216 + V_139 , V_169 ) ;
F_36 ( V_193 ) ;
}
return true ;
}
static struct V_2 * F_120 ( struct V_5 * V_6 , T_1 V_215 ,
int V_217 )
{
struct V_2 * V_29 ;
unsigned long * V_129 ;
unsigned long V_60 ;
T_4 * V_9 = NULL ;
void * V_31 ;
int V_80 ;
int V_128 ;
int V_30 ;
int V_218 ;
if ( ! F_119 ( V_6 , V_215 ) )
return NULL ;
V_29 = F_65 ( sizeof( * V_29 ) , V_114 ) ;
V_30 = F_121 ( 2UL , F_122 ( V_217 ) ) ;
V_218 = V_30 * V_6 -> V_219 ;
V_218 = F_121 ( V_218 , V_32 ) + V_32 - 1 ;
V_31 = F_65 ( V_218 , V_114 ) ;
V_129 = F_68 ( V_217 , & V_80 , & V_128 ) ;
if ( V_129 )
V_9 = F_65 ( sizeof( * V_9 ) * V_128 , V_114 ) ;
if ( ! V_29 || ! V_31 || ! V_129 || ! V_9 ) {
F_79 ( V_29 ) ;
F_79 ( V_31 ) ;
F_79 ( V_129 ) ;
F_79 ( V_9 ) ;
return NULL ;
}
F_35 ( V_31 , V_218 ) ;
V_29 -> V_6 = V_6 ;
V_29 -> V_31 = V_31 ;
V_29 -> V_30 = V_30 ;
V_29 -> V_8 . V_129 = V_129 ;
V_29 -> V_8 . V_9 = V_9 ;
V_29 -> V_8 . V_80 = V_80 ;
V_29 -> V_8 . V_128 = V_128 ;
V_29 -> V_34 = V_215 ;
F_123 ( & V_29 -> V_220 ) ;
F_39 ( & V_6 -> V_72 , V_60 ) ;
F_124 ( & V_29 -> V_220 , & V_6 -> V_221 ) ;
F_40 ( & V_6 -> V_72 , V_60 ) ;
F_42 ( V_29 , 1 ) ;
return V_29 ;
}
static void F_125 ( struct V_2 * V_3 )
{
unsigned long V_60 ;
F_39 ( & V_3 -> V_6 -> V_72 , V_60 ) ;
F_126 ( & V_3 -> V_220 ) ;
F_40 ( & V_3 -> V_6 -> V_72 , V_60 ) ;
F_79 ( V_3 -> V_31 ) ;
F_79 ( V_3 ) ;
}
static int F_127 ( struct V_2 * V_29 , T_6 * V_79 )
{
int V_139 ;
V_139 = F_128 ( V_29 -> V_8 . V_129 ,
V_29 -> V_8 . V_128 ) ;
if ( V_139 == V_29 -> V_8 . V_128 )
return - V_222 ;
* V_79 = V_29 -> V_8 . V_80 + V_139 ;
F_72 ( V_139 , V_29 -> V_8 . V_129 ) ;
return 0 ;
}
static int F_129 ( struct V_223 * V_224 , struct V_225 * V_29 ,
int V_226 , T_11 * V_227 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_228 * V_229 ;
T_1 V_215 ;
V_215 = V_227 -> V_230 [ 0 ] . V_231 ;
V_229 = F_130 ( V_224 ) ;
V_6 = V_229 -> V_106 ;
V_3 = F_117 ( V_6 , V_215 ) ;
if ( V_3 ) {
F_131 ( L_18 , V_215 ) ;
goto V_124;
}
V_3 = F_120 ( V_6 , V_215 , V_226 ) ;
if ( ! V_3 )
return - V_115 ;
F_131 ( L_19 , V_226 , F_16 ( V_226 ) ) ;
V_124:
V_227 -> V_230 [ 0 ] . V_49 = V_3 ;
return 0 ;
}
static int F_132 ( struct V_223 * V_224 ,
unsigned int V_232 ,
T_6 V_79 )
{
struct V_233 V_234 ;
if ( F_133 ( V_224 -> V_235 ) ) {
V_234 . V_236 = V_224 -> V_235 -> V_236 ;
V_234 . V_237 = 3 ;
V_234 . V_238 [ 0 ] = V_239 ;
V_234 . V_238 [ 1 ] = V_79 ;
V_234 . V_238 [ 2 ] = V_240 ;
} else if ( F_134 ( V_224 -> V_235 -> V_236 ) ) {
V_234 . V_236 = V_224 -> V_235 -> V_236 ;
V_234 . V_237 = 2 ;
V_234 . V_238 [ 0 ] = V_79 ;
V_234 . V_238 [ 1 ] = V_240 ;
} else {
return - V_96 ;
}
return F_135 ( V_224 , V_232 , 1 , & V_234 ) ;
}
static int F_136 ( struct V_223 * V_224 , unsigned int V_232 ,
unsigned int V_116 , void * args )
{
T_11 * V_227 = args ;
struct V_2 * V_3 = V_227 -> V_230 [ 0 ] . V_49 ;
T_6 V_79 ;
int V_181 ;
int V_121 ;
for ( V_121 = 0 ; V_121 < V_116 ; V_121 ++ ) {
V_181 = F_127 ( V_3 , & V_79 ) ;
if ( V_181 )
return V_181 ;
V_181 = F_132 ( V_224 , V_232 + V_121 , V_79 ) ;
if ( V_181 )
return V_181 ;
F_137 ( V_224 , V_232 + V_121 ,
V_79 , & V_241 , V_3 ) ;
F_131 ( L_20 ,
( int ) ( V_79 - V_3 -> V_8 . V_80 ) ,
( int ) V_79 , V_232 + V_121 ) ;
}
return 0 ;
}
static void F_138 ( struct V_223 * V_224 ,
struct V_77 * V_78 )
{
struct V_2 * V_3 = F_49 ( V_78 ) ;
T_1 V_4 = F_48 ( V_78 ) ;
const struct V_87 * V_91 = V_92 ;
if ( V_3 -> V_6 -> V_95 >= 0 )
V_91 = F_55 ( V_3 -> V_6 -> V_95 ) ;
V_3 -> V_8 . V_9 [ V_4 ] = F_139 ( V_91 ) ;
F_44 ( V_3 , V_78 -> V_79 , V_4 ) ;
}
static void F_140 ( struct V_223 * V_224 ,
struct V_77 * V_78 )
{
struct V_2 * V_3 = F_49 ( V_78 ) ;
T_1 V_4 = F_48 ( V_78 ) ;
F_46 ( V_3 , V_4 ) ;
}
static void F_141 ( struct V_223 * V_224 , unsigned int V_232 ,
unsigned int V_116 )
{
struct V_77 * V_78 = F_142 ( V_224 , V_232 ) ;
struct V_2 * V_3 = F_49 ( V_78 ) ;
int V_121 ;
for ( V_121 = 0 ; V_121 < V_116 ; V_121 ++ ) {
struct V_77 * V_106 = F_142 ( V_224 ,
V_232 + V_121 ) ;
T_1 V_4 = F_48 ( V_106 ) ;
F_77 ( V_4 , V_3 -> V_8 . V_129 ) ;
F_143 ( V_106 ) ;
}
if ( F_144 ( V_3 -> V_8 . V_129 ,
V_3 -> V_8 . V_128 ) ) {
F_74 ( & V_3 -> V_8 ) ;
F_42 ( V_3 , 0 ) ;
F_125 ( V_3 ) ;
}
F_145 ( V_224 , V_232 , V_116 ) ;
}
static int F_146 ( void T_9 * V_54 )
{
T_1 V_57 = 1000000 ;
T_1 V_11 ;
V_11 = F_27 ( V_54 + V_242 ) ;
if ( ( V_11 & V_243 ) && ! ( V_11 & V_244 ) )
return 0 ;
V_11 &= ~ V_244 ;
F_33 ( V_11 , V_54 + V_242 ) ;
while ( 1 ) {
V_11 = F_27 ( V_54 + V_242 ) ;
if ( V_11 & V_243 )
return 0 ;
V_57 -- ;
if ( ! V_57 )
return - V_245 ;
F_30 () ;
F_31 ( 1 ) ;
}
}
static void T_12 F_147 ( void * V_106 )
{
struct V_5 * V_6 = V_106 ;
V_6 -> V_60 |= V_182 ;
}
static void T_12 F_148 ( void * V_106 )
{
struct V_5 * V_6 = V_106 ;
V_6 -> V_60 |= V_94 ;
}
static void T_12 F_149 ( void * V_106 )
{
struct V_5 * V_6 = V_106 ;
V_6 -> V_219 = 16 ;
}
static void F_150 ( struct V_5 * V_6 )
{
T_1 V_246 = F_27 ( V_6 -> V_54 + V_247 ) ;
F_151 ( V_246 , V_248 , V_6 ) ;
}
static int F_152 ( struct V_249 * V_250 , struct V_5 * V_6 )
{
struct V_223 * V_251 ;
struct V_228 * V_227 ;
V_227 = F_65 ( sizeof( * V_227 ) , V_114 ) ;
if ( ! V_227 )
return - V_115 ;
V_251 = F_153 ( V_250 , & V_252 , V_6 ) ;
if ( ! V_251 ) {
F_79 ( V_227 ) ;
return - V_115 ;
}
V_251 -> V_235 = V_253 ;
F_154 ( V_251 , V_254 ) ;
V_251 -> V_60 |= V_255 ;
V_227 -> V_256 = & V_257 ;
V_227 -> V_106 = V_6 ;
V_251 -> V_258 = V_227 ;
return 0 ;
}
static int T_7 F_155 ( struct V_259 * V_260 ,
struct V_249 * V_250 , int V_95 )
{
struct V_5 * V_6 ;
void T_9 * V_261 ;
T_1 V_11 ;
T_2 V_138 , V_148 ;
int V_181 ;
V_261 = F_156 ( V_260 -> V_262 , F_157 ( V_260 ) ) ;
if ( ! V_261 ) {
F_93 ( L_21 , & V_260 -> V_262 ) ;
return - V_115 ;
}
V_11 = F_27 ( V_261 + V_263 ) & V_264 ;
if ( V_11 != 0x30 && V_11 != 0x40 ) {
F_93 ( L_22 , & V_260 -> V_262 ) ;
V_181 = - V_265 ;
goto V_266;
}
V_181 = F_146 ( V_261 ) ;
if ( V_181 ) {
F_93 ( L_23 , & V_260 -> V_262 ) ;
goto V_266;
}
F_67 ( L_24 , V_260 ) ;
V_6 = F_65 ( sizeof( * V_6 ) , V_114 ) ;
if ( ! V_6 ) {
V_181 = - V_115 ;
goto V_266;
}
F_158 ( & V_6 -> V_72 ) ;
F_123 ( & V_6 -> V_220 ) ;
F_123 ( & V_6 -> V_221 ) ;
V_6 -> V_54 = V_261 ;
V_6 -> V_102 = V_260 -> V_262 ;
V_6 -> V_219 = ( ( F_100 ( V_261 + V_180 ) >> 4 ) & 0xf ) + 1 ;
V_6 -> V_95 = V_95 ;
V_6 -> V_50 = ( void * ) F_94 ( V_114 | V_152 ,
F_83 ( V_267 ) ) ;
if ( ! V_6 -> V_50 ) {
V_181 = - V_115 ;
goto V_268;
}
V_6 -> V_53 = V_6 -> V_50 ;
F_150 ( V_6 ) ;
V_181 = F_99 ( V_6 ) ;
if ( V_181 )
goto V_269;
V_181 = F_102 ( V_6 ) ;
if ( V_181 )
goto V_270;
V_138 = ( F_17 ( V_6 -> V_50 ) |
V_271 |
V_272 |
( V_267 / V_159 - 1 ) |
V_273 ) ;
F_159 ( V_138 , V_6 -> V_54 + V_274 ) ;
V_148 = F_160 ( V_6 -> V_54 + V_274 ) ;
if ( ( V_148 ^ V_138 ) & V_275 ) {
if ( ! ( V_148 & V_275 ) ) {
V_138 &= ~ ( V_275 |
V_276 ) ;
V_138 |= V_277 ;
F_159 ( V_138 , V_6 -> V_54 + V_274 ) ;
}
F_67 ( L_25 ) ;
V_6 -> V_60 |= V_61 ;
}
F_161 ( 0 , V_6 -> V_54 + V_59 ) ;
F_33 ( V_244 , V_6 -> V_54 + V_242 ) ;
V_181 = F_152 ( V_250 , V_6 ) ;
if ( V_181 )
goto V_270;
F_70 ( & V_208 ) ;
F_124 ( & V_6 -> V_220 , & V_278 ) ;
F_73 ( & V_208 ) ;
return 0 ;
V_270:
F_98 ( V_6 ) ;
V_269:
F_95 ( ( unsigned long ) V_6 -> V_50 , F_83 ( V_267 ) ) ;
V_268:
F_79 ( V_6 ) ;
V_266:
F_162 ( V_261 ) ;
F_78 ( L_26 , & V_260 -> V_262 , V_181 ) ;
return V_181 ;
}
static bool F_163 ( void )
{
return ! ! ( F_100 ( F_104 () + V_214 ) & V_279 ) ;
}
int F_164 ( void )
{
if ( ! F_165 ( & V_278 ) ) {
if ( ! F_163 () ) {
F_67 ( L_27 , F_106 () ) ;
return - V_168 ;
}
F_103 () ;
F_112 () ;
}
return 0 ;
}
static int T_7 F_166 ( struct V_210 * V_280 )
{
struct V_210 * V_281 ;
struct V_259 V_260 ;
for ( V_281 = F_167 ( V_280 , V_282 ) ; V_281 ;
V_281 = F_167 ( V_281 , V_282 ) ) {
if ( ! F_168 ( V_281 , L_28 ) ) {
F_93 ( L_29 ,
V_281 -> V_283 ) ;
continue;
}
if ( F_169 ( V_281 , 0 , & V_260 ) ) {
F_93 ( L_30 , V_281 -> V_283 ) ;
continue;
}
F_155 ( & V_260 , & V_281 -> V_236 , F_115 ( V_281 ) ) ;
}
return 0 ;
}
static int T_7 F_170 ( T_1 V_284 )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_285 ; V_121 ++ ) {
if ( V_284 == V_286 [ V_121 ] . V_284 )
return V_286 [ V_121 ] . V_95 ;
}
return V_212 ;
}
static int T_7 F_171 ( struct V_287 * V_288 ,
const unsigned long V_289 )
{
return 0 ;
}
static int T_7 F_172 ( struct V_287 * V_288 ,
const unsigned long V_289 )
{
int V_280 ;
struct V_290 * V_291 ;
V_291 = (struct V_290 * ) V_288 ;
if ( ! V_291 )
return - V_96 ;
if ( V_291 -> V_288 . V_292 < sizeof( * V_291 ) ) {
F_78 ( L_31 ,
V_291 -> V_288 . V_292 ) ;
return - V_96 ;
}
V_280 = F_173 ( V_291 -> V_293 ) ;
if ( V_280 == V_212 || V_280 >= V_294 ) {
F_78 ( L_32 , V_280 ) ;
return 0 ;
}
V_286 [ V_285 ] . V_95 = V_280 ;
V_286 [ V_285 ] . V_284 = V_291 -> V_284 ;
V_285 ++ ;
F_67 ( L_33 ,
V_291 -> V_293 , V_291 -> V_284 , V_280 ) ;
return 0 ;
}
static void T_7 F_174 ( void )
{
int V_57 ;
V_57 = F_175 ( V_295 ,
sizeof( struct V_296 ) ,
V_297 ,
F_171 , 0 ) ;
if ( V_57 <= 0 )
return;
V_286 = F_176 ( V_57 * sizeof( struct V_298 ) ,
V_114 ) ;
if ( ! V_286 ) {
F_93 ( L_34 ) ;
return;
}
F_175 ( V_295 ,
sizeof( struct V_296 ) ,
V_297 ,
F_172 , 0 ) ;
}
static void T_7 F_177 ( void )
{
F_79 ( V_286 ) ;
}
static void T_7 F_174 ( void ) { }
static int T_7 F_170 ( T_1 V_284 ) { return V_212 ; }
static void T_7 F_177 ( void ) { }
static int T_7 F_178 ( struct V_287 * V_288 ,
const unsigned long V_289 )
{
struct V_299 * V_300 ;
struct V_249 * V_301 ;
struct V_259 V_260 ;
int V_181 ;
V_300 = (struct V_299 * ) V_288 ;
memset ( & V_260 , 0 , sizeof( V_260 ) ) ;
V_260 . V_262 = V_300 -> V_302 ;
V_260 . V_289 = V_300 -> V_302 + V_303 - 1 ;
V_260 . V_60 = V_304 ;
V_301 = F_179 ( ( void * ) V_300 -> V_302 ) ;
if ( ! V_301 ) {
F_78 ( L_35 ,
& V_260 . V_262 ) ;
return - V_115 ;
}
V_181 = F_180 ( V_300 -> V_305 , V_301 ) ;
if ( V_181 ) {
F_78 ( L_36 ,
& V_260 . V_262 , V_300 -> V_305 ) ;
goto V_306;
}
V_181 = F_155 ( & V_260 , V_301 ,
F_170 ( V_300 -> V_305 ) ) ;
if ( ! V_181 )
return 0 ;
F_181 ( V_300 -> V_305 ) ;
V_306:
F_182 ( V_301 ) ;
return V_181 ;
}
static void T_7 F_183 ( void )
{
F_174 () ;
F_184 ( V_307 ,
F_178 , 0 ) ;
F_177 () ;
}
static void T_7 F_183 ( void ) { }
int T_7 F_185 ( struct V_249 * V_250 , struct V_308 * V_308 ,
struct V_223 * V_309 )
{
struct V_210 * V_310 ;
V_253 = V_309 ;
V_310 = F_186 ( V_250 ) ;
if ( V_310 )
F_166 ( V_310 ) ;
else
F_183 () ;
if ( F_165 ( & V_278 ) ) {
F_93 ( L_37 ) ;
return - V_168 ;
}
V_83 = V_308 ;
return F_80 () ;
}
