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
V_93 = & V_3 -> V_6 -> V_7 [ V_90 ] ;
F_45 ( V_3 , V_93 , V_19 ) ;
V_3 -> V_8 . V_9 [ V_19 ] = V_90 ;
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
V_83 -> V_84 = F_81 ( V_131 ,
F_82 ( V_132 ) ) ;
if ( ! V_83 -> V_84 ) {
F_78 ( L_7 ) ;
return - V_115 ;
}
V_130 = F_83 ( V_83 -> V_84 ) ;
F_67 ( L_8 , & V_130 ) ;
memset ( F_51 ( V_83 -> V_84 ) ,
V_133 | V_134 ,
V_132 ) ;
F_35 ( F_51 ( V_83 -> V_84 ) , V_132 ) ;
return 0 ;
}
static T_2 F_84 ( struct V_5 * V_6 , struct V_135 * V_136 )
{
T_1 V_137 = V_136 - V_6 -> V_138 ;
return F_85 ( V_6 -> V_54 + V_139 + ( V_137 << 3 ) ) ;
}
static void F_86 ( struct V_5 * V_6 , struct V_135 * V_136 ,
T_2 V_11 )
{
T_1 V_137 = V_136 - V_6 -> V_138 ;
F_87 ( V_11 , V_6 -> V_54 + V_139 + ( V_137 << 3 ) ) ;
V_136 -> V_11 = F_84 ( V_6 , V_136 ) ;
}
static int F_88 ( struct V_5 * V_6 , struct V_135 * V_136 ,
T_2 V_140 , T_2 V_141 , T_1 V_142 , T_1 V_143 ,
bool V_144 )
{
T_2 V_11 = F_84 ( V_6 , V_136 ) ;
T_2 V_145 = F_89 ( V_11 ) ;
T_2 type = F_90 ( V_11 ) ;
T_1 F_81 ;
void * V_54 ;
T_2 V_146 ;
V_147:
F_81 = ( F_91 ( V_143 ) / V_142 ) ;
if ( F_81 > V_148 ) {
F_92 ( L_9 ,
& V_6 -> V_102 , V_149 [ type ] ,
F_81 , V_148 ) ;
F_81 = V_148 ;
V_143 = F_82 ( V_148 * V_142 ) ;
}
V_54 = ( void * ) F_93 ( V_114 | V_150 , V_143 ) ;
if ( ! V_54 )
return - V_115 ;
V_151:
V_11 = ( F_17 ( V_54 ) |
( type << V_152 ) |
( ( V_145 - 1 ) << V_153 ) |
( ( F_81 - 1 ) << V_154 ) |
V_140 |
V_141 |
V_155 ) ;
V_11 |= V_144 ? V_156 : 0x0 ;
switch ( V_142 ) {
case V_157 :
V_11 |= V_158 ;
break;
case V_159 :
V_11 |= V_160 ;
break;
case V_161 :
V_11 |= V_162 ;
break;
}
F_86 ( V_6 , V_136 , V_11 ) ;
V_146 = V_136 -> V_11 ;
if ( ( V_11 ^ V_146 ) & V_163 ) {
V_141 = V_146 & V_163 ;
if ( ! V_141 ) {
V_140 = V_164 ;
F_35 ( V_54 , F_91 ( V_143 ) ) ;
}
goto V_151;
}
if ( ( V_11 ^ V_146 ) & V_165 ) {
F_94 ( ( unsigned long ) V_54 , V_143 ) ;
V_136 -> V_54 = NULL ;
switch ( V_142 ) {
case V_159 :
V_142 = V_157 ;
goto V_147;
case V_161 :
V_142 = V_159 ;
goto V_147;
}
}
if ( V_11 != V_146 ) {
F_78 ( L_10 ,
& V_6 -> V_102 , V_149 [ type ] ,
V_11 , V_146 ) ;
F_94 ( ( unsigned long ) V_54 , V_143 ) ;
return - V_166 ;
}
V_136 -> V_143 = V_143 ;
V_136 -> V_54 = V_54 ;
V_136 -> V_142 = V_142 ;
V_146 = V_144 ? V_167 : V_145 ;
F_67 ( L_11 ,
& V_6 -> V_102 , ( int ) ( F_91 ( V_143 ) / ( int ) V_146 ) ,
V_149 [ type ] ,
( unsigned long ) F_17 ( V_54 ) ,
V_144 ? L_12 : L_13 , ( int ) V_145 ,
V_142 / V_168 , ( int ) V_141 >> V_169 ) ;
return 0 ;
}
static bool F_95 ( struct V_5 * V_6 , struct V_135 * V_136 ,
T_1 V_142 , T_1 * V_143 )
{
T_2 V_145 = F_89 ( F_84 ( V_6 , V_136 ) ) ;
T_2 V_11 = V_170 | V_171 ;
T_1 V_172 = V_6 -> V_173 ;
T_1 V_174 = * V_143 ;
bool V_144 = false ;
if ( ( V_145 << V_172 ) > ( V_142 * 2 ) ) {
F_86 ( V_6 , V_136 , V_11 | V_156 ) ;
V_144 = ! ! ( V_136 -> V_11 & V_156 ) ;
if ( V_144 ) {
V_172 -= F_16 ( V_142 / ( int ) V_145 ) ;
V_145 = V_167 ;
}
}
V_174 = F_96 ( T_1 , F_82 ( V_145 << V_172 ) , V_174 ) ;
if ( V_174 >= V_175 ) {
V_174 = V_175 - 1 ;
V_172 = F_16 ( F_91 ( V_174 ) / ( int ) V_145 ) ;
F_92 ( L_14 ,
& V_6 -> V_102 , V_6 -> V_173 , V_172 ) ;
}
* V_143 = V_174 ;
return V_144 ;
}
static void F_97 ( struct V_5 * V_6 )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_176 ; V_121 ++ ) {
if ( V_6 -> V_138 [ V_121 ] . V_54 ) {
F_94 ( ( unsigned long ) V_6 -> V_138 [ V_121 ] . V_54 ,
V_6 -> V_138 [ V_121 ] . V_143 ) ;
V_6 -> V_138 [ V_121 ] . V_54 = NULL ;
}
}
}
static int F_98 ( struct V_5 * V_6 )
{
T_2 V_177 = F_99 ( V_6 -> V_54 + V_178 ) ;
T_1 V_172 = F_100 ( V_177 ) ;
T_2 V_141 = V_170 ;
T_2 V_140 = V_171 ;
T_1 V_142 = V_161 ;
int V_179 , V_121 ;
if ( V_6 -> V_60 & V_180 ) {
V_140 = V_181 ;
V_172 = 0x14 ;
}
V_6 -> V_173 = V_172 ;
for ( V_121 = 0 ; V_121 < V_176 ; V_121 ++ ) {
struct V_135 * V_136 = V_6 -> V_138 + V_121 ;
T_2 V_11 = F_84 ( V_6 , V_136 ) ;
T_2 type = F_90 ( V_11 ) ;
T_1 V_143 = F_82 ( V_142 ) ;
bool V_144 = false ;
if ( type == V_182 )
continue;
if ( type == V_183 )
V_144 = F_95 ( V_6 , V_136 , V_142 , & V_143 ) ;
V_179 = F_88 ( V_6 , V_136 , V_140 , V_141 , V_142 , V_143 , V_144 ) ;
if ( V_179 < 0 ) {
F_97 ( V_6 ) ;
return V_179 ;
}
V_142 = V_136 -> V_142 ;
V_140 = V_136 -> V_11 & V_184 ;
V_141 = V_136 -> V_11 & V_163 ;
}
return 0 ;
}
static int F_101 ( struct V_5 * V_6 )
{
V_6 -> V_7 = F_65 ( V_97 * sizeof( * V_6 -> V_7 ) ,
V_114 ) ;
if ( ! V_6 -> V_7 )
return - V_115 ;
return 0 ;
}
static void F_102 ( void )
{
void T_9 * V_185 = F_103 () ;
struct V_186 * V_187 ;
T_2 V_11 , V_146 ;
V_187 = F_104 () -> V_187 ;
if ( ! V_187 ) {
T_8 V_130 ;
V_187 = F_81 ( V_131 | V_150 ,
F_82 ( F_105 ( V_188 , V_161 ) ) ) ;
if ( ! V_187 ) {
F_78 ( L_15 ,
F_106 () ) ;
return;
}
F_35 ( F_51 ( V_187 ) , V_188 ) ;
V_130 = F_83 ( V_187 ) ;
F_67 ( L_16 ,
F_106 () , & V_130 ) ;
F_104 () -> V_187 = V_187 ;
}
V_11 = F_27 ( V_185 + V_189 ) ;
V_11 &= ~ V_190 ;
F_33 ( V_11 , V_185 + V_189 ) ;
F_36 ( V_191 ) ;
V_11 = ( F_83 ( V_83 -> V_84 ) |
V_192 |
V_193 |
( ( V_194 - 1 ) & V_195 ) ) ;
F_107 ( V_11 , V_185 + V_196 ) ;
V_146 = F_108 ( V_185 + V_196 ) ;
if ( ( V_146 ^ V_11 ) & V_197 ) {
if ( ! ( V_146 & V_197 ) ) {
V_11 &= ~ ( V_197 |
V_198 ) ;
V_11 |= V_199 ;
F_107 ( V_11 , V_185 + V_196 ) ;
}
F_109 ( L_17 ) ;
V_83 -> V_60 |= V_86 ;
}
V_11 = ( F_83 ( V_187 ) |
V_200 |
V_201 ) ;
F_110 ( V_11 , V_185 + V_202 ) ;
V_146 = F_111 ( V_185 + V_202 ) ;
if ( ! ( V_146 & V_203 ) ) {
V_11 &= ~ ( V_203 |
V_204 ) ;
V_11 |= V_205 ;
F_110 ( V_11 , V_185 + V_202 ) ;
}
V_11 = F_27 ( V_185 + V_189 ) ;
V_11 |= V_190 ;
F_33 ( V_11 , V_185 + V_189 ) ;
F_36 ( V_191 ) ;
}
static void F_112 ( void )
{
struct V_5 * V_6 ;
int V_90 ;
F_70 ( & V_206 ) ;
V_90 = F_106 () ;
F_113 (its, &its_nodes, entry) {
T_2 V_207 ;
if ( V_6 -> V_60 & V_94 ) {
struct V_208 * V_209 ;
V_209 = F_114 ( V_90 , NULL ) ;
if ( V_6 -> V_95 != V_210 &&
V_6 -> V_95 != F_115 ( V_209 ) )
continue;
}
if ( F_99 ( V_6 -> V_54 + V_178 ) & V_211 ) {
V_207 = F_104 () -> V_102 ;
} else {
V_207 = F_99 ( F_103 () + V_212 ) ;
V_207 = F_116 ( V_207 ) << 16 ;
}
V_6 -> V_7 [ V_90 ] . V_38 = V_207 ;
V_6 -> V_7 [ V_90 ] . V_37 = V_90 ;
F_43 ( V_6 , & V_6 -> V_7 [ V_90 ] , 1 ) ;
F_47 ( V_6 , & V_6 -> V_7 [ V_90 ] ) ;
}
F_73 ( & V_206 ) ;
}
static struct V_2 * F_117 ( struct V_5 * V_6 , T_1 V_213 )
{
struct V_2 * V_3 = NULL , * V_146 ;
unsigned long V_60 ;
F_39 ( & V_6 -> V_72 , V_60 ) ;
F_113 (tmp, &its->its_device_list, entry) {
if ( V_146 -> V_34 == V_213 ) {
V_3 = V_146 ;
break;
}
}
F_40 ( & V_6 -> V_72 , V_60 ) ;
return V_3 ;
}
static struct V_135 * F_118 ( struct V_5 * V_6 , T_1 type )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_176 ; V_121 ++ ) {
if ( F_90 ( V_6 -> V_138 [ V_121 ] . V_11 ) == type )
return & V_6 -> V_138 [ V_121 ] ;
}
return NULL ;
}
static bool F_119 ( struct V_5 * V_6 , T_1 V_213 )
{
struct V_135 * V_136 ;
struct V_186 * V_186 ;
T_1 V_145 , V_137 ;
T_10 * V_214 ;
V_136 = F_118 ( V_6 , V_183 ) ;
if ( ! V_136 )
return ( F_16 ( V_213 ) < V_6 -> V_173 ) ;
V_145 = F_89 ( V_136 -> V_11 ) ;
if ( ! ( V_136 -> V_11 & V_156 ) )
return ( V_213 < ( F_91 ( V_136 -> V_143 ) / V_145 ) ) ;
V_137 = V_213 >> F_16 ( V_136 -> V_142 / V_145 ) ;
if ( V_137 >= ( F_91 ( V_136 -> V_143 ) / V_167 ) )
return false ;
V_214 = V_136 -> V_54 ;
if ( ! V_214 [ V_137 ] ) {
V_186 = F_81 ( V_114 | V_150 , F_82 ( V_136 -> V_142 ) ) ;
if ( ! V_186 )
return false ;
if ( ! ( V_136 -> V_11 & V_163 ) )
F_35 ( F_51 ( V_186 ) , V_136 -> V_142 ) ;
V_214 [ V_137 ] = F_14 ( F_83 ( V_186 ) | V_155 ) ;
if ( ! ( V_136 -> V_11 & V_163 ) )
F_35 ( V_214 + V_137 , V_167 ) ;
F_36 ( V_191 ) ;
}
return true ;
}
static struct V_2 * F_120 ( struct V_5 * V_6 , T_1 V_213 ,
int V_215 )
{
struct V_2 * V_29 ;
unsigned long * V_129 ;
unsigned long V_60 ;
T_4 * V_9 = NULL ;
void * V_31 ;
int V_80 ;
int V_128 ;
int V_30 ;
int V_216 ;
if ( ! F_119 ( V_6 , V_213 ) )
return NULL ;
V_29 = F_65 ( sizeof( * V_29 ) , V_114 ) ;
V_30 = F_105 ( 2UL , F_121 ( V_215 ) ) ;
V_216 = V_30 * V_6 -> V_217 ;
V_216 = F_105 ( V_216 , V_32 ) + V_32 - 1 ;
V_31 = F_65 ( V_216 , V_114 ) ;
V_129 = F_68 ( V_215 , & V_80 , & V_128 ) ;
if ( V_129 )
V_9 = F_65 ( sizeof( * V_9 ) * V_128 , V_114 ) ;
if ( ! V_29 || ! V_31 || ! V_129 || ! V_9 ) {
F_79 ( V_29 ) ;
F_79 ( V_31 ) ;
F_79 ( V_129 ) ;
F_79 ( V_9 ) ;
return NULL ;
}
F_35 ( V_31 , V_216 ) ;
V_29 -> V_6 = V_6 ;
V_29 -> V_31 = V_31 ;
V_29 -> V_30 = V_30 ;
V_29 -> V_8 . V_129 = V_129 ;
V_29 -> V_8 . V_9 = V_9 ;
V_29 -> V_8 . V_80 = V_80 ;
V_29 -> V_8 . V_128 = V_128 ;
V_29 -> V_34 = V_213 ;
F_122 ( & V_29 -> V_218 ) ;
F_39 ( & V_6 -> V_72 , V_60 ) ;
F_123 ( & V_29 -> V_218 , & V_6 -> V_219 ) ;
F_40 ( & V_6 -> V_72 , V_60 ) ;
F_42 ( V_29 , 1 ) ;
return V_29 ;
}
static void F_124 ( struct V_2 * V_3 )
{
unsigned long V_60 ;
F_39 ( & V_3 -> V_6 -> V_72 , V_60 ) ;
F_125 ( & V_3 -> V_218 ) ;
F_40 ( & V_3 -> V_6 -> V_72 , V_60 ) ;
F_79 ( V_3 -> V_31 ) ;
F_79 ( V_3 ) ;
}
static int F_126 ( struct V_2 * V_29 , T_6 * V_79 )
{
int V_137 ;
V_137 = F_127 ( V_29 -> V_8 . V_129 ,
V_29 -> V_8 . V_128 ) ;
if ( V_137 == V_29 -> V_8 . V_128 )
return - V_220 ;
* V_79 = V_29 -> V_8 . V_80 + V_137 ;
F_72 ( V_137 , V_29 -> V_8 . V_129 ) ;
return 0 ;
}
static int F_128 ( struct V_221 * V_222 , struct V_223 * V_29 ,
int V_224 , T_11 * V_225 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_226 * V_227 ;
T_1 V_213 ;
V_213 = V_225 -> V_228 [ 0 ] . V_229 ;
V_227 = F_129 ( V_222 ) ;
V_6 = V_227 -> V_106 ;
V_3 = F_117 ( V_6 , V_213 ) ;
if ( V_3 ) {
F_130 ( L_18 , V_213 ) ;
goto V_124;
}
V_3 = F_120 ( V_6 , V_213 , V_224 ) ;
if ( ! V_3 )
return - V_115 ;
F_130 ( L_19 , V_224 , F_16 ( V_224 ) ) ;
V_124:
V_225 -> V_228 [ 0 ] . V_49 = V_3 ;
return 0 ;
}
static int F_131 ( struct V_221 * V_222 ,
unsigned int V_230 ,
T_6 V_79 )
{
struct V_231 V_232 ;
if ( F_132 ( V_222 -> V_233 ) ) {
V_232 . V_234 = V_222 -> V_233 -> V_234 ;
V_232 . V_235 = 3 ;
V_232 . V_236 [ 0 ] = V_237 ;
V_232 . V_236 [ 1 ] = V_79 ;
V_232 . V_236 [ 2 ] = V_238 ;
} else if ( F_133 ( V_222 -> V_233 -> V_234 ) ) {
V_232 . V_234 = V_222 -> V_233 -> V_234 ;
V_232 . V_235 = 2 ;
V_232 . V_236 [ 0 ] = V_79 ;
V_232 . V_236 [ 1 ] = V_238 ;
} else {
return - V_96 ;
}
return F_134 ( V_222 , V_230 , 1 , & V_232 ) ;
}
static int F_135 ( struct V_221 * V_222 , unsigned int V_230 ,
unsigned int V_116 , void * args )
{
T_11 * V_225 = args ;
struct V_2 * V_3 = V_225 -> V_228 [ 0 ] . V_49 ;
T_6 V_79 ;
int V_179 ;
int V_121 ;
for ( V_121 = 0 ; V_121 < V_116 ; V_121 ++ ) {
V_179 = F_126 ( V_3 , & V_79 ) ;
if ( V_179 )
return V_179 ;
V_179 = F_131 ( V_222 , V_230 + V_121 , V_79 ) ;
if ( V_179 )
return V_179 ;
F_136 ( V_222 , V_230 + V_121 ,
V_79 , & V_239 , V_3 ) ;
F_130 ( L_20 ,
( int ) ( V_79 - V_3 -> V_8 . V_80 ) ,
( int ) V_79 , V_230 + V_121 ) ;
}
return 0 ;
}
static void F_137 ( struct V_221 * V_222 ,
struct V_77 * V_78 )
{
struct V_2 * V_3 = F_49 ( V_78 ) ;
T_1 V_4 = F_48 ( V_78 ) ;
const struct V_87 * V_91 = V_92 ;
if ( V_3 -> V_6 -> V_95 >= 0 )
V_91 = F_55 ( V_3 -> V_6 -> V_95 ) ;
V_3 -> V_8 . V_9 [ V_4 ] = F_138 ( V_91 ) ;
F_44 ( V_3 , V_78 -> V_79 , V_4 ) ;
}
static void F_139 ( struct V_221 * V_222 ,
struct V_77 * V_78 )
{
struct V_2 * V_3 = F_49 ( V_78 ) ;
T_1 V_4 = F_48 ( V_78 ) ;
F_46 ( V_3 , V_4 ) ;
}
static void F_140 ( struct V_221 * V_222 , unsigned int V_230 ,
unsigned int V_116 )
{
struct V_77 * V_78 = F_141 ( V_222 , V_230 ) ;
struct V_2 * V_3 = F_49 ( V_78 ) ;
int V_121 ;
for ( V_121 = 0 ; V_121 < V_116 ; V_121 ++ ) {
struct V_77 * V_106 = F_141 ( V_222 ,
V_230 + V_121 ) ;
T_1 V_4 = F_48 ( V_106 ) ;
F_77 ( V_4 , V_3 -> V_8 . V_129 ) ;
F_142 ( V_106 ) ;
}
if ( F_143 ( V_3 -> V_8 . V_129 ,
V_3 -> V_8 . V_128 ) ) {
F_74 ( & V_3 -> V_8 ) ;
F_42 ( V_3 , 0 ) ;
F_124 ( V_3 ) ;
}
F_144 ( V_222 , V_230 , V_116 ) ;
}
static int F_145 ( void T_9 * V_54 )
{
T_1 V_57 = 1000000 ;
T_1 V_11 ;
V_11 = F_27 ( V_54 + V_240 ) ;
if ( ( V_11 & V_241 ) && ! ( V_11 & V_242 ) )
return 0 ;
V_11 &= ~ V_242 ;
F_33 ( V_11 , V_54 + V_240 ) ;
while ( 1 ) {
V_11 = F_27 ( V_54 + V_240 ) ;
if ( V_11 & V_241 )
return 0 ;
V_57 -- ;
if ( ! V_57 )
return - V_243 ;
F_30 () ;
F_31 ( 1 ) ;
}
}
static void T_12 F_146 ( void * V_106 )
{
struct V_5 * V_6 = V_106 ;
V_6 -> V_60 |= V_180 ;
}
static void T_12 F_147 ( void * V_106 )
{
struct V_5 * V_6 = V_106 ;
V_6 -> V_60 |= V_94 ;
}
static void T_12 F_148 ( void * V_106 )
{
struct V_5 * V_6 = V_106 ;
V_6 -> V_217 = 16 ;
}
static void F_149 ( struct V_5 * V_6 )
{
T_1 V_244 = F_27 ( V_6 -> V_54 + V_245 ) ;
F_150 ( V_244 , V_246 , V_6 ) ;
}
static int F_151 ( struct V_247 * V_248 , struct V_5 * V_6 )
{
struct V_221 * V_249 ;
struct V_226 * V_225 ;
V_225 = F_65 ( sizeof( * V_225 ) , V_114 ) ;
if ( ! V_225 )
return - V_115 ;
V_249 = F_152 ( V_248 , & V_250 , V_6 ) ;
if ( ! V_249 ) {
F_79 ( V_225 ) ;
return - V_115 ;
}
V_249 -> V_233 = V_251 ;
V_249 -> V_252 = V_253 ;
V_249 -> V_60 |= V_254 ;
V_225 -> V_255 = & V_256 ;
V_225 -> V_106 = V_6 ;
V_249 -> V_257 = V_225 ;
return 0 ;
}
static int T_7 F_153 ( struct V_258 * V_259 ,
struct V_247 * V_248 , int V_95 )
{
struct V_5 * V_6 ;
void T_9 * V_260 ;
T_1 V_11 ;
T_2 V_136 , V_146 ;
int V_179 ;
V_260 = F_154 ( V_259 -> V_261 , F_155 ( V_259 ) ) ;
if ( ! V_260 ) {
F_92 ( L_21 , & V_259 -> V_261 ) ;
return - V_115 ;
}
V_11 = F_27 ( V_260 + V_262 ) & V_263 ;
if ( V_11 != 0x30 && V_11 != 0x40 ) {
F_92 ( L_22 , & V_259 -> V_261 ) ;
V_179 = - V_264 ;
goto V_265;
}
V_179 = F_145 ( V_260 ) ;
if ( V_179 ) {
F_92 ( L_23 , & V_259 -> V_261 ) ;
goto V_265;
}
F_67 ( L_24 , V_259 ) ;
V_6 = F_65 ( sizeof( * V_6 ) , V_114 ) ;
if ( ! V_6 ) {
V_179 = - V_115 ;
goto V_265;
}
F_156 ( & V_6 -> V_72 ) ;
F_122 ( & V_6 -> V_218 ) ;
F_122 ( & V_6 -> V_219 ) ;
V_6 -> V_54 = V_260 ;
V_6 -> V_102 = V_259 -> V_261 ;
V_6 -> V_217 = ( ( F_99 ( V_260 + V_178 ) >> 4 ) & 0xf ) + 1 ;
V_6 -> V_95 = V_95 ;
V_6 -> V_50 = ( void * ) F_93 ( V_114 | V_150 ,
F_82 ( V_266 ) ) ;
if ( ! V_6 -> V_50 ) {
V_179 = - V_115 ;
goto V_267;
}
V_6 -> V_53 = V_6 -> V_50 ;
F_149 ( V_6 ) ;
V_179 = F_98 ( V_6 ) ;
if ( V_179 )
goto V_268;
V_179 = F_101 ( V_6 ) ;
if ( V_179 )
goto V_269;
V_136 = ( F_17 ( V_6 -> V_50 ) |
V_270 |
V_271 |
( V_266 / V_157 - 1 ) |
V_272 ) ;
F_157 ( V_136 , V_6 -> V_54 + V_273 ) ;
V_146 = F_158 ( V_6 -> V_54 + V_273 ) ;
if ( ( V_146 ^ V_136 ) & V_274 ) {
if ( ! ( V_146 & V_274 ) ) {
V_136 &= ~ ( V_274 |
V_275 ) ;
V_136 |= V_276 ;
F_157 ( V_136 , V_6 -> V_54 + V_273 ) ;
}
F_67 ( L_25 ) ;
V_6 -> V_60 |= V_61 ;
}
F_159 ( 0 , V_6 -> V_54 + V_59 ) ;
F_33 ( V_242 , V_6 -> V_54 + V_240 ) ;
V_179 = F_151 ( V_248 , V_6 ) ;
if ( V_179 )
goto V_269;
F_70 ( & V_206 ) ;
F_123 ( & V_6 -> V_218 , & V_277 ) ;
F_73 ( & V_206 ) ;
return 0 ;
V_269:
F_97 ( V_6 ) ;
V_268:
F_94 ( ( unsigned long ) V_6 -> V_50 , F_82 ( V_266 ) ) ;
V_267:
F_79 ( V_6 ) ;
V_265:
F_160 ( V_260 ) ;
F_78 ( L_26 , & V_259 -> V_261 , V_179 ) ;
return V_179 ;
}
static bool F_161 ( void )
{
return ! ! ( F_99 ( F_103 () + V_212 ) & V_278 ) ;
}
int F_162 ( void )
{
if ( ! F_163 ( & V_277 ) ) {
if ( ! F_161 () ) {
F_67 ( L_27 , F_106 () ) ;
return - V_166 ;
}
F_102 () ;
F_112 () ;
}
return 0 ;
}
static int T_7 F_164 ( struct V_208 * V_279 )
{
struct V_208 * V_280 ;
struct V_258 V_259 ;
for ( V_280 = F_165 ( V_279 , V_281 ) ; V_280 ;
V_280 = F_165 ( V_280 , V_281 ) ) {
if ( ! F_166 ( V_280 , L_28 ) ) {
F_92 ( L_29 ,
V_280 -> V_282 ) ;
continue;
}
if ( F_167 ( V_280 , 0 , & V_259 ) ) {
F_92 ( L_30 , V_280 -> V_282 ) ;
continue;
}
F_153 ( & V_259 , & V_280 -> V_234 , F_115 ( V_280 ) ) ;
}
return 0 ;
}
static int T_7 F_168 ( struct V_283 * V_284 ,
const unsigned long V_285 )
{
struct V_286 * V_287 ;
struct V_247 * V_288 ;
struct V_258 V_259 ;
int V_179 ;
V_287 = (struct V_286 * ) V_284 ;
memset ( & V_259 , 0 , sizeof( V_259 ) ) ;
V_259 . V_261 = V_287 -> V_289 ;
V_259 . V_285 = V_287 -> V_289 + V_290 - 1 ;
V_259 . V_60 = V_291 ;
V_288 = F_169 ( ( void * ) V_287 -> V_289 ) ;
if ( ! V_288 ) {
F_78 ( L_31 ,
& V_259 . V_261 ) ;
return - V_115 ;
}
V_179 = F_170 ( V_287 -> V_292 , V_288 ) ;
if ( V_179 ) {
F_78 ( L_32 ,
& V_259 . V_261 , V_287 -> V_292 ) ;
goto V_293;
}
V_179 = F_153 ( & V_259 , V_288 , V_210 ) ;
if ( ! V_179 )
return 0 ;
F_171 ( V_287 -> V_292 ) ;
V_293:
F_172 ( V_288 ) ;
return V_179 ;
}
static void T_7 F_173 ( void )
{
F_174 ( V_294 ,
F_168 , 0 ) ;
}
static void T_7 F_173 ( void ) { }
int T_7 F_175 ( struct V_247 * V_248 , struct V_295 * V_295 ,
struct V_221 * V_296 )
{
struct V_208 * V_297 ;
V_251 = V_296 ;
V_297 = F_176 ( V_248 ) ;
if ( V_297 )
F_164 ( V_297 ) ;
else
F_173 () ;
if ( F_163 ( & V_277 ) ) {
F_92 ( L_33 ) ;
return - V_166 ;
}
V_83 = V_295 ;
F_80 () ;
F_64 ( V_295 -> V_111 ) ;
return 0 ;
}
