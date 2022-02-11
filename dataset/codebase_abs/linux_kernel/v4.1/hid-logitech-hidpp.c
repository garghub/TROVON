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
V_13 V_33 , struct V_78 * V_79 )
{
struct V_3 V_19 ;
int V_5 ;
V_13 * V_31 = ( V_13 * ) V_19 . V_32 . V_31 ;
V_5 = F_8 ( V_17 , V_33 ,
V_80 , NULL , 0 , & V_19 ) ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_7 ,
V_26 , V_5 ) ;
return - V_66 ;
}
if ( V_5 )
return V_5 ;
V_79 -> V_81 = F_30 ( & V_31 [ 0 ] ) ;
V_79 -> V_82 = F_30 ( & V_31 [ 2 ] ) ;
V_79 -> V_83 = V_31 [ 4 ] ;
V_79 -> V_84 = V_31 [ 5 ] ;
V_79 -> V_85 = V_31 [ 7 ] ;
V_79 -> V_86 = V_31 [ 8 ] ;
V_79 -> V_87 = F_30 ( & V_31 [ 13 ] ) * 2 / 51 ;
return V_5 ;
}
static int F_31 ( struct V_16 * V_41 ,
V_13 V_33 , bool V_88 ,
bool V_89 )
{
struct V_3 V_19 ;
V_13 V_31 = V_88 | ( V_89 << 2 ) ;
return F_8 ( V_41 , V_33 ,
V_90 , & V_31 , 1 , & V_19 ) ;
}
static void F_32 ( V_13 * V_91 ,
struct V_92 * V_93 )
{
V_13 V_94 = V_91 [ 0 ] << 2 ;
V_13 V_95 = V_91 [ 2 ] << 2 ;
V_93 -> V_96 = V_94 << 6 | V_91 [ 1 ] ;
V_93 -> V_97 = V_95 << 6 | V_91 [ 3 ] ;
V_93 -> V_98 = V_91 [ 0 ] >> 6 ;
V_93 -> V_99 = V_91 [ 2 ] >> 6 ;
V_93 -> V_100 = V_91 [ 4 ] ;
V_93 -> V_101 = V_91 [ 5 ] ;
V_93 -> V_102 = V_91 [ 6 ] >> 4 ;
}
static void F_33 ( struct V_16 * V_41 ,
V_13 * V_91 , struct V_103 * V_104 )
{
memset ( V_104 , 0 , sizeof( struct V_103 ) ) ;
V_104 -> V_105 = V_91 [ 8 ] & 0x01 ;
V_104 -> V_106 = ( V_91 [ 8 ] >> 1 ) & 0x01 ;
V_104 -> V_107 = V_91 [ 15 ] & 0x0f ;
V_104 -> V_108 = ( V_91 [ 8 ] >> 2 ) & 0x01 ;
if ( V_104 -> V_107 ) {
F_32 ( & V_91 [ 2 ] , & V_104 -> V_109 [ 0 ] ) ;
F_32 ( & V_91 [ 9 ] , & V_104 -> V_109 [ 1 ] ) ;
}
}
static int F_34 ( struct V_1 * V_2 , struct V_110 * V_111 ,
struct V_112 * V_113 , struct V_114 * V_115 ,
unsigned long * * V_116 , int * V_117 )
{
return - 1 ;
}
static void F_35 ( struct V_16 * V_17 ,
struct V_118 * V_118 , bool V_119 )
{
struct V_120 * V_121 = V_17 -> V_122 ;
F_36 ( V_123 , V_118 -> V_124 ) ;
F_36 ( V_125 , V_118 -> V_124 ) ;
F_37 ( V_126 , V_118 -> V_124 ) ;
F_37 ( V_127 , V_118 -> V_124 ) ;
F_38 ( V_118 , V_128 , 0 , V_121 -> V_81 , 0 , 0 ) ;
F_39 ( V_118 , V_128 , V_121 -> V_129 ) ;
F_38 ( V_118 , V_130 , 0 , V_121 -> V_82 , 0 , 0 ) ;
F_39 ( V_118 , V_130 , V_121 -> V_129 ) ;
F_38 ( V_118 , V_131 , 0 , 50 , 0 , 0 ) ;
F_40 ( V_118 , V_125 , V_132 ) ;
if ( V_17 -> V_133 & V_134 )
F_40 ( V_118 , V_125 , V_135 ) ;
else
F_36 ( V_136 , V_118 -> V_137 ) ;
F_41 ( V_118 , V_121 -> V_85 , V_138 |
V_139 ) ;
V_121 -> V_140 = V_118 ;
}
static void F_42 ( struct V_120 * V_121 ,
struct V_92 * V_141 )
{
int V_142 ;
if ( ! V_141 -> V_102 || V_141 -> V_98 )
return;
V_142 = F_43 ( V_121 -> V_140 , V_141 -> V_102 ) ;
F_44 ( V_121 -> V_140 , V_142 ) ;
F_45 ( V_121 -> V_140 , V_143 ,
V_141 -> V_99 ) ;
if ( V_141 -> V_99 ) {
F_46 ( V_121 -> V_140 , V_123 , V_128 ,
V_141 -> V_96 ) ;
F_46 ( V_121 -> V_140 , V_123 , V_130 ,
V_121 -> V_144 ? V_121 -> V_82 - V_141 -> V_97 :
V_141 -> V_97 ) ;
F_46 ( V_121 -> V_140 , V_123 , V_131 ,
V_141 -> V_101 ) ;
}
}
static void F_47 ( struct V_16 * V_17 ,
struct V_103 * V_145 )
{
struct V_120 * V_121 = V_17 -> V_122 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ )
F_42 ( V_121 , & ( V_145 -> V_109 [ V_72 ] ) ) ;
if ( V_145 -> V_105 &&
! ( V_17 -> V_133 & V_134 ) )
F_46 ( V_121 -> V_140 , V_125 , V_132 , V_145 -> V_108 ) ;
if ( V_145 -> V_105 || V_145 -> V_107 <= 2 ) {
F_48 ( V_121 -> V_140 ) ;
F_49 ( V_121 -> V_140 ) ;
}
}
static int F_50 ( struct V_16 * V_17 , V_13 * V_91 )
{
struct V_120 * V_121 = V_17 -> V_122 ;
V_13 V_146 = ( ( V_91 [ 7 ] & 0xf ) * ( V_91 [ 7 ] & 0xf ) +
( V_91 [ 7 ] >> 4 ) * ( V_91 [ 7 ] >> 4 ) ) / 2 ;
V_13 V_147 = ( ( V_91 [ 13 ] & 0xf ) * ( V_91 [ 13 ] & 0xf ) +
( V_91 [ 13 ] >> 4 ) * ( V_91 [ 13 ] >> 4 ) ) / 2 ;
struct V_103 V_145 = {
. V_148 = V_91 [ 1 ] ,
. V_109 = {
{
. V_98 = 0 ,
. V_99 = ! ! V_91 [ 7 ] ,
. V_96 = F_51 ( & V_91 [ 3 ] ) ,
. V_97 = F_51 ( & V_91 [ 5 ] ) ,
. V_100 = V_146 ,
. V_101 = V_146 ,
. V_102 = V_91 [ 2 ] ,
} , {
. V_98 = 0 ,
. V_99 = ! ! V_91 [ 13 ] ,
. V_96 = F_51 ( & V_91 [ 9 ] ) ,
. V_97 = F_51 ( & V_91 [ 11 ] ) ,
. V_100 = V_147 ,
. V_101 = V_147 ,
. V_102 = V_91 [ 8 ] ,
}
} ,
. V_107 = V_121 -> V_85 ,
. V_106 = 0 ,
. V_105 = ( V_91 [ 0 ] >> 7 ) == 0 ,
. V_108 = V_91 [ 0 ] & 0x01 ,
} ;
F_47 ( V_17 , & V_145 ) ;
return 1 ;
}
static int F_52 ( struct V_1 * V_2 , V_13 * V_91 , int V_149 )
{
struct V_16 * V_17 = F_53 ( V_2 ) ;
struct V_120 * V_121 = V_17 -> V_122 ;
struct V_3 * V_47 = (struct V_3 * ) V_91 ;
struct V_103 V_145 ;
if ( ! V_121 || ! V_121 -> V_140 )
return 1 ;
switch ( V_91 [ 0 ] ) {
case 0x02 :
if ( V_149 < 2 ) {
F_23 ( V_2 , L_9 ,
V_149 ) ;
return 1 ;
}
if ( V_17 -> V_133 & V_134 ) {
F_46 ( V_121 -> V_140 , V_125 , V_132 ,
! ! ( V_91 [ 1 ] & 0x01 ) ) ;
F_46 ( V_121 -> V_140 , V_125 , V_135 ,
! ! ( V_91 [ 1 ] & 0x02 ) ) ;
F_49 ( V_121 -> V_140 ) ;
return 0 ;
} else {
if ( V_149 < 21 )
return 1 ;
return F_50 ( V_17 , & V_91 [ 7 ] ) ;
}
case V_9 :
if ( ( V_47 -> V_32 . V_33 != V_121 -> V_150 ) ||
( V_47 -> V_32 . V_36 != V_151 ) )
return 1 ;
F_33 ( V_17 , V_91 + 4 , & V_145 ) ;
F_47 ( V_17 , & V_145 ) ;
return 0 ;
}
return 0 ;
}
static int F_54 ( struct V_16 * V_17 )
{
struct V_120 * V_121 = V_17 -> V_122 ;
struct V_78 V_79 = { 0 } ;
V_13 V_57 ;
int V_5 ;
V_5 = F_21 ( V_17 , V_152 ,
& V_121 -> V_150 , & V_57 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_29 ( V_17 , V_121 -> V_150 ,
& V_79 ) ;
if ( V_5 )
return V_5 ;
V_121 -> V_81 = V_79 . V_81 ;
V_121 -> V_82 = V_79 . V_82 ;
V_121 -> V_85 = V_79 . V_85 ;
V_121 -> V_144 = V_79 . V_86 == V_153 ;
V_121 -> V_129 = V_79 . V_87 ;
if ( ! V_121 -> V_129 )
V_121 -> V_129 = V_154 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , const struct V_155 * V_156 )
{
struct V_16 * V_17 = F_53 ( V_2 ) ;
struct V_120 * V_121 ;
V_121 = F_56 ( & V_2 -> V_157 , sizeof( struct V_120 ) ,
V_39 ) ;
if ( ! V_121 )
return - V_40 ;
V_17 -> V_122 = V_121 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , bool V_158 )
{
struct V_16 * V_17 = F_53 ( V_2 ) ;
struct V_120 * V_121 = V_17 -> V_122 ;
int V_5 ;
if ( ! V_158 )
return 0 ;
if ( ! V_121 -> V_81 ) {
V_5 = F_54 ( V_17 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_10 , V_5 ) ;
return V_5 ;
}
}
return F_31 ( V_17 , V_121 -> V_150 ,
true , true ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_110 * V_111 ,
struct V_112 * V_113 , struct V_114 * V_115 ,
unsigned long * * V_116 , int * V_117 )
{
struct V_16 * V_17 = F_53 ( V_2 ) ;
if ( V_17 -> V_133 & V_159 )
return F_34 ( V_2 , V_111 , V_113 , V_115 , V_116 , V_117 ) ;
return 0 ;
}
static void F_59 ( struct V_16 * V_17 ,
struct V_118 * V_140 , bool V_119 )
{
if ( V_17 -> V_133 & V_159 )
F_35 ( V_17 , V_140 , V_119 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_110 * V_160 )
{
struct V_16 * V_17 = F_53 ( V_2 ) ;
struct V_118 * V_140 = V_160 -> V_140 ;
F_59 ( V_17 , V_140 , true ) ;
}
static int F_61 ( struct V_16 * V_17 , V_13 * V_91 ,
int V_149 )
{
struct V_3 * V_45 = V_17 -> V_21 ;
struct V_3 * V_46 = V_17 -> V_21 ;
struct V_3 * V_47 = (struct V_3 * ) V_91 ;
if ( F_62 ( F_63 ( & V_17 -> V_20 ) ) ) {
if ( F_15 ( V_45 , V_47 ) ||
F_16 ( V_45 , V_47 ) ) {
* V_46 = * V_47 ;
V_17 -> V_22 = true ;
F_64 ( & V_17 -> V_24 ) ;
return 1 ;
}
}
if ( F_62 ( F_17 ( V_47 ) ) ) {
F_65 ( & V_17 -> V_158 ,
! ( V_47 -> V_28 . V_31 [ 0 ] & ( 1 << 6 ) ) ) ;
if ( ( V_17 -> V_133 & V_161 ) &&
( F_66 ( & V_17 -> V_44 ) == 0 ) )
F_5 ( L_11 , V_26 ) ;
return 1 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_162 * V_47 ,
V_13 * V_91 , int V_149 )
{
struct V_16 * V_17 = F_53 ( V_2 ) ;
int V_5 = 0 ;
switch ( V_91 [ 0 ] ) {
case V_9 :
if ( V_149 != V_10 ) {
F_23 ( V_2 , L_12 ,
V_149 ) ;
return 1 ;
}
V_5 = F_61 ( V_17 , V_91 , V_149 ) ;
break;
case V_7 :
if ( V_149 != V_8 ) {
F_23 ( V_2 , L_12 ,
V_149 ) ;
return 1 ;
}
V_5 = F_61 ( V_17 , V_91 , V_149 ) ;
break;
}
if ( V_5 != 0 )
return V_5 ;
if ( V_17 -> V_133 & V_159 )
return F_52 ( V_2 , V_91 , V_149 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , bool V_163 )
{
struct V_16 * V_17 = F_53 ( V_2 ) ;
char * V_48 ;
if ( V_163 )
V_48 = F_20 ( V_17 ) ;
else
V_48 = F_28 ( V_17 ) ;
if ( ! V_48 )
F_23 ( V_2 , L_13 ) ;
else
snprintf ( V_2 -> V_48 , sizeof( V_2 -> V_48 ) , L_14 , V_48 ) ;
F_10 ( V_48 ) ;
}
static int F_69 ( struct V_118 * V_157 )
{
struct V_1 * V_164 = F_70 ( V_157 ) ;
return F_71 ( V_164 ) ;
}
static void F_72 ( struct V_118 * V_157 )
{
struct V_1 * V_164 = F_70 ( V_157 ) ;
F_73 ( V_164 ) ;
}
static struct V_118 * F_74 ( struct V_1 * V_2 )
{
struct V_118 * V_118 = F_75 ( & V_2 -> V_157 ) ;
struct V_16 * V_17 = F_53 ( V_2 ) ;
if ( ! V_118 )
return NULL ;
F_76 ( V_118 , V_2 ) ;
V_118 -> V_165 = F_69 ;
V_118 -> V_166 = F_72 ;
V_118 -> V_48 = V_17 -> V_48 ;
V_118 -> V_167 = V_2 -> V_167 ;
V_118 -> V_168 = V_2 -> V_168 ;
V_118 -> V_156 . V_169 = V_2 -> V_170 ;
V_118 -> V_156 . V_171 = V_2 -> V_171 ;
V_118 -> V_156 . V_172 = V_2 -> V_172 ;
V_118 -> V_156 . V_173 = V_2 -> V_173 ;
V_118 -> V_157 . V_174 = & V_2 -> V_157 ;
return V_118 ;
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_23 ;
int V_5 = 0 ;
bool V_158 = F_77 ( & V_17 -> V_158 ) ;
struct V_118 * V_140 ;
char * V_48 , * V_175 ;
if ( V_17 -> V_133 & V_159 ) {
V_5 = F_57 ( V_2 , V_158 ) ;
if ( V_5 )
return;
}
if ( ! V_158 || V_17 -> V_176 )
return;
if ( ! V_17 -> V_62 ) {
V_5 = ! F_24 ( V_17 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_15 ) ;
return;
}
}
F_78 ( V_2 , L_8 ,
V_17 -> V_62 , V_17 -> V_63 ) ;
if ( ! V_17 -> V_48 || V_17 -> V_48 == V_2 -> V_48 ) {
V_48 = F_28 ( V_17 ) ;
if ( ! V_48 ) {
F_23 ( V_2 ,
L_13 ) ;
return;
}
V_175 = F_79 ( & V_2 -> V_157 , V_39 , L_14 , V_48 ) ;
F_10 ( V_48 ) ;
if ( ! V_175 )
return;
V_17 -> V_48 = V_175 ;
}
V_140 = F_74 ( V_2 ) ;
if ( ! V_140 ) {
F_23 ( V_2 , L_16 , V_5 ) ;
return;
}
F_59 ( V_17 , V_140 , false ) ;
V_5 = F_80 ( V_140 ) ;
if ( V_5 )
F_81 ( V_140 ) ;
V_17 -> V_176 = V_140 ;
}
static int F_82 ( struct V_1 * V_2 , const struct V_155 * V_156 )
{
struct V_16 * V_17 ;
int V_5 ;
bool V_158 ;
unsigned int V_177 = V_178 ;
V_17 = F_56 ( & V_2 -> V_157 , sizeof( struct V_16 ) ,
V_39 ) ;
if ( ! V_17 )
return - V_40 ;
V_17 -> V_23 = V_2 ;
V_17 -> V_48 = V_2 -> V_48 ;
F_83 ( V_2 , V_17 ) ;
V_17 -> V_133 = V_156 -> V_179 ;
if ( V_180 ) {
V_17 -> V_133 &= ~ V_159 ;
V_17 -> V_133 &= ~ V_161 ;
}
if ( V_17 -> V_133 & V_159 ) {
V_5 = F_55 ( V_2 , V_156 ) ;
if ( V_5 )
goto V_181;
}
F_84 ( & V_17 -> V_44 , F_12 ) ;
F_85 ( & V_17 -> V_20 ) ;
F_86 ( & V_17 -> V_24 ) ;
V_5 = F_87 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_17 , V_26 ) ;
goto V_182;
}
F_88 ( V_2 ) ;
V_158 = F_24 ( V_17 ) ;
if ( V_156 -> V_183 != V_184 ) {
if ( ! V_158 ) {
V_5 = - V_11 ;
F_23 ( V_2 , L_18 ) ;
F_89 ( V_2 ) ;
goto V_182;
}
F_78 ( V_2 , L_8 ,
V_17 -> V_62 , V_17 -> V_63 ) ;
}
F_68 ( V_2 , V_156 -> V_183 == V_184 ) ;
F_65 ( & V_17 -> V_158 , V_158 ) ;
if ( V_158 && ( V_17 -> V_133 & V_159 ) ) {
V_5 = F_54 ( V_17 ) ;
if ( V_5 )
goto V_182;
}
F_89 ( V_2 ) ;
if ( V_17 -> V_133 & V_161 )
V_177 &= ~ V_185 ;
V_5 = F_90 ( V_2 , V_177 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_19 , V_26 ) ;
goto V_186;
}
if ( V_17 -> V_133 & V_161 ) {
F_88 ( V_2 ) ;
F_14 ( V_17 ) ;
}
return V_5 ;
V_186:
V_182:
F_91 ( & V_17 -> V_44 ) ;
F_92 ( & V_17 -> V_20 ) ;
V_181:
F_83 ( V_2 , NULL ) ;
return V_5 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_53 ( V_2 ) ;
F_91 ( & V_17 -> V_44 ) ;
F_92 ( & V_17 -> V_20 ) ;
F_94 ( V_2 ) ;
}
