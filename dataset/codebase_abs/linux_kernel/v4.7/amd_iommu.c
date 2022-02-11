static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const char * V_5 , * V_6 ;
V_5 = F_2 ( F_3 ( V_2 ) ) ;
V_6 = F_4 ( F_3 ( V_2 ) ) ;
if ( ! V_5 || ! ( * V_5 ) )
return - V_7 ;
if ( ! V_6 || ! ( * V_6 ) )
return strcmp ( V_5 , V_4 -> V_5 ) ;
if ( ! ( * V_4 -> V_6 ) )
return strcmp ( V_5 , V_4 -> V_5 ) ;
return ( strcmp ( V_5 , V_4 -> V_5 ) || strcmp ( V_6 , V_4 -> V_6 ) ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
return F_7 ( V_9 -> V_10 -> V_11 , V_9 -> V_12 ) ;
}
static inline int F_8 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_3 * V_13 ;
F_9 (p, &acpihid_map, list) {
if ( ! F_1 ( V_2 , V_13 ) ) {
if ( V_4 )
* V_4 = V_13 ;
return V_13 -> V_14 ;
}
}
return - V_15 ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
int V_14 ;
if ( F_11 ( V_2 ) )
V_14 = F_5 ( V_2 ) ;
else
V_14 = F_8 ( V_2 , NULL ) ;
return V_14 ;
}
static struct V_16 * F_12 ( struct V_17 * V_18 )
{
return F_13 ( V_18 , struct V_16 , V_19 ) ;
}
static struct V_20 * F_14 ( T_1 V_14 )
{
struct V_20 * V_21 ;
unsigned long V_22 ;
V_21 = F_15 ( sizeof( * V_21 ) , V_23 ) ;
if ( ! V_21 )
return NULL ;
V_21 -> V_14 = V_14 ;
F_16 ( & V_24 , V_22 ) ;
F_17 ( & V_21 -> V_25 , & V_25 ) ;
F_18 ( & V_24 , V_22 ) ;
return V_21 ;
}
static struct V_20 * F_19 ( T_1 V_14 )
{
struct V_20 * V_21 ;
unsigned long V_22 ;
F_16 ( & V_24 , V_22 ) ;
F_9 (dev_data, &dev_data_list, dev_data_list) {
if ( V_21 -> V_14 == V_14 )
goto V_26;
}
V_21 = NULL ;
V_26:
F_18 ( & V_24 , V_22 ) ;
return V_21 ;
}
static int F_20 ( struct V_8 * V_9 , T_1 V_27 , void * V_28 )
{
* ( T_1 * ) V_28 = V_27 ;
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
T_1 V_14 , V_29 , V_30 ;
V_14 = F_10 ( V_2 ) ;
V_29 = V_31 [ V_14 ] ;
F_22 ( V_9 , F_20 , & V_30 ) ;
if ( V_29 == V_30 )
return V_29 ;
if ( V_29 == V_14 ) {
if ( ! V_32 [ V_30 ] ) {
V_32 [ V_30 ] =
V_32 [ V_14 ] ;
memcpy ( V_33 [ V_30 ] . V_28 ,
V_33 [ V_14 ] . V_28 ,
sizeof( V_33 [ V_30 ] . V_28 ) ) ;
}
return V_30 ;
}
F_23 ( L_1
L_2
L_3 , F_24 ( V_29 ) , F_25 ( V_29 ) ,
F_26 ( V_29 ) , F_27 ( V_2 ) , V_9 -> V_34 , V_9 -> V_1 ,
F_24 ( V_30 ) , F_25 ( V_30 ) ,
F_26 ( V_30 ) ) ;
if ( V_30 == V_14 &&
F_24 ( V_29 ) == V_9 -> V_10 -> V_11 ) {
F_28 ( V_9 , V_29 & 0xff ) ;
F_23 ( L_4 ,
F_25 ( V_29 ) , F_26 ( V_29 ) ,
F_27 ( V_2 ) ) ;
}
return V_29 ;
}
static struct V_20 * F_29 ( T_1 V_14 )
{
struct V_20 * V_21 ;
V_21 = F_19 ( V_14 ) ;
if ( V_21 == NULL )
V_21 = F_14 ( V_14 ) ;
return V_21 ;
}
static struct V_20 * F_30 ( struct V_1 * V_2 )
{
return V_2 -> V_35 . V_36 ;
}
static struct V_37 * F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_13 , * V_4 = NULL ;
int V_14 ;
V_14 = F_8 ( V_2 , & V_4 ) ;
if ( V_14 < 0 )
return F_32 ( V_14 ) ;
F_9 (p, &acpihid_map, list) {
if ( ( V_14 == V_13 -> V_14 ) && V_13 -> V_38 )
V_4 -> V_38 = V_13 -> V_38 ;
}
if ( ! V_4 -> V_38 )
V_4 -> V_38 = F_33 ( V_2 ) ;
return V_4 -> V_38 ;
}
static bool F_34 ( struct V_8 * V_9 )
{
static const int V_39 [] = {
V_40 ,
V_41 ,
V_42 ,
} ;
int V_43 , V_44 ;
for ( V_43 = 0 ; V_43 < 3 ; ++ V_43 ) {
V_44 = F_35 ( V_9 , V_39 [ V_43 ] ) ;
if ( V_44 == 0 )
return false ;
}
return true ;
}
static bool F_36 ( struct V_8 * V_9 , T_2 V_45 )
{
struct V_20 * V_21 ;
V_21 = F_30 ( & V_9 -> V_2 ) ;
return V_21 -> V_46 & ( 1 << V_45 ) ? true : false ;
}
static void F_37 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
T_3 V_51 ;
for ( V_51 = V_50 -> V_52 ; V_51 < V_50 -> V_53 ;
V_51 += V_54 ) {
if ( V_51 < V_48 -> V_55 )
F_38 ( V_51 >> V_56 ,
V_48 -> V_57 [ 0 ] -> V_58 ) ;
}
}
static void F_39 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
F_9 (e, &amd_iommu_unity_map, list) {
if ( ! ( V_14 >= V_50 -> V_59 && V_14 <= V_50 -> V_60 ) )
continue;
F_37 ( V_48 , V_50 ) ;
}
}
static bool F_40 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ! V_2 || ! V_2 -> V_61 )
return false ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return false ;
if ( V_14 > V_62 )
return false ;
if ( V_32 [ V_14 ] == NULL )
return false ;
return true ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_47 * V_63 ;
struct V_17 * V_19 ;
struct V_37 * V_38 ;
V_38 = F_42 ( V_2 ) ;
if ( F_43 ( V_38 ) )
return;
V_19 = F_44 ( V_38 ) ;
if ( ! V_19 )
goto V_64;
V_63 = F_12 ( V_19 ) -> V_65 ;
F_39 ( V_2 , V_63 ) ;
V_64:
F_45 ( V_38 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_14 ;
if ( V_2 -> V_35 . V_36 )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_21 = F_29 ( V_14 ) ;
if ( ! V_21 )
return - V_66 ;
V_21 -> V_27 = F_21 ( V_2 ) ;
if ( F_11 ( V_2 ) && F_34 ( F_6 ( V_2 ) ) ) {
struct V_67 * V_36 ;
V_36 = V_32 [ V_21 -> V_14 ] ;
V_21 -> V_68 = V_36 -> V_69 ;
}
V_2 -> V_35 . V_36 = V_21 ;
F_47 ( V_32 [ V_21 -> V_14 ] -> V_70 ,
V_2 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_1 V_27 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_27 = F_21 ( V_2 ) ;
memset ( & V_33 [ V_14 ] , 0 , sizeof( struct V_71 ) ) ;
memset ( & V_33 [ V_27 ] , 0 , sizeof( struct V_71 ) ) ;
V_32 [ V_14 ] = NULL ;
V_32 [ V_27 ] = NULL ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_14 ;
struct V_20 * V_21 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_21 = F_19 ( V_14 ) ;
if ( ! V_21 )
return;
if ( V_21 -> V_19 )
F_50 ( V_2 ) ;
F_51 ( V_32 [ V_21 -> V_14 ] -> V_70 ,
V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_35 . V_72 = NULL ;
}
static void F_53 ( T_1 V_14 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < 4 ; ++ V_43 )
F_54 ( L_5 , V_43 ,
V_33 [ V_14 ] . V_28 [ V_43 ] ) ;
}
static void F_55 ( unsigned long V_73 )
{
struct V_74 * V_75 = F_56 ( V_73 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < 4 ; ++ V_43 )
F_54 ( L_6 , V_43 , V_75 -> V_28 [ V_43 ] ) ;
}
static void F_57 ( struct V_67 * V_36 , void * V_76 )
{
int type , V_14 , V_77 , V_22 ;
volatile T_2 * V_78 = V_76 ;
int V_79 = 0 ;
T_3 V_80 ;
V_81:
type = ( V_78 [ 1 ] >> V_82 ) & V_83 ;
V_14 = ( V_78 [ 0 ] >> V_84 ) & V_85 ;
V_77 = ( V_78 [ 1 ] >> V_86 ) & V_87 ;
V_22 = ( V_78 [ 1 ] >> V_88 ) & V_89 ;
V_80 = ( T_3 ) ( ( ( T_3 ) V_78 [ 3 ] ) << 32 ) | V_78 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_79 == V_90 ) {
F_54 ( L_7 ) ;
return;
}
F_58 ( 1 ) ;
goto V_81;
}
F_59 ( V_91 L_8 ) ;
switch ( type ) {
case V_92 :
F_59 ( L_9
L_10 ,
F_24 ( V_14 ) , F_25 ( V_14 ) , F_26 ( V_14 ) ,
V_80 , V_22 ) ;
F_53 ( V_14 ) ;
break;
case V_93 :
F_59 ( L_11
L_12 ,
F_24 ( V_14 ) , F_25 ( V_14 ) , F_26 ( V_14 ) ,
V_77 , V_80 , V_22 ) ;
break;
case V_94 :
F_59 ( L_13
L_10 ,
F_24 ( V_14 ) , F_25 ( V_14 ) , F_26 ( V_14 ) ,
V_80 , V_22 ) ;
break;
case V_95 :
F_59 ( L_14
L_12 ,
F_24 ( V_14 ) , F_25 ( V_14 ) , F_26 ( V_14 ) ,
V_77 , V_80 , V_22 ) ;
break;
case V_96 :
F_59 ( L_15 , V_80 ) ;
F_55 ( V_80 ) ;
break;
case V_97 :
F_59 ( L_16
L_17 , V_80 , V_22 ) ;
break;
case V_98 :
F_59 ( L_18
L_19 ,
F_24 ( V_14 ) , F_25 ( V_14 ) , F_26 ( V_14 ) ,
V_80 ) ;
break;
case V_99 :
F_59 ( L_20
L_10 ,
F_24 ( V_14 ) , F_25 ( V_14 ) , F_26 ( V_14 ) ,
V_80 , V_22 ) ;
break;
default:
F_59 ( V_91 L_21 , type ) ;
}
memset ( V_76 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_60 ( struct V_67 * V_36 )
{
T_2 V_100 , V_101 ;
V_100 = F_61 ( V_36 -> V_102 + V_103 ) ;
V_101 = F_61 ( V_36 -> V_102 + V_104 ) ;
while ( V_100 != V_101 ) {
F_57 ( V_36 , V_36 -> V_105 + V_100 ) ;
V_100 = ( V_100 + V_106 ) % V_107 ;
}
F_62 ( V_100 , V_36 -> V_102 + V_103 ) ;
}
static void F_63 ( struct V_67 * V_36 , T_3 * V_108 )
{
struct V_109 V_110 ;
if ( F_64 ( V_108 [ 0 ] ) != V_111 ) {
F_65 ( L_22 ) ;
return;
}
V_110 . V_80 = V_108 [ 1 ] ;
V_110 . V_112 = F_66 ( V_108 [ 0 ] ) ;
V_110 . V_113 = F_67 ( V_108 [ 0 ] ) ;
V_110 . V_114 = F_68 ( V_108 [ 0 ] ) ;
V_110 . V_22 = F_69 ( V_108 [ 0 ] ) ;
F_70 ( & V_115 , 0 , & V_110 ) ;
}
static void F_71 ( struct V_67 * V_36 )
{
T_2 V_100 , V_101 ;
if ( V_36 -> V_116 == NULL )
return;
V_100 = F_61 ( V_36 -> V_102 + V_117 ) ;
V_101 = F_61 ( V_36 -> V_102 + V_118 ) ;
while ( V_100 != V_101 ) {
volatile T_3 * V_108 ;
T_3 V_4 [ 2 ] ;
int V_43 ;
V_108 = ( T_3 * ) ( V_36 -> V_116 + V_100 ) ;
for ( V_43 = 0 ; V_43 < V_90 ; ++ V_43 ) {
if ( F_64 ( V_108 [ 0 ] ) != 0 )
break;
F_58 ( 1 ) ;
}
V_4 [ 0 ] = V_108 [ 0 ] ;
V_4 [ 1 ] = V_108 [ 1 ] ;
V_108 [ 0 ] = V_108 [ 1 ] = 0UL ;
V_100 = ( V_100 + V_119 ) % V_120 ;
F_62 ( V_100 , V_36 -> V_102 + V_117 ) ;
F_63 ( V_36 , V_4 ) ;
V_100 = F_61 ( V_36 -> V_102 + V_117 ) ;
V_101 = F_61 ( V_36 -> V_102 + V_118 ) ;
}
}
T_4 F_72 ( int V_121 , void * V_28 )
{
struct V_67 * V_36 = (struct V_67 * ) V_28 ;
T_2 V_122 = F_61 ( V_36 -> V_102 + V_123 ) ;
while ( V_122 & ( V_124 | V_125 ) ) {
F_62 ( ( V_124 | V_125 ) ,
V_36 -> V_102 + V_123 ) ;
if ( V_122 & V_124 ) {
F_73 ( L_23 ) ;
F_60 ( V_36 ) ;
}
if ( V_122 & V_125 ) {
F_73 ( L_24 ) ;
F_71 ( V_36 ) ;
}
V_122 = F_61 ( V_36 -> V_102 + V_123 ) ;
}
return V_126 ;
}
T_4 F_74 ( int V_121 , void * V_28 )
{
return V_127 ;
}
static int F_75 ( volatile T_3 * V_128 )
{
int V_43 = 0 ;
while ( * V_128 == 0 && V_43 < V_90 ) {
F_58 ( 1 ) ;
V_43 += 1 ;
}
if ( V_43 == V_90 ) {
F_76 ( L_25 ) ;
return - V_129 ;
}
return 0 ;
}
static void F_77 ( struct V_67 * V_36 ,
struct V_74 * V_75 ,
T_2 V_101 )
{
T_5 * V_130 ;
V_130 = V_36 -> V_131 + V_101 ;
V_101 = ( V_101 + sizeof( * V_75 ) ) % V_132 ;
memcpy ( V_130 , V_75 , sizeof( * V_75 ) ) ;
F_62 ( V_101 , V_36 -> V_102 + V_133 ) ;
}
static void F_78 ( struct V_74 * V_75 , T_3 V_80 )
{
F_79 ( V_80 & 0x7ULL ) ;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_28 [ 0 ] = F_80 ( F_81 ( V_80 ) ) | V_134 ;
V_75 -> V_28 [ 1 ] = F_82 ( F_81 ( V_80 ) ) ;
V_75 -> V_28 [ 2 ] = 1 ;
F_83 ( V_75 , V_135 ) ;
}
static void F_84 ( struct V_74 * V_75 , T_1 V_14 )
{
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_28 [ 0 ] = V_14 ;
F_83 ( V_75 , V_136 ) ;
}
static void F_85 ( struct V_74 * V_75 , T_3 V_80 ,
T_6 V_137 , T_1 V_77 , int V_138 )
{
T_3 V_139 ;
bool V_140 ;
V_139 = F_86 ( V_80 , V_137 , V_54 ) ;
V_140 = false ;
if ( V_139 > 1 ) {
V_80 = V_141 ;
V_140 = true ;
}
V_80 &= V_142 ;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_28 [ 1 ] |= V_77 ;
V_75 -> V_28 [ 2 ] = F_80 ( V_80 ) ;
V_75 -> V_28 [ 3 ] = F_82 ( V_80 ) ;
F_83 ( V_75 , V_143 ) ;
if ( V_140 )
V_75 -> V_28 [ 2 ] |= V_144 ;
if ( V_138 )
V_75 -> V_28 [ 2 ] |= V_145 ;
}
static void F_87 ( struct V_74 * V_75 , T_1 V_14 , int V_146 ,
T_3 V_80 , T_6 V_137 )
{
T_3 V_139 ;
bool V_140 ;
V_139 = F_86 ( V_80 , V_137 , V_54 ) ;
V_140 = false ;
if ( V_139 > 1 ) {
V_80 = V_141 ;
V_140 = true ;
}
V_80 &= V_142 ;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_28 [ 0 ] = V_14 ;
V_75 -> V_28 [ 0 ] |= ( V_146 & 0xff ) << 24 ;
V_75 -> V_28 [ 1 ] = V_14 ;
V_75 -> V_28 [ 2 ] = F_80 ( V_80 ) ;
V_75 -> V_28 [ 3 ] = F_82 ( V_80 ) ;
F_83 ( V_75 , V_147 ) ;
if ( V_140 )
V_75 -> V_28 [ 2 ] |= V_144 ;
}
static void F_88 ( struct V_74 * V_75 , T_1 V_77 , int V_112 ,
T_3 V_80 , bool V_137 )
{
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_80 &= ~ ( 0xfffULL ) ;
V_75 -> V_28 [ 0 ] = V_112 ;
V_75 -> V_28 [ 1 ] = V_77 ;
V_75 -> V_28 [ 2 ] = F_80 ( V_80 ) ;
V_75 -> V_28 [ 3 ] = F_82 ( V_80 ) ;
V_75 -> V_28 [ 2 ] |= V_145 ;
V_75 -> V_28 [ 2 ] |= V_148 ;
if ( V_137 )
V_75 -> V_28 [ 2 ] |= V_144 ;
F_83 ( V_75 , V_143 ) ;
}
static void F_89 ( struct V_74 * V_75 , T_1 V_14 , int V_112 ,
int V_146 , T_3 V_80 , bool V_137 )
{
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_80 &= ~ ( 0xfffULL ) ;
V_75 -> V_28 [ 0 ] = V_14 ;
V_75 -> V_28 [ 0 ] |= ( ( V_112 >> 8 ) & 0xff ) << 16 ;
V_75 -> V_28 [ 0 ] |= ( V_146 & 0xff ) << 24 ;
V_75 -> V_28 [ 1 ] = V_14 ;
V_75 -> V_28 [ 1 ] |= ( V_112 & 0xff ) << 16 ;
V_75 -> V_28 [ 2 ] = F_80 ( V_80 ) ;
V_75 -> V_28 [ 2 ] |= V_148 ;
V_75 -> V_28 [ 3 ] = F_82 ( V_80 ) ;
if ( V_137 )
V_75 -> V_28 [ 2 ] |= V_144 ;
F_83 ( V_75 , V_147 ) ;
}
static void F_90 ( struct V_74 * V_75 , T_1 V_14 , int V_112 ,
int V_122 , int V_114 , bool V_149 )
{
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_28 [ 0 ] = V_14 ;
if ( V_149 ) {
V_75 -> V_28 [ 1 ] = V_112 ;
V_75 -> V_28 [ 2 ] = V_148 ;
}
V_75 -> V_28 [ 3 ] = V_114 & 0x1ff ;
V_75 -> V_28 [ 3 ] |= ( V_122 & V_150 ) << V_151 ;
F_83 ( V_75 , V_152 ) ;
}
static void F_91 ( struct V_74 * V_75 )
{
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
F_83 ( V_75 , V_153 ) ;
}
static void F_92 ( struct V_74 * V_75 , T_1 V_14 )
{
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_28 [ 0 ] = V_14 ;
F_83 ( V_75 , V_154 ) ;
}
static int F_93 ( struct V_67 * V_36 ,
struct V_74 * V_75 ,
bool V_155 )
{
T_2 V_156 , V_101 , V_100 , V_157 ;
unsigned long V_22 ;
V_158:
F_16 ( & V_36 -> V_159 , V_22 ) ;
V_100 = F_61 ( V_36 -> V_102 + V_160 ) ;
V_101 = F_61 ( V_36 -> V_102 + V_133 ) ;
V_157 = ( V_101 + sizeof( * V_75 ) ) % V_132 ;
V_156 = ( V_100 - V_157 ) % V_132 ;
if ( V_156 <= 2 ) {
struct V_74 V_161 ;
volatile T_3 V_128 = 0 ;
int V_162 ;
F_78 ( & V_161 , ( T_3 ) & V_128 ) ;
F_77 ( V_36 , & V_161 , V_101 ) ;
F_18 ( & V_36 -> V_159 , V_22 ) ;
if ( ( V_162 = F_75 ( & V_128 ) ) != 0 )
return V_162 ;
goto V_158;
}
F_77 ( V_36 , V_75 , V_101 ) ;
V_36 -> V_163 = V_155 ;
F_18 ( & V_36 -> V_159 , V_22 ) ;
return 0 ;
}
static int F_94 ( struct V_67 * V_36 , struct V_74 * V_75 )
{
return F_93 ( V_36 , V_75 , true ) ;
}
static int F_95 ( struct V_67 * V_36 )
{
struct V_74 V_75 ;
volatile T_3 V_128 = 0 ;
int V_162 ;
if ( ! V_36 -> V_163 )
return 0 ;
F_78 ( & V_75 , ( T_3 ) & V_128 ) ;
V_162 = F_93 ( V_36 , & V_75 , false ) ;
if ( V_162 )
return V_162 ;
return F_75 ( & V_128 ) ;
}
static int F_96 ( struct V_67 * V_36 , T_1 V_14 )
{
struct V_74 V_75 ;
F_84 ( & V_75 , V_14 ) ;
return F_94 ( V_36 , & V_75 ) ;
}
static void F_97 ( struct V_67 * V_36 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= 0xffff ; ++ V_14 )
F_96 ( V_36 , V_14 ) ;
F_95 ( V_36 ) ;
}
static void F_98 ( struct V_67 * V_36 )
{
T_2 V_164 ;
for ( V_164 = 0 ; V_164 <= 0xffff ; ++ V_164 ) {
struct V_74 V_75 ;
F_85 ( & V_75 , 0 , V_141 ,
V_164 , 1 ) ;
F_94 ( V_36 , & V_75 ) ;
}
F_95 ( V_36 ) ;
}
static void F_99 ( struct V_67 * V_36 )
{
struct V_74 V_75 ;
F_91 ( & V_75 ) ;
F_94 ( V_36 , & V_75 ) ;
F_95 ( V_36 ) ;
}
static void F_100 ( struct V_67 * V_36 , T_1 V_14 )
{
struct V_74 V_75 ;
F_92 ( & V_75 , V_14 ) ;
F_94 ( V_36 , & V_75 ) ;
}
static void F_101 ( struct V_67 * V_36 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= V_165 ; V_14 ++ )
F_100 ( V_36 , V_14 ) ;
F_95 ( V_36 ) ;
}
void F_102 ( struct V_67 * V_36 )
{
if ( F_103 ( V_36 , V_166 ) ) {
F_99 ( V_36 ) ;
} else {
F_97 ( V_36 ) ;
F_101 ( V_36 ) ;
F_98 ( V_36 ) ;
}
}
static int F_104 ( struct V_20 * V_21 ,
T_3 V_80 , T_6 V_137 )
{
struct V_67 * V_36 ;
struct V_74 V_75 ;
int V_146 ;
V_146 = V_21 -> V_167 . V_146 ;
V_36 = V_32 [ V_21 -> V_14 ] ;
F_87 ( & V_75 , V_21 -> V_14 , V_146 , V_80 , V_137 ) ;
return F_94 ( V_36 , & V_75 ) ;
}
static int F_105 ( struct V_20 * V_21 )
{
struct V_67 * V_36 ;
T_1 V_27 ;
int V_162 ;
V_36 = V_32 [ V_21 -> V_14 ] ;
V_27 = V_21 -> V_27 ;
V_162 = F_96 ( V_36 , V_21 -> V_14 ) ;
if ( ! V_162 && V_27 != V_21 -> V_14 )
V_162 = F_96 ( V_36 , V_27 ) ;
if ( V_162 )
return V_162 ;
if ( V_21 -> V_167 . V_168 )
V_162 = F_104 ( V_21 , 0 , ~ 0UL ) ;
return V_162 ;
}
static void F_106 ( struct V_16 * V_19 ,
T_3 V_80 , T_6 V_137 , int V_138 )
{
struct V_20 * V_21 ;
struct V_74 V_75 ;
int V_162 = 0 , V_43 ;
F_85 ( & V_75 , V_80 , V_137 , V_19 -> V_169 , V_138 ) ;
for ( V_43 = 0 ; V_43 < V_170 ; ++ V_43 ) {
if ( ! V_19 -> V_171 [ V_43 ] )
continue;
V_162 |= F_94 ( V_172 [ V_43 ] , & V_75 ) ;
}
F_9 (dev_data, &domain->dev_list, list) {
if ( ! V_21 -> V_167 . V_168 )
continue;
V_162 |= F_104 ( V_21 , V_80 , V_137 ) ;
}
F_79 ( V_162 ) ;
}
static void F_107 ( struct V_16 * V_19 ,
T_3 V_80 , T_6 V_137 )
{
F_106 ( V_19 , V_80 , V_137 , 0 ) ;
}
static void F_108 ( struct V_16 * V_19 )
{
F_106 ( V_19 , 0 , V_141 , 0 ) ;
}
static void F_109 ( struct V_16 * V_19 )
{
F_106 ( V_19 , 0 , V_141 , 1 ) ;
}
static void F_110 ( struct V_16 * V_19 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_170 ; ++ V_43 ) {
if ( ! V_19 -> V_171 [ V_43 ] )
continue;
F_95 ( V_172 [ V_43 ] ) ;
}
}
static void F_111 ( struct V_16 * V_19 )
{
struct V_20 * V_21 ;
F_9 (dev_data, &domain->dev_list, list)
F_105 ( V_21 ) ;
}
static bool F_112 ( struct V_16 * V_19 ,
T_7 V_173 )
{
T_3 * V_174 ;
if ( V_19 -> V_175 == V_176 )
return false ;
V_174 = ( void * ) F_113 ( V_173 ) ;
if ( ! V_174 )
return false ;
* V_174 = F_114 ( V_19 -> V_175 ,
F_115 ( V_19 -> V_177 ) ) ;
V_19 -> V_177 = V_174 ;
V_19 -> V_175 += 1 ;
V_19 -> V_178 = true ;
return true ;
}
static T_3 * F_116 ( struct V_16 * V_19 ,
unsigned long V_80 ,
unsigned long V_179 ,
T_3 * * V_180 ,
T_7 V_173 )
{
int V_181 , V_182 ;
T_3 * V_174 , * V_183 ;
F_117 ( ! F_118 ( V_179 ) ) ;
while ( V_80 > F_119 ( V_19 -> V_175 ) )
F_112 ( V_19 , V_173 ) ;
V_181 = V_19 -> V_175 - 1 ;
V_174 = & V_19 -> V_177 [ F_120 ( V_181 , V_80 ) ] ;
V_80 = F_121 ( V_80 , V_179 ) ;
V_182 = F_122 ( V_179 ) ;
while ( V_181 > V_182 ) {
T_3 V_184 , V_185 ;
V_184 = * V_174 ;
if ( ! F_123 ( V_184 ) ) {
V_183 = ( T_3 * ) F_113 ( V_173 ) ;
if ( ! V_183 )
return NULL ;
V_185 = F_114 ( V_181 , F_115 ( V_183 ) ) ;
if ( F_124 ( V_174 , V_184 , V_185 ) ) {
F_125 ( ( unsigned long ) V_183 ) ;
continue;
}
}
if ( F_126 ( * V_174 ) != V_181 )
return NULL ;
V_181 -= 1 ;
V_174 = F_127 ( * V_174 ) ;
if ( V_180 && V_181 == V_182 )
* V_180 = V_174 ;
V_174 = & V_174 [ F_120 ( V_181 , V_80 ) ] ;
}
return V_174 ;
}
static T_3 * F_128 ( struct V_16 * V_19 ,
unsigned long V_80 ,
unsigned long * V_179 )
{
int V_181 ;
T_3 * V_174 ;
if ( V_80 > F_119 ( V_19 -> V_175 ) )
return NULL ;
V_181 = V_19 -> V_175 - 1 ;
V_174 = & V_19 -> V_177 [ F_120 ( V_181 , V_80 ) ] ;
* V_179 = F_129 ( V_181 ) ;
while ( V_181 > 0 ) {
if ( ! F_123 ( * V_174 ) )
return NULL ;
if ( F_126 ( * V_174 ) == 7 ||
F_126 ( * V_174 ) == 0 )
break;
if ( F_126 ( * V_174 ) != V_181 )
return NULL ;
V_181 -= 1 ;
V_174 = F_127 ( * V_174 ) ;
V_174 = & V_174 [ F_120 ( V_181 , V_80 ) ] ;
* V_179 = F_129 ( V_181 ) ;
}
if ( F_126 ( * V_174 ) == 0x07 ) {
unsigned long V_186 ;
* V_179 = V_186 = F_130 ( * V_174 ) ;
V_186 = ~ ( ( F_131 ( V_186 ) << 3 ) - 1 ) ;
V_174 = ( T_3 * ) ( ( ( unsigned long ) V_174 ) & V_186 ) ;
}
return V_174 ;
}
static int F_132 ( struct V_16 * V_18 ,
unsigned long V_187 ,
unsigned long V_73 ,
int V_188 ,
unsigned long V_179 )
{
T_3 V_184 , * V_174 ;
int V_43 , V_79 ;
F_117 ( ! F_133 ( V_187 , V_179 ) ) ;
F_117 ( ! F_133 ( V_73 , V_179 ) ) ;
if ( ! ( V_188 & V_189 ) )
return - V_15 ;
V_79 = F_131 ( V_179 ) ;
V_174 = F_116 ( V_18 , V_187 , V_179 , NULL , V_23 ) ;
if ( ! V_174 )
return - V_66 ;
for ( V_43 = 0 ; V_43 < V_79 ; ++ V_43 )
if ( F_123 ( V_174 [ V_43 ] ) )
return - V_190 ;
if ( V_79 > 1 ) {
V_184 = F_134 ( V_73 , V_179 ) ;
V_184 |= F_135 ( 7 ) | V_191 | V_192 ;
} else
V_184 = V_73 | V_191 | V_192 ;
if ( V_188 & V_193 )
V_184 |= V_194 ;
if ( V_188 & V_195 )
V_184 |= V_196 ;
for ( V_43 = 0 ; V_43 < V_79 ; ++ V_43 )
V_174 [ V_43 ] = V_184 ;
F_136 ( V_18 ) ;
return 0 ;
}
static unsigned long F_137 ( struct V_16 * V_18 ,
unsigned long V_187 ,
unsigned long V_179 )
{
unsigned long long V_197 ;
unsigned long V_198 ;
T_3 * V_174 ;
F_117 ( ! F_118 ( V_179 ) ) ;
V_197 = 0 ;
while ( V_197 < V_179 ) {
V_174 = F_128 ( V_18 , V_187 , & V_198 ) ;
if ( V_174 ) {
int V_43 , V_79 ;
V_79 = F_131 ( V_198 ) ;
for ( V_43 = 0 ; V_43 < V_79 ; V_43 ++ )
V_174 [ V_43 ] = 0ULL ;
}
V_187 = ( V_187 & ~ ( V_198 - 1 ) ) + V_198 ;
V_197 += V_198 ;
}
F_117 ( V_197 && ! F_118 ( V_197 ) ) ;
return V_197 ;
}
static void F_138 ( struct V_47 * V_18 ,
unsigned long V_199 ,
unsigned int V_139 )
{
unsigned int V_43 , V_200 = V_18 -> V_55 >> V_56 ;
if ( V_199 + V_139 > V_200 )
V_139 = V_200 - V_199 ;
for ( V_43 = V_199 ; V_43 < V_199 + V_139 ; ++ V_43 ) {
int V_201 = V_43 / V_202 ;
int V_183 = V_43 % V_202 ;
F_38 ( V_183 , V_18 -> V_57 [ V_201 ] -> V_58 ) ;
}
}
static int F_139 ( struct V_47 * V_48 ,
bool V_203 , T_7 V_173 )
{
int V_201 = V_48 -> V_55 >> V_204 ;
unsigned long V_43 , V_205 , V_206 ;
struct V_207 * V_208 ;
struct V_67 * V_36 ;
unsigned long V_22 ;
#ifdef F_140
V_203 = false ;
#endif
if ( V_201 >= V_209 )
return - V_66 ;
V_208 = F_15 ( sizeof( struct V_207 ) , V_173 ) ;
if ( ! V_208 )
return - V_66 ;
V_208 -> V_58 = ( void * ) F_113 ( V_173 ) ;
if ( ! V_208 -> V_58 )
goto V_210;
V_208 -> V_211 = V_48 -> V_55 ;
F_141 ( & V_208 -> V_212 ) ;
if ( V_203 ) {
unsigned long V_80 = V_48 -> V_55 ;
int V_43 , V_213 = V_202 / 512 ;
T_3 * V_174 , * V_180 ;
for ( V_43 = 0 ; V_43 < V_213 ; ++ V_43 ) {
V_174 = F_116 ( & V_48 -> V_19 , V_80 , V_54 ,
& V_180 , V_173 ) ;
if ( ! V_174 )
goto V_210;
V_208 -> V_214 [ V_43 ] = V_180 ;
V_80 += V_215 / 64 ;
}
}
F_16 ( & V_48 -> V_19 . V_159 , V_22 ) ;
F_142 ( & V_208 -> V_212 ) ;
V_205 = V_48 -> V_55 ;
V_48 -> V_57 [ V_201 ] = V_208 ;
V_48 -> V_55 += V_215 ;
if ( V_205 < V_216 &&
V_48 -> V_55 > V_216 ) {
unsigned long V_217 ;
int V_139 ;
V_139 = F_86 ( V_216 , 0x10000 , V_54 ) ;
V_217 = V_216 >> V_56 ;
F_138 ( V_48 , V_217 , V_139 ) ;
}
F_143 (iommu) {
if ( V_36 -> V_218 &&
V_36 -> V_218 >= V_48 -> V_57 [ V_201 ] -> V_211
&& V_36 -> V_218 < V_48 -> V_55 ) {
unsigned long V_219 ;
int V_139 = F_86 ( V_36 -> V_218 ,
V_36 -> V_220 ,
V_54 ) ;
V_219 = V_36 -> V_218 >> V_56 ;
F_138 ( V_48 , V_219 , V_139 ) ;
}
}
for ( V_43 = V_48 -> V_57 [ V_201 ] -> V_211 ;
V_43 < V_48 -> V_55 ;
V_43 += V_206 ) {
T_3 * V_174 = F_128 ( & V_48 -> V_19 , V_43 , & V_206 ) ;
if ( ! V_174 || ! F_123 ( * V_174 ) )
continue;
F_138 ( V_48 , V_43 >> V_56 ,
V_206 >> 12 ) ;
}
F_136 ( & V_48 -> V_19 ) ;
F_144 ( & V_208 -> V_212 ) ;
F_18 ( & V_48 -> V_19 . V_159 , V_22 ) ;
return 0 ;
V_210:
F_136 ( & V_48 -> V_19 ) ;
F_125 ( ( unsigned long ) V_208 -> V_58 ) ;
F_145 ( V_208 ) ;
return - V_66 ;
}
static T_8 F_146 ( struct V_47 * V_18 ,
struct V_207 * V_208 ,
unsigned long V_139 ,
unsigned long V_61 ,
unsigned long V_221 ,
unsigned long V_222 ,
bool V_223 )
{
unsigned long V_211 , V_224 , V_22 ;
T_8 V_80 ;
bool V_225 = false ;
V_211 = V_208 -> V_211 >> V_56 ;
V_224 = F_147 ( V_202 , V_211 ,
V_61 >> V_56 ) ;
if ( V_223 ) {
if ( ! F_148 ( & V_208 -> V_212 , V_22 ) )
return - 1 ;
} else {
F_16 ( & V_208 -> V_212 , V_22 ) ;
}
V_80 = F_149 ( V_208 -> V_58 , V_224 , V_208 -> V_226 ,
V_139 , V_211 , V_221 , V_222 ) ;
if ( V_80 == - 1 ) {
V_80 = F_149 ( V_208 -> V_58 , V_224 ,
0 , V_139 , V_211 , V_221 ,
V_222 ) ;
V_225 = true ;
}
if ( V_80 != - 1 )
V_208 -> V_226 = V_80 + V_139 ;
F_18 ( & V_208 -> V_212 , V_22 ) ;
if ( V_225 ) {
F_108 ( & V_18 -> V_19 ) ;
F_110 ( & V_18 -> V_19 ) ;
}
return V_80 ;
}
static unsigned long F_150 ( struct V_1 * V_2 ,
struct V_47 * V_18 ,
unsigned int V_139 ,
unsigned long V_222 ,
T_3 V_61 )
{
unsigned long V_221 , V_227 ;
unsigned long V_80 = - 1 ;
bool V_228 = true ;
T_2 V_229 , V_43 ;
F_151 () ;
V_227 = F_152 ( V_2 ) ;
V_158:
V_229 = F_153 ( * V_18 -> V_230 ) ;
if ( F_154 ( V_229 > V_209 ) ) {
V_229 = 0 ;
F_155 ( * V_18 -> V_230 , 0 ) ;
}
V_221 = V_227 + 1 ? F_156 ( V_227 + 1 , V_54 ) >> V_56 :
1UL << ( V_231 - V_56 ) ;
for ( V_43 = 0 ; V_43 < V_209 ; ++ V_43 ) {
struct V_207 * V_208 ;
int V_201 ;
V_201 = ( V_229 + V_43 ) % V_209 ;
V_208 = V_18 -> V_57 [ V_201 ] ;
if ( ! V_208 || V_208 -> V_211 >= V_61 )
continue;
V_80 = F_146 ( V_18 , V_208 , V_139 ,
V_61 , V_221 ,
V_222 , V_228 ) ;
if ( V_80 != - 1 ) {
V_80 = V_208 -> V_211 + ( V_80 << V_56 ) ;
F_155 ( * V_18 -> V_230 , V_201 ) ;
break;
}
}
if ( V_80 == - 1 && V_228 ) {
V_228 = false ;
goto V_158;
}
F_157 () ;
return V_80 ;
}
static unsigned long F_158 ( struct V_1 * V_2 ,
struct V_47 * V_18 ,
unsigned int V_139 ,
unsigned long V_222 ,
T_3 V_61 )
{
unsigned long V_80 = - 1 ;
while ( V_80 == - 1 ) {
V_80 = F_150 ( V_2 , V_18 , V_139 ,
V_222 , V_61 ) ;
if ( V_80 == - 1 && F_139 ( V_18 , false , V_232 ) )
break;
}
if ( F_154 ( V_80 == - 1 ) )
V_80 = V_233 ;
F_79 ( ( V_80 + ( V_54 * V_139 ) ) > V_18 -> V_55 ) ;
return V_80 ;
}
static void F_159 ( struct V_47 * V_18 ,
unsigned long V_80 ,
unsigned int V_139 )
{
unsigned V_43 = V_80 >> V_204 ;
struct V_207 * V_208 = V_18 -> V_57 [ V_43 ] ;
unsigned long V_22 ;
F_117 ( V_43 >= V_209 || V_208 == NULL ) ;
#ifdef F_140
if ( V_43 < 4 )
return;
#endif
if ( V_234 ) {
F_108 ( & V_18 -> V_19 ) ;
F_110 ( & V_18 -> V_19 ) ;
}
V_80 = ( V_80 % V_215 ) >> V_56 ;
F_16 ( & V_208 -> V_212 , V_22 ) ;
if ( V_80 + V_139 > V_208 -> V_226 )
V_208 -> V_226 = V_80 + V_139 ;
F_160 ( V_208 -> V_58 , V_80 , V_139 ) ;
F_18 ( & V_208 -> V_212 , V_22 ) ;
}
static void F_161 ( struct V_16 * V_19 )
{
unsigned long V_22 ;
F_16 ( & V_235 , V_22 ) ;
F_162 ( & V_19 -> V_236 , & V_237 ) ;
F_18 ( & V_235 , V_22 ) ;
}
static void F_163 ( struct V_16 * V_19 )
{
unsigned long V_22 ;
F_16 ( & V_235 , V_22 ) ;
F_164 ( & V_19 -> V_236 ) ;
F_18 ( & V_235 , V_22 ) ;
}
static T_1 F_165 ( void )
{
unsigned long V_22 ;
int V_169 ;
F_166 ( & V_238 , V_22 ) ;
V_169 = F_167 ( V_239 , V_240 ) ;
F_117 ( V_169 == 0 ) ;
if ( V_169 > 0 && V_169 < V_240 )
F_38 ( V_169 , V_239 ) ;
else
V_169 = 0 ;
F_168 ( & V_238 , V_22 ) ;
return V_169 ;
}
static void F_169 ( int V_169 )
{
unsigned long V_22 ;
F_166 ( & V_238 , V_22 ) ;
if ( V_169 > 0 && V_169 < V_240 )
F_170 ( V_169 , V_239 ) ;
F_168 ( & V_238 , V_22 ) ;
}
static void F_171 ( struct V_16 * V_19 )
{
unsigned long V_241 = ( unsigned long ) V_19 -> V_177 ;
switch ( V_19 -> V_175 ) {
case V_242 :
break;
case V_243 :
F_125 ( V_241 ) ;
break;
case V_244 :
F_172 ( V_241 ) ;
break;
case V_245 :
F_173 ( V_241 ) ;
break;
case V_246 :
F_174 ( V_241 ) ;
break;
case V_247 :
F_175 ( V_241 ) ;
break;
case V_176 :
F_176 ( V_241 ) ;
break;
default:
F_177 () ;
}
}
static void F_178 ( T_3 * V_248 )
{
T_3 * V_249 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < 512 ; ++ V_43 ) {
if ( ! ( V_248 [ V_43 ] & V_250 ) )
continue;
V_249 = F_179 ( V_248 [ V_43 ] & V_142 ) ;
F_125 ( ( unsigned long ) V_249 ) ;
}
}
static void F_180 ( T_3 * V_248 )
{
T_3 * V_249 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < 512 ; ++ V_43 ) {
if ( ! ( V_248 [ V_43 ] & V_250 ) )
continue;
V_249 = F_179 ( V_248 [ V_43 ] & V_142 ) ;
F_178 ( V_249 ) ;
}
}
static void F_181 ( struct V_16 * V_19 )
{
if ( V_19 -> V_251 == 2 )
F_180 ( V_19 -> V_252 ) ;
else if ( V_19 -> V_251 == 1 )
F_178 ( V_19 -> V_252 ) ;
else
F_117 ( V_19 -> V_251 != 0 ) ;
F_125 ( ( unsigned long ) V_19 -> V_252 ) ;
}
static void F_182 ( struct V_47 * V_18 )
{
int V_43 ;
if ( ! V_18 )
return;
F_183 ( V_18 -> V_230 ) ;
F_163 ( & V_18 -> V_19 ) ;
F_171 ( & V_18 -> V_19 ) ;
for ( V_43 = 0 ; V_43 < V_209 ; ++ V_43 ) {
if ( ! V_18 -> V_57 [ V_43 ] )
continue;
F_125 ( ( unsigned long ) V_18 -> V_57 [ V_43 ] -> V_58 ) ;
F_145 ( V_18 -> V_57 [ V_43 ] ) ;
}
F_145 ( V_18 ) ;
}
static int F_184 ( struct V_47 * V_48 ,
int V_253 )
{
int V_162 , V_43 , V_254 ;
V_254 = V_48 -> V_55 >> V_204 ;
V_162 = 0 ;
for ( V_43 = V_254 ; V_43 < V_253 ; ++ V_43 ) {
V_162 = F_139 ( V_48 , false , V_23 ) ;
if ( V_162 )
break;
}
return V_162 ;
}
static struct V_47 * F_185 ( void )
{
struct V_47 * V_48 ;
int V_255 ;
V_48 = F_15 ( sizeof( struct V_47 ) , V_23 ) ;
if ( ! V_48 )
return NULL ;
if ( F_186 ( & V_48 -> V_19 ) )
goto V_256;
V_48 -> V_230 = F_187 ( T_2 ) ;
if ( ! V_48 -> V_230 )
goto V_256;
V_48 -> V_19 . V_175 = V_244 ;
V_48 -> V_19 . V_177 = ( void * ) F_113 ( V_23 ) ;
V_48 -> V_19 . V_22 = V_257 ;
V_48 -> V_19 . V_65 = V_48 ;
if ( ! V_48 -> V_19 . V_177 )
goto V_256;
F_161 ( & V_48 -> V_19 ) ;
if ( F_139 ( V_48 , true , V_23 ) )
goto V_256;
V_48 -> V_57 [ 0 ] -> V_58 [ 0 ] = 1 ;
F_188 ( V_255 )
* F_189 ( V_48 -> V_230 , V_255 ) = 0 ;
return V_48 ;
V_256:
F_182 ( V_48 ) ;
return NULL ;
}
static bool V_47 ( struct V_16 * V_19 )
{
return V_19 -> V_22 & V_257 ;
}
static void F_190 ( T_1 V_14 , struct V_16 * V_19 , bool V_167 )
{
T_3 V_258 = 0 ;
T_3 V_22 = 0 ;
if ( V_19 -> V_175 != V_242 )
V_258 = F_115 ( V_19 -> V_177 ) ;
V_258 |= ( V_19 -> V_175 & V_259 )
<< V_260 ;
V_258 |= V_194 | V_196 | V_191 | V_261 ;
V_22 = V_33 [ V_14 ] . V_28 [ 1 ] ;
if ( V_167 )
V_22 |= V_262 ;
if ( V_19 -> V_22 & V_263 ) {
T_3 V_264 = F_81 ( V_19 -> V_252 ) ;
T_3 V_251 = V_19 -> V_251 ;
T_3 V_265 ;
V_258 |= V_266 ;
V_258 |= ( V_251 & V_267 ) << V_268 ;
V_265 = F_191 ( ~ 0ULL ) << V_269 ;
V_22 &= ~ V_265 ;
V_265 = F_192 ( ~ 0ULL ) << V_270 ;
V_22 &= ~ V_265 ;
V_265 = F_193 ( V_264 ) << V_271 ;
V_258 |= V_265 ;
V_265 = F_191 ( V_264 ) << V_269 ;
V_22 |= V_265 ;
V_265 = F_192 ( V_264 ) << V_270 ;
V_22 |= V_265 ;
}
V_22 &= ~ ( 0xffffUL ) ;
V_22 |= V_19 -> V_169 ;
V_33 [ V_14 ] . V_28 [ 1 ] = V_22 ;
V_33 [ V_14 ] . V_28 [ 0 ] = V_258 ;
}
static void F_194 ( T_1 V_14 )
{
V_33 [ V_14 ] . V_28 [ 0 ] = V_191 | V_261 ;
V_33 [ V_14 ] . V_28 [ 1 ] &= V_272 ;
F_195 ( V_14 ) ;
}
static void F_196 ( struct V_20 * V_21 ,
struct V_16 * V_19 )
{
struct V_67 * V_36 ;
T_1 V_27 ;
bool V_167 ;
V_36 = V_32 [ V_21 -> V_14 ] ;
V_27 = V_21 -> V_27 ;
V_167 = V_21 -> V_167 . V_168 ;
V_21 -> V_19 = V_19 ;
F_162 ( & V_21 -> V_236 , & V_19 -> V_273 ) ;
V_19 -> V_171 [ V_36 -> V_201 ] += 1 ;
V_19 -> V_274 += 1 ;
F_190 ( V_21 -> V_14 , V_19 , V_167 ) ;
if ( V_27 != V_21 -> V_14 )
F_190 ( V_27 , V_19 , V_167 ) ;
F_105 ( V_21 ) ;
}
static void F_197 ( struct V_20 * V_21 )
{
struct V_67 * V_36 ;
T_1 V_27 ;
if ( ! V_21 -> V_19 )
return;
V_36 = V_32 [ V_21 -> V_14 ] ;
V_27 = V_21 -> V_27 ;
V_21 -> V_19 -> V_171 [ V_36 -> V_201 ] -= 1 ;
V_21 -> V_19 -> V_274 -= 1 ;
V_21 -> V_19 = NULL ;
F_164 ( & V_21 -> V_236 ) ;
F_194 ( V_21 -> V_14 ) ;
if ( V_27 != V_21 -> V_14 )
F_194 ( V_27 ) ;
F_105 ( V_21 ) ;
}
static int F_198 ( struct V_20 * V_21 ,
struct V_16 * V_19 )
{
int V_162 ;
F_79 ( ! F_199 () ) ;
F_142 ( & V_19 -> V_159 ) ;
V_162 = - V_190 ;
if ( V_21 -> V_19 != NULL )
goto V_26;
F_196 ( V_21 , V_19 ) ;
V_162 = 0 ;
V_26:
F_144 ( & V_19 -> V_159 ) ;
return V_162 ;
}
static void F_200 ( struct V_8 * V_9 )
{
F_201 ( V_9 ) ;
F_202 ( V_9 ) ;
F_203 ( V_9 ) ;
}
static int F_204 ( struct V_8 * V_9 )
{
T_1 V_275 ;
int V_44 ;
V_44 = F_35 ( V_9 , V_41 ) ;
if ( ! V_44 )
return - V_15 ;
F_205 ( V_9 , V_44 + V_276 , & V_275 ) ;
V_275 |= V_277 ;
F_206 ( V_9 , V_44 + V_276 , V_275 ) ;
return 0 ;
}
static int F_207 ( struct V_8 * V_9 )
{
bool V_278 ;
int V_279 , V_162 ;
V_279 = 32 ;
if ( F_36 ( V_9 , V_280 ) )
V_279 = 1 ;
V_278 = F_36 ( V_9 , V_281 ) ;
V_162 = F_208 ( V_9 , 0 ) ;
if ( V_162 )
goto V_282;
V_162 = F_209 ( V_9 ) ;
if ( V_162 )
goto V_282;
V_162 = F_210 ( V_9 , V_279 ) ;
if ( V_162 )
goto V_282;
if ( V_278 ) {
V_162 = F_204 ( V_9 ) ;
if ( V_162 )
goto V_282;
}
V_162 = F_211 ( V_9 , V_56 ) ;
if ( V_162 )
goto V_282;
return 0 ;
V_282:
F_202 ( V_9 ) ;
F_203 ( V_9 ) ;
return V_162 ;
}
static bool F_212 ( struct V_8 * V_9 )
{
T_1 V_122 ;
int V_44 ;
V_44 = F_35 ( V_9 , V_41 ) ;
if ( ! V_44 )
return false ;
F_205 ( V_9 , V_44 + V_283 , & V_122 ) ;
return ( V_122 & V_284 ) ? true : false ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_16 * V_19 )
{
struct V_8 * V_9 ;
struct V_20 * V_21 ;
unsigned long V_22 ;
int V_162 ;
V_21 = F_30 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
goto V_285;
V_9 = F_6 ( V_2 ) ;
if ( V_19 -> V_22 & V_263 ) {
if ( ! V_21 -> V_286 )
return - V_15 ;
if ( V_21 -> V_68 ) {
if ( F_207 ( V_9 ) != 0 )
return - V_15 ;
V_21 -> V_167 . V_168 = true ;
V_21 -> V_167 . V_146 = F_214 ( V_9 ) ;
V_21 -> V_287 = F_212 ( V_9 ) ;
}
} else if ( V_288 &&
F_211 ( V_9 , V_56 ) == 0 ) {
V_21 -> V_167 . V_168 = true ;
V_21 -> V_167 . V_146 = F_214 ( V_9 ) ;
}
V_285:
F_166 ( & V_238 , V_22 ) ;
V_162 = F_198 ( V_21 , V_19 ) ;
F_168 ( & V_238 , V_22 ) ;
F_109 ( V_19 ) ;
return V_162 ;
}
static void F_215 ( struct V_20 * V_21 )
{
struct V_16 * V_19 ;
F_79 ( ! F_199 () ) ;
if ( F_79 ( ! V_21 -> V_19 ) )
return;
V_19 = V_21 -> V_19 ;
F_142 ( & V_19 -> V_159 ) ;
F_197 ( V_21 ) ;
F_144 ( & V_19 -> V_159 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
struct V_20 * V_21 ;
unsigned long V_22 ;
V_21 = F_30 ( V_2 ) ;
V_19 = V_21 -> V_19 ;
F_166 ( & V_238 , V_22 ) ;
F_215 ( V_21 ) ;
F_168 ( & V_238 , V_22 ) ;
if ( ! F_11 ( V_2 ) )
return;
if ( V_19 -> V_22 & V_263 && V_21 -> V_68 )
F_200 ( F_6 ( V_2 ) ) ;
else if ( V_21 -> V_167 . V_168 )
F_201 ( F_6 ( V_2 ) ) ;
V_21 -> V_167 . V_168 = false ;
}
static int F_216 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_17 * V_19 ;
struct V_67 * V_36 ;
int V_162 , V_14 ;
if ( ! F_40 ( V_2 ) || F_30 ( V_2 ) )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_36 = V_32 [ V_14 ] ;
V_162 = F_46 ( V_2 ) ;
if ( V_162 ) {
if ( V_162 != - V_289 )
F_54 ( L_26 ,
F_27 ( V_2 ) ) ;
F_48 ( V_2 ) ;
V_2 -> V_35 . V_72 = & V_290 ;
goto V_64;
}
F_41 ( V_2 ) ;
V_21 = F_30 ( V_2 ) ;
F_117 ( ! V_21 ) ;
if ( V_291 || V_21 -> V_68 )
F_217 ( V_2 ) ;
V_19 = F_218 ( V_2 ) ;
if ( V_19 -> type == V_292 )
V_21 -> V_286 = true ;
else
V_2 -> V_35 . V_72 = & V_293 ;
V_64:
F_95 ( V_36 ) ;
return 0 ;
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_67 * V_36 ;
int V_14 ;
if ( ! F_40 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_36 = V_32 [ V_14 ] ;
F_49 ( V_2 ) ;
F_95 ( V_36 ) ;
}
static struct V_37 * F_220 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) )
return F_221 ( V_2 ) ;
return F_31 ( V_2 ) ;
}
static struct V_16 * F_222 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
struct V_17 * V_294 ;
if ( ! F_40 ( V_2 ) )
return F_32 ( - V_15 ) ;
V_294 = F_218 ( V_2 ) ;
if ( ! V_294 )
return NULL ;
V_19 = F_12 ( V_294 ) ;
if ( ! V_47 ( V_19 ) )
return F_32 ( - V_190 ) ;
return V_19 ;
}
static void F_223 ( struct V_16 * V_19 )
{
struct V_20 * V_21 ;
F_9 (dev_data, &domain->dev_list, list)
F_190 ( V_21 -> V_14 , V_19 , V_21 -> V_167 . V_168 ) ;
}
static void F_136 ( struct V_16 * V_19 )
{
if ( ! V_19 -> V_178 )
return;
F_223 ( V_19 ) ;
F_111 ( V_19 ) ;
F_109 ( V_19 ) ;
V_19 -> V_178 = false ;
}
static T_3 * F_224 ( struct V_47 * V_18 ,
unsigned long V_80 )
{
struct V_207 * V_57 ;
T_3 * V_174 , * V_180 ;
V_57 = V_18 -> V_57 [ F_225 ( V_80 ) ] ;
if ( ! V_57 )
return NULL ;
V_174 = V_57 -> V_214 [ F_226 ( V_80 ) ] ;
if ( ! V_174 ) {
V_174 = F_116 ( & V_18 -> V_19 , V_80 , V_54 , & V_180 ,
V_232 ) ;
V_57 -> V_214 [ F_226 ( V_80 ) ] = V_180 ;
} else
V_174 += F_120 ( 0 , V_80 ) ;
F_136 ( & V_18 -> V_19 ) ;
return V_174 ;
}
static T_8 F_227 ( struct V_47 * V_18 ,
unsigned long V_80 ,
T_9 V_295 ,
int V_296 )
{
T_3 * V_174 , V_184 ;
F_79 ( V_80 > V_18 -> V_55 ) ;
V_295 &= V_142 ;
V_174 = F_224 ( V_18 , V_80 ) ;
if ( ! V_174 )
return V_233 ;
V_184 = V_295 | V_191 | V_192 ;
if ( V_296 == V_297 )
V_184 |= V_194 ;
else if ( V_296 == V_298 )
V_184 |= V_196 ;
else if ( V_296 == V_299 )
V_184 |= V_194 | V_196 ;
F_228 ( * V_174 ) ;
* V_174 = V_184 ;
return ( T_8 ) V_80 ;
}
static void F_229 ( struct V_47 * V_18 ,
unsigned long V_80 )
{
struct V_207 * V_57 ;
T_3 * V_174 ;
if ( V_80 >= V_18 -> V_55 )
return;
V_57 = V_18 -> V_57 [ F_225 ( V_80 ) ] ;
if ( ! V_57 )
return;
V_174 = V_57 -> V_214 [ F_226 ( V_80 ) ] ;
if ( ! V_174 )
return;
V_174 += F_120 ( 0 , V_80 ) ;
F_228 ( ! * V_174 ) ;
* V_174 = 0ULL ;
}
static T_8 F_230 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
T_9 V_295 ,
T_6 V_137 ,
int V_300 ,
bool V_301 ,
T_3 V_61 )
{
T_8 V_211 = V_295 & ~ V_142 ;
T_8 V_80 , V_229 , V_162 ;
unsigned int V_139 ;
unsigned long V_222 = 0 ;
int V_43 ;
V_139 = F_86 ( V_295 , V_137 , V_54 ) ;
V_295 &= V_142 ;
if ( V_301 )
V_222 = ( 1UL << F_231 ( V_137 ) ) - 1 ;
V_80 = F_158 ( V_2 , V_48 , V_139 , V_222 ,
V_61 ) ;
if ( V_80 == V_233 )
goto V_64;
V_229 = V_80 ;
for ( V_43 = 0 ; V_43 < V_139 ; ++ V_43 ) {
V_162 = F_227 ( V_48 , V_229 , V_295 , V_300 ) ;
if ( V_162 == V_233 )
goto V_302;
V_295 += V_54 ;
V_229 += V_54 ;
}
V_80 += V_211 ;
if ( F_154 ( V_303 ) ) {
F_107 ( & V_48 -> V_19 , V_80 , V_137 ) ;
F_110 ( & V_48 -> V_19 ) ;
}
V_64:
return V_80 ;
V_302:
for ( -- V_43 ; V_43 >= 0 ; -- V_43 ) {
V_229 -= V_54 ;
F_229 ( V_48 , V_229 ) ;
}
F_159 ( V_48 , V_80 , V_139 ) ;
return V_233 ;
}
static void F_232 ( struct V_47 * V_48 ,
T_8 V_304 ,
T_6 V_137 ,
int V_300 )
{
T_8 V_305 ;
T_8 V_43 , V_229 ;
unsigned int V_139 ;
if ( ( V_304 == V_233 ) ||
( V_304 + V_137 > V_48 -> V_55 ) )
return;
V_305 = V_304 ;
V_139 = F_86 ( V_304 , V_137 , V_54 ) ;
V_304 &= V_142 ;
V_229 = V_304 ;
for ( V_43 = 0 ; V_43 < V_139 ; ++ V_43 ) {
F_229 ( V_48 , V_229 ) ;
V_229 += V_54 ;
}
F_159 ( V_48 , V_304 , V_139 ) ;
}
static T_8 F_233 ( struct V_1 * V_2 , struct V_183 * V_183 ,
unsigned long V_211 , T_6 V_137 ,
enum V_306 V_300 ,
struct V_307 * V_308 )
{
T_9 V_295 = F_234 ( V_183 ) + V_211 ;
struct V_16 * V_19 ;
T_3 V_61 ;
V_19 = F_222 ( V_2 ) ;
if ( F_235 ( V_19 ) == - V_15 )
return ( T_8 ) V_295 ;
else if ( F_43 ( V_19 ) )
return V_233 ;
V_61 = * V_2 -> V_61 ;
return F_230 ( V_2 , V_19 -> V_65 , V_295 , V_137 , V_300 , false ,
V_61 ) ;
}
static void F_236 ( struct V_1 * V_2 , T_8 V_304 , T_6 V_137 ,
enum V_306 V_300 , struct V_307 * V_308 )
{
struct V_16 * V_19 ;
V_19 = F_222 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return;
F_232 ( V_19 -> V_65 , V_304 , V_137 , V_300 ) ;
}
static int F_237 ( struct V_1 * V_2 , struct V_309 * V_310 ,
int V_311 , enum V_306 V_300 ,
struct V_307 * V_308 )
{
struct V_16 * V_19 ;
int V_43 ;
struct V_309 * V_140 ;
T_9 V_295 ;
int V_312 = 0 ;
T_3 V_61 ;
V_19 = F_222 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return 0 ;
V_61 = * V_2 -> V_61 ;
F_238 (sglist, s, nelems, i) {
V_295 = F_239 ( V_140 ) ;
V_140 -> V_313 = F_230 ( V_2 , V_19 -> V_65 ,
V_295 , V_140 -> V_314 , V_300 , false ,
V_61 ) ;
if ( V_140 -> V_313 ) {
V_140 -> V_315 = V_140 -> V_314 ;
V_312 ++ ;
} else
goto V_316;
}
return V_312 ;
V_316:
F_238 (sglist, s, mapped_elems, i) {
if ( V_140 -> V_313 )
F_232 ( V_19 -> V_65 , V_140 -> V_313 ,
V_140 -> V_315 , V_300 ) ;
V_140 -> V_313 = V_140 -> V_315 = 0 ;
}
return 0 ;
}
static void F_240 ( struct V_1 * V_2 , struct V_309 * V_310 ,
int V_311 , enum V_306 V_300 ,
struct V_307 * V_308 )
{
struct V_16 * V_19 ;
struct V_309 * V_140 ;
int V_43 ;
V_19 = F_222 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return;
F_238 (sglist, s, nelems, i) {
F_232 ( V_19 -> V_65 , V_140 -> V_313 ,
V_140 -> V_315 , V_300 ) ;
V_140 -> V_313 = V_140 -> V_315 = 0 ;
}
}
static void * F_241 ( struct V_1 * V_2 , T_6 V_137 ,
T_8 * V_304 , T_7 V_317 ,
struct V_307 * V_308 )
{
T_3 V_61 = V_2 -> V_318 ;
struct V_16 * V_19 ;
struct V_183 * V_183 ;
V_19 = F_222 ( V_2 ) ;
if ( F_235 ( V_19 ) == - V_15 ) {
V_183 = F_242 ( V_317 , F_231 ( V_137 ) ) ;
* V_304 = F_234 ( V_183 ) ;
return F_243 ( V_183 ) ;
} else if ( F_43 ( V_19 ) )
return NULL ;
V_137 = F_244 ( V_137 ) ;
V_61 = V_2 -> V_318 ;
V_317 &= ~ ( V_319 | V_320 | V_321 ) ;
V_317 |= V_322 ;
V_183 = F_242 ( V_317 | V_323 , F_231 ( V_137 ) ) ;
if ( ! V_183 ) {
if ( ! F_245 ( V_317 ) )
return NULL ;
V_183 = F_246 ( V_2 , V_137 >> V_56 ,
F_231 ( V_137 ) ) ;
if ( ! V_183 )
return NULL ;
}
if ( ! V_61 )
V_61 = * V_2 -> V_61 ;
* V_304 = F_230 ( V_2 , V_19 -> V_65 , F_234 ( V_183 ) ,
V_137 , V_299 , true , V_61 ) ;
if ( * V_304 == V_233 )
goto V_210;
return F_243 ( V_183 ) ;
V_210:
if ( ! F_247 ( V_2 , V_183 , V_137 >> V_56 ) )
F_248 ( V_183 , F_231 ( V_137 ) ) ;
return NULL ;
}
static void F_249 ( struct V_1 * V_2 , T_6 V_137 ,
void * V_324 , T_8 V_304 ,
struct V_307 * V_308 )
{
struct V_16 * V_19 ;
struct V_183 * V_183 ;
V_183 = F_250 ( V_324 ) ;
V_137 = F_244 ( V_137 ) ;
V_19 = F_222 ( V_2 ) ;
if ( F_43 ( V_19 ) )
goto V_325;
F_232 ( V_19 -> V_65 , V_304 , V_137 , V_299 ) ;
V_325:
if ( ! F_247 ( V_2 , V_183 , V_137 >> V_56 ) )
F_248 ( V_183 , F_231 ( V_137 ) ) ;
}
static int F_251 ( struct V_1 * V_2 , T_3 V_227 )
{
return F_40 ( V_2 ) ;
}
static int F_252 ( struct V_1 * V_2 , T_3 V_227 )
{
struct V_16 * V_19 ;
int V_253 = 1 ;
V_19 = F_222 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return F_235 ( V_19 ) ;
if ( V_227 == F_253 ( 64 ) )
V_253 = 8 ;
else if ( V_227 > F_253 ( 32 ) )
V_253 = 4 ;
if ( V_253 > F_254 () )
V_253 = F_254 () ;
if ( F_184 ( V_19 -> V_65 , V_253 ) )
F_255 ( V_2 , L_27 ,
V_253 ) ;
return 0 ;
}
int T_10 F_256 ( void )
{
int V_326 = 0 ;
V_326 = F_257 ( & V_327 , & V_328 ) ;
if ( V_326 )
return V_326 ;
#ifdef F_258
V_326 = F_257 ( & V_329 , & V_328 ) ;
if ( V_326 )
return V_326 ;
#endif
return 0 ;
}
int T_10 F_259 ( void )
{
V_330 = V_291 ? 1 : 0 ;
V_331 = 1 ;
if ( ! V_330 )
V_72 = & V_290 ;
if ( V_234 )
F_23 ( L_28 ) ;
else
F_23 ( L_29 ) ;
return 0 ;
}
static void F_260 ( struct V_16 * V_19 )
{
struct V_20 * V_4 ;
unsigned long V_22 ;
F_166 ( & V_238 , V_22 ) ;
while ( ! F_261 ( & V_19 -> V_273 ) ) {
V_4 = F_262 ( & V_19 -> V_273 ,
struct V_20 , V_236 ) ;
F_215 ( V_4 ) ;
}
F_168 ( & V_238 , V_22 ) ;
}
static void F_263 ( struct V_16 * V_19 )
{
if ( ! V_19 )
return;
F_163 ( V_19 ) ;
if ( V_19 -> V_169 )
F_169 ( V_19 -> V_169 ) ;
F_145 ( V_19 ) ;
}
static int F_186 ( struct V_16 * V_19 )
{
F_141 ( & V_19 -> V_159 ) ;
F_264 ( & V_19 -> V_332 ) ;
V_19 -> V_169 = F_165 () ;
if ( ! V_19 -> V_169 )
return - V_66 ;
F_265 ( & V_19 -> V_273 ) ;
return 0 ;
}
static struct V_16 * F_266 ( void )
{
struct V_16 * V_19 ;
V_19 = F_15 ( sizeof( * V_19 ) , V_23 ) ;
if ( ! V_19 )
return NULL ;
if ( F_186 ( V_19 ) )
goto V_282;
F_161 ( V_19 ) ;
return V_19 ;
V_282:
F_145 ( V_19 ) ;
return NULL ;
}
static struct V_17 * F_267 ( unsigned type )
{
struct V_16 * V_333 ;
struct V_47 * V_63 ;
switch ( type ) {
case V_334 :
V_333 = F_266 () ;
if ( ! V_333 )
return NULL ;
V_333 -> V_175 = V_245 ;
V_333 -> V_177 = ( void * ) F_113 ( V_23 ) ;
if ( ! V_333 -> V_177 ) {
F_263 ( V_333 ) ;
return NULL ;
}
V_333 -> V_19 . V_335 . V_336 = 0 ;
V_333 -> V_19 . V_335 . V_337 = ~ 0ULL ;
V_333 -> V_19 . V_335 . V_338 = true ;
break;
case V_339 :
V_63 = F_185 () ;
if ( ! V_63 ) {
F_54 ( L_30 ) ;
return NULL ;
}
V_333 = & V_63 -> V_19 ;
break;
case V_292 :
V_333 = F_266 () ;
if ( ! V_333 )
return NULL ;
V_333 -> V_175 = V_242 ;
break;
default:
return NULL ;
}
return & V_333 -> V_19 ;
}
static void F_268 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
if ( ! V_18 )
return;
V_19 = F_12 ( V_18 ) ;
if ( V_19 -> V_274 > 0 )
F_260 ( V_19 ) ;
F_117 ( V_19 -> V_274 != 0 ) ;
if ( V_19 -> V_175 != V_242 )
F_171 ( V_19 ) ;
if ( V_19 -> V_22 & V_263 )
F_181 ( V_19 ) ;
F_263 ( V_19 ) ;
}
static void F_269 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_35 . V_36 ;
struct V_67 * V_36 ;
int V_14 ;
if ( ! F_40 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
if ( V_21 -> V_19 != NULL )
F_50 ( V_2 ) ;
V_36 = V_32 [ V_14 ] ;
if ( ! V_36 )
return;
F_95 ( V_36 ) ;
}
static int F_270 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
struct V_20 * V_21 ;
struct V_67 * V_36 ;
int V_162 ;
if ( ! F_40 ( V_2 ) )
return - V_15 ;
V_21 = V_2 -> V_35 . V_36 ;
V_36 = V_32 [ V_21 -> V_14 ] ;
if ( ! V_36 )
return - V_15 ;
if ( V_21 -> V_19 )
F_50 ( V_2 ) ;
V_162 = F_213 ( V_2 , V_19 ) ;
F_95 ( V_36 ) ;
return V_162 ;
}
static int F_271 ( struct V_17 * V_18 , unsigned long V_340 ,
T_9 V_295 , T_6 V_179 , int V_341 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
int V_188 = 0 ;
int V_162 ;
if ( V_19 -> V_175 == V_242 )
return - V_15 ;
if ( V_341 & V_342 )
V_188 |= V_193 ;
if ( V_341 & V_343 )
V_188 |= V_195 ;
F_272 ( & V_19 -> V_332 ) ;
V_162 = F_132 ( V_19 , V_340 , V_295 , V_188 , V_179 ) ;
F_273 ( & V_19 -> V_332 ) ;
return V_162 ;
}
static T_6 F_274 ( struct V_17 * V_18 , unsigned long V_340 ,
T_6 V_179 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
T_6 V_198 ;
if ( V_19 -> V_175 == V_242 )
return - V_15 ;
F_272 ( & V_19 -> V_332 ) ;
V_198 = F_137 ( V_19 , V_340 , V_179 ) ;
F_273 ( & V_19 -> V_332 ) ;
F_109 ( V_19 ) ;
return V_198 ;
}
static T_9 F_275 ( struct V_17 * V_18 ,
T_8 V_340 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_344 , V_206 ;
T_3 * V_174 , V_184 ;
if ( V_19 -> V_175 == V_242 )
return V_340 ;
V_174 = F_128 ( V_19 , V_340 , & V_206 ) ;
if ( ! V_174 || ! F_123 ( * V_174 ) )
return 0 ;
V_344 = V_206 - 1 ;
V_184 = * V_174 & V_345 ;
return ( V_184 & ~ V_344 ) | ( V_340 & V_344 ) ;
}
static bool F_276 ( enum V_346 V_347 )
{
switch ( V_347 ) {
case V_348 :
return true ;
case V_349 :
return ( V_350 == 1 ) ;
case V_351 :
return false ;
}
return false ;
}
static void F_277 ( struct V_1 * V_2 ,
struct V_352 * V_100 )
{
struct V_49 * V_4 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
F_9 (entry, &amd_iommu_unity_map, list) {
struct V_353 * V_354 ;
if ( V_14 < V_4 -> V_59 || V_14 > V_4 -> V_60 )
continue;
V_354 = F_15 ( sizeof( * V_354 ) , V_23 ) ;
if ( ! V_354 ) {
F_54 ( L_31 ,
F_27 ( V_2 ) ) ;
return;
}
V_354 -> V_229 = V_4 -> V_52 ;
V_354 -> V_314 = V_4 -> V_53 - V_4 -> V_52 ;
if ( V_4 -> V_188 & V_193 )
V_354 -> V_188 |= V_342 ;
if ( V_4 -> V_188 & V_195 )
V_354 -> V_188 |= V_343 ;
F_17 ( & V_354 -> V_236 , V_100 ) ;
}
}
static void F_278 ( struct V_1 * V_2 ,
struct V_352 * V_100 )
{
struct V_353 * V_4 , * V_355 ;
F_279 (entry, next, head, list)
F_145 ( V_4 ) ;
}
int F_280 ( struct V_356 * V_357 )
{
return F_281 ( & V_115 , V_357 ) ;
}
int F_282 ( struct V_356 * V_357 )
{
return F_283 ( & V_115 , V_357 ) ;
}
void F_284 ( struct V_17 * V_18 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_22 ;
F_16 ( & V_19 -> V_159 , V_22 ) ;
V_19 -> V_175 = V_242 ;
V_19 -> V_178 = true ;
F_136 ( V_19 ) ;
F_171 ( V_19 ) ;
F_18 ( & V_19 -> V_159 , V_22 ) ;
}
int F_285 ( struct V_17 * V_18 , int V_358 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_22 ;
int V_359 , V_162 ;
if ( V_358 <= 0 || V_358 > ( V_360 + 1 ) )
return - V_15 ;
for ( V_359 = 0 ; ( V_358 - 1 ) & ~ 0x1ff ; V_358 >>= 9 )
V_359 += 1 ;
if ( V_359 > V_361 )
return - V_15 ;
F_16 ( & V_19 -> V_159 , V_22 ) ;
V_162 = - V_190 ;
if ( V_19 -> V_274 > 0 || V_19 -> V_22 & V_263 )
goto V_64;
V_162 = - V_66 ;
V_19 -> V_252 = ( void * ) F_113 ( V_232 ) ;
if ( V_19 -> V_252 == NULL )
goto V_64;
V_19 -> V_251 = V_359 ;
V_19 -> V_22 |= V_263 ;
V_19 -> V_178 = true ;
F_136 ( V_19 ) ;
V_162 = 0 ;
V_64:
F_18 ( & V_19 -> V_159 , V_22 ) ;
return V_162 ;
}
static int F_286 ( struct V_16 * V_19 , int V_112 ,
T_3 V_80 , bool V_137 )
{
struct V_20 * V_21 ;
struct V_74 V_75 ;
int V_43 , V_162 ;
if ( ! ( V_19 -> V_22 & V_263 ) )
return - V_15 ;
F_88 ( & V_75 , V_19 -> V_169 , V_112 , V_80 , V_137 ) ;
for ( V_43 = 0 ; V_43 < V_170 ; ++ V_43 ) {
if ( V_19 -> V_171 [ V_43 ] == 0 )
continue;
V_162 = F_94 ( V_172 [ V_43 ] , & V_75 ) ;
if ( V_162 != 0 )
goto V_64;
}
F_110 ( V_19 ) ;
F_9 (dev_data, &domain->dev_list, list) {
struct V_67 * V_36 ;
int V_146 ;
if ( ! V_21 -> V_167 . V_168 )
continue;
V_146 = V_21 -> V_167 . V_146 ;
V_36 = V_32 [ V_21 -> V_14 ] ;
F_89 ( & V_75 , V_21 -> V_14 , V_112 ,
V_146 , V_80 , V_137 ) ;
V_162 = F_94 ( V_36 , & V_75 ) ;
if ( V_162 != 0 )
goto V_64;
}
F_110 ( V_19 ) ;
V_162 = 0 ;
V_64:
return V_162 ;
}
static int F_287 ( struct V_16 * V_19 , int V_112 ,
T_3 V_80 )
{
return F_286 ( V_19 , V_112 , V_80 , false ) ;
}
int F_288 ( struct V_17 * V_18 , int V_112 ,
T_3 V_80 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_22 ;
int V_162 ;
F_16 ( & V_19 -> V_159 , V_22 ) ;
V_162 = F_287 ( V_19 , V_112 , V_80 ) ;
F_18 ( & V_19 -> V_159 , V_22 ) ;
return V_162 ;
}
static int F_289 ( struct V_16 * V_19 , int V_112 )
{
return F_286 ( V_19 , V_112 , V_141 ,
true ) ;
}
int F_290 ( struct V_17 * V_18 , int V_112 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_22 ;
int V_162 ;
F_16 ( & V_19 -> V_159 , V_22 ) ;
V_162 = F_289 ( V_19 , V_112 ) ;
F_18 ( & V_19 -> V_159 , V_22 ) ;
return V_162 ;
}
static T_3 * F_291 ( T_3 * V_241 , int V_181 , int V_112 , bool V_362 )
{
int V_201 ;
T_3 * V_174 ;
while ( true ) {
V_201 = ( V_112 >> ( 9 * V_181 ) ) & 0x1ff ;
V_174 = & V_241 [ V_201 ] ;
if ( V_181 == 0 )
break;
if ( ! ( * V_174 & V_250 ) ) {
if ( ! V_362 )
return NULL ;
V_241 = ( void * ) F_113 ( V_232 ) ;
if ( V_241 == NULL )
return NULL ;
* V_174 = F_81 ( V_241 ) | V_250 ;
}
V_241 = F_179 ( * V_174 & V_142 ) ;
V_181 -= 1 ;
}
return V_174 ;
}
static int F_292 ( struct V_16 * V_19 , int V_112 ,
unsigned long V_363 )
{
T_3 * V_174 ;
if ( V_19 -> V_175 != V_242 )
return - V_15 ;
V_174 = F_291 ( V_19 -> V_252 , V_19 -> V_251 , V_112 , true ) ;
if ( V_174 == NULL )
return - V_66 ;
* V_174 = ( V_363 & V_142 ) | V_250 ;
return F_289 ( V_19 , V_112 ) ;
}
static int F_293 ( struct V_16 * V_19 , int V_112 )
{
T_3 * V_174 ;
if ( V_19 -> V_175 != V_242 )
return - V_15 ;
V_174 = F_291 ( V_19 -> V_252 , V_19 -> V_251 , V_112 , false ) ;
if ( V_174 == NULL )
return 0 ;
* V_174 = 0 ;
return F_289 ( V_19 , V_112 ) ;
}
int F_294 ( struct V_17 * V_18 , int V_112 ,
unsigned long V_363 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_22 ;
int V_162 ;
F_16 ( & V_19 -> V_159 , V_22 ) ;
V_162 = F_292 ( V_19 , V_112 , V_363 ) ;
F_18 ( & V_19 -> V_159 , V_22 ) ;
return V_162 ;
}
int F_295 ( struct V_17 * V_18 , int V_112 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_22 ;
int V_162 ;
F_16 ( & V_19 -> V_159 , V_22 ) ;
V_162 = F_293 ( V_19 , V_112 ) ;
F_18 ( & V_19 -> V_159 , V_22 ) ;
return V_162 ;
}
int F_296 ( struct V_8 * V_9 , int V_112 ,
int V_122 , int V_114 )
{
struct V_20 * V_21 ;
struct V_67 * V_36 ;
struct V_74 V_75 ;
V_21 = F_30 ( & V_9 -> V_2 ) ;
V_36 = V_32 [ V_21 -> V_14 ] ;
F_90 ( & V_75 , V_21 -> V_14 , V_112 , V_122 ,
V_114 , V_21 -> V_287 ) ;
return F_94 ( V_36 , & V_75 ) ;
}
struct V_17 * F_297 ( struct V_8 * V_9 )
{
struct V_16 * V_333 ;
V_333 = F_222 ( & V_9 -> V_2 ) ;
if ( F_43 ( V_333 ) )
return NULL ;
if ( ! ( V_333 -> V_22 & V_263 ) )
return NULL ;
return & V_333 -> V_19 ;
}
void F_298 ( struct V_8 * V_9 , T_2 V_45 )
{
struct V_20 * V_21 ;
if ( ! F_299 () )
return;
V_21 = F_30 ( & V_9 -> V_2 ) ;
V_21 -> V_46 |= ( 1 << V_45 ) ;
}
int F_300 ( struct V_8 * V_9 ,
struct F_300 * V_364 )
{
int V_365 ;
int V_44 ;
if ( V_9 == NULL || V_364 == NULL )
return - V_15 ;
if ( ! F_299 () )
return - V_15 ;
memset ( V_364 , 0 , sizeof( * V_364 ) ) ;
V_44 = F_35 ( V_9 , V_40 ) ;
if ( V_44 )
V_364 -> V_22 |= V_366 ;
V_44 = F_35 ( V_9 , V_41 ) ;
if ( V_44 )
V_364 -> V_22 |= V_367 ;
V_44 = F_35 ( V_9 , V_42 ) ;
if ( V_44 ) {
int V_368 ;
V_365 = 1 << ( 9 * ( V_361 + 1 ) ) ;
V_365 = F_301 ( V_365 , ( 1 << 20 ) ) ;
V_364 -> V_22 |= V_369 ;
V_364 -> V_365 = F_301 ( F_302 ( V_9 ) , V_365 ) ;
V_368 = F_303 ( V_9 ) ;
if ( V_368 & V_370 )
V_364 -> V_22 |= V_371 ;
if ( V_368 & V_372 )
V_364 -> V_22 |= V_373 ;
}
return 0 ;
}
static void F_304 ( T_1 V_14 , struct V_374 * V_375 )
{
T_3 V_376 ;
V_376 = V_33 [ V_14 ] . V_28 [ 2 ] ;
V_376 &= ~ V_377 ;
V_376 |= F_115 ( V_375 -> V_375 ) ;
V_376 |= V_378 ;
V_376 |= V_379 ;
V_376 |= V_380 ;
V_33 [ V_14 ] . V_28 [ 2 ] = V_376 ;
}
static struct V_374 * F_305 ( T_1 V_14 , bool V_381 )
{
struct V_374 * V_375 = NULL ;
struct V_67 * V_36 ;
unsigned long V_22 ;
T_1 V_27 ;
F_166 ( & V_238 , V_22 ) ;
V_36 = V_32 [ V_14 ] ;
if ( ! V_36 )
goto V_26;
V_375 = V_382 [ V_14 ] ;
if ( V_375 )
goto V_64;
V_27 = V_31 [ V_14 ] ;
V_375 = V_382 [ V_27 ] ;
if ( V_375 ) {
V_382 [ V_14 ] = V_375 ;
F_304 ( V_14 , V_375 ) ;
F_96 ( V_36 , V_14 ) ;
goto V_64;
}
V_375 = F_15 ( sizeof( * V_375 ) , V_232 ) ;
if ( ! V_375 )
goto V_64;
F_141 ( & V_375 -> V_159 ) ;
if ( V_381 )
V_375 -> V_383 = 32 ;
V_375 -> V_375 = F_306 ( V_384 , V_232 ) ;
if ( ! V_375 -> V_375 ) {
F_145 ( V_375 ) ;
V_375 = NULL ;
goto V_64;
}
memset ( V_375 -> V_375 , 0 , V_385 * sizeof( T_2 ) ) ;
if ( V_381 ) {
int V_43 ;
for ( V_43 = 0 ; V_43 < 32 ; ++ V_43 )
V_375 -> V_375 [ V_43 ] = V_386 ;
}
V_382 [ V_14 ] = V_375 ;
F_304 ( V_14 , V_375 ) ;
F_96 ( V_36 , V_14 ) ;
if ( V_14 != V_27 ) {
V_382 [ V_27 ] = V_375 ;
F_304 ( V_27 , V_375 ) ;
F_96 ( V_36 , V_27 ) ;
}
V_64:
F_95 ( V_36 ) ;
V_26:
F_168 ( & V_238 , V_22 ) ;
return V_375 ;
}
static int F_307 ( T_1 V_14 , int V_79 )
{
struct V_374 * V_375 ;
unsigned long V_22 ;
int V_201 , V_387 ;
V_375 = F_305 ( V_14 , false ) ;
if ( ! V_375 )
return - V_7 ;
F_16 ( & V_375 -> V_159 , V_22 ) ;
for ( V_387 = 0 , V_201 = V_375 -> V_383 ;
V_201 < V_385 ;
++ V_201 ) {
if ( V_375 -> V_375 [ V_201 ] == 0 )
V_387 += 1 ;
else
V_387 = 0 ;
if ( V_387 == V_79 ) {
for (; V_387 != 0 ; -- V_387 )
V_375 -> V_375 [ V_201 - V_387 + 1 ] = V_386 ;
V_201 -= V_79 - 1 ;
goto V_64;
}
}
V_201 = - V_388 ;
V_64:
F_18 ( & V_375 -> V_159 , V_22 ) ;
return V_201 ;
}
static int F_308 ( T_1 V_14 , int V_201 , union V_389 V_389 )
{
struct V_374 * V_375 ;
struct V_67 * V_36 ;
unsigned long V_22 ;
V_36 = V_32 [ V_14 ] ;
if ( V_36 == NULL )
return - V_15 ;
V_375 = F_305 ( V_14 , false ) ;
if ( ! V_375 )
return - V_66 ;
F_16 ( & V_375 -> V_159 , V_22 ) ;
V_375 -> V_375 [ V_201 ] = V_389 . V_390 ;
F_18 ( & V_375 -> V_159 , V_22 ) ;
F_100 ( V_36 , V_14 ) ;
F_95 ( V_36 ) ;
return 0 ;
}
static void F_309 ( T_1 V_14 , int V_201 )
{
struct V_374 * V_375 ;
struct V_67 * V_36 ;
unsigned long V_22 ;
V_36 = V_32 [ V_14 ] ;
if ( V_36 == NULL )
return;
V_375 = F_305 ( V_14 , false ) ;
if ( ! V_375 )
return;
F_16 ( & V_375 -> V_159 , V_22 ) ;
V_375 -> V_375 [ V_201 ] = 0 ;
F_18 ( & V_375 -> V_159 , V_22 ) ;
F_100 ( V_36 , V_14 ) ;
F_95 ( V_36 ) ;
}
static int F_310 ( struct V_391 * V_364 )
{
int V_14 = - 1 ;
switch ( V_364 -> type ) {
case V_392 :
V_14 = F_311 ( V_364 -> V_393 ) ;
break;
case V_394 :
V_14 = F_312 ( V_364 -> V_395 ) ;
break;
case V_396 :
case V_397 :
V_14 = F_10 ( & V_364 -> V_398 -> V_2 ) ;
break;
default:
F_117 ( 1 ) ;
break;
}
return V_14 ;
}
static struct V_399 * F_313 ( struct V_391 * V_364 )
{
struct V_67 * V_36 ;
int V_14 ;
if ( ! V_364 )
return NULL ;
V_14 = F_310 ( V_364 ) ;
if ( V_14 >= 0 ) {
V_36 = V_32 [ V_14 ] ;
if ( V_36 )
return V_36 -> V_400 ;
}
return NULL ;
}
static struct V_399 * F_314 ( struct V_391 * V_364 )
{
struct V_67 * V_36 ;
int V_14 ;
if ( ! V_364 )
return NULL ;
switch ( V_364 -> type ) {
case V_396 :
case V_397 :
V_14 = F_10 ( & V_364 -> V_398 -> V_2 ) ;
if ( V_14 < 0 )
return NULL ;
V_36 = V_32 [ V_14 ] ;
if ( V_36 )
return V_36 -> V_401 ;
break;
default:
break;
}
return NULL ;
}
static void F_315 ( struct V_402 * V_28 ,
struct V_403 * V_403 ,
struct V_391 * V_364 ,
int V_14 , int V_201 , int V_404 )
{
struct V_405 * V_406 = & V_28 -> V_405 ;
struct V_407 * V_408 = & V_28 -> V_409 ;
union V_389 * V_389 = & V_28 -> V_410 ;
struct V_411 * V_4 ;
V_28 -> V_405 . V_14 = V_14 ;
V_28 -> V_405 . V_201 = V_201 + V_404 ;
V_389 -> V_390 = 0 ;
V_389 -> V_412 . V_413 = V_403 -> V_413 ;
V_389 -> V_412 . V_414 = V_415 -> V_416 ;
V_389 -> V_412 . V_417 = V_403 -> V_418 ;
V_389 -> V_412 . V_419 = V_415 -> V_420 ;
V_389 -> V_412 . V_421 = 1 ;
switch ( V_364 -> type ) {
case V_392 :
V_4 = V_364 -> V_422 ;
V_364 -> V_422 = NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_413 = V_201 ;
V_4 -> V_227 = 0 ;
V_4 -> V_423 = V_364 -> V_424 ;
V_4 -> V_425 = V_364 -> V_426 ;
if ( V_364 -> V_424 )
V_4 -> V_227 = 1 ;
break;
case V_394 :
case V_396 :
case V_397 :
V_408 -> V_427 = V_428 ;
V_408 -> V_429 = V_216 ;
V_408 -> V_28 = V_406 -> V_201 ;
break;
default:
F_117 ( 1 ) ;
break;
}
}
static int F_316 ( struct V_399 * V_19 , unsigned int V_430 ,
unsigned int V_431 , void * V_432 )
{
struct V_391 * V_364 = V_432 ;
struct V_433 * V_433 ;
struct V_402 * V_28 ;
struct V_403 * V_434 ;
int V_43 , V_162 , V_14 ;
int V_201 = - 1 ;
if ( ! V_364 )
return - V_15 ;
if ( V_431 > 1 && V_364 -> type != V_396 &&
V_364 -> type != V_397 )
return - V_15 ;
if ( V_364 -> type == V_396 )
V_364 -> V_22 &= ~ V_435 ;
V_14 = F_310 ( V_364 ) ;
if ( V_14 < 0 )
return - V_15 ;
V_162 = F_317 ( V_19 , V_430 , V_431 , V_432 ) ;
if ( V_162 < 0 )
return V_162 ;
if ( V_364 -> type == V_392 ) {
if ( F_305 ( V_14 , true ) )
V_201 = V_364 -> V_436 ;
else
V_162 = - V_66 ;
} else {
V_201 = F_307 ( V_14 , V_431 ) ;
}
if ( V_201 < 0 ) {
F_318 ( L_32 ) ;
goto V_437;
}
for ( V_43 = 0 ; V_43 < V_431 ; V_43 ++ ) {
V_433 = F_319 ( V_19 , V_430 + V_43 ) ;
V_434 = F_320 ( V_433 ) ;
if ( ! V_433 || ! V_434 ) {
V_162 = - V_15 ;
goto V_438;
}
V_162 = - V_66 ;
V_28 = F_15 ( sizeof( * V_28 ) , V_23 ) ;
if ( ! V_28 )
goto V_438;
V_433 -> V_439 = ( V_14 << 16 ) + V_43 ;
V_433 -> V_440 = V_28 ;
V_433 -> V_441 = & V_442 ;
F_315 ( V_28 , V_434 , V_364 , V_14 , V_201 , V_43 ) ;
F_321 ( V_430 + V_43 , V_443 ) ;
}
return 0 ;
V_438:
for ( V_43 -- ; V_43 >= 0 ; V_43 -- ) {
V_433 = F_319 ( V_19 , V_430 + V_43 ) ;
if ( V_433 )
F_145 ( V_433 -> V_440 ) ;
}
for ( V_43 = 0 ; V_43 < V_431 ; V_43 ++ )
F_309 ( V_14 , V_201 + V_43 ) ;
V_437:
F_322 ( V_19 , V_430 , V_431 ) ;
return V_162 ;
}
static void F_323 ( struct V_399 * V_19 , unsigned int V_430 ,
unsigned int V_431 )
{
struct V_405 * V_406 ;
struct V_433 * V_433 ;
struct V_402 * V_28 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_431 ; V_43 ++ ) {
V_433 = F_319 ( V_19 , V_430 + V_43 ) ;
if ( V_433 && V_433 -> V_440 ) {
V_28 = V_433 -> V_440 ;
V_406 = & V_28 -> V_405 ;
F_309 ( V_406 -> V_14 , V_406 -> V_201 ) ;
F_145 ( V_28 ) ;
}
}
F_322 ( V_19 , V_430 , V_431 ) ;
}
static void F_324 ( struct V_399 * V_19 ,
struct V_433 * V_433 )
{
struct V_402 * V_28 = V_433 -> V_440 ;
struct V_405 * V_406 = & V_28 -> V_405 ;
F_308 ( V_406 -> V_14 , V_406 -> V_201 , V_28 -> V_410 ) ;
}
static void F_325 ( struct V_399 * V_19 ,
struct V_433 * V_433 )
{
struct V_402 * V_28 = V_433 -> V_440 ;
struct V_405 * V_406 = & V_28 -> V_405 ;
union V_389 V_4 ;
V_4 . V_390 = 0 ;
F_308 ( V_406 -> V_14 , V_406 -> V_201 , V_28 -> V_410 ) ;
}
static int F_326 ( struct V_433 * V_28 ,
const struct V_444 * V_227 , bool V_445 )
{
struct V_402 * V_446 = V_28 -> V_440 ;
struct V_405 * V_406 = & V_446 -> V_405 ;
struct V_403 * V_434 = F_320 ( V_28 ) ;
struct V_433 * V_447 = V_28 -> V_448 ;
int V_162 ;
V_162 = V_447 -> V_441 -> V_449 ( V_447 , V_227 , V_445 ) ;
if ( V_162 < 0 || V_162 == V_450 )
return V_162 ;
V_446 -> V_410 . V_412 . V_413 = V_434 -> V_413 ;
V_446 -> V_410 . V_412 . V_417 = V_434 -> V_418 ;
F_308 ( V_406 -> V_14 , V_406 -> V_201 , V_446 -> V_410 ) ;
F_327 ( V_434 ) ;
return V_450 ;
}
static void F_328 ( struct V_433 * V_433 , struct V_407 * V_408 )
{
struct V_402 * V_446 = V_433 -> V_440 ;
* V_408 = V_446 -> V_409 ;
}
int F_329 ( struct V_67 * V_36 )
{
V_36 -> V_400 = F_330 ( NULL , & V_451 , V_36 ) ;
if ( ! V_36 -> V_400 )
return - V_66 ;
V_36 -> V_400 -> V_447 = F_331 () ;
V_36 -> V_401 = F_332 ( V_36 -> V_400 ) ;
return 0 ;
}
