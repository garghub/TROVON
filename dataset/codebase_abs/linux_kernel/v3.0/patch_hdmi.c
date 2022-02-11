static int F_1 ( T_1 * V_1 , T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_1 [ V_3 ] ; V_3 ++ )
if ( V_1 [ V_3 ] == V_2 )
return V_3 ;
F_2 ( V_4 L_1 , V_2 ) ;
return - V_5 ;
}
static void F_3 ( struct V_6 * V_7 , T_1 V_8 ,
int * V_9 , int * V_10 )
{
int V_11 ;
V_11 = F_4 ( V_7 , V_8 , 0 ,
V_12 , 0 ) ;
* V_9 = V_11 >> 5 ;
* V_10 = V_11 & 0x1f ;
}
static void F_5 ( struct V_6 * V_7 , T_1 V_8 ,
int V_9 , int V_10 )
{
int V_11 ;
V_11 = ( V_9 << 5 ) | ( V_10 & 0x1f ) ;
F_6 ( V_7 , V_8 , 0 , V_13 , V_11 ) ;
}
static void F_7 ( struct V_6 * V_7 , T_1 V_8 ,
unsigned char V_11 )
{
F_6 ( V_7 , V_8 , 0 , V_14 , V_11 ) ;
}
static void F_8 ( struct V_6 * V_7 , T_1 V_8 )
{
if ( F_9 ( V_7 , V_8 ) & V_15 )
F_6 ( V_7 , V_8 , 0 ,
V_16 , V_17 ) ;
F_6 ( V_7 , V_8 , 0 ,
V_18 , V_19 ) ;
}
static int F_10 ( struct V_6 * V_7 , T_1 V_2 )
{
return 1 + F_4 ( V_7 , V_2 , 0 ,
V_20 , 0 ) ;
}
static void F_11 ( struct V_6 * V_7 ,
T_1 V_2 , int V_21 )
{
if ( V_21 != F_10 ( V_7 , V_2 ) )
F_6 ( V_7 , V_2 , 0 ,
V_22 , V_21 - 1 ) ;
}
static void F_12 ( void )
{
int V_3 , V_23 ;
struct V_24 * V_25 ;
for ( V_3 = 0 ; V_3 < F_13 ( V_26 ) ; V_3 ++ ) {
V_25 = V_26 + V_3 ;
V_25 -> V_27 = 0 ;
V_25 -> V_28 = 0 ;
for ( V_23 = 0 ; V_23 < F_13 ( V_25 -> V_29 ) ; V_23 ++ )
if ( V_25 -> V_29 [ V_23 ] ) {
V_25 -> V_27 ++ ;
V_25 -> V_28 |= V_25 -> V_29 [ V_23 ] ;
}
}
}
static int F_14 ( struct V_6 * V_7 , T_1 V_2 ,
int V_27 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
struct V_32 * V_33 ;
int V_3 ;
int V_34 = 0 ;
int V_28 = 0 ;
char V_35 [ V_36 ] ;
if ( V_27 <= 2 )
return 0 ;
V_3 = F_1 ( V_31 -> V_37 , V_2 ) ;
if ( V_3 < 0 )
return 0 ;
V_33 = & V_31 -> V_38 [ V_3 ] ;
if ( ! V_33 -> V_39 )
V_33 -> V_39 = 0xffff ;
for ( V_3 = 0 ; V_3 < F_13 ( V_40 ) ; V_3 ++ ) {
if ( V_33 -> V_39 & ( 1 << V_3 ) )
V_28 |= V_40 [ V_3 ] ;
}
for ( V_3 = 0 ; V_3 < F_13 ( V_26 ) ; V_3 ++ ) {
if ( V_27 == V_26 [ V_3 ] . V_27 &&
( V_28 & V_26 [ V_3 ] . V_28 ) ==
V_26 [ V_3 ] . V_28 ) {
V_34 = V_26 [ V_3 ] . V_41 ;
break;
}
}
F_15 ( V_33 -> V_39 , V_35 , sizeof( V_35 ) ) ;
F_16 ( L_2 ,
V_34 , V_27 , V_35 ) ;
return V_34 ;
}
static void F_17 ( struct V_6 * V_7 ,
T_1 V_8 )
{
#ifdef F_18
int V_3 ;
int V_42 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_42 = F_4 ( V_7 , V_8 , 0 ,
V_43 , V_3 ) ;
F_19 ( V_44 L_3 ,
V_42 >> 4 , V_42 & 0xf ) ;
}
#endif
}
static void F_20 ( struct V_6 * V_7 ,
T_1 V_8 ,
int V_34 )
{
int V_3 ;
int V_45 ;
if ( V_46 [ V_34 ] [ 1 ] == 0 ) {
for ( V_3 = 0 ; V_3 < V_26 [ V_34 ] . V_27 ; V_3 ++ )
V_46 [ V_34 ] [ V_3 ] = V_3 | ( V_3 << 4 ) ;
for (; V_3 < 8 ; V_3 ++ )
V_46 [ V_34 ] [ V_3 ] = 0xf | ( V_3 << 4 ) ;
}
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_45 = F_6 ( V_7 , V_8 , 0 ,
V_47 ,
V_46 [ V_34 ] [ V_3 ] ) ;
if ( V_45 ) {
F_16 ( V_48
L_4 ) ;
break;
}
}
F_17 ( V_7 , V_8 ) ;
}
static void F_21 ( struct V_6 * V_7 ,
T_1 V_8 )
{
F_5 ( V_7 , V_8 , 0x0 , 0x0 ) ;
F_6 ( V_7 , V_8 , 0 , V_49 ,
V_50 ) ;
}
static void F_22 ( struct V_6 * V_7 ,
T_1 V_8 )
{
F_5 ( V_7 , V_8 , 0x0 , 0x0 ) ;
F_6 ( V_7 , V_8 , 0 , V_49 ,
V_51 ) ;
}
static void F_23 ( struct V_6 * V_7 , T_1 V_8 )
{
#ifdef F_18
int V_3 ;
int V_52 ;
V_52 = F_24 ( V_7 , V_8 ) ;
F_19 ( V_44 L_5 , V_52 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_52 = F_4 ( V_7 , V_8 , 0 ,
V_53 , V_3 ) ;
F_19 ( V_44 L_6 , V_3 , V_52 ) ;
}
#endif
}
static void F_25 ( struct V_6 * V_7 , T_1 V_8 )
{
#ifdef F_26
int V_3 , V_23 ;
int V_52 ;
int V_54 , V_55 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_52 = F_4 ( V_7 , V_8 , 0 ,
V_53 , V_3 ) ;
if ( V_52 == 0 )
continue;
F_5 ( V_7 , V_8 , V_3 , 0x0 ) ;
for ( V_23 = 1 ; V_23 < 1000 ; V_23 ++ ) {
F_7 ( V_7 , V_8 , 0x0 ) ;
F_3 ( V_7 , V_8 , & V_54 , & V_55 ) ;
if ( V_54 != V_3 )
F_27 ( V_56 L_7 ,
V_55 , V_54 , V_3 ) ;
if ( V_55 == 0 )
break;
}
F_27 ( V_56
L_8 ,
V_3 , V_52 , V_23 ) ;
}
#endif
}
static void F_28 ( struct V_57 * V_58 )
{
T_2 * V_59 = ( T_2 * ) V_58 ;
T_2 V_60 = 0 ;
int V_3 ;
V_58 -> V_61 = 0 ;
for ( V_3 = 0 ; V_3 < sizeof( * V_58 ) ; V_3 ++ )
V_60 += V_59 [ V_3 ] ;
V_58 -> V_61 = - V_60 ;
}
static void F_29 ( struct V_6 * V_7 ,
T_1 V_8 ,
T_2 * V_62 , int V_52 )
{
int V_3 ;
F_23 ( V_7 , V_8 ) ;
F_25 ( V_7 , V_8 ) ;
F_5 ( V_7 , V_8 , 0x0 , 0x0 ) ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
F_7 ( V_7 , V_8 , V_62 [ V_3 ] ) ;
}
static bool F_30 ( struct V_6 * V_7 , T_1 V_8 ,
T_2 * V_62 , int V_52 )
{
T_2 V_11 ;
int V_3 ;
if ( F_4 ( V_7 , V_8 , 0 , V_63 , 0 )
!= V_50 )
return false ;
F_5 ( V_7 , V_8 , 0x0 , 0x0 ) ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ ) {
V_11 = F_4 ( V_7 , V_8 , 0 ,
V_64 , 0 ) ;
if ( V_11 != V_62 [ V_3 ] )
return false ;
}
return true ;
}
static void F_31 ( struct V_6 * V_7 , T_1 V_2 ,
struct V_65 * V_66 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
T_1 V_8 ;
int V_27 = V_66 -> V_67 -> V_27 ;
int V_34 ;
int V_3 ;
union V_68 V_69 ;
V_34 = F_14 ( V_7 , V_2 , V_27 ) ;
for ( V_3 = 0 ; V_3 < V_31 -> V_70 ; V_3 ++ ) {
if ( V_31 -> V_37 [ V_3 ] != V_2 )
continue;
if ( ! V_31 -> V_38 [ V_3 ] . V_71 )
continue;
V_8 = V_31 -> V_72 [ V_3 ] ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_31 -> V_38 [ V_3 ] . V_73 == 0 ) {
struct V_57 * V_58 = & V_69 . V_74 ;
V_58 -> type = 0x84 ;
V_58 -> V_75 = 0x01 ;
V_58 -> V_76 = 0x0a ;
V_58 -> V_77 = V_27 - 1 ;
V_58 -> V_78 = V_34 ;
F_28 ( V_58 ) ;
} else if ( V_31 -> V_38 [ V_3 ] . V_73 == 1 ) {
struct V_79 * V_80 = & V_69 . V_81 ;
V_80 -> type = 0x84 ;
V_80 -> V_76 = 0x1b ;
V_80 -> V_75 = 0x11 << 2 ;
V_80 -> V_77 = V_27 - 1 ;
V_80 -> V_78 = V_34 ;
} else {
F_27 ( L_9 ,
V_8 ) ;
continue;
}
if ( ! F_30 ( V_7 , V_8 , V_69 . V_59 ,
sizeof( V_69 ) ) ) {
F_16 ( L_10
L_11 ,
V_2 , V_8 ,
V_27 ) ;
F_20 ( V_7 , V_8 , V_34 ) ;
F_22 ( V_7 , V_8 ) ;
F_29 ( V_7 , V_8 ,
V_69 . V_59 , sizeof( V_69 ) ) ;
F_21 ( V_7 , V_8 ) ;
}
}
}
static void F_32 ( struct V_6 * V_7 , unsigned int V_82 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
int V_8 = V_82 >> V_83 ;
int V_84 = ! ! ( V_82 & V_85 ) ;
int V_86 = ! ! ( V_82 & V_87 ) ;
int V_88 ;
F_19 ( V_56
L_12 ,
V_8 , V_84 , V_86 ) ;
V_88 = F_1 ( V_31 -> V_72 , V_8 ) ;
if ( V_88 < 0 )
return;
F_33 ( V_7 , V_8 , & V_31 -> V_38 [ V_88 ] ) ;
}
static void F_34 ( struct V_6 * V_7 , unsigned int V_82 )
{
int V_89 = V_82 >> V_83 ;
int V_90 = ( V_82 & V_91 ) >> V_92 ;
int V_93 = ! ! ( V_82 & V_94 ) ;
int V_95 = ! ! ( V_82 & V_96 ) ;
F_19 ( V_56
L_13 ,
V_89 ,
V_90 ,
V_93 ,
V_95 ) ;
if ( V_93 )
;
if ( V_95 )
;
}
static void F_35 ( struct V_6 * V_7 , unsigned int V_82 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
int V_89 = V_82 >> V_83 ;
int V_90 = ( V_82 & V_91 ) >> V_92 ;
if ( F_1 ( V_31 -> V_72 , V_89 ) < 0 ) {
F_27 ( V_56 L_14 , V_89 ) ;
return;
}
if ( V_90 == 0 )
F_32 ( V_7 , V_82 ) ;
else
F_34 ( V_7 , V_82 ) ;
}
static int F_36 ( struct V_6 * V_7 , T_1 V_2 ,
T_3 V_97 , int V_98 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
int V_99 ;
int V_100 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_31 -> V_70 ; V_3 ++ ) {
if ( V_31 -> V_37 [ V_3 ] != V_2 )
continue;
if ( ! ( F_37 ( V_7 , V_31 -> V_72 [ V_3 ] ) & V_101 ) )
continue;
V_99 = F_4 ( V_7 , V_31 -> V_72 [ V_3 ] , 0 ,
V_102 , 0 ) ;
V_100 = V_99 & ~ V_103 ;
if ( F_38 ( V_98 ) )
V_100 |= V_104 ;
else
V_100 |= V_105 ;
F_16 ( L_15
L_16 ,
V_31 -> V_72 [ V_3 ] ,
V_99 == V_100 ? L_17 : L_18 ,
V_100 ) ;
if ( V_99 != V_100 )
F_6 ( V_7 , V_31 -> V_72 [ V_3 ] , 0 ,
V_18 ,
V_100 ) ;
}
if ( F_38 ( V_98 ) && ! V_100 ) {
F_16 ( L_19 ) ;
return - V_5 ;
}
F_39 ( V_7 , V_2 , V_97 , 0 , V_98 ) ;
return 0 ;
}
static int F_40 ( struct V_106 * V_107 ,
struct V_6 * V_7 ,
struct V_65 * V_66 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
struct V_32 * V_33 ;
struct V_106 * V_108 ;
struct V_109 * V_67 = V_66 -> V_67 ;
unsigned int V_110 ;
for ( V_110 = 0 ; V_110 < V_31 -> V_111 ; V_110 ++ )
if ( V_107 -> V_2 == V_31 -> V_112 [ V_110 ] )
break;
if ( F_41 ( V_110 >= V_31 -> V_111 ) ||
F_41 ( V_110 >= V_31 -> V_70 ) )
return - V_5 ;
V_108 = & V_31 -> V_113 [ V_110 ] ;
if ( ! V_108 -> V_114 )
* V_108 = * V_107 ;
V_33 = & V_31 -> V_38 [ V_110 ] ;
if ( ! V_115 && V_33 -> V_116 && V_33 -> V_117 > 0 ) {
F_42 ( V_33 , V_107 , V_108 ) ;
if ( V_107 -> V_118 > V_107 -> V_119 ||
! V_107 -> V_114 || ! V_107 -> V_120 )
return - V_121 ;
} else {
V_107 -> V_119 = V_108 -> V_119 ;
V_107 -> V_114 = V_108 -> V_114 ;
V_107 -> V_120 = V_108 -> V_120 ;
V_107 -> V_122 = V_108 -> V_122 ;
}
V_67 -> V_123 . V_118 = V_107 -> V_118 ;
V_67 -> V_123 . V_119 = V_107 -> V_119 ;
V_67 -> V_123 . V_120 = V_107 -> V_120 ;
V_67 -> V_123 . V_114 = V_107 -> V_114 ;
F_43 ( V_66 -> V_67 , 0 ,
V_124 , 2 ) ;
return 0 ;
}
static int F_44 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
T_1 V_125 [ V_126 ] ;
int V_127 , V_128 ;
int V_88 ;
if ( ! ( F_9 ( V_7 , V_8 ) & V_129 ) ) {
F_2 ( V_4
L_20
L_21 ,
V_8 , F_9 ( V_7 , V_8 ) ) ;
return - V_5 ;
}
V_127 = F_45 ( V_7 , V_8 , V_125 ,
V_126 ) ;
if ( V_127 > 1 )
V_128 = F_4 ( V_7 , V_8 , 0 ,
V_130 , 0 ) ;
else
V_128 = 0 ;
V_88 = F_1 ( V_31 -> V_72 , V_8 ) ;
if ( V_88 < 0 )
return - V_5 ;
V_31 -> V_37 [ V_88 ] = V_125 [ V_128 ] ;
return 0 ;
}
static void F_33 ( struct V_6 * V_7 , T_1 V_8 ,
struct V_32 * V_33 )
{
int V_131 = F_46 ( V_7 , V_8 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_71 = ! ! ( V_131 & V_132 ) ;
if ( V_33 -> V_71 )
V_33 -> V_116 = ! ! ( V_131 & V_133 ) ;
else
V_33 -> V_116 = 0 ;
F_19 ( V_56
L_22 ,
V_8 , V_33 -> V_71 , V_33 -> V_116 ) ;
if ( V_33 -> V_116 )
if ( ! F_47 ( V_33 , V_7 , V_8 ) )
F_48 ( V_33 ) ;
F_49 ( V_7 , V_8 ) ;
}
static int F_50 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
int V_45 ;
if ( V_31 -> V_70 >= V_134 ) {
F_2 ( V_4
L_23 , V_8 ) ;
return - V_135 ;
}
V_45 = F_51 ( V_7 , V_8 ,
V_136 , NULL ) ;
if ( V_45 < 0 )
return V_45 ;
F_33 ( V_7 , V_8 , & V_31 -> V_38 [ V_31 -> V_70 ] ) ;
V_31 -> V_72 [ V_31 -> V_70 ] = V_8 ;
V_31 -> V_70 ++ ;
return F_44 ( V_7 , V_8 ) ;
}
static int F_52 ( struct V_6 * V_7 , T_1 V_2 )
{
int V_3 , V_137 = 0 ;
struct V_30 * V_31 = V_7 -> V_31 ;
for ( V_3 = 0 ; V_3 < V_31 -> V_70 ; V_3 ++ )
if ( V_2 == V_31 -> V_37 [ V_3 ] ) {
V_137 = 1 ;
break;
}
if ( ! V_137 ) {
F_16 ( L_24 , V_2 ) ;
return - V_5 ;
}
if ( F_41 ( V_31 -> V_111 >= V_138 ) )
return - V_135 ;
V_31 -> V_112 [ V_31 -> V_111 ] = V_2 ;
V_31 -> V_111 ++ ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 )
{
T_1 V_2 ;
int V_3 , V_139 ;
int V_140 = 0 ;
T_1 V_141 [ V_138 ] ;
V_139 = F_54 ( V_7 , V_7 -> V_142 , & V_2 ) ;
if ( ! V_2 || V_139 < 0 ) {
F_2 ( V_4 L_25 ) ;
return - V_5 ;
}
for ( V_3 = 0 ; V_3 < V_139 ; V_3 ++ , V_2 ++ ) {
unsigned int V_143 ;
unsigned int type ;
unsigned int V_144 ;
V_143 = F_55 ( V_7 , V_2 , V_145 ) ;
type = F_56 ( V_143 ) ;
if ( ! ( V_143 & V_146 ) )
continue;
switch ( type ) {
case V_147 :
if ( V_140 >= V_138 ) {
F_2 ( V_4
L_26 , V_2 ) ;
continue;
}
V_141 [ V_140 ] = V_2 ;
V_140 ++ ;
break;
case V_148 :
V_143 = F_55 ( V_7 , V_2 , V_149 ) ;
if ( ! ( V_143 & ( V_150 | V_151 ) ) )
continue;
V_144 = F_4 ( V_7 , V_2 , 0 ,
V_152 , 0 ) ;
if ( F_57 ( V_144 ) == V_153 )
continue;
F_50 ( V_7 , V_2 ) ;
break;
}
}
for ( V_3 = 0 ; V_3 < V_140 ; V_3 ++ )
F_52 ( V_7 , V_141 [ V_3 ] ) ;
#ifdef F_58
if ( ! ( F_55 ( V_7 , V_7 -> V_142 , V_154 ) &
V_155 ) )
V_7 -> V_156 -> V_157 = 1 ;
#endif
return 0 ;
}
static int F_59 ( struct V_106 * V_107 ,
struct V_6 * V_7 ,
unsigned int V_97 ,
unsigned int V_98 ,
struct V_65 * V_66 )
{
F_11 ( V_7 , V_107 -> V_2 ,
V_66 -> V_67 -> V_27 ) ;
F_31 ( V_7 , V_107 -> V_2 , V_66 ) ;
return F_36 ( V_7 , V_107 -> V_2 , V_97 , V_98 ) ;
}
static int F_60 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
struct V_158 * V_159 = V_31 -> V_160 ;
int V_3 ;
V_7 -> V_161 = V_31 -> V_111 ;
V_7 -> V_162 = V_159 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_161 ; V_3 ++ , V_159 ++ ) {
unsigned int V_163 ;
struct V_106 * V_164 ;
V_163 = F_9 ( V_7 , V_31 -> V_112 [ V_3 ] ) ;
V_163 = F_61 ( V_163 ) ;
V_159 -> V_165 = V_166 [ V_3 ] ;
V_159 -> V_167 = V_168 ;
V_164 = & V_159 -> V_169 [ V_170 ] ;
if ( V_31 -> V_171 )
* V_164 = * V_31 -> V_171 ;
else
* V_164 = V_172 ;
V_164 -> V_2 = V_31 -> V_112 [ V_3 ] ;
if ( V_164 -> V_119 <= 2 && V_163 && V_163 <= 16 )
V_164 -> V_119 = V_163 ;
}
return 0 ;
}
static int F_62 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
int V_45 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_161 ; V_3 ++ ) {
V_45 = F_63 ( V_7 , V_31 -> V_112 [ V_3 ] ) ;
if ( V_45 < 0 )
return V_45 ;
}
return 0 ;
}
static int F_64 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
int V_3 ;
for ( V_3 = 0 ; V_31 -> V_72 [ V_3 ] ; V_3 ++ ) {
F_8 ( V_7 , V_31 -> V_72 [ V_3 ] ) ;
F_6 ( V_7 , V_31 -> V_72 [ V_3 ] , 0 ,
V_173 ,
V_174 | V_31 -> V_72 [ V_3 ] ) ;
}
return 0 ;
}
static void F_65 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_31 -> V_70 ; V_3 ++ )
F_66 ( V_7 , & V_31 -> V_38 [ V_3 ] ) ;
F_67 ( V_7 ) ;
F_68 ( V_31 ) ;
}
static int F_69 ( struct V_6 * V_7 )
{
struct V_30 * V_31 ;
int V_3 ;
V_31 = F_70 ( sizeof( * V_31 ) , V_175 ) ;
if ( V_31 == NULL )
return - V_176 ;
V_7 -> V_31 = V_31 ;
if ( F_53 ( V_7 ) < 0 ) {
V_7 -> V_31 = NULL ;
F_68 ( V_31 ) ;
return - V_5 ;
}
V_7 -> V_177 = V_178 ;
for ( V_3 = 0 ; V_3 < V_31 -> V_70 ; V_3 ++ )
F_71 ( V_7 , & V_31 -> V_38 [ V_3 ] , V_3 ) ;
F_12 () ;
return 0 ;
}
static int F_72 ( struct V_6 * V_7 )
{
F_73 ( V_7 , V_179 ) ;
return 0 ;
}
static int F_74 ( struct V_106 * V_107 ,
struct V_6 * V_7 ,
struct V_65 * V_66 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
struct V_180 * V_181 = NULL ;
switch ( V_7 -> V_182 -> V_183 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_181 = & V_184 ;
break;
case 0x10de0007 :
V_181 = & V_185 ;
break;
default:
break;
}
if ( V_181 != NULL ) {
V_180 ( V_66 -> V_67 , 0 ,
V_124 ,
V_181 ) ;
} else {
F_43 ( V_66 -> V_67 , 0 ,
V_124 , 2 ) ;
}
return F_75 ( V_7 , & V_31 -> V_186 ) ;
}
static int F_76 ( struct V_106 * V_107 ,
struct V_6 * V_7 ,
struct V_65 * V_66 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
return F_77 ( V_7 , & V_31 -> V_186 ) ;
}
static int F_78 ( struct V_106 * V_107 ,
struct V_6 * V_7 ,
unsigned int V_97 ,
unsigned int V_98 ,
struct V_65 * V_66 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
return F_79 ( V_7 , & V_31 -> V_186 ,
V_97 , V_98 , V_66 ) ;
}
static void F_80 ( struct V_6 * V_7 ,
int V_27 )
{
unsigned int V_187 ;
int V_188 = V_27 ? ( V_27 - 1 ) : 1 ;
switch ( V_27 ) {
default:
case 0 :
case 2 :
V_187 = 0x00 ;
break;
case 4 :
V_187 = 0x08 ;
break;
case 6 :
V_187 = 0x0b ;
break;
case 8 :
V_187 = 0x13 ;
break;
}
F_6 ( V_7 , 0x1 , 0 ,
V_189 , V_187 ) ;
F_6 ( V_7 , 0x1 , 0 ,
V_190 ,
( 0x71 - V_188 - V_187 ) ) ;
}
static int F_81 ( struct V_106 * V_107 ,
struct V_6 * V_7 ,
struct V_65 * V_66 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
int V_3 ;
F_6 ( V_7 , V_191 ,
0 , V_192 , 0 ) ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
F_6 ( V_7 , V_193 [ V_3 ] , 0 ,
V_192 , 0 ) ;
F_6 ( V_7 , V_193 [ V_3 ] , 0 ,
V_194 , 0 ) ;
}
F_80 ( V_7 , 8 ) ;
return F_77 ( V_7 , & V_31 -> V_186 ) ;
}
static int F_82 ( struct V_106 * V_107 ,
struct V_6 * V_7 ,
unsigned int V_97 ,
unsigned int V_98 ,
struct V_65 * V_66 )
{
int V_21 ;
unsigned int V_195 , V_196 , V_197 ;
int V_3 ;
F_83 ( & V_7 -> V_198 ) ;
V_21 = V_66 -> V_67 -> V_27 ;
V_195 = V_199 | V_200 ;
V_196 = 0x2 ;
if ( V_7 -> V_201 && ( V_7 -> V_202 & V_199 ) )
F_6 ( V_7 ,
V_191 ,
0 ,
V_203 ,
V_7 -> V_202 & ~ V_199 & 0xff ) ;
F_6 ( V_7 , V_191 , 0 ,
V_192 , ( V_97 << 4 ) | 0x0 ) ;
F_6 ( V_7 , V_191 , 0 ,
V_194 , V_98 ) ;
if ( V_7 -> V_201 && ( V_7 -> V_202 & V_199 ) ) {
F_6 ( V_7 ,
V_191 ,
0 ,
V_203 ,
V_7 -> V_202 & 0xff ) ;
F_6 ( V_7 ,
V_191 ,
0 ,
V_204 , V_196 ) ;
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
if ( V_21 == 2 )
V_197 = 0 ;
else
V_197 = V_3 * 2 ;
if ( V_7 -> V_201 &&
( V_7 -> V_202 & V_199 ) )
F_6 ( V_7 ,
V_193 [ V_3 ] ,
0 ,
V_203 ,
V_7 -> V_202 & ~ V_199 & 0xff ) ;
F_6 ( V_7 ,
V_193 [ V_3 ] ,
0 ,
V_192 ,
( V_97 << 4 ) | V_197 ) ;
F_6 ( V_7 ,
V_193 [ V_3 ] ,
0 ,
V_194 ,
V_98 ) ;
if ( V_7 -> V_201 &&
( V_7 -> V_202 & V_199 ) ) {
F_6 ( V_7 ,
V_193 [ V_3 ] ,
0 ,
V_203 ,
V_7 -> V_202 & 0xff ) ;
F_6 ( V_7 ,
V_193 [ V_3 ] ,
0 ,
V_204 , V_196 ) ;
}
}
F_80 ( V_7 , V_21 ) ;
F_84 ( & V_7 -> V_198 ) ;
return 0 ;
}
static int F_85 ( struct V_6 * V_7 )
{
struct V_30 * V_31 ;
V_31 = F_70 ( sizeof( * V_31 ) , V_175 ) ;
if ( V_31 == NULL )
return - V_176 ;
V_7 -> V_31 = V_31 ;
V_31 -> V_186 . V_205 = 0 ;
V_31 -> V_186 . V_206 = 2 ;
V_31 -> V_186 . V_207 = V_191 ;
V_31 -> V_111 = 1 ;
V_31 -> V_112 [ 0 ] = V_191 ;
V_31 -> V_171 = & V_208 ;
V_7 -> V_177 = V_209 ;
return 0 ;
}
static int F_86 ( struct V_6 * V_7 )
{
struct V_30 * V_31 ;
int V_45 = F_85 ( V_7 ) ;
if ( V_45 < 0 )
return V_45 ;
V_31 = V_7 -> V_31 ;
V_31 -> V_186 . V_206 = 8 ;
V_31 -> V_171 = & V_210 ;
V_7 -> V_177 = V_211 ;
F_80 ( V_7 , 8 ) ;
return 0 ;
}
static int F_87 ( struct V_106 * V_107 ,
struct V_6 * V_7 ,
unsigned int V_97 ,
unsigned int V_98 ,
struct V_65 * V_66 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
int V_163 = V_66 -> V_67 -> V_27 ;
int V_3 , V_45 ;
V_45 = F_78 ( V_107 , V_7 , V_97 , V_98 ,
V_66 ) ;
if ( V_45 < 0 )
return V_45 ;
F_6 ( V_7 , V_31 -> V_112 [ 0 ] , 0 , V_22 ,
V_163 - 1 ) ;
for ( V_3 = 0 ; V_3 < V_163 ; V_3 ++ ) {
F_6 ( V_7 , V_31 -> V_112 [ 0 ] , 0 ,
V_47 ,
( V_3 << 4 ) | V_3 ) ;
}
return 0 ;
}
static int F_88 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_31 ;
F_73 ( V_7 , V_212 ) ;
if ( F_9 ( V_7 , V_31 -> V_72 [ 0 ] ) & V_15 )
F_6 ( V_7 , V_31 -> V_72 [ 0 ] , 0 ,
V_16 ,
V_17 ) ;
return 0 ;
}
static int F_89 ( struct V_6 * V_7 )
{
struct V_30 * V_31 ;
V_31 = F_70 ( sizeof( * V_31 ) , V_175 ) ;
if ( V_31 == NULL )
return - V_176 ;
V_7 -> V_31 = V_31 ;
V_31 -> V_186 . V_205 = 0 ;
V_31 -> V_186 . V_206 = 2 ;
V_31 -> V_186 . V_207 = V_213 ;
V_31 -> V_111 = 1 ;
V_31 -> V_112 [ 0 ] = V_213 ;
V_31 -> V_72 [ 0 ] = V_214 ;
V_31 -> V_171 = & V_215 ;
V_7 -> V_177 = V_216 ;
return 0 ;
}
static int T_4 F_90 ( void )
{
return F_91 ( & V_217 ) ;
}
static void T_5 F_92 ( void )
{
F_93 ( & V_217 ) ;
}
