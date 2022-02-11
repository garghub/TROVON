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
F_22 ( V_28 -> V_39 , L_1 , V_40 , * V_31 , * V_32 ) ;
return 0 ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_8 * V_9 ,
enum V_41 V_42 )
{
struct V_33 * V_34 = V_28 -> V_35 ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_43 * V_12 = & V_2 -> V_12 ;
int V_44 = V_36 [ V_2 -> V_37 ] . V_38 * V_12 -> V_16 / 8 ;
int V_45 ;
F_22 ( V_28 -> V_39 , L_2 , V_40 ) ;
if ( V_9 -> V_16 != V_12 -> V_16 ||
V_9 -> V_17 != V_12 -> V_17 ||
V_9 -> V_42 != V_12 -> V_42 ) {
V_9 -> V_16 = V_12 -> V_16 ;
V_9 -> V_17 = V_12 -> V_17 ;
V_9 -> V_42 = V_42 ;
if ( V_9 -> V_29 != V_30 )
F_14 ( V_28 , V_9 ) ;
}
V_9 -> V_32 = V_9 -> V_17 * V_44 ;
if ( V_9 -> V_46 && V_9 -> V_47 < V_9 -> V_32 ) {
F_24 ( V_28 -> V_39 , L_3 ,
V_9 -> V_47 , V_9 -> V_46 ) ;
return - V_48 ;
}
if ( V_9 -> V_29 == V_30 ) {
V_45 = F_25 ( V_28 , V_9 , NULL ) ;
if ( V_45 < 0 ) {
F_24 ( V_28 -> V_39 , L_4 ,
V_9 -> V_49 , V_45 ) ;
return V_45 ;
}
V_9 -> V_29 = V_50 ;
}
F_22 ( V_28 -> V_39 ,
L_5 ,
V_40 , V_2 -> V_37 , V_44 ,
F_11 ( V_9 ) , V_9 -> V_49 , V_9 -> V_29 ) ;
return 0 ;
}
static void F_26 ( struct V_27 * V_28 ,
struct V_8 * V_9 )
{
struct V_33 * V_34 = V_28 -> V_35 ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
F_22 ( V_28 -> V_39 , L_2 , V_40 ) ;
V_9 -> V_29 = V_51 ;
F_27 ( & V_9 -> V_52 , & V_2 -> V_52 ) ;
if ( V_2 -> V_53 == V_54 ) {
return;
} else if ( ! V_2 -> V_55 ) {
V_2 -> V_55 = V_9 ;
F_1 ( V_2 , V_56 , 1 ) ;
F_22 ( V_28 -> V_39 , L_6 , V_40 ,
F_5 ( V_2 , V_57 ) ) ;
F_10 ( V_2 , V_9 ) ;
} else if ( V_2 -> V_55 -> V_52 . V_58 == & V_9 -> V_52 ) {
F_1 ( V_2 , V_56 , 0 ) ;
F_12 ( V_2 , V_9 ) ;
F_1 ( V_2 , V_59 , 5 ) ;
F_22 ( V_28 -> V_39 , L_7 , V_40 ,
F_5 ( V_2 , V_57 ) ) ;
F_1 ( V_2 , V_60 , 0x10004 ) ;
V_2 -> V_53 = V_54 ;
F_1 ( V_2 , V_61 , 0x107 ) ;
}
}
static void F_28 ( struct V_27 * V_28 ,
struct V_8 * V_9 )
{
struct V_33 * V_34 = V_28 -> V_35 ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
unsigned long V_62 ;
F_22 ( V_28 -> V_39 , L_2 , V_40 ) ;
F_29 ( & V_2 -> V_63 , V_62 ) ;
if ( V_2 -> V_55 == V_9 ) {
F_7 ( V_2 , V_61 , 0 , 1 ) ;
F_7 ( V_2 , V_60 , 0 , 0x30000 ) ;
V_2 -> V_55 = NULL ;
}
if ( ( V_9 -> V_29 == V_64 || V_9 -> V_29 == V_51 ) ) {
V_9 -> V_29 = V_65 ;
F_30 ( & V_9 -> V_52 ) ;
}
F_31 ( & V_2 -> V_63 , V_62 ) ;
F_14 ( V_28 , V_9 ) ;
}
static int F_32 ( struct V_66 * V_66 , void * V_67 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
F_33 ( V_69 -> V_73 , L_8 , sizeof( V_69 -> V_73 ) ) ;
V_69 -> V_74 = F_34 ( 0 , 1 , 0 ) ;
V_69 -> V_75 = V_76 | V_77 ;
return 0 ;
}
static int F_35 ( struct V_66 * V_66 , void * V_67 ,
struct V_78 * V_79 )
{
struct V_70 * V_71 = V_67 ;
if ( V_79 -> V_80 >= F_36 ( V_36 ) )
return - V_48 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
V_79 -> type = V_81 ;
F_33 ( V_79 -> V_82 , V_36 [ V_79 -> V_80 ] . V_83 ,
sizeof( V_79 -> V_82 ) ) ;
V_79 -> V_13 = V_36 [ V_79 -> V_80 ] . V_84 ;
return 0 ;
}
static int F_37 ( struct V_66 * V_66 , void * V_67 ,
struct V_85 * V_79 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
F_22 ( V_2 -> V_86 . V_39 , L_2 , V_40 ) ;
V_79 -> type = V_81 ;
V_79 -> V_79 . V_12 = V_2 -> V_12 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
int V_37 , int V_87 , int V_88 )
{
struct V_89 * V_79 = V_36 + V_37 ;
unsigned int V_90 , V_91 , V_92 , V_93 ,
V_94 , V_95 , V_96 ;
struct V_97 * V_98 = & V_2 -> V_98 ;
struct V_43 * V_12 = & V_2 -> V_12 ;
T_1 V_99 = 0 , V_100 , V_101 ;
if ( V_2 -> V_102 & V_103 ) {
V_92 = 858 ;
V_93 = 262 ;
} else {
V_92 = 864 ;
V_93 = 312 ;
}
V_94 = V_12 -> V_17 / 2 ;
V_95 = V_98 -> V_17 / 2 ;
V_96 = V_98 -> V_104 / 2 ;
V_90 = V_92 - V_105 ;
V_91 = 20 ;
V_100 = V_98 -> V_16 + V_98 -> V_106 ;
V_101 = V_95 + V_96 ;
F_22 ( V_2 -> V_86 . V_39 ,
L_9 ,
V_12 -> V_16 , V_94 , V_90 , V_91 ,
V_98 -> V_106 , V_96 , V_100 , V_101 ) ;
F_3 ( V_2 , V_107 , ( V_12 -> V_16 << 16 ) | V_94 ) ;
F_3 ( V_2 , V_108 , ( V_90 << 16 ) | V_91 ) ;
F_3 ( V_2 , V_109 , ( V_98 -> V_106 << 16 ) | V_96 ) ;
F_3 ( V_2 , V_110 , ( V_100 << 16 ) | V_101 ) ;
if ( V_87 )
V_99 |= ( 1 << 15 ) | ( V_111 [ V_87 - 1 ] << 4 ) ;
if ( V_88 )
V_99 |= ( 1 << 14 ) | V_112 [ V_88 - 1 ] ;
F_22 ( V_2 -> V_86 . V_39 , L_10 , V_79 -> V_83 , V_99 ) ;
F_3 ( V_2 , V_113 , V_99 ) ;
F_3 ( V_2 , V_114 ,
V_79 -> V_115 | ( V_79 -> V_116 << 8 ) | ( V_79 -> V_117 << 16 ) ) ;
}
static void F_40 ( struct V_118 * V_119 , T_3 V_102 )
{
unsigned int V_120 = V_121 , V_122 = 0 , V_123 ;
int V_124 , V_125 = 0 ;
if ( V_102 & V_103 )
V_123 = 480 ;
else
V_123 = 576 ;
F_41 ( & V_119 -> V_126 , 0 , V_105 , 2 ,
& V_119 -> V_127 , 0 , V_123 , 1 , 0 ) ;
for ( V_124 = F_36 ( V_128 ) - 1 ; V_124 >= 0 ; V_124 -- ) {
unsigned int V_129 ;
unsigned int V_130 = V_119 -> V_131 . V_16 * V_132 [ V_124 ] /
V_128 [ V_124 ] ;
if ( V_130 > V_105 )
break;
V_129 = abs ( V_130 - V_119 -> V_126 ) ;
if ( V_129 < V_120 ) {
V_120 = V_129 ;
V_125 = V_124 ;
V_122 = V_130 ;
}
if ( ! V_129 )
break;
}
V_119 -> V_126 = V_122 ;
V_119 -> V_133 = V_125 ;
V_120 = V_121 ;
for ( V_124 = F_36 ( V_134 ) - 1 ; V_124 >= 0 ; V_124 -- ) {
unsigned int V_129 ;
unsigned int V_130 = V_119 -> V_131 . V_17 * V_135 [ V_124 ] /
V_134 [ V_124 ] ;
if ( V_130 > V_123 )
break;
V_129 = abs ( V_130 - V_119 -> V_127 ) ;
if ( V_129 < V_120 ) {
V_120 = V_129 ;
V_125 = V_124 ;
V_122 = V_130 ;
}
if ( ! V_129 )
break;
}
V_119 -> V_127 = V_122 ;
V_119 -> V_136 = V_125 ;
}
static void F_42 ( struct V_118 * V_119 , T_3 V_102 )
{
unsigned int V_120 = V_121 , V_122 , V_92 , V_93 ,
V_123 ;
int V_124 , V_125 ;
if ( V_102 & V_103 ) {
V_92 = 858 ;
V_93 = 262 * 2 ;
V_123 = 480 ;
} else {
V_92 = 864 ;
V_93 = 312 * 2 ;
V_123 = 576 ;
}
for ( V_124 = 0 ; V_124 < F_36 ( V_128 ) ; V_124 ++ ) {
unsigned int V_129 ;
unsigned int V_130 = V_119 -> V_126 * V_128 [ V_124 ] /
V_132 [ V_124 ] ;
if ( V_130 > V_105 )
break;
V_129 = abs ( V_130 - V_119 -> V_131 . V_16 ) ;
if ( V_129 < V_120 ) {
V_120 = V_129 ;
V_125 = V_124 ;
V_122 = V_130 ;
}
if ( ! V_129 )
break;
}
V_119 -> V_131 . V_16 = V_122 ;
V_119 -> V_133 = V_125 ;
if ( V_119 -> V_131 . V_106 + V_122 > V_92 )
V_119 -> V_131 . V_106 = V_92 - V_122 ;
F_43 ( L_11 , V_40 , V_119 -> V_126 ,
V_128 [ V_125 ] , V_132 [ V_125 ] , V_122 ) ;
V_120 = V_121 ;
for ( V_124 = 0 ; V_124 < F_36 ( V_134 ) ; V_124 ++ ) {
unsigned int V_129 ;
unsigned int V_130 = V_119 -> V_127 * V_134 [ V_124 ] /
V_135 [ V_124 ] ;
if ( V_130 > V_123 )
break;
V_129 = abs ( V_130 - V_119 -> V_131 . V_17 ) ;
if ( V_129 < V_120 ) {
V_120 = V_129 ;
V_125 = V_124 ;
V_122 = V_130 ;
}
if ( ! V_129 )
break;
}
V_119 -> V_131 . V_17 = V_122 ;
V_119 -> V_136 = V_125 ;
if ( V_119 -> V_131 . V_104 + V_122 > V_93 )
V_119 -> V_131 . V_104 = V_93 - V_122 ;
F_43 ( L_12 , V_40 , V_119 -> V_127 ,
V_134 [ V_125 ] , V_135 [ V_125 ] , V_122 ) ;
}
static int F_44 ( struct V_66 * V_66 , void * V_67 ,
struct V_85 * V_79 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_43 * V_12 = & V_79 -> V_79 . V_12 ;
unsigned int V_123 ;
int V_37 ;
struct V_118 V_119 ;
struct V_137 V_138 = {
. V_139 = V_140 ,
. V_42 = V_141 ,
. V_142 = V_143 ,
} ;
int V_45 ;
F_22 ( V_2 -> V_86 . V_39 , L_13 , V_40 ,
V_2 -> V_98 . V_16 , V_2 -> V_98 . V_17 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
if ( V_12 -> V_42 == V_144 )
V_12 -> V_42 = V_145 ;
if ( V_79 -> type != V_81 ||
V_12 -> V_42 != V_145 )
return - V_48 ;
for ( V_37 = 0 ; V_37 < F_36 ( V_36 ) ; V_37 ++ )
if ( V_36 [ V_37 ] . V_84 == V_12 -> V_13 )
break;
if ( V_37 == F_36 ( V_36 ) )
return - V_48 ;
if ( V_2 -> V_102 & V_103 )
V_123 = 480 ;
else
V_123 = 576 ;
F_41 ( & V_12 -> V_16 , 0 , V_105 , 2 ,
& V_12 -> V_17 , 0 , V_123 , 1 , 0 ) ;
V_119 . V_126 = V_12 -> V_16 ;
V_119 . V_127 = V_12 -> V_17 ;
V_119 . V_131 = V_2 -> V_98 ;
F_42 ( & V_119 , V_2 -> V_102 ) ;
V_138 . V_16 = V_119 . V_131 . V_16 ;
V_138 . V_17 = V_119 . V_131 . V_17 ;
V_45 = F_45 ( & V_2 -> V_86 , 0 , V_146 ,
V_147 , & V_138 ) ;
if ( V_45 < 0 )
return V_45 ;
F_22 ( V_2 -> V_86 . V_39 , L_13 , V_40 ,
V_119 . V_131 . V_16 , V_119 . V_131 . V_17 , V_138 . V_16 , V_138 . V_17 ) ;
if ( ( unsigned ) V_138 . V_16 > V_105 ||
( unsigned ) V_138 . V_17 > V_123 ||
V_138 . V_139 != V_140 )
return - V_148 ;
if ( V_138 . V_16 != V_119 . V_131 . V_16 ||
V_138 . V_17 != V_119 . V_131 . V_17 ) {
V_119 . V_131 . V_16 = V_138 . V_16 ;
V_119 . V_131 . V_17 = V_138 . V_17 ;
F_40 ( & V_119 , V_2 -> V_102 ) ;
}
V_2 -> V_98 = V_119 . V_131 ;
V_12 -> V_16 = V_119 . V_126 ;
V_12 -> V_17 = V_119 . V_127 ;
F_22 ( V_2 -> V_86 . V_39 , L_14 , V_40 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_12 = * V_12 ;
F_39 ( V_2 , V_37 ,
V_119 . V_133 , V_119 . V_136 ) ;
return 0 ;
}
static int F_46 ( struct V_66 * V_66 , void * V_67 ,
struct V_85 * V_79 )
{
struct V_70 * V_71 = V_67 ;
struct V_43 * V_12 = & V_79 -> V_79 . V_12 ;
int V_124 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
V_79 -> type = V_81 ;
V_12 -> V_42 = V_145 ;
F_41 ( & V_12 -> V_16 , 0 , V_105 , 1 ,
& V_12 -> V_17 , 0 , V_149 , 1 , 0 ) ;
for ( V_124 = 0 ; F_36 ( V_36 ) ; V_124 ++ )
if ( V_36 [ V_124 ] . V_84 == V_12 -> V_13 )
return 0 ;
V_12 -> V_13 = V_36 [ 0 ] . V_84 ;
return 0 ;
}
static int F_47 ( struct V_66 * V_66 , void * V_67 ,
struct V_150 * V_151 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
if ( V_151 -> type != V_81 )
return - V_48 ;
return F_48 ( & V_71 -> V_72 , V_151 ) ;
}
static int F_49 ( struct V_66 * V_66 , void * V_67 ,
struct V_152 * V_153 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
return F_50 ( & V_71 -> V_72 , V_153 ) ;
}
static int F_51 ( struct V_66 * V_66 , void * V_67 , struct V_152 * V_153 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
return F_52 ( & V_71 -> V_72 , V_153 ) ;
}
static int F_53 ( struct V_66 * V_66 , void * V_67 , struct V_152 * V_153 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
return F_54 ( & V_71 -> V_72 , V_153 , V_66 -> V_154 & V_155 ) ;
}
static int F_55 ( struct V_66 * V_66 , void * V_67 ,
enum V_156 V_157 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = V_67 ;
int V_45 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
V_45 = F_45 ( & V_2 -> V_86 , 0 ,
V_146 , V_158 , 1 ) ;
if ( V_45 < 0 && V_45 != - V_159 )
return V_45 ;
return F_56 ( & V_71 -> V_72 ) ;
}
static int F_57 ( struct V_66 * V_66 , void * V_67 ,
enum V_156 V_157 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
F_58 ( & V_71 -> V_72 ) ;
F_45 ( & V_2 -> V_86 , 0 , V_146 , V_158 , 0 ) ;
return 0 ;
}
static T_1 F_59 ( enum V_160 V_161 )
{
switch ( V_161 ) {
default:
F_60 ( L_15 ,
V_40 , V_161 ) ;
case V_162 :
return 1 ;
case V_163 :
return 0 ;
case V_164 :
return 3 ;
}
}
static int F_61 ( struct V_66 * V_66 , void * V_67 , T_3 * V_165 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
int V_45 ;
F_22 ( V_2 -> V_86 . V_39 , L_16 , V_40 , * V_165 ) ;
if ( * V_165 & ~ V_34 -> V_166 )
return - V_48 ;
V_45 = F_45 ( & V_2 -> V_86 , 0 , V_146 ,
V_167 , * V_165 ) ;
if ( V_45 < 0 && V_45 != - V_159 )
return V_45 ;
if ( * V_165 & V_103 )
F_9 ( V_2 , V_168 ,
F_59 ( V_2 -> V_169 -> V_161 ) << 29 , 7 << 29 ) ;
else
F_9 ( V_2 , V_168 , 5 << 29 , 7 << 29 ) ;
V_2 -> V_102 = * V_165 ;
return 0 ;
}
static int F_62 ( struct V_66 * V_66 , void * V_67 , T_3 * V_102 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
F_22 ( V_2 -> V_86 . V_39 , L_2 , V_40 ) ;
* V_102 = V_2 -> V_102 ;
return 0 ;
}
static int F_63 ( struct V_66 * V_66 , void * V_170 , struct V_171 * V_172 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
F_22 ( V_2 -> V_86 . V_39 , L_2 , V_40 ) ;
V_172 -> type = V_81 ;
V_172 -> V_173 = V_2 -> V_98 ;
return 0 ;
}
static int F_64 ( struct V_66 * V_66 , void * V_170 , struct V_171 * V_172 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_97 * V_98 = & V_172 -> V_173 ;
struct V_171 V_174 = { . type = V_81 } ;
struct V_43 * V_12 = & V_2 -> V_12 ;
struct V_118 V_119 ;
struct V_137 V_138 = {
. V_139 = V_140 ,
. V_42 = V_141 ,
. V_142 = V_143 ,
} ;
unsigned int V_123 ;
int V_45 ;
F_22 ( V_2 -> V_86 . V_39 , L_17 , V_40 ,
V_98 -> V_16 , V_98 -> V_17 , V_98 -> V_106 , V_98 -> V_104 ) ;
if ( V_172 -> type != V_81 )
return - V_48 ;
if ( V_2 -> V_102 & V_103 )
V_123 = 480 ;
else
V_123 = 576 ;
F_41 ( & V_98 -> V_16 , 0 , V_105 , 1 ,
& V_98 -> V_17 , 0 , V_123 , 1 , 0 ) ;
if ( V_98 -> V_16 + V_98 -> V_106 > V_105 )
V_98 -> V_106 = V_105 - V_98 -> V_16 ;
if ( V_98 -> V_17 + V_98 -> V_104 > V_123 )
V_98 -> V_104 = V_123 - V_98 -> V_17 ;
V_119 . V_131 = * V_98 ;
V_119 . V_126 = V_12 -> V_16 ;
V_119 . V_127 = V_12 -> V_17 ;
V_174 . V_173 . V_16 = V_119 . V_131 . V_16 ;
V_174 . V_173 . V_17 = V_119 . V_131 . V_17 ;
F_45 ( & V_2 -> V_86 , 0 , V_146 ,
V_175 , & V_174 ) ;
V_138 . V_16 = V_119 . V_131 . V_16 ;
V_138 . V_17 = V_119 . V_131 . V_17 ;
V_45 = F_45 ( & V_2 -> V_86 , 0 , V_146 ,
V_147 , & V_138 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( ( unsigned ) V_138 . V_16 > V_105 ||
( unsigned ) V_138 . V_17 > V_123 ||
V_138 . V_139 != V_140 )
return - V_148 ;
V_119 . V_131 . V_16 = V_138 . V_16 ;
V_119 . V_131 . V_17 = V_138 . V_17 ;
F_40 ( & V_119 , V_2 -> V_102 ) ;
V_2 -> V_98 = V_119 . V_131 ;
V_12 -> V_16 = V_119 . V_126 ;
V_12 -> V_17 = V_119 . V_127 ;
F_39 ( V_2 , V_2 -> V_37 ,
V_119 . V_133 , V_119 . V_136 ) ;
return 0 ;
}
static int F_65 ( struct V_66 * V_66 , void * V_67 ,
struct V_176 * V_172 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
V_172 -> type = V_81 ;
V_172 -> V_177 . V_106 = 0 ;
V_172 -> V_177 . V_104 = 0 ;
V_172 -> V_177 . V_16 = V_105 ;
V_172 -> V_177 . V_17 = V_149 ;
V_172 -> V_178 . V_106 = 0 ;
V_172 -> V_178 . V_104 = 0 ;
V_172 -> V_178 . V_16 = V_105 ;
V_172 -> V_178 . V_17 = V_149 ;
V_172 -> V_179 . V_180 = 1 ;
V_172 -> V_179 . V_181 = 1 ;
return 0 ;
}
static T_4 F_66 ( int V_182 , void * V_183 )
{
struct V_1 * V_2 = V_183 ;
static unsigned long V_184 ;
struct V_8 * V_9 ;
static int V_185 ;
static int V_186 ;
T_1 V_187 = F_5 ( V_2 , V_60 ) , V_188 ;
T_1 V_189 = F_5 ( V_2 , V_57 ) ;
if ( ! ( V_187 & 0x300 ) ) {
if ( F_67 ( & V_184 , 500 ) )
F_24 ( V_2 -> V_86 . V_39 , L_18 ,
V_187 ) ;
return V_190 ;
}
F_68 ( & V_2 -> V_63 ) ;
if ( ! V_2 -> V_55 || F_69 ( & V_2 -> V_52 ) ) {
if ( F_67 ( & V_184 , 500 ) )
F_24 ( V_2 -> V_86 . V_39 ,
L_19 , V_187 ) ;
F_7 ( V_2 , V_60 , 0 , 0x300 ) ;
F_70 ( & V_2 -> V_63 ) ;
return V_191 ;
}
V_188 = ~ ( 0x300 & V_187 ) & V_187 & 0x30304 ;
F_22 ( V_2 -> V_86 . V_39 ,
L_20 ,
V_187 , V_188 , V_189 , V_185 ) ;
V_185 ++ ;
V_186 = V_189 & 0x10000 ;
F_1 ( V_2 , V_60 , V_188 ) ;
V_9 = V_2 -> V_55 ;
F_30 ( & V_9 -> V_52 ) ;
V_9 -> V_29 = V_192 ;
F_71 ( & V_9 -> V_193 ) ;
V_9 -> V_194 ++ ;
F_72 ( & V_9 -> V_195 ) ;
if ( F_69 ( & V_2 -> V_52 ) ) {
F_22 ( V_2 -> V_86 . V_39 , L_21 ,
V_40 , V_185 ) ;
F_7 ( V_2 , V_61 , 0 , 1 ) ;
V_2 -> V_55 = NULL ;
V_2 -> V_53 = V_196 ;
F_7 ( V_2 , V_60 , 0 , 0x30000 ) ;
F_70 ( & V_2 -> V_63 ) ;
return V_191 ;
}
V_2 -> V_55 = F_73 ( V_2 -> V_52 . V_58 ,
struct V_8 , V_52 ) ;
if ( V_2 -> V_55 -> V_52 . V_58 != & V_2 -> V_52 ) {
struct V_8 * V_197 = F_73 ( V_2 -> V_55 -> V_52 . V_58 ,
struct V_8 , V_52 ) ;
F_10 ( V_2 , V_197 ) ;
}
F_70 ( & V_2 -> V_63 ) ;
return V_191 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_198 * V_169 = V_2 -> V_169 ;
T_1 V_199 = F_59 ( V_169 -> V_161 ) << 29 ;
int V_124 = 100 ;
F_1 ( V_2 , V_60 , 0 ) ;
F_1 ( V_2 , V_200 , 0x101 ) ;
while ( -- V_124 && ( F_5 ( V_2 , V_200 ) & 0x101 ) )
F_75 ( 1 ) ;
if ( ! V_124 )
return - V_201 ;
F_22 ( V_2 -> V_86 . V_39 , L_22 , 100 - V_124 ) ;
if ( V_169 -> V_62 & V_202 )
V_199 |= 1 << 28 ;
if ( V_169 -> V_62 & V_203 )
V_199 |= 1 << 27 ;
if ( V_169 -> V_62 & V_204 )
V_199 |= 1 << 26 ;
F_9 ( V_2 , V_168 , V_199 , 0xfc000000 ) ;
F_1 ( V_2 , V_59 , 4 ) ;
F_3 ( V_2 , V_205 , 0x800000 ) ;
return 0 ;
}
static int F_76 ( struct V_66 * V_66 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = F_77 ( sizeof( struct V_70 ) ,
V_206 ) ;
if ( ! V_71 )
return - V_207 ;
F_22 ( V_2 -> V_86 . V_39 , L_2 , V_40 ) ;
V_66 -> V_208 = V_71 ;
if ( F_78 ( & V_2 -> V_209 ) == 1 ) {
int V_45 ;
V_2 -> V_53 = V_196 ;
F_79 ( V_34 -> V_86 -> V_39 ) ;
V_45 = F_74 ( V_2 ) ;
if ( V_45 < 0 ) {
F_80 ( & V_2 -> V_209 ) ;
F_81 ( V_34 -> V_86 -> V_39 ) ;
V_2 -> V_53 = V_210 ;
return V_45 ;
}
}
F_82 ( & V_71 -> V_72 , & V_211 ,
V_2 -> V_86 . V_39 , & V_2 -> V_63 ,
V_81 ,
V_145 ,
sizeof( struct V_8 ) , V_34 ,
& V_2 -> V_212 ) ;
return 0 ;
}
static int F_83 ( struct V_66 * V_66 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = V_66 -> V_208 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
if ( ! F_84 ( & V_2 -> V_209 ) ) {
V_2 -> V_53 = V_210 ;
F_7 ( V_2 , V_61 , 0 , 0x101 ) ;
F_81 ( V_34 -> V_86 -> V_39 ) ;
}
V_66 -> V_208 = NULL ;
F_85 ( V_71 ) ;
return 0 ;
}
static int F_86 ( struct V_66 * V_66 , struct V_213 * V_214 )
{
struct V_70 * V_71 = V_66 -> V_208 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
return F_87 ( & V_71 -> V_72 , V_214 ) ;
}
static unsigned int F_88 ( struct V_66 * V_66 , T_5 * V_215 )
{
struct V_70 * V_71 = V_66 -> V_208 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
return F_89 ( V_66 , & V_71 -> V_72 , V_215 ) ;
}
static int F_90 ( struct V_66 * V_66 , void * V_170 ,
struct V_216 * V_217 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
return F_45 ( & V_2 -> V_86 , 0 , V_218 , V_219 , V_217 ) ;
}
static int F_91 ( struct V_66 * V_66 , void * V_170 ,
struct V_220 * V_3 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
return F_45 ( & V_2 -> V_86 , 0 , V_218 , V_221 , V_3 ) ;
}
static int F_92 ( struct V_66 * V_66 , void * V_170 ,
struct V_220 * V_3 )
{
struct V_33 * V_34 = F_38 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
return F_45 ( & V_2 -> V_86 , 0 , V_218 , V_222 , V_3 ) ;
}
static int T_6 F_93 ( struct V_223 * V_224 )
{
struct V_198 * V_225 = V_224 -> V_39 . V_226 ;
struct V_97 * V_98 ;
struct V_43 * V_12 ;
struct V_227 * V_228 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_229 * V_230 , * V_231 ;
struct V_232 * V_233 ;
int V_182 , V_45 ;
V_230 = F_94 ( V_224 , V_234 , 0 ) ;
V_182 = F_95 ( V_224 , 0 ) ;
if ( ! V_225 || ! V_230 || V_182 <= 0 ) {
F_96 ( & V_224 -> V_39 , L_23 ) ;
return - V_235 ;
}
V_2 = F_77 ( sizeof( * V_2 ) , V_206 ) ;
if ( ! V_2 )
return - V_207 ;
F_97 ( & V_2 -> V_52 ) ;
F_98 ( & V_2 -> V_63 ) ;
F_99 ( & V_2 -> V_212 ) ;
F_100 ( & V_2 -> V_209 , 0 ) ;
V_2 -> V_169 = V_225 ;
V_2 -> V_53 = V_210 ;
V_98 = & V_2 -> V_98 ;
V_12 = & V_2 -> V_12 ;
V_2 -> V_102 = V_236 . V_237 ;
V_98 -> V_106 = 0 ;
V_98 -> V_104 = 0 ;
V_98 -> V_16 = V_105 ;
V_98 -> V_17 = 480 ;
V_12 -> V_16 = V_105 ;
V_12 -> V_17 = 480 ;
V_12 -> V_13 = V_238 ;
V_12 -> V_42 = V_145 ;
V_12 -> V_239 = V_105 * 2 ;
V_12 -> V_240 = V_105 * 2 * 480 ;
V_12 -> V_142 = V_143 ;
V_231 = F_101 ( V_230 -> V_241 , F_102 ( V_230 ) ,
V_224 -> V_242 ) ;
if ( ! V_231 ) {
F_96 ( & V_224 -> V_39 , L_24 ) ;
V_45 = - V_243 ;
goto V_244;
}
V_2 -> V_5 = F_103 ( V_230 -> V_241 , F_102 ( V_230 ) ) ;
if ( ! V_2 -> V_5 ) {
V_45 = - V_207 ;
goto V_245;
}
V_45 = F_104 ( V_182 , F_66 , 0 , L_25 , V_2 ) ;
if ( V_45 < 0 )
goto V_246;
V_45 = F_105 ( & V_224 -> V_39 , & V_2 -> V_86 ) ;
if ( V_45 < 0 ) {
F_96 ( & V_224 -> V_39 , L_26 ) ;
goto V_247;
}
V_34 = F_106 () ;
if ( V_34 == NULL ) {
V_45 = - V_207 ;
goto V_248;
}
* V_34 = V_236 ;
if ( V_225 -> V_161 == V_162 )
V_34 -> V_166 |= V_249 ;
V_34 -> V_86 = & V_2 -> V_86 ;
V_34 -> V_250 = V_251 ;
V_34 -> V_63 = & V_2 -> V_212 ;
V_2 -> V_34 = V_34 ;
F_107 ( V_34 , V_2 ) ;
F_108 ( & V_224 -> V_39 ) ;
F_109 ( & V_224 -> V_39 ) ;
V_228 = F_110 ( V_225 -> V_228 ) ;
if ( ! V_228 ) {
V_45 = - V_235 ;
goto V_252;
}
V_45 = F_74 ( V_2 ) ;
if ( V_45 < 0 )
goto V_253;
V_233 = F_111 ( & V_2 -> V_86 , V_228 ,
V_225 -> V_254 , NULL ) ;
if ( ! V_233 ) {
V_45 = - V_207 ;
goto V_255;
}
V_45 = F_112 ( V_34 , V_256 , - 1 ) ;
if ( V_45 < 0 )
goto V_257;
return 0 ;
V_257:
V_255:
V_253:
F_113 ( V_228 ) ;
V_252:
V_251 ( V_34 ) ;
F_114 ( & V_224 -> V_39 ) ;
V_248:
F_115 ( & V_2 -> V_86 ) ;
V_247:
F_116 ( V_182 , V_2 ) ;
V_246:
F_117 ( V_2 -> V_5 ) ;
V_245:
F_118 ( V_230 -> V_241 , F_102 ( V_230 ) ) ;
V_244:
F_85 ( V_2 ) ;
return V_45 ;
}
static int T_7 F_119 ( struct V_223 * V_224 )
{
int V_182 = F_95 ( V_224 , 0 ) ;
struct V_258 * V_86 = F_120 ( V_224 ) ;
struct V_1 * V_2 = F_121 ( V_86 ,
struct V_1 , V_86 ) ;
struct V_232 * V_259 = F_73 ( V_86 -> V_260 . V_58 ,
struct V_232 , V_261 ) ;
struct V_262 * V_263 = F_122 ( V_259 ) ;
struct V_229 * V_230 ;
if ( V_182 > 0 )
F_116 ( V_182 , V_2 ) ;
F_114 ( & V_224 -> V_39 ) ;
F_123 ( V_2 -> V_34 ) ;
F_113 ( V_263 -> V_264 ) ;
F_115 ( & V_2 -> V_86 ) ;
F_117 ( V_2 -> V_5 ) ;
V_230 = F_94 ( V_224 , V_234 , 0 ) ;
if ( V_230 )
F_118 ( V_230 -> V_241 , F_102 ( V_230 ) ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int T_8 F_124 ( void )
{
return F_125 ( & V_265 , F_93 ) ;
}
static void T_9 F_126 ( void )
{
F_127 ( & V_265 ) ;
}
