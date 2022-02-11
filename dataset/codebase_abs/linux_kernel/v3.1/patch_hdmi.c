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
static void F_5 ( struct V_17 * V_18 , T_1 V_3 ,
int * V_19 , int * V_20 )
{
int V_21 ;
V_21 = F_6 ( V_18 , V_3 , 0 ,
V_22 , 0 ) ;
* V_19 = V_21 >> 5 ;
* V_20 = V_21 & 0x1f ;
}
static void F_7 ( struct V_17 * V_18 , T_1 V_3 ,
int V_19 , int V_20 )
{
int V_21 ;
V_21 = ( V_19 << 5 ) | ( V_20 & 0x1f ) ;
F_8 ( V_18 , V_3 , 0 , V_23 , V_21 ) ;
}
static void F_9 ( struct V_17 * V_18 , T_1 V_3 ,
unsigned char V_21 )
{
F_8 ( V_18 , V_3 , 0 , V_24 , V_21 ) ;
}
static void F_10 ( struct V_17 * V_18 , T_1 V_3 )
{
if ( F_11 ( V_18 , V_3 ) & V_25 )
F_8 ( V_18 , V_3 , 0 ,
V_26 , V_27 ) ;
F_8 ( V_18 , V_3 , 0 ,
V_28 , 0 ) ;
}
static int F_12 ( struct V_17 * V_18 , T_1 V_13 )
{
return 1 + F_6 ( V_18 , V_13 , 0 ,
V_29 , 0 ) ;
}
static void F_13 ( struct V_17 * V_18 ,
T_1 V_13 , int V_30 )
{
if ( V_30 != F_12 ( V_18 , V_13 ) )
F_8 ( V_18 , V_13 , 0 ,
V_31 , V_30 - 1 ) ;
}
static void F_14 ( void )
{
int V_32 , V_33 ;
struct V_34 * V_35 ;
for ( V_32 = 0 ; V_32 < F_15 ( V_36 ) ; V_32 ++ ) {
V_35 = V_36 + V_32 ;
V_35 -> V_37 = 0 ;
V_35 -> V_38 = 0 ;
for ( V_33 = 0 ; V_33 < F_15 ( V_35 -> V_39 ) ; V_33 ++ )
if ( V_35 -> V_39 [ V_33 ] ) {
V_35 -> V_37 ++ ;
V_35 -> V_38 |= V_35 -> V_39 [ V_33 ] ;
}
}
}
static int F_16 ( struct V_40 * V_41 , int V_37 )
{
int V_32 ;
int V_42 = 0 ;
int V_38 = 0 ;
char V_43 [ V_44 ] ;
if ( V_37 <= 2 )
return 0 ;
for ( V_32 = 0 ; V_32 < F_15 ( V_45 ) ; V_32 ++ ) {
if ( V_41 -> V_46 & ( 1 << V_32 ) )
V_38 |= V_45 [ V_32 ] ;
}
for ( V_32 = 0 ; V_32 < F_15 ( V_36 ) ; V_32 ++ ) {
if ( V_37 == V_36 [ V_32 ] . V_37 &&
( V_38 & V_36 [ V_32 ] . V_38 ) ==
V_36 [ V_32 ] . V_38 ) {
V_42 = V_36 [ V_32 ] . V_47 ;
break;
}
}
F_17 ( V_41 -> V_46 , V_43 , sizeof( V_43 ) ) ;
F_18 ( L_4 ,
V_42 , V_37 , V_43 ) ;
return V_42 ;
}
static void F_19 ( struct V_17 * V_18 ,
T_1 V_3 )
{
#ifdef F_20
int V_32 ;
int V_48 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
V_48 = F_6 ( V_18 , V_3 , 0 ,
V_49 , V_32 ) ;
F_21 ( V_50 L_5 ,
V_48 >> 4 , V_48 & 0xf ) ;
}
#endif
}
static void F_22 ( struct V_17 * V_18 ,
T_1 V_3 ,
int V_42 )
{
int V_32 ;
int V_51 ;
if ( V_52 [ V_42 ] [ 1 ] == 0 ) {
for ( V_32 = 0 ; V_32 < V_36 [ V_42 ] . V_37 ; V_32 ++ )
V_52 [ V_42 ] [ V_32 ] = V_32 | ( V_32 << 4 ) ;
for (; V_32 < 8 ; V_32 ++ )
V_52 [ V_42 ] [ V_32 ] = 0xf | ( V_32 << 4 ) ;
}
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
V_51 = F_8 ( V_18 , V_3 , 0 ,
V_53 ,
V_52 [ V_42 ] [ V_32 ] ) ;
if ( V_51 ) {
F_18 ( V_54
L_6 ) ;
break;
}
}
F_19 ( V_18 , V_3 ) ;
}
static void F_23 ( struct V_17 * V_18 ,
T_1 V_3 )
{
F_7 ( V_18 , V_3 , 0x0 , 0x0 ) ;
F_8 ( V_18 , V_3 , 0 , V_55 ,
V_56 ) ;
}
static void F_24 ( struct V_17 * V_18 ,
T_1 V_3 )
{
F_7 ( V_18 , V_3 , 0x0 , 0x0 ) ;
F_8 ( V_18 , V_3 , 0 , V_55 ,
V_57 ) ;
}
static void F_25 ( struct V_17 * V_18 , T_1 V_3 )
{
#ifdef F_20
int V_32 ;
int V_58 ;
V_58 = F_26 ( V_18 , V_3 ) ;
F_21 ( V_50 L_7 , V_58 ) ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
V_58 = F_6 ( V_18 , V_3 , 0 ,
V_59 , V_32 ) ;
F_21 ( V_50 L_8 , V_32 , V_58 ) ;
}
#endif
}
static void F_27 ( struct V_17 * V_18 , T_1 V_3 )
{
#ifdef F_28
int V_32 , V_33 ;
int V_58 ;
int V_60 , V_61 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
V_58 = F_6 ( V_18 , V_3 , 0 ,
V_59 , V_32 ) ;
if ( V_58 == 0 )
continue;
F_7 ( V_18 , V_3 , V_32 , 0x0 ) ;
for ( V_33 = 1 ; V_33 < 1000 ; V_33 ++ ) {
F_9 ( V_18 , V_3 , 0x0 ) ;
F_5 ( V_18 , V_3 , & V_60 , & V_61 ) ;
if ( V_60 != V_32 )
F_29 ( V_62 L_9 ,
V_61 , V_60 , V_32 ) ;
if ( V_61 == 0 )
break;
}
F_29 ( V_62
L_10 ,
V_32 , V_58 , V_33 ) ;
}
#endif
}
static void F_30 ( struct V_63 * V_64 )
{
T_2 * V_65 = ( T_2 * ) V_64 ;
T_2 V_66 = 0 ;
int V_32 ;
V_64 -> V_67 = 0 ;
for ( V_32 = 0 ; V_32 < sizeof( * V_64 ) ; V_32 ++ )
V_66 += V_65 [ V_32 ] ;
V_64 -> V_67 = - V_66 ;
}
static void F_31 ( struct V_17 * V_18 ,
T_1 V_3 ,
T_2 * V_68 , int V_58 )
{
int V_32 ;
F_25 ( V_18 , V_3 ) ;
F_27 ( V_18 , V_3 ) ;
F_7 ( V_18 , V_3 , 0x0 , 0x0 ) ;
for ( V_32 = 0 ; V_32 < V_58 ; V_32 ++ )
F_9 ( V_18 , V_3 , V_68 [ V_32 ] ) ;
}
static bool F_32 ( struct V_17 * V_18 , T_1 V_3 ,
T_2 * V_68 , int V_58 )
{
T_2 V_21 ;
int V_32 ;
if ( F_6 ( V_18 , V_3 , 0 , V_69 , 0 )
!= V_56 )
return false ;
F_7 ( V_18 , V_3 , 0x0 , 0x0 ) ;
for ( V_32 = 0 ; V_32 < V_58 ; V_32 ++ ) {
V_21 = F_6 ( V_18 , V_3 , 0 ,
V_70 , 0 ) ;
if ( V_21 != V_68 [ V_32 ] )
return false ;
}
return true ;
}
static void F_33 ( struct V_17 * V_18 , int V_4 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_73 * V_74 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_74 -> V_3 ;
int V_37 = V_72 -> V_75 -> V_37 ;
struct V_40 * V_41 ;
int V_42 ;
union V_76 V_77 ;
V_41 = & V_2 -> V_6 [ V_4 ] . V_78 ;
if ( ! V_41 -> V_79 )
return;
V_42 = F_16 ( V_41 , V_37 ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
if ( V_41 -> V_80 == 0 ) {
struct V_63 * V_64 = & V_77 . V_81 ;
V_64 -> type = 0x84 ;
V_64 -> V_82 = 0x01 ;
V_64 -> V_83 = 0x0a ;
V_64 -> V_84 = V_37 - 1 ;
V_64 -> V_85 = V_42 ;
F_30 ( V_64 ) ;
} else if ( V_41 -> V_80 == 1 ) {
struct V_86 * V_87 = & V_77 . V_88 ;
V_87 -> type = 0x84 ;
V_87 -> V_83 = 0x1b ;
V_87 -> V_82 = 0x11 << 2 ;
V_87 -> V_84 = V_37 - 1 ;
V_87 -> V_85 = V_42 ;
} else {
F_29 ( L_11 ,
V_3 ) ;
return;
}
if ( ! F_32 ( V_18 , V_3 , V_77 . V_65 ,
sizeof( V_77 ) ) ) {
F_18 ( L_12
L_13 ,
V_3 ,
V_37 ) ;
F_22 ( V_18 , V_3 , V_42 ) ;
F_24 ( V_18 , V_3 ) ;
F_31 ( V_18 , V_3 ,
V_77 . V_65 , sizeof( V_77 ) ) ;
F_23 ( V_18 , V_3 ) ;
}
}
static void F_34 ( struct V_17 * V_18 , unsigned int V_89 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_3 = V_89 >> V_90 ;
int V_91 = ! ! ( V_89 & V_92 ) ;
int V_93 = ! ! ( V_89 & V_94 ) ;
int V_4 ;
struct V_40 * V_41 ;
F_21 ( V_62
L_14 ,
V_18 -> V_95 , V_3 , V_91 , V_93 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return;
V_41 = & V_2 -> V_6 [ V_4 ] . V_78 ;
F_35 ( V_18 , V_3 , V_41 ) ;
if ( ! V_41 -> V_46 )
V_41 -> V_46 = 0xffff ;
}
static void F_36 ( struct V_17 * V_18 , unsigned int V_89 )
{
int V_96 = V_89 >> V_90 ;
int V_97 = ( V_89 & V_98 ) >> V_99 ;
int V_100 = ! ! ( V_89 & V_101 ) ;
int V_102 = ! ! ( V_89 & V_103 ) ;
F_21 ( V_62
L_15 ,
V_18 -> V_95 ,
V_96 ,
V_97 ,
V_100 ,
V_102 ) ;
if ( V_100 )
;
if ( V_102 )
;
}
static void F_37 ( struct V_17 * V_18 , unsigned int V_89 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_96 = V_89 >> V_90 ;
int V_97 = ( V_89 & V_98 ) >> V_99 ;
if ( F_1 ( V_2 , V_96 ) < 0 ) {
F_29 ( V_62 L_16 , V_96 ) ;
return;
}
if ( V_97 == 0 )
F_34 ( V_18 , V_89 ) ;
else
F_36 ( V_18 , V_89 ) ;
}
static int F_38 ( struct V_17 * V_18 , T_1 V_13 ,
T_1 V_3 , T_3 V_104 , int V_105 )
{
int V_106 ;
int V_107 = 0 ;
if ( F_39 ( V_18 , V_3 ) & V_108 ) {
V_106 = F_6 ( V_18 , V_3 , 0 ,
V_109 , 0 ) ;
V_107 = V_106 & ~ V_110 ;
if ( F_40 ( V_105 ) )
V_107 |= V_111 ;
else
V_107 |= V_112 ;
F_18 ( L_17
L_18 ,
V_3 ,
V_106 == V_107 ? L_19 : L_20 ,
V_107 ) ;
if ( V_106 != V_107 )
F_8 ( V_18 , V_3 , 0 ,
V_28 ,
V_107 ) ;
}
if ( F_40 ( V_105 ) && ! V_107 ) {
F_18 ( L_21 ) ;
return - V_8 ;
}
F_41 ( V_18 , V_13 , V_104 , 0 , V_105 ) ;
return 0 ;
}
static int F_42 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_113 * V_75 = V_72 -> V_75 ;
int V_4 , V_14 , V_114 = 0 ;
struct V_73 * V_74 ;
struct V_40 * V_41 ;
struct V_115 * V_116 = NULL ;
int V_106 ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_43 ( V_4 < 0 ) )
return - V_8 ;
V_74 = & V_2 -> V_6 [ V_4 ] ;
V_41 = & V_74 -> V_78 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ ) {
V_116 = & V_2 -> V_16 [ V_14 ] ;
if ( V_116 -> V_117 )
continue;
for ( V_114 = 0 ; V_114 < V_74 -> V_118 ; V_114 ++ )
if ( V_74 -> V_119 [ V_114 ] == V_116 -> V_13 )
break;
if ( V_114 == V_74 -> V_118 )
continue;
break;
}
if ( V_14 == V_2 -> V_15 )
return - V_120 ;
V_116 -> V_117 = 1 ;
V_10 -> V_121 = V_116 -> V_13 ;
F_8 ( V_18 , V_74 -> V_3 , 0 ,
V_122 ,
V_114 ) ;
V_106 = F_6 ( V_18 , V_74 -> V_3 , 0 ,
V_109 , 0 ) ;
F_8 ( V_18 , V_74 -> V_3 , 0 ,
V_28 ,
V_106 | V_123 ) ;
F_44 ( V_18 , V_4 , V_116 -> V_13 ) ;
V_10 -> V_124 = V_116 -> V_124 ;
V_10 -> V_125 = V_116 -> V_125 ;
V_10 -> V_126 = V_116 -> V_126 ;
V_10 -> V_127 = V_116 -> V_127 ;
V_10 -> V_128 = V_116 -> V_128 ;
if ( ! V_129 && V_41 -> V_130 ) {
F_45 ( V_41 , V_10 ) ;
if ( V_10 -> V_124 > V_10 -> V_125 ||
! V_10 -> V_126 || ! V_10 -> V_127 )
return - V_120 ;
}
V_75 -> V_131 . V_124 = V_10 -> V_124 ;
V_75 -> V_131 . V_125 = V_10 -> V_125 ;
V_75 -> V_131 . V_127 = V_10 -> V_127 ;
V_75 -> V_131 . V_126 = V_10 -> V_126 ;
F_46 ( V_72 -> V_75 , 0 ,
V_132 , 2 ) ;
return 0 ;
}
static int F_47 ( struct V_17 * V_18 , int V_4 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_73 * V_74 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_74 -> V_3 ;
if ( ! ( F_11 ( V_18 , V_3 ) & V_133 ) ) {
F_2 ( V_7
L_22
L_23 ,
V_3 , F_11 ( V_18 , V_3 ) ) ;
return - V_8 ;
}
V_74 -> V_118 = F_48 ( V_18 , V_3 ,
V_74 -> V_119 ,
V_134 ) ;
return 0 ;
}
static void F_35 ( struct V_17 * V_18 , T_1 V_3 ,
struct V_40 * V_41 )
{
int V_135 = F_49 ( V_18 , V_3 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_79 = ! ! ( V_135 & V_136 ) ;
if ( V_41 -> V_79 )
V_41 -> V_130 = ! ! ( V_135 & V_137 ) ;
else
V_41 -> V_130 = 0 ;
F_21 ( V_62
L_24 ,
V_18 -> V_95 , V_3 , V_41 -> V_79 , V_41 -> V_130 ) ;
if ( V_41 -> V_130 )
if ( ! F_50 ( V_41 , V_18 , V_3 ) )
F_51 ( V_41 ) ;
F_52 ( V_18 , V_3 ) ;
}
static int F_53 ( struct V_17 * V_18 , T_1 V_3 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
unsigned int V_138 , V_139 ;
int V_4 ;
struct V_73 * V_74 ;
struct V_40 * V_41 ;
int V_51 ;
V_138 = F_54 ( V_18 , V_3 , V_140 ) ;
if ( ! ( V_138 & ( V_141 | V_142 ) ) )
return 0 ;
V_139 = F_6 ( V_18 , V_3 , 0 ,
V_143 , 0 ) ;
if ( F_55 ( V_139 ) == V_144 )
return 0 ;
if ( F_43 ( V_2 -> V_5 >= V_145 ) )
return - V_146 ;
V_4 = V_2 -> V_5 ;
V_74 = & V_2 -> V_6 [ V_4 ] ;
V_41 = & V_74 -> V_78 ;
V_74 -> V_3 = V_3 ;
V_51 = F_56 ( V_18 , V_3 ,
V_147 , NULL ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = F_47 ( V_18 , V_4 ) ;
if ( V_51 < 0 )
return V_51 ;
V_2 -> V_5 ++ ;
F_35 ( V_18 , V_3 , V_41 ) ;
return 0 ;
}
static int F_57 ( struct V_17 * V_18 , T_1 V_13 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_14 ;
struct V_115 * V_116 ;
unsigned int V_148 ;
int V_51 ;
if ( F_43 ( V_2 -> V_15 >= V_149 ) )
return - V_146 ;
V_148 = F_11 ( V_18 , V_13 ) ;
V_148 = F_58 ( V_148 ) ;
V_14 = V_2 -> V_15 ;
V_116 = & V_2 -> V_16 [ V_14 ] ;
V_116 -> V_13 = V_13 ;
V_116 -> V_124 = 2 ;
if ( V_148 <= 16 )
V_116 -> V_125 = V_148 ;
V_51 = F_59 ( V_18 , V_13 ,
& V_116 -> V_126 ,
& V_116 -> V_127 ,
& V_116 -> V_128 ) ;
if ( V_51 < 0 )
return V_51 ;
V_2 -> V_15 ++ ;
return 0 ;
}
static int F_60 ( struct V_17 * V_18 )
{
T_1 V_121 ;
int V_32 , V_150 ;
V_150 = F_61 ( V_18 , V_18 -> V_151 , & V_121 ) ;
if ( ! V_121 || V_150 < 0 ) {
F_2 ( V_7 L_25 ) ;
return - V_8 ;
}
for ( V_32 = 0 ; V_32 < V_150 ; V_32 ++ , V_121 ++ ) {
unsigned int V_138 ;
unsigned int type ;
V_138 = F_54 ( V_18 , V_121 , V_152 ) ;
type = F_62 ( V_138 ) ;
if ( ! ( V_138 & V_153 ) )
continue;
switch ( type ) {
case V_154 :
F_57 ( V_18 , V_121 ) ;
break;
case V_155 :
F_53 ( V_18 , V_121 ) ;
break;
}
}
#ifdef F_63
if ( ! ( F_54 ( V_18 , V_18 -> V_151 , V_156 ) &
V_157 ) )
V_18 -> V_158 -> V_159 = 1 ;
#endif
return 0 ;
}
static int F_64 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_71 * V_72 )
{
T_1 V_13 = V_10 -> V_121 ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_4 = F_3 ( V_2 , V_10 ) ;
T_1 V_3 = V_2 -> V_6 [ V_4 ] . V_3 ;
F_13 ( V_18 , V_13 , V_72 -> V_75 -> V_37 ) ;
F_33 ( V_18 , V_4 , V_72 ) ;
return F_38 ( V_18 , V_13 , V_3 , V_104 , V_105 ) ;
}
static int F_65 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_14 , V_4 ;
struct V_115 * V_116 ;
struct V_73 * V_74 ;
int V_106 ;
F_66 ( V_18 , V_10 -> V_121 ) ;
if ( V_10 -> V_121 ) {
V_14 = F_4 ( V_2 , V_10 -> V_121 ) ;
if ( F_43 ( V_14 < 0 ) )
return - V_8 ;
V_116 = & V_2 -> V_16 [ V_14 ] ;
F_43 ( ! V_116 -> V_117 ) ;
V_116 -> V_117 = 0 ;
V_10 -> V_121 = 0 ;
V_4 = F_3 ( V_2 , V_10 ) ;
if ( F_43 ( V_4 < 0 ) )
return - V_8 ;
V_74 = & V_2 -> V_6 [ V_4 ] ;
V_106 = F_6 ( V_18 , V_74 -> V_3 , 0 ,
V_109 , 0 ) ;
F_8 ( V_18 , V_74 -> V_3 , 0 ,
V_28 ,
V_106 & ~ V_123 ) ;
F_67 ( V_18 , V_4 ) ;
}
return 0 ;
}
static int F_68 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_160 * V_161 ;
struct V_9 * V_162 ;
V_161 = & V_2 -> V_11 [ V_4 ] ;
V_161 -> V_163 = V_164 [ V_4 ] ;
V_161 -> V_165 = V_166 ;
V_162 = & V_161 -> V_12 [ V_167 ] ;
V_162 -> V_168 = 1 ;
V_162 -> V_169 = V_170 ;
}
V_18 -> V_171 = V_2 -> V_5 ;
V_18 -> V_172 = V_2 -> V_11 ;
return 0 ;
}
static int F_69 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_51 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_73 * V_74 = & V_2 -> V_6 [ V_4 ] ;
V_51 = F_70 ( V_18 ,
V_74 -> V_3 ,
V_74 -> V_119 [ 0 ] ) ;
if ( V_51 < 0 )
return V_51 ;
F_67 ( V_18 , V_4 ) ;
}
return 0 ;
}
static int F_71 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_73 * V_74 = & V_2 -> V_6 [ V_4 ] ;
T_1 V_3 = V_74 -> V_3 ;
struct V_40 * V_41 = & V_74 -> V_78 ;
F_10 ( V_18 , V_3 ) ;
F_8 ( V_18 , V_3 , 0 ,
V_173 ,
V_174 | V_3 ) ;
F_72 ( V_18 , V_41 , V_4 ) ;
}
return 0 ;
}
static void F_73 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_73 * V_74 = & V_2 -> V_6 [ V_4 ] ;
struct V_40 * V_41 = & V_74 -> V_78 ;
F_74 ( V_18 , V_41 ) ;
}
F_75 ( V_18 ) ;
F_76 ( V_2 ) ;
}
static int F_77 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( sizeof( * V_2 ) , V_175 ) ;
if ( V_2 == NULL )
return - V_176 ;
V_18 -> V_2 = V_2 ;
if ( F_60 ( V_18 ) < 0 ) {
V_18 -> V_2 = NULL ;
F_76 ( V_2 ) ;
return - V_8 ;
}
V_18 -> V_177 = V_178 ;
F_14 () ;
return 0 ;
}
static int F_79 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_160 * V_161 = V_2 -> V_11 ;
int V_32 ;
V_18 -> V_171 = V_2 -> V_15 ;
V_18 -> V_172 = V_161 ;
for ( V_32 = 0 ; V_32 < V_18 -> V_171 ; V_32 ++ , V_161 ++ ) {
unsigned int V_148 ;
struct V_9 * V_162 ;
V_148 = F_11 ( V_18 , V_2 -> V_16 [ V_32 ] . V_13 ) ;
V_148 = F_58 ( V_148 ) ;
V_161 -> V_163 = V_164 [ V_32 ] ;
V_161 -> V_165 = V_166 ;
V_162 = & V_161 -> V_12 [ V_167 ] ;
F_43 ( ! V_2 -> V_179 ) ;
* V_162 = * V_2 -> V_179 ;
V_162 -> V_121 = V_2 -> V_16 [ V_32 ] . V_13 ;
if ( V_162 -> V_125 <= 2 && V_148 && V_148 <= 16 )
V_162 -> V_125 = V_148 ;
}
return 0 ;
}
static int F_80 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_51 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_18 -> V_171 ; V_32 ++ ) {
V_51 = F_70 ( V_18 ,
V_2 -> V_16 [ V_32 ] . V_13 ,
V_2 -> V_16 [ V_32 ] . V_13 ) ;
if ( V_51 < 0 )
return V_51 ;
}
return 0 ;
}
static void F_81 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
F_76 ( V_2 ) ;
}
static int F_82 ( struct V_17 * V_18 )
{
F_83 ( V_18 , V_180 ) ;
return 0 ;
}
static int F_84 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_181 * V_182 = NULL ;
switch ( V_18 -> V_183 -> V_184 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_182 = & V_185 ;
break;
case 0x10de0007 :
V_182 = & V_186 ;
break;
default:
break;
}
if ( V_182 != NULL ) {
V_181 ( V_72 -> V_75 , 0 ,
V_132 ,
V_182 ) ;
} else {
F_46 ( V_72 -> V_75 , 0 ,
V_132 , 2 ) ;
}
return F_85 ( V_18 , & V_2 -> V_187 ) ;
}
static int F_86 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
return F_87 ( V_18 , & V_2 -> V_187 ) ;
}
static int F_88 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
return F_89 ( V_18 , & V_2 -> V_187 ,
V_104 , V_105 , V_72 ) ;
}
static void F_90 ( struct V_17 * V_18 ,
int V_37 )
{
unsigned int V_188 ;
int V_189 = V_37 ? ( V_37 - 1 ) : 1 ;
switch ( V_37 ) {
default:
case 0 :
case 2 :
V_188 = 0x00 ;
break;
case 4 :
V_188 = 0x08 ;
break;
case 6 :
V_188 = 0x0b ;
break;
case 8 :
V_188 = 0x13 ;
break;
}
F_8 ( V_18 , 0x1 , 0 ,
V_190 , V_188 ) ;
F_8 ( V_18 , 0x1 , 0 ,
V_191 ,
( 0x71 - V_189 - V_188 ) ) ;
}
static int F_91 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_32 ;
F_8 ( V_18 , V_192 ,
0 , V_193 , 0 ) ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
F_8 ( V_18 , V_194 [ V_32 ] , 0 ,
V_193 , 0 ) ;
F_8 ( V_18 , V_194 [ V_32 ] , 0 ,
V_195 , 0 ) ;
}
F_90 ( V_18 , 8 ) ;
return F_87 ( V_18 , & V_2 -> V_187 ) ;
}
static int F_92 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_71 * V_72 )
{
int V_30 ;
unsigned int V_196 , V_197 , V_198 ;
int V_32 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_199 * V_200 =
F_93 ( V_18 , V_2 -> V_16 [ 0 ] . V_13 ) ;
F_94 ( & V_18 -> V_201 ) ;
V_30 = V_72 -> V_75 -> V_37 ;
V_196 = V_202 | V_203 ;
V_197 = 0x2 ;
if ( V_18 -> V_204 && ( V_200 -> V_205 & V_202 ) )
F_8 ( V_18 ,
V_192 ,
0 ,
V_206 ,
V_200 -> V_205 & ~ V_202 & 0xff ) ;
F_8 ( V_18 , V_192 , 0 ,
V_193 , ( V_104 << 4 ) | 0x0 ) ;
F_8 ( V_18 , V_192 , 0 ,
V_195 , V_105 ) ;
if ( V_18 -> V_204 && ( V_200 -> V_205 & V_202 ) ) {
F_8 ( V_18 ,
V_192 ,
0 ,
V_206 ,
V_200 -> V_205 & 0xff ) ;
F_8 ( V_18 ,
V_192 ,
0 ,
V_207 , V_197 ) ;
}
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
if ( V_30 == 2 )
V_198 = 0 ;
else
V_198 = V_32 * 2 ;
if ( V_18 -> V_204 &&
( V_200 -> V_205 & V_202 ) )
F_8 ( V_18 ,
V_194 [ V_32 ] ,
0 ,
V_206 ,
V_200 -> V_205 & ~ V_202 & 0xff ) ;
F_8 ( V_18 ,
V_194 [ V_32 ] ,
0 ,
V_193 ,
( V_104 << 4 ) | V_198 ) ;
F_8 ( V_18 ,
V_194 [ V_32 ] ,
0 ,
V_195 ,
V_105 ) ;
if ( V_18 -> V_204 &&
( V_200 -> V_205 & V_202 ) ) {
F_8 ( V_18 ,
V_194 [ V_32 ] ,
0 ,
V_206 ,
V_200 -> V_205 & 0xff ) ;
F_8 ( V_18 ,
V_194 [ V_32 ] ,
0 ,
V_207 , V_197 ) ;
}
}
F_90 ( V_18 , V_30 ) ;
F_95 ( & V_18 -> V_201 ) ;
return 0 ;
}
static int F_96 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( sizeof( * V_2 ) , V_175 ) ;
if ( V_2 == NULL )
return - V_176 ;
V_18 -> V_2 = V_2 ;
V_2 -> V_187 . V_208 = 0 ;
V_2 -> V_187 . V_209 = 2 ;
V_2 -> V_187 . V_210 = V_192 ;
V_2 -> V_15 = 1 ;
V_2 -> V_16 [ 0 ] . V_13 = V_192 ;
V_2 -> V_179 = & V_211 ;
V_18 -> V_177 = V_212 ;
return 0 ;
}
static int F_97 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
int V_51 = F_96 ( V_18 ) ;
if ( V_51 < 0 )
return V_51 ;
V_2 = V_18 -> V_2 ;
V_2 -> V_187 . V_209 = 8 ;
V_2 -> V_179 = & V_213 ;
V_18 -> V_177 = V_214 ;
F_90 ( V_18 , 8 ) ;
return 0 ;
}
static int F_98 ( struct V_9 * V_10 ,
struct V_17 * V_18 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_148 = V_72 -> V_75 -> V_37 ;
int V_32 , V_51 ;
V_51 = F_88 ( V_10 , V_18 , V_104 , V_105 ,
V_72 ) ;
if ( V_51 < 0 )
return V_51 ;
F_8 ( V_18 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_31 , V_148 - 1 ) ;
for ( V_32 = 0 ; V_32 < V_148 ; V_32 ++ ) {
F_8 ( V_18 , V_2 -> V_16 [ 0 ] . V_13 , 0 ,
V_53 ,
( V_32 << 4 ) | V_32 ) ;
}
return 0 ;
}
static int F_99 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
F_83 ( V_18 , V_215 ) ;
if ( F_11 ( V_18 , V_2 -> V_6 [ 0 ] . V_3 ) & V_25 )
F_8 ( V_18 , V_2 -> V_6 [ 0 ] . V_3 , 0 ,
V_26 ,
V_27 ) ;
return 0 ;
}
static int F_100 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( sizeof( * V_2 ) , V_175 ) ;
if ( V_2 == NULL )
return - V_176 ;
V_18 -> V_2 = V_2 ;
V_2 -> V_187 . V_208 = 0 ;
V_2 -> V_187 . V_209 = 2 ;
V_2 -> V_187 . V_210 = V_216 ;
V_2 -> V_15 = 1 ;
V_2 -> V_16 [ 0 ] . V_13 = V_216 ;
V_2 -> V_6 [ 0 ] . V_3 = V_217 ;
V_2 -> V_179 = & V_218 ;
V_18 -> V_177 = V_219 ;
return 0 ;
}
static int T_4 F_101 ( void )
{
return F_102 ( & V_220 ) ;
}
static void T_5 F_103 ( void )
{
F_104 ( & V_220 ) ;
}
