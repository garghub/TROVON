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
struct V_51 * V_38 ;
int V_14 ;
if ( V_2 -> V_37 . V_38 )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_38 = V_34 [ V_14 ] ;
V_24 = F_31 ( V_14 ) ;
if ( ! V_24 )
return - V_52 ;
V_24 -> V_29 = F_23 ( V_2 ) ;
if ( F_11 ( V_2 ) && F_37 ( F_6 ( V_2 ) ) ) {
struct V_51 * V_38 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_24 -> V_53 = V_38 -> V_54 ;
}
V_2 -> V_37 . V_38 = V_24 ;
F_46 ( & V_38 -> V_38 , V_2 ) ;
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
memset ( & V_35 [ V_14 ] , 0 , sizeof( struct V_55 ) ) ;
memset ( & V_35 [ V_29 ] , 0 , sizeof( struct V_55 ) ) ;
V_34 [ V_14 ] = NULL ;
V_34 [ V_29 ] = NULL ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_51 * V_38 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_38 = V_34 [ V_14 ] ;
V_24 = F_21 ( V_14 ) ;
if ( ! V_24 )
return;
if ( V_24 -> V_19 )
F_49 ( V_2 ) ;
F_50 ( & V_38 -> V_38 , V_2 ) ;
F_51 ( V_2 ) ;
V_2 -> V_56 = NULL ;
}
static void F_52 ( T_1 V_14 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < 4 ; ++ V_45 )
F_53 ( L_5 , V_45 ,
V_35 [ V_14 ] . V_30 [ V_45 ] ) ;
}
static void F_54 ( unsigned long V_57 )
{
struct V_58 * V_59 = F_55 ( V_57 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 4 ; ++ V_45 )
F_53 ( L_6 , V_45 , V_59 -> V_30 [ V_45 ] ) ;
}
static void F_56 ( struct V_51 * V_38 , void * V_60 )
{
int type , V_14 , V_61 , V_21 ;
volatile T_2 * V_62 = V_60 ;
int V_63 = 0 ;
T_3 V_64 ;
V_65:
type = ( V_62 [ 1 ] >> V_66 ) & V_67 ;
V_14 = ( V_62 [ 0 ] >> V_68 ) & V_69 ;
V_61 = ( V_62 [ 1 ] >> V_70 ) & V_71 ;
V_21 = ( V_62 [ 1 ] >> V_72 ) & V_73 ;
V_64 = ( T_3 ) ( ( ( T_3 ) V_62 [ 3 ] ) << 32 ) | V_62 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_63 == V_74 ) {
F_53 ( L_7 ) ;
return;
}
F_57 ( 1 ) ;
goto V_65;
}
F_58 ( V_75 L_8 ) ;
switch ( type ) {
case V_76 :
F_58 ( L_9
L_10 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_64 , V_21 ) ;
F_52 ( V_14 ) ;
break;
case V_77 :
F_58 ( L_11
L_12 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_61 , V_64 , V_21 ) ;
break;
case V_78 :
F_58 ( L_13
L_10 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_64 , V_21 ) ;
break;
case V_79 :
F_58 ( L_14
L_12 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_61 , V_64 , V_21 ) ;
break;
case V_80 :
F_58 ( L_15 , V_64 ) ;
F_54 ( V_64 ) ;
break;
case V_81 :
F_58 ( L_16
L_17 , V_64 , V_21 ) ;
break;
case V_82 :
F_58 ( L_18
L_19 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_64 ) ;
break;
case V_83 :
F_58 ( L_20
L_10 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_64 , V_21 ) ;
break;
default:
F_58 ( V_75 L_21 , type ) ;
}
memset ( V_60 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_59 ( struct V_51 * V_38 )
{
T_2 V_84 , V_85 ;
V_84 = F_60 ( V_38 -> V_86 + V_87 ) ;
V_85 = F_60 ( V_38 -> V_86 + V_88 ) ;
while ( V_84 != V_85 ) {
F_56 ( V_38 , V_38 -> V_89 + V_84 ) ;
V_84 = ( V_84 + V_90 ) % V_91 ;
}
F_61 ( V_84 , V_38 -> V_86 + V_87 ) ;
}
static void F_62 ( struct V_51 * V_38 , T_3 * V_92 )
{
struct V_93 V_94 ;
if ( F_63 ( V_92 [ 0 ] ) != V_95 ) {
F_64 ( L_22 ) ;
return;
}
V_94 . V_64 = V_92 [ 1 ] ;
V_94 . V_96 = F_65 ( V_92 [ 0 ] ) ;
V_94 . V_97 = F_66 ( V_92 [ 0 ] ) ;
V_94 . V_98 = F_67 ( V_92 [ 0 ] ) ;
V_94 . V_21 = F_68 ( V_92 [ 0 ] ) ;
F_69 ( & V_99 , 0 , & V_94 ) ;
}
static void F_70 ( struct V_51 * V_38 )
{
T_2 V_84 , V_85 ;
if ( V_38 -> V_100 == NULL )
return;
V_84 = F_60 ( V_38 -> V_86 + V_101 ) ;
V_85 = F_60 ( V_38 -> V_86 + V_102 ) ;
while ( V_84 != V_85 ) {
volatile T_3 * V_92 ;
T_3 V_4 [ 2 ] ;
int V_45 ;
V_92 = ( T_3 * ) ( V_38 -> V_100 + V_84 ) ;
for ( V_45 = 0 ; V_45 < V_74 ; ++ V_45 ) {
if ( F_63 ( V_92 [ 0 ] ) != 0 )
break;
F_57 ( 1 ) ;
}
V_4 [ 0 ] = V_92 [ 0 ] ;
V_4 [ 1 ] = V_92 [ 1 ] ;
V_92 [ 0 ] = V_92 [ 1 ] = 0UL ;
V_84 = ( V_84 + V_103 ) % V_104 ;
F_61 ( V_84 , V_38 -> V_86 + V_101 ) ;
F_62 ( V_38 , V_4 ) ;
V_84 = F_60 ( V_38 -> V_86 + V_101 ) ;
V_85 = F_60 ( V_38 -> V_86 + V_102 ) ;
}
}
int F_71 ( int (* F_72)( T_2 ) )
{
V_105 = F_72 ;
return 0 ;
}
static void F_73 ( struct V_51 * V_38 )
{
T_2 V_84 , V_85 , V_106 = 0 ;
if ( V_38 -> V_107 == NULL )
return;
V_84 = F_60 ( V_38 -> V_86 + V_108 ) ;
V_85 = F_60 ( V_38 -> V_86 + V_109 ) ;
while ( V_84 != V_85 ) {
volatile T_3 * V_92 ;
T_3 V_110 ;
V_92 = ( T_3 * ) ( V_38 -> V_107 + V_84 ) ;
V_106 ++ ;
V_110 = * V_92 ;
V_84 = ( V_84 + V_111 ) % V_112 ;
F_61 ( V_84 , V_38 -> V_86 + V_108 ) ;
switch ( F_74 ( V_110 ) ) {
case V_113 :
if ( ! V_105 )
break;
F_75 ( L_23 ,
V_114 , F_76 ( V_110 ) ,
F_77 ( V_110 ) ) ;
if ( V_105 ( F_77 ( V_110 ) ) != 0 )
F_53 ( L_24 ) ;
break;
default:
break;
}
}
}
T_4 F_78 ( int V_115 , void * V_30 )
{
struct V_51 * V_38 = (struct V_51 * ) V_30 ;
T_2 V_116 = F_60 ( V_38 -> V_86 + V_117 ) ;
while ( V_116 & V_118 ) {
F_61 ( V_118 ,
V_38 -> V_86 + V_117 ) ;
if ( V_116 & V_119 ) {
F_79 ( L_25 ) ;
F_59 ( V_38 ) ;
}
if ( V_116 & V_120 ) {
F_79 ( L_26 ) ;
F_70 ( V_38 ) ;
}
#ifdef F_80
if ( V_116 & V_121 ) {
F_79 ( L_27 ) ;
F_73 ( V_38 ) ;
}
#endif
V_116 = F_60 ( V_38 -> V_86 + V_117 ) ;
}
return V_122 ;
}
T_4 F_81 ( int V_115 , void * V_30 )
{
return V_123 ;
}
static int F_82 ( volatile T_3 * V_124 )
{
int V_45 = 0 ;
while ( * V_124 == 0 && V_45 < V_74 ) {
F_57 ( 1 ) ;
V_45 += 1 ;
}
if ( V_45 == V_74 ) {
F_83 ( L_28 ) ;
return - V_125 ;
}
return 0 ;
}
static void F_84 ( struct V_51 * V_38 ,
struct V_58 * V_59 ,
T_2 V_85 )
{
T_5 * V_126 ;
V_126 = V_38 -> V_127 + V_85 ;
V_85 = ( V_85 + sizeof( * V_59 ) ) % V_128 ;
memcpy ( V_126 , V_59 , sizeof( * V_59 ) ) ;
F_61 ( V_85 , V_38 -> V_86 + V_129 ) ;
}
static void F_85 ( struct V_58 * V_59 , T_3 V_64 )
{
F_86 ( V_64 & 0x7ULL ) ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_30 [ 0 ] = F_87 ( F_88 ( V_64 ) ) | V_130 ;
V_59 -> V_30 [ 1 ] = F_89 ( F_88 ( V_64 ) ) ;
V_59 -> V_30 [ 2 ] = 1 ;
F_90 ( V_59 , V_131 ) ;
}
static void F_91 ( struct V_58 * V_59 , T_1 V_14 )
{
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_30 [ 0 ] = V_14 ;
F_90 ( V_59 , V_132 ) ;
}
static void F_92 ( struct V_58 * V_59 , T_3 V_64 ,
T_6 V_133 , T_1 V_61 , int V_134 )
{
T_3 V_135 ;
bool V_136 ;
V_135 = F_93 ( V_64 , V_133 , V_137 ) ;
V_136 = false ;
if ( V_135 > 1 ) {
V_64 = V_138 ;
V_136 = true ;
}
V_64 &= V_139 ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_30 [ 1 ] |= V_61 ;
V_59 -> V_30 [ 2 ] = F_87 ( V_64 ) ;
V_59 -> V_30 [ 3 ] = F_89 ( V_64 ) ;
F_90 ( V_59 , V_140 ) ;
if ( V_136 )
V_59 -> V_30 [ 2 ] |= V_141 ;
if ( V_134 )
V_59 -> V_30 [ 2 ] |= V_142 ;
}
static void F_94 ( struct V_58 * V_59 , T_1 V_14 , int V_143 ,
T_3 V_64 , T_6 V_133 )
{
T_3 V_135 ;
bool V_136 ;
V_135 = F_93 ( V_64 , V_133 , V_137 ) ;
V_136 = false ;
if ( V_135 > 1 ) {
V_64 = V_138 ;
V_136 = true ;
}
V_64 &= V_139 ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_30 [ 0 ] = V_14 ;
V_59 -> V_30 [ 0 ] |= ( V_143 & 0xff ) << 24 ;
V_59 -> V_30 [ 1 ] = V_14 ;
V_59 -> V_30 [ 2 ] = F_87 ( V_64 ) ;
V_59 -> V_30 [ 3 ] = F_89 ( V_64 ) ;
F_90 ( V_59 , V_144 ) ;
if ( V_136 )
V_59 -> V_30 [ 2 ] |= V_141 ;
}
static void F_95 ( struct V_58 * V_59 , T_1 V_61 , int V_96 ,
T_3 V_64 , bool V_133 )
{
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_64 &= ~ ( 0xfffULL ) ;
V_59 -> V_30 [ 0 ] = V_96 ;
V_59 -> V_30 [ 1 ] = V_61 ;
V_59 -> V_30 [ 2 ] = F_87 ( V_64 ) ;
V_59 -> V_30 [ 3 ] = F_89 ( V_64 ) ;
V_59 -> V_30 [ 2 ] |= V_142 ;
V_59 -> V_30 [ 2 ] |= V_145 ;
if ( V_133 )
V_59 -> V_30 [ 2 ] |= V_141 ;
F_90 ( V_59 , V_140 ) ;
}
static void F_96 ( struct V_58 * V_59 , T_1 V_14 , int V_96 ,
int V_143 , T_3 V_64 , bool V_133 )
{
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_64 &= ~ ( 0xfffULL ) ;
V_59 -> V_30 [ 0 ] = V_14 ;
V_59 -> V_30 [ 0 ] |= ( ( V_96 >> 8 ) & 0xff ) << 16 ;
V_59 -> V_30 [ 0 ] |= ( V_143 & 0xff ) << 24 ;
V_59 -> V_30 [ 1 ] = V_14 ;
V_59 -> V_30 [ 1 ] |= ( V_96 & 0xff ) << 16 ;
V_59 -> V_30 [ 2 ] = F_87 ( V_64 ) ;
V_59 -> V_30 [ 2 ] |= V_145 ;
V_59 -> V_30 [ 3 ] = F_89 ( V_64 ) ;
if ( V_133 )
V_59 -> V_30 [ 2 ] |= V_141 ;
F_90 ( V_59 , V_144 ) ;
}
static void F_97 ( struct V_58 * V_59 , T_1 V_14 , int V_96 ,
int V_116 , int V_98 , bool V_146 )
{
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_30 [ 0 ] = V_14 ;
if ( V_146 ) {
V_59 -> V_30 [ 1 ] = V_96 ;
V_59 -> V_30 [ 2 ] = V_145 ;
}
V_59 -> V_30 [ 3 ] = V_98 & 0x1ff ;
V_59 -> V_30 [ 3 ] |= ( V_116 & V_147 ) << V_148 ;
F_90 ( V_59 , V_149 ) ;
}
static void F_98 ( struct V_58 * V_59 )
{
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
F_90 ( V_59 , V_150 ) ;
}
static void F_99 ( struct V_58 * V_59 , T_1 V_14 )
{
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_30 [ 0 ] = V_14 ;
F_90 ( V_59 , V_151 ) ;
}
static int F_100 ( struct V_51 * V_38 ,
struct V_58 * V_59 ,
bool V_152 )
{
T_2 V_153 , V_85 , V_84 , V_154 ;
V_155:
V_84 = F_60 ( V_38 -> V_86 + V_156 ) ;
V_85 = F_60 ( V_38 -> V_86 + V_129 ) ;
V_154 = ( V_85 + sizeof( * V_59 ) ) % V_128 ;
V_153 = ( V_84 - V_154 ) % V_128 ;
if ( V_153 <= 0x20 ) {
struct V_58 V_157 ;
int V_158 ;
V_38 -> V_159 = 0 ;
F_85 ( & V_157 , ( T_3 ) & V_38 -> V_159 ) ;
F_84 ( V_38 , & V_157 , V_85 ) ;
if ( ( V_158 = F_82 ( & V_38 -> V_159 ) ) != 0 )
return V_158 ;
goto V_155;
}
F_84 ( V_38 , V_59 , V_85 ) ;
V_38 -> V_160 = V_152 ;
return 0 ;
}
static int F_101 ( struct V_51 * V_38 ,
struct V_58 * V_59 ,
bool V_152 )
{
unsigned long V_21 ;
int V_158 ;
F_18 ( & V_38 -> V_161 , V_21 ) ;
V_158 = F_100 ( V_38 , V_59 , V_152 ) ;
F_20 ( & V_38 -> V_161 , V_21 ) ;
return V_158 ;
}
static int F_102 ( struct V_51 * V_38 , struct V_58 * V_59 )
{
return F_101 ( V_38 , V_59 , true ) ;
}
static int F_103 ( struct V_51 * V_38 )
{
struct V_58 V_59 ;
unsigned long V_21 ;
int V_158 ;
if ( ! V_38 -> V_160 )
return 0 ;
F_85 ( & V_59 , ( T_3 ) & V_38 -> V_159 ) ;
F_18 ( & V_38 -> V_161 , V_21 ) ;
V_38 -> V_159 = 0 ;
V_158 = F_100 ( V_38 , & V_59 , false ) ;
if ( V_158 )
goto V_28;
V_158 = F_82 ( & V_38 -> V_159 ) ;
V_28:
F_20 ( & V_38 -> V_161 , V_21 ) ;
return V_158 ;
}
static int F_104 ( struct V_51 * V_38 , T_1 V_14 )
{
struct V_58 V_59 ;
F_91 ( & V_59 , V_14 ) ;
return F_102 ( V_38 , & V_59 ) ;
}
static void F_105 ( struct V_51 * V_38 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= 0xffff ; ++ V_14 )
F_104 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
}
static void F_106 ( struct V_51 * V_38 )
{
T_2 V_162 ;
for ( V_162 = 0 ; V_162 <= 0xffff ; ++ V_162 ) {
struct V_58 V_59 ;
F_92 ( & V_59 , 0 , V_138 ,
V_162 , 1 ) ;
F_102 ( V_38 , & V_59 ) ;
}
F_103 ( V_38 ) ;
}
static void F_107 ( struct V_51 * V_38 )
{
struct V_58 V_59 ;
F_98 ( & V_59 ) ;
F_102 ( V_38 , & V_59 ) ;
F_103 ( V_38 ) ;
}
static void F_108 ( struct V_51 * V_38 , T_1 V_14 )
{
struct V_58 V_59 ;
F_99 ( & V_59 , V_14 ) ;
F_102 ( V_38 , & V_59 ) ;
}
static void F_109 ( struct V_51 * V_38 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= V_163 ; V_14 ++ )
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
}
void F_110 ( struct V_51 * V_38 )
{
if ( F_111 ( V_38 , V_164 ) ) {
F_107 ( V_38 ) ;
} else {
F_105 ( V_38 ) ;
F_109 ( V_38 ) ;
F_106 ( V_38 ) ;
}
}
static int F_112 ( struct V_23 * V_24 ,
T_3 V_64 , T_6 V_133 )
{
struct V_51 * V_38 ;
struct V_58 V_59 ;
int V_143 ;
V_143 = V_24 -> V_165 . V_143 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_94 ( & V_59 , V_24 -> V_14 , V_143 , V_64 , V_133 ) ;
return F_102 ( V_38 , & V_59 ) ;
}
static int F_113 ( struct V_23 * V_24 )
{
struct V_51 * V_38 ;
T_1 V_29 ;
int V_158 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_158 = F_104 ( V_38 , V_24 -> V_14 ) ;
if ( ! V_158 && V_29 != V_24 -> V_14 )
V_158 = F_104 ( V_38 , V_29 ) ;
if ( V_158 )
return V_158 ;
if ( V_24 -> V_165 . V_166 )
V_158 = F_112 ( V_24 , 0 , ~ 0UL ) ;
return V_158 ;
}
static void F_114 ( struct V_16 * V_19 ,
T_3 V_64 , T_6 V_133 , int V_134 )
{
struct V_23 * V_24 ;
struct V_58 V_59 ;
int V_158 = 0 , V_45 ;
F_92 ( & V_59 , V_64 , V_133 , V_19 -> V_167 , V_134 ) ;
for ( V_45 = 0 ; V_45 < V_168 ; ++ V_45 ) {
if ( ! V_19 -> V_169 [ V_45 ] )
continue;
V_158 |= F_102 ( V_170 [ V_45 ] , & V_59 ) ;
}
F_9 (dev_data, &domain->dev_list, list) {
if ( ! V_24 -> V_165 . V_166 )
continue;
V_158 |= F_112 ( V_24 , V_64 , V_133 ) ;
}
F_86 ( V_158 ) ;
}
static void F_115 ( struct V_16 * V_19 ,
T_3 V_64 , T_6 V_133 )
{
F_114 ( V_19 , V_64 , V_133 , 0 ) ;
}
static void F_116 ( struct V_16 * V_19 )
{
F_114 ( V_19 , 0 , V_138 , 0 ) ;
}
static void F_117 ( struct V_16 * V_19 )
{
F_114 ( V_19 , 0 , V_138 , 1 ) ;
}
static void F_118 ( struct V_16 * V_19 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_168 ; ++ V_45 ) {
if ( V_19 && ! V_19 -> V_169 [ V_45 ] )
continue;
F_103 ( V_170 [ V_45 ] ) ;
}
}
static void F_119 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list)
F_113 ( V_24 ) ;
}
static bool F_120 ( struct V_16 * V_19 ,
T_7 V_171 )
{
T_3 * V_172 ;
if ( V_19 -> V_173 == V_174 )
return false ;
V_172 = ( void * ) F_121 ( V_171 ) ;
if ( ! V_172 )
return false ;
* V_172 = F_122 ( V_19 -> V_173 ,
F_123 ( V_19 -> V_175 ) ) ;
V_19 -> V_175 = V_172 ;
V_19 -> V_173 += 1 ;
V_19 -> V_176 = true ;
return true ;
}
static T_3 * F_124 ( struct V_16 * V_19 ,
unsigned long V_64 ,
unsigned long V_177 ,
T_3 * * V_178 ,
T_7 V_171 )
{
int V_179 , V_180 ;
T_3 * V_172 , * V_181 ;
F_15 ( ! F_125 ( V_177 ) ) ;
while ( V_64 > F_126 ( V_19 -> V_173 ) )
F_120 ( V_19 , V_171 ) ;
V_179 = V_19 -> V_173 - 1 ;
V_172 = & V_19 -> V_175 [ F_127 ( V_179 , V_64 ) ] ;
V_64 = F_128 ( V_64 , V_177 ) ;
V_180 = F_129 ( V_177 ) ;
while ( V_179 > V_180 ) {
T_3 V_182 , V_183 ;
V_182 = * V_172 ;
if ( ! F_130 ( V_182 ) ) {
V_181 = ( T_3 * ) F_121 ( V_171 ) ;
if ( ! V_181 )
return NULL ;
V_183 = F_122 ( V_179 , F_123 ( V_181 ) ) ;
if ( F_131 ( V_172 , V_182 , V_183 ) != V_182 ) {
F_132 ( ( unsigned long ) V_181 ) ;
continue;
}
}
if ( F_133 ( * V_172 ) != V_179 )
return NULL ;
V_179 -= 1 ;
V_172 = F_134 ( * V_172 ) ;
if ( V_178 && V_179 == V_180 )
* V_178 = V_172 ;
V_172 = & V_172 [ F_127 ( V_179 , V_64 ) ] ;
}
return V_172 ;
}
static T_3 * F_135 ( struct V_16 * V_19 ,
unsigned long V_64 ,
unsigned long * V_177 )
{
int V_179 ;
T_3 * V_172 ;
if ( V_64 > F_126 ( V_19 -> V_173 ) )
return NULL ;
V_179 = V_19 -> V_173 - 1 ;
V_172 = & V_19 -> V_175 [ F_127 ( V_179 , V_64 ) ] ;
* V_177 = F_136 ( V_179 ) ;
while ( V_179 > 0 ) {
if ( ! F_130 ( * V_172 ) )
return NULL ;
if ( F_133 ( * V_172 ) == 7 ||
F_133 ( * V_172 ) == 0 )
break;
if ( F_133 ( * V_172 ) != V_179 )
return NULL ;
V_179 -= 1 ;
V_172 = F_134 ( * V_172 ) ;
V_172 = & V_172 [ F_127 ( V_179 , V_64 ) ] ;
* V_177 = F_136 ( V_179 ) ;
}
if ( F_133 ( * V_172 ) == 0x07 ) {
unsigned long V_184 ;
* V_177 = V_184 = F_137 ( * V_172 ) ;
V_184 = ~ ( ( F_138 ( V_184 ) << 3 ) - 1 ) ;
V_172 = ( T_3 * ) ( ( ( unsigned long ) V_172 ) & V_184 ) ;
}
return V_172 ;
}
static int F_139 ( struct V_16 * V_18 ,
unsigned long V_185 ,
unsigned long V_57 ,
unsigned long V_177 ,
int V_186 ,
T_7 V_171 )
{
T_3 V_182 , * V_172 ;
int V_45 , V_63 ;
F_15 ( ! F_140 ( V_185 , V_177 ) ) ;
F_15 ( ! F_140 ( V_57 , V_177 ) ) ;
if ( ! ( V_186 & V_187 ) )
return - V_15 ;
V_63 = F_138 ( V_177 ) ;
V_172 = F_124 ( V_18 , V_185 , V_177 , NULL , V_171 ) ;
if ( ! V_172 )
return - V_52 ;
for ( V_45 = 0 ; V_45 < V_63 ; ++ V_45 )
if ( F_130 ( V_172 [ V_45 ] ) )
return - V_188 ;
if ( V_63 > 1 ) {
V_182 = F_141 ( V_57 , V_177 ) ;
V_182 |= F_142 ( 7 ) | V_189 | V_190 ;
} else
V_182 = V_57 | V_189 | V_190 ;
if ( V_186 & V_191 )
V_182 |= V_192 ;
if ( V_186 & V_193 )
V_182 |= V_194 ;
for ( V_45 = 0 ; V_45 < V_63 ; ++ V_45 )
V_172 [ V_45 ] = V_182 ;
F_143 ( V_18 ) ;
return 0 ;
}
static unsigned long F_144 ( struct V_16 * V_18 ,
unsigned long V_185 ,
unsigned long V_177 )
{
unsigned long long V_195 ;
unsigned long V_196 ;
T_3 * V_172 ;
F_15 ( ! F_125 ( V_177 ) ) ;
V_195 = 0 ;
while ( V_195 < V_177 ) {
V_172 = F_135 ( V_18 , V_185 , & V_196 ) ;
if ( V_172 ) {
int V_45 , V_63 ;
V_63 = F_138 ( V_196 ) ;
for ( V_45 = 0 ; V_45 < V_63 ; V_45 ++ )
V_172 [ V_45 ] = 0ULL ;
}
V_185 = ( V_185 & ~ ( V_196 - 1 ) ) + V_196 ;
V_195 += V_196 ;
}
F_15 ( V_195 && ! F_125 ( V_195 ) ) ;
return V_195 ;
}
static unsigned long F_145 ( struct V_1 * V_2 ,
struct V_20 * V_197 ,
unsigned int V_135 , T_3 V_49 )
{
unsigned long V_198 = 0 ;
V_135 = F_146 ( V_135 ) ;
if ( V_49 > F_147 ( 32 ) )
V_198 = F_148 ( & V_197 -> V_199 , V_135 ,
F_149 ( F_147 ( 32 ) ) ) ;
if ( ! V_198 )
V_198 = F_148 ( & V_197 -> V_199 , V_135 , F_149 ( V_49 ) ) ;
return ( V_198 << V_200 ) ;
}
static void F_150 ( struct V_20 * V_197 ,
unsigned long V_64 ,
unsigned int V_135 )
{
V_135 = F_146 ( V_135 ) ;
V_64 >>= V_200 ;
F_151 ( & V_197 -> V_199 , V_64 , V_135 ) ;
}
static void F_152 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_201 , V_21 ) ;
F_153 ( & V_19 -> V_202 , & V_203 ) ;
F_20 ( & V_201 , V_21 ) ;
}
static void F_154 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_201 , V_21 ) ;
F_155 ( & V_19 -> V_202 ) ;
F_20 ( & V_201 , V_21 ) ;
}
static T_1 F_156 ( void )
{
unsigned long V_21 ;
int V_167 ;
F_157 ( & V_204 , V_21 ) ;
V_167 = F_158 ( V_205 , V_206 ) ;
F_15 ( V_167 == 0 ) ;
if ( V_167 > 0 && V_167 < V_206 )
F_159 ( V_167 , V_205 ) ;
else
V_167 = 0 ;
F_160 ( & V_204 , V_21 ) ;
return V_167 ;
}
static void F_161 ( int V_167 )
{
unsigned long V_21 ;
F_157 ( & V_204 , V_21 ) ;
if ( V_167 > 0 && V_167 < V_206 )
F_162 ( V_167 , V_205 ) ;
F_160 ( & V_204 , V_21 ) ;
}
static void F_163 ( struct V_16 * V_19 )
{
unsigned long V_207 = ( unsigned long ) V_19 -> V_175 ;
switch ( V_19 -> V_173 ) {
case V_208 :
break;
case V_209 :
F_132 ( V_207 ) ;
break;
case V_210 :
F_164 ( V_207 ) ;
break;
case V_211 :
F_165 ( V_207 ) ;
break;
case V_212 :
F_166 ( V_207 ) ;
break;
case V_213 :
F_167 ( V_207 ) ;
break;
case V_174 :
F_168 ( V_207 ) ;
break;
default:
F_169 () ;
}
}
static void F_170 ( T_3 * V_214 )
{
T_3 * V_215 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 512 ; ++ V_45 ) {
if ( ! ( V_214 [ V_45 ] & V_216 ) )
continue;
V_215 = F_171 ( V_214 [ V_45 ] & V_139 ) ;
F_132 ( ( unsigned long ) V_215 ) ;
}
}
static void F_172 ( T_3 * V_214 )
{
T_3 * V_215 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 512 ; ++ V_45 ) {
if ( ! ( V_214 [ V_45 ] & V_216 ) )
continue;
V_215 = F_171 ( V_214 [ V_45 ] & V_139 ) ;
F_170 ( V_215 ) ;
}
}
static void F_173 ( struct V_16 * V_19 )
{
if ( V_19 -> V_217 == 2 )
F_172 ( V_19 -> V_218 ) ;
else if ( V_19 -> V_217 == 1 )
F_170 ( V_19 -> V_218 ) ;
else
F_15 ( V_19 -> V_217 != 0 ) ;
F_132 ( ( unsigned long ) V_19 -> V_218 ) ;
}
static void F_174 ( struct V_20 * V_18 )
{
if ( ! V_18 )
return;
F_154 ( & V_18 -> V_19 ) ;
F_175 ( & V_18 -> V_199 ) ;
F_163 ( & V_18 -> V_19 ) ;
if ( V_18 -> V_19 . V_167 )
F_161 ( V_18 -> V_19 . V_167 ) ;
F_176 ( V_18 ) ;
}
static struct V_20 * F_177 ( void )
{
struct V_20 * V_197 ;
V_197 = F_17 ( sizeof( struct V_20 ) , V_25 ) ;
if ( ! V_197 )
return NULL ;
if ( F_178 ( & V_197 -> V_19 ) )
goto V_219;
V_197 -> V_19 . V_173 = V_211 ;
V_197 -> V_19 . V_175 = ( void * ) F_121 ( V_25 ) ;
V_197 -> V_19 . V_21 = V_22 ;
if ( ! V_197 -> V_19 . V_175 )
goto V_219;
F_179 ( & V_197 -> V_199 , V_137 ,
V_220 , V_221 ) ;
F_180 ( & V_222 , & V_197 -> V_199 ) ;
F_152 ( & V_197 -> V_19 ) ;
return V_197 ;
V_219:
F_174 ( V_197 ) ;
return NULL ;
}
static bool V_20 ( struct V_16 * V_19 )
{
return V_19 -> V_21 & V_22 ;
}
static void F_181 ( T_1 V_14 , struct V_16 * V_19 , bool V_165 )
{
T_3 V_223 = 0 ;
T_3 V_21 = 0 ;
if ( V_19 -> V_173 != V_208 )
V_223 = F_123 ( V_19 -> V_175 ) ;
V_223 |= ( V_19 -> V_173 & V_224 )
<< V_225 ;
V_223 |= V_192 | V_194 | V_189 | V_226 ;
V_21 = V_35 [ V_14 ] . V_30 [ 1 ] ;
if ( V_165 )
V_21 |= V_227 ;
if ( V_19 -> V_21 & V_228 ) {
T_3 V_229 = F_88 ( V_19 -> V_218 ) ;
T_3 V_217 = V_19 -> V_217 ;
T_3 V_230 ;
V_223 |= V_231 ;
V_223 |= ( V_217 & V_232 ) << V_233 ;
V_230 = F_182 ( ~ 0ULL ) << V_234 ;
V_21 &= ~ V_230 ;
V_230 = F_183 ( ~ 0ULL ) << V_235 ;
V_21 &= ~ V_230 ;
V_230 = F_184 ( V_229 ) << V_236 ;
V_223 |= V_230 ;
V_230 = F_182 ( V_229 ) << V_234 ;
V_21 |= V_230 ;
V_230 = F_183 ( V_229 ) << V_235 ;
V_21 |= V_230 ;
}
V_21 &= ~ ( 0xffffUL ) ;
V_21 |= V_19 -> V_167 ;
V_35 [ V_14 ] . V_30 [ 1 ] = V_21 ;
V_35 [ V_14 ] . V_30 [ 0 ] = V_223 ;
}
static void F_185 ( T_1 V_14 )
{
V_35 [ V_14 ] . V_30 [ 0 ] = V_189 | V_226 ;
V_35 [ V_14 ] . V_30 [ 1 ] &= V_237 ;
F_186 ( V_14 ) ;
}
static void F_187 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
struct V_51 * V_38 ;
T_1 V_29 ;
bool V_165 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_165 = V_24 -> V_165 . V_166 ;
V_24 -> V_19 = V_19 ;
F_153 ( & V_24 -> V_202 , & V_19 -> V_238 ) ;
V_19 -> V_169 [ V_38 -> V_239 ] += 1 ;
V_19 -> V_240 += 1 ;
F_181 ( V_24 -> V_14 , V_19 , V_165 ) ;
if ( V_29 != V_24 -> V_14 )
F_181 ( V_29 , V_19 , V_165 ) ;
F_113 ( V_24 ) ;
}
static void F_188 ( struct V_23 * V_24 )
{
struct V_51 * V_38 ;
T_1 V_29 ;
if ( ! V_24 -> V_19 )
return;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_24 -> V_19 -> V_169 [ V_38 -> V_239 ] -= 1 ;
V_24 -> V_19 -> V_240 -= 1 ;
V_24 -> V_19 = NULL ;
F_155 ( & V_24 -> V_202 ) ;
F_185 ( V_24 -> V_14 ) ;
if ( V_29 != V_24 -> V_14 )
F_185 ( V_29 ) ;
F_113 ( V_24 ) ;
}
static int F_189 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
int V_158 ;
F_86 ( ! F_190 () ) ;
F_191 ( & V_19 -> V_161 ) ;
V_158 = - V_188 ;
if ( V_24 -> V_19 != NULL )
goto V_28;
F_187 ( V_24 , V_19 ) ;
V_158 = 0 ;
V_28:
F_192 ( & V_19 -> V_161 ) ;
return V_158 ;
}
static void F_193 ( struct V_8 * V_9 )
{
F_194 ( V_9 ) ;
F_195 ( V_9 ) ;
F_196 ( V_9 ) ;
}
static int F_197 ( struct V_8 * V_9 )
{
T_1 V_241 ;
int V_46 ;
V_46 = F_38 ( V_9 , V_43 ) ;
if ( ! V_46 )
return - V_15 ;
F_198 ( V_9 , V_46 + V_242 , & V_241 ) ;
V_241 |= V_243 ;
F_199 ( V_9 , V_46 + V_242 , V_241 ) ;
return 0 ;
}
static int F_200 ( struct V_8 * V_9 )
{
bool V_244 ;
int V_245 , V_158 ;
V_245 = 32 ;
if ( F_39 ( V_9 , V_246 ) )
V_245 = 1 ;
V_244 = F_39 ( V_9 , V_247 ) ;
V_158 = F_201 ( V_9 , 0 ) ;
if ( V_158 )
goto V_248;
V_158 = F_202 ( V_9 ) ;
if ( V_158 )
goto V_248;
V_158 = F_203 ( V_9 , V_245 ) ;
if ( V_158 )
goto V_248;
if ( V_244 ) {
V_158 = F_197 ( V_9 ) ;
if ( V_158 )
goto V_248;
}
V_158 = F_204 ( V_9 , V_200 ) ;
if ( V_158 )
goto V_248;
return 0 ;
V_248:
F_195 ( V_9 ) ;
F_196 ( V_9 ) ;
return V_158 ;
}
static bool F_205 ( struct V_8 * V_9 )
{
T_1 V_116 ;
int V_46 ;
V_46 = F_38 ( V_9 , V_43 ) ;
if ( ! V_46 )
return false ;
F_198 ( V_9 , V_46 + V_249 , & V_116 ) ;
return ( V_116 & V_250 ) ? true : false ;
}
static int F_206 ( struct V_1 * V_2 ,
struct V_16 * V_19 )
{
struct V_8 * V_9 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
int V_158 ;
V_24 = F_32 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
goto V_251;
V_9 = F_6 ( V_2 ) ;
if ( V_19 -> V_21 & V_228 ) {
if ( ! V_24 -> V_252 )
return - V_15 ;
if ( V_24 -> V_53 ) {
if ( F_200 ( V_9 ) != 0 )
return - V_15 ;
V_24 -> V_165 . V_166 = true ;
V_24 -> V_165 . V_143 = F_207 ( V_9 ) ;
V_24 -> V_253 = F_205 ( V_9 ) ;
}
} else if ( V_254 &&
F_204 ( V_9 , V_200 ) == 0 ) {
V_24 -> V_165 . V_166 = true ;
V_24 -> V_165 . V_143 = F_207 ( V_9 ) ;
}
V_251:
F_157 ( & V_204 , V_21 ) ;
V_158 = F_189 ( V_24 , V_19 ) ;
F_160 ( & V_204 , V_21 ) ;
F_117 ( V_19 ) ;
return V_158 ;
}
static void F_208 ( struct V_23 * V_24 )
{
struct V_16 * V_19 ;
F_86 ( ! F_190 () ) ;
if ( F_86 ( ! V_24 -> V_19 ) )
return;
V_19 = V_24 -> V_19 ;
F_191 ( & V_19 -> V_161 ) ;
F_188 ( V_24 ) ;
F_192 ( & V_19 -> V_161 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
V_24 = F_32 ( V_2 ) ;
V_19 = V_24 -> V_19 ;
F_157 ( & V_204 , V_21 ) ;
F_208 ( V_24 ) ;
F_160 ( & V_204 , V_21 ) ;
if ( ! F_11 ( V_2 ) )
return;
if ( V_19 -> V_21 & V_228 && V_24 -> V_53 )
F_193 ( F_6 ( V_2 ) ) ;
else if ( V_24 -> V_165 . V_166 )
F_194 ( F_6 ( V_2 ) ) ;
V_24 -> V_165 . V_166 = false ;
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_17 * V_19 ;
struct V_51 * V_38 ;
int V_158 , V_14 ;
if ( ! F_40 ( V_2 ) || F_32 ( V_2 ) )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_38 = V_34 [ V_14 ] ;
V_158 = F_45 ( V_2 ) ;
if ( V_158 ) {
if ( V_158 != - V_255 )
F_53 ( L_29 ,
F_29 ( V_2 ) ) ;
F_47 ( V_2 ) ;
V_2 -> V_56 = & V_256 ;
goto V_257;
}
F_41 ( V_2 ) ;
V_24 = F_32 ( V_2 ) ;
F_15 ( ! V_24 ) ;
if ( V_258 || V_24 -> V_53 )
F_210 ( V_2 ) ;
V_19 = F_211 ( V_2 ) ;
if ( V_19 -> type == V_259 )
V_24 -> V_252 = true ;
else
V_2 -> V_56 = & V_260 ;
V_257:
F_103 ( V_38 ) ;
return 0 ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_51 * V_38 ;
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
static void F_215 ( struct V_261 * V_262 )
{
struct V_16 * V_19 ;
unsigned long V_21 ;
int V_263 ;
F_18 ( & V_201 , V_21 ) ;
F_9 (domain, &amd_iommu_pd_list, list)
F_116 ( V_19 ) ;
F_20 ( & V_201 , V_21 ) ;
F_118 ( NULL ) ;
for ( V_263 = 0 ; V_263 < V_262 -> V_264 ; ++ V_263 ) {
struct V_265 * V_4 ;
V_4 = V_262 -> V_266 + V_263 ;
F_151 ( & V_4 -> V_197 -> V_199 ,
V_4 -> V_267 ,
V_4 -> V_135 ) ;
V_4 -> V_197 = NULL ;
}
V_262 -> V_264 = 0 ;
}
static void F_216 ( void )
{
int V_268 ;
F_217 (cpu) {
struct V_261 * V_262 ;
unsigned long V_21 ;
V_262 = F_218 ( & V_261 , V_268 ) ;
F_18 ( & V_262 -> V_161 , V_21 ) ;
if ( V_262 -> V_264 > 0 )
F_215 ( V_262 ) ;
F_20 ( & V_262 -> V_161 , V_21 ) ;
}
}
static void F_219 ( unsigned long V_269 )
{
F_220 ( & V_270 , 0 ) ;
F_216 () ;
}
static void F_221 ( struct V_20 * V_197 ,
unsigned long V_64 , unsigned long V_135 )
{
struct V_265 * V_4 ;
struct V_261 * V_262 ;
unsigned long V_21 ;
int V_263 ;
V_135 = F_146 ( V_135 ) ;
V_64 >>= V_200 ;
V_262 = F_222 ( & V_261 ) ;
F_18 ( & V_262 -> V_161 , V_21 ) ;
if ( V_262 -> V_264 == V_271 )
F_215 ( V_262 ) ;
V_263 = V_262 -> V_264 ++ ;
V_4 = V_262 -> V_266 + V_263 ;
V_4 -> V_267 = V_64 ;
V_4 -> V_135 = V_135 ;
V_4 -> V_197 = V_197 ;
F_20 ( & V_262 -> V_161 , V_21 ) ;
if ( F_223 ( & V_270 , 0 , 1 ) == 0 )
F_224 ( & V_272 , V_273 + F_225 ( 10 ) ) ;
F_226 ( & V_261 ) ;
}
static struct V_16 * F_227 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
if ( ! F_40 ( V_2 ) )
return F_34 ( - V_15 ) ;
V_19 = F_32 ( V_2 ) -> V_19 ;
if ( ! V_20 ( V_19 ) )
return F_34 ( - V_188 ) ;
return V_19 ;
}
static void F_228 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list) {
F_181 ( V_24 -> V_14 , V_19 , V_24 -> V_165 . V_166 ) ;
if ( V_24 -> V_14 == V_24 -> V_29 )
continue;
F_181 ( V_24 -> V_29 , V_19 , V_24 -> V_165 . V_166 ) ;
}
}
static void F_143 ( struct V_16 * V_19 )
{
if ( ! V_19 -> V_176 )
return;
F_228 ( V_19 ) ;
F_119 ( V_19 ) ;
F_117 ( V_19 ) ;
V_19 -> V_176 = false ;
}
static int F_229 ( enum V_274 V_275 )
{
if ( V_275 == V_276 )
return V_191 ;
else if ( V_275 == V_277 )
return V_193 ;
else if ( V_275 == V_278 )
return V_193 | V_191 ;
else
return 0 ;
}
static T_8 F_230 ( struct V_1 * V_2 ,
struct V_20 * V_197 ,
T_9 V_279 ,
T_6 V_133 ,
enum V_274 V_275 ,
T_3 V_49 )
{
T_8 V_280 = V_279 & ~ V_139 ;
T_8 V_64 , V_281 , V_158 ;
unsigned int V_135 ;
int V_186 = 0 ;
int V_45 ;
V_135 = F_93 ( V_279 , V_133 , V_137 ) ;
V_279 &= V_139 ;
V_64 = F_145 ( V_2 , V_197 , V_135 , V_49 ) ;
if ( V_64 == V_282 )
goto V_257;
V_186 = F_229 ( V_275 ) ;
V_281 = V_64 ;
for ( V_45 = 0 ; V_45 < V_135 ; ++ V_45 ) {
V_158 = F_139 ( & V_197 -> V_19 , V_281 , V_279 ,
V_137 , V_186 , V_283 ) ;
if ( V_158 )
goto V_284;
V_279 += V_137 ;
V_281 += V_137 ;
}
V_64 += V_280 ;
if ( F_231 ( V_285 ) ) {
F_115 ( & V_197 -> V_19 , V_64 , V_133 ) ;
F_118 ( & V_197 -> V_19 ) ;
}
V_257:
return V_64 ;
V_284:
for ( -- V_45 ; V_45 >= 0 ; -- V_45 ) {
V_281 -= V_137 ;
F_144 ( & V_197 -> V_19 , V_281 , V_137 ) ;
}
F_116 ( & V_197 -> V_19 ) ;
F_118 ( & V_197 -> V_19 ) ;
F_150 ( V_197 , V_64 , V_135 ) ;
return V_282 ;
}
static void F_232 ( struct V_20 * V_197 ,
T_8 V_286 ,
T_6 V_133 ,
int V_287 )
{
T_8 V_288 ;
T_8 V_45 , V_281 ;
unsigned int V_135 ;
V_288 = V_286 ;
V_135 = F_93 ( V_286 , V_133 , V_137 ) ;
V_286 &= V_139 ;
V_281 = V_286 ;
for ( V_45 = 0 ; V_45 < V_135 ; ++ V_45 ) {
F_144 ( & V_197 -> V_19 , V_281 , V_137 ) ;
V_281 += V_137 ;
}
if ( V_289 ) {
F_150 ( V_197 , V_286 , V_135 ) ;
F_116 ( & V_197 -> V_19 ) ;
F_118 ( & V_197 -> V_19 ) ;
} else {
F_221 ( V_197 , V_286 , V_135 ) ;
}
}
static T_8 F_233 ( struct V_1 * V_2 , struct V_181 * V_181 ,
unsigned long V_280 , T_6 V_133 ,
enum V_274 V_287 ,
unsigned long V_290 )
{
T_9 V_279 = F_234 ( V_181 ) + V_280 ;
struct V_16 * V_19 ;
struct V_20 * V_197 ;
T_3 V_49 ;
V_19 = F_227 ( V_2 ) ;
if ( F_235 ( V_19 ) == - V_15 )
return ( T_8 ) V_279 ;
else if ( F_43 ( V_19 ) )
return V_282 ;
V_49 = * V_2 -> V_49 ;
V_197 = F_14 ( V_19 ) ;
return F_230 ( V_2 , V_197 , V_279 , V_133 , V_287 , V_49 ) ;
}
static void F_236 ( struct V_1 * V_2 , T_8 V_286 , T_6 V_133 ,
enum V_274 V_287 , unsigned long V_290 )
{
struct V_16 * V_19 ;
struct V_20 * V_197 ;
V_19 = F_227 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return;
V_197 = F_14 ( V_19 ) ;
F_232 ( V_197 , V_286 , V_133 , V_287 ) ;
}
static int F_237 ( struct V_1 * V_2 ,
struct V_291 * V_292 ,
int V_293 )
{
unsigned long V_294 , V_295 ;
struct V_291 * V_136 ;
int V_45 , V_296 = 0 ;
V_294 = F_238 ( V_2 ) ;
V_295 = V_294 + 1 ? F_239 ( V_294 + 1 , V_137 ) >> V_200 :
1UL << ( V_297 - V_200 ) ;
F_240 (sglist, s, nelems, i) {
int V_13 , V_298 ;
V_136 -> V_299 = V_296 << V_200 ;
V_13 = V_296 % V_295 ;
V_298 = F_93 ( F_241 ( V_136 ) , V_136 -> V_300 , V_137 ) ;
if ( V_13 + V_298 > V_295 )
V_296 += V_295 - V_13 ;
V_296 += V_298 ;
}
return V_296 ;
}
static int F_242 ( struct V_1 * V_2 , struct V_291 * V_292 ,
int V_293 , enum V_274 V_275 ,
unsigned long V_290 )
{
int V_301 = 0 , V_296 = 0 , V_186 = 0 , V_45 ;
struct V_16 * V_19 ;
struct V_20 * V_197 ;
struct V_291 * V_136 ;
unsigned long V_64 ;
T_3 V_49 ;
V_19 = F_227 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return 0 ;
V_197 = F_14 ( V_19 ) ;
V_49 = * V_2 -> V_49 ;
V_296 = F_237 ( V_2 , V_292 , V_293 ) ;
V_64 = F_145 ( V_2 , V_197 , V_296 , V_49 ) ;
if ( V_64 == V_282 )
goto V_248;
V_186 = F_229 ( V_275 ) ;
F_240 (sglist, s, nelems, i) {
int V_302 , V_135 = F_93 ( F_241 ( V_136 ) , V_136 -> V_300 , V_137 ) ;
for ( V_302 = 0 ; V_302 < V_135 ; ++ V_302 ) {
unsigned long V_185 , V_57 ;
int V_158 ;
V_185 = V_64 + V_136 -> V_299 + ( V_302 << V_200 ) ;
V_57 = ( F_241 ( V_136 ) & V_139 ) + ( V_302 << V_200 ) ;
V_158 = F_139 ( V_19 , V_185 , V_57 , V_137 , V_186 , V_283 ) ;
if ( V_158 )
goto V_284;
V_301 += 1 ;
}
}
F_240 (sglist, s, nelems, i) {
V_136 -> V_299 += V_64 + V_136 -> V_280 ;
V_136 -> V_303 = V_136 -> V_300 ;
}
return V_293 ;
V_284:
F_53 ( L_30 ,
F_29 ( V_2 ) , V_296 ) ;
F_240 (sglist, s, nelems, i) {
int V_302 , V_135 = F_93 ( F_241 ( V_136 ) , V_136 -> V_300 , V_137 ) ;
for ( V_302 = 0 ; V_302 < V_135 ; ++ V_302 ) {
unsigned long V_185 ;
V_185 = V_64 + V_136 -> V_299 + ( V_302 << V_200 ) ;
F_144 ( V_19 , V_185 , V_137 ) ;
if ( -- V_301 )
goto V_304;
}
}
V_304:
F_151 ( & V_197 -> V_199 , V_64 , V_296 ) ;
V_248:
return 0 ;
}
static void F_243 ( struct V_1 * V_2 , struct V_291 * V_292 ,
int V_293 , enum V_274 V_287 ,
unsigned long V_290 )
{
struct V_16 * V_19 ;
struct V_20 * V_197 ;
unsigned long V_305 ;
int V_296 = 2 ;
V_19 = F_227 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return;
V_305 = F_244 ( V_292 ) & V_139 ;
V_197 = F_14 ( V_19 ) ;
V_296 = F_237 ( V_2 , V_292 , V_293 ) ;
F_232 ( V_197 , V_305 , V_296 << V_200 , V_287 ) ;
}
static void * F_245 ( struct V_1 * V_2 , T_6 V_133 ,
T_8 * V_286 , T_7 V_306 ,
unsigned long V_290 )
{
T_3 V_49 = V_2 -> V_307 ;
struct V_16 * V_19 ;
struct V_20 * V_197 ;
struct V_181 * V_181 ;
V_19 = F_227 ( V_2 ) ;
if ( F_235 ( V_19 ) == - V_15 ) {
V_181 = F_246 ( V_306 , F_247 ( V_133 ) ) ;
* V_286 = F_234 ( V_181 ) ;
return F_248 ( V_181 ) ;
} else if ( F_43 ( V_19 ) )
return NULL ;
V_197 = F_14 ( V_19 ) ;
V_133 = F_249 ( V_133 ) ;
V_49 = V_2 -> V_307 ;
V_306 &= ~ ( V_308 | V_309 | V_310 ) ;
V_306 |= V_311 ;
V_181 = F_246 ( V_306 | V_312 , F_247 ( V_133 ) ) ;
if ( ! V_181 ) {
if ( ! F_250 ( V_306 ) )
return NULL ;
V_181 = F_251 ( V_2 , V_133 >> V_200 ,
F_247 ( V_133 ) , V_306 ) ;
if ( ! V_181 )
return NULL ;
}
if ( ! V_49 )
V_49 = * V_2 -> V_49 ;
* V_286 = F_230 ( V_2 , V_197 , F_234 ( V_181 ) ,
V_133 , V_278 , V_49 ) ;
if ( * V_286 == V_282 )
goto V_313;
return F_248 ( V_181 ) ;
V_313:
if ( ! F_252 ( V_2 , V_181 , V_133 >> V_200 ) )
F_253 ( V_181 , F_247 ( V_133 ) ) ;
return NULL ;
}
static void F_254 ( struct V_1 * V_2 , T_6 V_133 ,
void * V_314 , T_8 V_286 ,
unsigned long V_290 )
{
struct V_16 * V_19 ;
struct V_20 * V_197 ;
struct V_181 * V_181 ;
V_181 = F_255 ( V_314 ) ;
V_133 = F_249 ( V_133 ) ;
V_19 = F_227 ( V_2 ) ;
if ( F_43 ( V_19 ) )
goto V_315;
V_197 = F_14 ( V_19 ) ;
F_232 ( V_197 , V_286 , V_133 , V_278 ) ;
V_315:
if ( ! F_252 ( V_2 , V_181 , V_133 >> V_200 ) )
F_253 ( V_181 , F_247 ( V_133 ) ) ;
}
static int F_256 ( struct V_1 * V_2 , T_3 V_294 )
{
return F_40 ( V_2 ) ;
}
static int F_257 ( void )
{
struct V_8 * V_9 = NULL ;
struct V_316 * V_317 ;
F_179 ( & V_222 , V_137 ,
V_220 , V_221 ) ;
F_258 ( & V_222 . V_318 ,
& V_319 ) ;
V_317 = F_259 ( & V_222 ,
F_149 ( V_320 ) , F_149 ( V_321 ) ) ;
if ( ! V_317 ) {
F_53 ( L_31 ) ;
return - V_52 ;
}
V_317 = F_259 ( & V_222 ,
F_149 ( V_322 ) , F_149 ( V_323 ) ) ;
if ( ! V_317 ) {
F_53 ( L_32 ) ;
return - V_52 ;
}
F_260 (pdev) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_324 ; ++ V_45 ) {
struct V_325 * V_326 = & V_9 -> V_325 [ V_45 ] ;
if ( ! ( V_326 -> V_21 & V_327 ) )
continue;
V_317 = F_259 ( & V_222 ,
F_149 ( V_326 -> V_281 ) ,
F_149 ( V_326 -> V_328 ) ) ;
if ( ! V_317 ) {
F_53 ( L_33 ) ;
return - V_52 ;
}
}
}
return 0 ;
}
int T_10 F_261 ( void )
{
int V_158 , V_268 , V_329 = 0 ;
V_158 = F_262 () ;
if ( V_158 )
return V_158 ;
V_158 = F_257 () ;
if ( V_158 )
return V_158 ;
F_217 (cpu) {
struct V_261 * V_262 = F_218 ( & V_261 , V_268 ) ;
V_262 -> V_266 = F_17 ( V_271 *
sizeof( * V_262 -> V_266 ) ,
V_25 ) ;
if ( ! V_262 -> V_266 )
goto V_330;
F_263 ( & V_262 -> V_161 ) ;
}
V_329 = F_264 ( & V_331 , & V_332 ) ;
if ( V_329 )
return V_329 ;
#ifdef F_265
V_329 = F_264 ( & V_333 , & V_332 ) ;
if ( V_329 )
return V_329 ;
#endif
V_329 = F_264 ( & V_334 , & V_332 ) ;
if ( V_329 )
return V_329 ;
return 0 ;
V_330:
F_217 (cpu) {
struct V_261 * V_262 = F_218 ( & V_261 , V_268 ) ;
F_176 ( V_262 -> V_266 ) ;
}
return - V_52 ;
}
int T_10 F_266 ( void )
{
F_267 ( & V_272 , F_219 , 0 ) ;
F_220 ( & V_270 , 0 ) ;
V_335 = V_258 ? 1 : 0 ;
V_336 = 1 ;
if ( ! V_335 )
V_56 = & V_256 ;
if ( V_289 )
F_25 ( L_34 ) ;
else
F_25 ( L_35 ) ;
return 0 ;
}
static void F_268 ( struct V_16 * V_19 )
{
struct V_23 * V_4 ;
unsigned long V_21 ;
F_157 ( & V_204 , V_21 ) ;
while ( ! F_269 ( & V_19 -> V_238 ) ) {
V_4 = F_270 ( & V_19 -> V_238 ,
struct V_23 , V_202 ) ;
F_208 ( V_4 ) ;
}
F_160 ( & V_204 , V_21 ) ;
}
static void F_271 ( struct V_16 * V_19 )
{
if ( ! V_19 )
return;
F_154 ( V_19 ) ;
if ( V_19 -> V_167 )
F_161 ( V_19 -> V_167 ) ;
F_176 ( V_19 ) ;
}
static int F_178 ( struct V_16 * V_19 )
{
F_263 ( & V_19 -> V_161 ) ;
F_272 ( & V_19 -> V_337 ) ;
V_19 -> V_167 = F_156 () ;
if ( ! V_19 -> V_167 )
return - V_52 ;
F_273 ( & V_19 -> V_238 ) ;
return 0 ;
}
static struct V_16 * F_274 ( void )
{
struct V_16 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_25 ) ;
if ( ! V_19 )
return NULL ;
if ( F_178 ( V_19 ) )
goto V_248;
F_152 ( V_19 ) ;
return V_19 ;
V_248:
F_176 ( V_19 ) ;
return NULL ;
}
static struct V_17 * F_275 ( unsigned type )
{
struct V_16 * V_338 ;
struct V_20 * V_339 ;
switch ( type ) {
case V_340 :
V_338 = F_274 () ;
if ( ! V_338 )
return NULL ;
V_338 -> V_173 = V_211 ;
V_338 -> V_175 = ( void * ) F_121 ( V_25 ) ;
if ( ! V_338 -> V_175 ) {
F_271 ( V_338 ) ;
return NULL ;
}
V_338 -> V_19 . V_341 . V_342 = 0 ;
V_338 -> V_19 . V_341 . V_343 = ~ 0ULL ;
V_338 -> V_19 . V_341 . V_344 = true ;
break;
case V_345 :
V_339 = F_177 () ;
if ( ! V_339 ) {
F_53 ( L_36 ) ;
return NULL ;
}
V_338 = & V_339 -> V_19 ;
break;
case V_259 :
V_338 = F_274 () ;
if ( ! V_338 )
return NULL ;
V_338 -> V_173 = V_208 ;
break;
default:
return NULL ;
}
return & V_338 -> V_19 ;
}
static void F_276 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
struct V_20 * V_197 ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 -> V_240 > 0 )
F_268 ( V_19 ) ;
F_15 ( V_19 -> V_240 != 0 ) ;
if ( ! V_18 )
return;
switch ( V_18 -> type ) {
case V_345 :
F_216 () ;
V_197 = F_14 ( V_19 ) ;
F_174 ( V_197 ) ;
break;
default:
if ( V_19 -> V_173 != V_208 )
F_163 ( V_19 ) ;
if ( V_19 -> V_21 & V_228 )
F_173 ( V_19 ) ;
F_271 ( V_19 ) ;
break;
}
}
static void F_277 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_37 . V_38 ;
struct V_51 * V_38 ;
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
if ( F_278 ( V_346 ) &&
( V_18 -> type == V_340 ) )
V_24 -> V_347 = 0 ;
#endif
F_103 ( V_38 ) ;
}
static int F_279 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
struct V_23 * V_24 ;
struct V_51 * V_38 ;
int V_158 ;
if ( ! F_40 ( V_2 ) )
return - V_15 ;
V_24 = V_2 -> V_37 . V_38 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
if ( ! V_38 )
return - V_15 ;
if ( V_24 -> V_19 )
F_49 ( V_2 ) ;
V_158 = F_206 ( V_2 , V_19 ) ;
#ifdef F_80
if ( F_278 ( V_346 ) ) {
if ( V_18 -> type == V_340 )
V_24 -> V_347 = 1 ;
else
V_24 -> V_347 = 0 ;
}
#endif
F_103 ( V_38 ) ;
return V_158 ;
}
static int F_280 ( struct V_17 * V_18 , unsigned long V_316 ,
T_9 V_279 , T_6 V_177 , int V_348 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
int V_186 = 0 ;
int V_158 ;
if ( V_19 -> V_173 == V_208 )
return - V_15 ;
if ( V_348 & V_349 )
V_186 |= V_191 ;
if ( V_348 & V_350 )
V_186 |= V_193 ;
F_281 ( & V_19 -> V_337 ) ;
V_158 = F_139 ( V_19 , V_316 , V_279 , V_177 , V_186 , V_25 ) ;
F_282 ( & V_19 -> V_337 ) ;
return V_158 ;
}
static T_6 F_283 ( struct V_17 * V_18 , unsigned long V_316 ,
T_6 V_177 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
T_6 V_196 ;
if ( V_19 -> V_173 == V_208 )
return - V_15 ;
F_281 ( & V_19 -> V_337 ) ;
V_196 = F_144 ( V_19 , V_316 , V_177 ) ;
F_282 ( & V_19 -> V_337 ) ;
F_117 ( V_19 ) ;
return V_196 ;
}
static T_9 F_284 ( struct V_17 * V_18 ,
T_8 V_316 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_351 , V_352 ;
T_3 * V_172 , V_182 ;
if ( V_19 -> V_173 == V_208 )
return V_316 ;
V_172 = F_135 ( V_19 , V_316 , & V_352 ) ;
if ( ! V_172 || ! F_130 ( * V_172 ) )
return 0 ;
V_351 = V_352 - 1 ;
V_182 = * V_172 & V_353 ;
return ( V_182 & ~ V_351 ) | ( V_316 & V_351 ) ;
}
static bool F_285 ( enum V_354 V_355 )
{
switch ( V_355 ) {
case V_356 :
return true ;
case V_357 :
return ( V_358 == 1 ) ;
case V_359 :
return false ;
}
return false ;
}
static void F_286 ( struct V_1 * V_2 ,
struct V_360 * V_84 )
{
struct V_361 * V_362 ;
struct V_363 * V_4 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
F_9 (entry, &amd_iommu_unity_map, list) {
T_6 V_300 ;
int V_186 = 0 ;
if ( V_14 < V_4 -> V_364 || V_14 > V_4 -> V_365 )
continue;
V_300 = V_4 -> V_366 - V_4 -> V_367 ;
if ( V_4 -> V_186 & V_191 )
V_186 |= V_349 ;
if ( V_4 -> V_186 & V_193 )
V_186 |= V_350 ;
V_362 = F_287 ( V_4 -> V_367 ,
V_300 , V_186 ,
V_368 ) ;
if ( ! V_362 ) {
F_53 ( L_37 ,
F_29 ( V_2 ) ) ;
return;
}
F_19 ( & V_362 -> V_202 , V_84 ) ;
}
V_362 = F_287 ( V_320 ,
V_321 - V_320 + 1 ,
0 , V_369 ) ;
if ( ! V_362 )
return;
F_19 ( & V_362 -> V_202 , V_84 ) ;
V_362 = F_287 ( V_322 ,
V_323 - V_322 + 1 ,
0 , V_370 ) ;
if ( ! V_362 )
return;
F_19 ( & V_362 -> V_202 , V_84 ) ;
}
static void F_288 ( struct V_1 * V_2 ,
struct V_360 * V_84 )
{
struct V_361 * V_4 , * V_264 ;
F_289 (entry, next, head, list)
F_176 ( V_4 ) ;
}
static void F_290 ( struct V_1 * V_2 ,
struct V_17 * V_19 ,
struct V_361 * V_362 )
{
struct V_20 * V_197 = F_14 ( F_12 ( V_19 ) ) ;
unsigned long V_281 , V_328 ;
V_281 = F_149 ( V_362 -> V_281 ) ;
V_328 = F_149 ( V_362 -> V_281 + V_362 -> V_300 ) ;
F_291 ( F_259 ( & V_197 -> V_199 , V_281 , V_328 ) == NULL ) ;
}
int F_292 ( struct V_371 * V_372 )
{
return F_293 ( & V_99 , V_372 ) ;
}
int F_294 ( struct V_371 * V_372 )
{
return F_295 ( & V_99 , V_372 ) ;
}
void F_296 ( struct V_17 * V_18 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_19 -> V_173 = V_208 ;
V_19 -> V_176 = true ;
F_143 ( V_19 ) ;
F_163 ( V_19 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
}
int F_297 ( struct V_17 * V_18 , int V_373 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_374 , V_158 ;
if ( V_373 <= 0 || V_373 > ( V_375 + 1 ) )
return - V_15 ;
for ( V_374 = 0 ; ( V_373 - 1 ) & ~ 0x1ff ; V_373 >>= 9 )
V_374 += 1 ;
if ( V_374 > V_376 )
return - V_15 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = - V_188 ;
if ( V_19 -> V_240 > 0 || V_19 -> V_21 & V_228 )
goto V_257;
V_158 = - V_52 ;
V_19 -> V_218 = ( void * ) F_121 ( V_283 ) ;
if ( V_19 -> V_218 == NULL )
goto V_257;
V_19 -> V_217 = V_374 ;
V_19 -> V_21 |= V_228 ;
V_19 -> V_176 = true ;
F_143 ( V_19 ) ;
V_158 = 0 ;
V_257:
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
static int F_298 ( struct V_16 * V_19 , int V_96 ,
T_3 V_64 , bool V_133 )
{
struct V_23 * V_24 ;
struct V_58 V_59 ;
int V_45 , V_158 ;
if ( ! ( V_19 -> V_21 & V_228 ) )
return - V_15 ;
F_95 ( & V_59 , V_19 -> V_167 , V_96 , V_64 , V_133 ) ;
for ( V_45 = 0 ; V_45 < V_168 ; ++ V_45 ) {
if ( V_19 -> V_169 [ V_45 ] == 0 )
continue;
V_158 = F_102 ( V_170 [ V_45 ] , & V_59 ) ;
if ( V_158 != 0 )
goto V_257;
}
F_118 ( V_19 ) ;
F_9 (dev_data, &domain->dev_list, list) {
struct V_51 * V_38 ;
int V_143 ;
if ( ! V_24 -> V_165 . V_166 )
continue;
V_143 = V_24 -> V_165 . V_143 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_96 ( & V_59 , V_24 -> V_14 , V_96 ,
V_143 , V_64 , V_133 ) ;
V_158 = F_102 ( V_38 , & V_59 ) ;
if ( V_158 != 0 )
goto V_257;
}
F_118 ( V_19 ) ;
V_158 = 0 ;
V_257:
return V_158 ;
}
static int F_299 ( struct V_16 * V_19 , int V_96 ,
T_3 V_64 )
{
return F_298 ( V_19 , V_96 , V_64 , false ) ;
}
int F_300 ( struct V_17 * V_18 , int V_96 ,
T_3 V_64 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_158 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = F_299 ( V_19 , V_96 , V_64 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
static int F_301 ( struct V_16 * V_19 , int V_96 )
{
return F_298 ( V_19 , V_96 , V_138 ,
true ) ;
}
int F_302 ( struct V_17 * V_18 , int V_96 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_158 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = F_301 ( V_19 , V_96 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
static T_3 * F_303 ( T_3 * V_207 , int V_179 , int V_96 , bool V_377 )
{
int V_239 ;
T_3 * V_172 ;
while ( true ) {
V_239 = ( V_96 >> ( 9 * V_179 ) ) & 0x1ff ;
V_172 = & V_207 [ V_239 ] ;
if ( V_179 == 0 )
break;
if ( ! ( * V_172 & V_216 ) ) {
if ( ! V_377 )
return NULL ;
V_207 = ( void * ) F_121 ( V_283 ) ;
if ( V_207 == NULL )
return NULL ;
* V_172 = F_88 ( V_207 ) | V_216 ;
}
V_207 = F_171 ( * V_172 & V_139 ) ;
V_179 -= 1 ;
}
return V_172 ;
}
static int F_304 ( struct V_16 * V_19 , int V_96 ,
unsigned long V_378 )
{
T_3 * V_172 ;
if ( V_19 -> V_173 != V_208 )
return - V_15 ;
V_172 = F_303 ( V_19 -> V_218 , V_19 -> V_217 , V_96 , true ) ;
if ( V_172 == NULL )
return - V_52 ;
* V_172 = ( V_378 & V_139 ) | V_216 ;
return F_301 ( V_19 , V_96 ) ;
}
static int F_305 ( struct V_16 * V_19 , int V_96 )
{
T_3 * V_172 ;
if ( V_19 -> V_173 != V_208 )
return - V_15 ;
V_172 = F_303 ( V_19 -> V_218 , V_19 -> V_217 , V_96 , false ) ;
if ( V_172 == NULL )
return 0 ;
* V_172 = 0 ;
return F_301 ( V_19 , V_96 ) ;
}
int F_306 ( struct V_17 * V_18 , int V_96 ,
unsigned long V_378 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_158 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = F_304 ( V_19 , V_96 , V_378 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
int F_307 ( struct V_17 * V_18 , int V_96 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_158 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = F_305 ( V_19 , V_96 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
int F_308 ( struct V_8 * V_9 , int V_96 ,
int V_116 , int V_98 )
{
struct V_23 * V_24 ;
struct V_51 * V_38 ;
struct V_58 V_59 ;
V_24 = F_32 ( & V_9 -> V_2 ) ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_97 ( & V_59 , V_24 -> V_14 , V_96 , V_116 ,
V_98 , V_24 -> V_253 ) ;
return F_102 ( V_38 , & V_59 ) ;
}
struct V_17 * F_309 ( struct V_8 * V_9 )
{
struct V_16 * V_338 ;
V_338 = F_227 ( & V_9 -> V_2 ) ;
if ( F_43 ( V_338 ) )
return NULL ;
if ( ! ( V_338 -> V_21 & V_228 ) )
return NULL ;
return & V_338 -> V_19 ;
}
void F_310 ( struct V_8 * V_9 , T_2 V_47 )
{
struct V_23 * V_24 ;
if ( ! F_311 () )
return;
V_24 = F_32 ( & V_9 -> V_2 ) ;
V_24 -> V_48 |= ( 1 << V_47 ) ;
}
int F_312 ( struct V_8 * V_9 ,
struct F_312 * V_379 )
{
int V_380 ;
int V_46 ;
if ( V_9 == NULL || V_379 == NULL )
return - V_15 ;
if ( ! F_311 () )
return - V_15 ;
memset ( V_379 , 0 , sizeof( * V_379 ) ) ;
V_46 = F_38 ( V_9 , V_42 ) ;
if ( V_46 )
V_379 -> V_21 |= V_381 ;
V_46 = F_38 ( V_9 , V_43 ) ;
if ( V_46 )
V_379 -> V_21 |= V_382 ;
V_46 = F_38 ( V_9 , V_44 ) ;
if ( V_46 ) {
int V_383 ;
V_380 = 1 << ( 9 * ( V_376 + 1 ) ) ;
V_380 = F_313 ( V_380 , ( 1 << 20 ) ) ;
V_379 -> V_21 |= V_384 ;
V_379 -> V_380 = F_313 ( F_314 ( V_9 ) , V_380 ) ;
V_383 = F_315 ( V_9 ) ;
if ( V_383 & V_385 )
V_379 -> V_21 |= V_386 ;
if ( V_383 & V_387 )
V_379 -> V_21 |= V_388 ;
}
return 0 ;
}
static void F_316 ( T_1 V_14 , struct V_389 * V_390 )
{
T_3 V_391 ;
V_391 = V_35 [ V_14 ] . V_30 [ 2 ] ;
V_391 &= ~ V_392 ;
V_391 |= F_123 ( V_390 -> V_390 ) ;
V_391 |= V_393 ;
V_391 |= V_394 ;
V_391 |= V_395 ;
V_35 [ V_14 ] . V_30 [ 2 ] = V_391 ;
}
static struct V_389 * F_317 ( T_1 V_14 , bool V_396 )
{
struct V_389 * V_390 = NULL ;
struct V_51 * V_38 ;
unsigned long V_21 ;
T_1 V_29 ;
F_157 ( & V_204 , V_21 ) ;
V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
goto V_28;
V_390 = V_397 [ V_14 ] ;
if ( V_390 )
goto V_28;
V_29 = V_33 [ V_14 ] ;
V_390 = V_397 [ V_29 ] ;
if ( V_390 ) {
V_397 [ V_14 ] = V_390 ;
F_316 ( V_14 , V_390 ) ;
F_104 ( V_38 , V_14 ) ;
goto V_257;
}
V_390 = F_17 ( sizeof( * V_390 ) , V_283 ) ;
if ( ! V_390 )
goto V_28;
F_263 ( & V_390 -> V_161 ) ;
if ( V_396 )
V_390 -> V_398 = 32 ;
V_390 -> V_390 = F_318 ( V_399 , V_283 ) ;
if ( ! V_390 -> V_390 ) {
F_176 ( V_390 ) ;
V_390 = NULL ;
goto V_28;
}
if ( ! F_319 ( V_346 ) )
memset ( V_390 -> V_390 , 0 ,
V_400 * sizeof( T_2 ) ) ;
else
memset ( V_390 -> V_390 , 0 ,
( V_400 * ( sizeof( T_3 ) * 2 ) ) ) ;
if ( V_396 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < 32 ; ++ V_45 )
V_38 -> V_401 -> V_402 ( V_390 , V_45 ) ;
}
V_397 [ V_14 ] = V_390 ;
F_316 ( V_14 , V_390 ) ;
F_104 ( V_38 , V_14 ) ;
if ( V_14 != V_29 ) {
V_397 [ V_29 ] = V_390 ;
F_316 ( V_29 , V_390 ) ;
F_104 ( V_38 , V_29 ) ;
}
V_257:
F_103 ( V_38 ) ;
V_28:
F_160 ( & V_204 , V_21 ) ;
return V_390 ;
}
static int F_320 ( T_1 V_14 , int V_63 )
{
struct V_389 * V_390 ;
unsigned long V_21 ;
int V_239 , V_403 ;
struct V_51 * V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return - V_7 ;
V_390 = F_317 ( V_14 , false ) ;
if ( ! V_390 )
return - V_7 ;
F_18 ( & V_390 -> V_161 , V_21 ) ;
for ( V_403 = 0 , V_239 = V_390 -> V_398 ;
V_239 < V_400 ;
++ V_239 ) {
if ( ! V_38 -> V_401 -> V_404 ( V_390 , V_239 ) )
V_403 += 1 ;
else
V_403 = 0 ;
if ( V_403 == V_63 ) {
for (; V_403 != 0 ; -- V_403 )
V_38 -> V_401 -> V_402 ( V_390 , V_239 - V_403 + 1 ) ;
V_239 -= V_63 - 1 ;
goto V_257;
}
}
V_239 = - V_405 ;
V_257:
F_20 ( & V_390 -> V_161 , V_21 ) ;
return V_239 ;
}
static int F_321 ( T_1 V_14 , int V_239 , struct V_406 * V_407 ,
struct V_408 * V_30 )
{
struct V_389 * V_390 ;
struct V_51 * V_38 ;
unsigned long V_21 ;
struct V_406 * V_4 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_390 = F_317 ( V_14 , false ) ;
if ( ! V_390 )
return - V_52 ;
F_18 ( & V_390 -> V_161 , V_21 ) ;
V_4 = (struct V_406 * ) V_390 -> V_390 ;
V_4 = & V_4 [ V_239 ] ;
V_4 -> V_409 . V_410 . V_411 = 0 ;
V_4 -> V_412 . V_317 = V_407 -> V_412 . V_317 ;
V_4 -> V_409 . V_317 = V_407 -> V_409 . V_317 ;
V_4 -> V_409 . V_410 . V_411 = 1 ;
if ( V_30 )
V_30 -> V_413 = V_4 ;
F_20 ( & V_390 -> V_161 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
return 0 ;
}
static int F_322 ( T_1 V_14 , int V_239 , union V_407 * V_407 )
{
struct V_389 * V_390 ;
struct V_51 * V_38 ;
unsigned long V_21 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_390 = F_317 ( V_14 , false ) ;
if ( ! V_390 )
return - V_52 ;
F_18 ( & V_390 -> V_161 , V_21 ) ;
V_390 -> V_390 [ V_239 ] = V_407 -> V_317 ;
F_20 ( & V_390 -> V_161 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
return 0 ;
}
static void F_323 ( T_1 V_14 , int V_239 )
{
struct V_389 * V_390 ;
struct V_51 * V_38 ;
unsigned long V_21 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return;
V_390 = F_317 ( V_14 , false ) ;
if ( ! V_390 )
return;
F_18 ( & V_390 -> V_161 , V_21 ) ;
V_38 -> V_401 -> V_414 ( V_390 , V_239 ) ;
F_20 ( & V_390 -> V_161 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
}
static void F_324 ( void * V_4 ,
T_2 V_415 , T_2 V_416 ,
T_5 V_417 , T_2 V_418 , int V_14 )
{
union V_407 * V_407 = (union V_407 * ) V_4 ;
V_407 -> V_317 = 0 ;
V_407 -> V_419 . V_417 = V_417 ;
V_407 -> V_419 . V_420 = V_415 ;
V_407 -> V_419 . V_421 = V_418 ;
V_407 -> V_419 . V_422 = V_416 ;
V_407 -> V_419 . V_411 = 1 ;
}
static void F_325 ( void * V_4 ,
T_2 V_415 , T_2 V_416 ,
T_5 V_417 , T_2 V_418 , int V_14 )
{
struct V_406 * V_407 = (struct V_406 * ) V_4 ;
struct V_23 * V_24 = F_21 ( V_14 ) ;
V_407 -> V_409 . V_317 = 0 ;
V_407 -> V_412 . V_317 = 0 ;
V_407 -> V_409 . V_410 . V_423 = V_24 ? V_24 -> V_347 : 0 ;
V_407 -> V_409 . V_410 . V_420 = V_415 ;
V_407 -> V_409 . V_410 . V_422 = V_416 ;
V_407 -> V_412 . V_419 . V_417 = V_417 ;
V_407 -> V_409 . V_410 . V_421 = V_418 ;
V_407 -> V_409 . V_410 . V_411 = 1 ;
}
static void F_326 ( void * V_4 , T_1 V_14 , T_1 V_239 )
{
union V_407 * V_407 = (union V_407 * ) V_4 ;
V_407 -> V_419 . V_411 = 1 ;
F_322 ( V_14 , V_239 , V_407 ) ;
}
static void F_327 ( void * V_4 , T_1 V_14 , T_1 V_239 )
{
struct V_406 * V_407 = (struct V_406 * ) V_4 ;
V_407 -> V_409 . V_410 . V_411 = 1 ;
F_321 ( V_14 , V_239 , V_407 , NULL ) ;
}
static void F_328 ( void * V_4 , T_1 V_14 , T_1 V_239 )
{
union V_407 * V_407 = (union V_407 * ) V_4 ;
V_407 -> V_419 . V_411 = 0 ;
F_322 ( V_14 , V_239 , V_407 ) ;
}
static void F_329 ( void * V_4 , T_1 V_14 , T_1 V_239 )
{
struct V_406 * V_407 = (struct V_406 * ) V_4 ;
V_407 -> V_409 . V_410 . V_411 = 0 ;
F_321 ( V_14 , V_239 , V_407 , NULL ) ;
}
static void F_330 ( void * V_4 , T_1 V_14 , T_1 V_239 ,
T_5 V_417 , T_2 V_418 )
{
union V_407 * V_407 = (union V_407 * ) V_4 ;
V_407 -> V_419 . V_417 = V_417 ;
V_407 -> V_419 . V_421 = V_418 ;
F_322 ( V_14 , V_239 , V_407 ) ;
}
static void F_331 ( void * V_4 , T_1 V_14 , T_1 V_239 ,
T_5 V_417 , T_2 V_418 )
{
struct V_406 * V_407 = (struct V_406 * ) V_4 ;
struct V_23 * V_24 = F_21 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> V_347 ) {
V_407 -> V_412 . V_419 . V_417 = V_417 ;
V_407 -> V_409 . V_410 . V_421 = V_418 ;
V_407 -> V_409 . V_410 . V_423 = 0 ;
F_321 ( V_14 , V_239 , V_407 , NULL ) ;
}
}
static void F_332 ( struct V_389 * V_390 , int V_239 )
{
V_390 -> V_390 [ V_239 ] = V_424 ;
}
static void F_333 ( struct V_389 * V_390 , int V_239 )
{
struct V_406 * V_215 = (struct V_406 * ) V_390 -> V_390 ;
struct V_406 * V_407 = & V_215 [ V_239 ] ;
memset ( & V_407 -> V_409 . V_317 , 0 , sizeof( T_3 ) ) ;
memset ( & V_407 -> V_412 . V_317 , 0 , sizeof( T_3 ) ) ;
V_407 -> V_412 . V_419 . V_417 = 0xff ;
}
static bool F_334 ( struct V_389 * V_390 , int V_239 )
{
union V_407 * V_215 = (union V_407 * ) V_390 -> V_390 ;
union V_407 * V_407 = & V_215 [ V_239 ] ;
return V_407 -> V_317 != 0 ;
}
static bool F_335 ( struct V_389 * V_390 , int V_239 )
{
struct V_406 * V_215 = (struct V_406 * ) V_390 -> V_390 ;
struct V_406 * V_407 = & V_215 [ V_239 ] ;
return V_407 -> V_412 . V_419 . V_417 != 0 ;
}
static void F_336 ( struct V_389 * V_390 , int V_239 )
{
V_390 -> V_390 [ V_239 ] = 0 ;
}
static void F_337 ( struct V_389 * V_390 , int V_239 )
{
struct V_406 * V_215 = (struct V_406 * ) V_390 -> V_390 ;
struct V_406 * V_407 = & V_215 [ V_239 ] ;
memset ( & V_407 -> V_409 . V_317 , 0 , sizeof( T_3 ) ) ;
memset ( & V_407 -> V_412 . V_317 , 0 , sizeof( T_3 ) ) ;
}
static int F_338 ( struct V_425 * V_379 )
{
int V_14 = - 1 ;
switch ( V_379 -> type ) {
case V_426 :
V_14 = F_339 ( V_379 -> V_427 ) ;
break;
case V_428 :
V_14 = F_340 ( V_379 -> V_429 ) ;
break;
case V_430 :
case V_431 :
V_14 = F_10 ( & V_379 -> V_432 -> V_2 ) ;
break;
default:
F_15 ( 1 ) ;
break;
}
return V_14 ;
}
static struct V_433 * F_341 ( struct V_425 * V_379 )
{
struct V_51 * V_38 ;
int V_14 ;
if ( ! V_379 )
return NULL ;
V_14 = F_338 ( V_379 ) ;
if ( V_14 >= 0 ) {
V_38 = V_34 [ V_14 ] ;
if ( V_38 )
return V_38 -> V_434 ;
}
return NULL ;
}
static struct V_433 * F_342 ( struct V_425 * V_379 )
{
struct V_51 * V_38 ;
int V_14 ;
if ( ! V_379 )
return NULL ;
switch ( V_379 -> type ) {
case V_430 :
case V_431 :
V_14 = F_10 ( & V_379 -> V_432 -> V_2 ) ;
if ( V_14 < 0 )
return NULL ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 )
return V_38 -> V_435 ;
break;
default:
break;
}
return NULL ;
}
static void F_343 ( struct V_408 * V_30 ,
struct V_436 * V_436 ,
struct V_425 * V_379 ,
int V_14 , int V_239 , int V_437 )
{
struct V_438 * V_439 = & V_30 -> V_438 ;
struct V_440 * V_441 = & V_30 -> V_442 ;
struct V_443 * V_4 ;
struct V_51 * V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return;
V_30 -> V_438 . V_14 = V_14 ;
V_30 -> V_438 . V_239 = V_239 + V_437 ;
V_38 -> V_401 -> V_444 ( V_30 -> V_4 , V_445 -> V_446 ,
V_445 -> V_447 , V_436 -> V_417 ,
V_436 -> V_418 , V_14 ) ;
switch ( V_379 -> type ) {
case V_426 :
V_4 = V_379 -> V_448 ;
V_379 -> V_448 = NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_417 = V_239 ;
V_4 -> V_294 = 0 ;
V_4 -> V_449 = V_379 -> V_450 ;
V_4 -> V_451 = V_379 -> V_452 ;
if ( V_379 -> V_450 )
V_4 -> V_294 = 1 ;
break;
case V_428 :
case V_430 :
case V_431 :
V_441 -> V_453 = V_454 ;
V_441 -> V_455 = V_456 ;
V_441 -> V_30 = V_439 -> V_239 ;
break;
default:
F_15 ( 1 ) ;
break;
}
}
static int F_344 ( struct V_433 * V_19 , unsigned int V_457 ,
unsigned int V_458 , void * V_459 )
{
struct V_425 * V_379 = V_459 ;
struct V_460 * V_460 ;
struct V_408 * V_30 = NULL ;
struct V_436 * V_461 ;
int V_45 , V_158 , V_14 ;
int V_239 = - 1 ;
if ( ! V_379 )
return - V_15 ;
if ( V_458 > 1 && V_379 -> type != V_430 &&
V_379 -> type != V_431 )
return - V_15 ;
if ( V_379 -> type == V_430 )
V_379 -> V_21 &= ~ V_462 ;
V_14 = F_338 ( V_379 ) ;
if ( V_14 < 0 )
return - V_15 ;
V_158 = F_345 ( V_19 , V_457 , V_458 , V_459 ) ;
if ( V_158 < 0 )
return V_158 ;
if ( V_379 -> type == V_426 ) {
if ( F_317 ( V_14 , true ) )
V_239 = V_379 -> V_463 ;
else
V_158 = - V_52 ;
} else {
V_239 = F_320 ( V_14 , V_458 ) ;
}
if ( V_239 < 0 ) {
F_346 ( L_38 ) ;
V_158 = V_239 ;
goto V_464;
}
for ( V_45 = 0 ; V_45 < V_458 ; V_45 ++ ) {
V_460 = F_347 ( V_19 , V_457 + V_45 ) ;
V_461 = F_348 ( V_460 ) ;
if ( ! V_460 || ! V_461 ) {
V_158 = - V_15 ;
goto V_465;
}
V_158 = - V_52 ;
V_30 = F_17 ( sizeof( * V_30 ) , V_25 ) ;
if ( ! V_30 )
goto V_465;
if ( ! F_319 ( V_346 ) )
V_30 -> V_4 = F_17 ( sizeof( union V_407 ) , V_25 ) ;
else
V_30 -> V_4 = F_17 ( sizeof( struct V_406 ) ,
V_25 ) ;
if ( ! V_30 -> V_4 ) {
F_176 ( V_30 ) ;
goto V_465;
}
V_460 -> V_466 = ( V_14 << 16 ) + V_45 ;
V_460 -> V_467 = V_30 ;
V_460 -> V_468 = & V_469 ;
F_343 ( V_30 , V_461 , V_379 , V_14 , V_239 , V_45 ) ;
F_349 ( V_457 + V_45 , V_470 ) ;
}
return 0 ;
V_465:
for ( V_45 -- ; V_45 >= 0 ; V_45 -- ) {
V_460 = F_347 ( V_19 , V_457 + V_45 ) ;
if ( V_460 )
F_176 ( V_460 -> V_467 ) ;
}
for ( V_45 = 0 ; V_45 < V_458 ; V_45 ++ )
F_323 ( V_14 , V_239 + V_45 ) ;
V_464:
F_350 ( V_19 , V_457 , V_458 ) ;
return V_158 ;
}
static void F_351 ( struct V_433 * V_19 , unsigned int V_457 ,
unsigned int V_458 )
{
struct V_438 * V_439 ;
struct V_460 * V_460 ;
struct V_408 * V_30 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_458 ; V_45 ++ ) {
V_460 = F_347 ( V_19 , V_457 + V_45 ) ;
if ( V_460 && V_460 -> V_467 ) {
V_30 = V_460 -> V_467 ;
V_439 = & V_30 -> V_438 ;
F_323 ( V_439 -> V_14 , V_439 -> V_239 ) ;
F_176 ( V_30 -> V_4 ) ;
F_176 ( V_30 ) ;
}
}
F_350 ( V_19 , V_457 , V_458 ) ;
}
static void F_352 ( struct V_433 * V_19 ,
struct V_460 * V_460 )
{
struct V_408 * V_30 = V_460 -> V_467 ;
struct V_438 * V_439 = & V_30 -> V_438 ;
struct V_51 * V_38 = V_34 [ V_439 -> V_14 ] ;
if ( V_38 )
V_38 -> V_401 -> V_471 ( V_30 -> V_4 , V_439 -> V_14 ,
V_439 -> V_239 ) ;
}
static void F_353 ( struct V_433 * V_19 ,
struct V_460 * V_460 )
{
struct V_408 * V_30 = V_460 -> V_467 ;
struct V_438 * V_439 = & V_30 -> V_438 ;
struct V_51 * V_38 = V_34 [ V_439 -> V_14 ] ;
if ( V_38 )
V_38 -> V_401 -> V_472 ( V_30 -> V_4 , V_439 -> V_14 ,
V_439 -> V_239 ) ;
}
static int F_354 ( struct V_460 * V_30 , void * V_473 )
{
struct V_51 * V_38 ;
struct V_474 * V_475 = V_473 ;
struct V_476 * V_477 = V_475 -> V_476 ;
struct V_408 * V_478 = V_30 -> V_467 ;
struct V_406 * V_407 = (struct V_406 * ) V_478 -> V_4 ;
struct V_438 * V_439 = & V_478 -> V_438 ;
struct V_23 * V_24 = F_21 ( V_439 -> V_14 ) ;
if ( ! V_24 || ! V_24 -> V_347 )
return 0 ;
V_475 -> V_478 = V_478 ;
if ( ! F_278 ( V_346 ) ) {
F_75 ( L_39 ,
V_114 ) ;
V_475 -> V_479 = false ;
}
V_38 = V_34 [ V_439 -> V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_475 -> V_480 = V_478 -> V_481 ;
if ( V_475 -> V_479 ) {
V_407 -> V_412 . V_419 . V_482 = ( V_475 -> V_483 >> 12 ) ;
V_407 -> V_412 . V_419 . V_417 = V_477 -> V_417 ;
V_407 -> V_409 . V_484 . V_423 = 1 ;
V_407 -> V_409 . V_484 . V_485 = V_475 -> V_485 ;
V_478 -> V_481 = V_475 -> V_485 ;
} else {
struct V_436 * V_461 = F_348 ( V_30 ) ;
V_407 -> V_412 . V_317 = 0 ;
V_407 -> V_409 . V_317 = 0 ;
V_407 -> V_412 . V_419 . V_417 = V_461 -> V_417 ;
V_407 -> V_409 . V_410 . V_423 = 0 ;
V_407 -> V_409 . V_410 . V_421 = V_461 -> V_418 ;
V_407 -> V_409 . V_410 . V_420 = V_445 -> V_446 ;
V_407 -> V_409 . V_410 . V_422 = V_445 -> V_447 ;
V_478 -> V_481 = 0 ;
}
return F_321 ( V_439 -> V_14 , V_439 -> V_239 , V_407 , V_478 ) ;
}
static int F_355 ( struct V_460 * V_30 ,
const struct V_486 * V_294 , bool V_487 )
{
struct V_408 * V_478 = V_30 -> V_467 ;
struct V_438 * V_439 = & V_478 -> V_438 ;
struct V_436 * V_461 = F_348 ( V_30 ) ;
struct V_460 * V_488 = V_30 -> V_489 ;
struct V_51 * V_38 = V_34 [ V_439 -> V_14 ] ;
int V_158 ;
if ( ! V_38 )
return - V_7 ;
V_158 = V_488 -> V_468 -> V_490 ( V_488 , V_294 , V_487 ) ;
if ( V_158 < 0 || V_158 == V_491 )
return V_158 ;
V_38 -> V_401 -> V_492 ( V_478 -> V_4 , V_439 -> V_14 ,
V_439 -> V_239 , V_461 -> V_417 , V_461 -> V_418 ) ;
F_356 ( V_461 ) ;
return V_491 ;
}
static void F_357 ( struct V_460 * V_460 , struct V_440 * V_441 )
{
struct V_408 * V_478 = V_460 -> V_467 ;
* V_441 = V_478 -> V_442 ;
}
int F_358 ( struct V_51 * V_38 )
{
V_38 -> V_434 = F_359 ( NULL , & V_493 , V_38 ) ;
if ( ! V_38 -> V_434 )
return - V_52 ;
V_38 -> V_434 -> V_488 = F_360 () ;
V_38 -> V_435 = F_361 ( V_38 -> V_434 ) ;
return 0 ;
}
int F_362 ( int V_268 , bool V_494 , void * V_30 )
{
unsigned long V_21 ;
struct V_51 * V_38 ;
struct V_389 * V_495 ;
struct V_408 * V_478 = (struct V_408 * ) V_30 ;
int V_14 = V_478 -> V_438 . V_14 ;
struct V_406 * V_4 = (struct V_406 * ) V_478 -> V_4 ;
struct V_406 * V_413 = (struct V_406 * ) V_478 -> V_413 ;
if ( ! F_278 ( V_346 ) ||
! V_413 || ! V_4 || ! V_4 -> V_409 . V_484 . V_423 )
return 0 ;
V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return - V_7 ;
V_495 = F_317 ( V_14 , false ) ;
if ( ! V_495 )
return - V_7 ;
F_18 ( & V_495 -> V_161 , V_21 ) ;
if ( V_413 -> V_409 . V_484 . V_423 ) {
if ( V_268 >= 0 )
V_413 -> V_409 . V_484 . V_421 = V_268 ;
V_413 -> V_409 . V_484 . V_494 = V_494 ;
F_363 () ;
}
F_20 ( & V_495 -> V_161 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
return 0 ;
}
