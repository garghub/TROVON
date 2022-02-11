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
if ( V_3 -> V_9 )
F_9 ( V_3 -> V_9 ) ;
F_10 ( V_3 ) ;
}
static struct V_1 * F_11 ( T_1 V_2 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
F_4 ( & V_7 , V_4 ) ;
F_12 (dev_data, &dev_data_list, dev_data_list) {
if ( V_3 -> V_2 == V_2 )
goto V_10;
}
V_3 = NULL ;
V_10:
F_6 ( & V_7 , V_4 ) ;
return V_3 ;
}
static struct V_1 * F_13 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_11 ( V_2 ) ;
if ( V_3 == NULL )
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
static inline T_1 F_14 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_15 ( V_12 ) ;
return F_16 ( V_14 -> V_15 -> V_16 , V_14 -> V_17 ) ;
}
static struct V_1 * F_17 ( struct V_11 * V_12 )
{
return V_12 -> V_18 . V_19 ;
}
static bool F_18 ( struct V_13 * V_14 )
{
static const int V_20 [] = {
V_21 ,
V_22 ,
V_23 ,
} ;
int V_24 , V_25 ;
for ( V_24 = 0 ; V_24 < 3 ; ++ V_24 ) {
V_25 = F_19 ( V_14 , V_20 [ V_24 ] ) ;
if ( V_25 == 0 )
return false ;
}
return true ;
}
static bool F_20 ( struct V_13 * V_14 , T_2 V_26 )
{
struct V_1 * V_3 ;
V_3 = F_17 ( & V_14 -> V_12 ) ;
return V_3 -> V_27 & ( 1 << V_26 ) ? true : false ;
}
static struct V_28 * F_21 ( T_1 V_2 )
{
struct V_28 * V_29 , * V_30 = NULL ;
unsigned long V_4 ;
T_1 V_31 = V_32 [ V_2 ] ;
if ( F_22 ( & V_33 ) )
return NULL ;
F_4 ( & V_34 , V_4 ) ;
F_12 (entry, &iommu_pd_list, list) {
if ( V_29 -> V_35 == V_2 ||
V_29 -> V_35 == V_31 ) {
V_30 = V_29 ;
break;
}
}
F_6 ( & V_34 , V_4 ) ;
return V_30 ;
}
static bool F_23 ( struct V_11 * V_12 )
{
T_1 V_2 ;
if ( ! V_12 || ! V_12 -> V_36 )
return false ;
if ( V_12 -> V_15 != & V_37 )
return false ;
V_2 = F_14 ( V_12 ) ;
if ( V_2 > V_38 )
return false ;
if ( V_39 [ V_2 ] == NULL )
return false ;
return true ;
}
static void F_24 ( struct V_13 * * V_40 , struct V_13 * V_41 )
{
F_25 ( * V_40 ) ;
* V_40 = V_41 ;
}
static struct V_42 * F_26 ( struct V_42 * V_15 )
{
while ( ! V_15 -> V_43 ) {
if ( ! F_27 ( V_15 ) )
V_15 = V_15 -> V_44 ;
else
return F_28 ( - V_45 ) ;
}
return V_15 ;
}
static struct V_13 * F_29 ( struct V_13 * V_14 )
{
struct V_13 * V_46 = V_14 ;
F_24 ( & V_46 , F_30 ( V_46 ) ) ;
if ( V_46 -> V_47 &&
! F_31 ( V_46 , V_48 ) )
F_24 ( & V_46 ,
F_32 ( V_46 -> V_15 ,
F_33 ( F_34 ( V_46 -> V_17 ) ,
0 ) ) ) ;
while ( ! F_27 ( V_46 -> V_15 ) ) {
struct V_42 * V_15 = F_26 ( V_46 -> V_15 ) ;
if ( F_35 ( V_15 ) )
break;
if ( F_36 ( V_15 -> V_43 , NULL , V_48 ) )
break;
F_24 ( & V_46 , F_37 ( V_15 -> V_43 ) ) ;
}
return V_46 ;
}
static int F_38 ( struct V_13 * V_14 , struct V_11 * V_12 )
{
struct V_49 * V_9 = F_39 ( & V_14 -> V_12 ) ;
int V_30 ;
if ( ! V_9 ) {
V_9 = F_40 () ;
if ( F_35 ( V_9 ) )
return F_41 ( V_9 ) ;
F_42 ( & V_14 -> V_12 != V_12 ) ;
}
V_30 = F_43 ( V_9 , V_12 ) ;
F_9 ( V_9 ) ;
return V_30 ;
}
static int F_44 ( struct V_1 * V_3 ,
struct V_11 * V_12 )
{
if ( ! V_3 -> V_9 ) {
struct V_49 * V_9 = F_40 () ;
if ( F_35 ( V_9 ) )
return F_41 ( V_9 ) ;
V_3 -> V_9 = V_9 ;
}
return F_43 ( V_3 -> V_9 , V_12 ) ;
}
static int F_45 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_49 * V_9 ;
struct V_13 * V_46 ;
int V_30 ;
V_9 = F_39 ( V_12 ) ;
if ( V_9 ) {
F_9 ( V_9 ) ;
return 0 ;
}
V_3 = F_13 ( F_14 ( V_12 ) ) ;
if ( ! V_3 )
return - V_50 ;
if ( V_3 -> V_51 ) {
T_1 V_31 ;
struct V_42 * V_15 ;
if ( V_3 -> V_51 -> V_9 )
goto V_52;
V_31 = V_32 [ V_3 -> V_2 ] ;
V_46 = F_46 ( V_31 >> 8 , V_31 & 0xff ) ;
if ( V_46 ) {
V_46 = F_29 ( V_46 ) ;
goto V_53;
}
V_15 = F_47 ( 0 , V_31 >> 8 ) ;
if ( ! V_15 )
goto V_52;
V_15 = F_26 ( V_15 ) ;
if ( F_35 ( V_15 ) || ! V_15 -> V_43 )
goto V_52;
V_46 = F_29 ( F_37 ( V_15 -> V_43 ) ) ;
if ( V_46 != V_15 -> V_43 || ( V_46 -> V_47 &&
! F_31 ( V_46 , V_48 ) ) )
goto V_53;
F_25 ( V_46 ) ;
goto V_52;
}
V_46 = F_29 ( F_37 ( F_15 ( V_12 ) ) ) ;
V_53:
V_30 = F_38 ( V_46 , V_12 ) ;
F_25 ( V_46 ) ;
return V_30 ;
V_52:
return F_44 ( V_3 -> V_51 , V_12 ) ;
}
static int F_48 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_15 ( V_12 ) ;
struct V_1 * V_3 ;
T_1 V_31 ;
int V_30 ;
if ( V_12 -> V_18 . V_19 )
return 0 ;
V_3 = F_13 ( F_14 ( V_12 ) ) ;
if ( ! V_3 )
return - V_50 ;
V_31 = V_32 [ V_3 -> V_2 ] ;
if ( V_31 != V_3 -> V_2 ) {
struct V_1 * V_51 ;
V_51 = F_13 ( V_31 ) ;
if ( V_51 == NULL ) {
F_49 ( L_1 ,
F_50 ( V_12 ) ) ;
F_7 ( V_3 ) ;
return - V_54 ;
}
V_3 -> V_51 = V_51 ;
}
V_30 = F_45 ( V_12 ) ;
if ( V_30 )
return V_30 ;
if ( F_18 ( V_14 ) ) {
struct V_55 * V_19 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_3 -> V_56 = V_19 -> V_57 ;
}
V_12 -> V_18 . V_19 = V_3 ;
return 0 ;
}
static void F_51 ( struct V_11 * V_12 )
{
T_1 V_2 , V_31 ;
V_2 = F_14 ( V_12 ) ;
V_31 = V_32 [ V_2 ] ;
memset ( & V_58 [ V_2 ] , 0 , sizeof( struct V_59 ) ) ;
memset ( & V_58 [ V_31 ] , 0 , sizeof( struct V_59 ) ) ;
V_39 [ V_2 ] = NULL ;
V_39 [ V_31 ] = NULL ;
}
static void F_52 ( struct V_11 * V_12 )
{
F_53 ( V_12 ) ;
}
void T_3 F_54 ( void )
{
struct V_1 * V_3 , * V_60 ;
struct V_13 * V_14 = NULL ;
F_55 (pdev) {
if ( ! F_23 ( & V_14 -> V_12 ) )
continue;
F_52 ( & V_14 -> V_12 ) ;
}
F_56 (dev_data, n, &dev_data_list, dev_data_list)
F_7 ( V_3 ) ;
}
int T_3 F_57 ( void )
{
struct V_13 * V_14 = NULL ;
int V_30 = 0 ;
F_55 (pdev) {
if ( ! F_23 ( & V_14 -> V_12 ) )
continue;
V_30 = F_48 ( & V_14 -> V_12 ) ;
if ( V_30 == - V_54 )
F_51 ( & V_14 -> V_12 ) ;
else if ( V_30 )
goto V_61;
}
return 0 ;
V_61:
F_54 () ;
return V_30 ;
}
static void F_58 ( struct V_62 * V_63 )
{
if ( V_64 == NULL )
return;
V_63 -> V_65 = F_59 ( V_63 -> V_66 , 0444 , V_64 ,
& V_63 -> V_67 ) ;
}
static void F_60 ( void )
{
V_64 = F_61 ( L_2 , NULL ) ;
if ( V_64 == NULL )
return;
V_68 = F_62 ( L_3 , 0444 , V_64 ,
& V_69 ) ;
F_58 ( & V_70 ) ;
F_58 ( & V_71 ) ;
F_58 ( & V_72 ) ;
F_58 ( & V_73 ) ;
F_58 ( & V_74 ) ;
F_58 ( & V_75 ) ;
F_58 ( & V_76 ) ;
F_58 ( & V_77 ) ;
F_58 ( & V_78 ) ;
F_58 ( & V_79 ) ;
F_58 ( & V_80 ) ;
F_58 ( & V_81 ) ;
F_58 ( & V_82 ) ;
F_58 ( & V_83 ) ;
F_58 ( & V_84 ) ;
F_58 ( & V_85 ) ;
}
static void F_63 ( T_1 V_2 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 4 ; ++ V_24 )
F_49 ( L_4 , V_24 ,
V_58 [ V_2 ] . V_86 [ V_24 ] ) ;
}
static void F_64 ( unsigned long V_87 )
{
struct V_88 * V_89 = F_65 ( V_87 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 4 ; ++ V_24 )
F_49 ( L_5 , V_24 , V_89 -> V_86 [ V_24 ] ) ;
}
static void F_66 ( struct V_55 * V_19 , void * V_90 )
{
int type , V_2 , V_91 , V_4 ;
volatile T_2 * V_92 = V_90 ;
int V_93 = 0 ;
T_4 V_94 ;
V_95:
type = ( V_92 [ 1 ] >> V_96 ) & V_97 ;
V_2 = ( V_92 [ 0 ] >> V_98 ) & V_99 ;
V_91 = ( V_92 [ 1 ] >> V_100 ) & V_101 ;
V_4 = ( V_92 [ 1 ] >> V_102 ) & V_103 ;
V_94 = ( T_4 ) ( ( ( T_4 ) V_92 [ 3 ] ) << 32 ) | V_92 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_93 == V_104 ) {
F_49 ( L_6 ) ;
return;
}
F_67 ( 1 ) ;
goto V_95;
}
F_68 ( V_105 L_7 ) ;
switch ( type ) {
case V_106 :
F_68 ( L_8
L_9 ,
F_69 ( V_2 ) , F_34 ( V_2 ) , F_70 ( V_2 ) ,
V_94 , V_4 ) ;
F_63 ( V_2 ) ;
break;
case V_107 :
F_68 ( L_10
L_11 ,
F_69 ( V_2 ) , F_34 ( V_2 ) , F_70 ( V_2 ) ,
V_91 , V_94 , V_4 ) ;
break;
case V_108 :
F_68 ( L_12
L_9 ,
F_69 ( V_2 ) , F_34 ( V_2 ) , F_70 ( V_2 ) ,
V_94 , V_4 ) ;
break;
case V_109 :
F_68 ( L_13
L_11 ,
F_69 ( V_2 ) , F_34 ( V_2 ) , F_70 ( V_2 ) ,
V_91 , V_94 , V_4 ) ;
break;
case V_110 :
F_68 ( L_14 , V_94 ) ;
F_64 ( V_94 ) ;
break;
case V_111 :
F_68 ( L_15
L_16 , V_94 , V_4 ) ;
break;
case V_112 :
F_68 ( L_17
L_18 ,
F_69 ( V_2 ) , F_34 ( V_2 ) , F_70 ( V_2 ) ,
V_94 ) ;
break;
case V_113 :
F_68 ( L_19
L_9 ,
F_69 ( V_2 ) , F_34 ( V_2 ) , F_70 ( V_2 ) ,
V_94 , V_4 ) ;
break;
default:
F_68 ( V_105 L_20 , type ) ;
}
memset ( V_90 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_71 ( struct V_55 * V_19 )
{
T_2 V_114 , V_115 ;
unsigned long V_4 ;
F_4 ( & V_19 -> V_116 , V_4 ) ;
V_114 = F_72 ( V_19 -> V_117 + V_118 ) ;
V_115 = F_72 ( V_19 -> V_117 + V_119 ) ;
while ( V_114 != V_115 ) {
F_66 ( V_19 , V_19 -> V_120 + V_114 ) ;
V_114 = ( V_114 + V_121 ) % V_19 -> V_122 ;
}
F_73 ( V_114 , V_19 -> V_117 + V_118 ) ;
F_6 ( & V_19 -> V_116 , V_4 ) ;
}
static void F_74 ( struct V_55 * V_19 , T_4 * V_123 )
{
struct V_124 V_125 ;
F_75 ( V_85 ) ;
if ( F_76 ( V_123 [ 0 ] ) != V_126 ) {
F_77 ( L_21 ) ;
return;
}
V_125 . V_94 = V_123 [ 1 ] ;
V_125 . V_127 = F_78 ( V_123 [ 0 ] ) ;
V_125 . V_128 = F_79 ( V_123 [ 0 ] ) ;
V_125 . V_129 = F_80 ( V_123 [ 0 ] ) ;
V_125 . V_4 = F_81 ( V_123 [ 0 ] ) ;
F_82 ( & V_130 , 0 , & V_125 ) ;
}
static void F_83 ( struct V_55 * V_19 )
{
unsigned long V_4 ;
T_2 V_114 , V_115 ;
if ( V_19 -> V_131 == NULL )
return;
F_73 ( V_132 , V_19 -> V_117 + V_133 ) ;
F_4 ( & V_19 -> V_116 , V_4 ) ;
V_114 = F_72 ( V_19 -> V_117 + V_134 ) ;
V_115 = F_72 ( V_19 -> V_117 + V_135 ) ;
while ( V_114 != V_115 ) {
volatile T_4 * V_123 ;
T_4 V_29 [ 2 ] ;
int V_24 ;
V_123 = ( T_4 * ) ( V_19 -> V_131 + V_114 ) ;
for ( V_24 = 0 ; V_24 < V_104 ; ++ V_24 ) {
if ( F_76 ( V_123 [ 0 ] ) != 0 )
break;
F_67 ( 1 ) ;
}
V_29 [ 0 ] = V_123 [ 0 ] ;
V_29 [ 1 ] = V_123 [ 1 ] ;
V_123 [ 0 ] = V_123 [ 1 ] = 0UL ;
V_114 = ( V_114 + V_136 ) % V_137 ;
F_73 ( V_114 , V_19 -> V_117 + V_134 ) ;
F_6 ( & V_19 -> V_116 , V_4 ) ;
F_74 ( V_19 , V_29 ) ;
F_4 ( & V_19 -> V_116 , V_4 ) ;
V_114 = F_72 ( V_19 -> V_117 + V_134 ) ;
V_115 = F_72 ( V_19 -> V_117 + V_135 ) ;
}
F_6 ( & V_19 -> V_116 , V_4 ) ;
}
T_5 F_84 ( int V_138 , void * V_86 )
{
struct V_55 * V_19 ;
F_85 (iommu) {
F_71 ( V_19 ) ;
F_83 ( V_19 ) ;
}
return V_139 ;
}
T_5 F_86 ( int V_138 , void * V_86 )
{
return V_140 ;
}
static int F_87 ( volatile T_4 * V_141 )
{
int V_24 = 0 ;
while ( * V_141 == 0 && V_24 < V_104 ) {
F_67 ( 1 ) ;
V_24 += 1 ;
}
if ( V_24 == V_104 ) {
F_88 ( L_22 ) ;
return - V_142 ;
}
return 0 ;
}
static void F_89 ( struct V_55 * V_19 ,
struct V_88 * V_89 ,
T_2 V_115 )
{
T_6 * V_143 ;
V_143 = V_19 -> V_144 + V_115 ;
V_115 = ( V_115 + sizeof( * V_89 ) ) % V_19 -> V_145 ;
memcpy ( V_143 , V_89 , sizeof( * V_89 ) ) ;
F_73 ( V_115 , V_19 -> V_117 + V_146 ) ;
}
static void F_90 ( struct V_88 * V_89 , T_4 V_94 )
{
F_42 ( V_94 & 0x7ULL ) ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = F_91 ( F_92 ( V_94 ) ) | V_147 ;
V_89 -> V_86 [ 1 ] = F_93 ( F_92 ( V_94 ) ) ;
V_89 -> V_86 [ 2 ] = 1 ;
F_94 ( V_89 , V_148 ) ;
}
static void F_95 ( struct V_88 * V_89 , T_1 V_2 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_2 ;
F_94 ( V_89 , V_149 ) ;
}
static void F_96 ( struct V_88 * V_89 , T_4 V_94 ,
T_7 V_150 , T_1 V_91 , int V_151 )
{
T_4 V_152 ;
int V_153 ;
V_152 = F_97 ( V_94 , V_150 , V_154 ) ;
V_153 = 0 ;
if ( V_152 > 1 ) {
V_94 = V_155 ;
V_153 = 1 ;
}
V_94 &= V_156 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 1 ] |= V_91 ;
V_89 -> V_86 [ 2 ] = F_91 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_93 ( V_94 ) ;
F_94 ( V_89 , V_157 ) ;
if ( V_153 )
V_89 -> V_86 [ 2 ] |= V_158 ;
if ( V_151 )
V_89 -> V_86 [ 2 ] |= V_159 ;
}
static void F_98 ( struct V_88 * V_89 , T_1 V_2 , int V_160 ,
T_4 V_94 , T_7 V_150 )
{
T_4 V_152 ;
int V_153 ;
V_152 = F_97 ( V_94 , V_150 , V_154 ) ;
V_153 = 0 ;
if ( V_152 > 1 ) {
V_94 = V_155 ;
V_153 = 1 ;
}
V_94 &= V_156 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_2 ;
V_89 -> V_86 [ 0 ] |= ( V_160 & 0xff ) << 24 ;
V_89 -> V_86 [ 1 ] = V_2 ;
V_89 -> V_86 [ 2 ] = F_91 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_93 ( V_94 ) ;
F_94 ( V_89 , V_161 ) ;
if ( V_153 )
V_89 -> V_86 [ 2 ] |= V_158 ;
}
static void F_99 ( struct V_88 * V_89 , T_1 V_91 , int V_127 ,
T_4 V_94 , bool V_150 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_94 &= ~ ( 0xfffULL ) ;
V_89 -> V_86 [ 0 ] = V_127 & V_162 ;
V_89 -> V_86 [ 1 ] = V_91 ;
V_89 -> V_86 [ 2 ] = F_91 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_93 ( V_94 ) ;
V_89 -> V_86 [ 2 ] |= V_159 ;
V_89 -> V_86 [ 2 ] |= V_163 ;
if ( V_150 )
V_89 -> V_86 [ 2 ] |= V_158 ;
F_94 ( V_89 , V_157 ) ;
}
static void F_100 ( struct V_88 * V_89 , T_1 V_2 , int V_127 ,
int V_160 , T_4 V_94 , bool V_150 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_94 &= ~ ( 0xfffULL ) ;
V_89 -> V_86 [ 0 ] = V_2 ;
V_89 -> V_86 [ 0 ] |= ( V_127 & 0xff ) << 16 ;
V_89 -> V_86 [ 0 ] |= ( V_160 & 0xff ) << 24 ;
V_89 -> V_86 [ 1 ] = V_2 ;
V_89 -> V_86 [ 1 ] |= ( ( V_127 >> 8 ) & 0xfff ) << 16 ;
V_89 -> V_86 [ 2 ] = F_91 ( V_94 ) ;
V_89 -> V_86 [ 2 ] |= V_163 ;
V_89 -> V_86 [ 3 ] = F_93 ( V_94 ) ;
if ( V_150 )
V_89 -> V_86 [ 2 ] |= V_158 ;
F_94 ( V_89 , V_161 ) ;
}
static void F_101 ( struct V_88 * V_89 , T_1 V_2 , int V_127 ,
int V_164 , int V_129 , bool V_165 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_2 ;
if ( V_165 ) {
V_89 -> V_86 [ 1 ] = V_127 & V_162 ;
V_89 -> V_86 [ 2 ] = V_163 ;
}
V_89 -> V_86 [ 3 ] = V_129 & 0x1ff ;
V_89 -> V_86 [ 3 ] |= ( V_164 & V_166 ) << V_167 ;
F_94 ( V_89 , V_168 ) ;
}
static void F_102 ( struct V_88 * V_89 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
F_94 ( V_89 , V_169 ) ;
}
static void F_103 ( struct V_88 * V_89 , T_1 V_2 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_2 ;
F_94 ( V_89 , V_170 ) ;
}
static int F_104 ( struct V_55 * V_19 ,
struct V_88 * V_89 ,
bool V_171 )
{
T_2 V_172 , V_115 , V_114 , V_173 ;
unsigned long V_4 ;
F_42 ( V_19 -> V_145 & V_174 ) ;
V_175:
F_4 ( & V_19 -> V_116 , V_4 ) ;
V_114 = F_72 ( V_19 -> V_117 + V_176 ) ;
V_115 = F_72 ( V_19 -> V_117 + V_146 ) ;
V_173 = ( V_115 + sizeof( * V_89 ) ) % V_19 -> V_145 ;
V_172 = ( V_114 - V_173 ) % V_19 -> V_145 ;
if ( V_172 <= 2 ) {
struct V_88 V_177 ;
volatile T_4 V_141 = 0 ;
int V_30 ;
F_90 ( & V_177 , ( T_4 ) & V_141 ) ;
F_89 ( V_19 , & V_177 , V_115 ) ;
F_6 ( & V_19 -> V_116 , V_4 ) ;
if ( ( V_30 = F_87 ( & V_141 ) ) != 0 )
return V_30 ;
goto V_175;
}
F_89 ( V_19 , V_89 , V_115 ) ;
V_19 -> V_178 = V_171 ;
F_6 ( & V_19 -> V_116 , V_4 ) ;
return 0 ;
}
static int F_105 ( struct V_55 * V_19 , struct V_88 * V_89 )
{
return F_104 ( V_19 , V_89 , true ) ;
}
static int F_106 ( struct V_55 * V_19 )
{
struct V_88 V_89 ;
volatile T_4 V_141 = 0 ;
int V_30 ;
if ( ! V_19 -> V_178 )
return 0 ;
F_90 ( & V_89 , ( T_4 ) & V_141 ) ;
V_30 = F_104 ( V_19 , & V_89 , false ) ;
if ( V_30 )
return V_30 ;
return F_87 ( & V_141 ) ;
}
static int F_107 ( struct V_55 * V_19 , T_1 V_2 )
{
struct V_88 V_89 ;
F_95 ( & V_89 , V_2 ) ;
return F_105 ( V_19 , & V_89 ) ;
}
static void F_108 ( struct V_55 * V_19 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= 0xffff ; ++ V_2 )
F_107 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
}
static void F_109 ( struct V_55 * V_19 )
{
T_2 V_179 ;
for ( V_179 = 0 ; V_179 <= 0xffff ; ++ V_179 ) {
struct V_88 V_89 ;
F_96 ( & V_89 , 0 , V_155 ,
V_179 , 1 ) ;
F_105 ( V_19 , & V_89 ) ;
}
F_106 ( V_19 ) ;
}
static void F_110 ( struct V_55 * V_19 )
{
struct V_88 V_89 ;
F_102 ( & V_89 ) ;
F_105 ( V_19 , & V_89 ) ;
F_106 ( V_19 ) ;
}
static void F_111 ( struct V_55 * V_19 , T_1 V_2 )
{
struct V_88 V_89 ;
F_103 ( & V_89 , V_2 ) ;
F_105 ( V_19 , & V_89 ) ;
}
static void F_112 ( struct V_55 * V_19 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= V_180 ; V_2 ++ )
F_111 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
}
void F_113 ( struct V_55 * V_19 )
{
if ( F_114 ( V_19 , V_181 ) ) {
F_110 ( V_19 ) ;
} else {
F_108 ( V_19 ) ;
F_112 ( V_19 ) ;
F_109 ( V_19 ) ;
}
}
static int F_115 ( struct V_1 * V_3 ,
T_4 V_94 , T_7 V_150 )
{
struct V_55 * V_19 ;
struct V_88 V_89 ;
int V_160 ;
V_160 = V_3 -> V_182 . V_160 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
F_98 ( & V_89 , V_3 -> V_2 , V_160 , V_94 , V_150 ) ;
return F_105 ( V_19 , & V_89 ) ;
}
static int F_116 ( struct V_1 * V_3 )
{
struct V_55 * V_19 ;
int V_30 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_30 = F_107 ( V_19 , V_3 -> V_2 ) ;
if ( V_30 )
return V_30 ;
if ( V_3 -> V_182 . V_183 )
V_30 = F_115 ( V_3 , 0 , ~ 0UL ) ;
return V_30 ;
}
static void F_117 ( struct V_184 * V_185 ,
T_4 V_94 , T_7 V_150 , int V_151 )
{
struct V_1 * V_3 ;
struct V_88 V_89 ;
int V_30 = 0 , V_24 ;
F_96 ( & V_89 , V_94 , V_150 , V_185 -> V_186 , V_151 ) ;
for ( V_24 = 0 ; V_24 < V_187 ; ++ V_24 ) {
if ( ! V_185 -> V_188 [ V_24 ] )
continue;
V_30 |= F_105 ( V_189 [ V_24 ] , & V_89 ) ;
}
F_12 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_182 . V_183 )
continue;
V_30 |= F_115 ( V_3 , V_94 , V_150 ) ;
}
F_42 ( V_30 ) ;
}
static void F_118 ( struct V_184 * V_185 ,
T_4 V_94 , T_7 V_150 )
{
F_117 ( V_185 , V_94 , V_150 , 0 ) ;
}
static void F_119 ( struct V_184 * V_185 )
{
F_117 ( V_185 , 0 , V_155 , 0 ) ;
}
static void F_120 ( struct V_184 * V_185 )
{
F_117 ( V_185 , 0 , V_155 , 1 ) ;
}
static void F_121 ( struct V_184 * V_185 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_187 ; ++ V_24 ) {
if ( ! V_185 -> V_188 [ V_24 ] )
continue;
F_106 ( V_189 [ V_24 ] ) ;
}
}
static void F_122 ( struct V_184 * V_185 )
{
struct V_1 * V_3 ;
F_12 (dev_data, &domain->dev_list, list)
F_116 ( V_3 ) ;
}
static bool F_123 ( struct V_184 * V_185 ,
T_8 V_190 )
{
T_4 * V_191 ;
if ( V_185 -> V_192 == V_193 )
return false ;
V_191 = ( void * ) F_124 ( V_190 ) ;
if ( ! V_191 )
return false ;
* V_191 = F_125 ( V_185 -> V_192 ,
F_126 ( V_185 -> V_194 ) ) ;
V_185 -> V_194 = V_191 ;
V_185 -> V_192 += 1 ;
V_185 -> V_195 = true ;
return true ;
}
static T_4 * F_127 ( struct V_184 * V_185 ,
unsigned long V_94 ,
unsigned long V_196 ,
T_4 * * V_197 ,
T_8 V_190 )
{
int V_198 , V_199 ;
T_4 * V_191 , * V_200 ;
F_128 ( ! F_129 ( V_196 ) ) ;
while ( V_94 > F_130 ( V_185 -> V_192 ) )
F_123 ( V_185 , V_190 ) ;
V_198 = V_185 -> V_192 - 1 ;
V_191 = & V_185 -> V_194 [ F_131 ( V_198 , V_94 ) ] ;
V_94 = F_132 ( V_94 , V_196 ) ;
V_199 = F_133 ( V_196 ) ;
while ( V_198 > V_199 ) {
if ( ! F_134 ( * V_191 ) ) {
V_200 = ( T_4 * ) F_124 ( V_190 ) ;
if ( ! V_200 )
return NULL ;
* V_191 = F_125 ( V_198 , F_126 ( V_200 ) ) ;
}
if ( F_135 ( * V_191 ) != V_198 )
return NULL ;
V_198 -= 1 ;
V_191 = F_136 ( * V_191 ) ;
if ( V_197 && V_198 == V_199 )
* V_197 = V_191 ;
V_191 = & V_191 [ F_131 ( V_198 , V_94 ) ] ;
}
return V_191 ;
}
static T_4 * F_137 ( struct V_184 * V_185 , unsigned long V_94 )
{
int V_198 ;
T_4 * V_191 ;
if ( V_94 > F_130 ( V_185 -> V_192 ) )
return NULL ;
V_198 = V_185 -> V_192 - 1 ;
V_191 = & V_185 -> V_194 [ F_131 ( V_198 , V_94 ) ] ;
while ( V_198 > 0 ) {
if ( ! F_134 ( * V_191 ) )
return NULL ;
if ( F_135 ( * V_191 ) == 0x07 ) {
unsigned long V_201 , V_202 ;
V_201 = F_138 ( * V_191 ) ;
V_201 = ~ ( ( F_139 ( V_201 ) << 3 ) - 1 ) ;
V_202 = ( ( unsigned long ) V_191 ) & V_201 ;
return ( T_4 * ) V_202 ;
}
if ( F_135 ( * V_191 ) != V_198 )
return NULL ;
V_198 -= 1 ;
V_191 = F_136 ( * V_191 ) ;
V_191 = & V_191 [ F_131 ( V_198 , V_94 ) ] ;
}
return V_191 ;
}
static int F_140 ( struct V_184 * V_203 ,
unsigned long V_204 ,
unsigned long V_87 ,
int V_205 ,
unsigned long V_196 )
{
T_4 V_202 , * V_191 ;
int V_24 , V_93 ;
if ( ! ( V_205 & V_206 ) )
return - V_207 ;
V_204 = F_141 ( V_204 ) ;
V_87 = F_141 ( V_87 ) ;
V_93 = F_139 ( V_196 ) ;
V_191 = F_127 ( V_203 , V_204 , V_196 , NULL , V_5 ) ;
for ( V_24 = 0 ; V_24 < V_93 ; ++ V_24 )
if ( F_134 ( V_191 [ V_24 ] ) )
return - V_208 ;
if ( V_196 > V_154 ) {
V_202 = F_142 ( V_87 , V_196 ) ;
V_202 |= F_143 ( 7 ) | V_209 | V_210 ;
} else
V_202 = V_87 | V_209 | V_210 ;
if ( V_205 & V_211 )
V_202 |= V_212 ;
if ( V_205 & V_213 )
V_202 |= V_214 ;
for ( V_24 = 0 ; V_24 < V_93 ; ++ V_24 )
V_191 [ V_24 ] = V_202 ;
F_144 ( V_203 ) ;
return 0 ;
}
static unsigned long F_145 ( struct V_184 * V_203 ,
unsigned long V_204 ,
unsigned long V_196 )
{
unsigned long long V_215 , V_216 ;
T_4 * V_191 ;
F_128 ( ! F_129 ( V_196 ) ) ;
V_216 = 0 ;
while ( V_216 < V_196 ) {
V_191 = F_137 ( V_203 , V_204 ) ;
if ( ! V_191 ) {
V_215 = V_154 ;
} else if ( F_135 ( * V_191 ) == 0 ) {
V_215 = V_154 ;
* V_191 = 0ULL ;
} else {
int V_93 , V_24 ;
V_215 = F_138 ( * V_191 ) ;
V_93 = F_139 ( V_215 ) ;
for ( V_24 = 0 ; V_24 < V_93 ; V_24 ++ )
V_191 [ V_24 ] = 0ULL ;
}
V_204 = ( V_204 & ~ ( V_215 - 1 ) ) + V_215 ;
V_216 += V_215 ;
}
F_128 ( ! F_129 ( V_216 ) ) ;
return V_216 ;
}
static int F_146 ( struct V_55 * V_19 ,
struct V_217 * V_29 )
{
T_1 V_218 , V_24 ;
for ( V_24 = V_29 -> V_219 ; V_24 <= V_29 -> V_220 ; ++ V_24 ) {
V_218 = V_32 [ V_24 ] ;
if ( V_39 [ V_218 ] == V_19 )
return 1 ;
}
return 0 ;
}
static int F_147 ( struct V_28 * V_221 ,
struct V_217 * V_222 )
{
T_4 V_223 ;
int V_30 ;
for ( V_223 = V_222 -> V_224 ; V_223 < V_222 -> V_225 ;
V_223 += V_154 ) {
V_30 = F_140 ( & V_221 -> V_185 , V_223 , V_223 , V_222 -> V_205 ,
V_154 ) ;
if ( V_30 )
return V_30 ;
if ( V_223 < V_221 -> V_226 )
F_148 ( V_223 >> V_227 ,
V_221 -> V_228 [ 0 ] -> V_229 ) ;
}
return 0 ;
}
static int F_149 ( struct V_55 * V_19 )
{
struct V_217 * V_29 ;
int V_30 ;
F_12 (entry, &amd_iommu_unity_map, list) {
if ( ! F_146 ( V_19 , V_29 ) )
continue;
V_30 = F_147 ( V_19 -> V_230 , V_29 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static int F_150 ( struct V_28 * V_221 ,
T_1 V_2 )
{
struct V_217 * V_222 ;
int V_30 ;
F_12 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_222 -> V_219 && V_2 <= V_222 -> V_220 ) )
continue;
V_30 = F_147 ( V_221 , V_222 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static void F_151 ( struct V_28 * V_203 ,
unsigned long V_231 ,
unsigned int V_152 )
{
unsigned int V_24 , V_232 = V_203 -> V_226 >> V_227 ;
if ( V_231 + V_152 > V_232 )
V_152 = V_232 - V_231 ;
for ( V_24 = V_231 ; V_24 < V_231 + V_152 ; ++ V_24 ) {
int V_233 = V_24 / V_234 ;
int V_200 = V_24 % V_234 ;
F_148 ( V_200 , V_203 -> V_228 [ V_233 ] -> V_229 ) ;
}
}
static int F_152 ( struct V_28 * V_221 ,
bool V_235 , T_8 V_190 )
{
int V_233 = V_221 -> V_226 >> V_236 ;
struct V_55 * V_19 ;
unsigned long V_24 , V_237 ;
#ifdef F_153
V_235 = false ;
#endif
if ( V_233 >= V_238 )
return - V_50 ;
V_221 -> V_228 [ V_233 ] = F_2 ( sizeof( struct V_239 ) , V_190 ) ;
if ( ! V_221 -> V_228 [ V_233 ] )
return - V_50 ;
V_221 -> V_228 [ V_233 ] -> V_229 = ( void * ) F_124 ( V_190 ) ;
if ( ! V_221 -> V_228 [ V_233 ] -> V_229 )
goto V_61;
V_221 -> V_228 [ V_233 ] -> V_240 = V_221 -> V_226 ;
if ( V_235 ) {
unsigned long V_94 = V_221 -> V_226 ;
int V_24 , V_241 = V_234 / 512 ;
T_4 * V_191 , * V_197 ;
for ( V_24 = 0 ; V_24 < V_241 ; ++ V_24 ) {
V_191 = F_127 ( & V_221 -> V_185 , V_94 , V_154 ,
& V_197 , V_190 ) ;
if ( ! V_191 )
goto V_61;
V_221 -> V_228 [ V_233 ] -> V_242 [ V_24 ] = V_197 ;
V_94 += V_243 / 64 ;
}
}
V_237 = V_221 -> V_226 ;
V_221 -> V_226 += V_243 ;
if ( V_237 < V_244 &&
V_221 -> V_226 > V_244 ) {
unsigned long V_245 ;
int V_152 ;
V_152 = F_97 ( V_244 , 0x10000 , V_154 ) ;
V_245 = V_244 >> V_227 ;
F_151 ( V_221 , V_245 , V_152 ) ;
}
F_85 (iommu) {
if ( V_19 -> V_246 &&
V_19 -> V_246 >= V_221 -> V_228 [ V_233 ] -> V_240
&& V_19 -> V_246 < V_221 -> V_226 ) {
unsigned long V_247 ;
int V_152 = F_97 ( V_19 -> V_246 ,
V_19 -> V_248 ,
V_154 ) ;
V_247 = V_19 -> V_246 >> V_227 ;
F_151 ( V_221 , V_247 , V_152 ) ;
}
}
for ( V_24 = V_221 -> V_228 [ V_233 ] -> V_240 ;
V_24 < V_221 -> V_226 ;
V_24 += V_154 ) {
T_4 * V_191 = F_137 ( & V_221 -> V_185 , V_24 ) ;
if ( ! V_191 || ! F_134 ( * V_191 ) )
continue;
F_151 ( V_221 , V_24 >> V_227 , 1 ) ;
}
F_144 ( & V_221 -> V_185 ) ;
return 0 ;
V_61:
F_144 ( & V_221 -> V_185 ) ;
F_154 ( ( unsigned long ) V_221 -> V_228 [ V_233 ] -> V_229 ) ;
F_10 ( V_221 -> V_228 [ V_233 ] ) ;
V_221 -> V_228 [ V_233 ] = NULL ;
return - V_50 ;
}
static unsigned long F_155 ( struct V_11 * V_12 ,
struct V_28 * V_203 ,
unsigned int V_152 ,
unsigned long V_249 ,
T_4 V_36 ,
unsigned long V_250 )
{
unsigned long V_251 = V_203 -> V_252 % V_243 ;
int V_253 = V_203 -> V_226 >> V_236 ;
int V_24 = V_250 >> V_236 ;
unsigned long V_254 ;
unsigned long V_94 = - 1 ;
unsigned long V_255 ;
V_251 >>= V_227 ;
V_254 = F_156 ( F_157 ( V_12 ) + 1 ,
V_154 ) >> V_227 ;
for (; V_24 < V_253 ; ++ V_24 ) {
unsigned long V_240 = V_203 -> V_228 [ V_24 ] -> V_240 >> V_227 ;
if ( V_203 -> V_228 [ V_24 ] -> V_240 >= V_36 )
break;
V_255 = F_158 ( V_234 , V_240 ,
V_36 >> V_227 ) ;
V_94 = F_159 ( V_203 -> V_228 [ V_24 ] -> V_229 ,
V_255 , V_251 , V_152 , 0 ,
V_254 , V_249 ) ;
if ( V_94 != - 1 ) {
V_94 = V_203 -> V_228 [ V_24 ] -> V_240 +
( V_94 << V_227 ) ;
V_203 -> V_252 = V_94 + ( V_152 << V_227 ) ;
break;
}
V_251 = 0 ;
}
return V_94 ;
}
static unsigned long F_160 ( struct V_11 * V_12 ,
struct V_28 * V_203 ,
unsigned int V_152 ,
unsigned long V_249 ,
T_4 V_36 )
{
unsigned long V_94 ;
#ifdef F_153
V_203 -> V_252 = 0 ;
V_203 -> V_256 = true ;
#endif
V_94 = F_155 ( V_12 , V_203 , V_152 , V_249 ,
V_36 , V_203 -> V_252 ) ;
if ( V_94 == - 1 ) {
V_203 -> V_252 = 0 ;
V_94 = F_155 ( V_12 , V_203 , V_152 , V_249 ,
V_36 , 0 ) ;
V_203 -> V_256 = true ;
}
if ( F_161 ( V_94 == - 1 ) )
V_94 = V_257 ;
F_42 ( ( V_94 + ( V_154 * V_152 ) ) > V_203 -> V_226 ) ;
return V_94 ;
}
static void F_162 ( struct V_28 * V_203 ,
unsigned long V_94 ,
unsigned int V_152 )
{
unsigned V_24 = V_94 >> V_236 ;
struct V_239 * V_258 = V_203 -> V_228 [ V_24 ] ;
F_128 ( V_24 >= V_238 || V_258 == NULL ) ;
#ifdef F_153
if ( V_24 < 4 )
return;
#endif
if ( V_94 >= V_203 -> V_252 )
V_203 -> V_256 = true ;
V_94 = ( V_94 % V_243 ) >> V_227 ;
F_163 ( V_258 -> V_229 , V_94 , V_152 ) ;
}
static void F_164 ( struct V_184 * V_185 )
{
unsigned long V_4 ;
F_4 ( & V_259 , V_4 ) ;
F_165 ( & V_185 -> V_260 , & V_261 ) ;
F_6 ( & V_259 , V_4 ) ;
}
static void F_166 ( struct V_184 * V_185 )
{
unsigned long V_4 ;
F_4 ( & V_259 , V_4 ) ;
F_8 ( & V_185 -> V_260 ) ;
F_6 ( & V_259 , V_4 ) ;
}
static T_1 F_167 ( void )
{
unsigned long V_4 ;
int V_186 ;
F_168 ( & V_262 , V_4 ) ;
V_186 = F_169 ( V_263 , V_264 ) ;
F_128 ( V_186 == 0 ) ;
if ( V_186 > 0 && V_186 < V_264 )
F_148 ( V_186 , V_263 ) ;
else
V_186 = 0 ;
F_170 ( & V_262 , V_4 ) ;
return V_186 ;
}
static void F_171 ( int V_186 )
{
unsigned long V_4 ;
F_168 ( & V_262 , V_4 ) ;
if ( V_186 > 0 && V_186 < V_264 )
F_172 ( V_186 , V_263 ) ;
F_170 ( & V_262 , V_4 ) ;
}
static void F_173 ( struct V_184 * V_185 )
{
int V_24 , V_265 ;
T_4 * V_266 , * V_267 , * V_268 ;
V_266 = V_185 -> V_194 ;
if ( ! V_266 )
return;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! F_134 ( V_266 [ V_24 ] ) )
continue;
V_267 = F_136 ( V_266 [ V_24 ] ) ;
for ( V_265 = 0 ; V_265 < 512 ; ++ V_265 ) {
if ( ! F_134 ( V_267 [ V_265 ] ) )
continue;
V_268 = F_136 ( V_267 [ V_265 ] ) ;
F_154 ( ( unsigned long ) V_268 ) ;
}
F_154 ( ( unsigned long ) V_267 ) ;
}
F_154 ( ( unsigned long ) V_266 ) ;
V_185 -> V_194 = NULL ;
}
static void F_174 ( T_4 * V_269 )
{
T_4 * V_270 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! ( V_269 [ V_24 ] & V_271 ) )
continue;
V_270 = F_175 ( V_269 [ V_24 ] & V_156 ) ;
F_154 ( ( unsigned long ) V_270 ) ;
}
}
static void F_176 ( T_4 * V_269 )
{
T_4 * V_270 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! ( V_269 [ V_24 ] & V_271 ) )
continue;
V_270 = F_175 ( V_269 [ V_24 ] & V_156 ) ;
F_174 ( V_270 ) ;
}
}
static void F_177 ( struct V_184 * V_185 )
{
if ( V_185 -> V_272 == 2 )
F_176 ( V_185 -> V_273 ) ;
else if ( V_185 -> V_272 == 1 )
F_174 ( V_185 -> V_273 ) ;
else if ( V_185 -> V_272 != 0 )
F_178 () ;
F_154 ( ( unsigned long ) V_185 -> V_273 ) ;
}
static void F_179 ( struct V_28 * V_203 )
{
int V_24 ;
if ( ! V_203 )
return;
F_166 ( & V_203 -> V_185 ) ;
F_173 ( & V_203 -> V_185 ) ;
for ( V_24 = 0 ; V_24 < V_238 ; ++ V_24 ) {
if ( ! V_203 -> V_228 [ V_24 ] )
continue;
F_154 ( ( unsigned long ) V_203 -> V_228 [ V_24 ] -> V_229 ) ;
F_10 ( V_203 -> V_228 [ V_24 ] ) ;
}
F_10 ( V_203 ) ;
}
static struct V_28 * F_180 ( void )
{
struct V_28 * V_221 ;
V_221 = F_2 ( sizeof( struct V_28 ) , V_5 ) ;
if ( ! V_221 )
return NULL ;
F_181 ( & V_221 -> V_185 . V_116 ) ;
V_221 -> V_185 . V_186 = F_167 () ;
if ( V_221 -> V_185 . V_186 == 0 )
goto V_274;
F_182 ( & V_221 -> V_185 . V_275 ) ;
V_221 -> V_185 . V_192 = V_276 ;
V_221 -> V_185 . V_194 = ( void * ) F_124 ( V_5 ) ;
V_221 -> V_185 . V_4 = V_277 ;
V_221 -> V_185 . V_278 = V_221 ;
if ( ! V_221 -> V_185 . V_194 )
goto V_274;
V_221 -> V_256 = false ;
V_221 -> V_35 = 0xffff ;
F_164 ( & V_221 -> V_185 ) ;
if ( F_152 ( V_221 , true , V_5 ) )
goto V_274;
V_221 -> V_228 [ 0 ] -> V_229 [ 0 ] = 1 ;
V_221 -> V_252 = 0 ;
return V_221 ;
V_274:
F_179 ( V_221 ) ;
return NULL ;
}
static bool V_28 ( struct V_184 * V_185 )
{
return V_185 -> V_4 & V_277 ;
}
static void F_183 ( T_1 V_2 , struct V_184 * V_185 , bool V_182 )
{
T_4 V_279 = 0 ;
T_4 V_4 = 0 ;
if ( V_185 -> V_192 != V_280 )
V_279 = F_126 ( V_185 -> V_194 ) ;
V_279 |= ( V_185 -> V_192 & V_281 )
<< V_282 ;
V_279 |= V_212 | V_214 | V_209 | V_283 ;
V_4 = V_58 [ V_2 ] . V_86 [ 1 ] ;
if ( V_182 )
V_4 |= V_284 ;
if ( V_185 -> V_4 & V_285 ) {
T_4 V_286 = F_92 ( V_185 -> V_273 ) ;
T_4 V_272 = V_185 -> V_272 ;
T_4 V_287 ;
V_279 |= V_288 ;
V_279 |= ( V_272 & V_289 ) << V_290 ;
V_287 = F_184 ( ~ 0ULL ) << V_291 ;
V_4 &= ~ V_287 ;
V_287 = F_185 ( ~ 0ULL ) << V_292 ;
V_4 &= ~ V_287 ;
V_287 = F_186 ( V_286 ) << V_293 ;
V_279 |= V_287 ;
V_287 = F_184 ( V_286 ) << V_291 ;
V_4 |= V_287 ;
V_287 = F_185 ( V_286 ) << V_292 ;
V_4 |= V_287 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_185 -> V_186 ;
V_58 [ V_2 ] . V_86 [ 1 ] = V_4 ;
V_58 [ V_2 ] . V_86 [ 0 ] = V_279 ;
}
static void F_187 ( T_1 V_2 )
{
V_58 [ V_2 ] . V_86 [ 0 ] = V_209 | V_283 ;
V_58 [ V_2 ] . V_86 [ 1 ] = 0 ;
F_188 ( V_2 ) ;
}
static void F_189 ( struct V_1 * V_3 ,
struct V_184 * V_185 )
{
struct V_55 * V_19 ;
bool V_182 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_182 = V_3 -> V_182 . V_183 ;
V_3 -> V_185 = V_185 ;
F_165 ( & V_3 -> V_260 , & V_185 -> V_275 ) ;
F_183 ( V_3 -> V_2 , V_185 , V_182 ) ;
V_185 -> V_188 [ V_19 -> V_233 ] += 1 ;
V_185 -> V_294 += 1 ;
F_116 ( V_3 ) ;
}
static void F_190 ( struct V_1 * V_3 )
{
struct V_55 * V_19 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_3 -> V_185 -> V_188 [ V_19 -> V_233 ] -= 1 ;
V_3 -> V_185 -> V_294 -= 1 ;
V_3 -> V_185 = NULL ;
F_8 ( & V_3 -> V_260 ) ;
F_187 ( V_3 -> V_2 ) ;
F_116 ( V_3 ) ;
}
static int F_191 ( struct V_1 * V_3 ,
struct V_184 * V_185 )
{
int V_30 ;
F_192 ( & V_185 -> V_116 ) ;
if ( V_3 -> V_51 != NULL ) {
struct V_1 * V_51 = V_3 -> V_51 ;
V_30 = - V_208 ;
if ( V_51 -> V_185 != NULL &&
V_51 -> V_185 != V_185 )
goto V_10;
if ( V_3 -> V_185 != NULL &&
V_3 -> V_185 != V_185 )
goto V_10;
if ( V_51 -> V_185 == NULL )
F_189 ( V_51 , V_185 ) ;
F_193 ( & V_51 -> V_6 ) ;
}
if ( V_3 -> V_185 == NULL )
F_189 ( V_3 , V_185 ) ;
F_193 ( & V_3 -> V_6 ) ;
V_30 = 0 ;
V_10:
F_194 ( & V_185 -> V_116 ) ;
return V_30 ;
}
static void F_195 ( struct V_13 * V_14 )
{
F_196 ( V_14 ) ;
F_197 ( V_14 ) ;
F_198 ( V_14 ) ;
}
static int F_199 ( struct V_13 * V_14 )
{
T_1 V_295 ;
int V_25 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( ! V_25 )
return - V_207 ;
F_200 ( V_14 , V_25 + V_296 , & V_295 ) ;
V_295 |= V_297 ;
F_201 ( V_14 , V_25 + V_296 , V_295 ) ;
return 0 ;
}
static int F_202 ( struct V_13 * V_14 )
{
bool V_298 ;
int V_299 , V_30 ;
V_299 = 32 ;
if ( F_20 ( V_14 , V_300 ) )
V_299 = 1 ;
V_298 = F_20 ( V_14 , V_301 ) ;
V_30 = F_203 ( V_14 , 0 ) ;
if ( V_30 )
goto V_302;
V_30 = F_204 ( V_14 ) ;
if ( V_30 )
goto V_302;
V_30 = F_205 ( V_14 , V_299 ) ;
if ( V_30 )
goto V_302;
if ( V_298 ) {
V_30 = F_199 ( V_14 ) ;
if ( V_30 )
goto V_302;
}
V_30 = F_206 ( V_14 , V_227 ) ;
if ( V_30 )
goto V_302;
return 0 ;
V_302:
F_197 ( V_14 ) ;
F_198 ( V_14 ) ;
return V_30 ;
}
static bool F_207 ( struct V_13 * V_14 )
{
T_1 V_164 ;
int V_25 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( ! V_25 )
return false ;
F_200 ( V_14 , V_25 + V_303 , & V_164 ) ;
return ( V_164 & V_304 ) ? true : false ;
}
static int F_208 ( struct V_11 * V_12 ,
struct V_184 * V_185 )
{
struct V_13 * V_14 = F_15 ( V_12 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_30 ;
V_3 = F_17 ( V_12 ) ;
if ( V_185 -> V_4 & V_285 ) {
if ( ! V_3 -> V_56 || ! V_3 -> V_305 )
return - V_207 ;
if ( F_202 ( V_14 ) != 0 )
return - V_207 ;
V_3 -> V_182 . V_183 = true ;
V_3 -> V_182 . V_160 = F_209 ( V_14 ) ;
V_3 -> V_306 = F_207 ( V_14 ) ;
} else if ( V_307 &&
F_206 ( V_14 , V_227 ) == 0 ) {
V_3 -> V_182 . V_183 = true ;
V_3 -> V_182 . V_160 = F_209 ( V_14 ) ;
}
F_168 ( & V_262 , V_4 ) ;
V_30 = F_191 ( V_3 , V_185 ) ;
F_170 ( & V_262 , V_4 ) ;
F_120 ( V_185 ) ;
return V_30 ;
}
static void F_210 ( struct V_1 * V_3 )
{
struct V_184 * V_185 ;
unsigned long V_4 ;
F_128 ( ! V_3 -> V_185 ) ;
V_185 = V_3 -> V_185 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
if ( V_3 -> V_51 != NULL ) {
struct V_1 * V_51 = V_3 -> V_51 ;
if ( F_211 ( & V_51 -> V_6 ) )
F_190 ( V_51 ) ;
}
if ( F_211 ( & V_3 -> V_6 ) )
F_190 ( V_3 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
if ( V_3 -> V_305 &&
( V_3 -> V_185 == NULL && V_185 != V_308 ) )
F_191 ( V_3 , V_308 ) ;
}
static void F_212 ( struct V_11 * V_12 )
{
struct V_184 * V_185 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_17 ( V_12 ) ;
V_185 = V_3 -> V_185 ;
F_168 ( & V_262 , V_4 ) ;
F_210 ( V_3 ) ;
F_170 ( & V_262 , V_4 ) ;
if ( V_185 -> V_4 & V_285 )
F_195 ( F_15 ( V_12 ) ) ;
else if ( V_3 -> V_182 . V_183 )
F_196 ( F_15 ( V_12 ) ) ;
V_3 -> V_182 . V_183 = false ;
}
static struct V_184 * F_213 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_184 * V_203 = NULL ;
unsigned long V_4 ;
V_3 = F_17 ( V_12 ) ;
if ( V_3 -> V_185 )
return V_3 -> V_185 ;
if ( V_3 -> V_51 != NULL ) {
struct V_1 * V_51 = V_3 -> V_51 ;
F_214 ( & V_262 , V_4 ) ;
if ( V_51 -> V_185 != NULL ) {
F_191 ( V_3 , V_51 -> V_185 ) ;
V_203 = V_51 -> V_185 ;
}
F_215 ( & V_262 , V_4 ) ;
}
return V_203 ;
}
static int F_216 ( struct V_309 * V_310 ,
unsigned long V_311 , void * V_86 )
{
struct V_28 * V_312 ;
struct V_184 * V_185 ;
struct V_1 * V_3 ;
struct V_11 * V_12 = V_86 ;
struct V_55 * V_19 ;
unsigned long V_4 ;
T_1 V_2 ;
if ( ! F_23 ( V_12 ) )
return 0 ;
V_2 = F_14 ( V_12 ) ;
V_19 = V_39 [ V_2 ] ;
V_3 = F_17 ( V_12 ) ;
switch ( V_311 ) {
case V_313 :
V_185 = F_213 ( V_12 ) ;
if ( ! V_185 )
goto V_314;
if ( V_3 -> V_305 )
break;
F_212 ( V_12 ) ;
break;
case V_315 :
F_48 ( V_12 ) ;
V_3 = F_17 ( V_12 ) ;
if ( V_316 || V_3 -> V_56 ) {
V_3 -> V_305 = true ;
F_208 ( V_12 , V_308 ) ;
break;
}
V_185 = F_213 ( V_12 ) ;
V_312 = F_21 ( V_2 ) ;
if ( ! V_312 ) {
V_312 = F_180 () ;
if ( ! V_312 )
goto V_314;
V_312 -> V_35 = V_2 ;
F_4 ( & V_34 , V_4 ) ;
F_5 ( & V_312 -> V_260 , & V_33 ) ;
F_6 ( & V_34 , V_4 ) ;
}
V_12 -> V_18 . V_317 = & V_318 ;
break;
case V_319 :
F_52 ( V_12 ) ;
default:
goto V_314;
}
F_106 ( V_19 ) ;
V_314:
return 0 ;
}
void F_217 ( void )
{
F_218 ( & V_37 , & V_320 ) ;
}
static struct V_184 * F_219 ( struct V_11 * V_12 )
{
struct V_184 * V_185 ;
struct V_28 * V_221 ;
T_1 V_2 = F_14 ( V_12 ) ;
if ( ! F_23 ( V_12 ) )
return F_28 ( - V_207 ) ;
V_185 = F_213 ( V_12 ) ;
if ( V_185 != NULL && ! V_28 ( V_185 ) )
return F_28 ( - V_208 ) ;
if ( V_185 != NULL )
return V_185 ;
V_221 = F_21 ( V_2 ) ;
if ( ! V_221 )
V_221 = V_39 [ V_2 ] -> V_230 ;
F_208 ( V_12 , & V_221 -> V_185 ) ;
F_220 ( L_23 ,
V_221 -> V_185 . V_186 , F_50 ( V_12 ) ) ;
return & V_221 -> V_185 ;
}
static void F_221 ( struct V_184 * V_185 )
{
struct V_1 * V_3 ;
F_12 (dev_data, &domain->dev_list, list)
F_183 ( V_3 -> V_2 , V_185 , V_3 -> V_182 . V_183 ) ;
}
static void F_144 ( struct V_184 * V_185 )
{
if ( ! V_185 -> V_195 )
return;
F_221 ( V_185 ) ;
F_122 ( V_185 ) ;
F_120 ( V_185 ) ;
V_185 -> V_195 = false ;
}
static T_4 * F_222 ( struct V_28 * V_203 ,
unsigned long V_94 )
{
struct V_239 * V_228 ;
T_4 * V_191 , * V_197 ;
V_228 = V_203 -> V_228 [ F_223 ( V_94 ) ] ;
if ( ! V_228 )
return NULL ;
V_191 = V_228 -> V_242 [ F_224 ( V_94 ) ] ;
if ( ! V_191 ) {
V_191 = F_127 ( & V_203 -> V_185 , V_94 , V_154 , & V_197 ,
V_321 ) ;
V_228 -> V_242 [ F_224 ( V_94 ) ] = V_197 ;
} else
V_191 += F_131 ( 0 , V_94 ) ;
F_144 ( & V_203 -> V_185 ) ;
return V_191 ;
}
static T_9 F_225 ( struct V_28 * V_203 ,
unsigned long V_94 ,
T_10 V_322 ,
int V_323 )
{
T_4 * V_191 , V_202 ;
F_42 ( V_94 > V_203 -> V_226 ) ;
V_322 &= V_156 ;
V_191 = F_222 ( V_203 , V_94 ) ;
if ( ! V_191 )
return V_257 ;
V_202 = V_322 | V_209 | V_210 ;
if ( V_323 == V_324 )
V_202 |= V_212 ;
else if ( V_323 == V_325 )
V_202 |= V_214 ;
else if ( V_323 == V_326 )
V_202 |= V_212 | V_214 ;
F_42 ( * V_191 ) ;
* V_191 = V_202 ;
return ( T_9 ) V_94 ;
}
static void F_226 ( struct V_28 * V_203 ,
unsigned long V_94 )
{
struct V_239 * V_228 ;
T_4 * V_191 ;
if ( V_94 >= V_203 -> V_226 )
return;
V_228 = V_203 -> V_228 [ F_223 ( V_94 ) ] ;
if ( ! V_228 )
return;
V_191 = V_228 -> V_242 [ F_224 ( V_94 ) ] ;
if ( ! V_191 )
return;
V_191 += F_131 ( 0 , V_94 ) ;
F_42 ( ! * V_191 ) ;
* V_191 = 0ULL ;
}
static T_9 F_227 ( struct V_11 * V_12 ,
struct V_28 * V_221 ,
T_10 V_322 ,
T_7 V_150 ,
int V_327 ,
bool V_328 ,
T_4 V_36 )
{
T_9 V_240 = V_322 & ~ V_156 ;
T_9 V_94 , V_250 , V_30 ;
unsigned int V_152 ;
unsigned long V_249 = 0 ;
int V_24 ;
V_152 = F_97 ( V_322 , V_150 , V_154 ) ;
V_322 &= V_156 ;
F_75 ( V_81 ) ;
if ( V_152 > 1 )
F_75 ( V_77 ) ;
if ( V_328 )
V_249 = ( 1UL << F_228 ( V_150 ) ) - 1 ;
V_95:
V_94 = F_160 ( V_12 , V_221 , V_152 , V_249 ,
V_36 ) ;
if ( F_161 ( V_94 == V_257 ) ) {
V_221 -> V_252 = V_221 -> V_226 ;
if ( F_152 ( V_221 , false , V_321 ) )
goto V_314;
goto V_95;
}
V_250 = V_94 ;
for ( V_24 = 0 ; V_24 < V_152 ; ++ V_24 ) {
V_30 = F_225 ( V_221 , V_250 , V_322 , V_327 ) ;
if ( V_30 == V_257 )
goto V_329;
V_322 += V_154 ;
V_250 += V_154 ;
}
V_94 += V_240 ;
F_229 ( V_80 , V_150 ) ;
if ( F_161 ( V_221 -> V_256 && ! V_69 ) ) {
F_119 ( & V_221 -> V_185 ) ;
V_221 -> V_256 = false ;
} else if ( F_161 ( V_330 ) )
F_118 ( & V_221 -> V_185 , V_94 , V_150 ) ;
V_314:
return V_94 ;
V_329:
for ( -- V_24 ; V_24 >= 0 ; -- V_24 ) {
V_250 -= V_154 ;
F_226 ( V_221 , V_250 ) ;
}
F_162 ( V_221 , V_94 , V_152 ) ;
return V_257 ;
}
static void F_230 ( struct V_28 * V_221 ,
T_9 V_331 ,
T_7 V_150 ,
int V_327 )
{
T_9 V_332 ;
T_9 V_24 , V_250 ;
unsigned int V_152 ;
if ( ( V_331 == V_257 ) ||
( V_331 + V_150 > V_221 -> V_226 ) )
return;
V_332 = V_331 ;
V_152 = F_97 ( V_331 , V_150 , V_154 ) ;
V_331 &= V_156 ;
V_250 = V_331 ;
for ( V_24 = 0 ; V_24 < V_152 ; ++ V_24 ) {
F_226 ( V_221 , V_250 ) ;
V_250 += V_154 ;
}
F_231 ( V_80 , V_150 ) ;
F_162 ( V_221 , V_331 , V_152 ) ;
if ( V_69 || V_221 -> V_256 ) {
F_118 ( & V_221 -> V_185 , V_332 , V_150 ) ;
V_221 -> V_256 = false ;
}
}
static T_9 F_232 ( struct V_11 * V_12 , struct V_200 * V_200 ,
unsigned long V_240 , T_7 V_150 ,
enum V_333 V_327 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_184 * V_185 ;
T_9 V_223 ;
T_4 V_36 ;
T_10 V_322 = F_233 ( V_200 ) + V_240 ;
F_75 ( V_71 ) ;
V_185 = F_219 ( V_12 ) ;
if ( F_41 ( V_185 ) == - V_207 )
return ( T_9 ) V_322 ;
else if ( F_35 ( V_185 ) )
return V_257 ;
V_36 = * V_12 -> V_36 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
V_223 = F_227 ( V_12 , V_185 -> V_278 , V_322 , V_150 , V_327 , false ,
V_36 ) ;
if ( V_223 == V_257 )
goto V_314;
F_121 ( V_185 ) ;
V_314:
F_6 ( & V_185 -> V_116 , V_4 ) ;
return V_223 ;
}
static void F_234 ( struct V_11 * V_12 , T_9 V_331 , T_7 V_150 ,
enum V_333 V_327 , struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_184 * V_185 ;
F_75 ( V_72 ) ;
V_185 = F_219 ( V_12 ) ;
if ( F_35 ( V_185 ) )
return;
F_4 ( & V_185 -> V_116 , V_4 ) ;
F_230 ( V_185 -> V_278 , V_331 , V_150 , V_327 ) ;
F_121 ( V_185 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
}
static int F_235 ( struct V_11 * V_12 , struct V_336 * V_337 ,
int V_338 , int V_327 )
{
struct V_336 * V_153 ;
int V_24 ;
F_236 (sglist, s, nelems, i) {
V_153 -> V_339 = ( T_9 ) F_237 ( V_153 ) ;
V_153 -> V_340 = V_153 -> V_341 ;
}
return V_338 ;
}
static int F_238 ( struct V_11 * V_12 , struct V_336 * V_337 ,
int V_338 , enum V_333 V_327 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_184 * V_185 ;
int V_24 ;
struct V_336 * V_153 ;
T_10 V_322 ;
int V_342 = 0 ;
T_4 V_36 ;
F_75 ( V_73 ) ;
V_185 = F_219 ( V_12 ) ;
if ( F_41 ( V_185 ) == - V_207 )
return F_235 ( V_12 , V_337 , V_338 , V_327 ) ;
else if ( F_35 ( V_185 ) )
return 0 ;
V_36 = * V_12 -> V_36 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
F_236 (sglist, s, nelems, i) {
V_322 = F_237 ( V_153 ) ;
V_153 -> V_339 = F_227 ( V_12 , V_185 -> V_278 ,
V_322 , V_153 -> V_341 , V_327 , false ,
V_36 ) ;
if ( V_153 -> V_339 ) {
V_153 -> V_340 = V_153 -> V_341 ;
V_342 ++ ;
} else
goto V_343;
}
F_121 ( V_185 ) ;
V_314:
F_6 ( & V_185 -> V_116 , V_4 ) ;
return V_342 ;
V_343:
F_236 (sglist, s, mapped_elems, i) {
if ( V_153 -> V_339 )
F_230 ( V_185 -> V_278 , V_153 -> V_339 ,
V_153 -> V_340 , V_327 ) ;
V_153 -> V_339 = V_153 -> V_340 = 0 ;
}
V_342 = 0 ;
goto V_314;
}
static void F_239 ( struct V_11 * V_12 , struct V_336 * V_337 ,
int V_338 , enum V_333 V_327 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_184 * V_185 ;
struct V_336 * V_153 ;
int V_24 ;
F_75 ( V_74 ) ;
V_185 = F_219 ( V_12 ) ;
if ( F_35 ( V_185 ) )
return;
F_4 ( & V_185 -> V_116 , V_4 ) ;
F_236 (sglist, s, nelems, i) {
F_230 ( V_185 -> V_278 , V_153 -> V_339 ,
V_153 -> V_340 , V_327 ) ;
V_153 -> V_339 = V_153 -> V_340 = 0 ;
}
F_121 ( V_185 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
}
static void * F_240 ( struct V_11 * V_12 , T_7 V_150 ,
T_9 * V_331 , T_8 V_344 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
void * V_345 ;
struct V_184 * V_185 ;
T_10 V_322 ;
T_4 V_36 = V_12 -> V_346 ;
F_75 ( V_75 ) ;
V_185 = F_219 ( V_12 ) ;
if ( F_41 ( V_185 ) == - V_207 ) {
V_345 = ( void * ) F_241 ( V_344 , F_228 ( V_150 ) ) ;
* V_331 = F_92 ( V_345 ) ;
return V_345 ;
} else if ( F_35 ( V_185 ) )
return NULL ;
V_36 = V_12 -> V_346 ;
V_344 &= ~ ( V_347 | V_348 | V_349 ) ;
V_344 |= V_350 ;
V_345 = ( void * ) F_241 ( V_344 , F_228 ( V_150 ) ) ;
if ( ! V_345 )
return NULL ;
V_322 = F_126 ( V_345 ) ;
if ( ! V_36 )
V_36 = * V_12 -> V_36 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
* V_331 = F_227 ( V_12 , V_185 -> V_278 , V_322 ,
V_150 , V_326 , true , V_36 ) ;
if ( * V_331 == V_257 ) {
F_6 ( & V_185 -> V_116 , V_4 ) ;
goto V_61;
}
F_121 ( V_185 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
return V_345 ;
V_61:
F_242 ( ( unsigned long ) V_345 , F_228 ( V_150 ) ) ;
return NULL ;
}
static void F_243 ( struct V_11 * V_12 , T_7 V_150 ,
void * V_345 , T_9 V_331 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_184 * V_185 ;
F_75 ( V_76 ) ;
V_185 = F_219 ( V_12 ) ;
if ( F_35 ( V_185 ) )
goto V_351;
F_4 ( & V_185 -> V_116 , V_4 ) ;
F_230 ( V_185 -> V_278 , V_331 , V_150 , V_326 ) ;
F_121 ( V_185 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
V_351:
F_242 ( ( unsigned long ) V_345 , F_228 ( V_150 ) ) ;
}
static int F_244 ( struct V_11 * V_12 , T_4 V_352 )
{
return F_23 ( V_12 ) ;
}
static void T_3 F_245 ( void )
{
struct V_1 * V_3 ;
struct V_28 * V_221 ;
struct V_13 * V_12 = NULL ;
T_1 V_2 ;
F_55 (dev) {
if ( ! F_23 ( & V_12 -> V_12 ) )
continue;
V_3 = F_17 ( & V_12 -> V_12 ) ;
if ( ! V_353 && V_3 -> V_56 ) {
F_246 () ;
V_3 -> V_305 = true ;
F_208 ( & V_12 -> V_12 , V_308 ) ;
F_247 ( L_24 ,
F_50 ( & V_12 -> V_12 ) ) ;
}
if ( F_213 ( & V_12 -> V_12 ) )
continue;
V_2 = F_14 ( & V_12 -> V_12 ) ;
V_221 = F_180 () ;
if ( ! V_221 )
continue;
F_150 ( V_221 , V_2 ) ;
V_221 -> V_35 = V_2 ;
F_208 ( & V_12 -> V_12 , & V_221 -> V_185 ) ;
F_5 ( & V_221 -> V_260 , & V_33 ) ;
}
}
static unsigned F_248 ( void )
{
struct V_1 * V_3 ;
struct V_13 * V_14 = NULL ;
unsigned V_354 = 0 ;
F_55 (pdev) {
if ( ! F_23 ( & V_14 -> V_12 ) ) {
F_51 ( & V_14 -> V_12 ) ;
V_354 += 1 ;
continue;
}
V_3 = F_17 ( & V_14 -> V_12 ) ;
if ( ! V_3 -> V_305 )
V_14 -> V_12 . V_18 . V_317 = & V_318 ;
else
V_14 -> V_12 . V_18 . V_317 = & V_355 ;
}
return V_354 ;
}
void T_3 F_249 ( void )
{
F_250 ( & V_37 , & V_356 ) ;
}
int T_3 F_251 ( void )
{
struct V_55 * V_19 ;
int V_30 , V_354 ;
F_85 (iommu) {
V_19 -> V_230 = F_180 () ;
if ( V_19 -> V_230 == NULL )
return - V_50 ;
V_19 -> V_230 -> V_185 . V_4 |= V_357 ;
V_30 = F_149 ( V_19 ) ;
if ( V_30 )
goto V_358;
}
F_245 () ;
V_359 = 1 ;
V_360 = 0 ;
V_354 = F_248 () ;
if ( V_354 && V_361 > V_362 ) {
V_360 = 1 ;
}
F_60 () ;
if ( V_69 )
F_247 ( L_25 ) ;
else
F_247 ( L_26 ) ;
return 0 ;
V_358:
F_85 (iommu) {
F_179 ( V_19 -> V_230 ) ;
}
return V_30 ;
}
static void F_252 ( struct V_184 * V_185 )
{
struct V_1 * V_3 , * V_363 ;
unsigned long V_4 ;
F_168 ( & V_262 , V_4 ) ;
F_56 (dev_data, next, &domain->dev_list, list) {
F_210 ( V_3 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
}
F_170 ( & V_262 , V_4 ) ;
}
static void F_253 ( struct V_184 * V_185 )
{
if ( ! V_185 )
return;
F_166 ( V_185 ) ;
if ( V_185 -> V_186 )
F_171 ( V_185 -> V_186 ) ;
F_10 ( V_185 ) ;
}
static struct V_184 * F_254 ( void )
{
struct V_184 * V_185 ;
V_185 = F_2 ( sizeof( * V_185 ) , V_5 ) ;
if ( ! V_185 )
return NULL ;
F_181 ( & V_185 -> V_116 ) ;
F_255 ( & V_185 -> V_364 ) ;
V_185 -> V_186 = F_167 () ;
if ( ! V_185 -> V_186 )
goto V_302;
F_182 ( & V_185 -> V_275 ) ;
F_164 ( V_185 ) ;
return V_185 ;
V_302:
F_10 ( V_185 ) ;
return NULL ;
}
static int T_3 F_246 ( void )
{
if ( V_308 != NULL )
return 0 ;
V_308 = F_254 () ;
if ( ! V_308 )
return - V_50 ;
V_308 -> V_192 = V_280 ;
return 0 ;
}
static int F_256 ( struct V_365 * V_203 )
{
struct V_184 * V_185 ;
V_185 = F_254 () ;
if ( ! V_185 )
goto V_61;
V_185 -> V_192 = V_366 ;
V_185 -> V_194 = ( void * ) F_124 ( V_5 ) ;
if ( ! V_185 -> V_194 )
goto V_61;
V_185 -> V_365 = V_203 ;
V_203 -> V_278 = V_185 ;
V_203 -> V_367 . V_368 = 0 ;
V_203 -> V_367 . V_369 = ~ 0ULL ;
V_203 -> V_367 . V_370 = true ;
return 0 ;
V_61:
F_253 ( V_185 ) ;
return - V_50 ;
}
static void F_257 ( struct V_365 * V_203 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
if ( ! V_185 )
return;
if ( V_185 -> V_294 > 0 )
F_252 ( V_185 ) ;
F_128 ( V_185 -> V_294 != 0 ) ;
if ( V_185 -> V_192 != V_280 )
F_173 ( V_185 ) ;
if ( V_185 -> V_4 & V_285 )
F_177 ( V_185 ) ;
F_253 ( V_185 ) ;
V_203 -> V_278 = NULL ;
}
static void F_258 ( struct V_365 * V_203 ,
struct V_11 * V_12 )
{
struct V_1 * V_3 = V_12 -> V_18 . V_19 ;
struct V_55 * V_19 ;
T_1 V_2 ;
if ( ! F_23 ( V_12 ) )
return;
V_2 = F_14 ( V_12 ) ;
if ( V_3 -> V_185 != NULL )
F_212 ( V_12 ) ;
V_19 = V_39 [ V_2 ] ;
if ( ! V_19 )
return;
F_106 ( V_19 ) ;
}
static int F_259 ( struct V_365 * V_203 ,
struct V_11 * V_12 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
struct V_1 * V_3 ;
struct V_55 * V_19 ;
int V_30 ;
if ( ! F_23 ( V_12 ) )
return - V_207 ;
V_3 = V_12 -> V_18 . V_19 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
if ( ! V_19 )
return - V_207 ;
if ( V_3 -> V_185 )
F_212 ( V_12 ) ;
V_30 = F_208 ( V_12 , V_185 ) ;
F_106 ( V_19 ) ;
return V_30 ;
}
static int F_260 ( struct V_365 * V_203 , unsigned long V_371 ,
T_10 V_322 , T_7 V_196 , int V_372 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
int V_205 = 0 ;
int V_30 ;
if ( V_185 -> V_192 == V_280 )
return - V_207 ;
if ( V_372 & V_373 )
V_205 |= V_211 ;
if ( V_372 & V_374 )
V_205 |= V_213 ;
F_261 ( & V_185 -> V_364 ) ;
V_30 = F_140 ( V_185 , V_371 , V_322 , V_205 , V_196 ) ;
F_262 ( & V_185 -> V_364 ) ;
return V_30 ;
}
static T_7 F_263 ( struct V_365 * V_203 , unsigned long V_371 ,
T_7 V_196 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
T_7 V_215 ;
if ( V_185 -> V_192 == V_280 )
return - V_207 ;
F_261 ( & V_185 -> V_364 ) ;
V_215 = F_145 ( V_185 , V_371 , V_196 ) ;
F_262 ( & V_185 -> V_364 ) ;
F_120 ( V_185 ) ;
return V_215 ;
}
static T_10 F_264 ( struct V_365 * V_203 ,
unsigned long V_371 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
unsigned long V_375 ;
T_10 V_322 ;
T_4 * V_191 , V_202 ;
if ( V_185 -> V_192 == V_280 )
return V_371 ;
V_191 = F_137 ( V_185 , V_371 ) ;
if ( ! V_191 || ! F_134 ( * V_191 ) )
return 0 ;
if ( F_135 ( * V_191 ) == 0 )
V_375 = V_154 - 1 ;
else
V_375 = F_138 ( * V_191 ) - 1 ;
V_202 = * V_191 & V_376 ;
V_322 = ( V_202 & ~ V_375 ) | ( V_371 & V_375 ) ;
return V_322 ;
}
static int F_265 ( struct V_365 * V_185 ,
unsigned long V_377 )
{
switch ( V_377 ) {
case V_378 :
return 1 ;
case V_379 :
return V_380 ;
}
return 0 ;
}
int T_3 F_266 ( void )
{
struct V_1 * V_3 ;
struct V_13 * V_12 = NULL ;
struct V_55 * V_19 ;
T_1 V_2 ;
int V_30 ;
V_30 = F_246 () ;
if ( V_30 )
return V_30 ;
F_55 (dev) {
if ( ! F_23 ( & V_12 -> V_12 ) )
continue;
V_3 = F_17 ( & V_12 -> V_12 ) ;
V_3 -> V_305 = true ;
V_2 = F_14 ( & V_12 -> V_12 ) ;
V_19 = V_39 [ V_2 ] ;
if ( ! V_19 )
continue;
F_208 ( & V_12 -> V_12 , V_308 ) ;
}
F_60 () ;
F_247 ( L_27 ) ;
return 0 ;
}
int F_267 ( struct V_309 * V_310 )
{
return F_268 ( & V_130 , V_310 ) ;
}
int F_269 ( struct V_309 * V_310 )
{
return F_270 ( & V_130 , V_310 ) ;
}
void F_271 ( struct V_365 * V_203 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
unsigned long V_4 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
V_185 -> V_192 = V_280 ;
V_185 -> V_195 = true ;
F_144 ( V_185 ) ;
F_173 ( V_185 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
}
int F_272 ( struct V_365 * V_203 , int V_381 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
unsigned long V_4 ;
int V_382 , V_30 ;
if ( V_381 <= 0 || V_381 > ( V_162 + 1 ) )
return - V_207 ;
for ( V_382 = 0 ; ( V_381 - 1 ) & ~ 0x1ff ; V_381 >>= 9 )
V_382 += 1 ;
if ( V_382 > V_383 )
return - V_207 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
V_30 = - V_208 ;
if ( V_185 -> V_294 > 0 || V_185 -> V_4 & V_285 )
goto V_314;
V_30 = - V_50 ;
V_185 -> V_273 = ( void * ) F_124 ( V_321 ) ;
if ( V_185 -> V_273 == NULL )
goto V_314;
V_185 -> V_272 = V_382 ;
V_185 -> V_4 |= V_285 ;
V_185 -> V_195 = true ;
F_144 ( V_185 ) ;
V_30 = 0 ;
V_314:
F_6 ( & V_185 -> V_116 , V_4 ) ;
return V_30 ;
}
static int F_273 ( struct V_184 * V_185 , int V_127 ,
T_4 V_94 , bool V_150 )
{
struct V_1 * V_3 ;
struct V_88 V_89 ;
int V_24 , V_30 ;
if ( ! ( V_185 -> V_4 & V_285 ) )
return - V_207 ;
F_99 ( & V_89 , V_185 -> V_186 , V_127 , V_94 , V_150 ) ;
for ( V_24 = 0 ; V_24 < V_187 ; ++ V_24 ) {
if ( V_185 -> V_188 [ V_24 ] == 0 )
continue;
V_30 = F_105 ( V_189 [ V_24 ] , & V_89 ) ;
if ( V_30 != 0 )
goto V_314;
}
F_121 ( V_185 ) ;
F_12 (dev_data, &domain->dev_list, list) {
struct V_55 * V_19 ;
int V_160 ;
F_128 ( ! V_3 -> V_182 . V_183 ) ;
V_160 = V_3 -> V_182 . V_160 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
F_100 ( & V_89 , V_3 -> V_2 , V_127 ,
V_160 , V_94 , V_150 ) ;
V_30 = F_105 ( V_19 , & V_89 ) ;
if ( V_30 != 0 )
goto V_314;
}
F_121 ( V_185 ) ;
V_30 = 0 ;
V_314:
return V_30 ;
}
static int F_274 ( struct V_184 * V_185 , int V_127 ,
T_4 V_94 )
{
F_75 ( V_83 ) ;
return F_273 ( V_185 , V_127 , V_94 , false ) ;
}
int F_275 ( struct V_365 * V_203 , int V_127 ,
T_4 V_94 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
V_30 = F_274 ( V_185 , V_127 , V_94 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
return V_30 ;
}
static int F_276 ( struct V_184 * V_185 , int V_127 )
{
F_75 ( V_84 ) ;
return F_273 ( V_185 , V_127 , V_155 ,
true ) ;
}
int F_277 ( struct V_365 * V_203 , int V_127 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
V_30 = F_276 ( V_185 , V_127 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
return V_30 ;
}
static T_4 * F_278 ( T_4 * V_384 , int V_198 , int V_127 , bool V_385 )
{
int V_233 ;
T_4 * V_191 ;
while ( true ) {
V_233 = ( V_127 >> ( 9 * V_198 ) ) & 0x1ff ;
V_191 = & V_384 [ V_233 ] ;
if ( V_198 == 0 )
break;
if ( ! ( * V_191 & V_271 ) ) {
if ( ! V_385 )
return NULL ;
V_384 = ( void * ) F_124 ( V_321 ) ;
if ( V_384 == NULL )
return NULL ;
* V_191 = F_92 ( V_384 ) | V_271 ;
}
V_384 = F_175 ( * V_191 & V_156 ) ;
V_198 -= 1 ;
}
return V_191 ;
}
static int F_279 ( struct V_184 * V_185 , int V_127 ,
unsigned long V_386 )
{
T_4 * V_191 ;
if ( V_185 -> V_192 != V_280 )
return - V_207 ;
V_191 = F_278 ( V_185 -> V_273 , V_185 -> V_272 , V_127 , true ) ;
if ( V_191 == NULL )
return - V_50 ;
* V_191 = ( V_386 & V_156 ) | V_271 ;
return F_276 ( V_185 , V_127 ) ;
}
static int F_280 ( struct V_184 * V_185 , int V_127 )
{
T_4 * V_191 ;
if ( V_185 -> V_192 != V_280 )
return - V_207 ;
V_191 = F_278 ( V_185 -> V_273 , V_185 -> V_272 , V_127 , false ) ;
if ( V_191 == NULL )
return 0 ;
* V_191 = 0 ;
return F_276 ( V_185 , V_127 ) ;
}
int F_281 ( struct V_365 * V_203 , int V_127 ,
unsigned long V_386 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
V_30 = F_279 ( V_185 , V_127 , V_386 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
return V_30 ;
}
int F_282 ( struct V_365 * V_203 , int V_127 )
{
struct V_184 * V_185 = V_203 -> V_278 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_185 -> V_116 , V_4 ) ;
V_30 = F_280 ( V_185 , V_127 ) ;
F_6 ( & V_185 -> V_116 , V_4 ) ;
return V_30 ;
}
int F_283 ( struct V_13 * V_14 , int V_127 ,
int V_164 , int V_129 )
{
struct V_1 * V_3 ;
struct V_55 * V_19 ;
struct V_88 V_89 ;
F_75 ( V_82 ) ;
V_3 = F_17 ( & V_14 -> V_12 ) ;
V_19 = V_39 [ V_3 -> V_2 ] ;
F_101 ( & V_89 , V_3 -> V_2 , V_127 , V_164 ,
V_129 , V_3 -> V_306 ) ;
return F_105 ( V_19 , & V_89 ) ;
}
struct V_365 * F_284 ( struct V_13 * V_14 )
{
struct V_184 * V_185 ;
V_185 = F_219 ( & V_14 -> V_12 ) ;
if ( F_35 ( V_185 ) )
return NULL ;
if ( ! ( V_185 -> V_4 & V_285 ) )
return NULL ;
return V_185 -> V_365 ;
}
void F_285 ( struct V_13 * V_14 , T_2 V_26 )
{
struct V_1 * V_3 ;
if ( ! F_286 () )
return;
V_3 = F_17 ( & V_14 -> V_12 ) ;
V_3 -> V_27 |= ( 1 << V_26 ) ;
}
int F_287 ( struct V_13 * V_14 ,
struct F_287 * V_387 )
{
int V_388 ;
int V_25 ;
if ( V_14 == NULL || V_387 == NULL )
return - V_207 ;
if ( ! F_286 () )
return - V_207 ;
memset ( V_387 , 0 , sizeof( * V_387 ) ) ;
V_25 = F_19 ( V_14 , V_21 ) ;
if ( V_25 )
V_387 -> V_4 |= V_389 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( V_25 )
V_387 -> V_4 |= V_390 ;
V_25 = F_19 ( V_14 , V_23 ) ;
if ( V_25 ) {
int V_391 ;
V_388 = 1 << ( 9 * ( V_383 + 1 ) ) ;
V_388 = F_288 ( V_388 , ( 1 << 20 ) ) ;
V_387 -> V_4 |= V_392 ;
V_387 -> V_388 = F_288 ( F_289 ( V_14 ) , V_388 ) ;
V_391 = F_290 ( V_14 ) ;
if ( V_391 & V_393 )
V_387 -> V_4 |= V_394 ;
if ( V_391 & V_395 )
V_387 -> V_4 |= V_396 ;
}
return 0 ;
}
static void F_291 ( T_1 V_2 , struct V_397 * V_398 )
{
T_4 V_399 ;
V_399 = V_58 [ V_2 ] . V_86 [ 2 ] ;
V_399 &= ~ V_400 ;
V_399 |= F_126 ( V_398 -> V_398 ) ;
V_399 |= V_401 ;
V_399 |= V_402 ;
V_399 |= V_403 ;
V_58 [ V_2 ] . V_86 [ 2 ] = V_399 ;
}
static struct V_397 * F_292 ( T_1 V_2 , bool V_404 )
{
struct V_397 * V_398 = NULL ;
struct V_55 * V_19 ;
unsigned long V_4 ;
T_1 V_31 ;
F_168 ( & V_262 , V_4 ) ;
V_19 = V_39 [ V_2 ] ;
if ( ! V_19 )
goto V_10;
V_398 = V_405 [ V_2 ] ;
if ( V_398 )
goto V_314;
V_31 = V_32 [ V_2 ] ;
V_398 = V_405 [ V_31 ] ;
if ( V_398 ) {
V_405 [ V_2 ] = V_398 ;
F_291 ( V_2 , V_398 ) ;
F_107 ( V_19 , V_2 ) ;
goto V_314;
}
V_398 = F_2 ( sizeof( * V_398 ) , V_321 ) ;
if ( ! V_398 )
goto V_314;
if ( V_404 )
V_398 -> V_406 = 32 ;
V_398 -> V_398 = F_293 ( V_407 , V_321 ) ;
if ( ! V_398 -> V_398 ) {
F_10 ( V_398 ) ;
V_398 = NULL ;
goto V_314;
}
memset ( V_398 -> V_398 , 0 , V_408 * sizeof( T_2 ) ) ;
if ( V_404 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < 32 ; ++ V_24 )
V_398 -> V_398 [ V_24 ] = V_409 ;
}
V_405 [ V_2 ] = V_398 ;
F_291 ( V_2 , V_398 ) ;
F_107 ( V_19 , V_2 ) ;
if ( V_2 != V_31 ) {
V_405 [ V_31 ] = V_398 ;
F_291 ( V_2 , V_398 ) ;
F_107 ( V_19 , V_31 ) ;
}
V_314:
F_106 ( V_19 ) ;
V_10:
F_170 ( & V_262 , V_4 ) ;
return V_398 ;
}
static int F_294 ( struct V_410 * V_411 , T_1 V_2 , int V_93 )
{
struct V_397 * V_398 ;
unsigned long V_4 ;
int V_233 , V_412 ;
V_398 = F_292 ( V_2 , false ) ;
if ( ! V_398 )
return - V_45 ;
F_4 ( & V_398 -> V_116 , V_4 ) ;
for ( V_412 = 0 , V_233 = V_398 -> V_406 ;
V_233 < V_408 ;
++ V_233 ) {
if ( V_398 -> V_398 [ V_233 ] == 0 )
V_412 += 1 ;
else
V_412 = 0 ;
if ( V_412 == V_93 ) {
struct V_413 * V_414 ;
for (; V_412 != 0 ; -- V_412 )
V_398 -> V_398 [ V_233 - V_412 + 1 ] = V_409 ;
V_233 -= V_93 - 1 ;
V_411 -> V_415 = 1 ;
V_414 = & V_411 -> V_413 ;
V_414 -> V_416 = V_2 ;
V_414 -> V_417 = V_233 ;
goto V_314;
}
}
V_233 = - V_418 ;
V_314:
F_6 ( & V_398 -> V_116 , V_4 ) ;
return V_233 ;
}
static int F_295 ( T_1 V_2 , int V_233 , union V_419 * V_419 )
{
struct V_397 * V_398 ;
unsigned long V_4 ;
V_398 = F_292 ( V_2 , false ) ;
if ( ! V_398 )
return - V_50 ;
F_4 ( & V_398 -> V_116 , V_4 ) ;
V_419 -> V_420 = V_398 -> V_398 [ V_233 ] ;
F_6 ( & V_398 -> V_116 , V_4 ) ;
return 0 ;
}
static int F_296 ( T_1 V_2 , int V_233 , union V_419 V_419 )
{
struct V_397 * V_398 ;
struct V_55 * V_19 ;
unsigned long V_4 ;
V_19 = V_39 [ V_2 ] ;
if ( V_19 == NULL )
return - V_207 ;
V_398 = F_292 ( V_2 , false ) ;
if ( ! V_398 )
return - V_50 ;
F_4 ( & V_398 -> V_116 , V_4 ) ;
V_398 -> V_398 [ V_233 ] = V_419 . V_420 ;
F_6 ( & V_398 -> V_116 , V_4 ) ;
F_111 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
return 0 ;
}
static void F_297 ( T_1 V_2 , int V_233 )
{
struct V_397 * V_398 ;
struct V_55 * V_19 ;
unsigned long V_4 ;
V_19 = V_39 [ V_2 ] ;
if ( V_19 == NULL )
return;
V_398 = F_292 ( V_2 , false ) ;
if ( ! V_398 )
return;
F_4 ( & V_398 -> V_116 , V_4 ) ;
V_398 -> V_398 [ V_233 ] = 0 ;
F_6 ( & V_398 -> V_116 , V_4 ) ;
F_111 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
}
static int F_298 ( int V_138 , struct V_421 * V_29 ,
unsigned int V_422 , int V_423 ,
struct V_424 * V_425 )
{
struct V_397 * V_398 ;
struct V_413 * V_414 ;
struct V_410 * V_411 ;
union V_419 V_419 ;
int V_426 ;
int V_233 ;
int V_2 ;
int V_30 ;
V_411 = F_299 ( V_138 ) ;
if ( ! V_411 )
return - V_207 ;
V_414 = & V_411 -> V_413 ;
V_426 = F_300 ( V_425 -> V_404 ) ;
V_2 = F_301 ( V_426 ) ;
if ( V_2 < 0 )
return V_2 ;
V_398 = F_292 ( V_2 , true ) ;
if ( V_398 == NULL )
return - V_50 ;
V_233 = V_425 -> V_427 ;
V_411 -> V_415 = 1 ;
V_414 -> V_416 = V_2 ;
V_414 -> V_417 = V_233 ;
V_419 . V_420 = 0 ;
V_419 . V_428 . V_423 = V_423 ;
V_419 . V_428 . V_429 = V_430 -> V_431 ;
V_419 . V_428 . V_422 = V_422 ;
V_419 . V_428 . V_432 = V_430 -> V_433 ;
V_419 . V_428 . V_434 = 1 ;
V_30 = F_296 ( V_2 , V_233 , V_419 ) ;
if ( V_30 )
return V_30 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_423 = V_233 ;
V_29 -> V_352 = 0 ;
V_29 -> V_435 = V_425 -> V_435 ;
V_29 -> V_436 = V_425 -> V_436 ;
if ( V_425 -> V_435 )
V_29 -> V_352 = 1 ;
return 0 ;
}
static int F_302 ( struct V_437 * V_86 , const struct V_438 * V_352 ,
bool V_439 )
{
struct V_413 * V_414 ;
unsigned int V_440 , V_138 ;
struct V_410 * V_411 ;
union V_419 V_419 ;
int V_441 ;
if ( ! F_303 ( V_442 ) )
return - 1 ;
V_411 = V_86 -> V_443 ;
V_138 = V_86 -> V_138 ;
V_414 = & V_411 -> V_413 ;
if ( ! F_304 ( V_352 , V_444 ) )
return - V_207 ;
if ( F_295 ( V_414 -> V_416 , V_414 -> V_417 , & V_419 ) )
return - V_208 ;
if ( F_305 ( V_138 , V_411 , V_352 ) )
return - V_208 ;
V_441 = V_430 -> V_445 ( V_411 -> V_185 , V_352 , & V_440 ) ;
if ( V_441 ) {
if ( F_305 ( V_138 , V_411 , V_86 -> V_446 ) )
F_49 ( L_28 , V_138 ) ;
return V_441 ;
}
V_419 . V_428 . V_423 = V_411 -> V_423 ;
V_419 . V_428 . V_422 = V_440 ;
F_296 ( V_414 -> V_416 , V_414 -> V_417 , V_419 ) ;
if ( V_411 -> V_447 )
F_306 ( V_411 ) ;
F_307 ( V_86 -> V_446 , V_352 ) ;
return 0 ;
}
static int F_308 ( int V_138 )
{
struct V_413 * V_414 ;
struct V_410 * V_411 ;
V_411 = F_299 ( V_138 ) ;
if ( ! V_411 )
return - V_207 ;
V_414 = & V_411 -> V_413 ;
F_297 ( V_414 -> V_416 , V_414 -> V_417 ) ;
return 0 ;
}
static void F_309 ( struct V_13 * V_14 ,
unsigned int V_138 , unsigned int V_440 ,
struct V_448 * V_449 , T_6 V_450 )
{
struct V_413 * V_414 ;
struct V_410 * V_411 ;
union V_419 V_419 ;
V_411 = F_299 ( V_138 ) ;
if ( ! V_411 )
return;
V_414 = & V_411 -> V_413 ;
V_419 . V_420 = 0 ;
V_419 . V_428 . V_423 = V_411 -> V_423 ;
V_419 . V_428 . V_429 = V_430 -> V_431 ;
V_419 . V_428 . V_422 = V_440 ;
V_419 . V_428 . V_432 = V_430 -> V_433 ;
V_419 . V_428 . V_434 = 1 ;
F_296 ( V_414 -> V_416 , V_414 -> V_417 , V_419 ) ;
V_449 -> V_451 = V_452 ;
V_449 -> V_453 = V_244 ;
V_449 -> V_86 = V_414 -> V_417 ;
}
static int F_310 ( struct V_13 * V_14 , int V_138 , int V_454 )
{
struct V_410 * V_411 ;
int V_233 ;
T_1 V_2 ;
if ( ! V_14 )
return - V_207 ;
V_411 = F_299 ( V_138 ) ;
if ( ! V_411 )
return - V_207 ;
V_2 = F_14 ( & V_14 -> V_12 ) ;
V_233 = F_294 ( V_411 , V_2 , V_454 ) ;
return V_233 < 0 ? V_408 : V_233 ;
}
static int F_311 ( struct V_13 * V_14 , unsigned int V_138 ,
int V_233 , int V_240 )
{
struct V_413 * V_414 ;
struct V_410 * V_411 ;
T_1 V_2 ;
if ( ! V_14 )
return - V_207 ;
V_411 = F_299 ( V_138 ) ;
if ( ! V_411 )
return - V_207 ;
if ( V_233 >= V_408 )
return 0 ;
V_2 = F_14 ( & V_14 -> V_12 ) ;
V_414 = & V_411 -> V_413 ;
V_411 -> V_415 = 1 ;
V_414 -> V_416 = V_2 ;
V_414 -> V_417 = V_233 + V_240 ;
return 0 ;
}
static int F_312 ( unsigned int V_138 , unsigned int V_186 )
{
struct V_413 * V_414 ;
struct V_410 * V_411 ;
int V_233 , V_2 ;
V_411 = F_299 ( V_138 ) ;
if ( ! V_411 )
return - V_207 ;
V_414 = & V_411 -> V_413 ;
V_2 = F_313 ( V_186 ) ;
if ( V_2 < 0 )
return V_2 ;
V_233 = F_294 ( V_411 , V_2 , 1 ) ;
if ( V_233 < 0 )
return V_233 ;
V_411 -> V_415 = 1 ;
V_414 -> V_416 = V_2 ;
V_414 -> V_417 = V_233 ;
return 0 ;
}
