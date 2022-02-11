static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( V_2 -> V_6 [ V_4 ] . V_3 == V_3 )
return V_4 ;
F_2 ( V_7 L_1 , V_3 ) ;
return - V_8 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( & V_2 -> V_11 [ V_4 ] . V_12 [ 0 ] == V_10 )
return V_4 ;
F_2 ( V_7 L_2 , V_10 ) ;
return - V_8 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ )
if ( V_2 -> V_16 [ V_14 ] . V_13 == V_13 )
return V_14 ;
F_2 ( V_7 L_3 , V_13 ) ;
return - V_8 ;
}
static int F_5 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_6 ( V_18 ) ;
struct V_1 * V_2 ;
int V_4 ;
V_2 = V_22 -> V_2 ;
V_20 -> type = V_23 ;
V_4 = V_18 -> V_24 ;
V_20 -> V_25 = V_2 -> V_6 [ V_4 ] . V_26 . V_27 ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
struct V_28 * V_29 )
{
struct V_21 * V_22 = F_6 ( V_18 ) ;
struct V_1 * V_2 ;
int V_4 ;
V_2 = V_22 -> V_2 ;
V_4 = V_18 -> V_24 ;
memcpy ( V_29 -> V_30 . V_31 . V_32 ,
V_2 -> V_6 [ V_4 ] . V_26 . V_33 , V_34 ) ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 , int V_4 ,
int V_35 )
{
struct V_17 * V_36 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
V_36 = F_9 ( & V_38 , V_22 ) ;
if ( ! V_36 )
return - V_39 ;
V_36 -> V_24 = V_4 ;
V_36 -> V_40 . V_35 = V_35 ;
V_37 = F_10 ( V_22 , V_2 -> V_6 [ V_4 ] . V_3 , V_36 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
static void F_11 ( struct V_21 * V_22 , T_1 V_3 ,
int * V_41 , int * V_42 )
{
int V_43 ;
V_43 = F_12 ( V_22 , V_3 , 0 ,
V_44 , 0 ) ;
* V_41 = V_43 >> 5 ;
* V_42 = V_43 & 0x1f ;
}
static void F_13 ( struct V_21 * V_22 , T_1 V_3 ,
int V_41 , int V_42 )
{
int V_43 ;
V_43 = ( V_41 << 5 ) | ( V_42 & 0x1f ) ;
F_14 ( V_22 , V_3 , 0 , V_45 , V_43 ) ;
}
static void F_15 ( struct V_21 * V_22 , T_1 V_3 ,
unsigned char V_43 )
{
F_14 ( V_22 , V_3 , 0 , V_46 , V_43 ) ;
}
static void F_16 ( struct V_21 * V_22 , T_1 V_3 )
{
if ( F_17 ( V_22 , V_3 ) & V_47 )
F_14 ( V_22 , V_3 , 0 ,
V_48 , V_49 ) ;
F_14 ( V_22 , V_3 , 0 ,
V_50 , 0 ) ;
}
static int F_18 ( struct V_21 * V_22 , T_1 V_13 )
{
return 1 + F_12 ( V_22 , V_13 , 0 ,
V_51 , 0 ) ;
}
static void F_19 ( struct V_21 * V_22 ,
T_1 V_13 , int V_52 )
{
if ( V_52 != F_18 ( V_22 , V_13 ) )
F_14 ( V_22 , V_13 , 0 ,
V_53 , V_52 - 1 ) ;
}
static void F_20 ( void )
{
int V_54 , V_55 ;
struct V_56 * V_57 ;
for ( V_54 = 0 ; V_54 < F_21 ( V_58 ) ; V_54 ++ ) {
V_57 = V_58 + V_54 ;
V_57 -> V_59 = 0 ;
V_57 -> V_60 = 0 ;
for ( V_55 = 0 ; V_55 < F_21 ( V_57 -> V_61 ) ; V_55 ++ )
if ( V_57 -> V_61 [ V_55 ] ) {
V_57 -> V_59 ++ ;
V_57 -> V_60 |= V_57 -> V_61 [ V_55 ] ;
}
}
}
static int F_22 ( struct V_62 * V_63 , int V_59 )
{
int V_54 ;
int V_64 = 0 ;
int V_60 = 0 ;
char V_65 [ V_66 ] ;
if ( V_59 <= 2 )
return 0 ;
for ( V_54 = 0 ; V_54 < F_21 ( V_67 ) ; V_54 ++ ) {
if ( V_63 -> V_68 & ( 1 << V_54 ) )
V_60 |= V_67 [ V_54 ] ;
}
for ( V_54 = 0 ; V_54 < F_21 ( V_58 ) ; V_54 ++ ) {
if ( V_59 == V_58 [ V_54 ] . V_59 &&
( V_60 & V_58 [ V_54 ] . V_60 ) ==
V_58 [ V_54 ] . V_60 ) {
V_64 = V_58 [ V_54 ] . V_69 ;
break;
}
}
F_23 ( V_63 -> V_68 , V_65 , sizeof( V_65 ) ) ;
F_24 ( L_4 ,
V_64 , V_59 , V_65 ) ;
return V_64 ;
}
static void F_25 ( struct V_21 * V_22 ,
T_1 V_3 )
{
#ifdef F_26
int V_54 ;
int V_70 ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
V_70 = F_12 ( V_22 , V_3 , 0 ,
V_71 , V_54 ) ;
F_27 ( V_72 L_5 ,
V_70 >> 4 , V_70 & 0xf ) ;
}
#endif
}
static void F_28 ( struct V_21 * V_22 ,
T_1 V_3 ,
int V_64 )
{
int V_54 ;
int V_37 ;
if ( V_73 [ V_64 ] [ 1 ] == 0 ) {
for ( V_54 = 0 ; V_54 < V_58 [ V_64 ] . V_59 ; V_54 ++ )
V_73 [ V_64 ] [ V_54 ] = V_54 | ( V_54 << 4 ) ;
for (; V_54 < 8 ; V_54 ++ )
V_73 [ V_64 ] [ V_54 ] = 0xf | ( V_54 << 4 ) ;
}
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
V_37 = F_14 ( V_22 , V_3 , 0 ,
V_74 ,
V_73 [ V_64 ] [ V_54 ] ) ;
if ( V_37 ) {
F_24 ( V_75
L_6 ) ;
break;
}
}
F_25 ( V_22 , V_3 ) ;
}
static void F_29 ( struct V_21 * V_22 ,
T_1 V_3 )
{
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
F_14 ( V_22 , V_3 , 0 , V_76 ,
V_77 ) ;
}
static void F_30 ( struct V_21 * V_22 ,
T_1 V_3 )
{
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
F_14 ( V_22 , V_3 , 0 , V_76 ,
V_78 ) ;
}
static void F_31 ( struct V_21 * V_22 , T_1 V_3 )
{
#ifdef F_26
int V_54 ;
int V_79 ;
V_79 = F_32 ( V_22 , V_3 ) ;
F_27 ( V_72 L_7 , V_79 ) ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
V_79 = F_12 ( V_22 , V_3 , 0 ,
V_80 , V_54 ) ;
F_27 ( V_72 L_8 , V_54 , V_79 ) ;
}
#endif
}
static void F_33 ( struct V_21 * V_22 , T_1 V_3 )
{
#ifdef F_34
int V_54 , V_55 ;
int V_79 ;
int V_81 , V_82 ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
V_79 = F_12 ( V_22 , V_3 , 0 ,
V_80 , V_54 ) ;
if ( V_79 == 0 )
continue;
F_13 ( V_22 , V_3 , V_54 , 0x0 ) ;
for ( V_55 = 1 ; V_55 < 1000 ; V_55 ++ ) {
F_15 ( V_22 , V_3 , 0x0 ) ;
F_11 ( V_22 , V_3 , & V_81 , & V_82 ) ;
if ( V_81 != V_54 )
F_35 ( V_83 L_9 ,
V_82 , V_81 , V_54 ) ;
if ( V_82 == 0 )
break;
}
F_35 ( V_83
L_10 ,
V_54 , V_79 , V_55 ) ;
}
#endif
}
static void F_36 ( struct V_84 * V_85 )
{
T_2 * V_31 = ( T_2 * ) V_85 ;
T_2 V_86 = 0 ;
int V_54 ;
V_85 -> V_87 = 0 ;
for ( V_54 = 0 ; V_54 < sizeof( * V_85 ) ; V_54 ++ )
V_86 += V_31 [ V_54 ] ;
V_85 -> V_87 = - V_86 ;
}
static void F_37 ( struct V_21 * V_22 ,
T_1 V_3 ,
T_2 * V_88 , int V_79 )
{
int V_54 ;
F_31 ( V_22 , V_3 ) ;
F_33 ( V_22 , V_3 ) ;
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
for ( V_54 = 0 ; V_54 < V_79 ; V_54 ++ )
F_15 ( V_22 , V_3 , V_88 [ V_54 ] ) ;
}
static bool F_38 ( struct V_21 * V_22 , T_1 V_3 ,
T_2 * V_88 , int V_79 )
{
T_2 V_43 ;
int V_54 ;
if ( F_12 ( V_22 , V_3 , 0 , V_89 , 0 )
!= V_77 )
return false ;
F_13 ( V_22 , V_3 , 0x0 , 0x0 ) ;
for ( V_54 = 0 ; V_54 < V_79 ; V_54 ++ ) {
V_43 = F_12 ( V_22 , V_3 , 0 ,
V_90 , 0 ) ;
if ( V_43 != V_88 [ V_54 ] )
return false ;
}
return true ;
}
static void F_39 ( struct V_21 * V_22 , int V_4 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_94 -> V_3 ;
int V_59 = V_92 -> V_95 -> V_59 ;
struct V_62 * V_63 ;
int V_64 ;
union V_96 V_97 ;
V_63 = & V_2 -> V_6 [ V_4 ] . V_26 ;
if ( ! V_63 -> V_98 )
return;
V_64 = F_22 ( V_63 , V_59 ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
if ( V_63 -> V_99 == 0 ) {
struct V_84 * V_85 = & V_97 . V_100 ;
V_85 -> type = 0x84 ;
V_85 -> V_101 = 0x01 ;
V_85 -> V_102 = 0x0a ;
V_85 -> V_103 = V_59 - 1 ;
V_85 -> V_104 = V_64 ;
F_36 ( V_85 ) ;
} else if ( V_63 -> V_99 == 1 ) {
struct V_105 * V_106 = & V_97 . V_107 ;
V_106 -> type = 0x84 ;
V_106 -> V_102 = 0x1b ;
V_106 -> V_101 = 0x11 << 2 ;
V_106 -> V_103 = V_59 - 1 ;
V_106 -> V_104 = V_64 ;
} else {
F_35 ( L_11 ,
V_3 ) ;
return;
}
if ( ! F_38 ( V_22 , V_3 , V_97 . V_31 ,
sizeof( V_97 ) ) ) {
F_24 ( L_12
L_13 ,
V_3 ,
V_59 ) ;
F_28 ( V_22 , V_3 , V_64 ) ;
F_30 ( V_22 , V_3 ) ;
F_37 ( V_22 , V_3 ,
V_97 . V_31 , sizeof( V_97 ) ) ;
F_29 ( V_22 , V_3 ) ;
}
}
static void F_40 ( struct V_21 * V_22 , unsigned int V_108 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_109 = V_108 >> V_110 ;
int V_3 ;
int V_111 = ! ! ( V_108 & V_112 ) ;
int V_113 = ! ! ( V_108 & V_114 ) ;
int V_4 ;
struct V_115 * V_116 ;
V_116 = F_41 ( V_22 , V_109 ) ;
if ( ! V_116 )
return;
V_3 = V_116 -> V_117 ;
V_116 -> V_118 = 1 ;
F_27 ( V_83
L_14 ,
V_22 -> V_119 , V_3 , V_111 , V_113 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return;
F_42 ( & V_2 -> V_6 [ V_4 ] , 1 ) ;
F_43 ( V_22 ) ;
}
static void F_44 ( struct V_21 * V_22 , unsigned int V_108 )
{
int V_109 = V_108 >> V_110 ;
int V_120 = ( V_108 & V_121 ) >> V_122 ;
int V_123 = ! ! ( V_108 & V_124 ) ;
int V_125 = ! ! ( V_108 & V_126 ) ;
F_27 ( V_83
L_15 ,
V_22 -> V_119 ,
V_109 ,
V_120 ,
V_123 ,
V_125 ) ;
if ( V_123 )
;
if ( V_125 )
;
}
static void F_45 ( struct V_21 * V_22 , unsigned int V_108 )
{
int V_109 = V_108 >> V_110 ;
int V_120 = ( V_108 & V_121 ) >> V_122 ;
if ( ! F_41 ( V_22 , V_109 ) ) {
F_35 ( V_83 L_16 , V_109 ) ;
return;
}
if ( V_120 == 0 )
F_40 ( V_22 , V_108 ) ;
else
F_44 ( V_22 , V_108 ) ;
}
static int F_46 ( struct V_21 * V_22 , T_1 V_13 ,
T_1 V_3 , T_3 V_127 , int V_128 )
{
int V_129 ;
int V_130 = 0 ;
if ( F_47 ( V_22 , V_3 ) & V_131 ) {
V_129 = F_12 ( V_22 , V_3 , 0 ,
V_132 , 0 ) ;
V_130 = V_129 & ~ V_133 ;
if ( F_48 ( V_128 ) )
V_130 |= V_134 ;
else
V_130 |= V_135 ;
F_24 ( L_17
L_18 ,
V_3 ,
V_129 == V_130 ? L_19 : L_20 ,
V_130 ) ;
if ( V_129 != V_130 )
F_14 ( V_22 , V_3 , 0 ,
V_50 ,
V_130 ) ;
}
if ( F_48 ( V_128 ) && ! V_130 ) {
F_24 ( L_21 ) ;
return - V_8 ;
}
F_49 ( V_22 , V_13 , V_127 , 0 , V_128 ) ;
return 0 ;
}
static int F_50 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_136 * V_95 = V_92 -> V_95 ;
int V_4 , V_14 , V_137 = 0 ;
struct V_93 * V_94 ;
struct V_62 * V_63 ;
struct V_138 * V_139 = NULL ;
int V_129 ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_51 ( V_4 < 0 ) )
return - V_8 ;
V_94 = & V_2 -> V_6 [ V_4 ] ;
V_63 = & V_94 -> V_26 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
V_139 = & V_2 -> V_16 [ V_14 ] ;
if ( V_139 -> V_140 )
continue;
for ( V_137 = 0 ; V_137 < V_94 -> V_141 ; V_137 ++ )
if ( V_94 -> V_142 [ V_137 ] == V_139 -> V_13 )
break;
if ( V_137 == V_94 -> V_141 )
continue;
break;
}
if ( V_14 == V_2 -> V_15 )
return - V_143 ;
V_139 -> V_140 = 1 ;
V_10 -> V_117 = V_139 -> V_13 ;
F_14 ( V_22 , V_94 -> V_3 , 0 ,
V_144 ,
V_137 ) ;
V_129 = F_12 ( V_22 , V_94 -> V_3 , 0 ,
V_132 , 0 ) ;
F_14 ( V_22 , V_94 -> V_3 , 0 ,
V_50 ,
V_129 | V_145 ) ;
F_52 ( V_22 , V_4 , V_139 -> V_13 ) ;
V_10 -> V_146 = V_139 -> V_146 ;
V_10 -> V_147 = V_139 -> V_147 ;
V_10 -> V_148 = V_139 -> V_148 ;
V_10 -> V_149 = V_139 -> V_149 ;
V_10 -> V_150 = V_139 -> V_150 ;
if ( ! V_151 && V_63 -> V_152 ) {
F_53 ( V_63 , V_10 ) ;
if ( V_10 -> V_146 > V_10 -> V_147 ||
! V_10 -> V_148 || ! V_10 -> V_149 )
return - V_143 ;
}
V_95 -> V_153 . V_146 = V_10 -> V_146 ;
V_95 -> V_153 . V_147 = V_10 -> V_147 ;
V_95 -> V_153 . V_149 = V_10 -> V_149 ;
V_95 -> V_153 . V_148 = V_10 -> V_148 ;
F_54 ( V_92 -> V_95 , 0 ,
V_154 , 2 ) ;
return 0 ;
}
static int F_55 ( struct V_21 * V_22 , int V_4 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_94 -> V_3 ;
if ( ! ( F_17 ( V_22 , V_3 ) & V_155 ) ) {
F_2 ( V_7
L_22
L_23 ,
V_3 , F_17 ( V_22 , V_3 ) ) ;
return - V_8 ;
}
V_94 -> V_141 = F_56 ( V_22 , V_3 ,
V_94 -> V_142 ,
V_156 ) ;
return 0 ;
}
static void F_42 ( struct V_93 * V_94 , int V_157 )
{
struct V_21 * V_22 = V_94 -> V_22 ;
struct V_62 * V_63 = & V_94 -> V_26 ;
T_1 V_3 = V_94 -> V_3 ;
int V_158 = F_57 ( V_22 , V_3 ) ;
bool V_152 = false ;
memset ( V_63 , 0 , F_58 ( struct V_62 , V_33 ) ) ;
V_63 -> V_98 = ! ! ( V_158 & V_159 ) ;
if ( V_63 -> V_98 )
V_152 = ! ! ( V_158 & V_160 ) ;
F_27 ( V_83
L_24 ,
V_22 -> V_119 , V_3 , V_63 -> V_98 , V_152 ) ;
if ( V_152 ) {
if ( ! F_59 ( V_63 , V_22 , V_3 ) )
F_60 ( V_63 ) ;
else if ( V_157 ) {
F_61 ( V_22 -> V_161 -> V_162 ,
& V_94 -> V_163 ,
F_62 ( 300 ) ) ;
}
}
}
static void F_63 ( struct V_164 * V_163 )
{
struct V_93 * V_94 =
F_64 ( F_65 ( V_163 ) , struct V_93 , V_163 ) ;
if ( V_94 -> V_165 ++ > 6 )
V_94 -> V_165 = 0 ;
F_42 ( V_94 , V_94 -> V_165 ) ;
}
static int F_66 ( struct V_21 * V_22 , T_1 V_3 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned int V_166 , V_167 ;
int V_4 ;
struct V_93 * V_94 ;
int V_37 ;
V_166 = F_67 ( V_22 , V_3 , V_168 ) ;
if ( ! ( V_166 & ( V_169 | V_170 ) ) )
return 0 ;
V_167 = F_12 ( V_22 , V_3 , 0 ,
V_171 , 0 ) ;
if ( F_68 ( V_167 ) == V_172 )
return 0 ;
if ( F_51 ( V_2 -> V_5 >= V_173 ) )
return - V_174 ;
V_4 = V_2 -> V_5 ;
V_94 = & V_2 -> V_6 [ V_4 ] ;
V_94 -> V_3 = V_3 ;
V_37 = F_55 ( V_22 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_5 ++ ;
return 0 ;
}
static int F_69 ( struct V_21 * V_22 , T_1 V_13 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_14 ;
struct V_138 * V_139 ;
unsigned int V_175 ;
int V_37 ;
if ( F_51 ( V_2 -> V_15 >= V_176 ) )
return - V_174 ;
V_175 = F_17 ( V_22 , V_13 ) ;
V_175 = F_70 ( V_175 ) ;
V_14 = V_2 -> V_15 ;
V_139 = & V_2 -> V_16 [ V_14 ] ;
V_139 -> V_13 = V_13 ;
V_139 -> V_146 = 2 ;
if ( V_175 <= 16 )
V_139 -> V_147 = V_175 ;
V_37 = F_71 ( V_22 , V_13 ,
& V_139 -> V_148 ,
& V_139 -> V_149 ,
& V_139 -> V_150 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_15 ++ ;
return 0 ;
}
static int F_72 ( struct V_21 * V_22 )
{
T_1 V_117 ;
int V_54 , V_177 ;
V_177 = F_73 ( V_22 , V_22 -> V_178 , & V_117 ) ;
if ( ! V_117 || V_177 < 0 ) {
F_2 ( V_7 L_25 ) ;
return - V_8 ;
}
for ( V_54 = 0 ; V_54 < V_177 ; V_54 ++ , V_117 ++ ) {
unsigned int V_166 ;
unsigned int type ;
V_166 = F_67 ( V_22 , V_117 , V_179 ) ;
type = F_74 ( V_166 ) ;
if ( ! ( V_166 & V_180 ) )
continue;
switch ( type ) {
case V_181 :
F_69 ( V_22 , V_117 ) ;
break;
case V_182 :
F_66 ( V_22 , V_117 ) ;
break;
}
}
#ifdef F_75
if ( ! ( F_67 ( V_22 , V_22 -> V_178 , V_183 ) &
V_184 ) )
V_22 -> V_161 -> V_185 = 1 ;
#endif
return 0 ;
}
static char * F_76 ( int V_186 )
{
static char V_187 [ V_173 ] [ 8 ] ;
sprintf ( & V_187 [ V_186 ] [ 0 ] , L_26 , V_186 ) ;
return & V_187 [ V_186 ] [ 0 ] ;
}
static int F_77 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_127 ,
unsigned int V_128 ,
struct V_91 * V_92 )
{
T_1 V_13 = V_10 -> V_117 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = F_3 ( V_2 , V_10 ) ;
T_1 V_3 = V_2 -> V_6 [ V_4 ] . V_3 ;
F_19 ( V_22 , V_13 , V_92 -> V_95 -> V_59 ) ;
F_39 ( V_22 , V_4 , V_92 ) ;
return F_46 ( V_22 , V_13 , V_3 , V_127 , V_128 ) ;
}
static int F_78 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_14 , V_4 ;
struct V_138 * V_139 ;
struct V_93 * V_94 ;
int V_129 ;
F_79 ( V_22 , V_10 -> V_117 ) ;
if ( V_10 -> V_117 ) {
V_14 = F_4 ( V_2 , V_10 -> V_117 ) ;
if ( F_51 ( V_14 < 0 ) )
return - V_8 ;
V_139 = & V_2 -> V_16 [ V_14 ] ;
F_51 ( ! V_139 -> V_140 ) ;
V_139 -> V_140 = 0 ;
V_10 -> V_117 = 0 ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_51 ( V_4 < 0 ) )
return - V_8 ;
V_94 = & V_2 -> V_6 [ V_4 ] ;
V_129 = F_12 ( V_22 , V_94 -> V_3 , 0 ,
V_132 , 0 ) ;
F_14 ( V_22 , V_94 -> V_3 , 0 ,
V_50 ,
V_129 & ~ V_145 ) ;
F_80 ( V_22 , V_4 ) ;
}
return 0 ;
}
static int F_81 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_188 * V_189 ;
struct V_9 * V_190 ;
V_189 = & V_2 -> V_11 [ V_4 ] ;
V_189 -> V_191 = F_76 ( V_4 ) ;
V_189 -> V_192 = V_193 ;
V_190 = & V_189 -> V_12 [ V_194 ] ;
V_190 -> V_195 = 1 ;
V_190 -> V_196 = V_197 ;
}
V_22 -> V_198 = V_2 -> V_5 ;
V_22 -> V_199 = V_2 -> V_11 ;
return 0 ;
}
static int F_82 ( struct V_21 * V_22 , int V_4 )
{
char V_200 [ 32 ] = L_27 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
int V_201 = V_2 -> V_11 [ V_4 ] . V_35 ;
if ( V_201 > 0 )
sprintf ( V_200 + strlen ( V_200 ) , L_28 , V_201 ) ;
return F_83 ( V_22 , V_94 -> V_3 , V_200 , 0 ) ;
}
static int F_84 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
V_37 = F_82 ( V_22 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_85 ( V_22 ,
V_94 -> V_3 ,
V_94 -> V_142 [ 0 ] ) ;
if ( V_37 < 0 )
return V_37 ;
F_80 ( V_22 , V_4 ) ;
V_37 = F_8 ( V_22 ,
V_4 ,
V_2 -> V_11 [ V_4 ] . V_35 ) ;
if ( V_37 < 0 )
return V_37 ;
F_42 ( V_94 , 0 ) ;
}
return 0 ;
}
static int F_86 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_94 -> V_3 ;
struct V_62 * V_63 = & V_94 -> V_26 ;
F_16 ( V_22 , V_3 ) ;
F_87 ( V_22 , V_3 , V_3 ) ;
V_94 -> V_22 = V_22 ;
F_88 ( & V_94 -> V_163 , F_63 ) ;
F_89 ( V_22 , V_63 , V_4 ) ;
}
F_43 ( V_22 ) ;
return 0 ;
}
static void F_90 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
struct V_62 * V_63 = & V_94 -> V_26 ;
F_91 ( & V_94 -> V_163 ) ;
F_92 ( V_22 , V_63 ) ;
}
F_93 ( V_22 -> V_161 -> V_162 ) ;
F_94 ( V_2 ) ;
}
static int F_95 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_96 ( sizeof( * V_2 ) , V_202 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_22 -> V_2 = V_2 ;
if ( F_72 ( V_22 ) < 0 ) {
V_22 -> V_2 = NULL ;
F_94 ( V_2 ) ;
return - V_8 ;
}
V_22 -> V_203 = V_204 ;
F_20 () ;
return 0 ;
}
static int F_97 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_188 * V_189 = V_2 -> V_11 ;
int V_54 ;
V_22 -> V_198 = V_2 -> V_15 ;
V_22 -> V_199 = V_189 ;
for ( V_54 = 0 ; V_54 < V_22 -> V_198 ; V_54 ++ , V_189 ++ ) {
unsigned int V_175 ;
struct V_9 * V_190 ;
V_175 = F_17 ( V_22 , V_2 -> V_16 [ V_54 ] . V_13 ) ;
V_175 = F_70 ( V_175 ) ;
V_189 -> V_191 = F_76 ( V_54 ) ;
V_189 -> V_192 = V_193 ;
V_190 = & V_189 -> V_12 [ V_194 ] ;
F_51 ( ! V_2 -> V_205 ) ;
* V_190 = * V_2 -> V_205 ;
V_190 -> V_117 = V_2 -> V_16 [ V_54 ] . V_13 ;
if ( V_190 -> V_147 <= 2 && V_175 && V_175 <= 16 )
V_190 -> V_147 = V_175 ;
}
return 0 ;
}
static int F_98 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_22 -> V_198 ; V_54 ++ ) {
V_37 = F_85 ( V_22 ,
V_2 -> V_16 [ V_54 ] . V_13 ,
V_2 -> V_16 [ V_54 ] . V_13 ) ;
if ( V_37 < 0 )
return V_37 ;
}
return 0 ;
}
static void F_99 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_94 ( V_2 ) ;
}
static int F_100 ( struct V_21 * V_22 )
{
F_101 ( V_22 , V_206 ) ;
return 0 ;
}
static int F_102 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_207 * V_208 = NULL ;
switch ( V_22 -> V_209 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_208 = & V_210 ;
break;
case 0x10de0007 :
V_208 = & V_211 ;
break;
default:
break;
}
if ( V_208 != NULL ) {
V_207 ( V_92 -> V_95 , 0 ,
V_154 ,
V_208 ) ;
} else {
F_54 ( V_92 -> V_95 , 0 ,
V_154 , 2 ) ;
}
return F_103 ( V_22 , & V_2 -> V_212 ) ;
}
static int F_104 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_105 ( V_22 , & V_2 -> V_212 ) ;
}
static int F_106 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_127 ,
unsigned int V_128 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_107 ( V_22 , & V_2 -> V_212 ,
V_127 , V_128 , V_92 ) ;
}
static void F_108 ( struct V_21 * V_22 ,
int V_59 )
{
unsigned int V_213 ;
int V_214 = V_59 ? ( V_59 - 1 ) : 1 ;
switch ( V_59 ) {
default:
case 0 :
case 2 :
V_213 = 0x00 ;
break;
case 4 :
V_213 = 0x08 ;
break;
case 6 :
V_213 = 0x0b ;
break;
case 8 :
V_213 = 0x13 ;
break;
}
F_14 ( V_22 , 0x1 , 0 ,
V_215 , V_213 ) ;
F_14 ( V_22 , 0x1 , 0 ,
V_216 ,
( 0x71 - V_214 - V_213 ) ) ;
}
static int F_109 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_54 ;
F_14 ( V_22 , V_217 ,
0 , V_218 , 0 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
F_14 ( V_22 , V_219 [ V_54 ] , 0 ,
V_218 , 0 ) ;
F_14 ( V_22 , V_219 [ V_54 ] , 0 ,
V_220 , 0 ) ;
}
F_108 ( V_22 , 8 ) ;
return F_105 ( V_22 , & V_2 -> V_212 ) ;
}
static int F_110 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_127 ,
unsigned int V_128 ,
struct V_91 * V_92 )
{
int V_52 ;
unsigned int V_221 , V_222 ;
int V_54 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_223 * V_224 =
F_111 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 ) ;
F_112 ( & V_22 -> V_225 ) ;
V_52 = V_92 -> V_95 -> V_59 ;
V_221 = 0x2 ;
if ( V_22 -> V_226 && ( V_224 -> V_227 & V_228 ) )
F_14 ( V_22 ,
V_217 ,
0 ,
V_229 ,
V_224 -> V_227 & ~ V_228 & 0xff ) ;
F_14 ( V_22 , V_217 , 0 ,
V_218 , ( V_127 << 4 ) | 0x0 ) ;
F_14 ( V_22 , V_217 , 0 ,
V_220 , V_128 ) ;
if ( V_22 -> V_226 && ( V_224 -> V_227 & V_228 ) ) {
F_14 ( V_22 ,
V_217 ,
0 ,
V_229 ,
V_224 -> V_227 & 0xff ) ;
F_14 ( V_22 ,
V_217 ,
0 ,
V_230 , V_221 ) ;
}
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
if ( V_52 == 2 )
V_222 = 0 ;
else
V_222 = V_54 * 2 ;
if ( V_22 -> V_226 &&
( V_224 -> V_227 & V_228 ) )
F_14 ( V_22 ,
V_219 [ V_54 ] ,
0 ,
V_229 ,
V_224 -> V_227 & ~ V_228 & 0xff ) ;
F_14 ( V_22 ,
V_219 [ V_54 ] ,
0 ,
V_218 ,
( V_127 << 4 ) | V_222 ) ;
F_14 ( V_22 ,
V_219 [ V_54 ] ,
0 ,
V_220 ,
V_128 ) ;
if ( V_22 -> V_226 &&
( V_224 -> V_227 & V_228 ) ) {
F_14 ( V_22 ,
V_219 [ V_54 ] ,
0 ,
V_229 ,
V_224 -> V_227 & 0xff ) ;
F_14 ( V_22 ,
V_219 [ V_54 ] ,
0 ,
V_230 , V_221 ) ;
}
}
F_108 ( V_22 , V_52 ) ;
F_113 ( & V_22 -> V_225 ) ;
return 0 ;
}
static int F_114 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_96 ( sizeof( * V_2 ) , V_202 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_22 -> V_2 = V_2 ;
V_2 -> V_212 . V_231 = 0 ;
V_2 -> V_212 . V_232 = 2 ;
V_2 -> V_212 . V_233 = V_217 ;
V_2 -> V_15 = 1 ;
V_2 -> V_16 [ 0 ] . V_13 = V_217 ;
V_2 -> V_205 = & V_234 ;
V_22 -> V_203 = V_235 ;
return 0 ;
}
static int F_115 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_37 = F_114 ( V_22 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_212 . V_232 = 8 ;
V_2 -> V_205 = & V_236 ;
V_22 -> V_203 = V_237 ;
F_108 ( V_22 , 8 ) ;
return 0 ;
}
static int F_116 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_127 ,
unsigned int V_128 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_175 = V_92 -> V_95 -> V_59 ;
int V_54 , V_37 ;
V_37 = F_106 ( V_10 , V_22 , V_127 , V_128 ,
V_92 ) ;
if ( V_37 < 0 )
return V_37 ;
F_14 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_53 , V_175 - 1 ) ;
for ( V_54 = 0 ; V_54 < V_175 ; V_54 ++ ) {
F_14 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_74 ,
( V_54 << 4 ) | V_54 ) ;
}
return 0 ;
}
static int F_117 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_101 ( V_22 , V_238 ) ;
if ( F_17 ( V_22 , V_2 -> V_6 [ 0 ] . V_3 ) & V_47 )
F_14 ( V_22 , V_2 -> V_6 [ 0 ] . V_3 , 0 ,
V_48 ,
V_49 ) ;
return 0 ;
}
static int F_118 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_96 ( sizeof( * V_2 ) , V_202 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_22 -> V_2 = V_2 ;
V_2 -> V_212 . V_231 = 0 ;
V_2 -> V_212 . V_232 = 2 ;
V_2 -> V_212 . V_233 = V_239 ;
V_2 -> V_15 = 1 ;
V_2 -> V_16 [ 0 ] . V_13 = V_239 ;
V_2 -> V_6 [ 0 ] . V_3 = V_240 ;
V_2 -> V_205 = & V_241 ;
V_22 -> V_203 = V_242 ;
return 0 ;
}
static int T_4 F_119 ( void )
{
return F_120 ( & V_243 ) ;
}
static void T_5 F_121 ( void )
{
F_122 ( & V_243 ) ;
}
