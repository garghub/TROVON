static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
int V_4 , V_5 ;
switch ( V_3 -> V_6 ) {
case V_7 :
V_4 = V_8 ;
break;
case V_9 :
V_4 = V_10 ;
break;
default:
return - V_11 ;
}
V_3 -> V_12 = 0xff ;
V_5 = F_2 ( V_2 , V_3 -> V_6 ,
( V_13 * ) V_3 , V_4 , V_14 ,
V_15 ) ;
return V_5 == V_4 ? 0 : - 1 ;
}
static int F_3 ( struct V_16 * V_17 ,
struct V_3 * V_18 ,
struct V_3 * V_19 )
{
int V_5 ;
F_4 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_19 ;
V_17 -> V_22 = false ;
* V_19 = * V_18 ;
V_5 = F_1 ( V_17 -> V_23 , V_18 ) ;
if ( V_5 ) {
F_5 ( L_1 , V_5 ) ;
memset ( V_19 , 0 , sizeof( struct V_3 ) ) ;
goto exit;
}
if ( ! F_6 ( V_17 -> V_24 , V_17 -> V_22 ,
5 * V_25 ) ) {
F_5 ( L_2 , V_26 ) ;
memset ( V_19 , 0 , sizeof( struct V_3 ) ) ;
V_5 = - V_27 ;
}
if ( V_19 -> V_6 == V_7 &&
V_19 -> V_28 . V_29 == V_30 ) {
V_5 = V_19 -> V_28 . V_31 [ 1 ] ;
F_5 ( L_3 , V_26 , V_5 ) ;
goto exit;
}
if ( V_19 -> V_6 == V_9 &&
V_19 -> V_32 . V_33 == V_34 ) {
V_5 = V_19 -> V_32 . V_31 [ 1 ] ;
F_5 ( L_4 , V_26 , V_5 ) ;
goto exit;
}
exit:
F_7 ( & V_17 -> V_20 ) ;
return V_5 ;
}
static int F_8 ( struct V_16 * V_17 ,
V_13 V_35 , V_13 V_36 , V_13 * V_31 , int V_37 ,
struct V_3 * V_19 )
{
struct V_3 * V_18 ;
int V_5 ;
if ( V_37 > sizeof( V_18 -> V_32 . V_31 ) )
return - V_38 ;
V_18 = F_9 ( sizeof( struct V_3 ) , V_39 ) ;
if ( ! V_18 )
return - V_40 ;
V_18 -> V_6 = V_9 ;
V_18 -> V_32 . V_33 = V_35 ;
V_18 -> V_32 . V_36 = V_36 ;
memcpy ( & V_18 -> V_32 . V_31 , V_31 , V_37 ) ;
V_5 = F_3 ( V_17 , V_18 , V_19 ) ;
F_10 ( V_18 ) ;
return V_5 ;
}
static int F_11 ( struct V_16 * V_41 ,
V_13 V_6 , V_13 V_29 , V_13 V_42 , V_13 * V_31 , int V_37 ,
struct V_3 * V_19 )
{
struct V_3 * V_18 ;
int V_5 ;
if ( ( V_6 != V_7 ) &&
( V_6 != V_9 ) )
return - V_38 ;
if ( V_37 > sizeof( V_18 -> V_28 . V_31 ) )
return - V_38 ;
V_18 = F_9 ( sizeof( struct V_3 ) , V_39 ) ;
if ( ! V_18 )
return - V_40 ;
V_18 -> V_6 = V_6 ;
V_18 -> V_28 . V_29 = V_29 ;
V_18 -> V_28 . V_42 = V_42 ;
memcpy ( & V_18 -> V_28 . V_31 , V_31 , V_37 ) ;
V_5 = F_3 ( V_41 , V_18 , V_19 ) ;
F_10 ( V_18 ) ;
return V_5 ;
}
static void F_12 ( struct V_43 * V_44 )
{
struct V_16 * V_17 = F_13 ( V_44 , struct V_16 ,
V_44 ) ;
F_14 ( V_17 ) ;
}
static inline bool F_15 ( struct V_3 * V_45 ,
struct V_3 * V_46 )
{
return ( V_46 -> V_32 . V_33 == V_45 -> V_32 . V_33 ) &&
( V_46 -> V_32 . V_36 == V_45 -> V_32 . V_36 ) ;
}
static inline bool F_16 ( struct V_3 * V_45 ,
struct V_3 * V_46 )
{
return ( ( V_46 -> V_28 . V_29 == V_30 ) ||
( V_46 -> V_32 . V_33 == V_34 ) ) &&
( V_46 -> V_32 . V_36 == V_45 -> V_32 . V_33 ) &&
( V_46 -> V_32 . V_31 [ 0 ] == V_45 -> V_32 . V_36 ) ;
}
static inline bool F_17 ( struct V_3 * V_47 )
{
return ( V_47 -> V_6 == V_7 ) &&
( V_47 -> V_28 . V_29 == 0x41 ) ;
}
static void F_18 ( char * * V_48 , int V_49 )
{
#define F_19 9
int V_50 ;
char * V_51 ;
if ( V_49 > F_19 &&
strncmp ( * V_48 , L_5 , F_19 ) == 0 )
return;
V_50 = F_19 + V_49 ;
V_51 = F_9 ( V_50 , V_39 ) ;
if ( ! V_51 )
return;
snprintf ( V_51 , V_50 , L_6 , * V_48 ) ;
F_10 ( * V_48 ) ;
* V_48 = V_51 ;
}
static char * F_20 ( struct V_16 * V_41 )
{
struct V_3 V_19 ;
int V_5 ;
V_13 V_31 [ 1 ] = { V_52 } ;
char * V_48 ;
int V_53 ;
V_5 = F_11 ( V_41 ,
V_7 ,
V_54 ,
V_55 ,
V_31 , 1 , & V_19 ) ;
if ( V_5 )
return NULL ;
V_53 = V_19 . V_28 . V_31 [ 1 ] ;
if ( 2 + V_53 > sizeof( V_19 . V_28 . V_31 ) )
return NULL ;
V_48 = F_9 ( V_53 + 1 , V_39 ) ;
if ( ! V_48 )
return NULL ;
memcpy ( V_48 , & V_19 . V_28 . V_31 [ 2 ] , V_53 ) ;
F_18 ( & V_48 , V_53 + 1 ) ;
return V_48 ;
}
static int F_21 ( struct V_16 * V_17 , T_1 V_56 ,
V_13 * V_33 , V_13 * V_57 )
{
struct V_3 V_19 ;
int V_5 ;
V_13 V_31 [ 2 ] = { V_56 >> 8 , V_56 & 0x00FF } ;
V_5 = F_8 ( V_17 ,
V_58 ,
V_59 ,
V_31 , 2 , & V_19 ) ;
if ( V_5 )
return V_5 ;
* V_33 = V_19 . V_32 . V_31 [ 0 ] ;
* V_57 = V_19 . V_32 . V_31 [ 1 ] ;
return V_5 ;
}
static int F_22 ( struct V_16 * V_17 )
{
struct V_3 V_19 ;
int V_5 ;
V_5 = F_8 ( V_17 ,
V_58 ,
V_60 ,
NULL , 0 , & V_19 ) ;
if ( V_5 == V_61 ) {
V_17 -> V_62 = 1 ;
V_17 -> V_63 = 0 ;
return 0 ;
}
if ( V_5 == V_64 )
return - V_65 ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_7 ,
V_26 , V_5 ) ;
return - V_66 ;
}
if ( V_5 )
return V_5 ;
V_17 -> V_62 = V_19 . V_32 . V_31 [ 0 ] ;
V_17 -> V_63 = V_19 . V_32 . V_31 [ 1 ] ;
return V_5 ;
}
static bool F_24 ( struct V_16 * V_17 )
{
int V_5 ;
V_5 = F_22 ( V_17 ) ;
if ( ! V_5 )
F_25 ( V_17 -> V_23 , L_8 ,
V_17 -> V_62 , V_17 -> V_63 ) ;
return V_5 == 0 ;
}
static int F_26 ( struct V_16 * V_17 ,
V_13 V_33 , V_13 * V_67 )
{
struct V_3 V_19 ;
int V_5 ;
V_5 = F_8 ( V_17 , V_33 ,
V_68 , NULL , 0 , & V_19 ) ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_7 ,
V_26 , V_5 ) ;
return - V_66 ;
}
if ( V_5 )
return V_5 ;
* V_67 = V_19 . V_32 . V_31 [ 0 ] ;
return V_5 ;
}
static int F_27 ( struct V_16 * V_17 ,
V_13 V_33 , V_13 V_69 , char * V_70 , int V_71 )
{
struct V_3 V_19 ;
int V_5 , V_72 ;
int V_73 ;
V_5 = F_8 ( V_17 , V_33 ,
V_74 , & V_69 , 1 ,
& V_19 ) ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_7 ,
V_26 , V_5 ) ;
return - V_66 ;
}
if ( V_5 )
return V_5 ;
if ( V_19 . V_6 == V_9 )
V_73 = V_10 - 4 ;
else
V_73 = V_8 - 4 ;
if ( V_71 < V_73 )
V_73 = V_71 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ )
V_70 [ V_72 ] = V_19 . V_32 . V_31 [ V_72 ] ;
return V_73 ;
}
static char * F_28 ( struct V_16 * V_17 )
{
V_13 V_57 ;
V_13 V_33 ;
V_13 V_75 ;
char * V_48 ;
unsigned V_76 = 0 ;
int V_5 ;
V_5 = F_21 ( V_17 , V_77 ,
& V_33 , & V_57 ) ;
if ( V_5 )
return NULL ;
V_5 = F_26 ( V_17 , V_33 ,
& V_75 ) ;
if ( V_5 )
return NULL ;
V_48 = F_9 ( V_75 + 1 , V_39 ) ;
if ( ! V_48 )
return NULL ;
while ( V_76 < V_75 ) {
V_5 = F_27 ( V_17 ,
V_33 , V_76 , V_48 + V_76 ,
V_75 - V_76 ) ;
if ( V_5 <= 0 ) {
F_10 ( V_48 ) ;
return NULL ;
}
V_76 += V_5 ;
}
F_18 ( & V_48 , V_75 + 1 ) ;
return V_48 ;
}
static int F_29 ( struct V_16 * V_17 ,
V_13 V_33 ,
struct V_78 * V_79 )
{
struct V_3 V_19 ;
int V_5 ;
V_13 * V_31 = ( V_13 * ) V_19 . V_32 . V_31 ;
V_5 = F_8 ( V_17 , V_33 ,
V_80 , & V_79 -> V_81 , 1 , & V_19 ) ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_7 ,
V_26 , V_5 ) ;
return - V_66 ;
}
if ( V_5 )
return V_5 ;
V_79 -> V_82 = V_31 [ 0 ] ;
V_79 -> V_83 = V_31 [ 1 ] ;
V_79 -> V_81 = V_31 [ 2 ] ;
V_79 -> V_84 = V_31 [ 3 ] ;
return 0 ;
}
static int F_30 ( struct V_16 * V_17 ,
V_13 V_33 , struct V_85 * V_86 )
{
struct V_3 V_19 ;
int V_5 ;
V_13 * V_31 = ( V_13 * ) V_19 . V_32 . V_31 ;
V_5 = F_8 ( V_17 , V_33 ,
V_87 , NULL , 0 , & V_19 ) ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_7 ,
V_26 , V_5 ) ;
return - V_66 ;
}
if ( V_5 )
return V_5 ;
V_86 -> V_88 = F_31 ( & V_31 [ 0 ] ) ;
V_86 -> V_89 = F_31 ( & V_31 [ 2 ] ) ;
V_86 -> V_90 = V_31 [ 4 ] ;
V_86 -> V_91 = V_31 [ 5 ] ;
V_86 -> V_92 = V_31 [ 7 ] ;
V_86 -> V_93 = V_31 [ 8 ] ;
V_86 -> V_94 = F_31 ( & V_31 [ 13 ] ) * 2 / 51 ;
return V_5 ;
}
static int F_32 ( struct V_16 * V_41 ,
V_13 V_33 , bool V_95 ,
bool V_96 )
{
struct V_3 V_19 ;
V_13 V_31 = V_95 | ( V_96 << 2 ) ;
return F_8 ( V_41 , V_33 ,
V_97 , & V_31 , 1 , & V_19 ) ;
}
static void F_33 ( V_13 * V_98 ,
struct V_99 * V_100 )
{
V_13 V_101 = V_98 [ 0 ] << 2 ;
V_13 V_102 = V_98 [ 2 ] << 2 ;
V_100 -> V_103 = V_101 << 6 | V_98 [ 1 ] ;
V_100 -> V_104 = V_102 << 6 | V_98 [ 3 ] ;
V_100 -> V_105 = V_98 [ 0 ] >> 6 ;
V_100 -> V_106 = V_98 [ 2 ] >> 6 ;
V_100 -> V_107 = V_98 [ 4 ] ;
V_100 -> V_108 = V_98 [ 5 ] ;
V_100 -> V_109 = V_98 [ 6 ] >> 4 ;
}
static void F_34 ( struct V_16 * V_41 ,
V_13 * V_98 , struct V_110 * V_111 )
{
memset ( V_111 , 0 , sizeof( struct V_110 ) ) ;
V_111 -> V_112 = V_98 [ 8 ] & 0x01 ;
V_111 -> V_113 = ( V_98 [ 8 ] >> 1 ) & 0x01 ;
V_111 -> V_114 = V_98 [ 15 ] & 0x0f ;
V_111 -> V_115 = ( V_98 [ 8 ] >> 2 ) & 0x01 ;
if ( V_111 -> V_114 ) {
F_33 ( & V_98 [ 2 ] , & V_111 -> V_116 [ 0 ] ) ;
F_33 ( & V_98 [ 9 ] , & V_111 -> V_116 [ 1 ] ) ;
}
}
static int F_35 ( struct V_1 * V_2 , struct V_117 * V_118 ,
struct V_119 * V_120 , struct V_121 * V_122 ,
unsigned long * * V_123 , int * V_124 )
{
return - 1 ;
}
static void F_36 ( struct V_16 * V_17 ,
struct V_125 * V_125 , bool V_126 )
{
struct V_127 * V_128 = V_17 -> V_129 ;
F_37 ( V_130 , V_125 -> V_131 ) ;
F_37 ( V_132 , V_125 -> V_131 ) ;
F_38 ( V_133 , V_125 -> V_131 ) ;
F_38 ( V_134 , V_125 -> V_131 ) ;
F_39 ( V_125 , V_135 , 0 , V_128 -> V_88 , 0 , 0 ) ;
F_40 ( V_125 , V_135 , V_128 -> V_136 ) ;
F_39 ( V_125 , V_137 , 0 , V_128 -> V_89 , 0 , 0 ) ;
F_40 ( V_125 , V_137 , V_128 -> V_136 ) ;
F_39 ( V_125 , V_138 , 0 , 50 , 0 , 0 ) ;
F_41 ( V_125 , V_132 , V_139 ) ;
if ( V_17 -> V_140 & V_141 )
F_41 ( V_125 , V_132 , V_142 ) ;
else
F_37 ( V_143 , V_125 -> V_144 ) ;
F_42 ( V_125 , V_128 -> V_92 , V_145 |
V_146 ) ;
V_128 -> V_147 = V_125 ;
}
static void F_43 ( struct V_127 * V_128 ,
struct V_99 * V_148 )
{
int V_149 ;
if ( ! V_148 -> V_109 || V_148 -> V_105 )
return;
V_149 = F_44 ( V_128 -> V_147 , V_148 -> V_109 ) ;
F_45 ( V_128 -> V_147 , V_149 ) ;
F_46 ( V_128 -> V_147 , V_150 ,
V_148 -> V_106 ) ;
if ( V_148 -> V_106 ) {
F_47 ( V_128 -> V_147 , V_130 , V_135 ,
V_148 -> V_103 ) ;
F_47 ( V_128 -> V_147 , V_130 , V_137 ,
V_128 -> V_151 ? V_128 -> V_89 - V_148 -> V_104 :
V_148 -> V_104 ) ;
F_47 ( V_128 -> V_147 , V_130 , V_138 ,
V_148 -> V_108 ) ;
}
}
static void F_48 ( struct V_16 * V_17 ,
struct V_110 * V_152 )
{
struct V_127 * V_128 = V_17 -> V_129 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ )
F_43 ( V_128 , & ( V_152 -> V_116 [ V_72 ] ) ) ;
if ( V_152 -> V_112 &&
! ( V_17 -> V_140 & V_141 ) )
F_47 ( V_128 -> V_147 , V_132 , V_139 , V_152 -> V_115 ) ;
if ( V_152 -> V_112 || V_152 -> V_114 <= 2 ) {
F_49 ( V_128 -> V_147 ) ;
F_50 ( V_128 -> V_147 ) ;
}
}
static int F_51 ( struct V_16 * V_17 , V_13 * V_98 )
{
struct V_127 * V_128 = V_17 -> V_129 ;
V_13 V_153 = ( ( V_98 [ 7 ] & 0xf ) * ( V_98 [ 7 ] & 0xf ) +
( V_98 [ 7 ] >> 4 ) * ( V_98 [ 7 ] >> 4 ) ) / 2 ;
V_13 V_154 = ( ( V_98 [ 13 ] & 0xf ) * ( V_98 [ 13 ] & 0xf ) +
( V_98 [ 13 ] >> 4 ) * ( V_98 [ 13 ] >> 4 ) ) / 2 ;
struct V_110 V_152 = {
. V_155 = V_98 [ 1 ] ,
. V_116 = {
{
. V_105 = 0 ,
. V_106 = ! ! V_98 [ 7 ] ,
. V_103 = F_52 ( & V_98 [ 3 ] ) ,
. V_104 = F_52 ( & V_98 [ 5 ] ) ,
. V_107 = V_153 ,
. V_108 = V_153 ,
. V_109 = V_98 [ 2 ] ,
} , {
. V_105 = 0 ,
. V_106 = ! ! V_98 [ 13 ] ,
. V_103 = F_52 ( & V_98 [ 9 ] ) ,
. V_104 = F_52 ( & V_98 [ 11 ] ) ,
. V_107 = V_154 ,
. V_108 = V_154 ,
. V_109 = V_98 [ 8 ] ,
}
} ,
. V_114 = V_128 -> V_92 ,
. V_113 = 0 ,
. V_112 = ( V_98 [ 0 ] >> 7 ) == 0 ,
. V_115 = V_98 [ 0 ] & 0x01 ,
} ;
F_48 ( V_17 , & V_152 ) ;
return 1 ;
}
static int F_53 ( struct V_1 * V_2 , V_13 * V_98 , int V_156 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
struct V_127 * V_128 = V_17 -> V_129 ;
struct V_3 * V_47 = (struct V_3 * ) V_98 ;
struct V_110 V_152 ;
if ( ! V_128 || ! V_128 -> V_147 )
return 1 ;
switch ( V_98 [ 0 ] ) {
case 0x02 :
if ( V_156 < 2 ) {
F_23 ( V_2 , L_9 ,
V_156 ) ;
return 1 ;
}
if ( V_17 -> V_140 & V_141 ) {
F_47 ( V_128 -> V_147 , V_132 , V_139 ,
! ! ( V_98 [ 1 ] & 0x01 ) ) ;
F_47 ( V_128 -> V_147 , V_132 , V_142 ,
! ! ( V_98 [ 1 ] & 0x02 ) ) ;
F_50 ( V_128 -> V_147 ) ;
return 0 ;
} else {
if ( V_156 < 21 )
return 1 ;
return F_51 ( V_17 , & V_98 [ 7 ] ) ;
}
case V_9 :
if ( ( V_47 -> V_32 . V_33 != V_128 -> V_157 ) ||
( V_47 -> V_32 . V_36 != V_158 ) )
return 1 ;
F_34 ( V_17 , V_98 + 4 , & V_152 ) ;
F_48 ( V_17 , & V_152 ) ;
return 0 ;
}
return 0 ;
}
static int F_55 ( struct V_16 * V_17 )
{
struct V_127 * V_128 = V_17 -> V_129 ;
struct V_85 V_86 = { 0 } ;
V_13 V_57 ;
int V_5 ;
V_5 = F_21 ( V_17 , V_159 ,
& V_128 -> V_157 , & V_57 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_30 ( V_17 , V_128 -> V_157 ,
& V_86 ) ;
if ( V_5 )
return V_5 ;
V_128 -> V_88 = V_86 . V_88 ;
V_128 -> V_89 = V_86 . V_89 ;
V_128 -> V_92 = V_86 . V_92 ;
V_128 -> V_151 = V_86 . V_93 == V_160 ;
V_128 -> V_136 = V_86 . V_94 ;
if ( ! V_128 -> V_136 )
V_128 -> V_136 = V_161 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , const struct V_162 * V_163 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
struct V_127 * V_128 ;
V_128 = F_57 ( & V_2 -> V_164 , sizeof( struct V_127 ) ,
V_39 ) ;
if ( ! V_128 )
return - V_40 ;
V_17 -> V_129 = V_128 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , bool V_165 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
struct V_127 * V_128 = V_17 -> V_129 ;
int V_5 ;
if ( ! V_165 )
return 0 ;
if ( ! V_128 -> V_88 ) {
V_5 = F_55 ( V_17 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_10 , V_5 ) ;
return V_5 ;
}
}
return F_32 ( V_17 , V_128 -> V_157 ,
true , true ) ;
}
static int F_59 ( struct V_1 * V_2 , bool V_165 )
{
struct V_3 V_19 ;
struct V_16 * V_41 ;
V_41 = F_54 ( V_2 ) ;
if ( ! V_165 )
return - V_11 ;
return F_11 (
V_41 ,
V_7 ,
V_166 ,
V_167 ,
( V_13 * ) V_168 ,
sizeof( V_168 ) ,
& V_19
) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
struct V_169 * V_170 ;
V_170 = F_57 ( & V_2 -> V_164 , sizeof( struct V_169 ) ,
V_39 ) ;
if ( ! V_170 )
return - V_40 ;
V_17 -> V_129 = V_170 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , V_13 * V_98 , int V_156 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
struct V_169 * V_171 = V_17 -> V_129 ;
if ( ! V_171 || ! V_171 -> V_147 ) {
F_23 ( V_2 , L_11 ) ;
return - V_38 ;
}
if ( V_156 < 7 ) {
F_23 ( V_2 , L_12 ) ;
return 0 ;
}
if ( V_98 [ 0 ] == V_9 &&
V_98 [ 2 ] == V_166 && V_98 [ 6 ] == 0x00 ) {
switch ( V_98 [ 5 ] ) {
case 0xaf :
F_62 ( V_171 -> V_147 , V_172 , 1 ) ;
break;
case 0xb0 :
F_62 ( V_171 -> V_147 , V_173 , 1 ) ;
break;
case 0xae :
F_62 ( V_171 -> V_147 , V_174 , 1 ) ;
break;
case 0x00 :
F_62 ( V_171 -> V_147 , V_174 , 0 ) ;
F_62 ( V_171 -> V_147 , V_173 , 0 ) ;
F_62 ( V_171 -> V_147 , V_172 , 0 ) ;
break;
default:
F_23 ( V_2 , L_12 ) ;
return 0 ;
}
F_50 ( V_171 -> V_147 ) ;
} else if ( V_98 [ 0 ] == 0x02 ) {
int V_175 ;
F_62 ( V_171 -> V_147 , V_139 ,
! ! ( V_98 [ 1 ] & V_176 ) ) ;
F_62 ( V_171 -> V_147 , V_142 ,
! ! ( V_98 [ 1 ] & V_177 ) ) ;
if ( V_98 [ 1 ] & V_178 )
F_63 ( V_171 -> V_147 , V_179 , - 1 ) ;
else if ( V_98 [ 1 ] & V_180 )
F_63 ( V_171 -> V_147 , V_179 , 1 ) ;
V_175 = F_64 ( F_65 ( V_2 , V_98 + 3 , 0 , 12 ) , 12 ) ;
F_63 ( V_171 -> V_147 , V_181 , V_175 ) ;
V_175 = F_64 ( F_65 ( V_2 , V_98 + 3 , 12 , 12 ) , 12 ) ;
F_63 ( V_171 -> V_147 , V_182 , V_175 ) ;
V_175 = F_64 ( V_98 [ 6 ] , 8 ) ;
F_63 ( V_171 -> V_147 , V_183 , V_175 ) ;
F_50 ( V_171 -> V_147 ) ;
}
return 1 ;
}
static void F_66 ( struct V_16 * V_17 ,
struct V_125 * V_125 , bool V_126 )
{
struct V_169 * V_171 = V_17 -> V_129 ;
V_171 -> V_147 = V_125 ;
F_37 ( V_132 , V_171 -> V_147 -> V_131 ) ;
F_37 ( V_172 , V_171 -> V_147 -> V_184 ) ;
F_37 ( V_142 , V_171 -> V_147 -> V_184 ) ;
F_37 ( V_139 , V_171 -> V_147 -> V_184 ) ;
F_37 ( V_174 , V_171 -> V_147 -> V_184 ) ;
F_37 ( V_173 , V_171 -> V_147 -> V_184 ) ;
F_37 ( V_133 , V_171 -> V_147 -> V_131 ) ;
F_37 ( V_181 , V_171 -> V_147 -> V_185 ) ;
F_37 ( V_182 , V_171 -> V_147 -> V_185 ) ;
F_37 ( V_183 , V_171 -> V_147 -> V_185 ) ;
F_37 ( V_179 , V_171 -> V_147 -> V_185 ) ;
}
static int F_67 ( struct V_1 * V_2 , struct V_117 * V_118 ,
struct V_119 * V_120 , struct V_121 * V_122 ,
unsigned long * * V_123 , int * V_124 )
{
return - 1 ;
}
static int F_68 ( struct V_16 * V_17 )
{
struct V_186 * V_187 = V_17 -> V_129 ;
struct V_78 V_79 = {} ;
int V_5 ;
V_13 V_57 ;
if ( ! V_187 -> V_33 ) {
V_5 = F_21 ( V_17 ,
V_188 ,
& V_187 -> V_33 , & V_57 ) ;
if ( V_5 )
return V_5 ;
}
V_5 = F_29 ( V_17 , V_187 -> V_33 , & V_79 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
struct V_186 * V_187 ;
V_187 = F_57 ( & V_2 -> V_164 , sizeof( struct V_186 ) ,
V_39 ) ;
if ( ! V_187 )
return - V_40 ;
V_17 -> V_129 = V_187 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , bool V_165 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
if ( ! V_165 )
return 0 ;
if ( ! V_189 )
return 0 ;
return F_68 ( V_17 ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_117 * V_118 ,
struct V_119 * V_120 , struct V_121 * V_122 ,
unsigned long * * V_123 , int * V_124 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
if ( V_17 -> V_140 & V_190 )
return F_35 ( V_2 , V_118 , V_120 , V_122 , V_123 , V_124 ) ;
else if ( V_17 -> V_140 & V_191 &&
V_120 -> V_192 != V_193 )
return F_67 ( V_2 , V_118 , V_120 , V_122 , V_123 , V_124 ) ;
return 0 ;
}
static void F_72 ( struct V_16 * V_17 ,
struct V_125 * V_147 , bool V_126 )
{
if ( V_17 -> V_140 & V_190 )
F_36 ( V_17 , V_147 , V_126 ) ;
else if ( V_17 -> V_140 & V_191 )
F_66 ( V_17 , V_147 , V_126 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_117 * V_194 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
struct V_125 * V_147 = V_194 -> V_147 ;
F_72 ( V_17 , V_147 , true ) ;
return 0 ;
}
static int F_74 ( struct V_16 * V_17 , V_13 * V_98 ,
int V_156 )
{
struct V_3 * V_45 = V_17 -> V_21 ;
struct V_3 * V_46 = V_17 -> V_21 ;
struct V_3 * V_47 = (struct V_3 * ) V_98 ;
if ( F_75 ( F_76 ( & V_17 -> V_20 ) ) ) {
if ( F_15 ( V_45 , V_47 ) ||
F_16 ( V_45 , V_47 ) ) {
* V_46 = * V_47 ;
V_17 -> V_22 = true ;
F_77 ( & V_17 -> V_24 ) ;
return 1 ;
}
}
if ( F_75 ( F_17 ( V_47 ) ) ) {
F_78 ( & V_17 -> V_165 ,
! ( V_47 -> V_28 . V_31 [ 0 ] & ( 1 << 6 ) ) ) ;
if ( ( V_17 -> V_140 & V_195 ) &&
( F_79 ( & V_17 -> V_44 ) == 0 ) )
F_5 ( L_13 , V_26 ) ;
return 1 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_196 * V_47 ,
V_13 * V_98 , int V_156 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
int V_5 = 0 ;
switch ( V_98 [ 0 ] ) {
case V_9 :
if ( V_156 != V_10 ) {
F_23 ( V_2 , L_14 ,
V_156 ) ;
return 1 ;
}
V_5 = F_74 ( V_17 , V_98 , V_156 ) ;
break;
case V_7 :
if ( V_156 != V_8 ) {
F_23 ( V_2 , L_14 ,
V_156 ) ;
return 1 ;
}
V_5 = F_74 ( V_17 , V_98 , V_156 ) ;
break;
}
if ( V_5 != 0 )
return V_5 ;
if ( V_17 -> V_140 & V_190 )
return F_53 ( V_2 , V_98 , V_156 ) ;
else if ( V_17 -> V_140 & V_191 )
return F_61 ( V_2 , V_98 , V_156 ) ;
return 0 ;
}
static void F_81 ( struct V_1 * V_2 , bool V_197 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
char * V_48 ;
if ( V_197 )
V_48 = F_20 ( V_17 ) ;
else
V_48 = F_28 ( V_17 ) ;
if ( ! V_48 )
F_23 ( V_2 , L_15 ) ;
else
snprintf ( V_2 -> V_48 , sizeof( V_2 -> V_48 ) , L_16 , V_48 ) ;
F_10 ( V_48 ) ;
}
static int F_82 ( struct V_125 * V_164 )
{
struct V_1 * V_198 = F_83 ( V_164 ) ;
return F_84 ( V_198 ) ;
}
static void F_85 ( struct V_125 * V_164 )
{
struct V_1 * V_198 = F_83 ( V_164 ) ;
F_86 ( V_198 ) ;
}
static struct V_125 * F_87 ( struct V_1 * V_2 )
{
struct V_125 * V_125 = F_88 ( & V_2 -> V_164 ) ;
struct V_16 * V_17 = F_54 ( V_2 ) ;
if ( ! V_125 )
return NULL ;
F_89 ( V_125 , V_2 ) ;
V_125 -> V_199 = F_82 ;
V_125 -> V_200 = F_85 ;
V_125 -> V_48 = V_17 -> V_48 ;
V_125 -> V_201 = V_2 -> V_201 ;
V_125 -> V_202 = V_2 -> V_202 ;
V_125 -> V_163 . V_203 = V_2 -> V_204 ;
V_125 -> V_163 . V_205 = V_2 -> V_205 ;
V_125 -> V_163 . V_206 = V_2 -> V_206 ;
V_125 -> V_163 . V_207 = V_2 -> V_207 ;
V_125 -> V_164 . V_208 = & V_2 -> V_164 ;
return V_125 ;
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_23 ;
int V_5 = 0 ;
bool V_165 = F_90 ( & V_17 -> V_165 ) ;
struct V_125 * V_147 ;
char * V_48 , * V_209 ;
if ( V_17 -> V_140 & V_190 ) {
V_5 = F_58 ( V_2 , V_165 ) ;
if ( V_5 )
return;
} else if ( V_17 -> V_140 & V_191 ) {
V_5 = F_59 ( V_2 , V_165 ) ;
if ( V_5 )
return;
} else if ( V_17 -> V_140 & V_210 ) {
V_5 = F_70 ( V_2 , V_165 ) ;
if ( V_5 )
return;
}
if ( ! V_165 || V_17 -> V_211 )
return;
if ( ! V_17 -> V_62 ) {
V_5 = ! F_24 ( V_17 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_17 ) ;
return;
}
F_91 ( V_2 , L_8 ,
V_17 -> V_62 , V_17 -> V_63 ) ;
}
if ( ! ( V_17 -> V_140 & V_212 ) )
return;
if ( ! V_17 -> V_48 || V_17 -> V_48 == V_2 -> V_48 ) {
V_48 = F_28 ( V_17 ) ;
if ( ! V_48 ) {
F_23 ( V_2 ,
L_15 ) ;
return;
}
V_209 = F_92 ( & V_2 -> V_164 , V_39 , L_16 , V_48 ) ;
F_10 ( V_48 ) ;
if ( ! V_209 )
return;
V_17 -> V_48 = V_209 ;
}
V_147 = F_87 ( V_2 ) ;
if ( ! V_147 ) {
F_23 ( V_2 , L_18 , V_5 ) ;
return;
}
F_72 ( V_17 , V_147 , false ) ;
V_5 = F_93 ( V_147 ) ;
if ( V_5 )
F_94 ( V_147 ) ;
V_17 -> V_211 = V_147 ;
}
static int F_95 ( struct V_1 * V_2 , const struct V_162 * V_163 )
{
struct V_16 * V_17 ;
int V_5 ;
bool V_165 ;
unsigned int V_213 = V_214 ;
V_17 = F_57 ( & V_2 -> V_164 , sizeof( struct V_16 ) ,
V_39 ) ;
if ( ! V_17 )
return - V_40 ;
V_17 -> V_23 = V_2 ;
V_17 -> V_48 = V_2 -> V_48 ;
F_96 ( V_2 , V_17 ) ;
V_17 -> V_140 = V_163 -> V_215 ;
if ( V_216 ) {
V_17 -> V_140 &= ~ V_190 ;
V_17 -> V_140 &= ~ V_195 ;
V_17 -> V_140 &= ~ V_212 ;
}
if ( V_17 -> V_140 & V_190 ) {
V_5 = F_56 ( V_2 , V_163 ) ;
if ( V_5 )
goto V_217;
} else if ( V_17 -> V_140 & V_191 ) {
V_5 = F_60 ( V_2 ) ;
if ( V_5 )
goto V_217;
} else if ( V_17 -> V_140 & V_210 ) {
V_5 = F_69 ( V_2 ) ;
if ( V_5 )
goto V_217;
}
F_97 ( & V_17 -> V_44 , F_12 ) ;
F_98 ( & V_17 -> V_20 ) ;
F_99 ( & V_17 -> V_24 ) ;
V_5 = F_100 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_19 , V_26 ) ;
goto V_218;
}
F_101 ( V_2 ) ;
V_165 = F_24 ( V_17 ) ;
if ( V_163 -> V_219 != V_220 ) {
if ( ! V_165 ) {
V_5 = - V_11 ;
F_23 ( V_2 , L_20 ) ;
F_102 ( V_2 ) ;
goto V_218;
}
F_91 ( V_2 , L_8 ,
V_17 -> V_62 , V_17 -> V_63 ) ;
}
F_81 ( V_2 , V_163 -> V_219 == V_220 ) ;
F_78 ( & V_17 -> V_165 , V_165 ) ;
if ( V_165 && ( V_17 -> V_140 & V_190 ) ) {
V_5 = F_55 ( V_17 ) ;
if ( V_5 )
goto V_218;
}
F_102 ( V_2 ) ;
if ( V_17 -> V_140 & V_212 )
V_213 &= ~ V_221 ;
V_5 = F_103 ( V_2 , V_213 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_21 , V_26 ) ;
goto V_222;
}
if ( V_17 -> V_140 & V_195 ) {
F_101 ( V_2 ) ;
F_14 ( V_17 ) ;
}
return V_5 ;
V_222:
V_218:
F_104 ( & V_17 -> V_44 ) ;
F_105 ( & V_17 -> V_20 ) ;
V_217:
F_96 ( V_2 , NULL ) ;
return V_5 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_54 ( V_2 ) ;
F_104 ( & V_17 -> V_44 ) ;
F_105 ( & V_17 -> V_20 ) ;
F_107 ( V_2 ) ;
}
