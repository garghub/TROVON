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
V_7 -> V_6 = V_6 ;
F_5 ( & V_10 , V_8 ) ;
F_6 ( & V_7 -> V_11 , & V_11 ) ;
F_7 ( & V_10 , V_8 ) ;
return V_7 ;
}
static struct V_5 * F_8 ( T_1 V_6 )
{
struct V_5 * V_7 ;
unsigned long V_8 ;
F_5 ( & V_10 , V_8 ) ;
F_9 (dev_data, &dev_data_list, dev_data_list) {
if ( V_7 -> V_6 == V_6 )
goto V_12;
}
V_7 = NULL ;
V_12:
F_7 ( & V_10 , V_8 ) ;
return V_7 ;
}
static struct V_5 * F_10 ( T_1 V_6 )
{
struct V_5 * V_7 ;
V_7 = F_8 ( V_6 ) ;
if ( V_7 == NULL )
V_7 = F_3 ( V_6 ) ;
return V_7 ;
}
static inline T_1 F_11 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
return F_13 ( V_16 -> V_17 -> V_18 , V_16 -> V_19 ) ;
}
static struct V_5 * F_14 ( struct V_13 * V_14 )
{
return V_14 -> V_20 . V_21 ;
}
static bool F_15 ( struct V_15 * V_16 )
{
static const int V_22 [] = {
V_23 ,
V_24 ,
V_25 ,
} ;
int V_26 , V_27 ;
for ( V_26 = 0 ; V_26 < 3 ; ++ V_26 ) {
V_27 = F_16 ( V_16 , V_22 [ V_26 ] ) ;
if ( V_27 == 0 )
return false ;
}
return true ;
}
static bool F_17 ( struct V_15 * V_16 , T_2 V_28 )
{
struct V_5 * V_7 ;
V_7 = F_14 ( & V_16 -> V_14 ) ;
return V_7 -> V_29 & ( 1 << V_28 ) ? true : false ;
}
static void F_18 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
T_3 V_34 ;
for ( V_34 = V_33 -> V_35 ; V_34 < V_33 -> V_36 ;
V_34 += V_37 ) {
if ( V_34 < V_31 -> V_38 )
F_19 ( V_34 >> V_39 ,
V_31 -> V_40 [ 0 ] -> V_41 ) ;
}
}
static void F_20 ( struct V_13 * V_14 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 ;
T_1 V_6 ;
V_6 = F_11 ( V_14 ) ;
F_9 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_6 >= V_33 -> V_42 && V_6 <= V_33 -> V_43 ) )
continue;
F_18 ( V_31 , V_33 ) ;
}
}
static bool F_21 ( struct V_13 * V_14 )
{
T_1 V_6 ;
if ( ! V_14 || ! V_14 -> V_44 )
return false ;
if ( ! F_22 ( V_14 ) )
return false ;
V_6 = F_11 ( V_14 ) ;
if ( V_6 > V_45 )
return false ;
if ( V_46 [ V_6 ] == NULL )
return false ;
return true ;
}
static void F_23 ( struct V_13 * V_14 )
{
struct V_30 * V_47 ;
struct V_2 * V_4 ;
struct V_48 * V_49 ;
V_49 = F_24 ( V_14 ) ;
if ( F_25 ( V_49 ) )
return;
V_4 = F_26 ( V_49 ) ;
if ( ! V_4 )
goto V_50;
V_47 = F_1 ( V_4 ) -> V_51 ;
F_20 ( V_14 , V_47 ) ;
V_50:
F_27 ( V_49 ) ;
}
static int F_28 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_5 * V_7 ;
if ( V_14 -> V_20 . V_21 )
return 0 ;
V_7 = F_10 ( F_11 ( V_14 ) ) ;
if ( ! V_7 )
return - V_52 ;
if ( F_15 ( V_16 ) ) {
struct V_53 * V_21 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
V_7 -> V_54 = V_21 -> V_55 ;
}
V_14 -> V_20 . V_21 = V_7 ;
F_29 ( V_46 [ V_7 -> V_6 ] -> V_56 ,
V_14 ) ;
return 0 ;
}
static void F_30 ( struct V_13 * V_14 )
{
T_1 V_6 , V_57 ;
V_6 = F_11 ( V_14 ) ;
V_57 = V_58 [ V_6 ] ;
memset ( & V_59 [ V_6 ] , 0 , sizeof( struct V_60 ) ) ;
memset ( & V_59 [ V_57 ] , 0 , sizeof( struct V_60 ) ) ;
V_46 [ V_6 ] = NULL ;
V_46 [ V_57 ] = NULL ;
}
static void F_31 ( struct V_13 * V_14 )
{
struct V_5 * V_7 = F_8 ( F_11 ( V_14 ) ) ;
if ( ! V_7 )
return;
F_32 ( V_46 [ V_7 -> V_6 ] -> V_56 ,
V_14 ) ;
F_33 ( V_14 ) ;
V_14 -> V_20 . V_61 = NULL ;
}
static void F_34 ( struct V_62 * V_63 )
{
if ( V_64 == NULL )
return;
V_63 -> V_65 = F_35 ( V_63 -> V_66 , 0444 , V_64 ,
& V_63 -> V_67 ) ;
}
static void F_36 ( void )
{
V_64 = F_37 ( L_1 , NULL ) ;
if ( V_64 == NULL )
return;
V_68 = F_38 ( L_2 , 0444 , V_64 ,
& V_69 ) ;
F_34 ( & V_70 ) ;
F_34 ( & V_71 ) ;
F_34 ( & V_72 ) ;
F_34 ( & V_73 ) ;
F_34 ( & V_74 ) ;
F_34 ( & V_75 ) ;
F_34 ( & V_76 ) ;
F_34 ( & V_77 ) ;
F_34 ( & V_78 ) ;
F_34 ( & V_79 ) ;
F_34 ( & V_80 ) ;
F_34 ( & V_81 ) ;
F_34 ( & V_82 ) ;
F_34 ( & V_83 ) ;
F_34 ( & V_84 ) ;
F_34 ( & V_85 ) ;
}
static void F_39 ( T_1 V_6 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 )
F_40 ( L_3 , V_26 ,
V_59 [ V_6 ] . V_86 [ V_26 ] ) ;
}
static void F_41 ( unsigned long V_87 )
{
struct V_88 * V_89 = F_42 ( V_87 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 )
F_40 ( L_4 , V_26 , V_89 -> V_86 [ V_26 ] ) ;
}
static void F_43 ( struct V_53 * V_21 , void * V_90 )
{
int type , V_6 , V_91 , V_8 ;
volatile T_2 * V_92 = V_90 ;
int V_93 = 0 ;
T_3 V_94 ;
V_95:
type = ( V_92 [ 1 ] >> V_96 ) & V_97 ;
V_6 = ( V_92 [ 0 ] >> V_98 ) & V_99 ;
V_91 = ( V_92 [ 1 ] >> V_100 ) & V_101 ;
V_8 = ( V_92 [ 1 ] >> V_102 ) & V_103 ;
V_94 = ( T_3 ) ( ( ( T_3 ) V_92 [ 3 ] ) << 32 ) | V_92 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_93 == V_104 ) {
F_40 ( L_5 ) ;
return;
}
F_44 ( 1 ) ;
goto V_95;
}
F_45 ( V_105 L_6 ) ;
switch ( type ) {
case V_106 :
F_45 ( L_7
L_8 ,
F_46 ( V_6 ) , F_47 ( V_6 ) , F_48 ( V_6 ) ,
V_94 , V_8 ) ;
F_39 ( V_6 ) ;
break;
case V_107 :
F_45 ( L_9
L_10 ,
F_46 ( V_6 ) , F_47 ( V_6 ) , F_48 ( V_6 ) ,
V_91 , V_94 , V_8 ) ;
break;
case V_108 :
F_45 ( L_11
L_8 ,
F_46 ( V_6 ) , F_47 ( V_6 ) , F_48 ( V_6 ) ,
V_94 , V_8 ) ;
break;
case V_109 :
F_45 ( L_12
L_10 ,
F_46 ( V_6 ) , F_47 ( V_6 ) , F_48 ( V_6 ) ,
V_91 , V_94 , V_8 ) ;
break;
case V_110 :
F_45 ( L_13 , V_94 ) ;
F_41 ( V_94 ) ;
break;
case V_111 :
F_45 ( L_14
L_15 , V_94 , V_8 ) ;
break;
case V_112 :
F_45 ( L_16
L_17 ,
F_46 ( V_6 ) , F_47 ( V_6 ) , F_48 ( V_6 ) ,
V_94 ) ;
break;
case V_113 :
F_45 ( L_18
L_8 ,
F_46 ( V_6 ) , F_47 ( V_6 ) , F_48 ( V_6 ) ,
V_94 , V_8 ) ;
break;
default:
F_45 ( V_105 L_19 , type ) ;
}
memset ( V_90 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_49 ( struct V_53 * V_21 )
{
T_2 V_114 , V_115 ;
V_114 = F_50 ( V_21 -> V_116 + V_117 ) ;
V_115 = F_50 ( V_21 -> V_116 + V_118 ) ;
while ( V_114 != V_115 ) {
F_43 ( V_21 , V_21 -> V_119 + V_114 ) ;
V_114 = ( V_114 + V_120 ) % V_121 ;
}
F_51 ( V_114 , V_21 -> V_116 + V_117 ) ;
}
static void F_52 ( struct V_53 * V_21 , T_3 * V_122 )
{
struct V_123 V_124 ;
F_53 ( V_85 ) ;
if ( F_54 ( V_122 [ 0 ] ) != V_125 ) {
F_55 ( L_20 ) ;
return;
}
V_124 . V_94 = V_122 [ 1 ] ;
V_124 . V_126 = F_56 ( V_122 [ 0 ] ) ;
V_124 . V_127 = F_57 ( V_122 [ 0 ] ) ;
V_124 . V_128 = F_58 ( V_122 [ 0 ] ) ;
V_124 . V_8 = F_59 ( V_122 [ 0 ] ) ;
F_60 ( & V_129 , 0 , & V_124 ) ;
}
static void F_61 ( struct V_53 * V_21 )
{
T_2 V_114 , V_115 ;
if ( V_21 -> V_130 == NULL )
return;
V_114 = F_50 ( V_21 -> V_116 + V_131 ) ;
V_115 = F_50 ( V_21 -> V_116 + V_132 ) ;
while ( V_114 != V_115 ) {
volatile T_3 * V_122 ;
T_3 V_133 [ 2 ] ;
int V_26 ;
V_122 = ( T_3 * ) ( V_21 -> V_130 + V_114 ) ;
for ( V_26 = 0 ; V_26 < V_104 ; ++ V_26 ) {
if ( F_54 ( V_122 [ 0 ] ) != 0 )
break;
F_44 ( 1 ) ;
}
V_133 [ 0 ] = V_122 [ 0 ] ;
V_133 [ 1 ] = V_122 [ 1 ] ;
V_122 [ 0 ] = V_122 [ 1 ] = 0UL ;
V_114 = ( V_114 + V_134 ) % V_135 ;
F_51 ( V_114 , V_21 -> V_116 + V_131 ) ;
F_52 ( V_21 , V_133 ) ;
V_114 = F_50 ( V_21 -> V_116 + V_131 ) ;
V_115 = F_50 ( V_21 -> V_116 + V_132 ) ;
}
}
T_4 F_62 ( int V_136 , void * V_86 )
{
struct V_53 * V_21 = (struct V_53 * ) V_86 ;
T_2 V_137 = F_50 ( V_21 -> V_116 + V_138 ) ;
while ( V_137 & ( V_139 | V_140 ) ) {
F_51 ( ( V_139 | V_140 ) ,
V_21 -> V_116 + V_138 ) ;
if ( V_137 & V_139 ) {
F_63 ( L_21 ) ;
F_49 ( V_21 ) ;
}
if ( V_137 & V_140 ) {
F_63 ( L_22 ) ;
F_61 ( V_21 ) ;
}
V_137 = F_50 ( V_21 -> V_116 + V_138 ) ;
}
return V_141 ;
}
T_4 F_64 ( int V_136 , void * V_86 )
{
return V_142 ;
}
static int F_65 ( volatile T_3 * V_143 )
{
int V_26 = 0 ;
while ( * V_143 == 0 && V_26 < V_104 ) {
F_44 ( 1 ) ;
V_26 += 1 ;
}
if ( V_26 == V_104 ) {
F_66 ( L_23 ) ;
return - V_144 ;
}
return 0 ;
}
static void F_67 ( struct V_53 * V_21 ,
struct V_88 * V_89 ,
T_2 V_115 )
{
T_5 * V_145 ;
V_145 = V_21 -> V_146 + V_115 ;
V_115 = ( V_115 + sizeof( * V_89 ) ) % V_147 ;
memcpy ( V_145 , V_89 , sizeof( * V_89 ) ) ;
F_51 ( V_115 , V_21 -> V_116 + V_148 ) ;
}
static void F_68 ( struct V_88 * V_89 , T_3 V_94 )
{
F_69 ( V_94 & 0x7ULL ) ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = F_70 ( F_71 ( V_94 ) ) | V_149 ;
V_89 -> V_86 [ 1 ] = F_72 ( F_71 ( V_94 ) ) ;
V_89 -> V_86 [ 2 ] = 1 ;
F_73 ( V_89 , V_150 ) ;
}
static void F_74 ( struct V_88 * V_89 , T_1 V_6 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_6 ;
F_73 ( V_89 , V_151 ) ;
}
static void F_75 ( struct V_88 * V_89 , T_3 V_94 ,
T_6 V_152 , T_1 V_91 , int V_153 )
{
T_3 V_154 ;
bool V_155 ;
V_154 = F_76 ( V_94 , V_152 , V_37 ) ;
V_155 = false ;
if ( V_154 > 1 ) {
V_94 = V_156 ;
V_155 = true ;
}
V_94 &= V_157 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 1 ] |= V_91 ;
V_89 -> V_86 [ 2 ] = F_70 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_72 ( V_94 ) ;
F_73 ( V_89 , V_158 ) ;
if ( V_155 )
V_89 -> V_86 [ 2 ] |= V_159 ;
if ( V_153 )
V_89 -> V_86 [ 2 ] |= V_160 ;
}
static void F_77 ( struct V_88 * V_89 , T_1 V_6 , int V_161 ,
T_3 V_94 , T_6 V_152 )
{
T_3 V_154 ;
bool V_155 ;
V_154 = F_76 ( V_94 , V_152 , V_37 ) ;
V_155 = false ;
if ( V_154 > 1 ) {
V_94 = V_156 ;
V_155 = true ;
}
V_94 &= V_157 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_6 ;
V_89 -> V_86 [ 0 ] |= ( V_161 & 0xff ) << 24 ;
V_89 -> V_86 [ 1 ] = V_6 ;
V_89 -> V_86 [ 2 ] = F_70 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_72 ( V_94 ) ;
F_73 ( V_89 , V_162 ) ;
if ( V_155 )
V_89 -> V_86 [ 2 ] |= V_159 ;
}
static void F_78 ( struct V_88 * V_89 , T_1 V_91 , int V_126 ,
T_3 V_94 , bool V_152 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_94 &= ~ ( 0xfffULL ) ;
V_89 -> V_86 [ 0 ] = V_126 ;
V_89 -> V_86 [ 1 ] = V_91 ;
V_89 -> V_86 [ 2 ] = F_70 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_72 ( V_94 ) ;
V_89 -> V_86 [ 2 ] |= V_160 ;
V_89 -> V_86 [ 2 ] |= V_163 ;
if ( V_152 )
V_89 -> V_86 [ 2 ] |= V_159 ;
F_73 ( V_89 , V_158 ) ;
}
static void F_79 ( struct V_88 * V_89 , T_1 V_6 , int V_126 ,
int V_161 , T_3 V_94 , bool V_152 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_94 &= ~ ( 0xfffULL ) ;
V_89 -> V_86 [ 0 ] = V_6 ;
V_89 -> V_86 [ 0 ] |= ( ( V_126 >> 8 ) & 0xff ) << 16 ;
V_89 -> V_86 [ 0 ] |= ( V_161 & 0xff ) << 24 ;
V_89 -> V_86 [ 1 ] = V_6 ;
V_89 -> V_86 [ 1 ] |= ( V_126 & 0xff ) << 16 ;
V_89 -> V_86 [ 2 ] = F_70 ( V_94 ) ;
V_89 -> V_86 [ 2 ] |= V_163 ;
V_89 -> V_86 [ 3 ] = F_72 ( V_94 ) ;
if ( V_152 )
V_89 -> V_86 [ 2 ] |= V_159 ;
F_73 ( V_89 , V_162 ) ;
}
static void F_80 ( struct V_88 * V_89 , T_1 V_6 , int V_126 ,
int V_137 , int V_128 , bool V_164 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_6 ;
if ( V_164 ) {
V_89 -> V_86 [ 1 ] = V_126 ;
V_89 -> V_86 [ 2 ] = V_163 ;
}
V_89 -> V_86 [ 3 ] = V_128 & 0x1ff ;
V_89 -> V_86 [ 3 ] |= ( V_137 & V_165 ) << V_166 ;
F_73 ( V_89 , V_167 ) ;
}
static void F_81 ( struct V_88 * V_89 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
F_73 ( V_89 , V_168 ) ;
}
static void F_82 ( struct V_88 * V_89 , T_1 V_6 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_6 ;
F_73 ( V_89 , V_169 ) ;
}
static int F_83 ( struct V_53 * V_21 ,
struct V_88 * V_89 ,
bool V_170 )
{
T_2 V_171 , V_115 , V_114 , V_172 ;
unsigned long V_8 ;
V_173:
F_5 ( & V_21 -> V_174 , V_8 ) ;
V_114 = F_50 ( V_21 -> V_116 + V_175 ) ;
V_115 = F_50 ( V_21 -> V_116 + V_148 ) ;
V_172 = ( V_115 + sizeof( * V_89 ) ) % V_147 ;
V_171 = ( V_114 - V_172 ) % V_147 ;
if ( V_171 <= 2 ) {
struct V_88 V_176 ;
volatile T_3 V_143 = 0 ;
int V_177 ;
F_68 ( & V_176 , ( T_3 ) & V_143 ) ;
F_67 ( V_21 , & V_176 , V_115 ) ;
F_7 ( & V_21 -> V_174 , V_8 ) ;
if ( ( V_177 = F_65 ( & V_143 ) ) != 0 )
return V_177 ;
goto V_173;
}
F_67 ( V_21 , V_89 , V_115 ) ;
V_21 -> V_178 = V_170 ;
F_7 ( & V_21 -> V_174 , V_8 ) ;
return 0 ;
}
static int F_84 ( struct V_53 * V_21 , struct V_88 * V_89 )
{
return F_83 ( V_21 , V_89 , true ) ;
}
static int F_85 ( struct V_53 * V_21 )
{
struct V_88 V_89 ;
volatile T_3 V_143 = 0 ;
int V_177 ;
if ( ! V_21 -> V_178 )
return 0 ;
F_68 ( & V_89 , ( T_3 ) & V_143 ) ;
V_177 = F_83 ( V_21 , & V_89 , false ) ;
if ( V_177 )
return V_177 ;
return F_65 ( & V_143 ) ;
}
static int F_86 ( struct V_53 * V_21 , T_1 V_6 )
{
struct V_88 V_89 ;
F_74 ( & V_89 , V_6 ) ;
return F_84 ( V_21 , & V_89 ) ;
}
static void F_87 ( struct V_53 * V_21 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 <= 0xffff ; ++ V_6 )
F_86 ( V_21 , V_6 ) ;
F_85 ( V_21 ) ;
}
static void F_88 ( struct V_53 * V_21 )
{
T_2 V_179 ;
for ( V_179 = 0 ; V_179 <= 0xffff ; ++ V_179 ) {
struct V_88 V_89 ;
F_75 ( & V_89 , 0 , V_156 ,
V_179 , 1 ) ;
F_84 ( V_21 , & V_89 ) ;
}
F_85 ( V_21 ) ;
}
static void F_89 ( struct V_53 * V_21 )
{
struct V_88 V_89 ;
F_81 ( & V_89 ) ;
F_84 ( V_21 , & V_89 ) ;
F_85 ( V_21 ) ;
}
static void F_90 ( struct V_53 * V_21 , T_1 V_6 )
{
struct V_88 V_89 ;
F_82 ( & V_89 , V_6 ) ;
F_84 ( V_21 , & V_89 ) ;
}
static void F_91 ( struct V_53 * V_21 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 <= V_180 ; V_6 ++ )
F_90 ( V_21 , V_6 ) ;
F_85 ( V_21 ) ;
}
void F_92 ( struct V_53 * V_21 )
{
if ( F_93 ( V_21 , V_181 ) ) {
F_89 ( V_21 ) ;
} else {
F_87 ( V_21 ) ;
F_91 ( V_21 ) ;
F_88 ( V_21 ) ;
}
}
static int F_94 ( struct V_5 * V_7 ,
T_3 V_94 , T_6 V_152 )
{
struct V_53 * V_21 ;
struct V_88 V_89 ;
int V_161 ;
V_161 = V_7 -> V_182 . V_161 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
F_77 ( & V_89 , V_7 -> V_6 , V_161 , V_94 , V_152 ) ;
return F_84 ( V_21 , & V_89 ) ;
}
static int F_95 ( struct V_5 * V_7 )
{
struct V_53 * V_21 ;
T_1 V_57 ;
int V_177 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
V_57 = V_58 [ V_7 -> V_6 ] ;
V_177 = F_86 ( V_21 , V_7 -> V_6 ) ;
if ( ! V_177 && V_57 != V_7 -> V_6 )
V_177 = F_86 ( V_21 , V_57 ) ;
if ( V_177 )
return V_177 ;
if ( V_7 -> V_182 . V_183 )
V_177 = F_94 ( V_7 , 0 , ~ 0UL ) ;
return V_177 ;
}
static void F_96 ( struct V_1 * V_4 ,
T_3 V_94 , T_6 V_152 , int V_153 )
{
struct V_5 * V_7 ;
struct V_88 V_89 ;
int V_177 = 0 , V_26 ;
F_75 ( & V_89 , V_94 , V_152 , V_4 -> V_184 , V_153 ) ;
for ( V_26 = 0 ; V_26 < V_185 ; ++ V_26 ) {
if ( ! V_4 -> V_186 [ V_26 ] )
continue;
V_177 |= F_84 ( V_187 [ V_26 ] , & V_89 ) ;
}
F_9 (dev_data, &domain->dev_list, list) {
if ( ! V_7 -> V_182 . V_183 )
continue;
V_177 |= F_94 ( V_7 , V_94 , V_152 ) ;
}
F_69 ( V_177 ) ;
}
static void F_97 ( struct V_1 * V_4 ,
T_3 V_94 , T_6 V_152 )
{
F_96 ( V_4 , V_94 , V_152 , 0 ) ;
}
static void F_98 ( struct V_1 * V_4 )
{
F_96 ( V_4 , 0 , V_156 , 0 ) ;
}
static void F_99 ( struct V_1 * V_4 )
{
F_96 ( V_4 , 0 , V_156 , 1 ) ;
}
static void F_100 ( struct V_1 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_185 ; ++ V_26 ) {
if ( ! V_4 -> V_186 [ V_26 ] )
continue;
F_85 ( V_187 [ V_26 ] ) ;
}
}
static void F_101 ( struct V_1 * V_4 )
{
struct V_5 * V_7 ;
F_9 (dev_data, &domain->dev_list, list)
F_95 ( V_7 ) ;
}
static bool F_102 ( struct V_1 * V_4 ,
T_7 V_188 )
{
T_3 * V_189 ;
if ( V_4 -> V_190 == V_191 )
return false ;
V_189 = ( void * ) F_103 ( V_188 ) ;
if ( ! V_189 )
return false ;
* V_189 = F_104 ( V_4 -> V_190 ,
F_105 ( V_4 -> V_192 ) ) ;
V_4 -> V_192 = V_189 ;
V_4 -> V_190 += 1 ;
V_4 -> V_193 = true ;
return true ;
}
static T_3 * F_106 ( struct V_1 * V_4 ,
unsigned long V_94 ,
unsigned long V_194 ,
T_3 * * V_195 ,
T_7 V_188 )
{
int V_196 , V_197 ;
T_3 * V_189 , * V_198 ;
F_107 ( ! F_108 ( V_194 ) ) ;
while ( V_94 > F_109 ( V_4 -> V_190 ) )
F_102 ( V_4 , V_188 ) ;
V_196 = V_4 -> V_190 - 1 ;
V_189 = & V_4 -> V_192 [ F_110 ( V_196 , V_94 ) ] ;
V_94 = F_111 ( V_94 , V_194 ) ;
V_197 = F_112 ( V_194 ) ;
while ( V_196 > V_197 ) {
if ( ! F_113 ( * V_189 ) ) {
V_198 = ( T_3 * ) F_103 ( V_188 ) ;
if ( ! V_198 )
return NULL ;
* V_189 = F_104 ( V_196 , F_105 ( V_198 ) ) ;
}
if ( F_114 ( * V_189 ) != V_196 )
return NULL ;
V_196 -= 1 ;
V_189 = F_115 ( * V_189 ) ;
if ( V_195 && V_196 == V_197 )
* V_195 = V_189 ;
V_189 = & V_189 [ F_110 ( V_196 , V_94 ) ] ;
}
return V_189 ;
}
static T_3 * F_116 ( struct V_1 * V_4 ,
unsigned long V_94 ,
unsigned long * V_194 )
{
int V_196 ;
T_3 * V_189 ;
if ( V_94 > F_109 ( V_4 -> V_190 ) )
return NULL ;
V_196 = V_4 -> V_190 - 1 ;
V_189 = & V_4 -> V_192 [ F_110 ( V_196 , V_94 ) ] ;
* V_194 = F_117 ( V_196 ) ;
while ( V_196 > 0 ) {
if ( ! F_113 ( * V_189 ) )
return NULL ;
if ( F_114 ( * V_189 ) == 7 ||
F_114 ( * V_189 ) == 0 )
break;
if ( F_114 ( * V_189 ) != V_196 )
return NULL ;
V_196 -= 1 ;
V_189 = F_115 ( * V_189 ) ;
V_189 = & V_189 [ F_110 ( V_196 , V_94 ) ] ;
* V_194 = F_117 ( V_196 ) ;
}
if ( F_114 ( * V_189 ) == 0x07 ) {
unsigned long V_199 ;
* V_194 = V_199 = F_118 ( * V_189 ) ;
V_199 = ~ ( ( F_119 ( V_199 ) << 3 ) - 1 ) ;
V_189 = ( T_3 * ) ( ( ( unsigned long ) V_189 ) & V_199 ) ;
}
return V_189 ;
}
static int F_120 ( struct V_1 * V_3 ,
unsigned long V_200 ,
unsigned long V_87 ,
int V_201 ,
unsigned long V_194 )
{
T_3 V_202 , * V_189 ;
int V_26 , V_93 ;
F_107 ( ! F_121 ( V_200 , V_194 ) ) ;
F_107 ( ! F_121 ( V_87 , V_194 ) ) ;
if ( ! ( V_201 & V_203 ) )
return - V_204 ;
V_93 = F_119 ( V_194 ) ;
V_189 = F_106 ( V_3 , V_200 , V_194 , NULL , V_9 ) ;
if ( ! V_189 )
return - V_52 ;
for ( V_26 = 0 ; V_26 < V_93 ; ++ V_26 )
if ( F_113 ( V_189 [ V_26 ] ) )
return - V_205 ;
if ( V_93 > 1 ) {
V_202 = F_122 ( V_87 , V_194 ) ;
V_202 |= F_123 ( 7 ) | V_206 | V_207 ;
} else
V_202 = V_87 | V_206 | V_207 ;
if ( V_201 & V_208 )
V_202 |= V_209 ;
if ( V_201 & V_210 )
V_202 |= V_211 ;
for ( V_26 = 0 ; V_26 < V_93 ; ++ V_26 )
V_189 [ V_26 ] = V_202 ;
F_124 ( V_3 ) ;
return 0 ;
}
static unsigned long F_125 ( struct V_1 * V_3 ,
unsigned long V_200 ,
unsigned long V_194 )
{
unsigned long long V_212 ;
unsigned long V_213 ;
T_3 * V_189 ;
F_107 ( ! F_108 ( V_194 ) ) ;
V_212 = 0 ;
while ( V_212 < V_194 ) {
V_189 = F_116 ( V_3 , V_200 , & V_213 ) ;
if ( V_189 ) {
int V_26 , V_93 ;
V_93 = F_119 ( V_213 ) ;
for ( V_26 = 0 ; V_26 < V_93 ; V_26 ++ )
V_189 [ V_26 ] = 0ULL ;
}
V_200 = ( V_200 & ~ ( V_213 - 1 ) ) + V_213 ;
V_212 += V_213 ;
}
F_107 ( V_212 && ! F_108 ( V_212 ) ) ;
return V_212 ;
}
static void F_126 ( struct V_30 * V_3 ,
unsigned long V_214 ,
unsigned int V_154 )
{
unsigned int V_26 , V_215 = V_3 -> V_38 >> V_39 ;
if ( V_214 + V_154 > V_215 )
V_154 = V_215 - V_214 ;
for ( V_26 = V_214 ; V_26 < V_214 + V_154 ; ++ V_26 ) {
int V_216 = V_26 / V_217 ;
int V_198 = V_26 % V_217 ;
F_19 ( V_198 , V_3 -> V_40 [ V_216 ] -> V_41 ) ;
}
}
static int F_127 ( struct V_30 * V_31 ,
bool V_218 , T_7 V_188 )
{
int V_216 = V_31 -> V_38 >> V_219 ;
struct V_53 * V_21 ;
unsigned long V_26 , V_220 , V_221 ;
#ifdef F_128
V_218 = false ;
#endif
if ( V_216 >= V_222 )
return - V_52 ;
V_31 -> V_40 [ V_216 ] = F_4 ( sizeof( struct V_223 ) , V_188 ) ;
if ( ! V_31 -> V_40 [ V_216 ] )
return - V_52 ;
V_31 -> V_40 [ V_216 ] -> V_41 = ( void * ) F_103 ( V_188 ) ;
if ( ! V_31 -> V_40 [ V_216 ] -> V_41 )
goto V_224;
V_31 -> V_40 [ V_216 ] -> V_225 = V_31 -> V_38 ;
if ( V_218 ) {
unsigned long V_94 = V_31 -> V_38 ;
int V_26 , V_226 = V_217 / 512 ;
T_3 * V_189 , * V_195 ;
for ( V_26 = 0 ; V_26 < V_226 ; ++ V_26 ) {
V_189 = F_106 ( & V_31 -> V_4 , V_94 , V_37 ,
& V_195 , V_188 ) ;
if ( ! V_189 )
goto V_224;
V_31 -> V_40 [ V_216 ] -> V_227 [ V_26 ] = V_195 ;
V_94 += V_228 / 64 ;
}
}
V_220 = V_31 -> V_38 ;
V_31 -> V_38 += V_228 ;
if ( V_220 < V_229 &&
V_31 -> V_38 > V_229 ) {
unsigned long V_230 ;
int V_154 ;
V_154 = F_76 ( V_229 , 0x10000 , V_37 ) ;
V_230 = V_229 >> V_39 ;
F_126 ( V_31 , V_230 , V_154 ) ;
}
F_129 (iommu) {
if ( V_21 -> V_231 &&
V_21 -> V_231 >= V_31 -> V_40 [ V_216 ] -> V_225
&& V_21 -> V_231 < V_31 -> V_38 ) {
unsigned long V_232 ;
int V_154 = F_76 ( V_21 -> V_231 ,
V_21 -> V_233 ,
V_37 ) ;
V_232 = V_21 -> V_231 >> V_39 ;
F_126 ( V_31 , V_232 , V_154 ) ;
}
}
for ( V_26 = V_31 -> V_40 [ V_216 ] -> V_225 ;
V_26 < V_31 -> V_38 ;
V_26 += V_221 ) {
T_3 * V_189 = F_116 ( & V_31 -> V_4 , V_26 , & V_221 ) ;
if ( ! V_189 || ! F_113 ( * V_189 ) )
continue;
F_126 ( V_31 , V_26 >> V_39 ,
V_221 >> 12 ) ;
}
F_124 ( & V_31 -> V_4 ) ;
return 0 ;
V_224:
F_124 ( & V_31 -> V_4 ) ;
F_130 ( ( unsigned long ) V_31 -> V_40 [ V_216 ] -> V_41 ) ;
F_131 ( V_31 -> V_40 [ V_216 ] ) ;
V_31 -> V_40 [ V_216 ] = NULL ;
return - V_52 ;
}
static unsigned long F_132 ( struct V_13 * V_14 ,
struct V_30 * V_3 ,
unsigned int V_154 ,
unsigned long V_234 ,
T_3 V_44 ,
unsigned long V_235 )
{
unsigned long V_236 = V_3 -> V_237 % V_228 ;
int V_238 = V_3 -> V_38 >> V_219 ;
int V_26 = V_235 >> V_219 ;
unsigned long V_239 , V_240 ;
unsigned long V_94 = - 1 ;
unsigned long V_241 ;
V_236 >>= V_39 ;
V_240 = F_133 ( V_14 ) ;
V_239 = V_240 + 1 ? F_134 ( V_240 + 1 , V_37 ) >> V_39 :
1UL << ( V_242 - V_39 ) ;
for (; V_26 < V_238 ; ++ V_26 ) {
unsigned long V_225 = V_3 -> V_40 [ V_26 ] -> V_225 >> V_39 ;
if ( V_3 -> V_40 [ V_26 ] -> V_225 >= V_44 )
break;
V_241 = F_135 ( V_217 , V_225 ,
V_44 >> V_39 ) ;
V_94 = F_136 ( V_3 -> V_40 [ V_26 ] -> V_41 ,
V_241 , V_236 , V_154 , 0 ,
V_239 , V_234 ) ;
if ( V_94 != - 1 ) {
V_94 = V_3 -> V_40 [ V_26 ] -> V_225 +
( V_94 << V_39 ) ;
V_3 -> V_237 = V_94 + ( V_154 << V_39 ) ;
break;
}
V_236 = 0 ;
}
return V_94 ;
}
static unsigned long F_137 ( struct V_13 * V_14 ,
struct V_30 * V_3 ,
unsigned int V_154 ,
unsigned long V_234 ,
T_3 V_44 )
{
unsigned long V_94 ;
#ifdef F_128
V_3 -> V_237 = 0 ;
V_3 -> V_243 = true ;
#endif
V_94 = F_132 ( V_14 , V_3 , V_154 , V_234 ,
V_44 , V_3 -> V_237 ) ;
if ( V_94 == - 1 ) {
V_3 -> V_237 = 0 ;
V_94 = F_132 ( V_14 , V_3 , V_154 , V_234 ,
V_44 , 0 ) ;
V_3 -> V_243 = true ;
}
if ( F_138 ( V_94 == - 1 ) )
V_94 = V_244 ;
F_69 ( ( V_94 + ( V_37 * V_154 ) ) > V_3 -> V_38 ) ;
return V_94 ;
}
static void F_139 ( struct V_30 * V_3 ,
unsigned long V_94 ,
unsigned int V_154 )
{
unsigned V_26 = V_94 >> V_219 ;
struct V_223 * V_245 = V_3 -> V_40 [ V_26 ] ;
F_107 ( V_26 >= V_222 || V_245 == NULL ) ;
#ifdef F_128
if ( V_26 < 4 )
return;
#endif
if ( V_94 >= V_3 -> V_237 )
V_3 -> V_243 = true ;
V_94 = ( V_94 % V_228 ) >> V_39 ;
F_140 ( V_245 -> V_41 , V_94 , V_154 ) ;
}
static void F_141 ( struct V_1 * V_4 )
{
unsigned long V_8 ;
F_5 ( & V_246 , V_8 ) ;
F_142 ( & V_4 -> V_247 , & V_248 ) ;
F_7 ( & V_246 , V_8 ) ;
}
static void F_143 ( struct V_1 * V_4 )
{
unsigned long V_8 ;
F_5 ( & V_246 , V_8 ) ;
F_144 ( & V_4 -> V_247 ) ;
F_7 ( & V_246 , V_8 ) ;
}
static T_1 F_145 ( void )
{
unsigned long V_8 ;
int V_184 ;
F_146 ( & V_249 , V_8 ) ;
V_184 = F_147 ( V_250 , V_251 ) ;
F_107 ( V_184 == 0 ) ;
if ( V_184 > 0 && V_184 < V_251 )
F_19 ( V_184 , V_250 ) ;
else
V_184 = 0 ;
F_148 ( & V_249 , V_8 ) ;
return V_184 ;
}
static void F_149 ( int V_184 )
{
unsigned long V_8 ;
F_146 ( & V_249 , V_8 ) ;
if ( V_184 > 0 && V_184 < V_251 )
F_150 ( V_184 , V_250 ) ;
F_148 ( & V_249 , V_8 ) ;
}
static void F_151 ( struct V_1 * V_4 )
{
unsigned long V_252 = ( unsigned long ) V_4 -> V_192 ;
switch ( V_4 -> V_190 ) {
case V_253 :
break;
case V_254 :
F_130 ( V_252 ) ;
break;
case V_255 :
F_152 ( V_252 ) ;
break;
case V_256 :
F_153 ( V_252 ) ;
break;
case V_257 :
F_154 ( V_252 ) ;
break;
case V_258 :
F_155 ( V_252 ) ;
break;
case V_191 :
F_156 ( V_252 ) ;
break;
default:
F_157 () ;
}
}
static void F_158 ( T_3 * V_259 )
{
T_3 * V_260 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 512 ; ++ V_26 ) {
if ( ! ( V_259 [ V_26 ] & V_261 ) )
continue;
V_260 = F_159 ( V_259 [ V_26 ] & V_157 ) ;
F_130 ( ( unsigned long ) V_260 ) ;
}
}
static void F_160 ( T_3 * V_259 )
{
T_3 * V_260 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 512 ; ++ V_26 ) {
if ( ! ( V_259 [ V_26 ] & V_261 ) )
continue;
V_260 = F_159 ( V_259 [ V_26 ] & V_157 ) ;
F_158 ( V_260 ) ;
}
}
static void F_161 ( struct V_1 * V_4 )
{
if ( V_4 -> V_262 == 2 )
F_160 ( V_4 -> V_263 ) ;
else if ( V_4 -> V_262 == 1 )
F_158 ( V_4 -> V_263 ) ;
else
F_107 ( V_4 -> V_262 != 0 ) ;
F_130 ( ( unsigned long ) V_4 -> V_263 ) ;
}
static void F_162 ( struct V_30 * V_3 )
{
int V_26 ;
if ( ! V_3 )
return;
F_143 ( & V_3 -> V_4 ) ;
F_151 ( & V_3 -> V_4 ) ;
for ( V_26 = 0 ; V_26 < V_222 ; ++ V_26 ) {
if ( ! V_3 -> V_40 [ V_26 ] )
continue;
F_130 ( ( unsigned long ) V_3 -> V_40 [ V_26 ] -> V_41 ) ;
F_131 ( V_3 -> V_40 [ V_26 ] ) ;
}
F_131 ( V_3 ) ;
}
static struct V_30 * F_163 ( void )
{
struct V_30 * V_31 ;
V_31 = F_4 ( sizeof( struct V_30 ) , V_9 ) ;
if ( ! V_31 )
return NULL ;
if ( F_164 ( & V_31 -> V_4 ) )
goto V_264;
V_31 -> V_4 . V_190 = V_255 ;
V_31 -> V_4 . V_192 = ( void * ) F_103 ( V_9 ) ;
V_31 -> V_4 . V_8 = V_265 ;
V_31 -> V_4 . V_51 = V_31 ;
if ( ! V_31 -> V_4 . V_192 )
goto V_264;
V_31 -> V_243 = false ;
F_141 ( & V_31 -> V_4 ) ;
if ( F_127 ( V_31 , true , V_9 ) )
goto V_264;
V_31 -> V_40 [ 0 ] -> V_41 [ 0 ] = 1 ;
V_31 -> V_237 = 0 ;
return V_31 ;
V_264:
F_162 ( V_31 ) ;
return NULL ;
}
static bool V_30 ( struct V_1 * V_4 )
{
return V_4 -> V_8 & V_265 ;
}
static void F_165 ( T_1 V_6 , struct V_1 * V_4 , bool V_182 )
{
T_3 V_266 = 0 ;
T_3 V_8 = 0 ;
if ( V_4 -> V_190 != V_253 )
V_266 = F_105 ( V_4 -> V_192 ) ;
V_266 |= ( V_4 -> V_190 & V_267 )
<< V_268 ;
V_266 |= V_209 | V_211 | V_206 | V_269 ;
V_8 = V_59 [ V_6 ] . V_86 [ 1 ] ;
if ( V_182 )
V_8 |= V_270 ;
if ( V_4 -> V_8 & V_271 ) {
T_3 V_272 = F_71 ( V_4 -> V_263 ) ;
T_3 V_262 = V_4 -> V_262 ;
T_3 V_273 ;
V_266 |= V_274 ;
V_266 |= ( V_262 & V_275 ) << V_276 ;
V_273 = F_166 ( ~ 0ULL ) << V_277 ;
V_8 &= ~ V_273 ;
V_273 = F_167 ( ~ 0ULL ) << V_278 ;
V_8 &= ~ V_273 ;
V_273 = F_168 ( V_272 ) << V_279 ;
V_266 |= V_273 ;
V_273 = F_166 ( V_272 ) << V_277 ;
V_8 |= V_273 ;
V_273 = F_167 ( V_272 ) << V_278 ;
V_8 |= V_273 ;
}
V_8 &= ~ ( 0xffffUL ) ;
V_8 |= V_4 -> V_184 ;
V_59 [ V_6 ] . V_86 [ 1 ] = V_8 ;
V_59 [ V_6 ] . V_86 [ 0 ] = V_266 ;
}
static void F_169 ( T_1 V_6 )
{
V_59 [ V_6 ] . V_86 [ 0 ] = V_206 | V_269 ;
V_59 [ V_6 ] . V_86 [ 1 ] &= V_280 ;
F_170 ( V_6 ) ;
}
static void F_171 ( struct V_5 * V_7 ,
struct V_1 * V_4 )
{
struct V_53 * V_21 ;
T_1 V_57 ;
bool V_182 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
V_57 = V_58 [ V_7 -> V_6 ] ;
V_182 = V_7 -> V_182 . V_183 ;
V_7 -> V_4 = V_4 ;
F_142 ( & V_7 -> V_247 , & V_4 -> V_281 ) ;
V_4 -> V_186 [ V_21 -> V_216 ] += 1 ;
V_4 -> V_282 += 1 ;
F_165 ( V_7 -> V_6 , V_4 , V_182 ) ;
if ( V_57 != V_7 -> V_6 )
F_165 ( V_7 -> V_6 , V_4 , V_182 ) ;
F_95 ( V_7 ) ;
}
static void F_172 ( struct V_5 * V_7 )
{
struct V_53 * V_21 ;
T_1 V_57 ;
if ( ! V_7 -> V_4 )
return;
V_21 = V_46 [ V_7 -> V_6 ] ;
V_57 = V_58 [ V_7 -> V_6 ] ;
V_7 -> V_4 -> V_186 [ V_21 -> V_216 ] -= 1 ;
V_7 -> V_4 -> V_282 -= 1 ;
V_7 -> V_4 = NULL ;
F_144 ( & V_7 -> V_247 ) ;
F_169 ( V_7 -> V_6 ) ;
if ( V_57 != V_7 -> V_6 )
F_169 ( V_57 ) ;
F_95 ( V_7 ) ;
}
static int F_173 ( struct V_5 * V_7 ,
struct V_1 * V_4 )
{
int V_177 ;
F_69 ( ! F_174 () ) ;
F_175 ( & V_4 -> V_174 ) ;
V_177 = - V_205 ;
if ( V_7 -> V_4 != NULL )
goto V_12;
F_171 ( V_7 , V_4 ) ;
V_177 = 0 ;
V_12:
F_176 ( & V_4 -> V_174 ) ;
return V_177 ;
}
static void F_177 ( struct V_15 * V_16 )
{
F_178 ( V_16 ) ;
F_179 ( V_16 ) ;
F_180 ( V_16 ) ;
}
static int F_181 ( struct V_15 * V_16 )
{
T_1 V_283 ;
int V_27 ;
V_27 = F_16 ( V_16 , V_24 ) ;
if ( ! V_27 )
return - V_204 ;
F_182 ( V_16 , V_27 + V_284 , & V_283 ) ;
V_283 |= V_285 ;
F_183 ( V_16 , V_27 + V_284 , V_283 ) ;
return 0 ;
}
static int F_184 ( struct V_15 * V_16 )
{
bool V_286 ;
int V_287 , V_177 ;
V_287 = 32 ;
if ( F_17 ( V_16 , V_288 ) )
V_287 = 1 ;
V_286 = F_17 ( V_16 , V_289 ) ;
V_177 = F_185 ( V_16 , 0 ) ;
if ( V_177 )
goto V_290;
V_177 = F_186 ( V_16 ) ;
if ( V_177 )
goto V_290;
V_177 = F_187 ( V_16 , V_287 ) ;
if ( V_177 )
goto V_290;
if ( V_286 ) {
V_177 = F_181 ( V_16 ) ;
if ( V_177 )
goto V_290;
}
V_177 = F_188 ( V_16 , V_39 ) ;
if ( V_177 )
goto V_290;
return 0 ;
V_290:
F_179 ( V_16 ) ;
F_180 ( V_16 ) ;
return V_177 ;
}
static bool F_189 ( struct V_15 * V_16 )
{
T_1 V_137 ;
int V_27 ;
V_27 = F_16 ( V_16 , V_24 ) ;
if ( ! V_27 )
return false ;
F_182 ( V_16 , V_27 + V_291 , & V_137 ) ;
return ( V_137 & V_292 ) ? true : false ;
}
static int F_190 ( struct V_13 * V_14 ,
struct V_1 * V_4 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_5 * V_7 ;
unsigned long V_8 ;
int V_177 ;
V_7 = F_14 ( V_14 ) ;
if ( V_4 -> V_8 & V_271 ) {
if ( ! V_7 -> V_293 )
return - V_204 ;
if ( V_7 -> V_54 ) {
if ( F_184 ( V_16 ) != 0 )
return - V_204 ;
V_7 -> V_182 . V_183 = true ;
V_7 -> V_182 . V_161 = F_191 ( V_16 ) ;
V_7 -> V_294 = F_189 ( V_16 ) ;
}
} else if ( V_295 &&
F_188 ( V_16 , V_39 ) == 0 ) {
V_7 -> V_182 . V_183 = true ;
V_7 -> V_182 . V_161 = F_191 ( V_16 ) ;
}
F_146 ( & V_249 , V_8 ) ;
V_177 = F_173 ( V_7 , V_4 ) ;
F_148 ( & V_249 , V_8 ) ;
F_99 ( V_4 ) ;
return V_177 ;
}
static void F_192 ( struct V_5 * V_7 )
{
struct V_1 * V_4 ;
F_69 ( ! F_174 () ) ;
if ( F_69 ( ! V_7 -> V_4 ) )
return;
V_4 = V_7 -> V_4 ;
F_175 ( & V_4 -> V_174 ) ;
F_172 ( V_7 ) ;
F_176 ( & V_4 -> V_174 ) ;
}
static void F_193 ( struct V_13 * V_14 )
{
struct V_1 * V_4 ;
struct V_5 * V_7 ;
unsigned long V_8 ;
V_7 = F_14 ( V_14 ) ;
V_4 = V_7 -> V_4 ;
F_146 ( & V_249 , V_8 ) ;
F_192 ( V_7 ) ;
F_148 ( & V_249 , V_8 ) ;
if ( V_4 -> V_8 & V_271 && V_7 -> V_54 )
F_177 ( F_12 ( V_14 ) ) ;
else if ( V_7 -> V_182 . V_183 )
F_178 ( F_12 ( V_14 ) ) ;
V_7 -> V_182 . V_183 = false ;
}
static int F_194 ( struct V_13 * V_14 )
{
struct V_5 * V_7 ;
struct V_2 * V_4 ;
struct V_53 * V_21 ;
T_1 V_6 ;
int V_177 ;
if ( ! F_21 ( V_14 ) || F_14 ( V_14 ) )
return 0 ;
V_6 = F_11 ( V_14 ) ;
V_21 = V_46 [ V_6 ] ;
V_177 = F_28 ( V_14 ) ;
if ( V_177 ) {
if ( V_177 != - V_296 )
F_40 ( L_24 ,
F_195 ( V_14 ) ) ;
F_30 ( V_14 ) ;
V_14 -> V_20 . V_61 = & V_297 ;
goto V_50;
}
F_23 ( V_14 ) ;
V_7 = F_14 ( V_14 ) ;
F_107 ( ! V_7 ) ;
if ( V_298 || V_7 -> V_54 )
F_196 ( V_14 ) ;
V_4 = F_197 ( V_14 ) ;
if ( V_4 -> type == V_299 )
V_7 -> V_293 = true ;
else
V_14 -> V_20 . V_61 = & V_300 ;
V_50:
F_85 ( V_21 ) ;
return 0 ;
}
static void F_198 ( struct V_13 * V_14 )
{
struct V_53 * V_21 ;
T_1 V_6 ;
if ( ! F_21 ( V_14 ) )
return;
V_6 = F_11 ( V_14 ) ;
V_21 = V_46 [ V_6 ] ;
F_31 ( V_14 ) ;
F_85 ( V_21 ) ;
}
static struct V_1 * F_199 ( struct V_13 * V_14 )
{
struct V_1 * V_4 ;
struct V_2 * V_301 ;
if ( ! F_21 ( V_14 ) )
return F_200 ( - V_204 ) ;
V_301 = F_197 ( V_14 ) ;
if ( ! V_301 )
return NULL ;
V_4 = F_1 ( V_301 ) ;
if ( ! V_30 ( V_4 ) )
return F_200 ( - V_205 ) ;
return V_4 ;
}
static void F_201 ( struct V_1 * V_4 )
{
struct V_5 * V_7 ;
F_9 (dev_data, &domain->dev_list, list)
F_165 ( V_7 -> V_6 , V_4 , V_7 -> V_182 . V_183 ) ;
}
static void F_124 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_193 )
return;
F_201 ( V_4 ) ;
F_101 ( V_4 ) ;
F_99 ( V_4 ) ;
V_4 -> V_193 = false ;
}
static T_3 * F_202 ( struct V_30 * V_3 ,
unsigned long V_94 )
{
struct V_223 * V_40 ;
T_3 * V_189 , * V_195 ;
V_40 = V_3 -> V_40 [ F_203 ( V_94 ) ] ;
if ( ! V_40 )
return NULL ;
V_189 = V_40 -> V_227 [ F_204 ( V_94 ) ] ;
if ( ! V_189 ) {
V_189 = F_106 ( & V_3 -> V_4 , V_94 , V_37 , & V_195 ,
V_302 ) ;
V_40 -> V_227 [ F_204 ( V_94 ) ] = V_195 ;
} else
V_189 += F_110 ( 0 , V_94 ) ;
F_124 ( & V_3 -> V_4 ) ;
return V_189 ;
}
static T_8 F_205 ( struct V_30 * V_3 ,
unsigned long V_94 ,
T_9 V_303 ,
int V_304 )
{
T_3 * V_189 , V_202 ;
F_69 ( V_94 > V_3 -> V_38 ) ;
V_303 &= V_157 ;
V_189 = F_202 ( V_3 , V_94 ) ;
if ( ! V_189 )
return V_244 ;
V_202 = V_303 | V_206 | V_207 ;
if ( V_304 == V_305 )
V_202 |= V_209 ;
else if ( V_304 == V_306 )
V_202 |= V_211 ;
else if ( V_304 == V_307 )
V_202 |= V_209 | V_211 ;
F_69 ( * V_189 ) ;
* V_189 = V_202 ;
return ( T_8 ) V_94 ;
}
static void F_206 ( struct V_30 * V_3 ,
unsigned long V_94 )
{
struct V_223 * V_40 ;
T_3 * V_189 ;
if ( V_94 >= V_3 -> V_38 )
return;
V_40 = V_3 -> V_40 [ F_203 ( V_94 ) ] ;
if ( ! V_40 )
return;
V_189 = V_40 -> V_227 [ F_204 ( V_94 ) ] ;
if ( ! V_189 )
return;
V_189 += F_110 ( 0 , V_94 ) ;
F_69 ( ! * V_189 ) ;
* V_189 = 0ULL ;
}
static T_8 F_207 ( struct V_13 * V_14 ,
struct V_30 * V_31 ,
T_9 V_303 ,
T_6 V_152 ,
int V_308 ,
bool V_309 ,
T_3 V_44 )
{
T_8 V_225 = V_303 & ~ V_157 ;
T_8 V_94 , V_235 , V_177 ;
unsigned int V_154 ;
unsigned long V_234 = 0 ;
int V_26 ;
V_154 = F_76 ( V_303 , V_152 , V_37 ) ;
V_303 &= V_157 ;
F_53 ( V_81 ) ;
if ( V_154 > 1 )
F_53 ( V_77 ) ;
if ( V_309 )
V_234 = ( 1UL << F_208 ( V_152 ) ) - 1 ;
V_95:
V_94 = F_137 ( V_14 , V_31 , V_154 , V_234 ,
V_44 ) ;
if ( F_138 ( V_94 == V_244 ) ) {
V_31 -> V_237 = V_31 -> V_38 ;
if ( F_127 ( V_31 , false , V_302 ) )
goto V_50;
goto V_95;
}
V_235 = V_94 ;
for ( V_26 = 0 ; V_26 < V_154 ; ++ V_26 ) {
V_177 = F_205 ( V_31 , V_235 , V_303 , V_308 ) ;
if ( V_177 == V_244 )
goto V_310;
V_303 += V_37 ;
V_235 += V_37 ;
}
V_94 += V_225 ;
F_209 ( V_80 , V_152 ) ;
if ( F_138 ( V_31 -> V_243 && ! V_69 ) ) {
F_98 ( & V_31 -> V_4 ) ;
V_31 -> V_243 = false ;
} else if ( F_138 ( V_311 ) )
F_97 ( & V_31 -> V_4 , V_94 , V_152 ) ;
V_50:
return V_94 ;
V_310:
for ( -- V_26 ; V_26 >= 0 ; -- V_26 ) {
V_235 -= V_37 ;
F_206 ( V_31 , V_235 ) ;
}
F_139 ( V_31 , V_94 , V_154 ) ;
return V_244 ;
}
static void F_210 ( struct V_30 * V_31 ,
T_8 V_312 ,
T_6 V_152 ,
int V_308 )
{
T_8 V_313 ;
T_8 V_26 , V_235 ;
unsigned int V_154 ;
if ( ( V_312 == V_244 ) ||
( V_312 + V_152 > V_31 -> V_38 ) )
return;
V_313 = V_312 ;
V_154 = F_76 ( V_312 , V_152 , V_37 ) ;
V_312 &= V_157 ;
V_235 = V_312 ;
for ( V_26 = 0 ; V_26 < V_154 ; ++ V_26 ) {
F_206 ( V_31 , V_235 ) ;
V_235 += V_37 ;
}
F_211 ( V_80 , V_152 ) ;
F_139 ( V_31 , V_312 , V_154 ) ;
if ( V_69 || V_31 -> V_243 ) {
F_97 ( & V_31 -> V_4 , V_313 , V_152 ) ;
V_31 -> V_243 = false ;
}
}
static T_8 F_212 ( struct V_13 * V_14 , struct V_198 * V_198 ,
unsigned long V_225 , T_6 V_152 ,
enum V_314 V_308 ,
struct V_315 * V_316 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
T_8 V_34 ;
T_3 V_44 ;
T_9 V_303 = F_213 ( V_198 ) + V_225 ;
F_53 ( V_71 ) ;
V_4 = F_199 ( V_14 ) ;
if ( F_214 ( V_4 ) == - V_204 )
return ( T_8 ) V_303 ;
else if ( F_25 ( V_4 ) )
return V_244 ;
V_44 = * V_14 -> V_44 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_34 = F_207 ( V_14 , V_4 -> V_51 , V_303 , V_152 , V_308 , false ,
V_44 ) ;
if ( V_34 == V_244 )
goto V_50;
F_100 ( V_4 ) ;
V_50:
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_34 ;
}
static void F_215 ( struct V_13 * V_14 , T_8 V_312 , T_6 V_152 ,
enum V_314 V_308 , struct V_315 * V_316 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
F_53 ( V_72 ) ;
V_4 = F_199 ( V_14 ) ;
if ( F_25 ( V_4 ) )
return;
F_5 ( & V_4 -> V_174 , V_8 ) ;
F_210 ( V_4 -> V_51 , V_312 , V_152 , V_308 ) ;
F_100 ( V_4 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
}
static int F_216 ( struct V_13 * V_14 , struct V_317 * V_318 ,
int V_319 , enum V_314 V_308 ,
struct V_315 * V_316 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
int V_26 ;
struct V_317 * V_155 ;
T_9 V_303 ;
int V_320 = 0 ;
T_3 V_44 ;
F_53 ( V_73 ) ;
V_4 = F_199 ( V_14 ) ;
if ( F_25 ( V_4 ) )
return 0 ;
V_44 = * V_14 -> V_44 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
F_217 (sglist, s, nelems, i) {
V_303 = F_218 ( V_155 ) ;
V_155 -> V_321 = F_207 ( V_14 , V_4 -> V_51 ,
V_303 , V_155 -> V_322 , V_308 , false ,
V_44 ) ;
if ( V_155 -> V_321 ) {
V_155 -> V_323 = V_155 -> V_322 ;
V_320 ++ ;
} else
goto V_324;
}
F_100 ( V_4 ) ;
V_50:
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_320 ;
V_324:
F_217 (sglist, s, mapped_elems, i) {
if ( V_155 -> V_321 )
F_210 ( V_4 -> V_51 , V_155 -> V_321 ,
V_155 -> V_323 , V_308 ) ;
V_155 -> V_321 = V_155 -> V_323 = 0 ;
}
V_320 = 0 ;
goto V_50;
}
static void F_219 ( struct V_13 * V_14 , struct V_317 * V_318 ,
int V_319 , enum V_314 V_308 ,
struct V_315 * V_316 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
struct V_317 * V_155 ;
int V_26 ;
F_53 ( V_74 ) ;
V_4 = F_199 ( V_14 ) ;
if ( F_25 ( V_4 ) )
return;
F_5 ( & V_4 -> V_174 , V_8 ) ;
F_217 (sglist, s, nelems, i) {
F_210 ( V_4 -> V_51 , V_155 -> V_321 ,
V_155 -> V_323 , V_308 ) ;
V_155 -> V_321 = V_155 -> V_323 = 0 ;
}
F_100 ( V_4 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
}
static void * F_220 ( struct V_13 * V_14 , T_6 V_152 ,
T_8 * V_312 , T_7 V_325 ,
struct V_315 * V_316 )
{
T_3 V_44 = V_14 -> V_326 ;
struct V_1 * V_4 ;
unsigned long V_8 ;
struct V_198 * V_198 ;
F_53 ( V_75 ) ;
V_4 = F_199 ( V_14 ) ;
if ( F_214 ( V_4 ) == - V_204 ) {
V_198 = F_221 ( V_325 , F_208 ( V_152 ) ) ;
* V_312 = F_213 ( V_198 ) ;
return F_222 ( V_198 ) ;
} else if ( F_25 ( V_4 ) )
return NULL ;
V_152 = F_223 ( V_152 ) ;
V_44 = V_14 -> V_326 ;
V_325 &= ~ ( V_327 | V_328 | V_329 ) ;
V_325 |= V_330 ;
V_198 = F_221 ( V_325 | V_331 , F_208 ( V_152 ) ) ;
if ( ! V_198 ) {
if ( ! F_224 ( V_325 ) )
return NULL ;
V_198 = F_225 ( V_14 , V_152 >> V_39 ,
F_208 ( V_152 ) ) ;
if ( ! V_198 )
return NULL ;
}
if ( ! V_44 )
V_44 = * V_14 -> V_44 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
* V_312 = F_207 ( V_14 , V_4 -> V_51 , F_213 ( V_198 ) ,
V_152 , V_307 , true , V_44 ) ;
if ( * V_312 == V_244 ) {
F_7 ( & V_4 -> V_174 , V_8 ) ;
goto V_224;
}
F_100 ( V_4 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
return F_222 ( V_198 ) ;
V_224:
if ( ! F_226 ( V_14 , V_198 , V_152 >> V_39 ) )
F_227 ( V_198 , F_208 ( V_152 ) ) ;
return NULL ;
}
static void F_228 ( struct V_13 * V_14 , T_6 V_152 ,
void * V_332 , T_8 V_312 ,
struct V_315 * V_316 )
{
struct V_1 * V_4 ;
unsigned long V_8 ;
struct V_198 * V_198 ;
F_53 ( V_76 ) ;
V_198 = F_229 ( V_332 ) ;
V_152 = F_223 ( V_152 ) ;
V_4 = F_199 ( V_14 ) ;
if ( F_25 ( V_4 ) )
goto V_333;
F_5 ( & V_4 -> V_174 , V_8 ) ;
F_210 ( V_4 -> V_51 , V_312 , V_152 , V_307 ) ;
F_100 ( V_4 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
V_333:
if ( ! F_226 ( V_14 , V_198 , V_152 >> V_39 ) )
F_227 ( V_198 , F_208 ( V_152 ) ) ;
}
static int F_230 ( struct V_13 * V_14 , T_3 V_240 )
{
return F_21 ( V_14 ) ;
}
int T_10 F_231 ( void )
{
return F_232 ( & V_334 , & V_335 ) ;
}
int T_10 F_233 ( void )
{
V_336 = V_298 ? 1 : 0 ;
V_337 = 1 ;
if ( ! V_336 )
V_61 = & V_297 ;
F_36 () ;
if ( V_69 )
F_234 ( L_25 ) ;
else
F_234 ( L_26 ) ;
return 0 ;
}
static void F_235 ( struct V_1 * V_4 )
{
struct V_5 * V_133 ;
unsigned long V_8 ;
F_146 ( & V_249 , V_8 ) ;
while ( ! F_236 ( & V_4 -> V_281 ) ) {
V_133 = F_237 ( & V_4 -> V_281 ,
struct V_5 , V_247 ) ;
F_192 ( V_133 ) ;
}
F_148 ( & V_249 , V_8 ) ;
}
static void F_238 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_143 ( V_4 ) ;
if ( V_4 -> V_184 )
F_149 ( V_4 -> V_184 ) ;
F_131 ( V_4 ) ;
}
static int F_164 ( struct V_1 * V_4 )
{
F_239 ( & V_4 -> V_174 ) ;
F_240 ( & V_4 -> V_338 ) ;
V_4 -> V_184 = F_145 () ;
if ( ! V_4 -> V_184 )
return - V_52 ;
F_241 ( & V_4 -> V_281 ) ;
return 0 ;
}
static struct V_1 * F_242 ( void )
{
struct V_1 * V_4 ;
V_4 = F_4 ( sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 )
return NULL ;
if ( F_164 ( V_4 ) )
goto V_290;
F_141 ( V_4 ) ;
return V_4 ;
V_290:
F_131 ( V_4 ) ;
return NULL ;
}
static struct V_2 * F_243 ( unsigned type )
{
struct V_1 * V_339 ;
struct V_30 * V_47 ;
switch ( type ) {
case V_340 :
V_339 = F_242 () ;
if ( ! V_339 )
return NULL ;
V_339 -> V_190 = V_256 ;
V_339 -> V_192 = ( void * ) F_103 ( V_9 ) ;
if ( ! V_339 -> V_192 ) {
F_238 ( V_339 ) ;
return NULL ;
}
V_339 -> V_4 . V_341 . V_342 = 0 ;
V_339 -> V_4 . V_341 . V_343 = ~ 0ULL ;
V_339 -> V_4 . V_341 . V_344 = true ;
break;
case V_345 :
V_47 = F_163 () ;
if ( ! V_47 ) {
F_40 ( L_27 ) ;
return NULL ;
}
V_339 = & V_47 -> V_4 ;
break;
case V_299 :
V_339 = F_242 () ;
if ( ! V_339 )
return NULL ;
V_339 -> V_190 = V_253 ;
break;
default:
return NULL ;
}
return & V_339 -> V_4 ;
}
static void F_244 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 )
return;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_282 > 0 )
F_235 ( V_4 ) ;
F_107 ( V_4 -> V_282 != 0 ) ;
if ( V_4 -> V_190 != V_253 )
F_151 ( V_4 ) ;
if ( V_4 -> V_8 & V_271 )
F_161 ( V_4 ) ;
F_238 ( V_4 ) ;
}
static void F_245 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_5 * V_7 = V_14 -> V_20 . V_21 ;
struct V_53 * V_21 ;
T_1 V_6 ;
if ( ! F_21 ( V_14 ) )
return;
V_6 = F_11 ( V_14 ) ;
if ( V_7 -> V_4 != NULL )
F_193 ( V_14 ) ;
V_21 = V_46 [ V_6 ] ;
if ( ! V_21 )
return;
F_85 ( V_21 ) ;
}
static int F_246 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_7 ;
struct V_53 * V_21 ;
int V_177 ;
if ( ! F_21 ( V_14 ) )
return - V_204 ;
V_7 = V_14 -> V_20 . V_21 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
if ( ! V_21 )
return - V_204 ;
if ( V_7 -> V_4 )
F_193 ( V_14 ) ;
V_177 = F_190 ( V_14 , V_4 ) ;
F_85 ( V_21 ) ;
return V_177 ;
}
static int F_247 ( struct V_2 * V_3 , unsigned long V_346 ,
T_9 V_303 , T_6 V_194 , int V_347 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_201 = 0 ;
int V_177 ;
if ( V_4 -> V_190 == V_253 )
return - V_204 ;
if ( V_347 & V_348 )
V_201 |= V_208 ;
if ( V_347 & V_349 )
V_201 |= V_210 ;
F_248 ( & V_4 -> V_338 ) ;
V_177 = F_120 ( V_4 , V_346 , V_303 , V_201 , V_194 ) ;
F_249 ( & V_4 -> V_338 ) ;
return V_177 ;
}
static T_6 F_250 ( struct V_2 * V_3 , unsigned long V_346 ,
T_6 V_194 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_6 V_213 ;
if ( V_4 -> V_190 == V_253 )
return - V_204 ;
F_248 ( & V_4 -> V_338 ) ;
V_213 = F_125 ( V_4 , V_346 , V_194 ) ;
F_249 ( & V_4 -> V_338 ) ;
F_99 ( V_4 ) ;
return V_213 ;
}
static T_9 F_251 ( struct V_2 * V_3 ,
T_8 V_346 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_350 , V_221 ;
T_3 * V_189 , V_202 ;
if ( V_4 -> V_190 == V_253 )
return V_346 ;
V_189 = F_116 ( V_4 , V_346 , & V_221 ) ;
if ( ! V_189 || ! F_113 ( * V_189 ) )
return 0 ;
V_350 = V_221 - 1 ;
V_202 = * V_189 & V_351 ;
return ( V_202 & ~ V_350 ) | ( V_346 & V_350 ) ;
}
static bool F_252 ( enum V_352 V_353 )
{
switch ( V_353 ) {
case V_354 :
return true ;
case V_355 :
return ( V_356 == 1 ) ;
case V_357 :
return false ;
}
return false ;
}
static void F_253 ( struct V_13 * V_14 ,
struct V_358 * V_114 )
{
struct V_32 * V_133 ;
T_1 V_6 ;
V_6 = F_11 ( V_14 ) ;
F_9 (entry, &amd_iommu_unity_map, list) {
struct V_359 * V_360 ;
if ( V_6 < V_133 -> V_42 || V_6 > V_133 -> V_43 )
continue;
V_360 = F_4 ( sizeof( * V_360 ) , V_9 ) ;
if ( ! V_360 ) {
F_40 ( L_28 ,
F_195 ( V_14 ) ) ;
return;
}
V_360 -> V_235 = V_133 -> V_35 ;
V_360 -> V_322 = V_133 -> V_36 - V_133 -> V_35 ;
if ( V_133 -> V_201 & V_208 )
V_360 -> V_201 |= V_348 ;
if ( V_133 -> V_201 & V_210 )
V_360 -> V_201 |= V_349 ;
F_6 ( & V_360 -> V_247 , V_114 ) ;
}
}
static void F_254 ( struct V_13 * V_14 ,
struct V_358 * V_114 )
{
struct V_359 * V_133 , * V_361 ;
F_255 (entry, next, head, list)
F_131 ( V_133 ) ;
}
int F_256 ( struct V_362 * V_363 )
{
return F_257 ( & V_129 , V_363 ) ;
}
int F_258 ( struct V_362 * V_363 )
{
return F_259 ( & V_129 , V_363 ) ;
}
void F_260 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_4 -> V_190 = V_253 ;
V_4 -> V_193 = true ;
F_124 ( V_4 ) ;
F_151 ( V_4 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
}
int F_261 ( struct V_2 * V_3 , int V_364 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_365 , V_177 ;
if ( V_364 <= 0 || V_364 > ( V_366 + 1 ) )
return - V_204 ;
for ( V_365 = 0 ; ( V_364 - 1 ) & ~ 0x1ff ; V_364 >>= 9 )
V_365 += 1 ;
if ( V_365 > V_367 )
return - V_204 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = - V_205 ;
if ( V_4 -> V_282 > 0 || V_4 -> V_8 & V_271 )
goto V_50;
V_177 = - V_52 ;
V_4 -> V_263 = ( void * ) F_103 ( V_302 ) ;
if ( V_4 -> V_263 == NULL )
goto V_50;
V_4 -> V_262 = V_365 ;
V_4 -> V_8 |= V_271 ;
V_4 -> V_193 = true ;
F_124 ( V_4 ) ;
V_177 = 0 ;
V_50:
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
static int F_262 ( struct V_1 * V_4 , int V_126 ,
T_3 V_94 , bool V_152 )
{
struct V_5 * V_7 ;
struct V_88 V_89 ;
int V_26 , V_177 ;
if ( ! ( V_4 -> V_8 & V_271 ) )
return - V_204 ;
F_78 ( & V_89 , V_4 -> V_184 , V_126 , V_94 , V_152 ) ;
for ( V_26 = 0 ; V_26 < V_185 ; ++ V_26 ) {
if ( V_4 -> V_186 [ V_26 ] == 0 )
continue;
V_177 = F_84 ( V_187 [ V_26 ] , & V_89 ) ;
if ( V_177 != 0 )
goto V_50;
}
F_100 ( V_4 ) ;
F_9 (dev_data, &domain->dev_list, list) {
struct V_53 * V_21 ;
int V_161 ;
if ( ! V_7 -> V_182 . V_183 )
continue;
V_161 = V_7 -> V_182 . V_161 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
F_79 ( & V_89 , V_7 -> V_6 , V_126 ,
V_161 , V_94 , V_152 ) ;
V_177 = F_84 ( V_21 , & V_89 ) ;
if ( V_177 != 0 )
goto V_50;
}
F_100 ( V_4 ) ;
V_177 = 0 ;
V_50:
return V_177 ;
}
static int F_263 ( struct V_1 * V_4 , int V_126 ,
T_3 V_94 )
{
F_53 ( V_83 ) ;
return F_262 ( V_4 , V_126 , V_94 , false ) ;
}
int F_264 ( struct V_2 * V_3 , int V_126 ,
T_3 V_94 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_177 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = F_263 ( V_4 , V_126 , V_94 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
static int F_265 ( struct V_1 * V_4 , int V_126 )
{
F_53 ( V_84 ) ;
return F_262 ( V_4 , V_126 , V_156 ,
true ) ;
}
int F_266 ( struct V_2 * V_3 , int V_126 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_177 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = F_265 ( V_4 , V_126 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
static T_3 * F_267 ( T_3 * V_252 , int V_196 , int V_126 , bool V_368 )
{
int V_216 ;
T_3 * V_189 ;
while ( true ) {
V_216 = ( V_126 >> ( 9 * V_196 ) ) & 0x1ff ;
V_189 = & V_252 [ V_216 ] ;
if ( V_196 == 0 )
break;
if ( ! ( * V_189 & V_261 ) ) {
if ( ! V_368 )
return NULL ;
V_252 = ( void * ) F_103 ( V_302 ) ;
if ( V_252 == NULL )
return NULL ;
* V_189 = F_71 ( V_252 ) | V_261 ;
}
V_252 = F_159 ( * V_189 & V_157 ) ;
V_196 -= 1 ;
}
return V_189 ;
}
static int F_268 ( struct V_1 * V_4 , int V_126 ,
unsigned long V_369 )
{
T_3 * V_189 ;
if ( V_4 -> V_190 != V_253 )
return - V_204 ;
V_189 = F_267 ( V_4 -> V_263 , V_4 -> V_262 , V_126 , true ) ;
if ( V_189 == NULL )
return - V_52 ;
* V_189 = ( V_369 & V_157 ) | V_261 ;
return F_265 ( V_4 , V_126 ) ;
}
static int F_269 ( struct V_1 * V_4 , int V_126 )
{
T_3 * V_189 ;
if ( V_4 -> V_190 != V_253 )
return - V_204 ;
V_189 = F_267 ( V_4 -> V_263 , V_4 -> V_262 , V_126 , false ) ;
if ( V_189 == NULL )
return 0 ;
* V_189 = 0 ;
return F_265 ( V_4 , V_126 ) ;
}
int F_270 ( struct V_2 * V_3 , int V_126 ,
unsigned long V_369 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_177 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = F_268 ( V_4 , V_126 , V_369 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
int F_271 ( struct V_2 * V_3 , int V_126 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_177 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = F_269 ( V_4 , V_126 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
int F_272 ( struct V_15 * V_16 , int V_126 ,
int V_137 , int V_128 )
{
struct V_5 * V_7 ;
struct V_53 * V_21 ;
struct V_88 V_89 ;
F_53 ( V_82 ) ;
V_7 = F_14 ( & V_16 -> V_14 ) ;
V_21 = V_46 [ V_7 -> V_6 ] ;
F_80 ( & V_89 , V_7 -> V_6 , V_126 , V_137 ,
V_128 , V_7 -> V_294 ) ;
return F_84 ( V_21 , & V_89 ) ;
}
struct V_2 * F_273 ( struct V_15 * V_16 )
{
struct V_1 * V_339 ;
V_339 = F_199 ( & V_16 -> V_14 ) ;
if ( F_25 ( V_339 ) )
return NULL ;
if ( ! ( V_339 -> V_8 & V_271 ) )
return NULL ;
return & V_339 -> V_4 ;
}
void F_274 ( struct V_15 * V_16 , T_2 V_28 )
{
struct V_5 * V_7 ;
if ( ! F_275 () )
return;
V_7 = F_14 ( & V_16 -> V_14 ) ;
V_7 -> V_29 |= ( 1 << V_28 ) ;
}
int F_276 ( struct V_15 * V_16 ,
struct F_276 * V_370 )
{
int V_371 ;
int V_27 ;
if ( V_16 == NULL || V_370 == NULL )
return - V_204 ;
if ( ! F_275 () )
return - V_204 ;
memset ( V_370 , 0 , sizeof( * V_370 ) ) ;
V_27 = F_16 ( V_16 , V_23 ) ;
if ( V_27 )
V_370 -> V_8 |= V_372 ;
V_27 = F_16 ( V_16 , V_24 ) ;
if ( V_27 )
V_370 -> V_8 |= V_373 ;
V_27 = F_16 ( V_16 , V_25 ) ;
if ( V_27 ) {
int V_374 ;
V_371 = 1 << ( 9 * ( V_367 + 1 ) ) ;
V_371 = F_277 ( V_371 , ( 1 << 20 ) ) ;
V_370 -> V_8 |= V_375 ;
V_370 -> V_371 = F_277 ( F_278 ( V_16 ) , V_371 ) ;
V_374 = F_279 ( V_16 ) ;
if ( V_374 & V_376 )
V_370 -> V_8 |= V_377 ;
if ( V_374 & V_378 )
V_370 -> V_8 |= V_379 ;
}
return 0 ;
}
static void F_280 ( T_1 V_6 , struct V_380 * V_381 )
{
T_3 V_382 ;
V_382 = V_59 [ V_6 ] . V_86 [ 2 ] ;
V_382 &= ~ V_383 ;
V_382 |= F_105 ( V_381 -> V_381 ) ;
V_382 |= V_384 ;
V_382 |= V_385 ;
V_382 |= V_386 ;
V_59 [ V_6 ] . V_86 [ 2 ] = V_382 ;
}
static struct V_380 * F_281 ( T_1 V_6 , bool V_387 )
{
struct V_380 * V_381 = NULL ;
struct V_53 * V_21 ;
unsigned long V_8 ;
T_1 V_57 ;
F_146 ( & V_249 , V_8 ) ;
V_21 = V_46 [ V_6 ] ;
if ( ! V_21 )
goto V_12;
V_381 = V_388 [ V_6 ] ;
if ( V_381 )
goto V_50;
V_57 = V_58 [ V_6 ] ;
V_381 = V_388 [ V_57 ] ;
if ( V_381 ) {
V_388 [ V_6 ] = V_381 ;
F_280 ( V_6 , V_381 ) ;
F_86 ( V_21 , V_6 ) ;
goto V_50;
}
V_381 = F_4 ( sizeof( * V_381 ) , V_302 ) ;
if ( ! V_381 )
goto V_50;
F_239 ( & V_381 -> V_174 ) ;
if ( V_387 )
V_381 -> V_389 = 32 ;
V_381 -> V_381 = F_282 ( V_390 , V_302 ) ;
if ( ! V_381 -> V_381 ) {
F_131 ( V_381 ) ;
V_381 = NULL ;
goto V_50;
}
memset ( V_381 -> V_381 , 0 , V_391 * sizeof( T_2 ) ) ;
if ( V_387 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < 32 ; ++ V_26 )
V_381 -> V_381 [ V_26 ] = V_392 ;
}
V_388 [ V_6 ] = V_381 ;
F_280 ( V_6 , V_381 ) ;
F_86 ( V_21 , V_6 ) ;
if ( V_6 != V_57 ) {
V_388 [ V_57 ] = V_381 ;
F_280 ( V_57 , V_381 ) ;
F_86 ( V_21 , V_57 ) ;
}
V_50:
F_85 ( V_21 ) ;
V_12:
F_148 ( & V_249 , V_8 ) ;
return V_381 ;
}
static int F_283 ( T_1 V_6 , int V_93 )
{
struct V_380 * V_381 ;
unsigned long V_8 ;
int V_216 , V_393 ;
V_381 = F_281 ( V_6 , false ) ;
if ( ! V_381 )
return - V_394 ;
F_5 ( & V_381 -> V_174 , V_8 ) ;
for ( V_393 = 0 , V_216 = V_381 -> V_389 ;
V_216 < V_391 ;
++ V_216 ) {
if ( V_381 -> V_381 [ V_216 ] == 0 )
V_393 += 1 ;
else
V_393 = 0 ;
if ( V_393 == V_93 ) {
for (; V_393 != 0 ; -- V_393 )
V_381 -> V_381 [ V_216 - V_393 + 1 ] = V_392 ;
V_216 -= V_93 - 1 ;
goto V_50;
}
}
V_216 = - V_395 ;
V_50:
F_7 ( & V_381 -> V_174 , V_8 ) ;
return V_216 ;
}
static int F_284 ( T_1 V_6 , int V_216 , union V_396 V_396 )
{
struct V_380 * V_381 ;
struct V_53 * V_21 ;
unsigned long V_8 ;
V_21 = V_46 [ V_6 ] ;
if ( V_21 == NULL )
return - V_204 ;
V_381 = F_281 ( V_6 , false ) ;
if ( ! V_381 )
return - V_52 ;
F_5 ( & V_381 -> V_174 , V_8 ) ;
V_381 -> V_381 [ V_216 ] = V_396 . V_397 ;
F_7 ( & V_381 -> V_174 , V_8 ) ;
F_90 ( V_21 , V_6 ) ;
F_85 ( V_21 ) ;
return 0 ;
}
static void F_285 ( T_1 V_6 , int V_216 )
{
struct V_380 * V_381 ;
struct V_53 * V_21 ;
unsigned long V_8 ;
V_21 = V_46 [ V_6 ] ;
if ( V_21 == NULL )
return;
V_381 = F_281 ( V_6 , false ) ;
if ( ! V_381 )
return;
F_5 ( & V_381 -> V_174 , V_8 ) ;
V_381 -> V_381 [ V_216 ] = 0 ;
F_7 ( & V_381 -> V_174 , V_8 ) ;
F_90 ( V_21 , V_6 ) ;
F_85 ( V_21 ) ;
}
static int F_286 ( struct V_398 * V_370 )
{
int V_6 = - 1 ;
switch ( V_370 -> type ) {
case V_399 :
V_6 = F_287 ( V_370 -> V_400 ) ;
break;
case V_401 :
V_6 = F_288 ( V_370 -> V_402 ) ;
break;
case V_403 :
case V_404 :
V_6 = F_11 ( & V_370 -> V_405 -> V_14 ) ;
break;
default:
F_107 ( 1 ) ;
break;
}
return V_6 ;
}
static struct V_406 * F_289 ( struct V_398 * V_370 )
{
struct V_53 * V_21 ;
int V_6 ;
if ( ! V_370 )
return NULL ;
V_6 = F_286 ( V_370 ) ;
if ( V_6 >= 0 ) {
V_21 = V_46 [ V_6 ] ;
if ( V_21 )
return V_21 -> V_407 ;
}
return NULL ;
}
static struct V_406 * F_290 ( struct V_398 * V_370 )
{
struct V_53 * V_21 ;
int V_6 ;
if ( ! V_370 )
return NULL ;
switch ( V_370 -> type ) {
case V_403 :
case V_404 :
V_6 = F_11 ( & V_370 -> V_405 -> V_14 ) ;
if ( V_6 >= 0 ) {
V_21 = V_46 [ V_6 ] ;
if ( V_21 )
return V_21 -> V_408 ;
}
break;
default:
break;
}
return NULL ;
}
static void F_291 ( struct V_409 * V_86 ,
struct V_410 * V_410 ,
struct V_398 * V_370 ,
int V_6 , int V_216 , int V_411 )
{
struct V_412 * V_413 = & V_86 -> V_412 ;
struct V_414 * V_415 = & V_86 -> V_416 ;
union V_396 * V_396 = & V_86 -> V_417 ;
struct V_418 * V_133 ;
V_86 -> V_412 . V_6 = V_6 ;
V_86 -> V_412 . V_216 = V_216 + V_411 ;
V_396 -> V_397 = 0 ;
V_396 -> V_419 . V_420 = V_410 -> V_420 ;
V_396 -> V_419 . V_421 = V_422 -> V_423 ;
V_396 -> V_419 . V_424 = V_410 -> V_425 ;
V_396 -> V_419 . V_426 = V_422 -> V_427 ;
V_396 -> V_419 . V_428 = 1 ;
switch ( V_370 -> type ) {
case V_399 :
V_133 = V_370 -> V_429 ;
V_370 -> V_429 = NULL ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_133 -> V_420 = V_216 ;
V_133 -> V_240 = 0 ;
V_133 -> V_430 = V_370 -> V_431 ;
V_133 -> V_432 = V_370 -> V_433 ;
if ( V_370 -> V_431 )
V_133 -> V_240 = 1 ;
break;
case V_401 :
case V_403 :
case V_404 :
V_415 -> V_434 = V_435 ;
V_415 -> V_436 = V_229 ;
V_415 -> V_86 = V_413 -> V_216 ;
break;
default:
F_107 ( 1 ) ;
break;
}
}
static int F_292 ( struct V_406 * V_4 , unsigned int V_437 ,
unsigned int V_438 , void * V_439 )
{
struct V_398 * V_370 = V_439 ;
struct V_440 * V_440 ;
struct V_409 * V_86 ;
struct V_410 * V_441 ;
int V_26 , V_177 , V_6 ;
int V_216 = - 1 ;
if ( ! V_370 )
return - V_204 ;
if ( V_438 > 1 && V_370 -> type != V_403 &&
V_370 -> type != V_404 )
return - V_204 ;
if ( V_370 -> type == V_403 )
V_370 -> V_8 &= ~ V_442 ;
V_6 = F_286 ( V_370 ) ;
if ( V_6 < 0 )
return - V_204 ;
V_177 = F_293 ( V_4 , V_437 , V_438 , V_439 ) ;
if ( V_177 < 0 )
return V_177 ;
if ( V_370 -> type == V_399 ) {
if ( F_281 ( V_6 , true ) )
V_216 = V_370 -> V_443 ;
else
V_177 = - V_52 ;
} else {
V_216 = F_283 ( V_6 , V_438 ) ;
}
if ( V_216 < 0 ) {
F_294 ( L_29 ) ;
goto V_444;
}
for ( V_26 = 0 ; V_26 < V_438 ; V_26 ++ ) {
V_440 = F_295 ( V_4 , V_437 + V_26 ) ;
V_441 = F_296 ( V_440 ) ;
if ( ! V_440 || ! V_441 ) {
V_177 = - V_204 ;
goto V_445;
}
V_177 = - V_52 ;
V_86 = F_4 ( sizeof( * V_86 ) , V_9 ) ;
if ( ! V_86 )
goto V_445;
V_440 -> V_446 = ( V_6 << 16 ) + V_26 ;
V_440 -> V_447 = V_86 ;
V_440 -> V_448 = & V_449 ;
F_291 ( V_86 , V_441 , V_370 , V_6 , V_216 , V_26 ) ;
F_297 ( V_437 + V_26 , V_450 ) ;
}
return 0 ;
V_445:
for ( V_26 -- ; V_26 >= 0 ; V_26 -- ) {
V_440 = F_295 ( V_4 , V_437 + V_26 ) ;
if ( V_440 )
F_131 ( V_440 -> V_447 ) ;
}
for ( V_26 = 0 ; V_26 < V_438 ; V_26 ++ )
F_285 ( V_6 , V_216 + V_26 ) ;
V_444:
F_298 ( V_4 , V_437 , V_438 ) ;
return V_177 ;
}
static void F_299 ( struct V_406 * V_4 , unsigned int V_437 ,
unsigned int V_438 )
{
struct V_412 * V_413 ;
struct V_440 * V_440 ;
struct V_409 * V_86 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_438 ; V_26 ++ ) {
V_440 = F_295 ( V_4 , V_437 + V_26 ) ;
if ( V_440 && V_440 -> V_447 ) {
V_86 = V_440 -> V_447 ;
V_413 = & V_86 -> V_412 ;
F_285 ( V_413 -> V_6 , V_413 -> V_216 ) ;
F_131 ( V_86 ) ;
}
}
F_298 ( V_4 , V_437 , V_438 ) ;
}
static void F_300 ( struct V_406 * V_4 ,
struct V_440 * V_440 )
{
struct V_409 * V_86 = V_440 -> V_447 ;
struct V_412 * V_413 = & V_86 -> V_412 ;
F_284 ( V_413 -> V_6 , V_413 -> V_216 , V_86 -> V_417 ) ;
}
static void F_301 ( struct V_406 * V_4 ,
struct V_440 * V_440 )
{
struct V_409 * V_86 = V_440 -> V_447 ;
struct V_412 * V_413 = & V_86 -> V_412 ;
union V_396 V_133 ;
V_133 . V_397 = 0 ;
F_284 ( V_413 -> V_6 , V_413 -> V_216 , V_86 -> V_417 ) ;
}
static int F_302 ( struct V_440 * V_86 ,
const struct V_451 * V_240 , bool V_452 )
{
struct V_409 * V_453 = V_86 -> V_447 ;
struct V_412 * V_413 = & V_453 -> V_412 ;
struct V_410 * V_441 = F_296 ( V_86 ) ;
struct V_440 * V_454 = V_86 -> V_455 ;
int V_177 ;
V_177 = V_454 -> V_448 -> V_456 ( V_454 , V_240 , V_452 ) ;
if ( V_177 < 0 || V_177 == V_457 )
return V_177 ;
V_453 -> V_417 . V_419 . V_420 = V_441 -> V_420 ;
V_453 -> V_417 . V_419 . V_424 = V_441 -> V_425 ;
F_284 ( V_413 -> V_6 , V_413 -> V_216 , V_453 -> V_417 ) ;
F_303 ( V_441 ) ;
return V_457 ;
}
static void F_304 ( struct V_440 * V_440 , struct V_414 * V_415 )
{
struct V_409 * V_453 = V_440 -> V_447 ;
* V_415 = V_453 -> V_416 ;
}
int F_305 ( struct V_53 * V_21 )
{
V_21 -> V_407 = F_306 ( NULL , & V_458 , V_21 ) ;
if ( ! V_21 -> V_407 )
return - V_52 ;
V_21 -> V_407 -> V_454 = F_307 () ;
V_21 -> V_408 = F_308 ( V_21 -> V_407 ) ;
return 0 ;
}
