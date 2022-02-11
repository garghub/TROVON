static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 [ 0 ] &= ~ 0xffUL ;
V_2 -> V_4 [ 0 ] |= V_3 ;
}
static void F_2 ( struct V_1 * V_2 , T_2 V_5 )
{
V_2 -> V_4 [ 0 ] &= ~ ( 0xffffUL << 32 ) ;
V_2 -> V_4 [ 0 ] |= ( ( V_6 ) V_5 ) << 32 ;
}
static void F_3 ( struct V_1 * V_2 , T_2 V_7 )
{
V_2 -> V_4 [ 1 ] &= ~ 0xffffffffUL ;
V_2 -> V_4 [ 1 ] |= V_7 ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_8 )
{
V_2 -> V_4 [ 1 ] &= 0xffffffffUL ;
V_2 -> V_4 [ 1 ] |= ( ( V_6 ) V_8 ) << 32 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_9 )
{
V_2 -> V_4 [ 1 ] &= ~ 0x1fUL ;
V_2 -> V_4 [ 1 ] |= V_9 & 0x1f ;
}
static void F_6 ( struct V_1 * V_2 , V_6 V_10 )
{
V_2 -> V_4 [ 2 ] &= ~ 0xffffffffffffUL ;
V_2 -> V_4 [ 2 ] |= V_10 & 0xffffffffff00UL ;
}
static void F_7 ( struct V_1 * V_2 , int V_11 )
{
V_2 -> V_4 [ 2 ] &= ~ ( 1UL << 63 ) ;
V_2 -> V_4 [ 2 ] |= ( ( V_6 ) ! ! V_11 ) << 63 ;
}
static void F_8 ( struct V_1 * V_2 , V_6 V_12 )
{
V_2 -> V_4 [ 2 ] &= ~ ( 0xffffffffUL << 16 ) ;
V_2 -> V_4 [ 2 ] |= ( V_12 & ( 0xffffffffUL << 16 ) ) ;
}
static void F_9 ( struct V_1 * V_2 , T_3 V_13 )
{
V_2 -> V_4 [ 2 ] &= ~ 0xffffUL ;
V_2 -> V_4 [ 2 ] |= V_13 ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_4 [ 0 ] = F_11 ( V_2 -> V_4 [ 0 ] ) ;
V_2 -> V_4 [ 1 ] = F_11 ( V_2 -> V_4 [ 1 ] ) ;
V_2 -> V_4 [ 2 ] = F_11 ( V_2 -> V_4 [ 2 ] ) ;
V_2 -> V_4 [ 3 ] = F_11 ( V_2 -> V_4 [ 3 ] ) ;
}
static struct V_14 * F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned long V_10 ;
T_1 V_9 = F_13 ( V_16 -> V_17 . V_18 -> V_19 ) ;
V_10 = F_14 ( V_16 -> V_17 . V_18 -> V_20 ) ;
V_10 = F_15 ( V_10 , V_21 ) ;
F_1 ( V_2 , V_22 ) ;
F_2 ( V_2 , V_16 -> V_17 . V_18 -> V_23 ) ;
F_5 ( V_2 , V_9 - 1 ) ;
F_6 ( V_2 , V_10 ) ;
F_7 ( V_2 , V_16 -> V_17 . V_11 ) ;
F_10 ( V_2 ) ;
return V_16 -> V_17 . V_18 -> V_24 ;
}
static struct V_14 * F_16 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_25 ) ;
F_9 ( V_2 , V_16 -> V_26 . V_13 -> V_27 ) ;
F_8 ( V_2 , V_16 -> V_26 . V_13 -> V_28 ) ;
F_7 ( V_2 , V_16 -> V_26 . V_11 ) ;
F_10 ( V_2 ) ;
return V_16 -> V_26 . V_13 ;
}
static struct V_14 * F_17 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_29 ) ;
F_2 ( V_2 , V_16 -> V_30 . V_18 -> V_23 ) ;
F_3 ( V_2 , V_16 -> V_30 . V_31 ) ;
F_4 ( V_2 , V_16 -> V_30 . V_8 ) ;
F_9 ( V_2 , V_16 -> V_30 . V_18 -> V_24 -> V_27 ) ;
F_10 ( V_2 ) ;
return V_16 -> V_30 . V_18 -> V_24 ;
}
static struct V_14 * F_18 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_32 ) ;
F_2 ( V_2 , V_16 -> V_33 . V_18 -> V_23 ) ;
F_3 ( V_2 , V_16 -> V_33 . V_7 ) ;
F_9 ( V_2 , V_16 -> V_33 . V_13 -> V_27 ) ;
F_10 ( V_2 ) ;
return V_16 -> V_33 . V_18 -> V_24 ;
}
static struct V_14 * F_19 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_34 ) ;
F_2 ( V_2 , V_16 -> V_35 . V_18 -> V_23 ) ;
F_3 ( V_2 , V_16 -> V_35 . V_31 ) ;
F_10 ( V_2 ) ;
return V_16 -> V_35 . V_18 -> V_24 ;
}
static struct V_14 * F_20 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_36 ) ;
F_2 ( V_2 , V_16 -> V_37 . V_18 -> V_23 ) ;
F_3 ( V_2 , V_16 -> V_37 . V_31 ) ;
F_10 ( V_2 ) ;
return V_16 -> V_37 . V_18 -> V_24 ;
}
static struct V_14 * F_21 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_38 ) ;
F_9 ( V_2 , V_16 -> V_26 . V_13 -> V_27 ) ;
F_10 ( V_2 ) ;
return NULL ;
}
static V_6 F_22 ( struct V_39 * V_40 ,
struct V_1 * V_41 )
{
return ( V_41 - V_40 -> V_42 ) * sizeof( * V_41 ) ;
}
static int F_23 ( struct V_39 * V_40 )
{
int V_43 ;
int V_44 ;
V_43 = V_40 -> V_45 - V_40 -> V_42 ;
V_44 = F_24 ( V_40 -> V_46 + V_47 ) / sizeof( struct V_1 ) ;
if ( ( ( V_43 + 1 ) % V_48 ) == V_44 )
return 1 ;
return 0 ;
}
static struct V_1 * F_25 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
T_2 V_49 = 1000000 ;
while ( F_23 ( V_40 ) ) {
V_49 -- ;
if ( ! V_49 ) {
F_26 ( L_1 ) ;
return NULL ;
}
F_27 () ;
F_28 ( 1 ) ;
}
V_2 = V_40 -> V_45 ++ ;
if ( V_40 -> V_45 == ( V_40 -> V_42 + V_48 ) )
V_40 -> V_45 = V_40 -> V_42 ;
return V_2 ;
}
static struct V_1 * F_29 ( struct V_39 * V_40 )
{
V_6 V_50 = F_22 ( V_40 , V_40 -> V_45 ) ;
F_30 ( V_50 , V_40 -> V_46 + V_51 ) ;
return V_40 -> V_45 ;
}
static void F_31 ( struct V_39 * V_40 , struct V_1 * V_2 )
{
if ( V_40 -> V_52 & V_53 )
F_32 ( V_2 , sizeof( * V_2 ) ) ;
else
F_33 ( V_54 ) ;
}
static void F_34 ( struct V_39 * V_40 ,
struct V_1 * V_55 ,
struct V_1 * V_56 )
{
V_6 V_57 , V_58 , V_59 ;
T_2 V_49 = 1000000 ;
V_58 = F_22 ( V_40 , V_55 ) ;
V_59 = F_22 ( V_40 , V_56 ) ;
while ( 1 ) {
V_57 = F_24 ( V_40 -> V_46 + V_47 ) ;
if ( V_57 >= V_59 || V_57 < V_58 )
break;
V_49 -- ;
if ( ! V_49 ) {
F_26 ( L_2 ) ;
return;
}
F_27 () ;
F_28 ( 1 ) ;
}
}
static void F_35 ( struct V_39 * V_40 ,
T_4 V_60 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_61 , * V_62 ;
struct V_14 * V_63 ;
F_36 ( & V_40 -> V_64 ) ;
V_2 = F_25 ( V_40 ) ;
if ( ! V_2 ) {
F_26 ( L_3 ) ;
F_37 ( & V_40 -> V_64 ) ;
return;
}
V_63 = V_60 ( V_2 , V_16 ) ;
F_31 ( V_40 , V_2 ) ;
if ( V_63 ) {
V_61 = F_25 ( V_40 ) ;
if ( ! V_61 ) {
F_26 ( L_4 ) ;
goto V_65;
}
F_1 ( V_61 , V_66 ) ;
F_8 ( V_61 , V_63 -> V_28 ) ;
F_10 ( V_61 ) ;
F_31 ( V_40 , V_61 ) ;
}
V_65:
V_62 = F_29 ( V_40 ) ;
F_37 ( & V_40 -> V_64 ) ;
F_34 ( V_40 , V_2 , V_62 ) ;
}
static void F_38 ( struct V_67 * V_18 , T_2 V_31 )
{
struct V_15 V_16 ;
V_16 . V_37 . V_18 = V_18 ;
V_16 . V_37 . V_31 = V_31 ;
F_35 ( V_18 -> V_40 , F_20 , & V_16 ) ;
}
static void F_39 ( struct V_67 * V_18 , int V_11 )
{
struct V_15 V_16 ;
V_16 . V_17 . V_18 = V_18 ;
V_16 . V_17 . V_11 = ! ! V_11 ;
F_35 ( V_18 -> V_40 , F_12 , & V_16 ) ;
}
static void F_40 ( struct V_39 * V_40 , struct V_14 * V_13 ,
int V_11 )
{
struct V_15 V_16 ;
V_16 . V_26 . V_13 = V_13 ;
V_16 . V_26 . V_11 = ! ! V_11 ;
F_35 ( V_40 , F_16 , & V_16 ) ;
}
static void F_41 ( struct V_67 * V_18 , T_2 V_68 , T_2 V_7 )
{
struct V_15 V_16 ;
V_16 . V_30 . V_18 = V_18 ;
V_16 . V_30 . V_8 = V_68 ;
V_16 . V_30 . V_31 = V_7 ;
F_35 ( V_18 -> V_40 , F_17 , & V_16 ) ;
}
static void F_42 ( struct V_67 * V_18 ,
struct V_14 * V_13 , T_2 V_7 )
{
struct V_15 V_16 ;
V_16 . V_33 . V_18 = V_18 ;
V_16 . V_33 . V_13 = V_13 ;
V_16 . V_33 . V_7 = V_7 ;
F_35 ( V_18 -> V_40 , F_18 , & V_16 ) ;
}
static void F_43 ( struct V_67 * V_18 , T_2 V_7 )
{
struct V_15 V_16 ;
V_16 . V_35 . V_18 = V_18 ;
V_16 . V_35 . V_31 = V_7 ;
F_35 ( V_18 -> V_40 , F_19 , & V_16 ) ;
}
static void F_44 ( struct V_39 * V_40 , struct V_14 * V_13 )
{
struct V_15 V_16 ;
V_16 . V_69 . V_13 = V_13 ;
F_35 ( V_40 , F_21 , & V_16 ) ;
}
static inline T_2 F_45 ( struct V_70 * V_71 )
{
struct V_67 * V_72 = F_46 ( V_71 ) ;
return V_71 -> V_73 - V_72 -> V_74 ;
}
static void F_47 ( struct V_70 * V_71 , bool V_75 )
{
struct V_67 * V_72 = F_46 ( V_71 ) ;
T_5 V_73 = V_71 -> V_73 ;
T_2 V_7 = F_45 ( V_71 ) ;
T_1 * V_76 = F_48 ( V_77 -> V_78 ) + V_73 - 8192 ;
if ( V_75 )
* V_76 |= V_79 ;
else
* V_76 &= ~ V_79 ;
if ( V_77 -> V_52 & V_80 )
F_32 ( V_76 , sizeof( * V_76 ) ) ;
else
F_33 ( V_54 ) ;
F_38 ( V_72 , V_7 ) ;
}
static void F_49 ( struct V_70 * V_71 )
{
F_47 ( V_71 , false ) ;
}
static void F_50 ( struct V_70 * V_71 )
{
F_47 ( V_71 , true ) ;
}
static void F_51 ( struct V_70 * V_71 )
{
F_52 ( V_71 -> V_73 ) ;
}
static int F_53 ( struct V_70 * V_71 , const struct V_81 * V_82 ,
bool V_83 )
{
unsigned int V_84 = F_54 ( V_82 , V_85 ) ;
struct V_67 * V_72 = F_46 ( V_71 ) ;
struct V_14 * V_86 ;
T_2 V_7 = F_45 ( V_71 ) ;
if ( V_84 >= V_87 )
return - V_88 ;
V_86 = & V_72 -> V_40 -> V_89 [ V_84 ] ;
F_42 ( V_72 , V_86 , V_7 ) ;
V_72 -> V_24 = V_86 ;
return V_90 ;
}
static void F_55 ( struct V_70 * V_71 , struct V_91 * V_92 )
{
struct V_67 * V_72 = F_46 ( V_71 ) ;
struct V_39 * V_40 ;
V_6 V_93 ;
V_40 = V_72 -> V_40 ;
V_93 = V_40 -> V_94 + V_95 ;
V_92 -> V_96 = V_93 & ( ( 1UL << 32 ) - 1 ) ;
V_92 -> V_97 = V_93 >> 32 ;
V_92 -> V_98 = F_45 ( V_71 ) ;
}
static void F_56 ( struct V_70 * V_71 )
{
F_57 ( V_71 ) ;
F_58 ( V_71 ) ;
}
static void F_59 ( struct V_70 * V_71 )
{
F_60 ( V_71 ) ;
F_61 ( V_71 ) ;
}
static int F_62 ( int V_99 )
{
return ( V_99 - 8192 ) >> V_100 ;
}
static int F_63 ( int V_101 )
{
return ( V_101 << V_100 ) + 8192 ;
}
static int F_64 ( T_2 V_102 )
{
V_103 = F_62 ( 1UL << V_102 ) ;
V_104 = F_65 ( F_66 ( V_103 ) * sizeof( long ) ,
V_105 ) ;
if ( ! V_104 ) {
V_103 = 0 ;
return - V_106 ;
}
F_67 ( L_5 , ( int ) V_103 ) ;
return 0 ;
}
static unsigned long * F_68 ( int V_107 , int * V_46 , int * V_108 )
{
unsigned long * V_109 = NULL ;
int V_110 ;
int V_111 ;
int V_112 ;
V_111 = F_69 ( V_107 , V_113 ) ;
F_70 ( & V_114 ) ;
do {
V_110 = F_71 ( V_104 , V_103 ,
0 , V_111 , 0 ) ;
if ( V_110 < V_103 )
break;
V_111 -- ;
} while ( V_111 > 0 );
if ( ! V_111 )
goto V_115;
V_109 = F_65 ( F_66 ( V_111 * V_113 ) * sizeof ( long ) ,
V_116 ) ;
if ( ! V_109 )
goto V_115;
for ( V_112 = 0 ; V_112 < V_111 ; V_112 ++ )
F_72 ( V_110 + V_112 , V_104 ) ;
* V_46 = F_63 ( V_110 ) ;
* V_108 = V_111 * V_113 ;
V_115:
F_73 ( & V_114 ) ;
return V_109 ;
}
static void F_74 ( unsigned long * V_109 , int V_46 , int V_108 )
{
int V_99 ;
F_70 ( & V_114 ) ;
for ( V_99 = V_46 ; V_99 < ( V_46 + V_108 ) ; V_99 += V_113 ) {
int V_101 = F_62 ( V_99 ) ;
F_75 ( V_101 > V_103 ) ;
if ( F_76 ( V_101 , V_104 ) ) {
F_77 ( V_101 , V_104 ) ;
} else {
F_78 ( L_6 , V_101 ) ;
}
}
F_73 ( & V_114 ) ;
F_79 ( V_109 ) ;
}
static int T_6 F_80 ( void )
{
T_7 V_117 ;
V_77 -> V_78 = F_81 ( V_118 ,
F_82 ( V_119 ) ) ;
if ( ! V_77 -> V_78 ) {
F_78 ( L_7 ) ;
return - V_106 ;
}
V_117 = F_83 ( V_77 -> V_78 ) ;
F_67 ( L_8 , & V_117 ) ;
memset ( F_48 ( V_77 -> V_78 ) ,
V_120 | V_121 ,
V_119 ) ;
F_32 ( F_48 ( V_77 -> V_78 ) , V_119 ) ;
return 0 ;
}
static void F_84 ( struct V_39 * V_40 )
{
int V_112 ;
for ( V_112 = 0 ; V_112 < V_122 ; V_112 ++ ) {
if ( V_40 -> V_123 [ V_112 ] ) {
F_85 ( ( unsigned long ) V_40 -> V_123 [ V_112 ] ) ;
V_40 -> V_123 [ V_112 ] = NULL ;
}
}
}
static int F_86 ( struct V_39 * V_40 )
{
int V_124 ;
int V_112 ;
int V_125 = V_126 ;
V_6 V_127 = V_128 ;
for ( V_112 = 0 ; V_112 < V_122 ; V_112 ++ ) {
V_6 V_129 = F_87 ( V_40 -> V_46 + V_130 + V_112 * 8 ) ;
V_6 type = F_88 ( V_129 ) ;
V_6 V_131 = F_89 ( V_129 ) ;
V_6 V_132 ;
void * V_46 ;
if ( type == V_133 )
continue;
V_46 = ( void * ) F_90 ( V_105 ) ;
if ( ! V_46 ) {
V_124 = - V_106 ;
goto V_134;
}
V_40 -> V_123 [ V_112 ] = V_46 ;
V_135:
V_129 = ( F_14 ( V_46 ) |
( type << V_136 ) |
( ( V_131 - 1 ) << V_137 ) |
V_138 |
V_127 |
V_139 ) ;
switch ( V_125 ) {
case V_140 :
V_129 |= V_141 ;
break;
case V_142 :
V_129 |= V_143 ;
break;
case V_144 :
V_129 |= V_145 ;
break;
}
V_129 |= ( V_126 / V_125 ) - 1 ;
F_91 ( V_129 , V_40 -> V_46 + V_130 + V_112 * 8 ) ;
V_132 = F_87 ( V_40 -> V_46 + V_130 + V_112 * 8 ) ;
if ( ( V_129 ^ V_132 ) & V_146 ) {
V_127 = V_132 & V_146 ;
goto V_135;
}
if ( ( V_129 ^ V_132 ) & V_147 ) {
switch ( V_125 ) {
case V_142 :
V_125 = V_140 ;
goto V_135;
case V_144 :
V_125 = V_142 ;
goto V_135;
}
}
if ( V_129 != V_132 ) {
F_78 ( L_9 ,
V_40 -> V_148 . V_149 -> V_150 , V_112 ,
( unsigned long ) V_129 , ( unsigned long ) V_132 ) ;
V_124 = - V_151 ;
goto V_134;
}
F_67 ( L_10 ,
( int ) ( V_126 / V_131 ) ,
V_152 [ type ] ,
( unsigned long ) F_14 ( V_46 ) ,
V_125 / V_153 , ( int ) V_127 >> V_154 ) ;
}
return 0 ;
V_134:
F_84 ( V_40 ) ;
return V_124 ;
}
static int F_92 ( struct V_39 * V_40 )
{
V_40 -> V_89 = F_65 ( V_87 * sizeof( * V_40 -> V_89 ) ,
V_105 ) ;
if ( ! V_40 -> V_89 )
return - V_106 ;
return 0 ;
}
static void F_93 ( void )
{
void T_8 * V_155 = F_94 () ;
struct V_156 * V_157 ;
V_6 V_129 , V_132 ;
V_157 = F_95 () -> V_157 ;
if ( ! V_157 ) {
T_7 V_117 ;
V_157 = F_81 ( V_118 | V_158 ,
F_82 ( F_96 ( V_159 , V_144 ) ) ) ;
if ( ! V_157 ) {
F_78 ( L_11 ,
F_97 () ) ;
return;
}
F_32 ( F_48 ( V_157 ) , V_159 ) ;
V_117 = F_83 ( V_157 ) ;
F_67 ( L_12 ,
F_97 () , & V_117 ) ;
F_95 () -> V_157 = V_157 ;
}
V_129 = F_24 ( V_155 + V_160 ) ;
V_129 &= ~ V_161 ;
F_30 ( V_129 , V_155 + V_160 ) ;
F_33 ( V_162 ) ;
V_129 = ( F_83 ( V_77 -> V_78 ) |
V_163 |
V_164 |
( ( V_165 - 1 ) & V_166 ) ) ;
F_91 ( V_129 , V_155 + V_167 ) ;
V_132 = F_87 ( V_155 + V_167 ) ;
if ( ( V_132 ^ V_129 ) & V_168 ) {
F_98 ( L_13 ) ;
V_77 -> V_52 |= V_80 ;
}
V_129 = ( F_83 ( V_157 ) |
V_163 |
V_164 ) ;
F_91 ( V_129 , V_155 + V_169 ) ;
V_129 = F_24 ( V_155 + V_160 ) ;
V_129 |= V_161 ;
F_30 ( V_129 , V_155 + V_160 ) ;
F_33 ( V_162 ) ;
}
static void F_99 ( void )
{
struct V_39 * V_40 ;
int V_84 ;
F_70 ( & V_170 ) ;
V_84 = F_97 () ;
F_100 (its, &its_nodes, entry) {
V_6 V_171 ;
if ( F_87 ( V_40 -> V_46 + V_172 ) & V_173 ) {
V_171 = F_95 () -> V_94 ;
} else {
V_171 = F_87 ( F_94 () + V_174 ) ;
V_171 = F_101 ( V_171 ) ;
}
V_40 -> V_89 [ V_84 ] . V_28 = V_171 ;
V_40 -> V_89 [ V_84 ] . V_27 = V_84 ;
F_40 ( V_40 , & V_40 -> V_89 [ V_84 ] , 1 ) ;
F_44 ( V_40 , & V_40 -> V_89 [ V_84 ] ) ;
}
F_73 ( & V_170 ) ;
}
static struct V_67 * F_102 ( struct V_39 * V_40 , T_2 V_175 )
{
struct V_67 * V_72 = NULL , * V_132 ;
F_36 ( & V_40 -> V_64 ) ;
F_100 (tmp, &its->its_device_list, entry) {
if ( V_132 -> V_23 == V_175 ) {
V_72 = V_132 ;
break;
}
}
F_37 ( & V_40 -> V_64 ) ;
return V_72 ;
}
static struct V_67 * F_103 ( struct V_39 * V_40 , T_2 V_175 ,
int V_176 )
{
struct V_67 * V_18 ;
unsigned long * V_177 ;
void * V_20 ;
int V_74 ;
int V_178 ;
int V_19 ;
int V_84 ;
int V_179 ;
V_18 = F_65 ( sizeof( * V_18 ) , V_105 ) ;
V_19 = F_96 ( 2UL , F_104 ( V_176 ) ) ;
V_179 = V_19 * V_40 -> V_180 ;
V_179 = F_96 ( V_179 , V_21 ) + V_21 - 1 ;
V_20 = F_105 ( V_179 , V_105 ) ;
V_177 = F_68 ( V_176 , & V_74 , & V_178 ) ;
if ( ! V_18 || ! V_20 || ! V_177 ) {
F_79 ( V_18 ) ;
F_79 ( V_20 ) ;
F_79 ( V_177 ) ;
return NULL ;
}
V_18 -> V_40 = V_40 ;
V_18 -> V_20 = V_20 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_177 = V_177 ;
V_18 -> V_74 = V_74 ;
V_18 -> V_178 = V_178 ;
V_18 -> V_23 = V_175 ;
F_106 ( & V_18 -> V_181 ) ;
F_36 ( & V_40 -> V_64 ) ;
F_107 ( & V_18 -> V_181 , & V_40 -> V_182 ) ;
F_37 ( & V_40 -> V_64 ) ;
V_84 = F_108 ( V_85 ) ;
V_18 -> V_24 = & V_40 -> V_89 [ V_84 ] ;
F_39 ( V_18 , 1 ) ;
return V_18 ;
}
static void F_109 ( struct V_67 * V_72 )
{
F_36 ( & V_72 -> V_40 -> V_64 ) ;
F_110 ( & V_72 -> V_181 ) ;
F_37 ( & V_72 -> V_40 -> V_64 ) ;
F_79 ( V_72 -> V_20 ) ;
F_79 ( V_72 ) ;
}
static int F_111 ( struct V_67 * V_18 , T_5 * V_73 )
{
int V_183 ;
V_183 = F_112 ( V_18 -> V_177 , V_18 -> V_178 ) ;
if ( V_183 == V_18 -> V_178 )
return - V_184 ;
* V_73 = V_18 -> V_74 + V_183 ;
F_72 ( V_183 , V_18 -> V_177 ) ;
return 0 ;
}
static int F_113 ( struct V_185 * V_186 , struct V_187 * V_18 ,
int V_188 , T_9 * V_189 )
{
struct V_190 * V_191 ;
struct V_39 * V_40 ;
T_2 V_175 ;
struct V_67 * V_72 ;
if ( ! F_114 ( V_18 ) )
return - V_88 ;
V_191 = F_115 ( V_18 ) ;
V_175 = F_116 ( V_191 -> V_192 -> V_193 , V_191 -> V_194 ) ;
V_40 = V_186 -> V_195 -> V_196 ;
V_72 = F_102 ( V_40 , V_175 ) ;
if ( F_117 ( V_72 ) )
return - V_88 ;
V_72 = F_103 ( V_40 , V_175 , V_188 ) ;
if ( ! V_72 )
return - V_106 ;
F_118 ( & V_191 -> V_18 , L_14 , V_188 , F_13 ( V_188 ) ) ;
V_189 -> V_197 [ 0 ] . V_41 = V_72 ;
V_189 -> V_197 [ 1 ] . V_41 = V_18 ;
return 0 ;
}
static int F_119 ( struct V_185 * V_186 ,
unsigned int V_198 ,
T_5 V_73 )
{
struct V_199 args ;
args . V_200 = V_186 -> V_195 -> V_149 ;
args . V_201 = 3 ;
args . args [ 0 ] = V_202 ;
args . args [ 1 ] = V_73 ;
args . args [ 2 ] = V_203 ;
return F_120 ( V_186 , V_198 , 1 , & args ) ;
}
static int F_121 ( struct V_185 * V_186 , unsigned int V_198 ,
unsigned int V_107 , void * args )
{
T_9 * V_189 = args ;
struct V_67 * V_72 = V_189 -> V_197 [ 0 ] . V_41 ;
T_5 V_73 ;
int V_124 ;
int V_112 ;
for ( V_112 = 0 ; V_112 < V_107 ; V_112 ++ ) {
V_124 = F_111 ( V_72 , & V_73 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_119 ( V_186 , V_198 + V_112 , V_73 ) ;
if ( V_124 )
return V_124 ;
F_122 ( V_186 , V_198 + V_112 ,
V_73 , & V_204 , V_72 ) ;
F_118 ( V_189 -> V_197 [ 1 ] . V_41 , L_15 ,
( int ) ( V_73 - V_72 -> V_74 ) , ( int ) V_73 , V_198 + V_112 ) ;
}
return 0 ;
}
static void F_123 ( struct V_185 * V_186 ,
struct V_70 * V_71 )
{
struct V_67 * V_72 = F_46 ( V_71 ) ;
T_2 V_205 = F_45 ( V_71 ) ;
F_41 ( V_72 , V_71 -> V_73 , V_205 ) ;
}
static void F_124 ( struct V_185 * V_186 ,
struct V_70 * V_71 )
{
struct V_67 * V_72 = F_46 ( V_71 ) ;
T_2 V_205 = F_45 ( V_71 ) ;
F_43 ( V_72 , V_205 ) ;
}
static void F_125 ( struct V_185 * V_186 , unsigned int V_198 ,
unsigned int V_107 )
{
struct V_70 * V_71 = F_126 ( V_186 , V_198 ) ;
struct V_67 * V_72 = F_46 ( V_71 ) ;
int V_112 ;
for ( V_112 = 0 ; V_112 < V_107 ; V_112 ++ ) {
struct V_70 * V_98 = F_126 ( V_186 ,
V_198 + V_112 ) ;
T_2 V_205 = F_45 ( V_98 ) ;
F_77 ( V_205 , V_72 -> V_177 ) ;
F_127 ( V_98 ) ;
}
if ( F_128 ( V_72 -> V_177 , V_72 -> V_178 ) ) {
F_74 ( V_72 -> V_177 ,
V_72 -> V_74 ,
V_72 -> V_178 ) ;
F_39 ( V_72 , 0 ) ;
F_109 ( V_72 ) ;
}
F_129 ( V_186 , V_198 , V_107 ) ;
}
static int F_130 ( struct V_206 * V_207 , struct V_185 * V_195 )
{
struct V_208 V_209 ;
struct V_39 * V_40 ;
void T_8 * V_210 ;
T_2 V_129 ;
V_6 V_211 , V_132 ;
int V_124 ;
V_124 = F_131 ( V_207 , 0 , & V_209 ) ;
if ( V_124 ) {
F_132 ( L_16 , V_207 -> V_150 ) ;
return - V_151 ;
}
V_210 = F_133 ( V_209 . V_212 , F_134 ( & V_209 ) ) ;
if ( ! V_210 ) {
F_132 ( L_17 , V_207 -> V_150 ) ;
return - V_106 ;
}
V_129 = F_24 ( V_210 + V_213 ) & V_214 ;
if ( V_129 != 0x30 && V_129 != 0x40 ) {
F_132 ( L_18 , V_207 -> V_150 ) ;
V_124 = - V_215 ;
goto V_216;
}
F_67 ( L_19 , V_207 -> V_150 ) ;
V_40 = F_65 ( sizeof( * V_40 ) , V_105 ) ;
if ( ! V_40 ) {
V_124 = - V_106 ;
goto V_216;
}
F_135 ( & V_40 -> V_64 ) ;
F_106 ( & V_40 -> V_181 ) ;
F_106 ( & V_40 -> V_182 ) ;
V_40 -> V_46 = V_210 ;
V_40 -> V_94 = V_209 . V_212 ;
V_40 -> V_148 . V_149 = V_207 ;
V_40 -> V_180 = ( ( F_24 ( V_210 + V_172 ) >> 4 ) & 0xf ) + 1 ;
V_40 -> V_42 = F_65 ( V_217 , V_105 ) ;
if ( ! V_40 -> V_42 ) {
V_124 = - V_106 ;
goto V_218;
}
V_40 -> V_45 = V_40 -> V_42 ;
V_124 = F_86 ( V_40 ) ;
if ( V_124 )
goto V_219;
V_124 = F_92 ( V_40 ) ;
if ( V_124 )
goto V_220;
V_211 = ( F_14 ( V_40 -> V_42 ) |
V_221 |
V_222 |
( V_217 / V_140 - 1 ) |
V_223 ) ;
F_91 ( V_211 , V_40 -> V_46 + V_224 ) ;
V_132 = F_87 ( V_40 -> V_46 + V_224 ) ;
F_91 ( 0 , V_40 -> V_46 + V_51 ) ;
F_30 ( 1 , V_40 -> V_46 + V_225 ) ;
if ( ( V_132 ^ V_211 ) & V_146 ) {
F_67 ( L_20 ) ;
V_40 -> V_52 |= V_53 ;
}
if ( F_136 ( V_40 -> V_148 . V_149 , L_21 ) ) {
V_40 -> V_186 = F_137 ( NULL , & V_226 , V_40 ) ;
if ( ! V_40 -> V_186 ) {
V_124 = - V_106 ;
goto V_220;
}
V_40 -> V_186 -> V_195 = V_195 ;
V_40 -> V_148 . V_186 = F_138 ( V_207 ,
& V_227 ,
V_40 -> V_186 ) ;
if ( ! V_40 -> V_148 . V_186 ) {
V_124 = - V_106 ;
goto V_228;
}
V_124 = F_139 ( & V_40 -> V_148 ) ;
if ( V_124 )
goto V_228;
}
F_70 ( & V_170 ) ;
F_107 ( & V_40 -> V_181 , & V_229 ) ;
F_73 ( & V_170 ) ;
return 0 ;
V_228:
if ( V_40 -> V_148 . V_186 )
F_140 ( V_40 -> V_148 . V_186 ) ;
if ( V_40 -> V_186 )
F_140 ( V_40 -> V_186 ) ;
V_220:
F_84 ( V_40 ) ;
V_219:
F_79 ( V_40 -> V_42 ) ;
V_218:
F_79 ( V_40 ) ;
V_216:
F_141 ( V_210 ) ;
F_78 ( L_22 , V_207 -> V_150 , V_124 ) ;
return V_124 ;
}
static bool F_142 ( void )
{
return ! ! ( F_24 ( F_94 () + V_174 ) & V_230 ) ;
}
int F_143 ( void )
{
if ( ! F_142 () ) {
F_67 ( L_23 , F_97 () ) ;
return - V_151 ;
}
if ( ! F_144 ( & V_229 ) ) {
F_93 () ;
F_99 () ;
}
return 0 ;
}
int F_145 ( struct V_206 * V_207 , struct V_231 * V_231 ,
struct V_185 * V_232 )
{
struct V_206 * V_200 ;
for ( V_200 = F_146 ( V_207 , V_233 ) ; V_200 ;
V_200 = F_146 ( V_200 , V_233 ) ) {
F_130 ( V_200 , V_232 ) ;
}
if ( F_144 ( & V_229 ) ) {
F_132 ( L_24 ) ;
return - V_151 ;
}
V_77 = V_231 ;
V_234 = V_207 ;
F_80 () ;
F_64 ( V_231 -> V_102 ) ;
return 0 ;
}
