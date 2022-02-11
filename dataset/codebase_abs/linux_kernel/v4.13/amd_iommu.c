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
F_21 ( & V_24 -> V_28 ) ;
return V_24 ;
}
static struct V_23 * F_22 ( T_1 V_14 )
{
struct V_23 * V_24 ;
unsigned long V_21 ;
F_18 ( & V_26 , V_21 ) ;
F_9 (dev_data, &dev_data_list, dev_data_list) {
if ( V_24 -> V_14 == V_14 )
goto V_29;
}
V_24 = NULL ;
V_29:
F_20 ( & V_26 , V_21 ) ;
return V_24 ;
}
static int F_23 ( struct V_8 * V_9 , T_1 V_30 , void * V_31 )
{
* ( T_1 * ) V_31 = V_30 ;
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
T_1 V_14 , V_32 , V_33 ;
V_14 = F_10 ( V_2 ) ;
V_32 = V_34 [ V_14 ] ;
F_25 ( V_9 , F_23 , & V_33 ) ;
if ( V_32 == V_33 )
return V_32 ;
if ( V_32 == V_14 ) {
if ( ! V_35 [ V_33 ] ) {
V_35 [ V_33 ] =
V_35 [ V_14 ] ;
memcpy ( V_36 [ V_33 ] . V_31 ,
V_36 [ V_14 ] . V_31 ,
sizeof( V_36 [ V_33 ] . V_31 ) ) ;
}
return V_33 ;
}
F_26 ( L_1
L_2
L_3 , F_27 ( V_32 ) , F_28 ( V_32 ) ,
F_29 ( V_32 ) , F_30 ( V_2 ) , V_9 -> V_37 , V_9 -> V_1 ,
F_27 ( V_33 ) , F_28 ( V_33 ) ,
F_29 ( V_33 ) ) ;
if ( V_33 == V_14 &&
F_27 ( V_32 ) == V_9 -> V_10 -> V_11 ) {
F_31 ( V_9 , V_32 & 0xff ) ;
F_26 ( L_4 ,
F_28 ( V_32 ) , F_29 ( V_32 ) ,
F_30 ( V_2 ) ) ;
}
return V_32 ;
}
static struct V_23 * F_32 ( T_1 V_14 )
{
struct V_23 * V_24 ;
V_24 = F_22 ( V_14 ) ;
if ( V_24 == NULL )
V_24 = F_16 ( V_14 ) ;
return V_24 ;
}
static struct V_23 * F_33 ( struct V_1 * V_2 )
{
return V_2 -> V_38 . V_39 ;
}
static struct V_40 * F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_13 , * V_4 = NULL ;
int V_14 ;
V_14 = F_8 ( V_2 , & V_4 ) ;
if ( V_14 < 0 )
return F_35 ( V_14 ) ;
F_9 (p, &acpihid_map, list) {
if ( ( V_14 == V_13 -> V_14 ) && V_13 -> V_41 )
V_4 -> V_41 = V_13 -> V_41 ;
}
if ( ! V_4 -> V_41 )
V_4 -> V_41 = F_36 ( V_2 ) ;
else
F_37 ( V_4 -> V_41 ) ;
return V_4 -> V_41 ;
}
static bool F_38 ( struct V_8 * V_9 )
{
static const int V_42 [] = {
V_43 ,
V_44 ,
V_45 ,
} ;
int V_46 , V_47 ;
for ( V_46 = 0 ; V_46 < 3 ; ++ V_46 ) {
V_47 = F_39 ( V_9 , V_42 [ V_46 ] ) ;
if ( V_47 == 0 )
return false ;
}
return true ;
}
static bool F_40 ( struct V_8 * V_9 , T_2 V_48 )
{
struct V_23 * V_24 ;
V_24 = F_33 ( & V_9 -> V_2 ) ;
return V_24 -> V_49 & ( 1 << V_48 ) ? true : false ;
}
static bool F_41 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ! V_2 || ! V_2 -> V_50 )
return false ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return false ;
if ( V_14 > V_51 )
return false ;
if ( V_35 [ V_14 ] == NULL )
return false ;
return true ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_40 * V_41 ;
V_41 = F_43 ( V_2 ) ;
if ( F_44 ( V_41 ) )
return;
F_45 ( V_41 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_52 * V_39 ;
int V_14 ;
if ( V_2 -> V_38 . V_39 )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_39 = V_35 [ V_14 ] ;
V_24 = F_32 ( V_14 ) ;
if ( ! V_24 )
return - V_53 ;
V_24 -> V_30 = F_24 ( V_2 ) ;
if ( F_11 ( V_2 ) && F_38 ( F_6 ( V_2 ) ) ) {
struct V_52 * V_39 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
V_24 -> V_54 = V_39 -> V_55 ;
}
V_2 -> V_38 . V_39 = V_24 ;
F_47 ( & V_39 -> V_39 , V_2 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_1 V_30 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_30 = F_24 ( V_2 ) ;
memset ( & V_36 [ V_14 ] , 0 , sizeof( struct V_56 ) ) ;
memset ( & V_36 [ V_30 ] , 0 , sizeof( struct V_56 ) ) ;
V_35 [ V_14 ] = NULL ;
V_35 [ V_30 ] = NULL ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_52 * V_39 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_39 = V_35 [ V_14 ] ;
V_24 = F_22 ( V_14 ) ;
if ( ! V_24 )
return;
if ( V_24 -> V_19 )
F_50 ( V_2 ) ;
F_51 ( & V_39 -> V_39 , V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_57 = NULL ;
}
static void F_53 ( T_1 V_14 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < 4 ; ++ V_46 )
F_54 ( L_5 , V_46 ,
V_36 [ V_14 ] . V_31 [ V_46 ] ) ;
}
static void F_55 ( unsigned long V_58 )
{
struct V_59 * V_60 = F_56 ( V_58 ) ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 4 ; ++ V_46 )
F_54 ( L_6 , V_46 , V_60 -> V_31 [ V_46 ] ) ;
}
static void F_57 ( T_1 V_14 , T_1 V_61 ,
T_3 V_62 , int V_21 )
{
struct V_23 * V_24 = NULL ;
struct V_8 * V_9 ;
V_9 = F_58 ( F_27 ( V_14 ) , V_14 & 0xff ) ;
if ( V_9 )
V_24 = F_33 ( & V_9 -> V_2 ) ;
if ( V_24 && F_59 ( & V_24 -> V_28 ) ) {
F_60 ( & V_9 -> V_2 , L_7 ,
V_61 , V_62 , V_21 ) ;
} else if ( F_61 () ) {
F_54 ( L_8 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_61 , V_62 , V_21 ) ;
}
if ( V_9 )
F_62 ( V_9 ) ;
}
static void F_63 ( struct V_52 * V_39 , void * V_63 )
{
int type , V_14 , V_64 , V_21 ;
volatile T_2 * V_65 = V_63 ;
int V_66 = 0 ;
T_3 V_62 ;
V_67:
type = ( V_65 [ 1 ] >> V_68 ) & V_69 ;
V_14 = ( V_65 [ 0 ] >> V_70 ) & V_71 ;
V_64 = ( V_65 [ 1 ] >> V_72 ) & V_73 ;
V_21 = ( V_65 [ 1 ] >> V_74 ) & V_75 ;
V_62 = ( T_3 ) ( ( ( T_3 ) V_65 [ 3 ] ) << 32 ) | V_65 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_66 == V_76 ) {
F_54 ( L_9 ) ;
return;
}
F_64 ( 1 ) ;
goto V_67;
}
if ( type == V_77 ) {
F_57 ( V_14 , V_64 , V_62 , V_21 ) ;
return;
} else {
F_65 ( V_78 L_10 ) ;
}
switch ( type ) {
case V_79 :
F_65 ( L_11
L_12 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_62 , V_21 ) ;
F_53 ( V_14 ) ;
break;
case V_80 :
F_65 ( L_13
L_12 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_62 , V_21 ) ;
break;
case V_81 :
F_65 ( L_14
L_15 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_64 , V_62 , V_21 ) ;
break;
case V_82 :
F_65 ( L_16 , V_62 ) ;
F_55 ( V_62 ) ;
break;
case V_83 :
F_65 ( L_17
L_18 , V_62 , V_21 ) ;
break;
case V_84 :
F_65 ( L_19
L_20 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_62 ) ;
break;
case V_85 :
F_65 ( L_21
L_12 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_62 , V_21 ) ;
break;
default:
F_65 ( V_78 L_22 , type ) ;
}
memset ( V_63 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_66 ( struct V_52 * V_39 )
{
T_2 V_86 , V_87 ;
V_86 = F_67 ( V_39 -> V_88 + V_89 ) ;
V_87 = F_67 ( V_39 -> V_88 + V_90 ) ;
while ( V_86 != V_87 ) {
F_63 ( V_39 , V_39 -> V_91 + V_86 ) ;
V_86 = ( V_86 + V_92 ) % V_93 ;
}
F_68 ( V_86 , V_39 -> V_88 + V_89 ) ;
}
static void F_69 ( struct V_52 * V_39 , T_3 * V_94 )
{
struct V_95 V_96 ;
if ( F_70 ( V_94 [ 0 ] ) != V_97 ) {
F_71 ( L_23 ) ;
return;
}
V_96 . V_62 = V_94 [ 1 ] ;
V_96 . V_98 = F_72 ( V_94 [ 0 ] ) ;
V_96 . V_99 = F_73 ( V_94 [ 0 ] ) ;
V_96 . V_100 = F_74 ( V_94 [ 0 ] ) ;
V_96 . V_21 = F_75 ( V_94 [ 0 ] ) ;
F_76 ( & V_101 , 0 , & V_96 ) ;
}
static void F_77 ( struct V_52 * V_39 )
{
T_2 V_86 , V_87 ;
if ( V_39 -> V_102 == NULL )
return;
V_86 = F_67 ( V_39 -> V_88 + V_103 ) ;
V_87 = F_67 ( V_39 -> V_88 + V_104 ) ;
while ( V_86 != V_87 ) {
volatile T_3 * V_94 ;
T_3 V_4 [ 2 ] ;
int V_46 ;
V_94 = ( T_3 * ) ( V_39 -> V_102 + V_86 ) ;
for ( V_46 = 0 ; V_46 < V_76 ; ++ V_46 ) {
if ( F_70 ( V_94 [ 0 ] ) != 0 )
break;
F_64 ( 1 ) ;
}
V_4 [ 0 ] = V_94 [ 0 ] ;
V_4 [ 1 ] = V_94 [ 1 ] ;
V_94 [ 0 ] = V_94 [ 1 ] = 0UL ;
V_86 = ( V_86 + V_105 ) % V_106 ;
F_68 ( V_86 , V_39 -> V_88 + V_103 ) ;
F_69 ( V_39 , V_4 ) ;
V_86 = F_67 ( V_39 -> V_88 + V_103 ) ;
V_87 = F_67 ( V_39 -> V_88 + V_104 ) ;
}
}
int F_78 ( int (* F_79)( T_2 ) )
{
V_107 = F_79 ;
return 0 ;
}
static void F_80 ( struct V_52 * V_39 )
{
T_2 V_86 , V_87 , V_108 = 0 ;
if ( V_39 -> V_109 == NULL )
return;
V_86 = F_67 ( V_39 -> V_88 + V_110 ) ;
V_87 = F_67 ( V_39 -> V_88 + V_111 ) ;
while ( V_86 != V_87 ) {
volatile T_3 * V_94 ;
T_3 V_112 ;
V_94 = ( T_3 * ) ( V_39 -> V_109 + V_86 ) ;
V_108 ++ ;
V_112 = * V_94 ;
V_86 = ( V_86 + V_113 ) % V_114 ;
F_68 ( V_86 , V_39 -> V_88 + V_110 ) ;
switch ( F_81 ( V_112 ) ) {
case V_115 :
if ( ! V_107 )
break;
F_82 ( L_24 ,
V_116 , F_83 ( V_112 ) ,
F_84 ( V_112 ) ) ;
if ( V_107 ( F_84 ( V_112 ) ) != 0 )
F_54 ( L_25 ) ;
break;
default:
break;
}
}
}
T_4 F_85 ( int V_117 , void * V_31 )
{
struct V_52 * V_39 = (struct V_52 * ) V_31 ;
T_2 V_118 = F_67 ( V_39 -> V_88 + V_119 ) ;
while ( V_118 & V_120 ) {
F_68 ( V_120 ,
V_39 -> V_88 + V_119 ) ;
if ( V_118 & V_121 ) {
F_86 ( L_26 ) ;
F_66 ( V_39 ) ;
}
if ( V_118 & V_122 ) {
F_86 ( L_27 ) ;
F_77 ( V_39 ) ;
}
#ifdef F_87
if ( V_118 & V_123 ) {
F_86 ( L_28 ) ;
F_80 ( V_39 ) ;
}
#endif
V_118 = F_67 ( V_39 -> V_88 + V_119 ) ;
}
return V_124 ;
}
T_4 F_88 ( int V_117 , void * V_31 )
{
return V_125 ;
}
static int F_89 ( volatile T_3 * V_126 )
{
int V_46 = 0 ;
while ( * V_126 == 0 && V_46 < V_76 ) {
F_64 ( 1 ) ;
V_46 += 1 ;
}
if ( V_46 == V_76 ) {
F_90 ( L_29 ) ;
return - V_127 ;
}
return 0 ;
}
static void F_91 ( struct V_52 * V_39 ,
struct V_59 * V_60 )
{
T_5 * V_128 ;
V_128 = V_39 -> V_129 + V_39 -> V_130 ;
V_39 -> V_130 += sizeof( * V_60 ) ;
V_39 -> V_130 %= V_131 ;
memcpy ( V_128 , V_60 , sizeof( * V_60 ) ) ;
F_68 ( V_39 -> V_130 , V_39 -> V_88 + V_132 ) ;
}
static void F_92 ( struct V_59 * V_60 , T_3 V_62 )
{
F_93 ( V_62 & 0x7ULL ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_31 [ 0 ] = F_94 ( F_95 ( V_62 ) ) | V_133 ;
V_60 -> V_31 [ 1 ] = F_96 ( F_95 ( V_62 ) ) ;
V_60 -> V_31 [ 2 ] = 1 ;
F_97 ( V_60 , V_134 ) ;
}
static void F_98 ( struct V_59 * V_60 , T_1 V_14 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_31 [ 0 ] = V_14 ;
F_97 ( V_60 , V_135 ) ;
}
static void F_99 ( struct V_59 * V_60 , T_3 V_62 ,
T_6 V_136 , T_1 V_64 , int V_137 )
{
T_3 V_138 ;
bool V_139 ;
V_138 = F_100 ( V_62 , V_136 , V_140 ) ;
V_139 = false ;
if ( V_138 > 1 ) {
V_62 = V_141 ;
V_139 = true ;
}
V_62 &= V_142 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_31 [ 1 ] |= V_64 ;
V_60 -> V_31 [ 2 ] = F_94 ( V_62 ) ;
V_60 -> V_31 [ 3 ] = F_96 ( V_62 ) ;
F_97 ( V_60 , V_143 ) ;
if ( V_139 )
V_60 -> V_31 [ 2 ] |= V_144 ;
if ( V_137 )
V_60 -> V_31 [ 2 ] |= V_145 ;
}
static void F_101 ( struct V_59 * V_60 , T_1 V_14 , int V_146 ,
T_3 V_62 , T_6 V_136 )
{
T_3 V_138 ;
bool V_139 ;
V_138 = F_100 ( V_62 , V_136 , V_140 ) ;
V_139 = false ;
if ( V_138 > 1 ) {
V_62 = V_141 ;
V_139 = true ;
}
V_62 &= V_142 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_31 [ 0 ] = V_14 ;
V_60 -> V_31 [ 0 ] |= ( V_146 & 0xff ) << 24 ;
V_60 -> V_31 [ 1 ] = V_14 ;
V_60 -> V_31 [ 2 ] = F_94 ( V_62 ) ;
V_60 -> V_31 [ 3 ] = F_96 ( V_62 ) ;
F_97 ( V_60 , V_147 ) ;
if ( V_139 )
V_60 -> V_31 [ 2 ] |= V_144 ;
}
static void F_102 ( struct V_59 * V_60 , T_1 V_64 , int V_98 ,
T_3 V_62 , bool V_136 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_62 &= ~ ( 0xfffULL ) ;
V_60 -> V_31 [ 0 ] = V_98 ;
V_60 -> V_31 [ 1 ] = V_64 ;
V_60 -> V_31 [ 2 ] = F_94 ( V_62 ) ;
V_60 -> V_31 [ 3 ] = F_96 ( V_62 ) ;
V_60 -> V_31 [ 2 ] |= V_145 ;
V_60 -> V_31 [ 2 ] |= V_148 ;
if ( V_136 )
V_60 -> V_31 [ 2 ] |= V_144 ;
F_97 ( V_60 , V_143 ) ;
}
static void F_103 ( struct V_59 * V_60 , T_1 V_14 , int V_98 ,
int V_146 , T_3 V_62 , bool V_136 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_62 &= ~ ( 0xfffULL ) ;
V_60 -> V_31 [ 0 ] = V_14 ;
V_60 -> V_31 [ 0 ] |= ( ( V_98 >> 8 ) & 0xff ) << 16 ;
V_60 -> V_31 [ 0 ] |= ( V_146 & 0xff ) << 24 ;
V_60 -> V_31 [ 1 ] = V_14 ;
V_60 -> V_31 [ 1 ] |= ( V_98 & 0xff ) << 16 ;
V_60 -> V_31 [ 2 ] = F_94 ( V_62 ) ;
V_60 -> V_31 [ 2 ] |= V_148 ;
V_60 -> V_31 [ 3 ] = F_96 ( V_62 ) ;
if ( V_136 )
V_60 -> V_31 [ 2 ] |= V_144 ;
F_97 ( V_60 , V_147 ) ;
}
static void F_104 ( struct V_59 * V_60 , T_1 V_14 , int V_98 ,
int V_118 , int V_100 , bool V_149 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_31 [ 0 ] = V_14 ;
if ( V_149 ) {
V_60 -> V_31 [ 1 ] = V_98 ;
V_60 -> V_31 [ 2 ] = V_148 ;
}
V_60 -> V_31 [ 3 ] = V_100 & 0x1ff ;
V_60 -> V_31 [ 3 ] |= ( V_118 & V_150 ) << V_151 ;
F_97 ( V_60 , V_152 ) ;
}
static void F_105 ( struct V_59 * V_60 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_97 ( V_60 , V_153 ) ;
}
static void F_106 ( struct V_59 * V_60 , T_1 V_14 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_31 [ 0 ] = V_14 ;
F_97 ( V_60 , V_154 ) ;
}
static int F_107 ( struct V_52 * V_39 ,
struct V_59 * V_60 ,
bool V_155 )
{
unsigned int V_66 = 0 ;
T_2 V_156 , V_157 ;
V_157 = ( V_39 -> V_130 + sizeof( * V_60 ) ) % V_131 ;
V_158:
V_156 = ( V_39 -> V_159 - V_157 ) % V_131 ;
if ( V_156 <= 0x20 ) {
if ( V_66 ++ ) {
if ( V_66 == V_76 ) {
F_54 ( L_30 ) ;
return - V_127 ;
}
F_64 ( 1 ) ;
}
V_39 -> V_159 = F_67 ( V_39 -> V_88 +
V_160 ) ;
goto V_158;
}
F_91 ( V_39 , V_60 ) ;
V_39 -> V_161 = V_155 ;
return 0 ;
}
static int F_108 ( struct V_52 * V_39 ,
struct V_59 * V_60 ,
bool V_155 )
{
unsigned long V_21 ;
int V_162 ;
F_18 ( & V_39 -> V_163 , V_21 ) ;
V_162 = F_107 ( V_39 , V_60 , V_155 ) ;
F_20 ( & V_39 -> V_163 , V_21 ) ;
return V_162 ;
}
static int F_109 ( struct V_52 * V_39 , struct V_59 * V_60 )
{
return F_108 ( V_39 , V_60 , true ) ;
}
static int F_110 ( struct V_52 * V_39 )
{
struct V_59 V_60 ;
unsigned long V_21 ;
int V_162 ;
if ( ! V_39 -> V_161 )
return 0 ;
F_92 ( & V_60 , ( T_3 ) & V_39 -> V_164 ) ;
F_18 ( & V_39 -> V_163 , V_21 ) ;
V_39 -> V_164 = 0 ;
V_162 = F_107 ( V_39 , & V_60 , false ) ;
if ( V_162 )
goto V_29;
V_162 = F_89 ( & V_39 -> V_164 ) ;
V_29:
F_20 ( & V_39 -> V_163 , V_21 ) ;
return V_162 ;
}
static int F_111 ( struct V_52 * V_39 , T_1 V_14 )
{
struct V_59 V_60 ;
F_98 ( & V_60 , V_14 ) ;
return F_109 ( V_39 , & V_60 ) ;
}
static void F_112 ( struct V_52 * V_39 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= 0xffff ; ++ V_14 )
F_111 ( V_39 , V_14 ) ;
F_110 ( V_39 ) ;
}
static void F_113 ( struct V_52 * V_39 )
{
T_2 V_165 ;
for ( V_165 = 0 ; V_165 <= 0xffff ; ++ V_165 ) {
struct V_59 V_60 ;
F_99 ( & V_60 , 0 , V_141 ,
V_165 , 1 ) ;
F_109 ( V_39 , & V_60 ) ;
}
F_110 ( V_39 ) ;
}
static void F_114 ( struct V_52 * V_39 )
{
struct V_59 V_60 ;
F_105 ( & V_60 ) ;
F_109 ( V_39 , & V_60 ) ;
F_110 ( V_39 ) ;
}
static void F_115 ( struct V_52 * V_39 , T_1 V_14 )
{
struct V_59 V_60 ;
F_106 ( & V_60 , V_14 ) ;
F_109 ( V_39 , & V_60 ) ;
}
static void F_116 ( struct V_52 * V_39 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= V_166 ; V_14 ++ )
F_115 ( V_39 , V_14 ) ;
F_110 ( V_39 ) ;
}
void F_117 ( struct V_52 * V_39 )
{
if ( F_118 ( V_39 , V_167 ) ) {
F_114 ( V_39 ) ;
} else {
F_112 ( V_39 ) ;
F_116 ( V_39 ) ;
F_113 ( V_39 ) ;
}
}
static int F_119 ( struct V_23 * V_24 ,
T_3 V_62 , T_6 V_136 )
{
struct V_52 * V_39 ;
struct V_59 V_60 ;
int V_146 ;
V_146 = V_24 -> V_168 . V_146 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
F_101 ( & V_60 , V_24 -> V_14 , V_146 , V_62 , V_136 ) ;
return F_109 ( V_39 , & V_60 ) ;
}
static int F_120 ( struct V_23 * V_24 )
{
struct V_52 * V_39 ;
T_1 V_30 ;
int V_162 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
V_30 = V_24 -> V_30 ;
V_162 = F_111 ( V_39 , V_24 -> V_14 ) ;
if ( ! V_162 && V_30 != V_24 -> V_14 )
V_162 = F_111 ( V_39 , V_30 ) ;
if ( V_162 )
return V_162 ;
if ( V_24 -> V_168 . V_169 )
V_162 = F_119 ( V_24 , 0 , ~ 0UL ) ;
return V_162 ;
}
static void F_121 ( struct V_16 * V_19 ,
T_3 V_62 , T_6 V_136 , int V_137 )
{
struct V_23 * V_24 ;
struct V_59 V_60 ;
int V_162 = 0 , V_46 ;
F_99 ( & V_60 , V_62 , V_136 , V_19 -> V_170 , V_137 ) ;
for ( V_46 = 0 ; V_46 < F_122 () ; ++ V_46 ) {
if ( ! V_19 -> V_171 [ V_46 ] )
continue;
V_162 |= F_109 ( V_172 [ V_46 ] , & V_60 ) ;
}
F_9 (dev_data, &domain->dev_list, list) {
if ( ! V_24 -> V_168 . V_169 )
continue;
V_162 |= F_119 ( V_24 , V_62 , V_136 ) ;
}
F_93 ( V_162 ) ;
}
static void F_123 ( struct V_16 * V_19 ,
T_3 V_62 , T_6 V_136 )
{
F_121 ( V_19 , V_62 , V_136 , 0 ) ;
}
static void F_124 ( struct V_16 * V_19 )
{
F_121 ( V_19 , 0 , V_141 , 0 ) ;
}
static void F_125 ( struct V_16 * V_19 )
{
F_121 ( V_19 , 0 , V_141 , 1 ) ;
}
static void F_126 ( struct V_16 * V_19 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < F_122 () ; ++ V_46 ) {
if ( V_19 && ! V_19 -> V_171 [ V_46 ] )
continue;
F_110 ( V_172 [ V_46 ] ) ;
}
}
static void F_127 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list)
F_120 ( V_24 ) ;
}
static bool F_128 ( struct V_16 * V_19 ,
T_7 V_173 )
{
T_3 * V_174 ;
if ( V_19 -> V_175 == V_176 )
return false ;
V_174 = ( void * ) F_129 ( V_173 ) ;
if ( ! V_174 )
return false ;
* V_174 = F_130 ( V_19 -> V_175 ,
F_131 ( V_19 -> V_177 ) ) ;
V_19 -> V_177 = V_174 ;
V_19 -> V_175 += 1 ;
V_19 -> V_178 = true ;
return true ;
}
static T_3 * F_132 ( struct V_16 * V_19 ,
unsigned long V_62 ,
unsigned long V_179 ,
T_3 * * V_180 ,
T_7 V_173 )
{
int V_181 , V_182 ;
T_3 * V_174 , * V_183 ;
F_15 ( ! F_133 ( V_179 ) ) ;
while ( V_62 > F_134 ( V_19 -> V_175 ) )
F_128 ( V_19 , V_173 ) ;
V_181 = V_19 -> V_175 - 1 ;
V_174 = & V_19 -> V_177 [ F_135 ( V_181 , V_62 ) ] ;
V_62 = F_136 ( V_62 , V_179 ) ;
V_182 = F_137 ( V_179 ) ;
while ( V_181 > V_182 ) {
T_3 V_184 , V_185 ;
V_184 = * V_174 ;
if ( ! F_138 ( V_184 ) ) {
V_183 = ( T_3 * ) F_129 ( V_173 ) ;
if ( ! V_183 )
return NULL ;
V_185 = F_130 ( V_181 , F_131 ( V_183 ) ) ;
if ( F_139 ( V_174 , V_184 , V_185 ) != V_184 ) {
F_140 ( ( unsigned long ) V_183 ) ;
continue;
}
}
if ( F_141 ( * V_174 ) != V_181 )
return NULL ;
V_181 -= 1 ;
V_174 = F_142 ( * V_174 ) ;
if ( V_180 && V_181 == V_182 )
* V_180 = V_174 ;
V_174 = & V_174 [ F_135 ( V_181 , V_62 ) ] ;
}
return V_174 ;
}
static T_3 * F_143 ( struct V_16 * V_19 ,
unsigned long V_62 ,
unsigned long * V_179 )
{
int V_181 ;
T_3 * V_174 ;
if ( V_62 > F_134 ( V_19 -> V_175 ) )
return NULL ;
V_181 = V_19 -> V_175 - 1 ;
V_174 = & V_19 -> V_177 [ F_135 ( V_181 , V_62 ) ] ;
* V_179 = F_144 ( V_181 ) ;
while ( V_181 > 0 ) {
if ( ! F_138 ( * V_174 ) )
return NULL ;
if ( F_141 ( * V_174 ) == 7 ||
F_141 ( * V_174 ) == 0 )
break;
if ( F_141 ( * V_174 ) != V_181 )
return NULL ;
V_181 -= 1 ;
V_174 = F_142 ( * V_174 ) ;
V_174 = & V_174 [ F_135 ( V_181 , V_62 ) ] ;
* V_179 = F_144 ( V_181 ) ;
}
if ( F_141 ( * V_174 ) == 0x07 ) {
unsigned long V_186 ;
* V_179 = V_186 = F_145 ( * V_174 ) ;
V_186 = ~ ( ( F_146 ( V_186 ) << 3 ) - 1 ) ;
V_174 = ( T_3 * ) ( ( ( unsigned long ) V_174 ) & V_186 ) ;
}
return V_174 ;
}
static int F_147 ( struct V_16 * V_18 ,
unsigned long V_187 ,
unsigned long V_58 ,
unsigned long V_179 ,
int V_188 ,
T_7 V_173 )
{
T_3 V_184 , * V_174 ;
int V_46 , V_66 ;
F_15 ( ! F_148 ( V_187 , V_179 ) ) ;
F_15 ( ! F_148 ( V_58 , V_179 ) ) ;
if ( ! ( V_188 & V_189 ) )
return - V_15 ;
V_66 = F_146 ( V_179 ) ;
V_174 = F_132 ( V_18 , V_187 , V_179 , NULL , V_173 ) ;
if ( ! V_174 )
return - V_53 ;
for ( V_46 = 0 ; V_46 < V_66 ; ++ V_46 )
if ( F_138 ( V_174 [ V_46 ] ) )
return - V_190 ;
if ( V_66 > 1 ) {
V_184 = F_149 ( V_58 , V_179 ) ;
V_184 |= F_150 ( 7 ) | V_191 | V_192 ;
} else
V_184 = V_58 | V_191 | V_192 ;
if ( V_188 & V_193 )
V_184 |= V_194 ;
if ( V_188 & V_195 )
V_184 |= V_196 ;
for ( V_46 = 0 ; V_46 < V_66 ; ++ V_46 )
V_174 [ V_46 ] = V_184 ;
F_151 ( V_18 ) ;
return 0 ;
}
static unsigned long F_152 ( struct V_16 * V_18 ,
unsigned long V_187 ,
unsigned long V_179 )
{
unsigned long long V_197 ;
unsigned long V_198 ;
T_3 * V_174 ;
F_15 ( ! F_133 ( V_179 ) ) ;
V_197 = 0 ;
while ( V_197 < V_179 ) {
V_174 = F_143 ( V_18 , V_187 , & V_198 ) ;
if ( V_174 ) {
int V_46 , V_66 ;
V_66 = F_146 ( V_198 ) ;
for ( V_46 = 0 ; V_46 < V_66 ; V_46 ++ )
V_174 [ V_46 ] = 0ULL ;
}
V_187 = ( V_187 & ~ ( V_198 - 1 ) ) + V_198 ;
V_197 += V_198 ;
}
F_15 ( V_197 && ! F_133 ( V_197 ) ) ;
return V_197 ;
}
static unsigned long F_153 ( struct V_1 * V_2 ,
struct V_20 * V_199 ,
unsigned int V_138 , T_3 V_50 )
{
unsigned long V_200 = 0 ;
V_138 = F_154 ( V_138 ) ;
if ( V_50 > F_155 ( 32 ) )
V_200 = F_156 ( & V_199 -> V_201 , V_138 ,
F_157 ( F_155 ( 32 ) ) ) ;
if ( ! V_200 )
V_200 = F_156 ( & V_199 -> V_201 , V_138 , F_157 ( V_50 ) ) ;
return ( V_200 << V_202 ) ;
}
static void F_158 ( struct V_20 * V_199 ,
unsigned long V_62 ,
unsigned int V_138 )
{
V_138 = F_154 ( V_138 ) ;
V_62 >>= V_202 ;
F_159 ( & V_199 -> V_201 , V_62 , V_138 ) ;
}
static void F_160 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_203 , V_21 ) ;
F_161 ( & V_19 -> V_204 , & V_205 ) ;
F_20 ( & V_203 , V_21 ) ;
}
static void F_162 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_203 , V_21 ) ;
F_163 ( & V_19 -> V_204 ) ;
F_20 ( & V_203 , V_21 ) ;
}
static T_1 F_164 ( void )
{
unsigned long V_21 ;
int V_170 ;
F_165 ( & V_206 , V_21 ) ;
V_170 = F_166 ( V_207 , V_208 ) ;
F_15 ( V_170 == 0 ) ;
if ( V_170 > 0 && V_170 < V_208 )
F_167 ( V_170 , V_207 ) ;
else
V_170 = 0 ;
F_168 ( & V_206 , V_21 ) ;
return V_170 ;
}
static void F_169 ( int V_170 )
{
unsigned long V_21 ;
F_165 ( & V_206 , V_21 ) ;
if ( V_170 > 0 && V_170 < V_208 )
F_170 ( V_170 , V_207 ) ;
F_168 ( & V_206 , V_21 ) ;
}
static void F_171 ( struct V_16 * V_19 )
{
unsigned long V_209 = ( unsigned long ) V_19 -> V_177 ;
switch ( V_19 -> V_175 ) {
case V_210 :
break;
case V_211 :
F_140 ( V_209 ) ;
break;
case V_212 :
F_172 ( V_209 ) ;
break;
case V_213 :
F_173 ( V_209 ) ;
break;
case V_214 :
F_174 ( V_209 ) ;
break;
case V_215 :
F_175 ( V_209 ) ;
break;
case V_176 :
F_176 ( V_209 ) ;
break;
default:
F_177 () ;
}
}
static void F_178 ( T_3 * V_216 )
{
T_3 * V_217 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 512 ; ++ V_46 ) {
if ( ! ( V_216 [ V_46 ] & V_218 ) )
continue;
V_217 = F_179 ( V_216 [ V_46 ] & V_142 ) ;
F_140 ( ( unsigned long ) V_217 ) ;
}
}
static void F_180 ( T_3 * V_216 )
{
T_3 * V_217 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 512 ; ++ V_46 ) {
if ( ! ( V_216 [ V_46 ] & V_218 ) )
continue;
V_217 = F_179 ( V_216 [ V_46 ] & V_142 ) ;
F_178 ( V_217 ) ;
}
}
static void F_181 ( struct V_16 * V_19 )
{
if ( V_19 -> V_219 == 2 )
F_180 ( V_19 -> V_220 ) ;
else if ( V_19 -> V_219 == 1 )
F_178 ( V_19 -> V_220 ) ;
else
F_15 ( V_19 -> V_219 != 0 ) ;
F_140 ( ( unsigned long ) V_19 -> V_220 ) ;
}
static void F_182 ( struct V_20 * V_18 )
{
int V_221 ;
F_183 (cpu) {
struct V_222 * V_223 ;
V_223 = F_184 ( V_18 -> V_222 , V_221 ) ;
F_185 ( V_223 -> V_224 ) ;
}
F_186 ( V_18 -> V_222 ) ;
V_18 -> V_222 = NULL ;
}
static int F_187 ( struct V_20 * V_18 )
{
int V_221 ;
F_188 ( & V_18 -> V_225 , 0 ) ;
F_188 ( & V_18 -> V_226 , 0 ) ;
V_18 -> V_222 = F_189 ( struct V_222 ) ;
if ( ! V_18 -> V_222 )
return - V_53 ;
F_183 (cpu) {
struct V_222 * V_223 ;
V_223 = F_184 ( V_18 -> V_222 , V_221 ) ;
V_223 -> V_86 = 0 ;
V_223 -> V_87 = 0 ;
V_223 -> V_224 = NULL ;
}
F_183 (cpu) {
struct V_222 * V_223 ;
V_223 = F_184 ( V_18 -> V_222 , V_221 ) ;
V_223 -> V_224 = F_17 ( V_227 * sizeof( * V_223 -> V_224 ) ,
V_25 ) ;
if ( ! V_223 -> V_224 ) {
F_182 ( V_18 ) ;
return - V_53 ;
}
F_190 ( & V_223 -> V_163 ) ;
}
return 0 ;
}
static void F_191 ( struct V_20 * V_18 )
{
F_192 ( & V_18 -> V_225 ) ;
F_124 ( & V_18 -> V_19 ) ;
F_126 ( & V_18 -> V_19 ) ;
F_192 ( & V_18 -> V_226 ) ;
}
static inline bool F_193 ( struct V_222 * V_223 )
{
F_194 ( & V_223 -> V_163 ) ;
return ( ( ( V_223 -> V_87 + 1 ) % V_227 ) == V_223 -> V_86 ) ;
}
static inline unsigned F_195 ( struct V_222 * V_223 )
{
unsigned V_228 = V_223 -> V_87 ;
F_194 ( & V_223 -> V_163 ) ;
V_223 -> V_87 = ( V_228 + 1 ) % V_227 ;
return V_228 ;
}
static inline void F_196 ( struct V_222 * V_223 )
{
F_194 ( & V_223 -> V_163 ) ;
V_223 -> V_86 = ( V_223 -> V_86 + 1 ) % V_227 ;
}
static void F_197 ( struct V_20 * V_18 ,
struct V_222 * V_223 )
{
T_3 V_229 = F_198 ( & V_18 -> V_226 ) ;
int V_228 ;
F_199 (idx, queue) {
if ( V_223 -> V_224 [ V_228 ] . V_229 >= V_229 )
break;
F_159 ( & V_18 -> V_201 ,
V_223 -> V_224 [ V_228 ] . V_230 ,
V_223 -> V_224 [ V_228 ] . V_138 ) ;
F_196 ( V_223 ) ;
}
}
static void F_200 ( struct V_20 * V_18 ,
unsigned long V_62 , unsigned long V_138 )
{
struct V_222 * V_223 ;
unsigned long V_21 ;
int V_228 ;
V_138 = F_154 ( V_138 ) ;
V_62 >>= V_202 ;
V_223 = F_201 ( V_18 -> V_222 ) ;
F_18 ( & V_223 -> V_163 , V_21 ) ;
F_197 ( V_18 , V_223 ) ;
if ( F_193 ( V_223 ) ) {
F_191 ( V_18 ) ;
F_197 ( V_18 , V_223 ) ;
}
V_228 = F_195 ( V_223 ) ;
V_223 -> V_224 [ V_228 ] . V_230 = V_62 ;
V_223 -> V_224 [ V_228 ] . V_138 = V_138 ;
V_223 -> V_224 [ V_228 ] . V_229 = F_198 ( & V_18 -> V_225 ) ;
F_20 ( & V_223 -> V_163 , V_21 ) ;
if ( F_202 ( & V_18 -> V_231 , 0 , 1 ) == 0 )
F_203 ( & V_18 -> V_232 , V_233 + F_204 ( 10 ) ) ;
F_205 ( V_18 -> V_222 ) ;
}
static void F_206 ( unsigned long V_31 )
{
struct V_20 * V_18 = (struct V_20 * ) V_31 ;
int V_221 ;
F_207 ( & V_18 -> V_231 , 0 ) ;
F_191 ( V_18 ) ;
F_183 (cpu) {
struct V_222 * V_223 ;
unsigned long V_21 ;
V_223 = F_184 ( V_18 -> V_222 , V_221 ) ;
F_18 ( & V_223 -> V_163 , V_21 ) ;
F_197 ( V_18 , V_223 ) ;
F_20 ( & V_223 -> V_163 , V_21 ) ;
}
}
static void F_208 ( struct V_20 * V_18 )
{
if ( ! V_18 )
return;
F_162 ( & V_18 -> V_19 ) ;
if ( F_209 ( & V_18 -> V_232 ) )
F_210 ( & V_18 -> V_232 ) ;
F_182 ( V_18 ) ;
F_211 ( & V_18 -> V_201 ) ;
F_171 ( & V_18 -> V_19 ) ;
if ( V_18 -> V_19 . V_170 )
F_169 ( V_18 -> V_19 . V_170 ) ;
F_185 ( V_18 ) ;
}
static struct V_20 * F_212 ( void )
{
struct V_20 * V_199 ;
V_199 = F_17 ( sizeof( struct V_20 ) , V_25 ) ;
if ( ! V_199 )
return NULL ;
if ( F_213 ( & V_199 -> V_19 ) )
goto V_234;
V_199 -> V_19 . V_175 = V_213 ;
V_199 -> V_19 . V_177 = ( void * ) F_129 ( V_25 ) ;
V_199 -> V_19 . V_21 = V_22 ;
if ( ! V_199 -> V_19 . V_177 )
goto V_234;
F_214 ( & V_199 -> V_201 , V_140 ,
V_235 , V_236 ) ;
F_215 ( & V_237 , & V_199 -> V_201 ) ;
if ( F_187 ( V_199 ) )
goto V_234;
F_216 ( & V_199 -> V_232 , F_206 ,
( unsigned long ) V_199 ) ;
F_207 ( & V_199 -> V_231 , 0 ) ;
F_160 ( & V_199 -> V_19 ) ;
return V_199 ;
V_234:
F_208 ( V_199 ) ;
return NULL ;
}
static bool V_20 ( struct V_16 * V_19 )
{
return V_19 -> V_21 & V_22 ;
}
static void F_217 ( T_1 V_14 , struct V_16 * V_19 , bool V_168 )
{
T_3 V_238 = 0 ;
T_3 V_21 = 0 ;
if ( V_19 -> V_175 != V_210 )
V_238 = F_131 ( V_19 -> V_177 ) ;
V_238 |= ( V_19 -> V_175 & V_239 )
<< V_240 ;
V_238 |= V_194 | V_196 | V_191 | V_241 ;
V_21 = V_36 [ V_14 ] . V_31 [ 1 ] ;
if ( V_168 )
V_21 |= V_242 ;
if ( V_19 -> V_21 & V_243 ) {
T_3 V_244 = F_95 ( V_19 -> V_220 ) ;
T_3 V_219 = V_19 -> V_219 ;
T_3 V_245 ;
V_238 |= V_246 ;
V_238 |= ( V_219 & V_247 ) << V_248 ;
V_245 = F_218 ( ~ 0ULL ) << V_249 ;
V_21 &= ~ V_245 ;
V_245 = F_219 ( ~ 0ULL ) << V_250 ;
V_21 &= ~ V_245 ;
V_245 = F_220 ( V_244 ) << V_251 ;
V_238 |= V_245 ;
V_245 = F_218 ( V_244 ) << V_249 ;
V_21 |= V_245 ;
V_245 = F_219 ( V_244 ) << V_250 ;
V_21 |= V_245 ;
}
V_21 &= ~ ( V_252 | 0xffffULL ) ;
V_21 |= V_19 -> V_170 ;
V_36 [ V_14 ] . V_31 [ 1 ] = V_21 ;
V_36 [ V_14 ] . V_31 [ 0 ] = V_238 ;
}
static void F_221 ( T_1 V_14 )
{
V_36 [ V_14 ] . V_31 [ 0 ] = V_191 | V_241 ;
V_36 [ V_14 ] . V_31 [ 1 ] &= V_253 ;
F_222 ( V_14 ) ;
}
static void F_223 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
struct V_52 * V_39 ;
T_1 V_30 ;
bool V_168 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
V_30 = V_24 -> V_30 ;
V_168 = V_24 -> V_168 . V_169 ;
V_24 -> V_19 = V_19 ;
F_161 ( & V_24 -> V_204 , & V_19 -> V_254 ) ;
V_19 -> V_171 [ V_39 -> V_255 ] += 1 ;
V_19 -> V_256 += 1 ;
F_217 ( V_24 -> V_14 , V_19 , V_168 ) ;
if ( V_30 != V_24 -> V_14 )
F_217 ( V_30 , V_19 , V_168 ) ;
F_120 ( V_24 ) ;
}
static void F_224 ( struct V_23 * V_24 )
{
struct V_52 * V_39 ;
T_1 V_30 ;
if ( ! V_24 -> V_19 )
return;
V_39 = V_35 [ V_24 -> V_14 ] ;
V_30 = V_24 -> V_30 ;
V_24 -> V_19 -> V_171 [ V_39 -> V_255 ] -= 1 ;
V_24 -> V_19 -> V_256 -= 1 ;
V_24 -> V_19 = NULL ;
F_163 ( & V_24 -> V_204 ) ;
F_221 ( V_24 -> V_14 ) ;
if ( V_30 != V_24 -> V_14 )
F_221 ( V_30 ) ;
F_120 ( V_24 ) ;
}
static int F_225 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
int V_162 ;
F_93 ( ! F_226 () ) ;
F_227 ( & V_19 -> V_163 ) ;
V_162 = - V_190 ;
if ( V_24 -> V_19 != NULL )
goto V_29;
F_223 ( V_24 , V_19 ) ;
V_162 = 0 ;
V_29:
F_228 ( & V_19 -> V_163 ) ;
return V_162 ;
}
static void F_229 ( struct V_8 * V_9 )
{
F_230 ( V_9 ) ;
F_231 ( V_9 ) ;
F_232 ( V_9 ) ;
}
static int F_233 ( struct V_8 * V_9 )
{
T_1 V_257 ;
int V_47 ;
V_47 = F_39 ( V_9 , V_44 ) ;
if ( ! V_47 )
return - V_15 ;
F_234 ( V_9 , V_47 + V_258 , & V_257 ) ;
V_257 |= V_259 ;
F_235 ( V_9 , V_47 + V_258 , V_257 ) ;
return 0 ;
}
static int F_236 ( struct V_8 * V_9 )
{
bool V_260 ;
int V_261 , V_162 ;
V_261 = 32 ;
if ( F_40 ( V_9 , V_262 ) )
V_261 = 1 ;
V_260 = F_40 ( V_9 , V_263 ) ;
V_162 = F_237 ( V_9 , 0 ) ;
if ( V_162 )
goto V_264;
V_162 = F_238 ( V_9 ) ;
if ( V_162 )
goto V_264;
V_162 = F_239 ( V_9 , V_261 ) ;
if ( V_162 )
goto V_264;
if ( V_260 ) {
V_162 = F_233 ( V_9 ) ;
if ( V_162 )
goto V_264;
}
V_162 = F_240 ( V_9 , V_202 ) ;
if ( V_162 )
goto V_264;
return 0 ;
V_264:
F_231 ( V_9 ) ;
F_232 ( V_9 ) ;
return V_162 ;
}
static bool F_241 ( struct V_8 * V_9 )
{
T_1 V_118 ;
int V_47 ;
V_47 = F_39 ( V_9 , V_44 ) ;
if ( ! V_47 )
return false ;
F_234 ( V_9 , V_47 + V_265 , & V_118 ) ;
return ( V_118 & V_266 ) ? true : false ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_16 * V_19 )
{
struct V_8 * V_9 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
int V_162 ;
V_24 = F_33 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
goto V_267;
V_9 = F_6 ( V_2 ) ;
if ( V_19 -> V_21 & V_243 ) {
if ( ! V_24 -> V_268 )
return - V_15 ;
if ( V_24 -> V_54 ) {
if ( F_236 ( V_9 ) != 0 )
return - V_15 ;
V_24 -> V_168 . V_169 = true ;
V_24 -> V_168 . V_146 = F_243 ( V_9 ) ;
V_24 -> V_269 = F_241 ( V_9 ) ;
}
} else if ( V_270 &&
F_240 ( V_9 , V_202 ) == 0 ) {
V_24 -> V_168 . V_169 = true ;
V_24 -> V_168 . V_146 = F_243 ( V_9 ) ;
}
V_267:
F_165 ( & V_206 , V_21 ) ;
V_162 = F_225 ( V_24 , V_19 ) ;
F_168 ( & V_206 , V_21 ) ;
F_125 ( V_19 ) ;
return V_162 ;
}
static void F_244 ( struct V_23 * V_24 )
{
struct V_16 * V_19 ;
F_93 ( ! F_226 () ) ;
if ( F_93 ( ! V_24 -> V_19 ) )
return;
V_19 = V_24 -> V_19 ;
F_227 ( & V_19 -> V_163 ) ;
F_224 ( V_24 ) ;
F_228 ( & V_19 -> V_163 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
V_24 = F_33 ( V_2 ) ;
V_19 = V_24 -> V_19 ;
F_165 ( & V_206 , V_21 ) ;
F_244 ( V_24 ) ;
F_168 ( & V_206 , V_21 ) ;
if ( ! F_11 ( V_2 ) )
return;
if ( V_19 -> V_21 & V_243 && V_24 -> V_54 )
F_229 ( F_6 ( V_2 ) ) ;
else if ( V_24 -> V_168 . V_169 )
F_230 ( F_6 ( V_2 ) ) ;
V_24 -> V_168 . V_169 = false ;
}
static int F_245 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_17 * V_19 ;
struct V_52 * V_39 ;
int V_162 , V_14 ;
if ( ! F_41 ( V_2 ) || F_33 ( V_2 ) )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_39 = V_35 [ V_14 ] ;
V_162 = F_46 ( V_2 ) ;
if ( V_162 ) {
if ( V_162 != - V_271 )
F_54 ( L_31 ,
F_30 ( V_2 ) ) ;
F_48 ( V_2 ) ;
V_2 -> V_57 = & V_272 ;
goto V_273;
}
F_42 ( V_2 ) ;
V_24 = F_33 ( V_2 ) ;
F_15 ( ! V_24 ) ;
if ( V_274 || V_24 -> V_54 )
F_246 ( V_2 ) ;
V_19 = F_247 ( V_2 ) ;
if ( V_19 -> type == V_275 )
V_24 -> V_268 = true ;
else
V_2 -> V_57 = & V_276 ;
V_273:
F_110 ( V_39 ) ;
return 0 ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_52 * V_39 ;
int V_14 ;
if ( ! F_41 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_39 = V_35 [ V_14 ] ;
F_49 ( V_2 ) ;
F_110 ( V_39 ) ;
}
static struct V_40 * F_249 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) )
return F_250 ( V_2 ) ;
return F_34 ( V_2 ) ;
}
static struct V_16 * F_251 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
if ( ! F_41 ( V_2 ) )
return F_35 ( - V_15 ) ;
V_19 = F_33 ( V_2 ) -> V_19 ;
if ( ! V_20 ( V_19 ) )
return F_35 ( - V_190 ) ;
return V_19 ;
}
static void F_252 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list) {
F_217 ( V_24 -> V_14 , V_19 , V_24 -> V_168 . V_169 ) ;
if ( V_24 -> V_14 == V_24 -> V_30 )
continue;
F_217 ( V_24 -> V_30 , V_19 , V_24 -> V_168 . V_169 ) ;
}
}
static void F_151 ( struct V_16 * V_19 )
{
if ( ! V_19 -> V_178 )
return;
F_252 ( V_19 ) ;
F_127 ( V_19 ) ;
F_125 ( V_19 ) ;
V_19 -> V_178 = false ;
}
static int F_253 ( enum V_277 V_278 )
{
if ( V_278 == V_279 )
return V_193 ;
else if ( V_278 == V_280 )
return V_195 ;
else if ( V_278 == V_281 )
return V_195 | V_193 ;
else
return 0 ;
}
static T_8 F_254 ( struct V_1 * V_2 ,
struct V_20 * V_199 ,
T_9 V_282 ,
T_6 V_136 ,
enum V_277 V_278 ,
T_3 V_50 )
{
T_8 V_283 = V_282 & ~ V_142 ;
T_8 V_62 , V_284 , V_162 ;
unsigned int V_138 ;
int V_188 = 0 ;
int V_46 ;
V_138 = F_100 ( V_282 , V_136 , V_140 ) ;
V_282 &= V_142 ;
V_62 = F_153 ( V_2 , V_199 , V_138 , V_50 ) ;
if ( V_62 == V_285 )
goto V_273;
V_188 = F_253 ( V_278 ) ;
V_284 = V_62 ;
for ( V_46 = 0 ; V_46 < V_138 ; ++ V_46 ) {
V_162 = F_147 ( & V_199 -> V_19 , V_284 , V_282 ,
V_140 , V_188 , V_286 ) ;
if ( V_162 )
goto V_287;
V_282 += V_140 ;
V_284 += V_140 ;
}
V_62 += V_283 ;
if ( F_255 ( V_288 ) ) {
F_123 ( & V_199 -> V_19 , V_62 , V_136 ) ;
F_126 ( & V_199 -> V_19 ) ;
}
V_273:
return V_62 ;
V_287:
for ( -- V_46 ; V_46 >= 0 ; -- V_46 ) {
V_284 -= V_140 ;
F_152 ( & V_199 -> V_19 , V_284 , V_140 ) ;
}
F_124 ( & V_199 -> V_19 ) ;
F_126 ( & V_199 -> V_19 ) ;
F_158 ( V_199 , V_62 , V_138 ) ;
return V_285 ;
}
static void F_256 ( struct V_20 * V_199 ,
T_8 V_289 ,
T_6 V_136 ,
int V_290 )
{
T_8 V_291 ;
T_8 V_46 , V_284 ;
unsigned int V_138 ;
V_291 = V_289 ;
V_138 = F_100 ( V_289 , V_136 , V_140 ) ;
V_289 &= V_142 ;
V_284 = V_289 ;
for ( V_46 = 0 ; V_46 < V_138 ; ++ V_46 ) {
F_152 ( & V_199 -> V_19 , V_284 , V_140 ) ;
V_284 += V_140 ;
}
if ( V_292 ) {
F_158 ( V_199 , V_289 , V_138 ) ;
F_124 ( & V_199 -> V_19 ) ;
F_126 ( & V_199 -> V_19 ) ;
} else {
F_200 ( V_199 , V_289 , V_138 ) ;
}
}
static T_8 F_257 ( struct V_1 * V_2 , struct V_183 * V_183 ,
unsigned long V_283 , T_6 V_136 ,
enum V_277 V_290 ,
unsigned long V_293 )
{
T_9 V_282 = F_258 ( V_183 ) + V_283 ;
struct V_16 * V_19 ;
struct V_20 * V_199 ;
T_3 V_50 ;
V_19 = F_251 ( V_2 ) ;
if ( F_259 ( V_19 ) == - V_15 )
return ( T_8 ) V_282 ;
else if ( F_44 ( V_19 ) )
return V_285 ;
V_50 = * V_2 -> V_50 ;
V_199 = F_14 ( V_19 ) ;
return F_254 ( V_2 , V_199 , V_282 , V_136 , V_290 , V_50 ) ;
}
static void F_260 ( struct V_1 * V_2 , T_8 V_289 , T_6 V_136 ,
enum V_277 V_290 , unsigned long V_293 )
{
struct V_16 * V_19 ;
struct V_20 * V_199 ;
V_19 = F_251 ( V_2 ) ;
if ( F_44 ( V_19 ) )
return;
V_199 = F_14 ( V_19 ) ;
F_256 ( V_199 , V_289 , V_136 , V_290 ) ;
}
static int F_261 ( struct V_1 * V_2 ,
struct V_294 * V_295 ,
int V_296 )
{
unsigned long V_297 , V_298 ;
struct V_294 * V_139 ;
int V_46 , V_299 = 0 ;
V_297 = F_262 ( V_2 ) ;
V_298 = V_297 + 1 ? F_263 ( V_297 + 1 , V_140 ) >> V_202 :
1UL << ( V_300 - V_202 ) ;
F_264 (sglist, s, nelems, i) {
int V_13 , V_301 ;
V_139 -> V_302 = V_299 << V_202 ;
V_13 = V_299 % V_298 ;
V_301 = F_100 ( F_265 ( V_139 ) , V_139 -> V_303 , V_140 ) ;
if ( V_13 + V_301 > V_298 )
V_299 += V_298 - V_13 ;
V_299 += V_301 ;
}
return V_299 ;
}
static int F_266 ( struct V_1 * V_2 , struct V_294 * V_295 ,
int V_296 , enum V_277 V_278 ,
unsigned long V_293 )
{
int V_304 = 0 , V_299 = 0 , V_188 = 0 , V_46 ;
struct V_16 * V_19 ;
struct V_20 * V_199 ;
struct V_294 * V_139 ;
unsigned long V_62 ;
T_3 V_50 ;
V_19 = F_251 ( V_2 ) ;
if ( F_44 ( V_19 ) )
return 0 ;
V_199 = F_14 ( V_19 ) ;
V_50 = * V_2 -> V_50 ;
V_299 = F_261 ( V_2 , V_295 , V_296 ) ;
V_62 = F_153 ( V_2 , V_199 , V_299 , V_50 ) ;
if ( V_62 == V_285 )
goto V_264;
V_188 = F_253 ( V_278 ) ;
F_264 (sglist, s, nelems, i) {
int V_305 , V_138 = F_100 ( F_265 ( V_139 ) , V_139 -> V_303 , V_140 ) ;
for ( V_305 = 0 ; V_305 < V_138 ; ++ V_305 ) {
unsigned long V_187 , V_58 ;
int V_162 ;
V_187 = V_62 + V_139 -> V_302 + ( V_305 << V_202 ) ;
V_58 = ( F_265 ( V_139 ) & V_142 ) + ( V_305 << V_202 ) ;
V_162 = F_147 ( V_19 , V_187 , V_58 , V_140 , V_188 , V_286 ) ;
if ( V_162 )
goto V_287;
V_304 += 1 ;
}
}
F_264 (sglist, s, nelems, i) {
V_139 -> V_302 += V_62 + V_139 -> V_283 ;
V_139 -> V_306 = V_139 -> V_303 ;
}
return V_296 ;
V_287:
F_54 ( L_32 ,
F_30 ( V_2 ) , V_299 ) ;
F_264 (sglist, s, nelems, i) {
int V_305 , V_138 = F_100 ( F_265 ( V_139 ) , V_139 -> V_303 , V_140 ) ;
for ( V_305 = 0 ; V_305 < V_138 ; ++ V_305 ) {
unsigned long V_187 ;
V_187 = V_62 + V_139 -> V_302 + ( V_305 << V_202 ) ;
F_152 ( V_19 , V_187 , V_140 ) ;
if ( -- V_304 )
goto V_307;
}
}
V_307:
F_159 ( & V_199 -> V_201 , V_62 , V_299 ) ;
V_264:
return 0 ;
}
static void F_267 ( struct V_1 * V_2 , struct V_294 * V_295 ,
int V_296 , enum V_277 V_290 ,
unsigned long V_293 )
{
struct V_16 * V_19 ;
struct V_20 * V_199 ;
unsigned long V_308 ;
int V_299 = 2 ;
V_19 = F_251 ( V_2 ) ;
if ( F_44 ( V_19 ) )
return;
V_308 = F_268 ( V_295 ) & V_142 ;
V_199 = F_14 ( V_19 ) ;
V_299 = F_261 ( V_2 , V_295 , V_296 ) ;
F_256 ( V_199 , V_308 , V_299 << V_202 , V_290 ) ;
}
static void * F_269 ( struct V_1 * V_2 , T_6 V_136 ,
T_8 * V_289 , T_7 V_309 ,
unsigned long V_293 )
{
T_3 V_50 = V_2 -> V_310 ;
struct V_16 * V_19 ;
struct V_20 * V_199 ;
struct V_183 * V_183 ;
V_19 = F_251 ( V_2 ) ;
if ( F_259 ( V_19 ) == - V_15 ) {
V_183 = F_270 ( V_309 , F_271 ( V_136 ) ) ;
* V_289 = F_258 ( V_183 ) ;
return F_272 ( V_183 ) ;
} else if ( F_44 ( V_19 ) )
return NULL ;
V_199 = F_14 ( V_19 ) ;
V_136 = F_273 ( V_136 ) ;
V_50 = V_2 -> V_310 ;
V_309 &= ~ ( V_311 | V_312 | V_313 ) ;
V_309 |= V_314 ;
V_183 = F_270 ( V_309 | V_315 , F_271 ( V_136 ) ) ;
if ( ! V_183 ) {
if ( ! F_274 ( V_309 ) )
return NULL ;
V_183 = F_275 ( V_2 , V_136 >> V_202 ,
F_271 ( V_136 ) , V_309 ) ;
if ( ! V_183 )
return NULL ;
}
if ( ! V_50 )
V_50 = * V_2 -> V_50 ;
* V_289 = F_254 ( V_2 , V_199 , F_258 ( V_183 ) ,
V_136 , V_281 , V_50 ) ;
if ( * V_289 == V_285 )
goto V_316;
return F_272 ( V_183 ) ;
V_316:
if ( ! F_276 ( V_2 , V_183 , V_136 >> V_202 ) )
F_277 ( V_183 , F_271 ( V_136 ) ) ;
return NULL ;
}
static void F_278 ( struct V_1 * V_2 , T_6 V_136 ,
void * V_317 , T_8 V_289 ,
unsigned long V_293 )
{
struct V_16 * V_19 ;
struct V_20 * V_199 ;
struct V_183 * V_183 ;
V_183 = F_279 ( V_317 ) ;
V_136 = F_273 ( V_136 ) ;
V_19 = F_251 ( V_2 ) ;
if ( F_44 ( V_19 ) )
goto V_318;
V_199 = F_14 ( V_19 ) ;
F_256 ( V_199 , V_289 , V_136 , V_281 ) ;
V_318:
if ( ! F_276 ( V_2 , V_183 , V_136 >> V_202 ) )
F_277 ( V_183 , F_271 ( V_136 ) ) ;
}
static int F_280 ( struct V_1 * V_2 , T_3 V_297 )
{
if ( ! F_281 ( V_2 , V_297 ) )
return 0 ;
return F_41 ( V_2 ) ;
}
static int F_282 ( struct V_1 * V_2 , T_8 V_289 )
{
return V_289 == V_285 ;
}
static int F_283 ( void )
{
struct V_8 * V_9 = NULL ;
struct V_319 * V_320 ;
F_214 ( & V_237 , V_140 ,
V_235 , V_236 ) ;
F_284 ( & V_237 . V_321 ,
& V_322 ) ;
V_320 = F_285 ( & V_237 ,
F_157 ( V_323 ) , F_157 ( V_324 ) ) ;
if ( ! V_320 ) {
F_54 ( L_33 ) ;
return - V_53 ;
}
V_320 = F_285 ( & V_237 ,
F_157 ( V_325 ) , F_157 ( V_326 ) ) ;
if ( ! V_320 ) {
F_54 ( L_34 ) ;
return - V_53 ;
}
F_286 (pdev) {
int V_46 ;
for ( V_46 = 0 ; V_46 < V_327 ; ++ V_46 ) {
struct V_328 * V_329 = & V_9 -> V_328 [ V_46 ] ;
if ( ! ( V_329 -> V_21 & V_330 ) )
continue;
V_320 = F_285 ( & V_237 ,
F_157 ( V_329 -> V_284 ) ,
F_157 ( V_329 -> V_331 ) ) ;
if ( ! V_320 ) {
F_54 ( L_35 ) ;
return - V_53 ;
}
}
}
return 0 ;
}
int T_10 F_287 ( void )
{
int V_162 , V_332 = 0 ;
V_162 = F_288 () ;
if ( V_162 )
return V_162 ;
V_162 = F_283 () ;
if ( V_162 )
return V_162 ;
V_332 = F_289 ( & V_333 , & V_334 ) ;
if ( V_332 )
return V_332 ;
#ifdef F_290
V_332 = F_289 ( & V_335 , & V_334 ) ;
if ( V_332 )
return V_332 ;
#endif
V_332 = F_289 ( & V_336 , & V_334 ) ;
if ( V_332 )
return V_332 ;
return 0 ;
}
int T_10 F_291 ( void )
{
V_337 = V_274 ? 1 : 0 ;
V_338 = 1 ;
if ( ! V_337 )
V_57 = & V_272 ;
if ( V_292 )
F_26 ( L_36 ) ;
else
F_26 ( L_37 ) ;
return 0 ;
}
static void F_292 ( struct V_16 * V_19 )
{
struct V_23 * V_4 ;
unsigned long V_21 ;
F_165 ( & V_206 , V_21 ) ;
while ( ! F_293 ( & V_19 -> V_254 ) ) {
V_4 = F_294 ( & V_19 -> V_254 ,
struct V_23 , V_204 ) ;
F_244 ( V_4 ) ;
}
F_168 ( & V_206 , V_21 ) ;
}
static void F_295 ( struct V_16 * V_19 )
{
if ( ! V_19 )
return;
F_162 ( V_19 ) ;
if ( V_19 -> V_170 )
F_169 ( V_19 -> V_170 ) ;
F_185 ( V_19 ) ;
}
static int F_213 ( struct V_16 * V_19 )
{
F_190 ( & V_19 -> V_163 ) ;
F_296 ( & V_19 -> V_339 ) ;
V_19 -> V_170 = F_164 () ;
if ( ! V_19 -> V_170 )
return - V_53 ;
F_297 ( & V_19 -> V_254 ) ;
return 0 ;
}
static struct V_16 * F_298 ( void )
{
struct V_16 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_25 ) ;
if ( ! V_19 )
return NULL ;
if ( F_213 ( V_19 ) )
goto V_264;
F_160 ( V_19 ) ;
return V_19 ;
V_264:
F_185 ( V_19 ) ;
return NULL ;
}
static struct V_17 * F_299 ( unsigned type )
{
struct V_16 * V_340 ;
struct V_20 * V_341 ;
switch ( type ) {
case V_342 :
V_340 = F_298 () ;
if ( ! V_340 )
return NULL ;
V_340 -> V_175 = V_213 ;
V_340 -> V_177 = ( void * ) F_129 ( V_25 ) ;
if ( ! V_340 -> V_177 ) {
F_295 ( V_340 ) ;
return NULL ;
}
V_340 -> V_19 . V_343 . V_344 = 0 ;
V_340 -> V_19 . V_343 . V_345 = ~ 0ULL ;
V_340 -> V_19 . V_343 . V_346 = true ;
break;
case V_347 :
V_341 = F_212 () ;
if ( ! V_341 ) {
F_54 ( L_38 ) ;
return NULL ;
}
V_340 = & V_341 -> V_19 ;
break;
case V_275 :
V_340 = F_298 () ;
if ( ! V_340 )
return NULL ;
V_340 -> V_175 = V_210 ;
break;
default:
return NULL ;
}
return & V_340 -> V_19 ;
}
static void F_300 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
struct V_20 * V_199 ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 -> V_256 > 0 )
F_292 ( V_19 ) ;
F_15 ( V_19 -> V_256 != 0 ) ;
if ( ! V_18 )
return;
switch ( V_18 -> type ) {
case V_347 :
V_199 = F_14 ( V_19 ) ;
F_208 ( V_199 ) ;
break;
default:
if ( V_19 -> V_175 != V_210 )
F_171 ( V_19 ) ;
if ( V_19 -> V_21 & V_243 )
F_181 ( V_19 ) ;
F_295 ( V_19 ) ;
break;
}
}
static void F_301 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_38 . V_39 ;
struct V_52 * V_39 ;
int V_14 ;
if ( ! F_41 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
if ( V_24 -> V_19 != NULL )
F_50 ( V_2 ) ;
V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
return;
#ifdef F_87
if ( F_302 ( V_348 ) &&
( V_18 -> type == V_342 ) )
V_24 -> V_349 = 0 ;
#endif
F_110 ( V_39 ) ;
}
static int F_303 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
struct V_23 * V_24 ;
struct V_52 * V_39 ;
int V_162 ;
if ( ! F_41 ( V_2 ) )
return - V_15 ;
V_24 = V_2 -> V_38 . V_39 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
if ( ! V_39 )
return - V_15 ;
if ( V_24 -> V_19 )
F_50 ( V_2 ) ;
V_162 = F_242 ( V_2 , V_19 ) ;
#ifdef F_87
if ( F_302 ( V_348 ) ) {
if ( V_18 -> type == V_342 )
V_24 -> V_349 = 1 ;
else
V_24 -> V_349 = 0 ;
}
#endif
F_110 ( V_39 ) ;
return V_162 ;
}
static int F_304 ( struct V_17 * V_18 , unsigned long V_319 ,
T_9 V_282 , T_6 V_179 , int V_350 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
int V_188 = 0 ;
int V_162 ;
if ( V_19 -> V_175 == V_210 )
return - V_15 ;
if ( V_350 & V_351 )
V_188 |= V_193 ;
if ( V_350 & V_352 )
V_188 |= V_195 ;
F_305 ( & V_19 -> V_339 ) ;
V_162 = F_147 ( V_19 , V_319 , V_282 , V_179 , V_188 , V_25 ) ;
F_306 ( & V_19 -> V_339 ) ;
return V_162 ;
}
static T_6 F_307 ( struct V_17 * V_18 , unsigned long V_319 ,
T_6 V_179 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
T_6 V_198 ;
if ( V_19 -> V_175 == V_210 )
return - V_15 ;
F_305 ( & V_19 -> V_339 ) ;
V_198 = F_152 ( V_19 , V_319 , V_179 ) ;
F_306 ( & V_19 -> V_339 ) ;
F_125 ( V_19 ) ;
return V_198 ;
}
static T_9 F_308 ( struct V_17 * V_18 ,
T_8 V_319 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_353 , V_354 ;
T_3 * V_174 , V_184 ;
if ( V_19 -> V_175 == V_210 )
return V_319 ;
V_174 = F_143 ( V_19 , V_319 , & V_354 ) ;
if ( ! V_174 || ! F_138 ( * V_174 ) )
return 0 ;
V_353 = V_354 - 1 ;
V_184 = * V_174 & V_355 ;
return ( V_184 & ~ V_353 ) | ( V_319 & V_353 ) ;
}
static bool F_309 ( enum V_356 V_357 )
{
switch ( V_357 ) {
case V_358 :
return true ;
case V_359 :
return ( V_360 == 1 ) ;
case V_361 :
return false ;
}
return false ;
}
static void F_310 ( struct V_1 * V_2 ,
struct V_362 * V_86 )
{
struct V_363 * V_364 ;
struct V_365 * V_4 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
F_9 (entry, &amd_iommu_unity_map, list) {
T_6 V_303 ;
int V_188 = 0 ;
if ( V_14 < V_4 -> V_366 || V_14 > V_4 -> V_367 )
continue;
V_303 = V_4 -> V_368 - V_4 -> V_369 ;
if ( V_4 -> V_188 & V_193 )
V_188 |= V_351 ;
if ( V_4 -> V_188 & V_195 )
V_188 |= V_352 ;
V_364 = F_311 ( V_4 -> V_369 ,
V_303 , V_188 ,
V_370 ) ;
if ( ! V_364 ) {
F_54 ( L_39 ,
F_30 ( V_2 ) ) ;
return;
}
F_19 ( & V_364 -> V_204 , V_86 ) ;
}
V_364 = F_311 ( V_323 ,
V_324 - V_323 + 1 ,
0 , V_371 ) ;
if ( ! V_364 )
return;
F_19 ( & V_364 -> V_204 , V_86 ) ;
V_364 = F_311 ( V_325 ,
V_326 - V_325 + 1 ,
0 , V_372 ) ;
if ( ! V_364 )
return;
F_19 ( & V_364 -> V_204 , V_86 ) ;
}
static void F_312 ( struct V_1 * V_2 ,
struct V_362 * V_86 )
{
struct V_363 * V_4 , * V_373 ;
F_313 (entry, next, head, list)
F_185 ( V_4 ) ;
}
static void F_314 ( struct V_1 * V_2 ,
struct V_17 * V_19 ,
struct V_363 * V_364 )
{
struct V_20 * V_199 = F_14 ( F_12 ( V_19 ) ) ;
unsigned long V_284 , V_331 ;
V_284 = F_157 ( V_364 -> V_284 ) ;
V_331 = F_157 ( V_364 -> V_284 + V_364 -> V_303 ) ;
F_315 ( F_285 ( & V_199 -> V_201 , V_284 , V_331 ) == NULL ) ;
}
int F_316 ( struct V_374 * V_375 )
{
return F_317 ( & V_101 , V_375 ) ;
}
int F_318 ( struct V_374 * V_375 )
{
return F_319 ( & V_101 , V_375 ) ;
}
void F_320 ( struct V_17 * V_18 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
F_18 ( & V_19 -> V_163 , V_21 ) ;
V_19 -> V_175 = V_210 ;
V_19 -> V_178 = true ;
F_151 ( V_19 ) ;
F_171 ( V_19 ) ;
F_20 ( & V_19 -> V_163 , V_21 ) ;
}
int F_321 ( struct V_17 * V_18 , int V_376 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_377 , V_162 ;
if ( V_376 <= 0 || V_376 > ( V_378 + 1 ) )
return - V_15 ;
for ( V_377 = 0 ; ( V_376 - 1 ) & ~ 0x1ff ; V_376 >>= 9 )
V_377 += 1 ;
if ( V_377 > V_379 )
return - V_15 ;
F_18 ( & V_19 -> V_163 , V_21 ) ;
V_162 = - V_190 ;
if ( V_19 -> V_256 > 0 || V_19 -> V_21 & V_243 )
goto V_273;
V_162 = - V_53 ;
V_19 -> V_220 = ( void * ) F_129 ( V_286 ) ;
if ( V_19 -> V_220 == NULL )
goto V_273;
V_19 -> V_219 = V_377 ;
V_19 -> V_21 |= V_243 ;
V_19 -> V_178 = true ;
F_151 ( V_19 ) ;
V_162 = 0 ;
V_273:
F_20 ( & V_19 -> V_163 , V_21 ) ;
return V_162 ;
}
static int F_322 ( struct V_16 * V_19 , int V_98 ,
T_3 V_62 , bool V_136 )
{
struct V_23 * V_24 ;
struct V_59 V_60 ;
int V_46 , V_162 ;
if ( ! ( V_19 -> V_21 & V_243 ) )
return - V_15 ;
F_102 ( & V_60 , V_19 -> V_170 , V_98 , V_62 , V_136 ) ;
for ( V_46 = 0 ; V_46 < F_122 () ; ++ V_46 ) {
if ( V_19 -> V_171 [ V_46 ] == 0 )
continue;
V_162 = F_109 ( V_172 [ V_46 ] , & V_60 ) ;
if ( V_162 != 0 )
goto V_273;
}
F_126 ( V_19 ) ;
F_9 (dev_data, &domain->dev_list, list) {
struct V_52 * V_39 ;
int V_146 ;
if ( ! V_24 -> V_168 . V_169 )
continue;
V_146 = V_24 -> V_168 . V_146 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
F_103 ( & V_60 , V_24 -> V_14 , V_98 ,
V_146 , V_62 , V_136 ) ;
V_162 = F_109 ( V_39 , & V_60 ) ;
if ( V_162 != 0 )
goto V_273;
}
F_126 ( V_19 ) ;
V_162 = 0 ;
V_273:
return V_162 ;
}
static int F_323 ( struct V_16 * V_19 , int V_98 ,
T_3 V_62 )
{
return F_322 ( V_19 , V_98 , V_62 , false ) ;
}
int F_324 ( struct V_17 * V_18 , int V_98 ,
T_3 V_62 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_162 ;
F_18 ( & V_19 -> V_163 , V_21 ) ;
V_162 = F_323 ( V_19 , V_98 , V_62 ) ;
F_20 ( & V_19 -> V_163 , V_21 ) ;
return V_162 ;
}
static int F_325 ( struct V_16 * V_19 , int V_98 )
{
return F_322 ( V_19 , V_98 , V_141 ,
true ) ;
}
int F_326 ( struct V_17 * V_18 , int V_98 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_162 ;
F_18 ( & V_19 -> V_163 , V_21 ) ;
V_162 = F_325 ( V_19 , V_98 ) ;
F_20 ( & V_19 -> V_163 , V_21 ) ;
return V_162 ;
}
static T_3 * F_327 ( T_3 * V_209 , int V_181 , int V_98 , bool V_380 )
{
int V_255 ;
T_3 * V_174 ;
while ( true ) {
V_255 = ( V_98 >> ( 9 * V_181 ) ) & 0x1ff ;
V_174 = & V_209 [ V_255 ] ;
if ( V_181 == 0 )
break;
if ( ! ( * V_174 & V_218 ) ) {
if ( ! V_380 )
return NULL ;
V_209 = ( void * ) F_129 ( V_286 ) ;
if ( V_209 == NULL )
return NULL ;
* V_174 = F_95 ( V_209 ) | V_218 ;
}
V_209 = F_179 ( * V_174 & V_142 ) ;
V_181 -= 1 ;
}
return V_174 ;
}
static int F_328 ( struct V_16 * V_19 , int V_98 ,
unsigned long V_381 )
{
T_3 * V_174 ;
if ( V_19 -> V_175 != V_210 )
return - V_15 ;
V_174 = F_327 ( V_19 -> V_220 , V_19 -> V_219 , V_98 , true ) ;
if ( V_174 == NULL )
return - V_53 ;
* V_174 = ( V_381 & V_142 ) | V_218 ;
return F_325 ( V_19 , V_98 ) ;
}
static int F_329 ( struct V_16 * V_19 , int V_98 )
{
T_3 * V_174 ;
if ( V_19 -> V_175 != V_210 )
return - V_15 ;
V_174 = F_327 ( V_19 -> V_220 , V_19 -> V_219 , V_98 , false ) ;
if ( V_174 == NULL )
return 0 ;
* V_174 = 0 ;
return F_325 ( V_19 , V_98 ) ;
}
int F_330 ( struct V_17 * V_18 , int V_98 ,
unsigned long V_381 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_162 ;
F_18 ( & V_19 -> V_163 , V_21 ) ;
V_162 = F_328 ( V_19 , V_98 , V_381 ) ;
F_20 ( & V_19 -> V_163 , V_21 ) ;
return V_162 ;
}
int F_331 ( struct V_17 * V_18 , int V_98 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_162 ;
F_18 ( & V_19 -> V_163 , V_21 ) ;
V_162 = F_329 ( V_19 , V_98 ) ;
F_20 ( & V_19 -> V_163 , V_21 ) ;
return V_162 ;
}
int F_332 ( struct V_8 * V_9 , int V_98 ,
int V_118 , int V_100 )
{
struct V_23 * V_24 ;
struct V_52 * V_39 ;
struct V_59 V_60 ;
V_24 = F_33 ( & V_9 -> V_2 ) ;
V_39 = V_35 [ V_24 -> V_14 ] ;
F_104 ( & V_60 , V_24 -> V_14 , V_98 , V_118 ,
V_100 , V_24 -> V_269 ) ;
return F_109 ( V_39 , & V_60 ) ;
}
struct V_17 * F_333 ( struct V_8 * V_9 )
{
struct V_16 * V_340 ;
V_340 = F_251 ( & V_9 -> V_2 ) ;
if ( F_44 ( V_340 ) )
return NULL ;
if ( ! ( V_340 -> V_21 & V_243 ) )
return NULL ;
return & V_340 -> V_19 ;
}
void F_334 ( struct V_8 * V_9 , T_2 V_48 )
{
struct V_23 * V_24 ;
if ( ! F_335 () )
return;
V_24 = F_33 ( & V_9 -> V_2 ) ;
V_24 -> V_49 |= ( 1 << V_48 ) ;
}
int F_336 ( struct V_8 * V_9 ,
struct F_336 * V_382 )
{
int V_383 ;
int V_47 ;
if ( V_9 == NULL || V_382 == NULL )
return - V_15 ;
if ( ! F_335 () )
return - V_15 ;
memset ( V_382 , 0 , sizeof( * V_382 ) ) ;
V_47 = F_39 ( V_9 , V_43 ) ;
if ( V_47 )
V_382 -> V_21 |= V_384 ;
V_47 = F_39 ( V_9 , V_44 ) ;
if ( V_47 )
V_382 -> V_21 |= V_385 ;
V_47 = F_39 ( V_9 , V_45 ) ;
if ( V_47 ) {
int V_386 ;
V_383 = 1 << ( 9 * ( V_379 + 1 ) ) ;
V_383 = F_337 ( V_383 , ( 1 << 20 ) ) ;
V_382 -> V_21 |= V_387 ;
V_382 -> V_383 = F_337 ( F_338 ( V_9 ) , V_383 ) ;
V_386 = F_339 ( V_9 ) ;
if ( V_386 & V_388 )
V_382 -> V_21 |= V_389 ;
if ( V_386 & V_390 )
V_382 -> V_21 |= V_391 ;
}
return 0 ;
}
static void F_340 ( T_1 V_14 , struct V_392 * V_393 )
{
T_3 V_394 ;
V_394 = V_36 [ V_14 ] . V_31 [ 2 ] ;
V_394 &= ~ V_395 ;
V_394 |= F_131 ( V_393 -> V_393 ) ;
V_394 |= V_396 ;
V_394 |= V_397 ;
V_394 |= V_398 ;
V_36 [ V_14 ] . V_31 [ 2 ] = V_394 ;
}
static struct V_392 * F_341 ( T_1 V_14 , bool V_399 )
{
struct V_392 * V_393 = NULL ;
struct V_52 * V_39 ;
unsigned long V_21 ;
T_1 V_30 ;
F_165 ( & V_206 , V_21 ) ;
V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
goto V_29;
V_393 = V_400 [ V_14 ] ;
if ( V_393 )
goto V_29;
V_30 = V_34 [ V_14 ] ;
V_393 = V_400 [ V_30 ] ;
if ( V_393 ) {
V_400 [ V_14 ] = V_393 ;
F_340 ( V_14 , V_393 ) ;
F_111 ( V_39 , V_14 ) ;
goto V_273;
}
V_393 = F_17 ( sizeof( * V_393 ) , V_286 ) ;
if ( ! V_393 )
goto V_29;
F_190 ( & V_393 -> V_163 ) ;
if ( V_399 )
V_393 -> V_401 = 32 ;
V_393 -> V_393 = F_342 ( V_402 , V_286 ) ;
if ( ! V_393 -> V_393 ) {
F_185 ( V_393 ) ;
V_393 = NULL ;
goto V_29;
}
if ( ! F_343 ( V_348 ) )
memset ( V_393 -> V_393 , 0 ,
V_403 * sizeof( T_2 ) ) ;
else
memset ( V_393 -> V_393 , 0 ,
( V_403 * ( sizeof( T_3 ) * 2 ) ) ) ;
if ( V_399 ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < 32 ; ++ V_46 )
V_39 -> V_404 -> V_405 ( V_393 , V_46 ) ;
}
V_400 [ V_14 ] = V_393 ;
F_340 ( V_14 , V_393 ) ;
F_111 ( V_39 , V_14 ) ;
if ( V_14 != V_30 ) {
V_400 [ V_30 ] = V_393 ;
F_340 ( V_30 , V_393 ) ;
F_111 ( V_39 , V_30 ) ;
}
V_273:
F_110 ( V_39 ) ;
V_29:
F_168 ( & V_206 , V_21 ) ;
return V_393 ;
}
static int F_344 ( T_1 V_14 , int V_66 )
{
struct V_392 * V_393 ;
unsigned long V_21 ;
int V_255 , V_406 ;
struct V_52 * V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
return - V_7 ;
V_393 = F_341 ( V_14 , false ) ;
if ( ! V_393 )
return - V_7 ;
F_18 ( & V_393 -> V_163 , V_21 ) ;
for ( V_406 = 0 , V_255 = V_393 -> V_401 ;
V_255 < V_403 ;
++ V_255 ) {
if ( ! V_39 -> V_404 -> V_407 ( V_393 , V_255 ) )
V_406 += 1 ;
else
V_406 = 0 ;
if ( V_406 == V_66 ) {
for (; V_406 != 0 ; -- V_406 )
V_39 -> V_404 -> V_405 ( V_393 , V_255 - V_406 + 1 ) ;
V_255 -= V_66 - 1 ;
goto V_273;
}
}
V_255 = - V_408 ;
V_273:
F_20 ( & V_393 -> V_163 , V_21 ) ;
return V_255 ;
}
static int F_345 ( T_1 V_14 , int V_255 , struct V_409 * V_410 ,
struct V_411 * V_31 )
{
struct V_392 * V_393 ;
struct V_52 * V_39 ;
unsigned long V_21 ;
struct V_409 * V_4 ;
V_39 = V_35 [ V_14 ] ;
if ( V_39 == NULL )
return - V_15 ;
V_393 = F_341 ( V_14 , false ) ;
if ( ! V_393 )
return - V_53 ;
F_18 ( & V_393 -> V_163 , V_21 ) ;
V_4 = (struct V_409 * ) V_393 -> V_393 ;
V_4 = & V_4 [ V_255 ] ;
V_4 -> V_412 . V_413 . V_414 = 0 ;
V_4 -> V_415 . V_320 = V_410 -> V_415 . V_320 ;
V_4 -> V_412 . V_320 = V_410 -> V_412 . V_320 ;
V_4 -> V_412 . V_413 . V_414 = 1 ;
if ( V_31 )
V_31 -> V_416 = V_4 ;
F_20 ( & V_393 -> V_163 , V_21 ) ;
F_115 ( V_39 , V_14 ) ;
F_110 ( V_39 ) ;
return 0 ;
}
static int F_346 ( T_1 V_14 , int V_255 , union V_410 * V_410 )
{
struct V_392 * V_393 ;
struct V_52 * V_39 ;
unsigned long V_21 ;
V_39 = V_35 [ V_14 ] ;
if ( V_39 == NULL )
return - V_15 ;
V_393 = F_341 ( V_14 , false ) ;
if ( ! V_393 )
return - V_53 ;
F_18 ( & V_393 -> V_163 , V_21 ) ;
V_393 -> V_393 [ V_255 ] = V_410 -> V_320 ;
F_20 ( & V_393 -> V_163 , V_21 ) ;
F_115 ( V_39 , V_14 ) ;
F_110 ( V_39 ) ;
return 0 ;
}
static void F_347 ( T_1 V_14 , int V_255 )
{
struct V_392 * V_393 ;
struct V_52 * V_39 ;
unsigned long V_21 ;
V_39 = V_35 [ V_14 ] ;
if ( V_39 == NULL )
return;
V_393 = F_341 ( V_14 , false ) ;
if ( ! V_393 )
return;
F_18 ( & V_393 -> V_163 , V_21 ) ;
V_39 -> V_404 -> V_417 ( V_393 , V_255 ) ;
F_20 ( & V_393 -> V_163 , V_21 ) ;
F_115 ( V_39 , V_14 ) ;
F_110 ( V_39 ) ;
}
static void F_348 ( void * V_4 ,
T_2 V_418 , T_2 V_419 ,
T_5 V_420 , T_2 V_421 , int V_14 )
{
union V_410 * V_410 = (union V_410 * ) V_4 ;
V_410 -> V_320 = 0 ;
V_410 -> V_422 . V_420 = V_420 ;
V_410 -> V_422 . V_423 = V_418 ;
V_410 -> V_422 . V_424 = V_421 ;
V_410 -> V_422 . V_425 = V_419 ;
V_410 -> V_422 . V_414 = 1 ;
}
static void F_349 ( void * V_4 ,
T_2 V_418 , T_2 V_419 ,
T_5 V_420 , T_2 V_421 , int V_14 )
{
struct V_409 * V_410 = (struct V_409 * ) V_4 ;
V_410 -> V_412 . V_320 = 0 ;
V_410 -> V_415 . V_320 = 0 ;
V_410 -> V_412 . V_413 . V_423 = V_418 ;
V_410 -> V_412 . V_413 . V_425 = V_419 ;
V_410 -> V_415 . V_422 . V_420 = V_420 ;
V_410 -> V_412 . V_413 . V_424 = V_421 ;
V_410 -> V_412 . V_413 . V_414 = 1 ;
}
static void F_350 ( void * V_4 , T_1 V_14 , T_1 V_255 )
{
union V_410 * V_410 = (union V_410 * ) V_4 ;
V_410 -> V_422 . V_414 = 1 ;
F_346 ( V_14 , V_255 , V_410 ) ;
}
static void F_351 ( void * V_4 , T_1 V_14 , T_1 V_255 )
{
struct V_409 * V_410 = (struct V_409 * ) V_4 ;
V_410 -> V_412 . V_413 . V_414 = 1 ;
F_345 ( V_14 , V_255 , V_410 , NULL ) ;
}
static void F_352 ( void * V_4 , T_1 V_14 , T_1 V_255 )
{
union V_410 * V_410 = (union V_410 * ) V_4 ;
V_410 -> V_422 . V_414 = 0 ;
F_346 ( V_14 , V_255 , V_410 ) ;
}
static void F_353 ( void * V_4 , T_1 V_14 , T_1 V_255 )
{
struct V_409 * V_410 = (struct V_409 * ) V_4 ;
V_410 -> V_412 . V_413 . V_414 = 0 ;
F_345 ( V_14 , V_255 , V_410 , NULL ) ;
}
static void F_354 ( void * V_4 , T_1 V_14 , T_1 V_255 ,
T_5 V_420 , T_2 V_421 )
{
union V_410 * V_410 = (union V_410 * ) V_4 ;
V_410 -> V_422 . V_420 = V_420 ;
V_410 -> V_422 . V_424 = V_421 ;
F_346 ( V_14 , V_255 , V_410 ) ;
}
static void F_355 ( void * V_4 , T_1 V_14 , T_1 V_255 ,
T_5 V_420 , T_2 V_421 )
{
struct V_409 * V_410 = (struct V_409 * ) V_4 ;
struct V_23 * V_24 = F_22 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> V_349 ||
! V_410 -> V_412 . V_413 . V_426 ) {
V_410 -> V_415 . V_422 . V_420 = V_420 ;
V_410 -> V_412 . V_413 . V_424 = V_421 ;
F_345 ( V_14 , V_255 , V_410 , NULL ) ;
}
}
static void F_356 ( struct V_392 * V_393 , int V_255 )
{
V_393 -> V_393 [ V_255 ] = V_427 ;
}
static void F_357 ( struct V_392 * V_393 , int V_255 )
{
struct V_409 * V_217 = (struct V_409 * ) V_393 -> V_393 ;
struct V_409 * V_410 = & V_217 [ V_255 ] ;
memset ( & V_410 -> V_412 . V_320 , 0 , sizeof( T_3 ) ) ;
memset ( & V_410 -> V_415 . V_320 , 0 , sizeof( T_3 ) ) ;
V_410 -> V_415 . V_422 . V_420 = 0xff ;
}
static bool F_358 ( struct V_392 * V_393 , int V_255 )
{
union V_410 * V_217 = (union V_410 * ) V_393 -> V_393 ;
union V_410 * V_410 = & V_217 [ V_255 ] ;
return V_410 -> V_320 != 0 ;
}
static bool F_359 ( struct V_392 * V_393 , int V_255 )
{
struct V_409 * V_217 = (struct V_409 * ) V_393 -> V_393 ;
struct V_409 * V_410 = & V_217 [ V_255 ] ;
return V_410 -> V_415 . V_422 . V_420 != 0 ;
}
static void F_360 ( struct V_392 * V_393 , int V_255 )
{
V_393 -> V_393 [ V_255 ] = 0 ;
}
static void F_361 ( struct V_392 * V_393 , int V_255 )
{
struct V_409 * V_217 = (struct V_409 * ) V_393 -> V_393 ;
struct V_409 * V_410 = & V_217 [ V_255 ] ;
memset ( & V_410 -> V_412 . V_320 , 0 , sizeof( T_3 ) ) ;
memset ( & V_410 -> V_415 . V_320 , 0 , sizeof( T_3 ) ) ;
}
static int F_362 ( struct V_428 * V_382 )
{
int V_14 = - 1 ;
switch ( V_382 -> type ) {
case V_429 :
V_14 = F_363 ( V_382 -> V_430 ) ;
break;
case V_431 :
V_14 = F_364 ( V_382 -> V_432 ) ;
break;
case V_433 :
case V_434 :
V_14 = F_10 ( & V_382 -> V_435 -> V_2 ) ;
break;
default:
F_15 ( 1 ) ;
break;
}
return V_14 ;
}
static struct V_436 * F_365 ( struct V_428 * V_382 )
{
struct V_52 * V_39 ;
int V_14 ;
if ( ! V_382 )
return NULL ;
V_14 = F_362 ( V_382 ) ;
if ( V_14 >= 0 ) {
V_39 = V_35 [ V_14 ] ;
if ( V_39 )
return V_39 -> V_437 ;
}
return NULL ;
}
static struct V_436 * F_366 ( struct V_428 * V_382 )
{
struct V_52 * V_39 ;
int V_14 ;
if ( ! V_382 )
return NULL ;
switch ( V_382 -> type ) {
case V_433 :
case V_434 :
V_14 = F_10 ( & V_382 -> V_435 -> V_2 ) ;
if ( V_14 < 0 )
return NULL ;
V_39 = V_35 [ V_14 ] ;
if ( V_39 )
return V_39 -> V_438 ;
break;
default:
break;
}
return NULL ;
}
static void F_367 ( struct V_411 * V_31 ,
struct V_439 * V_439 ,
struct V_428 * V_382 ,
int V_14 , int V_255 , int V_440 )
{
struct V_441 * V_442 = & V_31 -> V_441 ;
struct V_443 * V_444 = & V_31 -> V_445 ;
struct V_446 * V_4 ;
struct V_52 * V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
return;
V_31 -> V_441 . V_14 = V_14 ;
V_31 -> V_441 . V_255 = V_255 + V_440 ;
V_39 -> V_404 -> V_447 ( V_31 -> V_4 , V_448 -> V_449 ,
V_448 -> V_450 , V_439 -> V_420 ,
V_439 -> V_421 , V_14 ) ;
switch ( V_382 -> type ) {
case V_429 :
V_4 = V_382 -> V_451 ;
V_382 -> V_451 = NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_420 = V_255 ;
V_4 -> V_297 = 0 ;
V_4 -> V_452 = V_382 -> V_453 ;
V_4 -> V_454 = V_382 -> V_455 ;
if ( V_382 -> V_453 )
V_4 -> V_297 = 1 ;
break;
case V_431 :
case V_433 :
case V_434 :
V_444 -> V_456 = V_457 ;
V_444 -> V_458 = V_459 ;
V_444 -> V_31 = V_442 -> V_255 ;
break;
default:
F_15 ( 1 ) ;
break;
}
}
static int F_368 ( struct V_436 * V_19 , unsigned int V_460 ,
unsigned int V_461 , void * V_462 )
{
struct V_428 * V_382 = V_462 ;
struct V_463 * V_463 ;
struct V_411 * V_31 = NULL ;
struct V_439 * V_464 ;
int V_46 , V_162 , V_14 ;
int V_255 = - 1 ;
if ( ! V_382 )
return - V_15 ;
if ( V_461 > 1 && V_382 -> type != V_433 &&
V_382 -> type != V_434 )
return - V_15 ;
if ( V_382 -> type == V_433 )
V_382 -> V_21 &= ~ V_465 ;
V_14 = F_362 ( V_382 ) ;
if ( V_14 < 0 )
return - V_15 ;
V_162 = F_369 ( V_19 , V_460 , V_461 , V_462 ) ;
if ( V_162 < 0 )
return V_162 ;
if ( V_382 -> type == V_429 ) {
if ( F_341 ( V_14 , true ) )
V_255 = V_382 -> V_466 ;
else
V_162 = - V_53 ;
} else {
V_255 = F_344 ( V_14 , V_461 ) ;
}
if ( V_255 < 0 ) {
F_370 ( L_40 ) ;
V_162 = V_255 ;
goto V_467;
}
for ( V_46 = 0 ; V_46 < V_461 ; V_46 ++ ) {
V_463 = F_371 ( V_19 , V_460 + V_46 ) ;
V_464 = F_372 ( V_463 ) ;
if ( ! V_463 || ! V_464 ) {
V_162 = - V_15 ;
goto V_468;
}
V_162 = - V_53 ;
V_31 = F_17 ( sizeof( * V_31 ) , V_25 ) ;
if ( ! V_31 )
goto V_468;
if ( ! F_343 ( V_348 ) )
V_31 -> V_4 = F_17 ( sizeof( union V_410 ) , V_25 ) ;
else
V_31 -> V_4 = F_17 ( sizeof( struct V_409 ) ,
V_25 ) ;
if ( ! V_31 -> V_4 ) {
F_185 ( V_31 ) ;
goto V_468;
}
V_463 -> V_469 = ( V_14 << 16 ) + V_46 ;
V_463 -> V_470 = V_31 ;
V_463 -> V_471 = & V_472 ;
F_367 ( V_31 , V_464 , V_382 , V_14 , V_255 , V_46 ) ;
F_373 ( V_460 + V_46 , V_473 ) ;
}
return 0 ;
V_468:
for ( V_46 -- ; V_46 >= 0 ; V_46 -- ) {
V_463 = F_371 ( V_19 , V_460 + V_46 ) ;
if ( V_463 )
F_185 ( V_463 -> V_470 ) ;
}
for ( V_46 = 0 ; V_46 < V_461 ; V_46 ++ )
F_347 ( V_14 , V_255 + V_46 ) ;
V_467:
F_374 ( V_19 , V_460 , V_461 ) ;
return V_162 ;
}
static void F_375 ( struct V_436 * V_19 , unsigned int V_460 ,
unsigned int V_461 )
{
struct V_441 * V_442 ;
struct V_463 * V_463 ;
struct V_411 * V_31 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_461 ; V_46 ++ ) {
V_463 = F_371 ( V_19 , V_460 + V_46 ) ;
if ( V_463 && V_463 -> V_470 ) {
V_31 = V_463 -> V_470 ;
V_442 = & V_31 -> V_441 ;
F_347 ( V_442 -> V_14 , V_442 -> V_255 ) ;
F_185 ( V_31 -> V_4 ) ;
F_185 ( V_31 ) ;
}
}
F_374 ( V_19 , V_460 , V_461 ) ;
}
static void F_376 ( struct V_436 * V_19 ,
struct V_463 * V_463 )
{
struct V_411 * V_31 = V_463 -> V_470 ;
struct V_441 * V_442 = & V_31 -> V_441 ;
struct V_52 * V_39 = V_35 [ V_442 -> V_14 ] ;
if ( V_39 )
V_39 -> V_404 -> V_474 ( V_31 -> V_4 , V_442 -> V_14 ,
V_442 -> V_255 ) ;
}
static void F_377 ( struct V_436 * V_19 ,
struct V_463 * V_463 )
{
struct V_411 * V_31 = V_463 -> V_470 ;
struct V_441 * V_442 = & V_31 -> V_441 ;
struct V_52 * V_39 = V_35 [ V_442 -> V_14 ] ;
if ( V_39 )
V_39 -> V_404 -> V_475 ( V_31 -> V_4 , V_442 -> V_14 ,
V_442 -> V_255 ) ;
}
static int F_378 ( struct V_463 * V_31 , void * V_476 )
{
struct V_52 * V_39 ;
struct V_477 * V_478 = V_476 ;
struct V_479 * V_480 = V_478 -> V_479 ;
struct V_411 * V_481 = V_31 -> V_470 ;
struct V_409 * V_410 = (struct V_409 * ) V_481 -> V_4 ;
struct V_441 * V_442 = & V_481 -> V_441 ;
struct V_23 * V_24 = F_22 ( V_442 -> V_14 ) ;
if ( ! V_24 || ! V_24 -> V_349 )
return 0 ;
V_478 -> V_481 = V_481 ;
if ( ! F_302 ( V_348 ) ) {
F_82 ( L_41 ,
V_116 ) ;
V_478 -> V_482 = false ;
}
V_39 = V_35 [ V_442 -> V_14 ] ;
if ( V_39 == NULL )
return - V_15 ;
V_478 -> V_483 = V_481 -> V_484 ;
if ( V_478 -> V_482 ) {
V_410 -> V_415 . V_422 . V_485 = ( V_478 -> V_486 >> 12 ) ;
V_410 -> V_415 . V_422 . V_420 = V_480 -> V_420 ;
V_410 -> V_412 . V_487 . V_488 = 1 ;
V_410 -> V_412 . V_487 . V_426 = 1 ;
V_410 -> V_412 . V_487 . V_489 = V_478 -> V_489 ;
V_481 -> V_484 = V_478 -> V_489 ;
} else {
struct V_439 * V_464 = F_372 ( V_31 ) ;
V_410 -> V_415 . V_320 = 0 ;
V_410 -> V_412 . V_320 = 0 ;
V_410 -> V_415 . V_422 . V_420 = V_464 -> V_420 ;
V_410 -> V_412 . V_413 . V_426 = 0 ;
V_410 -> V_412 . V_413 . V_424 = V_464 -> V_421 ;
V_410 -> V_412 . V_413 . V_423 = V_448 -> V_449 ;
V_410 -> V_412 . V_413 . V_425 = V_448 -> V_450 ;
V_481 -> V_484 = 0 ;
}
return F_345 ( V_442 -> V_14 , V_442 -> V_255 , V_410 , V_481 ) ;
}
static int F_379 ( struct V_463 * V_31 ,
const struct V_490 * V_297 , bool V_491 )
{
struct V_411 * V_481 = V_31 -> V_470 ;
struct V_441 * V_442 = & V_481 -> V_441 ;
struct V_439 * V_464 = F_372 ( V_31 ) ;
struct V_463 * V_492 = V_31 -> V_493 ;
struct V_52 * V_39 = V_35 [ V_442 -> V_14 ] ;
int V_162 ;
if ( ! V_39 )
return - V_7 ;
V_162 = V_492 -> V_471 -> V_494 ( V_492 , V_297 , V_491 ) ;
if ( V_162 < 0 || V_162 == V_495 )
return V_162 ;
V_39 -> V_404 -> V_496 ( V_481 -> V_4 , V_442 -> V_14 ,
V_442 -> V_255 , V_464 -> V_420 , V_464 -> V_421 ) ;
F_380 ( V_464 ) ;
return V_495 ;
}
static void F_381 ( struct V_463 * V_463 , struct V_443 * V_444 )
{
struct V_411 * V_481 = V_463 -> V_470 ;
* V_444 = V_481 -> V_445 ;
}
int F_382 ( struct V_52 * V_39 )
{
struct V_497 * V_498 ;
V_498 = F_383 ( L_42 , V_39 -> V_255 ) ;
if ( ! V_498 )
return - V_53 ;
V_39 -> V_437 = F_384 ( V_498 , & V_499 , V_39 ) ;
F_385 ( V_498 ) ;
if ( ! V_39 -> V_437 )
return - V_53 ;
V_39 -> V_437 -> V_492 = F_386 () ;
V_39 -> V_438 = F_387 ( V_39 -> V_437 ,
L_43 ,
V_39 -> V_255 ) ;
return 0 ;
}
int F_388 ( int V_221 , bool V_500 , void * V_31 )
{
unsigned long V_21 ;
struct V_52 * V_39 ;
struct V_392 * V_501 ;
struct V_411 * V_481 = (struct V_411 * ) V_31 ;
int V_14 = V_481 -> V_441 . V_14 ;
struct V_409 * V_4 = (struct V_409 * ) V_481 -> V_4 ;
struct V_409 * V_416 = (struct V_409 * ) V_481 -> V_416 ;
if ( ! F_302 ( V_348 ) ||
! V_416 || ! V_4 || ! V_4 -> V_412 . V_487 . V_426 )
return 0 ;
V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
return - V_7 ;
V_501 = F_341 ( V_14 , false ) ;
if ( ! V_501 )
return - V_7 ;
F_18 ( & V_501 -> V_163 , V_21 ) ;
if ( V_416 -> V_412 . V_487 . V_426 ) {
if ( V_221 >= 0 )
V_416 -> V_412 . V_487 . V_424 = V_221 ;
V_416 -> V_412 . V_487 . V_500 = V_500 ;
F_389 () ;
}
F_20 ( & V_501 -> V_163 , V_21 ) ;
F_115 ( V_39 , V_14 ) ;
F_110 ( V_39 ) ;
return 0 ;
}
