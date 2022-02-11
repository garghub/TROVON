static inline T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 -> V_6 , V_4 -> V_7 ) ;
}
static struct V_8 * F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_9 . V_10 ;
}
static struct V_11 * F_5 ( T_1 V_12 )
{
struct V_11 * V_13 , * V_14 = NULL ;
unsigned long V_15 ;
T_1 V_16 = V_17 [ V_12 ] ;
if ( F_6 ( & V_18 ) )
return NULL ;
F_7 ( & V_19 , V_15 ) ;
F_8 (entry, &iommu_pd_list, list) {
if ( V_13 -> V_20 == V_12 ||
V_13 -> V_20 == V_16 ) {
V_14 = V_13 ;
break;
}
}
F_9 ( & V_19 , V_15 ) ;
return V_14 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
T_1 V_12 ;
if ( ! V_2 || ! V_2 -> V_21 )
return false ;
if ( V_2 -> V_5 != & V_22 )
return false ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 > V_23 )
return false ;
if ( V_24 [ V_12 ] == NULL )
return false ;
return true ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_25 ;
struct V_3 * V_4 ;
T_1 V_12 , V_16 ;
if ( V_2 -> V_9 . V_10 )
return 0 ;
V_25 = F_12 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 )
return - V_27 ;
V_25 -> V_2 = V_2 ;
V_12 = F_1 ( V_2 ) ;
V_16 = V_17 [ V_12 ] ;
V_4 = F_13 ( F_14 ( V_16 ) , V_16 & 0xff ) ;
if ( V_4 )
V_25 -> V_16 = & V_4 -> V_2 ;
else {
F_15 ( V_25 ) ;
return - V_28 ;
}
F_16 ( & V_25 -> V_29 , 0 ) ;
V_2 -> V_9 . V_10 = V_25 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_12 , V_16 ;
V_12 = F_1 ( V_2 ) ;
V_16 = V_17 [ V_12 ] ;
memset ( & V_30 [ V_12 ] , 0 , sizeof( struct V_31 ) ) ;
memset ( & V_30 [ V_16 ] , 0 , sizeof( struct V_31 ) ) ;
V_24 [ V_12 ] = NULL ;
V_24 [ V_16 ] = NULL ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_9 . V_10 ) ;
}
void T_2 F_19 ( void )
{
struct V_3 * V_4 = NULL ;
F_20 (pdev) {
if ( ! F_10 ( & V_4 -> V_2 ) )
continue;
F_18 ( & V_4 -> V_2 ) ;
}
}
int T_2 F_21 ( void )
{
struct V_3 * V_4 = NULL ;
int V_14 = 0 ;
F_20 (pdev) {
if ( ! F_10 ( & V_4 -> V_2 ) )
continue;
V_14 = F_11 ( & V_4 -> V_2 ) ;
if ( V_14 == - V_28 )
F_17 ( & V_4 -> V_2 ) ;
else if ( V_14 )
goto V_32;
}
return 0 ;
V_32:
F_19 () ;
return V_14 ;
}
static void F_22 ( struct V_33 * V_34 )
{
if ( V_35 == NULL )
return;
V_34 -> V_36 = F_23 ( V_34 -> V_37 , 0444 , V_35 ,
& V_34 -> V_38 ) ;
}
static void F_24 ( void )
{
V_35 = F_25 ( L_1 , NULL ) ;
if ( V_35 == NULL )
return;
V_39 = F_26 ( L_2 , 0444 , V_35 ,
( V_40 * ) & V_41 ) ;
F_22 ( & V_42 ) ;
F_22 ( & V_43 ) ;
F_22 ( & V_44 ) ;
F_22 ( & V_45 ) ;
F_22 ( & V_46 ) ;
F_22 ( & V_47 ) ;
F_22 ( & V_48 ) ;
F_22 ( & V_49 ) ;
F_22 ( & V_50 ) ;
F_22 ( & V_51 ) ;
F_22 ( & V_52 ) ;
F_22 ( & V_53 ) ;
}
static void F_27 ( T_1 V_12 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < 8 ; ++ V_54 )
F_28 ( L_3 , V_54 ,
V_30 [ V_12 ] . V_55 [ V_54 ] ) ;
}
static void F_29 ( unsigned long V_56 )
{
struct V_57 * V_58 = F_30 ( V_56 ) ;
int V_54 ;
for ( V_54 = 0 ; V_54 < 4 ; ++ V_54 )
F_28 ( L_4 , V_54 , V_58 -> V_55 [ V_54 ] ) ;
}
static void F_31 ( struct V_59 * V_10 , void * V_60 )
{
V_40 * V_61 = V_60 ;
int type = ( V_61 [ 1 ] >> V_62 ) & V_63 ;
int V_12 = ( V_61 [ 0 ] >> V_64 ) & V_65 ;
int V_66 = ( V_61 [ 1 ] >> V_67 ) & V_68 ;
int V_15 = ( V_61 [ 1 ] >> V_69 ) & V_70 ;
T_3 V_71 = ( T_3 ) ( ( ( T_3 ) V_61 [ 3 ] ) << 32 ) | V_61 [ 2 ] ;
F_32 ( V_72 L_5 ) ;
switch ( type ) {
case V_73 :
F_32 ( L_6
L_7 ,
F_14 ( V_12 ) , F_33 ( V_12 ) , F_34 ( V_12 ) ,
V_71 , V_15 ) ;
F_27 ( V_12 ) ;
break;
case V_74 :
F_32 ( L_8
L_9 ,
F_14 ( V_12 ) , F_33 ( V_12 ) , F_34 ( V_12 ) ,
V_66 , V_71 , V_15 ) ;
break;
case V_75 :
F_32 ( L_10
L_7 ,
F_14 ( V_12 ) , F_33 ( V_12 ) , F_34 ( V_12 ) ,
V_71 , V_15 ) ;
break;
case V_76 :
F_32 ( L_11
L_9 ,
F_14 ( V_12 ) , F_33 ( V_12 ) , F_34 ( V_12 ) ,
V_66 , V_71 , V_15 ) ;
break;
case V_77 :
F_32 ( L_12 , V_71 ) ;
F_29 ( V_71 ) ;
break;
case V_78 :
F_32 ( L_13
L_14 , V_71 , V_15 ) ;
break;
case V_79 :
F_32 ( L_15
L_16 ,
F_14 ( V_12 ) , F_33 ( V_12 ) , F_34 ( V_12 ) ,
V_71 ) ;
break;
case V_80 :
F_32 ( L_17
L_7 ,
F_14 ( V_12 ) , F_33 ( V_12 ) , F_34 ( V_12 ) ,
V_71 , V_15 ) ;
break;
default:
F_32 ( V_72 L_18 , type ) ;
}
}
static void F_35 ( struct V_59 * V_10 )
{
V_40 V_81 , V_82 ;
unsigned long V_15 ;
F_7 ( & V_10 -> V_83 , V_15 ) ;
V_81 = F_36 ( V_10 -> V_84 + V_85 ) ;
V_82 = F_36 ( V_10 -> V_84 + V_86 ) ;
while ( V_81 != V_82 ) {
F_31 ( V_10 , V_10 -> V_87 + V_81 ) ;
V_81 = ( V_81 + V_88 ) % V_10 -> V_89 ;
}
F_37 ( V_81 , V_10 -> V_84 + V_85 ) ;
F_9 ( & V_10 -> V_83 , V_15 ) ;
}
T_4 F_38 ( int V_90 , void * V_55 )
{
struct V_59 * V_10 ;
F_39 (iommu)
F_35 ( V_10 ) ;
return V_91 ;
}
T_4 F_40 ( int V_90 , void * V_55 )
{
return V_92 ;
}
static int F_41 ( volatile T_3 * V_93 )
{
int V_54 = 0 ;
while ( * V_93 == 0 && V_54 < V_94 ) {
F_42 ( 1 ) ;
V_54 += 1 ;
}
if ( V_54 == V_94 ) {
F_43 ( L_19 ) ;
return - V_95 ;
}
return 0 ;
}
static void F_44 ( struct V_59 * V_10 ,
struct V_57 * V_58 ,
V_40 V_82 )
{
T_5 * V_96 ;
V_96 = V_10 -> V_97 + V_82 ;
V_82 = ( V_82 + sizeof( * V_58 ) ) % V_10 -> V_98 ;
memcpy ( V_96 , V_58 , sizeof( * V_58 ) ) ;
F_37 ( V_82 , V_10 -> V_84 + V_99 ) ;
}
static void F_45 ( struct V_57 * V_58 , T_3 V_71 )
{
F_46 ( V_71 & 0x7ULL ) ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_55 [ 0 ] = F_47 ( F_48 ( V_71 ) ) | V_100 ;
V_58 -> V_55 [ 1 ] = F_49 ( F_48 ( V_71 ) ) ;
V_58 -> V_55 [ 2 ] = 1 ;
F_50 ( V_58 , V_101 ) ;
}
static void F_51 ( struct V_57 * V_58 , T_1 V_12 )
{
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_55 [ 0 ] = V_12 ;
F_50 ( V_58 , V_102 ) ;
}
static void F_52 ( struct V_57 * V_58 , T_3 V_71 ,
T_6 V_103 , T_1 V_66 , int V_104 )
{
T_3 V_105 ;
int V_106 ;
V_105 = F_53 ( V_71 , V_103 , V_107 ) ;
V_106 = 0 ;
if ( V_105 > 1 ) {
V_71 = V_108 ;
V_106 = 1 ;
}
V_71 &= V_109 ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_55 [ 1 ] |= V_66 ;
V_58 -> V_55 [ 2 ] = F_47 ( V_71 ) ;
V_58 -> V_55 [ 3 ] = F_49 ( V_71 ) ;
F_50 ( V_58 , V_110 ) ;
if ( V_106 )
V_58 -> V_55 [ 2 ] |= V_111 ;
if ( V_104 )
V_58 -> V_55 [ 2 ] |= V_112 ;
}
static void F_54 ( struct V_57 * V_58 , T_1 V_12 , int V_113 ,
T_3 V_71 , T_6 V_103 )
{
T_3 V_105 ;
int V_106 ;
V_105 = F_53 ( V_71 , V_103 , V_107 ) ;
V_106 = 0 ;
if ( V_105 > 1 ) {
V_71 = V_108 ;
V_106 = 1 ;
}
V_71 &= V_109 ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_55 [ 0 ] = V_12 ;
V_58 -> V_55 [ 0 ] |= ( V_113 & 0xff ) << 24 ;
V_58 -> V_55 [ 1 ] = V_12 ;
V_58 -> V_55 [ 2 ] = F_47 ( V_71 ) ;
V_58 -> V_55 [ 3 ] = F_49 ( V_71 ) ;
F_50 ( V_58 , V_114 ) ;
if ( V_106 )
V_58 -> V_55 [ 2 ] |= V_111 ;
}
static void F_55 ( struct V_57 * V_58 )
{
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
F_50 ( V_58 , V_115 ) ;
}
static int F_56 ( struct V_59 * V_10 , struct V_57 * V_58 )
{
V_40 V_116 , V_82 , V_81 , V_117 ;
unsigned long V_15 ;
F_46 ( V_10 -> V_98 & V_118 ) ;
V_119:
F_7 ( & V_10 -> V_83 , V_15 ) ;
V_81 = F_36 ( V_10 -> V_84 + V_120 ) ;
V_82 = F_36 ( V_10 -> V_84 + V_99 ) ;
V_117 = ( V_82 + sizeof( * V_58 ) ) % V_10 -> V_98 ;
V_116 = ( V_81 - V_117 ) % V_10 -> V_98 ;
if ( V_116 <= 2 ) {
struct V_57 V_121 ;
volatile T_3 V_93 = 0 ;
int V_14 ;
F_45 ( & V_121 , ( T_3 ) & V_93 ) ;
F_44 ( V_10 , & V_121 , V_82 ) ;
F_9 ( & V_10 -> V_83 , V_15 ) ;
if ( ( V_14 = F_41 ( & V_93 ) ) != 0 )
return V_14 ;
goto V_119;
}
F_44 ( V_10 , V_58 , V_82 ) ;
V_10 -> V_122 = true ;
F_9 ( & V_10 -> V_83 , V_15 ) ;
return 0 ;
}
static int F_57 ( struct V_59 * V_10 )
{
struct V_57 V_58 ;
volatile T_3 V_93 = 0 ;
int V_14 ;
if ( ! V_10 -> V_122 )
return 0 ;
F_45 ( & V_58 , ( T_3 ) & V_93 ) ;
V_14 = F_56 ( V_10 , & V_58 ) ;
if ( V_14 )
return V_14 ;
return F_41 ( & V_93 ) ;
}
static int F_58 ( struct V_59 * V_10 , T_1 V_12 )
{
struct V_57 V_58 ;
F_51 ( & V_58 , V_12 ) ;
return F_56 ( V_10 , & V_58 ) ;
}
static void F_59 ( struct V_59 * V_10 )
{
V_40 V_12 ;
for ( V_12 = 0 ; V_12 <= 0xffff ; ++ V_12 )
F_58 ( V_10 , V_12 ) ;
F_57 ( V_10 ) ;
}
static void F_60 ( struct V_59 * V_10 )
{
V_40 V_123 ;
for ( V_123 = 0 ; V_123 <= 0xffff ; ++ V_123 ) {
struct V_57 V_58 ;
F_52 ( & V_58 , 0 , V_108 ,
V_123 , 1 ) ;
F_56 ( V_10 , & V_58 ) ;
}
F_57 ( V_10 ) ;
}
static void F_61 ( struct V_59 * V_10 )
{
struct V_57 V_58 ;
F_55 ( & V_58 ) ;
F_56 ( V_10 , & V_58 ) ;
F_57 ( V_10 ) ;
}
void F_62 ( struct V_59 * V_10 )
{
if ( F_63 ( V_10 , V_124 ) ) {
F_61 ( V_10 ) ;
} else {
F_59 ( V_10 ) ;
F_60 ( V_10 ) ;
}
}
static int F_64 ( struct V_1 * V_2 , T_3 V_71 , T_6 V_103 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_59 * V_10 ;
struct V_57 V_58 ;
T_1 V_12 ;
int V_113 ;
V_113 = F_65 ( V_4 ) ;
V_12 = F_1 ( V_2 ) ;
V_10 = V_24 [ V_12 ] ;
F_54 ( & V_58 , V_12 , V_113 , V_71 , V_103 ) ;
return F_56 ( V_10 , & V_58 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_59 * V_10 ;
struct V_3 * V_4 ;
T_1 V_12 ;
int V_14 ;
V_4 = F_2 ( V_2 ) ;
V_12 = F_1 ( V_2 ) ;
V_10 = V_24 [ V_12 ] ;
V_14 = F_58 ( V_10 , V_12 ) ;
if ( V_14 )
return V_14 ;
if ( F_67 ( V_4 ) )
V_14 = F_64 ( V_2 , 0 , ~ 0UL ) ;
return V_14 ;
}
static void F_68 ( struct V_125 * V_126 ,
T_3 V_71 , T_6 V_103 , int V_104 )
{
struct V_8 * V_25 ;
struct V_57 V_58 ;
int V_14 = 0 , V_54 ;
F_52 ( & V_58 , V_71 , V_103 , V_126 -> V_127 , V_104 ) ;
for ( V_54 = 0 ; V_54 < V_128 ; ++ V_54 ) {
if ( ! V_126 -> V_129 [ V_54 ] )
continue;
V_14 |= F_56 ( V_130 [ V_54 ] , & V_58 ) ;
}
F_8 (dev_data, &domain->dev_list, list) {
struct V_3 * V_4 = F_2 ( V_25 -> V_2 ) ;
if ( ! F_67 ( V_4 ) )
continue;
V_14 |= F_64 ( V_25 -> V_2 , V_71 , V_103 ) ;
}
F_46 ( V_14 ) ;
}
static void F_69 ( struct V_125 * V_126 ,
T_3 V_71 , T_6 V_103 )
{
F_68 ( V_126 , V_71 , V_103 , 0 ) ;
}
static void F_70 ( struct V_125 * V_126 )
{
F_68 ( V_126 , 0 , V_108 , 0 ) ;
}
static void F_71 ( struct V_125 * V_126 )
{
F_68 ( V_126 , 0 , V_108 , 1 ) ;
}
static void F_72 ( struct V_125 * V_126 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_128 ; ++ V_54 ) {
if ( ! V_126 -> V_129 [ V_54 ] )
continue;
F_57 ( V_130 [ V_54 ] ) ;
}
}
static void F_73 ( struct V_125 * V_126 )
{
struct V_8 * V_25 ;
unsigned long V_15 ;
F_7 ( & V_126 -> V_83 , V_15 ) ;
F_8 (dev_data, &domain->dev_list, list)
F_66 ( V_25 -> V_2 ) ;
F_9 ( & V_126 -> V_83 , V_15 ) ;
}
static bool F_74 ( struct V_125 * V_126 ,
T_7 V_131 )
{
T_3 * V_132 ;
if ( V_126 -> V_133 == V_134 )
return false ;
V_132 = ( void * ) F_75 ( V_131 ) ;
if ( ! V_132 )
return false ;
* V_132 = F_76 ( V_126 -> V_133 ,
F_77 ( V_126 -> V_135 ) ) ;
V_126 -> V_135 = V_132 ;
V_126 -> V_133 += 1 ;
V_126 -> V_136 = true ;
return true ;
}
static T_3 * F_78 ( struct V_125 * V_126 ,
unsigned long V_71 ,
unsigned long V_137 ,
T_3 * * V_138 ,
T_7 V_131 )
{
int V_139 , V_140 ;
T_3 * V_132 , * V_141 ;
F_79 ( ! F_80 ( V_137 ) ) ;
while ( V_71 > F_81 ( V_126 -> V_133 ) )
F_74 ( V_126 , V_131 ) ;
V_139 = V_126 -> V_133 - 1 ;
V_132 = & V_126 -> V_135 [ F_82 ( V_139 , V_71 ) ] ;
V_71 = F_83 ( V_71 , V_137 ) ;
V_140 = F_84 ( V_137 ) ;
while ( V_139 > V_140 ) {
if ( ! F_85 ( * V_132 ) ) {
V_141 = ( T_3 * ) F_75 ( V_131 ) ;
if ( ! V_141 )
return NULL ;
* V_132 = F_76 ( V_139 , F_77 ( V_141 ) ) ;
}
if ( F_86 ( * V_132 ) != V_139 )
return NULL ;
V_139 -= 1 ;
V_132 = F_87 ( * V_132 ) ;
if ( V_138 && V_139 == V_140 )
* V_138 = V_132 ;
V_132 = & V_132 [ F_82 ( V_139 , V_71 ) ] ;
}
return V_132 ;
}
static T_3 * F_88 ( struct V_125 * V_126 , unsigned long V_71 )
{
int V_139 ;
T_3 * V_132 ;
if ( V_71 > F_81 ( V_126 -> V_133 ) )
return NULL ;
V_139 = V_126 -> V_133 - 1 ;
V_132 = & V_126 -> V_135 [ F_82 ( V_139 , V_71 ) ] ;
while ( V_139 > 0 ) {
if ( ! F_85 ( * V_132 ) )
return NULL ;
if ( F_86 ( * V_132 ) == 0x07 ) {
unsigned long V_142 , V_143 ;
V_142 = F_89 ( * V_132 ) ;
V_142 = ~ ( ( F_90 ( V_142 ) << 3 ) - 1 ) ;
V_143 = ( ( unsigned long ) V_132 ) & V_142 ;
return ( T_3 * ) V_143 ;
}
if ( F_86 ( * V_132 ) != V_139 )
return NULL ;
V_139 -= 1 ;
V_132 = F_87 ( * V_132 ) ;
V_132 = & V_132 [ F_82 ( V_139 , V_71 ) ] ;
}
return V_132 ;
}
static int F_91 ( struct V_125 * V_144 ,
unsigned long V_145 ,
unsigned long V_56 ,
int V_146 ,
unsigned long V_137 )
{
T_3 V_143 , * V_132 ;
int V_54 , V_147 ;
if ( ! ( V_146 & V_148 ) )
return - V_149 ;
V_145 = F_92 ( V_145 ) ;
V_56 = F_92 ( V_56 ) ;
V_147 = F_90 ( V_137 ) ;
V_132 = F_78 ( V_144 , V_145 , V_137 , NULL , V_26 ) ;
for ( V_54 = 0 ; V_54 < V_147 ; ++ V_54 )
if ( F_85 ( V_132 [ V_54 ] ) )
return - V_150 ;
if ( V_137 > V_107 ) {
V_143 = F_93 ( V_56 , V_137 ) ;
V_143 |= F_94 ( 7 ) | V_151 | V_152 ;
} else
V_143 = V_56 | V_151 | V_152 ;
if ( V_146 & V_153 )
V_143 |= V_154 ;
if ( V_146 & V_155 )
V_143 |= V_156 ;
for ( V_54 = 0 ; V_54 < V_147 ; ++ V_54 )
V_132 [ V_54 ] = V_143 ;
F_95 ( V_144 ) ;
return 0 ;
}
static unsigned long F_96 ( struct V_125 * V_144 ,
unsigned long V_145 ,
unsigned long V_137 )
{
unsigned long long V_157 , V_158 ;
T_3 * V_132 ;
F_79 ( ! F_80 ( V_137 ) ) ;
V_158 = 0 ;
while ( V_158 < V_137 ) {
V_132 = F_88 ( V_144 , V_145 ) ;
if ( ! V_132 ) {
V_157 = V_107 ;
} else if ( F_86 ( * V_132 ) == 0 ) {
V_157 = V_107 ;
* V_132 = 0ULL ;
} else {
int V_147 , V_54 ;
V_157 = F_89 ( * V_132 ) ;
V_147 = F_90 ( V_157 ) ;
for ( V_54 = 0 ; V_54 < V_147 ; V_54 ++ )
V_132 [ V_54 ] = 0ULL ;
}
V_145 = ( V_145 & ~ ( V_157 - 1 ) ) + V_157 ;
V_158 += V_157 ;
}
F_79 ( ! F_80 ( V_158 ) ) ;
return V_158 ;
}
static int F_97 ( struct V_59 * V_10 ,
struct V_159 * V_13 )
{
T_1 V_160 , V_54 ;
for ( V_54 = V_13 -> V_161 ; V_54 <= V_13 -> V_162 ; ++ V_54 ) {
V_160 = V_17 [ V_54 ] ;
if ( V_24 [ V_160 ] == V_10 )
return 1 ;
}
return 0 ;
}
static int F_98 ( struct V_11 * V_163 ,
struct V_159 * V_164 )
{
T_3 V_165 ;
int V_14 ;
for ( V_165 = V_164 -> V_166 ; V_165 < V_164 -> V_167 ;
V_165 += V_107 ) {
V_14 = F_91 ( & V_163 -> V_126 , V_165 , V_165 , V_164 -> V_146 ,
V_107 ) ;
if ( V_14 )
return V_14 ;
if ( V_165 < V_163 -> V_168 )
F_99 ( V_165 >> V_169 ,
V_163 -> V_170 [ 0 ] -> V_171 ) ;
}
return 0 ;
}
static int F_100 ( struct V_59 * V_10 )
{
struct V_159 * V_13 ;
int V_14 ;
F_8 (entry, &amd_iommu_unity_map, list) {
if ( ! F_97 ( V_10 , V_13 ) )
continue;
V_14 = F_98 ( V_10 -> V_172 , V_13 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static int F_101 ( struct V_11 * V_163 ,
T_1 V_12 )
{
struct V_159 * V_164 ;
int V_14 ;
F_8 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_12 >= V_164 -> V_161 && V_12 <= V_164 -> V_162 ) )
continue;
V_14 = F_98 ( V_163 , V_164 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static void F_102 ( struct V_11 * V_144 ,
unsigned long V_173 ,
unsigned int V_105 )
{
unsigned int V_54 , V_174 = V_144 -> V_168 >> V_169 ;
if ( V_173 + V_105 > V_174 )
V_105 = V_174 - V_173 ;
for ( V_54 = V_173 ; V_54 < V_173 + V_105 ; ++ V_54 ) {
int V_175 = V_54 / V_176 ;
int V_141 = V_54 % V_176 ;
F_99 ( V_141 , V_144 -> V_170 [ V_175 ] -> V_171 ) ;
}
}
static int F_103 ( struct V_11 * V_163 ,
bool V_177 , T_7 V_131 )
{
int V_175 = V_163 -> V_168 >> V_178 ;
struct V_59 * V_10 ;
unsigned long V_54 ;
#ifdef F_104
V_177 = false ;
#endif
if ( V_175 >= V_179 )
return - V_27 ;
V_163 -> V_170 [ V_175 ] = F_12 ( sizeof( struct V_180 ) , V_131 ) ;
if ( ! V_163 -> V_170 [ V_175 ] )
return - V_27 ;
V_163 -> V_170 [ V_175 ] -> V_171 = ( void * ) F_75 ( V_131 ) ;
if ( ! V_163 -> V_170 [ V_175 ] -> V_171 )
goto V_32;
V_163 -> V_170 [ V_175 ] -> V_181 = V_163 -> V_168 ;
if ( V_177 ) {
unsigned long V_71 = V_163 -> V_168 ;
int V_54 , V_182 = V_176 / 512 ;
T_3 * V_132 , * V_138 ;
for ( V_54 = 0 ; V_54 < V_182 ; ++ V_54 ) {
V_132 = F_78 ( & V_163 -> V_126 , V_71 , V_107 ,
& V_138 , V_131 ) ;
if ( ! V_132 )
goto V_32;
V_163 -> V_170 [ V_175 ] -> V_183 [ V_54 ] = V_138 ;
V_71 += V_184 / 64 ;
}
}
V_163 -> V_168 += V_184 ;
F_39 (iommu) {
if ( V_10 -> V_185 &&
V_10 -> V_185 >= V_163 -> V_170 [ V_175 ] -> V_181
&& V_10 -> V_185 < V_163 -> V_168 ) {
unsigned long V_186 ;
int V_105 = F_53 ( V_10 -> V_185 ,
V_10 -> V_187 ,
V_107 ) ;
V_186 = V_10 -> V_185 >> V_169 ;
F_102 ( V_163 , V_186 , V_105 ) ;
}
}
for ( V_54 = V_163 -> V_170 [ V_175 ] -> V_181 ;
V_54 < V_163 -> V_168 ;
V_54 += V_107 ) {
T_3 * V_132 = F_88 ( & V_163 -> V_126 , V_54 ) ;
if ( ! V_132 || ! F_85 ( * V_132 ) )
continue;
F_102 ( V_163 , V_54 << V_169 , 1 ) ;
}
F_95 ( & V_163 -> V_126 ) ;
return 0 ;
V_32:
F_95 ( & V_163 -> V_126 ) ;
F_105 ( ( unsigned long ) V_163 -> V_170 [ V_175 ] -> V_171 ) ;
F_15 ( V_163 -> V_170 [ V_175 ] ) ;
V_163 -> V_170 [ V_175 ] = NULL ;
return - V_27 ;
}
static unsigned long F_106 ( struct V_1 * V_2 ,
struct V_11 * V_144 ,
unsigned int V_105 ,
unsigned long V_188 ,
T_3 V_21 ,
unsigned long V_189 )
{
unsigned long V_190 = V_144 -> V_191 % V_184 ;
int V_192 = V_144 -> V_168 >> V_178 ;
int V_54 = V_189 >> V_178 ;
unsigned long V_193 ;
unsigned long V_71 = - 1 ;
unsigned long V_194 ;
V_190 >>= V_169 ;
V_193 = F_107 ( F_108 ( V_2 ) + 1 ,
V_107 ) >> V_169 ;
for (; V_54 < V_192 ; ++ V_54 ) {
unsigned long V_181 = V_144 -> V_170 [ V_54 ] -> V_181 >> V_169 ;
if ( V_144 -> V_170 [ V_54 ] -> V_181 >= V_21 )
break;
V_194 = F_109 ( V_176 , V_181 ,
V_21 >> V_169 ) ;
V_71 = F_110 ( V_144 -> V_170 [ V_54 ] -> V_171 ,
V_194 , V_190 , V_105 , 0 ,
V_193 , V_188 ) ;
if ( V_71 != - 1 ) {
V_71 = V_144 -> V_170 [ V_54 ] -> V_181 +
( V_71 << V_169 ) ;
V_144 -> V_191 = V_71 + ( V_105 << V_169 ) ;
break;
}
V_190 = 0 ;
}
return V_71 ;
}
static unsigned long F_111 ( struct V_1 * V_2 ,
struct V_11 * V_144 ,
unsigned int V_105 ,
unsigned long V_188 ,
T_3 V_21 )
{
unsigned long V_71 ;
#ifdef F_104
V_144 -> V_191 = 0 ;
V_144 -> V_195 = true ;
#endif
V_71 = F_106 ( V_2 , V_144 , V_105 , V_188 ,
V_21 , V_144 -> V_191 ) ;
if ( V_71 == - 1 ) {
V_144 -> V_191 = 0 ;
V_71 = F_106 ( V_2 , V_144 , V_105 , V_188 ,
V_21 , 0 ) ;
V_144 -> V_195 = true ;
}
if ( F_112 ( V_71 == - 1 ) )
V_71 = V_196 ;
F_46 ( ( V_71 + ( V_107 * V_105 ) ) > V_144 -> V_168 ) ;
return V_71 ;
}
static void F_113 ( struct V_11 * V_144 ,
unsigned long V_71 ,
unsigned int V_105 )
{
unsigned V_54 = V_71 >> V_178 ;
struct V_180 * V_197 = V_144 -> V_170 [ V_54 ] ;
F_79 ( V_54 >= V_179 || V_197 == NULL ) ;
#ifdef F_104
if ( V_54 < 4 )
return;
#endif
if ( V_71 >= V_144 -> V_191 )
V_144 -> V_195 = true ;
V_71 = ( V_71 % V_184 ) >> V_169 ;
F_114 ( V_197 -> V_171 , V_71 , V_105 ) ;
}
static void F_115 ( struct V_125 * V_126 )
{
unsigned long V_15 ;
F_7 ( & V_198 , V_15 ) ;
F_116 ( & V_126 -> V_199 , & V_200 ) ;
F_9 ( & V_198 , V_15 ) ;
}
static void F_117 ( struct V_125 * V_126 )
{
unsigned long V_15 ;
F_7 ( & V_198 , V_15 ) ;
F_118 ( & V_126 -> V_199 ) ;
F_9 ( & V_198 , V_15 ) ;
}
static T_1 F_119 ( void )
{
unsigned long V_15 ;
int V_127 ;
F_120 ( & V_201 , V_15 ) ;
V_127 = F_121 ( V_202 , V_203 ) ;
F_79 ( V_127 == 0 ) ;
if ( V_127 > 0 && V_127 < V_203 )
F_99 ( V_127 , V_202 ) ;
else
V_127 = 0 ;
F_122 ( & V_201 , V_15 ) ;
return V_127 ;
}
static void F_123 ( int V_127 )
{
unsigned long V_15 ;
F_120 ( & V_201 , V_15 ) ;
if ( V_127 > 0 && V_127 < V_203 )
F_124 ( V_127 , V_202 ) ;
F_122 ( & V_201 , V_15 ) ;
}
static void F_125 ( struct V_125 * V_126 )
{
int V_54 , V_204 ;
T_3 * V_205 , * V_206 , * V_207 ;
V_205 = V_126 -> V_135 ;
if ( ! V_205 )
return;
for ( V_54 = 0 ; V_54 < 512 ; ++ V_54 ) {
if ( ! F_85 ( V_205 [ V_54 ] ) )
continue;
V_206 = F_87 ( V_205 [ V_54 ] ) ;
for ( V_204 = 0 ; V_204 < 512 ; ++ V_204 ) {
if ( ! F_85 ( V_206 [ V_204 ] ) )
continue;
V_207 = F_87 ( V_206 [ V_204 ] ) ;
F_105 ( ( unsigned long ) V_207 ) ;
}
F_105 ( ( unsigned long ) V_206 ) ;
}
F_105 ( ( unsigned long ) V_205 ) ;
V_126 -> V_135 = NULL ;
}
static void F_126 ( struct V_11 * V_144 )
{
int V_54 ;
if ( ! V_144 )
return;
F_117 ( & V_144 -> V_126 ) ;
F_125 ( & V_144 -> V_126 ) ;
for ( V_54 = 0 ; V_54 < V_179 ; ++ V_54 ) {
if ( ! V_144 -> V_170 [ V_54 ] )
continue;
F_105 ( ( unsigned long ) V_144 -> V_170 [ V_54 ] -> V_171 ) ;
F_15 ( V_144 -> V_170 [ V_54 ] ) ;
}
F_15 ( V_144 ) ;
}
static struct V_11 * F_127 ( void )
{
struct V_11 * V_163 ;
V_163 = F_12 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_163 )
return NULL ;
F_128 ( & V_163 -> V_126 . V_83 ) ;
V_163 -> V_126 . V_127 = F_119 () ;
if ( V_163 -> V_126 . V_127 == 0 )
goto V_208;
F_129 ( & V_163 -> V_126 . V_209 ) ;
V_163 -> V_126 . V_133 = V_210 ;
V_163 -> V_126 . V_135 = ( void * ) F_75 ( V_26 ) ;
V_163 -> V_126 . V_15 = V_211 ;
V_163 -> V_126 . V_212 = V_163 ;
if ( ! V_163 -> V_126 . V_135 )
goto V_208;
V_163 -> V_195 = false ;
V_163 -> V_20 = 0xffff ;
F_115 ( & V_163 -> V_126 ) ;
if ( F_103 ( V_163 , true , V_26 ) )
goto V_208;
V_163 -> V_170 [ 0 ] -> V_171 [ 0 ] = 1 ;
V_163 -> V_191 = 0 ;
return V_163 ;
V_208:
F_126 ( V_163 ) ;
return NULL ;
}
static bool V_11 ( struct V_125 * V_126 )
{
return V_126 -> V_15 & V_211 ;
}
static void F_130 ( T_1 V_12 , struct V_125 * V_126 , bool V_213 )
{
T_3 V_214 = F_77 ( V_126 -> V_135 ) ;
V_40 V_15 = 0 ;
V_214 |= ( V_126 -> V_133 & V_215 )
<< V_216 ;
V_214 |= V_154 | V_156 | V_151 | V_217 ;
if ( V_213 )
V_15 |= V_218 ;
V_30 [ V_12 ] . V_55 [ 3 ] |= V_15 ;
V_30 [ V_12 ] . V_55 [ 2 ] = V_126 -> V_127 ;
V_30 [ V_12 ] . V_55 [ 1 ] = F_49 ( V_214 ) ;
V_30 [ V_12 ] . V_55 [ 0 ] = F_47 ( V_214 ) ;
}
static void F_131 ( T_1 V_12 )
{
V_30 [ V_12 ] . V_55 [ 0 ] = V_151 | V_217 ;
V_30 [ V_12 ] . V_55 [ 1 ] = 0 ;
V_30 [ V_12 ] . V_55 [ 2 ] = 0 ;
F_132 ( V_12 ) ;
}
static void F_133 ( struct V_1 * V_2 , struct V_125 * V_126 )
{
struct V_8 * V_25 ;
struct V_59 * V_10 ;
struct V_3 * V_4 ;
bool V_213 = false ;
T_1 V_12 ;
V_12 = F_1 ( V_2 ) ;
V_10 = V_24 [ V_12 ] ;
V_25 = F_4 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
if ( V_219 )
V_213 = F_67 ( V_4 ) ;
V_25 -> V_126 = V_126 ;
F_116 ( & V_25 -> V_199 , & V_126 -> V_209 ) ;
F_130 ( V_12 , V_126 , V_213 ) ;
V_126 -> V_129 [ V_10 -> V_175 ] += 1 ;
V_126 -> V_220 += 1 ;
F_66 ( V_2 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_8 * V_25 ;
struct V_59 * V_10 ;
T_1 V_12 ;
V_12 = F_1 ( V_2 ) ;
V_10 = V_24 [ V_12 ] ;
V_25 = F_4 ( V_2 ) ;
V_25 -> V_126 -> V_129 [ V_10 -> V_175 ] -= 1 ;
V_25 -> V_126 -> V_220 -= 1 ;
V_25 -> V_126 = NULL ;
F_118 ( & V_25 -> V_199 ) ;
F_131 ( V_12 ) ;
F_66 ( V_2 ) ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
struct V_8 * V_25 , * V_221 ;
int V_14 ;
V_25 = F_4 ( V_2 ) ;
V_221 = F_4 ( V_25 -> V_16 ) ;
if ( ! V_221 )
return - V_149 ;
F_136 ( & V_126 -> V_83 ) ;
V_14 = - V_150 ;
if ( V_221 -> V_126 != NULL &&
V_221 -> V_126 != V_126 )
goto V_222;
if ( V_25 -> V_126 != NULL &&
V_25 -> V_126 != V_126 )
goto V_222;
if ( V_25 -> V_16 != V_2 ) {
V_221 = F_4 ( V_25 -> V_16 ) ;
if ( V_221 -> V_126 == NULL )
F_133 ( V_25 -> V_16 , V_126 ) ;
F_137 ( & V_221 -> V_29 ) ;
}
if ( V_25 -> V_126 == NULL )
F_133 ( V_2 , V_126 ) ;
F_137 ( & V_25 -> V_29 ) ;
V_14 = 0 ;
V_222:
F_138 ( & V_126 -> V_83 ) ;
return V_14 ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_15 ;
int V_14 ;
if ( V_219 )
F_140 ( V_4 , V_169 ) ;
F_120 ( & V_201 , V_15 ) ;
V_14 = F_135 ( V_2 , V_126 ) ;
F_122 ( & V_201 , V_15 ) ;
F_71 ( V_126 ) ;
return V_14 ;
}
static void F_141 ( struct V_1 * V_2 )
{
struct V_8 * V_25 = F_4 ( V_2 ) ;
struct V_8 * V_221 ;
struct V_125 * V_126 ;
unsigned long V_15 ;
F_79 ( ! V_25 -> V_126 ) ;
V_126 = V_25 -> V_126 ;
F_7 ( & V_126 -> V_83 , V_15 ) ;
if ( V_25 -> V_16 != V_2 ) {
V_221 = F_4 ( V_25 -> V_16 ) ;
if ( F_142 ( & V_221 -> V_29 ) )
F_134 ( V_25 -> V_16 ) ;
}
if ( F_142 ( & V_25 -> V_29 ) )
F_134 ( V_2 ) ;
F_9 ( & V_126 -> V_83 , V_15 ) ;
if ( V_223 &&
( V_25 -> V_126 == NULL && V_126 != V_224 ) )
F_135 ( V_2 , V_224 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_15 ;
F_120 ( & V_201 , V_15 ) ;
F_141 ( V_2 ) ;
F_122 ( & V_201 , V_15 ) ;
if ( V_219 && F_67 ( V_4 ) )
F_144 ( V_4 ) ;
}
static struct V_125 * F_145 ( struct V_1 * V_2 )
{
struct V_125 * V_144 ;
struct V_8 * V_25 , * V_221 ;
unsigned long V_15 ;
T_1 V_12 ;
V_12 = F_1 ( V_2 ) ;
V_25 = F_4 ( V_2 ) ;
V_221 = F_4 ( V_25 -> V_16 ) ;
if ( ! V_221 )
return NULL ;
F_146 ( & V_201 , V_15 ) ;
V_144 = V_25 -> V_126 ;
if ( V_144 == NULL &&
V_221 -> V_126 != NULL ) {
F_135 ( V_2 , V_221 -> V_126 ) ;
V_144 = V_221 -> V_126 ;
}
F_147 ( & V_201 , V_15 ) ;
return V_144 ;
}
static int F_148 ( struct V_225 * V_226 ,
unsigned long V_227 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
T_1 V_12 ;
struct V_125 * V_126 ;
struct V_11 * V_228 ;
struct V_59 * V_10 ;
unsigned long V_15 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
V_12 = F_1 ( V_2 ) ;
V_10 = V_24 [ V_12 ] ;
switch ( V_227 ) {
case V_229 :
V_126 = F_145 ( V_2 ) ;
if ( ! V_126 )
goto V_230;
if ( V_223 )
break;
F_143 ( V_2 ) ;
break;
case V_231 :
F_11 ( V_2 ) ;
V_126 = F_145 ( V_2 ) ;
V_228 = F_5 ( V_12 ) ;
if ( V_228 )
goto V_230;
V_228 = F_127 () ;
if ( ! V_228 )
goto V_230;
V_228 -> V_20 = V_12 ;
F_7 ( & V_19 , V_15 ) ;
F_149 ( & V_228 -> V_199 , & V_18 ) ;
F_9 ( & V_19 , V_15 ) ;
break;
case V_232 :
F_18 ( V_2 ) ;
default:
goto V_230;
}
F_66 ( V_2 ) ;
F_57 ( V_10 ) ;
V_230:
return 0 ;
}
void F_150 ( void )
{
F_151 ( & V_22 , & V_233 ) ;
}
static struct V_125 * F_152 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
struct V_11 * V_163 ;
T_1 V_12 = F_1 ( V_2 ) ;
if ( ! F_10 ( V_2 ) )
return F_153 ( - V_149 ) ;
V_126 = F_145 ( V_2 ) ;
if ( V_126 != NULL && ! V_11 ( V_126 ) )
return F_153 ( - V_150 ) ;
if ( V_126 != NULL )
return V_126 ;
V_163 = F_5 ( V_12 ) ;
if ( ! V_163 )
V_163 = V_24 [ V_12 ] -> V_172 ;
F_139 ( V_2 , & V_163 -> V_126 ) ;
F_154 ( L_20 ,
V_163 -> V_126 . V_127 , F_155 ( V_2 ) ) ;
return & V_163 -> V_126 ;
}
static void F_156 ( struct V_125 * V_126 )
{
struct V_8 * V_25 ;
F_8 (dev_data, &domain->dev_list, list) {
struct V_3 * V_4 = F_2 ( V_25 -> V_2 ) ;
T_1 V_12 = F_1 ( V_25 -> V_2 ) ;
F_130 ( V_12 , V_126 , F_67 ( V_4 ) ) ;
}
}
static void F_95 ( struct V_125 * V_126 )
{
if ( ! V_126 -> V_136 )
return;
F_156 ( V_126 ) ;
F_73 ( V_126 ) ;
F_71 ( V_126 ) ;
V_126 -> V_136 = false ;
}
static T_3 * F_157 ( struct V_11 * V_144 ,
unsigned long V_71 )
{
struct V_180 * V_170 ;
T_3 * V_132 , * V_138 ;
V_170 = V_144 -> V_170 [ F_158 ( V_71 ) ] ;
if ( ! V_170 )
return NULL ;
V_132 = V_170 -> V_183 [ F_159 ( V_71 ) ] ;
if ( ! V_132 ) {
V_132 = F_78 ( & V_144 -> V_126 , V_71 , V_107 , & V_138 ,
V_234 ) ;
V_170 -> V_183 [ F_159 ( V_71 ) ] = V_138 ;
} else
V_132 += F_82 ( 0 , V_71 ) ;
F_95 ( & V_144 -> V_126 ) ;
return V_132 ;
}
static T_8 F_160 ( struct V_11 * V_144 ,
unsigned long V_71 ,
T_9 V_235 ,
int V_236 )
{
T_3 * V_132 , V_143 ;
F_46 ( V_71 > V_144 -> V_168 ) ;
V_235 &= V_109 ;
V_132 = F_157 ( V_144 , V_71 ) ;
if ( ! V_132 )
return V_196 ;
V_143 = V_235 | V_151 | V_152 ;
if ( V_236 == V_237 )
V_143 |= V_154 ;
else if ( V_236 == V_238 )
V_143 |= V_156 ;
else if ( V_236 == V_239 )
V_143 |= V_154 | V_156 ;
F_46 ( * V_132 ) ;
* V_132 = V_143 ;
return ( T_8 ) V_71 ;
}
static void F_161 ( struct V_11 * V_144 ,
unsigned long V_71 )
{
struct V_180 * V_170 ;
T_3 * V_132 ;
if ( V_71 >= V_144 -> V_168 )
return;
V_170 = V_144 -> V_170 [ F_158 ( V_71 ) ] ;
if ( ! V_170 )
return;
V_132 = V_170 -> V_183 [ F_159 ( V_71 ) ] ;
if ( ! V_132 )
return;
V_132 += F_82 ( 0 , V_71 ) ;
F_46 ( ! * V_132 ) ;
* V_132 = 0ULL ;
}
static T_8 F_162 ( struct V_1 * V_2 ,
struct V_11 * V_163 ,
T_9 V_235 ,
T_6 V_103 ,
int V_240 ,
bool V_241 ,
T_3 V_21 )
{
T_8 V_181 = V_235 & ~ V_109 ;
T_8 V_71 , V_189 , V_14 ;
unsigned int V_105 ;
unsigned long V_188 = 0 ;
int V_54 ;
V_105 = F_53 ( V_235 , V_103 , V_107 ) ;
V_235 &= V_109 ;
F_163 ( V_53 ) ;
if ( V_105 > 1 )
F_163 ( V_49 ) ;
if ( V_241 )
V_188 = ( 1UL << F_164 ( V_103 ) ) - 1 ;
V_242:
V_71 = F_111 ( V_2 , V_163 , V_105 , V_188 ,
V_21 ) ;
if ( F_112 ( V_71 == V_196 ) ) {
V_163 -> V_191 = V_163 -> V_168 ;
if ( F_103 ( V_163 , false , V_234 ) )
goto V_230;
goto V_242;
}
V_189 = V_71 ;
for ( V_54 = 0 ; V_54 < V_105 ; ++ V_54 ) {
V_14 = F_160 ( V_163 , V_189 , V_235 , V_240 ) ;
if ( V_14 == V_196 )
goto V_243;
V_235 += V_107 ;
V_189 += V_107 ;
}
V_71 += V_181 ;
F_165 ( V_52 , V_103 ) ;
if ( F_112 ( V_163 -> V_195 && ! V_41 ) ) {
F_70 ( & V_163 -> V_126 ) ;
V_163 -> V_195 = false ;
} else if ( F_112 ( V_244 ) )
F_69 ( & V_163 -> V_126 , V_71 , V_103 ) ;
V_230:
return V_71 ;
V_243:
for ( -- V_54 ; V_54 >= 0 ; -- V_54 ) {
V_189 -= V_107 ;
F_161 ( V_163 , V_189 ) ;
}
F_113 ( V_163 , V_71 , V_105 ) ;
return V_196 ;
}
static void F_166 ( struct V_11 * V_163 ,
T_8 V_245 ,
T_6 V_103 ,
int V_240 )
{
T_8 V_246 ;
T_8 V_54 , V_189 ;
unsigned int V_105 ;
if ( ( V_245 == V_196 ) ||
( V_245 + V_103 > V_163 -> V_168 ) )
return;
V_246 = V_245 ;
V_105 = F_53 ( V_245 , V_103 , V_107 ) ;
V_245 &= V_109 ;
V_189 = V_245 ;
for ( V_54 = 0 ; V_54 < V_105 ; ++ V_54 ) {
F_161 ( V_163 , V_189 ) ;
V_189 += V_107 ;
}
F_167 ( V_52 , V_103 ) ;
F_113 ( V_163 , V_245 , V_105 ) ;
if ( V_41 || V_163 -> V_195 ) {
F_69 ( & V_163 -> V_126 , V_246 , V_103 ) ;
V_163 -> V_195 = false ;
}
}
static T_8 F_168 ( struct V_1 * V_2 , struct V_141 * V_141 ,
unsigned long V_181 , T_6 V_103 ,
enum V_247 V_240 ,
struct V_248 * V_249 )
{
unsigned long V_15 ;
struct V_125 * V_126 ;
T_8 V_165 ;
T_3 V_21 ;
T_9 V_235 = F_169 ( V_141 ) + V_181 ;
F_163 ( V_43 ) ;
V_126 = F_152 ( V_2 ) ;
if ( F_170 ( V_126 ) == - V_149 )
return ( T_8 ) V_235 ;
else if ( F_171 ( V_126 ) )
return V_196 ;
V_21 = * V_2 -> V_21 ;
F_7 ( & V_126 -> V_83 , V_15 ) ;
V_165 = F_162 ( V_2 , V_126 -> V_212 , V_235 , V_103 , V_240 , false ,
V_21 ) ;
if ( V_165 == V_196 )
goto V_230;
F_72 ( V_126 ) ;
V_230:
F_9 ( & V_126 -> V_83 , V_15 ) ;
return V_165 ;
}
static void F_172 ( struct V_1 * V_2 , T_8 V_245 , T_6 V_103 ,
enum V_247 V_240 , struct V_248 * V_249 )
{
unsigned long V_15 ;
struct V_125 * V_126 ;
F_163 ( V_44 ) ;
V_126 = F_152 ( V_2 ) ;
if ( F_171 ( V_126 ) )
return;
F_7 ( & V_126 -> V_83 , V_15 ) ;
F_166 ( V_126 -> V_212 , V_245 , V_103 , V_240 ) ;
F_72 ( V_126 ) ;
F_9 ( & V_126 -> V_83 , V_15 ) ;
}
static int F_173 ( struct V_1 * V_2 , struct V_250 * V_251 ,
int V_252 , int V_240 )
{
struct V_250 * V_106 ;
int V_54 ;
F_174 (sglist, s, nelems, i) {
V_106 -> V_253 = ( T_8 ) F_175 ( V_106 ) ;
V_106 -> V_254 = V_106 -> V_255 ;
}
return V_252 ;
}
static int F_176 ( struct V_1 * V_2 , struct V_250 * V_251 ,
int V_252 , enum V_247 V_240 ,
struct V_248 * V_249 )
{
unsigned long V_15 ;
struct V_125 * V_126 ;
int V_54 ;
struct V_250 * V_106 ;
T_9 V_235 ;
int V_256 = 0 ;
T_3 V_21 ;
F_163 ( V_45 ) ;
V_126 = F_152 ( V_2 ) ;
if ( F_170 ( V_126 ) == - V_149 )
return F_173 ( V_2 , V_251 , V_252 , V_240 ) ;
else if ( F_171 ( V_126 ) )
return 0 ;
V_21 = * V_2 -> V_21 ;
F_7 ( & V_126 -> V_83 , V_15 ) ;
F_174 (sglist, s, nelems, i) {
V_235 = F_175 ( V_106 ) ;
V_106 -> V_253 = F_162 ( V_2 , V_126 -> V_212 ,
V_235 , V_106 -> V_255 , V_240 , false ,
V_21 ) ;
if ( V_106 -> V_253 ) {
V_106 -> V_254 = V_106 -> V_255 ;
V_256 ++ ;
} else
goto V_257;
}
F_72 ( V_126 ) ;
V_230:
F_9 ( & V_126 -> V_83 , V_15 ) ;
return V_256 ;
V_257:
F_174 (sglist, s, mapped_elems, i) {
if ( V_106 -> V_253 )
F_166 ( V_126 -> V_212 , V_106 -> V_253 ,
V_106 -> V_254 , V_240 ) ;
V_106 -> V_253 = V_106 -> V_254 = 0 ;
}
V_256 = 0 ;
goto V_230;
}
static void F_177 ( struct V_1 * V_2 , struct V_250 * V_251 ,
int V_252 , enum V_247 V_240 ,
struct V_248 * V_249 )
{
unsigned long V_15 ;
struct V_125 * V_126 ;
struct V_250 * V_106 ;
int V_54 ;
F_163 ( V_46 ) ;
V_126 = F_152 ( V_2 ) ;
if ( F_171 ( V_126 ) )
return;
F_7 ( & V_126 -> V_83 , V_15 ) ;
F_174 (sglist, s, nelems, i) {
F_166 ( V_126 -> V_212 , V_106 -> V_253 ,
V_106 -> V_254 , V_240 ) ;
V_106 -> V_253 = V_106 -> V_254 = 0 ;
}
F_72 ( V_126 ) ;
F_9 ( & V_126 -> V_83 , V_15 ) ;
}
static void * F_178 ( struct V_1 * V_2 , T_6 V_103 ,
T_8 * V_245 , T_7 V_258 )
{
unsigned long V_15 ;
void * V_259 ;
struct V_125 * V_126 ;
T_9 V_235 ;
T_3 V_21 = V_2 -> V_260 ;
F_163 ( V_47 ) ;
V_126 = F_152 ( V_2 ) ;
if ( F_170 ( V_126 ) == - V_149 ) {
V_259 = ( void * ) F_179 ( V_258 , F_164 ( V_103 ) ) ;
* V_245 = F_48 ( V_259 ) ;
return V_259 ;
} else if ( F_171 ( V_126 ) )
return NULL ;
V_21 = V_2 -> V_260 ;
V_258 &= ~ ( V_261 | V_262 | V_263 ) ;
V_258 |= V_264 ;
V_259 = ( void * ) F_179 ( V_258 , F_164 ( V_103 ) ) ;
if ( ! V_259 )
return NULL ;
V_235 = F_77 ( V_259 ) ;
if ( ! V_21 )
V_21 = * V_2 -> V_21 ;
F_7 ( & V_126 -> V_83 , V_15 ) ;
* V_245 = F_162 ( V_2 , V_126 -> V_212 , V_235 ,
V_103 , V_239 , true , V_21 ) ;
if ( * V_245 == V_196 ) {
F_9 ( & V_126 -> V_83 , V_15 ) ;
goto V_32;
}
F_72 ( V_126 ) ;
F_9 ( & V_126 -> V_83 , V_15 ) ;
return V_259 ;
V_32:
F_180 ( ( unsigned long ) V_259 , F_164 ( V_103 ) ) ;
return NULL ;
}
static void F_181 ( struct V_1 * V_2 , T_6 V_103 ,
void * V_259 , T_8 V_245 )
{
unsigned long V_15 ;
struct V_125 * V_126 ;
F_163 ( V_48 ) ;
V_126 = F_152 ( V_2 ) ;
if ( F_171 ( V_126 ) )
goto V_265;
F_7 ( & V_126 -> V_83 , V_15 ) ;
F_166 ( V_126 -> V_212 , V_245 , V_103 , V_239 ) ;
F_72 ( V_126 ) ;
F_9 ( & V_126 -> V_83 , V_15 ) ;
V_265:
F_180 ( ( unsigned long ) V_259 , F_164 ( V_103 ) ) ;
}
static int F_182 ( struct V_1 * V_2 , T_3 V_266 )
{
return F_10 ( V_2 ) ;
}
static void F_183 ( void )
{
struct V_3 * V_2 = NULL ;
struct V_11 * V_163 ;
T_1 V_12 ;
F_20 (dev) {
if ( ! F_10 ( & V_2 -> V_2 ) )
continue;
if ( F_145 ( & V_2 -> V_2 ) )
continue;
V_12 = F_1 ( & V_2 -> V_2 ) ;
V_163 = F_127 () ;
if ( ! V_163 )
continue;
F_101 ( V_163 , V_12 ) ;
V_163 -> V_20 = V_12 ;
F_139 ( & V_2 -> V_2 , & V_163 -> V_126 ) ;
F_149 ( & V_163 -> V_199 , & V_18 ) ;
}
}
static unsigned F_184 ( void )
{
struct V_3 * V_4 = NULL ;
unsigned V_267 = 0 ;
F_20 (pdev) {
if ( ! F_10 ( & V_4 -> V_2 ) ) {
V_267 += 1 ;
continue;
}
V_4 -> V_2 . V_9 . V_268 = & V_269 ;
}
return V_267 ;
}
void T_2 F_185 ( void )
{
F_186 ( & V_270 ) ;
}
int T_2 F_187 ( void )
{
struct V_59 * V_10 ;
int V_14 , V_267 ;
F_39 (iommu) {
V_10 -> V_172 = F_127 () ;
if ( V_10 -> V_172 == NULL )
return - V_27 ;
V_10 -> V_172 -> V_126 . V_15 |= V_271 ;
V_14 = F_100 ( V_10 ) ;
if ( V_14 )
goto V_272;
}
F_183 () ;
V_273 = 1 ;
V_274 = 0 ;
V_267 = F_184 () ;
if ( V_267 && V_275 > V_276 ) {
V_274 = 1 ;
}
F_24 () ;
return 0 ;
V_272:
F_39 (iommu) {
if ( V_10 -> V_172 )
F_126 ( V_10 -> V_172 ) ;
}
return V_14 ;
}
static void F_188 ( struct V_125 * V_126 )
{
struct V_8 * V_25 , * V_277 ;
unsigned long V_15 ;
F_120 ( & V_201 , V_15 ) ;
F_189 (dev_data, next, &domain->dev_list, list) {
struct V_1 * V_2 = V_25 -> V_2 ;
F_141 ( V_2 ) ;
F_16 ( & V_25 -> V_29 , 0 ) ;
}
F_122 ( & V_201 , V_15 ) ;
}
static void F_190 ( struct V_125 * V_126 )
{
if ( ! V_126 )
return;
F_117 ( V_126 ) ;
if ( V_126 -> V_127 )
F_123 ( V_126 -> V_127 ) ;
F_15 ( V_126 ) ;
}
static struct V_125 * F_191 ( void )
{
struct V_125 * V_126 ;
V_126 = F_12 ( sizeof( * V_126 ) , V_26 ) ;
if ( ! V_126 )
return NULL ;
F_128 ( & V_126 -> V_83 ) ;
F_192 ( & V_126 -> V_278 ) ;
V_126 -> V_127 = F_119 () ;
if ( ! V_126 -> V_127 )
goto V_279;
F_129 ( & V_126 -> V_209 ) ;
F_115 ( V_126 ) ;
return V_126 ;
V_279:
F_15 ( V_126 ) ;
return NULL ;
}
static int F_193 ( struct V_280 * V_144 )
{
struct V_125 * V_126 ;
V_126 = F_191 () ;
if ( ! V_126 )
goto V_32;
V_126 -> V_133 = V_281 ;
V_126 -> V_135 = ( void * ) F_75 ( V_26 ) ;
if ( ! V_126 -> V_135 )
goto V_32;
V_144 -> V_212 = V_126 ;
return 0 ;
V_32:
F_190 ( V_126 ) ;
return - V_27 ;
}
static void F_194 ( struct V_280 * V_144 )
{
struct V_125 * V_126 = V_144 -> V_212 ;
if ( ! V_126 )
return;
if ( V_126 -> V_220 > 0 )
F_188 ( V_126 ) ;
F_79 ( V_126 -> V_220 != 0 ) ;
F_125 ( V_126 ) ;
F_190 ( V_126 ) ;
V_144 -> V_212 = NULL ;
}
static void F_195 ( struct V_280 * V_144 ,
struct V_1 * V_2 )
{
struct V_8 * V_25 = V_2 -> V_9 . V_10 ;
struct V_59 * V_10 ;
T_1 V_12 ;
if ( ! F_10 ( V_2 ) )
return;
V_12 = F_1 ( V_2 ) ;
if ( V_25 -> V_126 != NULL )
F_143 ( V_2 ) ;
V_10 = V_24 [ V_12 ] ;
if ( ! V_10 )
return;
F_66 ( V_2 ) ;
F_57 ( V_10 ) ;
}
static int F_196 ( struct V_280 * V_144 ,
struct V_1 * V_2 )
{
struct V_125 * V_126 = V_144 -> V_212 ;
struct V_8 * V_25 ;
struct V_59 * V_10 ;
int V_14 ;
T_1 V_12 ;
if ( ! F_10 ( V_2 ) )
return - V_149 ;
V_25 = V_2 -> V_9 . V_10 ;
V_12 = F_1 ( V_2 ) ;
V_10 = V_24 [ V_12 ] ;
if ( ! V_10 )
return - V_149 ;
if ( V_25 -> V_126 )
F_143 ( V_2 ) ;
V_14 = F_139 ( V_2 , V_126 ) ;
F_57 ( V_10 ) ;
return V_14 ;
}
static int F_197 ( struct V_280 * V_144 , unsigned long V_282 ,
T_9 V_235 , int V_283 , int V_284 )
{
unsigned long V_137 = 0x1000UL << V_283 ;
struct V_125 * V_126 = V_144 -> V_212 ;
int V_146 = 0 ;
int V_14 ;
if ( V_284 & V_285 )
V_146 |= V_153 ;
if ( V_284 & V_286 )
V_146 |= V_155 ;
F_198 ( & V_126 -> V_278 ) ;
V_14 = F_91 ( V_126 , V_282 , V_235 , V_146 , V_137 ) ;
F_199 ( & V_126 -> V_278 ) ;
return V_14 ;
}
static int F_200 ( struct V_280 * V_144 , unsigned long V_282 ,
int V_283 )
{
struct V_125 * V_126 = V_144 -> V_212 ;
unsigned long V_137 , V_157 ;
V_137 = 0x1000UL << V_283 ;
F_198 ( & V_126 -> V_278 ) ;
V_157 = F_96 ( V_126 , V_282 , V_137 ) ;
F_199 ( & V_126 -> V_278 ) ;
F_71 ( V_126 ) ;
return F_164 ( V_157 ) ;
}
static T_9 F_201 ( struct V_280 * V_144 ,
unsigned long V_282 )
{
struct V_125 * V_126 = V_144 -> V_212 ;
unsigned long V_287 ;
T_9 V_235 ;
T_3 * V_132 , V_143 ;
V_132 = F_88 ( V_126 , V_282 ) ;
if ( ! V_132 || ! F_85 ( * V_132 ) )
return 0 ;
if ( F_86 ( * V_132 ) == 0 )
V_287 = V_107 - 1 ;
else
V_287 = F_89 ( * V_132 ) - 1 ;
V_143 = * V_132 & V_288 ;
V_235 = ( V_143 & ~ V_287 ) | ( V_282 & V_287 ) ;
return V_235 ;
}
static int F_202 ( struct V_280 * V_126 ,
unsigned long V_289 )
{
switch ( V_289 ) {
case V_290 :
return 1 ;
}
return 0 ;
}
int T_2 F_203 ( void )
{
struct V_59 * V_10 ;
struct V_3 * V_2 = NULL ;
T_1 V_12 ;
V_224 = F_191 () ;
if ( ! V_224 )
return - V_27 ;
V_224 -> V_133 |= V_291 ;
F_20 (dev) {
if ( ! F_10 ( & V_2 -> V_2 ) )
continue;
V_12 = F_1 ( & V_2 -> V_2 ) ;
V_10 = V_24 [ V_12 ] ;
if ( ! V_10 )
continue;
F_139 ( & V_2 -> V_2 , V_224 ) ;
}
F_204 ( L_21 ) ;
return 0 ;
}
