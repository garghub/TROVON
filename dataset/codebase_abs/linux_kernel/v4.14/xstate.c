void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
F_2 ( V_16 ) ;
F_2 ( V_17 ) ;
F_2 ( V_18 ) ;
F_2 ( V_19 ) ;
F_2 ( V_20 ) ;
F_2 ( V_21 ) ;
}
int F_3 ( T_1 V_22 , const char * * V_23 )
{
T_1 V_24 = V_22 & ~ V_25 ;
if ( F_4 ( V_23 ) ) {
long V_26 , V_27 ;
T_1 V_28 ;
if ( V_24 )
V_28 = V_24 ;
else
V_28 = V_22 ;
V_26 = F_5 ( V_28 ) - 1 ;
V_27 = F_6 ( V_29 ) - 1 ;
V_26 = F_7 ( V_26 , V_27 ) ;
* V_23 = V_29 [ V_26 ] ;
}
if ( V_24 )
return 0 ;
return 1 ;
}
static int F_8 ( int V_30 )
{
T_2 V_31 , V_32 , V_33 , V_34 ;
F_9 ( V_35 , V_30 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
return ! ! ( V_33 & 1 ) ;
}
static int F_10 ( int V_30 )
{
return ! F_8 ( V_30 ) ;
}
void F_11 ( struct V_36 * V_36 )
{
struct V_37 * V_38 = & V_36 -> V_39 . V_40 ;
int V_41 ;
T_1 V_42 ;
if ( ! F_12 () )
return;
V_42 = V_36 -> V_39 . V_43 . V_44 . V_42 ;
if ( ( V_42 & V_25 ) == V_25 )
return;
if ( ! ( V_42 & V_45 ) ) {
V_38 -> V_46 = 0x37f ;
V_38 -> V_47 = 0 ;
V_38 -> V_48 = 0 ;
V_38 -> V_49 = 0 ;
V_38 -> V_50 = 0 ;
V_38 -> V_51 = 0 ;
memset ( & V_38 -> V_52 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_42 & V_53 ) )
memset ( & V_38 -> V_54 [ 0 ] , 0 , 256 ) ;
V_41 = 0x2 ;
V_42 = ( V_25 & ~ V_42 ) >> 2 ;
while ( V_42 ) {
if ( V_42 & 0x1 ) {
int V_55 = V_56 [ V_41 ] ;
int V_57 = V_58 [ V_41 ] ;
memcpy ( ( void * ) V_38 + V_55 ,
( void * ) & V_59 . V_43 + V_55 ,
V_57 ) ;
}
V_42 >>= 1 ;
V_41 ++ ;
}
}
void F_13 ( void )
{
if ( ! F_14 ( V_1 ) || ! V_25 )
return;
F_15 ( ( V_25 & V_60 ) ,
L_1 ) ;
V_25 &= ~ V_60 ;
F_16 ( V_61 ) ;
F_17 ( V_62 , V_25 ) ;
}
static int F_18 ( enum V_63 V_63 )
{
return ! ! ( V_25 & ( 1UL << V_63 ) ) ;
}
static void T_3 F_19 ( void )
{
T_2 V_31 , V_32 , V_33 , V_34 , V_64 ;
unsigned int V_65 = F_20 ( struct V_66 ,
V_67 ) ;
V_68 [ 0 ] = 0 ;
V_58 [ 0 ] = F_20 ( struct V_37 , V_54 ) ;
V_68 [ 1 ] = V_58 [ 0 ] ;
V_58 [ 1 ] = F_21 ( struct V_37 , V_54 ) ;
for ( V_64 = V_69 ; V_64 < V_70 ; V_64 ++ ) {
if ( ! F_18 ( V_64 ) )
continue;
F_9 ( V_35 , V_64 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
if ( F_10 ( V_64 ) )
V_68 [ V_64 ] = V_32 ;
V_58 [ V_64 ] = V_31 ;
F_15 ( V_65 > V_68 [ V_64 ] ,
L_2 , V_65 ) ;
V_65 = V_68 [ V_64 ] ;
}
}
static void T_3 F_22 ( T_1 V_71 )
{
const char * V_23 ;
if ( F_3 ( V_71 , & V_23 ) )
F_23 ( L_3 , V_71 , V_23 ) ;
}
static void T_3 F_24 ( void )
{
F_22 ( V_45 ) ;
F_22 ( V_53 ) ;
F_22 ( V_72 ) ;
F_22 ( V_73 ) ;
F_22 ( V_74 ) ;
F_22 ( V_75 ) ;
F_22 ( V_76 ) ;
F_22 ( V_77 ) ;
F_22 ( V_78 ) ;
}
static int F_25 ( int V_30 )
{
T_2 V_31 , V_32 , V_33 , V_34 ;
F_26 ( V_30 ) ;
F_9 ( V_35 , V_30 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
return ! ! ( V_33 & 2 ) ;
}
static void T_3 F_27 ( void )
{
unsigned int V_79 [ sizeof( V_25 ) * 8 ] ;
int V_64 ;
V_56 [ 0 ] = 0 ;
V_56 [ 1 ] = F_20 ( struct V_37 , V_54 ) ;
if ( ! F_14 ( V_4 ) ) {
for ( V_64 = V_69 ; V_64 < V_70 ; V_64 ++ ) {
if ( F_18 ( V_64 ) ) {
V_56 [ V_64 ] = V_68 [ V_64 ] ;
V_79 [ V_64 ] = V_58 [ V_64 ] ;
}
}
return;
}
V_56 [ V_69 ] =
V_80 + V_81 ;
for ( V_64 = V_69 ; V_64 < V_70 ; V_64 ++ ) {
if ( F_18 ( V_64 ) )
V_79 [ V_64 ] = V_58 [ V_64 ] ;
else
V_79 [ V_64 ] = 0 ;
if ( V_64 > V_69 ) {
V_56 [ V_64 ] = V_56 [ V_64 - 1 ]
+ V_79 [ V_64 - 1 ] ;
if ( F_25 ( V_64 ) )
V_56 [ V_64 ] =
F_28 ( V_56 [ V_64 ] , 64 ) ;
}
}
}
static void T_3 F_29 ( void )
{
int V_64 ;
for ( V_64 = V_69 ; V_64 < V_70 ; V_64 ++ ) {
if ( ! F_18 ( V_64 ) )
continue;
F_23 ( L_4 ,
V_64 , V_56 [ V_64 ] , V_64 , V_58 [ V_64 ] ) ;
}
}
static void T_3 F_30 ( void )
{
static int T_4 V_82 = 1 ;
F_31 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_14 ( V_1 ) )
return;
F_19 () ;
F_24 () ;
if ( F_14 ( V_4 ) )
V_59 . V_43 . V_44 . V_83 = ( T_1 ) 1 << 63 | V_25 ;
F_32 ( & V_59 . V_43 ) ;
F_33 ( & V_59 . V_43 ) ;
}
static int F_34 ( int V_30 )
{
T_2 V_31 , V_32 , V_33 , V_34 ;
if ( V_60 & ( 1 << V_30 ) ) {
F_15 ( 1 , L_5 , V_30 ) ;
return - 1 ;
}
F_26 ( V_30 ) ;
F_9 ( V_35 , V_30 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
return V_32 ;
}
static int F_35 ( int V_30 )
{
T_2 V_31 , V_32 , V_33 , V_34 ;
F_26 ( V_30 ) ;
F_9 ( V_35 , V_30 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
return V_31 ;
}
int F_36 ( void )
{
return F_14 ( V_4 ) ;
}
int F_37 ( const struct V_84 * V_85 )
{
if ( V_85 -> V_42 & ( ~ V_25 | V_60 ) )
return - V_86 ;
if ( V_85 -> V_83 )
return - V_86 ;
F_38 ( sizeof( V_85 -> V_87 ) != 48 ) ;
if ( F_39 ( V_85 -> V_87 , 0 , sizeof( V_85 -> V_87 ) ) )
return - V_86 ;
return 0 ;
}
static void F_40 ( void )
{
int V_64 ;
T_2 V_31 , V_32 , V_33 , V_34 ;
static int V_88 = 1 ;
if ( ! V_88 )
return;
V_88 = 0 ;
for ( V_64 = 0 ; V_64 < V_70 + 10 ; V_64 ++ ) {
F_9 ( V_35 , V_64 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
F_41 ( L_6 ,
V_35 , V_64 , V_31 , V_32 , V_33 , V_34 ) ;
}
}
static void F_42 ( int V_89 )
{
int V_90 = F_35 ( V_89 ) ;
F_43 ( V_90 , V_89 , V_91 , struct V_92 ) ;
F_43 ( V_90 , V_89 , V_93 , struct V_94 ) ;
F_43 ( V_90 , V_89 , V_95 , struct V_96 ) ;
F_43 ( V_90 , V_89 , V_97 , struct V_98 ) ;
F_43 ( V_90 , V_89 , V_99 , struct V_100 ) ;
F_43 ( V_90 , V_89 , V_101 , struct V_102 ) ;
F_43 ( V_90 , V_89 , V_103 , struct V_104 ) ;
if ( ( V_89 < V_91 ) ||
( V_89 >= V_70 ) ||
( V_89 == V_105 ) ) {
F_15 ( 1 , L_7 , V_89 ) ;
F_44 ( 1 ) ;
}
}
static void F_45 ( void )
{
int V_106 = V_80 + V_81 ;
int V_64 ;
for ( V_64 = V_69 ; V_64 < V_70 ; V_64 ++ ) {
if ( ! F_18 ( V_64 ) )
continue;
F_42 ( V_64 ) ;
if ( ! F_36 () )
F_44 ( F_8 ( V_64 ) ) ;
if ( F_25 ( V_64 ) )
V_106 = F_28 ( V_106 , 64 ) ;
if ( ! F_36 () )
V_106 = F_34 ( V_64 ) ;
V_106 += F_35 ( V_64 ) ;
}
F_44 ( V_106 != V_107 ) ;
}
static unsigned int T_3 F_46 ( void )
{
unsigned int V_31 , V_32 , V_33 , V_34 ;
F_9 ( V_35 , 1 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
return V_32 ;
}
static unsigned int T_3 F_47 ( void )
{
unsigned int V_31 , V_32 , V_33 , V_34 ;
F_9 ( V_35 , 0 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
return V_32 ;
}
static bool F_48 ( unsigned int V_108 )
{
if ( V_108 <= sizeof( union V_109 ) )
return true ;
F_41 ( L_8 ,
sizeof( union V_109 ) , V_108 ) ;
return false ;
}
static int F_49 ( void )
{
unsigned int V_110 ;
unsigned int V_111 ;
V_111 = F_47 () ;
if ( F_14 ( V_4 ) )
V_110 = F_46 () ;
else
V_110 = V_111 ;
if ( ! F_48 ( V_110 ) )
return - V_86 ;
V_107 = V_110 ;
F_45 () ;
V_112 = V_111 ;
return 0 ;
}
static void F_50 ( void )
{
V_25 = 0 ;
F_51 ( V_61 ) ;
F_1 () ;
}
void T_3 F_52 ( void )
{
unsigned int V_31 , V_32 , V_33 , V_34 ;
static int T_4 V_82 = 1 ;
int V_113 ;
F_31 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_14 ( V_114 ) ) {
F_23 ( L_9 ) ;
return;
}
if ( ! F_14 ( V_1 ) ) {
F_23 ( L_10 ,
F_14 ( V_115 ) ? L_11 : L_12 ) ;
return;
}
if ( V_116 . V_117 < V_35 ) {
F_31 ( 1 ) ;
return;
}
F_9 ( V_35 , 0 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_25 = V_31 + ( ( T_1 ) V_34 << 32 ) ;
if ( ( V_25 & V_118 ) != V_118 ) {
F_53 ( L_13 , V_25 ) ;
goto V_119;
}
V_25 &= F_54 () ;
F_13 () ;
V_113 = F_49 () ;
if ( V_113 )
goto V_119;
F_55 ( V_112 , V_25 & ~ V_60 ) ;
F_56 () ;
F_30 () ;
F_27 () ;
F_29 () ;
F_23 ( L_14 ,
V_25 ,
V_107 ,
F_14 ( V_4 ) ? L_15 : L_16 ) ;
return;
V_119:
F_50 () ;
}
void F_57 ( void )
{
if ( F_14 ( V_1 ) )
F_17 ( V_62 , V_25 ) ;
}
void * F_58 ( struct V_66 * V_43 , int V_120 )
{
int V_121 = F_5 ( V_120 ) - 1 ;
if ( ! F_18 ( V_121 ) ) {
F_31 ( 1 ) ;
return NULL ;
}
return ( void * ) V_43 + V_56 [ V_121 ] ;
}
void * F_59 ( struct V_66 * V_43 , int V_122 )
{
if ( ! F_14 ( V_1 ) )
return NULL ;
F_15 ( ! ( V_25 & V_122 ) ,
L_17 ) ;
if ( ! ( V_43 -> V_44 . V_42 & V_122 ) )
return NULL ;
return F_58 ( V_43 , V_122 ) ;
}
const void * F_60 ( int V_123 )
{
struct V_36 * V_36 = & V_124 -> V_125 . V_36 ;
if ( ! V_36 -> V_126 )
return NULL ;
F_61 ( V_36 ) ;
return F_59 ( & V_36 -> V_39 . V_43 , V_123 ) ;
}
int F_62 ( struct V_127 * V_128 , int V_129 ,
unsigned long V_130 )
{
T_2 V_131 ;
int V_132 = ( V_129 * V_133 ) ;
T_2 V_134 = 0 ;
if ( ! F_14 ( V_135 ) )
return - V_86 ;
if ( V_130 & V_136 )
V_134 |= V_137 ;
if ( V_130 & V_138 )
V_134 |= V_139 ;
V_134 <<= V_132 ;
V_131 = F_63 () ;
V_131 &= ~ ( ( V_137 | V_139 ) << V_132 ) ;
F_64 ( V_131 | V_134 ) ;
return 0 ;
}
static inline bool F_65 ( T_1 V_42 )
{
if ( ! ( V_42 & ( V_53 | V_72 ) ) )
return false ;
if ( V_42 & V_45 )
return false ;
return true ;
}
static inline void
F_66 ( void * V_140 , const void * V_141 ,
unsigned int V_55 , unsigned int V_57 , unsigned int V_142 )
{
if ( V_55 < V_142 ) {
unsigned int V_143 = F_7 ( V_57 , V_142 - V_55 ) ;
memcpy ( V_140 + V_55 , V_141 , V_143 ) ;
}
}
int F_67 ( void * V_140 , struct V_66 * V_43 , unsigned int V_144 , unsigned int V_142 )
{
unsigned int V_55 , V_57 ;
struct V_84 V_44 ;
int V_64 ;
if ( F_4 ( V_144 != 0 ) )
return - V_145 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_42 = V_43 -> V_44 . V_42 ;
V_44 . V_42 &= ~ V_60 ;
V_55 = F_20 ( struct V_66 , V_44 ) ;
V_57 = sizeof( V_44 ) ;
F_66 ( V_140 , & V_44 , V_55 , V_57 , V_142 ) ;
for ( V_64 = 0 ; V_64 < V_70 ; V_64 ++ ) {
if ( ( V_44 . V_42 >> V_64 ) & 1 ) {
void * V_146 = F_58 ( V_43 , 1 << V_64 ) ;
V_55 = V_68 [ V_64 ] ;
V_57 = V_58 [ V_64 ] ;
if ( V_55 + V_57 > V_142 )
break;
F_66 ( V_140 , V_146 , V_55 , V_57 , V_142 ) ;
}
}
if ( F_65 ( V_44 . V_42 ) ) {
V_55 = F_20 ( struct V_37 , V_147 ) ;
V_57 = V_148 ;
F_66 ( V_140 , & V_43 -> V_149 . V_147 , V_55 , V_57 , V_142 ) ;
}
V_55 = F_20 ( struct V_37 , V_150 ) ;
V_57 = sizeof( V_151 ) ;
F_66 ( V_140 , V_151 , V_55 , V_57 , V_142 ) ;
return 0 ;
}
static inline int
F_68 ( void T_5 * V_152 , const void * V_141 , unsigned int V_55 , unsigned int V_57 , unsigned int V_142 )
{
if ( ! V_57 )
return 0 ;
if ( V_55 < V_142 ) {
unsigned int V_143 = F_7 ( V_57 , V_142 - V_55 ) ;
if ( F_69 ( V_152 + V_55 , V_141 , V_143 ) )
return - V_145 ;
}
return 0 ;
}
int F_70 ( void T_5 * V_152 , struct V_66 * V_43 , unsigned int V_144 , unsigned int V_142 )
{
unsigned int V_55 , V_57 ;
int V_153 , V_64 ;
struct V_84 V_44 ;
if ( F_4 ( V_144 != 0 ) )
return - V_145 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_42 = V_43 -> V_44 . V_42 ;
V_44 . V_42 &= ~ V_60 ;
V_55 = F_20 ( struct V_66 , V_44 ) ;
V_57 = sizeof( V_44 ) ;
V_153 = F_68 ( V_152 , & V_44 , V_55 , V_57 , V_142 ) ;
if ( V_153 )
return V_153 ;
for ( V_64 = 0 ; V_64 < V_70 ; V_64 ++ ) {
if ( ( V_44 . V_42 >> V_64 ) & 1 ) {
void * V_146 = F_58 ( V_43 , 1 << V_64 ) ;
V_55 = V_68 [ V_64 ] ;
V_57 = V_58 [ V_64 ] ;
if ( V_55 + V_57 > V_142 )
break;
V_153 = F_68 ( V_152 , V_146 , V_55 , V_57 , V_142 ) ;
if ( V_153 )
return V_153 ;
}
}
if ( F_65 ( V_44 . V_42 ) ) {
V_55 = F_20 ( struct V_37 , V_147 ) ;
V_57 = V_148 ;
F_68 ( V_152 , & V_43 -> V_149 . V_147 , V_55 , V_57 , V_142 ) ;
}
V_55 = F_20 ( struct V_37 , V_150 ) ;
V_57 = sizeof( V_151 ) ;
V_153 = F_68 ( V_152 , V_151 , V_55 , V_57 , V_142 ) ;
if ( V_153 )
return V_153 ;
return 0 ;
}
int F_71 ( struct V_66 * V_43 , const void * V_140 )
{
unsigned int V_55 , V_57 ;
int V_64 ;
struct V_84 V_85 ;
V_55 = F_20 ( struct V_66 , V_44 ) ;
V_57 = sizeof( V_85 ) ;
memcpy ( & V_85 , V_140 + V_55 , V_57 ) ;
if ( F_37 ( & V_85 ) )
return - V_86 ;
for ( V_64 = 0 ; V_64 < V_70 ; V_64 ++ ) {
T_1 V_154 = ( ( T_1 ) 1 << V_64 ) ;
if ( V_85 . V_42 & V_154 ) {
void * V_155 = F_58 ( V_43 , 1 << V_64 ) ;
V_55 = V_68 [ V_64 ] ;
V_57 = V_58 [ V_64 ] ;
memcpy ( V_155 , V_140 + V_55 , V_57 ) ;
}
}
if ( F_65 ( V_85 . V_42 ) ) {
V_55 = F_20 ( struct V_37 , V_147 ) ;
V_57 = V_148 ;
memcpy ( & V_43 -> V_149 . V_147 , V_140 + V_55 , V_57 ) ;
}
V_43 -> V_44 . V_42 &= V_60 ;
V_43 -> V_44 . V_42 |= V_85 . V_42 ;
return 0 ;
}
int F_72 ( struct V_66 * V_43 , const void T_5 * V_152 )
{
unsigned int V_55 , V_57 ;
int V_64 ;
struct V_84 V_85 ;
V_55 = F_20 ( struct V_66 , V_44 ) ;
V_57 = sizeof( V_85 ) ;
if ( F_73 ( & V_85 , V_152 + V_55 , V_57 ) )
return - V_145 ;
if ( F_37 ( & V_85 ) )
return - V_86 ;
for ( V_64 = 0 ; V_64 < V_70 ; V_64 ++ ) {
T_1 V_154 = ( ( T_1 ) 1 << V_64 ) ;
if ( V_85 . V_42 & V_154 ) {
void * V_155 = F_58 ( V_43 , 1 << V_64 ) ;
V_55 = V_68 [ V_64 ] ;
V_57 = V_58 [ V_64 ] ;
if ( F_73 ( V_155 , V_152 + V_55 , V_57 ) )
return - V_145 ;
}
}
if ( F_65 ( V_85 . V_42 ) ) {
V_55 = F_20 ( struct V_37 , V_147 ) ;
V_57 = V_148 ;
if ( F_73 ( & V_43 -> V_149 . V_147 , V_152 + V_55 , V_57 ) )
return - V_145 ;
}
V_43 -> V_44 . V_42 &= V_60 ;
V_43 -> V_44 . V_42 |= V_85 . V_42 ;
return 0 ;
}
