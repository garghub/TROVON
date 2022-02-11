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
return V_4 -> V_40 ;
}
static bool F_36 ( struct V_8 * V_9 )
{
static const int V_41 [] = {
V_42 ,
V_43 ,
V_44 ,
} ;
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < 3 ; ++ V_45 ) {
V_46 = F_37 ( V_9 , V_41 [ V_45 ] ) ;
if ( V_46 == 0 )
return false ;
}
return true ;
}
static bool F_38 ( struct V_8 * V_9 , T_2 V_47 )
{
struct V_23 * V_24 ;
V_24 = F_32 ( & V_9 -> V_2 ) ;
return V_24 -> V_48 & ( 1 << V_47 ) ? true : false ;
}
static bool F_39 ( struct V_1 * V_2 )
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
static void F_40 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
V_40 = F_41 ( V_2 ) ;
if ( F_42 ( V_40 ) )
return;
F_43 ( V_40 ) ;
}
static int F_44 ( struct V_1 * V_2 )
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
if ( F_11 ( V_2 ) && F_36 ( F_6 ( V_2 ) ) ) {
struct V_52 * V_38 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_24 -> V_53 = V_38 -> V_54 ;
}
V_2 -> V_37 . V_38 = V_24 ;
F_45 ( V_34 [ V_24 -> V_14 ] -> V_55 ,
V_2 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
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
static void F_47 ( struct V_1 * V_2 )
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
F_48 ( V_2 ) ;
F_49 ( V_34 [ V_24 -> V_14 ] -> V_55 ,
V_2 ) ;
F_50 ( V_2 ) ;
V_2 -> V_37 . V_57 = NULL ;
}
static void F_51 ( T_1 V_14 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < 4 ; ++ V_45 )
F_52 ( L_5 , V_45 ,
V_35 [ V_14 ] . V_30 [ V_45 ] ) ;
}
static void F_53 ( unsigned long V_58 )
{
struct V_59 * V_60 = F_54 ( V_58 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 4 ; ++ V_45 )
F_52 ( L_6 , V_45 , V_60 -> V_30 [ V_45 ] ) ;
}
static void F_55 ( struct V_52 * V_38 , void * V_61 )
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
F_52 ( L_7 ) ;
return;
}
F_56 ( 1 ) ;
goto V_66;
}
F_57 ( V_76 L_8 ) ;
switch ( type ) {
case V_77 :
F_57 ( L_9
L_10 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_65 , V_21 ) ;
F_51 ( V_14 ) ;
break;
case V_78 :
F_57 ( L_11
L_12 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_62 , V_65 , V_21 ) ;
break;
case V_79 :
F_57 ( L_13
L_10 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_65 , V_21 ) ;
break;
case V_80 :
F_57 ( L_14
L_12 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_62 , V_65 , V_21 ) ;
break;
case V_81 :
F_57 ( L_15 , V_65 ) ;
F_53 ( V_65 ) ;
break;
case V_82 :
F_57 ( L_16
L_17 , V_65 , V_21 ) ;
break;
case V_83 :
F_57 ( L_18
L_19 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_65 ) ;
break;
case V_84 :
F_57 ( L_20
L_10 ,
F_26 ( V_14 ) , F_27 ( V_14 ) , F_28 ( V_14 ) ,
V_65 , V_21 ) ;
break;
default:
F_57 ( V_76 L_21 , type ) ;
}
memset ( V_61 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_58 ( struct V_52 * V_38 )
{
T_2 V_85 , V_86 ;
V_85 = F_59 ( V_38 -> V_87 + V_88 ) ;
V_86 = F_59 ( V_38 -> V_87 + V_89 ) ;
while ( V_85 != V_86 ) {
F_55 ( V_38 , V_38 -> V_90 + V_85 ) ;
V_85 = ( V_85 + V_91 ) % V_92 ;
}
F_60 ( V_85 , V_38 -> V_87 + V_88 ) ;
}
static void F_61 ( struct V_52 * V_38 , T_3 * V_93 )
{
struct V_94 V_95 ;
if ( F_62 ( V_93 [ 0 ] ) != V_96 ) {
F_63 ( L_22 ) ;
return;
}
V_95 . V_65 = V_93 [ 1 ] ;
V_95 . V_97 = F_64 ( V_93 [ 0 ] ) ;
V_95 . V_98 = F_65 ( V_93 [ 0 ] ) ;
V_95 . V_99 = F_66 ( V_93 [ 0 ] ) ;
V_95 . V_21 = F_67 ( V_93 [ 0 ] ) ;
F_68 ( & V_100 , 0 , & V_95 ) ;
}
static void F_69 ( struct V_52 * V_38 )
{
T_2 V_85 , V_86 ;
if ( V_38 -> V_101 == NULL )
return;
V_85 = F_59 ( V_38 -> V_87 + V_102 ) ;
V_86 = F_59 ( V_38 -> V_87 + V_103 ) ;
while ( V_85 != V_86 ) {
volatile T_3 * V_93 ;
T_3 V_4 [ 2 ] ;
int V_45 ;
V_93 = ( T_3 * ) ( V_38 -> V_101 + V_85 ) ;
for ( V_45 = 0 ; V_45 < V_75 ; ++ V_45 ) {
if ( F_62 ( V_93 [ 0 ] ) != 0 )
break;
F_56 ( 1 ) ;
}
V_4 [ 0 ] = V_93 [ 0 ] ;
V_4 [ 1 ] = V_93 [ 1 ] ;
V_93 [ 0 ] = V_93 [ 1 ] = 0UL ;
V_85 = ( V_85 + V_104 ) % V_105 ;
F_60 ( V_85 , V_38 -> V_87 + V_102 ) ;
F_61 ( V_38 , V_4 ) ;
V_85 = F_59 ( V_38 -> V_87 + V_102 ) ;
V_86 = F_59 ( V_38 -> V_87 + V_103 ) ;
}
}
T_4 F_70 ( int V_106 , void * V_30 )
{
struct V_52 * V_38 = (struct V_52 * ) V_30 ;
T_2 V_107 = F_59 ( V_38 -> V_87 + V_108 ) ;
while ( V_107 & ( V_109 | V_110 ) ) {
F_60 ( ( V_109 | V_110 ) ,
V_38 -> V_87 + V_108 ) ;
if ( V_107 & V_109 ) {
F_71 ( L_23 ) ;
F_58 ( V_38 ) ;
}
if ( V_107 & V_110 ) {
F_71 ( L_24 ) ;
F_69 ( V_38 ) ;
}
V_107 = F_59 ( V_38 -> V_87 + V_108 ) ;
}
return V_111 ;
}
T_4 F_72 ( int V_106 , void * V_30 )
{
return V_112 ;
}
static int F_73 ( volatile T_3 * V_113 )
{
int V_45 = 0 ;
while ( * V_113 == 0 && V_45 < V_75 ) {
F_56 ( 1 ) ;
V_45 += 1 ;
}
if ( V_45 == V_75 ) {
F_74 ( L_25 ) ;
return - V_114 ;
}
return 0 ;
}
static void F_75 ( struct V_52 * V_38 ,
struct V_59 * V_60 ,
T_2 V_86 )
{
T_5 * V_115 ;
V_115 = V_38 -> V_116 + V_86 ;
V_86 = ( V_86 + sizeof( * V_60 ) ) % V_117 ;
memcpy ( V_115 , V_60 , sizeof( * V_60 ) ) ;
F_60 ( V_86 , V_38 -> V_87 + V_118 ) ;
}
static void F_76 ( struct V_59 * V_60 , T_3 V_65 )
{
F_77 ( V_65 & 0x7ULL ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = F_78 ( F_79 ( V_65 ) ) | V_119 ;
V_60 -> V_30 [ 1 ] = F_80 ( F_79 ( V_65 ) ) ;
V_60 -> V_30 [ 2 ] = 1 ;
F_81 ( V_60 , V_120 ) ;
}
static void F_82 ( struct V_59 * V_60 , T_1 V_14 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
F_81 ( V_60 , V_121 ) ;
}
static void F_83 ( struct V_59 * V_60 , T_3 V_65 ,
T_6 V_122 , T_1 V_62 , int V_123 )
{
T_3 V_124 ;
bool V_125 ;
V_124 = F_84 ( V_65 , V_122 , V_126 ) ;
V_125 = false ;
if ( V_124 > 1 ) {
V_65 = V_127 ;
V_125 = true ;
}
V_65 &= V_128 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 1 ] |= V_62 ;
V_60 -> V_30 [ 2 ] = F_78 ( V_65 ) ;
V_60 -> V_30 [ 3 ] = F_80 ( V_65 ) ;
F_81 ( V_60 , V_129 ) ;
if ( V_125 )
V_60 -> V_30 [ 2 ] |= V_130 ;
if ( V_123 )
V_60 -> V_30 [ 2 ] |= V_131 ;
}
static void F_85 ( struct V_59 * V_60 , T_1 V_14 , int V_132 ,
T_3 V_65 , T_6 V_122 )
{
T_3 V_124 ;
bool V_125 ;
V_124 = F_84 ( V_65 , V_122 , V_126 ) ;
V_125 = false ;
if ( V_124 > 1 ) {
V_65 = V_127 ;
V_125 = true ;
}
V_65 &= V_128 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
V_60 -> V_30 [ 0 ] |= ( V_132 & 0xff ) << 24 ;
V_60 -> V_30 [ 1 ] = V_14 ;
V_60 -> V_30 [ 2 ] = F_78 ( V_65 ) ;
V_60 -> V_30 [ 3 ] = F_80 ( V_65 ) ;
F_81 ( V_60 , V_133 ) ;
if ( V_125 )
V_60 -> V_30 [ 2 ] |= V_130 ;
}
static void F_86 ( struct V_59 * V_60 , T_1 V_62 , int V_97 ,
T_3 V_65 , bool V_122 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_65 &= ~ ( 0xfffULL ) ;
V_60 -> V_30 [ 0 ] = V_97 ;
V_60 -> V_30 [ 1 ] = V_62 ;
V_60 -> V_30 [ 2 ] = F_78 ( V_65 ) ;
V_60 -> V_30 [ 3 ] = F_80 ( V_65 ) ;
V_60 -> V_30 [ 2 ] |= V_131 ;
V_60 -> V_30 [ 2 ] |= V_134 ;
if ( V_122 )
V_60 -> V_30 [ 2 ] |= V_130 ;
F_81 ( V_60 , V_129 ) ;
}
static void F_87 ( struct V_59 * V_60 , T_1 V_14 , int V_97 ,
int V_132 , T_3 V_65 , bool V_122 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_65 &= ~ ( 0xfffULL ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
V_60 -> V_30 [ 0 ] |= ( ( V_97 >> 8 ) & 0xff ) << 16 ;
V_60 -> V_30 [ 0 ] |= ( V_132 & 0xff ) << 24 ;
V_60 -> V_30 [ 1 ] = V_14 ;
V_60 -> V_30 [ 1 ] |= ( V_97 & 0xff ) << 16 ;
V_60 -> V_30 [ 2 ] = F_78 ( V_65 ) ;
V_60 -> V_30 [ 2 ] |= V_134 ;
V_60 -> V_30 [ 3 ] = F_80 ( V_65 ) ;
if ( V_122 )
V_60 -> V_30 [ 2 ] |= V_130 ;
F_81 ( V_60 , V_133 ) ;
}
static void F_88 ( struct V_59 * V_60 , T_1 V_14 , int V_97 ,
int V_107 , int V_99 , bool V_135 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
if ( V_135 ) {
V_60 -> V_30 [ 1 ] = V_97 ;
V_60 -> V_30 [ 2 ] = V_134 ;
}
V_60 -> V_30 [ 3 ] = V_99 & 0x1ff ;
V_60 -> V_30 [ 3 ] |= ( V_107 & V_136 ) << V_137 ;
F_81 ( V_60 , V_138 ) ;
}
static void F_89 ( struct V_59 * V_60 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_81 ( V_60 , V_139 ) ;
}
static void F_90 ( struct V_59 * V_60 , T_1 V_14 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_30 [ 0 ] = V_14 ;
F_81 ( V_60 , V_140 ) ;
}
static int F_91 ( struct V_52 * V_38 ,
struct V_59 * V_60 ,
bool V_141 )
{
T_2 V_142 , V_86 , V_85 , V_143 ;
unsigned long V_21 ;
V_144:
F_18 ( & V_38 -> V_145 , V_21 ) ;
V_85 = F_59 ( V_38 -> V_87 + V_146 ) ;
V_86 = F_59 ( V_38 -> V_87 + V_118 ) ;
V_143 = ( V_86 + sizeof( * V_60 ) ) % V_117 ;
V_142 = ( V_85 - V_143 ) % V_117 ;
if ( V_142 <= 2 ) {
struct V_59 V_147 ;
volatile T_3 V_113 = 0 ;
int V_148 ;
F_76 ( & V_147 , ( T_3 ) & V_113 ) ;
F_75 ( V_38 , & V_147 , V_86 ) ;
F_20 ( & V_38 -> V_145 , V_21 ) ;
if ( ( V_148 = F_73 ( & V_113 ) ) != 0 )
return V_148 ;
goto V_144;
}
F_75 ( V_38 , V_60 , V_86 ) ;
V_38 -> V_149 = V_141 ;
F_20 ( & V_38 -> V_145 , V_21 ) ;
return 0 ;
}
static int F_92 ( struct V_52 * V_38 , struct V_59 * V_60 )
{
return F_91 ( V_38 , V_60 , true ) ;
}
static int F_93 ( struct V_52 * V_38 )
{
struct V_59 V_60 ;
volatile T_3 V_113 = 0 ;
int V_148 ;
if ( ! V_38 -> V_149 )
return 0 ;
F_76 ( & V_60 , ( T_3 ) & V_113 ) ;
V_148 = F_91 ( V_38 , & V_60 , false ) ;
if ( V_148 )
return V_148 ;
return F_73 ( & V_113 ) ;
}
static int F_94 ( struct V_52 * V_38 , T_1 V_14 )
{
struct V_59 V_60 ;
F_82 ( & V_60 , V_14 ) ;
return F_92 ( V_38 , & V_60 ) ;
}
static void F_95 ( struct V_52 * V_38 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= 0xffff ; ++ V_14 )
F_94 ( V_38 , V_14 ) ;
F_93 ( V_38 ) ;
}
static void F_96 ( struct V_52 * V_38 )
{
T_2 V_150 ;
for ( V_150 = 0 ; V_150 <= 0xffff ; ++ V_150 ) {
struct V_59 V_60 ;
F_83 ( & V_60 , 0 , V_127 ,
V_150 , 1 ) ;
F_92 ( V_38 , & V_60 ) ;
}
F_93 ( V_38 ) ;
}
static void F_97 ( struct V_52 * V_38 )
{
struct V_59 V_60 ;
F_89 ( & V_60 ) ;
F_92 ( V_38 , & V_60 ) ;
F_93 ( V_38 ) ;
}
static void F_98 ( struct V_52 * V_38 , T_1 V_14 )
{
struct V_59 V_60 ;
F_90 ( & V_60 , V_14 ) ;
F_92 ( V_38 , & V_60 ) ;
}
static void F_99 ( struct V_52 * V_38 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= V_151 ; V_14 ++ )
F_98 ( V_38 , V_14 ) ;
F_93 ( V_38 ) ;
}
void F_100 ( struct V_52 * V_38 )
{
if ( F_101 ( V_38 , V_152 ) ) {
F_97 ( V_38 ) ;
} else {
F_95 ( V_38 ) ;
F_99 ( V_38 ) ;
F_96 ( V_38 ) ;
}
}
static int F_102 ( struct V_23 * V_24 ,
T_3 V_65 , T_6 V_122 )
{
struct V_52 * V_38 ;
struct V_59 V_60 ;
int V_132 ;
V_132 = V_24 -> V_153 . V_132 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_85 ( & V_60 , V_24 -> V_14 , V_132 , V_65 , V_122 ) ;
return F_92 ( V_38 , & V_60 ) ;
}
static int F_103 ( struct V_23 * V_24 )
{
struct V_52 * V_38 ;
T_1 V_29 ;
int V_148 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_148 = F_94 ( V_38 , V_24 -> V_14 ) ;
if ( ! V_148 && V_29 != V_24 -> V_14 )
V_148 = F_94 ( V_38 , V_29 ) ;
if ( V_148 )
return V_148 ;
if ( V_24 -> V_153 . V_154 )
V_148 = F_102 ( V_24 , 0 , ~ 0UL ) ;
return V_148 ;
}
static void F_104 ( struct V_16 * V_19 ,
T_3 V_65 , T_6 V_122 , int V_123 )
{
struct V_23 * V_24 ;
struct V_59 V_60 ;
int V_148 = 0 , V_45 ;
F_83 ( & V_60 , V_65 , V_122 , V_19 -> V_155 , V_123 ) ;
for ( V_45 = 0 ; V_45 < V_156 ; ++ V_45 ) {
if ( ! V_19 -> V_157 [ V_45 ] )
continue;
V_148 |= F_92 ( V_158 [ V_45 ] , & V_60 ) ;
}
F_9 (dev_data, &domain->dev_list, list) {
if ( ! V_24 -> V_153 . V_154 )
continue;
V_148 |= F_102 ( V_24 , V_65 , V_122 ) ;
}
F_77 ( V_148 ) ;
}
static void F_105 ( struct V_16 * V_19 ,
T_3 V_65 , T_6 V_122 )
{
F_104 ( V_19 , V_65 , V_122 , 0 ) ;
}
static void F_106 ( struct V_16 * V_19 )
{
F_104 ( V_19 , 0 , V_127 , 0 ) ;
}
static void F_107 ( struct V_16 * V_19 )
{
F_104 ( V_19 , 0 , V_127 , 1 ) ;
}
static void F_108 ( struct V_16 * V_19 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_156 ; ++ V_45 ) {
if ( V_19 && ! V_19 -> V_157 [ V_45 ] )
continue;
F_93 ( V_158 [ V_45 ] ) ;
}
}
static void F_109 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list)
F_103 ( V_24 ) ;
}
static bool F_110 ( struct V_16 * V_19 ,
T_7 V_159 )
{
T_3 * V_160 ;
if ( V_19 -> V_161 == V_162 )
return false ;
V_160 = ( void * ) F_111 ( V_159 ) ;
if ( ! V_160 )
return false ;
* V_160 = F_112 ( V_19 -> V_161 ,
F_113 ( V_19 -> V_163 ) ) ;
V_19 -> V_163 = V_160 ;
V_19 -> V_161 += 1 ;
V_19 -> V_164 = true ;
return true ;
}
static T_3 * F_114 ( struct V_16 * V_19 ,
unsigned long V_65 ,
unsigned long V_165 ,
T_3 * * V_166 ,
T_7 V_159 )
{
int V_167 , V_168 ;
T_3 * V_160 , * V_169 ;
F_15 ( ! F_115 ( V_165 ) ) ;
while ( V_65 > F_116 ( V_19 -> V_161 ) )
F_110 ( V_19 , V_159 ) ;
V_167 = V_19 -> V_161 - 1 ;
V_160 = & V_19 -> V_163 [ F_117 ( V_167 , V_65 ) ] ;
V_65 = F_118 ( V_65 , V_165 ) ;
V_168 = F_119 ( V_165 ) ;
while ( V_167 > V_168 ) {
T_3 V_170 , V_171 ;
V_170 = * V_160 ;
if ( ! F_120 ( V_170 ) ) {
V_169 = ( T_3 * ) F_111 ( V_159 ) ;
if ( ! V_169 )
return NULL ;
V_171 = F_112 ( V_167 , F_113 ( V_169 ) ) ;
if ( F_121 ( V_160 , V_170 , V_171 ) ) {
F_122 ( ( unsigned long ) V_169 ) ;
continue;
}
}
if ( F_123 ( * V_160 ) != V_167 )
return NULL ;
V_167 -= 1 ;
V_160 = F_124 ( * V_160 ) ;
if ( V_166 && V_167 == V_168 )
* V_166 = V_160 ;
V_160 = & V_160 [ F_117 ( V_167 , V_65 ) ] ;
}
return V_160 ;
}
static T_3 * F_125 ( struct V_16 * V_19 ,
unsigned long V_65 ,
unsigned long * V_165 )
{
int V_167 ;
T_3 * V_160 ;
if ( V_65 > F_116 ( V_19 -> V_161 ) )
return NULL ;
V_167 = V_19 -> V_161 - 1 ;
V_160 = & V_19 -> V_163 [ F_117 ( V_167 , V_65 ) ] ;
* V_165 = F_126 ( V_167 ) ;
while ( V_167 > 0 ) {
if ( ! F_120 ( * V_160 ) )
return NULL ;
if ( F_123 ( * V_160 ) == 7 ||
F_123 ( * V_160 ) == 0 )
break;
if ( F_123 ( * V_160 ) != V_167 )
return NULL ;
V_167 -= 1 ;
V_160 = F_124 ( * V_160 ) ;
V_160 = & V_160 [ F_117 ( V_167 , V_65 ) ] ;
* V_165 = F_126 ( V_167 ) ;
}
if ( F_123 ( * V_160 ) == 0x07 ) {
unsigned long V_172 ;
* V_165 = V_172 = F_127 ( * V_160 ) ;
V_172 = ~ ( ( F_128 ( V_172 ) << 3 ) - 1 ) ;
V_160 = ( T_3 * ) ( ( ( unsigned long ) V_160 ) & V_172 ) ;
}
return V_160 ;
}
static int F_129 ( struct V_16 * V_18 ,
unsigned long V_173 ,
unsigned long V_58 ,
unsigned long V_165 ,
int V_174 ,
T_7 V_159 )
{
T_3 V_170 , * V_160 ;
int V_45 , V_64 ;
F_15 ( ! F_130 ( V_173 , V_165 ) ) ;
F_15 ( ! F_130 ( V_58 , V_165 ) ) ;
if ( ! ( V_174 & V_175 ) )
return - V_15 ;
V_64 = F_128 ( V_165 ) ;
V_160 = F_114 ( V_18 , V_173 , V_165 , NULL , V_159 ) ;
if ( ! V_160 )
return - V_51 ;
for ( V_45 = 0 ; V_45 < V_64 ; ++ V_45 )
if ( F_120 ( V_160 [ V_45 ] ) )
return - V_176 ;
if ( V_64 > 1 ) {
V_170 = F_131 ( V_58 , V_165 ) ;
V_170 |= F_132 ( 7 ) | V_177 | V_178 ;
} else
V_170 = V_58 | V_177 | V_178 ;
if ( V_174 & V_179 )
V_170 |= V_180 ;
if ( V_174 & V_181 )
V_170 |= V_182 ;
for ( V_45 = 0 ; V_45 < V_64 ; ++ V_45 )
V_160 [ V_45 ] = V_170 ;
F_133 ( V_18 ) ;
return 0 ;
}
static unsigned long F_134 ( struct V_16 * V_18 ,
unsigned long V_173 ,
unsigned long V_165 )
{
unsigned long long V_183 ;
unsigned long V_184 ;
T_3 * V_160 ;
F_15 ( ! F_115 ( V_165 ) ) ;
V_183 = 0 ;
while ( V_183 < V_165 ) {
V_160 = F_125 ( V_18 , V_173 , & V_184 ) ;
if ( V_160 ) {
int V_45 , V_64 ;
V_64 = F_128 ( V_184 ) ;
for ( V_45 = 0 ; V_45 < V_64 ; V_45 ++ )
V_160 [ V_45 ] = 0ULL ;
}
V_173 = ( V_173 & ~ ( V_184 - 1 ) ) + V_184 ;
V_183 += V_184 ;
}
F_15 ( V_183 && ! F_115 ( V_183 ) ) ;
return V_183 ;
}
static unsigned long F_135 ( struct V_1 * V_2 ,
struct V_20 * V_185 ,
unsigned int V_124 , T_3 V_49 )
{
unsigned long V_186 = 0 ;
V_124 = F_136 ( V_124 ) ;
if ( V_49 > F_137 ( 32 ) )
V_186 = F_138 ( & V_185 -> V_187 , V_124 ,
F_139 ( F_137 ( 32 ) ) ) ;
if ( ! V_186 )
V_186 = F_138 ( & V_185 -> V_187 , V_124 , F_139 ( V_49 ) ) ;
return ( V_186 << V_188 ) ;
}
static void F_140 ( struct V_20 * V_185 ,
unsigned long V_65 ,
unsigned int V_124 )
{
V_124 = F_136 ( V_124 ) ;
V_65 >>= V_188 ;
F_141 ( & V_185 -> V_187 , V_65 , V_124 ) ;
}
static void F_142 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_189 , V_21 ) ;
F_143 ( & V_19 -> V_190 , & V_191 ) ;
F_20 ( & V_189 , V_21 ) ;
}
static void F_144 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_189 , V_21 ) ;
F_145 ( & V_19 -> V_190 ) ;
F_20 ( & V_189 , V_21 ) ;
}
static T_1 F_146 ( void )
{
unsigned long V_21 ;
int V_155 ;
F_147 ( & V_192 , V_21 ) ;
V_155 = F_148 ( V_193 , V_194 ) ;
F_15 ( V_155 == 0 ) ;
if ( V_155 > 0 && V_155 < V_194 )
F_149 ( V_155 , V_193 ) ;
else
V_155 = 0 ;
F_150 ( & V_192 , V_21 ) ;
return V_155 ;
}
static void F_151 ( int V_155 )
{
unsigned long V_21 ;
F_147 ( & V_192 , V_21 ) ;
if ( V_155 > 0 && V_155 < V_194 )
F_152 ( V_155 , V_193 ) ;
F_150 ( & V_192 , V_21 ) ;
}
static void F_153 ( struct V_16 * V_19 )
{
unsigned long V_195 = ( unsigned long ) V_19 -> V_163 ;
switch ( V_19 -> V_161 ) {
case V_196 :
break;
case V_197 :
F_122 ( V_195 ) ;
break;
case V_198 :
F_154 ( V_195 ) ;
break;
case V_199 :
F_155 ( V_195 ) ;
break;
case V_200 :
F_156 ( V_195 ) ;
break;
case V_201 :
F_157 ( V_195 ) ;
break;
case V_162 :
F_158 ( V_195 ) ;
break;
default:
F_159 () ;
}
}
static void F_160 ( T_3 * V_202 )
{
T_3 * V_203 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 512 ; ++ V_45 ) {
if ( ! ( V_202 [ V_45 ] & V_204 ) )
continue;
V_203 = F_161 ( V_202 [ V_45 ] & V_128 ) ;
F_122 ( ( unsigned long ) V_203 ) ;
}
}
static void F_162 ( T_3 * V_202 )
{
T_3 * V_203 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < 512 ; ++ V_45 ) {
if ( ! ( V_202 [ V_45 ] & V_204 ) )
continue;
V_203 = F_161 ( V_202 [ V_45 ] & V_128 ) ;
F_160 ( V_203 ) ;
}
}
static void F_163 ( struct V_16 * V_19 )
{
if ( V_19 -> V_205 == 2 )
F_162 ( V_19 -> V_206 ) ;
else if ( V_19 -> V_205 == 1 )
F_160 ( V_19 -> V_206 ) ;
else
F_15 ( V_19 -> V_205 != 0 ) ;
F_122 ( ( unsigned long ) V_19 -> V_206 ) ;
}
static void F_164 ( struct V_20 * V_18 )
{
if ( ! V_18 )
return;
F_144 ( & V_18 -> V_19 ) ;
F_165 ( & V_18 -> V_187 ) ;
F_153 ( & V_18 -> V_19 ) ;
F_166 ( V_18 ) ;
}
static struct V_20 * F_167 ( void )
{
struct V_20 * V_185 ;
V_185 = F_17 ( sizeof( struct V_20 ) , V_25 ) ;
if ( ! V_185 )
return NULL ;
if ( F_168 ( & V_185 -> V_19 ) )
goto V_207;
V_185 -> V_19 . V_161 = V_199 ;
V_185 -> V_19 . V_163 = ( void * ) F_111 ( V_25 ) ;
V_185 -> V_19 . V_21 = V_22 ;
if ( ! V_185 -> V_19 . V_163 )
goto V_207;
F_169 ( & V_185 -> V_187 , V_126 ,
V_208 , V_209 ) ;
F_170 ( & V_210 , & V_185 -> V_187 ) ;
F_142 ( & V_185 -> V_19 ) ;
return V_185 ;
V_207:
F_164 ( V_185 ) ;
return NULL ;
}
static bool V_20 ( struct V_16 * V_19 )
{
return V_19 -> V_21 & V_22 ;
}
static void F_171 ( T_1 V_14 , struct V_16 * V_19 , bool V_153 )
{
T_3 V_211 = 0 ;
T_3 V_21 = 0 ;
if ( V_19 -> V_161 != V_196 )
V_211 = F_113 ( V_19 -> V_163 ) ;
V_211 |= ( V_19 -> V_161 & V_212 )
<< V_213 ;
V_211 |= V_180 | V_182 | V_177 | V_214 ;
V_21 = V_35 [ V_14 ] . V_30 [ 1 ] ;
if ( V_153 )
V_21 |= V_215 ;
if ( V_19 -> V_21 & V_216 ) {
T_3 V_217 = F_79 ( V_19 -> V_206 ) ;
T_3 V_205 = V_19 -> V_205 ;
T_3 V_218 ;
V_211 |= V_219 ;
V_211 |= ( V_205 & V_220 ) << V_221 ;
V_218 = F_172 ( ~ 0ULL ) << V_222 ;
V_21 &= ~ V_218 ;
V_218 = F_173 ( ~ 0ULL ) << V_223 ;
V_21 &= ~ V_218 ;
V_218 = F_174 ( V_217 ) << V_224 ;
V_211 |= V_218 ;
V_218 = F_172 ( V_217 ) << V_222 ;
V_21 |= V_218 ;
V_218 = F_173 ( V_217 ) << V_223 ;
V_21 |= V_218 ;
}
V_21 &= ~ ( 0xffffUL ) ;
V_21 |= V_19 -> V_155 ;
V_35 [ V_14 ] . V_30 [ 1 ] = V_21 ;
V_35 [ V_14 ] . V_30 [ 0 ] = V_211 ;
}
static void F_175 ( T_1 V_14 )
{
V_35 [ V_14 ] . V_30 [ 0 ] = V_177 | V_214 ;
V_35 [ V_14 ] . V_30 [ 1 ] &= V_225 ;
F_176 ( V_14 ) ;
}
static void F_177 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
struct V_52 * V_38 ;
T_1 V_29 ;
bool V_153 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_153 = V_24 -> V_153 . V_154 ;
V_24 -> V_19 = V_19 ;
F_143 ( & V_24 -> V_190 , & V_19 -> V_226 ) ;
V_19 -> V_157 [ V_38 -> V_227 ] += 1 ;
V_19 -> V_228 += 1 ;
F_171 ( V_24 -> V_14 , V_19 , V_153 ) ;
if ( V_29 != V_24 -> V_14 )
F_171 ( V_29 , V_19 , V_153 ) ;
F_103 ( V_24 ) ;
}
static void F_178 ( struct V_23 * V_24 )
{
struct V_52 * V_38 ;
T_1 V_29 ;
if ( ! V_24 -> V_19 )
return;
V_38 = V_34 [ V_24 -> V_14 ] ;
V_29 = V_24 -> V_29 ;
V_24 -> V_19 -> V_157 [ V_38 -> V_227 ] -= 1 ;
V_24 -> V_19 -> V_228 -= 1 ;
V_24 -> V_19 = NULL ;
F_145 ( & V_24 -> V_190 ) ;
F_175 ( V_24 -> V_14 ) ;
if ( V_29 != V_24 -> V_14 )
F_175 ( V_29 ) ;
F_103 ( V_24 ) ;
}
static int F_179 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
int V_148 ;
F_77 ( ! F_180 () ) ;
F_181 ( & V_19 -> V_145 ) ;
V_148 = - V_176 ;
if ( V_24 -> V_19 != NULL )
goto V_28;
F_177 ( V_24 , V_19 ) ;
V_148 = 0 ;
V_28:
F_182 ( & V_19 -> V_145 ) ;
return V_148 ;
}
static void F_183 ( struct V_8 * V_9 )
{
F_184 ( V_9 ) ;
F_185 ( V_9 ) ;
F_186 ( V_9 ) ;
}
static int F_187 ( struct V_8 * V_9 )
{
T_1 V_229 ;
int V_46 ;
V_46 = F_37 ( V_9 , V_43 ) ;
if ( ! V_46 )
return - V_15 ;
F_188 ( V_9 , V_46 + V_230 , & V_229 ) ;
V_229 |= V_231 ;
F_189 ( V_9 , V_46 + V_230 , V_229 ) ;
return 0 ;
}
static int F_190 ( struct V_8 * V_9 )
{
bool V_232 ;
int V_233 , V_148 ;
V_233 = 32 ;
if ( F_38 ( V_9 , V_234 ) )
V_233 = 1 ;
V_232 = F_38 ( V_9 , V_235 ) ;
V_148 = F_191 ( V_9 , 0 ) ;
if ( V_148 )
goto V_236;
V_148 = F_192 ( V_9 ) ;
if ( V_148 )
goto V_236;
V_148 = F_193 ( V_9 , V_233 ) ;
if ( V_148 )
goto V_236;
if ( V_232 ) {
V_148 = F_187 ( V_9 ) ;
if ( V_148 )
goto V_236;
}
V_148 = F_194 ( V_9 , V_188 ) ;
if ( V_148 )
goto V_236;
return 0 ;
V_236:
F_185 ( V_9 ) ;
F_186 ( V_9 ) ;
return V_148 ;
}
static bool F_195 ( struct V_8 * V_9 )
{
T_1 V_107 ;
int V_46 ;
V_46 = F_37 ( V_9 , V_43 ) ;
if ( ! V_46 )
return false ;
F_188 ( V_9 , V_46 + V_237 , & V_107 ) ;
return ( V_107 & V_238 ) ? true : false ;
}
static int F_196 ( struct V_1 * V_2 ,
struct V_16 * V_19 )
{
struct V_8 * V_9 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
int V_148 ;
V_24 = F_32 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
goto V_239;
V_9 = F_6 ( V_2 ) ;
if ( V_19 -> V_21 & V_216 ) {
if ( ! V_24 -> V_240 )
return - V_15 ;
if ( V_24 -> V_53 ) {
if ( F_190 ( V_9 ) != 0 )
return - V_15 ;
V_24 -> V_153 . V_154 = true ;
V_24 -> V_153 . V_132 = F_197 ( V_9 ) ;
V_24 -> V_241 = F_195 ( V_9 ) ;
}
} else if ( V_242 &&
F_194 ( V_9 , V_188 ) == 0 ) {
V_24 -> V_153 . V_154 = true ;
V_24 -> V_153 . V_132 = F_197 ( V_9 ) ;
}
V_239:
F_147 ( & V_192 , V_21 ) ;
V_148 = F_179 ( V_24 , V_19 ) ;
F_150 ( & V_192 , V_21 ) ;
F_107 ( V_19 ) ;
return V_148 ;
}
static void F_198 ( struct V_23 * V_24 )
{
struct V_16 * V_19 ;
F_77 ( ! F_180 () ) ;
if ( F_77 ( ! V_24 -> V_19 ) )
return;
V_19 = V_24 -> V_19 ;
F_181 ( & V_19 -> V_145 ) ;
F_178 ( V_24 ) ;
F_182 ( & V_19 -> V_145 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
V_24 = F_32 ( V_2 ) ;
V_19 = V_24 -> V_19 ;
F_147 ( & V_192 , V_21 ) ;
F_198 ( V_24 ) ;
F_150 ( & V_192 , V_21 ) ;
if ( ! F_11 ( V_2 ) )
return;
if ( V_19 -> V_21 & V_216 && V_24 -> V_53 )
F_183 ( F_6 ( V_2 ) ) ;
else if ( V_24 -> V_153 . V_154 )
F_184 ( F_6 ( V_2 ) ) ;
V_24 -> V_153 . V_154 = false ;
}
static int F_199 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_17 * V_19 ;
struct V_52 * V_38 ;
int V_148 , V_14 ;
if ( ! F_39 ( V_2 ) || F_32 ( V_2 ) )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_38 = V_34 [ V_14 ] ;
V_148 = F_44 ( V_2 ) ;
if ( V_148 ) {
if ( V_148 != - V_243 )
F_52 ( L_26 ,
F_29 ( V_2 ) ) ;
F_46 ( V_2 ) ;
V_2 -> V_37 . V_57 = & V_244 ;
goto V_245;
}
F_40 ( V_2 ) ;
V_24 = F_32 ( V_2 ) ;
F_15 ( ! V_24 ) ;
if ( V_246 || V_24 -> V_53 )
F_200 ( V_2 ) ;
V_19 = F_201 ( V_2 ) ;
if ( V_19 -> type == V_247 )
V_24 -> V_240 = true ;
else
V_2 -> V_37 . V_57 = & V_248 ;
V_245:
F_93 ( V_38 ) ;
return 0 ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_52 * V_38 ;
int V_14 ;
if ( ! F_39 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_38 = V_34 [ V_14 ] ;
F_47 ( V_2 ) ;
F_93 ( V_38 ) ;
}
static struct V_39 * F_203 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) )
return F_204 ( V_2 ) ;
return F_33 ( V_2 ) ;
}
static void F_205 ( struct V_249 * V_250 )
{
struct V_16 * V_19 ;
unsigned long V_21 ;
int V_251 ;
F_18 ( & V_189 , V_21 ) ;
F_9 (domain, &amd_iommu_pd_list, list)
F_106 ( V_19 ) ;
F_20 ( & V_189 , V_21 ) ;
F_108 ( NULL ) ;
for ( V_251 = 0 ; V_251 < V_250 -> V_252 ; ++ V_251 ) {
struct V_253 * V_4 ;
V_4 = V_250 -> V_254 + V_251 ;
F_141 ( & V_4 -> V_185 -> V_187 ,
V_4 -> V_255 ,
V_4 -> V_124 ) ;
V_4 -> V_185 = NULL ;
}
V_250 -> V_252 = 0 ;
}
static void F_206 ( void )
{
int V_256 ;
F_207 (cpu) {
struct V_249 * V_250 ;
unsigned long V_21 ;
V_250 = F_208 ( & V_249 , V_256 ) ;
F_18 ( & V_250 -> V_145 , V_21 ) ;
if ( V_250 -> V_252 > 0 )
F_205 ( V_250 ) ;
F_20 ( & V_250 -> V_145 , V_21 ) ;
}
}
static void F_209 ( unsigned long V_257 )
{
F_210 ( & V_258 , 0 ) ;
F_206 () ;
}
static void F_211 ( struct V_20 * V_185 ,
unsigned long V_65 , unsigned long V_124 )
{
struct V_253 * V_4 ;
struct V_249 * V_250 ;
unsigned long V_21 ;
int V_251 ;
V_124 = F_136 ( V_124 ) ;
V_65 >>= V_188 ;
V_250 = F_212 ( & V_249 ) ;
F_18 ( & V_250 -> V_145 , V_21 ) ;
if ( V_250 -> V_252 == V_259 )
F_205 ( V_250 ) ;
V_251 = V_250 -> V_252 ++ ;
V_4 = V_250 -> V_254 + V_251 ;
V_4 -> V_255 = V_65 ;
V_4 -> V_124 = V_124 ;
V_4 -> V_185 = V_185 ;
F_20 ( & V_250 -> V_145 , V_21 ) ;
if ( F_213 ( & V_258 , 0 , 1 ) == 0 )
F_214 ( & V_260 , V_261 + F_215 ( 10 ) ) ;
F_216 ( & V_249 ) ;
}
static struct V_16 * F_217 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
if ( ! F_39 ( V_2 ) )
return F_34 ( - V_15 ) ;
V_19 = F_32 ( V_2 ) -> V_19 ;
if ( ! V_20 ( V_19 ) )
return F_34 ( - V_176 ) ;
return V_19 ;
}
static void F_218 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list) {
F_171 ( V_24 -> V_14 , V_19 , V_24 -> V_153 . V_154 ) ;
if ( V_24 -> V_14 == V_24 -> V_29 )
continue;
F_171 ( V_24 -> V_29 , V_19 , V_24 -> V_153 . V_154 ) ;
}
}
static void F_133 ( struct V_16 * V_19 )
{
if ( ! V_19 -> V_164 )
return;
F_218 ( V_19 ) ;
F_109 ( V_19 ) ;
F_107 ( V_19 ) ;
V_19 -> V_164 = false ;
}
static int F_219 ( enum V_262 V_263 )
{
if ( V_263 == V_264 )
return V_179 ;
else if ( V_263 == V_265 )
return V_181 ;
else if ( V_263 == V_266 )
return V_181 | V_179 ;
else
return 0 ;
}
static T_8 F_220 ( struct V_1 * V_2 ,
struct V_20 * V_185 ,
T_9 V_267 ,
T_6 V_122 ,
enum V_262 V_263 ,
T_3 V_49 )
{
T_8 V_268 = V_267 & ~ V_128 ;
T_8 V_65 , V_269 , V_148 ;
unsigned int V_124 ;
int V_174 = 0 ;
int V_45 ;
V_124 = F_84 ( V_267 , V_122 , V_126 ) ;
V_267 &= V_128 ;
V_65 = F_135 ( V_2 , V_185 , V_124 , V_49 ) ;
if ( V_65 == V_270 )
goto V_245;
V_174 = F_219 ( V_263 ) ;
V_269 = V_65 ;
for ( V_45 = 0 ; V_45 < V_124 ; ++ V_45 ) {
V_148 = F_129 ( & V_185 -> V_19 , V_269 , V_267 ,
V_126 , V_174 , V_271 ) ;
if ( V_148 )
goto V_272;
V_267 += V_126 ;
V_269 += V_126 ;
}
V_65 += V_268 ;
if ( F_221 ( V_273 ) ) {
F_105 ( & V_185 -> V_19 , V_65 , V_122 ) ;
F_108 ( & V_185 -> V_19 ) ;
}
V_245:
return V_65 ;
V_272:
for ( -- V_45 ; V_45 >= 0 ; -- V_45 ) {
V_269 -= V_126 ;
F_134 ( & V_185 -> V_19 , V_269 , V_126 ) ;
}
F_106 ( & V_185 -> V_19 ) ;
F_108 ( & V_185 -> V_19 ) ;
F_140 ( V_185 , V_65 , V_124 ) ;
return V_270 ;
}
static void F_222 ( struct V_20 * V_185 ,
T_8 V_274 ,
T_6 V_122 ,
int V_275 )
{
T_8 V_276 ;
T_8 V_45 , V_269 ;
unsigned int V_124 ;
V_276 = V_274 ;
V_124 = F_84 ( V_274 , V_122 , V_126 ) ;
V_274 &= V_128 ;
V_269 = V_274 ;
for ( V_45 = 0 ; V_45 < V_124 ; ++ V_45 ) {
F_134 ( & V_185 -> V_19 , V_269 , V_126 ) ;
V_269 += V_126 ;
}
if ( V_277 ) {
F_140 ( V_185 , V_274 , V_124 ) ;
F_106 ( & V_185 -> V_19 ) ;
F_108 ( & V_185 -> V_19 ) ;
} else {
F_211 ( V_185 , V_274 , V_124 ) ;
}
}
static T_8 F_223 ( struct V_1 * V_2 , struct V_169 * V_169 ,
unsigned long V_268 , T_6 V_122 ,
enum V_262 V_275 ,
unsigned long V_278 )
{
T_9 V_267 = F_224 ( V_169 ) + V_268 ;
struct V_16 * V_19 ;
struct V_20 * V_185 ;
T_3 V_49 ;
V_19 = F_217 ( V_2 ) ;
if ( F_225 ( V_19 ) == - V_15 )
return ( T_8 ) V_267 ;
else if ( F_42 ( V_19 ) )
return V_270 ;
V_49 = * V_2 -> V_49 ;
V_185 = F_14 ( V_19 ) ;
return F_220 ( V_2 , V_185 , V_267 , V_122 , V_275 , V_49 ) ;
}
static void F_226 ( struct V_1 * V_2 , T_8 V_274 , T_6 V_122 ,
enum V_262 V_275 , unsigned long V_278 )
{
struct V_16 * V_19 ;
struct V_20 * V_185 ;
V_19 = F_217 ( V_2 ) ;
if ( F_42 ( V_19 ) )
return;
V_185 = F_14 ( V_19 ) ;
F_222 ( V_185 , V_274 , V_122 , V_275 ) ;
}
static int F_227 ( struct V_1 * V_2 ,
struct V_279 * V_280 ,
int V_281 )
{
unsigned long V_282 , V_283 ;
struct V_279 * V_125 ;
int V_45 , V_284 = 0 ;
V_282 = F_228 ( V_2 ) ;
V_283 = V_282 + 1 ? F_229 ( V_282 + 1 , V_126 ) >> V_188 :
1UL << ( V_285 - V_188 ) ;
F_230 (sglist, s, nelems, i) {
int V_13 , V_286 ;
V_125 -> V_287 = V_284 << V_188 ;
V_13 = V_284 % V_283 ;
V_286 = F_84 ( F_231 ( V_125 ) , V_125 -> V_288 , V_126 ) ;
if ( V_13 + V_286 > V_283 )
V_284 += V_283 - V_13 ;
V_284 += V_286 ;
}
return V_284 ;
}
static int F_232 ( struct V_1 * V_2 , struct V_279 * V_280 ,
int V_281 , enum V_262 V_263 ,
unsigned long V_278 )
{
int V_289 = 0 , V_284 = 0 , V_174 = 0 , V_45 ;
struct V_16 * V_19 ;
struct V_20 * V_185 ;
struct V_279 * V_125 ;
unsigned long V_65 ;
T_3 V_49 ;
V_19 = F_217 ( V_2 ) ;
if ( F_42 ( V_19 ) )
return 0 ;
V_185 = F_14 ( V_19 ) ;
V_49 = * V_2 -> V_49 ;
V_284 = F_227 ( V_2 , V_280 , V_281 ) ;
V_65 = F_135 ( V_2 , V_185 , V_284 , V_49 ) ;
if ( V_65 == V_270 )
goto V_236;
V_174 = F_219 ( V_263 ) ;
F_230 (sglist, s, nelems, i) {
int V_290 , V_124 = F_84 ( F_231 ( V_125 ) , V_125 -> V_288 , V_126 ) ;
for ( V_290 = 0 ; V_290 < V_124 ; ++ V_290 ) {
unsigned long V_173 , V_58 ;
int V_148 ;
V_173 = V_65 + V_125 -> V_287 + ( V_290 << V_188 ) ;
V_58 = ( F_231 ( V_125 ) & V_128 ) + ( V_290 << V_188 ) ;
V_148 = F_129 ( V_19 , V_173 , V_58 , V_126 , V_174 , V_271 ) ;
if ( V_148 )
goto V_272;
V_289 += 1 ;
}
}
F_230 (sglist, s, nelems, i) {
V_125 -> V_287 += V_65 + V_125 -> V_268 ;
V_125 -> V_291 = V_125 -> V_288 ;
}
return V_281 ;
V_272:
F_52 ( L_27 ,
F_29 ( V_2 ) , V_284 ) ;
F_230 (sglist, s, nelems, i) {
int V_290 , V_124 = F_84 ( F_231 ( V_125 ) , V_125 -> V_288 , V_126 ) ;
for ( V_290 = 0 ; V_290 < V_124 ; ++ V_290 ) {
unsigned long V_173 ;
V_173 = V_65 + V_125 -> V_287 + ( V_290 << V_188 ) ;
F_134 ( V_19 , V_173 , V_126 ) ;
if ( -- V_289 )
goto V_292;
}
}
V_292:
F_141 ( & V_185 -> V_187 , V_65 , V_284 ) ;
V_236:
return 0 ;
}
static void F_233 ( struct V_1 * V_2 , struct V_279 * V_280 ,
int V_281 , enum V_262 V_275 ,
unsigned long V_278 )
{
struct V_16 * V_19 ;
struct V_20 * V_185 ;
unsigned long V_293 ;
int V_284 = 2 ;
V_19 = F_217 ( V_2 ) ;
if ( F_42 ( V_19 ) )
return;
V_293 = F_234 ( V_280 ) & V_128 ;
V_185 = F_14 ( V_19 ) ;
V_284 = F_227 ( V_2 , V_280 , V_281 ) ;
F_222 ( V_185 , V_293 , V_284 << V_188 , V_275 ) ;
}
static void * F_235 ( struct V_1 * V_2 , T_6 V_122 ,
T_8 * V_274 , T_7 V_294 ,
unsigned long V_278 )
{
T_3 V_49 = V_2 -> V_295 ;
struct V_16 * V_19 ;
struct V_20 * V_185 ;
struct V_169 * V_169 ;
V_19 = F_217 ( V_2 ) ;
if ( F_225 ( V_19 ) == - V_15 ) {
V_169 = F_236 ( V_294 , F_237 ( V_122 ) ) ;
* V_274 = F_224 ( V_169 ) ;
return F_238 ( V_169 ) ;
} else if ( F_42 ( V_19 ) )
return NULL ;
V_185 = F_14 ( V_19 ) ;
V_122 = F_239 ( V_122 ) ;
V_49 = V_2 -> V_295 ;
V_294 &= ~ ( V_296 | V_297 | V_298 ) ;
V_294 |= V_299 ;
V_169 = F_236 ( V_294 | V_300 , F_237 ( V_122 ) ) ;
if ( ! V_169 ) {
if ( ! F_240 ( V_294 ) )
return NULL ;
V_169 = F_241 ( V_2 , V_122 >> V_188 ,
F_237 ( V_122 ) ) ;
if ( ! V_169 )
return NULL ;
}
if ( ! V_49 )
V_49 = * V_2 -> V_49 ;
* V_274 = F_220 ( V_2 , V_185 , F_224 ( V_169 ) ,
V_122 , V_266 , V_49 ) ;
if ( * V_274 == V_270 )
goto V_301;
return F_238 ( V_169 ) ;
V_301:
if ( ! F_242 ( V_2 , V_169 , V_122 >> V_188 ) )
F_243 ( V_169 , F_237 ( V_122 ) ) ;
return NULL ;
}
static void F_244 ( struct V_1 * V_2 , T_6 V_122 ,
void * V_302 , T_8 V_274 ,
unsigned long V_278 )
{
struct V_16 * V_19 ;
struct V_20 * V_185 ;
struct V_169 * V_169 ;
V_169 = F_245 ( V_302 ) ;
V_122 = F_239 ( V_122 ) ;
V_19 = F_217 ( V_2 ) ;
if ( F_42 ( V_19 ) )
goto V_303;
V_185 = F_14 ( V_19 ) ;
F_222 ( V_185 , V_274 , V_122 , V_266 ) ;
V_303:
if ( ! F_242 ( V_2 , V_169 , V_122 >> V_188 ) )
F_243 ( V_169 , F_237 ( V_122 ) ) ;
}
static int F_246 ( struct V_1 * V_2 , T_3 V_282 )
{
return F_39 ( V_2 ) ;
}
static int F_247 ( void )
{
struct V_8 * V_9 = NULL ;
struct V_304 * V_305 ;
F_169 ( & V_210 , V_126 ,
V_208 , V_209 ) ;
F_248 ( & V_210 . V_306 ,
& V_307 ) ;
V_305 = F_249 ( & V_210 ,
F_139 ( V_308 ) , F_139 ( V_309 ) ) ;
if ( ! V_305 ) {
F_52 ( L_28 ) ;
return - V_51 ;
}
V_305 = F_249 ( & V_210 ,
F_139 ( V_310 ) , F_139 ( V_311 ) ) ;
if ( ! V_305 ) {
F_52 ( L_29 ) ;
return - V_51 ;
}
F_250 (pdev) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_312 ; ++ V_45 ) {
struct V_313 * V_314 = & V_9 -> V_313 [ V_45 ] ;
if ( ! ( V_314 -> V_21 & V_315 ) )
continue;
V_305 = F_249 ( & V_210 ,
F_139 ( V_314 -> V_269 ) ,
F_139 ( V_314 -> V_316 ) ) ;
if ( ! V_305 ) {
F_52 ( L_30 ) ;
return - V_51 ;
}
}
}
return 0 ;
}
int T_10 F_251 ( void )
{
int V_148 , V_256 , V_317 = 0 ;
V_148 = F_252 () ;
if ( V_148 )
return V_148 ;
V_148 = F_247 () ;
if ( V_148 )
return V_148 ;
F_207 (cpu) {
struct V_249 * V_250 = F_208 ( & V_249 , V_256 ) ;
V_250 -> V_254 = F_17 ( V_259 *
sizeof( * V_250 -> V_254 ) ,
V_25 ) ;
if ( ! V_250 -> V_254 )
goto V_318;
F_253 ( & V_250 -> V_145 ) ;
}
V_317 = F_254 ( & V_319 , & V_320 ) ;
if ( V_317 )
return V_317 ;
#ifdef F_255
V_317 = F_254 ( & V_321 , & V_320 ) ;
if ( V_317 )
return V_317 ;
#endif
V_317 = F_254 ( & V_322 , & V_320 ) ;
if ( V_317 )
return V_317 ;
return 0 ;
V_318:
F_207 (cpu) {
struct V_249 * V_250 = F_208 ( & V_249 , V_256 ) ;
F_166 ( V_250 -> V_254 ) ;
}
return - V_51 ;
}
int T_10 F_256 ( void )
{
F_257 ( & V_260 , F_209 , 0 ) ;
F_210 ( & V_258 , 0 ) ;
V_323 = V_246 ? 1 : 0 ;
V_324 = 1 ;
if ( ! V_323 )
V_57 = & V_244 ;
if ( V_277 )
F_25 ( L_31 ) ;
else
F_25 ( L_32 ) ;
return 0 ;
}
static void F_258 ( struct V_16 * V_19 )
{
struct V_23 * V_4 ;
unsigned long V_21 ;
F_147 ( & V_192 , V_21 ) ;
while ( ! F_259 ( & V_19 -> V_226 ) ) {
V_4 = F_260 ( & V_19 -> V_226 ,
struct V_23 , V_190 ) ;
F_198 ( V_4 ) ;
}
F_150 ( & V_192 , V_21 ) ;
}
static void F_261 ( struct V_16 * V_19 )
{
if ( ! V_19 )
return;
F_144 ( V_19 ) ;
if ( V_19 -> V_155 )
F_151 ( V_19 -> V_155 ) ;
F_166 ( V_19 ) ;
}
static int F_168 ( struct V_16 * V_19 )
{
F_253 ( & V_19 -> V_145 ) ;
F_262 ( & V_19 -> V_325 ) ;
V_19 -> V_155 = F_146 () ;
if ( ! V_19 -> V_155 )
return - V_51 ;
F_263 ( & V_19 -> V_226 ) ;
return 0 ;
}
static struct V_16 * F_264 ( void )
{
struct V_16 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_25 ) ;
if ( ! V_19 )
return NULL ;
if ( F_168 ( V_19 ) )
goto V_236;
F_142 ( V_19 ) ;
return V_19 ;
V_236:
F_166 ( V_19 ) ;
return NULL ;
}
static struct V_17 * F_265 ( unsigned type )
{
struct V_16 * V_326 ;
struct V_20 * V_327 ;
switch ( type ) {
case V_328 :
V_326 = F_264 () ;
if ( ! V_326 )
return NULL ;
V_326 -> V_161 = V_199 ;
V_326 -> V_163 = ( void * ) F_111 ( V_25 ) ;
if ( ! V_326 -> V_163 ) {
F_261 ( V_326 ) ;
return NULL ;
}
V_326 -> V_19 . V_329 . V_330 = 0 ;
V_326 -> V_19 . V_329 . V_331 = ~ 0ULL ;
V_326 -> V_19 . V_329 . V_332 = true ;
break;
case V_333 :
V_327 = F_167 () ;
if ( ! V_327 ) {
F_52 ( L_33 ) ;
return NULL ;
}
V_326 = & V_327 -> V_19 ;
break;
case V_247 :
V_326 = F_264 () ;
if ( ! V_326 )
return NULL ;
V_326 -> V_161 = V_196 ;
break;
default:
return NULL ;
}
return & V_326 -> V_19 ;
}
static void F_266 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
struct V_20 * V_185 ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 -> V_228 > 0 )
F_258 ( V_19 ) ;
F_15 ( V_19 -> V_228 != 0 ) ;
if ( ! V_18 )
return;
switch ( V_18 -> type ) {
case V_333 :
F_206 () ;
V_185 = F_14 ( V_19 ) ;
F_164 ( V_185 ) ;
break;
default:
if ( V_19 -> V_161 != V_196 )
F_153 ( V_19 ) ;
if ( V_19 -> V_21 & V_216 )
F_163 ( V_19 ) ;
F_261 ( V_19 ) ;
break;
}
}
static void F_267 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_37 . V_38 ;
struct V_52 * V_38 ;
int V_14 ;
if ( ! F_39 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
if ( V_24 -> V_19 != NULL )
F_48 ( V_2 ) ;
V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
return;
F_93 ( V_38 ) ;
}
static int F_268 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
struct V_23 * V_24 ;
struct V_52 * V_38 ;
int V_148 ;
if ( ! F_39 ( V_2 ) )
return - V_15 ;
V_24 = V_2 -> V_37 . V_38 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
if ( ! V_38 )
return - V_15 ;
if ( V_24 -> V_19 )
F_48 ( V_2 ) ;
V_148 = F_196 ( V_2 , V_19 ) ;
F_93 ( V_38 ) ;
return V_148 ;
}
static int F_269 ( struct V_17 * V_18 , unsigned long V_304 ,
T_9 V_267 , T_6 V_165 , int V_334 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
int V_174 = 0 ;
int V_148 ;
if ( V_19 -> V_161 == V_196 )
return - V_15 ;
if ( V_334 & V_335 )
V_174 |= V_179 ;
if ( V_334 & V_336 )
V_174 |= V_181 ;
F_270 ( & V_19 -> V_325 ) ;
V_148 = F_129 ( V_19 , V_304 , V_267 , V_165 , V_174 , V_25 ) ;
F_271 ( & V_19 -> V_325 ) ;
return V_148 ;
}
static T_6 F_272 ( struct V_17 * V_18 , unsigned long V_304 ,
T_6 V_165 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
T_6 V_184 ;
if ( V_19 -> V_161 == V_196 )
return - V_15 ;
F_270 ( & V_19 -> V_325 ) ;
V_184 = F_134 ( V_19 , V_304 , V_165 ) ;
F_271 ( & V_19 -> V_325 ) ;
F_107 ( V_19 ) ;
return V_184 ;
}
static T_9 F_273 ( struct V_17 * V_18 ,
T_8 V_304 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_337 , V_338 ;
T_3 * V_160 , V_170 ;
if ( V_19 -> V_161 == V_196 )
return V_304 ;
V_160 = F_125 ( V_19 , V_304 , & V_338 ) ;
if ( ! V_160 || ! F_120 ( * V_160 ) )
return 0 ;
V_337 = V_338 - 1 ;
V_170 = * V_160 & V_339 ;
return ( V_170 & ~ V_337 ) | ( V_304 & V_337 ) ;
}
static bool F_274 ( enum V_340 V_341 )
{
switch ( V_341 ) {
case V_342 :
return true ;
case V_343 :
return ( V_344 == 1 ) ;
case V_345 :
return false ;
}
return false ;
}
static void F_275 ( struct V_1 * V_2 ,
struct V_346 * V_85 )
{
struct V_347 * V_4 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
F_9 (entry, &amd_iommu_unity_map, list) {
struct V_348 * V_349 ;
if ( V_14 < V_4 -> V_350 || V_14 > V_4 -> V_351 )
continue;
V_349 = F_17 ( sizeof( * V_349 ) , V_25 ) ;
if ( ! V_349 ) {
F_52 ( L_34 ,
F_29 ( V_2 ) ) ;
return;
}
V_349 -> V_269 = V_4 -> V_352 ;
V_349 -> V_288 = V_4 -> V_353 - V_4 -> V_352 ;
if ( V_4 -> V_174 & V_179 )
V_349 -> V_174 |= V_335 ;
if ( V_4 -> V_174 & V_181 )
V_349 -> V_174 |= V_336 ;
F_19 ( & V_349 -> V_190 , V_85 ) ;
}
}
static void F_276 ( struct V_1 * V_2 ,
struct V_346 * V_85 )
{
struct V_348 * V_4 , * V_252 ;
F_277 (entry, next, head, list)
F_166 ( V_4 ) ;
}
static void F_278 ( struct V_1 * V_2 ,
struct V_17 * V_19 ,
struct V_348 * V_349 )
{
struct V_20 * V_185 = F_14 ( F_12 ( V_19 ) ) ;
unsigned long V_269 , V_316 ;
V_269 = F_139 ( V_349 -> V_269 ) ;
V_316 = F_139 ( V_349 -> V_269 + V_349 -> V_288 ) ;
F_279 ( F_249 ( & V_185 -> V_187 , V_269 , V_316 ) == NULL ) ;
}
int F_280 ( struct V_354 * V_355 )
{
return F_281 ( & V_100 , V_355 ) ;
}
int F_282 ( struct V_354 * V_355 )
{
return F_283 ( & V_100 , V_355 ) ;
}
void F_284 ( struct V_17 * V_18 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
F_18 ( & V_19 -> V_145 , V_21 ) ;
V_19 -> V_161 = V_196 ;
V_19 -> V_164 = true ;
F_133 ( V_19 ) ;
F_153 ( V_19 ) ;
F_20 ( & V_19 -> V_145 , V_21 ) ;
}
int F_285 ( struct V_17 * V_18 , int V_356 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_357 , V_148 ;
if ( V_356 <= 0 || V_356 > ( V_358 + 1 ) )
return - V_15 ;
for ( V_357 = 0 ; ( V_356 - 1 ) & ~ 0x1ff ; V_356 >>= 9 )
V_357 += 1 ;
if ( V_357 > V_359 )
return - V_15 ;
F_18 ( & V_19 -> V_145 , V_21 ) ;
V_148 = - V_176 ;
if ( V_19 -> V_228 > 0 || V_19 -> V_21 & V_216 )
goto V_245;
V_148 = - V_51 ;
V_19 -> V_206 = ( void * ) F_111 ( V_271 ) ;
if ( V_19 -> V_206 == NULL )
goto V_245;
V_19 -> V_205 = V_357 ;
V_19 -> V_21 |= V_216 ;
V_19 -> V_164 = true ;
F_133 ( V_19 ) ;
V_148 = 0 ;
V_245:
F_20 ( & V_19 -> V_145 , V_21 ) ;
return V_148 ;
}
static int F_286 ( struct V_16 * V_19 , int V_97 ,
T_3 V_65 , bool V_122 )
{
struct V_23 * V_24 ;
struct V_59 V_60 ;
int V_45 , V_148 ;
if ( ! ( V_19 -> V_21 & V_216 ) )
return - V_15 ;
F_86 ( & V_60 , V_19 -> V_155 , V_97 , V_65 , V_122 ) ;
for ( V_45 = 0 ; V_45 < V_156 ; ++ V_45 ) {
if ( V_19 -> V_157 [ V_45 ] == 0 )
continue;
V_148 = F_92 ( V_158 [ V_45 ] , & V_60 ) ;
if ( V_148 != 0 )
goto V_245;
}
F_108 ( V_19 ) ;
F_9 (dev_data, &domain->dev_list, list) {
struct V_52 * V_38 ;
int V_132 ;
if ( ! V_24 -> V_153 . V_154 )
continue;
V_132 = V_24 -> V_153 . V_132 ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_87 ( & V_60 , V_24 -> V_14 , V_97 ,
V_132 , V_65 , V_122 ) ;
V_148 = F_92 ( V_38 , & V_60 ) ;
if ( V_148 != 0 )
goto V_245;
}
F_108 ( V_19 ) ;
V_148 = 0 ;
V_245:
return V_148 ;
}
static int F_287 ( struct V_16 * V_19 , int V_97 ,
T_3 V_65 )
{
return F_286 ( V_19 , V_97 , V_65 , false ) ;
}
int F_288 ( struct V_17 * V_18 , int V_97 ,
T_3 V_65 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_148 ;
F_18 ( & V_19 -> V_145 , V_21 ) ;
V_148 = F_287 ( V_19 , V_97 , V_65 ) ;
F_20 ( & V_19 -> V_145 , V_21 ) ;
return V_148 ;
}
static int F_289 ( struct V_16 * V_19 , int V_97 )
{
return F_286 ( V_19 , V_97 , V_127 ,
true ) ;
}
int F_290 ( struct V_17 * V_18 , int V_97 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_148 ;
F_18 ( & V_19 -> V_145 , V_21 ) ;
V_148 = F_289 ( V_19 , V_97 ) ;
F_20 ( & V_19 -> V_145 , V_21 ) ;
return V_148 ;
}
static T_3 * F_291 ( T_3 * V_195 , int V_167 , int V_97 , bool V_360 )
{
int V_227 ;
T_3 * V_160 ;
while ( true ) {
V_227 = ( V_97 >> ( 9 * V_167 ) ) & 0x1ff ;
V_160 = & V_195 [ V_227 ] ;
if ( V_167 == 0 )
break;
if ( ! ( * V_160 & V_204 ) ) {
if ( ! V_360 )
return NULL ;
V_195 = ( void * ) F_111 ( V_271 ) ;
if ( V_195 == NULL )
return NULL ;
* V_160 = F_79 ( V_195 ) | V_204 ;
}
V_195 = F_161 ( * V_160 & V_128 ) ;
V_167 -= 1 ;
}
return V_160 ;
}
static int F_292 ( struct V_16 * V_19 , int V_97 ,
unsigned long V_361 )
{
T_3 * V_160 ;
if ( V_19 -> V_161 != V_196 )
return - V_15 ;
V_160 = F_291 ( V_19 -> V_206 , V_19 -> V_205 , V_97 , true ) ;
if ( V_160 == NULL )
return - V_51 ;
* V_160 = ( V_361 & V_128 ) | V_204 ;
return F_289 ( V_19 , V_97 ) ;
}
static int F_293 ( struct V_16 * V_19 , int V_97 )
{
T_3 * V_160 ;
if ( V_19 -> V_161 != V_196 )
return - V_15 ;
V_160 = F_291 ( V_19 -> V_206 , V_19 -> V_205 , V_97 , false ) ;
if ( V_160 == NULL )
return 0 ;
* V_160 = 0 ;
return F_289 ( V_19 , V_97 ) ;
}
int F_294 ( struct V_17 * V_18 , int V_97 ,
unsigned long V_361 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_148 ;
F_18 ( & V_19 -> V_145 , V_21 ) ;
V_148 = F_292 ( V_19 , V_97 , V_361 ) ;
F_20 ( & V_19 -> V_145 , V_21 ) ;
return V_148 ;
}
int F_295 ( struct V_17 * V_18 , int V_97 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_148 ;
F_18 ( & V_19 -> V_145 , V_21 ) ;
V_148 = F_293 ( V_19 , V_97 ) ;
F_20 ( & V_19 -> V_145 , V_21 ) ;
return V_148 ;
}
int F_296 ( struct V_8 * V_9 , int V_97 ,
int V_107 , int V_99 )
{
struct V_23 * V_24 ;
struct V_52 * V_38 ;
struct V_59 V_60 ;
V_24 = F_32 ( & V_9 -> V_2 ) ;
V_38 = V_34 [ V_24 -> V_14 ] ;
F_88 ( & V_60 , V_24 -> V_14 , V_97 , V_107 ,
V_99 , V_24 -> V_241 ) ;
return F_92 ( V_38 , & V_60 ) ;
}
struct V_17 * F_297 ( struct V_8 * V_9 )
{
struct V_16 * V_326 ;
V_326 = F_217 ( & V_9 -> V_2 ) ;
if ( F_42 ( V_326 ) )
return NULL ;
if ( ! ( V_326 -> V_21 & V_216 ) )
return NULL ;
return & V_326 -> V_19 ;
}
void F_298 ( struct V_8 * V_9 , T_2 V_47 )
{
struct V_23 * V_24 ;
if ( ! F_299 () )
return;
V_24 = F_32 ( & V_9 -> V_2 ) ;
V_24 -> V_48 |= ( 1 << V_47 ) ;
}
int F_300 ( struct V_8 * V_9 ,
struct F_300 * V_362 )
{
int V_363 ;
int V_46 ;
if ( V_9 == NULL || V_362 == NULL )
return - V_15 ;
if ( ! F_299 () )
return - V_15 ;
memset ( V_362 , 0 , sizeof( * V_362 ) ) ;
V_46 = F_37 ( V_9 , V_42 ) ;
if ( V_46 )
V_362 -> V_21 |= V_364 ;
V_46 = F_37 ( V_9 , V_43 ) ;
if ( V_46 )
V_362 -> V_21 |= V_365 ;
V_46 = F_37 ( V_9 , V_44 ) ;
if ( V_46 ) {
int V_366 ;
V_363 = 1 << ( 9 * ( V_359 + 1 ) ) ;
V_363 = F_301 ( V_363 , ( 1 << 20 ) ) ;
V_362 -> V_21 |= V_367 ;
V_362 -> V_363 = F_301 ( F_302 ( V_9 ) , V_363 ) ;
V_366 = F_303 ( V_9 ) ;
if ( V_366 & V_368 )
V_362 -> V_21 |= V_369 ;
if ( V_366 & V_370 )
V_362 -> V_21 |= V_371 ;
}
return 0 ;
}
static void F_304 ( T_1 V_14 , struct V_372 * V_373 )
{
T_3 V_374 ;
V_374 = V_35 [ V_14 ] . V_30 [ 2 ] ;
V_374 &= ~ V_375 ;
V_374 |= F_113 ( V_373 -> V_373 ) ;
V_374 |= V_376 ;
V_374 |= V_377 ;
V_374 |= V_378 ;
V_35 [ V_14 ] . V_30 [ 2 ] = V_374 ;
}
static struct V_372 * F_305 ( T_1 V_14 , bool V_379 )
{
struct V_372 * V_373 = NULL ;
struct V_52 * V_38 ;
unsigned long V_21 ;
T_1 V_29 ;
F_147 ( & V_192 , V_21 ) ;
V_38 = V_34 [ V_14 ] ;
if ( ! V_38 )
goto V_28;
V_373 = V_380 [ V_14 ] ;
if ( V_373 )
goto V_245;
V_29 = V_33 [ V_14 ] ;
V_373 = V_380 [ V_29 ] ;
if ( V_373 ) {
V_380 [ V_14 ] = V_373 ;
F_304 ( V_14 , V_373 ) ;
F_94 ( V_38 , V_14 ) ;
goto V_245;
}
V_373 = F_17 ( sizeof( * V_373 ) , V_271 ) ;
if ( ! V_373 )
goto V_245;
F_253 ( & V_373 -> V_145 ) ;
if ( V_379 )
V_373 -> V_381 = 32 ;
V_373 -> V_373 = F_306 ( V_382 , V_271 ) ;
if ( ! V_373 -> V_373 ) {
F_166 ( V_373 ) ;
V_373 = NULL ;
goto V_245;
}
memset ( V_373 -> V_373 , 0 , V_383 * sizeof( T_2 ) ) ;
if ( V_379 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < 32 ; ++ V_45 )
V_373 -> V_373 [ V_45 ] = V_384 ;
}
V_380 [ V_14 ] = V_373 ;
F_304 ( V_14 , V_373 ) ;
F_94 ( V_38 , V_14 ) ;
if ( V_14 != V_29 ) {
V_380 [ V_29 ] = V_373 ;
F_304 ( V_29 , V_373 ) ;
F_94 ( V_38 , V_29 ) ;
}
V_245:
F_93 ( V_38 ) ;
V_28:
F_150 ( & V_192 , V_21 ) ;
return V_373 ;
}
static int F_307 ( T_1 V_14 , int V_64 )
{
struct V_372 * V_373 ;
unsigned long V_21 ;
int V_227 , V_385 ;
V_373 = F_305 ( V_14 , false ) ;
if ( ! V_373 )
return - V_7 ;
F_18 ( & V_373 -> V_145 , V_21 ) ;
for ( V_385 = 0 , V_227 = V_373 -> V_381 ;
V_227 < V_383 ;
++ V_227 ) {
if ( V_373 -> V_373 [ V_227 ] == 0 )
V_385 += 1 ;
else
V_385 = 0 ;
if ( V_385 == V_64 ) {
for (; V_385 != 0 ; -- V_385 )
V_373 -> V_373 [ V_227 - V_385 + 1 ] = V_384 ;
V_227 -= V_64 - 1 ;
goto V_245;
}
}
V_227 = - V_386 ;
V_245:
F_20 ( & V_373 -> V_145 , V_21 ) ;
return V_227 ;
}
static int F_308 ( T_1 V_14 , int V_227 , union V_387 V_387 )
{
struct V_372 * V_373 ;
struct V_52 * V_38 ;
unsigned long V_21 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return - V_15 ;
V_373 = F_305 ( V_14 , false ) ;
if ( ! V_373 )
return - V_51 ;
F_18 ( & V_373 -> V_145 , V_21 ) ;
V_373 -> V_373 [ V_227 ] = V_387 . V_305 ;
F_20 ( & V_373 -> V_145 , V_21 ) ;
F_98 ( V_38 , V_14 ) ;
F_93 ( V_38 ) ;
return 0 ;
}
static void F_309 ( T_1 V_14 , int V_227 )
{
struct V_372 * V_373 ;
struct V_52 * V_38 ;
unsigned long V_21 ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 == NULL )
return;
V_373 = F_305 ( V_14 , false ) ;
if ( ! V_373 )
return;
F_18 ( & V_373 -> V_145 , V_21 ) ;
V_373 -> V_373 [ V_227 ] = 0 ;
F_20 ( & V_373 -> V_145 , V_21 ) ;
F_98 ( V_38 , V_14 ) ;
F_93 ( V_38 ) ;
}
static int F_310 ( struct V_388 * V_362 )
{
int V_14 = - 1 ;
switch ( V_362 -> type ) {
case V_389 :
V_14 = F_311 ( V_362 -> V_390 ) ;
break;
case V_391 :
V_14 = F_312 ( V_362 -> V_392 ) ;
break;
case V_393 :
case V_394 :
V_14 = F_10 ( & V_362 -> V_395 -> V_2 ) ;
break;
default:
F_15 ( 1 ) ;
break;
}
return V_14 ;
}
static struct V_396 * F_313 ( struct V_388 * V_362 )
{
struct V_52 * V_38 ;
int V_14 ;
if ( ! V_362 )
return NULL ;
V_14 = F_310 ( V_362 ) ;
if ( V_14 >= 0 ) {
V_38 = V_34 [ V_14 ] ;
if ( V_38 )
return V_38 -> V_397 ;
}
return NULL ;
}
static struct V_396 * F_314 ( struct V_388 * V_362 )
{
struct V_52 * V_38 ;
int V_14 ;
if ( ! V_362 )
return NULL ;
switch ( V_362 -> type ) {
case V_393 :
case V_394 :
V_14 = F_10 ( & V_362 -> V_395 -> V_2 ) ;
if ( V_14 < 0 )
return NULL ;
V_38 = V_34 [ V_14 ] ;
if ( V_38 )
return V_38 -> V_398 ;
break;
default:
break;
}
return NULL ;
}
static void F_315 ( struct V_399 * V_30 ,
struct V_400 * V_400 ,
struct V_388 * V_362 ,
int V_14 , int V_227 , int V_401 )
{
struct V_402 * V_403 = & V_30 -> V_402 ;
struct V_404 * V_405 = & V_30 -> V_406 ;
union V_387 * V_387 = & V_30 -> V_407 ;
struct V_408 * V_4 ;
V_30 -> V_402 . V_14 = V_14 ;
V_30 -> V_402 . V_227 = V_227 + V_401 ;
V_387 -> V_305 = 0 ;
V_387 -> V_409 . V_410 = V_400 -> V_410 ;
V_387 -> V_409 . V_411 = V_412 -> V_413 ;
V_387 -> V_409 . V_414 = V_400 -> V_415 ;
V_387 -> V_409 . V_416 = V_412 -> V_417 ;
V_387 -> V_409 . V_418 = 1 ;
switch ( V_362 -> type ) {
case V_389 :
V_4 = V_362 -> V_419 ;
V_362 -> V_419 = NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_410 = V_227 ;
V_4 -> V_282 = 0 ;
V_4 -> V_420 = V_362 -> V_421 ;
V_4 -> V_422 = V_362 -> V_423 ;
if ( V_362 -> V_421 )
V_4 -> V_282 = 1 ;
break;
case V_391 :
case V_393 :
case V_394 :
V_405 -> V_424 = V_425 ;
V_405 -> V_426 = V_427 ;
V_405 -> V_30 = V_403 -> V_227 ;
break;
default:
F_15 ( 1 ) ;
break;
}
}
static int F_316 ( struct V_396 * V_19 , unsigned int V_428 ,
unsigned int V_429 , void * V_430 )
{
struct V_388 * V_362 = V_430 ;
struct V_431 * V_431 ;
struct V_399 * V_30 ;
struct V_400 * V_432 ;
int V_45 , V_148 , V_14 ;
int V_227 = - 1 ;
if ( ! V_362 )
return - V_15 ;
if ( V_429 > 1 && V_362 -> type != V_393 &&
V_362 -> type != V_394 )
return - V_15 ;
if ( V_362 -> type == V_393 )
V_362 -> V_21 &= ~ V_433 ;
V_14 = F_310 ( V_362 ) ;
if ( V_14 < 0 )
return - V_15 ;
V_148 = F_317 ( V_19 , V_428 , V_429 , V_430 ) ;
if ( V_148 < 0 )
return V_148 ;
if ( V_362 -> type == V_389 ) {
if ( F_305 ( V_14 , true ) )
V_227 = V_362 -> V_434 ;
else
V_148 = - V_51 ;
} else {
V_227 = F_307 ( V_14 , V_429 ) ;
}
if ( V_227 < 0 ) {
F_318 ( L_35 ) ;
goto V_435;
}
for ( V_45 = 0 ; V_45 < V_429 ; V_45 ++ ) {
V_431 = F_319 ( V_19 , V_428 + V_45 ) ;
V_432 = F_320 ( V_431 ) ;
if ( ! V_431 || ! V_432 ) {
V_148 = - V_15 ;
goto V_436;
}
V_148 = - V_51 ;
V_30 = F_17 ( sizeof( * V_30 ) , V_25 ) ;
if ( ! V_30 )
goto V_436;
V_431 -> V_437 = ( V_14 << 16 ) + V_45 ;
V_431 -> V_438 = V_30 ;
V_431 -> V_439 = & V_440 ;
F_315 ( V_30 , V_432 , V_362 , V_14 , V_227 , V_45 ) ;
F_321 ( V_428 + V_45 , V_441 ) ;
}
return 0 ;
V_436:
for ( V_45 -- ; V_45 >= 0 ; V_45 -- ) {
V_431 = F_319 ( V_19 , V_428 + V_45 ) ;
if ( V_431 )
F_166 ( V_431 -> V_438 ) ;
}
for ( V_45 = 0 ; V_45 < V_429 ; V_45 ++ )
F_309 ( V_14 , V_227 + V_45 ) ;
V_435:
F_322 ( V_19 , V_428 , V_429 ) ;
return V_148 ;
}
static void F_323 ( struct V_396 * V_19 , unsigned int V_428 ,
unsigned int V_429 )
{
struct V_402 * V_403 ;
struct V_431 * V_431 ;
struct V_399 * V_30 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_429 ; V_45 ++ ) {
V_431 = F_319 ( V_19 , V_428 + V_45 ) ;
if ( V_431 && V_431 -> V_438 ) {
V_30 = V_431 -> V_438 ;
V_403 = & V_30 -> V_402 ;
F_309 ( V_403 -> V_14 , V_403 -> V_227 ) ;
F_166 ( V_30 ) ;
}
}
F_322 ( V_19 , V_428 , V_429 ) ;
}
static void F_324 ( struct V_396 * V_19 ,
struct V_431 * V_431 )
{
struct V_399 * V_30 = V_431 -> V_438 ;
struct V_402 * V_403 = & V_30 -> V_402 ;
F_308 ( V_403 -> V_14 , V_403 -> V_227 , V_30 -> V_407 ) ;
}
static void F_325 ( struct V_396 * V_19 ,
struct V_431 * V_431 )
{
struct V_399 * V_30 = V_431 -> V_438 ;
struct V_402 * V_403 = & V_30 -> V_402 ;
union V_387 V_4 ;
V_4 . V_305 = 0 ;
F_308 ( V_403 -> V_14 , V_403 -> V_227 , V_30 -> V_407 ) ;
}
static int F_326 ( struct V_431 * V_30 ,
const struct V_442 * V_282 , bool V_443 )
{
struct V_399 * V_444 = V_30 -> V_438 ;
struct V_402 * V_403 = & V_444 -> V_402 ;
struct V_400 * V_432 = F_320 ( V_30 ) ;
struct V_431 * V_445 = V_30 -> V_446 ;
int V_148 ;
V_148 = V_445 -> V_439 -> V_447 ( V_445 , V_282 , V_443 ) ;
if ( V_148 < 0 || V_148 == V_448 )
return V_148 ;
V_444 -> V_407 . V_409 . V_410 = V_432 -> V_410 ;
V_444 -> V_407 . V_409 . V_414 = V_432 -> V_415 ;
F_308 ( V_403 -> V_14 , V_403 -> V_227 , V_444 -> V_407 ) ;
F_327 ( V_432 ) ;
return V_448 ;
}
static void F_328 ( struct V_431 * V_431 , struct V_404 * V_405 )
{
struct V_399 * V_444 = V_431 -> V_438 ;
* V_405 = V_444 -> V_406 ;
}
int F_329 ( struct V_52 * V_38 )
{
V_38 -> V_397 = F_330 ( NULL , & V_449 , V_38 ) ;
if ( ! V_38 -> V_397 )
return - V_51 ;
V_38 -> V_397 -> V_445 = F_331 () ;
V_38 -> V_398 = F_332 ( V_38 -> V_397 ) ;
return 0 ;
}
