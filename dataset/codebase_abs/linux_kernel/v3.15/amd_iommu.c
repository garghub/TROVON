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
if ( ! F_24 ( V_12 ) )
return false ;
V_2 = F_14 ( V_12 ) ;
if ( V_2 > V_37 )
return false ;
if ( V_38 [ V_2 ] == NULL )
return false ;
return true ;
}
static struct V_39 * F_25 ( struct V_39 * V_15 )
{
while ( ! V_15 -> V_40 ) {
if ( ! F_26 ( V_15 ) )
V_15 = V_15 -> V_41 ;
else
return F_27 ( - V_42 ) ;
}
return V_15 ;
}
static struct V_13 * F_28 ( struct V_13 * V_14 )
{
struct V_13 * V_43 = V_14 ;
F_29 ( & V_43 , F_30 ( V_43 ) ) ;
if ( V_43 -> V_44 &&
! F_31 ( V_43 , V_45 ) ) {
T_3 V_24 , V_46 = F_32 ( V_43 -> V_17 ) ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
struct V_13 * V_47 ;
V_47 = F_33 ( V_43 -> V_15 , F_34 ( V_46 , V_24 ) ) ;
if ( ! V_47 )
continue;
if ( ! F_31 ( V_47 , V_45 ) ) {
F_29 ( & V_43 , V_47 ) ;
break;
}
F_35 ( V_47 ) ;
}
}
while ( ! F_26 ( V_43 -> V_15 ) ) {
struct V_39 * V_15 = F_25 ( V_43 -> V_15 ) ;
if ( F_36 ( V_15 ) )
break;
if ( F_37 ( V_15 -> V_40 , NULL , V_45 ) )
break;
F_29 ( & V_43 , F_38 ( V_15 -> V_40 ) ) ;
}
return V_43 ;
}
static int F_39 ( struct V_13 * V_14 , struct V_11 * V_12 )
{
struct V_48 * V_9 = F_40 ( & V_14 -> V_12 ) ;
int V_30 ;
if ( ! V_9 ) {
V_9 = F_41 () ;
if ( F_36 ( V_9 ) )
return F_42 ( V_9 ) ;
F_43 ( & V_14 -> V_12 != V_12 ) ;
}
V_30 = F_44 ( V_9 , V_12 ) ;
F_9 ( V_9 ) ;
return V_30 ;
}
static int F_45 ( struct V_1 * V_3 ,
struct V_11 * V_12 )
{
if ( ! V_3 -> V_9 ) {
struct V_48 * V_9 = F_41 () ;
if ( F_36 ( V_9 ) )
return F_42 ( V_9 ) ;
V_3 -> V_9 = V_9 ;
}
return F_44 ( V_3 -> V_9 , V_12 ) ;
}
static int F_46 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_48 * V_9 ;
struct V_13 * V_43 ;
int V_30 ;
V_9 = F_40 ( V_12 ) ;
if ( V_9 ) {
F_9 ( V_9 ) ;
return 0 ;
}
V_3 = F_13 ( F_14 ( V_12 ) ) ;
if ( ! V_3 )
return - V_49 ;
if ( V_3 -> V_50 ) {
T_1 V_31 ;
struct V_39 * V_15 ;
if ( V_3 -> V_50 -> V_9 )
goto V_51;
V_31 = V_32 [ V_3 -> V_2 ] ;
V_43 = F_47 ( V_31 >> 8 , V_31 & 0xff ) ;
if ( V_43 ) {
V_43 = F_28 ( V_43 ) ;
goto V_52;
}
V_15 = F_48 ( 0 , V_31 >> 8 ) ;
if ( ! V_15 )
goto V_51;
V_15 = F_25 ( V_15 ) ;
if ( F_36 ( V_15 ) || ! V_15 -> V_40 )
goto V_51;
V_43 = F_28 ( F_38 ( V_15 -> V_40 ) ) ;
if ( V_43 != V_15 -> V_40 || ( V_43 -> V_44 &&
! F_31 ( V_43 , V_45 ) ) )
goto V_52;
F_35 ( V_43 ) ;
goto V_51;
}
V_43 = F_28 ( F_38 ( F_15 ( V_12 ) ) ) ;
V_52:
V_30 = F_39 ( V_43 , V_12 ) ;
F_35 ( V_43 ) ;
return V_30 ;
V_51:
return F_45 ( V_3 -> V_50 , V_12 ) ;
}
static int F_49 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_15 ( V_12 ) ;
struct V_1 * V_3 ;
T_1 V_31 ;
int V_30 ;
if ( V_12 -> V_18 . V_19 )
return 0 ;
V_3 = F_13 ( F_14 ( V_12 ) ) ;
if ( ! V_3 )
return - V_49 ;
V_31 = V_32 [ V_3 -> V_2 ] ;
if ( V_31 != V_3 -> V_2 ) {
struct V_1 * V_50 ;
V_50 = F_13 ( V_31 ) ;
if ( V_50 == NULL ) {
F_50 ( L_1 ,
F_51 ( V_12 ) ) ;
F_7 ( V_3 ) ;
return - V_53 ;
}
V_3 -> V_50 = V_50 ;
}
V_30 = F_46 ( V_12 ) ;
if ( V_30 ) {
F_7 ( V_3 ) ;
return V_30 ;
}
if ( F_18 ( V_14 ) ) {
struct V_54 * V_19 ;
V_19 = V_38 [ V_3 -> V_2 ] ;
V_3 -> V_55 = V_19 -> V_56 ;
}
V_12 -> V_18 . V_19 = V_3 ;
return 0 ;
}
static void F_52 ( struct V_11 * V_12 )
{
T_1 V_2 , V_31 ;
V_2 = F_14 ( V_12 ) ;
V_31 = V_32 [ V_2 ] ;
memset ( & V_57 [ V_2 ] , 0 , sizeof( struct V_58 ) ) ;
memset ( & V_57 [ V_31 ] , 0 , sizeof( struct V_58 ) ) ;
V_38 [ V_2 ] = NULL ;
V_38 [ V_31 ] = NULL ;
}
static void F_53 ( struct V_11 * V_12 )
{
F_54 ( V_12 ) ;
}
void T_4 F_55 ( void )
{
struct V_1 * V_3 , * V_59 ;
struct V_13 * V_14 = NULL ;
F_56 (pdev) {
if ( ! F_23 ( & V_14 -> V_12 ) )
continue;
F_53 ( & V_14 -> V_12 ) ;
}
F_57 (dev_data, n, &dev_data_list, dev_data_list)
F_7 ( V_3 ) ;
}
int T_4 F_58 ( void )
{
struct V_13 * V_14 = NULL ;
int V_30 = 0 ;
F_56 (pdev) {
if ( ! F_23 ( & V_14 -> V_12 ) )
continue;
V_30 = F_49 ( & V_14 -> V_12 ) ;
if ( V_30 == - V_53 )
F_52 ( & V_14 -> V_12 ) ;
else if ( V_30 )
goto V_60;
}
return 0 ;
V_60:
F_55 () ;
return V_30 ;
}
static void F_59 ( struct V_61 * V_62 )
{
if ( V_63 == NULL )
return;
V_62 -> V_64 = F_60 ( V_62 -> V_65 , 0444 , V_63 ,
& V_62 -> V_66 ) ;
}
static void F_61 ( void )
{
V_63 = F_62 ( L_2 , NULL ) ;
if ( V_63 == NULL )
return;
V_67 = F_63 ( L_3 , 0444 , V_63 ,
& V_68 ) ;
F_59 ( & V_69 ) ;
F_59 ( & V_70 ) ;
F_59 ( & V_71 ) ;
F_59 ( & V_72 ) ;
F_59 ( & V_73 ) ;
F_59 ( & V_74 ) ;
F_59 ( & V_75 ) ;
F_59 ( & V_76 ) ;
F_59 ( & V_77 ) ;
F_59 ( & V_78 ) ;
F_59 ( & V_79 ) ;
F_59 ( & V_80 ) ;
F_59 ( & V_81 ) ;
F_59 ( & V_82 ) ;
F_59 ( & V_83 ) ;
F_59 ( & V_84 ) ;
}
static void F_64 ( T_1 V_2 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 4 ; ++ V_24 )
F_50 ( L_4 , V_24 ,
V_57 [ V_2 ] . V_85 [ V_24 ] ) ;
}
static void F_65 ( unsigned long V_86 )
{
struct V_87 * V_88 = F_66 ( V_86 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 4 ; ++ V_24 )
F_50 ( L_5 , V_24 , V_88 -> V_85 [ V_24 ] ) ;
}
static void F_67 ( struct V_54 * V_19 , void * V_89 )
{
int type , V_2 , V_90 , V_4 ;
volatile T_2 * V_91 = V_89 ;
int V_92 = 0 ;
T_5 V_93 ;
V_94:
type = ( V_91 [ 1 ] >> V_95 ) & V_96 ;
V_2 = ( V_91 [ 0 ] >> V_97 ) & V_98 ;
V_90 = ( V_91 [ 1 ] >> V_99 ) & V_100 ;
V_4 = ( V_91 [ 1 ] >> V_101 ) & V_102 ;
V_93 = ( T_5 ) ( ( ( T_5 ) V_91 [ 3 ] ) << 32 ) | V_91 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_92 == V_103 ) {
F_50 ( L_6 ) ;
return;
}
F_68 ( 1 ) ;
goto V_94;
}
F_69 ( V_104 L_7 ) ;
switch ( type ) {
case V_105 :
F_69 ( L_8
L_9 ,
F_70 ( V_2 ) , F_32 ( V_2 ) , F_71 ( V_2 ) ,
V_93 , V_4 ) ;
F_64 ( V_2 ) ;
break;
case V_106 :
F_69 ( L_10
L_11 ,
F_70 ( V_2 ) , F_32 ( V_2 ) , F_71 ( V_2 ) ,
V_90 , V_93 , V_4 ) ;
break;
case V_107 :
F_69 ( L_12
L_9 ,
F_70 ( V_2 ) , F_32 ( V_2 ) , F_71 ( V_2 ) ,
V_93 , V_4 ) ;
break;
case V_108 :
F_69 ( L_13
L_11 ,
F_70 ( V_2 ) , F_32 ( V_2 ) , F_71 ( V_2 ) ,
V_90 , V_93 , V_4 ) ;
break;
case V_109 :
F_69 ( L_14 , V_93 ) ;
F_65 ( V_93 ) ;
break;
case V_110 :
F_69 ( L_15
L_16 , V_93 , V_4 ) ;
break;
case V_111 :
F_69 ( L_17
L_18 ,
F_70 ( V_2 ) , F_32 ( V_2 ) , F_71 ( V_2 ) ,
V_93 ) ;
break;
case V_112 :
F_69 ( L_19
L_9 ,
F_70 ( V_2 ) , F_32 ( V_2 ) , F_71 ( V_2 ) ,
V_93 , V_4 ) ;
break;
default:
F_69 ( V_104 L_20 , type ) ;
}
memset ( V_89 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_72 ( struct V_54 * V_19 )
{
T_2 V_113 , V_114 ;
V_113 = F_73 ( V_19 -> V_115 + V_116 ) ;
V_114 = F_73 ( V_19 -> V_115 + V_117 ) ;
while ( V_113 != V_114 ) {
F_67 ( V_19 , V_19 -> V_118 + V_113 ) ;
V_113 = ( V_113 + V_119 ) % V_19 -> V_120 ;
}
F_74 ( V_113 , V_19 -> V_115 + V_116 ) ;
}
static void F_75 ( struct V_54 * V_19 , T_5 * V_121 )
{
struct V_122 V_123 ;
F_76 ( V_84 ) ;
if ( F_77 ( V_121 [ 0 ] ) != V_124 ) {
F_78 ( L_21 ) ;
return;
}
V_123 . V_93 = V_121 [ 1 ] ;
V_123 . V_125 = F_79 ( V_121 [ 0 ] ) ;
V_123 . V_126 = F_80 ( V_121 [ 0 ] ) ;
V_123 . V_127 = F_81 ( V_121 [ 0 ] ) ;
V_123 . V_4 = F_82 ( V_121 [ 0 ] ) ;
F_83 ( & V_128 , 0 , & V_123 ) ;
}
static void F_84 ( struct V_54 * V_19 )
{
T_2 V_113 , V_114 ;
if ( V_19 -> V_129 == NULL )
return;
V_113 = F_73 ( V_19 -> V_115 + V_130 ) ;
V_114 = F_73 ( V_19 -> V_115 + V_131 ) ;
while ( V_113 != V_114 ) {
volatile T_5 * V_121 ;
T_5 V_29 [ 2 ] ;
int V_24 ;
V_121 = ( T_5 * ) ( V_19 -> V_129 + V_113 ) ;
for ( V_24 = 0 ; V_24 < V_103 ; ++ V_24 ) {
if ( F_77 ( V_121 [ 0 ] ) != 0 )
break;
F_68 ( 1 ) ;
}
V_29 [ 0 ] = V_121 [ 0 ] ;
V_29 [ 1 ] = V_121 [ 1 ] ;
V_121 [ 0 ] = V_121 [ 1 ] = 0UL ;
V_113 = ( V_113 + V_132 ) % V_133 ;
F_74 ( V_113 , V_19 -> V_115 + V_130 ) ;
F_75 ( V_19 , V_29 ) ;
V_113 = F_73 ( V_19 -> V_115 + V_130 ) ;
V_114 = F_73 ( V_19 -> V_115 + V_131 ) ;
}
}
T_6 F_85 ( int V_134 , void * V_85 )
{
struct V_54 * V_19 = (struct V_54 * ) V_85 ;
T_2 V_135 = F_73 ( V_19 -> V_115 + V_136 ) ;
while ( V_135 & ( V_137 | V_138 ) ) {
F_74 ( ( V_137 | V_138 ) ,
V_19 -> V_115 + V_136 ) ;
if ( V_135 & V_137 ) {
F_86 ( L_22 ) ;
F_72 ( V_19 ) ;
}
if ( V_135 & V_138 ) {
F_86 ( L_23 ) ;
F_84 ( V_19 ) ;
}
V_135 = F_73 ( V_19 -> V_115 + V_136 ) ;
}
return V_139 ;
}
T_6 F_87 ( int V_134 , void * V_85 )
{
return V_140 ;
}
static int F_88 ( volatile T_5 * V_141 )
{
int V_24 = 0 ;
while ( * V_141 == 0 && V_24 < V_103 ) {
F_68 ( 1 ) ;
V_24 += 1 ;
}
if ( V_24 == V_103 ) {
F_89 ( L_24 ) ;
return - V_142 ;
}
return 0 ;
}
static void F_90 ( struct V_54 * V_19 ,
struct V_87 * V_88 ,
T_2 V_114 )
{
T_3 * V_143 ;
V_143 = V_19 -> V_144 + V_114 ;
V_114 = ( V_114 + sizeof( * V_88 ) ) % V_19 -> V_145 ;
memcpy ( V_143 , V_88 , sizeof( * V_88 ) ) ;
F_74 ( V_114 , V_19 -> V_115 + V_146 ) ;
}
static void F_91 ( struct V_87 * V_88 , T_5 V_93 )
{
F_43 ( V_93 & 0x7ULL ) ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_85 [ 0 ] = F_92 ( F_93 ( V_93 ) ) | V_147 ;
V_88 -> V_85 [ 1 ] = F_94 ( F_93 ( V_93 ) ) ;
V_88 -> V_85 [ 2 ] = 1 ;
F_95 ( V_88 , V_148 ) ;
}
static void F_96 ( struct V_87 * V_88 , T_1 V_2 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_85 [ 0 ] = V_2 ;
F_95 ( V_88 , V_149 ) ;
}
static void F_97 ( struct V_87 * V_88 , T_5 V_93 ,
T_7 V_150 , T_1 V_90 , int V_151 )
{
T_5 V_152 ;
int V_153 ;
V_152 = F_98 ( V_93 , V_150 , V_154 ) ;
V_153 = 0 ;
if ( V_152 > 1 ) {
V_93 = V_155 ;
V_153 = 1 ;
}
V_93 &= V_156 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_85 [ 1 ] |= V_90 ;
V_88 -> V_85 [ 2 ] = F_92 ( V_93 ) ;
V_88 -> V_85 [ 3 ] = F_94 ( V_93 ) ;
F_95 ( V_88 , V_157 ) ;
if ( V_153 )
V_88 -> V_85 [ 2 ] |= V_158 ;
if ( V_151 )
V_88 -> V_85 [ 2 ] |= V_159 ;
}
static void F_99 ( struct V_87 * V_88 , T_1 V_2 , int V_160 ,
T_5 V_93 , T_7 V_150 )
{
T_5 V_152 ;
int V_153 ;
V_152 = F_98 ( V_93 , V_150 , V_154 ) ;
V_153 = 0 ;
if ( V_152 > 1 ) {
V_93 = V_155 ;
V_153 = 1 ;
}
V_93 &= V_156 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_85 [ 0 ] = V_2 ;
V_88 -> V_85 [ 0 ] |= ( V_160 & 0xff ) << 24 ;
V_88 -> V_85 [ 1 ] = V_2 ;
V_88 -> V_85 [ 2 ] = F_92 ( V_93 ) ;
V_88 -> V_85 [ 3 ] = F_94 ( V_93 ) ;
F_95 ( V_88 , V_161 ) ;
if ( V_153 )
V_88 -> V_85 [ 2 ] |= V_158 ;
}
static void F_100 ( struct V_87 * V_88 , T_1 V_90 , int V_125 ,
T_5 V_93 , bool V_150 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_93 &= ~ ( 0xfffULL ) ;
V_88 -> V_85 [ 0 ] = V_125 ;
V_88 -> V_85 [ 1 ] = V_90 ;
V_88 -> V_85 [ 2 ] = F_92 ( V_93 ) ;
V_88 -> V_85 [ 3 ] = F_94 ( V_93 ) ;
V_88 -> V_85 [ 2 ] |= V_159 ;
V_88 -> V_85 [ 2 ] |= V_162 ;
if ( V_150 )
V_88 -> V_85 [ 2 ] |= V_158 ;
F_95 ( V_88 , V_157 ) ;
}
static void F_101 ( struct V_87 * V_88 , T_1 V_2 , int V_125 ,
int V_160 , T_5 V_93 , bool V_150 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_93 &= ~ ( 0xfffULL ) ;
V_88 -> V_85 [ 0 ] = V_2 ;
V_88 -> V_85 [ 0 ] |= ( ( V_125 >> 8 ) & 0xff ) << 16 ;
V_88 -> V_85 [ 0 ] |= ( V_160 & 0xff ) << 24 ;
V_88 -> V_85 [ 1 ] = V_2 ;
V_88 -> V_85 [ 1 ] |= ( V_125 & 0xff ) << 16 ;
V_88 -> V_85 [ 2 ] = F_92 ( V_93 ) ;
V_88 -> V_85 [ 2 ] |= V_162 ;
V_88 -> V_85 [ 3 ] = F_94 ( V_93 ) ;
if ( V_150 )
V_88 -> V_85 [ 2 ] |= V_158 ;
F_95 ( V_88 , V_161 ) ;
}
static void F_102 ( struct V_87 * V_88 , T_1 V_2 , int V_125 ,
int V_135 , int V_127 , bool V_163 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_85 [ 0 ] = V_2 ;
if ( V_163 ) {
V_88 -> V_85 [ 1 ] = V_125 ;
V_88 -> V_85 [ 2 ] = V_162 ;
}
V_88 -> V_85 [ 3 ] = V_127 & 0x1ff ;
V_88 -> V_85 [ 3 ] |= ( V_135 & V_164 ) << V_165 ;
F_95 ( V_88 , V_166 ) ;
}
static void F_103 ( struct V_87 * V_88 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
F_95 ( V_88 , V_167 ) ;
}
static void F_104 ( struct V_87 * V_88 , T_1 V_2 )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_85 [ 0 ] = V_2 ;
F_95 ( V_88 , V_168 ) ;
}
static int F_105 ( struct V_54 * V_19 ,
struct V_87 * V_88 ,
bool V_169 )
{
T_2 V_170 , V_114 , V_113 , V_171 ;
unsigned long V_4 ;
F_43 ( V_19 -> V_145 & V_172 ) ;
V_173:
F_4 ( & V_19 -> V_174 , V_4 ) ;
V_113 = F_73 ( V_19 -> V_115 + V_175 ) ;
V_114 = F_73 ( V_19 -> V_115 + V_146 ) ;
V_171 = ( V_114 + sizeof( * V_88 ) ) % V_19 -> V_145 ;
V_170 = ( V_113 - V_171 ) % V_19 -> V_145 ;
if ( V_170 <= 2 ) {
struct V_87 V_176 ;
volatile T_5 V_141 = 0 ;
int V_30 ;
F_91 ( & V_176 , ( T_5 ) & V_141 ) ;
F_90 ( V_19 , & V_176 , V_114 ) ;
F_6 ( & V_19 -> V_174 , V_4 ) ;
if ( ( V_30 = F_88 ( & V_141 ) ) != 0 )
return V_30 ;
goto V_173;
}
F_90 ( V_19 , V_88 , V_114 ) ;
V_19 -> V_177 = V_169 ;
F_6 ( & V_19 -> V_174 , V_4 ) ;
return 0 ;
}
static int F_106 ( struct V_54 * V_19 , struct V_87 * V_88 )
{
return F_105 ( V_19 , V_88 , true ) ;
}
static int F_107 ( struct V_54 * V_19 )
{
struct V_87 V_88 ;
volatile T_5 V_141 = 0 ;
int V_30 ;
if ( ! V_19 -> V_177 )
return 0 ;
F_91 ( & V_88 , ( T_5 ) & V_141 ) ;
V_30 = F_105 ( V_19 , & V_88 , false ) ;
if ( V_30 )
return V_30 ;
return F_88 ( & V_141 ) ;
}
static int F_108 ( struct V_54 * V_19 , T_1 V_2 )
{
struct V_87 V_88 ;
F_96 ( & V_88 , V_2 ) ;
return F_106 ( V_19 , & V_88 ) ;
}
static void F_109 ( struct V_54 * V_19 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= 0xffff ; ++ V_2 )
F_108 ( V_19 , V_2 ) ;
F_107 ( V_19 ) ;
}
static void F_110 ( struct V_54 * V_19 )
{
T_2 V_178 ;
for ( V_178 = 0 ; V_178 <= 0xffff ; ++ V_178 ) {
struct V_87 V_88 ;
F_97 ( & V_88 , 0 , V_155 ,
V_178 , 1 ) ;
F_106 ( V_19 , & V_88 ) ;
}
F_107 ( V_19 ) ;
}
static void F_111 ( struct V_54 * V_19 )
{
struct V_87 V_88 ;
F_103 ( & V_88 ) ;
F_106 ( V_19 , & V_88 ) ;
F_107 ( V_19 ) ;
}
static void F_112 ( struct V_54 * V_19 , T_1 V_2 )
{
struct V_87 V_88 ;
F_104 ( & V_88 , V_2 ) ;
F_106 ( V_19 , & V_88 ) ;
}
static void F_113 ( struct V_54 * V_19 )
{
T_2 V_2 ;
for ( V_2 = 0 ; V_2 <= V_179 ; V_2 ++ )
F_112 ( V_19 , V_2 ) ;
F_107 ( V_19 ) ;
}
void F_114 ( struct V_54 * V_19 )
{
if ( F_115 ( V_19 , V_180 ) ) {
F_111 ( V_19 ) ;
} else {
F_109 ( V_19 ) ;
F_113 ( V_19 ) ;
F_110 ( V_19 ) ;
}
}
static int F_116 ( struct V_1 * V_3 ,
T_5 V_93 , T_7 V_150 )
{
struct V_54 * V_19 ;
struct V_87 V_88 ;
int V_160 ;
V_160 = V_3 -> V_181 . V_160 ;
V_19 = V_38 [ V_3 -> V_2 ] ;
F_99 ( & V_88 , V_3 -> V_2 , V_160 , V_93 , V_150 ) ;
return F_106 ( V_19 , & V_88 ) ;
}
static int F_117 ( struct V_1 * V_3 )
{
struct V_54 * V_19 ;
int V_30 ;
V_19 = V_38 [ V_3 -> V_2 ] ;
V_30 = F_108 ( V_19 , V_3 -> V_2 ) ;
if ( V_30 )
return V_30 ;
if ( V_3 -> V_181 . V_182 )
V_30 = F_116 ( V_3 , 0 , ~ 0UL ) ;
return V_30 ;
}
static void F_118 ( struct V_183 * V_184 ,
T_5 V_93 , T_7 V_150 , int V_151 )
{
struct V_1 * V_3 ;
struct V_87 V_88 ;
int V_30 = 0 , V_24 ;
F_97 ( & V_88 , V_93 , V_150 , V_184 -> V_185 , V_151 ) ;
for ( V_24 = 0 ; V_24 < V_186 ; ++ V_24 ) {
if ( ! V_184 -> V_187 [ V_24 ] )
continue;
V_30 |= F_106 ( V_188 [ V_24 ] , & V_88 ) ;
}
F_12 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_181 . V_182 )
continue;
V_30 |= F_116 ( V_3 , V_93 , V_150 ) ;
}
F_43 ( V_30 ) ;
}
static void F_119 ( struct V_183 * V_184 ,
T_5 V_93 , T_7 V_150 )
{
F_118 ( V_184 , V_93 , V_150 , 0 ) ;
}
static void F_120 ( struct V_183 * V_184 )
{
F_118 ( V_184 , 0 , V_155 , 0 ) ;
}
static void F_121 ( struct V_183 * V_184 )
{
F_118 ( V_184 , 0 , V_155 , 1 ) ;
}
static void F_122 ( struct V_183 * V_184 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_186 ; ++ V_24 ) {
if ( ! V_184 -> V_187 [ V_24 ] )
continue;
F_107 ( V_188 [ V_24 ] ) ;
}
}
static void F_123 ( struct V_183 * V_184 )
{
struct V_1 * V_3 ;
F_12 (dev_data, &domain->dev_list, list)
F_117 ( V_3 ) ;
}
static bool F_124 ( struct V_183 * V_184 ,
T_8 V_189 )
{
T_5 * V_190 ;
if ( V_184 -> V_191 == V_192 )
return false ;
V_190 = ( void * ) F_125 ( V_189 ) ;
if ( ! V_190 )
return false ;
* V_190 = F_126 ( V_184 -> V_191 ,
F_127 ( V_184 -> V_193 ) ) ;
V_184 -> V_193 = V_190 ;
V_184 -> V_191 += 1 ;
V_184 -> V_194 = true ;
return true ;
}
static T_5 * F_128 ( struct V_183 * V_184 ,
unsigned long V_93 ,
unsigned long V_195 ,
T_5 * * V_196 ,
T_8 V_189 )
{
int V_197 , V_198 ;
T_5 * V_190 , * V_199 ;
F_129 ( ! F_130 ( V_195 ) ) ;
while ( V_93 > F_131 ( V_184 -> V_191 ) )
F_124 ( V_184 , V_189 ) ;
V_197 = V_184 -> V_191 - 1 ;
V_190 = & V_184 -> V_193 [ F_132 ( V_197 , V_93 ) ] ;
V_93 = F_133 ( V_93 , V_195 ) ;
V_198 = F_134 ( V_195 ) ;
while ( V_197 > V_198 ) {
if ( ! F_135 ( * V_190 ) ) {
V_199 = ( T_5 * ) F_125 ( V_189 ) ;
if ( ! V_199 )
return NULL ;
* V_190 = F_126 ( V_197 , F_127 ( V_199 ) ) ;
}
if ( F_136 ( * V_190 ) != V_197 )
return NULL ;
V_197 -= 1 ;
V_190 = F_137 ( * V_190 ) ;
if ( V_196 && V_197 == V_198 )
* V_196 = V_190 ;
V_190 = & V_190 [ F_132 ( V_197 , V_93 ) ] ;
}
return V_190 ;
}
static T_5 * F_138 ( struct V_183 * V_184 , unsigned long V_93 )
{
int V_197 ;
T_5 * V_190 ;
if ( V_93 > F_131 ( V_184 -> V_191 ) )
return NULL ;
V_197 = V_184 -> V_191 - 1 ;
V_190 = & V_184 -> V_193 [ F_132 ( V_197 , V_93 ) ] ;
while ( V_197 > 0 ) {
if ( ! F_135 ( * V_190 ) )
return NULL ;
if ( F_136 ( * V_190 ) == 0x07 ) {
unsigned long V_200 , V_201 ;
V_200 = F_139 ( * V_190 ) ;
V_200 = ~ ( ( F_140 ( V_200 ) << 3 ) - 1 ) ;
V_201 = ( ( unsigned long ) V_190 ) & V_200 ;
return ( T_5 * ) V_201 ;
}
if ( F_136 ( * V_190 ) != V_197 )
return NULL ;
V_197 -= 1 ;
V_190 = F_137 ( * V_190 ) ;
V_190 = & V_190 [ F_132 ( V_197 , V_93 ) ] ;
}
return V_190 ;
}
static int F_141 ( struct V_183 * V_202 ,
unsigned long V_203 ,
unsigned long V_86 ,
int V_204 ,
unsigned long V_195 )
{
T_5 V_201 , * V_190 ;
int V_24 , V_92 ;
if ( ! ( V_204 & V_205 ) )
return - V_206 ;
V_203 = F_142 ( V_203 ) ;
V_86 = F_142 ( V_86 ) ;
V_92 = F_140 ( V_195 ) ;
V_190 = F_128 ( V_202 , V_203 , V_195 , NULL , V_5 ) ;
for ( V_24 = 0 ; V_24 < V_92 ; ++ V_24 )
if ( F_135 ( V_190 [ V_24 ] ) )
return - V_207 ;
if ( V_195 > V_154 ) {
V_201 = F_143 ( V_86 , V_195 ) ;
V_201 |= F_144 ( 7 ) | V_208 | V_209 ;
} else
V_201 = V_86 | V_208 | V_209 ;
if ( V_204 & V_210 )
V_201 |= V_211 ;
if ( V_204 & V_212 )
V_201 |= V_213 ;
for ( V_24 = 0 ; V_24 < V_92 ; ++ V_24 )
V_190 [ V_24 ] = V_201 ;
F_145 ( V_202 ) ;
return 0 ;
}
static unsigned long F_146 ( struct V_183 * V_202 ,
unsigned long V_203 ,
unsigned long V_195 )
{
unsigned long long V_214 , V_215 ;
T_5 * V_190 ;
F_129 ( ! F_130 ( V_195 ) ) ;
V_215 = 0 ;
while ( V_215 < V_195 ) {
V_190 = F_138 ( V_202 , V_203 ) ;
if ( ! V_190 ) {
V_214 = V_154 ;
} else if ( F_136 ( * V_190 ) == 0 ) {
V_214 = V_154 ;
* V_190 = 0ULL ;
} else {
int V_92 , V_24 ;
V_214 = F_139 ( * V_190 ) ;
if ( ( V_214 - 1 ) & V_203 )
break;
V_92 = F_140 ( V_214 ) ;
for ( V_24 = 0 ; V_24 < V_92 ; V_24 ++ )
V_190 [ V_24 ] = 0ULL ;
}
V_203 = ( V_203 & ~ ( V_214 - 1 ) ) + V_214 ;
V_215 += V_214 ;
}
F_129 ( V_215 && ! F_130 ( V_215 ) ) ;
return V_215 ;
}
static int F_147 ( struct V_54 * V_19 ,
struct V_216 * V_29 )
{
T_1 V_217 , V_24 ;
for ( V_24 = V_29 -> V_218 ; V_24 <= V_29 -> V_219 ; ++ V_24 ) {
V_217 = V_32 [ V_24 ] ;
if ( V_38 [ V_217 ] == V_19 )
return 1 ;
}
return 0 ;
}
static int F_148 ( struct V_28 * V_220 ,
struct V_216 * V_221 )
{
T_5 V_222 ;
int V_30 ;
for ( V_222 = V_221 -> V_223 ; V_222 < V_221 -> V_224 ;
V_222 += V_154 ) {
V_30 = F_141 ( & V_220 -> V_184 , V_222 , V_222 , V_221 -> V_204 ,
V_154 ) ;
if ( V_30 )
return V_30 ;
if ( V_222 < V_220 -> V_225 )
F_149 ( V_222 >> V_226 ,
V_220 -> V_227 [ 0 ] -> V_228 ) ;
}
return 0 ;
}
static int F_150 ( struct V_54 * V_19 )
{
struct V_216 * V_29 ;
int V_30 ;
F_12 (entry, &amd_iommu_unity_map, list) {
if ( ! F_147 ( V_19 , V_29 ) )
continue;
V_30 = F_148 ( V_19 -> V_229 , V_29 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static int F_151 ( struct V_28 * V_220 ,
T_1 V_2 )
{
struct V_216 * V_221 ;
int V_30 ;
F_12 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_221 -> V_218 && V_2 <= V_221 -> V_219 ) )
continue;
V_30 = F_148 ( V_220 , V_221 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static void F_152 ( struct V_28 * V_202 ,
unsigned long V_230 ,
unsigned int V_152 )
{
unsigned int V_24 , V_231 = V_202 -> V_225 >> V_226 ;
if ( V_230 + V_152 > V_231 )
V_152 = V_231 - V_230 ;
for ( V_24 = V_230 ; V_24 < V_230 + V_152 ; ++ V_24 ) {
int V_232 = V_24 / V_233 ;
int V_199 = V_24 % V_233 ;
F_149 ( V_199 , V_202 -> V_227 [ V_232 ] -> V_228 ) ;
}
}
static int F_153 ( struct V_28 * V_220 ,
bool V_234 , T_8 V_189 )
{
int V_232 = V_220 -> V_225 >> V_235 ;
struct V_54 * V_19 ;
unsigned long V_24 , V_236 ;
#ifdef F_154
V_234 = false ;
#endif
if ( V_232 >= V_237 )
return - V_49 ;
V_220 -> V_227 [ V_232 ] = F_2 ( sizeof( struct V_238 ) , V_189 ) ;
if ( ! V_220 -> V_227 [ V_232 ] )
return - V_49 ;
V_220 -> V_227 [ V_232 ] -> V_228 = ( void * ) F_125 ( V_189 ) ;
if ( ! V_220 -> V_227 [ V_232 ] -> V_228 )
goto V_60;
V_220 -> V_227 [ V_232 ] -> V_239 = V_220 -> V_225 ;
if ( V_234 ) {
unsigned long V_93 = V_220 -> V_225 ;
int V_24 , V_240 = V_233 / 512 ;
T_5 * V_190 , * V_196 ;
for ( V_24 = 0 ; V_24 < V_240 ; ++ V_24 ) {
V_190 = F_128 ( & V_220 -> V_184 , V_93 , V_154 ,
& V_196 , V_189 ) ;
if ( ! V_190 )
goto V_60;
V_220 -> V_227 [ V_232 ] -> V_241 [ V_24 ] = V_196 ;
V_93 += V_242 / 64 ;
}
}
V_236 = V_220 -> V_225 ;
V_220 -> V_225 += V_242 ;
if ( V_236 < V_243 &&
V_220 -> V_225 > V_243 ) {
unsigned long V_244 ;
int V_152 ;
V_152 = F_98 ( V_243 , 0x10000 , V_154 ) ;
V_244 = V_243 >> V_226 ;
F_152 ( V_220 , V_244 , V_152 ) ;
}
F_155 (iommu) {
if ( V_19 -> V_245 &&
V_19 -> V_245 >= V_220 -> V_227 [ V_232 ] -> V_239
&& V_19 -> V_245 < V_220 -> V_225 ) {
unsigned long V_246 ;
int V_152 = F_98 ( V_19 -> V_245 ,
V_19 -> V_247 ,
V_154 ) ;
V_246 = V_19 -> V_245 >> V_226 ;
F_152 ( V_220 , V_246 , V_152 ) ;
}
}
for ( V_24 = V_220 -> V_227 [ V_232 ] -> V_239 ;
V_24 < V_220 -> V_225 ;
V_24 += V_154 ) {
T_5 * V_190 = F_138 ( & V_220 -> V_184 , V_24 ) ;
if ( ! V_190 || ! F_135 ( * V_190 ) )
continue;
F_152 ( V_220 , V_24 >> V_226 , 1 ) ;
}
F_145 ( & V_220 -> V_184 ) ;
return 0 ;
V_60:
F_145 ( & V_220 -> V_184 ) ;
F_156 ( ( unsigned long ) V_220 -> V_227 [ V_232 ] -> V_228 ) ;
F_10 ( V_220 -> V_227 [ V_232 ] ) ;
V_220 -> V_227 [ V_232 ] = NULL ;
return - V_49 ;
}
static unsigned long F_157 ( struct V_11 * V_12 ,
struct V_28 * V_202 ,
unsigned int V_152 ,
unsigned long V_248 ,
T_5 V_36 ,
unsigned long V_249 )
{
unsigned long V_250 = V_202 -> V_251 % V_242 ;
int V_252 = V_202 -> V_225 >> V_235 ;
int V_24 = V_249 >> V_235 ;
unsigned long V_253 ;
unsigned long V_93 = - 1 ;
unsigned long V_254 ;
V_250 >>= V_226 ;
V_253 = F_158 ( F_159 ( V_12 ) + 1 ,
V_154 ) >> V_226 ;
for (; V_24 < V_252 ; ++ V_24 ) {
unsigned long V_239 = V_202 -> V_227 [ V_24 ] -> V_239 >> V_226 ;
if ( V_202 -> V_227 [ V_24 ] -> V_239 >= V_36 )
break;
V_254 = F_160 ( V_233 , V_239 ,
V_36 >> V_226 ) ;
V_93 = F_161 ( V_202 -> V_227 [ V_24 ] -> V_228 ,
V_254 , V_250 , V_152 , 0 ,
V_253 , V_248 ) ;
if ( V_93 != - 1 ) {
V_93 = V_202 -> V_227 [ V_24 ] -> V_239 +
( V_93 << V_226 ) ;
V_202 -> V_251 = V_93 + ( V_152 << V_226 ) ;
break;
}
V_250 = 0 ;
}
return V_93 ;
}
static unsigned long F_162 ( struct V_11 * V_12 ,
struct V_28 * V_202 ,
unsigned int V_152 ,
unsigned long V_248 ,
T_5 V_36 )
{
unsigned long V_93 ;
#ifdef F_154
V_202 -> V_251 = 0 ;
V_202 -> V_255 = true ;
#endif
V_93 = F_157 ( V_12 , V_202 , V_152 , V_248 ,
V_36 , V_202 -> V_251 ) ;
if ( V_93 == - 1 ) {
V_202 -> V_251 = 0 ;
V_93 = F_157 ( V_12 , V_202 , V_152 , V_248 ,
V_36 , 0 ) ;
V_202 -> V_255 = true ;
}
if ( F_163 ( V_93 == - 1 ) )
V_93 = V_256 ;
F_43 ( ( V_93 + ( V_154 * V_152 ) ) > V_202 -> V_225 ) ;
return V_93 ;
}
static void F_164 ( struct V_28 * V_202 ,
unsigned long V_93 ,
unsigned int V_152 )
{
unsigned V_24 = V_93 >> V_235 ;
struct V_238 * V_257 = V_202 -> V_227 [ V_24 ] ;
F_129 ( V_24 >= V_237 || V_257 == NULL ) ;
#ifdef F_154
if ( V_24 < 4 )
return;
#endif
if ( V_93 >= V_202 -> V_251 )
V_202 -> V_255 = true ;
V_93 = ( V_93 % V_242 ) >> V_226 ;
F_165 ( V_257 -> V_228 , V_93 , V_152 ) ;
}
static void F_166 ( struct V_183 * V_184 )
{
unsigned long V_4 ;
F_4 ( & V_258 , V_4 ) ;
F_167 ( & V_184 -> V_259 , & V_260 ) ;
F_6 ( & V_258 , V_4 ) ;
}
static void F_168 ( struct V_183 * V_184 )
{
unsigned long V_4 ;
F_4 ( & V_258 , V_4 ) ;
F_8 ( & V_184 -> V_259 ) ;
F_6 ( & V_258 , V_4 ) ;
}
static T_1 F_169 ( void )
{
unsigned long V_4 ;
int V_185 ;
F_170 ( & V_261 , V_4 ) ;
V_185 = F_171 ( V_262 , V_263 ) ;
F_129 ( V_185 == 0 ) ;
if ( V_185 > 0 && V_185 < V_263 )
F_149 ( V_185 , V_262 ) ;
else
V_185 = 0 ;
F_172 ( & V_261 , V_4 ) ;
return V_185 ;
}
static void F_173 ( int V_185 )
{
unsigned long V_4 ;
F_170 ( & V_261 , V_4 ) ;
if ( V_185 > 0 && V_185 < V_263 )
F_174 ( V_185 , V_262 ) ;
F_172 ( & V_261 , V_4 ) ;
}
static void F_175 ( struct V_183 * V_184 )
{
unsigned long V_264 = ( unsigned long ) V_184 -> V_193 ;
switch ( V_184 -> V_191 ) {
case V_265 :
break;
case V_266 :
F_156 ( V_264 ) ;
break;
case V_267 :
F_176 ( V_264 ) ;
break;
case V_268 :
F_177 ( V_264 ) ;
break;
case V_269 :
F_178 ( V_264 ) ;
break;
case V_270 :
F_179 ( V_264 ) ;
break;
case V_192 :
F_180 ( V_264 ) ;
break;
default:
F_181 () ;
}
}
static void F_182 ( T_5 * V_271 )
{
T_5 * V_272 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! ( V_271 [ V_24 ] & V_273 ) )
continue;
V_272 = F_183 ( V_271 [ V_24 ] & V_156 ) ;
F_156 ( ( unsigned long ) V_272 ) ;
}
}
static void F_184 ( T_5 * V_271 )
{
T_5 * V_272 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 512 ; ++ V_24 ) {
if ( ! ( V_271 [ V_24 ] & V_273 ) )
continue;
V_272 = F_183 ( V_271 [ V_24 ] & V_156 ) ;
F_182 ( V_272 ) ;
}
}
static void F_185 ( struct V_183 * V_184 )
{
if ( V_184 -> V_274 == 2 )
F_184 ( V_184 -> V_275 ) ;
else if ( V_184 -> V_274 == 1 )
F_182 ( V_184 -> V_275 ) ;
else if ( V_184 -> V_274 != 0 )
F_181 () ;
F_156 ( ( unsigned long ) V_184 -> V_275 ) ;
}
static void F_186 ( struct V_28 * V_202 )
{
int V_24 ;
if ( ! V_202 )
return;
F_168 ( & V_202 -> V_184 ) ;
F_175 ( & V_202 -> V_184 ) ;
for ( V_24 = 0 ; V_24 < V_237 ; ++ V_24 ) {
if ( ! V_202 -> V_227 [ V_24 ] )
continue;
F_156 ( ( unsigned long ) V_202 -> V_227 [ V_24 ] -> V_228 ) ;
F_10 ( V_202 -> V_227 [ V_24 ] ) ;
}
F_10 ( V_202 ) ;
}
static struct V_28 * F_187 ( void )
{
struct V_28 * V_220 ;
V_220 = F_2 ( sizeof( struct V_28 ) , V_5 ) ;
if ( ! V_220 )
return NULL ;
F_188 ( & V_220 -> V_184 . V_174 ) ;
V_220 -> V_184 . V_185 = F_169 () ;
if ( V_220 -> V_184 . V_185 == 0 )
goto V_276;
F_189 ( & V_220 -> V_184 . V_277 ) ;
V_220 -> V_184 . V_191 = V_267 ;
V_220 -> V_184 . V_193 = ( void * ) F_125 ( V_5 ) ;
V_220 -> V_184 . V_4 = V_278 ;
V_220 -> V_184 . V_279 = V_220 ;
if ( ! V_220 -> V_184 . V_193 )
goto V_276;
V_220 -> V_255 = false ;
V_220 -> V_35 = 0xffff ;
F_166 ( & V_220 -> V_184 ) ;
if ( F_153 ( V_220 , true , V_5 ) )
goto V_276;
V_220 -> V_227 [ 0 ] -> V_228 [ 0 ] = 1 ;
V_220 -> V_251 = 0 ;
return V_220 ;
V_276:
F_186 ( V_220 ) ;
return NULL ;
}
static bool V_28 ( struct V_183 * V_184 )
{
return V_184 -> V_4 & V_278 ;
}
static void F_190 ( T_1 V_2 , struct V_183 * V_184 , bool V_181 )
{
T_5 V_280 = 0 ;
T_5 V_4 = 0 ;
if ( V_184 -> V_191 != V_265 )
V_280 = F_127 ( V_184 -> V_193 ) ;
V_280 |= ( V_184 -> V_191 & V_281 )
<< V_282 ;
V_280 |= V_211 | V_213 | V_208 | V_283 ;
V_4 = V_57 [ V_2 ] . V_85 [ 1 ] ;
if ( V_181 )
V_4 |= V_284 ;
if ( V_184 -> V_4 & V_285 ) {
T_5 V_286 = F_93 ( V_184 -> V_275 ) ;
T_5 V_274 = V_184 -> V_274 ;
T_5 V_47 ;
V_280 |= V_287 ;
V_280 |= ( V_274 & V_288 ) << V_289 ;
V_47 = F_191 ( ~ 0ULL ) << V_290 ;
V_4 &= ~ V_47 ;
V_47 = F_192 ( ~ 0ULL ) << V_291 ;
V_4 &= ~ V_47 ;
V_47 = F_193 ( V_286 ) << V_292 ;
V_280 |= V_47 ;
V_47 = F_191 ( V_286 ) << V_290 ;
V_4 |= V_47 ;
V_47 = F_192 ( V_286 ) << V_291 ;
V_4 |= V_47 ;
}
V_4 &= ~ ( 0xffffUL ) ;
V_4 |= V_184 -> V_185 ;
V_57 [ V_2 ] . V_85 [ 1 ] = V_4 ;
V_57 [ V_2 ] . V_85 [ 0 ] = V_280 ;
}
static void F_194 ( T_1 V_2 )
{
V_57 [ V_2 ] . V_85 [ 0 ] = V_208 | V_283 ;
V_57 [ V_2 ] . V_85 [ 1 ] = 0 ;
F_195 ( V_2 ) ;
}
static void F_196 ( struct V_1 * V_3 ,
struct V_183 * V_184 )
{
struct V_54 * V_19 ;
bool V_181 ;
V_19 = V_38 [ V_3 -> V_2 ] ;
V_181 = V_3 -> V_181 . V_182 ;
V_3 -> V_184 = V_184 ;
F_167 ( & V_3 -> V_259 , & V_184 -> V_277 ) ;
F_190 ( V_3 -> V_2 , V_184 , V_181 ) ;
V_184 -> V_187 [ V_19 -> V_232 ] += 1 ;
V_184 -> V_293 += 1 ;
F_117 ( V_3 ) ;
}
static void F_197 ( struct V_1 * V_3 )
{
struct V_54 * V_19 ;
V_19 = V_38 [ V_3 -> V_2 ] ;
V_3 -> V_184 -> V_187 [ V_19 -> V_232 ] -= 1 ;
V_3 -> V_184 -> V_293 -= 1 ;
V_3 -> V_184 = NULL ;
F_8 ( & V_3 -> V_259 ) ;
F_194 ( V_3 -> V_2 ) ;
F_117 ( V_3 ) ;
}
static int F_198 ( struct V_1 * V_3 ,
struct V_183 * V_184 )
{
int V_30 ;
F_199 ( & V_184 -> V_174 ) ;
if ( V_3 -> V_50 != NULL ) {
struct V_1 * V_50 = V_3 -> V_50 ;
V_30 = - V_207 ;
if ( V_50 -> V_184 != NULL &&
V_50 -> V_184 != V_184 )
goto V_10;
if ( V_3 -> V_184 != NULL &&
V_3 -> V_184 != V_184 )
goto V_10;
if ( V_50 -> V_184 == NULL )
F_196 ( V_50 , V_184 ) ;
F_200 ( & V_50 -> V_6 ) ;
}
if ( V_3 -> V_184 == NULL )
F_196 ( V_3 , V_184 ) ;
F_200 ( & V_3 -> V_6 ) ;
V_30 = 0 ;
V_10:
F_201 ( & V_184 -> V_174 ) ;
return V_30 ;
}
static void F_202 ( struct V_13 * V_14 )
{
F_203 ( V_14 ) ;
F_204 ( V_14 ) ;
F_205 ( V_14 ) ;
}
static int F_206 ( struct V_13 * V_14 )
{
T_1 V_294 ;
int V_25 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( ! V_25 )
return - V_206 ;
F_207 ( V_14 , V_25 + V_295 , & V_294 ) ;
V_294 |= V_296 ;
F_208 ( V_14 , V_25 + V_295 , V_294 ) ;
return 0 ;
}
static int F_209 ( struct V_13 * V_14 )
{
bool V_297 ;
int V_298 , V_30 ;
V_298 = 32 ;
if ( F_20 ( V_14 , V_299 ) )
V_298 = 1 ;
V_297 = F_20 ( V_14 , V_300 ) ;
V_30 = F_210 ( V_14 , 0 ) ;
if ( V_30 )
goto V_301;
V_30 = F_211 ( V_14 ) ;
if ( V_30 )
goto V_301;
V_30 = F_212 ( V_14 , V_298 ) ;
if ( V_30 )
goto V_301;
if ( V_297 ) {
V_30 = F_206 ( V_14 ) ;
if ( V_30 )
goto V_301;
}
V_30 = F_213 ( V_14 , V_226 ) ;
if ( V_30 )
goto V_301;
return 0 ;
V_301:
F_204 ( V_14 ) ;
F_205 ( V_14 ) ;
return V_30 ;
}
static bool F_214 ( struct V_13 * V_14 )
{
T_1 V_135 ;
int V_25 ;
V_25 = F_19 ( V_14 , V_22 ) ;
if ( ! V_25 )
return false ;
F_207 ( V_14 , V_25 + V_302 , & V_135 ) ;
return ( V_135 & V_303 ) ? true : false ;
}
static int F_215 ( struct V_11 * V_12 ,
struct V_183 * V_184 )
{
struct V_13 * V_14 = F_15 ( V_12 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_30 ;
V_3 = F_17 ( V_12 ) ;
if ( V_184 -> V_4 & V_285 ) {
if ( ! V_3 -> V_55 || ! V_3 -> V_304 )
return - V_206 ;
if ( F_209 ( V_14 ) != 0 )
return - V_206 ;
V_3 -> V_181 . V_182 = true ;
V_3 -> V_181 . V_160 = F_216 ( V_14 ) ;
V_3 -> V_305 = F_214 ( V_14 ) ;
} else if ( V_306 &&
F_213 ( V_14 , V_226 ) == 0 ) {
V_3 -> V_181 . V_182 = true ;
V_3 -> V_181 . V_160 = F_216 ( V_14 ) ;
}
F_170 ( & V_261 , V_4 ) ;
V_30 = F_198 ( V_3 , V_184 ) ;
F_172 ( & V_261 , V_4 ) ;
F_121 ( V_184 ) ;
return V_30 ;
}
static void F_217 ( struct V_1 * V_3 )
{
struct V_183 * V_184 ;
unsigned long V_4 ;
F_129 ( ! V_3 -> V_184 ) ;
V_184 = V_3 -> V_184 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
if ( V_3 -> V_50 != NULL ) {
struct V_1 * V_50 = V_3 -> V_50 ;
if ( F_218 ( & V_50 -> V_6 ) )
F_197 ( V_50 ) ;
}
if ( F_218 ( & V_3 -> V_6 ) )
F_197 ( V_3 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
if ( V_3 -> V_304 &&
( V_3 -> V_184 == NULL && V_184 != V_307 ) )
F_198 ( V_3 , V_307 ) ;
}
static void F_219 ( struct V_11 * V_12 )
{
struct V_183 * V_184 ;
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_17 ( V_12 ) ;
V_184 = V_3 -> V_184 ;
F_170 ( & V_261 , V_4 ) ;
F_217 ( V_3 ) ;
F_172 ( & V_261 , V_4 ) ;
if ( V_184 -> V_4 & V_285 )
F_202 ( F_15 ( V_12 ) ) ;
else if ( V_3 -> V_181 . V_182 )
F_203 ( F_15 ( V_12 ) ) ;
V_3 -> V_181 . V_182 = false ;
}
static struct V_183 * F_220 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_183 * V_202 = NULL ;
unsigned long V_4 ;
V_3 = F_17 ( V_12 ) ;
if ( V_3 -> V_184 )
return V_3 -> V_184 ;
if ( V_3 -> V_50 != NULL ) {
struct V_1 * V_50 = V_3 -> V_50 ;
F_221 ( & V_261 , V_4 ) ;
if ( V_50 -> V_184 != NULL ) {
F_198 ( V_3 , V_50 -> V_184 ) ;
V_202 = V_50 -> V_184 ;
}
F_222 ( & V_261 , V_4 ) ;
}
return V_202 ;
}
static int F_223 ( struct V_308 * V_309 ,
unsigned long V_310 , void * V_85 )
{
struct V_28 * V_311 ;
struct V_183 * V_184 ;
struct V_1 * V_3 ;
struct V_11 * V_12 = V_85 ;
struct V_54 * V_19 ;
unsigned long V_4 ;
T_1 V_2 ;
if ( ! F_23 ( V_12 ) )
return 0 ;
V_2 = F_14 ( V_12 ) ;
V_19 = V_38 [ V_2 ] ;
V_3 = F_17 ( V_12 ) ;
switch ( V_310 ) {
case V_312 :
V_184 = F_220 ( V_12 ) ;
if ( ! V_184 )
goto V_313;
if ( V_3 -> V_304 )
break;
F_219 ( V_12 ) ;
break;
case V_314 :
F_49 ( V_12 ) ;
V_3 = F_17 ( V_12 ) ;
if ( V_315 || V_3 -> V_55 ) {
V_3 -> V_304 = true ;
F_215 ( V_12 , V_307 ) ;
break;
}
V_184 = F_220 ( V_12 ) ;
V_311 = F_21 ( V_2 ) ;
if ( ! V_311 ) {
V_311 = F_187 () ;
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
F_53 ( V_12 ) ;
default:
goto V_313;
}
F_107 ( V_19 ) ;
V_313:
return 0 ;
}
void F_224 ( void )
{
F_225 ( & V_319 , & V_320 ) ;
}
static struct V_183 * F_226 ( struct V_11 * V_12 )
{
struct V_183 * V_184 ;
struct V_28 * V_220 ;
T_1 V_2 = F_14 ( V_12 ) ;
if ( ! F_23 ( V_12 ) )
return F_27 ( - V_206 ) ;
V_184 = F_220 ( V_12 ) ;
if ( V_184 != NULL && ! V_28 ( V_184 ) )
return F_27 ( - V_207 ) ;
if ( V_184 != NULL )
return V_184 ;
V_220 = F_21 ( V_2 ) ;
if ( ! V_220 )
V_220 = V_38 [ V_2 ] -> V_229 ;
F_215 ( V_12 , & V_220 -> V_184 ) ;
F_227 ( L_25 ,
V_220 -> V_184 . V_185 , F_51 ( V_12 ) ) ;
return & V_220 -> V_184 ;
}
static void F_228 ( struct V_183 * V_184 )
{
struct V_1 * V_3 ;
F_12 (dev_data, &domain->dev_list, list)
F_190 ( V_3 -> V_2 , V_184 , V_3 -> V_181 . V_182 ) ;
}
static void F_145 ( struct V_183 * V_184 )
{
if ( ! V_184 -> V_194 )
return;
F_228 ( V_184 ) ;
F_123 ( V_184 ) ;
F_121 ( V_184 ) ;
V_184 -> V_194 = false ;
}
static T_5 * F_229 ( struct V_28 * V_202 ,
unsigned long V_93 )
{
struct V_238 * V_227 ;
T_5 * V_190 , * V_196 ;
V_227 = V_202 -> V_227 [ F_230 ( V_93 ) ] ;
if ( ! V_227 )
return NULL ;
V_190 = V_227 -> V_241 [ F_231 ( V_93 ) ] ;
if ( ! V_190 ) {
V_190 = F_128 ( & V_202 -> V_184 , V_93 , V_154 , & V_196 ,
V_321 ) ;
V_227 -> V_241 [ F_231 ( V_93 ) ] = V_196 ;
} else
V_190 += F_132 ( 0 , V_93 ) ;
F_145 ( & V_202 -> V_184 ) ;
return V_190 ;
}
static T_9 F_232 ( struct V_28 * V_202 ,
unsigned long V_93 ,
T_10 V_322 ,
int V_323 )
{
T_5 * V_190 , V_201 ;
F_43 ( V_93 > V_202 -> V_225 ) ;
V_322 &= V_156 ;
V_190 = F_229 ( V_202 , V_93 ) ;
if ( ! V_190 )
return V_256 ;
V_201 = V_322 | V_208 | V_209 ;
if ( V_323 == V_324 )
V_201 |= V_211 ;
else if ( V_323 == V_325 )
V_201 |= V_213 ;
else if ( V_323 == V_326 )
V_201 |= V_211 | V_213 ;
F_43 ( * V_190 ) ;
* V_190 = V_201 ;
return ( T_9 ) V_93 ;
}
static void F_233 ( struct V_28 * V_202 ,
unsigned long V_93 )
{
struct V_238 * V_227 ;
T_5 * V_190 ;
if ( V_93 >= V_202 -> V_225 )
return;
V_227 = V_202 -> V_227 [ F_230 ( V_93 ) ] ;
if ( ! V_227 )
return;
V_190 = V_227 -> V_241 [ F_231 ( V_93 ) ] ;
if ( ! V_190 )
return;
V_190 += F_132 ( 0 , V_93 ) ;
F_43 ( ! * V_190 ) ;
* V_190 = 0ULL ;
}
static T_9 F_234 ( struct V_11 * V_12 ,
struct V_28 * V_220 ,
T_10 V_322 ,
T_7 V_150 ,
int V_327 ,
bool V_328 ,
T_5 V_36 )
{
T_9 V_239 = V_322 & ~ V_156 ;
T_9 V_93 , V_249 , V_30 ;
unsigned int V_152 ;
unsigned long V_248 = 0 ;
int V_24 ;
V_152 = F_98 ( V_322 , V_150 , V_154 ) ;
V_322 &= V_156 ;
F_76 ( V_80 ) ;
if ( V_152 > 1 )
F_76 ( V_76 ) ;
if ( V_328 )
V_248 = ( 1UL << F_235 ( V_150 ) ) - 1 ;
V_94:
V_93 = F_162 ( V_12 , V_220 , V_152 , V_248 ,
V_36 ) ;
if ( F_163 ( V_93 == V_256 ) ) {
V_220 -> V_251 = V_220 -> V_225 ;
if ( F_153 ( V_220 , false , V_321 ) )
goto V_313;
goto V_94;
}
V_249 = V_93 ;
for ( V_24 = 0 ; V_24 < V_152 ; ++ V_24 ) {
V_30 = F_232 ( V_220 , V_249 , V_322 , V_327 ) ;
if ( V_30 == V_256 )
goto V_329;
V_322 += V_154 ;
V_249 += V_154 ;
}
V_93 += V_239 ;
F_236 ( V_79 , V_150 ) ;
if ( F_163 ( V_220 -> V_255 && ! V_68 ) ) {
F_120 ( & V_220 -> V_184 ) ;
V_220 -> V_255 = false ;
} else if ( F_163 ( V_330 ) )
F_119 ( & V_220 -> V_184 , V_93 , V_150 ) ;
V_313:
return V_93 ;
V_329:
for ( -- V_24 ; V_24 >= 0 ; -- V_24 ) {
V_249 -= V_154 ;
F_233 ( V_220 , V_249 ) ;
}
F_164 ( V_220 , V_93 , V_152 ) ;
return V_256 ;
}
static void F_237 ( struct V_28 * V_220 ,
T_9 V_331 ,
T_7 V_150 ,
int V_327 )
{
T_9 V_332 ;
T_9 V_24 , V_249 ;
unsigned int V_152 ;
if ( ( V_331 == V_256 ) ||
( V_331 + V_150 > V_220 -> V_225 ) )
return;
V_332 = V_331 ;
V_152 = F_98 ( V_331 , V_150 , V_154 ) ;
V_331 &= V_156 ;
V_249 = V_331 ;
for ( V_24 = 0 ; V_24 < V_152 ; ++ V_24 ) {
F_233 ( V_220 , V_249 ) ;
V_249 += V_154 ;
}
F_238 ( V_79 , V_150 ) ;
F_164 ( V_220 , V_331 , V_152 ) ;
if ( V_68 || V_220 -> V_255 ) {
F_119 ( & V_220 -> V_184 , V_332 , V_150 ) ;
V_220 -> V_255 = false ;
}
}
static T_9 F_239 ( struct V_11 * V_12 , struct V_199 * V_199 ,
unsigned long V_239 , T_7 V_150 ,
enum V_333 V_327 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
T_9 V_222 ;
T_5 V_36 ;
T_10 V_322 = F_240 ( V_199 ) + V_239 ;
F_76 ( V_70 ) ;
V_184 = F_226 ( V_12 ) ;
if ( F_42 ( V_184 ) == - V_206 )
return ( T_9 ) V_322 ;
else if ( F_36 ( V_184 ) )
return V_256 ;
V_36 = * V_12 -> V_36 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_222 = F_234 ( V_12 , V_184 -> V_279 , V_322 , V_150 , V_327 , false ,
V_36 ) ;
if ( V_222 == V_256 )
goto V_313;
F_122 ( V_184 ) ;
V_313:
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_222 ;
}
static void F_241 ( struct V_11 * V_12 , T_9 V_331 , T_7 V_150 ,
enum V_333 V_327 , struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
F_76 ( V_71 ) ;
V_184 = F_226 ( V_12 ) ;
if ( F_36 ( V_184 ) )
return;
F_4 ( & V_184 -> V_174 , V_4 ) ;
F_237 ( V_184 -> V_279 , V_331 , V_150 , V_327 ) ;
F_122 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
}
static int F_242 ( struct V_11 * V_12 , struct V_336 * V_337 ,
int V_338 , enum V_333 V_327 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
int V_24 ;
struct V_336 * V_153 ;
T_10 V_322 ;
int V_339 = 0 ;
T_5 V_36 ;
F_76 ( V_72 ) ;
V_184 = F_226 ( V_12 ) ;
if ( F_36 ( V_184 ) )
return 0 ;
V_36 = * V_12 -> V_36 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
F_243 (sglist, s, nelems, i) {
V_322 = F_244 ( V_153 ) ;
V_153 -> V_340 = F_234 ( V_12 , V_184 -> V_279 ,
V_322 , V_153 -> V_341 , V_327 , false ,
V_36 ) ;
if ( V_153 -> V_340 ) {
V_153 -> V_342 = V_153 -> V_341 ;
V_339 ++ ;
} else
goto V_343;
}
F_122 ( V_184 ) ;
V_313:
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_339 ;
V_343:
F_243 (sglist, s, mapped_elems, i) {
if ( V_153 -> V_340 )
F_237 ( V_184 -> V_279 , V_153 -> V_340 ,
V_153 -> V_342 , V_327 ) ;
V_153 -> V_340 = V_153 -> V_342 = 0 ;
}
V_339 = 0 ;
goto V_313;
}
static void F_245 ( struct V_11 * V_12 , struct V_336 * V_337 ,
int V_338 , enum V_333 V_327 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
struct V_336 * V_153 ;
int V_24 ;
F_76 ( V_73 ) ;
V_184 = F_226 ( V_12 ) ;
if ( F_36 ( V_184 ) )
return;
F_4 ( & V_184 -> V_174 , V_4 ) ;
F_243 (sglist, s, nelems, i) {
F_237 ( V_184 -> V_279 , V_153 -> V_340 ,
V_153 -> V_342 , V_327 ) ;
V_153 -> V_340 = V_153 -> V_342 = 0 ;
}
F_122 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
}
static void * F_246 ( struct V_11 * V_12 , T_7 V_150 ,
T_9 * V_331 , T_8 V_344 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
void * V_345 ;
struct V_183 * V_184 ;
T_10 V_322 ;
T_5 V_36 = V_12 -> V_346 ;
F_76 ( V_74 ) ;
V_184 = F_226 ( V_12 ) ;
if ( F_42 ( V_184 ) == - V_206 ) {
V_345 = ( void * ) F_247 ( V_344 , F_235 ( V_150 ) ) ;
* V_331 = F_93 ( V_345 ) ;
return V_345 ;
} else if ( F_36 ( V_184 ) )
return NULL ;
V_36 = V_12 -> V_346 ;
V_344 &= ~ ( V_347 | V_348 | V_349 ) ;
V_344 |= V_350 ;
V_345 = ( void * ) F_247 ( V_344 , F_235 ( V_150 ) ) ;
if ( ! V_345 )
return NULL ;
V_322 = F_127 ( V_345 ) ;
if ( ! V_36 )
V_36 = * V_12 -> V_36 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
* V_331 = F_234 ( V_12 , V_184 -> V_279 , V_322 ,
V_150 , V_326 , true , V_36 ) ;
if ( * V_331 == V_256 ) {
F_6 ( & V_184 -> V_174 , V_4 ) ;
goto V_60;
}
F_122 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_345 ;
V_60:
F_248 ( ( unsigned long ) V_345 , F_235 ( V_150 ) ) ;
return NULL ;
}
static void F_249 ( struct V_11 * V_12 , T_7 V_150 ,
void * V_345 , T_9 V_331 ,
struct V_334 * V_335 )
{
unsigned long V_4 ;
struct V_183 * V_184 ;
F_76 ( V_75 ) ;
V_184 = F_226 ( V_12 ) ;
if ( F_36 ( V_184 ) )
goto V_351;
F_4 ( & V_184 -> V_174 , V_4 ) ;
F_237 ( V_184 -> V_279 , V_331 , V_150 , V_326 ) ;
F_122 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
V_351:
F_248 ( ( unsigned long ) V_345 , F_235 ( V_150 ) ) ;
}
static int F_250 ( struct V_11 * V_12 , T_5 V_352 )
{
return F_23 ( V_12 ) ;
}
static void T_4 F_251 ( void )
{
struct V_1 * V_3 ;
struct V_28 * V_220 ;
struct V_13 * V_12 = NULL ;
T_1 V_2 ;
F_56 (dev) {
if ( ! F_23 ( & V_12 -> V_12 ) )
continue;
V_3 = F_17 ( & V_12 -> V_12 ) ;
if ( ! V_353 && V_3 -> V_55 ) {
F_252 () ;
V_3 -> V_304 = true ;
F_215 ( & V_12 -> V_12 , V_307 ) ;
F_253 ( L_26 ,
F_51 ( & V_12 -> V_12 ) ) ;
}
if ( F_220 ( & V_12 -> V_12 ) )
continue;
V_2 = F_14 ( & V_12 -> V_12 ) ;
V_220 = F_187 () ;
if ( ! V_220 )
continue;
F_151 ( V_220 , V_2 ) ;
V_220 -> V_35 = V_2 ;
F_215 ( & V_12 -> V_12 , & V_220 -> V_184 ) ;
F_5 ( & V_220 -> V_259 , & V_33 ) ;
}
}
static unsigned F_254 ( void )
{
struct V_1 * V_3 ;
struct V_13 * V_14 = NULL ;
unsigned V_354 = 0 ;
F_56 (pdev) {
if ( ! F_23 ( & V_14 -> V_12 ) ) {
F_52 ( & V_14 -> V_12 ) ;
V_354 += 1 ;
continue;
}
V_3 = F_17 ( & V_14 -> V_12 ) ;
if ( ! V_3 -> V_304 )
V_14 -> V_12 . V_18 . V_316 = & V_317 ;
else
V_14 -> V_12 . V_18 . V_316 = & V_355 ;
}
return V_354 ;
}
void T_4 F_255 ( void )
{
F_256 ( & V_319 , & V_356 ) ;
}
int T_4 F_257 ( void )
{
struct V_54 * V_19 ;
int V_30 , V_354 ;
F_155 (iommu) {
V_19 -> V_229 = F_187 () ;
if ( V_19 -> V_229 == NULL )
return - V_49 ;
V_19 -> V_229 -> V_184 . V_4 |= V_357 ;
V_30 = F_150 ( V_19 ) ;
if ( V_30 )
goto V_358;
}
F_251 () ;
V_359 = 1 ;
V_360 = 0 ;
V_354 = F_254 () ;
if ( V_354 && V_361 > V_362 ) {
V_360 = 1 ;
}
F_61 () ;
if ( V_68 )
F_253 ( L_27 ) ;
else
F_253 ( L_28 ) ;
return 0 ;
V_358:
F_155 (iommu) {
F_186 ( V_19 -> V_229 ) ;
}
return V_30 ;
}
static void F_258 ( struct V_183 * V_184 )
{
struct V_1 * V_3 , * V_363 ;
unsigned long V_4 ;
F_170 ( & V_261 , V_4 ) ;
F_57 (dev_data, next, &domain->dev_list, list) {
F_217 ( V_3 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
}
F_172 ( & V_261 , V_4 ) ;
}
static void F_259 ( struct V_183 * V_184 )
{
if ( ! V_184 )
return;
F_168 ( V_184 ) ;
if ( V_184 -> V_185 )
F_173 ( V_184 -> V_185 ) ;
F_10 ( V_184 ) ;
}
static struct V_183 * F_260 ( void )
{
struct V_183 * V_184 ;
V_184 = F_2 ( sizeof( * V_184 ) , V_5 ) ;
if ( ! V_184 )
return NULL ;
F_188 ( & V_184 -> V_174 ) ;
F_261 ( & V_184 -> V_364 ) ;
V_184 -> V_185 = F_169 () ;
if ( ! V_184 -> V_185 )
goto V_301;
F_189 ( & V_184 -> V_277 ) ;
F_166 ( V_184 ) ;
return V_184 ;
V_301:
F_10 ( V_184 ) ;
return NULL ;
}
static int T_4 F_252 ( void )
{
if ( V_307 != NULL )
return 0 ;
V_307 = F_260 () ;
if ( ! V_307 )
return - V_49 ;
V_307 -> V_191 = V_265 ;
return 0 ;
}
static int F_262 ( struct V_365 * V_202 )
{
struct V_183 * V_184 ;
V_184 = F_260 () ;
if ( ! V_184 )
goto V_60;
V_184 -> V_191 = V_268 ;
V_184 -> V_193 = ( void * ) F_125 ( V_5 ) ;
if ( ! V_184 -> V_193 )
goto V_60;
V_184 -> V_365 = V_202 ;
V_202 -> V_279 = V_184 ;
V_202 -> V_366 . V_367 = 0 ;
V_202 -> V_366 . V_368 = ~ 0ULL ;
V_202 -> V_366 . V_369 = true ;
return 0 ;
V_60:
F_259 ( V_184 ) ;
return - V_49 ;
}
static void F_263 ( struct V_365 * V_202 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
if ( ! V_184 )
return;
if ( V_184 -> V_293 > 0 )
F_258 ( V_184 ) ;
F_129 ( V_184 -> V_293 != 0 ) ;
if ( V_184 -> V_191 != V_265 )
F_175 ( V_184 ) ;
if ( V_184 -> V_4 & V_285 )
F_185 ( V_184 ) ;
F_259 ( V_184 ) ;
V_202 -> V_279 = NULL ;
}
static void F_264 ( struct V_365 * V_202 ,
struct V_11 * V_12 )
{
struct V_1 * V_3 = V_12 -> V_18 . V_19 ;
struct V_54 * V_19 ;
T_1 V_2 ;
if ( ! F_23 ( V_12 ) )
return;
V_2 = F_14 ( V_12 ) ;
if ( V_3 -> V_184 != NULL )
F_219 ( V_12 ) ;
V_19 = V_38 [ V_2 ] ;
if ( ! V_19 )
return;
F_107 ( V_19 ) ;
}
static int F_265 ( struct V_365 * V_202 ,
struct V_11 * V_12 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
struct V_1 * V_3 ;
struct V_54 * V_19 ;
int V_30 ;
if ( ! F_23 ( V_12 ) )
return - V_206 ;
V_3 = V_12 -> V_18 . V_19 ;
V_19 = V_38 [ V_3 -> V_2 ] ;
if ( ! V_19 )
return - V_206 ;
if ( V_3 -> V_184 )
F_219 ( V_12 ) ;
V_30 = F_215 ( V_12 , V_184 ) ;
F_107 ( V_19 ) ;
return V_30 ;
}
static int F_266 ( struct V_365 * V_202 , unsigned long V_370 ,
T_10 V_322 , T_7 V_195 , int V_371 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
int V_204 = 0 ;
int V_30 ;
if ( V_184 -> V_191 == V_265 )
return - V_206 ;
if ( V_371 & V_372 )
V_204 |= V_210 ;
if ( V_371 & V_373 )
V_204 |= V_212 ;
F_267 ( & V_184 -> V_364 ) ;
V_30 = F_141 ( V_184 , V_370 , V_322 , V_204 , V_195 ) ;
F_268 ( & V_184 -> V_364 ) ;
return V_30 ;
}
static T_7 F_269 ( struct V_365 * V_202 , unsigned long V_370 ,
T_7 V_195 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
T_7 V_214 ;
if ( V_184 -> V_191 == V_265 )
return - V_206 ;
F_267 ( & V_184 -> V_364 ) ;
V_214 = F_146 ( V_184 , V_370 , V_195 ) ;
F_268 ( & V_184 -> V_364 ) ;
F_121 ( V_184 ) ;
return V_214 ;
}
static T_10 F_270 ( struct V_365 * V_202 ,
T_9 V_370 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
unsigned long V_374 ;
T_10 V_322 ;
T_5 * V_190 , V_201 ;
if ( V_184 -> V_191 == V_265 )
return V_370 ;
V_190 = F_138 ( V_184 , V_370 ) ;
if ( ! V_190 || ! F_135 ( * V_190 ) )
return 0 ;
if ( F_136 ( * V_190 ) == 0 )
V_374 = V_154 - 1 ;
else
V_374 = F_139 ( * V_190 ) - 1 ;
V_201 = * V_190 & V_375 ;
V_322 = ( V_201 & ~ V_374 ) | ( V_370 & V_374 ) ;
return V_322 ;
}
static int F_271 ( struct V_365 * V_184 ,
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
int T_4 F_272 ( void )
{
struct V_1 * V_3 ;
struct V_13 * V_12 = NULL ;
struct V_54 * V_19 ;
T_1 V_2 ;
int V_30 ;
V_30 = F_252 () ;
if ( V_30 )
return V_30 ;
F_56 (dev) {
if ( ! F_23 ( & V_12 -> V_12 ) )
continue;
V_3 = F_17 ( & V_12 -> V_12 ) ;
V_3 -> V_304 = true ;
V_2 = F_14 ( & V_12 -> V_12 ) ;
V_19 = V_38 [ V_2 ] ;
if ( ! V_19 )
continue;
F_215 ( & V_12 -> V_12 , V_307 ) ;
}
F_61 () ;
F_253 ( L_29 ) ;
return 0 ;
}
int F_273 ( struct V_308 * V_309 )
{
return F_274 ( & V_128 , V_309 ) ;
}
int F_275 ( struct V_308 * V_309 )
{
return F_276 ( & V_128 , V_309 ) ;
}
void F_277 ( struct V_365 * V_202 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
unsigned long V_4 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_184 -> V_191 = V_265 ;
V_184 -> V_194 = true ;
F_145 ( V_184 ) ;
F_175 ( V_184 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
}
int F_278 ( struct V_365 * V_202 , int V_380 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
unsigned long V_4 ;
int V_381 , V_30 ;
if ( V_380 <= 0 || V_380 > ( V_382 + 1 ) )
return - V_206 ;
for ( V_381 = 0 ; ( V_380 - 1 ) & ~ 0x1ff ; V_380 >>= 9 )
V_381 += 1 ;
if ( V_381 > V_383 )
return - V_206 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = - V_207 ;
if ( V_184 -> V_293 > 0 || V_184 -> V_4 & V_285 )
goto V_313;
V_30 = - V_49 ;
V_184 -> V_275 = ( void * ) F_125 ( V_321 ) ;
if ( V_184 -> V_275 == NULL )
goto V_313;
V_184 -> V_274 = V_381 ;
V_184 -> V_4 |= V_285 ;
V_184 -> V_194 = true ;
F_145 ( V_184 ) ;
V_30 = 0 ;
V_313:
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
static int F_279 ( struct V_183 * V_184 , int V_125 ,
T_5 V_93 , bool V_150 )
{
struct V_1 * V_3 ;
struct V_87 V_88 ;
int V_24 , V_30 ;
if ( ! ( V_184 -> V_4 & V_285 ) )
return - V_206 ;
F_100 ( & V_88 , V_184 -> V_185 , V_125 , V_93 , V_150 ) ;
for ( V_24 = 0 ; V_24 < V_186 ; ++ V_24 ) {
if ( V_184 -> V_187 [ V_24 ] == 0 )
continue;
V_30 = F_106 ( V_188 [ V_24 ] , & V_88 ) ;
if ( V_30 != 0 )
goto V_313;
}
F_122 ( V_184 ) ;
F_12 (dev_data, &domain->dev_list, list) {
struct V_54 * V_19 ;
int V_160 ;
F_129 ( ! V_3 -> V_181 . V_182 ) ;
V_160 = V_3 -> V_181 . V_160 ;
V_19 = V_38 [ V_3 -> V_2 ] ;
F_101 ( & V_88 , V_3 -> V_2 , V_125 ,
V_160 , V_93 , V_150 ) ;
V_30 = F_106 ( V_19 , & V_88 ) ;
if ( V_30 != 0 )
goto V_313;
}
F_122 ( V_184 ) ;
V_30 = 0 ;
V_313:
return V_30 ;
}
static int F_280 ( struct V_183 * V_184 , int V_125 ,
T_5 V_93 )
{
F_76 ( V_82 ) ;
return F_279 ( V_184 , V_125 , V_93 , false ) ;
}
int F_281 ( struct V_365 * V_202 , int V_125 ,
T_5 V_93 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = F_280 ( V_184 , V_125 , V_93 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
static int F_282 ( struct V_183 * V_184 , int V_125 )
{
F_76 ( V_83 ) ;
return F_279 ( V_184 , V_125 , V_155 ,
true ) ;
}
int F_283 ( struct V_365 * V_202 , int V_125 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = F_282 ( V_184 , V_125 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
static T_5 * F_284 ( T_5 * V_264 , int V_197 , int V_125 , bool V_384 )
{
int V_232 ;
T_5 * V_190 ;
while ( true ) {
V_232 = ( V_125 >> ( 9 * V_197 ) ) & 0x1ff ;
V_190 = & V_264 [ V_232 ] ;
if ( V_197 == 0 )
break;
if ( ! ( * V_190 & V_273 ) ) {
if ( ! V_384 )
return NULL ;
V_264 = ( void * ) F_125 ( V_321 ) ;
if ( V_264 == NULL )
return NULL ;
* V_190 = F_93 ( V_264 ) | V_273 ;
}
V_264 = F_183 ( * V_190 & V_156 ) ;
V_197 -= 1 ;
}
return V_190 ;
}
static int F_285 ( struct V_183 * V_184 , int V_125 ,
unsigned long V_385 )
{
T_5 * V_190 ;
if ( V_184 -> V_191 != V_265 )
return - V_206 ;
V_190 = F_284 ( V_184 -> V_275 , V_184 -> V_274 , V_125 , true ) ;
if ( V_190 == NULL )
return - V_49 ;
* V_190 = ( V_385 & V_156 ) | V_273 ;
return F_282 ( V_184 , V_125 ) ;
}
static int F_286 ( struct V_183 * V_184 , int V_125 )
{
T_5 * V_190 ;
if ( V_184 -> V_191 != V_265 )
return - V_206 ;
V_190 = F_284 ( V_184 -> V_275 , V_184 -> V_274 , V_125 , false ) ;
if ( V_190 == NULL )
return 0 ;
* V_190 = 0 ;
return F_282 ( V_184 , V_125 ) ;
}
int F_287 ( struct V_365 * V_202 , int V_125 ,
unsigned long V_385 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = F_285 ( V_184 , V_125 , V_385 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
int F_288 ( struct V_365 * V_202 , int V_125 )
{
struct V_183 * V_184 = V_202 -> V_279 ;
unsigned long V_4 ;
int V_30 ;
F_4 ( & V_184 -> V_174 , V_4 ) ;
V_30 = F_286 ( V_184 , V_125 ) ;
F_6 ( & V_184 -> V_174 , V_4 ) ;
return V_30 ;
}
int F_289 ( struct V_13 * V_14 , int V_125 ,
int V_135 , int V_127 )
{
struct V_1 * V_3 ;
struct V_54 * V_19 ;
struct V_87 V_88 ;
F_76 ( V_81 ) ;
V_3 = F_17 ( & V_14 -> V_12 ) ;
V_19 = V_38 [ V_3 -> V_2 ] ;
F_102 ( & V_88 , V_3 -> V_2 , V_125 , V_135 ,
V_127 , V_3 -> V_305 ) ;
return F_106 ( V_19 , & V_88 ) ;
}
struct V_365 * F_290 ( struct V_13 * V_14 )
{
struct V_183 * V_184 ;
V_184 = F_226 ( & V_14 -> V_12 ) ;
if ( F_36 ( V_184 ) )
return NULL ;
if ( ! ( V_184 -> V_4 & V_285 ) )
return NULL ;
return V_184 -> V_365 ;
}
void F_291 ( struct V_13 * V_14 , T_2 V_26 )
{
struct V_1 * V_3 ;
if ( ! F_292 () )
return;
V_3 = F_17 ( & V_14 -> V_12 ) ;
V_3 -> V_27 |= ( 1 << V_26 ) ;
}
int F_293 ( struct V_13 * V_14 ,
struct F_293 * V_386 )
{
int V_387 ;
int V_25 ;
if ( V_14 == NULL || V_386 == NULL )
return - V_206 ;
if ( ! F_292 () )
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
V_387 = 1 << ( 9 * ( V_383 + 1 ) ) ;
V_387 = F_294 ( V_387 , ( 1 << 20 ) ) ;
V_386 -> V_4 |= V_391 ;
V_386 -> V_387 = F_294 ( F_295 ( V_14 ) , V_387 ) ;
V_390 = F_296 ( V_14 ) ;
if ( V_390 & V_392 )
V_386 -> V_4 |= V_393 ;
if ( V_390 & V_394 )
V_386 -> V_4 |= V_395 ;
}
return 0 ;
}
static void F_297 ( T_1 V_2 , struct V_396 * V_397 )
{
T_5 V_398 ;
V_398 = V_57 [ V_2 ] . V_85 [ 2 ] ;
V_398 &= ~ V_399 ;
V_398 |= F_127 ( V_397 -> V_397 ) ;
V_398 |= V_400 ;
V_398 |= V_401 ;
V_398 |= V_402 ;
V_57 [ V_2 ] . V_85 [ 2 ] = V_398 ;
}
static struct V_396 * F_298 ( T_1 V_2 , bool V_403 )
{
struct V_396 * V_397 = NULL ;
struct V_54 * V_19 ;
unsigned long V_4 ;
T_1 V_31 ;
F_170 ( & V_261 , V_4 ) ;
V_19 = V_38 [ V_2 ] ;
if ( ! V_19 )
goto V_10;
V_397 = V_404 [ V_2 ] ;
if ( V_397 )
goto V_313;
V_31 = V_32 [ V_2 ] ;
V_397 = V_404 [ V_31 ] ;
if ( V_397 ) {
V_404 [ V_2 ] = V_397 ;
F_297 ( V_2 , V_397 ) ;
F_108 ( V_19 , V_2 ) ;
goto V_313;
}
V_397 = F_2 ( sizeof( * V_397 ) , V_321 ) ;
if ( ! V_397 )
goto V_313;
F_188 ( & V_397 -> V_174 ) ;
if ( V_403 )
V_397 -> V_405 = 32 ;
V_397 -> V_397 = F_299 ( V_406 , V_321 ) ;
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
F_297 ( V_2 , V_397 ) ;
F_108 ( V_19 , V_2 ) ;
if ( V_2 != V_31 ) {
V_404 [ V_31 ] = V_397 ;
F_297 ( V_31 , V_397 ) ;
F_108 ( V_19 , V_31 ) ;
}
V_313:
F_107 ( V_19 ) ;
V_10:
F_172 ( & V_261 , V_4 ) ;
return V_397 ;
}
static int F_300 ( struct V_409 * V_410 , T_1 V_2 , int V_92 )
{
struct V_396 * V_397 ;
unsigned long V_4 ;
int V_232 , V_411 ;
V_397 = F_298 ( V_2 , false ) ;
if ( ! V_397 )
return - V_42 ;
F_4 ( & V_397 -> V_174 , V_4 ) ;
for ( V_411 = 0 , V_232 = V_397 -> V_405 ;
V_232 < V_407 ;
++ V_232 ) {
if ( V_397 -> V_397 [ V_232 ] == 0 )
V_411 += 1 ;
else
V_411 = 0 ;
if ( V_411 == V_92 ) {
struct V_412 * V_413 ;
for (; V_411 != 0 ; -- V_411 )
V_397 -> V_397 [ V_232 - V_411 + 1 ] = V_408 ;
V_232 -= V_92 - 1 ;
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
static int F_301 ( T_1 V_2 , int V_232 , union V_416 * V_416 )
{
struct V_396 * V_397 ;
unsigned long V_4 ;
V_397 = F_298 ( V_2 , false ) ;
if ( ! V_397 )
return - V_49 ;
F_4 ( & V_397 -> V_174 , V_4 ) ;
V_416 -> V_417 = V_397 -> V_397 [ V_232 ] ;
F_6 ( & V_397 -> V_174 , V_4 ) ;
return 0 ;
}
static int F_302 ( T_1 V_2 , int V_232 , union V_416 V_416 )
{
struct V_396 * V_397 ;
struct V_54 * V_19 ;
unsigned long V_4 ;
V_19 = V_38 [ V_2 ] ;
if ( V_19 == NULL )
return - V_206 ;
V_397 = F_298 ( V_2 , false ) ;
if ( ! V_397 )
return - V_49 ;
F_4 ( & V_397 -> V_174 , V_4 ) ;
V_397 -> V_397 [ V_232 ] = V_416 . V_417 ;
F_6 ( & V_397 -> V_174 , V_4 ) ;
F_112 ( V_19 , V_2 ) ;
F_107 ( V_19 ) ;
return 0 ;
}
static void F_303 ( T_1 V_2 , int V_232 )
{
struct V_396 * V_397 ;
struct V_54 * V_19 ;
unsigned long V_4 ;
V_19 = V_38 [ V_2 ] ;
if ( V_19 == NULL )
return;
V_397 = F_298 ( V_2 , false ) ;
if ( ! V_397 )
return;
F_4 ( & V_397 -> V_174 , V_4 ) ;
V_397 -> V_397 [ V_232 ] = 0 ;
F_6 ( & V_397 -> V_174 , V_4 ) ;
F_112 ( V_19 , V_2 ) ;
F_107 ( V_19 ) ;
}
static int F_304 ( int V_134 , struct V_418 * V_29 ,
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
V_410 = F_305 ( V_134 ) ;
if ( ! V_410 )
return - V_206 ;
V_413 = & V_410 -> V_412 ;
V_423 = F_306 ( V_422 -> V_403 ) ;
V_2 = F_307 ( V_423 ) ;
if ( V_2 < 0 )
return V_2 ;
V_397 = F_298 ( V_2 , true ) ;
if ( V_397 == NULL )
return - V_49 ;
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
V_30 = F_302 ( V_2 , V_232 , V_416 ) ;
if ( V_30 )
return V_30 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_420 = V_232 ;
V_29 -> V_352 = 0 ;
V_29 -> V_432 = V_422 -> V_432 ;
V_29 -> V_433 = V_422 -> V_433 ;
if ( V_422 -> V_432 )
V_29 -> V_352 = 1 ;
return 0 ;
}
static int F_308 ( struct V_434 * V_85 , const struct V_435 * V_352 ,
bool V_436 )
{
struct V_412 * V_413 ;
unsigned int V_437 , V_134 ;
struct V_409 * V_410 ;
union V_416 V_416 ;
int V_438 ;
if ( ! F_309 ( V_439 ) )
return - 1 ;
V_410 = V_85 -> V_440 ;
V_134 = V_85 -> V_134 ;
V_413 = & V_410 -> V_412 ;
if ( ! F_310 ( V_352 , V_441 ) )
return - V_206 ;
if ( F_301 ( V_413 -> V_2 , V_413 -> V_232 , & V_416 ) )
return - V_207 ;
if ( F_311 ( V_134 , V_410 , V_352 ) )
return - V_207 ;
V_438 = V_427 -> V_442 ( V_410 -> V_184 , V_352 , & V_437 ) ;
if ( V_438 ) {
if ( F_311 ( V_134 , V_410 , V_85 -> V_443 ) )
F_50 ( L_30 , V_134 ) ;
return V_438 ;
}
V_416 . V_425 . V_420 = V_410 -> V_420 ;
V_416 . V_425 . V_419 = V_437 ;
F_302 ( V_413 -> V_2 , V_413 -> V_232 , V_416 ) ;
if ( V_410 -> V_444 )
F_312 ( V_410 ) ;
F_313 ( V_85 -> V_443 , V_352 ) ;
return 0 ;
}
static int F_314 ( int V_134 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
V_410 = F_305 ( V_134 ) ;
if ( ! V_410 )
return - V_206 ;
V_413 = & V_410 -> V_412 ;
F_303 ( V_413 -> V_2 , V_413 -> V_232 ) ;
return 0 ;
}
static void F_315 ( struct V_13 * V_14 ,
unsigned int V_134 , unsigned int V_437 ,
struct V_445 * V_446 , T_3 V_447 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
union V_416 V_416 ;
V_410 = F_305 ( V_134 ) ;
if ( ! V_410 )
return;
V_413 = & V_410 -> V_412 ;
V_416 . V_417 = 0 ;
V_416 . V_425 . V_420 = V_410 -> V_420 ;
V_416 . V_425 . V_426 = V_427 -> V_428 ;
V_416 . V_425 . V_419 = V_437 ;
V_416 . V_425 . V_429 = V_427 -> V_430 ;
V_416 . V_425 . V_431 = 1 ;
F_302 ( V_413 -> V_2 , V_413 -> V_232 , V_416 ) ;
V_446 -> V_448 = V_449 ;
V_446 -> V_450 = V_243 ;
V_446 -> V_85 = V_413 -> V_232 ;
}
static int F_316 ( struct V_13 * V_14 , int V_134 , int V_451 )
{
struct V_409 * V_410 ;
int V_232 ;
T_1 V_2 ;
if ( ! V_14 )
return - V_206 ;
V_410 = F_305 ( V_134 ) ;
if ( ! V_410 )
return - V_206 ;
V_2 = F_14 ( & V_14 -> V_12 ) ;
V_232 = F_300 ( V_410 , V_2 , V_451 ) ;
return V_232 < 0 ? V_407 : V_232 ;
}
static int F_317 ( struct V_13 * V_14 , unsigned int V_134 ,
int V_232 , int V_239 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
T_1 V_2 ;
if ( ! V_14 )
return - V_206 ;
V_410 = F_305 ( V_134 ) ;
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
static int F_318 ( unsigned int V_134 , unsigned int V_185 )
{
struct V_412 * V_413 ;
struct V_409 * V_410 ;
int V_232 , V_2 ;
V_410 = F_305 ( V_134 ) ;
if ( ! V_410 )
return - V_206 ;
V_413 = & V_410 -> V_412 ;
V_2 = F_319 ( V_185 ) ;
if ( V_2 < 0 )
return V_2 ;
V_232 = F_300 ( V_410 , V_2 , 1 ) ;
if ( V_232 < 0 )
return V_232 ;
V_410 -> V_414 = 1 ;
V_413 -> V_2 = V_2 ;
V_413 -> V_232 = V_232 ;
return 0 ;
}
