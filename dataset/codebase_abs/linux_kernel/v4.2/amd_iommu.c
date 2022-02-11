static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 * F_3 ( T_1 V_6 )
{
struct V_5 * V_7 ;
unsigned long V_8 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_9 ) ;
if ( ! V_7 )
return NULL ;
F_5 ( & V_7 -> V_10 ) ;
V_7 -> V_6 = V_6 ;
F_6 ( & V_11 , V_8 ) ;
F_7 ( & V_7 -> V_12 , & V_12 ) ;
F_8 ( & V_11 , V_8 ) ;
return V_7 ;
}
static void F_9 ( struct V_5 * V_7 )
{
unsigned long V_8 ;
F_6 ( & V_11 , V_8 ) ;
F_10 ( & V_7 -> V_12 ) ;
F_8 ( & V_11 , V_8 ) ;
F_11 ( V_7 ) ;
}
static struct V_5 * F_12 ( T_1 V_6 )
{
struct V_5 * V_7 ;
unsigned long V_8 ;
F_6 ( & V_11 , V_8 ) ;
F_13 (dev_data, &dev_data_list, dev_data_list) {
if ( V_7 -> V_6 == V_6 )
goto V_13;
}
V_7 = NULL ;
V_13:
F_8 ( & V_11 , V_8 ) ;
return V_7 ;
}
static struct V_5 * F_14 ( T_1 V_6 )
{
struct V_5 * V_7 ;
V_7 = F_12 ( V_6 ) ;
if ( V_7 == NULL )
V_7 = F_3 ( V_6 ) ;
return V_7 ;
}
static inline T_1 F_15 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_16 ( V_15 ) ;
return F_17 ( V_17 -> V_18 -> V_19 , V_17 -> V_20 ) ;
}
static struct V_5 * F_18 ( struct V_14 * V_15 )
{
return V_15 -> V_21 . V_22 ;
}
static bool F_19 ( struct V_16 * V_17 )
{
static const int V_23 [] = {
V_24 ,
V_25 ,
V_26 ,
} ;
int V_27 , V_28 ;
for ( V_27 = 0 ; V_27 < 3 ; ++ V_27 ) {
V_28 = F_20 ( V_17 , V_23 [ V_27 ] ) ;
if ( V_28 == 0 )
return false ;
}
return true ;
}
static bool F_21 ( struct V_16 * V_17 , T_2 V_29 )
{
struct V_5 * V_7 ;
V_7 = F_18 ( & V_17 -> V_15 ) ;
return V_7 -> V_30 & ( 1 << V_29 ) ? true : false ;
}
static void F_22 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
T_3 V_35 ;
for ( V_35 = V_34 -> V_36 ; V_35 < V_34 -> V_37 ;
V_35 += V_38 ) {
if ( V_35 < V_32 -> V_39 )
F_23 ( V_35 >> V_40 ,
V_32 -> V_41 [ 0 ] -> V_42 ) ;
}
}
static void F_24 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 ;
T_1 V_6 ;
V_6 = F_15 ( V_15 ) ;
F_13 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_6 >= V_34 -> V_43 && V_6 <= V_34 -> V_44 ) )
continue;
F_22 ( V_32 , V_34 ) ;
}
}
static bool F_25 ( struct V_14 * V_15 )
{
T_1 V_6 ;
if ( ! V_15 || ! V_15 -> V_45 )
return false ;
if ( ! F_26 ( V_15 ) )
return false ;
V_6 = F_15 ( V_15 ) ;
if ( V_6 > V_46 )
return false ;
if ( V_47 [ V_6 ] == NULL )
return false ;
return true ;
}
static void F_27 ( struct V_14 * V_15 )
{
struct V_31 * V_48 ;
struct V_2 * V_4 ;
struct V_49 * V_50 ;
V_50 = F_28 ( V_15 ) ;
if ( F_29 ( V_50 ) )
return;
V_4 = F_30 ( V_50 ) ;
if ( ! V_4 )
goto V_51;
V_48 = F_1 ( V_4 ) -> V_52 ;
F_24 ( V_15 , V_48 ) ;
V_51:
F_31 ( V_50 ) ;
}
static int F_32 ( struct V_16 * V_17 , T_1 V_53 , void * V_54 )
{
* ( T_1 * ) V_54 = V_53 ;
return 0 ;
}
static T_1 F_33 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_16 ( V_15 ) ;
T_1 V_6 , V_55 , V_56 ;
V_6 = F_15 ( V_15 ) ;
V_55 = V_57 [ V_6 ] ;
F_34 ( V_17 , F_32 , & V_56 ) ;
if ( V_55 == V_56 )
return V_55 ;
if ( V_55 == V_6 ) {
if ( ! V_47 [ V_56 ] ) {
V_47 [ V_56 ] =
V_47 [ V_6 ] ;
memcpy ( V_58 [ V_56 ] . V_54 ,
V_58 [ V_6 ] . V_54 ,
sizeof( V_58 [ V_56 ] . V_54 ) ) ;
}
return V_56 ;
}
F_35 ( L_1
L_2
L_3 , F_36 ( V_55 ) , F_37 ( V_55 ) ,
F_38 ( V_55 ) , F_39 ( V_15 ) , V_17 -> V_59 , V_17 -> V_14 ,
F_36 ( V_56 ) , F_37 ( V_56 ) ,
F_38 ( V_56 ) ) ;
if ( V_56 == V_6 &&
F_36 ( V_55 ) == V_17 -> V_18 -> V_19 ) {
V_17 -> V_60 |= V_61 ;
V_17 -> V_62 = V_55 & 0xff ;
F_35 ( L_4 ,
F_37 ( V_55 ) , F_38 ( V_55 ) ,
F_39 ( V_15 ) ) ;
}
return V_55 ;
}
static int F_40 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_16 ( V_15 ) ;
struct V_5 * V_7 ;
T_1 V_53 ;
if ( V_15 -> V_21 . V_22 )
return 0 ;
V_7 = F_14 ( F_15 ( V_15 ) ) ;
if ( ! V_7 )
return - V_63 ;
V_53 = F_33 ( V_15 ) ;
if ( V_53 != V_7 -> V_6 ) {
struct V_5 * V_64 ;
V_64 = F_14 ( V_53 ) ;
if ( V_64 == NULL ) {
F_41 ( L_5 ,
F_39 ( V_15 ) ) ;
F_9 ( V_7 ) ;
return - V_65 ;
}
V_7 -> V_64 = V_64 ;
F_42 ( & V_7 -> V_10 , & V_64 -> V_10 ) ;
}
if ( F_19 ( V_17 ) ) {
struct V_66 * V_22 ;
V_22 = V_47 [ V_7 -> V_6 ] ;
V_7 -> V_67 = V_22 -> V_68 ;
}
V_15 -> V_21 . V_22 = V_7 ;
F_43 ( V_47 [ V_7 -> V_6 ] -> V_69 ,
V_15 ) ;
return 0 ;
}
static void F_44 ( struct V_14 * V_15 )
{
T_1 V_6 , V_53 ;
V_6 = F_15 ( V_15 ) ;
V_53 = V_57 [ V_6 ] ;
memset ( & V_58 [ V_6 ] , 0 , sizeof( struct V_70 ) ) ;
memset ( & V_58 [ V_53 ] , 0 , sizeof( struct V_70 ) ) ;
V_47 [ V_6 ] = NULL ;
V_47 [ V_53 ] = NULL ;
}
static void F_45 ( struct V_14 * V_15 )
{
struct V_5 * V_7 = F_12 ( F_15 ( V_15 ) ) ;
if ( ! V_7 )
return;
F_46 ( V_47 [ V_7 -> V_6 ] -> V_69 ,
V_15 ) ;
F_47 ( V_15 ) ;
V_7 -> V_64 = NULL ;
V_15 -> V_21 . V_71 = NULL ;
}
static void F_48 ( struct V_72 * V_73 )
{
if ( V_74 == NULL )
return;
V_73 -> V_75 = F_49 ( V_73 -> V_76 , 0444 , V_74 ,
& V_73 -> V_77 ) ;
}
static void F_50 ( void )
{
V_74 = F_51 ( L_6 , NULL ) ;
if ( V_74 == NULL )
return;
V_78 = F_52 ( L_7 , 0444 , V_74 ,
& V_79 ) ;
F_48 ( & V_80 ) ;
F_48 ( & V_81 ) ;
F_48 ( & V_82 ) ;
F_48 ( & V_83 ) ;
F_48 ( & V_84 ) ;
F_48 ( & V_85 ) ;
F_48 ( & V_86 ) ;
F_48 ( & V_87 ) ;
F_48 ( & V_88 ) ;
F_48 ( & V_89 ) ;
F_48 ( & V_90 ) ;
F_48 ( & V_91 ) ;
F_48 ( & V_92 ) ;
F_48 ( & V_93 ) ;
F_48 ( & V_94 ) ;
F_48 ( & V_95 ) ;
}
static void F_53 ( T_1 V_6 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < 4 ; ++ V_27 )
F_41 ( L_8 , V_27 ,
V_58 [ V_6 ] . V_54 [ V_27 ] ) ;
}
static void F_54 ( unsigned long V_96 )
{
struct V_97 * V_98 = F_55 ( V_96 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 4 ; ++ V_27 )
F_41 ( L_9 , V_27 , V_98 -> V_54 [ V_27 ] ) ;
}
static void F_56 ( struct V_66 * V_22 , void * V_99 )
{
int type , V_6 , V_100 , V_8 ;
volatile T_2 * V_101 = V_99 ;
int V_102 = 0 ;
T_3 V_103 ;
V_104:
type = ( V_101 [ 1 ] >> V_105 ) & V_106 ;
V_6 = ( V_101 [ 0 ] >> V_107 ) & V_108 ;
V_100 = ( V_101 [ 1 ] >> V_109 ) & V_110 ;
V_8 = ( V_101 [ 1 ] >> V_111 ) & V_112 ;
V_103 = ( T_3 ) ( ( ( T_3 ) V_101 [ 3 ] ) << 32 ) | V_101 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_102 == V_113 ) {
F_41 ( L_10 ) ;
return;
}
F_57 ( 1 ) ;
goto V_104;
}
F_58 ( V_114 L_11 ) ;
switch ( type ) {
case V_115 :
F_58 ( L_12
L_13 ,
F_36 ( V_6 ) , F_37 ( V_6 ) , F_38 ( V_6 ) ,
V_103 , V_8 ) ;
F_53 ( V_6 ) ;
break;
case V_116 :
F_58 ( L_14
L_15 ,
F_36 ( V_6 ) , F_37 ( V_6 ) , F_38 ( V_6 ) ,
V_100 , V_103 , V_8 ) ;
break;
case V_117 :
F_58 ( L_16
L_13 ,
F_36 ( V_6 ) , F_37 ( V_6 ) , F_38 ( V_6 ) ,
V_103 , V_8 ) ;
break;
case V_118 :
F_58 ( L_17
L_15 ,
F_36 ( V_6 ) , F_37 ( V_6 ) , F_38 ( V_6 ) ,
V_100 , V_103 , V_8 ) ;
break;
case V_119 :
F_58 ( L_18 , V_103 ) ;
F_54 ( V_103 ) ;
break;
case V_120 :
F_58 ( L_19
L_20 , V_103 , V_8 ) ;
break;
case V_121 :
F_58 ( L_21
L_22 ,
F_36 ( V_6 ) , F_37 ( V_6 ) , F_38 ( V_6 ) ,
V_103 ) ;
break;
case V_122 :
F_58 ( L_23
L_13 ,
F_36 ( V_6 ) , F_37 ( V_6 ) , F_38 ( V_6 ) ,
V_103 , V_8 ) ;
break;
default:
F_58 ( V_114 L_24 , type ) ;
}
memset ( V_99 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_59 ( struct V_66 * V_22 )
{
T_2 V_123 , V_124 ;
V_123 = F_60 ( V_22 -> V_125 + V_126 ) ;
V_124 = F_60 ( V_22 -> V_125 + V_127 ) ;
while ( V_123 != V_124 ) {
F_56 ( V_22 , V_22 -> V_128 + V_123 ) ;
V_123 = ( V_123 + V_129 ) % V_22 -> V_130 ;
}
F_61 ( V_123 , V_22 -> V_125 + V_126 ) ;
}
static void F_62 ( struct V_66 * V_22 , T_3 * V_131 )
{
struct V_132 V_133 ;
F_63 ( V_95 ) ;
if ( F_64 ( V_131 [ 0 ] ) != V_134 ) {
F_65 ( L_25 ) ;
return;
}
V_133 . V_103 = V_131 [ 1 ] ;
V_133 . V_135 = F_66 ( V_131 [ 0 ] ) ;
V_133 . V_136 = F_67 ( V_131 [ 0 ] ) ;
V_133 . V_137 = F_68 ( V_131 [ 0 ] ) ;
V_133 . V_8 = F_69 ( V_131 [ 0 ] ) ;
F_70 ( & V_138 , 0 , & V_133 ) ;
}
static void F_71 ( struct V_66 * V_22 )
{
T_2 V_123 , V_124 ;
if ( V_22 -> V_139 == NULL )
return;
V_123 = F_60 ( V_22 -> V_125 + V_140 ) ;
V_124 = F_60 ( V_22 -> V_125 + V_141 ) ;
while ( V_123 != V_124 ) {
volatile T_3 * V_131 ;
T_3 V_142 [ 2 ] ;
int V_27 ;
V_131 = ( T_3 * ) ( V_22 -> V_139 + V_123 ) ;
for ( V_27 = 0 ; V_27 < V_113 ; ++ V_27 ) {
if ( F_64 ( V_131 [ 0 ] ) != 0 )
break;
F_57 ( 1 ) ;
}
V_142 [ 0 ] = V_131 [ 0 ] ;
V_142 [ 1 ] = V_131 [ 1 ] ;
V_131 [ 0 ] = V_131 [ 1 ] = 0UL ;
V_123 = ( V_123 + V_143 ) % V_144 ;
F_61 ( V_123 , V_22 -> V_125 + V_140 ) ;
F_62 ( V_22 , V_142 ) ;
V_123 = F_60 ( V_22 -> V_125 + V_140 ) ;
V_124 = F_60 ( V_22 -> V_125 + V_141 ) ;
}
}
T_4 F_72 ( int V_145 , void * V_54 )
{
struct V_66 * V_22 = (struct V_66 * ) V_54 ;
T_2 V_146 = F_60 ( V_22 -> V_125 + V_147 ) ;
while ( V_146 & ( V_148 | V_149 ) ) {
F_61 ( ( V_148 | V_149 ) ,
V_22 -> V_125 + V_147 ) ;
if ( V_146 & V_148 ) {
F_73 ( L_26 ) ;
F_59 ( V_22 ) ;
}
if ( V_146 & V_149 ) {
F_73 ( L_27 ) ;
F_71 ( V_22 ) ;
}
V_146 = F_60 ( V_22 -> V_125 + V_147 ) ;
}
return V_150 ;
}
T_4 F_74 ( int V_145 , void * V_54 )
{
return V_151 ;
}
static int F_75 ( volatile T_3 * V_152 )
{
int V_27 = 0 ;
while ( * V_152 == 0 && V_27 < V_113 ) {
F_57 ( 1 ) ;
V_27 += 1 ;
}
if ( V_27 == V_113 ) {
F_76 ( L_28 ) ;
return - V_153 ;
}
return 0 ;
}
static void F_77 ( struct V_66 * V_22 ,
struct V_97 * V_98 ,
T_2 V_124 )
{
T_5 * V_154 ;
V_154 = V_22 -> V_155 + V_124 ;
V_124 = ( V_124 + sizeof( * V_98 ) ) % V_22 -> V_156 ;
memcpy ( V_154 , V_98 , sizeof( * V_98 ) ) ;
F_61 ( V_124 , V_22 -> V_125 + V_157 ) ;
}
static void F_78 ( struct V_97 * V_98 , T_3 V_103 )
{
F_79 ( V_103 & 0x7ULL ) ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_54 [ 0 ] = F_80 ( F_81 ( V_103 ) ) | V_158 ;
V_98 -> V_54 [ 1 ] = F_82 ( F_81 ( V_103 ) ) ;
V_98 -> V_54 [ 2 ] = 1 ;
F_83 ( V_98 , V_159 ) ;
}
static void F_84 ( struct V_97 * V_98 , T_1 V_6 )
{
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_54 [ 0 ] = V_6 ;
F_83 ( V_98 , V_160 ) ;
}
static void F_85 ( struct V_97 * V_98 , T_3 V_103 ,
T_6 V_161 , T_1 V_100 , int V_162 )
{
T_3 V_163 ;
bool V_164 ;
V_163 = F_86 ( V_103 , V_161 , V_38 ) ;
V_164 = false ;
if ( V_163 > 1 ) {
V_103 = V_165 ;
V_164 = true ;
}
V_103 &= V_166 ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_54 [ 1 ] |= V_100 ;
V_98 -> V_54 [ 2 ] = F_80 ( V_103 ) ;
V_98 -> V_54 [ 3 ] = F_82 ( V_103 ) ;
F_83 ( V_98 , V_167 ) ;
if ( V_164 )
V_98 -> V_54 [ 2 ] |= V_168 ;
if ( V_162 )
V_98 -> V_54 [ 2 ] |= V_169 ;
}
static void F_87 ( struct V_97 * V_98 , T_1 V_6 , int V_170 ,
T_3 V_103 , T_6 V_161 )
{
T_3 V_163 ;
bool V_164 ;
V_163 = F_86 ( V_103 , V_161 , V_38 ) ;
V_164 = false ;
if ( V_163 > 1 ) {
V_103 = V_165 ;
V_164 = true ;
}
V_103 &= V_166 ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_54 [ 0 ] = V_6 ;
V_98 -> V_54 [ 0 ] |= ( V_170 & 0xff ) << 24 ;
V_98 -> V_54 [ 1 ] = V_6 ;
V_98 -> V_54 [ 2 ] = F_80 ( V_103 ) ;
V_98 -> V_54 [ 3 ] = F_82 ( V_103 ) ;
F_83 ( V_98 , V_171 ) ;
if ( V_164 )
V_98 -> V_54 [ 2 ] |= V_168 ;
}
static void F_88 ( struct V_97 * V_98 , T_1 V_100 , int V_135 ,
T_3 V_103 , bool V_161 )
{
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_103 &= ~ ( 0xfffULL ) ;
V_98 -> V_54 [ 0 ] = V_135 ;
V_98 -> V_54 [ 1 ] = V_100 ;
V_98 -> V_54 [ 2 ] = F_80 ( V_103 ) ;
V_98 -> V_54 [ 3 ] = F_82 ( V_103 ) ;
V_98 -> V_54 [ 2 ] |= V_169 ;
V_98 -> V_54 [ 2 ] |= V_172 ;
if ( V_161 )
V_98 -> V_54 [ 2 ] |= V_168 ;
F_83 ( V_98 , V_167 ) ;
}
static void F_89 ( struct V_97 * V_98 , T_1 V_6 , int V_135 ,
int V_170 , T_3 V_103 , bool V_161 )
{
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_103 &= ~ ( 0xfffULL ) ;
V_98 -> V_54 [ 0 ] = V_6 ;
V_98 -> V_54 [ 0 ] |= ( ( V_135 >> 8 ) & 0xff ) << 16 ;
V_98 -> V_54 [ 0 ] |= ( V_170 & 0xff ) << 24 ;
V_98 -> V_54 [ 1 ] = V_6 ;
V_98 -> V_54 [ 1 ] |= ( V_135 & 0xff ) << 16 ;
V_98 -> V_54 [ 2 ] = F_80 ( V_103 ) ;
V_98 -> V_54 [ 2 ] |= V_172 ;
V_98 -> V_54 [ 3 ] = F_82 ( V_103 ) ;
if ( V_161 )
V_98 -> V_54 [ 2 ] |= V_168 ;
F_83 ( V_98 , V_171 ) ;
}
static void F_90 ( struct V_97 * V_98 , T_1 V_6 , int V_135 ,
int V_146 , int V_137 , bool V_173 )
{
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_54 [ 0 ] = V_6 ;
if ( V_173 ) {
V_98 -> V_54 [ 1 ] = V_135 ;
V_98 -> V_54 [ 2 ] = V_172 ;
}
V_98 -> V_54 [ 3 ] = V_137 & 0x1ff ;
V_98 -> V_54 [ 3 ] |= ( V_146 & V_174 ) << V_175 ;
F_83 ( V_98 , V_176 ) ;
}
static void F_91 ( struct V_97 * V_98 )
{
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
F_83 ( V_98 , V_177 ) ;
}
static void F_92 ( struct V_97 * V_98 , T_1 V_6 )
{
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_54 [ 0 ] = V_6 ;
F_83 ( V_98 , V_178 ) ;
}
static int F_93 ( struct V_66 * V_22 ,
struct V_97 * V_98 ,
bool V_179 )
{
T_2 V_180 , V_124 , V_123 , V_181 ;
unsigned long V_8 ;
F_79 ( V_22 -> V_156 & V_182 ) ;
V_183:
F_6 ( & V_22 -> V_184 , V_8 ) ;
V_123 = F_60 ( V_22 -> V_125 + V_185 ) ;
V_124 = F_60 ( V_22 -> V_125 + V_157 ) ;
V_181 = ( V_124 + sizeof( * V_98 ) ) % V_22 -> V_156 ;
V_180 = ( V_123 - V_181 ) % V_22 -> V_156 ;
if ( V_180 <= 2 ) {
struct V_97 V_186 ;
volatile T_3 V_152 = 0 ;
int V_187 ;
F_78 ( & V_186 , ( T_3 ) & V_152 ) ;
F_77 ( V_22 , & V_186 , V_124 ) ;
F_8 ( & V_22 -> V_184 , V_8 ) ;
if ( ( V_187 = F_75 ( & V_152 ) ) != 0 )
return V_187 ;
goto V_183;
}
F_77 ( V_22 , V_98 , V_124 ) ;
V_22 -> V_188 = V_179 ;
F_8 ( & V_22 -> V_184 , V_8 ) ;
return 0 ;
}
static int F_94 ( struct V_66 * V_22 , struct V_97 * V_98 )
{
return F_93 ( V_22 , V_98 , true ) ;
}
static int F_95 ( struct V_66 * V_22 )
{
struct V_97 V_98 ;
volatile T_3 V_152 = 0 ;
int V_187 ;
if ( ! V_22 -> V_188 )
return 0 ;
F_78 ( & V_98 , ( T_3 ) & V_152 ) ;
V_187 = F_93 ( V_22 , & V_98 , false ) ;
if ( V_187 )
return V_187 ;
return F_75 ( & V_152 ) ;
}
static int F_96 ( struct V_66 * V_22 , T_1 V_6 )
{
struct V_97 V_98 ;
F_84 ( & V_98 , V_6 ) ;
return F_94 ( V_22 , & V_98 ) ;
}
static void F_97 ( struct V_66 * V_22 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 <= 0xffff ; ++ V_6 )
F_96 ( V_22 , V_6 ) ;
F_95 ( V_22 ) ;
}
static void F_98 ( struct V_66 * V_22 )
{
T_2 V_189 ;
for ( V_189 = 0 ; V_189 <= 0xffff ; ++ V_189 ) {
struct V_97 V_98 ;
F_85 ( & V_98 , 0 , V_165 ,
V_189 , 1 ) ;
F_94 ( V_22 , & V_98 ) ;
}
F_95 ( V_22 ) ;
}
static void F_99 ( struct V_66 * V_22 )
{
struct V_97 V_98 ;
F_91 ( & V_98 ) ;
F_94 ( V_22 , & V_98 ) ;
F_95 ( V_22 ) ;
}
static void F_100 ( struct V_66 * V_22 , T_1 V_6 )
{
struct V_97 V_98 ;
F_92 ( & V_98 , V_6 ) ;
F_94 ( V_22 , & V_98 ) ;
}
static void F_101 ( struct V_66 * V_22 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 <= V_190 ; V_6 ++ )
F_100 ( V_22 , V_6 ) ;
F_95 ( V_22 ) ;
}
void F_102 ( struct V_66 * V_22 )
{
if ( F_103 ( V_22 , V_191 ) ) {
F_99 ( V_22 ) ;
} else {
F_97 ( V_22 ) ;
F_101 ( V_22 ) ;
F_98 ( V_22 ) ;
}
}
static int F_104 ( struct V_5 * V_7 ,
T_3 V_103 , T_6 V_161 )
{
struct V_66 * V_22 ;
struct V_97 V_98 ;
int V_170 ;
V_170 = V_7 -> V_192 . V_170 ;
V_22 = V_47 [ V_7 -> V_6 ] ;
F_87 ( & V_98 , V_7 -> V_6 , V_170 , V_103 , V_161 ) ;
return F_94 ( V_22 , & V_98 ) ;
}
static int F_105 ( struct V_5 * V_7 )
{
struct V_66 * V_22 ;
int V_187 ;
V_22 = V_47 [ V_7 -> V_6 ] ;
V_187 = F_96 ( V_22 , V_7 -> V_6 ) ;
if ( V_187 )
return V_187 ;
if ( V_7 -> V_192 . V_193 )
V_187 = F_104 ( V_7 , 0 , ~ 0UL ) ;
return V_187 ;
}
static void F_106 ( struct V_1 * V_4 ,
T_3 V_103 , T_6 V_161 , int V_162 )
{
struct V_5 * V_7 ;
struct V_97 V_98 ;
int V_187 = 0 , V_27 ;
F_85 ( & V_98 , V_103 , V_161 , V_4 -> V_194 , V_162 ) ;
for ( V_27 = 0 ; V_27 < V_195 ; ++ V_27 ) {
if ( ! V_4 -> V_196 [ V_27 ] )
continue;
V_187 |= F_94 ( V_197 [ V_27 ] , & V_98 ) ;
}
F_13 (dev_data, &domain->dev_list, list) {
if ( ! V_7 -> V_192 . V_193 )
continue;
V_187 |= F_104 ( V_7 , V_103 , V_161 ) ;
}
F_79 ( V_187 ) ;
}
static void F_107 ( struct V_1 * V_4 ,
T_3 V_103 , T_6 V_161 )
{
F_106 ( V_4 , V_103 , V_161 , 0 ) ;
}
static void F_108 ( struct V_1 * V_4 )
{
F_106 ( V_4 , 0 , V_165 , 0 ) ;
}
static void F_109 ( struct V_1 * V_4 )
{
F_106 ( V_4 , 0 , V_165 , 1 ) ;
}
static void F_110 ( struct V_1 * V_4 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_195 ; ++ V_27 ) {
if ( ! V_4 -> V_196 [ V_27 ] )
continue;
F_95 ( V_197 [ V_27 ] ) ;
}
}
static void F_111 ( struct V_1 * V_4 )
{
struct V_5 * V_7 ;
F_13 (dev_data, &domain->dev_list, list)
F_105 ( V_7 ) ;
}
static bool F_112 ( struct V_1 * V_4 ,
T_7 V_198 )
{
T_3 * V_199 ;
if ( V_4 -> V_200 == V_201 )
return false ;
V_199 = ( void * ) F_113 ( V_198 ) ;
if ( ! V_199 )
return false ;
* V_199 = F_114 ( V_4 -> V_200 ,
F_115 ( V_4 -> V_202 ) ) ;
V_4 -> V_202 = V_199 ;
V_4 -> V_200 += 1 ;
V_4 -> V_203 = true ;
return true ;
}
static T_3 * F_116 ( struct V_1 * V_4 ,
unsigned long V_103 ,
unsigned long V_204 ,
T_3 * * V_205 ,
T_7 V_198 )
{
int V_206 , V_207 ;
T_3 * V_199 , * V_208 ;
F_117 ( ! F_118 ( V_204 ) ) ;
while ( V_103 > F_119 ( V_4 -> V_200 ) )
F_112 ( V_4 , V_198 ) ;
V_206 = V_4 -> V_200 - 1 ;
V_199 = & V_4 -> V_202 [ F_120 ( V_206 , V_103 ) ] ;
V_103 = F_121 ( V_103 , V_204 ) ;
V_207 = F_122 ( V_204 ) ;
while ( V_206 > V_207 ) {
if ( ! F_123 ( * V_199 ) ) {
V_208 = ( T_3 * ) F_113 ( V_198 ) ;
if ( ! V_208 )
return NULL ;
* V_199 = F_114 ( V_206 , F_115 ( V_208 ) ) ;
}
if ( F_124 ( * V_199 ) != V_206 )
return NULL ;
V_206 -= 1 ;
V_199 = F_125 ( * V_199 ) ;
if ( V_205 && V_206 == V_207 )
* V_205 = V_199 ;
V_199 = & V_199 [ F_120 ( V_206 , V_103 ) ] ;
}
return V_199 ;
}
static T_3 * F_126 ( struct V_1 * V_4 ,
unsigned long V_103 ,
unsigned long * V_204 )
{
int V_206 ;
T_3 * V_199 ;
if ( V_103 > F_119 ( V_4 -> V_200 ) )
return NULL ;
V_206 = V_4 -> V_200 - 1 ;
V_199 = & V_4 -> V_202 [ F_120 ( V_206 , V_103 ) ] ;
* V_204 = F_127 ( V_206 ) ;
while ( V_206 > 0 ) {
if ( ! F_123 ( * V_199 ) )
return NULL ;
if ( F_124 ( * V_199 ) == 7 ||
F_124 ( * V_199 ) == 0 )
break;
if ( F_124 ( * V_199 ) != V_206 )
return NULL ;
V_206 -= 1 ;
V_199 = F_125 ( * V_199 ) ;
V_199 = & V_199 [ F_120 ( V_206 , V_103 ) ] ;
* V_204 = F_127 ( V_206 ) ;
}
if ( F_124 ( * V_199 ) == 0x07 ) {
unsigned long V_209 ;
* V_204 = V_209 = F_128 ( * V_199 ) ;
V_209 = ~ ( ( F_129 ( V_209 ) << 3 ) - 1 ) ;
V_199 = ( T_3 * ) ( ( ( unsigned long ) V_199 ) & V_209 ) ;
}
return V_199 ;
}
static int F_130 ( struct V_1 * V_3 ,
unsigned long V_210 ,
unsigned long V_96 ,
int V_211 ,
unsigned long V_204 )
{
T_3 V_212 , * V_199 ;
int V_27 , V_102 ;
F_117 ( ! F_131 ( V_210 , V_204 ) ) ;
F_117 ( ! F_131 ( V_96 , V_204 ) ) ;
if ( ! ( V_211 & V_213 ) )
return - V_214 ;
V_102 = F_129 ( V_204 ) ;
V_199 = F_116 ( V_3 , V_210 , V_204 , NULL , V_9 ) ;
if ( ! V_199 )
return - V_63 ;
for ( V_27 = 0 ; V_27 < V_102 ; ++ V_27 )
if ( F_123 ( V_199 [ V_27 ] ) )
return - V_215 ;
if ( V_102 > 1 ) {
V_212 = F_132 ( V_96 , V_204 ) ;
V_212 |= F_133 ( 7 ) | V_216 | V_217 ;
} else
V_212 = V_96 | V_216 | V_217 ;
if ( V_211 & V_218 )
V_212 |= V_219 ;
if ( V_211 & V_220 )
V_212 |= V_221 ;
for ( V_27 = 0 ; V_27 < V_102 ; ++ V_27 )
V_199 [ V_27 ] = V_212 ;
F_134 ( V_3 ) ;
return 0 ;
}
static unsigned long F_135 ( struct V_1 * V_3 ,
unsigned long V_210 ,
unsigned long V_204 )
{
unsigned long long V_222 ;
unsigned long V_223 ;
T_3 * V_199 ;
F_117 ( ! F_118 ( V_204 ) ) ;
V_222 = 0 ;
while ( V_222 < V_204 ) {
V_199 = F_126 ( V_3 , V_210 , & V_223 ) ;
if ( V_199 ) {
int V_27 , V_102 ;
V_102 = F_129 ( V_223 ) ;
for ( V_27 = 0 ; V_27 < V_102 ; V_27 ++ )
V_199 [ V_27 ] = 0ULL ;
}
V_210 = ( V_210 & ~ ( V_223 - 1 ) ) + V_223 ;
V_222 += V_223 ;
}
F_117 ( V_222 && ! F_118 ( V_222 ) ) ;
return V_222 ;
}
static void F_136 ( struct V_31 * V_3 ,
unsigned long V_224 ,
unsigned int V_163 )
{
unsigned int V_27 , V_225 = V_3 -> V_39 >> V_40 ;
if ( V_224 + V_163 > V_225 )
V_163 = V_225 - V_224 ;
for ( V_27 = V_224 ; V_27 < V_224 + V_163 ; ++ V_27 ) {
int V_226 = V_27 / V_227 ;
int V_208 = V_27 % V_227 ;
F_23 ( V_208 , V_3 -> V_41 [ V_226 ] -> V_42 ) ;
}
}
static int F_137 ( struct V_31 * V_32 ,
bool V_228 , T_7 V_198 )
{
int V_226 = V_32 -> V_39 >> V_229 ;
struct V_66 * V_22 ;
unsigned long V_27 , V_230 , V_231 ;
#ifdef F_138
V_228 = false ;
#endif
if ( V_226 >= V_232 )
return - V_63 ;
V_32 -> V_41 [ V_226 ] = F_4 ( sizeof( struct V_233 ) , V_198 ) ;
if ( ! V_32 -> V_41 [ V_226 ] )
return - V_63 ;
V_32 -> V_41 [ V_226 ] -> V_42 = ( void * ) F_113 ( V_198 ) ;
if ( ! V_32 -> V_41 [ V_226 ] -> V_42 )
goto V_234;
V_32 -> V_41 [ V_226 ] -> V_235 = V_32 -> V_39 ;
if ( V_228 ) {
unsigned long V_103 = V_32 -> V_39 ;
int V_27 , V_236 = V_227 / 512 ;
T_3 * V_199 , * V_205 ;
for ( V_27 = 0 ; V_27 < V_236 ; ++ V_27 ) {
V_199 = F_116 ( & V_32 -> V_4 , V_103 , V_38 ,
& V_205 , V_198 ) ;
if ( ! V_199 )
goto V_234;
V_32 -> V_41 [ V_226 ] -> V_237 [ V_27 ] = V_205 ;
V_103 += V_238 / 64 ;
}
}
V_230 = V_32 -> V_39 ;
V_32 -> V_39 += V_238 ;
if ( V_230 < V_239 &&
V_32 -> V_39 > V_239 ) {
unsigned long V_240 ;
int V_163 ;
V_163 = F_86 ( V_239 , 0x10000 , V_38 ) ;
V_240 = V_239 >> V_40 ;
F_136 ( V_32 , V_240 , V_163 ) ;
}
F_139 (iommu) {
if ( V_22 -> V_241 &&
V_22 -> V_241 >= V_32 -> V_41 [ V_226 ] -> V_235
&& V_22 -> V_241 < V_32 -> V_39 ) {
unsigned long V_242 ;
int V_163 = F_86 ( V_22 -> V_241 ,
V_22 -> V_243 ,
V_38 ) ;
V_242 = V_22 -> V_241 >> V_40 ;
F_136 ( V_32 , V_242 , V_163 ) ;
}
}
for ( V_27 = V_32 -> V_41 [ V_226 ] -> V_235 ;
V_27 < V_32 -> V_39 ;
V_27 += V_231 ) {
T_3 * V_199 = F_126 ( & V_32 -> V_4 , V_27 , & V_231 ) ;
if ( ! V_199 || ! F_123 ( * V_199 ) )
continue;
F_136 ( V_32 , V_27 >> V_40 ,
V_231 >> 12 ) ;
}
F_134 ( & V_32 -> V_4 ) ;
return 0 ;
V_234:
F_134 ( & V_32 -> V_4 ) ;
F_140 ( ( unsigned long ) V_32 -> V_41 [ V_226 ] -> V_42 ) ;
F_11 ( V_32 -> V_41 [ V_226 ] ) ;
V_32 -> V_41 [ V_226 ] = NULL ;
return - V_63 ;
}
static unsigned long F_141 ( struct V_14 * V_15 ,
struct V_31 * V_3 ,
unsigned int V_163 ,
unsigned long V_244 ,
T_3 V_45 ,
unsigned long V_245 )
{
unsigned long V_246 = V_3 -> V_247 % V_238 ;
int V_248 = V_3 -> V_39 >> V_229 ;
int V_27 = V_245 >> V_229 ;
unsigned long V_249 , V_250 ;
unsigned long V_103 = - 1 ;
unsigned long V_251 ;
V_246 >>= V_40 ;
V_250 = F_142 ( V_15 ) ;
V_249 = V_250 + 1 ? F_143 ( V_250 + 1 , V_38 ) >> V_40 :
1UL << ( V_252 - V_40 ) ;
for (; V_27 < V_248 ; ++ V_27 ) {
unsigned long V_235 = V_3 -> V_41 [ V_27 ] -> V_235 >> V_40 ;
if ( V_3 -> V_41 [ V_27 ] -> V_235 >= V_45 )
break;
V_251 = F_144 ( V_227 , V_235 ,
V_45 >> V_40 ) ;
V_103 = F_145 ( V_3 -> V_41 [ V_27 ] -> V_42 ,
V_251 , V_246 , V_163 , 0 ,
V_249 , V_244 ) ;
if ( V_103 != - 1 ) {
V_103 = V_3 -> V_41 [ V_27 ] -> V_235 +
( V_103 << V_40 ) ;
V_3 -> V_247 = V_103 + ( V_163 << V_40 ) ;
break;
}
V_246 = 0 ;
}
return V_103 ;
}
static unsigned long F_146 ( struct V_14 * V_15 ,
struct V_31 * V_3 ,
unsigned int V_163 ,
unsigned long V_244 ,
T_3 V_45 )
{
unsigned long V_103 ;
#ifdef F_138
V_3 -> V_247 = 0 ;
V_3 -> V_253 = true ;
#endif
V_103 = F_141 ( V_15 , V_3 , V_163 , V_244 ,
V_45 , V_3 -> V_247 ) ;
if ( V_103 == - 1 ) {
V_3 -> V_247 = 0 ;
V_103 = F_141 ( V_15 , V_3 , V_163 , V_244 ,
V_45 , 0 ) ;
V_3 -> V_253 = true ;
}
if ( F_147 ( V_103 == - 1 ) )
V_103 = V_254 ;
F_79 ( ( V_103 + ( V_38 * V_163 ) ) > V_3 -> V_39 ) ;
return V_103 ;
}
static void F_148 ( struct V_31 * V_3 ,
unsigned long V_103 ,
unsigned int V_163 )
{
unsigned V_27 = V_103 >> V_229 ;
struct V_233 * V_255 = V_3 -> V_41 [ V_27 ] ;
F_117 ( V_27 >= V_232 || V_255 == NULL ) ;
#ifdef F_138
if ( V_27 < 4 )
return;
#endif
if ( V_103 >= V_3 -> V_247 )
V_3 -> V_253 = true ;
V_103 = ( V_103 % V_238 ) >> V_40 ;
F_149 ( V_255 -> V_42 , V_103 , V_163 ) ;
}
static void F_150 ( struct V_1 * V_4 )
{
unsigned long V_8 ;
F_6 ( & V_256 , V_8 ) ;
F_42 ( & V_4 -> V_257 , & V_258 ) ;
F_8 ( & V_256 , V_8 ) ;
}
static void F_151 ( struct V_1 * V_4 )
{
unsigned long V_8 ;
F_6 ( & V_256 , V_8 ) ;
F_10 ( & V_4 -> V_257 ) ;
F_8 ( & V_256 , V_8 ) ;
}
static T_1 F_152 ( void )
{
unsigned long V_8 ;
int V_194 ;
F_153 ( & V_259 , V_8 ) ;
V_194 = F_154 ( V_260 , V_261 ) ;
F_117 ( V_194 == 0 ) ;
if ( V_194 > 0 && V_194 < V_261 )
F_23 ( V_194 , V_260 ) ;
else
V_194 = 0 ;
F_155 ( & V_259 , V_8 ) ;
return V_194 ;
}
static void F_156 ( int V_194 )
{
unsigned long V_8 ;
F_153 ( & V_259 , V_8 ) ;
if ( V_194 > 0 && V_194 < V_261 )
F_157 ( V_194 , V_260 ) ;
F_155 ( & V_259 , V_8 ) ;
}
static void F_158 ( struct V_1 * V_4 )
{
unsigned long V_262 = ( unsigned long ) V_4 -> V_202 ;
switch ( V_4 -> V_200 ) {
case V_263 :
break;
case V_264 :
F_140 ( V_262 ) ;
break;
case V_265 :
F_159 ( V_262 ) ;
break;
case V_266 :
F_160 ( V_262 ) ;
break;
case V_267 :
F_161 ( V_262 ) ;
break;
case V_268 :
F_162 ( V_262 ) ;
break;
case V_201 :
F_163 ( V_262 ) ;
break;
default:
F_164 () ;
}
}
static void F_165 ( T_3 * V_269 )
{
T_3 * V_270 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 512 ; ++ V_27 ) {
if ( ! ( V_269 [ V_27 ] & V_271 ) )
continue;
V_270 = F_166 ( V_269 [ V_27 ] & V_166 ) ;
F_140 ( ( unsigned long ) V_270 ) ;
}
}
static void F_167 ( T_3 * V_269 )
{
T_3 * V_270 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 512 ; ++ V_27 ) {
if ( ! ( V_269 [ V_27 ] & V_271 ) )
continue;
V_270 = F_166 ( V_269 [ V_27 ] & V_166 ) ;
F_165 ( V_270 ) ;
}
}
static void F_168 ( struct V_1 * V_4 )
{
if ( V_4 -> V_272 == 2 )
F_167 ( V_4 -> V_273 ) ;
else if ( V_4 -> V_272 == 1 )
F_165 ( V_4 -> V_273 ) ;
else if ( V_4 -> V_272 != 0 )
F_164 () ;
F_140 ( ( unsigned long ) V_4 -> V_273 ) ;
}
static void F_169 ( struct V_31 * V_3 )
{
int V_27 ;
if ( ! V_3 )
return;
F_151 ( & V_3 -> V_4 ) ;
F_158 ( & V_3 -> V_4 ) ;
for ( V_27 = 0 ; V_27 < V_232 ; ++ V_27 ) {
if ( ! V_3 -> V_41 [ V_27 ] )
continue;
F_140 ( ( unsigned long ) V_3 -> V_41 [ V_27 ] -> V_42 ) ;
F_11 ( V_3 -> V_41 [ V_27 ] ) ;
}
F_11 ( V_3 ) ;
}
static struct V_31 * F_170 ( void )
{
struct V_31 * V_32 ;
V_32 = F_4 ( sizeof( struct V_31 ) , V_9 ) ;
if ( ! V_32 )
return NULL ;
if ( F_171 ( & V_32 -> V_4 ) )
goto V_274;
V_32 -> V_4 . V_200 = V_265 ;
V_32 -> V_4 . V_202 = ( void * ) F_113 ( V_9 ) ;
V_32 -> V_4 . V_8 = V_275 ;
V_32 -> V_4 . V_52 = V_32 ;
if ( ! V_32 -> V_4 . V_202 )
goto V_274;
V_32 -> V_253 = false ;
F_150 ( & V_32 -> V_4 ) ;
if ( F_137 ( V_32 , true , V_9 ) )
goto V_274;
V_32 -> V_41 [ 0 ] -> V_42 [ 0 ] = 1 ;
V_32 -> V_247 = 0 ;
return V_32 ;
V_274:
F_169 ( V_32 ) ;
return NULL ;
}
static bool V_31 ( struct V_1 * V_4 )
{
return V_4 -> V_8 & V_275 ;
}
static void F_172 ( T_1 V_6 , struct V_1 * V_4 , bool V_192 )
{
T_3 V_276 = 0 ;
T_3 V_8 = 0 ;
if ( V_4 -> V_200 != V_263 )
V_276 = F_115 ( V_4 -> V_202 ) ;
V_276 |= ( V_4 -> V_200 & V_277 )
<< V_278 ;
V_276 |= V_219 | V_221 | V_216 | V_279 ;
V_8 = V_58 [ V_6 ] . V_54 [ 1 ] ;
if ( V_192 )
V_8 |= V_280 ;
if ( V_4 -> V_8 & V_281 ) {
T_3 V_282 = F_81 ( V_4 -> V_273 ) ;
T_3 V_272 = V_4 -> V_272 ;
T_3 V_283 ;
V_276 |= V_284 ;
V_276 |= ( V_272 & V_285 ) << V_286 ;
V_283 = F_173 ( ~ 0ULL ) << V_287 ;
V_8 &= ~ V_283 ;
V_283 = F_174 ( ~ 0ULL ) << V_288 ;
V_8 &= ~ V_283 ;
V_283 = F_175 ( V_282 ) << V_289 ;
V_276 |= V_283 ;
V_283 = F_173 ( V_282 ) << V_287 ;
V_8 |= V_283 ;
V_283 = F_174 ( V_282 ) << V_288 ;
V_8 |= V_283 ;
}
V_8 &= ~ ( 0xffffUL ) ;
V_8 |= V_4 -> V_194 ;
V_58 [ V_6 ] . V_54 [ 1 ] = V_8 ;
V_58 [ V_6 ] . V_54 [ 0 ] = V_276 ;
}
static void F_176 ( T_1 V_6 )
{
V_58 [ V_6 ] . V_54 [ 0 ] = V_216 | V_279 ;
V_58 [ V_6 ] . V_54 [ 1 ] = 0 ;
F_177 ( V_6 ) ;
}
static void F_178 ( struct V_5 * V_7 ,
struct V_1 * V_4 )
{
struct V_66 * V_22 ;
bool V_192 ;
V_22 = V_47 [ V_7 -> V_6 ] ;
V_192 = V_7 -> V_192 . V_193 ;
V_7 -> V_4 = V_4 ;
F_42 ( & V_7 -> V_257 , & V_4 -> V_290 ) ;
F_172 ( V_7 -> V_6 , V_4 , V_192 ) ;
V_4 -> V_196 [ V_22 -> V_226 ] += 1 ;
V_4 -> V_291 += 1 ;
F_105 ( V_7 ) ;
}
static void F_179 ( struct V_5 * V_7 )
{
struct V_66 * V_22 ;
V_22 = V_47 [ V_7 -> V_6 ] ;
V_7 -> V_4 -> V_196 [ V_22 -> V_226 ] -= 1 ;
V_7 -> V_4 -> V_291 -= 1 ;
V_7 -> V_4 = NULL ;
F_10 ( & V_7 -> V_257 ) ;
F_176 ( V_7 -> V_6 ) ;
F_105 ( V_7 ) ;
}
static int F_180 ( struct V_5 * V_7 ,
struct V_1 * V_4 )
{
struct V_5 * V_123 , * V_142 ;
int V_187 ;
F_181 ( & V_4 -> V_184 ) ;
V_123 = V_7 ;
if ( V_123 -> V_64 != NULL )
V_123 = V_123 -> V_64 ;
V_187 = - V_215 ;
if ( V_123 -> V_4 != NULL )
goto V_13;
F_178 ( V_123 , V_4 ) ;
F_13 (entry, &head->alias_list, alias_list)
F_178 ( V_142 , V_4 ) ;
V_187 = 0 ;
V_13:
F_182 ( & V_4 -> V_184 ) ;
return V_187 ;
}
static void F_183 ( struct V_16 * V_17 )
{
F_184 ( V_17 ) ;
F_185 ( V_17 ) ;
F_186 ( V_17 ) ;
}
static int F_187 ( struct V_16 * V_17 )
{
T_1 V_292 ;
int V_28 ;
V_28 = F_20 ( V_17 , V_25 ) ;
if ( ! V_28 )
return - V_214 ;
F_188 ( V_17 , V_28 + V_293 , & V_292 ) ;
V_292 |= V_294 ;
F_189 ( V_17 , V_28 + V_293 , V_292 ) ;
return 0 ;
}
static int F_190 ( struct V_16 * V_17 )
{
bool V_295 ;
int V_296 , V_187 ;
V_296 = 32 ;
if ( F_21 ( V_17 , V_297 ) )
V_296 = 1 ;
V_295 = F_21 ( V_17 , V_298 ) ;
V_187 = F_191 ( V_17 , 0 ) ;
if ( V_187 )
goto V_299;
V_187 = F_192 ( V_17 ) ;
if ( V_187 )
goto V_299;
V_187 = F_193 ( V_17 , V_296 ) ;
if ( V_187 )
goto V_299;
if ( V_295 ) {
V_187 = F_187 ( V_17 ) ;
if ( V_187 )
goto V_299;
}
V_187 = F_194 ( V_17 , V_40 ) ;
if ( V_187 )
goto V_299;
return 0 ;
V_299:
F_185 ( V_17 ) ;
F_186 ( V_17 ) ;
return V_187 ;
}
static bool F_195 ( struct V_16 * V_17 )
{
T_1 V_146 ;
int V_28 ;
V_28 = F_20 ( V_17 , V_25 ) ;
if ( ! V_28 )
return false ;
F_188 ( V_17 , V_28 + V_300 , & V_146 ) ;
return ( V_146 & V_301 ) ? true : false ;
}
static int F_196 ( struct V_14 * V_15 ,
struct V_1 * V_4 )
{
struct V_16 * V_17 = F_16 ( V_15 ) ;
struct V_5 * V_7 ;
unsigned long V_8 ;
int V_187 ;
V_7 = F_18 ( V_15 ) ;
if ( V_4 -> V_8 & V_281 ) {
if ( ! V_7 -> V_302 )
return - V_214 ;
if ( V_7 -> V_67 ) {
if ( F_190 ( V_17 ) != 0 )
return - V_214 ;
V_7 -> V_192 . V_193 = true ;
V_7 -> V_192 . V_170 = F_197 ( V_17 ) ;
V_7 -> V_303 = F_195 ( V_17 ) ;
}
} else if ( V_304 &&
F_194 ( V_17 , V_40 ) == 0 ) {
V_7 -> V_192 . V_193 = true ;
V_7 -> V_192 . V_170 = F_197 ( V_17 ) ;
}
F_153 ( & V_259 , V_8 ) ;
V_187 = F_180 ( V_7 , V_4 ) ;
F_155 ( & V_259 , V_8 ) ;
F_109 ( V_4 ) ;
return V_187 ;
}
static void F_198 ( struct V_5 * V_7 )
{
struct V_5 * V_123 , * V_142 ;
struct V_1 * V_4 ;
unsigned long V_8 ;
F_117 ( ! V_7 -> V_4 ) ;
V_4 = V_7 -> V_4 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
V_123 = V_7 ;
if ( V_123 -> V_64 != NULL )
V_123 = V_123 -> V_64 ;
F_13 (entry, &head->alias_list, alias_list)
F_179 ( V_142 ) ;
F_179 ( V_123 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
}
static void F_199 ( struct V_14 * V_15 )
{
struct V_1 * V_4 ;
struct V_5 * V_7 ;
unsigned long V_8 ;
V_7 = F_18 ( V_15 ) ;
V_4 = V_7 -> V_4 ;
F_153 ( & V_259 , V_8 ) ;
F_198 ( V_7 ) ;
F_155 ( & V_259 , V_8 ) ;
if ( V_4 -> V_8 & V_281 && V_7 -> V_67 )
F_183 ( F_16 ( V_15 ) ) ;
else if ( V_7 -> V_192 . V_193 )
F_184 ( F_16 ( V_15 ) ) ;
V_7 -> V_192 . V_193 = false ;
}
static int F_200 ( struct V_14 * V_15 )
{
struct V_5 * V_7 ;
struct V_2 * V_4 ;
struct V_66 * V_22 ;
T_1 V_6 ;
int V_187 ;
if ( ! F_25 ( V_15 ) || F_18 ( V_15 ) )
return 0 ;
V_6 = F_15 ( V_15 ) ;
V_22 = V_47 [ V_6 ] ;
V_187 = F_40 ( V_15 ) ;
if ( V_187 ) {
if ( V_187 != - V_65 )
F_41 ( L_29 ,
F_39 ( V_15 ) ) ;
F_44 ( V_15 ) ;
V_15 -> V_21 . V_71 = & V_305 ;
goto V_51;
}
F_27 ( V_15 ) ;
V_7 = F_18 ( V_15 ) ;
F_117 ( ! V_7 ) ;
if ( V_306 || V_7 -> V_67 )
F_201 ( V_15 ) ;
V_4 = F_202 ( V_15 ) ;
if ( V_4 -> type == V_307 )
V_7 -> V_302 = true ;
else
V_15 -> V_21 . V_71 = & V_308 ;
V_51:
F_95 ( V_22 ) ;
return 0 ;
}
static void F_203 ( struct V_14 * V_15 )
{
struct V_66 * V_22 ;
T_1 V_6 ;
if ( ! F_25 ( V_15 ) )
return;
V_6 = F_15 ( V_15 ) ;
V_22 = V_47 [ V_6 ] ;
F_45 ( V_15 ) ;
F_95 ( V_22 ) ;
}
static struct V_1 * F_204 ( struct V_14 * V_15 )
{
struct V_1 * V_4 ;
struct V_2 * V_309 ;
if ( ! F_25 ( V_15 ) )
return F_205 ( - V_214 ) ;
V_309 = F_202 ( V_15 ) ;
if ( ! V_309 )
return NULL ;
V_4 = F_1 ( V_309 ) ;
if ( ! V_31 ( V_4 ) )
return F_205 ( - V_215 ) ;
return V_4 ;
}
static void F_206 ( struct V_1 * V_4 )
{
struct V_5 * V_7 ;
F_13 (dev_data, &domain->dev_list, list)
F_172 ( V_7 -> V_6 , V_4 , V_7 -> V_192 . V_193 ) ;
}
static void F_134 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_203 )
return;
F_206 ( V_4 ) ;
F_111 ( V_4 ) ;
F_109 ( V_4 ) ;
V_4 -> V_203 = false ;
}
static T_3 * F_207 ( struct V_31 * V_3 ,
unsigned long V_103 )
{
struct V_233 * V_41 ;
T_3 * V_199 , * V_205 ;
V_41 = V_3 -> V_41 [ F_208 ( V_103 ) ] ;
if ( ! V_41 )
return NULL ;
V_199 = V_41 -> V_237 [ F_209 ( V_103 ) ] ;
if ( ! V_199 ) {
V_199 = F_116 ( & V_3 -> V_4 , V_103 , V_38 , & V_205 ,
V_310 ) ;
V_41 -> V_237 [ F_209 ( V_103 ) ] = V_205 ;
} else
V_199 += F_120 ( 0 , V_103 ) ;
F_134 ( & V_3 -> V_4 ) ;
return V_199 ;
}
static T_8 F_210 ( struct V_31 * V_3 ,
unsigned long V_103 ,
T_9 V_311 ,
int V_312 )
{
T_3 * V_199 , V_212 ;
F_79 ( V_103 > V_3 -> V_39 ) ;
V_311 &= V_166 ;
V_199 = F_207 ( V_3 , V_103 ) ;
if ( ! V_199 )
return V_254 ;
V_212 = V_311 | V_216 | V_217 ;
if ( V_312 == V_313 )
V_212 |= V_219 ;
else if ( V_312 == V_314 )
V_212 |= V_221 ;
else if ( V_312 == V_315 )
V_212 |= V_219 | V_221 ;
F_79 ( * V_199 ) ;
* V_199 = V_212 ;
return ( T_8 ) V_103 ;
}
static void F_211 ( struct V_31 * V_3 ,
unsigned long V_103 )
{
struct V_233 * V_41 ;
T_3 * V_199 ;
if ( V_103 >= V_3 -> V_39 )
return;
V_41 = V_3 -> V_41 [ F_208 ( V_103 ) ] ;
if ( ! V_41 )
return;
V_199 = V_41 -> V_237 [ F_209 ( V_103 ) ] ;
if ( ! V_199 )
return;
V_199 += F_120 ( 0 , V_103 ) ;
F_79 ( ! * V_199 ) ;
* V_199 = 0ULL ;
}
static T_8 F_212 ( struct V_14 * V_15 ,
struct V_31 * V_32 ,
T_9 V_311 ,
T_6 V_161 ,
int V_316 ,
bool V_317 ,
T_3 V_45 )
{
T_8 V_235 = V_311 & ~ V_166 ;
T_8 V_103 , V_245 , V_187 ;
unsigned int V_163 ;
unsigned long V_244 = 0 ;
int V_27 ;
V_163 = F_86 ( V_311 , V_161 , V_38 ) ;
V_311 &= V_166 ;
F_63 ( V_91 ) ;
if ( V_163 > 1 )
F_63 ( V_87 ) ;
if ( V_317 )
V_244 = ( 1UL << F_213 ( V_161 ) ) - 1 ;
V_104:
V_103 = F_146 ( V_15 , V_32 , V_163 , V_244 ,
V_45 ) ;
if ( F_147 ( V_103 == V_254 ) ) {
V_32 -> V_247 = V_32 -> V_39 ;
if ( F_137 ( V_32 , false , V_310 ) )
goto V_51;
goto V_104;
}
V_245 = V_103 ;
for ( V_27 = 0 ; V_27 < V_163 ; ++ V_27 ) {
V_187 = F_210 ( V_32 , V_245 , V_311 , V_316 ) ;
if ( V_187 == V_254 )
goto V_318;
V_311 += V_38 ;
V_245 += V_38 ;
}
V_103 += V_235 ;
F_214 ( V_90 , V_161 ) ;
if ( F_147 ( V_32 -> V_253 && ! V_79 ) ) {
F_108 ( & V_32 -> V_4 ) ;
V_32 -> V_253 = false ;
} else if ( F_147 ( V_319 ) )
F_107 ( & V_32 -> V_4 , V_103 , V_161 ) ;
V_51:
return V_103 ;
V_318:
for ( -- V_27 ; V_27 >= 0 ; -- V_27 ) {
V_245 -= V_38 ;
F_211 ( V_32 , V_245 ) ;
}
F_148 ( V_32 , V_103 , V_163 ) ;
return V_254 ;
}
static void F_215 ( struct V_31 * V_32 ,
T_8 V_320 ,
T_6 V_161 ,
int V_316 )
{
T_8 V_321 ;
T_8 V_27 , V_245 ;
unsigned int V_163 ;
if ( ( V_320 == V_254 ) ||
( V_320 + V_161 > V_32 -> V_39 ) )
return;
V_321 = V_320 ;
V_163 = F_86 ( V_320 , V_161 , V_38 ) ;
V_320 &= V_166 ;
V_245 = V_320 ;
for ( V_27 = 0 ; V_27 < V_163 ; ++ V_27 ) {
F_211 ( V_32 , V_245 ) ;
V_245 += V_38 ;
}
F_216 ( V_90 , V_161 ) ;
F_148 ( V_32 , V_320 , V_163 ) ;
if ( V_79 || V_32 -> V_253 ) {
F_107 ( & V_32 -> V_4 , V_321 , V_161 ) ;
V_32 -> V_253 = false ;
}
}
static T_8 F_217 ( struct V_14 * V_15 , struct V_208 * V_208 ,
unsigned long V_235 , T_6 V_161 ,
enum V_322 V_316 ,
struct V_323 * V_324 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
T_8 V_35 ;
T_3 V_45 ;
T_9 V_311 = F_218 ( V_208 ) + V_235 ;
F_63 ( V_81 ) ;
V_4 = F_204 ( V_15 ) ;
if ( F_219 ( V_4 ) == - V_214 )
return ( T_8 ) V_311 ;
else if ( F_29 ( V_4 ) )
return V_254 ;
V_45 = * V_15 -> V_45 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
V_35 = F_212 ( V_15 , V_4 -> V_52 , V_311 , V_161 , V_316 , false ,
V_45 ) ;
if ( V_35 == V_254 )
goto V_51;
F_110 ( V_4 ) ;
V_51:
F_8 ( & V_4 -> V_184 , V_8 ) ;
return V_35 ;
}
static void F_220 ( struct V_14 * V_15 , T_8 V_320 , T_6 V_161 ,
enum V_322 V_316 , struct V_323 * V_324 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
F_63 ( V_82 ) ;
V_4 = F_204 ( V_15 ) ;
if ( F_29 ( V_4 ) )
return;
F_6 ( & V_4 -> V_184 , V_8 ) ;
F_215 ( V_4 -> V_52 , V_320 , V_161 , V_316 ) ;
F_110 ( V_4 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
}
static int F_221 ( struct V_14 * V_15 , struct V_325 * V_326 ,
int V_327 , enum V_322 V_316 ,
struct V_323 * V_324 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
int V_27 ;
struct V_325 * V_164 ;
T_9 V_311 ;
int V_328 = 0 ;
T_3 V_45 ;
F_63 ( V_83 ) ;
V_4 = F_204 ( V_15 ) ;
if ( F_29 ( V_4 ) )
return 0 ;
V_45 = * V_15 -> V_45 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
F_222 (sglist, s, nelems, i) {
V_311 = F_223 ( V_164 ) ;
V_164 -> V_329 = F_212 ( V_15 , V_4 -> V_52 ,
V_311 , V_164 -> V_330 , V_316 , false ,
V_45 ) ;
if ( V_164 -> V_329 ) {
V_164 -> V_331 = V_164 -> V_330 ;
V_328 ++ ;
} else
goto V_332;
}
F_110 ( V_4 ) ;
V_51:
F_8 ( & V_4 -> V_184 , V_8 ) ;
return V_328 ;
V_332:
F_222 (sglist, s, mapped_elems, i) {
if ( V_164 -> V_329 )
F_215 ( V_4 -> V_52 , V_164 -> V_329 ,
V_164 -> V_331 , V_316 ) ;
V_164 -> V_329 = V_164 -> V_331 = 0 ;
}
V_328 = 0 ;
goto V_51;
}
static void F_224 ( struct V_14 * V_15 , struct V_325 * V_326 ,
int V_327 , enum V_322 V_316 ,
struct V_323 * V_324 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
struct V_325 * V_164 ;
int V_27 ;
F_63 ( V_84 ) ;
V_4 = F_204 ( V_15 ) ;
if ( F_29 ( V_4 ) )
return;
F_6 ( & V_4 -> V_184 , V_8 ) ;
F_222 (sglist, s, nelems, i) {
F_215 ( V_4 -> V_52 , V_164 -> V_329 ,
V_164 -> V_331 , V_316 ) ;
V_164 -> V_329 = V_164 -> V_331 = 0 ;
}
F_110 ( V_4 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
}
static void * F_225 ( struct V_14 * V_15 , T_6 V_161 ,
T_8 * V_320 , T_7 V_333 ,
struct V_323 * V_324 )
{
T_3 V_45 = V_15 -> V_334 ;
struct V_1 * V_4 ;
unsigned long V_8 ;
struct V_208 * V_208 ;
F_63 ( V_85 ) ;
V_4 = F_204 ( V_15 ) ;
if ( F_219 ( V_4 ) == - V_214 ) {
V_208 = F_226 ( V_333 , F_213 ( V_161 ) ) ;
* V_320 = F_218 ( V_208 ) ;
return F_227 ( V_208 ) ;
} else if ( F_29 ( V_4 ) )
return NULL ;
V_161 = F_228 ( V_161 ) ;
V_45 = V_15 -> V_334 ;
V_333 &= ~ ( V_335 | V_336 | V_337 ) ;
V_333 |= V_338 ;
V_208 = F_226 ( V_333 | V_339 , F_213 ( V_161 ) ) ;
if ( ! V_208 ) {
if ( ! ( V_333 & V_340 ) )
return NULL ;
V_208 = F_229 ( V_15 , V_161 >> V_40 ,
F_213 ( V_161 ) ) ;
if ( ! V_208 )
return NULL ;
}
if ( ! V_45 )
V_45 = * V_15 -> V_45 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
* V_320 = F_212 ( V_15 , V_4 -> V_52 , F_218 ( V_208 ) ,
V_161 , V_315 , true , V_45 ) ;
if ( * V_320 == V_254 ) {
F_8 ( & V_4 -> V_184 , V_8 ) ;
goto V_234;
}
F_110 ( V_4 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
return F_227 ( V_208 ) ;
V_234:
if ( ! F_230 ( V_15 , V_208 , V_161 >> V_40 ) )
F_231 ( V_208 , F_213 ( V_161 ) ) ;
return NULL ;
}
static void F_232 ( struct V_14 * V_15 , T_6 V_161 ,
void * V_341 , T_8 V_320 ,
struct V_323 * V_324 )
{
struct V_1 * V_4 ;
unsigned long V_8 ;
struct V_208 * V_208 ;
F_63 ( V_86 ) ;
V_208 = F_233 ( V_341 ) ;
V_161 = F_228 ( V_161 ) ;
V_4 = F_204 ( V_15 ) ;
if ( F_29 ( V_4 ) )
goto V_342;
F_6 ( & V_4 -> V_184 , V_8 ) ;
F_215 ( V_4 -> V_52 , V_320 , V_161 , V_315 ) ;
F_110 ( V_4 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
V_342:
if ( ! F_230 ( V_15 , V_208 , V_161 >> V_40 ) )
F_231 ( V_208 , F_213 ( V_161 ) ) ;
}
static int F_234 ( struct V_14 * V_15 , T_3 V_250 )
{
return F_25 ( V_15 ) ;
}
int T_10 F_235 ( void )
{
return F_236 ( & V_343 , & V_344 ) ;
}
int T_10 F_237 ( void )
{
V_345 = V_306 ? 1 : 0 ;
V_346 = 1 ;
if ( ! V_345 )
V_71 = & V_305 ;
F_50 () ;
if ( V_79 )
F_35 ( L_30 ) ;
else
F_35 ( L_31 ) ;
return 0 ;
}
static void F_238 ( struct V_1 * V_4 )
{
struct V_5 * V_142 ;
unsigned long V_8 ;
F_153 ( & V_259 , V_8 ) ;
while ( ! F_239 ( & V_4 -> V_290 ) ) {
V_142 = F_240 ( & V_4 -> V_290 ,
struct V_5 , V_257 ) ;
F_198 ( V_142 ) ;
}
F_155 ( & V_259 , V_8 ) ;
}
static void F_241 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_151 ( V_4 ) ;
if ( V_4 -> V_194 )
F_156 ( V_4 -> V_194 ) ;
F_11 ( V_4 ) ;
}
static int F_171 ( struct V_1 * V_4 )
{
F_242 ( & V_4 -> V_184 ) ;
F_243 ( & V_4 -> V_347 ) ;
V_4 -> V_194 = F_152 () ;
if ( ! V_4 -> V_194 )
return - V_63 ;
F_5 ( & V_4 -> V_290 ) ;
return 0 ;
}
static struct V_1 * F_244 ( void )
{
struct V_1 * V_4 ;
V_4 = F_4 ( sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 )
return NULL ;
if ( F_171 ( V_4 ) )
goto V_299;
F_150 ( V_4 ) ;
return V_4 ;
V_299:
F_11 ( V_4 ) ;
return NULL ;
}
static struct V_2 * F_245 ( unsigned type )
{
struct V_1 * V_348 ;
struct V_31 * V_48 ;
switch ( type ) {
case V_349 :
V_348 = F_244 () ;
if ( ! V_348 )
return NULL ;
V_348 -> V_200 = V_266 ;
V_348 -> V_202 = ( void * ) F_113 ( V_9 ) ;
if ( ! V_348 -> V_202 ) {
F_241 ( V_348 ) ;
return NULL ;
}
V_348 -> V_4 . V_350 . V_351 = 0 ;
V_348 -> V_4 . V_350 . V_352 = ~ 0ULL ;
V_348 -> V_4 . V_350 . V_353 = true ;
break;
case V_354 :
V_48 = F_170 () ;
if ( ! V_48 ) {
F_41 ( L_32 ) ;
return NULL ;
}
V_348 = & V_48 -> V_4 ;
break;
case V_307 :
V_348 = F_244 () ;
if ( ! V_348 )
return NULL ;
V_348 -> V_200 = V_263 ;
break;
default:
return NULL ;
}
return & V_348 -> V_4 ;
}
static void F_246 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 )
return;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_291 > 0 )
F_238 ( V_4 ) ;
F_117 ( V_4 -> V_291 != 0 ) ;
if ( V_4 -> V_200 != V_263 )
F_158 ( V_4 ) ;
if ( V_4 -> V_8 & V_281 )
F_168 ( V_4 ) ;
F_241 ( V_4 ) ;
}
static void F_247 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_5 * V_7 = V_15 -> V_21 . V_22 ;
struct V_66 * V_22 ;
T_1 V_6 ;
if ( ! F_25 ( V_15 ) )
return;
V_6 = F_15 ( V_15 ) ;
if ( V_7 -> V_4 != NULL )
F_199 ( V_15 ) ;
V_22 = V_47 [ V_6 ] ;
if ( ! V_22 )
return;
F_95 ( V_22 ) ;
}
static int F_248 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_7 ;
struct V_66 * V_22 ;
int V_187 ;
if ( ! F_25 ( V_15 ) )
return - V_214 ;
V_7 = V_15 -> V_21 . V_22 ;
V_22 = V_47 [ V_7 -> V_6 ] ;
if ( ! V_22 )
return - V_214 ;
if ( V_7 -> V_4 )
F_199 ( V_15 ) ;
V_187 = F_196 ( V_15 , V_4 ) ;
F_95 ( V_22 ) ;
return V_187 ;
}
static int F_249 ( struct V_2 * V_3 , unsigned long V_355 ,
T_9 V_311 , T_6 V_204 , int V_356 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_211 = 0 ;
int V_187 ;
if ( V_4 -> V_200 == V_263 )
return - V_214 ;
if ( V_356 & V_357 )
V_211 |= V_218 ;
if ( V_356 & V_358 )
V_211 |= V_220 ;
F_250 ( & V_4 -> V_347 ) ;
V_187 = F_130 ( V_4 , V_355 , V_311 , V_211 , V_204 ) ;
F_251 ( & V_4 -> V_347 ) ;
return V_187 ;
}
static T_6 F_252 ( struct V_2 * V_3 , unsigned long V_355 ,
T_6 V_204 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_6 V_223 ;
if ( V_4 -> V_200 == V_263 )
return - V_214 ;
F_250 ( & V_4 -> V_347 ) ;
V_223 = F_135 ( V_4 , V_355 , V_204 ) ;
F_251 ( & V_4 -> V_347 ) ;
F_109 ( V_4 ) ;
return V_223 ;
}
static T_9 F_253 ( struct V_2 * V_3 ,
T_8 V_355 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_359 , V_231 ;
T_3 * V_199 , V_212 ;
if ( V_4 -> V_200 == V_263 )
return V_355 ;
V_199 = F_126 ( V_4 , V_355 , & V_231 ) ;
if ( ! V_199 || ! F_123 ( * V_199 ) )
return 0 ;
V_359 = V_231 - 1 ;
V_212 = * V_199 & V_360 ;
return ( V_212 & ~ V_359 ) | ( V_355 & V_359 ) ;
}
static bool F_254 ( enum V_361 V_362 )
{
switch ( V_362 ) {
case V_363 :
return true ;
case V_364 :
return ( V_365 == 1 ) ;
case V_366 :
return false ;
}
return false ;
}
static void F_255 ( struct V_14 * V_15 ,
struct V_367 * V_123 )
{
struct V_33 * V_142 ;
T_1 V_6 ;
V_6 = F_15 ( V_15 ) ;
F_13 (entry, &amd_iommu_unity_map, list) {
struct V_368 * V_369 ;
if ( V_6 < V_142 -> V_43 || V_6 > V_142 -> V_44 )
continue;
V_369 = F_4 ( sizeof( * V_369 ) , V_9 ) ;
if ( ! V_369 ) {
F_41 ( L_33 ,
F_39 ( V_15 ) ) ;
return;
}
V_369 -> V_245 = V_142 -> V_36 ;
V_369 -> V_330 = V_142 -> V_37 - V_142 -> V_36 ;
if ( V_142 -> V_211 & V_218 )
V_369 -> V_211 |= V_357 ;
if ( V_142 -> V_211 & V_220 )
V_369 -> V_211 |= V_358 ;
F_7 ( & V_369 -> V_257 , V_123 ) ;
}
}
static void F_256 ( struct V_14 * V_15 ,
struct V_367 * V_123 )
{
struct V_368 * V_142 , * V_370 ;
F_257 (entry, next, head, list)
F_11 ( V_142 ) ;
}
int F_258 ( struct V_371 * V_372 )
{
return F_259 ( & V_138 , V_372 ) ;
}
int F_260 ( struct V_371 * V_372 )
{
return F_261 ( & V_138 , V_372 ) ;
}
void F_262 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
V_4 -> V_200 = V_263 ;
V_4 -> V_203 = true ;
F_134 ( V_4 ) ;
F_158 ( V_4 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
}
int F_263 ( struct V_2 * V_3 , int V_373 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_374 , V_187 ;
if ( V_373 <= 0 || V_373 > ( V_375 + 1 ) )
return - V_214 ;
for ( V_374 = 0 ; ( V_373 - 1 ) & ~ 0x1ff ; V_373 >>= 9 )
V_374 += 1 ;
if ( V_374 > V_376 )
return - V_214 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
V_187 = - V_215 ;
if ( V_4 -> V_291 > 0 || V_4 -> V_8 & V_281 )
goto V_51;
V_187 = - V_63 ;
V_4 -> V_273 = ( void * ) F_113 ( V_310 ) ;
if ( V_4 -> V_273 == NULL )
goto V_51;
V_4 -> V_272 = V_374 ;
V_4 -> V_8 |= V_281 ;
V_4 -> V_203 = true ;
F_134 ( V_4 ) ;
V_187 = 0 ;
V_51:
F_8 ( & V_4 -> V_184 , V_8 ) ;
return V_187 ;
}
static int F_264 ( struct V_1 * V_4 , int V_135 ,
T_3 V_103 , bool V_161 )
{
struct V_5 * V_7 ;
struct V_97 V_98 ;
int V_27 , V_187 ;
if ( ! ( V_4 -> V_8 & V_281 ) )
return - V_214 ;
F_88 ( & V_98 , V_4 -> V_194 , V_135 , V_103 , V_161 ) ;
for ( V_27 = 0 ; V_27 < V_195 ; ++ V_27 ) {
if ( V_4 -> V_196 [ V_27 ] == 0 )
continue;
V_187 = F_94 ( V_197 [ V_27 ] , & V_98 ) ;
if ( V_187 != 0 )
goto V_51;
}
F_110 ( V_4 ) ;
F_13 (dev_data, &domain->dev_list, list) {
struct V_66 * V_22 ;
int V_170 ;
if ( ! V_7 -> V_192 . V_193 )
continue;
V_170 = V_7 -> V_192 . V_170 ;
V_22 = V_47 [ V_7 -> V_6 ] ;
F_89 ( & V_98 , V_7 -> V_6 , V_135 ,
V_170 , V_103 , V_161 ) ;
V_187 = F_94 ( V_22 , & V_98 ) ;
if ( V_187 != 0 )
goto V_51;
}
F_110 ( V_4 ) ;
V_187 = 0 ;
V_51:
return V_187 ;
}
static int F_265 ( struct V_1 * V_4 , int V_135 ,
T_3 V_103 )
{
F_63 ( V_93 ) ;
return F_264 ( V_4 , V_135 , V_103 , false ) ;
}
int F_266 ( struct V_2 * V_3 , int V_135 ,
T_3 V_103 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_187 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
V_187 = F_265 ( V_4 , V_135 , V_103 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
return V_187 ;
}
static int F_267 ( struct V_1 * V_4 , int V_135 )
{
F_63 ( V_94 ) ;
return F_264 ( V_4 , V_135 , V_165 ,
true ) ;
}
int F_268 ( struct V_2 * V_3 , int V_135 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_187 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
V_187 = F_267 ( V_4 , V_135 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
return V_187 ;
}
static T_3 * F_269 ( T_3 * V_262 , int V_206 , int V_135 , bool V_377 )
{
int V_226 ;
T_3 * V_199 ;
while ( true ) {
V_226 = ( V_135 >> ( 9 * V_206 ) ) & 0x1ff ;
V_199 = & V_262 [ V_226 ] ;
if ( V_206 == 0 )
break;
if ( ! ( * V_199 & V_271 ) ) {
if ( ! V_377 )
return NULL ;
V_262 = ( void * ) F_113 ( V_310 ) ;
if ( V_262 == NULL )
return NULL ;
* V_199 = F_81 ( V_262 ) | V_271 ;
}
V_262 = F_166 ( * V_199 & V_166 ) ;
V_206 -= 1 ;
}
return V_199 ;
}
static int F_270 ( struct V_1 * V_4 , int V_135 ,
unsigned long V_378 )
{
T_3 * V_199 ;
if ( V_4 -> V_200 != V_263 )
return - V_214 ;
V_199 = F_269 ( V_4 -> V_273 , V_4 -> V_272 , V_135 , true ) ;
if ( V_199 == NULL )
return - V_63 ;
* V_199 = ( V_378 & V_166 ) | V_271 ;
return F_267 ( V_4 , V_135 ) ;
}
static int F_271 ( struct V_1 * V_4 , int V_135 )
{
T_3 * V_199 ;
if ( V_4 -> V_200 != V_263 )
return - V_214 ;
V_199 = F_269 ( V_4 -> V_273 , V_4 -> V_272 , V_135 , false ) ;
if ( V_199 == NULL )
return 0 ;
* V_199 = 0 ;
return F_267 ( V_4 , V_135 ) ;
}
int F_272 ( struct V_2 * V_3 , int V_135 ,
unsigned long V_378 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_187 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
V_187 = F_270 ( V_4 , V_135 , V_378 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
return V_187 ;
}
int F_273 ( struct V_2 * V_3 , int V_135 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_187 ;
F_6 ( & V_4 -> V_184 , V_8 ) ;
V_187 = F_271 ( V_4 , V_135 ) ;
F_8 ( & V_4 -> V_184 , V_8 ) ;
return V_187 ;
}
int F_274 ( struct V_16 * V_17 , int V_135 ,
int V_146 , int V_137 )
{
struct V_5 * V_7 ;
struct V_66 * V_22 ;
struct V_97 V_98 ;
F_63 ( V_92 ) ;
V_7 = F_18 ( & V_17 -> V_15 ) ;
V_22 = V_47 [ V_7 -> V_6 ] ;
F_90 ( & V_98 , V_7 -> V_6 , V_135 , V_146 ,
V_137 , V_7 -> V_303 ) ;
return F_94 ( V_22 , & V_98 ) ;
}
struct V_2 * F_275 ( struct V_16 * V_17 )
{
struct V_1 * V_348 ;
V_348 = F_204 ( & V_17 -> V_15 ) ;
if ( F_29 ( V_348 ) )
return NULL ;
if ( ! ( V_348 -> V_8 & V_281 ) )
return NULL ;
return & V_348 -> V_4 ;
}
void F_276 ( struct V_16 * V_17 , T_2 V_29 )
{
struct V_5 * V_7 ;
if ( ! F_277 () )
return;
V_7 = F_18 ( & V_17 -> V_15 ) ;
V_7 -> V_30 |= ( 1 << V_29 ) ;
}
int F_278 ( struct V_16 * V_17 ,
struct F_278 * V_379 )
{
int V_380 ;
int V_28 ;
if ( V_17 == NULL || V_379 == NULL )
return - V_214 ;
if ( ! F_277 () )
return - V_214 ;
memset ( V_379 , 0 , sizeof( * V_379 ) ) ;
V_28 = F_20 ( V_17 , V_24 ) ;
if ( V_28 )
V_379 -> V_8 |= V_381 ;
V_28 = F_20 ( V_17 , V_25 ) ;
if ( V_28 )
V_379 -> V_8 |= V_382 ;
V_28 = F_20 ( V_17 , V_26 ) ;
if ( V_28 ) {
int V_383 ;
V_380 = 1 << ( 9 * ( V_376 + 1 ) ) ;
V_380 = F_279 ( V_380 , ( 1 << 20 ) ) ;
V_379 -> V_8 |= V_384 ;
V_379 -> V_380 = F_279 ( F_280 ( V_17 ) , V_380 ) ;
V_383 = F_281 ( V_17 ) ;
if ( V_383 & V_385 )
V_379 -> V_8 |= V_386 ;
if ( V_383 & V_387 )
V_379 -> V_8 |= V_388 ;
}
return 0 ;
}
static void F_282 ( T_1 V_6 , struct V_389 * V_390 )
{
T_3 V_391 ;
V_391 = V_58 [ V_6 ] . V_54 [ 2 ] ;
V_391 &= ~ V_392 ;
V_391 |= F_115 ( V_390 -> V_390 ) ;
V_391 |= V_393 ;
V_391 |= V_394 ;
V_391 |= V_395 ;
V_58 [ V_6 ] . V_54 [ 2 ] = V_391 ;
}
static struct V_389 * F_283 ( T_1 V_6 , bool V_396 )
{
struct V_389 * V_390 = NULL ;
struct V_66 * V_22 ;
unsigned long V_8 ;
T_1 V_53 ;
F_153 ( & V_259 , V_8 ) ;
V_22 = V_47 [ V_6 ] ;
if ( ! V_22 )
goto V_13;
V_390 = V_397 [ V_6 ] ;
if ( V_390 )
goto V_51;
V_53 = V_57 [ V_6 ] ;
V_390 = V_397 [ V_53 ] ;
if ( V_390 ) {
V_397 [ V_6 ] = V_390 ;
F_282 ( V_6 , V_390 ) ;
F_96 ( V_22 , V_6 ) ;
goto V_51;
}
V_390 = F_4 ( sizeof( * V_390 ) , V_310 ) ;
if ( ! V_390 )
goto V_51;
F_242 ( & V_390 -> V_184 ) ;
if ( V_396 )
V_390 -> V_398 = 32 ;
V_390 -> V_390 = F_284 ( V_399 , V_310 ) ;
if ( ! V_390 -> V_390 ) {
F_11 ( V_390 ) ;
V_390 = NULL ;
goto V_51;
}
memset ( V_390 -> V_390 , 0 , V_400 * sizeof( T_2 ) ) ;
if ( V_396 ) {
int V_27 ;
for ( V_27 = 0 ; V_27 < 32 ; ++ V_27 )
V_390 -> V_390 [ V_27 ] = V_401 ;
}
V_397 [ V_6 ] = V_390 ;
F_282 ( V_6 , V_390 ) ;
F_96 ( V_22 , V_6 ) ;
if ( V_6 != V_53 ) {
V_397 [ V_53 ] = V_390 ;
F_282 ( V_53 , V_390 ) ;
F_96 ( V_22 , V_53 ) ;
}
V_51:
F_95 ( V_22 ) ;
V_13:
F_155 ( & V_259 , V_8 ) ;
return V_390 ;
}
static int F_285 ( T_1 V_6 , int V_102 )
{
struct V_389 * V_390 ;
unsigned long V_8 ;
int V_226 , V_402 ;
V_390 = F_283 ( V_6 , false ) ;
if ( ! V_390 )
return - V_403 ;
F_6 ( & V_390 -> V_184 , V_8 ) ;
for ( V_402 = 0 , V_226 = V_390 -> V_398 ;
V_226 < V_400 ;
++ V_226 ) {
if ( V_390 -> V_390 [ V_226 ] == 0 )
V_402 += 1 ;
else
V_402 = 0 ;
if ( V_402 == V_102 ) {
for (; V_402 != 0 ; -- V_402 )
V_390 -> V_390 [ V_226 - V_402 + 1 ] = V_401 ;
V_226 -= V_102 - 1 ;
goto V_51;
}
}
V_226 = - V_404 ;
V_51:
F_8 ( & V_390 -> V_184 , V_8 ) ;
return V_226 ;
}
static int F_286 ( T_1 V_6 , int V_226 , union V_405 V_405 )
{
struct V_389 * V_390 ;
struct V_66 * V_22 ;
unsigned long V_8 ;
V_22 = V_47 [ V_6 ] ;
if ( V_22 == NULL )
return - V_214 ;
V_390 = F_283 ( V_6 , false ) ;
if ( ! V_390 )
return - V_63 ;
F_6 ( & V_390 -> V_184 , V_8 ) ;
V_390 -> V_390 [ V_226 ] = V_405 . V_406 ;
F_8 ( & V_390 -> V_184 , V_8 ) ;
F_100 ( V_22 , V_6 ) ;
F_95 ( V_22 ) ;
return 0 ;
}
static void F_287 ( T_1 V_6 , int V_226 )
{
struct V_389 * V_390 ;
struct V_66 * V_22 ;
unsigned long V_8 ;
V_22 = V_47 [ V_6 ] ;
if ( V_22 == NULL )
return;
V_390 = F_283 ( V_6 , false ) ;
if ( ! V_390 )
return;
F_6 ( & V_390 -> V_184 , V_8 ) ;
V_390 -> V_390 [ V_226 ] = 0 ;
F_8 ( & V_390 -> V_184 , V_8 ) ;
F_100 ( V_22 , V_6 ) ;
F_95 ( V_22 ) ;
}
static int F_288 ( struct V_407 * V_379 )
{
int V_6 = - 1 ;
switch ( V_379 -> type ) {
case V_408 :
V_6 = F_289 ( V_379 -> V_409 ) ;
break;
case V_410 :
V_6 = F_290 ( V_379 -> V_411 ) ;
break;
case V_412 :
case V_413 :
V_6 = F_15 ( & V_379 -> V_414 -> V_15 ) ;
break;
default:
F_117 ( 1 ) ;
break;
}
return V_6 ;
}
static struct V_415 * F_291 ( struct V_407 * V_379 )
{
struct V_66 * V_22 ;
int V_6 ;
if ( ! V_379 )
return NULL ;
V_6 = F_288 ( V_379 ) ;
if ( V_6 >= 0 ) {
V_22 = V_47 [ V_6 ] ;
if ( V_22 )
return V_22 -> V_416 ;
}
return NULL ;
}
static struct V_415 * F_292 ( struct V_407 * V_379 )
{
struct V_66 * V_22 ;
int V_6 ;
if ( ! V_379 )
return NULL ;
switch ( V_379 -> type ) {
case V_412 :
case V_413 :
V_6 = F_15 ( & V_379 -> V_414 -> V_15 ) ;
if ( V_6 >= 0 ) {
V_22 = V_47 [ V_6 ] ;
if ( V_22 )
return V_22 -> V_417 ;
}
break;
default:
break;
}
return NULL ;
}
static void F_293 ( struct V_418 * V_54 ,
struct V_419 * V_419 ,
struct V_407 * V_379 ,
int V_6 , int V_226 , int V_420 )
{
struct V_421 * V_422 = & V_54 -> V_421 ;
struct V_423 * V_424 = & V_54 -> V_425 ;
union V_405 * V_405 = & V_54 -> V_426 ;
struct V_427 * V_142 ;
V_54 -> V_421 . V_6 = V_6 ;
V_54 -> V_421 . V_226 = V_226 + V_420 ;
V_405 -> V_406 = 0 ;
V_405 -> V_428 . V_429 = V_419 -> V_429 ;
V_405 -> V_428 . V_430 = V_431 -> V_432 ;
V_405 -> V_428 . V_433 = V_419 -> V_434 ;
V_405 -> V_428 . V_435 = V_431 -> V_436 ;
V_405 -> V_428 . V_437 = 1 ;
switch ( V_379 -> type ) {
case V_408 :
V_142 = V_379 -> V_438 ;
V_379 -> V_438 = NULL ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_429 = V_226 ;
V_142 -> V_250 = 0 ;
V_142 -> V_439 = V_379 -> V_440 ;
V_142 -> V_441 = V_379 -> V_442 ;
if ( V_379 -> V_440 )
V_142 -> V_250 = 1 ;
break;
case V_410 :
case V_412 :
case V_413 :
V_424 -> V_443 = V_444 ;
V_424 -> V_445 = V_239 ;
V_424 -> V_54 = V_422 -> V_226 ;
break;
default:
F_117 ( 1 ) ;
break;
}
}
static int F_294 ( struct V_415 * V_4 , unsigned int V_446 ,
unsigned int V_447 , void * V_448 )
{
struct V_407 * V_379 = V_448 ;
struct V_449 * V_449 ;
struct V_418 * V_54 ;
struct V_419 * V_450 ;
int V_27 , V_187 , V_6 ;
int V_226 = - 1 ;
if ( ! V_379 )
return - V_214 ;
if ( V_447 > 1 && V_379 -> type != V_412 &&
V_379 -> type != V_413 )
return - V_214 ;
if ( V_379 -> type == V_412 )
V_379 -> V_8 &= ~ V_451 ;
V_6 = F_288 ( V_379 ) ;
if ( V_6 < 0 )
return - V_214 ;
V_187 = F_295 ( V_4 , V_446 , V_447 , V_448 ) ;
if ( V_187 < 0 )
return V_187 ;
V_187 = - V_63 ;
V_54 = F_4 ( sizeof( * V_54 ) , V_9 ) ;
if ( ! V_54 )
goto V_452;
if ( V_379 -> type == V_408 ) {
if ( F_283 ( V_6 , true ) )
V_226 = V_379 -> V_453 ;
else
V_187 = - V_63 ;
} else {
V_226 = F_285 ( V_6 , V_447 ) ;
}
if ( V_226 < 0 ) {
F_296 ( L_34 ) ;
F_11 ( V_54 ) ;
goto V_452;
}
for ( V_27 = 0 ; V_27 < V_447 ; V_27 ++ ) {
V_449 = F_297 ( V_4 , V_446 + V_27 ) ;
V_450 = F_298 ( V_449 ) ;
if ( ! V_449 || ! V_450 ) {
V_187 = - V_214 ;
goto V_454;
}
if ( V_27 > 0 ) {
V_54 = F_4 ( sizeof( * V_54 ) , V_9 ) ;
if ( ! V_54 )
goto V_454;
}
V_449 -> V_455 = ( V_6 << 16 ) + V_27 ;
V_449 -> V_456 = V_54 ;
V_449 -> V_457 = & V_458 ;
F_293 ( V_54 , V_450 , V_379 , V_6 , V_226 , V_27 ) ;
F_299 ( V_446 + V_27 , V_459 ) ;
}
return 0 ;
V_454:
for ( V_27 -- ; V_27 >= 0 ; V_27 -- ) {
V_449 = F_297 ( V_4 , V_446 + V_27 ) ;
if ( V_449 )
F_11 ( V_449 -> V_456 ) ;
}
for ( V_27 = 0 ; V_27 < V_447 ; V_27 ++ )
F_287 ( V_6 , V_226 + V_27 ) ;
V_452:
F_300 ( V_4 , V_446 , V_447 ) ;
return V_187 ;
}
static void F_301 ( struct V_415 * V_4 , unsigned int V_446 ,
unsigned int V_447 )
{
struct V_421 * V_422 ;
struct V_449 * V_449 ;
struct V_418 * V_54 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_447 ; V_27 ++ ) {
V_449 = F_297 ( V_4 , V_446 + V_27 ) ;
if ( V_449 && V_449 -> V_456 ) {
V_54 = V_449 -> V_456 ;
V_422 = & V_54 -> V_421 ;
F_287 ( V_422 -> V_6 , V_422 -> V_226 ) ;
F_11 ( V_54 ) ;
}
}
F_300 ( V_4 , V_446 , V_447 ) ;
}
static void F_302 ( struct V_415 * V_4 ,
struct V_449 * V_449 )
{
struct V_418 * V_54 = V_449 -> V_456 ;
struct V_421 * V_422 = & V_54 -> V_421 ;
F_286 ( V_422 -> V_6 , V_422 -> V_226 , V_54 -> V_426 ) ;
}
static void F_303 ( struct V_415 * V_4 ,
struct V_449 * V_449 )
{
struct V_418 * V_54 = V_449 -> V_456 ;
struct V_421 * V_422 = & V_54 -> V_421 ;
union V_405 V_142 ;
V_142 . V_406 = 0 ;
F_286 ( V_422 -> V_6 , V_422 -> V_226 , V_54 -> V_426 ) ;
}
static int F_304 ( struct V_449 * V_54 ,
const struct V_460 * V_250 , bool V_461 )
{
struct V_418 * V_462 = V_54 -> V_456 ;
struct V_421 * V_422 = & V_462 -> V_421 ;
struct V_419 * V_450 = F_298 ( V_54 ) ;
struct V_449 * V_463 = V_54 -> V_464 ;
int V_187 ;
V_187 = V_463 -> V_457 -> V_465 ( V_463 , V_250 , V_461 ) ;
if ( V_187 < 0 || V_187 == V_466 )
return V_187 ;
V_462 -> V_426 . V_428 . V_429 = V_450 -> V_429 ;
V_462 -> V_426 . V_428 . V_433 = V_450 -> V_434 ;
F_286 ( V_422 -> V_6 , V_422 -> V_226 , V_462 -> V_426 ) ;
F_305 ( V_450 ) ;
return V_466 ;
}
static void F_306 ( struct V_449 * V_449 , struct V_423 * V_424 )
{
struct V_418 * V_462 = V_449 -> V_456 ;
* V_424 = V_462 -> V_425 ;
}
int F_307 ( struct V_66 * V_22 )
{
V_22 -> V_416 = F_308 ( NULL , & V_467 , V_22 ) ;
if ( ! V_22 -> V_416 )
return - V_63 ;
V_22 -> V_416 -> V_463 = F_309 () ;
V_22 -> V_417 = F_310 ( V_22 -> V_416 ) ;
return 0 ;
}
