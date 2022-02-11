static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_5 = F_2 ( V_2 ) ;
switch ( V_3 -> V_8 ) {
case V_9 :
V_6 = V_10 ;
break;
case V_11 :
V_6 = V_12 ;
break;
case V_13 :
V_6 = V_14 ;
break;
default:
return - V_15 ;
}
V_3 -> V_16 = 0xff ;
if ( V_5 -> V_17 & V_18 ) {
V_7 = F_3 ( V_2 , ( V_19 * ) V_3 , V_6 ) ;
} else {
V_7 = F_4 ( V_2 , V_3 -> V_8 ,
( V_19 * ) V_3 , V_6 , V_20 ,
V_21 ) ;
}
return V_7 == V_6 ? 0 : - 1 ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_3 * V_22 ,
struct V_3 * V_23 )
{
int V_7 ;
F_6 ( & V_5 -> V_24 ) ;
V_5 -> V_25 = V_23 ;
V_5 -> V_26 = false ;
* V_23 = * V_22 ;
V_7 = F_1 ( V_5 -> V_27 , V_22 ) ;
if ( V_7 ) {
F_7 ( L_1 , V_7 ) ;
memset ( V_23 , 0 , sizeof( struct V_3 ) ) ;
goto exit;
}
if ( ! F_8 ( V_5 -> V_28 , V_5 -> V_26 ,
5 * V_29 ) ) {
F_7 ( L_2 , V_30 ) ;
memset ( V_23 , 0 , sizeof( struct V_3 ) ) ;
V_7 = - V_31 ;
}
if ( V_23 -> V_8 == V_9 &&
V_23 -> V_32 . V_33 == V_34 ) {
V_7 = V_23 -> V_32 . V_35 [ 1 ] ;
F_7 ( L_3 , V_30 , V_7 ) ;
goto exit;
}
if ( ( V_23 -> V_8 == V_11 ||
V_23 -> V_8 == V_13 ) &&
V_23 -> V_36 . V_37 == V_38 ) {
V_7 = V_23 -> V_36 . V_35 [ 1 ] ;
F_7 ( L_4 , V_30 , V_7 ) ;
goto exit;
}
exit:
F_9 ( & V_5 -> V_24 ) ;
return V_7 ;
}
static int F_10 ( struct V_4 * V_5 ,
V_19 V_39 , V_19 V_40 , V_19 * V_35 , int V_41 ,
struct V_3 * V_23 )
{
struct V_3 * V_22 ;
int V_7 ;
if ( V_41 > sizeof( V_22 -> V_36 . V_35 ) )
return - V_42 ;
V_22 = F_11 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_22 )
return - V_44 ;
if ( V_41 > ( V_12 - 4 ) )
V_22 -> V_8 = V_13 ;
else
V_22 -> V_8 = V_11 ;
V_22 -> V_36 . V_37 = V_39 ;
V_22 -> V_36 . V_40 = V_40 ;
memcpy ( & V_22 -> V_36 . V_35 , V_35 , V_41 ) ;
V_7 = F_5 ( V_5 , V_22 , V_23 ) ;
F_12 ( V_22 ) ;
return V_7 ;
}
static int F_13 ( struct V_4 * V_45 ,
V_19 V_8 , V_19 V_33 , V_19 V_46 , V_19 * V_35 , int V_41 ,
struct V_3 * V_23 )
{
struct V_3 * V_22 ;
int V_7 , V_47 ;
switch ( V_8 ) {
case V_9 :
V_47 = V_10 - 4 ;
break;
case V_11 :
V_47 = V_12 - 4 ;
break;
case V_13 :
V_47 = V_14 - 4 ;
break;
default:
return - V_42 ;
}
if ( V_41 > V_47 )
return - V_42 ;
V_22 = F_11 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_22 )
return - V_44 ;
V_22 -> V_8 = V_8 ;
V_22 -> V_32 . V_33 = V_33 ;
V_22 -> V_32 . V_46 = V_46 ;
memcpy ( & V_22 -> V_32 . V_35 , V_35 , V_41 ) ;
V_7 = F_5 ( V_45 , V_22 , V_23 ) ;
F_12 ( V_22 ) ;
return V_7 ;
}
static void F_14 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_15 ( V_49 , struct V_4 ,
V_49 ) ;
F_16 ( V_5 ) ;
}
static inline bool F_17 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
return ( V_51 -> V_36 . V_37 == V_50 -> V_36 . V_37 ) &&
( V_51 -> V_36 . V_40 == V_50 -> V_36 . V_40 ) ;
}
static inline bool F_18 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
return ( ( V_51 -> V_32 . V_33 == V_34 ) ||
( V_51 -> V_36 . V_37 == V_38 ) ) &&
( V_51 -> V_36 . V_40 == V_50 -> V_36 . V_37 ) &&
( V_51 -> V_36 . V_35 [ 0 ] == V_50 -> V_36 . V_40 ) ;
}
static inline bool F_19 ( struct V_3 * V_52 )
{
return ( V_52 -> V_8 == V_9 ) &&
( V_52 -> V_32 . V_33 == 0x41 ) ;
}
static void F_20 ( char * * V_53 , int V_54 )
{
#define F_21 9
int V_55 ;
char * V_56 ;
if ( V_54 > F_21 &&
strncmp ( * V_53 , L_5 , F_21 ) == 0 )
return;
V_55 = F_21 + V_54 ;
V_56 = F_11 ( V_55 , V_43 ) ;
if ( ! V_56 )
return;
snprintf ( V_56 , V_55 , L_6 , * V_53 ) ;
F_12 ( * V_53 ) ;
* V_53 = V_56 ;
}
static char * F_22 ( struct V_4 * V_45 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 V_35 [ 1 ] = { V_57 } ;
char * V_53 ;
int V_58 ;
V_7 = F_13 ( V_45 ,
V_9 ,
V_59 ,
V_60 ,
V_35 , 1 , & V_23 ) ;
if ( V_7 )
return NULL ;
V_58 = V_23 . V_32 . V_35 [ 1 ] ;
if ( 2 + V_58 > sizeof( V_23 . V_32 . V_35 ) )
return NULL ;
V_53 = F_11 ( V_58 + 1 , V_43 ) ;
if ( ! V_53 )
return NULL ;
memcpy ( V_53 , & V_23 . V_32 . V_35 [ 2 ] , V_58 ) ;
F_20 ( & V_53 , V_58 + 1 ) ;
return V_53 ;
}
static int F_23 ( struct V_4 * V_5 , T_1 V_61 ,
V_19 * V_37 , V_19 * V_62 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 V_35 [ 2 ] = { V_61 >> 8 , V_61 & 0x00FF } ;
V_7 = F_10 ( V_5 ,
V_63 ,
V_64 ,
V_35 , 2 , & V_23 ) ;
if ( V_7 )
return V_7 ;
* V_37 = V_23 . V_36 . V_35 [ 0 ] ;
* V_62 = V_23 . V_36 . V_35 [ 1 ] ;
return V_7 ;
}
static int F_24 ( struct V_4 * V_5 )
{
struct V_3 V_23 ;
int V_7 ;
V_7 = F_10 ( V_5 ,
V_63 ,
V_65 ,
NULL , 0 , & V_23 ) ;
if ( V_7 == V_66 ) {
V_5 -> V_67 = 1 ;
V_5 -> V_68 = 0 ;
return 0 ;
}
if ( V_7 == V_69 )
return - V_70 ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
V_5 -> V_67 = V_23 . V_36 . V_35 [ 0 ] ;
V_5 -> V_68 = V_23 . V_36 . V_35 [ 1 ] ;
return V_7 ;
}
static bool F_26 ( struct V_4 * V_5 )
{
int V_7 ;
V_7 = F_24 ( V_5 ) ;
if ( ! V_7 )
F_27 ( V_5 -> V_27 , L_8 ,
V_5 -> V_67 , V_5 -> V_68 ) ;
return V_7 == 0 ;
}
static int F_28 ( struct V_4 * V_5 ,
V_19 V_37 , V_19 * V_72 )
{
struct V_3 V_23 ;
int V_7 ;
V_7 = F_10 ( V_5 , V_37 ,
V_73 , NULL , 0 , & V_23 ) ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
* V_72 = V_23 . V_36 . V_35 [ 0 ] ;
return V_7 ;
}
static int F_29 ( struct V_4 * V_5 ,
V_19 V_37 , V_19 V_74 , char * V_75 , int V_76 )
{
struct V_3 V_23 ;
int V_7 , V_77 ;
int V_78 ;
V_7 = F_10 ( V_5 , V_37 ,
V_79 , & V_74 , 1 ,
& V_23 ) ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
switch ( V_23 . V_8 ) {
case V_13 :
V_78 = V_14 - 4 ;
break;
case V_11 :
V_78 = V_12 - 4 ;
break;
case V_9 :
V_78 = V_10 - 4 ;
break;
default:
return - V_71 ;
}
if ( V_76 < V_78 )
V_78 = V_76 ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ )
V_75 [ V_77 ] = V_23 . V_36 . V_35 [ V_77 ] ;
return V_78 ;
}
static char * F_30 ( struct V_4 * V_5 )
{
V_19 V_62 ;
V_19 V_37 ;
V_19 V_80 ;
char * V_53 ;
unsigned V_81 = 0 ;
int V_7 ;
V_7 = F_23 ( V_5 , V_82 ,
& V_37 , & V_62 ) ;
if ( V_7 )
return NULL ;
V_7 = F_28 ( V_5 , V_37 ,
& V_80 ) ;
if ( V_7 )
return NULL ;
V_53 = F_11 ( V_80 + 1 , V_43 ) ;
if ( ! V_53 )
return NULL ;
while ( V_81 < V_80 ) {
V_7 = F_29 ( V_5 ,
V_37 , V_81 , V_53 + V_81 ,
V_80 - V_81 ) ;
if ( V_7 <= 0 ) {
F_12 ( V_53 ) ;
return NULL ;
}
V_81 += V_7 ;
}
F_20 ( & V_53 , V_80 + 1 ) ;
return V_53 ;
}
static int F_31 ( struct V_4 * V_5 ,
V_19 V_37 ,
struct V_83 * V_84 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 * V_35 = ( V_19 * ) V_23 . V_36 . V_35 ;
V_7 = F_10 ( V_5 , V_37 ,
V_85 , & V_84 -> V_86 , 1 , & V_23 ) ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
V_84 -> V_87 = V_35 [ 0 ] ;
V_84 -> V_88 = V_35 [ 1 ] ;
V_84 -> V_86 = V_35 [ 2 ] ;
V_84 -> V_89 = V_35 [ 3 ] ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
V_19 V_37 , struct V_90 * V_91 )
{
struct V_3 V_23 ;
int V_7 ;
V_19 * V_35 = ( V_19 * ) V_23 . V_36 . V_35 ;
V_7 = F_10 ( V_5 , V_37 ,
V_92 , NULL , 0 , & V_23 ) ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
V_91 -> V_93 = F_33 ( & V_35 [ 0 ] ) ;
V_91 -> V_94 = F_33 ( & V_35 [ 2 ] ) ;
V_91 -> V_95 = V_35 [ 4 ] ;
V_91 -> V_96 = V_35 [ 5 ] ;
V_91 -> V_97 = V_35 [ 7 ] ;
V_91 -> V_98 = V_35 [ 8 ] ;
V_91 -> V_99 = F_33 ( & V_35 [ 13 ] ) * 2 / 51 ;
return V_7 ;
}
static int F_34 ( struct V_4 * V_45 ,
V_19 V_37 , bool V_100 ,
bool V_101 )
{
struct V_3 V_23 ;
V_19 V_35 = V_100 | ( V_101 << 2 ) ;
return F_10 ( V_45 , V_37 ,
V_102 , & V_35 , 1 , & V_23 ) ;
}
static void F_35 ( V_19 * V_103 ,
struct V_104 * V_105 )
{
V_19 V_106 = V_103 [ 0 ] << 2 ;
V_19 V_107 = V_103 [ 2 ] << 2 ;
V_105 -> V_108 = V_106 << 6 | V_103 [ 1 ] ;
V_105 -> V_109 = V_107 << 6 | V_103 [ 3 ] ;
V_105 -> V_110 = V_103 [ 0 ] >> 6 ;
V_105 -> V_111 = V_103 [ 2 ] >> 6 ;
V_105 -> V_112 = V_103 [ 4 ] ;
V_105 -> V_113 = V_103 [ 5 ] ;
V_105 -> V_114 = V_103 [ 6 ] >> 4 ;
}
static void F_36 ( struct V_4 * V_45 ,
V_19 * V_103 , struct V_115 * V_116 )
{
memset ( V_116 , 0 , sizeof( struct V_115 ) ) ;
V_116 -> V_117 = V_103 [ 8 ] & 0x01 ;
V_116 -> V_118 = ( V_103 [ 8 ] >> 1 ) & 0x01 ;
V_116 -> V_119 = V_103 [ 15 ] & 0x0f ;
V_116 -> V_120 = ( V_103 [ 8 ] >> 2 ) & 0x01 ;
if ( V_116 -> V_119 ) {
F_35 ( & V_103 [ 2 ] , & V_116 -> V_121 [ 0 ] ) ;
F_35 ( & V_103 [ 9 ] , & V_116 -> V_121 [ 1 ] ) ;
}
}
static int F_37 ( struct V_1 * V_2 , struct V_122 * V_123 ,
struct V_124 * V_125 , struct V_126 * V_127 ,
unsigned long * * V_128 , int * V_129 )
{
return - 1 ;
}
static void F_38 ( struct V_4 * V_5 ,
struct V_130 * V_130 , bool V_131 )
{
struct V_132 * V_133 = V_5 -> V_134 ;
F_39 ( V_135 , V_130 -> V_136 ) ;
F_39 ( V_137 , V_130 -> V_136 ) ;
F_40 ( V_138 , V_130 -> V_136 ) ;
F_40 ( V_139 , V_130 -> V_136 ) ;
F_41 ( V_130 , V_140 , 0 , V_133 -> V_93 , 0 , 0 ) ;
F_42 ( V_130 , V_140 , V_133 -> V_141 ) ;
F_41 ( V_130 , V_142 , 0 , V_133 -> V_94 , 0 , 0 ) ;
F_42 ( V_130 , V_142 , V_133 -> V_141 ) ;
F_41 ( V_130 , V_143 , 0 , 50 , 0 , 0 ) ;
F_43 ( V_130 , V_137 , V_144 ) ;
if ( V_5 -> V_17 & V_145 )
F_43 ( V_130 , V_137 , V_146 ) ;
else
F_39 ( V_147 , V_130 -> V_148 ) ;
F_44 ( V_130 , V_133 -> V_97 , V_149 |
V_150 ) ;
V_133 -> V_151 = V_130 ;
}
static void F_45 ( struct V_132 * V_133 ,
struct V_104 * V_152 )
{
int V_153 ;
if ( ! V_152 -> V_114 || V_152 -> V_110 )
return;
V_153 = F_46 ( V_133 -> V_151 , V_152 -> V_114 ) ;
F_47 ( V_133 -> V_151 , V_153 ) ;
F_48 ( V_133 -> V_151 , V_154 ,
V_152 -> V_111 ) ;
if ( V_152 -> V_111 ) {
F_49 ( V_133 -> V_151 , V_135 , V_140 ,
V_152 -> V_108 ) ;
F_49 ( V_133 -> V_151 , V_135 , V_142 ,
V_133 -> V_155 ? V_133 -> V_94 - V_152 -> V_109 :
V_152 -> V_109 ) ;
F_49 ( V_133 -> V_151 , V_135 , V_143 ,
V_152 -> V_113 ) ;
}
}
static void F_50 ( struct V_4 * V_5 ,
struct V_115 * V_156 )
{
struct V_132 * V_133 = V_5 -> V_134 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < 2 ; V_77 ++ )
F_45 ( V_133 , & ( V_156 -> V_121 [ V_77 ] ) ) ;
if ( V_156 -> V_117 &&
! ( V_5 -> V_17 & V_145 ) )
F_49 ( V_133 -> V_151 , V_137 , V_144 , V_156 -> V_120 ) ;
if ( V_156 -> V_117 || V_156 -> V_119 <= 2 ) {
F_51 ( V_133 -> V_151 ) ;
F_52 ( V_133 -> V_151 ) ;
}
}
static int F_53 ( struct V_4 * V_5 , V_19 * V_103 )
{
struct V_132 * V_133 = V_5 -> V_134 ;
V_19 V_157 = ( ( V_103 [ 7 ] & 0xf ) * ( V_103 [ 7 ] & 0xf ) +
( V_103 [ 7 ] >> 4 ) * ( V_103 [ 7 ] >> 4 ) ) / 2 ;
V_19 V_158 = ( ( V_103 [ 13 ] & 0xf ) * ( V_103 [ 13 ] & 0xf ) +
( V_103 [ 13 ] >> 4 ) * ( V_103 [ 13 ] >> 4 ) ) / 2 ;
struct V_115 V_156 = {
. V_159 = V_103 [ 1 ] ,
. V_121 = {
{
. V_110 = 0 ,
. V_111 = ! ! V_103 [ 7 ] ,
. V_108 = F_54 ( & V_103 [ 3 ] ) ,
. V_109 = F_54 ( & V_103 [ 5 ] ) ,
. V_112 = V_157 ,
. V_113 = V_157 ,
. V_114 = V_103 [ 2 ] ,
} , {
. V_110 = 0 ,
. V_111 = ! ! V_103 [ 13 ] ,
. V_108 = F_54 ( & V_103 [ 9 ] ) ,
. V_109 = F_54 ( & V_103 [ 11 ] ) ,
. V_112 = V_158 ,
. V_113 = V_158 ,
. V_114 = V_103 [ 8 ] ,
}
} ,
. V_119 = V_133 -> V_97 ,
. V_118 = 0 ,
. V_117 = ( V_103 [ 0 ] >> 7 ) == 0 ,
. V_120 = V_103 [ 0 ] & 0x01 ,
} ;
F_50 ( V_5 , & V_156 ) ;
return 1 ;
}
static int F_55 ( struct V_1 * V_2 , V_19 * V_103 , int V_160 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_132 * V_133 = V_5 -> V_134 ;
struct V_3 * V_52 = (struct V_3 * ) V_103 ;
struct V_115 V_156 ;
if ( ! V_133 || ! V_133 -> V_151 )
return 1 ;
switch ( V_103 [ 0 ] ) {
case 0x02 :
if ( V_160 < 2 ) {
F_25 ( V_2 , L_9 ,
V_160 ) ;
return 1 ;
}
if ( V_5 -> V_17 & V_145 ) {
F_49 ( V_133 -> V_151 , V_137 , V_144 ,
! ! ( V_103 [ 1 ] & 0x01 ) ) ;
F_49 ( V_133 -> V_151 , V_137 , V_146 ,
! ! ( V_103 [ 1 ] & 0x02 ) ) ;
F_52 ( V_133 -> V_151 ) ;
return 0 ;
} else {
if ( V_160 < 21 )
return 1 ;
return F_53 ( V_5 , & V_103 [ 7 ] ) ;
}
case V_11 :
if ( ( V_52 -> V_36 . V_37 != V_133 -> V_161 ) ||
( V_52 -> V_36 . V_40 != V_162 ) )
return 1 ;
F_36 ( V_5 , V_103 + 4 , & V_156 ) ;
F_50 ( V_5 , & V_156 ) ;
return 0 ;
}
return 0 ;
}
static int F_56 ( struct V_4 * V_5 )
{
struct V_132 * V_133 = V_5 -> V_134 ;
struct V_90 V_91 = { 0 } ;
V_19 V_62 ;
int V_7 ;
V_7 = F_23 ( V_5 , V_163 ,
& V_133 -> V_161 , & V_62 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_32 ( V_5 , V_133 -> V_161 ,
& V_91 ) ;
if ( V_7 )
return V_7 ;
V_133 -> V_93 = V_91 . V_93 ;
V_133 -> V_94 = V_91 . V_94 ;
V_133 -> V_97 = V_91 . V_97 ;
V_133 -> V_155 = V_91 . V_98 == V_164 ;
V_133 -> V_141 = V_91 . V_99 ;
if ( ! V_133 -> V_141 )
V_133 -> V_141 = V_165 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , const struct V_166 * V_167 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_132 * V_133 ;
V_133 = F_58 ( & V_2 -> V_168 , sizeof( struct V_132 ) ,
V_43 ) ;
if ( ! V_133 )
return - V_44 ;
V_5 -> V_134 = V_133 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , bool V_169 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_132 * V_133 = V_5 -> V_134 ;
int V_7 ;
if ( ! V_169 )
return 0 ;
if ( ! V_133 -> V_93 ) {
V_7 = F_56 ( V_5 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_10 , V_7 ) ;
return V_7 ;
}
}
return F_34 ( V_5 , V_133 -> V_161 ,
true , true ) ;
}
static int F_60 ( struct V_1 * V_2 , bool V_169 )
{
struct V_3 V_23 ;
struct V_4 * V_45 ;
V_45 = F_2 ( V_2 ) ;
if ( ! V_169 )
return - V_15 ;
return F_13 (
V_45 ,
V_9 ,
V_170 ,
V_171 ,
( V_19 * ) V_172 ,
sizeof( V_172 ) ,
& V_23
) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_173 * V_174 ;
V_174 = F_58 ( & V_2 -> V_168 , sizeof( struct V_173 ) ,
V_43 ) ;
if ( ! V_174 )
return - V_44 ;
V_5 -> V_134 = V_174 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , V_19 * V_103 , int V_160 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_173 * V_175 = V_5 -> V_134 ;
if ( ! V_175 || ! V_175 -> V_151 ) {
F_25 ( V_2 , L_11 ) ;
return - V_42 ;
}
if ( V_160 < 7 ) {
F_25 ( V_2 , L_12 ) ;
return 0 ;
}
if ( V_103 [ 0 ] == V_11 &&
V_103 [ 2 ] == V_170 && V_103 [ 6 ] == 0x00 ) {
switch ( V_103 [ 5 ] ) {
case 0xaf :
F_63 ( V_175 -> V_151 , V_176 , 1 ) ;
break;
case 0xb0 :
F_63 ( V_175 -> V_151 , V_177 , 1 ) ;
break;
case 0xae :
F_63 ( V_175 -> V_151 , V_178 , 1 ) ;
break;
case 0x00 :
F_63 ( V_175 -> V_151 , V_178 , 0 ) ;
F_63 ( V_175 -> V_151 , V_177 , 0 ) ;
F_63 ( V_175 -> V_151 , V_176 , 0 ) ;
break;
default:
F_25 ( V_2 , L_12 ) ;
return 0 ;
}
F_52 ( V_175 -> V_151 ) ;
} else if ( V_103 [ 0 ] == 0x02 ) {
int V_179 ;
F_63 ( V_175 -> V_151 , V_144 ,
! ! ( V_103 [ 1 ] & V_180 ) ) ;
F_63 ( V_175 -> V_151 , V_146 ,
! ! ( V_103 [ 1 ] & V_181 ) ) ;
if ( V_103 [ 1 ] & V_182 )
F_64 ( V_175 -> V_151 , V_183 , - 1 ) ;
else if ( V_103 [ 1 ] & V_184 )
F_64 ( V_175 -> V_151 , V_183 , 1 ) ;
V_179 = F_65 ( F_66 ( V_2 , V_103 + 3 , 0 , 12 ) , 12 ) ;
F_64 ( V_175 -> V_151 , V_185 , V_179 ) ;
V_179 = F_65 ( F_66 ( V_2 , V_103 + 3 , 12 , 12 ) , 12 ) ;
F_64 ( V_175 -> V_151 , V_186 , V_179 ) ;
V_179 = F_65 ( V_103 [ 6 ] , 8 ) ;
F_64 ( V_175 -> V_151 , V_187 , V_179 ) ;
F_52 ( V_175 -> V_151 ) ;
}
return 1 ;
}
static void F_67 ( struct V_4 * V_5 ,
struct V_130 * V_130 , bool V_131 )
{
struct V_173 * V_175 = V_5 -> V_134 ;
V_175 -> V_151 = V_130 ;
F_39 ( V_137 , V_175 -> V_151 -> V_136 ) ;
F_39 ( V_176 , V_175 -> V_151 -> V_188 ) ;
F_39 ( V_146 , V_175 -> V_151 -> V_188 ) ;
F_39 ( V_144 , V_175 -> V_151 -> V_188 ) ;
F_39 ( V_178 , V_175 -> V_151 -> V_188 ) ;
F_39 ( V_177 , V_175 -> V_151 -> V_188 ) ;
F_39 ( V_138 , V_175 -> V_151 -> V_136 ) ;
F_39 ( V_185 , V_175 -> V_151 -> V_189 ) ;
F_39 ( V_186 , V_175 -> V_151 -> V_189 ) ;
F_39 ( V_187 , V_175 -> V_151 -> V_189 ) ;
F_39 ( V_183 , V_175 -> V_151 -> V_189 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_122 * V_123 ,
struct V_124 * V_125 , struct V_126 * V_127 ,
unsigned long * * V_128 , int * V_129 )
{
return - 1 ;
}
static int F_69 ( struct V_4 * V_5 )
{
struct V_190 * V_191 = V_5 -> V_134 ;
struct V_83 V_84 = {} ;
int V_7 ;
V_19 V_62 ;
if ( ! V_191 -> V_37 ) {
V_7 = F_23 ( V_5 ,
V_192 ,
& V_191 -> V_37 , & V_62 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_31 ( V_5 , V_191 -> V_37 , & V_84 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_190 * V_191 ;
V_191 = F_58 ( & V_2 -> V_168 , sizeof( struct V_190 ) ,
V_43 ) ;
if ( ! V_191 )
return - V_44 ;
V_5 -> V_134 = V_191 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , bool V_169 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_169 )
return 0 ;
if ( ! V_193 )
return 0 ;
return F_69 ( V_5 ) ;
}
static T_2 F_72 ( struct V_194 * V_168 , struct V_195 * V_196 ,
char * V_197 )
{
struct V_1 * V_198 = F_73 ( V_168 ) ;
struct V_4 * V_5 = F_2 ( V_198 ) ;
struct V_199 * V_200 ;
V_200 = V_5 -> V_134 ;
if ( ! V_200 ) {
F_25 ( V_198 , L_13 ) ;
return - V_42 ;
}
return F_74 ( V_197 , V_201 , L_14 , V_200 -> V_202 ) ;
}
static T_2 F_75 ( struct V_194 * V_168 , struct V_195 * V_196 ,
const char * V_197 , T_3 V_78 )
{
struct V_1 * V_198 = F_73 ( V_168 ) ;
struct V_4 * V_5 = F_2 ( V_198 ) ;
struct V_199 * V_200 ;
struct V_3 V_23 ;
V_19 V_35 [ 2 ] ;
int V_7 ;
T_1 V_202 = F_76 ( V_197 , NULL , 10 ) ;
V_200 = V_5 -> V_134 ;
if ( ! V_200 ) {
F_25 ( V_198 , L_13 ) ;
return - V_42 ;
}
if ( V_202 < 180 )
V_202 = 180 ;
else if ( V_202 > 900 )
V_202 = 900 ;
V_35 [ 0 ] = V_202 >> 8 ;
V_35 [ 1 ] = V_202 & 0x00FF ;
V_7 = F_10 ( V_5 , V_200 -> V_203 ,
V_204 , V_35 , 2 , & V_23 ) ;
if ( V_7 )
return V_7 ;
V_200 -> V_202 = V_202 ;
return V_78 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_199 * V_200 ;
V_200 = F_58 ( & V_2 -> V_168 , sizeof( struct V_199 ) ,
V_43 ) ;
if ( ! V_200 )
return - V_44 ;
V_5 -> V_134 = V_200 ;
return 0 ;
}
static int F_78 ( struct V_4 * V_5 )
{
struct V_199 * V_200 = V_5 -> V_134 ;
struct V_3 V_23 ;
V_19 V_62 ;
V_19 V_37 ;
int V_7 ;
V_200 = V_5 -> V_134 ;
if ( ! V_200 ) {
F_25 ( V_5 -> V_27 , L_13 ) ;
return - V_42 ;
}
V_7 = F_23 ( V_5 , V_205 ,
& V_37 , & V_62 ) ;
if ( V_7 )
return V_7 ;
V_200 -> V_203 = V_37 ;
V_7 = F_10 ( V_5 , V_37 ,
V_206 , NULL , 0 , & V_23 ) ;
if ( V_7 > 0 ) {
F_25 ( V_5 -> V_27 , L_7 ,
V_30 , V_7 ) ;
return - V_71 ;
}
if ( V_7 )
return V_7 ;
V_200 -> V_202 = F_33 ( & V_23 . V_36 . V_35 [ 0 ] ) ;
V_7 = F_79 ( & ( V_5 -> V_27 -> V_168 ) , & V_207 ) ;
if ( V_7 )
F_80 ( V_5 -> V_27 , L_15 , V_7 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_122 * V_123 ,
struct V_124 * V_125 , struct V_126 * V_127 ,
unsigned long * * V_128 , int * V_129 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_17 & V_208 )
return F_37 ( V_2 , V_123 , V_125 , V_127 , V_128 , V_129 ) ;
else if ( V_5 -> V_17 & V_209 &&
V_125 -> V_210 != V_211 )
return F_68 ( V_2 , V_123 , V_125 , V_127 , V_128 , V_129 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_122 * V_123 ,
struct V_124 * V_125 , struct V_126 * V_127 ,
unsigned long * * V_128 , int * V_129 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_17 & V_212 ) {
if ( V_127 -> type == V_135 && ( V_127 -> V_213 == V_214 ||
V_127 -> V_213 == V_215 || V_127 -> V_213 == V_216 ||
V_127 -> V_213 == V_217 ) ) {
V_125 -> V_210 = V_218 ;
}
}
return 0 ;
}
static void F_83 ( struct V_4 * V_5 ,
struct V_130 * V_151 , bool V_131 )
{
if ( V_5 -> V_17 & V_208 )
F_38 ( V_5 , V_151 , V_131 ) ;
else if ( V_5 -> V_17 & V_209 )
F_67 ( V_5 , V_151 , V_131 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_122 * V_219 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_130 * V_151 = V_219 -> V_151 ;
F_83 ( V_5 , V_151 , true ) ;
return 0 ;
}
static int F_85 ( struct V_4 * V_5 , V_19 * V_103 ,
int V_160 )
{
struct V_3 * V_50 = V_5 -> V_25 ;
struct V_3 * V_51 = V_5 -> V_25 ;
struct V_3 * V_52 = (struct V_3 * ) V_103 ;
if ( F_86 ( F_87 ( & V_5 -> V_24 ) ) ) {
if ( F_17 ( V_50 , V_52 ) ||
F_18 ( V_50 , V_52 ) ) {
* V_51 = * V_52 ;
V_5 -> V_26 = true ;
F_88 ( & V_5 -> V_28 ) ;
return 1 ;
}
}
if ( F_86 ( F_19 ( V_52 ) ) ) {
F_89 ( & V_5 -> V_169 ,
! ( V_52 -> V_32 . V_35 [ 0 ] & ( 1 << 6 ) ) ) ;
if ( ( V_5 -> V_17 & V_220 ) &&
( F_90 ( & V_5 -> V_49 ) == 0 ) )
F_7 ( L_16 , V_30 ) ;
return 1 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_221 * V_52 ,
V_19 * V_103 , int V_160 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_7 = 0 ;
switch ( V_103 [ 0 ] ) {
case V_13 :
if ( V_160 != V_14 ) {
F_25 ( V_2 , L_17 ,
V_160 ) ;
return 1 ;
}
V_7 = F_85 ( V_5 , V_103 , V_160 ) ;
break;
case V_11 :
if ( V_160 != V_12 ) {
F_25 ( V_2 , L_17 ,
V_160 ) ;
return 1 ;
}
V_7 = F_85 ( V_5 , V_103 , V_160 ) ;
break;
case V_9 :
if ( V_160 != V_10 ) {
F_25 ( V_2 , L_17 ,
V_160 ) ;
return 1 ;
}
V_7 = F_85 ( V_5 , V_103 , V_160 ) ;
break;
}
if ( V_7 != 0 )
return V_7 ;
if ( V_5 -> V_17 & V_208 )
return F_55 ( V_2 , V_103 , V_160 ) ;
else if ( V_5 -> V_17 & V_209 )
return F_62 ( V_2 , V_103 , V_160 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 , bool V_222 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
char * V_53 ;
if ( V_222 )
V_53 = F_22 ( V_5 ) ;
else
V_53 = F_30 ( V_5 ) ;
if ( ! V_53 ) {
F_25 ( V_2 , L_18 ) ;
} else {
F_7 ( L_19 , V_53 ) ;
snprintf ( V_2 -> V_53 , sizeof( V_2 -> V_53 ) , L_20 , V_53 ) ;
}
F_12 ( V_53 ) ;
}
static int F_93 ( struct V_130 * V_168 )
{
struct V_1 * V_198 = F_94 ( V_168 ) ;
return F_95 ( V_198 ) ;
}
static void F_96 ( struct V_130 * V_168 )
{
struct V_1 * V_198 = F_94 ( V_168 ) ;
F_97 ( V_198 ) ;
}
static struct V_130 * F_98 ( struct V_1 * V_2 )
{
struct V_130 * V_130 = F_99 ( & V_2 -> V_168 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_130 )
return NULL ;
F_100 ( V_130 , V_2 ) ;
V_130 -> V_223 = F_93 ;
V_130 -> V_224 = F_96 ;
V_130 -> V_53 = V_5 -> V_53 ;
V_130 -> V_225 = V_2 -> V_225 ;
V_130 -> V_226 = V_2 -> V_226 ;
V_130 -> V_167 . V_227 = V_2 -> V_228 ;
V_130 -> V_167 . V_229 = V_2 -> V_229 ;
V_130 -> V_167 . V_230 = V_2 -> V_230 ;
V_130 -> V_167 . V_231 = V_2 -> V_231 ;
V_130 -> V_168 . V_232 = & V_2 -> V_168 ;
return V_130 ;
}
static void F_16 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_27 ;
int V_7 = 0 ;
bool V_169 = F_101 ( & V_5 -> V_169 ) ;
struct V_130 * V_151 ;
char * V_53 , * V_233 ;
if ( V_5 -> V_17 & V_208 ) {
V_7 = F_59 ( V_2 , V_169 ) ;
if ( V_7 )
return;
} else if ( V_5 -> V_17 & V_209 ) {
V_7 = F_60 ( V_2 , V_169 ) ;
if ( V_7 )
return;
} else if ( V_5 -> V_17 & V_234 ) {
V_7 = F_71 ( V_2 , V_169 ) ;
if ( V_7 )
return;
}
if ( ! V_169 || V_5 -> V_235 )
return;
if ( ! V_5 -> V_67 ) {
V_7 = ! F_26 ( V_5 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_21 ) ;
return;
}
F_102 ( V_2 , L_8 ,
V_5 -> V_67 , V_5 -> V_68 ) ;
}
if ( ! ( V_5 -> V_17 & V_236 ) )
return;
if ( ! V_5 -> V_53 || V_5 -> V_53 == V_2 -> V_53 ) {
V_53 = F_30 ( V_5 ) ;
if ( ! V_53 ) {
F_25 ( V_2 ,
L_18 ) ;
return;
}
V_233 = F_103 ( & V_2 -> V_168 , V_43 , L_20 , V_53 ) ;
F_12 ( V_53 ) ;
if ( ! V_233 )
return;
V_5 -> V_53 = V_233 ;
}
V_151 = F_98 ( V_2 ) ;
if ( ! V_151 ) {
F_25 ( V_2 , L_22 , V_7 ) ;
return;
}
F_83 ( V_5 , V_151 , false ) ;
V_7 = F_104 ( V_151 ) ;
if ( V_7 )
F_105 ( V_151 ) ;
V_5 -> V_235 = V_151 ;
}
static int F_106 ( struct V_1 * V_2 , const struct V_166 * V_167 )
{
struct V_4 * V_5 ;
int V_7 ;
bool V_169 ;
unsigned int V_237 = V_238 ;
V_5 = F_58 ( & V_2 -> V_168 , sizeof( struct V_4 ) ,
V_43 ) ;
if ( ! V_5 )
return - V_44 ;
V_5 -> V_27 = V_2 ;
V_5 -> V_53 = V_2 -> V_53 ;
F_107 ( V_2 , V_5 ) ;
V_5 -> V_17 = V_167 -> V_239 ;
if ( V_240 ) {
V_5 -> V_17 &= ~ V_208 ;
V_5 -> V_17 &= ~ V_220 ;
V_5 -> V_17 &= ~ V_236 ;
}
if ( V_5 -> V_17 & V_208 ) {
V_7 = F_57 ( V_2 , V_167 ) ;
if ( V_7 )
goto V_241;
} else if ( V_5 -> V_17 & V_209 ) {
V_7 = F_61 ( V_2 ) ;
if ( V_7 )
goto V_241;
} else if ( V_5 -> V_17 & V_234 ) {
V_7 = F_70 ( V_2 ) ;
if ( V_7 )
goto V_241;
} else if ( V_5 -> V_17 & V_212 ) {
V_7 = F_77 ( V_2 ) ;
if ( V_7 )
goto V_241;
}
F_108 ( & V_5 -> V_49 , F_14 ) ;
F_109 ( & V_5 -> V_24 ) ;
F_110 ( & V_5 -> V_28 ) ;
V_7 = F_111 ( V_2 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_23 , V_30 ) ;
goto V_242;
}
if ( V_5 -> V_17 & V_236 )
V_237 &= ~ V_243 ;
if ( V_5 -> V_17 & V_212 ) {
V_7 = F_112 ( V_2 , V_237 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_24 ) ;
goto V_244;
}
V_7 = F_95 ( V_2 ) ;
if ( V_7 < 0 ) {
F_113 ( & V_2 -> V_168 , L_25 ,
V_30 , V_7 ) ;
F_114 ( V_2 ) ;
goto V_244;
}
}
F_115 ( V_2 ) ;
V_169 = F_26 ( V_5 ) ;
if ( V_167 -> V_245 != V_246 ) {
if ( ! V_169 ) {
V_7 = - V_15 ;
F_25 ( V_2 , L_26 ) ;
goto V_247;
}
F_102 ( V_2 , L_8 ,
V_5 -> V_67 , V_5 -> V_68 ) ;
}
F_92 ( V_2 , V_167 -> V_245 == V_246 ) ;
F_89 ( & V_5 -> V_169 , V_169 ) ;
if ( V_169 && ( V_5 -> V_17 & V_208 ) ) {
V_7 = F_56 ( V_5 ) ;
if ( V_7 )
goto V_247;
} else if ( V_169 && ( V_5 -> V_17 & V_212 ) ) {
V_7 = F_78 ( V_5 ) ;
if ( V_7 )
goto V_247;
}
F_116 ( V_2 ) ;
if ( ! ( V_5 -> V_17 & V_212 ) ) {
V_7 = F_112 ( V_2 , V_237 ) ;
if ( V_7 ) {
F_25 ( V_2 , L_27 , V_30 ) ;
goto V_244;
}
}
if ( V_5 -> V_17 & V_220 ) {
F_115 ( V_2 ) ;
F_16 ( V_5 ) ;
}
return V_7 ;
V_247:
F_116 ( V_2 ) ;
if ( V_5 -> V_17 & V_212 ) {
F_117 ( & V_2 -> V_168 , & V_207 ) ;
F_97 ( V_2 ) ;
F_114 ( V_2 ) ;
}
V_244:
V_242:
F_118 ( & V_5 -> V_49 ) ;
F_119 ( & V_5 -> V_24 ) ;
V_241:
F_107 ( V_2 , NULL ) ;
return V_7 ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_17 & V_212 ) {
F_117 ( & V_2 -> V_168 , & V_207 ) ;
F_97 ( V_2 ) ;
}
F_114 ( V_2 ) ;
F_118 ( & V_5 -> V_49 ) ;
F_119 ( & V_5 -> V_24 ) ;
}
