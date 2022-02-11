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
unsigned int V_87 = F_54 ( V_85 , V_88 ) ;
struct V_2 * V_3 = F_48 ( V_75 ) ;
struct V_1 * V_89 ;
T_1 V_16 = F_47 ( V_75 ) ;
if ( V_87 >= V_90 )
return - V_91 ;
V_89 = & V_3 -> V_6 -> V_7 [ V_87 ] ;
F_44 ( V_3 , V_89 , V_16 ) ;
V_3 -> V_8 . V_9 [ V_16 ] = V_87 ;
return V_92 ;
}
static void F_55 ( struct V_74 * V_75 , struct V_93 * V_94 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
struct V_5 * V_6 ;
V_15 V_95 ;
V_6 = V_3 -> V_6 ;
V_95 = V_6 -> V_96 + V_97 ;
V_94 -> V_98 = V_95 & ( ( 1UL << 32 ) - 1 ) ;
V_94 -> V_99 = V_95 >> 32 ;
V_94 -> V_100 = F_47 ( V_75 ) ;
}
static int F_56 ( int V_101 )
{
return ( V_101 - 8192 ) >> V_102 ;
}
static int F_57 ( int V_103 )
{
return ( V_103 << V_102 ) + 8192 ;
}
static int T_6 F_58 ( T_1 V_104 )
{
V_105 = F_56 ( 1UL << V_104 ) ;
V_106 = F_59 ( F_60 ( V_105 ) * sizeof( long ) ,
V_107 ) ;
if ( ! V_106 ) {
V_105 = 0 ;
return - V_108 ;
}
F_61 ( L_5 , ( int ) V_105 ) ;
return 0 ;
}
static unsigned long * F_62 ( int V_109 , int * V_51 , int * V_110 )
{
unsigned long * V_111 = NULL ;
int V_112 ;
int V_113 ;
int V_114 ;
V_113 = F_63 ( V_109 , V_115 ) ;
F_64 ( & V_116 ) ;
do {
V_112 = F_65 ( V_106 , V_105 ,
0 , V_113 , 0 ) ;
if ( V_112 < V_105 )
break;
V_113 -- ;
} while ( V_113 > 0 );
if ( ! V_113 )
goto V_117;
V_111 = F_59 ( F_60 ( V_113 * V_115 ) * sizeof ( long ) ,
V_118 ) ;
if ( ! V_111 )
goto V_117;
for ( V_114 = 0 ; V_114 < V_113 ; V_114 ++ )
F_66 ( V_112 + V_114 , V_106 ) ;
* V_51 = F_57 ( V_112 ) ;
* V_110 = V_113 * V_115 ;
V_117:
F_67 ( & V_116 ) ;
if ( ! V_111 )
* V_51 = * V_110 = 0 ;
return V_111 ;
}
static void F_68 ( struct V_119 * V_120 )
{
int V_51 = V_120 -> V_77 ;
int V_110 = V_120 -> V_121 ;
int V_101 ;
F_64 ( & V_116 ) ;
for ( V_101 = V_51 ; V_101 < ( V_51 + V_110 ) ; V_101 += V_115 ) {
int V_103 = F_56 ( V_101 ) ;
F_69 ( V_103 > V_105 ) ;
if ( F_70 ( V_103 , V_106 ) ) {
F_71 ( V_103 , V_106 ) ;
} else {
F_72 ( L_6 , V_103 ) ;
}
}
F_67 ( & V_116 ) ;
F_73 ( V_120 -> V_122 ) ;
F_73 ( V_120 -> V_9 ) ;
}
static int T_6 F_74 ( void )
{
T_7 V_123 ;
V_80 -> V_81 = F_75 ( V_124 ,
F_76 ( V_125 ) ) ;
if ( ! V_80 -> V_81 ) {
F_72 ( L_7 ) ;
return - V_108 ;
}
V_123 = F_77 ( V_80 -> V_81 ) ;
F_61 ( L_8 , & V_123 ) ;
memset ( F_50 ( V_80 -> V_81 ) ,
V_126 | V_127 ,
V_125 ) ;
F_34 ( F_50 ( V_80 -> V_81 ) , V_125 ) ;
return 0 ;
}
static void F_78 ( struct V_5 * V_6 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < V_128 ; V_114 ++ ) {
if ( V_6 -> V_129 [ V_114 ] . V_51 ) {
F_79 ( ( unsigned long ) V_6 -> V_129 [ V_114 ] . V_51 ,
V_6 -> V_129 [ V_114 ] . V_130 ) ;
V_6 -> V_129 [ V_114 ] . V_51 = NULL ;
}
}
}
static int F_80 ( const char * V_131 , struct V_5 * V_6 )
{
int V_132 ;
int V_114 ;
int V_133 = V_134 ;
V_15 V_135 = V_136 ;
V_15 V_137 ;
V_15 V_138 ;
T_1 V_139 ;
if ( V_6 -> V_57 & V_140 ) {
V_137 = 0 ;
V_139 = 0x14 ;
} else {
V_137 = V_141 ;
V_138 = F_81 ( V_6 -> V_51 + V_142 ) ;
V_139 = F_82 ( V_138 ) ;
}
for ( V_114 = 0 ; V_114 < V_128 ; V_114 ++ ) {
V_15 V_143 = F_81 ( V_6 -> V_51 + V_144 + V_114 * 8 ) ;
V_15 type = F_83 ( V_143 ) ;
V_15 V_145 = F_84 ( V_143 ) ;
int V_130 = F_76 ( V_133 ) ;
int F_75 ;
V_15 V_146 ;
void * V_51 ;
if ( type == V_147 )
continue;
if ( type == V_148 ) {
V_130 = F_85 ( F_76 ( ( 1UL << V_139 ) * V_145 ) ,
V_130 ) ;
if ( V_130 >= V_149 ) {
V_130 = V_149 - 1 ;
F_86 ( L_9 ,
V_131 , V_130 ) ;
}
}
V_150:
F_75 = ( F_87 ( V_130 ) / V_133 ) ;
if ( F_75 > V_151 ) {
F_75 = V_151 ;
V_130 = F_76 ( V_151 * V_133 ) ;
F_86 ( L_10 ,
V_131 , V_130 , F_75 ) ;
}
V_51 = ( void * ) F_88 ( V_107 | V_152 , V_130 ) ;
if ( ! V_51 ) {
V_132 = - V_108 ;
goto V_153;
}
V_6 -> V_129 [ V_114 ] . V_51 = V_51 ;
V_6 -> V_129 [ V_114 ] . V_130 = V_130 ;
V_154:
V_143 = ( F_16 ( V_51 ) |
( type << V_155 ) |
( ( V_145 - 1 ) << V_156 ) |
V_137 |
V_135 |
V_157 ) ;
switch ( V_133 ) {
case V_158 :
V_143 |= V_159 ;
break;
case V_160 :
V_143 |= V_161 ;
break;
case V_134 :
V_143 |= V_162 ;
break;
}
V_143 |= F_75 - 1 ;
F_89 ( V_143 , V_6 -> V_51 + V_144 + V_114 * 8 ) ;
V_146 = F_81 ( V_6 -> V_51 + V_144 + V_114 * 8 ) ;
if ( ( V_143 ^ V_146 ) & V_163 ) {
V_135 = V_146 & V_163 ;
if ( ! V_135 ) {
V_137 = V_164 ;
F_34 ( V_51 , F_87 ( V_130 ) ) ;
}
goto V_154;
}
if ( ( V_143 ^ V_146 ) & V_165 ) {
F_79 ( ( unsigned long ) V_51 , V_130 ) ;
V_6 -> V_129 [ V_114 ] . V_51 = NULL ;
switch ( V_133 ) {
case V_160 :
V_133 = V_158 ;
goto V_150;
case V_134 :
V_133 = V_160 ;
goto V_150;
}
}
if ( V_143 != V_146 ) {
F_72 ( L_11 ,
V_131 , V_114 ,
( unsigned long ) V_143 , ( unsigned long ) V_146 ) ;
V_132 = - V_166 ;
goto V_153;
}
F_61 ( L_12 ,
( int ) ( F_87 ( V_130 ) / V_145 ) ,
V_167 [ type ] ,
( unsigned long ) F_16 ( V_51 ) ,
V_133 / V_168 , ( int ) V_135 >> V_169 ) ;
}
return 0 ;
V_153:
F_78 ( V_6 ) ;
return V_132 ;
}
static int F_90 ( struct V_5 * V_6 )
{
V_6 -> V_7 = F_59 ( V_90 * sizeof( * V_6 -> V_7 ) ,
V_107 ) ;
if ( ! V_6 -> V_7 )
return - V_108 ;
return 0 ;
}
static void F_91 ( void )
{
void T_8 * V_170 = F_92 () ;
struct V_171 * V_172 ;
V_15 V_143 , V_146 ;
V_172 = F_93 () -> V_172 ;
if ( ! V_172 ) {
T_7 V_123 ;
V_172 = F_75 ( V_124 | V_152 ,
F_76 ( F_85 ( V_173 , V_134 ) ) ) ;
if ( ! V_172 ) {
F_72 ( L_13 ,
F_94 () ) ;
return;
}
F_34 ( F_50 ( V_172 ) , V_173 ) ;
V_123 = F_77 ( V_172 ) ;
F_61 ( L_14 ,
F_94 () , & V_123 ) ;
F_93 () -> V_172 = V_172 ;
}
V_143 = F_26 ( V_170 + V_174 ) ;
V_143 &= ~ V_175 ;
F_32 ( V_143 , V_170 + V_174 ) ;
F_35 ( V_176 ) ;
V_143 = ( F_77 ( V_80 -> V_81 ) |
V_177 |
V_178 |
( ( V_179 - 1 ) & V_180 ) ) ;
F_89 ( V_143 , V_170 + V_181 ) ;
V_146 = F_81 ( V_170 + V_181 ) ;
if ( ( V_146 ^ V_143 ) & V_182 ) {
if ( ! ( V_146 & V_182 ) ) {
V_143 &= ~ ( V_182 |
V_183 ) ;
V_143 |= V_184 ;
F_89 ( V_143 , V_170 + V_181 ) ;
}
F_95 ( L_15 ) ;
V_80 -> V_57 |= V_83 ;
}
V_143 = ( F_77 ( V_172 ) |
V_185 |
V_186 ) ;
F_89 ( V_143 , V_170 + V_187 ) ;
V_146 = F_81 ( V_170 + V_187 ) ;
if ( ! ( V_146 & V_188 ) ) {
V_143 &= ~ ( V_188 |
V_189 ) ;
V_143 |= V_190 ;
F_89 ( V_143 , V_170 + V_187 ) ;
}
V_143 = F_26 ( V_170 + V_174 ) ;
V_143 |= V_175 ;
F_32 ( V_143 , V_170 + V_174 ) ;
F_35 ( V_176 ) ;
}
static void F_96 ( void )
{
struct V_5 * V_6 ;
int V_87 ;
F_64 ( & V_191 ) ;
V_87 = F_94 () ;
F_97 (its, &its_nodes, entry) {
V_15 V_192 ;
if ( F_81 ( V_6 -> V_51 + V_142 ) & V_193 ) {
V_192 = F_93 () -> V_96 ;
} else {
V_192 = F_81 ( F_92 () + V_194 ) ;
V_192 = F_98 ( V_192 ) << 16 ;
}
V_6 -> V_7 [ V_87 ] . V_35 = V_192 ;
V_6 -> V_7 [ V_87 ] . V_34 = V_87 ;
F_42 ( V_6 , & V_6 -> V_7 [ V_87 ] , 1 ) ;
F_46 ( V_6 , & V_6 -> V_7 [ V_87 ] ) ;
}
F_67 ( & V_191 ) ;
}
static struct V_2 * F_99 ( struct V_5 * V_6 , T_1 V_195 )
{
struct V_2 * V_3 = NULL , * V_146 ;
unsigned long V_57 ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_97 (tmp, &its->its_device_list, entry) {
if ( V_146 -> V_31 == V_195 ) {
V_3 = V_146 ;
break;
}
}
F_39 ( & V_6 -> V_69 , V_57 ) ;
return V_3 ;
}
static struct V_2 * F_100 ( struct V_5 * V_6 , T_1 V_195 ,
int V_196 )
{
struct V_2 * V_26 ;
unsigned long * V_122 ;
unsigned long V_57 ;
T_3 * V_9 = NULL ;
void * V_28 ;
int V_77 ;
int V_121 ;
int V_27 ;
int V_197 ;
V_26 = F_59 ( sizeof( * V_26 ) , V_107 ) ;
V_27 = F_85 ( 2UL , F_101 ( V_196 ) ) ;
V_197 = V_27 * V_6 -> V_198 ;
V_197 = F_85 ( V_197 , V_29 ) + V_29 - 1 ;
V_28 = F_59 ( V_197 , V_107 ) ;
V_122 = F_62 ( V_196 , & V_77 , & V_121 ) ;
if ( V_122 )
V_9 = F_59 ( sizeof( * V_9 ) * V_121 , V_107 ) ;
if ( ! V_26 || ! V_28 || ! V_122 || ! V_9 ) {
F_73 ( V_26 ) ;
F_73 ( V_28 ) ;
F_73 ( V_122 ) ;
F_73 ( V_9 ) ;
return NULL ;
}
F_34 ( V_28 , V_197 ) ;
V_26 -> V_6 = V_6 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_8 . V_122 = V_122 ;
V_26 -> V_8 . V_9 = V_9 ;
V_26 -> V_8 . V_77 = V_77 ;
V_26 -> V_8 . V_121 = V_121 ;
V_26 -> V_31 = V_195 ;
F_102 ( & V_26 -> V_199 ) ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_103 ( & V_26 -> V_199 , & V_6 -> V_200 ) ;
F_39 ( & V_6 -> V_69 , V_57 ) ;
F_41 ( V_26 , 1 ) ;
return V_26 ;
}
static void F_104 ( struct V_2 * V_3 )
{
unsigned long V_57 ;
F_38 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_105 ( & V_3 -> V_199 ) ;
F_39 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_73 ( V_3 -> V_28 ) ;
F_73 ( V_3 ) ;
}
static int F_106 ( struct V_2 * V_26 , T_5 * V_76 )
{
int V_201 ;
V_201 = F_107 ( V_26 -> V_8 . V_122 ,
V_26 -> V_8 . V_121 ) ;
if ( V_201 == V_26 -> V_8 . V_121 )
return - V_202 ;
* V_76 = V_26 -> V_8 . V_77 + V_201 ;
F_66 ( V_201 , V_26 -> V_8 . V_122 ) ;
return 0 ;
}
static int F_108 ( struct V_203 * V_204 , struct V_205 * V_26 ,
int V_206 , T_9 * V_207 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_208 * V_209 ;
T_1 V_195 ;
V_195 = V_207 -> V_210 [ 0 ] . V_211 ;
V_209 = F_109 ( V_204 ) ;
V_6 = V_209 -> V_100 ;
V_3 = F_99 ( V_6 , V_195 ) ;
if ( V_3 ) {
F_110 ( L_16 , V_195 ) ;
goto V_117;
}
V_3 = F_100 ( V_6 , V_195 , V_206 ) ;
if ( ! V_3 )
return - V_108 ;
F_110 ( L_17 , V_206 , F_15 ( V_206 ) ) ;
V_117:
V_207 -> V_210 [ 0 ] . V_46 = V_3 ;
return 0 ;
}
static int F_111 ( struct V_203 * V_204 ,
unsigned int V_212 ,
T_5 V_76 )
{
struct V_213 V_214 ;
if ( F_112 ( V_204 -> V_215 ) ) {
V_214 . V_216 = V_204 -> V_215 -> V_216 ;
V_214 . V_217 = 3 ;
V_214 . V_218 [ 0 ] = V_219 ;
V_214 . V_218 [ 1 ] = V_76 ;
V_214 . V_218 [ 2 ] = V_220 ;
} else {
return - V_91 ;
}
return F_113 ( V_204 , V_212 , 1 , & V_214 ) ;
}
static int F_114 ( struct V_203 * V_204 , unsigned int V_212 ,
unsigned int V_109 , void * args )
{
T_9 * V_207 = args ;
struct V_2 * V_3 = V_207 -> V_210 [ 0 ] . V_46 ;
T_5 V_76 ;
int V_132 ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_109 ; V_114 ++ ) {
V_132 = F_106 ( V_3 , & V_76 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_111 ( V_204 , V_212 + V_114 , V_76 ) ;
if ( V_132 )
return V_132 ;
F_115 ( V_204 , V_212 + V_114 ,
V_76 , & V_221 , V_3 ) ;
F_110 ( L_18 ,
( int ) ( V_76 - V_3 -> V_8 . V_77 ) ,
( int ) V_76 , V_212 + V_114 ) ;
}
return 0 ;
}
static void F_116 ( struct V_203 * V_204 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
V_3 -> V_8 . V_9 [ V_4 ] = F_117 ( V_88 ) ;
F_43 ( V_3 , V_75 -> V_76 , V_4 ) ;
}
static void F_118 ( struct V_203 * V_204 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
F_45 ( V_3 , V_4 ) ;
}
static void F_119 ( struct V_203 * V_204 , unsigned int V_212 ,
unsigned int V_109 )
{
struct V_74 * V_75 = F_120 ( V_204 , V_212 ) ;
struct V_2 * V_3 = F_48 ( V_75 ) ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_109 ; V_114 ++ ) {
struct V_74 * V_100 = F_120 ( V_204 ,
V_212 + V_114 ) ;
T_1 V_4 = F_47 ( V_100 ) ;
F_71 ( V_4 , V_3 -> V_8 . V_122 ) ;
F_121 ( V_100 ) ;
}
if ( F_122 ( V_3 -> V_8 . V_122 ,
V_3 -> V_8 . V_121 ) ) {
F_68 ( & V_3 -> V_8 ) ;
F_41 ( V_3 , 0 ) ;
F_104 ( V_3 ) ;
}
F_123 ( V_204 , V_212 , V_109 ) ;
}
static int F_124 ( void T_8 * V_51 )
{
T_1 V_54 = 1000000 ;
T_1 V_143 ;
V_143 = F_26 ( V_51 + V_222 ) ;
if ( V_143 & V_223 )
return 0 ;
V_143 &= ~ V_224 ;
F_32 ( V_143 , V_51 + V_222 ) ;
while ( 1 ) {
V_143 = F_26 ( V_51 + V_222 ) ;
if ( V_143 & V_223 )
return 0 ;
V_54 -- ;
if ( ! V_54 )
return - V_225 ;
F_29 () ;
F_30 ( 1 ) ;
}
}
static void T_10 F_125 ( void * V_100 )
{
struct V_5 * V_6 = V_100 ;
V_6 -> V_57 |= V_140 ;
}
static void F_126 ( struct V_5 * V_6 )
{
T_1 V_226 = F_26 ( V_6 -> V_51 + V_227 ) ;
F_127 ( V_226 , V_228 , V_6 ) ;
}
static int T_6 F_128 ( struct V_229 * V_230 ,
struct V_203 * V_215 )
{
struct V_231 V_232 ;
struct V_5 * V_6 ;
void T_8 * V_233 ;
struct V_203 * V_234 ;
T_1 V_143 ;
V_15 V_235 , V_146 ;
int V_132 ;
V_132 = F_129 ( V_230 , 0 , & V_232 ) ;
if ( V_132 ) {
F_86 ( L_19 , V_230 -> V_236 ) ;
return - V_166 ;
}
V_233 = F_130 ( V_232 . V_237 , F_131 ( & V_232 ) ) ;
if ( ! V_233 ) {
F_86 ( L_20 , V_230 -> V_236 ) ;
return - V_108 ;
}
V_143 = F_26 ( V_233 + V_238 ) & V_239 ;
if ( V_143 != 0x30 && V_143 != 0x40 ) {
F_86 ( L_21 , V_230 -> V_236 ) ;
V_132 = - V_240 ;
goto V_241;
}
V_132 = F_124 ( V_233 ) ;
if ( V_132 ) {
F_86 ( L_22 ,
V_230 -> V_236 ) ;
goto V_241;
}
F_61 ( L_23 , V_230 -> V_236 ) ;
V_6 = F_59 ( sizeof( * V_6 ) , V_107 ) ;
if ( ! V_6 ) {
V_132 = - V_108 ;
goto V_241;
}
F_132 ( & V_6 -> V_69 ) ;
F_102 ( & V_6 -> V_199 ) ;
F_102 ( & V_6 -> V_200 ) ;
V_6 -> V_51 = V_233 ;
V_6 -> V_96 = V_232 . V_237 ;
V_6 -> V_198 = ( ( F_26 ( V_233 + V_142 ) >> 4 ) & 0xf ) + 1 ;
V_6 -> V_47 = F_59 ( V_242 , V_107 ) ;
if ( ! V_6 -> V_47 ) {
V_132 = - V_108 ;
goto V_243;
}
V_6 -> V_50 = V_6 -> V_47 ;
F_126 ( V_6 ) ;
V_132 = F_80 ( V_230 -> V_236 , V_6 ) ;
if ( V_132 )
goto V_244;
V_132 = F_90 ( V_6 ) ;
if ( V_132 )
goto V_245;
V_235 = ( F_16 ( V_6 -> V_47 ) |
V_246 |
V_247 |
( V_242 / V_158 - 1 ) |
V_248 ) ;
F_89 ( V_235 , V_6 -> V_51 + V_249 ) ;
V_146 = F_81 ( V_6 -> V_51 + V_249 ) ;
if ( ( V_146 ^ V_235 ) & V_250 ) {
if ( ! ( V_146 & V_250 ) ) {
V_235 &= ~ ( V_250 |
V_251 ) ;
V_235 |= V_252 ;
F_89 ( V_235 , V_6 -> V_51 + V_249 ) ;
}
F_61 ( L_24 ) ;
V_6 -> V_57 |= V_58 ;
}
F_89 ( 0 , V_6 -> V_51 + V_56 ) ;
F_32 ( V_224 , V_6 -> V_51 + V_222 ) ;
if ( F_133 ( V_230 , L_25 ) ) {
struct V_208 * V_207 ;
V_207 = F_59 ( sizeof( * V_207 ) , V_107 ) ;
if ( ! V_207 ) {
V_132 = - V_108 ;
goto V_245;
}
V_234 = F_134 ( V_230 , & V_253 , V_6 ) ;
if ( ! V_234 ) {
V_132 = - V_108 ;
F_73 ( V_207 ) ;
goto V_245;
}
V_234 -> V_215 = V_215 ;
V_234 -> V_254 = V_255 ;
V_207 -> V_256 = & V_257 ;
V_207 -> V_100 = V_6 ;
V_234 -> V_258 = V_207 ;
}
F_64 ( & V_191 ) ;
F_103 ( & V_6 -> V_199 , & V_259 ) ;
F_67 ( & V_191 ) ;
return 0 ;
V_245:
F_78 ( V_6 ) ;
V_244:
F_73 ( V_6 -> V_47 ) ;
V_243:
F_73 ( V_6 ) ;
V_241:
F_135 ( V_233 ) ;
F_72 ( L_26 , V_230 -> V_236 , V_132 ) ;
return V_132 ;
}
static bool F_136 ( void )
{
return ! ! ( F_26 ( F_92 () + V_194 ) & V_260 ) ;
}
int F_137 ( void )
{
if ( ! F_138 ( & V_259 ) ) {
if ( ! F_136 () ) {
F_61 ( L_27 , F_94 () ) ;
return - V_166 ;
}
F_91 () ;
F_96 () ;
}
return 0 ;
}
int T_6 F_139 ( struct V_229 * V_230 , struct V_261 * V_261 ,
struct V_203 * V_262 )
{
struct V_229 * V_263 ;
for ( V_263 = F_140 ( V_230 , V_264 ) ; V_263 ;
V_263 = F_140 ( V_263 , V_264 ) ) {
F_128 ( V_263 , V_262 ) ;
}
if ( F_138 ( & V_259 ) ) {
F_86 ( L_28 ) ;
return - V_166 ;
}
V_80 = V_261 ;
F_74 () ;
F_58 ( V_261 -> V_104 ) ;
return 0 ;
}
