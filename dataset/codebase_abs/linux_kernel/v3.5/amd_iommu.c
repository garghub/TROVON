static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_5 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_2 = V_2 ;
F_3 ( & V_3 -> V_6 , 0 ) ;
F_4 ( & V_7 , V_4 ) ;
F_5 ( & V_3 -> V_8 , & V_8 ) ;
F_6 ( & V_7 , V_4 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_3 )
{
unsigned long V_4 ;
F_4 ( & V_7 , V_4 ) ;
F_8 ( & V_3 -> V_8 ) ;
F_6 ( & V_7 , V_4 ) ;
F_9 ( V_3 ) ;
}
static struct V_1 * F_10 ( T_1 V_2 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
F_4 ( & V_7 , V_4 ) ;
F_11 (dev_data, &dev_data_list, dev_data_list) {
if ( V_3 -> V_2 == V_2 )
goto V_9;
}
V_3 = NULL ;
V_9:
F_6 ( & V_7 , V_4 ) ;
return V_3 ;
}
static struct V_1 * F_12 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_10 ( V_2 ) ;
if ( V_3 == NULL )
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
static inline T_1 F_13 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
return F_15 ( V_13 -> V_14 -> V_15 , V_13 -> V_16 ) ;
}
static struct V_1 * F_16 ( struct V_10 * V_11 )
{
return V_11 -> V_17 . V_18 ;
}
static bool F_17 ( struct V_12 * V_13 )
{
static const int V_19 [] = {
V_20 ,
V_21 ,
V_22 ,
} ;
int V_23 , V_24 ;
for ( V_23 = 0 ; V_23 < 3 ; ++ V_23 ) {
V_24 = F_18 ( V_13 , V_19 [ V_23 ] ) ;
if ( V_24 == 0 )
return false ;
}
return true ;
}
static bool F_19 ( struct V_12 * V_13 , T_2 V_25 )
{
struct V_1 * V_3 ;
V_3 = F_16 ( & V_13 -> V_11 ) ;
return V_3 -> V_26 & ( 1 << V_25 ) ? true : false ;
}
static struct V_27 * F_20 ( T_1 V_2 )
{
struct V_27 * V_28 , * V_29 = NULL ;
unsigned long V_4 ;
T_1 V_30 = V_31 [ V_2 ] ;
if ( F_21 ( & V_32 ) )
return NULL ;
F_4 ( & V_33 , V_4 ) ;
F_11 (entry, &iommu_pd_list, list) {
if ( V_28 -> V_34 == V_2 ||
V_28 -> V_34 == V_30 ) {
V_29 = V_28 ;
break;
}
}
F_6 ( & V_33 , V_4 ) ;
return V_29 ;
}
static bool F_22 ( struct V_10 * V_11 )
{
T_1 V_2 ;
if ( ! V_11 || ! V_11 -> V_35 )
return false ;
if ( V_11 -> V_14 != & V_36 )
return false ;
V_2 = F_13 ( V_11 ) ;
if ( V_2 > V_37 )
return false ;
if ( V_38 [ V_2 ] == NULL )
return false ;
return true ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
T_1 V_30 ;
if ( V_11 -> V_17 . V_18 )
return 0 ;
V_3 = F_12 ( F_13 ( V_11 ) ) ;
if ( ! V_3 )
return - V_39 ;
V_30 = V_31 [ V_3 -> V_2 ] ;
if ( V_30 != V_3 -> V_2 ) {
struct V_1 * V_40 ;
V_40 = F_12 ( V_30 ) ;
if ( V_40 == NULL ) {
F_24 ( L_1 ,
F_25 ( V_11 ) ) ;
F_7 ( V_3 ) ;
return - V_41 ;
}
V_3 -> V_40 = V_40 ;
}
if ( F_17 ( V_13 ) ) {
struct V_42 * V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_3 -> V_43 = V_18 -> V_44 ;
}
V_11 -> V_17 . V_18 = V_3 ;
return 0 ;
}
static void F_26 ( struct V_10 * V_11 )
{
T_1 V_2 , V_30 ;
V_2 = F_13 ( V_11 ) ;
V_30 = V_31 [ V_2 ] ;
memset ( & V_45 [ V_2 ] , 0 , sizeof( struct V_46 ) ) ;
memset ( & V_45 [ V_30 ] , 0 , sizeof( struct V_46 ) ) ;
V_38 [ V_2 ] = NULL ;
V_38 [ V_30 ] = NULL ;
}
static void F_27 ( struct V_10 * V_11 )
{
}
void T_3 F_28 ( void )
{
struct V_1 * V_3 , * V_47 ;
struct V_12 * V_13 = NULL ;
F_29 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) )
continue;
F_27 ( & V_13 -> V_11 ) ;
}
F_30 (dev_data, n, &dev_data_list, dev_data_list)
F_7 ( V_3 ) ;
}
int T_3 F_31 ( void )
{
struct V_12 * V_13 = NULL ;
int V_29 = 0 ;
F_29 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) )
continue;
V_29 = F_23 ( & V_13 -> V_11 ) ;
if ( V_29 == - V_41 )
F_26 ( & V_13 -> V_11 ) ;
else if ( V_29 )
goto V_48;
}
return 0 ;
V_48:
F_28 () ;
return V_29 ;
}
static void F_32 ( struct V_49 * V_50 )
{
if ( V_51 == NULL )
return;
V_50 -> V_52 = F_33 ( V_50 -> V_53 , 0444 , V_51 ,
& V_50 -> V_54 ) ;
}
static void F_34 ( void )
{
V_51 = F_35 ( L_2 , NULL ) ;
if ( V_51 == NULL )
return;
V_55 = F_36 ( L_3 , 0444 , V_51 ,
& V_56 ) ;
F_32 ( & V_57 ) ;
F_32 ( & V_58 ) ;
F_32 ( & V_59 ) ;
F_32 ( & V_60 ) ;
F_32 ( & V_61 ) ;
F_32 ( & V_62 ) ;
F_32 ( & V_63 ) ;
F_32 ( & V_64 ) ;
F_32 ( & V_65 ) ;
F_32 ( & V_66 ) ;
F_32 ( & V_67 ) ;
F_32 ( & V_68 ) ;
F_32 ( & V_69 ) ;
F_32 ( & V_70 ) ;
F_32 ( & V_71 ) ;
F_32 ( & V_72 ) ;
}
static void F_37 ( T_1 V_2 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 )
F_24 ( L_4 , V_23 ,
V_45 [ V_2 ] . V_73 [ V_23 ] ) ;
}
static void F_38 ( unsigned long V_74 )
{
struct V_75 * V_76 = F_39 ( V_74 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 )
F_24 ( L_5 , V_23 , V_76 -> V_73 [ V_23 ] ) ;
}
static void F_40 ( struct V_42 * V_18 , void * V_77 )
{
int type , V_2 , V_78 , V_4 ;
volatile T_2 * V_79 = V_77 ;
int V_80 = 0 ;
T_4 V_81 ;
V_82:
type = ( V_79 [ 1 ] >> V_83 ) & V_84 ;
V_2 = ( V_79 [ 0 ] >> V_85 ) & V_86 ;
V_78 = ( V_79 [ 1 ] >> V_87 ) & V_88 ;
V_4 = ( V_79 [ 1 ] >> V_89 ) & V_90 ;
V_81 = ( T_4 ) ( ( ( T_4 ) V_79 [ 3 ] ) << 32 ) | V_79 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_80 == V_91 ) {
F_24 ( L_6 ) ;
return;
}
F_41 ( 1 ) ;
goto V_82;
}
F_42 ( V_92 L_7 ) ;
switch ( type ) {
case V_93 :
F_42 ( L_8
L_9 ,
F_43 ( V_2 ) , F_44 ( V_2 ) , F_45 ( V_2 ) ,
V_81 , V_4 ) ;
F_37 ( V_2 ) ;
break;
case V_94 :
F_42 ( L_10
L_11 ,
F_43 ( V_2 ) , F_44 ( V_2 ) , F_45 ( V_2 ) ,
V_78 , V_81 , V_4 ) ;
break;
case V_95 :
F_42 ( L_12
L_9 ,
F_43 ( V_2 ) , F_44 ( V_2 ) , F_45 ( V_2 ) ,
V_81 , V_4 ) ;
break;
case V_96 :
F_42 ( L_13
L_11 ,
F_43 ( V_2 ) , F_44 ( V_2 ) , F_45 ( V_2 ) ,
V_78 , V_81 , V_4 ) ;
break;
case V_97 :
F_42 ( L_14 , V_81 ) ;
F_38 ( V_81 ) ;
break;
case V_98 :
F_42 ( L_15
L_16 , V_81 , V_4 ) ;
break;
case V_99 :
F_42 ( L_17
L_18 ,
F_43 ( V_2 ) , F_44 ( V_2 ) , F_45 ( V_2 ) ,
V_81 ) ;
break;
case V_100 :
F_42 ( L_19
L_9 ,
F_43 ( V_2 ) , F_44 ( V_2 ) , F_45 ( V_2 ) ,
V_81 , V_4 ) ;
break;
default:
F_42 ( V_92 L_20 , type ) ;
}
memset ( V_77 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_46 ( struct V_42 * V_18 )
{
T_2 V_101 , V_102 ;
unsigned long V_4 ;
F_4 ( & V_18 -> V_103 , V_4 ) ;
V_101 = F_47 ( V_18 -> V_104 + V_105 ) ;
V_102 = F_47 ( V_18 -> V_104 + V_106 ) ;
while ( V_101 != V_102 ) {
F_40 ( V_18 , V_18 -> V_107 + V_101 ) ;
V_101 = ( V_101 + V_108 ) % V_18 -> V_109 ;
}
F_48 ( V_101 , V_18 -> V_104 + V_105 ) ;
F_6 ( & V_18 -> V_103 , V_4 ) ;
}
static void F_49 ( struct V_42 * V_18 , T_4 * V_110 )
{
struct V_111 V_112 ;
F_50 ( V_72 ) ;
if ( F_51 ( V_110 [ 0 ] ) != V_113 ) {
F_52 ( L_21 ) ;
return;
}
V_112 . V_81 = V_110 [ 1 ] ;
V_112 . V_114 = F_53 ( V_110 [ 0 ] ) ;
V_112 . V_115 = F_54 ( V_110 [ 0 ] ) ;
V_112 . V_116 = F_55 ( V_110 [ 0 ] ) ;
V_112 . V_4 = F_56 ( V_110 [ 0 ] ) ;
F_57 ( & V_117 , 0 , & V_112 ) ;
}
static void F_58 ( struct V_42 * V_18 )
{
unsigned long V_4 ;
T_2 V_101 , V_102 ;
if ( V_18 -> V_118 == NULL )
return;
F_48 ( V_119 , V_18 -> V_104 + V_120 ) ;
F_4 ( & V_18 -> V_103 , V_4 ) ;
V_101 = F_47 ( V_18 -> V_104 + V_121 ) ;
V_102 = F_47 ( V_18 -> V_104 + V_122 ) ;
while ( V_101 != V_102 ) {
volatile T_4 * V_110 ;
T_4 V_28 [ 2 ] ;
int V_23 ;
V_110 = ( T_4 * ) ( V_18 -> V_118 + V_101 ) ;
for ( V_23 = 0 ; V_23 < V_91 ; ++ V_23 ) {
if ( F_51 ( V_110 [ 0 ] ) != 0 )
break;
F_41 ( 1 ) ;
}
V_28 [ 0 ] = V_110 [ 0 ] ;
V_28 [ 1 ] = V_110 [ 1 ] ;
V_110 [ 0 ] = V_110 [ 1 ] = 0UL ;
V_101 = ( V_101 + V_123 ) % V_124 ;
F_48 ( V_101 , V_18 -> V_104 + V_121 ) ;
F_6 ( & V_18 -> V_103 , V_4 ) ;
F_49 ( V_18 , V_28 ) ;
F_4 ( & V_18 -> V_103 , V_4 ) ;
V_101 = F_47 ( V_18 -> V_104 + V_121 ) ;
V_102 = F_47 ( V_18 -> V_104 + V_122 ) ;
}
F_6 ( & V_18 -> V_103 , V_4 ) ;
}
T_5 F_59 ( int V_125 , void * V_73 )
{
struct V_42 * V_18 ;
F_60 (iommu) {
F_46 ( V_18 ) ;
F_58 ( V_18 ) ;
}
return V_126 ;
}
T_5 F_61 ( int V_125 , void * V_73 )
{
return V_127 ;
}
static int F_62 ( volatile T_4 * V_128 )
{
int V_23 = 0 ;
while ( * V_128 == 0 && V_23 < V_91 ) {
F_41 ( 1 ) ;
V_23 += 1 ;
}
if ( V_23 == V_91 ) {
F_63 ( L_22 ) ;
return - V_129 ;
}
return 0 ;
}
static void F_64 ( struct V_42 * V_18 ,
struct V_75 * V_76 ,
T_2 V_102 )
{
T_6 * V_130 ;
V_130 = V_18 -> V_131 + V_102 ;
V_102 = ( V_102 + sizeof( * V_76 ) ) % V_18 -> V_132 ;
memcpy ( V_130 , V_76 , sizeof( * V_76 ) ) ;
F_48 ( V_102 , V_18 -> V_104 + V_133 ) ;
}
static void F_65 ( struct V_75 * V_76 , T_4 V_81 )
{
F_66 ( V_81 & 0x7ULL ) ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 0 ] = F_67 ( F_68 ( V_81 ) ) | V_134 ;
V_76 -> V_73 [ 1 ] = F_69 ( F_68 ( V_81 ) ) ;
V_76 -> V_73 [ 2 ] = 1 ;
F_70 ( V_76 , V_135 ) ;
}
static void F_71 ( struct V_75 * V_76 , T_1 V_2 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 0 ] = V_2 ;
F_70 ( V_76 , V_136 ) ;
}
static void F_72 ( struct V_75 * V_76 , T_4 V_81 ,
T_7 V_137 , T_1 V_78 , int V_138 )
{
T_4 V_139 ;
int V_140 ;
V_139 = F_73 ( V_81 , V_137 , V_141 ) ;
V_140 = 0 ;
if ( V_139 > 1 ) {
V_81 = V_142 ;
V_140 = 1 ;
}
V_81 &= V_143 ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 1 ] |= V_78 ;
V_76 -> V_73 [ 2 ] = F_67 ( V_81 ) ;
V_76 -> V_73 [ 3 ] = F_69 ( V_81 ) ;
F_70 ( V_76 , V_144 ) ;
if ( V_140 )
V_76 -> V_73 [ 2 ] |= V_145 ;
if ( V_138 )
V_76 -> V_73 [ 2 ] |= V_146 ;
}
static void F_74 ( struct V_75 * V_76 , T_1 V_2 , int V_147 ,
T_4 V_81 , T_7 V_137 )
{
T_4 V_139 ;
int V_140 ;
V_139 = F_73 ( V_81 , V_137 , V_141 ) ;
V_140 = 0 ;
if ( V_139 > 1 ) {
V_81 = V_142 ;
V_140 = 1 ;
}
V_81 &= V_143 ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 0 ] = V_2 ;
V_76 -> V_73 [ 0 ] |= ( V_147 & 0xff ) << 24 ;
V_76 -> V_73 [ 1 ] = V_2 ;
V_76 -> V_73 [ 2 ] = F_67 ( V_81 ) ;
V_76 -> V_73 [ 3 ] = F_69 ( V_81 ) ;
F_70 ( V_76 , V_148 ) ;
if ( V_140 )
V_76 -> V_73 [ 2 ] |= V_145 ;
}
static void F_75 ( struct V_75 * V_76 , T_1 V_78 , int V_114 ,
T_4 V_81 , bool V_137 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_81 &= ~ ( 0xfffULL ) ;
V_76 -> V_73 [ 0 ] = V_114 & V_149 ;
V_76 -> V_73 [ 1 ] = V_78 ;
V_76 -> V_73 [ 2 ] = F_67 ( V_81 ) ;
V_76 -> V_73 [ 3 ] = F_69 ( V_81 ) ;
V_76 -> V_73 [ 2 ] |= V_146 ;
V_76 -> V_73 [ 2 ] |= V_150 ;
if ( V_137 )
V_76 -> V_73 [ 2 ] |= V_145 ;
F_70 ( V_76 , V_144 ) ;
}
static void F_76 ( struct V_75 * V_76 , T_1 V_2 , int V_114 ,
int V_147 , T_4 V_81 , bool V_137 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_81 &= ~ ( 0xfffULL ) ;
V_76 -> V_73 [ 0 ] = V_2 ;
V_76 -> V_73 [ 0 ] |= ( V_114 & 0xff ) << 16 ;
V_76 -> V_73 [ 0 ] |= ( V_147 & 0xff ) << 24 ;
V_76 -> V_73 [ 1 ] = V_2 ;
V_76 -> V_73 [ 1 ] |= ( ( V_114 >> 8 ) & 0xfff ) << 16 ;
V_76 -> V_73 [ 2 ] = F_67 ( V_81 ) ;
V_76 -> V_73 [ 2 ] |= V_150 ;
V_76 -> V_73 [ 3 ] = F_69 ( V_81 ) ;
if ( V_137 )
V_76 -> V_73 [ 2 ] |= V_145 ;
F_70 ( V_76 , V_148 ) ;
}
static void F_77 ( struct V_75 * V_76 , T_1 V_2 , int V_114 ,
int V_151 , int V_116 , bool V_152 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 0 ] = V_2 ;
if ( V_152 ) {
V_76 -> V_73 [ 1 ] = V_114 & V_149 ;
V_76 -> V_73 [ 2 ] = V_150 ;
}
V_76 -> V_73 [ 3 ] = V_116 & 0x1ff ;
V_76 -> V_73 [ 3 ] |= ( V_151 & V_153 ) << V_154 ;
F_70 ( V_76 , V_155 ) ;
}
static void F_78 ( struct V_75 * V_76 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
F_70 ( V_76 , V_156 ) ;
}
static int F_79 ( struct V_42 * V_18 ,
struct V_75 * V_76 ,
bool V_157 )
{
T_2 V_158 , V_102 , V_101 , V_159 ;
unsigned long V_4 ;
F_66 ( V_18 -> V_132 & V_160 ) ;
V_161:
F_4 ( & V_18 -> V_103 , V_4 ) ;
V_101 = F_47 ( V_18 -> V_104 + V_162 ) ;
V_102 = F_47 ( V_18 -> V_104 + V_133 ) ;
V_159 = ( V_102 + sizeof( * V_76 ) ) % V_18 -> V_132 ;
V_158 = ( V_101 - V_159 ) % V_18 -> V_132 ;
if ( V_158 <= 2 ) {
struct V_75 V_163 ;
volatile T_4 V_128 = 0 ;
int V_29 ;
F_65 ( & V_163 , ( T_4 ) & V_128 ) ;
F_64 ( V_18 , & V_163 , V_102 ) ;
F_6 ( & V_18 -> V_103 , V_4 ) ;
if ( ( V_29 = F_62 ( & V_128 ) ) != 0 )
return V_29 ;
goto V_161;
}
F_64 ( V_18 , V_76 , V_102 ) ;
V_18 -> V_164 = V_157 ;
F_6 ( & V_18 -> V_103 , V_4 ) ;
return 0 ;
}
static int F_80 ( struct V_42 * V_18 , struct V_75 * V_76 )
{
return F_79 ( V_18 , V_76 , true ) ;
}
static int F_81 ( struct V_42 * V_18 )
{
struct V_75 V_76 ;
volatile T_4 V_128 = 0 ;
int V_29 ;
if ( ! V_18 -> V_164 )
return 0 ;
F_65 ( & V_76 , ( T_4 ) & V_128 ) ;
V_29 = F_79 ( V_18 , & V_76 , false ) ;
if ( V_29 )
return V_29 ;
return F_62 ( & V_128 ) ;
}
static int F_82 ( struct V_42 * V_18 , T_1 V_2 )
{
struct V_75 V_76 ;
F_71 ( & V_76 , V_2 ) ;
return F_80 ( V_18 , & V_76 ) ;
}
static void F_83 ( struct V_42 * V_18 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= 0xffff ; ++ V_2 )
F_82 ( V_18 , V_2 ) ;
F_81 ( V_18 ) ;
}
static void F_84 ( struct V_42 * V_18 )
{
T_2 V_165 ;
for ( V_165 = 0 ; V_165 <= 0xffff ; ++ V_165 ) {
struct V_75 V_76 ;
F_72 ( & V_76 , 0 , V_142 ,
V_165 , 1 ) ;
F_80 ( V_18 , & V_76 ) ;
}
F_81 ( V_18 ) ;
}
static void F_85 ( struct V_42 * V_18 )
{
struct V_75 V_76 ;
F_78 ( & V_76 ) ;
F_80 ( V_18 , & V_76 ) ;
F_81 ( V_18 ) ;
}
void F_86 ( struct V_42 * V_18 )
{
if ( F_87 ( V_18 , V_166 ) ) {
F_85 ( V_18 ) ;
} else {
F_83 ( V_18 ) ;
F_84 ( V_18 ) ;
}
}
static int F_88 ( struct V_1 * V_3 ,
T_4 V_81 , T_7 V_137 )
{
struct V_42 * V_18 ;
struct V_75 V_76 ;
int V_147 ;
V_147 = V_3 -> V_167 . V_147 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_74 ( & V_76 , V_3 -> V_2 , V_147 , V_81 , V_137 ) ;
return F_80 ( V_18 , & V_76 ) ;
}
static int F_89 ( struct V_1 * V_3 )
{
struct V_42 * V_18 ;
int V_29 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_29 = F_82 ( V_18 , V_3 -> V_2 ) ;
if ( V_29 )
return V_29 ;
if ( V_3 -> V_167 . V_168 )
V_29 = F_88 ( V_3 , 0 , ~ 0UL ) ;
return V_29 ;
}
static void F_90 ( struct V_169 * V_170 ,
T_4 V_81 , T_7 V_137 , int V_138 )
{
struct V_1 * V_3 ;
struct V_75 V_76 ;
int V_29 = 0 , V_23 ;
F_72 ( & V_76 , V_81 , V_137 , V_170 -> V_171 , V_138 ) ;
for ( V_23 = 0 ; V_23 < V_172 ; ++ V_23 ) {
if ( ! V_170 -> V_173 [ V_23 ] )
continue;
V_29 |= F_80 ( V_174 [ V_23 ] , & V_76 ) ;
}
F_11 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_167 . V_168 )
continue;
V_29 |= F_88 ( V_3 , V_81 , V_137 ) ;
}
F_66 ( V_29 ) ;
}
static void F_91 ( struct V_169 * V_170 ,
T_4 V_81 , T_7 V_137 )
{
F_90 ( V_170 , V_81 , V_137 , 0 ) ;
}
static void F_92 ( struct V_169 * V_170 )
{
F_90 ( V_170 , 0 , V_142 , 0 ) ;
}
static void F_93 ( struct V_169 * V_170 )
{
F_90 ( V_170 , 0 , V_142 , 1 ) ;
}
static void F_94 ( struct V_169 * V_170 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_172 ; ++ V_23 ) {
if ( ! V_170 -> V_173 [ V_23 ] )
continue;
F_81 ( V_174 [ V_23 ] ) ;
}
}
static void F_95 ( struct V_169 * V_170 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_89 ( V_3 ) ;
}
static bool F_96 ( struct V_169 * V_170 ,
T_8 V_175 )
{
T_4 * V_176 ;
if ( V_170 -> V_177 == V_178 )
return false ;
V_176 = ( void * ) F_97 ( V_175 ) ;
if ( ! V_176 )
return false ;
* V_176 = F_98 ( V_170 -> V_177 ,
F_99 ( V_170 -> V_179 ) ) ;
V_170 -> V_179 = V_176 ;
V_170 -> V_177 += 1 ;
V_170 -> V_180 = true ;
return true ;
}
static T_4 * F_100 ( struct V_169 * V_170 ,
unsigned long V_81 ,
unsigned long V_181 ,
T_4 * * V_182 ,
T_8 V_175 )
{
int V_183 , V_184 ;
T_4 * V_176 , * V_185 ;
F_101 ( ! F_102 ( V_181 ) ) ;
while ( V_81 > F_103 ( V_170 -> V_177 ) )
F_96 ( V_170 , V_175 ) ;
V_183 = V_170 -> V_177 - 1 ;
V_176 = & V_170 -> V_179 [ F_104 ( V_183 , V_81 ) ] ;
V_81 = F_105 ( V_81 , V_181 ) ;
V_184 = F_106 ( V_181 ) ;
while ( V_183 > V_184 ) {
if ( ! F_107 ( * V_176 ) ) {
V_185 = ( T_4 * ) F_97 ( V_175 ) ;
if ( ! V_185 )
return NULL ;
* V_176 = F_98 ( V_183 , F_99 ( V_185 ) ) ;
}
if ( F_108 ( * V_176 ) != V_183 )
return NULL ;
V_183 -= 1 ;
V_176 = F_109 ( * V_176 ) ;
if ( V_182 && V_183 == V_184 )
* V_182 = V_176 ;
V_176 = & V_176 [ F_104 ( V_183 , V_81 ) ] ;
}
return V_176 ;
}
static T_4 * F_110 ( struct V_169 * V_170 , unsigned long V_81 )
{
int V_183 ;
T_4 * V_176 ;
if ( V_81 > F_103 ( V_170 -> V_177 ) )
return NULL ;
V_183 = V_170 -> V_177 - 1 ;
V_176 = & V_170 -> V_179 [ F_104 ( V_183 , V_81 ) ] ;
while ( V_183 > 0 ) {
if ( ! F_107 ( * V_176 ) )
return NULL ;
if ( F_108 ( * V_176 ) == 0x07 ) {
unsigned long V_186 , V_187 ;
V_186 = F_111 ( * V_176 ) ;
V_186 = ~ ( ( F_112 ( V_186 ) << 3 ) - 1 ) ;
V_187 = ( ( unsigned long ) V_176 ) & V_186 ;
return ( T_4 * ) V_187 ;
}
if ( F_108 ( * V_176 ) != V_183 )
return NULL ;
V_183 -= 1 ;
V_176 = F_109 ( * V_176 ) ;
V_176 = & V_176 [ F_104 ( V_183 , V_81 ) ] ;
}
return V_176 ;
}
static int F_113 ( struct V_169 * V_188 ,
unsigned long V_189 ,
unsigned long V_74 ,
int V_190 ,
unsigned long V_181 )
{
T_4 V_187 , * V_176 ;
int V_23 , V_80 ;
if ( ! ( V_190 & V_191 ) )
return - V_192 ;
V_189 = F_114 ( V_189 ) ;
V_74 = F_114 ( V_74 ) ;
V_80 = F_112 ( V_181 ) ;
V_176 = F_100 ( V_188 , V_189 , V_181 , NULL , V_5 ) ;
for ( V_23 = 0 ; V_23 < V_80 ; ++ V_23 )
if ( F_107 ( V_176 [ V_23 ] ) )
return - V_193 ;
if ( V_181 > V_141 ) {
V_187 = F_115 ( V_74 , V_181 ) ;
V_187 |= F_116 ( 7 ) | V_194 | V_195 ;
} else
V_187 = V_74 | V_194 | V_195 ;
if ( V_190 & V_196 )
V_187 |= V_197 ;
if ( V_190 & V_198 )
V_187 |= V_199 ;
for ( V_23 = 0 ; V_23 < V_80 ; ++ V_23 )
V_176 [ V_23 ] = V_187 ;
F_117 ( V_188 ) ;
return 0 ;
}
static unsigned long F_118 ( struct V_169 * V_188 ,
unsigned long V_189 ,
unsigned long V_181 )
{
unsigned long long V_200 , V_201 ;
T_4 * V_176 ;
F_101 ( ! F_102 ( V_181 ) ) ;
V_201 = 0 ;
while ( V_201 < V_181 ) {
V_176 = F_110 ( V_188 , V_189 ) ;
if ( ! V_176 ) {
V_200 = V_141 ;
} else if ( F_108 ( * V_176 ) == 0 ) {
V_200 = V_141 ;
* V_176 = 0ULL ;
} else {
int V_80 , V_23 ;
V_200 = F_111 ( * V_176 ) ;
V_80 = F_112 ( V_200 ) ;
for ( V_23 = 0 ; V_23 < V_80 ; V_23 ++ )
V_176 [ V_23 ] = 0ULL ;
}
V_189 = ( V_189 & ~ ( V_200 - 1 ) ) + V_200 ;
V_201 += V_200 ;
}
F_101 ( ! F_102 ( V_201 ) ) ;
return V_201 ;
}
static int F_119 ( struct V_42 * V_18 ,
struct V_202 * V_28 )
{
T_1 V_203 , V_23 ;
for ( V_23 = V_28 -> V_204 ; V_23 <= V_28 -> V_205 ; ++ V_23 ) {
V_203 = V_31 [ V_23 ] ;
if ( V_38 [ V_203 ] == V_18 )
return 1 ;
}
return 0 ;
}
static int F_120 ( struct V_27 * V_206 ,
struct V_202 * V_207 )
{
T_4 V_208 ;
int V_29 ;
for ( V_208 = V_207 -> V_209 ; V_208 < V_207 -> V_210 ;
V_208 += V_141 ) {
V_29 = F_113 ( & V_206 -> V_170 , V_208 , V_208 , V_207 -> V_190 ,
V_141 ) ;
if ( V_29 )
return V_29 ;
if ( V_208 < V_206 -> V_211 )
F_121 ( V_208 >> V_212 ,
V_206 -> V_213 [ 0 ] -> V_214 ) ;
}
return 0 ;
}
static int F_122 ( struct V_42 * V_18 )
{
struct V_202 * V_28 ;
int V_29 ;
F_11 (entry, &amd_iommu_unity_map, list) {
if ( ! F_119 ( V_18 , V_28 ) )
continue;
V_29 = F_120 ( V_18 -> V_215 , V_28 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_123 ( struct V_27 * V_206 ,
T_1 V_2 )
{
struct V_202 * V_207 ;
int V_29 ;
F_11 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_207 -> V_204 && V_2 <= V_207 -> V_205 ) )
continue;
V_29 = F_120 ( V_206 , V_207 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static void F_124 ( struct V_27 * V_188 ,
unsigned long V_216 ,
unsigned int V_139 )
{
unsigned int V_23 , V_217 = V_188 -> V_211 >> V_212 ;
if ( V_216 + V_139 > V_217 )
V_139 = V_217 - V_216 ;
for ( V_23 = V_216 ; V_23 < V_216 + V_139 ; ++ V_23 ) {
int V_218 = V_23 / V_219 ;
int V_185 = V_23 % V_219 ;
F_121 ( V_185 , V_188 -> V_213 [ V_218 ] -> V_214 ) ;
}
}
static int F_125 ( struct V_27 * V_206 ,
bool V_220 , T_8 V_175 )
{
int V_218 = V_206 -> V_211 >> V_221 ;
struct V_42 * V_18 ;
unsigned long V_23 , V_222 ;
#ifdef F_126
V_220 = false ;
#endif
if ( V_218 >= V_223 )
return - V_39 ;
V_206 -> V_213 [ V_218 ] = F_2 ( sizeof( struct V_224 ) , V_175 ) ;
if ( ! V_206 -> V_213 [ V_218 ] )
return - V_39 ;
V_206 -> V_213 [ V_218 ] -> V_214 = ( void * ) F_97 ( V_175 ) ;
if ( ! V_206 -> V_213 [ V_218 ] -> V_214 )
goto V_48;
V_206 -> V_213 [ V_218 ] -> V_225 = V_206 -> V_211 ;
if ( V_220 ) {
unsigned long V_81 = V_206 -> V_211 ;
int V_23 , V_226 = V_219 / 512 ;
T_4 * V_176 , * V_182 ;
for ( V_23 = 0 ; V_23 < V_226 ; ++ V_23 ) {
V_176 = F_100 ( & V_206 -> V_170 , V_81 , V_141 ,
& V_182 , V_175 ) ;
if ( ! V_176 )
goto V_48;
V_206 -> V_213 [ V_218 ] -> V_227 [ V_23 ] = V_182 ;
V_81 += V_228 / 64 ;
}
}
V_222 = V_206 -> V_211 ;
V_206 -> V_211 += V_228 ;
if ( V_222 < V_229 &&
V_206 -> V_211 > V_229 ) {
unsigned long V_230 ;
int V_139 ;
V_139 = F_73 ( V_229 , 0x10000 , V_141 ) ;
V_230 = V_229 >> V_212 ;
F_124 ( V_206 , V_230 , V_139 ) ;
}
F_60 (iommu) {
if ( V_18 -> V_231 &&
V_18 -> V_231 >= V_206 -> V_213 [ V_218 ] -> V_225
&& V_18 -> V_231 < V_206 -> V_211 ) {
unsigned long V_232 ;
int V_139 = F_73 ( V_18 -> V_231 ,
V_18 -> V_233 ,
V_141 ) ;
V_232 = V_18 -> V_231 >> V_212 ;
F_124 ( V_206 , V_232 , V_139 ) ;
}
}
for ( V_23 = V_206 -> V_213 [ V_218 ] -> V_225 ;
V_23 < V_206 -> V_211 ;
V_23 += V_141 ) {
T_4 * V_176 = F_110 ( & V_206 -> V_170 , V_23 ) ;
if ( ! V_176 || ! F_107 ( * V_176 ) )
continue;
F_124 ( V_206 , V_23 >> V_212 , 1 ) ;
}
F_117 ( & V_206 -> V_170 ) ;
return 0 ;
V_48:
F_117 ( & V_206 -> V_170 ) ;
F_127 ( ( unsigned long ) V_206 -> V_213 [ V_218 ] -> V_214 ) ;
F_9 ( V_206 -> V_213 [ V_218 ] ) ;
V_206 -> V_213 [ V_218 ] = NULL ;
return - V_39 ;
}
static unsigned long F_128 ( struct V_10 * V_11 ,
struct V_27 * V_188 ,
unsigned int V_139 ,
unsigned long V_234 ,
T_4 V_35 ,
unsigned long V_235 )
{
unsigned long V_236 = V_188 -> V_237 % V_228 ;
int V_238 = V_188 -> V_211 >> V_221 ;
int V_23 = V_235 >> V_221 ;
unsigned long V_239 ;
unsigned long V_81 = - 1 ;
unsigned long V_240 ;
V_236 >>= V_212 ;
V_239 = F_129 ( F_130 ( V_11 ) + 1 ,
V_141 ) >> V_212 ;
for (; V_23 < V_238 ; ++ V_23 ) {
unsigned long V_225 = V_188 -> V_213 [ V_23 ] -> V_225 >> V_212 ;
if ( V_188 -> V_213 [ V_23 ] -> V_225 >= V_35 )
break;
V_240 = F_131 ( V_219 , V_225 ,
V_35 >> V_212 ) ;
V_81 = F_132 ( V_188 -> V_213 [ V_23 ] -> V_214 ,
V_240 , V_236 , V_139 , 0 ,
V_239 , V_234 ) ;
if ( V_81 != - 1 ) {
V_81 = V_188 -> V_213 [ V_23 ] -> V_225 +
( V_81 << V_212 ) ;
V_188 -> V_237 = V_81 + ( V_139 << V_212 ) ;
break;
}
V_236 = 0 ;
}
return V_81 ;
}
static unsigned long F_133 ( struct V_10 * V_11 ,
struct V_27 * V_188 ,
unsigned int V_139 ,
unsigned long V_234 ,
T_4 V_35 )
{
unsigned long V_81 ;
#ifdef F_126
V_188 -> V_237 = 0 ;
V_188 -> V_241 = true ;
#endif
V_81 = F_128 ( V_11 , V_188 , V_139 , V_234 ,
V_35 , V_188 -> V_237 ) ;
if ( V_81 == - 1 ) {
V_188 -> V_237 = 0 ;
V_81 = F_128 ( V_11 , V_188 , V_139 , V_234 ,
V_35 , 0 ) ;
V_188 -> V_241 = true ;
}
if ( F_134 ( V_81 == - 1 ) )
V_81 = V_242 ;
F_66 ( ( V_81 + ( V_141 * V_139 ) ) > V_188 -> V_211 ) ;
return V_81 ;
}
static void F_135 ( struct V_27 * V_188 ,
unsigned long V_81 ,
unsigned int V_139 )
{
unsigned V_23 = V_81 >> V_221 ;
struct V_224 * V_243 = V_188 -> V_213 [ V_23 ] ;
F_101 ( V_23 >= V_223 || V_243 == NULL ) ;
#ifdef F_126
if ( V_23 < 4 )
return;
#endif
if ( V_81 >= V_188 -> V_237 )
V_188 -> V_241 = true ;
V_81 = ( V_81 % V_228 ) >> V_212 ;
F_136 ( V_243 -> V_214 , V_81 , V_139 ) ;
}
static void F_137 ( struct V_169 * V_170 )
{
unsigned long V_4 ;
F_4 ( & V_244 , V_4 ) ;
F_138 ( & V_170 -> V_245 , & V_246 ) ;
F_6 ( & V_244 , V_4 ) ;
}
static void F_139 ( struct V_169 * V_170 )
{
unsigned long V_4 ;
F_4 ( & V_244 , V_4 ) ;
F_8 ( & V_170 -> V_245 ) ;
F_6 ( & V_244 , V_4 ) ;
}
static T_1 F_140 ( void )
{
unsigned long V_4 ;
int V_171 ;
F_141 ( & V_247 , V_4 ) ;
V_171 = F_142 ( V_248 , V_249 ) ;
F_101 ( V_171 == 0 ) ;
if ( V_171 > 0 && V_171 < V_249 )
F_121 ( V_171 , V_248 ) ;
else
V_171 = 0 ;
F_143 ( & V_247 , V_4 ) ;
return V_171 ;
}
static void F_144 ( int V_171 )
{
unsigned long V_4 ;
F_141 ( & V_247 , V_4 ) ;
if ( V_171 > 0 && V_171 < V_249 )
F_145 ( V_171 , V_248 ) ;
F_143 ( & V_247 , V_4 ) ;
}
static void F_146 ( struct V_169 * V_170 )
{
int V_23 , V_250 ;
T_4 * V_251 , * V_252 , * V_253 ;
V_251 = V_170 -> V_179 ;
if ( ! V_251 )
return;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! F_107 ( V_251 [ V_23 ] ) )
continue;
V_252 = F_109 ( V_251 [ V_23 ] ) ;
for ( V_250 = 0 ; V_250 < 512 ; ++ V_250 ) {
if ( ! F_107 ( V_252 [ V_250 ] ) )
continue;
V_253 = F_109 ( V_252 [ V_250 ] ) ;
F_127 ( ( unsigned long ) V_253 ) ;
}
F_127 ( ( unsigned long ) V_252 ) ;
}
F_127 ( ( unsigned long ) V_251 ) ;
V_170 -> V_179 = NULL ;
}
static void F_147 ( T_4 * V_254 )
{
T_4 * V_255 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_254 [ V_23 ] & V_256 ) )
continue;
V_255 = F_148 ( V_254 [ V_23 ] & V_143 ) ;
F_127 ( ( unsigned long ) V_255 ) ;
}
}
static void F_149 ( T_4 * V_254 )
{
T_4 * V_255 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_254 [ V_23 ] & V_256 ) )
continue;
V_255 = F_148 ( V_254 [ V_23 ] & V_143 ) ;
F_147 ( V_255 ) ;
}
}
static void F_150 ( struct V_169 * V_170 )
{
if ( V_170 -> V_257 == 2 )
F_149 ( V_170 -> V_258 ) ;
else if ( V_170 -> V_257 == 1 )
F_147 ( V_170 -> V_258 ) ;
else if ( V_170 -> V_257 != 0 )
F_151 () ;
F_127 ( ( unsigned long ) V_170 -> V_258 ) ;
}
static void F_152 ( struct V_27 * V_188 )
{
int V_23 ;
if ( ! V_188 )
return;
F_139 ( & V_188 -> V_170 ) ;
F_146 ( & V_188 -> V_170 ) ;
for ( V_23 = 0 ; V_23 < V_223 ; ++ V_23 ) {
if ( ! V_188 -> V_213 [ V_23 ] )
continue;
F_127 ( ( unsigned long ) V_188 -> V_213 [ V_23 ] -> V_214 ) ;
F_9 ( V_188 -> V_213 [ V_23 ] ) ;
}
F_9 ( V_188 ) ;
}
static struct V_27 * F_153 ( void )
{
struct V_27 * V_206 ;
V_206 = F_2 ( sizeof( struct V_27 ) , V_5 ) ;
if ( ! V_206 )
return NULL ;
F_154 ( & V_206 -> V_170 . V_103 ) ;
V_206 -> V_170 . V_171 = F_140 () ;
if ( V_206 -> V_170 . V_171 == 0 )
goto V_259;
F_155 ( & V_206 -> V_170 . V_260 ) ;
V_206 -> V_170 . V_177 = V_261 ;
V_206 -> V_170 . V_179 = ( void * ) F_97 ( V_5 ) ;
V_206 -> V_170 . V_4 = V_262 ;
V_206 -> V_170 . V_263 = V_206 ;
if ( ! V_206 -> V_170 . V_179 )
goto V_259;
V_206 -> V_241 = false ;
V_206 -> V_34 = 0xffff ;
F_137 ( & V_206 -> V_170 ) ;
if ( F_125 ( V_206 , true , V_5 ) )
goto V_259;
V_206 -> V_213 [ 0 ] -> V_214 [ 0 ] = 1 ;
V_206 -> V_237 = 0 ;
return V_206 ;
V_259:
F_152 ( V_206 ) ;
return NULL ;
}
static bool V_27 ( struct V_169 * V_170 )
{
return V_170 -> V_4 & V_262 ;
}
static void F_156 ( T_1 V_2 , struct V_169 * V_170 , bool V_167 )
{
T_4 V_264 = 0 ;
T_4 V_4 = 0 ;
if ( V_170 -> V_177 != V_265 )
V_264 = F_99 ( V_170 -> V_179 ) ;
V_264 |= ( V_170 -> V_177 & V_266 )
<< V_267 ;
V_264 |= V_197 | V_199 | V_194 | V_268 ;
V_4 = V_45 [ V_2 ] . V_73 [ 1 ] ;
if ( V_167 )
V_4 |= V_269 ;
if ( V_170 -> V_4 & V_270 ) {
T_4 V_271 = F_68 ( V_170 -> V_258 ) ;
T_4 V_257 = V_170 -> V_257 ;
T_4 V_272 ;
V_264 |= V_273 ;
V_264 |= ( V_257 & V_274 ) << V_275 ;
V_272 = F_157 ( ~ 0ULL ) << V_276 ;
V_4 &= ~ V_272 ;
V_272 = F_158 ( ~ 0ULL ) << V_277 ;
V_4 &= ~ V_272 ;
V_272 = F_159 ( V_271 ) << V_278 ;
V_264 |= V_272 ;
V_272 = F_157 ( V_271 ) << V_276 ;
V_4 |= V_272 ;
V_272 = F_158 ( V_271 ) << V_277 ;
V_4 |= V_272 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_170 -> V_171 ;
V_45 [ V_2 ] . V_73 [ 1 ] = V_4 ;
V_45 [ V_2 ] . V_73 [ 0 ] = V_264 ;
}
static void F_160 ( T_1 V_2 )
{
V_45 [ V_2 ] . V_73 [ 0 ] = V_194 | V_268 ;
V_45 [ V_2 ] . V_73 [ 1 ] = 0 ;
F_161 ( V_2 ) ;
}
static void F_162 ( struct V_1 * V_3 ,
struct V_169 * V_170 )
{
struct V_42 * V_18 ;
bool V_167 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_167 = V_3 -> V_167 . V_168 ;
V_3 -> V_170 = V_170 ;
F_138 ( & V_3 -> V_245 , & V_170 -> V_260 ) ;
F_156 ( V_3 -> V_2 , V_170 , V_167 ) ;
V_170 -> V_173 [ V_18 -> V_218 ] += 1 ;
V_170 -> V_279 += 1 ;
F_89 ( V_3 ) ;
}
static void F_163 ( struct V_1 * V_3 )
{
struct V_42 * V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_3 -> V_170 -> V_173 [ V_18 -> V_218 ] -= 1 ;
V_3 -> V_170 -> V_279 -= 1 ;
V_3 -> V_170 = NULL ;
F_8 ( & V_3 -> V_245 ) ;
F_160 ( V_3 -> V_2 ) ;
F_89 ( V_3 ) ;
}
static int F_164 ( struct V_1 * V_3 ,
struct V_169 * V_170 )
{
int V_29 ;
F_165 ( & V_170 -> V_103 ) ;
if ( V_3 -> V_40 != NULL ) {
struct V_1 * V_40 = V_3 -> V_40 ;
V_29 = - V_193 ;
if ( V_40 -> V_170 != NULL &&
V_40 -> V_170 != V_170 )
goto V_9;
if ( V_3 -> V_170 != NULL &&
V_3 -> V_170 != V_170 )
goto V_9;
if ( V_40 -> V_170 == NULL )
F_162 ( V_40 , V_170 ) ;
F_166 ( & V_40 -> V_6 ) ;
}
if ( V_3 -> V_170 == NULL )
F_162 ( V_3 , V_170 ) ;
F_166 ( & V_3 -> V_6 ) ;
V_29 = 0 ;
V_9:
F_167 ( & V_170 -> V_103 ) ;
return V_29 ;
}
static void F_168 ( struct V_12 * V_13 )
{
F_169 ( V_13 ) ;
F_170 ( V_13 ) ;
F_171 ( V_13 ) ;
}
static int F_172 ( struct V_12 * V_13 )
{
T_1 V_280 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return - V_192 ;
F_173 ( V_13 , V_24 + V_281 , & V_280 ) ;
V_280 |= V_282 ;
F_174 ( V_13 , V_24 + V_281 , V_280 ) ;
return 0 ;
}
static int F_175 ( struct V_12 * V_13 )
{
bool V_283 ;
int V_284 , V_29 ;
V_284 = 32 ;
if ( F_19 ( V_13 , V_285 ) )
V_284 = 1 ;
V_283 = F_19 ( V_13 , V_286 ) ;
V_29 = F_176 ( V_13 , 0 ) ;
if ( V_29 )
goto V_287;
V_29 = F_177 ( V_13 ) ;
if ( V_29 )
goto V_287;
V_29 = F_178 ( V_13 , V_284 ) ;
if ( V_29 )
goto V_287;
if ( V_283 ) {
V_29 = F_172 ( V_13 ) ;
if ( V_29 )
goto V_287;
}
V_29 = F_179 ( V_13 , V_212 ) ;
if ( V_29 )
goto V_287;
return 0 ;
V_287:
F_170 ( V_13 ) ;
F_171 ( V_13 ) ;
return V_29 ;
}
bool F_180 ( struct V_12 * V_13 )
{
T_1 V_151 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return false ;
F_173 ( V_13 , V_24 + V_288 , & V_151 ) ;
return ( V_151 & V_289 ) ? true : false ;
}
static int F_181 ( struct V_10 * V_11 ,
struct V_169 * V_170 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_29 ;
V_3 = F_16 ( V_11 ) ;
if ( V_170 -> V_4 & V_270 ) {
if ( ! V_3 -> V_43 || ! V_3 -> V_290 )
return - V_192 ;
if ( F_175 ( V_13 ) != 0 )
return - V_192 ;
V_3 -> V_167 . V_168 = true ;
V_3 -> V_167 . V_147 = F_182 ( V_13 ) ;
V_3 -> V_291 = F_180 ( V_13 ) ;
} else if ( V_292 &&
F_179 ( V_13 , V_212 ) == 0 ) {
V_3 -> V_167 . V_168 = true ;
V_3 -> V_167 . V_147 = F_182 ( V_13 ) ;
}
F_141 ( & V_247 , V_4 ) ;
V_29 = F_164 ( V_3 , V_170 ) ;
F_143 ( & V_247 , V_4 ) ;
F_93 ( V_170 ) ;
return V_29 ;
}
static void F_183 ( struct V_1 * V_3 )
{
struct V_169 * V_170 ;
unsigned long V_4 ;
F_101 ( ! V_3 -> V_170 ) ;
V_170 = V_3 -> V_170 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
if ( V_3 -> V_40 != NULL ) {
struct V_1 * V_40 = V_3 -> V_40 ;
if ( F_184 ( & V_40 -> V_6 ) )
F_163 ( V_40 ) ;
}
if ( F_184 ( & V_3 -> V_6 ) )
F_163 ( V_3 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
if ( V_3 -> V_290 &&
( V_3 -> V_170 == NULL && V_170 != V_293 ) )
F_164 ( V_3 , V_293 ) ;
}
static void F_185 ( struct V_10 * V_11 )
{
struct V_169 * V_170 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
V_170 = V_3 -> V_170 ;
F_141 ( & V_247 , V_4 ) ;
F_183 ( V_3 ) ;
F_143 ( & V_247 , V_4 ) ;
if ( V_170 -> V_4 & V_270 )
F_168 ( F_14 ( V_11 ) ) ;
else if ( V_3 -> V_167 . V_168 )
F_169 ( F_14 ( V_11 ) ) ;
V_3 -> V_167 . V_168 = false ;
}
static struct V_169 * F_186 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
struct V_169 * V_188 = NULL ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
if ( V_3 -> V_170 )
return V_3 -> V_170 ;
if ( V_3 -> V_40 != NULL ) {
struct V_1 * V_40 = V_3 -> V_40 ;
F_187 ( & V_247 , V_4 ) ;
if ( V_40 -> V_170 != NULL ) {
F_164 ( V_3 , V_40 -> V_170 ) ;
V_188 = V_40 -> V_170 ;
}
F_188 ( & V_247 , V_4 ) ;
}
return V_188 ;
}
static int F_189 ( struct V_294 * V_295 ,
unsigned long V_296 , void * V_73 )
{
struct V_27 * V_297 ;
struct V_169 * V_170 ;
struct V_1 * V_3 ;
struct V_10 * V_11 = V_73 ;
struct V_42 * V_18 ;
unsigned long V_4 ;
T_1 V_2 ;
if ( ! F_22 ( V_11 ) )
return 0 ;
V_2 = F_13 ( V_11 ) ;
V_18 = V_38 [ V_2 ] ;
V_3 = F_16 ( V_11 ) ;
switch ( V_296 ) {
case V_298 :
V_170 = F_186 ( V_11 ) ;
if ( ! V_170 )
goto V_299;
if ( V_3 -> V_290 )
break;
F_185 ( V_11 ) ;
break;
case V_300 :
F_23 ( V_11 ) ;
V_170 = F_186 ( V_11 ) ;
V_297 = F_20 ( V_2 ) ;
if ( V_297 )
goto V_299;
V_297 = F_153 () ;
if ( ! V_297 )
goto V_299;
V_297 -> V_34 = V_2 ;
F_4 ( & V_33 , V_4 ) ;
F_5 ( & V_297 -> V_245 , & V_32 ) ;
F_6 ( & V_33 , V_4 ) ;
V_3 = F_16 ( V_11 ) ;
if ( ! V_3 -> V_290 )
V_11 -> V_17 . V_301 = & V_302 ;
else
V_11 -> V_17 . V_301 = & V_303 ;
break;
case V_304 :
F_27 ( V_11 ) ;
default:
goto V_299;
}
F_81 ( V_18 ) ;
V_299:
return 0 ;
}
void F_190 ( void )
{
F_191 ( & V_36 , & V_305 ) ;
}
static struct V_169 * F_192 ( struct V_10 * V_11 )
{
struct V_169 * V_170 ;
struct V_27 * V_206 ;
T_1 V_2 = F_13 ( V_11 ) ;
if ( ! F_22 ( V_11 ) )
return F_193 ( - V_192 ) ;
V_170 = F_186 ( V_11 ) ;
if ( V_170 != NULL && ! V_27 ( V_170 ) )
return F_193 ( - V_193 ) ;
if ( V_170 != NULL )
return V_170 ;
V_206 = F_20 ( V_2 ) ;
if ( ! V_206 )
V_206 = V_38 [ V_2 ] -> V_215 ;
F_181 ( V_11 , & V_206 -> V_170 ) ;
F_194 ( L_23 ,
V_206 -> V_170 . V_171 , F_25 ( V_11 ) ) ;
return & V_206 -> V_170 ;
}
static void F_195 ( struct V_169 * V_170 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_156 ( V_3 -> V_2 , V_170 , V_3 -> V_167 . V_168 ) ;
}
static void F_117 ( struct V_169 * V_170 )
{
if ( ! V_170 -> V_180 )
return;
F_195 ( V_170 ) ;
F_95 ( V_170 ) ;
F_93 ( V_170 ) ;
V_170 -> V_180 = false ;
}
static T_4 * F_196 ( struct V_27 * V_188 ,
unsigned long V_81 )
{
struct V_224 * V_213 ;
T_4 * V_176 , * V_182 ;
V_213 = V_188 -> V_213 [ F_197 ( V_81 ) ] ;
if ( ! V_213 )
return NULL ;
V_176 = V_213 -> V_227 [ F_198 ( V_81 ) ] ;
if ( ! V_176 ) {
V_176 = F_100 ( & V_188 -> V_170 , V_81 , V_141 , & V_182 ,
V_306 ) ;
V_213 -> V_227 [ F_198 ( V_81 ) ] = V_182 ;
} else
V_176 += F_104 ( 0 , V_81 ) ;
F_117 ( & V_188 -> V_170 ) ;
return V_176 ;
}
static T_9 F_199 ( struct V_27 * V_188 ,
unsigned long V_81 ,
T_10 V_307 ,
int V_308 )
{
T_4 * V_176 , V_187 ;
F_66 ( V_81 > V_188 -> V_211 ) ;
V_307 &= V_143 ;
V_176 = F_196 ( V_188 , V_81 ) ;
if ( ! V_176 )
return V_242 ;
V_187 = V_307 | V_194 | V_195 ;
if ( V_308 == V_309 )
V_187 |= V_197 ;
else if ( V_308 == V_310 )
V_187 |= V_199 ;
else if ( V_308 == V_311 )
V_187 |= V_197 | V_199 ;
F_66 ( * V_176 ) ;
* V_176 = V_187 ;
return ( T_9 ) V_81 ;
}
static void F_200 ( struct V_27 * V_188 ,
unsigned long V_81 )
{
struct V_224 * V_213 ;
T_4 * V_176 ;
if ( V_81 >= V_188 -> V_211 )
return;
V_213 = V_188 -> V_213 [ F_197 ( V_81 ) ] ;
if ( ! V_213 )
return;
V_176 = V_213 -> V_227 [ F_198 ( V_81 ) ] ;
if ( ! V_176 )
return;
V_176 += F_104 ( 0 , V_81 ) ;
F_66 ( ! * V_176 ) ;
* V_176 = 0ULL ;
}
static T_9 F_201 ( struct V_10 * V_11 ,
struct V_27 * V_206 ,
T_10 V_307 ,
T_7 V_137 ,
int V_312 ,
bool V_313 ,
T_4 V_35 )
{
T_9 V_225 = V_307 & ~ V_143 ;
T_9 V_81 , V_235 , V_29 ;
unsigned int V_139 ;
unsigned long V_234 = 0 ;
int V_23 ;
V_139 = F_73 ( V_307 , V_137 , V_141 ) ;
V_307 &= V_143 ;
F_50 ( V_68 ) ;
if ( V_139 > 1 )
F_50 ( V_64 ) ;
if ( V_313 )
V_234 = ( 1UL << F_202 ( V_137 ) ) - 1 ;
V_82:
V_81 = F_133 ( V_11 , V_206 , V_139 , V_234 ,
V_35 ) ;
if ( F_134 ( V_81 == V_242 ) ) {
V_206 -> V_237 = V_206 -> V_211 ;
if ( F_125 ( V_206 , false , V_306 ) )
goto V_299;
goto V_82;
}
V_235 = V_81 ;
for ( V_23 = 0 ; V_23 < V_139 ; ++ V_23 ) {
V_29 = F_199 ( V_206 , V_235 , V_307 , V_312 ) ;
if ( V_29 == V_242 )
goto V_314;
V_307 += V_141 ;
V_235 += V_141 ;
}
V_81 += V_225 ;
F_203 ( V_67 , V_137 ) ;
if ( F_134 ( V_206 -> V_241 && ! V_56 ) ) {
F_92 ( & V_206 -> V_170 ) ;
V_206 -> V_241 = false ;
} else if ( F_134 ( V_315 ) )
F_91 ( & V_206 -> V_170 , V_81 , V_137 ) ;
V_299:
return V_81 ;
V_314:
for ( -- V_23 ; V_23 >= 0 ; -- V_23 ) {
V_235 -= V_141 ;
F_200 ( V_206 , V_235 ) ;
}
F_135 ( V_206 , V_81 , V_139 ) ;
return V_242 ;
}
static void F_204 ( struct V_27 * V_206 ,
T_9 V_316 ,
T_7 V_137 ,
int V_312 )
{
T_9 V_317 ;
T_9 V_23 , V_235 ;
unsigned int V_139 ;
if ( ( V_316 == V_242 ) ||
( V_316 + V_137 > V_206 -> V_211 ) )
return;
V_317 = V_316 ;
V_139 = F_73 ( V_316 , V_137 , V_141 ) ;
V_316 &= V_143 ;
V_235 = V_316 ;
for ( V_23 = 0 ; V_23 < V_139 ; ++ V_23 ) {
F_200 ( V_206 , V_235 ) ;
V_235 += V_141 ;
}
F_205 ( V_67 , V_137 ) ;
F_135 ( V_206 , V_316 , V_139 ) ;
if ( V_56 || V_206 -> V_241 ) {
F_91 ( & V_206 -> V_170 , V_317 , V_137 ) ;
V_206 -> V_241 = false ;
}
}
static T_9 F_206 ( struct V_10 * V_11 , struct V_185 * V_185 ,
unsigned long V_225 , T_7 V_137 ,
enum V_318 V_312 ,
struct V_319 * V_320 )
{
unsigned long V_4 ;
struct V_169 * V_170 ;
T_9 V_208 ;
T_4 V_35 ;
T_10 V_307 = F_207 ( V_185 ) + V_225 ;
F_50 ( V_58 ) ;
V_170 = F_192 ( V_11 ) ;
if ( F_208 ( V_170 ) == - V_192 )
return ( T_9 ) V_307 ;
else if ( F_209 ( V_170 ) )
return V_242 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
V_208 = F_201 ( V_11 , V_170 -> V_263 , V_307 , V_137 , V_312 , false ,
V_35 ) ;
if ( V_208 == V_242 )
goto V_299;
F_94 ( V_170 ) ;
V_299:
F_6 ( & V_170 -> V_103 , V_4 ) ;
return V_208 ;
}
static void F_210 ( struct V_10 * V_11 , T_9 V_316 , T_7 V_137 ,
enum V_318 V_312 , struct V_319 * V_320 )
{
unsigned long V_4 ;
struct V_169 * V_170 ;
F_50 ( V_59 ) ;
V_170 = F_192 ( V_11 ) ;
if ( F_209 ( V_170 ) )
return;
F_4 ( & V_170 -> V_103 , V_4 ) ;
F_204 ( V_170 -> V_263 , V_316 , V_137 , V_312 ) ;
F_94 ( V_170 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
}
static int F_211 ( struct V_10 * V_11 , struct V_321 * V_322 ,
int V_323 , int V_312 )
{
struct V_321 * V_140 ;
int V_23 ;
F_212 (sglist, s, nelems, i) {
V_140 -> V_324 = ( T_9 ) F_213 ( V_140 ) ;
V_140 -> V_325 = V_140 -> V_326 ;
}
return V_323 ;
}
static int F_214 ( struct V_10 * V_11 , struct V_321 * V_322 ,
int V_323 , enum V_318 V_312 ,
struct V_319 * V_320 )
{
unsigned long V_4 ;
struct V_169 * V_170 ;
int V_23 ;
struct V_321 * V_140 ;
T_10 V_307 ;
int V_327 = 0 ;
T_4 V_35 ;
F_50 ( V_60 ) ;
V_170 = F_192 ( V_11 ) ;
if ( F_208 ( V_170 ) == - V_192 )
return F_211 ( V_11 , V_322 , V_323 , V_312 ) ;
else if ( F_209 ( V_170 ) )
return 0 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
F_212 (sglist, s, nelems, i) {
V_307 = F_213 ( V_140 ) ;
V_140 -> V_324 = F_201 ( V_11 , V_170 -> V_263 ,
V_307 , V_140 -> V_326 , V_312 , false ,
V_35 ) ;
if ( V_140 -> V_324 ) {
V_140 -> V_325 = V_140 -> V_326 ;
V_327 ++ ;
} else
goto V_328;
}
F_94 ( V_170 ) ;
V_299:
F_6 ( & V_170 -> V_103 , V_4 ) ;
return V_327 ;
V_328:
F_212 (sglist, s, mapped_elems, i) {
if ( V_140 -> V_324 )
F_204 ( V_170 -> V_263 , V_140 -> V_324 ,
V_140 -> V_325 , V_312 ) ;
V_140 -> V_324 = V_140 -> V_325 = 0 ;
}
V_327 = 0 ;
goto V_299;
}
static void F_215 ( struct V_10 * V_11 , struct V_321 * V_322 ,
int V_323 , enum V_318 V_312 ,
struct V_319 * V_320 )
{
unsigned long V_4 ;
struct V_169 * V_170 ;
struct V_321 * V_140 ;
int V_23 ;
F_50 ( V_61 ) ;
V_170 = F_192 ( V_11 ) ;
if ( F_209 ( V_170 ) )
return;
F_4 ( & V_170 -> V_103 , V_4 ) ;
F_212 (sglist, s, nelems, i) {
F_204 ( V_170 -> V_263 , V_140 -> V_324 ,
V_140 -> V_325 , V_312 ) ;
V_140 -> V_324 = V_140 -> V_325 = 0 ;
}
F_94 ( V_170 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
}
static void * F_216 ( struct V_10 * V_11 , T_7 V_137 ,
T_9 * V_316 , T_8 V_329 ,
struct V_319 * V_320 )
{
unsigned long V_4 ;
void * V_330 ;
struct V_169 * V_170 ;
T_10 V_307 ;
T_4 V_35 = V_11 -> V_331 ;
F_50 ( V_62 ) ;
V_170 = F_192 ( V_11 ) ;
if ( F_208 ( V_170 ) == - V_192 ) {
V_330 = ( void * ) F_217 ( V_329 , F_202 ( V_137 ) ) ;
* V_316 = F_68 ( V_330 ) ;
return V_330 ;
} else if ( F_209 ( V_170 ) )
return NULL ;
V_35 = V_11 -> V_331 ;
V_329 &= ~ ( V_332 | V_333 | V_334 ) ;
V_329 |= V_335 ;
V_330 = ( void * ) F_217 ( V_329 , F_202 ( V_137 ) ) ;
if ( ! V_330 )
return NULL ;
V_307 = F_99 ( V_330 ) ;
if ( ! V_35 )
V_35 = * V_11 -> V_35 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
* V_316 = F_201 ( V_11 , V_170 -> V_263 , V_307 ,
V_137 , V_311 , true , V_35 ) ;
if ( * V_316 == V_242 ) {
F_6 ( & V_170 -> V_103 , V_4 ) ;
goto V_48;
}
F_94 ( V_170 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
return V_330 ;
V_48:
F_218 ( ( unsigned long ) V_330 , F_202 ( V_137 ) ) ;
return NULL ;
}
static void F_219 ( struct V_10 * V_11 , T_7 V_137 ,
void * V_330 , T_9 V_316 ,
struct V_319 * V_320 )
{
unsigned long V_4 ;
struct V_169 * V_170 ;
F_50 ( V_63 ) ;
V_170 = F_192 ( V_11 ) ;
if ( F_209 ( V_170 ) )
goto V_336;
F_4 ( & V_170 -> V_103 , V_4 ) ;
F_204 ( V_170 -> V_263 , V_316 , V_137 , V_311 ) ;
F_94 ( V_170 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
V_336:
F_218 ( ( unsigned long ) V_330 , F_202 ( V_137 ) ) ;
}
static int F_220 ( struct V_10 * V_11 , T_4 V_337 )
{
return F_22 ( V_11 ) ;
}
static void T_3 F_221 ( void )
{
struct V_1 * V_3 ;
struct V_27 * V_206 ;
struct V_12 * V_11 = NULL ;
T_1 V_2 ;
F_29 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
if ( ! V_338 && V_3 -> V_43 ) {
F_222 () ;
V_3 -> V_290 = true ;
F_181 ( & V_11 -> V_11 , V_293 ) ;
F_223 ( L_24 ,
F_25 ( & V_11 -> V_11 ) ) ;
}
if ( F_186 ( & V_11 -> V_11 ) )
continue;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_206 = F_153 () ;
if ( ! V_206 )
continue;
F_123 ( V_206 , V_2 ) ;
V_206 -> V_34 = V_2 ;
F_181 ( & V_11 -> V_11 , & V_206 -> V_170 ) ;
F_5 ( & V_206 -> V_245 , & V_32 ) ;
}
}
static unsigned F_224 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_13 = NULL ;
unsigned V_339 = 0 ;
F_29 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) ) {
F_26 ( & V_13 -> V_11 ) ;
V_339 += 1 ;
continue;
}
V_3 = F_16 ( & V_13 -> V_11 ) ;
if ( ! V_3 -> V_290 )
V_13 -> V_11 . V_17 . V_301 = & V_302 ;
else
V_13 -> V_11 . V_17 . V_301 = & V_303 ;
}
return V_339 ;
}
void T_3 F_225 ( void )
{
F_226 ( & V_36 , & V_340 ) ;
}
int T_3 F_227 ( void )
{
struct V_42 * V_18 ;
int V_29 , V_339 ;
F_60 (iommu) {
V_18 -> V_215 = F_153 () ;
if ( V_18 -> V_215 == NULL )
return - V_39 ;
V_18 -> V_215 -> V_170 . V_4 |= V_341 ;
V_29 = F_122 ( V_18 ) ;
if ( V_29 )
goto V_342;
}
F_221 () ;
V_343 = 1 ;
V_344 = 0 ;
V_339 = F_224 () ;
if ( V_339 && V_345 > V_346 ) {
V_344 = 1 ;
}
F_34 () ;
return 0 ;
V_342:
F_60 (iommu) {
if ( V_18 -> V_215 )
F_152 ( V_18 -> V_215 ) ;
}
return V_29 ;
}
static void F_228 ( struct V_169 * V_170 )
{
struct V_1 * V_3 , * V_347 ;
unsigned long V_4 ;
F_141 ( & V_247 , V_4 ) ;
F_30 (dev_data, next, &domain->dev_list, list) {
F_183 ( V_3 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
}
F_143 ( & V_247 , V_4 ) ;
}
static void F_229 ( struct V_169 * V_170 )
{
if ( ! V_170 )
return;
F_139 ( V_170 ) ;
if ( V_170 -> V_171 )
F_144 ( V_170 -> V_171 ) ;
F_9 ( V_170 ) ;
}
static struct V_169 * F_230 ( void )
{
struct V_169 * V_170 ;
V_170 = F_2 ( sizeof( * V_170 ) , V_5 ) ;
if ( ! V_170 )
return NULL ;
F_154 ( & V_170 -> V_103 ) ;
F_231 ( & V_170 -> V_348 ) ;
V_170 -> V_171 = F_140 () ;
if ( ! V_170 -> V_171 )
goto V_287;
F_155 ( & V_170 -> V_260 ) ;
F_137 ( V_170 ) ;
return V_170 ;
V_287:
F_9 ( V_170 ) ;
return NULL ;
}
static int T_3 F_222 ( void )
{
if ( V_293 != NULL )
return 0 ;
V_293 = F_230 () ;
if ( ! V_293 )
return - V_39 ;
V_293 -> V_177 = V_265 ;
return 0 ;
}
static int F_232 ( struct V_349 * V_188 )
{
struct V_169 * V_170 ;
V_170 = F_230 () ;
if ( ! V_170 )
goto V_48;
V_170 -> V_177 = V_350 ;
V_170 -> V_179 = ( void * ) F_97 ( V_5 ) ;
if ( ! V_170 -> V_179 )
goto V_48;
V_170 -> V_349 = V_188 ;
V_188 -> V_263 = V_170 ;
return 0 ;
V_48:
F_229 ( V_170 ) ;
return - V_39 ;
}
static void F_233 ( struct V_349 * V_188 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
if ( ! V_170 )
return;
if ( V_170 -> V_279 > 0 )
F_228 ( V_170 ) ;
F_101 ( V_170 -> V_279 != 0 ) ;
if ( V_170 -> V_177 != V_265 )
F_146 ( V_170 ) ;
if ( V_170 -> V_4 & V_270 )
F_150 ( V_170 ) ;
F_229 ( V_170 ) ;
V_188 -> V_263 = NULL ;
}
static void F_234 ( struct V_349 * V_188 ,
struct V_10 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_17 . V_18 ;
struct V_42 * V_18 ;
T_1 V_2 ;
if ( ! F_22 ( V_11 ) )
return;
V_2 = F_13 ( V_11 ) ;
if ( V_3 -> V_170 != NULL )
F_185 ( V_11 ) ;
V_18 = V_38 [ V_2 ] ;
if ( ! V_18 )
return;
F_81 ( V_18 ) ;
}
static int F_235 ( struct V_349 * V_188 ,
struct V_10 * V_11 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
struct V_1 * V_3 ;
struct V_42 * V_18 ;
int V_29 ;
if ( ! F_22 ( V_11 ) )
return - V_192 ;
V_3 = V_11 -> V_17 . V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
if ( ! V_18 )
return - V_192 ;
if ( V_3 -> V_170 )
F_185 ( V_11 ) ;
V_29 = F_181 ( V_11 , V_170 ) ;
F_81 ( V_18 ) ;
return V_29 ;
}
static int F_236 ( struct V_349 * V_188 , unsigned long V_351 ,
T_10 V_307 , T_7 V_181 , int V_352 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
int V_190 = 0 ;
int V_29 ;
if ( V_170 -> V_177 == V_265 )
return - V_192 ;
if ( V_352 & V_353 )
V_190 |= V_196 ;
if ( V_352 & V_354 )
V_190 |= V_198 ;
F_237 ( & V_170 -> V_348 ) ;
V_29 = F_113 ( V_170 , V_351 , V_307 , V_190 , V_181 ) ;
F_238 ( & V_170 -> V_348 ) ;
return V_29 ;
}
static T_7 F_239 ( struct V_349 * V_188 , unsigned long V_351 ,
T_7 V_181 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
T_7 V_200 ;
if ( V_170 -> V_177 == V_265 )
return - V_192 ;
F_237 ( & V_170 -> V_348 ) ;
V_200 = F_118 ( V_170 , V_351 , V_181 ) ;
F_238 ( & V_170 -> V_348 ) ;
F_93 ( V_170 ) ;
return V_200 ;
}
static T_10 F_240 ( struct V_349 * V_188 ,
unsigned long V_351 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
unsigned long V_355 ;
T_10 V_307 ;
T_4 * V_176 , V_187 ;
if ( V_170 -> V_177 == V_265 )
return V_351 ;
V_176 = F_110 ( V_170 , V_351 ) ;
if ( ! V_176 || ! F_107 ( * V_176 ) )
return 0 ;
if ( F_108 ( * V_176 ) == 0 )
V_355 = V_141 - 1 ;
else
V_355 = F_111 ( * V_176 ) - 1 ;
V_187 = * V_176 & V_356 ;
V_307 = ( V_187 & ~ V_355 ) | ( V_351 & V_355 ) ;
return V_307 ;
}
static int F_241 ( struct V_349 * V_170 ,
unsigned long V_357 )
{
switch ( V_357 ) {
case V_358 :
return 1 ;
}
return 0 ;
}
static int F_242 ( struct V_10 * V_11 , unsigned int * V_359 )
{
struct V_1 * V_3 = V_11 -> V_17 . V_18 ;
struct V_12 * V_13 = F_14 ( V_11 ) ;
T_1 V_2 ;
if ( ! V_3 )
return - V_360 ;
if ( V_13 -> V_361 || ! V_362 )
V_2 = V_3 -> V_2 ;
else
V_2 = F_15 ( V_13 -> V_14 -> V_15 ,
F_243 ( F_44 ( V_13 -> V_16 ) , 0 ) ) ;
* V_359 = V_31 [ V_2 ] ;
return 0 ;
}
int T_3 F_244 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_11 = NULL ;
struct V_42 * V_18 ;
T_1 V_2 ;
int V_29 ;
V_29 = F_222 () ;
if ( V_29 )
return V_29 ;
F_29 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
V_3 -> V_290 = true ;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_18 = V_38 [ V_2 ] ;
if ( ! V_18 )
continue;
F_181 ( & V_11 -> V_11 , V_293 ) ;
}
F_34 () ;
F_223 ( L_25 ) ;
return 0 ;
}
int F_245 ( struct V_294 * V_295 )
{
return F_246 ( & V_117 , V_295 ) ;
}
int F_247 ( struct V_294 * V_295 )
{
return F_248 ( & V_117 , V_295 ) ;
}
void F_249 ( struct V_349 * V_188 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
unsigned long V_4 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
V_170 -> V_177 = V_265 ;
V_170 -> V_180 = true ;
F_117 ( V_170 ) ;
F_146 ( V_170 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
}
int F_250 ( struct V_349 * V_188 , int V_363 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
unsigned long V_4 ;
int V_364 , V_29 ;
if ( V_363 <= 0 || V_363 > ( V_149 + 1 ) )
return - V_192 ;
for ( V_364 = 0 ; ( V_363 - 1 ) & ~ 0x1ff ; V_363 >>= 9 )
V_364 += 1 ;
if ( V_364 > V_365 )
return - V_192 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
V_29 = - V_193 ;
if ( V_170 -> V_279 > 0 || V_170 -> V_4 & V_270 )
goto V_299;
V_29 = - V_39 ;
V_170 -> V_258 = ( void * ) F_97 ( V_306 ) ;
if ( V_170 -> V_258 == NULL )
goto V_299;
V_170 -> V_257 = V_364 ;
V_170 -> V_4 |= V_270 ;
V_170 -> V_180 = true ;
F_117 ( V_170 ) ;
V_29 = 0 ;
V_299:
F_6 ( & V_170 -> V_103 , V_4 ) ;
return V_29 ;
}
static int F_251 ( struct V_169 * V_170 , int V_114 ,
T_4 V_81 , bool V_137 )
{
struct V_1 * V_3 ;
struct V_75 V_76 ;
int V_23 , V_29 ;
if ( ! ( V_170 -> V_4 & V_270 ) )
return - V_192 ;
F_75 ( & V_76 , V_170 -> V_171 , V_114 , V_81 , V_137 ) ;
for ( V_23 = 0 ; V_23 < V_172 ; ++ V_23 ) {
if ( V_170 -> V_173 [ V_23 ] == 0 )
continue;
V_29 = F_80 ( V_174 [ V_23 ] , & V_76 ) ;
if ( V_29 != 0 )
goto V_299;
}
F_94 ( V_170 ) ;
F_11 (dev_data, &domain->dev_list, list) {
struct V_42 * V_18 ;
int V_147 ;
F_101 ( ! V_3 -> V_167 . V_168 ) ;
V_147 = V_3 -> V_167 . V_147 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_76 ( & V_76 , V_3 -> V_2 , V_114 ,
V_147 , V_81 , V_137 ) ;
V_29 = F_80 ( V_18 , & V_76 ) ;
if ( V_29 != 0 )
goto V_299;
}
F_94 ( V_170 ) ;
V_29 = 0 ;
V_299:
return V_29 ;
}
static int F_252 ( struct V_169 * V_170 , int V_114 ,
T_4 V_81 )
{
F_50 ( V_70 ) ;
return F_251 ( V_170 , V_114 , V_81 , false ) ;
}
int F_253 ( struct V_349 * V_188 , int V_114 ,
T_4 V_81 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
V_29 = F_252 ( V_170 , V_114 , V_81 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
return V_29 ;
}
static int F_254 ( struct V_169 * V_170 , int V_114 )
{
F_50 ( V_71 ) ;
return F_251 ( V_170 , V_114 , V_142 ,
true ) ;
}
int F_255 ( struct V_349 * V_188 , int V_114 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
V_29 = F_254 ( V_170 , V_114 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
return V_29 ;
}
static T_4 * F_256 ( T_4 * V_366 , int V_183 , int V_114 , bool V_367 )
{
int V_218 ;
T_4 * V_176 ;
while ( true ) {
V_218 = ( V_114 >> ( 9 * V_183 ) ) & 0x1ff ;
V_176 = & V_366 [ V_218 ] ;
if ( V_183 == 0 )
break;
if ( ! ( * V_176 & V_256 ) ) {
if ( ! V_367 )
return NULL ;
V_366 = ( void * ) F_97 ( V_306 ) ;
if ( V_366 == NULL )
return NULL ;
* V_176 = F_68 ( V_366 ) | V_256 ;
}
V_366 = F_148 ( * V_176 & V_143 ) ;
V_183 -= 1 ;
}
return V_176 ;
}
static int F_257 ( struct V_169 * V_170 , int V_114 ,
unsigned long V_368 )
{
T_4 * V_176 ;
if ( V_170 -> V_177 != V_265 )
return - V_192 ;
V_176 = F_256 ( V_170 -> V_258 , V_170 -> V_257 , V_114 , true ) ;
if ( V_176 == NULL )
return - V_39 ;
* V_176 = ( V_368 & V_143 ) | V_256 ;
return F_254 ( V_170 , V_114 ) ;
}
static int F_258 ( struct V_169 * V_170 , int V_114 )
{
T_4 * V_176 ;
if ( V_170 -> V_177 != V_265 )
return - V_192 ;
V_176 = F_256 ( V_170 -> V_258 , V_170 -> V_257 , V_114 , false ) ;
if ( V_176 == NULL )
return 0 ;
* V_176 = 0 ;
return F_254 ( V_170 , V_114 ) ;
}
int F_259 ( struct V_349 * V_188 , int V_114 ,
unsigned long V_368 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
V_29 = F_257 ( V_170 , V_114 , V_368 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
return V_29 ;
}
int F_260 ( struct V_349 * V_188 , int V_114 )
{
struct V_169 * V_170 = V_188 -> V_263 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_170 -> V_103 , V_4 ) ;
V_29 = F_258 ( V_170 , V_114 ) ;
F_6 ( & V_170 -> V_103 , V_4 ) ;
return V_29 ;
}
int F_261 ( struct V_12 * V_13 , int V_114 ,
int V_151 , int V_116 )
{
struct V_1 * V_3 ;
struct V_42 * V_18 ;
struct V_75 V_76 ;
F_50 ( V_69 ) ;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_77 ( & V_76 , V_3 -> V_2 , V_114 , V_151 ,
V_116 , V_3 -> V_291 ) ;
return F_80 ( V_18 , & V_76 ) ;
}
struct V_349 * F_262 ( struct V_12 * V_13 )
{
struct V_169 * V_170 ;
V_170 = F_192 ( & V_13 -> V_11 ) ;
if ( F_209 ( V_170 ) )
return NULL ;
if ( ! ( V_170 -> V_4 & V_270 ) )
return NULL ;
return V_170 -> V_349 ;
}
void F_263 ( struct V_12 * V_13 , T_2 V_25 )
{
struct V_1 * V_3 ;
if ( ! F_264 () )
return;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_3 -> V_26 |= ( 1 << V_25 ) ;
}
int F_265 ( struct V_12 * V_13 ,
struct F_265 * V_369 )
{
int V_370 ;
int V_24 ;
if ( V_13 == NULL || V_369 == NULL )
return - V_192 ;
if ( ! F_264 () )
return - V_192 ;
memset ( V_369 , 0 , sizeof( * V_369 ) ) ;
V_24 = F_18 ( V_13 , V_20 ) ;
if ( V_24 )
V_369 -> V_4 |= V_371 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( V_24 )
V_369 -> V_4 |= V_372 ;
V_24 = F_18 ( V_13 , V_22 ) ;
if ( V_24 ) {
int V_373 ;
V_370 = 1 << ( 9 * ( V_365 + 1 ) ) ;
V_370 = F_266 ( V_370 , ( 1 << 20 ) ) ;
V_369 -> V_4 |= V_374 ;
V_369 -> V_370 = F_266 ( F_267 ( V_13 ) , V_370 ) ;
V_373 = F_268 ( V_13 ) ;
if ( V_373 & V_375 )
V_369 -> V_4 |= V_376 ;
if ( V_373 & V_377 )
V_369 -> V_4 |= V_378 ;
}
return 0 ;
}
