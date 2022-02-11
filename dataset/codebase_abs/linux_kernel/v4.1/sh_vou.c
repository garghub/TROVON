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
V_70 -> V_75 = V_70 -> V_72 | V_76 ;
return 0 ;
}
static int F_35 ( struct V_67 * V_67 , void * V_68 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
if ( V_78 -> V_79 >= F_36 ( V_36 ) )
return - V_49 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_78 -> type = V_80 ;
F_34 ( V_78 -> V_81 , V_36 [ V_78 -> V_79 ] . V_82 ,
sizeof( V_78 -> V_81 ) ) ;
V_78 -> V_13 = V_36 [ V_78 -> V_79 ] . V_83 ;
return 0 ;
}
static int F_37 ( struct V_67 * V_67 , void * V_68 ,
struct V_84 * V_78 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_78 -> type = V_80 ;
V_78 -> V_78 . V_12 = V_2 -> V_12 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
int V_37 , int V_85 , int V_86 )
{
struct V_87 * V_78 = V_36 + V_37 ;
unsigned int V_88 , V_89 , V_90 ,
V_91 , V_92 , V_93 ;
struct V_94 * V_95 = & V_2 -> V_95 ;
struct V_44 * V_12 = & V_2 -> V_12 ;
T_1 V_96 = 0 , V_97 , V_98 ;
if ( V_2 -> V_99 & V_100 ) {
V_90 = 858 ;
} else {
V_90 = 864 ;
}
V_91 = V_12 -> V_17 / 2 ;
V_92 = V_95 -> V_17 / 2 ;
V_93 = V_95 -> V_101 / 2 ;
V_88 = V_90 - V_102 ;
V_89 = 20 ;
V_97 = V_95 -> V_16 + V_95 -> V_103 ;
V_98 = V_92 + V_93 ;
F_22 ( V_2 -> V_39 . V_40 ,
L_9 ,
V_12 -> V_16 , V_91 , V_88 , V_89 ,
V_95 -> V_103 , V_93 , V_97 , V_98 ) ;
F_3 ( V_2 , V_104 , ( V_12 -> V_16 << 16 ) | V_91 ) ;
F_3 ( V_2 , V_105 , ( V_88 << 16 ) | V_89 ) ;
F_3 ( V_2 , V_106 , ( V_95 -> V_103 << 16 ) | V_93 ) ;
F_3 ( V_2 , V_107 , ( V_97 << 16 ) | V_98 ) ;
if ( V_85 )
V_96 |= ( 1 << 15 ) | ( V_108 [ V_85 - 1 ] << 4 ) ;
if ( V_86 )
V_96 |= ( 1 << 14 ) | V_109 [ V_86 - 1 ] ;
F_22 ( V_2 -> V_39 . V_40 , L_10 , V_78 -> V_82 , V_96 ) ;
F_3 ( V_2 , V_110 , V_96 ) ;
F_3 ( V_2 , V_111 ,
V_78 -> V_112 | ( V_78 -> V_113 << 8 ) | ( V_78 -> V_114 << 16 ) ) ;
}
static void F_39 ( struct V_115 * V_116 , T_3 V_99 )
{
unsigned int V_117 = V_118 , V_119 = 0 , V_120 ;
int V_121 , V_122 = 0 ;
if ( V_99 & V_100 )
V_120 = 480 ;
else
V_120 = 576 ;
F_40 ( & V_116 -> V_123 , 0 , V_102 , 2 ,
& V_116 -> V_124 , 0 , V_120 , 1 , 0 ) ;
for ( V_121 = F_36 ( V_125 ) - 1 ; V_121 >= 0 ; V_121 -- ) {
unsigned int V_126 ;
unsigned int V_127 = V_116 -> V_128 . V_16 * V_129 [ V_121 ] /
V_125 [ V_121 ] ;
if ( V_127 > V_102 )
break;
V_126 = abs ( V_127 - V_116 -> V_123 ) ;
if ( V_126 < V_117 ) {
V_117 = V_126 ;
V_122 = V_121 ;
V_119 = V_127 ;
}
if ( ! V_126 )
break;
}
V_116 -> V_123 = V_119 ;
V_116 -> V_130 = V_122 ;
V_117 = V_118 ;
for ( V_121 = F_36 ( V_131 ) - 1 ; V_121 >= 0 ; V_121 -- ) {
unsigned int V_126 ;
unsigned int V_127 = V_116 -> V_128 . V_17 * V_132 [ V_121 ] /
V_131 [ V_121 ] ;
if ( V_127 > V_120 )
break;
V_126 = abs ( V_127 - V_116 -> V_124 ) ;
if ( V_126 < V_117 ) {
V_117 = V_126 ;
V_122 = V_121 ;
V_119 = V_127 ;
}
if ( ! V_126 )
break;
}
V_116 -> V_124 = V_119 ;
V_116 -> V_133 = V_122 ;
}
static void F_41 ( struct V_115 * V_116 , T_3 V_99 )
{
unsigned int V_117 = V_118 , V_119 = V_116 -> V_123 ,
V_90 , V_134 , V_120 ;
int V_121 , V_122 = 0 ;
if ( V_99 & V_100 ) {
V_90 = 858 ;
V_134 = 262 * 2 ;
V_120 = 480 ;
} else {
V_90 = 864 ;
V_134 = 312 * 2 ;
V_120 = 576 ;
}
for ( V_121 = 0 ; V_121 < F_36 ( V_125 ) ; V_121 ++ ) {
unsigned int V_126 ;
unsigned int V_127 = V_116 -> V_123 * V_125 [ V_121 ] /
V_129 [ V_121 ] ;
if ( V_127 > V_102 )
break;
V_126 = abs ( V_127 - V_116 -> V_128 . V_16 ) ;
if ( V_126 < V_117 ) {
V_117 = V_126 ;
V_122 = V_121 ;
V_119 = V_127 ;
}
if ( ! V_126 )
break;
}
V_116 -> V_128 . V_16 = V_119 ;
V_116 -> V_130 = V_122 ;
if ( V_116 -> V_128 . V_103 + V_119 > V_90 )
V_116 -> V_128 . V_103 = V_90 - V_119 ;
F_42 ( L_11 , V_41 , V_116 -> V_123 ,
V_125 [ V_122 ] , V_129 [ V_122 ] , V_119 ) ;
V_117 = V_118 ;
for ( V_121 = 0 ; V_121 < F_36 ( V_131 ) ; V_121 ++ ) {
unsigned int V_126 ;
unsigned int V_127 = V_116 -> V_124 * V_131 [ V_121 ] /
V_132 [ V_121 ] ;
if ( V_127 > V_120 )
break;
V_126 = abs ( V_127 - V_116 -> V_128 . V_17 ) ;
if ( V_126 < V_117 ) {
V_117 = V_126 ;
V_122 = V_121 ;
V_119 = V_127 ;
}
if ( ! V_126 )
break;
}
V_116 -> V_128 . V_17 = V_119 ;
V_116 -> V_133 = V_122 ;
if ( V_116 -> V_128 . V_101 + V_119 > V_134 )
V_116 -> V_128 . V_101 = V_134 - V_119 ;
F_42 ( L_12 , V_41 , V_116 -> V_124 ,
V_131 [ V_122 ] , V_132 [ V_122 ] , V_119 ) ;
}
static int F_43 ( struct V_67 * V_67 , void * V_68 ,
struct V_84 * V_78 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_44 * V_12 = & V_78 -> V_78 . V_12 ;
unsigned int V_120 ;
int V_37 ;
struct V_115 V_116 ;
struct V_135 V_136 = {
. V_137 = V_138 ,
. V_43 = V_139 ,
. V_140 = V_141 ,
} ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_13 , V_41 ,
V_2 -> V_95 . V_16 , V_2 -> V_95 . V_17 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
if ( V_12 -> V_43 == V_142 )
V_12 -> V_43 = V_143 ;
if ( V_78 -> type != V_80 ||
V_12 -> V_43 != V_143 )
return - V_49 ;
for ( V_37 = 0 ; V_37 < F_36 ( V_36 ) ; V_37 ++ )
if ( V_36 [ V_37 ] . V_83 == V_12 -> V_13 )
break;
if ( V_37 == F_36 ( V_36 ) )
return - V_49 ;
if ( V_2 -> V_99 & V_100 )
V_120 = 480 ;
else
V_120 = 576 ;
F_40 ( & V_12 -> V_16 , 0 , V_102 , 2 ,
& V_12 -> V_17 , 0 , V_120 , 1 , 0 ) ;
V_116 . V_123 = V_12 -> V_16 ;
V_116 . V_124 = V_12 -> V_17 ;
V_116 . V_128 = V_2 -> V_95 ;
F_41 ( & V_116 , V_2 -> V_99 ) ;
V_136 . V_16 = V_116 . V_128 . V_16 ;
V_136 . V_17 = V_116 . V_128 . V_17 ;
V_46 = F_44 ( & V_2 -> V_39 , 0 , V_144 ,
V_145 , & V_136 ) ;
if ( V_46 < 0 )
return V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_13 , V_41 ,
V_116 . V_128 . V_16 , V_116 . V_128 . V_17 , V_136 . V_16 , V_136 . V_17 ) ;
if ( ( unsigned ) V_136 . V_16 > V_102 ||
( unsigned ) V_136 . V_17 > V_120 ||
V_136 . V_137 != V_138 )
return - V_146 ;
if ( V_136 . V_16 != V_116 . V_128 . V_16 ||
V_136 . V_17 != V_116 . V_128 . V_17 ) {
V_116 . V_128 . V_16 = V_136 . V_16 ;
V_116 . V_128 . V_17 = V_136 . V_17 ;
F_39 ( & V_116 , V_2 -> V_99 ) ;
}
V_2 -> V_95 = V_116 . V_128 ;
V_12 -> V_16 = V_116 . V_123 ;
V_12 -> V_17 = V_116 . V_124 ;
F_22 ( V_2 -> V_39 . V_40 , L_14 , V_41 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_12 = * V_12 ;
F_38 ( V_2 , V_37 ,
V_116 . V_130 , V_116 . V_133 ) ;
return 0 ;
}
static int F_45 ( struct V_67 * V_67 , void * V_68 ,
struct V_84 * V_78 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_44 * V_12 = & V_78 -> V_78 . V_12 ;
int V_121 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_78 -> type = V_80 ;
V_12 -> V_43 = V_143 ;
F_40 ( & V_12 -> V_16 , 0 , V_102 , 1 ,
& V_12 -> V_17 , 0 , V_147 , 1 , 0 ) ;
for ( V_121 = 0 ; V_121 < F_36 ( V_36 ) ; V_121 ++ )
if ( V_36 [ V_121 ] . V_83 == V_12 -> V_13 )
return 0 ;
V_12 -> V_13 = V_36 [ 0 ] . V_83 ;
return 0 ;
}
static int F_46 ( struct V_67 * V_67 , void * V_68 ,
struct V_148 * V_149 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( V_149 -> type != V_80 )
return - V_49 ;
return F_47 ( & V_151 -> V_152 , V_149 ) ;
}
static int F_48 ( struct V_67 * V_67 , void * V_68 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
return F_49 ( & V_151 -> V_152 , V_154 ) ;
}
static int F_50 ( struct V_67 * V_67 , void * V_68 , struct V_153 * V_154 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
return F_51 ( & V_151 -> V_152 , V_154 ) ;
}
static int F_52 ( struct V_67 * V_67 , void * V_68 , struct V_153 * V_154 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
return F_53 ( & V_151 -> V_152 , V_154 , V_67 -> V_155 & V_156 ) ;
}
static int F_54 ( struct V_67 * V_67 , void * V_68 ,
enum V_157 V_158 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = V_68 ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_46 = F_44 ( & V_2 -> V_39 , 0 ,
V_144 , V_159 , 1 ) ;
if ( V_46 < 0 && V_46 != - V_160 )
return V_46 ;
return F_55 ( & V_151 -> V_152 ) ;
}
static int F_56 ( struct V_67 * V_67 , void * V_68 ,
enum V_157 V_158 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = V_68 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
F_57 ( & V_151 -> V_152 ) ;
F_44 ( & V_2 -> V_39 , 0 , V_144 , V_159 , 0 ) ;
return 0 ;
}
static T_1 F_58 ( enum V_161 V_162 )
{
switch ( V_162 ) {
default:
F_59 ( L_15 ,
V_41 , V_162 ) ;
case V_163 :
return 1 ;
case V_164 :
return 0 ;
case V_165 :
return 3 ;
}
}
static int F_60 ( struct V_67 * V_67 , void * V_68 , T_3 V_166 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_16 , V_41 , V_166 ) ;
if ( V_166 & ~ V_2 -> V_34 . V_167 )
return - V_49 ;
V_46 = F_44 ( & V_2 -> V_39 , 0 , V_144 ,
V_168 , V_166 ) ;
if ( V_46 < 0 && V_46 != - V_160 )
return V_46 ;
if ( V_166 & V_100 )
F_9 ( V_2 , V_169 ,
F_58 ( V_2 -> V_170 -> V_162 ) << 29 , 7 << 29 ) ;
else
F_9 ( V_2 , V_169 , 5 << 29 , 7 << 29 ) ;
V_2 -> V_99 = V_166 ;
return 0 ;
}
static int F_61 ( struct V_67 * V_67 , void * V_68 , T_3 * V_99 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
* V_99 = V_2 -> V_99 ;
return 0 ;
}
static int F_62 ( struct V_67 * V_67 , void * V_171 , struct V_172 * V_173 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_173 -> type = V_80 ;
V_173 -> V_174 = V_2 -> V_95 ;
return 0 ;
}
static int F_63 ( struct V_67 * V_67 , void * V_171 , const struct V_172 * V_173 )
{
struct V_172 V_175 = * V_173 ;
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_94 * V_95 = & V_175 . V_174 ;
struct V_172 V_176 = { . type = V_80 } ;
struct V_44 * V_12 = & V_2 -> V_12 ;
struct V_115 V_116 ;
struct V_135 V_136 = {
. V_137 = V_138 ,
. V_43 = V_139 ,
. V_140 = V_141 ,
} ;
unsigned int V_120 ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_17 , V_41 ,
V_95 -> V_16 , V_95 -> V_17 , V_95 -> V_103 , V_95 -> V_101 ) ;
if ( V_173 -> type != V_80 )
return - V_49 ;
if ( V_2 -> V_99 & V_100 )
V_120 = 480 ;
else
V_120 = 576 ;
F_40 ( & V_95 -> V_16 , 0 , V_102 , 1 ,
& V_95 -> V_17 , 0 , V_120 , 1 , 0 ) ;
if ( V_95 -> V_16 + V_95 -> V_103 > V_102 )
V_95 -> V_103 = V_102 - V_95 -> V_16 ;
if ( V_95 -> V_17 + V_95 -> V_101 > V_120 )
V_95 -> V_101 = V_120 - V_95 -> V_17 ;
V_116 . V_128 = * V_95 ;
V_116 . V_123 = V_12 -> V_16 ;
V_116 . V_124 = V_12 -> V_17 ;
V_176 . V_174 . V_16 = V_116 . V_128 . V_16 ;
V_176 . V_174 . V_17 = V_116 . V_128 . V_17 ;
F_44 ( & V_2 -> V_39 , 0 , V_144 ,
V_177 , & V_176 ) ;
V_136 . V_16 = V_116 . V_128 . V_16 ;
V_136 . V_17 = V_116 . V_128 . V_17 ;
V_46 = F_44 ( & V_2 -> V_39 , 0 , V_144 ,
V_145 , & V_136 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( ( unsigned ) V_136 . V_16 > V_102 ||
( unsigned ) V_136 . V_17 > V_120 ||
V_136 . V_137 != V_138 )
return - V_146 ;
V_116 . V_128 . V_16 = V_136 . V_16 ;
V_116 . V_128 . V_17 = V_136 . V_17 ;
F_39 ( & V_116 , V_2 -> V_99 ) ;
V_2 -> V_95 = V_116 . V_128 ;
V_12 -> V_16 = V_116 . V_123 ;
V_12 -> V_17 = V_116 . V_124 ;
F_38 ( V_2 , V_2 -> V_37 ,
V_116 . V_130 , V_116 . V_133 ) ;
return 0 ;
}
static int F_64 ( struct V_67 * V_67 , void * V_68 ,
struct V_178 * V_173 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_173 -> type = V_80 ;
V_173 -> V_179 . V_103 = 0 ;
V_173 -> V_179 . V_101 = 0 ;
V_173 -> V_179 . V_16 = V_102 ;
V_173 -> V_179 . V_17 = V_147 ;
V_173 -> V_180 . V_103 = 0 ;
V_173 -> V_180 . V_101 = 0 ;
V_173 -> V_180 . V_16 = V_102 ;
V_173 -> V_180 . V_17 = V_147 ;
V_173 -> V_181 . V_182 = 1 ;
V_173 -> V_181 . V_183 = 1 ;
return 0 ;
}
static T_4 F_65 ( int V_184 , void * V_185 )
{
struct V_1 * V_2 = V_185 ;
static unsigned long V_186 ;
struct V_8 * V_9 ;
static int V_187 ;
T_1 V_188 = F_5 ( V_2 , V_61 ) , V_189 ;
T_1 V_190 = F_5 ( V_2 , V_58 ) ;
if ( ! ( V_188 & 0x300 ) ) {
if ( F_66 ( & V_186 , 500 ) )
F_24 ( V_2 -> V_39 . V_40 , L_18 ,
V_188 ) ;
return V_191 ;
}
F_67 ( & V_2 -> V_64 ) ;
if ( ! V_2 -> V_56 || F_68 ( & V_2 -> V_53 ) ) {
if ( F_66 ( & V_186 , 500 ) )
F_24 ( V_2 -> V_39 . V_40 ,
L_19 , V_188 ) ;
F_7 ( V_2 , V_61 , 0 , 0x300 ) ;
F_69 ( & V_2 -> V_64 ) ;
return V_192 ;
}
V_189 = ~ ( 0x300 & V_188 ) & V_188 & 0x30304 ;
F_22 ( V_2 -> V_39 . V_40 ,
L_20 ,
V_188 , V_189 , V_190 , V_187 ) ;
V_187 ++ ;
F_1 ( V_2 , V_61 , V_189 ) ;
V_9 = V_2 -> V_56 ;
F_30 ( & V_9 -> V_53 ) ;
V_9 -> V_29 = V_193 ;
F_70 ( & V_9 -> V_194 ) ;
V_9 -> V_195 ++ ;
F_71 ( & V_9 -> V_196 ) ;
if ( F_68 ( & V_2 -> V_53 ) ) {
F_22 ( V_2 -> V_39 . V_40 , L_21 ,
V_41 , V_187 ) ;
F_7 ( V_2 , V_62 , 0 , 1 ) ;
V_2 -> V_56 = NULL ;
V_2 -> V_54 = V_197 ;
F_7 ( V_2 , V_61 , 0 , 0x30000 ) ;
F_69 ( & V_2 -> V_64 ) ;
return V_192 ;
}
V_2 -> V_56 = F_72 ( V_2 -> V_53 . V_59 ,
struct V_8 , V_53 ) ;
if ( V_2 -> V_56 -> V_53 . V_59 != & V_2 -> V_53 ) {
struct V_8 * V_198 = F_72 ( V_2 -> V_56 -> V_53 . V_59 ,
struct V_8 , V_53 ) ;
F_10 ( V_2 , V_198 ) ;
}
F_69 ( & V_2 -> V_64 ) ;
return V_192 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_199 * V_170 = V_2 -> V_170 ;
T_1 V_200 = F_58 ( V_170 -> V_162 ) << 29 ;
int V_121 = 100 ;
F_1 ( V_2 , V_61 , 0 ) ;
F_1 ( V_2 , V_201 , 0x101 ) ;
while ( -- V_121 && ( F_5 ( V_2 , V_201 ) & 0x101 ) )
F_74 ( 1 ) ;
if ( ! V_121 )
return - V_202 ;
F_22 ( V_2 -> V_39 . V_40 , L_22 , 100 - V_121 ) ;
if ( V_170 -> V_63 & V_203 )
V_200 |= 1 << 28 ;
if ( V_170 -> V_63 & V_204 )
V_200 |= 1 << 27 ;
if ( V_170 -> V_63 & V_205 )
V_200 |= 1 << 26 ;
F_9 ( V_2 , V_169 , V_200 , 0xfc000000 ) ;
F_1 ( V_2 , V_60 , 4 ) ;
F_3 ( V_2 , V_206 , 0x800000 ) ;
return 0 ;
}
static int F_75 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = F_76 ( sizeof( struct V_150 ) ,
V_207 ) ;
if ( ! V_151 )
return - V_208 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( F_77 ( & V_2 -> V_209 ) ) {
F_78 ( V_151 ) ;
return - V_210 ;
}
if ( F_79 ( & V_2 -> V_211 ) == 1 ) {
int V_46 ;
V_2 -> V_54 = V_197 ;
F_80 ( V_2 -> V_39 . V_40 ) ;
V_46 = F_73 ( V_2 ) ;
if ( V_46 < 0 ) {
F_81 ( & V_2 -> V_211 ) ;
F_82 ( V_2 -> V_39 . V_40 ) ;
V_2 -> V_54 = V_212 ;
F_83 ( & V_2 -> V_209 ) ;
F_78 ( V_151 ) ;
return V_46 ;
}
}
F_84 ( & V_151 -> V_152 , & V_213 ,
V_2 -> V_39 . V_40 , & V_2 -> V_64 ,
V_80 ,
V_143 ,
sizeof( struct V_8 ) ,
& V_2 -> V_34 , & V_2 -> V_209 ) ;
F_83 ( & V_2 -> V_209 ) ;
V_67 -> V_214 = V_151 ;
return 0 ;
}
static int F_85 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = V_67 -> V_214 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( ! F_86 ( & V_2 -> V_211 ) ) {
F_87 ( & V_2 -> V_209 ) ;
V_2 -> V_54 = V_212 ;
F_7 ( V_2 , V_62 , 0 , 0x101 ) ;
F_82 ( V_2 -> V_39 . V_40 ) ;
F_83 ( & V_2 -> V_209 ) ;
}
V_67 -> V_214 = NULL ;
F_78 ( V_151 ) ;
return 0 ;
}
static int F_88 ( struct V_67 * V_67 , struct V_215 * V_216 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = V_67 -> V_214 ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( F_77 ( & V_2 -> V_209 ) )
return - V_210 ;
V_46 = F_89 ( & V_151 -> V_152 , V_216 ) ;
F_83 ( & V_2 -> V_209 ) ;
return V_46 ;
}
static unsigned int F_90 ( struct V_67 * V_67 , T_5 * V_217 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_150 * V_151 = V_67 -> V_214 ;
unsigned int V_218 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
F_87 ( & V_2 -> V_209 ) ;
V_218 = F_91 ( V_67 , & V_151 -> V_152 , V_217 ) ;
F_83 ( & V_2 -> V_209 ) ;
return V_218 ;
}
static int F_92 ( struct V_219 * V_220 )
{
struct V_199 * V_221 = V_220 -> V_40 . V_222 ;
struct V_94 * V_95 ;
struct V_44 * V_12 ;
struct V_223 * V_224 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_225 * V_226 , * V_227 ;
struct V_228 * V_229 ;
int V_184 , V_46 ;
V_226 = F_93 ( V_220 , V_230 , 0 ) ;
V_184 = F_94 ( V_220 , 0 ) ;
if ( ! V_221 || ! V_226 || V_184 <= 0 ) {
F_95 ( & V_220 -> V_40 , L_23 ) ;
return - V_231 ;
}
V_2 = F_76 ( sizeof( * V_2 ) , V_207 ) ;
if ( ! V_2 )
return - V_208 ;
F_96 ( & V_2 -> V_53 ) ;
F_97 ( & V_2 -> V_64 ) ;
F_98 ( & V_2 -> V_209 ) ;
F_99 ( & V_2 -> V_211 , 0 ) ;
V_2 -> V_170 = V_221 ;
V_2 -> V_54 = V_212 ;
V_95 = & V_2 -> V_95 ;
V_12 = & V_2 -> V_12 ;
V_2 -> V_99 = V_232 ;
V_95 -> V_103 = 0 ;
V_95 -> V_101 = 0 ;
V_95 -> V_16 = V_102 ;
V_95 -> V_17 = 480 ;
V_12 -> V_16 = V_102 ;
V_12 -> V_17 = 480 ;
V_12 -> V_13 = V_233 ;
V_12 -> V_43 = V_143 ;
V_12 -> V_234 = V_102 * 2 ;
V_12 -> V_235 = V_102 * 2 * 480 ;
V_12 -> V_140 = V_141 ;
V_227 = F_100 ( V_226 -> V_236 , F_101 ( V_226 ) ,
V_220 -> V_237 ) ;
if ( ! V_227 ) {
F_95 ( & V_220 -> V_40 , L_24 ) ;
V_46 = - V_238 ;
goto V_239;
}
V_2 -> V_5 = F_102 ( V_226 -> V_236 , F_101 ( V_226 ) ) ;
if ( ! V_2 -> V_5 ) {
V_46 = - V_208 ;
goto V_240;
}
V_46 = F_103 ( V_184 , F_65 , 0 , L_25 , V_2 ) ;
if ( V_46 < 0 )
goto V_241;
V_46 = F_104 ( & V_220 -> V_40 , & V_2 -> V_39 ) ;
if ( V_46 < 0 ) {
F_95 ( & V_220 -> V_40 , L_26 ) ;
goto V_242;
}
V_34 = & V_2 -> V_34 ;
* V_34 = V_243 ;
if ( V_221 -> V_162 == V_163 )
V_34 -> V_167 |= V_244 ;
V_34 -> V_39 = & V_2 -> V_39 ;
V_34 -> V_245 = V_246 ;
V_34 -> V_64 = & V_2 -> V_209 ;
F_105 ( V_34 , V_2 ) ;
F_106 ( & V_220 -> V_40 ) ;
F_107 ( & V_220 -> V_40 ) ;
V_224 = F_108 ( V_221 -> V_224 ) ;
if ( ! V_224 ) {
V_46 = - V_231 ;
goto V_247;
}
V_46 = F_73 ( V_2 ) ;
if ( V_46 < 0 )
goto V_248;
V_229 = F_109 ( & V_2 -> V_39 , V_224 ,
V_221 -> V_249 , NULL ) ;
if ( ! V_229 ) {
V_46 = - V_208 ;
goto V_250;
}
V_46 = F_110 ( V_34 , V_251 , - 1 ) ;
if ( V_46 < 0 )
goto V_252;
return 0 ;
V_252:
V_250:
V_248:
F_111 ( V_224 ) ;
V_247:
F_112 ( & V_220 -> V_40 ) ;
F_113 ( & V_2 -> V_39 ) ;
V_242:
F_114 ( V_184 , V_2 ) ;
V_241:
F_115 ( V_2 -> V_5 ) ;
V_240:
F_116 ( V_226 -> V_236 , F_101 ( V_226 ) ) ;
V_239:
F_78 ( V_2 ) ;
return V_46 ;
}
static int F_117 ( struct V_219 * V_220 )
{
int V_184 = F_94 ( V_220 , 0 ) ;
struct V_253 * V_39 = F_118 ( V_220 ) ;
struct V_1 * V_2 = F_119 ( V_39 ,
struct V_1 , V_39 ) ;
struct V_228 * V_254 = F_72 ( V_39 -> V_255 . V_59 ,
struct V_228 , V_256 ) ;
struct V_257 * V_258 = F_120 ( V_254 ) ;
struct V_225 * V_226 ;
if ( V_184 > 0 )
F_114 ( V_184 , V_2 ) ;
F_112 ( & V_220 -> V_40 ) ;
F_121 ( & V_2 -> V_34 ) ;
F_111 ( V_258 -> V_259 ) ;
F_113 ( & V_2 -> V_39 ) ;
F_115 ( V_2 -> V_5 ) ;
V_226 = F_93 ( V_220 , V_230 , 0 ) ;
if ( V_226 )
F_116 ( V_226 -> V_236 , F_101 ( V_226 ) ) ;
F_78 ( V_2 ) ;
return 0 ;
}
