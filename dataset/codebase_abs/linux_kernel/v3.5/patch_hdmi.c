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
int V_4 ;
struct V_111 * V_112 ;
V_112 = F_41 ( V_22 , V_109 ) ;
if ( ! V_112 )
return;
V_3 = V_112 -> V_113 ;
V_112 -> V_114 = 1 ;
F_42 ( V_115 ,
L_14 ,
V_22 -> V_116 , V_3 ,
! ! ( V_108 & V_117 ) , ! ! ( V_108 & V_118 ) ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return;
F_43 ( & V_2 -> V_6 [ V_4 ] , 1 ) ;
F_44 ( V_22 ) ;
}
static void F_45 ( struct V_21 * V_22 , unsigned int V_108 )
{
int V_109 = V_108 >> V_110 ;
int V_119 = ( V_108 & V_120 ) >> V_121 ;
int V_122 = ! ! ( V_108 & V_123 ) ;
int V_124 = ! ! ( V_108 & V_125 ) ;
F_27 ( V_83
L_15 ,
V_22 -> V_116 ,
V_109 ,
V_119 ,
V_122 ,
V_124 ) ;
if ( V_122 )
;
if ( V_124 )
;
}
static void F_46 ( struct V_21 * V_22 , unsigned int V_108 )
{
int V_109 = V_108 >> V_110 ;
int V_119 = ( V_108 & V_120 ) >> V_121 ;
if ( ! F_41 ( V_22 , V_109 ) ) {
F_35 ( V_83 L_16 , V_109 ) ;
return;
}
if ( V_119 == 0 )
F_40 ( V_22 , V_108 ) ;
else
F_45 ( V_22 , V_108 ) ;
}
static int F_47 ( struct V_21 * V_22 , T_1 V_13 ,
T_1 V_3 , T_3 V_126 , int V_127 )
{
int V_128 ;
int V_129 = 0 ;
if ( F_48 ( V_22 , V_3 ) & V_130 ) {
V_128 = F_12 ( V_22 , V_3 , 0 ,
V_131 , 0 ) ;
V_129 = V_128 & ~ V_132 ;
if ( F_49 ( V_127 ) )
V_129 |= V_133 ;
else
V_129 |= V_134 ;
F_24 ( L_17
L_18 ,
V_3 ,
V_128 == V_129 ? L_19 : L_20 ,
V_129 ) ;
if ( V_128 != V_129 )
F_14 ( V_22 , V_3 , 0 ,
V_50 ,
V_129 ) ;
}
if ( F_49 ( V_127 ) && ! V_129 ) {
F_24 ( L_21 ) ;
return - V_8 ;
}
F_50 ( V_22 , V_13 , V_126 , 0 , V_127 ) ;
return 0 ;
}
static int F_51 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_135 * V_95 = V_92 -> V_95 ;
int V_4 , V_14 , V_136 = 0 ;
struct V_93 * V_94 ;
struct V_62 * V_63 ;
struct V_137 * V_138 = NULL ;
int V_128 ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_52 ( V_4 < 0 ) )
return - V_8 ;
V_94 = & V_2 -> V_6 [ V_4 ] ;
V_63 = & V_94 -> V_26 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
V_138 = & V_2 -> V_16 [ V_14 ] ;
if ( V_138 -> V_139 )
continue;
for ( V_136 = 0 ; V_136 < V_94 -> V_140 ; V_136 ++ )
if ( V_94 -> V_141 [ V_136 ] == V_138 -> V_13 )
break;
if ( V_136 == V_94 -> V_140 )
continue;
break;
}
if ( V_14 == V_2 -> V_15 )
return - V_142 ;
V_138 -> V_139 = 1 ;
V_10 -> V_113 = V_138 -> V_13 ;
F_14 ( V_22 , V_94 -> V_3 , 0 ,
V_143 ,
V_136 ) ;
V_128 = F_12 ( V_22 , V_94 -> V_3 , 0 ,
V_131 , 0 ) ;
F_14 ( V_22 , V_94 -> V_3 , 0 ,
V_50 ,
V_128 | V_144 ) ;
F_53 ( V_22 , V_4 , V_138 -> V_13 ) ;
V_10 -> V_145 = V_138 -> V_145 ;
V_10 -> V_146 = V_138 -> V_146 ;
V_10 -> V_147 = V_138 -> V_147 ;
V_10 -> V_148 = V_138 -> V_148 ;
V_10 -> V_149 = V_138 -> V_149 ;
if ( ! V_150 && V_63 -> V_151 ) {
F_54 ( V_63 , V_10 ) ;
if ( V_10 -> V_145 > V_10 -> V_146 ||
! V_10 -> V_147 || ! V_10 -> V_148 )
return - V_142 ;
}
V_95 -> V_152 . V_145 = V_10 -> V_145 ;
V_95 -> V_152 . V_146 = V_10 -> V_146 ;
V_95 -> V_152 . V_148 = V_10 -> V_148 ;
V_95 -> V_152 . V_147 = V_10 -> V_147 ;
F_55 ( V_92 -> V_95 , 0 ,
V_153 , 2 ) ;
return 0 ;
}
static int F_56 ( struct V_21 * V_22 , int V_4 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_94 -> V_3 ;
if ( ! ( F_17 ( V_22 , V_3 ) & V_154 ) ) {
F_2 ( V_7
L_22
L_23 ,
V_3 , F_17 ( V_22 , V_3 ) ) ;
return - V_8 ;
}
V_94 -> V_140 = F_57 ( V_22 , V_3 ,
V_94 -> V_141 ,
V_155 ) ;
return 0 ;
}
static void F_43 ( struct V_93 * V_94 , int V_156 )
{
struct V_21 * V_22 = V_94 -> V_22 ;
struct V_62 * V_63 = & V_94 -> V_26 ;
T_1 V_3 = V_94 -> V_3 ;
int V_157 = F_58 ( V_22 , V_3 ) ;
bool V_151 = false ;
memset ( V_63 , 0 , F_59 ( struct V_62 , V_33 ) ) ;
V_63 -> V_98 = ! ! ( V_157 & V_158 ) ;
if ( V_63 -> V_98 )
V_151 = ! ! ( V_157 & V_159 ) ;
F_42 ( V_115 ,
L_24 ,
V_22 -> V_116 , V_3 , V_63 -> V_98 , V_151 ) ;
if ( V_151 ) {
if ( ! F_60 ( V_63 , V_22 , V_3 ) )
F_61 ( V_63 ) ;
else if ( V_156 ) {
F_62 ( V_22 -> V_160 -> V_161 ,
& V_94 -> V_162 ,
F_63 ( 300 ) ) ;
}
}
}
static void F_64 ( struct V_163 * V_162 )
{
struct V_93 * V_94 =
F_65 ( F_66 ( V_162 ) , struct V_93 , V_162 ) ;
if ( V_94 -> V_164 ++ > 6 )
V_94 -> V_164 = 0 ;
F_43 ( V_94 , V_94 -> V_164 ) ;
}
static int F_67 ( struct V_21 * V_22 , T_1 V_3 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned int V_165 , V_166 ;
int V_4 ;
struct V_93 * V_94 ;
int V_37 ;
V_165 = F_68 ( V_22 , V_3 , V_167 ) ;
if ( ! ( V_165 & ( V_168 | V_169 ) ) )
return 0 ;
V_166 = F_12 ( V_22 , V_3 , 0 ,
V_170 , 0 ) ;
if ( F_69 ( V_166 ) == V_171 )
return 0 ;
if ( F_52 ( V_2 -> V_5 >= V_172 ) )
return - V_173 ;
V_4 = V_2 -> V_5 ;
V_94 = & V_2 -> V_6 [ V_4 ] ;
V_94 -> V_3 = V_3 ;
V_37 = F_56 ( V_22 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_5 ++ ;
return 0 ;
}
static int F_70 ( struct V_21 * V_22 , T_1 V_13 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_14 ;
struct V_137 * V_138 ;
unsigned int V_174 ;
int V_37 ;
if ( F_52 ( V_2 -> V_15 >= V_175 ) )
return - V_173 ;
V_174 = F_17 ( V_22 , V_13 ) ;
V_174 = F_71 ( V_174 ) ;
V_14 = V_2 -> V_15 ;
V_138 = & V_2 -> V_16 [ V_14 ] ;
V_138 -> V_13 = V_13 ;
V_138 -> V_145 = 2 ;
if ( V_174 <= 16 )
V_138 -> V_146 = V_174 ;
V_37 = F_72 ( V_22 , V_13 ,
& V_138 -> V_147 ,
& V_138 -> V_148 ,
& V_138 -> V_149 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_15 ++ ;
return 0 ;
}
static int F_73 ( struct V_21 * V_22 )
{
T_1 V_113 ;
int V_54 , V_176 ;
V_176 = F_74 ( V_22 , V_22 -> V_177 , & V_113 ) ;
if ( ! V_113 || V_176 < 0 ) {
F_2 ( V_7 L_25 ) ;
return - V_8 ;
}
for ( V_54 = 0 ; V_54 < V_176 ; V_54 ++ , V_113 ++ ) {
unsigned int V_165 ;
unsigned int type ;
V_165 = F_68 ( V_22 , V_113 , V_178 ) ;
type = F_75 ( V_165 ) ;
if ( ! ( V_165 & V_179 ) )
continue;
switch ( type ) {
case V_180 :
F_70 ( V_22 , V_113 ) ;
break;
case V_181 :
F_67 ( V_22 , V_113 ) ;
break;
}
}
#ifdef F_76
if ( ! ( F_68 ( V_22 , V_22 -> V_177 , V_182 ) &
V_183 ) )
V_22 -> V_160 -> V_184 = 1 ;
#endif
return 0 ;
}
static char * F_77 ( int V_185 )
{
static char V_186 [ V_172 ] [ 8 ] ;
sprintf ( & V_186 [ V_185 ] [ 0 ] , L_26 , V_185 ) ;
return & V_186 [ V_185 ] [ 0 ] ;
}
static int F_78 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_126 ,
unsigned int V_127 ,
struct V_91 * V_92 )
{
T_1 V_13 = V_10 -> V_113 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 = F_3 ( V_2 , V_10 ) ;
T_1 V_3 = V_2 -> V_6 [ V_4 ] . V_3 ;
F_19 ( V_22 , V_13 , V_92 -> V_95 -> V_59 ) ;
F_39 ( V_22 , V_4 , V_92 ) ;
return F_47 ( V_22 , V_13 , V_3 , V_126 , V_127 ) ;
}
static int F_79 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_14 , V_4 ;
struct V_137 * V_138 ;
struct V_93 * V_94 ;
int V_128 ;
F_80 ( V_22 , V_10 -> V_113 ) ;
if ( V_10 -> V_113 ) {
V_14 = F_4 ( V_2 , V_10 -> V_113 ) ;
if ( F_52 ( V_14 < 0 ) )
return - V_8 ;
V_138 = & V_2 -> V_16 [ V_14 ] ;
F_52 ( ! V_138 -> V_139 ) ;
V_138 -> V_139 = 0 ;
V_10 -> V_113 = 0 ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_52 ( V_4 < 0 ) )
return - V_8 ;
V_94 = & V_2 -> V_6 [ V_4 ] ;
V_128 = F_12 ( V_22 , V_94 -> V_3 , 0 ,
V_131 , 0 ) ;
F_14 ( V_22 , V_94 -> V_3 , 0 ,
V_50 ,
V_128 & ~ V_144 ) ;
F_81 ( V_22 , V_4 ) ;
}
return 0 ;
}
static int F_82 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_187 * V_188 ;
struct V_9 * V_189 ;
V_188 = & V_2 -> V_11 [ V_4 ] ;
V_188 -> V_190 = F_77 ( V_4 ) ;
V_188 -> V_191 = V_192 ;
V_189 = & V_188 -> V_12 [ V_193 ] ;
V_189 -> V_194 = 1 ;
V_189 -> V_195 = V_196 ;
}
V_22 -> V_197 = V_2 -> V_5 ;
V_22 -> V_198 = V_2 -> V_11 ;
return 0 ;
}
static int F_83 ( struct V_21 * V_22 , int V_4 )
{
char V_199 [ 32 ] = L_27 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
int V_200 = V_2 -> V_11 [ V_4 ] . V_35 ;
if ( V_200 > 0 )
sprintf ( V_199 + strlen ( V_199 ) , L_28 , V_200 ) ;
return F_84 ( V_22 , V_94 -> V_3 , V_199 , 0 ) ;
}
static int F_85 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
V_37 = F_83 ( V_22 , V_4 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_86 ( V_22 ,
V_94 -> V_3 ,
V_94 -> V_141 [ 0 ] ) ;
if ( V_37 < 0 )
return V_37 ;
F_81 ( V_22 , V_4 ) ;
V_37 = F_8 ( V_22 ,
V_4 ,
V_2 -> V_11 [ V_4 ] . V_35 ) ;
if ( V_37 < 0 )
return V_37 ;
F_43 ( V_94 , 0 ) ;
}
return 0 ;
}
static int F_87 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_94 -> V_3 ;
struct V_62 * V_63 = & V_94 -> V_26 ;
F_16 ( V_22 , V_3 ) ;
F_88 ( V_22 , V_3 , V_3 ) ;
V_94 -> V_22 = V_22 ;
F_89 ( & V_94 -> V_162 , F_64 ) ;
F_90 ( V_22 , V_63 , V_4 ) ;
}
F_44 ( V_22 ) ;
return 0 ;
}
static void F_91 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_93 * V_94 = & V_2 -> V_6 [ V_4 ] ;
struct V_62 * V_63 = & V_94 -> V_26 ;
F_92 ( & V_94 -> V_162 ) ;
F_93 ( V_22 , V_63 ) ;
}
F_94 ( V_22 -> V_160 -> V_161 ) ;
F_95 ( V_2 ) ;
}
static int F_96 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_97 ( sizeof( * V_2 ) , V_201 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_22 -> V_2 = V_2 ;
if ( F_73 ( V_22 ) < 0 ) {
V_22 -> V_2 = NULL ;
F_95 ( V_2 ) ;
return - V_8 ;
}
V_22 -> V_202 = V_203 ;
F_20 () ;
return 0 ;
}
static int F_98 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_187 * V_188 = V_2 -> V_11 ;
int V_54 ;
V_22 -> V_197 = V_2 -> V_15 ;
V_22 -> V_198 = V_188 ;
for ( V_54 = 0 ; V_54 < V_22 -> V_197 ; V_54 ++ , V_188 ++ ) {
unsigned int V_174 ;
struct V_9 * V_189 ;
V_174 = F_17 ( V_22 , V_2 -> V_16 [ V_54 ] . V_13 ) ;
V_174 = F_71 ( V_174 ) ;
V_188 -> V_190 = F_77 ( V_54 ) ;
V_188 -> V_191 = V_192 ;
V_189 = & V_188 -> V_12 [ V_193 ] ;
F_52 ( ! V_2 -> V_204 ) ;
* V_189 = * V_2 -> V_204 ;
V_189 -> V_113 = V_2 -> V_16 [ V_54 ] . V_13 ;
if ( V_189 -> V_146 <= 2 && V_174 && V_174 <= 16 )
V_189 -> V_146 = V_174 ;
}
return 0 ;
}
static int F_99 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_37 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_22 -> V_197 ; V_54 ++ ) {
V_37 = F_86 ( V_22 ,
V_2 -> V_16 [ V_54 ] . V_13 ,
V_2 -> V_16 [ V_54 ] . V_13 ) ;
if ( V_37 < 0 )
return V_37 ;
}
return 0 ;
}
static void F_100 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_95 ( V_2 ) ;
}
static int F_101 ( struct V_21 * V_22 )
{
F_102 ( V_22 , V_205 ) ;
return 0 ;
}
static int F_103 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_206 * V_207 = NULL ;
switch ( V_22 -> V_208 -> V_40 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_207 = & V_209 ;
break;
case 0x10de0007 :
V_207 = & V_210 ;
break;
default:
break;
}
if ( V_207 != NULL ) {
V_206 ( V_92 -> V_95 , 0 ,
V_153 ,
V_207 ) ;
} else {
F_55 ( V_92 -> V_95 , 0 ,
V_153 , 2 ) ;
}
return F_104 ( V_22 , & V_2 -> V_211 ) ;
}
static int F_105 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_106 ( V_22 , & V_2 -> V_211 ) ;
}
static int F_107 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_126 ,
unsigned int V_127 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
return F_108 ( V_22 , & V_2 -> V_211 ,
V_126 , V_127 , V_92 ) ;
}
static void F_109 ( struct V_21 * V_22 ,
int V_59 )
{
unsigned int V_212 ;
int V_213 = V_59 ? ( V_59 - 1 ) : 1 ;
switch ( V_59 ) {
default:
case 0 :
case 2 :
V_212 = 0x00 ;
break;
case 4 :
V_212 = 0x08 ;
break;
case 6 :
V_212 = 0x0b ;
break;
case 8 :
V_212 = 0x13 ;
break;
}
F_14 ( V_22 , 0x1 , 0 ,
V_214 , V_212 ) ;
F_14 ( V_22 , 0x1 , 0 ,
V_215 ,
( 0x71 - V_213 - V_212 ) ) ;
}
static int F_110 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_54 ;
F_14 ( V_22 , V_216 ,
0 , V_217 , 0 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
F_14 ( V_22 , V_218 [ V_54 ] , 0 ,
V_217 , 0 ) ;
F_14 ( V_22 , V_218 [ V_54 ] , 0 ,
V_219 , 0 ) ;
}
F_109 ( V_22 , 8 ) ;
return F_106 ( V_22 , & V_2 -> V_211 ) ;
}
static int F_111 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_126 ,
unsigned int V_127 ,
struct V_91 * V_92 )
{
int V_52 ;
unsigned int V_220 , V_221 ;
int V_54 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_222 * V_223 ;
F_112 ( & V_22 -> V_224 ) ;
V_223 = F_113 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 ) ;
V_52 = V_92 -> V_95 -> V_59 ;
V_220 = 0x2 ;
if ( V_22 -> V_225 && ( V_223 -> V_226 & V_227 ) )
F_14 ( V_22 ,
V_216 ,
0 ,
V_228 ,
V_223 -> V_226 & ~ V_227 & 0xff ) ;
F_14 ( V_22 , V_216 , 0 ,
V_217 , ( V_126 << 4 ) | 0x0 ) ;
F_14 ( V_22 , V_216 , 0 ,
V_219 , V_127 ) ;
if ( V_22 -> V_225 && ( V_223 -> V_226 & V_227 ) ) {
F_14 ( V_22 ,
V_216 ,
0 ,
V_228 ,
V_223 -> V_226 & 0xff ) ;
F_14 ( V_22 ,
V_216 ,
0 ,
V_229 , V_220 ) ;
}
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
if ( V_52 == 2 )
V_221 = 0 ;
else
V_221 = V_54 * 2 ;
if ( V_22 -> V_225 &&
( V_223 -> V_226 & V_227 ) )
F_14 ( V_22 ,
V_218 [ V_54 ] ,
0 ,
V_228 ,
V_223 -> V_226 & ~ V_227 & 0xff ) ;
F_14 ( V_22 ,
V_218 [ V_54 ] ,
0 ,
V_217 ,
( V_126 << 4 ) | V_221 ) ;
F_14 ( V_22 ,
V_218 [ V_54 ] ,
0 ,
V_219 ,
V_127 ) ;
if ( V_22 -> V_225 &&
( V_223 -> V_226 & V_227 ) ) {
F_14 ( V_22 ,
V_218 [ V_54 ] ,
0 ,
V_228 ,
V_223 -> V_226 & 0xff ) ;
F_14 ( V_22 ,
V_218 [ V_54 ] ,
0 ,
V_229 , V_220 ) ;
}
}
F_109 ( V_22 , V_52 ) ;
F_114 ( & V_22 -> V_224 ) ;
return 0 ;
}
static int F_115 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_97 ( sizeof( * V_2 ) , V_201 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_22 -> V_2 = V_2 ;
V_2 -> V_211 . V_230 = 0 ;
V_2 -> V_211 . V_231 = 2 ;
V_2 -> V_211 . V_232 = V_216 ;
V_2 -> V_15 = 1 ;
V_2 -> V_16 [ 0 ] . V_13 = V_216 ;
V_2 -> V_204 = & V_233 ;
V_22 -> V_202 = V_234 ;
return 0 ;
}
static int F_116 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_37 = F_115 ( V_22 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = V_22 -> V_2 ;
V_2 -> V_211 . V_231 = 8 ;
V_2 -> V_204 = & V_235 ;
V_22 -> V_202 = V_236 ;
F_109 ( V_22 , 8 ) ;
return 0 ;
}
static int F_117 ( struct V_9 * V_10 ,
struct V_21 * V_22 ,
unsigned int V_126 ,
unsigned int V_127 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_174 = V_92 -> V_95 -> V_59 ;
int V_54 , V_37 ;
V_37 = F_107 ( V_10 , V_22 , V_126 , V_127 ,
V_92 ) ;
if ( V_37 < 0 )
return V_37 ;
F_14 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_53 , V_174 - 1 ) ;
for ( V_54 = 0 ; V_54 < V_174 ; V_54 ++ ) {
F_14 ( V_22 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_74 ,
( V_54 << 4 ) | V_54 ) ;
}
return 0 ;
}
static int F_118 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_102 ( V_22 , V_237 ) ;
if ( F_17 ( V_22 , V_2 -> V_6 [ 0 ] . V_3 ) & V_47 )
F_14 ( V_22 , V_2 -> V_6 [ 0 ] . V_3 , 0 ,
V_48 ,
V_49 ) ;
return 0 ;
}
static int F_119 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_97 ( sizeof( * V_2 ) , V_201 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_22 -> V_2 = V_2 ;
V_2 -> V_211 . V_230 = 0 ;
V_2 -> V_211 . V_231 = 2 ;
V_2 -> V_211 . V_232 = V_238 ;
V_2 -> V_15 = 1 ;
V_2 -> V_16 [ 0 ] . V_13 = V_238 ;
V_2 -> V_6 [ 0 ] . V_3 = V_239 ;
V_2 -> V_204 = & V_240 ;
V_22 -> V_202 = V_241 ;
return 0 ;
}
static int T_4 F_120 ( void )
{
return F_121 ( & V_242 ) ;
}
static void T_5 F_122 ( void )
{
F_123 ( & V_242 ) ;
}
