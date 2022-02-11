static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
F_2 ( V_4 , V_2 -> V_5 + V_3 + 0x1000 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 + 0x2000 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_6 ( V_2 -> V_5 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_6 )
{
T_1 V_7 = F_6 ( V_2 -> V_5 + V_3 ) ;
V_4 = ( V_4 & V_6 ) | ( V_7 & ~ V_6 ) ;
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_6 )
{
F_7 ( V_2 , V_3 + 0x1000 , V_4 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_6 )
{
F_7 ( V_2 , V_3 , V_4 , V_6 ) ;
F_8 ( V_2 , V_3 , V_4 , V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_2 V_10 , V_11 ;
V_10 = F_11 ( V_9 ) ;
switch ( V_2 -> V_12 . V_13 ) {
case V_14 :
case V_15 :
V_11 = V_10 + V_2 -> V_12 . V_16 * V_2 -> V_12 . V_17 ;
break;
default:
V_11 = 0 ;
}
F_4 ( V_2 , V_18 , V_10 ) ;
F_4 ( V_2 , V_19 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned int V_20 ;
#ifdef F_13
T_1 V_21 = 7 ;
#else
T_1 V_21 = 0 ;
#endif
switch ( V_2 -> V_12 . V_13 ) {
default:
case V_14 :
case V_15 :
V_20 = 1 ;
break;
case V_22 :
V_21 ^= 1 ;
case V_23 :
V_20 = 2 ;
break;
case V_24 :
V_20 = 3 ;
break;
}
F_1 ( V_2 , V_25 , V_21 ) ;
F_3 ( V_2 , V_26 , V_2 -> V_12 . V_16 * V_20 ) ;
F_10 ( V_2 , V_9 ) ;
}
static void F_14 ( struct V_27 * V_28 , struct V_8 * V_9 )
{
F_15 ( F_16 () ) ;
F_17 ( V_28 , V_9 , 0 , 0 ) ;
F_18 ( V_28 , V_9 ) ;
V_9 -> V_29 = V_30 ;
}
static int F_19 ( struct V_27 * V_28 , unsigned int * V_31 ,
unsigned int * V_32 )
{
struct V_33 * V_34 = V_28 -> V_35 ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
* V_32 = V_36 [ V_2 -> V_37 ] . V_38 * V_2 -> V_12 . V_16 *
V_2 -> V_12 . V_17 / 8 ;
if ( * V_31 < 2 )
* V_31 = 2 ;
if ( F_21 ( * V_32 ) * * V_31 > 4 * 1024 * 1024 )
* V_31 = 4 * 1024 * 1024 / F_21 ( * V_32 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_1 , V_41 ,
* V_31 , * V_32 ) ;
return 0 ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_8 * V_9 ,
enum V_42 V_43 )
{
struct V_33 * V_34 = V_28 -> V_35 ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_44 * V_12 = & V_2 -> V_12 ;
int V_45 = V_36 [ V_2 -> V_37 ] . V_38 * V_12 -> V_16 / 8 ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( V_9 -> V_16 != V_12 -> V_16 ||
V_9 -> V_17 != V_12 -> V_17 ||
V_9 -> V_43 != V_12 -> V_43 ) {
V_9 -> V_16 = V_12 -> V_16 ;
V_9 -> V_17 = V_12 -> V_17 ;
V_9 -> V_43 = V_43 ;
if ( V_9 -> V_29 != V_30 )
F_14 ( V_28 , V_9 ) ;
}
V_9 -> V_32 = V_9 -> V_17 * V_45 ;
if ( V_9 -> V_47 && V_9 -> V_48 < V_9 -> V_32 ) {
F_24 ( V_28 -> V_40 , L_3 ,
V_9 -> V_48 , V_9 -> V_47 ) ;
return - V_49 ;
}
if ( V_9 -> V_29 == V_30 ) {
V_46 = F_25 ( V_28 , V_9 , NULL ) ;
if ( V_46 < 0 ) {
F_24 ( V_28 -> V_40 , L_4 ,
V_9 -> V_50 , V_46 ) ;
return V_46 ;
}
V_9 -> V_29 = V_51 ;
}
F_22 (vou_dev->v4l2_dev.dev,
L_5 ,
__func__, vou_dev->pix_idx, bytes_per_line,
({ dma_addr_t addr = videobuf_to_dma_contig(vb); &addr; }),
vb->memory, vb->state) ;
return 0 ;
}
static void F_26 ( struct V_27 * V_28 ,
struct V_8 * V_9 )
{
struct V_33 * V_34 = V_28 -> V_35 ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_9 -> V_29 = V_52 ;
F_27 ( & V_9 -> V_53 , & V_2 -> V_53 ) ;
if ( V_2 -> V_54 == V_55 ) {
return;
} else if ( ! V_2 -> V_56 ) {
V_2 -> V_56 = V_9 ;
F_1 ( V_2 , V_57 , 1 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_6 ,
V_41 , F_5 ( V_2 , V_58 ) ) ;
F_10 ( V_2 , V_9 ) ;
} else if ( V_2 -> V_56 -> V_53 . V_59 == & V_9 -> V_53 ) {
F_1 ( V_2 , V_57 , 0 ) ;
F_12 ( V_2 , V_9 ) ;
F_1 ( V_2 , V_60 , 5 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_7 ,
V_41 , F_5 ( V_2 , V_58 ) ) ;
F_1 ( V_2 , V_61 , 0x10004 ) ;
V_2 -> V_54 = V_55 ;
F_1 ( V_2 , V_62 , 0x107 ) ;
}
}
static void F_28 ( struct V_27 * V_28 ,
struct V_8 * V_9 )
{
struct V_33 * V_34 = V_28 -> V_35 ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
unsigned long V_63 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
F_29 ( & V_2 -> V_64 , V_63 ) ;
if ( V_2 -> V_56 == V_9 ) {
F_7 ( V_2 , V_62 , 0 , 1 ) ;
F_7 ( V_2 , V_61 , 0 , 0x30000 ) ;
V_2 -> V_56 = NULL ;
}
if ( ( V_9 -> V_29 == V_65 || V_9 -> V_29 == V_52 ) ) {
V_9 -> V_29 = V_66 ;
F_30 ( & V_9 -> V_53 ) ;
}
F_31 ( & V_2 -> V_64 , V_63 ) ;
F_14 ( V_28 , V_9 ) ;
}
static int F_32 ( struct V_67 * V_67 , void * V_68 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
F_34 ( V_70 -> V_71 , L_8 , sizeof( V_70 -> V_71 ) ) ;
V_70 -> V_72 = V_73 | V_74 ;
return 0 ;
}
static int F_35 ( struct V_67 * V_67 , void * V_68 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
if ( V_76 -> V_77 >= F_36 ( V_36 ) )
return - V_49 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_76 -> type = V_78 ;
F_34 ( V_76 -> V_79 , V_36 [ V_76 -> V_77 ] . V_80 ,
sizeof( V_76 -> V_79 ) ) ;
V_76 -> V_13 = V_36 [ V_76 -> V_77 ] . V_81 ;
return 0 ;
}
static int F_37 ( struct V_67 * V_67 , void * V_68 ,
struct V_82 * V_76 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_76 -> type = V_78 ;
V_76 -> V_76 . V_12 = V_2 -> V_12 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
int V_37 , int V_83 , int V_84 )
{
struct V_85 * V_76 = V_36 + V_37 ;
unsigned int V_86 , V_87 , V_88 ,
V_89 , V_90 , V_91 ;
struct V_92 * V_93 = & V_2 -> V_93 ;
struct V_44 * V_12 = & V_2 -> V_12 ;
T_1 V_94 = 0 , V_95 , V_96 ;
if ( V_2 -> V_97 & V_98 ) {
V_88 = 858 ;
} else {
V_88 = 864 ;
}
V_89 = V_12 -> V_17 / 2 ;
V_90 = V_93 -> V_17 / 2 ;
V_91 = V_93 -> V_99 / 2 ;
V_86 = V_88 - V_100 ;
V_87 = 20 ;
V_95 = V_93 -> V_16 + V_93 -> V_101 ;
V_96 = V_90 + V_91 ;
F_22 ( V_2 -> V_39 . V_40 ,
L_9 ,
V_12 -> V_16 , V_89 , V_86 , V_87 ,
V_93 -> V_101 , V_91 , V_95 , V_96 ) ;
F_3 ( V_2 , V_102 , ( V_12 -> V_16 << 16 ) | V_89 ) ;
F_3 ( V_2 , V_103 , ( V_86 << 16 ) | V_87 ) ;
F_3 ( V_2 , V_104 , ( V_93 -> V_101 << 16 ) | V_91 ) ;
F_3 ( V_2 , V_105 , ( V_95 << 16 ) | V_96 ) ;
if ( V_83 )
V_94 |= ( 1 << 15 ) | ( V_106 [ V_83 - 1 ] << 4 ) ;
if ( V_84 )
V_94 |= ( 1 << 14 ) | V_107 [ V_84 - 1 ] ;
F_22 ( V_2 -> V_39 . V_40 , L_10 , V_76 -> V_80 , V_94 ) ;
F_3 ( V_2 , V_108 , V_94 ) ;
F_3 ( V_2 , V_109 ,
V_76 -> V_110 | ( V_76 -> V_111 << 8 ) | ( V_76 -> V_112 << 16 ) ) ;
}
static void F_39 ( struct V_113 * V_114 , T_3 V_97 )
{
unsigned int V_115 = V_116 , V_117 = 0 , V_118 ;
int V_119 , V_120 = 0 ;
if ( V_97 & V_98 )
V_118 = 480 ;
else
V_118 = 576 ;
F_40 ( & V_114 -> V_121 , 0 , V_100 , 2 ,
& V_114 -> V_122 , 0 , V_118 , 1 , 0 ) ;
for ( V_119 = F_36 ( V_123 ) - 1 ; V_119 >= 0 ; V_119 -- ) {
unsigned int V_124 ;
unsigned int V_125 = V_114 -> V_126 . V_16 * V_127 [ V_119 ] /
V_123 [ V_119 ] ;
if ( V_125 > V_100 )
break;
V_124 = abs ( V_125 - V_114 -> V_121 ) ;
if ( V_124 < V_115 ) {
V_115 = V_124 ;
V_120 = V_119 ;
V_117 = V_125 ;
}
if ( ! V_124 )
break;
}
V_114 -> V_121 = V_117 ;
V_114 -> V_128 = V_120 ;
V_115 = V_116 ;
for ( V_119 = F_36 ( V_129 ) - 1 ; V_119 >= 0 ; V_119 -- ) {
unsigned int V_124 ;
unsigned int V_125 = V_114 -> V_126 . V_17 * V_130 [ V_119 ] /
V_129 [ V_119 ] ;
if ( V_125 > V_118 )
break;
V_124 = abs ( V_125 - V_114 -> V_122 ) ;
if ( V_124 < V_115 ) {
V_115 = V_124 ;
V_120 = V_119 ;
V_117 = V_125 ;
}
if ( ! V_124 )
break;
}
V_114 -> V_122 = V_117 ;
V_114 -> V_131 = V_120 ;
}
static void F_41 ( struct V_113 * V_114 , T_3 V_97 )
{
unsigned int V_115 = V_116 , V_117 = V_114 -> V_121 ,
V_88 , V_132 , V_118 ;
int V_119 , V_120 = 0 ;
if ( V_97 & V_98 ) {
V_88 = 858 ;
V_132 = 262 * 2 ;
V_118 = 480 ;
} else {
V_88 = 864 ;
V_132 = 312 * 2 ;
V_118 = 576 ;
}
for ( V_119 = 0 ; V_119 < F_36 ( V_123 ) ; V_119 ++ ) {
unsigned int V_124 ;
unsigned int V_125 = V_114 -> V_121 * V_123 [ V_119 ] /
V_127 [ V_119 ] ;
if ( V_125 > V_100 )
break;
V_124 = abs ( V_125 - V_114 -> V_126 . V_16 ) ;
if ( V_124 < V_115 ) {
V_115 = V_124 ;
V_120 = V_119 ;
V_117 = V_125 ;
}
if ( ! V_124 )
break;
}
V_114 -> V_126 . V_16 = V_117 ;
V_114 -> V_128 = V_120 ;
if ( V_114 -> V_126 . V_101 + V_117 > V_88 )
V_114 -> V_126 . V_101 = V_88 - V_117 ;
F_42 ( L_11 , V_41 , V_114 -> V_121 ,
V_123 [ V_120 ] , V_127 [ V_120 ] , V_117 ) ;
V_115 = V_116 ;
for ( V_119 = 0 ; V_119 < F_36 ( V_129 ) ; V_119 ++ ) {
unsigned int V_124 ;
unsigned int V_125 = V_114 -> V_122 * V_129 [ V_119 ] /
V_130 [ V_119 ] ;
if ( V_125 > V_118 )
break;
V_124 = abs ( V_125 - V_114 -> V_126 . V_17 ) ;
if ( V_124 < V_115 ) {
V_115 = V_124 ;
V_120 = V_119 ;
V_117 = V_125 ;
}
if ( ! V_124 )
break;
}
V_114 -> V_126 . V_17 = V_117 ;
V_114 -> V_131 = V_120 ;
if ( V_114 -> V_126 . V_99 + V_117 > V_132 )
V_114 -> V_126 . V_99 = V_132 - V_117 ;
F_42 ( L_12 , V_41 , V_114 -> V_122 ,
V_129 [ V_120 ] , V_130 [ V_120 ] , V_117 ) ;
}
static int F_43 ( struct V_67 * V_67 , void * V_68 ,
struct V_82 * V_76 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_44 * V_12 = & V_76 -> V_76 . V_12 ;
unsigned int V_118 ;
int V_37 ;
struct V_113 V_114 ;
struct V_133 V_134 = {
. V_135 = V_136 ,
. V_43 = V_137 ,
. V_138 = V_139 ,
} ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_13 , V_41 ,
V_2 -> V_93 . V_16 , V_2 -> V_93 . V_17 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
if ( V_12 -> V_43 == V_140 )
V_12 -> V_43 = V_141 ;
if ( V_76 -> type != V_78 ||
V_12 -> V_43 != V_141 )
return - V_49 ;
for ( V_37 = 0 ; V_37 < F_36 ( V_36 ) ; V_37 ++ )
if ( V_36 [ V_37 ] . V_81 == V_12 -> V_13 )
break;
if ( V_37 == F_36 ( V_36 ) )
return - V_49 ;
if ( V_2 -> V_97 & V_98 )
V_118 = 480 ;
else
V_118 = 576 ;
F_40 ( & V_12 -> V_16 , 0 , V_100 , 2 ,
& V_12 -> V_17 , 0 , V_118 , 1 , 0 ) ;
V_114 . V_121 = V_12 -> V_16 ;
V_114 . V_122 = V_12 -> V_17 ;
V_114 . V_126 = V_2 -> V_93 ;
F_41 ( & V_114 , V_2 -> V_97 ) ;
V_134 . V_16 = V_114 . V_126 . V_16 ;
V_134 . V_17 = V_114 . V_126 . V_17 ;
V_46 = F_44 ( & V_2 -> V_39 , 0 , V_142 ,
V_143 , & V_134 ) ;
if ( V_46 < 0 )
return V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_13 , V_41 ,
V_114 . V_126 . V_16 , V_114 . V_126 . V_17 , V_134 . V_16 , V_134 . V_17 ) ;
if ( ( unsigned ) V_134 . V_16 > V_100 ||
( unsigned ) V_134 . V_17 > V_118 ||
V_134 . V_135 != V_136 )
return - V_144 ;
if ( V_134 . V_16 != V_114 . V_126 . V_16 ||
V_134 . V_17 != V_114 . V_126 . V_17 ) {
V_114 . V_126 . V_16 = V_134 . V_16 ;
V_114 . V_126 . V_17 = V_134 . V_17 ;
F_39 ( & V_114 , V_2 -> V_97 ) ;
}
V_2 -> V_93 = V_114 . V_126 ;
V_12 -> V_16 = V_114 . V_121 ;
V_12 -> V_17 = V_114 . V_122 ;
F_22 ( V_2 -> V_39 . V_40 , L_14 , V_41 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_12 = * V_12 ;
F_38 ( V_2 , V_37 ,
V_114 . V_128 , V_114 . V_131 ) ;
return 0 ;
}
static int F_45 ( struct V_67 * V_67 , void * V_68 ,
struct V_82 * V_76 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_44 * V_12 = & V_76 -> V_76 . V_12 ;
int V_119 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_76 -> type = V_78 ;
V_12 -> V_43 = V_141 ;
F_40 ( & V_12 -> V_16 , 0 , V_100 , 1 ,
& V_12 -> V_17 , 0 , V_145 , 1 , 0 ) ;
for ( V_119 = 0 ; V_119 < F_36 ( V_36 ) ; V_119 ++ )
if ( V_36 [ V_119 ] . V_81 == V_12 -> V_13 )
return 0 ;
V_12 -> V_13 = V_36 [ 0 ] . V_81 ;
return 0 ;
}
static int F_46 ( struct V_67 * V_67 , void * V_68 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( V_147 -> type != V_78 )
return - V_49 ;
return F_47 ( & V_149 -> V_150 , V_147 ) ;
}
static int F_48 ( struct V_67 * V_67 , void * V_68 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
return F_49 ( & V_149 -> V_150 , V_152 ) ;
}
static int F_50 ( struct V_67 * V_67 , void * V_68 , struct V_151 * V_152 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
return F_51 ( & V_149 -> V_150 , V_152 ) ;
}
static int F_52 ( struct V_67 * V_67 , void * V_68 , struct V_151 * V_152 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
return F_53 ( & V_149 -> V_150 , V_152 , V_67 -> V_153 & V_154 ) ;
}
static int F_54 ( struct V_67 * V_67 , void * V_68 ,
enum V_155 V_156 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_68 ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_46 = F_44 ( & V_2 -> V_39 , 0 ,
V_142 , V_157 , 1 ) ;
if ( V_46 < 0 && V_46 != - V_158 )
return V_46 ;
return F_55 ( & V_149 -> V_150 ) ;
}
static int F_56 ( struct V_67 * V_67 , void * V_68 ,
enum V_155 V_156 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
F_57 ( & V_149 -> V_150 ) ;
F_44 ( & V_2 -> V_39 , 0 , V_142 , V_157 , 0 ) ;
return 0 ;
}
static T_1 F_58 ( enum V_159 V_160 )
{
switch ( V_160 ) {
default:
F_59 ( L_15 ,
V_41 , V_160 ) ;
case V_161 :
return 1 ;
case V_162 :
return 0 ;
case V_163 :
return 3 ;
}
}
static int F_60 ( struct V_67 * V_67 , void * V_68 , T_3 V_164 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_16 , V_41 , V_164 ) ;
if ( V_164 & ~ V_2 -> V_34 -> V_165 )
return - V_49 ;
V_46 = F_44 ( & V_2 -> V_39 , 0 , V_142 ,
V_166 , V_164 ) ;
if ( V_46 < 0 && V_46 != - V_158 )
return V_46 ;
if ( V_164 & V_98 )
F_9 ( V_2 , V_167 ,
F_58 ( V_2 -> V_168 -> V_160 ) << 29 , 7 << 29 ) ;
else
F_9 ( V_2 , V_167 , 5 << 29 , 7 << 29 ) ;
V_2 -> V_97 = V_164 ;
return 0 ;
}
static int F_61 ( struct V_67 * V_67 , void * V_68 , T_3 * V_97 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
* V_97 = V_2 -> V_97 ;
return 0 ;
}
static int F_62 ( struct V_67 * V_67 , void * V_169 , struct V_170 * V_171 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_171 -> type = V_78 ;
V_171 -> V_172 = V_2 -> V_93 ;
return 0 ;
}
static int F_63 ( struct V_67 * V_67 , void * V_169 , const struct V_170 * V_171 )
{
struct V_170 V_173 = * V_171 ;
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_92 * V_93 = & V_173 . V_172 ;
struct V_170 V_174 = { . type = V_78 } ;
struct V_44 * V_12 = & V_2 -> V_12 ;
struct V_113 V_114 ;
struct V_133 V_134 = {
. V_135 = V_136 ,
. V_43 = V_137 ,
. V_138 = V_139 ,
} ;
unsigned int V_118 ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_17 , V_41 ,
V_93 -> V_16 , V_93 -> V_17 , V_93 -> V_101 , V_93 -> V_99 ) ;
if ( V_171 -> type != V_78 )
return - V_49 ;
if ( V_2 -> V_97 & V_98 )
V_118 = 480 ;
else
V_118 = 576 ;
F_40 ( & V_93 -> V_16 , 0 , V_100 , 1 ,
& V_93 -> V_17 , 0 , V_118 , 1 , 0 ) ;
if ( V_93 -> V_16 + V_93 -> V_101 > V_100 )
V_93 -> V_101 = V_100 - V_93 -> V_16 ;
if ( V_93 -> V_17 + V_93 -> V_99 > V_118 )
V_93 -> V_99 = V_118 - V_93 -> V_17 ;
V_114 . V_126 = * V_93 ;
V_114 . V_121 = V_12 -> V_16 ;
V_114 . V_122 = V_12 -> V_17 ;
V_174 . V_172 . V_16 = V_114 . V_126 . V_16 ;
V_174 . V_172 . V_17 = V_114 . V_126 . V_17 ;
F_44 ( & V_2 -> V_39 , 0 , V_142 ,
V_175 , & V_174 ) ;
V_134 . V_16 = V_114 . V_126 . V_16 ;
V_134 . V_17 = V_114 . V_126 . V_17 ;
V_46 = F_44 ( & V_2 -> V_39 , 0 , V_142 ,
V_143 , & V_134 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( ( unsigned ) V_134 . V_16 > V_100 ||
( unsigned ) V_134 . V_17 > V_118 ||
V_134 . V_135 != V_136 )
return - V_144 ;
V_114 . V_126 . V_16 = V_134 . V_16 ;
V_114 . V_126 . V_17 = V_134 . V_17 ;
F_39 ( & V_114 , V_2 -> V_97 ) ;
V_2 -> V_93 = V_114 . V_126 ;
V_12 -> V_16 = V_114 . V_121 ;
V_12 -> V_17 = V_114 . V_122 ;
F_38 ( V_2 , V_2 -> V_37 ,
V_114 . V_128 , V_114 . V_131 ) ;
return 0 ;
}
static int F_64 ( struct V_67 * V_67 , void * V_68 ,
struct V_176 * V_171 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_171 -> type = V_78 ;
V_171 -> V_177 . V_101 = 0 ;
V_171 -> V_177 . V_99 = 0 ;
V_171 -> V_177 . V_16 = V_100 ;
V_171 -> V_177 . V_17 = V_145 ;
V_171 -> V_178 . V_101 = 0 ;
V_171 -> V_178 . V_99 = 0 ;
V_171 -> V_178 . V_16 = V_100 ;
V_171 -> V_178 . V_17 = V_145 ;
V_171 -> V_179 . V_180 = 1 ;
V_171 -> V_179 . V_181 = 1 ;
return 0 ;
}
static T_4 F_65 ( int V_182 , void * V_183 )
{
struct V_1 * V_2 = V_183 ;
static unsigned long V_184 ;
struct V_8 * V_9 ;
static int V_185 ;
T_1 V_186 = F_5 ( V_2 , V_61 ) , V_187 ;
T_1 V_188 = F_5 ( V_2 , V_58 ) ;
if ( ! ( V_186 & 0x300 ) ) {
if ( F_66 ( & V_184 , 500 ) )
F_24 ( V_2 -> V_39 . V_40 , L_18 ,
V_186 ) ;
return V_189 ;
}
F_67 ( & V_2 -> V_64 ) ;
if ( ! V_2 -> V_56 || F_68 ( & V_2 -> V_53 ) ) {
if ( F_66 ( & V_184 , 500 ) )
F_24 ( V_2 -> V_39 . V_40 ,
L_19 , V_186 ) ;
F_7 ( V_2 , V_61 , 0 , 0x300 ) ;
F_69 ( & V_2 -> V_64 ) ;
return V_190 ;
}
V_187 = ~ ( 0x300 & V_186 ) & V_186 & 0x30304 ;
F_22 ( V_2 -> V_39 . V_40 ,
L_20 ,
V_186 , V_187 , V_188 , V_185 ) ;
V_185 ++ ;
F_1 ( V_2 , V_61 , V_187 ) ;
V_9 = V_2 -> V_56 ;
F_30 ( & V_9 -> V_53 ) ;
V_9 -> V_29 = V_191 ;
F_70 ( & V_9 -> V_192 ) ;
V_9 -> V_193 ++ ;
F_71 ( & V_9 -> V_194 ) ;
if ( F_68 ( & V_2 -> V_53 ) ) {
F_22 ( V_2 -> V_39 . V_40 , L_21 ,
V_41 , V_185 ) ;
F_7 ( V_2 , V_62 , 0 , 1 ) ;
V_2 -> V_56 = NULL ;
V_2 -> V_54 = V_195 ;
F_7 ( V_2 , V_61 , 0 , 0x30000 ) ;
F_69 ( & V_2 -> V_64 ) ;
return V_190 ;
}
V_2 -> V_56 = F_72 ( V_2 -> V_53 . V_59 ,
struct V_8 , V_53 ) ;
if ( V_2 -> V_56 -> V_53 . V_59 != & V_2 -> V_53 ) {
struct V_8 * V_196 = F_72 ( V_2 -> V_56 -> V_53 . V_59 ,
struct V_8 , V_53 ) ;
F_10 ( V_2 , V_196 ) ;
}
F_69 ( & V_2 -> V_64 ) ;
return V_190 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_197 * V_168 = V_2 -> V_168 ;
T_1 V_198 = F_58 ( V_168 -> V_160 ) << 29 ;
int V_119 = 100 ;
F_1 ( V_2 , V_61 , 0 ) ;
F_1 ( V_2 , V_199 , 0x101 ) ;
while ( -- V_119 && ( F_5 ( V_2 , V_199 ) & 0x101 ) )
F_74 ( 1 ) ;
if ( ! V_119 )
return - V_200 ;
F_22 ( V_2 -> V_39 . V_40 , L_22 , 100 - V_119 ) ;
if ( V_168 -> V_63 & V_201 )
V_198 |= 1 << 28 ;
if ( V_168 -> V_63 & V_202 )
V_198 |= 1 << 27 ;
if ( V_168 -> V_63 & V_203 )
V_198 |= 1 << 26 ;
F_9 ( V_2 , V_167 , V_198 , 0xfc000000 ) ;
F_1 ( V_2 , V_60 , 4 ) ;
F_3 ( V_2 , V_204 , 0x800000 ) ;
return 0 ;
}
static int F_75 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = F_76 ( sizeof( struct V_148 ) ,
V_205 ) ;
if ( ! V_149 )
return - V_206 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_67 -> V_207 = V_149 ;
if ( F_77 ( & V_2 -> V_208 ) )
return - V_209 ;
if ( F_78 ( & V_2 -> V_210 ) == 1 ) {
int V_46 ;
V_2 -> V_54 = V_195 ;
F_79 ( V_2 -> V_39 . V_40 ) ;
V_46 = F_73 ( V_2 ) ;
if ( V_46 < 0 ) {
F_80 ( & V_2 -> V_210 ) ;
F_81 ( V_2 -> V_39 . V_40 ) ;
V_2 -> V_54 = V_211 ;
F_82 ( & V_2 -> V_208 ) ;
return V_46 ;
}
}
F_83 ( & V_149 -> V_150 , & V_212 ,
V_2 -> V_39 . V_40 , & V_2 -> V_64 ,
V_78 ,
V_141 ,
sizeof( struct V_8 ) ,
V_2 -> V_34 , & V_2 -> V_208 ) ;
F_82 ( & V_2 -> V_208 ) ;
return 0 ;
}
static int F_84 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_67 -> V_207 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( ! F_85 ( & V_2 -> V_210 ) ) {
F_86 ( & V_2 -> V_208 ) ;
V_2 -> V_54 = V_211 ;
F_7 ( V_2 , V_62 , 0 , 0x101 ) ;
F_81 ( V_2 -> V_39 . V_40 ) ;
F_82 ( & V_2 -> V_208 ) ;
}
V_67 -> V_207 = NULL ;
F_87 ( V_149 ) ;
return 0 ;
}
static int F_88 ( struct V_67 * V_67 , struct V_213 * V_214 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_67 -> V_207 ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( F_77 ( & V_2 -> V_208 ) )
return - V_209 ;
V_46 = F_89 ( & V_149 -> V_150 , V_214 ) ;
F_82 ( & V_2 -> V_208 ) ;
return V_46 ;
}
static unsigned int F_90 ( struct V_67 * V_67 , T_5 * V_215 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_67 -> V_207 ;
unsigned int V_216 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
F_86 ( & V_2 -> V_208 ) ;
V_216 = F_91 ( V_67 , & V_149 -> V_150 , V_215 ) ;
F_82 ( & V_2 -> V_208 ) ;
return V_216 ;
}
static int F_92 ( struct V_217 * V_218 )
{
struct V_197 * V_219 = V_218 -> V_40 . V_220 ;
struct V_92 * V_93 ;
struct V_44 * V_12 ;
struct V_221 * V_222 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_223 * V_224 , * V_225 ;
struct V_226 * V_227 ;
int V_182 , V_46 ;
V_224 = F_93 ( V_218 , V_228 , 0 ) ;
V_182 = F_94 ( V_218 , 0 ) ;
if ( ! V_219 || ! V_224 || V_182 <= 0 ) {
F_95 ( & V_218 -> V_40 , L_23 ) ;
return - V_229 ;
}
V_2 = F_76 ( sizeof( * V_2 ) , V_205 ) ;
if ( ! V_2 )
return - V_206 ;
F_96 ( & V_2 -> V_53 ) ;
F_97 ( & V_2 -> V_64 ) ;
F_98 ( & V_2 -> V_208 ) ;
F_99 ( & V_2 -> V_210 , 0 ) ;
V_2 -> V_168 = V_219 ;
V_2 -> V_54 = V_211 ;
V_93 = & V_2 -> V_93 ;
V_12 = & V_2 -> V_12 ;
V_2 -> V_97 = V_230 ;
V_93 -> V_101 = 0 ;
V_93 -> V_99 = 0 ;
V_93 -> V_16 = V_100 ;
V_93 -> V_17 = 480 ;
V_12 -> V_16 = V_100 ;
V_12 -> V_17 = 480 ;
V_12 -> V_13 = V_231 ;
V_12 -> V_43 = V_141 ;
V_12 -> V_232 = V_100 * 2 ;
V_12 -> V_233 = V_100 * 2 * 480 ;
V_12 -> V_138 = V_139 ;
V_225 = F_100 ( V_224 -> V_234 , F_101 ( V_224 ) ,
V_218 -> V_235 ) ;
if ( ! V_225 ) {
F_95 ( & V_218 -> V_40 , L_24 ) ;
V_46 = - V_236 ;
goto V_237;
}
V_2 -> V_5 = F_102 ( V_224 -> V_234 , F_101 ( V_224 ) ) ;
if ( ! V_2 -> V_5 ) {
V_46 = - V_206 ;
goto V_238;
}
V_46 = F_103 ( V_182 , F_65 , 0 , L_25 , V_2 ) ;
if ( V_46 < 0 )
goto V_239;
V_46 = F_104 ( & V_218 -> V_40 , & V_2 -> V_39 ) ;
if ( V_46 < 0 ) {
F_95 ( & V_218 -> V_40 , L_26 ) ;
goto V_240;
}
V_34 = F_105 () ;
if ( V_34 == NULL ) {
V_46 = - V_206 ;
goto V_241;
}
* V_34 = V_242 ;
if ( V_219 -> V_160 == V_161 )
V_34 -> V_165 |= V_243 ;
V_34 -> V_39 = & V_2 -> V_39 ;
V_34 -> V_244 = V_245 ;
V_34 -> V_64 = & V_2 -> V_208 ;
V_2 -> V_34 = V_34 ;
F_106 ( V_34 , V_2 ) ;
F_107 ( & V_218 -> V_40 ) ;
F_108 ( & V_218 -> V_40 ) ;
V_222 = F_109 ( V_219 -> V_222 ) ;
if ( ! V_222 ) {
V_46 = - V_229 ;
goto V_246;
}
V_46 = F_73 ( V_2 ) ;
if ( V_46 < 0 )
goto V_247;
V_227 = F_110 ( & V_2 -> V_39 , V_222 ,
V_219 -> V_248 , NULL ) ;
if ( ! V_227 ) {
V_46 = - V_206 ;
goto V_249;
}
V_46 = F_111 ( V_34 , V_250 , - 1 ) ;
if ( V_46 < 0 )
goto V_251;
return 0 ;
V_251:
V_249:
V_247:
F_112 ( V_222 ) ;
V_246:
V_245 ( V_34 ) ;
F_113 ( & V_218 -> V_40 ) ;
V_241:
F_114 ( & V_2 -> V_39 ) ;
V_240:
F_115 ( V_182 , V_2 ) ;
V_239:
F_116 ( V_2 -> V_5 ) ;
V_238:
F_117 ( V_224 -> V_234 , F_101 ( V_224 ) ) ;
V_237:
F_87 ( V_2 ) ;
return V_46 ;
}
static int F_118 ( struct V_217 * V_218 )
{
int V_182 = F_94 ( V_218 , 0 ) ;
struct V_252 * V_39 = F_119 ( V_218 ) ;
struct V_1 * V_2 = F_120 ( V_39 ,
struct V_1 , V_39 ) ;
struct V_226 * V_253 = F_72 ( V_39 -> V_254 . V_59 ,
struct V_226 , V_255 ) ;
struct V_256 * V_257 = F_121 ( V_253 ) ;
struct V_223 * V_224 ;
if ( V_182 > 0 )
F_115 ( V_182 , V_2 ) ;
F_113 ( & V_218 -> V_40 ) ;
F_122 ( V_2 -> V_34 ) ;
F_112 ( V_257 -> V_258 ) ;
F_114 ( & V_2 -> V_39 ) ;
F_116 ( V_2 -> V_5 ) ;
V_224 = F_93 ( V_218 , V_228 , 0 ) ;
if ( V_224 )
F_117 ( V_224 -> V_234 , F_101 ( V_224 ) ) ;
F_87 ( V_2 ) ;
return 0 ;
}
