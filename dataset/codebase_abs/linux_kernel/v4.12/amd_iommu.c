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
for ( V_45 = 0 ; V_45 < F_115 () ; ++ V_45 ) {
if ( ! V_19 -> V_168 [ V_45 ] )
continue;
V_158 |= F_102 ( V_169 [ V_45 ] , & V_59 ) ;
}
F_9 (dev_data, &domain->dev_list, list) {
if ( ! V_24 -> V_165 . V_166 )
continue;
V_158 |= F_112 ( V_24 , V_64 , V_133 ) ;
}
F_86 ( V_158 ) ;
}
static void F_116 ( struct V_16 * V_19 ,
T_3 V_64 , T_6 V_133 )
{
F_114 ( V_19 , V_64 , V_133 , 0 ) ;
}
static void F_117 ( struct V_16 * V_19 )
{
F_114 ( V_19 , 0 , V_138 , 0 ) ;
}
static void F_118 ( struct V_16 * V_19 )
{
F_114 ( V_19 , 0 , V_138 , 1 ) ;
}
static void F_119 ( struct V_16 * V_19 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < F_115 () ; ++ V_45 ) {
if ( V_19 && ! V_19 -> V_168 [ V_45 ] )
continue;
F_103 ( V_169 [ V_45 ] ) ;
}
}
static void F_120 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list)
F_113 ( V_24 ) ;
}
static bool F_121 ( struct V_16 * V_19 ,
T_7 V_170 )
{
T_3 * V_171 ;
if ( V_19 -> V_172 == V_173 )
return false ;
V_171 = ( void * ) F_122 ( V_170 ) ;
if ( ! V_171 )
return false ;
* V_171 = F_123 ( V_19 -> V_172 ,
F_124 ( V_19 -> V_174 ) ) ;
V_19 -> V_174 = V_171 ;
V_19 -> V_172 += 1 ;
V_19 -> V_175 = true ;
return true ;
}
static T_3 * F_125 ( struct V_16 * V_19 ,
unsigned long V_64 ,
unsigned long V_176 ,
T_3 * * V_177 ,
T_7 V_170 )
{
int V_178 , V_179 ;
T_3 * V_171 , * V_180 ;
F_15 ( ! F_126 ( V_176 ) ) ;
while ( V_64 > F_127 ( V_19 -> V_172 ) )
F_121 ( V_19 , V_170 ) ;
V_178 = V_19 -> V_172 - 1 ;
V_171 = & V_19 -> V_174 [ F_128 ( V_178 , V_64 ) ] ;
V_64 = F_129 ( V_64 , V_176 ) ;
V_179 = F_130 ( V_176 ) ;
while ( V_178 > V_179 ) {
T_3 V_181 , V_182 ;
V_181 = * V_171 ;
if ( ! F_131 ( V_181 ) ) {
V_180 = ( T_3 * ) F_122 ( V_170 ) ;
if ( ! V_180 )
return NULL ;
V_182 = F_123 ( V_178 , F_124 ( V_180 ) ) ;
if ( F_132 ( V_171 , V_181 , V_182 ) != V_181 ) {
F_133 ( ( unsigned long ) V_180 ) ;
continue;
}
}
if ( F_134 ( * V_171 ) != V_178 )
return NULL ;
V_178 -= 1 ;
V_171 = F_135 ( * V_171 ) ;
if ( V_177 && V_178 == V_179 )
* V_177 = V_171 ;
V_171 = & V_171 [ F_128 ( V_178 , V_64 ) ] ;
}
return V_171 ;
}
static T_3 * F_136 ( struct V_16 * V_19 ,
unsigned long V_64 ,
unsigned long * V_176 )
{
int V_178 ;
T_3 * V_171 ;
if ( V_64 > F_127 ( V_19 -> V_172 ) )
return NULL ;
V_178 = V_19 -> V_172 - 1 ;
V_171 = & V_19 -> V_174 [ F_128 ( V_178 , V_64 ) ] ;
* V_176 = F_137 ( V_178 ) ;
while ( V_178 > 0 ) {
if ( ! F_131 ( * V_171 ) )
return NULL ;
if ( F_134 ( * V_171 ) == 7 ||
F_134 ( * V_171 ) == 0 )
break;
if ( F_134 ( * V_171 ) != V_178 )
return NULL ;
V_178 -= 1 ;
V_171 = F_135 ( * V_171 ) ;
V_171 = & V_171 [ F_128 ( V_178 , V_64 ) ] ;
* V_176 = F_137 ( V_178 ) ;
}
if ( F_134 ( * V_171 ) == 0x07 ) {
unsigned long V_183 ;
* V_176 = V_183 = F_138 ( * V_171 ) ;
V_183 = ~ ( ( F_139 ( V_183 ) << 3 ) - 1 ) ;
V_171 = ( T_3 * ) ( ( ( unsigned long ) V_171 ) & V_183 ) ;
}
return V_171 ;
}
static int F_140 ( struct V_16 * V_18 ,
unsigned long V_184 ,
unsigned long V_57 ,
unsigned long V_176 ,
int V_185 ,
T_7 V_170 )
{
T_3 V_181 , * V_171 ;
int V_45 , V_63 ;
F_15 ( ! F_141 ( V_184 , V_176 ) ) ;
F_15 ( ! F_141 ( V_57 , V_176 ) ) ;
if ( ! ( V_185 & V_186 ) )
return - V_15 ;
V_63 = F_139 ( V_176 ) ;
V_171 = F_125 ( V_18 , V_184 , V_176 , NULL , V_170 ) ;
if ( ! V_171 )
return - V_52 ;
for ( V_45 = 0 ; V_45 < V_63 ; ++ V_45 )
if ( F_131 ( V_171 [ V_45 ] ) )
return - V_187 ;
if ( V_63 > 1 ) {
V_181 = F_142 ( V_57 , V_176 ) ;
V_181 |= F_143 ( 7 ) | V_188 | V_189 ;
} else
V_181 = V_57 | V_188 | V_189 ;
if ( V_185 & V_190 )
V_181 |= V_191 ;
if ( V_185 & V_192 )
V_181 |= V_193 ;
for ( V_45 = 0 ; V_45 < V_63 ; ++ V_45 )
V_171 [ V_45 ] = V_181 ;
F_144 ( V_18 ) ;
return 0 ;
}
static unsigned long F_145 ( struct V_16 * V_18 ,
unsigned long V_184 ,
unsigned long V_176 )
{
unsigned long long V_194 ;
unsigned long V_195 ;
T_3 * V_171 ;
F_15 ( ! F_126 ( V_176 ) ) ;
V_194 = 0 ;
while ( V_194 < V_176 ) {
V_171 = F_136 ( V_18 , V_184 , & V_195 ) ;
if ( V_171 ) {
int V_45 , V_63 ;
V_63 = F_139 ( V_195 ) ;
for ( V_45 = 0 ; V_45 < V_63 ; V_45 ++ )
V_171 [ V_45 ] = 0ULL ;
}
V_184 = ( V_184 & ~ ( V_195 - 1 ) ) + V_195 ;
V_194 += V_195 ;
}
F_15 ( V_194 && ! F_126 ( V_194 ) ) ;
return V_194 ;
}
static unsigned long F_146 ( struct V_1 * V_2 ,
struct V_20 * V_196 ,
unsigned int V_135 , T_3 V_49 )
{
unsigned long V_197 = 0 ;
V_135 = F_147 ( V_135 ) ;
if ( V_49 > F_148 ( 32 ) )
V_197 = F_149 ( & V_196 -> V_198 , V_135 ,
F_150 ( F_148 ( 32 ) ) ) ;
if ( ! V_197 )
V_197 = F_149 ( & V_196 -> V_198 , V_135 , F_150 ( V_49 ) ) ;
return ( V_197 << V_199 ) ;
}
static void F_151 ( struct V_20 * V_196 ,
unsigned long V_64 ,
unsigned int V_135 )
{
V_135 = F_147 ( V_135 ) ;
V_64 >>= V_199 ;
F_152 ( & V_196 -> V_198 , V_64 , V_135 ) ;
}
static void F_153 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_200 , V_21 ) ;
F_154 ( & V_19 -> V_201 , & V_202 ) ;
F_20 ( & V_200 , V_21 ) ;
}
static void F_155 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_200 , V_21 ) ;
F_156 ( & V_19 -> V_201 ) ;
F_20 ( & V_200 , V_21 ) ;
}
static T_1 F_157 ( void )
{
unsigned long V_21 ;
int V_167 ;
F_158 ( & V_203 , V_21 ) ;
V_167 = F_159 ( V_204 , V_205 ) ;
F_15 ( V_167 == 0 ) ;
if ( V_167 > 0 && V_167 < V_205 )
F_160 ( V_167 , V_204 ) ;
else
V_167 = 0 ;
F_161 ( & V_203 , V_21 ) ;
return V_167 ;
}
static void F_162 ( int V_167 )
{
unsigned long V_21 ;
F_158 ( & V_203 , V_21 ) ;
if ( V_167 > 0 && V_167 < V_205 )
F_163 ( V_167 , V_204 ) ;
F_161 ( & V_203 , V_21 ) ;
}
static void F_164 ( struct V_16 * V_19 )
{
unsigned long V_206 = ( unsigned long ) V_19 -> V_174 ;
switch ( V_19 -> V_172 ) {
case V_207 :
break;
case V_208 :
F_133 ( V_206 ) ;
break;
case V_209 :
F_165 ( V_206 ) ;
break;
case V_210 :
F_166 ( V_206 ) ;
break;
case V_211 :
F_167 ( V_206 ) ;
break;
case V_212 :
F_168 ( V_206 ) ;
break;
case V_173 :
F_169 ( V_206 ) ;
break;
default:
F_170 () ;
}
}
static void F_171 ( T_3 * V_213 )
{
T_3 * V_214 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 512 ; ++ V_45 ) {
if ( ! ( V_213 [ V_45 ] & V_215 ) )
continue;
V_214 = F_172 ( V_213 [ V_45 ] & V_139 ) ;
F_133 ( ( unsigned long ) V_214 ) ;
}
}
static void F_173 ( T_3 * V_213 )
{
T_3 * V_214 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 512 ; ++ V_45 ) {
if ( ! ( V_213 [ V_45 ] & V_215 ) )
continue;
V_214 = F_172 ( V_213 [ V_45 ] & V_139 ) ;
F_171 ( V_214 ) ;
}
}
static void F_174 ( struct V_16 * V_19 )
{
if ( V_19 -> V_216 == 2 )
F_173 ( V_19 -> V_217 ) ;
else if ( V_19 -> V_216 == 1 )
F_171 ( V_19 -> V_217 ) ;
else
F_15 ( V_19 -> V_216 != 0 ) ;
F_133 ( ( unsigned long ) V_19 -> V_217 ) ;
}
static void F_175 ( struct V_20 * V_18 )
{
if ( ! V_18 )
return;
F_155 ( & V_18 -> V_19 ) ;
F_176 ( & V_18 -> V_198 ) ;
F_164 ( & V_18 -> V_19 ) ;
if ( V_18 -> V_19 . V_167 )
F_162 ( V_18 -> V_19 . V_167 ) ;
F_177 ( V_18 ) ;
}
static struct V_20 * F_178 ( void )
{
struct V_20 * V_196 ;
V_196 = F_17 ( sizeof( struct V_20 ) , V_25 ) ;
if ( ! V_196 )
return NULL ;
if ( F_179 ( & V_196 -> V_19 ) )
goto V_218;
V_196 -> V_19 . V_172 = V_210 ;
V_196 -> V_19 . V_174 = ( void * ) F_122 ( V_25 ) ;
V_196 -> V_19 . V_21 = V_22 ;
if ( ! V_196 -> V_19 . V_174 )
goto V_218;
F_180 ( & V_196 -> V_198 , V_137 ,
V_219 , V_220 ) ;
F_181 ( & V_221 , & V_196 -> V_198 ) ;
F_153 ( & V_196 -> V_19 ) ;
return V_196 ;
V_218:
F_175 ( V_196 ) ;
return NULL ;
}
static bool V_20 ( struct V_16 * V_19 )
{
return V_19 -> V_21 & V_22 ;
}
static void F_182 ( T_1 V_14 , struct V_16 * V_19 , bool V_165 )
{
T_3 V_222 = 0 ;
T_3 V_21 = 0 ;
if ( V_19 -> V_172 != V_207 )
V_222 = F_124 ( V_19 -> V_174 ) ;
V_222 |= ( V_19 -> V_172 & V_223 )
<< V_224 ;
V_222 |= V_191 | V_193 | V_188 | V_225 ;
V_21 = V_35 [ V_14 ] . V_30 [ 1 ] ;
if ( V_165 )
V_21 |= V_226 ;
if ( V_19 -> V_21 & V_227 ) {
T_3 V_228 = F_88 ( V_19 -> V_217 ) ;
T_3 V_216 = V_19 -> V_216 ;
T_3 V_229 ;
V_222 |= V_230 ;
V_222 |= ( V_216 & V_231 ) << V_232 ;
V_229 = F_183 ( ~ 0ULL ) << V_233 ;
V_21 &= ~ V_229 ;
V_229 = F_184 ( ~ 0ULL ) << V_234 ;
V_21 &= ~ V_229 ;
V_229 = F_185 ( V_228 ) << V_235 ;
V_222 |= V_229 ;
V_229 = F_183 ( V_228 ) << V_233 ;
V_21 |= V_229 ;
V_229 = F_184 ( V_228 ) << V_234 ;
V_21 |= V_229 ;
}
V_21 &= ~ ( 0xffffUL ) ;
V_21 |= V_19 -> V_167 ;
V_35 [ V_14 ] . V_30 [ 1 ] = V_21 ;
V_35 [ V_14 ] . V_30 [ 0 ] = V_222 ;
}
static void F_186 ( T_1 V_14 )
{
V_35 [ V_14 ] . V_30 [ 0 ] = V_188 | V_225 ;
V_35 [ V_14 ] . V_30 [ 1 ] &= V_236 ;
F_187 ( V_14 ) ;
}
static void F_188 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
struct V_51 * V_38 ;
T_1 V_29 ;
bool V_165 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_165 = V_24 -> V_165 . V_166 ;
V_24 -> V_19 = V_19 ;
F_154 ( & V_24 -> V_201 , & V_19 -> V_237 ) ;
V_19 -> V_168 [ V_38 -> V_238 ] += 1 ;
V_19 -> V_239 += 1 ;
F_182 ( V_24 -> V_14 , V_19 , V_165 ) ;
if ( V_29 != V_24 -> V_14 )
F_182 ( V_29 , V_19 , V_165 ) ;
F_113 ( V_24 ) ;
}
static void F_189 ( struct V_23 * V_24 )
{
struct V_51 * V_38 ;
T_1 V_29 ;
if ( ! V_24 -> V_19 )
return;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_24 -> V_19 -> V_168 [ V_38 -> V_238 ] -= 1 ;
V_24 -> V_19 -> V_239 -= 1 ;
V_24 -> V_19 = NULL ;
F_156 ( & V_24 -> V_201 ) ;
F_186 ( V_24 -> V_14 ) ;
if ( V_29 != V_24 -> V_14 )
F_186 ( V_29 ) ;
F_113 ( V_24 ) ;
}
static int F_190 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
int V_158 ;
F_86 ( ! F_191 () ) ;
F_192 ( & V_19 -> V_161 ) ;
V_158 = - V_187 ;
if ( V_24 -> V_19 != NULL )
goto V_28;
F_188 ( V_24 , V_19 ) ;
V_158 = 0 ;
V_28:
F_193 ( & V_19 -> V_161 ) ;
return V_158 ;
}
static void F_194 ( struct V_8 * V_9 )
{
F_195 ( V_9 ) ;
F_196 ( V_9 ) ;
F_197 ( V_9 ) ;
}
static int F_198 ( struct V_8 * V_9 )
{
T_1 V_240 ;
int V_46 ;
V_46 = F_38 ( V_9 , V_43 ) ;
if ( ! V_46 )
return - V_15 ;
F_199 ( V_9 , V_46 + V_241 , & V_240 ) ;
V_240 |= V_242 ;
F_200 ( V_9 , V_46 + V_241 , V_240 ) ;
return 0 ;
}
static int F_201 ( struct V_8 * V_9 )
{
bool V_243 ;
int V_244 , V_158 ;
V_244 = 32 ;
if ( F_39 ( V_9 , V_245 ) )
V_244 = 1 ;
V_243 = F_39 ( V_9 , V_246 ) ;
V_158 = F_202 ( V_9 , 0 ) ;
if ( V_158 )
goto V_247;
V_158 = F_203 ( V_9 ) ;
if ( V_158 )
goto V_247;
V_158 = F_204 ( V_9 , V_244 ) ;
if ( V_158 )
goto V_247;
if ( V_243 ) {
V_158 = F_198 ( V_9 ) ;
if ( V_158 )
goto V_247;
}
V_158 = F_205 ( V_9 , V_199 ) ;
if ( V_158 )
goto V_247;
return 0 ;
V_247:
F_196 ( V_9 ) ;
F_197 ( V_9 ) ;
return V_158 ;
}
static bool F_206 ( struct V_8 * V_9 )
{
T_1 V_116 ;
int V_46 ;
V_46 = F_38 ( V_9 , V_43 ) ;
if ( ! V_46 )
return false ;
F_199 ( V_9 , V_46 + V_248 , & V_116 ) ;
return ( V_116 & V_249 ) ? true : false ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_16 * V_19 )
{
struct V_8 * V_9 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
int V_158 ;
V_24 = F_32 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
goto V_250;
V_9 = F_6 ( V_2 ) ;
if ( V_19 -> V_21 & V_227 ) {
if ( ! V_24 -> V_251 )
return - V_15 ;
if ( V_24 -> V_53 ) {
if ( F_201 ( V_9 ) != 0 )
return - V_15 ;
V_24 -> V_165 . V_166 = true ;
V_24 -> V_165 . V_143 = F_208 ( V_9 ) ;
V_24 -> V_252 = F_206 ( V_9 ) ;
}
} else if ( V_253 &&
F_205 ( V_9 , V_199 ) == 0 ) {
V_24 -> V_165 . V_166 = true ;
V_24 -> V_165 . V_143 = F_208 ( V_9 ) ;
}
V_250:
F_158 ( & V_203 , V_21 ) ;
V_158 = F_190 ( V_24 , V_19 ) ;
F_161 ( & V_203 , V_21 ) ;
F_118 ( V_19 ) ;
return V_158 ;
}
static void F_209 ( struct V_23 * V_24 )
{
struct V_16 * V_19 ;
F_86 ( ! F_191 () ) ;
if ( F_86 ( ! V_24 -> V_19 ) )
return;
V_19 = V_24 -> V_19 ;
F_192 ( & V_19 -> V_161 ) ;
F_189 ( V_24 ) ;
F_193 ( & V_19 -> V_161 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
V_24 = F_32 ( V_2 ) ;
V_19 = V_24 -> V_19 ;
F_158 ( & V_203 , V_21 ) ;
F_209 ( V_24 ) ;
F_161 ( & V_203 , V_21 ) ;
if ( ! F_11 ( V_2 ) )
return;
if ( V_19 -> V_21 & V_227 && V_24 -> V_53 )
F_194 ( F_6 ( V_2 ) ) ;
else if ( V_24 -> V_165 . V_166 )
F_195 ( F_6 ( V_2 ) ) ;
V_24 -> V_165 . V_166 = false ;
}
static int F_210 ( struct V_1 * V_2 )
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
if ( V_158 != - V_254 )
F_53 ( L_29 ,
F_29 ( V_2 ) ) ;
F_47 ( V_2 ) ;
V_2 -> V_56 = & V_255 ;
goto V_256;
}
F_41 ( V_2 ) ;
V_24 = F_32 ( V_2 ) ;
F_15 ( ! V_24 ) ;
if ( V_257 || V_24 -> V_53 )
F_211 ( V_2 ) ;
V_19 = F_212 ( V_2 ) ;
if ( V_19 -> type == V_258 )
V_24 -> V_251 = true ;
else
V_2 -> V_56 = & V_259 ;
V_256:
F_103 ( V_38 ) ;
return 0 ;
}
static void F_213 ( struct V_1 * V_2 )
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
static struct V_39 * F_214 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) )
return F_215 ( V_2 ) ;
return F_33 ( V_2 ) ;
}
static void F_216 ( struct V_260 * V_261 )
{
struct V_16 * V_19 ;
unsigned long V_21 ;
int V_262 ;
F_18 ( & V_200 , V_21 ) ;
F_9 (domain, &amd_iommu_pd_list, list)
F_117 ( V_19 ) ;
F_20 ( & V_200 , V_21 ) ;
F_119 ( NULL ) ;
for ( V_262 = 0 ; V_262 < V_261 -> V_263 ; ++ V_262 ) {
struct V_264 * V_4 ;
V_4 = V_261 -> V_265 + V_262 ;
F_152 ( & V_4 -> V_196 -> V_198 ,
V_4 -> V_266 ,
V_4 -> V_135 ) ;
V_4 -> V_196 = NULL ;
}
V_261 -> V_263 = 0 ;
}
static void F_217 ( void )
{
int V_267 ;
F_218 (cpu) {
struct V_260 * V_261 ;
unsigned long V_21 ;
V_261 = F_219 ( & V_260 , V_267 ) ;
F_18 ( & V_261 -> V_161 , V_21 ) ;
if ( V_261 -> V_263 > 0 )
F_216 ( V_261 ) ;
F_20 ( & V_261 -> V_161 , V_21 ) ;
}
}
static void F_220 ( unsigned long V_268 )
{
F_221 ( & V_269 , 0 ) ;
F_217 () ;
}
static void F_222 ( struct V_20 * V_196 ,
unsigned long V_64 , unsigned long V_135 )
{
struct V_264 * V_4 ;
struct V_260 * V_261 ;
unsigned long V_21 ;
int V_262 ;
V_135 = F_147 ( V_135 ) ;
V_64 >>= V_199 ;
V_261 = F_223 ( & V_260 ) ;
F_18 ( & V_261 -> V_161 , V_21 ) ;
if ( V_261 -> V_263 == V_270 )
F_216 ( V_261 ) ;
V_262 = V_261 -> V_263 ++ ;
V_4 = V_261 -> V_265 + V_262 ;
V_4 -> V_266 = V_64 ;
V_4 -> V_135 = V_135 ;
V_4 -> V_196 = V_196 ;
F_20 ( & V_261 -> V_161 , V_21 ) ;
if ( F_224 ( & V_269 , 0 , 1 ) == 0 )
F_225 ( & V_271 , V_272 + F_226 ( 10 ) ) ;
F_227 ( & V_260 ) ;
}
static struct V_16 * F_228 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
if ( ! F_40 ( V_2 ) )
return F_34 ( - V_15 ) ;
V_19 = F_32 ( V_2 ) -> V_19 ;
if ( ! V_20 ( V_19 ) )
return F_34 ( - V_187 ) ;
return V_19 ;
}
static void F_229 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list) {
F_182 ( V_24 -> V_14 , V_19 , V_24 -> V_165 . V_166 ) ;
if ( V_24 -> V_14 == V_24 -> V_29 )
continue;
F_182 ( V_24 -> V_29 , V_19 , V_24 -> V_165 . V_166 ) ;
}
}
static void F_144 ( struct V_16 * V_19 )
{
if ( ! V_19 -> V_175 )
return;
F_229 ( V_19 ) ;
F_120 ( V_19 ) ;
F_118 ( V_19 ) ;
V_19 -> V_175 = false ;
}
static int F_230 ( enum V_273 V_274 )
{
if ( V_274 == V_275 )
return V_190 ;
else if ( V_274 == V_276 )
return V_192 ;
else if ( V_274 == V_277 )
return V_192 | V_190 ;
else
return 0 ;
}
static T_8 F_231 ( struct V_1 * V_2 ,
struct V_20 * V_196 ,
T_9 V_278 ,
T_6 V_133 ,
enum V_273 V_274 ,
T_3 V_49 )
{
T_8 V_279 = V_278 & ~ V_139 ;
T_8 V_64 , V_280 , V_158 ;
unsigned int V_135 ;
int V_185 = 0 ;
int V_45 ;
V_135 = F_93 ( V_278 , V_133 , V_137 ) ;
V_278 &= V_139 ;
V_64 = F_146 ( V_2 , V_196 , V_135 , V_49 ) ;
if ( V_64 == V_281 )
goto V_256;
V_185 = F_230 ( V_274 ) ;
V_280 = V_64 ;
for ( V_45 = 0 ; V_45 < V_135 ; ++ V_45 ) {
V_158 = F_140 ( & V_196 -> V_19 , V_280 , V_278 ,
V_137 , V_185 , V_282 ) ;
if ( V_158 )
goto V_283;
V_278 += V_137 ;
V_280 += V_137 ;
}
V_64 += V_279 ;
if ( F_232 ( V_284 ) ) {
F_116 ( & V_196 -> V_19 , V_64 , V_133 ) ;
F_119 ( & V_196 -> V_19 ) ;
}
V_256:
return V_64 ;
V_283:
for ( -- V_45 ; V_45 >= 0 ; -- V_45 ) {
V_280 -= V_137 ;
F_145 ( & V_196 -> V_19 , V_280 , V_137 ) ;
}
F_117 ( & V_196 -> V_19 ) ;
F_119 ( & V_196 -> V_19 ) ;
F_151 ( V_196 , V_64 , V_135 ) ;
return V_281 ;
}
static void F_233 ( struct V_20 * V_196 ,
T_8 V_285 ,
T_6 V_133 ,
int V_286 )
{
T_8 V_287 ;
T_8 V_45 , V_280 ;
unsigned int V_135 ;
V_287 = V_285 ;
V_135 = F_93 ( V_285 , V_133 , V_137 ) ;
V_285 &= V_139 ;
V_280 = V_285 ;
for ( V_45 = 0 ; V_45 < V_135 ; ++ V_45 ) {
F_145 ( & V_196 -> V_19 , V_280 , V_137 ) ;
V_280 += V_137 ;
}
if ( V_288 ) {
F_151 ( V_196 , V_285 , V_135 ) ;
F_117 ( & V_196 -> V_19 ) ;
F_119 ( & V_196 -> V_19 ) ;
} else {
F_222 ( V_196 , V_285 , V_135 ) ;
}
}
static T_8 F_234 ( struct V_1 * V_2 , struct V_180 * V_180 ,
unsigned long V_279 , T_6 V_133 ,
enum V_273 V_286 ,
unsigned long V_289 )
{
T_9 V_278 = F_235 ( V_180 ) + V_279 ;
struct V_16 * V_19 ;
struct V_20 * V_196 ;
T_3 V_49 ;
V_19 = F_228 ( V_2 ) ;
if ( F_236 ( V_19 ) == - V_15 )
return ( T_8 ) V_278 ;
else if ( F_43 ( V_19 ) )
return V_281 ;
V_49 = * V_2 -> V_49 ;
V_196 = F_14 ( V_19 ) ;
return F_231 ( V_2 , V_196 , V_278 , V_133 , V_286 , V_49 ) ;
}
static void F_237 ( struct V_1 * V_2 , T_8 V_285 , T_6 V_133 ,
enum V_273 V_286 , unsigned long V_289 )
{
struct V_16 * V_19 ;
struct V_20 * V_196 ;
V_19 = F_228 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return;
V_196 = F_14 ( V_19 ) ;
F_233 ( V_196 , V_285 , V_133 , V_286 ) ;
}
static int F_238 ( struct V_1 * V_2 ,
struct V_290 * V_291 ,
int V_292 )
{
unsigned long V_293 , V_294 ;
struct V_290 * V_136 ;
int V_45 , V_295 = 0 ;
V_293 = F_239 ( V_2 ) ;
V_294 = V_293 + 1 ? F_240 ( V_293 + 1 , V_137 ) >> V_199 :
1UL << ( V_296 - V_199 ) ;
F_241 (sglist, s, nelems, i) {
int V_13 , V_297 ;
V_136 -> V_298 = V_295 << V_199 ;
V_13 = V_295 % V_294 ;
V_297 = F_93 ( F_242 ( V_136 ) , V_136 -> V_299 , V_137 ) ;
if ( V_13 + V_297 > V_294 )
V_295 += V_294 - V_13 ;
V_295 += V_297 ;
}
return V_295 ;
}
static int F_243 ( struct V_1 * V_2 , struct V_290 * V_291 ,
int V_292 , enum V_273 V_274 ,
unsigned long V_289 )
{
int V_300 = 0 , V_295 = 0 , V_185 = 0 , V_45 ;
struct V_16 * V_19 ;
struct V_20 * V_196 ;
struct V_290 * V_136 ;
unsigned long V_64 ;
T_3 V_49 ;
V_19 = F_228 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return 0 ;
V_196 = F_14 ( V_19 ) ;
V_49 = * V_2 -> V_49 ;
V_295 = F_238 ( V_2 , V_291 , V_292 ) ;
V_64 = F_146 ( V_2 , V_196 , V_295 , V_49 ) ;
if ( V_64 == V_281 )
goto V_247;
V_185 = F_230 ( V_274 ) ;
F_241 (sglist, s, nelems, i) {
int V_301 , V_135 = F_93 ( F_242 ( V_136 ) , V_136 -> V_299 , V_137 ) ;
for ( V_301 = 0 ; V_301 < V_135 ; ++ V_301 ) {
unsigned long V_184 , V_57 ;
int V_158 ;
V_184 = V_64 + V_136 -> V_298 + ( V_301 << V_199 ) ;
V_57 = ( F_242 ( V_136 ) & V_139 ) + ( V_301 << V_199 ) ;
V_158 = F_140 ( V_19 , V_184 , V_57 , V_137 , V_185 , V_282 ) ;
if ( V_158 )
goto V_283;
V_300 += 1 ;
}
}
F_241 (sglist, s, nelems, i) {
V_136 -> V_298 += V_64 + V_136 -> V_279 ;
V_136 -> V_302 = V_136 -> V_299 ;
}
return V_292 ;
V_283:
F_53 ( L_30 ,
F_29 ( V_2 ) , V_295 ) ;
F_241 (sglist, s, nelems, i) {
int V_301 , V_135 = F_93 ( F_242 ( V_136 ) , V_136 -> V_299 , V_137 ) ;
for ( V_301 = 0 ; V_301 < V_135 ; ++ V_301 ) {
unsigned long V_184 ;
V_184 = V_64 + V_136 -> V_298 + ( V_301 << V_199 ) ;
F_145 ( V_19 , V_184 , V_137 ) ;
if ( -- V_300 )
goto V_303;
}
}
V_303:
F_152 ( & V_196 -> V_198 , V_64 , V_295 ) ;
V_247:
return 0 ;
}
static void F_244 ( struct V_1 * V_2 , struct V_290 * V_291 ,
int V_292 , enum V_273 V_286 ,
unsigned long V_289 )
{
struct V_16 * V_19 ;
struct V_20 * V_196 ;
unsigned long V_304 ;
int V_295 = 2 ;
V_19 = F_228 ( V_2 ) ;
if ( F_43 ( V_19 ) )
return;
V_304 = F_245 ( V_291 ) & V_139 ;
V_196 = F_14 ( V_19 ) ;
V_295 = F_238 ( V_2 , V_291 , V_292 ) ;
F_233 ( V_196 , V_304 , V_295 << V_199 , V_286 ) ;
}
static void * F_246 ( struct V_1 * V_2 , T_6 V_133 ,
T_8 * V_285 , T_7 V_305 ,
unsigned long V_289 )
{
T_3 V_49 = V_2 -> V_306 ;
struct V_16 * V_19 ;
struct V_20 * V_196 ;
struct V_180 * V_180 ;
V_19 = F_228 ( V_2 ) ;
if ( F_236 ( V_19 ) == - V_15 ) {
V_180 = F_247 ( V_305 , F_248 ( V_133 ) ) ;
* V_285 = F_235 ( V_180 ) ;
return F_249 ( V_180 ) ;
} else if ( F_43 ( V_19 ) )
return NULL ;
V_196 = F_14 ( V_19 ) ;
V_133 = F_250 ( V_133 ) ;
V_49 = V_2 -> V_306 ;
V_305 &= ~ ( V_307 | V_308 | V_309 ) ;
V_305 |= V_310 ;
V_180 = F_247 ( V_305 | V_311 , F_248 ( V_133 ) ) ;
if ( ! V_180 ) {
if ( ! F_251 ( V_305 ) )
return NULL ;
V_180 = F_252 ( V_2 , V_133 >> V_199 ,
F_248 ( V_133 ) , V_305 ) ;
if ( ! V_180 )
return NULL ;
}
if ( ! V_49 )
V_49 = * V_2 -> V_49 ;
* V_285 = F_231 ( V_2 , V_196 , F_235 ( V_180 ) ,
V_133 , V_277 , V_49 ) ;
if ( * V_285 == V_281 )
goto V_312;
return F_249 ( V_180 ) ;
V_312:
if ( ! F_253 ( V_2 , V_180 , V_133 >> V_199 ) )
F_254 ( V_180 , F_248 ( V_133 ) ) ;
return NULL ;
}
static void F_255 ( struct V_1 * V_2 , T_6 V_133 ,
void * V_313 , T_8 V_285 ,
unsigned long V_289 )
{
struct V_16 * V_19 ;
struct V_20 * V_196 ;
struct V_180 * V_180 ;
V_180 = F_256 ( V_313 ) ;
V_133 = F_250 ( V_133 ) ;
V_19 = F_228 ( V_2 ) ;
if ( F_43 ( V_19 ) )
goto V_314;
V_196 = F_14 ( V_19 ) ;
F_233 ( V_196 , V_285 , V_133 , V_277 ) ;
V_314:
if ( ! F_253 ( V_2 , V_180 , V_133 >> V_199 ) )
F_254 ( V_180 , F_248 ( V_133 ) ) ;
}
static int F_257 ( struct V_1 * V_2 , T_3 V_293 )
{
return F_40 ( V_2 ) ;
}
static int F_258 ( void )
{
struct V_8 * V_9 = NULL ;
struct V_315 * V_316 ;
F_180 ( & V_221 , V_137 ,
V_219 , V_220 ) ;
F_259 ( & V_221 . V_317 ,
& V_318 ) ;
V_316 = F_260 ( & V_221 ,
F_150 ( V_319 ) , F_150 ( V_320 ) ) ;
if ( ! V_316 ) {
F_53 ( L_31 ) ;
return - V_52 ;
}
V_316 = F_260 ( & V_221 ,
F_150 ( V_321 ) , F_150 ( V_322 ) ) ;
if ( ! V_316 ) {
F_53 ( L_32 ) ;
return - V_52 ;
}
F_261 (pdev) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_323 ; ++ V_45 ) {
struct V_324 * V_325 = & V_9 -> V_324 [ V_45 ] ;
if ( ! ( V_325 -> V_21 & V_326 ) )
continue;
V_316 = F_260 ( & V_221 ,
F_150 ( V_325 -> V_280 ) ,
F_150 ( V_325 -> V_327 ) ) ;
if ( ! V_316 ) {
F_53 ( L_33 ) ;
return - V_52 ;
}
}
}
return 0 ;
}
int T_10 F_262 ( void )
{
int V_158 , V_267 , V_328 = 0 ;
V_158 = F_263 () ;
if ( V_158 )
return V_158 ;
V_158 = F_258 () ;
if ( V_158 )
return V_158 ;
F_218 (cpu) {
struct V_260 * V_261 = F_219 ( & V_260 , V_267 ) ;
V_261 -> V_265 = F_17 ( V_270 *
sizeof( * V_261 -> V_265 ) ,
V_25 ) ;
if ( ! V_261 -> V_265 )
goto V_329;
F_264 ( & V_261 -> V_161 ) ;
}
V_328 = F_265 ( & V_330 , & V_331 ) ;
if ( V_328 )
return V_328 ;
#ifdef F_266
V_328 = F_265 ( & V_332 , & V_331 ) ;
if ( V_328 )
return V_328 ;
#endif
V_328 = F_265 ( & V_333 , & V_331 ) ;
if ( V_328 )
return V_328 ;
return 0 ;
V_329:
F_218 (cpu) {
struct V_260 * V_261 = F_219 ( & V_260 , V_267 ) ;
F_177 ( V_261 -> V_265 ) ;
}
return - V_52 ;
}
int T_10 F_267 ( void )
{
F_268 ( & V_271 , F_220 , 0 ) ;
F_221 ( & V_269 , 0 ) ;
V_334 = V_257 ? 1 : 0 ;
V_335 = 1 ;
if ( ! V_334 )
V_56 = & V_255 ;
if ( V_288 )
F_25 ( L_34 ) ;
else
F_25 ( L_35 ) ;
return 0 ;
}
static void F_269 ( struct V_16 * V_19 )
{
struct V_23 * V_4 ;
unsigned long V_21 ;
F_158 ( & V_203 , V_21 ) ;
while ( ! F_270 ( & V_19 -> V_237 ) ) {
V_4 = F_271 ( & V_19 -> V_237 ,
struct V_23 , V_201 ) ;
F_209 ( V_4 ) ;
}
F_161 ( & V_203 , V_21 ) ;
}
static void F_272 ( struct V_16 * V_19 )
{
if ( ! V_19 )
return;
F_155 ( V_19 ) ;
if ( V_19 -> V_167 )
F_162 ( V_19 -> V_167 ) ;
F_177 ( V_19 ) ;
}
static int F_179 ( struct V_16 * V_19 )
{
F_264 ( & V_19 -> V_161 ) ;
F_273 ( & V_19 -> V_336 ) ;
V_19 -> V_167 = F_157 () ;
if ( ! V_19 -> V_167 )
return - V_52 ;
F_274 ( & V_19 -> V_237 ) ;
return 0 ;
}
static struct V_16 * F_275 ( void )
{
struct V_16 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_25 ) ;
if ( ! V_19 )
return NULL ;
if ( F_179 ( V_19 ) )
goto V_247;
F_153 ( V_19 ) ;
return V_19 ;
V_247:
F_177 ( V_19 ) ;
return NULL ;
}
static struct V_17 * F_276 ( unsigned type )
{
struct V_16 * V_337 ;
struct V_20 * V_338 ;
switch ( type ) {
case V_339 :
V_337 = F_275 () ;
if ( ! V_337 )
return NULL ;
V_337 -> V_172 = V_210 ;
V_337 -> V_174 = ( void * ) F_122 ( V_25 ) ;
if ( ! V_337 -> V_174 ) {
F_272 ( V_337 ) ;
return NULL ;
}
V_337 -> V_19 . V_340 . V_341 = 0 ;
V_337 -> V_19 . V_340 . V_342 = ~ 0ULL ;
V_337 -> V_19 . V_340 . V_343 = true ;
break;
case V_344 :
V_338 = F_178 () ;
if ( ! V_338 ) {
F_53 ( L_36 ) ;
return NULL ;
}
V_337 = & V_338 -> V_19 ;
break;
case V_258 :
V_337 = F_275 () ;
if ( ! V_337 )
return NULL ;
V_337 -> V_172 = V_207 ;
break;
default:
return NULL ;
}
return & V_337 -> V_19 ;
}
static void F_277 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
struct V_20 * V_196 ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 -> V_239 > 0 )
F_269 ( V_19 ) ;
F_15 ( V_19 -> V_239 != 0 ) ;
if ( ! V_18 )
return;
switch ( V_18 -> type ) {
case V_344 :
F_217 () ;
V_196 = F_14 ( V_19 ) ;
F_175 ( V_196 ) ;
break;
default:
if ( V_19 -> V_172 != V_207 )
F_164 ( V_19 ) ;
if ( V_19 -> V_21 & V_227 )
F_174 ( V_19 ) ;
F_272 ( V_19 ) ;
break;
}
}
static void F_278 ( struct V_17 * V_18 ,
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
if ( F_279 ( V_345 ) &&
( V_18 -> type == V_339 ) )
V_24 -> V_346 = 0 ;
#endif
F_103 ( V_38 ) ;
}
static int F_280 ( struct V_17 * V_18 ,
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
V_158 = F_207 ( V_2 , V_19 ) ;
#ifdef F_80
if ( F_279 ( V_345 ) ) {
if ( V_18 -> type == V_339 )
V_24 -> V_346 = 1 ;
else
V_24 -> V_346 = 0 ;
}
#endif
F_103 ( V_38 ) ;
return V_158 ;
}
static int F_281 ( struct V_17 * V_18 , unsigned long V_315 ,
T_9 V_278 , T_6 V_176 , int V_347 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
int V_185 = 0 ;
int V_158 ;
if ( V_19 -> V_172 == V_207 )
return - V_15 ;
if ( V_347 & V_348 )
V_185 |= V_190 ;
if ( V_347 & V_349 )
V_185 |= V_192 ;
F_282 ( & V_19 -> V_336 ) ;
V_158 = F_140 ( V_19 , V_315 , V_278 , V_176 , V_185 , V_25 ) ;
F_283 ( & V_19 -> V_336 ) ;
return V_158 ;
}
static T_6 F_284 ( struct V_17 * V_18 , unsigned long V_315 ,
T_6 V_176 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
T_6 V_195 ;
if ( V_19 -> V_172 == V_207 )
return - V_15 ;
F_282 ( & V_19 -> V_336 ) ;
V_195 = F_145 ( V_19 , V_315 , V_176 ) ;
F_283 ( & V_19 -> V_336 ) ;
F_118 ( V_19 ) ;
return V_195 ;
}
static T_9 F_285 ( struct V_17 * V_18 ,
T_8 V_315 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_350 , V_351 ;
T_3 * V_171 , V_181 ;
if ( V_19 -> V_172 == V_207 )
return V_315 ;
V_171 = F_136 ( V_19 , V_315 , & V_351 ) ;
if ( ! V_171 || ! F_131 ( * V_171 ) )
return 0 ;
V_350 = V_351 - 1 ;
V_181 = * V_171 & V_352 ;
return ( V_181 & ~ V_350 ) | ( V_315 & V_350 ) ;
}
static bool F_286 ( enum V_353 V_354 )
{
switch ( V_354 ) {
case V_355 :
return true ;
case V_356 :
return ( V_357 == 1 ) ;
case V_358 :
return false ;
}
return false ;
}
static void F_287 ( struct V_1 * V_2 ,
struct V_359 * V_84 )
{
struct V_360 * V_361 ;
struct V_362 * V_4 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
F_9 (entry, &amd_iommu_unity_map, list) {
T_6 V_299 ;
int V_185 = 0 ;
if ( V_14 < V_4 -> V_363 || V_14 > V_4 -> V_364 )
continue;
V_299 = V_4 -> V_365 - V_4 -> V_366 ;
if ( V_4 -> V_185 & V_190 )
V_185 |= V_348 ;
if ( V_4 -> V_185 & V_192 )
V_185 |= V_349 ;
V_361 = F_288 ( V_4 -> V_366 ,
V_299 , V_185 ,
V_367 ) ;
if ( ! V_361 ) {
F_53 ( L_37 ,
F_29 ( V_2 ) ) ;
return;
}
F_19 ( & V_361 -> V_201 , V_84 ) ;
}
V_361 = F_288 ( V_319 ,
V_320 - V_319 + 1 ,
0 , V_368 ) ;
if ( ! V_361 )
return;
F_19 ( & V_361 -> V_201 , V_84 ) ;
V_361 = F_288 ( V_321 ,
V_322 - V_321 + 1 ,
0 , V_369 ) ;
if ( ! V_361 )
return;
F_19 ( & V_361 -> V_201 , V_84 ) ;
}
static void F_289 ( struct V_1 * V_2 ,
struct V_359 * V_84 )
{
struct V_360 * V_4 , * V_263 ;
F_290 (entry, next, head, list)
F_177 ( V_4 ) ;
}
static void F_291 ( struct V_1 * V_2 ,
struct V_17 * V_19 ,
struct V_360 * V_361 )
{
struct V_20 * V_196 = F_14 ( F_12 ( V_19 ) ) ;
unsigned long V_280 , V_327 ;
V_280 = F_150 ( V_361 -> V_280 ) ;
V_327 = F_150 ( V_361 -> V_280 + V_361 -> V_299 ) ;
F_292 ( F_260 ( & V_196 -> V_198 , V_280 , V_327 ) == NULL ) ;
}
int F_293 ( struct V_370 * V_371 )
{
return F_294 ( & V_99 , V_371 ) ;
}
int F_295 ( struct V_370 * V_371 )
{
return F_296 ( & V_99 , V_371 ) ;
}
void F_297 ( struct V_17 * V_18 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_19 -> V_172 = V_207 ;
V_19 -> V_175 = true ;
F_144 ( V_19 ) ;
F_164 ( V_19 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
}
int F_298 ( struct V_17 * V_18 , int V_372 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_373 , V_158 ;
if ( V_372 <= 0 || V_372 > ( V_374 + 1 ) )
return - V_15 ;
for ( V_373 = 0 ; ( V_372 - 1 ) & ~ 0x1ff ; V_372 >>= 9 )
V_373 += 1 ;
if ( V_373 > V_375 )
return - V_15 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = - V_187 ;
if ( V_19 -> V_239 > 0 || V_19 -> V_21 & V_227 )
goto V_256;
V_158 = - V_52 ;
V_19 -> V_217 = ( void * ) F_122 ( V_282 ) ;
if ( V_19 -> V_217 == NULL )
goto V_256;
V_19 -> V_216 = V_373 ;
V_19 -> V_21 |= V_227 ;
V_19 -> V_175 = true ;
F_144 ( V_19 ) ;
V_158 = 0 ;
V_256:
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
static int F_299 ( struct V_16 * V_19 , int V_96 ,
T_3 V_64 , bool V_133 )
{
struct V_23 * V_24 ;
struct V_58 V_59 ;
int V_45 , V_158 ;
if ( ! ( V_19 -> V_21 & V_227 ) )
return - V_15 ;
F_95 ( & V_59 , V_19 -> V_167 , V_96 , V_64 , V_133 ) ;
for ( V_45 = 0 ; V_45 < F_115 () ; ++ V_45 ) {
if ( V_19 -> V_168 [ V_45 ] == 0 )
continue;
V_158 = F_102 ( V_169 [ V_45 ] , & V_59 ) ;
if ( V_158 != 0 )
goto V_256;
}
F_119 ( V_19 ) ;
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
goto V_256;
}
F_119 ( V_19 ) ;
V_158 = 0 ;
V_256:
return V_158 ;
}
static int F_300 ( struct V_16 * V_19 , int V_96 ,
T_3 V_64 )
{
return F_299 ( V_19 , V_96 , V_64 , false ) ;
}
int F_301 ( struct V_17 * V_18 , int V_96 ,
T_3 V_64 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_158 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = F_300 ( V_19 , V_96 , V_64 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
static int F_302 ( struct V_16 * V_19 , int V_96 )
{
return F_299 ( V_19 , V_96 , V_138 ,
true ) ;
}
int F_303 ( struct V_17 * V_18 , int V_96 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_158 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = F_302 ( V_19 , V_96 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
static T_3 * F_304 ( T_3 * V_206 , int V_178 , int V_96 , bool V_376 )
{
int V_238 ;
T_3 * V_171 ;
while ( true ) {
V_238 = ( V_96 >> ( 9 * V_178 ) ) & 0x1ff ;
V_171 = & V_206 [ V_238 ] ;
if ( V_178 == 0 )
break;
if ( ! ( * V_171 & V_215 ) ) {
if ( ! V_376 )
return NULL ;
V_206 = ( void * ) F_122 ( V_282 ) ;
if ( V_206 == NULL )
return NULL ;
* V_171 = F_88 ( V_206 ) | V_215 ;
}
V_206 = F_172 ( * V_171 & V_139 ) ;
V_178 -= 1 ;
}
return V_171 ;
}
static int F_305 ( struct V_16 * V_19 , int V_96 ,
unsigned long V_377 )
{
T_3 * V_171 ;
if ( V_19 -> V_172 != V_207 )
return - V_15 ;
V_171 = F_304 ( V_19 -> V_217 , V_19 -> V_216 , V_96 , true ) ;
if ( V_171 == NULL )
return - V_52 ;
* V_171 = ( V_377 & V_139 ) | V_215 ;
return F_302 ( V_19 , V_96 ) ;
}
static int F_306 ( struct V_16 * V_19 , int V_96 )
{
T_3 * V_171 ;
if ( V_19 -> V_172 != V_207 )
return - V_15 ;
V_171 = F_304 ( V_19 -> V_217 , V_19 -> V_216 , V_96 , false ) ;
if ( V_171 == NULL )
return 0 ;
* V_171 = 0 ;
return F_302 ( V_19 , V_96 ) ;
}
int F_307 ( struct V_17 * V_18 , int V_96 ,
unsigned long V_377 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_158 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = F_305 ( V_19 , V_96 , V_377 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
int F_308 ( struct V_17 * V_18 , int V_96 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_158 ;
F_18 ( & V_19 -> V_161 , V_21 ) ;
V_158 = F_306 ( V_19 , V_96 ) ;
F_20 ( & V_19 -> V_161 , V_21 ) ;
return V_158 ;
}
int F_309 ( struct V_8 * V_9 , int V_96 ,
int V_116 , int V_98 )
{
struct V_23 * V_24 ;
struct V_51 * V_38 ;
struct V_58 V_59 ;
V_24 = F_32 ( & V_9 -> V_2 ) ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_97 ( & V_59 , V_24 -> V_14 , V_96 , V_116 ,
V_98 , V_24 -> V_252 ) ;
return F_102 ( V_38 , & V_59 ) ;
}
struct V_17 * F_310 ( struct V_8 * V_9 )
{
struct V_16 * V_337 ;
V_337 = F_228 ( & V_9 -> V_2 ) ;
if ( F_43 ( V_337 ) )
return NULL ;
if ( ! ( V_337 -> V_21 & V_227 ) )
return NULL ;
return & V_337 -> V_19 ;
}
void F_311 ( struct V_8 * V_9 , T_2 V_47 )
{
struct V_23 * V_24 ;
if ( ! F_312 () )
return;
V_24 = F_32 ( & V_9 -> V_2 ) ;
V_24 -> V_48 |= ( 1 << V_47 ) ;
}
int F_313 ( struct V_8 * V_9 ,
struct F_313 * V_378 )
{
int V_379 ;
int V_46 ;
if ( V_9 == NULL || V_378 == NULL )
return - V_15 ;
if ( ! F_312 () )
return - V_15 ;
memset ( V_378 , 0 , sizeof( * V_378 ) ) ;
V_46 = F_38 ( V_9 , V_42 ) ;
if ( V_46 )
V_378 -> V_21 |= V_380 ;
V_46 = F_38 ( V_9 , V_43 ) ;
if ( V_46 )
V_378 -> V_21 |= V_381 ;
V_46 = F_38 ( V_9 , V_44 ) ;
if ( V_46 ) {
int V_382 ;
V_379 = 1 << ( 9 * ( V_375 + 1 ) ) ;
V_379 = F_314 ( V_379 , ( 1 << 20 ) ) ;
V_378 -> V_21 |= V_383 ;
V_378 -> V_379 = F_314 ( F_315 ( V_9 ) , V_379 ) ;
V_382 = F_316 ( V_9 ) ;
if ( V_382 & V_384 )
V_378 -> V_21 |= V_385 ;
if ( V_382 & V_386 )
V_378 -> V_21 |= V_387 ;
}
return 0 ;
}
static void F_317 ( T_1 V_14 , struct V_388 * V_389 )
{
T_3 V_390 ;
V_390 = V_35 [ V_14 ] . V_30 [ 2 ] ;
V_390 &= ~ V_391 ;
V_390 |= F_124 ( V_389 -> V_389 ) ;
V_390 |= V_392 ;
V_390 |= V_393 ;
V_390 |= V_394 ;
V_35 [ V_14 ] . V_30 [ 2 ] = V_390 ;
}
static struct V_388 * F_318 ( T_1 V_14 , bool V_395 )
{
struct V_388 * V_389 = NULL ;
struct V_51 * V_38 ;
unsigned long V_21 ;
T_1 V_29 ;
F_158 ( & V_203 , V_21 ) ;
V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
goto V_28;
V_389 = V_396 [ V_14 ] ;
if ( V_389 )
goto V_28;
V_29 = V_33 [ V_14 ] ;
V_389 = V_396 [ V_29 ] ;
if ( V_389 ) {
V_396 [ V_14 ] = V_389 ;
F_317 ( V_14 , V_389 ) ;
F_104 ( V_38 , V_14 ) ;
goto V_256;
}
V_389 = F_17 ( sizeof( * V_389 ) , V_282 ) ;
if ( ! V_389 )
goto V_28;
F_264 ( & V_389 -> V_161 ) ;
if ( V_395 )
V_389 -> V_397 = 32 ;
V_389 -> V_389 = F_319 ( V_398 , V_282 ) ;
if ( ! V_389 -> V_389 ) {
F_177 ( V_389 ) ;
V_389 = NULL ;
goto V_28;
}
if ( ! F_320 ( V_345 ) )
memset ( V_389 -> V_389 , 0 ,
V_399 * sizeof( T_2 ) ) ;
else
memset ( V_389 -> V_389 , 0 ,
( V_399 * ( sizeof( T_3 ) * 2 ) ) ) ;
if ( V_395 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < 32 ; ++ V_45 )
V_38 -> V_400 -> V_401 ( V_389 , V_45 ) ;
}
V_396 [ V_14 ] = V_389 ;
F_317 ( V_14 , V_389 ) ;
F_104 ( V_38 , V_14 ) ;
if ( V_14 != V_29 ) {
V_396 [ V_29 ] = V_389 ;
F_317 ( V_29 , V_389 ) ;
F_104 ( V_38 , V_29 ) ;
}
V_256:
F_103 ( V_38 ) ;
V_28:
F_161 ( & V_203 , V_21 ) ;
return V_389 ;
}
static int F_321 ( T_1 V_14 , int V_63 )
{
struct V_388 * V_389 ;
unsigned long V_21 ;
int V_238 , V_402 ;
struct V_51 * V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return - V_7 ;
V_389 = F_318 ( V_14 , false ) ;
if ( ! V_389 )
return - V_7 ;
F_18 ( & V_389 -> V_161 , V_21 ) ;
for ( V_402 = 0 , V_238 = V_389 -> V_397 ;
V_238 < V_399 ;
++ V_238 ) {
if ( ! V_38 -> V_400 -> V_403 ( V_389 , V_238 ) )
V_402 += 1 ;
else
V_402 = 0 ;
if ( V_402 == V_63 ) {
for (; V_402 != 0 ; -- V_402 )
V_38 -> V_400 -> V_401 ( V_389 , V_238 - V_402 + 1 ) ;
V_238 -= V_63 - 1 ;
goto V_256;
}
}
V_238 = - V_404 ;
V_256:
F_20 ( & V_389 -> V_161 , V_21 ) ;
return V_238 ;
}
static int F_322 ( T_1 V_14 , int V_238 , struct V_405 * V_406 ,
struct V_407 * V_30 )
{
struct V_388 * V_389 ;
struct V_51 * V_38 ;
unsigned long V_21 ;
struct V_405 * V_4 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_389 = F_318 ( V_14 , false ) ;
if ( ! V_389 )
return - V_52 ;
F_18 ( & V_389 -> V_161 , V_21 ) ;
V_4 = (struct V_405 * ) V_389 -> V_389 ;
V_4 = & V_4 [ V_238 ] ;
V_4 -> V_408 . V_409 . V_410 = 0 ;
V_4 -> V_411 . V_316 = V_406 -> V_411 . V_316 ;
V_4 -> V_408 . V_316 = V_406 -> V_408 . V_316 ;
V_4 -> V_408 . V_409 . V_410 = 1 ;
if ( V_30 )
V_30 -> V_412 = V_4 ;
F_20 ( & V_389 -> V_161 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
return 0 ;
}
static int F_323 ( T_1 V_14 , int V_238 , union V_406 * V_406 )
{
struct V_388 * V_389 ;
struct V_51 * V_38 ;
unsigned long V_21 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_389 = F_318 ( V_14 , false ) ;
if ( ! V_389 )
return - V_52 ;
F_18 ( & V_389 -> V_161 , V_21 ) ;
V_389 -> V_389 [ V_238 ] = V_406 -> V_316 ;
F_20 ( & V_389 -> V_161 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
return 0 ;
}
static void F_324 ( T_1 V_14 , int V_238 )
{
struct V_388 * V_389 ;
struct V_51 * V_38 ;
unsigned long V_21 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return;
V_389 = F_318 ( V_14 , false ) ;
if ( ! V_389 )
return;
F_18 ( & V_389 -> V_161 , V_21 ) ;
V_38 -> V_400 -> V_413 ( V_389 , V_238 ) ;
F_20 ( & V_389 -> V_161 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
}
static void F_325 ( void * V_4 ,
T_2 V_414 , T_2 V_415 ,
T_5 V_416 , T_2 V_417 , int V_14 )
{
union V_406 * V_406 = (union V_406 * ) V_4 ;
V_406 -> V_316 = 0 ;
V_406 -> V_418 . V_416 = V_416 ;
V_406 -> V_418 . V_419 = V_414 ;
V_406 -> V_418 . V_420 = V_417 ;
V_406 -> V_418 . V_421 = V_415 ;
V_406 -> V_418 . V_410 = 1 ;
}
static void F_326 ( void * V_4 ,
T_2 V_414 , T_2 V_415 ,
T_5 V_416 , T_2 V_417 , int V_14 )
{
struct V_405 * V_406 = (struct V_405 * ) V_4 ;
V_406 -> V_408 . V_316 = 0 ;
V_406 -> V_411 . V_316 = 0 ;
V_406 -> V_408 . V_409 . V_419 = V_414 ;
V_406 -> V_408 . V_409 . V_421 = V_415 ;
V_406 -> V_411 . V_418 . V_416 = V_416 ;
V_406 -> V_408 . V_409 . V_420 = V_417 ;
V_406 -> V_408 . V_409 . V_410 = 1 ;
}
static void F_327 ( void * V_4 , T_1 V_14 , T_1 V_238 )
{
union V_406 * V_406 = (union V_406 * ) V_4 ;
V_406 -> V_418 . V_410 = 1 ;
F_323 ( V_14 , V_238 , V_406 ) ;
}
static void F_328 ( void * V_4 , T_1 V_14 , T_1 V_238 )
{
struct V_405 * V_406 = (struct V_405 * ) V_4 ;
V_406 -> V_408 . V_409 . V_410 = 1 ;
F_322 ( V_14 , V_238 , V_406 , NULL ) ;
}
static void F_329 ( void * V_4 , T_1 V_14 , T_1 V_238 )
{
union V_406 * V_406 = (union V_406 * ) V_4 ;
V_406 -> V_418 . V_410 = 0 ;
F_323 ( V_14 , V_238 , V_406 ) ;
}
static void F_330 ( void * V_4 , T_1 V_14 , T_1 V_238 )
{
struct V_405 * V_406 = (struct V_405 * ) V_4 ;
V_406 -> V_408 . V_409 . V_410 = 0 ;
F_322 ( V_14 , V_238 , V_406 , NULL ) ;
}
static void F_331 ( void * V_4 , T_1 V_14 , T_1 V_238 ,
T_5 V_416 , T_2 V_417 )
{
union V_406 * V_406 = (union V_406 * ) V_4 ;
V_406 -> V_418 . V_416 = V_416 ;
V_406 -> V_418 . V_420 = V_417 ;
F_323 ( V_14 , V_238 , V_406 ) ;
}
static void F_332 ( void * V_4 , T_1 V_14 , T_1 V_238 ,
T_5 V_416 , T_2 V_417 )
{
struct V_405 * V_406 = (struct V_405 * ) V_4 ;
struct V_23 * V_24 = F_21 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> V_346 ||
! V_406 -> V_408 . V_409 . V_422 ) {
V_406 -> V_411 . V_418 . V_416 = V_416 ;
V_406 -> V_408 . V_409 . V_420 = V_417 ;
F_322 ( V_14 , V_238 , V_406 , NULL ) ;
}
}
static void F_333 ( struct V_388 * V_389 , int V_238 )
{
V_389 -> V_389 [ V_238 ] = V_423 ;
}
static void F_334 ( struct V_388 * V_389 , int V_238 )
{
struct V_405 * V_214 = (struct V_405 * ) V_389 -> V_389 ;
struct V_405 * V_406 = & V_214 [ V_238 ] ;
memset ( & V_406 -> V_408 . V_316 , 0 , sizeof( T_3 ) ) ;
memset ( & V_406 -> V_411 . V_316 , 0 , sizeof( T_3 ) ) ;
V_406 -> V_411 . V_418 . V_416 = 0xff ;
}
static bool F_335 ( struct V_388 * V_389 , int V_238 )
{
union V_406 * V_214 = (union V_406 * ) V_389 -> V_389 ;
union V_406 * V_406 = & V_214 [ V_238 ] ;
return V_406 -> V_316 != 0 ;
}
static bool F_336 ( struct V_388 * V_389 , int V_238 )
{
struct V_405 * V_214 = (struct V_405 * ) V_389 -> V_389 ;
struct V_405 * V_406 = & V_214 [ V_238 ] ;
return V_406 -> V_411 . V_418 . V_416 != 0 ;
}
static void F_337 ( struct V_388 * V_389 , int V_238 )
{
V_389 -> V_389 [ V_238 ] = 0 ;
}
static void F_338 ( struct V_388 * V_389 , int V_238 )
{
struct V_405 * V_214 = (struct V_405 * ) V_389 -> V_389 ;
struct V_405 * V_406 = & V_214 [ V_238 ] ;
memset ( & V_406 -> V_408 . V_316 , 0 , sizeof( T_3 ) ) ;
memset ( & V_406 -> V_411 . V_316 , 0 , sizeof( T_3 ) ) ;
}
static int F_339 ( struct V_424 * V_378 )
{
int V_14 = - 1 ;
switch ( V_378 -> type ) {
case V_425 :
V_14 = F_340 ( V_378 -> V_426 ) ;
break;
case V_427 :
V_14 = F_341 ( V_378 -> V_428 ) ;
break;
case V_429 :
case V_430 :
V_14 = F_10 ( & V_378 -> V_431 -> V_2 ) ;
break;
default:
F_15 ( 1 ) ;
break;
}
return V_14 ;
}
static struct V_432 * F_342 ( struct V_424 * V_378 )
{
struct V_51 * V_38 ;
int V_14 ;
if ( ! V_378 )
return NULL ;
V_14 = F_339 ( V_378 ) ;
if ( V_14 >= 0 ) {
V_38 = V_34 [ V_14 ] ;
if ( V_38 )
return V_38 -> V_433 ;
}
return NULL ;
}
static struct V_432 * F_343 ( struct V_424 * V_378 )
{
struct V_51 * V_38 ;
int V_14 ;
if ( ! V_378 )
return NULL ;
switch ( V_378 -> type ) {
case V_429 :
case V_430 :
V_14 = F_10 ( & V_378 -> V_431 -> V_2 ) ;
if ( V_14 < 0 )
return NULL ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 )
return V_38 -> V_434 ;
break;
default:
break;
}
return NULL ;
}
static void F_344 ( struct V_407 * V_30 ,
struct V_435 * V_435 ,
struct V_424 * V_378 ,
int V_14 , int V_238 , int V_436 )
{
struct V_437 * V_438 = & V_30 -> V_437 ;
struct V_439 * V_440 = & V_30 -> V_441 ;
struct V_442 * V_4 ;
struct V_51 * V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return;
V_30 -> V_437 . V_14 = V_14 ;
V_30 -> V_437 . V_238 = V_238 + V_436 ;
V_38 -> V_400 -> V_443 ( V_30 -> V_4 , V_444 -> V_445 ,
V_444 -> V_446 , V_435 -> V_416 ,
V_435 -> V_417 , V_14 ) ;
switch ( V_378 -> type ) {
case V_425 :
V_4 = V_378 -> V_447 ;
V_378 -> V_447 = NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_416 = V_238 ;
V_4 -> V_293 = 0 ;
V_4 -> V_448 = V_378 -> V_449 ;
V_4 -> V_450 = V_378 -> V_451 ;
if ( V_378 -> V_449 )
V_4 -> V_293 = 1 ;
break;
case V_427 :
case V_429 :
case V_430 :
V_440 -> V_452 = V_453 ;
V_440 -> V_454 = V_455 ;
V_440 -> V_30 = V_438 -> V_238 ;
break;
default:
F_15 ( 1 ) ;
break;
}
}
static int F_345 ( struct V_432 * V_19 , unsigned int V_456 ,
unsigned int V_457 , void * V_458 )
{
struct V_424 * V_378 = V_458 ;
struct V_459 * V_459 ;
struct V_407 * V_30 = NULL ;
struct V_435 * V_460 ;
int V_45 , V_158 , V_14 ;
int V_238 = - 1 ;
if ( ! V_378 )
return - V_15 ;
if ( V_457 > 1 && V_378 -> type != V_429 &&
V_378 -> type != V_430 )
return - V_15 ;
if ( V_378 -> type == V_429 )
V_378 -> V_21 &= ~ V_461 ;
V_14 = F_339 ( V_378 ) ;
if ( V_14 < 0 )
return - V_15 ;
V_158 = F_346 ( V_19 , V_456 , V_457 , V_458 ) ;
if ( V_158 < 0 )
return V_158 ;
if ( V_378 -> type == V_425 ) {
if ( F_318 ( V_14 , true ) )
V_238 = V_378 -> V_462 ;
else
V_158 = - V_52 ;
} else {
V_238 = F_321 ( V_14 , V_457 ) ;
}
if ( V_238 < 0 ) {
F_347 ( L_38 ) ;
V_158 = V_238 ;
goto V_463;
}
for ( V_45 = 0 ; V_45 < V_457 ; V_45 ++ ) {
V_459 = F_348 ( V_19 , V_456 + V_45 ) ;
V_460 = F_349 ( V_459 ) ;
if ( ! V_459 || ! V_460 ) {
V_158 = - V_15 ;
goto V_464;
}
V_158 = - V_52 ;
V_30 = F_17 ( sizeof( * V_30 ) , V_25 ) ;
if ( ! V_30 )
goto V_464;
if ( ! F_320 ( V_345 ) )
V_30 -> V_4 = F_17 ( sizeof( union V_406 ) , V_25 ) ;
else
V_30 -> V_4 = F_17 ( sizeof( struct V_405 ) ,
V_25 ) ;
if ( ! V_30 -> V_4 ) {
F_177 ( V_30 ) ;
goto V_464;
}
V_459 -> V_465 = ( V_14 << 16 ) + V_45 ;
V_459 -> V_466 = V_30 ;
V_459 -> V_467 = & V_468 ;
F_344 ( V_30 , V_460 , V_378 , V_14 , V_238 , V_45 ) ;
F_350 ( V_456 + V_45 , V_469 ) ;
}
return 0 ;
V_464:
for ( V_45 -- ; V_45 >= 0 ; V_45 -- ) {
V_459 = F_348 ( V_19 , V_456 + V_45 ) ;
if ( V_459 )
F_177 ( V_459 -> V_466 ) ;
}
for ( V_45 = 0 ; V_45 < V_457 ; V_45 ++ )
F_324 ( V_14 , V_238 + V_45 ) ;
V_463:
F_351 ( V_19 , V_456 , V_457 ) ;
return V_158 ;
}
static void F_352 ( struct V_432 * V_19 , unsigned int V_456 ,
unsigned int V_457 )
{
struct V_437 * V_438 ;
struct V_459 * V_459 ;
struct V_407 * V_30 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_457 ; V_45 ++ ) {
V_459 = F_348 ( V_19 , V_456 + V_45 ) ;
if ( V_459 && V_459 -> V_466 ) {
V_30 = V_459 -> V_466 ;
V_438 = & V_30 -> V_437 ;
F_324 ( V_438 -> V_14 , V_438 -> V_238 ) ;
F_177 ( V_30 -> V_4 ) ;
F_177 ( V_30 ) ;
}
}
F_351 ( V_19 , V_456 , V_457 ) ;
}
static void F_353 ( struct V_432 * V_19 ,
struct V_459 * V_459 )
{
struct V_407 * V_30 = V_459 -> V_466 ;
struct V_437 * V_438 = & V_30 -> V_437 ;
struct V_51 * V_38 = V_34 [ V_438 -> V_14 ] ;
if ( V_38 )
V_38 -> V_400 -> V_470 ( V_30 -> V_4 , V_438 -> V_14 ,
V_438 -> V_238 ) ;
}
static void F_354 ( struct V_432 * V_19 ,
struct V_459 * V_459 )
{
struct V_407 * V_30 = V_459 -> V_466 ;
struct V_437 * V_438 = & V_30 -> V_437 ;
struct V_51 * V_38 = V_34 [ V_438 -> V_14 ] ;
if ( V_38 )
V_38 -> V_400 -> V_471 ( V_30 -> V_4 , V_438 -> V_14 ,
V_438 -> V_238 ) ;
}
static int F_355 ( struct V_459 * V_30 , void * V_472 )
{
struct V_51 * V_38 ;
struct V_473 * V_474 = V_472 ;
struct V_475 * V_476 = V_474 -> V_475 ;
struct V_407 * V_477 = V_30 -> V_466 ;
struct V_405 * V_406 = (struct V_405 * ) V_477 -> V_4 ;
struct V_437 * V_438 = & V_477 -> V_437 ;
struct V_23 * V_24 = F_21 ( V_438 -> V_14 ) ;
if ( ! V_24 || ! V_24 -> V_346 )
return 0 ;
V_474 -> V_477 = V_477 ;
if ( ! F_279 ( V_345 ) ) {
F_75 ( L_39 ,
V_114 ) ;
V_474 -> V_478 = false ;
}
V_38 = V_34 [ V_438 -> V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_474 -> V_479 = V_477 -> V_480 ;
if ( V_474 -> V_478 ) {
V_406 -> V_411 . V_418 . V_481 = ( V_474 -> V_482 >> 12 ) ;
V_406 -> V_411 . V_418 . V_416 = V_476 -> V_416 ;
V_406 -> V_408 . V_483 . V_422 = 1 ;
V_406 -> V_408 . V_483 . V_484 = V_474 -> V_484 ;
V_477 -> V_480 = V_474 -> V_484 ;
} else {
struct V_435 * V_460 = F_349 ( V_30 ) ;
V_406 -> V_411 . V_316 = 0 ;
V_406 -> V_408 . V_316 = 0 ;
V_406 -> V_411 . V_418 . V_416 = V_460 -> V_416 ;
V_406 -> V_408 . V_409 . V_422 = 0 ;
V_406 -> V_408 . V_409 . V_420 = V_460 -> V_417 ;
V_406 -> V_408 . V_409 . V_419 = V_444 -> V_445 ;
V_406 -> V_408 . V_409 . V_421 = V_444 -> V_446 ;
V_477 -> V_480 = 0 ;
}
return F_322 ( V_438 -> V_14 , V_438 -> V_238 , V_406 , V_477 ) ;
}
static int F_356 ( struct V_459 * V_30 ,
const struct V_485 * V_293 , bool V_486 )
{
struct V_407 * V_477 = V_30 -> V_466 ;
struct V_437 * V_438 = & V_477 -> V_437 ;
struct V_435 * V_460 = F_349 ( V_30 ) ;
struct V_459 * V_487 = V_30 -> V_488 ;
struct V_51 * V_38 = V_34 [ V_438 -> V_14 ] ;
int V_158 ;
if ( ! V_38 )
return - V_7 ;
V_158 = V_487 -> V_467 -> V_489 ( V_487 , V_293 , V_486 ) ;
if ( V_158 < 0 || V_158 == V_490 )
return V_158 ;
V_38 -> V_400 -> V_491 ( V_477 -> V_4 , V_438 -> V_14 ,
V_438 -> V_238 , V_460 -> V_416 , V_460 -> V_417 ) ;
F_357 ( V_460 ) ;
return V_490 ;
}
static void F_358 ( struct V_459 * V_459 , struct V_439 * V_440 )
{
struct V_407 * V_477 = V_459 -> V_466 ;
* V_440 = V_477 -> V_441 ;
}
int F_359 ( struct V_51 * V_38 )
{
V_38 -> V_433 = F_360 ( NULL , & V_492 , V_38 ) ;
if ( ! V_38 -> V_433 )
return - V_52 ;
V_38 -> V_433 -> V_487 = F_361 () ;
V_38 -> V_434 = F_362 ( V_38 -> V_433 ) ;
return 0 ;
}
int F_363 ( int V_267 , bool V_493 , void * V_30 )
{
unsigned long V_21 ;
struct V_51 * V_38 ;
struct V_388 * V_494 ;
struct V_407 * V_477 = (struct V_407 * ) V_30 ;
int V_14 = V_477 -> V_437 . V_14 ;
struct V_405 * V_4 = (struct V_405 * ) V_477 -> V_4 ;
struct V_405 * V_412 = (struct V_405 * ) V_477 -> V_412 ;
if ( ! F_279 ( V_345 ) ||
! V_412 || ! V_4 || ! V_4 -> V_408 . V_483 . V_422 )
return 0 ;
V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return - V_7 ;
V_494 = F_318 ( V_14 , false ) ;
if ( ! V_494 )
return - V_7 ;
F_18 ( & V_494 -> V_161 , V_21 ) ;
if ( V_412 -> V_408 . V_483 . V_422 ) {
if ( V_267 >= 0 )
V_412 -> V_408 . V_483 . V_420 = V_267 ;
V_412 -> V_408 . V_483 . V_493 = V_493 ;
F_364 () ;
}
F_20 ( & V_494 -> V_161 , V_21 ) ;
F_108 ( V_38 , V_14 ) ;
F_103 ( V_38 ) ;
return 0 ;
}
