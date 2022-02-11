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
F_5 ( L_3 , V_5 ) ;
goto exit;
}
exit:
F_7 ( & V_17 -> V_20 ) ;
return V_5 ;
}
static int F_8 ( struct V_16 * V_17 ,
V_13 V_32 , V_13 V_33 , V_13 * V_31 , int V_34 ,
struct V_3 * V_19 )
{
struct V_3 * V_18 ;
int V_5 ;
if ( V_34 > sizeof( V_18 -> V_28 . V_31 ) )
return - V_35 ;
V_18 = F_9 ( sizeof( struct V_3 ) , V_36 ) ;
if ( ! V_18 )
return - V_37 ;
V_18 -> V_6 = V_9 ;
V_18 -> V_28 . V_29 = V_32 ;
V_18 -> V_28 . V_33 = V_33 ;
memcpy ( & V_18 -> V_28 . V_31 , V_31 , V_34 ) ;
V_5 = F_3 ( V_17 , V_18 , V_19 ) ;
F_10 ( V_18 ) ;
return V_5 ;
}
static int F_11 ( struct V_16 * V_38 ,
V_13 V_6 , V_13 V_39 , V_13 V_40 , V_13 * V_31 , int V_34 ,
struct V_3 * V_19 )
{
struct V_3 * V_18 ;
int V_5 ;
if ( ( V_6 != V_7 ) &&
( V_6 != V_9 ) )
return - V_35 ;
if ( V_34 > sizeof( V_18 -> V_41 . V_31 ) )
return - V_35 ;
V_18 = F_9 ( sizeof( struct V_3 ) , V_36 ) ;
if ( ! V_18 )
return - V_37 ;
V_18 -> V_6 = V_6 ;
V_18 -> V_41 . V_39 = V_39 ;
V_18 -> V_41 . V_40 = V_40 ;
memcpy ( & V_18 -> V_41 . V_31 , V_31 , V_34 ) ;
V_5 = F_3 ( V_38 , V_18 , V_19 ) ;
F_10 ( V_18 ) ;
return V_5 ;
}
static void F_12 ( struct V_42 * V_43 )
{
struct V_16 * V_17 = F_13 ( V_43 , struct V_16 ,
V_43 ) ;
F_14 ( V_17 ) ;
}
static inline bool F_15 ( struct V_3 * V_44 ,
struct V_3 * V_45 )
{
return ( V_45 -> V_28 . V_29 == V_44 -> V_28 . V_29 ) &&
( V_45 -> V_28 . V_33 == V_44 -> V_28 . V_33 ) ;
}
static inline bool F_16 ( struct V_3 * V_44 ,
struct V_3 * V_45 )
{
return ( V_45 -> V_28 . V_29 == V_30 ) &&
( V_45 -> V_28 . V_33 == V_44 -> V_28 . V_29 ) &&
( V_45 -> V_28 . V_31 [ 0 ] == V_44 -> V_28 . V_33 ) ;
}
static inline bool F_17 ( struct V_3 * V_46 )
{
return ( V_46 -> V_6 == V_7 ) &&
( V_46 -> V_41 . V_39 == 0x41 ) ;
}
static void F_18 ( char * * V_47 , int V_48 )
{
#define F_19 9
int V_49 ;
char * V_50 ;
if ( V_48 > F_19 &&
strncmp ( * V_47 , L_4 , F_19 ) == 0 )
return;
V_49 = F_19 + V_48 ;
V_50 = F_9 ( V_49 , V_36 ) ;
if ( ! V_50 )
return;
snprintf ( V_50 , V_49 , L_5 , * V_47 ) ;
F_10 ( * V_47 ) ;
* V_47 = V_50 ;
}
static char * F_20 ( struct V_16 * V_38 )
{
struct V_3 V_19 ;
int V_5 ;
V_13 V_31 [ 1 ] = { V_51 } ;
char * V_47 ;
int V_52 ;
V_5 = F_11 ( V_38 ,
V_7 ,
V_53 ,
V_54 ,
V_31 , 1 , & V_19 ) ;
if ( V_5 )
return NULL ;
V_52 = V_19 . V_41 . V_31 [ 1 ] ;
if ( 2 + V_52 > sizeof( V_19 . V_41 . V_31 ) )
return NULL ;
V_47 = F_9 ( V_52 + 1 , V_36 ) ;
if ( ! V_47 )
return NULL ;
memcpy ( V_47 , & V_19 . V_41 . V_31 [ 2 ] , V_52 ) ;
F_18 ( & V_47 , V_52 + 1 ) ;
return V_47 ;
}
static int F_21 ( struct V_16 * V_17 , T_1 V_55 ,
V_13 * V_29 , V_13 * V_56 )
{
struct V_3 V_19 ;
int V_5 ;
V_13 V_31 [ 2 ] = { V_55 >> 8 , V_55 & 0x00FF } ;
V_5 = F_8 ( V_17 ,
V_57 ,
V_58 ,
V_31 , 2 , & V_19 ) ;
if ( V_5 )
return V_5 ;
* V_29 = V_19 . V_28 . V_31 [ 0 ] ;
* V_56 = V_19 . V_28 . V_31 [ 1 ] ;
return V_5 ;
}
static int F_22 ( struct V_16 * V_17 )
{
struct V_3 V_19 ;
int V_5 ;
V_5 = F_8 ( V_17 ,
V_57 ,
V_59 ,
NULL , 0 , & V_19 ) ;
if ( V_5 == V_60 ) {
V_17 -> V_61 = 1 ;
V_17 -> V_62 = 0 ;
return 0 ;
}
if ( V_5 == V_63 )
return - V_64 ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_6 ,
V_26 , V_5 ) ;
return - V_65 ;
}
if ( V_5 )
return V_5 ;
V_17 -> V_61 = V_19 . V_28 . V_31 [ 0 ] ;
V_17 -> V_62 = V_19 . V_28 . V_31 [ 1 ] ;
return V_5 ;
}
static bool F_24 ( struct V_16 * V_17 )
{
int V_5 ;
V_5 = F_22 ( V_17 ) ;
if ( ! V_5 )
F_25 ( V_17 -> V_23 , L_7 ,
V_17 -> V_61 , V_17 -> V_62 ) ;
return V_5 == 0 ;
}
static int F_26 ( struct V_16 * V_17 ,
V_13 V_29 , V_13 * V_66 )
{
struct V_3 V_19 ;
int V_5 ;
V_5 = F_8 ( V_17 , V_29 ,
V_67 , NULL , 0 , & V_19 ) ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_6 ,
V_26 , V_5 ) ;
return - V_65 ;
}
if ( V_5 )
return V_5 ;
* V_66 = V_19 . V_28 . V_31 [ 0 ] ;
return V_5 ;
}
static int F_27 ( struct V_16 * V_17 ,
V_13 V_29 , V_13 V_68 , char * V_69 , int V_70 )
{
struct V_3 V_19 ;
int V_5 , V_71 ;
int V_72 ;
V_5 = F_8 ( V_17 , V_29 ,
V_73 , & V_68 , 1 ,
& V_19 ) ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_6 ,
V_26 , V_5 ) ;
return - V_65 ;
}
if ( V_5 )
return V_5 ;
if ( V_19 . V_6 == V_9 )
V_72 = V_10 - 4 ;
else
V_72 = V_8 - 4 ;
if ( V_70 < V_72 )
V_72 = V_70 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ )
V_69 [ V_71 ] = V_19 . V_28 . V_31 [ V_71 ] ;
return V_72 ;
}
static char * F_28 ( struct V_16 * V_17 )
{
V_13 V_56 ;
V_13 V_29 ;
V_13 V_74 ;
char * V_47 ;
unsigned V_75 = 0 ;
int V_5 ;
V_5 = F_21 ( V_17 , V_76 ,
& V_29 , & V_56 ) ;
if ( V_5 )
return NULL ;
V_5 = F_26 ( V_17 , V_29 ,
& V_74 ) ;
if ( V_5 )
return NULL ;
V_47 = F_9 ( V_74 + 1 , V_36 ) ;
if ( ! V_47 )
return NULL ;
while ( V_75 < V_74 ) {
V_5 = F_27 ( V_17 ,
V_29 , V_75 , V_47 + V_75 ,
V_74 - V_75 ) ;
if ( V_5 <= 0 ) {
F_10 ( V_47 ) ;
return NULL ;
}
V_75 += V_5 ;
}
F_18 ( & V_47 , V_74 + 1 ) ;
return V_47 ;
}
static int F_29 ( struct V_16 * V_17 ,
V_13 V_29 , struct V_77 * V_78 )
{
struct V_3 V_19 ;
int V_5 ;
V_13 * V_31 = ( V_13 * ) V_19 . V_28 . V_31 ;
V_5 = F_8 ( V_17 , V_29 ,
V_79 , NULL , 0 , & V_19 ) ;
if ( V_5 > 0 ) {
F_23 ( V_17 -> V_23 , L_6 ,
V_26 , V_5 ) ;
return - V_65 ;
}
if ( V_5 )
return V_5 ;
V_78 -> V_80 = F_30 ( & V_31 [ 0 ] ) ;
V_78 -> V_81 = F_30 ( & V_31 [ 2 ] ) ;
V_78 -> V_82 = V_31 [ 4 ] ;
V_78 -> V_83 = V_31 [ 5 ] ;
V_78 -> V_84 = V_31 [ 7 ] ;
V_78 -> V_85 = V_31 [ 8 ] ;
V_78 -> V_86 = F_30 ( & V_31 [ 13 ] ) * 2 / 51 ;
return V_5 ;
}
static int F_31 ( struct V_16 * V_38 ,
V_13 V_29 , bool V_87 ,
bool V_88 )
{
struct V_3 V_19 ;
V_13 V_31 = V_87 | ( V_88 << 2 ) ;
return F_8 ( V_38 , V_29 ,
V_89 , & V_31 , 1 , & V_19 ) ;
}
static void F_32 ( V_13 * V_90 ,
struct V_91 * V_92 )
{
V_13 V_93 = V_90 [ 0 ] << 2 ;
V_13 V_94 = V_90 [ 2 ] << 2 ;
V_92 -> V_95 = V_93 << 6 | V_90 [ 1 ] ;
V_92 -> V_96 = V_94 << 6 | V_90 [ 3 ] ;
V_92 -> V_97 = V_90 [ 0 ] >> 6 ;
V_92 -> V_98 = V_90 [ 2 ] >> 6 ;
V_92 -> V_99 = V_90 [ 4 ] ;
V_92 -> V_100 = V_90 [ 5 ] ;
V_92 -> V_101 = V_90 [ 6 ] >> 4 ;
}
static void F_33 ( struct V_16 * V_38 ,
V_13 * V_90 , struct V_102 * V_103 )
{
memset ( V_103 , 0 , sizeof( struct V_102 ) ) ;
V_103 -> V_104 = V_90 [ 8 ] & 0x01 ;
V_103 -> V_105 = ( V_90 [ 8 ] >> 1 ) & 0x01 ;
V_103 -> V_106 = V_90 [ 15 ] & 0x0f ;
V_103 -> V_107 = ( V_90 [ 8 ] >> 2 ) & 0x01 ;
if ( V_103 -> V_106 ) {
F_32 ( & V_90 [ 2 ] , & V_103 -> V_108 [ 0 ] ) ;
F_32 ( & V_90 [ 9 ] , & V_103 -> V_108 [ 1 ] ) ;
}
}
static int F_34 ( struct V_1 * V_2 , struct V_109 * V_110 ,
struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned long * * V_115 , int * V_116 )
{
struct V_16 * V_17 = F_35 ( V_2 ) ;
if ( ( V_17 -> V_117 & V_118 ) &&
( V_112 -> V_119 == V_120 ) )
return 0 ;
return - 1 ;
}
static void F_36 ( struct V_16 * V_17 ,
struct V_121 * V_121 , bool V_122 )
{
struct V_123 * V_124 = V_17 -> V_125 ;
if ( ( V_17 -> V_117 & V_118 ) && V_122 )
return;
F_37 ( V_126 , V_121 -> V_127 ) ;
F_37 ( V_128 , V_121 -> V_127 ) ;
F_38 ( V_129 , V_121 -> V_127 ) ;
F_38 ( V_130 , V_121 -> V_127 ) ;
F_39 ( V_121 , V_131 , 0 , V_124 -> V_80 , 0 , 0 ) ;
F_40 ( V_121 , V_131 , V_124 -> V_132 ) ;
F_39 ( V_121 , V_133 , 0 , V_124 -> V_81 , 0 , 0 ) ;
F_40 ( V_121 , V_133 , V_124 -> V_132 ) ;
F_39 ( V_121 , V_134 , 0 , 50 , 0 , 0 ) ;
F_41 ( V_121 , V_128 , V_135 ) ;
if ( V_17 -> V_117 & V_136 )
F_41 ( V_121 , V_128 , V_137 ) ;
else
F_37 ( V_138 , V_121 -> V_139 ) ;
F_42 ( V_121 , V_124 -> V_84 , V_140 |
V_141 ) ;
V_124 -> V_142 = V_121 ;
}
static void F_43 ( struct V_123 * V_124 ,
struct V_91 * V_143 )
{
int V_144 ;
if ( ! V_143 -> V_101 || V_143 -> V_97 )
return;
V_144 = F_44 ( V_124 -> V_142 , V_143 -> V_101 ) ;
F_45 ( V_124 -> V_142 , V_144 ) ;
F_46 ( V_124 -> V_142 , V_145 ,
V_143 -> V_98 ) ;
if ( V_143 -> V_98 ) {
F_47 ( V_124 -> V_142 , V_126 , V_131 ,
V_143 -> V_95 ) ;
F_47 ( V_124 -> V_142 , V_126 , V_133 ,
V_124 -> V_146 ? V_124 -> V_81 - V_143 -> V_96 :
V_143 -> V_96 ) ;
F_47 ( V_124 -> V_142 , V_126 , V_134 ,
V_143 -> V_100 ) ;
}
}
static void F_48 ( struct V_16 * V_17 ,
struct V_102 * V_147 )
{
struct V_123 * V_124 = V_17 -> V_125 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ )
F_43 ( V_124 , & ( V_147 -> V_108 [ V_71 ] ) ) ;
if ( V_147 -> V_104 &&
! ( V_17 -> V_117 & V_136 ) )
F_47 ( V_124 -> V_142 , V_128 , V_135 , V_147 -> V_107 ) ;
if ( V_147 -> V_104 || V_147 -> V_106 <= 2 ) {
F_49 ( V_124 -> V_142 ) ;
F_50 ( V_124 -> V_142 ) ;
}
}
static int F_51 ( struct V_16 * V_17 , V_13 * V_90 )
{
struct V_123 * V_124 = V_17 -> V_125 ;
V_13 V_148 = ( ( V_90 [ 7 ] & 0xf ) * ( V_90 [ 7 ] & 0xf ) +
( V_90 [ 7 ] >> 4 ) * ( V_90 [ 7 ] >> 4 ) ) / 2 ;
V_13 V_149 = ( ( V_90 [ 13 ] & 0xf ) * ( V_90 [ 13 ] & 0xf ) +
( V_90 [ 13 ] >> 4 ) * ( V_90 [ 13 ] >> 4 ) ) / 2 ;
struct V_102 V_147 = {
. V_150 = V_90 [ 1 ] ,
. V_108 = {
{
. V_97 = 0 ,
. V_98 = ! ! V_90 [ 7 ] ,
. V_95 = F_52 ( & V_90 [ 3 ] ) ,
. V_96 = F_52 ( & V_90 [ 5 ] ) ,
. V_99 = V_148 ,
. V_100 = V_148 ,
. V_101 = V_90 [ 2 ] ,
} , {
. V_97 = 0 ,
. V_98 = ! ! V_90 [ 13 ] ,
. V_95 = F_52 ( & V_90 [ 9 ] ) ,
. V_96 = F_52 ( & V_90 [ 11 ] ) ,
. V_99 = V_149 ,
. V_100 = V_149 ,
. V_101 = V_90 [ 8 ] ,
}
} ,
. V_106 = V_124 -> V_84 ,
. V_105 = 0 ,
. V_104 = ( V_90 [ 0 ] >> 7 ) == 0 ,
. V_107 = V_90 [ 0 ] & 0x01 ,
} ;
F_48 ( V_17 , & V_147 ) ;
return 1 ;
}
static int F_53 ( struct V_1 * V_2 , V_13 * V_90 , int V_151 )
{
struct V_16 * V_17 = F_35 ( V_2 ) ;
struct V_123 * V_124 = V_17 -> V_125 ;
struct V_3 * V_46 = (struct V_3 * ) V_90 ;
struct V_102 V_147 ;
if ( ! V_124 || ! V_124 -> V_142 )
return 1 ;
switch ( V_90 [ 0 ] ) {
case 0x02 :
if ( V_151 < 2 ) {
F_23 ( V_2 , L_8 ,
V_151 ) ;
return 1 ;
}
if ( V_17 -> V_117 & V_136 ) {
F_47 ( V_124 -> V_142 , V_128 , V_135 ,
! ! ( V_90 [ 1 ] & 0x01 ) ) ;
F_47 ( V_124 -> V_142 , V_128 , V_137 ,
! ! ( V_90 [ 1 ] & 0x02 ) ) ;
F_50 ( V_124 -> V_142 ) ;
return 0 ;
} else {
if ( V_151 < 21 )
return 1 ;
return F_51 ( V_17 , & V_90 [ 7 ] ) ;
}
case V_9 :
if ( ( V_46 -> V_28 . V_29 != V_124 -> V_152 ) ||
( V_46 -> V_28 . V_33 != V_153 ) )
return 1 ;
F_33 ( V_17 , V_90 + 4 , & V_147 ) ;
F_48 ( V_17 , & V_147 ) ;
return 0 ;
}
return 0 ;
}
static int F_54 ( struct V_16 * V_17 )
{
struct V_123 * V_124 = V_17 -> V_125 ;
struct V_77 V_78 = { 0 } ;
V_13 V_56 ;
int V_5 ;
V_5 = F_21 ( V_17 , V_154 ,
& V_124 -> V_152 , & V_56 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_29 ( V_17 , V_124 -> V_152 ,
& V_78 ) ;
if ( V_5 )
return V_5 ;
V_124 -> V_80 = V_78 . V_80 ;
V_124 -> V_81 = V_78 . V_81 ;
V_124 -> V_84 = V_78 . V_84 ;
V_124 -> V_146 = V_78 . V_85 == V_155 ;
V_124 -> V_132 = V_78 . V_86 ;
if ( ! V_124 -> V_132 )
V_124 -> V_132 = V_156 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , const struct V_157 * V_158 )
{
struct V_16 * V_17 = F_35 ( V_2 ) ;
struct V_123 * V_124 ;
V_124 = F_56 ( & V_2 -> V_159 , sizeof( struct V_123 ) ,
V_36 ) ;
if ( ! V_124 )
return - V_37 ;
V_17 -> V_125 = V_124 ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , bool V_160 )
{
struct V_16 * V_17 = F_35 ( V_2 ) ;
struct V_123 * V_124 = V_17 -> V_125 ;
int V_5 ;
if ( ! V_160 )
return;
if ( ! V_124 -> V_80 ) {
V_5 = F_54 ( V_17 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_9 , V_5 ) ;
return;
}
}
F_31 ( V_17 , V_124 -> V_152 ,
true , true ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_109 * V_110 ,
struct V_111 * V_112 , struct V_113 * V_114 ,
unsigned long * * V_115 , int * V_116 )
{
struct V_16 * V_17 = F_35 ( V_2 ) ;
if ( V_17 -> V_117 & V_161 )
return F_34 ( V_2 , V_110 , V_112 , V_114 , V_115 , V_116 ) ;
return 0 ;
}
static void F_59 ( struct V_16 * V_17 ,
struct V_121 * V_142 , bool V_122 )
{
if ( V_17 -> V_117 & V_161 )
F_36 ( V_17 , V_142 , V_122 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_109 * V_162 )
{
struct V_16 * V_17 = F_35 ( V_2 ) ;
struct V_121 * V_142 = V_162 -> V_142 ;
F_59 ( V_17 , V_142 , true ) ;
}
static int F_61 ( struct V_16 * V_17 , V_13 * V_90 ,
int V_151 )
{
struct V_3 * V_44 = V_17 -> V_21 ;
struct V_3 * V_45 = V_17 -> V_21 ;
struct V_3 * V_46 = (struct V_3 * ) V_90 ;
if ( F_62 ( F_63 ( & V_17 -> V_20 ) ) ) {
if ( F_15 ( V_44 , V_46 ) ||
F_16 ( V_44 , V_46 ) ) {
* V_45 = * V_46 ;
V_17 -> V_22 = true ;
F_64 ( & V_17 -> V_24 ) ;
return 1 ;
}
}
if ( F_62 ( F_17 ( V_46 ) ) ) {
F_65 ( & V_17 -> V_160 ,
! ( V_46 -> V_41 . V_31 [ 0 ] & ( 1 << 6 ) ) ) ;
if ( ( V_17 -> V_117 & V_163 ) &&
( F_66 ( & V_17 -> V_43 ) == 0 ) )
F_5 ( L_10 , V_26 ) ;
return 1 ;
}
if ( V_17 -> V_117 & V_161 )
return F_53 ( V_17 -> V_23 , V_90 , V_151 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_164 * V_46 ,
V_13 * V_90 , int V_151 )
{
struct V_16 * V_17 = F_35 ( V_2 ) ;
switch ( V_90 [ 0 ] ) {
case V_9 :
if ( V_151 != V_10 ) {
F_23 ( V_2 , L_11 ,
V_151 ) ;
return 1 ;
}
return F_61 ( V_17 , V_90 , V_151 ) ;
case V_7 :
if ( V_151 != V_8 ) {
F_23 ( V_2 , L_11 ,
V_151 ) ;
return 1 ;
}
return F_61 ( V_17 , V_90 , V_151 ) ;
}
if ( V_17 -> V_117 & V_161 )
return F_53 ( V_2 , V_90 , V_151 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , bool V_165 )
{
struct V_16 * V_17 = F_35 ( V_2 ) ;
char * V_47 ;
if ( V_165 )
V_47 = F_20 ( V_17 ) ;
else
V_47 = F_28 ( V_17 ) ;
if ( ! V_47 )
F_23 ( V_2 , L_12 ) ;
else
snprintf ( V_2 -> V_47 , sizeof( V_2 -> V_47 ) , L_13 , V_47 ) ;
F_10 ( V_47 ) ;
}
static int F_69 ( struct V_121 * V_159 )
{
struct V_1 * V_166 = F_70 ( V_159 ) ;
return F_71 ( V_166 ) ;
}
static void F_72 ( struct V_121 * V_159 )
{
struct V_1 * V_166 = F_70 ( V_159 ) ;
F_73 ( V_166 ) ;
}
static struct V_121 * F_74 ( struct V_1 * V_2 )
{
struct V_121 * V_121 = F_75 ( & V_2 -> V_159 ) ;
if ( ! V_121 )
return NULL ;
F_76 ( V_121 , V_2 ) ;
V_121 -> V_167 = F_69 ;
V_121 -> V_168 = F_72 ;
V_121 -> V_47 = V_2 -> V_47 ;
V_121 -> V_169 = V_2 -> V_169 ;
V_121 -> V_170 = V_2 -> V_170 ;
V_121 -> V_158 . V_171 = V_2 -> V_172 ;
V_121 -> V_158 . V_173 = V_2 -> V_173 ;
V_121 -> V_158 . V_174 = V_2 -> V_174 ;
V_121 -> V_158 . V_175 = V_2 -> V_175 ;
V_121 -> V_159 . V_176 = & V_2 -> V_159 ;
return V_121 ;
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_23 ;
int V_5 = 0 ;
bool V_160 = F_77 ( & V_17 -> V_160 ) ;
struct V_121 * V_142 ;
char * V_47 , * V_177 ;
if ( V_17 -> V_117 & V_161 )
F_57 ( V_2 , V_160 ) ;
if ( ! V_160 || V_17 -> V_178 )
return;
if ( ! V_17 -> V_61 ) {
V_5 = ! F_24 ( V_17 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_14 ) ;
return;
}
}
F_78 ( V_2 , L_7 ,
V_17 -> V_61 , V_17 -> V_62 ) ;
V_142 = F_74 ( V_2 ) ;
if ( ! V_142 ) {
F_23 ( V_2 , L_15 , V_5 ) ;
return;
}
V_47 = F_28 ( V_17 ) ;
if ( ! V_47 ) {
F_23 ( V_2 , L_12 ) ;
} else {
V_177 = F_79 ( & V_2 -> V_159 , V_36 , L_13 , V_47 ) ;
if ( V_177 )
V_142 -> V_47 = V_177 ;
F_10 ( V_47 ) ;
}
F_59 ( V_17 , V_142 , false ) ;
V_5 = F_80 ( V_142 ) ;
if ( V_5 )
F_81 ( V_142 ) ;
V_17 -> V_178 = V_142 ;
}
static int F_82 ( struct V_1 * V_2 , const struct V_157 * V_158 )
{
struct V_16 * V_17 ;
int V_5 ;
bool V_160 ;
unsigned int V_179 = V_180 ;
V_17 = F_56 ( & V_2 -> V_159 , sizeof( struct V_16 ) ,
V_36 ) ;
if ( ! V_17 )
return - V_37 ;
V_17 -> V_23 = V_2 ;
F_83 ( V_2 , V_17 ) ;
V_17 -> V_117 = V_158 -> V_181 ;
if ( V_17 -> V_117 & V_161 ) {
V_5 = F_55 ( V_2 , V_158 ) ;
if ( V_5 )
goto V_182;
}
F_84 ( & V_17 -> V_43 , F_12 ) ;
F_85 ( & V_17 -> V_20 ) ;
F_86 ( & V_17 -> V_24 ) ;
V_5 = F_87 ( V_2 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_16 , V_26 ) ;
goto V_183;
}
F_88 ( V_2 ) ;
V_160 = F_24 ( V_17 ) ;
if ( V_158 -> V_184 != V_185 ) {
if ( ! V_160 ) {
F_23 ( V_2 , L_17 ) ;
F_89 ( V_2 ) ;
goto V_183;
}
F_78 ( V_2 , L_7 ,
V_17 -> V_61 , V_17 -> V_62 ) ;
}
F_68 ( V_2 , V_158 -> V_184 == V_185 ) ;
F_65 ( & V_17 -> V_160 , V_160 ) ;
if ( V_160 && ( V_17 -> V_117 & V_161 ) ) {
V_5 = F_54 ( V_17 ) ;
if ( V_5 )
goto V_183;
}
F_89 ( V_2 ) ;
if ( V_17 -> V_117 & V_163 )
V_179 &= ~ V_186 ;
if ( V_17 -> V_117 & V_118 )
V_179 |= V_186 ;
V_5 = F_90 ( V_2 , V_179 ) ;
if ( V_5 ) {
F_23 ( V_2 , L_18 , V_26 ) ;
goto V_187;
}
if ( V_17 -> V_117 & V_163 ) {
F_88 ( V_2 ) ;
F_14 ( V_17 ) ;
}
return V_5 ;
V_187:
V_183:
F_91 ( & V_17 -> V_43 ) ;
F_92 ( & V_17 -> V_20 ) ;
V_182:
F_83 ( V_2 , NULL ) ;
return V_5 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_35 ( V_2 ) ;
F_91 ( & V_17 -> V_43 ) ;
F_92 ( & V_17 -> V_20 ) ;
F_94 ( V_2 ) ;
}
