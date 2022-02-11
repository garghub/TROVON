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
static struct V_20 * F_14 ( struct V_16 * V_19 )
{
F_15 ( V_19 -> V_21 != V_22 ) ;
return F_13 ( V_19 , struct V_20 , V_19 ) ;
}
static struct V_23 * F_16 ( T_1 V_14 )
{
struct V_23 * V_24 ;
unsigned long V_21 ;
V_24 = F_17 ( sizeof( * V_24 ) , V_25 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_14 = V_14 ;
F_18 ( & V_26 , V_21 ) ;
F_19 ( & V_24 -> V_27 , & V_27 ) ;
F_20 ( & V_26 , V_21 ) ;
return V_24 ;
}
static struct V_23 * F_21 ( T_1 V_14 )
{
struct V_23 * V_24 ;
unsigned long V_21 ;
F_18 ( & V_26 , V_21 ) ;
F_9 (dev_data, &dev_data_list, dev_data_list) {
if ( V_24 -> V_14 == V_14 )
goto V_28;
}
V_24 = NULL ;
V_28:
F_20 ( & V_26 , V_21 ) ;
return V_24 ;
}
static int F_22 ( struct V_8 * V_9 , T_1 V_29 , void * V_30 )
{
* ( T_1 * ) V_30 = V_29 ;
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
T_1 V_14 , V_31 , V_32 ;
V_14 = F_10 ( V_2 ) ;
V_31 = V_33 [ V_14 ] ;
F_24 ( V_9 , F_22 , & V_32 ) ;
if ( V_31 == V_32 )
return V_31 ;
if ( V_31 == V_14 ) {
if ( ! V_34 [ V_32 ] ) {
V_34 [ V_32 ] =
V_34 [ V_14 ] ;
memcpy ( V_35 [ V_32 ] . V_30 ,
V_35 [ V_14 ] . V_30 ,
sizeof( V_35 [ V_32 ] . V_30 ) ) ;
}
return V_32 ;
}
F_25 ( L_1
L_2
L_3 , F_26 ( V_31 ) , F_27 ( V_31 ) ,
F_28 ( V_31 ) , F_29 ( V_2 ) , V_9 -> V_36 , V_9 -> V_1 ,
F_26 ( V_32 ) , F_27 ( V_32 ) ,
F_28 ( V_32 ) ) ;
if ( V_32 == V_14 &&
F_26 ( V_31 ) == V_9 -> V_10 -> V_11 ) {
F_30 ( V_9 , V_31 & 0xff ) ;
F_25 ( L_4 ,
F_27 ( V_31 ) , F_28 ( V_31 ) ,
F_29 ( V_2 ) ) ;
}
return V_31 ;
}
static struct V_23 * F_31 ( T_1 V_14 )
{
struct V_23 * V_24 ;
V_24 = F_21 ( V_14 ) ;
if ( V_24 == NULL )
V_24 = F_16 ( V_14 ) ;
return V_24 ;
}
static struct V_23 * F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_37 . V_38 ;
}
static struct V_39 * F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_13 , * V_4 = NULL ;
int V_14 ;
V_14 = F_8 ( V_2 , & V_4 ) ;
if ( V_14 < 0 )
return F_34 ( V_14 ) ;
F_9 (p, &acpihid_map, list) {
if ( ( V_14 == V_13 -> V_14 ) && V_13 -> V_40 )
V_4 -> V_40 = V_13 -> V_40 ;
}
if ( ! V_4 -> V_40 )
V_4 -> V_40 = F_35 ( V_2 ) ;
else
F_36 ( V_4 -> V_40 ) ;
return V_4 -> V_40 ;
}
static bool F_37 ( struct V_8 * V_9 )
{
static const int V_41 [] = {
V_42 ,
V_43 ,
V_44 ,
} ;
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < 3 ; ++ V_45 ) {
V_46 = F_38 ( V_9 , V_41 [ V_45 ] ) ;
if ( V_46 == 0 )
return false ;
}
return true ;
}
static bool F_39 ( struct V_8 * V_9 , T_2 V_47 )
{
struct V_23 * V_24 ;
V_24 = F_32 ( & V_9 -> V_2 ) ;
return V_24 -> V_48 & ( 1 << V_47 ) ? true : false ;
}
static bool F_40 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ! V_2 || ! V_2 -> V_49 )
return false ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return false ;
if ( V_14 > V_50 )
return false ;
if ( V_34 [ V_14 ] == NULL )
return false ;
return true ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
V_40 = F_42 ( V_2 ) ;
if ( F_43 ( V_40 ) )
return;
F_44 ( V_40 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
int V_14 ;
if ( V_2 -> V_37 . V_38 )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_24 = F_31 ( V_14 ) ;
if ( ! V_24 )
return - V_51 ;
V_24 -> V_29 = F_23 ( V_2 ) ;
if ( F_11 ( V_2 ) && F_37 ( F_6 ( V_2 ) ) ) {
struct V_52 * V_38 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_24 -> V_53 = V_38 -> V_54 ;
}
V_2 -> V_37 . V_38 = V_24 ;
F_46 ( V_34 [ V_24 -> V_14 ] -> V_55 ,
V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
T_1 V_29 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_29 = F_23 ( V_2 ) ;
memset ( & V_35 [ V_14 ] , 0 , sizeof( struct V_56 ) ) ;
memset ( & V_35 [ V_29 ] , 0 , sizeof( struct V_56 ) ) ;
V_34 [ V_14 ] = NULL ;
V_34 [ V_29 ] = NULL ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_14 ;
struct V_23 * V_24 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_24 = F_21 ( V_14 ) ;
if ( ! V_24 )
return;
if ( V_24 -> V_19 )
F_49 ( V_2 ) ;
F_50 ( V_34 [ V_24 -> V_14 ] -> V_55 ,
V_2 ) ;
F_51 ( V_2 ) ;
V_2 -> V_37 . V_57 = NULL ;
}
static void F_52 ( T_1 V_14 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < 4 ; ++ V_45 )
F_53 ( L_5 , V_45 ,
V_35 [ V_14 ] . V_30 [ V_45 ] ) ;
}
static void F_54 ( unsigned long V_58 )
{
struct V_59 * V_60 = F_55 ( V_58 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 4 ; ++ V_45 )
F_53 ( L_6 , V_45 , V_60 -> V_30 [ V_45 ] ) ;
}
static void F_56 ( struct V_52 * V_38 , void * V_61 )
{
int type , V_14 , V_62 , V_21 ;
volatile T_2 * V_63 = V_61 ;
int V_64 = 0 ;
T_3 V_65 ;
V_66:
type = ( V_63 [ 1 ] >> V_67 ) & V_68 ;
V_14 = ( V_63 [ 0 ] >> V_69 ) & V_70 ;
V_62 = ( V_63 [ 1 ] >> V_71 ) & V_72 ;
V_21 = ( V_63 [ 1 ] >> V_73 ) & V_74 ;
V_65 = ( T_3 ) ( ( ( T_3 ) V_63 [ 3 ] ) << 32 ) | V_63 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_64 == V_75 ) {
F_53 ( L_7 ) ;
return;
}
F_57 ( 1 ) ;
goto V_66;
}
F_58 ( V_76 L_8 ) ;
switch ( type ) {
case V_77 :
F_58 ( L_9
L_10 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_65 , V_21 ) ;
F_52 ( V_14 ) ;
break;
case V_78 :
F_58 ( L_11
L_12 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_62 , V_65 , V_21 ) ;
break;
case V_79 :
F_58 ( L_13
L_10 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_65 , V_21 ) ;
break;
case V_80 :
F_58 ( L_14
L_12 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_62 , V_65 , V_21 ) ;
break;
case V_81 :
F_58 ( L_15 , V_65 ) ;
F_54 ( V_65 ) ;
break;
case V_82 :
F_58 ( L_16
L_17 , V_65 , V_21 ) ;
break;
case V_83 :
F_58 ( L_18
L_19 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_65 ) ;
break;
case V_84 :
F_58 ( L_20
L_10 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_65 , V_21 ) ;
break;
default:
F_58 ( V_76 L_21 , type ) ;
}
memset ( V_61 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_59 ( struct V_52 * V_38 )
{
T_2 V_85 , V_86 ;
V_85 = F_60 ( V_38 -> V_87 + V_88 ) ;
V_86 = F_60 ( V_38 -> V_87 + V_89 ) ;
while ( V_85 != V_86 ) {
F_56 ( V_38 , V_38 -> V_90 + V_85 ) ;
V_85 = ( V_85 + V_91 ) % V_92 ;
}
F_61 ( V_85 , V_38 -> V_87 + V_88 ) ;
}
static void F_62 ( struct V_52 * V_38 , T_3 * V_93 )
{
struct V_94 V_95 ;
if ( F_63 ( V_93 [ 0 ] ) != V_96 ) {
F_64 ( L_22 ) ;
return;
}
V_95 . V_65 = V_93 [ 1 ] ;
V_95 . V_97 = F_65 ( V_93 [ 0 ] ) ;
V_95 . V_98 = F_66 ( V_93 [ 0 ] ) ;
V_95 . V_99 = F_67 ( V_93 [ 0 ] ) ;
V_95 . V_21 = F_68 ( V_93 [ 0 ] ) ;
F_69 ( & V_100 , 0 , & V_95 ) ;
}
static void F_70 ( struct V_52 * V_38 )
{
T_2 V_85 , V_86 ;
if ( V_38 -> V_101 == NULL )
return;
V_85 = F_60 ( V_38 -> V_87 + V_102 ) ;
V_86 = F_60 ( V_38 -> V_87 + V_103 ) ;
while ( V_85 != V_86 ) {
volatile T_3 * V_93 ;
T_3 V_4 [ 2 ] ;
int V_45 ;
V_93 = ( T_3 * ) ( V_38 -> V_101 + V_85 ) ;
for ( V_45 = 0 ; V_45 < V_75 ; ++ V_45 ) {
if ( F_63 ( V_93 [ 0 ] ) != 0 )
break;
F_57 ( 1 ) ;
}
V_4 [ 0 ] = V_93 [ 0 ] ;
V_4 [ 1 ] = V_93 [ 1 ] ;
V_93 [ 0 ] = V_93 [ 1 ] = 0UL ;
V_85 = ( V_85 + V_104 ) % V_105 ;
F_61 ( V_85 , V_38 -> V_87 + V_102 ) ;
F_62 ( V_38 , V_4 ) ;
V_85 = F_60 ( V_38 -> V_87 + V_102 ) ;
V_86 = F_60 ( V_38 -> V_87 + V_103 ) ;
}
}
int F_71 ( int (* F_72)( T_2 ) )
{
V_106 = F_72 ;
return 0 ;
}
static void F_73 ( struct V_52 * V_38 )
{
T_2 V_85 , V_86 , V_107 = 0 ;
if ( V_38 -> V_108 == NULL )
return;
V_85 = F_60 ( V_38 -> V_87 + V_109 ) ;
V_86 = F_60 ( V_38 -> V_87 + V_110 ) ;
while ( V_85 != V_86 ) {
volatile T_3 * V_93 ;
T_3 V_111 ;
V_93 = ( T_3 * ) ( V_38 -> V_108 + V_85 ) ;
V_107 ++ ;
V_111 = * V_93 ;
V_85 = ( V_85 + V_112 ) % V_113 ;
F_61 ( V_85 , V_38 -> V_87 + V_109 ) ;
switch ( F_74 ( V_111 ) ) {
case V_114 :
if ( ! V_106 )
break;
F_75 ( L_23 ,
V_115 , F_76 ( V_111 ) ,
F_77 ( V_111 ) ) ;
if ( V_106 ( F_77 ( V_111 ) ) != 0 )
F_53 ( L_24 ) ;
break;
default:
break;
}
}
}
T_4 F_78 ( int V_116 , void * V_30 )
{
struct V_52 * V_38 = (struct V_52 * ) V_30 ;
T_2 V_117 = F_60 ( V_38 -> V_87 + V_118 ) ;
while ( V_117 & V_119 ) {
F_61 ( V_119 ,
V_38 -> V_87 + V_118 ) ;
if ( V_117 & V_120 ) {
F_79 ( L_25 ) ;
F_59 ( V_38 ) ;
}
if ( V_117 & V_121 ) {
F_79 ( L_26 ) ;
F_70 ( V_38 ) ;
}
#ifdef F_80
if ( V_117 & V_122 ) {
F_79 ( L_27 ) ;
F_73 ( V_38 ) ;
}
#endif
V_117 = F_60 ( V_38 -> V_87 + V_118 ) ;
}
return V_123 ;
}
T_4 F_81 ( int V_116 , void * V_30 )
{
return V_124 ;
}
static int F_82 ( volatile T_3 * V_125 )
{
int V_45 = 0 ;
while ( * V_125 == 0 && V_45 < V_75 ) {
F_57 ( 1 ) ;
V_45 += 1 ;
}
if ( V_45 == V_75 ) {
F_83 ( L_28 ) ;
return - V_126 ;
}
return 0 ;
}
static void F_84 ( struct V_52 * V_38 ,
struct V_59 * V_60 ,
T_2 V_86 )
{
T_5 * V_127 ;
V_127 = V_38 -> V_128 + V_86 ;
V_86 = ( V_86 + sizeof( * V_60 ) ) % V_129 ;
memcpy ( V_127 , V_60 , sizeof( * V_60 ) ) ;
F_61 ( V_86 , V_38 -> V_87 + V_130 ) ;
}
static void F_85 ( struct V_59 * V_60 , T_3 V_65 )
{
F_86 ( V_65 & 0x7ULL ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = F_87 ( F_88 ( V_65 ) ) | V_131 ;
V_60 -> V_30 [ 1 ] = F_89 ( F_88 ( V_65 ) ) ;
V_60 -> V_30 [ 2 ] = 1 ;
F_90 ( V_60 , V_132 ) ;
}
static void F_91 ( struct V_59 * V_60 , T_1 V_14 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
F_90 ( V_60 , V_133 ) ;
}
static void F_92 ( struct V_59 * V_60 , T_3 V_65 ,
T_6 V_134 , T_1 V_62 , int V_135 )
{
T_3 V_136 ;
bool V_137 ;
V_136 = F_93 ( V_65 , V_134 , V_138 ) ;
V_137 = false ;
if ( V_136 > 1 ) {
V_65 = V_139 ;
V_137 = true ;
}
V_65 &= V_140 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 1 ] |= V_62 ;
V_60 -> V_30 [ 2 ] = F_87 ( V_65 ) ;
V_60 -> V_30 [ 3 ] = F_89 ( V_65 ) ;
F_90 ( V_60 , V_141 ) ;
if ( V_137 )
V_60 -> V_30 [ 2 ] |= V_142 ;
if ( V_135 )
V_60 -> V_30 [ 2 ] |= V_143 ;
}
static void F_94 ( struct V_59 * V_60 , T_1 V_14 , int V_144 ,
T_3 V_65 , T_6 V_134 )
{
T_3 V_136 ;
bool V_137 ;
V_136 = F_93 ( V_65 , V_134 , V_138 ) ;
V_137 = false ;
if ( V_136 > 1 ) {
V_65 = V_139 ;
V_137 = true ;
}
V_65 &= V_140 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
V_60 -> V_30 [ 0 ] |= ( V_144 & 0xff ) << 24 ;
V_60 -> V_30 [ 1 ] = V_14 ;
V_60 -> V_30 [ 2 ] = F_87 ( V_65 ) ;
V_60 -> V_30 [ 3 ] = F_89 ( V_65 ) ;
F_90 ( V_60 , V_145 ) ;
if ( V_137 )
V_60 -> V_30 [ 2 ] |= V_142 ;
}
static void F_95 ( struct V_59 * V_60 , T_1 V_62 , int V_97 ,
T_3 V_65 , bool V_134 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_65 &= ~ ( 0xfffULL ) ;
V_60 -> V_30 [ 0 ] = V_97 ;
V_60 -> V_30 [ 1 ] = V_62 ;
V_60 -> V_30 [ 2 ] = F_87 ( V_65 ) ;
V_60 -> V_30 [ 3 ] = F_89 ( V_65 ) ;
V_60 -> V_30 [ 2 ] |= V_143 ;
V_60 -> V_30 [ 2 ] |= V_146 ;
if ( V_134 )
V_60 -> V_30 [ 2 ] |= V_142 ;
F_90 ( V_60 , V_141 ) ;
}
static void F_96 ( struct V_59 * V_60 , T_1 V_14 , int V_97 ,
int V_144 , T_3 V_65 , bool V_134 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_65 &= ~ ( 0xfffULL ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
V_60 -> V_30 [ 0 ] |= ( ( V_97 >> 8 ) & 0xff ) << 16 ;
V_60 -> V_30 [ 0 ] |= ( V_144 & 0xff ) << 24 ;
V_60 -> V_30 [ 1 ] = V_14 ;
V_60 -> V_30 [ 1 ] |= ( V_97 & 0xff ) << 16 ;
V_60 -> V_30 [ 2 ] = F_87 ( V_65 ) ;
V_60 -> V_30 [ 2 ] |= V_146 ;
V_60 -> V_30 [ 3 ] = F_89 ( V_65 ) ;
if ( V_134 )
V_60 -> V_30 [ 2 ] |= V_142 ;
F_90 ( V_60 , V_145 ) ;
}
static void F_97 ( struct V_59 * V_60 , T_1 V_14 , int V_97 ,
int V_117 , int V_99 , bool V_147 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
if ( V_147 ) {
V_60 -> V_30 [ 1 ] = V_97 ;
V_60 -> V_30 [ 2 ] = V_146 ;
}
V_60 -> V_30 [ 3 ] = V_99 & 0x1ff ;
V_60 -> V_30 [ 3 ] |= ( V_117 & V_148 ) << V_149 ;
F_90 ( V_60 , V_150 ) ;
}
static void F_98 ( struct V_59 * V_60 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_90 ( V_60 , V_151 ) ;
}
static void F_99 ( struct V_59 * V_60 , T_1 V_14 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
F_90 ( V_60 , V_152 ) ;
}
static int F_100 ( struct V_52 * V_38 ,
struct V_59 * V_60 ,
bool V_153 )
{
T_2 V_154 , V_86 , V_85 , V_155 ;
V_156:
V_85 = F_60 ( V_38 -> V_87 + V_157 ) ;
V_86 = F_60 ( V_38 -> V_87 + V_130 ) ;
V_155 = ( V_86 + sizeof( * V_60 ) ) % V_129 ;
V_154 = ( V_85 - V_155 ) % V_129 ;
if ( V_154 <= 0x20 ) {
struct V_59 V_158 ;
int V_159 ;
V_38 -> V_160 = 0 ;
F_85 ( & V_158 , ( T_3 ) & V_38 -> V_160 ) ;
F_84 ( V_38 , & V_158 , V_86 ) ;
if ( ( V_159 = F_82 ( & V_38 -> V_160 ) ) != 0 )
return V_159 ;
goto V_156;
}
F_84 ( V_38 , V_60 , V_86 ) ;
V_38 -> V_161 = V_153 ;
return 0 ;
}
static int F_101 ( struct V_52 * V_38 ,
struct V_59 * V_60 ,
bool V_153 )
{
unsigned long V_21 ;
int V_159 ;
F_18 ( & V_38 -> V_162 , V_21 ) ;
V_159 = F_100 ( V_38 , V_60 , V_153 ) ;
F_20 ( & V_38 -> V_162 , V_21 ) ;
return V_159 ;
}
static int F_102 ( struct V_52 * V_38 , struct V_59 * V_60 )
{
return F_101 ( V_38 , V_60 , true ) ;
}
static int F_103 ( struct V_52 * V_38 )
{
struct V_59 V_60 ;
unsigned long V_21 ;
int V_159 ;
if ( ! V_38 -> V_161 )
return 0 ;
F_85 ( & V_60 , ( T_3 ) & V_38 -> V_160 ) ;
F_18 ( & V_38 -> V_162 , V_21 ) ;
V_38 -> V_160 = 0 ;
V_159 = F_100 ( V_38 , & V_60 , false ) ;
if ( V_159 )
goto V_28;
V_159 = F_82 ( & V_38 -> V_160 ) ;
V_28:
F_20 ( & V_38 -> V_162 , V_21 ) ;
return V_159 ;
}
static int F_104 ( struct V_52 * V_38 , T_1 V_14 )
{
struct V_59 V_60 ;
F_91 ( & V_60 , V_14 ) ;
return F_102 ( V_38 , & V_60 ) ;
}
static void F_105 ( struct V_52 * V_38 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= 0xffff ; ++ V_14 )
F_104 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
}
static void F_106 ( struct V_52 * V_38 )
{
T_2 V_163 ;
for ( V_163 = 0 ; V_163 <= 0xffff ; ++ V_163 ) {
struct V_59 V_60 ;
F_92 ( & V_60 , 0 , V_139 ,
V_163 , 1 ) ;
F_102 ( V_38 , & V_60 ) ;
}
F_103 ( V_38 ) ;
}
static void F_107 ( struct V_52 * V_38 )
{
struct V_59 V_60 ;
F_98 ( & V_60 ) ;
F_102 ( V_38 , & V_60 ) ;
F_103 ( V_38 ) ;
}
static void F_108 ( struct V_52 * V_38 , T_1 V_14 )
{
struct V_59 V_60 ;
F_99 ( & V_60 , V_14 ) ;
F_102 ( V_38 , & V_60 ) ;
}
static void F_109 ( struct V_52 * V_38 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= V_164 ; V_14 ++ )
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
}
void F_110 ( struct V_52 * V_38 )
{
if ( F_111 ( V_38 , V_165 ) ) {
F_107 ( V_38 ) ;
} else {
F_105 ( V_38 ) ;
F_109 ( V_38 ) ;
F_106 ( V_38 ) ;
}
}
static int F_112 ( struct V_23 * V_24 ,
T_3 V_65 , T_6 V_134 )
{
struct V_52 * V_38 ;
struct V_59 V_60 ;
int V_144 ;
V_144 = V_24 -> V_166 . V_144 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_94 ( & V_60 , V_24 -> V_14 , V_144 , V_65 , V_134 ) ;
return F_102 ( V_38 , & V_60 ) ;
}
static int F_113 ( struct V_23 * V_24 )
{
struct V_52 * V_38 ;
T_1 V_29 ;
int V_159 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_159 = F_104 ( V_38 , V_24 -> V_14 ) ;
if ( ! V_159 && V_29 != V_24 -> V_14 )
V_159 = F_104 ( V_38 , V_29 ) ;
if ( V_159 )
return V_159 ;
if ( V_24 -> V_166 . V_167 )
V_159 = F_112 ( V_24 , 0 , ~ 0UL ) ;
return V_159 ;
}
static void F_114 ( struct V_16 * V_19 ,
T_3 V_65 , T_6 V_134 , int V_135 )
{
struct V_23 * V_24 ;
struct V_59 V_60 ;
int V_159 = 0 , V_45 ;
F_92 ( & V_60 , V_65 , V_134 , V_19 -> V_168 , V_135 ) ;
for ( V_45 = 0 ; V_45 < V_169 ; ++ V_45 ) {
if ( ! V_19 -> V_170 [ V_45 ] )
continue;
V_159 |= F_102 ( V_171 [ V_45 ] , & V_60 ) ;
}
F_9 (dev_data, &domain->dev_list, list) {
if ( ! V_24 -> V_166 . V_167 )
continue;
V_159 |= F_112 ( V_24 , V_65 , V_134 ) ;
}
F_86 ( V_159 ) ;
}
static void F_115 ( struct V_16 * V_19 ,
T_3 V_65 , T_6 V_134 )
{
F_114 ( V_19 , V_65 , V_134 , 0 ) ;
}
static void F_116 ( struct V_16 * V_19 )
{
F_114 ( V_19 , 0 , V_139 , 0 ) ;
}
static void F_117 ( struct V_16 * V_19 )
{
F_114 ( V_19 , 0 , V_139 , 1 ) ;
}
static void F_118 ( struct V_16 * V_19 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_169 ; ++ V_45 ) {
if ( V_19 && ! V_19 -> V_170 [ V_45 ] )
continue;
F_103 ( V_171 [ V_45 ] ) ;
}
}
static void F_119 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list)
F_113 ( V_24 ) ;
}
static bool F_120 ( struct V_16 * V_19 ,
T_7 V_172 )
{
T_3 * V_173 ;
if ( V_19 -> V_174 == V_175 )
return false ;
V_173 = ( void * ) F_121 ( V_172 ) ;
if ( ! V_173 )
return false ;
* V_173 = F_122 ( V_19 -> V_174 ,
F_123 ( V_19 -> V_176 ) ) ;
V_19 -> V_176 = V_173 ;
V_19 -> V_174 += 1 ;
V_19 -> V_177 = true ;
return true ;
}
static T_3 * F_124 ( struct V_16 * V_19 ,
unsigned long V_65 ,
unsigned long V_178 ,
T_3 * * V_179 ,
T_7 V_172 )
{
int V_180 , V_181 ;
T_3 * V_173 , * V_182 ;
F_15 ( ! F_125 ( V_178 ) ) ;
while ( V_65 > F_126 ( V_19 -> V_174 ) )
F_120 ( V_19 , V_172 ) ;
V_180 = V_19 -> V_174 - 1 ;
V_173 = & V_19 -> V_176 [ F_127 ( V_180 , V_65 ) ] ;
V_65 = F_128 ( V_65 , V_178 ) ;
V_181 = F_129 ( V_178 ) ;
while ( V_180 > V_181 ) {
T_3 V_183 , V_184 ;
V_183 = * V_173 ;
if ( ! F_130 ( V_183 ) ) {
V_182 = ( T_3 * ) F_121 ( V_172 ) ;
if ( ! V_182 )
return NULL ;
V_184 = F_122 ( V_180 , F_123 ( V_182 ) ) ;
if ( F_131 ( V_173 , V_183 , V_184 ) != V_183 ) {
F_132 ( ( unsigned long ) V_182 ) ;
continue;
}
}
if ( F_133 ( * V_173 ) != V_180 )
return NULL ;
V_180 -= 1 ;
V_173 = F_134 ( * V_173 ) ;
if ( V_179 && V_180 == V_181 )
* V_179 = V_173 ;
V_173 = & V_173 [ F_127 ( V_180 , V_65 ) ] ;
}
return V_173 ;
}
static T_3 * F_135 ( struct V_16 * V_19 ,
unsigned long V_65 ,
unsigned long * V_178 )
{
int V_180 ;
T_3 * V_173 ;
if ( V_65 > F_126 ( V_19 -> V_174 ) )
return NULL ;
V_180 = V_19 -> V_174 - 1 ;
V_173 = & V_19 -> V_176 [ F_127 ( V_180 , V_65 ) ] ;
* V_178 = F_136 ( V_180 ) ;
while ( V_180 > 0 ) {
if ( ! F_130 ( * V_173 ) )
return NULL ;
if ( F_133 ( * V_173 ) == 7 ||
F_133 ( * V_173 ) == 0 )
break;
if ( F_133 ( * V_173 ) != V_180 )
return NULL ;
V_180 -= 1 ;
V_173 = F_134 ( * V_173 ) ;
V_173 = & V_173 [ F_127 ( V_180 , V_65 ) ] ;
* V_178 = F_136 ( V_180 ) ;
}
if ( F_133 ( * V_173 ) == 0x07 ) {
unsigned long V_185 ;
* V_178 = V_185 = F_137 ( * V_173 ) ;
V_185 = ~ ( ( F_138 ( V_185 ) << 3 ) - 1 ) ;
V_173 = ( T_3 * ) ( ( ( unsigned long ) V_173 ) & V_185 ) ;
}
return V_173 ;
}
static int F_139 ( struct V_16 * V_18 ,
unsigned long V_186 ,
unsigned long V_58 ,
unsigned long V_178 ,
int V_187 ,
T_7 V_172 )
{
T_3 V_183 , * V_173 ;
int V_45 , V_64 ;
F_15 ( ! F_140 ( V_186 , V_178 ) ) ;
F_15 ( ! F_140 ( V_58 , V_178 ) ) ;
if ( ! ( V_187 & V_188 ) )
return - V_15 ;
V_64 = F_138 ( V_178 ) ;
V_173 = F_124 ( V_18 , V_186 , V_178 , NULL , V_172 ) ;
if ( ! V_173 )
return - V_51 ;
for ( V_45 = 0 ; V_45 < V_64 ; ++ V_45 )
if ( F_130 ( V_173 [ V_45 ] ) )
return - V_189 ;
if ( V_64 > 1 ) {
V_183 = F_141 ( V_58 , V_178 ) ;
V_183 |= F_142 ( 7 ) | V_190 | V_191 ;
} else
V_183 = V_58 | V_190 | V_191 ;
if ( V_187 & V_192 )
V_183 |= V_193 ;
if ( V_187 & V_194 )
V_183 |= V_195 ;
for ( V_45 = 0 ; V_45 < V_64 ; ++ V_45 )
V_173 [ V_45 ] = V_183 ;
F_143 ( V_18 ) ;
return 0 ;
}
static unsigned long F_144 ( struct V_16 * V_18 ,
unsigned long V_186 ,
unsigned long V_178 )
{
unsigned long long V_196 ;
unsigned long V_197 ;
T_3 * V_173 ;
F_15 ( ! F_125 ( V_178 ) ) ;
V_196 = 0 ;
while ( V_196 < V_178 ) {
V_173 = F_135 ( V_18 , V_186 , & V_197 ) ;
if ( V_173 ) {
int V_45 , V_64 ;
V_64 = F_138 ( V_197 ) ;
for ( V_45 = 0 ; V_45 < V_64 ; V_45 ++ )
V_173 [ V_45 ] = 0ULL ;
}
V_186 = ( V_186 & ~ ( V_197 - 1 ) ) + V_197 ;
V_196 += V_197 ;
}
F_15 ( V_196 && ! F_125 ( V_196 ) ) ;
return V_196 ;
}
static unsigned long F_145 ( struct V_1 * V_2 ,
struct V_20 * V_198 ,
unsigned int V_136 , T_3 V_49 )
{
unsigned long V_199 = 0 ;
V_136 = F_146 ( V_136 ) ;
if ( V_49 > F_147 ( 32 ) )
V_199 = F_148 ( & V_198 -> V_200 , V_136 ,
F_149 ( F_147 ( 32 ) ) ) ;
if ( ! V_199 )
V_199 = F_148 ( & V_198 -> V_200 , V_136 , F_149 ( V_49 ) ) ;
return ( V_199 << V_201 ) ;
}
static void F_150 ( struct V_20 * V_198 ,
unsigned long V_65 ,
unsigned int V_136 )
{
V_136 = F_146 ( V_136 ) ;
V_65 >>= V_201 ;
F_151 ( & V_198 -> V_200 , V_65 , V_136 ) ;
}
static void F_152 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_202 , V_21 ) ;
F_153 ( & V_19 -> V_203 , & V_204 ) ;
F_20 ( & V_202 , V_21 ) ;
}
static void F_154 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_202 , V_21 ) ;
F_155 ( & V_19 -> V_203 ) ;
F_20 ( & V_202 , V_21 ) ;
}
static T_1 F_156 ( void )
{
unsigned long V_21 ;
int V_168 ;
F_157 ( & V_205 , V_21 ) ;
V_168 = F_158 ( V_206 , V_207 ) ;
F_15 ( V_168 == 0 ) ;
if ( V_168 > 0 && V_168 < V_207 )
F_159 ( V_168 , V_206 ) ;
else
V_168 = 0 ;
F_160 ( & V_205 , V_21 ) ;
return V_168 ;
}
static void F_161 ( int V_168 )
{
unsigned long V_21 ;
F_157 ( & V_205 , V_21 ) ;
if ( V_168 > 0 && V_168 < V_207 )
F_162 ( V_168 , V_206 ) ;
F_160 ( & V_205 , V_21 ) ;
}
static void F_163 ( struct V_16 * V_19 )
{
unsigned long V_208 = ( unsigned long ) V_19 -> V_176 ;
switch ( V_19 -> V_174 ) {
case V_209 :
break;
case V_210 :
F_132 ( V_208 ) ;
break;
case V_211 :
F_164 ( V_208 ) ;
break;
case V_212 :
F_165 ( V_208 ) ;
break;
case V_213 :
F_166 ( V_208 ) ;
break;
case V_214 :
F_167 ( V_208 ) ;
break;
case V_175 :
F_168 ( V_208 ) ;
break;
default:
F_169 () ;
}
}
static void F_170 ( T_3 * V_215 )
{
T_3 * V_216 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 512 ; ++ V_45 ) {
if ( ! ( V_215 [ V_45 ] & V_217 ) )
continue;
V_216 = F_171 ( V_215 [ V_45 ] & V_140 ) ;
F_132 ( ( unsigned long ) V_216 ) ;
}
}
static void F_172 ( T_3 * V_215 )
{
T_3 * V_216 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 512 ; ++ V_45 ) {
if ( ! ( V_215 [ V_45 ] & V_217 ) )
continue;
V_216 = F_171 ( V_215 [ V_45 ] & V_140 ) ;
F_170 ( V_216 ) ;
}
}
static void F_173 ( struct V_16 * V_19 )
{
if ( V_19 -> V_218 == 2 )
F_172 ( V_19 -> V_219 ) ;
else if ( V_19 -> V_218 == 1 )
F_170 ( V_19 -> V_219 ) ;
else
F_15 ( V_19 -> V_218 != 0 ) ;
F_132 ( ( unsigned long ) V_19 -> V_219 ) ;
}
static void F_174 ( struct V_20 * V_18 )
{
if ( ! V_18 )
return;
F_154 ( & V_18 -> V_19 ) ;
F_175 ( & V_18 -> V_200 ) ;
F_163 ( & V_18 -> V_19 ) ;
if ( V_18 -> V_19 . V_168 )
F_161 ( V_18 -> V_19 . V_168 ) ;
F_176 ( V_18 ) ;
}
static struct V_20 * F_177 ( void )
{
struct V_20 * V_198 ;
V_198 = F_17 ( sizeof( struct V_20 ) , V_25 ) ;
if ( ! V_198 )
return NULL ;
if ( F_178 ( & V_198 -> V_19 ) )
goto V_220;
V_198 -> V_19 . V_174 = V_212 ;
V_198 -> V_19 . V_176 = ( void * ) F_121 ( V_25 ) ;
V_198 -> V_19 . V_21 = V_22 ;
if ( ! V_198 -> V_19 . V_176 )
goto V_220;
F_179 ( & V_198 -> V_200 , V_138 ,
V_221 , V_222 ) ;
F_180 ( & V_223 , & V_198 -> V_200 ) ;
F_152 ( & V_198 -> V_19 ) ;
return V_198 ;
V_220:
F_174 ( V_198 ) ;
return NULL ;
}
static bool V_20 ( struct V_16 * V_19 )
{
return V_19 -> V_21 & V_22 ;
}
static void F_181 ( T_1 V_14 , struct V_16 * V_19 , bool V_166 )
{
T_3 V_224 = 0 ;
T_3 V_21 = 0 ;
if ( V_19 -> V_174 != V_209 )
V_224 = F_123 ( V_19 -> V_176 ) ;
V_224 |= ( V_19 -> V_174 & V_225 )
<< V_226 ;
V_224 |= V_193 | V_195 | V_190 | V_227 ;
V_21 = V_35 [ V_14 ] . V_30 [ 1 ] ;
if ( V_166 )
V_21 |= V_228 ;
if ( V_19 -> V_21 & V_229 ) {
T_3 V_230 = F_88 ( V_19 -> V_219 ) ;
T_3 V_218 = V_19 -> V_218 ;
T_3 V_231 ;
V_224 |= V_232 ;
V_224 |= ( V_218 & V_233 ) << V_234 ;
V_231 = F_182 ( ~ 0ULL ) << V_235 ;
V_21 &= ~ V_231 ;
V_231 = F_183 ( ~ 0ULL ) << V_236 ;
V_21 &= ~ V_231 ;
V_231 = F_184 ( V_230 ) << V_237 ;
V_224 |= V_231 ;
V_231 = F_182 ( V_230 ) << V_235 ;
V_21 |= V_231 ;
V_231 = F_183 ( V_230 ) << V_236 ;
V_21 |= V_231 ;
}
V_21 &= ~ ( 0xffffUL ) ;
V_21 |= V_19 -> V_168 ;
V_35 [ V_14 ] . V_30 [ 1 ] = V_21 ;
V_35 [ V_14 ] . V_30 [ 0 ] = V_224 ;
}
static void F_185 ( T_1 V_14 )
{
V_35 [ V_14 ] . V_30 [ 0 ] = V_190 | V_227 ;
V_35 [ V_14 ] . V_30 [ 1 ] &= V_238 ;
F_186 ( V_14 ) ;
}
static void F_187 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
struct V_52 * V_38 ;
T_1 V_29 ;
bool V_166 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_166 = V_24 -> V_166 . V_167 ;
V_24 -> V_19 = V_19 ;
F_153 ( & V_24 -> V_203 , & V_19 -> V_239 ) ;
V_19 -> V_170 [ V_38 -> V_240 ] += 1 ;
V_19 -> V_241 += 1 ;
F_181 ( V_24 -> V_14 , V_19 , V_166 ) ;
if ( V_29 != V_24 -> V_14 )
F_181 ( V_29 , V_19 , V_166 ) ;
F_113 ( V_24 ) ;
}
static void F_188 ( struct V_23 * V_24 )
{
struct V_52 * V_38 ;
T_1 V_29 ;
if ( ! V_24 -> V_19 )
return;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_24 -> V_19 -> V_170 [ V_38 -> V_240 ] -= 1 ;
V_24 -> V_19 -> V_241 -= 1 ;
V_24 -> V_19 = NULL ;
F_155 ( & V_24 -> V_203 ) ;
F_185 ( V_24 -> V_14 ) ;
if ( V_29 != V_24 -> V_14 )
F_185 ( V_29 ) ;
F_113 ( V_24 ) ;
}
static int F_189 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
int V_159 ;
F_86 ( ! F_190 () ) ;
F_191 ( & V_19 -> V_162 ) ;
V_159 = - V_189 ;
if ( V_24 -> V_19 != NULL )
goto V_28;
F_187 ( V_24 , V_19 ) ;
V_159 = 0 ;
V_28:
F_192 ( & V_19 -> V_162 ) ;
return V_159 ;
}
static void F_193 ( struct V_8 * V_9 )
{
F_194 ( V_9 ) ;
F_195 ( V_9 ) ;
F_196 ( V_9 ) ;
}
static int F_197 ( struct V_8 * V_9 )
{
T_1 V_242 ;
int V_46 ;
V_46 = F_38 ( V_9 , V_43 ) ;
if ( ! V_46 )
return - V_15 ;
F_198 ( V_9 , V_46 + V_243 , & V_242 ) ;
V_242 |= V_244 ;
F_199 ( V_9 , V_46 + V_243 , V_242 ) ;
return 0 ;
}
static int F_200 ( struct V_8 * V_9 )
{
bool V_245 ;
int V_246 , V_159 ;
V_246 = 32 ;
if ( F_39 ( V_9 , V_247 ) )
V_246 = 1 ;
V_245 = F_39 ( V_9 , V_248 ) ;
V_159 = F_201 ( V_9 , 0 ) ;
if ( V_159 )
goto V_249;
V_159 = F_202 ( V_9 ) ;
if ( V_159 )
goto V_249;
V_159 = F_203 ( V_9 , V_246 ) ;
if ( V_159 )
goto V_249;
if ( V_245 ) {
V_159 = F_197 ( V_9 ) ;
if ( V_159 )
goto V_249;
}
V_159 = F_204 ( V_9 , V_201 ) ;
if ( V_159 )
goto V_249;
return 0 ;
V_249:
F_195 ( V_9 ) ;
F_196 ( V_9 ) ;
return V_159 ;
}
static bool F_205 ( struct V_8 * V_9 )
{
T_1 V_117 ;
int V_46 ;
V_46 = F_38 ( V_9 , V_43 ) ;
if ( ! V_46 )
return false ;
F_198 ( V_9 , V_46 + V_250 , & V_117 ) ;
return ( V_117 & V_251 ) ? true : false ;
}
static int F_206 ( struct V_1 * V_2 ,
struct V_16 * V_19 )
{
struct V_8 * V_9 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
int V_159 ;
V_24 = F_32 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
goto V_252;
V_9 = F_6 ( V_2 ) ;
if ( V_19 -> V_21 & V_229 ) {
if ( ! V_24 -> V_253 )
return - V_15 ;
if ( V_24 -> V_53 ) {
if ( F_200 ( V_9 ) != 0 )
return - V_15 ;
V_24 -> V_166 . V_167 = true ;
V_24 -> V_166 . V_144 = F_207 ( V_9 ) ;
V_24 -> V_254 = F_205 ( V_9 ) ;
}
} else if ( V_255 &&
F_204 ( V_9 , V_201 ) == 0 ) {
V_24 -> V_166 . V_167 = true ;
V_24 -> V_166 . V_144 = F_207 ( V_9 ) ;
}
V_252:
F_157 ( & V_205 , V_21 ) ;
V_159 = F_189 ( V_24 , V_19 ) ;
F_160 ( & V_205 , V_21 ) ;
F_117 ( V_19 ) ;
return V_159 ;
}
static void F_208 ( struct V_23 * V_24 )
{
struct V_16 * V_19 ;
F_86 ( ! F_190 () ) ;
if ( F_86 ( ! V_24 -> V_19 ) )
return;
V_19 = V_24 -> V_19 ;
F_191 ( & V_19 -> V_162 ) ;
F_188 ( V_24 ) ;
F_192 ( & V_19 -> V_162 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
V_24 = F_32 ( V_2 ) ;
V_19 = V_24 -> V_19 ;
F_157 ( & V_205 , V_21 ) ;
F_208 ( V_24 ) ;
F_160 ( & V_205 , V_21 ) ;
if ( ! F_11 ( V_2 ) )
return;
if ( V_19 -> V_21 & V_229 && V_24 -> V_53 )
F_193 ( F_6 ( V_2 ) ) ;
else if ( V_24 -> V_166 . V_167 )
F_194 ( F_6 ( V_2 ) ) ;
V_24 -> V_166 . V_167 = false ;
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_17 * V_19 ;
struct V_52 * V_38 ;
int V_159 , V_14 ;
if ( ! F_40 ( V_2 ) || F_32 ( V_2 ) )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_38 = V_34 [ V_14 ] ;
V_159 = F_45 ( V_2 ) ;
if ( V_159 ) {
if ( V_159 != - V_256 )
F_53 ( L_29 ,
F_29 ( V_2 ) ) ;
F_47 ( V_2 ) ;
V_2 -> V_37 . V_57 = & V_257 ;
goto V_258;
}
F_41 ( V_2 ) ;
V_24 = F_32 ( V_2 ) ;
F_15 ( ! V_24 ) ;
if ( V_259 || V_24 -> V_53 )
F_210 ( V_2 ) ;
V_19 = F_211 ( V_2 ) ;
if ( V_19 -> type == V_260 )
V_24 -> V_253 = true ;
else
V_2 -> V_37 . V_57 = & V_261 ;
V_258:
F_103 ( V_38 ) ;
return 0 ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_52 * V_38 ;
int V_14 ;
if ( ! F_40 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_38 = V_34 [ V_14 ] ;
F_48 ( V_2 ) ;
F_103 ( V_38 ) ;
}
static struct V_39 * F_213 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) )
return F_214 ( V_2 ) ;
return F_33 ( V_2 ) ;
}
static void F_215 ( struct V_262 * V_263 )
{
struct V_16 * V_19 ;
unsigned long V_21 ;
int V_264 ;
F_18 ( & V_202 , V_21 ) ;
F_9 (domain, &amd_iommu_pd_list, list)
F_116 ( V_19 ) ;
F_20 ( & V_202 , V_21 ) ;
F_118 ( NULL ) ;
for ( V_264 = 0 ; V_264 < V_263 -> V_265 ; ++ V_264 ) {
struct V_266 * V_4 ;
V_4 = V_263 -> V_267 + V_264 ;
F_151 ( & V_4 -> V_198 -> V_200 ,
V_4 -> V_268 ,
V_4 -> V_136 ) ;
V_4 -> V_198 = NULL ;
}
V_263 -> V_265 = 0 ;
}
static void F_216 ( void )
{
int V_269 ;
F_217 (cpu) {
struct V_262 * V_263 ;
unsigned long V_21 ;
V_263 = F_218 ( & V_262 , V_269 ) ;
F_18 ( & V_263 -> V_162 , V_21 ) ;
if ( V_263 -> V_265 > 0 )
F_215 ( V_263 ) ;
F_20 ( & V_263 -> V_162 , V_21 ) ;
}
}
static void F_219 ( unsigned long V_270 )
{
F_220 ( & V_271 , 0 ) ;
F_216 () ;
}
static void F_221 ( struct V_20 * V_198 ,
unsigned long V_65 , unsigned long V_136 )
{
struct V_266 * V_4 ;
struct V_262 * V_263 ;
unsigned long V_21 ;
int V_264 ;
V_136 = F_146 ( V_136 ) ;
V_65 >>= V_201 ;
V_263 = F_222 ( & V_262 ) ;
F_18 ( & V_263 -> V_162 , V_21 ) ;
if ( V_263 -> V_265 == V_272 )
F_215 ( V_263 ) ;
V_264 = V_263 -> V_265 ++ ;
V_4 = V_263 -> V_267 + V_264 ;
V_4 -> V_268 = V_65 ;
V_4 -> V_136 = V_136 ;
V_4 -> V_198 = V_198 ;
F_20 ( & V_263 -> V_162 , V_21 ) ;
if ( F_223 ( & V_271 , 0 , 1 ) == 0 )
F_224 ( & V_273 , V_274 + F_225 ( 10 ) ) ;
F_226 ( & V_262 ) ;
}
static struct V_16 * F_227 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
if ( ! F_40 ( V_2 ) )
return F_34 ( - V_15 ) ;
V_19 = F_32 ( V_2 ) -> V_19 ;
if ( ! V_20 ( V_19 ) )
return F_34 ( - V_189 ) ;
return V_19 ;
}
static void F_228 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list) {
F_181 ( V_24 -> V_14 , V_19 , V_24 -> V_166 . V_167 ) ;
if ( V_24 -> V_14 == V_24 -> V_29 )
continue;
F_181 ( V_24 -> V_29 , V_19 , V_24 -> V_166 . V_167 ) ;
}
}
static void F_143 ( struct V_16 * V_19 )
{
if ( ! V_19 -> V_177 )
return;
F_228 ( V_19 ) ;
F_119 ( V_19 ) ;
F_117 ( V_19 ) ;
V_19 -> V_177 = false ;
}
static int F_229 ( enum V_275 V_276 )
{
if ( V_276 == V_277 )
return V_192 ;
else if ( V_276 == V_278 )
return V_194 ;
else if ( V_276 == V_279 )
return V_194 | V_192 ;
else
return 0 ;
}
static T_8 F_230 ( struct V_1 * V_2 ,
struct V_20 * V_198 ,
T_9 V_280 ,
T_6 V_134 ,
enum V_275 V_276 ,
T_3 V_49 )
{
T_8 V_281 = V_280 & ~ V_140 ;
T_8 V_65 , V_282 , V_159 ;
unsigned int V_136 ;
int V_187 = 0 ;
int V_45 ;
V_136 = F_93 ( V_280 , V_134 , V_138 ) ;
V_280 &= V_140 ;
V_65 = F_145 ( V_2 , V_198 , V_136 , V_49 ) ;
if ( V_65 == V_283 )
goto V_258;
V_187 = F_229 ( V_276 ) ;
V_282 = V_65 ;
for ( V_45 = 0 ; V_45 < V_136 ; ++ V_45 ) {
V_159 = F_139 ( & V_198 -> V_19 , V_282 , V_280 ,
V_138 , V_187 , V_284 ) ;
if ( V_159 )
goto V_285;
V_280 += V_138 ;
V_282 += V_138 ;
}
V_65 += V_281 ;
if ( F_231 ( V_286 ) ) {
F_115 ( & V_198 -> V_19 , V_65 , V_134 ) ;
F_118 ( & V_198 -> V_19 ) ;
}
V_258:
return V_65 ;
V_285:
for ( -- V_45 ; V_45 >= 0 ; -- V_45 ) {
V_282 -= V_138 ;
F_144 ( & V_198 -> V_19 , V_282 , V_138 ) ;
}
F_116 ( & V_198 -> V_19 ) ;
F_118 ( & V_198 -> V_19 ) ;
F_150 ( V_198 , V_65 , V_136 ) ;
return V_283 ;
}
static void F_232 ( struct V_20 * V_198 ,
T_8 V_287 ,
T_6 V_134 ,
int V_288 )
{
T_8 V_289 ;
T_8 V_45 , V_282 ;
unsigned int V_136 ;
V_289 = V_287 ;
V_136 = F_93 ( V_287 , V_134 , V_138 ) ;
V_287 &= V_140 ;
V_282 = V_287 ;
for ( V_45 = 0 ; V_45 < V_136 ; ++ V_45 ) {
F_144 ( & V_198 -> V_19 , V_282 , V_138 ) ;
V_282 += V_138 ;
}
if ( V_290 ) {
F_150 ( V_198 , V_287 , V_136 ) ;
F_116 ( & V_198 -> V_19 ) ;
F_118 ( & V_198 -> V_19 ) ;
} else {
F_221 ( V_198 , V_287 , V_136 ) ;
}
}
static T_8 F_233 ( struct V_1 * V_2 , struct V_182 * V_182 ,
unsigned long V_281 , T_6 V_134 ,
enum V_275 V_288 ,
unsigned long V_291 )
{
T_9 V_280 = F_234 ( V_182 ) + V_281 ;
struct V_16 * V_19 ;
struct V_20 * V_198 ;
T_3 V_49 ;
V_19 = F_227 ( V_2 ) ;
if ( F_235 ( V_19 ) == - V_15 )
return ( T_8 ) V_280 ;
else if ( F_43 ( V_19 ) )
return V_283 ;
V_49 = * V_2 -> V_49 ;
V_198 = F_14 ( V_19 ) ;
return F_230 ( V_2 , V_198 , V_280 , V_134 , V_288 , V_49 ) ;
}
static void F_236 ( struct V_1 * V_2 , T_8 V_287 , T_6 V_134 ,
enum V_275 V_288 , unsigned long V_291 )
{
struct V_16 * V_19 ;
struct V_20 * V_198 ;
V_19 = F_227 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return;
V_198 = F_14 ( V_19 ) ;
F_232 ( V_198 , V_287 , V_134 , V_288 ) ;
}
static int F_237 ( struct V_1 * V_2 ,
struct V_292 * V_293 ,
int V_294 )
{
unsigned long V_295 , V_296 ;
struct V_292 * V_137 ;
int V_45 , V_297 = 0 ;
V_295 = F_238 ( V_2 ) ;
V_296 = V_295 + 1 ? F_239 ( V_295 + 1 , V_138 ) >> V_201 :
1UL << ( V_298 - V_201 ) ;
F_240 (sglist, s, nelems, i) {
int V_13 , V_299 ;
V_137 -> V_300 = V_297 << V_201 ;
V_13 = V_297 % V_296 ;
V_299 = F_93 ( F_241 ( V_137 ) , V_137 -> V_301 , V_138 ) ;
if ( V_13 + V_299 > V_296 )
V_297 += V_296 - V_13 ;
V_297 += V_299 ;
}
return V_297 ;
}
static int F_242 ( struct V_1 * V_2 , struct V_292 * V_293 ,
int V_294 , enum V_275 V_276 ,
unsigned long V_291 )
{
int V_302 = 0 , V_297 = 0 , V_187 = 0 , V_45 ;
struct V_16 * V_19 ;
struct V_20 * V_198 ;
struct V_292 * V_137 ;
unsigned long V_65 ;
T_3 V_49 ;
V_19 = F_227 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return 0 ;
V_198 = F_14 ( V_19 ) ;
V_49 = * V_2 -> V_49 ;
V_297 = F_237 ( V_2 , V_293 , V_294 ) ;
V_65 = F_145 ( V_2 , V_198 , V_297 , V_49 ) ;
if ( V_65 == V_283 )
goto V_249;
V_187 = F_229 ( V_276 ) ;
F_240 (sglist, s, nelems, i) {
int V_303 , V_136 = F_93 ( F_241 ( V_137 ) , V_137 -> V_301 , V_138 ) ;
for ( V_303 = 0 ; V_303 < V_136 ; ++ V_303 ) {
unsigned long V_186 , V_58 ;
int V_159 ;
V_186 = V_65 + V_137 -> V_300 + ( V_303 << V_201 ) ;
V_58 = ( F_241 ( V_137 ) & V_140 ) + ( V_303 << V_201 ) ;
V_159 = F_139 ( V_19 , V_186 , V_58 , V_138 , V_187 , V_284 ) ;
if ( V_159 )
goto V_285;
V_302 += 1 ;
}
}
F_240 (sglist, s, nelems, i) {
V_137 -> V_300 += V_65 + V_137 -> V_281 ;
V_137 -> V_304 = V_137 -> V_301 ;
}
return V_294 ;
V_285:
F_53 ( L_30 ,
F_29 ( V_2 ) , V_297 ) ;
F_240 (sglist, s, nelems, i) {
int V_303 , V_136 = F_93 ( F_241 ( V_137 ) , V_137 -> V_301 , V_138 ) ;
for ( V_303 = 0 ; V_303 < V_136 ; ++ V_303 ) {
unsigned long V_186 ;
V_186 = V_65 + V_137 -> V_300 + ( V_303 << V_201 ) ;
F_144 ( V_19 , V_186 , V_138 ) ;
if ( -- V_302 )
goto V_305;
}
}
V_305:
F_151 ( & V_198 -> V_200 , V_65 , V_297 ) ;
V_249:
return 0 ;
}
static void F_243 ( struct V_1 * V_2 , struct V_292 * V_293 ,
int V_294 , enum V_275 V_288 ,
unsigned long V_291 )
{
struct V_16 * V_19 ;
struct V_20 * V_198 ;
unsigned long V_306 ;
int V_297 = 2 ;
V_19 = F_227 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return;
V_306 = F_244 ( V_293 ) & V_140 ;
V_198 = F_14 ( V_19 ) ;
V_297 = F_237 ( V_2 , V_293 , V_294 ) ;
F_232 ( V_198 , V_306 , V_297 << V_201 , V_288 ) ;
}
static void * F_245 ( struct V_1 * V_2 , T_6 V_134 ,
T_8 * V_287 , T_7 V_307 ,
unsigned long V_291 )
{
T_3 V_49 = V_2 -> V_308 ;
struct V_16 * V_19 ;
struct V_20 * V_198 ;
struct V_182 * V_182 ;
V_19 = F_227 ( V_2 ) ;
if ( F_235 ( V_19 ) == - V_15 ) {
V_182 = F_246 ( V_307 , F_247 ( V_134 ) ) ;
* V_287 = F_234 ( V_182 ) ;
return F_248 ( V_182 ) ;
} else if ( F_43 ( V_19 ) )
return NULL ;
V_198 = F_14 ( V_19 ) ;
V_134 = F_249 ( V_134 ) ;
V_49 = V_2 -> V_308 ;
V_307 &= ~ ( V_309 | V_310 | V_311 ) ;
V_307 |= V_312 ;
V_182 = F_246 ( V_307 | V_313 , F_247 ( V_134 ) ) ;
if ( ! V_182 ) {
if ( ! F_250 ( V_307 ) )
return NULL ;
V_182 = F_251 ( V_2 , V_134 >> V_201 ,
F_247 ( V_134 ) ) ;
if ( ! V_182 )
return NULL ;
}
if ( ! V_49 )
V_49 = * V_2 -> V_49 ;
* V_287 = F_230 ( V_2 , V_198 , F_234 ( V_182 ) ,
V_134 , V_279 , V_49 ) ;
if ( * V_287 == V_283 )
goto V_314;
return F_248 ( V_182 ) ;
V_314:
if ( ! F_252 ( V_2 , V_182 , V_134 >> V_201 ) )
F_253 ( V_182 , F_247 ( V_134 ) ) ;
return NULL ;
}
static void F_254 ( struct V_1 * V_2 , T_6 V_134 ,
void * V_315 , T_8 V_287 ,
unsigned long V_291 )
{
struct V_16 * V_19 ;
struct V_20 * V_198 ;
struct V_182 * V_182 ;
V_182 = F_255 ( V_315 ) ;
V_134 = F_249 ( V_134 ) ;
V_19 = F_227 ( V_2 ) ;
if ( F_43 ( V_19 ) )
goto V_316;
V_198 = F_14 ( V_19 ) ;
F_232 ( V_198 , V_287 , V_134 , V_279 ) ;
V_316:
if ( ! F_252 ( V_2 , V_182 , V_134 >> V_201 ) )
F_253 ( V_182 , F_247 ( V_134 ) ) ;
}
static int F_256 ( struct V_1 * V_2 , T_3 V_295 )
{
return F_40 ( V_2 ) ;
}
static int F_257 ( void )
{
struct V_8 * V_9 = NULL ;
struct V_317 * V_318 ;
F_179 ( & V_223 , V_138 ,
V_221 , V_222 ) ;
F_258 ( & V_223 . V_319 ,
& V_320 ) ;
V_318 = F_259 ( & V_223 ,
F_149 ( V_321 ) , F_149 ( V_322 ) ) ;
if ( ! V_318 ) {
F_53 ( L_31 ) ;
return - V_51 ;
}
V_318 = F_259 ( & V_223 ,
F_149 ( V_323 ) , F_149 ( V_324 ) ) ;
if ( ! V_318 ) {
F_53 ( L_32 ) ;
return - V_51 ;
}
F_260 (pdev) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_325 ; ++ V_45 ) {
struct V_326 * V_327 = & V_9 -> V_326 [ V_45 ] ;
if ( ! ( V_327 -> V_21 & V_328 ) )
continue;
V_318 = F_259 ( & V_223 ,
F_149 ( V_327 -> V_282 ) ,
F_149 ( V_327 -> V_329 ) ) ;
if ( ! V_318 ) {
F_53 ( L_33 ) ;
return - V_51 ;
}
}
}
return 0 ;
}
int T_10 F_261 ( void )
{
int V_159 , V_269 , V_330 = 0 ;
V_159 = F_262 () ;
if ( V_159 )
return V_159 ;
V_159 = F_257 () ;
if ( V_159 )
return V_159 ;
F_217 (cpu) {
struct V_262 * V_263 = F_218 ( & V_262 , V_269 ) ;
V_263 -> V_267 = F_17 ( V_272 *
sizeof( * V_263 -> V_267 ) ,
V_25 ) ;
if ( ! V_263 -> V_267 )
goto V_331;
F_263 ( & V_263 -> V_162 ) ;
}
V_330 = F_264 ( & V_332 , & V_333 ) ;
if ( V_330 )
return V_330 ;
#ifdef F_265
V_330 = F_264 ( & V_334 , & V_333 ) ;
if ( V_330 )
return V_330 ;
#endif
V_330 = F_264 ( & V_335 , & V_333 ) ;
if ( V_330 )
return V_330 ;
return 0 ;
V_331:
F_217 (cpu) {
struct V_262 * V_263 = F_218 ( & V_262 , V_269 ) ;
F_176 ( V_263 -> V_267 ) ;
}
return - V_51 ;
}
int T_10 F_266 ( void )
{
F_267 ( & V_273 , F_219 , 0 ) ;
F_220 ( & V_271 , 0 ) ;
V_336 = V_259 ? 1 : 0 ;
V_337 = 1 ;
if ( ! V_336 )
V_57 = & V_257 ;
if ( V_290 )
F_25 ( L_34 ) ;
else
F_25 ( L_35 ) ;
return 0 ;
}
static void F_268 ( struct V_16 * V_19 )
{
struct V_23 * V_4 ;
unsigned long V_21 ;
F_157 ( & V_205 , V_21 ) ;
while ( ! F_269 ( & V_19 -> V_239 ) ) {
V_4 = F_270 ( & V_19 -> V_239 ,
struct V_23 , V_203 ) ;
F_208 ( V_4 ) ;
}
F_160 ( & V_205 , V_21 ) ;
}
static void F_271 ( struct V_16 * V_19 )
{
if ( ! V_19 )
return;
F_154 ( V_19 ) ;
if ( V_19 -> V_168 )
F_161 ( V_19 -> V_168 ) ;
F_176 ( V_19 ) ;
}
static int F_178 ( struct V_16 * V_19 )
{
F_263 ( & V_19 -> V_162 ) ;
F_272 ( & V_19 -> V_338 ) ;
V_19 -> V_168 = F_156 () ;
if ( ! V_19 -> V_168 )
return - V_51 ;
F_273 ( & V_19 -> V_239 ) ;
return 0 ;
}
static struct V_16 * F_274 ( void )
{
struct V_16 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_25 ) ;
if ( ! V_19 )
return NULL ;
if ( F_178 ( V_19 ) )
goto V_249;
F_152 ( V_19 ) ;
return V_19 ;
V_249:
F_176 ( V_19 ) ;
return NULL ;
}
static struct V_17 * F_275 ( unsigned type )
{
struct V_16 * V_339 ;
struct V_20 * V_340 ;
switch ( type ) {
case V_341 :
V_339 = F_274 () ;
if ( ! V_339 )
return NULL ;
V_339 -> V_174 = V_212 ;
V_339 -> V_176 = ( void * ) F_121 ( V_25 ) ;
if ( ! V_339 -> V_176 ) {
F_271 ( V_339 ) ;
return NULL ;
}
V_339 -> V_19 . V_342 . V_343 = 0 ;
V_339 -> V_19 . V_342 . V_344 = ~ 0ULL ;
V_339 -> V_19 . V_342 . V_345 = true ;
break;
case V_346 :
V_340 = F_177 () ;
if ( ! V_340 ) {
F_53 ( L_36 ) ;
return NULL ;
}
V_339 = & V_340 -> V_19 ;
break;
case V_260 :
V_339 = F_274 () ;
if ( ! V_339 )
return NULL ;
V_339 -> V_174 = V_209 ;
break;
default:
return NULL ;
}
return & V_339 -> V_19 ;
}
static void F_276 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
struct V_20 * V_198 ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 -> V_241 > 0 )
F_268 ( V_19 ) ;
F_15 ( V_19 -> V_241 != 0 ) ;
if ( ! V_18 )
return;
switch ( V_18 -> type ) {
case V_346 :
F_216 () ;
V_198 = F_14 ( V_19 ) ;
F_174 ( V_198 ) ;
break;
default:
if ( V_19 -> V_174 != V_209 )
F_163 ( V_19 ) ;
if ( V_19 -> V_21 & V_229 )
F_173 ( V_19 ) ;
F_271 ( V_19 ) ;
break;
}
}
static void F_277 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_37 . V_38 ;
struct V_52 * V_38 ;
int V_14 ;
if ( ! F_40 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
if ( V_24 -> V_19 != NULL )
F_49 ( V_2 ) ;
V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return;
#ifdef F_80
if ( F_278 ( V_347 ) &&
( V_18 -> type == V_341 ) )
V_24 -> V_348 = 0 ;
#endif
F_103 ( V_38 ) ;
}
static int F_279 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
struct V_23 * V_24 ;
struct V_52 * V_38 ;
int V_159 ;
if ( ! F_40 ( V_2 ) )
return - V_15 ;
V_24 = V_2 -> V_37 . V_38 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
if ( ! V_38 )
return - V_15 ;
if ( V_24 -> V_19 )
F_49 ( V_2 ) ;
V_159 = F_206 ( V_2 , V_19 ) ;
#ifdef F_80
if ( F_278 ( V_347 ) ) {
if ( V_18 -> type == V_341 )
V_24 -> V_348 = 1 ;
else
V_24 -> V_348 = 0 ;
}
#endif
F_103 ( V_38 ) ;
return V_159 ;
}
static int F_280 ( struct V_17 * V_18 , unsigned long V_317 ,
T_9 V_280 , T_6 V_178 , int V_349 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
int V_187 = 0 ;
int V_159 ;
if ( V_19 -> V_174 == V_209 )
return - V_15 ;
if ( V_349 & V_350 )
V_187 |= V_192 ;
if ( V_349 & V_351 )
V_187 |= V_194 ;
F_281 ( & V_19 -> V_338 ) ;
V_159 = F_139 ( V_19 , V_317 , V_280 , V_178 , V_187 , V_25 ) ;
F_282 ( & V_19 -> V_338 ) ;
return V_159 ;
}
static T_6 F_283 ( struct V_17 * V_18 , unsigned long V_317 ,
T_6 V_178 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
T_6 V_197 ;
if ( V_19 -> V_174 == V_209 )
return - V_15 ;
F_281 ( & V_19 -> V_338 ) ;
V_197 = F_144 ( V_19 , V_317 , V_178 ) ;
F_282 ( & V_19 -> V_338 ) ;
F_117 ( V_19 ) ;
return V_197 ;
}
static T_9 F_284 ( struct V_17 * V_18 ,
T_8 V_317 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_352 , V_353 ;
T_3 * V_173 , V_183 ;
if ( V_19 -> V_174 == V_209 )
return V_317 ;
V_173 = F_135 ( V_19 , V_317 , & V_353 ) ;
if ( ! V_173 || ! F_130 ( * V_173 ) )
return 0 ;
V_352 = V_353 - 1 ;
V_183 = * V_173 & V_354 ;
return ( V_183 & ~ V_352 ) | ( V_317 & V_352 ) ;
}
static bool F_285 ( enum V_355 V_356 )
{
switch ( V_356 ) {
case V_357 :
return true ;
case V_358 :
return ( V_359 == 1 ) ;
case V_360 :
return false ;
}
return false ;
}
static void F_286 ( struct V_1 * V_2 ,
struct V_361 * V_85 )
{
struct V_362 * V_4 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
F_9 (entry, &amd_iommu_unity_map, list) {
struct V_363 * V_364 ;
if ( V_14 < V_4 -> V_365 || V_14 > V_4 -> V_366 )
continue;
V_364 = F_17 ( sizeof( * V_364 ) , V_25 ) ;
if ( ! V_364 ) {
F_53 ( L_37 ,
F_29 ( V_2 ) ) ;
return;
}
V_364 -> V_282 = V_4 -> V_367 ;
V_364 -> V_301 = V_4 -> V_368 - V_4 -> V_367 ;
if ( V_4 -> V_187 & V_192 )
V_364 -> V_187 |= V_350 ;
if ( V_4 -> V_187 & V_194 )
V_364 -> V_187 |= V_351 ;
F_19 ( & V_364 -> V_203 , V_85 ) ;
}
}
static void F_287 ( struct V_1 * V_2 ,
struct V_361 * V_85 )
{
struct V_363 * V_4 , * V_265 ;
F_288 (entry, next, head, list)
F_176 ( V_4 ) ;
}
static void F_289 ( struct V_1 * V_2 ,
struct V_17 * V_19 ,
struct V_363 * V_364 )
{
struct V_20 * V_198 = F_14 ( F_12 ( V_19 ) ) ;
unsigned long V_282 , V_329 ;
V_282 = F_149 ( V_364 -> V_282 ) ;
V_329 = F_149 ( V_364 -> V_282 + V_364 -> V_301 ) ;
F_290 ( F_259 ( & V_198 -> V_200 , V_282 , V_329 ) == NULL ) ;
}
int F_291 ( struct V_369 * V_370 )
{
return F_292 ( & V_100 , V_370 ) ;
}
int F_293 ( struct V_369 * V_370 )
{
return F_294 ( & V_100 , V_370 ) ;
}
void F_295 ( struct V_17 * V_18 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
F_18 ( & V_19 -> V_162 , V_21 ) ;
V_19 -> V_174 = V_209 ;
V_19 -> V_177 = true ;
F_143 ( V_19 ) ;
F_163 ( V_19 ) ;
F_20 ( & V_19 -> V_162 , V_21 ) ;
}
int F_296 ( struct V_17 * V_18 , int V_371 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_372 , V_159 ;
if ( V_371 <= 0 || V_371 > ( V_373 + 1 ) )
return - V_15 ;
for ( V_372 = 0 ; ( V_371 - 1 ) & ~ 0x1ff ; V_371 >>= 9 )
V_372 += 1 ;
if ( V_372 > V_374 )
return - V_15 ;
F_18 ( & V_19 -> V_162 , V_21 ) ;
V_159 = - V_189 ;
if ( V_19 -> V_241 > 0 || V_19 -> V_21 & V_229 )
goto V_258;
V_159 = - V_51 ;
V_19 -> V_219 = ( void * ) F_121 ( V_284 ) ;
if ( V_19 -> V_219 == NULL )
goto V_258;
V_19 -> V_218 = V_372 ;
V_19 -> V_21 |= V_229 ;
V_19 -> V_177 = true ;
F_143 ( V_19 ) ;
V_159 = 0 ;
V_258:
F_20 ( & V_19 -> V_162 , V_21 ) ;
return V_159 ;
}
static int F_297 ( struct V_16 * V_19 , int V_97 ,
T_3 V_65 , bool V_134 )
{
struct V_23 * V_24 ;
struct V_59 V_60 ;
int V_45 , V_159 ;
if ( ! ( V_19 -> V_21 & V_229 ) )
return - V_15 ;
F_95 ( & V_60 , V_19 -> V_168 , V_97 , V_65 , V_134 ) ;
for ( V_45 = 0 ; V_45 < V_169 ; ++ V_45 ) {
if ( V_19 -> V_170 [ V_45 ] == 0 )
continue;
V_159 = F_102 ( V_171 [ V_45 ] , & V_60 ) ;
if ( V_159 != 0 )
goto V_258;
}
F_118 ( V_19 ) ;
F_9 (dev_data, &domain->dev_list, list) {
struct V_52 * V_38 ;
int V_144 ;
if ( ! V_24 -> V_166 . V_167 )
continue;
V_144 = V_24 -> V_166 . V_144 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_96 ( & V_60 , V_24 -> V_14 , V_97 ,
V_144 , V_65 , V_134 ) ;
V_159 = F_102 ( V_38 , & V_60 ) ;
if ( V_159 != 0 )
goto V_258;
}
F_118 ( V_19 ) ;
V_159 = 0 ;
V_258:
return V_159 ;
}
static int F_298 ( struct V_16 * V_19 , int V_97 ,
T_3 V_65 )
{
return F_297 ( V_19 , V_97 , V_65 , false ) ;
}
int F_299 ( struct V_17 * V_18 , int V_97 ,
T_3 V_65 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_159 ;
F_18 ( & V_19 -> V_162 , V_21 ) ;
V_159 = F_298 ( V_19 , V_97 , V_65 ) ;
F_20 ( & V_19 -> V_162 , V_21 ) ;
return V_159 ;
}
static int F_300 ( struct V_16 * V_19 , int V_97 )
{
return F_297 ( V_19 , V_97 , V_139 ,
true ) ;
}
int F_301 ( struct V_17 * V_18 , int V_97 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_159 ;
F_18 ( & V_19 -> V_162 , V_21 ) ;
V_159 = F_300 ( V_19 , V_97 ) ;
F_20 ( & V_19 -> V_162 , V_21 ) ;
return V_159 ;
}
static T_3 * F_302 ( T_3 * V_208 , int V_180 , int V_97 , bool V_375 )
{
int V_240 ;
T_3 * V_173 ;
while ( true ) {
V_240 = ( V_97 >> ( 9 * V_180 ) ) & 0x1ff ;
V_173 = & V_208 [ V_240 ] ;
if ( V_180 == 0 )
break;
if ( ! ( * V_173 & V_217 ) ) {
if ( ! V_375 )
return NULL ;
V_208 = ( void * ) F_121 ( V_284 ) ;
if ( V_208 == NULL )
return NULL ;
* V_173 = F_88 ( V_208 ) | V_217 ;
}
V_208 = F_171 ( * V_173 & V_140 ) ;
V_180 -= 1 ;
}
return V_173 ;
}
static int F_303 ( struct V_16 * V_19 , int V_97 ,
unsigned long V_376 )
{
T_3 * V_173 ;
if ( V_19 -> V_174 != V_209 )
return - V_15 ;
V_173 = F_302 ( V_19 -> V_219 , V_19 -> V_218 , V_97 , true ) ;
if ( V_173 == NULL )
return - V_51 ;
* V_173 = ( V_376 & V_140 ) | V_217 ;
return F_300 ( V_19 , V_97 ) ;
}
static int F_304 ( struct V_16 * V_19 , int V_97 )
{
T_3 * V_173 ;
if ( V_19 -> V_174 != V_209 )
return - V_15 ;
V_173 = F_302 ( V_19 -> V_219 , V_19 -> V_218 , V_97 , false ) ;
if ( V_173 == NULL )
return 0 ;
* V_173 = 0 ;
return F_300 ( V_19 , V_97 ) ;
}
int F_305 ( struct V_17 * V_18 , int V_97 ,
unsigned long V_376 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_159 ;
F_18 ( & V_19 -> V_162 , V_21 ) ;
V_159 = F_303 ( V_19 , V_97 , V_376 ) ;
F_20 ( & V_19 -> V_162 , V_21 ) ;
return V_159 ;
}
int F_306 ( struct V_17 * V_18 , int V_97 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_159 ;
F_18 ( & V_19 -> V_162 , V_21 ) ;
V_159 = F_304 ( V_19 , V_97 ) ;
F_20 ( & V_19 -> V_162 , V_21 ) ;
return V_159 ;
}
int F_307 ( struct V_8 * V_9 , int V_97 ,
int V_117 , int V_99 )
{
struct V_23 * V_24 ;
struct V_52 * V_38 ;
struct V_59 V_60 ;
V_24 = F_32 ( & V_9 -> V_2 ) ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_97 ( & V_60 , V_24 -> V_14 , V_97 , V_117 ,
V_99 , V_24 -> V_254 ) ;
return F_102 ( V_38 , & V_60 ) ;
}
struct V_17 * F_308 ( struct V_8 * V_9 )
{
struct V_16 * V_339 ;
V_339 = F_227 ( & V_9 -> V_2 ) ;
if ( F_43 ( V_339 ) )
return NULL ;
if ( ! ( V_339 -> V_21 & V_229 ) )
return NULL ;
return & V_339 -> V_19 ;
}
void F_309 ( struct V_8 * V_9 , T_2 V_47 )
{
struct V_23 * V_24 ;
if ( ! F_310 () )
return;
V_24 = F_32 ( & V_9 -> V_2 ) ;
V_24 -> V_48 |= ( 1 << V_47 ) ;
}
int F_311 ( struct V_8 * V_9 ,
struct F_311 * V_377 )
{
int V_378 ;
int V_46 ;
if ( V_9 == NULL || V_377 == NULL )
return - V_15 ;
if ( ! F_310 () )
return - V_15 ;
memset ( V_377 , 0 , sizeof( * V_377 ) ) ;
V_46 = F_38 ( V_9 , V_42 ) ;
if ( V_46 )
V_377 -> V_21 |= V_379 ;
V_46 = F_38 ( V_9 , V_43 ) ;
if ( V_46 )
V_377 -> V_21 |= V_380 ;
V_46 = F_38 ( V_9 , V_44 ) ;
if ( V_46 ) {
int V_381 ;
V_378 = 1 << ( 9 * ( V_374 + 1 ) ) ;
V_378 = F_312 ( V_378 , ( 1 << 20 ) ) ;
V_377 -> V_21 |= V_382 ;
V_377 -> V_378 = F_312 ( F_313 ( V_9 ) , V_378 ) ;
V_381 = F_314 ( V_9 ) ;
if ( V_381 & V_383 )
V_377 -> V_21 |= V_384 ;
if ( V_381 & V_385 )
V_377 -> V_21 |= V_386 ;
}
return 0 ;
}
static void F_315 ( T_1 V_14 , struct V_387 * V_388 )
{
T_3 V_389 ;
V_389 = V_35 [ V_14 ] . V_30 [ 2 ] ;
V_389 &= ~ V_390 ;
V_389 |= F_123 ( V_388 -> V_388 ) ;
V_389 |= V_391 ;
V_389 |= V_392 ;
V_389 |= V_393 ;
V_35 [ V_14 ] . V_30 [ 2 ] = V_389 ;
}
static struct V_387 * F_316 ( T_1 V_14 , bool V_394 )
{
struct V_387 * V_388 = NULL ;
struct V_52 * V_38 ;
unsigned long V_21 ;
T_1 V_29 ;
F_157 ( & V_205 , V_21 ) ;
V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
goto V_28;
V_388 = V_395 [ V_14 ] ;
if ( V_388 )
goto V_28;
V_29 = V_33 [ V_14 ] ;
V_388 = V_395 [ V_29 ] ;
if ( V_388 ) {
V_395 [ V_14 ] = V_388 ;
F_315 ( V_14 , V_388 ) ;
F_104 ( V_38 , V_14 ) ;
goto V_258;
}
V_388 = F_17 ( sizeof( * V_388 ) , V_284 ) ;
if ( ! V_388 )
goto V_28;
F_263 ( & V_388 -> V_162 ) ;
if ( V_394 )
V_388 -> V_396 = 32 ;
V_388 -> V_388 = F_317 ( V_397 , V_284 ) ;
if ( ! V_388 -> V_388 ) {
F_176 ( V_388 ) ;
V_388 = NULL ;
goto V_28;
}
if ( ! F_318 ( V_347 ) )
memset ( V_388 -> V_388 , 0 ,
V_398 * sizeof( T_2 ) ) ;
else
memset ( V_388 -> V_388 , 0 ,
( V_398 * ( sizeof( T_3 ) * 2 ) ) ) ;
if ( V_394 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < 32 ; ++ V_45 )
V_38 -> V_399 -> V_400 ( V_388 , V_45 ) ;
}
V_395 [ V_14 ] = V_388 ;
F_315 ( V_14 , V_388 ) ;
F_104 ( V_38 , V_14 ) ;
if ( V_14 != V_29 ) {
V_395 [ V_29 ] = V_388 ;
F_315 ( V_29 , V_388 ) ;
F_104 ( V_38 , V_29 ) ;
}
V_258:
F_103 ( V_38 ) ;
V_28:
F_160 ( & V_205 , V_21 ) ;
return V_388 ;
}
static int F_319 ( T_1 V_14 , int V_64 )
{
struct V_387 * V_388 ;
unsigned long V_21 ;
int V_240 , V_401 ;
struct V_52 * V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return - V_7 ;
V_388 = F_316 ( V_14 , false ) ;
if ( ! V_388 )
return - V_7 ;
F_18 ( & V_388 -> V_162 , V_21 ) ;
for ( V_401 = 0 , V_240 = V_388 -> V_396 ;
V_240 < V_398 ;
++ V_240 ) {
if ( ! V_38 -> V_399 -> V_402 ( V_388 , V_240 ) )
V_401 += 1 ;
else
V_401 = 0 ;
if ( V_401 == V_64 ) {
for (; V_401 != 0 ; -- V_401 )
V_38 -> V_399 -> V_400 ( V_388 , V_240 - V_401 + 1 ) ;
V_240 -= V_64 - 1 ;
goto V_258;
}
}
V_240 = - V_403 ;
V_258:
F_20 ( & V_388 -> V_162 , V_21 ) ;
return V_240 ;
}
static int F_320 ( T_1 V_14 , int V_240 , struct V_404 * V_405 ,
struct V_406 * V_30 )
{
struct V_387 * V_388 ;
struct V_52 * V_38 ;
unsigned long V_21 ;
struct V_404 * V_4 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_388 = F_316 ( V_14 , false ) ;
if ( ! V_388 )
return - V_51 ;
F_18 ( & V_388 -> V_162 , V_21 ) ;
V_4 = (struct V_404 * ) V_388 -> V_388 ;
V_4 = & V_4 [ V_240 ] ;
V_4 -> V_407 . V_408 . V_409 = 0 ;
V_4 -> V_410 . V_318 = V_405 -> V_410 . V_318 ;
V_4 -> V_407 . V_318 = V_405 -> V_407 . V_318 ;
V_4 -> V_407 . V_408 . V_409 = 1 ;
if ( V_30 )
V_30 -> V_411 = V_4 ;
F_20 ( & V_388 -> V_162 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
return 0 ;
}
static int F_321 ( T_1 V_14 , int V_240 , union V_405 * V_405 )
{
struct V_387 * V_388 ;
struct V_52 * V_38 ;
unsigned long V_21 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_388 = F_316 ( V_14 , false ) ;
if ( ! V_388 )
return - V_51 ;
F_18 ( & V_388 -> V_162 , V_21 ) ;
V_388 -> V_388 [ V_240 ] = V_405 -> V_318 ;
F_20 ( & V_388 -> V_162 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
return 0 ;
}
static void F_322 ( T_1 V_14 , int V_240 )
{
struct V_387 * V_388 ;
struct V_52 * V_38 ;
unsigned long V_21 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return;
V_388 = F_316 ( V_14 , false ) ;
if ( ! V_388 )
return;
F_18 ( & V_388 -> V_162 , V_21 ) ;
V_38 -> V_399 -> V_412 ( V_388 , V_240 ) ;
F_20 ( & V_388 -> V_162 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
}
static void F_323 ( void * V_4 ,
T_2 V_413 , T_2 V_414 ,
T_5 V_415 , T_2 V_416 , int V_14 )
{
union V_405 * V_405 = (union V_405 * ) V_4 ;
V_405 -> V_318 = 0 ;
V_405 -> V_417 . V_415 = V_415 ;
V_405 -> V_417 . V_418 = V_413 ;
V_405 -> V_417 . V_419 = V_416 ;
V_405 -> V_417 . V_420 = V_414 ;
V_405 -> V_417 . V_409 = 1 ;
}
static void F_324 ( void * V_4 ,
T_2 V_413 , T_2 V_414 ,
T_5 V_415 , T_2 V_416 , int V_14 )
{
struct V_404 * V_405 = (struct V_404 * ) V_4 ;
struct V_23 * V_24 = F_21 ( V_14 ) ;
V_405 -> V_407 . V_318 = 0 ;
V_405 -> V_410 . V_318 = 0 ;
V_405 -> V_407 . V_408 . V_421 = V_24 ? V_24 -> V_348 : 0 ;
V_405 -> V_407 . V_408 . V_418 = V_413 ;
V_405 -> V_407 . V_408 . V_420 = V_414 ;
V_405 -> V_410 . V_417 . V_415 = V_415 ;
V_405 -> V_407 . V_408 . V_419 = V_416 ;
V_405 -> V_407 . V_408 . V_409 = 1 ;
}
static void F_325 ( void * V_4 , T_1 V_14 , T_1 V_240 )
{
union V_405 * V_405 = (union V_405 * ) V_4 ;
V_405 -> V_417 . V_409 = 1 ;
F_321 ( V_14 , V_240 , V_405 ) ;
}
static void F_326 ( void * V_4 , T_1 V_14 , T_1 V_240 )
{
struct V_404 * V_405 = (struct V_404 * ) V_4 ;
V_405 -> V_407 . V_408 . V_409 = 1 ;
F_320 ( V_14 , V_240 , V_405 , NULL ) ;
}
static void F_327 ( void * V_4 , T_1 V_14 , T_1 V_240 )
{
union V_405 * V_405 = (union V_405 * ) V_4 ;
V_405 -> V_417 . V_409 = 0 ;
F_321 ( V_14 , V_240 , V_405 ) ;
}
static void F_328 ( void * V_4 , T_1 V_14 , T_1 V_240 )
{
struct V_404 * V_405 = (struct V_404 * ) V_4 ;
V_405 -> V_407 . V_408 . V_409 = 0 ;
F_320 ( V_14 , V_240 , V_405 , NULL ) ;
}
static void F_329 ( void * V_4 , T_1 V_14 , T_1 V_240 ,
T_5 V_415 , T_2 V_416 )
{
union V_405 * V_405 = (union V_405 * ) V_4 ;
V_405 -> V_417 . V_415 = V_415 ;
V_405 -> V_417 . V_419 = V_416 ;
F_321 ( V_14 , V_240 , V_405 ) ;
}
static void F_330 ( void * V_4 , T_1 V_14 , T_1 V_240 ,
T_5 V_415 , T_2 V_416 )
{
struct V_404 * V_405 = (struct V_404 * ) V_4 ;
struct V_23 * V_24 = F_21 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> V_348 ) {
V_405 -> V_410 . V_417 . V_415 = V_415 ;
V_405 -> V_407 . V_408 . V_419 = V_416 ;
V_405 -> V_407 . V_408 . V_421 = 0 ;
F_320 ( V_14 , V_240 , V_405 , NULL ) ;
}
}
static void F_331 ( struct V_387 * V_388 , int V_240 )
{
V_388 -> V_388 [ V_240 ] = V_422 ;
}
static void F_332 ( struct V_387 * V_388 , int V_240 )
{
struct V_404 * V_216 = (struct V_404 * ) V_388 -> V_388 ;
struct V_404 * V_405 = & V_216 [ V_240 ] ;
memset ( & V_405 -> V_407 . V_318 , 0 , sizeof( T_3 ) ) ;
memset ( & V_405 -> V_410 . V_318 , 0 , sizeof( T_3 ) ) ;
V_405 -> V_410 . V_417 . V_415 = 0xff ;
}
static bool F_333 ( struct V_387 * V_388 , int V_240 )
{
union V_405 * V_216 = (union V_405 * ) V_388 -> V_388 ;
union V_405 * V_405 = & V_216 [ V_240 ] ;
return V_405 -> V_318 != 0 ;
}
static bool F_334 ( struct V_387 * V_388 , int V_240 )
{
struct V_404 * V_216 = (struct V_404 * ) V_388 -> V_388 ;
struct V_404 * V_405 = & V_216 [ V_240 ] ;
return V_405 -> V_410 . V_417 . V_415 != 0 ;
}
static void F_335 ( struct V_387 * V_388 , int V_240 )
{
V_388 -> V_388 [ V_240 ] = 0 ;
}
static void F_336 ( struct V_387 * V_388 , int V_240 )
{
struct V_404 * V_216 = (struct V_404 * ) V_388 -> V_388 ;
struct V_404 * V_405 = & V_216 [ V_240 ] ;
memset ( & V_405 -> V_407 . V_318 , 0 , sizeof( T_3 ) ) ;
memset ( & V_405 -> V_410 . V_318 , 0 , sizeof( T_3 ) ) ;
}
static int F_337 ( struct V_423 * V_377 )
{
int V_14 = - 1 ;
switch ( V_377 -> type ) {
case V_424 :
V_14 = F_338 ( V_377 -> V_425 ) ;
break;
case V_426 :
V_14 = F_339 ( V_377 -> V_427 ) ;
break;
case V_428 :
case V_429 :
V_14 = F_10 ( & V_377 -> V_430 -> V_2 ) ;
break;
default:
F_15 ( 1 ) ;
break;
}
return V_14 ;
}
static struct V_431 * F_340 ( struct V_423 * V_377 )
{
struct V_52 * V_38 ;
int V_14 ;
if ( ! V_377 )
return NULL ;
V_14 = F_337 ( V_377 ) ;
if ( V_14 >= 0 ) {
V_38 = V_34 [ V_14 ] ;
if ( V_38 )
return V_38 -> V_432 ;
}
return NULL ;
}
static struct V_431 * F_341 ( struct V_423 * V_377 )
{
struct V_52 * V_38 ;
int V_14 ;
if ( ! V_377 )
return NULL ;
switch ( V_377 -> type ) {
case V_428 :
case V_429 :
V_14 = F_10 ( & V_377 -> V_430 -> V_2 ) ;
if ( V_14 < 0 )
return NULL ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 )
return V_38 -> V_433 ;
break;
default:
break;
}
return NULL ;
}
static void F_342 ( struct V_406 * V_30 ,
struct V_434 * V_434 ,
struct V_423 * V_377 ,
int V_14 , int V_240 , int V_435 )
{
struct V_436 * V_437 = & V_30 -> V_436 ;
struct V_438 * V_439 = & V_30 -> V_440 ;
struct V_441 * V_4 ;
struct V_52 * V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return;
V_30 -> V_436 . V_14 = V_14 ;
V_30 -> V_436 . V_240 = V_240 + V_435 ;
V_38 -> V_399 -> V_442 ( V_30 -> V_4 , V_443 -> V_444 ,
V_443 -> V_445 , V_434 -> V_415 ,
V_434 -> V_416 , V_14 ) ;
switch ( V_377 -> type ) {
case V_424 :
V_4 = V_377 -> V_446 ;
V_377 -> V_446 = NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_415 = V_240 ;
V_4 -> V_295 = 0 ;
V_4 -> V_447 = V_377 -> V_448 ;
V_4 -> V_449 = V_377 -> V_450 ;
if ( V_377 -> V_448 )
V_4 -> V_295 = 1 ;
break;
case V_426 :
case V_428 :
case V_429 :
V_439 -> V_451 = V_452 ;
V_439 -> V_453 = V_454 ;
V_439 -> V_30 = V_437 -> V_240 ;
break;
default:
F_15 ( 1 ) ;
break;
}
}
static int F_343 ( struct V_431 * V_19 , unsigned int V_455 ,
unsigned int V_456 , void * V_457 )
{
struct V_423 * V_377 = V_457 ;
struct V_458 * V_458 ;
struct V_406 * V_30 = NULL ;
struct V_434 * V_459 ;
int V_45 , V_159 , V_14 ;
int V_240 = - 1 ;
if ( ! V_377 )
return - V_15 ;
if ( V_456 > 1 && V_377 -> type != V_428 &&
V_377 -> type != V_429 )
return - V_15 ;
if ( V_377 -> type == V_428 )
V_377 -> V_21 &= ~ V_460 ;
V_14 = F_337 ( V_377 ) ;
if ( V_14 < 0 )
return - V_15 ;
V_159 = F_344 ( V_19 , V_455 , V_456 , V_457 ) ;
if ( V_159 < 0 )
return V_159 ;
if ( V_377 -> type == V_424 ) {
if ( F_316 ( V_14 , true ) )
V_240 = V_377 -> V_461 ;
else
V_159 = - V_51 ;
} else {
V_240 = F_319 ( V_14 , V_456 ) ;
}
if ( V_240 < 0 ) {
F_345 ( L_38 ) ;
V_159 = V_240 ;
goto V_462;
}
for ( V_45 = 0 ; V_45 < V_456 ; V_45 ++ ) {
V_458 = F_346 ( V_19 , V_455 + V_45 ) ;
V_459 = F_347 ( V_458 ) ;
if ( ! V_458 || ! V_459 ) {
V_159 = - V_15 ;
goto V_463;
}
V_159 = - V_51 ;
V_30 = F_17 ( sizeof( * V_30 ) , V_25 ) ;
if ( ! V_30 )
goto V_463;
if ( ! F_318 ( V_347 ) )
V_30 -> V_4 = F_17 ( sizeof( union V_405 ) , V_25 ) ;
else
V_30 -> V_4 = F_17 ( sizeof( struct V_404 ) ,
V_25 ) ;
if ( ! V_30 -> V_4 ) {
F_176 ( V_30 ) ;
goto V_463;
}
V_458 -> V_464 = ( V_14 << 16 ) + V_45 ;
V_458 -> V_465 = V_30 ;
V_458 -> V_466 = & V_467 ;
F_342 ( V_30 , V_459 , V_377 , V_14 , V_240 , V_45 ) ;
F_348 ( V_455 + V_45 , V_468 ) ;
}
return 0 ;
V_463:
for ( V_45 -- ; V_45 >= 0 ; V_45 -- ) {
V_458 = F_346 ( V_19 , V_455 + V_45 ) ;
if ( V_458 )
F_176 ( V_458 -> V_465 ) ;
}
for ( V_45 = 0 ; V_45 < V_456 ; V_45 ++ )
F_322 ( V_14 , V_240 + V_45 ) ;
V_462:
F_349 ( V_19 , V_455 , V_456 ) ;
return V_159 ;
}
static void F_350 ( struct V_431 * V_19 , unsigned int V_455 ,
unsigned int V_456 )
{
struct V_436 * V_437 ;
struct V_458 * V_458 ;
struct V_406 * V_30 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_456 ; V_45 ++ ) {
V_458 = F_346 ( V_19 , V_455 + V_45 ) ;
if ( V_458 && V_458 -> V_465 ) {
V_30 = V_458 -> V_465 ;
V_437 = & V_30 -> V_436 ;
F_322 ( V_437 -> V_14 , V_437 -> V_240 ) ;
F_176 ( V_30 -> V_4 ) ;
F_176 ( V_30 ) ;
}
}
F_349 ( V_19 , V_455 , V_456 ) ;
}
static void F_351 ( struct V_431 * V_19 ,
struct V_458 * V_458 )
{
struct V_406 * V_30 = V_458 -> V_465 ;
struct V_436 * V_437 = & V_30 -> V_436 ;
struct V_52 * V_38 = V_34 [ V_437 -> V_14 ] ;
if ( V_38 )
V_38 -> V_399 -> V_469 ( V_30 -> V_4 , V_437 -> V_14 ,
V_437 -> V_240 ) ;
}
static void F_352 ( struct V_431 * V_19 ,
struct V_458 * V_458 )
{
struct V_406 * V_30 = V_458 -> V_465 ;
struct V_436 * V_437 = & V_30 -> V_436 ;
struct V_52 * V_38 = V_34 [ V_437 -> V_14 ] ;
if ( V_38 )
V_38 -> V_399 -> V_470 ( V_30 -> V_4 , V_437 -> V_14 ,
V_437 -> V_240 ) ;
}
static int F_353 ( struct V_458 * V_30 , void * V_471 )
{
struct V_52 * V_38 ;
struct V_472 * V_473 = V_471 ;
struct V_474 * V_475 = V_473 -> V_474 ;
struct V_406 * V_476 = V_30 -> V_465 ;
struct V_404 * V_405 = (struct V_404 * ) V_476 -> V_4 ;
struct V_436 * V_437 = & V_476 -> V_436 ;
struct V_23 * V_24 = F_21 ( V_437 -> V_14 ) ;
if ( ! V_24 || ! V_24 -> V_348 )
return 0 ;
V_473 -> V_476 = V_476 ;
if ( ! F_278 ( V_347 ) ) {
F_75 ( L_39 ,
V_115 ) ;
V_473 -> V_477 = false ;
}
V_38 = V_34 [ V_437 -> V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_473 -> V_478 = V_476 -> V_479 ;
if ( V_473 -> V_477 ) {
V_405 -> V_410 . V_417 . V_480 = ( V_473 -> V_481 >> 12 ) ;
V_405 -> V_410 . V_417 . V_415 = V_475 -> V_415 ;
V_405 -> V_407 . V_482 . V_421 = 1 ;
V_405 -> V_407 . V_482 . V_483 = V_473 -> V_483 ;
V_476 -> V_479 = V_473 -> V_483 ;
} else {
struct V_434 * V_459 = F_347 ( V_30 ) ;
V_405 -> V_410 . V_318 = 0 ;
V_405 -> V_407 . V_318 = 0 ;
V_405 -> V_410 . V_417 . V_415 = V_459 -> V_415 ;
V_405 -> V_407 . V_408 . V_421 = 0 ;
V_405 -> V_407 . V_408 . V_419 = V_459 -> V_416 ;
V_405 -> V_407 . V_408 . V_418 = V_443 -> V_444 ;
V_405 -> V_407 . V_408 . V_420 = V_443 -> V_445 ;
V_476 -> V_479 = 0 ;
}
return F_320 ( V_437 -> V_14 , V_437 -> V_240 , V_405 , V_476 ) ;
}
static int F_354 ( struct V_458 * V_30 ,
const struct V_484 * V_295 , bool V_485 )
{
struct V_406 * V_476 = V_30 -> V_465 ;
struct V_436 * V_437 = & V_476 -> V_436 ;
struct V_434 * V_459 = F_347 ( V_30 ) ;
struct V_458 * V_486 = V_30 -> V_487 ;
struct V_52 * V_38 = V_34 [ V_437 -> V_14 ] ;
int V_159 ;
if ( ! V_38 )
return - V_7 ;
V_159 = V_486 -> V_466 -> V_488 ( V_486 , V_295 , V_485 ) ;
if ( V_159 < 0 || V_159 == V_489 )
return V_159 ;
V_38 -> V_399 -> V_490 ( V_476 -> V_4 , V_437 -> V_14 ,
V_437 -> V_240 , V_459 -> V_415 , V_459 -> V_416 ) ;
F_355 ( V_459 ) ;
return V_489 ;
}
static void F_356 ( struct V_458 * V_458 , struct V_438 * V_439 )
{
struct V_406 * V_476 = V_458 -> V_465 ;
* V_439 = V_476 -> V_440 ;
}
int F_357 ( struct V_52 * V_38 )
{
V_38 -> V_432 = F_358 ( NULL , & V_491 , V_38 ) ;
if ( ! V_38 -> V_432 )
return - V_51 ;
V_38 -> V_432 -> V_486 = F_359 () ;
V_38 -> V_433 = F_360 ( V_38 -> V_432 ) ;
return 0 ;
}
int F_361 ( int V_269 , bool V_492 , void * V_30 )
{
unsigned long V_21 ;
struct V_52 * V_38 ;
struct V_387 * V_493 ;
struct V_406 * V_476 = (struct V_406 * ) V_30 ;
int V_14 = V_476 -> V_436 . V_14 ;
struct V_404 * V_4 = (struct V_404 * ) V_476 -> V_4 ;
struct V_404 * V_411 = (struct V_404 * ) V_476 -> V_411 ;
if ( ! F_278 ( V_347 ) ||
! V_411 || ! V_4 || ! V_4 -> V_407 . V_482 . V_421 )
return 0 ;
V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return - V_7 ;
V_493 = F_316 ( V_14 , false ) ;
if ( ! V_493 )
return - V_7 ;
F_18 ( & V_493 -> V_162 , V_21 ) ;
if ( V_411 -> V_407 . V_482 . V_421 ) {
if ( V_269 >= 0 )
V_411 -> V_407 . V_482 . V_419 = V_269 ;
V_411 -> V_407 . V_482 . V_492 = V_492 ;
F_362 () ;
}
F_20 ( & V_493 -> V_162 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
return 0 ;
}
