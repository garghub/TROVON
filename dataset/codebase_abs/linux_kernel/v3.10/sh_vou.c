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
F_22 ( V_2 -> V_39 . V_40 ,
L_5 ,
V_41 , V_2 -> V_37 , V_45 ,
F_11 ( V_9 ) , V_9 -> V_50 , V_9 -> V_29 ) ;
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
unsigned int V_86 , V_87 , V_88 , V_89 ,
V_90 , V_91 , V_92 ;
struct V_93 * V_94 = & V_2 -> V_94 ;
struct V_44 * V_12 = & V_2 -> V_12 ;
T_1 V_95 = 0 , V_96 , V_97 ;
if ( V_2 -> V_98 & V_99 ) {
V_88 = 858 ;
V_89 = 262 ;
} else {
V_88 = 864 ;
V_89 = 312 ;
}
V_90 = V_12 -> V_17 / 2 ;
V_91 = V_94 -> V_17 / 2 ;
V_92 = V_94 -> V_100 / 2 ;
V_86 = V_88 - V_101 ;
V_87 = 20 ;
V_96 = V_94 -> V_16 + V_94 -> V_102 ;
V_97 = V_91 + V_92 ;
F_22 ( V_2 -> V_39 . V_40 ,
L_9 ,
V_12 -> V_16 , V_90 , V_86 , V_87 ,
V_94 -> V_102 , V_92 , V_96 , V_97 ) ;
F_3 ( V_2 , V_103 , ( V_12 -> V_16 << 16 ) | V_90 ) ;
F_3 ( V_2 , V_104 , ( V_86 << 16 ) | V_87 ) ;
F_3 ( V_2 , V_105 , ( V_94 -> V_102 << 16 ) | V_92 ) ;
F_3 ( V_2 , V_106 , ( V_96 << 16 ) | V_97 ) ;
if ( V_83 )
V_95 |= ( 1 << 15 ) | ( V_107 [ V_83 - 1 ] << 4 ) ;
if ( V_84 )
V_95 |= ( 1 << 14 ) | V_108 [ V_84 - 1 ] ;
F_22 ( V_2 -> V_39 . V_40 , L_10 , V_76 -> V_80 , V_95 ) ;
F_3 ( V_2 , V_109 , V_95 ) ;
F_3 ( V_2 , V_110 ,
V_76 -> V_111 | ( V_76 -> V_112 << 8 ) | ( V_76 -> V_113 << 16 ) ) ;
}
static void F_39 ( struct V_114 * V_115 , T_3 V_98 )
{
unsigned int V_116 = V_117 , V_118 = 0 , V_119 ;
int V_120 , V_121 = 0 ;
if ( V_98 & V_99 )
V_119 = 480 ;
else
V_119 = 576 ;
F_40 ( & V_115 -> V_122 , 0 , V_101 , 2 ,
& V_115 -> V_123 , 0 , V_119 , 1 , 0 ) ;
for ( V_120 = F_36 ( V_124 ) - 1 ; V_120 >= 0 ; V_120 -- ) {
unsigned int V_125 ;
unsigned int V_126 = V_115 -> V_127 . V_16 * V_128 [ V_120 ] /
V_124 [ V_120 ] ;
if ( V_126 > V_101 )
break;
V_125 = abs ( V_126 - V_115 -> V_122 ) ;
if ( V_125 < V_116 ) {
V_116 = V_125 ;
V_121 = V_120 ;
V_118 = V_126 ;
}
if ( ! V_125 )
break;
}
V_115 -> V_122 = V_118 ;
V_115 -> V_129 = V_121 ;
V_116 = V_117 ;
for ( V_120 = F_36 ( V_130 ) - 1 ; V_120 >= 0 ; V_120 -- ) {
unsigned int V_125 ;
unsigned int V_126 = V_115 -> V_127 . V_17 * V_131 [ V_120 ] /
V_130 [ V_120 ] ;
if ( V_126 > V_119 )
break;
V_125 = abs ( V_126 - V_115 -> V_123 ) ;
if ( V_125 < V_116 ) {
V_116 = V_125 ;
V_121 = V_120 ;
V_118 = V_126 ;
}
if ( ! V_125 )
break;
}
V_115 -> V_123 = V_118 ;
V_115 -> V_132 = V_121 ;
}
static void F_41 ( struct V_114 * V_115 , T_3 V_98 )
{
unsigned int V_116 = V_117 , V_118 = V_115 -> V_122 ,
V_88 , V_89 , V_119 ;
int V_120 , V_121 = 0 ;
if ( V_98 & V_99 ) {
V_88 = 858 ;
V_89 = 262 * 2 ;
V_119 = 480 ;
} else {
V_88 = 864 ;
V_89 = 312 * 2 ;
V_119 = 576 ;
}
for ( V_120 = 0 ; V_120 < F_36 ( V_124 ) ; V_120 ++ ) {
unsigned int V_125 ;
unsigned int V_126 = V_115 -> V_122 * V_124 [ V_120 ] /
V_128 [ V_120 ] ;
if ( V_126 > V_101 )
break;
V_125 = abs ( V_126 - V_115 -> V_127 . V_16 ) ;
if ( V_125 < V_116 ) {
V_116 = V_125 ;
V_121 = V_120 ;
V_118 = V_126 ;
}
if ( ! V_125 )
break;
}
V_115 -> V_127 . V_16 = V_118 ;
V_115 -> V_129 = V_121 ;
if ( V_115 -> V_127 . V_102 + V_118 > V_88 )
V_115 -> V_127 . V_102 = V_88 - V_118 ;
F_42 ( L_11 , V_41 , V_115 -> V_122 ,
V_124 [ V_121 ] , V_128 [ V_121 ] , V_118 ) ;
V_116 = V_117 ;
for ( V_120 = 0 ; V_120 < F_36 ( V_130 ) ; V_120 ++ ) {
unsigned int V_125 ;
unsigned int V_126 = V_115 -> V_123 * V_130 [ V_120 ] /
V_131 [ V_120 ] ;
if ( V_126 > V_119 )
break;
V_125 = abs ( V_126 - V_115 -> V_127 . V_17 ) ;
if ( V_125 < V_116 ) {
V_116 = V_125 ;
V_121 = V_120 ;
V_118 = V_126 ;
}
if ( ! V_125 )
break;
}
V_115 -> V_127 . V_17 = V_118 ;
V_115 -> V_132 = V_121 ;
if ( V_115 -> V_127 . V_100 + V_118 > V_89 )
V_115 -> V_127 . V_100 = V_89 - V_118 ;
F_42 ( L_12 , V_41 , V_115 -> V_123 ,
V_130 [ V_121 ] , V_131 [ V_121 ] , V_118 ) ;
}
static int F_43 ( struct V_67 * V_67 , void * V_68 ,
struct V_82 * V_76 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_44 * V_12 = & V_76 -> V_76 . V_12 ;
unsigned int V_119 ;
int V_37 ;
struct V_114 V_115 ;
struct V_133 V_134 = {
. V_135 = V_136 ,
. V_43 = V_137 ,
. V_138 = V_139 ,
} ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_13 , V_41 ,
V_2 -> V_94 . V_16 , V_2 -> V_94 . V_17 ,
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
if ( V_2 -> V_98 & V_99 )
V_119 = 480 ;
else
V_119 = 576 ;
F_40 ( & V_12 -> V_16 , 0 , V_101 , 2 ,
& V_12 -> V_17 , 0 , V_119 , 1 , 0 ) ;
V_115 . V_122 = V_12 -> V_16 ;
V_115 . V_123 = V_12 -> V_17 ;
V_115 . V_127 = V_2 -> V_94 ;
F_41 ( & V_115 , V_2 -> V_98 ) ;
V_134 . V_16 = V_115 . V_127 . V_16 ;
V_134 . V_17 = V_115 . V_127 . V_17 ;
V_46 = F_44 ( & V_2 -> V_39 , 0 , V_142 ,
V_143 , & V_134 ) ;
if ( V_46 < 0 )
return V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_13 , V_41 ,
V_115 . V_127 . V_16 , V_115 . V_127 . V_17 , V_134 . V_16 , V_134 . V_17 ) ;
if ( ( unsigned ) V_134 . V_16 > V_101 ||
( unsigned ) V_134 . V_17 > V_119 ||
V_134 . V_135 != V_136 )
return - V_144 ;
if ( V_134 . V_16 != V_115 . V_127 . V_16 ||
V_134 . V_17 != V_115 . V_127 . V_17 ) {
V_115 . V_127 . V_16 = V_134 . V_16 ;
V_115 . V_127 . V_17 = V_134 . V_17 ;
F_39 ( & V_115 , V_2 -> V_98 ) ;
}
V_2 -> V_94 = V_115 . V_127 ;
V_12 -> V_16 = V_115 . V_122 ;
V_12 -> V_17 = V_115 . V_123 ;
F_22 ( V_2 -> V_39 . V_40 , L_14 , V_41 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_12 = * V_12 ;
F_38 ( V_2 , V_37 ,
V_115 . V_129 , V_115 . V_132 ) ;
return 0 ;
}
static int F_45 ( struct V_67 * V_67 , void * V_68 ,
struct V_82 * V_76 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_44 * V_12 = & V_76 -> V_76 . V_12 ;
int V_120 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_76 -> type = V_78 ;
V_12 -> V_43 = V_141 ;
F_40 ( & V_12 -> V_16 , 0 , V_101 , 1 ,
& V_12 -> V_17 , 0 , V_145 , 1 , 0 ) ;
for ( V_120 = 0 ; F_36 ( V_36 ) ; V_120 ++ )
if ( V_36 [ V_120 ] . V_81 == V_12 -> V_13 )
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
if ( V_164 & V_99 )
F_9 ( V_2 , V_167 ,
F_58 ( V_2 -> V_168 -> V_160 ) << 29 , 7 << 29 ) ;
else
F_9 ( V_2 , V_167 , 5 << 29 , 7 << 29 ) ;
V_2 -> V_98 = V_164 ;
return 0 ;
}
static int F_61 ( struct V_67 * V_67 , void * V_68 , T_3 * V_98 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
* V_98 = V_2 -> V_98 ;
return 0 ;
}
static int F_62 ( struct V_67 * V_67 , void * V_169 , struct V_170 * V_171 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_171 -> type = V_78 ;
V_171 -> V_172 = V_2 -> V_94 ;
return 0 ;
}
static int F_63 ( struct V_67 * V_67 , void * V_169 , const struct V_170 * V_171 )
{
struct V_170 V_173 = * V_171 ;
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_93 * V_94 = & V_173 . V_172 ;
struct V_170 V_174 = { . type = V_78 } ;
struct V_44 * V_12 = & V_2 -> V_12 ;
struct V_114 V_115 ;
struct V_133 V_134 = {
. V_135 = V_136 ,
. V_43 = V_137 ,
. V_138 = V_139 ,
} ;
unsigned int V_119 ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_17 , V_41 ,
V_94 -> V_16 , V_94 -> V_17 , V_94 -> V_102 , V_94 -> V_100 ) ;
if ( V_171 -> type != V_78 )
return - V_49 ;
if ( V_2 -> V_98 & V_99 )
V_119 = 480 ;
else
V_119 = 576 ;
F_40 ( & V_94 -> V_16 , 0 , V_101 , 1 ,
& V_94 -> V_17 , 0 , V_119 , 1 , 0 ) ;
if ( V_94 -> V_16 + V_94 -> V_102 > V_101 )
V_94 -> V_102 = V_101 - V_94 -> V_16 ;
if ( V_94 -> V_17 + V_94 -> V_100 > V_119 )
V_94 -> V_100 = V_119 - V_94 -> V_17 ;
V_115 . V_127 = * V_94 ;
V_115 . V_122 = V_12 -> V_16 ;
V_115 . V_123 = V_12 -> V_17 ;
V_174 . V_172 . V_16 = V_115 . V_127 . V_16 ;
V_174 . V_172 . V_17 = V_115 . V_127 . V_17 ;
F_44 ( & V_2 -> V_39 , 0 , V_142 ,
V_175 , & V_174 ) ;
V_134 . V_16 = V_115 . V_127 . V_16 ;
V_134 . V_17 = V_115 . V_127 . V_17 ;
V_46 = F_44 ( & V_2 -> V_39 , 0 , V_142 ,
V_143 , & V_134 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( ( unsigned ) V_134 . V_16 > V_101 ||
( unsigned ) V_134 . V_17 > V_119 ||
V_134 . V_135 != V_136 )
return - V_144 ;
V_115 . V_127 . V_16 = V_134 . V_16 ;
V_115 . V_127 . V_17 = V_134 . V_17 ;
F_39 ( & V_115 , V_2 -> V_98 ) ;
V_2 -> V_94 = V_115 . V_127 ;
V_12 -> V_16 = V_115 . V_122 ;
V_12 -> V_17 = V_115 . V_123 ;
F_38 ( V_2 , V_2 -> V_37 ,
V_115 . V_129 , V_115 . V_132 ) ;
return 0 ;
}
static int F_64 ( struct V_67 * V_67 , void * V_68 ,
struct V_176 * V_171 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_171 -> type = V_78 ;
V_171 -> V_177 . V_102 = 0 ;
V_171 -> V_177 . V_100 = 0 ;
V_171 -> V_177 . V_16 = V_101 ;
V_171 -> V_177 . V_17 = V_145 ;
V_171 -> V_178 . V_102 = 0 ;
V_171 -> V_178 . V_100 = 0 ;
V_171 -> V_178 . V_16 = V_101 ;
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
static int V_186 ;
T_1 V_187 = F_5 ( V_2 , V_61 ) , V_188 ;
T_1 V_189 = F_5 ( V_2 , V_58 ) ;
if ( ! ( V_187 & 0x300 ) ) {
if ( F_66 ( & V_184 , 500 ) )
F_24 ( V_2 -> V_39 . V_40 , L_18 ,
V_187 ) ;
return V_190 ;
}
F_67 ( & V_2 -> V_64 ) ;
if ( ! V_2 -> V_56 || F_68 ( & V_2 -> V_53 ) ) {
if ( F_66 ( & V_184 , 500 ) )
F_24 ( V_2 -> V_39 . V_40 ,
L_19 , V_187 ) ;
F_7 ( V_2 , V_61 , 0 , 0x300 ) ;
F_69 ( & V_2 -> V_64 ) ;
return V_191 ;
}
V_188 = ~ ( 0x300 & V_187 ) & V_187 & 0x30304 ;
F_22 ( V_2 -> V_39 . V_40 ,
L_20 ,
V_187 , V_188 , V_189 , V_185 ) ;
V_185 ++ ;
V_186 = V_189 & 0x10000 ;
F_1 ( V_2 , V_61 , V_188 ) ;
V_9 = V_2 -> V_56 ;
F_30 ( & V_9 -> V_53 ) ;
V_9 -> V_29 = V_192 ;
F_70 ( & V_9 -> V_193 ) ;
V_9 -> V_194 ++ ;
F_71 ( & V_9 -> V_195 ) ;
if ( F_68 ( & V_2 -> V_53 ) ) {
F_22 ( V_2 -> V_39 . V_40 , L_21 ,
V_41 , V_185 ) ;
F_7 ( V_2 , V_62 , 0 , 1 ) ;
V_2 -> V_56 = NULL ;
V_2 -> V_54 = V_196 ;
F_7 ( V_2 , V_61 , 0 , 0x30000 ) ;
F_69 ( & V_2 -> V_64 ) ;
return V_191 ;
}
V_2 -> V_56 = F_72 ( V_2 -> V_53 . V_59 ,
struct V_8 , V_53 ) ;
if ( V_2 -> V_56 -> V_53 . V_59 != & V_2 -> V_53 ) {
struct V_8 * V_197 = F_72 ( V_2 -> V_56 -> V_53 . V_59 ,
struct V_8 , V_53 ) ;
F_10 ( V_2 , V_197 ) ;
}
F_69 ( & V_2 -> V_64 ) ;
return V_191 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_198 * V_168 = V_2 -> V_168 ;
T_1 V_199 = F_58 ( V_168 -> V_160 ) << 29 ;
int V_120 = 100 ;
F_1 ( V_2 , V_61 , 0 ) ;
F_1 ( V_2 , V_200 , 0x101 ) ;
while ( -- V_120 && ( F_5 ( V_2 , V_200 ) & 0x101 ) )
F_74 ( 1 ) ;
if ( ! V_120 )
return - V_201 ;
F_22 ( V_2 -> V_39 . V_40 , L_22 , 100 - V_120 ) ;
if ( V_168 -> V_63 & V_202 )
V_199 |= 1 << 28 ;
if ( V_168 -> V_63 & V_203 )
V_199 |= 1 << 27 ;
if ( V_168 -> V_63 & V_204 )
V_199 |= 1 << 26 ;
F_9 ( V_2 , V_167 , V_199 , 0xfc000000 ) ;
F_1 ( V_2 , V_60 , 4 ) ;
F_3 ( V_2 , V_205 , 0x800000 ) ;
return 0 ;
}
static int F_75 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = F_76 ( sizeof( struct V_148 ) ,
V_206 ) ;
if ( ! V_149 )
return - V_207 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
V_67 -> V_208 = V_149 ;
if ( F_77 ( & V_2 -> V_209 ) )
return - V_210 ;
if ( F_78 ( & V_2 -> V_211 ) == 1 ) {
int V_46 ;
V_2 -> V_54 = V_196 ;
F_79 ( V_2 -> V_39 . V_40 ) ;
V_46 = F_73 ( V_2 ) ;
if ( V_46 < 0 ) {
F_80 ( & V_2 -> V_211 ) ;
F_81 ( V_2 -> V_39 . V_40 ) ;
V_2 -> V_54 = V_212 ;
F_82 ( & V_2 -> V_209 ) ;
return V_46 ;
}
}
F_83 ( & V_149 -> V_150 , & V_213 ,
V_2 -> V_39 . V_40 , & V_2 -> V_64 ,
V_78 ,
V_141 ,
sizeof( struct V_8 ) ,
V_2 -> V_34 , & V_2 -> V_209 ) ;
F_82 ( & V_2 -> V_209 ) ;
return 0 ;
}
static int F_84 ( struct V_67 * V_67 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_67 -> V_208 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( ! F_85 ( & V_2 -> V_211 ) ) {
F_86 ( & V_2 -> V_209 ) ;
V_2 -> V_54 = V_212 ;
F_7 ( V_2 , V_62 , 0 , 0x101 ) ;
F_81 ( V_2 -> V_39 . V_40 ) ;
F_82 ( & V_2 -> V_209 ) ;
}
V_67 -> V_208 = NULL ;
F_87 ( V_149 ) ;
return 0 ;
}
static int F_88 ( struct V_67 * V_67 , struct V_214 * V_215 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_67 -> V_208 ;
int V_46 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
if ( F_77 ( & V_2 -> V_209 ) )
return - V_210 ;
V_46 = F_89 ( & V_149 -> V_150 , V_215 ) ;
F_82 ( & V_2 -> V_209 ) ;
return V_46 ;
}
static unsigned int F_90 ( struct V_67 * V_67 , T_5 * V_216 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
struct V_148 * V_149 = V_67 -> V_208 ;
unsigned int V_217 ;
F_22 ( V_2 -> V_39 . V_40 , L_2 , V_41 ) ;
F_86 ( & V_2 -> V_209 ) ;
V_217 = F_91 ( V_67 , & V_149 -> V_150 , V_216 ) ;
F_82 ( & V_2 -> V_209 ) ;
return V_217 ;
}
static int F_92 ( struct V_67 * V_67 , void * V_169 ,
struct V_218 * V_219 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
return F_44 ( & V_2 -> V_39 , 0 , V_220 , V_221 , V_219 ) ;
}
static int F_93 ( struct V_67 * V_67 , void * V_169 ,
struct V_222 * V_3 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
return F_44 ( & V_2 -> V_39 , 0 , V_220 , V_223 , V_3 ) ;
}
static int F_94 ( struct V_67 * V_67 , void * V_169 ,
const struct V_222 * V_3 )
{
struct V_1 * V_2 = F_33 ( V_67 ) ;
return F_44 ( & V_2 -> V_39 , 0 , V_220 , V_224 , V_3 ) ;
}
static int F_95 ( struct V_225 * V_226 )
{
struct V_198 * V_227 = V_226 -> V_40 . V_228 ;
struct V_93 * V_94 ;
struct V_44 * V_12 ;
struct V_229 * V_230 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_231 * V_232 , * V_233 ;
struct V_234 * V_235 ;
int V_182 , V_46 ;
V_232 = F_96 ( V_226 , V_236 , 0 ) ;
V_182 = F_97 ( V_226 , 0 ) ;
if ( ! V_227 || ! V_232 || V_182 <= 0 ) {
F_98 ( & V_226 -> V_40 , L_23 ) ;
return - V_237 ;
}
V_2 = F_76 ( sizeof( * V_2 ) , V_206 ) ;
if ( ! V_2 )
return - V_207 ;
F_99 ( & V_2 -> V_53 ) ;
F_100 ( & V_2 -> V_64 ) ;
F_101 ( & V_2 -> V_209 ) ;
F_102 ( & V_2 -> V_211 , 0 ) ;
V_2 -> V_168 = V_227 ;
V_2 -> V_54 = V_212 ;
V_94 = & V_2 -> V_94 ;
V_12 = & V_2 -> V_12 ;
V_2 -> V_98 = V_238 . V_239 ;
V_94 -> V_102 = 0 ;
V_94 -> V_100 = 0 ;
V_94 -> V_16 = V_101 ;
V_94 -> V_17 = 480 ;
V_12 -> V_16 = V_101 ;
V_12 -> V_17 = 480 ;
V_12 -> V_13 = V_240 ;
V_12 -> V_43 = V_141 ;
V_12 -> V_241 = V_101 * 2 ;
V_12 -> V_242 = V_101 * 2 * 480 ;
V_12 -> V_138 = V_139 ;
V_233 = F_103 ( V_232 -> V_243 , F_104 ( V_232 ) ,
V_226 -> V_244 ) ;
if ( ! V_233 ) {
F_98 ( & V_226 -> V_40 , L_24 ) ;
V_46 = - V_245 ;
goto V_246;
}
V_2 -> V_5 = F_105 ( V_232 -> V_243 , F_104 ( V_232 ) ) ;
if ( ! V_2 -> V_5 ) {
V_46 = - V_207 ;
goto V_247;
}
V_46 = F_106 ( V_182 , F_65 , 0 , L_25 , V_2 ) ;
if ( V_46 < 0 )
goto V_248;
V_46 = F_107 ( & V_226 -> V_40 , & V_2 -> V_39 ) ;
if ( V_46 < 0 ) {
F_98 ( & V_226 -> V_40 , L_26 ) ;
goto V_249;
}
V_34 = F_108 () ;
if ( V_34 == NULL ) {
V_46 = - V_207 ;
goto V_250;
}
* V_34 = V_238 ;
if ( V_227 -> V_160 == V_161 )
V_34 -> V_165 |= V_251 ;
V_34 -> V_39 = & V_2 -> V_39 ;
V_34 -> V_252 = V_253 ;
V_34 -> V_64 = & V_2 -> V_209 ;
V_2 -> V_34 = V_34 ;
F_109 ( V_34 , V_2 ) ;
F_110 ( & V_226 -> V_40 ) ;
F_111 ( & V_226 -> V_40 ) ;
V_230 = F_112 ( V_227 -> V_230 ) ;
if ( ! V_230 ) {
V_46 = - V_237 ;
goto V_254;
}
V_46 = F_73 ( V_2 ) ;
if ( V_46 < 0 )
goto V_255;
V_235 = F_113 ( & V_2 -> V_39 , V_230 ,
V_227 -> V_256 , NULL ) ;
if ( ! V_235 ) {
V_46 = - V_207 ;
goto V_257;
}
V_46 = F_114 ( V_34 , V_258 , - 1 ) ;
if ( V_46 < 0 )
goto V_259;
return 0 ;
V_259:
V_257:
V_255:
F_115 ( V_230 ) ;
V_254:
V_253 ( V_34 ) ;
F_116 ( & V_226 -> V_40 ) ;
V_250:
F_117 ( & V_2 -> V_39 ) ;
V_249:
F_118 ( V_182 , V_2 ) ;
V_248:
F_119 ( V_2 -> V_5 ) ;
V_247:
F_120 ( V_232 -> V_243 , F_104 ( V_232 ) ) ;
V_246:
F_87 ( V_2 ) ;
return V_46 ;
}
static int F_121 ( struct V_225 * V_226 )
{
int V_182 = F_97 ( V_226 , 0 ) ;
struct V_260 * V_39 = F_122 ( V_226 ) ;
struct V_1 * V_2 = F_123 ( V_39 ,
struct V_1 , V_39 ) ;
struct V_234 * V_261 = F_72 ( V_39 -> V_262 . V_59 ,
struct V_234 , V_263 ) ;
struct V_264 * V_265 = F_124 ( V_261 ) ;
struct V_231 * V_232 ;
if ( V_182 > 0 )
F_118 ( V_182 , V_2 ) ;
F_116 ( & V_226 -> V_40 ) ;
F_125 ( V_2 -> V_34 ) ;
F_115 ( V_265 -> V_266 ) ;
F_117 ( & V_2 -> V_39 ) ;
F_119 ( V_2 -> V_5 ) ;
V_232 = F_96 ( V_226 , V_236 , 0 ) ;
if ( V_232 )
F_120 ( V_232 -> V_243 , F_104 ( V_232 ) ) ;
F_87 ( V_2 ) ;
return 0 ;
}
