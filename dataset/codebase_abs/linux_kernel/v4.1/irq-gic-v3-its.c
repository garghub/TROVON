static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 [ 0 ] &= ~ 0xffUL ;
V_2 -> V_4 [ 0 ] |= V_3 ;
}
static void F_2 ( struct V_1 * V_2 , T_2 V_5 )
{
V_2 -> V_4 [ 0 ] &= F_3 ( 32 ) - 1 ;
V_2 -> V_4 [ 0 ] |= ( ( V_6 ) V_5 ) << 32 ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_7 )
{
V_2 -> V_4 [ 1 ] &= ~ 0xffffffffUL ;
V_2 -> V_4 [ 1 ] |= V_7 ;
}
static void F_5 ( struct V_1 * V_2 , T_2 V_8 )
{
V_2 -> V_4 [ 1 ] &= 0xffffffffUL ;
V_2 -> V_4 [ 1 ] |= ( ( V_6 ) V_8 ) << 32 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_9 )
{
V_2 -> V_4 [ 1 ] &= ~ 0x1fUL ;
V_2 -> V_4 [ 1 ] |= V_9 & 0x1f ;
}
static void F_7 ( struct V_1 * V_2 , V_6 V_10 )
{
V_2 -> V_4 [ 2 ] &= ~ 0xffffffffffffUL ;
V_2 -> V_4 [ 2 ] |= V_10 & 0xffffffffff00UL ;
}
static void F_8 ( struct V_1 * V_2 , int V_11 )
{
V_2 -> V_4 [ 2 ] &= ~ ( 1UL << 63 ) ;
V_2 -> V_4 [ 2 ] |= ( ( V_6 ) ! ! V_11 ) << 63 ;
}
static void F_9 ( struct V_1 * V_2 , V_6 V_12 )
{
V_2 -> V_4 [ 2 ] &= ~ ( 0xffffffffUL << 16 ) ;
V_2 -> V_4 [ 2 ] |= ( V_12 & ( 0xffffffffUL << 16 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , T_3 V_13 )
{
V_2 -> V_4 [ 2 ] &= ~ 0xffffUL ;
V_2 -> V_4 [ 2 ] |= V_13 ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_4 [ 0 ] = F_12 ( V_2 -> V_4 [ 0 ] ) ;
V_2 -> V_4 [ 1 ] = F_12 ( V_2 -> V_4 [ 1 ] ) ;
V_2 -> V_4 [ 2 ] = F_12 ( V_2 -> V_4 [ 2 ] ) ;
V_2 -> V_4 [ 3 ] = F_12 ( V_2 -> V_4 [ 3 ] ) ;
}
static struct V_14 * F_13 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned long V_10 ;
T_1 V_9 = F_14 ( V_16 -> V_17 . V_18 -> V_19 ) ;
V_10 = F_15 ( V_16 -> V_17 . V_18 -> V_20 ) ;
V_10 = F_16 ( V_10 , V_21 ) ;
F_1 ( V_2 , V_22 ) ;
F_2 ( V_2 , V_16 -> V_17 . V_18 -> V_23 ) ;
F_6 ( V_2 , V_9 - 1 ) ;
F_7 ( V_2 , V_10 ) ;
F_8 ( V_2 , V_16 -> V_17 . V_11 ) ;
F_11 ( V_2 ) ;
return V_16 -> V_17 . V_18 -> V_24 ;
}
static struct V_14 * F_17 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_25 ) ;
F_10 ( V_2 , V_16 -> V_26 . V_13 -> V_27 ) ;
F_9 ( V_2 , V_16 -> V_26 . V_13 -> V_28 ) ;
F_8 ( V_2 , V_16 -> V_26 . V_11 ) ;
F_11 ( V_2 ) ;
return V_16 -> V_26 . V_13 ;
}
static struct V_14 * F_18 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_29 ) ;
F_2 ( V_2 , V_16 -> V_30 . V_18 -> V_23 ) ;
F_4 ( V_2 , V_16 -> V_30 . V_31 ) ;
F_5 ( V_2 , V_16 -> V_30 . V_8 ) ;
F_10 ( V_2 , V_16 -> V_30 . V_18 -> V_24 -> V_27 ) ;
F_11 ( V_2 ) ;
return V_16 -> V_30 . V_18 -> V_24 ;
}
static struct V_14 * F_19 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_32 ) ;
F_2 ( V_2 , V_16 -> V_33 . V_18 -> V_23 ) ;
F_4 ( V_2 , V_16 -> V_33 . V_7 ) ;
F_10 ( V_2 , V_16 -> V_33 . V_13 -> V_27 ) ;
F_11 ( V_2 ) ;
return V_16 -> V_33 . V_18 -> V_24 ;
}
static struct V_14 * F_20 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_34 ) ;
F_2 ( V_2 , V_16 -> V_35 . V_18 -> V_23 ) ;
F_4 ( V_2 , V_16 -> V_35 . V_31 ) ;
F_11 ( V_2 ) ;
return V_16 -> V_35 . V_18 -> V_24 ;
}
static struct V_14 * F_21 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_36 ) ;
F_2 ( V_2 , V_16 -> V_37 . V_18 -> V_23 ) ;
F_4 ( V_2 , V_16 -> V_37 . V_31 ) ;
F_11 ( V_2 ) ;
return V_16 -> V_37 . V_18 -> V_24 ;
}
static struct V_14 * F_22 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_1 ( V_2 , V_38 ) ;
F_10 ( V_2 , V_16 -> V_26 . V_13 -> V_27 ) ;
F_11 ( V_2 ) ;
return NULL ;
}
static V_6 F_23 ( struct V_39 * V_40 ,
struct V_1 * V_41 )
{
return ( V_41 - V_40 -> V_42 ) * sizeof( * V_41 ) ;
}
static int F_24 ( struct V_39 * V_40 )
{
int V_43 ;
int V_44 ;
V_43 = V_40 -> V_45 - V_40 -> V_42 ;
V_44 = F_25 ( V_40 -> V_46 + V_47 ) / sizeof( struct V_1 ) ;
if ( ( ( V_43 + 1 ) % V_48 ) == V_44 )
return 1 ;
return 0 ;
}
static struct V_1 * F_26 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
T_2 V_49 = 1000000 ;
while ( F_24 ( V_40 ) ) {
V_49 -- ;
if ( ! V_49 ) {
F_27 ( L_1 ) ;
return NULL ;
}
F_28 () ;
F_29 ( 1 ) ;
}
V_2 = V_40 -> V_45 ++ ;
if ( V_40 -> V_45 == ( V_40 -> V_42 + V_48 ) )
V_40 -> V_45 = V_40 -> V_42 ;
return V_2 ;
}
static struct V_1 * F_30 ( struct V_39 * V_40 )
{
V_6 V_50 = F_23 ( V_40 , V_40 -> V_45 ) ;
F_31 ( V_50 , V_40 -> V_46 + V_51 ) ;
return V_40 -> V_45 ;
}
static void F_32 ( struct V_39 * V_40 , struct V_1 * V_2 )
{
if ( V_40 -> V_52 & V_53 )
F_33 ( V_2 , sizeof( * V_2 ) ) ;
else
F_34 ( V_54 ) ;
}
static void F_35 ( struct V_39 * V_40 ,
struct V_1 * V_55 ,
struct V_1 * V_56 )
{
V_6 V_57 , V_58 , V_59 ;
T_2 V_49 = 1000000 ;
V_58 = F_23 ( V_40 , V_55 ) ;
V_59 = F_23 ( V_40 , V_56 ) ;
while ( 1 ) {
V_57 = F_25 ( V_40 -> V_46 + V_47 ) ;
if ( V_57 >= V_59 || V_57 < V_58 )
break;
V_49 -- ;
if ( ! V_49 ) {
F_27 ( L_2 ) ;
return;
}
F_28 () ;
F_29 ( 1 ) ;
}
}
static void F_36 ( struct V_39 * V_40 ,
T_4 V_60 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_61 , * V_62 ;
struct V_14 * V_63 ;
unsigned long V_52 ;
F_37 ( & V_40 -> V_64 , V_52 ) ;
V_2 = F_26 ( V_40 ) ;
if ( ! V_2 ) {
F_27 ( L_3 ) ;
F_38 ( & V_40 -> V_64 , V_52 ) ;
return;
}
V_63 = V_60 ( V_2 , V_16 ) ;
F_32 ( V_40 , V_2 ) ;
if ( V_63 ) {
V_61 = F_26 ( V_40 ) ;
if ( ! V_61 ) {
F_27 ( L_4 ) ;
goto V_65;
}
F_1 ( V_61 , V_66 ) ;
F_9 ( V_61 , V_63 -> V_28 ) ;
F_11 ( V_61 ) ;
F_32 ( V_40 , V_61 ) ;
}
V_65:
V_62 = F_30 ( V_40 ) ;
F_38 ( & V_40 -> V_64 , V_52 ) ;
F_35 ( V_40 , V_2 , V_62 ) ;
}
static void F_39 ( struct V_67 * V_18 , T_2 V_31 )
{
struct V_15 V_16 ;
V_16 . V_37 . V_18 = V_18 ;
V_16 . V_37 . V_31 = V_31 ;
F_36 ( V_18 -> V_40 , F_21 , & V_16 ) ;
}
static void F_40 ( struct V_67 * V_18 , int V_11 )
{
struct V_15 V_16 ;
V_16 . V_17 . V_18 = V_18 ;
V_16 . V_17 . V_11 = ! ! V_11 ;
F_36 ( V_18 -> V_40 , F_13 , & V_16 ) ;
}
static void F_41 ( struct V_39 * V_40 , struct V_14 * V_13 ,
int V_11 )
{
struct V_15 V_16 ;
V_16 . V_26 . V_13 = V_13 ;
V_16 . V_26 . V_11 = ! ! V_11 ;
F_36 ( V_40 , F_17 , & V_16 ) ;
}
static void F_42 ( struct V_67 * V_18 , T_2 V_68 , T_2 V_7 )
{
struct V_15 V_16 ;
V_16 . V_30 . V_18 = V_18 ;
V_16 . V_30 . V_8 = V_68 ;
V_16 . V_30 . V_31 = V_7 ;
F_36 ( V_18 -> V_40 , F_18 , & V_16 ) ;
}
static void F_43 ( struct V_67 * V_18 ,
struct V_14 * V_13 , T_2 V_7 )
{
struct V_15 V_16 ;
V_16 . V_33 . V_18 = V_18 ;
V_16 . V_33 . V_13 = V_13 ;
V_16 . V_33 . V_7 = V_7 ;
F_36 ( V_18 -> V_40 , F_19 , & V_16 ) ;
}
static void F_44 ( struct V_67 * V_18 , T_2 V_7 )
{
struct V_15 V_16 ;
V_16 . V_35 . V_18 = V_18 ;
V_16 . V_35 . V_31 = V_7 ;
F_36 ( V_18 -> V_40 , F_20 , & V_16 ) ;
}
static void F_45 ( struct V_39 * V_40 , struct V_14 * V_13 )
{
struct V_15 V_16 ;
V_16 . V_69 . V_13 = V_13 ;
F_36 ( V_40 , F_22 , & V_16 ) ;
}
static inline T_2 F_46 ( struct V_70 * V_71 )
{
struct V_67 * V_72 = F_47 ( V_71 ) ;
return V_71 -> V_73 - V_72 -> V_74 ;
}
static void F_48 ( struct V_70 * V_71 , bool V_75 )
{
struct V_67 * V_72 = F_47 ( V_71 ) ;
T_5 V_73 = V_71 -> V_73 ;
T_2 V_7 = F_46 ( V_71 ) ;
T_1 * V_76 = F_49 ( V_77 -> V_78 ) + V_73 - 8192 ;
if ( V_75 )
* V_76 |= V_79 ;
else
* V_76 &= ~ V_79 ;
if ( V_77 -> V_52 & V_80 )
F_33 ( V_76 , sizeof( * V_76 ) ) ;
else
F_34 ( V_54 ) ;
F_39 ( V_72 , V_7 ) ;
}
static void F_50 ( struct V_70 * V_71 )
{
F_48 ( V_71 , false ) ;
}
static void F_51 ( struct V_70 * V_71 )
{
F_48 ( V_71 , true ) ;
}
static void F_52 ( struct V_70 * V_71 )
{
F_53 ( V_71 -> V_73 ) ;
}
static int F_54 ( struct V_70 * V_71 , const struct V_81 * V_82 ,
bool V_83 )
{
unsigned int V_84 = F_55 ( V_82 , V_85 ) ;
struct V_67 * V_72 = F_47 ( V_71 ) ;
struct V_14 * V_86 ;
T_2 V_7 = F_46 ( V_71 ) ;
if ( V_84 >= V_87 )
return - V_88 ;
V_86 = & V_72 -> V_40 -> V_89 [ V_84 ] ;
F_43 ( V_72 , V_86 , V_7 ) ;
V_72 -> V_24 = V_86 ;
return V_90 ;
}
static void F_56 ( struct V_70 * V_71 , struct V_91 * V_92 )
{
struct V_67 * V_72 = F_47 ( V_71 ) ;
struct V_39 * V_40 ;
V_6 V_93 ;
V_40 = V_72 -> V_40 ;
V_93 = V_40 -> V_94 + V_95 ;
V_92 -> V_96 = V_93 & ( ( 1UL << 32 ) - 1 ) ;
V_92 -> V_97 = V_93 >> 32 ;
V_92 -> V_98 = F_46 ( V_71 ) ;
}
static void F_57 ( struct V_70 * V_71 )
{
F_58 ( V_71 ) ;
F_59 ( V_71 ) ;
}
static void F_60 ( struct V_70 * V_71 )
{
F_61 ( V_71 ) ;
F_62 ( V_71 ) ;
}
static int F_63 ( int V_99 )
{
return ( V_99 - 8192 ) >> V_100 ;
}
static int F_64 ( int V_101 )
{
return ( V_101 << V_100 ) + 8192 ;
}
static int F_65 ( T_2 V_102 )
{
V_103 = F_63 ( 1UL << V_102 ) ;
V_104 = F_66 ( F_67 ( V_103 ) * sizeof( long ) ,
V_105 ) ;
if ( ! V_104 ) {
V_103 = 0 ;
return - V_106 ;
}
F_68 ( L_5 , ( int ) V_103 ) ;
return 0 ;
}
static unsigned long * F_69 ( int V_107 , int * V_46 , int * V_108 )
{
unsigned long * V_109 = NULL ;
int V_110 ;
int V_111 ;
int V_112 ;
V_111 = F_70 ( V_107 , V_113 ) ;
F_71 ( & V_114 ) ;
do {
V_110 = F_72 ( V_104 , V_103 ,
0 , V_111 , 0 ) ;
if ( V_110 < V_103 )
break;
V_111 -- ;
} while ( V_111 > 0 );
if ( ! V_111 )
goto V_115;
V_109 = F_66 ( F_67 ( V_111 * V_113 ) * sizeof ( long ) ,
V_116 ) ;
if ( ! V_109 )
goto V_115;
for ( V_112 = 0 ; V_112 < V_111 ; V_112 ++ )
F_73 ( V_110 + V_112 , V_104 ) ;
* V_46 = F_64 ( V_110 ) ;
* V_108 = V_111 * V_113 ;
V_115:
F_74 ( & V_114 ) ;
return V_109 ;
}
static void F_75 ( unsigned long * V_109 , int V_46 , int V_108 )
{
int V_99 ;
F_71 ( & V_114 ) ;
for ( V_99 = V_46 ; V_99 < ( V_46 + V_108 ) ; V_99 += V_113 ) {
int V_101 = F_63 ( V_99 ) ;
F_76 ( V_101 > V_103 ) ;
if ( F_77 ( V_101 , V_104 ) ) {
F_78 ( V_101 , V_104 ) ;
} else {
F_79 ( L_6 , V_101 ) ;
}
}
F_74 ( & V_114 ) ;
F_80 ( V_109 ) ;
}
static int T_6 F_81 ( void )
{
T_7 V_117 ;
V_77 -> V_78 = F_82 ( V_118 ,
F_83 ( V_119 ) ) ;
if ( ! V_77 -> V_78 ) {
F_79 ( L_7 ) ;
return - V_106 ;
}
V_117 = F_84 ( V_77 -> V_78 ) ;
F_68 ( L_8 , & V_117 ) ;
memset ( F_49 ( V_77 -> V_78 ) ,
V_120 | V_121 ,
V_119 ) ;
F_33 ( F_49 ( V_77 -> V_78 ) , V_119 ) ;
return 0 ;
}
static void F_85 ( struct V_39 * V_40 )
{
int V_112 ;
for ( V_112 = 0 ; V_112 < V_122 ; V_112 ++ ) {
if ( V_40 -> V_123 [ V_112 ] ) {
F_86 ( ( unsigned long ) V_40 -> V_123 [ V_112 ] ) ;
V_40 -> V_123 [ V_112 ] = NULL ;
}
}
}
static int F_87 ( struct V_39 * V_40 )
{
int V_124 ;
int V_112 ;
int V_125 = V_126 ;
V_6 V_127 = V_128 ;
V_6 V_129 = V_130 ;
for ( V_112 = 0 ; V_112 < V_122 ; V_112 ++ ) {
V_6 V_131 = F_88 ( V_40 -> V_46 + V_132 + V_112 * 8 ) ;
V_6 type = F_89 ( V_131 ) ;
V_6 V_133 = F_90 ( V_131 ) ;
int V_134 = F_83 ( V_125 ) ;
int V_135 ;
V_6 V_136 ;
void * V_46 ;
if ( type == V_137 )
continue;
if ( type == V_138 ) {
V_6 V_139 = F_88 ( V_40 -> V_46 + V_140 ) ;
T_2 V_141 = F_91 ( V_139 ) ;
V_134 = F_92 ( F_83 ( ( 1UL << V_141 ) * V_133 ) ,
V_134 ) ;
if ( V_134 >= V_142 ) {
V_134 = V_142 - 1 ;
F_93 ( L_9 ,
V_40 -> V_143 . V_144 -> V_145 , V_134 ) ;
}
}
V_135 = ( 1 << V_134 ) * V_146 ;
V_46 = ( void * ) F_94 ( V_105 | V_147 , V_134 ) ;
if ( ! V_46 ) {
V_124 = - V_106 ;
goto V_148;
}
V_40 -> V_123 [ V_112 ] = V_46 ;
V_149:
V_131 = ( F_15 ( V_46 ) |
( type << V_150 ) |
( ( V_133 - 1 ) << V_151 ) |
V_129 |
V_127 |
V_152 ) ;
switch ( V_125 ) {
case V_153 :
V_131 |= V_154 ;
break;
case V_155 :
V_131 |= V_156 ;
break;
case V_126 :
V_131 |= V_157 ;
break;
}
V_131 |= ( V_135 / V_125 ) - 1 ;
F_95 ( V_131 , V_40 -> V_46 + V_132 + V_112 * 8 ) ;
V_136 = F_88 ( V_40 -> V_46 + V_132 + V_112 * 8 ) ;
if ( ( V_131 ^ V_136 ) & V_158 ) {
V_127 = V_136 & V_158 ;
if ( ! V_127 )
V_129 = V_159 ;
goto V_149;
}
if ( ( V_131 ^ V_136 ) & V_160 ) {
switch ( V_125 ) {
case V_155 :
V_125 = V_153 ;
goto V_149;
case V_126 :
V_125 = V_155 ;
goto V_149;
}
}
if ( V_131 != V_136 ) {
F_79 ( L_10 ,
V_40 -> V_143 . V_144 -> V_145 , V_112 ,
( unsigned long ) V_131 , ( unsigned long ) V_136 ) ;
V_124 = - V_161 ;
goto V_148;
}
F_68 ( L_11 ,
( int ) ( V_135 / V_133 ) ,
V_162 [ type ] ,
( unsigned long ) F_15 ( V_46 ) ,
V_125 / V_163 , ( int ) V_127 >> V_164 ) ;
}
return 0 ;
V_148:
F_85 ( V_40 ) ;
return V_124 ;
}
static int F_96 ( struct V_39 * V_40 )
{
V_40 -> V_89 = F_66 ( V_87 * sizeof( * V_40 -> V_89 ) ,
V_105 ) ;
if ( ! V_40 -> V_89 )
return - V_106 ;
return 0 ;
}
static void F_97 ( void )
{
void T_8 * V_165 = F_98 () ;
struct V_166 * V_167 ;
V_6 V_131 , V_136 ;
V_167 = F_99 () -> V_167 ;
if ( ! V_167 ) {
T_7 V_117 ;
V_167 = F_82 ( V_118 | V_147 ,
F_83 ( F_92 ( V_168 , V_126 ) ) ) ;
if ( ! V_167 ) {
F_79 ( L_12 ,
F_100 () ) ;
return;
}
F_33 ( F_49 ( V_167 ) , V_168 ) ;
V_117 = F_84 ( V_167 ) ;
F_68 ( L_13 ,
F_100 () , & V_117 ) ;
F_99 () -> V_167 = V_167 ;
}
V_131 = F_25 ( V_165 + V_169 ) ;
V_131 &= ~ V_170 ;
F_31 ( V_131 , V_165 + V_169 ) ;
F_34 ( V_171 ) ;
V_131 = ( F_84 ( V_77 -> V_78 ) |
V_172 |
V_173 |
( ( V_174 - 1 ) & V_175 ) ) ;
F_95 ( V_131 , V_165 + V_176 ) ;
V_136 = F_88 ( V_165 + V_176 ) ;
if ( ( V_136 ^ V_131 ) & V_177 ) {
if ( ! ( V_136 & V_177 ) ) {
V_131 &= ~ ( V_177 |
V_178 ) ;
V_131 |= V_179 ;
F_95 ( V_131 , V_165 + V_176 ) ;
}
F_101 ( L_14 ) ;
V_77 -> V_52 |= V_80 ;
}
V_131 = ( F_84 ( V_167 ) |
V_180 |
V_181 ) ;
F_95 ( V_131 , V_165 + V_182 ) ;
V_136 = F_88 ( V_165 + V_182 ) ;
if ( ! ( V_136 & V_183 ) ) {
V_131 &= ~ ( V_183 |
V_184 ) ;
V_131 |= V_185 ;
F_95 ( V_131 , V_165 + V_182 ) ;
}
V_131 = F_25 ( V_165 + V_169 ) ;
V_131 |= V_170 ;
F_31 ( V_131 , V_165 + V_169 ) ;
F_34 ( V_171 ) ;
}
static void F_102 ( void )
{
struct V_39 * V_40 ;
int V_84 ;
F_71 ( & V_186 ) ;
V_84 = F_100 () ;
F_103 (its, &its_nodes, entry) {
V_6 V_187 ;
if ( F_88 ( V_40 -> V_46 + V_140 ) & V_188 ) {
V_187 = F_99 () -> V_94 ;
} else {
V_187 = F_88 ( F_98 () + V_189 ) ;
V_187 = F_104 ( V_187 ) << 16 ;
}
V_40 -> V_89 [ V_84 ] . V_28 = V_187 ;
V_40 -> V_89 [ V_84 ] . V_27 = V_84 ;
F_41 ( V_40 , & V_40 -> V_89 [ V_84 ] , 1 ) ;
F_45 ( V_40 , & V_40 -> V_89 [ V_84 ] ) ;
}
F_74 ( & V_186 ) ;
}
static struct V_67 * F_105 ( struct V_39 * V_40 , T_2 V_190 )
{
struct V_67 * V_72 = NULL , * V_136 ;
unsigned long V_52 ;
F_37 ( & V_40 -> V_64 , V_52 ) ;
F_103 (tmp, &its->its_device_list, entry) {
if ( V_136 -> V_23 == V_190 ) {
V_72 = V_136 ;
break;
}
}
F_38 ( & V_40 -> V_64 , V_52 ) ;
return V_72 ;
}
static struct V_67 * F_106 ( struct V_39 * V_40 , T_2 V_190 ,
int V_191 )
{
struct V_67 * V_18 ;
unsigned long * V_192 ;
unsigned long V_52 ;
void * V_20 ;
int V_74 ;
int V_193 ;
int V_19 ;
int V_84 ;
int V_194 ;
V_18 = F_66 ( sizeof( * V_18 ) , V_105 ) ;
V_19 = F_92 ( 2UL , F_107 ( V_191 ) ) ;
V_194 = V_19 * V_40 -> V_195 ;
V_194 = F_92 ( V_194 , V_21 ) + V_21 - 1 ;
V_20 = F_66 ( V_194 , V_105 ) ;
V_192 = F_69 ( V_191 , & V_74 , & V_193 ) ;
if ( ! V_18 || ! V_20 || ! V_192 ) {
F_80 ( V_18 ) ;
F_80 ( V_20 ) ;
F_80 ( V_192 ) ;
return NULL ;
}
V_18 -> V_40 = V_40 ;
V_18 -> V_20 = V_20 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_192 = V_192 ;
V_18 -> V_74 = V_74 ;
V_18 -> V_193 = V_193 ;
V_18 -> V_23 = V_190 ;
F_108 ( & V_18 -> V_196 ) ;
F_37 ( & V_40 -> V_64 , V_52 ) ;
F_109 ( & V_18 -> V_196 , & V_40 -> V_197 ) ;
F_38 ( & V_40 -> V_64 , V_52 ) ;
V_84 = F_110 ( V_85 ) ;
V_18 -> V_24 = & V_40 -> V_89 [ V_84 ] ;
F_40 ( V_18 , 1 ) ;
return V_18 ;
}
static void F_111 ( struct V_67 * V_72 )
{
unsigned long V_52 ;
F_37 ( & V_72 -> V_40 -> V_64 , V_52 ) ;
F_112 ( & V_72 -> V_196 ) ;
F_38 ( & V_72 -> V_40 -> V_64 , V_52 ) ;
F_80 ( V_72 -> V_20 ) ;
F_80 ( V_72 ) ;
}
static int F_113 ( struct V_67 * V_18 , T_5 * V_73 )
{
int V_198 ;
V_198 = F_114 ( V_18 -> V_192 , V_18 -> V_193 ) ;
if ( V_198 == V_18 -> V_193 )
return - V_199 ;
* V_73 = V_18 -> V_74 + V_198 ;
F_73 ( V_198 , V_18 -> V_192 ) ;
return 0 ;
}
static int F_115 ( struct V_200 * V_201 )
{
int V_202 , V_203 ;
V_202 = F_92 ( F_116 ( V_201 ) , 0 ) ;
V_203 = F_92 ( F_117 ( V_201 ) , 0 ) ;
return F_92 ( V_202 , V_203 ) ;
}
static int F_118 ( struct V_200 * V_201 , T_3 V_204 , void * V_98 )
{
struct V_205 * V_206 = V_98 ;
V_206 -> V_190 = V_204 ;
if ( V_201 != V_206 -> V_201 )
V_206 -> V_49 += F_115 ( V_206 -> V_201 ) ;
return 0 ;
}
static int F_119 ( struct V_207 * V_208 , struct V_209 * V_18 ,
int V_210 , T_9 * V_211 )
{
struct V_200 * V_201 ;
struct V_39 * V_40 ;
struct V_67 * V_72 ;
struct V_205 V_206 ;
if ( ! F_120 ( V_18 ) )
return - V_88 ;
V_201 = F_121 ( V_18 ) ;
V_206 . V_201 = V_201 ;
V_206 . V_49 = V_210 ;
F_122 ( V_201 , F_118 , & V_206 ) ;
V_40 = V_208 -> V_212 -> V_213 ;
V_72 = F_105 ( V_40 , V_206 . V_190 ) ;
if ( V_72 ) {
F_123 ( V_18 , L_15 , V_206 . V_190 ) ;
goto V_115;
}
V_72 = F_106 ( V_40 , V_206 . V_190 , V_206 . V_49 ) ;
if ( ! V_72 )
return - V_106 ;
F_123 ( & V_201 -> V_18 , L_16 ,
V_206 . V_49 , F_14 ( V_206 . V_49 ) ) ;
V_115:
V_211 -> V_214 [ 0 ] . V_41 = V_72 ;
V_211 -> V_214 [ 1 ] . V_41 = V_18 ;
return 0 ;
}
static int F_124 ( struct V_207 * V_208 ,
unsigned int V_215 ,
T_5 V_73 )
{
struct V_216 args ;
args . V_217 = V_208 -> V_212 -> V_144 ;
args . V_218 = 3 ;
args . args [ 0 ] = V_219 ;
args . args [ 1 ] = V_73 ;
args . args [ 2 ] = V_220 ;
return F_125 ( V_208 , V_215 , 1 , & args ) ;
}
static int F_126 ( struct V_207 * V_208 , unsigned int V_215 ,
unsigned int V_107 , void * args )
{
T_9 * V_211 = args ;
struct V_67 * V_72 = V_211 -> V_214 [ 0 ] . V_41 ;
T_5 V_73 ;
int V_124 ;
int V_112 ;
for ( V_112 = 0 ; V_112 < V_107 ; V_112 ++ ) {
V_124 = F_113 ( V_72 , & V_73 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_124 ( V_208 , V_215 + V_112 , V_73 ) ;
if ( V_124 )
return V_124 ;
F_127 ( V_208 , V_215 + V_112 ,
V_73 , & V_221 , V_72 ) ;
F_123 ( V_211 -> V_214 [ 1 ] . V_41 , L_17 ,
( int ) ( V_73 - V_72 -> V_74 ) , ( int ) V_73 , V_215 + V_112 ) ;
}
return 0 ;
}
static void F_128 ( struct V_207 * V_208 ,
struct V_70 * V_71 )
{
struct V_67 * V_72 = F_47 ( V_71 ) ;
T_2 V_222 = F_46 ( V_71 ) ;
F_42 ( V_72 , V_71 -> V_73 , V_222 ) ;
}
static void F_129 ( struct V_207 * V_208 ,
struct V_70 * V_71 )
{
struct V_67 * V_72 = F_47 ( V_71 ) ;
T_2 V_222 = F_46 ( V_71 ) ;
F_44 ( V_72 , V_222 ) ;
}
static void F_130 ( struct V_207 * V_208 , unsigned int V_215 ,
unsigned int V_107 )
{
struct V_70 * V_71 = F_131 ( V_208 , V_215 ) ;
struct V_67 * V_72 = F_47 ( V_71 ) ;
int V_112 ;
for ( V_112 = 0 ; V_112 < V_107 ; V_112 ++ ) {
struct V_70 * V_98 = F_131 ( V_208 ,
V_215 + V_112 ) ;
T_2 V_222 = F_46 ( V_98 ) ;
F_78 ( V_222 , V_72 -> V_192 ) ;
F_132 ( V_98 ) ;
}
if ( F_133 ( V_72 -> V_192 , V_72 -> V_193 ) ) {
F_75 ( V_72 -> V_192 ,
V_72 -> V_74 ,
V_72 -> V_193 ) ;
F_40 ( V_72 , 0 ) ;
F_111 ( V_72 ) ;
}
F_134 ( V_208 , V_215 , V_107 ) ;
}
static int F_135 ( void T_8 * V_46 )
{
T_2 V_49 = 1000000 ;
T_2 V_131 ;
V_131 = F_25 ( V_46 + V_223 ) ;
if ( V_131 & V_224 )
return 0 ;
V_131 &= ~ V_225 ;
F_31 ( V_131 , V_46 + V_223 ) ;
while ( 1 ) {
V_131 = F_25 ( V_46 + V_223 ) ;
if ( V_131 & V_224 )
return 0 ;
V_49 -- ;
if ( ! V_49 )
return - V_226 ;
F_28 () ;
F_29 ( 1 ) ;
}
}
static int F_136 ( struct V_227 * V_228 , struct V_207 * V_212 )
{
struct V_229 V_230 ;
struct V_39 * V_40 ;
void T_8 * V_231 ;
T_2 V_131 ;
V_6 V_232 , V_136 ;
int V_124 ;
V_124 = F_137 ( V_228 , 0 , & V_230 ) ;
if ( V_124 ) {
F_93 ( L_18 , V_228 -> V_145 ) ;
return - V_161 ;
}
V_231 = F_138 ( V_230 . V_233 , F_139 ( & V_230 ) ) ;
if ( ! V_231 ) {
F_93 ( L_19 , V_228 -> V_145 ) ;
return - V_106 ;
}
V_131 = F_25 ( V_231 + V_234 ) & V_235 ;
if ( V_131 != 0x30 && V_131 != 0x40 ) {
F_93 ( L_20 , V_228 -> V_145 ) ;
V_124 = - V_236 ;
goto V_237;
}
V_124 = F_135 ( V_231 ) ;
if ( V_124 ) {
F_93 ( L_21 ,
V_228 -> V_145 ) ;
goto V_237;
}
F_68 ( L_22 , V_228 -> V_145 ) ;
V_40 = F_66 ( sizeof( * V_40 ) , V_105 ) ;
if ( ! V_40 ) {
V_124 = - V_106 ;
goto V_237;
}
F_140 ( & V_40 -> V_64 ) ;
F_108 ( & V_40 -> V_196 ) ;
F_108 ( & V_40 -> V_197 ) ;
V_40 -> V_46 = V_231 ;
V_40 -> V_94 = V_230 . V_233 ;
V_40 -> V_143 . V_144 = V_228 ;
V_40 -> V_195 = ( ( F_25 ( V_231 + V_140 ) >> 4 ) & 0xf ) + 1 ;
V_40 -> V_42 = F_66 ( V_238 , V_105 ) ;
if ( ! V_40 -> V_42 ) {
V_124 = - V_106 ;
goto V_239;
}
V_40 -> V_45 = V_40 -> V_42 ;
V_124 = F_87 ( V_40 ) ;
if ( V_124 )
goto V_240;
V_124 = F_96 ( V_40 ) ;
if ( V_124 )
goto V_241;
V_232 = ( F_15 ( V_40 -> V_42 ) |
V_242 |
V_243 |
( V_238 / V_153 - 1 ) |
V_244 ) ;
F_95 ( V_232 , V_40 -> V_46 + V_245 ) ;
V_136 = F_88 ( V_40 -> V_46 + V_245 ) ;
if ( ( V_136 ^ V_232 ) & V_246 ) {
if ( ! ( V_136 & V_246 ) ) {
V_232 &= ~ ( V_246 |
V_247 ) ;
V_232 |= V_248 ;
F_95 ( V_232 , V_40 -> V_46 + V_245 ) ;
}
F_68 ( L_23 ) ;
V_40 -> V_52 |= V_53 ;
}
F_95 ( 0 , V_40 -> V_46 + V_51 ) ;
F_31 ( V_225 , V_40 -> V_46 + V_223 ) ;
if ( F_141 ( V_40 -> V_143 . V_144 , L_24 ) ) {
V_40 -> V_208 = F_142 ( NULL , & V_249 , V_40 ) ;
if ( ! V_40 -> V_208 ) {
V_124 = - V_106 ;
goto V_241;
}
V_40 -> V_208 -> V_212 = V_212 ;
V_40 -> V_143 . V_208 = F_143 ( V_228 ,
& V_250 ,
V_40 -> V_208 ) ;
if ( ! V_40 -> V_143 . V_208 ) {
V_124 = - V_106 ;
goto V_251;
}
V_124 = F_144 ( & V_40 -> V_143 ) ;
if ( V_124 )
goto V_251;
}
F_71 ( & V_186 ) ;
F_109 ( & V_40 -> V_196 , & V_252 ) ;
F_74 ( & V_186 ) ;
return 0 ;
V_251:
if ( V_40 -> V_143 . V_208 )
F_145 ( V_40 -> V_143 . V_208 ) ;
if ( V_40 -> V_208 )
F_145 ( V_40 -> V_208 ) ;
V_241:
F_85 ( V_40 ) ;
V_240:
F_80 ( V_40 -> V_42 ) ;
V_239:
F_80 ( V_40 ) ;
V_237:
F_146 ( V_231 ) ;
F_79 ( L_25 , V_228 -> V_145 , V_124 ) ;
return V_124 ;
}
static bool F_147 ( void )
{
return ! ! ( F_25 ( F_98 () + V_189 ) & V_253 ) ;
}
int F_148 ( void )
{
if ( ! F_149 ( & V_252 ) ) {
if ( ! F_147 () ) {
F_68 ( L_26 , F_100 () ) ;
return - V_161 ;
}
F_97 () ;
F_102 () ;
}
return 0 ;
}
int F_150 ( struct V_227 * V_228 , struct V_254 * V_254 ,
struct V_207 * V_255 )
{
struct V_227 * V_217 ;
for ( V_217 = F_151 ( V_228 , V_256 ) ; V_217 ;
V_217 = F_151 ( V_217 , V_256 ) ) {
F_136 ( V_217 , V_255 ) ;
}
if ( F_149 ( & V_252 ) ) {
F_93 ( L_27 ) ;
return - V_161 ;
}
V_77 = V_254 ;
V_257 = V_228 ;
F_81 () ;
F_65 ( V_254 -> V_102 ) ;
return 0 ;
}
