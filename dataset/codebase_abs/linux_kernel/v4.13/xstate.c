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
static void F_37 ( void )
{
int V_64 ;
T_2 V_31 , V_32 , V_33 , V_34 ;
static int V_84 = 1 ;
if ( ! V_84 )
return;
V_84 = 0 ;
for ( V_64 = 0 ; V_64 < V_70 + 10 ; V_64 ++ ) {
F_9 ( V_35 , V_64 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
F_38 ( L_6 ,
V_35 , V_64 , V_31 , V_32 , V_33 , V_34 ) ;
}
}
static void F_39 ( int V_85 )
{
int V_86 = F_35 ( V_85 ) ;
F_40 ( V_86 , V_85 , V_87 , struct V_88 ) ;
F_40 ( V_86 , V_85 , V_89 , struct V_90 ) ;
F_40 ( V_86 , V_85 , V_91 , struct V_92 ) ;
F_40 ( V_86 , V_85 , V_93 , struct V_94 ) ;
F_40 ( V_86 , V_85 , V_95 , struct V_96 ) ;
F_40 ( V_86 , V_85 , V_97 , struct V_98 ) ;
F_40 ( V_86 , V_85 , V_99 , struct V_100 ) ;
if ( ( V_85 < V_87 ) ||
( V_85 >= V_70 ) ||
( V_85 == V_101 ) ) {
F_15 ( 1 , L_7 , V_85 ) ;
F_41 ( 1 ) ;
}
}
static void F_42 ( void )
{
int V_102 = V_80 + V_81 ;
int V_64 ;
for ( V_64 = V_69 ; V_64 < V_70 ; V_64 ++ ) {
if ( ! F_18 ( V_64 ) )
continue;
F_39 ( V_64 ) ;
if ( ! F_36 () )
F_41 ( F_8 ( V_64 ) ) ;
if ( F_25 ( V_64 ) )
V_102 = F_28 ( V_102 , 64 ) ;
if ( ! F_36 () )
V_102 = F_34 ( V_64 ) ;
V_102 += F_35 ( V_64 ) ;
}
F_41 ( V_102 != V_103 ) ;
}
static unsigned int T_3 F_43 ( void )
{
unsigned int V_31 , V_32 , V_33 , V_34 ;
F_9 ( V_35 , 1 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
return V_32 ;
}
static unsigned int T_3 F_44 ( void )
{
unsigned int V_31 , V_32 , V_33 , V_34 ;
F_9 ( V_35 , 0 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
return V_32 ;
}
static bool F_45 ( unsigned int V_104 )
{
if ( V_104 <= sizeof( union V_105 ) )
return true ;
F_38 ( L_8 ,
sizeof( union V_105 ) , V_104 ) ;
return false ;
}
static int F_46 ( void )
{
unsigned int V_106 ;
unsigned int V_107 ;
V_107 = F_44 () ;
if ( F_14 ( V_4 ) )
V_106 = F_43 () ;
else
V_106 = V_107 ;
if ( ! F_45 ( V_106 ) )
return - V_108 ;
V_103 = V_106 ;
F_42 () ;
V_109 = V_107 ;
return 0 ;
}
static void F_47 ( void )
{
V_25 = 0 ;
F_48 ( V_61 ) ;
F_1 () ;
}
void T_3 F_49 ( void )
{
unsigned int V_31 , V_32 , V_33 , V_34 ;
static int T_4 V_82 = 1 ;
int V_110 ;
F_31 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_14 ( V_111 ) ) {
F_23 ( L_9 ) ;
return;
}
if ( ! F_14 ( V_1 ) ) {
F_23 ( L_10 ,
F_14 ( V_112 ) ? L_11 : L_12 ) ;
return;
}
if ( V_113 . V_114 < V_35 ) {
F_31 ( 1 ) ;
return;
}
F_9 ( V_35 , 0 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
V_25 = V_31 + ( ( T_1 ) V_34 << 32 ) ;
if ( ( V_25 & V_115 ) != V_115 ) {
F_50 ( L_13 , V_25 ) ;
goto V_116;
}
V_25 &= F_51 () ;
F_13 () ;
V_110 = F_46 () ;
if ( V_110 )
goto V_116;
F_52 ( V_109 , V_25 & ~ V_60 ) ;
F_53 () ;
F_30 () ;
F_27 () ;
F_29 () ;
F_23 ( L_14 ,
V_25 ,
V_103 ,
F_14 ( V_4 ) ? L_15 : L_16 ) ;
return;
V_116:
F_47 () ;
}
void F_54 ( void )
{
if ( F_14 ( V_1 ) )
F_17 ( V_62 , V_25 ) ;
}
void * F_55 ( struct V_66 * V_43 , int V_117 )
{
int V_118 = F_5 ( V_117 ) - 1 ;
if ( ! F_18 ( V_118 ) ) {
F_31 ( 1 ) ;
return NULL ;
}
return ( void * ) V_43 + V_56 [ V_118 ] ;
}
void * F_56 ( struct V_66 * V_43 , int V_119 )
{
if ( ! F_14 ( V_1 ) )
return NULL ;
F_15 ( ! ( V_25 & V_119 ) ,
L_17 ) ;
if ( ! ( V_43 -> V_44 . V_42 & V_119 ) )
return NULL ;
return F_55 ( V_43 , V_119 ) ;
}
const void * F_57 ( int V_120 )
{
struct V_36 * V_36 = & V_121 -> V_122 . V_36 ;
if ( ! V_36 -> V_123 )
return NULL ;
F_58 ( V_36 ) ;
return F_56 ( & V_36 -> V_39 . V_43 , V_120 ) ;
}
int F_59 ( struct V_124 * V_125 , int V_126 ,
unsigned long V_127 )
{
T_2 V_128 ;
int V_129 = ( V_126 * V_130 ) ;
T_2 V_131 = 0 ;
if ( ! F_14 ( V_132 ) )
return - V_108 ;
if ( V_127 & V_133 )
V_131 |= V_134 ;
if ( V_127 & V_135 )
V_131 |= V_136 ;
V_131 <<= V_129 ;
V_128 = F_60 () ;
V_128 &= ~ ( ( V_134 | V_136 ) << V_129 ) ;
F_61 ( V_128 | V_131 ) ;
return 0 ;
}
static inline int F_62 ( unsigned int V_137 , unsigned int V_138 ,
void * V_139 , void T_5 * V_140 ,
const void * V_141 , const int V_142 ,
const int V_143 )
{
if ( ( V_138 == 0 ) || ( V_137 < V_142 ) )
return 0 ;
if ( V_143 < 0 || V_137 < V_143 ) {
unsigned int V_144 = ( V_143 < 0 ? V_138 : F_7 ( V_138 , V_143 - V_137 ) ) ;
if ( V_139 ) {
memcpy ( V_139 + V_137 , V_141 , V_144 ) ;
} else {
if ( F_63 ( V_140 + V_137 , V_141 , V_144 ) )
return - V_145 ;
}
}
return 0 ;
}
int F_64 ( unsigned int V_137 , unsigned int V_138 , void * V_139 ,
void T_5 * V_140 , struct V_66 * V_43 )
{
unsigned int V_55 , V_57 ;
int V_146 , V_64 ;
struct V_147 V_44 ;
if ( F_4 ( V_137 != 0 ) )
return - V_145 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_42 = V_43 -> V_44 . V_42 ;
V_44 . V_42 &= ~ V_60 ;
V_55 = F_20 ( struct V_66 , V_44 ) ;
V_57 = sizeof( V_44 ) ;
V_146 = F_62 ( V_55 , V_57 , V_139 , V_140 , & V_44 , 0 , V_138 ) ;
if ( V_146 )
return V_146 ;
for ( V_64 = 0 ; V_64 < V_70 ; V_64 ++ ) {
if ( ( V_44 . V_42 >> V_64 ) & 1 ) {
void * V_148 = F_55 ( V_43 , 1 << V_64 ) ;
V_55 = V_68 [ V_64 ] ;
V_57 = V_58 [ V_64 ] ;
V_146 = F_62 ( V_55 , V_57 , V_139 , V_140 , V_148 , 0 , V_138 ) ;
if ( V_146 )
return V_146 ;
if ( V_55 + V_57 >= V_138 )
break;
}
}
V_55 = F_20 ( struct V_37 , V_149 ) ;
V_57 = sizeof( V_150 ) ;
V_146 = F_62 ( V_55 , V_57 , V_139 , V_140 , V_150 , 0 , V_138 ) ;
if ( V_146 )
return V_146 ;
return 0 ;
}
int F_65 ( const void * V_139 , const void T_5 * V_140 ,
struct V_66 * V_43 )
{
unsigned int V_55 , V_57 ;
int V_64 ;
T_1 V_42 ;
T_1 V_151 ;
V_55 = F_20 ( struct V_66 , V_44 ) ;
V_57 = sizeof( V_42 ) ;
if ( V_139 ) {
memcpy ( & V_42 , V_139 + V_55 , V_57 ) ;
} else {
if ( F_66 ( & V_42 , V_140 + V_55 , V_57 ) )
return - V_145 ;
}
V_151 = V_25 & ~ V_60 ;
if ( V_42 & ~ V_151 )
return - V_108 ;
for ( V_64 = 0 ; V_64 < V_70 ; V_64 ++ ) {
T_1 V_152 = ( ( T_1 ) 1 << V_64 ) ;
if ( V_42 & V_152 ) {
void * V_153 = F_55 ( V_43 , 1 << V_64 ) ;
V_55 = V_68 [ V_64 ] ;
V_57 = V_58 [ V_64 ] ;
if ( V_139 ) {
memcpy ( V_153 , V_139 + V_55 , V_57 ) ;
} else {
if ( F_66 ( V_153 , V_140 + V_55 , V_57 ) )
return - V_145 ;
}
}
}
V_43 -> V_44 . V_42 &= V_60 ;
V_43 -> V_44 . V_42 |= V_42 ;
return 0 ;
}
