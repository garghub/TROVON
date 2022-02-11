static enum V_1 F_1 ( T_1 V_2 )
{
switch ( V_2 ) {
default:
F_2 () ;
case V_3 :
case V_4 :
case V_5 :
return V_6 ;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return V_12 ;
}
}
static T_1 F_3 ( struct V_13 * V_14 , unsigned int V_15 )
{
return F_4 ( V_14 -> V_16 + V_15 ) ;
}
static void F_5 ( struct V_13 * V_14 , unsigned int V_15 ,
T_1 V_17 )
{
F_6 ( V_17 , V_14 -> V_16 + V_15 ) ;
}
static void F_7 ( void * V_18 )
{
struct V_13 * V_14 = V_18 ;
V_14 -> V_19 = true ;
}
static void F_8 ( struct V_13 * V_14 ,
struct V_20 * V_21 ,
struct V_20 * V_22 )
{
T_2 V_23 = F_9 ( V_22 , 0 ) ;
F_5 ( V_14 , V_24 , V_23 + V_14 -> V_25 . V_26 ) ;
F_5 ( V_14 , V_27 , V_14 -> V_25 . V_28 ?
V_23 + V_14 -> V_25 . V_28 : 0 ) ;
F_10 ( V_14 -> V_29 , L_1 , V_30 ,
( unsigned long ) V_23 ,
V_14 -> V_25 . V_26 , V_14 -> V_25 . V_28 ) ;
V_23 = F_9 ( V_21 , 0 ) ;
F_5 ( V_14 , V_31 , V_23 + V_14 -> V_32 . V_26 ) ;
F_5 ( V_14 , V_33 , V_14 -> V_32 . V_28 ?
V_23 + V_14 -> V_32 . V_28 : 0 ) ;
F_10 ( V_14 -> V_29 , L_2 , V_30 ,
( unsigned long ) V_23 ,
V_14 -> V_32 . V_26 , V_14 -> V_32 . V_28 ) ;
F_5 ( V_14 , V_34 , 1 ) ;
F_5 ( V_14 , V_35 , 1 ) ;
}
static void F_11 ( void * V_18 )
{
struct V_13 * V_14 = V_18 ;
struct V_20 * V_21 , * V_22 ;
V_21 = F_12 ( V_14 -> V_36 ) ;
V_22 = F_13 ( V_14 -> V_36 ) ;
if ( V_21 && V_22 )
F_8 ( V_14 , V_21 , V_22 ) ;
}
static bool F_14 ( struct V_13 * V_14 , struct V_37 * V_38 ,
enum V_39 type )
{
return ( type == V_40 &&
V_38 == V_14 -> V_41 ) ||
( type == V_42 &&
V_38 == V_14 -> V_43 ) ;
}
static int F_15 ( struct V_13 * V_14 , struct V_37 * V_38 ,
enum V_39 type )
{
struct V_37 * * V_44 ;
switch ( type ) {
case V_40 :
V_44 = & V_14 -> V_41 ;
break;
case V_42 :
V_44 = & V_14 -> V_43 ;
break;
default:
return - V_45 ;
}
if ( * V_44 == V_38 )
return 0 ;
if ( * V_44 )
return - V_46 ;
* V_44 = V_38 ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 )
{
if ( V_14 -> V_36 )
return 0 ;
V_14 -> V_36 = F_17 ( V_14 -> V_47 , V_14 ,
V_48 ) ;
return F_18 ( V_14 -> V_36 ) ;
}
static int F_19 ( struct V_49 * V_49 , void * V_18 ,
struct V_50 * V_51 )
{
F_20 ( V_51 -> V_52 , L_3 , sizeof( V_51 -> V_52 ) ) ;
F_20 ( V_51 -> V_53 , L_4 , sizeof( V_51 -> V_53 ) ) ;
F_20 ( V_51 -> V_54 , L_5 , sizeof( V_51 -> V_54 ) ) ;
V_51 -> V_55 = V_56 | V_57 ;
V_51 -> V_58 = V_51 -> V_55 | V_59 ;
return 0 ;
}
static int F_21 ( struct V_60 * V_61 , const int * V_62 , int V_63 )
{
if ( V_61 -> V_64 >= V_63 )
return - V_45 ;
F_20 ( V_61 -> V_65 , V_66 [ V_62 [ V_61 -> V_64 ] ] . V_67 , sizeof( V_61 -> V_65 ) ) ;
V_61 -> V_68 = V_66 [ V_62 [ V_61 -> V_64 ] ] . V_2 ;
return 0 ;
}
static int F_22 ( struct V_49 * V_49 , void * V_18 ,
struct V_60 * V_61 )
{
return F_21 ( V_61 , V_69 , F_23 ( V_69 ) ) ;
}
static int F_24 ( struct V_49 * V_49 , void * V_18 ,
struct V_60 * V_61 )
{
return F_21 ( V_61 , V_70 , F_23 ( V_70 ) ) ;
}
static struct V_71 * F_25 ( struct V_13 * V_14 ,
enum V_39 type )
{
switch ( type ) {
case V_40 :
return & V_14 -> V_25 ;
case V_42 :
return & V_14 -> V_32 ;
default:
return NULL ;
}
}
static int F_26 ( struct V_37 * V_38 , struct V_72 * V_61 )
{
struct V_73 * V_74 = & V_61 -> V_62 . V_74 ;
struct V_13 * V_14 = V_38 -> V_75 ;
struct V_71 * V_76 ;
V_76 = F_25 ( V_14 , V_61 -> type ) ;
V_74 -> V_77 = V_76 -> V_78 . V_77 ;
V_74 -> V_79 = V_76 -> V_78 . V_79 ;
V_74 -> V_80 = V_81 ;
V_74 -> V_68 = V_76 -> V_62 -> V_2 ;
V_74 -> V_82 = F_1 ( V_74 -> V_68 ) ;
V_74 -> V_83 = V_76 -> V_83 ;
V_74 -> V_84 = V_76 -> V_83 * V_74 -> V_79 *
V_76 -> V_62 -> V_85 / V_76 -> V_62 -> V_86 ;
F_10 ( V_14 -> V_29 , L_6 , V_30 ,
V_61 -> type , V_74 -> V_84 , V_74 -> V_77 , V_74 -> V_79 , V_74 -> V_68 ) ;
return 0 ;
}
static int F_27 ( struct V_49 * V_49 , void * V_18 ,
struct V_72 * V_61 )
{
return F_26 ( V_18 , V_61 ) ;
}
static int F_28 ( struct V_49 * V_49 , void * V_18 ,
struct V_72 * V_61 )
{
return F_26 ( V_18 , V_61 ) ;
}
static int F_29 ( struct V_72 * V_61 , const struct V_87 * V_62 )
{
struct V_73 * V_74 = & V_61 -> V_62 . V_74 ;
unsigned int V_88 ;
switch ( V_74 -> V_80 ) {
default:
case V_89 :
V_74 -> V_80 = V_81 ;
case V_81 :
break;
}
F_30 ( & V_74 -> V_77 , V_90 , V_91 , V_92 ,
& V_74 -> V_79 , V_93 , V_94 , 0 , 0 ) ;
V_88 = ( V_74 -> V_77 * V_62 -> V_86 ) >> 3 ;
if ( V_74 -> V_83 < V_88 )
V_74 -> V_83 = V_88 ;
V_74 -> V_84 = V_74 -> V_79 * V_74 -> V_83 * V_62 -> V_85 / V_62 -> V_86 ;
V_74 -> V_68 = V_62 -> V_2 ;
V_74 -> V_82 = F_1 ( V_74 -> V_68 ) ;
F_31 ( L_7 , V_30 , V_61 -> type , V_74 -> V_84 ) ;
return 0 ;
}
static const struct V_87 * F_32 ( const struct V_72 * V_61 )
{
const int * V_62 ;
int V_95 , V_96 , V_97 ;
F_31 ( L_8 , V_30 , V_61 -> type , V_61 -> V_62 . V_74 . V_80 ) ;
switch ( V_61 -> type ) {
case V_40 :
V_62 = V_69 ;
V_96 = F_23 ( V_69 ) ;
V_97 = V_98 ;
break;
case V_42 :
default:
V_62 = V_70 ;
V_96 = F_23 ( V_70 ) ;
V_97 = V_99 ;
break;
}
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ )
if ( V_66 [ V_62 [ V_95 ] ] . V_2 == V_61 -> V_62 . V_74 . V_68 )
return & V_66 [ V_62 [ V_95 ] ] ;
return & V_66 [ V_97 ] ;
}
static int F_33 ( struct V_49 * V_49 , void * V_18 ,
struct V_72 * V_61 )
{
const struct V_87 * V_62 ;
V_62 = F_32 ( V_61 ) ;
if ( ! V_62 )
return - V_45 ;
return F_29 ( V_61 , V_62 ) ;
}
static int F_34 ( struct V_49 * V_49 , void * V_18 ,
struct V_72 * V_61 )
{
const struct V_87 * V_62 ;
V_62 = F_32 ( V_61 ) ;
if ( ! V_62 )
return - V_45 ;
return F_29 ( V_61 , V_62 ) ;
}
static void F_35 ( struct V_13 * V_14 , struct V_71 * V_76 )
{
unsigned int V_100 = V_76 -> V_78 . V_100 & ~ 0x03 ;
unsigned int V_101 = V_76 -> V_78 . V_101 ;
T_2 V_102 = ( ( V_100 * V_14 -> V_25 . V_62 -> V_85 ) >> 3 ) +
V_101 * V_14 -> V_25 . V_83 ;
unsigned int V_103 ;
V_76 -> V_26 = V_102 ;
switch ( V_76 -> V_62 -> V_2 ) {
case V_3 :
case V_4 :
case V_5 :
V_103 = F_36 ( V_76 -> V_78 . V_77 , 16 ) ;
V_76 -> V_28 = V_102 + V_103 * V_76 -> V_78 . V_79 ;
break;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
V_76 -> V_28 = 0 ;
break;
default:
F_2 () ;
}
}
static int F_37 ( struct V_37 * V_38 , struct V_72 * V_61 )
{
struct V_73 * V_74 = & V_61 -> V_62 . V_74 ;
struct V_13 * V_14 = V_38 -> V_75 ;
struct V_71 * V_76 ;
struct V_104 * V_105 ;
int V_106 = F_16 ( V_14 ) ;
if ( V_106 < 0 )
return V_106 ;
V_105 = F_38 ( V_14 -> V_36 , V_61 -> type ) ;
if ( ! V_105 )
return - V_45 ;
if ( F_39 ( V_105 ) ) {
F_40 ( & V_38 -> V_75 -> V_107 , L_9 , V_30 ) ;
return - V_46 ;
}
V_76 = F_25 ( V_14 , V_61 -> type ) ;
V_76 -> V_62 = F_32 ( V_61 ) ;
V_76 -> V_78 . V_77 = V_74 -> V_77 ;
V_76 -> V_78 . V_79 = V_74 -> V_79 ;
V_76 -> V_83 = V_74 -> V_83 ;
F_35 ( V_14 , V_76 ) ;
V_38 -> V_108 = true ;
F_10 ( V_14 -> V_29 ,
L_10 ,
V_61 -> type , V_74 -> V_77 , V_74 -> V_79 , V_76 -> V_62 -> V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_49 * V_49 , void * V_18 ,
struct V_72 * V_61 )
{
int V_106 = F_33 ( V_49 , V_18 , V_61 ) ;
if ( V_106 )
return V_106 ;
return F_37 ( V_18 , V_61 ) ;
}
static int F_42 ( struct V_49 * V_49 , void * V_18 ,
struct V_72 * V_61 )
{
int V_106 = F_34 ( V_49 , V_18 , V_61 ) ;
if ( V_106 )
return V_106 ;
return F_37 ( V_18 , V_61 ) ;
}
static int F_43 ( struct V_49 * V_49 , void * V_18 ,
struct V_109 * V_110 )
{
struct V_37 * V_38 = V_18 ;
struct V_13 * V_14 = V_38 -> V_75 ;
int V_106 = F_16 ( V_14 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_15 ( V_14 , V_38 , V_110 -> type ) ;
if ( V_106 < 0 )
return V_106 ;
return F_44 ( V_49 , V_14 -> V_36 , V_110 ) ;
}
static int F_45 ( struct V_49 * V_49 , void * V_18 ,
struct V_111 * V_112 )
{
struct V_37 * V_38 = V_18 ;
if ( ! F_14 ( V_38 -> V_75 , V_38 , V_112 -> type ) )
return - V_46 ;
return F_46 ( V_49 , V_38 -> V_75 -> V_36 , V_112 ) ;
}
static int F_47 ( struct V_49 * V_49 , void * V_18 , struct V_111 * V_112 )
{
struct V_37 * V_38 = V_18 ;
F_10 ( V_38 -> V_75 -> V_29 , L_11 , V_30 , V_112 -> type ) ;
if ( ! F_14 ( V_38 -> V_75 , V_38 , V_112 -> type ) )
return - V_46 ;
return F_48 ( V_49 , V_38 -> V_75 -> V_36 , V_112 ) ;
}
static int F_49 ( struct V_49 * V_49 , void * V_18 , struct V_111 * V_112 )
{
struct V_37 * V_38 = V_18 ;
F_10 ( V_38 -> V_75 -> V_29 , L_11 , V_30 , V_112 -> type ) ;
if ( ! F_14 ( V_38 -> V_75 , V_38 , V_112 -> type ) )
return - V_46 ;
return F_50 ( V_49 , V_38 -> V_75 -> V_36 , V_112 ) ;
}
static void F_51 ( struct V_13 * V_14 ,
int V_113 , int V_114 , int V_115 ,
T_1 * V_116 , T_1 * V_117 , T_1 * V_118 )
{
T_1 V_119 ;
* V_118 = * V_116 = * V_117 = 0 ;
if ( V_113 == V_114 ) {
if ( V_115 != V_114 )
* V_116 = 1 ;
return;
}
if ( V_14 -> V_120 && V_114 > V_113 ) {
T_1 V_119 = ( 4096 * V_113 ) / V_114 ;
* V_116 = V_119 / 4096 ;
* V_117 = ( V_119 - ( * V_116 * 4096 ) ) & ~ 0x07 ;
switch ( * V_117 ) {
case 0x800 :
* V_118 = 1 ;
break;
case 0x400 :
* V_118 = 3 ;
break;
case 0x200 :
* V_118 = 7 ;
break;
}
if ( * V_118 )
return;
}
V_119 = ( 4096 * ( V_113 - 1 ) ) / ( V_114 + 1 ) ;
* V_116 = V_119 / 4096 ;
* V_117 = V_119 - ( * V_116 * 4096 ) ;
if ( * V_117 & 0x07 ) {
* V_117 &= ~ 0x07 ;
if ( V_114 > V_113 )
* V_117 -= 8 ;
else
* V_117 += 8 ;
}
}
static unsigned long F_52 ( struct V_13 * V_14 ,
int V_113 , int V_114 , int V_115 )
{
T_1 V_116 , V_117 , V_17 , V_118 ;
F_51 ( V_14 , V_113 , V_114 , V_115 , & V_116 , & V_117 , & V_118 ) ;
V_17 = ( F_3 ( V_14 , V_121 ) & ~ 0xffff0000 ) |
( ( ( V_116 << 12 ) | V_117 ) << 16 ) ;
F_5 ( V_14 , V_121 , V_17 ) ;
V_17 = ( F_3 ( V_14 , V_122 ) & ~ 0xffff0000 ) |
( ( ( V_118 << 12 ) | V_115 ) << 16 ) ;
F_5 ( V_14 , V_122 , V_17 ) ;
return F_36 ( ( V_113 * V_115 ) / V_114 , 4 ) ;
}
static unsigned long F_53 ( struct V_13 * V_14 ,
int V_113 , int V_114 , int V_115 )
{
T_1 V_116 , V_117 , V_17 , V_118 ;
F_51 ( V_14 , V_113 , V_114 , V_115 , & V_116 , & V_117 , & V_118 ) ;
V_17 = ( F_3 ( V_14 , V_121 ) & ~ 0xffff ) |
( V_116 << 12 ) | V_117 ;
F_5 ( V_14 , V_121 , V_17 ) ;
V_17 = ( F_3 ( V_14 , V_122 ) & ~ 0xffff ) |
( V_118 << 12 ) | V_115 ;
F_5 ( V_14 , V_122 , V_17 ) ;
return F_36 ( ( V_113 * V_115 ) / V_114 , 4 ) ;
}
static void F_54 ( struct V_13 * V_14 )
{
T_1 V_123 , V_124 , V_125 ;
T_1 V_126 , V_127 , V_128 ;
T_1 V_129 , V_130 ;
F_5 ( V_14 , V_131 , 0x100 ) ;
V_123 = V_14 -> V_32 . V_78 . V_77 ;
V_125 = V_14 -> V_32 . V_78 . V_79 ;
V_124 = F_36 ( V_14 -> V_32 . V_78 . V_77 , 16 ) ;
V_126 = V_129 = V_14 -> V_25 . V_78 . V_77 ;
V_128 = V_130 = V_14 -> V_25 . V_78 . V_79 ;
V_127 = V_14 -> V_25 . V_83 ;
V_123 = F_53 ( V_14 , V_123 , V_129 , V_126 ) ;
V_125 = F_52 ( V_14 , V_125 , V_130 , V_128 ) ;
F_5 ( V_14 , V_132 , V_124 ) ;
F_5 ( V_14 , V_133 , V_123 | ( V_125 << 16 ) ) ;
F_5 ( V_14 , V_134 , 0 ) ;
F_5 ( V_14 , V_135 , V_127 ) ;
F_5 ( V_14 , V_27 , 0 ) ;
F_5 ( V_14 , V_136 , 0x67 ) ;
F_5 ( V_14 , V_137 , ( 6 << 16 ) | ( 0 << 14 ) | 2 | 4 ) ;
if ( V_14 -> V_120 ) {
F_5 ( V_14 , V_138 , 0x0cc5 ) ;
F_5 ( V_14 , V_139 , 0x0950 ) ;
F_5 ( V_14 , V_140 , 0x0000 ) ;
F_5 ( V_14 , V_141 , 0x397f ) ;
F_5 ( V_14 , V_142 , 0x0950 ) ;
F_5 ( V_14 , V_143 , 0x3ccd ) ;
F_5 ( V_14 , V_144 , 0x0000 ) ;
F_5 ( V_14 , V_145 , 0x0950 ) ;
F_5 ( V_14 , V_146 , 0x1023 ) ;
F_5 ( V_14 , V_147 , 0x00800010 ) ;
}
}
static int F_55 ( struct V_49 * V_49 , void * V_18 ,
enum V_39 type )
{
struct V_37 * V_38 = V_18 ;
if ( ! F_14 ( V_38 -> V_75 , V_38 , type ) )
return - V_46 ;
if ( V_38 -> V_108 ) {
struct V_13 * V_14 = V_38 -> V_75 ;
V_38 -> V_108 = false ;
F_54 ( V_38 -> V_75 ) ;
V_14 -> V_148 = 0 ;
V_14 -> V_19 = false ;
}
return F_56 ( V_49 , V_38 -> V_75 -> V_36 , type ) ;
}
static int F_57 ( struct V_49 * V_49 , void * V_18 ,
enum V_39 type )
{
struct V_37 * V_38 = V_18 ;
if ( ! F_14 ( V_38 -> V_75 , V_38 , type ) )
return - V_46 ;
return F_58 ( V_49 , V_38 -> V_75 -> V_36 , type ) ;
}
static int F_59 ( struct V_104 * V_105 ,
unsigned int * V_149 , unsigned int * V_150 ,
unsigned int V_151 [] , void * V_152 [] )
{
struct V_13 * V_14 = F_60 ( V_105 ) ;
struct V_71 * V_76 = F_25 ( V_14 , V_105 -> type ) ;
unsigned int V_153 = * V_149 ;
unsigned int V_154 = V_76 -> V_83 * V_76 -> V_78 . V_79 *
V_76 -> V_62 -> V_85 / V_76 -> V_62 -> V_86 ;
if ( V_153 < 2 )
* V_149 = V_153 = 2 ;
if ( V_154 * V_153 > V_155 ) {
V_153 = V_155 / V_154 ;
* V_149 = V_153 ;
}
if ( * V_150 ) {
V_152 [ 0 ] = V_14 -> V_156 ;
return V_151 [ 0 ] < V_154 ? - V_45 : 0 ;
}
* V_150 = 1 ;
V_151 [ 0 ] = V_154 ;
V_152 [ 0 ] = V_14 -> V_156 ;
F_10 ( V_14 -> V_29 , L_12 , V_153 , V_154 ) ;
return 0 ;
}
static int F_61 ( struct V_20 * V_157 )
{
struct V_13 * V_14 = F_60 ( V_157 -> V_104 ) ;
struct V_71 * V_76 ;
unsigned int V_84 ;
V_76 = F_25 ( V_14 , V_157 -> V_104 -> type ) ;
V_84 = V_76 -> V_83 * V_76 -> V_78 . V_79 *
V_76 -> V_62 -> V_85 / V_76 -> V_62 -> V_86 ;
if ( F_62 ( V_157 , 0 ) < V_84 ) {
F_10 ( V_14 -> V_29 , L_13 ,
V_30 , F_62 ( V_157 , 0 ) , V_84 ) ;
return - V_45 ;
}
F_63 ( V_157 , 0 , V_84 ) ;
return 0 ;
}
static void F_64 ( struct V_20 * V_157 )
{
struct V_158 * V_159 = F_65 ( V_157 ) ;
struct V_13 * V_14 = F_60 ( V_157 -> V_104 ) ;
F_10 ( V_14 -> V_29 , L_11 , V_30 , V_157 -> type ) ;
F_66 ( V_14 -> V_36 , V_159 ) ;
}
static int V_48 ( void * V_18 , struct V_104 * V_160 ,
struct V_104 * V_161 )
{
struct V_13 * V_14 = V_18 ;
int V_106 ;
memset ( V_160 , 0 , sizeof( * V_160 ) ) ;
V_160 -> type = V_42 ;
V_160 -> V_162 = V_163 | V_164 ;
V_160 -> V_165 = V_14 ;
V_160 -> V_166 = sizeof( struct V_167 ) ;
V_160 -> V_168 = & V_169 ;
V_160 -> V_170 = & V_171 ;
V_160 -> V_172 = & V_14 -> V_173 ;
V_160 -> V_174 = V_175 ;
V_106 = F_67 ( V_160 ) ;
if ( V_106 < 0 )
return V_106 ;
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
V_161 -> type = V_40 ;
V_161 -> V_162 = V_163 | V_164 ;
V_161 -> V_165 = V_14 ;
V_161 -> V_166 = sizeof( struct V_167 ) ;
V_161 -> V_168 = & V_169 ;
V_161 -> V_170 = & V_171 ;
V_161 -> V_172 = & V_14 -> V_173 ;
V_161 -> V_174 = V_175 ;
return F_67 ( V_161 ) ;
}
static int F_68 ( struct V_49 * V_49 )
{
struct V_13 * V_14 = F_69 ( V_49 ) ;
struct V_37 * V_38 ;
V_38 = F_70 ( sizeof( * V_38 ) , V_176 ) ;
if ( ! V_38 )
return - V_177 ;
V_38 -> V_75 = V_14 ;
V_38 -> V_108 = true ;
V_49 -> V_178 = V_38 ;
F_71 ( V_14 -> V_29 ) ;
F_10 ( V_14 -> V_29 , L_14 , V_38 ) ;
return 0 ;
}
static int F_72 ( struct V_49 * V_49 )
{
struct V_13 * V_14 = F_69 ( V_49 ) ;
struct V_37 * V_38 = V_49 -> V_178 ;
F_10 ( V_14 -> V_29 , L_15 , V_38 ) ;
if ( V_38 == V_14 -> V_41 ) {
V_14 -> V_41 = NULL ;
F_73 ( F_38 ( V_14 -> V_36 , V_40 ) ) ;
}
if ( V_38 == V_14 -> V_43 ) {
V_14 -> V_43 = NULL ;
F_73 ( F_38 ( V_14 -> V_36 , V_42 ) ) ;
}
if ( ! V_14 -> V_43 && ! V_14 -> V_41 && V_14 -> V_36 ) {
F_74 ( V_14 -> V_36 ) ;
V_14 -> V_36 = NULL ;
}
F_75 ( V_14 -> V_29 ) ;
F_76 ( V_38 ) ;
return 0 ;
}
static unsigned int F_77 ( struct V_49 * V_49 ,
struct V_179 * V_180 )
{
struct V_37 * V_38 = V_49 -> V_178 ;
return F_78 ( V_49 , V_38 -> V_75 -> V_36 , V_180 ) ;
}
static int F_79 ( struct V_49 * V_49 , struct V_181 * V_182 )
{
struct V_37 * V_38 = V_49 -> V_178 ;
return F_80 ( V_49 , V_38 -> V_75 -> V_36 , V_182 ) ;
}
static T_3 F_81 ( int V_183 , void * V_184 )
{
struct V_13 * V_14 = V_184 ;
if ( V_14 -> V_148 == V_185 || V_14 -> V_19 ) {
F_82 ( V_14 -> V_47 , V_14 -> V_36 ) ;
V_14 -> V_148 = 0 ;
} else {
F_11 ( V_14 ) ;
}
return V_186 ;
}
static T_3 F_83 ( int V_183 , void * V_184 )
{
struct V_13 * V_14 = V_184 ;
struct V_158 * V_187 ;
struct V_158 * V_188 ;
T_1 V_189 = F_3 ( V_14 , V_190 ) ;
if ( ! ( V_189 & 1 ) )
return V_191 ;
F_5 ( V_14 , V_35 , 0 ) ;
F_5 ( V_14 , V_34 , 0 ) ;
F_5 ( V_14 , V_190 , V_189 & ~ 1 ) ;
V_187 = F_84 ( V_14 -> V_36 ) ;
V_188 = F_85 ( V_14 -> V_36 ) ;
if ( ! V_188 || ! V_187 )
return V_191 ;
V_187 -> V_192 . V_193 = V_188 -> V_192 . V_193 ;
V_187 -> V_194 &= ~ V_195 ;
V_187 -> V_194 |=
V_188 -> V_194 & V_195 ;
V_187 -> V_196 = V_188 -> V_196 ;
F_86 ( & V_14 -> V_172 ) ;
F_87 ( V_188 , V_197 ) ;
F_87 ( V_187 , V_197 ) ;
F_88 ( & V_14 -> V_172 ) ;
V_14 -> V_148 ++ ;
return V_198 ;
}
static int F_89 ( struct V_199 * V_200 )
{
struct V_13 * V_14 ;
struct V_201 * V_202 ;
struct V_203 * V_204 ;
int V_183 , V_106 ;
V_202 = F_90 ( V_200 , V_205 , 0 ) ;
V_183 = F_91 ( V_200 , 0 ) ;
if ( ! V_202 || V_183 <= 0 ) {
F_92 ( & V_200 -> V_29 , L_16 ) ;
return - V_206 ;
}
V_14 = F_93 ( & V_200 -> V_29 , sizeof( * V_14 ) , V_176 ) ;
if ( ! V_14 )
return - V_177 ;
V_14 -> V_120 = F_94 ( V_202 ) == 0x22c ;
V_14 -> V_16 = F_95 ( & V_200 -> V_29 , V_202 ) ;
if ( F_96 ( V_14 -> V_16 ) )
return F_97 ( V_14 -> V_16 ) ;
V_106 = F_98 ( & V_200 -> V_29 , V_183 , F_83 , F_81 ,
0 , L_17 , V_14 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_99 ( & V_200 -> V_29 , & V_14 -> V_107 ) ;
if ( V_106 < 0 ) {
F_92 ( & V_200 -> V_29 , L_18 ) ;
return V_106 ;
}
V_204 = & V_14 -> V_204 ;
V_14 -> V_156 = F_100 ( & V_200 -> V_29 ) ;
if ( F_96 ( V_14 -> V_156 ) ) {
V_106 = F_97 ( V_14 -> V_156 ) ;
goto V_207;
}
* V_204 = V_208 ;
V_204 -> V_107 = & V_14 -> V_107 ;
F_101 ( & V_14 -> V_172 ) ;
F_102 ( & V_14 -> V_173 ) ;
V_204 -> V_172 = & V_14 -> V_173 ;
F_103 ( V_204 , V_14 ) ;
V_14 -> V_29 = & V_200 -> V_29 ;
V_14 -> V_25 = V_209 ;
V_14 -> V_32 = V_210 ;
V_14 -> V_47 = F_104 ( & V_211 ) ;
if ( F_96 ( V_14 -> V_47 ) ) {
V_106 = F_97 ( V_14 -> V_47 ) ;
F_40 ( & V_14 -> V_107 , L_19 , V_106 ) ;
goto V_212;
}
F_105 ( & V_200 -> V_29 ) ;
F_106 ( & V_200 -> V_29 ) ;
V_106 = F_107 ( V_204 , V_213 , - 1 ) ;
F_108 ( & V_200 -> V_29 ) ;
if ( V_106 < 0 )
goto V_214;
return V_106 ;
V_214:
F_109 ( & V_200 -> V_29 ) ;
F_110 ( V_14 -> V_47 ) ;
V_212:
F_111 ( V_14 -> V_156 ) ;
V_207:
F_112 ( & V_14 -> V_107 ) ;
return V_106 ;
}
static int F_113 ( struct V_199 * V_200 )
{
struct V_215 * V_107 = F_114 ( V_200 ) ;
struct V_13 * V_14 = F_115 ( V_107 ,
struct V_13 , V_107 ) ;
F_116 ( & V_14 -> V_204 ) ;
F_109 ( & V_200 -> V_29 ) ;
F_110 ( V_14 -> V_47 ) ;
F_111 ( V_14 -> V_156 ) ;
F_112 ( & V_14 -> V_107 ) ;
return 0 ;
}
