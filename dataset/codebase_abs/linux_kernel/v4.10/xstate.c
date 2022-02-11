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
}
int F_3 ( T_1 V_21 , const char * * V_22 )
{
T_1 V_23 = V_21 & ~ V_24 ;
if ( F_4 ( V_22 ) ) {
long V_25 , V_26 ;
T_1 V_27 ;
if ( V_23 )
V_27 = V_23 ;
else
V_27 = V_21 ;
V_25 = F_5 ( V_27 ) - 1 ;
V_26 = F_6 ( V_28 ) - 1 ;
V_25 = F_7 ( V_25 , V_26 ) ;
* V_22 = V_28 [ V_25 ] ;
}
if ( V_23 )
return 0 ;
return 1 ;
}
static int F_8 ( int V_29 )
{
T_2 V_30 , V_31 , V_32 , V_33 ;
F_9 ( V_34 , V_29 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
return ! ! ( V_32 & 1 ) ;
}
static int F_10 ( int V_29 )
{
return ! F_8 ( V_29 ) ;
}
void F_11 ( struct V_35 * V_35 )
{
struct V_36 * V_37 = & V_35 -> V_38 . V_39 ;
int V_40 ;
T_1 V_41 ;
if ( ! F_12 () )
return;
V_41 = V_35 -> V_38 . V_42 . V_43 . V_41 ;
if ( ( V_41 & V_24 ) == V_24 )
return;
if ( ! ( V_41 & V_44 ) ) {
V_37 -> V_45 = 0x37f ;
V_37 -> V_46 = 0 ;
V_37 -> V_47 = 0 ;
V_37 -> V_48 = 0 ;
V_37 -> V_49 = 0 ;
V_37 -> V_50 = 0 ;
memset ( & V_37 -> V_51 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_41 & V_52 ) )
memset ( & V_37 -> V_53 [ 0 ] , 0 , 256 ) ;
V_40 = 0x2 ;
V_41 = ( V_24 & ~ V_41 ) >> 2 ;
while ( V_41 ) {
if ( V_41 & 0x1 ) {
int V_54 = V_55 [ V_40 ] ;
int V_56 = V_57 [ V_40 ] ;
memcpy ( ( void * ) V_37 + V_54 ,
( void * ) & V_58 . V_42 + V_54 ,
V_56 ) ;
}
V_41 >>= 1 ;
V_40 ++ ;
}
}
void F_13 ( void )
{
if ( ! F_14 ( V_1 ) || ! V_24 )
return;
F_15 ( ( V_24 & V_59 ) ,
L_1 ) ;
V_24 &= ~ V_59 ;
F_16 ( V_60 ) ;
F_17 ( V_61 , V_24 ) ;
}
static int F_18 ( enum V_62 V_62 )
{
return ! ! ( V_24 & ( 1UL << V_62 ) ) ;
}
static void T_3 F_19 ( void )
{
T_2 V_30 , V_31 , V_32 , V_33 , V_63 ;
unsigned int V_64 = F_20 ( struct V_65 ,
V_66 ) ;
V_67 [ 0 ] = 0 ;
V_57 [ 0 ] = F_20 ( struct V_36 , V_53 ) ;
V_67 [ 1 ] = V_57 [ 0 ] ;
V_57 [ 1 ] = F_21 ( struct V_36 , V_53 ) ;
for ( V_63 = V_68 ; V_63 < V_69 ; V_63 ++ ) {
if ( ! F_18 ( V_63 ) )
continue;
F_9 ( V_34 , V_63 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
if ( F_10 ( V_63 ) )
V_67 [ V_63 ] = V_31 ;
V_57 [ V_63 ] = V_30 ;
F_15 ( V_64 > V_67 [ V_63 ] ,
L_2 , V_64 ) ;
V_64 = V_67 [ V_63 ] ;
}
}
static void T_3 F_22 ( T_1 V_70 )
{
const char * V_22 ;
if ( F_3 ( V_70 , & V_22 ) )
F_23 ( L_3 , V_70 , V_22 ) ;
}
static void T_3 F_24 ( void )
{
F_22 ( V_44 ) ;
F_22 ( V_52 ) ;
F_22 ( V_71 ) ;
F_22 ( V_72 ) ;
F_22 ( V_73 ) ;
F_22 ( V_74 ) ;
F_22 ( V_75 ) ;
F_22 ( V_76 ) ;
F_22 ( V_77 ) ;
}
static int F_25 ( int V_29 )
{
T_2 V_30 , V_31 , V_32 , V_33 ;
F_26 ( V_29 ) ;
F_9 ( V_34 , V_29 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
return ! ! ( V_32 & 2 ) ;
}
static void T_3 F_27 ( void )
{
unsigned int V_78 [ sizeof( V_24 ) * 8 ] ;
int V_63 ;
V_55 [ 0 ] = 0 ;
V_55 [ 1 ] = F_20 ( struct V_36 , V_53 ) ;
if ( ! F_14 ( V_4 ) ) {
for ( V_63 = V_68 ; V_63 < V_69 ; V_63 ++ ) {
if ( F_18 ( V_63 ) ) {
V_55 [ V_63 ] = V_67 [ V_63 ] ;
V_78 [ V_63 ] = V_57 [ V_63 ] ;
}
}
return;
}
V_55 [ V_68 ] =
V_79 + V_80 ;
for ( V_63 = V_68 ; V_63 < V_69 ; V_63 ++ ) {
if ( F_18 ( V_63 ) )
V_78 [ V_63 ] = V_57 [ V_63 ] ;
else
V_78 [ V_63 ] = 0 ;
if ( V_63 > V_68 ) {
V_55 [ V_63 ] = V_55 [ V_63 - 1 ]
+ V_78 [ V_63 - 1 ] ;
if ( F_25 ( V_63 ) )
V_55 [ V_63 ] =
F_28 ( V_55 [ V_63 ] , 64 ) ;
}
}
}
static void T_3 F_29 ( void )
{
int V_63 ;
for ( V_63 = V_68 ; V_63 < V_69 ; V_63 ++ ) {
if ( ! F_18 ( V_63 ) )
continue;
F_23 ( L_4 ,
V_63 , V_55 [ V_63 ] , V_63 , V_57 [ V_63 ] ) ;
}
}
static void T_3 F_30 ( void )
{
static int T_4 V_81 = 1 ;
F_31 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_14 ( V_1 ) )
return;
F_19 () ;
F_24 () ;
if ( F_14 ( V_4 ) )
V_58 . V_42 . V_43 . V_82 = ( T_1 ) 1 << 63 | V_24 ;
F_32 ( & V_58 . V_42 ) ;
F_33 ( & V_58 . V_42 ) ;
}
static int F_34 ( int V_29 )
{
T_2 V_30 , V_31 , V_32 , V_33 ;
if ( V_59 & ( 1 << V_29 ) ) {
F_15 ( 1 , L_5 , V_29 ) ;
return - 1 ;
}
F_26 ( V_29 ) ;
F_9 ( V_34 , V_29 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
return V_31 ;
}
static int F_35 ( int V_29 )
{
T_2 V_30 , V_31 , V_32 , V_33 ;
F_26 ( V_29 ) ;
F_9 ( V_34 , V_29 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
return V_30 ;
}
int F_36 ( void )
{
return F_14 ( V_4 ) ;
}
static void F_37 ( void )
{
int V_63 ;
T_2 V_30 , V_31 , V_32 , V_33 ;
static int V_83 = 1 ;
if ( ! V_83 )
return;
V_83 = 0 ;
for ( V_63 = 0 ; V_63 < V_69 + 10 ; V_63 ++ ) {
F_9 ( V_34 , V_63 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
F_38 ( L_6 ,
V_34 , V_63 , V_30 , V_31 , V_32 , V_33 ) ;
}
}
static void F_39 ( int V_84 )
{
int V_85 = F_35 ( V_84 ) ;
F_40 ( V_85 , V_84 , V_86 , struct V_87 ) ;
F_40 ( V_85 , V_84 , V_88 , struct V_89 ) ;
F_40 ( V_85 , V_84 , V_90 , struct V_91 ) ;
F_40 ( V_85 , V_84 , V_92 , struct V_93 ) ;
F_40 ( V_85 , V_84 , V_94 , struct V_95 ) ;
F_40 ( V_85 , V_84 , V_96 , struct V_97 ) ;
F_40 ( V_85 , V_84 , V_98 , struct V_99 ) ;
if ( ( V_84 < V_86 ) ||
( V_84 >= V_69 ) ||
( V_84 == V_100 ) ) {
F_15 ( 1 , L_7 , V_84 ) ;
F_41 ( 1 ) ;
}
}
static void F_42 ( void )
{
int V_101 = V_79 + V_80 ;
int V_63 ;
for ( V_63 = V_68 ; V_63 < V_69 ; V_63 ++ ) {
if ( ! F_18 ( V_63 ) )
continue;
F_39 ( V_63 ) ;
if ( ! F_36 () )
F_41 ( F_8 ( V_63 ) ) ;
if ( F_25 ( V_63 ) )
V_101 = F_28 ( V_101 , 64 ) ;
if ( ! F_36 () )
V_101 = F_34 ( V_63 ) ;
V_101 += F_35 ( V_63 ) ;
}
F_41 ( V_101 != V_102 ) ;
}
static unsigned int T_3 F_43 ( void )
{
unsigned int V_30 , V_31 , V_32 , V_33 ;
F_9 ( V_34 , 1 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
return V_31 ;
}
static unsigned int T_3 F_44 ( void )
{
unsigned int V_30 , V_31 , V_32 , V_33 ;
F_9 ( V_34 , 0 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
return V_31 ;
}
static bool F_45 ( unsigned int V_103 )
{
if ( V_103 <= sizeof( union V_104 ) )
return true ;
F_38 ( L_8 ,
sizeof( union V_104 ) , V_103 ) ;
return false ;
}
static int F_46 ( void )
{
unsigned int V_105 ;
unsigned int V_106 ;
V_106 = F_44 () ;
if ( F_14 ( V_4 ) )
V_105 = F_43 () ;
else
V_105 = V_106 ;
if ( ! F_45 ( V_105 ) )
return - V_107 ;
V_102 = V_105 ;
F_42 () ;
V_108 = V_106 ;
return 0 ;
}
static void F_47 ( void )
{
V_24 = 0 ;
F_48 ( V_60 ) ;
F_1 () ;
}
void T_3 F_49 ( void )
{
unsigned int V_30 , V_31 , V_32 , V_33 ;
static int T_4 V_81 = 1 ;
int V_109 ;
F_31 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_14 ( V_1 ) ) {
F_23 ( L_9 ) ;
return;
}
if ( V_110 . V_111 < V_34 ) {
F_31 ( 1 ) ;
return;
}
F_9 ( V_34 , 0 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
V_24 = V_30 + ( ( T_1 ) V_33 << 32 ) ;
if ( ( V_24 & V_112 ) != V_112 ) {
F_50 ( L_10 , V_24 ) ;
goto V_113;
}
V_24 &= F_51 () ;
F_13 () ;
V_109 = F_46 () ;
if ( V_109 )
goto V_113;
F_52 ( V_108 , V_24 & ~ V_59 ) ;
F_53 () ;
F_30 () ;
F_27 () ;
F_29 () ;
F_23 ( L_11 ,
V_24 ,
V_102 ,
F_14 ( V_4 ) ? L_12 : L_13 ) ;
return;
V_113:
F_47 () ;
}
void F_54 ( void )
{
if ( F_14 ( V_1 ) )
F_17 ( V_61 , V_24 ) ;
}
void * F_55 ( struct V_65 * V_42 , int V_114 )
{
int V_115 = F_5 ( V_114 ) - 1 ;
if ( ! F_18 ( V_115 ) ) {
F_31 ( 1 ) ;
return NULL ;
}
return ( void * ) V_42 + V_55 [ V_115 ] ;
}
void * F_56 ( struct V_65 * V_42 , int V_116 )
{
if ( ! F_14 ( V_1 ) )
return NULL ;
F_15 ( ! ( V_24 & V_116 ) ,
L_14 ) ;
if ( ! ( V_42 -> V_43 . V_41 & V_116 ) )
return NULL ;
return F_55 ( V_42 , V_116 ) ;
}
const void * F_57 ( int V_117 )
{
struct V_35 * V_35 = & V_118 -> V_119 . V_35 ;
if ( ! V_35 -> V_120 )
return NULL ;
F_58 ( V_35 ) ;
return F_56 ( & V_35 -> V_38 . V_42 , V_117 ) ;
}
int F_59 ( struct V_121 * V_122 , int V_123 ,
unsigned long V_124 )
{
T_2 V_125 ;
int V_126 = ( V_123 * V_127 ) ;
T_2 V_128 = 0 ;
if ( ! F_14 ( V_129 ) )
return - V_107 ;
if ( V_124 & V_130 )
V_128 |= V_131 ;
if ( V_124 & V_132 )
V_128 |= V_133 ;
V_128 <<= V_126 ;
V_125 = F_60 () ;
V_125 &= ~ ( ( V_131 | V_133 ) << V_126 ) ;
F_61 ( V_125 | V_128 ) ;
return 0 ;
}
static inline int F_62 ( unsigned int V_134 , unsigned int V_135 ,
void * V_136 , void T_5 * V_137 ,
const void * V_138 , const int V_139 ,
const int V_140 )
{
if ( ( V_135 == 0 ) || ( V_134 < V_139 ) )
return 0 ;
if ( V_140 < 0 || V_134 < V_140 ) {
unsigned int V_141 = ( V_140 < 0 ? V_135 : F_7 ( V_135 , V_140 - V_134 ) ) ;
if ( V_136 ) {
memcpy ( V_136 + V_134 , V_138 , V_141 ) ;
} else {
if ( F_63 ( V_137 + V_134 , V_138 , V_141 ) )
return - V_142 ;
}
}
return 0 ;
}
int F_64 ( unsigned int V_134 , unsigned int V_135 , void * V_136 ,
void T_5 * V_137 , struct V_65 * V_42 )
{
unsigned int V_54 , V_56 ;
int V_143 , V_63 ;
struct V_144 V_43 ;
if ( F_4 ( V_134 != 0 ) )
return - V_142 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_41 = V_42 -> V_43 . V_41 ;
V_43 . V_41 &= ~ V_59 ;
V_54 = F_20 ( struct V_65 , V_43 ) ;
V_56 = sizeof( V_43 ) ;
V_143 = F_62 ( V_54 , V_56 , V_136 , V_137 , & V_43 , 0 , V_135 ) ;
if ( V_143 )
return V_143 ;
for ( V_63 = 0 ; V_63 < V_69 ; V_63 ++ ) {
if ( ( V_43 . V_41 >> V_63 ) & 1 ) {
void * V_145 = F_55 ( V_42 , 1 << V_63 ) ;
V_54 = V_67 [ V_63 ] ;
V_56 = V_57 [ V_63 ] ;
V_143 = F_62 ( V_54 , V_56 , V_136 , V_137 , V_145 , 0 , V_135 ) ;
if ( V_143 )
return V_143 ;
if ( V_54 + V_56 >= V_135 )
break;
}
}
V_54 = F_20 ( struct V_36 , V_146 ) ;
V_56 = sizeof( V_147 ) ;
V_143 = F_62 ( V_54 , V_56 , V_136 , V_137 , V_147 , 0 , V_135 ) ;
if ( V_143 )
return V_143 ;
return 0 ;
}
int F_65 ( const void * V_136 , const void T_5 * V_137 ,
struct V_65 * V_42 )
{
unsigned int V_54 , V_56 ;
int V_63 ;
T_1 V_41 ;
T_1 V_148 ;
V_54 = F_20 ( struct V_65 , V_43 ) ;
V_56 = sizeof( V_41 ) ;
if ( V_136 ) {
memcpy ( & V_41 , V_136 + V_54 , V_56 ) ;
} else {
if ( F_66 ( & V_41 , V_137 + V_54 , V_56 ) )
return - V_142 ;
}
V_148 = V_24 & ~ V_59 ;
if ( V_41 & ~ V_148 )
return - V_107 ;
for ( V_63 = 0 ; V_63 < V_69 ; V_63 ++ ) {
T_1 V_149 = ( ( T_1 ) 1 << V_63 ) ;
if ( V_41 & V_149 ) {
void * V_150 = F_55 ( V_42 , 1 << V_63 ) ;
V_54 = V_67 [ V_63 ] ;
V_56 = V_57 [ V_63 ] ;
if ( V_136 ) {
memcpy ( V_150 , V_136 + V_54 , V_56 ) ;
} else {
if ( F_66 ( V_150 , V_137 + V_54 , V_56 ) )
return - V_142 ;
}
}
}
V_42 -> V_43 . V_41 &= V_59 ;
V_42 -> V_43 . V_41 |= V_41 ;
return 0 ;
}
