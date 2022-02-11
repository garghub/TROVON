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
V_69 -> V_74 = V_75 | V_76 ;
return 0 ;
}
static int F_34 ( struct V_66 * V_66 , void * V_67 ,
struct V_77 * V_78 )
{
struct V_70 * V_71 = V_67 ;
if ( V_78 -> V_79 >= F_35 ( V_36 ) )
return - V_48 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
V_78 -> type = V_80 ;
F_33 ( V_78 -> V_81 , V_36 [ V_78 -> V_79 ] . V_82 ,
sizeof( V_78 -> V_81 ) ) ;
V_78 -> V_13 = V_36 [ V_78 -> V_79 ] . V_83 ;
return 0 ;
}
static int F_36 ( struct V_66 * V_66 , void * V_67 ,
struct V_84 * V_78 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
F_22 ( V_2 -> V_85 . V_39 , L_2 , V_40 ) ;
V_78 -> type = V_80 ;
V_78 -> V_78 . V_12 = V_2 -> V_12 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
int V_37 , int V_86 , int V_87 )
{
struct V_88 * V_78 = V_36 + V_37 ;
unsigned int V_89 , V_90 , V_91 , V_92 ,
V_93 , V_94 , V_95 ;
struct V_96 * V_97 = & V_2 -> V_97 ;
struct V_43 * V_12 = & V_2 -> V_12 ;
T_1 V_98 = 0 , V_99 , V_100 ;
if ( V_2 -> V_101 & V_102 ) {
V_91 = 858 ;
V_92 = 262 ;
} else {
V_91 = 864 ;
V_92 = 312 ;
}
V_93 = V_12 -> V_17 / 2 ;
V_94 = V_97 -> V_17 / 2 ;
V_95 = V_97 -> V_103 / 2 ;
V_89 = V_91 - V_104 ;
V_90 = 20 ;
V_99 = V_97 -> V_16 + V_97 -> V_105 ;
V_100 = V_94 + V_95 ;
F_22 ( V_2 -> V_85 . V_39 ,
L_9 ,
V_12 -> V_16 , V_93 , V_89 , V_90 ,
V_97 -> V_105 , V_95 , V_99 , V_100 ) ;
F_3 ( V_2 , V_106 , ( V_12 -> V_16 << 16 ) | V_93 ) ;
F_3 ( V_2 , V_107 , ( V_89 << 16 ) | V_90 ) ;
F_3 ( V_2 , V_108 , ( V_97 -> V_105 << 16 ) | V_95 ) ;
F_3 ( V_2 , V_109 , ( V_99 << 16 ) | V_100 ) ;
if ( V_86 )
V_98 |= ( 1 << 15 ) | ( V_110 [ V_86 - 1 ] << 4 ) ;
if ( V_87 )
V_98 |= ( 1 << 14 ) | V_111 [ V_87 - 1 ] ;
F_22 ( V_2 -> V_85 . V_39 , L_10 , V_78 -> V_82 , V_98 ) ;
F_3 ( V_2 , V_112 , V_98 ) ;
F_3 ( V_2 , V_113 ,
V_78 -> V_114 | ( V_78 -> V_115 << 8 ) | ( V_78 -> V_116 << 16 ) ) ;
}
static void F_39 ( struct V_117 * V_118 , T_3 V_101 )
{
unsigned int V_119 = V_120 , V_121 = 0 , V_122 ;
int V_123 , V_124 = 0 ;
if ( V_101 & V_102 )
V_122 = 480 ;
else
V_122 = 576 ;
F_40 ( & V_118 -> V_125 , 0 , V_104 , 2 ,
& V_118 -> V_126 , 0 , V_122 , 1 , 0 ) ;
for ( V_123 = F_35 ( V_127 ) - 1 ; V_123 >= 0 ; V_123 -- ) {
unsigned int V_128 ;
unsigned int V_129 = V_118 -> V_130 . V_16 * V_131 [ V_123 ] /
V_127 [ V_123 ] ;
if ( V_129 > V_104 )
break;
V_128 = abs ( V_129 - V_118 -> V_125 ) ;
if ( V_128 < V_119 ) {
V_119 = V_128 ;
V_124 = V_123 ;
V_121 = V_129 ;
}
if ( ! V_128 )
break;
}
V_118 -> V_125 = V_121 ;
V_118 -> V_132 = V_124 ;
V_119 = V_120 ;
for ( V_123 = F_35 ( V_133 ) - 1 ; V_123 >= 0 ; V_123 -- ) {
unsigned int V_128 ;
unsigned int V_129 = V_118 -> V_130 . V_17 * V_134 [ V_123 ] /
V_133 [ V_123 ] ;
if ( V_129 > V_122 )
break;
V_128 = abs ( V_129 - V_118 -> V_126 ) ;
if ( V_128 < V_119 ) {
V_119 = V_128 ;
V_124 = V_123 ;
V_121 = V_129 ;
}
if ( ! V_128 )
break;
}
V_118 -> V_126 = V_121 ;
V_118 -> V_135 = V_124 ;
}
static void F_41 ( struct V_117 * V_118 , T_3 V_101 )
{
unsigned int V_119 = V_120 , V_121 , V_91 , V_92 ,
V_122 ;
int V_123 , V_124 ;
if ( V_101 & V_102 ) {
V_91 = 858 ;
V_92 = 262 * 2 ;
V_122 = 480 ;
} else {
V_91 = 864 ;
V_92 = 312 * 2 ;
V_122 = 576 ;
}
for ( V_123 = 0 ; V_123 < F_35 ( V_127 ) ; V_123 ++ ) {
unsigned int V_128 ;
unsigned int V_129 = V_118 -> V_125 * V_127 [ V_123 ] /
V_131 [ V_123 ] ;
if ( V_129 > V_104 )
break;
V_128 = abs ( V_129 - V_118 -> V_130 . V_16 ) ;
if ( V_128 < V_119 ) {
V_119 = V_128 ;
V_124 = V_123 ;
V_121 = V_129 ;
}
if ( ! V_128 )
break;
}
V_118 -> V_130 . V_16 = V_121 ;
V_118 -> V_132 = V_124 ;
if ( V_118 -> V_130 . V_105 + V_121 > V_91 )
V_118 -> V_130 . V_105 = V_91 - V_121 ;
F_42 ( L_11 , V_40 , V_118 -> V_125 ,
V_127 [ V_124 ] , V_131 [ V_124 ] , V_121 ) ;
V_119 = V_120 ;
for ( V_123 = 0 ; V_123 < F_35 ( V_133 ) ; V_123 ++ ) {
unsigned int V_128 ;
unsigned int V_129 = V_118 -> V_126 * V_133 [ V_123 ] /
V_134 [ V_123 ] ;
if ( V_129 > V_122 )
break;
V_128 = abs ( V_129 - V_118 -> V_130 . V_17 ) ;
if ( V_128 < V_119 ) {
V_119 = V_128 ;
V_124 = V_123 ;
V_121 = V_129 ;
}
if ( ! V_128 )
break;
}
V_118 -> V_130 . V_17 = V_121 ;
V_118 -> V_135 = V_124 ;
if ( V_118 -> V_130 . V_103 + V_121 > V_92 )
V_118 -> V_130 . V_103 = V_92 - V_121 ;
F_42 ( L_12 , V_40 , V_118 -> V_126 ,
V_133 [ V_124 ] , V_134 [ V_124 ] , V_121 ) ;
}
static int F_43 ( struct V_66 * V_66 , void * V_67 ,
struct V_84 * V_78 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_43 * V_12 = & V_78 -> V_78 . V_12 ;
unsigned int V_122 ;
int V_37 ;
struct V_117 V_118 ;
struct V_136 V_137 = {
. V_138 = V_139 ,
. V_42 = V_140 ,
. V_141 = V_142 ,
} ;
int V_45 ;
F_22 ( V_2 -> V_85 . V_39 , L_13 , V_40 ,
V_2 -> V_97 . V_16 , V_2 -> V_97 . V_17 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
if ( V_12 -> V_42 == V_143 )
V_12 -> V_42 = V_144 ;
if ( V_78 -> type != V_80 ||
V_12 -> V_42 != V_144 )
return - V_48 ;
for ( V_37 = 0 ; V_37 < F_35 ( V_36 ) ; V_37 ++ )
if ( V_36 [ V_37 ] . V_83 == V_12 -> V_13 )
break;
if ( V_37 == F_35 ( V_36 ) )
return - V_48 ;
if ( V_2 -> V_101 & V_102 )
V_122 = 480 ;
else
V_122 = 576 ;
F_40 ( & V_12 -> V_16 , 0 , V_104 , 2 ,
& V_12 -> V_17 , 0 , V_122 , 1 , 0 ) ;
V_118 . V_125 = V_12 -> V_16 ;
V_118 . V_126 = V_12 -> V_17 ;
V_118 . V_130 = V_2 -> V_97 ;
F_41 ( & V_118 , V_2 -> V_101 ) ;
V_137 . V_16 = V_118 . V_130 . V_16 ;
V_137 . V_17 = V_118 . V_130 . V_17 ;
V_45 = F_44 ( & V_2 -> V_85 , 0 , V_145 ,
V_146 , & V_137 ) ;
if ( V_45 < 0 )
return V_45 ;
F_22 ( V_2 -> V_85 . V_39 , L_13 , V_40 ,
V_118 . V_130 . V_16 , V_118 . V_130 . V_17 , V_137 . V_16 , V_137 . V_17 ) ;
if ( ( unsigned ) V_137 . V_16 > V_104 ||
( unsigned ) V_137 . V_17 > V_122 ||
V_137 . V_138 != V_139 )
return - V_147 ;
if ( V_137 . V_16 != V_118 . V_130 . V_16 ||
V_137 . V_17 != V_118 . V_130 . V_17 ) {
V_118 . V_130 . V_16 = V_137 . V_16 ;
V_118 . V_130 . V_17 = V_137 . V_17 ;
F_39 ( & V_118 , V_2 -> V_101 ) ;
}
V_2 -> V_97 = V_118 . V_130 ;
V_12 -> V_16 = V_118 . V_125 ;
V_12 -> V_17 = V_118 . V_126 ;
F_22 ( V_2 -> V_85 . V_39 , L_14 , V_40 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_12 = * V_12 ;
F_38 ( V_2 , V_37 ,
V_118 . V_132 , V_118 . V_135 ) ;
return 0 ;
}
static int F_45 ( struct V_66 * V_66 , void * V_67 ,
struct V_84 * V_78 )
{
struct V_70 * V_71 = V_67 ;
struct V_43 * V_12 = & V_78 -> V_78 . V_12 ;
int V_123 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
V_78 -> type = V_80 ;
V_12 -> V_42 = V_144 ;
F_40 ( & V_12 -> V_16 , 0 , V_104 , 1 ,
& V_12 -> V_17 , 0 , V_148 , 1 , 0 ) ;
for ( V_123 = 0 ; F_35 ( V_36 ) ; V_123 ++ )
if ( V_36 [ V_123 ] . V_83 == V_12 -> V_13 )
return 0 ;
V_12 -> V_13 = V_36 [ 0 ] . V_83 ;
return 0 ;
}
static int F_46 ( struct V_66 * V_66 , void * V_67 ,
struct V_149 * V_150 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
if ( V_150 -> type != V_80 )
return - V_48 ;
return F_47 ( & V_71 -> V_72 , V_150 ) ;
}
static int F_48 ( struct V_66 * V_66 , void * V_67 ,
struct V_151 * V_152 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
return F_49 ( & V_71 -> V_72 , V_152 ) ;
}
static int F_50 ( struct V_66 * V_66 , void * V_67 , struct V_151 * V_152 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
return F_51 ( & V_71 -> V_72 , V_152 ) ;
}
static int F_52 ( struct V_66 * V_66 , void * V_67 , struct V_151 * V_152 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
return F_53 ( & V_71 -> V_72 , V_152 , V_66 -> V_153 & V_154 ) ;
}
static int F_54 ( struct V_66 * V_66 , void * V_67 ,
enum V_155 V_156 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = V_67 ;
int V_45 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
V_45 = F_44 ( & V_2 -> V_85 , 0 ,
V_145 , V_157 , 1 ) ;
if ( V_45 < 0 && V_45 != - V_158 )
return V_45 ;
return F_55 ( & V_71 -> V_72 ) ;
}
static int F_56 ( struct V_66 * V_66 , void * V_67 ,
enum V_155 V_156 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
F_57 ( & V_71 -> V_72 ) ;
F_44 ( & V_2 -> V_85 , 0 , V_145 , V_157 , 0 ) ;
return 0 ;
}
static T_1 F_58 ( enum V_159 V_160 )
{
switch ( V_160 ) {
default:
F_59 ( L_15 ,
V_40 , V_160 ) ;
case V_161 :
return 1 ;
case V_162 :
return 0 ;
case V_163 :
return 3 ;
}
}
static int F_60 ( struct V_66 * V_66 , void * V_67 , T_3 * V_164 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
int V_45 ;
F_22 ( V_2 -> V_85 . V_39 , L_16 , V_40 , * V_164 ) ;
if ( * V_164 & ~ V_34 -> V_165 )
return - V_48 ;
V_45 = F_44 ( & V_2 -> V_85 , 0 , V_145 ,
V_166 , * V_164 ) ;
if ( V_45 < 0 && V_45 != - V_158 )
return V_45 ;
if ( * V_164 & V_102 )
F_9 ( V_2 , V_167 ,
F_58 ( V_2 -> V_168 -> V_160 ) << 29 , 7 << 29 ) ;
else
F_9 ( V_2 , V_167 , 5 << 29 , 7 << 29 ) ;
V_2 -> V_101 = * V_164 ;
return 0 ;
}
static int F_61 ( struct V_66 * V_66 , void * V_67 , T_3 * V_101 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
F_22 ( V_2 -> V_85 . V_39 , L_2 , V_40 ) ;
* V_101 = V_2 -> V_101 ;
return 0 ;
}
static int F_62 ( struct V_66 * V_66 , void * V_169 , struct V_170 * V_171 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
F_22 ( V_2 -> V_85 . V_39 , L_2 , V_40 ) ;
V_171 -> type = V_80 ;
V_171 -> V_172 = V_2 -> V_97 ;
return 0 ;
}
static int F_63 ( struct V_66 * V_66 , void * V_169 , const struct V_170 * V_171 )
{
struct V_170 V_173 = * V_171 ;
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_96 * V_97 = & V_173 . V_172 ;
struct V_170 V_174 = { . type = V_80 } ;
struct V_43 * V_12 = & V_2 -> V_12 ;
struct V_117 V_118 ;
struct V_136 V_137 = {
. V_138 = V_139 ,
. V_42 = V_140 ,
. V_141 = V_142 ,
} ;
unsigned int V_122 ;
int V_45 ;
F_22 ( V_2 -> V_85 . V_39 , L_17 , V_40 ,
V_97 -> V_16 , V_97 -> V_17 , V_97 -> V_105 , V_97 -> V_103 ) ;
if ( V_171 -> type != V_80 )
return - V_48 ;
if ( V_2 -> V_101 & V_102 )
V_122 = 480 ;
else
V_122 = 576 ;
F_40 ( & V_97 -> V_16 , 0 , V_104 , 1 ,
& V_97 -> V_17 , 0 , V_122 , 1 , 0 ) ;
if ( V_97 -> V_16 + V_97 -> V_105 > V_104 )
V_97 -> V_105 = V_104 - V_97 -> V_16 ;
if ( V_97 -> V_17 + V_97 -> V_103 > V_122 )
V_97 -> V_103 = V_122 - V_97 -> V_17 ;
V_118 . V_130 = * V_97 ;
V_118 . V_125 = V_12 -> V_16 ;
V_118 . V_126 = V_12 -> V_17 ;
V_174 . V_172 . V_16 = V_118 . V_130 . V_16 ;
V_174 . V_172 . V_17 = V_118 . V_130 . V_17 ;
F_44 ( & V_2 -> V_85 , 0 , V_145 ,
V_175 , & V_174 ) ;
V_137 . V_16 = V_118 . V_130 . V_16 ;
V_137 . V_17 = V_118 . V_130 . V_17 ;
V_45 = F_44 ( & V_2 -> V_85 , 0 , V_145 ,
V_146 , & V_137 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( ( unsigned ) V_137 . V_16 > V_104 ||
( unsigned ) V_137 . V_17 > V_122 ||
V_137 . V_138 != V_139 )
return - V_147 ;
V_118 . V_130 . V_16 = V_137 . V_16 ;
V_118 . V_130 . V_17 = V_137 . V_17 ;
F_39 ( & V_118 , V_2 -> V_101 ) ;
V_2 -> V_97 = V_118 . V_130 ;
V_12 -> V_16 = V_118 . V_125 ;
V_12 -> V_17 = V_118 . V_126 ;
F_38 ( V_2 , V_2 -> V_37 ,
V_118 . V_132 , V_118 . V_135 ) ;
return 0 ;
}
static int F_64 ( struct V_66 * V_66 , void * V_67 ,
struct V_176 * V_171 )
{
struct V_70 * V_71 = V_67 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
V_171 -> type = V_80 ;
V_171 -> V_177 . V_105 = 0 ;
V_171 -> V_177 . V_103 = 0 ;
V_171 -> V_177 . V_16 = V_104 ;
V_171 -> V_177 . V_17 = V_148 ;
V_171 -> V_178 . V_105 = 0 ;
V_171 -> V_178 . V_103 = 0 ;
V_171 -> V_178 . V_16 = V_104 ;
V_171 -> V_178 . V_17 = V_148 ;
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
static int V_186 ;
T_1 V_187 = F_5 ( V_2 , V_60 ) , V_188 ;
T_1 V_189 = F_5 ( V_2 , V_57 ) ;
if ( ! ( V_187 & 0x300 ) ) {
if ( F_66 ( & V_184 , 500 ) )
F_24 ( V_2 -> V_85 . V_39 , L_18 ,
V_187 ) ;
return V_190 ;
}
F_67 ( & V_2 -> V_63 ) ;
if ( ! V_2 -> V_55 || F_68 ( & V_2 -> V_52 ) ) {
if ( F_66 ( & V_184 , 500 ) )
F_24 ( V_2 -> V_85 . V_39 ,
L_19 , V_187 ) ;
F_7 ( V_2 , V_60 , 0 , 0x300 ) ;
F_69 ( & V_2 -> V_63 ) ;
return V_191 ;
}
V_188 = ~ ( 0x300 & V_187 ) & V_187 & 0x30304 ;
F_22 ( V_2 -> V_85 . V_39 ,
L_20 ,
V_187 , V_188 , V_189 , V_185 ) ;
V_185 ++ ;
V_186 = V_189 & 0x10000 ;
F_1 ( V_2 , V_60 , V_188 ) ;
V_9 = V_2 -> V_55 ;
F_30 ( & V_9 -> V_52 ) ;
V_9 -> V_29 = V_192 ;
F_70 ( & V_9 -> V_193 ) ;
V_9 -> V_194 ++ ;
F_71 ( & V_9 -> V_195 ) ;
if ( F_68 ( & V_2 -> V_52 ) ) {
F_22 ( V_2 -> V_85 . V_39 , L_21 ,
V_40 , V_185 ) ;
F_7 ( V_2 , V_61 , 0 , 1 ) ;
V_2 -> V_55 = NULL ;
V_2 -> V_53 = V_196 ;
F_7 ( V_2 , V_60 , 0 , 0x30000 ) ;
F_69 ( & V_2 -> V_63 ) ;
return V_191 ;
}
V_2 -> V_55 = F_72 ( V_2 -> V_52 . V_58 ,
struct V_8 , V_52 ) ;
if ( V_2 -> V_55 -> V_52 . V_58 != & V_2 -> V_52 ) {
struct V_8 * V_197 = F_72 ( V_2 -> V_55 -> V_52 . V_58 ,
struct V_8 , V_52 ) ;
F_10 ( V_2 , V_197 ) ;
}
F_69 ( & V_2 -> V_63 ) ;
return V_191 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_198 * V_168 = V_2 -> V_168 ;
T_1 V_199 = F_58 ( V_168 -> V_160 ) << 29 ;
int V_123 = 100 ;
F_1 ( V_2 , V_60 , 0 ) ;
F_1 ( V_2 , V_200 , 0x101 ) ;
while ( -- V_123 && ( F_5 ( V_2 , V_200 ) & 0x101 ) )
F_74 ( 1 ) ;
if ( ! V_123 )
return - V_201 ;
F_22 ( V_2 -> V_85 . V_39 , L_22 , 100 - V_123 ) ;
if ( V_168 -> V_62 & V_202 )
V_199 |= 1 << 28 ;
if ( V_168 -> V_62 & V_203 )
V_199 |= 1 << 27 ;
if ( V_168 -> V_62 & V_204 )
V_199 |= 1 << 26 ;
F_9 ( V_2 , V_167 , V_199 , 0xfc000000 ) ;
F_1 ( V_2 , V_59 , 4 ) ;
F_3 ( V_2 , V_205 , 0x800000 ) ;
return 0 ;
}
static int F_75 ( struct V_66 * V_66 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = F_76 ( sizeof( struct V_70 ) ,
V_206 ) ;
if ( ! V_71 )
return - V_207 ;
F_22 ( V_2 -> V_85 . V_39 , L_2 , V_40 ) ;
V_66 -> V_208 = V_71 ;
if ( F_77 ( & V_2 -> V_209 ) )
return - V_210 ;
if ( F_78 ( & V_2 -> V_211 ) == 1 ) {
int V_45 ;
V_2 -> V_53 = V_196 ;
F_79 ( V_34 -> V_85 -> V_39 ) ;
V_45 = F_73 ( V_2 ) ;
if ( V_45 < 0 ) {
F_80 ( & V_2 -> V_211 ) ;
F_81 ( V_34 -> V_85 -> V_39 ) ;
V_2 -> V_53 = V_212 ;
F_82 ( & V_2 -> V_209 ) ;
return V_45 ;
}
}
F_83 ( & V_71 -> V_72 , & V_213 ,
V_2 -> V_85 . V_39 , & V_2 -> V_63 ,
V_80 ,
V_144 ,
sizeof( struct V_8 ) , V_34 ,
& V_2 -> V_209 ) ;
F_82 ( & V_2 -> V_209 ) ;
return 0 ;
}
static int F_84 ( struct V_66 * V_66 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = V_66 -> V_208 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
if ( ! F_85 ( & V_2 -> V_211 ) ) {
F_86 ( & V_2 -> V_209 ) ;
V_2 -> V_53 = V_212 ;
F_7 ( V_2 , V_61 , 0 , 0x101 ) ;
F_81 ( V_34 -> V_85 -> V_39 ) ;
F_82 ( & V_2 -> V_209 ) ;
}
V_66 -> V_208 = NULL ;
F_87 ( V_71 ) ;
return 0 ;
}
static int F_88 ( struct V_66 * V_66 , struct V_214 * V_215 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = V_66 -> V_208 ;
int V_45 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
if ( F_77 ( & V_2 -> V_209 ) )
return - V_210 ;
V_45 = F_89 ( & V_71 -> V_72 , V_215 ) ;
F_82 ( & V_2 -> V_209 ) ;
return V_45 ;
}
static unsigned int F_90 ( struct V_66 * V_66 , T_5 * V_216 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
struct V_70 * V_71 = V_66 -> V_208 ;
unsigned int V_217 ;
F_22 ( V_71 -> V_72 . V_39 , L_2 , V_40 ) ;
F_86 ( & V_2 -> V_209 ) ;
V_217 = F_91 ( V_66 , & V_71 -> V_72 , V_216 ) ;
F_82 ( & V_2 -> V_209 ) ;
return V_217 ;
}
static int F_92 ( struct V_66 * V_66 , void * V_169 ,
struct V_218 * V_219 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
return F_44 ( & V_2 -> V_85 , 0 , V_220 , V_221 , V_219 ) ;
}
static int F_93 ( struct V_66 * V_66 , void * V_169 ,
struct V_222 * V_3 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
return F_44 ( & V_2 -> V_85 , 0 , V_220 , V_223 , V_3 ) ;
}
static int F_94 ( struct V_66 * V_66 , void * V_169 ,
struct V_222 * V_3 )
{
struct V_33 * V_34 = F_37 ( V_66 ) ;
struct V_1 * V_2 = F_20 ( V_34 ) ;
return F_44 ( & V_2 -> V_85 , 0 , V_220 , V_224 , V_3 ) ;
}
static int F_95 ( struct V_225 * V_226 )
{
struct V_198 * V_227 = V_226 -> V_39 . V_228 ;
struct V_96 * V_97 ;
struct V_43 * V_12 ;
struct V_229 * V_230 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_231 * V_232 , * V_233 ;
struct V_234 * V_235 ;
int V_182 , V_45 ;
V_232 = F_96 ( V_226 , V_236 , 0 ) ;
V_182 = F_97 ( V_226 , 0 ) ;
if ( ! V_227 || ! V_232 || V_182 <= 0 ) {
F_98 ( & V_226 -> V_39 , L_23 ) ;
return - V_237 ;
}
V_2 = F_76 ( sizeof( * V_2 ) , V_206 ) ;
if ( ! V_2 )
return - V_207 ;
F_99 ( & V_2 -> V_52 ) ;
F_100 ( & V_2 -> V_63 ) ;
F_101 ( & V_2 -> V_209 ) ;
F_102 ( & V_2 -> V_211 , 0 ) ;
V_2 -> V_168 = V_227 ;
V_2 -> V_53 = V_212 ;
V_97 = & V_2 -> V_97 ;
V_12 = & V_2 -> V_12 ;
V_2 -> V_101 = V_238 . V_239 ;
V_97 -> V_105 = 0 ;
V_97 -> V_103 = 0 ;
V_97 -> V_16 = V_104 ;
V_97 -> V_17 = 480 ;
V_12 -> V_16 = V_104 ;
V_12 -> V_17 = 480 ;
V_12 -> V_13 = V_240 ;
V_12 -> V_42 = V_144 ;
V_12 -> V_241 = V_104 * 2 ;
V_12 -> V_242 = V_104 * 2 * 480 ;
V_12 -> V_141 = V_142 ;
V_233 = F_103 ( V_232 -> V_243 , F_104 ( V_232 ) ,
V_226 -> V_244 ) ;
if ( ! V_233 ) {
F_98 ( & V_226 -> V_39 , L_24 ) ;
V_45 = - V_245 ;
goto V_246;
}
V_2 -> V_5 = F_105 ( V_232 -> V_243 , F_104 ( V_232 ) ) ;
if ( ! V_2 -> V_5 ) {
V_45 = - V_207 ;
goto V_247;
}
V_45 = F_106 ( V_182 , F_65 , 0 , L_25 , V_2 ) ;
if ( V_45 < 0 )
goto V_248;
V_45 = F_107 ( & V_226 -> V_39 , & V_2 -> V_85 ) ;
if ( V_45 < 0 ) {
F_98 ( & V_226 -> V_39 , L_26 ) ;
goto V_249;
}
V_34 = F_108 () ;
if ( V_34 == NULL ) {
V_45 = - V_207 ;
goto V_250;
}
* V_34 = V_238 ;
if ( V_227 -> V_160 == V_161 )
V_34 -> V_165 |= V_251 ;
V_34 -> V_85 = & V_2 -> V_85 ;
V_34 -> V_252 = V_253 ;
V_34 -> V_63 = & V_2 -> V_209 ;
V_2 -> V_34 = V_34 ;
F_109 ( V_34 , V_2 ) ;
F_110 ( & V_226 -> V_39 ) ;
F_111 ( & V_226 -> V_39 ) ;
V_230 = F_112 ( V_227 -> V_230 ) ;
if ( ! V_230 ) {
V_45 = - V_237 ;
goto V_254;
}
V_45 = F_73 ( V_2 ) ;
if ( V_45 < 0 )
goto V_255;
V_235 = F_113 ( & V_2 -> V_85 , V_230 ,
V_227 -> V_256 , NULL ) ;
if ( ! V_235 ) {
V_45 = - V_207 ;
goto V_257;
}
V_45 = F_114 ( V_34 , V_258 , - 1 ) ;
if ( V_45 < 0 )
goto V_259;
return 0 ;
V_259:
V_257:
V_255:
F_115 ( V_230 ) ;
V_254:
V_253 ( V_34 ) ;
F_116 ( & V_226 -> V_39 ) ;
V_250:
F_117 ( & V_2 -> V_85 ) ;
V_249:
F_118 ( V_182 , V_2 ) ;
V_248:
F_119 ( V_2 -> V_5 ) ;
V_247:
F_120 ( V_232 -> V_243 , F_104 ( V_232 ) ) ;
V_246:
F_87 ( V_2 ) ;
return V_45 ;
}
static int F_121 ( struct V_225 * V_226 )
{
int V_182 = F_97 ( V_226 , 0 ) ;
struct V_260 * V_85 = F_122 ( V_226 ) ;
struct V_1 * V_2 = F_123 ( V_85 ,
struct V_1 , V_85 ) ;
struct V_234 * V_261 = F_72 ( V_85 -> V_262 . V_58 ,
struct V_234 , V_263 ) ;
struct V_264 * V_265 = F_124 ( V_261 ) ;
struct V_231 * V_232 ;
if ( V_182 > 0 )
F_118 ( V_182 , V_2 ) ;
F_116 ( & V_226 -> V_39 ) ;
F_125 ( V_2 -> V_34 ) ;
F_115 ( V_265 -> V_266 ) ;
F_117 ( & V_2 -> V_85 ) ;
F_119 ( V_2 -> V_5 ) ;
V_232 = F_96 ( V_226 , V_236 , 0 ) ;
if ( V_232 )
F_120 ( V_232 -> V_243 , F_104 ( V_232 ) ) ;
F_87 ( V_2 ) ;
return 0 ;
}
static int T_6 F_126 ( void )
{
return F_127 ( & V_267 , F_95 ) ;
}
static void T_7 F_128 ( void )
{
F_129 ( & V_267 ) ;
}
