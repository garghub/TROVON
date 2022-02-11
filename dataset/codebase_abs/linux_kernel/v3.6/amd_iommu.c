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
static void F_23 ( struct V_12 * * V_39 , struct V_12 * V_40 )
{
F_24 ( * V_39 ) ;
* V_39 = V_40 ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_12 * V_41 = NULL , * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
struct V_42 * V_43 ;
T_1 V_30 ;
int V_29 ;
if ( V_11 -> V_17 . V_18 )
return 0 ;
V_3 = F_12 ( F_13 ( V_11 ) ) ;
if ( ! V_3 )
return - V_44 ;
V_30 = V_31 [ V_3 -> V_2 ] ;
if ( V_30 != V_3 -> V_2 ) {
struct V_1 * V_45 ;
V_45 = F_12 ( V_30 ) ;
if ( V_45 == NULL ) {
F_26 ( L_1 ,
F_27 ( V_11 ) ) ;
F_7 ( V_3 ) ;
return - V_46 ;
}
V_3 -> V_45 = V_45 ;
V_41 = F_28 ( V_30 >> 8 , V_30 & 0xff ) ;
}
if ( V_41 == NULL )
V_41 = F_29 ( V_13 ) ;
F_23 ( & V_41 , F_30 ( V_41 ) ) ;
if ( V_41 -> V_47 &&
! F_31 ( V_41 , V_48 ) )
F_23 ( & V_41 ,
F_32 ( V_41 -> V_14 ,
F_33 ( F_34 ( V_41 -> V_16 ) ,
0 ) ) ) ;
while ( ! F_35 ( V_41 -> V_14 ) ) {
struct V_49 * V_14 = V_41 -> V_14 ;
while ( ! V_14 -> V_50 ) {
if ( ! F_35 ( V_14 ) )
V_14 = V_14 -> V_51 ;
else
goto V_52;
}
if ( F_36 ( V_14 -> V_50 , NULL , V_48 ) )
break;
F_23 ( & V_41 , F_29 ( V_14 -> V_50 ) ) ;
}
V_52:
V_43 = F_37 ( & V_41 -> V_11 ) ;
F_24 ( V_41 ) ;
if ( ! V_43 ) {
V_43 = F_38 () ;
if ( F_39 ( V_43 ) )
return F_40 ( V_43 ) ;
}
V_29 = F_41 ( V_43 , V_11 ) ;
F_42 ( V_43 ) ;
if ( V_29 )
return V_29 ;
if ( F_17 ( V_13 ) ) {
struct V_53 * V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_3 -> V_54 = V_18 -> V_55 ;
}
V_11 -> V_17 . V_18 = V_3 ;
return 0 ;
}
static void F_43 ( struct V_10 * V_11 )
{
T_1 V_2 , V_30 ;
V_2 = F_13 ( V_11 ) ;
V_30 = V_31 [ V_2 ] ;
memset ( & V_56 [ V_2 ] , 0 , sizeof( struct V_57 ) ) ;
memset ( & V_56 [ V_30 ] , 0 , sizeof( struct V_57 ) ) ;
V_38 [ V_2 ] = NULL ;
V_38 [ V_30 ] = NULL ;
}
static void F_44 ( struct V_10 * V_11 )
{
F_45 ( V_11 ) ;
}
void T_3 F_46 ( void )
{
struct V_1 * V_3 , * V_58 ;
struct V_12 * V_13 = NULL ;
F_47 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) )
continue;
F_44 ( & V_13 -> V_11 ) ;
}
F_48 (dev_data, n, &dev_data_list, dev_data_list)
F_7 ( V_3 ) ;
}
int T_3 F_49 ( void )
{
struct V_12 * V_13 = NULL ;
int V_29 = 0 ;
F_47 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) )
continue;
V_29 = F_25 ( & V_13 -> V_11 ) ;
if ( V_29 == - V_46 )
F_43 ( & V_13 -> V_11 ) ;
else if ( V_29 )
goto V_59;
}
return 0 ;
V_59:
F_46 () ;
return V_29 ;
}
static void F_50 ( struct V_60 * V_61 )
{
if ( V_62 == NULL )
return;
V_61 -> V_63 = F_51 ( V_61 -> V_64 , 0444 , V_62 ,
& V_61 -> V_65 ) ;
}
static void F_52 ( void )
{
V_62 = F_53 ( L_2 , NULL ) ;
if ( V_62 == NULL )
return;
V_66 = F_54 ( L_3 , 0444 , V_62 ,
& V_67 ) ;
F_50 ( & V_68 ) ;
F_50 ( & V_69 ) ;
F_50 ( & V_70 ) ;
F_50 ( & V_71 ) ;
F_50 ( & V_72 ) ;
F_50 ( & V_73 ) ;
F_50 ( & V_74 ) ;
F_50 ( & V_75 ) ;
F_50 ( & V_76 ) ;
F_50 ( & V_77 ) ;
F_50 ( & V_78 ) ;
F_50 ( & V_79 ) ;
F_50 ( & V_80 ) ;
F_50 ( & V_81 ) ;
F_50 ( & V_82 ) ;
F_50 ( & V_83 ) ;
}
static void F_55 ( T_1 V_2 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 )
F_26 ( L_4 , V_23 ,
V_56 [ V_2 ] . V_84 [ V_23 ] ) ;
}
static void F_56 ( unsigned long V_85 )
{
struct V_86 * V_87 = F_57 ( V_85 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 )
F_26 ( L_5 , V_23 , V_87 -> V_84 [ V_23 ] ) ;
}
static void F_58 ( struct V_53 * V_18 , void * V_88 )
{
int type , V_2 , V_89 , V_4 ;
volatile T_2 * V_90 = V_88 ;
int V_91 = 0 ;
T_4 V_92 ;
V_93:
type = ( V_90 [ 1 ] >> V_94 ) & V_95 ;
V_2 = ( V_90 [ 0 ] >> V_96 ) & V_97 ;
V_89 = ( V_90 [ 1 ] >> V_98 ) & V_99 ;
V_4 = ( V_90 [ 1 ] >> V_100 ) & V_101 ;
V_92 = ( T_4 ) ( ( ( T_4 ) V_90 [ 3 ] ) << 32 ) | V_90 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_91 == V_102 ) {
F_26 ( L_6 ) ;
return;
}
F_59 ( 1 ) ;
goto V_93;
}
F_60 ( V_103 L_7 ) ;
switch ( type ) {
case V_104 :
F_60 ( L_8
L_9 ,
F_61 ( V_2 ) , F_34 ( V_2 ) , F_62 ( V_2 ) ,
V_92 , V_4 ) ;
F_55 ( V_2 ) ;
break;
case V_105 :
F_60 ( L_10
L_11 ,
F_61 ( V_2 ) , F_34 ( V_2 ) , F_62 ( V_2 ) ,
V_89 , V_92 , V_4 ) ;
break;
case V_106 :
F_60 ( L_12
L_9 ,
F_61 ( V_2 ) , F_34 ( V_2 ) , F_62 ( V_2 ) ,
V_92 , V_4 ) ;
break;
case V_107 :
F_60 ( L_13
L_11 ,
F_61 ( V_2 ) , F_34 ( V_2 ) , F_62 ( V_2 ) ,
V_89 , V_92 , V_4 ) ;
break;
case V_108 :
F_60 ( L_14 , V_92 ) ;
F_56 ( V_92 ) ;
break;
case V_109 :
F_60 ( L_15
L_16 , V_92 , V_4 ) ;
break;
case V_110 :
F_60 ( L_17
L_18 ,
F_61 ( V_2 ) , F_34 ( V_2 ) , F_62 ( V_2 ) ,
V_92 ) ;
break;
case V_111 :
F_60 ( L_19
L_9 ,
F_61 ( V_2 ) , F_34 ( V_2 ) , F_62 ( V_2 ) ,
V_92 , V_4 ) ;
break;
default:
F_60 ( V_103 L_20 , type ) ;
}
memset ( V_88 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_63 ( struct V_53 * V_18 )
{
T_2 V_112 , V_113 ;
unsigned long V_4 ;
F_4 ( & V_18 -> V_114 , V_4 ) ;
V_112 = F_64 ( V_18 -> V_115 + V_116 ) ;
V_113 = F_64 ( V_18 -> V_115 + V_117 ) ;
while ( V_112 != V_113 ) {
F_58 ( V_18 , V_18 -> V_118 + V_112 ) ;
V_112 = ( V_112 + V_119 ) % V_18 -> V_120 ;
}
F_65 ( V_112 , V_18 -> V_115 + V_116 ) ;
F_6 ( & V_18 -> V_114 , V_4 ) ;
}
static void F_66 ( struct V_53 * V_18 , T_4 * V_121 )
{
struct V_122 V_123 ;
F_67 ( V_83 ) ;
if ( F_68 ( V_121 [ 0 ] ) != V_124 ) {
F_69 ( L_21 ) ;
return;
}
V_123 . V_92 = V_121 [ 1 ] ;
V_123 . V_125 = F_70 ( V_121 [ 0 ] ) ;
V_123 . V_126 = F_71 ( V_121 [ 0 ] ) ;
V_123 . V_127 = F_72 ( V_121 [ 0 ] ) ;
V_123 . V_4 = F_73 ( V_121 [ 0 ] ) ;
F_74 ( & V_128 , 0 , & V_123 ) ;
}
static void F_75 ( struct V_53 * V_18 )
{
unsigned long V_4 ;
T_2 V_112 , V_113 ;
if ( V_18 -> V_129 == NULL )
return;
F_65 ( V_130 , V_18 -> V_115 + V_131 ) ;
F_4 ( & V_18 -> V_114 , V_4 ) ;
V_112 = F_64 ( V_18 -> V_115 + V_132 ) ;
V_113 = F_64 ( V_18 -> V_115 + V_133 ) ;
while ( V_112 != V_113 ) {
volatile T_4 * V_121 ;
T_4 V_28 [ 2 ] ;
int V_23 ;
V_121 = ( T_4 * ) ( V_18 -> V_129 + V_112 ) ;
for ( V_23 = 0 ; V_23 < V_102 ; ++ V_23 ) {
if ( F_68 ( V_121 [ 0 ] ) != 0 )
break;
F_59 ( 1 ) ;
}
V_28 [ 0 ] = V_121 [ 0 ] ;
V_28 [ 1 ] = V_121 [ 1 ] ;
V_121 [ 0 ] = V_121 [ 1 ] = 0UL ;
V_112 = ( V_112 + V_134 ) % V_135 ;
F_65 ( V_112 , V_18 -> V_115 + V_132 ) ;
F_6 ( & V_18 -> V_114 , V_4 ) ;
F_66 ( V_18 , V_28 ) ;
F_4 ( & V_18 -> V_114 , V_4 ) ;
V_112 = F_64 ( V_18 -> V_115 + V_132 ) ;
V_113 = F_64 ( V_18 -> V_115 + V_133 ) ;
}
F_6 ( & V_18 -> V_114 , V_4 ) ;
}
T_5 F_76 ( int V_136 , void * V_84 )
{
struct V_53 * V_18 ;
F_77 (iommu) {
F_63 ( V_18 ) ;
F_75 ( V_18 ) ;
}
return V_137 ;
}
T_5 F_78 ( int V_136 , void * V_84 )
{
return V_138 ;
}
static int F_79 ( volatile T_4 * V_139 )
{
int V_23 = 0 ;
while ( * V_139 == 0 && V_23 < V_102 ) {
F_59 ( 1 ) ;
V_23 += 1 ;
}
if ( V_23 == V_102 ) {
F_80 ( L_22 ) ;
return - V_140 ;
}
return 0 ;
}
static void F_81 ( struct V_53 * V_18 ,
struct V_86 * V_87 ,
T_2 V_113 )
{
T_6 * V_141 ;
V_141 = V_18 -> V_142 + V_113 ;
V_113 = ( V_113 + sizeof( * V_87 ) ) % V_18 -> V_143 ;
memcpy ( V_141 , V_87 , sizeof( * V_87 ) ) ;
F_65 ( V_113 , V_18 -> V_115 + V_144 ) ;
}
static void F_82 ( struct V_86 * V_87 , T_4 V_92 )
{
F_83 ( V_92 & 0x7ULL ) ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = F_84 ( F_85 ( V_92 ) ) | V_145 ;
V_87 -> V_84 [ 1 ] = F_86 ( F_85 ( V_92 ) ) ;
V_87 -> V_84 [ 2 ] = 1 ;
F_87 ( V_87 , V_146 ) ;
}
static void F_88 ( struct V_86 * V_87 , T_1 V_2 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
F_87 ( V_87 , V_147 ) ;
}
static void F_89 ( struct V_86 * V_87 , T_4 V_92 ,
T_7 V_148 , T_1 V_89 , int V_149 )
{
T_4 V_150 ;
int V_151 ;
V_150 = F_90 ( V_92 , V_148 , V_152 ) ;
V_151 = 0 ;
if ( V_150 > 1 ) {
V_92 = V_153 ;
V_151 = 1 ;
}
V_92 &= V_154 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 1 ] |= V_89 ;
V_87 -> V_84 [ 2 ] = F_84 ( V_92 ) ;
V_87 -> V_84 [ 3 ] = F_86 ( V_92 ) ;
F_87 ( V_87 , V_155 ) ;
if ( V_151 )
V_87 -> V_84 [ 2 ] |= V_156 ;
if ( V_149 )
V_87 -> V_84 [ 2 ] |= V_157 ;
}
static void F_91 ( struct V_86 * V_87 , T_1 V_2 , int V_158 ,
T_4 V_92 , T_7 V_148 )
{
T_4 V_150 ;
int V_151 ;
V_150 = F_90 ( V_92 , V_148 , V_152 ) ;
V_151 = 0 ;
if ( V_150 > 1 ) {
V_92 = V_153 ;
V_151 = 1 ;
}
V_92 &= V_154 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
V_87 -> V_84 [ 0 ] |= ( V_158 & 0xff ) << 24 ;
V_87 -> V_84 [ 1 ] = V_2 ;
V_87 -> V_84 [ 2 ] = F_84 ( V_92 ) ;
V_87 -> V_84 [ 3 ] = F_86 ( V_92 ) ;
F_87 ( V_87 , V_159 ) ;
if ( V_151 )
V_87 -> V_84 [ 2 ] |= V_156 ;
}
static void F_92 ( struct V_86 * V_87 , T_1 V_89 , int V_125 ,
T_4 V_92 , bool V_148 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_92 &= ~ ( 0xfffULL ) ;
V_87 -> V_84 [ 0 ] = V_125 & V_160 ;
V_87 -> V_84 [ 1 ] = V_89 ;
V_87 -> V_84 [ 2 ] = F_84 ( V_92 ) ;
V_87 -> V_84 [ 3 ] = F_86 ( V_92 ) ;
V_87 -> V_84 [ 2 ] |= V_157 ;
V_87 -> V_84 [ 2 ] |= V_161 ;
if ( V_148 )
V_87 -> V_84 [ 2 ] |= V_156 ;
F_87 ( V_87 , V_155 ) ;
}
static void F_93 ( struct V_86 * V_87 , T_1 V_2 , int V_125 ,
int V_158 , T_4 V_92 , bool V_148 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_92 &= ~ ( 0xfffULL ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
V_87 -> V_84 [ 0 ] |= ( V_125 & 0xff ) << 16 ;
V_87 -> V_84 [ 0 ] |= ( V_158 & 0xff ) << 24 ;
V_87 -> V_84 [ 1 ] = V_2 ;
V_87 -> V_84 [ 1 ] |= ( ( V_125 >> 8 ) & 0xfff ) << 16 ;
V_87 -> V_84 [ 2 ] = F_84 ( V_92 ) ;
V_87 -> V_84 [ 2 ] |= V_161 ;
V_87 -> V_84 [ 3 ] = F_86 ( V_92 ) ;
if ( V_148 )
V_87 -> V_84 [ 2 ] |= V_156 ;
F_87 ( V_87 , V_159 ) ;
}
static void F_94 ( struct V_86 * V_87 , T_1 V_2 , int V_125 ,
int V_162 , int V_127 , bool V_163 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
if ( V_163 ) {
V_87 -> V_84 [ 1 ] = V_125 & V_160 ;
V_87 -> V_84 [ 2 ] = V_161 ;
}
V_87 -> V_84 [ 3 ] = V_127 & 0x1ff ;
V_87 -> V_84 [ 3 ] |= ( V_162 & V_164 ) << V_165 ;
F_87 ( V_87 , V_166 ) ;
}
static void F_95 ( struct V_86 * V_87 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
F_87 ( V_87 , V_167 ) ;
}
static int F_96 ( struct V_53 * V_18 ,
struct V_86 * V_87 ,
bool V_168 )
{
T_2 V_169 , V_113 , V_112 , V_170 ;
unsigned long V_4 ;
F_83 ( V_18 -> V_143 & V_171 ) ;
V_172:
F_4 ( & V_18 -> V_114 , V_4 ) ;
V_112 = F_64 ( V_18 -> V_115 + V_173 ) ;
V_113 = F_64 ( V_18 -> V_115 + V_144 ) ;
V_170 = ( V_113 + sizeof( * V_87 ) ) % V_18 -> V_143 ;
V_169 = ( V_112 - V_170 ) % V_18 -> V_143 ;
if ( V_169 <= 2 ) {
struct V_86 V_174 ;
volatile T_4 V_139 = 0 ;
int V_29 ;
F_82 ( & V_174 , ( T_4 ) & V_139 ) ;
F_81 ( V_18 , & V_174 , V_113 ) ;
F_6 ( & V_18 -> V_114 , V_4 ) ;
if ( ( V_29 = F_79 ( & V_139 ) ) != 0 )
return V_29 ;
goto V_172;
}
F_81 ( V_18 , V_87 , V_113 ) ;
V_18 -> V_175 = V_168 ;
F_6 ( & V_18 -> V_114 , V_4 ) ;
return 0 ;
}
static int F_97 ( struct V_53 * V_18 , struct V_86 * V_87 )
{
return F_96 ( V_18 , V_87 , true ) ;
}
static int F_98 ( struct V_53 * V_18 )
{
struct V_86 V_87 ;
volatile T_4 V_139 = 0 ;
int V_29 ;
if ( ! V_18 -> V_175 )
return 0 ;
F_82 ( & V_87 , ( T_4 ) & V_139 ) ;
V_29 = F_96 ( V_18 , & V_87 , false ) ;
if ( V_29 )
return V_29 ;
return F_79 ( & V_139 ) ;
}
static int F_99 ( struct V_53 * V_18 , T_1 V_2 )
{
struct V_86 V_87 ;
F_88 ( & V_87 , V_2 ) ;
return F_97 ( V_18 , & V_87 ) ;
}
static void F_100 ( struct V_53 * V_18 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= 0xffff ; ++ V_2 )
F_99 ( V_18 , V_2 ) ;
F_98 ( V_18 ) ;
}
static void F_101 ( struct V_53 * V_18 )
{
T_2 V_176 ;
for ( V_176 = 0 ; V_176 <= 0xffff ; ++ V_176 ) {
struct V_86 V_87 ;
F_89 ( & V_87 , 0 , V_153 ,
V_176 , 1 ) ;
F_97 ( V_18 , & V_87 ) ;
}
F_98 ( V_18 ) ;
}
static void F_102 ( struct V_53 * V_18 )
{
struct V_86 V_87 ;
F_95 ( & V_87 ) ;
F_97 ( V_18 , & V_87 ) ;
F_98 ( V_18 ) ;
}
void F_103 ( struct V_53 * V_18 )
{
if ( F_104 ( V_18 , V_177 ) ) {
F_102 ( V_18 ) ;
} else {
F_100 ( V_18 ) ;
F_101 ( V_18 ) ;
}
}
static int F_105 ( struct V_1 * V_3 ,
T_4 V_92 , T_7 V_148 )
{
struct V_53 * V_18 ;
struct V_86 V_87 ;
int V_158 ;
V_158 = V_3 -> V_178 . V_158 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_91 ( & V_87 , V_3 -> V_2 , V_158 , V_92 , V_148 ) ;
return F_97 ( V_18 , & V_87 ) ;
}
static int F_106 ( struct V_1 * V_3 )
{
struct V_53 * V_18 ;
int V_29 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_29 = F_99 ( V_18 , V_3 -> V_2 ) ;
if ( V_29 )
return V_29 ;
if ( V_3 -> V_178 . V_179 )
V_29 = F_105 ( V_3 , 0 , ~ 0UL ) ;
return V_29 ;
}
static void F_107 ( struct V_180 * V_181 ,
T_4 V_92 , T_7 V_148 , int V_149 )
{
struct V_1 * V_3 ;
struct V_86 V_87 ;
int V_29 = 0 , V_23 ;
F_89 ( & V_87 , V_92 , V_148 , V_181 -> V_182 , V_149 ) ;
for ( V_23 = 0 ; V_23 < V_183 ; ++ V_23 ) {
if ( ! V_181 -> V_184 [ V_23 ] )
continue;
V_29 |= F_97 ( V_185 [ V_23 ] , & V_87 ) ;
}
F_11 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_178 . V_179 )
continue;
V_29 |= F_105 ( V_3 , V_92 , V_148 ) ;
}
F_83 ( V_29 ) ;
}
static void F_108 ( struct V_180 * V_181 ,
T_4 V_92 , T_7 V_148 )
{
F_107 ( V_181 , V_92 , V_148 , 0 ) ;
}
static void F_109 ( struct V_180 * V_181 )
{
F_107 ( V_181 , 0 , V_153 , 0 ) ;
}
static void F_110 ( struct V_180 * V_181 )
{
F_107 ( V_181 , 0 , V_153 , 1 ) ;
}
static void F_111 ( struct V_180 * V_181 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_183 ; ++ V_23 ) {
if ( ! V_181 -> V_184 [ V_23 ] )
continue;
F_98 ( V_185 [ V_23 ] ) ;
}
}
static void F_112 ( struct V_180 * V_181 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_106 ( V_3 ) ;
}
static bool F_113 ( struct V_180 * V_181 ,
T_8 V_186 )
{
T_4 * V_187 ;
if ( V_181 -> V_188 == V_189 )
return false ;
V_187 = ( void * ) F_114 ( V_186 ) ;
if ( ! V_187 )
return false ;
* V_187 = F_115 ( V_181 -> V_188 ,
F_116 ( V_181 -> V_190 ) ) ;
V_181 -> V_190 = V_187 ;
V_181 -> V_188 += 1 ;
V_181 -> V_191 = true ;
return true ;
}
static T_4 * F_117 ( struct V_180 * V_181 ,
unsigned long V_92 ,
unsigned long V_192 ,
T_4 * * V_193 ,
T_8 V_186 )
{
int V_194 , V_195 ;
T_4 * V_187 , * V_196 ;
F_118 ( ! F_119 ( V_192 ) ) ;
while ( V_92 > F_120 ( V_181 -> V_188 ) )
F_113 ( V_181 , V_186 ) ;
V_194 = V_181 -> V_188 - 1 ;
V_187 = & V_181 -> V_190 [ F_121 ( V_194 , V_92 ) ] ;
V_92 = F_122 ( V_92 , V_192 ) ;
V_195 = F_123 ( V_192 ) ;
while ( V_194 > V_195 ) {
if ( ! F_124 ( * V_187 ) ) {
V_196 = ( T_4 * ) F_114 ( V_186 ) ;
if ( ! V_196 )
return NULL ;
* V_187 = F_115 ( V_194 , F_116 ( V_196 ) ) ;
}
if ( F_125 ( * V_187 ) != V_194 )
return NULL ;
V_194 -= 1 ;
V_187 = F_126 ( * V_187 ) ;
if ( V_193 && V_194 == V_195 )
* V_193 = V_187 ;
V_187 = & V_187 [ F_121 ( V_194 , V_92 ) ] ;
}
return V_187 ;
}
static T_4 * F_127 ( struct V_180 * V_181 , unsigned long V_92 )
{
int V_194 ;
T_4 * V_187 ;
if ( V_92 > F_120 ( V_181 -> V_188 ) )
return NULL ;
V_194 = V_181 -> V_188 - 1 ;
V_187 = & V_181 -> V_190 [ F_121 ( V_194 , V_92 ) ] ;
while ( V_194 > 0 ) {
if ( ! F_124 ( * V_187 ) )
return NULL ;
if ( F_125 ( * V_187 ) == 0x07 ) {
unsigned long V_197 , V_198 ;
V_197 = F_128 ( * V_187 ) ;
V_197 = ~ ( ( F_129 ( V_197 ) << 3 ) - 1 ) ;
V_198 = ( ( unsigned long ) V_187 ) & V_197 ;
return ( T_4 * ) V_198 ;
}
if ( F_125 ( * V_187 ) != V_194 )
return NULL ;
V_194 -= 1 ;
V_187 = F_126 ( * V_187 ) ;
V_187 = & V_187 [ F_121 ( V_194 , V_92 ) ] ;
}
return V_187 ;
}
static int F_130 ( struct V_180 * V_199 ,
unsigned long V_200 ,
unsigned long V_85 ,
int V_201 ,
unsigned long V_192 )
{
T_4 V_198 , * V_187 ;
int V_23 , V_91 ;
if ( ! ( V_201 & V_202 ) )
return - V_203 ;
V_200 = F_131 ( V_200 ) ;
V_85 = F_131 ( V_85 ) ;
V_91 = F_129 ( V_192 ) ;
V_187 = F_117 ( V_199 , V_200 , V_192 , NULL , V_5 ) ;
for ( V_23 = 0 ; V_23 < V_91 ; ++ V_23 )
if ( F_124 ( V_187 [ V_23 ] ) )
return - V_204 ;
if ( V_192 > V_152 ) {
V_198 = F_132 ( V_85 , V_192 ) ;
V_198 |= F_133 ( 7 ) | V_205 | V_206 ;
} else
V_198 = V_85 | V_205 | V_206 ;
if ( V_201 & V_207 )
V_198 |= V_208 ;
if ( V_201 & V_209 )
V_198 |= V_210 ;
for ( V_23 = 0 ; V_23 < V_91 ; ++ V_23 )
V_187 [ V_23 ] = V_198 ;
F_134 ( V_199 ) ;
return 0 ;
}
static unsigned long F_135 ( struct V_180 * V_199 ,
unsigned long V_200 ,
unsigned long V_192 )
{
unsigned long long V_211 , V_212 ;
T_4 * V_187 ;
F_118 ( ! F_119 ( V_192 ) ) ;
V_212 = 0 ;
while ( V_212 < V_192 ) {
V_187 = F_127 ( V_199 , V_200 ) ;
if ( ! V_187 ) {
V_211 = V_152 ;
} else if ( F_125 ( * V_187 ) == 0 ) {
V_211 = V_152 ;
* V_187 = 0ULL ;
} else {
int V_91 , V_23 ;
V_211 = F_128 ( * V_187 ) ;
V_91 = F_129 ( V_211 ) ;
for ( V_23 = 0 ; V_23 < V_91 ; V_23 ++ )
V_187 [ V_23 ] = 0ULL ;
}
V_200 = ( V_200 & ~ ( V_211 - 1 ) ) + V_211 ;
V_212 += V_211 ;
}
F_118 ( ! F_119 ( V_212 ) ) ;
return V_212 ;
}
static int F_136 ( struct V_53 * V_18 ,
struct V_213 * V_28 )
{
T_1 V_214 , V_23 ;
for ( V_23 = V_28 -> V_215 ; V_23 <= V_28 -> V_216 ; ++ V_23 ) {
V_214 = V_31 [ V_23 ] ;
if ( V_38 [ V_214 ] == V_18 )
return 1 ;
}
return 0 ;
}
static int F_137 ( struct V_27 * V_217 ,
struct V_213 * V_218 )
{
T_4 V_219 ;
int V_29 ;
for ( V_219 = V_218 -> V_220 ; V_219 < V_218 -> V_221 ;
V_219 += V_152 ) {
V_29 = F_130 ( & V_217 -> V_181 , V_219 , V_219 , V_218 -> V_201 ,
V_152 ) ;
if ( V_29 )
return V_29 ;
if ( V_219 < V_217 -> V_222 )
F_138 ( V_219 >> V_223 ,
V_217 -> V_224 [ 0 ] -> V_225 ) ;
}
return 0 ;
}
static int F_139 ( struct V_53 * V_18 )
{
struct V_213 * V_28 ;
int V_29 ;
F_11 (entry, &amd_iommu_unity_map, list) {
if ( ! F_136 ( V_18 , V_28 ) )
continue;
V_29 = F_137 ( V_18 -> V_226 , V_28 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_140 ( struct V_27 * V_217 ,
T_1 V_2 )
{
struct V_213 * V_218 ;
int V_29 ;
F_11 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_218 -> V_215 && V_2 <= V_218 -> V_216 ) )
continue;
V_29 = F_137 ( V_217 , V_218 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static void F_141 ( struct V_27 * V_199 ,
unsigned long V_227 ,
unsigned int V_150 )
{
unsigned int V_23 , V_228 = V_199 -> V_222 >> V_223 ;
if ( V_227 + V_150 > V_228 )
V_150 = V_228 - V_227 ;
for ( V_23 = V_227 ; V_23 < V_227 + V_150 ; ++ V_23 ) {
int V_229 = V_23 / V_230 ;
int V_196 = V_23 % V_230 ;
F_138 ( V_196 , V_199 -> V_224 [ V_229 ] -> V_225 ) ;
}
}
static int F_142 ( struct V_27 * V_217 ,
bool V_231 , T_8 V_186 )
{
int V_229 = V_217 -> V_222 >> V_232 ;
struct V_53 * V_18 ;
unsigned long V_23 , V_233 ;
#ifdef F_143
V_231 = false ;
#endif
if ( V_229 >= V_234 )
return - V_44 ;
V_217 -> V_224 [ V_229 ] = F_2 ( sizeof( struct V_235 ) , V_186 ) ;
if ( ! V_217 -> V_224 [ V_229 ] )
return - V_44 ;
V_217 -> V_224 [ V_229 ] -> V_225 = ( void * ) F_114 ( V_186 ) ;
if ( ! V_217 -> V_224 [ V_229 ] -> V_225 )
goto V_59;
V_217 -> V_224 [ V_229 ] -> V_236 = V_217 -> V_222 ;
if ( V_231 ) {
unsigned long V_92 = V_217 -> V_222 ;
int V_23 , V_237 = V_230 / 512 ;
T_4 * V_187 , * V_193 ;
for ( V_23 = 0 ; V_23 < V_237 ; ++ V_23 ) {
V_187 = F_117 ( & V_217 -> V_181 , V_92 , V_152 ,
& V_193 , V_186 ) ;
if ( ! V_187 )
goto V_59;
V_217 -> V_224 [ V_229 ] -> V_238 [ V_23 ] = V_193 ;
V_92 += V_239 / 64 ;
}
}
V_233 = V_217 -> V_222 ;
V_217 -> V_222 += V_239 ;
if ( V_233 < V_240 &&
V_217 -> V_222 > V_240 ) {
unsigned long V_241 ;
int V_150 ;
V_150 = F_90 ( V_240 , 0x10000 , V_152 ) ;
V_241 = V_240 >> V_223 ;
F_141 ( V_217 , V_241 , V_150 ) ;
}
F_77 (iommu) {
if ( V_18 -> V_242 &&
V_18 -> V_242 >= V_217 -> V_224 [ V_229 ] -> V_236
&& V_18 -> V_242 < V_217 -> V_222 ) {
unsigned long V_243 ;
int V_150 = F_90 ( V_18 -> V_242 ,
V_18 -> V_244 ,
V_152 ) ;
V_243 = V_18 -> V_242 >> V_223 ;
F_141 ( V_217 , V_243 , V_150 ) ;
}
}
for ( V_23 = V_217 -> V_224 [ V_229 ] -> V_236 ;
V_23 < V_217 -> V_222 ;
V_23 += V_152 ) {
T_4 * V_187 = F_127 ( & V_217 -> V_181 , V_23 ) ;
if ( ! V_187 || ! F_124 ( * V_187 ) )
continue;
F_141 ( V_217 , V_23 >> V_223 , 1 ) ;
}
F_134 ( & V_217 -> V_181 ) ;
return 0 ;
V_59:
F_134 ( & V_217 -> V_181 ) ;
F_144 ( ( unsigned long ) V_217 -> V_224 [ V_229 ] -> V_225 ) ;
F_9 ( V_217 -> V_224 [ V_229 ] ) ;
V_217 -> V_224 [ V_229 ] = NULL ;
return - V_44 ;
}
static unsigned long F_145 ( struct V_10 * V_11 ,
struct V_27 * V_199 ,
unsigned int V_150 ,
unsigned long V_245 ,
T_4 V_35 ,
unsigned long V_246 )
{
unsigned long V_247 = V_199 -> V_248 % V_239 ;
int V_249 = V_199 -> V_222 >> V_232 ;
int V_23 = V_246 >> V_232 ;
unsigned long V_250 ;
unsigned long V_92 = - 1 ;
unsigned long V_251 ;
V_247 >>= V_223 ;
V_250 = F_146 ( F_147 ( V_11 ) + 1 ,
V_152 ) >> V_223 ;
for (; V_23 < V_249 ; ++ V_23 ) {
unsigned long V_236 = V_199 -> V_224 [ V_23 ] -> V_236 >> V_223 ;
if ( V_199 -> V_224 [ V_23 ] -> V_236 >= V_35 )
break;
V_251 = F_148 ( V_230 , V_236 ,
V_35 >> V_223 ) ;
V_92 = F_149 ( V_199 -> V_224 [ V_23 ] -> V_225 ,
V_251 , V_247 , V_150 , 0 ,
V_250 , V_245 ) ;
if ( V_92 != - 1 ) {
V_92 = V_199 -> V_224 [ V_23 ] -> V_236 +
( V_92 << V_223 ) ;
V_199 -> V_248 = V_92 + ( V_150 << V_223 ) ;
break;
}
V_247 = 0 ;
}
return V_92 ;
}
static unsigned long F_150 ( struct V_10 * V_11 ,
struct V_27 * V_199 ,
unsigned int V_150 ,
unsigned long V_245 ,
T_4 V_35 )
{
unsigned long V_92 ;
#ifdef F_143
V_199 -> V_248 = 0 ;
V_199 -> V_252 = true ;
#endif
V_92 = F_145 ( V_11 , V_199 , V_150 , V_245 ,
V_35 , V_199 -> V_248 ) ;
if ( V_92 == - 1 ) {
V_199 -> V_248 = 0 ;
V_92 = F_145 ( V_11 , V_199 , V_150 , V_245 ,
V_35 , 0 ) ;
V_199 -> V_252 = true ;
}
if ( F_151 ( V_92 == - 1 ) )
V_92 = V_253 ;
F_83 ( ( V_92 + ( V_152 * V_150 ) ) > V_199 -> V_222 ) ;
return V_92 ;
}
static void F_152 ( struct V_27 * V_199 ,
unsigned long V_92 ,
unsigned int V_150 )
{
unsigned V_23 = V_92 >> V_232 ;
struct V_235 * V_254 = V_199 -> V_224 [ V_23 ] ;
F_118 ( V_23 >= V_234 || V_254 == NULL ) ;
#ifdef F_143
if ( V_23 < 4 )
return;
#endif
if ( V_92 >= V_199 -> V_248 )
V_199 -> V_252 = true ;
V_92 = ( V_92 % V_239 ) >> V_223 ;
F_153 ( V_254 -> V_225 , V_92 , V_150 ) ;
}
static void F_154 ( struct V_180 * V_181 )
{
unsigned long V_4 ;
F_4 ( & V_255 , V_4 ) ;
F_155 ( & V_181 -> V_256 , & V_257 ) ;
F_6 ( & V_255 , V_4 ) ;
}
static void F_156 ( struct V_180 * V_181 )
{
unsigned long V_4 ;
F_4 ( & V_255 , V_4 ) ;
F_8 ( & V_181 -> V_256 ) ;
F_6 ( & V_255 , V_4 ) ;
}
static T_1 F_157 ( void )
{
unsigned long V_4 ;
int V_182 ;
F_158 ( & V_258 , V_4 ) ;
V_182 = F_159 ( V_259 , V_260 ) ;
F_118 ( V_182 == 0 ) ;
if ( V_182 > 0 && V_182 < V_260 )
F_138 ( V_182 , V_259 ) ;
else
V_182 = 0 ;
F_160 ( & V_258 , V_4 ) ;
return V_182 ;
}
static void F_161 ( int V_182 )
{
unsigned long V_4 ;
F_158 ( & V_258 , V_4 ) ;
if ( V_182 > 0 && V_182 < V_260 )
F_162 ( V_182 , V_259 ) ;
F_160 ( & V_258 , V_4 ) ;
}
static void F_163 ( struct V_180 * V_181 )
{
int V_23 , V_261 ;
T_4 * V_262 , * V_263 , * V_264 ;
V_262 = V_181 -> V_190 ;
if ( ! V_262 )
return;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! F_124 ( V_262 [ V_23 ] ) )
continue;
V_263 = F_126 ( V_262 [ V_23 ] ) ;
for ( V_261 = 0 ; V_261 < 512 ; ++ V_261 ) {
if ( ! F_124 ( V_263 [ V_261 ] ) )
continue;
V_264 = F_126 ( V_263 [ V_261 ] ) ;
F_144 ( ( unsigned long ) V_264 ) ;
}
F_144 ( ( unsigned long ) V_263 ) ;
}
F_144 ( ( unsigned long ) V_262 ) ;
V_181 -> V_190 = NULL ;
}
static void F_164 ( T_4 * V_265 )
{
T_4 * V_266 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_265 [ V_23 ] & V_267 ) )
continue;
V_266 = F_165 ( V_265 [ V_23 ] & V_154 ) ;
F_144 ( ( unsigned long ) V_266 ) ;
}
}
static void F_166 ( T_4 * V_265 )
{
T_4 * V_266 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_265 [ V_23 ] & V_267 ) )
continue;
V_266 = F_165 ( V_265 [ V_23 ] & V_154 ) ;
F_164 ( V_266 ) ;
}
}
static void F_167 ( struct V_180 * V_181 )
{
if ( V_181 -> V_268 == 2 )
F_166 ( V_181 -> V_269 ) ;
else if ( V_181 -> V_268 == 1 )
F_164 ( V_181 -> V_269 ) ;
else if ( V_181 -> V_268 != 0 )
F_168 () ;
F_144 ( ( unsigned long ) V_181 -> V_269 ) ;
}
static void F_169 ( struct V_27 * V_199 )
{
int V_23 ;
if ( ! V_199 )
return;
F_156 ( & V_199 -> V_181 ) ;
F_163 ( & V_199 -> V_181 ) ;
for ( V_23 = 0 ; V_23 < V_234 ; ++ V_23 ) {
if ( ! V_199 -> V_224 [ V_23 ] )
continue;
F_144 ( ( unsigned long ) V_199 -> V_224 [ V_23 ] -> V_225 ) ;
F_9 ( V_199 -> V_224 [ V_23 ] ) ;
}
F_9 ( V_199 ) ;
}
static struct V_27 * F_170 ( void )
{
struct V_27 * V_217 ;
V_217 = F_2 ( sizeof( struct V_27 ) , V_5 ) ;
if ( ! V_217 )
return NULL ;
F_171 ( & V_217 -> V_181 . V_114 ) ;
V_217 -> V_181 . V_182 = F_157 () ;
if ( V_217 -> V_181 . V_182 == 0 )
goto V_270;
F_172 ( & V_217 -> V_181 . V_271 ) ;
V_217 -> V_181 . V_188 = V_272 ;
V_217 -> V_181 . V_190 = ( void * ) F_114 ( V_5 ) ;
V_217 -> V_181 . V_4 = V_273 ;
V_217 -> V_181 . V_274 = V_217 ;
if ( ! V_217 -> V_181 . V_190 )
goto V_270;
V_217 -> V_252 = false ;
V_217 -> V_34 = 0xffff ;
F_154 ( & V_217 -> V_181 ) ;
if ( F_142 ( V_217 , true , V_5 ) )
goto V_270;
V_217 -> V_224 [ 0 ] -> V_225 [ 0 ] = 1 ;
V_217 -> V_248 = 0 ;
return V_217 ;
V_270:
F_169 ( V_217 ) ;
return NULL ;
}
static bool V_27 ( struct V_180 * V_181 )
{
return V_181 -> V_4 & V_273 ;
}
static void F_173 ( T_1 V_2 , struct V_180 * V_181 , bool V_178 )
{
T_4 V_275 = 0 ;
T_4 V_4 = 0 ;
if ( V_181 -> V_188 != V_276 )
V_275 = F_116 ( V_181 -> V_190 ) ;
V_275 |= ( V_181 -> V_188 & V_277 )
<< V_278 ;
V_275 |= V_208 | V_210 | V_205 | V_279 ;
V_4 = V_56 [ V_2 ] . V_84 [ 1 ] ;
if ( V_178 )
V_4 |= V_280 ;
if ( V_181 -> V_4 & V_281 ) {
T_4 V_282 = F_85 ( V_181 -> V_269 ) ;
T_4 V_268 = V_181 -> V_268 ;
T_4 V_283 ;
V_275 |= V_284 ;
V_275 |= ( V_268 & V_285 ) << V_286 ;
V_283 = F_174 ( ~ 0ULL ) << V_287 ;
V_4 &= ~ V_283 ;
V_283 = F_175 ( ~ 0ULL ) << V_288 ;
V_4 &= ~ V_283 ;
V_283 = F_176 ( V_282 ) << V_289 ;
V_275 |= V_283 ;
V_283 = F_174 ( V_282 ) << V_287 ;
V_4 |= V_283 ;
V_283 = F_175 ( V_282 ) << V_288 ;
V_4 |= V_283 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_181 -> V_182 ;
V_56 [ V_2 ] . V_84 [ 1 ] = V_4 ;
V_56 [ V_2 ] . V_84 [ 0 ] = V_275 ;
}
static void F_177 ( T_1 V_2 )
{
V_56 [ V_2 ] . V_84 [ 0 ] = V_205 | V_279 ;
V_56 [ V_2 ] . V_84 [ 1 ] = 0 ;
F_178 ( V_2 ) ;
}
static void F_179 ( struct V_1 * V_3 ,
struct V_180 * V_181 )
{
struct V_53 * V_18 ;
bool V_178 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_178 = V_3 -> V_178 . V_179 ;
V_3 -> V_181 = V_181 ;
F_155 ( & V_3 -> V_256 , & V_181 -> V_271 ) ;
F_173 ( V_3 -> V_2 , V_181 , V_178 ) ;
V_181 -> V_184 [ V_18 -> V_229 ] += 1 ;
V_181 -> V_290 += 1 ;
F_106 ( V_3 ) ;
}
static void F_180 ( struct V_1 * V_3 )
{
struct V_53 * V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_3 -> V_181 -> V_184 [ V_18 -> V_229 ] -= 1 ;
V_3 -> V_181 -> V_290 -= 1 ;
V_3 -> V_181 = NULL ;
F_8 ( & V_3 -> V_256 ) ;
F_177 ( V_3 -> V_2 ) ;
F_106 ( V_3 ) ;
}
static int F_181 ( struct V_1 * V_3 ,
struct V_180 * V_181 )
{
int V_29 ;
F_182 ( & V_181 -> V_114 ) ;
if ( V_3 -> V_45 != NULL ) {
struct V_1 * V_45 = V_3 -> V_45 ;
V_29 = - V_204 ;
if ( V_45 -> V_181 != NULL &&
V_45 -> V_181 != V_181 )
goto V_9;
if ( V_3 -> V_181 != NULL &&
V_3 -> V_181 != V_181 )
goto V_9;
if ( V_45 -> V_181 == NULL )
F_179 ( V_45 , V_181 ) ;
F_183 ( & V_45 -> V_6 ) ;
}
if ( V_3 -> V_181 == NULL )
F_179 ( V_3 , V_181 ) ;
F_183 ( & V_3 -> V_6 ) ;
V_29 = 0 ;
V_9:
F_184 ( & V_181 -> V_114 ) ;
return V_29 ;
}
static void F_185 ( struct V_12 * V_13 )
{
F_186 ( V_13 ) ;
F_187 ( V_13 ) ;
F_188 ( V_13 ) ;
}
static int F_189 ( struct V_12 * V_13 )
{
T_1 V_291 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return - V_203 ;
F_190 ( V_13 , V_24 + V_292 , & V_291 ) ;
V_291 |= V_293 ;
F_191 ( V_13 , V_24 + V_292 , V_291 ) ;
return 0 ;
}
static int F_192 ( struct V_12 * V_13 )
{
bool V_294 ;
int V_295 , V_29 ;
V_295 = 32 ;
if ( F_19 ( V_13 , V_296 ) )
V_295 = 1 ;
V_294 = F_19 ( V_13 , V_297 ) ;
V_29 = F_193 ( V_13 , 0 ) ;
if ( V_29 )
goto V_298;
V_29 = F_194 ( V_13 ) ;
if ( V_29 )
goto V_298;
V_29 = F_195 ( V_13 , V_295 ) ;
if ( V_29 )
goto V_298;
if ( V_294 ) {
V_29 = F_189 ( V_13 ) ;
if ( V_29 )
goto V_298;
}
V_29 = F_196 ( V_13 , V_223 ) ;
if ( V_29 )
goto V_298;
return 0 ;
V_298:
F_187 ( V_13 ) ;
F_188 ( V_13 ) ;
return V_29 ;
}
static bool F_197 ( struct V_12 * V_13 )
{
T_1 V_162 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return false ;
F_190 ( V_13 , V_24 + V_299 , & V_162 ) ;
return ( V_162 & V_300 ) ? true : false ;
}
static int F_198 ( struct V_10 * V_11 ,
struct V_180 * V_181 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_29 ;
V_3 = F_16 ( V_11 ) ;
if ( V_181 -> V_4 & V_281 ) {
if ( ! V_3 -> V_54 || ! V_3 -> V_301 )
return - V_203 ;
if ( F_192 ( V_13 ) != 0 )
return - V_203 ;
V_3 -> V_178 . V_179 = true ;
V_3 -> V_178 . V_158 = F_199 ( V_13 ) ;
V_3 -> V_302 = F_197 ( V_13 ) ;
} else if ( V_303 &&
F_196 ( V_13 , V_223 ) == 0 ) {
V_3 -> V_178 . V_179 = true ;
V_3 -> V_178 . V_158 = F_199 ( V_13 ) ;
}
F_158 ( & V_258 , V_4 ) ;
V_29 = F_181 ( V_3 , V_181 ) ;
F_160 ( & V_258 , V_4 ) ;
F_110 ( V_181 ) ;
return V_29 ;
}
static void F_200 ( struct V_1 * V_3 )
{
struct V_180 * V_181 ;
unsigned long V_4 ;
F_118 ( ! V_3 -> V_181 ) ;
V_181 = V_3 -> V_181 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
if ( V_3 -> V_45 != NULL ) {
struct V_1 * V_45 = V_3 -> V_45 ;
if ( F_201 ( & V_45 -> V_6 ) )
F_180 ( V_45 ) ;
}
if ( F_201 ( & V_3 -> V_6 ) )
F_180 ( V_3 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
if ( V_3 -> V_301 &&
( V_3 -> V_181 == NULL && V_181 != V_304 ) )
F_181 ( V_3 , V_304 ) ;
}
static void F_202 ( struct V_10 * V_11 )
{
struct V_180 * V_181 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
V_181 = V_3 -> V_181 ;
F_158 ( & V_258 , V_4 ) ;
F_200 ( V_3 ) ;
F_160 ( & V_258 , V_4 ) ;
if ( V_181 -> V_4 & V_281 )
F_185 ( F_14 ( V_11 ) ) ;
else if ( V_3 -> V_178 . V_179 )
F_186 ( F_14 ( V_11 ) ) ;
V_3 -> V_178 . V_179 = false ;
}
static struct V_180 * F_203 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
struct V_180 * V_199 = NULL ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
if ( V_3 -> V_181 )
return V_3 -> V_181 ;
if ( V_3 -> V_45 != NULL ) {
struct V_1 * V_45 = V_3 -> V_45 ;
F_204 ( & V_258 , V_4 ) ;
if ( V_45 -> V_181 != NULL ) {
F_181 ( V_3 , V_45 -> V_181 ) ;
V_199 = V_45 -> V_181 ;
}
F_205 ( & V_258 , V_4 ) ;
}
return V_199 ;
}
static int F_206 ( struct V_305 * V_306 ,
unsigned long V_307 , void * V_84 )
{
struct V_27 * V_308 ;
struct V_180 * V_181 ;
struct V_1 * V_3 ;
struct V_10 * V_11 = V_84 ;
struct V_53 * V_18 ;
unsigned long V_4 ;
T_1 V_2 ;
if ( ! F_22 ( V_11 ) )
return 0 ;
V_2 = F_13 ( V_11 ) ;
V_18 = V_38 [ V_2 ] ;
V_3 = F_16 ( V_11 ) ;
switch ( V_307 ) {
case V_309 :
V_181 = F_203 ( V_11 ) ;
if ( ! V_181 )
goto V_310;
if ( V_3 -> V_301 )
break;
F_202 ( V_11 ) ;
break;
case V_311 :
F_25 ( V_11 ) ;
V_3 = F_16 ( V_11 ) ;
if ( V_312 || V_3 -> V_54 ) {
V_3 -> V_301 = true ;
F_198 ( V_11 , V_304 ) ;
break;
}
V_181 = F_203 ( V_11 ) ;
V_308 = F_20 ( V_2 ) ;
if ( V_308 )
goto V_310;
V_308 = F_170 () ;
if ( ! V_308 )
goto V_310;
V_308 -> V_34 = V_2 ;
F_4 ( & V_33 , V_4 ) ;
F_5 ( & V_308 -> V_256 , & V_32 ) ;
F_6 ( & V_33 , V_4 ) ;
V_3 = F_16 ( V_11 ) ;
V_11 -> V_17 . V_313 = & V_314 ;
break;
case V_315 :
F_44 ( V_11 ) ;
default:
goto V_310;
}
F_98 ( V_18 ) ;
V_310:
return 0 ;
}
void F_207 ( void )
{
F_208 ( & V_36 , & V_316 ) ;
}
static struct V_180 * F_209 ( struct V_10 * V_11 )
{
struct V_180 * V_181 ;
struct V_27 * V_217 ;
T_1 V_2 = F_13 ( V_11 ) ;
if ( ! F_22 ( V_11 ) )
return F_210 ( - V_203 ) ;
V_181 = F_203 ( V_11 ) ;
if ( V_181 != NULL && ! V_27 ( V_181 ) )
return F_210 ( - V_204 ) ;
if ( V_181 != NULL )
return V_181 ;
V_217 = F_20 ( V_2 ) ;
if ( ! V_217 )
V_217 = V_38 [ V_2 ] -> V_226 ;
F_198 ( V_11 , & V_217 -> V_181 ) ;
F_211 ( L_23 ,
V_217 -> V_181 . V_182 , F_27 ( V_11 ) ) ;
return & V_217 -> V_181 ;
}
static void F_212 ( struct V_180 * V_181 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_173 ( V_3 -> V_2 , V_181 , V_3 -> V_178 . V_179 ) ;
}
static void F_134 ( struct V_180 * V_181 )
{
if ( ! V_181 -> V_191 )
return;
F_212 ( V_181 ) ;
F_112 ( V_181 ) ;
F_110 ( V_181 ) ;
V_181 -> V_191 = false ;
}
static T_4 * F_213 ( struct V_27 * V_199 ,
unsigned long V_92 )
{
struct V_235 * V_224 ;
T_4 * V_187 , * V_193 ;
V_224 = V_199 -> V_224 [ F_214 ( V_92 ) ] ;
if ( ! V_224 )
return NULL ;
V_187 = V_224 -> V_238 [ F_215 ( V_92 ) ] ;
if ( ! V_187 ) {
V_187 = F_117 ( & V_199 -> V_181 , V_92 , V_152 , & V_193 ,
V_317 ) ;
V_224 -> V_238 [ F_215 ( V_92 ) ] = V_193 ;
} else
V_187 += F_121 ( 0 , V_92 ) ;
F_134 ( & V_199 -> V_181 ) ;
return V_187 ;
}
static T_9 F_216 ( struct V_27 * V_199 ,
unsigned long V_92 ,
T_10 V_318 ,
int V_319 )
{
T_4 * V_187 , V_198 ;
F_83 ( V_92 > V_199 -> V_222 ) ;
V_318 &= V_154 ;
V_187 = F_213 ( V_199 , V_92 ) ;
if ( ! V_187 )
return V_253 ;
V_198 = V_318 | V_205 | V_206 ;
if ( V_319 == V_320 )
V_198 |= V_208 ;
else if ( V_319 == V_321 )
V_198 |= V_210 ;
else if ( V_319 == V_322 )
V_198 |= V_208 | V_210 ;
F_83 ( * V_187 ) ;
* V_187 = V_198 ;
return ( T_9 ) V_92 ;
}
static void F_217 ( struct V_27 * V_199 ,
unsigned long V_92 )
{
struct V_235 * V_224 ;
T_4 * V_187 ;
if ( V_92 >= V_199 -> V_222 )
return;
V_224 = V_199 -> V_224 [ F_214 ( V_92 ) ] ;
if ( ! V_224 )
return;
V_187 = V_224 -> V_238 [ F_215 ( V_92 ) ] ;
if ( ! V_187 )
return;
V_187 += F_121 ( 0 , V_92 ) ;
F_83 ( ! * V_187 ) ;
* V_187 = 0ULL ;
}
static T_9 F_218 ( struct V_10 * V_11 ,
struct V_27 * V_217 ,
T_10 V_318 ,
T_7 V_148 ,
int V_323 ,
bool V_324 ,
T_4 V_35 )
{
T_9 V_236 = V_318 & ~ V_154 ;
T_9 V_92 , V_246 , V_29 ;
unsigned int V_150 ;
unsigned long V_245 = 0 ;
int V_23 ;
V_150 = F_90 ( V_318 , V_148 , V_152 ) ;
V_318 &= V_154 ;
F_67 ( V_79 ) ;
if ( V_150 > 1 )
F_67 ( V_75 ) ;
if ( V_324 )
V_245 = ( 1UL << F_219 ( V_148 ) ) - 1 ;
V_93:
V_92 = F_150 ( V_11 , V_217 , V_150 , V_245 ,
V_35 ) ;
if ( F_151 ( V_92 == V_253 ) ) {
V_217 -> V_248 = V_217 -> V_222 ;
if ( F_142 ( V_217 , false , V_317 ) )
goto V_310;
goto V_93;
}
V_246 = V_92 ;
for ( V_23 = 0 ; V_23 < V_150 ; ++ V_23 ) {
V_29 = F_216 ( V_217 , V_246 , V_318 , V_323 ) ;
if ( V_29 == V_253 )
goto V_325;
V_318 += V_152 ;
V_246 += V_152 ;
}
V_92 += V_236 ;
F_220 ( V_78 , V_148 ) ;
if ( F_151 ( V_217 -> V_252 && ! V_67 ) ) {
F_109 ( & V_217 -> V_181 ) ;
V_217 -> V_252 = false ;
} else if ( F_151 ( V_326 ) )
F_108 ( & V_217 -> V_181 , V_92 , V_148 ) ;
V_310:
return V_92 ;
V_325:
for ( -- V_23 ; V_23 >= 0 ; -- V_23 ) {
V_246 -= V_152 ;
F_217 ( V_217 , V_246 ) ;
}
F_152 ( V_217 , V_92 , V_150 ) ;
return V_253 ;
}
static void F_221 ( struct V_27 * V_217 ,
T_9 V_327 ,
T_7 V_148 ,
int V_323 )
{
T_9 V_328 ;
T_9 V_23 , V_246 ;
unsigned int V_150 ;
if ( ( V_327 == V_253 ) ||
( V_327 + V_148 > V_217 -> V_222 ) )
return;
V_328 = V_327 ;
V_150 = F_90 ( V_327 , V_148 , V_152 ) ;
V_327 &= V_154 ;
V_246 = V_327 ;
for ( V_23 = 0 ; V_23 < V_150 ; ++ V_23 ) {
F_217 ( V_217 , V_246 ) ;
V_246 += V_152 ;
}
F_222 ( V_78 , V_148 ) ;
F_152 ( V_217 , V_327 , V_150 ) ;
if ( V_67 || V_217 -> V_252 ) {
F_108 ( & V_217 -> V_181 , V_328 , V_148 ) ;
V_217 -> V_252 = false ;
}
}
static T_9 F_223 ( struct V_10 * V_11 , struct V_196 * V_196 ,
unsigned long V_236 , T_7 V_148 ,
enum V_329 V_323 ,
struct V_330 * V_331 )
{
unsigned long V_4 ;
struct V_180 * V_181 ;
T_9 V_219 ;
T_4 V_35 ;
T_10 V_318 = F_224 ( V_196 ) + V_236 ;
F_67 ( V_69 ) ;
V_181 = F_209 ( V_11 ) ;
if ( F_40 ( V_181 ) == - V_203 )
return ( T_9 ) V_318 ;
else if ( F_39 ( V_181 ) )
return V_253 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
V_219 = F_218 ( V_11 , V_181 -> V_274 , V_318 , V_148 , V_323 , false ,
V_35 ) ;
if ( V_219 == V_253 )
goto V_310;
F_111 ( V_181 ) ;
V_310:
F_6 ( & V_181 -> V_114 , V_4 ) ;
return V_219 ;
}
static void F_225 ( struct V_10 * V_11 , T_9 V_327 , T_7 V_148 ,
enum V_329 V_323 , struct V_330 * V_331 )
{
unsigned long V_4 ;
struct V_180 * V_181 ;
F_67 ( V_70 ) ;
V_181 = F_209 ( V_11 ) ;
if ( F_39 ( V_181 ) )
return;
F_4 ( & V_181 -> V_114 , V_4 ) ;
F_221 ( V_181 -> V_274 , V_327 , V_148 , V_323 ) ;
F_111 ( V_181 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
}
static int F_226 ( struct V_10 * V_11 , struct V_332 * V_333 ,
int V_334 , int V_323 )
{
struct V_332 * V_151 ;
int V_23 ;
F_227 (sglist, s, nelems, i) {
V_151 -> V_335 = ( T_9 ) F_228 ( V_151 ) ;
V_151 -> V_336 = V_151 -> V_337 ;
}
return V_334 ;
}
static int F_229 ( struct V_10 * V_11 , struct V_332 * V_333 ,
int V_334 , enum V_329 V_323 ,
struct V_330 * V_331 )
{
unsigned long V_4 ;
struct V_180 * V_181 ;
int V_23 ;
struct V_332 * V_151 ;
T_10 V_318 ;
int V_338 = 0 ;
T_4 V_35 ;
F_67 ( V_71 ) ;
V_181 = F_209 ( V_11 ) ;
if ( F_40 ( V_181 ) == - V_203 )
return F_226 ( V_11 , V_333 , V_334 , V_323 ) ;
else if ( F_39 ( V_181 ) )
return 0 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
F_227 (sglist, s, nelems, i) {
V_318 = F_228 ( V_151 ) ;
V_151 -> V_335 = F_218 ( V_11 , V_181 -> V_274 ,
V_318 , V_151 -> V_337 , V_323 , false ,
V_35 ) ;
if ( V_151 -> V_335 ) {
V_151 -> V_336 = V_151 -> V_337 ;
V_338 ++ ;
} else
goto V_339;
}
F_111 ( V_181 ) ;
V_310:
F_6 ( & V_181 -> V_114 , V_4 ) ;
return V_338 ;
V_339:
F_227 (sglist, s, mapped_elems, i) {
if ( V_151 -> V_335 )
F_221 ( V_181 -> V_274 , V_151 -> V_335 ,
V_151 -> V_336 , V_323 ) ;
V_151 -> V_335 = V_151 -> V_336 = 0 ;
}
V_338 = 0 ;
goto V_310;
}
static void F_230 ( struct V_10 * V_11 , struct V_332 * V_333 ,
int V_334 , enum V_329 V_323 ,
struct V_330 * V_331 )
{
unsigned long V_4 ;
struct V_180 * V_181 ;
struct V_332 * V_151 ;
int V_23 ;
F_67 ( V_72 ) ;
V_181 = F_209 ( V_11 ) ;
if ( F_39 ( V_181 ) )
return;
F_4 ( & V_181 -> V_114 , V_4 ) ;
F_227 (sglist, s, nelems, i) {
F_221 ( V_181 -> V_274 , V_151 -> V_335 ,
V_151 -> V_336 , V_323 ) ;
V_151 -> V_335 = V_151 -> V_336 = 0 ;
}
F_111 ( V_181 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
}
static void * F_231 ( struct V_10 * V_11 , T_7 V_148 ,
T_9 * V_327 , T_8 V_340 ,
struct V_330 * V_331 )
{
unsigned long V_4 ;
void * V_341 ;
struct V_180 * V_181 ;
T_10 V_318 ;
T_4 V_35 = V_11 -> V_342 ;
F_67 ( V_73 ) ;
V_181 = F_209 ( V_11 ) ;
if ( F_40 ( V_181 ) == - V_203 ) {
V_341 = ( void * ) F_232 ( V_340 , F_219 ( V_148 ) ) ;
* V_327 = F_85 ( V_341 ) ;
return V_341 ;
} else if ( F_39 ( V_181 ) )
return NULL ;
V_35 = V_11 -> V_342 ;
V_340 &= ~ ( V_343 | V_344 | V_345 ) ;
V_340 |= V_346 ;
V_341 = ( void * ) F_232 ( V_340 , F_219 ( V_148 ) ) ;
if ( ! V_341 )
return NULL ;
V_318 = F_116 ( V_341 ) ;
if ( ! V_35 )
V_35 = * V_11 -> V_35 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
* V_327 = F_218 ( V_11 , V_181 -> V_274 , V_318 ,
V_148 , V_322 , true , V_35 ) ;
if ( * V_327 == V_253 ) {
F_6 ( & V_181 -> V_114 , V_4 ) ;
goto V_59;
}
F_111 ( V_181 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
return V_341 ;
V_59:
F_233 ( ( unsigned long ) V_341 , F_219 ( V_148 ) ) ;
return NULL ;
}
static void F_234 ( struct V_10 * V_11 , T_7 V_148 ,
void * V_341 , T_9 V_327 ,
struct V_330 * V_331 )
{
unsigned long V_4 ;
struct V_180 * V_181 ;
F_67 ( V_74 ) ;
V_181 = F_209 ( V_11 ) ;
if ( F_39 ( V_181 ) )
goto V_347;
F_4 ( & V_181 -> V_114 , V_4 ) ;
F_221 ( V_181 -> V_274 , V_327 , V_148 , V_322 ) ;
F_111 ( V_181 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
V_347:
F_233 ( ( unsigned long ) V_341 , F_219 ( V_148 ) ) ;
}
static int F_235 ( struct V_10 * V_11 , T_4 V_348 )
{
return F_22 ( V_11 ) ;
}
static void T_3 F_236 ( void )
{
struct V_1 * V_3 ;
struct V_27 * V_217 ;
struct V_12 * V_11 = NULL ;
T_1 V_2 ;
F_47 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
if ( ! V_349 && V_3 -> V_54 ) {
F_237 () ;
V_3 -> V_301 = true ;
F_198 ( & V_11 -> V_11 , V_304 ) ;
F_238 ( L_24 ,
F_27 ( & V_11 -> V_11 ) ) ;
}
if ( F_203 ( & V_11 -> V_11 ) )
continue;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_217 = F_170 () ;
if ( ! V_217 )
continue;
F_140 ( V_217 , V_2 ) ;
V_217 -> V_34 = V_2 ;
F_198 ( & V_11 -> V_11 , & V_217 -> V_181 ) ;
F_5 ( & V_217 -> V_256 , & V_32 ) ;
}
}
static unsigned F_239 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_13 = NULL ;
unsigned V_350 = 0 ;
F_47 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) ) {
F_43 ( & V_13 -> V_11 ) ;
V_350 += 1 ;
continue;
}
V_3 = F_16 ( & V_13 -> V_11 ) ;
if ( ! V_3 -> V_301 )
V_13 -> V_11 . V_17 . V_313 = & V_314 ;
else
V_13 -> V_11 . V_17 . V_313 = & V_351 ;
}
return V_350 ;
}
void T_3 F_240 ( void )
{
F_241 ( & V_36 , & V_352 ) ;
}
int T_3 F_242 ( void )
{
struct V_53 * V_18 ;
int V_29 , V_350 ;
F_77 (iommu) {
V_18 -> V_226 = F_170 () ;
if ( V_18 -> V_226 == NULL )
return - V_44 ;
V_18 -> V_226 -> V_181 . V_4 |= V_353 ;
V_29 = F_139 ( V_18 ) ;
if ( V_29 )
goto V_354;
}
F_236 () ;
V_355 = 1 ;
V_356 = 0 ;
V_350 = F_239 () ;
if ( V_350 && V_357 > V_358 ) {
V_356 = 1 ;
}
F_52 () ;
if ( V_67 )
F_238 ( L_25 ) ;
else
F_238 ( L_26 ) ;
return 0 ;
V_354:
F_77 (iommu) {
if ( V_18 -> V_226 )
F_169 ( V_18 -> V_226 ) ;
}
return V_29 ;
}
static void F_243 ( struct V_180 * V_181 )
{
struct V_1 * V_3 , * V_359 ;
unsigned long V_4 ;
F_158 ( & V_258 , V_4 ) ;
F_48 (dev_data, next, &domain->dev_list, list) {
F_200 ( V_3 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
}
F_160 ( & V_258 , V_4 ) ;
}
static void F_244 ( struct V_180 * V_181 )
{
if ( ! V_181 )
return;
F_156 ( V_181 ) ;
if ( V_181 -> V_182 )
F_161 ( V_181 -> V_182 ) ;
F_9 ( V_181 ) ;
}
static struct V_180 * F_245 ( void )
{
struct V_180 * V_181 ;
V_181 = F_2 ( sizeof( * V_181 ) , V_5 ) ;
if ( ! V_181 )
return NULL ;
F_171 ( & V_181 -> V_114 ) ;
F_246 ( & V_181 -> V_360 ) ;
V_181 -> V_182 = F_157 () ;
if ( ! V_181 -> V_182 )
goto V_298;
F_172 ( & V_181 -> V_271 ) ;
F_154 ( V_181 ) ;
return V_181 ;
V_298:
F_9 ( V_181 ) ;
return NULL ;
}
static int T_3 F_237 ( void )
{
if ( V_304 != NULL )
return 0 ;
V_304 = F_245 () ;
if ( ! V_304 )
return - V_44 ;
V_304 -> V_188 = V_276 ;
return 0 ;
}
static int F_247 ( struct V_361 * V_199 )
{
struct V_180 * V_181 ;
V_181 = F_245 () ;
if ( ! V_181 )
goto V_59;
V_181 -> V_188 = V_362 ;
V_181 -> V_190 = ( void * ) F_114 ( V_5 ) ;
if ( ! V_181 -> V_190 )
goto V_59;
V_181 -> V_361 = V_199 ;
V_199 -> V_274 = V_181 ;
V_199 -> V_363 . V_364 = 0 ;
V_199 -> V_363 . V_365 = ~ 0ULL ;
V_199 -> V_363 . V_366 = true ;
return 0 ;
V_59:
F_244 ( V_181 ) ;
return - V_44 ;
}
static void F_248 ( struct V_361 * V_199 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
if ( ! V_181 )
return;
if ( V_181 -> V_290 > 0 )
F_243 ( V_181 ) ;
F_118 ( V_181 -> V_290 != 0 ) ;
if ( V_181 -> V_188 != V_276 )
F_163 ( V_181 ) ;
if ( V_181 -> V_4 & V_281 )
F_167 ( V_181 ) ;
F_244 ( V_181 ) ;
V_199 -> V_274 = NULL ;
}
static void F_249 ( struct V_361 * V_199 ,
struct V_10 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_17 . V_18 ;
struct V_53 * V_18 ;
T_1 V_2 ;
if ( ! F_22 ( V_11 ) )
return;
V_2 = F_13 ( V_11 ) ;
if ( V_3 -> V_181 != NULL )
F_202 ( V_11 ) ;
V_18 = V_38 [ V_2 ] ;
if ( ! V_18 )
return;
F_98 ( V_18 ) ;
}
static int F_250 ( struct V_361 * V_199 ,
struct V_10 * V_11 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
struct V_1 * V_3 ;
struct V_53 * V_18 ;
int V_29 ;
if ( ! F_22 ( V_11 ) )
return - V_203 ;
V_3 = V_11 -> V_17 . V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
if ( ! V_18 )
return - V_203 ;
if ( V_3 -> V_181 )
F_202 ( V_11 ) ;
V_29 = F_198 ( V_11 , V_181 ) ;
F_98 ( V_18 ) ;
return V_29 ;
}
static int F_251 ( struct V_361 * V_199 , unsigned long V_367 ,
T_10 V_318 , T_7 V_192 , int V_368 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
int V_201 = 0 ;
int V_29 ;
if ( V_181 -> V_188 == V_276 )
return - V_203 ;
if ( V_368 & V_369 )
V_201 |= V_207 ;
if ( V_368 & V_370 )
V_201 |= V_209 ;
F_252 ( & V_181 -> V_360 ) ;
V_29 = F_130 ( V_181 , V_367 , V_318 , V_201 , V_192 ) ;
F_253 ( & V_181 -> V_360 ) ;
return V_29 ;
}
static T_7 F_254 ( struct V_361 * V_199 , unsigned long V_367 ,
T_7 V_192 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
T_7 V_211 ;
if ( V_181 -> V_188 == V_276 )
return - V_203 ;
F_252 ( & V_181 -> V_360 ) ;
V_211 = F_135 ( V_181 , V_367 , V_192 ) ;
F_253 ( & V_181 -> V_360 ) ;
F_110 ( V_181 ) ;
return V_211 ;
}
static T_10 F_255 ( struct V_361 * V_199 ,
unsigned long V_367 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
unsigned long V_371 ;
T_10 V_318 ;
T_4 * V_187 , V_198 ;
if ( V_181 -> V_188 == V_276 )
return V_367 ;
V_187 = F_127 ( V_181 , V_367 ) ;
if ( ! V_187 || ! F_124 ( * V_187 ) )
return 0 ;
if ( F_125 ( * V_187 ) == 0 )
V_371 = V_152 - 1 ;
else
V_371 = F_128 ( * V_187 ) - 1 ;
V_198 = * V_187 & V_372 ;
V_318 = ( V_198 & ~ V_371 ) | ( V_367 & V_371 ) ;
return V_318 ;
}
static int F_256 ( struct V_361 * V_181 ,
unsigned long V_373 )
{
switch ( V_373 ) {
case V_374 :
return 1 ;
}
return 0 ;
}
int T_3 F_257 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_11 = NULL ;
struct V_53 * V_18 ;
T_1 V_2 ;
int V_29 ;
V_29 = F_237 () ;
if ( V_29 )
return V_29 ;
F_47 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
V_3 -> V_301 = true ;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_18 = V_38 [ V_2 ] ;
if ( ! V_18 )
continue;
F_198 ( & V_11 -> V_11 , V_304 ) ;
}
F_52 () ;
F_238 ( L_27 ) ;
return 0 ;
}
int F_258 ( struct V_305 * V_306 )
{
return F_259 ( & V_128 , V_306 ) ;
}
int F_260 ( struct V_305 * V_306 )
{
return F_261 ( & V_128 , V_306 ) ;
}
void F_262 ( struct V_361 * V_199 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
unsigned long V_4 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
V_181 -> V_188 = V_276 ;
V_181 -> V_191 = true ;
F_134 ( V_181 ) ;
F_163 ( V_181 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
}
int F_263 ( struct V_361 * V_199 , int V_375 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
unsigned long V_4 ;
int V_376 , V_29 ;
if ( V_375 <= 0 || V_375 > ( V_160 + 1 ) )
return - V_203 ;
for ( V_376 = 0 ; ( V_375 - 1 ) & ~ 0x1ff ; V_375 >>= 9 )
V_376 += 1 ;
if ( V_376 > V_377 )
return - V_203 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
V_29 = - V_204 ;
if ( V_181 -> V_290 > 0 || V_181 -> V_4 & V_281 )
goto V_310;
V_29 = - V_44 ;
V_181 -> V_269 = ( void * ) F_114 ( V_317 ) ;
if ( V_181 -> V_269 == NULL )
goto V_310;
V_181 -> V_268 = V_376 ;
V_181 -> V_4 |= V_281 ;
V_181 -> V_191 = true ;
F_134 ( V_181 ) ;
V_29 = 0 ;
V_310:
F_6 ( & V_181 -> V_114 , V_4 ) ;
return V_29 ;
}
static int F_264 ( struct V_180 * V_181 , int V_125 ,
T_4 V_92 , bool V_148 )
{
struct V_1 * V_3 ;
struct V_86 V_87 ;
int V_23 , V_29 ;
if ( ! ( V_181 -> V_4 & V_281 ) )
return - V_203 ;
F_92 ( & V_87 , V_181 -> V_182 , V_125 , V_92 , V_148 ) ;
for ( V_23 = 0 ; V_23 < V_183 ; ++ V_23 ) {
if ( V_181 -> V_184 [ V_23 ] == 0 )
continue;
V_29 = F_97 ( V_185 [ V_23 ] , & V_87 ) ;
if ( V_29 != 0 )
goto V_310;
}
F_111 ( V_181 ) ;
F_11 (dev_data, &domain->dev_list, list) {
struct V_53 * V_18 ;
int V_158 ;
F_118 ( ! V_3 -> V_178 . V_179 ) ;
V_158 = V_3 -> V_178 . V_158 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_93 ( & V_87 , V_3 -> V_2 , V_125 ,
V_158 , V_92 , V_148 ) ;
V_29 = F_97 ( V_18 , & V_87 ) ;
if ( V_29 != 0 )
goto V_310;
}
F_111 ( V_181 ) ;
V_29 = 0 ;
V_310:
return V_29 ;
}
static int F_265 ( struct V_180 * V_181 , int V_125 ,
T_4 V_92 )
{
F_67 ( V_81 ) ;
return F_264 ( V_181 , V_125 , V_92 , false ) ;
}
int F_266 ( struct V_361 * V_199 , int V_125 ,
T_4 V_92 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
V_29 = F_265 ( V_181 , V_125 , V_92 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
return V_29 ;
}
static int F_267 ( struct V_180 * V_181 , int V_125 )
{
F_67 ( V_82 ) ;
return F_264 ( V_181 , V_125 , V_153 ,
true ) ;
}
int F_268 ( struct V_361 * V_199 , int V_125 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
V_29 = F_267 ( V_181 , V_125 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
return V_29 ;
}
static T_4 * F_269 ( T_4 * V_378 , int V_194 , int V_125 , bool V_379 )
{
int V_229 ;
T_4 * V_187 ;
while ( true ) {
V_229 = ( V_125 >> ( 9 * V_194 ) ) & 0x1ff ;
V_187 = & V_378 [ V_229 ] ;
if ( V_194 == 0 )
break;
if ( ! ( * V_187 & V_267 ) ) {
if ( ! V_379 )
return NULL ;
V_378 = ( void * ) F_114 ( V_317 ) ;
if ( V_378 == NULL )
return NULL ;
* V_187 = F_85 ( V_378 ) | V_267 ;
}
V_378 = F_165 ( * V_187 & V_154 ) ;
V_194 -= 1 ;
}
return V_187 ;
}
static int F_270 ( struct V_180 * V_181 , int V_125 ,
unsigned long V_380 )
{
T_4 * V_187 ;
if ( V_181 -> V_188 != V_276 )
return - V_203 ;
V_187 = F_269 ( V_181 -> V_269 , V_181 -> V_268 , V_125 , true ) ;
if ( V_187 == NULL )
return - V_44 ;
* V_187 = ( V_380 & V_154 ) | V_267 ;
return F_267 ( V_181 , V_125 ) ;
}
static int F_271 ( struct V_180 * V_181 , int V_125 )
{
T_4 * V_187 ;
if ( V_181 -> V_188 != V_276 )
return - V_203 ;
V_187 = F_269 ( V_181 -> V_269 , V_181 -> V_268 , V_125 , false ) ;
if ( V_187 == NULL )
return 0 ;
* V_187 = 0 ;
return F_267 ( V_181 , V_125 ) ;
}
int F_272 ( struct V_361 * V_199 , int V_125 ,
unsigned long V_380 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
V_29 = F_270 ( V_181 , V_125 , V_380 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
return V_29 ;
}
int F_273 ( struct V_361 * V_199 , int V_125 )
{
struct V_180 * V_181 = V_199 -> V_274 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_181 -> V_114 , V_4 ) ;
V_29 = F_271 ( V_181 , V_125 ) ;
F_6 ( & V_181 -> V_114 , V_4 ) ;
return V_29 ;
}
int F_274 ( struct V_12 * V_13 , int V_125 ,
int V_162 , int V_127 )
{
struct V_1 * V_3 ;
struct V_53 * V_18 ;
struct V_86 V_87 ;
F_67 ( V_80 ) ;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_94 ( & V_87 , V_3 -> V_2 , V_125 , V_162 ,
V_127 , V_3 -> V_302 ) ;
return F_97 ( V_18 , & V_87 ) ;
}
struct V_361 * F_275 ( struct V_12 * V_13 )
{
struct V_180 * V_181 ;
V_181 = F_209 ( & V_13 -> V_11 ) ;
if ( F_39 ( V_181 ) )
return NULL ;
if ( ! ( V_181 -> V_4 & V_281 ) )
return NULL ;
return V_181 -> V_361 ;
}
void F_276 ( struct V_12 * V_13 , T_2 V_25 )
{
struct V_1 * V_3 ;
if ( ! F_277 () )
return;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_3 -> V_26 |= ( 1 << V_25 ) ;
}
int F_278 ( struct V_12 * V_13 ,
struct F_278 * V_381 )
{
int V_382 ;
int V_24 ;
if ( V_13 == NULL || V_381 == NULL )
return - V_203 ;
if ( ! F_277 () )
return - V_203 ;
memset ( V_381 , 0 , sizeof( * V_381 ) ) ;
V_24 = F_18 ( V_13 , V_20 ) ;
if ( V_24 )
V_381 -> V_4 |= V_383 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( V_24 )
V_381 -> V_4 |= V_384 ;
V_24 = F_18 ( V_13 , V_22 ) ;
if ( V_24 ) {
int V_385 ;
V_382 = 1 << ( 9 * ( V_377 + 1 ) ) ;
V_382 = F_279 ( V_382 , ( 1 << 20 ) ) ;
V_381 -> V_4 |= V_386 ;
V_381 -> V_382 = F_279 ( F_280 ( V_13 ) , V_382 ) ;
V_385 = F_281 ( V_13 ) ;
if ( V_385 & V_387 )
V_381 -> V_4 |= V_388 ;
if ( V_385 & V_389 )
V_381 -> V_4 |= V_390 ;
}
return 0 ;
}
