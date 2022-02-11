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
( T_2 * ) & V_56 ) ;
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
T_2 * V_78 = V_77 ;
int type = ( V_78 [ 1 ] >> V_79 ) & V_80 ;
int V_2 = ( V_78 [ 0 ] >> V_81 ) & V_82 ;
int V_83 = ( V_78 [ 1 ] >> V_84 ) & V_85 ;
int V_4 = ( V_78 [ 1 ] >> V_86 ) & V_87 ;
T_4 V_88 = ( T_4 ) ( ( ( T_4 ) V_78 [ 3 ] ) << 32 ) | V_78 [ 2 ] ;
F_41 ( V_89 L_6 ) ;
switch ( type ) {
case V_90 :
F_41 ( L_7
L_8 ,
F_42 ( V_2 ) , F_43 ( V_2 ) , F_44 ( V_2 ) ,
V_88 , V_4 ) ;
F_37 ( V_2 ) ;
break;
case V_91 :
F_41 ( L_9
L_10 ,
F_42 ( V_2 ) , F_43 ( V_2 ) , F_44 ( V_2 ) ,
V_83 , V_88 , V_4 ) ;
break;
case V_92 :
F_41 ( L_11
L_8 ,
F_42 ( V_2 ) , F_43 ( V_2 ) , F_44 ( V_2 ) ,
V_88 , V_4 ) ;
break;
case V_93 :
F_41 ( L_12
L_10 ,
F_42 ( V_2 ) , F_43 ( V_2 ) , F_44 ( V_2 ) ,
V_83 , V_88 , V_4 ) ;
break;
case V_94 :
F_41 ( L_13 , V_88 ) ;
F_38 ( V_88 ) ;
break;
case V_95 :
F_41 ( L_14
L_15 , V_88 , V_4 ) ;
break;
case V_96 :
F_41 ( L_16
L_17 ,
F_42 ( V_2 ) , F_43 ( V_2 ) , F_44 ( V_2 ) ,
V_88 ) ;
break;
case V_97 :
F_41 ( L_18
L_8 ,
F_42 ( V_2 ) , F_43 ( V_2 ) , F_44 ( V_2 ) ,
V_88 , V_4 ) ;
break;
default:
F_41 ( V_89 L_19 , type ) ;
}
}
static void F_45 ( struct V_42 * V_18 )
{
T_2 V_98 , V_99 ;
unsigned long V_4 ;
F_4 ( & V_18 -> V_100 , V_4 ) ;
V_98 = F_46 ( V_18 -> V_101 + V_102 ) ;
V_99 = F_46 ( V_18 -> V_101 + V_103 ) ;
while ( V_98 != V_99 ) {
F_40 ( V_18 , V_18 -> V_104 + V_98 ) ;
V_98 = ( V_98 + V_105 ) % V_18 -> V_106 ;
}
F_47 ( V_98 , V_18 -> V_101 + V_102 ) ;
F_6 ( & V_18 -> V_100 , V_4 ) ;
}
static void F_48 ( struct V_42 * V_18 , T_2 V_98 )
{
struct V_107 V_108 ;
volatile T_4 * V_109 ;
int V_23 ;
F_49 ( V_72 ) ;
V_109 = ( T_4 * ) ( V_18 -> V_110 + V_98 ) ;
for ( V_23 = 0 ; V_23 < V_111 ; ++ V_23 ) {
if ( F_50 ( V_109 [ 0 ] ) != 0 )
break;
F_51 ( 1 ) ;
}
if ( F_50 ( V_109 [ 0 ] ) != V_112 ) {
F_52 ( L_20 ) ;
return;
}
V_108 . V_88 = V_109 [ 1 ] ;
V_108 . V_113 = F_53 ( V_109 [ 0 ] ) ;
V_108 . V_114 = F_54 ( V_109 [ 0 ] ) ;
V_108 . V_115 = F_55 ( V_109 [ 0 ] ) ;
V_108 . V_4 = F_56 ( V_109 [ 0 ] ) ;
V_109 [ 0 ] = V_109 [ 1 ] = 0 ;
F_57 ( & V_116 , 0 , & V_108 ) ;
}
static void F_58 ( struct V_42 * V_18 )
{
unsigned long V_4 ;
T_2 V_98 , V_99 ;
if ( V_18 -> V_110 == NULL )
return;
F_4 ( & V_18 -> V_100 , V_4 ) ;
V_98 = F_46 ( V_18 -> V_101 + V_117 ) ;
V_99 = F_46 ( V_18 -> V_101 + V_118 ) ;
while ( V_98 != V_99 ) {
F_48 ( V_18 , V_98 ) ;
V_98 = ( V_98 + V_119 ) % V_120 ;
F_47 ( V_98 , V_18 -> V_101 + V_117 ) ;
V_99 = F_46 ( V_18 -> V_101 + V_118 ) ;
}
F_47 ( V_121 , V_18 -> V_101 + V_122 ) ;
F_6 ( & V_18 -> V_100 , V_4 ) ;
}
T_5 F_59 ( int V_123 , void * V_73 )
{
struct V_42 * V_18 ;
F_60 (iommu) {
F_45 ( V_18 ) ;
F_58 ( V_18 ) ;
}
return V_124 ;
}
T_5 F_61 ( int V_123 , void * V_73 )
{
return V_125 ;
}
static int F_62 ( volatile T_4 * V_126 )
{
int V_23 = 0 ;
while ( * V_126 == 0 && V_23 < V_111 ) {
F_51 ( 1 ) ;
V_23 += 1 ;
}
if ( V_23 == V_111 ) {
F_63 ( L_21 ) ;
return - V_127 ;
}
return 0 ;
}
static void F_64 ( struct V_42 * V_18 ,
struct V_75 * V_76 ,
T_2 V_99 )
{
T_6 * V_128 ;
V_128 = V_18 -> V_129 + V_99 ;
V_99 = ( V_99 + sizeof( * V_76 ) ) % V_18 -> V_130 ;
memcpy ( V_128 , V_76 , sizeof( * V_76 ) ) ;
F_47 ( V_99 , V_18 -> V_101 + V_131 ) ;
}
static void F_65 ( struct V_75 * V_76 , T_4 V_88 )
{
F_66 ( V_88 & 0x7ULL ) ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 0 ] = F_67 ( F_68 ( V_88 ) ) | V_132 ;
V_76 -> V_73 [ 1 ] = F_69 ( F_68 ( V_88 ) ) ;
V_76 -> V_73 [ 2 ] = 1 ;
F_70 ( V_76 , V_133 ) ;
}
static void F_71 ( struct V_75 * V_76 , T_1 V_2 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 0 ] = V_2 ;
F_70 ( V_76 , V_134 ) ;
}
static void F_72 ( struct V_75 * V_76 , T_4 V_88 ,
T_7 V_135 , T_1 V_83 , int V_136 )
{
T_4 V_137 ;
int V_138 ;
V_137 = F_73 ( V_88 , V_135 , V_139 ) ;
V_138 = 0 ;
if ( V_137 > 1 ) {
V_88 = V_140 ;
V_138 = 1 ;
}
V_88 &= V_141 ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 1 ] |= V_83 ;
V_76 -> V_73 [ 2 ] = F_67 ( V_88 ) ;
V_76 -> V_73 [ 3 ] = F_69 ( V_88 ) ;
F_70 ( V_76 , V_142 ) ;
if ( V_138 )
V_76 -> V_73 [ 2 ] |= V_143 ;
if ( V_136 )
V_76 -> V_73 [ 2 ] |= V_144 ;
}
static void F_74 ( struct V_75 * V_76 , T_1 V_2 , int V_145 ,
T_4 V_88 , T_7 V_135 )
{
T_4 V_137 ;
int V_138 ;
V_137 = F_73 ( V_88 , V_135 , V_139 ) ;
V_138 = 0 ;
if ( V_137 > 1 ) {
V_88 = V_140 ;
V_138 = 1 ;
}
V_88 &= V_141 ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 0 ] = V_2 ;
V_76 -> V_73 [ 0 ] |= ( V_145 & 0xff ) << 24 ;
V_76 -> V_73 [ 1 ] = V_2 ;
V_76 -> V_73 [ 2 ] = F_67 ( V_88 ) ;
V_76 -> V_73 [ 3 ] = F_69 ( V_88 ) ;
F_70 ( V_76 , V_146 ) ;
if ( V_138 )
V_76 -> V_73 [ 2 ] |= V_143 ;
}
static void F_75 ( struct V_75 * V_76 , T_1 V_83 , int V_113 ,
T_4 V_88 , bool V_135 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_88 &= ~ ( 0xfffULL ) ;
V_76 -> V_73 [ 0 ] = V_113 & V_147 ;
V_76 -> V_73 [ 1 ] = V_83 ;
V_76 -> V_73 [ 2 ] = F_67 ( V_88 ) ;
V_76 -> V_73 [ 3 ] = F_69 ( V_88 ) ;
V_76 -> V_73 [ 2 ] |= V_144 ;
V_76 -> V_73 [ 2 ] |= V_148 ;
if ( V_135 )
V_76 -> V_73 [ 2 ] |= V_143 ;
F_70 ( V_76 , V_142 ) ;
}
static void F_76 ( struct V_75 * V_76 , T_1 V_2 , int V_113 ,
int V_145 , T_4 V_88 , bool V_135 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_88 &= ~ ( 0xfffULL ) ;
V_76 -> V_73 [ 0 ] = V_2 ;
V_76 -> V_73 [ 0 ] |= ( V_113 & 0xff ) << 16 ;
V_76 -> V_73 [ 0 ] |= ( V_145 & 0xff ) << 24 ;
V_76 -> V_73 [ 1 ] = V_2 ;
V_76 -> V_73 [ 1 ] |= ( ( V_113 >> 8 ) & 0xfff ) << 16 ;
V_76 -> V_73 [ 2 ] = F_67 ( V_88 ) ;
V_76 -> V_73 [ 2 ] |= V_148 ;
V_76 -> V_73 [ 3 ] = F_69 ( V_88 ) ;
if ( V_135 )
V_76 -> V_73 [ 2 ] |= V_143 ;
F_70 ( V_76 , V_146 ) ;
}
static void F_77 ( struct V_75 * V_76 , T_1 V_2 , int V_113 ,
int V_149 , int V_115 , bool V_150 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_73 [ 0 ] = V_2 ;
if ( V_150 ) {
V_76 -> V_73 [ 1 ] = V_113 & V_147 ;
V_76 -> V_73 [ 2 ] = V_148 ;
}
V_76 -> V_73 [ 3 ] = V_115 & 0x1ff ;
V_76 -> V_73 [ 3 ] |= ( V_149 & V_151 ) << V_152 ;
F_70 ( V_76 , V_153 ) ;
}
static void F_78 ( struct V_75 * V_76 )
{
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
F_70 ( V_76 , V_154 ) ;
}
static int F_79 ( struct V_42 * V_18 ,
struct V_75 * V_76 ,
bool V_155 )
{
T_2 V_156 , V_99 , V_98 , V_157 ;
unsigned long V_4 ;
F_66 ( V_18 -> V_130 & V_158 ) ;
V_159:
F_4 ( & V_18 -> V_100 , V_4 ) ;
V_98 = F_46 ( V_18 -> V_101 + V_160 ) ;
V_99 = F_46 ( V_18 -> V_101 + V_131 ) ;
V_157 = ( V_99 + sizeof( * V_76 ) ) % V_18 -> V_130 ;
V_156 = ( V_98 - V_157 ) % V_18 -> V_130 ;
if ( V_156 <= 2 ) {
struct V_75 V_161 ;
volatile T_4 V_126 = 0 ;
int V_29 ;
F_65 ( & V_161 , ( T_4 ) & V_126 ) ;
F_64 ( V_18 , & V_161 , V_99 ) ;
F_6 ( & V_18 -> V_100 , V_4 ) ;
if ( ( V_29 = F_62 ( & V_126 ) ) != 0 )
return V_29 ;
goto V_159;
}
F_64 ( V_18 , V_76 , V_99 ) ;
V_18 -> V_162 = V_155 ;
F_6 ( & V_18 -> V_100 , V_4 ) ;
return 0 ;
}
static int F_80 ( struct V_42 * V_18 , struct V_75 * V_76 )
{
return F_79 ( V_18 , V_76 , true ) ;
}
static int F_81 ( struct V_42 * V_18 )
{
struct V_75 V_76 ;
volatile T_4 V_126 = 0 ;
int V_29 ;
if ( ! V_18 -> V_162 )
return 0 ;
F_65 ( & V_76 , ( T_4 ) & V_126 ) ;
V_29 = F_79 ( V_18 , & V_76 , false ) ;
if ( V_29 )
return V_29 ;
return F_62 ( & V_126 ) ;
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
T_2 V_163 ;
for ( V_163 = 0 ; V_163 <= 0xffff ; ++ V_163 ) {
struct V_75 V_76 ;
F_72 ( & V_76 , 0 , V_140 ,
V_163 , 1 ) ;
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
if ( F_87 ( V_18 , V_164 ) ) {
F_85 ( V_18 ) ;
} else {
F_83 ( V_18 ) ;
F_84 ( V_18 ) ;
}
}
static int F_88 ( struct V_1 * V_3 ,
T_4 V_88 , T_7 V_135 )
{
struct V_42 * V_18 ;
struct V_75 V_76 ;
int V_145 ;
V_145 = V_3 -> V_165 . V_145 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_74 ( & V_76 , V_3 -> V_2 , V_145 , V_88 , V_135 ) ;
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
if ( V_3 -> V_165 . V_166 )
V_29 = F_88 ( V_3 , 0 , ~ 0UL ) ;
return V_29 ;
}
static void F_90 ( struct V_167 * V_168 ,
T_4 V_88 , T_7 V_135 , int V_136 )
{
struct V_1 * V_3 ;
struct V_75 V_76 ;
int V_29 = 0 , V_23 ;
F_72 ( & V_76 , V_88 , V_135 , V_168 -> V_169 , V_136 ) ;
for ( V_23 = 0 ; V_23 < V_170 ; ++ V_23 ) {
if ( ! V_168 -> V_171 [ V_23 ] )
continue;
V_29 |= F_80 ( V_172 [ V_23 ] , & V_76 ) ;
}
F_11 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_165 . V_166 )
continue;
V_29 |= F_88 ( V_3 , V_88 , V_135 ) ;
}
F_66 ( V_29 ) ;
}
static void F_91 ( struct V_167 * V_168 ,
T_4 V_88 , T_7 V_135 )
{
F_90 ( V_168 , V_88 , V_135 , 0 ) ;
}
static void F_92 ( struct V_167 * V_168 )
{
F_90 ( V_168 , 0 , V_140 , 0 ) ;
}
static void F_93 ( struct V_167 * V_168 )
{
F_90 ( V_168 , 0 , V_140 , 1 ) ;
}
static void F_94 ( struct V_167 * V_168 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_170 ; ++ V_23 ) {
if ( ! V_168 -> V_171 [ V_23 ] )
continue;
F_81 ( V_172 [ V_23 ] ) ;
}
}
static void F_95 ( struct V_167 * V_168 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_89 ( V_3 ) ;
}
static bool F_96 ( struct V_167 * V_168 ,
T_8 V_173 )
{
T_4 * V_174 ;
if ( V_168 -> V_175 == V_176 )
return false ;
V_174 = ( void * ) F_97 ( V_173 ) ;
if ( ! V_174 )
return false ;
* V_174 = F_98 ( V_168 -> V_175 ,
F_99 ( V_168 -> V_177 ) ) ;
V_168 -> V_177 = V_174 ;
V_168 -> V_175 += 1 ;
V_168 -> V_178 = true ;
return true ;
}
static T_4 * F_100 ( struct V_167 * V_168 ,
unsigned long V_88 ,
unsigned long V_179 ,
T_4 * * V_180 ,
T_8 V_173 )
{
int V_181 , V_182 ;
T_4 * V_174 , * V_183 ;
F_101 ( ! F_102 ( V_179 ) ) ;
while ( V_88 > F_103 ( V_168 -> V_175 ) )
F_96 ( V_168 , V_173 ) ;
V_181 = V_168 -> V_175 - 1 ;
V_174 = & V_168 -> V_177 [ F_104 ( V_181 , V_88 ) ] ;
V_88 = F_105 ( V_88 , V_179 ) ;
V_182 = F_106 ( V_179 ) ;
while ( V_181 > V_182 ) {
if ( ! F_107 ( * V_174 ) ) {
V_183 = ( T_4 * ) F_97 ( V_173 ) ;
if ( ! V_183 )
return NULL ;
* V_174 = F_98 ( V_181 , F_99 ( V_183 ) ) ;
}
if ( F_108 ( * V_174 ) != V_181 )
return NULL ;
V_181 -= 1 ;
V_174 = F_109 ( * V_174 ) ;
if ( V_180 && V_181 == V_182 )
* V_180 = V_174 ;
V_174 = & V_174 [ F_104 ( V_181 , V_88 ) ] ;
}
return V_174 ;
}
static T_4 * F_110 ( struct V_167 * V_168 , unsigned long V_88 )
{
int V_181 ;
T_4 * V_174 ;
if ( V_88 > F_103 ( V_168 -> V_175 ) )
return NULL ;
V_181 = V_168 -> V_175 - 1 ;
V_174 = & V_168 -> V_177 [ F_104 ( V_181 , V_88 ) ] ;
while ( V_181 > 0 ) {
if ( ! F_107 ( * V_174 ) )
return NULL ;
if ( F_108 ( * V_174 ) == 0x07 ) {
unsigned long V_184 , V_185 ;
V_184 = F_111 ( * V_174 ) ;
V_184 = ~ ( ( F_112 ( V_184 ) << 3 ) - 1 ) ;
V_185 = ( ( unsigned long ) V_174 ) & V_184 ;
return ( T_4 * ) V_185 ;
}
if ( F_108 ( * V_174 ) != V_181 )
return NULL ;
V_181 -= 1 ;
V_174 = F_109 ( * V_174 ) ;
V_174 = & V_174 [ F_104 ( V_181 , V_88 ) ] ;
}
return V_174 ;
}
static int F_113 ( struct V_167 * V_186 ,
unsigned long V_187 ,
unsigned long V_74 ,
int V_188 ,
unsigned long V_179 )
{
T_4 V_185 , * V_174 ;
int V_23 , V_189 ;
if ( ! ( V_188 & V_190 ) )
return - V_191 ;
V_187 = F_114 ( V_187 ) ;
V_74 = F_114 ( V_74 ) ;
V_189 = F_112 ( V_179 ) ;
V_174 = F_100 ( V_186 , V_187 , V_179 , NULL , V_5 ) ;
for ( V_23 = 0 ; V_23 < V_189 ; ++ V_23 )
if ( F_107 ( V_174 [ V_23 ] ) )
return - V_192 ;
if ( V_179 > V_139 ) {
V_185 = F_115 ( V_74 , V_179 ) ;
V_185 |= F_116 ( 7 ) | V_193 | V_194 ;
} else
V_185 = V_74 | V_193 | V_194 ;
if ( V_188 & V_195 )
V_185 |= V_196 ;
if ( V_188 & V_197 )
V_185 |= V_198 ;
for ( V_23 = 0 ; V_23 < V_189 ; ++ V_23 )
V_174 [ V_23 ] = V_185 ;
F_117 ( V_186 ) ;
return 0 ;
}
static unsigned long F_118 ( struct V_167 * V_186 ,
unsigned long V_187 ,
unsigned long V_179 )
{
unsigned long long V_199 , V_200 ;
T_4 * V_174 ;
F_101 ( ! F_102 ( V_179 ) ) ;
V_200 = 0 ;
while ( V_200 < V_179 ) {
V_174 = F_110 ( V_186 , V_187 ) ;
if ( ! V_174 ) {
V_199 = V_139 ;
} else if ( F_108 ( * V_174 ) == 0 ) {
V_199 = V_139 ;
* V_174 = 0ULL ;
} else {
int V_189 , V_23 ;
V_199 = F_111 ( * V_174 ) ;
V_189 = F_112 ( V_199 ) ;
for ( V_23 = 0 ; V_23 < V_189 ; V_23 ++ )
V_174 [ V_23 ] = 0ULL ;
}
V_187 = ( V_187 & ~ ( V_199 - 1 ) ) + V_199 ;
V_200 += V_199 ;
}
F_101 ( ! F_102 ( V_200 ) ) ;
return V_200 ;
}
static int F_119 ( struct V_42 * V_18 ,
struct V_201 * V_28 )
{
T_1 V_202 , V_23 ;
for ( V_23 = V_28 -> V_203 ; V_23 <= V_28 -> V_204 ; ++ V_23 ) {
V_202 = V_31 [ V_23 ] ;
if ( V_38 [ V_202 ] == V_18 )
return 1 ;
}
return 0 ;
}
static int F_120 ( struct V_27 * V_205 ,
struct V_201 * V_206 )
{
T_4 V_207 ;
int V_29 ;
for ( V_207 = V_206 -> V_208 ; V_207 < V_206 -> V_209 ;
V_207 += V_139 ) {
V_29 = F_113 ( & V_205 -> V_168 , V_207 , V_207 , V_206 -> V_188 ,
V_139 ) ;
if ( V_29 )
return V_29 ;
if ( V_207 < V_205 -> V_210 )
F_121 ( V_207 >> V_211 ,
V_205 -> V_212 [ 0 ] -> V_213 ) ;
}
return 0 ;
}
static int F_122 ( struct V_42 * V_18 )
{
struct V_201 * V_28 ;
int V_29 ;
F_11 (entry, &amd_iommu_unity_map, list) {
if ( ! F_119 ( V_18 , V_28 ) )
continue;
V_29 = F_120 ( V_18 -> V_214 , V_28 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_123 ( struct V_27 * V_205 ,
T_1 V_2 )
{
struct V_201 * V_206 ;
int V_29 ;
F_11 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_206 -> V_203 && V_2 <= V_206 -> V_204 ) )
continue;
V_29 = F_120 ( V_205 , V_206 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static void F_124 ( struct V_27 * V_186 ,
unsigned long V_215 ,
unsigned int V_137 )
{
unsigned int V_23 , V_216 = V_186 -> V_210 >> V_211 ;
if ( V_215 + V_137 > V_216 )
V_137 = V_216 - V_215 ;
for ( V_23 = V_215 ; V_23 < V_215 + V_137 ; ++ V_23 ) {
int V_217 = V_23 / V_218 ;
int V_183 = V_23 % V_218 ;
F_121 ( V_183 , V_186 -> V_212 [ V_217 ] -> V_213 ) ;
}
}
static int F_125 ( struct V_27 * V_205 ,
bool V_219 , T_8 V_173 )
{
int V_217 = V_205 -> V_210 >> V_220 ;
struct V_42 * V_18 ;
unsigned long V_23 , V_221 ;
#ifdef F_126
V_219 = false ;
#endif
if ( V_217 >= V_222 )
return - V_39 ;
V_205 -> V_212 [ V_217 ] = F_2 ( sizeof( struct V_223 ) , V_173 ) ;
if ( ! V_205 -> V_212 [ V_217 ] )
return - V_39 ;
V_205 -> V_212 [ V_217 ] -> V_213 = ( void * ) F_97 ( V_173 ) ;
if ( ! V_205 -> V_212 [ V_217 ] -> V_213 )
goto V_48;
V_205 -> V_212 [ V_217 ] -> V_224 = V_205 -> V_210 ;
if ( V_219 ) {
unsigned long V_88 = V_205 -> V_210 ;
int V_23 , V_225 = V_218 / 512 ;
T_4 * V_174 , * V_180 ;
for ( V_23 = 0 ; V_23 < V_225 ; ++ V_23 ) {
V_174 = F_100 ( & V_205 -> V_168 , V_88 , V_139 ,
& V_180 , V_173 ) ;
if ( ! V_174 )
goto V_48;
V_205 -> V_212 [ V_217 ] -> V_226 [ V_23 ] = V_180 ;
V_88 += V_227 / 64 ;
}
}
V_221 = V_205 -> V_210 ;
V_205 -> V_210 += V_227 ;
if ( V_221 < V_228 &&
V_205 -> V_210 > V_228 ) {
unsigned long V_229 ;
int V_137 ;
V_137 = F_73 ( V_228 , 0x10000 , V_139 ) ;
V_229 = V_228 >> V_211 ;
F_124 ( V_205 , V_229 , V_137 ) ;
}
F_60 (iommu) {
if ( V_18 -> V_230 &&
V_18 -> V_230 >= V_205 -> V_212 [ V_217 ] -> V_224
&& V_18 -> V_230 < V_205 -> V_210 ) {
unsigned long V_231 ;
int V_137 = F_73 ( V_18 -> V_230 ,
V_18 -> V_232 ,
V_139 ) ;
V_231 = V_18 -> V_230 >> V_211 ;
F_124 ( V_205 , V_231 , V_137 ) ;
}
}
for ( V_23 = V_205 -> V_212 [ V_217 ] -> V_224 ;
V_23 < V_205 -> V_210 ;
V_23 += V_139 ) {
T_4 * V_174 = F_110 ( & V_205 -> V_168 , V_23 ) ;
if ( ! V_174 || ! F_107 ( * V_174 ) )
continue;
F_124 ( V_205 , V_23 >> V_211 , 1 ) ;
}
F_117 ( & V_205 -> V_168 ) ;
return 0 ;
V_48:
F_117 ( & V_205 -> V_168 ) ;
F_127 ( ( unsigned long ) V_205 -> V_212 [ V_217 ] -> V_213 ) ;
F_9 ( V_205 -> V_212 [ V_217 ] ) ;
V_205 -> V_212 [ V_217 ] = NULL ;
return - V_39 ;
}
static unsigned long F_128 ( struct V_10 * V_11 ,
struct V_27 * V_186 ,
unsigned int V_137 ,
unsigned long V_233 ,
T_4 V_35 ,
unsigned long V_234 )
{
unsigned long V_235 = V_186 -> V_236 % V_227 ;
int V_237 = V_186 -> V_210 >> V_220 ;
int V_23 = V_234 >> V_220 ;
unsigned long V_238 ;
unsigned long V_88 = - 1 ;
unsigned long V_239 ;
V_235 >>= V_211 ;
V_238 = F_129 ( F_130 ( V_11 ) + 1 ,
V_139 ) >> V_211 ;
for (; V_23 < V_237 ; ++ V_23 ) {
unsigned long V_224 = V_186 -> V_212 [ V_23 ] -> V_224 >> V_211 ;
if ( V_186 -> V_212 [ V_23 ] -> V_224 >= V_35 )
break;
V_239 = F_131 ( V_218 , V_224 ,
V_35 >> V_211 ) ;
V_88 = F_132 ( V_186 -> V_212 [ V_23 ] -> V_213 ,
V_239 , V_235 , V_137 , 0 ,
V_238 , V_233 ) ;
if ( V_88 != - 1 ) {
V_88 = V_186 -> V_212 [ V_23 ] -> V_224 +
( V_88 << V_211 ) ;
V_186 -> V_236 = V_88 + ( V_137 << V_211 ) ;
break;
}
V_235 = 0 ;
}
return V_88 ;
}
static unsigned long F_133 ( struct V_10 * V_11 ,
struct V_27 * V_186 ,
unsigned int V_137 ,
unsigned long V_233 ,
T_4 V_35 )
{
unsigned long V_88 ;
#ifdef F_126
V_186 -> V_236 = 0 ;
V_186 -> V_240 = true ;
#endif
V_88 = F_128 ( V_11 , V_186 , V_137 , V_233 ,
V_35 , V_186 -> V_236 ) ;
if ( V_88 == - 1 ) {
V_186 -> V_236 = 0 ;
V_88 = F_128 ( V_11 , V_186 , V_137 , V_233 ,
V_35 , 0 ) ;
V_186 -> V_240 = true ;
}
if ( F_134 ( V_88 == - 1 ) )
V_88 = V_241 ;
F_66 ( ( V_88 + ( V_139 * V_137 ) ) > V_186 -> V_210 ) ;
return V_88 ;
}
static void F_135 ( struct V_27 * V_186 ,
unsigned long V_88 ,
unsigned int V_137 )
{
unsigned V_23 = V_88 >> V_220 ;
struct V_223 * V_242 = V_186 -> V_212 [ V_23 ] ;
F_101 ( V_23 >= V_222 || V_242 == NULL ) ;
#ifdef F_126
if ( V_23 < 4 )
return;
#endif
if ( V_88 >= V_186 -> V_236 )
V_186 -> V_240 = true ;
V_88 = ( V_88 % V_227 ) >> V_211 ;
F_136 ( V_242 -> V_213 , V_88 , V_137 ) ;
}
static void F_137 ( struct V_167 * V_168 )
{
unsigned long V_4 ;
F_4 ( & V_243 , V_4 ) ;
F_138 ( & V_168 -> V_244 , & V_245 ) ;
F_6 ( & V_243 , V_4 ) ;
}
static void F_139 ( struct V_167 * V_168 )
{
unsigned long V_4 ;
F_4 ( & V_243 , V_4 ) ;
F_8 ( & V_168 -> V_244 ) ;
F_6 ( & V_243 , V_4 ) ;
}
static T_1 F_140 ( void )
{
unsigned long V_4 ;
int V_169 ;
F_141 ( & V_246 , V_4 ) ;
V_169 = F_142 ( V_247 , V_248 ) ;
F_101 ( V_169 == 0 ) ;
if ( V_169 > 0 && V_169 < V_248 )
F_121 ( V_169 , V_247 ) ;
else
V_169 = 0 ;
F_143 ( & V_246 , V_4 ) ;
return V_169 ;
}
static void F_144 ( int V_169 )
{
unsigned long V_4 ;
F_141 ( & V_246 , V_4 ) ;
if ( V_169 > 0 && V_169 < V_248 )
F_145 ( V_169 , V_247 ) ;
F_143 ( & V_246 , V_4 ) ;
}
static void F_146 ( struct V_167 * V_168 )
{
int V_23 , V_249 ;
T_4 * V_250 , * V_251 , * V_252 ;
V_250 = V_168 -> V_177 ;
if ( ! V_250 )
return;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! F_107 ( V_250 [ V_23 ] ) )
continue;
V_251 = F_109 ( V_250 [ V_23 ] ) ;
for ( V_249 = 0 ; V_249 < 512 ; ++ V_249 ) {
if ( ! F_107 ( V_251 [ V_249 ] ) )
continue;
V_252 = F_109 ( V_251 [ V_249 ] ) ;
F_127 ( ( unsigned long ) V_252 ) ;
}
F_127 ( ( unsigned long ) V_251 ) ;
}
F_127 ( ( unsigned long ) V_250 ) ;
V_168 -> V_177 = NULL ;
}
static void F_147 ( T_4 * V_253 )
{
T_4 * V_254 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_253 [ V_23 ] & V_255 ) )
continue;
V_254 = F_148 ( V_253 [ V_23 ] & V_141 ) ;
F_127 ( ( unsigned long ) V_254 ) ;
}
}
static void F_149 ( T_4 * V_253 )
{
T_4 * V_254 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_253 [ V_23 ] & V_255 ) )
continue;
V_254 = F_148 ( V_253 [ V_23 ] & V_141 ) ;
F_147 ( V_254 ) ;
}
}
static void F_150 ( struct V_167 * V_168 )
{
if ( V_168 -> V_256 == 2 )
F_149 ( V_168 -> V_257 ) ;
else if ( V_168 -> V_256 == 1 )
F_147 ( V_168 -> V_257 ) ;
else if ( V_168 -> V_256 != 0 )
F_151 () ;
F_127 ( ( unsigned long ) V_168 -> V_257 ) ;
}
static void F_152 ( struct V_27 * V_186 )
{
int V_23 ;
if ( ! V_186 )
return;
F_139 ( & V_186 -> V_168 ) ;
F_146 ( & V_186 -> V_168 ) ;
for ( V_23 = 0 ; V_23 < V_222 ; ++ V_23 ) {
if ( ! V_186 -> V_212 [ V_23 ] )
continue;
F_127 ( ( unsigned long ) V_186 -> V_212 [ V_23 ] -> V_213 ) ;
F_9 ( V_186 -> V_212 [ V_23 ] ) ;
}
F_9 ( V_186 ) ;
}
static struct V_27 * F_153 ( void )
{
struct V_27 * V_205 ;
V_205 = F_2 ( sizeof( struct V_27 ) , V_5 ) ;
if ( ! V_205 )
return NULL ;
F_154 ( & V_205 -> V_168 . V_100 ) ;
V_205 -> V_168 . V_169 = F_140 () ;
if ( V_205 -> V_168 . V_169 == 0 )
goto V_258;
F_155 ( & V_205 -> V_168 . V_259 ) ;
V_205 -> V_168 . V_175 = V_260 ;
V_205 -> V_168 . V_177 = ( void * ) F_97 ( V_5 ) ;
V_205 -> V_168 . V_4 = V_261 ;
V_205 -> V_168 . V_262 = V_205 ;
if ( ! V_205 -> V_168 . V_177 )
goto V_258;
V_205 -> V_240 = false ;
V_205 -> V_34 = 0xffff ;
F_137 ( & V_205 -> V_168 ) ;
if ( F_125 ( V_205 , true , V_5 ) )
goto V_258;
V_205 -> V_212 [ 0 ] -> V_213 [ 0 ] = 1 ;
V_205 -> V_236 = 0 ;
return V_205 ;
V_258:
F_152 ( V_205 ) ;
return NULL ;
}
static bool V_27 ( struct V_167 * V_168 )
{
return V_168 -> V_4 & V_261 ;
}
static void F_156 ( T_1 V_2 , struct V_167 * V_168 , bool V_165 )
{
T_4 V_263 = 0 ;
T_4 V_4 = 0 ;
if ( V_168 -> V_175 != V_264 )
V_263 = F_99 ( V_168 -> V_177 ) ;
V_263 |= ( V_168 -> V_175 & V_265 )
<< V_266 ;
V_263 |= V_196 | V_198 | V_193 | V_267 ;
V_4 = V_45 [ V_2 ] . V_73 [ 1 ] ;
if ( V_165 )
V_4 |= V_268 ;
if ( V_168 -> V_4 & V_269 ) {
T_4 V_270 = F_68 ( V_168 -> V_257 ) ;
T_4 V_256 = V_168 -> V_256 ;
T_4 V_271 ;
V_263 |= V_272 ;
V_263 |= ( V_256 & V_273 ) << V_274 ;
V_271 = F_157 ( ~ 0ULL ) << V_275 ;
V_4 &= ~ V_271 ;
V_271 = F_158 ( ~ 0ULL ) << V_276 ;
V_4 &= ~ V_271 ;
V_271 = F_159 ( V_270 ) << V_277 ;
V_263 |= V_271 ;
V_271 = F_157 ( V_270 ) << V_275 ;
V_4 |= V_271 ;
V_271 = F_158 ( V_270 ) << V_276 ;
V_4 |= V_271 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_168 -> V_169 ;
V_45 [ V_2 ] . V_73 [ 1 ] = V_4 ;
V_45 [ V_2 ] . V_73 [ 0 ] = V_263 ;
}
static void F_160 ( T_1 V_2 )
{
V_45 [ V_2 ] . V_73 [ 0 ] = V_193 | V_267 ;
V_45 [ V_2 ] . V_73 [ 1 ] = 0 ;
F_161 ( V_2 ) ;
}
static void F_162 ( struct V_1 * V_3 ,
struct V_167 * V_168 )
{
struct V_42 * V_18 ;
bool V_165 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_165 = V_3 -> V_165 . V_166 ;
V_3 -> V_168 = V_168 ;
F_138 ( & V_3 -> V_244 , & V_168 -> V_259 ) ;
F_156 ( V_3 -> V_2 , V_168 , V_165 ) ;
V_168 -> V_171 [ V_18 -> V_217 ] += 1 ;
V_168 -> V_278 += 1 ;
F_89 ( V_3 ) ;
}
static void F_163 ( struct V_1 * V_3 )
{
struct V_42 * V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_3 -> V_168 -> V_171 [ V_18 -> V_217 ] -= 1 ;
V_3 -> V_168 -> V_278 -= 1 ;
V_3 -> V_168 = NULL ;
F_8 ( & V_3 -> V_244 ) ;
F_160 ( V_3 -> V_2 ) ;
F_89 ( V_3 ) ;
}
static int F_164 ( struct V_1 * V_3 ,
struct V_167 * V_168 )
{
int V_29 ;
F_165 ( & V_168 -> V_100 ) ;
if ( V_3 -> V_40 != NULL ) {
struct V_1 * V_40 = V_3 -> V_40 ;
V_29 = - V_192 ;
if ( V_40 -> V_168 != NULL &&
V_40 -> V_168 != V_168 )
goto V_9;
if ( V_3 -> V_168 != NULL &&
V_3 -> V_168 != V_168 )
goto V_9;
if ( V_40 -> V_168 == NULL )
F_162 ( V_40 , V_168 ) ;
F_166 ( & V_40 -> V_6 ) ;
}
if ( V_3 -> V_168 == NULL )
F_162 ( V_3 , V_168 ) ;
F_166 ( & V_3 -> V_6 ) ;
V_29 = 0 ;
V_9:
F_167 ( & V_168 -> V_100 ) ;
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
T_1 V_279 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return - V_191 ;
F_173 ( V_13 , V_24 + V_280 , & V_279 ) ;
V_279 |= V_281 ;
F_174 ( V_13 , V_24 + V_280 , V_279 ) ;
return 0 ;
}
static int F_175 ( struct V_12 * V_13 )
{
bool V_282 ;
int V_283 , V_29 ;
V_283 = 32 ;
if ( F_19 ( V_13 , V_284 ) )
V_283 = 1 ;
V_282 = F_19 ( V_13 , V_285 ) ;
V_29 = F_176 ( V_13 , 0 ) ;
if ( V_29 )
goto V_286;
V_29 = F_177 ( V_13 ) ;
if ( V_29 )
goto V_286;
V_29 = F_178 ( V_13 , V_283 ) ;
if ( V_29 )
goto V_286;
if ( V_282 ) {
V_29 = F_172 ( V_13 ) ;
if ( V_29 )
goto V_286;
}
V_29 = F_179 ( V_13 , V_211 ) ;
if ( V_29 )
goto V_286;
return 0 ;
V_286:
F_170 ( V_13 ) ;
F_171 ( V_13 ) ;
return V_29 ;
}
bool F_180 ( struct V_12 * V_13 )
{
T_1 V_279 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return false ;
F_173 ( V_13 , V_24 + V_280 , & V_279 ) ;
return ( V_279 & V_287 ) ? true : false ;
}
static int F_181 ( struct V_10 * V_11 ,
struct V_167 * V_168 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_29 ;
V_3 = F_16 ( V_11 ) ;
if ( V_168 -> V_4 & V_269 ) {
if ( ! V_3 -> V_43 || ! V_3 -> V_288 )
return - V_191 ;
if ( F_175 ( V_13 ) != 0 )
return - V_191 ;
V_3 -> V_165 . V_166 = true ;
V_3 -> V_165 . V_145 = F_182 ( V_13 ) ;
V_3 -> V_289 = F_180 ( V_13 ) ;
} else if ( V_290 &&
F_179 ( V_13 , V_211 ) == 0 ) {
V_3 -> V_165 . V_166 = true ;
V_3 -> V_165 . V_145 = F_182 ( V_13 ) ;
}
F_141 ( & V_246 , V_4 ) ;
V_29 = F_164 ( V_3 , V_168 ) ;
F_143 ( & V_246 , V_4 ) ;
F_93 ( V_168 ) ;
return V_29 ;
}
static void F_183 ( struct V_1 * V_3 )
{
struct V_167 * V_168 ;
unsigned long V_4 ;
F_101 ( ! V_3 -> V_168 ) ;
V_168 = V_3 -> V_168 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
if ( V_3 -> V_40 != NULL ) {
struct V_1 * V_40 = V_3 -> V_40 ;
if ( F_184 ( & V_40 -> V_6 ) )
F_163 ( V_40 ) ;
}
if ( F_184 ( & V_3 -> V_6 ) )
F_163 ( V_3 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
if ( V_3 -> V_288 &&
( V_3 -> V_168 == NULL && V_168 != V_291 ) )
F_164 ( V_3 , V_291 ) ;
}
static void F_185 ( struct V_10 * V_11 )
{
struct V_167 * V_168 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
V_168 = V_3 -> V_168 ;
F_141 ( & V_246 , V_4 ) ;
F_183 ( V_3 ) ;
F_143 ( & V_246 , V_4 ) ;
if ( V_168 -> V_4 & V_269 )
F_168 ( F_14 ( V_11 ) ) ;
else if ( V_3 -> V_165 . V_166 )
F_169 ( F_14 ( V_11 ) ) ;
V_3 -> V_165 . V_166 = false ;
}
static struct V_167 * F_186 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
struct V_167 * V_186 = NULL ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
if ( V_3 -> V_168 )
return V_3 -> V_168 ;
if ( V_3 -> V_40 != NULL ) {
struct V_1 * V_40 = V_3 -> V_40 ;
F_187 ( & V_246 , V_4 ) ;
if ( V_40 -> V_168 != NULL ) {
F_164 ( V_3 , V_40 -> V_168 ) ;
V_186 = V_40 -> V_168 ;
}
F_188 ( & V_246 , V_4 ) ;
}
return V_186 ;
}
static int F_189 ( struct V_292 * V_293 ,
unsigned long V_294 , void * V_73 )
{
struct V_27 * V_295 ;
struct V_167 * V_168 ;
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
switch ( V_294 ) {
case V_296 :
V_168 = F_186 ( V_11 ) ;
if ( ! V_168 )
goto V_297;
if ( V_3 -> V_288 )
break;
F_185 ( V_11 ) ;
break;
case V_298 :
F_23 ( V_11 ) ;
V_168 = F_186 ( V_11 ) ;
V_295 = F_20 ( V_2 ) ;
if ( V_295 )
goto V_297;
V_295 = F_153 () ;
if ( ! V_295 )
goto V_297;
V_295 -> V_34 = V_2 ;
F_4 ( & V_33 , V_4 ) ;
F_5 ( & V_295 -> V_244 , & V_32 ) ;
F_6 ( & V_33 , V_4 ) ;
break;
case V_299 :
F_27 ( V_11 ) ;
default:
goto V_297;
}
F_81 ( V_18 ) ;
V_297:
return 0 ;
}
void F_190 ( void )
{
F_191 ( & V_36 , & V_300 ) ;
}
static struct V_167 * F_192 ( struct V_10 * V_11 )
{
struct V_167 * V_168 ;
struct V_27 * V_205 ;
T_1 V_2 = F_13 ( V_11 ) ;
if ( ! F_22 ( V_11 ) )
return F_193 ( - V_191 ) ;
V_168 = F_186 ( V_11 ) ;
if ( V_168 != NULL && ! V_27 ( V_168 ) )
return F_193 ( - V_192 ) ;
if ( V_168 != NULL )
return V_168 ;
V_205 = F_20 ( V_2 ) ;
if ( ! V_205 )
V_205 = V_38 [ V_2 ] -> V_214 ;
F_181 ( V_11 , & V_205 -> V_168 ) ;
F_194 ( L_22 ,
V_205 -> V_168 . V_169 , F_25 ( V_11 ) ) ;
return & V_205 -> V_168 ;
}
static void F_195 ( struct V_167 * V_168 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_156 ( V_3 -> V_2 , V_168 , V_3 -> V_165 . V_166 ) ;
}
static void F_117 ( struct V_167 * V_168 )
{
if ( ! V_168 -> V_178 )
return;
F_195 ( V_168 ) ;
F_95 ( V_168 ) ;
F_93 ( V_168 ) ;
V_168 -> V_178 = false ;
}
static T_4 * F_196 ( struct V_27 * V_186 ,
unsigned long V_88 )
{
struct V_223 * V_212 ;
T_4 * V_174 , * V_180 ;
V_212 = V_186 -> V_212 [ F_197 ( V_88 ) ] ;
if ( ! V_212 )
return NULL ;
V_174 = V_212 -> V_226 [ F_198 ( V_88 ) ] ;
if ( ! V_174 ) {
V_174 = F_100 ( & V_186 -> V_168 , V_88 , V_139 , & V_180 ,
V_301 ) ;
V_212 -> V_226 [ F_198 ( V_88 ) ] = V_180 ;
} else
V_174 += F_104 ( 0 , V_88 ) ;
F_117 ( & V_186 -> V_168 ) ;
return V_174 ;
}
static T_9 F_199 ( struct V_27 * V_186 ,
unsigned long V_88 ,
T_10 V_302 ,
int V_303 )
{
T_4 * V_174 , V_185 ;
F_66 ( V_88 > V_186 -> V_210 ) ;
V_302 &= V_141 ;
V_174 = F_196 ( V_186 , V_88 ) ;
if ( ! V_174 )
return V_241 ;
V_185 = V_302 | V_193 | V_194 ;
if ( V_303 == V_304 )
V_185 |= V_196 ;
else if ( V_303 == V_305 )
V_185 |= V_198 ;
else if ( V_303 == V_306 )
V_185 |= V_196 | V_198 ;
F_66 ( * V_174 ) ;
* V_174 = V_185 ;
return ( T_9 ) V_88 ;
}
static void F_200 ( struct V_27 * V_186 ,
unsigned long V_88 )
{
struct V_223 * V_212 ;
T_4 * V_174 ;
if ( V_88 >= V_186 -> V_210 )
return;
V_212 = V_186 -> V_212 [ F_197 ( V_88 ) ] ;
if ( ! V_212 )
return;
V_174 = V_212 -> V_226 [ F_198 ( V_88 ) ] ;
if ( ! V_174 )
return;
V_174 += F_104 ( 0 , V_88 ) ;
F_66 ( ! * V_174 ) ;
* V_174 = 0ULL ;
}
static T_9 F_201 ( struct V_10 * V_11 ,
struct V_27 * V_205 ,
T_10 V_302 ,
T_7 V_135 ,
int V_307 ,
bool V_308 ,
T_4 V_35 )
{
T_9 V_224 = V_302 & ~ V_141 ;
T_9 V_88 , V_234 , V_29 ;
unsigned int V_137 ;
unsigned long V_233 = 0 ;
int V_23 ;
V_137 = F_73 ( V_302 , V_135 , V_139 ) ;
V_302 &= V_141 ;
F_49 ( V_68 ) ;
if ( V_137 > 1 )
F_49 ( V_64 ) ;
if ( V_308 )
V_233 = ( 1UL << F_202 ( V_135 ) ) - 1 ;
V_309:
V_88 = F_133 ( V_11 , V_205 , V_137 , V_233 ,
V_35 ) ;
if ( F_134 ( V_88 == V_241 ) ) {
V_205 -> V_236 = V_205 -> V_210 ;
if ( F_125 ( V_205 , false , V_301 ) )
goto V_297;
goto V_309;
}
V_234 = V_88 ;
for ( V_23 = 0 ; V_23 < V_137 ; ++ V_23 ) {
V_29 = F_199 ( V_205 , V_234 , V_302 , V_307 ) ;
if ( V_29 == V_241 )
goto V_310;
V_302 += V_139 ;
V_234 += V_139 ;
}
V_88 += V_224 ;
F_203 ( V_67 , V_135 ) ;
if ( F_134 ( V_205 -> V_240 && ! V_56 ) ) {
F_92 ( & V_205 -> V_168 ) ;
V_205 -> V_240 = false ;
} else if ( F_134 ( V_311 ) )
F_91 ( & V_205 -> V_168 , V_88 , V_135 ) ;
V_297:
return V_88 ;
V_310:
for ( -- V_23 ; V_23 >= 0 ; -- V_23 ) {
V_234 -= V_139 ;
F_200 ( V_205 , V_234 ) ;
}
F_135 ( V_205 , V_88 , V_137 ) ;
return V_241 ;
}
static void F_204 ( struct V_27 * V_205 ,
T_9 V_312 ,
T_7 V_135 ,
int V_307 )
{
T_9 V_313 ;
T_9 V_23 , V_234 ;
unsigned int V_137 ;
if ( ( V_312 == V_241 ) ||
( V_312 + V_135 > V_205 -> V_210 ) )
return;
V_313 = V_312 ;
V_137 = F_73 ( V_312 , V_135 , V_139 ) ;
V_312 &= V_141 ;
V_234 = V_312 ;
for ( V_23 = 0 ; V_23 < V_137 ; ++ V_23 ) {
F_200 ( V_205 , V_234 ) ;
V_234 += V_139 ;
}
F_205 ( V_67 , V_135 ) ;
F_135 ( V_205 , V_312 , V_137 ) ;
if ( V_56 || V_205 -> V_240 ) {
F_91 ( & V_205 -> V_168 , V_313 , V_135 ) ;
V_205 -> V_240 = false ;
}
}
static T_9 F_206 ( struct V_10 * V_11 , struct V_183 * V_183 ,
unsigned long V_224 , T_7 V_135 ,
enum V_314 V_307 ,
struct V_315 * V_316 )
{
unsigned long V_4 ;
struct V_167 * V_168 ;
T_9 V_207 ;
T_4 V_35 ;
T_10 V_302 = F_207 ( V_183 ) + V_224 ;
F_49 ( V_58 ) ;
V_168 = F_192 ( V_11 ) ;
if ( F_208 ( V_168 ) == - V_191 )
return ( T_9 ) V_302 ;
else if ( F_209 ( V_168 ) )
return V_241 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
V_207 = F_201 ( V_11 , V_168 -> V_262 , V_302 , V_135 , V_307 , false ,
V_35 ) ;
if ( V_207 == V_241 )
goto V_297;
F_94 ( V_168 ) ;
V_297:
F_6 ( & V_168 -> V_100 , V_4 ) ;
return V_207 ;
}
static void F_210 ( struct V_10 * V_11 , T_9 V_312 , T_7 V_135 ,
enum V_314 V_307 , struct V_315 * V_316 )
{
unsigned long V_4 ;
struct V_167 * V_168 ;
F_49 ( V_59 ) ;
V_168 = F_192 ( V_11 ) ;
if ( F_209 ( V_168 ) )
return;
F_4 ( & V_168 -> V_100 , V_4 ) ;
F_204 ( V_168 -> V_262 , V_312 , V_135 , V_307 ) ;
F_94 ( V_168 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
}
static int F_211 ( struct V_10 * V_11 , struct V_317 * V_318 ,
int V_319 , int V_307 )
{
struct V_317 * V_138 ;
int V_23 ;
F_212 (sglist, s, nelems, i) {
V_138 -> V_320 = ( T_9 ) F_213 ( V_138 ) ;
V_138 -> V_321 = V_138 -> V_322 ;
}
return V_319 ;
}
static int F_214 ( struct V_10 * V_11 , struct V_317 * V_318 ,
int V_319 , enum V_314 V_307 ,
struct V_315 * V_316 )
{
unsigned long V_4 ;
struct V_167 * V_168 ;
int V_23 ;
struct V_317 * V_138 ;
T_10 V_302 ;
int V_323 = 0 ;
T_4 V_35 ;
F_49 ( V_60 ) ;
V_168 = F_192 ( V_11 ) ;
if ( F_208 ( V_168 ) == - V_191 )
return F_211 ( V_11 , V_318 , V_319 , V_307 ) ;
else if ( F_209 ( V_168 ) )
return 0 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
F_212 (sglist, s, nelems, i) {
V_302 = F_213 ( V_138 ) ;
V_138 -> V_320 = F_201 ( V_11 , V_168 -> V_262 ,
V_302 , V_138 -> V_322 , V_307 , false ,
V_35 ) ;
if ( V_138 -> V_320 ) {
V_138 -> V_321 = V_138 -> V_322 ;
V_323 ++ ;
} else
goto V_324;
}
F_94 ( V_168 ) ;
V_297:
F_6 ( & V_168 -> V_100 , V_4 ) ;
return V_323 ;
V_324:
F_212 (sglist, s, mapped_elems, i) {
if ( V_138 -> V_320 )
F_204 ( V_168 -> V_262 , V_138 -> V_320 ,
V_138 -> V_321 , V_307 ) ;
V_138 -> V_320 = V_138 -> V_321 = 0 ;
}
V_323 = 0 ;
goto V_297;
}
static void F_215 ( struct V_10 * V_11 , struct V_317 * V_318 ,
int V_319 , enum V_314 V_307 ,
struct V_315 * V_316 )
{
unsigned long V_4 ;
struct V_167 * V_168 ;
struct V_317 * V_138 ;
int V_23 ;
F_49 ( V_61 ) ;
V_168 = F_192 ( V_11 ) ;
if ( F_209 ( V_168 ) )
return;
F_4 ( & V_168 -> V_100 , V_4 ) ;
F_212 (sglist, s, nelems, i) {
F_204 ( V_168 -> V_262 , V_138 -> V_320 ,
V_138 -> V_321 , V_307 ) ;
V_138 -> V_320 = V_138 -> V_321 = 0 ;
}
F_94 ( V_168 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
}
static void * F_216 ( struct V_10 * V_11 , T_7 V_135 ,
T_9 * V_312 , T_8 V_325 )
{
unsigned long V_4 ;
void * V_326 ;
struct V_167 * V_168 ;
T_10 V_302 ;
T_4 V_35 = V_11 -> V_327 ;
F_49 ( V_62 ) ;
V_168 = F_192 ( V_11 ) ;
if ( F_208 ( V_168 ) == - V_191 ) {
V_326 = ( void * ) F_217 ( V_325 , F_202 ( V_135 ) ) ;
* V_312 = F_68 ( V_326 ) ;
return V_326 ;
} else if ( F_209 ( V_168 ) )
return NULL ;
V_35 = V_11 -> V_327 ;
V_325 &= ~ ( V_328 | V_329 | V_330 ) ;
V_325 |= V_331 ;
V_326 = ( void * ) F_217 ( V_325 , F_202 ( V_135 ) ) ;
if ( ! V_326 )
return NULL ;
V_302 = F_99 ( V_326 ) ;
if ( ! V_35 )
V_35 = * V_11 -> V_35 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
* V_312 = F_201 ( V_11 , V_168 -> V_262 , V_302 ,
V_135 , V_306 , true , V_35 ) ;
if ( * V_312 == V_241 ) {
F_6 ( & V_168 -> V_100 , V_4 ) ;
goto V_48;
}
F_94 ( V_168 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
return V_326 ;
V_48:
F_218 ( ( unsigned long ) V_326 , F_202 ( V_135 ) ) ;
return NULL ;
}
static void F_219 ( struct V_10 * V_11 , T_7 V_135 ,
void * V_326 , T_9 V_312 )
{
unsigned long V_4 ;
struct V_167 * V_168 ;
F_49 ( V_63 ) ;
V_168 = F_192 ( V_11 ) ;
if ( F_209 ( V_168 ) )
goto V_332;
F_4 ( & V_168 -> V_100 , V_4 ) ;
F_204 ( V_168 -> V_262 , V_312 , V_135 , V_306 ) ;
F_94 ( V_168 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
V_332:
F_218 ( ( unsigned long ) V_326 , F_202 ( V_135 ) ) ;
}
static int F_220 ( struct V_10 * V_11 , T_4 V_333 )
{
return F_22 ( V_11 ) ;
}
static void F_221 ( void )
{
struct V_1 * V_3 ;
struct V_27 * V_205 ;
struct V_12 * V_11 = NULL ;
T_1 V_2 ;
F_29 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
if ( ! V_334 && V_3 -> V_43 ) {
F_222 () ;
V_3 -> V_288 = true ;
F_181 ( & V_11 -> V_11 , V_291 ) ;
F_223 ( L_23 ,
F_25 ( & V_11 -> V_11 ) ) ;
}
if ( F_186 ( & V_11 -> V_11 ) )
continue;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_205 = F_153 () ;
if ( ! V_205 )
continue;
F_123 ( V_205 , V_2 ) ;
V_205 -> V_34 = V_2 ;
F_181 ( & V_11 -> V_11 , & V_205 -> V_168 ) ;
F_5 ( & V_205 -> V_244 , & V_32 ) ;
}
}
static unsigned F_224 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_13 = NULL ;
unsigned V_335 = 0 ;
F_29 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) ) {
F_26 ( & V_13 -> V_11 ) ;
V_335 += 1 ;
continue;
}
V_3 = F_16 ( & V_13 -> V_11 ) ;
if ( ! V_3 -> V_288 )
V_13 -> V_11 . V_17 . V_336 = & V_337 ;
else
V_13 -> V_11 . V_17 . V_336 = & V_338 ;
}
return V_335 ;
}
void T_3 F_225 ( void )
{
F_226 ( & V_36 , & V_339 ) ;
}
int T_3 F_227 ( void )
{
struct V_42 * V_18 ;
int V_29 , V_335 ;
F_60 (iommu) {
V_18 -> V_214 = F_153 () ;
if ( V_18 -> V_214 == NULL )
return - V_39 ;
V_18 -> V_214 -> V_168 . V_4 |= V_340 ;
V_29 = F_122 ( V_18 ) ;
if ( V_29 )
goto V_341;
}
F_221 () ;
V_342 = 1 ;
V_343 = 0 ;
V_335 = F_224 () ;
if ( V_335 && V_344 > V_345 ) {
V_343 = 1 ;
}
F_34 () ;
return 0 ;
V_341:
F_60 (iommu) {
if ( V_18 -> V_214 )
F_152 ( V_18 -> V_214 ) ;
}
return V_29 ;
}
static void F_228 ( struct V_167 * V_168 )
{
struct V_1 * V_3 , * V_346 ;
unsigned long V_4 ;
F_141 ( & V_246 , V_4 ) ;
F_30 (dev_data, next, &domain->dev_list, list) {
F_183 ( V_3 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
}
F_143 ( & V_246 , V_4 ) ;
}
static void F_229 ( struct V_167 * V_168 )
{
if ( ! V_168 )
return;
F_139 ( V_168 ) ;
if ( V_168 -> V_169 )
F_144 ( V_168 -> V_169 ) ;
F_9 ( V_168 ) ;
}
static struct V_167 * F_230 ( void )
{
struct V_167 * V_168 ;
V_168 = F_2 ( sizeof( * V_168 ) , V_5 ) ;
if ( ! V_168 )
return NULL ;
F_154 ( & V_168 -> V_100 ) ;
F_231 ( & V_168 -> V_347 ) ;
V_168 -> V_169 = F_140 () ;
if ( ! V_168 -> V_169 )
goto V_286;
F_155 ( & V_168 -> V_259 ) ;
F_137 ( V_168 ) ;
return V_168 ;
V_286:
F_9 ( V_168 ) ;
return NULL ;
}
static int T_3 F_222 ( void )
{
if ( V_291 != NULL )
return 0 ;
V_291 = F_230 () ;
if ( ! V_291 )
return - V_39 ;
V_291 -> V_175 = V_264 ;
return 0 ;
}
static int F_232 ( struct V_348 * V_186 )
{
struct V_167 * V_168 ;
V_168 = F_230 () ;
if ( ! V_168 )
goto V_48;
V_168 -> V_175 = V_349 ;
V_168 -> V_177 = ( void * ) F_97 ( V_5 ) ;
if ( ! V_168 -> V_177 )
goto V_48;
V_168 -> V_348 = V_186 ;
V_186 -> V_262 = V_168 ;
return 0 ;
V_48:
F_229 ( V_168 ) ;
return - V_39 ;
}
static void F_233 ( struct V_348 * V_186 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
if ( ! V_168 )
return;
if ( V_168 -> V_278 > 0 )
F_228 ( V_168 ) ;
F_101 ( V_168 -> V_278 != 0 ) ;
if ( V_168 -> V_175 != V_264 )
F_146 ( V_168 ) ;
if ( V_168 -> V_4 & V_269 )
F_150 ( V_168 ) ;
F_229 ( V_168 ) ;
V_186 -> V_262 = NULL ;
}
static void F_234 ( struct V_348 * V_186 ,
struct V_10 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_17 . V_18 ;
struct V_42 * V_18 ;
T_1 V_2 ;
if ( ! F_22 ( V_11 ) )
return;
V_2 = F_13 ( V_11 ) ;
if ( V_3 -> V_168 != NULL )
F_185 ( V_11 ) ;
V_18 = V_38 [ V_2 ] ;
if ( ! V_18 )
return;
F_81 ( V_18 ) ;
}
static int F_235 ( struct V_348 * V_186 ,
struct V_10 * V_11 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
struct V_1 * V_3 ;
struct V_42 * V_18 ;
int V_29 ;
if ( ! F_22 ( V_11 ) )
return - V_191 ;
V_3 = V_11 -> V_17 . V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
if ( ! V_18 )
return - V_191 ;
if ( V_3 -> V_168 )
F_185 ( V_11 ) ;
V_29 = F_181 ( V_11 , V_168 ) ;
F_81 ( V_18 ) ;
return V_29 ;
}
static int F_236 ( struct V_348 * V_186 , unsigned long V_350 ,
T_10 V_302 , T_7 V_179 , int V_351 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
int V_188 = 0 ;
int V_29 ;
if ( V_168 -> V_175 == V_264 )
return - V_191 ;
if ( V_351 & V_352 )
V_188 |= V_195 ;
if ( V_351 & V_353 )
V_188 |= V_197 ;
F_237 ( & V_168 -> V_347 ) ;
V_29 = F_113 ( V_168 , V_350 , V_302 , V_188 , V_179 ) ;
F_238 ( & V_168 -> V_347 ) ;
return V_29 ;
}
static T_7 F_239 ( struct V_348 * V_186 , unsigned long V_350 ,
T_7 V_179 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
T_7 V_199 ;
if ( V_168 -> V_175 == V_264 )
return - V_191 ;
F_237 ( & V_168 -> V_347 ) ;
V_199 = F_118 ( V_168 , V_350 , V_179 ) ;
F_238 ( & V_168 -> V_347 ) ;
F_93 ( V_168 ) ;
return V_199 ;
}
static T_10 F_240 ( struct V_348 * V_186 ,
unsigned long V_350 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
unsigned long V_354 ;
T_10 V_302 ;
T_4 * V_174 , V_185 ;
if ( V_168 -> V_175 == V_264 )
return V_350 ;
V_174 = F_110 ( V_168 , V_350 ) ;
if ( ! V_174 || ! F_107 ( * V_174 ) )
return 0 ;
if ( F_108 ( * V_174 ) == 0 )
V_354 = V_139 - 1 ;
else
V_354 = F_111 ( * V_174 ) - 1 ;
V_185 = * V_174 & V_355 ;
V_302 = ( V_185 & ~ V_354 ) | ( V_350 & V_354 ) ;
return V_302 ;
}
static int F_241 ( struct V_348 * V_168 ,
unsigned long V_356 )
{
switch ( V_356 ) {
case V_357 :
return 1 ;
}
return 0 ;
}
static int F_242 ( struct V_10 * V_11 , unsigned int * V_358 )
{
struct V_1 * V_3 = V_11 -> V_17 . V_18 ;
struct V_12 * V_13 = F_14 ( V_11 ) ;
T_1 V_2 ;
if ( ! V_3 )
return - V_359 ;
if ( V_13 -> V_360 || ! V_361 )
V_2 = V_3 -> V_2 ;
else
V_2 = F_15 ( V_13 -> V_14 -> V_15 ,
F_243 ( F_43 ( V_13 -> V_16 ) , 0 ) ) ;
* V_358 = V_31 [ V_2 ] ;
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
V_3 -> V_288 = true ;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_18 = V_38 [ V_2 ] ;
if ( ! V_18 )
continue;
F_181 ( & V_11 -> V_11 , V_291 ) ;
}
F_34 () ;
F_223 ( L_24 ) ;
return 0 ;
}
int F_245 ( struct V_292 * V_293 )
{
return F_246 ( & V_116 , V_293 ) ;
}
int F_247 ( struct V_292 * V_293 )
{
return F_248 ( & V_116 , V_293 ) ;
}
void F_249 ( struct V_348 * V_186 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
unsigned long V_4 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
V_168 -> V_175 = V_264 ;
V_168 -> V_178 = true ;
F_117 ( V_168 ) ;
F_146 ( V_168 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
}
int F_250 ( struct V_348 * V_186 , int V_362 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
unsigned long V_4 ;
int V_363 , V_29 ;
if ( V_362 <= 0 || V_362 > ( V_147 + 1 ) )
return - V_191 ;
for ( V_363 = 0 ; ( V_362 - 1 ) & ~ 0x1ff ; V_362 >>= 9 )
V_363 += 1 ;
if ( V_363 > V_364 )
return - V_191 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
V_29 = - V_192 ;
if ( V_168 -> V_278 > 0 || V_168 -> V_4 & V_269 )
goto V_297;
V_29 = - V_39 ;
V_168 -> V_257 = ( void * ) F_97 ( V_301 ) ;
if ( V_168 -> V_257 == NULL )
goto V_297;
V_168 -> V_256 = V_363 ;
V_168 -> V_4 |= V_269 ;
V_168 -> V_178 = true ;
F_117 ( V_168 ) ;
V_29 = 0 ;
V_297:
F_6 ( & V_168 -> V_100 , V_4 ) ;
return V_29 ;
}
static int F_251 ( struct V_167 * V_168 , int V_113 ,
T_4 V_88 , bool V_135 )
{
struct V_1 * V_3 ;
struct V_75 V_76 ;
int V_23 , V_29 ;
if ( ! ( V_168 -> V_4 & V_269 ) )
return - V_191 ;
F_75 ( & V_76 , V_168 -> V_169 , V_113 , V_88 , V_135 ) ;
for ( V_23 = 0 ; V_23 < V_170 ; ++ V_23 ) {
if ( V_168 -> V_171 [ V_23 ] == 0 )
continue;
V_29 = F_80 ( V_172 [ V_23 ] , & V_76 ) ;
if ( V_29 != 0 )
goto V_297;
}
F_94 ( V_168 ) ;
F_11 (dev_data, &domain->dev_list, list) {
struct V_42 * V_18 ;
int V_145 ;
F_101 ( ! V_3 -> V_165 . V_166 ) ;
V_145 = V_3 -> V_165 . V_145 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_76 ( & V_76 , V_3 -> V_2 , V_113 ,
V_145 , V_88 , V_135 ) ;
V_29 = F_80 ( V_18 , & V_76 ) ;
if ( V_29 != 0 )
goto V_297;
}
F_94 ( V_168 ) ;
V_29 = 0 ;
V_297:
return V_29 ;
}
static int F_252 ( struct V_167 * V_168 , int V_113 ,
T_4 V_88 )
{
F_49 ( V_70 ) ;
return F_251 ( V_168 , V_113 , V_88 , false ) ;
}
int F_253 ( struct V_348 * V_186 , int V_113 ,
T_4 V_88 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
V_29 = F_252 ( V_168 , V_113 , V_88 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
return V_29 ;
}
static int F_254 ( struct V_167 * V_168 , int V_113 )
{
F_49 ( V_71 ) ;
return F_251 ( V_168 , V_113 , V_140 ,
true ) ;
}
int F_255 ( struct V_348 * V_186 , int V_113 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
V_29 = F_254 ( V_168 , V_113 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
return V_29 ;
}
static T_4 * F_256 ( T_4 * V_365 , int V_181 , int V_113 , bool V_366 )
{
int V_217 ;
T_4 * V_174 ;
while ( true ) {
V_217 = ( V_113 >> ( 9 * V_181 ) ) & 0x1ff ;
V_174 = & V_365 [ V_217 ] ;
if ( V_181 == 0 )
break;
if ( ! ( * V_174 & V_255 ) ) {
if ( ! V_366 )
return NULL ;
V_365 = ( void * ) F_97 ( V_301 ) ;
if ( V_365 == NULL )
return NULL ;
* V_174 = F_68 ( V_365 ) | V_255 ;
}
V_365 = F_148 ( * V_174 & V_141 ) ;
V_181 -= 1 ;
}
return V_174 ;
}
static int F_257 ( struct V_167 * V_168 , int V_113 ,
unsigned long V_367 )
{
T_4 * V_174 ;
if ( V_168 -> V_175 != V_264 )
return - V_191 ;
V_174 = F_256 ( V_168 -> V_257 , V_168 -> V_256 , V_113 , true ) ;
if ( V_174 == NULL )
return - V_39 ;
* V_174 = ( V_367 & V_141 ) | V_255 ;
return F_254 ( V_168 , V_113 ) ;
}
static int F_258 ( struct V_167 * V_168 , int V_113 )
{
T_4 * V_174 ;
if ( V_168 -> V_175 != V_264 )
return - V_191 ;
V_174 = F_256 ( V_168 -> V_257 , V_168 -> V_256 , V_113 , false ) ;
if ( V_174 == NULL )
return 0 ;
* V_174 = 0 ;
return F_254 ( V_168 , V_113 ) ;
}
int F_259 ( struct V_348 * V_186 , int V_113 ,
unsigned long V_367 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
V_29 = F_257 ( V_168 , V_113 , V_367 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
return V_29 ;
}
int F_260 ( struct V_348 * V_186 , int V_113 )
{
struct V_167 * V_168 = V_186 -> V_262 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_168 -> V_100 , V_4 ) ;
V_29 = F_258 ( V_168 , V_113 ) ;
F_6 ( & V_168 -> V_100 , V_4 ) ;
return V_29 ;
}
int F_261 ( struct V_12 * V_13 , int V_113 ,
int V_149 , int V_115 )
{
struct V_1 * V_3 ;
struct V_42 * V_18 ;
struct V_75 V_76 ;
F_49 ( V_69 ) ;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_77 ( & V_76 , V_3 -> V_2 , V_113 , V_149 ,
V_115 , V_3 -> V_289 ) ;
return F_80 ( V_18 , & V_76 ) ;
}
struct V_348 * F_262 ( struct V_12 * V_13 )
{
struct V_167 * V_168 ;
V_168 = F_192 ( & V_13 -> V_11 ) ;
if ( F_209 ( V_168 ) )
return NULL ;
if ( ! ( V_168 -> V_4 & V_269 ) )
return NULL ;
return V_168 -> V_348 ;
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
struct F_265 * V_368 )
{
int V_369 ;
int V_24 ;
if ( V_13 == NULL || V_368 == NULL )
return - V_191 ;
if ( ! F_264 () )
return - V_191 ;
memset ( V_368 , 0 , sizeof( * V_368 ) ) ;
V_24 = F_18 ( V_13 , V_20 ) ;
if ( V_24 )
V_368 -> V_4 |= V_370 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( V_24 )
V_368 -> V_4 |= V_371 ;
V_24 = F_18 ( V_13 , V_22 ) ;
if ( V_24 ) {
int V_372 ;
V_369 = 1 << ( 9 * ( V_364 + 1 ) ) ;
V_369 = F_266 ( V_369 , ( 1 << 20 ) ) ;
V_368 -> V_4 |= V_373 ;
V_368 -> V_369 = F_266 ( F_267 ( V_13 ) , V_369 ) ;
V_372 = F_268 ( V_13 ) ;
if ( V_372 & V_374 )
V_368 -> V_4 |= V_375 ;
if ( V_372 & V_376 )
V_368 -> V_4 |= V_377 ;
}
return 0 ;
}
