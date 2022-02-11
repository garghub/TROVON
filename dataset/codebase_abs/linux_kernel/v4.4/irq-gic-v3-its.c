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
static void F_53 ( struct V_74 * V_75 )
{
F_54 ( V_75 -> V_76 ) ;
}
static int F_55 ( struct V_74 * V_75 , const struct V_84 * V_85 ,
bool V_86 )
{
unsigned int V_87 = F_56 ( V_85 , V_88 ) ;
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
static void F_57 ( struct V_74 * V_75 , struct V_93 * V_94 )
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
static int F_58 ( int V_101 )
{
return ( V_101 - 8192 ) >> V_102 ;
}
static int F_59 ( int V_103 )
{
return ( V_103 << V_102 ) + 8192 ;
}
static int F_60 ( T_1 V_104 )
{
V_105 = F_58 ( 1UL << V_104 ) ;
V_106 = F_61 ( F_62 ( V_105 ) * sizeof( long ) ,
V_107 ) ;
if ( ! V_106 ) {
V_105 = 0 ;
return - V_108 ;
}
F_63 ( L_5 , ( int ) V_105 ) ;
return 0 ;
}
static unsigned long * F_64 ( int V_109 , int * V_51 , int * V_110 )
{
unsigned long * V_111 = NULL ;
int V_112 ;
int V_113 ;
int V_114 ;
V_113 = F_65 ( V_109 , V_115 ) ;
F_66 ( & V_116 ) ;
do {
V_112 = F_67 ( V_106 , V_105 ,
0 , V_113 , 0 ) ;
if ( V_112 < V_105 )
break;
V_113 -- ;
} while ( V_113 > 0 );
if ( ! V_113 )
goto V_117;
V_111 = F_61 ( F_62 ( V_113 * V_115 ) * sizeof ( long ) ,
V_118 ) ;
if ( ! V_111 )
goto V_117;
for ( V_114 = 0 ; V_114 < V_113 ; V_114 ++ )
F_68 ( V_112 + V_114 , V_106 ) ;
* V_51 = F_59 ( V_112 ) ;
* V_110 = V_113 * V_115 ;
V_117:
F_69 ( & V_116 ) ;
if ( ! V_111 )
* V_51 = * V_110 = 0 ;
return V_111 ;
}
static void F_70 ( struct V_119 * V_120 )
{
int V_51 = V_120 -> V_77 ;
int V_110 = V_120 -> V_121 ;
int V_101 ;
F_66 ( & V_116 ) ;
for ( V_101 = V_51 ; V_101 < ( V_51 + V_110 ) ; V_101 += V_115 ) {
int V_103 = F_58 ( V_101 ) ;
F_71 ( V_103 > V_105 ) ;
if ( F_72 ( V_103 , V_106 ) ) {
F_73 ( V_103 , V_106 ) ;
} else {
F_74 ( L_6 , V_103 ) ;
}
}
F_69 ( & V_116 ) ;
F_75 ( V_120 -> V_122 ) ;
F_75 ( V_120 -> V_9 ) ;
}
static int T_6 F_76 ( void )
{
T_7 V_123 ;
V_80 -> V_81 = F_77 ( V_124 ,
F_78 ( V_125 ) ) ;
if ( ! V_80 -> V_81 ) {
F_74 ( L_7 ) ;
return - V_108 ;
}
V_123 = F_79 ( V_80 -> V_81 ) ;
F_63 ( L_8 , & V_123 ) ;
memset ( F_50 ( V_80 -> V_81 ) ,
V_126 | V_127 ,
V_125 ) ;
F_34 ( F_50 ( V_80 -> V_81 ) , V_125 ) ;
return 0 ;
}
static void F_80 ( struct V_5 * V_6 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < V_128 ; V_114 ++ ) {
if ( V_6 -> V_129 [ V_114 ] ) {
F_81 ( ( unsigned long ) V_6 -> V_129 [ V_114 ] ) ;
V_6 -> V_129 [ V_114 ] = NULL ;
}
}
}
static int F_82 ( const char * V_130 , struct V_5 * V_6 )
{
int V_131 ;
int V_114 ;
int V_132 = V_133 ;
V_15 V_134 = V_135 ;
V_15 V_136 ;
V_15 V_137 ;
T_1 V_138 ;
if ( V_6 -> V_57 & V_139 ) {
V_136 = 0 ;
V_138 = 0x14 ;
} else {
V_136 = V_140 ;
V_137 = F_83 ( V_6 -> V_51 + V_141 ) ;
V_138 = F_84 ( V_137 ) ;
}
for ( V_114 = 0 ; V_114 < V_128 ; V_114 ++ ) {
V_15 V_142 = F_83 ( V_6 -> V_51 + V_143 + V_114 * 8 ) ;
V_15 type = F_85 ( V_142 ) ;
V_15 V_144 = F_86 ( V_142 ) ;
int V_145 = F_78 ( V_132 ) ;
int V_146 ;
int F_77 ;
V_15 V_147 ;
void * V_51 ;
if ( type == V_148 )
continue;
if ( type == V_149 ) {
V_145 = F_87 ( F_78 ( ( 1UL << V_138 ) * V_144 ) ,
V_145 ) ;
if ( V_145 >= V_150 ) {
V_145 = V_150 - 1 ;
F_88 ( L_9 ,
V_130 , V_145 ) ;
}
}
V_146 = ( 1 << V_145 ) * V_151 ;
F_77 = ( V_146 / V_132 ) ;
if ( F_77 > V_152 ) {
F_77 = V_152 ;
V_145 = F_78 ( V_152 * V_132 ) ;
F_88 ( L_10 ,
V_130 , V_145 , F_77 ) ;
}
V_51 = ( void * ) F_89 ( V_107 | V_153 , V_145 ) ;
if ( ! V_51 ) {
V_131 = - V_108 ;
goto V_154;
}
V_6 -> V_129 [ V_114 ] = V_51 ;
V_155:
V_142 = ( F_16 ( V_51 ) |
( type << V_156 ) |
( ( V_144 - 1 ) << V_157 ) |
V_136 |
V_134 |
V_158 ) ;
switch ( V_132 ) {
case V_159 :
V_142 |= V_160 ;
break;
case V_161 :
V_142 |= V_162 ;
break;
case V_133 :
V_142 |= V_163 ;
break;
}
V_142 |= F_77 - 1 ;
F_90 ( V_142 , V_6 -> V_51 + V_143 + V_114 * 8 ) ;
V_147 = F_83 ( V_6 -> V_51 + V_143 + V_114 * 8 ) ;
if ( ( V_142 ^ V_147 ) & V_164 ) {
V_134 = V_147 & V_164 ;
if ( ! V_134 ) {
V_136 = V_165 ;
F_34 ( V_51 , V_146 ) ;
}
goto V_155;
}
if ( ( V_142 ^ V_147 ) & V_166 ) {
switch ( V_132 ) {
case V_161 :
V_132 = V_159 ;
goto V_155;
case V_133 :
V_132 = V_161 ;
goto V_155;
}
}
if ( V_142 != V_147 ) {
F_74 ( L_11 ,
V_130 , V_114 ,
( unsigned long ) V_142 , ( unsigned long ) V_147 ) ;
V_131 = - V_167 ;
goto V_154;
}
F_63 ( L_12 ,
( int ) ( V_146 / V_144 ) ,
V_168 [ type ] ,
( unsigned long ) F_16 ( V_51 ) ,
V_132 / V_169 , ( int ) V_134 >> V_170 ) ;
}
return 0 ;
V_154:
F_80 ( V_6 ) ;
return V_131 ;
}
static int F_91 ( struct V_5 * V_6 )
{
V_6 -> V_7 = F_61 ( V_90 * sizeof( * V_6 -> V_7 ) ,
V_107 ) ;
if ( ! V_6 -> V_7 )
return - V_108 ;
return 0 ;
}
static void F_92 ( void )
{
void T_8 * V_171 = F_93 () ;
struct V_172 * V_173 ;
V_15 V_142 , V_147 ;
V_173 = F_94 () -> V_173 ;
if ( ! V_173 ) {
T_7 V_123 ;
V_173 = F_77 ( V_124 | V_153 ,
F_78 ( F_87 ( V_174 , V_133 ) ) ) ;
if ( ! V_173 ) {
F_74 ( L_13 ,
F_95 () ) ;
return;
}
F_34 ( F_50 ( V_173 ) , V_174 ) ;
V_123 = F_79 ( V_173 ) ;
F_63 ( L_14 ,
F_95 () , & V_123 ) ;
F_94 () -> V_173 = V_173 ;
}
V_142 = F_26 ( V_171 + V_175 ) ;
V_142 &= ~ V_176 ;
F_32 ( V_142 , V_171 + V_175 ) ;
F_35 ( V_177 ) ;
V_142 = ( F_79 ( V_80 -> V_81 ) |
V_178 |
V_179 |
( ( V_180 - 1 ) & V_181 ) ) ;
F_90 ( V_142 , V_171 + V_182 ) ;
V_147 = F_83 ( V_171 + V_182 ) ;
if ( ( V_147 ^ V_142 ) & V_183 ) {
if ( ! ( V_147 & V_183 ) ) {
V_142 &= ~ ( V_183 |
V_184 ) ;
V_142 |= V_185 ;
F_90 ( V_142 , V_171 + V_182 ) ;
}
F_96 ( L_15 ) ;
V_80 -> V_57 |= V_83 ;
}
V_142 = ( F_79 ( V_173 ) |
V_186 |
V_187 ) ;
F_90 ( V_142 , V_171 + V_188 ) ;
V_147 = F_83 ( V_171 + V_188 ) ;
if ( ! ( V_147 & V_189 ) ) {
V_142 &= ~ ( V_189 |
V_190 ) ;
V_142 |= V_191 ;
F_90 ( V_142 , V_171 + V_188 ) ;
}
V_142 = F_26 ( V_171 + V_175 ) ;
V_142 |= V_176 ;
F_32 ( V_142 , V_171 + V_175 ) ;
F_35 ( V_177 ) ;
}
static void F_97 ( void )
{
struct V_5 * V_6 ;
int V_87 ;
F_66 ( & V_192 ) ;
V_87 = F_95 () ;
F_98 (its, &its_nodes, entry) {
V_15 V_193 ;
if ( F_83 ( V_6 -> V_51 + V_141 ) & V_194 ) {
V_193 = F_94 () -> V_96 ;
} else {
V_193 = F_83 ( F_93 () + V_195 ) ;
V_193 = F_99 ( V_193 ) << 16 ;
}
V_6 -> V_7 [ V_87 ] . V_35 = V_193 ;
V_6 -> V_7 [ V_87 ] . V_34 = V_87 ;
F_42 ( V_6 , & V_6 -> V_7 [ V_87 ] , 1 ) ;
F_46 ( V_6 , & V_6 -> V_7 [ V_87 ] ) ;
}
F_69 ( & V_192 ) ;
}
static struct V_2 * F_100 ( struct V_5 * V_6 , T_1 V_196 )
{
struct V_2 * V_3 = NULL , * V_147 ;
unsigned long V_57 ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_98 (tmp, &its->its_device_list, entry) {
if ( V_147 -> V_31 == V_196 ) {
V_3 = V_147 ;
break;
}
}
F_39 ( & V_6 -> V_69 , V_57 ) ;
return V_3 ;
}
static struct V_2 * F_101 ( struct V_5 * V_6 , T_1 V_196 ,
int V_197 )
{
struct V_2 * V_26 ;
unsigned long * V_122 ;
unsigned long V_57 ;
T_3 * V_9 = NULL ;
void * V_28 ;
int V_77 ;
int V_121 ;
int V_27 ;
int V_198 ;
V_26 = F_61 ( sizeof( * V_26 ) , V_107 ) ;
V_27 = F_87 ( 2UL , F_102 ( V_197 ) ) ;
V_198 = V_27 * V_6 -> V_199 ;
V_198 = F_87 ( V_198 , V_29 ) + V_29 - 1 ;
V_28 = F_61 ( V_198 , V_107 ) ;
V_122 = F_64 ( V_197 , & V_77 , & V_121 ) ;
if ( V_122 )
V_9 = F_61 ( sizeof( * V_9 ) * V_121 , V_107 ) ;
if ( ! V_26 || ! V_28 || ! V_122 || ! V_9 ) {
F_75 ( V_26 ) ;
F_75 ( V_28 ) ;
F_75 ( V_122 ) ;
F_75 ( V_9 ) ;
return NULL ;
}
F_34 ( V_28 , V_198 ) ;
V_26 -> V_6 = V_6 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_8 . V_122 = V_122 ;
V_26 -> V_8 . V_9 = V_9 ;
V_26 -> V_8 . V_77 = V_77 ;
V_26 -> V_8 . V_121 = V_121 ;
V_26 -> V_31 = V_196 ;
F_103 ( & V_26 -> V_200 ) ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_104 ( & V_26 -> V_200 , & V_6 -> V_201 ) ;
F_39 ( & V_6 -> V_69 , V_57 ) ;
F_41 ( V_26 , 1 ) ;
return V_26 ;
}
static void F_105 ( struct V_2 * V_3 )
{
unsigned long V_57 ;
F_38 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_106 ( & V_3 -> V_200 ) ;
F_39 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_75 ( V_3 -> V_28 ) ;
F_75 ( V_3 ) ;
}
static int F_107 ( struct V_2 * V_26 , T_5 * V_76 )
{
int V_202 ;
V_202 = F_108 ( V_26 -> V_8 . V_122 ,
V_26 -> V_8 . V_121 ) ;
if ( V_202 == V_26 -> V_8 . V_121 )
return - V_203 ;
* V_76 = V_26 -> V_8 . V_77 + V_202 ;
F_68 ( V_202 , V_26 -> V_8 . V_122 ) ;
return 0 ;
}
static int F_109 ( struct V_204 * V_205 , struct V_206 * V_26 ,
int V_207 , T_9 * V_208 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_209 * V_210 ;
T_1 V_196 ;
V_196 = V_208 -> V_211 [ 0 ] . V_212 ;
V_210 = F_110 ( V_205 ) ;
V_6 = V_210 -> V_100 ;
V_3 = F_100 ( V_6 , V_196 ) ;
if ( V_3 ) {
F_111 ( L_16 , V_196 ) ;
goto V_117;
}
V_3 = F_101 ( V_6 , V_196 , V_207 ) ;
if ( ! V_3 )
return - V_108 ;
F_111 ( L_17 , V_207 , F_15 ( V_207 ) ) ;
V_117:
V_208 -> V_211 [ 0 ] . V_46 = V_3 ;
return 0 ;
}
static int F_112 ( struct V_204 * V_205 ,
unsigned int V_213 ,
T_5 V_76 )
{
struct V_214 V_215 ;
if ( F_113 ( V_205 -> V_216 ) ) {
V_215 . V_217 = V_205 -> V_216 -> V_217 ;
V_215 . V_218 = 3 ;
V_215 . V_219 [ 0 ] = V_220 ;
V_215 . V_219 [ 1 ] = V_76 ;
V_215 . V_219 [ 2 ] = V_221 ;
} else {
return - V_91 ;
}
return F_114 ( V_205 , V_213 , 1 , & V_215 ) ;
}
static int F_115 ( struct V_204 * V_205 , unsigned int V_213 ,
unsigned int V_109 , void * args )
{
T_9 * V_208 = args ;
struct V_2 * V_3 = V_208 -> V_211 [ 0 ] . V_46 ;
T_5 V_76 ;
int V_131 ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_109 ; V_114 ++ ) {
V_131 = F_107 ( V_3 , & V_76 ) ;
if ( V_131 )
return V_131 ;
V_131 = F_112 ( V_205 , V_213 + V_114 , V_76 ) ;
if ( V_131 )
return V_131 ;
F_116 ( V_205 , V_213 + V_114 ,
V_76 , & V_222 , V_3 ) ;
F_111 ( L_18 ,
( int ) ( V_76 - V_3 -> V_8 . V_77 ) ,
( int ) V_76 , V_213 + V_114 ) ;
}
return 0 ;
}
static void F_117 ( struct V_204 * V_205 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
V_3 -> V_8 . V_9 [ V_4 ] = F_118 ( V_88 ) ;
F_43 ( V_3 , V_75 -> V_76 , V_4 ) ;
}
static void F_119 ( struct V_204 * V_205 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
F_45 ( V_3 , V_4 ) ;
}
static void F_120 ( struct V_204 * V_205 , unsigned int V_213 ,
unsigned int V_109 )
{
struct V_74 * V_75 = F_121 ( V_205 , V_213 ) ;
struct V_2 * V_3 = F_48 ( V_75 ) ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_109 ; V_114 ++ ) {
struct V_74 * V_100 = F_121 ( V_205 ,
V_213 + V_114 ) ;
T_1 V_4 = F_47 ( V_100 ) ;
F_73 ( V_4 , V_3 -> V_8 . V_122 ) ;
F_122 ( V_100 ) ;
}
if ( F_123 ( V_3 -> V_8 . V_122 ,
V_3 -> V_8 . V_121 ) ) {
F_70 ( & V_3 -> V_8 ) ;
F_41 ( V_3 , 0 ) ;
F_105 ( V_3 ) ;
}
F_124 ( V_205 , V_213 , V_109 ) ;
}
static int F_125 ( void T_8 * V_51 )
{
T_1 V_54 = 1000000 ;
T_1 V_142 ;
V_142 = F_26 ( V_51 + V_223 ) ;
if ( V_142 & V_224 )
return 0 ;
V_142 &= ~ V_225 ;
F_32 ( V_142 , V_51 + V_223 ) ;
while ( 1 ) {
V_142 = F_26 ( V_51 + V_223 ) ;
if ( V_142 & V_224 )
return 0 ;
V_54 -- ;
if ( ! V_54 )
return - V_226 ;
F_29 () ;
F_30 ( 1 ) ;
}
}
static void T_10 F_126 ( void * V_100 )
{
struct V_5 * V_6 = V_100 ;
V_6 -> V_57 |= V_139 ;
}
static void F_127 ( struct V_5 * V_6 )
{
T_1 V_227 = F_26 ( V_6 -> V_51 + V_228 ) ;
F_128 ( V_227 , V_229 , V_6 ) ;
}
static int F_129 ( struct V_230 * V_231 , struct V_204 * V_216 )
{
struct V_232 V_233 ;
struct V_5 * V_6 ;
void T_8 * V_234 ;
struct V_204 * V_235 ;
T_1 V_142 ;
V_15 V_236 , V_147 ;
int V_131 ;
V_131 = F_130 ( V_231 , 0 , & V_233 ) ;
if ( V_131 ) {
F_88 ( L_19 , V_231 -> V_237 ) ;
return - V_167 ;
}
V_234 = F_131 ( V_233 . V_238 , F_132 ( & V_233 ) ) ;
if ( ! V_234 ) {
F_88 ( L_20 , V_231 -> V_237 ) ;
return - V_108 ;
}
V_142 = F_26 ( V_234 + V_239 ) & V_240 ;
if ( V_142 != 0x30 && V_142 != 0x40 ) {
F_88 ( L_21 , V_231 -> V_237 ) ;
V_131 = - V_241 ;
goto V_242;
}
V_131 = F_125 ( V_234 ) ;
if ( V_131 ) {
F_88 ( L_22 ,
V_231 -> V_237 ) ;
goto V_242;
}
F_63 ( L_23 , V_231 -> V_237 ) ;
V_6 = F_61 ( sizeof( * V_6 ) , V_107 ) ;
if ( ! V_6 ) {
V_131 = - V_108 ;
goto V_242;
}
F_133 ( & V_6 -> V_69 ) ;
F_103 ( & V_6 -> V_200 ) ;
F_103 ( & V_6 -> V_201 ) ;
V_6 -> V_51 = V_234 ;
V_6 -> V_96 = V_233 . V_238 ;
V_6 -> V_199 = ( ( F_26 ( V_234 + V_141 ) >> 4 ) & 0xf ) + 1 ;
V_6 -> V_47 = F_61 ( V_243 , V_107 ) ;
if ( ! V_6 -> V_47 ) {
V_131 = - V_108 ;
goto V_244;
}
V_6 -> V_50 = V_6 -> V_47 ;
F_127 ( V_6 ) ;
V_131 = F_82 ( V_231 -> V_237 , V_6 ) ;
if ( V_131 )
goto V_245;
V_131 = F_91 ( V_6 ) ;
if ( V_131 )
goto V_246;
V_236 = ( F_16 ( V_6 -> V_47 ) |
V_247 |
V_248 |
( V_243 / V_159 - 1 ) |
V_249 ) ;
F_90 ( V_236 , V_6 -> V_51 + V_250 ) ;
V_147 = F_83 ( V_6 -> V_51 + V_250 ) ;
if ( ( V_147 ^ V_236 ) & V_251 ) {
if ( ! ( V_147 & V_251 ) ) {
V_236 &= ~ ( V_251 |
V_252 ) ;
V_236 |= V_253 ;
F_90 ( V_236 , V_6 -> V_51 + V_250 ) ;
}
F_63 ( L_24 ) ;
V_6 -> V_57 |= V_58 ;
}
F_90 ( 0 , V_6 -> V_51 + V_56 ) ;
F_32 ( V_225 , V_6 -> V_51 + V_223 ) ;
if ( F_134 ( V_231 , L_25 ) ) {
struct V_209 * V_208 ;
V_208 = F_61 ( sizeof( * V_208 ) , V_107 ) ;
if ( ! V_208 ) {
V_131 = - V_108 ;
goto V_246;
}
V_235 = F_135 ( V_231 , & V_254 , V_6 ) ;
if ( ! V_235 ) {
V_131 = - V_108 ;
F_75 ( V_208 ) ;
goto V_246;
}
V_235 -> V_216 = V_216 ;
V_235 -> V_255 = V_256 ;
V_208 -> V_257 = & V_258 ;
V_208 -> V_100 = V_6 ;
V_235 -> V_259 = V_208 ;
}
F_66 ( & V_192 ) ;
F_104 ( & V_6 -> V_200 , & V_260 ) ;
F_69 ( & V_192 ) ;
return 0 ;
V_246:
F_80 ( V_6 ) ;
V_245:
F_75 ( V_6 -> V_47 ) ;
V_244:
F_75 ( V_6 ) ;
V_242:
F_136 ( V_234 ) ;
F_74 ( L_26 , V_231 -> V_237 , V_131 ) ;
return V_131 ;
}
static bool F_137 ( void )
{
return ! ! ( F_26 ( F_93 () + V_195 ) & V_261 ) ;
}
int F_138 ( void )
{
if ( ! F_139 ( & V_260 ) ) {
if ( ! F_137 () ) {
F_63 ( L_27 , F_95 () ) ;
return - V_167 ;
}
F_92 () ;
F_97 () ;
}
return 0 ;
}
int F_140 ( struct V_230 * V_231 , struct V_262 * V_262 ,
struct V_204 * V_263 )
{
struct V_230 * V_264 ;
for ( V_264 = F_141 ( V_231 , V_265 ) ; V_264 ;
V_264 = F_141 ( V_264 , V_265 ) ) {
F_129 ( V_264 , V_263 ) ;
}
if ( F_139 ( & V_260 ) ) {
F_88 ( L_28 ) ;
return - V_167 ;
}
V_80 = V_262 ;
V_266 = V_231 ;
F_76 () ;
F_60 ( V_262 -> V_104 ) ;
return 0 ;
}
