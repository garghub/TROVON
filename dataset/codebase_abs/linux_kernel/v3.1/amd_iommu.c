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
F_9 ( V_3 ) ;
}
static struct V_1 * F_10 ( T_1 V_2 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
F_4 ( & V_7 , V_4 ) ;
F_11 (dev_data, &dev_data_list, dev_data_list) {
if ( V_3 -> V_2 == V_2 )
goto V_9;
}
V_3 = NULL ;
V_9:
F_6 ( & V_7 , V_4 ) ;
return V_3 ;
}
static struct V_1 * F_12 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_10 ( V_2 ) ;
if ( V_3 == NULL )
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
static inline T_1 F_13 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
return F_15 ( V_13 -> V_14 -> V_15 , V_13 -> V_16 ) ;
}
static struct V_1 * F_16 ( struct V_10 * V_11 )
{
return V_11 -> V_17 . V_18 ;
}
static struct V_19 * F_17 ( T_1 V_2 )
{
struct V_19 * V_20 , * V_21 = NULL ;
unsigned long V_4 ;
T_1 V_22 = V_23 [ V_2 ] ;
if ( F_18 ( & V_24 ) )
return NULL ;
F_4 ( & V_25 , V_4 ) ;
F_11 (entry, &iommu_pd_list, list) {
if ( V_20 -> V_26 == V_2 ||
V_20 -> V_26 == V_22 ) {
V_21 = V_20 ;
break;
}
}
F_6 ( & V_25 , V_4 ) ;
return V_21 ;
}
static bool F_19 ( struct V_10 * V_11 )
{
T_1 V_2 ;
if ( ! V_11 || ! V_11 -> V_27 )
return false ;
if ( V_11 -> V_14 != & V_28 )
return false ;
V_2 = F_13 ( V_11 ) ;
if ( V_2 > V_29 )
return false ;
if ( V_30 [ V_2 ] == NULL )
return false ;
return true ;
}
static int F_20 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
T_1 V_22 ;
if ( V_11 -> V_17 . V_18 )
return 0 ;
V_3 = F_12 ( F_13 ( V_11 ) ) ;
if ( ! V_3 )
return - V_31 ;
V_22 = V_23 [ V_3 -> V_2 ] ;
if ( V_22 != V_3 -> V_2 ) {
struct V_1 * V_32 ;
V_32 = F_12 ( V_22 ) ;
if ( V_32 == NULL ) {
F_21 ( L_1 ,
F_22 ( V_11 ) ) ;
F_7 ( V_3 ) ;
return - V_33 ;
}
V_3 -> V_32 = V_32 ;
}
V_11 -> V_17 . V_18 = V_3 ;
return 0 ;
}
static void F_23 ( struct V_10 * V_11 )
{
T_1 V_2 , V_22 ;
V_2 = F_13 ( V_11 ) ;
V_22 = V_23 [ V_2 ] ;
memset ( & V_34 [ V_2 ] , 0 , sizeof( struct V_35 ) ) ;
memset ( & V_34 [ V_22 ] , 0 , sizeof( struct V_35 ) ) ;
V_30 [ V_2 ] = NULL ;
V_30 [ V_22 ] = NULL ;
}
static void F_24 ( struct V_10 * V_11 )
{
}
void T_2 F_25 ( void )
{
struct V_1 * V_3 , * V_36 ;
struct V_12 * V_13 = NULL ;
F_26 (pdev) {
if ( ! F_19 ( & V_13 -> V_11 ) )
continue;
F_24 ( & V_13 -> V_11 ) ;
}
F_27 (dev_data, n, &dev_data_list, dev_data_list)
F_7 ( V_3 ) ;
}
int T_2 F_28 ( void )
{
struct V_12 * V_13 = NULL ;
int V_21 = 0 ;
F_26 (pdev) {
if ( ! F_19 ( & V_13 -> V_11 ) )
continue;
V_21 = F_20 ( & V_13 -> V_11 ) ;
if ( V_21 == - V_33 )
F_23 ( & V_13 -> V_11 ) ;
else if ( V_21 )
goto V_37;
}
return 0 ;
V_37:
F_25 () ;
return V_21 ;
}
static void F_29 ( struct V_38 * V_39 )
{
if ( V_40 == NULL )
return;
V_39 -> V_41 = F_30 ( V_39 -> V_42 , 0444 , V_40 ,
& V_39 -> V_43 ) ;
}
static void F_31 ( void )
{
V_40 = F_32 ( L_2 , NULL ) ;
if ( V_40 == NULL )
return;
V_44 = F_33 ( L_3 , 0444 , V_40 ,
( V_45 * ) & V_46 ) ;
F_29 ( & V_47 ) ;
F_29 ( & V_48 ) ;
F_29 ( & V_49 ) ;
F_29 ( & V_50 ) ;
F_29 ( & V_51 ) ;
F_29 ( & V_52 ) ;
F_29 ( & V_53 ) ;
F_29 ( & V_54 ) ;
F_29 ( & V_55 ) ;
F_29 ( & V_56 ) ;
F_29 ( & V_57 ) ;
F_29 ( & V_58 ) ;
}
static void F_34 ( T_1 V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < 8 ; ++ V_59 )
F_21 ( L_4 , V_59 ,
V_34 [ V_2 ] . V_60 [ V_59 ] ) ;
}
static void F_35 ( unsigned long V_61 )
{
struct V_62 * V_63 = F_36 ( V_61 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < 4 ; ++ V_59 )
F_21 ( L_5 , V_59 , V_63 -> V_60 [ V_59 ] ) ;
}
static void F_37 ( struct V_64 * V_18 , void * V_65 )
{
V_45 * V_66 = V_65 ;
int type = ( V_66 [ 1 ] >> V_67 ) & V_68 ;
int V_2 = ( V_66 [ 0 ] >> V_69 ) & V_70 ;
int V_71 = ( V_66 [ 1 ] >> V_72 ) & V_73 ;
int V_4 = ( V_66 [ 1 ] >> V_74 ) & V_75 ;
T_3 V_76 = ( T_3 ) ( ( ( T_3 ) V_66 [ 3 ] ) << 32 ) | V_66 [ 2 ] ;
F_38 ( V_77 L_6 ) ;
switch ( type ) {
case V_78 :
F_38 ( L_7
L_8 ,
F_39 ( V_2 ) , F_40 ( V_2 ) , F_41 ( V_2 ) ,
V_76 , V_4 ) ;
F_34 ( V_2 ) ;
break;
case V_79 :
F_38 ( L_9
L_10 ,
F_39 ( V_2 ) , F_40 ( V_2 ) , F_41 ( V_2 ) ,
V_71 , V_76 , V_4 ) ;
break;
case V_80 :
F_38 ( L_11
L_8 ,
F_39 ( V_2 ) , F_40 ( V_2 ) , F_41 ( V_2 ) ,
V_76 , V_4 ) ;
break;
case V_81 :
F_38 ( L_12
L_10 ,
F_39 ( V_2 ) , F_40 ( V_2 ) , F_41 ( V_2 ) ,
V_71 , V_76 , V_4 ) ;
break;
case V_82 :
F_38 ( L_13 , V_76 ) ;
F_35 ( V_76 ) ;
break;
case V_83 :
F_38 ( L_14
L_15 , V_76 , V_4 ) ;
break;
case V_84 :
F_38 ( L_16
L_17 ,
F_39 ( V_2 ) , F_40 ( V_2 ) , F_41 ( V_2 ) ,
V_76 ) ;
break;
case V_85 :
F_38 ( L_18
L_8 ,
F_39 ( V_2 ) , F_40 ( V_2 ) , F_41 ( V_2 ) ,
V_76 , V_4 ) ;
break;
default:
F_38 ( V_77 L_19 , type ) ;
}
}
static void F_42 ( struct V_64 * V_18 )
{
V_45 V_86 , V_87 ;
unsigned long V_4 ;
F_4 ( & V_18 -> V_88 , V_4 ) ;
V_86 = F_43 ( V_18 -> V_89 + V_90 ) ;
V_87 = F_43 ( V_18 -> V_89 + V_91 ) ;
while ( V_86 != V_87 ) {
F_37 ( V_18 , V_18 -> V_92 + V_86 ) ;
V_86 = ( V_86 + V_93 ) % V_18 -> V_94 ;
}
F_44 ( V_86 , V_18 -> V_89 + V_90 ) ;
F_6 ( & V_18 -> V_88 , V_4 ) ;
}
T_4 F_45 ( int V_95 , void * V_60 )
{
struct V_64 * V_18 ;
F_46 (iommu)
F_42 ( V_18 ) ;
return V_96 ;
}
T_4 F_47 ( int V_95 , void * V_60 )
{
return V_97 ;
}
static int F_48 ( volatile T_3 * V_98 )
{
int V_59 = 0 ;
while ( * V_98 == 0 && V_59 < V_99 ) {
F_49 ( 1 ) ;
V_59 += 1 ;
}
if ( V_59 == V_99 ) {
F_50 ( L_20 ) ;
return - V_100 ;
}
return 0 ;
}
static void F_51 ( struct V_64 * V_18 ,
struct V_62 * V_63 ,
V_45 V_87 )
{
T_5 * V_101 ;
V_101 = V_18 -> V_102 + V_87 ;
V_87 = ( V_87 + sizeof( * V_63 ) ) % V_18 -> V_103 ;
memcpy ( V_101 , V_63 , sizeof( * V_63 ) ) ;
F_44 ( V_87 , V_18 -> V_89 + V_104 ) ;
}
static void F_52 ( struct V_62 * V_63 , T_3 V_76 )
{
F_53 ( V_76 & 0x7ULL ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_60 [ 0 ] = F_54 ( F_55 ( V_76 ) ) | V_105 ;
V_63 -> V_60 [ 1 ] = F_56 ( F_55 ( V_76 ) ) ;
V_63 -> V_60 [ 2 ] = 1 ;
F_57 ( V_63 , V_106 ) ;
}
static void F_58 ( struct V_62 * V_63 , T_1 V_2 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_60 [ 0 ] = V_2 ;
F_57 ( V_63 , V_107 ) ;
}
static void F_59 ( struct V_62 * V_63 , T_3 V_76 ,
T_6 V_108 , T_1 V_71 , int V_109 )
{
T_3 V_110 ;
int V_111 ;
V_110 = F_60 ( V_76 , V_108 , V_112 ) ;
V_111 = 0 ;
if ( V_110 > 1 ) {
V_76 = V_113 ;
V_111 = 1 ;
}
V_76 &= V_114 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_60 [ 1 ] |= V_71 ;
V_63 -> V_60 [ 2 ] = F_54 ( V_76 ) ;
V_63 -> V_60 [ 3 ] = F_56 ( V_76 ) ;
F_57 ( V_63 , V_115 ) ;
if ( V_111 )
V_63 -> V_60 [ 2 ] |= V_116 ;
if ( V_109 )
V_63 -> V_60 [ 2 ] |= V_117 ;
}
static void F_61 ( struct V_62 * V_63 , T_1 V_2 , int V_118 ,
T_3 V_76 , T_6 V_108 )
{
T_3 V_110 ;
int V_111 ;
V_110 = F_60 ( V_76 , V_108 , V_112 ) ;
V_111 = 0 ;
if ( V_110 > 1 ) {
V_76 = V_113 ;
V_111 = 1 ;
}
V_76 &= V_114 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_60 [ 0 ] = V_2 ;
V_63 -> V_60 [ 0 ] |= ( V_118 & 0xff ) << 24 ;
V_63 -> V_60 [ 1 ] = V_2 ;
V_63 -> V_60 [ 2 ] = F_54 ( V_76 ) ;
V_63 -> V_60 [ 3 ] = F_56 ( V_76 ) ;
F_57 ( V_63 , V_119 ) ;
if ( V_111 )
V_63 -> V_60 [ 2 ] |= V_116 ;
}
static void F_62 ( struct V_62 * V_63 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
F_57 ( V_63 , V_120 ) ;
}
static int F_63 ( struct V_64 * V_18 ,
struct V_62 * V_63 ,
bool V_121 )
{
V_45 V_122 , V_87 , V_86 , V_123 ;
unsigned long V_4 ;
F_53 ( V_18 -> V_103 & V_124 ) ;
V_125:
F_4 ( & V_18 -> V_88 , V_4 ) ;
V_86 = F_43 ( V_18 -> V_89 + V_126 ) ;
V_87 = F_43 ( V_18 -> V_89 + V_104 ) ;
V_123 = ( V_87 + sizeof( * V_63 ) ) % V_18 -> V_103 ;
V_122 = ( V_86 - V_123 ) % V_18 -> V_103 ;
if ( V_122 <= 2 ) {
struct V_62 V_127 ;
volatile T_3 V_98 = 0 ;
int V_21 ;
F_52 ( & V_127 , ( T_3 ) & V_98 ) ;
F_51 ( V_18 , & V_127 , V_87 ) ;
F_6 ( & V_18 -> V_88 , V_4 ) ;
if ( ( V_21 = F_48 ( & V_98 ) ) != 0 )
return V_21 ;
goto V_125;
}
F_51 ( V_18 , V_63 , V_87 ) ;
V_18 -> V_128 = V_121 ;
F_6 ( & V_18 -> V_88 , V_4 ) ;
return 0 ;
}
static int F_64 ( struct V_64 * V_18 , struct V_62 * V_63 )
{
return F_63 ( V_18 , V_63 , true ) ;
}
static int F_65 ( struct V_64 * V_18 )
{
struct V_62 V_63 ;
volatile T_3 V_98 = 0 ;
int V_21 ;
if ( ! V_18 -> V_128 )
return 0 ;
F_52 ( & V_63 , ( T_3 ) & V_98 ) ;
V_21 = F_63 ( V_18 , & V_63 , false ) ;
if ( V_21 )
return V_21 ;
return F_48 ( & V_98 ) ;
}
static int F_66 ( struct V_64 * V_18 , T_1 V_2 )
{
struct V_62 V_63 ;
F_58 ( & V_63 , V_2 ) ;
return F_64 ( V_18 , & V_63 ) ;
}
static void F_67 ( struct V_64 * V_18 )
{
V_45 V_2 ;
for ( V_2 = 0 ; V_2 <= 0xffff ; ++ V_2 )
F_66 ( V_18 , V_2 ) ;
F_65 ( V_18 ) ;
}
static void F_68 ( struct V_64 * V_18 )
{
V_45 V_129 ;
for ( V_129 = 0 ; V_129 <= 0xffff ; ++ V_129 ) {
struct V_62 V_63 ;
F_59 ( & V_63 , 0 , V_113 ,
V_129 , 1 ) ;
F_64 ( V_18 , & V_63 ) ;
}
F_65 ( V_18 ) ;
}
static void F_69 ( struct V_64 * V_18 )
{
struct V_62 V_63 ;
F_62 ( & V_63 ) ;
F_64 ( V_18 , & V_63 ) ;
F_65 ( V_18 ) ;
}
void F_70 ( struct V_64 * V_18 )
{
if ( F_71 ( V_18 , V_130 ) ) {
F_69 ( V_18 ) ;
} else {
F_67 ( V_18 ) ;
F_68 ( V_18 ) ;
}
}
static int F_72 ( struct V_1 * V_3 ,
T_3 V_76 , T_6 V_108 )
{
struct V_64 * V_18 ;
struct V_62 V_63 ;
int V_118 ;
V_118 = V_3 -> V_131 . V_118 ;
V_18 = V_30 [ V_3 -> V_2 ] ;
F_61 ( & V_63 , V_3 -> V_2 , V_118 , V_76 , V_108 ) ;
return F_64 ( V_18 , & V_63 ) ;
}
static int F_73 ( struct V_1 * V_3 )
{
struct V_64 * V_18 ;
int V_21 ;
V_18 = V_30 [ V_3 -> V_2 ] ;
V_21 = F_66 ( V_18 , V_3 -> V_2 ) ;
if ( V_21 )
return V_21 ;
if ( V_3 -> V_131 . V_132 )
V_21 = F_72 ( V_3 , 0 , ~ 0UL ) ;
return V_21 ;
}
static void F_74 ( struct V_133 * V_134 ,
T_3 V_76 , T_6 V_108 , int V_109 )
{
struct V_1 * V_3 ;
struct V_62 V_63 ;
int V_21 = 0 , V_59 ;
F_59 ( & V_63 , V_76 , V_108 , V_134 -> V_135 , V_109 ) ;
for ( V_59 = 0 ; V_59 < V_136 ; ++ V_59 ) {
if ( ! V_134 -> V_137 [ V_59 ] )
continue;
V_21 |= F_64 ( V_138 [ V_59 ] , & V_63 ) ;
}
F_11 (dev_data, &domain->dev_list, list) {
if ( ! V_3 -> V_131 . V_132 )
continue;
V_21 |= F_72 ( V_3 , V_76 , V_108 ) ;
}
F_53 ( V_21 ) ;
}
static void F_75 ( struct V_133 * V_134 ,
T_3 V_76 , T_6 V_108 )
{
F_74 ( V_134 , V_76 , V_108 , 0 ) ;
}
static void F_76 ( struct V_133 * V_134 )
{
F_74 ( V_134 , 0 , V_113 , 0 ) ;
}
static void F_77 ( struct V_133 * V_134 )
{
F_74 ( V_134 , 0 , V_113 , 1 ) ;
}
static void F_78 ( struct V_133 * V_134 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_136 ; ++ V_59 ) {
if ( ! V_134 -> V_137 [ V_59 ] )
continue;
F_65 ( V_138 [ V_59 ] ) ;
}
}
static void F_79 ( struct V_133 * V_134 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_73 ( V_3 ) ;
}
static bool F_80 ( struct V_133 * V_134 ,
T_7 V_139 )
{
T_3 * V_140 ;
if ( V_134 -> V_141 == V_142 )
return false ;
V_140 = ( void * ) F_81 ( V_139 ) ;
if ( ! V_140 )
return false ;
* V_140 = F_82 ( V_134 -> V_141 ,
F_83 ( V_134 -> V_143 ) ) ;
V_134 -> V_143 = V_140 ;
V_134 -> V_141 += 1 ;
V_134 -> V_144 = true ;
return true ;
}
static T_3 * F_84 ( struct V_133 * V_134 ,
unsigned long V_76 ,
unsigned long V_145 ,
T_3 * * V_146 ,
T_7 V_139 )
{
int V_147 , V_148 ;
T_3 * V_140 , * V_149 ;
F_85 ( ! F_86 ( V_145 ) ) ;
while ( V_76 > F_87 ( V_134 -> V_141 ) )
F_80 ( V_134 , V_139 ) ;
V_147 = V_134 -> V_141 - 1 ;
V_140 = & V_134 -> V_143 [ F_88 ( V_147 , V_76 ) ] ;
V_76 = F_89 ( V_76 , V_145 ) ;
V_148 = F_90 ( V_145 ) ;
while ( V_147 > V_148 ) {
if ( ! F_91 ( * V_140 ) ) {
V_149 = ( T_3 * ) F_81 ( V_139 ) ;
if ( ! V_149 )
return NULL ;
* V_140 = F_82 ( V_147 , F_83 ( V_149 ) ) ;
}
if ( F_92 ( * V_140 ) != V_147 )
return NULL ;
V_147 -= 1 ;
V_140 = F_93 ( * V_140 ) ;
if ( V_146 && V_147 == V_148 )
* V_146 = V_140 ;
V_140 = & V_140 [ F_88 ( V_147 , V_76 ) ] ;
}
return V_140 ;
}
static T_3 * F_94 ( struct V_133 * V_134 , unsigned long V_76 )
{
int V_147 ;
T_3 * V_140 ;
if ( V_76 > F_87 ( V_134 -> V_141 ) )
return NULL ;
V_147 = V_134 -> V_141 - 1 ;
V_140 = & V_134 -> V_143 [ F_88 ( V_147 , V_76 ) ] ;
while ( V_147 > 0 ) {
if ( ! F_91 ( * V_140 ) )
return NULL ;
if ( F_92 ( * V_140 ) == 0x07 ) {
unsigned long V_150 , V_151 ;
V_150 = F_95 ( * V_140 ) ;
V_150 = ~ ( ( F_96 ( V_150 ) << 3 ) - 1 ) ;
V_151 = ( ( unsigned long ) V_140 ) & V_150 ;
return ( T_3 * ) V_151 ;
}
if ( F_92 ( * V_140 ) != V_147 )
return NULL ;
V_147 -= 1 ;
V_140 = F_93 ( * V_140 ) ;
V_140 = & V_140 [ F_88 ( V_147 , V_76 ) ] ;
}
return V_140 ;
}
static int F_97 ( struct V_133 * V_152 ,
unsigned long V_153 ,
unsigned long V_61 ,
int V_154 ,
unsigned long V_145 )
{
T_3 V_151 , * V_140 ;
int V_59 , V_155 ;
if ( ! ( V_154 & V_156 ) )
return - V_157 ;
V_153 = F_98 ( V_153 ) ;
V_61 = F_98 ( V_61 ) ;
V_155 = F_96 ( V_145 ) ;
V_140 = F_84 ( V_152 , V_153 , V_145 , NULL , V_5 ) ;
for ( V_59 = 0 ; V_59 < V_155 ; ++ V_59 )
if ( F_91 ( V_140 [ V_59 ] ) )
return - V_158 ;
if ( V_145 > V_112 ) {
V_151 = F_99 ( V_61 , V_145 ) ;
V_151 |= F_100 ( 7 ) | V_159 | V_160 ;
} else
V_151 = V_61 | V_159 | V_160 ;
if ( V_154 & V_161 )
V_151 |= V_162 ;
if ( V_154 & V_163 )
V_151 |= V_164 ;
for ( V_59 = 0 ; V_59 < V_155 ; ++ V_59 )
V_140 [ V_59 ] = V_151 ;
F_101 ( V_152 ) ;
return 0 ;
}
static unsigned long F_102 ( struct V_133 * V_152 ,
unsigned long V_153 ,
unsigned long V_145 )
{
unsigned long long V_165 , V_166 ;
T_3 * V_140 ;
F_85 ( ! F_86 ( V_145 ) ) ;
V_166 = 0 ;
while ( V_166 < V_145 ) {
V_140 = F_94 ( V_152 , V_153 ) ;
if ( ! V_140 ) {
V_165 = V_112 ;
} else if ( F_92 ( * V_140 ) == 0 ) {
V_165 = V_112 ;
* V_140 = 0ULL ;
} else {
int V_155 , V_59 ;
V_165 = F_95 ( * V_140 ) ;
V_155 = F_96 ( V_165 ) ;
for ( V_59 = 0 ; V_59 < V_155 ; V_59 ++ )
V_140 [ V_59 ] = 0ULL ;
}
V_153 = ( V_153 & ~ ( V_165 - 1 ) ) + V_165 ;
V_166 += V_165 ;
}
F_85 ( ! F_86 ( V_166 ) ) ;
return V_166 ;
}
static int F_103 ( struct V_64 * V_18 ,
struct V_167 * V_20 )
{
T_1 V_168 , V_59 ;
for ( V_59 = V_20 -> V_169 ; V_59 <= V_20 -> V_170 ; ++ V_59 ) {
V_168 = V_23 [ V_59 ] ;
if ( V_30 [ V_168 ] == V_18 )
return 1 ;
}
return 0 ;
}
static int F_104 ( struct V_19 * V_171 ,
struct V_167 * V_172 )
{
T_3 V_173 ;
int V_21 ;
for ( V_173 = V_172 -> V_174 ; V_173 < V_172 -> V_175 ;
V_173 += V_112 ) {
V_21 = F_97 ( & V_171 -> V_134 , V_173 , V_173 , V_172 -> V_154 ,
V_112 ) ;
if ( V_21 )
return V_21 ;
if ( V_173 < V_171 -> V_176 )
F_105 ( V_173 >> V_177 ,
V_171 -> V_178 [ 0 ] -> V_179 ) ;
}
return 0 ;
}
static int F_106 ( struct V_64 * V_18 )
{
struct V_167 * V_20 ;
int V_21 ;
F_11 (entry, &amd_iommu_unity_map, list) {
if ( ! F_103 ( V_18 , V_20 ) )
continue;
V_21 = F_104 ( V_18 -> V_180 , V_20 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_107 ( struct V_19 * V_171 ,
T_1 V_2 )
{
struct V_167 * V_172 ;
int V_21 ;
F_11 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_2 >= V_172 -> V_169 && V_2 <= V_172 -> V_170 ) )
continue;
V_21 = F_104 ( V_171 , V_172 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static void F_108 ( struct V_19 * V_152 ,
unsigned long V_181 ,
unsigned int V_110 )
{
unsigned int V_59 , V_182 = V_152 -> V_176 >> V_177 ;
if ( V_181 + V_110 > V_182 )
V_110 = V_182 - V_181 ;
for ( V_59 = V_181 ; V_59 < V_181 + V_110 ; ++ V_59 ) {
int V_183 = V_59 / V_184 ;
int V_149 = V_59 % V_184 ;
F_105 ( V_149 , V_152 -> V_178 [ V_183 ] -> V_179 ) ;
}
}
static int F_109 ( struct V_19 * V_171 ,
bool V_185 , T_7 V_139 )
{
int V_183 = V_171 -> V_176 >> V_186 ;
struct V_64 * V_18 ;
unsigned long V_59 , V_187 ;
#ifdef F_110
V_185 = false ;
#endif
if ( V_183 >= V_188 )
return - V_31 ;
V_171 -> V_178 [ V_183 ] = F_2 ( sizeof( struct V_189 ) , V_139 ) ;
if ( ! V_171 -> V_178 [ V_183 ] )
return - V_31 ;
V_171 -> V_178 [ V_183 ] -> V_179 = ( void * ) F_81 ( V_139 ) ;
if ( ! V_171 -> V_178 [ V_183 ] -> V_179 )
goto V_37;
V_171 -> V_178 [ V_183 ] -> V_190 = V_171 -> V_176 ;
if ( V_185 ) {
unsigned long V_76 = V_171 -> V_176 ;
int V_59 , V_191 = V_184 / 512 ;
T_3 * V_140 , * V_146 ;
for ( V_59 = 0 ; V_59 < V_191 ; ++ V_59 ) {
V_140 = F_84 ( & V_171 -> V_134 , V_76 , V_112 ,
& V_146 , V_139 ) ;
if ( ! V_140 )
goto V_37;
V_171 -> V_178 [ V_183 ] -> V_192 [ V_59 ] = V_146 ;
V_76 += V_193 / 64 ;
}
}
V_187 = V_171 -> V_176 ;
V_171 -> V_176 += V_193 ;
if ( V_187 < V_194 &&
V_171 -> V_176 > V_194 ) {
unsigned long V_195 ;
int V_110 ;
V_110 = F_60 ( V_194 , 0x10000 , V_112 ) ;
V_195 = V_194 >> V_177 ;
F_108 ( V_171 , V_195 , V_110 ) ;
}
F_46 (iommu) {
if ( V_18 -> V_196 &&
V_18 -> V_196 >= V_171 -> V_178 [ V_183 ] -> V_190
&& V_18 -> V_196 < V_171 -> V_176 ) {
unsigned long V_197 ;
int V_110 = F_60 ( V_18 -> V_196 ,
V_18 -> V_198 ,
V_112 ) ;
V_197 = V_18 -> V_196 >> V_177 ;
F_108 ( V_171 , V_197 , V_110 ) ;
}
}
for ( V_59 = V_171 -> V_178 [ V_183 ] -> V_190 ;
V_59 < V_171 -> V_176 ;
V_59 += V_112 ) {
T_3 * V_140 = F_94 ( & V_171 -> V_134 , V_59 ) ;
if ( ! V_140 || ! F_91 ( * V_140 ) )
continue;
F_108 ( V_171 , V_59 << V_177 , 1 ) ;
}
F_101 ( & V_171 -> V_134 ) ;
return 0 ;
V_37:
F_101 ( & V_171 -> V_134 ) ;
F_111 ( ( unsigned long ) V_171 -> V_178 [ V_183 ] -> V_179 ) ;
F_9 ( V_171 -> V_178 [ V_183 ] ) ;
V_171 -> V_178 [ V_183 ] = NULL ;
return - V_31 ;
}
static unsigned long F_112 ( struct V_10 * V_11 ,
struct V_19 * V_152 ,
unsigned int V_110 ,
unsigned long V_199 ,
T_3 V_27 ,
unsigned long V_200 )
{
unsigned long V_201 = V_152 -> V_202 % V_193 ;
int V_203 = V_152 -> V_176 >> V_186 ;
int V_59 = V_200 >> V_186 ;
unsigned long V_204 ;
unsigned long V_76 = - 1 ;
unsigned long V_205 ;
V_201 >>= V_177 ;
V_204 = F_113 ( F_114 ( V_11 ) + 1 ,
V_112 ) >> V_177 ;
for (; V_59 < V_203 ; ++ V_59 ) {
unsigned long V_190 = V_152 -> V_178 [ V_59 ] -> V_190 >> V_177 ;
if ( V_152 -> V_178 [ V_59 ] -> V_190 >= V_27 )
break;
V_205 = F_115 ( V_184 , V_190 ,
V_27 >> V_177 ) ;
V_76 = F_116 ( V_152 -> V_178 [ V_59 ] -> V_179 ,
V_205 , V_201 , V_110 , 0 ,
V_204 , V_199 ) ;
if ( V_76 != - 1 ) {
V_76 = V_152 -> V_178 [ V_59 ] -> V_190 +
( V_76 << V_177 ) ;
V_152 -> V_202 = V_76 + ( V_110 << V_177 ) ;
break;
}
V_201 = 0 ;
}
return V_76 ;
}
static unsigned long F_117 ( struct V_10 * V_11 ,
struct V_19 * V_152 ,
unsigned int V_110 ,
unsigned long V_199 ,
T_3 V_27 )
{
unsigned long V_76 ;
#ifdef F_110
V_152 -> V_202 = 0 ;
V_152 -> V_206 = true ;
#endif
V_76 = F_112 ( V_11 , V_152 , V_110 , V_199 ,
V_27 , V_152 -> V_202 ) ;
if ( V_76 == - 1 ) {
V_152 -> V_202 = 0 ;
V_76 = F_112 ( V_11 , V_152 , V_110 , V_199 ,
V_27 , 0 ) ;
V_152 -> V_206 = true ;
}
if ( F_118 ( V_76 == - 1 ) )
V_76 = V_207 ;
F_53 ( ( V_76 + ( V_112 * V_110 ) ) > V_152 -> V_176 ) ;
return V_76 ;
}
static void F_119 ( struct V_19 * V_152 ,
unsigned long V_76 ,
unsigned int V_110 )
{
unsigned V_59 = V_76 >> V_186 ;
struct V_189 * V_208 = V_152 -> V_178 [ V_59 ] ;
F_85 ( V_59 >= V_188 || V_208 == NULL ) ;
#ifdef F_110
if ( V_59 < 4 )
return;
#endif
if ( V_76 >= V_152 -> V_202 )
V_152 -> V_206 = true ;
V_76 = ( V_76 % V_193 ) >> V_177 ;
F_120 ( V_208 -> V_179 , V_76 , V_110 ) ;
}
static void F_121 ( struct V_133 * V_134 )
{
unsigned long V_4 ;
F_4 ( & V_209 , V_4 ) ;
F_122 ( & V_134 -> V_210 , & V_211 ) ;
F_6 ( & V_209 , V_4 ) ;
}
static void F_123 ( struct V_133 * V_134 )
{
unsigned long V_4 ;
F_4 ( & V_209 , V_4 ) ;
F_8 ( & V_134 -> V_210 ) ;
F_6 ( & V_209 , V_4 ) ;
}
static T_1 F_124 ( void )
{
unsigned long V_4 ;
int V_135 ;
F_125 ( & V_212 , V_4 ) ;
V_135 = F_126 ( V_213 , V_214 ) ;
F_85 ( V_135 == 0 ) ;
if ( V_135 > 0 && V_135 < V_214 )
F_105 ( V_135 , V_213 ) ;
else
V_135 = 0 ;
F_127 ( & V_212 , V_4 ) ;
return V_135 ;
}
static void F_128 ( int V_135 )
{
unsigned long V_4 ;
F_125 ( & V_212 , V_4 ) ;
if ( V_135 > 0 && V_135 < V_214 )
F_129 ( V_135 , V_213 ) ;
F_127 ( & V_212 , V_4 ) ;
}
static void F_130 ( struct V_133 * V_134 )
{
int V_59 , V_215 ;
T_3 * V_216 , * V_217 , * V_218 ;
V_216 = V_134 -> V_143 ;
if ( ! V_216 )
return;
for ( V_59 = 0 ; V_59 < 512 ; ++ V_59 ) {
if ( ! F_91 ( V_216 [ V_59 ] ) )
continue;
V_217 = F_93 ( V_216 [ V_59 ] ) ;
for ( V_215 = 0 ; V_215 < 512 ; ++ V_215 ) {
if ( ! F_91 ( V_217 [ V_215 ] ) )
continue;
V_218 = F_93 ( V_217 [ V_215 ] ) ;
F_111 ( ( unsigned long ) V_218 ) ;
}
F_111 ( ( unsigned long ) V_217 ) ;
}
F_111 ( ( unsigned long ) V_216 ) ;
V_134 -> V_143 = NULL ;
}
static void F_131 ( struct V_19 * V_152 )
{
int V_59 ;
if ( ! V_152 )
return;
F_123 ( & V_152 -> V_134 ) ;
F_130 ( & V_152 -> V_134 ) ;
for ( V_59 = 0 ; V_59 < V_188 ; ++ V_59 ) {
if ( ! V_152 -> V_178 [ V_59 ] )
continue;
F_111 ( ( unsigned long ) V_152 -> V_178 [ V_59 ] -> V_179 ) ;
F_9 ( V_152 -> V_178 [ V_59 ] ) ;
}
F_9 ( V_152 ) ;
}
static struct V_19 * F_132 ( void )
{
struct V_19 * V_171 ;
V_171 = F_2 ( sizeof( struct V_19 ) , V_5 ) ;
if ( ! V_171 )
return NULL ;
F_133 ( & V_171 -> V_134 . V_88 ) ;
V_171 -> V_134 . V_135 = F_124 () ;
if ( V_171 -> V_134 . V_135 == 0 )
goto V_219;
F_134 ( & V_171 -> V_134 . V_220 ) ;
V_171 -> V_134 . V_141 = V_221 ;
V_171 -> V_134 . V_143 = ( void * ) F_81 ( V_5 ) ;
V_171 -> V_134 . V_4 = V_222 ;
V_171 -> V_134 . V_223 = V_171 ;
if ( ! V_171 -> V_134 . V_143 )
goto V_219;
V_171 -> V_206 = false ;
V_171 -> V_26 = 0xffff ;
F_121 ( & V_171 -> V_134 ) ;
if ( F_109 ( V_171 , true , V_5 ) )
goto V_219;
V_171 -> V_178 [ 0 ] -> V_179 [ 0 ] = 1 ;
V_171 -> V_202 = 0 ;
return V_171 ;
V_219:
F_131 ( V_171 ) ;
return NULL ;
}
static bool V_19 ( struct V_133 * V_134 )
{
return V_134 -> V_4 & V_222 ;
}
static void F_135 ( T_1 V_2 , struct V_133 * V_134 , bool V_131 )
{
T_3 V_224 = F_83 ( V_134 -> V_143 ) ;
V_45 V_4 = 0 ;
V_224 |= ( V_134 -> V_141 & V_225 )
<< V_226 ;
V_224 |= V_162 | V_164 | V_159 | V_227 ;
if ( V_131 )
V_4 |= V_228 ;
V_34 [ V_2 ] . V_60 [ 3 ] |= V_4 ;
V_34 [ V_2 ] . V_60 [ 2 ] = V_134 -> V_135 ;
V_34 [ V_2 ] . V_60 [ 1 ] = F_56 ( V_224 ) ;
V_34 [ V_2 ] . V_60 [ 0 ] = F_54 ( V_224 ) ;
}
static void F_136 ( T_1 V_2 )
{
V_34 [ V_2 ] . V_60 [ 0 ] = V_159 | V_227 ;
V_34 [ V_2 ] . V_60 [ 1 ] = 0 ;
V_34 [ V_2 ] . V_60 [ 2 ] = 0 ;
F_137 ( V_2 ) ;
}
static void F_138 ( struct V_1 * V_3 ,
struct V_133 * V_134 )
{
struct V_64 * V_18 ;
bool V_131 ;
V_18 = V_30 [ V_3 -> V_2 ] ;
V_131 = V_3 -> V_131 . V_132 ;
V_3 -> V_134 = V_134 ;
F_122 ( & V_3 -> V_210 , & V_134 -> V_220 ) ;
F_135 ( V_3 -> V_2 , V_134 , V_131 ) ;
V_134 -> V_137 [ V_18 -> V_183 ] += 1 ;
V_134 -> V_229 += 1 ;
F_73 ( V_3 ) ;
}
static void F_139 ( struct V_1 * V_3 )
{
struct V_64 * V_18 ;
V_18 = V_30 [ V_3 -> V_2 ] ;
V_3 -> V_134 -> V_137 [ V_18 -> V_183 ] -= 1 ;
V_3 -> V_134 -> V_229 -= 1 ;
V_3 -> V_134 = NULL ;
F_8 ( & V_3 -> V_210 ) ;
F_136 ( V_3 -> V_2 ) ;
F_73 ( V_3 ) ;
}
static int F_140 ( struct V_1 * V_3 ,
struct V_133 * V_134 )
{
int V_21 ;
F_141 ( & V_134 -> V_88 ) ;
if ( V_3 -> V_32 != NULL ) {
struct V_1 * V_32 = V_3 -> V_32 ;
V_21 = - V_158 ;
if ( V_32 -> V_134 != NULL &&
V_32 -> V_134 != V_134 )
goto V_9;
if ( V_3 -> V_134 != NULL &&
V_3 -> V_134 != V_134 )
goto V_9;
if ( V_32 -> V_134 == NULL )
F_138 ( V_32 , V_134 ) ;
F_142 ( & V_32 -> V_6 ) ;
}
if ( V_3 -> V_134 == NULL )
F_138 ( V_3 , V_134 ) ;
F_142 ( & V_3 -> V_6 ) ;
V_21 = 0 ;
V_9:
F_143 ( & V_134 -> V_88 ) ;
return V_21 ;
}
static int F_144 ( struct V_10 * V_11 ,
struct V_133 * V_134 )
{
struct V_12 * V_13 = F_14 ( V_11 ) ;
struct V_1 * V_3 ;
unsigned long V_4 ;
int V_21 ;
V_3 = F_16 ( V_11 ) ;
if ( V_230 && F_145 ( V_13 , V_177 ) == 0 ) {
V_3 -> V_131 . V_132 = true ;
V_3 -> V_131 . V_118 = F_146 ( V_13 ) ;
}
F_125 ( & V_212 , V_4 ) ;
V_21 = F_140 ( V_3 , V_134 ) ;
F_127 ( & V_212 , V_4 ) ;
F_77 ( V_134 ) ;
return V_21 ;
}
static void F_147 ( struct V_1 * V_3 )
{
struct V_133 * V_134 ;
unsigned long V_4 ;
F_85 ( ! V_3 -> V_134 ) ;
V_134 = V_3 -> V_134 ;
F_4 ( & V_134 -> V_88 , V_4 ) ;
if ( V_3 -> V_32 != NULL ) {
struct V_1 * V_32 = V_3 -> V_32 ;
if ( F_148 ( & V_32 -> V_6 ) )
F_139 ( V_32 ) ;
}
if ( F_148 ( & V_3 -> V_6 ) )
F_139 ( V_3 ) ;
F_6 ( & V_134 -> V_88 , V_4 ) ;
if ( V_231 &&
( V_3 -> V_134 == NULL && V_134 != V_232 ) )
F_140 ( V_3 , V_232 ) ;
}
static void F_149 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
F_125 ( & V_212 , V_4 ) ;
F_147 ( V_3 ) ;
F_127 ( & V_212 , V_4 ) ;
if ( V_3 -> V_131 . V_132 ) {
F_150 ( F_14 ( V_11 ) ) ;
V_3 -> V_131 . V_132 = false ;
}
}
static struct V_133 * F_151 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
struct V_133 * V_152 = NULL ;
unsigned long V_4 ;
V_3 = F_16 ( V_11 ) ;
if ( V_3 -> V_134 )
return V_3 -> V_134 ;
if ( V_3 -> V_32 != NULL ) {
struct V_1 * V_32 = V_3 -> V_32 ;
F_152 ( & V_212 , V_4 ) ;
if ( V_32 -> V_134 != NULL ) {
F_140 ( V_3 , V_32 -> V_134 ) ;
V_152 = V_32 -> V_134 ;
}
F_153 ( & V_212 , V_4 ) ;
}
return V_152 ;
}
static int F_154 ( struct V_233 * V_234 ,
unsigned long V_235 , void * V_60 )
{
struct V_10 * V_11 = V_60 ;
T_1 V_2 ;
struct V_133 * V_134 ;
struct V_19 * V_236 ;
struct V_64 * V_18 ;
unsigned long V_4 ;
if ( ! F_19 ( V_11 ) )
return 0 ;
V_2 = F_13 ( V_11 ) ;
V_18 = V_30 [ V_2 ] ;
switch ( V_235 ) {
case V_237 :
V_134 = F_151 ( V_11 ) ;
if ( ! V_134 )
goto V_238;
if ( V_231 )
break;
F_149 ( V_11 ) ;
break;
case V_239 :
F_20 ( V_11 ) ;
V_134 = F_151 ( V_11 ) ;
V_236 = F_17 ( V_2 ) ;
if ( V_236 )
goto V_238;
V_236 = F_132 () ;
if ( ! V_236 )
goto V_238;
V_236 -> V_26 = V_2 ;
F_4 ( & V_25 , V_4 ) ;
F_5 ( & V_236 -> V_210 , & V_24 ) ;
F_6 ( & V_25 , V_4 ) ;
break;
case V_240 :
F_24 ( V_11 ) ;
default:
goto V_238;
}
F_65 ( V_18 ) ;
V_238:
return 0 ;
}
void F_155 ( void )
{
F_156 ( & V_28 , & V_241 ) ;
}
static struct V_133 * F_157 ( struct V_10 * V_11 )
{
struct V_133 * V_134 ;
struct V_19 * V_171 ;
T_1 V_2 = F_13 ( V_11 ) ;
if ( ! F_19 ( V_11 ) )
return F_158 ( - V_157 ) ;
V_134 = F_151 ( V_11 ) ;
if ( V_134 != NULL && ! V_19 ( V_134 ) )
return F_158 ( - V_158 ) ;
if ( V_134 != NULL )
return V_134 ;
V_171 = F_17 ( V_2 ) ;
if ( ! V_171 )
V_171 = V_30 [ V_2 ] -> V_180 ;
F_144 ( V_11 , & V_171 -> V_134 ) ;
F_159 ( L_21 ,
V_171 -> V_134 . V_135 , F_22 ( V_11 ) ) ;
return & V_171 -> V_134 ;
}
static void F_160 ( struct V_133 * V_134 )
{
struct V_1 * V_3 ;
F_11 (dev_data, &domain->dev_list, list)
F_135 ( V_3 -> V_2 , V_134 , V_3 -> V_131 . V_132 ) ;
}
static void F_101 ( struct V_133 * V_134 )
{
if ( ! V_134 -> V_144 )
return;
F_160 ( V_134 ) ;
F_79 ( V_134 ) ;
F_77 ( V_134 ) ;
V_134 -> V_144 = false ;
}
static T_3 * F_161 ( struct V_19 * V_152 ,
unsigned long V_76 )
{
struct V_189 * V_178 ;
T_3 * V_140 , * V_146 ;
V_178 = V_152 -> V_178 [ F_162 ( V_76 ) ] ;
if ( ! V_178 )
return NULL ;
V_140 = V_178 -> V_192 [ F_163 ( V_76 ) ] ;
if ( ! V_140 ) {
V_140 = F_84 ( & V_152 -> V_134 , V_76 , V_112 , & V_146 ,
V_242 ) ;
V_178 -> V_192 [ F_163 ( V_76 ) ] = V_146 ;
} else
V_140 += F_88 ( 0 , V_76 ) ;
F_101 ( & V_152 -> V_134 ) ;
return V_140 ;
}
static T_8 F_164 ( struct V_19 * V_152 ,
unsigned long V_76 ,
T_9 V_243 ,
int V_244 )
{
T_3 * V_140 , V_151 ;
F_53 ( V_76 > V_152 -> V_176 ) ;
V_243 &= V_114 ;
V_140 = F_161 ( V_152 , V_76 ) ;
if ( ! V_140 )
return V_207 ;
V_151 = V_243 | V_159 | V_160 ;
if ( V_244 == V_245 )
V_151 |= V_162 ;
else if ( V_244 == V_246 )
V_151 |= V_164 ;
else if ( V_244 == V_247 )
V_151 |= V_162 | V_164 ;
F_53 ( * V_140 ) ;
* V_140 = V_151 ;
return ( T_8 ) V_76 ;
}
static void F_165 ( struct V_19 * V_152 ,
unsigned long V_76 )
{
struct V_189 * V_178 ;
T_3 * V_140 ;
if ( V_76 >= V_152 -> V_176 )
return;
V_178 = V_152 -> V_178 [ F_162 ( V_76 ) ] ;
if ( ! V_178 )
return;
V_140 = V_178 -> V_192 [ F_163 ( V_76 ) ] ;
if ( ! V_140 )
return;
V_140 += F_88 ( 0 , V_76 ) ;
F_53 ( ! * V_140 ) ;
* V_140 = 0ULL ;
}
static T_8 F_166 ( struct V_10 * V_11 ,
struct V_19 * V_171 ,
T_9 V_243 ,
T_6 V_108 ,
int V_248 ,
bool V_249 ,
T_3 V_27 )
{
T_8 V_190 = V_243 & ~ V_114 ;
T_8 V_76 , V_200 , V_21 ;
unsigned int V_110 ;
unsigned long V_199 = 0 ;
int V_59 ;
V_110 = F_60 ( V_243 , V_108 , V_112 ) ;
V_243 &= V_114 ;
F_167 ( V_58 ) ;
if ( V_110 > 1 )
F_167 ( V_54 ) ;
if ( V_249 )
V_199 = ( 1UL << F_168 ( V_108 ) ) - 1 ;
V_250:
V_76 = F_117 ( V_11 , V_171 , V_110 , V_199 ,
V_27 ) ;
if ( F_118 ( V_76 == V_207 ) ) {
V_171 -> V_202 = V_171 -> V_176 ;
if ( F_109 ( V_171 , false , V_242 ) )
goto V_238;
goto V_250;
}
V_200 = V_76 ;
for ( V_59 = 0 ; V_59 < V_110 ; ++ V_59 ) {
V_21 = F_164 ( V_171 , V_200 , V_243 , V_248 ) ;
if ( V_21 == V_207 )
goto V_251;
V_243 += V_112 ;
V_200 += V_112 ;
}
V_76 += V_190 ;
F_169 ( V_57 , V_108 ) ;
if ( F_118 ( V_171 -> V_206 && ! V_46 ) ) {
F_76 ( & V_171 -> V_134 ) ;
V_171 -> V_206 = false ;
} else if ( F_118 ( V_252 ) )
F_75 ( & V_171 -> V_134 , V_76 , V_108 ) ;
V_238:
return V_76 ;
V_251:
for ( -- V_59 ; V_59 >= 0 ; -- V_59 ) {
V_200 -= V_112 ;
F_165 ( V_171 , V_200 ) ;
}
F_119 ( V_171 , V_76 , V_110 ) ;
return V_207 ;
}
static void F_170 ( struct V_19 * V_171 ,
T_8 V_253 ,
T_6 V_108 ,
int V_248 )
{
T_8 V_254 ;
T_8 V_59 , V_200 ;
unsigned int V_110 ;
if ( ( V_253 == V_207 ) ||
( V_253 + V_108 > V_171 -> V_176 ) )
return;
V_254 = V_253 ;
V_110 = F_60 ( V_253 , V_108 , V_112 ) ;
V_253 &= V_114 ;
V_200 = V_253 ;
for ( V_59 = 0 ; V_59 < V_110 ; ++ V_59 ) {
F_165 ( V_171 , V_200 ) ;
V_200 += V_112 ;
}
F_171 ( V_57 , V_108 ) ;
F_119 ( V_171 , V_253 , V_110 ) ;
if ( V_46 || V_171 -> V_206 ) {
F_75 ( & V_171 -> V_134 , V_254 , V_108 ) ;
V_171 -> V_206 = false ;
}
}
static T_8 F_172 ( struct V_10 * V_11 , struct V_149 * V_149 ,
unsigned long V_190 , T_6 V_108 ,
enum V_255 V_248 ,
struct V_256 * V_257 )
{
unsigned long V_4 ;
struct V_133 * V_134 ;
T_8 V_173 ;
T_3 V_27 ;
T_9 V_243 = F_173 ( V_149 ) + V_190 ;
F_167 ( V_48 ) ;
V_134 = F_157 ( V_11 ) ;
if ( F_174 ( V_134 ) == - V_157 )
return ( T_8 ) V_243 ;
else if ( F_175 ( V_134 ) )
return V_207 ;
V_27 = * V_11 -> V_27 ;
F_4 ( & V_134 -> V_88 , V_4 ) ;
V_173 = F_166 ( V_11 , V_134 -> V_223 , V_243 , V_108 , V_248 , false ,
V_27 ) ;
if ( V_173 == V_207 )
goto V_238;
F_78 ( V_134 ) ;
V_238:
F_6 ( & V_134 -> V_88 , V_4 ) ;
return V_173 ;
}
static void F_176 ( struct V_10 * V_11 , T_8 V_253 , T_6 V_108 ,
enum V_255 V_248 , struct V_256 * V_257 )
{
unsigned long V_4 ;
struct V_133 * V_134 ;
F_167 ( V_49 ) ;
V_134 = F_157 ( V_11 ) ;
if ( F_175 ( V_134 ) )
return;
F_4 ( & V_134 -> V_88 , V_4 ) ;
F_170 ( V_134 -> V_223 , V_253 , V_108 , V_248 ) ;
F_78 ( V_134 ) ;
F_6 ( & V_134 -> V_88 , V_4 ) ;
}
static int F_177 ( struct V_10 * V_11 , struct V_258 * V_259 ,
int V_260 , int V_248 )
{
struct V_258 * V_111 ;
int V_59 ;
F_178 (sglist, s, nelems, i) {
V_111 -> V_261 = ( T_8 ) F_179 ( V_111 ) ;
V_111 -> V_262 = V_111 -> V_263 ;
}
return V_260 ;
}
static int F_180 ( struct V_10 * V_11 , struct V_258 * V_259 ,
int V_260 , enum V_255 V_248 ,
struct V_256 * V_257 )
{
unsigned long V_4 ;
struct V_133 * V_134 ;
int V_59 ;
struct V_258 * V_111 ;
T_9 V_243 ;
int V_264 = 0 ;
T_3 V_27 ;
F_167 ( V_50 ) ;
V_134 = F_157 ( V_11 ) ;
if ( F_174 ( V_134 ) == - V_157 )
return F_177 ( V_11 , V_259 , V_260 , V_248 ) ;
else if ( F_175 ( V_134 ) )
return 0 ;
V_27 = * V_11 -> V_27 ;
F_4 ( & V_134 -> V_88 , V_4 ) ;
F_178 (sglist, s, nelems, i) {
V_243 = F_179 ( V_111 ) ;
V_111 -> V_261 = F_166 ( V_11 , V_134 -> V_223 ,
V_243 , V_111 -> V_263 , V_248 , false ,
V_27 ) ;
if ( V_111 -> V_261 ) {
V_111 -> V_262 = V_111 -> V_263 ;
V_264 ++ ;
} else
goto V_265;
}
F_78 ( V_134 ) ;
V_238:
F_6 ( & V_134 -> V_88 , V_4 ) ;
return V_264 ;
V_265:
F_178 (sglist, s, mapped_elems, i) {
if ( V_111 -> V_261 )
F_170 ( V_134 -> V_223 , V_111 -> V_261 ,
V_111 -> V_262 , V_248 ) ;
V_111 -> V_261 = V_111 -> V_262 = 0 ;
}
V_264 = 0 ;
goto V_238;
}
static void F_181 ( struct V_10 * V_11 , struct V_258 * V_259 ,
int V_260 , enum V_255 V_248 ,
struct V_256 * V_257 )
{
unsigned long V_4 ;
struct V_133 * V_134 ;
struct V_258 * V_111 ;
int V_59 ;
F_167 ( V_51 ) ;
V_134 = F_157 ( V_11 ) ;
if ( F_175 ( V_134 ) )
return;
F_4 ( & V_134 -> V_88 , V_4 ) ;
F_178 (sglist, s, nelems, i) {
F_170 ( V_134 -> V_223 , V_111 -> V_261 ,
V_111 -> V_262 , V_248 ) ;
V_111 -> V_261 = V_111 -> V_262 = 0 ;
}
F_78 ( V_134 ) ;
F_6 ( & V_134 -> V_88 , V_4 ) ;
}
static void * F_182 ( struct V_10 * V_11 , T_6 V_108 ,
T_8 * V_253 , T_7 V_266 )
{
unsigned long V_4 ;
void * V_267 ;
struct V_133 * V_134 ;
T_9 V_243 ;
T_3 V_27 = V_11 -> V_268 ;
F_167 ( V_52 ) ;
V_134 = F_157 ( V_11 ) ;
if ( F_174 ( V_134 ) == - V_157 ) {
V_267 = ( void * ) F_183 ( V_266 , F_168 ( V_108 ) ) ;
* V_253 = F_55 ( V_267 ) ;
return V_267 ;
} else if ( F_175 ( V_134 ) )
return NULL ;
V_27 = V_11 -> V_268 ;
V_266 &= ~ ( V_269 | V_270 | V_271 ) ;
V_266 |= V_272 ;
V_267 = ( void * ) F_183 ( V_266 , F_168 ( V_108 ) ) ;
if ( ! V_267 )
return NULL ;
V_243 = F_83 ( V_267 ) ;
if ( ! V_27 )
V_27 = * V_11 -> V_27 ;
F_4 ( & V_134 -> V_88 , V_4 ) ;
* V_253 = F_166 ( V_11 , V_134 -> V_223 , V_243 ,
V_108 , V_247 , true , V_27 ) ;
if ( * V_253 == V_207 ) {
F_6 ( & V_134 -> V_88 , V_4 ) ;
goto V_37;
}
F_78 ( V_134 ) ;
F_6 ( & V_134 -> V_88 , V_4 ) ;
return V_267 ;
V_37:
F_184 ( ( unsigned long ) V_267 , F_168 ( V_108 ) ) ;
return NULL ;
}
static void F_185 ( struct V_10 * V_11 , T_6 V_108 ,
void * V_267 , T_8 V_253 )
{
unsigned long V_4 ;
struct V_133 * V_134 ;
F_167 ( V_53 ) ;
V_134 = F_157 ( V_11 ) ;
if ( F_175 ( V_134 ) )
goto V_273;
F_4 ( & V_134 -> V_88 , V_4 ) ;
F_170 ( V_134 -> V_223 , V_253 , V_108 , V_247 ) ;
F_78 ( V_134 ) ;
F_6 ( & V_134 -> V_88 , V_4 ) ;
V_273:
F_184 ( ( unsigned long ) V_267 , F_168 ( V_108 ) ) ;
}
static int F_186 ( struct V_10 * V_11 , T_3 V_274 )
{
return F_19 ( V_11 ) ;
}
static void F_187 ( void )
{
struct V_12 * V_11 = NULL ;
struct V_19 * V_171 ;
T_1 V_2 ;
F_26 (dev) {
if ( ! F_19 ( & V_11 -> V_11 ) )
continue;
if ( F_151 ( & V_11 -> V_11 ) )
continue;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_171 = F_132 () ;
if ( ! V_171 )
continue;
F_107 ( V_171 , V_2 ) ;
V_171 -> V_26 = V_2 ;
F_144 ( & V_11 -> V_11 , & V_171 -> V_134 ) ;
F_5 ( & V_171 -> V_210 , & V_24 ) ;
}
}
static unsigned F_188 ( void )
{
struct V_12 * V_13 = NULL ;
unsigned V_275 = 0 ;
F_26 (pdev) {
if ( ! F_19 ( & V_13 -> V_11 ) ) {
V_275 += 1 ;
continue;
}
V_13 -> V_11 . V_17 . V_276 = & V_277 ;
}
return V_275 ;
}
void T_2 F_189 ( void )
{
F_190 ( & V_278 ) ;
}
int T_2 F_191 ( void )
{
struct V_64 * V_18 ;
int V_21 , V_275 ;
F_46 (iommu) {
V_18 -> V_180 = F_132 () ;
if ( V_18 -> V_180 == NULL )
return - V_31 ;
V_18 -> V_180 -> V_134 . V_4 |= V_279 ;
V_21 = F_106 ( V_18 ) ;
if ( V_21 )
goto V_280;
}
F_187 () ;
V_281 = 1 ;
V_282 = 0 ;
V_275 = F_188 () ;
if ( V_275 && V_283 > V_284 ) {
V_282 = 1 ;
}
F_31 () ;
return 0 ;
V_280:
F_46 (iommu) {
if ( V_18 -> V_180 )
F_131 ( V_18 -> V_180 ) ;
}
return V_21 ;
}
static void F_192 ( struct V_133 * V_134 )
{
struct V_1 * V_3 , * V_285 ;
unsigned long V_4 ;
F_125 ( & V_212 , V_4 ) ;
F_27 (dev_data, next, &domain->dev_list, list) {
F_147 ( V_3 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
}
F_127 ( & V_212 , V_4 ) ;
}
static void F_193 ( struct V_133 * V_134 )
{
if ( ! V_134 )
return;
F_123 ( V_134 ) ;
if ( V_134 -> V_135 )
F_128 ( V_134 -> V_135 ) ;
F_9 ( V_134 ) ;
}
static struct V_133 * F_194 ( void )
{
struct V_133 * V_134 ;
V_134 = F_2 ( sizeof( * V_134 ) , V_5 ) ;
if ( ! V_134 )
return NULL ;
F_133 ( & V_134 -> V_88 ) ;
F_195 ( & V_134 -> V_286 ) ;
V_134 -> V_135 = F_124 () ;
if ( ! V_134 -> V_135 )
goto V_287;
F_134 ( & V_134 -> V_220 ) ;
F_121 ( V_134 ) ;
return V_134 ;
V_287:
F_9 ( V_134 ) ;
return NULL ;
}
static int F_196 ( struct V_288 * V_152 )
{
struct V_133 * V_134 ;
V_134 = F_194 () ;
if ( ! V_134 )
goto V_37;
V_134 -> V_141 = V_289 ;
V_134 -> V_143 = ( void * ) F_81 ( V_5 ) ;
if ( ! V_134 -> V_143 )
goto V_37;
V_152 -> V_223 = V_134 ;
return 0 ;
V_37:
F_193 ( V_134 ) ;
return - V_31 ;
}
static void F_197 ( struct V_288 * V_152 )
{
struct V_133 * V_134 = V_152 -> V_223 ;
if ( ! V_134 )
return;
if ( V_134 -> V_229 > 0 )
F_192 ( V_134 ) ;
F_85 ( V_134 -> V_229 != 0 ) ;
F_130 ( V_134 ) ;
F_193 ( V_134 ) ;
V_152 -> V_223 = NULL ;
}
static void F_198 ( struct V_288 * V_152 ,
struct V_10 * V_11 )
{
struct V_1 * V_3 = V_11 -> V_17 . V_18 ;
struct V_64 * V_18 ;
T_1 V_2 ;
if ( ! F_19 ( V_11 ) )
return;
V_2 = F_13 ( V_11 ) ;
if ( V_3 -> V_134 != NULL )
F_149 ( V_11 ) ;
V_18 = V_30 [ V_2 ] ;
if ( ! V_18 )
return;
F_65 ( V_18 ) ;
}
static int F_199 ( struct V_288 * V_152 ,
struct V_10 * V_11 )
{
struct V_133 * V_134 = V_152 -> V_223 ;
struct V_1 * V_3 ;
struct V_64 * V_18 ;
int V_21 ;
if ( ! F_19 ( V_11 ) )
return - V_157 ;
V_3 = V_11 -> V_17 . V_18 ;
V_18 = V_30 [ V_3 -> V_2 ] ;
if ( ! V_18 )
return - V_157 ;
if ( V_3 -> V_134 )
F_149 ( V_11 ) ;
V_21 = F_144 ( V_11 , V_134 ) ;
F_65 ( V_18 ) ;
return V_21 ;
}
static int F_200 ( struct V_288 * V_152 , unsigned long V_290 ,
T_9 V_243 , int V_291 , int V_292 )
{
unsigned long V_145 = 0x1000UL << V_291 ;
struct V_133 * V_134 = V_152 -> V_223 ;
int V_154 = 0 ;
int V_21 ;
if ( V_292 & V_293 )
V_154 |= V_161 ;
if ( V_292 & V_294 )
V_154 |= V_163 ;
F_201 ( & V_134 -> V_286 ) ;
V_21 = F_97 ( V_134 , V_290 , V_243 , V_154 , V_145 ) ;
F_202 ( & V_134 -> V_286 ) ;
return V_21 ;
}
static int F_203 ( struct V_288 * V_152 , unsigned long V_290 ,
int V_291 )
{
struct V_133 * V_134 = V_152 -> V_223 ;
unsigned long V_145 , V_165 ;
V_145 = 0x1000UL << V_291 ;
F_201 ( & V_134 -> V_286 ) ;
V_165 = F_102 ( V_134 , V_290 , V_145 ) ;
F_202 ( & V_134 -> V_286 ) ;
F_77 ( V_134 ) ;
return F_168 ( V_165 ) ;
}
static T_9 F_204 ( struct V_288 * V_152 ,
unsigned long V_290 )
{
struct V_133 * V_134 = V_152 -> V_223 ;
unsigned long V_295 ;
T_9 V_243 ;
T_3 * V_140 , V_151 ;
V_140 = F_94 ( V_134 , V_290 ) ;
if ( ! V_140 || ! F_91 ( * V_140 ) )
return 0 ;
if ( F_92 ( * V_140 ) == 0 )
V_295 = V_112 - 1 ;
else
V_295 = F_95 ( * V_140 ) - 1 ;
V_151 = * V_140 & V_296 ;
V_243 = ( V_151 & ~ V_295 ) | ( V_290 & V_295 ) ;
return V_243 ;
}
static int F_205 ( struct V_288 * V_134 ,
unsigned long V_297 )
{
switch ( V_297 ) {
case V_298 :
return 1 ;
}
return 0 ;
}
int T_2 F_206 ( void )
{
struct V_64 * V_18 ;
struct V_12 * V_11 = NULL ;
T_1 V_2 ;
V_232 = F_194 () ;
if ( ! V_232 )
return - V_31 ;
V_232 -> V_141 |= V_299 ;
F_26 (dev) {
if ( ! F_19 ( & V_11 -> V_11 ) )
continue;
V_2 = F_13 ( & V_11 -> V_11 ) ;
V_18 = V_30 [ V_2 ] ;
if ( ! V_18 )
continue;
F_144 ( & V_11 -> V_11 , V_232 ) ;
}
F_207 ( L_22 ) ;
return 0 ;
}
