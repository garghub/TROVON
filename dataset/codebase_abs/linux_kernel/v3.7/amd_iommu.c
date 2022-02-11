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
static void F_96 ( struct V_86 * V_87 , T_1 V_2 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
F_87 ( V_87 , V_168 ) ;
}
static int F_97 ( struct V_53 * V_18 ,
struct V_86 * V_87 ,
bool V_169 )
{
T_2 V_170 , V_113 , V_112 , V_171 ;
unsigned long V_4 ;
F_83 ( V_18 -> V_143 & V_172 ) ;
V_173:
F_4 ( & V_18 -> V_114 , V_4 ) ;
V_112 = F_64 ( V_18 -> V_115 + V_174 ) ;
V_113 = F_64 ( V_18 -> V_115 + V_144 ) ;
V_171 = ( V_113 + sizeof( * V_87 ) ) % V_18 -> V_143 ;
V_170 = ( V_112 - V_171 ) % V_18 -> V_143 ;
if ( V_170 <= 2 ) {
struct V_86 V_175 ;
volatile T_4 V_139 = 0 ;
int V_29 ;
F_82 ( & V_175 , ( T_4 ) & V_139 ) ;
F_81 ( V_18 , & V_175 , V_113 ) ;
F_6 ( & V_18 -> V_114 , V_4 ) ;
if ( ( V_29 = F_79 ( & V_139 ) ) != 0 )
return V_29 ;
goto V_173;
}
F_81 ( V_18 , V_87 , V_113 ) ;
V_18 -> V_176 = V_169 ;
F_6 ( & V_18 -> V_114 , V_4 ) ;
return 0 ;
}
static int F_98 ( struct V_53 * V_18 , struct V_86 * V_87 )
{
return F_97 ( V_18 , V_87 , true ) ;
}
static int F_99 ( struct V_53 * V_18 )
{
struct V_86 V_87 ;
volatile T_4 V_139 = 0 ;
int V_29 ;
if ( ! V_18 -> V_176 )
return 0 ;
F_82 ( & V_87 , ( T_4 ) & V_139 ) ;
V_29 = F_97 ( V_18 , & V_87 , false ) ;
if ( V_29 )
return V_29 ;
return F_79 ( & V_139 ) ;
}
static int F_100 ( struct V_53 * V_18 , T_1 V_2 )
{
struct V_86 V_87 ;
F_88 ( & V_87 , V_2 ) ;
return F_98 ( V_18 , & V_87 ) ;
}
static void F_101 ( struct V_53 * V_18 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= 0xffff ; ++ V_2 )
F_100 ( V_18 , V_2 ) ;
F_99 ( V_18 ) ;
}
static void F_102 ( struct V_53 * V_18 )
{
T_2 V_177 ;
for ( V_177 = 0 ; V_177 <= 0xffff ; ++ V_177 ) {
struct V_86 V_87 ;
F_89 ( & V_87 , 0 , V_153 ,
V_177 , 1 ) ;
F_98 ( V_18 , & V_87 ) ;
}
F_99 ( V_18 ) ;
}
static void F_103 ( struct V_53 * V_18 )
{
struct V_86 V_87 ;
F_95 ( & V_87 ) ;
F_98 ( V_18 , & V_87 ) ;
F_99 ( V_18 ) ;
}
static void F_104 ( struct V_53 * V_18 , T_1 V_2 )
{
struct V_86 V_87 ;
F_96 ( & V_87 , V_2 ) ;
F_98 ( V_18 , & V_87 ) ;
}
static void F_105 ( struct V_53 * V_18 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= V_178 ; V_2 ++ )
F_104 ( V_18 , V_2 ) ;
F_99 ( V_18 ) ;
}
void F_106 ( struct V_53 * V_18 )
{
if ( F_107 ( V_18 , V_179 ) ) {
F_103 ( V_18 ) ;
} else {
F_101 ( V_18 ) ;
F_105 ( V_18 ) ;
F_102 ( V_18 ) ;
}
}
static int F_108 ( struct V_1 * V_3 ,
T_4 V_92 , T_7 V_148 )
{
struct V_53 * V_18 ;
struct V_86 V_87 ;
int V_158 ;
V_158 = V_3 -> V_180 . V_158 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_91 ( & V_87 , V_3 -> V_2 , V_158 , V_92 , V_148 ) ;
return F_98 ( V_18 , & V_87 ) ;
}
static int F_109 ( struct V_1 * V_3 )
{
struct V_53 * V_18 ;
int V_29 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_29 = F_100 ( V_18 , V_3 -> V_2 ) ;
if ( V_29 )
return V_29 ;
if ( V_3 -> V_180 . V_181 )
V_29 = F_108 ( V_3 , 0 , ~ 0UL ) ;
return V_29 ;
}
static void F_110 ( struct V_182 * V_183 ,
T_4 V_92 , T_7 V_148 , int V_149 )
{
struct V_1 * V_3 ;
struct V_86 V_87 ;
int V_29 = 0 , V_23 ;
F_89 ( & V_87 , V_92 , V_148 , V_183 -> V_184 , V_149 ) ;
for ( V_23 = 0 ; V_23 < V_185 ; ++ V_23 ) {
if ( ! V_183 -> V_186 [ V_23 ] )
continue;
V_29 |= F_98 ( V_187 [ V_23 ] , & V_87 ) ;
}
F_11 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_180 . V_181 )
continue;
V_29 |= F_108 ( V_3 , V_92 , V_148 ) ;
}
F_83 ( V_29 ) ;
}
static void F_111 ( struct V_182 * V_183 ,
T_4 V_92 , T_7 V_148 )
{
F_110 ( V_183 , V_92 , V_148 , 0 ) ;
}
static void F_112 ( struct V_182 * V_183 )
{
F_110 ( V_183 , 0 , V_153 , 0 ) ;
}
static void F_113 ( struct V_182 * V_183 )
{
F_110 ( V_183 , 0 , V_153 , 1 ) ;
}
static void F_114 ( struct V_182 * V_183 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_185 ; ++ V_23 ) {
if ( ! V_183 -> V_186 [ V_23 ] )
continue;
F_99 ( V_187 [ V_23 ] ) ;
}
}
static void F_115 ( struct V_182 * V_183 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_109 ( V_3 ) ;
}
static bool F_116 ( struct V_182 * V_183 ,
T_8 V_188 )
{
T_4 * V_189 ;
if ( V_183 -> V_190 == V_191 )
return false ;
V_189 = ( void * ) F_117 ( V_188 ) ;
if ( ! V_189 )
return false ;
* V_189 = F_118 ( V_183 -> V_190 ,
F_119 ( V_183 -> V_192 ) ) ;
V_183 -> V_192 = V_189 ;
V_183 -> V_190 += 1 ;
V_183 -> V_193 = true ;
return true ;
}
static T_4 * F_120 ( struct V_182 * V_183 ,
unsigned long V_92 ,
unsigned long V_194 ,
T_4 * * V_195 ,
T_8 V_188 )
{
int V_196 , V_197 ;
T_4 * V_189 , * V_198 ;
F_121 ( ! F_122 ( V_194 ) ) ;
while ( V_92 > F_123 ( V_183 -> V_190 ) )
F_116 ( V_183 , V_188 ) ;
V_196 = V_183 -> V_190 - 1 ;
V_189 = & V_183 -> V_192 [ F_124 ( V_196 , V_92 ) ] ;
V_92 = F_125 ( V_92 , V_194 ) ;
V_197 = F_126 ( V_194 ) ;
while ( V_196 > V_197 ) {
if ( ! F_127 ( * V_189 ) ) {
V_198 = ( T_4 * ) F_117 ( V_188 ) ;
if ( ! V_198 )
return NULL ;
* V_189 = F_118 ( V_196 , F_119 ( V_198 ) ) ;
}
if ( F_128 ( * V_189 ) != V_196 )
return NULL ;
V_196 -= 1 ;
V_189 = F_129 ( * V_189 ) ;
if ( V_195 && V_196 == V_197 )
* V_195 = V_189 ;
V_189 = & V_189 [ F_124 ( V_196 , V_92 ) ] ;
}
return V_189 ;
}
static T_4 * F_130 ( struct V_182 * V_183 , unsigned long V_92 )
{
int V_196 ;
T_4 * V_189 ;
if ( V_92 > F_123 ( V_183 -> V_190 ) )
return NULL ;
V_196 = V_183 -> V_190 - 1 ;
V_189 = & V_183 -> V_192 [ F_124 ( V_196 , V_92 ) ] ;
while ( V_196 > 0 ) {
if ( ! F_127 ( * V_189 ) )
return NULL ;
if ( F_128 ( * V_189 ) == 0x07 ) {
unsigned long V_199 , V_200 ;
V_199 = F_131 ( * V_189 ) ;
V_199 = ~ ( ( F_132 ( V_199 ) << 3 ) - 1 ) ;
V_200 = ( ( unsigned long ) V_189 ) & V_199 ;
return ( T_4 * ) V_200 ;
}
if ( F_128 ( * V_189 ) != V_196 )
return NULL ;
V_196 -= 1 ;
V_189 = F_129 ( * V_189 ) ;
V_189 = & V_189 [ F_124 ( V_196 , V_92 ) ] ;
}
return V_189 ;
}
static int F_133 ( struct V_182 * V_201 ,
unsigned long V_202 ,
unsigned long V_85 ,
int V_203 ,
unsigned long V_194 )
{
T_4 V_200 , * V_189 ;
int V_23 , V_91 ;
if ( ! ( V_203 & V_204 ) )
return - V_205 ;
V_202 = F_134 ( V_202 ) ;
V_85 = F_134 ( V_85 ) ;
V_91 = F_132 ( V_194 ) ;
V_189 = F_120 ( V_201 , V_202 , V_194 , NULL , V_5 ) ;
for ( V_23 = 0 ; V_23 < V_91 ; ++ V_23 )
if ( F_127 ( V_189 [ V_23 ] ) )
return - V_206 ;
if ( V_194 > V_152 ) {
V_200 = F_135 ( V_85 , V_194 ) ;
V_200 |= F_136 ( 7 ) | V_207 | V_208 ;
} else
V_200 = V_85 | V_207 | V_208 ;
if ( V_203 & V_209 )
V_200 |= V_210 ;
if ( V_203 & V_211 )
V_200 |= V_212 ;
for ( V_23 = 0 ; V_23 < V_91 ; ++ V_23 )
V_189 [ V_23 ] = V_200 ;
F_137 ( V_201 ) ;
return 0 ;
}
static unsigned long F_138 ( struct V_182 * V_201 ,
unsigned long V_202 ,
unsigned long V_194 )
{
unsigned long long V_213 , V_214 ;
T_4 * V_189 ;
F_121 ( ! F_122 ( V_194 ) ) ;
V_214 = 0 ;
while ( V_214 < V_194 ) {
V_189 = F_130 ( V_201 , V_202 ) ;
if ( ! V_189 ) {
V_213 = V_152 ;
} else if ( F_128 ( * V_189 ) == 0 ) {
V_213 = V_152 ;
* V_189 = 0ULL ;
} else {
int V_91 , V_23 ;
V_213 = F_131 ( * V_189 ) ;
V_91 = F_132 ( V_213 ) ;
for ( V_23 = 0 ; V_23 < V_91 ; V_23 ++ )
V_189 [ V_23 ] = 0ULL ;
}
V_202 = ( V_202 & ~ ( V_213 - 1 ) ) + V_213 ;
V_214 += V_213 ;
}
F_121 ( ! F_122 ( V_214 ) ) ;
return V_214 ;
}
static int F_139 ( struct V_53 * V_18 ,
struct V_215 * V_28 )
{
T_1 V_216 , V_23 ;
for ( V_23 = V_28 -> V_217 ; V_23 <= V_28 -> V_218 ; ++ V_23 ) {
V_216 = V_31 [ V_23 ] ;
if ( V_38 [ V_216 ] == V_18 )
return 1 ;
}
return 0 ;
}
static int F_140 ( struct V_27 * V_219 ,
struct V_215 * V_220 )
{
T_4 V_221 ;
int V_29 ;
for ( V_221 = V_220 -> V_222 ; V_221 < V_220 -> V_223 ;
V_221 += V_152 ) {
V_29 = F_133 ( & V_219 -> V_183 , V_221 , V_221 , V_220 -> V_203 ,
V_152 ) ;
if ( V_29 )
return V_29 ;
if ( V_221 < V_219 -> V_224 )
F_141 ( V_221 >> V_225 ,
V_219 -> V_226 [ 0 ] -> V_227 ) ;
}
return 0 ;
}
static int F_142 ( struct V_53 * V_18 )
{
struct V_215 * V_28 ;
int V_29 ;
F_11 (entry, &amd_iommu_unity_map, list) {
if ( ! F_139 ( V_18 , V_28 ) )
continue;
V_29 = F_140 ( V_18 -> V_228 , V_28 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_143 ( struct V_27 * V_219 ,
T_1 V_2 )
{
struct V_215 * V_220 ;
int V_29 ;
F_11 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_220 -> V_217 && V_2 <= V_220 -> V_218 ) )
continue;
V_29 = F_140 ( V_219 , V_220 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static void F_144 ( struct V_27 * V_201 ,
unsigned long V_229 ,
unsigned int V_150 )
{
unsigned int V_23 , V_230 = V_201 -> V_224 >> V_225 ;
if ( V_229 + V_150 > V_230 )
V_150 = V_230 - V_229 ;
for ( V_23 = V_229 ; V_23 < V_229 + V_150 ; ++ V_23 ) {
int V_231 = V_23 / V_232 ;
int V_198 = V_23 % V_232 ;
F_141 ( V_198 , V_201 -> V_226 [ V_231 ] -> V_227 ) ;
}
}
static int F_145 ( struct V_27 * V_219 ,
bool V_233 , T_8 V_188 )
{
int V_231 = V_219 -> V_224 >> V_234 ;
struct V_53 * V_18 ;
unsigned long V_23 , V_235 ;
#ifdef F_146
V_233 = false ;
#endif
if ( V_231 >= V_236 )
return - V_44 ;
V_219 -> V_226 [ V_231 ] = F_2 ( sizeof( struct V_237 ) , V_188 ) ;
if ( ! V_219 -> V_226 [ V_231 ] )
return - V_44 ;
V_219 -> V_226 [ V_231 ] -> V_227 = ( void * ) F_117 ( V_188 ) ;
if ( ! V_219 -> V_226 [ V_231 ] -> V_227 )
goto V_59;
V_219 -> V_226 [ V_231 ] -> V_238 = V_219 -> V_224 ;
if ( V_233 ) {
unsigned long V_92 = V_219 -> V_224 ;
int V_23 , V_239 = V_232 / 512 ;
T_4 * V_189 , * V_195 ;
for ( V_23 = 0 ; V_23 < V_239 ; ++ V_23 ) {
V_189 = F_120 ( & V_219 -> V_183 , V_92 , V_152 ,
& V_195 , V_188 ) ;
if ( ! V_189 )
goto V_59;
V_219 -> V_226 [ V_231 ] -> V_240 [ V_23 ] = V_195 ;
V_92 += V_241 / 64 ;
}
}
V_235 = V_219 -> V_224 ;
V_219 -> V_224 += V_241 ;
if ( V_235 < V_242 &&
V_219 -> V_224 > V_242 ) {
unsigned long V_243 ;
int V_150 ;
V_150 = F_90 ( V_242 , 0x10000 , V_152 ) ;
V_243 = V_242 >> V_225 ;
F_144 ( V_219 , V_243 , V_150 ) ;
}
F_77 (iommu) {
if ( V_18 -> V_244 &&
V_18 -> V_244 >= V_219 -> V_226 [ V_231 ] -> V_238
&& V_18 -> V_244 < V_219 -> V_224 ) {
unsigned long V_245 ;
int V_150 = F_90 ( V_18 -> V_244 ,
V_18 -> V_246 ,
V_152 ) ;
V_245 = V_18 -> V_244 >> V_225 ;
F_144 ( V_219 , V_245 , V_150 ) ;
}
}
for ( V_23 = V_219 -> V_226 [ V_231 ] -> V_238 ;
V_23 < V_219 -> V_224 ;
V_23 += V_152 ) {
T_4 * V_189 = F_130 ( & V_219 -> V_183 , V_23 ) ;
if ( ! V_189 || ! F_127 ( * V_189 ) )
continue;
F_144 ( V_219 , V_23 >> V_225 , 1 ) ;
}
F_137 ( & V_219 -> V_183 ) ;
return 0 ;
V_59:
F_137 ( & V_219 -> V_183 ) ;
F_147 ( ( unsigned long ) V_219 -> V_226 [ V_231 ] -> V_227 ) ;
F_9 ( V_219 -> V_226 [ V_231 ] ) ;
V_219 -> V_226 [ V_231 ] = NULL ;
return - V_44 ;
}
static unsigned long F_148 ( struct V_10 * V_11 ,
struct V_27 * V_201 ,
unsigned int V_150 ,
unsigned long V_247 ,
T_4 V_35 ,
unsigned long V_248 )
{
unsigned long V_249 = V_201 -> V_250 % V_241 ;
int V_251 = V_201 -> V_224 >> V_234 ;
int V_23 = V_248 >> V_234 ;
unsigned long V_252 ;
unsigned long V_92 = - 1 ;
unsigned long V_253 ;
V_249 >>= V_225 ;
V_252 = F_149 ( F_150 ( V_11 ) + 1 ,
V_152 ) >> V_225 ;
for (; V_23 < V_251 ; ++ V_23 ) {
unsigned long V_238 = V_201 -> V_226 [ V_23 ] -> V_238 >> V_225 ;
if ( V_201 -> V_226 [ V_23 ] -> V_238 >= V_35 )
break;
V_253 = F_151 ( V_232 , V_238 ,
V_35 >> V_225 ) ;
V_92 = F_152 ( V_201 -> V_226 [ V_23 ] -> V_227 ,
V_253 , V_249 , V_150 , 0 ,
V_252 , V_247 ) ;
if ( V_92 != - 1 ) {
V_92 = V_201 -> V_226 [ V_23 ] -> V_238 +
( V_92 << V_225 ) ;
V_201 -> V_250 = V_92 + ( V_150 << V_225 ) ;
break;
}
V_249 = 0 ;
}
return V_92 ;
}
static unsigned long F_153 ( struct V_10 * V_11 ,
struct V_27 * V_201 ,
unsigned int V_150 ,
unsigned long V_247 ,
T_4 V_35 )
{
unsigned long V_92 ;
#ifdef F_146
V_201 -> V_250 = 0 ;
V_201 -> V_254 = true ;
#endif
V_92 = F_148 ( V_11 , V_201 , V_150 , V_247 ,
V_35 , V_201 -> V_250 ) ;
if ( V_92 == - 1 ) {
V_201 -> V_250 = 0 ;
V_92 = F_148 ( V_11 , V_201 , V_150 , V_247 ,
V_35 , 0 ) ;
V_201 -> V_254 = true ;
}
if ( F_154 ( V_92 == - 1 ) )
V_92 = V_255 ;
F_83 ( ( V_92 + ( V_152 * V_150 ) ) > V_201 -> V_224 ) ;
return V_92 ;
}
static void F_155 ( struct V_27 * V_201 ,
unsigned long V_92 ,
unsigned int V_150 )
{
unsigned V_23 = V_92 >> V_234 ;
struct V_237 * V_256 = V_201 -> V_226 [ V_23 ] ;
F_121 ( V_23 >= V_236 || V_256 == NULL ) ;
#ifdef F_146
if ( V_23 < 4 )
return;
#endif
if ( V_92 >= V_201 -> V_250 )
V_201 -> V_254 = true ;
V_92 = ( V_92 % V_241 ) >> V_225 ;
F_156 ( V_256 -> V_227 , V_92 , V_150 ) ;
}
static void F_157 ( struct V_182 * V_183 )
{
unsigned long V_4 ;
F_4 ( & V_257 , V_4 ) ;
F_158 ( & V_183 -> V_258 , & V_259 ) ;
F_6 ( & V_257 , V_4 ) ;
}
static void F_159 ( struct V_182 * V_183 )
{
unsigned long V_4 ;
F_4 ( & V_257 , V_4 ) ;
F_8 ( & V_183 -> V_258 ) ;
F_6 ( & V_257 , V_4 ) ;
}
static T_1 F_160 ( void )
{
unsigned long V_4 ;
int V_184 ;
F_161 ( & V_260 , V_4 ) ;
V_184 = F_162 ( V_261 , V_262 ) ;
F_121 ( V_184 == 0 ) ;
if ( V_184 > 0 && V_184 < V_262 )
F_141 ( V_184 , V_261 ) ;
else
V_184 = 0 ;
F_163 ( & V_260 , V_4 ) ;
return V_184 ;
}
static void F_164 ( int V_184 )
{
unsigned long V_4 ;
F_161 ( & V_260 , V_4 ) ;
if ( V_184 > 0 && V_184 < V_262 )
F_165 ( V_184 , V_261 ) ;
F_163 ( & V_260 , V_4 ) ;
}
static void F_166 ( struct V_182 * V_183 )
{
int V_23 , V_263 ;
T_4 * V_264 , * V_265 , * V_266 ;
V_264 = V_183 -> V_192 ;
if ( ! V_264 )
return;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! F_127 ( V_264 [ V_23 ] ) )
continue;
V_265 = F_129 ( V_264 [ V_23 ] ) ;
for ( V_263 = 0 ; V_263 < 512 ; ++ V_263 ) {
if ( ! F_127 ( V_265 [ V_263 ] ) )
continue;
V_266 = F_129 ( V_265 [ V_263 ] ) ;
F_147 ( ( unsigned long ) V_266 ) ;
}
F_147 ( ( unsigned long ) V_265 ) ;
}
F_147 ( ( unsigned long ) V_264 ) ;
V_183 -> V_192 = NULL ;
}
static void F_167 ( T_4 * V_267 )
{
T_4 * V_268 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_267 [ V_23 ] & V_269 ) )
continue;
V_268 = F_168 ( V_267 [ V_23 ] & V_154 ) ;
F_147 ( ( unsigned long ) V_268 ) ;
}
}
static void F_169 ( T_4 * V_267 )
{
T_4 * V_268 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_267 [ V_23 ] & V_269 ) )
continue;
V_268 = F_168 ( V_267 [ V_23 ] & V_154 ) ;
F_167 ( V_268 ) ;
}
}
static void F_170 ( struct V_182 * V_183 )
{
if ( V_183 -> V_270 == 2 )
F_169 ( V_183 -> V_271 ) ;
else if ( V_183 -> V_270 == 1 )
F_167 ( V_183 -> V_271 ) ;
else if ( V_183 -> V_270 != 0 )
F_171 () ;
F_147 ( ( unsigned long ) V_183 -> V_271 ) ;
}
static void F_172 ( struct V_27 * V_201 )
{
int V_23 ;
if ( ! V_201 )
return;
F_159 ( & V_201 -> V_183 ) ;
F_166 ( & V_201 -> V_183 ) ;
for ( V_23 = 0 ; V_23 < V_236 ; ++ V_23 ) {
if ( ! V_201 -> V_226 [ V_23 ] )
continue;
F_147 ( ( unsigned long ) V_201 -> V_226 [ V_23 ] -> V_227 ) ;
F_9 ( V_201 -> V_226 [ V_23 ] ) ;
}
F_9 ( V_201 ) ;
}
static struct V_27 * F_173 ( void )
{
struct V_27 * V_219 ;
V_219 = F_2 ( sizeof( struct V_27 ) , V_5 ) ;
if ( ! V_219 )
return NULL ;
F_174 ( & V_219 -> V_183 . V_114 ) ;
V_219 -> V_183 . V_184 = F_160 () ;
if ( V_219 -> V_183 . V_184 == 0 )
goto V_272;
F_175 ( & V_219 -> V_183 . V_273 ) ;
V_219 -> V_183 . V_190 = V_274 ;
V_219 -> V_183 . V_192 = ( void * ) F_117 ( V_5 ) ;
V_219 -> V_183 . V_4 = V_275 ;
V_219 -> V_183 . V_276 = V_219 ;
if ( ! V_219 -> V_183 . V_192 )
goto V_272;
V_219 -> V_254 = false ;
V_219 -> V_34 = 0xffff ;
F_157 ( & V_219 -> V_183 ) ;
if ( F_145 ( V_219 , true , V_5 ) )
goto V_272;
V_219 -> V_226 [ 0 ] -> V_227 [ 0 ] = 1 ;
V_219 -> V_250 = 0 ;
return V_219 ;
V_272:
F_172 ( V_219 ) ;
return NULL ;
}
static bool V_27 ( struct V_182 * V_183 )
{
return V_183 -> V_4 & V_275 ;
}
static void F_176 ( T_1 V_2 , struct V_182 * V_183 , bool V_180 )
{
T_4 V_277 = 0 ;
T_4 V_4 = 0 ;
if ( V_183 -> V_190 != V_278 )
V_277 = F_119 ( V_183 -> V_192 ) ;
V_277 |= ( V_183 -> V_190 & V_279 )
<< V_280 ;
V_277 |= V_210 | V_212 | V_207 | V_281 ;
V_4 = V_56 [ V_2 ] . V_84 [ 1 ] ;
if ( V_180 )
V_4 |= V_282 ;
if ( V_183 -> V_4 & V_283 ) {
T_4 V_284 = F_85 ( V_183 -> V_271 ) ;
T_4 V_270 = V_183 -> V_270 ;
T_4 V_285 ;
V_277 |= V_286 ;
V_277 |= ( V_270 & V_287 ) << V_288 ;
V_285 = F_177 ( ~ 0ULL ) << V_289 ;
V_4 &= ~ V_285 ;
V_285 = F_178 ( ~ 0ULL ) << V_290 ;
V_4 &= ~ V_285 ;
V_285 = F_179 ( V_284 ) << V_291 ;
V_277 |= V_285 ;
V_285 = F_177 ( V_284 ) << V_289 ;
V_4 |= V_285 ;
V_285 = F_178 ( V_284 ) << V_290 ;
V_4 |= V_285 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_183 -> V_184 ;
V_56 [ V_2 ] . V_84 [ 1 ] = V_4 ;
V_56 [ V_2 ] . V_84 [ 0 ] = V_277 ;
}
static void F_180 ( T_1 V_2 )
{
V_56 [ V_2 ] . V_84 [ 0 ] = V_207 | V_281 ;
V_56 [ V_2 ] . V_84 [ 1 ] = 0 ;
F_181 ( V_2 ) ;
}
static void F_182 ( struct V_1 * V_3 ,
struct V_182 * V_183 )
{
struct V_53 * V_18 ;
bool V_180 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_180 = V_3 -> V_180 . V_181 ;
V_3 -> V_183 = V_183 ;
F_158 ( & V_3 -> V_258 , & V_183 -> V_273 ) ;
F_176 ( V_3 -> V_2 , V_183 , V_180 ) ;
V_183 -> V_186 [ V_18 -> V_231 ] += 1 ;
V_183 -> V_292 += 1 ;
F_109 ( V_3 ) ;
}
static void F_183 ( struct V_1 * V_3 )
{
struct V_53 * V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
V_3 -> V_183 -> V_186 [ V_18 -> V_231 ] -= 1 ;
V_3 -> V_183 -> V_292 -= 1 ;
V_3 -> V_183 = NULL ;
F_8 ( & V_3 -> V_258 ) ;
F_180 ( V_3 -> V_2 ) ;
F_109 ( V_3 ) ;
}
static int F_184 ( struct V_1 * V_3 ,
struct V_182 * V_183 )
{
int V_29 ;
F_185 ( & V_183 -> V_114 ) ;
if ( V_3 -> V_45 != NULL ) {
struct V_1 * V_45 = V_3 -> V_45 ;
V_29 = - V_206 ;
if ( V_45 -> V_183 != NULL &&
V_45 -> V_183 != V_183 )
goto V_9;
if ( V_3 -> V_183 != NULL &&
V_3 -> V_183 != V_183 )
goto V_9;
if ( V_45 -> V_183 == NULL )
F_182 ( V_45 , V_183 ) ;
F_186 ( & V_45 -> V_6 ) ;
}
if ( V_3 -> V_183 == NULL )
F_182 ( V_3 , V_183 ) ;
F_186 ( & V_3 -> V_6 ) ;
V_29 = 0 ;
V_9:
F_187 ( & V_183 -> V_114 ) ;
return V_29 ;
}
static void F_188 ( struct V_12 * V_13 )
{
F_189 ( V_13 ) ;
F_190 ( V_13 ) ;
F_191 ( V_13 ) ;
}
static int F_192 ( struct V_12 * V_13 )
{
T_1 V_293 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return - V_205 ;
F_193 ( V_13 , V_24 + V_294 , & V_293 ) ;
V_293 |= V_295 ;
F_194 ( V_13 , V_24 + V_294 , V_293 ) ;
return 0 ;
}
static int F_195 ( struct V_12 * V_13 )
{
bool V_296 ;
int V_297 , V_29 ;
V_297 = 32 ;
if ( F_19 ( V_13 , V_298 ) )
V_297 = 1 ;
V_296 = F_19 ( V_13 , V_299 ) ;
V_29 = F_196 ( V_13 , 0 ) ;
if ( V_29 )
goto V_300;
V_29 = F_197 ( V_13 ) ;
if ( V_29 )
goto V_300;
V_29 = F_198 ( V_13 , V_297 ) ;
if ( V_29 )
goto V_300;
if ( V_296 ) {
V_29 = F_192 ( V_13 ) ;
if ( V_29 )
goto V_300;
}
V_29 = F_199 ( V_13 , V_225 ) ;
if ( V_29 )
goto V_300;
return 0 ;
V_300:
F_190 ( V_13 ) ;
F_191 ( V_13 ) ;
return V_29 ;
}
static bool F_200 ( struct V_12 * V_13 )
{
T_1 V_162 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return false ;
F_193 ( V_13 , V_24 + V_301 , & V_162 ) ;
return ( V_162 & V_302 ) ? true : false ;
}
static int F_201 ( struct V_10 * V_11 ,
struct V_182 * V_183 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_29 ;
V_3 = F_16 ( V_11 ) ;
if ( V_183 -> V_4 & V_283 ) {
if ( ! V_3 -> V_54 || ! V_3 -> V_303 )
return - V_205 ;
if ( F_195 ( V_13 ) != 0 )
return - V_205 ;
V_3 -> V_180 . V_181 = true ;
V_3 -> V_180 . V_158 = F_202 ( V_13 ) ;
V_3 -> V_304 = F_200 ( V_13 ) ;
} else if ( V_305 &&
F_199 ( V_13 , V_225 ) == 0 ) {
V_3 -> V_180 . V_181 = true ;
V_3 -> V_180 . V_158 = F_202 ( V_13 ) ;
}
F_161 ( & V_260 , V_4 ) ;
V_29 = F_184 ( V_3 , V_183 ) ;
F_163 ( & V_260 , V_4 ) ;
F_113 ( V_183 ) ;
return V_29 ;
}
static void F_203 ( struct V_1 * V_3 )
{
struct V_182 * V_183 ;
unsigned long V_4 ;
F_121 ( ! V_3 -> V_183 ) ;
V_183 = V_3 -> V_183 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
if ( V_3 -> V_45 != NULL ) {
struct V_1 * V_45 = V_3 -> V_45 ;
if ( F_204 ( & V_45 -> V_6 ) )
F_183 ( V_45 ) ;
}
if ( F_204 ( & V_3 -> V_6 ) )
F_183 ( V_3 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
if ( V_3 -> V_303 &&
( V_3 -> V_183 == NULL && V_183 != V_306 ) )
F_184 ( V_3 , V_306 ) ;
}
static void F_205 ( struct V_10 * V_11 )
{
struct V_182 * V_183 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
V_183 = V_3 -> V_183 ;
F_161 ( & V_260 , V_4 ) ;
F_203 ( V_3 ) ;
F_163 ( & V_260 , V_4 ) ;
if ( V_183 -> V_4 & V_283 )
F_188 ( F_14 ( V_11 ) ) ;
else if ( V_3 -> V_180 . V_181 )
F_189 ( F_14 ( V_11 ) ) ;
V_3 -> V_180 . V_181 = false ;
}
static struct V_182 * F_206 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
struct V_182 * V_201 = NULL ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
if ( V_3 -> V_183 )
return V_3 -> V_183 ;
if ( V_3 -> V_45 != NULL ) {
struct V_1 * V_45 = V_3 -> V_45 ;
F_207 ( & V_260 , V_4 ) ;
if ( V_45 -> V_183 != NULL ) {
F_184 ( V_3 , V_45 -> V_183 ) ;
V_201 = V_45 -> V_183 ;
}
F_208 ( & V_260 , V_4 ) ;
}
return V_201 ;
}
static int F_209 ( struct V_307 * V_308 ,
unsigned long V_309 , void * V_84 )
{
struct V_27 * V_310 ;
struct V_182 * V_183 ;
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
switch ( V_309 ) {
case V_311 :
V_183 = F_206 ( V_11 ) ;
if ( ! V_183 )
goto V_312;
if ( V_3 -> V_303 )
break;
F_205 ( V_11 ) ;
break;
case V_313 :
F_25 ( V_11 ) ;
V_3 = F_16 ( V_11 ) ;
if ( V_314 || V_3 -> V_54 ) {
V_3 -> V_303 = true ;
F_201 ( V_11 , V_306 ) ;
break;
}
V_183 = F_206 ( V_11 ) ;
V_310 = F_20 ( V_2 ) ;
if ( V_310 )
goto V_312;
V_310 = F_173 () ;
if ( ! V_310 )
goto V_312;
V_310 -> V_34 = V_2 ;
F_4 ( & V_33 , V_4 ) ;
F_5 ( & V_310 -> V_258 , & V_32 ) ;
F_6 ( & V_33 , V_4 ) ;
V_3 = F_16 ( V_11 ) ;
V_11 -> V_17 . V_315 = & V_316 ;
break;
case V_317 :
F_44 ( V_11 ) ;
default:
goto V_312;
}
F_99 ( V_18 ) ;
V_312:
return 0 ;
}
void F_210 ( void )
{
F_211 ( & V_36 , & V_318 ) ;
}
static struct V_182 * F_212 ( struct V_10 * V_11 )
{
struct V_182 * V_183 ;
struct V_27 * V_219 ;
T_1 V_2 = F_13 ( V_11 ) ;
if ( ! F_22 ( V_11 ) )
return F_213 ( - V_205 ) ;
V_183 = F_206 ( V_11 ) ;
if ( V_183 != NULL && ! V_27 ( V_183 ) )
return F_213 ( - V_206 ) ;
if ( V_183 != NULL )
return V_183 ;
V_219 = F_20 ( V_2 ) ;
if ( ! V_219 )
V_219 = V_38 [ V_2 ] -> V_228 ;
F_201 ( V_11 , & V_219 -> V_183 ) ;
F_214 ( L_23 ,
V_219 -> V_183 . V_184 , F_27 ( V_11 ) ) ;
return & V_219 -> V_183 ;
}
static void F_215 ( struct V_182 * V_183 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_176 ( V_3 -> V_2 , V_183 , V_3 -> V_180 . V_181 ) ;
}
static void F_137 ( struct V_182 * V_183 )
{
if ( ! V_183 -> V_193 )
return;
F_215 ( V_183 ) ;
F_115 ( V_183 ) ;
F_113 ( V_183 ) ;
V_183 -> V_193 = false ;
}
static T_4 * F_216 ( struct V_27 * V_201 ,
unsigned long V_92 )
{
struct V_237 * V_226 ;
T_4 * V_189 , * V_195 ;
V_226 = V_201 -> V_226 [ F_217 ( V_92 ) ] ;
if ( ! V_226 )
return NULL ;
V_189 = V_226 -> V_240 [ F_218 ( V_92 ) ] ;
if ( ! V_189 ) {
V_189 = F_120 ( & V_201 -> V_183 , V_92 , V_152 , & V_195 ,
V_319 ) ;
V_226 -> V_240 [ F_218 ( V_92 ) ] = V_195 ;
} else
V_189 += F_124 ( 0 , V_92 ) ;
F_137 ( & V_201 -> V_183 ) ;
return V_189 ;
}
static T_9 F_219 ( struct V_27 * V_201 ,
unsigned long V_92 ,
T_10 V_320 ,
int V_321 )
{
T_4 * V_189 , V_200 ;
F_83 ( V_92 > V_201 -> V_224 ) ;
V_320 &= V_154 ;
V_189 = F_216 ( V_201 , V_92 ) ;
if ( ! V_189 )
return V_255 ;
V_200 = V_320 | V_207 | V_208 ;
if ( V_321 == V_322 )
V_200 |= V_210 ;
else if ( V_321 == V_323 )
V_200 |= V_212 ;
else if ( V_321 == V_324 )
V_200 |= V_210 | V_212 ;
F_83 ( * V_189 ) ;
* V_189 = V_200 ;
return ( T_9 ) V_92 ;
}
static void F_220 ( struct V_27 * V_201 ,
unsigned long V_92 )
{
struct V_237 * V_226 ;
T_4 * V_189 ;
if ( V_92 >= V_201 -> V_224 )
return;
V_226 = V_201 -> V_226 [ F_217 ( V_92 ) ] ;
if ( ! V_226 )
return;
V_189 = V_226 -> V_240 [ F_218 ( V_92 ) ] ;
if ( ! V_189 )
return;
V_189 += F_124 ( 0 , V_92 ) ;
F_83 ( ! * V_189 ) ;
* V_189 = 0ULL ;
}
static T_9 F_221 ( struct V_10 * V_11 ,
struct V_27 * V_219 ,
T_10 V_320 ,
T_7 V_148 ,
int V_325 ,
bool V_326 ,
T_4 V_35 )
{
T_9 V_238 = V_320 & ~ V_154 ;
T_9 V_92 , V_248 , V_29 ;
unsigned int V_150 ;
unsigned long V_247 = 0 ;
int V_23 ;
V_150 = F_90 ( V_320 , V_148 , V_152 ) ;
V_320 &= V_154 ;
F_67 ( V_79 ) ;
if ( V_150 > 1 )
F_67 ( V_75 ) ;
if ( V_326 )
V_247 = ( 1UL << F_222 ( V_148 ) ) - 1 ;
V_93:
V_92 = F_153 ( V_11 , V_219 , V_150 , V_247 ,
V_35 ) ;
if ( F_154 ( V_92 == V_255 ) ) {
V_219 -> V_250 = V_219 -> V_224 ;
if ( F_145 ( V_219 , false , V_319 ) )
goto V_312;
goto V_93;
}
V_248 = V_92 ;
for ( V_23 = 0 ; V_23 < V_150 ; ++ V_23 ) {
V_29 = F_219 ( V_219 , V_248 , V_320 , V_325 ) ;
if ( V_29 == V_255 )
goto V_327;
V_320 += V_152 ;
V_248 += V_152 ;
}
V_92 += V_238 ;
F_223 ( V_78 , V_148 ) ;
if ( F_154 ( V_219 -> V_254 && ! V_67 ) ) {
F_112 ( & V_219 -> V_183 ) ;
V_219 -> V_254 = false ;
} else if ( F_154 ( V_328 ) )
F_111 ( & V_219 -> V_183 , V_92 , V_148 ) ;
V_312:
return V_92 ;
V_327:
for ( -- V_23 ; V_23 >= 0 ; -- V_23 ) {
V_248 -= V_152 ;
F_220 ( V_219 , V_248 ) ;
}
F_155 ( V_219 , V_92 , V_150 ) ;
return V_255 ;
}
static void F_224 ( struct V_27 * V_219 ,
T_9 V_329 ,
T_7 V_148 ,
int V_325 )
{
T_9 V_330 ;
T_9 V_23 , V_248 ;
unsigned int V_150 ;
if ( ( V_329 == V_255 ) ||
( V_329 + V_148 > V_219 -> V_224 ) )
return;
V_330 = V_329 ;
V_150 = F_90 ( V_329 , V_148 , V_152 ) ;
V_329 &= V_154 ;
V_248 = V_329 ;
for ( V_23 = 0 ; V_23 < V_150 ; ++ V_23 ) {
F_220 ( V_219 , V_248 ) ;
V_248 += V_152 ;
}
F_225 ( V_78 , V_148 ) ;
F_155 ( V_219 , V_329 , V_150 ) ;
if ( V_67 || V_219 -> V_254 ) {
F_111 ( & V_219 -> V_183 , V_330 , V_148 ) ;
V_219 -> V_254 = false ;
}
}
static T_9 F_226 ( struct V_10 * V_11 , struct V_198 * V_198 ,
unsigned long V_238 , T_7 V_148 ,
enum V_331 V_325 ,
struct V_332 * V_333 )
{
unsigned long V_4 ;
struct V_182 * V_183 ;
T_9 V_221 ;
T_4 V_35 ;
T_10 V_320 = F_227 ( V_198 ) + V_238 ;
F_67 ( V_69 ) ;
V_183 = F_212 ( V_11 ) ;
if ( F_40 ( V_183 ) == - V_205 )
return ( T_9 ) V_320 ;
else if ( F_39 ( V_183 ) )
return V_255 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
V_221 = F_221 ( V_11 , V_183 -> V_276 , V_320 , V_148 , V_325 , false ,
V_35 ) ;
if ( V_221 == V_255 )
goto V_312;
F_114 ( V_183 ) ;
V_312:
F_6 ( & V_183 -> V_114 , V_4 ) ;
return V_221 ;
}
static void F_228 ( struct V_10 * V_11 , T_9 V_329 , T_7 V_148 ,
enum V_331 V_325 , struct V_332 * V_333 )
{
unsigned long V_4 ;
struct V_182 * V_183 ;
F_67 ( V_70 ) ;
V_183 = F_212 ( V_11 ) ;
if ( F_39 ( V_183 ) )
return;
F_4 ( & V_183 -> V_114 , V_4 ) ;
F_224 ( V_183 -> V_276 , V_329 , V_148 , V_325 ) ;
F_114 ( V_183 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
}
static int F_229 ( struct V_10 * V_11 , struct V_334 * V_335 ,
int V_336 , int V_325 )
{
struct V_334 * V_151 ;
int V_23 ;
F_230 (sglist, s, nelems, i) {
V_151 -> V_337 = ( T_9 ) F_231 ( V_151 ) ;
V_151 -> V_338 = V_151 -> V_339 ;
}
return V_336 ;
}
static int F_232 ( struct V_10 * V_11 , struct V_334 * V_335 ,
int V_336 , enum V_331 V_325 ,
struct V_332 * V_333 )
{
unsigned long V_4 ;
struct V_182 * V_183 ;
int V_23 ;
struct V_334 * V_151 ;
T_10 V_320 ;
int V_340 = 0 ;
T_4 V_35 ;
F_67 ( V_71 ) ;
V_183 = F_212 ( V_11 ) ;
if ( F_40 ( V_183 ) == - V_205 )
return F_229 ( V_11 , V_335 , V_336 , V_325 ) ;
else if ( F_39 ( V_183 ) )
return 0 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
F_230 (sglist, s, nelems, i) {
V_320 = F_231 ( V_151 ) ;
V_151 -> V_337 = F_221 ( V_11 , V_183 -> V_276 ,
V_320 , V_151 -> V_339 , V_325 , false ,
V_35 ) ;
if ( V_151 -> V_337 ) {
V_151 -> V_338 = V_151 -> V_339 ;
V_340 ++ ;
} else
goto V_341;
}
F_114 ( V_183 ) ;
V_312:
F_6 ( & V_183 -> V_114 , V_4 ) ;
return V_340 ;
V_341:
F_230 (sglist, s, mapped_elems, i) {
if ( V_151 -> V_337 )
F_224 ( V_183 -> V_276 , V_151 -> V_337 ,
V_151 -> V_338 , V_325 ) ;
V_151 -> V_337 = V_151 -> V_338 = 0 ;
}
V_340 = 0 ;
goto V_312;
}
static void F_233 ( struct V_10 * V_11 , struct V_334 * V_335 ,
int V_336 , enum V_331 V_325 ,
struct V_332 * V_333 )
{
unsigned long V_4 ;
struct V_182 * V_183 ;
struct V_334 * V_151 ;
int V_23 ;
F_67 ( V_72 ) ;
V_183 = F_212 ( V_11 ) ;
if ( F_39 ( V_183 ) )
return;
F_4 ( & V_183 -> V_114 , V_4 ) ;
F_230 (sglist, s, nelems, i) {
F_224 ( V_183 -> V_276 , V_151 -> V_337 ,
V_151 -> V_338 , V_325 ) ;
V_151 -> V_337 = V_151 -> V_338 = 0 ;
}
F_114 ( V_183 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
}
static void * F_234 ( struct V_10 * V_11 , T_7 V_148 ,
T_9 * V_329 , T_8 V_342 ,
struct V_332 * V_333 )
{
unsigned long V_4 ;
void * V_343 ;
struct V_182 * V_183 ;
T_10 V_320 ;
T_4 V_35 = V_11 -> V_344 ;
F_67 ( V_73 ) ;
V_183 = F_212 ( V_11 ) ;
if ( F_40 ( V_183 ) == - V_205 ) {
V_343 = ( void * ) F_235 ( V_342 , F_222 ( V_148 ) ) ;
* V_329 = F_85 ( V_343 ) ;
return V_343 ;
} else if ( F_39 ( V_183 ) )
return NULL ;
V_35 = V_11 -> V_344 ;
V_342 &= ~ ( V_345 | V_346 | V_347 ) ;
V_342 |= V_348 ;
V_343 = ( void * ) F_235 ( V_342 , F_222 ( V_148 ) ) ;
if ( ! V_343 )
return NULL ;
V_320 = F_119 ( V_343 ) ;
if ( ! V_35 )
V_35 = * V_11 -> V_35 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
* V_329 = F_221 ( V_11 , V_183 -> V_276 , V_320 ,
V_148 , V_324 , true , V_35 ) ;
if ( * V_329 == V_255 ) {
F_6 ( & V_183 -> V_114 , V_4 ) ;
goto V_59;
}
F_114 ( V_183 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
return V_343 ;
V_59:
F_236 ( ( unsigned long ) V_343 , F_222 ( V_148 ) ) ;
return NULL ;
}
static void F_237 ( struct V_10 * V_11 , T_7 V_148 ,
void * V_343 , T_9 V_329 ,
struct V_332 * V_333 )
{
unsigned long V_4 ;
struct V_182 * V_183 ;
F_67 ( V_74 ) ;
V_183 = F_212 ( V_11 ) ;
if ( F_39 ( V_183 ) )
goto V_349;
F_4 ( & V_183 -> V_114 , V_4 ) ;
F_224 ( V_183 -> V_276 , V_329 , V_148 , V_324 ) ;
F_114 ( V_183 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
V_349:
F_236 ( ( unsigned long ) V_343 , F_222 ( V_148 ) ) ;
}
static int F_238 ( struct V_10 * V_11 , T_4 V_350 )
{
return F_22 ( V_11 ) ;
}
static void T_3 F_239 ( void )
{
struct V_1 * V_3 ;
struct V_27 * V_219 ;
struct V_12 * V_11 = NULL ;
T_1 V_2 ;
F_47 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
if ( ! V_351 && V_3 -> V_54 ) {
F_240 () ;
V_3 -> V_303 = true ;
F_201 ( & V_11 -> V_11 , V_306 ) ;
F_241 ( L_24 ,
F_27 ( & V_11 -> V_11 ) ) ;
}
if ( F_206 ( & V_11 -> V_11 ) )
continue;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_219 = F_173 () ;
if ( ! V_219 )
continue;
F_143 ( V_219 , V_2 ) ;
V_219 -> V_34 = V_2 ;
F_201 ( & V_11 -> V_11 , & V_219 -> V_183 ) ;
F_5 ( & V_219 -> V_258 , & V_32 ) ;
}
}
static unsigned F_242 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_13 = NULL ;
unsigned V_352 = 0 ;
F_47 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) ) {
F_43 ( & V_13 -> V_11 ) ;
V_352 += 1 ;
continue;
}
V_3 = F_16 ( & V_13 -> V_11 ) ;
if ( ! V_3 -> V_303 )
V_13 -> V_11 . V_17 . V_315 = & V_316 ;
else
V_13 -> V_11 . V_17 . V_315 = & V_353 ;
}
return V_352 ;
}
void T_3 F_243 ( void )
{
F_244 ( & V_36 , & V_354 ) ;
}
int T_3 F_245 ( void )
{
struct V_53 * V_18 ;
int V_29 , V_352 ;
F_77 (iommu) {
V_18 -> V_228 = F_173 () ;
if ( V_18 -> V_228 == NULL )
return - V_44 ;
V_18 -> V_228 -> V_183 . V_4 |= V_355 ;
V_29 = F_142 ( V_18 ) ;
if ( V_29 )
goto V_356;
}
F_239 () ;
V_357 = 1 ;
V_358 = 0 ;
V_352 = F_242 () ;
if ( V_352 && V_359 > V_360 ) {
V_358 = 1 ;
}
F_52 () ;
if ( V_67 )
F_241 ( L_25 ) ;
else
F_241 ( L_26 ) ;
return 0 ;
V_356:
F_77 (iommu) {
if ( V_18 -> V_228 )
F_172 ( V_18 -> V_228 ) ;
}
return V_29 ;
}
static void F_246 ( struct V_182 * V_183 )
{
struct V_1 * V_3 , * V_361 ;
unsigned long V_4 ;
F_161 ( & V_260 , V_4 ) ;
F_48 (dev_data, next, &domain->dev_list, list) {
F_203 ( V_3 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
}
F_163 ( & V_260 , V_4 ) ;
}
static void F_247 ( struct V_182 * V_183 )
{
if ( ! V_183 )
return;
F_159 ( V_183 ) ;
if ( V_183 -> V_184 )
F_164 ( V_183 -> V_184 ) ;
F_9 ( V_183 ) ;
}
static struct V_182 * F_248 ( void )
{
struct V_182 * V_183 ;
V_183 = F_2 ( sizeof( * V_183 ) , V_5 ) ;
if ( ! V_183 )
return NULL ;
F_174 ( & V_183 -> V_114 ) ;
F_249 ( & V_183 -> V_362 ) ;
V_183 -> V_184 = F_160 () ;
if ( ! V_183 -> V_184 )
goto V_300;
F_175 ( & V_183 -> V_273 ) ;
F_157 ( V_183 ) ;
return V_183 ;
V_300:
F_9 ( V_183 ) ;
return NULL ;
}
static int T_3 F_240 ( void )
{
if ( V_306 != NULL )
return 0 ;
V_306 = F_248 () ;
if ( ! V_306 )
return - V_44 ;
V_306 -> V_190 = V_278 ;
return 0 ;
}
static int F_250 ( struct V_363 * V_201 )
{
struct V_182 * V_183 ;
V_183 = F_248 () ;
if ( ! V_183 )
goto V_59;
V_183 -> V_190 = V_364 ;
V_183 -> V_192 = ( void * ) F_117 ( V_5 ) ;
if ( ! V_183 -> V_192 )
goto V_59;
V_183 -> V_363 = V_201 ;
V_201 -> V_276 = V_183 ;
V_201 -> V_365 . V_366 = 0 ;
V_201 -> V_365 . V_367 = ~ 0ULL ;
V_201 -> V_365 . V_368 = true ;
return 0 ;
V_59:
F_247 ( V_183 ) ;
return - V_44 ;
}
static void F_251 ( struct V_363 * V_201 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
if ( ! V_183 )
return;
if ( V_183 -> V_292 > 0 )
F_246 ( V_183 ) ;
F_121 ( V_183 -> V_292 != 0 ) ;
if ( V_183 -> V_190 != V_278 )
F_166 ( V_183 ) ;
if ( V_183 -> V_4 & V_283 )
F_170 ( V_183 ) ;
F_247 ( V_183 ) ;
V_201 -> V_276 = NULL ;
}
static void F_252 ( struct V_363 * V_201 ,
struct V_10 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_17 . V_18 ;
struct V_53 * V_18 ;
T_1 V_2 ;
if ( ! F_22 ( V_11 ) )
return;
V_2 = F_13 ( V_11 ) ;
if ( V_3 -> V_183 != NULL )
F_205 ( V_11 ) ;
V_18 = V_38 [ V_2 ] ;
if ( ! V_18 )
return;
F_99 ( V_18 ) ;
}
static int F_253 ( struct V_363 * V_201 ,
struct V_10 * V_11 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
struct V_1 * V_3 ;
struct V_53 * V_18 ;
int V_29 ;
if ( ! F_22 ( V_11 ) )
return - V_205 ;
V_3 = V_11 -> V_17 . V_18 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
if ( ! V_18 )
return - V_205 ;
if ( V_3 -> V_183 )
F_205 ( V_11 ) ;
V_29 = F_201 ( V_11 , V_183 ) ;
F_99 ( V_18 ) ;
return V_29 ;
}
static int F_254 ( struct V_363 * V_201 , unsigned long V_369 ,
T_10 V_320 , T_7 V_194 , int V_370 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
int V_203 = 0 ;
int V_29 ;
if ( V_183 -> V_190 == V_278 )
return - V_205 ;
if ( V_370 & V_371 )
V_203 |= V_209 ;
if ( V_370 & V_372 )
V_203 |= V_211 ;
F_255 ( & V_183 -> V_362 ) ;
V_29 = F_133 ( V_183 , V_369 , V_320 , V_203 , V_194 ) ;
F_256 ( & V_183 -> V_362 ) ;
return V_29 ;
}
static T_7 F_257 ( struct V_363 * V_201 , unsigned long V_369 ,
T_7 V_194 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
T_7 V_213 ;
if ( V_183 -> V_190 == V_278 )
return - V_205 ;
F_255 ( & V_183 -> V_362 ) ;
V_213 = F_138 ( V_183 , V_369 , V_194 ) ;
F_256 ( & V_183 -> V_362 ) ;
F_113 ( V_183 ) ;
return V_213 ;
}
static T_10 F_258 ( struct V_363 * V_201 ,
unsigned long V_369 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
unsigned long V_373 ;
T_10 V_320 ;
T_4 * V_189 , V_200 ;
if ( V_183 -> V_190 == V_278 )
return V_369 ;
V_189 = F_130 ( V_183 , V_369 ) ;
if ( ! V_189 || ! F_127 ( * V_189 ) )
return 0 ;
if ( F_128 ( * V_189 ) == 0 )
V_373 = V_152 - 1 ;
else
V_373 = F_131 ( * V_189 ) - 1 ;
V_200 = * V_189 & V_374 ;
V_320 = ( V_200 & ~ V_373 ) | ( V_369 & V_373 ) ;
return V_320 ;
}
static int F_259 ( struct V_363 * V_183 ,
unsigned long V_375 )
{
switch ( V_375 ) {
case V_376 :
return 1 ;
case V_377 :
return V_378 ;
}
return 0 ;
}
int T_3 F_260 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_11 = NULL ;
struct V_53 * V_18 ;
T_1 V_2 ;
int V_29 ;
V_29 = F_240 () ;
if ( V_29 )
return V_29 ;
F_47 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
V_3 -> V_303 = true ;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_18 = V_38 [ V_2 ] ;
if ( ! V_18 )
continue;
F_201 ( & V_11 -> V_11 , V_306 ) ;
}
F_52 () ;
F_241 ( L_27 ) ;
return 0 ;
}
int F_261 ( struct V_307 * V_308 )
{
return F_262 ( & V_128 , V_308 ) ;
}
int F_263 ( struct V_307 * V_308 )
{
return F_264 ( & V_128 , V_308 ) ;
}
void F_265 ( struct V_363 * V_201 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
unsigned long V_4 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
V_183 -> V_190 = V_278 ;
V_183 -> V_193 = true ;
F_137 ( V_183 ) ;
F_166 ( V_183 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
}
int F_266 ( struct V_363 * V_201 , int V_379 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
unsigned long V_4 ;
int V_380 , V_29 ;
if ( V_379 <= 0 || V_379 > ( V_160 + 1 ) )
return - V_205 ;
for ( V_380 = 0 ; ( V_379 - 1 ) & ~ 0x1ff ; V_379 >>= 9 )
V_380 += 1 ;
if ( V_380 > V_381 )
return - V_205 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
V_29 = - V_206 ;
if ( V_183 -> V_292 > 0 || V_183 -> V_4 & V_283 )
goto V_312;
V_29 = - V_44 ;
V_183 -> V_271 = ( void * ) F_117 ( V_319 ) ;
if ( V_183 -> V_271 == NULL )
goto V_312;
V_183 -> V_270 = V_380 ;
V_183 -> V_4 |= V_283 ;
V_183 -> V_193 = true ;
F_137 ( V_183 ) ;
V_29 = 0 ;
V_312:
F_6 ( & V_183 -> V_114 , V_4 ) ;
return V_29 ;
}
static int F_267 ( struct V_182 * V_183 , int V_125 ,
T_4 V_92 , bool V_148 )
{
struct V_1 * V_3 ;
struct V_86 V_87 ;
int V_23 , V_29 ;
if ( ! ( V_183 -> V_4 & V_283 ) )
return - V_205 ;
F_92 ( & V_87 , V_183 -> V_184 , V_125 , V_92 , V_148 ) ;
for ( V_23 = 0 ; V_23 < V_185 ; ++ V_23 ) {
if ( V_183 -> V_186 [ V_23 ] == 0 )
continue;
V_29 = F_98 ( V_187 [ V_23 ] , & V_87 ) ;
if ( V_29 != 0 )
goto V_312;
}
F_114 ( V_183 ) ;
F_11 (dev_data, &domain->dev_list, list) {
struct V_53 * V_18 ;
int V_158 ;
F_121 ( ! V_3 -> V_180 . V_181 ) ;
V_158 = V_3 -> V_180 . V_158 ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_93 ( & V_87 , V_3 -> V_2 , V_125 ,
V_158 , V_92 , V_148 ) ;
V_29 = F_98 ( V_18 , & V_87 ) ;
if ( V_29 != 0 )
goto V_312;
}
F_114 ( V_183 ) ;
V_29 = 0 ;
V_312:
return V_29 ;
}
static int F_268 ( struct V_182 * V_183 , int V_125 ,
T_4 V_92 )
{
F_67 ( V_81 ) ;
return F_267 ( V_183 , V_125 , V_92 , false ) ;
}
int F_269 ( struct V_363 * V_201 , int V_125 ,
T_4 V_92 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
V_29 = F_268 ( V_183 , V_125 , V_92 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
return V_29 ;
}
static int F_270 ( struct V_182 * V_183 , int V_125 )
{
F_67 ( V_82 ) ;
return F_267 ( V_183 , V_125 , V_153 ,
true ) ;
}
int F_271 ( struct V_363 * V_201 , int V_125 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
V_29 = F_270 ( V_183 , V_125 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
return V_29 ;
}
static T_4 * F_272 ( T_4 * V_382 , int V_196 , int V_125 , bool V_383 )
{
int V_231 ;
T_4 * V_189 ;
while ( true ) {
V_231 = ( V_125 >> ( 9 * V_196 ) ) & 0x1ff ;
V_189 = & V_382 [ V_231 ] ;
if ( V_196 == 0 )
break;
if ( ! ( * V_189 & V_269 ) ) {
if ( ! V_383 )
return NULL ;
V_382 = ( void * ) F_117 ( V_319 ) ;
if ( V_382 == NULL )
return NULL ;
* V_189 = F_85 ( V_382 ) | V_269 ;
}
V_382 = F_168 ( * V_189 & V_154 ) ;
V_196 -= 1 ;
}
return V_189 ;
}
static int F_273 ( struct V_182 * V_183 , int V_125 ,
unsigned long V_384 )
{
T_4 * V_189 ;
if ( V_183 -> V_190 != V_278 )
return - V_205 ;
V_189 = F_272 ( V_183 -> V_271 , V_183 -> V_270 , V_125 , true ) ;
if ( V_189 == NULL )
return - V_44 ;
* V_189 = ( V_384 & V_154 ) | V_269 ;
return F_270 ( V_183 , V_125 ) ;
}
static int F_274 ( struct V_182 * V_183 , int V_125 )
{
T_4 * V_189 ;
if ( V_183 -> V_190 != V_278 )
return - V_205 ;
V_189 = F_272 ( V_183 -> V_271 , V_183 -> V_270 , V_125 , false ) ;
if ( V_189 == NULL )
return 0 ;
* V_189 = 0 ;
return F_270 ( V_183 , V_125 ) ;
}
int F_275 ( struct V_363 * V_201 , int V_125 ,
unsigned long V_384 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
V_29 = F_273 ( V_183 , V_125 , V_384 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
return V_29 ;
}
int F_276 ( struct V_363 * V_201 , int V_125 )
{
struct V_182 * V_183 = V_201 -> V_276 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_183 -> V_114 , V_4 ) ;
V_29 = F_274 ( V_183 , V_125 ) ;
F_6 ( & V_183 -> V_114 , V_4 ) ;
return V_29 ;
}
int F_277 ( struct V_12 * V_13 , int V_125 ,
int V_162 , int V_127 )
{
struct V_1 * V_3 ;
struct V_53 * V_18 ;
struct V_86 V_87 ;
F_67 ( V_80 ) ;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_18 = V_38 [ V_3 -> V_2 ] ;
F_94 ( & V_87 , V_3 -> V_2 , V_125 , V_162 ,
V_127 , V_3 -> V_304 ) ;
return F_98 ( V_18 , & V_87 ) ;
}
struct V_363 * F_278 ( struct V_12 * V_13 )
{
struct V_182 * V_183 ;
V_183 = F_212 ( & V_13 -> V_11 ) ;
if ( F_39 ( V_183 ) )
return NULL ;
if ( ! ( V_183 -> V_4 & V_283 ) )
return NULL ;
return V_183 -> V_363 ;
}
void F_279 ( struct V_12 * V_13 , T_2 V_25 )
{
struct V_1 * V_3 ;
if ( ! F_280 () )
return;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_3 -> V_26 |= ( 1 << V_25 ) ;
}
int F_281 ( struct V_12 * V_13 ,
struct F_281 * V_385 )
{
int V_386 ;
int V_24 ;
if ( V_13 == NULL || V_385 == NULL )
return - V_205 ;
if ( ! F_280 () )
return - V_205 ;
memset ( V_385 , 0 , sizeof( * V_385 ) ) ;
V_24 = F_18 ( V_13 , V_20 ) ;
if ( V_24 )
V_385 -> V_4 |= V_387 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( V_24 )
V_385 -> V_4 |= V_388 ;
V_24 = F_18 ( V_13 , V_22 ) ;
if ( V_24 ) {
int V_389 ;
V_386 = 1 << ( 9 * ( V_381 + 1 ) ) ;
V_386 = F_282 ( V_386 , ( 1 << 20 ) ) ;
V_385 -> V_4 |= V_390 ;
V_385 -> V_386 = F_282 ( F_283 ( V_13 ) , V_386 ) ;
V_389 = F_284 ( V_13 ) ;
if ( V_389 & V_391 )
V_385 -> V_4 |= V_392 ;
if ( V_389 & V_393 )
V_385 -> V_4 |= V_394 ;
}
return 0 ;
}
static void F_285 ( T_1 V_2 , struct V_395 * V_396 )
{
T_4 V_397 ;
V_397 = V_56 [ V_2 ] . V_84 [ 2 ] ;
V_397 &= ~ V_398 ;
V_397 |= F_119 ( V_396 -> V_396 ) ;
V_397 |= V_399 ;
V_397 |= V_400 ;
V_397 |= V_401 ;
V_56 [ V_2 ] . V_84 [ 2 ] = V_397 ;
}
static struct V_395 * F_286 ( T_1 V_2 , bool V_402 )
{
struct V_395 * V_396 = NULL ;
struct V_53 * V_18 ;
unsigned long V_4 ;
T_1 V_30 ;
F_161 ( & V_260 , V_4 ) ;
V_18 = V_38 [ V_2 ] ;
if ( ! V_18 )
goto V_9;
V_396 = V_403 [ V_2 ] ;
if ( V_396 )
goto V_312;
V_30 = V_31 [ V_2 ] ;
V_396 = V_403 [ V_30 ] ;
if ( V_396 ) {
V_403 [ V_2 ] = V_396 ;
F_285 ( V_2 , V_396 ) ;
F_100 ( V_18 , V_2 ) ;
goto V_312;
}
V_396 = F_2 ( sizeof( * V_396 ) , V_319 ) ;
if ( ! V_396 )
goto V_312;
if ( V_402 )
V_396 -> V_404 = 32 ;
V_396 -> V_396 = F_287 ( V_405 , V_319 ) ;
if ( ! V_396 -> V_396 ) {
F_9 ( V_396 ) ;
V_396 = NULL ;
goto V_312;
}
memset ( V_396 -> V_396 , 0 , V_406 * sizeof( T_2 ) ) ;
if ( V_402 ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < 32 ; ++ V_23 )
V_396 -> V_396 [ V_23 ] = V_407 ;
}
V_403 [ V_2 ] = V_396 ;
F_285 ( V_2 , V_396 ) ;
F_100 ( V_18 , V_2 ) ;
if ( V_2 != V_30 ) {
V_403 [ V_30 ] = V_396 ;
F_285 ( V_2 , V_396 ) ;
F_100 ( V_18 , V_30 ) ;
}
V_312:
F_99 ( V_18 ) ;
V_9:
F_163 ( & V_260 , V_4 ) ;
return V_396 ;
}
static int F_288 ( struct V_408 * V_409 , T_1 V_2 , int V_91 )
{
struct V_395 * V_396 ;
unsigned long V_4 ;
int V_231 , V_410 ;
V_396 = F_286 ( V_2 , false ) ;
if ( ! V_396 )
return - V_411 ;
F_4 ( & V_396 -> V_114 , V_4 ) ;
for ( V_410 = 0 , V_231 = V_396 -> V_404 ;
V_231 < V_406 ;
++ V_231 ) {
if ( V_396 -> V_396 [ V_231 ] == 0 )
V_410 += 1 ;
else
V_410 = 0 ;
if ( V_410 == V_91 ) {
struct V_412 * V_413 ;
for (; V_410 != 0 ; -- V_410 )
V_396 -> V_396 [ V_231 - V_410 + 1 ] = V_407 ;
V_231 -= V_91 - 1 ;
V_413 = & V_409 -> V_412 ;
V_413 -> V_414 = V_2 ;
V_413 -> V_415 = V_231 ;
V_413 -> V_18 = ( void * ) V_409 ;
goto V_312;
}
}
V_231 = - V_416 ;
V_312:
F_6 ( & V_396 -> V_114 , V_4 ) ;
return V_231 ;
}
static int F_289 ( T_1 V_2 , int V_231 , union V_417 * V_417 )
{
struct V_395 * V_396 ;
unsigned long V_4 ;
V_396 = F_286 ( V_2 , false ) ;
if ( ! V_396 )
return - V_44 ;
F_4 ( & V_396 -> V_114 , V_4 ) ;
V_417 -> V_418 = V_396 -> V_396 [ V_231 ] ;
F_6 ( & V_396 -> V_114 , V_4 ) ;
return 0 ;
}
static int F_290 ( T_1 V_2 , int V_231 , union V_417 V_417 )
{
struct V_395 * V_396 ;
struct V_53 * V_18 ;
unsigned long V_4 ;
V_18 = V_38 [ V_2 ] ;
if ( V_18 == NULL )
return - V_205 ;
V_396 = F_286 ( V_2 , false ) ;
if ( ! V_396 )
return - V_44 ;
F_4 ( & V_396 -> V_114 , V_4 ) ;
V_396 -> V_396 [ V_231 ] = V_417 . V_418 ;
F_6 ( & V_396 -> V_114 , V_4 ) ;
F_104 ( V_18 , V_2 ) ;
F_99 ( V_18 ) ;
return 0 ;
}
static void F_291 ( T_1 V_2 , int V_231 )
{
struct V_395 * V_396 ;
struct V_53 * V_18 ;
unsigned long V_4 ;
V_18 = V_38 [ V_2 ] ;
if ( V_18 == NULL )
return;
V_396 = F_286 ( V_2 , false ) ;
if ( ! V_396 )
return;
F_4 ( & V_396 -> V_114 , V_4 ) ;
V_396 -> V_396 [ V_231 ] = 0 ;
F_6 ( & V_396 -> V_114 , V_4 ) ;
F_104 ( V_18 , V_2 ) ;
F_99 ( V_18 ) ;
}
static int F_292 ( int V_136 , struct V_419 * V_28 ,
unsigned int V_420 , int V_421 ,
struct V_422 * V_423 )
{
struct V_395 * V_396 ;
struct V_412 * V_413 ;
struct V_408 * V_409 ;
union V_417 V_417 ;
int V_424 ;
int V_231 ;
int V_2 ;
int V_29 ;
V_409 = F_293 ( V_136 ) ;
if ( ! V_409 )
return - V_205 ;
V_413 = & V_409 -> V_412 ;
V_424 = F_294 ( V_423 -> V_402 ) ;
V_2 = F_295 ( V_424 ) ;
if ( V_2 < 0 )
return V_2 ;
V_396 = F_286 ( V_2 , true ) ;
if ( V_396 == NULL )
return - V_44 ;
V_231 = V_423 -> V_425 ;
V_413 -> V_414 = V_2 ;
V_413 -> V_415 = V_231 ;
V_413 -> V_18 = ( void * ) V_409 ;
V_417 . V_418 = 0 ;
V_417 . V_426 . V_421 = V_421 ;
V_417 . V_426 . V_427 = V_428 -> V_429 ;
V_417 . V_426 . V_420 = V_420 ;
V_417 . V_426 . V_430 = V_428 -> V_431 ;
V_417 . V_426 . V_432 = 1 ;
V_29 = F_290 ( V_2 , V_231 , V_417 ) ;
if ( V_29 )
return V_29 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_421 = V_231 ;
V_28 -> V_350 = 0 ;
V_28 -> V_433 = V_423 -> V_433 ;
V_28 -> V_434 = V_423 -> V_434 ;
if ( V_423 -> V_433 )
V_28 -> V_350 = 1 ;
return 0 ;
}
static int F_296 ( struct V_435 * V_84 , const struct V_436 * V_350 ,
bool V_437 )
{
struct V_412 * V_413 ;
unsigned int V_438 , V_136 ;
struct V_408 * V_409 ;
union V_417 V_417 ;
int V_439 ;
if ( ! F_297 ( V_440 ) )
return - 1 ;
V_409 = V_84 -> V_441 ;
V_136 = V_84 -> V_136 ;
V_413 = & V_409 -> V_412 ;
if ( ! F_298 ( V_350 , V_442 ) )
return - V_205 ;
if ( F_289 ( V_413 -> V_414 , V_413 -> V_415 , & V_417 ) )
return - V_206 ;
if ( F_299 ( V_136 , V_409 , V_350 ) )
return - V_206 ;
V_439 = V_428 -> V_443 ( V_409 -> V_183 , V_350 , & V_438 ) ;
if ( V_439 ) {
if ( F_299 ( V_136 , V_409 , V_84 -> V_444 ) )
F_26 ( L_28 , V_136 ) ;
return V_439 ;
}
V_417 . V_426 . V_421 = V_409 -> V_421 ;
V_417 . V_426 . V_420 = V_438 ;
F_290 ( V_413 -> V_414 , V_413 -> V_415 , V_417 ) ;
if ( V_409 -> V_445 )
F_300 ( V_409 ) ;
F_301 ( V_84 -> V_444 , V_350 ) ;
return 0 ;
}
static int F_302 ( int V_136 )
{
struct V_412 * V_413 ;
struct V_408 * V_409 ;
V_409 = F_293 ( V_136 ) ;
if ( ! V_409 )
return - V_205 ;
V_413 = & V_409 -> V_412 ;
F_291 ( V_413 -> V_414 , V_413 -> V_415 ) ;
return 0 ;
}
static void F_303 ( struct V_12 * V_13 ,
unsigned int V_136 , unsigned int V_438 ,
struct V_446 * V_447 , T_6 V_448 )
{
struct V_412 * V_413 ;
struct V_408 * V_409 ;
union V_417 V_417 ;
V_409 = F_293 ( V_136 ) ;
if ( ! V_409 )
return;
V_413 = & V_409 -> V_412 ;
V_417 . V_418 = 0 ;
V_417 . V_426 . V_421 = V_409 -> V_421 ;
V_417 . V_426 . V_427 = V_428 -> V_429 ;
V_417 . V_426 . V_420 = V_438 ;
V_417 . V_426 . V_430 = V_428 -> V_431 ;
V_417 . V_426 . V_432 = 1 ;
F_290 ( V_413 -> V_414 , V_413 -> V_415 , V_417 ) ;
V_447 -> V_449 = V_450 ;
V_447 -> V_451 = V_242 ;
V_447 -> V_84 = V_413 -> V_415 ;
}
static int F_304 ( struct V_12 * V_13 , int V_136 , int V_452 )
{
struct V_408 * V_409 ;
int V_231 ;
T_1 V_2 ;
if ( ! V_13 )
return - V_205 ;
V_409 = F_293 ( V_136 ) ;
if ( ! V_409 )
return - V_205 ;
V_2 = F_13 ( & V_13 -> V_11 ) ;
V_231 = F_288 ( V_409 , V_2 , V_452 ) ;
return V_231 < 0 ? V_406 : V_231 ;
}
static int F_305 ( struct V_12 * V_13 , unsigned int V_136 ,
int V_231 , int V_238 )
{
struct V_412 * V_413 ;
struct V_408 * V_409 ;
T_1 V_2 ;
if ( ! V_13 )
return - V_205 ;
V_409 = F_293 ( V_136 ) ;
if ( ! V_409 )
return - V_205 ;
if ( V_231 >= V_406 )
return 0 ;
V_2 = F_13 ( & V_13 -> V_11 ) ;
V_413 = & V_409 -> V_412 ;
V_413 -> V_414 = V_2 ;
V_413 -> V_415 = V_231 + V_238 ;
V_413 -> V_18 = ( void * ) V_409 ;
return 0 ;
}
static int F_306 ( unsigned int V_136 , unsigned int V_184 )
{
struct V_412 * V_413 ;
struct V_408 * V_409 ;
int V_231 , V_2 ;
V_409 = F_293 ( V_136 ) ;
if ( ! V_409 )
return - V_205 ;
V_413 = & V_409 -> V_412 ;
V_2 = F_307 ( V_184 ) ;
if ( V_2 < 0 )
return V_2 ;
V_231 = F_288 ( V_409 , V_2 , 1 ) ;
if ( V_231 < 0 )
return V_231 ;
V_413 -> V_414 = V_2 ;
V_413 -> V_415 = V_231 ;
V_413 -> V_18 = ( void * ) V_409 ;
return 0 ;
}
