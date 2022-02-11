static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
return V_6 -> V_7 + V_3 -> V_8 . V_9 [ V_4 ] ;
}
static void F_2 ( struct V_10 * V_11 , T_2 V_12 )
{
V_11 -> V_13 [ 0 ] &= ~ 0xffUL ;
V_11 -> V_13 [ 0 ] |= V_12 ;
}
static void F_3 ( struct V_10 * V_11 , T_1 V_14 )
{
V_11 -> V_13 [ 0 ] &= F_4 ( 32 ) - 1 ;
V_11 -> V_13 [ 0 ] |= ( ( V_15 ) V_14 ) << 32 ;
}
static void F_5 ( struct V_10 * V_11 , T_1 V_16 )
{
V_11 -> V_13 [ 1 ] &= ~ 0xffffffffUL ;
V_11 -> V_13 [ 1 ] |= V_16 ;
}
static void F_6 ( struct V_10 * V_11 , T_1 V_17 )
{
V_11 -> V_13 [ 1 ] &= 0xffffffffUL ;
V_11 -> V_13 [ 1 ] |= ( ( V_15 ) V_17 ) << 32 ;
}
static void F_7 ( struct V_10 * V_11 , T_2 V_18 )
{
V_11 -> V_13 [ 1 ] &= ~ 0x1fUL ;
V_11 -> V_13 [ 1 ] |= V_18 & 0x1f ;
}
static void F_8 ( struct V_10 * V_11 , V_15 V_19 )
{
V_11 -> V_13 [ 2 ] &= ~ 0xffffffffffffUL ;
V_11 -> V_13 [ 2 ] |= V_19 & 0xffffffffff00UL ;
}
static void F_9 ( struct V_10 * V_11 , int V_20 )
{
V_11 -> V_13 [ 2 ] &= ~ ( 1UL << 63 ) ;
V_11 -> V_13 [ 2 ] |= ( ( V_15 ) ! ! V_20 ) << 63 ;
}
static void F_10 ( struct V_10 * V_11 , V_15 V_21 )
{
V_11 -> V_13 [ 2 ] &= ~ ( 0xffffffffUL << 16 ) ;
V_11 -> V_13 [ 2 ] |= ( V_21 & ( 0xffffffffUL << 16 ) ) ;
}
static void F_11 ( struct V_10 * V_11 , T_3 V_22 )
{
V_11 -> V_13 [ 2 ] &= ~ 0xffffUL ;
V_11 -> V_13 [ 2 ] |= V_22 ;
}
static inline void F_12 ( struct V_10 * V_11 )
{
V_11 -> V_13 [ 0 ] = F_13 ( V_11 -> V_13 [ 0 ] ) ;
V_11 -> V_13 [ 1 ] = F_13 ( V_11 -> V_13 [ 1 ] ) ;
V_11 -> V_13 [ 2 ] = F_13 ( V_11 -> V_13 [ 2 ] ) ;
V_11 -> V_13 [ 3 ] = F_13 ( V_11 -> V_13 [ 3 ] ) ;
}
static struct V_1 * F_14 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
unsigned long V_19 ;
T_2 V_18 = F_15 ( V_24 -> V_25 . V_26 -> V_27 ) ;
V_19 = F_16 ( V_24 -> V_25 . V_26 -> V_28 ) ;
V_19 = F_17 ( V_19 , V_29 ) ;
F_2 ( V_11 , V_30 ) ;
F_3 ( V_11 , V_24 -> V_25 . V_26 -> V_31 ) ;
F_7 ( V_11 , V_18 - 1 ) ;
F_8 ( V_11 , V_19 ) ;
F_9 ( V_11 , V_24 -> V_25 . V_20 ) ;
F_12 ( V_11 ) ;
return NULL ;
}
static struct V_1 * F_18 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
F_2 ( V_11 , V_32 ) ;
F_11 ( V_11 , V_24 -> V_33 . V_22 -> V_34 ) ;
F_10 ( V_11 , V_24 -> V_33 . V_22 -> V_35 ) ;
F_9 ( V_11 , V_24 -> V_33 . V_20 ) ;
F_12 ( V_11 ) ;
return V_24 -> V_33 . V_22 ;
}
static struct V_1 * F_19 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_1 * V_22 ;
V_22 = F_1 ( V_24 -> V_36 . V_26 ,
V_24 -> V_36 . V_37 ) ;
F_2 ( V_11 , V_38 ) ;
F_3 ( V_11 , V_24 -> V_36 . V_26 -> V_31 ) ;
F_5 ( V_11 , V_24 -> V_36 . V_37 ) ;
F_6 ( V_11 , V_24 -> V_36 . V_17 ) ;
F_11 ( V_11 , V_22 -> V_34 ) ;
F_12 ( V_11 ) ;
return V_22 ;
}
static struct V_1 * F_20 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_1 * V_22 ;
V_22 = F_1 ( V_24 -> V_39 . V_26 ,
V_24 -> V_39 . V_37 ) ;
F_2 ( V_11 , V_40 ) ;
F_3 ( V_11 , V_24 -> V_39 . V_26 -> V_31 ) ;
F_5 ( V_11 , V_24 -> V_39 . V_37 ) ;
F_11 ( V_11 , V_24 -> V_39 . V_22 -> V_34 ) ;
F_12 ( V_11 ) ;
return V_22 ;
}
static struct V_1 * F_21 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_1 * V_22 ;
V_22 = F_1 ( V_24 -> V_41 . V_26 ,
V_24 -> V_41 . V_37 ) ;
F_2 ( V_11 , V_42 ) ;
F_3 ( V_11 , V_24 -> V_41 . V_26 -> V_31 ) ;
F_5 ( V_11 , V_24 -> V_41 . V_37 ) ;
F_12 ( V_11 ) ;
return V_22 ;
}
static struct V_1 * F_22 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_1 * V_22 ;
V_22 = F_1 ( V_24 -> V_43 . V_26 ,
V_24 -> V_43 . V_37 ) ;
F_2 ( V_11 , V_44 ) ;
F_3 ( V_11 , V_24 -> V_43 . V_26 -> V_31 ) ;
F_5 ( V_11 , V_24 -> V_43 . V_37 ) ;
F_12 ( V_11 ) ;
return V_22 ;
}
static struct V_1 * F_23 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
F_2 ( V_11 , V_45 ) ;
F_11 ( V_11 , V_24 -> V_33 . V_22 -> V_34 ) ;
F_12 ( V_11 ) ;
return NULL ;
}
static V_15 F_24 ( struct V_5 * V_6 ,
struct V_10 * V_46 )
{
return ( V_46 - V_6 -> V_47 ) * sizeof( * V_46 ) ;
}
static int F_25 ( struct V_5 * V_6 )
{
int V_48 ;
int V_49 ;
V_48 = V_6 -> V_50 - V_6 -> V_47 ;
V_49 = F_26 ( V_6 -> V_51 + V_52 ) / sizeof( struct V_10 ) ;
if ( ( ( V_48 + 1 ) % V_53 ) == V_49 )
return 1 ;
return 0 ;
}
static struct V_10 * F_27 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
T_1 V_54 = 1000000 ;
while ( F_25 ( V_6 ) ) {
V_54 -- ;
if ( ! V_54 ) {
F_28 ( L_1 ) ;
return NULL ;
}
F_29 () ;
F_30 ( 1 ) ;
}
V_11 = V_6 -> V_50 ++ ;
if ( V_6 -> V_50 == ( V_6 -> V_47 + V_53 ) )
V_6 -> V_50 = V_6 -> V_47 ;
return V_11 ;
}
static struct V_10 * F_31 ( struct V_5 * V_6 )
{
V_15 V_55 = F_24 ( V_6 , V_6 -> V_50 ) ;
F_32 ( V_55 , V_6 -> V_51 + V_56 ) ;
return V_6 -> V_50 ;
}
static void F_33 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
if ( V_6 -> V_57 & V_58 )
F_34 ( V_11 , sizeof( * V_11 ) ) ;
else
F_35 ( V_59 ) ;
}
static void F_36 ( struct V_5 * V_6 ,
struct V_10 * V_60 ,
struct V_10 * V_61 )
{
V_15 V_62 , V_63 , V_64 ;
T_1 V_54 = 1000000 ;
V_63 = F_24 ( V_6 , V_60 ) ;
V_64 = F_24 ( V_6 , V_61 ) ;
while ( 1 ) {
V_62 = F_26 ( V_6 -> V_51 + V_52 ) ;
if ( V_62 >= V_64 || V_62 < V_63 )
break;
V_54 -- ;
if ( ! V_54 ) {
F_28 ( L_2 ) ;
return;
}
F_29 () ;
F_30 ( 1 ) ;
}
}
static void F_37 ( struct V_5 * V_6 ,
T_4 V_65 ,
struct V_23 * V_24 )
{
struct V_10 * V_11 , * V_66 , * V_67 ;
struct V_1 * V_68 ;
unsigned long V_57 ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
V_11 = F_27 ( V_6 ) ;
if ( ! V_11 ) {
F_28 ( L_3 ) ;
F_39 ( & V_6 -> V_69 , V_57 ) ;
return;
}
V_68 = V_65 ( V_11 , V_24 ) ;
F_33 ( V_6 , V_11 ) ;
if ( V_68 ) {
V_66 = F_27 ( V_6 ) ;
if ( ! V_66 ) {
F_28 ( L_4 ) ;
goto V_70;
}
F_2 ( V_66 , V_71 ) ;
F_10 ( V_66 , V_68 -> V_35 ) ;
F_12 ( V_66 ) ;
F_33 ( V_6 , V_66 ) ;
}
V_70:
V_67 = F_31 ( V_6 ) ;
F_39 ( & V_6 -> V_69 , V_57 ) ;
F_36 ( V_6 , V_11 , V_67 ) ;
}
static void F_40 ( struct V_2 * V_26 , T_1 V_37 )
{
struct V_23 V_24 ;
V_24 . V_43 . V_26 = V_26 ;
V_24 . V_43 . V_37 = V_37 ;
F_37 ( V_26 -> V_6 , F_22 , & V_24 ) ;
}
static void F_41 ( struct V_2 * V_26 , int V_20 )
{
struct V_23 V_24 ;
V_24 . V_25 . V_26 = V_26 ;
V_24 . V_25 . V_20 = ! ! V_20 ;
F_37 ( V_26 -> V_6 , F_14 , & V_24 ) ;
}
static void F_42 ( struct V_5 * V_6 , struct V_1 * V_22 ,
int V_20 )
{
struct V_23 V_24 ;
V_24 . V_33 . V_22 = V_22 ;
V_24 . V_33 . V_20 = ! ! V_20 ;
F_37 ( V_6 , F_18 , & V_24 ) ;
}
static void F_43 ( struct V_2 * V_26 , T_1 V_72 , T_1 V_16 )
{
struct V_23 V_24 ;
V_24 . V_36 . V_26 = V_26 ;
V_24 . V_36 . V_17 = V_72 ;
V_24 . V_36 . V_37 = V_16 ;
F_37 ( V_26 -> V_6 , F_19 , & V_24 ) ;
}
static void F_44 ( struct V_2 * V_26 ,
struct V_1 * V_22 , T_1 V_16 )
{
struct V_23 V_24 ;
V_24 . V_39 . V_26 = V_26 ;
V_24 . V_39 . V_22 = V_22 ;
V_24 . V_39 . V_37 = V_16 ;
F_37 ( V_26 -> V_6 , F_20 , & V_24 ) ;
}
static void F_45 ( struct V_2 * V_26 , T_1 V_16 )
{
struct V_23 V_24 ;
V_24 . V_41 . V_26 = V_26 ;
V_24 . V_41 . V_37 = V_16 ;
F_37 ( V_26 -> V_6 , F_21 , & V_24 ) ;
}
static void F_46 ( struct V_5 * V_6 , struct V_1 * V_22 )
{
struct V_23 V_24 ;
V_24 . V_73 . V_22 = V_22 ;
F_37 ( V_6 , F_23 , & V_24 ) ;
}
static inline T_1 F_47 ( struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
return V_75 -> V_76 - V_3 -> V_8 . V_77 ;
}
static void F_49 ( struct V_74 * V_75 , bool V_78 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_5 V_76 = V_75 -> V_76 ;
T_1 V_16 = F_47 ( V_75 ) ;
T_2 * V_79 = F_50 ( V_80 -> V_81 ) + V_76 - 8192 ;
if ( V_78 )
* V_79 |= V_82 ;
else
* V_79 &= ~ V_82 ;
if ( V_80 -> V_57 & V_83 )
F_34 ( V_79 , sizeof( * V_79 ) ) ;
else
F_35 ( V_59 ) ;
F_40 ( V_3 , V_16 ) ;
}
static void F_51 ( struct V_74 * V_75 )
{
F_49 ( V_75 , false ) ;
}
static void F_52 ( struct V_74 * V_75 )
{
F_49 ( V_75 , true ) ;
}
static int F_53 ( struct V_74 * V_75 , const struct V_84 * V_85 ,
bool V_86 )
{
unsigned int V_87 ;
const struct V_84 * V_88 = V_89 ;
struct V_2 * V_3 = F_48 ( V_75 ) ;
struct V_1 * V_90 ;
T_1 V_16 = F_47 ( V_75 ) ;
if ( V_3 -> V_6 -> V_57 & V_91 ) {
if ( V_3 -> V_6 -> V_92 >= 0 ) {
V_88 = F_54 ( V_3 -> V_6 -> V_92 ) ;
if ( ! F_55 ( V_85 , V_88 ) )
return - V_93 ;
}
}
V_87 = F_56 ( V_85 , V_88 ) ;
if ( V_87 >= V_94 )
return - V_93 ;
V_90 = & V_3 -> V_6 -> V_7 [ V_87 ] ;
F_44 ( V_3 , V_90 , V_16 ) ;
V_3 -> V_8 . V_9 [ V_16 ] = V_87 ;
return V_95 ;
}
static void F_57 ( struct V_74 * V_75 , struct V_96 * V_97 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
struct V_5 * V_6 ;
V_15 V_98 ;
V_6 = V_3 -> V_6 ;
V_98 = V_6 -> V_99 + V_100 ;
V_97 -> V_101 = V_98 & ( ( 1UL << 32 ) - 1 ) ;
V_97 -> V_102 = V_98 >> 32 ;
V_97 -> V_103 = F_47 ( V_75 ) ;
}
static int F_58 ( int V_104 )
{
return ( V_104 - 8192 ) >> V_105 ;
}
static int F_59 ( int V_106 )
{
return ( V_106 << V_105 ) + 8192 ;
}
static int T_6 F_60 ( T_1 V_107 )
{
V_108 = F_58 ( 1UL << V_107 ) ;
V_109 = F_61 ( F_62 ( V_108 ) * sizeof( long ) ,
V_110 ) ;
if ( ! V_109 ) {
V_108 = 0 ;
return - V_111 ;
}
F_63 ( L_5 , ( int ) V_108 ) ;
return 0 ;
}
static unsigned long * F_64 ( int V_112 , int * V_51 , int * V_113 )
{
unsigned long * V_114 = NULL ;
int V_115 ;
int V_116 ;
int V_117 ;
V_116 = F_65 ( V_112 , V_118 ) ;
F_66 ( & V_119 ) ;
do {
V_115 = F_67 ( V_109 , V_108 ,
0 , V_116 , 0 ) ;
if ( V_115 < V_108 )
break;
V_116 -- ;
} while ( V_116 > 0 );
if ( ! V_116 )
goto V_120;
V_114 = F_61 ( F_62 ( V_116 * V_118 ) * sizeof ( long ) ,
V_121 ) ;
if ( ! V_114 )
goto V_120;
for ( V_117 = 0 ; V_117 < V_116 ; V_117 ++ )
F_68 ( V_115 + V_117 , V_109 ) ;
* V_51 = F_59 ( V_115 ) ;
* V_113 = V_116 * V_118 ;
V_120:
F_69 ( & V_119 ) ;
if ( ! V_114 )
* V_51 = * V_113 = 0 ;
return V_114 ;
}
static void F_70 ( struct V_122 * V_123 )
{
int V_51 = V_123 -> V_77 ;
int V_113 = V_123 -> V_124 ;
int V_104 ;
F_66 ( & V_119 ) ;
for ( V_104 = V_51 ; V_104 < ( V_51 + V_113 ) ; V_104 += V_118 ) {
int V_106 = F_58 ( V_104 ) ;
F_71 ( V_106 > V_108 ) ;
if ( F_72 ( V_106 , V_109 ) ) {
F_73 ( V_106 , V_109 ) ;
} else {
F_74 ( L_6 , V_106 ) ;
}
}
F_69 ( & V_119 ) ;
F_75 ( V_123 -> V_125 ) ;
F_75 ( V_123 -> V_9 ) ;
}
static int T_6 F_76 ( void )
{
T_7 V_126 ;
V_80 -> V_81 = F_77 ( V_127 ,
F_78 ( V_128 ) ) ;
if ( ! V_80 -> V_81 ) {
F_74 ( L_7 ) ;
return - V_111 ;
}
V_126 = F_79 ( V_80 -> V_81 ) ;
F_63 ( L_8 , & V_126 ) ;
memset ( F_50 ( V_80 -> V_81 ) ,
V_129 | V_130 ,
V_128 ) ;
F_34 ( F_50 ( V_80 -> V_81 ) , V_128 ) ;
return 0 ;
}
static void F_80 ( struct V_5 * V_6 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_131 ; V_117 ++ ) {
if ( V_6 -> V_132 [ V_117 ] . V_51 ) {
F_81 ( ( unsigned long ) V_6 -> V_132 [ V_117 ] . V_51 ,
V_6 -> V_132 [ V_117 ] . V_133 ) ;
V_6 -> V_132 [ V_117 ] . V_51 = NULL ;
}
}
}
static int F_82 ( const char * V_134 , struct V_5 * V_6 )
{
int V_135 ;
int V_117 ;
int V_136 = V_137 ;
V_15 V_138 = V_139 ;
V_15 V_140 ;
V_15 V_141 ;
T_1 V_142 ;
if ( V_6 -> V_57 & V_143 ) {
V_140 = 0 ;
V_142 = 0x14 ;
} else {
V_140 = V_144 ;
V_141 = F_83 ( V_6 -> V_51 + V_145 ) ;
V_142 = F_84 ( V_141 ) ;
}
V_6 -> V_146 = V_142 ;
for ( V_117 = 0 ; V_117 < V_131 ; V_117 ++ ) {
V_15 V_147 = F_83 ( V_6 -> V_51 + V_148 + V_117 * 8 ) ;
V_15 type = F_85 ( V_147 ) ;
V_15 V_149 = F_86 ( V_147 ) ;
int V_133 = F_78 ( V_136 ) ;
int F_77 ;
V_15 V_150 ;
void * V_51 ;
if ( type == V_151 )
continue;
if ( type == V_152 ) {
V_133 = F_87 ( F_78 ( ( 1UL << V_142 ) * V_149 ) ,
V_133 ) ;
if ( V_133 >= V_153 ) {
V_133 = V_153 - 1 ;
F_88 ( L_9 ,
V_134 , V_133 ) ;
}
}
V_154:
F_77 = ( F_89 ( V_133 ) / V_136 ) ;
if ( F_77 > V_155 ) {
F_77 = V_155 ;
V_133 = F_78 ( V_155 * V_136 ) ;
F_88 ( L_10 ,
V_134 , V_133 , F_77 ) ;
}
V_51 = ( void * ) F_90 ( V_110 | V_156 , V_133 ) ;
if ( ! V_51 ) {
V_135 = - V_111 ;
goto V_157;
}
V_6 -> V_132 [ V_117 ] . V_51 = V_51 ;
V_6 -> V_132 [ V_117 ] . V_133 = V_133 ;
V_158:
V_147 = ( F_16 ( V_51 ) |
( type << V_159 ) |
( ( V_149 - 1 ) << V_160 ) |
V_140 |
V_138 |
V_161 ) ;
switch ( V_136 ) {
case V_162 :
V_147 |= V_163 ;
break;
case V_164 :
V_147 |= V_165 ;
break;
case V_137 :
V_147 |= V_166 ;
break;
}
V_147 |= F_77 - 1 ;
V_6 -> V_132 [ V_117 ] . V_147 = V_147 ;
F_91 ( V_147 , V_6 -> V_51 + V_148 + V_117 * 8 ) ;
V_150 = F_83 ( V_6 -> V_51 + V_148 + V_117 * 8 ) ;
if ( ( V_147 ^ V_150 ) & V_167 ) {
V_138 = V_150 & V_167 ;
if ( ! V_138 ) {
V_140 = V_168 ;
F_34 ( V_51 , F_89 ( V_133 ) ) ;
}
goto V_158;
}
if ( ( V_147 ^ V_150 ) & V_169 ) {
F_81 ( ( unsigned long ) V_51 , V_133 ) ;
V_6 -> V_132 [ V_117 ] . V_51 = NULL ;
switch ( V_136 ) {
case V_164 :
V_136 = V_162 ;
goto V_154;
case V_137 :
V_136 = V_164 ;
goto V_154;
}
}
if ( V_147 != V_150 ) {
F_74 ( L_11 ,
V_134 , V_117 ,
( unsigned long ) V_147 , ( unsigned long ) V_150 ) ;
V_135 = - V_170 ;
goto V_157;
}
F_63 ( L_12 ,
( int ) ( F_89 ( V_133 ) / V_149 ) ,
V_171 [ type ] ,
( unsigned long ) F_16 ( V_51 ) ,
V_136 / V_172 , ( int ) V_138 >> V_173 ) ;
}
return 0 ;
V_157:
F_80 ( V_6 ) ;
return V_135 ;
}
static int F_92 ( struct V_5 * V_6 )
{
V_6 -> V_7 = F_61 ( V_94 * sizeof( * V_6 -> V_7 ) ,
V_110 ) ;
if ( ! V_6 -> V_7 )
return - V_111 ;
return 0 ;
}
static void F_93 ( void )
{
void T_8 * V_174 = F_94 () ;
struct V_175 * V_176 ;
V_15 V_147 , V_150 ;
V_176 = F_95 () -> V_176 ;
if ( ! V_176 ) {
T_7 V_126 ;
V_176 = F_77 ( V_127 | V_156 ,
F_78 ( F_87 ( V_177 , V_137 ) ) ) ;
if ( ! V_176 ) {
F_74 ( L_13 ,
F_96 () ) ;
return;
}
F_34 ( F_50 ( V_176 ) , V_177 ) ;
V_126 = F_79 ( V_176 ) ;
F_63 ( L_14 ,
F_96 () , & V_126 ) ;
F_95 () -> V_176 = V_176 ;
}
V_147 = F_26 ( V_174 + V_178 ) ;
V_147 &= ~ V_179 ;
F_32 ( V_147 , V_174 + V_178 ) ;
F_35 ( V_180 ) ;
V_147 = ( F_79 ( V_80 -> V_81 ) |
V_181 |
V_182 |
( ( V_183 - 1 ) & V_184 ) ) ;
F_91 ( V_147 , V_174 + V_185 ) ;
V_150 = F_83 ( V_174 + V_185 ) ;
if ( ( V_150 ^ V_147 ) & V_186 ) {
if ( ! ( V_150 & V_186 ) ) {
V_147 &= ~ ( V_186 |
V_187 ) ;
V_147 |= V_188 ;
F_91 ( V_147 , V_174 + V_185 ) ;
}
F_97 ( L_15 ) ;
V_80 -> V_57 |= V_83 ;
}
V_147 = ( F_79 ( V_176 ) |
V_189 |
V_190 ) ;
F_91 ( V_147 , V_174 + V_191 ) ;
V_150 = F_83 ( V_174 + V_191 ) ;
if ( ! ( V_150 & V_192 ) ) {
V_147 &= ~ ( V_192 |
V_193 ) ;
V_147 |= V_194 ;
F_91 ( V_147 , V_174 + V_191 ) ;
}
V_147 = F_26 ( V_174 + V_178 ) ;
V_147 |= V_179 ;
F_32 ( V_147 , V_174 + V_178 ) ;
F_35 ( V_180 ) ;
}
static void F_98 ( void )
{
struct V_5 * V_6 ;
int V_87 ;
F_66 ( & V_195 ) ;
V_87 = F_96 () ;
F_99 (its, &its_nodes, entry) {
V_15 V_196 ;
if ( V_6 -> V_57 & V_91 ) {
struct V_197 * V_198 ;
V_198 = F_100 ( V_87 , NULL ) ;
if ( V_6 -> V_92 != V_199 &&
V_6 -> V_92 != F_101 ( V_198 ) )
continue;
}
if ( F_83 ( V_6 -> V_51 + V_145 ) & V_200 ) {
V_196 = F_95 () -> V_99 ;
} else {
V_196 = F_83 ( F_94 () + V_201 ) ;
V_196 = F_102 ( V_196 ) << 16 ;
}
V_6 -> V_7 [ V_87 ] . V_35 = V_196 ;
V_6 -> V_7 [ V_87 ] . V_34 = V_87 ;
F_42 ( V_6 , & V_6 -> V_7 [ V_87 ] , 1 ) ;
F_46 ( V_6 , & V_6 -> V_7 [ V_87 ] ) ;
}
F_69 ( & V_195 ) ;
}
static struct V_2 * F_103 ( struct V_5 * V_6 , T_1 V_202 )
{
struct V_2 * V_3 = NULL , * V_150 ;
unsigned long V_57 ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_99 (tmp, &its->its_device_list, entry) {
if ( V_150 -> V_31 == V_202 ) {
V_3 = V_150 ;
break;
}
}
F_39 ( & V_6 -> V_69 , V_57 ) ;
return V_3 ;
}
static struct V_203 * F_104 ( struct V_5 * V_6 , T_1 type )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_131 ; V_117 ++ ) {
if ( F_85 ( V_6 -> V_132 [ V_117 ] . V_147 ) == type )
return & V_6 -> V_132 [ V_117 ] ;
}
return NULL ;
}
static struct V_2 * F_105 ( struct V_5 * V_6 , T_1 V_202 ,
int V_204 )
{
struct V_203 * V_205 ;
struct V_2 * V_26 ;
unsigned long * V_125 ;
unsigned long V_57 ;
T_3 * V_9 = NULL ;
void * V_28 ;
int V_77 ;
int V_124 ;
int V_27 ;
int V_206 ;
V_205 = F_104 ( V_6 , V_152 ) ;
if ( V_205 ) {
if ( V_202 >= ( F_89 ( V_205 -> V_133 ) /
F_86 ( V_205 -> V_147 ) ) )
return NULL ;
} else if ( F_15 ( V_202 ) >= V_6 -> V_146 )
return NULL ;
V_26 = F_61 ( sizeof( * V_26 ) , V_110 ) ;
V_27 = F_87 ( 2UL , F_106 ( V_204 ) ) ;
V_206 = V_27 * V_6 -> V_207 ;
V_206 = F_87 ( V_206 , V_29 ) + V_29 - 1 ;
V_28 = F_61 ( V_206 , V_110 ) ;
V_125 = F_64 ( V_204 , & V_77 , & V_124 ) ;
if ( V_125 )
V_9 = F_61 ( sizeof( * V_9 ) * V_124 , V_110 ) ;
if ( ! V_26 || ! V_28 || ! V_125 || ! V_9 ) {
F_75 ( V_26 ) ;
F_75 ( V_28 ) ;
F_75 ( V_125 ) ;
F_75 ( V_9 ) ;
return NULL ;
}
F_34 ( V_28 , V_206 ) ;
V_26 -> V_6 = V_6 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_8 . V_125 = V_125 ;
V_26 -> V_8 . V_9 = V_9 ;
V_26 -> V_8 . V_77 = V_77 ;
V_26 -> V_8 . V_124 = V_124 ;
V_26 -> V_31 = V_202 ;
F_107 ( & V_26 -> V_208 ) ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_108 ( & V_26 -> V_208 , & V_6 -> V_209 ) ;
F_39 ( & V_6 -> V_69 , V_57 ) ;
F_41 ( V_26 , 1 ) ;
return V_26 ;
}
static void F_109 ( struct V_2 * V_3 )
{
unsigned long V_57 ;
F_38 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_110 ( & V_3 -> V_208 ) ;
F_39 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_75 ( V_3 -> V_28 ) ;
F_75 ( V_3 ) ;
}
static int F_111 ( struct V_2 * V_26 , T_5 * V_76 )
{
int V_210 ;
V_210 = F_112 ( V_26 -> V_8 . V_125 ,
V_26 -> V_8 . V_124 ) ;
if ( V_210 == V_26 -> V_8 . V_124 )
return - V_211 ;
* V_76 = V_26 -> V_8 . V_77 + V_210 ;
F_68 ( V_210 , V_26 -> V_8 . V_125 ) ;
return 0 ;
}
static int F_113 ( struct V_212 * V_213 , struct V_214 * V_26 ,
int V_215 , T_9 * V_216 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_217 * V_218 ;
T_1 V_202 ;
V_202 = V_216 -> V_219 [ 0 ] . V_220 ;
V_218 = F_114 ( V_213 ) ;
V_6 = V_218 -> V_103 ;
V_3 = F_103 ( V_6 , V_202 ) ;
if ( V_3 ) {
F_115 ( L_16 , V_202 ) ;
goto V_120;
}
V_3 = F_105 ( V_6 , V_202 , V_215 ) ;
if ( ! V_3 )
return - V_111 ;
F_115 ( L_17 , V_215 , F_15 ( V_215 ) ) ;
V_120:
V_216 -> V_219 [ 0 ] . V_46 = V_3 ;
return 0 ;
}
static int F_116 ( struct V_212 * V_213 ,
unsigned int V_221 ,
T_5 V_76 )
{
struct V_222 V_223 ;
if ( F_117 ( V_213 -> V_224 ) ) {
V_223 . V_225 = V_213 -> V_224 -> V_225 ;
V_223 . V_226 = 3 ;
V_223 . V_227 [ 0 ] = V_228 ;
V_223 . V_227 [ 1 ] = V_76 ;
V_223 . V_227 [ 2 ] = V_229 ;
} else {
return - V_93 ;
}
return F_118 ( V_213 , V_221 , 1 , & V_223 ) ;
}
static int F_119 ( struct V_212 * V_213 , unsigned int V_221 ,
unsigned int V_112 , void * args )
{
T_9 * V_216 = args ;
struct V_2 * V_3 = V_216 -> V_219 [ 0 ] . V_46 ;
T_5 V_76 ;
int V_135 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_112 ; V_117 ++ ) {
V_135 = F_111 ( V_3 , & V_76 ) ;
if ( V_135 )
return V_135 ;
V_135 = F_116 ( V_213 , V_221 + V_117 , V_76 ) ;
if ( V_135 )
return V_135 ;
F_120 ( V_213 , V_221 + V_117 ,
V_76 , & V_230 , V_3 ) ;
F_115 ( L_18 ,
( int ) ( V_76 - V_3 -> V_8 . V_77 ) ,
( int ) V_76 , V_221 + V_117 ) ;
}
return 0 ;
}
static void F_121 ( struct V_212 * V_213 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
const struct V_84 * V_88 = V_89 ;
if ( V_3 -> V_6 -> V_92 >= 0 )
V_88 = F_54 ( V_3 -> V_6 -> V_92 ) ;
V_3 -> V_8 . V_9 [ V_4 ] = F_122 ( V_88 ) ;
F_43 ( V_3 , V_75 -> V_76 , V_4 ) ;
}
static void F_123 ( struct V_212 * V_213 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
F_45 ( V_3 , V_4 ) ;
}
static void F_124 ( struct V_212 * V_213 , unsigned int V_221 ,
unsigned int V_112 )
{
struct V_74 * V_75 = F_125 ( V_213 , V_221 ) ;
struct V_2 * V_3 = F_48 ( V_75 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_112 ; V_117 ++ ) {
struct V_74 * V_103 = F_125 ( V_213 ,
V_221 + V_117 ) ;
T_1 V_4 = F_47 ( V_103 ) ;
F_73 ( V_4 , V_3 -> V_8 . V_125 ) ;
F_126 ( V_103 ) ;
}
if ( F_127 ( V_3 -> V_8 . V_125 ,
V_3 -> V_8 . V_124 ) ) {
F_70 ( & V_3 -> V_8 ) ;
F_41 ( V_3 , 0 ) ;
F_109 ( V_3 ) ;
}
F_128 ( V_213 , V_221 , V_112 ) ;
}
static int F_129 ( void T_8 * V_51 )
{
T_1 V_54 = 1000000 ;
T_1 V_147 ;
V_147 = F_26 ( V_51 + V_231 ) ;
if ( V_147 & V_232 )
return 0 ;
V_147 &= ~ V_233 ;
F_32 ( V_147 , V_51 + V_231 ) ;
while ( 1 ) {
V_147 = F_26 ( V_51 + V_231 ) ;
if ( V_147 & V_232 )
return 0 ;
V_54 -- ;
if ( ! V_54 )
return - V_234 ;
F_29 () ;
F_30 ( 1 ) ;
}
}
static void T_10 F_130 ( void * V_103 )
{
struct V_5 * V_6 = V_103 ;
V_6 -> V_57 |= V_143 ;
}
static void T_10 F_131 ( void * V_103 )
{
struct V_5 * V_6 = V_103 ;
V_6 -> V_57 |= V_91 ;
}
static void F_132 ( struct V_5 * V_6 )
{
T_1 V_235 = F_26 ( V_6 -> V_51 + V_236 ) ;
F_133 ( V_235 , V_237 , V_6 ) ;
}
static int T_6 F_134 ( struct V_197 * V_238 ,
struct V_212 * V_224 )
{
struct V_239 V_240 ;
struct V_5 * V_6 ;
void T_8 * V_241 ;
struct V_212 * V_242 ;
T_1 V_147 ;
V_15 V_205 , V_150 ;
int V_135 ;
V_135 = F_135 ( V_238 , 0 , & V_240 ) ;
if ( V_135 ) {
F_88 ( L_19 , V_238 -> V_243 ) ;
return - V_170 ;
}
V_241 = F_136 ( V_240 . V_244 , F_137 ( & V_240 ) ) ;
if ( ! V_241 ) {
F_88 ( L_20 , V_238 -> V_243 ) ;
return - V_111 ;
}
V_147 = F_26 ( V_241 + V_245 ) & V_246 ;
if ( V_147 != 0x30 && V_147 != 0x40 ) {
F_88 ( L_21 , V_238 -> V_243 ) ;
V_135 = - V_247 ;
goto V_248;
}
V_135 = F_129 ( V_241 ) ;
if ( V_135 ) {
F_88 ( L_22 ,
V_238 -> V_243 ) ;
goto V_248;
}
F_63 ( L_23 , V_238 -> V_243 ) ;
V_6 = F_61 ( sizeof( * V_6 ) , V_110 ) ;
if ( ! V_6 ) {
V_135 = - V_111 ;
goto V_248;
}
F_138 ( & V_6 -> V_69 ) ;
F_107 ( & V_6 -> V_208 ) ;
F_107 ( & V_6 -> V_209 ) ;
V_6 -> V_51 = V_241 ;
V_6 -> V_99 = V_240 . V_244 ;
V_6 -> V_207 = ( ( F_26 ( V_241 + V_145 ) >> 4 ) & 0xf ) + 1 ;
V_6 -> V_92 = F_101 ( V_238 ) ;
V_6 -> V_47 = F_61 ( V_249 , V_110 ) ;
if ( ! V_6 -> V_47 ) {
V_135 = - V_111 ;
goto V_250;
}
V_6 -> V_50 = V_6 -> V_47 ;
F_132 ( V_6 ) ;
V_135 = F_82 ( V_238 -> V_243 , V_6 ) ;
if ( V_135 )
goto V_251;
V_135 = F_92 ( V_6 ) ;
if ( V_135 )
goto V_252;
V_205 = ( F_16 ( V_6 -> V_47 ) |
V_253 |
V_254 |
( V_249 / V_162 - 1 ) |
V_255 ) ;
F_91 ( V_205 , V_6 -> V_51 + V_256 ) ;
V_150 = F_83 ( V_6 -> V_51 + V_256 ) ;
if ( ( V_150 ^ V_205 ) & V_257 ) {
if ( ! ( V_150 & V_257 ) ) {
V_205 &= ~ ( V_257 |
V_258 ) ;
V_205 |= V_259 ;
F_91 ( V_205 , V_6 -> V_51 + V_256 ) ;
}
F_63 ( L_24 ) ;
V_6 -> V_57 |= V_58 ;
}
F_91 ( 0 , V_6 -> V_51 + V_56 ) ;
F_32 ( V_233 , V_6 -> V_51 + V_231 ) ;
if ( F_139 ( V_238 , L_25 ) ) {
struct V_217 * V_216 ;
V_216 = F_61 ( sizeof( * V_216 ) , V_110 ) ;
if ( ! V_216 ) {
V_135 = - V_111 ;
goto V_252;
}
V_242 = F_140 ( V_238 , & V_260 , V_6 ) ;
if ( ! V_242 ) {
V_135 = - V_111 ;
F_75 ( V_216 ) ;
goto V_252;
}
V_242 -> V_224 = V_224 ;
V_242 -> V_261 = V_262 ;
V_216 -> V_263 = & V_264 ;
V_216 -> V_103 = V_6 ;
V_242 -> V_265 = V_216 ;
}
F_66 ( & V_195 ) ;
F_108 ( & V_6 -> V_208 , & V_266 ) ;
F_69 ( & V_195 ) ;
return 0 ;
V_252:
F_80 ( V_6 ) ;
V_251:
F_75 ( V_6 -> V_47 ) ;
V_250:
F_75 ( V_6 ) ;
V_248:
F_141 ( V_241 ) ;
F_74 ( L_26 , V_238 -> V_243 , V_135 ) ;
return V_135 ;
}
static bool F_142 ( void )
{
return ! ! ( F_26 ( F_94 () + V_201 ) & V_267 ) ;
}
int F_143 ( void )
{
if ( ! F_144 ( & V_266 ) ) {
if ( ! F_142 () ) {
F_63 ( L_27 , F_96 () ) ;
return - V_170 ;
}
F_93 () ;
F_98 () ;
}
return 0 ;
}
int T_6 F_145 ( struct V_197 * V_238 , struct V_268 * V_268 ,
struct V_212 * V_269 )
{
struct V_197 * V_270 ;
for ( V_270 = F_146 ( V_238 , V_271 ) ; V_270 ;
V_270 = F_146 ( V_270 , V_271 ) ) {
F_134 ( V_270 , V_269 ) ;
}
if ( F_144 ( & V_266 ) ) {
F_88 ( L_28 ) ;
return - V_170 ;
}
V_80 = V_268 ;
F_76 () ;
F_60 ( V_268 -> V_107 ) ;
return 0 ;
}
