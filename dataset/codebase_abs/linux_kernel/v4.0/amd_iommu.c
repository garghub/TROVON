static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_5 ) ;
if ( ! V_3 )
return NULL ;
F_3 ( & V_3 -> V_6 ) ;
V_3 -> V_2 = V_2 ;
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
if ( ! F_23 ( V_11 ) )
return false ;
V_2 = F_13 ( V_11 ) ;
if ( V_2 > V_36 )
return false ;
if ( V_37 [ V_2 ] == NULL )
return false ;
return true ;
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_38 * V_39 ;
V_39 = F_25 ( V_11 ) ;
if ( ! F_26 ( V_39 ) )
F_27 ( V_39 ) ;
}
static int F_28 ( struct V_12 * V_13 , T_1 V_30 , void * V_40 )
{
* ( T_1 * ) V_40 = V_30 ;
return 0 ;
}
static T_1 F_29 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
T_1 V_2 , V_41 , V_42 ;
V_2 = F_13 ( V_11 ) ;
V_41 = V_31 [ V_2 ] ;
F_30 ( V_13 , F_28 , & V_42 ) ;
if ( V_41 == V_42 )
return V_41 ;
if ( V_41 == V_2 ) {
if ( ! V_37 [ V_42 ] ) {
V_37 [ V_42 ] =
V_37 [ V_2 ] ;
memcpy ( V_43 [ V_42 ] . V_40 ,
V_43 [ V_2 ] . V_40 ,
sizeof( V_43 [ V_42 ] . V_40 ) ) ;
}
return V_42 ;
}
F_31 ( L_1
L_2
L_3 , F_32 ( V_41 ) , F_33 ( V_41 ) ,
F_34 ( V_41 ) , F_35 ( V_11 ) , V_13 -> V_44 , V_13 -> V_10 ,
F_32 ( V_42 ) , F_33 ( V_42 ) ,
F_34 ( V_42 ) ) ;
if ( V_42 == V_2 &&
F_32 ( V_41 ) == V_13 -> V_14 -> V_15 ) {
V_13 -> V_45 |= V_46 ;
V_13 -> V_47 = V_41 & 0xff ;
F_31 ( L_4 ,
F_33 ( V_41 ) , F_34 ( V_41 ) ,
F_35 ( V_11 ) ) ;
}
return V_41 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
T_1 V_30 ;
if ( V_11 -> V_17 . V_18 )
return 0 ;
V_3 = F_12 ( F_13 ( V_11 ) ) ;
if ( ! V_3 )
return - V_48 ;
V_30 = F_29 ( V_11 ) ;
if ( V_30 != V_3 -> V_2 ) {
struct V_1 * V_49 ;
V_49 = F_12 ( V_30 ) ;
if ( V_49 == NULL ) {
F_37 ( L_5 ,
F_35 ( V_11 ) ) ;
F_7 ( V_3 ) ;
return - V_50 ;
}
V_3 -> V_49 = V_49 ;
F_38 ( & V_3 -> V_6 , & V_49 -> V_6 ) ;
}
if ( F_17 ( V_13 ) ) {
struct V_51 * V_18 ;
V_18 = V_37 [ V_3 -> V_2 ] ;
V_3 -> V_52 = V_18 -> V_53 ;
}
V_11 -> V_17 . V_18 = V_3 ;
F_39 ( V_37 [ V_3 -> V_2 ] -> V_54 ,
V_11 ) ;
return 0 ;
}
static void F_40 ( struct V_10 * V_11 )
{
T_1 V_2 , V_30 ;
V_2 = F_13 ( V_11 ) ;
V_30 = V_31 [ V_2 ] ;
memset ( & V_43 [ V_2 ] , 0 , sizeof( struct V_55 ) ) ;
memset ( & V_43 [ V_30 ] , 0 , sizeof( struct V_55 ) ) ;
V_37 [ V_2 ] = NULL ;
V_37 [ V_30 ] = NULL ;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_1 * V_3 = F_10 ( F_13 ( V_11 ) ) ;
if ( ! V_3 )
return;
F_42 ( V_37 [ V_3 -> V_2 ] -> V_54 ,
V_11 ) ;
F_43 ( V_11 ) ;
V_3 -> V_49 = NULL ;
}
void T_3 F_44 ( void )
{
struct V_1 * V_3 , * V_56 ;
struct V_12 * V_13 = NULL ;
F_45 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) )
continue;
F_41 ( & V_13 -> V_11 ) ;
}
F_46 (dev_data, n, &dev_data_list, dev_data_list)
F_7 ( V_3 ) ;
}
int T_3 F_47 ( void )
{
struct V_12 * V_13 = NULL ;
int V_29 = 0 ;
F_45 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) )
continue;
V_29 = F_36 ( & V_13 -> V_11 ) ;
if ( V_29 == - V_50 )
F_40 ( & V_13 -> V_11 ) ;
else if ( V_29 )
goto V_57;
}
F_45 (pdev) {
if ( F_22 ( & V_13 -> V_11 ) )
F_24 ( & V_13 -> V_11 ) ;
}
return 0 ;
V_57:
F_44 () ;
return V_29 ;
}
static void F_48 ( struct V_58 * V_59 )
{
if ( V_60 == NULL )
return;
V_59 -> V_61 = F_49 ( V_59 -> V_62 , 0444 , V_60 ,
& V_59 -> V_63 ) ;
}
static void F_50 ( void )
{
V_60 = F_51 ( L_6 , NULL ) ;
if ( V_60 == NULL )
return;
V_64 = F_52 ( L_7 , 0444 , V_60 ,
& V_65 ) ;
F_48 ( & V_66 ) ;
F_48 ( & V_67 ) ;
F_48 ( & V_68 ) ;
F_48 ( & V_69 ) ;
F_48 ( & V_70 ) ;
F_48 ( & V_71 ) ;
F_48 ( & V_72 ) ;
F_48 ( & V_73 ) ;
F_48 ( & V_74 ) ;
F_48 ( & V_75 ) ;
F_48 ( & V_76 ) ;
F_48 ( & V_77 ) ;
F_48 ( & V_78 ) ;
F_48 ( & V_79 ) ;
F_48 ( & V_80 ) ;
F_48 ( & V_81 ) ;
}
static void F_53 ( T_1 V_2 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 )
F_37 ( L_8 , V_23 ,
V_43 [ V_2 ] . V_40 [ V_23 ] ) ;
}
static void F_54 ( unsigned long V_82 )
{
struct V_83 * V_84 = F_55 ( V_82 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 )
F_37 ( L_9 , V_23 , V_84 -> V_40 [ V_23 ] ) ;
}
static void F_56 ( struct V_51 * V_18 , void * V_85 )
{
int type , V_2 , V_86 , V_4 ;
volatile T_2 * V_87 = V_85 ;
int V_88 = 0 ;
T_4 V_89 ;
V_90:
type = ( V_87 [ 1 ] >> V_91 ) & V_92 ;
V_2 = ( V_87 [ 0 ] >> V_93 ) & V_94 ;
V_86 = ( V_87 [ 1 ] >> V_95 ) & V_96 ;
V_4 = ( V_87 [ 1 ] >> V_97 ) & V_98 ;
V_89 = ( T_4 ) ( ( ( T_4 ) V_87 [ 3 ] ) << 32 ) | V_87 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_88 == V_99 ) {
F_37 ( L_10 ) ;
return;
}
F_57 ( 1 ) ;
goto V_90;
}
F_58 ( V_100 L_11 ) ;
switch ( type ) {
case V_101 :
F_58 ( L_12
L_13 ,
F_32 ( V_2 ) , F_33 ( V_2 ) , F_34 ( V_2 ) ,
V_89 , V_4 ) ;
F_53 ( V_2 ) ;
break;
case V_102 :
F_58 ( L_14
L_15 ,
F_32 ( V_2 ) , F_33 ( V_2 ) , F_34 ( V_2 ) ,
V_86 , V_89 , V_4 ) ;
break;
case V_103 :
F_58 ( L_16
L_13 ,
F_32 ( V_2 ) , F_33 ( V_2 ) , F_34 ( V_2 ) ,
V_89 , V_4 ) ;
break;
case V_104 :
F_58 ( L_17
L_15 ,
F_32 ( V_2 ) , F_33 ( V_2 ) , F_34 ( V_2 ) ,
V_86 , V_89 , V_4 ) ;
break;
case V_105 :
F_58 ( L_18 , V_89 ) ;
F_54 ( V_89 ) ;
break;
case V_106 :
F_58 ( L_19
L_20 , V_89 , V_4 ) ;
break;
case V_107 :
F_58 ( L_21
L_22 ,
F_32 ( V_2 ) , F_33 ( V_2 ) , F_34 ( V_2 ) ,
V_89 ) ;
break;
case V_108 :
F_58 ( L_23
L_13 ,
F_32 ( V_2 ) , F_33 ( V_2 ) , F_34 ( V_2 ) ,
V_89 , V_4 ) ;
break;
default:
F_58 ( V_100 L_24 , type ) ;
}
memset ( V_85 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_59 ( struct V_51 * V_18 )
{
T_2 V_109 , V_110 ;
V_109 = F_60 ( V_18 -> V_111 + V_112 ) ;
V_110 = F_60 ( V_18 -> V_111 + V_113 ) ;
while ( V_109 != V_110 ) {
F_56 ( V_18 , V_18 -> V_114 + V_109 ) ;
V_109 = ( V_109 + V_115 ) % V_18 -> V_116 ;
}
F_61 ( V_109 , V_18 -> V_111 + V_112 ) ;
}
static void F_62 ( struct V_51 * V_18 , T_4 * V_117 )
{
struct V_118 V_119 ;
F_63 ( V_81 ) ;
if ( F_64 ( V_117 [ 0 ] ) != V_120 ) {
F_65 ( L_25 ) ;
return;
}
V_119 . V_89 = V_117 [ 1 ] ;
V_119 . V_121 = F_66 ( V_117 [ 0 ] ) ;
V_119 . V_122 = F_67 ( V_117 [ 0 ] ) ;
V_119 . V_123 = F_68 ( V_117 [ 0 ] ) ;
V_119 . V_4 = F_69 ( V_117 [ 0 ] ) ;
F_70 ( & V_124 , 0 , & V_119 ) ;
}
static void F_71 ( struct V_51 * V_18 )
{
T_2 V_109 , V_110 ;
if ( V_18 -> V_125 == NULL )
return;
V_109 = F_60 ( V_18 -> V_111 + V_126 ) ;
V_110 = F_60 ( V_18 -> V_111 + V_127 ) ;
while ( V_109 != V_110 ) {
volatile T_4 * V_117 ;
T_4 V_28 [ 2 ] ;
int V_23 ;
V_117 = ( T_4 * ) ( V_18 -> V_125 + V_109 ) ;
for ( V_23 = 0 ; V_23 < V_99 ; ++ V_23 ) {
if ( F_64 ( V_117 [ 0 ] ) != 0 )
break;
F_57 ( 1 ) ;
}
V_28 [ 0 ] = V_117 [ 0 ] ;
V_28 [ 1 ] = V_117 [ 1 ] ;
V_117 [ 0 ] = V_117 [ 1 ] = 0UL ;
V_109 = ( V_109 + V_128 ) % V_129 ;
F_61 ( V_109 , V_18 -> V_111 + V_126 ) ;
F_62 ( V_18 , V_28 ) ;
V_109 = F_60 ( V_18 -> V_111 + V_126 ) ;
V_110 = F_60 ( V_18 -> V_111 + V_127 ) ;
}
}
T_5 F_72 ( int V_130 , void * V_40 )
{
struct V_51 * V_18 = (struct V_51 * ) V_40 ;
T_2 V_131 = F_60 ( V_18 -> V_111 + V_132 ) ;
while ( V_131 & ( V_133 | V_134 ) ) {
F_61 ( ( V_133 | V_134 ) ,
V_18 -> V_111 + V_132 ) ;
if ( V_131 & V_133 ) {
F_73 ( L_26 ) ;
F_59 ( V_18 ) ;
}
if ( V_131 & V_134 ) {
F_73 ( L_27 ) ;
F_71 ( V_18 ) ;
}
V_131 = F_60 ( V_18 -> V_111 + V_132 ) ;
}
return V_135 ;
}
T_5 F_74 ( int V_130 , void * V_40 )
{
return V_136 ;
}
static int F_75 ( volatile T_4 * V_137 )
{
int V_23 = 0 ;
while ( * V_137 == 0 && V_23 < V_99 ) {
F_57 ( 1 ) ;
V_23 += 1 ;
}
if ( V_23 == V_99 ) {
F_76 ( L_28 ) ;
return - V_138 ;
}
return 0 ;
}
static void F_77 ( struct V_51 * V_18 ,
struct V_83 * V_84 ,
T_2 V_110 )
{
T_6 * V_139 ;
V_139 = V_18 -> V_140 + V_110 ;
V_110 = ( V_110 + sizeof( * V_84 ) ) % V_18 -> V_141 ;
memcpy ( V_139 , V_84 , sizeof( * V_84 ) ) ;
F_61 ( V_110 , V_18 -> V_111 + V_142 ) ;
}
static void F_78 ( struct V_83 * V_84 , T_4 V_89 )
{
F_79 ( V_89 & 0x7ULL ) ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_40 [ 0 ] = F_80 ( F_81 ( V_89 ) ) | V_143 ;
V_84 -> V_40 [ 1 ] = F_82 ( F_81 ( V_89 ) ) ;
V_84 -> V_40 [ 2 ] = 1 ;
F_83 ( V_84 , V_144 ) ;
}
static void F_84 ( struct V_83 * V_84 , T_1 V_2 )
{
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_40 [ 0 ] = V_2 ;
F_83 ( V_84 , V_145 ) ;
}
static void F_85 ( struct V_83 * V_84 , T_4 V_89 ,
T_7 V_146 , T_1 V_86 , int V_147 )
{
T_4 V_148 ;
bool V_149 ;
V_148 = F_86 ( V_89 , V_146 , V_150 ) ;
V_149 = false ;
if ( V_148 > 1 ) {
V_89 = V_151 ;
V_149 = true ;
}
V_89 &= V_152 ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_40 [ 1 ] |= V_86 ;
V_84 -> V_40 [ 2 ] = F_80 ( V_89 ) ;
V_84 -> V_40 [ 3 ] = F_82 ( V_89 ) ;
F_83 ( V_84 , V_153 ) ;
if ( V_149 )
V_84 -> V_40 [ 2 ] |= V_154 ;
if ( V_147 )
V_84 -> V_40 [ 2 ] |= V_155 ;
}
static void F_87 ( struct V_83 * V_84 , T_1 V_2 , int V_156 ,
T_4 V_89 , T_7 V_146 )
{
T_4 V_148 ;
bool V_149 ;
V_148 = F_86 ( V_89 , V_146 , V_150 ) ;
V_149 = false ;
if ( V_148 > 1 ) {
V_89 = V_151 ;
V_149 = true ;
}
V_89 &= V_152 ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_40 [ 0 ] = V_2 ;
V_84 -> V_40 [ 0 ] |= ( V_156 & 0xff ) << 24 ;
V_84 -> V_40 [ 1 ] = V_2 ;
V_84 -> V_40 [ 2 ] = F_80 ( V_89 ) ;
V_84 -> V_40 [ 3 ] = F_82 ( V_89 ) ;
F_83 ( V_84 , V_157 ) ;
if ( V_149 )
V_84 -> V_40 [ 2 ] |= V_154 ;
}
static void F_88 ( struct V_83 * V_84 , T_1 V_86 , int V_121 ,
T_4 V_89 , bool V_146 )
{
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_89 &= ~ ( 0xfffULL ) ;
V_84 -> V_40 [ 0 ] = V_121 ;
V_84 -> V_40 [ 1 ] = V_86 ;
V_84 -> V_40 [ 2 ] = F_80 ( V_89 ) ;
V_84 -> V_40 [ 3 ] = F_82 ( V_89 ) ;
V_84 -> V_40 [ 2 ] |= V_155 ;
V_84 -> V_40 [ 2 ] |= V_158 ;
if ( V_146 )
V_84 -> V_40 [ 2 ] |= V_154 ;
F_83 ( V_84 , V_153 ) ;
}
static void F_89 ( struct V_83 * V_84 , T_1 V_2 , int V_121 ,
int V_156 , T_4 V_89 , bool V_146 )
{
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_89 &= ~ ( 0xfffULL ) ;
V_84 -> V_40 [ 0 ] = V_2 ;
V_84 -> V_40 [ 0 ] |= ( ( V_121 >> 8 ) & 0xff ) << 16 ;
V_84 -> V_40 [ 0 ] |= ( V_156 & 0xff ) << 24 ;
V_84 -> V_40 [ 1 ] = V_2 ;
V_84 -> V_40 [ 1 ] |= ( V_121 & 0xff ) << 16 ;
V_84 -> V_40 [ 2 ] = F_80 ( V_89 ) ;
V_84 -> V_40 [ 2 ] |= V_158 ;
V_84 -> V_40 [ 3 ] = F_82 ( V_89 ) ;
if ( V_146 )
V_84 -> V_40 [ 2 ] |= V_154 ;
F_83 ( V_84 , V_157 ) ;
}
static void F_90 ( struct V_83 * V_84 , T_1 V_2 , int V_121 ,
int V_131 , int V_123 , bool V_159 )
{
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_40 [ 0 ] = V_2 ;
if ( V_159 ) {
V_84 -> V_40 [ 1 ] = V_121 ;
V_84 -> V_40 [ 2 ] = V_158 ;
}
V_84 -> V_40 [ 3 ] = V_123 & 0x1ff ;
V_84 -> V_40 [ 3 ] |= ( V_131 & V_160 ) << V_161 ;
F_83 ( V_84 , V_162 ) ;
}
static void F_91 ( struct V_83 * V_84 )
{
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
F_83 ( V_84 , V_163 ) ;
}
static void F_92 ( struct V_83 * V_84 , T_1 V_2 )
{
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_40 [ 0 ] = V_2 ;
F_83 ( V_84 , V_164 ) ;
}
static int F_93 ( struct V_51 * V_18 ,
struct V_83 * V_84 ,
bool V_165 )
{
T_2 V_166 , V_110 , V_109 , V_167 ;
unsigned long V_4 ;
F_79 ( V_18 -> V_141 & V_168 ) ;
V_169:
F_4 ( & V_18 -> V_170 , V_4 ) ;
V_109 = F_60 ( V_18 -> V_111 + V_171 ) ;
V_110 = F_60 ( V_18 -> V_111 + V_142 ) ;
V_167 = ( V_110 + sizeof( * V_84 ) ) % V_18 -> V_141 ;
V_166 = ( V_109 - V_167 ) % V_18 -> V_141 ;
if ( V_166 <= 2 ) {
struct V_83 V_172 ;
volatile T_4 V_137 = 0 ;
int V_29 ;
F_78 ( & V_172 , ( T_4 ) & V_137 ) ;
F_77 ( V_18 , & V_172 , V_110 ) ;
F_6 ( & V_18 -> V_170 , V_4 ) ;
if ( ( V_29 = F_75 ( & V_137 ) ) != 0 )
return V_29 ;
goto V_169;
}
F_77 ( V_18 , V_84 , V_110 ) ;
V_18 -> V_173 = V_165 ;
F_6 ( & V_18 -> V_170 , V_4 ) ;
return 0 ;
}
static int F_94 ( struct V_51 * V_18 , struct V_83 * V_84 )
{
return F_93 ( V_18 , V_84 , true ) ;
}
static int F_95 ( struct V_51 * V_18 )
{
struct V_83 V_84 ;
volatile T_4 V_137 = 0 ;
int V_29 ;
if ( ! V_18 -> V_173 )
return 0 ;
F_78 ( & V_84 , ( T_4 ) & V_137 ) ;
V_29 = F_93 ( V_18 , & V_84 , false ) ;
if ( V_29 )
return V_29 ;
return F_75 ( & V_137 ) ;
}
static int F_96 ( struct V_51 * V_18 , T_1 V_2 )
{
struct V_83 V_84 ;
F_84 ( & V_84 , V_2 ) ;
return F_94 ( V_18 , & V_84 ) ;
}
static void F_97 ( struct V_51 * V_18 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= 0xffff ; ++ V_2 )
F_96 ( V_18 , V_2 ) ;
F_95 ( V_18 ) ;
}
static void F_98 ( struct V_51 * V_18 )
{
T_2 V_174 ;
for ( V_174 = 0 ; V_174 <= 0xffff ; ++ V_174 ) {
struct V_83 V_84 ;
F_85 ( & V_84 , 0 , V_151 ,
V_174 , 1 ) ;
F_94 ( V_18 , & V_84 ) ;
}
F_95 ( V_18 ) ;
}
static void F_99 ( struct V_51 * V_18 )
{
struct V_83 V_84 ;
F_91 ( & V_84 ) ;
F_94 ( V_18 , & V_84 ) ;
F_95 ( V_18 ) ;
}
static void F_100 ( struct V_51 * V_18 , T_1 V_2 )
{
struct V_83 V_84 ;
F_92 ( & V_84 , V_2 ) ;
F_94 ( V_18 , & V_84 ) ;
}
static void F_101 ( struct V_51 * V_18 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= V_175 ; V_2 ++ )
F_100 ( V_18 , V_2 ) ;
F_95 ( V_18 ) ;
}
void F_102 ( struct V_51 * V_18 )
{
if ( F_103 ( V_18 , V_176 ) ) {
F_99 ( V_18 ) ;
} else {
F_97 ( V_18 ) ;
F_101 ( V_18 ) ;
F_98 ( V_18 ) ;
}
}
static int F_104 ( struct V_1 * V_3 ,
T_4 V_89 , T_7 V_146 )
{
struct V_51 * V_18 ;
struct V_83 V_84 ;
int V_156 ;
V_156 = V_3 -> V_177 . V_156 ;
V_18 = V_37 [ V_3 -> V_2 ] ;
F_87 ( & V_84 , V_3 -> V_2 , V_156 , V_89 , V_146 ) ;
return F_94 ( V_18 , & V_84 ) ;
}
static int F_105 ( struct V_1 * V_3 )
{
struct V_51 * V_18 ;
int V_29 ;
V_18 = V_37 [ V_3 -> V_2 ] ;
V_29 = F_96 ( V_18 , V_3 -> V_2 ) ;
if ( V_29 )
return V_29 ;
if ( V_3 -> V_177 . V_178 )
V_29 = F_104 ( V_3 , 0 , ~ 0UL ) ;
return V_29 ;
}
static void F_106 ( struct V_179 * V_180 ,
T_4 V_89 , T_7 V_146 , int V_147 )
{
struct V_1 * V_3 ;
struct V_83 V_84 ;
int V_29 = 0 , V_23 ;
F_85 ( & V_84 , V_89 , V_146 , V_180 -> V_181 , V_147 ) ;
for ( V_23 = 0 ; V_23 < V_182 ; ++ V_23 ) {
if ( ! V_180 -> V_183 [ V_23 ] )
continue;
V_29 |= F_94 ( V_184 [ V_23 ] , & V_84 ) ;
}
F_11 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_177 . V_178 )
continue;
V_29 |= F_104 ( V_3 , V_89 , V_146 ) ;
}
F_79 ( V_29 ) ;
}
static void F_107 ( struct V_179 * V_180 ,
T_4 V_89 , T_7 V_146 )
{
F_106 ( V_180 , V_89 , V_146 , 0 ) ;
}
static void F_108 ( struct V_179 * V_180 )
{
F_106 ( V_180 , 0 , V_151 , 0 ) ;
}
static void F_109 ( struct V_179 * V_180 )
{
F_106 ( V_180 , 0 , V_151 , 1 ) ;
}
static void F_110 ( struct V_179 * V_180 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_182 ; ++ V_23 ) {
if ( ! V_180 -> V_183 [ V_23 ] )
continue;
F_95 ( V_184 [ V_23 ] ) ;
}
}
static void F_111 ( struct V_179 * V_180 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_105 ( V_3 ) ;
}
static bool F_112 ( struct V_179 * V_180 ,
T_8 V_185 )
{
T_4 * V_186 ;
if ( V_180 -> V_187 == V_188 )
return false ;
V_186 = ( void * ) F_113 ( V_185 ) ;
if ( ! V_186 )
return false ;
* V_186 = F_114 ( V_180 -> V_187 ,
F_115 ( V_180 -> V_189 ) ) ;
V_180 -> V_189 = V_186 ;
V_180 -> V_187 += 1 ;
V_180 -> V_190 = true ;
return true ;
}
static T_4 * F_116 ( struct V_179 * V_180 ,
unsigned long V_89 ,
unsigned long V_191 ,
T_4 * * V_192 ,
T_8 V_185 )
{
int V_193 , V_194 ;
T_4 * V_186 , * V_195 ;
F_117 ( ! F_118 ( V_191 ) ) ;
while ( V_89 > F_119 ( V_180 -> V_187 ) )
F_112 ( V_180 , V_185 ) ;
V_193 = V_180 -> V_187 - 1 ;
V_186 = & V_180 -> V_189 [ F_120 ( V_193 , V_89 ) ] ;
V_89 = F_121 ( V_89 , V_191 ) ;
V_194 = F_122 ( V_191 ) ;
while ( V_193 > V_194 ) {
if ( ! F_123 ( * V_186 ) ) {
V_195 = ( T_4 * ) F_113 ( V_185 ) ;
if ( ! V_195 )
return NULL ;
* V_186 = F_114 ( V_193 , F_115 ( V_195 ) ) ;
}
if ( F_124 ( * V_186 ) != V_193 )
return NULL ;
V_193 -= 1 ;
V_186 = F_125 ( * V_186 ) ;
if ( V_192 && V_193 == V_194 )
* V_192 = V_186 ;
V_186 = & V_186 [ F_120 ( V_193 , V_89 ) ] ;
}
return V_186 ;
}
static T_4 * F_126 ( struct V_179 * V_180 , unsigned long V_89 )
{
int V_193 ;
T_4 * V_186 ;
if ( V_89 > F_119 ( V_180 -> V_187 ) )
return NULL ;
V_193 = V_180 -> V_187 - 1 ;
V_186 = & V_180 -> V_189 [ F_120 ( V_193 , V_89 ) ] ;
while ( V_193 > 0 ) {
if ( ! F_123 ( * V_186 ) )
return NULL ;
if ( F_124 ( * V_186 ) == 0x07 ) {
unsigned long V_196 , V_197 ;
V_196 = F_127 ( * V_186 ) ;
V_196 = ~ ( ( F_128 ( V_196 ) << 3 ) - 1 ) ;
V_197 = ( ( unsigned long ) V_186 ) & V_196 ;
return ( T_4 * ) V_197 ;
}
if ( F_124 ( * V_186 ) != V_193 )
return NULL ;
V_193 -= 1 ;
V_186 = F_125 ( * V_186 ) ;
V_186 = & V_186 [ F_120 ( V_193 , V_89 ) ] ;
}
return V_186 ;
}
static int F_129 ( struct V_179 * V_198 ,
unsigned long V_199 ,
unsigned long V_82 ,
int V_200 ,
unsigned long V_191 )
{
T_4 V_197 , * V_186 ;
int V_23 , V_88 ;
if ( ! ( V_200 & V_201 ) )
return - V_202 ;
V_199 = F_130 ( V_199 ) ;
V_82 = F_130 ( V_82 ) ;
V_88 = F_128 ( V_191 ) ;
V_186 = F_116 ( V_198 , V_199 , V_191 , NULL , V_5 ) ;
if ( ! V_186 )
return - V_48 ;
for ( V_23 = 0 ; V_23 < V_88 ; ++ V_23 )
if ( F_123 ( V_186 [ V_23 ] ) )
return - V_203 ;
if ( V_191 > V_150 ) {
V_197 = F_131 ( V_82 , V_191 ) ;
V_197 |= F_132 ( 7 ) | V_204 | V_205 ;
} else
V_197 = V_82 | V_204 | V_205 ;
if ( V_200 & V_206 )
V_197 |= V_207 ;
if ( V_200 & V_208 )
V_197 |= V_209 ;
for ( V_23 = 0 ; V_23 < V_88 ; ++ V_23 )
V_186 [ V_23 ] = V_197 ;
F_133 ( V_198 ) ;
return 0 ;
}
static unsigned long F_134 ( struct V_179 * V_198 ,
unsigned long V_199 ,
unsigned long V_191 )
{
unsigned long long V_210 , V_211 ;
T_4 * V_186 ;
F_117 ( ! F_118 ( V_191 ) ) ;
V_211 = 0 ;
while ( V_211 < V_191 ) {
V_186 = F_126 ( V_198 , V_199 ) ;
if ( ! V_186 ) {
V_210 = V_150 ;
} else if ( F_124 ( * V_186 ) == 0 ) {
V_210 = V_150 ;
* V_186 = 0ULL ;
} else {
int V_88 , V_23 ;
V_210 = F_127 ( * V_186 ) ;
if ( ( V_210 - 1 ) & V_199 )
break;
V_88 = F_128 ( V_210 ) ;
for ( V_23 = 0 ; V_23 < V_88 ; V_23 ++ )
V_186 [ V_23 ] = 0ULL ;
}
V_199 = ( V_199 & ~ ( V_210 - 1 ) ) + V_210 ;
V_211 += V_210 ;
}
F_117 ( V_211 && ! F_118 ( V_211 ) ) ;
return V_211 ;
}
static int F_135 ( struct V_51 * V_18 ,
struct V_212 * V_28 )
{
T_1 V_213 , V_23 ;
for ( V_23 = V_28 -> V_214 ; V_23 <= V_28 -> V_215 ; ++ V_23 ) {
V_213 = V_31 [ V_23 ] ;
if ( V_37 [ V_213 ] == V_18 )
return 1 ;
}
return 0 ;
}
static int F_136 ( struct V_27 * V_216 ,
struct V_212 * V_217 )
{
T_4 V_218 ;
int V_29 ;
for ( V_218 = V_217 -> V_219 ; V_218 < V_217 -> V_220 ;
V_218 += V_150 ) {
V_29 = F_129 ( & V_216 -> V_180 , V_218 , V_218 , V_217 -> V_200 ,
V_150 ) ;
if ( V_29 )
return V_29 ;
if ( V_218 < V_216 -> V_221 )
F_137 ( V_218 >> V_222 ,
V_216 -> V_223 [ 0 ] -> V_224 ) ;
}
return 0 ;
}
static int F_138 ( struct V_51 * V_18 )
{
struct V_212 * V_28 ;
int V_29 ;
F_11 (entry, &amd_iommu_unity_map, list) {
if ( ! F_135 ( V_18 , V_28 ) )
continue;
V_29 = F_136 ( V_18 -> V_225 , V_28 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_139 ( struct V_27 * V_216 ,
T_1 V_2 )
{
struct V_212 * V_217 ;
int V_29 ;
F_11 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_217 -> V_214 && V_2 <= V_217 -> V_215 ) )
continue;
V_29 = F_136 ( V_216 , V_217 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static void F_140 ( struct V_27 * V_198 ,
unsigned long V_226 ,
unsigned int V_148 )
{
unsigned int V_23 , V_227 = V_198 -> V_221 >> V_222 ;
if ( V_226 + V_148 > V_227 )
V_148 = V_227 - V_226 ;
for ( V_23 = V_226 ; V_23 < V_226 + V_148 ; ++ V_23 ) {
int V_228 = V_23 / V_229 ;
int V_195 = V_23 % V_229 ;
F_137 ( V_195 , V_198 -> V_223 [ V_228 ] -> V_224 ) ;
}
}
static int F_141 ( struct V_27 * V_216 ,
bool V_230 , T_8 V_185 )
{
int V_228 = V_216 -> V_221 >> V_231 ;
struct V_51 * V_18 ;
unsigned long V_23 , V_232 ;
#ifdef F_142
V_230 = false ;
#endif
if ( V_228 >= V_233 )
return - V_48 ;
V_216 -> V_223 [ V_228 ] = F_2 ( sizeof( struct V_234 ) , V_185 ) ;
if ( ! V_216 -> V_223 [ V_228 ] )
return - V_48 ;
V_216 -> V_223 [ V_228 ] -> V_224 = ( void * ) F_113 ( V_185 ) ;
if ( ! V_216 -> V_223 [ V_228 ] -> V_224 )
goto V_57;
V_216 -> V_223 [ V_228 ] -> V_235 = V_216 -> V_221 ;
if ( V_230 ) {
unsigned long V_89 = V_216 -> V_221 ;
int V_23 , V_236 = V_229 / 512 ;
T_4 * V_186 , * V_192 ;
for ( V_23 = 0 ; V_23 < V_236 ; ++ V_23 ) {
V_186 = F_116 ( & V_216 -> V_180 , V_89 , V_150 ,
& V_192 , V_185 ) ;
if ( ! V_186 )
goto V_57;
V_216 -> V_223 [ V_228 ] -> V_237 [ V_23 ] = V_192 ;
V_89 += V_238 / 64 ;
}
}
V_232 = V_216 -> V_221 ;
V_216 -> V_221 += V_238 ;
if ( V_232 < V_239 &&
V_216 -> V_221 > V_239 ) {
unsigned long V_240 ;
int V_148 ;
V_148 = F_86 ( V_239 , 0x10000 , V_150 ) ;
V_240 = V_239 >> V_222 ;
F_140 ( V_216 , V_240 , V_148 ) ;
}
F_143 (iommu) {
if ( V_18 -> V_241 &&
V_18 -> V_241 >= V_216 -> V_223 [ V_228 ] -> V_235
&& V_18 -> V_241 < V_216 -> V_221 ) {
unsigned long V_242 ;
int V_148 = F_86 ( V_18 -> V_241 ,
V_18 -> V_243 ,
V_150 ) ;
V_242 = V_18 -> V_241 >> V_222 ;
F_140 ( V_216 , V_242 , V_148 ) ;
}
}
for ( V_23 = V_216 -> V_223 [ V_228 ] -> V_235 ;
V_23 < V_216 -> V_221 ;
V_23 += V_150 ) {
T_4 * V_186 = F_126 ( & V_216 -> V_180 , V_23 ) ;
if ( ! V_186 || ! F_123 ( * V_186 ) )
continue;
F_140 ( V_216 , V_23 >> V_222 , 1 ) ;
}
F_133 ( & V_216 -> V_180 ) ;
return 0 ;
V_57:
F_133 ( & V_216 -> V_180 ) ;
F_144 ( ( unsigned long ) V_216 -> V_223 [ V_228 ] -> V_224 ) ;
F_9 ( V_216 -> V_223 [ V_228 ] ) ;
V_216 -> V_223 [ V_228 ] = NULL ;
return - V_48 ;
}
static unsigned long F_145 ( struct V_10 * V_11 ,
struct V_27 * V_198 ,
unsigned int V_148 ,
unsigned long V_244 ,
T_4 V_35 ,
unsigned long V_245 )
{
unsigned long V_246 = V_198 -> V_247 % V_238 ;
int V_248 = V_198 -> V_221 >> V_231 ;
int V_23 = V_245 >> V_231 ;
unsigned long V_249 ;
unsigned long V_89 = - 1 ;
unsigned long V_250 ;
V_246 >>= V_222 ;
V_249 = F_146 ( F_147 ( V_11 ) + 1 ,
V_150 ) >> V_222 ;
for (; V_23 < V_248 ; ++ V_23 ) {
unsigned long V_235 = V_198 -> V_223 [ V_23 ] -> V_235 >> V_222 ;
if ( V_198 -> V_223 [ V_23 ] -> V_235 >= V_35 )
break;
V_250 = F_148 ( V_229 , V_235 ,
V_35 >> V_222 ) ;
V_89 = F_149 ( V_198 -> V_223 [ V_23 ] -> V_224 ,
V_250 , V_246 , V_148 , 0 ,
V_249 , V_244 ) ;
if ( V_89 != - 1 ) {
V_89 = V_198 -> V_223 [ V_23 ] -> V_235 +
( V_89 << V_222 ) ;
V_198 -> V_247 = V_89 + ( V_148 << V_222 ) ;
break;
}
V_246 = 0 ;
}
return V_89 ;
}
static unsigned long F_150 ( struct V_10 * V_11 ,
struct V_27 * V_198 ,
unsigned int V_148 ,
unsigned long V_244 ,
T_4 V_35 )
{
unsigned long V_89 ;
#ifdef F_142
V_198 -> V_247 = 0 ;
V_198 -> V_251 = true ;
#endif
V_89 = F_145 ( V_11 , V_198 , V_148 , V_244 ,
V_35 , V_198 -> V_247 ) ;
if ( V_89 == - 1 ) {
V_198 -> V_247 = 0 ;
V_89 = F_145 ( V_11 , V_198 , V_148 , V_244 ,
V_35 , 0 ) ;
V_198 -> V_251 = true ;
}
if ( F_151 ( V_89 == - 1 ) )
V_89 = V_252 ;
F_79 ( ( V_89 + ( V_150 * V_148 ) ) > V_198 -> V_221 ) ;
return V_89 ;
}
static void F_152 ( struct V_27 * V_198 ,
unsigned long V_89 ,
unsigned int V_148 )
{
unsigned V_23 = V_89 >> V_231 ;
struct V_234 * V_253 = V_198 -> V_223 [ V_23 ] ;
F_117 ( V_23 >= V_233 || V_253 == NULL ) ;
#ifdef F_142
if ( V_23 < 4 )
return;
#endif
if ( V_89 >= V_198 -> V_247 )
V_198 -> V_251 = true ;
V_89 = ( V_89 % V_238 ) >> V_222 ;
F_153 ( V_253 -> V_224 , V_89 , V_148 ) ;
}
static void F_154 ( struct V_179 * V_180 )
{
unsigned long V_4 ;
F_4 ( & V_254 , V_4 ) ;
F_38 ( & V_180 -> V_255 , & V_256 ) ;
F_6 ( & V_254 , V_4 ) ;
}
static void F_155 ( struct V_179 * V_180 )
{
unsigned long V_4 ;
F_4 ( & V_254 , V_4 ) ;
F_8 ( & V_180 -> V_255 ) ;
F_6 ( & V_254 , V_4 ) ;
}
static T_1 F_156 ( void )
{
unsigned long V_4 ;
int V_181 ;
F_157 ( & V_257 , V_4 ) ;
V_181 = F_158 ( V_258 , V_259 ) ;
F_117 ( V_181 == 0 ) ;
if ( V_181 > 0 && V_181 < V_259 )
F_137 ( V_181 , V_258 ) ;
else
V_181 = 0 ;
F_159 ( & V_257 , V_4 ) ;
return V_181 ;
}
static void F_160 ( int V_181 )
{
unsigned long V_4 ;
F_157 ( & V_257 , V_4 ) ;
if ( V_181 > 0 && V_181 < V_259 )
F_161 ( V_181 , V_258 ) ;
F_159 ( & V_257 , V_4 ) ;
}
static void F_162 ( struct V_179 * V_180 )
{
unsigned long V_260 = ( unsigned long ) V_180 -> V_189 ;
switch ( V_180 -> V_187 ) {
case V_261 :
break;
case V_262 :
F_144 ( V_260 ) ;
break;
case V_263 :
F_163 ( V_260 ) ;
break;
case V_264 :
F_164 ( V_260 ) ;
break;
case V_265 :
F_165 ( V_260 ) ;
break;
case V_266 :
F_166 ( V_260 ) ;
break;
case V_188 :
F_167 ( V_260 ) ;
break;
default:
F_168 () ;
}
}
static void F_169 ( T_4 * V_267 )
{
T_4 * V_268 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_267 [ V_23 ] & V_269 ) )
continue;
V_268 = F_170 ( V_267 [ V_23 ] & V_152 ) ;
F_144 ( ( unsigned long ) V_268 ) ;
}
}
static void F_171 ( T_4 * V_267 )
{
T_4 * V_268 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_267 [ V_23 ] & V_269 ) )
continue;
V_268 = F_170 ( V_267 [ V_23 ] & V_152 ) ;
F_169 ( V_268 ) ;
}
}
static void F_172 ( struct V_179 * V_180 )
{
if ( V_180 -> V_270 == 2 )
F_171 ( V_180 -> V_271 ) ;
else if ( V_180 -> V_270 == 1 )
F_169 ( V_180 -> V_271 ) ;
else if ( V_180 -> V_270 != 0 )
F_168 () ;
F_144 ( ( unsigned long ) V_180 -> V_271 ) ;
}
static void F_173 ( struct V_27 * V_198 )
{
int V_23 ;
if ( ! V_198 )
return;
F_155 ( & V_198 -> V_180 ) ;
F_162 ( & V_198 -> V_180 ) ;
for ( V_23 = 0 ; V_23 < V_233 ; ++ V_23 ) {
if ( ! V_198 -> V_223 [ V_23 ] )
continue;
F_144 ( ( unsigned long ) V_198 -> V_223 [ V_23 ] -> V_224 ) ;
F_9 ( V_198 -> V_223 [ V_23 ] ) ;
}
F_9 ( V_198 ) ;
}
static struct V_27 * F_174 ( void )
{
struct V_27 * V_216 ;
V_216 = F_2 ( sizeof( struct V_27 ) , V_5 ) ;
if ( ! V_216 )
return NULL ;
F_175 ( & V_216 -> V_180 . V_170 ) ;
V_216 -> V_180 . V_181 = F_156 () ;
if ( V_216 -> V_180 . V_181 == 0 )
goto V_272;
F_3 ( & V_216 -> V_180 . V_273 ) ;
V_216 -> V_180 . V_187 = V_263 ;
V_216 -> V_180 . V_189 = ( void * ) F_113 ( V_5 ) ;
V_216 -> V_180 . V_4 = V_274 ;
V_216 -> V_180 . V_275 = V_216 ;
if ( ! V_216 -> V_180 . V_189 )
goto V_272;
V_216 -> V_251 = false ;
V_216 -> V_34 = 0xffff ;
F_154 ( & V_216 -> V_180 ) ;
if ( F_141 ( V_216 , true , V_5 ) )
goto V_272;
V_216 -> V_223 [ 0 ] -> V_224 [ 0 ] = 1 ;
V_216 -> V_247 = 0 ;
return V_216 ;
V_272:
F_173 ( V_216 ) ;
return NULL ;
}
static bool V_27 ( struct V_179 * V_180 )
{
return V_180 -> V_4 & V_274 ;
}
static void F_176 ( T_1 V_2 , struct V_179 * V_180 , bool V_177 )
{
T_4 V_276 = 0 ;
T_4 V_4 = 0 ;
if ( V_180 -> V_187 != V_261 )
V_276 = F_115 ( V_180 -> V_189 ) ;
V_276 |= ( V_180 -> V_187 & V_277 )
<< V_278 ;
V_276 |= V_207 | V_209 | V_204 | V_279 ;
V_4 = V_43 [ V_2 ] . V_40 [ 1 ] ;
if ( V_177 )
V_4 |= V_280 ;
if ( V_180 -> V_4 & V_281 ) {
T_4 V_282 = F_81 ( V_180 -> V_271 ) ;
T_4 V_270 = V_180 -> V_270 ;
T_4 V_283 ;
V_276 |= V_284 ;
V_276 |= ( V_270 & V_285 ) << V_286 ;
V_283 = F_177 ( ~ 0ULL ) << V_287 ;
V_4 &= ~ V_283 ;
V_283 = F_178 ( ~ 0ULL ) << V_288 ;
V_4 &= ~ V_283 ;
V_283 = F_179 ( V_282 ) << V_289 ;
V_276 |= V_283 ;
V_283 = F_177 ( V_282 ) << V_287 ;
V_4 |= V_283 ;
V_283 = F_178 ( V_282 ) << V_288 ;
V_4 |= V_283 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_180 -> V_181 ;
V_43 [ V_2 ] . V_40 [ 1 ] = V_4 ;
V_43 [ V_2 ] . V_40 [ 0 ] = V_276 ;
}
static void F_180 ( T_1 V_2 )
{
V_43 [ V_2 ] . V_40 [ 0 ] = V_204 | V_279 ;
V_43 [ V_2 ] . V_40 [ 1 ] = 0 ;
F_181 ( V_2 ) ;
}
static void F_182 ( struct V_1 * V_3 ,
struct V_179 * V_180 )
{
struct V_51 * V_18 ;
bool V_177 ;
V_18 = V_37 [ V_3 -> V_2 ] ;
V_177 = V_3 -> V_177 . V_178 ;
V_3 -> V_180 = V_180 ;
F_38 ( & V_3 -> V_255 , & V_180 -> V_273 ) ;
F_176 ( V_3 -> V_2 , V_180 , V_177 ) ;
V_180 -> V_183 [ V_18 -> V_228 ] += 1 ;
V_180 -> V_290 += 1 ;
F_105 ( V_3 ) ;
}
static void F_183 ( struct V_1 * V_3 )
{
struct V_51 * V_18 ;
V_18 = V_37 [ V_3 -> V_2 ] ;
V_3 -> V_180 -> V_183 [ V_18 -> V_228 ] -= 1 ;
V_3 -> V_180 -> V_290 -= 1 ;
V_3 -> V_180 = NULL ;
F_8 ( & V_3 -> V_255 ) ;
F_180 ( V_3 -> V_2 ) ;
F_105 ( V_3 ) ;
}
static int F_184 ( struct V_1 * V_3 ,
struct V_179 * V_180 )
{
struct V_1 * V_109 , * V_28 ;
int V_29 ;
F_185 ( & V_180 -> V_170 ) ;
V_109 = V_3 ;
if ( V_109 -> V_49 != NULL )
V_109 = V_109 -> V_49 ;
V_29 = - V_203 ;
if ( V_109 -> V_180 != NULL )
goto V_9;
F_182 ( V_109 , V_180 ) ;
F_11 (entry, &head->alias_list, alias_list)
F_182 ( V_28 , V_180 ) ;
V_29 = 0 ;
V_9:
F_186 ( & V_180 -> V_170 ) ;
return V_29 ;
}
static void F_187 ( struct V_12 * V_13 )
{
F_188 ( V_13 ) ;
F_189 ( V_13 ) ;
F_190 ( V_13 ) ;
}
static int F_191 ( struct V_12 * V_13 )
{
T_1 V_291 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return - V_202 ;
F_192 ( V_13 , V_24 + V_292 , & V_291 ) ;
V_291 |= V_293 ;
F_193 ( V_13 , V_24 + V_292 , V_291 ) ;
return 0 ;
}
static int F_194 ( struct V_12 * V_13 )
{
bool V_294 ;
int V_295 , V_29 ;
V_295 = 32 ;
if ( F_19 ( V_13 , V_296 ) )
V_295 = 1 ;
V_294 = F_19 ( V_13 , V_297 ) ;
V_29 = F_195 ( V_13 , 0 ) ;
if ( V_29 )
goto V_298;
V_29 = F_196 ( V_13 ) ;
if ( V_29 )
goto V_298;
V_29 = F_197 ( V_13 , V_295 ) ;
if ( V_29 )
goto V_298;
if ( V_294 ) {
V_29 = F_191 ( V_13 ) ;
if ( V_29 )
goto V_298;
}
V_29 = F_198 ( V_13 , V_222 ) ;
if ( V_29 )
goto V_298;
return 0 ;
V_298:
F_189 ( V_13 ) ;
F_190 ( V_13 ) ;
return V_29 ;
}
static bool F_199 ( struct V_12 * V_13 )
{
T_1 V_131 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return false ;
F_192 ( V_13 , V_24 + V_299 , & V_131 ) ;
return ( V_131 & V_300 ) ? true : false ;
}
static int F_200 ( struct V_10 * V_11 ,
struct V_179 * V_180 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_29 ;
V_3 = F_16 ( V_11 ) ;
if ( V_180 -> V_4 & V_281 ) {
if ( ! V_3 -> V_52 || ! V_3 -> V_301 )
return - V_202 ;
if ( F_194 ( V_13 ) != 0 )
return - V_202 ;
V_3 -> V_177 . V_178 = true ;
V_3 -> V_177 . V_156 = F_201 ( V_13 ) ;
V_3 -> V_302 = F_199 ( V_13 ) ;
} else if ( V_303 &&
F_198 ( V_13 , V_222 ) == 0 ) {
V_3 -> V_177 . V_178 = true ;
V_3 -> V_177 . V_156 = F_201 ( V_13 ) ;
}
F_157 ( & V_257 , V_4 ) ;
V_29 = F_184 ( V_3 , V_180 ) ;
F_159 ( & V_257 , V_4 ) ;
F_109 ( V_180 ) ;
return V_29 ;
}
static void F_202 ( struct V_1 * V_3 )
{
struct V_1 * V_109 , * V_28 ;
struct V_179 * V_180 ;
unsigned long V_4 ;
F_117 ( ! V_3 -> V_180 ) ;
V_180 = V_3 -> V_180 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_109 = V_3 ;
if ( V_109 -> V_49 != NULL )
V_109 = V_109 -> V_49 ;
F_11 (entry, &head->alias_list, alias_list)
F_183 ( V_28 ) ;
F_183 ( V_109 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
if ( V_3 -> V_301 &&
( V_3 -> V_180 == NULL && V_180 != V_304 ) )
F_184 ( V_3 , V_304 ) ;
}
static void F_203 ( struct V_10 * V_11 )
{
struct V_179 * V_180 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
V_180 = V_3 -> V_180 ;
F_157 ( & V_257 , V_4 ) ;
F_202 ( V_3 ) ;
F_159 ( & V_257 , V_4 ) ;
if ( V_180 -> V_4 & V_281 )
F_187 ( F_14 ( V_11 ) ) ;
else if ( V_3 -> V_177 . V_178 )
F_188 ( F_14 ( V_11 ) ) ;
V_3 -> V_177 . V_178 = false ;
}
static struct V_179 * F_204 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
struct V_179 * V_198 = NULL ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
if ( V_3 -> V_180 )
return V_3 -> V_180 ;
if ( V_3 -> V_49 != NULL ) {
struct V_1 * V_49 = V_3 -> V_49 ;
F_205 ( & V_257 , V_4 ) ;
if ( V_49 -> V_180 != NULL ) {
F_184 ( V_3 , V_49 -> V_180 ) ;
V_198 = V_49 -> V_180 ;
}
F_206 ( & V_257 , V_4 ) ;
}
return V_198 ;
}
static int F_207 ( struct V_305 * V_306 ,
unsigned long V_307 , void * V_40 )
{
struct V_27 * V_308 ;
struct V_179 * V_180 ;
struct V_1 * V_3 ;
struct V_10 * V_11 = V_40 ;
struct V_51 * V_18 ;
unsigned long V_4 ;
T_1 V_2 ;
if ( ! F_22 ( V_11 ) )
return 0 ;
V_2 = F_13 ( V_11 ) ;
V_18 = V_37 [ V_2 ] ;
V_3 = F_16 ( V_11 ) ;
switch ( V_307 ) {
case V_309 :
V_180 = F_204 ( V_11 ) ;
if ( ! V_180 )
goto V_310;
if ( V_3 -> V_301 )
break;
F_203 ( V_11 ) ;
break;
case V_311 :
F_36 ( V_11 ) ;
F_24 ( V_11 ) ;
V_3 = F_16 ( V_11 ) ;
if ( V_312 || V_3 -> V_52 ) {
V_3 -> V_301 = true ;
F_200 ( V_11 , V_304 ) ;
break;
}
V_180 = F_204 ( V_11 ) ;
V_308 = F_20 ( V_2 ) ;
if ( ! V_308 ) {
V_308 = F_174 () ;
if ( ! V_308 )
goto V_310;
V_308 -> V_34 = V_2 ;
F_4 ( & V_33 , V_4 ) ;
F_5 ( & V_308 -> V_255 , & V_32 ) ;
F_6 ( & V_33 , V_4 ) ;
}
V_11 -> V_17 . V_313 = & V_314 ;
break;
case V_315 :
F_41 ( V_11 ) ;
default:
goto V_310;
}
F_95 ( V_18 ) ;
V_310:
return 0 ;
}
void F_208 ( void )
{
F_209 ( & V_316 , & V_317 ) ;
}
static struct V_179 * F_210 ( struct V_10 * V_11 )
{
struct V_179 * V_180 ;
struct V_27 * V_216 ;
T_1 V_2 = F_13 ( V_11 ) ;
if ( ! F_22 ( V_11 ) )
return F_211 ( - V_202 ) ;
V_180 = F_204 ( V_11 ) ;
if ( V_180 != NULL && ! V_27 ( V_180 ) )
return F_211 ( - V_203 ) ;
if ( V_180 != NULL )
return V_180 ;
V_216 = F_20 ( V_2 ) ;
if ( ! V_216 )
V_216 = V_37 [ V_2 ] -> V_225 ;
F_200 ( V_11 , & V_216 -> V_180 ) ;
F_212 ( L_29 ,
V_216 -> V_180 . V_181 , F_35 ( V_11 ) ) ;
return & V_216 -> V_180 ;
}
static void F_213 ( struct V_179 * V_180 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_176 ( V_3 -> V_2 , V_180 , V_3 -> V_177 . V_178 ) ;
}
static void F_133 ( struct V_179 * V_180 )
{
if ( ! V_180 -> V_190 )
return;
F_213 ( V_180 ) ;
F_111 ( V_180 ) ;
F_109 ( V_180 ) ;
V_180 -> V_190 = false ;
}
static T_4 * F_214 ( struct V_27 * V_198 ,
unsigned long V_89 )
{
struct V_234 * V_223 ;
T_4 * V_186 , * V_192 ;
V_223 = V_198 -> V_223 [ F_215 ( V_89 ) ] ;
if ( ! V_223 )
return NULL ;
V_186 = V_223 -> V_237 [ F_216 ( V_89 ) ] ;
if ( ! V_186 ) {
V_186 = F_116 ( & V_198 -> V_180 , V_89 , V_150 , & V_192 ,
V_318 ) ;
V_223 -> V_237 [ F_216 ( V_89 ) ] = V_192 ;
} else
V_186 += F_120 ( 0 , V_89 ) ;
F_133 ( & V_198 -> V_180 ) ;
return V_186 ;
}
static T_9 F_217 ( struct V_27 * V_198 ,
unsigned long V_89 ,
T_10 V_319 ,
int V_320 )
{
T_4 * V_186 , V_197 ;
F_79 ( V_89 > V_198 -> V_221 ) ;
V_319 &= V_152 ;
V_186 = F_214 ( V_198 , V_89 ) ;
if ( ! V_186 )
return V_252 ;
V_197 = V_319 | V_204 | V_205 ;
if ( V_320 == V_321 )
V_197 |= V_207 ;
else if ( V_320 == V_322 )
V_197 |= V_209 ;
else if ( V_320 == V_323 )
V_197 |= V_207 | V_209 ;
F_79 ( * V_186 ) ;
* V_186 = V_197 ;
return ( T_9 ) V_89 ;
}
static void F_218 ( struct V_27 * V_198 ,
unsigned long V_89 )
{
struct V_234 * V_223 ;
T_4 * V_186 ;
if ( V_89 >= V_198 -> V_221 )
return;
V_223 = V_198 -> V_223 [ F_215 ( V_89 ) ] ;
if ( ! V_223 )
return;
V_186 = V_223 -> V_237 [ F_216 ( V_89 ) ] ;
if ( ! V_186 )
return;
V_186 += F_120 ( 0 , V_89 ) ;
F_79 ( ! * V_186 ) ;
* V_186 = 0ULL ;
}
static T_9 F_219 ( struct V_10 * V_11 ,
struct V_27 * V_216 ,
T_10 V_319 ,
T_7 V_146 ,
int V_324 ,
bool V_325 ,
T_4 V_35 )
{
T_9 V_235 = V_319 & ~ V_152 ;
T_9 V_89 , V_245 , V_29 ;
unsigned int V_148 ;
unsigned long V_244 = 0 ;
int V_23 ;
V_148 = F_86 ( V_319 , V_146 , V_150 ) ;
V_319 &= V_152 ;
F_63 ( V_77 ) ;
if ( V_148 > 1 )
F_63 ( V_73 ) ;
if ( V_325 )
V_244 = ( 1UL << F_220 ( V_146 ) ) - 1 ;
V_90:
V_89 = F_150 ( V_11 , V_216 , V_148 , V_244 ,
V_35 ) ;
if ( F_151 ( V_89 == V_252 ) ) {
V_216 -> V_247 = V_216 -> V_221 ;
if ( F_141 ( V_216 , false , V_318 ) )
goto V_310;
goto V_90;
}
V_245 = V_89 ;
for ( V_23 = 0 ; V_23 < V_148 ; ++ V_23 ) {
V_29 = F_217 ( V_216 , V_245 , V_319 , V_324 ) ;
if ( V_29 == V_252 )
goto V_326;
V_319 += V_150 ;
V_245 += V_150 ;
}
V_89 += V_235 ;
F_221 ( V_76 , V_146 ) ;
if ( F_151 ( V_216 -> V_251 && ! V_65 ) ) {
F_108 ( & V_216 -> V_180 ) ;
V_216 -> V_251 = false ;
} else if ( F_151 ( V_327 ) )
F_107 ( & V_216 -> V_180 , V_89 , V_146 ) ;
V_310:
return V_89 ;
V_326:
for ( -- V_23 ; V_23 >= 0 ; -- V_23 ) {
V_245 -= V_150 ;
F_218 ( V_216 , V_245 ) ;
}
F_152 ( V_216 , V_89 , V_148 ) ;
return V_252 ;
}
static void F_222 ( struct V_27 * V_216 ,
T_9 V_328 ,
T_7 V_146 ,
int V_324 )
{
T_9 V_329 ;
T_9 V_23 , V_245 ;
unsigned int V_148 ;
if ( ( V_328 == V_252 ) ||
( V_328 + V_146 > V_216 -> V_221 ) )
return;
V_329 = V_328 ;
V_148 = F_86 ( V_328 , V_146 , V_150 ) ;
V_328 &= V_152 ;
V_245 = V_328 ;
for ( V_23 = 0 ; V_23 < V_148 ; ++ V_23 ) {
F_218 ( V_216 , V_245 ) ;
V_245 += V_150 ;
}
F_223 ( V_76 , V_146 ) ;
F_152 ( V_216 , V_328 , V_148 ) ;
if ( V_65 || V_216 -> V_251 ) {
F_107 ( & V_216 -> V_180 , V_329 , V_146 ) ;
V_216 -> V_251 = false ;
}
}
static T_9 F_224 ( struct V_10 * V_11 , struct V_195 * V_195 ,
unsigned long V_235 , T_7 V_146 ,
enum V_330 V_324 ,
struct V_331 * V_332 )
{
unsigned long V_4 ;
struct V_179 * V_180 ;
T_9 V_218 ;
T_4 V_35 ;
T_10 V_319 = F_225 ( V_195 ) + V_235 ;
F_63 ( V_67 ) ;
V_180 = F_210 ( V_11 ) ;
if ( F_226 ( V_180 ) == - V_202 )
return ( T_9 ) V_319 ;
else if ( F_26 ( V_180 ) )
return V_252 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_218 = F_219 ( V_11 , V_180 -> V_275 , V_319 , V_146 , V_324 , false ,
V_35 ) ;
if ( V_218 == V_252 )
goto V_310;
F_110 ( V_180 ) ;
V_310:
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_218 ;
}
static void F_227 ( struct V_10 * V_11 , T_9 V_328 , T_7 V_146 ,
enum V_330 V_324 , struct V_331 * V_332 )
{
unsigned long V_4 ;
struct V_179 * V_180 ;
F_63 ( V_68 ) ;
V_180 = F_210 ( V_11 ) ;
if ( F_26 ( V_180 ) )
return;
F_4 ( & V_180 -> V_170 , V_4 ) ;
F_222 ( V_180 -> V_275 , V_328 , V_146 , V_324 ) ;
F_110 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
}
static int F_228 ( struct V_10 * V_11 , struct V_333 * V_334 ,
int V_335 , enum V_330 V_324 ,
struct V_331 * V_332 )
{
unsigned long V_4 ;
struct V_179 * V_180 ;
int V_23 ;
struct V_333 * V_149 ;
T_10 V_319 ;
int V_336 = 0 ;
T_4 V_35 ;
F_63 ( V_69 ) ;
V_180 = F_210 ( V_11 ) ;
if ( F_26 ( V_180 ) )
return 0 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
F_229 (sglist, s, nelems, i) {
V_319 = F_230 ( V_149 ) ;
V_149 -> V_337 = F_219 ( V_11 , V_180 -> V_275 ,
V_319 , V_149 -> V_338 , V_324 , false ,
V_35 ) ;
if ( V_149 -> V_337 ) {
V_149 -> V_339 = V_149 -> V_338 ;
V_336 ++ ;
} else
goto V_340;
}
F_110 ( V_180 ) ;
V_310:
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_336 ;
V_340:
F_229 (sglist, s, mapped_elems, i) {
if ( V_149 -> V_337 )
F_222 ( V_180 -> V_275 , V_149 -> V_337 ,
V_149 -> V_339 , V_324 ) ;
V_149 -> V_337 = V_149 -> V_339 = 0 ;
}
V_336 = 0 ;
goto V_310;
}
static void F_231 ( struct V_10 * V_11 , struct V_333 * V_334 ,
int V_335 , enum V_330 V_324 ,
struct V_331 * V_332 )
{
unsigned long V_4 ;
struct V_179 * V_180 ;
struct V_333 * V_149 ;
int V_23 ;
F_63 ( V_70 ) ;
V_180 = F_210 ( V_11 ) ;
if ( F_26 ( V_180 ) )
return;
F_4 ( & V_180 -> V_170 , V_4 ) ;
F_229 (sglist, s, nelems, i) {
F_222 ( V_180 -> V_275 , V_149 -> V_337 ,
V_149 -> V_339 , V_324 ) ;
V_149 -> V_337 = V_149 -> V_339 = 0 ;
}
F_110 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
}
static void * F_232 ( struct V_10 * V_11 , T_7 V_146 ,
T_9 * V_328 , T_8 V_341 ,
struct V_331 * V_332 )
{
unsigned long V_4 ;
void * V_342 ;
struct V_179 * V_180 ;
T_10 V_319 ;
T_4 V_35 = V_11 -> V_343 ;
F_63 ( V_71 ) ;
V_180 = F_210 ( V_11 ) ;
if ( F_226 ( V_180 ) == - V_202 ) {
V_342 = ( void * ) F_233 ( V_341 , F_220 ( V_146 ) ) ;
* V_328 = F_81 ( V_342 ) ;
return V_342 ;
} else if ( F_26 ( V_180 ) )
return NULL ;
V_35 = V_11 -> V_343 ;
V_341 &= ~ ( V_344 | V_345 | V_346 ) ;
V_341 |= V_347 ;
V_342 = ( void * ) F_233 ( V_341 , F_220 ( V_146 ) ) ;
if ( ! V_342 )
return NULL ;
V_319 = F_115 ( V_342 ) ;
if ( ! V_35 )
V_35 = * V_11 -> V_35 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
* V_328 = F_219 ( V_11 , V_180 -> V_275 , V_319 ,
V_146 , V_323 , true , V_35 ) ;
if ( * V_328 == V_252 ) {
F_6 ( & V_180 -> V_170 , V_4 ) ;
goto V_57;
}
F_110 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_342 ;
V_57:
F_234 ( ( unsigned long ) V_342 , F_220 ( V_146 ) ) ;
return NULL ;
}
static void F_235 ( struct V_10 * V_11 , T_7 V_146 ,
void * V_342 , T_9 V_328 ,
struct V_331 * V_332 )
{
unsigned long V_4 ;
struct V_179 * V_180 ;
F_63 ( V_72 ) ;
V_180 = F_210 ( V_11 ) ;
if ( F_26 ( V_180 ) )
goto V_348;
F_4 ( & V_180 -> V_170 , V_4 ) ;
F_222 ( V_180 -> V_275 , V_328 , V_146 , V_323 ) ;
F_110 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
V_348:
F_234 ( ( unsigned long ) V_342 , F_220 ( V_146 ) ) ;
}
static int F_236 ( struct V_10 * V_11 , T_4 V_349 )
{
return F_22 ( V_11 ) ;
}
static void T_3 F_237 ( void )
{
struct V_1 * V_3 ;
struct V_27 * V_216 ;
struct V_12 * V_11 = NULL ;
T_1 V_2 ;
F_45 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
if ( ! V_350 && V_3 -> V_52 ) {
F_238 () ;
V_3 -> V_301 = true ;
F_200 ( & V_11 -> V_11 , V_304 ) ;
F_31 ( L_30 ,
F_35 ( & V_11 -> V_11 ) ) ;
}
if ( F_204 ( & V_11 -> V_11 ) )
continue;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_216 = F_174 () ;
if ( ! V_216 )
continue;
F_139 ( V_216 , V_2 ) ;
V_216 -> V_34 = V_2 ;
F_200 ( & V_11 -> V_11 , & V_216 -> V_180 ) ;
F_5 ( & V_216 -> V_255 , & V_32 ) ;
}
}
static unsigned F_239 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_13 = NULL ;
unsigned V_351 = 0 ;
F_45 (pdev) {
if ( ! F_22 ( & V_13 -> V_11 ) ) {
F_40 ( & V_13 -> V_11 ) ;
V_351 += 1 ;
continue;
}
V_3 = F_16 ( & V_13 -> V_11 ) ;
if ( ! V_3 -> V_301 )
V_13 -> V_11 . V_17 . V_313 = & V_314 ;
else
V_13 -> V_11 . V_17 . V_313 = & V_352 ;
}
return V_351 ;
}
void T_3 F_240 ( void )
{
F_241 ( & V_316 , & V_353 ) ;
}
int T_3 F_242 ( void )
{
struct V_51 * V_18 ;
int V_29 , V_351 ;
F_143 (iommu) {
V_18 -> V_225 = F_174 () ;
if ( V_18 -> V_225 == NULL )
return - V_48 ;
V_18 -> V_225 -> V_180 . V_4 |= V_354 ;
V_29 = F_138 ( V_18 ) ;
if ( V_29 )
goto V_355;
}
F_237 () ;
V_356 = 1 ;
V_357 = 0 ;
V_351 = F_239 () ;
if ( V_351 && V_358 > V_359 ) {
V_357 = 1 ;
}
F_50 () ;
if ( V_65 )
F_31 ( L_31 ) ;
else
F_31 ( L_32 ) ;
return 0 ;
V_355:
F_143 (iommu) {
F_173 ( V_18 -> V_225 ) ;
}
return V_29 ;
}
static void F_243 ( struct V_179 * V_180 )
{
struct V_1 * V_28 ;
unsigned long V_4 ;
F_157 ( & V_257 , V_4 ) ;
while ( ! F_21 ( & V_180 -> V_273 ) ) {
V_28 = F_244 ( & V_180 -> V_273 ,
struct V_1 , V_255 ) ;
F_202 ( V_28 ) ;
}
F_159 ( & V_257 , V_4 ) ;
}
static void F_245 ( struct V_179 * V_180 )
{
if ( ! V_180 )
return;
F_155 ( V_180 ) ;
if ( V_180 -> V_181 )
F_160 ( V_180 -> V_181 ) ;
F_9 ( V_180 ) ;
}
static struct V_179 * F_246 ( void )
{
struct V_179 * V_180 ;
V_180 = F_2 ( sizeof( * V_180 ) , V_5 ) ;
if ( ! V_180 )
return NULL ;
F_175 ( & V_180 -> V_170 ) ;
F_247 ( & V_180 -> V_360 ) ;
V_180 -> V_181 = F_156 () ;
if ( ! V_180 -> V_181 )
goto V_298;
F_3 ( & V_180 -> V_273 ) ;
F_154 ( V_180 ) ;
return V_180 ;
V_298:
F_9 ( V_180 ) ;
return NULL ;
}
static int T_3 F_238 ( void )
{
if ( V_304 != NULL )
return 0 ;
V_304 = F_246 () ;
if ( ! V_304 )
return - V_48 ;
V_304 -> V_187 = V_261 ;
return 0 ;
}
static int F_248 ( struct V_361 * V_198 )
{
struct V_179 * V_180 ;
V_180 = F_246 () ;
if ( ! V_180 )
goto V_57;
V_180 -> V_187 = V_264 ;
V_180 -> V_189 = ( void * ) F_113 ( V_5 ) ;
if ( ! V_180 -> V_189 )
goto V_57;
V_180 -> V_361 = V_198 ;
V_198 -> V_275 = V_180 ;
V_198 -> V_362 . V_363 = 0 ;
V_198 -> V_362 . V_364 = ~ 0ULL ;
V_198 -> V_362 . V_365 = true ;
return 0 ;
V_57:
F_245 ( V_180 ) ;
return - V_48 ;
}
static void F_249 ( struct V_361 * V_198 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
if ( ! V_180 )
return;
if ( V_180 -> V_290 > 0 )
F_243 ( V_180 ) ;
F_117 ( V_180 -> V_290 != 0 ) ;
if ( V_180 -> V_187 != V_261 )
F_162 ( V_180 ) ;
if ( V_180 -> V_4 & V_281 )
F_172 ( V_180 ) ;
F_245 ( V_180 ) ;
V_198 -> V_275 = NULL ;
}
static void F_250 ( struct V_361 * V_198 ,
struct V_10 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_17 . V_18 ;
struct V_51 * V_18 ;
T_1 V_2 ;
if ( ! F_22 ( V_11 ) )
return;
V_2 = F_13 ( V_11 ) ;
if ( V_3 -> V_180 != NULL )
F_203 ( V_11 ) ;
V_18 = V_37 [ V_2 ] ;
if ( ! V_18 )
return;
F_95 ( V_18 ) ;
}
static int F_251 ( struct V_361 * V_198 ,
struct V_10 * V_11 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
struct V_1 * V_3 ;
struct V_51 * V_18 ;
int V_29 ;
if ( ! F_22 ( V_11 ) )
return - V_202 ;
V_3 = V_11 -> V_17 . V_18 ;
V_18 = V_37 [ V_3 -> V_2 ] ;
if ( ! V_18 )
return - V_202 ;
if ( V_3 -> V_180 )
F_203 ( V_11 ) ;
V_29 = F_200 ( V_11 , V_180 ) ;
F_95 ( V_18 ) ;
return V_29 ;
}
static int F_252 ( struct V_361 * V_198 , unsigned long V_366 ,
T_10 V_319 , T_7 V_191 , int V_367 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
int V_200 = 0 ;
int V_29 ;
if ( V_180 -> V_187 == V_261 )
return - V_202 ;
if ( V_367 & V_368 )
V_200 |= V_206 ;
if ( V_367 & V_369 )
V_200 |= V_208 ;
F_253 ( & V_180 -> V_360 ) ;
V_29 = F_129 ( V_180 , V_366 , V_319 , V_200 , V_191 ) ;
F_254 ( & V_180 -> V_360 ) ;
return V_29 ;
}
static T_7 F_255 ( struct V_361 * V_198 , unsigned long V_366 ,
T_7 V_191 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
T_7 V_210 ;
if ( V_180 -> V_187 == V_261 )
return - V_202 ;
F_253 ( & V_180 -> V_360 ) ;
V_210 = F_134 ( V_180 , V_366 , V_191 ) ;
F_254 ( & V_180 -> V_360 ) ;
F_109 ( V_180 ) ;
return V_210 ;
}
static T_10 F_256 ( struct V_361 * V_198 ,
T_9 V_366 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_370 ;
T_10 V_319 ;
T_4 * V_186 , V_197 ;
if ( V_180 -> V_187 == V_261 )
return V_366 ;
V_186 = F_126 ( V_180 , V_366 ) ;
if ( ! V_186 || ! F_123 ( * V_186 ) )
return 0 ;
if ( F_124 ( * V_186 ) == 0 )
V_370 = V_150 - 1 ;
else
V_370 = F_127 ( * V_186 ) - 1 ;
V_197 = * V_186 & V_371 ;
V_319 = ( V_197 & ~ V_370 ) | ( V_366 & V_370 ) ;
return V_319 ;
}
static bool F_257 ( enum V_372 V_373 )
{
switch ( V_373 ) {
case V_374 :
return true ;
case V_375 :
return ( V_376 == 1 ) ;
case V_377 :
return false ;
}
return false ;
}
int T_3 F_258 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_11 = NULL ;
int V_29 ;
V_29 = F_238 () ;
if ( V_29 )
return V_29 ;
F_45 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
V_3 -> V_301 = true ;
F_200 ( & V_11 -> V_11 , V_304 ) ;
}
F_50 () ;
F_31 ( L_33 ) ;
return 0 ;
}
int F_259 ( struct V_305 * V_306 )
{
return F_260 ( & V_124 , V_306 ) ;
}
int F_261 ( struct V_305 * V_306 )
{
return F_262 ( & V_124 , V_306 ) ;
}
void F_263 ( struct V_361 * V_198 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_180 -> V_187 = V_261 ;
V_180 -> V_190 = true ;
F_133 ( V_180 ) ;
F_162 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
}
int F_264 ( struct V_361 * V_198 , int V_378 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_379 , V_29 ;
if ( V_378 <= 0 || V_378 > ( V_380 + 1 ) )
return - V_202 ;
for ( V_379 = 0 ; ( V_378 - 1 ) & ~ 0x1ff ; V_378 >>= 9 )
V_379 += 1 ;
if ( V_379 > V_381 )
return - V_202 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = - V_203 ;
if ( V_180 -> V_290 > 0 || V_180 -> V_4 & V_281 )
goto V_310;
V_29 = - V_48 ;
V_180 -> V_271 = ( void * ) F_113 ( V_318 ) ;
if ( V_180 -> V_271 == NULL )
goto V_310;
V_180 -> V_270 = V_379 ;
V_180 -> V_4 |= V_281 ;
V_180 -> V_190 = true ;
F_133 ( V_180 ) ;
V_29 = 0 ;
V_310:
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
static int F_265 ( struct V_179 * V_180 , int V_121 ,
T_4 V_89 , bool V_146 )
{
struct V_1 * V_3 ;
struct V_83 V_84 ;
int V_23 , V_29 ;
if ( ! ( V_180 -> V_4 & V_281 ) )
return - V_202 ;
F_88 ( & V_84 , V_180 -> V_181 , V_121 , V_89 , V_146 ) ;
for ( V_23 = 0 ; V_23 < V_182 ; ++ V_23 ) {
if ( V_180 -> V_183 [ V_23 ] == 0 )
continue;
V_29 = F_94 ( V_184 [ V_23 ] , & V_84 ) ;
if ( V_29 != 0 )
goto V_310;
}
F_110 ( V_180 ) ;
F_11 (dev_data, &domain->dev_list, list) {
struct V_51 * V_18 ;
int V_156 ;
F_117 ( ! V_3 -> V_177 . V_178 ) ;
V_156 = V_3 -> V_177 . V_156 ;
V_18 = V_37 [ V_3 -> V_2 ] ;
F_89 ( & V_84 , V_3 -> V_2 , V_121 ,
V_156 , V_89 , V_146 ) ;
V_29 = F_94 ( V_18 , & V_84 ) ;
if ( V_29 != 0 )
goto V_310;
}
F_110 ( V_180 ) ;
V_29 = 0 ;
V_310:
return V_29 ;
}
static int F_266 ( struct V_179 * V_180 , int V_121 ,
T_4 V_89 )
{
F_63 ( V_79 ) ;
return F_265 ( V_180 , V_121 , V_89 , false ) ;
}
int F_267 ( struct V_361 * V_198 , int V_121 ,
T_4 V_89 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = F_266 ( V_180 , V_121 , V_89 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
static int F_268 ( struct V_179 * V_180 , int V_121 )
{
F_63 ( V_80 ) ;
return F_265 ( V_180 , V_121 , V_151 ,
true ) ;
}
int F_269 ( struct V_361 * V_198 , int V_121 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = F_268 ( V_180 , V_121 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
static T_4 * F_270 ( T_4 * V_260 , int V_193 , int V_121 , bool V_382 )
{
int V_228 ;
T_4 * V_186 ;
while ( true ) {
V_228 = ( V_121 >> ( 9 * V_193 ) ) & 0x1ff ;
V_186 = & V_260 [ V_228 ] ;
if ( V_193 == 0 )
break;
if ( ! ( * V_186 & V_269 ) ) {
if ( ! V_382 )
return NULL ;
V_260 = ( void * ) F_113 ( V_318 ) ;
if ( V_260 == NULL )
return NULL ;
* V_186 = F_81 ( V_260 ) | V_269 ;
}
V_260 = F_170 ( * V_186 & V_152 ) ;
V_193 -= 1 ;
}
return V_186 ;
}
static int F_271 ( struct V_179 * V_180 , int V_121 ,
unsigned long V_383 )
{
T_4 * V_186 ;
if ( V_180 -> V_187 != V_261 )
return - V_202 ;
V_186 = F_270 ( V_180 -> V_271 , V_180 -> V_270 , V_121 , true ) ;
if ( V_186 == NULL )
return - V_48 ;
* V_186 = ( V_383 & V_152 ) | V_269 ;
return F_268 ( V_180 , V_121 ) ;
}
static int F_272 ( struct V_179 * V_180 , int V_121 )
{
T_4 * V_186 ;
if ( V_180 -> V_187 != V_261 )
return - V_202 ;
V_186 = F_270 ( V_180 -> V_271 , V_180 -> V_270 , V_121 , false ) ;
if ( V_186 == NULL )
return 0 ;
* V_186 = 0 ;
return F_268 ( V_180 , V_121 ) ;
}
int F_273 ( struct V_361 * V_198 , int V_121 ,
unsigned long V_383 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = F_271 ( V_180 , V_121 , V_383 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
int F_274 ( struct V_361 * V_198 , int V_121 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = F_272 ( V_180 , V_121 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
int F_275 ( struct V_12 * V_13 , int V_121 ,
int V_131 , int V_123 )
{
struct V_1 * V_3 ;
struct V_51 * V_18 ;
struct V_83 V_84 ;
F_63 ( V_78 ) ;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_18 = V_37 [ V_3 -> V_2 ] ;
F_90 ( & V_84 , V_3 -> V_2 , V_121 , V_131 ,
V_123 , V_3 -> V_302 ) ;
return F_94 ( V_18 , & V_84 ) ;
}
struct V_361 * F_276 ( struct V_12 * V_13 )
{
struct V_179 * V_180 ;
V_180 = F_210 ( & V_13 -> V_11 ) ;
if ( F_26 ( V_180 ) )
return NULL ;
if ( ! ( V_180 -> V_4 & V_281 ) )
return NULL ;
return V_180 -> V_361 ;
}
void F_277 ( struct V_12 * V_13 , T_2 V_25 )
{
struct V_1 * V_3 ;
if ( ! F_278 () )
return;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_3 -> V_26 |= ( 1 << V_25 ) ;
}
int F_279 ( struct V_12 * V_13 ,
struct F_279 * V_384 )
{
int V_385 ;
int V_24 ;
if ( V_13 == NULL || V_384 == NULL )
return - V_202 ;
if ( ! F_278 () )
return - V_202 ;
memset ( V_384 , 0 , sizeof( * V_384 ) ) ;
V_24 = F_18 ( V_13 , V_20 ) ;
if ( V_24 )
V_384 -> V_4 |= V_386 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( V_24 )
V_384 -> V_4 |= V_387 ;
V_24 = F_18 ( V_13 , V_22 ) ;
if ( V_24 ) {
int V_388 ;
V_385 = 1 << ( 9 * ( V_381 + 1 ) ) ;
V_385 = F_280 ( V_385 , ( 1 << 20 ) ) ;
V_384 -> V_4 |= V_389 ;
V_384 -> V_385 = F_280 ( F_281 ( V_13 ) , V_385 ) ;
V_388 = F_282 ( V_13 ) ;
if ( V_388 & V_390 )
V_384 -> V_4 |= V_391 ;
if ( V_388 & V_392 )
V_384 -> V_4 |= V_393 ;
}
return 0 ;
}
static void F_283 ( T_1 V_2 , struct V_394 * V_395 )
{
T_4 V_396 ;
V_396 = V_43 [ V_2 ] . V_40 [ 2 ] ;
V_396 &= ~ V_397 ;
V_396 |= F_115 ( V_395 -> V_395 ) ;
V_396 |= V_398 ;
V_396 |= V_399 ;
V_396 |= V_400 ;
V_43 [ V_2 ] . V_40 [ 2 ] = V_396 ;
}
static struct V_394 * F_284 ( T_1 V_2 , bool V_401 )
{
struct V_394 * V_395 = NULL ;
struct V_51 * V_18 ;
unsigned long V_4 ;
T_1 V_30 ;
F_157 ( & V_257 , V_4 ) ;
V_18 = V_37 [ V_2 ] ;
if ( ! V_18 )
goto V_9;
V_395 = V_402 [ V_2 ] ;
if ( V_395 )
goto V_310;
V_30 = V_31 [ V_2 ] ;
V_395 = V_402 [ V_30 ] ;
if ( V_395 ) {
V_402 [ V_2 ] = V_395 ;
F_283 ( V_2 , V_395 ) ;
F_96 ( V_18 , V_2 ) ;
goto V_310;
}
V_395 = F_2 ( sizeof( * V_395 ) , V_318 ) ;
if ( ! V_395 )
goto V_310;
F_175 ( & V_395 -> V_170 ) ;
if ( V_401 )
V_395 -> V_403 = 32 ;
V_395 -> V_395 = F_285 ( V_404 , V_318 ) ;
if ( ! V_395 -> V_395 ) {
F_9 ( V_395 ) ;
V_395 = NULL ;
goto V_310;
}
memset ( V_395 -> V_395 , 0 , V_405 * sizeof( T_2 ) ) ;
if ( V_401 ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < 32 ; ++ V_23 )
V_395 -> V_395 [ V_23 ] = V_406 ;
}
V_402 [ V_2 ] = V_395 ;
F_283 ( V_2 , V_395 ) ;
F_96 ( V_18 , V_2 ) ;
if ( V_2 != V_30 ) {
V_402 [ V_30 ] = V_395 ;
F_283 ( V_30 , V_395 ) ;
F_96 ( V_18 , V_30 ) ;
}
V_310:
F_95 ( V_18 ) ;
V_9:
F_159 ( & V_257 , V_4 ) ;
return V_395 ;
}
static int F_286 ( struct V_407 * V_408 , T_1 V_2 , int V_88 )
{
struct V_394 * V_395 ;
unsigned long V_4 ;
int V_228 , V_409 ;
V_395 = F_284 ( V_2 , false ) ;
if ( ! V_395 )
return - V_410 ;
F_4 ( & V_395 -> V_170 , V_4 ) ;
for ( V_409 = 0 , V_228 = V_395 -> V_403 ;
V_228 < V_405 ;
++ V_228 ) {
if ( V_395 -> V_395 [ V_228 ] == 0 )
V_409 += 1 ;
else
V_409 = 0 ;
if ( V_409 == V_88 ) {
struct V_411 * V_412 ;
for (; V_409 != 0 ; -- V_409 )
V_395 -> V_395 [ V_228 - V_409 + 1 ] = V_406 ;
V_228 -= V_88 - 1 ;
V_408 -> V_413 = 1 ;
V_412 = & V_408 -> V_411 ;
V_412 -> V_2 = V_2 ;
V_412 -> V_228 = V_228 ;
goto V_310;
}
}
V_228 = - V_414 ;
V_310:
F_6 ( & V_395 -> V_170 , V_4 ) ;
return V_228 ;
}
static int F_287 ( T_1 V_2 , int V_228 , union V_415 * V_415 )
{
struct V_394 * V_395 ;
unsigned long V_4 ;
V_395 = F_284 ( V_2 , false ) ;
if ( ! V_395 )
return - V_48 ;
F_4 ( & V_395 -> V_170 , V_4 ) ;
V_415 -> V_416 = V_395 -> V_395 [ V_228 ] ;
F_6 ( & V_395 -> V_170 , V_4 ) ;
return 0 ;
}
static int F_288 ( T_1 V_2 , int V_228 , union V_415 V_415 )
{
struct V_394 * V_395 ;
struct V_51 * V_18 ;
unsigned long V_4 ;
V_18 = V_37 [ V_2 ] ;
if ( V_18 == NULL )
return - V_202 ;
V_395 = F_284 ( V_2 , false ) ;
if ( ! V_395 )
return - V_48 ;
F_4 ( & V_395 -> V_170 , V_4 ) ;
V_395 -> V_395 [ V_228 ] = V_415 . V_416 ;
F_6 ( & V_395 -> V_170 , V_4 ) ;
F_100 ( V_18 , V_2 ) ;
F_95 ( V_18 ) ;
return 0 ;
}
static void F_289 ( T_1 V_2 , int V_228 )
{
struct V_394 * V_395 ;
struct V_51 * V_18 ;
unsigned long V_4 ;
V_18 = V_37 [ V_2 ] ;
if ( V_18 == NULL )
return;
V_395 = F_284 ( V_2 , false ) ;
if ( ! V_395 )
return;
F_4 ( & V_395 -> V_170 , V_4 ) ;
V_395 -> V_395 [ V_228 ] = 0 ;
F_6 ( & V_395 -> V_170 , V_4 ) ;
F_100 ( V_18 , V_2 ) ;
F_95 ( V_18 ) ;
}
static int F_290 ( int V_130 , struct V_417 * V_28 ,
unsigned int V_418 , int V_419 ,
struct V_420 * V_421 )
{
struct V_394 * V_395 ;
struct V_411 * V_412 ;
struct V_407 * V_408 ;
union V_415 V_415 ;
int V_422 ;
int V_228 ;
int V_2 ;
int V_29 ;
V_408 = V_407 ( V_130 ) ;
if ( ! V_408 )
return - V_202 ;
V_412 = & V_408 -> V_411 ;
V_422 = F_291 ( V_421 -> V_401 ) ;
V_2 = F_292 ( V_422 ) ;
if ( V_2 < 0 )
return V_2 ;
V_395 = F_284 ( V_2 , true ) ;
if ( V_395 == NULL )
return - V_48 ;
V_228 = V_421 -> V_423 ;
V_408 -> V_413 = 1 ;
V_412 -> V_2 = V_2 ;
V_412 -> V_228 = V_228 ;
V_415 . V_416 = 0 ;
V_415 . V_424 . V_419 = V_419 ;
V_415 . V_424 . V_425 = V_426 -> V_427 ;
V_415 . V_424 . V_418 = V_418 ;
V_415 . V_424 . V_428 = V_426 -> V_429 ;
V_415 . V_424 . V_430 = 1 ;
V_29 = F_288 ( V_2 , V_228 , V_415 ) ;
if ( V_29 )
return V_29 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_419 = V_228 ;
V_28 -> V_349 = 0 ;
V_28 -> V_431 = V_421 -> V_431 ;
V_28 -> V_432 = V_421 -> V_432 ;
if ( V_421 -> V_431 )
V_28 -> V_349 = 1 ;
return 0 ;
}
static int F_293 ( struct V_433 * V_40 , const struct V_434 * V_349 ,
bool V_435 )
{
struct V_411 * V_412 ;
unsigned int V_436 , V_130 ;
struct V_407 * V_408 ;
union V_415 V_415 ;
int V_437 ;
if ( ! F_294 ( V_438 ) )
return - 1 ;
V_408 = F_295 ( V_40 ) ;
V_130 = V_40 -> V_130 ;
V_412 = & V_408 -> V_411 ;
if ( ! F_296 ( V_349 , V_439 ) )
return - V_202 ;
if ( F_287 ( V_412 -> V_2 , V_412 -> V_228 , & V_415 ) )
return - V_203 ;
if ( F_297 ( V_130 , V_408 , V_349 ) )
return - V_203 ;
V_437 = V_426 -> V_440 ( V_408 -> V_180 , V_349 , & V_436 ) ;
if ( V_437 ) {
if ( F_297 ( V_130 , V_408 , V_40 -> V_441 ) )
F_37 ( L_34 , V_130 ) ;
return V_437 ;
}
V_415 . V_424 . V_419 = V_408 -> V_419 ;
V_415 . V_424 . V_418 = V_436 ;
F_288 ( V_412 -> V_2 , V_412 -> V_228 , V_415 ) ;
if ( V_408 -> V_442 )
F_298 ( V_408 ) ;
F_299 ( V_40 -> V_441 , V_349 ) ;
return 0 ;
}
static int F_300 ( int V_130 )
{
struct V_411 * V_412 ;
struct V_407 * V_408 ;
V_408 = V_407 ( V_130 ) ;
if ( ! V_408 )
return - V_202 ;
V_412 = & V_408 -> V_411 ;
F_289 ( V_412 -> V_2 , V_412 -> V_228 ) ;
return 0 ;
}
static void F_301 ( struct V_12 * V_13 ,
unsigned int V_130 , unsigned int V_436 ,
struct V_443 * V_444 , T_6 V_445 )
{
struct V_411 * V_412 ;
struct V_407 * V_408 ;
union V_415 V_415 ;
V_408 = V_407 ( V_130 ) ;
if ( ! V_408 )
return;
V_412 = & V_408 -> V_411 ;
V_415 . V_416 = 0 ;
V_415 . V_424 . V_419 = V_408 -> V_419 ;
V_415 . V_424 . V_425 = V_426 -> V_427 ;
V_415 . V_424 . V_418 = V_436 ;
V_415 . V_424 . V_428 = V_426 -> V_429 ;
V_415 . V_424 . V_430 = 1 ;
F_288 ( V_412 -> V_2 , V_412 -> V_228 , V_415 ) ;
V_444 -> V_446 = V_447 ;
V_444 -> V_448 = V_239 ;
V_444 -> V_40 = V_412 -> V_228 ;
}
static int F_302 ( struct V_12 * V_13 , int V_130 , int V_449 )
{
struct V_407 * V_408 ;
int V_228 ;
T_1 V_2 ;
if ( ! V_13 )
return - V_202 ;
V_408 = V_407 ( V_130 ) ;
if ( ! V_408 )
return - V_202 ;
V_2 = F_13 ( & V_13 -> V_11 ) ;
V_228 = F_286 ( V_408 , V_2 , V_449 ) ;
return V_228 < 0 ? V_405 : V_228 ;
}
static int F_303 ( struct V_12 * V_13 , unsigned int V_130 ,
int V_228 , int V_235 )
{
struct V_411 * V_412 ;
struct V_407 * V_408 ;
T_1 V_2 ;
if ( ! V_13 )
return - V_202 ;
V_408 = V_407 ( V_130 ) ;
if ( ! V_408 )
return - V_202 ;
if ( V_228 >= V_405 )
return 0 ;
V_2 = F_13 ( & V_13 -> V_11 ) ;
V_412 = & V_408 -> V_411 ;
V_408 -> V_413 = 1 ;
V_412 -> V_2 = V_2 ;
V_412 -> V_228 = V_228 + V_235 ;
return 0 ;
}
static int F_304 ( unsigned int V_130 , unsigned int V_181 )
{
struct V_411 * V_412 ;
struct V_407 * V_408 ;
int V_228 , V_2 ;
V_408 = V_407 ( V_130 ) ;
if ( ! V_408 )
return - V_202 ;
V_412 = & V_408 -> V_411 ;
V_2 = F_305 ( V_181 ) ;
if ( V_2 < 0 )
return V_2 ;
V_228 = F_286 ( V_408 , V_2 , 1 ) ;
if ( V_228 < 0 )
return V_228 ;
V_408 -> V_413 = 1 ;
V_412 -> V_2 = V_2 ;
V_412 -> V_228 = V_228 ;
return 0 ;
}
