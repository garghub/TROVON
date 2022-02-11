static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_2 -> V_6 )
return;
V_2 -> V_6 = NULL ;
F_2 ( & V_4 -> V_7 -> V_8 , L_1 ) ;
if ( F_3 ( V_9 , & V_4 -> V_10 ) )
F_4 ( & V_4 -> V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
T_1 V_13 ;
if ( V_12 == V_14 ) {
F_1 ( V_2 ) ;
return;
}
V_13 = F_6 ( V_2 , V_14 ) ;
if ( V_13 == V_15 )
F_1 ( V_2 ) ;
}
T_1 F_6 ( struct V_1 * V_2 , T_1 V_12 )
{
T_2 T_3 * V_16 = F_7 ( V_2 -> V_6 ) ;
T_1 V_13 ;
if ( F_8 ( V_16 ) )
return V_15 ;
V_13 = F_9 ( V_16 + V_12 ) ;
if ( F_10 ( V_13 == V_15 ) )
F_5 ( V_2 , V_12 ) ;
return V_13 ;
}
static void F_11 ( struct V_3 * V_4 , T_4 V_17 ,
T_2 V_18 , T_2 V_19 )
{
T_1 V_20 , V_21 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
if ( V_17 == - 1 ) {
V_19 |= V_22 ;
V_20 = F_12 ( V_2 , V_23 ) ;
V_20 &= ~ 0xFF ;
V_20 |= V_19 ;
F_13 ( V_2 , V_23 , V_20 ) ;
} else {
V_19 |= V_22 ;
V_21 = ( ( 16 * ( V_18 & 1 ) ) + ( 8 * V_17 ) ) ;
V_20 = F_12 ( V_2 , F_14 ( V_18 >> 1 ) ) ;
V_20 &= ~ ( 0xFF << V_21 ) ;
V_20 |= ( V_19 << V_21 ) ;
F_13 ( V_2 , F_14 ( V_18 >> 1 ) , V_20 ) ;
}
}
static void F_15 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
if ( V_27 -> V_28 ) {
F_16 ( V_27 -> V_28 ) ;
if ( F_17 ( V_27 , V_29 ) )
F_18 ( V_25 -> V_8 ,
F_19 ( V_27 , V_30 ) ,
F_17 ( V_27 , V_29 ) ,
V_31 ) ;
} else if ( F_17 ( V_27 , V_29 ) ) {
F_20 ( V_25 -> V_8 ,
F_19 ( V_27 , V_30 ) ,
F_17 ( V_27 , V_29 ) ,
V_31 ) ;
}
V_27 -> V_32 = NULL ;
V_27 -> V_28 = NULL ;
F_21 ( V_27 , V_29 , 0 ) ;
}
static bool F_22 ( struct V_33 * V_34 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = V_34 -> V_4 ;
struct V_26 * V_27 ;
union V_35 * V_36 ;
unsigned int V_37 = 0 , V_38 = 0 ;
unsigned int V_39 = V_25 -> V_40 / 2 ;
unsigned int V_41 = V_25 -> V_42 ;
if ( F_3 ( V_43 , & V_4 -> V_10 ) )
return true ;
V_27 = & V_25 -> V_44 [ V_41 ] ;
V_36 = F_23 ( V_25 , V_41 ) ;
V_41 -= V_25 -> V_40 ;
do {
union V_35 * V_45 = V_27 -> V_32 ;
if ( ! V_45 )
break;
F_24 () ;
if ( ! ( V_45 -> V_46 . V_47 & F_25 ( V_48 ) ) )
break;
V_27 -> V_32 = NULL ;
V_37 += V_27 -> V_49 ;
V_38 += V_27 -> V_50 ;
F_16 ( V_27 -> V_28 ) ;
F_18 ( V_25 -> V_8 ,
F_19 ( V_27 , V_30 ) ,
F_17 ( V_27 , V_29 ) ,
V_31 ) ;
V_27 -> V_28 = NULL ;
F_21 ( V_27 , V_29 , 0 ) ;
while ( V_36 != V_45 ) {
V_27 ++ ;
V_36 ++ ;
V_41 ++ ;
if ( F_10 ( ! V_41 ) ) {
V_41 -= V_25 -> V_40 ;
V_27 = V_25 -> V_44 ;
V_36 = F_23 ( V_25 , 0 ) ;
}
if ( F_17 ( V_27 , V_29 ) ) {
F_20 ( V_25 -> V_8 ,
F_19 ( V_27 , V_30 ) ,
F_17 ( V_27 , V_29 ) ,
V_31 ) ;
F_21 ( V_27 , V_29 , 0 ) ;
}
}
V_27 ++ ;
V_36 ++ ;
V_41 ++ ;
if ( F_10 ( ! V_41 ) ) {
V_41 -= V_25 -> V_40 ;
V_27 = V_25 -> V_44 ;
V_36 = F_23 ( V_25 , 0 ) ;
}
F_26 ( V_36 ) ;
V_39 -- ;
} while ( F_27 ( V_39 ) );
V_41 += V_25 -> V_40 ;
V_25 -> V_42 = V_41 ;
F_28 ( & V_25 -> V_51 ) ;
V_25 -> V_52 . V_53 += V_37 ;
V_25 -> V_52 . V_54 += V_38 ;
F_29 ( & V_25 -> V_51 ) ;
V_34 -> V_55 . V_37 += V_37 ;
V_34 -> V_55 . V_38 += V_38 ;
#define F_30 (DESC_NEEDED * 2)
if ( F_10 ( V_38 && F_31 ( V_25 -> V_56 ) &&
( F_32 ( V_25 ) >= F_30 ) ) ) {
F_33 () ;
if ( F_34 ( V_25 -> V_56 ,
V_25 -> V_57 ) &&
! F_3 ( V_43 , & V_4 -> V_10 ) ) {
F_35 ( V_25 -> V_56 ,
V_25 -> V_57 ) ;
++ V_25 -> V_58 . V_59 ;
}
}
return ! ! V_39 ;
}
static void F_36 ( struct V_33 * V_34 ,
struct V_60 * V_28 )
{
#ifdef F_37
F_38 ( V_28 , & V_34 -> V_61 ) ;
if ( F_39 ( V_34 ) ) {
F_40 ( V_28 ) ;
return;
}
#endif
F_41 ( & V_34 -> V_61 , V_28 ) ;
}
static inline void F_42 ( struct V_24 * V_62 ,
union V_63 * V_64 ,
struct V_60 * V_28 )
{
F_43 ( V_28 ) ;
if ( ! ( V_62 -> V_56 -> V_65 & V_66 ) )
return;
if ( F_44 ( V_64 , V_67 ) &&
F_44 ( V_64 , V_68 ) ) {
V_62 -> V_69 . V_70 ++ ;
return;
}
if ( ! F_44 ( V_64 , V_71 ) )
return;
if ( F_44 ( V_64 , V_72 ) ) {
V_62 -> V_69 . V_70 ++ ;
return;
}
V_28 -> V_73 = V_74 ;
}
static void F_45 ( struct V_24 * V_75 ,
union V_63 * V_64 ,
struct V_60 * V_28 )
{
F_42 ( V_75 , V_64 , V_28 ) ;
if ( F_44 ( V_64 , V_76 ) ) {
T_5 V_77 = F_46 ( V_64 -> V_46 . V_78 . V_79 ) ;
unsigned long * V_80 = F_47 ( V_75 -> V_56 ) ;
if ( F_3 ( V_77 & V_81 , V_80 ) )
F_48 ( V_28 , F_49 ( V_82 ) , V_77 ) ;
}
V_28 -> V_83 = F_50 ( V_28 , V_75 -> V_56 ) ;
}
static bool F_51 ( struct V_24 * V_75 ,
union V_63 * V_64 )
{
T_1 V_84 = V_75 -> V_42 + 1 ;
V_84 = ( V_84 < V_75 -> V_40 ) ? V_84 : 0 ;
V_75 -> V_42 = V_84 ;
F_26 ( F_52 ( V_75 , V_84 ) ) ;
if ( F_27 ( F_44 ( V_64 , V_85 ) ) )
return false ;
return true ;
}
static bool F_53 ( struct V_24 * V_75 ,
struct V_86 * V_87 )
{
struct V_88 * V_88 = V_87 -> V_88 ;
T_6 V_30 = V_87 -> V_30 ;
if ( F_27 ( V_88 ) )
return true ;
V_88 = F_54 () ;
if ( F_10 ( ! V_88 ) ) {
V_75 -> V_69 . V_89 ++ ;
return false ;
}
V_30 = F_55 ( V_75 -> V_8 , V_88 , 0 ,
V_90 , V_91 ) ;
if ( F_56 ( V_75 -> V_8 , V_30 ) ) {
F_57 ( V_88 ) ;
V_75 -> V_69 . V_92 ++ ;
return false ;
}
V_87 -> V_30 = V_30 ;
V_87 -> V_88 = V_88 ;
V_87 -> V_93 = 0 ;
return true ;
}
static void F_58 ( struct V_24 * V_75 ,
T_5 V_94 )
{
union V_63 * V_64 ;
struct V_86 * V_87 ;
unsigned int V_41 = V_75 -> V_95 ;
if ( ! V_94 || ! V_75 -> V_56 )
return;
V_64 = F_52 ( V_75 , V_41 ) ;
V_87 = & V_75 -> V_96 [ V_41 ] ;
V_41 -= V_75 -> V_40 ;
do {
if ( ! F_53 ( V_75 , V_87 ) )
break;
V_64 -> V_97 . V_98 = F_59 ( V_87 -> V_30 + V_87 -> V_93 ) ;
V_64 ++ ;
V_87 ++ ;
V_41 ++ ;
if ( F_10 ( ! V_41 ) ) {
V_64 = F_52 ( V_75 , 0 ) ;
V_87 = V_75 -> V_96 ;
V_41 -= V_75 -> V_40 ;
}
V_64 -> V_97 . V_99 = 0 ;
V_94 -- ;
} while ( V_94 );
V_41 += V_75 -> V_40 ;
if ( V_75 -> V_95 != V_41 ) {
V_75 -> V_95 = V_41 ;
V_75 -> V_100 = V_41 ;
F_60 () ;
F_61 ( V_75 , V_41 ) ;
}
}
static void F_62 ( struct V_24 * V_75 ,
struct V_60 * V_28 )
{
struct V_101 * V_102 = & F_63 ( V_28 ) -> V_103 [ 0 ] ;
unsigned char * V_104 ;
unsigned int V_105 ;
V_104 = F_64 ( V_102 ) ;
V_105 = F_65 ( V_104 , V_106 ) ;
F_66 ( V_28 , V_104 , F_67 ( V_105 , sizeof( long ) ) ) ;
F_68 ( V_102 , V_105 ) ;
V_102 -> V_93 += V_105 ;
V_28 -> V_107 -= V_105 ;
V_28 -> V_108 += V_105 ;
}
static bool F_69 ( struct V_24 * V_75 ,
union V_63 * V_64 ,
struct V_60 * V_28 )
{
if ( F_10 ( F_44 ( V_64 ,
V_109 ) ) ) {
struct V_110 * V_56 = V_75 -> V_56 ;
if ( ! ( V_56 -> V_65 & V_111 ) ) {
F_16 ( V_28 ) ;
return true ;
}
}
if ( F_70 ( V_28 ) )
F_62 ( V_75 , V_28 ) ;
if ( F_71 ( V_28 ) )
return true ;
return false ;
}
static void F_72 ( struct V_24 * V_75 ,
struct V_86 * V_112 )
{
struct V_86 * V_113 ;
T_5 V_114 = V_75 -> V_100 ;
V_113 = & V_75 -> V_96 [ V_114 ] ;
V_114 ++ ;
V_75 -> V_100 = ( V_114 < V_75 -> V_40 ) ? V_114 : 0 ;
V_113 -> V_88 = V_112 -> V_88 ;
V_113 -> V_30 = V_112 -> V_30 ;
V_113 -> V_93 = V_112 -> V_93 ;
F_73 ( V_75 -> V_8 , V_113 -> V_30 ,
V_113 -> V_93 ,
V_115 ,
V_91 ) ;
}
static inline bool F_74 ( struct V_88 * V_88 )
{
return ( F_75 ( V_88 ) != F_76 () ) || V_88 -> V_116 ;
}
static bool F_77 ( struct V_24 * V_75 ,
struct V_86 * V_117 ,
union V_63 * V_64 ,
struct V_60 * V_28 )
{
struct V_88 * V_88 = V_117 -> V_88 ;
unsigned int V_118 = F_46 ( V_64 -> V_46 . V_78 . V_119 ) ;
#if ( V_90 < 8192 )
unsigned int V_120 = V_115 ;
#else
unsigned int V_120 = F_67 ( V_118 , V_121 ) ;
#endif
if ( ( V_118 <= V_106 ) && ! F_70 ( V_28 ) ) {
unsigned char * V_104 = F_78 ( V_88 ) + V_117 -> V_93 ;
memcpy ( F_79 ( V_28 , V_118 ) , V_104 , F_67 ( V_118 , sizeof( long ) ) ) ;
if ( F_27 ( ! F_74 ( V_88 ) ) )
return true ;
F_80 ( V_88 ) ;
return false ;
}
F_81 ( V_28 , F_63 ( V_28 ) -> V_122 , V_88 ,
V_117 -> V_93 , V_118 , V_120 ) ;
if ( F_10 ( F_74 ( V_88 ) ) )
return false ;
#if ( V_90 < 8192 )
if ( F_10 ( F_82 ( V_88 ) != 1 ) )
return false ;
V_117 -> V_93 ^= V_115 ;
#else
V_117 -> V_93 += V_120 ;
if ( V_117 -> V_93 > ( V_90 - V_115 ) )
return false ;
#endif
F_83 ( & V_88 -> V_123 ) ;
return true ;
}
static struct V_60 * F_84 ( struct V_24 * V_75 ,
union V_63 * V_64 ,
struct V_60 * V_28 )
{
struct V_86 * V_117 ;
struct V_88 * V_88 ;
V_117 = & V_75 -> V_96 [ V_75 -> V_42 ] ;
V_88 = V_117 -> V_88 ;
F_85 ( V_88 ) ;
if ( F_27 ( ! V_28 ) ) {
void * V_124 = F_78 ( V_88 ) +
V_117 -> V_93 ;
F_26 ( V_124 ) ;
#if V_121 < 128
F_26 ( V_124 + V_121 ) ;
#endif
V_28 = F_86 ( V_75 -> V_56 ,
V_106 ) ;
if ( F_10 ( ! V_28 ) ) {
V_75 -> V_69 . V_92 ++ ;
return NULL ;
}
F_85 ( V_28 -> V_125 ) ;
}
F_87 ( V_75 -> V_8 ,
V_117 -> V_30 ,
V_117 -> V_93 ,
V_115 ,
V_91 ) ;
if ( F_77 ( V_75 , V_117 , V_64 , V_28 ) ) {
F_72 ( V_75 , V_117 ) ;
} else {
F_20 ( V_75 -> V_8 , V_117 -> V_30 ,
V_90 , V_91 ) ;
}
V_117 -> V_30 = 0 ;
V_117 -> V_88 = NULL ;
return V_28 ;
}
static inline void F_88 ( struct V_3 * V_4 ,
T_1 V_126 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_13 ( V_2 , V_127 , V_126 ) ;
}
static int F_89 ( struct V_33 * V_34 ,
struct V_24 * V_75 ,
int V_39 )
{
unsigned int V_128 = 0 , V_129 = 0 ;
T_5 V_94 = F_32 ( V_75 ) ;
struct V_60 * V_28 = V_75 -> V_28 ;
while ( F_27 ( V_129 < V_39 ) ) {
union V_63 * V_64 ;
if ( V_94 >= V_130 ) {
F_58 ( V_75 , V_94 ) ;
V_94 = 0 ;
}
V_64 = F_52 ( V_75 , V_75 -> V_42 ) ;
if ( ! F_44 ( V_64 , V_131 ) )
break;
F_90 () ;
V_28 = F_84 ( V_75 , V_64 , V_28 ) ;
if ( ! V_28 )
break;
V_94 ++ ;
if ( F_51 ( V_75 , V_64 ) )
continue;
if ( F_69 ( V_75 , V_64 , V_28 ) ) {
V_28 = NULL ;
continue;
}
V_128 += V_28 -> V_29 ;
if ( ( V_28 -> V_132 == V_133 ||
V_28 -> V_132 == V_134 ) &&
F_91 ( V_75 -> V_56 -> V_135 ,
F_92 ( V_28 ) -> V_136 ) ) {
F_93 ( V_28 ) ;
continue;
}
F_45 ( V_75 , V_64 , V_28 ) ;
F_36 ( V_34 , V_28 ) ;
V_28 = NULL ;
V_129 ++ ;
}
V_75 -> V_28 = V_28 ;
F_28 ( & V_75 -> V_51 ) ;
V_75 -> V_52 . V_54 += V_129 ;
V_75 -> V_52 . V_53 += V_128 ;
F_29 ( & V_75 -> V_51 ) ;
V_34 -> V_137 . V_38 += V_129 ;
V_34 -> V_137 . V_37 += V_128 ;
return V_129 ;
}
static int F_94 ( struct V_138 * V_61 , int V_39 )
{
struct V_33 * V_34 =
F_95 ( V_61 , struct V_33 , V_61 ) ;
struct V_3 * V_4 = V_34 -> V_4 ;
struct V_24 * V_62 ;
int V_139 ;
bool V_140 = true ;
F_96 (ring, q_vector->tx)
V_140 &= F_22 ( V_34 , V_62 ) ;
#ifdef F_37
if ( ! F_97 ( V_34 ) )
return V_39 ;
#endif
if ( V_34 -> V_137 . V_40 > 1 )
V_139 = F_98 ( V_39 / V_34 -> V_137 . V_40 , 1 ) ;
else
V_139 = V_39 ;
F_96 (ring, q_vector->rx)
V_140 &= ( F_89 ( V_34 , V_62 ,
V_139 )
< V_139 ) ;
#ifdef F_37
F_99 ( V_34 ) ;
#endif
if ( ! V_140 )
return V_39 ;
F_100 ( V_61 ) ;
if ( V_4 -> V_141 & 1 )
F_101 ( V_34 ) ;
if ( ! F_3 ( V_43 , & V_4 -> V_10 ) &&
! F_3 ( V_142 , & V_4 -> V_10 ) )
F_88 ( V_4 ,
1 << V_34 -> V_143 ) ;
return 0 ;
}
void F_102 ( struct V_33 * V_34 )
{
struct V_3 * V_4 = V_34 -> V_4 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_143 = V_34 -> V_143 ;
T_1 V_144 = V_34 -> V_145 & V_146 ;
V_144 |= V_147 ;
F_13 ( V_2 , F_103 ( V_143 ) , V_144 ) ;
}
static int F_104 ( struct V_138 * V_61 )
{
struct V_33 * V_34 =
F_95 ( V_61 , struct V_33 , V_61 ) ;
struct V_3 * V_4 = V_34 -> V_4 ;
struct V_24 * V_62 ;
int V_148 = 0 ;
if ( F_3 ( V_43 , & V_4 -> V_10 ) )
return V_149 ;
if ( ! F_105 ( V_34 ) )
return V_150 ;
F_96 (ring, q_vector->rx) {
V_148 = F_89 ( V_34 , V_62 , 4 ) ;
#ifdef F_106
if ( V_148 )
V_62 -> V_52 . V_151 += V_148 ;
else
V_62 -> V_52 . V_152 ++ ;
#endif
if ( V_148 )
break;
}
F_107 ( V_34 ) ;
return V_148 ;
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_33 * V_34 ;
int V_153 , V_143 ;
V_153 = V_4 -> V_154 - V_155 ;
V_4 -> V_156 = 0 ;
for ( V_143 = 0 ; V_143 < V_153 ; V_143 ++ ) {
struct V_24 * V_62 ;
V_34 = V_4 -> V_34 [ V_143 ] ;
F_96 (ring, q_vector->rx)
F_11 ( V_4 , 0 , V_62 -> V_157 , V_143 ) ;
F_96 (ring, q_vector->tx)
F_11 ( V_4 , 1 , V_62 -> V_157 , V_143 ) ;
if ( V_34 -> V_55 . V_62 && ! V_34 -> V_137 . V_62 ) {
if ( V_4 -> V_158 == 1 )
V_34 -> V_145 = V_159 ;
else
V_34 -> V_145 = V_4 -> V_158 ;
} else {
if ( V_4 -> V_141 == 1 )
V_34 -> V_145 = V_160 ;
else
V_34 -> V_145 = V_4 -> V_141 ;
}
V_4 -> V_156 |= 1 << V_143 ;
F_102 ( V_34 ) ;
}
F_11 ( V_4 , - 1 , 1 , V_143 ) ;
V_4 -> V_161 = 1 << V_143 ;
V_4 -> V_156 |= V_4 -> V_161 ;
}
static void F_109 ( struct V_33 * V_34 ,
struct V_162 * V_163 )
{
int V_53 = V_163 -> V_37 ;
int V_54 = V_163 -> V_38 ;
T_1 V_164 ;
T_7 V_165 ;
T_2 V_166 = V_163 -> V_145 ;
if ( V_54 == 0 )
return;
V_164 = V_34 -> V_145 >> 2 ;
V_165 = V_53 / V_164 ;
switch ( V_166 ) {
case V_167 :
if ( V_165 > 10 )
V_166 = V_168 ;
break;
case V_168 :
if ( V_165 > 20 )
V_166 = V_169 ;
else if ( V_165 <= 10 )
V_166 = V_167 ;
break;
case V_169 :
if ( V_165 <= 20 )
V_166 = V_168 ;
break;
}
V_163 -> V_37 = 0 ;
V_163 -> V_38 = 0 ;
V_163 -> V_145 = V_166 ;
}
static void F_101 ( struct V_33 * V_34 )
{
T_1 V_170 = V_34 -> V_145 ;
T_2 V_171 ;
F_109 ( V_34 , & V_34 -> V_55 ) ;
F_109 ( V_34 , & V_34 -> V_137 ) ;
V_171 = F_98 ( V_34 -> V_137 . V_145 , V_34 -> V_55 . V_145 ) ;
switch ( V_171 ) {
case V_167 :
V_170 = V_172 ;
break;
case V_168 :
V_170 = V_160 ;
break;
case V_169 :
default:
V_170 = V_173 ;
break;
}
if ( V_170 != V_34 -> V_145 ) {
V_170 = ( 10 * V_170 * V_34 -> V_145 ) /
( ( 9 * V_170 ) + V_34 -> V_145 ) ;
V_34 -> V_145 = V_170 ;
F_102 ( V_34 ) ;
}
}
static T_8 F_110 ( int V_174 , void * V_125 )
{
struct V_3 * V_4 = V_125 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
V_2 -> V_175 . V_176 = 1 ;
if ( ! F_3 ( V_43 , & V_4 -> V_10 ) &&
! F_3 ( V_142 , & V_4 -> V_10 ) )
F_111 ( & V_4 -> V_177 , V_178 ) ;
F_13 ( V_2 , V_127 , V_4 -> V_161 ) ;
return V_179 ;
}
static T_8 F_112 ( int V_174 , void * V_125 )
{
struct V_33 * V_34 = V_125 ;
if ( V_34 -> V_137 . V_62 || V_34 -> V_55 . V_62 )
F_113 ( & V_34 -> V_61 ) ;
return V_179 ;
}
static inline void F_114 ( struct V_3 * V_180 , int V_143 ,
int V_181 )
{
struct V_33 * V_34 = V_180 -> V_34 [ V_143 ] ;
V_180 -> V_75 [ V_181 ] -> V_182 = V_34 -> V_137 . V_62 ;
V_34 -> V_137 . V_62 = V_180 -> V_75 [ V_181 ] ;
V_34 -> V_137 . V_40 ++ ;
}
static inline void F_115 ( struct V_3 * V_180 , int V_143 ,
int V_183 )
{
struct V_33 * V_34 = V_180 -> V_34 [ V_143 ] ;
V_180 -> V_25 [ V_183 ] -> V_182 = V_34 -> V_55 . V_62 ;
V_34 -> V_55 . V_62 = V_180 -> V_25 [ V_183 ] ;
V_34 -> V_55 . V_40 ++ ;
}
static int F_116 ( struct V_3 * V_4 )
{
int V_153 ;
int V_184 = 0 ;
int V_185 = 0 , V_186 = 0 ;
int V_187 = V_4 -> V_188 ;
int V_189 = V_4 -> V_190 ;
int V_41 , V_191 ;
int V_192 , V_193 ;
int V_194 = 0 ;
V_153 = V_4 -> V_154 - V_155 ;
if ( V_153 == V_4 -> V_188 + V_4 -> V_190 ) {
for (; V_185 < V_187 ; V_184 ++ , V_185 ++ )
F_114 ( V_4 , V_184 , V_185 ) ;
for (; V_186 < V_189 ; V_184 ++ , V_186 ++ )
F_115 ( V_4 , V_184 , V_186 ) ;
goto V_195;
}
for ( V_41 = V_184 ; V_41 < V_153 ; V_41 ++ ) {
V_192 = F_117 ( V_187 , V_153 - V_41 ) ;
for ( V_191 = 0 ; V_191 < V_192 ; V_191 ++ ) {
F_114 ( V_4 , V_41 , V_185 ) ;
V_185 ++ ;
V_187 -- ;
}
}
for ( V_41 = V_184 ; V_41 < V_153 ; V_41 ++ ) {
V_193 = F_117 ( V_189 , V_153 - V_41 ) ;
for ( V_191 = 0 ; V_191 < V_193 ; V_191 ++ ) {
F_115 ( V_4 , V_41 , V_186 ) ;
V_186 ++ ;
V_189 -- ;
}
}
V_195:
return V_194 ;
}
static int F_118 ( struct V_3 * V_4 )
{
struct V_110 * V_56 = V_4 -> V_56 ;
int V_153 = V_4 -> V_154 - V_155 ;
int V_196 , V_194 ;
int V_197 = 0 , V_198 = 0 ;
for ( V_196 = 0 ; V_196 < V_153 ; V_196 ++ ) {
struct V_33 * V_34 = V_4 -> V_34 [ V_196 ] ;
struct V_199 * V_200 = & V_4 -> V_201 [ V_196 ] ;
if ( V_34 -> V_55 . V_62 && V_34 -> V_137 . V_62 ) {
snprintf ( V_34 -> V_202 , sizeof( V_34 -> V_202 ) - 1 ,
L_2 , V_56 -> V_202 , L_3 , V_197 ++ ) ;
V_198 ++ ;
} else if ( V_34 -> V_137 . V_62 ) {
snprintf ( V_34 -> V_202 , sizeof( V_34 -> V_202 ) - 1 ,
L_2 , V_56 -> V_202 , L_4 , V_197 ++ ) ;
} else if ( V_34 -> V_55 . V_62 ) {
snprintf ( V_34 -> V_202 , sizeof( V_34 -> V_202 ) - 1 ,
L_2 , V_56 -> V_202 , L_5 , V_198 ++ ) ;
} else {
continue;
}
V_194 = F_119 ( V_200 -> V_196 , & F_112 , 0 ,
V_34 -> V_202 , V_34 ) ;
if ( V_194 ) {
F_120 ( & V_4 -> V_2 ,
L_6
L_7 , V_194 ) ;
goto V_203;
}
}
V_194 = F_119 ( V_4 -> V_201 [ V_196 ] . V_196 ,
& F_110 , 0 , V_56 -> V_202 , V_4 ) ;
if ( V_194 ) {
F_120 ( & V_4 -> V_2 ,
L_8 , V_194 ) ;
goto V_203;
}
return 0 ;
V_203:
while ( V_196 ) {
V_196 -- ;
F_121 ( V_4 -> V_201 [ V_196 ] . V_196 ,
V_4 -> V_34 [ V_196 ] ) ;
}
V_4 -> V_154 = 0 ;
return V_194 ;
}
static inline void F_122 ( struct V_3 * V_4 )
{
int V_41 , V_153 = V_4 -> V_154 - V_155 ;
for ( V_41 = 0 ; V_41 < V_153 ; V_41 ++ ) {
struct V_33 * V_34 = V_4 -> V_34 [ V_41 ] ;
V_34 -> V_137 . V_62 = NULL ;
V_34 -> V_55 . V_62 = NULL ;
V_34 -> V_137 . V_40 = 0 ;
V_34 -> V_55 . V_40 = 0 ;
}
}
static int F_123 ( struct V_3 * V_4 )
{
int V_194 = 0 ;
V_194 = F_118 ( V_4 ) ;
if ( V_194 )
F_120 ( & V_4 -> V_2 ,
L_9 , V_194 ) ;
return V_194 ;
}
static void F_124 ( struct V_3 * V_4 )
{
int V_41 , V_153 ;
V_153 = V_4 -> V_154 ;
V_41 = V_153 - 1 ;
F_121 ( V_4 -> V_201 [ V_41 ] . V_196 , V_4 ) ;
V_41 -- ;
for (; V_41 >= 0 ; V_41 -- ) {
if ( ! V_4 -> V_34 [ V_41 ] -> V_137 . V_62 &&
! V_4 -> V_34 [ V_41 ] -> V_55 . V_62 )
continue;
F_121 ( V_4 -> V_201 [ V_41 ] . V_196 ,
V_4 -> V_34 [ V_41 ] ) ;
}
F_122 ( V_4 ) ;
}
static inline void F_125 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_41 ;
F_13 ( V_2 , V_204 , 0 ) ;
F_13 ( V_2 , V_205 , ~ 0 ) ;
F_13 ( V_2 , V_206 , 0 ) ;
F_126 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_154 ; V_41 ++ )
F_127 ( V_4 -> V_201 [ V_41 ] . V_196 ) ;
}
static inline void F_128 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_13 ( V_2 , V_204 , V_4 -> V_156 ) ;
F_13 ( V_2 , V_206 , V_4 -> V_156 ) ;
F_13 ( V_2 , V_127 , V_4 -> V_156 ) ;
}
static void F_129 ( struct V_3 * V_4 ,
struct V_24 * V_62 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
T_7 V_207 = V_62 -> V_30 ;
int V_208 = 10 ;
T_1 V_209 = V_210 ;
T_2 V_157 = V_62 -> V_157 ;
F_13 ( V_2 , F_130 ( V_157 ) , V_211 ) ;
F_126 ( V_2 ) ;
F_13 ( V_2 , F_131 ( V_157 ) , V_207 & F_132 ( 32 ) ) ;
F_13 ( V_2 , F_133 ( V_157 ) , V_207 >> 32 ) ;
F_13 ( V_2 , F_134 ( V_157 ) ,
V_62 -> V_40 * sizeof( union V_35 ) ) ;
F_13 ( V_2 , F_135 ( V_157 ) , 0 ) ;
F_13 ( V_2 , F_136 ( V_157 ) , 0 ) ;
F_13 ( V_2 , F_137 ( V_157 ) ,
( V_212 |
V_213 ) ) ;
F_13 ( V_2 , F_138 ( V_157 ) , 0 ) ;
F_13 ( V_2 , F_139 ( V_157 ) , 0 ) ;
V_62 -> V_108 = V_4 -> V_214 + F_139 ( V_157 ) ;
V_62 -> V_42 = 0 ;
V_62 -> V_95 = 0 ;
V_209 |= ( 8 << 16 ) ;
V_209 |= ( 1 << 8 ) |
32 ;
F_13 ( V_2 , F_130 ( V_157 ) , V_209 ) ;
do {
F_140 ( 1000 , 2000 ) ;
V_209 = F_12 ( V_2 , F_130 ( V_157 ) ) ;
} while ( -- V_208 && ! ( V_209 & V_210 ) );
if ( ! V_208 )
F_141 ( L_10 , V_157 ) ;
}
static void F_142 ( struct V_3 * V_4 )
{
T_1 V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_190 ; V_41 ++ )
F_129 ( V_4 , V_4 -> V_25 [ V_41 ] ) ;
}
static void F_143 ( struct V_3 * V_4 , int V_21 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
T_1 V_215 ;
V_215 = V_216 ;
V_215 |= V_106 << V_217 ;
V_215 |= V_115 >> V_218 ;
V_215 |= V_219 ;
F_13 ( V_2 , F_144 ( V_21 ) , V_215 ) ;
}
static void F_145 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
T_1 V_220 = V_221 | V_222 |
V_223 | V_224 |
V_225 ;
if ( V_4 -> V_188 > 1 )
V_220 |= 1 << 29 ;
F_13 ( V_2 , V_226 , V_220 ) ;
}
static void F_146 ( struct V_3 * V_4 ,
struct V_24 * V_62 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_208 = V_227 ;
T_1 V_228 ;
T_2 V_157 = V_62 -> V_157 ;
if ( F_8 ( V_2 -> V_6 ) )
return;
V_228 = F_12 ( V_2 , F_147 ( V_157 ) ) ;
V_228 &= ~ V_229 ;
F_13 ( V_2 , F_147 ( V_157 ) , V_228 ) ;
do {
F_148 ( 10 ) ;
V_228 = F_12 ( V_2 , F_147 ( V_157 ) ) ;
} while ( -- V_208 && ( V_228 & V_229 ) );
if ( ! V_208 )
F_141 ( L_11 ,
V_157 ) ;
}
static void F_149 ( struct V_3 * V_4 ,
struct V_24 * V_62 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_208 = V_227 ;
T_1 V_228 ;
T_2 V_157 = V_62 -> V_157 ;
if ( F_8 ( V_2 -> V_6 ) )
return;
do {
F_140 ( 1000 , 2000 ) ;
V_228 = F_12 ( V_2 , F_147 ( V_157 ) ) ;
} while ( -- V_208 && ! ( V_228 & V_229 ) );
if ( ! V_208 )
F_141 ( L_12 ,
V_157 ) ;
}
static void F_150 ( struct V_3 * V_4 ,
struct V_24 * V_62 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
T_7 V_230 = V_62 -> V_30 ;
T_1 V_228 ;
T_2 V_157 = V_62 -> V_157 ;
V_228 = F_12 ( V_2 , F_147 ( V_157 ) ) ;
F_146 ( V_4 , V_62 ) ;
F_13 ( V_2 , F_151 ( V_157 ) , V_230 & F_132 ( 32 ) ) ;
F_13 ( V_2 , F_152 ( V_157 ) , V_230 >> 32 ) ;
F_13 ( V_2 , F_153 ( V_157 ) ,
V_62 -> V_40 * sizeof( union V_63 ) ) ;
F_13 ( V_2 , F_154 ( V_157 ) ,
V_231 ) ;
F_13 ( V_2 , F_155 ( V_157 ) , 0 ) ;
F_13 ( V_2 , F_156 ( V_157 ) , 0 ) ;
V_62 -> V_108 = V_4 -> V_214 + F_156 ( V_157 ) ;
V_62 -> V_42 = 0 ;
V_62 -> V_95 = 0 ;
V_62 -> V_100 = 0 ;
F_143 ( V_4 , V_157 ) ;
V_228 &= ~ V_232 ;
V_228 |= V_229 | V_233 ;
F_13 ( V_2 , F_147 ( V_157 ) , V_228 ) ;
F_149 ( V_4 , V_62 ) ;
F_58 ( V_62 , F_32 ( V_62 ) ) ;
}
static void F_157 ( struct V_3 * V_4 )
{
int V_41 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_110 * V_56 = V_4 -> V_56 ;
F_145 ( V_4 ) ;
F_158 ( V_2 , V_56 -> V_234 + V_235 + V_236 ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_188 ; V_41 ++ )
F_150 ( V_4 , V_4 -> V_75 [ V_41 ] ) ;
}
static int F_159 ( struct V_110 * V_56 ,
T_9 V_237 , T_5 V_77 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_194 ;
F_160 ( & V_4 -> V_238 ) ;
V_194 = V_2 -> V_175 . V_239 . V_240 ( V_2 , V_77 , 0 , true ) ;
F_161 ( & V_4 -> V_238 ) ;
if ( V_194 == V_241 )
return - V_242 ;
if ( V_194 == V_243 )
return - V_244 ;
F_162 ( V_77 , V_4 -> V_80 ) ;
return V_194 ;
}
static int F_163 ( struct V_110 * V_56 ,
T_9 V_237 , T_5 V_77 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_194 = - V_245 ;
F_160 ( & V_4 -> V_238 ) ;
V_194 = V_2 -> V_175 . V_239 . V_240 ( V_2 , V_77 , 0 , false ) ;
F_161 ( & V_4 -> V_238 ) ;
F_164 ( V_77 , V_4 -> V_80 ) ;
return V_194 ;
}
static void F_165 ( struct V_3 * V_4 )
{
T_5 V_77 ;
F_166 (vid, adapter->active_vlans, VLAN_N_VID)
F_159 ( V_4 -> V_56 ,
F_49 ( V_82 ) , V_77 ) ;
}
static int F_167 ( struct V_110 * V_56 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_40 = 0 ;
if ( ( F_168 ( V_56 ) ) > 10 ) {
F_141 ( L_13 ) ;
return - V_246 ;
}
if ( ! F_169 ( V_56 ) ) {
struct V_247 * V_248 ;
F_170 (ha, netdev) {
V_2 -> V_175 . V_239 . V_249 ( V_2 , ++ V_40 , V_248 -> V_250 ) ;
F_148 ( 200 ) ;
}
} else {
V_2 -> V_175 . V_239 . V_249 ( V_2 , 0 , NULL ) ;
}
return V_40 ;
}
static void F_171 ( struct V_110 * V_56 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
F_160 ( & V_4 -> V_238 ) ;
V_2 -> V_175 . V_239 . V_251 ( V_2 , V_56 ) ;
F_167 ( V_56 ) ;
F_161 ( & V_4 -> V_238 ) ;
}
static void F_172 ( struct V_3 * V_4 )
{
int V_252 ;
struct V_33 * V_34 ;
int V_153 = V_4 -> V_154 - V_155 ;
for ( V_252 = 0 ; V_252 < V_153 ; V_252 ++ ) {
V_34 = V_4 -> V_34 [ V_252 ] ;
#ifdef F_37
F_173 ( V_4 -> V_34 [ V_252 ] ) ;
#endif
F_174 ( & V_34 -> V_61 ) ;
}
}
static void F_175 ( struct V_3 * V_4 )
{
int V_252 ;
struct V_33 * V_34 ;
int V_153 = V_4 -> V_154 - V_155 ;
for ( V_252 = 0 ; V_252 < V_153 ; V_252 ++ ) {
V_34 = V_4 -> V_34 [ V_252 ] ;
F_176 ( & V_34 -> V_61 ) ;
#ifdef F_37
while ( ! F_177 ( V_4 -> V_34 [ V_252 ] ) ) {
F_178 ( L_14 , V_252 ) ;
F_140 ( 1000 , 20000 ) ;
}
#endif
}
}
static int F_179 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
unsigned int V_253 = 0 ;
unsigned int V_254 = 0 ;
unsigned int V_188 = 1 ;
int V_194 ;
F_160 ( & V_4 -> V_238 ) ;
V_194 = F_180 ( V_2 , & V_254 , & V_253 ) ;
F_161 ( & V_4 -> V_238 ) ;
if ( V_194 )
return V_194 ;
if ( V_254 > 1 ) {
V_4 -> V_25 [ 0 ] -> V_157 = V_253 ;
V_188 = V_254 ;
}
if ( V_4 -> V_188 != V_188 ) {
V_2 -> V_255 . V_256 = 0 ;
V_4 -> V_257 |= V_258 ;
}
return 0 ;
}
static void F_181 ( struct V_3 * V_4 )
{
F_179 ( V_4 ) ;
F_171 ( V_4 -> V_56 ) ;
F_165 ( V_4 ) ;
F_142 ( V_4 ) ;
F_157 ( V_4 ) ;
}
static void F_182 ( struct V_3 * V_4 )
{
if ( V_4 -> V_52 . V_259 || V_4 -> V_52 . V_260 ) {
V_4 -> V_52 . V_261 += V_4 -> V_52 . V_259 -
V_4 -> V_52 . V_262 ;
V_4 -> V_52 . V_263 += V_4 -> V_52 . V_260 -
V_4 -> V_52 . V_264 ;
V_4 -> V_52 . V_265 += V_4 -> V_52 . V_266 -
V_4 -> V_52 . V_267 ;
V_4 -> V_52 . V_268 += V_4 -> V_52 . V_269 -
V_4 -> V_52 . V_270 ;
V_4 -> V_52 . V_271 += V_4 -> V_52 . V_272 -
V_4 -> V_52 . V_273 ;
}
}
static void F_183 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
V_4 -> V_52 . V_274 = F_12 ( V_2 , V_275 ) ;
V_4 -> V_52 . V_276 = F_12 ( V_2 , V_277 ) ;
V_4 -> V_52 . V_276 |=
( ( ( T_7 ) ( F_12 ( V_2 , V_278 ) ) ) << 32 ) ;
V_4 -> V_52 . V_279 = F_12 ( V_2 , V_280 ) ;
V_4 -> V_52 . V_281 = F_12 ( V_2 , V_282 ) ;
V_4 -> V_52 . V_281 |=
( ( ( T_7 ) ( F_12 ( V_2 , V_283 ) ) ) << 32 ) ;
V_4 -> V_52 . V_284 = F_12 ( V_2 , V_285 ) ;
V_4 -> V_52 . V_262 = V_4 -> V_52 . V_274 ;
V_4 -> V_52 . V_267 = V_4 -> V_52 . V_276 ;
V_4 -> V_52 . V_264 = V_4 -> V_52 . V_279 ;
V_4 -> V_52 . V_270 = V_4 -> V_52 . V_281 ;
V_4 -> V_52 . V_273 = V_4 -> V_52 . V_284 ;
}
static void F_184 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_286 [] = { V_287 ,
V_288 ,
V_289 } ;
int V_194 = 0 , V_290 = 0 ;
F_160 ( & V_4 -> V_238 ) ;
while ( V_286 [ V_290 ] != V_289 ) {
V_194 = F_185 ( V_2 , V_286 [ V_290 ] ) ;
if ( ! V_194 )
break;
V_290 ++ ;
}
F_161 ( & V_4 -> V_238 ) ;
}
static void F_186 ( struct V_3 * V_4 )
{
struct V_110 * V_56 = V_4 -> V_56 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
F_108 ( V_4 ) ;
F_160 ( & V_4 -> V_238 ) ;
if ( F_187 ( V_2 -> V_175 . V_250 ) )
V_2 -> V_175 . V_239 . V_291 ( V_2 , 0 , V_2 -> V_175 . V_250 , 0 ) ;
else
V_2 -> V_175 . V_239 . V_291 ( V_2 , 0 , V_2 -> V_175 . V_292 , 0 ) ;
F_161 ( & V_4 -> V_238 ) ;
F_188 () ;
F_164 ( V_43 , & V_4 -> V_10 ) ;
F_172 ( V_4 ) ;
F_189 ( V_56 ) ;
F_182 ( V_4 ) ;
F_183 ( V_4 ) ;
V_2 -> V_175 . V_176 = 1 ;
F_111 ( & V_4 -> V_177 , V_178 ) ;
}
void F_190 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_181 ( V_4 ) ;
F_186 ( V_4 ) ;
F_12 ( V_2 , V_293 ) ;
F_128 ( V_4 ) ;
}
static void F_191 ( struct V_24 * V_75 )
{
struct V_294 * V_8 = V_75 -> V_8 ;
unsigned long V_118 ;
unsigned int V_41 ;
if ( V_75 -> V_28 ) {
F_192 ( V_75 -> V_28 ) ;
V_75 -> V_28 = NULL ;
}
if ( ! V_75 -> V_96 )
return;
for ( V_41 = 0 ; V_41 < V_75 -> V_40 ; V_41 ++ ) {
struct V_86 * V_117 ;
V_117 = & V_75 -> V_96 [ V_41 ] ;
if ( V_117 -> V_30 )
F_20 ( V_8 , V_117 -> V_30 ,
V_90 , V_91 ) ;
V_117 -> V_30 = 0 ;
if ( V_117 -> V_88 )
F_57 ( V_117 -> V_88 ) ;
V_117 -> V_88 = NULL ;
}
V_118 = sizeof( struct V_86 ) * V_75 -> V_40 ;
memset ( V_75 -> V_96 , 0 , V_118 ) ;
memset ( V_75 -> V_295 , 0 , V_75 -> V_118 ) ;
}
static void F_193 ( struct V_24 * V_25 )
{
struct V_26 * V_44 ;
unsigned long V_118 ;
unsigned int V_41 ;
if ( ! V_25 -> V_44 )
return;
for ( V_41 = 0 ; V_41 < V_25 -> V_40 ; V_41 ++ ) {
V_44 = & V_25 -> V_44 [ V_41 ] ;
F_15 ( V_25 , V_44 ) ;
}
V_118 = sizeof( struct V_26 ) * V_25 -> V_40 ;
memset ( V_25 -> V_44 , 0 , V_118 ) ;
memset ( V_25 -> V_295 , 0 , V_25 -> V_118 ) ;
}
static void F_194 ( struct V_3 * V_4 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_188 ; V_41 ++ )
F_191 ( V_4 -> V_75 [ V_41 ] ) ;
}
static void F_195 ( struct V_3 * V_4 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_190 ; V_41 ++ )
F_193 ( V_4 -> V_25 [ V_41 ] ) ;
}
void F_196 ( struct V_3 * V_4 )
{
struct V_110 * V_56 = V_4 -> V_56 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_41 ;
if ( F_197 ( V_43 , & V_4 -> V_10 ) )
return;
for ( V_41 = 0 ; V_41 < V_4 -> V_188 ; V_41 ++ )
F_146 ( V_4 , V_4 -> V_75 [ V_41 ] ) ;
F_198 ( V_56 ) ;
F_199 ( 10 ) ;
F_200 ( V_56 ) ;
F_125 ( V_4 ) ;
F_175 ( V_4 ) ;
F_201 ( & V_4 -> V_177 ) ;
while ( V_4 -> V_257 & V_296 )
F_199 ( 1 ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_190 ; V_41 ++ ) {
T_2 V_157 = V_4 -> V_25 [ V_41 ] -> V_157 ;
F_13 ( V_2 , F_130 ( V_157 ) ,
V_211 ) ;
}
F_202 ( V_56 ) ;
if ( ! F_203 ( V_4 -> V_7 ) )
F_204 ( V_4 ) ;
F_195 ( V_4 ) ;
F_194 ( V_4 ) ;
}
void F_205 ( struct V_3 * V_4 )
{
F_206 ( F_207 () ) ;
while ( F_197 ( V_297 , & V_4 -> V_10 ) )
F_199 ( 1 ) ;
F_196 ( V_4 ) ;
F_190 ( V_4 ) ;
F_164 ( V_297 , & V_4 -> V_10 ) ;
}
void F_204 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_110 * V_56 = V_4 -> V_56 ;
if ( V_2 -> V_175 . V_239 . V_298 ( V_2 ) ) {
F_120 ( V_2 , L_15 ) ;
} else {
V_2 -> V_175 . V_239 . V_299 ( V_2 ) ;
F_184 ( V_4 ) ;
}
if ( F_187 ( V_4 -> V_2 . V_175 . V_250 ) ) {
memcpy ( V_56 -> V_135 , V_4 -> V_2 . V_175 . V_250 ,
V_56 -> V_300 ) ;
memcpy ( V_56 -> V_292 , V_4 -> V_2 . V_175 . V_250 ,
V_56 -> V_300 ) ;
}
}
static int F_208 ( struct V_3 * V_4 ,
int V_301 )
{
int V_302 ;
V_302 = V_303 ;
V_301 = F_209 ( V_4 -> V_7 , V_4 -> V_201 ,
V_302 , V_301 ) ;
if ( V_301 < 0 ) {
F_2 ( & V_4 -> V_7 -> V_8 ,
L_16 ) ;
F_210 ( V_4 -> V_201 ) ;
V_4 -> V_201 = NULL ;
return V_301 ;
}
V_4 -> V_154 = V_301 ;
return 0 ;
}
static void F_211 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
unsigned int V_253 = 0 ;
unsigned int V_254 = 0 ;
int V_194 ;
V_4 -> V_188 = 1 ;
V_4 -> V_190 = 1 ;
F_160 ( & V_4 -> V_238 ) ;
V_194 = F_180 ( V_2 , & V_254 , & V_253 ) ;
F_161 ( & V_4 -> V_238 ) ;
if ( V_194 )
return;
if ( V_254 > 1 )
V_4 -> V_188 = V_254 ;
}
static int F_212 ( struct V_3 * V_4 )
{
struct V_24 * V_62 ;
int V_137 = 0 , V_55 = 0 ;
for (; V_55 < V_4 -> V_190 ; V_55 ++ ) {
V_62 = F_213 ( sizeof( * V_62 ) , V_304 ) ;
if ( ! V_62 )
goto V_305;
V_62 -> V_8 = & V_4 -> V_7 -> V_8 ;
V_62 -> V_56 = V_4 -> V_56 ;
V_62 -> V_40 = V_4 -> V_306 ;
V_62 -> V_57 = V_55 ;
V_62 -> V_157 = V_55 ;
V_4 -> V_25 [ V_55 ] = V_62 ;
}
for (; V_137 < V_4 -> V_188 ; V_137 ++ ) {
V_62 = F_213 ( sizeof( * V_62 ) , V_304 ) ;
if ( ! V_62 )
goto V_305;
V_62 -> V_8 = & V_4 -> V_7 -> V_8 ;
V_62 -> V_56 = V_4 -> V_56 ;
V_62 -> V_40 = V_4 -> V_307 ;
V_62 -> V_57 = V_137 ;
V_62 -> V_157 = V_137 ;
V_4 -> V_75 [ V_137 ] = V_62 ;
}
return 0 ;
V_305:
while ( V_55 ) {
F_210 ( V_4 -> V_25 [ -- V_55 ] ) ;
V_4 -> V_25 [ V_55 ] = NULL ;
}
while ( V_137 ) {
F_210 ( V_4 -> V_75 [ -- V_137 ] ) ;
V_4 -> V_75 [ V_137 ] = NULL ;
}
return - V_308 ;
}
static int F_214 ( struct V_3 * V_4 )
{
struct V_110 * V_56 = V_4 -> V_56 ;
int V_194 = 0 ;
int V_196 , V_309 ;
V_309 = F_98 ( V_4 -> V_188 , V_4 -> V_190 ) ;
V_309 = F_215 ( int , V_309 , F_216 () ) ;
V_309 += V_155 ;
V_4 -> V_201 = F_217 ( V_309 ,
sizeof( struct V_199 ) , V_304 ) ;
if ( ! V_4 -> V_201 ) {
V_194 = - V_308 ;
goto V_195;
}
for ( V_196 = 0 ; V_196 < V_309 ; V_196 ++ )
V_4 -> V_201 [ V_196 ] . V_200 = V_196 ;
V_194 = F_208 ( V_4 , V_309 ) ;
if ( V_194 )
goto V_195;
V_194 = F_218 ( V_56 , V_4 -> V_190 ) ;
if ( V_194 )
goto V_195;
V_194 = F_219 ( V_56 , V_4 -> V_188 ) ;
V_195:
return V_194 ;
}
static int F_220 ( struct V_3 * V_4 )
{
int V_252 , V_310 ;
struct V_33 * V_34 ;
V_310 = V_4 -> V_154 - V_155 ;
for ( V_252 = 0 ; V_252 < V_310 ; V_252 ++ ) {
V_34 = F_213 ( sizeof( struct V_33 ) , V_304 ) ;
if ( ! V_34 )
goto V_311;
V_34 -> V_4 = V_4 ;
V_34 -> V_143 = V_252 ;
F_221 ( V_4 -> V_56 , & V_34 -> V_61 ,
F_94 , 64 ) ;
#ifdef F_37
F_222 ( & V_34 -> V_61 ) ;
#endif
V_4 -> V_34 [ V_252 ] = V_34 ;
}
return 0 ;
V_311:
while ( V_252 ) {
V_252 -- ;
V_34 = V_4 -> V_34 [ V_252 ] ;
#ifdef F_37
F_223 ( & V_34 -> V_61 ) ;
#endif
F_224 ( & V_34 -> V_61 ) ;
F_210 ( V_34 ) ;
V_4 -> V_34 [ V_252 ] = NULL ;
}
return - V_308 ;
}
static void F_225 ( struct V_3 * V_4 )
{
int V_252 , V_310 = V_4 -> V_154 - V_155 ;
for ( V_252 = 0 ; V_252 < V_310 ; V_252 ++ ) {
struct V_33 * V_34 = V_4 -> V_34 [ V_252 ] ;
V_4 -> V_34 [ V_252 ] = NULL ;
#ifdef F_37
F_223 ( & V_34 -> V_61 ) ;
#endif
F_224 ( & V_34 -> V_61 ) ;
F_210 ( V_34 ) ;
}
}
static void F_226 ( struct V_3 * V_4 )
{
F_227 ( V_4 -> V_7 ) ;
F_210 ( V_4 -> V_201 ) ;
V_4 -> V_201 = NULL ;
}
static int F_228 ( struct V_3 * V_4 )
{
int V_194 ;
F_211 ( V_4 ) ;
V_194 = F_214 ( V_4 ) ;
if ( V_194 ) {
F_120 ( & V_4 -> V_2 ,
L_17 ) ;
goto V_312;
}
V_194 = F_220 ( V_4 ) ;
if ( V_194 ) {
F_120 ( & V_4 -> V_2 , L_18
L_19 ) ;
goto V_313;
}
V_194 = F_212 ( V_4 ) ;
if ( V_194 ) {
F_141 ( L_20 ) ;
goto V_314;
}
F_120 ( & V_4 -> V_2 , L_21
L_22 ,
( V_4 -> V_188 > 1 ) ? L_23 :
L_24 , V_4 -> V_188 , V_4 -> V_190 ) ;
F_162 ( V_43 , & V_4 -> V_10 ) ;
return 0 ;
V_314:
F_225 ( V_4 ) ;
V_313:
F_226 ( V_4 ) ;
V_312:
return V_194 ;
}
static void F_229 ( struct V_3 * V_4 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_190 ; V_41 ++ ) {
F_210 ( V_4 -> V_25 [ V_41 ] ) ;
V_4 -> V_25 [ V_41 ] = NULL ;
}
for ( V_41 = 0 ; V_41 < V_4 -> V_188 ; V_41 ++ ) {
F_210 ( V_4 -> V_75 [ V_41 ] ) ;
V_4 -> V_75 [ V_41 ] = NULL ;
}
V_4 -> V_190 = 0 ;
V_4 -> V_188 = 0 ;
F_225 ( V_4 ) ;
F_226 ( V_4 ) ;
}
static int F_230 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_315 * V_7 = V_4 -> V_7 ;
struct V_110 * V_56 = V_4 -> V_56 ;
int V_194 ;
V_2 -> V_316 = V_7 -> V_317 ;
V_2 -> V_318 = V_7 -> V_294 ;
V_2 -> V_319 = V_7 -> V_320 ;
V_2 -> V_321 = V_7 -> V_322 ;
V_2 -> V_323 = V_7 -> V_324 ;
V_2 -> V_255 . V_239 . V_325 ( V_2 ) ;
V_2 -> V_175 . V_326 = 2 ;
V_2 -> V_175 . V_327 = 2 ;
F_231 ( & V_4 -> V_238 ) ;
V_194 = V_2 -> V_175 . V_239 . V_298 ( V_2 ) ;
if ( V_194 ) {
F_232 ( & V_7 -> V_8 ,
L_25 ) ;
} else {
V_194 = V_2 -> V_175 . V_239 . V_299 ( V_2 ) ;
if ( V_194 ) {
F_141 ( L_26 , V_194 ) ;
goto V_195;
}
F_184 ( V_4 ) ;
V_194 = V_2 -> V_175 . V_239 . V_328 ( V_2 , V_2 -> V_175 . V_250 ) ;
if ( V_194 )
F_232 ( & V_7 -> V_8 , L_27 ) ;
else if ( F_233 ( V_4 -> V_2 . V_175 . V_250 ) )
F_232 ( & V_7 -> V_8 ,
L_28 ) ;
memcpy ( V_56 -> V_135 , V_2 -> V_175 . V_250 , V_56 -> V_300 ) ;
}
if ( ! F_187 ( V_56 -> V_135 ) ) {
F_232 ( & V_7 -> V_8 , L_29 ) ;
F_234 ( V_56 ) ;
memcpy ( V_2 -> V_175 . V_250 , V_56 -> V_135 , V_56 -> V_300 ) ;
}
V_4 -> V_141 = 1 ;
V_4 -> V_158 = 1 ;
V_4 -> V_306 = V_329 ;
V_4 -> V_307 = V_330 ;
F_162 ( V_43 , & V_4 -> V_10 ) ;
return 0 ;
V_195:
return V_194 ;
}
void F_235 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_41 ;
if ( ! V_4 -> V_331 )
return;
F_236 ( V_275 , V_4 -> V_52 . V_274 ,
V_4 -> V_52 . V_259 ) ;
F_236 ( V_280 , V_4 -> V_52 . V_279 ,
V_4 -> V_52 . V_260 ) ;
F_237 ( V_277 , V_278 ,
V_4 -> V_52 . V_276 ,
V_4 -> V_52 . V_266 ) ;
F_237 ( V_282 , V_283 ,
V_4 -> V_52 . V_281 ,
V_4 -> V_52 . V_269 ) ;
F_236 ( V_285 , V_4 -> V_52 . V_284 ,
V_4 -> V_52 . V_272 ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_188 ; V_41 ++ ) {
V_4 -> V_332 +=
V_4 -> V_75 [ V_41 ] -> V_332 ;
V_4 -> V_75 [ V_41 ] -> V_332 = 0 ;
}
}
static void F_238 ( unsigned long V_125 )
{
struct V_3 * V_4 = (struct V_3 * ) V_125 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
T_1 V_333 = 0 ;
int V_41 ;
if ( F_3 ( V_43 , & V_4 -> V_10 ) )
goto V_334;
for ( V_41 = 0 ; V_41 < V_4 -> V_154 - V_155 ; V_41 ++ ) {
struct V_33 * V_335 = V_4 -> V_34 [ V_41 ] ;
if ( V_335 -> V_137 . V_62 || V_335 -> V_55 . V_62 )
V_333 |= 1 << V_41 ;
}
F_13 ( V_2 , V_336 , V_333 ) ;
V_334:
F_4 ( & V_4 -> V_11 ) ;
}
static void F_239 ( struct V_110 * V_56 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
F_4 ( & V_4 -> V_337 ) ;
}
static void F_240 ( struct V_338 * V_339 )
{
struct V_3 * V_4 ;
V_4 = F_95 ( V_339 , struct V_3 , V_337 ) ;
if ( F_3 ( V_43 , & V_4 -> V_10 ) ||
F_3 ( V_142 , & V_4 -> V_10 ) ||
F_3 ( V_297 , & V_4 -> V_10 ) )
return;
V_4 -> V_340 ++ ;
F_205 ( V_4 ) ;
}
static void F_241 ( struct V_338 * V_339 )
{
struct V_3 * V_4 = F_95 ( V_339 ,
struct V_3 ,
V_11 ) ;
struct V_110 * V_56 = V_4 -> V_56 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
T_1 V_341 = V_4 -> V_341 ;
bool V_331 = V_4 -> V_331 ;
T_10 V_342 ;
if ( F_8 ( V_2 -> V_6 ) ) {
if ( ! F_3 ( V_43 , & V_4 -> V_10 ) ) {
F_242 () ;
F_196 ( V_4 ) ;
F_243 () ;
}
return;
}
F_244 ( V_4 ) ;
V_4 -> V_257 |= V_296 ;
F_160 ( & V_4 -> V_238 ) ;
V_342 = V_2 -> V_175 . V_239 . V_343 ( V_2 , & V_341 , & V_331 , false ) ;
F_161 ( & V_4 -> V_238 ) ;
if ( V_342 ) {
V_4 -> V_331 = V_331 ;
V_4 -> V_341 = V_341 ;
F_202 ( V_56 ) ;
F_200 ( V_56 ) ;
F_4 ( & V_4 -> V_337 ) ;
goto V_344;
}
V_4 -> V_331 = V_331 ;
V_4 -> V_341 = V_341 ;
if ( V_331 ) {
if ( ! F_31 ( V_56 ) ) {
char * V_345 ;
switch ( V_341 ) {
case V_346 :
V_345 = L_30 ;
break;
case V_347 :
V_345 = L_31 ;
break;
case V_348 :
V_345 = L_32 ;
break;
default:
V_345 = L_33 ;
break;
}
F_232 ( & V_4 -> V_7 -> V_8 ,
L_34 , V_345 ) ;
F_245 ( V_56 ) ;
F_246 ( V_56 ) ;
}
} else {
V_4 -> V_331 = false ;
V_4 -> V_341 = 0 ;
if ( F_31 ( V_56 ) ) {
F_232 ( & V_4 -> V_7 -> V_8 , L_35 ) ;
F_202 ( V_56 ) ;
F_200 ( V_56 ) ;
}
}
F_235 ( V_4 ) ;
V_344:
if ( ! F_3 ( V_43 , & V_4 -> V_10 ) &&
! F_3 ( V_142 , & V_4 -> V_10 ) )
F_111 ( & V_4 -> V_177 ,
F_247 ( V_178 + ( 2 * V_349 ) ) ) ;
V_4 -> V_257 &= ~ V_296 ;
}
void F_248 ( struct V_24 * V_25 )
{
F_193 ( V_25 ) ;
F_249 ( V_25 -> V_44 ) ;
V_25 -> V_44 = NULL ;
if ( ! V_25 -> V_295 )
return;
F_250 ( V_25 -> V_8 , V_25 -> V_118 , V_25 -> V_295 ,
V_25 -> V_30 ) ;
V_25 -> V_295 = NULL ;
}
static void F_251 ( struct V_3 * V_4 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_190 ; V_41 ++ )
if ( V_4 -> V_25 [ V_41 ] -> V_295 )
F_248 ( V_4 -> V_25 [ V_41 ] ) ;
}
int F_252 ( struct V_24 * V_25 )
{
int V_118 ;
V_118 = sizeof( struct V_26 ) * V_25 -> V_40 ;
V_25 -> V_44 = F_253 ( V_118 ) ;
if ( ! V_25 -> V_44 )
goto V_194;
V_25 -> V_118 = V_25 -> V_40 * sizeof( union V_35 ) ;
V_25 -> V_118 = F_67 ( V_25 -> V_118 , 4096 ) ;
V_25 -> V_295 = F_254 ( V_25 -> V_8 , V_25 -> V_118 ,
& V_25 -> V_30 , V_304 ) ;
if ( ! V_25 -> V_295 )
goto V_194;
return 0 ;
V_194:
F_249 ( V_25 -> V_44 ) ;
V_25 -> V_44 = NULL ;
F_120 ( & V_4 -> V_2 , L_36
L_37 ) ;
return - V_308 ;
}
static int F_255 ( struct V_3 * V_4 )
{
int V_41 , V_194 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_190 ; V_41 ++ ) {
V_194 = F_252 ( V_4 -> V_25 [ V_41 ] ) ;
if ( ! V_194 )
continue;
F_120 ( & V_4 -> V_2 ,
L_38 , V_41 ) ;
break;
}
return V_194 ;
}
int F_256 ( struct V_24 * V_75 )
{
int V_118 ;
V_118 = sizeof( struct V_86 ) * V_75 -> V_40 ;
V_75 -> V_96 = F_253 ( V_118 ) ;
if ( ! V_75 -> V_96 )
goto V_194;
V_75 -> V_118 = V_75 -> V_40 * sizeof( union V_63 ) ;
V_75 -> V_118 = F_67 ( V_75 -> V_118 , 4096 ) ;
V_75 -> V_295 = F_254 ( V_75 -> V_8 , V_75 -> V_118 ,
& V_75 -> V_30 , V_304 ) ;
if ( ! V_75 -> V_295 )
goto V_194;
return 0 ;
V_194:
F_249 ( V_75 -> V_96 ) ;
V_75 -> V_96 = NULL ;
F_2 ( V_75 -> V_8 , L_39 ) ;
return - V_308 ;
}
static int F_257 ( struct V_3 * V_4 )
{
int V_41 , V_194 = 0 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_188 ; V_41 ++ ) {
V_194 = F_256 ( V_4 -> V_75 [ V_41 ] ) ;
if ( ! V_194 )
continue;
F_120 ( & V_4 -> V_2 ,
L_40 , V_41 ) ;
break;
}
return V_194 ;
}
void F_258 ( struct V_24 * V_75 )
{
F_191 ( V_75 ) ;
F_249 ( V_75 -> V_96 ) ;
V_75 -> V_96 = NULL ;
F_250 ( V_75 -> V_8 , V_75 -> V_118 , V_75 -> V_295 ,
V_75 -> V_30 ) ;
V_75 -> V_295 = NULL ;
}
static void F_259 ( struct V_3 * V_4 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_188 ; V_41 ++ )
if ( V_4 -> V_75 [ V_41 ] -> V_295 )
F_258 ( V_4 -> V_75 [ V_41 ] ) ;
}
static int F_260 ( struct V_110 * V_56 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_194 ;
if ( ! V_4 -> V_154 )
return - V_308 ;
if ( F_3 ( V_350 , & V_4 -> V_10 ) )
return - V_351 ;
if ( V_2 -> V_352 ) {
F_204 ( V_4 ) ;
if ( V_2 -> V_352 ) {
V_194 = V_241 ;
F_141 ( L_41
L_42 ) ;
goto V_353;
}
}
V_194 = F_255 ( V_4 ) ;
if ( V_194 )
goto V_354;
V_194 = F_257 ( V_4 ) ;
if ( V_194 )
goto V_355;
F_181 ( V_4 ) ;
F_116 ( V_4 ) ;
F_186 ( V_4 ) ;
F_12 ( V_2 , V_293 ) ;
V_194 = F_123 ( V_4 ) ;
if ( V_194 )
goto V_356;
F_128 ( V_4 ) ;
return 0 ;
V_356:
F_196 ( V_4 ) ;
V_355:
F_259 ( V_4 ) ;
V_354:
F_251 ( V_4 ) ;
F_204 ( V_4 ) ;
V_353:
return V_194 ;
}
static int F_261 ( struct V_110 * V_56 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
F_196 ( V_4 ) ;
F_124 ( V_4 ) ;
F_251 ( V_4 ) ;
F_259 ( V_4 ) ;
return 0 ;
}
static void F_244 ( struct V_3 * V_4 )
{
struct V_110 * V_8 = V_4 -> V_56 ;
if ( ! ( V_4 -> V_257 & V_258 ) )
return;
V_4 -> V_257 &= ~ V_258 ;
if ( F_3 ( V_43 , & V_4 -> V_10 ) ||
F_3 ( V_297 , & V_4 -> V_10 ) )
return;
if ( F_262 ( V_8 ) )
F_261 ( V_8 ) ;
F_229 ( V_4 ) ;
F_228 ( V_4 ) ;
if ( F_262 ( V_8 ) )
F_260 ( V_8 ) ;
}
static void F_263 ( struct V_24 * V_25 ,
T_1 V_357 , T_1 V_358 ,
T_1 V_359 )
{
struct V_360 * V_361 ;
T_5 V_41 = V_25 -> V_95 ;
V_361 = F_264 ( V_25 , V_41 ) ;
V_41 ++ ;
V_25 -> V_95 = ( V_41 < V_25 -> V_40 ) ? V_41 : 0 ;
V_358 |= V_362 | V_363 ;
V_361 -> V_357 = F_25 ( V_357 ) ;
V_361 -> V_364 = 0 ;
V_361 -> V_365 = F_25 ( V_358 ) ;
V_361 -> V_359 = F_25 ( V_359 ) ;
}
static int F_265 ( struct V_24 * V_25 ,
struct V_26 * V_366 ,
T_2 * V_367 )
{
struct V_60 * V_28 = V_366 -> V_28 ;
T_1 V_357 , V_358 ;
T_1 V_359 , V_368 ;
int V_194 ;
if ( V_28 -> V_73 != V_369 )
return 0 ;
if ( ! F_266 ( V_28 ) )
return 0 ;
V_194 = F_267 ( V_28 , 0 ) ;
if ( V_194 < 0 )
return V_194 ;
V_358 = V_370 ;
if ( V_366 -> V_83 == F_49 ( V_371 ) ) {
struct V_372 * V_373 = F_268 ( V_28 ) ;
V_373 -> V_374 = 0 ;
V_373 -> V_375 = 0 ;
F_269 ( V_28 ) -> V_375 = ~ F_270 ( V_373 -> V_376 ,
V_373 -> V_377 , 0 ,
V_378 ,
0 ) ;
V_358 |= V_379 ;
V_366 -> V_380 |= V_381 |
V_382 |
V_383 ;
} else if ( F_271 ( V_28 ) ) {
F_272 ( V_28 ) -> V_384 = 0 ;
F_269 ( V_28 ) -> V_375 =
~ F_273 ( & F_272 ( V_28 ) -> V_376 ,
& F_272 ( V_28 ) -> V_377 ,
0 , V_378 , 0 ) ;
V_366 -> V_380 |= V_381 |
V_382 ;
}
V_368 = F_274 ( V_28 ) ;
* V_367 += V_368 ;
* V_367 = F_275 ( V_28 ) + V_368 ;
V_366 -> V_50 = F_63 ( V_28 ) -> V_50 ;
V_366 -> V_49 += ( V_366 -> V_50 - 1 ) * * V_367 ;
V_359 = V_368 << V_385 ;
V_359 |= F_63 ( V_28 ) -> V_386 << V_387 ;
V_359 |= 1 << V_388 ;
V_357 = F_276 ( V_28 ) ;
V_357 |= F_277 ( V_28 ) << V_389 ;
V_357 |= V_366 -> V_380 & V_390 ;
F_263 ( V_25 , V_357 ,
V_358 , V_359 ) ;
return 1 ;
}
static void F_278 ( struct V_24 * V_25 ,
struct V_26 * V_366 )
{
struct V_60 * V_28 = V_366 -> V_28 ;
T_1 V_357 = 0 ;
T_1 V_359 = 0 ;
T_1 V_358 = 0 ;
if ( V_28 -> V_73 == V_369 ) {
T_2 V_391 = 0 ;
switch ( V_366 -> V_83 ) {
case F_49 ( V_371 ) :
V_357 |= F_276 ( V_28 ) ;
V_358 |= V_379 ;
V_391 = F_268 ( V_28 ) -> V_83 ;
break;
case F_49 ( V_392 ) :
V_357 |= F_276 ( V_28 ) ;
V_391 = F_272 ( V_28 ) -> V_393 ;
break;
default:
if ( F_10 ( F_279 () ) ) {
F_280 ( V_25 -> V_8 ,
L_43 ,
V_366 -> V_83 ) ;
}
break;
}
switch ( V_391 ) {
case V_378 :
V_358 |= V_370 ;
V_359 = F_274 ( V_28 ) <<
V_385 ;
break;
case V_394 :
V_358 |= V_395 ;
V_359 = sizeof( struct V_396 ) <<
V_385 ;
break;
case V_397 :
V_359 = sizeof( struct V_398 ) <<
V_385 ;
break;
default:
if ( F_10 ( F_279 () ) ) {
F_280 ( V_25 -> V_8 ,
L_44 ,
V_391 ) ;
}
break;
}
V_366 -> V_380 |= V_382 ;
}
V_357 |= F_277 ( V_28 ) << V_389 ;
V_357 |= V_366 -> V_380 & V_390 ;
F_263 ( V_25 , V_357 ,
V_358 , V_359 ) ;
}
static T_11 F_281 ( T_1 V_380 )
{
T_11 V_399 = F_25 ( V_400 |
V_401 |
V_402 ) ;
if ( V_380 & V_403 )
V_399 |= F_25 ( V_404 ) ;
if ( V_380 & V_381 )
V_399 |= F_25 ( V_405 ) ;
return V_399 ;
}
static void F_282 ( union V_35 * V_36 ,
T_1 V_380 , unsigned int V_406 )
{
T_11 V_407 = F_25 ( V_406 << V_408 ) ;
if ( V_380 & V_382 )
V_407 |= F_25 ( V_409 ) ;
if ( V_380 & V_383 )
V_407 |= F_25 ( V_410 ) ;
if ( V_380 & V_381 )
V_407 |= F_25 ( 1 << V_388 ) ;
V_407 |= F_25 ( V_411 ) ;
V_36 -> V_97 . V_407 = V_407 ;
}
static void F_283 ( struct V_24 * V_25 ,
struct V_26 * V_366 ,
const T_2 V_367 )
{
T_6 V_30 ;
struct V_60 * V_28 = V_366 -> V_28 ;
struct V_26 * V_27 ;
union V_35 * V_36 ;
struct V_101 * V_102 = & F_63 ( V_28 ) -> V_103 [ 0 ] ;
unsigned int V_107 = V_28 -> V_107 ;
unsigned int V_118 = F_284 ( V_28 ) ;
unsigned int V_406 = V_28 -> V_29 - V_367 ;
T_1 V_380 = V_366 -> V_380 ;
T_11 V_399 ;
T_5 V_41 = V_25 -> V_95 ;
V_36 = F_23 ( V_25 , V_41 ) ;
F_282 ( V_36 , V_380 , V_406 ) ;
V_399 = F_281 ( V_380 ) ;
V_30 = F_285 ( V_25 -> V_8 , V_28 -> V_125 , V_118 , V_31 ) ;
if ( F_56 ( V_25 -> V_8 , V_30 ) )
goto V_412;
F_21 ( V_366 , V_29 , V_118 ) ;
F_286 ( V_366 , V_30 , V_30 ) ;
V_36 -> V_97 . V_413 = F_59 ( V_30 ) ;
for (; ; ) {
while ( F_10 ( V_118 > V_414 ) ) {
V_36 -> V_97 . V_415 =
V_399 | F_25 ( V_414 ) ;
V_41 ++ ;
V_36 ++ ;
if ( V_41 == V_25 -> V_40 ) {
V_36 = F_23 ( V_25 , 0 ) ;
V_41 = 0 ;
}
V_30 += V_414 ;
V_118 -= V_414 ;
V_36 -> V_97 . V_413 = F_59 ( V_30 ) ;
V_36 -> V_97 . V_407 = 0 ;
}
if ( F_27 ( ! V_107 ) )
break;
V_36 -> V_97 . V_415 = V_399 | F_25 ( V_118 ) ;
V_41 ++ ;
V_36 ++ ;
if ( V_41 == V_25 -> V_40 ) {
V_36 = F_23 ( V_25 , 0 ) ;
V_41 = 0 ;
}
V_118 = F_287 ( V_102 ) ;
V_107 -= V_118 ;
V_30 = F_288 ( V_25 -> V_8 , V_102 , 0 , V_118 ,
V_31 ) ;
if ( F_56 ( V_25 -> V_8 , V_30 ) )
goto V_412;
V_27 = & V_25 -> V_44 [ V_41 ] ;
F_21 ( V_27 , V_29 , V_118 ) ;
F_286 ( V_27 , V_30 , V_30 ) ;
V_36 -> V_97 . V_413 = F_59 ( V_30 ) ;
V_36 -> V_97 . V_407 = 0 ;
V_102 ++ ;
}
V_399 |= F_25 ( V_118 ) | F_25 ( V_416 ) ;
V_36 -> V_97 . V_415 = V_399 ;
V_366 -> V_417 = V_178 ;
F_60 () ;
V_366 -> V_32 = V_36 ;
V_41 ++ ;
if ( V_41 == V_25 -> V_40 )
V_41 = 0 ;
V_25 -> V_95 = V_41 ;
F_61 ( V_25 , V_41 ) ;
return;
V_412:
F_2 ( V_25 -> V_8 , L_45 ) ;
for (; ; ) {
V_27 = & V_25 -> V_44 [ V_41 ] ;
F_15 ( V_25 , V_27 ) ;
if ( V_27 == V_366 )
break;
if ( V_41 == 0 )
V_41 = V_25 -> V_40 ;
V_41 -- ;
}
V_25 -> V_95 = V_41 ;
}
static int F_289 ( struct V_24 * V_25 , int V_118 )
{
F_290 ( V_25 -> V_56 , V_25 -> V_57 ) ;
F_33 () ;
if ( F_27 ( F_32 ( V_25 ) < V_118 ) )
return - V_351 ;
F_291 ( V_25 -> V_56 , V_25 -> V_57 ) ;
++ V_25 -> V_58 . V_59 ;
return 0 ;
}
static int F_292 ( struct V_24 * V_25 , int V_118 )
{
if ( F_27 ( F_32 ( V_25 ) >= V_118 ) )
return 0 ;
return F_289 ( V_25 , V_118 ) ;
}
static int F_293 ( struct V_60 * V_28 , struct V_110 * V_56 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
struct V_26 * V_366 ;
struct V_24 * V_25 ;
int V_418 ;
T_1 V_380 = 0 ;
T_5 V_40 = F_294 ( F_284 ( V_28 ) ) ;
#if V_90 > V_414
unsigned short V_419 ;
#endif
T_2 V_367 = 0 ;
T_2 * V_420 = F_295 ( V_28 , 0 , 0 , NULL ) ;
if ( ! V_420 || F_296 ( V_420 ) ) {
F_192 ( V_28 ) ;
return V_421 ;
}
V_25 = V_4 -> V_25 [ V_28 -> V_422 ] ;
#if V_90 > V_414
for ( V_419 = 0 ; V_419 < F_63 ( V_28 ) -> V_122 ; V_419 ++ )
V_40 += F_294 ( F_63 ( V_28 ) -> V_103 [ V_419 ] . V_118 ) ;
#else
V_40 += F_63 ( V_28 ) -> V_122 ;
#endif
if ( F_292 ( V_25 , V_40 + 3 ) ) {
V_25 -> V_58 . V_423 ++ ;
return V_424 ;
}
V_366 = & V_25 -> V_44 [ V_25 -> V_95 ] ;
V_366 -> V_28 = V_28 ;
V_366 -> V_49 = V_28 -> V_29 ;
V_366 -> V_50 = 1 ;
if ( F_297 ( V_28 ) ) {
V_380 |= F_298 ( V_28 ) ;
V_380 <<= V_425 ;
V_380 |= V_403 ;
}
V_366 -> V_380 = V_380 ;
V_366 -> V_83 = F_299 ( V_28 ) ;
V_418 = F_265 ( V_25 , V_366 , & V_367 ) ;
if ( V_418 < 0 )
goto V_426;
else if ( ! V_418 )
F_278 ( V_25 , V_366 ) ;
F_283 ( V_25 , V_366 , V_367 ) ;
F_292 ( V_25 , V_427 ) ;
return V_421 ;
V_426:
F_16 ( V_366 -> V_28 ) ;
V_366 -> V_28 = NULL ;
return V_421 ;
}
static int F_300 ( struct V_110 * V_56 , void * V_428 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_429 * V_250 = V_428 ;
if ( ! F_187 ( V_250 -> V_430 ) )
return - V_431 ;
memcpy ( V_56 -> V_135 , V_250 -> V_430 , V_56 -> V_300 ) ;
memcpy ( V_2 -> V_175 . V_250 , V_250 -> V_430 , V_56 -> V_300 ) ;
F_160 ( & V_4 -> V_238 ) ;
V_2 -> V_175 . V_239 . V_291 ( V_2 , 0 , V_2 -> V_175 . V_250 , 0 ) ;
F_161 ( & V_4 -> V_238 ) ;
return 0 ;
}
static int F_301 ( struct V_110 * V_56 , int V_432 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
int V_433 = V_432 + V_235 + V_236 ;
int V_434 = V_435 ;
switch ( V_4 -> V_2 . V_436 ) {
case V_287 :
V_434 = V_437 ;
break;
default:
if ( V_4 -> V_2 . V_175 . type != V_438 )
V_434 = V_437 ;
break;
}
if ( ( V_432 < 68 ) || ( V_433 > V_434 ) )
return - V_439 ;
F_120 ( V_2 , L_46 ,
V_56 -> V_234 , V_432 ) ;
V_56 -> V_234 = V_432 ;
F_158 ( V_2 , V_433 ) ;
return 0 ;
}
static void F_302 ( struct V_110 * V_56 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
int V_41 ;
if ( F_3 ( V_43 , & V_4 -> V_10 ) )
return;
for ( V_41 = 0 ; V_41 < V_4 -> V_188 ; V_41 ++ )
F_112 ( 0 , V_4 -> V_34 [ V_41 ] ) ;
}
static int F_303 ( struct V_315 * V_7 , T_12 V_10 )
{
struct V_110 * V_56 = F_304 ( V_7 ) ;
struct V_3 * V_4 = F_47 ( V_56 ) ;
#ifdef F_305
int V_440 = 0 ;
#endif
F_306 ( V_56 ) ;
if ( F_262 ( V_56 ) ) {
F_242 () ;
F_196 ( V_4 ) ;
F_124 ( V_4 ) ;
F_251 ( V_4 ) ;
F_259 ( V_4 ) ;
F_243 () ;
}
F_229 ( V_4 ) ;
#ifdef F_305
V_440 = F_307 ( V_7 ) ;
if ( V_440 )
return V_440 ;
#endif
if ( ! F_197 ( V_441 , & V_4 -> V_10 ) )
F_308 ( V_7 ) ;
return 0 ;
}
static int F_309 ( struct V_315 * V_7 )
{
struct V_110 * V_56 = F_304 ( V_7 ) ;
struct V_3 * V_4 = F_47 ( V_56 ) ;
T_1 V_194 ;
F_310 ( V_7 ) ;
F_307 ( V_7 ) ;
V_194 = F_311 ( V_7 ) ;
if ( V_194 ) {
F_2 ( & V_7 -> V_8 , L_47 ) ;
return V_194 ;
}
F_188 () ;
F_164 ( V_441 , & V_4 -> V_10 ) ;
F_312 ( V_7 ) ;
F_204 ( V_4 ) ;
F_242 () ;
V_194 = F_228 ( V_4 ) ;
F_243 () ;
if ( V_194 ) {
F_2 ( & V_7 -> V_8 , L_48 ) ;
return V_194 ;
}
if ( F_262 ( V_56 ) ) {
V_194 = F_260 ( V_56 ) ;
if ( V_194 )
return V_194 ;
}
F_313 ( V_56 ) ;
return V_194 ;
}
static void F_314 ( struct V_315 * V_7 )
{
F_303 ( V_7 , V_442 ) ;
}
static struct V_443 * F_315 ( struct V_110 * V_56 ,
struct V_443 * V_52 )
{
struct V_3 * V_4 = F_47 ( V_56 ) ;
unsigned int V_444 ;
T_7 V_53 , V_54 ;
const struct V_24 * V_62 ;
int V_41 ;
F_235 ( V_4 ) ;
V_52 -> V_445 = V_4 -> V_52 . V_272 - V_4 -> V_52 . V_273 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_188 ; V_41 ++ ) {
V_62 = V_4 -> V_75 [ V_41 ] ;
do {
V_444 = F_316 ( & V_62 -> V_51 ) ;
V_53 = V_62 -> V_52 . V_53 ;
V_54 = V_62 -> V_52 . V_54 ;
} while ( F_317 ( & V_62 -> V_51 , V_444 ) );
V_52 -> V_446 += V_53 ;
V_52 -> V_447 += V_54 ;
}
for ( V_41 = 0 ; V_41 < V_4 -> V_190 ; V_41 ++ ) {
V_62 = V_4 -> V_25 [ V_41 ] ;
do {
V_444 = F_316 ( & V_62 -> V_51 ) ;
V_53 = V_62 -> V_52 . V_53 ;
V_54 = V_62 -> V_52 . V_54 ;
} while ( F_317 ( & V_62 -> V_51 , V_444 ) );
V_52 -> V_448 += V_53 ;
V_52 -> V_449 += V_54 ;
}
return V_52 ;
}
static void F_318 ( struct V_110 * V_8 )
{
V_8 -> V_450 = & V_451 ;
F_319 ( V_8 ) ;
V_8 -> V_452 = 5 * V_349 ;
}
static int F_320 ( struct V_315 * V_7 , const struct V_453 * V_454 )
{
struct V_110 * V_56 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 = NULL ;
const struct V_455 * V_456 = V_457 [ V_454 -> V_458 ] ;
int V_194 , V_459 ;
bool V_460 = false ;
V_194 = F_321 ( V_7 ) ;
if ( V_194 )
return V_194 ;
if ( ! F_322 ( & V_7 -> V_8 , F_132 ( 64 ) ) ) {
V_459 = 1 ;
} else {
V_194 = F_322 ( & V_7 -> V_8 , F_132 ( 32 ) ) ;
if ( V_194 ) {
F_2 ( & V_7 -> V_8 , L_49
L_50 ) ;
goto V_461;
}
V_459 = 0 ;
}
V_194 = F_323 ( V_7 , V_462 ) ;
if ( V_194 ) {
F_2 ( & V_7 -> V_8 , L_51 , V_194 ) ;
goto V_463;
}
F_312 ( V_7 ) ;
V_56 = F_324 ( sizeof( struct V_3 ) ,
V_464 ) ;
if ( ! V_56 ) {
V_194 = - V_308 ;
goto V_465;
}
F_325 ( V_56 , & V_7 -> V_8 ) ;
V_4 = F_47 ( V_56 ) ;
V_4 -> V_56 = V_56 ;
V_4 -> V_7 = V_7 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_466 = F_326 ( V_467 , V_468 ) ;
F_307 ( V_7 ) ;
V_2 -> V_6 = F_327 ( F_328 ( V_7 , 0 ) ,
F_329 ( V_7 , 0 ) ) ;
V_4 -> V_214 = V_2 -> V_6 ;
if ( ! V_2 -> V_6 ) {
V_194 = - V_242 ;
goto V_469;
}
F_318 ( V_56 ) ;
memcpy ( & V_2 -> V_175 . V_239 , V_456 -> V_470 , sizeof( V_2 -> V_175 . V_239 ) ) ;
V_2 -> V_175 . type = V_456 -> V_175 ;
memcpy ( & V_2 -> V_255 . V_239 , & V_471 ,
sizeof( struct V_472 ) ) ;
V_194 = F_230 ( V_4 ) ;
if ( V_194 )
goto V_473;
if ( ! F_187 ( V_56 -> V_135 ) ) {
F_141 ( L_52 ) ;
V_194 = - V_242 ;
goto V_473;
}
V_56 -> V_474 = V_475 |
V_476 |
V_477 |
V_478 |
V_479 |
V_66 ;
V_56 -> V_65 = V_56 -> V_474 |
V_480 |
V_481 |
V_482 ;
V_56 -> V_483 |= V_478 ;
V_56 -> V_483 |= V_479 ;
V_56 -> V_483 |= V_476 ;
V_56 -> V_483 |= V_477 ;
V_56 -> V_483 |= V_475 ;
if ( V_459 )
V_56 -> V_65 |= V_484 ;
V_56 -> V_485 |= V_486 ;
F_330 ( & V_4 -> V_177 ) ;
V_4 -> V_177 . V_487 = F_238 ;
V_4 -> V_177 . V_125 = ( unsigned long ) V_4 ;
if ( F_8 ( V_2 -> V_6 ) ) {
V_194 = - V_242 ;
goto V_473;
}
F_331 ( & V_4 -> V_337 , F_240 ) ;
F_331 ( & V_4 -> V_11 , F_241 ) ;
F_162 ( V_9 , & V_4 -> V_10 ) ;
V_194 = F_228 ( V_4 ) ;
if ( V_194 )
goto V_473;
strcpy ( V_56 -> V_202 , L_53 ) ;
V_194 = F_332 ( V_56 ) ;
if ( V_194 )
goto V_488;
F_333 ( V_7 , V_56 ) ;
F_202 ( V_56 ) ;
F_183 ( V_4 ) ;
F_232 ( & V_7 -> V_8 , L_54 , V_56 -> V_135 ) ;
F_232 ( & V_7 -> V_8 , L_55 , V_2 -> V_175 . type ) ;
switch ( V_2 -> V_175 . type ) {
case V_489 :
F_232 ( & V_7 -> V_8 , L_56 ) ;
break;
case V_490 :
F_232 ( & V_7 -> V_8 , L_57 ) ;
break;
case V_438 :
default:
F_232 ( & V_7 -> V_8 , L_58 ) ;
break;
}
return 0 ;
V_488:
F_229 ( V_4 ) ;
V_473:
F_226 ( V_4 ) ;
F_334 ( V_4 -> V_214 ) ;
V_469:
V_460 = ! F_197 ( V_441 , & V_4 -> V_10 ) ;
F_335 ( V_56 ) ;
V_465:
F_336 ( V_7 ) ;
V_463:
V_461:
if ( ! V_4 || V_460 )
F_308 ( V_7 ) ;
return V_194 ;
}
static void F_337 ( struct V_315 * V_7 )
{
struct V_110 * V_56 = F_304 ( V_7 ) ;
struct V_3 * V_4 ;
bool V_460 ;
if ( ! V_56 )
return;
V_4 = F_47 ( V_56 ) ;
F_162 ( V_142 , & V_4 -> V_10 ) ;
F_201 ( & V_4 -> V_177 ) ;
F_338 ( & V_4 -> V_337 ) ;
F_338 ( & V_4 -> V_11 ) ;
if ( V_56 -> V_491 == V_492 )
F_339 ( V_56 ) ;
F_229 ( V_4 ) ;
F_226 ( V_4 ) ;
F_334 ( V_4 -> V_214 ) ;
F_336 ( V_7 ) ;
F_120 ( & V_4 -> V_2 , L_59 ) ;
V_460 = ! F_197 ( V_441 , & V_4 -> V_10 ) ;
F_335 ( V_56 ) ;
if ( V_460 )
F_308 ( V_7 ) ;
}
static T_13 F_340 ( struct V_315 * V_7 ,
T_14 V_10 )
{
struct V_110 * V_56 = F_304 ( V_7 ) ;
struct V_3 * V_4 = F_47 ( V_56 ) ;
if ( ! F_3 ( V_9 , & V_4 -> V_10 ) )
return V_493 ;
F_242 () ;
F_306 ( V_56 ) ;
if ( V_10 == V_494 ) {
F_243 () ;
return V_493 ;
}
if ( F_262 ( V_56 ) )
F_196 ( V_4 ) ;
if ( ! F_197 ( V_441 , & V_4 -> V_10 ) )
F_308 ( V_7 ) ;
F_243 () ;
return V_495 ;
}
static T_13 F_341 ( struct V_315 * V_7 )
{
struct V_110 * V_56 = F_304 ( V_7 ) ;
struct V_3 * V_4 = F_47 ( V_56 ) ;
if ( F_311 ( V_7 ) ) {
F_2 ( & V_7 -> V_8 ,
L_60 ) ;
return V_493 ;
}
F_188 () ;
F_164 ( V_441 , & V_4 -> V_10 ) ;
F_312 ( V_7 ) ;
F_204 ( V_4 ) ;
return V_496 ;
}
static void F_342 ( struct V_315 * V_7 )
{
struct V_110 * V_56 = F_304 ( V_7 ) ;
struct V_3 * V_4 = F_47 ( V_56 ) ;
if ( F_262 ( V_56 ) )
F_190 ( V_4 ) ;
F_313 ( V_56 ) ;
}
static int T_15 F_343 ( void )
{
int V_497 ;
F_178 ( L_61 , V_498 ,
V_499 ) ;
F_178 ( L_62 , V_500 ) ;
V_497 = F_344 ( & V_501 ) ;
return V_497 ;
}
static void T_16 F_345 ( void )
{
F_346 ( & V_501 ) ;
}
char * F_347 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_56 -> V_202 ;
}
