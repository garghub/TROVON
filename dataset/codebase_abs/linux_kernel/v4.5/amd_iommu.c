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
if ( V_7 -> V_4 )
F_32 ( V_14 ) ;
F_33 ( V_46 [ V_7 -> V_6 ] -> V_56 ,
V_14 ) ;
F_34 ( V_14 ) ;
V_14 -> V_20 . V_61 = NULL ;
}
static void F_35 ( struct V_62 * V_63 )
{
if ( V_64 == NULL )
return;
V_63 -> V_65 = F_36 ( V_63 -> V_66 , 0444 , V_64 ,
& V_63 -> V_67 ) ;
}
static void F_37 ( void )
{
V_64 = F_38 ( L_1 , NULL ) ;
if ( V_64 == NULL )
return;
V_68 = F_39 ( L_2 , 0444 , V_64 ,
& V_69 ) ;
F_35 ( & V_70 ) ;
F_35 ( & V_71 ) ;
F_35 ( & V_72 ) ;
F_35 ( & V_73 ) ;
F_35 ( & V_74 ) ;
F_35 ( & V_75 ) ;
F_35 ( & V_76 ) ;
F_35 ( & V_77 ) ;
F_35 ( & V_78 ) ;
F_35 ( & V_79 ) ;
F_35 ( & V_80 ) ;
F_35 ( & V_81 ) ;
F_35 ( & V_82 ) ;
F_35 ( & V_83 ) ;
F_35 ( & V_84 ) ;
F_35 ( & V_85 ) ;
}
static void F_40 ( T_1 V_6 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 )
F_41 ( L_3 , V_26 ,
V_59 [ V_6 ] . V_86 [ V_26 ] ) ;
}
static void F_42 ( unsigned long V_87 )
{
struct V_88 * V_89 = F_43 ( V_87 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 )
F_41 ( L_4 , V_26 , V_89 -> V_86 [ V_26 ] ) ;
}
static void F_44 ( struct V_53 * V_21 , void * V_90 )
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
F_41 ( L_5 ) ;
return;
}
F_45 ( 1 ) ;
goto V_95;
}
F_46 ( V_105 L_6 ) ;
switch ( type ) {
case V_106 :
F_46 ( L_7
L_8 ,
F_47 ( V_6 ) , F_48 ( V_6 ) , F_49 ( V_6 ) ,
V_94 , V_8 ) ;
F_40 ( V_6 ) ;
break;
case V_107 :
F_46 ( L_9
L_10 ,
F_47 ( V_6 ) , F_48 ( V_6 ) , F_49 ( V_6 ) ,
V_91 , V_94 , V_8 ) ;
break;
case V_108 :
F_46 ( L_11
L_8 ,
F_47 ( V_6 ) , F_48 ( V_6 ) , F_49 ( V_6 ) ,
V_94 , V_8 ) ;
break;
case V_109 :
F_46 ( L_12
L_10 ,
F_47 ( V_6 ) , F_48 ( V_6 ) , F_49 ( V_6 ) ,
V_91 , V_94 , V_8 ) ;
break;
case V_110 :
F_46 ( L_13 , V_94 ) ;
F_42 ( V_94 ) ;
break;
case V_111 :
F_46 ( L_14
L_15 , V_94 , V_8 ) ;
break;
case V_112 :
F_46 ( L_16
L_17 ,
F_47 ( V_6 ) , F_48 ( V_6 ) , F_49 ( V_6 ) ,
V_94 ) ;
break;
case V_113 :
F_46 ( L_18
L_8 ,
F_47 ( V_6 ) , F_48 ( V_6 ) , F_49 ( V_6 ) ,
V_94 , V_8 ) ;
break;
default:
F_46 ( V_105 L_19 , type ) ;
}
memset ( V_90 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_50 ( struct V_53 * V_21 )
{
T_2 V_114 , V_115 ;
V_114 = F_51 ( V_21 -> V_116 + V_117 ) ;
V_115 = F_51 ( V_21 -> V_116 + V_118 ) ;
while ( V_114 != V_115 ) {
F_44 ( V_21 , V_21 -> V_119 + V_114 ) ;
V_114 = ( V_114 + V_120 ) % V_121 ;
}
F_52 ( V_114 , V_21 -> V_116 + V_117 ) ;
}
static void F_53 ( struct V_53 * V_21 , T_3 * V_122 )
{
struct V_123 V_124 ;
F_54 ( V_85 ) ;
if ( F_55 ( V_122 [ 0 ] ) != V_125 ) {
F_56 ( L_20 ) ;
return;
}
V_124 . V_94 = V_122 [ 1 ] ;
V_124 . V_126 = F_57 ( V_122 [ 0 ] ) ;
V_124 . V_127 = F_58 ( V_122 [ 0 ] ) ;
V_124 . V_128 = F_59 ( V_122 [ 0 ] ) ;
V_124 . V_8 = F_60 ( V_122 [ 0 ] ) ;
F_61 ( & V_129 , 0 , & V_124 ) ;
}
static void F_62 ( struct V_53 * V_21 )
{
T_2 V_114 , V_115 ;
if ( V_21 -> V_130 == NULL )
return;
V_114 = F_51 ( V_21 -> V_116 + V_131 ) ;
V_115 = F_51 ( V_21 -> V_116 + V_132 ) ;
while ( V_114 != V_115 ) {
volatile T_3 * V_122 ;
T_3 V_133 [ 2 ] ;
int V_26 ;
V_122 = ( T_3 * ) ( V_21 -> V_130 + V_114 ) ;
for ( V_26 = 0 ; V_26 < V_104 ; ++ V_26 ) {
if ( F_55 ( V_122 [ 0 ] ) != 0 )
break;
F_45 ( 1 ) ;
}
V_133 [ 0 ] = V_122 [ 0 ] ;
V_133 [ 1 ] = V_122 [ 1 ] ;
V_122 [ 0 ] = V_122 [ 1 ] = 0UL ;
V_114 = ( V_114 + V_134 ) % V_135 ;
F_52 ( V_114 , V_21 -> V_116 + V_131 ) ;
F_53 ( V_21 , V_133 ) ;
V_114 = F_51 ( V_21 -> V_116 + V_131 ) ;
V_115 = F_51 ( V_21 -> V_116 + V_132 ) ;
}
}
T_4 F_63 ( int V_136 , void * V_86 )
{
struct V_53 * V_21 = (struct V_53 * ) V_86 ;
T_2 V_137 = F_51 ( V_21 -> V_116 + V_138 ) ;
while ( V_137 & ( V_139 | V_140 ) ) {
F_52 ( ( V_139 | V_140 ) ,
V_21 -> V_116 + V_138 ) ;
if ( V_137 & V_139 ) {
F_64 ( L_21 ) ;
F_50 ( V_21 ) ;
}
if ( V_137 & V_140 ) {
F_64 ( L_22 ) ;
F_62 ( V_21 ) ;
}
V_137 = F_51 ( V_21 -> V_116 + V_138 ) ;
}
return V_141 ;
}
T_4 F_65 ( int V_136 , void * V_86 )
{
return V_142 ;
}
static int F_66 ( volatile T_3 * V_143 )
{
int V_26 = 0 ;
while ( * V_143 == 0 && V_26 < V_104 ) {
F_45 ( 1 ) ;
V_26 += 1 ;
}
if ( V_26 == V_104 ) {
F_67 ( L_23 ) ;
return - V_144 ;
}
return 0 ;
}
static void F_68 ( struct V_53 * V_21 ,
struct V_88 * V_89 ,
T_2 V_115 )
{
T_5 * V_145 ;
V_145 = V_21 -> V_146 + V_115 ;
V_115 = ( V_115 + sizeof( * V_89 ) ) % V_147 ;
memcpy ( V_145 , V_89 , sizeof( * V_89 ) ) ;
F_52 ( V_115 , V_21 -> V_116 + V_148 ) ;
}
static void F_69 ( struct V_88 * V_89 , T_3 V_94 )
{
F_70 ( V_94 & 0x7ULL ) ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = F_71 ( F_72 ( V_94 ) ) | V_149 ;
V_89 -> V_86 [ 1 ] = F_73 ( F_72 ( V_94 ) ) ;
V_89 -> V_86 [ 2 ] = 1 ;
F_74 ( V_89 , V_150 ) ;
}
static void F_75 ( struct V_88 * V_89 , T_1 V_6 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_6 ;
F_74 ( V_89 , V_151 ) ;
}
static void F_76 ( struct V_88 * V_89 , T_3 V_94 ,
T_6 V_152 , T_1 V_91 , int V_153 )
{
T_3 V_154 ;
bool V_155 ;
V_154 = F_77 ( V_94 , V_152 , V_37 ) ;
V_155 = false ;
if ( V_154 > 1 ) {
V_94 = V_156 ;
V_155 = true ;
}
V_94 &= V_157 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 1 ] |= V_91 ;
V_89 -> V_86 [ 2 ] = F_71 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_73 ( V_94 ) ;
F_74 ( V_89 , V_158 ) ;
if ( V_155 )
V_89 -> V_86 [ 2 ] |= V_159 ;
if ( V_153 )
V_89 -> V_86 [ 2 ] |= V_160 ;
}
static void F_78 ( struct V_88 * V_89 , T_1 V_6 , int V_161 ,
T_3 V_94 , T_6 V_152 )
{
T_3 V_154 ;
bool V_155 ;
V_154 = F_77 ( V_94 , V_152 , V_37 ) ;
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
V_89 -> V_86 [ 2 ] = F_71 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_73 ( V_94 ) ;
F_74 ( V_89 , V_162 ) ;
if ( V_155 )
V_89 -> V_86 [ 2 ] |= V_159 ;
}
static void F_79 ( struct V_88 * V_89 , T_1 V_91 , int V_126 ,
T_3 V_94 , bool V_152 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_94 &= ~ ( 0xfffULL ) ;
V_89 -> V_86 [ 0 ] = V_126 ;
V_89 -> V_86 [ 1 ] = V_91 ;
V_89 -> V_86 [ 2 ] = F_71 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_73 ( V_94 ) ;
V_89 -> V_86 [ 2 ] |= V_160 ;
V_89 -> V_86 [ 2 ] |= V_163 ;
if ( V_152 )
V_89 -> V_86 [ 2 ] |= V_159 ;
F_74 ( V_89 , V_158 ) ;
}
static void F_80 ( struct V_88 * V_89 , T_1 V_6 , int V_126 ,
int V_161 , T_3 V_94 , bool V_152 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_94 &= ~ ( 0xfffULL ) ;
V_89 -> V_86 [ 0 ] = V_6 ;
V_89 -> V_86 [ 0 ] |= ( ( V_126 >> 8 ) & 0xff ) << 16 ;
V_89 -> V_86 [ 0 ] |= ( V_161 & 0xff ) << 24 ;
V_89 -> V_86 [ 1 ] = V_6 ;
V_89 -> V_86 [ 1 ] |= ( V_126 & 0xff ) << 16 ;
V_89 -> V_86 [ 2 ] = F_71 ( V_94 ) ;
V_89 -> V_86 [ 2 ] |= V_163 ;
V_89 -> V_86 [ 3 ] = F_73 ( V_94 ) ;
if ( V_152 )
V_89 -> V_86 [ 2 ] |= V_159 ;
F_74 ( V_89 , V_162 ) ;
}
static void F_81 ( struct V_88 * V_89 , T_1 V_6 , int V_126 ,
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
F_74 ( V_89 , V_167 ) ;
}
static void F_82 ( struct V_88 * V_89 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
F_74 ( V_89 , V_168 ) ;
}
static void F_83 ( struct V_88 * V_89 , T_1 V_6 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_6 ;
F_74 ( V_89 , V_169 ) ;
}
static int F_84 ( struct V_53 * V_21 ,
struct V_88 * V_89 ,
bool V_170 )
{
T_2 V_171 , V_115 , V_114 , V_172 ;
unsigned long V_8 ;
V_173:
F_5 ( & V_21 -> V_174 , V_8 ) ;
V_114 = F_51 ( V_21 -> V_116 + V_175 ) ;
V_115 = F_51 ( V_21 -> V_116 + V_148 ) ;
V_172 = ( V_115 + sizeof( * V_89 ) ) % V_147 ;
V_171 = ( V_114 - V_172 ) % V_147 ;
if ( V_171 <= 2 ) {
struct V_88 V_176 ;
volatile T_3 V_143 = 0 ;
int V_177 ;
F_69 ( & V_176 , ( T_3 ) & V_143 ) ;
F_68 ( V_21 , & V_176 , V_115 ) ;
F_7 ( & V_21 -> V_174 , V_8 ) ;
if ( ( V_177 = F_66 ( & V_143 ) ) != 0 )
return V_177 ;
goto V_173;
}
F_68 ( V_21 , V_89 , V_115 ) ;
V_21 -> V_178 = V_170 ;
F_7 ( & V_21 -> V_174 , V_8 ) ;
return 0 ;
}
static int F_85 ( struct V_53 * V_21 , struct V_88 * V_89 )
{
return F_84 ( V_21 , V_89 , true ) ;
}
static int F_86 ( struct V_53 * V_21 )
{
struct V_88 V_89 ;
volatile T_3 V_143 = 0 ;
int V_177 ;
if ( ! V_21 -> V_178 )
return 0 ;
F_69 ( & V_89 , ( T_3 ) & V_143 ) ;
V_177 = F_84 ( V_21 , & V_89 , false ) ;
if ( V_177 )
return V_177 ;
return F_66 ( & V_143 ) ;
}
static int F_87 ( struct V_53 * V_21 , T_1 V_6 )
{
struct V_88 V_89 ;
F_75 ( & V_89 , V_6 ) ;
return F_85 ( V_21 , & V_89 ) ;
}
static void F_88 ( struct V_53 * V_21 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 <= 0xffff ; ++ V_6 )
F_87 ( V_21 , V_6 ) ;
F_86 ( V_21 ) ;
}
static void F_89 ( struct V_53 * V_21 )
{
T_2 V_179 ;
for ( V_179 = 0 ; V_179 <= 0xffff ; ++ V_179 ) {
struct V_88 V_89 ;
F_76 ( & V_89 , 0 , V_156 ,
V_179 , 1 ) ;
F_85 ( V_21 , & V_89 ) ;
}
F_86 ( V_21 ) ;
}
static void F_90 ( struct V_53 * V_21 )
{
struct V_88 V_89 ;
F_82 ( & V_89 ) ;
F_85 ( V_21 , & V_89 ) ;
F_86 ( V_21 ) ;
}
static void F_91 ( struct V_53 * V_21 , T_1 V_6 )
{
struct V_88 V_89 ;
F_83 ( & V_89 , V_6 ) ;
F_85 ( V_21 , & V_89 ) ;
}
static void F_92 ( struct V_53 * V_21 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 <= V_180 ; V_6 ++ )
F_91 ( V_21 , V_6 ) ;
F_86 ( V_21 ) ;
}
void F_93 ( struct V_53 * V_21 )
{
if ( F_94 ( V_21 , V_181 ) ) {
F_90 ( V_21 ) ;
} else {
F_88 ( V_21 ) ;
F_92 ( V_21 ) ;
F_89 ( V_21 ) ;
}
}
static int F_95 ( struct V_5 * V_7 ,
T_3 V_94 , T_6 V_152 )
{
struct V_53 * V_21 ;
struct V_88 V_89 ;
int V_161 ;
V_161 = V_7 -> V_182 . V_161 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
F_78 ( & V_89 , V_7 -> V_6 , V_161 , V_94 , V_152 ) ;
return F_85 ( V_21 , & V_89 ) ;
}
static int F_96 ( struct V_5 * V_7 )
{
struct V_53 * V_21 ;
T_1 V_57 ;
int V_177 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
V_57 = V_58 [ V_7 -> V_6 ] ;
V_177 = F_87 ( V_21 , V_7 -> V_6 ) ;
if ( ! V_177 && V_57 != V_7 -> V_6 )
V_177 = F_87 ( V_21 , V_57 ) ;
if ( V_177 )
return V_177 ;
if ( V_7 -> V_182 . V_183 )
V_177 = F_95 ( V_7 , 0 , ~ 0UL ) ;
return V_177 ;
}
static void F_97 ( struct V_1 * V_4 ,
T_3 V_94 , T_6 V_152 , int V_153 )
{
struct V_5 * V_7 ;
struct V_88 V_89 ;
int V_177 = 0 , V_26 ;
F_76 ( & V_89 , V_94 , V_152 , V_4 -> V_184 , V_153 ) ;
for ( V_26 = 0 ; V_26 < V_185 ; ++ V_26 ) {
if ( ! V_4 -> V_186 [ V_26 ] )
continue;
V_177 |= F_85 ( V_187 [ V_26 ] , & V_89 ) ;
}
F_9 (dev_data, &domain->dev_list, list) {
if ( ! V_7 -> V_182 . V_183 )
continue;
V_177 |= F_95 ( V_7 , V_94 , V_152 ) ;
}
F_70 ( V_177 ) ;
}
static void F_98 ( struct V_1 * V_4 ,
T_3 V_94 , T_6 V_152 )
{
F_97 ( V_4 , V_94 , V_152 , 0 ) ;
}
static void F_99 ( struct V_1 * V_4 )
{
F_97 ( V_4 , 0 , V_156 , 0 ) ;
}
static void F_100 ( struct V_1 * V_4 )
{
F_97 ( V_4 , 0 , V_156 , 1 ) ;
}
static void F_101 ( struct V_1 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_185 ; ++ V_26 ) {
if ( ! V_4 -> V_186 [ V_26 ] )
continue;
F_86 ( V_187 [ V_26 ] ) ;
}
}
static void F_102 ( struct V_1 * V_4 )
{
struct V_5 * V_7 ;
F_9 (dev_data, &domain->dev_list, list)
F_96 ( V_7 ) ;
}
static bool F_103 ( struct V_1 * V_4 ,
T_7 V_188 )
{
T_3 * V_189 ;
if ( V_4 -> V_190 == V_191 )
return false ;
V_189 = ( void * ) F_104 ( V_188 ) ;
if ( ! V_189 )
return false ;
* V_189 = F_105 ( V_4 -> V_190 ,
F_106 ( V_4 -> V_192 ) ) ;
V_4 -> V_192 = V_189 ;
V_4 -> V_190 += 1 ;
V_4 -> V_193 = true ;
return true ;
}
static T_3 * F_107 ( struct V_1 * V_4 ,
unsigned long V_94 ,
unsigned long V_194 ,
T_3 * * V_195 ,
T_7 V_188 )
{
int V_196 , V_197 ;
T_3 * V_189 , * V_198 ;
F_108 ( ! F_109 ( V_194 ) ) ;
while ( V_94 > F_110 ( V_4 -> V_190 ) )
F_103 ( V_4 , V_188 ) ;
V_196 = V_4 -> V_190 - 1 ;
V_189 = & V_4 -> V_192 [ F_111 ( V_196 , V_94 ) ] ;
V_94 = F_112 ( V_94 , V_194 ) ;
V_197 = F_113 ( V_194 ) ;
while ( V_196 > V_197 ) {
T_3 V_199 , V_200 ;
V_199 = * V_189 ;
if ( ! F_114 ( V_199 ) ) {
V_198 = ( T_3 * ) F_104 ( V_188 ) ;
if ( ! V_198 )
return NULL ;
V_200 = F_105 ( V_196 , F_106 ( V_198 ) ) ;
if ( F_115 ( V_189 , V_199 , V_200 ) ) {
F_116 ( ( unsigned long ) V_198 ) ;
continue;
}
}
if ( F_117 ( * V_189 ) != V_196 )
return NULL ;
V_196 -= 1 ;
V_189 = F_118 ( * V_189 ) ;
if ( V_195 && V_196 == V_197 )
* V_195 = V_189 ;
V_189 = & V_189 [ F_111 ( V_196 , V_94 ) ] ;
}
return V_189 ;
}
static T_3 * F_119 ( struct V_1 * V_4 ,
unsigned long V_94 ,
unsigned long * V_194 )
{
int V_196 ;
T_3 * V_189 ;
if ( V_94 > F_110 ( V_4 -> V_190 ) )
return NULL ;
V_196 = V_4 -> V_190 - 1 ;
V_189 = & V_4 -> V_192 [ F_111 ( V_196 , V_94 ) ] ;
* V_194 = F_120 ( V_196 ) ;
while ( V_196 > 0 ) {
if ( ! F_114 ( * V_189 ) )
return NULL ;
if ( F_117 ( * V_189 ) == 7 ||
F_117 ( * V_189 ) == 0 )
break;
if ( F_117 ( * V_189 ) != V_196 )
return NULL ;
V_196 -= 1 ;
V_189 = F_118 ( * V_189 ) ;
V_189 = & V_189 [ F_111 ( V_196 , V_94 ) ] ;
* V_194 = F_120 ( V_196 ) ;
}
if ( F_117 ( * V_189 ) == 0x07 ) {
unsigned long V_201 ;
* V_194 = V_201 = F_121 ( * V_189 ) ;
V_201 = ~ ( ( F_122 ( V_201 ) << 3 ) - 1 ) ;
V_189 = ( T_3 * ) ( ( ( unsigned long ) V_189 ) & V_201 ) ;
}
return V_189 ;
}
static int F_123 ( struct V_1 * V_3 ,
unsigned long V_202 ,
unsigned long V_87 ,
int V_203 ,
unsigned long V_194 )
{
T_3 V_199 , * V_189 ;
int V_26 , V_93 ;
F_108 ( ! F_124 ( V_202 , V_194 ) ) ;
F_108 ( ! F_124 ( V_87 , V_194 ) ) ;
if ( ! ( V_203 & V_204 ) )
return - V_205 ;
V_93 = F_122 ( V_194 ) ;
V_189 = F_107 ( V_3 , V_202 , V_194 , NULL , V_9 ) ;
if ( ! V_189 )
return - V_52 ;
for ( V_26 = 0 ; V_26 < V_93 ; ++ V_26 )
if ( F_114 ( V_189 [ V_26 ] ) )
return - V_206 ;
if ( V_93 > 1 ) {
V_199 = F_125 ( V_87 , V_194 ) ;
V_199 |= F_126 ( 7 ) | V_207 | V_208 ;
} else
V_199 = V_87 | V_207 | V_208 ;
if ( V_203 & V_209 )
V_199 |= V_210 ;
if ( V_203 & V_211 )
V_199 |= V_212 ;
for ( V_26 = 0 ; V_26 < V_93 ; ++ V_26 )
V_189 [ V_26 ] = V_199 ;
F_127 ( V_3 ) ;
return 0 ;
}
static unsigned long F_128 ( struct V_1 * V_3 ,
unsigned long V_202 ,
unsigned long V_194 )
{
unsigned long long V_213 ;
unsigned long V_214 ;
T_3 * V_189 ;
F_108 ( ! F_109 ( V_194 ) ) ;
V_213 = 0 ;
while ( V_213 < V_194 ) {
V_189 = F_119 ( V_3 , V_202 , & V_214 ) ;
if ( V_189 ) {
int V_26 , V_93 ;
V_93 = F_122 ( V_214 ) ;
for ( V_26 = 0 ; V_26 < V_93 ; V_26 ++ )
V_189 [ V_26 ] = 0ULL ;
}
V_202 = ( V_202 & ~ ( V_214 - 1 ) ) + V_214 ;
V_213 += V_214 ;
}
F_108 ( V_213 && ! F_109 ( V_213 ) ) ;
return V_213 ;
}
static void F_129 ( struct V_30 * V_3 ,
unsigned long V_215 ,
unsigned int V_154 )
{
unsigned int V_26 , V_216 = V_3 -> V_38 >> V_39 ;
if ( V_215 + V_154 > V_216 )
V_154 = V_216 - V_215 ;
for ( V_26 = V_215 ; V_26 < V_215 + V_154 ; ++ V_26 ) {
int V_217 = V_26 / V_218 ;
int V_198 = V_26 % V_218 ;
F_19 ( V_198 , V_3 -> V_40 [ V_217 ] -> V_41 ) ;
}
}
static int F_130 ( struct V_30 * V_31 ,
bool V_219 , T_7 V_188 )
{
int V_217 = V_31 -> V_38 >> V_220 ;
unsigned long V_26 , V_221 , V_222 ;
struct V_223 * V_224 ;
struct V_53 * V_21 ;
unsigned long V_8 ;
#ifdef F_131
V_219 = false ;
#endif
if ( V_217 >= V_225 )
return - V_52 ;
V_224 = F_4 ( sizeof( struct V_223 ) , V_188 ) ;
if ( ! V_224 )
return - V_52 ;
V_224 -> V_41 = ( void * ) F_104 ( V_188 ) ;
if ( ! V_224 -> V_41 )
goto V_226;
V_224 -> V_227 = V_31 -> V_38 ;
F_132 ( & V_224 -> V_228 ) ;
if ( V_219 ) {
unsigned long V_94 = V_31 -> V_38 ;
int V_26 , V_229 = V_218 / 512 ;
T_3 * V_189 , * V_195 ;
for ( V_26 = 0 ; V_26 < V_229 ; ++ V_26 ) {
V_189 = F_107 ( & V_31 -> V_4 , V_94 , V_37 ,
& V_195 , V_188 ) ;
if ( ! V_189 )
goto V_226;
V_224 -> V_230 [ V_26 ] = V_195 ;
V_94 += V_231 / 64 ;
}
}
F_5 ( & V_31 -> V_4 . V_174 , V_8 ) ;
F_133 ( & V_224 -> V_228 ) ;
V_221 = V_31 -> V_38 ;
V_31 -> V_40 [ V_217 ] = V_224 ;
V_31 -> V_38 += V_231 ;
if ( V_221 < V_232 &&
V_31 -> V_38 > V_232 ) {
unsigned long V_233 ;
int V_154 ;
V_154 = F_77 ( V_232 , 0x10000 , V_37 ) ;
V_233 = V_232 >> V_39 ;
F_129 ( V_31 , V_233 , V_154 ) ;
}
F_134 (iommu) {
if ( V_21 -> V_234 &&
V_21 -> V_234 >= V_31 -> V_40 [ V_217 ] -> V_227
&& V_21 -> V_234 < V_31 -> V_38 ) {
unsigned long V_235 ;
int V_154 = F_77 ( V_21 -> V_234 ,
V_21 -> V_236 ,
V_37 ) ;
V_235 = V_21 -> V_234 >> V_39 ;
F_129 ( V_31 , V_235 , V_154 ) ;
}
}
for ( V_26 = V_31 -> V_40 [ V_217 ] -> V_227 ;
V_26 < V_31 -> V_38 ;
V_26 += V_222 ) {
T_3 * V_189 = F_119 ( & V_31 -> V_4 , V_26 , & V_222 ) ;
if ( ! V_189 || ! F_114 ( * V_189 ) )
continue;
F_129 ( V_31 , V_26 >> V_39 ,
V_222 >> 12 ) ;
}
F_127 ( & V_31 -> V_4 ) ;
F_135 ( & V_224 -> V_228 ) ;
F_7 ( & V_31 -> V_4 . V_174 , V_8 ) ;
return 0 ;
V_226:
F_127 ( & V_31 -> V_4 ) ;
F_116 ( ( unsigned long ) V_224 -> V_41 ) ;
F_136 ( V_224 ) ;
return - V_52 ;
}
static T_8 F_137 ( struct V_30 * V_3 ,
struct V_223 * V_224 ,
unsigned long V_154 ,
unsigned long V_44 ,
unsigned long V_237 ,
unsigned long V_238 ,
bool V_239 )
{
unsigned long V_227 , V_240 , V_8 ;
T_8 V_94 ;
bool V_241 = false ;
V_227 = V_224 -> V_227 >> V_39 ;
V_240 = F_138 ( V_218 , V_227 ,
V_44 >> V_39 ) ;
if ( V_239 ) {
if ( ! F_139 ( & V_224 -> V_228 , V_8 ) )
return - 1 ;
} else {
F_5 ( & V_224 -> V_228 , V_8 ) ;
}
V_94 = F_140 ( V_224 -> V_41 , V_240 , V_224 -> V_242 ,
V_154 , V_227 , V_237 , V_238 ) ;
if ( V_94 == - 1 ) {
V_94 = F_140 ( V_224 -> V_41 , V_240 ,
0 , V_154 , V_227 , V_237 ,
V_238 ) ;
V_241 = true ;
}
if ( V_94 != - 1 )
V_224 -> V_242 = V_94 + V_154 ;
F_7 ( & V_224 -> V_228 , V_8 ) ;
if ( V_241 ) {
F_99 ( & V_3 -> V_4 ) ;
F_101 ( & V_3 -> V_4 ) ;
}
return V_94 ;
}
static unsigned long F_141 ( struct V_13 * V_14 ,
struct V_30 * V_3 ,
unsigned int V_154 ,
unsigned long V_238 ,
T_3 V_44 )
{
unsigned long V_237 , V_243 ;
unsigned long V_94 = - 1 ;
bool V_244 = true ;
T_2 V_245 , V_26 ;
F_142 () ;
V_243 = F_143 ( V_14 ) ;
V_173:
V_245 = F_144 ( * V_3 -> V_246 ) ;
if ( F_145 ( V_245 > V_225 ) ) {
V_245 = 0 ;
F_146 ( * V_3 -> V_246 , 0 ) ;
}
V_237 = V_243 + 1 ? F_147 ( V_243 + 1 , V_37 ) >> V_39 :
1UL << ( V_247 - V_39 ) ;
for ( V_26 = 0 ; V_26 < V_225 ; ++ V_26 ) {
struct V_223 * V_224 ;
int V_217 ;
V_217 = ( V_245 + V_26 ) % V_225 ;
V_224 = V_3 -> V_40 [ V_217 ] ;
if ( ! V_224 || V_224 -> V_227 >= V_44 )
continue;
V_94 = F_137 ( V_3 , V_224 , V_154 ,
V_44 , V_237 ,
V_238 , V_244 ) ;
if ( V_94 != - 1 ) {
V_94 = V_224 -> V_227 + ( V_94 << V_39 ) ;
F_146 ( * V_3 -> V_246 , V_217 ) ;
break;
}
}
if ( V_94 == - 1 && V_244 ) {
V_244 = false ;
goto V_173;
}
F_148 () ;
return V_94 ;
}
static unsigned long F_149 ( struct V_13 * V_14 ,
struct V_30 * V_3 ,
unsigned int V_154 ,
unsigned long V_238 ,
T_3 V_44 )
{
unsigned long V_94 = - 1 ;
while ( V_94 == - 1 ) {
V_94 = F_141 ( V_14 , V_3 , V_154 ,
V_238 , V_44 ) ;
if ( V_94 == - 1 && F_130 ( V_3 , false , V_248 ) )
break;
}
if ( F_145 ( V_94 == - 1 ) )
V_94 = V_249 ;
F_70 ( ( V_94 + ( V_37 * V_154 ) ) > V_3 -> V_38 ) ;
return V_94 ;
}
static void F_150 ( struct V_30 * V_3 ,
unsigned long V_94 ,
unsigned int V_154 )
{
unsigned V_26 = V_94 >> V_220 ;
struct V_223 * V_224 = V_3 -> V_40 [ V_26 ] ;
unsigned long V_8 ;
F_108 ( V_26 >= V_225 || V_224 == NULL ) ;
#ifdef F_131
if ( V_26 < 4 )
return;
#endif
if ( V_69 ) {
F_99 ( & V_3 -> V_4 ) ;
F_101 ( & V_3 -> V_4 ) ;
}
V_94 = ( V_94 % V_231 ) >> V_39 ;
F_5 ( & V_224 -> V_228 , V_8 ) ;
if ( V_94 + V_154 > V_224 -> V_242 )
V_224 -> V_242 = V_94 + V_154 ;
F_151 ( V_224 -> V_41 , V_94 , V_154 ) ;
F_7 ( & V_224 -> V_228 , V_8 ) ;
}
static void F_152 ( struct V_1 * V_4 )
{
unsigned long V_8 ;
F_5 ( & V_250 , V_8 ) ;
F_153 ( & V_4 -> V_251 , & V_252 ) ;
F_7 ( & V_250 , V_8 ) ;
}
static void F_154 ( struct V_1 * V_4 )
{
unsigned long V_8 ;
F_5 ( & V_250 , V_8 ) ;
F_155 ( & V_4 -> V_251 ) ;
F_7 ( & V_250 , V_8 ) ;
}
static T_1 F_156 ( void )
{
unsigned long V_8 ;
int V_184 ;
F_157 ( & V_253 , V_8 ) ;
V_184 = F_158 ( V_254 , V_255 ) ;
F_108 ( V_184 == 0 ) ;
if ( V_184 > 0 && V_184 < V_255 )
F_19 ( V_184 , V_254 ) ;
else
V_184 = 0 ;
F_159 ( & V_253 , V_8 ) ;
return V_184 ;
}
static void F_160 ( int V_184 )
{
unsigned long V_8 ;
F_157 ( & V_253 , V_8 ) ;
if ( V_184 > 0 && V_184 < V_255 )
F_161 ( V_184 , V_254 ) ;
F_159 ( & V_253 , V_8 ) ;
}
static void F_162 ( struct V_1 * V_4 )
{
unsigned long V_256 = ( unsigned long ) V_4 -> V_192 ;
switch ( V_4 -> V_190 ) {
case V_257 :
break;
case V_258 :
F_116 ( V_256 ) ;
break;
case V_259 :
F_163 ( V_256 ) ;
break;
case V_260 :
F_164 ( V_256 ) ;
break;
case V_261 :
F_165 ( V_256 ) ;
break;
case V_262 :
F_166 ( V_256 ) ;
break;
case V_191 :
F_167 ( V_256 ) ;
break;
default:
F_168 () ;
}
}
static void F_169 ( T_3 * V_263 )
{
T_3 * V_264 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 512 ; ++ V_26 ) {
if ( ! ( V_263 [ V_26 ] & V_265 ) )
continue;
V_264 = F_170 ( V_263 [ V_26 ] & V_157 ) ;
F_116 ( ( unsigned long ) V_264 ) ;
}
}
static void F_171 ( T_3 * V_263 )
{
T_3 * V_264 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 512 ; ++ V_26 ) {
if ( ! ( V_263 [ V_26 ] & V_265 ) )
continue;
V_264 = F_170 ( V_263 [ V_26 ] & V_157 ) ;
F_169 ( V_264 ) ;
}
}
static void F_172 ( struct V_1 * V_4 )
{
if ( V_4 -> V_266 == 2 )
F_171 ( V_4 -> V_267 ) ;
else if ( V_4 -> V_266 == 1 )
F_169 ( V_4 -> V_267 ) ;
else
F_108 ( V_4 -> V_266 != 0 ) ;
F_116 ( ( unsigned long ) V_4 -> V_267 ) ;
}
static void F_173 ( struct V_30 * V_3 )
{
int V_26 ;
if ( ! V_3 )
return;
F_174 ( V_3 -> V_246 ) ;
F_154 ( & V_3 -> V_4 ) ;
F_162 ( & V_3 -> V_4 ) ;
for ( V_26 = 0 ; V_26 < V_225 ; ++ V_26 ) {
if ( ! V_3 -> V_40 [ V_26 ] )
continue;
F_116 ( ( unsigned long ) V_3 -> V_40 [ V_26 ] -> V_41 ) ;
F_136 ( V_3 -> V_40 [ V_26 ] ) ;
}
F_136 ( V_3 ) ;
}
static int F_175 ( struct V_30 * V_31 ,
int V_268 )
{
int V_177 , V_26 , V_269 ;
V_269 = V_31 -> V_38 >> V_220 ;
V_177 = 0 ;
for ( V_26 = V_269 ; V_26 < V_268 ; ++ V_26 ) {
V_177 = F_130 ( V_31 , false , V_9 ) ;
if ( V_177 )
break;
}
return V_177 ;
}
static struct V_30 * F_176 ( void )
{
struct V_30 * V_31 ;
int V_270 ;
V_31 = F_4 ( sizeof( struct V_30 ) , V_9 ) ;
if ( ! V_31 )
return NULL ;
if ( F_177 ( & V_31 -> V_4 ) )
goto V_271;
V_31 -> V_246 = F_178 ( T_2 ) ;
if ( ! V_31 -> V_246 )
goto V_271;
V_31 -> V_4 . V_190 = V_259 ;
V_31 -> V_4 . V_192 = ( void * ) F_104 ( V_9 ) ;
V_31 -> V_4 . V_8 = V_272 ;
V_31 -> V_4 . V_51 = V_31 ;
if ( ! V_31 -> V_4 . V_192 )
goto V_271;
F_152 ( & V_31 -> V_4 ) ;
if ( F_130 ( V_31 , true , V_9 ) )
goto V_271;
V_31 -> V_40 [ 0 ] -> V_41 [ 0 ] = 1 ;
F_179 ( V_270 )
* F_180 ( V_31 -> V_246 , V_270 ) = 0 ;
return V_31 ;
V_271:
F_173 ( V_31 ) ;
return NULL ;
}
static bool V_30 ( struct V_1 * V_4 )
{
return V_4 -> V_8 & V_272 ;
}
static void F_181 ( T_1 V_6 , struct V_1 * V_4 , bool V_182 )
{
T_3 V_273 = 0 ;
T_3 V_8 = 0 ;
if ( V_4 -> V_190 != V_257 )
V_273 = F_106 ( V_4 -> V_192 ) ;
V_273 |= ( V_4 -> V_190 & V_274 )
<< V_275 ;
V_273 |= V_210 | V_212 | V_207 | V_276 ;
V_8 = V_59 [ V_6 ] . V_86 [ 1 ] ;
if ( V_182 )
V_8 |= V_277 ;
if ( V_4 -> V_8 & V_278 ) {
T_3 V_279 = F_72 ( V_4 -> V_267 ) ;
T_3 V_266 = V_4 -> V_266 ;
T_3 V_280 ;
V_273 |= V_281 ;
V_273 |= ( V_266 & V_282 ) << V_283 ;
V_280 = F_182 ( ~ 0ULL ) << V_284 ;
V_8 &= ~ V_280 ;
V_280 = F_183 ( ~ 0ULL ) << V_285 ;
V_8 &= ~ V_280 ;
V_280 = F_184 ( V_279 ) << V_286 ;
V_273 |= V_280 ;
V_280 = F_182 ( V_279 ) << V_284 ;
V_8 |= V_280 ;
V_280 = F_183 ( V_279 ) << V_285 ;
V_8 |= V_280 ;
}
V_8 &= ~ ( 0xffffUL ) ;
V_8 |= V_4 -> V_184 ;
V_59 [ V_6 ] . V_86 [ 1 ] = V_8 ;
V_59 [ V_6 ] . V_86 [ 0 ] = V_273 ;
}
static void F_185 ( T_1 V_6 )
{
V_59 [ V_6 ] . V_86 [ 0 ] = V_207 | V_276 ;
V_59 [ V_6 ] . V_86 [ 1 ] &= V_287 ;
F_186 ( V_6 ) ;
}
static void F_187 ( struct V_5 * V_7 ,
struct V_1 * V_4 )
{
struct V_53 * V_21 ;
T_1 V_57 ;
bool V_182 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
V_57 = V_58 [ V_7 -> V_6 ] ;
V_182 = V_7 -> V_182 . V_183 ;
V_7 -> V_4 = V_4 ;
F_153 ( & V_7 -> V_251 , & V_4 -> V_288 ) ;
V_4 -> V_186 [ V_21 -> V_217 ] += 1 ;
V_4 -> V_289 += 1 ;
F_181 ( V_7 -> V_6 , V_4 , V_182 ) ;
if ( V_57 != V_7 -> V_6 )
F_181 ( V_57 , V_4 , V_182 ) ;
F_96 ( V_7 ) ;
}
static void F_188 ( struct V_5 * V_7 )
{
struct V_53 * V_21 ;
T_1 V_57 ;
if ( ! V_7 -> V_4 )
return;
V_21 = V_46 [ V_7 -> V_6 ] ;
V_57 = V_58 [ V_7 -> V_6 ] ;
V_7 -> V_4 -> V_186 [ V_21 -> V_217 ] -= 1 ;
V_7 -> V_4 -> V_289 -= 1 ;
V_7 -> V_4 = NULL ;
F_155 ( & V_7 -> V_251 ) ;
F_185 ( V_7 -> V_6 ) ;
if ( V_57 != V_7 -> V_6 )
F_185 ( V_57 ) ;
F_96 ( V_7 ) ;
}
static int F_189 ( struct V_5 * V_7 ,
struct V_1 * V_4 )
{
int V_177 ;
F_70 ( ! F_190 () ) ;
F_133 ( & V_4 -> V_174 ) ;
V_177 = - V_206 ;
if ( V_7 -> V_4 != NULL )
goto V_12;
F_187 ( V_7 , V_4 ) ;
V_177 = 0 ;
V_12:
F_135 ( & V_4 -> V_174 ) ;
return V_177 ;
}
static void F_191 ( struct V_15 * V_16 )
{
F_192 ( V_16 ) ;
F_193 ( V_16 ) ;
F_194 ( V_16 ) ;
}
static int F_195 ( struct V_15 * V_16 )
{
T_1 V_290 ;
int V_27 ;
V_27 = F_16 ( V_16 , V_24 ) ;
if ( ! V_27 )
return - V_205 ;
F_196 ( V_16 , V_27 + V_291 , & V_290 ) ;
V_290 |= V_292 ;
F_197 ( V_16 , V_27 + V_291 , V_290 ) ;
return 0 ;
}
static int F_198 ( struct V_15 * V_16 )
{
bool V_293 ;
int V_294 , V_177 ;
V_294 = 32 ;
if ( F_17 ( V_16 , V_295 ) )
V_294 = 1 ;
V_293 = F_17 ( V_16 , V_296 ) ;
V_177 = F_199 ( V_16 , 0 ) ;
if ( V_177 )
goto V_297;
V_177 = F_200 ( V_16 ) ;
if ( V_177 )
goto V_297;
V_177 = F_201 ( V_16 , V_294 ) ;
if ( V_177 )
goto V_297;
if ( V_293 ) {
V_177 = F_195 ( V_16 ) ;
if ( V_177 )
goto V_297;
}
V_177 = F_202 ( V_16 , V_39 ) ;
if ( V_177 )
goto V_297;
return 0 ;
V_297:
F_193 ( V_16 ) ;
F_194 ( V_16 ) ;
return V_177 ;
}
static bool F_203 ( struct V_15 * V_16 )
{
T_1 V_137 ;
int V_27 ;
V_27 = F_16 ( V_16 , V_24 ) ;
if ( ! V_27 )
return false ;
F_196 ( V_16 , V_27 + V_298 , & V_137 ) ;
return ( V_137 & V_299 ) ? true : false ;
}
static int F_204 ( struct V_13 * V_14 ,
struct V_1 * V_4 )
{
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_5 * V_7 ;
unsigned long V_8 ;
int V_177 ;
V_7 = F_14 ( V_14 ) ;
if ( V_4 -> V_8 & V_278 ) {
if ( ! V_7 -> V_300 )
return - V_205 ;
if ( V_7 -> V_54 ) {
if ( F_198 ( V_16 ) != 0 )
return - V_205 ;
V_7 -> V_182 . V_183 = true ;
V_7 -> V_182 . V_161 = F_205 ( V_16 ) ;
V_7 -> V_301 = F_203 ( V_16 ) ;
}
} else if ( V_302 &&
F_202 ( V_16 , V_39 ) == 0 ) {
V_7 -> V_182 . V_183 = true ;
V_7 -> V_182 . V_161 = F_205 ( V_16 ) ;
}
F_157 ( & V_253 , V_8 ) ;
V_177 = F_189 ( V_7 , V_4 ) ;
F_159 ( & V_253 , V_8 ) ;
F_100 ( V_4 ) ;
return V_177 ;
}
static void F_206 ( struct V_5 * V_7 )
{
struct V_1 * V_4 ;
F_70 ( ! F_190 () ) ;
if ( F_70 ( ! V_7 -> V_4 ) )
return;
V_4 = V_7 -> V_4 ;
F_133 ( & V_4 -> V_174 ) ;
F_188 ( V_7 ) ;
F_135 ( & V_4 -> V_174 ) ;
}
static void F_32 ( struct V_13 * V_14 )
{
struct V_1 * V_4 ;
struct V_5 * V_7 ;
unsigned long V_8 ;
V_7 = F_14 ( V_14 ) ;
V_4 = V_7 -> V_4 ;
F_157 ( & V_253 , V_8 ) ;
F_206 ( V_7 ) ;
F_159 ( & V_253 , V_8 ) ;
if ( V_4 -> V_8 & V_278 && V_7 -> V_54 )
F_191 ( F_12 ( V_14 ) ) ;
else if ( V_7 -> V_182 . V_183 )
F_192 ( F_12 ( V_14 ) ) ;
V_7 -> V_182 . V_183 = false ;
}
static int F_207 ( struct V_13 * V_14 )
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
if ( V_177 != - V_303 )
F_41 ( L_24 ,
F_208 ( V_14 ) ) ;
F_30 ( V_14 ) ;
V_14 -> V_20 . V_61 = & V_304 ;
goto V_50;
}
F_23 ( V_14 ) ;
V_7 = F_14 ( V_14 ) ;
F_108 ( ! V_7 ) ;
if ( V_305 || V_7 -> V_54 )
F_209 ( V_14 ) ;
V_4 = F_210 ( V_14 ) ;
if ( V_4 -> type == V_306 )
V_7 -> V_300 = true ;
else
V_14 -> V_20 . V_61 = & V_307 ;
V_50:
F_86 ( V_21 ) ;
return 0 ;
}
static void F_211 ( struct V_13 * V_14 )
{
struct V_53 * V_21 ;
T_1 V_6 ;
if ( ! F_21 ( V_14 ) )
return;
V_6 = F_11 ( V_14 ) ;
V_21 = V_46 [ V_6 ] ;
F_31 ( V_14 ) ;
F_86 ( V_21 ) ;
}
static struct V_1 * F_212 ( struct V_13 * V_14 )
{
struct V_1 * V_4 ;
struct V_2 * V_308 ;
if ( ! F_21 ( V_14 ) )
return F_213 ( - V_205 ) ;
V_308 = F_210 ( V_14 ) ;
if ( ! V_308 )
return NULL ;
V_4 = F_1 ( V_308 ) ;
if ( ! V_30 ( V_4 ) )
return F_213 ( - V_206 ) ;
return V_4 ;
}
static void F_214 ( struct V_1 * V_4 )
{
struct V_5 * V_7 ;
F_9 (dev_data, &domain->dev_list, list)
F_181 ( V_7 -> V_6 , V_4 , V_7 -> V_182 . V_183 ) ;
}
static void F_127 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_193 )
return;
F_214 ( V_4 ) ;
F_102 ( V_4 ) ;
F_100 ( V_4 ) ;
V_4 -> V_193 = false ;
}
static T_3 * F_215 ( struct V_30 * V_3 ,
unsigned long V_94 )
{
struct V_223 * V_40 ;
T_3 * V_189 , * V_195 ;
V_40 = V_3 -> V_40 [ F_216 ( V_94 ) ] ;
if ( ! V_40 )
return NULL ;
V_189 = V_40 -> V_230 [ F_217 ( V_94 ) ] ;
if ( ! V_189 ) {
V_189 = F_107 ( & V_3 -> V_4 , V_94 , V_37 , & V_195 ,
V_248 ) ;
V_40 -> V_230 [ F_217 ( V_94 ) ] = V_195 ;
} else
V_189 += F_111 ( 0 , V_94 ) ;
F_127 ( & V_3 -> V_4 ) ;
return V_189 ;
}
static T_8 F_218 ( struct V_30 * V_3 ,
unsigned long V_94 ,
T_9 V_309 ,
int V_310 )
{
T_3 * V_189 , V_199 ;
F_70 ( V_94 > V_3 -> V_38 ) ;
V_309 &= V_157 ;
V_189 = F_215 ( V_3 , V_94 ) ;
if ( ! V_189 )
return V_249 ;
V_199 = V_309 | V_207 | V_208 ;
if ( V_310 == V_311 )
V_199 |= V_210 ;
else if ( V_310 == V_312 )
V_199 |= V_212 ;
else if ( V_310 == V_313 )
V_199 |= V_210 | V_212 ;
F_219 ( * V_189 ) ;
* V_189 = V_199 ;
return ( T_8 ) V_94 ;
}
static void F_220 ( struct V_30 * V_3 ,
unsigned long V_94 )
{
struct V_223 * V_40 ;
T_3 * V_189 ;
if ( V_94 >= V_3 -> V_38 )
return;
V_40 = V_3 -> V_40 [ F_216 ( V_94 ) ] ;
if ( ! V_40 )
return;
V_189 = V_40 -> V_230 [ F_217 ( V_94 ) ] ;
if ( ! V_189 )
return;
V_189 += F_111 ( 0 , V_94 ) ;
F_219 ( ! * V_189 ) ;
* V_189 = 0ULL ;
}
static T_8 F_221 ( struct V_13 * V_14 ,
struct V_30 * V_31 ,
T_9 V_309 ,
T_6 V_152 ,
int V_314 ,
bool V_315 ,
T_3 V_44 )
{
T_8 V_227 = V_309 & ~ V_157 ;
T_8 V_94 , V_245 , V_177 ;
unsigned int V_154 ;
unsigned long V_238 = 0 ;
int V_26 ;
V_154 = F_77 ( V_309 , V_152 , V_37 ) ;
V_309 &= V_157 ;
F_54 ( V_81 ) ;
if ( V_154 > 1 )
F_54 ( V_77 ) ;
if ( V_315 )
V_238 = ( 1UL << F_222 ( V_152 ) ) - 1 ;
V_94 = F_149 ( V_14 , V_31 , V_154 , V_238 ,
V_44 ) ;
if ( V_94 == V_249 )
goto V_50;
V_245 = V_94 ;
for ( V_26 = 0 ; V_26 < V_154 ; ++ V_26 ) {
V_177 = F_218 ( V_31 , V_245 , V_309 , V_314 ) ;
if ( V_177 == V_249 )
goto V_316;
V_309 += V_37 ;
V_245 += V_37 ;
}
V_94 += V_227 ;
F_223 ( V_80 , V_152 ) ;
if ( F_145 ( V_317 ) ) {
F_98 ( & V_31 -> V_4 , V_94 , V_152 ) ;
F_101 ( & V_31 -> V_4 ) ;
}
V_50:
return V_94 ;
V_316:
for ( -- V_26 ; V_26 >= 0 ; -- V_26 ) {
V_245 -= V_37 ;
F_220 ( V_31 , V_245 ) ;
}
F_150 ( V_31 , V_94 , V_154 ) ;
return V_249 ;
}
static void F_224 ( struct V_30 * V_31 ,
T_8 V_318 ,
T_6 V_152 ,
int V_314 )
{
T_8 V_319 ;
T_8 V_26 , V_245 ;
unsigned int V_154 ;
if ( ( V_318 == V_249 ) ||
( V_318 + V_152 > V_31 -> V_38 ) )
return;
V_319 = V_318 ;
V_154 = F_77 ( V_318 , V_152 , V_37 ) ;
V_318 &= V_157 ;
V_245 = V_318 ;
for ( V_26 = 0 ; V_26 < V_154 ; ++ V_26 ) {
F_220 ( V_31 , V_245 ) ;
V_245 += V_37 ;
}
F_225 ( V_80 , V_152 ) ;
F_150 ( V_31 , V_318 , V_154 ) ;
}
static T_8 F_226 ( struct V_13 * V_14 , struct V_198 * V_198 ,
unsigned long V_227 , T_6 V_152 ,
enum V_320 V_314 ,
struct V_321 * V_322 )
{
T_9 V_309 = F_227 ( V_198 ) + V_227 ;
struct V_1 * V_4 ;
T_3 V_44 ;
F_54 ( V_71 ) ;
V_4 = F_212 ( V_14 ) ;
if ( F_228 ( V_4 ) == - V_205 )
return ( T_8 ) V_309 ;
else if ( F_25 ( V_4 ) )
return V_249 ;
V_44 = * V_14 -> V_44 ;
return F_221 ( V_14 , V_4 -> V_51 , V_309 , V_152 , V_314 , false ,
V_44 ) ;
}
static void F_229 ( struct V_13 * V_14 , T_8 V_318 , T_6 V_152 ,
enum V_320 V_314 , struct V_321 * V_322 )
{
struct V_1 * V_4 ;
F_54 ( V_72 ) ;
V_4 = F_212 ( V_14 ) ;
if ( F_25 ( V_4 ) )
return;
F_224 ( V_4 -> V_51 , V_318 , V_152 , V_314 ) ;
}
static int F_230 ( struct V_13 * V_14 , struct V_323 * V_324 ,
int V_325 , enum V_320 V_314 ,
struct V_321 * V_322 )
{
struct V_1 * V_4 ;
int V_26 ;
struct V_323 * V_155 ;
T_9 V_309 ;
int V_326 = 0 ;
T_3 V_44 ;
F_54 ( V_73 ) ;
V_4 = F_212 ( V_14 ) ;
if ( F_25 ( V_4 ) )
return 0 ;
V_44 = * V_14 -> V_44 ;
F_231 (sglist, s, nelems, i) {
V_309 = F_232 ( V_155 ) ;
V_155 -> V_327 = F_221 ( V_14 , V_4 -> V_51 ,
V_309 , V_155 -> V_328 , V_314 , false ,
V_44 ) ;
if ( V_155 -> V_327 ) {
V_155 -> V_329 = V_155 -> V_328 ;
V_326 ++ ;
} else
goto V_330;
}
return V_326 ;
V_330:
F_231 (sglist, s, mapped_elems, i) {
if ( V_155 -> V_327 )
F_224 ( V_4 -> V_51 , V_155 -> V_327 ,
V_155 -> V_329 , V_314 ) ;
V_155 -> V_327 = V_155 -> V_329 = 0 ;
}
return 0 ;
}
static void F_233 ( struct V_13 * V_14 , struct V_323 * V_324 ,
int V_325 , enum V_320 V_314 ,
struct V_321 * V_322 )
{
struct V_1 * V_4 ;
struct V_323 * V_155 ;
int V_26 ;
F_54 ( V_74 ) ;
V_4 = F_212 ( V_14 ) ;
if ( F_25 ( V_4 ) )
return;
F_231 (sglist, s, nelems, i) {
F_224 ( V_4 -> V_51 , V_155 -> V_327 ,
V_155 -> V_329 , V_314 ) ;
V_155 -> V_327 = V_155 -> V_329 = 0 ;
}
}
static void * F_234 ( struct V_13 * V_14 , T_6 V_152 ,
T_8 * V_318 , T_7 V_331 ,
struct V_321 * V_322 )
{
T_3 V_44 = V_14 -> V_332 ;
struct V_1 * V_4 ;
struct V_198 * V_198 ;
F_54 ( V_75 ) ;
V_4 = F_212 ( V_14 ) ;
if ( F_228 ( V_4 ) == - V_205 ) {
V_198 = F_235 ( V_331 , F_222 ( V_152 ) ) ;
* V_318 = F_227 ( V_198 ) ;
return F_236 ( V_198 ) ;
} else if ( F_25 ( V_4 ) )
return NULL ;
V_152 = F_237 ( V_152 ) ;
V_44 = V_14 -> V_332 ;
V_331 &= ~ ( V_333 | V_334 | V_335 ) ;
V_331 |= V_336 ;
V_198 = F_235 ( V_331 | V_337 , F_222 ( V_152 ) ) ;
if ( ! V_198 ) {
if ( ! F_238 ( V_331 ) )
return NULL ;
V_198 = F_239 ( V_14 , V_152 >> V_39 ,
F_222 ( V_152 ) ) ;
if ( ! V_198 )
return NULL ;
}
if ( ! V_44 )
V_44 = * V_14 -> V_44 ;
* V_318 = F_221 ( V_14 , V_4 -> V_51 , F_227 ( V_198 ) ,
V_152 , V_313 , true , V_44 ) ;
if ( * V_318 == V_249 )
goto V_226;
return F_236 ( V_198 ) ;
V_226:
if ( ! F_240 ( V_14 , V_198 , V_152 >> V_39 ) )
F_241 ( V_198 , F_222 ( V_152 ) ) ;
return NULL ;
}
static void F_242 ( struct V_13 * V_14 , T_6 V_152 ,
void * V_338 , T_8 V_318 ,
struct V_321 * V_322 )
{
struct V_1 * V_4 ;
struct V_198 * V_198 ;
F_54 ( V_76 ) ;
V_198 = F_243 ( V_338 ) ;
V_152 = F_237 ( V_152 ) ;
V_4 = F_212 ( V_14 ) ;
if ( F_25 ( V_4 ) )
goto V_339;
F_224 ( V_4 -> V_51 , V_318 , V_152 , V_313 ) ;
V_339:
if ( ! F_240 ( V_14 , V_198 , V_152 >> V_39 ) )
F_241 ( V_198 , F_222 ( V_152 ) ) ;
}
static int F_244 ( struct V_13 * V_14 , T_3 V_243 )
{
return F_21 ( V_14 ) ;
}
static int F_245 ( struct V_13 * V_14 , T_3 V_243 )
{
struct V_1 * V_4 ;
int V_268 = 1 ;
V_4 = F_212 ( V_14 ) ;
if ( F_25 ( V_4 ) )
return F_228 ( V_4 ) ;
if ( V_243 == F_246 ( 64 ) )
V_268 = 8 ;
else if ( V_243 > F_246 ( 32 ) )
V_268 = 4 ;
if ( V_268 > F_247 () )
V_268 = F_247 () ;
if ( F_175 ( V_4 -> V_51 , V_268 ) )
F_248 ( V_14 , L_25 ,
V_268 ) ;
return 0 ;
}
int T_10 F_249 ( void )
{
return F_250 ( & V_340 , & V_341 ) ;
}
int T_10 F_251 ( void )
{
V_342 = V_305 ? 1 : 0 ;
V_343 = 1 ;
if ( ! V_342 )
V_61 = & V_304 ;
F_37 () ;
if ( V_69 )
F_252 ( L_26 ) ;
else
F_252 ( L_27 ) ;
return 0 ;
}
static void F_253 ( struct V_1 * V_4 )
{
struct V_5 * V_133 ;
unsigned long V_8 ;
F_157 ( & V_253 , V_8 ) ;
while ( ! F_254 ( & V_4 -> V_288 ) ) {
V_133 = F_255 ( & V_4 -> V_288 ,
struct V_5 , V_251 ) ;
F_206 ( V_133 ) ;
}
F_159 ( & V_253 , V_8 ) ;
}
static void F_256 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_154 ( V_4 ) ;
if ( V_4 -> V_184 )
F_160 ( V_4 -> V_184 ) ;
F_136 ( V_4 ) ;
}
static int F_177 ( struct V_1 * V_4 )
{
F_132 ( & V_4 -> V_174 ) ;
F_257 ( & V_4 -> V_344 ) ;
V_4 -> V_184 = F_156 () ;
if ( ! V_4 -> V_184 )
return - V_52 ;
F_258 ( & V_4 -> V_288 ) ;
return 0 ;
}
static struct V_1 * F_259 ( void )
{
struct V_1 * V_4 ;
V_4 = F_4 ( sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 )
return NULL ;
if ( F_177 ( V_4 ) )
goto V_297;
F_152 ( V_4 ) ;
return V_4 ;
V_297:
F_136 ( V_4 ) ;
return NULL ;
}
static struct V_2 * F_260 ( unsigned type )
{
struct V_1 * V_345 ;
struct V_30 * V_47 ;
switch ( type ) {
case V_346 :
V_345 = F_259 () ;
if ( ! V_345 )
return NULL ;
V_345 -> V_190 = V_260 ;
V_345 -> V_192 = ( void * ) F_104 ( V_9 ) ;
if ( ! V_345 -> V_192 ) {
F_256 ( V_345 ) ;
return NULL ;
}
V_345 -> V_4 . V_347 . V_348 = 0 ;
V_345 -> V_4 . V_347 . V_349 = ~ 0ULL ;
V_345 -> V_4 . V_347 . V_350 = true ;
break;
case V_351 :
V_47 = F_176 () ;
if ( ! V_47 ) {
F_41 ( L_28 ) ;
return NULL ;
}
V_345 = & V_47 -> V_4 ;
break;
case V_306 :
V_345 = F_259 () ;
if ( ! V_345 )
return NULL ;
V_345 -> V_190 = V_257 ;
break;
default:
return NULL ;
}
return & V_345 -> V_4 ;
}
static void F_261 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 )
return;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_289 > 0 )
F_253 ( V_4 ) ;
F_108 ( V_4 -> V_289 != 0 ) ;
if ( V_4 -> V_190 != V_257 )
F_162 ( V_4 ) ;
if ( V_4 -> V_8 & V_278 )
F_172 ( V_4 ) ;
F_256 ( V_4 ) ;
}
static void F_262 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_5 * V_7 = V_14 -> V_20 . V_21 ;
struct V_53 * V_21 ;
T_1 V_6 ;
if ( ! F_21 ( V_14 ) )
return;
V_6 = F_11 ( V_14 ) ;
if ( V_7 -> V_4 != NULL )
F_32 ( V_14 ) ;
V_21 = V_46 [ V_6 ] ;
if ( ! V_21 )
return;
F_86 ( V_21 ) ;
}
static int F_263 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_7 ;
struct V_53 * V_21 ;
int V_177 ;
if ( ! F_21 ( V_14 ) )
return - V_205 ;
V_7 = V_14 -> V_20 . V_21 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
if ( ! V_21 )
return - V_205 ;
if ( V_7 -> V_4 )
F_32 ( V_14 ) ;
V_177 = F_204 ( V_14 , V_4 ) ;
F_86 ( V_21 ) ;
return V_177 ;
}
static int F_264 ( struct V_2 * V_3 , unsigned long V_352 ,
T_9 V_309 , T_6 V_194 , int V_353 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_203 = 0 ;
int V_177 ;
if ( V_4 -> V_190 == V_257 )
return - V_205 ;
if ( V_353 & V_354 )
V_203 |= V_209 ;
if ( V_353 & V_355 )
V_203 |= V_211 ;
F_265 ( & V_4 -> V_344 ) ;
V_177 = F_123 ( V_4 , V_352 , V_309 , V_203 , V_194 ) ;
F_266 ( & V_4 -> V_344 ) ;
return V_177 ;
}
static T_6 F_267 ( struct V_2 * V_3 , unsigned long V_352 ,
T_6 V_194 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_6 V_214 ;
if ( V_4 -> V_190 == V_257 )
return - V_205 ;
F_265 ( & V_4 -> V_344 ) ;
V_214 = F_128 ( V_4 , V_352 , V_194 ) ;
F_266 ( & V_4 -> V_344 ) ;
F_100 ( V_4 ) ;
return V_214 ;
}
static T_9 F_268 ( struct V_2 * V_3 ,
T_8 V_352 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_356 , V_222 ;
T_3 * V_189 , V_199 ;
if ( V_4 -> V_190 == V_257 )
return V_352 ;
V_189 = F_119 ( V_4 , V_352 , & V_222 ) ;
if ( ! V_189 || ! F_114 ( * V_189 ) )
return 0 ;
V_356 = V_222 - 1 ;
V_199 = * V_189 & V_357 ;
return ( V_199 & ~ V_356 ) | ( V_352 & V_356 ) ;
}
static bool F_269 ( enum V_358 V_359 )
{
switch ( V_359 ) {
case V_360 :
return true ;
case V_361 :
return ( V_362 == 1 ) ;
case V_363 :
return false ;
}
return false ;
}
static void F_270 ( struct V_13 * V_14 ,
struct V_364 * V_114 )
{
struct V_32 * V_133 ;
T_1 V_6 ;
V_6 = F_11 ( V_14 ) ;
F_9 (entry, &amd_iommu_unity_map, list) {
struct V_365 * V_366 ;
if ( V_6 < V_133 -> V_42 || V_6 > V_133 -> V_43 )
continue;
V_366 = F_4 ( sizeof( * V_366 ) , V_9 ) ;
if ( ! V_366 ) {
F_41 ( L_29 ,
F_208 ( V_14 ) ) ;
return;
}
V_366 -> V_245 = V_133 -> V_35 ;
V_366 -> V_328 = V_133 -> V_36 - V_133 -> V_35 ;
if ( V_133 -> V_203 & V_209 )
V_366 -> V_203 |= V_354 ;
if ( V_133 -> V_203 & V_211 )
V_366 -> V_203 |= V_355 ;
F_6 ( & V_366 -> V_251 , V_114 ) ;
}
}
static void F_271 ( struct V_13 * V_14 ,
struct V_364 * V_114 )
{
struct V_365 * V_133 , * V_367 ;
F_272 (entry, next, head, list)
F_136 ( V_133 ) ;
}
int F_273 ( struct V_368 * V_369 )
{
return F_274 ( & V_129 , V_369 ) ;
}
int F_275 ( struct V_368 * V_369 )
{
return F_276 ( & V_129 , V_369 ) ;
}
void F_277 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_4 -> V_190 = V_257 ;
V_4 -> V_193 = true ;
F_127 ( V_4 ) ;
F_162 ( V_4 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
}
int F_278 ( struct V_2 * V_3 , int V_370 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_371 , V_177 ;
if ( V_370 <= 0 || V_370 > ( V_372 + 1 ) )
return - V_205 ;
for ( V_371 = 0 ; ( V_370 - 1 ) & ~ 0x1ff ; V_370 >>= 9 )
V_371 += 1 ;
if ( V_371 > V_373 )
return - V_205 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = - V_206 ;
if ( V_4 -> V_289 > 0 || V_4 -> V_8 & V_278 )
goto V_50;
V_177 = - V_52 ;
V_4 -> V_267 = ( void * ) F_104 ( V_248 ) ;
if ( V_4 -> V_267 == NULL )
goto V_50;
V_4 -> V_266 = V_371 ;
V_4 -> V_8 |= V_278 ;
V_4 -> V_193 = true ;
F_127 ( V_4 ) ;
V_177 = 0 ;
V_50:
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
static int F_279 ( struct V_1 * V_4 , int V_126 ,
T_3 V_94 , bool V_152 )
{
struct V_5 * V_7 ;
struct V_88 V_89 ;
int V_26 , V_177 ;
if ( ! ( V_4 -> V_8 & V_278 ) )
return - V_205 ;
F_79 ( & V_89 , V_4 -> V_184 , V_126 , V_94 , V_152 ) ;
for ( V_26 = 0 ; V_26 < V_185 ; ++ V_26 ) {
if ( V_4 -> V_186 [ V_26 ] == 0 )
continue;
V_177 = F_85 ( V_187 [ V_26 ] , & V_89 ) ;
if ( V_177 != 0 )
goto V_50;
}
F_101 ( V_4 ) ;
F_9 (dev_data, &domain->dev_list, list) {
struct V_53 * V_21 ;
int V_161 ;
if ( ! V_7 -> V_182 . V_183 )
continue;
V_161 = V_7 -> V_182 . V_161 ;
V_21 = V_46 [ V_7 -> V_6 ] ;
F_80 ( & V_89 , V_7 -> V_6 , V_126 ,
V_161 , V_94 , V_152 ) ;
V_177 = F_85 ( V_21 , & V_89 ) ;
if ( V_177 != 0 )
goto V_50;
}
F_101 ( V_4 ) ;
V_177 = 0 ;
V_50:
return V_177 ;
}
static int F_280 ( struct V_1 * V_4 , int V_126 ,
T_3 V_94 )
{
F_54 ( V_83 ) ;
return F_279 ( V_4 , V_126 , V_94 , false ) ;
}
int F_281 ( struct V_2 * V_3 , int V_126 ,
T_3 V_94 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_177 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = F_280 ( V_4 , V_126 , V_94 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
static int F_282 ( struct V_1 * V_4 , int V_126 )
{
F_54 ( V_84 ) ;
return F_279 ( V_4 , V_126 , V_156 ,
true ) ;
}
int F_283 ( struct V_2 * V_3 , int V_126 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_177 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = F_282 ( V_4 , V_126 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
static T_3 * F_284 ( T_3 * V_256 , int V_196 , int V_126 , bool V_374 )
{
int V_217 ;
T_3 * V_189 ;
while ( true ) {
V_217 = ( V_126 >> ( 9 * V_196 ) ) & 0x1ff ;
V_189 = & V_256 [ V_217 ] ;
if ( V_196 == 0 )
break;
if ( ! ( * V_189 & V_265 ) ) {
if ( ! V_374 )
return NULL ;
V_256 = ( void * ) F_104 ( V_248 ) ;
if ( V_256 == NULL )
return NULL ;
* V_189 = F_72 ( V_256 ) | V_265 ;
}
V_256 = F_170 ( * V_189 & V_157 ) ;
V_196 -= 1 ;
}
return V_189 ;
}
static int F_285 ( struct V_1 * V_4 , int V_126 ,
unsigned long V_375 )
{
T_3 * V_189 ;
if ( V_4 -> V_190 != V_257 )
return - V_205 ;
V_189 = F_284 ( V_4 -> V_267 , V_4 -> V_266 , V_126 , true ) ;
if ( V_189 == NULL )
return - V_52 ;
* V_189 = ( V_375 & V_157 ) | V_265 ;
return F_282 ( V_4 , V_126 ) ;
}
static int F_286 ( struct V_1 * V_4 , int V_126 )
{
T_3 * V_189 ;
if ( V_4 -> V_190 != V_257 )
return - V_205 ;
V_189 = F_284 ( V_4 -> V_267 , V_4 -> V_266 , V_126 , false ) ;
if ( V_189 == NULL )
return 0 ;
* V_189 = 0 ;
return F_282 ( V_4 , V_126 ) ;
}
int F_287 ( struct V_2 * V_3 , int V_126 ,
unsigned long V_375 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_177 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = F_285 ( V_4 , V_126 , V_375 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
int F_288 ( struct V_2 * V_3 , int V_126 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_177 ;
F_5 ( & V_4 -> V_174 , V_8 ) ;
V_177 = F_286 ( V_4 , V_126 ) ;
F_7 ( & V_4 -> V_174 , V_8 ) ;
return V_177 ;
}
int F_289 ( struct V_15 * V_16 , int V_126 ,
int V_137 , int V_128 )
{
struct V_5 * V_7 ;
struct V_53 * V_21 ;
struct V_88 V_89 ;
F_54 ( V_82 ) ;
V_7 = F_14 ( & V_16 -> V_14 ) ;
V_21 = V_46 [ V_7 -> V_6 ] ;
F_81 ( & V_89 , V_7 -> V_6 , V_126 , V_137 ,
V_128 , V_7 -> V_301 ) ;
return F_85 ( V_21 , & V_89 ) ;
}
struct V_2 * F_290 ( struct V_15 * V_16 )
{
struct V_1 * V_345 ;
V_345 = F_212 ( & V_16 -> V_14 ) ;
if ( F_25 ( V_345 ) )
return NULL ;
if ( ! ( V_345 -> V_8 & V_278 ) )
return NULL ;
return & V_345 -> V_4 ;
}
void F_291 ( struct V_15 * V_16 , T_2 V_28 )
{
struct V_5 * V_7 ;
if ( ! F_292 () )
return;
V_7 = F_14 ( & V_16 -> V_14 ) ;
V_7 -> V_29 |= ( 1 << V_28 ) ;
}
int F_293 ( struct V_15 * V_16 ,
struct F_293 * V_376 )
{
int V_377 ;
int V_27 ;
if ( V_16 == NULL || V_376 == NULL )
return - V_205 ;
if ( ! F_292 () )
return - V_205 ;
memset ( V_376 , 0 , sizeof( * V_376 ) ) ;
V_27 = F_16 ( V_16 , V_23 ) ;
if ( V_27 )
V_376 -> V_8 |= V_378 ;
V_27 = F_16 ( V_16 , V_24 ) ;
if ( V_27 )
V_376 -> V_8 |= V_379 ;
V_27 = F_16 ( V_16 , V_25 ) ;
if ( V_27 ) {
int V_380 ;
V_377 = 1 << ( 9 * ( V_373 + 1 ) ) ;
V_377 = F_294 ( V_377 , ( 1 << 20 ) ) ;
V_376 -> V_8 |= V_381 ;
V_376 -> V_377 = F_294 ( F_295 ( V_16 ) , V_377 ) ;
V_380 = F_296 ( V_16 ) ;
if ( V_380 & V_382 )
V_376 -> V_8 |= V_383 ;
if ( V_380 & V_384 )
V_376 -> V_8 |= V_385 ;
}
return 0 ;
}
static void F_297 ( T_1 V_6 , struct V_386 * V_387 )
{
T_3 V_388 ;
V_388 = V_59 [ V_6 ] . V_86 [ 2 ] ;
V_388 &= ~ V_389 ;
V_388 |= F_106 ( V_387 -> V_387 ) ;
V_388 |= V_390 ;
V_388 |= V_391 ;
V_388 |= V_392 ;
V_59 [ V_6 ] . V_86 [ 2 ] = V_388 ;
}
static struct V_386 * F_298 ( T_1 V_6 , bool V_393 )
{
struct V_386 * V_387 = NULL ;
struct V_53 * V_21 ;
unsigned long V_8 ;
T_1 V_57 ;
F_157 ( & V_253 , V_8 ) ;
V_21 = V_46 [ V_6 ] ;
if ( ! V_21 )
goto V_12;
V_387 = V_394 [ V_6 ] ;
if ( V_387 )
goto V_50;
V_57 = V_58 [ V_6 ] ;
V_387 = V_394 [ V_57 ] ;
if ( V_387 ) {
V_394 [ V_6 ] = V_387 ;
F_297 ( V_6 , V_387 ) ;
F_87 ( V_21 , V_6 ) ;
goto V_50;
}
V_387 = F_4 ( sizeof( * V_387 ) , V_248 ) ;
if ( ! V_387 )
goto V_50;
F_132 ( & V_387 -> V_174 ) ;
if ( V_393 )
V_387 -> V_395 = 32 ;
V_387 -> V_387 = F_299 ( V_396 , V_248 ) ;
if ( ! V_387 -> V_387 ) {
F_136 ( V_387 ) ;
V_387 = NULL ;
goto V_50;
}
memset ( V_387 -> V_387 , 0 , V_397 * sizeof( T_2 ) ) ;
if ( V_393 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < 32 ; ++ V_26 )
V_387 -> V_387 [ V_26 ] = V_398 ;
}
V_394 [ V_6 ] = V_387 ;
F_297 ( V_6 , V_387 ) ;
F_87 ( V_21 , V_6 ) ;
if ( V_6 != V_57 ) {
V_394 [ V_57 ] = V_387 ;
F_297 ( V_57 , V_387 ) ;
F_87 ( V_21 , V_57 ) ;
}
V_50:
F_86 ( V_21 ) ;
V_12:
F_159 ( & V_253 , V_8 ) ;
return V_387 ;
}
static int F_300 ( T_1 V_6 , int V_93 )
{
struct V_386 * V_387 ;
unsigned long V_8 ;
int V_217 , V_399 ;
V_387 = F_298 ( V_6 , false ) ;
if ( ! V_387 )
return - V_400 ;
F_5 ( & V_387 -> V_174 , V_8 ) ;
for ( V_399 = 0 , V_217 = V_387 -> V_395 ;
V_217 < V_397 ;
++ V_217 ) {
if ( V_387 -> V_387 [ V_217 ] == 0 )
V_399 += 1 ;
else
V_399 = 0 ;
if ( V_399 == V_93 ) {
for (; V_399 != 0 ; -- V_399 )
V_387 -> V_387 [ V_217 - V_399 + 1 ] = V_398 ;
V_217 -= V_93 - 1 ;
goto V_50;
}
}
V_217 = - V_401 ;
V_50:
F_7 ( & V_387 -> V_174 , V_8 ) ;
return V_217 ;
}
static int F_301 ( T_1 V_6 , int V_217 , union V_402 V_402 )
{
struct V_386 * V_387 ;
struct V_53 * V_21 ;
unsigned long V_8 ;
V_21 = V_46 [ V_6 ] ;
if ( V_21 == NULL )
return - V_205 ;
V_387 = F_298 ( V_6 , false ) ;
if ( ! V_387 )
return - V_52 ;
F_5 ( & V_387 -> V_174 , V_8 ) ;
V_387 -> V_387 [ V_217 ] = V_402 . V_403 ;
F_7 ( & V_387 -> V_174 , V_8 ) ;
F_91 ( V_21 , V_6 ) ;
F_86 ( V_21 ) ;
return 0 ;
}
static void F_302 ( T_1 V_6 , int V_217 )
{
struct V_386 * V_387 ;
struct V_53 * V_21 ;
unsigned long V_8 ;
V_21 = V_46 [ V_6 ] ;
if ( V_21 == NULL )
return;
V_387 = F_298 ( V_6 , false ) ;
if ( ! V_387 )
return;
F_5 ( & V_387 -> V_174 , V_8 ) ;
V_387 -> V_387 [ V_217 ] = 0 ;
F_7 ( & V_387 -> V_174 , V_8 ) ;
F_91 ( V_21 , V_6 ) ;
F_86 ( V_21 ) ;
}
static int F_303 ( struct V_404 * V_376 )
{
int V_6 = - 1 ;
switch ( V_376 -> type ) {
case V_405 :
V_6 = F_304 ( V_376 -> V_406 ) ;
break;
case V_407 :
V_6 = F_305 ( V_376 -> V_408 ) ;
break;
case V_409 :
case V_410 :
V_6 = F_11 ( & V_376 -> V_411 -> V_14 ) ;
break;
default:
F_108 ( 1 ) ;
break;
}
return V_6 ;
}
static struct V_412 * F_306 ( struct V_404 * V_376 )
{
struct V_53 * V_21 ;
int V_6 ;
if ( ! V_376 )
return NULL ;
V_6 = F_303 ( V_376 ) ;
if ( V_6 >= 0 ) {
V_21 = V_46 [ V_6 ] ;
if ( V_21 )
return V_21 -> V_413 ;
}
return NULL ;
}
static struct V_412 * F_307 ( struct V_404 * V_376 )
{
struct V_53 * V_21 ;
int V_6 ;
if ( ! V_376 )
return NULL ;
switch ( V_376 -> type ) {
case V_409 :
case V_410 :
V_6 = F_11 ( & V_376 -> V_411 -> V_14 ) ;
V_21 = V_46 [ V_6 ] ;
if ( V_21 )
return V_21 -> V_414 ;
break;
default:
break;
}
return NULL ;
}
static void F_308 ( struct V_415 * V_86 ,
struct V_416 * V_416 ,
struct V_404 * V_376 ,
int V_6 , int V_217 , int V_417 )
{
struct V_418 * V_419 = & V_86 -> V_418 ;
struct V_420 * V_421 = & V_86 -> V_422 ;
union V_402 * V_402 = & V_86 -> V_423 ;
struct V_424 * V_133 ;
V_86 -> V_418 . V_6 = V_6 ;
V_86 -> V_418 . V_217 = V_217 + V_417 ;
V_402 -> V_403 = 0 ;
V_402 -> V_425 . V_426 = V_416 -> V_426 ;
V_402 -> V_425 . V_427 = V_428 -> V_429 ;
V_402 -> V_425 . V_430 = V_416 -> V_431 ;
V_402 -> V_425 . V_432 = V_428 -> V_433 ;
V_402 -> V_425 . V_434 = 1 ;
switch ( V_376 -> type ) {
case V_405 :
V_133 = V_376 -> V_435 ;
V_376 -> V_435 = NULL ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_133 -> V_426 = V_217 ;
V_133 -> V_243 = 0 ;
V_133 -> V_436 = V_376 -> V_437 ;
V_133 -> V_438 = V_376 -> V_439 ;
if ( V_376 -> V_437 )
V_133 -> V_243 = 1 ;
break;
case V_407 :
case V_409 :
case V_410 :
V_421 -> V_440 = V_441 ;
V_421 -> V_442 = V_232 ;
V_421 -> V_86 = V_419 -> V_217 ;
break;
default:
F_108 ( 1 ) ;
break;
}
}
static int F_309 ( struct V_412 * V_4 , unsigned int V_443 ,
unsigned int V_444 , void * V_445 )
{
struct V_404 * V_376 = V_445 ;
struct V_446 * V_446 ;
struct V_415 * V_86 ;
struct V_416 * V_447 ;
int V_26 , V_177 , V_6 ;
int V_217 = - 1 ;
if ( ! V_376 )
return - V_205 ;
if ( V_444 > 1 && V_376 -> type != V_409 &&
V_376 -> type != V_410 )
return - V_205 ;
if ( V_376 -> type == V_409 )
V_376 -> V_8 &= ~ V_448 ;
V_6 = F_303 ( V_376 ) ;
if ( V_6 < 0 )
return - V_205 ;
V_177 = F_310 ( V_4 , V_443 , V_444 , V_445 ) ;
if ( V_177 < 0 )
return V_177 ;
if ( V_376 -> type == V_405 ) {
if ( F_298 ( V_6 , true ) )
V_217 = V_376 -> V_449 ;
else
V_177 = - V_52 ;
} else {
V_217 = F_300 ( V_6 , V_444 ) ;
}
if ( V_217 < 0 ) {
F_311 ( L_30 ) ;
goto V_450;
}
for ( V_26 = 0 ; V_26 < V_444 ; V_26 ++ ) {
V_446 = F_312 ( V_4 , V_443 + V_26 ) ;
V_447 = F_313 ( V_446 ) ;
if ( ! V_446 || ! V_447 ) {
V_177 = - V_205 ;
goto V_451;
}
V_177 = - V_52 ;
V_86 = F_4 ( sizeof( * V_86 ) , V_9 ) ;
if ( ! V_86 )
goto V_451;
V_446 -> V_452 = ( V_6 << 16 ) + V_26 ;
V_446 -> V_453 = V_86 ;
V_446 -> V_454 = & V_455 ;
F_308 ( V_86 , V_447 , V_376 , V_6 , V_217 , V_26 ) ;
F_314 ( V_443 + V_26 , V_456 ) ;
}
return 0 ;
V_451:
for ( V_26 -- ; V_26 >= 0 ; V_26 -- ) {
V_446 = F_312 ( V_4 , V_443 + V_26 ) ;
if ( V_446 )
F_136 ( V_446 -> V_453 ) ;
}
for ( V_26 = 0 ; V_26 < V_444 ; V_26 ++ )
F_302 ( V_6 , V_217 + V_26 ) ;
V_450:
F_315 ( V_4 , V_443 , V_444 ) ;
return V_177 ;
}
static void F_316 ( struct V_412 * V_4 , unsigned int V_443 ,
unsigned int V_444 )
{
struct V_418 * V_419 ;
struct V_446 * V_446 ;
struct V_415 * V_86 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_444 ; V_26 ++ ) {
V_446 = F_312 ( V_4 , V_443 + V_26 ) ;
if ( V_446 && V_446 -> V_453 ) {
V_86 = V_446 -> V_453 ;
V_419 = & V_86 -> V_418 ;
F_302 ( V_419 -> V_6 , V_419 -> V_217 ) ;
F_136 ( V_86 ) ;
}
}
F_315 ( V_4 , V_443 , V_444 ) ;
}
static void F_317 ( struct V_412 * V_4 ,
struct V_446 * V_446 )
{
struct V_415 * V_86 = V_446 -> V_453 ;
struct V_418 * V_419 = & V_86 -> V_418 ;
F_301 ( V_419 -> V_6 , V_419 -> V_217 , V_86 -> V_423 ) ;
}
static void F_318 ( struct V_412 * V_4 ,
struct V_446 * V_446 )
{
struct V_415 * V_86 = V_446 -> V_453 ;
struct V_418 * V_419 = & V_86 -> V_418 ;
union V_402 V_133 ;
V_133 . V_403 = 0 ;
F_301 ( V_419 -> V_6 , V_419 -> V_217 , V_86 -> V_423 ) ;
}
static int F_319 ( struct V_446 * V_86 ,
const struct V_457 * V_243 , bool V_458 )
{
struct V_415 * V_459 = V_86 -> V_453 ;
struct V_418 * V_419 = & V_459 -> V_418 ;
struct V_416 * V_447 = F_313 ( V_86 ) ;
struct V_446 * V_460 = V_86 -> V_461 ;
int V_177 ;
V_177 = V_460 -> V_454 -> V_462 ( V_460 , V_243 , V_458 ) ;
if ( V_177 < 0 || V_177 == V_463 )
return V_177 ;
V_459 -> V_423 . V_425 . V_426 = V_447 -> V_426 ;
V_459 -> V_423 . V_425 . V_430 = V_447 -> V_431 ;
F_301 ( V_419 -> V_6 , V_419 -> V_217 , V_459 -> V_423 ) ;
F_320 ( V_447 ) ;
return V_463 ;
}
static void F_321 ( struct V_446 * V_446 , struct V_420 * V_421 )
{
struct V_415 * V_459 = V_446 -> V_453 ;
* V_421 = V_459 -> V_422 ;
}
int F_322 ( struct V_53 * V_21 )
{
V_21 -> V_413 = F_323 ( NULL , & V_464 , V_21 ) ;
if ( ! V_21 -> V_413 )
return - V_52 ;
V_21 -> V_413 -> V_460 = F_324 () ;
V_21 -> V_414 = F_325 ( V_21 -> V_413 ) ;
return 0 ;
}
