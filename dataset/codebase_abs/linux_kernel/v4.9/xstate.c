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
}
int F_3 ( T_1 V_19 , const char * * V_20 )
{
T_1 V_21 = V_19 & ~ V_22 ;
if ( F_4 ( V_20 ) ) {
long V_23 , V_24 ;
T_1 V_25 ;
if ( V_21 )
V_25 = V_21 ;
else
V_25 = V_19 ;
V_23 = F_5 ( V_25 ) - 1 ;
V_24 = F_6 ( V_26 ) - 1 ;
V_23 = F_7 ( V_23 , V_24 ) ;
* V_20 = V_26 [ V_23 ] ;
}
if ( V_21 )
return 0 ;
return 1 ;
}
static int F_8 ( int V_27 )
{
T_2 V_28 , V_29 , V_30 , V_31 ;
F_9 ( V_32 , V_27 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
return ! ! ( V_30 & 1 ) ;
}
static int F_10 ( int V_27 )
{
return ! F_8 ( V_27 ) ;
}
void F_11 ( struct V_33 * V_33 )
{
struct V_34 * V_35 = & V_33 -> V_36 . V_37 ;
int V_38 ;
T_1 V_39 ;
if ( ! F_12 () )
return;
V_39 = V_33 -> V_36 . V_40 . V_41 . V_39 ;
if ( ( V_39 & V_22 ) == V_22 )
return;
if ( ! ( V_39 & V_42 ) ) {
V_35 -> V_43 = 0x37f ;
V_35 -> V_44 = 0 ;
V_35 -> V_45 = 0 ;
V_35 -> V_46 = 0 ;
V_35 -> V_47 = 0 ;
V_35 -> V_48 = 0 ;
memset ( & V_35 -> V_49 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_39 & V_50 ) )
memset ( & V_35 -> V_51 [ 0 ] , 0 , 256 ) ;
V_38 = 0x2 ;
V_39 = ( V_22 & ~ V_39 ) >> 2 ;
while ( V_39 ) {
if ( V_39 & 0x1 ) {
int V_52 = V_53 [ V_38 ] ;
int V_54 = V_55 [ V_38 ] ;
memcpy ( ( void * ) V_35 + V_52 ,
( void * ) & V_56 . V_40 + V_52 ,
V_54 ) ;
}
V_39 >>= 1 ;
V_38 ++ ;
}
}
void F_13 ( void )
{
if ( ! F_14 ( V_1 ) || ! V_22 )
return;
F_15 ( ( V_22 & V_57 ) ,
L_1 ) ;
V_22 &= ~ V_57 ;
F_16 ( V_58 ) ;
F_17 ( V_59 , V_22 ) ;
}
static int F_18 ( enum V_60 V_60 )
{
return ! ! ( V_22 & ( 1UL << V_60 ) ) ;
}
static void T_3 F_19 ( void )
{
T_2 V_28 , V_29 , V_30 , V_31 , V_61 ;
unsigned int V_62 = F_20 ( struct V_63 ,
V_64 ) ;
V_65 [ 0 ] = 0 ;
V_55 [ 0 ] = F_20 ( struct V_34 , V_51 ) ;
V_65 [ 1 ] = V_55 [ 0 ] ;
V_55 [ 1 ] = F_21 ( struct V_34 , V_51 ) ;
for ( V_61 = V_66 ; V_61 < V_67 ; V_61 ++ ) {
if ( ! F_18 ( V_61 ) )
continue;
F_9 ( V_32 , V_61 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
if ( F_10 ( V_61 ) )
V_65 [ V_61 ] = V_29 ;
V_55 [ V_61 ] = V_28 ;
F_15 ( V_62 > V_65 [ V_61 ] ,
L_2 , V_62 ) ;
V_62 = V_65 [ V_61 ] ;
}
}
static void T_3 F_22 ( T_1 V_68 )
{
const char * V_20 ;
if ( F_3 ( V_68 , & V_20 ) )
F_23 ( L_3 , V_68 , V_20 ) ;
}
static void T_3 F_24 ( void )
{
F_22 ( V_42 ) ;
F_22 ( V_50 ) ;
F_22 ( V_69 ) ;
F_22 ( V_70 ) ;
F_22 ( V_71 ) ;
F_22 ( V_72 ) ;
F_22 ( V_73 ) ;
F_22 ( V_74 ) ;
F_22 ( V_75 ) ;
}
static int F_25 ( int V_27 )
{
T_2 V_28 , V_29 , V_30 , V_31 ;
F_26 ( V_27 ) ;
F_9 ( V_32 , V_27 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
return ! ! ( V_30 & 2 ) ;
}
static void T_3 F_27 ( void )
{
unsigned int V_76 [ sizeof( V_22 ) * 8 ] ;
int V_61 ;
V_53 [ 0 ] = 0 ;
V_53 [ 1 ] = F_20 ( struct V_34 , V_51 ) ;
if ( ! F_14 ( V_4 ) ) {
for ( V_61 = V_66 ; V_61 < V_67 ; V_61 ++ ) {
if ( F_18 ( V_61 ) ) {
V_53 [ V_61 ] = V_65 [ V_61 ] ;
V_76 [ V_61 ] = V_55 [ V_61 ] ;
}
}
return;
}
V_53 [ V_66 ] =
V_77 + V_78 ;
for ( V_61 = V_66 ; V_61 < V_67 ; V_61 ++ ) {
if ( F_18 ( V_61 ) )
V_76 [ V_61 ] = V_55 [ V_61 ] ;
else
V_76 [ V_61 ] = 0 ;
if ( V_61 > V_66 ) {
V_53 [ V_61 ] = V_53 [ V_61 - 1 ]
+ V_76 [ V_61 - 1 ] ;
if ( F_25 ( V_61 ) )
V_53 [ V_61 ] =
F_28 ( V_53 [ V_61 ] , 64 ) ;
}
}
}
static void T_3 F_29 ( void )
{
int V_61 ;
for ( V_61 = V_66 ; V_61 < V_67 ; V_61 ++ ) {
if ( ! F_18 ( V_61 ) )
continue;
F_23 ( L_4 ,
V_61 , V_53 [ V_61 ] , V_61 , V_55 [ V_61 ] ) ;
}
}
static void T_3 F_30 ( void )
{
static int T_4 V_79 = 1 ;
F_31 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_14 ( V_1 ) )
return;
F_19 () ;
F_24 () ;
if ( F_14 ( V_4 ) )
V_56 . V_40 . V_41 . V_80 = ( T_1 ) 1 << 63 | V_22 ;
F_32 ( & V_56 . V_40 ) ;
F_33 ( & V_56 . V_40 ) ;
}
static int F_34 ( int V_27 )
{
T_2 V_28 , V_29 , V_30 , V_31 ;
if ( V_57 & ( 1 << V_27 ) ) {
F_15 ( 1 , L_5 , V_27 ) ;
return - 1 ;
}
F_26 ( V_27 ) ;
F_9 ( V_32 , V_27 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
return V_29 ;
}
static int F_35 ( int V_27 )
{
T_2 V_28 , V_29 , V_30 , V_31 ;
F_26 ( V_27 ) ;
F_9 ( V_32 , V_27 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
return V_28 ;
}
int F_36 ( void )
{
return F_14 ( V_4 ) ;
}
static void F_37 ( void )
{
int V_61 ;
T_2 V_28 , V_29 , V_30 , V_31 ;
static int V_81 = 1 ;
if ( ! V_81 )
return;
V_81 = 0 ;
for ( V_61 = 0 ; V_61 < V_67 + 10 ; V_61 ++ ) {
F_9 ( V_32 , V_61 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
F_38 ( L_6 ,
V_32 , V_61 , V_28 , V_29 , V_30 , V_31 ) ;
}
}
static void F_39 ( int V_82 )
{
int V_83 = F_35 ( V_82 ) ;
F_40 ( V_83 , V_82 , V_84 , struct V_85 ) ;
F_40 ( V_83 , V_82 , V_86 , struct V_87 ) ;
F_40 ( V_83 , V_82 , V_88 , struct V_89 ) ;
F_40 ( V_83 , V_82 , V_90 , struct V_91 ) ;
F_40 ( V_83 , V_82 , V_92 , struct V_93 ) ;
F_40 ( V_83 , V_82 , V_94 , struct V_95 ) ;
F_40 ( V_83 , V_82 , V_96 , struct V_97 ) ;
if ( ( V_82 < V_84 ) ||
( V_82 >= V_67 ) ||
( V_82 == V_98 ) ) {
F_15 ( 1 , L_7 , V_82 ) ;
F_41 ( 1 ) ;
}
}
static void F_42 ( void )
{
int V_99 = V_77 + V_78 ;
int V_61 ;
for ( V_61 = V_66 ; V_61 < V_67 ; V_61 ++ ) {
if ( ! F_18 ( V_61 ) )
continue;
F_39 ( V_61 ) ;
if ( ! F_36 () )
F_41 ( F_8 ( V_61 ) ) ;
if ( F_25 ( V_61 ) )
V_99 = F_28 ( V_99 , 64 ) ;
if ( ! F_36 () )
V_99 = F_34 ( V_61 ) ;
V_99 += F_35 ( V_61 ) ;
}
F_41 ( V_99 != V_100 ) ;
}
static unsigned int T_3 F_43 ( void )
{
unsigned int V_28 , V_29 , V_30 , V_31 ;
F_9 ( V_32 , 1 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
return V_29 ;
}
static unsigned int T_3 F_44 ( void )
{
unsigned int V_28 , V_29 , V_30 , V_31 ;
F_9 ( V_32 , 0 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
return V_29 ;
}
static bool F_45 ( unsigned int V_101 )
{
if ( V_101 <= sizeof( union V_102 ) )
return true ;
F_38 ( L_8 ,
sizeof( union V_102 ) , V_101 ) ;
return false ;
}
static int F_46 ( void )
{
unsigned int V_103 ;
unsigned int V_104 ;
V_104 = F_44 () ;
if ( F_14 ( V_4 ) )
V_103 = F_43 () ;
else
V_103 = V_104 ;
if ( ! F_45 ( V_103 ) )
return - V_105 ;
V_100 = V_103 ;
F_42 () ;
V_106 = V_104 ;
return 0 ;
}
static void F_47 ( void )
{
V_22 = 0 ;
F_48 ( V_58 ) ;
F_1 () ;
}
void T_3 F_49 ( void )
{
unsigned int V_28 , V_29 , V_30 , V_31 ;
static int T_4 V_79 = 1 ;
int V_107 ;
F_31 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_14 ( V_1 ) ) {
F_23 ( L_9 ) ;
return;
}
if ( V_108 . V_109 < V_32 ) {
F_31 ( 1 ) ;
return;
}
F_9 ( V_32 , 0 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
V_22 = V_28 + ( ( T_1 ) V_31 << 32 ) ;
if ( ( V_22 & V_110 ) != V_110 ) {
F_50 ( L_10 , V_22 ) ;
goto V_111;
}
V_22 &= F_51 () ;
F_13 () ;
V_107 = F_46 () ;
if ( V_107 )
goto V_111;
F_52 ( V_106 , V_22 & ~ V_57 ) ;
F_53 () ;
F_30 () ;
F_27 () ;
F_29 () ;
F_23 ( L_11 ,
V_22 ,
V_100 ,
F_14 ( V_4 ) ? L_12 : L_13 ) ;
return;
V_111:
F_47 () ;
}
void F_54 ( void )
{
if ( F_14 ( V_1 ) )
F_17 ( V_59 , V_22 ) ;
}
void * F_55 ( struct V_63 * V_40 , int V_112 )
{
int V_113 = F_5 ( V_112 ) - 1 ;
if ( ! F_18 ( V_113 ) ) {
F_31 ( 1 ) ;
return NULL ;
}
return ( void * ) V_40 + V_53 [ V_113 ] ;
}
void * F_56 ( struct V_63 * V_40 , int V_114 )
{
if ( ! F_14 ( V_1 ) )
return NULL ;
F_15 ( ! ( V_22 & V_114 ) ,
L_14 ) ;
if ( ! ( V_40 -> V_41 . V_39 & V_114 ) )
return NULL ;
return F_55 ( V_40 , V_114 ) ;
}
const void * F_57 ( int V_115 )
{
struct V_33 * V_33 = & V_116 -> V_117 . V_33 ;
if ( ! V_33 -> V_118 )
return NULL ;
F_58 ( V_33 ) ;
return F_56 ( & V_33 -> V_36 . V_40 , V_115 ) ;
}
int F_59 ( struct V_119 * V_120 , int V_121 ,
unsigned long V_122 )
{
T_2 V_123 ;
int V_124 = ( V_121 * V_125 ) ;
T_2 V_126 = 0 ;
if ( ! F_14 ( V_127 ) )
return - V_105 ;
F_60 ( ! F_61 () ) ;
if ( V_122 & V_128 )
V_126 |= V_129 ;
if ( V_122 & V_130 )
V_126 |= V_131 ;
V_126 <<= V_124 ;
V_123 = F_62 () ;
V_123 &= ~ ( ( V_129 | V_131 ) << V_124 ) ;
F_63 ( V_123 | V_126 ) ;
return 0 ;
}
static inline int F_64 ( unsigned int V_132 , unsigned int V_133 ,
void * V_134 , void T_5 * V_135 ,
const void * V_136 , const int V_137 ,
const int V_138 )
{
if ( ( V_133 == 0 ) || ( V_132 < V_137 ) )
return 0 ;
if ( V_138 < 0 || V_132 < V_138 ) {
unsigned int V_139 = ( V_138 < 0 ? V_133 : F_7 ( V_133 , V_138 - V_132 ) ) ;
if ( V_134 ) {
memcpy ( V_134 + V_132 , V_136 , V_139 ) ;
} else {
if ( F_65 ( V_135 + V_132 , V_136 , V_139 ) )
return - V_140 ;
}
}
return 0 ;
}
int F_66 ( unsigned int V_132 , unsigned int V_133 , void * V_134 ,
void T_5 * V_135 , struct V_63 * V_40 )
{
unsigned int V_52 , V_54 ;
int V_141 , V_61 ;
struct V_142 V_41 ;
if ( F_4 ( V_132 != 0 ) )
return - V_140 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_39 = V_40 -> V_41 . V_39 ;
V_41 . V_39 &= ~ V_57 ;
V_52 = F_20 ( struct V_63 , V_41 ) ;
V_54 = sizeof( V_41 ) ;
V_141 = F_64 ( V_52 , V_54 , V_134 , V_135 , & V_41 , 0 , V_133 ) ;
if ( V_141 )
return V_141 ;
for ( V_61 = 0 ; V_61 < V_67 ; V_61 ++ ) {
if ( ( V_41 . V_39 >> V_61 ) & 1 ) {
void * V_143 = F_55 ( V_40 , 1 << V_61 ) ;
V_52 = V_65 [ V_61 ] ;
V_54 = V_55 [ V_61 ] ;
V_141 = F_64 ( V_52 , V_54 , V_134 , V_135 , V_143 , 0 , V_133 ) ;
if ( V_141 )
return V_141 ;
if ( V_52 + V_54 >= V_133 )
break;
}
}
V_52 = F_20 ( struct V_34 , V_144 ) ;
V_54 = sizeof( V_145 ) ;
V_141 = F_64 ( V_52 , V_54 , V_134 , V_135 , V_145 , 0 , V_133 ) ;
if ( V_141 )
return V_141 ;
return 0 ;
}
int F_67 ( const void * V_134 , const void T_5 * V_135 ,
struct V_63 * V_40 )
{
unsigned int V_52 , V_54 ;
int V_61 ;
T_1 V_39 ;
T_1 V_146 ;
V_52 = F_20 ( struct V_63 , V_41 ) ;
V_54 = sizeof( V_39 ) ;
if ( V_134 ) {
memcpy ( & V_39 , V_134 + V_52 , V_54 ) ;
} else {
if ( F_68 ( & V_39 , V_135 + V_52 , V_54 ) )
return - V_140 ;
}
V_146 = V_22 & ~ V_57 ;
if ( V_39 & ~ V_146 )
return - V_105 ;
for ( V_61 = 0 ; V_61 < V_67 ; V_61 ++ ) {
T_1 V_147 = ( ( T_1 ) 1 << V_61 ) ;
if ( V_39 & V_147 ) {
void * V_148 = F_55 ( V_40 , 1 << V_61 ) ;
V_52 = V_65 [ V_61 ] ;
V_54 = V_55 [ V_61 ] ;
if ( V_134 ) {
memcpy ( V_148 , V_134 + V_52 , V_54 ) ;
} else {
if ( F_68 ( V_148 , V_135 + V_52 , V_54 ) )
return - V_140 ;
}
}
}
V_40 -> V_41 . V_39 &= V_57 ;
V_40 -> V_41 . V_39 |= V_39 ;
return 0 ;
}
