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
struct V_38 * V_39 = V_35 [ V_14 ] ;
V_24 = F_22 ( V_14 ) ;
if ( V_24 == NULL ) {
V_24 = F_16 ( V_14 ) ;
if ( F_33 ( V_39 ) )
V_24 -> V_40 = true ;
}
return V_24 ;
}
struct V_23 * F_34 ( struct V_1 * V_2 )
{
return V_2 -> V_41 . V_39 ;
}
static struct V_42 * F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_13 , * V_4 = NULL ;
int V_14 ;
V_14 = F_8 ( V_2 , & V_4 ) ;
if ( V_14 < 0 )
return F_36 ( V_14 ) ;
F_9 (p, &acpihid_map, list) {
if ( ( V_14 == V_13 -> V_14 ) && V_13 -> V_43 )
V_4 -> V_43 = V_13 -> V_43 ;
}
if ( ! V_4 -> V_43 )
V_4 -> V_43 = F_37 ( V_2 ) ;
else
F_38 ( V_4 -> V_43 ) ;
return V_4 -> V_43 ;
}
static bool F_39 ( struct V_8 * V_9 )
{
static const int V_44 [] = {
V_45 ,
V_46 ,
V_47 ,
} ;
int V_48 , V_49 ;
for ( V_48 = 0 ; V_48 < 3 ; ++ V_48 ) {
V_49 = F_40 ( V_9 , V_44 [ V_48 ] ) ;
if ( V_49 == 0 )
return false ;
}
return true ;
}
static bool F_41 ( struct V_8 * V_9 , T_2 V_50 )
{
struct V_23 * V_24 ;
V_24 = F_34 ( & V_9 -> V_2 ) ;
return V_24 -> V_51 & ( 1 << V_50 ) ? true : false ;
}
static bool F_42 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ! V_2 || ! V_2 -> V_52 )
return false ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return false ;
if ( V_14 > V_53 )
return false ;
if ( V_35 [ V_14 ] == NULL )
return false ;
return true ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
V_43 = F_44 ( V_2 ) ;
if ( F_45 ( V_43 ) )
return;
F_46 ( V_43 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_38 * V_39 ;
int V_14 ;
if ( V_2 -> V_41 . V_39 )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_39 = V_35 [ V_14 ] ;
V_24 = F_32 ( V_14 ) ;
if ( ! V_24 )
return - V_54 ;
V_24 -> V_30 = F_24 ( V_2 ) ;
if ( F_11 ( V_2 ) && F_39 ( F_6 ( V_2 ) ) ) {
struct V_38 * V_39 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
V_24 -> V_55 = V_39 -> V_56 ;
}
V_2 -> V_41 . V_39 = V_24 ;
F_48 ( & V_39 -> V_39 , V_2 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
T_1 V_30 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_30 = F_24 ( V_2 ) ;
memset ( & V_36 [ V_14 ] , 0 , sizeof( struct V_57 ) ) ;
memset ( & V_36 [ V_30 ] , 0 , sizeof( struct V_57 ) ) ;
V_35 [ V_14 ] = NULL ;
V_35 [ V_30 ] = NULL ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_38 * V_39 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_39 = V_35 [ V_14 ] ;
V_24 = F_22 ( V_14 ) ;
if ( ! V_24 )
return;
if ( V_24 -> V_19 )
F_51 ( V_2 ) ;
F_52 ( & V_39 -> V_39 , V_2 ) ;
F_53 ( V_2 ) ;
V_2 -> V_58 = NULL ;
}
static void F_54 ( T_1 V_14 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < 4 ; ++ V_48 )
F_55 ( L_5 , V_48 ,
V_36 [ V_14 ] . V_31 [ V_48 ] ) ;
}
static void F_56 ( unsigned long V_59 )
{
struct V_60 * V_61 = F_57 ( V_59 ) ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 4 ; ++ V_48 )
F_55 ( L_6 , V_48 , V_61 -> V_31 [ V_48 ] ) ;
}
static void F_58 ( T_1 V_14 , T_1 V_62 ,
T_3 V_63 , int V_21 )
{
struct V_23 * V_24 = NULL ;
struct V_8 * V_9 ;
V_9 = F_59 ( F_27 ( V_14 ) , V_14 & 0xff ) ;
if ( V_9 )
V_24 = F_34 ( & V_9 -> V_2 ) ;
if ( V_24 && F_60 ( & V_24 -> V_28 ) ) {
F_61 ( & V_9 -> V_2 , L_7 ,
V_62 , V_63 , V_21 ) ;
} else if ( F_62 () ) {
F_55 ( L_8 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_62 , V_63 , V_21 ) ;
}
if ( V_9 )
F_63 ( V_9 ) ;
}
static void F_64 ( struct V_38 * V_39 , void * V_64 )
{
int type , V_14 , V_65 , V_21 ;
volatile T_2 * V_66 = V_64 ;
int V_67 = 0 ;
T_3 V_63 ;
V_68:
type = ( V_66 [ 1 ] >> V_69 ) & V_70 ;
V_14 = ( V_66 [ 0 ] >> V_71 ) & V_72 ;
V_65 = ( V_66 [ 1 ] >> V_73 ) & V_74 ;
V_21 = ( V_66 [ 1 ] >> V_75 ) & V_76 ;
V_63 = ( T_3 ) ( ( ( T_3 ) V_66 [ 3 ] ) << 32 ) | V_66 [ 2 ] ;
if ( type == 0 ) {
if ( ++ V_67 == V_77 ) {
F_55 ( L_9 ) ;
return;
}
F_65 ( 1 ) ;
goto V_68;
}
if ( type == V_78 ) {
F_58 ( V_14 , V_65 , V_63 , V_21 ) ;
return;
} else {
F_66 ( V_79 L_10 ) ;
}
switch ( type ) {
case V_80 :
F_66 ( L_11
L_12 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_63 , V_21 ) ;
F_54 ( V_14 ) ;
break;
case V_81 :
F_66 ( L_13
L_12 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_63 , V_21 ) ;
break;
case V_82 :
F_66 ( L_14
L_15 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_65 , V_63 , V_21 ) ;
break;
case V_83 :
F_66 ( L_16 , V_63 ) ;
F_56 ( V_63 ) ;
break;
case V_84 :
F_66 ( L_17
L_18 , V_63 , V_21 ) ;
break;
case V_85 :
F_66 ( L_19
L_20 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_63 ) ;
break;
case V_86 :
F_66 ( L_21
L_12 ,
F_27 ( V_14 ) , F_28 ( V_14 ) , F_29 ( V_14 ) ,
V_63 , V_21 ) ;
break;
default:
F_66 ( V_79 L_22 , type ) ;
}
memset ( V_64 , 0 , 4 * sizeof( T_2 ) ) ;
}
static void F_67 ( struct V_38 * V_39 )
{
T_2 V_87 , V_88 ;
V_87 = F_68 ( V_39 -> V_89 + V_90 ) ;
V_88 = F_68 ( V_39 -> V_89 + V_91 ) ;
while ( V_87 != V_88 ) {
F_64 ( V_39 , V_39 -> V_92 + V_87 ) ;
V_87 = ( V_87 + V_93 ) % V_94 ;
}
F_69 ( V_87 , V_39 -> V_89 + V_90 ) ;
}
static void F_70 ( struct V_38 * V_39 , T_3 * V_95 )
{
struct V_96 V_97 ;
if ( F_71 ( V_95 [ 0 ] ) != V_98 ) {
F_72 ( L_23 ) ;
return;
}
V_97 . V_63 = V_95 [ 1 ] ;
V_97 . V_99 = F_73 ( V_95 [ 0 ] ) ;
V_97 . V_100 = F_74 ( V_95 [ 0 ] ) ;
V_97 . V_101 = F_75 ( V_95 [ 0 ] ) ;
V_97 . V_21 = F_76 ( V_95 [ 0 ] ) ;
F_77 ( & V_102 , 0 , & V_97 ) ;
}
static void F_78 ( struct V_38 * V_39 )
{
T_2 V_87 , V_88 ;
if ( V_39 -> V_103 == NULL )
return;
V_87 = F_68 ( V_39 -> V_89 + V_104 ) ;
V_88 = F_68 ( V_39 -> V_89 + V_105 ) ;
while ( V_87 != V_88 ) {
volatile T_3 * V_95 ;
T_3 V_4 [ 2 ] ;
int V_48 ;
V_95 = ( T_3 * ) ( V_39 -> V_103 + V_87 ) ;
for ( V_48 = 0 ; V_48 < V_77 ; ++ V_48 ) {
if ( F_71 ( V_95 [ 0 ] ) != 0 )
break;
F_65 ( 1 ) ;
}
V_4 [ 0 ] = V_95 [ 0 ] ;
V_4 [ 1 ] = V_95 [ 1 ] ;
V_95 [ 0 ] = V_95 [ 1 ] = 0UL ;
V_87 = ( V_87 + V_106 ) % V_107 ;
F_69 ( V_87 , V_39 -> V_89 + V_104 ) ;
F_70 ( V_39 , V_4 ) ;
V_87 = F_68 ( V_39 -> V_89 + V_104 ) ;
V_88 = F_68 ( V_39 -> V_89 + V_105 ) ;
}
}
int F_79 ( int (* F_80)( T_2 ) )
{
V_108 = F_80 ;
return 0 ;
}
static void F_81 ( struct V_38 * V_39 )
{
T_2 V_87 , V_88 , V_109 = 0 ;
if ( V_39 -> V_110 == NULL )
return;
V_87 = F_68 ( V_39 -> V_89 + V_111 ) ;
V_88 = F_68 ( V_39 -> V_89 + V_112 ) ;
while ( V_87 != V_88 ) {
volatile T_3 * V_95 ;
T_3 V_113 ;
V_95 = ( T_3 * ) ( V_39 -> V_110 + V_87 ) ;
V_109 ++ ;
V_113 = * V_95 ;
V_87 = ( V_87 + V_114 ) % V_115 ;
F_69 ( V_87 , V_39 -> V_89 + V_111 ) ;
switch ( F_82 ( V_113 ) ) {
case V_116 :
if ( ! V_108 )
break;
F_83 ( L_24 ,
V_117 , F_84 ( V_113 ) ,
F_85 ( V_113 ) ) ;
if ( V_108 ( F_85 ( V_113 ) ) != 0 )
F_55 ( L_25 ) ;
break;
default:
break;
}
}
}
T_4 F_86 ( int V_118 , void * V_31 )
{
struct V_38 * V_39 = (struct V_38 * ) V_31 ;
T_2 V_119 = F_68 ( V_39 -> V_89 + V_120 ) ;
while ( V_119 & V_121 ) {
F_69 ( V_121 ,
V_39 -> V_89 + V_120 ) ;
if ( V_119 & V_122 ) {
F_87 ( L_26 ) ;
F_67 ( V_39 ) ;
}
if ( V_119 & V_123 ) {
F_87 ( L_27 ) ;
F_78 ( V_39 ) ;
}
#ifdef F_88
if ( V_119 & V_124 ) {
F_87 ( L_28 ) ;
F_81 ( V_39 ) ;
}
#endif
V_119 = F_68 ( V_39 -> V_89 + V_120 ) ;
}
return V_125 ;
}
T_4 F_89 ( int V_118 , void * V_31 )
{
return V_126 ;
}
static int F_90 ( volatile T_3 * V_127 )
{
int V_48 = 0 ;
while ( * V_127 == 0 && V_48 < V_77 ) {
F_65 ( 1 ) ;
V_48 += 1 ;
}
if ( V_48 == V_77 ) {
F_91 ( L_29 ) ;
return - V_128 ;
}
return 0 ;
}
static void F_92 ( struct V_38 * V_39 ,
struct V_60 * V_61 )
{
T_5 * V_129 ;
V_129 = V_39 -> V_130 + V_39 -> V_131 ;
V_39 -> V_131 += sizeof( * V_61 ) ;
V_39 -> V_131 %= V_132 ;
memcpy ( V_129 , V_61 , sizeof( * V_61 ) ) ;
F_69 ( V_39 -> V_131 , V_39 -> V_89 + V_133 ) ;
}
static void F_93 ( struct V_60 * V_61 , T_3 V_63 )
{
T_3 V_134 = F_94 ( ( void * ) V_63 ) ;
F_95 ( V_63 & 0x7ULL ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_31 [ 0 ] = F_96 ( V_134 ) | V_135 ;
V_61 -> V_31 [ 1 ] = F_97 ( V_134 ) ;
V_61 -> V_31 [ 2 ] = 1 ;
F_98 ( V_61 , V_136 ) ;
}
static void F_99 ( struct V_60 * V_61 , T_1 V_14 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_31 [ 0 ] = V_14 ;
F_98 ( V_61 , V_137 ) ;
}
static void F_100 ( struct V_60 * V_61 , T_3 V_63 ,
T_6 V_138 , T_1 V_65 , int V_139 )
{
T_3 V_140 ;
bool V_141 ;
V_140 = F_101 ( V_63 , V_138 , V_142 ) ;
V_141 = false ;
if ( V_140 > 1 ) {
V_63 = V_143 ;
V_141 = true ;
}
V_63 &= V_144 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_31 [ 1 ] |= V_65 ;
V_61 -> V_31 [ 2 ] = F_96 ( V_63 ) ;
V_61 -> V_31 [ 3 ] = F_97 ( V_63 ) ;
F_98 ( V_61 , V_145 ) ;
if ( V_141 )
V_61 -> V_31 [ 2 ] |= V_146 ;
if ( V_139 )
V_61 -> V_31 [ 2 ] |= V_147 ;
}
static void F_102 ( struct V_60 * V_61 , T_1 V_14 , int V_148 ,
T_3 V_63 , T_6 V_138 )
{
T_3 V_140 ;
bool V_141 ;
V_140 = F_101 ( V_63 , V_138 , V_142 ) ;
V_141 = false ;
if ( V_140 > 1 ) {
V_63 = V_143 ;
V_141 = true ;
}
V_63 &= V_144 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_31 [ 0 ] = V_14 ;
V_61 -> V_31 [ 0 ] |= ( V_148 & 0xff ) << 24 ;
V_61 -> V_31 [ 1 ] = V_14 ;
V_61 -> V_31 [ 2 ] = F_96 ( V_63 ) ;
V_61 -> V_31 [ 3 ] = F_97 ( V_63 ) ;
F_98 ( V_61 , V_149 ) ;
if ( V_141 )
V_61 -> V_31 [ 2 ] |= V_146 ;
}
static void F_103 ( struct V_60 * V_61 , T_1 V_65 , int V_99 ,
T_3 V_63 , bool V_138 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_63 &= ~ ( 0xfffULL ) ;
V_61 -> V_31 [ 0 ] = V_99 ;
V_61 -> V_31 [ 1 ] = V_65 ;
V_61 -> V_31 [ 2 ] = F_96 ( V_63 ) ;
V_61 -> V_31 [ 3 ] = F_97 ( V_63 ) ;
V_61 -> V_31 [ 2 ] |= V_147 ;
V_61 -> V_31 [ 2 ] |= V_150 ;
if ( V_138 )
V_61 -> V_31 [ 2 ] |= V_146 ;
F_98 ( V_61 , V_145 ) ;
}
static void F_104 ( struct V_60 * V_61 , T_1 V_14 , int V_99 ,
int V_148 , T_3 V_63 , bool V_138 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_63 &= ~ ( 0xfffULL ) ;
V_61 -> V_31 [ 0 ] = V_14 ;
V_61 -> V_31 [ 0 ] |= ( ( V_99 >> 8 ) & 0xff ) << 16 ;
V_61 -> V_31 [ 0 ] |= ( V_148 & 0xff ) << 24 ;
V_61 -> V_31 [ 1 ] = V_14 ;
V_61 -> V_31 [ 1 ] |= ( V_99 & 0xff ) << 16 ;
V_61 -> V_31 [ 2 ] = F_96 ( V_63 ) ;
V_61 -> V_31 [ 2 ] |= V_150 ;
V_61 -> V_31 [ 3 ] = F_97 ( V_63 ) ;
if ( V_138 )
V_61 -> V_31 [ 2 ] |= V_146 ;
F_98 ( V_61 , V_149 ) ;
}
static void F_105 ( struct V_60 * V_61 , T_1 V_14 , int V_99 ,
int V_119 , int V_101 , bool V_151 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_31 [ 0 ] = V_14 ;
if ( V_151 ) {
V_61 -> V_31 [ 1 ] = V_99 ;
V_61 -> V_31 [ 2 ] = V_150 ;
}
V_61 -> V_31 [ 3 ] = V_101 & 0x1ff ;
V_61 -> V_31 [ 3 ] |= ( V_119 & V_152 ) << V_153 ;
F_98 ( V_61 , V_154 ) ;
}
static void F_106 ( struct V_60 * V_61 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_98 ( V_61 , V_155 ) ;
}
static void F_107 ( struct V_60 * V_61 , T_1 V_14 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_31 [ 0 ] = V_14 ;
F_98 ( V_61 , V_156 ) ;
}
static int F_108 ( struct V_38 * V_39 ,
struct V_60 * V_61 ,
bool V_157 )
{
unsigned int V_67 = 0 ;
T_2 V_158 , V_159 ;
V_159 = ( V_39 -> V_131 + sizeof( * V_61 ) ) % V_132 ;
V_160:
V_158 = ( V_39 -> V_161 - V_159 ) % V_132 ;
if ( V_158 <= 0x20 ) {
if ( V_67 ++ ) {
if ( V_67 == V_77 ) {
F_55 ( L_30 ) ;
return - V_128 ;
}
F_65 ( 1 ) ;
}
V_39 -> V_161 = F_68 ( V_39 -> V_89 +
V_162 ) ;
goto V_160;
}
F_92 ( V_39 , V_61 ) ;
V_39 -> V_163 = V_157 ;
return 0 ;
}
static int F_109 ( struct V_38 * V_39 ,
struct V_60 * V_61 ,
bool V_157 )
{
unsigned long V_21 ;
int V_164 ;
F_18 ( & V_39 -> V_165 , V_21 ) ;
V_164 = F_108 ( V_39 , V_61 , V_157 ) ;
F_20 ( & V_39 -> V_165 , V_21 ) ;
return V_164 ;
}
static int F_110 ( struct V_38 * V_39 , struct V_60 * V_61 )
{
return F_109 ( V_39 , V_61 , true ) ;
}
static int F_111 ( struct V_38 * V_39 )
{
struct V_60 V_61 ;
unsigned long V_21 ;
int V_164 ;
if ( ! V_39 -> V_163 )
return 0 ;
F_93 ( & V_61 , ( T_3 ) & V_39 -> V_166 ) ;
F_18 ( & V_39 -> V_165 , V_21 ) ;
V_39 -> V_166 = 0 ;
V_164 = F_108 ( V_39 , & V_61 , false ) ;
if ( V_164 )
goto V_29;
V_164 = F_90 ( & V_39 -> V_166 ) ;
V_29:
F_20 ( & V_39 -> V_165 , V_21 ) ;
return V_164 ;
}
static int F_112 ( struct V_38 * V_39 , T_1 V_14 )
{
struct V_60 V_61 ;
F_99 ( & V_61 , V_14 ) ;
return F_110 ( V_39 , & V_61 ) ;
}
static void F_113 ( struct V_38 * V_39 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= 0xffff ; ++ V_14 )
F_112 ( V_39 , V_14 ) ;
F_111 ( V_39 ) ;
}
static void F_114 ( struct V_38 * V_39 )
{
T_2 V_167 ;
for ( V_167 = 0 ; V_167 <= 0xffff ; ++ V_167 ) {
struct V_60 V_61 ;
F_100 ( & V_61 , 0 , V_143 ,
V_167 , 1 ) ;
F_110 ( V_39 , & V_61 ) ;
}
F_111 ( V_39 ) ;
}
static void F_115 ( struct V_38 * V_39 )
{
struct V_60 V_61 ;
F_106 ( & V_61 ) ;
F_110 ( V_39 , & V_61 ) ;
F_111 ( V_39 ) ;
}
static void F_116 ( struct V_38 * V_39 , T_1 V_14 )
{
struct V_60 V_61 ;
F_107 ( & V_61 , V_14 ) ;
F_110 ( V_39 , & V_61 ) ;
}
static void F_117 ( struct V_38 * V_39 )
{
T_2 V_14 ;
for ( V_14 = 0 ; V_14 <= V_168 ; V_14 ++ )
F_116 ( V_39 , V_14 ) ;
F_111 ( V_39 ) ;
}
void F_118 ( struct V_38 * V_39 )
{
if ( F_119 ( V_39 , V_169 ) ) {
F_115 ( V_39 ) ;
} else {
F_113 ( V_39 ) ;
F_117 ( V_39 ) ;
F_114 ( V_39 ) ;
}
}
static int F_120 ( struct V_23 * V_24 ,
T_3 V_63 , T_6 V_138 )
{
struct V_38 * V_39 ;
struct V_60 V_61 ;
int V_148 ;
V_148 = V_24 -> V_170 . V_148 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
F_102 ( & V_61 , V_24 -> V_14 , V_148 , V_63 , V_138 ) ;
return F_110 ( V_39 , & V_61 ) ;
}
static int F_121 ( struct V_23 * V_24 )
{
struct V_38 * V_39 ;
T_1 V_30 ;
int V_164 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
V_30 = V_24 -> V_30 ;
V_164 = F_112 ( V_39 , V_24 -> V_14 ) ;
if ( ! V_164 && V_30 != V_24 -> V_14 )
V_164 = F_112 ( V_39 , V_30 ) ;
if ( V_164 )
return V_164 ;
if ( V_24 -> V_170 . V_171 )
V_164 = F_120 ( V_24 , 0 , ~ 0UL ) ;
return V_164 ;
}
static void F_122 ( struct V_16 * V_19 ,
T_3 V_63 , T_6 V_138 , int V_139 )
{
struct V_23 * V_24 ;
struct V_60 V_61 ;
int V_164 = 0 , V_48 ;
F_100 ( & V_61 , V_63 , V_138 , V_19 -> V_172 , V_139 ) ;
for ( V_48 = 0 ; V_48 < F_123 () ; ++ V_48 ) {
if ( ! V_19 -> V_173 [ V_48 ] )
continue;
V_164 |= F_110 ( V_174 [ V_48 ] , & V_61 ) ;
}
F_9 (dev_data, &domain->dev_list, list) {
if ( ! V_24 -> V_170 . V_171 )
continue;
V_164 |= F_120 ( V_24 , V_63 , V_138 ) ;
}
F_95 ( V_164 ) ;
}
static void F_124 ( struct V_16 * V_19 ,
T_3 V_63 , T_6 V_138 )
{
F_122 ( V_19 , V_63 , V_138 , 0 ) ;
}
static void F_125 ( struct V_16 * V_19 )
{
F_122 ( V_19 , 0 , V_143 , 0 ) ;
}
static void F_126 ( struct V_16 * V_19 )
{
F_122 ( V_19 , 0 , V_143 , 1 ) ;
}
static void F_127 ( struct V_16 * V_19 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_123 () ; ++ V_48 ) {
if ( V_19 && ! V_19 -> V_173 [ V_48 ] )
continue;
F_111 ( V_174 [ V_48 ] ) ;
}
}
static void F_128 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list)
F_121 ( V_24 ) ;
}
static bool F_129 ( struct V_16 * V_19 ,
T_7 V_175 )
{
T_3 * V_176 ;
if ( V_19 -> V_177 == V_178 )
return false ;
V_176 = ( void * ) F_130 ( V_175 ) ;
if ( ! V_176 )
return false ;
* V_176 = F_131 ( V_19 -> V_177 ,
F_94 ( V_19 -> V_179 ) ) ;
V_19 -> V_179 = V_176 ;
V_19 -> V_177 += 1 ;
V_19 -> V_180 = true ;
return true ;
}
static T_3 * F_132 ( struct V_16 * V_19 ,
unsigned long V_63 ,
unsigned long V_181 ,
T_3 * * V_182 ,
T_7 V_175 )
{
int V_183 , V_184 ;
T_3 * V_176 , * V_185 ;
F_15 ( ! F_133 ( V_181 ) ) ;
while ( V_63 > F_134 ( V_19 -> V_177 ) )
F_129 ( V_19 , V_175 ) ;
V_183 = V_19 -> V_177 - 1 ;
V_176 = & V_19 -> V_179 [ F_135 ( V_183 , V_63 ) ] ;
V_63 = F_136 ( V_63 , V_181 ) ;
V_184 = F_137 ( V_181 ) ;
while ( V_183 > V_184 ) {
T_3 V_186 , V_187 ;
V_186 = * V_176 ;
if ( ! F_138 ( V_186 ) ) {
V_185 = ( T_3 * ) F_130 ( V_175 ) ;
if ( ! V_185 )
return NULL ;
V_187 = F_131 ( V_183 , F_94 ( V_185 ) ) ;
if ( F_139 ( V_176 , V_186 , V_187 ) != V_186 ) {
F_140 ( ( unsigned long ) V_185 ) ;
continue;
}
}
if ( F_141 ( * V_176 ) != V_183 )
return NULL ;
V_183 -= 1 ;
V_176 = F_142 ( * V_176 ) ;
if ( V_182 && V_183 == V_184 )
* V_182 = V_176 ;
V_176 = & V_176 [ F_135 ( V_183 , V_63 ) ] ;
}
return V_176 ;
}
static T_3 * F_143 ( struct V_16 * V_19 ,
unsigned long V_63 ,
unsigned long * V_181 )
{
int V_183 ;
T_3 * V_176 ;
if ( V_63 > F_134 ( V_19 -> V_177 ) )
return NULL ;
V_183 = V_19 -> V_177 - 1 ;
V_176 = & V_19 -> V_179 [ F_135 ( V_183 , V_63 ) ] ;
* V_181 = F_144 ( V_183 ) ;
while ( V_183 > 0 ) {
if ( ! F_138 ( * V_176 ) )
return NULL ;
if ( F_141 ( * V_176 ) == 7 ||
F_141 ( * V_176 ) == 0 )
break;
if ( F_141 ( * V_176 ) != V_183 )
return NULL ;
V_183 -= 1 ;
V_176 = F_142 ( * V_176 ) ;
V_176 = & V_176 [ F_135 ( V_183 , V_63 ) ] ;
* V_181 = F_144 ( V_183 ) ;
}
if ( F_141 ( * V_176 ) == 0x07 ) {
unsigned long V_188 ;
* V_181 = V_188 = F_145 ( * V_176 ) ;
V_188 = ~ ( ( F_146 ( V_188 ) << 3 ) - 1 ) ;
V_176 = ( T_3 * ) ( ( ( unsigned long ) V_176 ) & V_188 ) ;
}
return V_176 ;
}
static int F_147 ( struct V_16 * V_18 ,
unsigned long V_189 ,
unsigned long V_59 ,
unsigned long V_181 ,
int V_190 ,
T_7 V_175 )
{
T_3 V_186 , * V_176 ;
int V_48 , V_67 ;
F_15 ( ! F_148 ( V_189 , V_181 ) ) ;
F_15 ( ! F_148 ( V_59 , V_181 ) ) ;
if ( ! ( V_190 & V_191 ) )
return - V_15 ;
V_67 = F_146 ( V_181 ) ;
V_176 = F_132 ( V_18 , V_189 , V_181 , NULL , V_175 ) ;
if ( ! V_176 )
return - V_54 ;
for ( V_48 = 0 ; V_48 < V_67 ; ++ V_48 )
if ( F_138 ( V_176 [ V_48 ] ) )
return - V_192 ;
if ( V_67 > 1 ) {
V_186 = F_149 ( F_150 ( V_59 ) , V_181 ) ;
V_186 |= F_151 ( 7 ) | V_193 | V_194 ;
} else
V_186 = F_150 ( V_59 ) | V_193 | V_194 ;
if ( V_190 & V_195 )
V_186 |= V_196 ;
if ( V_190 & V_197 )
V_186 |= V_198 ;
for ( V_48 = 0 ; V_48 < V_67 ; ++ V_48 )
V_176 [ V_48 ] = V_186 ;
F_152 ( V_18 ) ;
return 0 ;
}
static unsigned long F_153 ( struct V_16 * V_18 ,
unsigned long V_189 ,
unsigned long V_181 )
{
unsigned long long V_199 ;
unsigned long V_200 ;
T_3 * V_176 ;
F_15 ( ! F_133 ( V_181 ) ) ;
V_199 = 0 ;
while ( V_199 < V_181 ) {
V_176 = F_143 ( V_18 , V_189 , & V_200 ) ;
if ( V_176 ) {
int V_48 , V_67 ;
V_67 = F_146 ( V_200 ) ;
for ( V_48 = 0 ; V_48 < V_67 ; V_48 ++ )
V_176 [ V_48 ] = 0ULL ;
}
V_189 = ( V_189 & ~ ( V_200 - 1 ) ) + V_200 ;
V_199 += V_200 ;
}
F_15 ( V_199 && ! F_133 ( V_199 ) ) ;
return V_199 ;
}
static unsigned long F_154 ( struct V_1 * V_2 ,
struct V_20 * V_201 ,
unsigned int V_140 , T_3 V_52 )
{
unsigned long V_202 = 0 ;
V_140 = F_155 ( V_140 ) ;
if ( V_52 > F_156 ( 32 ) )
V_202 = F_157 ( & V_201 -> V_203 , V_140 ,
F_158 ( F_156 ( 32 ) ) ) ;
if ( ! V_202 )
V_202 = F_157 ( & V_201 -> V_203 , V_140 , F_158 ( V_52 ) ) ;
return ( V_202 << V_204 ) ;
}
static void F_159 ( struct V_20 * V_201 ,
unsigned long V_63 ,
unsigned int V_140 )
{
V_140 = F_155 ( V_140 ) ;
V_63 >>= V_204 ;
F_160 ( & V_201 -> V_203 , V_63 , V_140 ) ;
}
static void F_161 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_205 , V_21 ) ;
F_162 ( & V_19 -> V_206 , & V_207 ) ;
F_20 ( & V_205 , V_21 ) ;
}
static void F_163 ( struct V_16 * V_19 )
{
unsigned long V_21 ;
F_18 ( & V_205 , V_21 ) ;
F_164 ( & V_19 -> V_206 ) ;
F_20 ( & V_205 , V_21 ) ;
}
static T_1 F_165 ( void )
{
unsigned long V_21 ;
int V_172 ;
F_166 ( & V_208 , V_21 ) ;
V_172 = F_167 ( V_209 , V_210 ) ;
F_15 ( V_172 == 0 ) ;
if ( V_172 > 0 && V_172 < V_210 )
F_168 ( V_172 , V_209 ) ;
else
V_172 = 0 ;
F_169 ( & V_208 , V_21 ) ;
return V_172 ;
}
static void F_170 ( int V_172 )
{
unsigned long V_21 ;
F_166 ( & V_208 , V_21 ) ;
if ( V_172 > 0 && V_172 < V_210 )
F_171 ( V_172 , V_209 ) ;
F_169 ( & V_208 , V_21 ) ;
}
static void F_172 ( struct V_16 * V_19 )
{
unsigned long V_211 = ( unsigned long ) V_19 -> V_179 ;
switch ( V_19 -> V_177 ) {
case V_212 :
break;
case V_213 :
F_140 ( V_211 ) ;
break;
case V_214 :
F_173 ( V_211 ) ;
break;
case V_215 :
F_174 ( V_211 ) ;
break;
case V_216 :
F_175 ( V_211 ) ;
break;
case V_217 :
F_176 ( V_211 ) ;
break;
case V_178 :
F_177 ( V_211 ) ;
break;
default:
F_178 () ;
}
}
static void F_179 ( T_3 * V_218 )
{
T_3 * V_219 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 512 ; ++ V_48 ) {
if ( ! ( V_218 [ V_48 ] & V_220 ) )
continue;
V_219 = F_57 ( V_218 [ V_48 ] & V_144 ) ;
F_140 ( ( unsigned long ) V_219 ) ;
}
}
static void F_180 ( T_3 * V_218 )
{
T_3 * V_219 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 512 ; ++ V_48 ) {
if ( ! ( V_218 [ V_48 ] & V_220 ) )
continue;
V_219 = F_57 ( V_218 [ V_48 ] & V_144 ) ;
F_179 ( V_219 ) ;
}
}
static void F_181 ( struct V_16 * V_19 )
{
if ( V_19 -> V_221 == 2 )
F_180 ( V_19 -> V_222 ) ;
else if ( V_19 -> V_221 == 1 )
F_179 ( V_19 -> V_222 ) ;
else
F_15 ( V_19 -> V_221 != 0 ) ;
F_140 ( ( unsigned long ) V_19 -> V_222 ) ;
}
static void F_182 ( struct V_20 * V_18 )
{
F_125 ( & V_18 -> V_19 ) ;
F_127 ( & V_18 -> V_19 ) ;
}
static void F_183 ( struct V_223 * V_203 )
{
struct V_20 * V_18 ;
V_18 = F_13 ( V_203 , struct V_20 , V_203 ) ;
F_182 ( V_18 ) ;
}
static void F_184 ( struct V_20 * V_18 )
{
if ( ! V_18 )
return;
F_163 ( & V_18 -> V_19 ) ;
F_185 ( & V_18 -> V_203 ) ;
F_172 ( & V_18 -> V_19 ) ;
if ( V_18 -> V_19 . V_172 )
F_170 ( V_18 -> V_19 . V_172 ) ;
F_186 ( V_18 ) ;
}
static struct V_20 * F_187 ( void )
{
struct V_20 * V_201 ;
V_201 = F_17 ( sizeof( struct V_20 ) , V_25 ) ;
if ( ! V_201 )
return NULL ;
if ( F_188 ( & V_201 -> V_19 ) )
goto V_224;
V_201 -> V_19 . V_177 = V_215 ;
V_201 -> V_19 . V_179 = ( void * ) F_130 ( V_25 ) ;
V_201 -> V_19 . V_21 = V_22 ;
if ( ! V_201 -> V_19 . V_179 )
goto V_224;
F_189 ( & V_201 -> V_203 , V_142 ,
V_225 , V_226 ) ;
if ( F_190 ( & V_201 -> V_203 , F_183 , NULL ) )
goto V_224;
F_191 ( & V_227 , & V_201 -> V_203 ) ;
F_161 ( & V_201 -> V_19 ) ;
return V_201 ;
V_224:
F_184 ( V_201 ) ;
return NULL ;
}
static bool V_20 ( struct V_16 * V_19 )
{
return V_19 -> V_21 & V_22 ;
}
static void F_192 ( T_1 V_14 , struct V_16 * V_19 , bool V_170 )
{
T_3 V_228 = 0 ;
T_3 V_21 = 0 ;
if ( V_19 -> V_177 != V_212 )
V_228 = F_94 ( V_19 -> V_179 ) ;
V_228 |= ( V_19 -> V_177 & V_229 )
<< V_230 ;
V_228 |= V_231 | V_232 | V_233 | V_234 ;
V_21 = V_36 [ V_14 ] . V_31 [ 1 ] ;
if ( V_170 )
V_21 |= V_235 ;
if ( V_19 -> V_21 & V_236 ) {
T_3 V_237 = F_94 ( V_19 -> V_222 ) ;
T_3 V_221 = V_19 -> V_221 ;
T_3 V_238 ;
V_228 |= V_239 ;
V_228 |= ( V_221 & V_240 ) << V_241 ;
V_238 = F_193 ( ~ 0ULL ) << V_242 ;
V_21 &= ~ V_238 ;
V_238 = F_194 ( ~ 0ULL ) << V_243 ;
V_21 &= ~ V_238 ;
V_238 = F_195 ( V_237 ) << V_244 ;
V_228 |= V_238 ;
V_238 = F_193 ( V_237 ) << V_242 ;
V_21 |= V_238 ;
V_238 = F_194 ( V_237 ) << V_243 ;
V_21 |= V_238 ;
}
V_21 &= ~ V_245 ;
V_21 |= V_19 -> V_172 ;
V_36 [ V_14 ] . V_31 [ 1 ] = V_21 ;
V_36 [ V_14 ] . V_31 [ 0 ] = V_228 ;
}
static void F_196 ( T_1 V_14 )
{
V_36 [ V_14 ] . V_31 [ 0 ] = V_233 | V_234 ;
V_36 [ V_14 ] . V_31 [ 1 ] &= V_246 ;
F_197 ( V_14 ) ;
}
static void F_198 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
struct V_38 * V_39 ;
T_1 V_30 ;
bool V_170 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
V_30 = V_24 -> V_30 ;
V_170 = V_24 -> V_170 . V_171 ;
V_24 -> V_19 = V_19 ;
F_162 ( & V_24 -> V_206 , & V_19 -> V_247 ) ;
V_19 -> V_173 [ V_39 -> V_248 ] += 1 ;
V_19 -> V_249 += 1 ;
F_192 ( V_24 -> V_14 , V_19 , V_170 ) ;
if ( V_30 != V_24 -> V_14 )
F_192 ( V_30 , V_19 , V_170 ) ;
F_121 ( V_24 ) ;
}
static void F_199 ( struct V_23 * V_24 )
{
struct V_38 * V_39 ;
T_1 V_30 ;
if ( ! V_24 -> V_19 )
return;
V_39 = V_35 [ V_24 -> V_14 ] ;
V_30 = V_24 -> V_30 ;
V_24 -> V_19 -> V_173 [ V_39 -> V_248 ] -= 1 ;
V_24 -> V_19 -> V_249 -= 1 ;
V_24 -> V_19 = NULL ;
F_164 ( & V_24 -> V_206 ) ;
F_196 ( V_24 -> V_14 ) ;
if ( V_30 != V_24 -> V_14 )
F_196 ( V_30 ) ;
F_121 ( V_24 ) ;
}
static int F_200 ( struct V_23 * V_24 ,
struct V_16 * V_19 )
{
int V_164 ;
F_95 ( ! F_201 () ) ;
F_202 ( & V_19 -> V_165 ) ;
V_164 = - V_192 ;
if ( V_24 -> V_19 != NULL )
goto V_29;
F_198 ( V_24 , V_19 ) ;
V_164 = 0 ;
V_29:
F_203 ( & V_19 -> V_165 ) ;
return V_164 ;
}
static void F_204 ( struct V_8 * V_9 )
{
F_205 ( V_9 ) ;
F_206 ( V_9 ) ;
F_207 ( V_9 ) ;
}
static int F_208 ( struct V_8 * V_9 )
{
T_1 V_250 ;
int V_49 ;
V_49 = F_40 ( V_9 , V_46 ) ;
if ( ! V_49 )
return - V_15 ;
F_209 ( V_9 , V_49 + V_251 , & V_250 ) ;
V_250 |= V_252 ;
F_210 ( V_9 , V_49 + V_251 , V_250 ) ;
return 0 ;
}
static int F_211 ( struct V_8 * V_9 )
{
bool V_253 ;
int V_254 , V_164 ;
V_254 = 32 ;
if ( F_41 ( V_9 , V_255 ) )
V_254 = 1 ;
V_253 = F_41 ( V_9 , V_256 ) ;
V_164 = F_212 ( V_9 , 0 ) ;
if ( V_164 )
goto V_257;
V_164 = F_213 ( V_9 ) ;
if ( V_164 )
goto V_257;
V_164 = F_214 ( V_9 , V_254 ) ;
if ( V_164 )
goto V_257;
if ( V_253 ) {
V_164 = F_208 ( V_9 ) ;
if ( V_164 )
goto V_257;
}
V_164 = F_215 ( V_9 , V_204 ) ;
if ( V_164 )
goto V_257;
return 0 ;
V_257:
F_206 ( V_9 ) ;
F_207 ( V_9 ) ;
return V_164 ;
}
static bool F_216 ( struct V_8 * V_9 )
{
T_1 V_119 ;
int V_49 ;
V_49 = F_40 ( V_9 , V_46 ) ;
if ( ! V_49 )
return false ;
F_209 ( V_9 , V_49 + V_258 , & V_119 ) ;
return ( V_119 & V_259 ) ? true : false ;
}
static int F_217 ( struct V_1 * V_2 ,
struct V_16 * V_19 )
{
struct V_8 * V_9 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
int V_164 ;
V_24 = F_34 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
goto V_260;
V_9 = F_6 ( V_2 ) ;
if ( V_19 -> V_21 & V_236 ) {
if ( ! V_24 -> V_261 )
return - V_15 ;
if ( V_24 -> V_55 ) {
if ( F_211 ( V_9 ) != 0 )
return - V_15 ;
V_24 -> V_170 . V_171 = true ;
V_24 -> V_170 . V_148 = F_218 ( V_9 ) ;
V_24 -> V_262 = F_216 ( V_9 ) ;
}
} else if ( V_263 &&
F_215 ( V_9 , V_204 ) == 0 ) {
V_24 -> V_170 . V_171 = true ;
V_24 -> V_170 . V_148 = F_218 ( V_9 ) ;
}
V_260:
F_166 ( & V_208 , V_21 ) ;
V_164 = F_200 ( V_24 , V_19 ) ;
F_169 ( & V_208 , V_21 ) ;
F_126 ( V_19 ) ;
return V_164 ;
}
static void F_219 ( struct V_23 * V_24 )
{
struct V_16 * V_19 ;
F_95 ( ! F_201 () ) ;
if ( F_95 ( ! V_24 -> V_19 ) )
return;
V_19 = V_24 -> V_19 ;
F_202 ( & V_19 -> V_165 ) ;
F_199 ( V_24 ) ;
F_203 ( & V_19 -> V_165 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
struct V_23 * V_24 ;
unsigned long V_21 ;
V_24 = F_34 ( V_2 ) ;
V_19 = V_24 -> V_19 ;
F_166 ( & V_208 , V_21 ) ;
F_219 ( V_24 ) ;
F_169 ( & V_208 , V_21 ) ;
if ( ! F_11 ( V_2 ) )
return;
if ( V_19 -> V_21 & V_236 && V_24 -> V_55 )
F_204 ( F_6 ( V_2 ) ) ;
else if ( V_24 -> V_170 . V_171 )
F_205 ( F_6 ( V_2 ) ) ;
V_24 -> V_170 . V_171 = false ;
}
static int F_220 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_17 * V_19 ;
struct V_38 * V_39 ;
int V_164 , V_14 ;
if ( ! F_42 ( V_2 ) || F_34 ( V_2 ) )
return 0 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_39 = V_35 [ V_14 ] ;
V_164 = F_47 ( V_2 ) ;
if ( V_164 ) {
if ( V_164 != - V_264 )
F_55 ( L_31 ,
F_30 ( V_2 ) ) ;
F_49 ( V_2 ) ;
V_2 -> V_58 = & V_265 ;
goto V_266;
}
F_43 ( V_2 ) ;
V_24 = F_34 ( V_2 ) ;
F_15 ( ! V_24 ) ;
if ( V_267 || V_24 -> V_55 )
F_221 ( V_2 ) ;
V_19 = F_222 ( V_2 ) ;
if ( V_19 -> type == V_268 )
V_24 -> V_261 = true ;
else
V_2 -> V_58 = & V_269 ;
V_266:
F_111 ( V_39 ) ;
return 0 ;
}
static void F_223 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
int V_14 ;
if ( ! F_42 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
V_39 = V_35 [ V_14 ] ;
F_50 ( V_2 ) ;
F_111 ( V_39 ) ;
}
static struct V_42 * F_224 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) )
return F_225 ( V_2 ) ;
return F_35 ( V_2 ) ;
}
static struct V_16 * F_226 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
struct V_17 * V_270 ;
if ( ! F_42 ( V_2 ) )
return F_36 ( - V_15 ) ;
V_19 = F_34 ( V_2 ) -> V_19 ;
if ( V_19 == NULL && F_34 ( V_2 ) -> V_40 ) {
F_34 ( V_2 ) -> V_40 = false ;
V_270 = F_222 ( V_2 ) ;
V_19 = F_12 ( V_270 ) ;
F_217 ( V_2 , V_19 ) ;
}
if ( V_19 == NULL )
return F_36 ( - V_192 ) ;
if ( ! V_20 ( V_19 ) )
return F_36 ( - V_192 ) ;
return V_19 ;
}
static void F_227 ( struct V_16 * V_19 )
{
struct V_23 * V_24 ;
F_9 (dev_data, &domain->dev_list, list) {
F_192 ( V_24 -> V_14 , V_19 , V_24 -> V_170 . V_171 ) ;
if ( V_24 -> V_14 == V_24 -> V_30 )
continue;
F_192 ( V_24 -> V_30 , V_19 , V_24 -> V_170 . V_171 ) ;
}
}
static void F_152 ( struct V_16 * V_19 )
{
if ( ! V_19 -> V_180 )
return;
F_227 ( V_19 ) ;
F_128 ( V_19 ) ;
F_126 ( V_19 ) ;
V_19 -> V_180 = false ;
}
static int F_228 ( enum V_271 V_272 )
{
if ( V_272 == V_273 )
return V_195 ;
else if ( V_272 == V_274 )
return V_197 ;
else if ( V_272 == V_275 )
return V_197 | V_195 ;
else
return 0 ;
}
static T_8 F_229 ( struct V_1 * V_2 ,
struct V_20 * V_201 ,
T_9 V_134 ,
T_6 V_138 ,
enum V_271 V_272 ,
T_3 V_52 )
{
T_8 V_276 = V_134 & ~ V_144 ;
T_8 V_63 , V_277 , V_164 ;
unsigned int V_140 ;
int V_190 = 0 ;
int V_48 ;
V_140 = F_101 ( V_134 , V_138 , V_142 ) ;
V_134 &= V_144 ;
V_63 = F_154 ( V_2 , V_201 , V_140 , V_52 ) ;
if ( V_63 == V_278 )
goto V_266;
V_190 = F_228 ( V_272 ) ;
V_277 = V_63 ;
for ( V_48 = 0 ; V_48 < V_140 ; ++ V_48 ) {
V_164 = F_147 ( & V_201 -> V_19 , V_277 , V_134 ,
V_142 , V_190 , V_279 ) ;
if ( V_164 )
goto V_280;
V_134 += V_142 ;
V_277 += V_142 ;
}
V_63 += V_276 ;
if ( F_230 ( V_281 ) ) {
F_124 ( & V_201 -> V_19 , V_63 , V_138 ) ;
F_127 ( & V_201 -> V_19 ) ;
}
V_266:
return V_63 ;
V_280:
for ( -- V_48 ; V_48 >= 0 ; -- V_48 ) {
V_277 -= V_142 ;
F_153 ( & V_201 -> V_19 , V_277 , V_142 ) ;
}
F_125 ( & V_201 -> V_19 ) ;
F_127 ( & V_201 -> V_19 ) ;
F_159 ( V_201 , V_63 , V_140 ) ;
return V_278 ;
}
static void F_231 ( struct V_20 * V_201 ,
T_8 V_282 ,
T_6 V_138 ,
int V_283 )
{
T_8 V_284 ;
T_8 V_48 , V_277 ;
unsigned int V_140 ;
V_284 = V_282 ;
V_140 = F_101 ( V_282 , V_138 , V_142 ) ;
V_282 &= V_144 ;
V_277 = V_282 ;
for ( V_48 = 0 ; V_48 < V_140 ; ++ V_48 ) {
F_153 ( & V_201 -> V_19 , V_277 , V_142 ) ;
V_277 += V_142 ;
}
if ( V_285 ) {
F_159 ( V_201 , V_282 , V_140 ) ;
F_125 ( & V_201 -> V_19 ) ;
F_127 ( & V_201 -> V_19 ) ;
} else {
V_140 = F_155 ( V_140 ) ;
F_232 ( & V_201 -> V_203 , V_282 >> V_204 , V_140 , 0 ) ;
}
}
static T_8 F_233 ( struct V_1 * V_2 , struct V_185 * V_185 ,
unsigned long V_276 , T_6 V_138 ,
enum V_271 V_283 ,
unsigned long V_286 )
{
T_9 V_134 = F_234 ( V_185 ) + V_276 ;
struct V_16 * V_19 ;
struct V_20 * V_201 ;
T_3 V_52 ;
V_19 = F_226 ( V_2 ) ;
if ( F_235 ( V_19 ) == - V_15 )
return ( T_8 ) V_134 ;
else if ( F_45 ( V_19 ) )
return V_278 ;
V_52 = * V_2 -> V_52 ;
V_201 = F_14 ( V_19 ) ;
return F_229 ( V_2 , V_201 , V_134 , V_138 , V_283 , V_52 ) ;
}
static void F_236 ( struct V_1 * V_2 , T_8 V_282 , T_6 V_138 ,
enum V_271 V_283 , unsigned long V_286 )
{
struct V_16 * V_19 ;
struct V_20 * V_201 ;
V_19 = F_226 ( V_2 ) ;
if ( F_45 ( V_19 ) )
return;
V_201 = F_14 ( V_19 ) ;
F_231 ( V_201 , V_282 , V_138 , V_283 ) ;
}
static int F_237 ( struct V_1 * V_2 ,
struct V_287 * V_288 ,
int V_289 )
{
unsigned long V_290 , V_291 ;
struct V_287 * V_141 ;
int V_48 , V_292 = 0 ;
V_290 = F_238 ( V_2 ) ;
V_291 = V_290 + 1 ? F_239 ( V_290 + 1 , V_142 ) >> V_204 :
1UL << ( V_293 - V_204 ) ;
F_240 (sglist, s, nelems, i) {
int V_13 , V_294 ;
V_141 -> V_295 = V_292 << V_204 ;
V_13 = V_292 % V_291 ;
V_294 = F_101 ( F_241 ( V_141 ) , V_141 -> V_296 , V_142 ) ;
if ( V_13 + V_294 > V_291 )
V_292 += V_291 - V_13 ;
V_292 += V_294 ;
}
return V_292 ;
}
static int F_242 ( struct V_1 * V_2 , struct V_287 * V_288 ,
int V_289 , enum V_271 V_272 ,
unsigned long V_286 )
{
int V_297 = 0 , V_292 = 0 , V_190 = 0 , V_48 ;
struct V_16 * V_19 ;
struct V_20 * V_201 ;
struct V_287 * V_141 ;
unsigned long V_63 ;
T_3 V_52 ;
V_19 = F_226 ( V_2 ) ;
if ( F_45 ( V_19 ) )
return 0 ;
V_201 = F_14 ( V_19 ) ;
V_52 = * V_2 -> V_52 ;
V_292 = F_237 ( V_2 , V_288 , V_289 ) ;
V_63 = F_154 ( V_2 , V_201 , V_292 , V_52 ) ;
if ( V_63 == V_278 )
goto V_257;
V_190 = F_228 ( V_272 ) ;
F_240 (sglist, s, nelems, i) {
int V_298 , V_140 = F_101 ( F_241 ( V_141 ) , V_141 -> V_296 , V_142 ) ;
for ( V_298 = 0 ; V_298 < V_140 ; ++ V_298 ) {
unsigned long V_189 , V_59 ;
int V_164 ;
V_189 = V_63 + V_141 -> V_295 + ( V_298 << V_204 ) ;
V_59 = ( F_241 ( V_141 ) & V_144 ) + ( V_298 << V_204 ) ;
V_164 = F_147 ( V_19 , V_189 , V_59 , V_142 , V_190 , V_279 ) ;
if ( V_164 )
goto V_280;
V_297 += 1 ;
}
}
F_240 (sglist, s, nelems, i) {
V_141 -> V_295 += V_63 + V_141 -> V_276 ;
V_141 -> V_299 = V_141 -> V_296 ;
}
return V_289 ;
V_280:
F_55 ( L_32 ,
F_30 ( V_2 ) , V_292 ) ;
F_240 (sglist, s, nelems, i) {
int V_298 , V_140 = F_101 ( F_241 ( V_141 ) , V_141 -> V_296 , V_142 ) ;
for ( V_298 = 0 ; V_298 < V_140 ; ++ V_298 ) {
unsigned long V_189 ;
V_189 = V_63 + V_141 -> V_295 + ( V_298 << V_204 ) ;
F_153 ( V_19 , V_189 , V_142 ) ;
if ( -- V_297 )
goto V_300;
}
}
V_300:
F_160 ( & V_201 -> V_203 , V_63 , V_292 ) ;
V_257:
return 0 ;
}
static void F_243 ( struct V_1 * V_2 , struct V_287 * V_288 ,
int V_289 , enum V_271 V_283 ,
unsigned long V_286 )
{
struct V_16 * V_19 ;
struct V_20 * V_201 ;
unsigned long V_301 ;
int V_292 = 2 ;
V_19 = F_226 ( V_2 ) ;
if ( F_45 ( V_19 ) )
return;
V_301 = F_244 ( V_288 ) & V_144 ;
V_201 = F_14 ( V_19 ) ;
V_292 = F_237 ( V_2 , V_288 , V_289 ) ;
F_231 ( V_201 , V_301 , V_292 << V_204 , V_283 ) ;
}
static void * F_245 ( struct V_1 * V_2 , T_6 V_138 ,
T_8 * V_282 , T_7 V_302 ,
unsigned long V_286 )
{
T_3 V_52 = V_2 -> V_303 ;
struct V_16 * V_19 ;
struct V_20 * V_201 ;
struct V_185 * V_185 ;
V_19 = F_226 ( V_2 ) ;
if ( F_235 ( V_19 ) == - V_15 ) {
V_185 = F_246 ( V_302 , F_247 ( V_138 ) ) ;
* V_282 = F_234 ( V_185 ) ;
return F_248 ( V_185 ) ;
} else if ( F_45 ( V_19 ) )
return NULL ;
V_201 = F_14 ( V_19 ) ;
V_138 = F_249 ( V_138 ) ;
V_52 = V_2 -> V_303 ;
V_302 &= ~ ( V_304 | V_305 | V_306 ) ;
V_302 |= V_307 ;
V_185 = F_246 ( V_302 | V_308 , F_247 ( V_138 ) ) ;
if ( ! V_185 ) {
if ( ! F_250 ( V_302 ) )
return NULL ;
V_185 = F_251 ( V_2 , V_138 >> V_204 ,
F_247 ( V_138 ) , V_302 ) ;
if ( ! V_185 )
return NULL ;
}
if ( ! V_52 )
V_52 = * V_2 -> V_52 ;
* V_282 = F_229 ( V_2 , V_201 , F_234 ( V_185 ) ,
V_138 , V_275 , V_52 ) ;
if ( * V_282 == V_278 )
goto V_309;
return F_248 ( V_185 ) ;
V_309:
if ( ! F_252 ( V_2 , V_185 , V_138 >> V_204 ) )
F_253 ( V_185 , F_247 ( V_138 ) ) ;
return NULL ;
}
static void F_254 ( struct V_1 * V_2 , T_6 V_138 ,
void * V_310 , T_8 V_282 ,
unsigned long V_286 )
{
struct V_16 * V_19 ;
struct V_20 * V_201 ;
struct V_185 * V_185 ;
V_185 = F_255 ( V_310 ) ;
V_138 = F_249 ( V_138 ) ;
V_19 = F_226 ( V_2 ) ;
if ( F_45 ( V_19 ) )
goto V_311;
V_201 = F_14 ( V_19 ) ;
F_231 ( V_201 , V_282 , V_138 , V_275 ) ;
V_311:
if ( ! F_252 ( V_2 , V_185 , V_138 >> V_204 ) )
F_253 ( V_185 , F_247 ( V_138 ) ) ;
}
static int F_256 ( struct V_1 * V_2 , T_3 V_290 )
{
if ( ! F_257 ( V_2 , V_290 ) )
return 0 ;
return F_42 ( V_2 ) ;
}
static int F_258 ( struct V_1 * V_2 , T_8 V_282 )
{
return V_282 == V_278 ;
}
static int F_259 ( void )
{
struct V_8 * V_9 = NULL ;
struct V_312 * V_313 ;
F_189 ( & V_227 , V_142 ,
V_225 , V_226 ) ;
F_260 ( & V_227 . V_314 ,
& V_315 ) ;
V_313 = F_261 ( & V_227 ,
F_158 ( V_316 ) , F_158 ( V_317 ) ) ;
if ( ! V_313 ) {
F_55 ( L_33 ) ;
return - V_54 ;
}
V_313 = F_261 ( & V_227 ,
F_158 ( V_318 ) , F_158 ( V_319 ) ) ;
if ( ! V_313 ) {
F_55 ( L_34 ) ;
return - V_54 ;
}
F_262 (pdev) {
int V_48 ;
for ( V_48 = 0 ; V_48 < V_320 ; ++ V_48 ) {
struct V_321 * V_322 = & V_9 -> V_321 [ V_48 ] ;
if ( ! ( V_322 -> V_21 & V_323 ) )
continue;
V_313 = F_261 ( & V_227 ,
F_158 ( V_322 -> V_277 ) ,
F_158 ( V_322 -> V_324 ) ) ;
if ( ! V_313 ) {
F_55 ( L_35 ) ;
return - V_54 ;
}
}
}
return 0 ;
}
int T_10 F_263 ( void )
{
int V_164 , V_325 = 0 ;
V_164 = F_264 () ;
if ( V_164 )
return V_164 ;
V_164 = F_259 () ;
if ( V_164 )
return V_164 ;
V_325 = F_265 ( & V_326 , & V_327 ) ;
if ( V_325 )
return V_325 ;
#ifdef F_266
V_325 = F_265 ( & V_328 , & V_327 ) ;
if ( V_325 )
return V_325 ;
#endif
V_325 = F_265 ( & V_329 , & V_327 ) ;
if ( V_325 )
return V_325 ;
return 0 ;
}
int T_10 F_267 ( void )
{
V_330 = ( V_267 || V_331 ) ? 1 : 0 ;
V_332 = 1 ;
if ( ! V_330 )
V_58 = & V_265 ;
if ( V_285 )
F_26 ( L_36 ) ;
else
F_26 ( L_37 ) ;
return 0 ;
}
static void F_268 ( struct V_16 * V_19 )
{
struct V_23 * V_4 ;
unsigned long V_21 ;
F_166 ( & V_208 , V_21 ) ;
while ( ! F_269 ( & V_19 -> V_247 ) ) {
V_4 = F_270 ( & V_19 -> V_247 ,
struct V_23 , V_206 ) ;
F_219 ( V_4 ) ;
}
F_169 ( & V_208 , V_21 ) ;
}
static void F_271 ( struct V_16 * V_19 )
{
if ( ! V_19 )
return;
F_163 ( V_19 ) ;
if ( V_19 -> V_172 )
F_170 ( V_19 -> V_172 ) ;
F_186 ( V_19 ) ;
}
static int F_188 ( struct V_16 * V_19 )
{
F_272 ( & V_19 -> V_165 ) ;
F_273 ( & V_19 -> V_333 ) ;
V_19 -> V_172 = F_165 () ;
if ( ! V_19 -> V_172 )
return - V_54 ;
F_274 ( & V_19 -> V_247 ) ;
return 0 ;
}
static struct V_16 * F_275 ( void )
{
struct V_16 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_25 ) ;
if ( ! V_19 )
return NULL ;
if ( F_188 ( V_19 ) )
goto V_257;
F_161 ( V_19 ) ;
return V_19 ;
V_257:
F_186 ( V_19 ) ;
return NULL ;
}
static struct V_17 * F_276 ( unsigned type )
{
struct V_16 * V_334 ;
struct V_20 * V_335 ;
switch ( type ) {
case V_336 :
V_334 = F_275 () ;
if ( ! V_334 )
return NULL ;
V_334 -> V_177 = V_215 ;
V_334 -> V_179 = ( void * ) F_130 ( V_25 ) ;
if ( ! V_334 -> V_179 ) {
F_271 ( V_334 ) ;
return NULL ;
}
V_334 -> V_19 . V_337 . V_338 = 0 ;
V_334 -> V_19 . V_337 . V_339 = ~ 0ULL ;
V_334 -> V_19 . V_337 . V_340 = true ;
break;
case V_341 :
V_335 = F_187 () ;
if ( ! V_335 ) {
F_55 ( L_38 ) ;
return NULL ;
}
V_334 = & V_335 -> V_19 ;
break;
case V_268 :
V_334 = F_275 () ;
if ( ! V_334 )
return NULL ;
V_334 -> V_177 = V_212 ;
break;
default:
return NULL ;
}
return & V_334 -> V_19 ;
}
static void F_277 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
struct V_20 * V_201 ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 -> V_249 > 0 )
F_268 ( V_19 ) ;
F_15 ( V_19 -> V_249 != 0 ) ;
if ( ! V_18 )
return;
switch ( V_18 -> type ) {
case V_341 :
V_201 = F_14 ( V_19 ) ;
F_184 ( V_201 ) ;
break;
default:
if ( V_19 -> V_177 != V_212 )
F_172 ( V_19 ) ;
if ( V_19 -> V_21 & V_236 )
F_181 ( V_19 ) ;
F_271 ( V_19 ) ;
break;
}
}
static void F_278 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_41 . V_39 ;
struct V_38 * V_39 ;
int V_14 ;
if ( ! F_42 ( V_2 ) )
return;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
if ( V_24 -> V_19 != NULL )
F_51 ( V_2 ) ;
V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
return;
#ifdef F_88
if ( F_279 ( V_342 ) &&
( V_18 -> type == V_336 ) )
V_24 -> V_343 = 0 ;
#endif
F_111 ( V_39 ) ;
}
static int F_280 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
struct V_23 * V_24 ;
struct V_38 * V_39 ;
int V_164 ;
if ( ! F_42 ( V_2 ) )
return - V_15 ;
V_24 = V_2 -> V_41 . V_39 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
if ( ! V_39 )
return - V_15 ;
if ( V_24 -> V_19 )
F_51 ( V_2 ) ;
V_164 = F_217 ( V_2 , V_19 ) ;
#ifdef F_88
if ( F_279 ( V_342 ) ) {
if ( V_18 -> type == V_336 )
V_24 -> V_343 = 1 ;
else
V_24 -> V_343 = 0 ;
}
#endif
F_111 ( V_39 ) ;
return V_164 ;
}
static int F_281 ( struct V_17 * V_18 , unsigned long V_312 ,
T_9 V_134 , T_6 V_181 , int V_344 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
int V_190 = 0 ;
int V_164 ;
if ( V_19 -> V_177 == V_212 )
return - V_15 ;
if ( V_344 & V_345 )
V_190 |= V_195 ;
if ( V_344 & V_346 )
V_190 |= V_197 ;
F_282 ( & V_19 -> V_333 ) ;
V_164 = F_147 ( V_19 , V_312 , V_134 , V_181 , V_190 , V_25 ) ;
F_283 ( & V_19 -> V_333 ) ;
return V_164 ;
}
static T_6 F_284 ( struct V_17 * V_18 , unsigned long V_312 ,
T_6 V_181 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
T_6 V_200 ;
if ( V_19 -> V_177 == V_212 )
return - V_15 ;
F_282 ( & V_19 -> V_333 ) ;
V_200 = F_153 ( V_19 , V_312 , V_181 ) ;
F_283 ( & V_19 -> V_333 ) ;
F_126 ( V_19 ) ;
F_127 ( V_19 ) ;
return V_200 ;
}
static T_9 F_285 ( struct V_17 * V_18 ,
T_8 V_312 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_347 , V_348 ;
T_3 * V_176 , V_186 ;
if ( V_19 -> V_177 == V_212 )
return V_312 ;
V_176 = F_143 ( V_19 , V_312 , & V_348 ) ;
if ( ! V_176 || ! F_138 ( * V_176 ) )
return 0 ;
V_347 = V_348 - 1 ;
V_186 = * V_176 & V_349 ;
return ( V_186 & ~ V_347 ) | ( V_312 & V_347 ) ;
}
static bool F_286 ( enum V_350 V_351 )
{
switch ( V_351 ) {
case V_352 :
return true ;
case V_353 :
return ( V_354 == 1 ) ;
case V_355 :
return false ;
}
return false ;
}
static void F_287 ( struct V_1 * V_2 ,
struct V_356 * V_87 )
{
struct V_357 * V_358 ;
struct V_359 * V_4 ;
int V_14 ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 < 0 )
return;
F_9 (entry, &amd_iommu_unity_map, list) {
T_6 V_296 ;
int V_190 = 0 ;
if ( V_14 < V_4 -> V_360 || V_14 > V_4 -> V_361 )
continue;
V_296 = V_4 -> V_362 - V_4 -> V_363 ;
if ( V_4 -> V_190 & V_195 )
V_190 |= V_345 ;
if ( V_4 -> V_190 & V_197 )
V_190 |= V_346 ;
V_358 = F_288 ( V_4 -> V_363 ,
V_296 , V_190 ,
V_364 ) ;
if ( ! V_358 ) {
F_55 ( L_39 ,
F_30 ( V_2 ) ) ;
return;
}
F_19 ( & V_358 -> V_206 , V_87 ) ;
}
V_358 = F_288 ( V_316 ,
V_317 - V_316 + 1 ,
0 , V_365 ) ;
if ( ! V_358 )
return;
F_19 ( & V_358 -> V_206 , V_87 ) ;
V_358 = F_288 ( V_318 ,
V_319 - V_318 + 1 ,
0 , V_366 ) ;
if ( ! V_358 )
return;
F_19 ( & V_358 -> V_206 , V_87 ) ;
}
static void F_289 ( struct V_1 * V_2 ,
struct V_356 * V_87 )
{
struct V_357 * V_4 , * V_367 ;
F_290 (entry, next, head, list)
F_186 ( V_4 ) ;
}
static void F_291 ( struct V_1 * V_2 ,
struct V_17 * V_19 ,
struct V_357 * V_358 )
{
struct V_20 * V_201 = F_14 ( F_12 ( V_19 ) ) ;
unsigned long V_277 , V_324 ;
V_277 = F_158 ( V_358 -> V_277 ) ;
V_324 = F_158 ( V_358 -> V_277 + V_358 -> V_296 ) ;
F_292 ( F_261 ( & V_201 -> V_203 , V_277 , V_324 ) == NULL ) ;
}
static bool F_293 ( struct V_17 * V_19 ,
struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_41 . V_39 ;
return V_24 -> V_40 ;
}
int F_294 ( struct V_368 * V_369 )
{
return F_295 ( & V_102 , V_369 ) ;
}
int F_296 ( struct V_368 * V_369 )
{
return F_297 ( & V_102 , V_369 ) ;
}
void F_298 ( struct V_17 * V_18 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
F_18 ( & V_19 -> V_165 , V_21 ) ;
V_19 -> V_177 = V_212 ;
V_19 -> V_180 = true ;
F_152 ( V_19 ) ;
F_172 ( V_19 ) ;
F_20 ( & V_19 -> V_165 , V_21 ) ;
}
int F_299 ( struct V_17 * V_18 , int V_370 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_371 , V_164 ;
if ( V_370 <= 0 || V_370 > ( V_372 + 1 ) )
return - V_15 ;
for ( V_371 = 0 ; ( V_370 - 1 ) & ~ 0x1ff ; V_370 >>= 9 )
V_371 += 1 ;
if ( V_371 > V_373 )
return - V_15 ;
F_18 ( & V_19 -> V_165 , V_21 ) ;
V_164 = - V_192 ;
if ( V_19 -> V_249 > 0 || V_19 -> V_21 & V_236 )
goto V_266;
V_164 = - V_54 ;
V_19 -> V_222 = ( void * ) F_130 ( V_279 ) ;
if ( V_19 -> V_222 == NULL )
goto V_266;
V_19 -> V_221 = V_371 ;
V_19 -> V_21 |= V_236 ;
V_19 -> V_180 = true ;
F_152 ( V_19 ) ;
V_164 = 0 ;
V_266:
F_20 ( & V_19 -> V_165 , V_21 ) ;
return V_164 ;
}
static int F_300 ( struct V_16 * V_19 , int V_99 ,
T_3 V_63 , bool V_138 )
{
struct V_23 * V_24 ;
struct V_60 V_61 ;
int V_48 , V_164 ;
if ( ! ( V_19 -> V_21 & V_236 ) )
return - V_15 ;
F_103 ( & V_61 , V_19 -> V_172 , V_99 , V_63 , V_138 ) ;
for ( V_48 = 0 ; V_48 < F_123 () ; ++ V_48 ) {
if ( V_19 -> V_173 [ V_48 ] == 0 )
continue;
V_164 = F_110 ( V_174 [ V_48 ] , & V_61 ) ;
if ( V_164 != 0 )
goto V_266;
}
F_127 ( V_19 ) ;
F_9 (dev_data, &domain->dev_list, list) {
struct V_38 * V_39 ;
int V_148 ;
if ( ! V_24 -> V_170 . V_171 )
continue;
V_148 = V_24 -> V_170 . V_148 ;
V_39 = V_35 [ V_24 -> V_14 ] ;
F_104 ( & V_61 , V_24 -> V_14 , V_99 ,
V_148 , V_63 , V_138 ) ;
V_164 = F_110 ( V_39 , & V_61 ) ;
if ( V_164 != 0 )
goto V_266;
}
F_127 ( V_19 ) ;
V_164 = 0 ;
V_266:
return V_164 ;
}
static int F_301 ( struct V_16 * V_19 , int V_99 ,
T_3 V_63 )
{
return F_300 ( V_19 , V_99 , V_63 , false ) ;
}
int F_302 ( struct V_17 * V_18 , int V_99 ,
T_3 V_63 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_164 ;
F_18 ( & V_19 -> V_165 , V_21 ) ;
V_164 = F_301 ( V_19 , V_99 , V_63 ) ;
F_20 ( & V_19 -> V_165 , V_21 ) ;
return V_164 ;
}
static int F_303 ( struct V_16 * V_19 , int V_99 )
{
return F_300 ( V_19 , V_99 , V_143 ,
true ) ;
}
int F_304 ( struct V_17 * V_18 , int V_99 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_164 ;
F_18 ( & V_19 -> V_165 , V_21 ) ;
V_164 = F_303 ( V_19 , V_99 ) ;
F_20 ( & V_19 -> V_165 , V_21 ) ;
return V_164 ;
}
static T_3 * F_305 ( T_3 * V_211 , int V_183 , int V_99 , bool V_374 )
{
int V_248 ;
T_3 * V_176 ;
while ( true ) {
V_248 = ( V_99 >> ( 9 * V_183 ) ) & 0x1ff ;
V_176 = & V_211 [ V_248 ] ;
if ( V_183 == 0 )
break;
if ( ! ( * V_176 & V_220 ) ) {
if ( ! V_374 )
return NULL ;
V_211 = ( void * ) F_130 ( V_279 ) ;
if ( V_211 == NULL )
return NULL ;
* V_176 = F_94 ( V_211 ) | V_220 ;
}
V_211 = F_57 ( * V_176 & V_144 ) ;
V_183 -= 1 ;
}
return V_176 ;
}
static int F_306 ( struct V_16 * V_19 , int V_99 ,
unsigned long V_375 )
{
T_3 * V_176 ;
if ( V_19 -> V_177 != V_212 )
return - V_15 ;
V_176 = F_305 ( V_19 -> V_222 , V_19 -> V_221 , V_99 , true ) ;
if ( V_176 == NULL )
return - V_54 ;
* V_176 = ( V_375 & V_144 ) | V_220 ;
return F_303 ( V_19 , V_99 ) ;
}
static int F_307 ( struct V_16 * V_19 , int V_99 )
{
T_3 * V_176 ;
if ( V_19 -> V_177 != V_212 )
return - V_15 ;
V_176 = F_305 ( V_19 -> V_222 , V_19 -> V_221 , V_99 , false ) ;
if ( V_176 == NULL )
return 0 ;
* V_176 = 0 ;
return F_303 ( V_19 , V_99 ) ;
}
int F_308 ( struct V_17 * V_18 , int V_99 ,
unsigned long V_375 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_164 ;
F_18 ( & V_19 -> V_165 , V_21 ) ;
V_164 = F_306 ( V_19 , V_99 , V_375 ) ;
F_20 ( & V_19 -> V_165 , V_21 ) ;
return V_164 ;
}
int F_309 ( struct V_17 * V_18 , int V_99 )
{
struct V_16 * V_19 = F_12 ( V_18 ) ;
unsigned long V_21 ;
int V_164 ;
F_18 ( & V_19 -> V_165 , V_21 ) ;
V_164 = F_307 ( V_19 , V_99 ) ;
F_20 ( & V_19 -> V_165 , V_21 ) ;
return V_164 ;
}
int F_310 ( struct V_8 * V_9 , int V_99 ,
int V_119 , int V_101 )
{
struct V_23 * V_24 ;
struct V_38 * V_39 ;
struct V_60 V_61 ;
V_24 = F_34 ( & V_9 -> V_2 ) ;
V_39 = V_35 [ V_24 -> V_14 ] ;
F_105 ( & V_61 , V_24 -> V_14 , V_99 , V_119 ,
V_101 , V_24 -> V_262 ) ;
return F_110 ( V_39 , & V_61 ) ;
}
struct V_17 * F_311 ( struct V_8 * V_9 )
{
struct V_16 * V_334 ;
V_334 = F_226 ( & V_9 -> V_2 ) ;
if ( F_45 ( V_334 ) )
return NULL ;
if ( ! ( V_334 -> V_21 & V_236 ) )
return NULL ;
return & V_334 -> V_19 ;
}
void F_312 ( struct V_8 * V_9 , T_2 V_50 )
{
struct V_23 * V_24 ;
if ( ! F_313 () )
return;
V_24 = F_34 ( & V_9 -> V_2 ) ;
V_24 -> V_51 |= ( 1 << V_50 ) ;
}
int F_314 ( struct V_8 * V_9 ,
struct F_314 * V_376 )
{
int V_377 ;
int V_49 ;
if ( V_9 == NULL || V_376 == NULL )
return - V_15 ;
if ( ! F_313 () )
return - V_15 ;
memset ( V_376 , 0 , sizeof( * V_376 ) ) ;
V_49 = F_40 ( V_9 , V_45 ) ;
if ( V_49 )
V_376 -> V_21 |= V_378 ;
V_49 = F_40 ( V_9 , V_46 ) ;
if ( V_49 )
V_376 -> V_21 |= V_379 ;
V_49 = F_40 ( V_9 , V_47 ) ;
if ( V_49 ) {
int V_380 ;
V_377 = 1 << ( 9 * ( V_373 + 1 ) ) ;
V_377 = F_315 ( V_377 , ( 1 << 20 ) ) ;
V_376 -> V_21 |= V_381 ;
V_376 -> V_377 = F_315 ( F_316 ( V_9 ) , V_377 ) ;
V_380 = F_317 ( V_9 ) ;
if ( V_380 & V_382 )
V_376 -> V_21 |= V_383 ;
if ( V_380 & V_384 )
V_376 -> V_21 |= V_385 ;
}
return 0 ;
}
static void F_318 ( T_1 V_14 , struct V_386 * V_387 )
{
T_3 V_388 ;
V_388 = V_36 [ V_14 ] . V_31 [ 2 ] ;
V_388 &= ~ V_389 ;
V_388 |= F_94 ( V_387 -> V_387 ) ;
V_388 |= V_390 ;
V_388 |= V_391 ;
V_388 |= V_392 ;
V_36 [ V_14 ] . V_31 [ 2 ] = V_388 ;
}
static struct V_386 * F_319 ( T_1 V_14 , bool V_393 )
{
struct V_386 * V_387 = NULL ;
struct V_38 * V_39 ;
unsigned long V_21 ;
T_1 V_30 ;
F_166 ( & V_208 , V_21 ) ;
V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
goto V_29;
V_387 = V_394 [ V_14 ] ;
if ( V_387 )
goto V_29;
V_30 = V_34 [ V_14 ] ;
V_387 = V_394 [ V_30 ] ;
if ( V_387 ) {
V_394 [ V_14 ] = V_387 ;
F_318 ( V_14 , V_387 ) ;
F_112 ( V_39 , V_14 ) ;
goto V_266;
}
V_387 = F_17 ( sizeof( * V_387 ) , V_279 ) ;
if ( ! V_387 )
goto V_29;
F_272 ( & V_387 -> V_165 ) ;
if ( V_393 )
V_387 -> V_395 = 32 ;
V_387 -> V_387 = F_320 ( V_396 , V_279 ) ;
if ( ! V_387 -> V_387 ) {
F_186 ( V_387 ) ;
V_387 = NULL ;
goto V_29;
}
if ( ! F_321 ( V_342 ) )
memset ( V_387 -> V_387 , 0 ,
V_397 * sizeof( T_2 ) ) ;
else
memset ( V_387 -> V_387 , 0 ,
( V_397 * ( sizeof( T_3 ) * 2 ) ) ) ;
if ( V_393 ) {
int V_48 ;
for ( V_48 = 0 ; V_48 < 32 ; ++ V_48 )
V_39 -> V_398 -> V_399 ( V_387 , V_48 ) ;
}
V_394 [ V_14 ] = V_387 ;
F_318 ( V_14 , V_387 ) ;
F_112 ( V_39 , V_14 ) ;
if ( V_14 != V_30 ) {
V_394 [ V_30 ] = V_387 ;
F_318 ( V_30 , V_387 ) ;
F_112 ( V_39 , V_30 ) ;
}
V_266:
F_111 ( V_39 ) ;
V_29:
F_169 ( & V_208 , V_21 ) ;
return V_387 ;
}
static int F_322 ( T_1 V_14 , int V_67 )
{
struct V_386 * V_387 ;
unsigned long V_21 ;
int V_248 , V_400 ;
struct V_38 * V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
return - V_7 ;
V_387 = F_319 ( V_14 , false ) ;
if ( ! V_387 )
return - V_7 ;
F_18 ( & V_387 -> V_165 , V_21 ) ;
for ( V_400 = 0 , V_248 = V_387 -> V_395 ;
V_248 < V_397 ;
++ V_248 ) {
if ( ! V_39 -> V_398 -> V_401 ( V_387 , V_248 ) )
V_400 += 1 ;
else
V_400 = 0 ;
if ( V_400 == V_67 ) {
for (; V_400 != 0 ; -- V_400 )
V_39 -> V_398 -> V_399 ( V_387 , V_248 - V_400 + 1 ) ;
V_248 -= V_67 - 1 ;
goto V_266;
}
}
V_248 = - V_402 ;
V_266:
F_20 ( & V_387 -> V_165 , V_21 ) ;
return V_248 ;
}
static int F_323 ( T_1 V_14 , int V_248 , struct V_403 * V_404 ,
struct V_405 * V_31 )
{
struct V_386 * V_387 ;
struct V_38 * V_39 ;
unsigned long V_21 ;
struct V_403 * V_4 ;
V_39 = V_35 [ V_14 ] ;
if ( V_39 == NULL )
return - V_15 ;
V_387 = F_319 ( V_14 , false ) ;
if ( ! V_387 )
return - V_54 ;
F_18 ( & V_387 -> V_165 , V_21 ) ;
V_4 = (struct V_403 * ) V_387 -> V_387 ;
V_4 = & V_4 [ V_248 ] ;
V_4 -> V_406 . V_407 . V_408 = 0 ;
V_4 -> V_409 . V_313 = V_404 -> V_409 . V_313 ;
V_4 -> V_406 . V_313 = V_404 -> V_406 . V_313 ;
V_4 -> V_406 . V_407 . V_408 = 1 ;
if ( V_31 )
V_31 -> V_410 = V_4 ;
F_20 ( & V_387 -> V_165 , V_21 ) ;
F_116 ( V_39 , V_14 ) ;
F_111 ( V_39 ) ;
return 0 ;
}
static int F_324 ( T_1 V_14 , int V_248 , union V_404 * V_404 )
{
struct V_386 * V_387 ;
struct V_38 * V_39 ;
unsigned long V_21 ;
V_39 = V_35 [ V_14 ] ;
if ( V_39 == NULL )
return - V_15 ;
V_387 = F_319 ( V_14 , false ) ;
if ( ! V_387 )
return - V_54 ;
F_18 ( & V_387 -> V_165 , V_21 ) ;
V_387 -> V_387 [ V_248 ] = V_404 -> V_313 ;
F_20 ( & V_387 -> V_165 , V_21 ) ;
F_116 ( V_39 , V_14 ) ;
F_111 ( V_39 ) ;
return 0 ;
}
static void F_325 ( T_1 V_14 , int V_248 )
{
struct V_386 * V_387 ;
struct V_38 * V_39 ;
unsigned long V_21 ;
V_39 = V_35 [ V_14 ] ;
if ( V_39 == NULL )
return;
V_387 = F_319 ( V_14 , false ) ;
if ( ! V_387 )
return;
F_18 ( & V_387 -> V_165 , V_21 ) ;
V_39 -> V_398 -> V_411 ( V_387 , V_248 ) ;
F_20 ( & V_387 -> V_165 , V_21 ) ;
F_116 ( V_39 , V_14 ) ;
F_111 ( V_39 ) ;
}
static void F_326 ( void * V_4 ,
T_2 V_412 , T_2 V_413 ,
T_5 V_414 , T_2 V_415 , int V_14 )
{
union V_404 * V_404 = (union V_404 * ) V_4 ;
V_404 -> V_313 = 0 ;
V_404 -> V_416 . V_414 = V_414 ;
V_404 -> V_416 . V_417 = V_412 ;
V_404 -> V_416 . V_418 = V_415 ;
V_404 -> V_416 . V_419 = V_413 ;
V_404 -> V_416 . V_408 = 1 ;
}
static void F_327 ( void * V_4 ,
T_2 V_412 , T_2 V_413 ,
T_5 V_414 , T_2 V_415 , int V_14 )
{
struct V_403 * V_404 = (struct V_403 * ) V_4 ;
V_404 -> V_406 . V_313 = 0 ;
V_404 -> V_409 . V_313 = 0 ;
V_404 -> V_406 . V_407 . V_417 = V_412 ;
V_404 -> V_406 . V_407 . V_419 = V_413 ;
V_404 -> V_409 . V_416 . V_414 = V_414 ;
V_404 -> V_406 . V_407 . V_418 = V_415 ;
V_404 -> V_406 . V_407 . V_408 = 1 ;
}
static void F_328 ( void * V_4 , T_1 V_14 , T_1 V_248 )
{
union V_404 * V_404 = (union V_404 * ) V_4 ;
V_404 -> V_416 . V_408 = 1 ;
F_324 ( V_14 , V_248 , V_404 ) ;
}
static void F_329 ( void * V_4 , T_1 V_14 , T_1 V_248 )
{
struct V_403 * V_404 = (struct V_403 * ) V_4 ;
V_404 -> V_406 . V_407 . V_408 = 1 ;
F_323 ( V_14 , V_248 , V_404 , NULL ) ;
}
static void F_330 ( void * V_4 , T_1 V_14 , T_1 V_248 )
{
union V_404 * V_404 = (union V_404 * ) V_4 ;
V_404 -> V_416 . V_408 = 0 ;
F_324 ( V_14 , V_248 , V_404 ) ;
}
static void F_331 ( void * V_4 , T_1 V_14 , T_1 V_248 )
{
struct V_403 * V_404 = (struct V_403 * ) V_4 ;
V_404 -> V_406 . V_407 . V_408 = 0 ;
F_323 ( V_14 , V_248 , V_404 , NULL ) ;
}
static void F_332 ( void * V_4 , T_1 V_14 , T_1 V_248 ,
T_5 V_414 , T_2 V_415 )
{
union V_404 * V_404 = (union V_404 * ) V_4 ;
V_404 -> V_416 . V_414 = V_414 ;
V_404 -> V_416 . V_418 = V_415 ;
F_324 ( V_14 , V_248 , V_404 ) ;
}
static void F_333 ( void * V_4 , T_1 V_14 , T_1 V_248 ,
T_5 V_414 , T_2 V_415 )
{
struct V_403 * V_404 = (struct V_403 * ) V_4 ;
struct V_23 * V_24 = F_22 ( V_14 ) ;
if ( ! V_24 || ! V_24 -> V_343 ||
! V_404 -> V_406 . V_407 . V_420 ) {
V_404 -> V_409 . V_416 . V_414 = V_414 ;
V_404 -> V_406 . V_407 . V_418 = V_415 ;
F_323 ( V_14 , V_248 , V_404 , NULL ) ;
}
}
static void F_334 ( struct V_386 * V_387 , int V_248 )
{
V_387 -> V_387 [ V_248 ] = V_421 ;
}
static void F_335 ( struct V_386 * V_387 , int V_248 )
{
struct V_403 * V_219 = (struct V_403 * ) V_387 -> V_387 ;
struct V_403 * V_404 = & V_219 [ V_248 ] ;
memset ( & V_404 -> V_406 . V_313 , 0 , sizeof( T_3 ) ) ;
memset ( & V_404 -> V_409 . V_313 , 0 , sizeof( T_3 ) ) ;
V_404 -> V_409 . V_416 . V_414 = 0xff ;
}
static bool F_336 ( struct V_386 * V_387 , int V_248 )
{
union V_404 * V_219 = (union V_404 * ) V_387 -> V_387 ;
union V_404 * V_404 = & V_219 [ V_248 ] ;
return V_404 -> V_313 != 0 ;
}
static bool F_337 ( struct V_386 * V_387 , int V_248 )
{
struct V_403 * V_219 = (struct V_403 * ) V_387 -> V_387 ;
struct V_403 * V_404 = & V_219 [ V_248 ] ;
return V_404 -> V_409 . V_416 . V_414 != 0 ;
}
static void F_338 ( struct V_386 * V_387 , int V_248 )
{
V_387 -> V_387 [ V_248 ] = 0 ;
}
static void F_339 ( struct V_386 * V_387 , int V_248 )
{
struct V_403 * V_219 = (struct V_403 * ) V_387 -> V_387 ;
struct V_403 * V_404 = & V_219 [ V_248 ] ;
memset ( & V_404 -> V_406 . V_313 , 0 , sizeof( T_3 ) ) ;
memset ( & V_404 -> V_409 . V_313 , 0 , sizeof( T_3 ) ) ;
}
static int F_340 ( struct V_422 * V_376 )
{
int V_14 = - 1 ;
switch ( V_376 -> type ) {
case V_423 :
V_14 = F_341 ( V_376 -> V_424 ) ;
break;
case V_425 :
V_14 = F_342 ( V_376 -> V_426 ) ;
break;
case V_427 :
case V_428 :
V_14 = F_10 ( & V_376 -> V_429 -> V_2 ) ;
break;
default:
F_15 ( 1 ) ;
break;
}
return V_14 ;
}
static struct V_430 * F_343 ( struct V_422 * V_376 )
{
struct V_38 * V_39 ;
int V_14 ;
if ( ! V_376 )
return NULL ;
V_14 = F_340 ( V_376 ) ;
if ( V_14 >= 0 ) {
V_39 = V_35 [ V_14 ] ;
if ( V_39 )
return V_39 -> V_431 ;
}
return NULL ;
}
static struct V_430 * F_344 ( struct V_422 * V_376 )
{
struct V_38 * V_39 ;
int V_14 ;
if ( ! V_376 )
return NULL ;
switch ( V_376 -> type ) {
case V_427 :
case V_428 :
V_14 = F_10 ( & V_376 -> V_429 -> V_2 ) ;
if ( V_14 < 0 )
return NULL ;
V_39 = V_35 [ V_14 ] ;
if ( V_39 )
return V_39 -> V_432 ;
break;
default:
break;
}
return NULL ;
}
static void F_345 ( struct V_405 * V_31 ,
struct V_433 * V_433 ,
struct V_422 * V_376 ,
int V_14 , int V_248 , int V_434 )
{
struct V_435 * V_436 = & V_31 -> V_435 ;
struct V_437 * V_438 = & V_31 -> V_439 ;
struct V_440 * V_4 ;
struct V_38 * V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
return;
V_31 -> V_435 . V_14 = V_14 ;
V_31 -> V_435 . V_248 = V_248 + V_434 ;
V_39 -> V_398 -> V_441 ( V_31 -> V_4 , V_442 -> V_443 ,
V_442 -> V_444 , V_433 -> V_414 ,
V_433 -> V_415 , V_14 ) ;
switch ( V_376 -> type ) {
case V_423 :
V_4 = V_376 -> V_445 ;
V_376 -> V_445 = NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_414 = V_248 ;
V_4 -> V_290 = 0 ;
V_4 -> V_446 = V_376 -> V_447 ;
V_4 -> V_448 = V_376 -> V_449 ;
if ( V_376 -> V_447 )
V_4 -> V_290 = 1 ;
break;
case V_425 :
case V_427 :
case V_428 :
V_438 -> V_450 = V_451 ;
V_438 -> V_452 = V_453 ;
V_438 -> V_31 = V_436 -> V_248 ;
break;
default:
F_15 ( 1 ) ;
break;
}
}
static int F_346 ( struct V_430 * V_19 , unsigned int V_454 ,
unsigned int V_455 , void * V_456 )
{
struct V_422 * V_376 = V_456 ;
struct V_457 * V_457 ;
struct V_405 * V_31 = NULL ;
struct V_433 * V_458 ;
int V_48 , V_164 , V_14 ;
int V_248 = - 1 ;
if ( ! V_376 )
return - V_15 ;
if ( V_455 > 1 && V_376 -> type != V_427 &&
V_376 -> type != V_428 )
return - V_15 ;
if ( V_376 -> type == V_427 )
V_376 -> V_21 &= ~ V_459 ;
V_14 = F_340 ( V_376 ) ;
if ( V_14 < 0 )
return - V_15 ;
V_164 = F_347 ( V_19 , V_454 , V_455 , V_456 ) ;
if ( V_164 < 0 )
return V_164 ;
if ( V_376 -> type == V_423 ) {
if ( F_319 ( V_14 , true ) )
V_248 = V_376 -> V_460 ;
else
V_164 = - V_54 ;
} else {
V_248 = F_322 ( V_14 , V_455 ) ;
}
if ( V_248 < 0 ) {
F_348 ( L_40 ) ;
V_164 = V_248 ;
goto V_461;
}
for ( V_48 = 0 ; V_48 < V_455 ; V_48 ++ ) {
V_457 = F_349 ( V_19 , V_454 + V_48 ) ;
V_458 = F_350 ( V_457 ) ;
if ( ! V_457 || ! V_458 ) {
V_164 = - V_15 ;
goto V_462;
}
V_164 = - V_54 ;
V_31 = F_17 ( sizeof( * V_31 ) , V_25 ) ;
if ( ! V_31 )
goto V_462;
if ( ! F_321 ( V_342 ) )
V_31 -> V_4 = F_17 ( sizeof( union V_404 ) , V_25 ) ;
else
V_31 -> V_4 = F_17 ( sizeof( struct V_403 ) ,
V_25 ) ;
if ( ! V_31 -> V_4 ) {
F_186 ( V_31 ) ;
goto V_462;
}
V_457 -> V_463 = ( V_14 << 16 ) + V_48 ;
V_457 -> V_464 = V_31 ;
V_457 -> V_465 = & V_466 ;
F_345 ( V_31 , V_458 , V_376 , V_14 , V_248 , V_48 ) ;
F_351 ( V_454 + V_48 , V_467 ) ;
}
return 0 ;
V_462:
for ( V_48 -- ; V_48 >= 0 ; V_48 -- ) {
V_457 = F_349 ( V_19 , V_454 + V_48 ) ;
if ( V_457 )
F_186 ( V_457 -> V_464 ) ;
}
for ( V_48 = 0 ; V_48 < V_455 ; V_48 ++ )
F_325 ( V_14 , V_248 + V_48 ) ;
V_461:
F_352 ( V_19 , V_454 , V_455 ) ;
return V_164 ;
}
static void F_353 ( struct V_430 * V_19 , unsigned int V_454 ,
unsigned int V_455 )
{
struct V_435 * V_436 ;
struct V_457 * V_457 ;
struct V_405 * V_31 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_455 ; V_48 ++ ) {
V_457 = F_349 ( V_19 , V_454 + V_48 ) ;
if ( V_457 && V_457 -> V_464 ) {
V_31 = V_457 -> V_464 ;
V_436 = & V_31 -> V_435 ;
F_325 ( V_436 -> V_14 , V_436 -> V_248 ) ;
F_186 ( V_31 -> V_4 ) ;
F_186 ( V_31 ) ;
}
}
F_352 ( V_19 , V_454 , V_455 ) ;
}
static void F_354 ( struct V_430 * V_19 ,
struct V_457 * V_457 )
{
struct V_405 * V_31 = V_457 -> V_464 ;
struct V_435 * V_436 = & V_31 -> V_435 ;
struct V_38 * V_39 = V_35 [ V_436 -> V_14 ] ;
if ( V_39 )
V_39 -> V_398 -> V_468 ( V_31 -> V_4 , V_436 -> V_14 ,
V_436 -> V_248 ) ;
}
static void F_355 ( struct V_430 * V_19 ,
struct V_457 * V_457 )
{
struct V_405 * V_31 = V_457 -> V_464 ;
struct V_435 * V_436 = & V_31 -> V_435 ;
struct V_38 * V_39 = V_35 [ V_436 -> V_14 ] ;
if ( V_39 )
V_39 -> V_398 -> V_469 ( V_31 -> V_4 , V_436 -> V_14 ,
V_436 -> V_248 ) ;
}
static int F_356 ( struct V_457 * V_31 , void * V_470 )
{
struct V_38 * V_39 ;
struct V_471 * V_472 = V_470 ;
struct V_473 * V_474 = V_472 -> V_473 ;
struct V_405 * V_475 = V_31 -> V_464 ;
struct V_403 * V_404 = (struct V_403 * ) V_475 -> V_4 ;
struct V_435 * V_436 = & V_475 -> V_435 ;
struct V_23 * V_24 = F_22 ( V_436 -> V_14 ) ;
if ( ! V_24 || ! V_24 -> V_343 )
return 0 ;
V_472 -> V_475 = V_475 ;
if ( ! F_279 ( V_342 ) ) {
F_83 ( L_41 ,
V_117 ) ;
V_472 -> V_476 = false ;
}
V_39 = V_35 [ V_436 -> V_14 ] ;
if ( V_39 == NULL )
return - V_15 ;
V_472 -> V_477 = V_475 -> V_478 ;
if ( V_472 -> V_476 ) {
V_404 -> V_409 . V_416 . V_479 = ( V_472 -> V_480 >> 12 ) ;
V_404 -> V_409 . V_416 . V_414 = V_474 -> V_414 ;
V_404 -> V_406 . V_481 . V_482 = 1 ;
V_404 -> V_406 . V_481 . V_420 = 1 ;
V_404 -> V_406 . V_481 . V_483 = V_472 -> V_483 ;
V_475 -> V_478 = V_472 -> V_483 ;
} else {
struct V_433 * V_458 = F_350 ( V_31 ) ;
V_404 -> V_409 . V_313 = 0 ;
V_404 -> V_406 . V_313 = 0 ;
V_404 -> V_409 . V_416 . V_414 = V_458 -> V_414 ;
V_404 -> V_406 . V_407 . V_420 = 0 ;
V_404 -> V_406 . V_407 . V_418 = V_458 -> V_415 ;
V_404 -> V_406 . V_407 . V_417 = V_442 -> V_443 ;
V_404 -> V_406 . V_407 . V_419 = V_442 -> V_444 ;
V_475 -> V_478 = 0 ;
}
return F_323 ( V_436 -> V_14 , V_436 -> V_248 , V_404 , V_475 ) ;
}
static int F_357 ( struct V_457 * V_31 ,
const struct V_484 * V_290 , bool V_485 )
{
struct V_405 * V_475 = V_31 -> V_464 ;
struct V_435 * V_436 = & V_475 -> V_435 ;
struct V_433 * V_458 = F_350 ( V_31 ) ;
struct V_457 * V_486 = V_31 -> V_487 ;
struct V_38 * V_39 = V_35 [ V_436 -> V_14 ] ;
int V_164 ;
if ( ! V_39 )
return - V_7 ;
V_164 = V_486 -> V_465 -> V_488 ( V_486 , V_290 , V_485 ) ;
if ( V_164 < 0 || V_164 == V_489 )
return V_164 ;
V_39 -> V_398 -> V_490 ( V_475 -> V_4 , V_436 -> V_14 ,
V_436 -> V_248 , V_458 -> V_414 , V_458 -> V_415 ) ;
F_358 ( V_458 ) ;
return V_489 ;
}
static void F_359 ( struct V_457 * V_457 , struct V_437 * V_438 )
{
struct V_405 * V_475 = V_457 -> V_464 ;
* V_438 = V_475 -> V_439 ;
}
int F_360 ( struct V_38 * V_39 )
{
struct V_491 * V_492 ;
V_492 = F_361 ( L_42 , V_39 -> V_248 ) ;
if ( ! V_492 )
return - V_54 ;
V_39 -> V_431 = F_362 ( V_492 , & V_493 , V_39 ) ;
F_363 ( V_492 ) ;
if ( ! V_39 -> V_431 )
return - V_54 ;
V_39 -> V_431 -> V_486 = F_364 () ;
V_39 -> V_432 = F_365 ( V_39 -> V_431 ,
L_43 ,
V_39 -> V_248 ) ;
return 0 ;
}
int F_366 ( int V_494 , bool V_495 , void * V_31 )
{
unsigned long V_21 ;
struct V_38 * V_39 ;
struct V_386 * V_496 ;
struct V_405 * V_475 = (struct V_405 * ) V_31 ;
int V_14 = V_475 -> V_435 . V_14 ;
struct V_403 * V_4 = (struct V_403 * ) V_475 -> V_4 ;
struct V_403 * V_410 = (struct V_403 * ) V_475 -> V_410 ;
if ( ! F_279 ( V_342 ) ||
! V_410 || ! V_4 || ! V_4 -> V_406 . V_481 . V_420 )
return 0 ;
V_39 = V_35 [ V_14 ] ;
if ( ! V_39 )
return - V_7 ;
V_496 = F_319 ( V_14 , false ) ;
if ( ! V_496 )
return - V_7 ;
F_18 ( & V_496 -> V_165 , V_21 ) ;
if ( V_410 -> V_406 . V_481 . V_420 ) {
if ( V_494 >= 0 )
V_410 -> V_406 . V_481 . V_418 = V_494 ;
V_410 -> V_406 . V_481 . V_495 = V_495 ;
F_367 () ;
}
F_20 ( & V_496 -> V_165 , V_21 ) ;
F_116 ( V_39 , V_14 ) ;
F_111 ( V_39 ) ;
return 0 ;
}
