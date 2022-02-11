static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline T_1 F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
return F_5 ( V_8 -> V_9 -> V_10 , V_8 -> V_11 ) ;
}
static struct V_12 * F_6 ( T_1 V_13 )
{
struct V_12 * V_14 ;
unsigned long V_15 ;
V_14 = F_7 ( sizeof( * V_14 ) , V_16 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_13 = V_13 ;
F_8 ( & V_17 , V_15 ) ;
F_9 ( & V_14 -> V_18 , & V_18 ) ;
F_10 ( & V_17 , V_15 ) ;
return V_14 ;
}
static struct V_12 * F_11 ( T_1 V_13 )
{
struct V_12 * V_14 ;
unsigned long V_15 ;
F_8 ( & V_17 , V_15 ) ;
F_12 (dev_data, &dev_data_list, dev_data_list) {
if ( V_14 -> V_13 == V_13 )
goto V_19;
}
V_14 = NULL ;
V_19:
F_10 ( & V_17 , V_15 ) ;
return V_14 ;
}
static int F_13 ( struct V_7 * V_8 , T_1 V_20 , void * V_21 )
{
* ( T_1 * ) V_21 = V_20 ;
return 0 ;
}
static T_1 F_14 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
T_1 V_13 , V_22 , V_23 ;
V_13 = F_3 ( V_6 ) ;
V_22 = V_24 [ V_13 ] ;
F_15 ( V_8 , F_13 , & V_23 ) ;
if ( V_22 == V_23 )
return V_22 ;
if ( V_22 == V_13 ) {
if ( ! V_25 [ V_23 ] ) {
V_25 [ V_23 ] =
V_25 [ V_13 ] ;
memcpy ( V_26 [ V_23 ] . V_21 ,
V_26 [ V_13 ] . V_21 ,
sizeof( V_26 [ V_23 ] . V_21 ) ) ;
}
return V_23 ;
}
F_16 ( L_1
L_2
L_3 , F_17 ( V_22 ) , F_18 ( V_22 ) ,
F_19 ( V_22 ) , F_20 ( V_6 ) , V_8 -> V_27 , V_8 -> V_5 ,
F_17 ( V_23 ) , F_18 ( V_23 ) ,
F_19 ( V_23 ) ) ;
if ( V_23 == V_13 &&
F_17 ( V_22 ) == V_8 -> V_9 -> V_10 ) {
V_8 -> V_28 |= V_29 ;
V_8 -> V_30 = V_22 & 0xff ;
F_16 ( L_4 ,
F_18 ( V_22 ) , F_19 ( V_22 ) ,
F_20 ( V_6 ) ) ;
}
return V_22 ;
}
static struct V_12 * F_21 ( T_1 V_13 )
{
struct V_12 * V_14 ;
V_14 = F_11 ( V_13 ) ;
if ( V_14 == NULL )
V_14 = F_6 ( V_13 ) ;
return V_14 ;
}
static struct V_12 * F_22 ( struct V_5 * V_6 )
{
return V_6 -> V_31 . V_32 ;
}
static bool F_23 ( struct V_7 * V_8 )
{
static const int V_33 [] = {
V_34 ,
V_35 ,
V_36 ,
} ;
int V_37 , V_38 ;
for ( V_37 = 0 ; V_37 < 3 ; ++ V_37 ) {
V_38 = F_24 ( V_8 , V_33 [ V_37 ] ) ;
if ( V_38 == 0 )
return false ;
}
return true ;
}
static bool F_25 ( struct V_7 * V_8 , T_2 V_39 )
{
struct V_12 * V_14 ;
V_14 = F_22 ( & V_8 -> V_6 ) ;
return V_14 -> V_40 & ( 1 << V_39 ) ? true : false ;
}
static void F_26 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
T_3 V_45 ;
for ( V_45 = V_44 -> V_46 ; V_45 < V_44 -> V_47 ;
V_45 += V_48 ) {
if ( V_45 < V_42 -> V_49 )
F_27 ( V_45 >> V_50 ,
V_42 -> V_51 [ 0 ] -> V_52 ) ;
}
}
static void F_28 ( struct V_5 * V_6 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 ;
T_1 V_13 ;
V_13 = F_3 ( V_6 ) ;
F_12 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_13 >= V_44 -> V_53 && V_13 <= V_44 -> V_54 ) )
continue;
F_26 ( V_42 , V_44 ) ;
}
}
static bool F_29 ( struct V_5 * V_6 )
{
T_1 V_13 ;
if ( ! V_6 || ! V_6 -> V_55 )
return false ;
if ( ! F_30 ( V_6 ) )
return false ;
V_13 = F_3 ( V_6 ) ;
if ( V_13 > V_56 )
return false ;
if ( V_25 [ V_13 ] == NULL )
return false ;
return true ;
}
static void F_31 ( struct V_5 * V_6 )
{
struct V_41 * V_57 ;
struct V_2 * V_4 ;
struct V_58 * V_59 ;
V_59 = F_32 ( V_6 ) ;
if ( F_33 ( V_59 ) )
return;
V_4 = F_34 ( V_59 ) ;
if ( ! V_4 )
goto V_60;
V_57 = F_1 ( V_4 ) -> V_61 ;
F_28 ( V_6 , V_57 ) ;
V_60:
F_35 ( V_59 ) ;
}
static int F_36 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_12 * V_14 ;
if ( V_6 -> V_31 . V_32 )
return 0 ;
V_14 = F_21 ( F_3 ( V_6 ) ) ;
if ( ! V_14 )
return - V_62 ;
V_14 -> V_20 = F_14 ( V_6 ) ;
if ( F_23 ( V_8 ) ) {
struct V_63 * V_32 ;
V_32 = V_25 [ V_14 -> V_13 ] ;
V_14 -> V_64 = V_32 -> V_65 ;
}
V_6 -> V_31 . V_32 = V_14 ;
F_37 ( V_25 [ V_14 -> V_13 ] -> V_66 ,
V_6 ) ;
return 0 ;
}
static void F_38 ( struct V_5 * V_6 )
{
T_1 V_13 , V_20 ;
V_13 = F_3 ( V_6 ) ;
V_20 = F_14 ( V_6 ) ;
memset ( & V_26 [ V_13 ] , 0 , sizeof( struct V_67 ) ) ;
memset ( & V_26 [ V_20 ] , 0 , sizeof( struct V_67 ) ) ;
V_25 [ V_13 ] = NULL ;
V_25 [ V_20 ] = NULL ;
}
static void F_39 ( struct V_5 * V_6 )
{
struct V_12 * V_14 = F_11 ( F_3 ( V_6 ) ) ;
if ( ! V_14 )
return;
if ( V_14 -> V_4 )
F_40 ( V_6 ) ;
F_41 ( V_25 [ V_14 -> V_13 ] -> V_66 ,
V_6 ) ;
F_42 ( V_6 ) ;
V_6 -> V_31 . V_68 = NULL ;
}
static void F_43 ( struct V_69 * V_70 )
{
if ( V_71 == NULL )
return;
V_70 -> V_72 = F_44 ( V_70 -> V_73 , 0444 , V_71 ,
& V_70 -> V_74 ) ;
}
static void F_45 ( void )
{
V_71 = F_46 ( L_5 , NULL ) ;
if ( V_71 == NULL )
return;
V_75 = F_47 ( L_6 , 0444 , V_71 ,
& V_76 ) ;
F_43 ( & V_77 ) ;
F_43 ( & V_78 ) ;
F_43 ( & V_79 ) ;
F_43 ( & V_80 ) ;
F_43 ( & V_81 ) ;
F_43 ( & V_82 ) ;
F_43 ( & V_83 ) ;
F_43 ( & V_84 ) ;
F_43 ( & V_85 ) ;
F_43 ( & V_86 ) ;
F_43 ( & V_87 ) ;
F_43 ( & V_88 ) ;
F_43 ( & V_89 ) ;
F_43 ( & V_90 ) ;
F_43 ( & V_91 ) ;
F_43 ( & V_92 ) ;
}
static void F_48 ( T_1 V_13 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < 4 ; ++ V_37 )
F_49 ( L_7 , V_37 ,
V_26 [ V_13 ] . V_21 [ V_37 ] ) ;
}
static void F_50 ( unsigned long V_93 )
{
struct V_94 * V_95 = F_51 ( V_93 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < 4 ; ++ V_37 )
F_49 ( L_8 , V_37 , V_95 -> V_21 [ V_37 ] ) ;
}
static void F_52 ( struct V_63 * V_32 , void * V_96 )
{
int type , V_13 , V_97 , V_15 ;
volatile T_2 * V_98 = V_96 ;
int V_99 = 0 ;
T_3 V_100 ;
V_101:
type = ( V_98 [ 1 ] >> V_102 ) & V_103 ;
V_13 = ( V_98 [ 0 ] >> V_104 ) & V_105 ;
V_97 = ( V_98 [ 1 ] >> V_106 ) & V_107 ;
V_15 = ( V_98 [ 1 ] >> V_108 ) & V_109 ;
V_100 = ( T_3 ) ( ( ( T_3 ) V_98 [ 3 ] ) << 32 ) | V_98 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_99 == V_110 ) {
F_49 ( L_9 ) ;
return;
}
F_53 ( 1 ) ;
goto V_101;
}
F_54 ( V_111 L_10 ) ;
switch ( type ) {
case V_112 :
F_54 ( L_11
L_12 ,
F_17 ( V_13 ) , F_18 ( V_13 ) , F_19 ( V_13 ) ,
V_100 , V_15 ) ;
F_48 ( V_13 ) ;
break;
case V_113 :
F_54 ( L_13
L_14 ,
F_17 ( V_13 ) , F_18 ( V_13 ) , F_19 ( V_13 ) ,
V_97 , V_100 , V_15 ) ;
break;
case V_114 :
F_54 ( L_15
L_12 ,
F_17 ( V_13 ) , F_18 ( V_13 ) , F_19 ( V_13 ) ,
V_100 , V_15 ) ;
break;
case V_115 :
F_54 ( L_16
L_14 ,
F_17 ( V_13 ) , F_18 ( V_13 ) , F_19 ( V_13 ) ,
V_97 , V_100 , V_15 ) ;
break;
case V_116 :
F_54 ( L_17 , V_100 ) ;
F_50 ( V_100 ) ;
break;
case V_117 :
F_54 ( L_18
L_19 , V_100 , V_15 ) ;
break;
case V_118 :
F_54 ( L_20
L_21 ,
F_17 ( V_13 ) , F_18 ( V_13 ) , F_19 ( V_13 ) ,
V_100 ) ;
break;
case V_119 :
F_54 ( L_22
L_12 ,
F_17 ( V_13 ) , F_18 ( V_13 ) , F_19 ( V_13 ) ,
V_100 , V_15 ) ;
break;
default:
F_54 ( V_111 L_23 , type ) ;
}
memset ( V_96 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_55 ( struct V_63 * V_32 )
{
T_2 V_120 , V_121 ;
V_120 = F_56 ( V_32 -> V_122 + V_123 ) ;
V_121 = F_56 ( V_32 -> V_122 + V_124 ) ;
while ( V_120 != V_121 ) {
F_52 ( V_32 , V_32 -> V_125 + V_120 ) ;
V_120 = ( V_120 + V_126 ) % V_127 ;
}
F_57 ( V_120 , V_32 -> V_122 + V_123 ) ;
}
static void F_58 ( struct V_63 * V_32 , T_3 * V_128 )
{
struct V_129 V_130 ;
F_59 ( V_92 ) ;
if ( F_60 ( V_128 [ 0 ] ) != V_131 ) {
F_61 ( L_24 ) ;
return;
}
V_130 . V_100 = V_128 [ 1 ] ;
V_130 . V_132 = F_62 ( V_128 [ 0 ] ) ;
V_130 . V_133 = F_63 ( V_128 [ 0 ] ) ;
V_130 . V_134 = F_64 ( V_128 [ 0 ] ) ;
V_130 . V_15 = F_65 ( V_128 [ 0 ] ) ;
F_66 ( & V_135 , 0 , & V_130 ) ;
}
static void F_67 ( struct V_63 * V_32 )
{
T_2 V_120 , V_121 ;
if ( V_32 -> V_136 == NULL )
return;
V_120 = F_56 ( V_32 -> V_122 + V_137 ) ;
V_121 = F_56 ( V_32 -> V_122 + V_138 ) ;
while ( V_120 != V_121 ) {
volatile T_3 * V_128 ;
T_3 V_139 [ 2 ] ;
int V_37 ;
V_128 = ( T_3 * ) ( V_32 -> V_136 + V_120 ) ;
for ( V_37 = 0 ; V_37 < V_110 ; ++ V_37 ) {
if ( F_60 ( V_128 [ 0 ] ) != 0 )
break;
F_53 ( 1 ) ;
}
V_139 [ 0 ] = V_128 [ 0 ] ;
V_139 [ 1 ] = V_128 [ 1 ] ;
V_128 [ 0 ] = V_128 [ 1 ] = 0UL ;
V_120 = ( V_120 + V_140 ) % V_141 ;
F_57 ( V_120 , V_32 -> V_122 + V_137 ) ;
F_58 ( V_32 , V_139 ) ;
V_120 = F_56 ( V_32 -> V_122 + V_137 ) ;
V_121 = F_56 ( V_32 -> V_122 + V_138 ) ;
}
}
T_4 F_68 ( int V_142 , void * V_21 )
{
struct V_63 * V_32 = (struct V_63 * ) V_21 ;
T_2 V_143 = F_56 ( V_32 -> V_122 + V_144 ) ;
while ( V_143 & ( V_145 | V_146 ) ) {
F_57 ( ( V_145 | V_146 ) ,
V_32 -> V_122 + V_144 ) ;
if ( V_143 & V_145 ) {
F_69 ( L_25 ) ;
F_55 ( V_32 ) ;
}
if ( V_143 & V_146 ) {
F_69 ( L_26 ) ;
F_67 ( V_32 ) ;
}
V_143 = F_56 ( V_32 -> V_122 + V_144 ) ;
}
return V_147 ;
}
T_4 F_70 ( int V_142 , void * V_21 )
{
return V_148 ;
}
static int F_71 ( volatile T_3 * V_149 )
{
int V_37 = 0 ;
while ( * V_149 == 0 && V_37 < V_110 ) {
F_53 ( 1 ) ;
V_37 += 1 ;
}
if ( V_37 == V_110 ) {
F_72 ( L_27 ) ;
return - V_150 ;
}
return 0 ;
}
static void F_73 ( struct V_63 * V_32 ,
struct V_94 * V_95 ,
T_2 V_121 )
{
T_5 * V_151 ;
V_151 = V_32 -> V_152 + V_121 ;
V_121 = ( V_121 + sizeof( * V_95 ) ) % V_153 ;
memcpy ( V_151 , V_95 , sizeof( * V_95 ) ) ;
F_57 ( V_121 , V_32 -> V_122 + V_154 ) ;
}
static void F_74 ( struct V_94 * V_95 , T_3 V_100 )
{
F_75 ( V_100 & 0x7ULL ) ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_21 [ 0 ] = F_76 ( F_77 ( V_100 ) ) | V_155 ;
V_95 -> V_21 [ 1 ] = F_78 ( F_77 ( V_100 ) ) ;
V_95 -> V_21 [ 2 ] = 1 ;
F_79 ( V_95 , V_156 ) ;
}
static void F_80 ( struct V_94 * V_95 , T_1 V_13 )
{
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_21 [ 0 ] = V_13 ;
F_79 ( V_95 , V_157 ) ;
}
static void F_81 ( struct V_94 * V_95 , T_3 V_100 ,
T_6 V_158 , T_1 V_97 , int V_159 )
{
T_3 V_160 ;
bool V_161 ;
V_160 = F_82 ( V_100 , V_158 , V_48 ) ;
V_161 = false ;
if ( V_160 > 1 ) {
V_100 = V_162 ;
V_161 = true ;
}
V_100 &= V_163 ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_21 [ 1 ] |= V_97 ;
V_95 -> V_21 [ 2 ] = F_76 ( V_100 ) ;
V_95 -> V_21 [ 3 ] = F_78 ( V_100 ) ;
F_79 ( V_95 , V_164 ) ;
if ( V_161 )
V_95 -> V_21 [ 2 ] |= V_165 ;
if ( V_159 )
V_95 -> V_21 [ 2 ] |= V_166 ;
}
static void F_83 ( struct V_94 * V_95 , T_1 V_13 , int V_167 ,
T_3 V_100 , T_6 V_158 )
{
T_3 V_160 ;
bool V_161 ;
V_160 = F_82 ( V_100 , V_158 , V_48 ) ;
V_161 = false ;
if ( V_160 > 1 ) {
V_100 = V_162 ;
V_161 = true ;
}
V_100 &= V_163 ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_21 [ 0 ] = V_13 ;
V_95 -> V_21 [ 0 ] |= ( V_167 & 0xff ) << 24 ;
V_95 -> V_21 [ 1 ] = V_13 ;
V_95 -> V_21 [ 2 ] = F_76 ( V_100 ) ;
V_95 -> V_21 [ 3 ] = F_78 ( V_100 ) ;
F_79 ( V_95 , V_168 ) ;
if ( V_161 )
V_95 -> V_21 [ 2 ] |= V_165 ;
}
static void F_84 ( struct V_94 * V_95 , T_1 V_97 , int V_132 ,
T_3 V_100 , bool V_158 )
{
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_100 &= ~ ( 0xfffULL ) ;
V_95 -> V_21 [ 0 ] = V_132 ;
V_95 -> V_21 [ 1 ] = V_97 ;
V_95 -> V_21 [ 2 ] = F_76 ( V_100 ) ;
V_95 -> V_21 [ 3 ] = F_78 ( V_100 ) ;
V_95 -> V_21 [ 2 ] |= V_166 ;
V_95 -> V_21 [ 2 ] |= V_169 ;
if ( V_158 )
V_95 -> V_21 [ 2 ] |= V_165 ;
F_79 ( V_95 , V_164 ) ;
}
static void F_85 ( struct V_94 * V_95 , T_1 V_13 , int V_132 ,
int V_167 , T_3 V_100 , bool V_158 )
{
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_100 &= ~ ( 0xfffULL ) ;
V_95 -> V_21 [ 0 ] = V_13 ;
V_95 -> V_21 [ 0 ] |= ( ( V_132 >> 8 ) & 0xff ) << 16 ;
V_95 -> V_21 [ 0 ] |= ( V_167 & 0xff ) << 24 ;
V_95 -> V_21 [ 1 ] = V_13 ;
V_95 -> V_21 [ 1 ] |= ( V_132 & 0xff ) << 16 ;
V_95 -> V_21 [ 2 ] = F_76 ( V_100 ) ;
V_95 -> V_21 [ 2 ] |= V_169 ;
V_95 -> V_21 [ 3 ] = F_78 ( V_100 ) ;
if ( V_158 )
V_95 -> V_21 [ 2 ] |= V_165 ;
F_79 ( V_95 , V_168 ) ;
}
static void F_86 ( struct V_94 * V_95 , T_1 V_13 , int V_132 ,
int V_143 , int V_134 , bool V_170 )
{
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_21 [ 0 ] = V_13 ;
if ( V_170 ) {
V_95 -> V_21 [ 1 ] = V_132 ;
V_95 -> V_21 [ 2 ] = V_169 ;
}
V_95 -> V_21 [ 3 ] = V_134 & 0x1ff ;
V_95 -> V_21 [ 3 ] |= ( V_143 & V_171 ) << V_172 ;
F_79 ( V_95 , V_173 ) ;
}
static void F_87 ( struct V_94 * V_95 )
{
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
F_79 ( V_95 , V_174 ) ;
}
static void F_88 ( struct V_94 * V_95 , T_1 V_13 )
{
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_21 [ 0 ] = V_13 ;
F_79 ( V_95 , V_175 ) ;
}
static int F_89 ( struct V_63 * V_32 ,
struct V_94 * V_95 ,
bool V_176 )
{
T_2 V_177 , V_121 , V_120 , V_178 ;
unsigned long V_15 ;
V_179:
F_8 ( & V_32 -> V_180 , V_15 ) ;
V_120 = F_56 ( V_32 -> V_122 + V_181 ) ;
V_121 = F_56 ( V_32 -> V_122 + V_154 ) ;
V_178 = ( V_121 + sizeof( * V_95 ) ) % V_153 ;
V_177 = ( V_120 - V_178 ) % V_153 ;
if ( V_177 <= 2 ) {
struct V_94 V_182 ;
volatile T_3 V_149 = 0 ;
int V_183 ;
F_74 ( & V_182 , ( T_3 ) & V_149 ) ;
F_73 ( V_32 , & V_182 , V_121 ) ;
F_10 ( & V_32 -> V_180 , V_15 ) ;
if ( ( V_183 = F_71 ( & V_149 ) ) != 0 )
return V_183 ;
goto V_179;
}
F_73 ( V_32 , V_95 , V_121 ) ;
V_32 -> V_184 = V_176 ;
F_10 ( & V_32 -> V_180 , V_15 ) ;
return 0 ;
}
static int F_90 ( struct V_63 * V_32 , struct V_94 * V_95 )
{
return F_89 ( V_32 , V_95 , true ) ;
}
static int F_91 ( struct V_63 * V_32 )
{
struct V_94 V_95 ;
volatile T_3 V_149 = 0 ;
int V_183 ;
if ( ! V_32 -> V_184 )
return 0 ;
F_74 ( & V_95 , ( T_3 ) & V_149 ) ;
V_183 = F_89 ( V_32 , & V_95 , false ) ;
if ( V_183 )
return V_183 ;
return F_71 ( & V_149 ) ;
}
static int F_92 ( struct V_63 * V_32 , T_1 V_13 )
{
struct V_94 V_95 ;
F_80 ( & V_95 , V_13 ) ;
return F_90 ( V_32 , & V_95 ) ;
}
static void F_93 ( struct V_63 * V_32 )
{
T_2 V_13 ;
for ( V_13 = 0 ; V_13 <= 0xffff ; ++ V_13 )
F_92 ( V_32 , V_13 ) ;
F_91 ( V_32 ) ;
}
static void F_94 ( struct V_63 * V_32 )
{
T_2 V_185 ;
for ( V_185 = 0 ; V_185 <= 0xffff ; ++ V_185 ) {
struct V_94 V_95 ;
F_81 ( & V_95 , 0 , V_162 ,
V_185 , 1 ) ;
F_90 ( V_32 , & V_95 ) ;
}
F_91 ( V_32 ) ;
}
static void F_95 ( struct V_63 * V_32 )
{
struct V_94 V_95 ;
F_87 ( & V_95 ) ;
F_90 ( V_32 , & V_95 ) ;
F_91 ( V_32 ) ;
}
static void F_96 ( struct V_63 * V_32 , T_1 V_13 )
{
struct V_94 V_95 ;
F_88 ( & V_95 , V_13 ) ;
F_90 ( V_32 , & V_95 ) ;
}
static void F_97 ( struct V_63 * V_32 )
{
T_2 V_13 ;
for ( V_13 = 0 ; V_13 <= V_186 ; V_13 ++ )
F_96 ( V_32 , V_13 ) ;
F_91 ( V_32 ) ;
}
void F_98 ( struct V_63 * V_32 )
{
if ( F_99 ( V_32 , V_187 ) ) {
F_95 ( V_32 ) ;
} else {
F_93 ( V_32 ) ;
F_97 ( V_32 ) ;
F_94 ( V_32 ) ;
}
}
static int F_100 ( struct V_12 * V_14 ,
T_3 V_100 , T_6 V_158 )
{
struct V_63 * V_32 ;
struct V_94 V_95 ;
int V_167 ;
V_167 = V_14 -> V_188 . V_167 ;
V_32 = V_25 [ V_14 -> V_13 ] ;
F_83 ( & V_95 , V_14 -> V_13 , V_167 , V_100 , V_158 ) ;
return F_90 ( V_32 , & V_95 ) ;
}
static int F_101 ( struct V_12 * V_14 )
{
struct V_63 * V_32 ;
T_1 V_20 ;
int V_183 ;
V_32 = V_25 [ V_14 -> V_13 ] ;
V_20 = V_14 -> V_20 ;
V_183 = F_92 ( V_32 , V_14 -> V_13 ) ;
if ( ! V_183 && V_20 != V_14 -> V_13 )
V_183 = F_92 ( V_32 , V_20 ) ;
if ( V_183 )
return V_183 ;
if ( V_14 -> V_188 . V_189 )
V_183 = F_100 ( V_14 , 0 , ~ 0UL ) ;
return V_183 ;
}
static void F_102 ( struct V_1 * V_4 ,
T_3 V_100 , T_6 V_158 , int V_159 )
{
struct V_12 * V_14 ;
struct V_94 V_95 ;
int V_183 = 0 , V_37 ;
F_81 ( & V_95 , V_100 , V_158 , V_4 -> V_190 , V_159 ) ;
for ( V_37 = 0 ; V_37 < V_191 ; ++ V_37 ) {
if ( ! V_4 -> V_192 [ V_37 ] )
continue;
V_183 |= F_90 ( V_193 [ V_37 ] , & V_95 ) ;
}
F_12 (dev_data, &domain->dev_list, list) {
if ( ! V_14 -> V_188 . V_189 )
continue;
V_183 |= F_100 ( V_14 , V_100 , V_158 ) ;
}
F_75 ( V_183 ) ;
}
static void F_103 ( struct V_1 * V_4 ,
T_3 V_100 , T_6 V_158 )
{
F_102 ( V_4 , V_100 , V_158 , 0 ) ;
}
static void F_104 ( struct V_1 * V_4 )
{
F_102 ( V_4 , 0 , V_162 , 0 ) ;
}
static void F_105 ( struct V_1 * V_4 )
{
F_102 ( V_4 , 0 , V_162 , 1 ) ;
}
static void F_106 ( struct V_1 * V_4 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_191 ; ++ V_37 ) {
if ( ! V_4 -> V_192 [ V_37 ] )
continue;
F_91 ( V_193 [ V_37 ] ) ;
}
}
static void F_107 ( struct V_1 * V_4 )
{
struct V_12 * V_14 ;
F_12 (dev_data, &domain->dev_list, list)
F_101 ( V_14 ) ;
}
static bool F_108 ( struct V_1 * V_4 ,
T_7 V_194 )
{
T_3 * V_195 ;
if ( V_4 -> V_196 == V_197 )
return false ;
V_195 = ( void * ) F_109 ( V_194 ) ;
if ( ! V_195 )
return false ;
* V_195 = F_110 ( V_4 -> V_196 ,
F_111 ( V_4 -> V_198 ) ) ;
V_4 -> V_198 = V_195 ;
V_4 -> V_196 += 1 ;
V_4 -> V_199 = true ;
return true ;
}
static T_3 * F_112 ( struct V_1 * V_4 ,
unsigned long V_100 ,
unsigned long V_200 ,
T_3 * * V_201 ,
T_7 V_194 )
{
int V_202 , V_203 ;
T_3 * V_195 , * V_204 ;
F_113 ( ! F_114 ( V_200 ) ) ;
while ( V_100 > F_115 ( V_4 -> V_196 ) )
F_108 ( V_4 , V_194 ) ;
V_202 = V_4 -> V_196 - 1 ;
V_195 = & V_4 -> V_198 [ F_116 ( V_202 , V_100 ) ] ;
V_100 = F_117 ( V_100 , V_200 ) ;
V_203 = F_118 ( V_200 ) ;
while ( V_202 > V_203 ) {
T_3 V_205 , V_206 ;
V_205 = * V_195 ;
if ( ! F_119 ( V_205 ) ) {
V_204 = ( T_3 * ) F_109 ( V_194 ) ;
if ( ! V_204 )
return NULL ;
V_206 = F_110 ( V_202 , F_111 ( V_204 ) ) ;
if ( F_120 ( V_195 , V_205 , V_206 ) ) {
F_121 ( ( unsigned long ) V_204 ) ;
continue;
}
}
if ( F_122 ( * V_195 ) != V_202 )
return NULL ;
V_202 -= 1 ;
V_195 = F_123 ( * V_195 ) ;
if ( V_201 && V_202 == V_203 )
* V_201 = V_195 ;
V_195 = & V_195 [ F_116 ( V_202 , V_100 ) ] ;
}
return V_195 ;
}
static T_3 * F_124 ( struct V_1 * V_4 ,
unsigned long V_100 ,
unsigned long * V_200 )
{
int V_202 ;
T_3 * V_195 ;
if ( V_100 > F_115 ( V_4 -> V_196 ) )
return NULL ;
V_202 = V_4 -> V_196 - 1 ;
V_195 = & V_4 -> V_198 [ F_116 ( V_202 , V_100 ) ] ;
* V_200 = F_125 ( V_202 ) ;
while ( V_202 > 0 ) {
if ( ! F_119 ( * V_195 ) )
return NULL ;
if ( F_122 ( * V_195 ) == 7 ||
F_122 ( * V_195 ) == 0 )
break;
if ( F_122 ( * V_195 ) != V_202 )
return NULL ;
V_202 -= 1 ;
V_195 = F_123 ( * V_195 ) ;
V_195 = & V_195 [ F_116 ( V_202 , V_100 ) ] ;
* V_200 = F_125 ( V_202 ) ;
}
if ( F_122 ( * V_195 ) == 0x07 ) {
unsigned long V_207 ;
* V_200 = V_207 = F_126 ( * V_195 ) ;
V_207 = ~ ( ( F_127 ( V_207 ) << 3 ) - 1 ) ;
V_195 = ( T_3 * ) ( ( ( unsigned long ) V_195 ) & V_207 ) ;
}
return V_195 ;
}
static int F_128 ( struct V_1 * V_3 ,
unsigned long V_208 ,
unsigned long V_93 ,
int V_209 ,
unsigned long V_200 )
{
T_3 V_205 , * V_195 ;
int V_37 , V_99 ;
F_113 ( ! F_129 ( V_208 , V_200 ) ) ;
F_113 ( ! F_129 ( V_93 , V_200 ) ) ;
if ( ! ( V_209 & V_210 ) )
return - V_211 ;
V_99 = F_127 ( V_200 ) ;
V_195 = F_112 ( V_3 , V_208 , V_200 , NULL , V_16 ) ;
if ( ! V_195 )
return - V_62 ;
for ( V_37 = 0 ; V_37 < V_99 ; ++ V_37 )
if ( F_119 ( V_195 [ V_37 ] ) )
return - V_212 ;
if ( V_99 > 1 ) {
V_205 = F_130 ( V_93 , V_200 ) ;
V_205 |= F_131 ( 7 ) | V_213 | V_214 ;
} else
V_205 = V_93 | V_213 | V_214 ;
if ( V_209 & V_215 )
V_205 |= V_216 ;
if ( V_209 & V_217 )
V_205 |= V_218 ;
for ( V_37 = 0 ; V_37 < V_99 ; ++ V_37 )
V_195 [ V_37 ] = V_205 ;
F_132 ( V_3 ) ;
return 0 ;
}
static unsigned long F_133 ( struct V_1 * V_3 ,
unsigned long V_208 ,
unsigned long V_200 )
{
unsigned long long V_219 ;
unsigned long V_220 ;
T_3 * V_195 ;
F_113 ( ! F_114 ( V_200 ) ) ;
V_219 = 0 ;
while ( V_219 < V_200 ) {
V_195 = F_124 ( V_3 , V_208 , & V_220 ) ;
if ( V_195 ) {
int V_37 , V_99 ;
V_99 = F_127 ( V_220 ) ;
for ( V_37 = 0 ; V_37 < V_99 ; V_37 ++ )
V_195 [ V_37 ] = 0ULL ;
}
V_208 = ( V_208 & ~ ( V_220 - 1 ) ) + V_220 ;
V_219 += V_220 ;
}
F_113 ( V_219 && ! F_114 ( V_219 ) ) ;
return V_219 ;
}
static void F_134 ( struct V_41 * V_3 ,
unsigned long V_221 ,
unsigned int V_160 )
{
unsigned int V_37 , V_222 = V_3 -> V_49 >> V_50 ;
if ( V_221 + V_160 > V_222 )
V_160 = V_222 - V_221 ;
for ( V_37 = V_221 ; V_37 < V_221 + V_160 ; ++ V_37 ) {
int V_223 = V_37 / V_224 ;
int V_204 = V_37 % V_224 ;
F_27 ( V_204 , V_3 -> V_51 [ V_223 ] -> V_52 ) ;
}
}
static int F_135 ( struct V_41 * V_42 ,
bool V_225 , T_7 V_194 )
{
int V_223 = V_42 -> V_49 >> V_226 ;
unsigned long V_37 , V_227 , V_228 ;
struct V_229 * V_230 ;
struct V_63 * V_32 ;
unsigned long V_15 ;
#ifdef F_136
V_225 = false ;
#endif
if ( V_223 >= V_231 )
return - V_62 ;
V_230 = F_7 ( sizeof( struct V_229 ) , V_194 ) ;
if ( ! V_230 )
return - V_62 ;
V_230 -> V_52 = ( void * ) F_109 ( V_194 ) ;
if ( ! V_230 -> V_52 )
goto V_232;
V_230 -> V_233 = V_42 -> V_49 ;
F_137 ( & V_230 -> V_234 ) ;
if ( V_225 ) {
unsigned long V_100 = V_42 -> V_49 ;
int V_37 , V_235 = V_224 / 512 ;
T_3 * V_195 , * V_201 ;
for ( V_37 = 0 ; V_37 < V_235 ; ++ V_37 ) {
V_195 = F_112 ( & V_42 -> V_4 , V_100 , V_48 ,
& V_201 , V_194 ) ;
if ( ! V_195 )
goto V_232;
V_230 -> V_236 [ V_37 ] = V_201 ;
V_100 += V_237 / 64 ;
}
}
F_8 ( & V_42 -> V_4 . V_180 , V_15 ) ;
F_138 ( & V_230 -> V_234 ) ;
V_227 = V_42 -> V_49 ;
V_42 -> V_51 [ V_223 ] = V_230 ;
V_42 -> V_49 += V_237 ;
if ( V_227 < V_238 &&
V_42 -> V_49 > V_238 ) {
unsigned long V_239 ;
int V_160 ;
V_160 = F_82 ( V_238 , 0x10000 , V_48 ) ;
V_239 = V_238 >> V_50 ;
F_134 ( V_42 , V_239 , V_160 ) ;
}
F_139 (iommu) {
if ( V_32 -> V_240 &&
V_32 -> V_240 >= V_42 -> V_51 [ V_223 ] -> V_233
&& V_32 -> V_240 < V_42 -> V_49 ) {
unsigned long V_241 ;
int V_160 = F_82 ( V_32 -> V_240 ,
V_32 -> V_242 ,
V_48 ) ;
V_241 = V_32 -> V_240 >> V_50 ;
F_134 ( V_42 , V_241 , V_160 ) ;
}
}
for ( V_37 = V_42 -> V_51 [ V_223 ] -> V_233 ;
V_37 < V_42 -> V_49 ;
V_37 += V_228 ) {
T_3 * V_195 = F_124 ( & V_42 -> V_4 , V_37 , & V_228 ) ;
if ( ! V_195 || ! F_119 ( * V_195 ) )
continue;
F_134 ( V_42 , V_37 >> V_50 ,
V_228 >> 12 ) ;
}
F_132 ( & V_42 -> V_4 ) ;
F_140 ( & V_230 -> V_234 ) ;
F_10 ( & V_42 -> V_4 . V_180 , V_15 ) ;
return 0 ;
V_232:
F_132 ( & V_42 -> V_4 ) ;
F_121 ( ( unsigned long ) V_230 -> V_52 ) ;
F_141 ( V_230 ) ;
return - V_62 ;
}
static T_8 F_142 ( struct V_41 * V_3 ,
struct V_229 * V_230 ,
unsigned long V_160 ,
unsigned long V_55 ,
unsigned long V_243 ,
unsigned long V_244 ,
bool V_245 )
{
unsigned long V_233 , V_246 , V_15 ;
T_8 V_100 ;
bool V_247 = false ;
V_233 = V_230 -> V_233 >> V_50 ;
V_246 = F_143 ( V_224 , V_233 ,
V_55 >> V_50 ) ;
if ( V_245 ) {
if ( ! F_144 ( & V_230 -> V_234 , V_15 ) )
return - 1 ;
} else {
F_8 ( & V_230 -> V_234 , V_15 ) ;
}
V_100 = F_145 ( V_230 -> V_52 , V_246 , V_230 -> V_248 ,
V_160 , V_233 , V_243 , V_244 ) ;
if ( V_100 == - 1 ) {
V_100 = F_145 ( V_230 -> V_52 , V_246 ,
0 , V_160 , V_233 , V_243 ,
V_244 ) ;
V_247 = true ;
}
if ( V_100 != - 1 )
V_230 -> V_248 = V_100 + V_160 ;
F_10 ( & V_230 -> V_234 , V_15 ) ;
if ( V_247 ) {
F_104 ( & V_3 -> V_4 ) ;
F_106 ( & V_3 -> V_4 ) ;
}
return V_100 ;
}
static unsigned long F_146 ( struct V_5 * V_6 ,
struct V_41 * V_3 ,
unsigned int V_160 ,
unsigned long V_244 ,
T_3 V_55 )
{
unsigned long V_243 , V_249 ;
unsigned long V_100 = - 1 ;
bool V_250 = true ;
T_2 V_251 , V_37 ;
F_147 () ;
V_249 = F_148 ( V_6 ) ;
V_179:
V_251 = F_149 ( * V_3 -> V_252 ) ;
if ( F_150 ( V_251 > V_231 ) ) {
V_251 = 0 ;
F_151 ( * V_3 -> V_252 , 0 ) ;
}
V_243 = V_249 + 1 ? F_152 ( V_249 + 1 , V_48 ) >> V_50 :
1UL << ( V_253 - V_50 ) ;
for ( V_37 = 0 ; V_37 < V_231 ; ++ V_37 ) {
struct V_229 * V_230 ;
int V_223 ;
V_223 = ( V_251 + V_37 ) % V_231 ;
V_230 = V_3 -> V_51 [ V_223 ] ;
if ( ! V_230 || V_230 -> V_233 >= V_55 )
continue;
V_100 = F_142 ( V_3 , V_230 , V_160 ,
V_55 , V_243 ,
V_244 , V_250 ) ;
if ( V_100 != - 1 ) {
V_100 = V_230 -> V_233 + ( V_100 << V_50 ) ;
F_151 ( * V_3 -> V_252 , V_223 ) ;
break;
}
}
if ( V_100 == - 1 && V_250 ) {
V_250 = false ;
goto V_179;
}
F_153 () ;
return V_100 ;
}
static unsigned long F_154 ( struct V_5 * V_6 ,
struct V_41 * V_3 ,
unsigned int V_160 ,
unsigned long V_244 ,
T_3 V_55 )
{
unsigned long V_100 = - 1 ;
while ( V_100 == - 1 ) {
V_100 = F_146 ( V_6 , V_3 , V_160 ,
V_244 , V_55 ) ;
if ( V_100 == - 1 && F_135 ( V_3 , false , V_254 ) )
break;
}
if ( F_150 ( V_100 == - 1 ) )
V_100 = V_255 ;
F_75 ( ( V_100 + ( V_48 * V_160 ) ) > V_3 -> V_49 ) ;
return V_100 ;
}
static void F_155 ( struct V_41 * V_3 ,
unsigned long V_100 ,
unsigned int V_160 )
{
unsigned V_37 = V_100 >> V_226 ;
struct V_229 * V_230 = V_3 -> V_51 [ V_37 ] ;
unsigned long V_15 ;
F_113 ( V_37 >= V_231 || V_230 == NULL ) ;
#ifdef F_136
if ( V_37 < 4 )
return;
#endif
if ( V_76 ) {
F_104 ( & V_3 -> V_4 ) ;
F_106 ( & V_3 -> V_4 ) ;
}
V_100 = ( V_100 % V_237 ) >> V_50 ;
F_8 ( & V_230 -> V_234 , V_15 ) ;
if ( V_100 + V_160 > V_230 -> V_248 )
V_230 -> V_248 = V_100 + V_160 ;
F_156 ( V_230 -> V_52 , V_100 , V_160 ) ;
F_10 ( & V_230 -> V_234 , V_15 ) ;
}
static void F_157 ( struct V_1 * V_4 )
{
unsigned long V_15 ;
F_8 ( & V_256 , V_15 ) ;
F_158 ( & V_4 -> V_257 , & V_258 ) ;
F_10 ( & V_256 , V_15 ) ;
}
static void F_159 ( struct V_1 * V_4 )
{
unsigned long V_15 ;
F_8 ( & V_256 , V_15 ) ;
F_160 ( & V_4 -> V_257 ) ;
F_10 ( & V_256 , V_15 ) ;
}
static T_1 F_161 ( void )
{
unsigned long V_15 ;
int V_190 ;
F_162 ( & V_259 , V_15 ) ;
V_190 = F_163 ( V_260 , V_261 ) ;
F_113 ( V_190 == 0 ) ;
if ( V_190 > 0 && V_190 < V_261 )
F_27 ( V_190 , V_260 ) ;
else
V_190 = 0 ;
F_164 ( & V_259 , V_15 ) ;
return V_190 ;
}
static void F_165 ( int V_190 )
{
unsigned long V_15 ;
F_162 ( & V_259 , V_15 ) ;
if ( V_190 > 0 && V_190 < V_261 )
F_166 ( V_190 , V_260 ) ;
F_164 ( & V_259 , V_15 ) ;
}
static void F_167 ( struct V_1 * V_4 )
{
unsigned long V_262 = ( unsigned long ) V_4 -> V_198 ;
switch ( V_4 -> V_196 ) {
case V_263 :
break;
case V_264 :
F_121 ( V_262 ) ;
break;
case V_265 :
F_168 ( V_262 ) ;
break;
case V_266 :
F_169 ( V_262 ) ;
break;
case V_267 :
F_170 ( V_262 ) ;
break;
case V_268 :
F_171 ( V_262 ) ;
break;
case V_197 :
F_172 ( V_262 ) ;
break;
default:
F_173 () ;
}
}
static void F_174 ( T_3 * V_269 )
{
T_3 * V_270 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < 512 ; ++ V_37 ) {
if ( ! ( V_269 [ V_37 ] & V_271 ) )
continue;
V_270 = F_175 ( V_269 [ V_37 ] & V_163 ) ;
F_121 ( ( unsigned long ) V_270 ) ;
}
}
static void F_176 ( T_3 * V_269 )
{
T_3 * V_270 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < 512 ; ++ V_37 ) {
if ( ! ( V_269 [ V_37 ] & V_271 ) )
continue;
V_270 = F_175 ( V_269 [ V_37 ] & V_163 ) ;
F_174 ( V_270 ) ;
}
}
static void F_177 ( struct V_1 * V_4 )
{
if ( V_4 -> V_272 == 2 )
F_176 ( V_4 -> V_273 ) ;
else if ( V_4 -> V_272 == 1 )
F_174 ( V_4 -> V_273 ) ;
else
F_113 ( V_4 -> V_272 != 0 ) ;
F_121 ( ( unsigned long ) V_4 -> V_273 ) ;
}
static void F_178 ( struct V_41 * V_3 )
{
int V_37 ;
if ( ! V_3 )
return;
F_179 ( V_3 -> V_252 ) ;
F_159 ( & V_3 -> V_4 ) ;
F_167 ( & V_3 -> V_4 ) ;
for ( V_37 = 0 ; V_37 < V_231 ; ++ V_37 ) {
if ( ! V_3 -> V_51 [ V_37 ] )
continue;
F_121 ( ( unsigned long ) V_3 -> V_51 [ V_37 ] -> V_52 ) ;
F_141 ( V_3 -> V_51 [ V_37 ] ) ;
}
F_141 ( V_3 ) ;
}
static int F_180 ( struct V_41 * V_42 ,
int V_274 )
{
int V_183 , V_37 , V_275 ;
V_275 = V_42 -> V_49 >> V_226 ;
V_183 = 0 ;
for ( V_37 = V_275 ; V_37 < V_274 ; ++ V_37 ) {
V_183 = F_135 ( V_42 , false , V_16 ) ;
if ( V_183 )
break;
}
return V_183 ;
}
static struct V_41 * F_181 ( void )
{
struct V_41 * V_42 ;
int V_276 ;
V_42 = F_7 ( sizeof( struct V_41 ) , V_16 ) ;
if ( ! V_42 )
return NULL ;
if ( F_182 ( & V_42 -> V_4 ) )
goto V_277;
V_42 -> V_252 = F_183 ( T_2 ) ;
if ( ! V_42 -> V_252 )
goto V_277;
V_42 -> V_4 . V_196 = V_265 ;
V_42 -> V_4 . V_198 = ( void * ) F_109 ( V_16 ) ;
V_42 -> V_4 . V_15 = V_278 ;
V_42 -> V_4 . V_61 = V_42 ;
if ( ! V_42 -> V_4 . V_198 )
goto V_277;
F_157 ( & V_42 -> V_4 ) ;
if ( F_135 ( V_42 , true , V_16 ) )
goto V_277;
V_42 -> V_51 [ 0 ] -> V_52 [ 0 ] = 1 ;
F_184 ( V_276 )
* F_185 ( V_42 -> V_252 , V_276 ) = 0 ;
return V_42 ;
V_277:
F_178 ( V_42 ) ;
return NULL ;
}
static bool V_41 ( struct V_1 * V_4 )
{
return V_4 -> V_15 & V_278 ;
}
static void F_186 ( T_1 V_13 , struct V_1 * V_4 , bool V_188 )
{
T_3 V_279 = 0 ;
T_3 V_15 = 0 ;
if ( V_4 -> V_196 != V_263 )
V_279 = F_111 ( V_4 -> V_198 ) ;
V_279 |= ( V_4 -> V_196 & V_280 )
<< V_281 ;
V_279 |= V_216 | V_218 | V_213 | V_282 ;
V_15 = V_26 [ V_13 ] . V_21 [ 1 ] ;
if ( V_188 )
V_15 |= V_283 ;
if ( V_4 -> V_15 & V_284 ) {
T_3 V_285 = F_77 ( V_4 -> V_273 ) ;
T_3 V_272 = V_4 -> V_272 ;
T_3 V_286 ;
V_279 |= V_287 ;
V_279 |= ( V_272 & V_288 ) << V_289 ;
V_286 = F_187 ( ~ 0ULL ) << V_290 ;
V_15 &= ~ V_286 ;
V_286 = F_188 ( ~ 0ULL ) << V_291 ;
V_15 &= ~ V_286 ;
V_286 = F_189 ( V_285 ) << V_292 ;
V_279 |= V_286 ;
V_286 = F_187 ( V_285 ) << V_290 ;
V_15 |= V_286 ;
V_286 = F_188 ( V_285 ) << V_291 ;
V_15 |= V_286 ;
}
V_15 &= ~ ( 0xffffUL ) ;
V_15 |= V_4 -> V_190 ;
V_26 [ V_13 ] . V_21 [ 1 ] = V_15 ;
V_26 [ V_13 ] . V_21 [ 0 ] = V_279 ;
}
static void F_190 ( T_1 V_13 )
{
V_26 [ V_13 ] . V_21 [ 0 ] = V_213 | V_282 ;
V_26 [ V_13 ] . V_21 [ 1 ] &= V_293 ;
F_191 ( V_13 ) ;
}
static void F_192 ( struct V_12 * V_14 ,
struct V_1 * V_4 )
{
struct V_63 * V_32 ;
T_1 V_20 ;
bool V_188 ;
V_32 = V_25 [ V_14 -> V_13 ] ;
V_20 = V_14 -> V_20 ;
V_188 = V_14 -> V_188 . V_189 ;
V_14 -> V_4 = V_4 ;
F_158 ( & V_14 -> V_257 , & V_4 -> V_294 ) ;
V_4 -> V_192 [ V_32 -> V_223 ] += 1 ;
V_4 -> V_295 += 1 ;
F_186 ( V_14 -> V_13 , V_4 , V_188 ) ;
if ( V_20 != V_14 -> V_13 )
F_186 ( V_20 , V_4 , V_188 ) ;
F_101 ( V_14 ) ;
}
static void F_193 ( struct V_12 * V_14 )
{
struct V_63 * V_32 ;
T_1 V_20 ;
if ( ! V_14 -> V_4 )
return;
V_32 = V_25 [ V_14 -> V_13 ] ;
V_20 = V_14 -> V_20 ;
V_14 -> V_4 -> V_192 [ V_32 -> V_223 ] -= 1 ;
V_14 -> V_4 -> V_295 -= 1 ;
V_14 -> V_4 = NULL ;
F_160 ( & V_14 -> V_257 ) ;
F_190 ( V_14 -> V_13 ) ;
if ( V_20 != V_14 -> V_13 )
F_190 ( V_20 ) ;
F_101 ( V_14 ) ;
}
static int F_194 ( struct V_12 * V_14 ,
struct V_1 * V_4 )
{
int V_183 ;
F_75 ( ! F_195 () ) ;
F_138 ( & V_4 -> V_180 ) ;
V_183 = - V_212 ;
if ( V_14 -> V_4 != NULL )
goto V_19;
F_192 ( V_14 , V_4 ) ;
V_183 = 0 ;
V_19:
F_140 ( & V_4 -> V_180 ) ;
return V_183 ;
}
static void F_196 ( struct V_7 * V_8 )
{
F_197 ( V_8 ) ;
F_198 ( V_8 ) ;
F_199 ( V_8 ) ;
}
static int F_200 ( struct V_7 * V_8 )
{
T_1 V_296 ;
int V_38 ;
V_38 = F_24 ( V_8 , V_35 ) ;
if ( ! V_38 )
return - V_211 ;
F_201 ( V_8 , V_38 + V_297 , & V_296 ) ;
V_296 |= V_298 ;
F_202 ( V_8 , V_38 + V_297 , V_296 ) ;
return 0 ;
}
static int F_203 ( struct V_7 * V_8 )
{
bool V_299 ;
int V_300 , V_183 ;
V_300 = 32 ;
if ( F_25 ( V_8 , V_301 ) )
V_300 = 1 ;
V_299 = F_25 ( V_8 , V_302 ) ;
V_183 = F_204 ( V_8 , 0 ) ;
if ( V_183 )
goto V_303;
V_183 = F_205 ( V_8 ) ;
if ( V_183 )
goto V_303;
V_183 = F_206 ( V_8 , V_300 ) ;
if ( V_183 )
goto V_303;
if ( V_299 ) {
V_183 = F_200 ( V_8 ) ;
if ( V_183 )
goto V_303;
}
V_183 = F_207 ( V_8 , V_50 ) ;
if ( V_183 )
goto V_303;
return 0 ;
V_303:
F_198 ( V_8 ) ;
F_199 ( V_8 ) ;
return V_183 ;
}
static bool F_208 ( struct V_7 * V_8 )
{
T_1 V_143 ;
int V_38 ;
V_38 = F_24 ( V_8 , V_35 ) ;
if ( ! V_38 )
return false ;
F_201 ( V_8 , V_38 + V_304 , & V_143 ) ;
return ( V_143 & V_305 ) ? true : false ;
}
static int F_209 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_12 * V_14 ;
unsigned long V_15 ;
int V_183 ;
V_14 = F_22 ( V_6 ) ;
if ( V_4 -> V_15 & V_284 ) {
if ( ! V_14 -> V_306 )
return - V_211 ;
if ( V_14 -> V_64 ) {
if ( F_203 ( V_8 ) != 0 )
return - V_211 ;
V_14 -> V_188 . V_189 = true ;
V_14 -> V_188 . V_167 = F_210 ( V_8 ) ;
V_14 -> V_307 = F_208 ( V_8 ) ;
}
} else if ( V_308 &&
F_207 ( V_8 , V_50 ) == 0 ) {
V_14 -> V_188 . V_189 = true ;
V_14 -> V_188 . V_167 = F_210 ( V_8 ) ;
}
F_162 ( & V_259 , V_15 ) ;
V_183 = F_194 ( V_14 , V_4 ) ;
F_164 ( & V_259 , V_15 ) ;
F_105 ( V_4 ) ;
return V_183 ;
}
static void F_211 ( struct V_12 * V_14 )
{
struct V_1 * V_4 ;
F_75 ( ! F_195 () ) ;
if ( F_75 ( ! V_14 -> V_4 ) )
return;
V_4 = V_14 -> V_4 ;
F_138 ( & V_4 -> V_180 ) ;
F_193 ( V_14 ) ;
F_140 ( & V_4 -> V_180 ) ;
}
static void F_40 ( struct V_5 * V_6 )
{
struct V_1 * V_4 ;
struct V_12 * V_14 ;
unsigned long V_15 ;
V_14 = F_22 ( V_6 ) ;
V_4 = V_14 -> V_4 ;
F_162 ( & V_259 , V_15 ) ;
F_211 ( V_14 ) ;
F_164 ( & V_259 , V_15 ) ;
if ( V_4 -> V_15 & V_284 && V_14 -> V_64 )
F_196 ( F_4 ( V_6 ) ) ;
else if ( V_14 -> V_188 . V_189 )
F_197 ( F_4 ( V_6 ) ) ;
V_14 -> V_188 . V_189 = false ;
}
static int F_212 ( struct V_5 * V_6 )
{
struct V_12 * V_14 ;
struct V_2 * V_4 ;
struct V_63 * V_32 ;
T_1 V_13 ;
int V_183 ;
if ( ! F_29 ( V_6 ) || F_22 ( V_6 ) )
return 0 ;
V_13 = F_3 ( V_6 ) ;
V_32 = V_25 [ V_13 ] ;
V_183 = F_36 ( V_6 ) ;
if ( V_183 ) {
if ( V_183 != - V_309 )
F_49 ( L_28 ,
F_20 ( V_6 ) ) ;
F_38 ( V_6 ) ;
V_6 -> V_31 . V_68 = & V_310 ;
goto V_60;
}
F_31 ( V_6 ) ;
V_14 = F_22 ( V_6 ) ;
F_113 ( ! V_14 ) ;
if ( V_311 || V_14 -> V_64 )
F_213 ( V_6 ) ;
V_4 = F_214 ( V_6 ) ;
if ( V_4 -> type == V_312 )
V_14 -> V_306 = true ;
else
V_6 -> V_31 . V_68 = & V_313 ;
V_60:
F_91 ( V_32 ) ;
return 0 ;
}
static void F_215 ( struct V_5 * V_6 )
{
struct V_63 * V_32 ;
T_1 V_13 ;
if ( ! F_29 ( V_6 ) )
return;
V_13 = F_3 ( V_6 ) ;
V_32 = V_25 [ V_13 ] ;
F_39 ( V_6 ) ;
F_91 ( V_32 ) ;
}
static struct V_1 * F_216 ( struct V_5 * V_6 )
{
struct V_1 * V_4 ;
struct V_2 * V_314 ;
if ( ! F_29 ( V_6 ) )
return F_217 ( - V_211 ) ;
V_314 = F_214 ( V_6 ) ;
if ( ! V_314 )
return NULL ;
V_4 = F_1 ( V_314 ) ;
if ( ! V_41 ( V_4 ) )
return F_217 ( - V_212 ) ;
return V_4 ;
}
static void F_218 ( struct V_1 * V_4 )
{
struct V_12 * V_14 ;
F_12 (dev_data, &domain->dev_list, list)
F_186 ( V_14 -> V_13 , V_4 , V_14 -> V_188 . V_189 ) ;
}
static void F_132 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_199 )
return;
F_218 ( V_4 ) ;
F_107 ( V_4 ) ;
F_105 ( V_4 ) ;
V_4 -> V_199 = false ;
}
static T_3 * F_219 ( struct V_41 * V_3 ,
unsigned long V_100 )
{
struct V_229 * V_51 ;
T_3 * V_195 , * V_201 ;
V_51 = V_3 -> V_51 [ F_220 ( V_100 ) ] ;
if ( ! V_51 )
return NULL ;
V_195 = V_51 -> V_236 [ F_221 ( V_100 ) ] ;
if ( ! V_195 ) {
V_195 = F_112 ( & V_3 -> V_4 , V_100 , V_48 , & V_201 ,
V_254 ) ;
V_51 -> V_236 [ F_221 ( V_100 ) ] = V_201 ;
} else
V_195 += F_116 ( 0 , V_100 ) ;
F_132 ( & V_3 -> V_4 ) ;
return V_195 ;
}
static T_8 F_222 ( struct V_41 * V_3 ,
unsigned long V_100 ,
T_9 V_315 ,
int V_316 )
{
T_3 * V_195 , V_205 ;
F_75 ( V_100 > V_3 -> V_49 ) ;
V_315 &= V_163 ;
V_195 = F_219 ( V_3 , V_100 ) ;
if ( ! V_195 )
return V_255 ;
V_205 = V_315 | V_213 | V_214 ;
if ( V_316 == V_317 )
V_205 |= V_216 ;
else if ( V_316 == V_318 )
V_205 |= V_218 ;
else if ( V_316 == V_319 )
V_205 |= V_216 | V_218 ;
F_223 ( * V_195 ) ;
* V_195 = V_205 ;
return ( T_8 ) V_100 ;
}
static void F_224 ( struct V_41 * V_3 ,
unsigned long V_100 )
{
struct V_229 * V_51 ;
T_3 * V_195 ;
if ( V_100 >= V_3 -> V_49 )
return;
V_51 = V_3 -> V_51 [ F_220 ( V_100 ) ] ;
if ( ! V_51 )
return;
V_195 = V_51 -> V_236 [ F_221 ( V_100 ) ] ;
if ( ! V_195 )
return;
V_195 += F_116 ( 0 , V_100 ) ;
F_223 ( ! * V_195 ) ;
* V_195 = 0ULL ;
}
static T_8 F_225 ( struct V_5 * V_6 ,
struct V_41 * V_42 ,
T_9 V_315 ,
T_6 V_158 ,
int V_320 ,
bool V_321 ,
T_3 V_55 )
{
T_8 V_233 = V_315 & ~ V_163 ;
T_8 V_100 , V_251 , V_183 ;
unsigned int V_160 ;
unsigned long V_244 = 0 ;
int V_37 ;
V_160 = F_82 ( V_315 , V_158 , V_48 ) ;
V_315 &= V_163 ;
F_59 ( V_88 ) ;
if ( V_160 > 1 )
F_59 ( V_84 ) ;
if ( V_321 )
V_244 = ( 1UL << F_226 ( V_158 ) ) - 1 ;
V_100 = F_154 ( V_6 , V_42 , V_160 , V_244 ,
V_55 ) ;
if ( V_100 == V_255 )
goto V_60;
V_251 = V_100 ;
for ( V_37 = 0 ; V_37 < V_160 ; ++ V_37 ) {
V_183 = F_222 ( V_42 , V_251 , V_315 , V_320 ) ;
if ( V_183 == V_255 )
goto V_322;
V_315 += V_48 ;
V_251 += V_48 ;
}
V_100 += V_233 ;
F_227 ( V_87 , V_158 ) ;
if ( F_150 ( V_323 ) ) {
F_103 ( & V_42 -> V_4 , V_100 , V_158 ) ;
F_106 ( & V_42 -> V_4 ) ;
}
V_60:
return V_100 ;
V_322:
for ( -- V_37 ; V_37 >= 0 ; -- V_37 ) {
V_251 -= V_48 ;
F_224 ( V_42 , V_251 ) ;
}
F_155 ( V_42 , V_100 , V_160 ) ;
return V_255 ;
}
static void F_228 ( struct V_41 * V_42 ,
T_8 V_324 ,
T_6 V_158 ,
int V_320 )
{
T_8 V_325 ;
T_8 V_37 , V_251 ;
unsigned int V_160 ;
if ( ( V_324 == V_255 ) ||
( V_324 + V_158 > V_42 -> V_49 ) )
return;
V_325 = V_324 ;
V_160 = F_82 ( V_324 , V_158 , V_48 ) ;
V_324 &= V_163 ;
V_251 = V_324 ;
for ( V_37 = 0 ; V_37 < V_160 ; ++ V_37 ) {
F_224 ( V_42 , V_251 ) ;
V_251 += V_48 ;
}
F_229 ( V_87 , V_158 ) ;
F_155 ( V_42 , V_324 , V_160 ) ;
}
static T_8 F_230 ( struct V_5 * V_6 , struct V_204 * V_204 ,
unsigned long V_233 , T_6 V_158 ,
enum V_326 V_320 ,
struct V_327 * V_328 )
{
T_9 V_315 = F_231 ( V_204 ) + V_233 ;
struct V_1 * V_4 ;
T_3 V_55 ;
F_59 ( V_78 ) ;
V_4 = F_216 ( V_6 ) ;
if ( F_232 ( V_4 ) == - V_211 )
return ( T_8 ) V_315 ;
else if ( F_33 ( V_4 ) )
return V_255 ;
V_55 = * V_6 -> V_55 ;
return F_225 ( V_6 , V_4 -> V_61 , V_315 , V_158 , V_320 , false ,
V_55 ) ;
}
static void F_233 ( struct V_5 * V_6 , T_8 V_324 , T_6 V_158 ,
enum V_326 V_320 , struct V_327 * V_328 )
{
struct V_1 * V_4 ;
F_59 ( V_79 ) ;
V_4 = F_216 ( V_6 ) ;
if ( F_33 ( V_4 ) )
return;
F_228 ( V_4 -> V_61 , V_324 , V_158 , V_320 ) ;
}
static int F_234 ( struct V_5 * V_6 , struct V_329 * V_330 ,
int V_331 , enum V_326 V_320 ,
struct V_327 * V_328 )
{
struct V_1 * V_4 ;
int V_37 ;
struct V_329 * V_161 ;
T_9 V_315 ;
int V_332 = 0 ;
T_3 V_55 ;
F_59 ( V_80 ) ;
V_4 = F_216 ( V_6 ) ;
if ( F_33 ( V_4 ) )
return 0 ;
V_55 = * V_6 -> V_55 ;
F_235 (sglist, s, nelems, i) {
V_315 = F_236 ( V_161 ) ;
V_161 -> V_333 = F_225 ( V_6 , V_4 -> V_61 ,
V_315 , V_161 -> V_334 , V_320 , false ,
V_55 ) ;
if ( V_161 -> V_333 ) {
V_161 -> V_335 = V_161 -> V_334 ;
V_332 ++ ;
} else
goto V_336;
}
return V_332 ;
V_336:
F_235 (sglist, s, mapped_elems, i) {
if ( V_161 -> V_333 )
F_228 ( V_4 -> V_61 , V_161 -> V_333 ,
V_161 -> V_335 , V_320 ) ;
V_161 -> V_333 = V_161 -> V_335 = 0 ;
}
return 0 ;
}
static void F_237 ( struct V_5 * V_6 , struct V_329 * V_330 ,
int V_331 , enum V_326 V_320 ,
struct V_327 * V_328 )
{
struct V_1 * V_4 ;
struct V_329 * V_161 ;
int V_37 ;
F_59 ( V_81 ) ;
V_4 = F_216 ( V_6 ) ;
if ( F_33 ( V_4 ) )
return;
F_235 (sglist, s, nelems, i) {
F_228 ( V_4 -> V_61 , V_161 -> V_333 ,
V_161 -> V_335 , V_320 ) ;
V_161 -> V_333 = V_161 -> V_335 = 0 ;
}
}
static void * F_238 ( struct V_5 * V_6 , T_6 V_158 ,
T_8 * V_324 , T_7 V_337 ,
struct V_327 * V_328 )
{
T_3 V_55 = V_6 -> V_338 ;
struct V_1 * V_4 ;
struct V_204 * V_204 ;
F_59 ( V_82 ) ;
V_4 = F_216 ( V_6 ) ;
if ( F_232 ( V_4 ) == - V_211 ) {
V_204 = F_239 ( V_337 , F_226 ( V_158 ) ) ;
* V_324 = F_231 ( V_204 ) ;
return F_240 ( V_204 ) ;
} else if ( F_33 ( V_4 ) )
return NULL ;
V_158 = F_241 ( V_158 ) ;
V_55 = V_6 -> V_338 ;
V_337 &= ~ ( V_339 | V_340 | V_341 ) ;
V_337 |= V_342 ;
V_204 = F_239 ( V_337 | V_343 , F_226 ( V_158 ) ) ;
if ( ! V_204 ) {
if ( ! F_242 ( V_337 ) )
return NULL ;
V_204 = F_243 ( V_6 , V_158 >> V_50 ,
F_226 ( V_158 ) ) ;
if ( ! V_204 )
return NULL ;
}
if ( ! V_55 )
V_55 = * V_6 -> V_55 ;
* V_324 = F_225 ( V_6 , V_4 -> V_61 , F_231 ( V_204 ) ,
V_158 , V_319 , true , V_55 ) ;
if ( * V_324 == V_255 )
goto V_232;
return F_240 ( V_204 ) ;
V_232:
if ( ! F_244 ( V_6 , V_204 , V_158 >> V_50 ) )
F_245 ( V_204 , F_226 ( V_158 ) ) ;
return NULL ;
}
static void F_246 ( struct V_5 * V_6 , T_6 V_158 ,
void * V_344 , T_8 V_324 ,
struct V_327 * V_328 )
{
struct V_1 * V_4 ;
struct V_204 * V_204 ;
F_59 ( V_83 ) ;
V_204 = F_247 ( V_344 ) ;
V_158 = F_241 ( V_158 ) ;
V_4 = F_216 ( V_6 ) ;
if ( F_33 ( V_4 ) )
goto V_345;
F_228 ( V_4 -> V_61 , V_324 , V_158 , V_319 ) ;
V_345:
if ( ! F_244 ( V_6 , V_204 , V_158 >> V_50 ) )
F_245 ( V_204 , F_226 ( V_158 ) ) ;
}
static int F_248 ( struct V_5 * V_6 , T_3 V_249 )
{
return F_29 ( V_6 ) ;
}
static int F_249 ( struct V_5 * V_6 , T_3 V_249 )
{
struct V_1 * V_4 ;
int V_274 = 1 ;
V_4 = F_216 ( V_6 ) ;
if ( F_33 ( V_4 ) )
return F_232 ( V_4 ) ;
if ( V_249 == F_250 ( 64 ) )
V_274 = 8 ;
else if ( V_249 > F_250 ( 32 ) )
V_274 = 4 ;
if ( V_274 > F_251 () )
V_274 = F_251 () ;
if ( F_180 ( V_4 -> V_61 , V_274 ) )
F_252 ( V_6 , L_29 ,
V_274 ) ;
return 0 ;
}
int T_10 F_253 ( void )
{
return F_254 ( & V_346 , & V_347 ) ;
}
int T_10 F_255 ( void )
{
V_348 = V_311 ? 1 : 0 ;
V_349 = 1 ;
if ( ! V_348 )
V_68 = & V_310 ;
F_45 () ;
if ( V_76 )
F_16 ( L_30 ) ;
else
F_16 ( L_31 ) ;
return 0 ;
}
static void F_256 ( struct V_1 * V_4 )
{
struct V_12 * V_139 ;
unsigned long V_15 ;
F_162 ( & V_259 , V_15 ) ;
while ( ! F_257 ( & V_4 -> V_294 ) ) {
V_139 = F_258 ( & V_4 -> V_294 ,
struct V_12 , V_257 ) ;
F_211 ( V_139 ) ;
}
F_164 ( & V_259 , V_15 ) ;
}
static void F_259 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_159 ( V_4 ) ;
if ( V_4 -> V_190 )
F_165 ( V_4 -> V_190 ) ;
F_141 ( V_4 ) ;
}
static int F_182 ( struct V_1 * V_4 )
{
F_137 ( & V_4 -> V_180 ) ;
F_260 ( & V_4 -> V_350 ) ;
V_4 -> V_190 = F_161 () ;
if ( ! V_4 -> V_190 )
return - V_62 ;
F_261 ( & V_4 -> V_294 ) ;
return 0 ;
}
static struct V_1 * F_262 ( void )
{
struct V_1 * V_4 ;
V_4 = F_7 ( sizeof( * V_4 ) , V_16 ) ;
if ( ! V_4 )
return NULL ;
if ( F_182 ( V_4 ) )
goto V_303;
F_157 ( V_4 ) ;
return V_4 ;
V_303:
F_141 ( V_4 ) ;
return NULL ;
}
static struct V_2 * F_263 ( unsigned type )
{
struct V_1 * V_351 ;
struct V_41 * V_57 ;
switch ( type ) {
case V_352 :
V_351 = F_262 () ;
if ( ! V_351 )
return NULL ;
V_351 -> V_196 = V_266 ;
V_351 -> V_198 = ( void * ) F_109 ( V_16 ) ;
if ( ! V_351 -> V_198 ) {
F_259 ( V_351 ) ;
return NULL ;
}
V_351 -> V_4 . V_353 . V_354 = 0 ;
V_351 -> V_4 . V_353 . V_355 = ~ 0ULL ;
V_351 -> V_4 . V_353 . V_356 = true ;
break;
case V_357 :
V_57 = F_181 () ;
if ( ! V_57 ) {
F_49 ( L_32 ) ;
return NULL ;
}
V_351 = & V_57 -> V_4 ;
break;
case V_312 :
V_351 = F_262 () ;
if ( ! V_351 )
return NULL ;
V_351 -> V_196 = V_263 ;
break;
default:
return NULL ;
}
return & V_351 -> V_4 ;
}
static void F_264 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 )
return;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_295 > 0 )
F_256 ( V_4 ) ;
F_113 ( V_4 -> V_295 != 0 ) ;
if ( V_4 -> V_196 != V_263 )
F_167 ( V_4 ) ;
if ( V_4 -> V_15 & V_284 )
F_177 ( V_4 ) ;
F_259 ( V_4 ) ;
}
static void F_265 ( struct V_2 * V_3 ,
struct V_5 * V_6 )
{
struct V_12 * V_14 = V_6 -> V_31 . V_32 ;
struct V_63 * V_32 ;
T_1 V_13 ;
if ( ! F_29 ( V_6 ) )
return;
V_13 = F_3 ( V_6 ) ;
if ( V_14 -> V_4 != NULL )
F_40 ( V_6 ) ;
V_32 = V_25 [ V_13 ] ;
if ( ! V_32 )
return;
F_91 ( V_32 ) ;
}
static int F_266 ( struct V_2 * V_3 ,
struct V_5 * V_6 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_12 * V_14 ;
struct V_63 * V_32 ;
int V_183 ;
if ( ! F_29 ( V_6 ) )
return - V_211 ;
V_14 = V_6 -> V_31 . V_32 ;
V_32 = V_25 [ V_14 -> V_13 ] ;
if ( ! V_32 )
return - V_211 ;
if ( V_14 -> V_4 )
F_40 ( V_6 ) ;
V_183 = F_209 ( V_6 , V_4 ) ;
F_91 ( V_32 ) ;
return V_183 ;
}
static int F_267 ( struct V_2 * V_3 , unsigned long V_358 ,
T_9 V_315 , T_6 V_200 , int V_359 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_209 = 0 ;
int V_183 ;
if ( V_4 -> V_196 == V_263 )
return - V_211 ;
if ( V_359 & V_360 )
V_209 |= V_215 ;
if ( V_359 & V_361 )
V_209 |= V_217 ;
F_268 ( & V_4 -> V_350 ) ;
V_183 = F_128 ( V_4 , V_358 , V_315 , V_209 , V_200 ) ;
F_269 ( & V_4 -> V_350 ) ;
return V_183 ;
}
static T_6 F_270 ( struct V_2 * V_3 , unsigned long V_358 ,
T_6 V_200 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_6 V_220 ;
if ( V_4 -> V_196 == V_263 )
return - V_211 ;
F_268 ( & V_4 -> V_350 ) ;
V_220 = F_133 ( V_4 , V_358 , V_200 ) ;
F_269 ( & V_4 -> V_350 ) ;
F_105 ( V_4 ) ;
return V_220 ;
}
static T_9 F_271 ( struct V_2 * V_3 ,
T_8 V_358 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_362 , V_228 ;
T_3 * V_195 , V_205 ;
if ( V_4 -> V_196 == V_263 )
return V_358 ;
V_195 = F_124 ( V_4 , V_358 , & V_228 ) ;
if ( ! V_195 || ! F_119 ( * V_195 ) )
return 0 ;
V_362 = V_228 - 1 ;
V_205 = * V_195 & V_363 ;
return ( V_205 & ~ V_362 ) | ( V_358 & V_362 ) ;
}
static bool F_272 ( enum V_364 V_365 )
{
switch ( V_365 ) {
case V_366 :
return true ;
case V_367 :
return ( V_368 == 1 ) ;
case V_369 :
return false ;
}
return false ;
}
static void F_273 ( struct V_5 * V_6 ,
struct V_370 * V_120 )
{
struct V_43 * V_139 ;
T_1 V_13 ;
V_13 = F_3 ( V_6 ) ;
F_12 (entry, &amd_iommu_unity_map, list) {
struct V_371 * V_372 ;
if ( V_13 < V_139 -> V_53 || V_13 > V_139 -> V_54 )
continue;
V_372 = F_7 ( sizeof( * V_372 ) , V_16 ) ;
if ( ! V_372 ) {
F_49 ( L_33 ,
F_20 ( V_6 ) ) ;
return;
}
V_372 -> V_251 = V_139 -> V_46 ;
V_372 -> V_334 = V_139 -> V_47 - V_139 -> V_46 ;
if ( V_139 -> V_209 & V_215 )
V_372 -> V_209 |= V_360 ;
if ( V_139 -> V_209 & V_217 )
V_372 -> V_209 |= V_361 ;
F_9 ( & V_372 -> V_257 , V_120 ) ;
}
}
static void F_274 ( struct V_5 * V_6 ,
struct V_370 * V_120 )
{
struct V_371 * V_139 , * V_373 ;
F_275 (entry, next, head, list)
F_141 ( V_139 ) ;
}
int F_276 ( struct V_374 * V_375 )
{
return F_277 ( & V_135 , V_375 ) ;
}
int F_278 ( struct V_374 * V_375 )
{
return F_279 ( & V_135 , V_375 ) ;
}
void F_280 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_15 ;
F_8 ( & V_4 -> V_180 , V_15 ) ;
V_4 -> V_196 = V_263 ;
V_4 -> V_199 = true ;
F_132 ( V_4 ) ;
F_167 ( V_4 ) ;
F_10 ( & V_4 -> V_180 , V_15 ) ;
}
int F_281 ( struct V_2 * V_3 , int V_376 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_15 ;
int V_377 , V_183 ;
if ( V_376 <= 0 || V_376 > ( V_378 + 1 ) )
return - V_211 ;
for ( V_377 = 0 ; ( V_376 - 1 ) & ~ 0x1ff ; V_376 >>= 9 )
V_377 += 1 ;
if ( V_377 > V_379 )
return - V_211 ;
F_8 ( & V_4 -> V_180 , V_15 ) ;
V_183 = - V_212 ;
if ( V_4 -> V_295 > 0 || V_4 -> V_15 & V_284 )
goto V_60;
V_183 = - V_62 ;
V_4 -> V_273 = ( void * ) F_109 ( V_254 ) ;
if ( V_4 -> V_273 == NULL )
goto V_60;
V_4 -> V_272 = V_377 ;
V_4 -> V_15 |= V_284 ;
V_4 -> V_199 = true ;
F_132 ( V_4 ) ;
V_183 = 0 ;
V_60:
F_10 ( & V_4 -> V_180 , V_15 ) ;
return V_183 ;
}
static int F_282 ( struct V_1 * V_4 , int V_132 ,
T_3 V_100 , bool V_158 )
{
struct V_12 * V_14 ;
struct V_94 V_95 ;
int V_37 , V_183 ;
if ( ! ( V_4 -> V_15 & V_284 ) )
return - V_211 ;
F_84 ( & V_95 , V_4 -> V_190 , V_132 , V_100 , V_158 ) ;
for ( V_37 = 0 ; V_37 < V_191 ; ++ V_37 ) {
if ( V_4 -> V_192 [ V_37 ] == 0 )
continue;
V_183 = F_90 ( V_193 [ V_37 ] , & V_95 ) ;
if ( V_183 != 0 )
goto V_60;
}
F_106 ( V_4 ) ;
F_12 (dev_data, &domain->dev_list, list) {
struct V_63 * V_32 ;
int V_167 ;
if ( ! V_14 -> V_188 . V_189 )
continue;
V_167 = V_14 -> V_188 . V_167 ;
V_32 = V_25 [ V_14 -> V_13 ] ;
F_85 ( & V_95 , V_14 -> V_13 , V_132 ,
V_167 , V_100 , V_158 ) ;
V_183 = F_90 ( V_32 , & V_95 ) ;
if ( V_183 != 0 )
goto V_60;
}
F_106 ( V_4 ) ;
V_183 = 0 ;
V_60:
return V_183 ;
}
static int F_283 ( struct V_1 * V_4 , int V_132 ,
T_3 V_100 )
{
F_59 ( V_90 ) ;
return F_282 ( V_4 , V_132 , V_100 , false ) ;
}
int F_284 ( struct V_2 * V_3 , int V_132 ,
T_3 V_100 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_15 ;
int V_183 ;
F_8 ( & V_4 -> V_180 , V_15 ) ;
V_183 = F_283 ( V_4 , V_132 , V_100 ) ;
F_10 ( & V_4 -> V_180 , V_15 ) ;
return V_183 ;
}
static int F_285 ( struct V_1 * V_4 , int V_132 )
{
F_59 ( V_91 ) ;
return F_282 ( V_4 , V_132 , V_162 ,
true ) ;
}
int F_286 ( struct V_2 * V_3 , int V_132 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_15 ;
int V_183 ;
F_8 ( & V_4 -> V_180 , V_15 ) ;
V_183 = F_285 ( V_4 , V_132 ) ;
F_10 ( & V_4 -> V_180 , V_15 ) ;
return V_183 ;
}
static T_3 * F_287 ( T_3 * V_262 , int V_202 , int V_132 , bool V_380 )
{
int V_223 ;
T_3 * V_195 ;
while ( true ) {
V_223 = ( V_132 >> ( 9 * V_202 ) ) & 0x1ff ;
V_195 = & V_262 [ V_223 ] ;
if ( V_202 == 0 )
break;
if ( ! ( * V_195 & V_271 ) ) {
if ( ! V_380 )
return NULL ;
V_262 = ( void * ) F_109 ( V_254 ) ;
if ( V_262 == NULL )
return NULL ;
* V_195 = F_77 ( V_262 ) | V_271 ;
}
V_262 = F_175 ( * V_195 & V_163 ) ;
V_202 -= 1 ;
}
return V_195 ;
}
static int F_288 ( struct V_1 * V_4 , int V_132 ,
unsigned long V_381 )
{
T_3 * V_195 ;
if ( V_4 -> V_196 != V_263 )
return - V_211 ;
V_195 = F_287 ( V_4 -> V_273 , V_4 -> V_272 , V_132 , true ) ;
if ( V_195 == NULL )
return - V_62 ;
* V_195 = ( V_381 & V_163 ) | V_271 ;
return F_285 ( V_4 , V_132 ) ;
}
static int F_289 ( struct V_1 * V_4 , int V_132 )
{
T_3 * V_195 ;
if ( V_4 -> V_196 != V_263 )
return - V_211 ;
V_195 = F_287 ( V_4 -> V_273 , V_4 -> V_272 , V_132 , false ) ;
if ( V_195 == NULL )
return 0 ;
* V_195 = 0 ;
return F_285 ( V_4 , V_132 ) ;
}
int F_290 ( struct V_2 * V_3 , int V_132 ,
unsigned long V_381 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_15 ;
int V_183 ;
F_8 ( & V_4 -> V_180 , V_15 ) ;
V_183 = F_288 ( V_4 , V_132 , V_381 ) ;
F_10 ( & V_4 -> V_180 , V_15 ) ;
return V_183 ;
}
int F_291 ( struct V_2 * V_3 , int V_132 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_15 ;
int V_183 ;
F_8 ( & V_4 -> V_180 , V_15 ) ;
V_183 = F_289 ( V_4 , V_132 ) ;
F_10 ( & V_4 -> V_180 , V_15 ) ;
return V_183 ;
}
int F_292 ( struct V_7 * V_8 , int V_132 ,
int V_143 , int V_134 )
{
struct V_12 * V_14 ;
struct V_63 * V_32 ;
struct V_94 V_95 ;
F_59 ( V_89 ) ;
V_14 = F_22 ( & V_8 -> V_6 ) ;
V_32 = V_25 [ V_14 -> V_13 ] ;
F_86 ( & V_95 , V_14 -> V_13 , V_132 , V_143 ,
V_134 , V_14 -> V_307 ) ;
return F_90 ( V_32 , & V_95 ) ;
}
struct V_2 * F_293 ( struct V_7 * V_8 )
{
struct V_1 * V_351 ;
V_351 = F_216 ( & V_8 -> V_6 ) ;
if ( F_33 ( V_351 ) )
return NULL ;
if ( ! ( V_351 -> V_15 & V_284 ) )
return NULL ;
return & V_351 -> V_4 ;
}
void F_294 ( struct V_7 * V_8 , T_2 V_39 )
{
struct V_12 * V_14 ;
if ( ! F_295 () )
return;
V_14 = F_22 ( & V_8 -> V_6 ) ;
V_14 -> V_40 |= ( 1 << V_39 ) ;
}
int F_296 ( struct V_7 * V_8 ,
struct F_296 * V_382 )
{
int V_383 ;
int V_38 ;
if ( V_8 == NULL || V_382 == NULL )
return - V_211 ;
if ( ! F_295 () )
return - V_211 ;
memset ( V_382 , 0 , sizeof( * V_382 ) ) ;
V_38 = F_24 ( V_8 , V_34 ) ;
if ( V_38 )
V_382 -> V_15 |= V_384 ;
V_38 = F_24 ( V_8 , V_35 ) ;
if ( V_38 )
V_382 -> V_15 |= V_385 ;
V_38 = F_24 ( V_8 , V_36 ) ;
if ( V_38 ) {
int V_386 ;
V_383 = 1 << ( 9 * ( V_379 + 1 ) ) ;
V_383 = F_297 ( V_383 , ( 1 << 20 ) ) ;
V_382 -> V_15 |= V_387 ;
V_382 -> V_383 = F_297 ( F_298 ( V_8 ) , V_383 ) ;
V_386 = F_299 ( V_8 ) ;
if ( V_386 & V_388 )
V_382 -> V_15 |= V_389 ;
if ( V_386 & V_390 )
V_382 -> V_15 |= V_391 ;
}
return 0 ;
}
static void F_300 ( T_1 V_13 , struct V_392 * V_393 )
{
T_3 V_394 ;
V_394 = V_26 [ V_13 ] . V_21 [ 2 ] ;
V_394 &= ~ V_395 ;
V_394 |= F_111 ( V_393 -> V_393 ) ;
V_394 |= V_396 ;
V_394 |= V_397 ;
V_394 |= V_398 ;
V_26 [ V_13 ] . V_21 [ 2 ] = V_394 ;
}
static struct V_392 * F_301 ( T_1 V_13 , bool V_399 )
{
struct V_392 * V_393 = NULL ;
struct V_63 * V_32 ;
unsigned long V_15 ;
T_1 V_20 ;
F_162 ( & V_259 , V_15 ) ;
V_32 = V_25 [ V_13 ] ;
if ( ! V_32 )
goto V_19;
V_393 = V_400 [ V_13 ] ;
if ( V_393 )
goto V_60;
V_20 = V_24 [ V_13 ] ;
V_393 = V_400 [ V_20 ] ;
if ( V_393 ) {
V_400 [ V_13 ] = V_393 ;
F_300 ( V_13 , V_393 ) ;
F_92 ( V_32 , V_13 ) ;
goto V_60;
}
V_393 = F_7 ( sizeof( * V_393 ) , V_254 ) ;
if ( ! V_393 )
goto V_60;
F_137 ( & V_393 -> V_180 ) ;
if ( V_399 )
V_393 -> V_401 = 32 ;
V_393 -> V_393 = F_302 ( V_402 , V_254 ) ;
if ( ! V_393 -> V_393 ) {
F_141 ( V_393 ) ;
V_393 = NULL ;
goto V_60;
}
memset ( V_393 -> V_393 , 0 , V_403 * sizeof( T_2 ) ) ;
if ( V_399 ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < 32 ; ++ V_37 )
V_393 -> V_393 [ V_37 ] = V_404 ;
}
V_400 [ V_13 ] = V_393 ;
F_300 ( V_13 , V_393 ) ;
F_92 ( V_32 , V_13 ) ;
if ( V_13 != V_20 ) {
V_400 [ V_20 ] = V_393 ;
F_300 ( V_20 , V_393 ) ;
F_92 ( V_32 , V_20 ) ;
}
V_60:
F_91 ( V_32 ) ;
V_19:
F_164 ( & V_259 , V_15 ) ;
return V_393 ;
}
static int F_303 ( T_1 V_13 , int V_99 )
{
struct V_392 * V_393 ;
unsigned long V_15 ;
int V_223 , V_405 ;
V_393 = F_301 ( V_13 , false ) ;
if ( ! V_393 )
return - V_406 ;
F_8 ( & V_393 -> V_180 , V_15 ) ;
for ( V_405 = 0 , V_223 = V_393 -> V_401 ;
V_223 < V_403 ;
++ V_223 ) {
if ( V_393 -> V_393 [ V_223 ] == 0 )
V_405 += 1 ;
else
V_405 = 0 ;
if ( V_405 == V_99 ) {
for (; V_405 != 0 ; -- V_405 )
V_393 -> V_393 [ V_223 - V_405 + 1 ] = V_404 ;
V_223 -= V_99 - 1 ;
goto V_60;
}
}
V_223 = - V_407 ;
V_60:
F_10 ( & V_393 -> V_180 , V_15 ) ;
return V_223 ;
}
static int F_304 ( T_1 V_13 , int V_223 , union V_408 V_408 )
{
struct V_392 * V_393 ;
struct V_63 * V_32 ;
unsigned long V_15 ;
V_32 = V_25 [ V_13 ] ;
if ( V_32 == NULL )
return - V_211 ;
V_393 = F_301 ( V_13 , false ) ;
if ( ! V_393 )
return - V_62 ;
F_8 ( & V_393 -> V_180 , V_15 ) ;
V_393 -> V_393 [ V_223 ] = V_408 . V_409 ;
F_10 ( & V_393 -> V_180 , V_15 ) ;
F_96 ( V_32 , V_13 ) ;
F_91 ( V_32 ) ;
return 0 ;
}
static void F_305 ( T_1 V_13 , int V_223 )
{
struct V_392 * V_393 ;
struct V_63 * V_32 ;
unsigned long V_15 ;
V_32 = V_25 [ V_13 ] ;
if ( V_32 == NULL )
return;
V_393 = F_301 ( V_13 , false ) ;
if ( ! V_393 )
return;
F_8 ( & V_393 -> V_180 , V_15 ) ;
V_393 -> V_393 [ V_223 ] = 0 ;
F_10 ( & V_393 -> V_180 , V_15 ) ;
F_96 ( V_32 , V_13 ) ;
F_91 ( V_32 ) ;
}
static int F_306 ( struct V_410 * V_382 )
{
int V_13 = - 1 ;
switch ( V_382 -> type ) {
case V_411 :
V_13 = F_307 ( V_382 -> V_412 ) ;
break;
case V_413 :
V_13 = F_308 ( V_382 -> V_414 ) ;
break;
case V_415 :
case V_416 :
V_13 = F_3 ( & V_382 -> V_417 -> V_6 ) ;
break;
default:
F_113 ( 1 ) ;
break;
}
return V_13 ;
}
static struct V_418 * F_309 ( struct V_410 * V_382 )
{
struct V_63 * V_32 ;
int V_13 ;
if ( ! V_382 )
return NULL ;
V_13 = F_306 ( V_382 ) ;
if ( V_13 >= 0 ) {
V_32 = V_25 [ V_13 ] ;
if ( V_32 )
return V_32 -> V_419 ;
}
return NULL ;
}
static struct V_418 * F_310 ( struct V_410 * V_382 )
{
struct V_63 * V_32 ;
int V_13 ;
if ( ! V_382 )
return NULL ;
switch ( V_382 -> type ) {
case V_415 :
case V_416 :
V_13 = F_3 ( & V_382 -> V_417 -> V_6 ) ;
V_32 = V_25 [ V_13 ] ;
if ( V_32 )
return V_32 -> V_420 ;
break;
default:
break;
}
return NULL ;
}
static void F_311 ( struct V_421 * V_21 ,
struct V_422 * V_422 ,
struct V_410 * V_382 ,
int V_13 , int V_223 , int V_423 )
{
struct V_424 * V_425 = & V_21 -> V_424 ;
struct V_426 * V_427 = & V_21 -> V_428 ;
union V_408 * V_408 = & V_21 -> V_429 ;
struct V_430 * V_139 ;
V_21 -> V_424 . V_13 = V_13 ;
V_21 -> V_424 . V_223 = V_223 + V_423 ;
V_408 -> V_409 = 0 ;
V_408 -> V_431 . V_432 = V_422 -> V_432 ;
V_408 -> V_431 . V_433 = V_434 -> V_435 ;
V_408 -> V_431 . V_436 = V_422 -> V_437 ;
V_408 -> V_431 . V_438 = V_434 -> V_439 ;
V_408 -> V_431 . V_440 = 1 ;
switch ( V_382 -> type ) {
case V_411 :
V_139 = V_382 -> V_441 ;
V_382 -> V_441 = NULL ;
memset ( V_139 , 0 , sizeof( * V_139 ) ) ;
V_139 -> V_432 = V_223 ;
V_139 -> V_249 = 0 ;
V_139 -> V_442 = V_382 -> V_443 ;
V_139 -> V_444 = V_382 -> V_445 ;
if ( V_382 -> V_443 )
V_139 -> V_249 = 1 ;
break;
case V_413 :
case V_415 :
case V_416 :
V_427 -> V_446 = V_447 ;
V_427 -> V_448 = V_238 ;
V_427 -> V_21 = V_425 -> V_223 ;
break;
default:
F_113 ( 1 ) ;
break;
}
}
static int F_312 ( struct V_418 * V_4 , unsigned int V_449 ,
unsigned int V_450 , void * V_451 )
{
struct V_410 * V_382 = V_451 ;
struct V_452 * V_452 ;
struct V_421 * V_21 ;
struct V_422 * V_453 ;
int V_37 , V_183 , V_13 ;
int V_223 = - 1 ;
if ( ! V_382 )
return - V_211 ;
if ( V_450 > 1 && V_382 -> type != V_415 &&
V_382 -> type != V_416 )
return - V_211 ;
if ( V_382 -> type == V_415 )
V_382 -> V_15 &= ~ V_454 ;
V_13 = F_306 ( V_382 ) ;
if ( V_13 < 0 )
return - V_211 ;
V_183 = F_313 ( V_4 , V_449 , V_450 , V_451 ) ;
if ( V_183 < 0 )
return V_183 ;
if ( V_382 -> type == V_411 ) {
if ( F_301 ( V_13 , true ) )
V_223 = V_382 -> V_455 ;
else
V_183 = - V_62 ;
} else {
V_223 = F_303 ( V_13 , V_450 ) ;
}
if ( V_223 < 0 ) {
F_314 ( L_34 ) ;
goto V_456;
}
for ( V_37 = 0 ; V_37 < V_450 ; V_37 ++ ) {
V_452 = F_315 ( V_4 , V_449 + V_37 ) ;
V_453 = F_316 ( V_452 ) ;
if ( ! V_452 || ! V_453 ) {
V_183 = - V_211 ;
goto V_457;
}
V_183 = - V_62 ;
V_21 = F_7 ( sizeof( * V_21 ) , V_16 ) ;
if ( ! V_21 )
goto V_457;
V_452 -> V_458 = ( V_13 << 16 ) + V_37 ;
V_452 -> V_459 = V_21 ;
V_452 -> V_460 = & V_461 ;
F_311 ( V_21 , V_453 , V_382 , V_13 , V_223 , V_37 ) ;
F_317 ( V_449 + V_37 , V_462 ) ;
}
return 0 ;
V_457:
for ( V_37 -- ; V_37 >= 0 ; V_37 -- ) {
V_452 = F_315 ( V_4 , V_449 + V_37 ) ;
if ( V_452 )
F_141 ( V_452 -> V_459 ) ;
}
for ( V_37 = 0 ; V_37 < V_450 ; V_37 ++ )
F_305 ( V_13 , V_223 + V_37 ) ;
V_456:
F_318 ( V_4 , V_449 , V_450 ) ;
return V_183 ;
}
static void F_319 ( struct V_418 * V_4 , unsigned int V_449 ,
unsigned int V_450 )
{
struct V_424 * V_425 ;
struct V_452 * V_452 ;
struct V_421 * V_21 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_450 ; V_37 ++ ) {
V_452 = F_315 ( V_4 , V_449 + V_37 ) ;
if ( V_452 && V_452 -> V_459 ) {
V_21 = V_452 -> V_459 ;
V_425 = & V_21 -> V_424 ;
F_305 ( V_425 -> V_13 , V_425 -> V_223 ) ;
F_141 ( V_21 ) ;
}
}
F_318 ( V_4 , V_449 , V_450 ) ;
}
static void F_320 ( struct V_418 * V_4 ,
struct V_452 * V_452 )
{
struct V_421 * V_21 = V_452 -> V_459 ;
struct V_424 * V_425 = & V_21 -> V_424 ;
F_304 ( V_425 -> V_13 , V_425 -> V_223 , V_21 -> V_429 ) ;
}
static void F_321 ( struct V_418 * V_4 ,
struct V_452 * V_452 )
{
struct V_421 * V_21 = V_452 -> V_459 ;
struct V_424 * V_425 = & V_21 -> V_424 ;
union V_408 V_139 ;
V_139 . V_409 = 0 ;
F_304 ( V_425 -> V_13 , V_425 -> V_223 , V_21 -> V_429 ) ;
}
static int F_322 ( struct V_452 * V_21 ,
const struct V_463 * V_249 , bool V_464 )
{
struct V_421 * V_465 = V_21 -> V_459 ;
struct V_424 * V_425 = & V_465 -> V_424 ;
struct V_422 * V_453 = F_316 ( V_21 ) ;
struct V_452 * V_466 = V_21 -> V_467 ;
int V_183 ;
V_183 = V_466 -> V_460 -> V_468 ( V_466 , V_249 , V_464 ) ;
if ( V_183 < 0 || V_183 == V_469 )
return V_183 ;
V_465 -> V_429 . V_431 . V_432 = V_453 -> V_432 ;
V_465 -> V_429 . V_431 . V_436 = V_453 -> V_437 ;
F_304 ( V_425 -> V_13 , V_425 -> V_223 , V_465 -> V_429 ) ;
F_323 ( V_453 ) ;
return V_469 ;
}
static void F_324 ( struct V_452 * V_452 , struct V_426 * V_427 )
{
struct V_421 * V_465 = V_452 -> V_459 ;
* V_427 = V_465 -> V_428 ;
}
int F_325 ( struct V_63 * V_32 )
{
V_32 -> V_419 = F_326 ( NULL , & V_470 , V_32 ) ;
if ( ! V_32 -> V_419 )
return - V_62 ;
V_32 -> V_419 -> V_466 = F_327 () ;
V_32 -> V_420 = F_328 ( V_32 -> V_419 ) ;
return 0 ;
}
