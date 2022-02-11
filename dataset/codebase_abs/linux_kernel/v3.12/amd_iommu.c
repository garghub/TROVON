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
! F_30 ( V_44 , V_46 ) ) {
T_3 V_24 , V_47 = F_31 ( V_44 -> V_17 ) ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
struct V_13 * V_48 ;
V_48 = F_32 ( V_44 -> V_15 , F_33 ( V_47 , V_24 ) ) ;
if ( ! V_48 )
continue;
if ( ! F_30 ( V_48 , V_46 ) ) {
F_28 ( & V_44 , V_48 ) ;
break;
}
F_34 ( V_48 ) ;
}
}
while ( ! F_25 ( V_44 -> V_15 ) ) {
struct V_40 * V_15 = F_24 ( V_44 -> V_15 ) ;
if ( F_35 ( V_15 ) )
break;
if ( F_36 ( V_15 -> V_41 , NULL , V_46 ) )
break;
F_28 ( & V_44 , F_37 ( V_15 -> V_41 ) ) ;
}
return V_44 ;
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
struct V_13 * V_44 ;
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
struct V_40 * V_15 ;
if ( V_3 -> V_51 -> V_9 )
goto V_52;
V_31 = V_32 [ V_3 -> V_2 ] ;
V_44 = F_46 ( V_31 >> 8 , V_31 & 0xff ) ;
if ( V_44 ) {
V_44 = F_27 ( V_44 ) ;
goto V_53;
}
V_15 = F_47 ( 0 , V_31 >> 8 ) ;
if ( ! V_15 )
goto V_52;
V_15 = F_24 ( V_15 ) ;
if ( F_35 ( V_15 ) || ! V_15 -> V_41 )
goto V_52;
V_44 = F_27 ( F_37 ( V_15 -> V_41 ) ) ;
if ( V_44 != V_15 -> V_41 || ( V_44 -> V_45 &&
! F_30 ( V_44 , V_46 ) ) )
goto V_53;
F_34 ( V_44 ) ;
goto V_52;
}
V_44 = F_27 ( F_37 ( F_15 ( V_12 ) ) ) ;
V_53:
V_30 = F_38 ( V_44 , V_12 ) ;
F_34 ( V_44 ) ;
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
if ( V_30 ) {
F_7 ( V_3 ) ;
return V_30 ;
}
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
void T_4 F_54 ( void )
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
int T_4 F_57 ( void )
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
T_5 V_94 ;
V_95:
type = ( V_92 [ 1 ] >> V_96 ) & V_97 ;
V_2 = ( V_92 [ 0 ] >> V_98 ) & V_99 ;
V_91 = ( V_92 [ 1 ] >> V_100 ) & V_101 ;
V_4 = ( V_92 [ 1 ] >> V_102 ) & V_103 ;
V_94 = ( T_5 ) ( ( ( T_5 ) V_92 [ 3 ] ) << 32 ) | V_92 [ 2 ] ;
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
F_69 ( V_2 ) , F_31 ( V_2 ) , F_70 ( V_2 ) ,
V_94 , V_4 ) ;
F_63 ( V_2 ) ;
break;
case V_107 :
F_68 ( L_10
L_11 ,
F_69 ( V_2 ) , F_31 ( V_2 ) , F_70 ( V_2 ) ,
V_91 , V_94 , V_4 ) ;
break;
case V_108 :
F_68 ( L_12
L_9 ,
F_69 ( V_2 ) , F_31 ( V_2 ) , F_70 ( V_2 ) ,
V_94 , V_4 ) ;
break;
case V_109 :
F_68 ( L_13
L_11 ,
F_69 ( V_2 ) , F_31 ( V_2 ) , F_70 ( V_2 ) ,
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
F_69 ( V_2 ) , F_31 ( V_2 ) , F_70 ( V_2 ) ,
V_94 ) ;
break;
case V_113 :
F_68 ( L_19
L_9 ,
F_69 ( V_2 ) , F_31 ( V_2 ) , F_70 ( V_2 ) ,
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
V_114 = F_72 ( V_19 -> V_116 + V_117 ) ;
V_115 = F_72 ( V_19 -> V_116 + V_118 ) ;
while ( V_114 != V_115 ) {
F_66 ( V_19 , V_19 -> V_119 + V_114 ) ;
V_114 = ( V_114 + V_120 ) % V_19 -> V_121 ;
}
F_73 ( V_114 , V_19 -> V_116 + V_117 ) ;
}
static void F_74 ( struct V_55 * V_19 , T_5 * V_122 )
{
struct V_123 V_124 ;
F_75 ( V_85 ) ;
if ( F_76 ( V_122 [ 0 ] ) != V_125 ) {
F_77 ( L_21 ) ;
return;
}
V_124 . V_94 = V_122 [ 1 ] ;
V_124 . V_126 = F_78 ( V_122 [ 0 ] ) ;
V_124 . V_127 = F_79 ( V_122 [ 0 ] ) ;
V_124 . V_128 = F_80 ( V_122 [ 0 ] ) ;
V_124 . V_4 = F_81 ( V_122 [ 0 ] ) ;
F_82 ( & V_129 , 0 , & V_124 ) ;
}
static void F_83 ( struct V_55 * V_19 )
{
T_2 V_114 , V_115 ;
if ( V_19 -> V_130 == NULL )
return;
V_114 = F_72 ( V_19 -> V_116 + V_131 ) ;
V_115 = F_72 ( V_19 -> V_116 + V_132 ) ;
while ( V_114 != V_115 ) {
volatile T_5 * V_122 ;
T_5 V_29 [ 2 ] ;
int V_24 ;
V_122 = ( T_5 * ) ( V_19 -> V_130 + V_114 ) ;
for ( V_24 = 0 ; V_24 < V_104 ; ++ V_24 ) {
if ( F_76 ( V_122 [ 0 ] ) != 0 )
break;
F_67 ( 1 ) ;
}
V_29 [ 0 ] = V_122 [ 0 ] ;
V_29 [ 1 ] = V_122 [ 1 ] ;
V_122 [ 0 ] = V_122 [ 1 ] = 0UL ;
V_114 = ( V_114 + V_133 ) % V_134 ;
F_73 ( V_114 , V_19 -> V_116 + V_131 ) ;
F_74 ( V_19 , V_29 ) ;
V_114 = F_72 ( V_19 -> V_116 + V_131 ) ;
V_115 = F_72 ( V_19 -> V_116 + V_132 ) ;
}
}
T_6 F_84 ( int V_135 , void * V_86 )
{
struct V_55 * V_19 = (struct V_55 * ) V_86 ;
T_2 V_136 = F_72 ( V_19 -> V_116 + V_137 ) ;
while ( V_136 & ( V_138 | V_139 ) ) {
F_73 ( ( V_138 | V_139 ) ,
V_19 -> V_116 + V_137 ) ;
if ( V_136 & V_138 ) {
F_85 ( L_22 ) ;
F_71 ( V_19 ) ;
}
if ( V_136 & V_139 ) {
F_85 ( L_23 ) ;
F_83 ( V_19 ) ;
}
V_136 = F_72 ( V_19 -> V_116 + V_137 ) ;
}
return V_140 ;
}
T_6 F_86 ( int V_135 , void * V_86 )
{
return V_141 ;
}
static int F_87 ( volatile T_5 * V_142 )
{
int V_24 = 0 ;
while ( * V_142 == 0 && V_24 < V_104 ) {
F_67 ( 1 ) ;
V_24 += 1 ;
}
if ( V_24 == V_104 ) {
F_88 ( L_24 ) ;
return - V_143 ;
}
return 0 ;
}
static void F_89 ( struct V_55 * V_19 ,
struct V_88 * V_89 ,
T_2 V_115 )
{
T_3 * V_144 ;
V_144 = V_19 -> V_145 + V_115 ;
V_115 = ( V_115 + sizeof( * V_89 ) ) % V_19 -> V_146 ;
memcpy ( V_144 , V_89 , sizeof( * V_89 ) ) ;
F_73 ( V_115 , V_19 -> V_116 + V_147 ) ;
}
static void F_90 ( struct V_88 * V_89 , T_5 V_94 )
{
F_42 ( V_94 & 0x7ULL ) ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = F_91 ( F_92 ( V_94 ) ) | V_148 ;
V_89 -> V_86 [ 1 ] = F_93 ( F_92 ( V_94 ) ) ;
V_89 -> V_86 [ 2 ] = 1 ;
F_94 ( V_89 , V_149 ) ;
}
static void F_95 ( struct V_88 * V_89 , T_1 V_2 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_2 ;
F_94 ( V_89 , V_150 ) ;
}
static void F_96 ( struct V_88 * V_89 , T_5 V_94 ,
T_7 V_151 , T_1 V_91 , int V_152 )
{
T_5 V_153 ;
int V_154 ;
V_153 = F_97 ( V_94 , V_151 , V_155 ) ;
V_154 = 0 ;
if ( V_153 > 1 ) {
V_94 = V_156 ;
V_154 = 1 ;
}
V_94 &= V_157 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 1 ] |= V_91 ;
V_89 -> V_86 [ 2 ] = F_91 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_93 ( V_94 ) ;
F_94 ( V_89 , V_158 ) ;
if ( V_154 )
V_89 -> V_86 [ 2 ] |= V_159 ;
if ( V_152 )
V_89 -> V_86 [ 2 ] |= V_160 ;
}
static void F_98 ( struct V_88 * V_89 , T_1 V_2 , int V_161 ,
T_5 V_94 , T_7 V_151 )
{
T_5 V_153 ;
int V_154 ;
V_153 = F_97 ( V_94 , V_151 , V_155 ) ;
V_154 = 0 ;
if ( V_153 > 1 ) {
V_94 = V_156 ;
V_154 = 1 ;
}
V_94 &= V_157 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_2 ;
V_89 -> V_86 [ 0 ] |= ( V_161 & 0xff ) << 24 ;
V_89 -> V_86 [ 1 ] = V_2 ;
V_89 -> V_86 [ 2 ] = F_91 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_93 ( V_94 ) ;
F_94 ( V_89 , V_162 ) ;
if ( V_154 )
V_89 -> V_86 [ 2 ] |= V_159 ;
}
static void F_99 ( struct V_88 * V_89 , T_1 V_91 , int V_126 ,
T_5 V_94 , bool V_151 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_94 &= ~ ( 0xfffULL ) ;
V_89 -> V_86 [ 0 ] = V_126 & V_163 ;
V_89 -> V_86 [ 1 ] = V_91 ;
V_89 -> V_86 [ 2 ] = F_91 ( V_94 ) ;
V_89 -> V_86 [ 3 ] = F_93 ( V_94 ) ;
V_89 -> V_86 [ 2 ] |= V_160 ;
V_89 -> V_86 [ 2 ] |= V_164 ;
if ( V_151 )
V_89 -> V_86 [ 2 ] |= V_159 ;
F_94 ( V_89 , V_158 ) ;
}
static void F_100 ( struct V_88 * V_89 , T_1 V_2 , int V_126 ,
int V_161 , T_5 V_94 , bool V_151 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_94 &= ~ ( 0xfffULL ) ;
V_89 -> V_86 [ 0 ] = V_2 ;
V_89 -> V_86 [ 0 ] |= ( V_126 & 0xff ) << 16 ;
V_89 -> V_86 [ 0 ] |= ( V_161 & 0xff ) << 24 ;
V_89 -> V_86 [ 1 ] = V_2 ;
V_89 -> V_86 [ 1 ] |= ( ( V_126 >> 8 ) & 0xfff ) << 16 ;
V_89 -> V_86 [ 2 ] = F_91 ( V_94 ) ;
V_89 -> V_86 [ 2 ] |= V_164 ;
V_89 -> V_86 [ 3 ] = F_93 ( V_94 ) ;
if ( V_151 )
V_89 -> V_86 [ 2 ] |= V_159 ;
F_94 ( V_89 , V_162 ) ;
}
static void F_101 ( struct V_88 * V_89 , T_1 V_2 , int V_126 ,
int V_136 , int V_128 , bool V_165 )
{
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_86 [ 0 ] = V_2 ;
if ( V_165 ) {
V_89 -> V_86 [ 1 ] = V_126 & V_163 ;
V_89 -> V_86 [ 2 ] = V_164 ;
}
V_89 -> V_86 [ 3 ] = V_128 & 0x1ff ;
V_89 -> V_86 [ 3 ] |= ( V_136 & V_166 ) << V_167 ;
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
F_42 ( V_19 -> V_146 & V_174 ) ;
V_175:
F_4 ( & V_19 -> V_176 , V_4 ) ;
V_114 = F_72 ( V_19 -> V_116 + V_177 ) ;
V_115 = F_72 ( V_19 -> V_116 + V_147 ) ;
V_173 = ( V_115 + sizeof( * V_89 ) ) % V_19 -> V_146 ;
V_172 = ( V_114 - V_173 ) % V_19 -> V_146 ;
if ( V_172 <= 2 ) {
struct V_88 V_178 ;
volatile T_5 V_142 = 0 ;
int V_30 ;
F_90 ( & V_178 , ( T_5 ) & V_142 ) ;
F_89 ( V_19 , & V_178 , V_115 ) ;
F_6 ( & V_19 -> V_176 , V_4 ) ;
if ( ( V_30 = F_87 ( & V_142 ) ) != 0 )
return V_30 ;
goto V_175;
}
F_89 ( V_19 , V_89 , V_115 ) ;
V_19 -> V_179 = V_171 ;
F_6 ( & V_19 -> V_176 , V_4 ) ;
return 0 ;
}
static int F_105 ( struct V_55 * V_19 , struct V_88 * V_89 )
{
return F_104 ( V_19 , V_89 , true ) ;
}
static int F_106 ( struct V_55 * V_19 )
{
struct V_88 V_89 ;
volatile T_5 V_142 = 0 ;
int V_30 ;
if ( ! V_19 -> V_179 )
return 0 ;
F_90 ( & V_89 , ( T_5 ) & V_142 ) ;
V_30 = F_104 ( V_19 , & V_89 , false ) ;
if ( V_30 )
return V_30 ;
return F_87 ( & V_142 ) ;
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
T_2 V_180 ;
for ( V_180 = 0 ; V_180 <= 0xffff ; ++ V_180 ) {
struct V_88 V_89 ;
F_96 ( & V_89 , 0 , V_156 ,
V_180 , 1 ) ;
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
for ( V_2 = 0 ; V_2 <= V_181 ; V_2 ++ )
F_111 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
}
void F_113 ( struct V_55 * V_19 )
{
if ( F_114 ( V_19 , V_182 ) ) {
F_110 ( V_19 ) ;
} else {
F_108 ( V_19 ) ;
F_112 ( V_19 ) ;
F_109 ( V_19 ) ;
}
}
static int F_115 ( struct V_1 * V_3 ,
T_5 V_94 , T_7 V_151 )
{
struct V_55 * V_19 ;
struct V_88 V_89 ;
int V_161 ;
V_161 = V_3 -> V_183 . V_161 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
F_98 ( & V_89 , V_3 -> V_2 , V_161 , V_94 , V_151 ) ;
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
if ( V_3 -> V_183 . V_184 )
V_30 = F_115 ( V_3 , 0 , ~ 0UL ) ;
return V_30 ;
}
static void F_117 ( struct V_185 * V_186 ,
T_5 V_94 , T_7 V_151 , int V_152 )
{
struct V_1 * V_3 ;
struct V_88 V_89 ;
int V_30 = 0 , V_24 ;
F_96 ( & V_89 , V_94 , V_151 , V_186 -> V_187 , V_152 ) ;
for ( V_24 = 0 ; V_24 < V_188 ; ++ V_24 ) {
if ( ! V_186 -> V_189 [ V_24 ] )
continue;
V_30 |= F_105 ( V_190 [ V_24 ] , & V_89 ) ;
}
F_12 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_183 . V_184 )
continue;
V_30 |= F_115 ( V_3 , V_94 , V_151 ) ;
}
F_42 ( V_30 ) ;
}
static void F_118 ( struct V_185 * V_186 ,
T_5 V_94 , T_7 V_151 )
{
F_117 ( V_186 , V_94 , V_151 , 0 ) ;
}
static void F_119 ( struct V_185 * V_186 )
{
F_117 ( V_186 , 0 , V_156 , 0 ) ;
}
static void F_120 ( struct V_185 * V_186 )
{
F_117 ( V_186 , 0 , V_156 , 1 ) ;
}
static void F_121 ( struct V_185 * V_186 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_188 ; ++ V_24 ) {
if ( ! V_186 -> V_189 [ V_24 ] )
continue;
F_106 ( V_190 [ V_24 ] ) ;
}
}
static void F_122 ( struct V_185 * V_186 )
{
struct V_1 * V_3 ;
F_12 (dev_data, &domain->dev_list, list)
F_116 ( V_3 ) ;
}
static bool F_123 ( struct V_185 * V_186 ,
T_8 V_191 )
{
T_5 * V_192 ;
if ( V_186 -> V_193 == V_194 )
return false ;
V_192 = ( void * ) F_124 ( V_191 ) ;
if ( ! V_192 )
return false ;
* V_192 = F_125 ( V_186 -> V_193 ,
F_126 ( V_186 -> V_195 ) ) ;
V_186 -> V_195 = V_192 ;
V_186 -> V_193 += 1 ;
V_186 -> V_196 = true ;
return true ;
}
static T_5 * F_127 ( struct V_185 * V_186 ,
unsigned long V_94 ,
unsigned long V_197 ,
T_5 * * V_198 ,
T_8 V_191 )
{
int V_199 , V_200 ;
T_5 * V_192 , * V_201 ;
F_128 ( ! F_129 ( V_197 ) ) ;
while ( V_94 > F_130 ( V_186 -> V_193 ) )
F_123 ( V_186 , V_191 ) ;
V_199 = V_186 -> V_193 - 1 ;
V_192 = & V_186 -> V_195 [ F_131 ( V_199 , V_94 ) ] ;
V_94 = F_132 ( V_94 , V_197 ) ;
V_200 = F_133 ( V_197 ) ;
while ( V_199 > V_200 ) {
if ( ! F_134 ( * V_192 ) ) {
V_201 = ( T_5 * ) F_124 ( V_191 ) ;
if ( ! V_201 )
return NULL ;
* V_192 = F_125 ( V_199 , F_126 ( V_201 ) ) ;
}
if ( F_135 ( * V_192 ) != V_199 )
return NULL ;
V_199 -= 1 ;
V_192 = F_136 ( * V_192 ) ;
if ( V_198 && V_199 == V_200 )
* V_198 = V_192 ;
V_192 = & V_192 [ F_131 ( V_199 , V_94 ) ] ;
}
return V_192 ;
}
static T_5 * F_137 ( struct V_185 * V_186 , unsigned long V_94 )
{
int V_199 ;
T_5 * V_192 ;
if ( V_94 > F_130 ( V_186 -> V_193 ) )
return NULL ;
V_199 = V_186 -> V_193 - 1 ;
V_192 = & V_186 -> V_195 [ F_131 ( V_199 , V_94 ) ] ;
while ( V_199 > 0 ) {
if ( ! F_134 ( * V_192 ) )
return NULL ;
if ( F_135 ( * V_192 ) == 0x07 ) {
unsigned long V_202 , V_203 ;
V_202 = F_138 ( * V_192 ) ;
V_202 = ~ ( ( F_139 ( V_202 ) << 3 ) - 1 ) ;
V_203 = ( ( unsigned long ) V_192 ) & V_202 ;
return ( T_5 * ) V_203 ;
}
if ( F_135 ( * V_192 ) != V_199 )
return NULL ;
V_199 -= 1 ;
V_192 = F_136 ( * V_192 ) ;
V_192 = & V_192 [ F_131 ( V_199 , V_94 ) ] ;
}
return V_192 ;
}
static int F_140 ( struct V_185 * V_204 ,
unsigned long V_205 ,
unsigned long V_87 ,
int V_206 ,
unsigned long V_197 )
{
T_5 V_203 , * V_192 ;
int V_24 , V_93 ;
if ( ! ( V_206 & V_207 ) )
return - V_208 ;
V_205 = F_141 ( V_205 ) ;
V_87 = F_141 ( V_87 ) ;
V_93 = F_139 ( V_197 ) ;
V_192 = F_127 ( V_204 , V_205 , V_197 , NULL , V_5 ) ;
for ( V_24 = 0 ; V_24 < V_93 ; ++ V_24 )
if ( F_134 ( V_192 [ V_24 ] ) )
return - V_209 ;
if ( V_197 > V_155 ) {
V_203 = F_142 ( V_87 , V_197 ) ;
V_203 |= F_143 ( 7 ) | V_210 | V_211 ;
} else
V_203 = V_87 | V_210 | V_211 ;
if ( V_206 & V_212 )
V_203 |= V_213 ;
if ( V_206 & V_214 )
V_203 |= V_215 ;
for ( V_24 = 0 ; V_24 < V_93 ; ++ V_24 )
V_192 [ V_24 ] = V_203 ;
F_144 ( V_204 ) ;
return 0 ;
}
static unsigned long F_145 ( struct V_185 * V_204 ,
unsigned long V_205 ,
unsigned long V_197 )
{
unsigned long long V_216 , V_217 ;
T_5 * V_192 ;
F_128 ( ! F_129 ( V_197 ) ) ;
V_217 = 0 ;
while ( V_217 < V_197 ) {
V_192 = F_137 ( V_204 , V_205 ) ;
if ( ! V_192 ) {
V_216 = V_155 ;
} else if ( F_135 ( * V_192 ) == 0 ) {
V_216 = V_155 ;
* V_192 = 0ULL ;
} else {
int V_93 , V_24 ;
V_216 = F_138 ( * V_192 ) ;
if ( ( V_216 - 1 ) & V_205 )
break;
V_93 = F_139 ( V_216 ) ;
for ( V_24 = 0 ; V_24 < V_93 ; V_24 ++ )
V_192 [ V_24 ] = 0ULL ;
}
V_205 = ( V_205 & ~ ( V_216 - 1 ) ) + V_216 ;
V_217 += V_216 ;
}
F_128 ( V_217 && ! F_129 ( V_217 ) ) ;
return V_217 ;
}
static int F_146 ( struct V_55 * V_19 ,
struct V_218 * V_29 )
{
T_1 V_219 , V_24 ;
for ( V_24 = V_29 -> V_220 ; V_24 <= V_29 -> V_221 ; ++ V_24 ) {
V_219 = V_32 [ V_24 ] ;
if ( V_39 [ V_219 ] == V_19 )
return 1 ;
}
return 0 ;
}
static int F_147 ( struct V_28 * V_222 ,
struct V_218 * V_223 )
{
T_5 V_224 ;
int V_30 ;
for ( V_224 = V_223 -> V_225 ; V_224 < V_223 -> V_226 ;
V_224 += V_155 ) {
V_30 = F_140 ( & V_222 -> V_186 , V_224 , V_224 , V_223 -> V_206 ,
V_155 ) ;
if ( V_30 )
return V_30 ;
if ( V_224 < V_222 -> V_227 )
F_148 ( V_224 >> V_228 ,
V_222 -> V_229 [ 0 ] -> V_230 ) ;
}
return 0 ;
}
static int F_149 ( struct V_55 * V_19 )
{
struct V_218 * V_29 ;
int V_30 ;
F_12 (entry, &amd_iommu_unity_map, list) {
if ( ! F_146 ( V_19 , V_29 ) )
continue;
V_30 = F_147 ( V_19 -> V_231 , V_29 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static int F_150 ( struct V_28 * V_222 ,
T_1 V_2 )
{
struct V_218 * V_223 ;
int V_30 ;
F_12 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_223 -> V_220 && V_2 <= V_223 -> V_221 ) )
continue;
V_30 = F_147 ( V_222 , V_223 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static void F_151 ( struct V_28 * V_204 ,
unsigned long V_232 ,
unsigned int V_153 )
{
unsigned int V_24 , V_233 = V_204 -> V_227 >> V_228 ;
if ( V_232 + V_153 > V_233 )
V_153 = V_233 - V_232 ;
for ( V_24 = V_232 ; V_24 < V_232 + V_153 ; ++ V_24 ) {
int V_234 = V_24 / V_235 ;
int V_201 = V_24 % V_235 ;
F_148 ( V_201 , V_204 -> V_229 [ V_234 ] -> V_230 ) ;
}
}
static int F_152 ( struct V_28 * V_222 ,
bool V_236 , T_8 V_191 )
{
int V_234 = V_222 -> V_227 >> V_237 ;
struct V_55 * V_19 ;
unsigned long V_24 , V_238 ;
#ifdef F_153
V_236 = false ;
#endif
if ( V_234 >= V_239 )
return - V_50 ;
V_222 -> V_229 [ V_234 ] = F_2 ( sizeof( struct V_240 ) , V_191 ) ;
if ( ! V_222 -> V_229 [ V_234 ] )
return - V_50 ;
V_222 -> V_229 [ V_234 ] -> V_230 = ( void * ) F_124 ( V_191 ) ;
if ( ! V_222 -> V_229 [ V_234 ] -> V_230 )
goto V_61;
V_222 -> V_229 [ V_234 ] -> V_241 = V_222 -> V_227 ;
if ( V_236 ) {
unsigned long V_94 = V_222 -> V_227 ;
int V_24 , V_242 = V_235 / 512 ;
T_5 * V_192 , * V_198 ;
for ( V_24 = 0 ; V_24 < V_242 ; ++ V_24 ) {
V_192 = F_127 ( & V_222 -> V_186 , V_94 , V_155 ,
& V_198 , V_191 ) ;
if ( ! V_192 )
goto V_61;
V_222 -> V_229 [ V_234 ] -> V_243 [ V_24 ] = V_198 ;
V_94 += V_244 / 64 ;
}
}
V_238 = V_222 -> V_227 ;
V_222 -> V_227 += V_244 ;
if ( V_238 < V_245 &&
V_222 -> V_227 > V_245 ) {
unsigned long V_246 ;
int V_153 ;
V_153 = F_97 ( V_245 , 0x10000 , V_155 ) ;
V_246 = V_245 >> V_228 ;
F_151 ( V_222 , V_246 , V_153 ) ;
}
F_154 (iommu) {
if ( V_19 -> V_247 &&
V_19 -> V_247 >= V_222 -> V_229 [ V_234 ] -> V_241
&& V_19 -> V_247 < V_222 -> V_227 ) {
unsigned long V_248 ;
int V_153 = F_97 ( V_19 -> V_247 ,
V_19 -> V_249 ,
V_155 ) ;
V_248 = V_19 -> V_247 >> V_228 ;
F_151 ( V_222 , V_248 , V_153 ) ;
}
}
for ( V_24 = V_222 -> V_229 [ V_234 ] -> V_241 ;
V_24 < V_222 -> V_227 ;
V_24 += V_155 ) {
T_5 * V_192 = F_137 ( & V_222 -> V_186 , V_24 ) ;
if ( ! V_192 || ! F_134 ( * V_192 ) )
continue;
F_151 ( V_222 , V_24 >> V_228 , 1 ) ;
}
F_144 ( & V_222 -> V_186 ) ;
return 0 ;
V_61:
F_144 ( & V_222 -> V_186 ) ;
F_155 ( ( unsigned long ) V_222 -> V_229 [ V_234 ] -> V_230 ) ;
F_10 ( V_222 -> V_229 [ V_234 ] ) ;
V_222 -> V_229 [ V_234 ] = NULL ;
return - V_50 ;
}
static unsigned long F_156 ( struct V_11 * V_12 ,
struct V_28 * V_204 ,
unsigned int V_153 ,
unsigned long V_250 ,
T_5 V_36 ,
unsigned long V_251 )
{
unsigned long V_252 = V_204 -> V_253 % V_244 ;
int V_254 = V_204 -> V_227 >> V_237 ;
int V_24 = V_251 >> V_237 ;
unsigned long V_255 ;
unsigned long V_94 = - 1 ;
unsigned long V_256 ;
V_252 >>= V_228 ;
V_255 = F_157 ( F_158 ( V_12 ) + 1 ,
V_155 ) >> V_228 ;
for (; V_24 < V_254 ; ++ V_24 ) {
unsigned long V_241 = V_204 -> V_229 [ V_24 ] -> V_241 >> V_228 ;
if ( V_204 -> V_229 [ V_24 ] -> V_241 >= V_36 )
break;
V_256 = F_159 ( V_235 , V_241 ,
V_36 >> V_228 ) ;
V_94 = F_160 ( V_204 -> V_229 [ V_24 ] -> V_230 ,
V_256 , V_252 , V_153 , 0 ,
V_255 , V_250 ) ;
if ( V_94 != - 1 ) {
V_94 = V_204 -> V_229 [ V_24 ] -> V_241 +
( V_94 << V_228 ) ;
V_204 -> V_253 = V_94 + ( V_153 << V_228 ) ;
break;
}
V_252 = 0 ;
}
return V_94 ;
}
static unsigned long F_161 ( struct V_11 * V_12 ,
struct V_28 * V_204 ,
unsigned int V_153 ,
unsigned long V_250 ,
T_5 V_36 )
{
unsigned long V_94 ;
#ifdef F_153
V_204 -> V_253 = 0 ;
V_204 -> V_257 = true ;
#endif
V_94 = F_156 ( V_12 , V_204 , V_153 , V_250 ,
V_36 , V_204 -> V_253 ) ;
if ( V_94 == - 1 ) {
V_204 -> V_253 = 0 ;
V_94 = F_156 ( V_12 , V_204 , V_153 , V_250 ,
V_36 , 0 ) ;
V_204 -> V_257 = true ;
}
if ( F_162 ( V_94 == - 1 ) )
V_94 = V_258 ;
F_42 ( ( V_94 + ( V_155 * V_153 ) ) > V_204 -> V_227 ) ;
return V_94 ;
}
static void F_163 ( struct V_28 * V_204 ,
unsigned long V_94 ,
unsigned int V_153 )
{
unsigned V_24 = V_94 >> V_237 ;
struct V_240 * V_259 = V_204 -> V_229 [ V_24 ] ;
F_128 ( V_24 >= V_239 || V_259 == NULL ) ;
#ifdef F_153
if ( V_24 < 4 )
return;
#endif
if ( V_94 >= V_204 -> V_253 )
V_204 -> V_257 = true ;
V_94 = ( V_94 % V_244 ) >> V_228 ;
F_164 ( V_259 -> V_230 , V_94 , V_153 ) ;
}
static void F_165 ( struct V_185 * V_186 )
{
unsigned long V_4 ;
F_4 ( & V_260 , V_4 ) ;
F_166 ( & V_186 -> V_261 , & V_262 ) ;
F_6 ( & V_260 , V_4 ) ;
}
static void F_167 ( struct V_185 * V_186 )
{
unsigned long V_4 ;
F_4 ( & V_260 , V_4 ) ;
F_8 ( & V_186 -> V_261 ) ;
F_6 ( & V_260 , V_4 ) ;
}
static T_1 F_168 ( void )
{
unsigned long V_4 ;
int V_187 ;
F_169 ( & V_263 , V_4 ) ;
V_187 = F_170 ( V_264 , V_265 ) ;
F_128 ( V_187 == 0 ) ;
if ( V_187 > 0 && V_187 < V_265 )
F_148 ( V_187 , V_264 ) ;
else
V_187 = 0 ;
F_171 ( & V_263 , V_4 ) ;
return V_187 ;
}
static void F_172 ( int V_187 )
{
unsigned long V_4 ;
F_169 ( & V_263 , V_4 ) ;
if ( V_187 > 0 && V_187 < V_265 )
F_173 ( V_187 , V_264 ) ;
F_171 ( & V_263 , V_4 ) ;
}
static void F_174 ( struct V_185 * V_186 )
{
unsigned long V_266 = ( unsigned long ) V_186 -> V_195 ;
switch ( V_186 -> V_193 ) {
case V_267 :
break;
case V_268 :
F_155 ( V_266 ) ;
break;
case V_269 :
F_175 ( V_266 ) ;
break;
case V_270 :
F_176 ( V_266 ) ;
break;
case V_271 :
F_177 ( V_266 ) ;
break;
case V_272 :
F_178 ( V_266 ) ;
break;
case V_194 :
F_179 ( V_266 ) ;
break;
default:
F_180 () ;
}
}
static void F_181 ( T_5 * V_273 )
{
T_5 * V_274 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! ( V_273 [ V_24 ] & V_275 ) )
continue;
V_274 = F_182 ( V_273 [ V_24 ] & V_157 ) ;
F_155 ( ( unsigned long ) V_274 ) ;
}
}
static void F_183 ( T_5 * V_273 )
{
T_5 * V_274 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! ( V_273 [ V_24 ] & V_275 ) )
continue;
V_274 = F_182 ( V_273 [ V_24 ] & V_157 ) ;
F_181 ( V_274 ) ;
}
}
static void F_184 ( struct V_185 * V_186 )
{
if ( V_186 -> V_276 == 2 )
F_183 ( V_186 -> V_277 ) ;
else if ( V_186 -> V_276 == 1 )
F_181 ( V_186 -> V_277 ) ;
else if ( V_186 -> V_276 != 0 )
F_180 () ;
F_155 ( ( unsigned long ) V_186 -> V_277 ) ;
}
static void F_185 ( struct V_28 * V_204 )
{
int V_24 ;
if ( ! V_204 )
return;
F_167 ( & V_204 -> V_186 ) ;
F_174 ( & V_204 -> V_186 ) ;
for ( V_24 = 0 ; V_24 < V_239 ; ++ V_24 ) {
if ( ! V_204 -> V_229 [ V_24 ] )
continue;
F_155 ( ( unsigned long ) V_204 -> V_229 [ V_24 ] -> V_230 ) ;
F_10 ( V_204 -> V_229 [ V_24 ] ) ;
}
F_10 ( V_204 ) ;
}
static struct V_28 * F_186 ( void )
{
struct V_28 * V_222 ;
V_222 = F_2 ( sizeof( struct V_28 ) , V_5 ) ;
if ( ! V_222 )
return NULL ;
F_187 ( & V_222 -> V_186 . V_176 ) ;
V_222 -> V_186 . V_187 = F_168 () ;
if ( V_222 -> V_186 . V_187 == 0 )
goto V_278;
F_188 ( & V_222 -> V_186 . V_279 ) ;
V_222 -> V_186 . V_193 = V_269 ;
V_222 -> V_186 . V_195 = ( void * ) F_124 ( V_5 ) ;
V_222 -> V_186 . V_4 = V_280 ;
V_222 -> V_186 . V_281 = V_222 ;
if ( ! V_222 -> V_186 . V_195 )
goto V_278;
V_222 -> V_257 = false ;
V_222 -> V_35 = 0xffff ;
F_165 ( & V_222 -> V_186 ) ;
if ( F_152 ( V_222 , true , V_5 ) )
goto V_278;
V_222 -> V_229 [ 0 ] -> V_230 [ 0 ] = 1 ;
V_222 -> V_253 = 0 ;
return V_222 ;
V_278:
F_185 ( V_222 ) ;
return NULL ;
}
static bool V_28 ( struct V_185 * V_186 )
{
return V_186 -> V_4 & V_280 ;
}
static void F_189 ( T_1 V_2 , struct V_185 * V_186 , bool V_183 )
{
T_5 V_282 = 0 ;
T_5 V_4 = 0 ;
if ( V_186 -> V_193 != V_267 )
V_282 = F_126 ( V_186 -> V_195 ) ;
V_282 |= ( V_186 -> V_193 & V_283 )
<< V_284 ;
V_282 |= V_213 | V_215 | V_210 | V_285 ;
V_4 = V_58 [ V_2 ] . V_86 [ 1 ] ;
if ( V_183 )
V_4 |= V_286 ;
if ( V_186 -> V_4 & V_287 ) {
T_5 V_288 = F_92 ( V_186 -> V_277 ) ;
T_5 V_276 = V_186 -> V_276 ;
T_5 V_48 ;
V_282 |= V_289 ;
V_282 |= ( V_276 & V_290 ) << V_291 ;
V_48 = F_190 ( ~ 0ULL ) << V_292 ;
V_4 &= ~ V_48 ;
V_48 = F_191 ( ~ 0ULL ) << V_293 ;
V_4 &= ~ V_48 ;
V_48 = F_192 ( V_288 ) << V_294 ;
V_282 |= V_48 ;
V_48 = F_190 ( V_288 ) << V_292 ;
V_4 |= V_48 ;
V_48 = F_191 ( V_288 ) << V_293 ;
V_4 |= V_48 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_186 -> V_187 ;
V_58 [ V_2 ] . V_86 [ 1 ] = V_4 ;
V_58 [ V_2 ] . V_86 [ 0 ] = V_282 ;
}
static void F_193 ( T_1 V_2 )
{
V_58 [ V_2 ] . V_86 [ 0 ] = V_210 | V_285 ;
V_58 [ V_2 ] . V_86 [ 1 ] = 0 ;
F_194 ( V_2 ) ;
}
static void F_195 ( struct V_1 * V_3 ,
struct V_185 * V_186 )
{
struct V_55 * V_19 ;
bool V_183 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_183 = V_3 -> V_183 . V_184 ;
V_3 -> V_186 = V_186 ;
F_166 ( & V_3 -> V_261 , & V_186 -> V_279 ) ;
F_189 ( V_3 -> V_2 , V_186 , V_183 ) ;
V_186 -> V_189 [ V_19 -> V_234 ] += 1 ;
V_186 -> V_295 += 1 ;
F_116 ( V_3 ) ;
}
static void F_196 ( struct V_1 * V_3 )
{
struct V_55 * V_19 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
V_3 -> V_186 -> V_189 [ V_19 -> V_234 ] -= 1 ;
V_3 -> V_186 -> V_295 -= 1 ;
V_3 -> V_186 = NULL ;
F_8 ( & V_3 -> V_261 ) ;
F_193 ( V_3 -> V_2 ) ;
F_116 ( V_3 ) ;
}
static int F_197 ( struct V_1 * V_3 ,
struct V_185 * V_186 )
{
int V_30 ;
F_198 ( & V_186 -> V_176 ) ;
if ( V_3 -> V_51 != NULL ) {
struct V_1 * V_51 = V_3 -> V_51 ;
V_30 = - V_209 ;
if ( V_51 -> V_186 != NULL &&
V_51 -> V_186 != V_186 )
goto V_10;
if ( V_3 -> V_186 != NULL &&
V_3 -> V_186 != V_186 )
goto V_10;
if ( V_51 -> V_186 == NULL )
F_195 ( V_51 , V_186 ) ;
F_199 ( & V_51 -> V_6 ) ;
}
if ( V_3 -> V_186 == NULL )
F_195 ( V_3 , V_186 ) ;
F_199 ( & V_3 -> V_6 ) ;
V_30 = 0 ;
V_10:
F_200 ( & V_186 -> V_176 ) ;
return V_30 ;
}
static void F_201 ( struct V_13 * V_14 )
{
F_202 ( V_14 ) ;
F_203 ( V_14 ) ;
F_204 ( V_14 ) ;
}
static int F_205 ( struct V_13 * V_14 )
{
T_1 V_296 ;
int V_25 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( ! V_25 )
return - V_208 ;
F_206 ( V_14 , V_25 + V_297 , & V_296 ) ;
V_296 |= V_298 ;
F_207 ( V_14 , V_25 + V_297 , V_296 ) ;
return 0 ;
}
static int F_208 ( struct V_13 * V_14 )
{
bool V_299 ;
int V_300 , V_30 ;
V_300 = 32 ;
if ( F_20 ( V_14 , V_301 ) )
V_300 = 1 ;
V_299 = F_20 ( V_14 , V_302 ) ;
V_30 = F_209 ( V_14 , 0 ) ;
if ( V_30 )
goto V_303;
V_30 = F_210 ( V_14 ) ;
if ( V_30 )
goto V_303;
V_30 = F_211 ( V_14 , V_300 ) ;
if ( V_30 )
goto V_303;
if ( V_299 ) {
V_30 = F_205 ( V_14 ) ;
if ( V_30 )
goto V_303;
}
V_30 = F_212 ( V_14 , V_228 ) ;
if ( V_30 )
goto V_303;
return 0 ;
V_303:
F_203 ( V_14 ) ;
F_204 ( V_14 ) ;
return V_30 ;
}
static bool F_213 ( struct V_13 * V_14 )
{
T_1 V_136 ;
int V_25 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( ! V_25 )
return false ;
F_206 ( V_14 , V_25 + V_304 , & V_136 ) ;
return ( V_136 & V_305 ) ? true : false ;
}
static int F_214 ( struct V_11 * V_12 ,
struct V_185 * V_186 )
{
struct V_13 * V_14 = F_15 ( V_12 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_30 ;
V_3 = F_17 ( V_12 ) ;
if ( V_186 -> V_4 & V_287 ) {
if ( ! V_3 -> V_56 || ! V_3 -> V_306 )
return - V_208 ;
if ( F_208 ( V_14 ) != 0 )
return - V_208 ;
V_3 -> V_183 . V_184 = true ;
V_3 -> V_183 . V_161 = F_215 ( V_14 ) ;
V_3 -> V_307 = F_213 ( V_14 ) ;
} else if ( V_308 &&
F_212 ( V_14 , V_228 ) == 0 ) {
V_3 -> V_183 . V_184 = true ;
V_3 -> V_183 . V_161 = F_215 ( V_14 ) ;
}
F_169 ( & V_263 , V_4 ) ;
V_30 = F_197 ( V_3 , V_186 ) ;
F_171 ( & V_263 , V_4 ) ;
F_120 ( V_186 ) ;
return V_30 ;
}
static void F_216 ( struct V_1 * V_3 )
{
struct V_185 * V_186 ;
unsigned long V_4 ;
F_128 ( ! V_3 -> V_186 ) ;
V_186 = V_3 -> V_186 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
if ( V_3 -> V_51 != NULL ) {
struct V_1 * V_51 = V_3 -> V_51 ;
if ( F_217 ( & V_51 -> V_6 ) )
F_196 ( V_51 ) ;
}
if ( F_217 ( & V_3 -> V_6 ) )
F_196 ( V_3 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
if ( V_3 -> V_306 &&
( V_3 -> V_186 == NULL && V_186 != V_309 ) )
F_197 ( V_3 , V_309 ) ;
}
static void F_218 ( struct V_11 * V_12 )
{
struct V_185 * V_186 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_17 ( V_12 ) ;
V_186 = V_3 -> V_186 ;
F_169 ( & V_263 , V_4 ) ;
F_216 ( V_3 ) ;
F_171 ( & V_263 , V_4 ) ;
if ( V_186 -> V_4 & V_287 )
F_201 ( F_15 ( V_12 ) ) ;
else if ( V_3 -> V_183 . V_184 )
F_202 ( F_15 ( V_12 ) ) ;
V_3 -> V_183 . V_184 = false ;
}
static struct V_185 * F_219 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_185 * V_204 = NULL ;
unsigned long V_4 ;
V_3 = F_17 ( V_12 ) ;
if ( V_3 -> V_186 )
return V_3 -> V_186 ;
if ( V_3 -> V_51 != NULL ) {
struct V_1 * V_51 = V_3 -> V_51 ;
F_220 ( & V_263 , V_4 ) ;
if ( V_51 -> V_186 != NULL ) {
F_197 ( V_3 , V_51 -> V_186 ) ;
V_204 = V_51 -> V_186 ;
}
F_221 ( & V_263 , V_4 ) ;
}
return V_204 ;
}
static int F_222 ( struct V_310 * V_311 ,
unsigned long V_312 , void * V_86 )
{
struct V_28 * V_313 ;
struct V_185 * V_186 ;
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
switch ( V_312 ) {
case V_314 :
V_186 = F_219 ( V_12 ) ;
if ( ! V_186 )
goto V_315;
if ( V_3 -> V_306 )
break;
F_218 ( V_12 ) ;
break;
case V_316 :
F_48 ( V_12 ) ;
V_3 = F_17 ( V_12 ) ;
if ( V_317 || V_3 -> V_56 ) {
V_3 -> V_306 = true ;
F_214 ( V_12 , V_309 ) ;
break;
}
V_186 = F_219 ( V_12 ) ;
V_313 = F_21 ( V_2 ) ;
if ( ! V_313 ) {
V_313 = F_186 () ;
if ( ! V_313 )
goto V_315;
V_313 -> V_35 = V_2 ;
F_4 ( & V_34 , V_4 ) ;
F_5 ( & V_313 -> V_261 , & V_33 ) ;
F_6 ( & V_34 , V_4 ) ;
}
V_12 -> V_18 . V_318 = & V_319 ;
break;
case V_320 :
F_52 ( V_12 ) ;
default:
goto V_315;
}
F_106 ( V_19 ) ;
V_315:
return 0 ;
}
void F_223 ( void )
{
F_224 ( & V_37 , & V_321 ) ;
}
static struct V_185 * F_225 ( struct V_11 * V_12 )
{
struct V_185 * V_186 ;
struct V_28 * V_222 ;
T_1 V_2 = F_14 ( V_12 ) ;
if ( ! F_23 ( V_12 ) )
return F_26 ( - V_208 ) ;
V_186 = F_219 ( V_12 ) ;
if ( V_186 != NULL && ! V_28 ( V_186 ) )
return F_26 ( - V_209 ) ;
if ( V_186 != NULL )
return V_186 ;
V_222 = F_21 ( V_2 ) ;
if ( ! V_222 )
V_222 = V_39 [ V_2 ] -> V_231 ;
F_214 ( V_12 , & V_222 -> V_186 ) ;
F_226 ( L_25 ,
V_222 -> V_186 . V_187 , F_50 ( V_12 ) ) ;
return & V_222 -> V_186 ;
}
static void F_227 ( struct V_185 * V_186 )
{
struct V_1 * V_3 ;
F_12 (dev_data, &domain->dev_list, list)
F_189 ( V_3 -> V_2 , V_186 , V_3 -> V_183 . V_184 ) ;
}
static void F_144 ( struct V_185 * V_186 )
{
if ( ! V_186 -> V_196 )
return;
F_227 ( V_186 ) ;
F_122 ( V_186 ) ;
F_120 ( V_186 ) ;
V_186 -> V_196 = false ;
}
static T_5 * F_228 ( struct V_28 * V_204 ,
unsigned long V_94 )
{
struct V_240 * V_229 ;
T_5 * V_192 , * V_198 ;
V_229 = V_204 -> V_229 [ F_229 ( V_94 ) ] ;
if ( ! V_229 )
return NULL ;
V_192 = V_229 -> V_243 [ F_230 ( V_94 ) ] ;
if ( ! V_192 ) {
V_192 = F_127 ( & V_204 -> V_186 , V_94 , V_155 , & V_198 ,
V_322 ) ;
V_229 -> V_243 [ F_230 ( V_94 ) ] = V_198 ;
} else
V_192 += F_131 ( 0 , V_94 ) ;
F_144 ( & V_204 -> V_186 ) ;
return V_192 ;
}
static T_9 F_231 ( struct V_28 * V_204 ,
unsigned long V_94 ,
T_10 V_323 ,
int V_324 )
{
T_5 * V_192 , V_203 ;
F_42 ( V_94 > V_204 -> V_227 ) ;
V_323 &= V_157 ;
V_192 = F_228 ( V_204 , V_94 ) ;
if ( ! V_192 )
return V_258 ;
V_203 = V_323 | V_210 | V_211 ;
if ( V_324 == V_325 )
V_203 |= V_213 ;
else if ( V_324 == V_326 )
V_203 |= V_215 ;
else if ( V_324 == V_327 )
V_203 |= V_213 | V_215 ;
F_42 ( * V_192 ) ;
* V_192 = V_203 ;
return ( T_9 ) V_94 ;
}
static void F_232 ( struct V_28 * V_204 ,
unsigned long V_94 )
{
struct V_240 * V_229 ;
T_5 * V_192 ;
if ( V_94 >= V_204 -> V_227 )
return;
V_229 = V_204 -> V_229 [ F_229 ( V_94 ) ] ;
if ( ! V_229 )
return;
V_192 = V_229 -> V_243 [ F_230 ( V_94 ) ] ;
if ( ! V_192 )
return;
V_192 += F_131 ( 0 , V_94 ) ;
F_42 ( ! * V_192 ) ;
* V_192 = 0ULL ;
}
static T_9 F_233 ( struct V_11 * V_12 ,
struct V_28 * V_222 ,
T_10 V_323 ,
T_7 V_151 ,
int V_328 ,
bool V_329 ,
T_5 V_36 )
{
T_9 V_241 = V_323 & ~ V_157 ;
T_9 V_94 , V_251 , V_30 ;
unsigned int V_153 ;
unsigned long V_250 = 0 ;
int V_24 ;
V_153 = F_97 ( V_323 , V_151 , V_155 ) ;
V_323 &= V_157 ;
F_75 ( V_81 ) ;
if ( V_153 > 1 )
F_75 ( V_77 ) ;
if ( V_329 )
V_250 = ( 1UL << F_234 ( V_151 ) ) - 1 ;
V_95:
V_94 = F_161 ( V_12 , V_222 , V_153 , V_250 ,
V_36 ) ;
if ( F_162 ( V_94 == V_258 ) ) {
V_222 -> V_253 = V_222 -> V_227 ;
if ( F_152 ( V_222 , false , V_322 ) )
goto V_315;
goto V_95;
}
V_251 = V_94 ;
for ( V_24 = 0 ; V_24 < V_153 ; ++ V_24 ) {
V_30 = F_231 ( V_222 , V_251 , V_323 , V_328 ) ;
if ( V_30 == V_258 )
goto V_330;
V_323 += V_155 ;
V_251 += V_155 ;
}
V_94 += V_241 ;
F_235 ( V_80 , V_151 ) ;
if ( F_162 ( V_222 -> V_257 && ! V_69 ) ) {
F_119 ( & V_222 -> V_186 ) ;
V_222 -> V_257 = false ;
} else if ( F_162 ( V_331 ) )
F_118 ( & V_222 -> V_186 , V_94 , V_151 ) ;
V_315:
return V_94 ;
V_330:
for ( -- V_24 ; V_24 >= 0 ; -- V_24 ) {
V_251 -= V_155 ;
F_232 ( V_222 , V_251 ) ;
}
F_163 ( V_222 , V_94 , V_153 ) ;
return V_258 ;
}
static void F_236 ( struct V_28 * V_222 ,
T_9 V_332 ,
T_7 V_151 ,
int V_328 )
{
T_9 V_333 ;
T_9 V_24 , V_251 ;
unsigned int V_153 ;
if ( ( V_332 == V_258 ) ||
( V_332 + V_151 > V_222 -> V_227 ) )
return;
V_333 = V_332 ;
V_153 = F_97 ( V_332 , V_151 , V_155 ) ;
V_332 &= V_157 ;
V_251 = V_332 ;
for ( V_24 = 0 ; V_24 < V_153 ; ++ V_24 ) {
F_232 ( V_222 , V_251 ) ;
V_251 += V_155 ;
}
F_237 ( V_80 , V_151 ) ;
F_163 ( V_222 , V_332 , V_153 ) ;
if ( V_69 || V_222 -> V_257 ) {
F_118 ( & V_222 -> V_186 , V_333 , V_151 ) ;
V_222 -> V_257 = false ;
}
}
static T_9 F_238 ( struct V_11 * V_12 , struct V_201 * V_201 ,
unsigned long V_241 , T_7 V_151 ,
enum V_334 V_328 ,
struct V_335 * V_336 )
{
unsigned long V_4 ;
struct V_185 * V_186 ;
T_9 V_224 ;
T_5 V_36 ;
T_10 V_323 = F_239 ( V_201 ) + V_241 ;
F_75 ( V_71 ) ;
V_186 = F_225 ( V_12 ) ;
if ( F_41 ( V_186 ) == - V_208 )
return ( T_9 ) V_323 ;
else if ( F_35 ( V_186 ) )
return V_258 ;
V_36 = * V_12 -> V_36 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
V_224 = F_233 ( V_12 , V_186 -> V_281 , V_323 , V_151 , V_328 , false ,
V_36 ) ;
if ( V_224 == V_258 )
goto V_315;
F_121 ( V_186 ) ;
V_315:
F_6 ( & V_186 -> V_176 , V_4 ) ;
return V_224 ;
}
static void F_240 ( struct V_11 * V_12 , T_9 V_332 , T_7 V_151 ,
enum V_334 V_328 , struct V_335 * V_336 )
{
unsigned long V_4 ;
struct V_185 * V_186 ;
F_75 ( V_72 ) ;
V_186 = F_225 ( V_12 ) ;
if ( F_35 ( V_186 ) )
return;
F_4 ( & V_186 -> V_176 , V_4 ) ;
F_236 ( V_186 -> V_281 , V_332 , V_151 , V_328 ) ;
F_121 ( V_186 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
}
static int F_241 ( struct V_11 * V_12 , struct V_337 * V_338 ,
int V_339 , enum V_334 V_328 ,
struct V_335 * V_336 )
{
unsigned long V_4 ;
struct V_185 * V_186 ;
int V_24 ;
struct V_337 * V_154 ;
T_10 V_323 ;
int V_340 = 0 ;
T_5 V_36 ;
F_75 ( V_73 ) ;
V_186 = F_225 ( V_12 ) ;
if ( F_35 ( V_186 ) )
return 0 ;
V_36 = * V_12 -> V_36 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
F_242 (sglist, s, nelems, i) {
V_323 = F_243 ( V_154 ) ;
V_154 -> V_341 = F_233 ( V_12 , V_186 -> V_281 ,
V_323 , V_154 -> V_342 , V_328 , false ,
V_36 ) ;
if ( V_154 -> V_341 ) {
V_154 -> V_343 = V_154 -> V_342 ;
V_340 ++ ;
} else
goto V_344;
}
F_121 ( V_186 ) ;
V_315:
F_6 ( & V_186 -> V_176 , V_4 ) ;
return V_340 ;
V_344:
F_242 (sglist, s, mapped_elems, i) {
if ( V_154 -> V_341 )
F_236 ( V_186 -> V_281 , V_154 -> V_341 ,
V_154 -> V_343 , V_328 ) ;
V_154 -> V_341 = V_154 -> V_343 = 0 ;
}
V_340 = 0 ;
goto V_315;
}
static void F_244 ( struct V_11 * V_12 , struct V_337 * V_338 ,
int V_339 , enum V_334 V_328 ,
struct V_335 * V_336 )
{
unsigned long V_4 ;
struct V_185 * V_186 ;
struct V_337 * V_154 ;
int V_24 ;
F_75 ( V_74 ) ;
V_186 = F_225 ( V_12 ) ;
if ( F_35 ( V_186 ) )
return;
F_4 ( & V_186 -> V_176 , V_4 ) ;
F_242 (sglist, s, nelems, i) {
F_236 ( V_186 -> V_281 , V_154 -> V_341 ,
V_154 -> V_343 , V_328 ) ;
V_154 -> V_341 = V_154 -> V_343 = 0 ;
}
F_121 ( V_186 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
}
static void * F_245 ( struct V_11 * V_12 , T_7 V_151 ,
T_9 * V_332 , T_8 V_345 ,
struct V_335 * V_336 )
{
unsigned long V_4 ;
void * V_346 ;
struct V_185 * V_186 ;
T_10 V_323 ;
T_5 V_36 = V_12 -> V_347 ;
F_75 ( V_75 ) ;
V_186 = F_225 ( V_12 ) ;
if ( F_41 ( V_186 ) == - V_208 ) {
V_346 = ( void * ) F_246 ( V_345 , F_234 ( V_151 ) ) ;
* V_332 = F_92 ( V_346 ) ;
return V_346 ;
} else if ( F_35 ( V_186 ) )
return NULL ;
V_36 = V_12 -> V_347 ;
V_345 &= ~ ( V_348 | V_349 | V_350 ) ;
V_345 |= V_351 ;
V_346 = ( void * ) F_246 ( V_345 , F_234 ( V_151 ) ) ;
if ( ! V_346 )
return NULL ;
V_323 = F_126 ( V_346 ) ;
if ( ! V_36 )
V_36 = * V_12 -> V_36 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
* V_332 = F_233 ( V_12 , V_186 -> V_281 , V_323 ,
V_151 , V_327 , true , V_36 ) ;
if ( * V_332 == V_258 ) {
F_6 ( & V_186 -> V_176 , V_4 ) ;
goto V_61;
}
F_121 ( V_186 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
return V_346 ;
V_61:
F_247 ( ( unsigned long ) V_346 , F_234 ( V_151 ) ) ;
return NULL ;
}
static void F_248 ( struct V_11 * V_12 , T_7 V_151 ,
void * V_346 , T_9 V_332 ,
struct V_335 * V_336 )
{
unsigned long V_4 ;
struct V_185 * V_186 ;
F_75 ( V_76 ) ;
V_186 = F_225 ( V_12 ) ;
if ( F_35 ( V_186 ) )
goto V_352;
F_4 ( & V_186 -> V_176 , V_4 ) ;
F_236 ( V_186 -> V_281 , V_332 , V_151 , V_327 ) ;
F_121 ( V_186 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
V_352:
F_247 ( ( unsigned long ) V_346 , F_234 ( V_151 ) ) ;
}
static int F_249 ( struct V_11 * V_12 , T_5 V_353 )
{
return F_23 ( V_12 ) ;
}
static void T_4 F_250 ( void )
{
struct V_1 * V_3 ;
struct V_28 * V_222 ;
struct V_13 * V_12 = NULL ;
T_1 V_2 ;
F_55 (dev) {
if ( ! F_23 ( & V_12 -> V_12 ) )
continue;
V_3 = F_17 ( & V_12 -> V_12 ) ;
if ( ! V_354 && V_3 -> V_56 ) {
F_251 () ;
V_3 -> V_306 = true ;
F_214 ( & V_12 -> V_12 , V_309 ) ;
F_252 ( L_26 ,
F_50 ( & V_12 -> V_12 ) ) ;
}
if ( F_219 ( & V_12 -> V_12 ) )
continue;
V_2 = F_14 ( & V_12 -> V_12 ) ;
V_222 = F_186 () ;
if ( ! V_222 )
continue;
F_150 ( V_222 , V_2 ) ;
V_222 -> V_35 = V_2 ;
F_214 ( & V_12 -> V_12 , & V_222 -> V_186 ) ;
F_5 ( & V_222 -> V_261 , & V_33 ) ;
}
}
static unsigned F_253 ( void )
{
struct V_1 * V_3 ;
struct V_13 * V_14 = NULL ;
unsigned V_355 = 0 ;
F_55 (pdev) {
if ( ! F_23 ( & V_14 -> V_12 ) ) {
F_51 ( & V_14 -> V_12 ) ;
V_355 += 1 ;
continue;
}
V_3 = F_17 ( & V_14 -> V_12 ) ;
if ( ! V_3 -> V_306 )
V_14 -> V_12 . V_18 . V_318 = & V_319 ;
else
V_14 -> V_12 . V_18 . V_318 = & V_356 ;
}
return V_355 ;
}
void T_4 F_254 ( void )
{
F_255 ( & V_37 , & V_357 ) ;
}
int T_4 F_256 ( void )
{
struct V_55 * V_19 ;
int V_30 , V_355 ;
F_154 (iommu) {
V_19 -> V_231 = F_186 () ;
if ( V_19 -> V_231 == NULL )
return - V_50 ;
V_19 -> V_231 -> V_186 . V_4 |= V_358 ;
V_30 = F_149 ( V_19 ) ;
if ( V_30 )
goto V_359;
}
F_250 () ;
V_360 = 1 ;
V_361 = 0 ;
V_355 = F_253 () ;
if ( V_355 && V_362 > V_363 ) {
V_361 = 1 ;
}
F_60 () ;
if ( V_69 )
F_252 ( L_27 ) ;
else
F_252 ( L_28 ) ;
return 0 ;
V_359:
F_154 (iommu) {
F_185 ( V_19 -> V_231 ) ;
}
return V_30 ;
}
static void F_257 ( struct V_185 * V_186 )
{
struct V_1 * V_3 , * V_364 ;
unsigned long V_4 ;
F_169 ( & V_263 , V_4 ) ;
F_56 (dev_data, next, &domain->dev_list, list) {
F_216 ( V_3 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
}
F_171 ( & V_263 , V_4 ) ;
}
static void F_258 ( struct V_185 * V_186 )
{
if ( ! V_186 )
return;
F_167 ( V_186 ) ;
if ( V_186 -> V_187 )
F_172 ( V_186 -> V_187 ) ;
F_10 ( V_186 ) ;
}
static struct V_185 * F_259 ( void )
{
struct V_185 * V_186 ;
V_186 = F_2 ( sizeof( * V_186 ) , V_5 ) ;
if ( ! V_186 )
return NULL ;
F_187 ( & V_186 -> V_176 ) ;
F_260 ( & V_186 -> V_365 ) ;
V_186 -> V_187 = F_168 () ;
if ( ! V_186 -> V_187 )
goto V_303;
F_188 ( & V_186 -> V_279 ) ;
F_165 ( V_186 ) ;
return V_186 ;
V_303:
F_10 ( V_186 ) ;
return NULL ;
}
static int T_4 F_251 ( void )
{
if ( V_309 != NULL )
return 0 ;
V_309 = F_259 () ;
if ( ! V_309 )
return - V_50 ;
V_309 -> V_193 = V_267 ;
return 0 ;
}
static int F_261 ( struct V_366 * V_204 )
{
struct V_185 * V_186 ;
V_186 = F_259 () ;
if ( ! V_186 )
goto V_61;
V_186 -> V_193 = V_270 ;
V_186 -> V_195 = ( void * ) F_124 ( V_5 ) ;
if ( ! V_186 -> V_195 )
goto V_61;
V_186 -> V_366 = V_204 ;
V_204 -> V_281 = V_186 ;
V_204 -> V_367 . V_368 = 0 ;
V_204 -> V_367 . V_369 = ~ 0ULL ;
V_204 -> V_367 . V_370 = true ;
return 0 ;
V_61:
F_258 ( V_186 ) ;
return - V_50 ;
}
static void F_262 ( struct V_366 * V_204 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
if ( ! V_186 )
return;
if ( V_186 -> V_295 > 0 )
F_257 ( V_186 ) ;
F_128 ( V_186 -> V_295 != 0 ) ;
if ( V_186 -> V_193 != V_267 )
F_174 ( V_186 ) ;
if ( V_186 -> V_4 & V_287 )
F_184 ( V_186 ) ;
F_258 ( V_186 ) ;
V_204 -> V_281 = NULL ;
}
static void F_263 ( struct V_366 * V_204 ,
struct V_11 * V_12 )
{
struct V_1 * V_3 = V_12 -> V_18 . V_19 ;
struct V_55 * V_19 ;
T_1 V_2 ;
if ( ! F_23 ( V_12 ) )
return;
V_2 = F_14 ( V_12 ) ;
if ( V_3 -> V_186 != NULL )
F_218 ( V_12 ) ;
V_19 = V_39 [ V_2 ] ;
if ( ! V_19 )
return;
F_106 ( V_19 ) ;
}
static int F_264 ( struct V_366 * V_204 ,
struct V_11 * V_12 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
struct V_1 * V_3 ;
struct V_55 * V_19 ;
int V_30 ;
if ( ! F_23 ( V_12 ) )
return - V_208 ;
V_3 = V_12 -> V_18 . V_19 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
if ( ! V_19 )
return - V_208 ;
if ( V_3 -> V_186 )
F_218 ( V_12 ) ;
V_30 = F_214 ( V_12 , V_186 ) ;
F_106 ( V_19 ) ;
return V_30 ;
}
static int F_265 ( struct V_366 * V_204 , unsigned long V_371 ,
T_10 V_323 , T_7 V_197 , int V_372 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
int V_206 = 0 ;
int V_30 ;
if ( V_186 -> V_193 == V_267 )
return - V_208 ;
if ( V_372 & V_373 )
V_206 |= V_212 ;
if ( V_372 & V_374 )
V_206 |= V_214 ;
F_266 ( & V_186 -> V_365 ) ;
V_30 = F_140 ( V_186 , V_371 , V_323 , V_206 , V_197 ) ;
F_267 ( & V_186 -> V_365 ) ;
return V_30 ;
}
static T_7 F_268 ( struct V_366 * V_204 , unsigned long V_371 ,
T_7 V_197 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
T_7 V_216 ;
if ( V_186 -> V_193 == V_267 )
return - V_208 ;
F_266 ( & V_186 -> V_365 ) ;
V_216 = F_145 ( V_186 , V_371 , V_197 ) ;
F_267 ( & V_186 -> V_365 ) ;
F_120 ( V_186 ) ;
return V_216 ;
}
static T_10 F_269 ( struct V_366 * V_204 ,
T_9 V_371 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
unsigned long V_375 ;
T_10 V_323 ;
T_5 * V_192 , V_203 ;
if ( V_186 -> V_193 == V_267 )
return V_371 ;
V_192 = F_137 ( V_186 , V_371 ) ;
if ( ! V_192 || ! F_134 ( * V_192 ) )
return 0 ;
if ( F_135 ( * V_192 ) == 0 )
V_375 = V_155 - 1 ;
else
V_375 = F_138 ( * V_192 ) - 1 ;
V_203 = * V_192 & V_376 ;
V_323 = ( V_203 & ~ V_375 ) | ( V_371 & V_375 ) ;
return V_323 ;
}
static int F_270 ( struct V_366 * V_186 ,
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
int T_4 F_271 ( void )
{
struct V_1 * V_3 ;
struct V_13 * V_12 = NULL ;
struct V_55 * V_19 ;
T_1 V_2 ;
int V_30 ;
V_30 = F_251 () ;
if ( V_30 )
return V_30 ;
F_55 (dev) {
if ( ! F_23 ( & V_12 -> V_12 ) )
continue;
V_3 = F_17 ( & V_12 -> V_12 ) ;
V_3 -> V_306 = true ;
V_2 = F_14 ( & V_12 -> V_12 ) ;
V_19 = V_39 [ V_2 ] ;
if ( ! V_19 )
continue;
F_214 ( & V_12 -> V_12 , V_309 ) ;
}
F_60 () ;
F_252 ( L_29 ) ;
return 0 ;
}
int F_272 ( struct V_310 * V_311 )
{
return F_273 ( & V_129 , V_311 ) ;
}
int F_274 ( struct V_310 * V_311 )
{
return F_275 ( & V_129 , V_311 ) ;
}
void F_276 ( struct V_366 * V_204 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
unsigned long V_4 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
V_186 -> V_193 = V_267 ;
V_186 -> V_196 = true ;
F_144 ( V_186 ) ;
F_174 ( V_186 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
}
int F_277 ( struct V_366 * V_204 , int V_381 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
unsigned long V_4 ;
int V_382 , V_30 ;
if ( V_381 <= 0 || V_381 > ( V_163 + 1 ) )
return - V_208 ;
for ( V_382 = 0 ; ( V_381 - 1 ) & ~ 0x1ff ; V_381 >>= 9 )
V_382 += 1 ;
if ( V_382 > V_383 )
return - V_208 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
V_30 = - V_209 ;
if ( V_186 -> V_295 > 0 || V_186 -> V_4 & V_287 )
goto V_315;
V_30 = - V_50 ;
V_186 -> V_277 = ( void * ) F_124 ( V_322 ) ;
if ( V_186 -> V_277 == NULL )
goto V_315;
V_186 -> V_276 = V_382 ;
V_186 -> V_4 |= V_287 ;
V_186 -> V_196 = true ;
F_144 ( V_186 ) ;
V_30 = 0 ;
V_315:
F_6 ( & V_186 -> V_176 , V_4 ) ;
return V_30 ;
}
static int F_278 ( struct V_185 * V_186 , int V_126 ,
T_5 V_94 , bool V_151 )
{
struct V_1 * V_3 ;
struct V_88 V_89 ;
int V_24 , V_30 ;
if ( ! ( V_186 -> V_4 & V_287 ) )
return - V_208 ;
F_99 ( & V_89 , V_186 -> V_187 , V_126 , V_94 , V_151 ) ;
for ( V_24 = 0 ; V_24 < V_188 ; ++ V_24 ) {
if ( V_186 -> V_189 [ V_24 ] == 0 )
continue;
V_30 = F_105 ( V_190 [ V_24 ] , & V_89 ) ;
if ( V_30 != 0 )
goto V_315;
}
F_121 ( V_186 ) ;
F_12 (dev_data, &domain->dev_list, list) {
struct V_55 * V_19 ;
int V_161 ;
F_128 ( ! V_3 -> V_183 . V_184 ) ;
V_161 = V_3 -> V_183 . V_161 ;
V_19 = V_39 [ V_3 -> V_2 ] ;
F_100 ( & V_89 , V_3 -> V_2 , V_126 ,
V_161 , V_94 , V_151 ) ;
V_30 = F_105 ( V_19 , & V_89 ) ;
if ( V_30 != 0 )
goto V_315;
}
F_121 ( V_186 ) ;
V_30 = 0 ;
V_315:
return V_30 ;
}
static int F_279 ( struct V_185 * V_186 , int V_126 ,
T_5 V_94 )
{
F_75 ( V_83 ) ;
return F_278 ( V_186 , V_126 , V_94 , false ) ;
}
int F_280 ( struct V_366 * V_204 , int V_126 ,
T_5 V_94 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
V_30 = F_279 ( V_186 , V_126 , V_94 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
return V_30 ;
}
static int F_281 ( struct V_185 * V_186 , int V_126 )
{
F_75 ( V_84 ) ;
return F_278 ( V_186 , V_126 , V_156 ,
true ) ;
}
int F_282 ( struct V_366 * V_204 , int V_126 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
V_30 = F_281 ( V_186 , V_126 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
return V_30 ;
}
static T_5 * F_283 ( T_5 * V_266 , int V_199 , int V_126 , bool V_384 )
{
int V_234 ;
T_5 * V_192 ;
while ( true ) {
V_234 = ( V_126 >> ( 9 * V_199 ) ) & 0x1ff ;
V_192 = & V_266 [ V_234 ] ;
if ( V_199 == 0 )
break;
if ( ! ( * V_192 & V_275 ) ) {
if ( ! V_384 )
return NULL ;
V_266 = ( void * ) F_124 ( V_322 ) ;
if ( V_266 == NULL )
return NULL ;
* V_192 = F_92 ( V_266 ) | V_275 ;
}
V_266 = F_182 ( * V_192 & V_157 ) ;
V_199 -= 1 ;
}
return V_192 ;
}
static int F_284 ( struct V_185 * V_186 , int V_126 ,
unsigned long V_385 )
{
T_5 * V_192 ;
if ( V_186 -> V_193 != V_267 )
return - V_208 ;
V_192 = F_283 ( V_186 -> V_277 , V_186 -> V_276 , V_126 , true ) ;
if ( V_192 == NULL )
return - V_50 ;
* V_192 = ( V_385 & V_157 ) | V_275 ;
return F_281 ( V_186 , V_126 ) ;
}
static int F_285 ( struct V_185 * V_186 , int V_126 )
{
T_5 * V_192 ;
if ( V_186 -> V_193 != V_267 )
return - V_208 ;
V_192 = F_283 ( V_186 -> V_277 , V_186 -> V_276 , V_126 , false ) ;
if ( V_192 == NULL )
return 0 ;
* V_192 = 0 ;
return F_281 ( V_186 , V_126 ) ;
}
int F_286 ( struct V_366 * V_204 , int V_126 ,
unsigned long V_385 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
V_30 = F_284 ( V_186 , V_126 , V_385 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
return V_30 ;
}
int F_287 ( struct V_366 * V_204 , int V_126 )
{
struct V_185 * V_186 = V_204 -> V_281 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_186 -> V_176 , V_4 ) ;
V_30 = F_285 ( V_186 , V_126 ) ;
F_6 ( & V_186 -> V_176 , V_4 ) ;
return V_30 ;
}
int F_288 ( struct V_13 * V_14 , int V_126 ,
int V_136 , int V_128 )
{
struct V_1 * V_3 ;
struct V_55 * V_19 ;
struct V_88 V_89 ;
F_75 ( V_82 ) ;
V_3 = F_17 ( & V_14 -> V_12 ) ;
V_19 = V_39 [ V_3 -> V_2 ] ;
F_101 ( & V_89 , V_3 -> V_2 , V_126 , V_136 ,
V_128 , V_3 -> V_307 ) ;
return F_105 ( V_19 , & V_89 ) ;
}
struct V_366 * F_289 ( struct V_13 * V_14 )
{
struct V_185 * V_186 ;
V_186 = F_225 ( & V_14 -> V_12 ) ;
if ( F_35 ( V_186 ) )
return NULL ;
if ( ! ( V_186 -> V_4 & V_287 ) )
return NULL ;
return V_186 -> V_366 ;
}
void F_290 ( struct V_13 * V_14 , T_2 V_26 )
{
struct V_1 * V_3 ;
if ( ! F_291 () )
return;
V_3 = F_17 ( & V_14 -> V_12 ) ;
V_3 -> V_27 |= ( 1 << V_26 ) ;
}
int F_292 ( struct V_13 * V_14 ,
struct F_292 * V_386 )
{
int V_387 ;
int V_25 ;
if ( V_14 == NULL || V_386 == NULL )
return - V_208 ;
if ( ! F_291 () )
return - V_208 ;
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
V_387 = 1 << ( 9 * ( V_383 + 1 ) ) ;
V_387 = F_293 ( V_387 , ( 1 << 20 ) ) ;
V_386 -> V_4 |= V_391 ;
V_386 -> V_387 = F_293 ( F_294 ( V_14 ) , V_387 ) ;
V_390 = F_295 ( V_14 ) ;
if ( V_390 & V_392 )
V_386 -> V_4 |= V_393 ;
if ( V_390 & V_394 )
V_386 -> V_4 |= V_395 ;
}
return 0 ;
}
static void F_296 ( T_1 V_2 , struct V_396 * V_397 )
{
T_5 V_398 ;
V_398 = V_58 [ V_2 ] . V_86 [ 2 ] ;
V_398 &= ~ V_399 ;
V_398 |= F_126 ( V_397 -> V_397 ) ;
V_398 |= V_400 ;
V_398 |= V_401 ;
V_398 |= V_402 ;
V_58 [ V_2 ] . V_86 [ 2 ] = V_398 ;
}
static struct V_396 * F_297 ( T_1 V_2 , bool V_403 )
{
struct V_396 * V_397 = NULL ;
struct V_55 * V_19 ;
unsigned long V_4 ;
T_1 V_31 ;
F_169 ( & V_263 , V_4 ) ;
V_19 = V_39 [ V_2 ] ;
if ( ! V_19 )
goto V_10;
V_397 = V_404 [ V_2 ] ;
if ( V_397 )
goto V_315;
V_31 = V_32 [ V_2 ] ;
V_397 = V_404 [ V_31 ] ;
if ( V_397 ) {
V_404 [ V_2 ] = V_397 ;
F_296 ( V_2 , V_397 ) ;
F_107 ( V_19 , V_2 ) ;
goto V_315;
}
V_397 = F_2 ( sizeof( * V_397 ) , V_322 ) ;
if ( ! V_397 )
goto V_315;
F_187 ( & V_397 -> V_176 ) ;
if ( V_403 )
V_397 -> V_405 = 32 ;
V_397 -> V_397 = F_298 ( V_406 , V_322 ) ;
if ( ! V_397 -> V_397 ) {
F_10 ( V_397 ) ;
V_397 = NULL ;
goto V_315;
}
memset ( V_397 -> V_397 , 0 , V_407 * sizeof( T_2 ) ) ;
if ( V_403 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < 32 ; ++ V_24 )
V_397 -> V_397 [ V_24 ] = V_408 ;
}
V_404 [ V_2 ] = V_397 ;
F_296 ( V_2 , V_397 ) ;
F_107 ( V_19 , V_2 ) ;
if ( V_2 != V_31 ) {
V_404 [ V_31 ] = V_397 ;
F_296 ( V_2 , V_397 ) ;
F_107 ( V_19 , V_31 ) ;
}
V_315:
F_106 ( V_19 ) ;
V_10:
F_171 ( & V_263 , V_4 ) ;
return V_397 ;
}
static int F_299 ( struct V_409 * V_410 , T_1 V_2 , int V_93 )
{
struct V_396 * V_397 ;
unsigned long V_4 ;
int V_234 , V_411 ;
V_397 = F_297 ( V_2 , false ) ;
if ( ! V_397 )
return - V_43 ;
F_4 ( & V_397 -> V_176 , V_4 ) ;
for ( V_411 = 0 , V_234 = V_397 -> V_405 ;
V_234 < V_407 ;
++ V_234 ) {
if ( V_397 -> V_397 [ V_234 ] == 0 )
V_411 += 1 ;
else
V_411 = 0 ;
if ( V_411 == V_93 ) {
struct V_412 * V_413 ;
for (; V_411 != 0 ; -- V_411 )
V_397 -> V_397 [ V_234 - V_411 + 1 ] = V_408 ;
V_234 -= V_93 - 1 ;
V_410 -> V_414 = 1 ;
V_413 = & V_410 -> V_412 ;
V_413 -> V_2 = V_2 ;
V_413 -> V_234 = V_234 ;
goto V_315;
}
}
V_234 = - V_415 ;
V_315:
F_6 ( & V_397 -> V_176 , V_4 ) ;
return V_234 ;
}
static int F_300 ( T_1 V_2 , int V_234 , union V_416 * V_416 )
{
struct V_396 * V_397 ;
unsigned long V_4 ;
V_397 = F_297 ( V_2 , false ) ;
if ( ! V_397 )
return - V_50 ;
F_4 ( & V_397 -> V_176 , V_4 ) ;
V_416 -> V_417 = V_397 -> V_397 [ V_234 ] ;
F_6 ( & V_397 -> V_176 , V_4 ) ;
return 0 ;
}
static int F_301 ( T_1 V_2 , int V_234 , union V_416 V_416 )
{
struct V_396 * V_397 ;
struct V_55 * V_19 ;
unsigned long V_4 ;
V_19 = V_39 [ V_2 ] ;
if ( V_19 == NULL )
return - V_208 ;
V_397 = F_297 ( V_2 , false ) ;
if ( ! V_397 )
return - V_50 ;
F_4 ( & V_397 -> V_176 , V_4 ) ;
V_397 -> V_397 [ V_234 ] = V_416 . V_417 ;
F_6 ( & V_397 -> V_176 , V_4 ) ;
F_111 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
return 0 ;
}
static void F_302 ( T_1 V_2 , int V_234 )
{
struct V_396 * V_397 ;
struct V_55 * V_19 ;
unsigned long V_4 ;
V_19 = V_39 [ V_2 ] ;
if ( V_19 == NULL )
return;
V_397 = F_297 ( V_2 , false ) ;
if ( ! V_397 )
return;
F_4 ( & V_397 -> V_176 , V_4 ) ;
V_397 -> V_397 [ V_234 ] = 0 ;
F_6 ( & V_397 -> V_176 , V_4 ) ;
F_111 ( V_19 , V_2 ) ;
F_106 ( V_19 ) ;
}
static int F_303 ( int V_135 , struct V_418 * V_29 ,
unsigned int V_419 , int V_420 ,
struct V_421 * V_422 )
{
struct V_396 * V_397 ;
struct V_412 * V_413 ;
struct V_409 * V_410 ;
union V_416 V_416 ;
int V_423 ;
int V_234 ;
int V_2 ;
int V_30 ;
V_410 = F_304 ( V_135 ) ;
if ( ! V_410 )
return - V_208 ;
V_413 = & V_410 -> V_412 ;
V_423 = F_305 ( V_422 -> V_403 ) ;
V_2 = F_306 ( V_423 ) ;
if ( V_2 < 0 )
return V_2 ;
V_397 = F_297 ( V_2 , true ) ;
if ( V_397 == NULL )
return - V_50 ;
V_234 = V_422 -> V_424 ;
V_410 -> V_414 = 1 ;
V_413 -> V_2 = V_2 ;
V_413 -> V_234 = V_234 ;
V_416 . V_417 = 0 ;
V_416 . V_425 . V_420 = V_420 ;
V_416 . V_425 . V_426 = V_427 -> V_428 ;
V_416 . V_425 . V_419 = V_419 ;
V_416 . V_425 . V_429 = V_427 -> V_430 ;
V_416 . V_425 . V_431 = 1 ;
V_30 = F_301 ( V_2 , V_234 , V_416 ) ;
if ( V_30 )
return V_30 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_420 = V_234 ;
V_29 -> V_353 = 0 ;
V_29 -> V_432 = V_422 -> V_432 ;
V_29 -> V_433 = V_422 -> V_433 ;
if ( V_422 -> V_432 )
V_29 -> V_353 = 1 ;
return 0 ;
}
static int F_307 ( struct V_434 * V_86 , const struct V_435 * V_353 ,
bool V_436 )
{
struct V_412 * V_413 ;
unsigned int V_437 , V_135 ;
struct V_409 * V_410 ;
union V_416 V_416 ;
int V_438 ;
if ( ! F_308 ( V_439 ) )
return - 1 ;
V_410 = V_86 -> V_440 ;
V_135 = V_86 -> V_135 ;
V_413 = & V_410 -> V_412 ;
if ( ! F_309 ( V_353 , V_441 ) )
return - V_208 ;
if ( F_300 ( V_413 -> V_2 , V_413 -> V_234 , & V_416 ) )
return - V_209 ;
if ( F_310 ( V_135 , V_410 , V_353 ) )
return - V_209 ;
V_438 = V_427 -> V_442 ( V_410 -> V_186 , V_353 , & V_437 ) ;
if ( V_438 ) {
if ( F_310 ( V_135 , V_410 , V_86 -> V_443 ) )
F_49 ( L_30 , V_135 ) ;
return V_438 ;
}
V_416 . V_425 . V_420 = V_410 -> V_420 ;
V_416 . V_425 . V_419 = V_437 ;
F_301 ( V_413 -> V_2 , V_413 -> V_234 , V_416 ) ;
if ( V_410 -> V_444 )
F_311 ( V_410 ) ;
F_312 ( V_86 -> V_443 , V_353 ) ;
return 0 ;
}
static int F_313 ( int V_135 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
V_410 = F_304 ( V_135 ) ;
if ( ! V_410 )
return - V_208 ;
V_413 = & V_410 -> V_412 ;
F_302 ( V_413 -> V_2 , V_413 -> V_234 ) ;
return 0 ;
}
static void F_314 ( struct V_13 * V_14 ,
unsigned int V_135 , unsigned int V_437 ,
struct V_445 * V_446 , T_3 V_447 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
union V_416 V_416 ;
V_410 = F_304 ( V_135 ) ;
if ( ! V_410 )
return;
V_413 = & V_410 -> V_412 ;
V_416 . V_417 = 0 ;
V_416 . V_425 . V_420 = V_410 -> V_420 ;
V_416 . V_425 . V_426 = V_427 -> V_428 ;
V_416 . V_425 . V_419 = V_437 ;
V_416 . V_425 . V_429 = V_427 -> V_430 ;
V_416 . V_425 . V_431 = 1 ;
F_301 ( V_413 -> V_2 , V_413 -> V_234 , V_416 ) ;
V_446 -> V_448 = V_449 ;
V_446 -> V_450 = V_245 ;
V_446 -> V_86 = V_413 -> V_234 ;
}
static int F_315 ( struct V_13 * V_14 , int V_135 , int V_451 )
{
struct V_409 * V_410 ;
int V_234 ;
T_1 V_2 ;
if ( ! V_14 )
return - V_208 ;
V_410 = F_304 ( V_135 ) ;
if ( ! V_410 )
return - V_208 ;
V_2 = F_14 ( & V_14 -> V_12 ) ;
V_234 = F_299 ( V_410 , V_2 , V_451 ) ;
return V_234 < 0 ? V_407 : V_234 ;
}
static int F_316 ( struct V_13 * V_14 , unsigned int V_135 ,
int V_234 , int V_241 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
T_1 V_2 ;
if ( ! V_14 )
return - V_208 ;
V_410 = F_304 ( V_135 ) ;
if ( ! V_410 )
return - V_208 ;
if ( V_234 >= V_407 )
return 0 ;
V_2 = F_14 ( & V_14 -> V_12 ) ;
V_413 = & V_410 -> V_412 ;
V_410 -> V_414 = 1 ;
V_413 -> V_2 = V_2 ;
V_413 -> V_234 = V_234 + V_241 ;
return 0 ;
}
static int F_317 ( unsigned int V_135 , unsigned int V_187 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
int V_234 , V_2 ;
V_410 = F_304 ( V_135 ) ;
if ( ! V_410 )
return - V_208 ;
V_413 = & V_410 -> V_412 ;
V_2 = F_318 ( V_187 ) ;
if ( V_2 < 0 )
return V_2 ;
V_234 = F_299 ( V_410 , V_2 , 1 ) ;
if ( V_234 < 0 )
return V_234 ;
V_410 -> V_414 = 1 ;
V_413 -> V_2 = V_2 ;
V_413 -> V_234 = V_234 ;
return 0 ;
}
