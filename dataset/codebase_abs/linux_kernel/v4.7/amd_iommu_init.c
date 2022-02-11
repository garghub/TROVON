static inline void F_1 ( T_1 V_1 )
{
if ( V_1 > V_2 )
V_2 = V_1 ;
}
static inline unsigned long F_2 ( int V_3 )
{
unsigned V_4 = V_5 +
F_3 ( ( ( int ) V_2 + 1 ) * V_3 ) ;
return 1UL << V_4 ;
}
static T_2 F_4 ( struct V_6 * V_7 , T_1 V_8 , T_3 V_9 )
{
T_2 V_10 ;
F_5 ( V_7 -> V_11 , 0xf8 , ( V_9 | V_8 << 16 ) ) ;
F_6 ( V_7 -> V_11 , 0xfc , & V_10 ) ;
return V_10 ;
}
static void F_7 ( struct V_6 * V_7 , T_1 V_8 , T_3 V_9 , T_2 V_10 )
{
F_5 ( V_7 -> V_11 , 0xf8 , ( V_9 | V_8 << 16 | 1 << 31 ) ) ;
F_5 ( V_7 -> V_11 , 0xfc , V_10 ) ;
F_5 ( V_7 -> V_11 , 0xf8 , ( V_9 | V_8 << 16 ) ) ;
}
static T_2 F_8 ( struct V_6 * V_7 , T_3 V_9 )
{
T_2 V_10 ;
F_5 ( V_7 -> V_11 , 0xf0 , V_9 ) ;
F_6 ( V_7 -> V_11 , 0xf4 , & V_10 ) ;
return V_10 ;
}
static void F_9 ( struct V_6 * V_7 , T_3 V_9 , T_2 V_10 )
{
F_5 ( V_7 -> V_11 , 0xf0 , ( V_9 | 1 << 8 ) ) ;
F_5 ( V_7 -> V_11 , 0xf4 , V_10 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
T_4 V_12 = V_7 -> V_13 & V_14 ;
T_4 V_15 = ( V_12 + V_7 -> V_16 ) & V_14 ;
T_4 V_17 ;
if ( ! V_7 -> V_13 )
return;
V_17 = V_12 | V_18 ;
F_11 ( V_7 -> V_19 + V_20 ,
& V_17 , sizeof( V_17 ) ) ;
V_17 = V_15 ;
F_11 ( V_7 -> V_19 + V_21 ,
& V_17 , sizeof( V_17 ) ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_19 == NULL ) ;
V_17 = F_14 ( V_22 ) ;
V_17 |= ( V_23 >> 12 ) - 1 ;
F_11 ( V_7 -> V_19 + V_24 ,
& V_17 , sizeof( V_17 ) ) ;
}
static void F_15 ( struct V_6 * V_7 , T_3 V_25 )
{
T_2 V_26 ;
V_26 = F_16 ( V_7 -> V_19 + V_27 ) ;
V_26 |= ( 1 << V_25 ) ;
F_17 ( V_26 , V_7 -> V_19 + V_27 ) ;
}
static void F_18 ( struct V_6 * V_7 , T_3 V_25 )
{
T_2 V_26 ;
V_26 = F_16 ( V_7 -> V_19 + V_27 ) ;
V_26 &= ~ ( 1 << V_25 ) ;
F_17 ( V_26 , V_7 -> V_19 + V_27 ) ;
}
static void F_19 ( struct V_6 * V_7 , int V_28 )
{
T_2 V_26 ;
V_26 = F_16 ( V_7 -> V_19 + V_27 ) ;
V_26 &= ~ V_29 ;
V_26 |= ( V_28 << V_30 ) & V_29 ;
F_17 ( V_26 , V_7 -> V_19 + V_27 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
F_15 ( V_7 , V_31 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_32 ) ;
F_18 ( V_7 , V_33 ) ;
F_18 ( V_7 , V_34 ) ;
F_18 ( V_7 , V_31 ) ;
}
static T_3 T_5 * T_6 F_22 ( T_4 V_9 , T_4 V_35 )
{
if ( ! F_23 ( V_9 , V_35 , L_1 ) ) {
F_24 ( L_2 ,
V_9 , V_35 ) ;
F_24 ( L_3 ) ;
return NULL ;
}
return ( T_3 T_5 * ) F_25 ( V_9 , V_35 ) ;
}
static void T_6 F_26 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 )
F_27 ( V_7 -> V_19 ) ;
F_28 ( V_7 -> V_36 , V_7 -> V_37 ) ;
}
static inline T_2 F_29 ( struct V_38 * V_39 )
{
T_2 V_40 = 0 ;
switch ( V_39 -> type ) {
case 0x10 :
V_40 = 24 ;
break;
case 0x11 :
case 0x40 :
V_40 = 40 ;
break;
}
return V_40 ;
}
static inline int F_30 ( T_3 * V_41 )
{
T_2 type = ( (struct V_42 * ) V_41 ) -> type ;
if ( type < 0x80 ) {
return 0x04 << ( * V_41 >> 6 ) ;
} else if ( type == V_43 ) {
return * ( ( T_3 * ) V_41 + 21 ) + 22 ;
}
return 0 ;
}
static int T_6 F_31 ( struct V_38 * V_39 )
{
T_3 * V_44 = ( void * ) V_39 , * V_35 = ( void * ) V_39 ;
struct V_42 * V_11 ;
T_2 V_45 = F_29 ( V_39 ) ;
if ( ! V_45 ) {
F_24 ( L_4 , V_39 -> type ) ;
return - V_46 ;
}
V_44 += V_45 ;
V_35 += V_39 -> V_47 ;
while ( V_44 < V_35 ) {
V_11 = (struct V_42 * ) V_44 ;
switch ( V_11 -> type ) {
case V_48 :
F_1 ( 0xffff ) ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_1 ( V_11 -> V_1 ) ;
break;
default:
break;
}
V_44 += F_30 ( V_44 ) ;
}
F_32 ( V_44 != V_35 ) ;
return 0 ;
}
static int T_6 F_33 ( struct V_53 * V_54 )
{
int V_55 ;
T_3 V_56 = 0 , * V_44 = ( T_3 * ) V_54 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_47 ; ++ V_55 )
V_56 += V_44 [ V_55 ] ;
if ( V_56 != 0 ) {
F_24 ( V_57 L_5 ) ;
return - V_58 ;
}
return 0 ;
}
static int T_6 F_34 ( struct V_53 * V_54 )
{
T_3 * V_44 = ( T_3 * ) V_54 , * V_35 = ( T_3 * ) V_54 ;
struct V_38 * V_39 ;
V_44 += V_59 ;
V_35 += V_54 -> V_47 ;
while ( V_44 < V_35 ) {
V_39 = (struct V_38 * ) V_44 ;
if ( V_39 -> type == V_60 ) {
int V_61 = F_31 ( V_39 ) ;
if ( V_61 )
return V_61 ;
}
V_44 += V_39 -> V_47 ;
}
F_32 ( V_44 != V_35 ) ;
return 0 ;
}
static int T_6 F_35 ( struct V_6 * V_7 )
{
V_7 -> V_62 = ( void * ) F_36 ( V_63 | V_64 ,
F_3 ( V_65 ) ) ;
return V_7 -> V_62 ? 0 : - V_66 ;
}
void F_37 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_32 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_67 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_68 ) ;
F_15 ( V_7 , V_32 ) ;
}
static void F_38 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_62 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_62 ) ;
V_17 |= V_69 ;
F_11 ( V_7 -> V_19 + V_70 ,
& V_17 , sizeof( V_17 ) ) ;
F_37 ( V_7 ) ;
}
static void T_6 F_39 ( struct V_6 * V_7 )
{
F_40 ( ( unsigned long ) V_7 -> V_62 , F_3 ( V_65 ) ) ;
}
static int T_6 F_41 ( struct V_6 * V_7 )
{
V_7 -> V_71 = ( void * ) F_36 ( V_63 | V_64 ,
F_3 ( V_72 ) ) ;
return V_7 -> V_71 ? 0 : - V_66 ;
}
static void F_42 ( struct V_6 * V_7 )
{
T_4 V_17 ;
F_13 ( V_7 -> V_71 == NULL ) ;
V_17 = ( T_4 ) F_14 ( V_7 -> V_71 ) | V_73 ;
F_11 ( V_7 -> V_19 + V_74 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_75 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_76 ) ;
F_15 ( V_7 , V_34 ) ;
}
static void T_6 F_43 ( struct V_6 * V_7 )
{
F_40 ( ( unsigned long ) V_7 -> V_71 , F_3 ( V_72 ) ) ;
}
static int T_6 F_44 ( struct V_6 * V_7 )
{
V_7 -> V_77 = ( void * ) F_36 ( V_63 | V_64 ,
F_3 ( V_78 ) ) ;
return V_7 -> V_77 ? 0 : - V_66 ;
}
static void F_45 ( struct V_6 * V_7 )
{
T_4 V_17 ;
if ( V_7 -> V_77 == NULL )
return;
V_17 = ( T_4 ) F_14 ( V_7 -> V_77 ) | V_79 ;
F_11 ( V_7 -> V_19 + V_80 ,
& V_17 , sizeof( V_17 ) ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_81 ) ;
F_17 ( 0x00 , V_7 -> V_19 + V_82 ) ;
F_15 ( V_7 , V_83 ) ;
F_15 ( V_7 , V_84 ) ;
}
static void T_6 F_46 ( struct V_6 * V_7 )
{
if ( V_7 -> V_77 == NULL )
return;
F_40 ( ( unsigned long ) V_7 -> V_77 , F_3 ( V_78 ) ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
if ( ! F_48 ( V_7 , V_85 ) )
return;
F_15 ( V_7 , V_86 ) ;
}
static void F_49 ( T_1 V_1 , T_3 V_25 )
{
int V_55 = ( V_25 >> 6 ) & 0x03 ;
int V_87 = V_25 & 0x3f ;
V_22 [ V_1 ] . V_88 [ V_55 ] |= ( 1UL << V_87 ) ;
}
static int F_50 ( T_1 V_1 , T_3 V_25 )
{
int V_55 = ( V_25 >> 6 ) & 0x03 ;
int V_87 = V_25 & 0x3f ;
return ( V_22 [ V_1 ] . V_88 [ V_55 ] & ( 1UL << V_87 ) ) >> V_87 ;
}
void F_51 ( T_1 V_1 )
{
int V_89 ;
V_89 = F_50 ( V_1 , V_90 ) |
( F_50 ( V_1 , V_91 ) << 1 ) ;
if ( V_89 == 0x01 )
F_49 ( V_1 , V_92 ) ;
}
static void T_6 F_52 ( struct V_6 * V_7 , T_1 V_1 )
{
V_93 [ V_1 ] = V_7 ;
}
static void T_6 F_53 ( struct V_6 * V_7 ,
T_1 V_1 , T_2 V_94 , T_2 V_95 )
{
if ( V_94 & V_96 )
F_49 ( V_1 , V_97 ) ;
if ( V_94 & V_98 )
F_49 ( V_1 , V_99 ) ;
if ( V_94 & V_100 )
F_49 ( V_1 , V_101 ) ;
if ( V_94 & V_102 )
F_49 ( V_1 , V_90 ) ;
if ( V_94 & V_103 )
F_49 ( V_1 , V_91 ) ;
if ( V_94 & V_104 )
F_49 ( V_1 , V_105 ) ;
if ( V_94 & V_106 )
F_49 ( V_1 , V_107 ) ;
F_51 ( V_1 ) ;
F_52 ( V_7 , V_1 ) ;
}
static int T_6 F_54 ( T_3 type , T_3 V_108 , T_1 * V_1 , bool V_109 )
{
struct V_110 * V_17 ;
struct V_111 * V_112 ;
if ( type == V_113 )
V_112 = & V_114 ;
else if ( type == V_115 )
V_112 = & V_116 ;
else
return - V_46 ;
F_55 (entry, list, list) {
if ( ! ( V_17 -> V_108 == V_108 && V_17 -> V_109 ) )
continue;
F_56 ( L_6 ,
type == V_113 ? L_7 : L_8 , V_108 ) ;
* V_1 = V_17 -> V_1 ;
return 0 ;
}
V_17 = F_57 ( sizeof( * V_17 ) , V_63 ) ;
if ( ! V_17 )
return - V_66 ;
V_17 -> V_108 = V_108 ;
V_17 -> V_1 = * V_1 ;
V_17 -> V_109 = V_109 ;
F_58 ( & V_17 -> V_112 , V_112 ) ;
return 0 ;
}
static int T_6 F_59 ( T_3 * V_117 , T_3 * V_118 , T_1 * V_1 ,
bool V_109 )
{
struct V_119 * V_17 ;
struct V_111 * V_112 = & V_120 ;
F_55 (entry, list, list) {
if ( strcmp ( V_17 -> V_117 , V_117 ) ||
( * V_118 && * V_17 -> V_118 && strcmp ( V_17 -> V_118 , V_118 ) ) ||
! V_17 -> V_109 )
continue;
F_56 ( L_9 ,
V_117 , V_118 ) ;
* V_1 = V_17 -> V_1 ;
return 0 ;
}
V_17 = F_57 ( sizeof( * V_17 ) , V_63 ) ;
if ( ! V_17 )
return - V_66 ;
memcpy ( V_17 -> V_118 , V_118 , strlen ( V_118 ) ) ;
memcpy ( V_17 -> V_117 , V_117 , strlen ( V_117 ) ) ;
V_17 -> V_1 = * V_1 ;
V_17 -> V_109 = V_109 ;
V_17 -> V_121 = ( V_17 -> V_1 & ( ~ 0x7 ) ) ;
F_56 ( L_10 ,
V_17 -> V_109 ? L_11 : L_12 ,
V_17 -> V_117 , V_17 -> V_118 , V_17 -> V_121 ) ;
F_58 ( & V_17 -> V_112 , V_112 ) ;
return 0 ;
}
static int T_6 F_60 ( void )
{
int V_55 , V_61 ;
for ( V_55 = 0 ; V_55 < V_122 ; ++ V_55 ) {
V_61 = F_54 ( V_113 ,
V_123 [ V_55 ] . V_108 ,
& V_123 [ V_55 ] . V_1 ,
V_123 [ V_55 ] . V_109 ) ;
if ( V_61 )
return V_61 ;
}
for ( V_55 = 0 ; V_55 < V_124 ; ++ V_55 ) {
V_61 = F_54 ( V_115 ,
V_125 [ V_55 ] . V_108 ,
& V_125 [ V_55 ] . V_1 ,
V_125 [ V_55 ] . V_109 ) ;
if ( V_61 )
return V_61 ;
}
for ( V_55 = 0 ; V_55 < V_126 ; ++ V_55 ) {
V_61 = F_59 ( V_127 [ V_55 ] . V_117 ,
V_127 [ V_55 ] . V_118 ,
& V_127 [ V_55 ] . V_1 ,
V_127 [ V_55 ] . V_109 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static void T_6 F_61 ( T_1 V_1 , struct V_128 * V_129 )
{
struct V_6 * V_7 = V_93 [ V_1 ] ;
if ( ! ( V_129 -> V_94 & V_130 ) )
return;
if ( V_7 ) {
F_49 ( V_1 , V_131 ) ;
V_7 -> V_13 = V_129 -> V_132 ;
V_7 -> V_16 = V_129 -> V_133 ;
}
}
static int T_6 F_62 ( struct V_6 * V_7 ,
struct V_38 * V_39 )
{
T_3 * V_44 = ( T_3 * ) V_39 ;
T_3 * V_35 = V_44 , V_94 = 0 ;
T_1 V_1 = 0 , V_134 = 0 , V_135 = 0 ;
T_2 V_136 , V_95 = 0 ;
bool V_137 = false ;
struct V_42 * V_138 ;
T_2 V_45 ;
int V_61 ;
V_61 = F_60 () ;
if ( V_61 )
return V_61 ;
V_7 -> V_139 = V_39 -> V_94 ;
V_45 = F_29 ( V_39 ) ;
if ( ! V_45 ) {
F_24 ( L_4 , V_39 -> type ) ;
return - V_46 ;
}
V_44 += V_45 ;
V_35 += V_39 -> V_47 ;
while ( V_44 < V_35 ) {
V_138 = (struct V_42 * ) V_44 ;
switch ( V_138 -> type ) {
case V_48 :
F_63 ( L_13 , V_138 -> V_94 ) ;
for ( V_136 = 0 ; V_136 <= V_2 ; ++ V_136 )
F_53 ( V_7 , V_136 , V_138 -> V_94 , 0 ) ;
break;
case V_49 :
F_63 ( L_14
L_15 ,
F_64 ( V_138 -> V_1 ) ,
F_65 ( V_138 -> V_1 ) ,
F_66 ( V_138 -> V_1 ) ,
V_138 -> V_94 ) ;
V_1 = V_138 -> V_1 ;
F_53 ( V_7 , V_1 , V_138 -> V_94 , 0 ) ;
break;
case V_140 :
F_63 ( L_16
L_17 ,
F_64 ( V_138 -> V_1 ) ,
F_65 ( V_138 -> V_1 ) ,
F_66 ( V_138 -> V_1 ) ,
V_138 -> V_94 ) ;
V_134 = V_138 -> V_1 ;
V_94 = V_138 -> V_94 ;
V_95 = 0 ;
V_137 = false ;
break;
case V_51 :
F_63 ( L_18
L_19 ,
F_64 ( V_138 -> V_1 ) ,
F_65 ( V_138 -> V_1 ) ,
F_66 ( V_138 -> V_1 ) ,
V_138 -> V_94 ,
F_64 ( V_138 -> V_141 >> 8 ) ,
F_65 ( V_138 -> V_141 >> 8 ) ,
F_66 ( V_138 -> V_141 >> 8 ) ) ;
V_1 = V_138 -> V_1 ;
V_135 = V_138 -> V_141 >> 8 ;
F_53 ( V_7 , V_1 , V_138 -> V_94 , 0 ) ;
F_53 ( V_7 , V_135 , V_138 -> V_94 , 0 ) ;
V_142 [ V_1 ] = V_135 ;
break;
case V_143 :
F_63 ( L_20
L_21
L_22 ,
F_64 ( V_138 -> V_1 ) ,
F_65 ( V_138 -> V_1 ) ,
F_66 ( V_138 -> V_1 ) ,
V_138 -> V_94 ,
F_64 ( V_138 -> V_141 >> 8 ) ,
F_65 ( V_138 -> V_141 >> 8 ) ,
F_66 ( V_138 -> V_141 >> 8 ) ) ;
V_134 = V_138 -> V_1 ;
V_94 = V_138 -> V_94 ;
V_135 = V_138 -> V_141 >> 8 ;
V_95 = 0 ;
V_137 = true ;
break;
case V_52 :
F_63 ( L_23
L_24 ,
F_64 ( V_138 -> V_1 ) ,
F_65 ( V_138 -> V_1 ) ,
F_66 ( V_138 -> V_1 ) ,
V_138 -> V_94 , V_138 -> V_141 ) ;
V_1 = V_138 -> V_1 ;
F_53 ( V_7 , V_1 , V_138 -> V_94 ,
V_138 -> V_141 ) ;
break;
case V_144 :
F_63 ( L_25
L_26 ,
F_64 ( V_138 -> V_1 ) ,
F_65 ( V_138 -> V_1 ) ,
F_66 ( V_138 -> V_1 ) ,
V_138 -> V_94 , V_138 -> V_141 ) ;
V_134 = V_138 -> V_1 ;
V_94 = V_138 -> V_94 ;
V_95 = V_138 -> V_141 ;
V_137 = false ;
break;
case V_50 :
F_63 ( L_27 ,
F_64 ( V_138 -> V_1 ) ,
F_65 ( V_138 -> V_1 ) ,
F_66 ( V_138 -> V_1 ) ) ;
V_1 = V_138 -> V_1 ;
for ( V_136 = V_134 ; V_136 <= V_1 ; ++ V_136 ) {
if ( V_137 ) {
V_142 [ V_136 ] = V_135 ;
F_53 ( V_7 ,
V_135 , V_94 , V_95 ) ;
}
F_53 ( V_7 , V_136 ,
V_94 , V_95 ) ;
}
break;
case V_145 : {
T_3 V_146 , type ;
const char * V_147 ;
T_1 V_1 ;
int V_61 ;
V_146 = V_138 -> V_141 & 0xff ;
V_1 = ( V_138 -> V_141 >> 8 ) & 0xffff ;
type = ( V_138 -> V_141 >> 24 ) & 0xff ;
if ( type == V_113 )
V_147 = L_7 ;
else if ( type == V_115 )
V_147 = L_8 ;
else
V_147 = L_28 ;
F_63 ( L_29 ,
V_147 , ( int ) V_146 ,
F_64 ( V_1 ) ,
F_65 ( V_1 ) ,
F_66 ( V_1 ) ) ;
V_61 = F_54 ( type , V_146 , & V_1 , false ) ;
if ( V_61 )
return V_61 ;
F_53 ( V_7 , V_1 , V_138 -> V_94 , 0 ) ;
break;
}
case V_43 : {
T_1 V_1 ;
T_3 V_117 [ V_148 ] = { 0 } ;
T_3 V_118 [ V_149 ] = { 0 } ;
int V_61 ;
if ( V_39 -> type != 0x40 ) {
F_24 ( V_57 L_30 ,
V_138 -> type ) ;
break;
}
memcpy ( V_117 , ( T_3 * ) ( & V_138 -> V_141 ) , V_148 - 1 ) ;
V_117 [ V_148 - 1 ] = '\0' ;
if ( ! ( * V_117 ) ) {
F_24 ( V_57 L_31 ) ;
break;
}
switch ( V_138 -> V_150 ) {
case V_151 :
if ( V_138 -> V_152 != 0 )
F_67 ( V_57 L_32 ) ;
break;
case V_153 :
sprintf ( V_118 , L_33 , V_138 -> V_118 ) ;
break;
case V_154 :
memcpy ( V_118 , ( T_3 * ) ( & V_138 -> V_118 ) , V_149 - 1 ) ;
V_118 [ V_149 - 1 ] = '\0' ;
break;
default:
break;
}
V_1 = V_138 -> V_1 ;
F_63 ( L_34 ,
V_117 , V_118 ,
F_64 ( V_1 ) ,
F_65 ( V_1 ) ,
F_66 ( V_1 ) ) ;
V_94 = V_138 -> V_94 ;
V_61 = F_59 ( V_117 , V_118 , & V_1 , false ) ;
if ( V_61 )
return V_61 ;
F_53 ( V_7 , V_1 , V_138 -> V_94 , 0 ) ;
break;
}
default:
break;
}
V_44 += F_30 ( V_44 ) ;
}
return 0 ;
}
static void T_6 F_68 ( struct V_6 * V_7 )
{
F_39 ( V_7 ) ;
F_43 ( V_7 ) ;
F_46 ( V_7 ) ;
F_26 ( V_7 ) ;
}
static void T_6 F_69 ( void )
{
struct V_6 * V_7 , * V_155 ;
F_70 (iommu, next) {
F_71 ( & V_7 -> V_112 ) ;
F_68 ( V_7 ) ;
F_72 ( V_7 ) ;
}
}
static void F_73 ( struct V_6 * V_7 )
{
T_2 V_156 ;
if ( ( V_157 . V_158 != 0x15 ) ||
( V_157 . V_159 < 0x10 ) ||
( V_157 . V_159 > 0x1f ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
F_6 ( V_7 -> V_11 , 0xf4 , & V_156 ) ;
if ( V_156 & F_74 ( 2 ) )
return;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 | ( 1 << 8 ) ) ;
F_5 ( V_7 -> V_11 , 0xf4 , V_156 | 0x4 ) ;
F_56 ( L_35 ,
F_75 ( & V_7 -> V_11 -> V_11 ) ) ;
F_5 ( V_7 -> V_11 , 0xf0 , 0x90 ) ;
}
static void F_76 ( struct V_6 * V_7 )
{
T_2 V_156 ;
if ( ( V_157 . V_158 != 0x15 ) ||
( V_157 . V_159 < 0x30 ) ||
( V_157 . V_159 > 0x3f ) )
return;
V_156 = F_8 ( V_7 , 0x47 ) ;
if ( V_156 & F_74 ( 0 ) )
return;
F_9 ( V_7 , 0x47 , V_156 | F_74 ( 0 ) ) ;
F_56 ( L_36 ,
F_75 ( & V_7 -> V_11 -> V_11 ) ) ;
}
static int T_6 F_77 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
int V_61 ;
F_78 ( & V_7 -> V_160 ) ;
F_58 ( & V_7 -> V_112 , & V_161 ) ;
V_7 -> V_162 = V_163 ++ ;
if ( F_79 ( V_7 -> V_162 >= V_164 ) ) {
F_80 ( 1 , L_37 ) ;
return - V_165 ;
}
V_166 [ V_7 -> V_162 ] = V_7 ;
V_7 -> V_1 = V_39 -> V_1 ;
V_7 -> V_167 = V_39 -> V_167 ;
V_7 -> V_168 = V_39 -> V_168 ;
V_7 -> V_36 = V_39 -> V_36 ;
switch ( V_39 -> type ) {
case 0x10 :
if ( ( V_39 -> V_169 != 0 ) &&
( ( V_39 -> V_169 & ( 0xF << 13 ) ) != 0 ) &&
( ( V_39 -> V_169 & ( 0x3F << 17 ) ) != 0 ) )
V_7 -> V_37 = V_170 ;
else
V_7 -> V_37 = V_171 ;
break;
case 0x11 :
case 0x40 :
if ( V_39 -> V_172 & ( 1 << 9 ) )
V_7 -> V_37 = V_170 ;
else
V_7 -> V_37 = V_171 ;
break;
default:
return - V_46 ;
}
V_7 -> V_19 = F_22 ( V_7 -> V_36 ,
V_7 -> V_37 ) ;
if ( ! V_7 -> V_19 )
return - V_66 ;
if ( F_35 ( V_7 ) )
return - V_66 ;
if ( F_41 ( V_7 ) )
return - V_66 ;
V_7 -> V_173 = false ;
V_61 = F_62 ( V_7 , V_39 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_81 ( V_7 ) ;
if ( V_61 )
return V_61 ;
V_93 [ V_7 -> V_1 ] = NULL ;
return 0 ;
}
static T_3 F_82 ( struct V_53 * V_174 )
{
T_3 * V_175 = ( T_3 * ) V_174 ;
struct V_38 * V_41 = (struct V_38 * )
( V_175 + V_59 ) ;
T_3 V_176 = V_41 -> type ;
T_1 V_1 = V_41 -> V_1 ;
while ( ( ( T_3 * ) V_41 - V_175 < V_174 -> V_47 ) &&
( V_41 -> type <= V_177 ) ) {
T_3 * V_44 = ( T_3 * ) V_41 ;
if ( V_41 -> V_1 == V_1 )
V_176 = V_41 -> type ;
V_41 = (struct V_38 * ) ( V_44 + V_41 -> V_47 ) ;
}
return V_176 ;
}
static int T_6 F_83 ( struct V_53 * V_54 )
{
T_3 * V_44 = ( T_3 * ) V_54 , * V_35 = ( T_3 * ) V_54 ;
struct V_38 * V_39 ;
struct V_6 * V_7 ;
int V_61 ;
V_35 += V_54 -> V_47 ;
V_44 += V_59 ;
while ( V_44 < V_35 ) {
V_39 = (struct V_38 * ) V_44 ;
if ( * V_44 == V_60 ) {
F_63 ( L_38
L_39 ,
F_64 ( V_39 -> V_1 ) , F_65 ( V_39 -> V_1 ) ,
F_66 ( V_39 -> V_1 ) , V_39 -> V_167 ,
V_39 -> V_168 , V_39 -> V_94 , V_39 -> V_178 ) ;
F_63 ( L_40 ,
V_39 -> V_36 ) ;
V_7 = F_57 ( sizeof( struct V_6 ) , V_63 ) ;
if ( V_7 == NULL )
return - V_66 ;
V_61 = F_77 ( V_7 , V_39 ) ;
if ( V_61 )
return V_61 ;
}
V_44 += V_39 -> V_47 ;
}
F_32 ( V_44 != V_35 ) ;
return 0 ;
}
static void F_84 ( struct V_6 * V_7 )
{
T_4 V_10 = 0xabcd , V_179 = 0 ;
if ( ! F_48 ( V_7 , V_180 ) )
return;
V_181 = true ;
if ( ( 0 != F_85 ( V_7 , 0 , 0 , 0 , & V_10 , true ) ) ||
( 0 != F_85 ( V_7 , 0 , 0 , 0 , & V_179 , false ) ) ||
( V_10 != V_179 ) ) {
F_24 ( L_41 ) ;
V_181 = false ;
return;
}
F_56 ( L_42 ) ;
V_10 = F_16 ( V_7 -> V_19 + V_171 ) ;
V_7 -> V_182 = ( T_3 ) ( ( V_10 >> 12 ) & 0x3f ) ;
V_7 -> V_183 = ( T_3 ) ( ( V_10 >> 7 ) & 0xf ) ;
}
static T_7 F_86 ( struct V_184 * V_11 ,
struct V_185 * V_186 ,
char * V_187 )
{
struct V_6 * V_7 = F_87 ( V_11 ) ;
return sprintf ( V_187 , L_43 , V_7 -> V_188 ) ;
}
static T_7 F_88 ( struct V_184 * V_11 ,
struct V_185 * V_186 ,
char * V_187 )
{
struct V_6 * V_7 = F_87 ( V_11 ) ;
return sprintf ( V_187 , L_44 , V_7 -> V_189 ) ;
}
static int F_89 ( struct V_6 * V_7 )
{
int V_167 = V_7 -> V_167 ;
T_2 V_190 , V_191 , V_192 , V_193 ;
V_7 -> V_11 = F_90 ( F_64 ( V_7 -> V_1 ) ,
V_7 -> V_1 & 0xff ) ;
if ( ! V_7 -> V_11 )
return - V_58 ;
V_7 -> V_11 -> V_194 = false ;
F_6 ( V_7 -> V_11 , V_167 + V_195 ,
& V_7 -> V_188 ) ;
F_6 ( V_7 -> V_11 , V_167 + V_196 ,
& V_190 ) ;
F_6 ( V_7 -> V_11 , V_167 + V_197 ,
& V_191 ) ;
if ( ! ( V_7 -> V_188 & ( 1 << V_198 ) ) )
V_199 = false ;
V_192 = F_16 ( V_7 -> V_19 + V_200 ) ;
V_193 = F_16 ( V_7 -> V_19 + V_200 + 4 ) ;
V_7 -> V_189 = ( ( T_4 ) V_193 << 32 ) | V_192 ;
if ( F_48 ( V_7 , V_85 ) ) {
int V_201 ;
T_2 V_202 ;
T_4 V_203 ;
V_203 = V_7 -> V_189 & V_204 ;
V_203 >>= V_205 ;
V_202 = ( 1 << ( V_203 + 1 ) ) - 1 ;
V_206 = F_91 ( V_206 , V_202 ) ;
F_13 ( V_206 & ~ V_207 ) ;
V_201 = V_7 -> V_189 & V_208 ;
V_201 >>= V_209 ;
if ( V_210 == - 1 )
V_210 = V_201 ;
else
V_210 = F_91 ( V_210 , V_201 ) ;
}
if ( F_48 ( V_7 , V_85 ) &&
F_48 ( V_7 , V_211 ) ) {
V_7 -> V_212 = true ;
V_213 = true ;
}
if ( F_48 ( V_7 , V_211 ) && F_44 ( V_7 ) )
return - V_66 ;
if ( V_7 -> V_188 & ( 1UL << V_214 ) )
V_215 = true ;
F_84 ( V_7 ) ;
if ( F_92 ( V_7 -> V_11 ) ) {
int V_55 , V_216 ;
V_7 -> V_217 = F_90 ( V_7 -> V_11 -> V_218 -> V_219 ,
F_93 ( 0 , 0 ) ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_167 + 4 ,
& V_7 -> V_220 ) ;
F_6 ( V_7 -> V_11 , V_7 -> V_167 + 8 ,
& V_7 -> V_221 ) ;
V_7 -> V_220 &= ~ 1 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_216 = 0 ; V_216 < 0x12 ; V_216 ++ )
V_7 -> V_222 [ V_55 ] [ V_216 ] = F_4 ( V_7 , V_55 , V_216 ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
V_7 -> V_223 [ V_55 ] = F_8 ( V_7 , V_55 ) ;
}
F_73 ( V_7 ) ;
F_76 ( V_7 ) ;
V_7 -> V_224 = F_94 ( & V_7 -> V_11 -> V_11 , V_7 ,
V_225 , L_45 ,
V_7 -> V_162 ) ;
return F_95 ( V_7 -> V_11 ) ;
}
static void F_96 ( void )
{
static const char * const V_226 [] = {
L_46 , L_47 , L_48 , L_49 , L_50 , L_51 ,
L_52 , L_53 , L_54 , L_55
} ;
struct V_6 * V_7 ;
F_97 (iommu) {
int V_55 ;
F_56 ( L_56 ,
F_75 ( & V_7 -> V_11 -> V_11 ) , V_7 -> V_167 ) ;
if ( V_7 -> V_188 & ( 1 << V_227 ) ) {
F_56 ( L_57 ) ;
for ( V_55 = 0 ; V_55 < F_98 ( V_226 ) ; ++ V_55 ) {
if ( F_48 ( V_7 , ( 1ULL << V_55 ) ) )
F_99 ( L_58 , V_226 [ V_55 ] ) ;
}
F_99 ( L_59 ) ;
}
}
if ( V_228 )
F_56 ( L_60 ) ;
}
static int T_6 F_100 ( void )
{
struct V_6 * V_7 ;
int V_61 = 0 ;
F_97 (iommu) {
V_61 = F_89 ( V_7 ) ;
if ( V_61 )
break;
}
V_61 = F_101 () ;
F_102 () ;
F_97 (iommu)
F_103 ( V_7 ) ;
if ( ! V_61 )
F_96 () ;
return V_61 ;
}
static int F_104 ( struct V_6 * V_7 )
{
int V_229 ;
V_229 = F_105 ( V_7 -> V_11 ) ;
if ( V_229 )
return V_229 ;
V_229 = F_106 ( V_7 -> V_11 -> V_230 ,
V_231 ,
V_232 ,
0 , L_61 ,
V_7 ) ;
if ( V_229 ) {
F_107 ( V_7 -> V_11 ) ;
return V_229 ;
}
V_7 -> V_173 = true ;
return 0 ;
}
static int F_108 ( struct V_6 * V_7 )
{
int V_61 ;
if ( V_7 -> V_173 )
goto V_233;
if ( V_7 -> V_11 -> V_234 )
V_61 = F_104 ( V_7 ) ;
else
V_61 = - V_58 ;
if ( V_61 )
return V_61 ;
V_233:
F_15 ( V_7 , V_33 ) ;
if ( V_7 -> V_77 != NULL )
F_15 ( V_7 , V_235 ) ;
return 0 ;
}
static void T_6 F_109 ( void )
{
struct V_236 * V_17 , * V_155 ;
F_110 (entry, next, &amd_iommu_unity_map, list) {
F_71 ( & V_17 -> V_112 ) ;
F_72 ( V_17 ) ;
}
}
static int T_6 F_111 ( struct V_128 * V_129 )
{
int V_55 ;
switch ( V_129 -> type ) {
case V_237 :
F_61 ( V_129 -> V_1 , V_129 ) ;
break;
case V_238 :
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
F_61 ( V_55 , V_129 ) ;
break;
case V_239 :
for ( V_55 = V_129 -> V_1 ; V_55 <= V_129 -> V_240 ; ++ V_55 )
F_61 ( V_55 , V_129 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_6 F_112 ( struct V_128 * V_129 )
{
struct V_236 * V_138 = NULL ;
char * V_241 ;
V_138 = F_57 ( sizeof( * V_138 ) , V_63 ) ;
if ( V_138 == NULL )
return - V_66 ;
switch ( V_129 -> type ) {
default:
F_72 ( V_138 ) ;
return 0 ;
case V_237 :
V_241 = L_62 ;
V_138 -> V_134 = V_138 -> V_242 = V_129 -> V_1 ;
break;
case V_238 :
V_241 = L_63 ;
V_138 -> V_134 = 0 ;
V_138 -> V_242 = V_2 ;
break;
case V_239 :
V_241 = L_64 ;
V_138 -> V_134 = V_129 -> V_1 ;
V_138 -> V_242 = V_129 -> V_240 ;
break;
}
V_138 -> V_243 = F_113 ( V_129 -> V_132 ) ;
V_138 -> V_244 = V_138 -> V_243 + F_113 ( V_129 -> V_133 ) ;
V_138 -> V_245 = V_129 -> V_94 >> 1 ;
F_63 ( L_65
L_66 , V_241 ,
F_64 ( V_138 -> V_134 ) , F_65 ( V_138 -> V_134 ) ,
F_66 ( V_138 -> V_134 ) , F_64 ( V_138 -> V_242 ) ,
F_65 ( V_138 -> V_242 ) , F_66 ( V_138 -> V_242 ) ,
V_138 -> V_243 , V_138 -> V_244 , V_129 -> V_94 ) ;
F_58 ( & V_138 -> V_112 , & V_246 ) ;
return 0 ;
}
static int T_6 F_114 ( struct V_53 * V_54 )
{
T_3 * V_44 = ( T_3 * ) V_54 , * V_35 = ( T_3 * ) V_54 ;
struct V_128 * V_129 ;
V_35 += V_54 -> V_47 ;
V_44 += V_59 ;
while ( V_44 < V_35 ) {
V_129 = (struct V_128 * ) V_44 ;
if ( V_129 -> V_94 & V_130 )
F_111 ( V_129 ) ;
else if ( V_129 -> V_94 & V_247 )
F_112 ( V_129 ) ;
V_44 += V_129 -> V_47 ;
}
return 0 ;
}
static void F_102 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
F_49 ( V_1 , V_248 ) ;
F_49 ( V_1 , V_249 ) ;
}
}
static void T_6 F_115 ( void )
{
T_2 V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 ) {
V_22 [ V_1 ] . V_88 [ 0 ] = 0ULL ;
V_22 [ V_1 ] . V_88 [ 1 ] = 0ULL ;
}
}
static void F_116 ( void )
{
T_2 V_1 ;
if ( ! V_250 )
return;
for ( V_1 = 0 ; V_1 <= V_2 ; ++ V_1 )
F_49 ( V_1 , V_251 ) ;
}
static void F_117 ( struct V_6 * V_7 )
{
V_7 -> V_139 & V_252 ?
F_15 ( V_7 , V_253 ) :
F_18 ( V_7 , V_253 ) ;
V_7 -> V_139 & V_254 ?
F_15 ( V_7 , V_255 ) :
F_18 ( V_7 , V_255 ) ;
V_7 -> V_139 & V_256 ?
F_15 ( V_7 , V_257 ) :
F_18 ( V_7 , V_257 ) ;
V_7 -> V_139 & V_258 ?
F_15 ( V_7 , V_259 ) :
F_18 ( V_7 , V_259 ) ;
F_15 ( V_7 , V_260 ) ;
F_19 ( V_7 , V_261 ) ;
}
static void F_118 ( struct V_6 * V_7 )
{
int V_55 , V_216 ;
T_2 V_262 ;
struct V_263 * V_264 = V_7 -> V_217 ;
if ( ! F_92 ( V_7 -> V_11 ) || ! V_264 )
return;
F_5 ( V_264 , 0x60 , 0x75 | ( 1 << 7 ) ) ;
F_6 ( V_264 , 0x64 , & V_262 ) ;
if ( ! ( V_262 & 0x1 ) )
F_5 ( V_264 , 0x64 , V_262 | 1 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_167 + 4 ,
V_7 -> V_220 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_167 + 8 ,
V_7 -> V_221 ) ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
for ( V_216 = 0 ; V_216 < 0x12 ; V_216 ++ )
F_7 ( V_7 , V_55 , V_216 , V_7 -> V_222 [ V_55 ] [ V_216 ] ) ;
for ( V_55 = 0 ; V_55 < 0x83 ; V_55 ++ )
F_9 ( V_7 , V_55 , V_7 -> V_223 [ V_55 ] ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_167 + 4 ,
V_7 -> V_220 | 1 ) ;
}
static void F_119 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu) {
F_21 ( V_7 ) ;
F_117 ( V_7 ) ;
F_12 ( V_7 ) ;
F_38 ( V_7 ) ;
F_42 ( V_7 ) ;
F_10 ( V_7 ) ;
F_20 ( V_7 ) ;
F_103 ( V_7 ) ;
}
}
static void F_120 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu) {
F_45 ( V_7 ) ;
F_47 ( V_7 ) ;
}
}
static void F_121 ( void )
{
F_119 () ;
F_120 () ;
}
static void F_122 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu)
F_21 ( V_7 ) ;
}
static void F_123 ( void )
{
struct V_6 * V_7 ;
F_97 (iommu)
F_118 ( V_7 ) ;
F_121 () ;
F_124 () ;
}
static int F_125 ( void )
{
F_122 () ;
return 0 ;
}
static void T_6 F_126 ( void )
{
F_40 ( ( unsigned long ) V_265 ,
F_3 ( V_266 ) ) ;
F_127 ( V_267 ) ;
V_267 = NULL ;
F_40 ( ( unsigned long ) V_93 ,
F_3 ( V_266 ) ) ;
F_40 ( ( unsigned long ) V_142 ,
F_3 ( V_268 ) ) ;
F_40 ( ( unsigned long ) V_22 ,
F_3 ( V_23 ) ) ;
F_69 () ;
#ifdef F_128
F_129 () ;
#endif
}
static bool T_6 F_130 ( void )
{
const char * V_269 = V_57 ;
bool V_61 , V_270 ;
int V_271 ;
V_270 = false ;
V_61 = false ;
if ( V_272 )
V_269 = L_67 ;
for ( V_271 = 0 ; V_271 < V_273 ; V_271 ++ ) {
int V_1 , V_108 = F_131 ( V_271 ) ;
V_1 = F_132 ( V_108 ) ;
if ( V_1 < 0 ) {
F_24 ( L_68 ,
V_269 , V_108 ) ;
V_61 = false ;
} else if ( V_1 == V_274 ) {
V_270 = true ;
V_61 = true ;
}
}
if ( ! V_270 ) {
F_24 ( L_69 , V_269 ) ;
}
if ( ! V_61 )
F_24 ( L_70 ) ;
return V_61 ;
}
static void T_6 F_133 ( void )
{
F_40 ( ( unsigned long ) V_275 ,
F_3 ( V_276 / 8 ) ) ;
F_109 () ;
}
static int T_6 F_134 ( void )
{
struct V_53 * V_277 ;
T_8 V_278 ;
T_9 V_279 ;
int V_55 , V_61 = 0 ;
if ( ! V_280 )
return - V_58 ;
V_279 = F_135 ( L_71 , 0 , & V_277 , & V_278 ) ;
if ( V_279 == V_281 )
return - V_58 ;
else if ( F_136 ( V_279 ) ) {
const char * V_282 = F_137 ( V_279 ) ;
F_24 ( L_72 , V_282 ) ;
return - V_46 ;
}
V_61 = F_33 ( V_277 ) ;
if ( V_61 )
return V_61 ;
V_60 = F_82 ( V_277 ) ;
F_63 ( L_73 , V_60 ) ;
V_61 = F_34 ( V_277 ) ;
if ( V_61 )
goto V_283;
V_23 = F_2 ( V_284 ) ;
V_268 = F_2 ( V_285 ) ;
V_266 = F_2 ( V_286 ) ;
V_61 = - V_66 ;
V_22 = ( void * ) F_36 ( V_63 | V_64 ,
F_3 ( V_23 ) ) ;
if ( V_22 == NULL )
goto V_283;
V_142 = ( void * ) F_36 ( V_63 ,
F_3 ( V_268 ) ) ;
if ( V_142 == NULL )
goto V_283;
V_93 = ( void * ) F_36 (
V_63 | V_64 ,
F_3 ( V_266 ) ) ;
if ( V_93 == NULL )
goto V_283;
V_275 = ( void * ) F_36 (
V_63 | V_64 ,
F_3 ( V_276 / 8 ) ) ;
if ( V_275 == NULL )
goto V_283;
for ( V_55 = 0 ; V_55 <= V_2 ; ++ V_55 )
V_142 [ V_55 ] = V_55 ;
V_275 [ 0 ] = 1 ;
F_78 ( & V_287 ) ;
V_61 = F_83 ( V_277 ) ;
if ( V_61 )
goto V_283;
if ( V_250 )
V_250 = F_130 () ;
if ( V_250 ) {
V_61 = - V_66 ;
V_267 = F_138 ( L_74 ,
V_288 * sizeof( T_2 ) ,
V_289 ,
0 , NULL ) ;
if ( ! V_267 )
goto V_283;
V_265 = ( void * ) F_36 (
V_63 | V_64 ,
F_3 ( V_266 ) ) ;
if ( ! V_265 )
goto V_283;
}
V_61 = F_114 ( V_277 ) ;
if ( V_61 )
goto V_283;
F_116 () ;
V_283:
F_139 ( ( char T_5 * ) V_277 , V_278 ) ;
V_277 = NULL ;
return V_61 ;
}
static int F_124 ( void )
{
struct V_6 * V_7 ;
int V_61 = 0 ;
F_97 (iommu) {
V_61 = F_108 ( V_7 ) ;
if ( V_61 )
goto V_283;
}
V_283:
return V_61 ;
}
static bool F_140 ( void )
{
struct V_53 * V_277 ;
T_8 V_278 ;
T_9 V_279 ;
V_279 = F_135 ( L_71 , 0 , & V_277 , & V_278 ) ;
if ( V_279 == V_281 )
return false ;
else if ( F_136 ( V_279 ) ) {
const char * V_282 = F_137 ( V_279 ) ;
F_24 ( L_72 , V_282 ) ;
return false ;
}
F_139 ( ( char T_5 * ) V_277 , V_278 ) ;
F_141 () ;
return true ;
}
static int T_6 F_142 ( void )
{
int V_61 = 0 ;
switch ( V_290 ) {
case V_291 :
if ( ! F_140 () ) {
V_290 = V_292 ;
V_61 = - V_58 ;
} else {
V_290 = V_293 ;
}
break;
case V_293 :
V_61 = F_134 () ;
V_290 = V_61 ? V_294 : V_295 ;
break;
case V_295 :
F_119 () ;
F_143 ( & V_296 ) ;
V_297 . V_298 = F_122 ;
V_290 = V_299 ;
break;
case V_299 :
V_61 = F_100 () ;
V_290 = V_61 ? V_294 : V_300 ;
F_120 () ;
break;
case V_300 :
V_61 = F_124 () ;
V_290 = V_61 ? V_294 : V_301 ;
break;
case V_301 :
V_61 = F_144 () ;
V_290 = V_61 ? V_294 : V_302 ;
break;
case V_302 :
V_290 = V_303 ;
break;
case V_303 :
break;
case V_292 :
case V_294 :
V_61 = - V_46 ;
break;
default:
F_145 () ;
}
return V_61 ;
}
static int T_6 F_146 ( enum V_304 V_305 )
{
int V_61 = 0 ;
while ( V_290 != V_305 ) {
V_61 = F_142 () ;
if ( V_290 == V_292 ||
V_290 == V_294 )
break;
}
return V_61 ;
}
int T_6 F_147 ( void )
{
int V_61 ;
V_250 = true ;
V_61 = F_146 ( V_295 ) ;
if ( V_61 )
return V_61 ;
return V_250 ? 0 : - V_58 ;
}
int T_6 F_148 ( void )
{
int V_61 ;
V_61 = F_146 ( V_299 ) ;
if ( V_61 )
return V_61 ;
V_228 = 1 ;
return 0 ;
}
void F_149 ( void )
{
F_125 () ;
}
int F_150 ( int V_306 )
{
F_123 () ;
return 0 ;
}
int T_6 F_151 ( void )
{
return 0 ;
}
static int T_6 F_152 ( void )
{
int V_61 ;
V_61 = F_146 ( V_303 ) ;
if ( V_61 ) {
F_133 () ;
if ( ! V_228 ) {
F_122 () ;
F_126 () ;
} else {
struct V_6 * V_7 ;
F_115 () ;
F_97 (iommu)
F_103 ( V_7 ) ;
}
}
return V_61 ;
}
int T_6 F_153 ( void )
{
int V_61 ;
if ( V_307 || ( V_308 && ! V_309 ) )
return - V_58 ;
if ( V_310 )
return - V_58 ;
V_61 = F_146 ( V_293 ) ;
if ( V_61 )
return V_61 ;
V_280 = true ;
V_308 = 1 ;
V_311 . V_7 . V_312 = F_152 ;
return 1 ;
}
static int T_6 F_154 ( char * V_313 )
{
V_314 = true ;
return 1 ;
}
static int T_6 F_155 ( char * V_313 )
{
for (; * V_313 ; ++ V_313 ) {
if ( strncmp ( V_313 , L_75 , 9 ) == 0 )
V_315 = true ;
if ( strncmp ( V_313 , L_76 , 3 ) == 0 )
V_310 = true ;
if ( strncmp ( V_313 , L_77 , 15 ) == 0 )
V_316 = true ;
}
return 1 ;
}
static int T_6 F_156 ( char * V_313 )
{
unsigned int V_218 , V_11 , V_317 ;
int V_61 , V_108 , V_55 ;
T_1 V_1 ;
V_61 = sscanf ( V_313 , L_78 , & V_108 , & V_218 , & V_11 , & V_317 ) ;
if ( V_61 != 4 ) {
F_24 ( L_79 , V_313 ) ;
return 1 ;
}
if ( V_122 == V_318 ) {
F_24 ( L_80 ,
V_313 ) ;
return 1 ;
}
V_1 = ( ( V_218 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_317 & 0x7 ) ;
V_272 = true ;
V_55 = V_122 ++ ;
V_123 [ V_55 ] . V_108 = V_108 ;
V_123 [ V_55 ] . V_1 = V_1 ;
V_123 [ V_55 ] . V_109 = true ;
return 1 ;
}
static int T_6 F_157 ( char * V_313 )
{
unsigned int V_218 , V_11 , V_317 ;
int V_61 , V_108 , V_55 ;
T_1 V_1 ;
V_61 = sscanf ( V_313 , L_78 , & V_108 , & V_218 , & V_11 , & V_317 ) ;
if ( V_61 != 4 ) {
F_24 ( L_81 , V_313 ) ;
return 1 ;
}
if ( V_124 == V_318 ) {
F_24 ( L_82 ,
V_313 ) ;
return 1 ;
}
V_1 = ( ( V_218 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_317 & 0x7 ) ;
V_272 = true ;
V_55 = V_124 ++ ;
V_125 [ V_55 ] . V_108 = V_108 ;
V_125 [ V_55 ] . V_1 = V_1 ;
V_125 [ V_55 ] . V_109 = true ;
return 1 ;
}
static int T_6 F_158 ( char * V_313 )
{
T_2 V_218 , V_11 , V_317 ;
char * V_117 , * V_118 , * V_44 ;
char V_319 [ V_149 + V_148 ] = { 0 } ;
int V_61 , V_55 ;
V_61 = sscanf ( V_313 , L_83 , & V_218 , & V_11 , & V_317 , V_319 ) ;
if ( V_61 != 4 ) {
F_24 ( L_84 , V_313 ) ;
return 1 ;
}
V_44 = V_319 ;
V_117 = F_159 ( & V_44 , L_85 ) ;
V_118 = V_44 ;
if ( ! V_117 || ! ( * V_117 ) || ! V_118 ) {
F_24 ( L_86 ) ;
return 1 ;
}
V_55 = V_126 ++ ;
memcpy ( V_127 [ V_55 ] . V_117 , V_117 , strlen ( V_117 ) ) ;
memcpy ( V_127 [ V_55 ] . V_118 , V_118 , strlen ( V_118 ) ) ;
V_127 [ V_55 ] . V_1 =
( ( V_218 & 0xff ) << 8 ) | ( ( V_11 & 0x1f ) << 3 ) | ( V_317 & 0x7 ) ;
V_127 [ V_55 ] . V_109 = true ;
return 1 ;
}
bool F_160 ( void )
{
return V_213 ;
}
T_3 F_161 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_61 = 0 ;
V_7 = V_93 [ V_1 ] ;
if ( V_7 )
V_61 = V_7 -> V_182 ;
return V_61 ;
}
bool F_162 ( void )
{
return V_181 ;
}
T_3 F_163 ( T_1 V_1 )
{
struct V_6 * V_7 ;
T_3 V_61 = 0 ;
V_7 = V_93 [ V_1 ] ;
if ( V_7 )
V_61 = V_7 -> V_183 ;
return V_61 ;
}
static int F_85 ( struct V_6 * V_7 ,
T_3 V_320 , T_3 V_321 , T_3 V_322 ,
T_4 * V_156 , bool V_323 )
{
T_2 V_324 ;
T_2 V_325 ;
if ( F_32 ( ( V_322 > 0x28 ) || ( V_322 & 7 ) ) )
return - V_58 ;
V_324 = ( T_2 ) ( ( ( 0x40 | V_320 ) << 12 ) | ( V_321 << 8 ) | V_322 ) ;
V_325 = ( T_2 ) ( ( ( 0x40 | V_7 -> V_182 ) << 12 ) |
( V_7 -> V_183 << 8 ) | 0x28 ) ;
if ( ( V_324 < V_326 ) ||
( V_324 > V_325 ) )
return - V_46 ;
if ( V_323 ) {
F_17 ( ( T_2 ) * V_156 , V_7 -> V_19 + V_324 ) ;
F_17 ( ( * V_156 >> 32 ) , V_7 -> V_19 + V_324 + 4 ) ;
} else {
* V_156 = F_16 ( V_7 -> V_19 + V_324 + 4 ) ;
* V_156 <<= 32 ;
* V_156 = F_16 ( V_7 -> V_19 + V_324 ) ;
}
return 0 ;
}
int F_164 ( T_1 V_1 , T_3 V_320 , T_3 V_321 , T_3 V_322 ,
T_4 * V_156 , bool V_323 )
{
struct V_6 * V_7 = V_93 [ V_1 ] ;
if ( ! V_181 || V_7 == NULL )
return - V_58 ;
return F_85 ( V_7 , V_320 , V_321 , V_322 ,
V_156 , V_323 ) ;
}
