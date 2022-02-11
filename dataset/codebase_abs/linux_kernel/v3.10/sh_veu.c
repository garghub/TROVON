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
static void F_8 ( void * V_18 )
{
struct V_13 * V_14 = V_18 ;
F_9 ( & V_14 -> V_20 ) ;
}
static void F_10 ( void * V_18 )
{
struct V_13 * V_14 = V_18 ;
F_11 ( & V_14 -> V_20 ) ;
}
static void F_12 ( struct V_13 * V_14 ,
struct V_21 * V_22 ,
struct V_21 * V_23 )
{
T_2 V_24 = F_13 ( V_23 , 0 ) ;
F_5 ( V_14 , V_25 , V_24 + V_14 -> V_26 . V_27 ) ;
F_5 ( V_14 , V_28 , V_14 -> V_26 . V_29 ?
V_24 + V_14 -> V_26 . V_29 : 0 ) ;
F_14 ( V_14 -> V_30 , L_1 , V_31 ,
( unsigned long ) V_24 ,
V_14 -> V_26 . V_27 , V_14 -> V_26 . V_29 ) ;
V_24 = F_13 ( V_22 , 0 ) ;
F_5 ( V_14 , V_32 , V_24 + V_14 -> V_33 . V_27 ) ;
F_5 ( V_14 , V_34 , V_14 -> V_33 . V_29 ?
V_24 + V_14 -> V_33 . V_29 : 0 ) ;
F_14 ( V_14 -> V_30 , L_2 , V_31 ,
( unsigned long ) V_24 ,
V_14 -> V_33 . V_27 , V_14 -> V_33 . V_29 ) ;
F_5 ( V_14 , V_35 , 1 ) ;
F_5 ( V_14 , V_36 , 1 ) ;
}
static void F_15 ( void * V_18 )
{
struct V_13 * V_14 = V_18 ;
struct V_21 * V_22 , * V_23 ;
V_22 = F_16 ( V_14 -> V_37 ) ;
V_23 = F_17 ( V_14 -> V_37 ) ;
if ( V_22 && V_23 )
F_12 ( V_14 , V_22 , V_23 ) ;
}
static bool F_18 ( struct V_13 * V_14 , struct V_38 * V_39 ,
enum V_40 type )
{
return ( type == V_41 &&
V_39 == V_14 -> V_42 ) ||
( type == V_43 &&
V_39 == V_14 -> V_44 ) ;
}
static int F_19 ( struct V_13 * V_14 , struct V_38 * V_39 ,
enum V_40 type )
{
struct V_38 * * V_45 ;
switch ( type ) {
case V_41 :
V_45 = & V_14 -> V_42 ;
break;
case V_43 :
V_45 = & V_14 -> V_44 ;
break;
default:
return - V_46 ;
}
if ( * V_45 == V_39 )
return 0 ;
if ( * V_45 )
return - V_47 ;
* V_45 = V_39 ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 )
{
if ( V_14 -> V_37 )
return 0 ;
V_14 -> V_37 = F_21 ( V_14 -> V_48 , V_14 ,
V_49 ) ;
if ( F_22 ( V_14 -> V_37 ) )
return F_23 ( V_14 -> V_37 ) ;
return 0 ;
}
static int F_24 ( struct V_50 * V_50 , void * V_18 ,
struct V_51 * V_52 )
{
F_25 ( V_52 -> V_53 , L_3 , sizeof( V_52 -> V_53 ) ) ;
F_25 ( V_52 -> V_54 , L_4 , sizeof( V_52 -> V_54 ) ) ;
F_25 ( V_52 -> V_55 , L_5 , sizeof( V_52 -> V_55 ) ) ;
V_52 -> V_56 = V_57 | V_58 ;
V_52 -> V_59 = V_52 -> V_56 | V_60 ;
return 0 ;
}
static int F_26 ( struct V_61 * V_62 , const int * V_63 , int V_64 )
{
if ( V_62 -> V_65 >= V_64 )
return - V_46 ;
F_25 ( V_62 -> V_66 , V_67 [ V_63 [ V_62 -> V_65 ] ] . V_68 , sizeof( V_62 -> V_66 ) ) ;
V_62 -> V_69 = V_67 [ V_63 [ V_62 -> V_65 ] ] . V_2 ;
return 0 ;
}
static int F_27 ( struct V_50 * V_50 , void * V_18 ,
struct V_61 * V_62 )
{
return F_26 ( V_62 , V_70 , F_28 ( V_70 ) ) ;
}
static int F_29 ( struct V_50 * V_50 , void * V_18 ,
struct V_61 * V_62 )
{
return F_26 ( V_62 , V_71 , F_28 ( V_71 ) ) ;
}
static struct V_72 * F_30 ( struct V_13 * V_14 ,
enum V_40 type )
{
switch ( type ) {
case V_41 :
return & V_14 -> V_26 ;
case V_43 :
return & V_14 -> V_33 ;
default:
return NULL ;
}
}
static int F_31 ( struct V_38 * V_39 , struct V_73 * V_62 )
{
struct V_74 * V_75 = & V_62 -> V_63 . V_75 ;
struct V_13 * V_14 = V_39 -> V_76 ;
struct V_72 * V_77 ;
V_77 = F_30 ( V_14 , V_62 -> type ) ;
V_75 -> V_78 = V_77 -> V_79 . V_78 ;
V_75 -> V_80 = V_77 -> V_79 . V_80 ;
V_75 -> V_81 = V_82 ;
V_75 -> V_69 = V_77 -> V_63 -> V_2 ;
V_75 -> V_83 = F_1 ( V_75 -> V_69 ) ;
V_75 -> V_84 = V_77 -> V_84 ;
V_75 -> V_85 = V_77 -> V_84 * V_75 -> V_80 *
V_77 -> V_63 -> V_86 / V_77 -> V_63 -> V_87 ;
V_75 -> V_18 = 0 ;
F_14 ( V_14 -> V_30 , L_6 , V_31 ,
V_62 -> type , V_75 -> V_85 , V_75 -> V_78 , V_75 -> V_80 , V_75 -> V_69 ) ;
return 0 ;
}
static int F_32 ( struct V_50 * V_50 , void * V_18 ,
struct V_73 * V_62 )
{
return F_31 ( V_18 , V_62 ) ;
}
static int F_33 ( struct V_50 * V_50 , void * V_18 ,
struct V_73 * V_62 )
{
return F_31 ( V_18 , V_62 ) ;
}
static int F_34 ( struct V_73 * V_62 , const struct V_88 * V_63 )
{
struct V_74 * V_75 = & V_62 -> V_63 . V_75 ;
unsigned int V_89 ;
switch ( V_75 -> V_81 ) {
default:
case V_90 :
V_75 -> V_81 = V_82 ;
case V_82 :
break;
}
F_35 ( & V_75 -> V_78 , V_91 , V_92 , V_93 ,
& V_75 -> V_80 , V_94 , V_95 , 0 , 0 ) ;
V_89 = ( V_75 -> V_78 * V_63 -> V_87 ) >> 3 ;
if ( V_75 -> V_84 < V_89 )
V_75 -> V_84 = V_89 ;
V_75 -> V_85 = V_75 -> V_80 * V_75 -> V_84 * V_63 -> V_86 / V_63 -> V_87 ;
V_75 -> V_69 = V_63 -> V_2 ;
V_75 -> V_83 = F_1 ( V_75 -> V_69 ) ;
V_75 -> V_18 = 0 ;
F_36 ( L_7 , V_31 , V_62 -> type , V_75 -> V_85 ) ;
return 0 ;
}
static const struct V_88 * F_37 ( const struct V_73 * V_62 )
{
const int * V_63 ;
int V_96 , V_97 , V_98 ;
F_36 ( L_8 , V_31 , V_62 -> type , V_62 -> V_63 . V_75 . V_81 ) ;
switch ( V_62 -> type ) {
case V_41 :
V_63 = V_70 ;
V_97 = F_28 ( V_70 ) ;
V_98 = V_99 ;
break;
case V_43 :
default:
V_63 = V_71 ;
V_97 = F_28 ( V_71 ) ;
V_98 = V_100 ;
break;
}
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ )
if ( V_67 [ V_63 [ V_96 ] ] . V_2 == V_62 -> V_63 . V_75 . V_69 )
return & V_67 [ V_63 [ V_96 ] ] ;
return & V_67 [ V_98 ] ;
}
static int F_38 ( struct V_50 * V_50 , void * V_18 ,
struct V_73 * V_62 )
{
const struct V_88 * V_63 ;
V_63 = F_37 ( V_62 ) ;
if ( ! V_63 )
return - V_46 ;
return F_34 ( V_62 , V_63 ) ;
}
static int F_39 ( struct V_50 * V_50 , void * V_18 ,
struct V_73 * V_62 )
{
const struct V_88 * V_63 ;
V_63 = F_37 ( V_62 ) ;
if ( ! V_63 )
return - V_46 ;
return F_34 ( V_62 , V_63 ) ;
}
static void F_40 ( struct V_13 * V_14 , struct V_72 * V_77 )
{
unsigned int V_101 = V_77 -> V_79 . V_101 & ~ 0x03 ;
unsigned int V_102 = V_77 -> V_79 . V_102 ;
T_2 V_103 = ( ( V_101 * V_14 -> V_26 . V_63 -> V_86 ) >> 3 ) +
V_102 * V_14 -> V_26 . V_84 ;
unsigned int V_104 ;
V_77 -> V_27 = V_103 ;
switch ( V_77 -> V_63 -> V_2 ) {
case V_3 :
case V_4 :
case V_5 :
V_104 = F_41 ( V_77 -> V_79 . V_78 , 16 ) ;
V_77 -> V_29 = V_103 + V_104 * V_77 -> V_79 . V_80 ;
break;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
V_77 -> V_29 = 0 ;
break;
default:
F_2 () ;
}
}
static int F_42 ( struct V_38 * V_39 , struct V_73 * V_62 )
{
struct V_74 * V_75 = & V_62 -> V_63 . V_75 ;
struct V_13 * V_14 = V_39 -> V_76 ;
struct V_72 * V_77 ;
struct V_105 * V_106 ;
int V_107 = F_20 ( V_14 ) ;
if ( V_107 < 0 )
return V_107 ;
V_106 = F_43 ( V_14 -> V_37 , V_62 -> type ) ;
if ( ! V_106 )
return - V_46 ;
if ( F_44 ( V_106 ) ) {
F_45 ( & V_39 -> V_76 -> V_108 , L_9 , V_31 ) ;
return - V_47 ;
}
V_77 = F_30 ( V_14 , V_62 -> type ) ;
V_77 -> V_63 = F_37 ( V_62 ) ;
V_77 -> V_79 . V_78 = V_75 -> V_78 ;
V_77 -> V_79 . V_80 = V_75 -> V_80 ;
V_77 -> V_84 = V_75 -> V_84 ;
F_40 ( V_14 , V_77 ) ;
V_39 -> V_109 = true ;
F_14 ( V_14 -> V_30 ,
L_10 ,
V_62 -> type , V_75 -> V_78 , V_75 -> V_80 , V_77 -> V_63 -> V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_50 * V_50 , void * V_18 ,
struct V_73 * V_62 )
{
int V_107 = F_38 ( V_50 , V_18 , V_62 ) ;
if ( V_107 )
return V_107 ;
return F_42 ( V_18 , V_62 ) ;
}
static int F_47 ( struct V_50 * V_50 , void * V_18 ,
struct V_73 * V_62 )
{
int V_107 = F_39 ( V_50 , V_18 , V_62 ) ;
if ( V_107 )
return V_107 ;
return F_42 ( V_18 , V_62 ) ;
}
static int F_48 ( struct V_50 * V_50 , void * V_18 ,
struct V_110 * V_111 )
{
struct V_38 * V_39 = V_18 ;
struct V_13 * V_14 = V_39 -> V_76 ;
int V_107 = F_20 ( V_14 ) ;
if ( V_107 < 0 )
return V_107 ;
V_107 = F_19 ( V_14 , V_39 , V_111 -> type ) ;
if ( V_107 < 0 )
return V_107 ;
return F_49 ( V_50 , V_14 -> V_37 , V_111 ) ;
}
static int F_50 ( struct V_50 * V_50 , void * V_18 ,
struct V_112 * V_113 )
{
struct V_38 * V_39 = V_18 ;
if ( ! F_18 ( V_39 -> V_76 , V_39 , V_113 -> type ) )
return - V_47 ;
return F_51 ( V_50 , V_39 -> V_76 -> V_37 , V_113 ) ;
}
static int F_52 ( struct V_50 * V_50 , void * V_18 , struct V_112 * V_113 )
{
struct V_38 * V_39 = V_18 ;
F_14 ( V_39 -> V_76 -> V_30 , L_11 , V_31 , V_113 -> type ) ;
if ( ! F_18 ( V_39 -> V_76 , V_39 , V_113 -> type ) )
return - V_47 ;
return F_53 ( V_50 , V_39 -> V_76 -> V_37 , V_113 ) ;
}
static int F_54 ( struct V_50 * V_50 , void * V_18 , struct V_112 * V_113 )
{
struct V_38 * V_39 = V_18 ;
F_14 ( V_39 -> V_76 -> V_30 , L_11 , V_31 , V_113 -> type ) ;
if ( ! F_18 ( V_39 -> V_76 , V_39 , V_113 -> type ) )
return - V_47 ;
return F_55 ( V_50 , V_39 -> V_76 -> V_37 , V_113 ) ;
}
static void F_56 ( struct V_13 * V_14 ,
int V_114 , int V_115 , int V_116 ,
T_1 * V_117 , T_1 * V_118 , T_1 * V_119 )
{
T_1 V_120 ;
* V_119 = * V_117 = * V_118 = 0 ;
if ( V_114 == V_115 ) {
if ( V_116 != V_115 )
* V_117 = 1 ;
return;
}
if ( V_14 -> V_121 && V_115 > V_114 ) {
T_1 V_120 = ( 4096 * V_114 ) / V_115 ;
* V_117 = V_120 / 4096 ;
* V_118 = ( V_120 - ( * V_117 * 4096 ) ) & ~ 0x07 ;
switch ( * V_118 ) {
case 0x800 :
* V_119 = 1 ;
break;
case 0x400 :
* V_119 = 3 ;
break;
case 0x200 :
* V_119 = 7 ;
break;
}
if ( * V_119 )
return;
}
V_120 = ( 4096 * ( V_114 - 1 ) ) / ( V_115 + 1 ) ;
* V_117 = V_120 / 4096 ;
* V_118 = V_120 - ( * V_117 * 4096 ) ;
if ( * V_118 & 0x07 ) {
* V_118 &= ~ 0x07 ;
if ( V_115 > V_114 )
* V_118 -= 8 ;
else
* V_118 += 8 ;
}
}
static unsigned long F_57 ( struct V_13 * V_14 ,
int V_114 , int V_115 , int V_116 )
{
T_1 V_117 , V_118 , V_17 , V_119 ;
F_56 ( V_14 , V_114 , V_115 , V_116 , & V_117 , & V_118 , & V_119 ) ;
V_17 = ( F_3 ( V_14 , V_122 ) & ~ 0xffff0000 ) |
( ( ( V_117 << 12 ) | V_118 ) << 16 ) ;
F_5 ( V_14 , V_122 , V_17 ) ;
V_17 = ( F_3 ( V_14 , V_123 ) & ~ 0xffff0000 ) |
( ( ( V_119 << 12 ) | V_116 ) << 16 ) ;
F_5 ( V_14 , V_123 , V_17 ) ;
return F_41 ( ( V_114 * V_116 ) / V_115 , 4 ) ;
}
static unsigned long F_58 ( struct V_13 * V_14 ,
int V_114 , int V_115 , int V_116 )
{
T_1 V_117 , V_118 , V_17 , V_119 ;
F_56 ( V_14 , V_114 , V_115 , V_116 , & V_117 , & V_118 , & V_119 ) ;
V_17 = ( F_3 ( V_14 , V_122 ) & ~ 0xffff ) |
( V_117 << 12 ) | V_118 ;
F_5 ( V_14 , V_122 , V_17 ) ;
V_17 = ( F_3 ( V_14 , V_123 ) & ~ 0xffff ) |
( V_119 << 12 ) | V_116 ;
F_5 ( V_14 , V_123 , V_17 ) ;
return F_41 ( ( V_114 * V_116 ) / V_115 , 4 ) ;
}
static void F_59 ( struct V_13 * V_14 )
{
T_1 V_124 , V_125 , V_126 ;
T_1 V_127 , V_128 , V_129 ;
T_1 V_130 , V_131 ;
F_5 ( V_14 , V_132 , 0x100 ) ;
V_124 = V_14 -> V_33 . V_79 . V_78 ;
V_126 = V_14 -> V_33 . V_79 . V_80 ;
V_125 = F_41 ( V_14 -> V_33 . V_79 . V_78 , 16 ) ;
V_127 = V_130 = V_14 -> V_26 . V_79 . V_78 ;
V_129 = V_131 = V_14 -> V_26 . V_79 . V_80 ;
V_128 = V_14 -> V_26 . V_84 ;
V_124 = F_58 ( V_14 , V_124 , V_130 , V_127 ) ;
V_126 = F_57 ( V_14 , V_126 , V_131 , V_129 ) ;
F_5 ( V_14 , V_133 , V_125 ) ;
F_5 ( V_14 , V_134 , V_124 | ( V_126 << 16 ) ) ;
F_5 ( V_14 , V_135 , 0 ) ;
F_5 ( V_14 , V_136 , V_128 ) ;
F_5 ( V_14 , V_28 , 0 ) ;
F_5 ( V_14 , V_137 , 0x67 ) ;
F_5 ( V_14 , V_138 , ( 6 << 16 ) | ( 0 << 14 ) | 2 | 4 ) ;
if ( V_14 -> V_121 ) {
F_5 ( V_14 , V_139 , 0x0cc5 ) ;
F_5 ( V_14 , V_140 , 0x0950 ) ;
F_5 ( V_14 , V_141 , 0x0000 ) ;
F_5 ( V_14 , V_142 , 0x397f ) ;
F_5 ( V_14 , V_143 , 0x0950 ) ;
F_5 ( V_14 , V_144 , 0x3ccd ) ;
F_5 ( V_14 , V_145 , 0x0000 ) ;
F_5 ( V_14 , V_146 , 0x0950 ) ;
F_5 ( V_14 , V_147 , 0x1023 ) ;
F_5 ( V_14 , V_148 , 0x00800010 ) ;
}
}
static int F_60 ( struct V_50 * V_50 , void * V_18 ,
enum V_40 type )
{
struct V_38 * V_39 = V_18 ;
if ( ! F_18 ( V_39 -> V_76 , V_39 , type ) )
return - V_47 ;
if ( V_39 -> V_109 ) {
struct V_13 * V_14 = V_39 -> V_76 ;
V_39 -> V_109 = false ;
F_59 ( V_39 -> V_76 ) ;
V_14 -> V_149 = 0 ;
V_14 -> V_19 = false ;
}
return F_61 ( V_50 , V_39 -> V_76 -> V_37 , type ) ;
}
static int F_62 ( struct V_50 * V_50 , void * V_18 ,
enum V_40 type )
{
struct V_38 * V_39 = V_18 ;
if ( ! F_18 ( V_39 -> V_76 , V_39 , type ) )
return - V_47 ;
return F_63 ( V_50 , V_39 -> V_76 -> V_37 , type ) ;
}
static int F_64 ( struct V_105 * V_106 ,
const struct V_73 * V_62 ,
unsigned int * V_150 , unsigned int * V_151 ,
unsigned int V_152 [] , void * V_153 [] )
{
struct V_13 * V_14 = F_65 ( V_106 ) ;
struct V_72 * V_77 ;
unsigned int V_154 , V_155 = * V_150 ;
if ( V_62 ) {
const struct V_74 * V_75 = & V_62 -> V_63 . V_75 ;
const struct V_88 * V_63 = F_37 ( V_62 ) ;
struct V_73 V_156 = * V_62 ;
if ( V_63 -> V_2 != V_75 -> V_69 )
return - V_46 ;
F_34 ( & V_156 , V_63 ) ;
if ( V_156 . V_63 . V_75 . V_78 != V_75 -> V_78 ||
V_156 . V_63 . V_75 . V_80 != V_75 -> V_80 )
return - V_46 ;
V_154 = V_75 -> V_84 ? V_75 -> V_84 * V_75 -> V_80 * V_63 -> V_86 / V_63 -> V_87 :
V_75 -> V_78 * V_75 -> V_80 * V_63 -> V_86 / V_63 -> V_87 ;
} else {
V_77 = F_30 ( V_14 , V_106 -> type ) ;
V_154 = V_77 -> V_84 * V_77 -> V_79 . V_80 * V_77 -> V_63 -> V_86 / V_77 -> V_63 -> V_87 ;
}
if ( V_155 < 2 )
* V_150 = V_155 = 2 ;
if ( V_154 * V_155 > V_157 ) {
V_155 = V_157 / V_154 ;
* V_150 = V_155 ;
}
* V_151 = 1 ;
V_152 [ 0 ] = V_154 ;
V_153 [ 0 ] = V_14 -> V_158 ;
F_14 ( V_14 -> V_30 , L_12 , V_155 , V_154 ) ;
return 0 ;
}
static int F_66 ( struct V_21 * V_159 )
{
struct V_13 * V_14 = F_65 ( V_159 -> V_105 ) ;
struct V_72 * V_77 ;
unsigned int V_85 ;
V_77 = F_30 ( V_14 , V_159 -> V_105 -> type ) ;
V_85 = V_77 -> V_84 * V_77 -> V_79 . V_80 *
V_77 -> V_63 -> V_86 / V_77 -> V_63 -> V_87 ;
if ( F_67 ( V_159 , 0 ) < V_85 ) {
F_14 ( V_14 -> V_30 , L_13 ,
V_31 , F_67 ( V_159 , 0 ) , V_85 ) ;
return - V_46 ;
}
F_68 ( V_159 , 0 , V_85 ) ;
return 0 ;
}
static void F_69 ( struct V_21 * V_159 )
{
struct V_13 * V_14 = F_65 ( V_159 -> V_105 ) ;
F_14 ( V_14 -> V_30 , L_11 , V_31 , V_159 -> V_160 . type ) ;
F_70 ( V_14 -> V_37 , V_159 ) ;
}
static void F_71 ( struct V_105 * V_161 )
{
F_10 ( F_65 ( V_161 ) ) ;
}
static void F_72 ( struct V_105 * V_161 )
{
F_8 ( F_65 ( V_161 ) ) ;
}
static int V_49 ( void * V_18 , struct V_105 * V_162 ,
struct V_105 * V_163 )
{
int V_107 ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
V_162 -> type = V_43 ;
V_162 -> V_164 = V_165 | V_166 ;
V_162 -> V_167 = V_18 ;
V_162 -> V_168 = sizeof( struct V_169 ) ;
V_162 -> V_170 = & V_171 ;
V_162 -> V_172 = & V_173 ;
V_107 = F_73 ( V_162 ) ;
if ( V_107 < 0 )
return V_107 ;
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
V_163 -> type = V_41 ;
V_163 -> V_164 = V_165 | V_166 ;
V_163 -> V_167 = V_18 ;
V_163 -> V_168 = sizeof( struct V_169 ) ;
V_163 -> V_170 = & V_171 ;
V_163 -> V_172 = & V_173 ;
return F_73 ( V_163 ) ;
}
static int F_74 ( struct V_50 * V_50 )
{
struct V_13 * V_14 = F_75 ( V_50 ) ;
struct V_38 * V_39 ;
V_39 = F_76 ( sizeof( * V_39 ) , V_174 ) ;
if ( ! V_39 )
return - V_175 ;
V_39 -> V_76 = V_14 ;
V_39 -> V_109 = true ;
V_50 -> V_176 = V_39 ;
F_77 ( V_14 -> V_30 ) ;
F_14 ( V_14 -> V_30 , L_14 , V_39 ) ;
return 0 ;
}
static int F_78 ( struct V_50 * V_50 )
{
struct V_13 * V_14 = F_75 ( V_50 ) ;
struct V_38 * V_39 = V_50 -> V_176 ;
F_14 ( V_14 -> V_30 , L_15 , V_39 ) ;
if ( V_39 == V_14 -> V_42 ) {
V_14 -> V_42 = NULL ;
F_79 ( F_43 ( V_14 -> V_37 , V_41 ) ) ;
}
if ( V_39 == V_14 -> V_44 ) {
V_14 -> V_44 = NULL ;
F_79 ( F_43 ( V_14 -> V_37 , V_43 ) ) ;
}
if ( ! V_14 -> V_44 && ! V_14 -> V_42 && V_14 -> V_37 ) {
F_80 ( V_14 -> V_37 ) ;
V_14 -> V_37 = NULL ;
}
F_81 ( V_14 -> V_30 ) ;
F_82 ( V_39 ) ;
return 0 ;
}
static unsigned int F_83 ( struct V_50 * V_50 ,
struct V_177 * V_178 )
{
struct V_38 * V_39 = V_50 -> V_176 ;
return F_84 ( V_50 , V_39 -> V_76 -> V_37 , V_178 ) ;
}
static int F_85 ( struct V_50 * V_50 , struct V_179 * V_180 )
{
struct V_38 * V_39 = V_50 -> V_176 ;
return F_86 ( V_50 , V_39 -> V_76 -> V_37 , V_180 ) ;
}
static T_3 F_87 ( int V_181 , void * V_182 )
{
struct V_13 * V_14 = V_182 ;
if ( V_14 -> V_149 == V_183 || V_14 -> V_19 ) {
F_88 ( V_14 -> V_48 , V_14 -> V_37 ) ;
V_14 -> V_149 = 0 ;
} else {
F_15 ( V_14 ) ;
}
return V_184 ;
}
static T_3 F_89 ( int V_181 , void * V_182 )
{
struct V_13 * V_14 = V_182 ;
struct V_21 * V_185 ;
struct V_21 * V_186 ;
T_1 V_187 = F_3 ( V_14 , V_188 ) ;
if ( ! ( V_187 & 1 ) )
return V_189 ;
F_5 ( V_14 , V_36 , 0 ) ;
F_5 ( V_14 , V_35 , 0 ) ;
F_5 ( V_14 , V_188 , V_187 & ~ 1 ) ;
V_185 = F_90 ( V_14 -> V_37 ) ;
V_186 = F_91 ( V_14 -> V_37 ) ;
if ( ! V_186 || ! V_185 )
return V_189 ;
F_92 ( & V_14 -> V_190 ) ;
F_93 ( V_186 , V_191 ) ;
F_93 ( V_185 , V_191 ) ;
F_94 ( & V_14 -> V_190 ) ;
V_14 -> V_149 ++ ;
return V_192 ;
}
static int F_95 ( struct V_193 * V_194 )
{
struct V_13 * V_14 ;
struct V_195 * V_196 ;
struct V_197 * V_198 ;
int V_181 , V_107 ;
V_196 = F_96 ( V_194 , V_199 , 0 ) ;
V_181 = F_97 ( V_194 , 0 ) ;
if ( ! V_196 || V_181 <= 0 ) {
F_98 ( & V_194 -> V_30 , L_16 ) ;
return - V_200 ;
}
V_14 = F_99 ( & V_194 -> V_30 , sizeof( * V_14 ) , V_174 ) ;
if ( ! V_14 )
return - V_175 ;
V_14 -> V_121 = F_100 ( V_196 ) == 0x22c ;
V_14 -> V_16 = F_101 ( & V_194 -> V_30 , V_196 ) ;
if ( F_22 ( V_14 -> V_16 ) )
return F_23 ( V_14 -> V_16 ) ;
V_107 = F_102 ( & V_194 -> V_30 , V_181 , F_89 , F_87 ,
0 , L_17 , V_14 ) ;
if ( V_107 < 0 )
return V_107 ;
V_107 = F_103 ( & V_194 -> V_30 , & V_14 -> V_108 ) ;
if ( V_107 < 0 ) {
F_98 ( & V_194 -> V_30 , L_18 ) ;
return V_107 ;
}
V_198 = & V_14 -> V_198 ;
V_14 -> V_158 = F_104 ( & V_194 -> V_30 ) ;
if ( F_22 ( V_14 -> V_158 ) ) {
V_107 = F_23 ( V_14 -> V_158 ) ;
goto V_201;
}
* V_198 = V_202 ;
F_105 ( & V_14 -> V_190 ) ;
F_106 ( & V_14 -> V_20 ) ;
V_198 -> V_190 = & V_14 -> V_20 ;
F_107 ( V_198 , V_14 ) ;
V_14 -> V_30 = & V_194 -> V_30 ;
V_14 -> V_26 = V_203 ;
V_14 -> V_33 = V_204 ;
V_14 -> V_48 = F_108 ( & V_205 ) ;
if ( F_22 ( V_14 -> V_48 ) ) {
V_107 = F_23 ( V_14 -> V_48 ) ;
F_45 ( & V_14 -> V_108 , L_19 , V_107 ) ;
goto V_206;
}
F_109 ( & V_194 -> V_30 ) ;
F_110 ( & V_194 -> V_30 ) ;
V_107 = F_111 ( V_198 , V_207 , - 1 ) ;
F_112 ( & V_194 -> V_30 ) ;
if ( V_107 < 0 )
goto V_208;
return V_107 ;
V_208:
F_113 ( & V_194 -> V_30 ) ;
F_114 ( V_14 -> V_48 ) ;
V_206:
F_115 ( V_14 -> V_158 ) ;
V_201:
F_116 ( & V_14 -> V_108 ) ;
return V_107 ;
}
static int F_117 ( struct V_193 * V_194 )
{
struct V_209 * V_108 = F_118 ( V_194 ) ;
struct V_13 * V_14 = F_119 ( V_108 ,
struct V_13 , V_108 ) ;
F_120 ( & V_14 -> V_198 ) ;
F_113 ( & V_194 -> V_30 ) ;
F_114 ( V_14 -> V_48 ) ;
F_115 ( V_14 -> V_158 ) ;
F_116 ( & V_14 -> V_108 ) ;
return 0 ;
}
