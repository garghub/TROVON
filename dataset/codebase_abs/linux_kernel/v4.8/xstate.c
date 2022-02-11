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
}
int F_3 ( T_1 V_17 , const char * * V_18 )
{
T_1 V_19 = V_17 & ~ V_20 ;
if ( F_4 ( V_18 ) ) {
long V_21 , V_22 ;
T_1 V_23 ;
if ( V_19 )
V_23 = V_19 ;
else
V_23 = V_17 ;
V_21 = F_5 ( V_23 ) - 1 ;
V_22 = F_6 ( V_24 ) - 1 ;
V_21 = F_7 ( V_21 , V_22 ) ;
* V_18 = V_24 [ V_21 ] ;
}
if ( V_19 )
return 0 ;
return 1 ;
}
static int F_8 ( int V_25 )
{
T_2 V_26 , V_27 , V_28 , V_29 ;
F_9 ( V_30 , V_25 , & V_26 , & V_27 , & V_28 , & V_29 ) ;
return ! ! ( V_28 & 1 ) ;
}
static int F_10 ( int V_25 )
{
return ! F_8 ( V_25 ) ;
}
void F_11 ( struct V_31 * V_31 )
{
struct V_32 * V_33 = & V_31 -> V_34 . V_35 ;
int V_36 ;
T_1 V_37 ;
if ( ! F_12 () )
return;
V_37 = V_31 -> V_34 . V_38 . V_39 . V_37 ;
if ( ( V_37 & V_20 ) == V_20 )
return;
if ( ! ( V_37 & V_40 ) ) {
V_33 -> V_41 = 0x37f ;
V_33 -> V_42 = 0 ;
V_33 -> V_43 = 0 ;
V_33 -> V_44 = 0 ;
V_33 -> V_45 = 0 ;
V_33 -> V_46 = 0 ;
memset ( & V_33 -> V_47 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_37 & V_48 ) )
memset ( & V_33 -> V_49 [ 0 ] , 0 , 256 ) ;
V_36 = 0x2 ;
V_37 = ( V_20 & ~ V_37 ) >> 2 ;
while ( V_37 ) {
if ( V_37 & 0x1 ) {
int V_50 = V_51 [ V_36 ] ;
int V_52 = V_53 [ V_36 ] ;
memcpy ( ( void * ) V_33 + V_50 ,
( void * ) & V_54 . V_38 + V_50 ,
V_52 ) ;
}
V_37 >>= 1 ;
V_36 ++ ;
}
}
void F_13 ( void )
{
if ( ! F_14 ( V_1 ) || ! V_20 )
return;
F_15 ( ( V_20 & V_55 ) ,
L_1 ) ;
V_20 &= ~ V_55 ;
F_16 ( V_56 ) ;
F_17 ( V_57 , V_20 ) ;
}
static int F_18 ( enum V_58 V_58 )
{
return ! ! ( V_20 & ( 1UL << V_58 ) ) ;
}
static void T_3 F_19 ( void )
{
T_2 V_26 , V_27 , V_28 , V_29 , V_59 ;
unsigned int V_60 = F_20 ( struct V_61 ,
V_62 ) ;
V_63 [ 0 ] = 0 ;
V_53 [ 0 ] = F_20 ( struct V_32 , V_49 ) ;
V_63 [ 1 ] = V_53 [ 0 ] ;
V_53 [ 1 ] = F_21 ( struct V_32 , V_49 ) ;
for ( V_59 = V_64 ; V_59 < V_65 ; V_59 ++ ) {
if ( ! F_18 ( V_59 ) )
continue;
F_9 ( V_30 , V_59 , & V_26 , & V_27 , & V_28 , & V_29 ) ;
if ( F_10 ( V_59 ) )
V_63 [ V_59 ] = V_27 ;
V_53 [ V_59 ] = V_26 ;
F_15 ( V_60 > V_63 [ V_59 ] ,
L_2 , V_60 ) ;
V_60 = V_63 [ V_59 ] ;
}
}
static void T_3 F_22 ( T_1 V_66 )
{
const char * V_18 ;
if ( F_3 ( V_66 , & V_18 ) )
F_23 ( L_3 , V_66 , V_18 ) ;
}
static void T_3 F_24 ( void )
{
F_22 ( V_40 ) ;
F_22 ( V_48 ) ;
F_22 ( V_67 ) ;
F_22 ( V_68 ) ;
F_22 ( V_69 ) ;
F_22 ( V_70 ) ;
F_22 ( V_71 ) ;
F_22 ( V_72 ) ;
F_22 ( V_73 ) ;
}
static int F_25 ( int V_25 )
{
T_2 V_26 , V_27 , V_28 , V_29 ;
F_26 ( V_25 ) ;
F_9 ( V_30 , V_25 , & V_26 , & V_27 , & V_28 , & V_29 ) ;
return ! ! ( V_28 & 2 ) ;
}
static void T_3 F_27 ( void )
{
unsigned int V_74 [ sizeof( V_20 ) * 8 ] ;
int V_59 ;
V_51 [ 0 ] = 0 ;
V_51 [ 1 ] = F_20 ( struct V_32 , V_49 ) ;
if ( ! F_14 ( V_4 ) ) {
for ( V_59 = V_64 ; V_59 < V_65 ; V_59 ++ ) {
if ( F_18 ( V_59 ) ) {
V_51 [ V_59 ] = V_63 [ V_59 ] ;
V_74 [ V_59 ] = V_53 [ V_59 ] ;
}
}
return;
}
V_51 [ V_64 ] =
V_75 + V_76 ;
for ( V_59 = V_64 ; V_59 < V_65 ; V_59 ++ ) {
if ( F_18 ( V_59 ) )
V_74 [ V_59 ] = V_53 [ V_59 ] ;
else
V_74 [ V_59 ] = 0 ;
if ( V_59 > V_64 ) {
V_51 [ V_59 ] = V_51 [ V_59 - 1 ]
+ V_74 [ V_59 - 1 ] ;
if ( F_25 ( V_59 ) )
V_51 [ V_59 ] =
F_28 ( V_51 [ V_59 ] , 64 ) ;
}
}
}
static void T_3 F_29 ( void )
{
int V_59 ;
for ( V_59 = V_64 ; V_59 < V_65 ; V_59 ++ ) {
if ( ! F_18 ( V_59 ) )
continue;
F_23 ( L_4 ,
V_59 , V_51 [ V_59 ] , V_59 , V_53 [ V_59 ] ) ;
}
}
static void T_3 F_30 ( void )
{
static int T_4 V_77 = 1 ;
F_31 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_14 ( V_1 ) )
return;
F_19 () ;
F_24 () ;
if ( F_14 ( V_4 ) )
V_54 . V_38 . V_39 . V_78 = ( T_1 ) 1 << 63 | V_20 ;
F_32 ( & V_54 . V_38 ) ;
F_33 ( & V_54 . V_38 ) ;
}
static int F_34 ( int V_25 )
{
T_2 V_26 , V_27 , V_28 , V_29 ;
if ( V_55 & ( 1 << V_25 ) ) {
F_15 ( 1 , L_5 , V_25 ) ;
return - 1 ;
}
F_26 ( V_25 ) ;
F_9 ( V_30 , V_25 , & V_26 , & V_27 , & V_28 , & V_29 ) ;
return V_27 ;
}
static int F_35 ( int V_25 )
{
T_2 V_26 , V_27 , V_28 , V_29 ;
F_26 ( V_25 ) ;
F_9 ( V_30 , V_25 , & V_26 , & V_27 , & V_28 , & V_29 ) ;
return V_26 ;
}
int F_36 ( void )
{
return F_14 ( V_4 ) ;
}
static void F_37 ( void )
{
int V_59 ;
T_2 V_26 , V_27 , V_28 , V_29 ;
static int V_79 = 1 ;
if ( ! V_79 )
return;
V_79 = 0 ;
for ( V_59 = 0 ; V_59 < V_65 + 10 ; V_59 ++ ) {
F_9 ( V_30 , V_59 , & V_26 , & V_27 , & V_28 , & V_29 ) ;
F_38 ( L_6 ,
V_30 , V_59 , V_26 , V_27 , V_28 , V_29 ) ;
}
}
static void F_39 ( int V_80 )
{
int V_81 = F_35 ( V_80 ) ;
F_40 ( V_81 , V_80 , V_82 , struct V_83 ) ;
F_40 ( V_81 , V_80 , V_84 , struct V_85 ) ;
F_40 ( V_81 , V_80 , V_86 , struct V_87 ) ;
F_40 ( V_81 , V_80 , V_88 , struct V_89 ) ;
F_40 ( V_81 , V_80 , V_90 , struct V_91 ) ;
F_40 ( V_81 , V_80 , V_92 , struct V_93 ) ;
F_40 ( V_81 , V_80 , V_94 , struct V_95 ) ;
if ( ( V_80 < V_82 ) ||
( V_80 >= V_65 ) ||
( V_80 == V_96 ) ) {
F_15 ( 1 , L_7 , V_80 ) ;
F_41 ( 1 ) ;
}
}
static void F_42 ( void )
{
int V_97 = V_75 + V_76 ;
int V_59 ;
for ( V_59 = V_64 ; V_59 < V_65 ; V_59 ++ ) {
if ( ! F_18 ( V_59 ) )
continue;
F_39 ( V_59 ) ;
if ( ! F_36 () )
F_41 ( F_8 ( V_59 ) ) ;
if ( F_25 ( V_59 ) )
V_97 = F_28 ( V_97 , 64 ) ;
if ( ! F_36 () )
V_97 = F_34 ( V_59 ) ;
V_97 += F_35 ( V_59 ) ;
}
F_41 ( V_97 != V_98 ) ;
}
static unsigned int T_3 F_43 ( void )
{
unsigned int V_26 , V_27 , V_28 , V_29 ;
F_9 ( V_30 , 1 , & V_26 , & V_27 , & V_28 , & V_29 ) ;
return V_27 ;
}
static unsigned int T_3 F_44 ( void )
{
unsigned int V_26 , V_27 , V_28 , V_29 ;
F_9 ( V_30 , 0 , & V_26 , & V_27 , & V_28 , & V_29 ) ;
return V_27 ;
}
static bool F_45 ( unsigned int V_99 )
{
if ( V_99 <= sizeof( union V_100 ) )
return true ;
F_38 ( L_8 ,
sizeof( union V_100 ) , V_99 ) ;
return false ;
}
static int F_46 ( void )
{
unsigned int V_101 ;
unsigned int V_102 ;
V_102 = F_44 () ;
if ( F_14 ( V_4 ) )
V_101 = F_43 () ;
else
V_101 = V_102 ;
if ( ! F_45 ( V_101 ) )
return - V_103 ;
V_98 = V_101 ;
F_42 () ;
V_104 = V_102 ;
return 0 ;
}
static void F_47 ( void )
{
V_20 = 0 ;
F_48 ( V_56 ) ;
F_1 () ;
}
void T_3 F_49 ( void )
{
unsigned int V_26 , V_27 , V_28 , V_29 ;
static int T_4 V_77 = 1 ;
int V_105 ;
F_31 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_14 ( V_1 ) ) {
F_23 ( L_9 ) ;
return;
}
if ( V_106 . V_107 < V_30 ) {
F_31 ( 1 ) ;
return;
}
F_9 ( V_30 , 0 , & V_26 , & V_27 , & V_28 , & V_29 ) ;
V_20 = V_26 + ( ( T_1 ) V_29 << 32 ) ;
if ( ( V_20 & V_108 ) != V_108 ) {
F_50 ( L_10 , V_20 ) ;
goto V_109;
}
V_20 &= F_51 () ;
F_13 () ;
V_105 = F_46 () ;
if ( V_105 )
goto V_109;
F_52 ( V_104 , V_20 & ~ V_55 ) ;
F_53 () ;
F_30 () ;
F_27 () ;
F_29 () ;
F_23 ( L_11 ,
V_20 ,
V_98 ,
F_14 ( V_4 ) ? L_12 : L_13 ) ;
return;
V_109:
F_47 () ;
}
void F_54 ( void )
{
if ( F_14 ( V_1 ) )
F_17 ( V_57 , V_20 ) ;
}
void * F_55 ( struct V_61 * V_38 , int V_110 )
{
int V_111 = F_5 ( V_110 ) - 1 ;
if ( ! F_18 ( V_111 ) ) {
F_31 ( 1 ) ;
return NULL ;
}
return ( void * ) V_38 + V_51 [ V_111 ] ;
}
void * F_56 ( struct V_61 * V_38 , int V_112 )
{
if ( ! F_14 ( V_1 ) )
return NULL ;
F_15 ( ! ( V_20 & V_112 ) ,
L_14 ) ;
if ( ! ( V_38 -> V_39 . V_37 & V_112 ) )
return NULL ;
return F_55 ( V_38 , V_112 ) ;
}
const void * F_57 ( int V_113 )
{
struct V_31 * V_31 = & V_114 -> V_115 . V_31 ;
if ( ! V_31 -> V_116 )
return NULL ;
F_58 ( V_31 ) ;
return F_56 ( & V_31 -> V_34 . V_38 , V_113 ) ;
}
int F_59 ( struct V_117 * V_118 , int V_119 ,
unsigned long V_120 )
{
T_2 V_121 ;
int V_122 = ( V_119 * V_123 ) ;
T_2 V_124 = 0 ;
if ( ! F_14 ( V_125 ) )
return - V_103 ;
F_60 ( ! F_61 () ) ;
if ( V_120 & V_126 )
V_124 |= V_127 ;
if ( V_120 & V_128 )
V_124 |= V_129 ;
V_124 <<= V_122 ;
V_121 = F_62 () ;
V_121 &= ~ ( ( V_127 | V_129 ) << V_122 ) ;
F_63 ( V_121 | V_124 ) ;
return 0 ;
}
static inline int F_64 ( unsigned int V_130 , unsigned int V_131 ,
void * V_132 , void T_5 * V_133 ,
const void * V_134 , const int V_135 ,
const int V_136 )
{
if ( ( V_131 == 0 ) || ( V_130 < V_135 ) )
return 0 ;
if ( V_136 < 0 || V_130 < V_136 ) {
unsigned int V_137 = ( V_136 < 0 ? V_131 : F_7 ( V_131 , V_136 - V_130 ) ) ;
if ( V_132 ) {
memcpy ( V_132 + V_130 , V_134 , V_137 ) ;
} else {
if ( F_65 ( V_133 + V_130 , V_134 , V_137 ) )
return - V_138 ;
}
}
return 0 ;
}
int F_66 ( unsigned int V_130 , unsigned int V_131 , void * V_132 ,
void T_5 * V_133 , struct V_61 * V_38 )
{
unsigned int V_50 , V_52 ;
int V_139 , V_59 ;
struct V_140 V_39 ;
if ( F_4 ( V_130 != 0 ) )
return - V_138 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_37 = V_38 -> V_39 . V_37 ;
V_39 . V_37 &= ~ V_55 ;
V_50 = F_20 ( struct V_61 , V_39 ) ;
V_52 = sizeof( V_39 ) ;
V_139 = F_64 ( V_50 , V_52 , V_132 , V_133 , & V_39 , 0 , V_131 ) ;
if ( V_139 )
return V_139 ;
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ ) {
if ( ( V_39 . V_37 >> V_59 ) & 1 ) {
void * V_141 = F_55 ( V_38 , 1 << V_59 ) ;
V_50 = V_63 [ V_59 ] ;
V_52 = V_53 [ V_59 ] ;
V_139 = F_64 ( V_50 , V_52 , V_132 , V_133 , V_141 , 0 , V_131 ) ;
if ( V_139 )
return V_139 ;
if ( V_50 + V_52 >= V_131 )
break;
}
}
V_50 = F_20 ( struct V_32 , V_142 ) ;
V_52 = sizeof( V_143 ) ;
V_139 = F_64 ( V_50 , V_52 , V_132 , V_133 , V_143 , 0 , V_131 ) ;
if ( V_139 )
return V_139 ;
return 0 ;
}
int F_67 ( const void * V_132 , const void T_5 * V_133 ,
struct V_61 * V_38 )
{
unsigned int V_50 , V_52 ;
int V_59 ;
T_1 V_37 ;
T_1 V_144 ;
V_50 = F_20 ( struct V_61 , V_39 ) ;
V_52 = sizeof( V_37 ) ;
if ( V_132 ) {
memcpy ( & V_37 , V_132 + V_50 , V_52 ) ;
} else {
if ( F_68 ( & V_37 , V_133 + V_50 , V_52 ) )
return - V_138 ;
}
V_144 = V_20 & ~ V_55 ;
if ( V_37 & ~ V_144 )
return - V_103 ;
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ ) {
T_1 V_145 = ( ( T_1 ) 1 << V_59 ) ;
if ( V_37 & V_145 ) {
void * V_146 = F_55 ( V_38 , 1 << V_59 ) ;
V_50 = V_63 [ V_59 ] ;
V_52 = V_53 [ V_59 ] ;
if ( V_132 ) {
memcpy ( V_146 , V_132 + V_50 , V_52 ) ;
} else {
if ( F_68 ( V_146 , V_133 + V_50 , V_52 ) )
return - V_138 ;
}
}
}
V_38 -> V_39 . V_37 &= V_55 ;
V_38 -> V_39 . V_37 |= V_37 ;
return 0 ;
}
