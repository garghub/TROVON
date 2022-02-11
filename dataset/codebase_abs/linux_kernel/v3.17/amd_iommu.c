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
if ( ! F_23 ( V_11 ) )
return false ;
V_2 = F_13 ( V_11 ) ;
if ( V_2 > V_36 )
return false ;
if ( V_37 [ V_2 ] == NULL )
return false ;
return true ;
}
static int F_24 ( struct V_10 * V_11 )
{
struct V_38 * V_39 ;
V_39 = F_25 ( V_11 ) ;
if ( F_26 ( V_39 ) )
return F_27 ( V_39 ) ;
F_28 ( V_39 ) ;
return 0 ;
}
static int F_29 ( struct V_12 * V_13 , T_1 V_30 , void * V_40 )
{
* ( T_1 * ) V_40 = V_30 ;
return 0 ;
}
static T_1 F_30 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
T_1 V_2 , V_41 , V_42 ;
V_2 = F_13 ( V_11 ) ;
V_41 = V_31 [ V_2 ] ;
F_31 ( V_13 , F_29 , & V_42 ) ;
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
F_32 ( L_1
L_2
L_3 , F_33 ( V_41 ) , F_34 ( V_41 ) ,
F_35 ( V_41 ) , F_36 ( V_11 ) , V_13 -> V_44 , V_13 -> V_10 ,
F_33 ( V_42 ) , F_34 ( V_42 ) ,
F_35 ( V_42 ) ) ;
if ( V_42 == V_2 &&
F_33 ( V_41 ) == V_13 -> V_14 -> V_15 ) {
V_13 -> V_45 |= V_46 ;
V_13 -> V_47 = V_41 & 0xff ;
F_32 ( L_4 ,
F_34 ( V_41 ) , F_35 ( V_41 ) ,
F_36 ( V_11 ) ) ;
}
return V_41 ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
T_1 V_30 ;
int V_29 ;
if ( V_11 -> V_17 . V_18 )
return 0 ;
V_3 = F_12 ( F_13 ( V_11 ) ) ;
if ( ! V_3 )
return - V_48 ;
V_30 = F_30 ( V_11 ) ;
if ( V_30 != V_3 -> V_2 ) {
struct V_1 * V_49 ;
V_49 = F_12 ( V_30 ) ;
if ( V_49 == NULL ) {
F_38 ( L_5 ,
F_36 ( V_11 ) ) ;
F_7 ( V_3 ) ;
return - V_50 ;
}
V_3 -> V_49 = V_49 ;
}
V_29 = F_24 ( V_11 ) ;
if ( V_29 ) {
F_7 ( V_3 ) ;
return V_29 ;
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
V_29 = F_37 ( & V_13 -> V_11 ) ;
if ( V_29 == - V_50 )
F_40 ( & V_13 -> V_11 ) ;
else if ( V_29 )
goto V_57;
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
F_38 ( L_8 , V_23 ,
V_43 [ V_2 ] . V_40 [ V_23 ] ) ;
}
static void F_54 ( unsigned long V_82 )
{
struct V_83 * V_84 = F_55 ( V_82 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 4 ; ++ V_23 )
F_38 ( L_9 , V_23 , V_84 -> V_40 [ V_23 ] ) ;
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
F_38 ( L_10 ) ;
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
F_33 ( V_2 ) , F_34 ( V_2 ) , F_35 ( V_2 ) ,
V_89 , V_4 ) ;
F_53 ( V_2 ) ;
break;
case V_102 :
F_58 ( L_14
L_15 ,
F_33 ( V_2 ) , F_34 ( V_2 ) , F_35 ( V_2 ) ,
V_86 , V_89 , V_4 ) ;
break;
case V_103 :
F_58 ( L_16
L_13 ,
F_33 ( V_2 ) , F_34 ( V_2 ) , F_35 ( V_2 ) ,
V_89 , V_4 ) ;
break;
case V_104 :
F_58 ( L_17
L_15 ,
F_33 ( V_2 ) , F_34 ( V_2 ) , F_35 ( V_2 ) ,
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
F_33 ( V_2 ) , F_34 ( V_2 ) , F_35 ( V_2 ) ,
V_89 ) ;
break;
case V_108 :
F_58 ( L_23
L_13 ,
F_33 ( V_2 ) , F_34 ( V_2 ) , F_35 ( V_2 ) ,
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
int V_149 ;
V_148 = F_86 ( V_89 , V_146 , V_150 ) ;
V_149 = 0 ;
if ( V_148 > 1 ) {
V_89 = V_151 ;
V_149 = 1 ;
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
int V_149 ;
V_148 = F_86 ( V_89 , V_146 , V_150 ) ;
V_149 = 0 ;
if ( V_148 > 1 ) {
V_89 = V_151 ;
V_149 = 1 ;
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
F_155 ( & V_180 -> V_255 , & V_256 ) ;
F_6 ( & V_254 , V_4 ) ;
}
static void F_156 ( struct V_179 * V_180 )
{
unsigned long V_4 ;
F_4 ( & V_254 , V_4 ) ;
F_8 ( & V_180 -> V_255 ) ;
F_6 ( & V_254 , V_4 ) ;
}
static T_1 F_157 ( void )
{
unsigned long V_4 ;
int V_181 ;
F_158 ( & V_257 , V_4 ) ;
V_181 = F_159 ( V_258 , V_259 ) ;
F_117 ( V_181 == 0 ) ;
if ( V_181 > 0 && V_181 < V_259 )
F_137 ( V_181 , V_258 ) ;
else
V_181 = 0 ;
F_160 ( & V_257 , V_4 ) ;
return V_181 ;
}
static void F_161 ( int V_181 )
{
unsigned long V_4 ;
F_158 ( & V_257 , V_4 ) ;
if ( V_181 > 0 && V_181 < V_259 )
F_162 ( V_181 , V_258 ) ;
F_160 ( & V_257 , V_4 ) ;
}
static void F_163 ( struct V_179 * V_180 )
{
unsigned long V_260 = ( unsigned long ) V_180 -> V_189 ;
switch ( V_180 -> V_187 ) {
case V_261 :
break;
case V_262 :
F_144 ( V_260 ) ;
break;
case V_263 :
F_164 ( V_260 ) ;
break;
case V_264 :
F_165 ( V_260 ) ;
break;
case V_265 :
F_166 ( V_260 ) ;
break;
case V_266 :
F_167 ( V_260 ) ;
break;
case V_188 :
F_168 ( V_260 ) ;
break;
default:
F_169 () ;
}
}
static void F_170 ( T_4 * V_267 )
{
T_4 * V_268 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_267 [ V_23 ] & V_269 ) )
continue;
V_268 = F_171 ( V_267 [ V_23 ] & V_152 ) ;
F_144 ( ( unsigned long ) V_268 ) ;
}
}
static void F_172 ( T_4 * V_267 )
{
T_4 * V_268 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 512 ; ++ V_23 ) {
if ( ! ( V_267 [ V_23 ] & V_269 ) )
continue;
V_268 = F_171 ( V_267 [ V_23 ] & V_152 ) ;
F_170 ( V_268 ) ;
}
}
static void F_173 ( struct V_179 * V_180 )
{
if ( V_180 -> V_270 == 2 )
F_172 ( V_180 -> V_271 ) ;
else if ( V_180 -> V_270 == 1 )
F_170 ( V_180 -> V_271 ) ;
else if ( V_180 -> V_270 != 0 )
F_169 () ;
F_144 ( ( unsigned long ) V_180 -> V_271 ) ;
}
static void F_174 ( struct V_27 * V_198 )
{
int V_23 ;
if ( ! V_198 )
return;
F_156 ( & V_198 -> V_180 ) ;
F_163 ( & V_198 -> V_180 ) ;
for ( V_23 = 0 ; V_23 < V_233 ; ++ V_23 ) {
if ( ! V_198 -> V_223 [ V_23 ] )
continue;
F_144 ( ( unsigned long ) V_198 -> V_223 [ V_23 ] -> V_224 ) ;
F_9 ( V_198 -> V_223 [ V_23 ] ) ;
}
F_9 ( V_198 ) ;
}
static struct V_27 * F_175 ( void )
{
struct V_27 * V_216 ;
V_216 = F_2 ( sizeof( struct V_27 ) , V_5 ) ;
if ( ! V_216 )
return NULL ;
F_176 ( & V_216 -> V_180 . V_170 ) ;
V_216 -> V_180 . V_181 = F_157 () ;
if ( V_216 -> V_180 . V_181 == 0 )
goto V_272;
F_177 ( & V_216 -> V_180 . V_273 ) ;
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
F_174 ( V_216 ) ;
return NULL ;
}
static bool V_27 ( struct V_179 * V_180 )
{
return V_180 -> V_4 & V_274 ;
}
static void F_178 ( T_1 V_2 , struct V_179 * V_180 , bool V_177 )
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
V_283 = F_179 ( ~ 0ULL ) << V_287 ;
V_4 &= ~ V_283 ;
V_283 = F_180 ( ~ 0ULL ) << V_288 ;
V_4 &= ~ V_283 ;
V_283 = F_181 ( V_282 ) << V_289 ;
V_276 |= V_283 ;
V_283 = F_179 ( V_282 ) << V_287 ;
V_4 |= V_283 ;
V_283 = F_180 ( V_282 ) << V_288 ;
V_4 |= V_283 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_180 -> V_181 ;
V_43 [ V_2 ] . V_40 [ 1 ] = V_4 ;
V_43 [ V_2 ] . V_40 [ 0 ] = V_276 ;
}
static void F_182 ( T_1 V_2 )
{
V_43 [ V_2 ] . V_40 [ 0 ] = V_204 | V_279 ;
V_43 [ V_2 ] . V_40 [ 1 ] = 0 ;
F_183 ( V_2 ) ;
}
static void F_184 ( struct V_1 * V_3 ,
struct V_179 * V_180 )
{
struct V_51 * V_18 ;
bool V_177 ;
V_18 = V_37 [ V_3 -> V_2 ] ;
V_177 = V_3 -> V_177 . V_178 ;
V_3 -> V_180 = V_180 ;
F_155 ( & V_3 -> V_255 , & V_180 -> V_273 ) ;
F_178 ( V_3 -> V_2 , V_180 , V_177 ) ;
V_180 -> V_183 [ V_18 -> V_228 ] += 1 ;
V_180 -> V_290 += 1 ;
F_105 ( V_3 ) ;
}
static void F_185 ( struct V_1 * V_3 )
{
struct V_51 * V_18 ;
V_18 = V_37 [ V_3 -> V_2 ] ;
V_3 -> V_180 -> V_183 [ V_18 -> V_228 ] -= 1 ;
V_3 -> V_180 -> V_290 -= 1 ;
V_3 -> V_180 = NULL ;
F_8 ( & V_3 -> V_255 ) ;
F_182 ( V_3 -> V_2 ) ;
F_105 ( V_3 ) ;
}
static int F_186 ( struct V_1 * V_3 ,
struct V_179 * V_180 )
{
int V_29 ;
F_187 ( & V_180 -> V_170 ) ;
if ( V_3 -> V_49 != NULL ) {
struct V_1 * V_49 = V_3 -> V_49 ;
V_29 = - V_203 ;
if ( V_49 -> V_180 != NULL &&
V_49 -> V_180 != V_180 )
goto V_9;
if ( V_3 -> V_180 != NULL &&
V_3 -> V_180 != V_180 )
goto V_9;
if ( V_49 -> V_180 == NULL )
F_184 ( V_49 , V_180 ) ;
F_188 ( & V_49 -> V_6 ) ;
}
if ( V_3 -> V_180 == NULL )
F_184 ( V_3 , V_180 ) ;
F_188 ( & V_3 -> V_6 ) ;
V_29 = 0 ;
V_9:
F_189 ( & V_180 -> V_170 ) ;
return V_29 ;
}
static void F_190 ( struct V_12 * V_13 )
{
F_191 ( V_13 ) ;
F_192 ( V_13 ) ;
F_193 ( V_13 ) ;
}
static int F_194 ( struct V_12 * V_13 )
{
T_1 V_291 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return - V_202 ;
F_195 ( V_13 , V_24 + V_292 , & V_291 ) ;
V_291 |= V_293 ;
F_196 ( V_13 , V_24 + V_292 , V_291 ) ;
return 0 ;
}
static int F_197 ( struct V_12 * V_13 )
{
bool V_294 ;
int V_295 , V_29 ;
V_295 = 32 ;
if ( F_19 ( V_13 , V_296 ) )
V_295 = 1 ;
V_294 = F_19 ( V_13 , V_297 ) ;
V_29 = F_198 ( V_13 , 0 ) ;
if ( V_29 )
goto V_298;
V_29 = F_199 ( V_13 ) ;
if ( V_29 )
goto V_298;
V_29 = F_200 ( V_13 , V_295 ) ;
if ( V_29 )
goto V_298;
if ( V_294 ) {
V_29 = F_194 ( V_13 ) ;
if ( V_29 )
goto V_298;
}
V_29 = F_201 ( V_13 , V_222 ) ;
if ( V_29 )
goto V_298;
return 0 ;
V_298:
F_192 ( V_13 ) ;
F_193 ( V_13 ) ;
return V_29 ;
}
static bool F_202 ( struct V_12 * V_13 )
{
T_1 V_131 ;
int V_24 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( ! V_24 )
return false ;
F_195 ( V_13 , V_24 + V_299 , & V_131 ) ;
return ( V_131 & V_300 ) ? true : false ;
}
static int F_203 ( struct V_10 * V_11 ,
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
if ( F_197 ( V_13 ) != 0 )
return - V_202 ;
V_3 -> V_177 . V_178 = true ;
V_3 -> V_177 . V_156 = F_204 ( V_13 ) ;
V_3 -> V_302 = F_202 ( V_13 ) ;
} else if ( V_303 &&
F_201 ( V_13 , V_222 ) == 0 ) {
V_3 -> V_177 . V_178 = true ;
V_3 -> V_177 . V_156 = F_204 ( V_13 ) ;
}
F_158 ( & V_257 , V_4 ) ;
V_29 = F_186 ( V_3 , V_180 ) ;
F_160 ( & V_257 , V_4 ) ;
F_109 ( V_180 ) ;
return V_29 ;
}
static void F_205 ( struct V_1 * V_3 )
{
struct V_179 * V_180 ;
unsigned long V_4 ;
F_117 ( ! V_3 -> V_180 ) ;
V_180 = V_3 -> V_180 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
if ( V_3 -> V_49 != NULL ) {
struct V_1 * V_49 = V_3 -> V_49 ;
if ( F_206 ( & V_49 -> V_6 ) )
F_185 ( V_49 ) ;
}
if ( F_206 ( & V_3 -> V_6 ) )
F_185 ( V_3 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
if ( V_3 -> V_301 &&
( V_3 -> V_180 == NULL && V_180 != V_304 ) )
F_186 ( V_3 , V_304 ) ;
}
static void F_207 ( struct V_10 * V_11 )
{
struct V_179 * V_180 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
V_180 = V_3 -> V_180 ;
F_158 ( & V_257 , V_4 ) ;
F_205 ( V_3 ) ;
F_160 ( & V_257 , V_4 ) ;
if ( V_180 -> V_4 & V_281 )
F_190 ( F_14 ( V_11 ) ) ;
else if ( V_3 -> V_177 . V_178 )
F_191 ( F_14 ( V_11 ) ) ;
V_3 -> V_177 . V_178 = false ;
}
static struct V_179 * F_208 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
struct V_179 * V_198 = NULL ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
if ( V_3 -> V_180 )
return V_3 -> V_180 ;
if ( V_3 -> V_49 != NULL ) {
struct V_1 * V_49 = V_3 -> V_49 ;
F_209 ( & V_257 , V_4 ) ;
if ( V_49 -> V_180 != NULL ) {
F_186 ( V_3 , V_49 -> V_180 ) ;
V_198 = V_49 -> V_180 ;
}
F_210 ( & V_257 , V_4 ) ;
}
return V_198 ;
}
static int F_211 ( struct V_305 * V_306 ,
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
V_180 = F_208 ( V_11 ) ;
if ( ! V_180 )
goto V_310;
if ( V_3 -> V_301 )
break;
F_207 ( V_11 ) ;
break;
case V_311 :
F_37 ( V_11 ) ;
V_3 = F_16 ( V_11 ) ;
if ( V_312 || V_3 -> V_52 ) {
V_3 -> V_301 = true ;
F_203 ( V_11 , V_304 ) ;
break;
}
V_180 = F_208 ( V_11 ) ;
V_308 = F_20 ( V_2 ) ;
if ( ! V_308 ) {
V_308 = F_175 () ;
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
void F_212 ( void )
{
F_213 ( & V_316 , & V_317 ) ;
}
static struct V_179 * F_214 ( struct V_10 * V_11 )
{
struct V_179 * V_180 ;
struct V_27 * V_216 ;
T_1 V_2 = F_13 ( V_11 ) ;
if ( ! F_22 ( V_11 ) )
return F_215 ( - V_202 ) ;
V_180 = F_208 ( V_11 ) ;
if ( V_180 != NULL && ! V_27 ( V_180 ) )
return F_215 ( - V_203 ) ;
if ( V_180 != NULL )
return V_180 ;
V_216 = F_20 ( V_2 ) ;
if ( ! V_216 )
V_216 = V_37 [ V_2 ] -> V_225 ;
F_203 ( V_11 , & V_216 -> V_180 ) ;
F_216 ( L_29 ,
V_216 -> V_180 . V_181 , F_36 ( V_11 ) ) ;
return & V_216 -> V_180 ;
}
static void F_217 ( struct V_179 * V_180 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_178 ( V_3 -> V_2 , V_180 , V_3 -> V_177 . V_178 ) ;
}
static void F_133 ( struct V_179 * V_180 )
{
if ( ! V_180 -> V_190 )
return;
F_217 ( V_180 ) ;
F_111 ( V_180 ) ;
F_109 ( V_180 ) ;
V_180 -> V_190 = false ;
}
static T_4 * F_218 ( struct V_27 * V_198 ,
unsigned long V_89 )
{
struct V_234 * V_223 ;
T_4 * V_186 , * V_192 ;
V_223 = V_198 -> V_223 [ F_219 ( V_89 ) ] ;
if ( ! V_223 )
return NULL ;
V_186 = V_223 -> V_237 [ F_220 ( V_89 ) ] ;
if ( ! V_186 ) {
V_186 = F_116 ( & V_198 -> V_180 , V_89 , V_150 , & V_192 ,
V_318 ) ;
V_223 -> V_237 [ F_220 ( V_89 ) ] = V_192 ;
} else
V_186 += F_120 ( 0 , V_89 ) ;
F_133 ( & V_198 -> V_180 ) ;
return V_186 ;
}
static T_9 F_221 ( struct V_27 * V_198 ,
unsigned long V_89 ,
T_10 V_319 ,
int V_320 )
{
T_4 * V_186 , V_197 ;
F_79 ( V_89 > V_198 -> V_221 ) ;
V_319 &= V_152 ;
V_186 = F_218 ( V_198 , V_89 ) ;
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
static void F_222 ( struct V_27 * V_198 ,
unsigned long V_89 )
{
struct V_234 * V_223 ;
T_4 * V_186 ;
if ( V_89 >= V_198 -> V_221 )
return;
V_223 = V_198 -> V_223 [ F_219 ( V_89 ) ] ;
if ( ! V_223 )
return;
V_186 = V_223 -> V_237 [ F_220 ( V_89 ) ] ;
if ( ! V_186 )
return;
V_186 += F_120 ( 0 , V_89 ) ;
F_79 ( ! * V_186 ) ;
* V_186 = 0ULL ;
}
static T_9 F_223 ( struct V_10 * V_11 ,
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
V_244 = ( 1UL << F_224 ( V_146 ) ) - 1 ;
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
V_29 = F_221 ( V_216 , V_245 , V_319 , V_324 ) ;
if ( V_29 == V_252 )
goto V_326;
V_319 += V_150 ;
V_245 += V_150 ;
}
V_89 += V_235 ;
F_225 ( V_76 , V_146 ) ;
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
F_222 ( V_216 , V_245 ) ;
}
F_152 ( V_216 , V_89 , V_148 ) ;
return V_252 ;
}
static void F_226 ( struct V_27 * V_216 ,
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
F_222 ( V_216 , V_245 ) ;
V_245 += V_150 ;
}
F_227 ( V_76 , V_146 ) ;
F_152 ( V_216 , V_328 , V_148 ) ;
if ( V_65 || V_216 -> V_251 ) {
F_107 ( & V_216 -> V_180 , V_329 , V_146 ) ;
V_216 -> V_251 = false ;
}
}
static T_9 F_228 ( struct V_10 * V_11 , struct V_195 * V_195 ,
unsigned long V_235 , T_7 V_146 ,
enum V_330 V_324 ,
struct V_331 * V_332 )
{
unsigned long V_4 ;
struct V_179 * V_180 ;
T_9 V_218 ;
T_4 V_35 ;
T_10 V_319 = F_229 ( V_195 ) + V_235 ;
F_63 ( V_67 ) ;
V_180 = F_214 ( V_11 ) ;
if ( F_27 ( V_180 ) == - V_202 )
return ( T_9 ) V_319 ;
else if ( F_26 ( V_180 ) )
return V_252 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_218 = F_223 ( V_11 , V_180 -> V_275 , V_319 , V_146 , V_324 , false ,
V_35 ) ;
if ( V_218 == V_252 )
goto V_310;
F_110 ( V_180 ) ;
V_310:
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_218 ;
}
static void F_230 ( struct V_10 * V_11 , T_9 V_328 , T_7 V_146 ,
enum V_330 V_324 , struct V_331 * V_332 )
{
unsigned long V_4 ;
struct V_179 * V_180 ;
F_63 ( V_68 ) ;
V_180 = F_214 ( V_11 ) ;
if ( F_26 ( V_180 ) )
return;
F_4 ( & V_180 -> V_170 , V_4 ) ;
F_226 ( V_180 -> V_275 , V_328 , V_146 , V_324 ) ;
F_110 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
}
static int F_231 ( struct V_10 * V_11 , struct V_333 * V_334 ,
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
V_180 = F_214 ( V_11 ) ;
if ( F_26 ( V_180 ) )
return 0 ;
V_35 = * V_11 -> V_35 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
F_232 (sglist, s, nelems, i) {
V_319 = F_233 ( V_149 ) ;
V_149 -> V_337 = F_223 ( V_11 , V_180 -> V_275 ,
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
F_232 (sglist, s, mapped_elems, i) {
if ( V_149 -> V_337 )
F_226 ( V_180 -> V_275 , V_149 -> V_337 ,
V_149 -> V_339 , V_324 ) ;
V_149 -> V_337 = V_149 -> V_339 = 0 ;
}
V_336 = 0 ;
goto V_310;
}
static void F_234 ( struct V_10 * V_11 , struct V_333 * V_334 ,
int V_335 , enum V_330 V_324 ,
struct V_331 * V_332 )
{
unsigned long V_4 ;
struct V_179 * V_180 ;
struct V_333 * V_149 ;
int V_23 ;
F_63 ( V_70 ) ;
V_180 = F_214 ( V_11 ) ;
if ( F_26 ( V_180 ) )
return;
F_4 ( & V_180 -> V_170 , V_4 ) ;
F_232 (sglist, s, nelems, i) {
F_226 ( V_180 -> V_275 , V_149 -> V_337 ,
V_149 -> V_339 , V_324 ) ;
V_149 -> V_337 = V_149 -> V_339 = 0 ;
}
F_110 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
}
static void * F_235 ( struct V_10 * V_11 , T_7 V_146 ,
T_9 * V_328 , T_8 V_341 ,
struct V_331 * V_332 )
{
unsigned long V_4 ;
void * V_342 ;
struct V_179 * V_180 ;
T_10 V_319 ;
T_4 V_35 = V_11 -> V_343 ;
F_63 ( V_71 ) ;
V_180 = F_214 ( V_11 ) ;
if ( F_27 ( V_180 ) == - V_202 ) {
V_342 = ( void * ) F_236 ( V_341 , F_224 ( V_146 ) ) ;
* V_328 = F_81 ( V_342 ) ;
return V_342 ;
} else if ( F_26 ( V_180 ) )
return NULL ;
V_35 = V_11 -> V_343 ;
V_341 &= ~ ( V_344 | V_345 | V_346 ) ;
V_341 |= V_347 ;
V_342 = ( void * ) F_236 ( V_341 , F_224 ( V_146 ) ) ;
if ( ! V_342 )
return NULL ;
V_319 = F_115 ( V_342 ) ;
if ( ! V_35 )
V_35 = * V_11 -> V_35 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
* V_328 = F_223 ( V_11 , V_180 -> V_275 , V_319 ,
V_146 , V_323 , true , V_35 ) ;
if ( * V_328 == V_252 ) {
F_6 ( & V_180 -> V_170 , V_4 ) ;
goto V_57;
}
F_110 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_342 ;
V_57:
F_237 ( ( unsigned long ) V_342 , F_224 ( V_146 ) ) ;
return NULL ;
}
static void F_238 ( struct V_10 * V_11 , T_7 V_146 ,
void * V_342 , T_9 V_328 ,
struct V_331 * V_332 )
{
unsigned long V_4 ;
struct V_179 * V_180 ;
F_63 ( V_72 ) ;
V_180 = F_214 ( V_11 ) ;
if ( F_26 ( V_180 ) )
goto V_348;
F_4 ( & V_180 -> V_170 , V_4 ) ;
F_226 ( V_180 -> V_275 , V_328 , V_146 , V_323 ) ;
F_110 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
V_348:
F_237 ( ( unsigned long ) V_342 , F_224 ( V_146 ) ) ;
}
static int F_239 ( struct V_10 * V_11 , T_4 V_349 )
{
return F_22 ( V_11 ) ;
}
static void T_3 F_240 ( void )
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
F_241 () ;
V_3 -> V_301 = true ;
F_203 ( & V_11 -> V_11 , V_304 ) ;
F_32 ( L_30 ,
F_36 ( & V_11 -> V_11 ) ) ;
}
if ( F_208 ( & V_11 -> V_11 ) )
continue;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_216 = F_175 () ;
if ( ! V_216 )
continue;
F_139 ( V_216 , V_2 ) ;
V_216 -> V_34 = V_2 ;
F_203 ( & V_11 -> V_11 , & V_216 -> V_180 ) ;
F_5 ( & V_216 -> V_255 , & V_32 ) ;
}
}
static unsigned F_242 ( void )
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
void T_3 F_243 ( void )
{
F_244 ( & V_316 , & V_353 ) ;
}
int T_3 F_245 ( void )
{
struct V_51 * V_18 ;
int V_29 , V_351 ;
F_143 (iommu) {
V_18 -> V_225 = F_175 () ;
if ( V_18 -> V_225 == NULL )
return - V_48 ;
V_18 -> V_225 -> V_180 . V_4 |= V_354 ;
V_29 = F_138 ( V_18 ) ;
if ( V_29 )
goto V_355;
}
F_240 () ;
V_356 = 1 ;
V_357 = 0 ;
V_351 = F_242 () ;
if ( V_351 && V_358 > V_359 ) {
V_357 = 1 ;
}
F_50 () ;
if ( V_65 )
F_32 ( L_31 ) ;
else
F_32 ( L_32 ) ;
return 0 ;
V_355:
F_143 (iommu) {
F_174 ( V_18 -> V_225 ) ;
}
return V_29 ;
}
static void F_246 ( struct V_179 * V_180 )
{
struct V_1 * V_28 ;
unsigned long V_4 ;
F_158 ( & V_257 , V_4 ) ;
while ( ! F_21 ( & V_180 -> V_273 ) ) {
V_28 = F_247 ( & V_180 -> V_273 ,
struct V_1 , V_255 ) ;
F_205 ( V_28 ) ;
F_3 ( & V_28 -> V_6 , 0 ) ;
}
F_160 ( & V_257 , V_4 ) ;
}
static void F_248 ( struct V_179 * V_180 )
{
if ( ! V_180 )
return;
F_156 ( V_180 ) ;
if ( V_180 -> V_181 )
F_161 ( V_180 -> V_181 ) ;
F_9 ( V_180 ) ;
}
static struct V_179 * F_249 ( void )
{
struct V_179 * V_180 ;
V_180 = F_2 ( sizeof( * V_180 ) , V_5 ) ;
if ( ! V_180 )
return NULL ;
F_176 ( & V_180 -> V_170 ) ;
F_250 ( & V_180 -> V_360 ) ;
V_180 -> V_181 = F_157 () ;
if ( ! V_180 -> V_181 )
goto V_298;
F_177 ( & V_180 -> V_273 ) ;
F_154 ( V_180 ) ;
return V_180 ;
V_298:
F_9 ( V_180 ) ;
return NULL ;
}
static int T_3 F_241 ( void )
{
if ( V_304 != NULL )
return 0 ;
V_304 = F_249 () ;
if ( ! V_304 )
return - V_48 ;
V_304 -> V_187 = V_261 ;
return 0 ;
}
static int F_251 ( struct V_361 * V_198 )
{
struct V_179 * V_180 ;
V_180 = F_249 () ;
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
F_248 ( V_180 ) ;
return - V_48 ;
}
static void F_252 ( struct V_361 * V_198 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
if ( ! V_180 )
return;
if ( V_180 -> V_290 > 0 )
F_246 ( V_180 ) ;
F_117 ( V_180 -> V_290 != 0 ) ;
if ( V_180 -> V_187 != V_261 )
F_163 ( V_180 ) ;
if ( V_180 -> V_4 & V_281 )
F_173 ( V_180 ) ;
F_248 ( V_180 ) ;
V_198 -> V_275 = NULL ;
}
static void F_253 ( struct V_361 * V_198 ,
struct V_10 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_17 . V_18 ;
struct V_51 * V_18 ;
T_1 V_2 ;
if ( ! F_22 ( V_11 ) )
return;
V_2 = F_13 ( V_11 ) ;
if ( V_3 -> V_180 != NULL )
F_207 ( V_11 ) ;
V_18 = V_37 [ V_2 ] ;
if ( ! V_18 )
return;
F_95 ( V_18 ) ;
}
static int F_254 ( struct V_361 * V_198 ,
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
F_207 ( V_11 ) ;
V_29 = F_203 ( V_11 , V_180 ) ;
F_95 ( V_18 ) ;
return V_29 ;
}
static int F_255 ( struct V_361 * V_198 , unsigned long V_366 ,
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
F_256 ( & V_180 -> V_360 ) ;
V_29 = F_129 ( V_180 , V_366 , V_319 , V_200 , V_191 ) ;
F_257 ( & V_180 -> V_360 ) ;
return V_29 ;
}
static T_7 F_258 ( struct V_361 * V_198 , unsigned long V_366 ,
T_7 V_191 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
T_7 V_210 ;
if ( V_180 -> V_187 == V_261 )
return - V_202 ;
F_256 ( & V_180 -> V_360 ) ;
V_210 = F_134 ( V_180 , V_366 , V_191 ) ;
F_257 ( & V_180 -> V_360 ) ;
F_109 ( V_180 ) ;
return V_210 ;
}
static T_10 F_259 ( struct V_361 * V_198 ,
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
static int F_260 ( struct V_361 * V_180 ,
unsigned long V_372 )
{
switch ( V_372 ) {
case V_373 :
return 1 ;
case V_374 :
return V_375 ;
}
return 0 ;
}
int T_3 F_261 ( void )
{
struct V_1 * V_3 ;
struct V_12 * V_11 = NULL ;
int V_29 ;
V_29 = F_241 () ;
if ( V_29 )
return V_29 ;
F_45 (dev) {
if ( ! F_22 ( & V_11 -> V_11 ) )
continue;
V_3 = F_16 ( & V_11 -> V_11 ) ;
V_3 -> V_301 = true ;
F_203 ( & V_11 -> V_11 , V_304 ) ;
}
F_50 () ;
F_32 ( L_33 ) ;
return 0 ;
}
int F_262 ( struct V_305 * V_306 )
{
return F_263 ( & V_124 , V_306 ) ;
}
int F_264 ( struct V_305 * V_306 )
{
return F_265 ( & V_124 , V_306 ) ;
}
void F_266 ( struct V_361 * V_198 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_180 -> V_187 = V_261 ;
V_180 -> V_190 = true ;
F_133 ( V_180 ) ;
F_163 ( V_180 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
}
int F_267 ( struct V_361 * V_198 , int V_376 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_377 , V_29 ;
if ( V_376 <= 0 || V_376 > ( V_378 + 1 ) )
return - V_202 ;
for ( V_377 = 0 ; ( V_376 - 1 ) & ~ 0x1ff ; V_376 >>= 9 )
V_377 += 1 ;
if ( V_377 > V_379 )
return - V_202 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = - V_203 ;
if ( V_180 -> V_290 > 0 || V_180 -> V_4 & V_281 )
goto V_310;
V_29 = - V_48 ;
V_180 -> V_271 = ( void * ) F_113 ( V_318 ) ;
if ( V_180 -> V_271 == NULL )
goto V_310;
V_180 -> V_270 = V_377 ;
V_180 -> V_4 |= V_281 ;
V_180 -> V_190 = true ;
F_133 ( V_180 ) ;
V_29 = 0 ;
V_310:
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
static int F_268 ( struct V_179 * V_180 , int V_121 ,
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
static int F_269 ( struct V_179 * V_180 , int V_121 ,
T_4 V_89 )
{
F_63 ( V_79 ) ;
return F_268 ( V_180 , V_121 , V_89 , false ) ;
}
int F_270 ( struct V_361 * V_198 , int V_121 ,
T_4 V_89 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = F_269 ( V_180 , V_121 , V_89 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
static int F_271 ( struct V_179 * V_180 , int V_121 )
{
F_63 ( V_80 ) ;
return F_268 ( V_180 , V_121 , V_151 ,
true ) ;
}
int F_272 ( struct V_361 * V_198 , int V_121 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = F_271 ( V_180 , V_121 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
static T_4 * F_273 ( T_4 * V_260 , int V_193 , int V_121 , bool V_380 )
{
int V_228 ;
T_4 * V_186 ;
while ( true ) {
V_228 = ( V_121 >> ( 9 * V_193 ) ) & 0x1ff ;
V_186 = & V_260 [ V_228 ] ;
if ( V_193 == 0 )
break;
if ( ! ( * V_186 & V_269 ) ) {
if ( ! V_380 )
return NULL ;
V_260 = ( void * ) F_113 ( V_318 ) ;
if ( V_260 == NULL )
return NULL ;
* V_186 = F_81 ( V_260 ) | V_269 ;
}
V_260 = F_171 ( * V_186 & V_152 ) ;
V_193 -= 1 ;
}
return V_186 ;
}
static int F_274 ( struct V_179 * V_180 , int V_121 ,
unsigned long V_381 )
{
T_4 * V_186 ;
if ( V_180 -> V_187 != V_261 )
return - V_202 ;
V_186 = F_273 ( V_180 -> V_271 , V_180 -> V_270 , V_121 , true ) ;
if ( V_186 == NULL )
return - V_48 ;
* V_186 = ( V_381 & V_152 ) | V_269 ;
return F_271 ( V_180 , V_121 ) ;
}
static int F_275 ( struct V_179 * V_180 , int V_121 )
{
T_4 * V_186 ;
if ( V_180 -> V_187 != V_261 )
return - V_202 ;
V_186 = F_273 ( V_180 -> V_271 , V_180 -> V_270 , V_121 , false ) ;
if ( V_186 == NULL )
return 0 ;
* V_186 = 0 ;
return F_271 ( V_180 , V_121 ) ;
}
int F_276 ( struct V_361 * V_198 , int V_121 ,
unsigned long V_381 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = F_274 ( V_180 , V_121 , V_381 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
int F_277 ( struct V_361 * V_198 , int V_121 )
{
struct V_179 * V_180 = V_198 -> V_275 ;
unsigned long V_4 ;
int V_29 ;
F_4 ( & V_180 -> V_170 , V_4 ) ;
V_29 = F_275 ( V_180 , V_121 ) ;
F_6 ( & V_180 -> V_170 , V_4 ) ;
return V_29 ;
}
int F_278 ( struct V_12 * V_13 , int V_121 ,
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
struct V_361 * F_279 ( struct V_12 * V_13 )
{
struct V_179 * V_180 ;
V_180 = F_214 ( & V_13 -> V_11 ) ;
if ( F_26 ( V_180 ) )
return NULL ;
if ( ! ( V_180 -> V_4 & V_281 ) )
return NULL ;
return V_180 -> V_361 ;
}
void F_280 ( struct V_12 * V_13 , T_2 V_25 )
{
struct V_1 * V_3 ;
if ( ! F_281 () )
return;
V_3 = F_16 ( & V_13 -> V_11 ) ;
V_3 -> V_26 |= ( 1 << V_25 ) ;
}
int F_282 ( struct V_12 * V_13 ,
struct F_282 * V_382 )
{
int V_383 ;
int V_24 ;
if ( V_13 == NULL || V_382 == NULL )
return - V_202 ;
if ( ! F_281 () )
return - V_202 ;
memset ( V_382 , 0 , sizeof( * V_382 ) ) ;
V_24 = F_18 ( V_13 , V_20 ) ;
if ( V_24 )
V_382 -> V_4 |= V_384 ;
V_24 = F_18 ( V_13 , V_21 ) ;
if ( V_24 )
V_382 -> V_4 |= V_385 ;
V_24 = F_18 ( V_13 , V_22 ) ;
if ( V_24 ) {
int V_386 ;
V_383 = 1 << ( 9 * ( V_379 + 1 ) ) ;
V_383 = F_283 ( V_383 , ( 1 << 20 ) ) ;
V_382 -> V_4 |= V_387 ;
V_382 -> V_383 = F_283 ( F_284 ( V_13 ) , V_383 ) ;
V_386 = F_285 ( V_13 ) ;
if ( V_386 & V_388 )
V_382 -> V_4 |= V_389 ;
if ( V_386 & V_390 )
V_382 -> V_4 |= V_391 ;
}
return 0 ;
}
static void F_286 ( T_1 V_2 , struct V_392 * V_393 )
{
T_4 V_394 ;
V_394 = V_43 [ V_2 ] . V_40 [ 2 ] ;
V_394 &= ~ V_395 ;
V_394 |= F_115 ( V_393 -> V_393 ) ;
V_394 |= V_396 ;
V_394 |= V_397 ;
V_394 |= V_398 ;
V_43 [ V_2 ] . V_40 [ 2 ] = V_394 ;
}
static struct V_392 * F_287 ( T_1 V_2 , bool V_399 )
{
struct V_392 * V_393 = NULL ;
struct V_51 * V_18 ;
unsigned long V_4 ;
T_1 V_30 ;
F_158 ( & V_257 , V_4 ) ;
V_18 = V_37 [ V_2 ] ;
if ( ! V_18 )
goto V_9;
V_393 = V_400 [ V_2 ] ;
if ( V_393 )
goto V_310;
V_30 = V_31 [ V_2 ] ;
V_393 = V_400 [ V_30 ] ;
if ( V_393 ) {
V_400 [ V_2 ] = V_393 ;
F_286 ( V_2 , V_393 ) ;
F_96 ( V_18 , V_2 ) ;
goto V_310;
}
V_393 = F_2 ( sizeof( * V_393 ) , V_318 ) ;
if ( ! V_393 )
goto V_310;
F_176 ( & V_393 -> V_170 ) ;
if ( V_399 )
V_393 -> V_401 = 32 ;
V_393 -> V_393 = F_288 ( V_402 , V_318 ) ;
if ( ! V_393 -> V_393 ) {
F_9 ( V_393 ) ;
V_393 = NULL ;
goto V_310;
}
memset ( V_393 -> V_393 , 0 , V_403 * sizeof( T_2 ) ) ;
if ( V_399 ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < 32 ; ++ V_23 )
V_393 -> V_393 [ V_23 ] = V_404 ;
}
V_400 [ V_2 ] = V_393 ;
F_286 ( V_2 , V_393 ) ;
F_96 ( V_18 , V_2 ) ;
if ( V_2 != V_30 ) {
V_400 [ V_30 ] = V_393 ;
F_286 ( V_30 , V_393 ) ;
F_96 ( V_18 , V_30 ) ;
}
V_310:
F_95 ( V_18 ) ;
V_9:
F_160 ( & V_257 , V_4 ) ;
return V_393 ;
}
static int F_289 ( struct V_405 * V_406 , T_1 V_2 , int V_88 )
{
struct V_392 * V_393 ;
unsigned long V_4 ;
int V_228 , V_407 ;
V_393 = F_287 ( V_2 , false ) ;
if ( ! V_393 )
return - V_408 ;
F_4 ( & V_393 -> V_170 , V_4 ) ;
for ( V_407 = 0 , V_228 = V_393 -> V_401 ;
V_228 < V_403 ;
++ V_228 ) {
if ( V_393 -> V_393 [ V_228 ] == 0 )
V_407 += 1 ;
else
V_407 = 0 ;
if ( V_407 == V_88 ) {
struct V_409 * V_410 ;
for (; V_407 != 0 ; -- V_407 )
V_393 -> V_393 [ V_228 - V_407 + 1 ] = V_404 ;
V_228 -= V_88 - 1 ;
V_406 -> V_411 = 1 ;
V_410 = & V_406 -> V_409 ;
V_410 -> V_2 = V_2 ;
V_410 -> V_228 = V_228 ;
goto V_310;
}
}
V_228 = - V_412 ;
V_310:
F_6 ( & V_393 -> V_170 , V_4 ) ;
return V_228 ;
}
static int F_290 ( T_1 V_2 , int V_228 , union V_413 * V_413 )
{
struct V_392 * V_393 ;
unsigned long V_4 ;
V_393 = F_287 ( V_2 , false ) ;
if ( ! V_393 )
return - V_48 ;
F_4 ( & V_393 -> V_170 , V_4 ) ;
V_413 -> V_414 = V_393 -> V_393 [ V_228 ] ;
F_6 ( & V_393 -> V_170 , V_4 ) ;
return 0 ;
}
static int F_291 ( T_1 V_2 , int V_228 , union V_413 V_413 )
{
struct V_392 * V_393 ;
struct V_51 * V_18 ;
unsigned long V_4 ;
V_18 = V_37 [ V_2 ] ;
if ( V_18 == NULL )
return - V_202 ;
V_393 = F_287 ( V_2 , false ) ;
if ( ! V_393 )
return - V_48 ;
F_4 ( & V_393 -> V_170 , V_4 ) ;
V_393 -> V_393 [ V_228 ] = V_413 . V_414 ;
F_6 ( & V_393 -> V_170 , V_4 ) ;
F_100 ( V_18 , V_2 ) ;
F_95 ( V_18 ) ;
return 0 ;
}
static void F_292 ( T_1 V_2 , int V_228 )
{
struct V_392 * V_393 ;
struct V_51 * V_18 ;
unsigned long V_4 ;
V_18 = V_37 [ V_2 ] ;
if ( V_18 == NULL )
return;
V_393 = F_287 ( V_2 , false ) ;
if ( ! V_393 )
return;
F_4 ( & V_393 -> V_170 , V_4 ) ;
V_393 -> V_393 [ V_228 ] = 0 ;
F_6 ( & V_393 -> V_170 , V_4 ) ;
F_100 ( V_18 , V_2 ) ;
F_95 ( V_18 ) ;
}
static int F_293 ( int V_130 , struct V_415 * V_28 ,
unsigned int V_416 , int V_417 ,
struct V_418 * V_419 )
{
struct V_392 * V_393 ;
struct V_409 * V_410 ;
struct V_405 * V_406 ;
union V_413 V_413 ;
int V_420 ;
int V_228 ;
int V_2 ;
int V_29 ;
V_406 = F_294 ( V_130 ) ;
if ( ! V_406 )
return - V_202 ;
V_410 = & V_406 -> V_409 ;
V_420 = F_295 ( V_419 -> V_399 ) ;
V_2 = F_296 ( V_420 ) ;
if ( V_2 < 0 )
return V_2 ;
V_393 = F_287 ( V_2 , true ) ;
if ( V_393 == NULL )
return - V_48 ;
V_228 = V_419 -> V_421 ;
V_406 -> V_411 = 1 ;
V_410 -> V_2 = V_2 ;
V_410 -> V_228 = V_228 ;
V_413 . V_414 = 0 ;
V_413 . V_422 . V_417 = V_417 ;
V_413 . V_422 . V_423 = V_424 -> V_425 ;
V_413 . V_422 . V_416 = V_416 ;
V_413 . V_422 . V_426 = V_424 -> V_427 ;
V_413 . V_422 . V_428 = 1 ;
V_29 = F_291 ( V_2 , V_228 , V_413 ) ;
if ( V_29 )
return V_29 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_417 = V_228 ;
V_28 -> V_349 = 0 ;
V_28 -> V_429 = V_419 -> V_429 ;
V_28 -> V_430 = V_419 -> V_430 ;
if ( V_419 -> V_429 )
V_28 -> V_349 = 1 ;
return 0 ;
}
static int F_297 ( struct V_431 * V_40 , const struct V_432 * V_349 ,
bool V_433 )
{
struct V_409 * V_410 ;
unsigned int V_434 , V_130 ;
struct V_405 * V_406 ;
union V_413 V_413 ;
int V_435 ;
if ( ! F_298 ( V_436 ) )
return - 1 ;
V_406 = V_40 -> V_437 ;
V_130 = V_40 -> V_130 ;
V_410 = & V_406 -> V_409 ;
if ( ! F_299 ( V_349 , V_438 ) )
return - V_202 ;
if ( F_290 ( V_410 -> V_2 , V_410 -> V_228 , & V_413 ) )
return - V_203 ;
if ( F_300 ( V_130 , V_406 , V_349 ) )
return - V_203 ;
V_435 = V_424 -> V_439 ( V_406 -> V_180 , V_349 , & V_434 ) ;
if ( V_435 ) {
if ( F_300 ( V_130 , V_406 , V_40 -> V_440 ) )
F_38 ( L_34 , V_130 ) ;
return V_435 ;
}
V_413 . V_422 . V_417 = V_406 -> V_417 ;
V_413 . V_422 . V_416 = V_434 ;
F_291 ( V_410 -> V_2 , V_410 -> V_228 , V_413 ) ;
if ( V_406 -> V_441 )
F_301 ( V_406 ) ;
F_302 ( V_40 -> V_440 , V_349 ) ;
return 0 ;
}
static int F_303 ( int V_130 )
{
struct V_409 * V_410 ;
struct V_405 * V_406 ;
V_406 = F_294 ( V_130 ) ;
if ( ! V_406 )
return - V_202 ;
V_410 = & V_406 -> V_409 ;
F_292 ( V_410 -> V_2 , V_410 -> V_228 ) ;
return 0 ;
}
static void F_304 ( struct V_12 * V_13 ,
unsigned int V_130 , unsigned int V_434 ,
struct V_442 * V_443 , T_6 V_444 )
{
struct V_409 * V_410 ;
struct V_405 * V_406 ;
union V_413 V_413 ;
V_406 = F_294 ( V_130 ) ;
if ( ! V_406 )
return;
V_410 = & V_406 -> V_409 ;
V_413 . V_414 = 0 ;
V_413 . V_422 . V_417 = V_406 -> V_417 ;
V_413 . V_422 . V_423 = V_424 -> V_425 ;
V_413 . V_422 . V_416 = V_434 ;
V_413 . V_422 . V_426 = V_424 -> V_427 ;
V_413 . V_422 . V_428 = 1 ;
F_291 ( V_410 -> V_2 , V_410 -> V_228 , V_413 ) ;
V_443 -> V_445 = V_446 ;
V_443 -> V_447 = V_239 ;
V_443 -> V_40 = V_410 -> V_228 ;
}
static int F_305 ( struct V_12 * V_13 , int V_130 , int V_448 )
{
struct V_405 * V_406 ;
int V_228 ;
T_1 V_2 ;
if ( ! V_13 )
return - V_202 ;
V_406 = F_294 ( V_130 ) ;
if ( ! V_406 )
return - V_202 ;
V_2 = F_13 ( & V_13 -> V_11 ) ;
V_228 = F_289 ( V_406 , V_2 , V_448 ) ;
return V_228 < 0 ? V_403 : V_228 ;
}
static int F_306 ( struct V_12 * V_13 , unsigned int V_130 ,
int V_228 , int V_235 )
{
struct V_409 * V_410 ;
struct V_405 * V_406 ;
T_1 V_2 ;
if ( ! V_13 )
return - V_202 ;
V_406 = F_294 ( V_130 ) ;
if ( ! V_406 )
return - V_202 ;
if ( V_228 >= V_403 )
return 0 ;
V_2 = F_13 ( & V_13 -> V_11 ) ;
V_410 = & V_406 -> V_409 ;
V_406 -> V_411 = 1 ;
V_410 -> V_2 = V_2 ;
V_410 -> V_228 = V_228 + V_235 ;
return 0 ;
}
static int F_307 ( unsigned int V_130 , unsigned int V_181 )
{
struct V_409 * V_410 ;
struct V_405 * V_406 ;
int V_228 , V_2 ;
V_406 = F_294 ( V_130 ) ;
if ( ! V_406 )
return - V_202 ;
V_410 = & V_406 -> V_409 ;
V_2 = F_308 ( V_181 ) ;
if ( V_2 < 0 )
return V_2 ;
V_228 = F_289 ( V_406 , V_2 , 1 ) ;
if ( V_228 < 0 )
return V_228 ;
V_406 -> V_411 = 1 ;
V_410 -> V_2 = V_2 ;
V_410 -> V_228 = V_228 ;
return 0 ;
}
