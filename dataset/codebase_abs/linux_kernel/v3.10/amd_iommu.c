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
static struct V_40 * F_24 ( struct V_40 * V_15 )
{
while ( ! V_15 -> V_41 ) {
if ( ! F_25 ( V_15 ) )
V_15 = V_15 -> V_42 ;
else
return F_26 ( - V_43 ) ;
}
return V_15 ;
}
static struct V_13 * F_27 ( struct V_13 * V_14 )
{
struct V_13 * V_44 = V_14 ;
F_28 ( & V_44 , F_29 ( V_44 ) ) ;
if ( V_44 -> V_45 &&
! F_30 ( V_44 , V_46 ) )
F_28 ( & V_44 ,
F_31 ( V_44 -> V_15 ,
F_32 ( F_33 ( V_44 -> V_17 ) ,
0 ) ) ) ;
while ( ! F_25 ( V_44 -> V_15 ) ) {
struct V_40 * V_15 = F_24 ( V_44 -> V_15 ) ;
if ( F_34 ( V_15 ) )
break;
if ( F_35 ( V_15 -> V_41 , NULL , V_46 ) )
break;
F_28 ( & V_44 , F_36 ( V_15 -> V_41 ) ) ;
}
return V_44 ;
}
static int F_37 ( struct V_13 * V_14 , struct V_11 * V_12 )
{
struct V_47 * V_9 = F_38 ( & V_14 -> V_12 ) ;
int V_30 ;
if ( ! V_9 ) {
V_9 = F_39 () ;
if ( F_34 ( V_9 ) )
return F_40 ( V_9 ) ;
F_41 ( & V_14 -> V_12 != V_12 ) ;
}
V_30 = F_42 ( V_9 , V_12 ) ;
F_9 ( V_9 ) ;
return V_30 ;
}
static int F_43 ( struct V_1 * V_3 ,
struct V_11 * V_12 )
{
if ( ! V_3 -> V_9 ) {
struct V_47 * V_9 = F_39 () ;
if ( F_34 ( V_9 ) )
return F_40 ( V_9 ) ;
V_3 -> V_9 = V_9 ;
}
return F_42 ( V_3 -> V_9 , V_12 ) ;
}
static int F_44 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_47 * V_9 ;
struct V_13 * V_44 ;
int V_30 ;
V_9 = F_38 ( V_12 ) ;
if ( V_9 ) {
F_9 ( V_9 ) ;
return 0 ;
}
V_3 = F_13 ( F_14 ( V_12 ) ) ;
if ( ! V_3 )
return - V_48 ;
if ( V_3 -> V_49 ) {
T_1 V_31 ;
struct V_40 * V_15 ;
if ( V_3 -> V_49 -> V_9 )
goto V_50;
V_31 = V_32 [ V_3 -> V_2 ] ;
V_44 = F_45 ( V_31 >> 8 , V_31 & 0xff ) ;
if ( V_44 ) {
V_44 = F_27 ( V_44 ) ;
goto V_51;
}
V_15 = F_46 ( 0 , V_31 >> 8 ) ;
if ( ! V_15 )
goto V_50;
V_15 = F_24 ( V_15 ) ;
if ( F_34 ( V_15 ) || ! V_15 -> V_41 )
goto V_50;
V_44 = F_27 ( F_36 ( V_15 -> V_41 ) ) ;
if ( V_44 != V_15 -> V_41 || ( V_44 -> V_45 &&
! F_30 ( V_44 , V_46 ) ) )
goto V_51;
F_47 ( V_44 ) ;
goto V_50;
}
V_44 = F_27 ( F_36 ( F_15 ( V_12 ) ) ) ;
V_51:
V_30 = F_37 ( V_44 , V_12 ) ;
F_47 ( V_44 ) ;
return V_30 ;
V_50:
return F_43 ( V_3 -> V_49 , V_12 ) ;
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
return - V_48 ;
V_31 = V_32 [ V_3 -> V_2 ] ;
if ( V_31 != V_3 -> V_2 ) {
struct V_1 * V_49 ;
V_49 = F_13 ( V_31 ) ;
if ( V_49 == NULL ) {
F_49 ( L_1 ,
F_50 ( V_12 ) ) ;
F_7 ( V_3 ) ;
return - V_52 ;
}
V_3 -> V_49 = V_49 ;
}
V_30 = F_44 ( V_12 ) ;
if ( V_30 )
return V_30 ;
if ( F_18 ( V_14 ) ) {
struct V_53 * V_19 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_3 -> V_54 = V_19 -> V_55 ;
}
V_12 -> V_18 . V_19 = V_3 ;
return 0 ;
}
static void F_51 ( struct V_11 * V_12 )
{
T_1 V_2 , V_31 ;
V_2 = F_14 ( V_12 ) ;
V_31 = V_32 [ V_2 ] ;
memset ( & V_56 [ V_2 ] , 0 , sizeof( struct V_57 ) ) ;
memset ( & V_56 [ V_31 ] , 0 , sizeof( struct V_57 ) ) ;
V_39 [ V_2 ] = NULL ;
V_39 [ V_31 ] = NULL ;
}
static void F_52 ( struct V_11 * V_12 )
{
F_53 ( V_12 ) ;
}
void T_3 F_54 ( void )
{
struct V_1 * V_3 , * V_58 ;
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
if ( V_30 == - V_52 )
F_51 ( & V_14 -> V_12 ) ;
else if ( V_30 )
goto V_59;
}
return 0 ;
V_59:
F_54 () ;
return V_30 ;
}
static void F_58 ( struct V_60 * V_61 )
{
if ( V_62 == NULL )
return;
V_61 -> V_63 = F_59 ( V_61 -> V_64 , 0444 , V_62 ,
& V_61 -> V_65 ) ;
}
static void F_60 ( void )
{
V_62 = F_61 ( L_2 , NULL ) ;
if ( V_62 == NULL )
return;
V_66 = F_62 ( L_3 , 0444 , V_62 ,
& V_67 ) ;
F_58 ( & V_68 ) ;
F_58 ( & V_69 ) ;
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
}
static void F_63 ( T_1 V_2 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 4 ; ++ V_24 )
F_49 ( L_4 , V_24 ,
V_56 [ V_2 ] . V_84 [ V_24 ] ) ;
}
static void F_64 ( unsigned long V_85 )
{
struct V_86 * V_87 = F_65 ( V_85 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 4 ; ++ V_24 )
F_49 ( L_5 , V_24 , V_87 -> V_84 [ V_24 ] ) ;
}
static void F_66 ( struct V_53 * V_19 , void * V_88 )
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
F_49 ( L_6 ) ;
return;
}
F_67 ( 1 ) ;
goto V_93;
}
F_68 ( V_103 L_7 ) ;
switch ( type ) {
case V_104 :
F_68 ( L_8
L_9 ,
F_69 ( V_2 ) , F_33 ( V_2 ) , F_70 ( V_2 ) ,
V_92 , V_4 ) ;
F_63 ( V_2 ) ;
break;
case V_105 :
F_68 ( L_10
L_11 ,
F_69 ( V_2 ) , F_33 ( V_2 ) , F_70 ( V_2 ) ,
V_89 , V_92 , V_4 ) ;
break;
case V_106 :
F_68 ( L_12
L_9 ,
F_69 ( V_2 ) , F_33 ( V_2 ) , F_70 ( V_2 ) ,
V_92 , V_4 ) ;
break;
case V_107 :
F_68 ( L_13
L_11 ,
F_69 ( V_2 ) , F_33 ( V_2 ) , F_70 ( V_2 ) ,
V_89 , V_92 , V_4 ) ;
break;
case V_108 :
F_68 ( L_14 , V_92 ) ;
F_64 ( V_92 ) ;
break;
case V_109 :
F_68 ( L_15
L_16 , V_92 , V_4 ) ;
break;
case V_110 :
F_68 ( L_17
L_18 ,
F_69 ( V_2 ) , F_33 ( V_2 ) , F_70 ( V_2 ) ,
V_92 ) ;
break;
case V_111 :
F_68 ( L_19
L_9 ,
F_69 ( V_2 ) , F_33 ( V_2 ) , F_70 ( V_2 ) ,
V_92 , V_4 ) ;
break;
default:
F_68 ( V_103 L_20 , type ) ;
}
memset ( V_88 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_71 ( struct V_53 * V_19 )
{
T_2 V_112 , V_113 ;
V_112 = F_72 ( V_19 -> V_114 + V_115 ) ;
V_113 = F_72 ( V_19 -> V_114 + V_116 ) ;
while ( V_112 != V_113 ) {
F_66 ( V_19 , V_19 -> V_117 + V_112 ) ;
V_112 = ( V_112 + V_118 ) % V_19 -> V_119 ;
}
F_73 ( V_112 , V_19 -> V_114 + V_115 ) ;
}
static void F_74 ( struct V_53 * V_19 , T_4 * V_120 )
{
struct V_121 V_122 ;
F_75 ( V_83 ) ;
if ( F_76 ( V_120 [ 0 ] ) != V_123 ) {
F_77 ( L_21 ) ;
return;
}
V_122 . V_92 = V_120 [ 1 ] ;
V_122 . V_124 = F_78 ( V_120 [ 0 ] ) ;
V_122 . V_125 = F_79 ( V_120 [ 0 ] ) ;
V_122 . V_126 = F_80 ( V_120 [ 0 ] ) ;
V_122 . V_4 = F_81 ( V_120 [ 0 ] ) ;
F_82 ( & V_127 , 0 , & V_122 ) ;
}
static void F_83 ( struct V_53 * V_19 )
{
T_2 V_112 , V_113 ;
if ( V_19 -> V_128 == NULL )
return;
V_112 = F_72 ( V_19 -> V_114 + V_129 ) ;
V_113 = F_72 ( V_19 -> V_114 + V_130 ) ;
while ( V_112 != V_113 ) {
volatile T_4 * V_120 ;
T_4 V_29 [ 2 ] ;
int V_24 ;
V_120 = ( T_4 * ) ( V_19 -> V_128 + V_112 ) ;
for ( V_24 = 0 ; V_24 < V_102 ; ++ V_24 ) {
if ( F_76 ( V_120 [ 0 ] ) != 0 )
break;
F_67 ( 1 ) ;
}
V_29 [ 0 ] = V_120 [ 0 ] ;
V_29 [ 1 ] = V_120 [ 1 ] ;
V_120 [ 0 ] = V_120 [ 1 ] = 0UL ;
V_112 = ( V_112 + V_131 ) % V_132 ;
F_73 ( V_112 , V_19 -> V_114 + V_129 ) ;
F_74 ( V_19 , V_29 ) ;
V_112 = F_72 ( V_19 -> V_114 + V_129 ) ;
V_113 = F_72 ( V_19 -> V_114 + V_130 ) ;
}
}
T_5 F_84 ( int V_133 , void * V_84 )
{
struct V_53 * V_19 = (struct V_53 * ) V_84 ;
T_2 V_134 = F_72 ( V_19 -> V_114 + V_135 ) ;
while ( V_134 & ( V_136 | V_137 ) ) {
F_73 ( ( V_136 | V_137 ) ,
V_19 -> V_114 + V_135 ) ;
if ( V_134 & V_136 ) {
F_85 ( L_22 ) ;
F_71 ( V_19 ) ;
}
if ( V_134 & V_137 ) {
F_85 ( L_23 ) ;
F_83 ( V_19 ) ;
}
V_134 = F_72 ( V_19 -> V_114 + V_135 ) ;
}
return V_138 ;
}
T_5 F_86 ( int V_133 , void * V_84 )
{
return V_139 ;
}
static int F_87 ( volatile T_4 * V_140 )
{
int V_24 = 0 ;
while ( * V_140 == 0 && V_24 < V_102 ) {
F_67 ( 1 ) ;
V_24 += 1 ;
}
if ( V_24 == V_102 ) {
F_88 ( L_24 ) ;
return - V_141 ;
}
return 0 ;
}
static void F_89 ( struct V_53 * V_19 ,
struct V_86 * V_87 ,
T_2 V_113 )
{
T_6 * V_142 ;
V_142 = V_19 -> V_143 + V_113 ;
V_113 = ( V_113 + sizeof( * V_87 ) ) % V_19 -> V_144 ;
memcpy ( V_142 , V_87 , sizeof( * V_87 ) ) ;
F_73 ( V_113 , V_19 -> V_114 + V_145 ) ;
}
static void F_90 ( struct V_86 * V_87 , T_4 V_92 )
{
F_41 ( V_92 & 0x7ULL ) ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = F_91 ( F_92 ( V_92 ) ) | V_146 ;
V_87 -> V_84 [ 1 ] = F_93 ( F_92 ( V_92 ) ) ;
V_87 -> V_84 [ 2 ] = 1 ;
F_94 ( V_87 , V_147 ) ;
}
static void F_95 ( struct V_86 * V_87 , T_1 V_2 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
F_94 ( V_87 , V_148 ) ;
}
static void F_96 ( struct V_86 * V_87 , T_4 V_92 ,
T_7 V_149 , T_1 V_89 , int V_150 )
{
T_4 V_151 ;
int V_152 ;
V_151 = F_97 ( V_92 , V_149 , V_153 ) ;
V_152 = 0 ;
if ( V_151 > 1 ) {
V_92 = V_154 ;
V_152 = 1 ;
}
V_92 &= V_155 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 1 ] |= V_89 ;
V_87 -> V_84 [ 2 ] = F_91 ( V_92 ) ;
V_87 -> V_84 [ 3 ] = F_93 ( V_92 ) ;
F_94 ( V_87 , V_156 ) ;
if ( V_152 )
V_87 -> V_84 [ 2 ] |= V_157 ;
if ( V_150 )
V_87 -> V_84 [ 2 ] |= V_158 ;
}
static void F_98 ( struct V_86 * V_87 , T_1 V_2 , int V_159 ,
T_4 V_92 , T_7 V_149 )
{
T_4 V_151 ;
int V_152 ;
V_151 = F_97 ( V_92 , V_149 , V_153 ) ;
V_152 = 0 ;
if ( V_151 > 1 ) {
V_92 = V_154 ;
V_152 = 1 ;
}
V_92 &= V_155 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
V_87 -> V_84 [ 0 ] |= ( V_159 & 0xff ) << 24 ;
V_87 -> V_84 [ 1 ] = V_2 ;
V_87 -> V_84 [ 2 ] = F_91 ( V_92 ) ;
V_87 -> V_84 [ 3 ] = F_93 ( V_92 ) ;
F_94 ( V_87 , V_160 ) ;
if ( V_152 )
V_87 -> V_84 [ 2 ] |= V_157 ;
}
static void F_99 ( struct V_86 * V_87 , T_1 V_89 , int V_124 ,
T_4 V_92 , bool V_149 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_92 &= ~ ( 0xfffULL ) ;
V_87 -> V_84 [ 0 ] = V_124 & V_161 ;
V_87 -> V_84 [ 1 ] = V_89 ;
V_87 -> V_84 [ 2 ] = F_91 ( V_92 ) ;
V_87 -> V_84 [ 3 ] = F_93 ( V_92 ) ;
V_87 -> V_84 [ 2 ] |= V_158 ;
V_87 -> V_84 [ 2 ] |= V_162 ;
if ( V_149 )
V_87 -> V_84 [ 2 ] |= V_157 ;
F_94 ( V_87 , V_156 ) ;
}
static void F_100 ( struct V_86 * V_87 , T_1 V_2 , int V_124 ,
int V_159 , T_4 V_92 , bool V_149 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_92 &= ~ ( 0xfffULL ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
V_87 -> V_84 [ 0 ] |= ( V_124 & 0xff ) << 16 ;
V_87 -> V_84 [ 0 ] |= ( V_159 & 0xff ) << 24 ;
V_87 -> V_84 [ 1 ] = V_2 ;
V_87 -> V_84 [ 1 ] |= ( ( V_124 >> 8 ) & 0xfff ) << 16 ;
V_87 -> V_84 [ 2 ] = F_91 ( V_92 ) ;
V_87 -> V_84 [ 2 ] |= V_162 ;
V_87 -> V_84 [ 3 ] = F_93 ( V_92 ) ;
if ( V_149 )
V_87 -> V_84 [ 2 ] |= V_157 ;
F_94 ( V_87 , V_160 ) ;
}
static void F_101 ( struct V_86 * V_87 , T_1 V_2 , int V_124 ,
int V_134 , int V_126 , bool V_163 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
if ( V_163 ) {
V_87 -> V_84 [ 1 ] = V_124 & V_161 ;
V_87 -> V_84 [ 2 ] = V_162 ;
}
V_87 -> V_84 [ 3 ] = V_126 & 0x1ff ;
V_87 -> V_84 [ 3 ] |= ( V_134 & V_164 ) << V_165 ;
F_94 ( V_87 , V_166 ) ;
}
static void F_102 ( struct V_86 * V_87 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
F_94 ( V_87 , V_167 ) ;
}
static void F_103 ( struct V_86 * V_87 , T_1 V_2 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_84 [ 0 ] = V_2 ;
F_94 ( V_87 , V_168 ) ;
}
static int F_104 ( struct V_53 * V_19 ,
struct V_86 * V_87 ,
bool V_169 )
{
T_2 V_170 , V_113 , V_112 , V_171 ;
unsigned long V_4 ;
F_41 ( V_19 -> V_144 & V_172 ) ;
V_173:
F_4 ( & V_19 -> V_174 , V_4 ) ;
V_112 = F_72 ( V_19 -> V_114 + V_175 ) ;
V_113 = F_72 ( V_19 -> V_114 + V_145 ) ;
V_171 = ( V_113 + sizeof( * V_87 ) ) % V_19 -> V_144 ;
V_170 = ( V_112 - V_171 ) % V_19 -> V_144 ;
if ( V_170 <= 2 ) {
struct V_86 V_176 ;
volatile T_4 V_140 = 0 ;
int V_30 ;
F_90 ( & V_176 , ( T_4 ) & V_140 ) ;
F_89 ( V_19 , & V_176 , V_113 ) ;
F_6 ( & V_19 -> V_174 , V_4 ) ;
if ( ( V_30 = F_87 ( & V_140 ) ) != 0 )
return V_30 ;
goto V_173;
}
F_89 ( V_19 , V_87 , V_113 ) ;
V_19 -> V_177 = V_169 ;
F_6 ( & V_19 -> V_174 , V_4 ) ;
return 0 ;
}
static int F_105 ( struct V_53 * V_19 , struct V_86 * V_87 )
{
return F_104 ( V_19 , V_87 , true ) ;
}
static int F_106 ( struct V_53 * V_19 )
{
struct V_86 V_87 ;
volatile T_4 V_140 = 0 ;
int V_30 ;
if ( ! V_19 -> V_177 )
return 0 ;
F_90 ( & V_87 , ( T_4 ) & V_140 ) ;
V_30 = F_104 ( V_19 , & V_87 , false ) ;
if ( V_30 )
return V_30 ;
return F_87 ( & V_140 ) ;
}
static int F_107 ( struct V_53 * V_19 , T_1 V_2 )
{
struct V_86 V_87 ;
F_95 ( & V_87 , V_2 ) ;
return F_105 ( V_19 , & V_87 ) ;
}
static void F_108 ( struct V_53 * V_19 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= 0xffff ; ++ V_2 )
F_107 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
}
static void F_109 ( struct V_53 * V_19 )
{
T_2 V_178 ;
for ( V_178 = 0 ; V_178 <= 0xffff ; ++ V_178 ) {
struct V_86 V_87 ;
F_96 ( & V_87 , 0 , V_154 ,
V_178 , 1 ) ;
F_105 ( V_19 , & V_87 ) ;
}
F_106 ( V_19 ) ;
}
static void F_110 ( struct V_53 * V_19 )
{
struct V_86 V_87 ;
F_102 ( & V_87 ) ;
F_105 ( V_19 , & V_87 ) ;
F_106 ( V_19 ) ;
}
static void F_111 ( struct V_53 * V_19 , T_1 V_2 )
{
struct V_86 V_87 ;
F_103 ( & V_87 , V_2 ) ;
F_105 ( V_19 , & V_87 ) ;
}
static void F_112 ( struct V_53 * V_19 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= V_179 ; V_2 ++ )
F_111 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
}
void F_113 ( struct V_53 * V_19 )
{
if ( F_114 ( V_19 , V_180 ) ) {
F_110 ( V_19 ) ;
} else {
F_108 ( V_19 ) ;
F_112 ( V_19 ) ;
F_109 ( V_19 ) ;
}
}
static int F_115 ( struct V_1 * V_3 ,
T_4 V_92 , T_7 V_149 )
{
struct V_53 * V_19 ;
struct V_86 V_87 ;
int V_159 ;
V_159 = V_3 -> V_181 . V_159 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
F_98 ( & V_87 , V_3 -> V_2 , V_159 , V_92 , V_149 ) ;
return F_105 ( V_19 , & V_87 ) ;
}
static int F_116 ( struct V_1 * V_3 )
{
struct V_53 * V_19 ;
int V_30 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_30 = F_107 ( V_19 , V_3 -> V_2 ) ;
if ( V_30 )
return V_30 ;
if ( V_3 -> V_181 . V_182 )
V_30 = F_115 ( V_3 , 0 , ~ 0UL ) ;
return V_30 ;
}
static void F_117 ( struct V_183 * V_184 ,
T_4 V_92 , T_7 V_149 , int V_150 )
{
struct V_1 * V_3 ;
struct V_86 V_87 ;
int V_30 = 0 , V_24 ;
F_96 ( & V_87 , V_92 , V_149 , V_184 -> V_185 , V_150 ) ;
for ( V_24 = 0 ; V_24 < V_186 ; ++ V_24 ) {
if ( ! V_184 -> V_187 [ V_24 ] )
continue;
V_30 |= F_105 ( V_188 [ V_24 ] , & V_87 ) ;
}
F_12 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_181 . V_182 )
continue;
V_30 |= F_115 ( V_3 , V_92 , V_149 ) ;
}
F_41 ( V_30 ) ;
}
static void F_118 ( struct V_183 * V_184 ,
T_4 V_92 , T_7 V_149 )
{
F_117 ( V_184 , V_92 , V_149 , 0 ) ;
}
static void F_119 ( struct V_183 * V_184 )
{
F_117 ( V_184 , 0 , V_154 , 0 ) ;
}
static void F_120 ( struct V_183 * V_184 )
{
F_117 ( V_184 , 0 , V_154 , 1 ) ;
}
static void F_121 ( struct V_183 * V_184 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_186 ; ++ V_24 ) {
if ( ! V_184 -> V_187 [ V_24 ] )
continue;
F_106 ( V_188 [ V_24 ] ) ;
}
}
static void F_122 ( struct V_183 * V_184 )
{
struct V_1 * V_3 ;
F_12 (dev_data, &domain->dev_list, list)
F_116 ( V_3 ) ;
}
static bool F_123 ( struct V_183 * V_184 ,
T_8 V_189 )
{
T_4 * V_190 ;
if ( V_184 -> V_191 == V_192 )
return false ;
V_190 = ( void * ) F_124 ( V_189 ) ;
if ( ! V_190 )
return false ;
* V_190 = F_125 ( V_184 -> V_191 ,
F_126 ( V_184 -> V_193 ) ) ;
V_184 -> V_193 = V_190 ;
V_184 -> V_191 += 1 ;
V_184 -> V_194 = true ;
return true ;
}
static T_4 * F_127 ( struct V_183 * V_184 ,
unsigned long V_92 ,
unsigned long V_195 ,
T_4 * * V_196 ,
T_8 V_189 )
{
int V_197 , V_198 ;
T_4 * V_190 , * V_199 ;
F_128 ( ! F_129 ( V_195 ) ) ;
while ( V_92 > F_130 ( V_184 -> V_191 ) )
F_123 ( V_184 , V_189 ) ;
V_197 = V_184 -> V_191 - 1 ;
V_190 = & V_184 -> V_193 [ F_131 ( V_197 , V_92 ) ] ;
V_92 = F_132 ( V_92 , V_195 ) ;
V_198 = F_133 ( V_195 ) ;
while ( V_197 > V_198 ) {
if ( ! F_134 ( * V_190 ) ) {
V_199 = ( T_4 * ) F_124 ( V_189 ) ;
if ( ! V_199 )
return NULL ;
* V_190 = F_125 ( V_197 , F_126 ( V_199 ) ) ;
}
if ( F_135 ( * V_190 ) != V_197 )
return NULL ;
V_197 -= 1 ;
V_190 = F_136 ( * V_190 ) ;
if ( V_196 && V_197 == V_198 )
* V_196 = V_190 ;
V_190 = & V_190 [ F_131 ( V_197 , V_92 ) ] ;
}
return V_190 ;
}
static T_4 * F_137 ( struct V_183 * V_184 , unsigned long V_92 )
{
int V_197 ;
T_4 * V_190 ;
if ( V_92 > F_130 ( V_184 -> V_191 ) )
return NULL ;
V_197 = V_184 -> V_191 - 1 ;
V_190 = & V_184 -> V_193 [ F_131 ( V_197 , V_92 ) ] ;
while ( V_197 > 0 ) {
if ( ! F_134 ( * V_190 ) )
return NULL ;
if ( F_135 ( * V_190 ) == 0x07 ) {
unsigned long V_200 , V_201 ;
V_200 = F_138 ( * V_190 ) ;
V_200 = ~ ( ( F_139 ( V_200 ) << 3 ) - 1 ) ;
V_201 = ( ( unsigned long ) V_190 ) & V_200 ;
return ( T_4 * ) V_201 ;
}
if ( F_135 ( * V_190 ) != V_197 )
return NULL ;
V_197 -= 1 ;
V_190 = F_136 ( * V_190 ) ;
V_190 = & V_190 [ F_131 ( V_197 , V_92 ) ] ;
}
return V_190 ;
}
static int F_140 ( struct V_183 * V_202 ,
unsigned long V_203 ,
unsigned long V_85 ,
int V_204 ,
unsigned long V_195 )
{
T_4 V_201 , * V_190 ;
int V_24 , V_91 ;
if ( ! ( V_204 & V_205 ) )
return - V_206 ;
V_203 = F_141 ( V_203 ) ;
V_85 = F_141 ( V_85 ) ;
V_91 = F_139 ( V_195 ) ;
V_190 = F_127 ( V_202 , V_203 , V_195 , NULL , V_5 ) ;
for ( V_24 = 0 ; V_24 < V_91 ; ++ V_24 )
if ( F_134 ( V_190 [ V_24 ] ) )
return - V_207 ;
if ( V_195 > V_153 ) {
V_201 = F_142 ( V_85 , V_195 ) ;
V_201 |= F_143 ( 7 ) | V_208 | V_209 ;
} else
V_201 = V_85 | V_208 | V_209 ;
if ( V_204 & V_210 )
V_201 |= V_211 ;
if ( V_204 & V_212 )
V_201 |= V_213 ;
for ( V_24 = 0 ; V_24 < V_91 ; ++ V_24 )
V_190 [ V_24 ] = V_201 ;
F_144 ( V_202 ) ;
return 0 ;
}
static unsigned long F_145 ( struct V_183 * V_202 ,
unsigned long V_203 ,
unsigned long V_195 )
{
unsigned long long V_214 , V_215 ;
T_4 * V_190 ;
F_128 ( ! F_129 ( V_195 ) ) ;
V_215 = 0 ;
while ( V_215 < V_195 ) {
V_190 = F_137 ( V_202 , V_203 ) ;
if ( ! V_190 ) {
V_214 = V_153 ;
} else if ( F_135 ( * V_190 ) == 0 ) {
V_214 = V_153 ;
* V_190 = 0ULL ;
} else {
int V_91 , V_24 ;
V_214 = F_138 ( * V_190 ) ;
V_91 = F_139 ( V_214 ) ;
for ( V_24 = 0 ; V_24 < V_91 ; V_24 ++ )
V_190 [ V_24 ] = 0ULL ;
}
V_203 = ( V_203 & ~ ( V_214 - 1 ) ) + V_214 ;
V_215 += V_214 ;
}
F_128 ( ! F_129 ( V_215 ) ) ;
return V_215 ;
}
static int F_146 ( struct V_53 * V_19 ,
struct V_216 * V_29 )
{
T_1 V_217 , V_24 ;
for ( V_24 = V_29 -> V_218 ; V_24 <= V_29 -> V_219 ; ++ V_24 ) {
V_217 = V_32 [ V_24 ] ;
if ( V_39 [ V_217 ] == V_19 )
return 1 ;
}
return 0 ;
}
static int F_147 ( struct V_28 * V_220 ,
struct V_216 * V_221 )
{
T_4 V_222 ;
int V_30 ;
for ( V_222 = V_221 -> V_223 ; V_222 < V_221 -> V_224 ;
V_222 += V_153 ) {
V_30 = F_140 ( & V_220 -> V_184 , V_222 , V_222 , V_221 -> V_204 ,
V_153 ) ;
if ( V_30 )
return V_30 ;
if ( V_222 < V_220 -> V_225 )
F_148 ( V_222 >> V_226 ,
V_220 -> V_227 [ 0 ] -> V_228 ) ;
}
return 0 ;
}
static int F_149 ( struct V_53 * V_19 )
{
struct V_216 * V_29 ;
int V_30 ;
F_12 (entry, &amd_iommu_unity_map, list) {
if ( ! F_146 ( V_19 , V_29 ) )
continue;
V_30 = F_147 ( V_19 -> V_229 , V_29 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static int F_150 ( struct V_28 * V_220 ,
T_1 V_2 )
{
struct V_216 * V_221 ;
int V_30 ;
F_12 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_221 -> V_218 && V_2 <= V_221 -> V_219 ) )
continue;
V_30 = F_147 ( V_220 , V_221 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static void F_151 ( struct V_28 * V_202 ,
unsigned long V_230 ,
unsigned int V_151 )
{
unsigned int V_24 , V_231 = V_202 -> V_225 >> V_226 ;
if ( V_230 + V_151 > V_231 )
V_151 = V_231 - V_230 ;
for ( V_24 = V_230 ; V_24 < V_230 + V_151 ; ++ V_24 ) {
int V_232 = V_24 / V_233 ;
int V_199 = V_24 % V_233 ;
F_148 ( V_199 , V_202 -> V_227 [ V_232 ] -> V_228 ) ;
}
}
static int F_152 ( struct V_28 * V_220 ,
bool V_234 , T_8 V_189 )
{
int V_232 = V_220 -> V_225 >> V_235 ;
struct V_53 * V_19 ;
unsigned long V_24 , V_236 ;
#ifdef F_153
V_234 = false ;
#endif
if ( V_232 >= V_237 )
return - V_48 ;
V_220 -> V_227 [ V_232 ] = F_2 ( sizeof( struct V_238 ) , V_189 ) ;
if ( ! V_220 -> V_227 [ V_232 ] )
return - V_48 ;
V_220 -> V_227 [ V_232 ] -> V_228 = ( void * ) F_124 ( V_189 ) ;
if ( ! V_220 -> V_227 [ V_232 ] -> V_228 )
goto V_59;
V_220 -> V_227 [ V_232 ] -> V_239 = V_220 -> V_225 ;
if ( V_234 ) {
unsigned long V_92 = V_220 -> V_225 ;
int V_24 , V_240 = V_233 / 512 ;
T_4 * V_190 , * V_196 ;
for ( V_24 = 0 ; V_24 < V_240 ; ++ V_24 ) {
V_190 = F_127 ( & V_220 -> V_184 , V_92 , V_153 ,
& V_196 , V_189 ) ;
if ( ! V_190 )
goto V_59;
V_220 -> V_227 [ V_232 ] -> V_241 [ V_24 ] = V_196 ;
V_92 += V_242 / 64 ;
}
}
V_236 = V_220 -> V_225 ;
V_220 -> V_225 += V_242 ;
if ( V_236 < V_243 &&
V_220 -> V_225 > V_243 ) {
unsigned long V_244 ;
int V_151 ;
V_151 = F_97 ( V_243 , 0x10000 , V_153 ) ;
V_244 = V_243 >> V_226 ;
F_151 ( V_220 , V_244 , V_151 ) ;
}
F_154 (iommu) {
if ( V_19 -> V_245 &&
V_19 -> V_245 >= V_220 -> V_227 [ V_232 ] -> V_239
&& V_19 -> V_245 < V_220 -> V_225 ) {
unsigned long V_246 ;
int V_151 = F_97 ( V_19 -> V_245 ,
V_19 -> V_247 ,
V_153 ) ;
V_246 = V_19 -> V_245 >> V_226 ;
F_151 ( V_220 , V_246 , V_151 ) ;
}
}
for ( V_24 = V_220 -> V_227 [ V_232 ] -> V_239 ;
V_24 < V_220 -> V_225 ;
V_24 += V_153 ) {
T_4 * V_190 = F_137 ( & V_220 -> V_184 , V_24 ) ;
if ( ! V_190 || ! F_134 ( * V_190 ) )
continue;
F_151 ( V_220 , V_24 >> V_226 , 1 ) ;
}
F_144 ( & V_220 -> V_184 ) ;
return 0 ;
V_59:
F_144 ( & V_220 -> V_184 ) ;
F_155 ( ( unsigned long ) V_220 -> V_227 [ V_232 ] -> V_228 ) ;
F_10 ( V_220 -> V_227 [ V_232 ] ) ;
V_220 -> V_227 [ V_232 ] = NULL ;
return - V_48 ;
}
static unsigned long F_156 ( struct V_11 * V_12 ,
struct V_28 * V_202 ,
unsigned int V_151 ,
unsigned long V_248 ,
T_4 V_36 ,
unsigned long V_249 )
{
unsigned long V_250 = V_202 -> V_251 % V_242 ;
int V_252 = V_202 -> V_225 >> V_235 ;
int V_24 = V_249 >> V_235 ;
unsigned long V_253 ;
unsigned long V_92 = - 1 ;
unsigned long V_254 ;
V_250 >>= V_226 ;
V_253 = F_157 ( F_158 ( V_12 ) + 1 ,
V_153 ) >> V_226 ;
for (; V_24 < V_252 ; ++ V_24 ) {
unsigned long V_239 = V_202 -> V_227 [ V_24 ] -> V_239 >> V_226 ;
if ( V_202 -> V_227 [ V_24 ] -> V_239 >= V_36 )
break;
V_254 = F_159 ( V_233 , V_239 ,
V_36 >> V_226 ) ;
V_92 = F_160 ( V_202 -> V_227 [ V_24 ] -> V_228 ,
V_254 , V_250 , V_151 , 0 ,
V_253 , V_248 ) ;
if ( V_92 != - 1 ) {
V_92 = V_202 -> V_227 [ V_24 ] -> V_239 +
( V_92 << V_226 ) ;
V_202 -> V_251 = V_92 + ( V_151 << V_226 ) ;
break;
}
V_250 = 0 ;
}
return V_92 ;
}
static unsigned long F_161 ( struct V_11 * V_12 ,
struct V_28 * V_202 ,
unsigned int V_151 ,
unsigned long V_248 ,
T_4 V_36 )
{
unsigned long V_92 ;
#ifdef F_153
V_202 -> V_251 = 0 ;
V_202 -> V_255 = true ;
#endif
V_92 = F_156 ( V_12 , V_202 , V_151 , V_248 ,
V_36 , V_202 -> V_251 ) ;
if ( V_92 == - 1 ) {
V_202 -> V_251 = 0 ;
V_92 = F_156 ( V_12 , V_202 , V_151 , V_248 ,
V_36 , 0 ) ;
V_202 -> V_255 = true ;
}
if ( F_162 ( V_92 == - 1 ) )
V_92 = V_256 ;
F_41 ( ( V_92 + ( V_153 * V_151 ) ) > V_202 -> V_225 ) ;
return V_92 ;
}
static void F_163 ( struct V_28 * V_202 ,
unsigned long V_92 ,
unsigned int V_151 )
{
unsigned V_24 = V_92 >> V_235 ;
struct V_238 * V_257 = V_202 -> V_227 [ V_24 ] ;
F_128 ( V_24 >= V_237 || V_257 == NULL ) ;
#ifdef F_153
if ( V_24 < 4 )
return;
#endif
if ( V_92 >= V_202 -> V_251 )
V_202 -> V_255 = true ;
V_92 = ( V_92 % V_242 ) >> V_226 ;
F_164 ( V_257 -> V_228 , V_92 , V_151 ) ;
}
static void F_165 ( struct V_183 * V_184 )
{
unsigned long V_4 ;
F_4 ( & V_258 , V_4 ) ;
F_166 ( & V_184 -> V_259 , & V_260 ) ;
F_6 ( & V_258 , V_4 ) ;
}
static void F_167 ( struct V_183 * V_184 )
{
unsigned long V_4 ;
F_4 ( & V_258 , V_4 ) ;
F_8 ( & V_184 -> V_259 ) ;
F_6 ( & V_258 , V_4 ) ;
}
static T_1 F_168 ( void )
{
unsigned long V_4 ;
int V_185 ;
F_169 ( & V_261 , V_4 ) ;
V_185 = F_170 ( V_262 , V_263 ) ;
F_128 ( V_185 == 0 ) ;
if ( V_185 > 0 && V_185 < V_263 )
F_148 ( V_185 , V_262 ) ;
else
V_185 = 0 ;
F_171 ( & V_261 , V_4 ) ;
return V_185 ;
}
static void F_172 ( int V_185 )
{
unsigned long V_4 ;
F_169 ( & V_261 , V_4 ) ;
if ( V_185 > 0 && V_185 < V_263 )
F_173 ( V_185 , V_262 ) ;
F_171 ( & V_261 , V_4 ) ;
}
static void F_174 ( struct V_183 * V_184 )
{
int V_24 , V_264 ;
T_4 * V_265 , * V_266 , * V_267 ;
V_265 = V_184 -> V_193 ;
if ( ! V_265 )
return;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! F_134 ( V_265 [ V_24 ] ) )
continue;
V_266 = F_136 ( V_265 [ V_24 ] ) ;
for ( V_264 = 0 ; V_264 < 512 ; ++ V_264 ) {
if ( ! F_134 ( V_266 [ V_264 ] ) )
continue;
V_267 = F_136 ( V_266 [ V_264 ] ) ;
F_155 ( ( unsigned long ) V_267 ) ;
}
F_155 ( ( unsigned long ) V_266 ) ;
}
F_155 ( ( unsigned long ) V_265 ) ;
V_184 -> V_193 = NULL ;
}
static void F_175 ( T_4 * V_268 )
{
T_4 * V_269 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! ( V_268 [ V_24 ] & V_270 ) )
continue;
V_269 = F_176 ( V_268 [ V_24 ] & V_155 ) ;
F_155 ( ( unsigned long ) V_269 ) ;
}
}
static void F_177 ( T_4 * V_268 )
{
T_4 * V_269 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! ( V_268 [ V_24 ] & V_270 ) )
continue;
V_269 = F_176 ( V_268 [ V_24 ] & V_155 ) ;
F_175 ( V_269 ) ;
}
}
static void F_178 ( struct V_183 * V_184 )
{
if ( V_184 -> V_271 == 2 )
F_177 ( V_184 -> V_272 ) ;
else if ( V_184 -> V_271 == 1 )
F_175 ( V_184 -> V_272 ) ;
else if ( V_184 -> V_271 != 0 )
F_179 () ;
F_155 ( ( unsigned long ) V_184 -> V_272 ) ;
}
static void F_180 ( struct V_28 * V_202 )
{
int V_24 ;
if ( ! V_202 )
return;
F_167 ( & V_202 -> V_184 ) ;
F_174 ( & V_202 -> V_184 ) ;
for ( V_24 = 0 ; V_24 < V_237 ; ++ V_24 ) {
if ( ! V_202 -> V_227 [ V_24 ] )
continue;
F_155 ( ( unsigned long ) V_202 -> V_227 [ V_24 ] -> V_228 ) ;
F_10 ( V_202 -> V_227 [ V_24 ] ) ;
}
F_10 ( V_202 ) ;
}
static struct V_28 * F_181 ( void )
{
struct V_28 * V_220 ;
V_220 = F_2 ( sizeof( struct V_28 ) , V_5 ) ;
if ( ! V_220 )
return NULL ;
F_182 ( & V_220 -> V_184 . V_174 ) ;
V_220 -> V_184 . V_185 = F_168 () ;
if ( V_220 -> V_184 . V_185 == 0 )
goto V_273;
F_183 ( & V_220 -> V_184 . V_274 ) ;
V_220 -> V_184 . V_191 = V_275 ;
V_220 -> V_184 . V_193 = ( void * ) F_124 ( V_5 ) ;
V_220 -> V_184 . V_4 = V_276 ;
V_220 -> V_184 . V_277 = V_220 ;
if ( ! V_220 -> V_184 . V_193 )
goto V_273;
V_220 -> V_255 = false ;
V_220 -> V_35 = 0xffff ;
F_165 ( & V_220 -> V_184 ) ;
if ( F_152 ( V_220 , true , V_5 ) )
goto V_273;
V_220 -> V_227 [ 0 ] -> V_228 [ 0 ] = 1 ;
V_220 -> V_251 = 0 ;
return V_220 ;
V_273:
F_180 ( V_220 ) ;
return NULL ;
}
static bool V_28 ( struct V_183 * V_184 )
{
return V_184 -> V_4 & V_276 ;
}
static void F_184 ( T_1 V_2 , struct V_183 * V_184 , bool V_181 )
{
T_4 V_278 = 0 ;
T_4 V_4 = 0 ;
if ( V_184 -> V_191 != V_279 )
V_278 = F_126 ( V_184 -> V_193 ) ;
V_278 |= ( V_184 -> V_191 & V_280 )
<< V_281 ;
V_278 |= V_211 | V_213 | V_208 | V_282 ;
V_4 = V_56 [ V_2 ] . V_84 [ 1 ] ;
if ( V_181 )
V_4 |= V_283 ;
if ( V_184 -> V_4 & V_284 ) {
T_4 V_285 = F_92 ( V_184 -> V_272 ) ;
T_4 V_271 = V_184 -> V_271 ;
T_4 V_286 ;
V_278 |= V_287 ;
V_278 |= ( V_271 & V_288 ) << V_289 ;
V_286 = F_185 ( ~ 0ULL ) << V_290 ;
V_4 &= ~ V_286 ;
V_286 = F_186 ( ~ 0ULL ) << V_291 ;
V_4 &= ~ V_286 ;
V_286 = F_187 ( V_285 ) << V_292 ;
V_278 |= V_286 ;
V_286 = F_185 ( V_285 ) << V_290 ;
V_4 |= V_286 ;
V_286 = F_186 ( V_285 ) << V_291 ;
V_4 |= V_286 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_184 -> V_185 ;
V_56 [ V_2 ] . V_84 [ 1 ] = V_4 ;
V_56 [ V_2 ] . V_84 [ 0 ] = V_278 ;
}
static void F_188 ( T_1 V_2 )
{
V_56 [ V_2 ] . V_84 [ 0 ] = V_208 | V_282 ;
V_56 [ V_2 ] . V_84 [ 1 ] = 0 ;
F_189 ( V_2 ) ;
}
static void F_190 ( struct V_1 * V_3 ,
struct V_183 * V_184 )
{
struct V_53 * V_19 ;
bool V_181 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_181 = V_3 -> V_181 . V_182 ;
V_3 -> V_184 = V_184 ;
F_166 ( & V_3 -> V_259 , & V_184 -> V_274 ) ;
F_184 ( V_3 -> V_2 , V_184 , V_181 ) ;
V_184 -> V_187 [ V_19 -> V_232 ] += 1 ;
V_184 -> V_293 += 1 ;
F_116 ( V_3 ) ;
}
static void F_191 ( struct V_1 * V_3 )
{
struct V_53 * V_19 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_3 -> V_184 -> V_187 [ V_19 -> V_232 ] -= 1 ;
V_3 -> V_184 -> V_293 -= 1 ;
V_3 -> V_184 = NULL ;
F_8 ( & V_3 -> V_259 ) ;
F_188 ( V_3 -> V_2 ) ;
F_116 ( V_3 ) ;
}
static int F_192 ( struct V_1 * V_3 ,
struct V_183 * V_184 )
{
int V_30 ;
F_193 ( & V_184 -> V_174 ) ;
if ( V_3 -> V_49 != NULL ) {
struct V_1 * V_49 = V_3 -> V_49 ;
V_30 = - V_207 ;
if ( V_49 -> V_184 != NULL &&
V_49 -> V_184 != V_184 )
goto V_10;
if ( V_3 -> V_184 != NULL &&
V_3 -> V_184 != V_184 )
goto V_10;
if ( V_49 -> V_184 == NULL )
F_190 ( V_49 , V_184 ) ;
F_194 ( & V_49 -> V_6 ) ;
}
if ( V_3 -> V_184 == NULL )
F_190 ( V_3 , V_184 ) ;
F_194 ( & V_3 -> V_6 ) ;
V_30 = 0 ;
V_10:
F_195 ( & V_184 -> V_174 ) ;
return V_30 ;
}
static void F_196 ( struct V_13 * V_14 )
{
F_197 ( V_14 ) ;
F_198 ( V_14 ) ;
F_199 ( V_14 ) ;
}
static int F_200 ( struct V_13 * V_14 )
{
T_1 V_294 ;
int V_25 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( ! V_25 )
return - V_206 ;
F_201 ( V_14 , V_25 + V_295 , & V_294 ) ;
V_294 |= V_296 ;
F_202 ( V_14 , V_25 + V_295 , V_294 ) ;
return 0 ;
}
static int F_203 ( struct V_13 * V_14 )
{
bool V_297 ;
int V_298 , V_30 ;
V_298 = 32 ;
if ( F_20 ( V_14 , V_299 ) )
V_298 = 1 ;
V_297 = F_20 ( V_14 , V_300 ) ;
V_30 = F_204 ( V_14 , 0 ) ;
if ( V_30 )
goto V_301;
V_30 = F_205 ( V_14 ) ;
if ( V_30 )
goto V_301;
V_30 = F_206 ( V_14 , V_298 ) ;
if ( V_30 )
goto V_301;
if ( V_297 ) {
V_30 = F_200 ( V_14 ) ;
if ( V_30 )
goto V_301;
}
V_30 = F_207 ( V_14 , V_226 ) ;
if ( V_30 )
goto V_301;
return 0 ;
V_301:
F_198 ( V_14 ) ;
F_199 ( V_14 ) ;
return V_30 ;
}
static bool F_208 ( struct V_13 * V_14 )
{
T_1 V_134 ;
int V_25 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( ! V_25 )
return false ;
F_201 ( V_14 , V_25 + V_302 , & V_134 ) ;
return ( V_134 & V_303 ) ? true : false ;
}
static int F_209 ( struct V_11 * V_12 ,
struct V_183 * V_184 )
{
struct V_13 * V_14 = F_15 ( V_12 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_30 ;
V_3 = F_17 ( V_12 ) ;
if ( V_184 -> V_4 & V_284 ) {
if ( ! V_3 -> V_54 || ! V_3 -> V_304 )
return - V_206 ;
if ( F_203 ( V_14 ) != 0 )
return - V_206 ;
V_3 -> V_181 . V_182 = true ;
V_3 -> V_181 . V_159 = F_210 ( V_14 ) ;
V_3 -> V_305 = F_208 ( V_14 ) ;
} else if ( V_306 &&
F_207 ( V_14 , V_226 ) == 0 ) {
V_3 -> V_181 . V_182 = true ;
V_3 -> V_181 . V_159 = F_210 ( V_14 ) ;
}
F_169 ( & V_261 , V_4 ) ;
V_30 = F_192 ( V_3 , V_184 ) ;
F_171 ( & V_261 , V_4 ) ;
F_120 ( V_184 ) ;
return V_30 ;
}
static void F_211 ( struct V_1 * V_3 )
{
struct V_183 * V_184 ;
unsigned long V_4 ;
F_128 ( ! V_3 -> V_184 ) ;
V_184 = V_3 -> V_184 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
if ( V_3 -> V_49 != NULL ) {
struct V_1 * V_49 = V_3 -> V_49 ;
if ( F_212 ( & V_49 -> V_6 ) )
F_191 ( V_49 ) ;
}
if ( F_212 ( & V_3 -> V_6 ) )
F_191 ( V_3 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
if ( V_3 -> V_304 &&
( V_3 -> V_184 == NULL && V_184 != V_307 ) )
F_192 ( V_3 , V_307 ) ;
}
static void F_213 ( struct V_11 * V_12 )
{
struct V_183 * V_184 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_17 ( V_12 ) ;
V_184 = V_3 -> V_184 ;
F_169 ( & V_261 , V_4 ) ;
F_211 ( V_3 ) ;
F_171 ( & V_261 , V_4 ) ;
if ( V_184 -> V_4 & V_284 )
F_196 ( F_15 ( V_12 ) ) ;
else if ( V_3 -> V_181 . V_182 )
F_197 ( F_15 ( V_12 ) ) ;
V_3 -> V_181 . V_182 = false ;
}
static struct V_183 * F_214 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_183 * V_202 = NULL ;
unsigned long V_4 ;
V_3 = F_17 ( V_12 ) ;
if ( V_3 -> V_184 )
return V_3 -> V_184 ;
if ( V_3 -> V_49 != NULL ) {
struct V_1 * V_49 = V_3 -> V_49 ;
F_215 ( & V_261 , V_4 ) ;
if ( V_49 -> V_184 != NULL ) {
F_192 ( V_3 , V_49 -> V_184 ) ;
V_202 = V_49 -> V_184 ;
}
F_216 ( & V_261 , V_4 ) ;
}
return V_202 ;
}
static int F_217 ( struct V_308 * V_309 ,
unsigned long V_310 , void * V_84 )
{
struct V_28 * V_311 ;
struct V_183 * V_184 ;
struct V_1 * V_3 ;
struct V_11 * V_12 = V_84 ;
struct V_53 * V_19 ;
unsigned long V_4 ;
T_1 V_2 ;
if ( ! F_23 ( V_12 ) )
return 0 ;
V_2 = F_14 ( V_12 ) ;
V_19 = V_39 [ V_2 ] ;
V_3 = F_17 ( V_12 ) ;
switch ( V_310 ) {
case V_312 :
V_184 = F_214 ( V_12 ) ;
if ( ! V_184 )
goto V_313;
if ( V_3 -> V_304 )
break;
F_213 ( V_12 ) ;
break;
case V_314 :
F_48 ( V_12 ) ;
V_3 = F_17 ( V_12 ) ;
if ( V_315 || V_3 -> V_54 ) {
V_3 -> V_304 = true ;
F_209 ( V_12 , V_307 ) ;
break;
}
V_184 = F_214 ( V_12 ) ;
V_311 = F_21 ( V_2 ) ;
if ( ! V_311 ) {
V_311 = F_181 () ;
if ( ! V_311 )
goto V_313;
V_311 -> V_35 = V_2 ;
F_4 ( & V_34 , V_4 ) ;
F_5 ( & V_311 -> V_259 , & V_33 ) ;
F_6 ( & V_34 , V_4 ) ;
}
V_12 -> V_18 . V_316 = & V_317 ;
break;
case V_318 :
F_52 ( V_12 ) ;
default:
goto V_313;
}
F_106 ( V_19 ) ;
V_313:
return 0 ;
}
void F_218 ( void )
{
F_219 ( & V_37 , & V_319 ) ;
}
static struct V_183 * F_220 ( struct V_11 * V_12 )
{
struct V_183 * V_184 ;
struct V_28 * V_220 ;
T_1 V_2 = F_14 ( V_12 ) ;
if ( ! F_23 ( V_12 ) )
return F_26 ( - V_206 ) ;
V_184 = F_214 ( V_12 ) ;
if ( V_184 != NULL && ! V_28 ( V_184 ) )
return F_26 ( - V_207 ) ;
if ( V_184 != NULL )
return V_184 ;
V_220 = F_21 ( V_2 ) ;
if ( ! V_220 )
V_220 = V_39 [ V_2 ] -> V_229 ;
F_209 ( V_12 , & V_220 -> V_184 ) ;
F_221 ( L_25 ,
V_220 -> V_184 . V_185 , F_50 ( V_12 ) ) ;
return & V_220 -> V_184 ;
}
static void F_222 ( struct V_183 * V_184 )
{
struct V_1 * V_3 ;
F_12 (dev_data, &domain->dev_list, list)
F_184 ( V_3 -> V_2 , V_184 , V_3 -> V_181 . V_182 ) ;
}
static void F_144 ( struct V_183 * V_184 )
{
if ( ! V_184 -> V_194 )
return;
F_222 ( V_184 ) ;
F_122 ( V_184 ) ;
F_120 ( V_184 ) ;
V_184 -> V_194 = false ;
}
static T_4 * F_223 ( struct V_28 * V_202 ,
unsigned long V_92 )
{
struct V_238 * V_227 ;
T_4 * V_190 , * V_196 ;
V_227 = V_202 -> V_227 [ F_224 ( V_92 ) ] ;
if ( ! V_227 )
return NULL ;
V_190 = V_227 -> V_241 [ F_225 ( V_92 ) ] ;
if ( ! V_190 ) {
V_190 = F_127 ( & V_202 -> V_184 , V_92 , V_153 , & V_196 ,
V_320 ) ;
V_227 -> V_241 [ F_225 ( V_92 ) ] = V_196 ;
} else
V_190 += F_131 ( 0 , V_92 ) ;
F_144 ( & V_202 -> V_184 ) ;
return V_190 ;
}
static T_9 F_226 ( struct V_28 * V_202 ,
unsigned long V_92 ,
T_10 V_321 ,
int V_322 )
{
T_4 * V_190 , V_201 ;
F_41 ( V_92 > V_202 -> V_225 ) ;
V_321 &= V_155 ;
V_190 = F_223 ( V_202 , V_92 ) ;
if ( ! V_190 )
return V_256 ;
V_201 = V_321 | V_208 | V_209 ;
if ( V_322 == V_323 )
V_201 |= V_211 ;
else if ( V_322 == V_324 )
V_201 |= V_213 ;
else if ( V_322 == V_325 )
V_201 |= V_211 | V_213 ;
F_41 ( * V_190 ) ;
* V_190 = V_201 ;
return ( T_9 ) V_92 ;
}
static void F_227 ( struct V_28 * V_202 ,
unsigned long V_92 )
{
struct V_238 * V_227 ;
T_4 * V_190 ;
if ( V_92 >= V_202 -> V_225 )
return;
V_227 = V_202 -> V_227 [ F_224 ( V_92 ) ] ;
if ( ! V_227 )
return;
V_190 = V_227 -> V_241 [ F_225 ( V_92 ) ] ;
if ( ! V_190 )
return;
V_190 += F_131 ( 0 , V_92 ) ;
F_41 ( ! * V_190 ) ;
* V_190 = 0ULL ;
}
static T_9 F_228 ( struct V_11 * V_12 ,
struct V_28 * V_220 ,
T_10 V_321 ,
T_7 V_149 ,
int V_326 ,
bool V_327 ,
T_4 V_36 )
{
T_9 V_239 = V_321 & ~ V_155 ;
T_9 V_92 , V_249 , V_30 ;
unsigned int V_151 ;
unsigned long V_248 = 0 ;
int V_24 ;
V_151 = F_97 ( V_321 , V_149 , V_153 ) ;
V_321 &= V_155 ;
F_75 ( V_79 ) ;
if ( V_151 > 1 )
F_75 ( V_75 ) ;
if ( V_327 )
V_248 = ( 1UL << F_229 ( V_149 ) ) - 1 ;
V_93:
V_92 = F_161 ( V_12 , V_220 , V_151 , V_248 ,
V_36 ) ;
if ( F_162 ( V_92 == V_256 ) ) {
V_220 -> V_251 = V_220 -> V_225 ;
if ( F_152 ( V_220 , false , V_320 ) )
goto V_313;
goto V_93;
}
V_249 = V_92 ;
for ( V_24 = 0 ; V_24 < V_151 ; ++ V_24 ) {
V_30 = F_226 ( V_220 , V_249 , V_321 , V_326 ) ;
if ( V_30 == V_256 )
goto V_328;
V_321 += V_153 ;
V_249 += V_153 ;
}
V_92 += V_239 ;
F_230 ( V_78 , V_149 ) ;
if ( F_162 ( V_220 -> V_255 && ! V_67 ) ) {
F_119 ( & V_220 -> V_184 ) ;
V_220 -> V_255 = false ;
} else if ( F_162 ( V_329 ) )
F_118 ( & V_220 -> V_184 , V_92 , V_149 ) ;
V_313:
return V_92 ;
V_328:
for ( -- V_24 ; V_24 >= 0 ; -- V_24 ) {
V_249 -= V_153 ;
F_227 ( V_220 , V_249 ) ;
}
F_163 ( V_220 , V_92 , V_151 ) ;
return V_256 ;
}
static void F_231 ( struct V_28 * V_220 ,
T_9 V_330 ,
T_7 V_149 ,
int V_326 )
{
T_9 V_331 ;
T_9 V_24 , V_249 ;
unsigned int V_151 ;
if ( ( V_330 == V_256 ) ||
( V_330 + V_149 > V_220 -> V_225 ) )
return;
V_331 = V_330 ;
V_151 = F_97 ( V_330 , V_149 , V_153 ) ;
V_330 &= V_155 ;
V_249 = V_330 ;
for ( V_24 = 0 ; V_24 < V_151 ; ++ V_24 ) {
F_227 ( V_220 , V_249 ) ;
V_249 += V_153 ;
}
F_232 ( V_78 , V_149 ) ;
F_163 ( V_220 , V_330 , V_151 ) ;
if ( V_67 || V_220 -> V_255 ) {
F_118 ( & V_220 -> V_184 , V_331 , V_149 ) ;
V_220 -> V_255 = false ;
}
}
static T_9 F_233 ( struct V_11 * V_12 , struct V_199 * V_199 ,
unsigned long V_239 , T_7 V_149 ,
enum V_332 V_326 ,
struct V_333 * V_334 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
T_9 V_222 ;
T_4 V_36 ;
T_10 V_321 = F_234 ( V_199 ) + V_239 ;
F_75 ( V_69 ) ;
V_184 = F_220 ( V_12 ) ;
if ( F_40 ( V_184 ) == - V_206 )
return ( T_9 ) V_321 ;
else if ( F_34 ( V_184 ) )
return V_256 ;
V_36 = * V_12 -> V_36 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_222 = F_228 ( V_12 , V_184 -> V_277 , V_321 , V_149 , V_326 , false ,
V_36 ) ;
if ( V_222 == V_256 )
goto V_313;
F_121 ( V_184 ) ;
V_313:
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_222 ;
}
static void F_235 ( struct V_11 * V_12 , T_9 V_330 , T_7 V_149 ,
enum V_332 V_326 , struct V_333 * V_334 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
F_75 ( V_70 ) ;
V_184 = F_220 ( V_12 ) ;
if ( F_34 ( V_184 ) )
return;
F_4 ( & V_184 -> V_174 , V_4 ) ;
F_231 ( V_184 -> V_277 , V_330 , V_149 , V_326 ) ;
F_121 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
}
static int F_236 ( struct V_11 * V_12 , struct V_335 * V_336 ,
int V_337 , enum V_332 V_326 ,
struct V_333 * V_334 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
int V_24 ;
struct V_335 * V_152 ;
T_10 V_321 ;
int V_338 = 0 ;
T_4 V_36 ;
F_75 ( V_71 ) ;
V_184 = F_220 ( V_12 ) ;
if ( F_34 ( V_184 ) )
return 0 ;
V_36 = * V_12 -> V_36 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
F_237 (sglist, s, nelems, i) {
V_321 = F_238 ( V_152 ) ;
V_152 -> V_339 = F_228 ( V_12 , V_184 -> V_277 ,
V_321 , V_152 -> V_340 , V_326 , false ,
V_36 ) ;
if ( V_152 -> V_339 ) {
V_152 -> V_341 = V_152 -> V_340 ;
V_338 ++ ;
} else
goto V_342;
}
F_121 ( V_184 ) ;
V_313:
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_338 ;
V_342:
F_237 (sglist, s, mapped_elems, i) {
if ( V_152 -> V_339 )
F_231 ( V_184 -> V_277 , V_152 -> V_339 ,
V_152 -> V_341 , V_326 ) ;
V_152 -> V_339 = V_152 -> V_341 = 0 ;
}
V_338 = 0 ;
goto V_313;
}
static void F_239 ( struct V_11 * V_12 , struct V_335 * V_336 ,
int V_337 , enum V_332 V_326 ,
struct V_333 * V_334 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
struct V_335 * V_152 ;
int V_24 ;
F_75 ( V_72 ) ;
V_184 = F_220 ( V_12 ) ;
if ( F_34 ( V_184 ) )
return;
F_4 ( & V_184 -> V_174 , V_4 ) ;
F_237 (sglist, s, nelems, i) {
F_231 ( V_184 -> V_277 , V_152 -> V_339 ,
V_152 -> V_341 , V_326 ) ;
V_152 -> V_339 = V_152 -> V_341 = 0 ;
}
F_121 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
}
static void * F_240 ( struct V_11 * V_12 , T_7 V_149 ,
T_9 * V_330 , T_8 V_343 ,
struct V_333 * V_334 )
{
unsigned long V_4 ;
void * V_344 ;
struct V_183 * V_184 ;
T_10 V_321 ;
T_4 V_36 = V_12 -> V_345 ;
F_75 ( V_73 ) ;
V_184 = F_220 ( V_12 ) ;
if ( F_40 ( V_184 ) == - V_206 ) {
V_344 = ( void * ) F_241 ( V_343 , F_229 ( V_149 ) ) ;
* V_330 = F_92 ( V_344 ) ;
return V_344 ;
} else if ( F_34 ( V_184 ) )
return NULL ;
V_36 = V_12 -> V_345 ;
V_343 &= ~ ( V_346 | V_347 | V_348 ) ;
V_343 |= V_349 ;
V_344 = ( void * ) F_241 ( V_343 , F_229 ( V_149 ) ) ;
if ( ! V_344 )
return NULL ;
V_321 = F_126 ( V_344 ) ;
if ( ! V_36 )
V_36 = * V_12 -> V_36 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
* V_330 = F_228 ( V_12 , V_184 -> V_277 , V_321 ,
V_149 , V_325 , true , V_36 ) ;
if ( * V_330 == V_256 ) {
F_6 ( & V_184 -> V_174 , V_4 ) ;
goto V_59;
}
F_121 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_344 ;
V_59:
F_242 ( ( unsigned long ) V_344 , F_229 ( V_149 ) ) ;
return NULL ;
}
static void F_243 ( struct V_11 * V_12 , T_7 V_149 ,
void * V_344 , T_9 V_330 ,
struct V_333 * V_334 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
F_75 ( V_74 ) ;
V_184 = F_220 ( V_12 ) ;
if ( F_34 ( V_184 ) )
goto V_350;
F_4 ( & V_184 -> V_174 , V_4 ) ;
F_231 ( V_184 -> V_277 , V_330 , V_149 , V_325 ) ;
F_121 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
V_350:
F_242 ( ( unsigned long ) V_344 , F_229 ( V_149 ) ) ;
}
static int F_244 ( struct V_11 * V_12 , T_4 V_351 )
{
return F_23 ( V_12 ) ;
}
static void T_3 F_245 ( void )
{
struct V_1 * V_3 ;
struct V_28 * V_220 ;
struct V_13 * V_12 = NULL ;
T_1 V_2 ;
F_55 (dev) {
if ( ! F_23 ( & V_12 -> V_12 ) )
continue;
V_3 = F_17 ( & V_12 -> V_12 ) ;
if ( ! V_352 && V_3 -> V_54 ) {
F_246 () ;
V_3 -> V_304 = true ;
F_209 ( & V_12 -> V_12 , V_307 ) ;
F_247 ( L_26 ,
F_50 ( & V_12 -> V_12 ) ) ;
}
if ( F_214 ( & V_12 -> V_12 ) )
continue;
V_2 = F_14 ( & V_12 -> V_12 ) ;
V_220 = F_181 () ;
if ( ! V_220 )
continue;
F_150 ( V_220 , V_2 ) ;
V_220 -> V_35 = V_2 ;
F_209 ( & V_12 -> V_12 , & V_220 -> V_184 ) ;
F_5 ( & V_220 -> V_259 , & V_33 ) ;
}
}
static unsigned F_248 ( void )
{
struct V_1 * V_3 ;
struct V_13 * V_14 = NULL ;
unsigned V_353 = 0 ;
F_55 (pdev) {
if ( ! F_23 ( & V_14 -> V_12 ) ) {
F_51 ( & V_14 -> V_12 ) ;
V_353 += 1 ;
continue;
}
V_3 = F_17 ( & V_14 -> V_12 ) ;
if ( ! V_3 -> V_304 )
V_14 -> V_12 . V_18 . V_316 = & V_317 ;
else
V_14 -> V_12 . V_18 . V_316 = & V_354 ;
}
return V_353 ;
}
void T_3 F_249 ( void )
{
F_250 ( & V_37 , & V_355 ) ;
}
int T_3 F_251 ( void )
{
struct V_53 * V_19 ;
int V_30 , V_353 ;
F_154 (iommu) {
V_19 -> V_229 = F_181 () ;
if ( V_19 -> V_229 == NULL )
return - V_48 ;
V_19 -> V_229 -> V_184 . V_4 |= V_356 ;
V_30 = F_149 ( V_19 ) ;
if ( V_30 )
goto V_357;
}
F_245 () ;
V_358 = 1 ;
V_359 = 0 ;
V_353 = F_248 () ;
if ( V_353 && V_360 > V_361 ) {
V_359 = 1 ;
}
F_60 () ;
if ( V_67 )
F_247 ( L_27 ) ;
else
F_247 ( L_28 ) ;
return 0 ;
V_357:
F_154 (iommu) {
F_180 ( V_19 -> V_229 ) ;
}
return V_30 ;
}
static void F_252 ( struct V_183 * V_184 )
{
struct V_1 * V_3 , * V_362 ;
unsigned long V_4 ;
F_169 ( & V_261 , V_4 ) ;
F_56 (dev_data, next, &domain->dev_list, list) {
F_211 ( V_3 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
}
F_171 ( & V_261 , V_4 ) ;
}
static void F_253 ( struct V_183 * V_184 )
{
if ( ! V_184 )
return;
F_167 ( V_184 ) ;
if ( V_184 -> V_185 )
F_172 ( V_184 -> V_185 ) ;
F_10 ( V_184 ) ;
}
static struct V_183 * F_254 ( void )
{
struct V_183 * V_184 ;
V_184 = F_2 ( sizeof( * V_184 ) , V_5 ) ;
if ( ! V_184 )
return NULL ;
F_182 ( & V_184 -> V_174 ) ;
F_255 ( & V_184 -> V_363 ) ;
V_184 -> V_185 = F_168 () ;
if ( ! V_184 -> V_185 )
goto V_301;
F_183 ( & V_184 -> V_274 ) ;
F_165 ( V_184 ) ;
return V_184 ;
V_301:
F_10 ( V_184 ) ;
return NULL ;
}
static int T_3 F_246 ( void )
{
if ( V_307 != NULL )
return 0 ;
V_307 = F_254 () ;
if ( ! V_307 )
return - V_48 ;
V_307 -> V_191 = V_279 ;
return 0 ;
}
static int F_256 ( struct V_364 * V_202 )
{
struct V_183 * V_184 ;
V_184 = F_254 () ;
if ( ! V_184 )
goto V_59;
V_184 -> V_191 = V_365 ;
V_184 -> V_193 = ( void * ) F_124 ( V_5 ) ;
if ( ! V_184 -> V_193 )
goto V_59;
V_184 -> V_364 = V_202 ;
V_202 -> V_277 = V_184 ;
V_202 -> V_366 . V_367 = 0 ;
V_202 -> V_366 . V_368 = ~ 0ULL ;
V_202 -> V_366 . V_369 = true ;
return 0 ;
V_59:
F_253 ( V_184 ) ;
return - V_48 ;
}
static void F_257 ( struct V_364 * V_202 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
if ( ! V_184 )
return;
if ( V_184 -> V_293 > 0 )
F_252 ( V_184 ) ;
F_128 ( V_184 -> V_293 != 0 ) ;
if ( V_184 -> V_191 != V_279 )
F_174 ( V_184 ) ;
if ( V_184 -> V_4 & V_284 )
F_178 ( V_184 ) ;
F_253 ( V_184 ) ;
V_202 -> V_277 = NULL ;
}
static void F_258 ( struct V_364 * V_202 ,
struct V_11 * V_12 )
{
struct V_1 * V_3 = V_12 -> V_18 . V_19 ;
struct V_53 * V_19 ;
T_1 V_2 ;
if ( ! F_23 ( V_12 ) )
return;
V_2 = F_14 ( V_12 ) ;
if ( V_3 -> V_184 != NULL )
F_213 ( V_12 ) ;
V_19 = V_39 [ V_2 ] ;
if ( ! V_19 )
return;
F_106 ( V_19 ) ;
}
static int F_259 ( struct V_364 * V_202 ,
struct V_11 * V_12 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
struct V_1 * V_3 ;
struct V_53 * V_19 ;
int V_30 ;
if ( ! F_23 ( V_12 ) )
return - V_206 ;
V_3 = V_12 -> V_18 . V_19 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
if ( ! V_19 )
return - V_206 ;
if ( V_3 -> V_184 )
F_213 ( V_12 ) ;
V_30 = F_209 ( V_12 , V_184 ) ;
F_106 ( V_19 ) ;
return V_30 ;
}
static int F_260 ( struct V_364 * V_202 , unsigned long V_370 ,
T_10 V_321 , T_7 V_195 , int V_371 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
int V_204 = 0 ;
int V_30 ;
if ( V_184 -> V_191 == V_279 )
return - V_206 ;
if ( V_371 & V_372 )
V_204 |= V_210 ;
if ( V_371 & V_373 )
V_204 |= V_212 ;
F_261 ( & V_184 -> V_363 ) ;
V_30 = F_140 ( V_184 , V_370 , V_321 , V_204 , V_195 ) ;
F_262 ( & V_184 -> V_363 ) ;
return V_30 ;
}
static T_7 F_263 ( struct V_364 * V_202 , unsigned long V_370 ,
T_7 V_195 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
T_7 V_214 ;
if ( V_184 -> V_191 == V_279 )
return - V_206 ;
F_261 ( & V_184 -> V_363 ) ;
V_214 = F_145 ( V_184 , V_370 , V_195 ) ;
F_262 ( & V_184 -> V_363 ) ;
F_120 ( V_184 ) ;
return V_214 ;
}
static T_10 F_264 ( struct V_364 * V_202 ,
T_9 V_370 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
unsigned long V_374 ;
T_10 V_321 ;
T_4 * V_190 , V_201 ;
if ( V_184 -> V_191 == V_279 )
return V_370 ;
V_190 = F_137 ( V_184 , V_370 ) ;
if ( ! V_190 || ! F_134 ( * V_190 ) )
return 0 ;
if ( F_135 ( * V_190 ) == 0 )
V_374 = V_153 - 1 ;
else
V_374 = F_138 ( * V_190 ) - 1 ;
V_201 = * V_190 & V_375 ;
V_321 = ( V_201 & ~ V_374 ) | ( V_370 & V_374 ) ;
return V_321 ;
}
static int F_265 ( struct V_364 * V_184 ,
unsigned long V_376 )
{
switch ( V_376 ) {
case V_377 :
return 1 ;
case V_378 :
return V_379 ;
}
return 0 ;
}
int T_3 F_266 ( void )
{
struct V_1 * V_3 ;
struct V_13 * V_12 = NULL ;
struct V_53 * V_19 ;
T_1 V_2 ;
int V_30 ;
V_30 = F_246 () ;
if ( V_30 )
return V_30 ;
F_55 (dev) {
if ( ! F_23 ( & V_12 -> V_12 ) )
continue;
V_3 = F_17 ( & V_12 -> V_12 ) ;
V_3 -> V_304 = true ;
V_2 = F_14 ( & V_12 -> V_12 ) ;
V_19 = V_39 [ V_2 ] ;
if ( ! V_19 )
continue;
F_209 ( & V_12 -> V_12 , V_307 ) ;
}
F_60 () ;
F_247 ( L_29 ) ;
return 0 ;
}
int F_267 ( struct V_308 * V_309 )
{
return F_268 ( & V_127 , V_309 ) ;
}
int F_269 ( struct V_308 * V_309 )
{
return F_270 ( & V_127 , V_309 ) ;
}
void F_271 ( struct V_364 * V_202 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
unsigned long V_4 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_184 -> V_191 = V_279 ;
V_184 -> V_194 = true ;
F_144 ( V_184 ) ;
F_174 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
}
int F_272 ( struct V_364 * V_202 , int V_380 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
unsigned long V_4 ;
int V_381 , V_30 ;
if ( V_380 <= 0 || V_380 > ( V_161 + 1 ) )
return - V_206 ;
for ( V_381 = 0 ; ( V_380 - 1 ) & ~ 0x1ff ; V_380 >>= 9 )
V_381 += 1 ;
if ( V_381 > V_382 )
return - V_206 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = - V_207 ;
if ( V_184 -> V_293 > 0 || V_184 -> V_4 & V_284 )
goto V_313;
V_30 = - V_48 ;
V_184 -> V_272 = ( void * ) F_124 ( V_320 ) ;
if ( V_184 -> V_272 == NULL )
goto V_313;
V_184 -> V_271 = V_381 ;
V_184 -> V_4 |= V_284 ;
V_184 -> V_194 = true ;
F_144 ( V_184 ) ;
V_30 = 0 ;
V_313:
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
static int F_273 ( struct V_183 * V_184 , int V_124 ,
T_4 V_92 , bool V_149 )
{
struct V_1 * V_3 ;
struct V_86 V_87 ;
int V_24 , V_30 ;
if ( ! ( V_184 -> V_4 & V_284 ) )
return - V_206 ;
F_99 ( & V_87 , V_184 -> V_185 , V_124 , V_92 , V_149 ) ;
for ( V_24 = 0 ; V_24 < V_186 ; ++ V_24 ) {
if ( V_184 -> V_187 [ V_24 ] == 0 )
continue;
V_30 = F_105 ( V_188 [ V_24 ] , & V_87 ) ;
if ( V_30 != 0 )
goto V_313;
}
F_121 ( V_184 ) ;
F_12 (dev_data, &domain->dev_list, list) {
struct V_53 * V_19 ;
int V_159 ;
F_128 ( ! V_3 -> V_181 . V_182 ) ;
V_159 = V_3 -> V_181 . V_159 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
F_100 ( & V_87 , V_3 -> V_2 , V_124 ,
V_159 , V_92 , V_149 ) ;
V_30 = F_105 ( V_19 , & V_87 ) ;
if ( V_30 != 0 )
goto V_313;
}
F_121 ( V_184 ) ;
V_30 = 0 ;
V_313:
return V_30 ;
}
static int F_274 ( struct V_183 * V_184 , int V_124 ,
T_4 V_92 )
{
F_75 ( V_81 ) ;
return F_273 ( V_184 , V_124 , V_92 , false ) ;
}
int F_275 ( struct V_364 * V_202 , int V_124 ,
T_4 V_92 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = F_274 ( V_184 , V_124 , V_92 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
static int F_276 ( struct V_183 * V_184 , int V_124 )
{
F_75 ( V_82 ) ;
return F_273 ( V_184 , V_124 , V_154 ,
true ) ;
}
int F_277 ( struct V_364 * V_202 , int V_124 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = F_276 ( V_184 , V_124 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
static T_4 * F_278 ( T_4 * V_383 , int V_197 , int V_124 , bool V_384 )
{
int V_232 ;
T_4 * V_190 ;
while ( true ) {
V_232 = ( V_124 >> ( 9 * V_197 ) ) & 0x1ff ;
V_190 = & V_383 [ V_232 ] ;
if ( V_197 == 0 )
break;
if ( ! ( * V_190 & V_270 ) ) {
if ( ! V_384 )
return NULL ;
V_383 = ( void * ) F_124 ( V_320 ) ;
if ( V_383 == NULL )
return NULL ;
* V_190 = F_92 ( V_383 ) | V_270 ;
}
V_383 = F_176 ( * V_190 & V_155 ) ;
V_197 -= 1 ;
}
return V_190 ;
}
static int F_279 ( struct V_183 * V_184 , int V_124 ,
unsigned long V_385 )
{
T_4 * V_190 ;
if ( V_184 -> V_191 != V_279 )
return - V_206 ;
V_190 = F_278 ( V_184 -> V_272 , V_184 -> V_271 , V_124 , true ) ;
if ( V_190 == NULL )
return - V_48 ;
* V_190 = ( V_385 & V_155 ) | V_270 ;
return F_276 ( V_184 , V_124 ) ;
}
static int F_280 ( struct V_183 * V_184 , int V_124 )
{
T_4 * V_190 ;
if ( V_184 -> V_191 != V_279 )
return - V_206 ;
V_190 = F_278 ( V_184 -> V_272 , V_184 -> V_271 , V_124 , false ) ;
if ( V_190 == NULL )
return 0 ;
* V_190 = 0 ;
return F_276 ( V_184 , V_124 ) ;
}
int F_281 ( struct V_364 * V_202 , int V_124 ,
unsigned long V_385 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = F_279 ( V_184 , V_124 , V_385 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
int F_282 ( struct V_364 * V_202 , int V_124 )
{
struct V_183 * V_184 = V_202 -> V_277 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = F_280 ( V_184 , V_124 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
int F_283 ( struct V_13 * V_14 , int V_124 ,
int V_134 , int V_126 )
{
struct V_1 * V_3 ;
struct V_53 * V_19 ;
struct V_86 V_87 ;
F_75 ( V_80 ) ;
V_3 = F_17 ( & V_14 -> V_12 ) ;
V_19 = V_39 [ V_3 -> V_2 ] ;
F_101 ( & V_87 , V_3 -> V_2 , V_124 , V_134 ,
V_126 , V_3 -> V_305 ) ;
return F_105 ( V_19 , & V_87 ) ;
}
struct V_364 * F_284 ( struct V_13 * V_14 )
{
struct V_183 * V_184 ;
V_184 = F_220 ( & V_14 -> V_12 ) ;
if ( F_34 ( V_184 ) )
return NULL ;
if ( ! ( V_184 -> V_4 & V_284 ) )
return NULL ;
return V_184 -> V_364 ;
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
struct F_287 * V_386 )
{
int V_387 ;
int V_25 ;
if ( V_14 == NULL || V_386 == NULL )
return - V_206 ;
if ( ! F_286 () )
return - V_206 ;
memset ( V_386 , 0 , sizeof( * V_386 ) ) ;
V_25 = F_19 ( V_14 , V_21 ) ;
if ( V_25 )
V_386 -> V_4 |= V_388 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( V_25 )
V_386 -> V_4 |= V_389 ;
V_25 = F_19 ( V_14 , V_23 ) ;
if ( V_25 ) {
int V_390 ;
V_387 = 1 << ( 9 * ( V_382 + 1 ) ) ;
V_387 = F_288 ( V_387 , ( 1 << 20 ) ) ;
V_386 -> V_4 |= V_391 ;
V_386 -> V_387 = F_288 ( F_289 ( V_14 ) , V_387 ) ;
V_390 = F_290 ( V_14 ) ;
if ( V_390 & V_392 )
V_386 -> V_4 |= V_393 ;
if ( V_390 & V_394 )
V_386 -> V_4 |= V_395 ;
}
return 0 ;
}
static void F_291 ( T_1 V_2 , struct V_396 * V_397 )
{
T_4 V_398 ;
V_398 = V_56 [ V_2 ] . V_84 [ 2 ] ;
V_398 &= ~ V_399 ;
V_398 |= F_126 ( V_397 -> V_397 ) ;
V_398 |= V_400 ;
V_398 |= V_401 ;
V_398 |= V_402 ;
V_56 [ V_2 ] . V_84 [ 2 ] = V_398 ;
}
static struct V_396 * F_292 ( T_1 V_2 , bool V_403 )
{
struct V_396 * V_397 = NULL ;
struct V_53 * V_19 ;
unsigned long V_4 ;
T_1 V_31 ;
F_169 ( & V_261 , V_4 ) ;
V_19 = V_39 [ V_2 ] ;
if ( ! V_19 )
goto V_10;
V_397 = V_404 [ V_2 ] ;
if ( V_397 )
goto V_313;
V_31 = V_32 [ V_2 ] ;
V_397 = V_404 [ V_31 ] ;
if ( V_397 ) {
V_404 [ V_2 ] = V_397 ;
F_291 ( V_2 , V_397 ) ;
F_107 ( V_19 , V_2 ) ;
goto V_313;
}
V_397 = F_2 ( sizeof( * V_397 ) , V_320 ) ;
if ( ! V_397 )
goto V_313;
F_182 ( & V_397 -> V_174 ) ;
if ( V_403 )
V_397 -> V_405 = 32 ;
V_397 -> V_397 = F_293 ( V_406 , V_320 ) ;
if ( ! V_397 -> V_397 ) {
F_10 ( V_397 ) ;
V_397 = NULL ;
goto V_313;
}
memset ( V_397 -> V_397 , 0 , V_407 * sizeof( T_2 ) ) ;
if ( V_403 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < 32 ; ++ V_24 )
V_397 -> V_397 [ V_24 ] = V_408 ;
}
V_404 [ V_2 ] = V_397 ;
F_291 ( V_2 , V_397 ) ;
F_107 ( V_19 , V_2 ) ;
if ( V_2 != V_31 ) {
V_404 [ V_31 ] = V_397 ;
F_291 ( V_2 , V_397 ) ;
F_107 ( V_19 , V_31 ) ;
}
V_313:
F_106 ( V_19 ) ;
V_10:
F_171 ( & V_261 , V_4 ) ;
return V_397 ;
}
static int F_294 ( struct V_409 * V_410 , T_1 V_2 , int V_91 )
{
struct V_396 * V_397 ;
unsigned long V_4 ;
int V_232 , V_411 ;
V_397 = F_292 ( V_2 , false ) ;
if ( ! V_397 )
return - V_43 ;
F_4 ( & V_397 -> V_174 , V_4 ) ;
for ( V_411 = 0 , V_232 = V_397 -> V_405 ;
V_232 < V_407 ;
++ V_232 ) {
if ( V_397 -> V_397 [ V_232 ] == 0 )
V_411 += 1 ;
else
V_411 = 0 ;
if ( V_411 == V_91 ) {
struct V_412 * V_413 ;
for (; V_411 != 0 ; -- V_411 )
V_397 -> V_397 [ V_232 - V_411 + 1 ] = V_408 ;
V_232 -= V_91 - 1 ;
V_410 -> V_414 = 1 ;
V_413 = & V_410 -> V_412 ;
V_413 -> V_2 = V_2 ;
V_413 -> V_232 = V_232 ;
goto V_313;
}
}
V_232 = - V_415 ;
V_313:
F_6 ( & V_397 -> V_174 , V_4 ) ;
return V_232 ;
}
static int F_295 ( T_1 V_2 , int V_232 , union V_416 * V_416 )
{
struct V_396 * V_397 ;
unsigned long V_4 ;
V_397 = F_292 ( V_2 , false ) ;
if ( ! V_397 )
return - V_48 ;
F_4 ( & V_397 -> V_174 , V_4 ) ;
V_416 -> V_417 = V_397 -> V_397 [ V_232 ] ;
F_6 ( & V_397 -> V_174 , V_4 ) ;
return 0 ;
}
static int F_296 ( T_1 V_2 , int V_232 , union V_416 V_416 )
{
struct V_396 * V_397 ;
struct V_53 * V_19 ;
unsigned long V_4 ;
V_19 = V_39 [ V_2 ] ;
if ( V_19 == NULL )
return - V_206 ;
V_397 = F_292 ( V_2 , false ) ;
if ( ! V_397 )
return - V_48 ;
F_4 ( & V_397 -> V_174 , V_4 ) ;
V_397 -> V_397 [ V_232 ] = V_416 . V_417 ;
F_6 ( & V_397 -> V_174 , V_4 ) ;
F_111 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
return 0 ;
}
static void F_297 ( T_1 V_2 , int V_232 )
{
struct V_396 * V_397 ;
struct V_53 * V_19 ;
unsigned long V_4 ;
V_19 = V_39 [ V_2 ] ;
if ( V_19 == NULL )
return;
V_397 = F_292 ( V_2 , false ) ;
if ( ! V_397 )
return;
F_4 ( & V_397 -> V_174 , V_4 ) ;
V_397 -> V_397 [ V_232 ] = 0 ;
F_6 ( & V_397 -> V_174 , V_4 ) ;
F_111 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
}
static int F_298 ( int V_133 , struct V_418 * V_29 ,
unsigned int V_419 , int V_420 ,
struct V_421 * V_422 )
{
struct V_396 * V_397 ;
struct V_412 * V_413 ;
struct V_409 * V_410 ;
union V_416 V_416 ;
int V_423 ;
int V_232 ;
int V_2 ;
int V_30 ;
V_410 = F_299 ( V_133 ) ;
if ( ! V_410 )
return - V_206 ;
V_413 = & V_410 -> V_412 ;
V_423 = F_300 ( V_422 -> V_403 ) ;
V_2 = F_301 ( V_423 ) ;
if ( V_2 < 0 )
return V_2 ;
V_397 = F_292 ( V_2 , true ) ;
if ( V_397 == NULL )
return - V_48 ;
V_232 = V_422 -> V_424 ;
V_410 -> V_414 = 1 ;
V_413 -> V_2 = V_2 ;
V_413 -> V_232 = V_232 ;
V_416 . V_417 = 0 ;
V_416 . V_425 . V_420 = V_420 ;
V_416 . V_425 . V_426 = V_427 -> V_428 ;
V_416 . V_425 . V_419 = V_419 ;
V_416 . V_425 . V_429 = V_427 -> V_430 ;
V_416 . V_425 . V_431 = 1 ;
V_30 = F_296 ( V_2 , V_232 , V_416 ) ;
if ( V_30 )
return V_30 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_420 = V_232 ;
V_29 -> V_351 = 0 ;
V_29 -> V_432 = V_422 -> V_432 ;
V_29 -> V_433 = V_422 -> V_433 ;
if ( V_422 -> V_432 )
V_29 -> V_351 = 1 ;
return 0 ;
}
static int F_302 ( struct V_434 * V_84 , const struct V_435 * V_351 ,
bool V_436 )
{
struct V_412 * V_413 ;
unsigned int V_437 , V_133 ;
struct V_409 * V_410 ;
union V_416 V_416 ;
int V_438 ;
if ( ! F_303 ( V_439 ) )
return - 1 ;
V_410 = V_84 -> V_440 ;
V_133 = V_84 -> V_133 ;
V_413 = & V_410 -> V_412 ;
if ( ! F_304 ( V_351 , V_441 ) )
return - V_206 ;
if ( F_295 ( V_413 -> V_2 , V_413 -> V_232 , & V_416 ) )
return - V_207 ;
if ( F_305 ( V_133 , V_410 , V_351 ) )
return - V_207 ;
V_438 = V_427 -> V_442 ( V_410 -> V_184 , V_351 , & V_437 ) ;
if ( V_438 ) {
if ( F_305 ( V_133 , V_410 , V_84 -> V_443 ) )
F_49 ( L_30 , V_133 ) ;
return V_438 ;
}
V_416 . V_425 . V_420 = V_410 -> V_420 ;
V_416 . V_425 . V_419 = V_437 ;
F_296 ( V_413 -> V_2 , V_413 -> V_232 , V_416 ) ;
if ( V_410 -> V_444 )
F_306 ( V_410 ) ;
F_307 ( V_84 -> V_443 , V_351 ) ;
return 0 ;
}
static int F_308 ( int V_133 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
V_410 = F_299 ( V_133 ) ;
if ( ! V_410 )
return - V_206 ;
V_413 = & V_410 -> V_412 ;
F_297 ( V_413 -> V_2 , V_413 -> V_232 ) ;
return 0 ;
}
static void F_309 ( struct V_13 * V_14 ,
unsigned int V_133 , unsigned int V_437 ,
struct V_445 * V_446 , T_6 V_447 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
union V_416 V_416 ;
V_410 = F_299 ( V_133 ) ;
if ( ! V_410 )
return;
V_413 = & V_410 -> V_412 ;
V_416 . V_417 = 0 ;
V_416 . V_425 . V_420 = V_410 -> V_420 ;
V_416 . V_425 . V_426 = V_427 -> V_428 ;
V_416 . V_425 . V_419 = V_437 ;
V_416 . V_425 . V_429 = V_427 -> V_430 ;
V_416 . V_425 . V_431 = 1 ;
F_296 ( V_413 -> V_2 , V_413 -> V_232 , V_416 ) ;
V_446 -> V_448 = V_449 ;
V_446 -> V_450 = V_243 ;
V_446 -> V_84 = V_413 -> V_232 ;
}
static int F_310 ( struct V_13 * V_14 , int V_133 , int V_451 )
{
struct V_409 * V_410 ;
int V_232 ;
T_1 V_2 ;
if ( ! V_14 )
return - V_206 ;
V_410 = F_299 ( V_133 ) ;
if ( ! V_410 )
return - V_206 ;
V_2 = F_14 ( & V_14 -> V_12 ) ;
V_232 = F_294 ( V_410 , V_2 , V_451 ) ;
return V_232 < 0 ? V_407 : V_232 ;
}
static int F_311 ( struct V_13 * V_14 , unsigned int V_133 ,
int V_232 , int V_239 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
T_1 V_2 ;
if ( ! V_14 )
return - V_206 ;
V_410 = F_299 ( V_133 ) ;
if ( ! V_410 )
return - V_206 ;
if ( V_232 >= V_407 )
return 0 ;
V_2 = F_14 ( & V_14 -> V_12 ) ;
V_413 = & V_410 -> V_412 ;
V_410 -> V_414 = 1 ;
V_413 -> V_2 = V_2 ;
V_413 -> V_232 = V_232 + V_239 ;
return 0 ;
}
static int F_312 ( unsigned int V_133 , unsigned int V_185 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
int V_232 , V_2 ;
V_410 = F_299 ( V_133 ) ;
if ( ! V_410 )
return - V_206 ;
V_413 = & V_410 -> V_412 ;
V_2 = F_313 ( V_185 ) ;
if ( V_2 < 0 )
return V_2 ;
V_232 = F_294 ( V_410 , V_2 , 1 ) ;
if ( V_232 < 0 )
return V_232 ;
V_410 -> V_414 = 1 ;
V_413 -> V_2 = V_2 ;
V_413 -> V_232 = V_232 ;
return 0 ;
}
