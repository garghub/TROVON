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
static struct V_31 * F_22 ( T_1 V_6 )
{
struct V_31 * V_32 , * V_33 = NULL ;
unsigned long V_8 ;
T_1 V_34 = V_35 [ V_6 ] ;
if ( F_23 ( & V_36 ) )
return NULL ;
F_6 ( & V_37 , V_8 ) ;
F_13 (entry, &iommu_pd_list, list) {
if ( V_32 -> V_38 == V_6 ||
V_32 -> V_38 == V_34 ) {
V_33 = V_32 ;
break;
}
}
F_8 ( & V_37 , V_8 ) ;
return V_33 ;
}
static bool F_24 ( struct V_14 * V_15 )
{
T_1 V_6 ;
if ( ! V_15 || ! V_15 -> V_39 )
return false ;
if ( ! F_25 ( V_15 ) )
return false ;
V_6 = F_15 ( V_15 ) ;
if ( V_6 > V_40 )
return false ;
if ( V_41 [ V_6 ] == NULL )
return false ;
return true ;
}
static void F_26 ( struct V_14 * V_15 )
{
struct V_42 * V_43 ;
V_43 = F_27 ( V_15 ) ;
if ( ! F_28 ( V_43 ) )
F_29 ( V_43 ) ;
}
static int F_30 ( struct V_16 * V_17 , T_1 V_34 , void * V_44 )
{
* ( T_1 * ) V_44 = V_34 ;
return 0 ;
}
static T_1 F_31 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_16 ( V_15 ) ;
T_1 V_6 , V_45 , V_46 ;
V_6 = F_15 ( V_15 ) ;
V_45 = V_35 [ V_6 ] ;
F_32 ( V_17 , F_30 , & V_46 ) ;
if ( V_45 == V_46 )
return V_45 ;
if ( V_45 == V_6 ) {
if ( ! V_41 [ V_46 ] ) {
V_41 [ V_46 ] =
V_41 [ V_6 ] ;
memcpy ( V_47 [ V_46 ] . V_44 ,
V_47 [ V_6 ] . V_44 ,
sizeof( V_47 [ V_46 ] . V_44 ) ) ;
}
return V_46 ;
}
F_33 ( L_1
L_2
L_3 , F_34 ( V_45 ) , F_35 ( V_45 ) ,
F_36 ( V_45 ) , F_37 ( V_15 ) , V_17 -> V_48 , V_17 -> V_14 ,
F_34 ( V_46 ) , F_35 ( V_46 ) ,
F_36 ( V_46 ) ) ;
if ( V_46 == V_6 &&
F_34 ( V_45 ) == V_17 -> V_18 -> V_19 ) {
V_17 -> V_49 |= V_50 ;
V_17 -> V_51 = V_45 & 0xff ;
F_33 ( L_4 ,
F_35 ( V_45 ) , F_36 ( V_45 ) ,
F_37 ( V_15 ) ) ;
}
return V_45 ;
}
static int F_38 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_16 ( V_15 ) ;
struct V_5 * V_7 ;
T_1 V_34 ;
if ( V_15 -> V_21 . V_22 )
return 0 ;
V_7 = F_14 ( F_15 ( V_15 ) ) ;
if ( ! V_7 )
return - V_52 ;
V_34 = F_31 ( V_15 ) ;
if ( V_34 != V_7 -> V_6 ) {
struct V_5 * V_53 ;
V_53 = F_14 ( V_34 ) ;
if ( V_53 == NULL ) {
F_39 ( L_5 ,
F_37 ( V_15 ) ) ;
F_9 ( V_7 ) ;
return - V_54 ;
}
V_7 -> V_53 = V_53 ;
F_40 ( & V_7 -> V_10 , & V_53 -> V_10 ) ;
}
if ( F_19 ( V_17 ) ) {
struct V_55 * V_22 ;
V_22 = V_41 [ V_7 -> V_6 ] ;
V_7 -> V_56 = V_22 -> V_57 ;
}
V_15 -> V_21 . V_22 = V_7 ;
F_41 ( V_41 [ V_7 -> V_6 ] -> V_58 ,
V_15 ) ;
return 0 ;
}
static void F_42 ( struct V_14 * V_15 )
{
T_1 V_6 , V_34 ;
V_6 = F_15 ( V_15 ) ;
V_34 = V_35 [ V_6 ] ;
memset ( & V_47 [ V_6 ] , 0 , sizeof( struct V_59 ) ) ;
memset ( & V_47 [ V_34 ] , 0 , sizeof( struct V_59 ) ) ;
V_41 [ V_6 ] = NULL ;
V_41 [ V_34 ] = NULL ;
}
static void F_43 ( struct V_14 * V_15 )
{
struct V_5 * V_7 = F_12 ( F_15 ( V_15 ) ) ;
if ( ! V_7 )
return;
F_44 ( V_41 [ V_7 -> V_6 ] -> V_58 ,
V_15 ) ;
F_45 ( V_15 ) ;
V_7 -> V_53 = NULL ;
}
void T_3 F_46 ( void )
{
struct V_5 * V_7 , * V_60 ;
struct V_16 * V_17 = NULL ;
F_47 (pdev) {
if ( ! F_24 ( & V_17 -> V_15 ) )
continue;
F_43 ( & V_17 -> V_15 ) ;
}
F_48 (dev_data, n, &dev_data_list, dev_data_list)
F_9 ( V_7 ) ;
}
int T_3 F_49 ( void )
{
struct V_16 * V_17 = NULL ;
int V_33 = 0 ;
F_47 (pdev) {
if ( ! F_24 ( & V_17 -> V_15 ) )
continue;
V_33 = F_38 ( & V_17 -> V_15 ) ;
if ( V_33 == - V_54 )
F_42 ( & V_17 -> V_15 ) ;
else if ( V_33 )
goto V_61;
}
F_47 (pdev) {
if ( F_24 ( & V_17 -> V_15 ) )
F_26 ( & V_17 -> V_15 ) ;
}
return 0 ;
V_61:
F_46 () ;
return V_33 ;
}
static void F_50 ( struct V_62 * V_63 )
{
if ( V_64 == NULL )
return;
V_63 -> V_65 = F_51 ( V_63 -> V_66 , 0444 , V_64 ,
& V_63 -> V_67 ) ;
}
static void F_52 ( void )
{
V_64 = F_53 ( L_6 , NULL ) ;
if ( V_64 == NULL )
return;
V_68 = F_54 ( L_7 , 0444 , V_64 ,
& V_69 ) ;
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
F_50 ( & V_84 ) ;
F_50 ( & V_85 ) ;
}
static void F_55 ( T_1 V_6 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < 4 ; ++ V_27 )
F_39 ( L_8 , V_27 ,
V_47 [ V_6 ] . V_44 [ V_27 ] ) ;
}
static void F_56 ( unsigned long V_86 )
{
struct V_87 * V_88 = F_57 ( V_86 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 4 ; ++ V_27 )
F_39 ( L_9 , V_27 , V_88 -> V_44 [ V_27 ] ) ;
}
static void F_58 ( struct V_55 * V_22 , void * V_89 )
{
int type , V_6 , V_90 , V_8 ;
volatile T_2 * V_91 = V_89 ;
int V_92 = 0 ;
T_4 V_93 ;
V_94:
type = ( V_91 [ 1 ] >> V_95 ) & V_96 ;
V_6 = ( V_91 [ 0 ] >> V_97 ) & V_98 ;
V_90 = ( V_91 [ 1 ] >> V_99 ) & V_100 ;
V_8 = ( V_91 [ 1 ] >> V_101 ) & V_102 ;
V_93 = ( T_4 ) ( ( ( T_4 ) V_91 [ 3 ] ) << 32 ) | V_91 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_92 == V_103 ) {
F_39 ( L_10 ) ;
return;
}
F_59 ( 1 ) ;
goto V_94;
}
F_60 ( V_104 L_11 ) ;
switch ( type ) {
case V_105 :
F_60 ( L_12
L_13 ,
F_34 ( V_6 ) , F_35 ( V_6 ) , F_36 ( V_6 ) ,
V_93 , V_8 ) ;
F_55 ( V_6 ) ;
break;
case V_106 :
F_60 ( L_14
L_15 ,
F_34 ( V_6 ) , F_35 ( V_6 ) , F_36 ( V_6 ) ,
V_90 , V_93 , V_8 ) ;
break;
case V_107 :
F_60 ( L_16
L_13 ,
F_34 ( V_6 ) , F_35 ( V_6 ) , F_36 ( V_6 ) ,
V_93 , V_8 ) ;
break;
case V_108 :
F_60 ( L_17
L_15 ,
F_34 ( V_6 ) , F_35 ( V_6 ) , F_36 ( V_6 ) ,
V_90 , V_93 , V_8 ) ;
break;
case V_109 :
F_60 ( L_18 , V_93 ) ;
F_56 ( V_93 ) ;
break;
case V_110 :
F_60 ( L_19
L_20 , V_93 , V_8 ) ;
break;
case V_111 :
F_60 ( L_21
L_22 ,
F_34 ( V_6 ) , F_35 ( V_6 ) , F_36 ( V_6 ) ,
V_93 ) ;
break;
case V_112 :
F_60 ( L_23
L_13 ,
F_34 ( V_6 ) , F_35 ( V_6 ) , F_36 ( V_6 ) ,
V_93 , V_8 ) ;
break;
default:
F_60 ( V_104 L_24 , type ) ;
}
memset ( V_89 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_61 ( struct V_55 * V_22 )
{
T_2 V_113 , V_114 ;
V_113 = F_62 ( V_22 -> V_115 + V_116 ) ;
V_114 = F_62 ( V_22 -> V_115 + V_117 ) ;
while ( V_113 != V_114 ) {
F_58 ( V_22 , V_22 -> V_118 + V_113 ) ;
V_113 = ( V_113 + V_119 ) % V_22 -> V_120 ;
}
F_63 ( V_113 , V_22 -> V_115 + V_116 ) ;
}
static void F_64 ( struct V_55 * V_22 , T_4 * V_121 )
{
struct V_122 V_123 ;
F_65 ( V_85 ) ;
if ( F_66 ( V_121 [ 0 ] ) != V_124 ) {
F_67 ( L_25 ) ;
return;
}
V_123 . V_93 = V_121 [ 1 ] ;
V_123 . V_125 = F_68 ( V_121 [ 0 ] ) ;
V_123 . V_126 = F_69 ( V_121 [ 0 ] ) ;
V_123 . V_127 = F_70 ( V_121 [ 0 ] ) ;
V_123 . V_8 = F_71 ( V_121 [ 0 ] ) ;
F_72 ( & V_128 , 0 , & V_123 ) ;
}
static void F_73 ( struct V_55 * V_22 )
{
T_2 V_113 , V_114 ;
if ( V_22 -> V_129 == NULL )
return;
V_113 = F_62 ( V_22 -> V_115 + V_130 ) ;
V_114 = F_62 ( V_22 -> V_115 + V_131 ) ;
while ( V_113 != V_114 ) {
volatile T_4 * V_121 ;
T_4 V_32 [ 2 ] ;
int V_27 ;
V_121 = ( T_4 * ) ( V_22 -> V_129 + V_113 ) ;
for ( V_27 = 0 ; V_27 < V_103 ; ++ V_27 ) {
if ( F_66 ( V_121 [ 0 ] ) != 0 )
break;
F_59 ( 1 ) ;
}
V_32 [ 0 ] = V_121 [ 0 ] ;
V_32 [ 1 ] = V_121 [ 1 ] ;
V_121 [ 0 ] = V_121 [ 1 ] = 0UL ;
V_113 = ( V_113 + V_132 ) % V_133 ;
F_63 ( V_113 , V_22 -> V_115 + V_130 ) ;
F_64 ( V_22 , V_32 ) ;
V_113 = F_62 ( V_22 -> V_115 + V_130 ) ;
V_114 = F_62 ( V_22 -> V_115 + V_131 ) ;
}
}
T_5 F_74 ( int V_134 , void * V_44 )
{
struct V_55 * V_22 = (struct V_55 * ) V_44 ;
T_2 V_135 = F_62 ( V_22 -> V_115 + V_136 ) ;
while ( V_135 & ( V_137 | V_138 ) ) {
F_63 ( ( V_137 | V_138 ) ,
V_22 -> V_115 + V_136 ) ;
if ( V_135 & V_137 ) {
F_75 ( L_26 ) ;
F_61 ( V_22 ) ;
}
if ( V_135 & V_138 ) {
F_75 ( L_27 ) ;
F_73 ( V_22 ) ;
}
V_135 = F_62 ( V_22 -> V_115 + V_136 ) ;
}
return V_139 ;
}
T_5 F_76 ( int V_134 , void * V_44 )
{
return V_140 ;
}
static int F_77 ( volatile T_4 * V_141 )
{
int V_27 = 0 ;
while ( * V_141 == 0 && V_27 < V_103 ) {
F_59 ( 1 ) ;
V_27 += 1 ;
}
if ( V_27 == V_103 ) {
F_78 ( L_28 ) ;
return - V_142 ;
}
return 0 ;
}
static void F_79 ( struct V_55 * V_22 ,
struct V_87 * V_88 ,
T_2 V_114 )
{
T_6 * V_143 ;
V_143 = V_22 -> V_144 + V_114 ;
V_114 = ( V_114 + sizeof( * V_88 ) ) % V_22 -> V_145 ;
memcpy ( V_143 , V_88 , sizeof( * V_88 ) ) ;
F_63 ( V_114 , V_22 -> V_115 + V_146 ) ;
}
static void F_80 ( struct V_87 * V_88 , T_4 V_93 )
{
F_81 ( V_93 & 0x7ULL ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_44 [ 0 ] = F_82 ( F_83 ( V_93 ) ) | V_147 ;
V_88 -> V_44 [ 1 ] = F_84 ( F_83 ( V_93 ) ) ;
V_88 -> V_44 [ 2 ] = 1 ;
F_85 ( V_88 , V_148 ) ;
}
static void F_86 ( struct V_87 * V_88 , T_1 V_6 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_44 [ 0 ] = V_6 ;
F_85 ( V_88 , V_149 ) ;
}
static void F_87 ( struct V_87 * V_88 , T_4 V_93 ,
T_7 V_150 , T_1 V_90 , int V_151 )
{
T_4 V_152 ;
bool V_153 ;
V_152 = F_88 ( V_93 , V_150 , V_154 ) ;
V_153 = false ;
if ( V_152 > 1 ) {
V_93 = V_155 ;
V_153 = true ;
}
V_93 &= V_156 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_44 [ 1 ] |= V_90 ;
V_88 -> V_44 [ 2 ] = F_82 ( V_93 ) ;
V_88 -> V_44 [ 3 ] = F_84 ( V_93 ) ;
F_85 ( V_88 , V_157 ) ;
if ( V_153 )
V_88 -> V_44 [ 2 ] |= V_158 ;
if ( V_151 )
V_88 -> V_44 [ 2 ] |= V_159 ;
}
static void F_89 ( struct V_87 * V_88 , T_1 V_6 , int V_160 ,
T_4 V_93 , T_7 V_150 )
{
T_4 V_152 ;
bool V_153 ;
V_152 = F_88 ( V_93 , V_150 , V_154 ) ;
V_153 = false ;
if ( V_152 > 1 ) {
V_93 = V_155 ;
V_153 = true ;
}
V_93 &= V_156 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_44 [ 0 ] = V_6 ;
V_88 -> V_44 [ 0 ] |= ( V_160 & 0xff ) << 24 ;
V_88 -> V_44 [ 1 ] = V_6 ;
V_88 -> V_44 [ 2 ] = F_82 ( V_93 ) ;
V_88 -> V_44 [ 3 ] = F_84 ( V_93 ) ;
F_85 ( V_88 , V_161 ) ;
if ( V_153 )
V_88 -> V_44 [ 2 ] |= V_158 ;
}
static void F_90 ( struct V_87 * V_88 , T_1 V_90 , int V_125 ,
T_4 V_93 , bool V_150 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_93 &= ~ ( 0xfffULL ) ;
V_88 -> V_44 [ 0 ] = V_125 ;
V_88 -> V_44 [ 1 ] = V_90 ;
V_88 -> V_44 [ 2 ] = F_82 ( V_93 ) ;
V_88 -> V_44 [ 3 ] = F_84 ( V_93 ) ;
V_88 -> V_44 [ 2 ] |= V_159 ;
V_88 -> V_44 [ 2 ] |= V_162 ;
if ( V_150 )
V_88 -> V_44 [ 2 ] |= V_158 ;
F_85 ( V_88 , V_157 ) ;
}
static void F_91 ( struct V_87 * V_88 , T_1 V_6 , int V_125 ,
int V_160 , T_4 V_93 , bool V_150 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_93 &= ~ ( 0xfffULL ) ;
V_88 -> V_44 [ 0 ] = V_6 ;
V_88 -> V_44 [ 0 ] |= ( ( V_125 >> 8 ) & 0xff ) << 16 ;
V_88 -> V_44 [ 0 ] |= ( V_160 & 0xff ) << 24 ;
V_88 -> V_44 [ 1 ] = V_6 ;
V_88 -> V_44 [ 1 ] |= ( V_125 & 0xff ) << 16 ;
V_88 -> V_44 [ 2 ] = F_82 ( V_93 ) ;
V_88 -> V_44 [ 2 ] |= V_162 ;
V_88 -> V_44 [ 3 ] = F_84 ( V_93 ) ;
if ( V_150 )
V_88 -> V_44 [ 2 ] |= V_158 ;
F_85 ( V_88 , V_161 ) ;
}
static void F_92 ( struct V_87 * V_88 , T_1 V_6 , int V_125 ,
int V_135 , int V_127 , bool V_163 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_44 [ 0 ] = V_6 ;
if ( V_163 ) {
V_88 -> V_44 [ 1 ] = V_125 ;
V_88 -> V_44 [ 2 ] = V_162 ;
}
V_88 -> V_44 [ 3 ] = V_127 & 0x1ff ;
V_88 -> V_44 [ 3 ] |= ( V_135 & V_164 ) << V_165 ;
F_85 ( V_88 , V_166 ) ;
}
static void F_93 ( struct V_87 * V_88 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
F_85 ( V_88 , V_167 ) ;
}
static void F_94 ( struct V_87 * V_88 , T_1 V_6 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_44 [ 0 ] = V_6 ;
F_85 ( V_88 , V_168 ) ;
}
static int F_95 ( struct V_55 * V_22 ,
struct V_87 * V_88 ,
bool V_169 )
{
T_2 V_170 , V_114 , V_113 , V_171 ;
unsigned long V_8 ;
F_81 ( V_22 -> V_145 & V_172 ) ;
V_173:
F_6 ( & V_22 -> V_174 , V_8 ) ;
V_113 = F_62 ( V_22 -> V_115 + V_175 ) ;
V_114 = F_62 ( V_22 -> V_115 + V_146 ) ;
V_171 = ( V_114 + sizeof( * V_88 ) ) % V_22 -> V_145 ;
V_170 = ( V_113 - V_171 ) % V_22 -> V_145 ;
if ( V_170 <= 2 ) {
struct V_87 V_176 ;
volatile T_4 V_141 = 0 ;
int V_33 ;
F_80 ( & V_176 , ( T_4 ) & V_141 ) ;
F_79 ( V_22 , & V_176 , V_114 ) ;
F_8 ( & V_22 -> V_174 , V_8 ) ;
if ( ( V_33 = F_77 ( & V_141 ) ) != 0 )
return V_33 ;
goto V_173;
}
F_79 ( V_22 , V_88 , V_114 ) ;
V_22 -> V_177 = V_169 ;
F_8 ( & V_22 -> V_174 , V_8 ) ;
return 0 ;
}
static int F_96 ( struct V_55 * V_22 , struct V_87 * V_88 )
{
return F_95 ( V_22 , V_88 , true ) ;
}
static int F_97 ( struct V_55 * V_22 )
{
struct V_87 V_88 ;
volatile T_4 V_141 = 0 ;
int V_33 ;
if ( ! V_22 -> V_177 )
return 0 ;
F_80 ( & V_88 , ( T_4 ) & V_141 ) ;
V_33 = F_95 ( V_22 , & V_88 , false ) ;
if ( V_33 )
return V_33 ;
return F_77 ( & V_141 ) ;
}
static int F_98 ( struct V_55 * V_22 , T_1 V_6 )
{
struct V_87 V_88 ;
F_86 ( & V_88 , V_6 ) ;
return F_96 ( V_22 , & V_88 ) ;
}
static void F_99 ( struct V_55 * V_22 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 <= 0xffff ; ++ V_6 )
F_98 ( V_22 , V_6 ) ;
F_97 ( V_22 ) ;
}
static void F_100 ( struct V_55 * V_22 )
{
T_2 V_178 ;
for ( V_178 = 0 ; V_178 <= 0xffff ; ++ V_178 ) {
struct V_87 V_88 ;
F_87 ( & V_88 , 0 , V_155 ,
V_178 , 1 ) ;
F_96 ( V_22 , & V_88 ) ;
}
F_97 ( V_22 ) ;
}
static void F_101 ( struct V_55 * V_22 )
{
struct V_87 V_88 ;
F_93 ( & V_88 ) ;
F_96 ( V_22 , & V_88 ) ;
F_97 ( V_22 ) ;
}
static void F_102 ( struct V_55 * V_22 , T_1 V_6 )
{
struct V_87 V_88 ;
F_94 ( & V_88 , V_6 ) ;
F_96 ( V_22 , & V_88 ) ;
}
static void F_103 ( struct V_55 * V_22 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 <= V_179 ; V_6 ++ )
F_102 ( V_22 , V_6 ) ;
F_97 ( V_22 ) ;
}
void F_104 ( struct V_55 * V_22 )
{
if ( F_105 ( V_22 , V_180 ) ) {
F_101 ( V_22 ) ;
} else {
F_99 ( V_22 ) ;
F_103 ( V_22 ) ;
F_100 ( V_22 ) ;
}
}
static int F_106 ( struct V_5 * V_7 ,
T_4 V_93 , T_7 V_150 )
{
struct V_55 * V_22 ;
struct V_87 V_88 ;
int V_160 ;
V_160 = V_7 -> V_181 . V_160 ;
V_22 = V_41 [ V_7 -> V_6 ] ;
F_89 ( & V_88 , V_7 -> V_6 , V_160 , V_93 , V_150 ) ;
return F_96 ( V_22 , & V_88 ) ;
}
static int F_107 ( struct V_5 * V_7 )
{
struct V_55 * V_22 ;
int V_33 ;
V_22 = V_41 [ V_7 -> V_6 ] ;
V_33 = F_98 ( V_22 , V_7 -> V_6 ) ;
if ( V_33 )
return V_33 ;
if ( V_7 -> V_181 . V_182 )
V_33 = F_106 ( V_7 , 0 , ~ 0UL ) ;
return V_33 ;
}
static void F_108 ( struct V_1 * V_4 ,
T_4 V_93 , T_7 V_150 , int V_151 )
{
struct V_5 * V_7 ;
struct V_87 V_88 ;
int V_33 = 0 , V_27 ;
F_87 ( & V_88 , V_93 , V_150 , V_4 -> V_183 , V_151 ) ;
for ( V_27 = 0 ; V_27 < V_184 ; ++ V_27 ) {
if ( ! V_4 -> V_185 [ V_27 ] )
continue;
V_33 |= F_96 ( V_186 [ V_27 ] , & V_88 ) ;
}
F_13 (dev_data, &domain->dev_list, list) {
if ( ! V_7 -> V_181 . V_182 )
continue;
V_33 |= F_106 ( V_7 , V_93 , V_150 ) ;
}
F_81 ( V_33 ) ;
}
static void F_109 ( struct V_1 * V_4 ,
T_4 V_93 , T_7 V_150 )
{
F_108 ( V_4 , V_93 , V_150 , 0 ) ;
}
static void F_110 ( struct V_1 * V_4 )
{
F_108 ( V_4 , 0 , V_155 , 0 ) ;
}
static void F_111 ( struct V_1 * V_4 )
{
F_108 ( V_4 , 0 , V_155 , 1 ) ;
}
static void F_112 ( struct V_1 * V_4 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_184 ; ++ V_27 ) {
if ( ! V_4 -> V_185 [ V_27 ] )
continue;
F_97 ( V_186 [ V_27 ] ) ;
}
}
static void F_113 ( struct V_1 * V_4 )
{
struct V_5 * V_7 ;
F_13 (dev_data, &domain->dev_list, list)
F_107 ( V_7 ) ;
}
static bool F_114 ( struct V_1 * V_4 ,
T_8 V_187 )
{
T_4 * V_188 ;
if ( V_4 -> V_189 == V_190 )
return false ;
V_188 = ( void * ) F_115 ( V_187 ) ;
if ( ! V_188 )
return false ;
* V_188 = F_116 ( V_4 -> V_189 ,
F_117 ( V_4 -> V_191 ) ) ;
V_4 -> V_191 = V_188 ;
V_4 -> V_189 += 1 ;
V_4 -> V_192 = true ;
return true ;
}
static T_4 * F_118 ( struct V_1 * V_4 ,
unsigned long V_93 ,
unsigned long V_193 ,
T_4 * * V_194 ,
T_8 V_187 )
{
int V_195 , V_196 ;
T_4 * V_188 , * V_197 ;
F_119 ( ! F_120 ( V_193 ) ) ;
while ( V_93 > F_121 ( V_4 -> V_189 ) )
F_114 ( V_4 , V_187 ) ;
V_195 = V_4 -> V_189 - 1 ;
V_188 = & V_4 -> V_191 [ F_122 ( V_195 , V_93 ) ] ;
V_93 = F_123 ( V_93 , V_193 ) ;
V_196 = F_124 ( V_193 ) ;
while ( V_195 > V_196 ) {
if ( ! F_125 ( * V_188 ) ) {
V_197 = ( T_4 * ) F_115 ( V_187 ) ;
if ( ! V_197 )
return NULL ;
* V_188 = F_116 ( V_195 , F_117 ( V_197 ) ) ;
}
if ( F_126 ( * V_188 ) != V_195 )
return NULL ;
V_195 -= 1 ;
V_188 = F_127 ( * V_188 ) ;
if ( V_194 && V_195 == V_196 )
* V_194 = V_188 ;
V_188 = & V_188 [ F_122 ( V_195 , V_93 ) ] ;
}
return V_188 ;
}
static T_4 * F_128 ( struct V_1 * V_4 ,
unsigned long V_93 ,
unsigned long * V_193 )
{
int V_195 ;
T_4 * V_188 ;
if ( V_93 > F_121 ( V_4 -> V_189 ) )
return NULL ;
V_195 = V_4 -> V_189 - 1 ;
V_188 = & V_4 -> V_191 [ F_122 ( V_195 , V_93 ) ] ;
* V_193 = F_129 ( V_195 ) ;
while ( V_195 > 0 ) {
if ( ! F_125 ( * V_188 ) )
return NULL ;
if ( F_126 ( * V_188 ) == 7 ||
F_126 ( * V_188 ) == 0 )
break;
if ( F_126 ( * V_188 ) != V_195 )
return NULL ;
V_195 -= 1 ;
V_188 = F_127 ( * V_188 ) ;
V_188 = & V_188 [ F_122 ( V_195 , V_93 ) ] ;
* V_193 = F_129 ( V_195 ) ;
}
if ( F_126 ( * V_188 ) == 0x07 ) {
unsigned long V_198 ;
* V_193 = V_198 = F_130 ( * V_188 ) ;
V_198 = ~ ( ( F_131 ( V_198 ) << 3 ) - 1 ) ;
V_188 = ( T_4 * ) ( ( ( unsigned long ) V_188 ) & V_198 ) ;
}
return V_188 ;
}
static int F_132 ( struct V_1 * V_3 ,
unsigned long V_199 ,
unsigned long V_86 ,
int V_200 ,
unsigned long V_193 )
{
T_4 V_201 , * V_188 ;
int V_27 , V_92 ;
F_119 ( ! F_133 ( V_199 , V_193 ) ) ;
F_119 ( ! F_133 ( V_86 , V_193 ) ) ;
if ( ! ( V_200 & V_202 ) )
return - V_203 ;
V_92 = F_131 ( V_193 ) ;
V_188 = F_118 ( V_3 , V_199 , V_193 , NULL , V_9 ) ;
if ( ! V_188 )
return - V_52 ;
for ( V_27 = 0 ; V_27 < V_92 ; ++ V_27 )
if ( F_125 ( V_188 [ V_27 ] ) )
return - V_204 ;
if ( V_92 > 1 ) {
V_201 = F_134 ( V_86 , V_193 ) ;
V_201 |= F_135 ( 7 ) | V_205 | V_206 ;
} else
V_201 = V_86 | V_205 | V_206 ;
if ( V_200 & V_207 )
V_201 |= V_208 ;
if ( V_200 & V_209 )
V_201 |= V_210 ;
for ( V_27 = 0 ; V_27 < V_92 ; ++ V_27 )
V_188 [ V_27 ] = V_201 ;
F_136 ( V_3 ) ;
return 0 ;
}
static unsigned long F_137 ( struct V_1 * V_3 ,
unsigned long V_199 ,
unsigned long V_193 )
{
unsigned long long V_211 ;
unsigned long V_212 ;
T_4 * V_188 ;
F_119 ( ! F_120 ( V_193 ) ) ;
V_211 = 0 ;
while ( V_211 < V_193 ) {
V_188 = F_128 ( V_3 , V_199 , & V_212 ) ;
if ( V_188 ) {
int V_27 , V_92 ;
V_92 = F_131 ( V_212 ) ;
for ( V_27 = 0 ; V_27 < V_92 ; V_27 ++ )
V_188 [ V_27 ] = 0ULL ;
}
V_199 = ( V_199 & ~ ( V_212 - 1 ) ) + V_212 ;
V_211 += V_212 ;
}
F_119 ( V_211 && ! F_120 ( V_211 ) ) ;
return V_211 ;
}
static int F_138 ( struct V_55 * V_22 ,
struct V_213 * V_32 )
{
T_1 V_214 , V_27 ;
for ( V_27 = V_32 -> V_215 ; V_27 <= V_32 -> V_216 ; ++ V_27 ) {
V_214 = V_35 [ V_27 ] ;
if ( V_41 [ V_214 ] == V_22 )
return 1 ;
}
return 0 ;
}
static int F_139 ( struct V_31 * V_217 ,
struct V_213 * V_218 )
{
T_4 V_219 ;
int V_33 ;
for ( V_219 = V_218 -> V_220 ; V_219 < V_218 -> V_221 ;
V_219 += V_154 ) {
V_33 = F_132 ( & V_217 -> V_4 , V_219 , V_219 , V_218 -> V_200 ,
V_154 ) ;
if ( V_33 )
return V_33 ;
if ( V_219 < V_217 -> V_222 )
F_140 ( V_219 >> V_223 ,
V_217 -> V_224 [ 0 ] -> V_225 ) ;
}
return 0 ;
}
static int F_141 ( struct V_55 * V_22 )
{
struct V_213 * V_32 ;
int V_33 ;
F_13 (entry, &amd_iommu_unity_map, list) {
if ( ! F_138 ( V_22 , V_32 ) )
continue;
V_33 = F_139 ( V_22 -> V_226 , V_32 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_142 ( struct V_31 * V_217 ,
T_1 V_6 )
{
struct V_213 * V_218 ;
int V_33 ;
F_13 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_6 >= V_218 -> V_215 && V_6 <= V_218 -> V_216 ) )
continue;
V_33 = F_139 ( V_217 , V_218 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static void F_143 ( struct V_31 * V_3 ,
unsigned long V_227 ,
unsigned int V_152 )
{
unsigned int V_27 , V_228 = V_3 -> V_222 >> V_223 ;
if ( V_227 + V_152 > V_228 )
V_152 = V_228 - V_227 ;
for ( V_27 = V_227 ; V_27 < V_227 + V_152 ; ++ V_27 ) {
int V_229 = V_27 / V_230 ;
int V_197 = V_27 % V_230 ;
F_140 ( V_197 , V_3 -> V_224 [ V_229 ] -> V_225 ) ;
}
}
static int F_144 ( struct V_31 * V_217 ,
bool V_231 , T_8 V_187 )
{
int V_229 = V_217 -> V_222 >> V_232 ;
struct V_55 * V_22 ;
unsigned long V_27 , V_233 , V_234 ;
#ifdef F_145
V_231 = false ;
#endif
if ( V_229 >= V_235 )
return - V_52 ;
V_217 -> V_224 [ V_229 ] = F_4 ( sizeof( struct V_236 ) , V_187 ) ;
if ( ! V_217 -> V_224 [ V_229 ] )
return - V_52 ;
V_217 -> V_224 [ V_229 ] -> V_225 = ( void * ) F_115 ( V_187 ) ;
if ( ! V_217 -> V_224 [ V_229 ] -> V_225 )
goto V_61;
V_217 -> V_224 [ V_229 ] -> V_237 = V_217 -> V_222 ;
if ( V_231 ) {
unsigned long V_93 = V_217 -> V_222 ;
int V_27 , V_238 = V_230 / 512 ;
T_4 * V_188 , * V_194 ;
for ( V_27 = 0 ; V_27 < V_238 ; ++ V_27 ) {
V_188 = F_118 ( & V_217 -> V_4 , V_93 , V_154 ,
& V_194 , V_187 ) ;
if ( ! V_188 )
goto V_61;
V_217 -> V_224 [ V_229 ] -> V_239 [ V_27 ] = V_194 ;
V_93 += V_240 / 64 ;
}
}
V_233 = V_217 -> V_222 ;
V_217 -> V_222 += V_240 ;
if ( V_233 < V_241 &&
V_217 -> V_222 > V_241 ) {
unsigned long V_242 ;
int V_152 ;
V_152 = F_88 ( V_241 , 0x10000 , V_154 ) ;
V_242 = V_241 >> V_223 ;
F_143 ( V_217 , V_242 , V_152 ) ;
}
F_146 (iommu) {
if ( V_22 -> V_243 &&
V_22 -> V_243 >= V_217 -> V_224 [ V_229 ] -> V_237
&& V_22 -> V_243 < V_217 -> V_222 ) {
unsigned long V_244 ;
int V_152 = F_88 ( V_22 -> V_243 ,
V_22 -> V_245 ,
V_154 ) ;
V_244 = V_22 -> V_243 >> V_223 ;
F_143 ( V_217 , V_244 , V_152 ) ;
}
}
for ( V_27 = V_217 -> V_224 [ V_229 ] -> V_237 ;
V_27 < V_217 -> V_222 ;
V_27 += V_234 ) {
T_4 * V_188 = F_128 ( & V_217 -> V_4 , V_27 , & V_234 ) ;
if ( ! V_188 || ! F_125 ( * V_188 ) )
continue;
F_143 ( V_217 , V_27 >> V_223 ,
V_234 >> 12 ) ;
}
F_136 ( & V_217 -> V_4 ) ;
return 0 ;
V_61:
F_136 ( & V_217 -> V_4 ) ;
F_147 ( ( unsigned long ) V_217 -> V_224 [ V_229 ] -> V_225 ) ;
F_11 ( V_217 -> V_224 [ V_229 ] ) ;
V_217 -> V_224 [ V_229 ] = NULL ;
return - V_52 ;
}
static unsigned long F_148 ( struct V_14 * V_15 ,
struct V_31 * V_3 ,
unsigned int V_152 ,
unsigned long V_246 ,
T_4 V_39 ,
unsigned long V_247 )
{
unsigned long V_248 = V_3 -> V_249 % V_240 ;
int V_250 = V_3 -> V_222 >> V_232 ;
int V_27 = V_247 >> V_232 ;
unsigned long V_251 ;
unsigned long V_93 = - 1 ;
unsigned long V_252 ;
V_248 >>= V_223 ;
V_251 = F_149 ( F_150 ( V_15 ) + 1 ,
V_154 ) >> V_223 ;
for (; V_27 < V_250 ; ++ V_27 ) {
unsigned long V_237 = V_3 -> V_224 [ V_27 ] -> V_237 >> V_223 ;
if ( V_3 -> V_224 [ V_27 ] -> V_237 >= V_39 )
break;
V_252 = F_151 ( V_230 , V_237 ,
V_39 >> V_223 ) ;
V_93 = F_152 ( V_3 -> V_224 [ V_27 ] -> V_225 ,
V_252 , V_248 , V_152 , 0 ,
V_251 , V_246 ) ;
if ( V_93 != - 1 ) {
V_93 = V_3 -> V_224 [ V_27 ] -> V_237 +
( V_93 << V_223 ) ;
V_3 -> V_249 = V_93 + ( V_152 << V_223 ) ;
break;
}
V_248 = 0 ;
}
return V_93 ;
}
static unsigned long F_153 ( struct V_14 * V_15 ,
struct V_31 * V_3 ,
unsigned int V_152 ,
unsigned long V_246 ,
T_4 V_39 )
{
unsigned long V_93 ;
#ifdef F_145
V_3 -> V_249 = 0 ;
V_3 -> V_253 = true ;
#endif
V_93 = F_148 ( V_15 , V_3 , V_152 , V_246 ,
V_39 , V_3 -> V_249 ) ;
if ( V_93 == - 1 ) {
V_3 -> V_249 = 0 ;
V_93 = F_148 ( V_15 , V_3 , V_152 , V_246 ,
V_39 , 0 ) ;
V_3 -> V_253 = true ;
}
if ( F_154 ( V_93 == - 1 ) )
V_93 = V_254 ;
F_81 ( ( V_93 + ( V_154 * V_152 ) ) > V_3 -> V_222 ) ;
return V_93 ;
}
static void F_155 ( struct V_31 * V_3 ,
unsigned long V_93 ,
unsigned int V_152 )
{
unsigned V_27 = V_93 >> V_232 ;
struct V_236 * V_255 = V_3 -> V_224 [ V_27 ] ;
F_119 ( V_27 >= V_235 || V_255 == NULL ) ;
#ifdef F_145
if ( V_27 < 4 )
return;
#endif
if ( V_93 >= V_3 -> V_249 )
V_3 -> V_253 = true ;
V_93 = ( V_93 % V_240 ) >> V_223 ;
F_156 ( V_255 -> V_225 , V_93 , V_152 ) ;
}
static void F_157 ( struct V_1 * V_4 )
{
unsigned long V_8 ;
F_6 ( & V_256 , V_8 ) ;
F_40 ( & V_4 -> V_257 , & V_258 ) ;
F_8 ( & V_256 , V_8 ) ;
}
static void F_158 ( struct V_1 * V_4 )
{
unsigned long V_8 ;
F_6 ( & V_256 , V_8 ) ;
F_10 ( & V_4 -> V_257 ) ;
F_8 ( & V_256 , V_8 ) ;
}
static T_1 F_159 ( void )
{
unsigned long V_8 ;
int V_183 ;
F_160 ( & V_259 , V_8 ) ;
V_183 = F_161 ( V_260 , V_261 ) ;
F_119 ( V_183 == 0 ) ;
if ( V_183 > 0 && V_183 < V_261 )
F_140 ( V_183 , V_260 ) ;
else
V_183 = 0 ;
F_162 ( & V_259 , V_8 ) ;
return V_183 ;
}
static void F_163 ( int V_183 )
{
unsigned long V_8 ;
F_160 ( & V_259 , V_8 ) ;
if ( V_183 > 0 && V_183 < V_261 )
F_164 ( V_183 , V_260 ) ;
F_162 ( & V_259 , V_8 ) ;
}
static void F_165 ( struct V_1 * V_4 )
{
unsigned long V_262 = ( unsigned long ) V_4 -> V_191 ;
switch ( V_4 -> V_189 ) {
case V_263 :
break;
case V_264 :
F_147 ( V_262 ) ;
break;
case V_265 :
F_166 ( V_262 ) ;
break;
case V_266 :
F_167 ( V_262 ) ;
break;
case V_267 :
F_168 ( V_262 ) ;
break;
case V_268 :
F_169 ( V_262 ) ;
break;
case V_190 :
F_170 ( V_262 ) ;
break;
default:
F_171 () ;
}
}
static void F_172 ( T_4 * V_269 )
{
T_4 * V_270 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 512 ; ++ V_27 ) {
if ( ! ( V_269 [ V_27 ] & V_271 ) )
continue;
V_270 = F_173 ( V_269 [ V_27 ] & V_156 ) ;
F_147 ( ( unsigned long ) V_270 ) ;
}
}
static void F_174 ( T_4 * V_269 )
{
T_4 * V_270 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 512 ; ++ V_27 ) {
if ( ! ( V_269 [ V_27 ] & V_271 ) )
continue;
V_270 = F_173 ( V_269 [ V_27 ] & V_156 ) ;
F_172 ( V_270 ) ;
}
}
static void F_175 ( struct V_1 * V_4 )
{
if ( V_4 -> V_272 == 2 )
F_174 ( V_4 -> V_273 ) ;
else if ( V_4 -> V_272 == 1 )
F_172 ( V_4 -> V_273 ) ;
else if ( V_4 -> V_272 != 0 )
F_171 () ;
F_147 ( ( unsigned long ) V_4 -> V_273 ) ;
}
static void F_176 ( struct V_31 * V_3 )
{
int V_27 ;
if ( ! V_3 )
return;
F_158 ( & V_3 -> V_4 ) ;
F_165 ( & V_3 -> V_4 ) ;
for ( V_27 = 0 ; V_27 < V_235 ; ++ V_27 ) {
if ( ! V_3 -> V_224 [ V_27 ] )
continue;
F_147 ( ( unsigned long ) V_3 -> V_224 [ V_27 ] -> V_225 ) ;
F_11 ( V_3 -> V_224 [ V_27 ] ) ;
}
F_11 ( V_3 ) ;
}
static struct V_31 * F_177 ( void )
{
struct V_31 * V_217 ;
V_217 = F_4 ( sizeof( struct V_31 ) , V_9 ) ;
if ( ! V_217 )
return NULL ;
F_178 ( & V_217 -> V_4 . V_174 ) ;
V_217 -> V_4 . V_183 = F_159 () ;
if ( V_217 -> V_4 . V_183 == 0 )
goto V_274;
F_5 ( & V_217 -> V_4 . V_275 ) ;
V_217 -> V_4 . V_189 = V_265 ;
V_217 -> V_4 . V_191 = ( void * ) F_115 ( V_9 ) ;
V_217 -> V_4 . V_8 = V_276 ;
V_217 -> V_4 . V_277 = V_217 ;
if ( ! V_217 -> V_4 . V_191 )
goto V_274;
V_217 -> V_253 = false ;
V_217 -> V_38 = 0xffff ;
F_157 ( & V_217 -> V_4 ) ;
if ( F_144 ( V_217 , true , V_9 ) )
goto V_274;
V_217 -> V_224 [ 0 ] -> V_225 [ 0 ] = 1 ;
V_217 -> V_249 = 0 ;
return V_217 ;
V_274:
F_176 ( V_217 ) ;
return NULL ;
}
static bool V_31 ( struct V_1 * V_4 )
{
return V_4 -> V_8 & V_276 ;
}
static void F_179 ( T_1 V_6 , struct V_1 * V_4 , bool V_181 )
{
T_4 V_278 = 0 ;
T_4 V_8 = 0 ;
if ( V_4 -> V_189 != V_263 )
V_278 = F_117 ( V_4 -> V_191 ) ;
V_278 |= ( V_4 -> V_189 & V_279 )
<< V_280 ;
V_278 |= V_208 | V_210 | V_205 | V_281 ;
V_8 = V_47 [ V_6 ] . V_44 [ 1 ] ;
if ( V_181 )
V_8 |= V_282 ;
if ( V_4 -> V_8 & V_283 ) {
T_4 V_284 = F_83 ( V_4 -> V_273 ) ;
T_4 V_272 = V_4 -> V_272 ;
T_4 V_285 ;
V_278 |= V_286 ;
V_278 |= ( V_272 & V_287 ) << V_288 ;
V_285 = F_180 ( ~ 0ULL ) << V_289 ;
V_8 &= ~ V_285 ;
V_285 = F_181 ( ~ 0ULL ) << V_290 ;
V_8 &= ~ V_285 ;
V_285 = F_182 ( V_284 ) << V_291 ;
V_278 |= V_285 ;
V_285 = F_180 ( V_284 ) << V_289 ;
V_8 |= V_285 ;
V_285 = F_181 ( V_284 ) << V_290 ;
V_8 |= V_285 ;
}
V_8 &= ~ ( 0xffffUL ) ;
V_8 |= V_4 -> V_183 ;
V_47 [ V_6 ] . V_44 [ 1 ] = V_8 ;
V_47 [ V_6 ] . V_44 [ 0 ] = V_278 ;
}
static void F_183 ( T_1 V_6 )
{
V_47 [ V_6 ] . V_44 [ 0 ] = V_205 | V_281 ;
V_47 [ V_6 ] . V_44 [ 1 ] = 0 ;
F_184 ( V_6 ) ;
}
static void F_185 ( struct V_5 * V_7 ,
struct V_1 * V_4 )
{
struct V_55 * V_22 ;
bool V_181 ;
V_22 = V_41 [ V_7 -> V_6 ] ;
V_181 = V_7 -> V_181 . V_182 ;
V_7 -> V_4 = V_4 ;
F_40 ( & V_7 -> V_257 , & V_4 -> V_275 ) ;
F_179 ( V_7 -> V_6 , V_4 , V_181 ) ;
V_4 -> V_185 [ V_22 -> V_229 ] += 1 ;
V_4 -> V_292 += 1 ;
F_107 ( V_7 ) ;
}
static void F_186 ( struct V_5 * V_7 )
{
struct V_55 * V_22 ;
V_22 = V_41 [ V_7 -> V_6 ] ;
V_7 -> V_4 -> V_185 [ V_22 -> V_229 ] -= 1 ;
V_7 -> V_4 -> V_292 -= 1 ;
V_7 -> V_4 = NULL ;
F_10 ( & V_7 -> V_257 ) ;
F_183 ( V_7 -> V_6 ) ;
F_107 ( V_7 ) ;
}
static int F_187 ( struct V_5 * V_7 ,
struct V_1 * V_4 )
{
struct V_5 * V_113 , * V_32 ;
int V_33 ;
F_188 ( & V_4 -> V_174 ) ;
V_113 = V_7 ;
if ( V_113 -> V_53 != NULL )
V_113 = V_113 -> V_53 ;
V_33 = - V_204 ;
if ( V_113 -> V_4 != NULL )
goto V_13;
F_185 ( V_113 , V_4 ) ;
F_13 (entry, &head->alias_list, alias_list)
F_185 ( V_32 , V_4 ) ;
V_33 = 0 ;
V_13:
F_189 ( & V_4 -> V_174 ) ;
return V_33 ;
}
static void F_190 ( struct V_16 * V_17 )
{
F_191 ( V_17 ) ;
F_192 ( V_17 ) ;
F_193 ( V_17 ) ;
}
static int F_194 ( struct V_16 * V_17 )
{
T_1 V_293 ;
int V_28 ;
V_28 = F_20 ( V_17 , V_25 ) ;
if ( ! V_28 )
return - V_203 ;
F_195 ( V_17 , V_28 + V_294 , & V_293 ) ;
V_293 |= V_295 ;
F_196 ( V_17 , V_28 + V_294 , V_293 ) ;
return 0 ;
}
static int F_197 ( struct V_16 * V_17 )
{
bool V_296 ;
int V_297 , V_33 ;
V_297 = 32 ;
if ( F_21 ( V_17 , V_298 ) )
V_297 = 1 ;
V_296 = F_21 ( V_17 , V_299 ) ;
V_33 = F_198 ( V_17 , 0 ) ;
if ( V_33 )
goto V_300;
V_33 = F_199 ( V_17 ) ;
if ( V_33 )
goto V_300;
V_33 = F_200 ( V_17 , V_297 ) ;
if ( V_33 )
goto V_300;
if ( V_296 ) {
V_33 = F_194 ( V_17 ) ;
if ( V_33 )
goto V_300;
}
V_33 = F_201 ( V_17 , V_223 ) ;
if ( V_33 )
goto V_300;
return 0 ;
V_300:
F_192 ( V_17 ) ;
F_193 ( V_17 ) ;
return V_33 ;
}
static bool F_202 ( struct V_16 * V_17 )
{
T_1 V_135 ;
int V_28 ;
V_28 = F_20 ( V_17 , V_25 ) ;
if ( ! V_28 )
return false ;
F_195 ( V_17 , V_28 + V_301 , & V_135 ) ;
return ( V_135 & V_302 ) ? true : false ;
}
static int F_203 ( struct V_14 * V_15 ,
struct V_1 * V_4 )
{
struct V_16 * V_17 = F_16 ( V_15 ) ;
struct V_5 * V_7 ;
unsigned long V_8 ;
int V_33 ;
V_7 = F_18 ( V_15 ) ;
if ( V_4 -> V_8 & V_283 ) {
if ( ! V_7 -> V_56 || ! V_7 -> V_303 )
return - V_203 ;
if ( F_197 ( V_17 ) != 0 )
return - V_203 ;
V_7 -> V_181 . V_182 = true ;
V_7 -> V_181 . V_160 = F_204 ( V_17 ) ;
V_7 -> V_304 = F_202 ( V_17 ) ;
} else if ( V_305 &&
F_201 ( V_17 , V_223 ) == 0 ) {
V_7 -> V_181 . V_182 = true ;
V_7 -> V_181 . V_160 = F_204 ( V_17 ) ;
}
F_160 ( & V_259 , V_8 ) ;
V_33 = F_187 ( V_7 , V_4 ) ;
F_162 ( & V_259 , V_8 ) ;
F_111 ( V_4 ) ;
return V_33 ;
}
static void F_205 ( struct V_5 * V_7 )
{
struct V_5 * V_113 , * V_32 ;
struct V_1 * V_4 ;
unsigned long V_8 ;
F_119 ( ! V_7 -> V_4 ) ;
V_4 = V_7 -> V_4 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
V_113 = V_7 ;
if ( V_113 -> V_53 != NULL )
V_113 = V_113 -> V_53 ;
F_13 (entry, &head->alias_list, alias_list)
F_186 ( V_32 ) ;
F_186 ( V_113 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
if ( V_7 -> V_303 &&
( V_7 -> V_4 == NULL && V_4 != V_306 ) )
F_187 ( V_7 , V_306 ) ;
}
static void F_206 ( struct V_14 * V_15 )
{
struct V_1 * V_4 ;
struct V_5 * V_7 ;
unsigned long V_8 ;
V_7 = F_18 ( V_15 ) ;
V_4 = V_7 -> V_4 ;
F_160 ( & V_259 , V_8 ) ;
F_205 ( V_7 ) ;
F_162 ( & V_259 , V_8 ) ;
if ( V_4 -> V_8 & V_283 )
F_190 ( F_16 ( V_15 ) ) ;
else if ( V_7 -> V_181 . V_182 )
F_191 ( F_16 ( V_15 ) ) ;
V_7 -> V_181 . V_182 = false ;
}
static struct V_1 * F_207 ( struct V_14 * V_15 )
{
struct V_5 * V_7 ;
struct V_1 * V_3 = NULL ;
unsigned long V_8 ;
V_7 = F_18 ( V_15 ) ;
if ( V_7 -> V_4 )
return V_7 -> V_4 ;
if ( V_7 -> V_53 != NULL ) {
struct V_5 * V_53 = V_7 -> V_53 ;
F_208 ( & V_259 , V_8 ) ;
if ( V_53 -> V_4 != NULL ) {
F_187 ( V_7 , V_53 -> V_4 ) ;
V_3 = V_53 -> V_4 ;
}
F_209 ( & V_259 , V_8 ) ;
}
return V_3 ;
}
static int F_210 ( struct V_307 * V_308 ,
unsigned long V_309 , void * V_44 )
{
struct V_31 * V_310 ;
struct V_1 * V_4 ;
struct V_5 * V_7 ;
struct V_14 * V_15 = V_44 ;
struct V_55 * V_22 ;
unsigned long V_8 ;
T_1 V_6 ;
if ( ! F_24 ( V_15 ) )
return 0 ;
V_6 = F_15 ( V_15 ) ;
V_22 = V_41 [ V_6 ] ;
V_7 = F_18 ( V_15 ) ;
switch ( V_309 ) {
case V_311 :
F_38 ( V_15 ) ;
F_26 ( V_15 ) ;
V_7 = F_18 ( V_15 ) ;
if ( V_312 || V_7 -> V_56 ) {
V_7 -> V_303 = true ;
F_203 ( V_15 , V_306 ) ;
break;
}
V_4 = F_207 ( V_15 ) ;
V_310 = F_22 ( V_6 ) ;
if ( ! V_310 ) {
V_310 = F_177 () ;
if ( ! V_310 )
goto V_313;
V_310 -> V_38 = V_6 ;
F_6 ( & V_37 , V_8 ) ;
F_7 ( & V_310 -> V_257 , & V_36 ) ;
F_8 ( & V_37 , V_8 ) ;
}
V_15 -> V_21 . V_314 = & V_315 ;
break;
case V_316 :
F_43 ( V_15 ) ;
default:
goto V_313;
}
F_97 ( V_22 ) ;
V_313:
return 0 ;
}
void F_211 ( void )
{
F_212 ( & V_317 , & V_318 ) ;
}
static struct V_1 * F_213 ( struct V_14 * V_15 )
{
struct V_1 * V_4 ;
struct V_31 * V_217 ;
T_1 V_6 = F_15 ( V_15 ) ;
if ( ! F_24 ( V_15 ) )
return F_214 ( - V_203 ) ;
V_4 = F_207 ( V_15 ) ;
if ( V_4 != NULL && ! V_31 ( V_4 ) )
return F_214 ( - V_204 ) ;
if ( V_4 != NULL )
return V_4 ;
V_217 = F_22 ( V_6 ) ;
if ( ! V_217 )
V_217 = V_41 [ V_6 ] -> V_226 ;
F_203 ( V_15 , & V_217 -> V_4 ) ;
F_215 ( L_29 ,
V_217 -> V_4 . V_183 , F_37 ( V_15 ) ) ;
return & V_217 -> V_4 ;
}
static void F_216 ( struct V_1 * V_4 )
{
struct V_5 * V_7 ;
F_13 (dev_data, &domain->dev_list, list)
F_179 ( V_7 -> V_6 , V_4 , V_7 -> V_181 . V_182 ) ;
}
static void F_136 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_192 )
return;
F_216 ( V_4 ) ;
F_113 ( V_4 ) ;
F_111 ( V_4 ) ;
V_4 -> V_192 = false ;
}
static T_4 * F_217 ( struct V_31 * V_3 ,
unsigned long V_93 )
{
struct V_236 * V_224 ;
T_4 * V_188 , * V_194 ;
V_224 = V_3 -> V_224 [ F_218 ( V_93 ) ] ;
if ( ! V_224 )
return NULL ;
V_188 = V_224 -> V_239 [ F_219 ( V_93 ) ] ;
if ( ! V_188 ) {
V_188 = F_118 ( & V_3 -> V_4 , V_93 , V_154 , & V_194 ,
V_319 ) ;
V_224 -> V_239 [ F_219 ( V_93 ) ] = V_194 ;
} else
V_188 += F_122 ( 0 , V_93 ) ;
F_136 ( & V_3 -> V_4 ) ;
return V_188 ;
}
static T_9 F_220 ( struct V_31 * V_3 ,
unsigned long V_93 ,
T_10 V_320 ,
int V_321 )
{
T_4 * V_188 , V_201 ;
F_81 ( V_93 > V_3 -> V_222 ) ;
V_320 &= V_156 ;
V_188 = F_217 ( V_3 , V_93 ) ;
if ( ! V_188 )
return V_254 ;
V_201 = V_320 | V_205 | V_206 ;
if ( V_321 == V_322 )
V_201 |= V_208 ;
else if ( V_321 == V_323 )
V_201 |= V_210 ;
else if ( V_321 == V_324 )
V_201 |= V_208 | V_210 ;
F_81 ( * V_188 ) ;
* V_188 = V_201 ;
return ( T_9 ) V_93 ;
}
static void F_221 ( struct V_31 * V_3 ,
unsigned long V_93 )
{
struct V_236 * V_224 ;
T_4 * V_188 ;
if ( V_93 >= V_3 -> V_222 )
return;
V_224 = V_3 -> V_224 [ F_218 ( V_93 ) ] ;
if ( ! V_224 )
return;
V_188 = V_224 -> V_239 [ F_219 ( V_93 ) ] ;
if ( ! V_188 )
return;
V_188 += F_122 ( 0 , V_93 ) ;
F_81 ( ! * V_188 ) ;
* V_188 = 0ULL ;
}
static T_9 F_222 ( struct V_14 * V_15 ,
struct V_31 * V_217 ,
T_10 V_320 ,
T_7 V_150 ,
int V_325 ,
bool V_326 ,
T_4 V_39 )
{
T_9 V_237 = V_320 & ~ V_156 ;
T_9 V_93 , V_247 , V_33 ;
unsigned int V_152 ;
unsigned long V_246 = 0 ;
int V_27 ;
V_152 = F_88 ( V_320 , V_150 , V_154 ) ;
V_320 &= V_156 ;
F_65 ( V_81 ) ;
if ( V_152 > 1 )
F_65 ( V_77 ) ;
if ( V_326 )
V_246 = ( 1UL << F_223 ( V_150 ) ) - 1 ;
V_94:
V_93 = F_153 ( V_15 , V_217 , V_152 , V_246 ,
V_39 ) ;
if ( F_154 ( V_93 == V_254 ) ) {
V_217 -> V_249 = V_217 -> V_222 ;
if ( F_144 ( V_217 , false , V_319 ) )
goto V_313;
goto V_94;
}
V_247 = V_93 ;
for ( V_27 = 0 ; V_27 < V_152 ; ++ V_27 ) {
V_33 = F_220 ( V_217 , V_247 , V_320 , V_325 ) ;
if ( V_33 == V_254 )
goto V_327;
V_320 += V_154 ;
V_247 += V_154 ;
}
V_93 += V_237 ;
F_224 ( V_80 , V_150 ) ;
if ( F_154 ( V_217 -> V_253 && ! V_69 ) ) {
F_110 ( & V_217 -> V_4 ) ;
V_217 -> V_253 = false ;
} else if ( F_154 ( V_328 ) )
F_109 ( & V_217 -> V_4 , V_93 , V_150 ) ;
V_313:
return V_93 ;
V_327:
for ( -- V_27 ; V_27 >= 0 ; -- V_27 ) {
V_247 -= V_154 ;
F_221 ( V_217 , V_247 ) ;
}
F_155 ( V_217 , V_93 , V_152 ) ;
return V_254 ;
}
static void F_225 ( struct V_31 * V_217 ,
T_9 V_329 ,
T_7 V_150 ,
int V_325 )
{
T_9 V_330 ;
T_9 V_27 , V_247 ;
unsigned int V_152 ;
if ( ( V_329 == V_254 ) ||
( V_329 + V_150 > V_217 -> V_222 ) )
return;
V_330 = V_329 ;
V_152 = F_88 ( V_329 , V_150 , V_154 ) ;
V_329 &= V_156 ;
V_247 = V_329 ;
for ( V_27 = 0 ; V_27 < V_152 ; ++ V_27 ) {
F_221 ( V_217 , V_247 ) ;
V_247 += V_154 ;
}
F_226 ( V_80 , V_150 ) ;
F_155 ( V_217 , V_329 , V_152 ) ;
if ( V_69 || V_217 -> V_253 ) {
F_109 ( & V_217 -> V_4 , V_330 , V_150 ) ;
V_217 -> V_253 = false ;
}
}
static T_9 F_227 ( struct V_14 * V_15 , struct V_197 * V_197 ,
unsigned long V_237 , T_7 V_150 ,
enum V_331 V_325 ,
struct V_332 * V_333 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
T_9 V_219 ;
T_4 V_39 ;
T_10 V_320 = F_228 ( V_197 ) + V_237 ;
F_65 ( V_71 ) ;
V_4 = F_213 ( V_15 ) ;
if ( F_229 ( V_4 ) == - V_203 )
return ( T_9 ) V_320 ;
else if ( F_28 ( V_4 ) )
return V_254 ;
V_39 = * V_15 -> V_39 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
V_219 = F_222 ( V_15 , V_4 -> V_277 , V_320 , V_150 , V_325 , false ,
V_39 ) ;
if ( V_219 == V_254 )
goto V_313;
F_112 ( V_4 ) ;
V_313:
F_8 ( & V_4 -> V_174 , V_8 ) ;
return V_219 ;
}
static void F_230 ( struct V_14 * V_15 , T_9 V_329 , T_7 V_150 ,
enum V_331 V_325 , struct V_332 * V_333 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
F_65 ( V_72 ) ;
V_4 = F_213 ( V_15 ) ;
if ( F_28 ( V_4 ) )
return;
F_6 ( & V_4 -> V_174 , V_8 ) ;
F_225 ( V_4 -> V_277 , V_329 , V_150 , V_325 ) ;
F_112 ( V_4 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
}
static int F_231 ( struct V_14 * V_15 , struct V_334 * V_335 ,
int V_336 , enum V_331 V_325 ,
struct V_332 * V_333 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
int V_27 ;
struct V_334 * V_153 ;
T_10 V_320 ;
int V_337 = 0 ;
T_4 V_39 ;
F_65 ( V_73 ) ;
V_4 = F_213 ( V_15 ) ;
if ( F_28 ( V_4 ) )
return 0 ;
V_39 = * V_15 -> V_39 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
F_232 (sglist, s, nelems, i) {
V_320 = F_233 ( V_153 ) ;
V_153 -> V_338 = F_222 ( V_15 , V_4 -> V_277 ,
V_320 , V_153 -> V_339 , V_325 , false ,
V_39 ) ;
if ( V_153 -> V_338 ) {
V_153 -> V_340 = V_153 -> V_339 ;
V_337 ++ ;
} else
goto V_341;
}
F_112 ( V_4 ) ;
V_313:
F_8 ( & V_4 -> V_174 , V_8 ) ;
return V_337 ;
V_341:
F_232 (sglist, s, mapped_elems, i) {
if ( V_153 -> V_338 )
F_225 ( V_4 -> V_277 , V_153 -> V_338 ,
V_153 -> V_340 , V_325 ) ;
V_153 -> V_338 = V_153 -> V_340 = 0 ;
}
V_337 = 0 ;
goto V_313;
}
static void F_234 ( struct V_14 * V_15 , struct V_334 * V_335 ,
int V_336 , enum V_331 V_325 ,
struct V_332 * V_333 )
{
unsigned long V_8 ;
struct V_1 * V_4 ;
struct V_334 * V_153 ;
int V_27 ;
F_65 ( V_74 ) ;
V_4 = F_213 ( V_15 ) ;
if ( F_28 ( V_4 ) )
return;
F_6 ( & V_4 -> V_174 , V_8 ) ;
F_232 (sglist, s, nelems, i) {
F_225 ( V_4 -> V_277 , V_153 -> V_338 ,
V_153 -> V_340 , V_325 ) ;
V_153 -> V_338 = V_153 -> V_340 = 0 ;
}
F_112 ( V_4 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
}
static void * F_235 ( struct V_14 * V_15 , T_7 V_150 ,
T_9 * V_329 , T_8 V_342 ,
struct V_332 * V_333 )
{
T_4 V_39 = V_15 -> V_343 ;
struct V_1 * V_4 ;
unsigned long V_8 ;
struct V_197 * V_197 ;
F_65 ( V_75 ) ;
V_4 = F_213 ( V_15 ) ;
if ( F_229 ( V_4 ) == - V_203 ) {
V_197 = F_236 ( V_342 , F_223 ( V_150 ) ) ;
* V_329 = F_228 ( V_197 ) ;
return F_237 ( V_197 ) ;
} else if ( F_28 ( V_4 ) )
return NULL ;
V_150 = F_238 ( V_150 ) ;
V_39 = V_15 -> V_343 ;
V_342 &= ~ ( V_344 | V_345 | V_346 ) ;
V_342 |= V_347 ;
V_197 = F_236 ( V_342 | V_348 , F_223 ( V_150 ) ) ;
if ( ! V_197 ) {
if ( ! ( V_342 & V_349 ) )
return NULL ;
V_197 = F_239 ( V_15 , V_150 >> V_223 ,
F_223 ( V_150 ) ) ;
if ( ! V_197 )
return NULL ;
}
if ( ! V_39 )
V_39 = * V_15 -> V_39 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
* V_329 = F_222 ( V_15 , V_4 -> V_277 , F_228 ( V_197 ) ,
V_150 , V_324 , true , V_39 ) ;
if ( * V_329 == V_254 ) {
F_8 ( & V_4 -> V_174 , V_8 ) ;
goto V_61;
}
F_112 ( V_4 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
return F_237 ( V_197 ) ;
V_61:
if ( ! F_240 ( V_15 , V_197 , V_150 >> V_223 ) )
F_241 ( V_197 , F_223 ( V_150 ) ) ;
return NULL ;
}
static void F_242 ( struct V_14 * V_15 , T_7 V_150 ,
void * V_350 , T_9 V_329 ,
struct V_332 * V_333 )
{
struct V_1 * V_4 ;
unsigned long V_8 ;
struct V_197 * V_197 ;
F_65 ( V_76 ) ;
V_197 = F_243 ( V_350 ) ;
V_150 = F_238 ( V_150 ) ;
V_4 = F_213 ( V_15 ) ;
if ( F_28 ( V_4 ) )
goto V_351;
F_6 ( & V_4 -> V_174 , V_8 ) ;
F_225 ( V_4 -> V_277 , V_329 , V_150 , V_324 ) ;
F_112 ( V_4 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
V_351:
if ( ! F_240 ( V_15 , V_197 , V_150 >> V_223 ) )
F_241 ( V_197 , F_223 ( V_150 ) ) ;
}
static int F_244 ( struct V_14 * V_15 , T_4 V_352 )
{
return F_24 ( V_15 ) ;
}
static void T_3 F_245 ( void )
{
struct V_5 * V_7 ;
struct V_31 * V_217 ;
struct V_16 * V_15 = NULL ;
T_1 V_6 ;
F_47 (dev) {
if ( ! F_24 ( & V_15 -> V_15 ) )
continue;
V_7 = F_18 ( & V_15 -> V_15 ) ;
if ( ! V_353 && V_7 -> V_56 ) {
F_246 () ;
V_7 -> V_303 = true ;
F_203 ( & V_15 -> V_15 , V_306 ) ;
F_33 ( L_30 ,
F_37 ( & V_15 -> V_15 ) ) ;
}
if ( F_207 ( & V_15 -> V_15 ) )
continue;
V_6 = F_15 ( & V_15 -> V_15 ) ;
V_217 = F_177 () ;
if ( ! V_217 )
continue;
F_142 ( V_217 , V_6 ) ;
V_217 -> V_38 = V_6 ;
F_203 ( & V_15 -> V_15 , & V_217 -> V_4 ) ;
F_7 ( & V_217 -> V_257 , & V_36 ) ;
}
}
static unsigned F_247 ( void )
{
struct V_5 * V_7 ;
struct V_16 * V_17 = NULL ;
unsigned V_354 = 0 ;
F_47 (pdev) {
if ( ! F_24 ( & V_17 -> V_15 ) ) {
F_42 ( & V_17 -> V_15 ) ;
V_354 += 1 ;
continue;
}
V_7 = F_18 ( & V_17 -> V_15 ) ;
if ( ! V_7 -> V_303 )
V_17 -> V_15 . V_21 . V_314 = & V_315 ;
else
V_17 -> V_15 . V_21 . V_314 = & V_355 ;
}
return V_354 ;
}
void T_3 F_248 ( void )
{
F_249 ( & V_317 , & V_356 ) ;
}
int T_3 F_250 ( void )
{
struct V_55 * V_22 ;
int V_33 , V_354 ;
F_146 (iommu) {
V_22 -> V_226 = F_177 () ;
if ( V_22 -> V_226 == NULL )
return - V_52 ;
V_22 -> V_226 -> V_4 . V_8 |= V_357 ;
V_33 = F_141 ( V_22 ) ;
if ( V_33 )
goto V_358;
}
F_245 () ;
V_359 = 1 ;
V_360 = 0 ;
V_354 = F_247 () ;
if ( V_354 && V_361 > V_362 ) {
V_360 = 1 ;
}
F_52 () ;
if ( V_69 )
F_33 ( L_31 ) ;
else
F_33 ( L_32 ) ;
return 0 ;
V_358:
F_146 (iommu) {
F_176 ( V_22 -> V_226 ) ;
}
return V_33 ;
}
static void F_251 ( struct V_1 * V_4 )
{
struct V_5 * V_32 ;
unsigned long V_8 ;
F_160 ( & V_259 , V_8 ) ;
while ( ! F_23 ( & V_4 -> V_275 ) ) {
V_32 = F_252 ( & V_4 -> V_275 ,
struct V_5 , V_257 ) ;
F_205 ( V_32 ) ;
}
F_162 ( & V_259 , V_8 ) ;
}
static void F_253 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
F_158 ( V_4 ) ;
if ( V_4 -> V_183 )
F_163 ( V_4 -> V_183 ) ;
F_11 ( V_4 ) ;
}
static struct V_1 * F_254 ( void )
{
struct V_1 * V_4 ;
V_4 = F_4 ( sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 )
return NULL ;
F_178 ( & V_4 -> V_174 ) ;
F_255 ( & V_4 -> V_363 ) ;
V_4 -> V_183 = F_159 () ;
if ( ! V_4 -> V_183 )
goto V_300;
F_5 ( & V_4 -> V_275 ) ;
F_157 ( V_4 ) ;
return V_4 ;
V_300:
F_11 ( V_4 ) ;
return NULL ;
}
static int T_3 F_246 ( void )
{
if ( V_306 != NULL )
return 0 ;
V_306 = F_254 () ;
if ( ! V_306 )
return - V_52 ;
V_306 -> V_189 = V_263 ;
return 0 ;
}
static struct V_2 * F_256 ( unsigned type )
{
struct V_1 * V_364 ;
if ( type != V_365 )
return NULL ;
V_364 = F_254 () ;
if ( ! V_364 )
goto V_61;
V_364 -> V_189 = V_266 ;
V_364 -> V_191 = ( void * ) F_115 ( V_9 ) ;
if ( ! V_364 -> V_191 )
goto V_61;
V_364 -> V_4 . V_366 . V_367 = 0 ;
V_364 -> V_4 . V_366 . V_368 = ~ 0ULL ;
V_364 -> V_4 . V_366 . V_369 = true ;
return & V_364 -> V_4 ;
V_61:
F_253 ( V_364 ) ;
return NULL ;
}
static void F_257 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 )
return;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_292 > 0 )
F_251 ( V_4 ) ;
F_119 ( V_4 -> V_292 != 0 ) ;
if ( V_4 -> V_189 != V_263 )
F_165 ( V_4 ) ;
if ( V_4 -> V_8 & V_283 )
F_175 ( V_4 ) ;
F_253 ( V_4 ) ;
}
static void F_258 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_5 * V_7 = V_15 -> V_21 . V_22 ;
struct V_55 * V_22 ;
T_1 V_6 ;
if ( ! F_24 ( V_15 ) )
return;
V_6 = F_15 ( V_15 ) ;
if ( V_7 -> V_4 != NULL )
F_206 ( V_15 ) ;
V_22 = V_41 [ V_6 ] ;
if ( ! V_22 )
return;
F_97 ( V_22 ) ;
}
static int F_259 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_7 ;
struct V_55 * V_22 ;
int V_33 ;
if ( ! F_24 ( V_15 ) )
return - V_203 ;
V_7 = V_15 -> V_21 . V_22 ;
V_22 = V_41 [ V_7 -> V_6 ] ;
if ( ! V_22 )
return - V_203 ;
if ( V_7 -> V_4 )
F_206 ( V_15 ) ;
V_33 = F_203 ( V_15 , V_4 ) ;
F_97 ( V_22 ) ;
return V_33 ;
}
static int F_260 ( struct V_2 * V_3 , unsigned long V_370 ,
T_10 V_320 , T_7 V_193 , int V_371 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_200 = 0 ;
int V_33 ;
if ( V_4 -> V_189 == V_263 )
return - V_203 ;
if ( V_371 & V_372 )
V_200 |= V_207 ;
if ( V_371 & V_373 )
V_200 |= V_209 ;
F_261 ( & V_4 -> V_363 ) ;
V_33 = F_132 ( V_4 , V_370 , V_320 , V_200 , V_193 ) ;
F_262 ( & V_4 -> V_363 ) ;
return V_33 ;
}
static T_7 F_263 ( struct V_2 * V_3 , unsigned long V_370 ,
T_7 V_193 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_7 V_212 ;
if ( V_4 -> V_189 == V_263 )
return - V_203 ;
F_261 ( & V_4 -> V_363 ) ;
V_212 = F_137 ( V_4 , V_370 , V_193 ) ;
F_262 ( & V_4 -> V_363 ) ;
F_111 ( V_4 ) ;
return V_212 ;
}
static T_10 F_264 ( struct V_2 * V_3 ,
T_9 V_370 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_374 , V_234 ;
T_4 * V_188 , V_201 ;
if ( V_4 -> V_189 == V_263 )
return V_370 ;
V_188 = F_128 ( V_4 , V_370 , & V_234 ) ;
if ( ! V_188 || ! F_125 ( * V_188 ) )
return 0 ;
V_374 = V_234 - 1 ;
V_201 = * V_188 & V_375 ;
return ( V_201 & ~ V_374 ) | ( V_370 & V_374 ) ;
}
static bool F_265 ( enum V_376 V_377 )
{
switch ( V_377 ) {
case V_378 :
return true ;
case V_379 :
return ( V_380 == 1 ) ;
case V_381 :
return false ;
}
return false ;
}
int T_3 F_266 ( void )
{
struct V_5 * V_7 ;
struct V_16 * V_15 = NULL ;
int V_33 ;
V_33 = F_246 () ;
if ( V_33 )
return V_33 ;
F_47 (dev) {
if ( ! F_24 ( & V_15 -> V_15 ) )
continue;
V_7 = F_18 ( & V_15 -> V_15 ) ;
V_7 -> V_303 = true ;
F_203 ( & V_15 -> V_15 , V_306 ) ;
}
F_52 () ;
F_33 ( L_33 ) ;
return 0 ;
}
int F_267 ( struct V_307 * V_308 )
{
return F_268 ( & V_128 , V_308 ) ;
}
int F_269 ( struct V_307 * V_308 )
{
return F_270 ( & V_128 , V_308 ) ;
}
void F_271 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
V_4 -> V_189 = V_263 ;
V_4 -> V_192 = true ;
F_136 ( V_4 ) ;
F_165 ( V_4 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
}
int F_272 ( struct V_2 * V_3 , int V_382 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_383 , V_33 ;
if ( V_382 <= 0 || V_382 > ( V_384 + 1 ) )
return - V_203 ;
for ( V_383 = 0 ; ( V_382 - 1 ) & ~ 0x1ff ; V_382 >>= 9 )
V_383 += 1 ;
if ( V_383 > V_385 )
return - V_203 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
V_33 = - V_204 ;
if ( V_4 -> V_292 > 0 || V_4 -> V_8 & V_283 )
goto V_313;
V_33 = - V_52 ;
V_4 -> V_273 = ( void * ) F_115 ( V_319 ) ;
if ( V_4 -> V_273 == NULL )
goto V_313;
V_4 -> V_272 = V_383 ;
V_4 -> V_8 |= V_283 ;
V_4 -> V_192 = true ;
F_136 ( V_4 ) ;
V_33 = 0 ;
V_313:
F_8 ( & V_4 -> V_174 , V_8 ) ;
return V_33 ;
}
static int F_273 ( struct V_1 * V_4 , int V_125 ,
T_4 V_93 , bool V_150 )
{
struct V_5 * V_7 ;
struct V_87 V_88 ;
int V_27 , V_33 ;
if ( ! ( V_4 -> V_8 & V_283 ) )
return - V_203 ;
F_90 ( & V_88 , V_4 -> V_183 , V_125 , V_93 , V_150 ) ;
for ( V_27 = 0 ; V_27 < V_184 ; ++ V_27 ) {
if ( V_4 -> V_185 [ V_27 ] == 0 )
continue;
V_33 = F_96 ( V_186 [ V_27 ] , & V_88 ) ;
if ( V_33 != 0 )
goto V_313;
}
F_112 ( V_4 ) ;
F_13 (dev_data, &domain->dev_list, list) {
struct V_55 * V_22 ;
int V_160 ;
F_119 ( ! V_7 -> V_181 . V_182 ) ;
V_160 = V_7 -> V_181 . V_160 ;
V_22 = V_41 [ V_7 -> V_6 ] ;
F_91 ( & V_88 , V_7 -> V_6 , V_125 ,
V_160 , V_93 , V_150 ) ;
V_33 = F_96 ( V_22 , & V_88 ) ;
if ( V_33 != 0 )
goto V_313;
}
F_112 ( V_4 ) ;
V_33 = 0 ;
V_313:
return V_33 ;
}
static int F_274 ( struct V_1 * V_4 , int V_125 ,
T_4 V_93 )
{
F_65 ( V_83 ) ;
return F_273 ( V_4 , V_125 , V_93 , false ) ;
}
int F_275 ( struct V_2 * V_3 , int V_125 ,
T_4 V_93 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_33 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
V_33 = F_274 ( V_4 , V_125 , V_93 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
return V_33 ;
}
static int F_276 ( struct V_1 * V_4 , int V_125 )
{
F_65 ( V_84 ) ;
return F_273 ( V_4 , V_125 , V_155 ,
true ) ;
}
int F_277 ( struct V_2 * V_3 , int V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_33 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
V_33 = F_276 ( V_4 , V_125 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
return V_33 ;
}
static T_4 * F_278 ( T_4 * V_262 , int V_195 , int V_125 , bool V_386 )
{
int V_229 ;
T_4 * V_188 ;
while ( true ) {
V_229 = ( V_125 >> ( 9 * V_195 ) ) & 0x1ff ;
V_188 = & V_262 [ V_229 ] ;
if ( V_195 == 0 )
break;
if ( ! ( * V_188 & V_271 ) ) {
if ( ! V_386 )
return NULL ;
V_262 = ( void * ) F_115 ( V_319 ) ;
if ( V_262 == NULL )
return NULL ;
* V_188 = F_83 ( V_262 ) | V_271 ;
}
V_262 = F_173 ( * V_188 & V_156 ) ;
V_195 -= 1 ;
}
return V_188 ;
}
static int F_279 ( struct V_1 * V_4 , int V_125 ,
unsigned long V_387 )
{
T_4 * V_188 ;
if ( V_4 -> V_189 != V_263 )
return - V_203 ;
V_188 = F_278 ( V_4 -> V_273 , V_4 -> V_272 , V_125 , true ) ;
if ( V_188 == NULL )
return - V_52 ;
* V_188 = ( V_387 & V_156 ) | V_271 ;
return F_276 ( V_4 , V_125 ) ;
}
static int F_280 ( struct V_1 * V_4 , int V_125 )
{
T_4 * V_188 ;
if ( V_4 -> V_189 != V_263 )
return - V_203 ;
V_188 = F_278 ( V_4 -> V_273 , V_4 -> V_272 , V_125 , false ) ;
if ( V_188 == NULL )
return 0 ;
* V_188 = 0 ;
return F_276 ( V_4 , V_125 ) ;
}
int F_281 ( struct V_2 * V_3 , int V_125 ,
unsigned long V_387 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_33 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
V_33 = F_279 ( V_4 , V_125 , V_387 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
return V_33 ;
}
int F_282 ( struct V_2 * V_3 , int V_125 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_8 ;
int V_33 ;
F_6 ( & V_4 -> V_174 , V_8 ) ;
V_33 = F_280 ( V_4 , V_125 ) ;
F_8 ( & V_4 -> V_174 , V_8 ) ;
return V_33 ;
}
int F_283 ( struct V_16 * V_17 , int V_125 ,
int V_135 , int V_127 )
{
struct V_5 * V_7 ;
struct V_55 * V_22 ;
struct V_87 V_88 ;
F_65 ( V_82 ) ;
V_7 = F_18 ( & V_17 -> V_15 ) ;
V_22 = V_41 [ V_7 -> V_6 ] ;
F_92 ( & V_88 , V_7 -> V_6 , V_125 , V_135 ,
V_127 , V_7 -> V_304 ) ;
return F_96 ( V_22 , & V_88 ) ;
}
struct V_2 * F_284 ( struct V_16 * V_17 )
{
struct V_1 * V_364 ;
V_364 = F_213 ( & V_17 -> V_15 ) ;
if ( F_28 ( V_364 ) )
return NULL ;
if ( ! ( V_364 -> V_8 & V_283 ) )
return NULL ;
return & V_364 -> V_4 ;
}
void F_285 ( struct V_16 * V_17 , T_2 V_29 )
{
struct V_5 * V_7 ;
if ( ! F_286 () )
return;
V_7 = F_18 ( & V_17 -> V_15 ) ;
V_7 -> V_30 |= ( 1 << V_29 ) ;
}
int F_287 ( struct V_16 * V_17 ,
struct F_287 * V_388 )
{
int V_389 ;
int V_28 ;
if ( V_17 == NULL || V_388 == NULL )
return - V_203 ;
if ( ! F_286 () )
return - V_203 ;
memset ( V_388 , 0 , sizeof( * V_388 ) ) ;
V_28 = F_20 ( V_17 , V_24 ) ;
if ( V_28 )
V_388 -> V_8 |= V_390 ;
V_28 = F_20 ( V_17 , V_25 ) ;
if ( V_28 )
V_388 -> V_8 |= V_391 ;
V_28 = F_20 ( V_17 , V_26 ) ;
if ( V_28 ) {
int V_392 ;
V_389 = 1 << ( 9 * ( V_385 + 1 ) ) ;
V_389 = F_288 ( V_389 , ( 1 << 20 ) ) ;
V_388 -> V_8 |= V_393 ;
V_388 -> V_389 = F_288 ( F_289 ( V_17 ) , V_389 ) ;
V_392 = F_290 ( V_17 ) ;
if ( V_392 & V_394 )
V_388 -> V_8 |= V_395 ;
if ( V_392 & V_396 )
V_388 -> V_8 |= V_397 ;
}
return 0 ;
}
static void F_291 ( T_1 V_6 , struct V_398 * V_399 )
{
T_4 V_400 ;
V_400 = V_47 [ V_6 ] . V_44 [ 2 ] ;
V_400 &= ~ V_401 ;
V_400 |= F_117 ( V_399 -> V_399 ) ;
V_400 |= V_402 ;
V_400 |= V_403 ;
V_400 |= V_404 ;
V_47 [ V_6 ] . V_44 [ 2 ] = V_400 ;
}
static struct V_398 * F_292 ( T_1 V_6 , bool V_405 )
{
struct V_398 * V_399 = NULL ;
struct V_55 * V_22 ;
unsigned long V_8 ;
T_1 V_34 ;
F_160 ( & V_259 , V_8 ) ;
V_22 = V_41 [ V_6 ] ;
if ( ! V_22 )
goto V_13;
V_399 = V_406 [ V_6 ] ;
if ( V_399 )
goto V_313;
V_34 = V_35 [ V_6 ] ;
V_399 = V_406 [ V_34 ] ;
if ( V_399 ) {
V_406 [ V_6 ] = V_399 ;
F_291 ( V_6 , V_399 ) ;
F_98 ( V_22 , V_6 ) ;
goto V_313;
}
V_399 = F_4 ( sizeof( * V_399 ) , V_319 ) ;
if ( ! V_399 )
goto V_313;
F_178 ( & V_399 -> V_174 ) ;
if ( V_405 )
V_399 -> V_407 = 32 ;
V_399 -> V_399 = F_293 ( V_408 , V_319 ) ;
if ( ! V_399 -> V_399 ) {
F_11 ( V_399 ) ;
V_399 = NULL ;
goto V_313;
}
memset ( V_399 -> V_399 , 0 , V_409 * sizeof( T_2 ) ) ;
if ( V_405 ) {
int V_27 ;
for ( V_27 = 0 ; V_27 < 32 ; ++ V_27 )
V_399 -> V_399 [ V_27 ] = V_410 ;
}
V_406 [ V_6 ] = V_399 ;
F_291 ( V_6 , V_399 ) ;
F_98 ( V_22 , V_6 ) ;
if ( V_6 != V_34 ) {
V_406 [ V_34 ] = V_399 ;
F_291 ( V_34 , V_399 ) ;
F_98 ( V_22 , V_34 ) ;
}
V_313:
F_97 ( V_22 ) ;
V_13:
F_162 ( & V_259 , V_8 ) ;
return V_399 ;
}
static int F_294 ( struct V_411 * V_412 , T_1 V_6 , int V_92 )
{
struct V_398 * V_399 ;
unsigned long V_8 ;
int V_229 , V_413 ;
V_399 = F_292 ( V_6 , false ) ;
if ( ! V_399 )
return - V_414 ;
F_6 ( & V_399 -> V_174 , V_8 ) ;
for ( V_413 = 0 , V_229 = V_399 -> V_407 ;
V_229 < V_409 ;
++ V_229 ) {
if ( V_399 -> V_399 [ V_229 ] == 0 )
V_413 += 1 ;
else
V_413 = 0 ;
if ( V_413 == V_92 ) {
struct V_415 * V_416 ;
for (; V_413 != 0 ; -- V_413 )
V_399 -> V_399 [ V_229 - V_413 + 1 ] = V_410 ;
V_229 -= V_92 - 1 ;
V_412 -> V_417 = 1 ;
V_416 = & V_412 -> V_415 ;
V_416 -> V_6 = V_6 ;
V_416 -> V_229 = V_229 ;
goto V_313;
}
}
V_229 = - V_418 ;
V_313:
F_8 ( & V_399 -> V_174 , V_8 ) ;
return V_229 ;
}
static int F_295 ( T_1 V_6 , int V_229 , union V_419 * V_419 )
{
struct V_398 * V_399 ;
unsigned long V_8 ;
V_399 = F_292 ( V_6 , false ) ;
if ( ! V_399 )
return - V_52 ;
F_6 ( & V_399 -> V_174 , V_8 ) ;
V_419 -> V_420 = V_399 -> V_399 [ V_229 ] ;
F_8 ( & V_399 -> V_174 , V_8 ) ;
return 0 ;
}
static int F_296 ( T_1 V_6 , int V_229 , union V_419 V_419 )
{
struct V_398 * V_399 ;
struct V_55 * V_22 ;
unsigned long V_8 ;
V_22 = V_41 [ V_6 ] ;
if ( V_22 == NULL )
return - V_203 ;
V_399 = F_292 ( V_6 , false ) ;
if ( ! V_399 )
return - V_52 ;
F_6 ( & V_399 -> V_174 , V_8 ) ;
V_399 -> V_399 [ V_229 ] = V_419 . V_420 ;
F_8 ( & V_399 -> V_174 , V_8 ) ;
F_102 ( V_22 , V_6 ) ;
F_97 ( V_22 ) ;
return 0 ;
}
static void F_297 ( T_1 V_6 , int V_229 )
{
struct V_398 * V_399 ;
struct V_55 * V_22 ;
unsigned long V_8 ;
V_22 = V_41 [ V_6 ] ;
if ( V_22 == NULL )
return;
V_399 = F_292 ( V_6 , false ) ;
if ( ! V_399 )
return;
F_6 ( & V_399 -> V_174 , V_8 ) ;
V_399 -> V_399 [ V_229 ] = 0 ;
F_8 ( & V_399 -> V_174 , V_8 ) ;
F_102 ( V_22 , V_6 ) ;
F_97 ( V_22 ) ;
}
static int F_298 ( int V_134 , struct V_421 * V_32 ,
unsigned int V_422 , int V_423 ,
struct V_424 * V_425 )
{
struct V_398 * V_399 ;
struct V_415 * V_416 ;
struct V_411 * V_412 ;
union V_419 V_419 ;
int V_426 ;
int V_229 ;
int V_6 ;
int V_33 ;
V_412 = V_411 ( V_134 ) ;
if ( ! V_412 )
return - V_203 ;
V_416 = & V_412 -> V_415 ;
V_426 = F_299 ( V_425 -> V_405 ) ;
V_6 = F_300 ( V_426 ) ;
if ( V_6 < 0 )
return V_6 ;
V_399 = F_292 ( V_6 , true ) ;
if ( V_399 == NULL )
return - V_52 ;
V_229 = V_425 -> V_427 ;
V_412 -> V_417 = 1 ;
V_416 -> V_6 = V_6 ;
V_416 -> V_229 = V_229 ;
V_419 . V_420 = 0 ;
V_419 . V_428 . V_423 = V_423 ;
V_419 . V_428 . V_429 = V_430 -> V_431 ;
V_419 . V_428 . V_422 = V_422 ;
V_419 . V_428 . V_432 = V_430 -> V_433 ;
V_419 . V_428 . V_434 = 1 ;
V_33 = F_296 ( V_6 , V_229 , V_419 ) ;
if ( V_33 )
return V_33 ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_423 = V_229 ;
V_32 -> V_352 = 0 ;
V_32 -> V_435 = V_425 -> V_435 ;
V_32 -> V_436 = V_425 -> V_436 ;
if ( V_425 -> V_435 )
V_32 -> V_352 = 1 ;
return 0 ;
}
static int F_301 ( struct V_437 * V_44 , const struct V_438 * V_352 ,
bool V_439 )
{
struct V_415 * V_416 ;
unsigned int V_440 , V_134 ;
struct V_411 * V_412 ;
union V_419 V_419 ;
int V_441 ;
if ( ! F_302 ( V_442 ) )
return - 1 ;
V_412 = F_303 ( V_44 ) ;
V_134 = V_44 -> V_134 ;
V_416 = & V_412 -> V_415 ;
if ( ! F_304 ( V_352 , V_443 ) )
return - V_203 ;
if ( F_295 ( V_416 -> V_6 , V_416 -> V_229 , & V_419 ) )
return - V_204 ;
if ( F_305 ( V_134 , V_412 , V_352 ) )
return - V_204 ;
V_441 = V_430 -> V_444 ( V_412 -> V_4 , V_352 , & V_440 ) ;
if ( V_441 ) {
if ( F_305 ( V_134 , V_412 , V_44 -> V_445 ) )
F_39 ( L_34 , V_134 ) ;
return V_441 ;
}
V_419 . V_428 . V_423 = V_412 -> V_423 ;
V_419 . V_428 . V_422 = V_440 ;
F_296 ( V_416 -> V_6 , V_416 -> V_229 , V_419 ) ;
if ( V_412 -> V_446 )
F_306 ( V_412 ) ;
F_307 ( V_44 -> V_445 , V_352 ) ;
return 0 ;
}
static int F_308 ( int V_134 )
{
struct V_415 * V_416 ;
struct V_411 * V_412 ;
V_412 = V_411 ( V_134 ) ;
if ( ! V_412 )
return - V_203 ;
V_416 = & V_412 -> V_415 ;
F_297 ( V_416 -> V_6 , V_416 -> V_229 ) ;
return 0 ;
}
static void F_309 ( struct V_16 * V_17 ,
unsigned int V_134 , unsigned int V_440 ,
struct V_447 * V_448 , T_6 V_449 )
{
struct V_415 * V_416 ;
struct V_411 * V_412 ;
union V_419 V_419 ;
V_412 = V_411 ( V_134 ) ;
if ( ! V_412 )
return;
V_416 = & V_412 -> V_415 ;
V_419 . V_420 = 0 ;
V_419 . V_428 . V_423 = V_412 -> V_423 ;
V_419 . V_428 . V_429 = V_430 -> V_431 ;
V_419 . V_428 . V_422 = V_440 ;
V_419 . V_428 . V_432 = V_430 -> V_433 ;
V_419 . V_428 . V_434 = 1 ;
F_296 ( V_416 -> V_6 , V_416 -> V_229 , V_419 ) ;
V_448 -> V_450 = V_451 ;
V_448 -> V_452 = V_241 ;
V_448 -> V_44 = V_416 -> V_229 ;
}
static int F_310 ( struct V_16 * V_17 , int V_134 , int V_453 )
{
struct V_411 * V_412 ;
int V_229 ;
T_1 V_6 ;
if ( ! V_17 )
return - V_203 ;
V_412 = V_411 ( V_134 ) ;
if ( ! V_412 )
return - V_203 ;
V_6 = F_15 ( & V_17 -> V_15 ) ;
V_229 = F_294 ( V_412 , V_6 , V_453 ) ;
return V_229 < 0 ? V_409 : V_229 ;
}
static int F_311 ( struct V_16 * V_17 , unsigned int V_134 ,
int V_229 , int V_237 )
{
struct V_415 * V_416 ;
struct V_411 * V_412 ;
T_1 V_6 ;
if ( ! V_17 )
return - V_203 ;
V_412 = V_411 ( V_134 ) ;
if ( ! V_412 )
return - V_203 ;
if ( V_229 >= V_409 )
return 0 ;
V_6 = F_15 ( & V_17 -> V_15 ) ;
V_416 = & V_412 -> V_415 ;
V_412 -> V_417 = 1 ;
V_416 -> V_6 = V_6 ;
V_416 -> V_229 = V_229 + V_237 ;
return 0 ;
}
static int F_312 ( unsigned int V_134 , unsigned int V_183 )
{
struct V_415 * V_416 ;
struct V_411 * V_412 ;
int V_229 , V_6 ;
V_412 = V_411 ( V_134 ) ;
if ( ! V_412 )
return - V_203 ;
V_416 = & V_412 -> V_415 ;
V_6 = F_313 ( V_183 ) ;
if ( V_6 < 0 )
return V_6 ;
V_229 = F_294 ( V_412 , V_6 , 1 ) ;
if ( V_229 < 0 )
return V_229 ;
V_412 -> V_417 = 1 ;
V_416 -> V_6 = V_6 ;
V_416 -> V_229 = V_229 ;
return 0 ;
}
